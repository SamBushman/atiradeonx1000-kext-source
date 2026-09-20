#include "decls.h"

/* FUN_00083100 @ 0x83100 (4 bytes) */
int FUN_00083100()
{
  return;
}

/* FUN_00083110 @ 0x83110 (856 bytes) */
int FUN_00083110(param_1)
  int param_1;
{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  *(undefined4 *)(param_1 + 0x1ca0) = 1;
  *(undefined4 *)(param_1 + 0x1ca4) = 4;
  uVar2 = *(uint *)(param_1 + 0x1804);
  FUN_0004fc80(param_1,0,3,0,0,0,0,0);
  *(undefined4 *)(param_1 + 0x1b9c) = 1;
  *(undefined4 *)(param_1 + 0x1bb0) = 0;
  *(undefined4 *)(param_1 + 0x1ba0) = 0;
  if ((uVar2 & 2) == 0) {
    iVar6 = 1;
    iVar4 = 2;
  }
  else {
    iVar6 = 2;
    iVar4 = 3;
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 0x40000;
    *(uint *)(param_1 + 0x1ca4) =
         (*(uint *)(param_1 + 0x1ca4) & 0x7f) + 1 & 0x7f | *(uint *)(param_1 + 0x1ca4) & 0xffffff80;
    FUN_0004fc80(param_1,1,0,0,1,0,0,0);
    *(uint *)(param_1 + 0x1b9c) = *(uint *)(param_1 + 0x1b9c) | 0x10000;
  }
  *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 4;
  *(uint *)(param_1 + 0x1ca4) =
       (*(uint *)(param_1 + 0x1ca4) & 0x7f) + 4 & 0x7f | *(uint *)(param_1 + 0x1ca4) & 0xffffff80;
  FUN_0004fc80(param_1,iVar6,3,0,iVar6,0,0,0);
  *(uint *)(param_1 + 0x1b9c) = *(uint *)(param_1 + 0x1b9c) | 2;
  iVar5 = iVar4;
  if ((uVar2 & 1) != 0) {
    iVar5 = iVar6 + 2;
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 8;
    *(uint *)(param_1 + 0x1ca4) =
         (*(uint *)(param_1 + 0x1ca4) & 0x7f) + 4 & 0x7f | *(uint *)(param_1 + 0x1ca4) & 0xffffff80;
    FUN_0004fc80(param_1,iVar4,3,0,iVar4,0,0,0);
    *(uint *)(param_1 + 0x1b9c) = *(uint *)(param_1 + 0x1b9c) | 4;
  }
  if ((uVar2 & 8) != 0) {
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 0x30;
    *(uint *)(param_1 + 0x1ca4) =
         (*(uint *)(param_1 + 0x1ca4) & 0x7f) + 7 & 0x7f | *(uint *)(param_1 + 0x1ca4) & 0xffffff80;
    FUN_0004fc80(param_1,iVar5,3,0,iVar5,0,0,0);
    iVar4 = iVar5 + 1;
    iVar5 = iVar5 + 2;
    FUN_0004fc80(param_1,iVar4,2,0,iVar4,0,0,0);
    *(uint *)(param_1 + 0x1b9c) = *(uint *)(param_1 + 0x1b9c) | 0x18;
  }
  if (uVar2 >> 4 != 0) {
    uVar3 = 0;
    iVar4 = iVar5;
    iVar6 = param_1;
    do {
      uVar7 = *(uint *)(iVar6 + 0x1824);
      uVar3 = uVar3 + 1;
      iVar5 = iVar4 + 1;
      iVar6 = iVar6 + 4;
      *(uint *)(param_1 + 0x1ca0) = 0x400 << (uVar7 & 0x3f) | *(uint *)(param_1 + 0x1ca0);
      uVar7 = 4 << (uVar7 * 3 & 0x3f);
      *(uint *)(param_1 + 0x1ca4) =
           (*(uint *)(param_1 + 0x1ca4) & 0x7f) + 4 & 0x7f |
           *(uint *)(param_1 + 0x1ca4) & 0xffffff80;
      FUN_0004fc80(param_1,iVar4,3,0,iVar4,0,0,0);
      *(uint *)(param_1 + 0x1bb0) = uVar7 | *(uint *)(param_1 + 0x1bb0);
      *(uint *)(param_1 + 0x1ba0) = uVar7 | *(uint *)(param_1 + 0x1ba0);
      iVar4 = iVar5;
    } while (uVar2 >> 4 != uVar3);
  }
  if ((*(uint *)(param_1 + 0x44) & 0x400) != 0) {
    uVar2 = 4 << ((uint)(byte)((unsigned char *)0x000011d2)[param_1] * 3 & 0x3f);
    *(uint *)(param_1 + 0x1bb0) = uVar2 | *(uint *)(param_1 + 0x1bb0);
    *(uint *)(param_1 + 0x1ba0) = uVar2 | *(uint *)(param_1 + 0x1ba0);
  }
  uVar2 = iVar5 - 1;
  if ((uVar2 & 1) == 0) {
    iVar4 = (uVar2 * 2 & 0xfffffffc) + param_1;
    *(uint *)(iVar4 + 0x1be4) = *(uint *)(iVar4 + 0x1be4) | 0x2000;
  }
  else {
    iVar4 = (uVar2 * 2 & 0xfffffffc) + param_1;
    *(uint *)(iVar4 + 0x1be4) = *(uint *)(iVar4 + 0x1be4) | 0x20000000;
  }
  pcVar1 = *(code **)(((unsigned char *)0x00001334) + param_1);
  *(int *)(param_1 + 0x243c) = iVar5;
  *(int *)(param_1 + 0x2438) = iVar5;
  (*pcVar1)(param_1,1);
                    
                    
  (**(code **)(((unsigned char *)0x00001330) + param_1))(param_1,0xc0100000);
  return;
}

/* FUN_00083470 @ 0x83470 (828 bytes) */
int FUN_00083470(param_1)
  int param_1;
{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  void *pvVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 in_r7;
  undefined4 in_r8;
  uint in_r9;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  void *pvVar13;
  uint uVar14;
  int iVar15;
  uint local_68 [2];
  undefined4 local_60;
  uint local_5c;
  
  if (*(char *)(param_1 + 0x1868) == '\0') {
    _memset(local_68,0,0x30);
    uVar8 = *(uint *)(param_1 + 0x44);
    local_60 = *(undefined4 *)(param_1 + 0x1804);
    local_68[0] = local_68[0] | 8;
    if ((uVar8 & 0xc00) != 0) {
      in_r9 = uVar8 >> 9 & 2;
      local_5c = uVar8 >> 0xb & 1 | in_r9 | (uint)(byte)((unsigned char *)0x000011d3)[param_1] << 2;
    }
    pvVar13 = *(void **)(param_1 + 0x14c);
    if ((pvVar13 == (void *)0x0) ||
       (iVar3 = _memcmp(pvVar13,local_68,0x30), pvVar4 = pvVar13, iVar3 != 0)) {
      pvVar4 = (void *)FUN_0009edd0(param_1,local_68);
      if (pvVar4 == (void *)0x0) {
        uVar12 = *(uint *)(param_1 + 0x1804);
        puVar5 = (undefined4 *)FUN_00092bf0(param_1,0,0);
        puVar5[0x1a] = 0;
        *puVar5 = 0;
        uVar8 = *(uint *)(param_1 + 0x44);
        if ((uVar8 & 0x400) == 0) {
          uVar1 = uVar12 >> 3 & 1;
          uVar14 = uVar12 >> 1 & 1;
          iVar3 = 0;
        }
        else {
          uVar1 = uVar12 >> 3 & 1;
          uVar14 = uVar12 >> 1 & 1;
          in_r9 = uVar1 * 2 + (uVar12 & 1) + uVar14 + (uint)(byte)((unsigned char *)0x000011d2)[param_1];
          iVar3 = in_r9 + 2;
          puVar5[(byte)((unsigned char *)0x000011d2)[param_1] + 0x21] = iVar3;
          uVar8 = *(uint *)(param_1 + 0x44);
        }
        FUN_00092d40(puVar5,uVar8 >> 10 & 1,(uint)(byte)((unsigned char *)0x000011d2)[param_1]);
        if (uVar14 == 0) {
          iVar9 = 1;
          iVar15 = 1;
          iVar10 = 2;
          iVar11 = 2;
        }
        else {
          iVar15 = 2;
          iVar9 = 2;
          puVar5[0x1b] = 1;
          puVar5[0x13] = 1;
          iVar10 = 3;
          iVar11 = 3;
          FUN_00093130(puVar5);
        }
        puVar5[3] = iVar9;
        puVar5[0x1d] = iVar15;
        uVar6 = 0;
        uVar7 = 0;
        FUN_00092ea0(puVar5,3,0,0);
        if ((uVar12 & 1) != 0) {
          puVar5[4] = iVar10;
          puVar5[0x1f] = iVar11;
          uVar6 = 1;
          uVar7 = 0;
          FUN_00092ea0(puVar5,4,1,0);
          if ((uVar12 & 4) != 0) {
            puVar5[0x14] = iVar10;
            puVar5[0x1c] = iVar11;
            puVar5[0x15] = 3;
            FUN_000931e0(puVar5);
          }
          iVar10 = iVar9 + 2;
          iVar11 = iVar15 + 2;
        }
        if (uVar1 != 0) {
          puVar5[5] = iVar10;
          puVar5[0x1e] = iVar11;
          FUN_00092ea0(puVar5,3,2,1);
          puVar5[6] = iVar10 + 1;
          puVar5[0x20] = iVar11 + 1;
          uVar6 = 3;
          uVar7 = 1;
          iVar10 = iVar10 + 2;
          iVar11 = iVar11 + 2;
          FUN_00092ea0(puVar5,4,3,1);
        }
        if (uVar12 >> 4 != 0) {
          uVar8 = 0;
          iVar9 = param_1;
          do {
            iVar15 = *(int *)(iVar9 + 0x1824);
            puVar5[iVar15 + 0xb] = iVar10;
            iVar10 = iVar10 + 1;
            if (iVar3 == iVar11) {
              iVar11 = iVar11 + 1;
            }
            puVar5[iVar15 + 0x21] = iVar11;
            uVar8 = uVar8 + 1;
            iVar9 = iVar9 + 4;
            iVar11 = iVar11 + 1;
            FUN_00093000(puVar5,iVar15,uVar6,uVar7,in_r7,in_r8,in_r9);
          } while (uVar12 >> 4 != uVar8);
        }
        FUN_0009a910(puVar5);
        if (iVar3 == iVar11) {
          iVar11 = iVar11 + 1;
        }
        pvVar4 = (void *)FUN_0009c800(param_1,local_68,puVar5,iVar10,iVar11,0,0,1);
        *(undefined4 *)((int)pvVar4 + 0x34) = 0;
        *(int *)((int)pvVar4 + 0x38) = *(int *)(*(int *)((int)pvVar4 + 0x54) + 0x3cc) + -1;
        pvVar13 = *(void **)(param_1 + 0x14c);
      }
      else {
        pvVar13 = *(void **)(param_1 + 0x14c);
      }
    }
    if (pvVar4 != pvVar13) {
      pcVar2 = *(code **)(((unsigned char *)0x000012d0) + param_1);
      *(void **)(param_1 + 0x14c) = pvVar4;
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000;
      (*pcVar2)(param_1,pvVar4);
    }
  }
  else {
    FUN_000656b0(param_1);
  }
  return;
}

/* FUN_000837b0 @ 0x837b0 (188 bytes) */
int FUN_000837b0(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  ((int (*)())FUN_00083470)(param_1);
  ((int (*)())FUN_00083110)(param_1);
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,9);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar1;
  *puVar1 = 0x861;
  uVar2 = *(undefined4 *)(param_1 + 0x1ca0);
  puVar1[2] = 0x10824;
  puVar1[1] = uVar2;
  puVar1[3] = *(undefined4 *)(param_1 + 0x1b9c);
  uVar2 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar1[5] = 0x82d;
  puVar1[4] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x1ca4);
  puVar1[7] = ((unsigned char *)0x00001047);
  puVar1[6] = uVar2;
  puVar1[8] = *(undefined4 *)(param_1 + 0x1bb0);
  pcVar3 = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x24;
  (*pcVar3)(param_1);
  FUN_0004e880(param_1);
  return;
}

/* FUN_00083870 @ 0x83870 (1012 bytes) */
void FUN_00083870(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                 double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,
                 double fparam_7,double fparam_8,double fparam_9)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  code *pcVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 *puVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined4 in_r10;
  uint uVar16;
  double dVar17;
  undefined8 uVar18;
  double in_stack_ffffff98;
  undefined4 local_38;
  undefined4 local_34 [5];
  
  *(undefined1 *)(param_1 + 0x126) = 0;
  *(undefined4 *)(param_1 + 0x1b98) = 0;
  cVar1 = *(char *)(param_1 + 0x29);
  ((void (*)())FUN_00090470)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff98);
  if (cVar1 == '\0') {
    iVar15 = *(int *)(param_1 + 0x13c);
    if (iVar15 == *(int *)(param_1 + 0x140)) {
      iVar3 = *(int *)(param_1 + 0x148);
      if (iVar3 == *(int *)(param_1 + 0x144)) {
        return;
      }
    }
    else {
      iVar3 = *(int *)(param_1 + 0x148);
    }
  }
  else {
    iVar15 = *(int *)(param_1 + 0x13c);
    iVar3 = *(int *)(param_1 + 0x148);
  }
  *(int *)(param_1 + 0x140) = iVar15;
  *(int *)(param_1 + 0x144) = iVar3;
  if (*(char *)(param_1 + 0x124) == '\0') {
    if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
      return;
    }
    uVar18 = FUN_0009edd0(param_1,param_1 + 0x1874);
    iVar3 = (int)((ulonglong)uVar18 >> 0x20);
    if (iVar3 == 0) {
      FUN_0009d080(param_1,(int)uVar18,param_3,param_4,param_5,param_6);
      uVar8 = FUN_0009bd00(param_1);
      iVar15 = FUN_0009d410(param_1,0,&local_38,local_34,uVar8,param_6,iVar15,in_r10);
      iVar3 = FUN_0009c800(param_1,param_1 + 0x1874,iVar15,(uint)*(byte *)(param_1 + 0x131),local_38
                           ,local_34[0],uVar8,(uint)*(byte *)(param_1 + 0x126));
      puVar9 = (undefined4 *)
               FUN_000774c0(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x18));
      puVar9[8] = 0;
      puVar9[9] = 0;
      *puVar9 = 0x460;
      puVar9[3] = 0x20;
      uVar12 = 0x10;
      puVar11 = puVar9;
      iVar10 = FUN_0009cb10(param_1,iVar3,puVar9,0x10);
      FUN_0007a110(puVar9);
      if (*(uint *)(iVar15 + 0x3cc) <= *(uint *)(iVar15 + 0x3e4)) {
        *(undefined1 *)(iVar3 + 0x59) = 0;
        *(undefined1 *)(param_1 + 0x126) = 0;
      }
      if (*(char *)(param_1 + 0x126) == '\0') {
        if (iVar10 == 0) {
          iVar15 = *(int *)(iVar3 + 0x54);
          iVar10 = *(int *)(iVar15 + 0x3cc);
          *(undefined4 *)(iVar3 + 0x38) = 0;
          if (iVar10 != 0) {
            iVar4 = iVar10 * 0x10 + *(int *)(iVar15 + 0x3c8);
            do {
              if ((((*(uint *)(iVar4 + -0xc) & 7) == 1) || ((*(uint *)(iVar4 + -8) & 7) == 1)) ||
                 ((*(uint *)(iVar4 + -4) & 7) == 1)) {
                *(int *)(iVar3 + 0x38) = iVar10 + -1;
              }
              iVar10 = iVar10 + -1;
            } while ((iVar10 != 0) && (iVar4 = iVar4 + -0x10, *(int *)(iVar3 + 0x38) == 0));
          }
        }
        else {
          iVar15 = *(int *)(iVar3 + 0x54);
        }
        puVar5 = *(uint **)(iVar15 + 0x3c8);
        if (*(int *)(iVar15 + 0x3cc) != 0) {
          uVar14 = 0;
          do {
            uVar2 = *puVar5;
            if ((uVar2 & 0x3f) == 4) {
              if ((((puVar5[1] & 7) == 0) && ((puVar5[2] & 7) == 0)) && ((puVar5[3] & 7) == 0)) {
                uVar6 = puVar5[1] >> 5 & 0xff;
                uVar13 = puVar5[2] >> 5 & 0xff;
                if (((uVar6 != uVar13) && (uVar16 = puVar5[3] >> 5 & 0xff, uVar6 != uVar16)) &&
                   (uVar13 != uVar16)) {
                  *puVar5 = uVar2 & 0xffffffc0 | 0x80;
                  iVar15 = *(int *)(iVar3 + 0x54);
                }
              }
            }
            else if ((((uVar2 & 0x3f) == 0xb) && ((puVar5[1] & 7) == 0)) &&
                    (((puVar5[2] & 7) == 0 && ((puVar5[3] & 7) == 0)))) {
              uVar6 = puVar5[1] >> 5 & 0xff;
              uVar13 = puVar5[2] >> 5 & 0xff;
              if (((uVar6 != uVar13) && (uVar16 = puVar5[3] >> 5 & 0xff, uVar6 != uVar16)) &&
                 (uVar13 != uVar16)) {
                *puVar5 = uVar2 & 0xffffffc0 | 0x81;
                iVar15 = *(int *)(iVar3 + 0x54);
              }
            }
            uVar14 = uVar14 + 1;
            puVar5 = puVar5 + 4;
          } while (uVar14 < *(uint *)(iVar15 + 0x3cc));
        }
LAB_00083c10:
        if (iVar3 != *(int *)(param_1 + 0x14c)) {
          *(int *)(param_1 + 0x14c) = iVar3;
          pcVar7 = *(code **)(((unsigned char *)0x000012d0) + param_1);
          *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000;
          (*pcVar7)(param_1,iVar3);
        }
        (**(code **)(((unsigned char *)0x000012c4) + param_1))(param_1,iVar3);
        return;
      }
      *(undefined1 *)(param_1 + 0x2435) = 1;
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000000;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1020;
      dVar17 = (double)FUN_000a7d10(param_1);
      *(undefined1 *)(param_1 + 0x29) = 1;
      ((void (*)())FUN_00090470)(param_1,extraout_r4,puVar11,uVar12,local_38,local_34[0],uVar8,dVar17,fparam_2,
                   fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff98);
    }
    else {
      if (*(char *)(iVar3 + 0x59) == '\0') goto LAB_00083c10;
      *(undefined1 *)(param_1 + 0x2435) = 1;
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000000;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1020;
      dVar17 = (double)FUN_000a7d10(param_1);
      *(undefined1 *)(param_1 + 0x126) = 1;
      *(undefined1 *)(param_1 + 0x29) = 1;
      ((void (*)())FUN_00090470)(param_1,extraout_r4_00,param_3,param_4,param_5,param_6,iVar15,dVar17,fparam_2,
                   fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff98);
    }
  }
  ((int (*)())FUN_000837b0)(param_1);
  return;
}

/* FUN_00083c80 @ 0x83c80 (12 bytes) */
void FUN_00083c80(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                 double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,
                 double fparam_7,double fparam_8,double fparam_9)

{
  *(undefined1 *)(param_1 + 0x29) = 1;
  ((void (*)())FUN_00083870)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,fparam_9);
  return;
}

