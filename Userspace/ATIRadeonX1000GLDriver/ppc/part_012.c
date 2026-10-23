#include "decls.h"

/* noop_83100 @ 0x83100 (4 bytes) */
int noop_83100()
{
  return;
}

/* FUN_00083110 @ 0x83110 (856 bytes) */
int FUN_00083110(param_1)
  int param_1;
{
  code *pcVar1;
  uint uVar2;
  uint loopIndex;
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
    loopIndex = 0;
    iVar4 = iVar5;
    iVar6 = param_1;
    do {
      uVar7 = *(uint *)(iVar6 + 0x1824);
      loopIndex = loopIndex + 1;
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
    } while (uVar2 >> 4 != loopIndex);
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
  uint loopIndex;
  uint uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 in_r7;
  undefined4 in_r8;
  uint in_r9;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
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
    iVar11 = *(int *)(param_1 + 0x14c);
    if ((iVar11 == 0) || (iVar3 = _memcmp(iVar11,local_68,0x30), iVar4 = iVar11, iVar3 != 0)) {
      iVar4 = FUN_0009edd0(param_1,local_68);
      if (iVar4 == 0) {
        uVar10 = *(uint *)(param_1 + 0x1804);
        puVar5 = (undefined4 *)FUN_00092bf0(param_1,0,0);
        puVar5[0x1a] = 0;
        *puVar5 = 0;
        uVar8 = *(uint *)(param_1 + 0x44);
        if ((uVar8 & 0x400) == 0) {
          uVar1 = uVar10 >> 3 & 1;
          uVar12 = uVar10 >> 1 & 1;
          iVar11 = 0;
        }
        else {
          uVar1 = uVar10 >> 3 & 1;
          uVar12 = uVar10 >> 1 & 1;
          in_r9 = uVar1 * 2 + (uVar10 & 1) + uVar12 + (uint)(byte)((unsigned char *)0x000011d2)[param_1];
          iVar11 = in_r9 + 2;
          puVar5[(byte)((unsigned char *)0x000011d2)[param_1] + 0x21] = iVar11;
          uVar8 = *(uint *)(param_1 + 0x44);
        }
        FUN_00092d40(puVar5,uVar8 >> 10 & 1,(uint)(byte)((unsigned char *)0x000011d2)[param_1]);
        if (uVar12 == 0) {
          iVar4 = 1;
          iVar13 = 1;
          iVar3 = 2;
          iVar9 = 2;
        }
        else {
          iVar13 = 2;
          iVar4 = 2;
          puVar5[0x1b] = 1;
          puVar5[0x13] = 1;
          iVar3 = 3;
          iVar9 = 3;
          FUN_00093130(puVar5);
        }
        puVar5[3] = iVar4;
        puVar5[0x1d] = iVar13;
        uVar6 = 0;
        uVar7 = 0;
        FUN_00092ea0(puVar5,3,0,0);
        if ((uVar10 & 1) != 0) {
          puVar5[4] = iVar3;
          puVar5[0x1f] = iVar9;
          uVar6 = 1;
          uVar7 = 0;
          FUN_00092ea0(puVar5,4,1,0);
          if ((uVar10 & 4) != 0) {
            puVar5[0x14] = iVar3;
            puVar5[0x1c] = iVar9;
            puVar5[0x15] = 3;
            FUN_000931e0(puVar5);
          }
          iVar3 = iVar4 + 2;
          iVar9 = iVar13 + 2;
        }
        if (uVar1 != 0) {
          puVar5[5] = iVar3;
          puVar5[0x1e] = iVar9;
          FUN_00092ea0(puVar5,3,2,1);
          puVar5[6] = iVar3 + 1;
          puVar5[0x20] = iVar9 + 1;
          uVar6 = 3;
          uVar7 = 1;
          iVar3 = iVar3 + 2;
          iVar9 = iVar9 + 2;
          FUN_00092ea0(puVar5,4,3,1);
        }
        if (uVar10 >> 4 != 0) {
          loopIndex = 0;
          iVar4 = param_1;
          do {
            iVar13 = *(int *)(iVar4 + 0x1824);
            puVar5[iVar13 + 0xb] = iVar3;
            iVar3 = iVar3 + 1;
            if (iVar11 == iVar9) {
              iVar9 = iVar9 + 1;
            }
            puVar5[iVar13 + 0x21] = iVar9;
            loopIndex = loopIndex + 1;
            iVar4 = iVar4 + 4;
            iVar9 = iVar9 + 1;
            FUN_00093000(puVar5,iVar13,uVar6,uVar7,in_r7,in_r8,in_r9);
          } while (uVar10 >> 4 != loopIndex);
        }
        FUN_0009a910(puVar5);
        if (iVar11 == iVar9) {
          iVar9 = iVar9 + 1;
        }
        iVar4 = FUN_0009c800(param_1,local_68,puVar5,iVar3,iVar9,0,0,1);
        *(undefined4 *)(iVar4 + 0x34) = 0;
        *(int *)(iVar4 + 0x38) = *(int *)(*(int *)(iVar4 + 0x54) + 0x3cc) + -1;
        iVar11 = *(int *)(param_1 + 0x14c);
      }
      else {
        iVar11 = *(int *)(param_1 + 0x14c);
      }
    }
    if (iVar4 != iVar11) {
      pcVar2 = *(code **)(((unsigned char *)0x000012d0) + param_1);
      *(int *)(param_1 + 0x14c) = iVar4;
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000;
      (*pcVar2)(param_1,iVar4);
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
  undefined4 *a6;
  int iVar1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 uVar2;
  code *pcVar3;
  
  ((int (*)())FUN_00083470)(param_1);
  ((int (*)())FUN_00083110)(param_1);
  a6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,9);
  *(undefined4 **)(0x00002748 + param_1 + 4) = a6;
  *a6 = 0x861;
  uVar2 = *(undefined4 *)(param_1 + 0x1ca0);
  a6[2] = 0x10824;
  a6[1] = uVar2;
  a6[3] = *(undefined4 *)(param_1 + 0x1b9c);
  uVar2 = *(undefined4 *)(param_1 + 0x1ba0);
  a6[5] = 0x82d;
  a6[4] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x1ca4);
  a6[7] = ((unsigned char *)0x00001047U);
  a6[6] = uVar2;
  a6[8] = *(undefined4 *)(param_1 + 0x1bb0);
  iVar1 = *(int *)(0x00002748 + param_1 + 4);
  pcVar3 = *(code **)(param_1 + 0x275c);
  *(int *)(0x00002748 + param_1 + 4) = iVar1 + 0x24;
  (*pcVar3)(param_1,iVar1 + 0x24,in_r5,in_r6,in_r7,in_r8,a6);
  return FUN_0004e880(param_1);
}

/* FUN_00083870 @ 0x83870 (1012 bytes) */
void FUN_00083870(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
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
  uint loopIndex;
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
  ((void (*)())gldValidateState)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,fparam_2,fparam_3,
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
          loopIndex = 0;
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
            loopIndex = loopIndex + 1;
            puVar5 = puVar5 + 4;
          } while (loopIndex < *(uint *)(iVar15 + 0x3cc));
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
      ((void (*)())gldValidateState)(param_1,extraout_r4,puVar11,uVar12,local_38,local_34[0],uVar8,dVar17,fparam_2,
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
      ((void (*)())gldValidateState)(param_1,extraout_r4_00,param_3,param_4,param_5,param_6,iVar15,dVar17,fparam_2,
                   fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff98);
    }
  }
  ((int (*)())FUN_000837b0)(param_1);
  return;
}