/* FUN_00083c90 @ 0x83c90 (372 bytes) */
int FUN_00083c90(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  
  bVar4 = 4;
  *(undefined4 *)(((unsigned char *)0x0000148c) + param_1) = 0;
  *(undefined1 *)(param_1 + 0x3d4) = 1;
  uVar2 = *(int *)(((unsigned char *)0x000013f4) + param_1) - 2;
  uVar3 = *(int *)(((unsigned char *)0x000013f4) + param_1) - 1;
  DAT_001dbca8 = uVar3 & 0x3ff | DAT_001dbca8 & 0xfffffc00;
  DAT_001dbcac = (uVar3 & 0x3ff) << 0x14 |
                 (uVar2 & 0x3ff) << 10 | uVar2 & 0x3ff | DAT_001dbcac & 0xc0000000;
  uVar3 = *(uint *)(param_1 + 0x8c);
  if ((uVar3 & 0x8000) != 0) {
    if (*(int *)(param_1 + 0xd8) == 2) {
      bVar4 = 0xc;
      *(uint *)(param_1 + 0x8c) = uVar3 | 0x50000;
    }
    else {
      bVar4 = 4;
      *(uint *)(param_1 + 0x8c) = uVar3 & 0xffff7fff;
    }
  }
  if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
    *(byte *)(param_1 + 0x2d) = bVar4 | *(byte *)(param_1 + 0x2d);
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  param_2[3] = uVar2;
  param_2[1] = 0;
  *param_2 = 0x8a1;
  param_2[2] = 0x880;
  param_2[4] = 0x78882;
  param_2[5] = DAT_001dbcb0;
  param_2[6] = DAT_001dbcb4;
  param_2[7] = DAT_001dbcb8;
  param_2[8] = DAT_001dbcbc;
  param_2[9] = DAT_001dbcc0;
  param_2[10] = DAT_001dbcc4;
  param_2[0xb] = DAT_001dbcc8;
  uVar1 = DAT_001dbccc;
  param_2[0xd] = 0x208b4;
  param_2[0xc] = uVar1;
  param_2[0xe] = DAT_001dbcac;
  param_2[0xf] = DAT_001fa5e4;
  uVar3 = DAT_001dbca8;
  param_2[0x11] = 0x8b7;
  param_2[0x12] = 0;
  param_2[0x10] = uVar3;
  return param_2 + 0x13;
}

/* FUN_00083e10 @ 0x83e10 (692 bytes) */
int FUN_00083e10(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  void *pvVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint *in_stack_00000040;
  uint *in_stack_00000044;
  uint in_stack_00000048;
  uint in_stack_0000004c;
  uint *in_stack_00000050;
  uint *in_stack_00000054;
  
  iVar19 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar19 + 1U) {
    sVar9 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar15 = _calloc(sVar9 + 0x200,1);
    if (sVar9 != 0) {
      _memcpy(pvVar15,*(void **)(param_1 + 0x3c8),sVar9);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar15;
    iVar19 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar16 = *(int *)(param_1 + 0x3c8);
  iVar10 = iVar19 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar19 + 1;
  iVar19 = iVar10 + iVar16;
  *(int *)(param_1 + 0x3dc) = iVar19;
  *(undefined4 *)(iVar10 + iVar16) = 0;
  *(undefined1 *)(iVar19 + 3) = 0x44;
  uVar14 = *(uint *)(iVar10 + iVar16);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar10 + iVar16) = uVar2 | uVar1 | uVar14 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar10 + iVar16) = uVar3 | uVar2 | uVar1 | uVar14 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar10 + iVar16) = uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar10 + iVar16) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff8010ff;
  *(uint *)(iVar10 + iVar16) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff0010ff;
  uVar13 = *(uint *)(iVar19 + 4);
  uVar17 = *(uint *)(iVar19 + 8);
  uVar11 = param_5 & 0xf;
  uVar12 = in_stack_00000038 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  uVar2 = (in_stack_0000003c & 0xff) << 5;
  *(uint *)(iVar19 + 4) = uVar1 | uVar11 | uVar13 & 0xffffe000;
  uVar3 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar19 + 4) = uVar3 | uVar1 | uVar11 | uVar13 & 0xffff0000;
  uVar4 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar19 + 4) = uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfff80000;
  uVar5 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar19 + 4) = uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xffc00000;
  uVar14 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar19 + 4) = uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfe000000;
  uVar6 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar19 + 4) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfc000000;
  uVar7 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar19 + 4) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf8000000;
  uVar8 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar19 + 4) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf0000000
  ;
  uVar13 = param_8[3];
  *(uint *)(iVar19 + 8) = uVar2 | uVar12 | uVar17 & 0xffffe000;
  uVar18 = *(uint *)(iVar19 + 0xc);
  *(uint *)(iVar19 + 4) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11;
  uVar1 = (*in_stack_00000040 & 7) << 0xd;
  uVar11 = in_stack_00000048 & 0xf;
  *(uint *)(iVar19 + 8) = uVar1 | uVar2 | uVar12 | uVar17 & 0xffff0000;
  uVar3 = (in_stack_0000004c & 0xff) << 5;
  uVar4 = (in_stack_00000040[1] & 7) << 0x10;
  *(uint *)(iVar19 + 8) = uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xfff80000;
  uVar5 = (in_stack_00000040[2] & 7) << 0x13;
  *(uint *)(iVar19 + 8) = uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xffc00000;
  uVar14 = (in_stack_00000040[3] & 7) << 0x16;
  *(uint *)(iVar19 + 8) = uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xfe000000;
  uVar6 = (*in_stack_00000044 & 1) << 0x19;
  *(uint *)(iVar19 + 8) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xfc000000;
  uVar7 = (in_stack_00000044[1] & 1) << 0x1a;
  *(uint *)(iVar19 + 8) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xf8000000;
  uVar8 = (in_stack_00000044[2] & 1) << 0x1b;
  *(uint *)(iVar19 + 8) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xf0000000
  ;
  uVar13 = in_stack_00000044[3];
  *(uint *)(iVar19 + 0xc) = uVar3 | uVar11 | uVar18 & 0xffffe000;
  *(uint *)(iVar19 + 8) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12;
  uVar1 = (*in_stack_00000050 & 7) << 0xd;
  *(uint *)(iVar19 + 0xc) = uVar1 | uVar3 | uVar11 | uVar18 & 0xffff0000;
  uVar2 = (in_stack_00000050[1] & 7) << 0x10;
  *(uint *)(iVar19 + 0xc) = uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xfff80000;
  uVar4 = (in_stack_00000050[2] & 7) << 0x13;
  *(uint *)(iVar19 + 0xc) = uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xffc00000;
  uVar5 = (in_stack_00000050[3] & 7) << 0x16;
  *(uint *)(iVar19 + 0xc) = uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xfe000000;
  uVar14 = (*in_stack_00000054 & 1) << 0x19;
  *(uint *)(iVar19 + 0xc) =
       uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xfc000000;
  uVar6 = (in_stack_00000054[1] & 1) << 0x1a;
  *(uint *)(iVar19 + 0xc) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xf8000000;
  uVar7 = (in_stack_00000054[2] & 1) << 0x1b;
  *(uint *)(iVar19 + 0xc) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xf0000000
  ;
  *(uint *)(iVar19 + 0xc) =
       (in_stack_00000054[3] & 1) << 0x1c |
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_000840d0 @ 0x840d0 (548 bytes) */
int FUN_000840d0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  void *pvVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint *in_stack_00000040;
  uint *in_stack_00000044;
  
  iVar16 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar16 + 1U) {
    sVar9 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar15 = _calloc(sVar9 + 0x200,1);
    if (sVar9 != 0) {
      _memcpy(pvVar15,*(void **)(param_1 + 0x3c8),sVar9);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar15;
    iVar16 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar17 = *(int *)(param_1 + 0x3c8);
  iVar10 = iVar16 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar16 + 1;
  iVar16 = iVar10 + iVar17;
  *(int *)(param_1 + 0x3dc) = iVar16;
  *(undefined4 *)(iVar10 + iVar17) = 0;
  *(undefined1 *)(iVar16 + 3) = 1;
  uVar14 = *(uint *)(iVar10 + iVar17);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar10 + iVar17) = uVar2 | uVar1 | uVar14 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar10 + iVar17) = uVar3 | uVar2 | uVar1 | uVar14 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar10 + iVar17) = uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar10 + iVar17) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff8010ff;
  *(uint *)(iVar10 + iVar17) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff0010ff;
  uVar13 = *(uint *)(iVar16 + 4);
  uVar18 = *(uint *)(iVar16 + 8);
  uVar11 = param_5 & 0xf;
  uVar12 = in_stack_00000038 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  uVar2 = (in_stack_0000003c & 0xff) << 5;
  *(uint *)(iVar16 + 4) = uVar1 | uVar11 | uVar13 & 0xffffe000;
  uVar3 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar16 + 4) = uVar3 | uVar1 | uVar11 | uVar13 & 0xffff0000;
  uVar4 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar16 + 4) = uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfff80000;
  uVar5 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar16 + 4) = uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xffc00000;
  uVar14 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar16 + 4) = uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfe000000;
  uVar6 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar16 + 4) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfc000000;
  uVar7 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 4) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf8000000;
  uVar8 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 4) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf0000000
  ;
  uVar13 = param_8[3];
  *(uint *)(iVar16 + 8) = uVar2 | uVar12 | uVar18 & 0xffffe000;
  *(uint *)(iVar16 + 4) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11;
  uVar1 = (*in_stack_00000040 & 7) << 0xd;
  *(uint *)(iVar16 + 8) = uVar1 | uVar2 | uVar12 | uVar18 & 0xffff0000;
  uVar3 = (in_stack_00000040[1] & 7) << 0x10;
  *(uint *)(iVar16 + 8) = uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfff80000;
  uVar4 = (in_stack_00000040[2] & 7) << 0x13;
  *(uint *)(iVar16 + 8) = uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xffc00000;
  uVar5 = (in_stack_00000040[3] & 7) << 0x16;
  *(uint *)(iVar16 + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfe000000;
  uVar14 = (*in_stack_00000044 & 1) << 0x19;
  *(uint *)(iVar16 + 8) =
       uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfc000000;
  uVar6 = (in_stack_00000044[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 8) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf8000000;
  uVar7 = (in_stack_00000044[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 8) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf0000000
  ;
  uVar1 = (in_stack_00000044[3] & 1) << 0x1c |
          uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12;
  *(uint *)(iVar16 + 0xc) = uVar1;
  *(uint *)(iVar16 + 8) = uVar1;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00084300 @ 0x84300 (472 bytes) */
int FUN_00084300(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  size_t sVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  void *pvVar14;
  int iVar15;
  int iVar16;
  
  iVar15 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar15 + 1U) {
    sVar7 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar14 = _calloc(sVar7 + 0x200,1);
    if (sVar7 != 0) {
      _memcpy(pvVar14,*(void **)(param_1 + 0x3c8),sVar7);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar14;
    iVar15 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar16 = *(int *)(param_1 + 0x3c8);
  iVar8 = iVar15 * 0x10;
  uVar9 = param_5 & 0xf;
  *(int *)(param_1 + 0x3cc) = iVar15 + 1;
  iVar15 = iVar8 + iVar16;
  *(int *)(param_1 + 0x3dc) = iVar15;
  *(undefined4 *)(iVar8 + iVar16) = 0;
  *(undefined1 *)(iVar15 + 3) = 2;
  uVar12 = *(uint *)(iVar8 + iVar16);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar8 + iVar16) = uVar2 | uVar1 | uVar12 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar8 + iVar16) = uVar3 | uVar2 | uVar1 | uVar12 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar8 + iVar16) = uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar8 + iVar16) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xff8010ff;
  *(uint *)(iVar8 + iVar16) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xff0010ff;
  uVar13 = *(uint *)(iVar15 + 4);
  uVar11 = (param_6 & 0xff) << 5;
  *(uint *)(iVar15 + 4) = uVar11 | uVar9 | uVar13 & 0xffffe000;
  uVar1 = (*param_7 & 7) << 0xd;
  uVar10 = (param_6 & 0xff) << 5 | uVar9 | 0x16da000;
  *(uint *)(iVar15 + 4) = uVar1 | uVar11 | uVar9 | uVar13 & 0xffff0000;
  uVar2 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar15 + 4) = uVar2 | uVar1 | uVar11 | uVar9 | uVar13 & 0xfff80000;
  uVar3 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar15 + 4) = uVar3 | uVar2 | uVar1 | uVar11 | uVar9 | uVar13 & 0xffc00000;
  uVar4 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar15 + 4) = uVar4 | uVar3 | uVar2 | uVar1 | uVar11 | uVar9 | uVar13 & 0xfe000000;
  uVar5 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar15 + 4) =
       uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar11 | uVar9 | uVar13 & 0xfc000000;
  uVar12 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar15 + 4) =
       uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar11 | uVar9 | uVar13 & 0xf8000000;
  uVar6 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar15 + 4) =
       uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar11 | uVar9 | uVar13 & 0xf0000000
  ;
  *(uint *)(iVar15 + 4) =
       (param_8[3] & 1) << 0x1c |
       uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar11 | uVar9;
  *(uint *)(iVar15 + 8) = uVar10;
  *(uint *)(iVar15 + 0xc) = uVar10;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_000844e0 @ 0x844e0 (548 bytes) */
int FUN_000844e0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  void *pvVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint *in_stack_00000040;
  uint *in_stack_00000044;
  
  iVar16 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar16 + 1U) {
    sVar9 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar15 = _calloc(sVar9 + 0x200,1);
    if (sVar9 != 0) {
      _memcpy(pvVar15,*(void **)(param_1 + 0x3c8),sVar9);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar15;
    iVar16 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar17 = *(int *)(param_1 + 0x3c8);
  iVar10 = iVar16 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar16 + 1;
  iVar16 = iVar10 + iVar17;
  *(int *)(param_1 + 0x3dc) = iVar16;
  *(undefined4 *)(iVar10 + iVar17) = 0;
  *(undefined1 *)(iVar16 + 3) = 2;
  uVar14 = *(uint *)(iVar10 + iVar17);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar10 + iVar17) = uVar2 | uVar1 | uVar14 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar10 + iVar17) = uVar3 | uVar2 | uVar1 | uVar14 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar10 + iVar17) = uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar10 + iVar17) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff8010ff;
  *(uint *)(iVar10 + iVar17) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff0010ff;
  uVar13 = *(uint *)(iVar16 + 4);
  uVar18 = *(uint *)(iVar16 + 8);
  uVar11 = param_5 & 0xf;
  uVar12 = in_stack_00000038 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  uVar2 = (in_stack_0000003c & 0xff) << 5;
  *(uint *)(iVar16 + 4) = uVar1 | uVar11 | uVar13 & 0xffffe000;
  uVar3 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar16 + 4) = uVar3 | uVar1 | uVar11 | uVar13 & 0xffff0000;
  uVar4 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar16 + 4) = uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfff80000;
  uVar5 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar16 + 4) = uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xffc00000;
  uVar14 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar16 + 4) = uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfe000000;
  uVar6 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar16 + 4) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfc000000;
  uVar7 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 4) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf8000000;
  uVar8 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 4) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf0000000
  ;
  uVar13 = param_8[3];
  *(uint *)(iVar16 + 8) = uVar2 | uVar12 | uVar18 & 0xffffe000;
  *(uint *)(iVar16 + 4) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11;
  uVar1 = (*in_stack_00000040 & 7) << 0xd;
  *(uint *)(iVar16 + 8) = uVar1 | uVar2 | uVar12 | uVar18 & 0xffff0000;
  uVar3 = (in_stack_00000040[1] & 7) << 0x10;
  *(uint *)(iVar16 + 8) = uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfff80000;
  uVar4 = (in_stack_00000040[2] & 7) << 0x13;
  *(uint *)(iVar16 + 8) = uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xffc00000;
  uVar5 = (in_stack_00000040[3] & 7) << 0x16;
  *(uint *)(iVar16 + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfe000000;
  uVar14 = (*in_stack_00000044 & 1) << 0x19;
  *(uint *)(iVar16 + 8) =
       uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfc000000;
  uVar6 = (in_stack_00000044[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 8) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf8000000;
  uVar7 = (in_stack_00000044[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 8) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf0000000
  ;
  uVar1 = (in_stack_00000044[3] & 1) << 0x1c |
          uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12;
  *(uint *)(iVar16 + 0xc) = uVar1;
  *(uint *)(iVar16 + 8) = uVar1;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00084710 @ 0x84710 (548 bytes) */
int FUN_00084710(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  void *pvVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint *in_stack_00000040;
  uint *in_stack_00000044;
  
  iVar16 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar16 + 1U) {
    sVar9 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar15 = _calloc(sVar9 + 0x200,1);
    if (sVar9 != 0) {
      _memcpy(pvVar15,*(void **)(param_1 + 0x3c8),sVar9);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar15;
    iVar16 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar17 = *(int *)(param_1 + 0x3c8);
  iVar10 = iVar16 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar16 + 1;
  iVar16 = iVar10 + iVar17;
  *(int *)(param_1 + 0x3dc) = iVar16;
  *(undefined4 *)(iVar10 + iVar17) = 0;
  *(undefined1 *)(iVar16 + 3) = 3;
  uVar14 = *(uint *)(iVar10 + iVar17);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar10 + iVar17) = uVar2 | uVar1 | uVar14 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar10 + iVar17) = uVar3 | uVar2 | uVar1 | uVar14 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar10 + iVar17) = uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar10 + iVar17) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff8010ff;
  *(uint *)(iVar10 + iVar17) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff0010ff;
  uVar13 = *(uint *)(iVar16 + 4);
  uVar18 = *(uint *)(iVar16 + 8);
  uVar11 = param_5 & 0xf;
  uVar12 = in_stack_00000038 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  uVar2 = (in_stack_0000003c & 0xff) << 5;
  *(uint *)(iVar16 + 4) = uVar1 | uVar11 | uVar13 & 0xffffe000;
  uVar3 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar16 + 4) = uVar3 | uVar1 | uVar11 | uVar13 & 0xffff0000;
  uVar4 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar16 + 4) = uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfff80000;
  uVar5 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar16 + 4) = uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xffc00000;
  uVar14 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar16 + 4) = uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfe000000;
  uVar6 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar16 + 4) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfc000000;
  uVar7 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 4) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf8000000;
  uVar8 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 4) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf0000000
  ;
  uVar13 = param_8[3];
  *(uint *)(iVar16 + 8) = uVar2 | uVar12 | uVar18 & 0xffffe000;
  *(uint *)(iVar16 + 4) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11;
  uVar1 = (*in_stack_00000040 & 7) << 0xd;
  *(uint *)(iVar16 + 8) = uVar1 | uVar2 | uVar12 | uVar18 & 0xffff0000;
  uVar3 = (in_stack_00000040[1] & 7) << 0x10;
  *(uint *)(iVar16 + 8) = uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfff80000;
  uVar4 = (in_stack_00000040[2] & 7) << 0x13;
  *(uint *)(iVar16 + 8) = uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xffc00000;
  uVar5 = (in_stack_00000040[3] & 7) << 0x16;
  *(uint *)(iVar16 + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfe000000;
  uVar14 = (*in_stack_00000044 & 1) << 0x19;
  *(uint *)(iVar16 + 8) =
       uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfc000000;
  uVar6 = (in_stack_00000044[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 8) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf8000000;
  uVar7 = (in_stack_00000044[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 8) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf0000000
  ;
  uVar1 = (in_stack_00000044[3] & 1) << 0x1c |
          uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12;
  *(uint *)(iVar16 + 0xc) = uVar1;
  *(uint *)(iVar16 + 8) = uVar1;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00084940 @ 0x84940 (692 bytes) */
int FUN_00084940(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  void *pvVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint *in_stack_00000040;
  uint *in_stack_00000044;
  uint in_stack_00000048;
  uint in_stack_0000004c;
  uint *in_stack_00000050;
  uint *in_stack_00000054;
  
  iVar19 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar19 + 1U) {
    sVar9 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar15 = _calloc(sVar9 + 0x200,1);
    if (sVar9 != 0) {
      _memcpy(pvVar15,*(void **)(param_1 + 0x3c8),sVar9);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar15;
    iVar19 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar16 = *(int *)(param_1 + 0x3c8);
  iVar10 = iVar19 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar19 + 1;
  iVar19 = iVar10 + iVar16;
  *(int *)(param_1 + 0x3dc) = iVar19;
  *(undefined4 *)(iVar10 + iVar16) = 0;
  *(undefined1 *)(iVar19 + 3) = 4;
  uVar14 = *(uint *)(iVar10 + iVar16);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar10 + iVar16) = uVar2 | uVar1 | uVar14 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar10 + iVar16) = uVar3 | uVar2 | uVar1 | uVar14 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar10 + iVar16) = uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar10 + iVar16) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff8010ff;
  *(uint *)(iVar10 + iVar16) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff0010ff;
  uVar13 = *(uint *)(iVar19 + 4);
  uVar17 = *(uint *)(iVar19 + 8);
  uVar11 = param_5 & 0xf;
  uVar12 = in_stack_00000038 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  uVar2 = (in_stack_0000003c & 0xff) << 5;
  *(uint *)(iVar19 + 4) = uVar1 | uVar11 | uVar13 & 0xffffe000;
  uVar3 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar19 + 4) = uVar3 | uVar1 | uVar11 | uVar13 & 0xffff0000;
  uVar4 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar19 + 4) = uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfff80000;
  uVar5 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar19 + 4) = uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xffc00000;
  uVar14 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar19 + 4) = uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfe000000;
  uVar6 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar19 + 4) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfc000000;
  uVar7 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar19 + 4) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf8000000;
  uVar8 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar19 + 4) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf0000000
  ;
  uVar13 = param_8[3];
  *(uint *)(iVar19 + 8) = uVar2 | uVar12 | uVar17 & 0xffffe000;
  uVar18 = *(uint *)(iVar19 + 0xc);
  *(uint *)(iVar19 + 4) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11;
  uVar1 = (*in_stack_00000040 & 7) << 0xd;
  uVar11 = in_stack_00000048 & 0xf;
  *(uint *)(iVar19 + 8) = uVar1 | uVar2 | uVar12 | uVar17 & 0xffff0000;
  uVar3 = (in_stack_0000004c & 0xff) << 5;
  uVar4 = (in_stack_00000040[1] & 7) << 0x10;
  *(uint *)(iVar19 + 8) = uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xfff80000;
  uVar5 = (in_stack_00000040[2] & 7) << 0x13;
  *(uint *)(iVar19 + 8) = uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xffc00000;
  uVar14 = (in_stack_00000040[3] & 7) << 0x16;
  *(uint *)(iVar19 + 8) = uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xfe000000;
  uVar6 = (*in_stack_00000044 & 1) << 0x19;
  *(uint *)(iVar19 + 8) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xfc000000;
  uVar7 = (in_stack_00000044[1] & 1) << 0x1a;
  *(uint *)(iVar19 + 8) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xf8000000;
  uVar8 = (in_stack_00000044[2] & 1) << 0x1b;
  *(uint *)(iVar19 + 8) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xf0000000
  ;
  uVar13 = in_stack_00000044[3];
  *(uint *)(iVar19 + 0xc) = uVar3 | uVar11 | uVar18 & 0xffffe000;
  *(uint *)(iVar19 + 8) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12;
  uVar1 = (*in_stack_00000050 & 7) << 0xd;
  *(uint *)(iVar19 + 0xc) = uVar1 | uVar3 | uVar11 | uVar18 & 0xffff0000;
  uVar2 = (in_stack_00000050[1] & 7) << 0x10;
  *(uint *)(iVar19 + 0xc) = uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xfff80000;
  uVar4 = (in_stack_00000050[2] & 7) << 0x13;
  *(uint *)(iVar19 + 0xc) = uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xffc00000;
  uVar5 = (in_stack_00000050[3] & 7) << 0x16;
  *(uint *)(iVar19 + 0xc) = uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xfe000000;
  uVar14 = (*in_stack_00000054 & 1) << 0x19;
  *(uint *)(iVar19 + 0xc) =
       uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xfc000000;
  uVar6 = (in_stack_00000054[1] & 1) << 0x1a;
  *(uint *)(iVar19 + 0xc) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xf8000000;
  uVar7 = (in_stack_00000054[2] & 1) << 0x1b;
  *(uint *)(iVar19 + 0xc) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xf0000000
  ;
  *(uint *)(iVar19 + 0xc) =
       (in_stack_00000054[3] & 1) << 0x1c |
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00084c00 @ 0x84c00 (692 bytes) */
int FUN_00084c00(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  void *pvVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint *in_stack_00000040;
  uint *in_stack_00000044;
  uint in_stack_00000048;
  uint in_stack_0000004c;
  uint *in_stack_00000050;
  uint *in_stack_00000054;
  
  iVar19 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar19 + 1U) {
    sVar9 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar15 = _calloc(sVar9 + 0x200,1);
    if (sVar9 != 0) {
      _memcpy(pvVar15,*(void **)(param_1 + 0x3c8),sVar9);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar15;
    iVar19 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar16 = *(int *)(param_1 + 0x3c8);
  iVar10 = iVar19 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar19 + 1;
  iVar19 = iVar10 + iVar16;
  *(int *)(param_1 + 0x3dc) = iVar19;
  *(undefined4 *)(iVar10 + iVar16) = 0;
  *(undefined1 *)(iVar19 + 3) = 0xb;
  uVar14 = *(uint *)(iVar10 + iVar16);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar10 + iVar16) = uVar2 | uVar1 | uVar14 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar10 + iVar16) = uVar3 | uVar2 | uVar1 | uVar14 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar10 + iVar16) = uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar10 + iVar16) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff8010ff;
  *(uint *)(iVar10 + iVar16) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff0010ff;
  uVar13 = *(uint *)(iVar19 + 4);
  uVar17 = *(uint *)(iVar19 + 8);
  uVar11 = param_5 & 0xf;
  uVar12 = in_stack_00000038 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  uVar2 = (in_stack_0000003c & 0xff) << 5;
  *(uint *)(iVar19 + 4) = uVar1 | uVar11 | uVar13 & 0xffffe000;
  uVar3 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar19 + 4) = uVar3 | uVar1 | uVar11 | uVar13 & 0xffff0000;
  uVar4 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar19 + 4) = uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfff80000;
  uVar5 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar19 + 4) = uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xffc00000;
  uVar14 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar19 + 4) = uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfe000000;
  uVar6 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar19 + 4) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfc000000;
  uVar7 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar19 + 4) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf8000000;
  uVar8 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar19 + 4) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf0000000
  ;
  uVar13 = param_8[3];
  *(uint *)(iVar19 + 8) = uVar2 | uVar12 | uVar17 & 0xffffe000;
  uVar18 = *(uint *)(iVar19 + 0xc);
  *(uint *)(iVar19 + 4) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11;
  uVar1 = (*in_stack_00000040 & 7) << 0xd;
  uVar11 = in_stack_00000048 & 0xf;
  *(uint *)(iVar19 + 8) = uVar1 | uVar2 | uVar12 | uVar17 & 0xffff0000;
  uVar3 = (in_stack_0000004c & 0xff) << 5;
  uVar4 = (in_stack_00000040[1] & 7) << 0x10;
  *(uint *)(iVar19 + 8) = uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xfff80000;
  uVar5 = (in_stack_00000040[2] & 7) << 0x13;
  *(uint *)(iVar19 + 8) = uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xffc00000;
  uVar14 = (in_stack_00000040[3] & 7) << 0x16;
  *(uint *)(iVar19 + 8) = uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xfe000000;
  uVar6 = (*in_stack_00000044 & 1) << 0x19;
  *(uint *)(iVar19 + 8) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xfc000000;
  uVar7 = (in_stack_00000044[1] & 1) << 0x1a;
  *(uint *)(iVar19 + 8) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xf8000000;
  uVar8 = (in_stack_00000044[2] & 1) << 0x1b;
  *(uint *)(iVar19 + 8) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xf0000000
  ;
  uVar13 = in_stack_00000044[3];
  *(uint *)(iVar19 + 0xc) = uVar3 | uVar11 | uVar18 & 0xffffe000;
  *(uint *)(iVar19 + 8) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12;
  uVar1 = (*in_stack_00000050 & 7) << 0xd;
  *(uint *)(iVar19 + 0xc) = uVar1 | uVar3 | uVar11 | uVar18 & 0xffff0000;
  uVar2 = (in_stack_00000050[1] & 7) << 0x10;
  *(uint *)(iVar19 + 0xc) = uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xfff80000;
  uVar4 = (in_stack_00000050[2] & 7) << 0x13;
  *(uint *)(iVar19 + 0xc) = uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xffc00000;
  uVar5 = (in_stack_00000050[3] & 7) << 0x16;
  *(uint *)(iVar19 + 0xc) = uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xfe000000;
  uVar14 = (*in_stack_00000054 & 1) << 0x19;
  *(uint *)(iVar19 + 0xc) =
       uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xfc000000;
  uVar6 = (in_stack_00000054[1] & 1) << 0x1a;
  *(uint *)(iVar19 + 0xc) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xf8000000;
  uVar7 = (in_stack_00000054[2] & 1) << 0x1b;
  *(uint *)(iVar19 + 0xc) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xf0000000
  ;
  *(uint *)(iVar19 + 0xc) =
       (in_stack_00000054[3] & 1) << 0x1c |
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00084ec0 @ 0x84ec0 (692 bytes) */
int FUN_00084ec0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  void *pvVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint *in_stack_00000040;
  uint *in_stack_00000044;
  uint in_stack_00000048;
  uint in_stack_0000004c;
  uint *in_stack_00000050;
  uint *in_stack_00000054;
  
  iVar19 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar19 + 1U) {
    sVar9 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar15 = _calloc(sVar9 + 0x200,1);
    if (sVar9 != 0) {
      _memcpy(pvVar15,*(void **)(param_1 + 0x3c8),sVar9);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar15;
    iVar19 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar16 = *(int *)(param_1 + 0x3c8);
  iVar10 = iVar19 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar19 + 1;
  iVar19 = iVar10 + iVar16;
  *(int *)(param_1 + 0x3dc) = iVar19;
  *(undefined4 *)(iVar10 + iVar16) = 0;
  *(undefined1 *)(iVar19 + 3) = 0xc;
  uVar14 = *(uint *)(iVar10 + iVar16);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar10 + iVar16) = uVar2 | uVar1 | uVar14 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar10 + iVar16) = uVar3 | uVar2 | uVar1 | uVar14 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar10 + iVar16) = uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar10 + iVar16) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff8010ff;
  *(uint *)(iVar10 + iVar16) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff0010ff;
  uVar13 = *(uint *)(iVar19 + 4);
  uVar17 = *(uint *)(iVar19 + 8);
  uVar11 = param_5 & 0xf;
  uVar12 = in_stack_00000038 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  uVar2 = (in_stack_0000003c & 0xff) << 5;
  *(uint *)(iVar19 + 4) = uVar1 | uVar11 | uVar13 & 0xffffe000;
  uVar3 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar19 + 4) = uVar3 | uVar1 | uVar11 | uVar13 & 0xffff0000;
  uVar4 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar19 + 4) = uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfff80000;
  uVar5 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar19 + 4) = uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xffc00000;
  uVar14 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar19 + 4) = uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfe000000;
  uVar6 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar19 + 4) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfc000000;
  uVar7 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar19 + 4) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf8000000;
  uVar8 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar19 + 4) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf0000000
  ;
  uVar13 = param_8[3];
  *(uint *)(iVar19 + 8) = uVar2 | uVar12 | uVar17 & 0xffffe000;
  uVar18 = *(uint *)(iVar19 + 0xc);
  *(uint *)(iVar19 + 4) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11;
  uVar1 = (*in_stack_00000040 & 7) << 0xd;
  uVar11 = in_stack_00000048 & 0xf;
  *(uint *)(iVar19 + 8) = uVar1 | uVar2 | uVar12 | uVar17 & 0xffff0000;
  uVar3 = (in_stack_0000004c & 0xff) << 5;
  uVar4 = (in_stack_00000040[1] & 7) << 0x10;
  *(uint *)(iVar19 + 8) = uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xfff80000;
  uVar5 = (in_stack_00000040[2] & 7) << 0x13;
  *(uint *)(iVar19 + 8) = uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xffc00000;
  uVar14 = (in_stack_00000040[3] & 7) << 0x16;
  *(uint *)(iVar19 + 8) = uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xfe000000;
  uVar6 = (*in_stack_00000044 & 1) << 0x19;
  *(uint *)(iVar19 + 8) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xfc000000;
  uVar7 = (in_stack_00000044[1] & 1) << 0x1a;
  *(uint *)(iVar19 + 8) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xf8000000;
  uVar8 = (in_stack_00000044[2] & 1) << 0x1b;
  *(uint *)(iVar19 + 8) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12 | uVar17 & 0xf0000000
  ;
  uVar13 = in_stack_00000044[3];
  *(uint *)(iVar19 + 0xc) = uVar3 | uVar11 | uVar18 & 0xffffe000;
  *(uint *)(iVar19 + 8) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar1 | uVar2 | uVar12;
  uVar1 = (*in_stack_00000050 & 7) << 0xd;
  *(uint *)(iVar19 + 0xc) = uVar1 | uVar3 | uVar11 | uVar18 & 0xffff0000;
  uVar2 = (in_stack_00000050[1] & 7) << 0x10;
  *(uint *)(iVar19 + 0xc) = uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xfff80000;
  uVar4 = (in_stack_00000050[2] & 7) << 0x13;
  *(uint *)(iVar19 + 0xc) = uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xffc00000;
  uVar5 = (in_stack_00000050[3] & 7) << 0x16;
  *(uint *)(iVar19 + 0xc) = uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xfe000000;
  uVar14 = (*in_stack_00000054 & 1) << 0x19;
  *(uint *)(iVar19 + 0xc) =
       uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xfc000000;
  uVar6 = (in_stack_00000054[1] & 1) << 0x1a;
  *(uint *)(iVar19 + 0xc) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xf8000000;
  uVar7 = (in_stack_00000054[2] & 1) << 0x1b;
  *(uint *)(iVar19 + 0xc) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11 | uVar18 & 0xf0000000
  ;
  *(uint *)(iVar19 + 0xc) =
       (in_stack_00000054[3] & 1) << 0x1c |
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | uVar11;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00085180 @ 0x85180 (548 bytes) */
int FUN_00085180(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  void *pvVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint *in_stack_00000040;
  uint *in_stack_00000044;
  
  iVar16 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar16 + 1U) {
    sVar9 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar15 = _calloc(sVar9 + 0x200,1);
    if (sVar9 != 0) {
      _memcpy(pvVar15,*(void **)(param_1 + 0x3c8),sVar9);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar15;
    iVar16 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar17 = *(int *)(param_1 + 0x3c8);
  iVar10 = iVar16 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar16 + 1;
  iVar16 = iVar10 + iVar17;
  *(int *)(param_1 + 0x3dc) = iVar16;
  *(undefined4 *)(iVar10 + iVar17) = 0;
  *(undefined1 *)(iVar16 + 3) = 8;
  uVar14 = *(uint *)(iVar10 + iVar17);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar10 + iVar17) = uVar2 | uVar1 | uVar14 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar10 + iVar17) = uVar3 | uVar2 | uVar1 | uVar14 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar10 + iVar17) = uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar10 + iVar17) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff8010ff;
  *(uint *)(iVar10 + iVar17) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff0010ff;
  uVar13 = *(uint *)(iVar16 + 4);
  uVar18 = *(uint *)(iVar16 + 8);
  uVar11 = param_5 & 0xf;
  uVar12 = in_stack_00000038 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  uVar2 = (in_stack_0000003c & 0xff) << 5;
  *(uint *)(iVar16 + 4) = uVar1 | uVar11 | uVar13 & 0xffffe000;
  uVar3 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar16 + 4) = uVar3 | uVar1 | uVar11 | uVar13 & 0xffff0000;
  uVar4 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar16 + 4) = uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfff80000;
  uVar5 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar16 + 4) = uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xffc00000;
  uVar14 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar16 + 4) = uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfe000000;
  uVar6 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar16 + 4) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfc000000;
  uVar7 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 4) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf8000000;
  uVar8 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 4) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf0000000
  ;
  uVar13 = param_8[3];
  *(uint *)(iVar16 + 8) = uVar2 | uVar12 | uVar18 & 0xffffe000;
  *(uint *)(iVar16 + 4) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11;
  uVar1 = (*in_stack_00000040 & 7) << 0xd;
  *(uint *)(iVar16 + 8) = uVar1 | uVar2 | uVar12 | uVar18 & 0xffff0000;
  uVar3 = (in_stack_00000040[1] & 7) << 0x10;
  *(uint *)(iVar16 + 8) = uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfff80000;
  uVar4 = (in_stack_00000040[2] & 7) << 0x13;
  *(uint *)(iVar16 + 8) = uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xffc00000;
  uVar5 = (in_stack_00000040[3] & 7) << 0x16;
  *(uint *)(iVar16 + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfe000000;
  uVar14 = (*in_stack_00000044 & 1) << 0x19;
  *(uint *)(iVar16 + 8) =
       uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfc000000;
  uVar6 = (in_stack_00000044[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 8) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf8000000;
  uVar7 = (in_stack_00000044[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 8) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf0000000
  ;
  uVar1 = (in_stack_00000044[3] & 1) << 0x1c |
          uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12;
  *(uint *)(iVar16 + 0xc) = uVar1;
  *(uint *)(iVar16 + 8) = uVar1;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_000853b0 @ 0x853b0 (548 bytes) */
int FUN_000853b0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  void *pvVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint *in_stack_00000040;
  uint *in_stack_00000044;
  
  iVar16 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar16 + 1U) {
    sVar9 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar15 = _calloc(sVar9 + 0x200,1);
    if (sVar9 != 0) {
      _memcpy(pvVar15,*(void **)(param_1 + 0x3c8),sVar9);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar15;
    iVar16 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar17 = *(int *)(param_1 + 0x3c8);
  iVar10 = iVar16 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar16 + 1;
  iVar16 = iVar10 + iVar17;
  *(int *)(param_1 + 0x3dc) = iVar16;
  *(undefined4 *)(iVar10 + iVar17) = 0;
  *(undefined1 *)(iVar16 + 3) = 7;
  uVar14 = *(uint *)(iVar10 + iVar17);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar10 + iVar17) = uVar2 | uVar1 | uVar14 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar10 + iVar17) = uVar3 | uVar2 | uVar1 | uVar14 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar10 + iVar17) = uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar10 + iVar17) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff8010ff;
  *(uint *)(iVar10 + iVar17) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff0010ff;
  uVar13 = *(uint *)(iVar16 + 4);
  uVar18 = *(uint *)(iVar16 + 8);
  uVar11 = param_5 & 0xf;
  uVar12 = in_stack_00000038 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  uVar2 = (in_stack_0000003c & 0xff) << 5;
  *(uint *)(iVar16 + 4) = uVar1 | uVar11 | uVar13 & 0xffffe000;
  uVar3 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar16 + 4) = uVar3 | uVar1 | uVar11 | uVar13 & 0xffff0000;
  uVar4 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar16 + 4) = uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfff80000;
  uVar5 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar16 + 4) = uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xffc00000;
  uVar14 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar16 + 4) = uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfe000000;
  uVar6 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar16 + 4) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfc000000;
  uVar7 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 4) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf8000000;
  uVar8 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 4) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf0000000
  ;
  uVar13 = param_8[3];
  *(uint *)(iVar16 + 8) = uVar2 | uVar12 | uVar18 & 0xffffe000;
  *(uint *)(iVar16 + 4) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11;
  uVar1 = (*in_stack_00000040 & 7) << 0xd;
  *(uint *)(iVar16 + 8) = uVar1 | uVar2 | uVar12 | uVar18 & 0xffff0000;
  uVar3 = (in_stack_00000040[1] & 7) << 0x10;
  *(uint *)(iVar16 + 8) = uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfff80000;
  uVar4 = (in_stack_00000040[2] & 7) << 0x13;
  *(uint *)(iVar16 + 8) = uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xffc00000;
  uVar5 = (in_stack_00000040[3] & 7) << 0x16;
  *(uint *)(iVar16 + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfe000000;
  uVar14 = (*in_stack_00000044 & 1) << 0x19;
  *(uint *)(iVar16 + 8) =
       uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfc000000;
  uVar6 = (in_stack_00000044[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 8) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf8000000;
  uVar7 = (in_stack_00000044[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 8) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf0000000
  ;
  uVar1 = (in_stack_00000044[3] & 1) << 0x1c |
          uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12;
  *(uint *)(iVar16 + 0xc) = uVar1;
  *(uint *)(iVar16 + 8) = uVar1;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_000855e0 @ 0x855e0 (548 bytes) */
int FUN_000855e0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  void *pvVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint *in_stack_00000040;
  uint *in_stack_00000044;
  
  iVar16 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar16 + 1U) {
    sVar9 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar15 = _calloc(sVar9 + 0x200,1);
    if (sVar9 != 0) {
      _memcpy(pvVar15,*(void **)(param_1 + 0x3c8),sVar9);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar15;
    iVar16 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar17 = *(int *)(param_1 + 0x3c8);
  iVar10 = iVar16 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar16 + 1;
  iVar16 = iVar10 + iVar17;
  *(int *)(param_1 + 0x3dc) = iVar16;
  *(undefined4 *)(iVar10 + iVar17) = 0;
  *(undefined1 *)(iVar16 + 3) = 10;
  uVar14 = *(uint *)(iVar10 + iVar17);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar10 + iVar17) = uVar2 | uVar1 | uVar14 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar10 + iVar17) = uVar3 | uVar2 | uVar1 | uVar14 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar10 + iVar17) = uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar10 + iVar17) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff8010ff;
  *(uint *)(iVar10 + iVar17) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff0010ff;
  uVar13 = *(uint *)(iVar16 + 4);
  uVar18 = *(uint *)(iVar16 + 8);
  uVar11 = param_5 & 0xf;
  uVar12 = in_stack_00000038 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  uVar2 = (in_stack_0000003c & 0xff) << 5;
  *(uint *)(iVar16 + 4) = uVar1 | uVar11 | uVar13 & 0xffffe000;
  uVar3 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar16 + 4) = uVar3 | uVar1 | uVar11 | uVar13 & 0xffff0000;
  uVar4 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar16 + 4) = uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfff80000;
  uVar5 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar16 + 4) = uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xffc00000;
  uVar14 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar16 + 4) = uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfe000000;
  uVar6 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar16 + 4) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfc000000;
  uVar7 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 4) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf8000000;
  uVar8 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 4) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf0000000
  ;
  uVar13 = param_8[3];
  *(uint *)(iVar16 + 8) = uVar2 | uVar12 | uVar18 & 0xffffe000;
  *(uint *)(iVar16 + 4) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11;
  uVar1 = (*in_stack_00000040 & 7) << 0xd;
  *(uint *)(iVar16 + 8) = uVar1 | uVar2 | uVar12 | uVar18 & 0xffff0000;
  uVar3 = (in_stack_00000040[1] & 7) << 0x10;
  *(uint *)(iVar16 + 8) = uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfff80000;
  uVar4 = (in_stack_00000040[2] & 7) << 0x13;
  *(uint *)(iVar16 + 8) = uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xffc00000;
  uVar5 = (in_stack_00000040[3] & 7) << 0x16;
  *(uint *)(iVar16 + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfe000000;
  uVar14 = (*in_stack_00000044 & 1) << 0x19;
  *(uint *)(iVar16 + 8) =
       uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfc000000;
  uVar6 = (in_stack_00000044[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 8) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf8000000;
  uVar7 = (in_stack_00000044[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 8) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf0000000
  ;
  uVar1 = (in_stack_00000044[3] & 1) << 0x1c |
          uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12;
  *(uint *)(iVar16 + 0xc) = uVar1;
  *(uint *)(iVar16 + 8) = uVar1;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00085810 @ 0x85810 (548 bytes) */
int FUN_00085810(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  void *pvVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint *in_stack_00000040;
  uint *in_stack_00000044;
  
  iVar16 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar16 + 1U) {
    sVar9 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar15 = _calloc(sVar9 + 0x200,1);
    if (sVar9 != 0) {
      _memcpy(pvVar15,*(void **)(param_1 + 0x3c8),sVar9);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar15;
    iVar16 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar17 = *(int *)(param_1 + 0x3c8);
  iVar10 = iVar16 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar16 + 1;
  iVar16 = iVar10 + iVar17;
  *(int *)(param_1 + 0x3dc) = iVar16;
  *(undefined4 *)(iVar10 + iVar17) = 0;
  *(undefined1 *)(iVar16 + 3) = 9;
  uVar14 = *(uint *)(iVar10 + iVar17);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar10 + iVar17) = uVar2 | uVar1 | uVar14 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar10 + iVar17) = uVar3 | uVar2 | uVar1 | uVar14 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar10 + iVar17) = uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar10 + iVar17) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff8010ff;
  *(uint *)(iVar10 + iVar17) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff0010ff;
  uVar13 = *(uint *)(iVar16 + 4);
  uVar18 = *(uint *)(iVar16 + 8);
  uVar11 = param_5 & 0xf;
  uVar12 = in_stack_00000038 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  uVar2 = (in_stack_0000003c & 0xff) << 5;
  *(uint *)(iVar16 + 4) = uVar1 | uVar11 | uVar13 & 0xffffe000;
  uVar3 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar16 + 4) = uVar3 | uVar1 | uVar11 | uVar13 & 0xffff0000;
  uVar4 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar16 + 4) = uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfff80000;
  uVar5 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar16 + 4) = uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xffc00000;
  uVar14 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar16 + 4) = uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfe000000;
  uVar6 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar16 + 4) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfc000000;
  uVar7 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 4) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf8000000;
  uVar8 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 4) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf0000000
  ;
  uVar13 = param_8[3];
  *(uint *)(iVar16 + 8) = uVar2 | uVar12 | uVar18 & 0xffffe000;
  *(uint *)(iVar16 + 4) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11;
  uVar1 = (*in_stack_00000040 & 7) << 0xd;
  *(uint *)(iVar16 + 8) = uVar1 | uVar2 | uVar12 | uVar18 & 0xffff0000;
  uVar3 = (in_stack_00000040[1] & 7) << 0x10;
  *(uint *)(iVar16 + 8) = uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfff80000;
  uVar4 = (in_stack_00000040[2] & 7) << 0x13;
  *(uint *)(iVar16 + 8) = uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xffc00000;
  uVar5 = (in_stack_00000040[3] & 7) << 0x16;
  *(uint *)(iVar16 + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfe000000;
  uVar14 = (*in_stack_00000044 & 1) << 0x19;
  *(uint *)(iVar16 + 8) =
       uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfc000000;
  uVar6 = (in_stack_00000044[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 8) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf8000000;
  uVar7 = (in_stack_00000044[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 8) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf0000000
  ;
  uVar1 = (in_stack_00000044[3] & 1) << 0x1c |
          uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12;
  *(uint *)(iVar16 + 0xc) = uVar1;
  *(uint *)(iVar16 + 8) = uVar1;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00085a40 @ 0x85a40 (424 bytes) */
int FUN_00085a40(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  size_t sVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  void *pvVar13;
  int iVar14;
  int iVar15;
  
  iVar14 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar14 + 1U) {
    sVar8 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar13 = _calloc(sVar8 + 0x200,1);
    if (sVar8 != 0) {
      _memcpy(pvVar13,*(void **)(param_1 + 0x3c8),sVar8);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar13;
    iVar14 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar15 = *(int *)(param_1 + 0x3c8);
  iVar9 = iVar14 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar14 + 1;
  iVar14 = iVar9 + iVar15;
  *(int *)(param_1 + 0x3dc) = iVar14;
  *(undefined4 *)(iVar9 + iVar15) = 0;
  *(undefined1 *)(iVar14 + 3) = 0xe;
  uVar12 = *(uint *)(iVar9 + iVar15);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar9 + iVar15) = uVar2 | uVar1 | uVar12 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar9 + iVar15) = uVar3 | uVar2 | uVar1 | uVar12 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar9 + iVar15) = uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar9 + iVar15) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xff8010ff;
  *(uint *)(iVar9 + iVar15) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xff0010ff;
  uVar11 = *(uint *)(iVar14 + 4);
  uVar10 = param_5 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  *(uint *)(iVar14 + 4) = uVar1 | uVar10 | uVar11 & 0xffffe000;
  uVar2 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar14 + 4) = uVar2 | uVar1 | uVar10 | uVar11 & 0xffff0000;
  uVar3 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar14 + 4) = uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xfff80000;
  uVar4 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar14 + 4) = uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xffc00000;
  uVar5 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar14 + 4) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xfe000000;
  uVar12 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar14 + 4) =
       uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xfc000000;
  uVar6 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar14 + 4) =
       uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xf8000000;
  uVar7 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar14 + 4) =
       uVar7 | uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xf0000000
  ;
  uVar1 = (param_8[3] & 1) << 0x1c |
          uVar7 | uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10;
  *(uint *)(iVar14 + 4) = uVar1;
  *(uint *)(iVar14 + 8) = uVar1;
  *(uint *)(iVar14 + 0xc) = uVar1;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00085bf0 @ 0x85bf0 (424 bytes) */