/* FUN_00083c80 @ 0x83c80 (12 bytes) */
void FUN_00083c80(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
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
int FUN_00083e10(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate, src2File, src2Index, src2Select, src2Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
  uint src2File;
  uint src2Index;
  uint *src2Select;
  uint *src2Negate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrArray;
  uint oldWord2;
  uint oldWord3;
  int instr;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0x44;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  uVar1 = (src0Index & 0xff) << 5;
  uVar2 = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | src0FileField | oldWord1 & 0xffffe000;
  uVar3 = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = uVar3 | uVar1 | src0FileField | oldWord1 & 0xffff0000;
  uVar4 = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfff80000;
  uVar5 = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xffc00000;
  oldWord0 = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfe000000;
  uVar6 = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfc000000;
  uVar7 = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf8000000;
  uVar8 = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf0000000
  ;
  oldWord1 = src0Negate[3];
  *(uint *)(instr + 8) = uVar2 | src1FileField | oldWord2 & 0xffffe000;
  oldWord3 = *(uint *)(instr + 0xc);
  *(uint *)(instr + 4) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField;
  uVar1 = (*src1Select & 7) << 0xd;
  src0FileField = src2File & 0xf;
  *(uint *)(instr + 8) = uVar1 | uVar2 | src1FileField | oldWord2 & 0xffff0000;
  uVar3 = (src2Index & 0xff) << 5;
  uVar4 = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfff80000;
  uVar5 = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xffc00000;
  oldWord0 = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfe000000;
  uVar6 = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfc000000;
  uVar7 = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf8000000;
  uVar8 = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf0000000
  ;
  oldWord1 = src1Negate[3];
  *(uint *)(instr + 0xc) = uVar3 | src0FileField | oldWord3 & 0xffffe000;
  *(uint *)(instr + 8) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField;
  uVar1 = (*src2Select & 7) << 0xd;
  *(uint *)(instr + 0xc) = uVar1 | uVar3 | src0FileField | oldWord3 & 0xffff0000;
  uVar2 = (src2Select[1] & 7) << 0x10;
  *(uint *)(instr + 0xc) = uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xfff80000;
  uVar4 = (src2Select[2] & 7) << 0x13;
  *(uint *)(instr + 0xc) = uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xffc00000;
  uVar5 = (src2Select[3] & 7) << 0x16;
  *(uint *)(instr + 0xc) = uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xfe000000;
  oldWord0 = (*src2Negate & 1) << 0x19;
  *(uint *)(instr + 0xc) =
       oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xfc000000;
  uVar6 = (src2Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 0xc) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xf8000000;
  uVar7 = (src2Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 0xc) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xf0000000
  ;
  *(uint *)(instr + 0xc) =
       (src2Negate[3] & 1) << 0x1c |
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_000840d0 @ 0x840d0 (548 bytes) */
int FUN_000840d0(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instr;
  int instrArray;
  uint oldWord2;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 1;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  uVar1 = (src0Index & 0xff) << 5;
  uVar2 = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | src0FileField | oldWord1 & 0xffffe000;
  uVar3 = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = uVar3 | uVar1 | src0FileField | oldWord1 & 0xffff0000;
  uVar4 = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfff80000;
  uVar5 = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xffc00000;
  oldWord0 = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfe000000;
  uVar6 = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfc000000;
  uVar7 = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf8000000;
  uVar8 = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf0000000
  ;
  oldWord1 = src0Negate[3];
  *(uint *)(instr + 8) = uVar2 | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField;
  uVar1 = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = uVar1 | uVar2 | src1FileField | oldWord2 & 0xffff0000;
  uVar3 = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfff80000;
  uVar4 = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xffc00000;
  uVar5 = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfe000000;
  oldWord0 = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfc000000;
  uVar6 = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf8000000;
  uVar7 = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf0000000
  ;
  uVar1 = (src1Negate[3] & 1) << 0x1c |
          uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField;
  *(uint *)(instr + 0xc) = uVar1;
  *(uint *)(instr + 8) = uVar1;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_00084300 @ 0x84300 (472 bytes) */
int FUN_00084300(param_1, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate)
  int param_1;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 allocation;
  int iVar14;
  int iVar15;
  
  iVar14 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar14 + 1U) {
    iVar14 = *(uint *)(param_1 + 0x3e0) * 0x10;
    allocation = _calloc(iVar14 + 0x200,1);
    if (iVar14 != 0) {
      _memcpy(allocation,*(undefined4 *)(param_1 + 0x3c8),iVar14);
      _free(*(undefined4 *)(param_1 + 0x3c8));
    }
    *(undefined4 *)(param_1 + 0x3c8) = allocation;
    iVar14 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar15 = *(int *)(param_1 + 0x3c8);
  iVar7 = iVar14 * 0x10;
  uVar8 = src0File & 0xf;
  *(int *)(param_1 + 0x3cc) = iVar14 + 1;
  iVar14 = iVar7 + iVar15;
  *(int *)(param_1 + 0x3dc) = iVar14;
  *(undefined4 *)(iVar7 + iVar15) = 0;
  *(undefined1 *)(iVar14 + 3) = 2;
  uVar11 = *(uint *)(iVar7 + iVar15);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(iVar7 + iVar15) = uVar2 | uVar1 | uVar11 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(iVar7 + iVar15) = uVar3 | uVar2 | uVar1 | uVar11 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(iVar7 + iVar15) = uVar4 | uVar3 | uVar2 | uVar1 | uVar11 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(iVar7 + iVar15) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar11 & 0xff8010ff;
  *(uint *)(iVar7 + iVar15) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar11 & 0xff0010ff;
  uVar12 = *(uint *)(iVar14 + 4);
  uVar10 = (src0Index & 0xff) << 5;
  *(uint *)(iVar14 + 4) = uVar10 | uVar8 | uVar12 & 0xffffe000;
  uVar1 = (*src0Select & 7) << 0xd;
  uVar9 = (src0Index & 0xff) << 5 | uVar8 | 0x16da000;
  *(uint *)(iVar14 + 4) = uVar1 | uVar10 | uVar8 | uVar12 & 0xffff0000;
  uVar2 = (src0Select[1] & 7) << 0x10;
  *(uint *)(iVar14 + 4) = uVar2 | uVar1 | uVar10 | uVar8 | uVar12 & 0xfff80000;
  uVar3 = (src0Select[2] & 7) << 0x13;
  *(uint *)(iVar14 + 4) = uVar3 | uVar2 | uVar1 | uVar10 | uVar8 | uVar12 & 0xffc00000;
  uVar4 = (src0Select[3] & 7) << 0x16;
  *(uint *)(iVar14 + 4) = uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar8 | uVar12 & 0xfe000000;
  uVar5 = (*src0Negate & 1) << 0x19;
  *(uint *)(iVar14 + 4) =
       uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar8 | uVar12 & 0xfc000000;
  uVar11 = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(iVar14 + 4) =
       uVar11 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar8 | uVar12 & 0xf8000000;
  uVar6 = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(iVar14 + 4) =
       uVar6 | uVar11 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar8 | uVar12 & 0xf0000000
  ;
  *(uint *)(iVar14 + 4) =
       (src0Negate[3] & 1) << 0x1c |
       uVar6 | uVar11 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | uVar10 | uVar8;
  *(uint *)(iVar14 + 8) = uVar9;
  *(uint *)(iVar14 + 0xc) = uVar9;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_000844e0 @ 0x844e0 (548 bytes) */
int FUN_000844e0(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instr;
  int instrArray;
  uint oldWord2;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 2;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  uVar1 = (src0Index & 0xff) << 5;
  uVar2 = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | src0FileField | oldWord1 & 0xffffe000;
  uVar3 = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = uVar3 | uVar1 | src0FileField | oldWord1 & 0xffff0000;
  uVar4 = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfff80000;
  uVar5 = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xffc00000;
  oldWord0 = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfe000000;
  uVar6 = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfc000000;
  uVar7 = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf8000000;
  uVar8 = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf0000000
  ;
  oldWord1 = src0Negate[3];
  *(uint *)(instr + 8) = uVar2 | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField;
  uVar1 = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = uVar1 | uVar2 | src1FileField | oldWord2 & 0xffff0000;
  uVar3 = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfff80000;
  uVar4 = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xffc00000;
  uVar5 = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfe000000;
  oldWord0 = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfc000000;
  uVar6 = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf8000000;
  uVar7 = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf0000000
  ;
  uVar1 = (src1Negate[3] & 1) << 0x1c |
          uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField;
  *(uint *)(instr + 0xc) = uVar1;
  *(uint *)(instr + 8) = uVar1;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_00084710 @ 0x84710 (548 bytes) */
int FUN_00084710(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instr;
  int instrArray;
  uint oldWord2;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 3;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  uVar1 = (src0Index & 0xff) << 5;
  uVar2 = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | src0FileField | oldWord1 & 0xffffe000;
  uVar3 = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = uVar3 | uVar1 | src0FileField | oldWord1 & 0xffff0000;
  uVar4 = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfff80000;
  uVar5 = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xffc00000;
  oldWord0 = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfe000000;
  uVar6 = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfc000000;
  uVar7 = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf8000000;
  uVar8 = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf0000000
  ;
  oldWord1 = src0Negate[3];
  *(uint *)(instr + 8) = uVar2 | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField;
  uVar1 = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = uVar1 | uVar2 | src1FileField | oldWord2 & 0xffff0000;
  uVar3 = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfff80000;
  uVar4 = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xffc00000;
  uVar5 = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfe000000;
  oldWord0 = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfc000000;
  uVar6 = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf8000000;
  uVar7 = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf0000000
  ;
  uVar1 = (src1Negate[3] & 1) << 0x1c |
          uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField;
  *(uint *)(instr + 0xc) = uVar1;
  *(uint *)(instr + 8) = uVar1;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_00084940 @ 0x84940 (692 bytes) */
int FUN_00084940(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate, src2File, src2Index, src2Select, src2Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
  uint src2File;
  uint src2Index;
  uint *src2Select;
  uint *src2Negate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrArray;
  uint oldWord2;
  uint oldWord3;
  int instr;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 4;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  uVar1 = (src0Index & 0xff) << 5;
  uVar2 = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | src0FileField | oldWord1 & 0xffffe000;
  uVar3 = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = uVar3 | uVar1 | src0FileField | oldWord1 & 0xffff0000;
  uVar4 = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfff80000;
  uVar5 = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xffc00000;
  oldWord0 = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfe000000;
  uVar6 = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfc000000;
  uVar7 = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf8000000;
  uVar8 = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf0000000
  ;
  oldWord1 = src0Negate[3];
  *(uint *)(instr + 8) = uVar2 | src1FileField | oldWord2 & 0xffffe000;
  oldWord3 = *(uint *)(instr + 0xc);
  *(uint *)(instr + 4) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField;
  uVar1 = (*src1Select & 7) << 0xd;
  src0FileField = src2File & 0xf;
  *(uint *)(instr + 8) = uVar1 | uVar2 | src1FileField | oldWord2 & 0xffff0000;
  uVar3 = (src2Index & 0xff) << 5;
  uVar4 = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfff80000;
  uVar5 = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xffc00000;
  oldWord0 = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfe000000;
  uVar6 = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfc000000;
  uVar7 = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf8000000;
  uVar8 = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf0000000
  ;
  oldWord1 = src1Negate[3];
  *(uint *)(instr + 0xc) = uVar3 | src0FileField | oldWord3 & 0xffffe000;
  *(uint *)(instr + 8) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField;
  uVar1 = (*src2Select & 7) << 0xd;
  *(uint *)(instr + 0xc) = uVar1 | uVar3 | src0FileField | oldWord3 & 0xffff0000;
  uVar2 = (src2Select[1] & 7) << 0x10;
  *(uint *)(instr + 0xc) = uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xfff80000;
  uVar4 = (src2Select[2] & 7) << 0x13;
  *(uint *)(instr + 0xc) = uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xffc00000;
  uVar5 = (src2Select[3] & 7) << 0x16;
  *(uint *)(instr + 0xc) = uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xfe000000;
  oldWord0 = (*src2Negate & 1) << 0x19;
  *(uint *)(instr + 0xc) =
       oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xfc000000;
  uVar6 = (src2Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 0xc) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xf8000000;
  uVar7 = (src2Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 0xc) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xf0000000
  ;
  *(uint *)(instr + 0xc) =
       (src2Negate[3] & 1) << 0x1c |
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_00084c00 @ 0x84c00 (692 bytes) */
int FUN_00084c00(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate, src2File, src2Index, src2Select, src2Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
  uint src2File;
  uint src2Index;
  uint *src2Select;
  uint *src2Negate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrArray;
  uint oldWord2;
  uint oldWord3;
  int instr;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0xb;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  uVar1 = (src0Index & 0xff) << 5;
  uVar2 = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | src0FileField | oldWord1 & 0xffffe000;
  uVar3 = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = uVar3 | uVar1 | src0FileField | oldWord1 & 0xffff0000;
  uVar4 = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfff80000;
  uVar5 = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xffc00000;
  oldWord0 = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfe000000;
  uVar6 = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfc000000;
  uVar7 = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf8000000;
  uVar8 = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf0000000
  ;
  oldWord1 = src0Negate[3];
  *(uint *)(instr + 8) = uVar2 | src1FileField | oldWord2 & 0xffffe000;
  oldWord3 = *(uint *)(instr + 0xc);
  *(uint *)(instr + 4) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField;
  uVar1 = (*src1Select & 7) << 0xd;
  src0FileField = src2File & 0xf;
  *(uint *)(instr + 8) = uVar1 | uVar2 | src1FileField | oldWord2 & 0xffff0000;
  uVar3 = (src2Index & 0xff) << 5;
  uVar4 = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfff80000;
  uVar5 = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xffc00000;
  oldWord0 = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfe000000;
  uVar6 = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfc000000;
  uVar7 = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf8000000;
  uVar8 = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf0000000
  ;
  oldWord1 = src1Negate[3];
  *(uint *)(instr + 0xc) = uVar3 | src0FileField | oldWord3 & 0xffffe000;
  *(uint *)(instr + 8) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField;
  uVar1 = (*src2Select & 7) << 0xd;
  *(uint *)(instr + 0xc) = uVar1 | uVar3 | src0FileField | oldWord3 & 0xffff0000;
  uVar2 = (src2Select[1] & 7) << 0x10;
  *(uint *)(instr + 0xc) = uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xfff80000;
  uVar4 = (src2Select[2] & 7) << 0x13;
  *(uint *)(instr + 0xc) = uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xffc00000;
  uVar5 = (src2Select[3] & 7) << 0x16;
  *(uint *)(instr + 0xc) = uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xfe000000;
  oldWord0 = (*src2Negate & 1) << 0x19;
  *(uint *)(instr + 0xc) =
       oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xfc000000;
  uVar6 = (src2Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 0xc) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xf8000000;
  uVar7 = (src2Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 0xc) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xf0000000
  ;
  *(uint *)(instr + 0xc) =
       (src2Negate[3] & 1) << 0x1c |
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_00084ec0 @ 0x84ec0 (692 bytes) */
int FUN_00084ec0(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate, src2File, src2Index, src2Select, src2Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
  uint src2File;
  uint src2Index;
  uint *src2Select;
  uint *src2Negate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrArray;
  uint oldWord2;
  uint oldWord3;
  int instr;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0xc;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  uVar1 = (src0Index & 0xff) << 5;
  uVar2 = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | src0FileField | oldWord1 & 0xffffe000;
  uVar3 = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = uVar3 | uVar1 | src0FileField | oldWord1 & 0xffff0000;
  uVar4 = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfff80000;
  uVar5 = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xffc00000;
  oldWord0 = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfe000000;
  uVar6 = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfc000000;
  uVar7 = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf8000000;
  uVar8 = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf0000000
  ;
  oldWord1 = src0Negate[3];
  *(uint *)(instr + 8) = uVar2 | src1FileField | oldWord2 & 0xffffe000;
  oldWord3 = *(uint *)(instr + 0xc);
  *(uint *)(instr + 4) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField;
  uVar1 = (*src1Select & 7) << 0xd;
  src0FileField = src2File & 0xf;
  *(uint *)(instr + 8) = uVar1 | uVar2 | src1FileField | oldWord2 & 0xffff0000;
  uVar3 = (src2Index & 0xff) << 5;
  uVar4 = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfff80000;
  uVar5 = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xffc00000;
  oldWord0 = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfe000000;
  uVar6 = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfc000000;
  uVar7 = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf8000000;
  uVar8 = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf0000000
  ;
  oldWord1 = src1Negate[3];
  *(uint *)(instr + 0xc) = uVar3 | src0FileField | oldWord3 & 0xffffe000;
  *(uint *)(instr + 8) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar1 | uVar2 | src1FileField;
  uVar1 = (*src2Select & 7) << 0xd;
  *(uint *)(instr + 0xc) = uVar1 | uVar3 | src0FileField | oldWord3 & 0xffff0000;
  uVar2 = (src2Select[1] & 7) << 0x10;
  *(uint *)(instr + 0xc) = uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xfff80000;
  uVar4 = (src2Select[2] & 7) << 0x13;
  *(uint *)(instr + 0xc) = uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xffc00000;
  uVar5 = (src2Select[3] & 7) << 0x16;
  *(uint *)(instr + 0xc) = uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xfe000000;
  oldWord0 = (*src2Negate & 1) << 0x19;
  *(uint *)(instr + 0xc) =
       oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xfc000000;
  uVar6 = (src2Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 0xc) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xf8000000;
  uVar7 = (src2Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 0xc) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField | oldWord3 & 0xf0000000
  ;
  *(uint *)(instr + 0xc) =
       (src2Negate[3] & 1) << 0x1c |
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar2 | uVar1 | uVar3 | src0FileField;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_00085180 @ 0x85180 (548 bytes) */
int FUN_00085180(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instr;
  int instrArray;
  uint oldWord2;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 8;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  uVar1 = (src0Index & 0xff) << 5;
  uVar2 = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | src0FileField | oldWord1 & 0xffffe000;
  uVar3 = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = uVar3 | uVar1 | src0FileField | oldWord1 & 0xffff0000;
  uVar4 = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfff80000;
  uVar5 = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xffc00000;
  oldWord0 = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfe000000;
  uVar6 = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfc000000;
  uVar7 = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf8000000;
  uVar8 = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf0000000
  ;
  oldWord1 = src0Negate[3];
  *(uint *)(instr + 8) = uVar2 | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField;
  uVar1 = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = uVar1 | uVar2 | src1FileField | oldWord2 & 0xffff0000;
  uVar3 = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfff80000;
  uVar4 = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xffc00000;
  uVar5 = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfe000000;
  oldWord0 = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfc000000;
  uVar6 = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf8000000;
  uVar7 = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf0000000
  ;
  uVar1 = (src1Negate[3] & 1) << 0x1c |
          uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField;
  *(uint *)(instr + 0xc) = uVar1;
  *(uint *)(instr + 8) = uVar1;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_000853b0 @ 0x853b0 (548 bytes) */
int FUN_000853b0(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instr;
  int instrArray;
  uint oldWord2;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 7;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  uVar1 = (src0Index & 0xff) << 5;
  uVar2 = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | src0FileField | oldWord1 & 0xffffe000;
  uVar3 = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = uVar3 | uVar1 | src0FileField | oldWord1 & 0xffff0000;
  uVar4 = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfff80000;
  uVar5 = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xffc00000;
  oldWord0 = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfe000000;
  uVar6 = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfc000000;
  uVar7 = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf8000000;
  uVar8 = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf0000000
  ;
  oldWord1 = src0Negate[3];
  *(uint *)(instr + 8) = uVar2 | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField;
  uVar1 = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = uVar1 | uVar2 | src1FileField | oldWord2 & 0xffff0000;
  uVar3 = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfff80000;
  uVar4 = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xffc00000;
  uVar5 = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfe000000;
  oldWord0 = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfc000000;
  uVar6 = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf8000000;
  uVar7 = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf0000000
  ;
  uVar1 = (src1Negate[3] & 1) << 0x1c |
          uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField;
  *(uint *)(instr + 0xc) = uVar1;
  *(uint *)(instr + 8) = uVar1;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_000855e0 @ 0x855e0 (548 bytes) */
int FUN_000855e0(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instr;
  int instrArray;
  uint oldWord2;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 10;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  uVar1 = (src0Index & 0xff) << 5;
  uVar2 = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | src0FileField | oldWord1 & 0xffffe000;
  uVar3 = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = uVar3 | uVar1 | src0FileField | oldWord1 & 0xffff0000;
  uVar4 = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfff80000;
  uVar5 = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xffc00000;
  oldWord0 = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfe000000;
  uVar6 = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfc000000;
  uVar7 = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf8000000;
  uVar8 = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf0000000
  ;
  oldWord1 = src0Negate[3];
  *(uint *)(instr + 8) = uVar2 | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField;
  uVar1 = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = uVar1 | uVar2 | src1FileField | oldWord2 & 0xffff0000;
  uVar3 = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfff80000;
  uVar4 = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xffc00000;
  uVar5 = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfe000000;
  oldWord0 = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfc000000;
  uVar6 = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf8000000;
  uVar7 = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf0000000
  ;
  uVar1 = (src1Negate[3] & 1) << 0x1c |
          uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField;
  *(uint *)(instr + 0xc) = uVar1;
  *(uint *)(instr + 8) = uVar1;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_00085810 @ 0x85810 (548 bytes) */
int FUN_00085810(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instr;
  int instrArray;
  uint oldWord2;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 9;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  uVar1 = (src0Index & 0xff) << 5;
  uVar2 = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | src0FileField | oldWord1 & 0xffffe000;
  uVar3 = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = uVar3 | uVar1 | src0FileField | oldWord1 & 0xffff0000;
  uVar4 = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfff80000;
  uVar5 = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xffc00000;
  oldWord0 = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfe000000;
  uVar6 = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfc000000;
  uVar7 = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf8000000;
  uVar8 = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf0000000
  ;
  oldWord1 = src0Negate[3];
  *(uint *)(instr + 8) = uVar2 | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField;
  uVar1 = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = uVar1 | uVar2 | src1FileField | oldWord2 & 0xffff0000;
  uVar3 = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfff80000;
  uVar4 = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xffc00000;
  uVar5 = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfe000000;
  oldWord0 = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfc000000;
  uVar6 = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf8000000;
  uVar7 = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf0000000
  ;
  uVar1 = (src1Negate[3] & 1) << 0x1c |
          uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField;
  *(uint *)(instr + 0xc) = uVar1;
  *(uint *)(instr + 8) = uVar1;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_00085a40 @ 0x85a40 (424 bytes) */
int FUN_00085a40(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint srcFile;
  uint srcIndex;
  uint *srcSelect;
  uint *srcNegate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int instrOffset;
  uint srcFileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instr;
  int instrArray;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0xe;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  srcFileField = srcFile & 0xf;
  uVar1 = (srcIndex & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | srcFileField | oldWord1 & 0xffffe000;
  uVar2 = (*srcSelect & 7) << 0xd;
  *(uint *)(instr + 4) = uVar2 | uVar1 | srcFileField | oldWord1 & 0xffff0000;
  uVar3 = (srcSelect[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xfff80000;
  uVar4 = (srcSelect[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xffc00000;
  uVar5 = (srcSelect[3] & 7) << 0x16;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xfe000000;
  oldWord0 = (*srcNegate & 1) << 0x19;
  *(uint *)(instr + 4) =
       oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xfc000000;
  uVar6 = (srcNegate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xf8000000;
  uVar7 = (srcNegate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xf0000000;
  uVar1 = (srcNegate[3] & 1) << 0x1c |
          uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField;
  *(uint *)(instr + 4) = uVar1;
  *(uint *)(instr + 8) = uVar1;
  *(uint *)(instr + 0xc) = uVar1;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_00085bf0 @ 0x85bf0 (424 bytes) */
int FUN_00085bf0(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint srcFile;
  uint srcIndex;
  uint *srcSelect;
  uint *srcNegate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int instrOffset;
  uint srcFileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instr;
  int instrArray;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0x47;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  srcFileField = srcFile & 0xf;
  uVar1 = (srcIndex & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | srcFileField | oldWord1 & 0xffffe000;
  uVar2 = (*srcSelect & 7) << 0xd;
  *(uint *)(instr + 4) = uVar2 | uVar1 | srcFileField | oldWord1 & 0xffff0000;
  uVar3 = (srcSelect[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xfff80000;
  uVar4 = (srcSelect[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xffc00000;
  uVar5 = (srcSelect[3] & 7) << 0x16;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xfe000000;
  oldWord0 = (*srcNegate & 1) << 0x19;
  *(uint *)(instr + 4) =
       oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xfc000000;
  uVar6 = (srcNegate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xf8000000;
  uVar7 = (srcNegate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xf0000000;
  uVar1 = (srcNegate[3] & 1) << 0x1c |
          uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField;
  *(uint *)(instr + 4) = uVar1;
  *(uint *)(instr + 8) = uVar1;
  *(uint *)(instr + 0xc) = uVar1;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_00085da0 @ 0x85da0 (424 bytes) */
int FUN_00085da0(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint srcFile;
  uint srcIndex;
  uint *srcSelect;
  uint *srcNegate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int instrOffset;
  uint srcFileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instr;
  int instrArray;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0x49;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  srcFileField = srcFile & 0xf;
  uVar1 = (srcIndex & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | srcFileField | oldWord1 & 0xffffe000;
  uVar2 = (*srcSelect & 7) << 0xd;
  *(uint *)(instr + 4) = uVar2 | uVar1 | srcFileField | oldWord1 & 0xffff0000;
  uVar3 = (srcSelect[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xfff80000;
  uVar4 = (srcSelect[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xffc00000;
  uVar5 = (srcSelect[3] & 7) << 0x16;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xfe000000;
  oldWord0 = (*srcNegate & 1) << 0x19;
  *(uint *)(instr + 4) =
       oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xfc000000;
  uVar6 = (srcNegate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xf8000000;
  uVar7 = (srcNegate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xf0000000;
  uVar1 = (srcNegate[3] & 1) << 0x1c |
          uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField;
  *(uint *)(instr + 4) = uVar1;
  *(uint *)(instr + 8) = uVar1;
  *(uint *)(instr + 0xc) = uVar1;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_00085f50 @ 0x85f50 (424 bytes) */
int FUN_00085f50(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint srcFile;
  uint srcIndex;
  uint *srcSelect;
  uint *srcNegate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int instrOffset;
  uint srcFileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instr;
  int instrArray;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0x4b;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  srcFileField = srcFile & 0xf;
  uVar1 = (srcIndex & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | srcFileField | oldWord1 & 0xffffe000;
  uVar2 = (*srcSelect & 7) << 0xd;
  *(uint *)(instr + 4) = uVar2 | uVar1 | srcFileField | oldWord1 & 0xffff0000;
  uVar3 = (srcSelect[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xfff80000;
  uVar4 = (srcSelect[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xffc00000;
  uVar5 = (srcSelect[3] & 7) << 0x16;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xfe000000;
  oldWord0 = (*srcNegate & 1) << 0x19;
  *(uint *)(instr + 4) =
       oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xfc000000;
  uVar6 = (srcNegate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xf8000000;
  uVar7 = (srcNegate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xf0000000;
  uVar1 = (srcNegate[3] & 1) << 0x1c |
          uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField;
  *(uint *)(instr + 4) = uVar1;
  *(uint *)(instr + 8) = uVar1;
  *(uint *)(instr + 0xc) = uVar1;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_00086100 @ 0x86100 (424 bytes) */
int FUN_00086100(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint srcFile;
  uint srcIndex;
  uint *srcSelect;
  uint *srcNegate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int instrOffset;
  uint srcFileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instr;
  int instrArray;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0x43;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  srcFileField = srcFile & 0xf;
  uVar1 = (srcIndex & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | srcFileField | oldWord1 & 0xffffe000;
  uVar2 = (*srcSelect & 7) << 0xd;
  *(uint *)(instr + 4) = uVar2 | uVar1 | srcFileField | oldWord1 & 0xffff0000;
  uVar3 = (srcSelect[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xfff80000;
  uVar4 = (srcSelect[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xffc00000;
  uVar5 = (srcSelect[3] & 7) << 0x16;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xfe000000;
  oldWord0 = (*srcNegate & 1) << 0x19;
  *(uint *)(instr + 4) =
       oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xfc000000;
  uVar6 = (srcNegate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xf8000000;
  uVar7 = (srcNegate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField | oldWord1 & 0xf0000000;
  uVar1 = (srcNegate[3] & 1) << 0x1c |
          uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | srcFileField;
  *(uint *)(instr + 4) = uVar1;
  *(uint *)(instr + 8) = uVar1;
  *(uint *)(instr + 0xc) = uVar1;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_000862b0 @ 0x862b0 (548 bytes) */
int FUN_000862b0(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instr;
  int instrArray;
  uint oldWord2;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0x45;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  uVar1 = (src0Index & 0xff) << 5;
  uVar2 = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | src0FileField | oldWord1 & 0xffffe000;
  uVar3 = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = uVar3 | uVar1 | src0FileField | oldWord1 & 0xffff0000;
  uVar4 = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfff80000;
  uVar5 = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xffc00000;
  oldWord0 = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfe000000;
  uVar6 = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfc000000;
  uVar7 = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf8000000;
  uVar8 = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf0000000
  ;
  oldWord1 = src0Negate[3];
  *(uint *)(instr + 8) = uVar2 | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField;
  uVar1 = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = uVar1 | uVar2 | src1FileField | oldWord2 & 0xffff0000;
  uVar3 = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfff80000;
  uVar4 = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xffc00000;
  uVar5 = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfe000000;
  oldWord0 = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfc000000;
  uVar6 = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf8000000;
  uVar7 = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf0000000
  ;
  uVar1 = (src1Negate[3] & 1) << 0x1c |
          uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField;
  *(uint *)(instr + 0xc) = uVar1;
  *(uint *)(instr + 8) = uVar1;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_000864e0 @ 0x864e0 (548 bytes) */
int FUN_000864e0(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instr;
  int instrArray;
  uint oldWord2;
  
  instr = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instr + 1U) {
    instr = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(instr + 0x200,1);
    if (instr != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),instr);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instr = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instr * 0x10;
  *(int *)(ctx + ARB_instrCount) = instr + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0x4f;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  uVar1 = (dstFile & 0xf) << 8;
  uVar2 = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = uVar2 | uVar1 | oldWord0 & 0xfff010ff;
  uVar3 = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = uVar3 | uVar2 | uVar1 | oldWord0 & 0xffe010ff;
  uVar4 = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xffc010ff;
  uVar5 = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  uVar1 = (src0Index & 0xff) << 5;
  uVar2 = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = uVar1 | src0FileField | oldWord1 & 0xffffe000;
  uVar3 = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = uVar3 | uVar1 | src0FileField | oldWord1 & 0xffff0000;
  uVar4 = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfff80000;
  uVar5 = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xffc00000;
  oldWord0 = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfe000000;
  uVar6 = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xfc000000;
  uVar7 = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf8000000;
  uVar8 = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField | oldWord1 & 0xf0000000
  ;
  oldWord1 = src0Negate[3];
  *(uint *)(instr + 8) = uVar2 | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (oldWord1 & 1) << 0x1c |
       uVar8 | uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | src0FileField;
  uVar1 = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = uVar1 | uVar2 | src1FileField | oldWord2 & 0xffff0000;
  uVar3 = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfff80000;
  uVar4 = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xffc00000;
  uVar5 = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfe000000;
  oldWord0 = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xfc000000;
  uVar6 = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf8000000;
  uVar7 = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField | oldWord2 & 0xf0000000
  ;
  uVar1 = (src1Negate[3] & 1) << 0x1c |
          uVar7 | uVar6 | oldWord0 | uVar5 | uVar4 | uVar3 | uVar1 | uVar2 | src1FileField;
  *(uint *)(instr + 0xc) = uVar1;
  *(uint *)(instr + 8) = uVar1;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
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
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar1;
  *puVar1 = 0x880;
  uVar2 = *(undefined4 *)(param_1 + 0x244c);
  puVar1[2] = 0x38882;
  puVar1[1] = uVar2;
  puVar1[3] = *(undefined4 *)(param_1 + 400);
  puVar1[4] = *(undefined4 *)(param_1 + 0x194);
  puVar1[5] = *(undefined4 *)(param_1 + 0xf0);
  puVar1[6] = *(undefined4 *)(param_1 + 0x198);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(0x00002748 + param_1 + 4) = *(int *)(0x00002748 + param_1 + 4) + 0x1c;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,*(int *)(0x00002748 + param_1 + 4));
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
  undefined4 *a6;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)(param_1 + 0x3d8);
  uVar5 = 0;
  uVar4 = *(uint *)(((unsigned char *)0x00003e28) + *(int *)(*(int *)(param_1 + 4) + 0x10));
  do {
    if ((uVar4 & 1 << (uVar5 & 0x3f)) != 0) {
      a6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,7);
      *(undefined4 **)(0x00002748 + param_1 + 4) = a6;
      *a6 = 0x880;
      iVar2 = *(int *)(param_1 + 0x1be0);
      a6[2] = 0x38882;
      a6[1] = uVar5 + iVar2;
      a6[3] = *puVar6;
      a6[4] = puVar6[1];
      a6[5] = puVar6[2];
      a6[6] = puVar6[3];
      iVar2 = *(int *)(0x00002748 + param_1 + 4);
      pcVar3 = *(code **)(param_1 + 0x275c);
      *(int *)(0x00002748 + param_1 + 4) = iVar2 + 0x1c;
      (*pcVar3)(param_1,iVar2 + 0x1c,in_r5,in_r6,in_r7,in_r8,a6);
    }
    bVar1 = uVar5 != 5;
    puVar6 = puVar6 + 4;
    uVar5 = uVar5 + 1;
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
  param_2[0x17] = *(undefined4 *)(0x00001af4 + param_1);
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
  uint uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint a2;
  undefined4 uVar5;
  undefined4 a4;
  undefined4 a5;
  uint uVar6;
  code *a6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  
  bVar1 = param_3 == 0;
  a2 = param_3;
  ((int (*)())FUN_00086a80)(param_1,param_5);
  *(undefined4 *)(param_1 + 0x1c8c) = *(undefined4 *)(param_1 + 0x2814);
  *(undefined4 *)(param_1 + 0x1c94) = *(undefined4 *)(param_1 + 0x2818);
  *(undefined4 *)(param_1 + 0x23e0) = 0;
  *(uint *)(param_1 + 0x1aa0) = param_4 & 1 | (param_3 & 1) << 1 | (param_3 & 1) << 2;
  *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) & 0xffff3fff | 0x1c000;
  *(uint *)(param_1 + 0x1b84) = *(uint *)(param_1 + 0x1b84) & 0xffffffc5 | 5;
  if (bVar1) {
    uVar2 = *(uint *)(param_1 + 0x1aa4) & 0xfffffff8;
    *(uint *)(param_1 + 0x1aa4) = uVar2;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x1aa4) & 0xfffffff8 | 7;
    *(uint *)(param_1 + 0x1aa4) = uVar2;
  }
  if (param_4 == 0) {
    *(uint *)(param_1 + 0x1aa4) = uVar2 & 0xffffffc7;
  }
  else {
    iVar8 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    *(uint *)(param_1 + 0x1aa4) = uVar2 & 0xff1c71c7 | 0x438438;
    *(char *)(param_1 + 0x1aab) = (char)*(undefined4 *)(((unsigned char *)0x00002db4) + iVar8);
    *(char *)(param_1 + 0x1aa9) = (char)*(undefined4 *)(((unsigned char *)0x00002e38) + iVar8);
  }
  uVar5 = 0;
  a5 = 2;
  a4 = 0xf;
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
  if (*(int *)(param_1 + 8) == 0xc) {
    uVar6 = *(uint *)(param_1 + 0x1b10);
    *(uint *)(param_1 + 7000) = *(uint *)(param_1 + 7000) & 0xfc000000;
    uVar2 = (int)((float)((double)CONCAT44(0x43300000,
                                           *(uint *)(*(int *)(param_1 + 4) + 0x15c) ^ 0x80000000) -
                         4503601774854144.0) * *(float *)(param_1 + 0x2814) + 0.0) & 0x1fff;
    *(uint *)(param_1 + 0x1b10) = uVar2 | uVar6 & 0xffffe000;
    *(uint *)(param_1 + 0x1b10) =
         ((int)((float)((double)CONCAT44(0x43300000,
                                         *(uint *)(*(int *)(param_1 + 4) + 0x160) ^ 0x80000000) -
                       4503601774854144.0) * *(float *)(param_1 + 0x2818) + 0.0) & 0x1fffU) << 0xd |
         uVar2 | uVar6 & 0xfc000000;
  }
  else {
    uVar6 = *(uint *)(param_1 + 0x1b10);
    *(uint *)(param_1 + 7000) = *(uint *)(param_1 + 7000) & 0xfc000000;
    uVar2 = (int)((float)((double)CONCAT44(0x43300000,
                                           *(uint *)(*(int *)(param_1 + 4) + 0x15c) ^ 0x80000000) -
                         4503601774854144.0) * *(float *)(param_1 + 0x2814) + 0.0) & 0x1fff;
    *(uint *)(param_1 + 0x1b10) = uVar2 | uVar6 & 0xffffe000;
    *(uint *)(param_1 + 0x1b10) =
         ((int)((float)((double)CONCAT44(0x43300000,
                                         *(uint *)(*(int *)(param_1 + 4) + 0x160) ^ 0x80000000) -
                       4503601774854144.0) * *(float *)(param_1 + 0x2818) + 0.0) & 0x1fffU) << 0xd |
         uVar2 | uVar6 & 0xfc000000;
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
    *(undefined4 *)(0x00001af4 + param_1) = 0;
  }
  uVar9 = *(undefined4 *)(param_1 + 0x1930);
  *(undefined4 *)(param_1 + 0x1b3c) = 0;
  FUN_0004b480(param_1,*(uint *)(param_1 + 0x18a4) >> 6 & 0xffff);
  a6 = *(code **)(((unsigned char *)0x00001330) + param_1);
  *(uint *)(param_1 + 0x1f2c) = *(uint *)(param_1 + 0x1f2c) & 0xfffff800 | 0x80;
  (*a6)(param_1,0xc0100000,a2,uVar5,a4,a5,a6);
  *(undefined4 *)(param_1 + 0x1930) = uVar9;
  if (!bVar1) {
    *(uint *)(param_1 + 0x1ae0) = *(uint *)(param_1 + 0x1ae0) & 0xfffffffe;
    *(uint *)(param_1 + 0x1ab0) = *(uint *)(param_1 + 0x1ab0) & 0xfffffffe;
  }
  puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x3d);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar4;
  puVar7 = puVar4 + 0x34;
  *puVar4 = 0x887;
  uVar5 = *(undefined4 *)(param_1 + 0x1b74);
  puVar4[2] = 0x82c;
  puVar4[1] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x1b84);
  puVar4[4] = ((unsigned char *)0x000010aeU);
  puVar4[3] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x1b30);
  puVar4[6] = ((unsigned char *)0x000013c0U);
  puVar4[5] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x1aa0);
  puVar4[8] = ((unsigned char *)0x000013c1U);
  puVar4[7] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x1aa4);
  puVar4[10] = ((unsigned char *)0x000013c2U);
  puVar4[9] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x1aa8);
  puVar4[0xc] = ((unsigned char *)0x000012f0U);
  puVar4[0xb] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x1aec);
  puVar4[0xe] = ((unsigned char *)0x000012f5U);
  puVar4[0xd] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x1a4c);
  puVar4[0x10] = ((unsigned char *)0x000012f6U);
  puVar4[0xf] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x1a50);
  puVar4[0x12] = ((unsigned char *)0x00001381U);
  puVar4[0x11] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x1a80);
  puVar4[0x14] = ((unsigned char *)0x00001386U);
  puVar4[0x13] = uVar5;
  puVar4[0x15] = *(undefined4 *)(param_1 + 0x1af8);
  puVar4[0x16] = 0x824;
  uVar5 = *(undefined4 *)(param_1 + 0x1b9c);
  puVar4[0x18] = 0x825;
  puVar4[0x17] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar4[0x1a] = 0x82d;
  puVar4[0x19] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x248c);
  puVar4[0x1c] = 0x854;
  puVar4[0x1b] = uVar5;
  uVar5 = **(undefined4 **)(param_1 + 0x2440);
  puVar4[0x1e] = 0x878;
  puVar4[0x1d] = uVar5;
  uVar5 = **(undefined4 **)(param_1 + 0x2444);
  puVar4[0x20] = ((unsigned char *)0x000010f8U);
  puVar4[0x1f] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 7000);
  puVar4[0x22] = ((unsigned char *)0x000010f9U);
  puVar4[0x21] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x1b10);
  puVar4[0x24] = ((unsigned char *)0x000010a2U);
  puVar4[0x23] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x1b3c);
  puVar4[0x26] = ((unsigned char *)0x00001383U);
  puVar4[0x25] = uVar5;
  uVar5 = *(undefined4 *)(0x00001af4 + param_1);
  puVar4[0x28] = ((unsigned char *)0x00001002U);
  puVar4[0x27] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x1b50);
  puVar4[0x2a] = ((unsigned char *)0x000010c0U);
  puVar4[0x29] = uVar5;
  puVar4[0x2b] = *(undefined4 *)(param_1 + 0x1f2c);
  puVar4[0x2c] = 0x825;
  uVar5 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar4[0x2e] = 0x766;
  puVar4[0x2d] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x1c8c);
  puVar4[0x30] = 0x768;
  puVar4[0x2f] = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 0x1c94);
  puVar4[0x32] = ((unsigned char *)0x000010faU);
  puVar4[0x31] = uVar5;
  puVar4[0x33] = *(undefined4 *)(param_1 + 0x1b60);
  if (!bVar1) {
    iVar8 = *(int *)(param_1 + 4);
    puVar3 = *(uint **)(iVar8 + 0x1d8);
    *puVar3 = (int)puVar7 - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(iVar8 + 0x1d8) = puVar7;
    puVar7 = puVar4 + 0x39;
    puVar4[0x34] = 0x2f000000;
    puVar4[0x35] = ((unsigned char *)0x000010e9U);
    uVar5 = *(undefined4 *)(param_1 + 0x1ae0);
    puVar4[0x37] = ((unsigned char *)0x000013c7U);
    puVar4[0x36] = uVar5;
    puVar4[0x38] = *(undefined4 *)(param_1 + 0x1ab0);
  }
  *puVar7 = ((unsigned char *)0x00001048U);
  uVar5 = *(undefined4 *)(param_1 + 0x1bc0);
  puVar7[2] = ((unsigned char *)0x00001047U);
  puVar7[1] = uVar5;
  puVar7[3] = *(undefined4 *)(param_1 + 0x1bb0);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar7 + 4;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar7 + 4);
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
  uint *puVar4;
  undefined4 extraout_r4;
  undefined4 *puVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  double fparam_1;
  
  puVar8 = *(undefined4 **)(param_1 + 0x2440);
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
  *puVar8 = param_2[0x11];
  **(undefined4 **)(param_1 + 0x2444) = param_2[0x12];
  *(undefined4 *)(param_1 + 0x1ae0) = param_2[0x15];
  *(undefined4 *)(param_1 + 7000) = param_2[0x13];
  *(undefined4 *)(param_1 + 0x1b10) = param_2[0x14];
  *(undefined4 *)(param_1 + 0x1b3c) = param_2[0x16];
  *(undefined4 *)(0x00001af4 + param_1) = param_2[0x17];
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
  uVar6 = param_2[0x22];
  *(undefined4 *)(param_1 + 0x1bb0) = uVar6;
  (*pcVar3)(param_1,0,in_r5,in_r6,in_r7,in_r8,uVar6,puVar8);
  if (((*(uint *)(param_1 + 0x44) & 0x20000) != 0) &&
     (puVar8 = *(undefined4 **)(param_1 + 0x1e70), puVar8 != (undefined4 *)0x0)) {
    if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
      cVar1 = ((unsigned char *)0x00001136)[param_1];
    }
    else {
      cVar1 = ((unsigned char *)0x000011d0)[param_1];
    }
    if (cVar1 == '\0') goto LAB_00087474;
  }
  puVar8 = *(undefined4 **)(param_1 + 0x1e5c);
LAB_00087474:
  *(undefined1 *)((int)puVar8 + 0x10eb) = 0;
  if (*(int *)(param_1 + 0x23e0) == 0) {
    *puVar8 = 0;
    puVar8[0x4c0] = 0;
  }
  else {
    puVar8[7] = 0;
    puVar8[0x54b] = 0;
  }
  ((void (*)())FUN_0004a8f0)(param_1,extraout_r4,in_r5,in_r6,fparam_1);
  (**(code **)(((unsigned char *)0x00001330) + param_1))(param_1,0xc0100000);
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) & 0x3fefffff;
  puVar8 = (undefined4 *)
           (**(code **)(param_1 + 0x2758))
                     (param_1,0x55,in_r5,in_r6,in_r7,in_r8,*(code **)(param_1 + 0x2758));
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar8;
  *puVar8 = 0x887;
  puVar2 = PTR_DAT_001e88c8;
  uVar6 = *(undefined4 *)(param_1 + 0x1b74);
  puVar8[2] = 0x82c;
  puVar8[1] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1b84);
  puVar8[4] = ((unsigned char *)0x000010aeU);
  puVar8[3] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1b30);
  puVar8[6] = ((unsigned char *)0x000013c0U);
  puVar8[5] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1aa0);
  puVar8[8] = ((unsigned char *)0x000013c1U);
  puVar8[7] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1aa4);
  puVar8[10] = ((unsigned char *)0x000013c2U);
  puVar8[9] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1aa8);
  puVar8[0xc] = ((unsigned char *)0x000012f0U);
  puVar8[0xb] = uVar6;
  uVar7 = *(uint *)(param_1 + 0x1aec);
  puVar8[0xd] = uVar7;
  if ((*(uint *)(puVar2 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    puVar8[0xd] = uVar7 & 0xfffffffe;
  }
  puVar8[0xe] = ((unsigned char *)0x000012f5U);
  uVar7 = *(uint *)(param_1 + 0x1a4c);
  puVar8[0xf] = uVar7;
  if ((*(uint *)(puVar2 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    puVar8[0xf] = uVar7 & 0xfffff7ff;
  }
  puVar8[0x10] = ((unsigned char *)0x000012f6U);
  uVar6 = *(undefined4 *)(param_1 + 0x1a50);
  puVar8[0x12] = ((unsigned char *)0x00001381U);
  puVar8[0x11] = uVar6;
  uVar7 = *(uint *)(param_1 + 0x1a80);
  puVar8[0x13] = uVar7;
  if ((*(uint *)(puVar2 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x4000) == 0) {
    puVar8[0x13] = uVar7 & 0xfffffffc;
  }
  puVar8[0x14] = ((unsigned char *)0x00001386U);
  puVar5 = puVar8 + 0x34;
  uVar6 = *(undefined4 *)(param_1 + 0x1af8);
  puVar8[0x16] = 0x824;
  puVar8[0x15] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1b9c);
  puVar8[0x18] = 0x825;
  puVar8[0x17] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar8[0x1a] = 0x82d;
  puVar8[0x19] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x248c);
  puVar8[0x1c] = 0x854;
  puVar8[0x1b] = uVar6;
  uVar6 = **(undefined4 **)(param_1 + 0x2440);
  puVar8[0x1e] = 0x878;
  puVar8[0x1d] = uVar6;
  uVar6 = **(undefined4 **)(param_1 + 0x2444);
  puVar8[0x20] = ((unsigned char *)0x000010a2U);
  puVar8[0x1f] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1b3c);
  puVar8[0x22] = ((unsigned char *)0x00001383U);
  puVar8[0x21] = uVar6;
  uVar6 = *(undefined4 *)(0x00001af4 + param_1);
  puVar8[0x24] = ((unsigned char *)0x00001002U);
  puVar8[0x23] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1b50);
  puVar8[0x26] = ((unsigned char *)0x000010c0U);
  puVar8[0x25] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1f2c);
  puVar8[0x28] = 0x825;
  puVar8[0x27] = uVar6;
  puVar8[0x29] = *(undefined4 *)(param_1 + 0x1ba0);
  puVar8[0x2a] = ((unsigned char *)0x00001008U);
  uVar6 = *(undefined4 *)(param_1 + 0x1a60);
  puVar8[0x2c] = ((unsigned char *)0x00001004U);
  puVar8[0x2b] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1a68);
  puVar8[0x2e] = ((unsigned char *)0x00001005U);
  puVar8[0x2d] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1a6c);
  puVar8[0x30] = ((unsigned char *)0x000010faU);
  puVar8[0x2f] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1b60);
  puVar8[0x32] = ((unsigned char *)0x000013c5U);
  puVar8[0x31] = uVar6;
  puVar8[0x33] = *(undefined4 *)(param_1 + 0x1ab8);
  if ((*(uint *)(param_1 + 0x2454) & 0x8000000) != 0) {
    puVar8[0x34] = ((unsigned char *)0x000013c5U);
    puVar5 = puVar8 + 0x36;
    puVar8[0x35] = *(undefined4 *)(param_1 + 0x1ab8);
  }
  puVar8 = (undefined4 *)FUN_0004dd10(param_1,puVar5);
  *puVar8 = 0x766;
  uVar6 = *(undefined4 *)(param_1 + 0x1c8c);
  puVar8[2] = 0x768;
  puVar8[1] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1c94);
  puVar8[4] = ((unsigned char *)0x000010faU);
  puVar8[3] = uVar6;
  puVar8[5] = *(undefined4 *)(param_1 + 0x1b60);
  iVar9 = *(int *)(param_1 + 4);
  puVar4 = *(uint **)(iVar9 + 0x1d8);
  *puVar4 = (int)(puVar8 + 6) - (int)puVar4 >> 2 | *puVar4;
  *(undefined4 **)(iVar9 + 0x1d8) = puVar8 + 6;
  puVar8[6] = 0x2f000000;
  puVar8[7] = ((unsigned char *)0x000010e9U);
  uVar6 = *(undefined4 *)(param_1 + 0x1ae0);
  puVar8[9] = ((unsigned char *)0x000013c7U);
  puVar8[8] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1ab0);
  puVar8[0xb] = ((unsigned char *)0x00001048U);
  puVar8[10] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1bc0);
  puVar8[0xd] = ((unsigned char *)0x00001047U);
  puVar8[0xc] = uVar6;
  puVar8[0xe] = *(undefined4 *)(param_1 + 0x1bb0);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar8 + 0xf;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar8 + 0xf);
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
  int loopIndex;
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
    loopIndex = 0;
    iVar8 = 0;
    do {
      iVar10 = iVar8 + *(int *)(iVar6 + 0x80);
      if (*(int *)(iVar10 + 8) != 0x34) {
        arbfpFetchParameterValue(param_1,iVar10,&fStack_48,param_4);
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
      loopIndex = loopIndex + 1;
      iVar8 = iVar8 + 0x14;
    } while (loopIndex < *(int *)(iVar6 + 0x84));
  }
  return;
}

/* FUN_00087960 @ 0x87960 (120 bytes) */
int FUN_00087960(param_1)
  int param_1;
{
  *(undefined4 *)(((unsigned char *)0x0000120cU) + param_1) = 0x1ff;
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

/* noop_879e0 @ 0x879e0 (4 bytes) */
int noop_879e0()
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
  return ((unsigned char *)0x00003880U);
}

/* FUN_00087e70 @ 0x87e70 (8 bytes) */
int FUN_00087e70()
{
  return ((unsigned char *)0x00003880U);
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
  /* local_48/local_44/local_40/local_3c/local_38/local_34/local_30 are one contiguous 7-word array
   * (&local_48 passed to FUN_000b4400, which internally indexes it param_4[0]..param_4[6] - and that
   * value flows straight through into ilRewriteForTextureState as its own param_4, where param_4[1] seeds a loop
   * counter). Declared as 7 separate scalars, they landed non-adjacent at -O0 (confirmed live: the
   * value ilRewriteForTextureState read via param_4[1] was heap-garbage-sized, not the small local_44 value),
   * corrupting a command-stream interpreter loop's iteration count downstream and eventually walking
   * off the end into zeroed memory, hitting the interpreter's own out-of-range-opcode safety net
   * (_exit(0), confirmed present in stock too - not itself a bug). Merged into a real array, aliased
   * back to the original names so the rest of this function's logic is unchanged (issue #64). */
  undefined4 local_48_arr[7];
#define local_48 local_48_arr[0]
#define local_44 local_48_arr[1]
#define local_40 local_48_arr[2]
#define local_3c local_48_arr[3]
#define local_38 local_48_arr[4]
#define local_34 local_48_arr[5]
#define local_30 local_48_arr[6]

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
    *(undefined4 *)(0x00001830 + param_3) = param_1[0x9db];
  }
  uVar2 = local_3c | 0x80;
  if (*(char *)(param_3 + 0x120) != '\0') {
    uVar2 = local_3c | 0x280;
  }
  local_3c = uVar2;
  iVar4 = FUN_000b4400(param_1,param_3 + 0x18a8,param_3 + 0x1784,&local_48,iVar8);
#undef local_48
#undef local_44
#undef local_40
#undef local_3c
#undef local_38
#undef local_34
#undef local_30
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
      /* issue #79 class: the stock's r4 here is the flags word itself (`lwz r4,0x1930(r29)`, tested by
       * `andis. r0,r4,0xc010`, then the `bctrl` at 0x88444); the siblings pass the literal 0xc0100000 */
      (**(code **)(((unsigned char *)0x00001330) + param_1))(param_1,*(undefined4 *)(param_1 + 0x1930));
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) & 0x3fefffff;
    }
  }
  return 0;
}

/* arbfpLookupKeyword @ 0x88480 (268 bytes) */
int arbfpLookupKeyword(parser)
  int parser;
{
  bool isEqual;
  uint sum;
  int compareResult;
  byte *tokenText;
  int high;
  int mid;
  int matchIndex;
  int low;
  int tokenLength;
  int remaining;
  
  tokenText = *(byte **)(parser + 8);
  low = 0;
  compareResult = 0;
  tokenLength = *(int *)(parser + 0xc) - (int)tokenText;
  high = DAT_001dbcd0 + -1;
  do {
    sum = low + high;
    mid = ((int)sum >> 1) + (uint)((int)sum < 0 && (sum & 1) != 0);
    if (tokenLength < 1) {
      isEqual = compareResult == 0;
LAB_000884dc:
      matchIndex = 0;
    }
    else {
      compareResult = (uint)*tokenText - (int)(char)*(PTR_s_1D_001e9158)[mid * 3];
      isEqual = compareResult == 0;
      if (!isEqual) goto LAB_000884dc;
      matchIndex = 0;
      remaining = tokenLength;
      do {
        matchIndex = matchIndex + 1;
        remaining = remaining + -1;
        if (remaining == 0) {
          compareResult = 0;
          goto LAB_0008855c;
        }
        compareResult = (uint)tokenText[matchIndex] - (int)(char)(PTR_s_1D_001e9158)[mid * 3][matchIndex];
        isEqual = false;
      } while (compareResult == 0);
    }
    if (compareResult < 1) {
      if (isEqual) {
LAB_0008855c:
        if ((PTR_s_1D_001e9158)[mid * 3][matchIndex] == '\0') {
          *(undefined4 *)(parser + 0x14) = *(undefined4 *)(&UNK_001e915c + mid * 0xc);
          *(undefined4 *)(parser + 0x18) = *(undefined4 *)(&UNK_001e9160 + mid * 0xc);
          return;
        }
      }
      high = mid + -1;
    }
    else {
      low = mid + 1;
    }
    if (high < low) {
      *(undefined4 *)(parser + 0x18) = 0;
      *(undefined4 *)(parser + 0x14) = 0;
      return;
    }
  } while( true );
}

/* arbLexNumber @ 0x885b0 (860 bytes) */
int arbLexNumber(parser)
  int parser;
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
  pbVar6 = *(byte **)(parser + 0xc);
  bVar1 = *pbVar6;
  dVar10 = DOUBLE_001aa228;
  while ((bVar1 - 0x30 & 0xff) < 10) {
    pbVar6 = pbVar6 + 1;
    *(byte **)(parser + 0xc) = pbVar6;
    dVar10 = dVar10 * dVar3 + ((double)CONCAT44(0x43300000,bVar1 - 0x30 ^ 0x80000000) - dVar9);
    bVar1 = *pbVar6;
  }
  if ((bVar1 == 0x2e) && (pbVar7 = pbVar6 + 1, pbVar6[1] != 0x2e)) {
    *(byte **)(parser + 0xc) = pbVar7;
    dVar4 = DOUBLE_001aa220;
    dVar3 = DOUBLE_001aa1e0;
    bVar1 = pbVar6[1];
    dVar9 = DOUBLE_001aa220;
    while ((bVar1 - 0x30 & 0xff) < 10) {
      pbVar7 = pbVar7 + 1;
      *(byte **)(parser + 0xc) = pbVar7;
      dVar10 = dVar9 * ((double)CONCAT44(0x43300000,bVar1 - 0x30 ^ 0x80000000) - dVar3) + dVar10;
      dVar9 = dVar9 * dVar4;
      bVar1 = *pbVar7;
    }
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  pbVar6 = *(byte **)(parser + 0xc);
  if ((*pbVar6 != 0x45) && (*pbVar6 != 0x65)) goto LAB_0008886c;
  *(byte **)(parser + 0xc) = pbVar6 + 1;
  if (pbVar6[1] == 0x2d) {
    bVar2 = true;
    *(byte **)(parser + 0xc) = pbVar6 + 2;
  }
  else {
    bVar2 = false;
    if (pbVar6[1] == 0x2b) {
      *(byte **)(parser + 0xc) = pbVar6 + 2;
    }
  }
  pbVar6 = *(byte **)(parser + 0xc);
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
      *(byte **)(parser + 0xc) = pbVar6;
      uVar8 = (uint)*pbVar6;
    } while ((uVar8 - 0x30 & 0xff) < 10);
    dVar9 = DOUBLE_001aa200;
    if (0 < iVar5) {
      do {
        dVar9 = dVar9 * DOUBLE_001aa238;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      pbVar6 = *(byte **)(parser + 0xc);
    }
  }
  else {
    ((int (*)())arbSetError)(parser,"Invalid scientific notation.");
    pbVar6 = *(byte **)(parser + 0xc);
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
    ((int (*)())arbSetError)(parser,"invalid suffix on number");
  }
  *(double *)(parser + 0x1c) = dVar10;
  *(int *)(parser + 0x18) = (int)GH_F2U((float)(dVar10));
  if ((bVar2) && (dVar10 == (double)CONCAT44(0x43300000,(int)dVar10) - DOUBLE_001aa250)) {
    *(undefined4 *)(parser + 0x14) = 0xf;
  }
  else {
    *(undefined4 *)(parser + 0x14) = 0x10;
  }
  return;
}

/* arbNextToken @ 0x88920 (892 bytes) */
int arbNextToken(parser)
  int parser;
{
  char ch;
  bool sawCarriageReturn;
  bool sawNewline;
  bool inComment;
  undefined1 *sourceEnd;
  int remaining;
  undefined1 *cursor;
  
  cursor = *(undefined1 **)(parser + 0xc);
  sourceEnd = *(undefined1 **)(parser + 0x10);
  if (sourceEnd != cursor) {
    sawNewline = false;
    sawCarriageReturn = false;
    inComment = false;
    remaining = (int)sourceEnd - (int)cursor;
    do {
      switch(*cursor) {
      case 9:
      case 0x20:
        if ((!sawCarriageReturn) && (!sawNewline)) goto LAB_00088ae8;
        sawNewline = false;
        sawCarriageReturn = false;
        *(int *)(parser + 0x24) = *(int *)(parser + 0x24) + 1;
        break;
      case 10:
        if (sawNewline) {
          sawNewline = true;
          inComment = false;
          *(int *)(parser + 0x24) = *(int *)(parser + 0x24) + 1;
        }
        else {
          sawNewline = true;
          inComment = false;
        }
        break;
      default:
        if ((sawCarriageReturn) || (sawNewline)) {
          sawNewline = false;
          *(int *)(parser + 0x24) = *(int *)(parser + 0x24) + 1;
        }
        if (!inComment) goto LAB_00088afc;
LAB_00088ae8:
        sawCarriageReturn = false;
        break;
      case 0xd:
        if ((sawCarriageReturn) || (sawNewline)) {
          sawNewline = false;
          sawCarriageReturn = true;
          inComment = false;
          *(int *)(parser + 0x24) = *(int *)(parser + 0x24) + 1;
        }
        else {
          sawCarriageReturn = true;
          inComment = false;
        }
        break;
      case 0x23:
        if ((sawCarriageReturn) || (inComment = true, sawNewline)) {
          sawNewline = false;
          sawCarriageReturn = false;
          inComment = true;
          *(int *)(parser + 0x24) = *(int *)(parser + 0x24) + 1;
        }
      }
      remaining = remaining + -1;
      cursor = cursor + 1;
      *(undefined1 **)(parser + 0xc) = cursor;
    } while (remaining != 0);
  }
LAB_00088afc:
  if (cursor < sourceEnd) {
    *(undefined1 **)(parser + 8) = cursor;
    switch(*cursor) {
    case 0x2b:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x19;
      break;
    case 0x2c:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x13;
      break;
    case 0x2d:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x1a;
      break;
    case 0x2e:
      if (cursor[1] == '.') {
        *(undefined1 **)(parser + 0xc) = cursor + 2;
        *(undefined4 *)(parser + 0x14) = 0x12;
      }
      else {
        if ((byte)(cursor[1] - 0x30) < 10) goto switchD_00088b48_caseD_30;
        *(undefined1 **)(parser + 0xc) = cursor + 1;
        *(undefined4 *)(parser + 0x14) = 0x11;
      }
      break;
    default:
      ((int (*)())arbSetError)(parser,"invalid character");
      return;
    case 0x31:
    case 0x32:
    case 0x33:
      if (cursor[1] == 'D') {
        do {
          do {
            sourceEnd = cursor + 1;
            *(undefined1 **)(parser + 0xc) = sourceEnd;
            ch = cursor[1];
            cursor = sourceEnd;
          } while ((byte)(ch + 0xbfU) < 0x1a);
        } while ((((byte)(ch + 0x9fU) < 0x1a) || ((byte)(ch - 0x30U) < 10)) || (ch == '_'))
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
      ((int (*)())arbLexNumber)(parser);
      return;
    case 0x3b:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x14;
      break;
    case 0x3d:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x1b;
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
          sourceEnd = cursor + 1;
          *(undefined1 **)(parser + 0xc) = sourceEnd;
          ch = cursor[1];
          cursor = sourceEnd;
        } while ((byte)(ch + 0xbfU) < 0x1a);
      } while ((((byte)(ch + 0x9fU) < 0x1a) || ((byte)(ch - 0x30U) < 10)) || (ch == '_'));
LAB_00088d48:
      ((int (*)())arbfpLookupKeyword)(parser);
      return;
    case 0x5b:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x15;
      break;
    case 0x5d:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x16;
      break;
    case 0x7b:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x17;
      break;
    case 0x7d:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x18;
    }
  }
  else {
    *(undefined4 *)(parser + 0x14) = 0x1c;
  }
  return;
}

/* arbSetError @ 0x88e70 (112 bytes) */
int arbSetError(parser, message)
  undefined4 *parser;
  undefined4 message;
{
  if ((int)parser[10] < 0) {
    parser[0xc] = message;
    parser[0xb] = parser[9];
    parser[10] = parser[2] - parser[1];
  }
  parser[3] = parser[4];
  ((int (*)())arbNextToken)(parser);
  *(undefined4 *)*parser = 0x502;
  return;
}

/* arbErrorOutOfMemory @ 0x88ee0 (28 bytes) */
int arbErrorOutOfMemory(parser)
  undefined4 parser;
{
  return ((int (*)())arbSetError)(parser,"out of memory");
}

/* arbAllocVariable @ 0x88f00 (184 bytes) */
int arbAllocVariable(parser)
  int *parser;
{
  undefined4 *variable;
  
  variable = (undefined4 *)(**(code **)(*parser + 0xc))(0x2c);
  if (variable == (undefined4 *)0x0) {
    ((int (*)())arbErrorOutOfMemory)(parser);
  }
  else {
    variable[5] = variable + 6;
    variable[10] = 0;
    variable[6] = 4;
    variable[2] = 0;
    variable[8] = 0x36;
    variable[1] = 0;
    *variable = 0;
    variable[3] = 0;
    variable[4] = 0;
    variable[7] = 0;
    variable[9] = 0;
    if (parser[0x11] == 0) {
      parser[0x11] = (int)variable;
    }
    else {
      *(undefined4 **)parser[0x12] = variable;
    }
    parser[0x12] = (int)variable;
  }
  return variable;
}

/* arbParseVariableName @ 0x88fd0 (332 bytes) */
int arbParseVariableName(parser)
  int parser;
{
  int *entry;
  char *tokenText;
  int charIndex;
  int tokenLength;
  int remaining;
  
  tokenText = *(char **)(parser + 8);
  tokenLength = *(int *)(parser + 0xc) - (int)tokenText;
  if (*(int *)(parser + 0x14) == 0) {
    entry = *(int **)(parser + 0x3c);
    if (entry != (int *)0x0) {
      do {
        if (tokenLength == entry[2]) {
          if (tokenLength < 1) {
            if (tokenLength == 0) {
              return entry;
            }
          }
          else if (*tokenText == *(char *)entry[1]) {
            charIndex = 0;
            remaining = tokenLength;
            do {
              charIndex = charIndex + 1;
              remaining = remaining + -1;
              if (remaining == 0) {
                return entry;
              }
            } while (tokenText[charIndex] == ((char *)entry[1])[charIndex]);
          }
        }
        entry = (int *)*entry;
      } while (entry != (int *)0x0);
    }
    entry = *(int **)(parser + 0x4c);
    if (entry != (int *)0x0) {
      do {
        if (tokenLength == entry[2]) {
          if (tokenLength < 1) {
            if (tokenLength == 0) {
LAB_00089104:
              return (int *)entry[3];
            }
          }
          else if (*tokenText == *(char *)entry[1]) {
            charIndex = 0;
            remaining = tokenLength;
            do {
              charIndex = charIndex + 1;
              remaining = remaining + -1;
              if (remaining == 0) goto LAB_00089104;
            } while (tokenText[charIndex] == ((char *)entry[1])[charIndex]);
          }
        }
        entry = (int *)*entry;
      } while (entry != (int *)0x0);
    }
  }
  else {
    ((int (*)())arbSetError)(parser,"invalid variable name");
  }
  return (int *)0x0;
}

/* arbErrorInternal @ 0x89140 (28 bytes) */
int arbErrorInternal(parser)
  undefined4 parser;
{
  return ((int (*)())arbSetError)(parser,"internal error");
}

/* arbExpectToken @ 0x89160 (44 bytes) */
int arbExpectToken(parser, expectedToken)
  int parser;
  int expectedToken;
{
  if (*(int *)(parser + 0x14) == expectedToken) {
    ((int (*)())arbNextToken)(parser);
    return;
  }
  return ((int (*)())arbSetError)(parser,"unexpected token");
}

/* arbComponentLetterToIndex @ 0x89190 (124 bytes) */
int arbComponentLetterToIndex(parser, letter)
  undefined4 parser;
  undefined4 letter;
{
  undefined4 componentIndex;
  
  switch(letter) {
  case 0x61:
  case 0x77:
    componentIndex = 3;
    break;
  case 0x62:
  case 0x7a:
    componentIndex = 2;
    break;
  default:
    ((int (*)())arbSetError)(parser,"invalid component");
  case 0x72:
  case 0x78:
    componentIndex = 0;
    break;
  case 0x67:
  case 0x79:
    componentIndex = 1;
  }
  return componentIndex;
}

/* arbAllocBindingEntry @ 0x89280 (156 bytes) */
int arbAllocBindingEntry(parser, variable)
  undefined4 parser;
  int variable;
{
  undefined4 *element;
  uint used;
  
  element = (undefined4 *)(variable + 0x18);
  if (*(uint *)(variable + 0xc) != 0) {
    used = *(uint *)(variable + 0x10);
    if (used < *(uint *)(variable + 0xc)) {
      *(uint *)(variable + 0x10) = used + 1;
      element = (undefined4 *)(used * 0x14 + *(int *)(variable + 0x14));
    }
    else {
      ((int (*)())arbSetError)(parser,"too many array initializers");
      element = (undefined4 *)(variable + 0x18);
    }
  }
  *element = 4;
  element[4] = 0;
  element[2] = 0x36;
  element[1] = 0;
  element[3] = 0;
  return element;
}

/* arbInternConstant @ 0x89320 (264 bytes) */
int arbInternConstant(parser, constant)
  int *parser;
  float *constant;
{
  float valueX;
  float valueY;
  float valueZ;
  float *entry;
  int constantIndex;
  int foundCount;
  int constantCount;
  int remaining;
  
  constantCount = parser[0x9116];
  foundCount = 0;
  if (constantCount != 0) {
    entry = (float *)(parser + 0x9016);
    constantIndex = 0;
    remaining = constantCount;
    do {
      if ((((*entry == *constant) && (entry[1] == constant[1])) && (entry[2] == constant[2])) &&
         (entry[3] == constant[3])) {
        return constantIndex;
      }
      constantIndex = constantIndex + 1;
      entry = entry + 4;
      remaining = remaining + -1;
      foundCount = constantCount;
    } while (remaining != 0);
  }
  if (foundCount < *(int *)(((unsigned char *)0x000011e4) + *parser)) {
    valueX = *constant;
    valueY = constant[1];
    valueZ = constant[2];
    parser[constantCount * 4 + 0x9019] = (int)GH_F2U((float)(constant[3]));
    parser[constantCount * 4 + 0x9016] = (int)GH_F2U(valueX);
    parser[constantCount * 4 + 0x9017] = (int)GH_F2U(valueY);
    parser[constantCount * 4 + 0x9018] = (int)GH_F2U(valueZ);
    parser[0x9116] = parser[0x9116] + 1;
  }
  else {
    ((int (*)())arbSetError)(parser,"too many constants");
    constantCount = 0;
  }
  return constantCount;
}

/* arbDeclareVariable @ 0x89430 (348 bytes) */
int arbDeclareVariable(parser)
  int *parser;
{
  int keywordOrFound;
  undefined4 *variable;
  
  if (parser[5] == 0) {
    keywordOrFound = parser[6];
    if ((((keywordOrFound == 0xc) || (keywordOrFound == 0x1d)) || (keywordOrFound == 0x20)) ||
       ((keywordOrFound == 0x27 || (keywordOrFound == 0x2a)))) {
      variable = (undefined4 *)0x0;
      ((int (*)())arbSetError)(parser,"reserved variable name");
    }
    else {
      keywordOrFound = ((int (*)())arbParseVariableName)(parser);
      if (keywordOrFound == 0) {
        variable = (undefined4 *)(**(code **)(*parser + 0xc))(0x2c);
        if (variable == (undefined4 *)0x0) {
          ((int (*)())arbErrorOutOfMemory)(parser);
        }
        else {
          variable[2] = parser[3] - parser[2];
          keywordOrFound = parser[2];
          variable[5] = variable + 6;
          variable[6] = 4;
          variable[8] = 0x36;
          variable[10] = 0;
          *variable = 0;
          variable[3] = 0;
          variable[4] = 0;
          variable[1] = keywordOrFound;
          variable[7] = 0;
          variable[9] = 0;
          if (parser[0xf] == 0) {
            parser[0xf] = (int)variable;
          }
          else {
            *(undefined4 **)parser[0x10] = variable;
          }
          parser[0x10] = (int)variable;
        }
      }
      else {
        variable = (undefined4 *)0x0;
        ((int (*)())arbSetError)(parser,"redeclared variable name");
      }
    }
  }
  else {
    ((int (*)())arbErrorInternal)(parser);
    variable = (undefined4 *)0x0;
  }
  ((int (*)())arbNextToken)(parser);
  return variable;
}

/* arbParseResultBinding @ 0x895b0 (364 bytes) */
int arbParseResultBinding(parser, binding)
  int *parser;
  undefined4 *binding;
{
  int colorIndex;
  
  if ((parser[5] != 0) || (parser[6] != 0x20)) {
    ((int (*)())arbSetError)(parser,"invalid result binding");
  }
  ((int (*)())arbNextToken)(parser);
  ((int (*)())arbExpectToken)(parser,0x11);
  if (parser[5] == 0) {
    binding[2] = 0x35;
    *binding = 3;
    if (parser[6] == 4) {
      ((int (*)())arbNextToken)(parser);
      binding[1] = 0;
      if (*(char *)((int)parser + 0x3a) == '\0') {
        binding[3] = 0;
      }
      else {
        colorIndex = 0;
        if (parser[5] == 0x15) {
          ((int (*)())arbNextToken)(parser);
          if (((parser[5] == 0xf) && (colorIndex = parser[6], -1 < colorIndex)) &&
             (colorIndex < (int)(uint)(byte)((unsigned char *)0x000013b3)[*parser])) {
            ((int (*)())arbNextToken)(parser);
          }
          else {
            colorIndex = 0;
            ((int (*)())arbSetError)(parser,"invalid output color");
          }
          ((int (*)())arbExpectToken)(parser,0x16);
        }
        binding[3] = colorIndex;
      }
    }
    else {
      if (parser[6] != 5) goto LAB_00089638;
      ((int (*)())arbNextToken)(parser);
      binding[1] = 1;
    }
    return;
  }
LAB_00089638:
  ((int (*)())arbSetError)(parser,"invalid result binding");
  return;
}

/* arbParseOptionalSign @ 0x89740 (88 bytes) */
int arbParseOptionalSign(parser)
  int parser;
{
  undefined4 sign;
  
  if (*(int *)(parser + 0x14) == 0x19) {
    ((int (*)())arbNextToken)(parser);
    sign = 1;
  }
  else {
    sign = 1;
    if (*(int *)(parser + 0x14) == 0x1a) {
      ((int (*)())arbNextToken)(parser);
      sign = 0xffffffff;
    }
  }
  return sign;
}

/* arbParseFloatConstant @ 0x897b0 (164 bytes) */
double arbParseFloatConstant(int parser)
{
  uint sign;
  double value;
  double signAsDouble;
  
  sign = ((int (*)())arbParseOptionalSign)(parser);
  value = DOUBLE_001aa228;
  signAsDouble = (double)CONCAT44(0x43300000,sign ^ 0x80000000) - DOUBLE_001aa1e0;
  if (*(int *)(parser + 0x14) - 0xfU < 2) {
    value = *(double *)(parser + 0x1c);
    ((int (*)())arbNextToken)(parser);
  }
  else {
    ((int (*)())arbSetError)(parser,"invalid constant");
  }
  return value * signAsDouble;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_000837b0");
asm(".set FUN_000837b0, _FUN_000837b0");
asm(".globl FUN_00083870");
asm(".set FUN_00083870, _FUN_00083870");
asm(".globl FUN_00083e10");
asm(".set FUN_00083e10, _FUN_00083e10");
asm(".globl FUN_000840d0");
asm(".set FUN_000840d0, _FUN_000840d0");
asm(".globl FUN_00084300");
asm(".set FUN_00084300, _FUN_00084300");
asm(".globl FUN_000844e0");
asm(".set FUN_000844e0, _FUN_000844e0");
asm(".globl FUN_00084710");
asm(".set FUN_00084710, _FUN_00084710");
asm(".globl FUN_00084940");
asm(".set FUN_00084940, _FUN_00084940");
asm(".globl FUN_00084c00");
asm(".set FUN_00084c00, _FUN_00084c00");
asm(".globl FUN_00084ec0");
asm(".set FUN_00084ec0, _FUN_00084ec0");
asm(".globl FUN_00085180");
asm(".set FUN_00085180, _FUN_00085180");
asm(".globl FUN_000853b0");
asm(".set FUN_000853b0, _FUN_000853b0");
asm(".globl FUN_000855e0");
asm(".set FUN_000855e0, _FUN_000855e0");
asm(".globl FUN_00085810");
asm(".set FUN_00085810, _FUN_00085810");
asm(".globl FUN_00085a40");
asm(".set FUN_00085a40, _FUN_00085a40");
asm(".globl FUN_00085bf0");
asm(".set FUN_00085bf0, _FUN_00085bf0");
asm(".globl FUN_00085da0");
asm(".set FUN_00085da0, _FUN_00085da0");
asm(".globl FUN_00085f50");
asm(".set FUN_00085f50, _FUN_00085f50");
asm(".globl FUN_00086100");
asm(".set FUN_00086100, _FUN_00086100");
asm(".globl FUN_000862b0");
asm(".set FUN_000862b0, _FUN_000862b0");
asm(".globl FUN_000864e0");
asm(".set FUN_000864e0, _FUN_000864e0");
asm(".globl FUN_00087960");
asm(".set FUN_00087960, _FUN_00087960");
asm(".globl FUN_000879e0");
asm(".set FUN_000879e0, _noop_879e0");
asm(".globl FUN_00087cd0");
asm(".set FUN_00087cd0, _FUN_00087cd0");
asm(".globl FUN_00087da0");
asm(".set FUN_00087da0, _FUN_00087da0");
asm(".globl FUN_00087e60");
asm(".set FUN_00087e60, _FUN_00087e60");
asm(".globl FUN_00087e80");
asm(".set FUN_00087e80, _FUN_00087e80");
asm(".globl FUN_00088190");
asm(".set FUN_00088190, _FUN_00088190");