int FUN_00085bf0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  size_t sVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  void *pvVar13;
  int iVar14;
  int iVar15;
  
  iVar14 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar14 + 1U) {
    sVar8 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar13 = _calloc(sVar8 + 0x200,1);
    if (sVar8 != 0) {
      _memcpy(pvVar13,*(void **)(param_1 + 0x3c8),sVar8);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar13;
    iVar14 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar15 = *(int *)(param_1 + 0x3c8);
  iVar9 = iVar14 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar14 + 1;
  iVar14 = iVar9 + iVar15;
  *(int *)(param_1 + 0x3dc) = iVar14;
  *(undefined4 *)(iVar9 + iVar15) = 0;
  *(undefined1 *)(iVar14 + 3) = 0x47;
  uVar12 = *(uint *)(iVar9 + iVar15);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar9 + iVar15) = uVar2 | uVar1 | uVar12 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar9 + iVar15) = uVar3 | uVar2 | uVar1 | uVar12 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar9 + iVar15) = uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar9 + iVar15) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xff8010ff;
  *(uint *)(iVar9 + iVar15) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xff0010ff;
  uVar11 = *(uint *)(iVar14 + 4);
  uVar10 = param_5 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  *(uint *)(iVar14 + 4) = uVar1 | uVar10 | uVar11 & 0xffffe000;
  uVar2 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar14 + 4) = uVar2 | uVar1 | uVar10 | uVar11 & 0xffff0000;
  uVar3 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar14 + 4) = uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xfff80000;
  uVar4 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar14 + 4) = uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xffc00000;
  uVar5 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar14 + 4) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xfe000000;
  uVar12 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar14 + 4) =
       uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xfc000000;
  uVar6 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar14 + 4) =
       uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xf8000000;
  uVar7 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar14 + 4) =
       uVar7 | uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xf0000000
  ;
  uVar1 = (param_8[3] & 1) << 0x1c |
          uVar7 | uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10;
  *(uint *)(iVar14 + 4) = uVar1;
  *(uint *)(iVar14 + 8) = uVar1;
  *(uint *)(iVar14 + 0xc) = uVar1;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00085da0 @ 0x85da0 (424 bytes) */
int FUN_00085da0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  size_t sVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  void *pvVar13;
  int iVar14;
  int iVar15;
  
  iVar14 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar14 + 1U) {
    sVar8 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar13 = _calloc(sVar8 + 0x200,1);
    if (sVar8 != 0) {
      _memcpy(pvVar13,*(void **)(param_1 + 0x3c8),sVar8);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar13;
    iVar14 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar15 = *(int *)(param_1 + 0x3c8);
  iVar9 = iVar14 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar14 + 1;
  iVar14 = iVar9 + iVar15;
  *(int *)(param_1 + 0x3dc) = iVar14;
  *(undefined4 *)(iVar9 + iVar15) = 0;
  *(undefined1 *)(iVar14 + 3) = 0x49;
  uVar12 = *(uint *)(iVar9 + iVar15);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar9 + iVar15) = uVar2 | uVar1 | uVar12 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar9 + iVar15) = uVar3 | uVar2 | uVar1 | uVar12 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar9 + iVar15) = uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar9 + iVar15) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xff8010ff;
  *(uint *)(iVar9 + iVar15) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xff0010ff;
  uVar11 = *(uint *)(iVar14 + 4);
  uVar10 = param_5 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  *(uint *)(iVar14 + 4) = uVar1 | uVar10 | uVar11 & 0xffffe000;
  uVar2 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar14 + 4) = uVar2 | uVar1 | uVar10 | uVar11 & 0xffff0000;
  uVar3 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar14 + 4) = uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xfff80000;
  uVar4 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar14 + 4) = uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xffc00000;
  uVar5 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar14 + 4) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xfe000000;
  uVar12 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar14 + 4) =
       uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xfc000000;
  uVar6 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar14 + 4) =
       uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xf8000000;
  uVar7 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar14 + 4) =
       uVar7 | uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xf0000000
  ;
  uVar1 = (param_8[3] & 1) << 0x1c |
          uVar7 | uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10;
  *(uint *)(iVar14 + 4) = uVar1;
  *(uint *)(iVar14 + 8) = uVar1;
  *(uint *)(iVar14 + 0xc) = uVar1;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00085f50 @ 0x85f50 (424 bytes) */
int FUN_00085f50(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  size_t sVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  void *pvVar13;
  int iVar14;
  int iVar15;
  
  iVar14 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar14 + 1U) {
    sVar8 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar13 = _calloc(sVar8 + 0x200,1);
    if (sVar8 != 0) {
      _memcpy(pvVar13,*(void **)(param_1 + 0x3c8),sVar8);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar13;
    iVar14 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar15 = *(int *)(param_1 + 0x3c8);
  iVar9 = iVar14 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar14 + 1;
  iVar14 = iVar9 + iVar15;
  *(int *)(param_1 + 0x3dc) = iVar14;
  *(undefined4 *)(iVar9 + iVar15) = 0;
  *(undefined1 *)(iVar14 + 3) = 0x4b;
  uVar12 = *(uint *)(iVar9 + iVar15);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar9 + iVar15) = uVar2 | uVar1 | uVar12 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar9 + iVar15) = uVar3 | uVar2 | uVar1 | uVar12 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar9 + iVar15) = uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar9 + iVar15) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xff8010ff;
  *(uint *)(iVar9 + iVar15) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xff0010ff;
  uVar11 = *(uint *)(iVar14 + 4);
  uVar10 = param_5 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  *(uint *)(iVar14 + 4) = uVar1 | uVar10 | uVar11 & 0xffffe000;
  uVar2 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar14 + 4) = uVar2 | uVar1 | uVar10 | uVar11 & 0xffff0000;
  uVar3 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar14 + 4) = uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xfff80000;
  uVar4 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar14 + 4) = uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xffc00000;
  uVar5 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar14 + 4) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xfe000000;
  uVar12 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar14 + 4) =
       uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xfc000000;
  uVar6 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar14 + 4) =
       uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xf8000000;
  uVar7 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar14 + 4) =
       uVar7 | uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xf0000000
  ;
  uVar1 = (param_8[3] & 1) << 0x1c |
          uVar7 | uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10;
  *(uint *)(iVar14 + 4) = uVar1;
  *(uint *)(iVar14 + 8) = uVar1;
  *(uint *)(iVar14 + 0xc) = uVar1;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00086100 @ 0x86100 (424 bytes) */
int FUN_00086100(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  size_t sVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  void *pvVar13;
  int iVar14;
  int iVar15;
  
  iVar14 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar14 + 1U) {
    sVar8 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar13 = _calloc(sVar8 + 0x200,1);
    if (sVar8 != 0) {
      _memcpy(pvVar13,*(void **)(param_1 + 0x3c8),sVar8);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar13;
    iVar14 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar15 = *(int *)(param_1 + 0x3c8);
  iVar9 = iVar14 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar14 + 1;
  iVar14 = iVar9 + iVar15;
  *(int *)(param_1 + 0x3dc) = iVar14;
  *(undefined4 *)(iVar9 + iVar15) = 0;
  *(undefined1 *)(iVar14 + 3) = 0x43;
  uVar12 = *(uint *)(iVar9 + iVar15);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar9 + iVar15) = uVar2 | uVar1 | uVar12 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar9 + iVar15) = uVar3 | uVar2 | uVar1 | uVar12 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar9 + iVar15) = uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar9 + iVar15) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xff8010ff;
  *(uint *)(iVar9 + iVar15) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar12 & 0xff0010ff;
  uVar11 = *(uint *)(iVar14 + 4);
  uVar10 = param_5 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  *(uint *)(iVar14 + 4) = uVar1 | uVar10 | uVar11 & 0xffffe000;
  uVar2 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar14 + 4) = uVar2 | uVar1 | uVar10 | uVar11 & 0xffff0000;
  uVar3 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar14 + 4) = uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xfff80000;
  uVar4 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar14 + 4) = uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xffc00000;
  uVar5 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar14 + 4) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xfe000000;
  uVar12 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar14 + 4) =
       uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xfc000000;
  uVar6 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar14 + 4) =
       uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xf8000000;
  uVar7 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar14 + 4) =
       uVar7 | uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar11 & 0xf0000000
  ;
  uVar1 = (param_8[3] & 1) << 0x1c |
          uVar7 | uVar6 | uVar12 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10;
  *(uint *)(iVar14 + 4) = uVar1;
  *(uint *)(iVar14 + 8) = uVar1;
  *(uint *)(iVar14 + 0xc) = uVar1;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_000862b0 @ 0x862b0 (548 bytes) */
int FUN_000862b0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  void *pvVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint *in_stack_00000040;
  uint *in_stack_00000044;
  
  iVar16 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar16 + 1U) {
    sVar9 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar15 = _calloc(sVar9 + 0x200,1);
    if (sVar9 != 0) {
      _memcpy(pvVar15,*(void **)(param_1 + 0x3c8),sVar9);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar15;
    iVar16 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar17 = *(int *)(param_1 + 0x3c8);
  iVar10 = iVar16 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar16 + 1;
  iVar16 = iVar10 + iVar17;
  *(int *)(param_1 + 0x3dc) = iVar16;
  *(undefined4 *)(iVar10 + iVar17) = 0;
  *(undefined1 *)(iVar16 + 3) = 0x45;
  uVar14 = *(uint *)(iVar10 + iVar17);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar10 + iVar17) = uVar2 | uVar1 | uVar14 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar10 + iVar17) = uVar3 | uVar2 | uVar1 | uVar14 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar10 + iVar17) = uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar10 + iVar17) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff8010ff;
  *(uint *)(iVar10 + iVar17) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff0010ff;
  uVar13 = *(uint *)(iVar16 + 4);
  uVar18 = *(uint *)(iVar16 + 8);
  uVar11 = param_5 & 0xf;
  uVar12 = in_stack_00000038 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  uVar2 = (in_stack_0000003c & 0xff) << 5;
  *(uint *)(iVar16 + 4) = uVar1 | uVar11 | uVar13 & 0xffffe000;
  uVar3 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar16 + 4) = uVar3 | uVar1 | uVar11 | uVar13 & 0xffff0000;
  uVar4 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar16 + 4) = uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfff80000;
  uVar5 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar16 + 4) = uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xffc00000;
  uVar14 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar16 + 4) = uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfe000000;
  uVar6 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar16 + 4) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfc000000;
  uVar7 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 4) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf8000000;
  uVar8 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 4) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf0000000
  ;
  uVar13 = param_8[3];
  *(uint *)(iVar16 + 8) = uVar2 | uVar12 | uVar18 & 0xffffe000;
  *(uint *)(iVar16 + 4) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11;
  uVar1 = (*in_stack_00000040 & 7) << 0xd;
  *(uint *)(iVar16 + 8) = uVar1 | uVar2 | uVar12 | uVar18 & 0xffff0000;
  uVar3 = (in_stack_00000040[1] & 7) << 0x10;
  *(uint *)(iVar16 + 8) = uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfff80000;
  uVar4 = (in_stack_00000040[2] & 7) << 0x13;
  *(uint *)(iVar16 + 8) = uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xffc00000;
  uVar5 = (in_stack_00000040[3] & 7) << 0x16;
  *(uint *)(iVar16 + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfe000000;
  uVar14 = (*in_stack_00000044 & 1) << 0x19;
  *(uint *)(iVar16 + 8) =
       uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfc000000;
  uVar6 = (in_stack_00000044[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 8) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf8000000;
  uVar7 = (in_stack_00000044[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 8) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf0000000
  ;
  uVar1 = (in_stack_00000044[3] & 1) << 0x1c |
          uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12;
  *(uint *)(iVar16 + 0xc) = uVar1;
  *(uint *)(iVar16 + 8) = uVar1;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_000864e0 @ 0x864e0 (548 bytes) */
int FUN_000864e0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  void *pvVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint *in_stack_00000040;
  uint *in_stack_00000044;
  
  iVar16 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar16 + 1U) {
    sVar9 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar15 = _calloc(sVar9 + 0x200,1);
    if (sVar9 != 0) {
      _memcpy(pvVar15,*(void **)(param_1 + 0x3c8),sVar9);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar15;
    iVar16 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar17 = *(int *)(param_1 + 0x3c8);
  iVar10 = iVar16 * 0x10;
  *(int *)(param_1 + 0x3cc) = iVar16 + 1;
  iVar16 = iVar10 + iVar17;
  *(int *)(param_1 + 0x3dc) = iVar16;
  *(undefined4 *)(iVar10 + iVar17) = 0;
  *(undefined1 *)(iVar16 + 3) = 0x4f;
  uVar14 = *(uint *)(iVar10 + iVar17);
  uVar1 = (param_2 & 0xf) << 8;
  uVar2 = (param_3 & 0x7f) << 0xd;
  *(uint *)(iVar10 + iVar17) = uVar2 | uVar1 | uVar14 & 0xfff010ff;
  uVar3 = (*param_4 & 1) << 0x14;
  *(uint *)(iVar10 + iVar17) = uVar3 | uVar2 | uVar1 | uVar14 & 0xffe010ff;
  uVar4 = (param_4[1] & 1) << 0x15;
  *(uint *)(iVar10 + iVar17) = uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xffc010ff;
  uVar5 = (param_4[2] & 1) << 0x16;
  *(uint *)(iVar10 + iVar17) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff8010ff;
  *(uint *)(iVar10 + iVar17) =
       (param_4[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar14 & 0xff0010ff;
  uVar13 = *(uint *)(iVar16 + 4);
  uVar18 = *(uint *)(iVar16 + 8);
  uVar11 = param_5 & 0xf;
  uVar12 = in_stack_00000038 & 0xf;
  uVar1 = (param_6 & 0xff) << 5;
  uVar2 = (in_stack_0000003c & 0xff) << 5;
  *(uint *)(iVar16 + 4) = uVar1 | uVar11 | uVar13 & 0xffffe000;
  uVar3 = (*param_7 & 7) << 0xd;
  *(uint *)(iVar16 + 4) = uVar3 | uVar1 | uVar11 | uVar13 & 0xffff0000;
  uVar4 = (param_7[1] & 7) << 0x10;
  *(uint *)(iVar16 + 4) = uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfff80000;
  uVar5 = (param_7[2] & 7) << 0x13;
  *(uint *)(iVar16 + 4) = uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xffc00000;
  uVar14 = (param_7[3] & 7) << 0x16;
  *(uint *)(iVar16 + 4) = uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfe000000;
  uVar6 = (*param_8 & 1) << 0x19;
  *(uint *)(iVar16 + 4) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xfc000000;
  uVar7 = (param_8[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 4) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf8000000;
  uVar8 = (param_8[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 4) =
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11 | uVar13 & 0xf0000000
  ;
  uVar13 = param_8[3];
  *(uint *)(iVar16 + 8) = uVar2 | uVar12 | uVar18 & 0xffffe000;
  *(uint *)(iVar16 + 4) =
       (uVar13 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar11;
  uVar1 = (*in_stack_00000040 & 7) << 0xd;
  *(uint *)(iVar16 + 8) = uVar1 | uVar2 | uVar12 | uVar18 & 0xffff0000;
  uVar3 = (in_stack_00000040[1] & 7) << 0x10;
  *(uint *)(iVar16 + 8) = uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfff80000;
  uVar4 = (in_stack_00000040[2] & 7) << 0x13;
  *(uint *)(iVar16 + 8) = uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xffc00000;
  uVar5 = (in_stack_00000040[3] & 7) << 0x16;
  *(uint *)(iVar16 + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfe000000;
  uVar14 = (*in_stack_00000044 & 1) << 0x19;
  *(uint *)(iVar16 + 8) =
       uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xfc000000;
  uVar6 = (in_stack_00000044[1] & 1) << 0x1a;
  *(uint *)(iVar16 + 8) =
       uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf8000000;
  uVar7 = (in_stack_00000044[2] & 1) << 0x1b;
  *(uint *)(iVar16 + 8) =
       uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12 | uVar18 & 0xf0000000
  ;
  uVar1 = (in_stack_00000044[3] & 1) << 0x1c |
          uVar7 | uVar6 | uVar14 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | uVar12;
  *(uint *)(iVar16 + 0xc) = uVar1;
  *(uint *)(iVar16 + 8) = uVar1;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00086710 @ 0x86710 (152 bytes) */
int FUN_00086710(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,7);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar1;
  *puVar1 = 0x880;
  uVar2 = *(undefined4 *)(param_1 + 0x244c);
  puVar1[2] = 0x38882;
  puVar1[1] = uVar2;
  puVar1[3] = *(undefined4 *)(param_1 + 400);
  puVar1[4] = *(undefined4 *)(param_1 + 0x194);
  puVar1[5] = *(undefined4 *)(param_1 + 0xf0);
  puVar1[6] = *(undefined4 *)(param_1 + 0x198);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x1c;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}

/* FUN_000867b0 @ 0x867b0 (140 bytes) */
int FUN_000867b0(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = *(uint *)(param_1 + 0x1930);
  uVar4 = 0;
  iVar5 = 6;
  uVar2 = *(uint *)(((unsigned char *)0x00003e28) + *(int *)(*(int *)(param_1 + 4) + 0x10));
  do {
    if (((int)(uint)*(ushort *)(param_1 + 0x36) >> (uVar4 & 0x3f) & 1U) != 0) {
      uVar1 = 1 << (uVar4 & 0x3f);
      if ((uVar2 & uVar1) == 0) {
        *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) & ~uVar1;
      }
      else {
        uVar3 = uVar3 | 0x1000000;
        *(uint *)(param_1 + 0x1930) = uVar3;
        *(uint *)(param_1 + 0x1b74) = uVar1 | *(uint *)(param_1 + 0x1b74);
      }
    }
    uVar4 = uVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(uint *)(param_1 + 0x1930) = uVar3 | 0x400000;
  *(undefined2 *)(param_1 + 0x36) = 0;
  return;
}

/* FUN_00086840 @ 0x86840 (228 bytes) */
int FUN_00086840(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  puVar7 = (undefined4 *)(param_1 + 0x3d8);
  uVar6 = 0;
  uVar5 = *(uint *)(((unsigned char *)0x00003e28) + *(int *)(*(int *)(param_1 + 4) + 0x10));
  do {
    if ((uVar5 & 1 << (uVar6 & 0x3f)) != 0) {
      puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,7);
      *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4;
      *puVar4 = 0x880;
      iVar2 = *(int *)(param_1 + 0x1be0);
      puVar4[2] = 0x38882;
      puVar4[1] = uVar6 + iVar2;
      puVar4[3] = *puVar7;
      puVar4[4] = puVar7[1];
      puVar4[5] = puVar7[2];
      puVar4[6] = puVar7[3];
      pcVar3 = *(code **)(param_1 + 0x275c);
      *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x1c;
      (*pcVar3)(param_1);
    }
    bVar1 = uVar6 != 5;
    puVar7 = puVar7 + 4;
    uVar6 = uVar6 + 1;
  } while (bVar1);
  return;
}

/* FUN_00086930 @ 0x86930 (204 bytes) */
int FUN_00086930(int param_1,double fparam_1,double fparam_2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,*(undefined4 *)(param_1 + 0x284c)) - DOUBLE_001aa250)
          * FLOAT_001aa170 + (float)(fparam_1 + fparam_2);
  if (fVar1 == FLOAT_001aa0d4) {
    return 0;
  }
  if (fVar1 != FLOAT_001aa174) {
    fVar2 = FLOAT_001aa17c;
    if ((FLOAT_001aa178 <= fVar1) && (fVar2 = FLOAT_001aa184, fVar1 <= FLOAT_001aa180)) {
      fVar2 = fVar1 * FLOAT_001aa0f8;
    }
    return (int)fVar2;
  }
  return -0x10;
}

/* FUN_00086a10 @ 0x86a10 (96 bytes) */
int FUN_00086a10(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  float *param_3;
{
  undefined2 uVar1;
  
  if (param_3 == (float *)0x0) {
    uVar1 = ((int (*)())FUN_00086930)(param_1,(double)*(float *)(param_2 + 0x20),(double)FLOAT_001aa0d4);
    *(undefined2 *)(param_2 + 0x1e) = uVar1;
  }
  else {
    uVar1 = ((int (*)())FUN_00086930)(param_1,(double)*(float *)(param_2 + 0x20),(double)*param_3);
    *(undefined2 *)(param_2 + 0x1e) = uVar1;
  }
  return;
}

/* FUN_00086a80 @ 0x86a80 (284 bytes) */
int FUN_00086a80(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = *(undefined4 *)(param_1 + 0x1b74);
  param_2[1] = *(undefined4 *)(param_1 + 0x1b84);
  param_2[2] = *(undefined4 *)(param_1 + 0x1b30);
  param_2[3] = *(undefined4 *)(param_1 + 0x1aa0);
  param_2[4] = *(undefined4 *)(param_1 + 0x1ab0);
  param_2[5] = *(undefined4 *)(param_1 + 0x1aa4);
  param_2[6] = *(undefined4 *)(param_1 + 0x1aa8);
  param_2[8] = *(undefined4 *)(param_1 + 0x1ab8);
  param_2[9] = *(undefined4 *)(param_1 + 0x1aec);
  param_2[10] = *(undefined4 *)(param_1 + 0x1a4c);
  param_2[0xb] = *(undefined4 *)(param_1 + 0x1a50);
  param_2[0xc] = *(undefined4 *)(param_1 + 0x1a80);
  param_2[0xd] = *(undefined4 *)(param_1 + 0x1af8);
  param_2[0xe] = *(undefined4 *)(param_1 + 0x1b9c);
  param_2[0xf] = *(undefined4 *)(param_1 + 0x1ba0);
  param_2[0x10] = *(undefined4 *)(param_1 + 0x248c);
  param_2[0x11] = **(undefined4 **)(param_1 + 0x2440);
  param_2[0x12] = **(undefined4 **)(param_1 + 0x2444);
  param_2[0x15] = *(undefined4 *)(param_1 + 0x1ae0);
  param_2[0x13] = *(undefined4 *)(param_1 + 7000);
  param_2[0x14] = *(undefined4 *)(param_1 + 0x1b10);
  param_2[0x16] = *(undefined4 *)(param_1 + 0x1b3c);
  param_2[0x17] = *(undefined4 *)(FUN_00001af4 + param_1);
  param_2[0x18] = *(undefined4 *)(param_1 + 0x1b50);
  param_2[0x19] = *(undefined4 *)(param_1 + 0x1f2c);
  param_2[0x1a] = *(undefined4 *)(param_1 + 0x1a60);
  param_2[0x1b] = *(undefined4 *)(param_1 + 0x1a68);
  param_2[0x1c] = *(undefined4 *)(param_1 + 0x1a6c);
  param_2[0x1d] = *(undefined4 *)(param_1 + 0x1b60);
  param_2[0x1e] = *(undefined4 *)(param_1 + 0x23e0);
  param_2[0x1f] = *(undefined4 *)(param_1 + 0x1c8c);
  param_2[0x20] = *(undefined4 *)(param_1 + 0x1c94);
  param_2[0x21] = *(undefined4 *)(param_1 + 0x1bc0);
  param_2[0x22] = *(undefined4 *)(param_1 + 0x1bb0);
  return;
}

/* FUN_00086ba0 @ 0x86ba0 (1840 bytes) */
int FUN_00086ba0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
  undefined4 param_5;
{
  bool bVar1;
  float fVar2;
  double dVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  code *pcVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 uVar11;
  
  bVar1 = param_3 == 0;
  ((int (*)())FUN_00086a80)(param_1,param_5);
  *(undefined4 *)(param_1 + 0x1c8c) = *(undefined4 *)(param_1 + 0x2814);
  *(undefined4 *)(param_1 + 0x1c94) = *(undefined4 *)(param_1 + 0x2818);
  *(undefined4 *)(param_1 + 0x23e0) = 0;
  *(uint *)(param_1 + 0x1aa0) = param_4 & 1 | (param_3 & 1) << 1 | (param_3 & 1) << 2;
  *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) & 0xffff3fff | 0x1c000;
  *(uint *)(param_1 + 0x1b84) = *(uint *)(param_1 + 0x1b84) & 0xffffffc5 | 5;
  if (bVar1) {
    uVar4 = *(uint *)(param_1 + 0x1aa4) & 0xfffffff8;
    *(uint *)(param_1 + 0x1aa4) = uVar4;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x1aa4) & 0xfffffff8 | 7;
    *(uint *)(param_1 + 0x1aa4) = uVar4;
  }
  if (param_4 == 0) {
    *(uint *)(param_1 + 0x1aa4) = uVar4 & 0xffffffc7;
  }
  else {
    iVar10 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    *(uint *)(param_1 + 0x1aa4) = uVar4 & 0xff1c71c7 | 0x438438;
    *(char *)(param_1 + 0x1aab) = (char)*(undefined4 *)(((unsigned char *)0x00002db4) + iVar10);
    *(char *)(param_1 + 0x1aa9) = (char)*(undefined4 *)(((unsigned char *)0x00002e38) + iVar10);
  }
  *(undefined4 *)(param_1 + 0x1a80) = 0x20200000;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xfffffff0 | 3;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffff0f;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffe0ff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffdfff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffbfff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffff7fff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xfff0ffff | 0x30000;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xff0fffff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xe0ffffff | 0x1000000;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) | 0x20000000;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xbfffffff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0x7fffffff;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffff8;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffffffc7 | 8;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffe3f | 0x80;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffff1ff | 0x600;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffff0fff | 0xf000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfff8ffff;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffc7ffff | 0x80000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfe3fffff | 0x800000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xf1ffffff | 0x6000000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffff | 0xf0000000;
  dVar3 = DOUBLE_001aa1e0;
  fVar2 = FLOAT_001aa0d4;
  if (*(int *)(param_1 + 8) == 0xc) {
    uVar7 = *(uint *)(param_1 + 0x1b10);
    *(uint *)(param_1 + 7000) = *(uint *)(param_1 + 7000) & 0xfc000000;
    uVar4 = (int)((float)((double)CONCAT44(0x43300000,
                                           *(uint *)(*(int *)(param_1 + 4) + 0x15c) ^ 0x80000000) -
                         dVar3) * *(float *)(param_1 + 0x2814) + fVar2) & 0x1fff;
    *(uint *)(param_1 + 0x1b10) = uVar4 | uVar7 & 0xffffe000;
    *(uint *)(param_1 + 0x1b10) =
         ((int)((float)((double)CONCAT44(0x43300000,
                                         *(uint *)(*(int *)(param_1 + 4) + 0x160) ^ 0x80000000) -
                       dVar3) * *(float *)(param_1 + 0x2818) + fVar2) & 0x1fffU) << 0xd |
         uVar4 | uVar7 & 0xfc000000;
  }
  else {
    uVar7 = *(uint *)(param_1 + 0x1b10);
    *(uint *)(param_1 + 7000) = *(uint *)(param_1 + 7000) & 0xfc000000;
    uVar4 = (int)((float)((double)CONCAT44(0x43300000,
                                           *(uint *)(*(int *)(param_1 + 4) + 0x15c) ^ 0x80000000) -
                         dVar3) * *(float *)(param_1 + 0x2814) + fVar2) & 0x1fff;
    *(uint *)(param_1 + 0x1b10) = uVar4 | uVar7 & 0xffffe000;
    *(uint *)(param_1 + 0x1b10) =
         ((int)((float)((double)CONCAT44(0x43300000,
                                         *(uint *)(*(int *)(param_1 + 4) + 0x160) ^ 0x80000000) -
                       dVar3) * *(float *)(param_1 + 0x2818) + fVar2) & 0x1fffU) << 0xd |
         uVar4 | uVar7 & 0xfc000000;
  }
  *(undefined4 *)(param_1 + 0x1b9c) = 3;
  *(undefined4 *)(param_1 + 0x1b30) = 0;
  *(undefined4 *)(param_1 + 0x248c) = 8;
  *(undefined4 *)(param_1 + 0x1b60) = 0xffffff;
  *(uint *)(param_1 + 0x1b50) = (uint)*(ushort *)(param_1 + 0x1b52);
  *(undefined4 *)(param_1 + 0x1aec) = 0;
  *(undefined4 *)(param_1 + 0x1a4c) = 0;
  *(undefined4 *)(param_1 + 0x1a50) = 0;
  *(undefined4 *)(param_1 + 0x1af8) = 0;
  *(undefined4 *)(param_1 + 0x1ba0) = 0;
  *(undefined4 *)(param_1 + 0x1bb0) = 0;
  *(undefined4 *)(param_1 + 0x1bc0) = 0;
  if (param_2 == 0) {
    *(undefined4 *)(FUN_00001af4 + param_1) = 0;
  }
  uVar11 = *(undefined4 *)(param_1 + 0x1930);
  *(undefined4 *)(param_1 + 0x1b3c) = 0;
  FUN_0004b480(param_1,*(uint *)(param_1 + 0x18a4) >> 6 & 0xffff);
  pcVar8 = *(code **)(((unsigned char *)0x00001330) + param_1);
  *(uint *)(param_1 + 0x1f2c) = *(uint *)(param_1 + 0x1f2c) & 0xfffff800 | 0x80;
  (*pcVar8)(param_1,0xc0100000);
  *(undefined4 *)(param_1 + 0x1930) = uVar11;
  if (!bVar1) {
    *(uint *)(param_1 + 0x1ae0) = *(uint *)(param_1 + 0x1ae0) & 0xfffffffe;
    *(uint *)(param_1 + 0x1ab0) = *(uint *)(param_1 + 0x1ab0) & 0xfffffffe;
  }
  puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x3d);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar6;
  puVar9 = puVar6 + 0x34;
  *puVar6 = 0x887;
  uVar11 = *(undefined4 *)(param_1 + 0x1b74);
  puVar6[2] = 0x82c;
  puVar6[1] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x1b84);
  puVar6[4] = ((unsigned char *)0x000010ae);
  puVar6[3] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x1b30);
  puVar6[6] = ((unsigned char *)0x000013c0);
  puVar6[5] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x1aa0);
  puVar6[8] = ((unsigned char *)0x000013c1);
  puVar6[7] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x1aa4);
  puVar6[10] = ((unsigned char *)0x000013c2);
  puVar6[9] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x1aa8);
  puVar6[0xc] = ((unsigned char *)0x000012f0);
  puVar6[0xb] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x1aec);
  puVar6[0xe] = ((unsigned char *)0x000012f5);
  puVar6[0xd] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x1a4c);
  puVar6[0x10] = ((unsigned char *)0x000012f6);
  puVar6[0xf] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x1a50);
  puVar6[0x12] = ((unsigned char *)0x00001381);
  puVar6[0x11] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x1a80);
  puVar6[0x14] = ((unsigned char *)0x00001386);
  puVar6[0x13] = uVar11;
  puVar6[0x15] = *(undefined4 *)(param_1 + 0x1af8);
  puVar6[0x16] = 0x824;
  uVar11 = *(undefined4 *)(param_1 + 0x1b9c);
  puVar6[0x18] = 0x825;
  puVar6[0x17] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar6[0x1a] = 0x82d;
  puVar6[0x19] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x248c);
  puVar6[0x1c] = 0x854;
  puVar6[0x1b] = uVar11;
  uVar11 = **(undefined4 **)(param_1 + 0x2440);
  puVar6[0x1e] = 0x878;
  puVar6[0x1d] = uVar11;
  uVar11 = **(undefined4 **)(param_1 + 0x2444);
  puVar6[0x20] = ((unsigned char *)0x000010f8);
  puVar6[0x1f] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 7000);
  puVar6[0x22] = ((unsigned char *)0x000010f9);
  puVar6[0x21] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x1b10);
  puVar6[0x24] = ((unsigned char *)0x000010a2);
  puVar6[0x23] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x1b3c);
  puVar6[0x26] = ((unsigned char *)0x00001383);
  puVar6[0x25] = uVar11;
  uVar11 = *(undefined4 *)(FUN_00001af4 + param_1);
  puVar6[0x28] = ((unsigned char *)0x00001002);
  puVar6[0x27] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x1b50);
  puVar6[0x2a] = ((unsigned char *)0x000010c0);
  puVar6[0x29] = uVar11;
  puVar6[0x2b] = *(undefined4 *)(param_1 + 0x1f2c);
  puVar6[0x2c] = 0x825;
  uVar11 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar6[0x2e] = 0x766;
  puVar6[0x2d] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x1c8c);
  puVar6[0x30] = 0x768;
  puVar6[0x2f] = uVar11;
  uVar11 = *(undefined4 *)(param_1 + 0x1c94);
  puVar6[0x32] = ((unsigned char *)0x000010fa);
  puVar6[0x31] = uVar11;
  puVar6[0x33] = *(undefined4 *)(param_1 + 0x1b60);
  if (!bVar1) {
    iVar10 = *(int *)(param_1 + 4);
    puVar5 = *(uint **)(iVar10 + 0x1d8);
    *puVar5 = (int)puVar9 - (int)puVar5 >> 2 | *puVar5;
    *(undefined4 **)(iVar10 + 0x1d8) = puVar9;
    puVar9 = puVar6 + 0x39;
    puVar6[0x34] = 0x2f000000;
    puVar6[0x35] = (*(unsigned char *)0x000010e9);
    uVar11 = *(undefined4 *)(param_1 + 0x1ae0);
    puVar6[0x37] = ((unsigned char *)0x000013c7);
    puVar6[0x36] = uVar11;
    puVar6[0x38] = *(undefined4 *)(param_1 + 0x1ab0);
  }
  *puVar9 = ((unsigned char *)0x00001048);
  uVar11 = *(undefined4 *)(param_1 + 0x1bc0);
  puVar9[2] = ((unsigned char *)0x00001047);
  puVar9[1] = uVar11;
  puVar9[3] = *(undefined4 *)(param_1 + 0x1bb0);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar9 + 4;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar9 + 4);
  return;
}

/* FUN_000872e0 @ 0x872e0 (1296 bytes) */
int FUN_000872e0(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  char cVar1;
  undefined *puVar2;
  code *pcVar3;
  undefined4 *puVar4;
  uint *puVar5;
  undefined4 extraout_r4;
  undefined4 *puVar6;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  double fparam_1;
  
  *(undefined4 *)(param_1 + 0x1b74) = *param_2;
  *(undefined4 *)(param_1 + 0x1b84) = param_2[1];
  *(undefined4 *)(param_1 + 0x1b30) = param_2[2];
  *(undefined4 *)(param_1 + 0x1aa0) = param_2[3];
  *(undefined4 *)(param_1 + 0x1ab0) = param_2[4];
  *(undefined4 *)(param_1 + 0x1aa4) = param_2[5];
  *(undefined4 *)(param_1 + 0x1aa8) = param_2[6];
  *(undefined4 *)(param_1 + 0x1ab8) = param_2[8];
  *(undefined4 *)(param_1 + 0x1aec) = param_2[9];
  *(undefined4 *)(param_1 + 0x1a4c) = param_2[10];
  *(undefined4 *)(param_1 + 0x1a50) = param_2[0xb];
  *(undefined4 *)(param_1 + 0x1a80) = param_2[0xc];
  *(undefined4 *)(param_1 + 0x1af8) = param_2[0xd];
  *(undefined4 *)(param_1 + 0x1b9c) = param_2[0xe];
  *(undefined4 *)(param_1 + 0x1ba0) = param_2[0xf];
  *(undefined4 *)(param_1 + 0x248c) = param_2[0x10];
  **(undefined4 **)(param_1 + 0x2440) = param_2[0x11];
  **(undefined4 **)(param_1 + 0x2444) = param_2[0x12];
  *(undefined4 *)(param_1 + 0x1ae0) = param_2[0x15];
  *(undefined4 *)(param_1 + 7000) = param_2[0x13];
  *(undefined4 *)(param_1 + 0x1b10) = param_2[0x14];
  *(undefined4 *)(param_1 + 0x1b3c) = param_2[0x16];
  *(undefined4 *)(FUN_00001af4 + param_1) = param_2[0x17];
  *(undefined4 *)(param_1 + 0x1b50) = param_2[0x18];
  *(undefined4 *)(param_1 + 0x1f2c) = param_2[0x19];
  *(undefined4 *)(param_1 + 0x1a60) = param_2[0x1a];
  *(undefined4 *)(param_1 + 0x1a68) = param_2[0x1b];
  *(undefined4 *)(param_1 + 0x1a6c) = param_2[0x1c];
  *(undefined4 *)(param_1 + 0x1b60) = param_2[0x1d];
  *(undefined4 *)(param_1 + 0x23e0) = param_2[0x1e];
  *(undefined4 *)(param_1 + 0x1c8c) = param_2[0x1f];
  *(undefined4 *)(param_1 + 0x1c94) = param_2[0x20];
  *(undefined4 *)(param_1 + 0x1bc0) = param_2[0x21];
  pcVar3 = *(code **)(((unsigned char *)0x00001334) + param_1);
  *(undefined4 *)(param_1 + 0x1bb0) = param_2[0x22];
  fparam_1 = (double)(*pcVar3)(param_1,0);
  if (((*(uint *)(param_1 + 0x44) & 0x20000) != 0) &&
     (puVar4 = *(undefined4 **)(param_1 + 0x1e70), puVar4 != (undefined4 *)0x0)) {
    if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
      cVar1 = ((unsigned char *)0x00001136)[param_1];
    }
    else {
      cVar1 = ((unsigned char *)0x000011d0)[param_1];
    }
    if (cVar1 == '\0') goto LAB_00087474;
  }
  puVar4 = *(undefined4 **)(param_1 + 0x1e5c);
LAB_00087474:
  *(undefined1 *)((int)puVar4 + 0x10eb) = 0;
  if (*(int *)(param_1 + 0x23e0) == 0) {
    *puVar4 = 0;
    puVar4[0x4c0] = 0;
  }
  else {
    puVar4[7] = 0;
    puVar4[0x54b] = 0;
  }
  ((void (*)())FUN_0004a8f0)(param_1,extraout_r4,in_r5,in_r6,fparam_1);
  (**(code **)(((unsigned char *)0x00001330) + param_1))(param_1,0xc0100000);
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) & 0x3fefffff;
  puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x55);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4;
  *puVar4 = 0x887;
  puVar2 = PTR_DAT_001e88c8;
  uVar7 = *(undefined4 *)(param_1 + 0x1b74);
  puVar4[2] = 0x82c;
  puVar4[1] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b84);
  puVar4[4] = ((unsigned char *)0x000010ae);
  puVar4[3] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b30);
  puVar4[6] = ((unsigned char *)0x000013c0);
  puVar4[5] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1aa0);
  puVar4[8] = ((unsigned char *)0x000013c1);
  puVar4[7] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1aa4);
  puVar4[10] = ((unsigned char *)0x000013c2);
  puVar4[9] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1aa8);
  puVar4[0xc] = ((unsigned char *)0x000012f0);
  puVar4[0xb] = uVar7;
  uVar8 = *(uint *)(param_1 + 0x1aec);
  puVar4[0xd] = uVar8;
  if ((*(uint *)(puVar2 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    puVar4[0xd] = uVar8 & 0xfffffffe;
  }
  puVar4[0xe] = ((unsigned char *)0x000012f5);
  uVar8 = *(uint *)(param_1 + 0x1a4c);
  puVar4[0xf] = uVar8;
  if ((*(uint *)(puVar2 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    puVar4[0xf] = uVar8 & 0xfffff7ff;
  }
  puVar4[0x10] = ((unsigned char *)0x000012f6);
  uVar7 = *(undefined4 *)(param_1 + 0x1a50);
  puVar4[0x12] = ((unsigned char *)0x00001381);
  puVar4[0x11] = uVar7;
  uVar8 = *(uint *)(param_1 + 0x1a80);
  puVar4[0x13] = uVar8;
  if ((*(uint *)(puVar2 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x4000) == 0) {
    puVar4[0x13] = uVar8 & 0xfffffffc;
  }
  puVar4[0x14] = ((unsigned char *)0x00001386);
  puVar6 = puVar4 + 0x34;
  uVar7 = *(undefined4 *)(param_1 + 0x1af8);
  puVar4[0x16] = 0x824;
  puVar4[0x15] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b9c);
  puVar4[0x18] = 0x825;
  puVar4[0x17] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar4[0x1a] = 0x82d;
  puVar4[0x19] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x248c);
  puVar4[0x1c] = 0x854;
  puVar4[0x1b] = uVar7;
  uVar7 = **(undefined4 **)(param_1 + 0x2440);
  puVar4[0x1e] = 0x878;
  puVar4[0x1d] = uVar7;
  uVar7 = **(undefined4 **)(param_1 + 0x2444);
  puVar4[0x20] = ((unsigned char *)0x000010a2);
  puVar4[0x1f] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b3c);
  puVar4[0x22] = ((unsigned char *)0x00001383);
  puVar4[0x21] = uVar7;
  uVar7 = *(undefined4 *)(FUN_00001af4 + param_1);
  puVar4[0x24] = ((unsigned char *)0x00001002);
  puVar4[0x23] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b50);
  puVar4[0x26] = ((unsigned char *)0x000010c0);
  puVar4[0x25] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1f2c);
  puVar4[0x28] = 0x825;
  puVar4[0x27] = uVar7;
  puVar4[0x29] = *(undefined4 *)(param_1 + 0x1ba0);
  puVar4[0x2a] = ((unsigned char *)0x00001008);
  uVar7 = *(undefined4 *)(param_1 + 0x1a60);
  puVar4[0x2c] = ((unsigned char *)0x00001004);
  puVar4[0x2b] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1a68);
  puVar4[0x2e] = ((unsigned char *)0x00001005);
  puVar4[0x2d] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1a6c);
  puVar4[0x30] = ((unsigned char *)0x000010fa);
  puVar4[0x2f] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b60);
  puVar4[0x32] = ((unsigned char *)0x000013c5);
  puVar4[0x31] = uVar7;
  puVar4[0x33] = *(undefined4 *)(param_1 + 0x1ab8);
  if ((*(uint *)(param_1 + 0x2454) & 0x8000000) != 0) {
    puVar4[0x34] = ((unsigned char *)0x000013c5);
    puVar6 = puVar4 + 0x36;
    puVar4[0x35] = *(undefined4 *)(param_1 + 0x1ab8);
  }
  puVar4 = (undefined4 *)FUN_0004dd10(param_1,puVar6);
  *puVar4 = 0x766;
  uVar7 = *(undefined4 *)(param_1 + 0x1c8c);
  puVar4[2] = 0x768;
  puVar4[1] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1c94);
  puVar4[4] = ((unsigned char *)0x000010fa);
  puVar4[3] = uVar7;
  puVar4[5] = *(undefined4 *)(param_1 + 0x1b60);
  iVar9 = *(int *)(param_1 + 4);
  puVar5 = *(uint **)(iVar9 + 0x1d8);
  *puVar5 = (int)(puVar4 + 6) - (int)puVar5 >> 2 | *puVar5;
  *(undefined4 **)(iVar9 + 0x1d8) = puVar4 + 6;
  puVar4[6] = 0x2f000000;
  puVar4[7] = (*(unsigned char *)0x000010e9);
  uVar7 = *(undefined4 *)(param_1 + 0x1ae0);
  puVar4[9] = ((unsigned char *)0x000013c7);
  puVar4[8] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1ab0);
  puVar4[0xb] = ((unsigned char *)0x00001048);
  puVar4[10] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1bc0);
  puVar4[0xd] = ((unsigned char *)0x00001047);
  puVar4[0xc] = uVar7;
  puVar4[0xe] = *(undefined4 *)(param_1 + 0x1bb0);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4 + 0xf;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar4 + 0xf);
  return;
}

/* FUN_00087800 @ 0x87800 (344 bytes) */
int FUN_00087800(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
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
  int iVar10;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  
  iVar6 = *(int *)(param_2 + 0x74);
  iVar9 = *(int *)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 + *(int *)(param_2 + 0x70));
  if (0 < *(int *)(iVar6 + 0x84)) {
    iVar7 = 0;
    iVar8 = 0;
    do {
      iVar10 = iVar8 + *(int *)(iVar6 + 0x80);
      if (*(int *)(iVar10 + 8) != 0x34) {
        FUN_0008ebb0(param_1,iVar10,&fStack_48,param_4);
        iVar2 = ((uint (*)())FUN_0004a7d0)((double)fStack_48);
        iVar3 = ((uint (*)())FUN_0004a7d0)((double)fStack_44);
        iVar4 = ((uint (*)())FUN_0004a7d0)((double)fStack_40);
        iVar5 = ((uint (*)())FUN_0004a7d0)((double)fStack_3c);
        iVar6 = *(int *)(iVar10 + 4) * 0x10;
        iVar1 = iVar6 + iVar9;
        if ((((iVar2 == *(int *)(iVar1 + 0x8c)) && (iVar3 == *(int *)(iVar1 + 0x90))) &&
            (iVar4 == *(int *)(iVar1 + 0x94))) && (iVar5 == *(int *)(iVar1 + 0x98))) {
          iVar6 = *(int *)(param_2 + 0x74);
        }
        else {
          *(int *)(iVar6 + iVar9 + 0x8c) = iVar2;
          *(int *)(*(int *)(iVar10 + 4) * 0x10 + iVar9 + 0x90) = iVar3;
          *(int *)(*(int *)(iVar10 + 4) * 0x10 + iVar9 + 0x94) = iVar4;
          *(int *)(*(int *)(iVar10 + 4) * 0x10 + iVar9 + 0x98) = iVar5;
          *(undefined4 *)(param_1 + 0x1e64) = 0;
          iVar6 = *(int *)(param_2 + 0x74);
        }
      }
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0x14;
    } while (iVar7 < *(int *)(iVar6 + 0x84));
  }
  return;
}

/* FUN_00087960 @ 0x87960 (120 bytes) */
int FUN_00087960(param_1)
  int param_1;
{
  *(undefined4 *)((*(unsigned char *)0x0000120c) + param_1) = 0x1ff;
  *(undefined4 *)(((unsigned char *)0x00001200) + param_1) = 0x40;
  *(undefined4 *)(((unsigned char *)0x000011e0) + param_1) = 0x40;
  *(undefined4 *)(((unsigned char *)0x00001204) + param_1) = 0x400;
  *(undefined4 *)(((unsigned char *)0x00001214) + param_1) = 0x200;
  *(undefined4 *)(((unsigned char *)0x000011f0) + param_1) = 10;
  *(undefined4 *)(((unsigned char *)0x000011d8) + param_1) = 0x400;
  *(undefined4 *)(((unsigned char *)0x000011e4) + param_1) = 0x40;
  *(undefined4 *)(((unsigned char *)0x000011e8) + param_1) = 0x40;
  *(undefined4 *)(((unsigned char *)0x000011ec) + param_1) = 10;
  *(undefined4 *)(((unsigned char *)0x000011fc) + param_1) = 0x40;
  *(undefined4 *)(((unsigned char *)0x00001210) + param_1) = 0x200;
  *(undefined4 *)(((unsigned char *)0x00001208) + param_1) = 0x200;
  *(undefined4 *)(((unsigned char *)0x000011f8) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x000011dc) + param_1) = 0x8000;
  *(undefined4 *)(((unsigned char *)0x00001218) + param_1) = 4;
  *(undefined4 *)(((unsigned char *)0x000011d4) + param_1) = 0x600;
  *(undefined4 *)(((unsigned char *)0x000011f4) + param_1) = 0;
  return;
}

/* FUN_000879e0 @ 0x879e0 (4 bytes) */
int FUN_000879e0()
{
  return;
}

/* FUN_000879f0 @ 0x879f0 (732 bytes) */
int FUN_000879f0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  undefined4 *param_5;
  int param_6;
  int param_7;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = 0;
  if (param_1 != 0) {
    iVar8 = *(int *)(param_1 + 0x276c);
  }
  _memset(param_5,0,0x80);
  iVar7 = 0;
  iVar9 = 8;
  uVar2 = 0;
  iVar3 = param_4;
  iVar5 = param_4;
  puVar6 = param_5;
  do {
    *puVar6 = 1;
    *(undefined1 *)((int)puVar6 + 0xb) = 0;
    *(undefined2 *)((int)puVar6 + 6) = 0;
    *(undefined1 *)((int)puVar6 + 0xe) = 0;
    *(undefined1 *)((int)puVar6 + 0xf) = 0;
    *(undefined4 *)(iVar3 + 200) = 0;
    *(undefined1 *)((int)puVar6 + 9) = 0;
    if (*(char *)(iVar7 + param_6) != '\0') {
      *(uint *)(iVar5 + 0x88) = *(uint *)(iVar5 + 0x88) & 0xfe001fff | 0xd10000;
      *(uint *)(iVar5 + 200) =
           (uVar2 + 3) * 0x40000 |
           (uVar2 + 2) * 0x1000 | (uVar2 + 1) * 0x40 | uVar2 | *(uint *)(iVar5 + 200) & 0xff000000;
      *(short *)(puVar6 + 1) = (short)iVar7 + 2;
      *(undefined1 *)((int)puVar6 + 9) = 1;
      *(char *)(puVar6 + 2) = (char)iVar7;
      *(undefined1 *)(puVar6 + 3) = 0;
    }
    puVar6 = puVar6 + 0x12;
    iVar7 = iVar7 + 1;
    iVar5 = iVar5 + 4;
    uVar2 = uVar2 + 4 & 0x3f;
    iVar3 = iVar3 + 4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if (*(char *)(param_3 + 0x118) != '\0') {
    *(undefined1 *)((int)param_5 + 0x24f) = 0;
    *(undefined1 *)((int)param_5 + 0x24b) = 0;
    uVar2 = iVar8 * 4;
    *(undefined1 *)((int)param_5 + 0x24a) = 0;
    *(undefined1 *)((int)param_5 + 0x24d) = 0;
    *(undefined1 *)((int)param_5 + 0x24e) = 0;
    *(undefined2 *)((int)param_5 + 0x246) = 0;
    *(undefined1 *)((int)param_5 + 0x249) = 1;
    param_5[0x90] = 1;
    iVar3 = 4;
    *(uint *)(uVar2 + param_4 + 0x88) = *(uint *)(uVar2 + param_4 + 0x88) & 0xfff81fff | 0x10000;
    if (*(int *)(param_4 + 0x210) != 2) {
      iVar3 = 2;
    }
    iVar5 = uVar2 + param_4;
    uVar4 = 0x3e;
    *(uint *)(iVar5 + 0x88) = iVar3 << 0x13 | *(uint *)(iVar5 + 0x88) & 0xfe07ffff | 0x1400000;
    *(uint *)(iVar5 + 200) =
         ((char)uVar2 + 1) * 0x40 & 0xfc0U | uVar2 & 0x3c | *(uint *)(iVar5 + 200) & 0xfffff000;
    if (*(int *)(param_4 + 0x210) != 2) {
      uVar4 = (int)(char)uVar2 + 2U & 0x3e;
    }
    *(uint *)(uVar2 + param_4 + 200) =
         uVar4 << 0xc | *(uint *)(uVar2 + param_4 + 200) & 0xff000fff | 0xfc0000;
    *(char *)(param_5 + 0x92) = (char)iVar8;
    uVar1 = *(undefined4 *)(param_3 + 0x108);
    *(undefined1 *)(param_5 + 0x93) = 0;
    *(short *)(param_5 + 0x91) = (short)uVar1;
  }
  *(undefined1 *)((int)param_5 + 10) = 0;
  *(undefined2 *)((int)param_5 + 6) = 0;
  *(undefined1 *)((int)param_5 + 0xb) = 1;
  *(undefined1 *)((int)param_5 + 0xd) = 0;
  *(uint *)(param_4 + 0x88) = *(uint *)(param_4 + 0x88) & 0xffffe03f;
  *(uint *)(param_4 + 200) = *(uint *)(param_4 + 200) & 0x80ffffff;
  if (param_7 == 0) {
    uVar1 = 1;
    iVar8 = 1;
  }
  else {
    uVar1 = 2;
    *(undefined1 *)((int)param_5 + 0x55) = 0;
    *(undefined1 *)((int)param_5 + 0x53) = 1;
    *(undefined1 *)((int)param_5 + 0x52) = 1;
    *(undefined2 *)((int)param_5 + 0x4e) = 1;
    iVar8 = 2;
    *(uint *)(param_4 + 0x8c) = *(uint *)(param_4 + 0x8c) & 0xffffe03f | 0x40;
    *(uint *)(param_4 + 0xcc) = *(uint *)(param_4 + 0xcc) & 0x80ffffff | 0x1000000;
  }
  *(undefined4 *)(param_4 + 0x20c) = uVar1;
  iVar3 = 0x48;
  *(undefined4 *)(param_4 + 0x214) = 0;
  *(uint *)(param_4 + 0x208) = iVar8 << 7 | *(uint *)(param_4 + 0x208) & 0xfffff87f;
  if (*(char *)(param_3 + 0x118) == '\0') {
    iVar3 = 0;
  }
  return (int)param_5 + iVar3 + 0x240;
}

/* FUN_00087cd0 @ 0x87cd0 (188 bytes) */
int FUN_00087cd0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = param_2 + 0x124;
  if (param_2 != 0) {
    if (iVar1 == *(int *)(param_1 + 0x1e70)) {
      *(undefined4 *)(param_1 + 0x1e70) = 0;
    }
    FUN_0004b5d0(param_1,iVar1);
    if (iVar1 == *(int *)(param_1 + 0x1e64)) {
      *(undefined4 *)(param_1 + 0x1e64) = 0;
    }
    if (*(int *)(((unsigned char *)0x00001488) + param_1) == param_2) {
      *(undefined4 *)(((unsigned char *)0x00001488) + param_1) = 0;
    }
    if (iVar1 == *(int *)(param_1 + 0x1e5c)) {
      FUN_0004b480(param_1,1);
      return;
    }
  }
  return;
}

/* FUN_00087da0 @ 0x87da0 (172 bytes) */
int FUN_00087da0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = param_2 + 0x124;
  if (iVar1 == *(int *)(param_1 + 0x1e70)) {
    *(undefined4 *)(param_1 + 0x1e70) = 0;
  }
  FUN_0004b5d0(param_1,iVar1);
  if (iVar1 == *(int *)(param_1 + 0x1e64)) {
    *(undefined4 *)(param_1 + 0x1e64) = 0;
  }
  if (*(int *)(((unsigned char *)0x00001488) + param_1) == param_2) {
    *(undefined4 *)(((unsigned char *)0x00001488) + param_1) = 0;
  }
  if (iVar1 == *(int *)(param_1 + 0x1e5c)) {
    FUN_0004b480(param_1,1);
    return;
  }
  return;
}

/* FUN_00087e60 @ 0x87e60 (8 bytes) */
int FUN_00087e60()
{
  return ((unsigned char *)0x00003880);
}

/* FUN_00087e70 @ 0x87e70 (8 bytes) */
int FUN_00087e70()
{
  return ((unsigned char *)0x00003880);
}

/* FUN_00087e80 @ 0x87e80 (764 bytes) */
int FUN_00087e80(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  iVar8 = param_3 + 0x124;
  uVar3 = param_1[0x8f8];
  *(undefined4 *)(((unsigned char *)0x000037cc) + param_3) = 0;
  ((unsigned char *)0x000037e8)[param_3] = (char)uVar3;
  if (param_3 == 0) {
    return 0;
  }
  *(int *)(((unsigned char *)0x000037e4) + param_3) = param_3;
  local_38 = 0;
  local_34 = 2;
  local_30 = 0;
  local_40 = 0;
  local_3c = 0;
  uVar3 = param_4[1];
  uVar5 = param_4[2];
  iVar6 = param_1[0x8f8];
  *(undefined4 *)(param_3 + 4) = *param_4;
  *(undefined4 *)(param_3 + 8) = uVar3;
  *(undefined4 *)(param_3 + 0xc) = uVar5;
  local_48 = param_4[2];
  local_44 = *param_4;
  if (param_2 != 0) {
    *(undefined4 *)(((unsigned char *)0x000011fc) + param_3) = 0;
    iVar9 = *(int *)(param_2 + 0x74);
    iVar4 = FUN_000abb60(param_1);
    if (iVar4 == 0x801) {
      local_3c = local_3c | 0xc;
    }
    else if (iVar4 == 0x2601) {
      local_3c = local_3c | 4;
    }
    else if (iVar4 == 0x800) {
      local_3c = local_3c | 8;
    }
    if (*(char *)(iVar9 + 5) != '\0') goto LAB_00088008;
  }
  else {
    local_3c = 2;
    _memset(((unsigned char *)0x00003100) + param_3,0,0x100);
    iVar9 = 0x10;
    iVar4 = iVar8;
    do {
      ((unsigned char *)0x00002fdc)[iVar4] = 1;
      iVar4 = iVar4 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    *(undefined4 *)(((unsigned char *)0x000011fc) + param_3) = 0;
  }
  iVar4 = param_1[0x917];
  if (iVar4 != 0) {
    local_38 = 0;
    do {
      local_38 = local_38 << 1 | 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    local_3c = local_3c | 0x400;
  }
LAB_00088008:
  if (iVar6 != 0) {
    local_3c = local_3c | 0x100;
    *(undefined4 *)(FUN_00001830 + param_3) = param_1[0x9db];
  }
  uVar2 = local_3c | 0x80;
  if (*(char *)(param_3 + 0x120) != '\0') {
    uVar2 = local_3c | 0x280;
  }
  local_3c = uVar2;
  iVar4 = FUN_000b4400(param_1,param_3 + 0x18a8,param_3 + 0x1784,&local_48,iVar8);
  if (iVar4 == 1) {
    return 0xfffffffe;
  }
  if (param_2 != 0) {
    if (iVar6 == 0) {
      iVar6 = *(int *)(((unsigned char *)0x000037cc) + param_3);
      iVar9 = *(int *)(((unsigned char *)0x000037d0) + param_3);
    }
    else {
      iVar6 = *(int *)(((unsigned char *)0x000037d8) + param_3);
      iVar9 = *(int *)(((unsigned char *)0x000037dc) + param_3);
    }
    if (iVar4 == 0) {
      *(undefined1 *)(param_2 + 0x6c) = 1;
    }
    else {
      *(undefined1 *)(param_2 + 0x6c) = 0;
      *param_1 = 1;
    }
    uVar3 = *(undefined4 *)(((unsigned char *)0x00003874) + param_3);
    *(int *)(param_2 + 0x54) = iVar6;
    *(int *)(param_2 + 0x58) = iVar9;
    iVar7 = 0;
    *(undefined4 *)(param_2 + 100) = 0;
    *(undefined4 *)(param_2 + 0x5c) = uVar3;
    do {
      for (uVar2 = *(uint *)(((unsigned char *)0x000010b8) + iVar8); uVar2 != 0; uVar2 = uVar2 >> 1) {
        if ((uVar2 & 1) != 0) {
          *(int *)(param_2 + 100) = *(int *)(param_2 + 100) + 1;
        }
      }
      bVar1 = iVar7 != 7;
      iVar8 = iVar8 + 4;
      iVar7 = iVar7 + 1;
    } while (bVar1);
    *(int *)(param_2 + 0x68) = *(int *)(((unsigned char *)0x00003870) + param_3) + 1;
    uVar3 = *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x7c);
    *(int *)(param_2 + 0x50) = iVar6 + iVar9;
    *(undefined4 *)(param_2 + 0x60) = uVar3;
    *(undefined *)(param_2 + 2) = ((unsigned char *)0x000036d7)[param_3];
    *(undefined *)(param_2 + 1) = ((unsigned char *)0x000036d6)[param_3];
  }
  if (iVar4 == 0) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_00088190 @ 0x88190 (740 bytes) */
int FUN_00088190(param_1, param_2)
  int param_1;
  char *param_2;
{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar5 = param_2 + 0x124;
  if (param_2 != (char *)0x0) {
    if (*(int *)(param_1 + 0x23e0) == 0) {
      if (*(int *)(param_2 + 0x37cc) == 0) {
        ((int (*)())FUN_00087e80)(param_1,0,*(int *)(param_2 + 0x37e4),*(int *)(param_2 + 0x37e4) + 4);
        *param_2 = '\0';
      }
      pcVar4 = pcVar5;
      if (0 < *(int *)(param_2 + 0x37cc)) {
        *(char **)(param_1 + 0x1e70) = pcVar5;
        *(char **)(param_1 + 0x1e5c) = pcVar5;
        *(char **)(param_2 + 0x37e4) = param_2;
      }
    }
    else {
      if (*(int *)(param_2 + 0x37d8) == 0) {
        ((int (*)())FUN_00087e80)(param_1,0,*(int *)(param_2 + 0x37e4),*(int *)(param_2 + 0x37e4) + 4);
        *param_2 = '\0';
      }
      if (0 < *(int *)(param_2 + 0x37d8)) {
        *(char **)(param_1 + 0x1e70) = pcVar5;
        *(char **)(param_1 + 0x1e5c) = pcVar5;
        *(char **)(param_2 + 0x37e4) = param_2;
      }
      pcVar4 = param_2 + 0x140;
    }
    pcVar1 = *(char **)(((unsigned char *)0x00001488) + param_1);
    if ((pcVar1 != (char *)0x0) && (param_2 != pcVar1)) {
      *pcVar1 = '\0';
    }
    if (*param_2 == '\0') {
      iVar3 = *(int *)(param_1 + 0x2768);
      *(undefined4 *)(((unsigned char *)0x00001488) + param_1) = 0;
      if ((iVar3 == 0) || (*(int *)(param_1 + 0x277c) == -1)) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x277c) * 4 + iVar3 + 0xc0);
      }
      *(undefined4 *)(param_2 + 0x164c) = uVar2;
      *(undefined4 *)(param_2 + 0x1208) = uVar2;
      param_2[0x1420] = '\0';
      param_2[0x1421] = '\0';
      param_2[0x1422] = '\0';
      param_2[0x1423] = '\0';
    }
    if (param_2 == *(char **)(((unsigned char *)0x00001488) + param_1)) {
      if ((param_2[0x36d7] != '\0') &&
         (((*(uint *)(param_1 + 0x38) & 0x400) != 0 || ((*(uint *)(param_1 + 0x3c) & 1) != 0)))) {
        FUN_000b51a0(param_1,param_2 + 0x18a8,param_2 + 0x1784);
        param_2[0x120f] = '\0';
      }
      if ((param_2[0x3748] != '\0') && ((*(uint *)(param_1 + 0x38) & 0x100) != 0)) {
        FUN_000b5320(param_1,param_2 + 0x18a8,param_2 + 0x1784);
        param_2[0x120f] = '\0';
      }
      if ((*(int *)(param_2 + 0x374c) != 0) &&
         (*(short *)(param_1 + 0x34) != 0 || *(short *)(param_1 + 0x32) != 0)) {
        FUN_000b50a0(param_1,param_2 + 0x18a8,param_2 + 0x1784);
        param_2[0x120f] = '\0';
      }
    }
    else {
      if (*(char *)(param_1 + 0x1868) == '\0') {
        (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,0);
      }
      *(char **)(((unsigned char *)0x00001488) + param_1) = param_2;
      *param_2 = '\x01';
      pcVar4[0] = '\0';
      pcVar4[1] = '\0';
      pcVar4[2] = '\0';
      pcVar4[3] = '\0';
      param_2[0x1424] = '\0';
      param_2[0x1425] = '\0';
      param_2[0x1426] = '\0';
      param_2[0x1427] = '\0';
      param_2[0x120f] = '\0';
      if (param_2[0x36d7] != '\0') {
        FUN_000b51a0(param_1,param_2 + 0x18a8,param_2 + 0x1784);
      }
      if (param_2[0x3748] != '\0') {
        FUN_000b5320(param_1,param_2 + 0x18a8,param_2 + 0x1784);
      }
      if (*(int *)(param_2 + 0x374c) != 0) {
        FUN_000b50a0(param_1,param_2 + 0x18a8,param_2 + 0x1784);
      }
    }
    (**(code **)(param_1 + 0x294c))(param_1,pcVar5);
    if ((*(uint *)(param_1 + 0x1930) & 0xc0100000) != 0) {
      (**(code **)(((unsigned char *)0x00001330) + param_1))(param_1);
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) & 0x3fefffff;
    }
  }
  return 0;
}

/* FUN_00088480 @ 0x88480 (268 bytes) */
int FUN_00088480(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  pbVar4 = *(byte **)(param_1 + 8);
  iVar8 = 0;
  iVar3 = 0;
  iVar9 = *(int *)(param_1 + 0xc) - (int)pbVar4;
  iVar5 = DAT_001dbcd0 + -1;
  do {
    uVar2 = iVar8 + iVar5;
    iVar6 = ((int)uVar2 >> 1) + (uint)((int)uVar2 < 0 && (uVar2 & 1) != 0);
    if (iVar9 < 1) {
      bVar1 = iVar3 == 0;
LAB_000884dc:
      iVar7 = 0;
    }
    else {
      iVar3 = (uint)*pbVar4 - (int)(char)*(PTR_s_1D_001e9158)[iVar6 * 3];
      bVar1 = iVar3 == 0;
      if (!bVar1) goto LAB_000884dc;
      iVar7 = 0;
      iVar10 = iVar9;
      do {
        iVar7 = iVar7 + 1;
        iVar10 = iVar10 + -1;
        if (iVar10 == 0) {
          iVar3 = 0;
          goto LAB_0008855c;
        }
        iVar3 = (uint)pbVar4[iVar7] - (int)(char)(PTR_s_1D_001e9158)[iVar6 * 3][iVar7];
        bVar1 = false;
      } while (iVar3 == 0);
    }
    if (iVar3 < 1) {
      if (bVar1) {
LAB_0008855c:
        if ((PTR_s_1D_001e9158)[iVar6 * 3][iVar7] == '\0') {
          *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(&UNK_001e915c + iVar6 * 0xc);
          *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(&UNK_001e9160 + iVar6 * 0xc);
          return;
        }
      }
      iVar5 = iVar6 + -1;
    }
    else {
      iVar8 = iVar6 + 1;
    }
    if (iVar5 < iVar8) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
      return;
    }
  } while( true );
}

/* FUN_000885b0 @ 0x885b0 (860 bytes) */
int FUN_000885b0(param_1)
  int param_1;
{
  byte bVar1;
  bool bVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  double dVar9;
  double dVar10;
  
  dVar3 = DOUBLE_001aa238;
  dVar9 = DOUBLE_001aa1e0;
  pbVar6 = *(byte **)(param_1 + 0xc);
  bVar1 = *pbVar6;
  dVar10 = DOUBLE_001aa228;
  while ((bVar1 - 0x30 & 0xff) < 10) {
    pbVar6 = pbVar6 + 1;
    *(byte **)(param_1 + 0xc) = pbVar6;
    dVar10 = dVar10 * dVar3 + ((double)CONCAT44(0x43300000,bVar1 - 0x30 ^ 0x80000000) - dVar9);
    bVar1 = *pbVar6;
  }
  if ((bVar1 == 0x2e) && (pbVar7 = pbVar6 + 1, pbVar6[1] != 0x2e)) {
    *(byte **)(param_1 + 0xc) = pbVar7;
    dVar4 = DOUBLE_001aa220;
    dVar3 = DOUBLE_001aa1e0;
    bVar1 = pbVar6[1];
    dVar9 = DOUBLE_001aa220;
    while ((bVar1 - 0x30 & 0xff) < 10) {
      pbVar7 = pbVar7 + 1;
      *(byte **)(param_1 + 0xc) = pbVar7;
      dVar10 = dVar9 * ((double)CONCAT44(0x43300000,bVar1 - 0x30 ^ 0x80000000) - dVar3) + dVar10;
      dVar9 = dVar9 * dVar4;
      bVar1 = *pbVar7;
    }
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  pbVar6 = *(byte **)(param_1 + 0xc);
  if ((*pbVar6 != 0x45) && (*pbVar6 != 0x65)) goto LAB_0008886c;
  *(byte **)(param_1 + 0xc) = pbVar6 + 1;
  if (pbVar6[1] == 0x2d) {
    bVar2 = true;
    *(byte **)(param_1 + 0xc) = pbVar6 + 2;
  }
  else {
    bVar2 = false;
    if (pbVar6[1] == 0x2b) {
      *(byte **)(param_1 + 0xc) = pbVar6 + 2;
    }
  }
  pbVar6 = *(byte **)(param_1 + 0xc);
  uVar8 = (uint)*pbVar6;
  if ((uVar8 - 0x30 & 0xff) < 10) {
LAB_000887c4:
    iVar5 = 0;
    do {
      iVar5 = iVar5 * 10 + uVar8 + -0x30;
      if (1000 < iVar5) {
        iVar5 = 1000;
      }
      pbVar6 = pbVar6 + 1;
      *(byte **)(param_1 + 0xc) = pbVar6;
      uVar8 = (uint)*pbVar6;
    } while ((uVar8 - 0x30 & 0xff) < 10);
    dVar9 = DOUBLE_001aa200;
    if (0 < iVar5) {
      do {
        dVar9 = dVar9 * DOUBLE_001aa238;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      pbVar6 = *(byte **)(param_1 + 0xc);
    }
  }
  else {
    ((int (*)())FUN_00088e70)(param_1,"Invalid scientific notation.");
    pbVar6 = *(byte **)(param_1 + 0xc);
    uVar8 = (uint)*pbVar6;
    dVar9 = DOUBLE_001aa200;
    if ((uVar8 - 0x30 & 0xff) < 10) goto LAB_000887c4;
  }
  if (bVar2) {
    dVar9 = DOUBLE_001aa200 / dVar9;
  }
  dVar10 = dVar10 * dVar9;
  bVar2 = false;
LAB_0008886c:
  bVar1 = *pbVar6;
  if ((((byte)(bVar1 + 0xbf) < 0x1a) || ((byte)(bVar1 + 0x9f) < 0x1a)) || (bVar1 == 0x5f)) {
    ((int (*)())FUN_00088e70)(param_1,"invalid suffix on number");
  }
  *(double *)(param_1 + 0x1c) = dVar10;
  *(int *)(param_1 + 0x18) = (int)dVar10;
  if ((bVar2) && (dVar10 == (double)CONCAT44(0x43300000,(int)dVar10) - DOUBLE_001aa250)) {
    *(undefined4 *)(param_1 + 0x14) = 0xf;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0x10;
  }
  return;
}

/* FUN_00088920 @ 0x88920 (892 bytes) */
int FUN_00088920(param_1)
  int param_1;
{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined1 *puVar7;
  
  puVar7 = *(undefined1 **)(param_1 + 0xc);
  puVar5 = *(undefined1 **)(param_1 + 0x10);
  if (puVar5 != puVar7) {
    bVar3 = false;
    bVar2 = false;
    bVar4 = false;
    iVar6 = (int)puVar5 - (int)puVar7;
    do {
      switch(*puVar7) {
      case 9:
      case 0x20:
        if ((!bVar2) && (!bVar3)) goto LAB_00088ae8;
        bVar3 = false;
        bVar2 = false;
        *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        break;
      case 10:
        if (bVar3) {
          bVar3 = true;
          bVar4 = false;
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        }
        else {
          bVar3 = true;
          bVar4 = false;
        }
        break;
      default:
        if ((bVar2) || (bVar3)) {
          bVar3 = false;
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        }
        if (!bVar4) goto LAB_00088afc;
LAB_00088ae8:
        bVar2 = false;
        break;
      case 0xd:
        if ((bVar2) || (bVar3)) {
          bVar3 = false;
          bVar2 = true;
          bVar4 = false;
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        }
        else {
          bVar2 = true;
          bVar4 = false;
        }
        break;
      case 0x23:
        if ((bVar2) || (bVar4 = true, bVar3)) {
          bVar3 = false;
          bVar2 = false;
          bVar4 = true;
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        }
      }
      iVar6 = iVar6 + -1;
      puVar7 = puVar7 + 1;
      *(undefined1 **)(param_1 + 0xc) = puVar7;
    } while (iVar6 != 0);
  }
LAB_00088afc:
  if (puVar7 < puVar5) {
    *(undefined1 **)(param_1 + 8) = puVar7;
    switch(*puVar7) {
    case 0x2b:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x19;
      break;
    case 0x2c:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x13;
      break;
    case 0x2d:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x1a;
      break;
    case 0x2e:
      if (puVar7[1] == '.') {
        *(undefined1 **)(param_1 + 0xc) = puVar7 + 2;
        *(undefined4 *)(param_1 + 0x14) = 0x12;
      }
      else {
        if ((byte)(puVar7[1] - 0x30) < 10) goto switchD_00088b48_caseD_30;
        *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
        *(undefined4 *)(param_1 + 0x14) = 0x11;
      }
      break;
    default:
      ((int (*)())FUN_00088e70)(param_1,"invalid character");
      return;
    case 0x31:
    case 0x32:
    case 0x33:
      if (puVar7[1] == 'D') {
        do {
          do {
            puVar5 = puVar7 + 1;
            *(undefined1 **)(param_1 + 0xc) = puVar5;
            cVar1 = puVar7[1];
            puVar7 = puVar5;
          } while ((byte)(cVar1 + 0xbfU) < 0x1a);
        } while ((((byte)(cVar1 + 0x9fU) < 0x1a) || ((byte)(cVar1 - 0x30U) < 10)) || (cVar1 == '_'))
        ;
        goto LAB_00088d48;
      }
    case 0x30:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
switchD_00088b48_caseD_30:
      ((int (*)())FUN_000885b0)(param_1);
      return;
    case 0x3b:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x14;
      break;
    case 0x3d:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x1b;
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
          puVar5 = puVar7 + 1;
          *(undefined1 **)(param_1 + 0xc) = puVar5;
          cVar1 = puVar7[1];
          puVar7 = puVar5;
        } while ((byte)(cVar1 + 0xbfU) < 0x1a);
      } while ((((byte)(cVar1 + 0x9fU) < 0x1a) || ((byte)(cVar1 - 0x30U) < 10)) || (cVar1 == '_'));
LAB_00088d48:
      ((int (*)())FUN_00088480)(param_1);
      return;
    case 0x5b:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x15;
      break;
    case 0x5d:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x16;
      break;
    case 0x7b:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x17;
      break;
    case 0x7d:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x18;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0x1c;
  }
  return;
}

/* FUN_00088e70 @ 0x88e70 (112 bytes) */
int FUN_00088e70(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  if ((int)param_1[10] < 0) {
    param_1[0xc] = param_2;
    param_1[0xb] = param_1[9];
    param_1[10] = param_1[2] - param_1[1];
  }
  param_1[3] = param_1[4];
  ((int (*)())FUN_00088920)(param_1);
  *(undefined4 *)*param_1 = 0x502;
  return;
}

/* FUN_00088ee0 @ 0x88ee0 (28 bytes) */
int FUN_00088ee0(param_1)
  undefined4 param_1;
{
  ((int (*)())FUN_00088e70)(param_1,"out of memory");
  return;
}

/* FUN_00088f00 @ 0x88f00 (184 bytes) */
int FUN_00088f00(param_1)
  int *param_1;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 0xc))(0x2c);
  if (puVar1 == (undefined4 *)0x0) {
    ((int (*)())FUN_00088ee0)(param_1);
  }
  else {
    puVar1[5] = puVar1 + 6;
    puVar1[10] = 0;
    puVar1[6] = 4;
    puVar1[2] = 0;
    puVar1[8] = 0x36;
    puVar1[1] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[7] = 0;
    puVar1[9] = 0;
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

/* FUN_00088fd0 @ 0x88fd0 (332 bytes) */
int FUN_00088fd0(param_1)
  int param_1;
{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  pcVar2 = *(char **)(param_1 + 8);
  iVar4 = *(int *)(param_1 + 0xc) - (int)pcVar2;
  if (*(int *)(param_1 + 0x14) == 0) {
    piVar1 = *(int **)(param_1 + 0x3c);
    if (piVar1 != (int *)0x0) {
      do {
        if (iVar4 == piVar1[2]) {
          if (iVar4 < 1) {
            if (iVar4 == 0) {
              return piVar1;
            }
          }
          else if (*pcVar2 == *(char *)piVar1[1]) {
            iVar3 = 0;
            iVar5 = iVar4;
            do {
              iVar3 = iVar3 + 1;
              iVar5 = iVar5 + -1;
              if (iVar5 == 0) {
                return piVar1;
              }
            } while (pcVar2[iVar3] == ((char *)piVar1[1])[iVar3]);
          }
        }
        piVar1 = (int *)*piVar1;
      } while (piVar1 != (int *)0x0);
    }
    piVar1 = *(int **)(param_1 + 0x4c);
    if (piVar1 != (int *)0x0) {
      do {
        if (iVar4 == piVar1[2]) {
          if (iVar4 < 1) {
            if (iVar4 == 0) {
LAB_00089104:
              return (int *)piVar1[3];
            }
          }
          else if (*pcVar2 == *(char *)piVar1[1]) {
            iVar3 = 0;
            iVar5 = iVar4;
            do {
              iVar3 = iVar3 + 1;
              iVar5 = iVar5 + -1;
              if (iVar5 == 0) goto LAB_00089104;
            } while (pcVar2[iVar3] == ((char *)piVar1[1])[iVar3]);
          }
        }
        piVar1 = (int *)*piVar1;
      } while (piVar1 != (int *)0x0);
    }
  }
  else {
    ((int (*)())FUN_00088e70)(param_1,"invalid variable name");
  }
  return (int *)0x0;
}

/* FUN_00089140 @ 0x89140 (28 bytes) */
int FUN_00089140(param_1)
  undefined4 param_1;
{
  ((int (*)())FUN_00088e70)(param_1,"internal error");
  return;
}

/* FUN_00089160 @ 0x89160 (44 bytes) */
int FUN_00089160(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(param_1 + 0x14) == param_2) {
    ((int (*)())FUN_00088920)(param_1);
    return;
  }
  ((int (*)())FUN_00088e70)(param_1,"unexpected token");
  return;
}

/* FUN_00089190 @ 0x89190 (124 bytes) */
int FUN_00089190(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  switch(param_2) {
  case 0x61:
  case 0x77:
    uVar1 = 3;
    break;
  case 0x62:
  case 0x7a:
    uVar1 = 2;
    break;
  default:
    ((int (*)())FUN_00088e70)(param_1,"invalid component");
  case 0x72:
  case 0x78:
    uVar1 = 0;
    break;
  case 0x67:
  case 0x79:
    uVar1 = 1;
  }
  return uVar1;
}

/* FUN_00089280 @ 0x89280 (156 bytes) */
int FUN_00089280(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined4 *)(param_2 + 0x18);
  if (*(uint *)(param_2 + 0xc) != 0) {
    uVar2 = *(uint *)(param_2 + 0x10);
    if (uVar2 < *(uint *)(param_2 + 0xc)) {
      *(uint *)(param_2 + 0x10) = uVar2 + 1;
      puVar1 = (undefined4 *)(uVar2 * 0x14 + *(int *)(param_2 + 0x14));
    }
    else {
      ((int (*)())FUN_00088e70)(param_1,"too many array initializers");
      puVar1 = (undefined4 *)(param_2 + 0x18);
    }
  }
  *puVar1 = 4;
  puVar1[4] = 0;
  puVar1[2] = 0x36;
  puVar1[1] = 0;
  puVar1[3] = 0;
  return puVar1;
}

/* FUN_00089320 @ 0x89320 (264 bytes) */
int FUN_00089320(param_1, param_2)
  int *param_1;
  float *param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = param_1[0x9116];
  iVar6 = 0;
  if (iVar7 != 0) {
    pfVar4 = (float *)(param_1 + 0x9016);
    iVar5 = 0;
    iVar8 = iVar7;
    do {
      if ((((*pfVar4 == *param_2) && (pfVar4[1] == param_2[1])) && (pfVar4[2] == param_2[2])) &&
         (pfVar4[3] == param_2[3])) {
        return iVar5;
      }
      iVar5 = iVar5 + 1;
      pfVar4 = pfVar4 + 4;
      iVar8 = iVar8 + -1;
      iVar6 = iVar7;
    } while (iVar8 != 0);
  }
  if (iVar6 < *(int *)(((unsigned char *)0x000011e4) + *param_1)) {
    fVar1 = *param_2;
    fVar2 = param_2[1];
    fVar3 = param_2[2];
    param_1[iVar7 * 4 + 0x9019] = (int)param_2[3];
    param_1[iVar7 * 4 + 0x9016] = (int)fVar1;
    param_1[iVar7 * 4 + 0x9017] = (int)fVar2;
    param_1[iVar7 * 4 + 0x9018] = (int)fVar3;
    param_1[0x9116] = param_1[0x9116] + 1;
  }
  else {
    ((int (*)())FUN_00088e70)(param_1,"too many constants");
    iVar7 = 0;
  }
  return iVar7;
}

/* FUN_00089430 @ 0x89430 (348 bytes) */
int FUN_00089430(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1[5] == 0) {
    iVar1 = param_1[6];
    if ((((iVar1 == 0xc) || (iVar1 == 0x1d)) || (iVar1 == 0x20)) ||
       ((iVar1 == 0x27 || (iVar1 == 0x2a)))) {
      puVar2 = (undefined4 *)0x0;
      ((int (*)())FUN_00088e70)(param_1,"reserved variable name");
    }
    else {
      iVar1 = ((int (*)())FUN_00088fd0)(param_1);
      if (iVar1 == 0) {
        puVar2 = (undefined4 *)(**(code **)(*param_1 + 0xc))(0x2c);
        if (puVar2 == (undefined4 *)0x0) {
          ((int (*)())FUN_00088ee0)(param_1);
        }
        else {
          puVar2[2] = param_1[3] - param_1[2];
          iVar1 = param_1[2];
          puVar2[5] = puVar2 + 6;
          puVar2[6] = 4;
          puVar2[8] = 0x36;
          puVar2[10] = 0;
          *puVar2 = 0;
          puVar2[3] = 0;
          puVar2[4] = 0;
          puVar2[1] = iVar1;
          puVar2[7] = 0;
          puVar2[9] = 0;
          if (param_1[0xf] == 0) {
            param_1[0xf] = (int)puVar2;
          }
          else {
            *(undefined4 **)param_1[0x10] = puVar2;
          }
          param_1[0x10] = (int)puVar2;
        }
      }
      else {
        puVar2 = (undefined4 *)0x0;
        ((int (*)())FUN_00088e70)(param_1,"redeclared variable name");
      }
    }
  }
  else {
    ((int (*)())FUN_00089140)(param_1);
    puVar2 = (undefined4 *)0x0;
  }
  ((int (*)())FUN_00088920)(param_1);
  return puVar2;
}

/* FUN_000895b0 @ 0x895b0 (364 bytes) */
int FUN_000895b0(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  int iVar1;
  
  if ((param_1[5] != 0) || (param_1[6] != 0x20)) {
    ((int (*)())FUN_00088e70)(param_1,"invalid result binding");
  }
  ((int (*)())FUN_00088920)(param_1);
  ((int (*)())FUN_00089160)(param_1,0x11);
  if (param_1[5] == 0) {
    param_2[2] = 0x35;
    *param_2 = 3;
    if (param_1[6] == 4) {
      ((int (*)())FUN_00088920)(param_1);
      param_2[1] = 0;
      if (*(char *)((int)param_1 + 0x3a) == '\0') {
        param_2[3] = 0;
      }
      else {
        iVar1 = 0;
        if (param_1[5] == 0x15) {
          ((int (*)())FUN_00088920)(param_1);
          if (((param_1[5] == 0xf) && (iVar1 = param_1[6], -1 < iVar1)) &&
             (iVar1 < (int)(uint)(byte)((unsigned char *)0x000013b3)[*param_1])) {
            ((int (*)())FUN_00088920)(param_1);
          }
          else {
            iVar1 = 0;
            ((int (*)())FUN_00088e70)(param_1,"invalid output color");
          }
          ((int (*)())FUN_00089160)(param_1,0x16);
        }
        param_2[3] = iVar1;
      }
    }
    else {
      if (param_1[6] != 5) goto LAB_00089638;
      ((int (*)())FUN_00088920)(param_1);
      param_2[1] = 1;
    }
    return;
  }
LAB_00089638:
  ((int (*)())FUN_00088e70)(param_1,"invalid result binding");
  return;
}

/* FUN_00089740 @ 0x89740 (88 bytes) */
int FUN_00089740(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x14) == 0x19) {
    ((int (*)())FUN_00088920)(param_1);
    uVar1 = 1;
  }
  else {
    uVar1 = 1;
    if (*(int *)(param_1 + 0x14) == 0x1a) {
      ((int (*)())FUN_00088920)(param_1);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* FUN_000897b0 @ 0x897b0 (164 bytes) */
double FUN_000897b0(int param_1)

{
  uint uVar1;
  double dVar2;
  double dVar3;
  
  uVar1 = ((int (*)())FUN_00089740)(param_1);
  dVar2 = DOUBLE_001aa228;
  dVar3 = (double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_001aa1e0;
  if (*(int *)(param_1 + 0x14) - 0xfU < 2) {
    dVar2 = *(double *)(param_1 + 0x1c);
    ((int (*)())FUN_00088920)(param_1);
  }
  else {
    ((int (*)())FUN_00088e70)(param_1,"invalid constant");
  }
  return dVar2 * dVar3;
}

