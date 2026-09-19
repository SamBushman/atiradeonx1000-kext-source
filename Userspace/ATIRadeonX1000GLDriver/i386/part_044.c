#include "decls.h"

/* FUN_001582e0 @ 0x1582e0 (2537 bytes) */
int FUN_001582e0(param_1, param_2)
  void *param_1;
  int param_2;
{
  float fVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char cVar8;
  byte bVar9;
  byte bVar10;
  char cVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  undefined4 uVar16;
  uint uVar17;
  void *pvVar18;
  byte bVar19;
  byte bVar20;
  int iVar21;
  int iVar22;
  bool bVar23;
  int local_f8;
  int local_f4;
  int local_e8;
  int local_c8;
  int local_c0;
  uint local_b8;
  int *local_b4;
  int *local_68;
  int *local_64;
  undefined4 local_44;
  int local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar4 = *(int *)(param_2 + 8);
  cVar8 = FUN_000e1402(iVar4,0x2a);
  if (((cVar8 == '\0') && (param_1 != (void *)0x0)) &&
     (*(int *)(*(int *)((int)param_1 + 0x88) + 8) == 0x13)) {
    iVar12 = FUN_0010b0f4(param_1,0);
    local_20 = *(undefined4 *)(iVar12 + 0x10);
    local_c8 = 1;
    local_f4 = 0x18;
    local_f8 = 0x98;
    do {
      iVar12 = FUN_0010b180(param_1,local_c8);
      if (((*(int *)(*(int *)(iVar12 + 0x88) + 8) == 0x12) && (*(char *)(iVar12 + 0x120) == '\0'))
         && ((*(int *)(iVar12 + 0x124) == 0 &&
             (((*(byte *)(local_f4 + 0xa0 + (int)param_1) & 2) == 0 &&
              ((*(byte *)(iVar12 + 0x15) & 2) == 0)))))) {
        iVar13 = FUN_0010b0f4(param_1,local_c8);
        local_24 = *(undefined4 *)(iVar13 + 0x10);
        local_c0 = 1;
        local_e8 = 0x98;
        do {
          iVar13 = FUN_0010b0f4(iVar12,local_c0);
          local_28 = *(undefined4 *)(iVar13 + 0x10);
          iVar13 = FUN_0010b0f4(iVar12,0);
          local_2c = *(undefined4 *)(iVar13 + 0x10);
          iVar13 = FUN_0010b180(iVar12,local_c0);
          bVar23 = true;
          local_b8 = 0;
          iVar21 = 1;
          do {
            if (*(char *)((int)&local_24 + iVar21 + 3) != '\0') goto LAB_001584e6;
            uVar14 = (uint)*(byte *)((int)&local_28 + iVar21 + 3);
            bVar2 = *(byte *)((int)&local_28 + uVar14);
            if ((*(char *)((int)&local_2c + uVar14) == '\0') &&
               (((int)*(char *)(iVar13 + 0x15c) >> (bVar2 & 0x1f) & 1U) != 0)) {
              fVar1 = *(float *)(iVar13 + 0x20 + (uint)bVar2 * 0x18);
              if ((fVar1 != FLOAT_001c5bdc) || (NAN(fVar1) || NAN(FLOAT_001c5bdc))) {
                if (((fVar1 != FLOAT_001c5ba4) || (NAN(fVar1) || NAN(FLOAT_001c5ba4))) ||
                   ((int)local_b8 < 0)) goto LAB_001584df;
                local_b8 = 1;
              }
              else {
                if (0 < (int)local_b8) goto LAB_001584df;
                local_b8 = 0xffffffff;
              }
            }
            else {
LAB_001584df:
              bVar23 = false;
            }
LAB_001584e6:
            iVar21 = iVar21 + 1;
          } while (iVar21 != 5);
          if ((bVar23) &&
             ((cVar8 = (**(code **)(**(int **)(iVar4 + 0x54) + 0x88))(*(int **)(iVar4 + 0x54)),
              cVar8 != '\0' || ((*(byte *)(iVar13 + 0x20 + local_e8) & 2) == 0)))) {
            local_b4 = *(int **)((int)param_1 + 4);
            iVar13 = FUN_00109e42(param_1,param_2);
            uVar3 = *(undefined1 *)((int)param_1 + 0x120);
            uVar5 = *(undefined4 *)((int)param_1 + 0x124);
            iVar21 = (local_c8 == 1) + 1;
            local_64 = (int *)FUN_0010b180(param_1,iVar21);
            iVar15 = FUN_0010b0f4(param_1,iVar21);
            uVar6 = *(undefined4 *)(iVar15 + 0x10);
            uVar14 = *(uint *)((int)param_1 + iVar21 * 0x18 + 0xa0);
            bVar19 = (byte)uVar14 & 1;
            bVar9 = (byte)(uVar14 >> 1) & 1;
            iVar15 = FUN_0010b0f4(param_1,local_c8);
            uVar16 = *(undefined4 *)(iVar15 + 0x10);
            bVar20 = *(byte *)((int)param_1 + local_f8 + 0x20) & 1;
            iVar22 = (local_c0 == 1) + 1;
            local_68 = (int *)FUN_0010b180(iVar12,iVar22);
            iVar15 = FUN_0010b0f4(iVar12,iVar22);
            uVar14 = *(uint *)(iVar12 + 0xa0 + iVar22 * 0x18);
            bVar10 = (byte)(uVar14 >> 1) & 1;
            uVar16 = FUN_000f5610(*(undefined4 *)(iVar15 + 0x10),uVar16);
            bVar2 = *(byte *)(local_e8 + 0x20 + iVar12);
            local_44 = 0;
            local_40 = 0;
            local_30 = 0;
            uVar17 = *(uint *)((int)param_1 + 0x14);
            if ((uVar17 & 0x200) != 0) {
              FUN_0010a980(param_1,&local_44);
              uVar17 = *(uint *)((int)param_1 + 0x14);
            }
            uVar7 = *(undefined4 *)((int)param_1 + 0x98);
            pvVar18 = (void *)FUN_0010a17a(0x14,*(undefined4 *)(param_2 + 8));
            if ((uVar17 & 2) != 0) {
              *(uint *)((int)pvVar18 + 0x14) = *(uint *)((int)pvVar18 + 0x14) | 2;
            }
            *(undefined4 *)((int)pvVar18 + 0xc) = *(undefined4 *)((int)param_1 + 0xc);
            *(undefined4 *)((int)pvVar18 + 0x94) = *(undefined4 *)((int)pvVar18 + 0x14c);
            *(undefined4 *)((int)pvVar18 + 0x98) = uVar7;
            *(undefined4 *)((int)pvVar18 + 0x9c) = local_20;
            *(undefined1 *)((int)pvVar18 + 0x120) = uVar3;
            *(undefined4 *)((int)pvVar18 + 0x124) = uVar5;
            FUN_0010ba02(pvVar18,iVar21,local_64,0,iVar4);
            iVar15 = FUN_0010b0f4(pvVar18,iVar21);
            *(undefined4 *)(iVar15 + 0x10) = uVar6;
            iVar21 = (int)pvVar18 + iVar21 * 0x18 + 0x8c;
            FUN_00109c0e(iVar21,2,bVar9);
            FUN_00109c0e(iVar21,1,bVar19);
            iVar21 = *(int *)(param_2 + 0x46c);
            cVar8 = (**(code **)(*local_68 + 0x5c))(local_68);
            if (cVar8 != '\0') {
              local_68 = (int *)FUN_0010a1c2(local_68,*(undefined4 *)(param_2 + 8),0);
              iVar15 = local_68[0x53];
              iVar22 = FUN_0010b0f4(local_68,0);
              *(int *)(iVar22 + 8) = iVar15;
              local_68[0x58] = iVar21;
            }
            bVar23 = bVar20 != ((byte)uVar14 & 1);
            cVar8 = FUN_0010bc1e(pvVar18,local_c8,local_68,bVar10,bVar23,iVar4);
            iVar15 = FUN_0010b0f4(pvVar18,local_c8);
            *(undefined4 *)(iVar15 + 0x10) = uVar16;
            iVar15 = local_f4 + 0x8c + (int)pvVar18;
            FUN_00109c0e(iVar15,2,bVar10);
            FUN_00109c0e(iVar15,1,bVar23);
            cVar11 = (**(code **)(*local_64 + 0x5c))(local_64);
            if (cVar11 != '\0') {
              local_64 = (int *)FUN_0010a1c2(local_64,*(undefined4 *)(param_2 + 8),0);
              iVar15 = local_64[0x53];
              iVar22 = FUN_0010b0f4(local_64,0);
              *(int *)(iVar22 + 8) = iVar15;
              local_64[0x58] = iVar21;
            }
            bVar23 = ((uint)(bVar2 & 1) != local_b8 >> 0x1f) != (bVar19 != bVar20);
            cVar11 = FUN_0010bc1e(pvVar18,3,local_64,bVar9,bVar23,iVar4);
            iVar15 = FUN_0010b0f4(pvVar18,3);
            *(undefined4 *)(iVar15 + 0x10) = uVar6;
            FUN_00109c0e((int)pvVar18 + 0xd4,2,bVar9);
            FUN_00109c0e((int)pvVar18 + 0xd4,1,bVar23);
            if (local_40 != 0) {
              FUN_0010c568(pvVar18,&local_44,0,iVar4);
            }
            *(int *)((int)pvVar18 + 0x160) = iVar13 + *(int *)(param_2 + 0x46c);
            if (cVar11 != '\0' && cVar8 != '\0') {
              *(int *)(param_2 + 0x1d0) = *(int *)(param_2 + 0x1d0) + 1;
              cVar8 = (**(code **)(*local_68 + 0x5c))(local_68);
              if (cVar8 != '\0') {
                iVar13 = 1;
                while (iVar15 = (**(code **)(*local_68 + 0x14))(local_68), iVar13 <= iVar15) {
                  iVar15 = FUN_0010b180(local_68,iVar13);
                  if (iVar21 < *(int *)(iVar15 + 0x160)) {
                    *(int *)(iVar15 + 0x160) = *(int *)(iVar15 + 0x160) + 1;
                    iVar13 = iVar13 + 1;
                  }
                  else {
                    *(int *)(iVar15 + 0x160) = iVar21 + 1;
                    iVar13 = iVar13 + 1;
                  }
                }
                FUN_000e9596(local_b4[0x56],local_b4,local_68);
                local_b4 = local_68;
              }
              if (*(int *)(param_2 + 0x46c) < local_68[0x58]) {
                local_68[0x58] = local_68[0x58] + 1;
              }
              else {
                local_68[0x58] = *(int *)(param_2 + 0x46c) + 1;
              }
              cVar8 = (**(code **)(*local_64 + 0x5c))(local_64);
              if (cVar8 != '\0') {
                iVar13 = 1;
                while (iVar15 = (**(code **)(*local_64 + 0x14))(local_64), iVar13 <= iVar15) {
                  iVar15 = FUN_0010b180(local_64,iVar13);
                  if (iVar21 < *(int *)(iVar15 + 0x160)) {
                    *(int *)(iVar15 + 0x160) = *(int *)(iVar15 + 0x160) + 1;
                    iVar13 = iVar13 + 1;
                  }
                  else {
                    *(int *)(iVar15 + 0x160) = iVar21 + 1;
                    iVar13 = iVar13 + 1;
                  }
                }
                FUN_000e9596(local_b4[0x56],local_b4,local_64);
                local_b4 = local_64;
              }
              if (*(int *)(param_2 + 0x46c) < local_64[0x58]) {
                local_64[0x58] = local_64[0x58] + 1;
              }
              else {
                local_64[0x58] = *(int *)(param_2 + 0x46c) + 1;
              }
              FUN_001a7d72(param_1);
              _memcpy(param_1,pvVar18,0x164);
              FUN_000e9596(local_b4[0x56],local_b4,param_1);
              FUN_0010b3fe(iVar12,iVar4);
              return 1;
            }
          }
          local_c0 = local_c0 + 1;
          local_e8 = local_e8 + 0x18;
        } while (local_c0 != 3);
      }
      local_c8 = local_c8 + 1;
      local_f8 = local_f8 + 0x18;
      local_f4 = local_f4 + 0x18;
    } while (local_c8 != 3);
  }
  return 0;
}

/* FUN_00158cca @ 0x158cca (158 bytes) */
int FUN_00158cca(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  char cStack_25;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  local_20[0] = DAT_001cc5a4;
  iVar3 = 0;
  iVar2 = 1;
  do {
    iVar1 = FUN_0010b0f4(param_1,param_2);
    local_24 = *(undefined4 *)(iVar1 + 0x10);
    if ((&cStack_25)[iVar2] != '\x04') {
      *(char *)((int)local_20 + iVar3) = (&cStack_25)[iVar2];
      iVar3 = iVar3 + 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 5);
  iVar2 = 1;
  do {
    iVar1 = FUN_0010b0f4(param_3,param_4);
    local_24 = *(undefined4 *)(iVar1 + 0x10);
    if ((iVar3 < 4) && ((&cStack_25)[iVar2] != '\x04')) {
      *(char *)((int)local_20 + iVar3) = (&cStack_25)[iVar2];
      iVar3 = iVar3 + 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 5);
  return local_20[0];
}

/* FUN_00158d68 @ 0x158d68 (1320 bytes) */
int FUN_00158d68(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
  undefined4 *param_5;
  char *param_6;
{
  undefined1 uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 local_e;
  undefined1 local_d;
  
  local_d = 0;
  local_e = 0;
  cVar2 = FUN_00150d7c(param_1,1,param_2,1,param_3,0,&local_d);
  cVar3 = FUN_00150d7c(param_1,1,param_2,2,param_3,0,&local_d);
  cVar4 = FUN_00150d7c(param_1,2,param_2,2,param_3,0,&local_e);
  cVar5 = FUN_00150d7c(param_1,2,param_2,1,param_3,0,&local_e);
  if ((cVar2 == '\0') || (cVar4 == '\0')) {
    if (cVar3 == '\0') {
      return 0;
    }
    if (cVar5 == '\0') {
      return 0;
    }
    if (cVar2 == '\0') {
      uVar6 = ((int (*)())FUN_00158cca)(param_1,1,param_2,2);
      *param_4 = uVar6;
      uVar6 = ((int (*)())FUN_00158cca)(param_1,2,param_2,1);
      uVar1 = local_d;
      *param_5 = uVar6;
      uVar6 = *(undefined4 *)(param_3 + 8);
      uVar7 = FUN_0010b180(param_1,1);
      cVar3 = FUN_0014fb5a(param_4,uVar7,uVar1,uVar6);
      uVar1 = local_e;
      if (cVar3 == '\0') {
LAB_001590a2:
        uVar6 = ((int (*)())FUN_00158cca)(param_2,1,param_1,2);
        *param_4 = uVar6;
        uVar6 = ((int (*)())FUN_00158cca)(param_2,2,param_1,1);
        uVar1 = local_d;
        *param_5 = uVar6;
        uVar6 = *(undefined4 *)(param_3 + 8);
        uVar7 = FUN_0010b180(param_1,1);
        cVar3 = FUN_0014fb5a(param_4,uVar7,uVar1,uVar6);
        uVar1 = local_e;
        if (cVar3 == '\0') {
          return 0;
        }
        uVar6 = *(undefined4 *)(param_3 + 8);
        uVar7 = FUN_0010b180(param_1,2);
        cVar3 = FUN_0014fb5a(param_5,uVar7,uVar1,uVar6);
        if (cVar3 == '\0') {
          return 0;
        }
      }
      else {
        uVar6 = *(undefined4 *)(param_3 + 8);
        uVar7 = FUN_0010b180(param_1,2);
        cVar3 = FUN_0014fb5a(param_5,uVar7,uVar1,uVar6);
        if (cVar3 == '\0') goto LAB_001590a2;
      }
      FUN_00150d7c(param_1,1,param_2,2,param_3,1,&local_d);
      uVar6 = 1;
      goto LAB_00158f95;
    }
  }
  uVar6 = ((int (*)())FUN_00158cca)(param_1,1,param_2,1);
  *param_4 = uVar6;
  uVar6 = ((int (*)())FUN_00158cca)(param_1,2,param_2,2);
  uVar1 = local_d;
  *param_5 = uVar6;
  uVar6 = *(undefined4 *)(param_3 + 8);
  uVar7 = FUN_0010b180(param_1,1);
  cVar3 = FUN_0014fb5a(param_4,uVar7,uVar1,uVar6);
  uVar1 = local_e;
  if (cVar3 == '\0') {
LAB_001591c3:
    uVar6 = ((int (*)())FUN_00158cca)(param_2,1,param_1,1);
    *param_4 = uVar6;
    uVar6 = ((int (*)())FUN_00158cca)(param_2,2,param_1,2);
    uVar1 = local_d;
    *param_5 = uVar6;
    uVar6 = *(undefined4 *)(param_3 + 8);
    uVar7 = FUN_0010b180(param_1,1);
    cVar3 = FUN_0014fb5a(param_4,uVar7,uVar1,uVar6);
    uVar1 = local_e;
    if (cVar3 == '\0') {
      return 0;
    }
    uVar6 = *(undefined4 *)(param_3 + 8);
    uVar7 = FUN_0010b180(param_1,2);
    cVar3 = FUN_0014fb5a(param_5,uVar7,uVar1,uVar6);
    if (cVar3 == '\0') {
      return 0;
    }
  }
  else {
    uVar6 = *(undefined4 *)(param_3 + 8);
    uVar7 = FUN_0010b180(param_1,2);
    cVar3 = FUN_0014fb5a(param_5,uVar7,uVar1,uVar6);
    if (cVar3 == '\0') goto LAB_001591c3;
  }
  FUN_00150d7c(param_1,1,param_2,1,param_3,1,&local_d);
  uVar6 = 2;
LAB_00158f95:
  FUN_00150d7c(param_1,2,param_2,uVar6,param_3,1,&local_e);
  *param_6 = cVar2;
  return 1;
}

/* FUN_00159290 @ 0x159290 (261 bytes) */
int FUN_00159290(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  cVar1 = (**(code **)(*param_1 + 0x5c))(param_1);
  if (cVar1 != '\0') {
    iVar2 = FUN_0010b0f4(param_2,0);
    uVar3 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = FUN_0010b0f4(param_1,0);
    iVar2 = FUN_000f5892(*(undefined4 *)(iVar2 + 0x10),uVar3);
    param_1[0x27] = iVar2;
    iVar2 = FUN_0010b0f4(param_2,1);
    uVar3 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = FUN_0010b0f4(param_1,1);
    uVar3 = FUN_000f58c0(*(undefined4 *)(iVar2 + 0x10),uVar3);
    iVar2 = FUN_0010b0f4(param_1,1);
    *(undefined4 *)(iVar2 + 0x10) = uVar3;
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar2 == 2) {
      iVar2 = FUN_0010b0f4(param_2,2);
      uVar3 = *(undefined4 *)(iVar2 + 0x10);
      iVar2 = FUN_0010b0f4(param_1,2);
      uVar3 = FUN_000f58c0(*(undefined4 *)(iVar2 + 0x10),uVar3);
      iVar2 = FUN_0010b0f4(param_1,2);
      *(undefined4 *)(iVar2 + 0x10) = uVar3;
      return;
    }
  }
  return;
}

/* FUN_00159396 @ 0x159396 (1133 bytes) */
int FUN_00159396(param_1, param_2)
  int *param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  char local_1d [13];
  
  if (((((param_1 != (int *)0x0) && (*(int *)(param_1[0x22] + 8) == 0x14)) &&
       ((uint)*(byte *)(param_1 + 3) + (uint)*(byte *)((int)param_1 + 0xd) +
        (uint)*(byte *)((int)param_1 + 0xe) + (uint)*(byte *)((int)param_1 + 0xf) == 1)) &&
      (((param_1[0x3a] & 1U) == 0 && ((param_1[0x3a] & 2U) == 0)))) &&
     (iVar2 = (**(code **)(*param_1 + 0x14))(param_1),
     param_1[0x21] <= (int)((iVar2 + 1) - (uint)((param_1[5] & 0x200U) == 0)))) {
    iVar2 = FUN_0010b180(param_1,3);
    if (((*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x13) ||
        (*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x36)) &&
       (((uint)*(byte *)(iVar2 + 0xc) + (uint)*(byte *)(iVar2 + 0xd) + (uint)*(byte *)(iVar2 + 0xe)
         + (uint)*(byte *)(iVar2 + 0xf) == 1 &&
        ((*(char *)(iVar2 + 0x120) == '\0' && (*(int *)(iVar2 + 0x124) == 0)))))) {
      local_1d[0] = '\0';
      cVar1 = ((int (*)())FUN_00158d68)(param_1,iVar2,param_2,&local_24,&local_28,local_1d);
      if (cVar1 != '\0') {
        *(int *)(param_2 + 0x1e0) = *(int *)(param_2 + 0x1e0) + 1;
        pvVar3 = (void *)FUN_0010a17a(0x1e,*(undefined4 *)(param_2 + 8));
        iVar4 = FUN_0010b0f4(pvVar3,1);
        *(undefined4 *)(iVar4 + 0x10) = local_24;
        iVar4 = FUN_0010b0f4(pvVar3,2);
        *(undefined4 *)(iVar4 + 0x10) = local_28;
        if (local_1d[0] == '\0') {
          uVar5 = FUN_0010b180(iVar2,2);
          uVar6 = FUN_0010b180(param_1,1);
          ((int (*)())FUN_00159290)(uVar6,uVar5);
          uVar5 = 1;
        }
        else {
          uVar5 = FUN_0010b180(iVar2,1);
          uVar6 = FUN_0010b180(param_1,1);
          ((int (*)())FUN_00159290)(uVar6,uVar5);
          uVar5 = 2;
        }
        uVar5 = FUN_0010b180(iVar2,uVar5);
        uVar6 = FUN_0010b180(param_1,2);
        ((int (*)())FUN_00159290)(uVar6,uVar5);
        uVar5 = *(undefined4 *)(param_2 + 8);
        uVar6 = FUN_0010b180(param_1,1);
        FUN_0010ba02(pvVar3,1,uVar6,0,uVar5);
        uVar5 = *(undefined4 *)(param_2 + 8);
        uVar6 = FUN_0010b180(param_1,2);
        FUN_0010ba02(pvVar3,2,uVar6,0,uVar5);
        FUN_00109c0e((int)pvVar3 + 0xa4,1,*(byte *)(param_1 + 0x2e) & 1);
        FUN_00109c0e((int)pvVar3 + 0xbc,1,*(byte *)(param_1 + 0x34) & 1);
        FUN_00109c0e((int)pvVar3 + 0xa4,2,(uint)param_1[0x2e] >> 1 & 1);
        FUN_00109c0e((int)pvVar3 + 0xbc,2,(uint)param_1[0x34] >> 1 & 1);
        FUN_000fa0d2(pvVar3,param_2,3,0,0,0,0);
        iVar4 = param_1[0x26];
        *(undefined4 *)((int)pvVar3 + 0x94) = *(undefined4 *)((int)pvVar3 + 0x14c);
        *(int *)((int)pvVar3 + 0x98) = iVar4;
        local_34 = 0;
        local_30 = 0;
        local_2c = 0;
        FUN_00109d1c(param_1,&local_34,0xffffffff);
        FUN_00109d48(pvVar3,&local_34);
        iVar4 = FUN_0010b0f4(param_1,0);
        *(undefined4 *)((int)pvVar3 + 0x9c) = *(undefined4 *)(iVar4 + 0x10);
        if ((*(byte *)((int)param_1 + 0x15) & 2) != 0) {
          local_4c = 0;
          local_48 = 0;
          local_38 = 0;
          FUN_0010a980(param_1,&local_4c);
          FUN_0010c568(pvVar3,&local_4c,0,*(undefined4 *)(param_2 + 8));
        }
        *(int *)((int)pvVar3 + 0x124) = param_1[0x49];
        *(char *)((int)pvVar3 + 0x120) = (char)param_1[0x48];
        *(int *)((int)pvVar3 + 0xc) = param_1[3];
        iVar4 = param_1[1];
        FUN_001a7d72(param_1);
        _memcpy(param_1,pvVar3,0x164);
        FUN_000e9596(*(undefined4 *)(iVar4 + 0x158),iVar4,param_1);
        FUN_0010b3fe(iVar2,*(undefined4 *)(param_2 + 8));
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00159804 @ 0x159804 (1134 bytes) */
int FUN_00159804(param_1, param_2)
  void *param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int local_4c;
  float local_48;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  char local_1d [13];
  
  if (((((param_1 != (void *)0x0) && (*(int *)(*(int *)((int)param_1 + 0x88) + 8) == 0x14)) &&
       ((uint)*(byte *)((int)param_1 + 0xc) + (uint)*(byte *)((int)param_1 + 0xd) +
        (uint)*(byte *)((int)param_1 + 0xe) + (uint)*(byte *)((int)param_1 + 0xf) == 1)) &&
      ((((*(uint *)((int)param_1 + 0xe8) & 1) == 0 && ((*(uint *)((int)param_1 + 0xe8) & 2) == 0))
       && ((iVar2 = FUN_0010b180(param_1,3), *(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x1e &&
           (((uint)*(byte *)(iVar2 + 0xc) + (uint)*(byte *)(iVar2 + 0xd) +
             (uint)*(byte *)(iVar2 + 0xe) + (uint)*(byte *)(iVar2 + 0xf) == 1 &&
            (*(char *)(iVar2 + 0x120) == '\0')))))))) && (*(int *)(iVar2 + 0x124) == 0)) {
    iVar3 = FUN_0010b0f4(iVar2,0);
    cVar1 = FUN_000f7e7e(iVar2,3,*(undefined4 *)(iVar3 + 0x10),&local_4c);
    if ((((cVar1 != '\0') && (local_48 == 0.0)) && (!NAN(local_48))) && (local_4c == 2)) {
      local_1d[0] = '\0';
      cVar1 = ((int (*)())FUN_00158d68)(param_1,iVar2,param_2,&local_24,&local_28,local_1d);
      if (cVar1 != '\0') {
        pvVar4 = (void *)FUN_0010a17a(0x1c,*(undefined4 *)(param_2 + 8));
        iVar3 = FUN_0010b0f4(pvVar4,1);
        *(undefined4 *)(iVar3 + 0x10) = local_24;
        iVar3 = FUN_0010b0f4(pvVar4,2);
        *(undefined4 *)(iVar3 + 0x10) = local_28;
        if (local_1d[0] == '\0') {
          uVar5 = FUN_0010b180(iVar2,2);
          uVar6 = FUN_0010b180(param_1,1);
          ((int (*)())FUN_00159290)(uVar6,uVar5);
          uVar5 = 1;
        }
        else {
          uVar5 = FUN_0010b180(iVar2,1);
          uVar6 = FUN_0010b180(param_1,1);
          ((int (*)())FUN_00159290)(uVar6,uVar5);
          uVar5 = 2;
        }
        uVar5 = FUN_0010b180(iVar2,uVar5);
        uVar6 = FUN_0010b180(param_1,2);
        ((int (*)())FUN_00159290)(uVar6,uVar5);
        uVar5 = *(undefined4 *)(param_2 + 8);
        uVar6 = FUN_0010b180(param_1,1);
        FUN_0010ba02(pvVar4,1,uVar6,0,uVar5);
        uVar5 = *(undefined4 *)(param_2 + 8);
        uVar6 = FUN_0010b180(param_1,2);
        FUN_0010ba02(pvVar4,2,uVar6,0,uVar5);
        FUN_00109c0e((int)pvVar4 + 0xa4,1,*(byte *)((int)param_1 + 0xb8) & 1);
        FUN_00109c0e((int)pvVar4 + 0xbc,1,*(byte *)((int)param_1 + 0xd0) & 1);
        FUN_00109c0e((int)pvVar4 + 0xa4,2,*(uint *)((int)param_1 + 0xb8) >> 1 & 1);
        FUN_00109c0e((int)pvVar4 + 0xbc,2,*(uint *)((int)param_1 + 0xd0) >> 1 & 1);
        uVar5 = *(undefined4 *)((int)param_1 + 0x98);
        *(undefined4 *)((int)pvVar4 + 0x94) = *(undefined4 *)((int)pvVar4 + 0x14c);
        *(undefined4 *)((int)pvVar4 + 0x98) = uVar5;
        local_34 = 0;
        local_30 = 0;
        local_2c = 0;
        FUN_00109d1c(param_1,&local_34,0xffffffff);
        FUN_00109d48(pvVar4,&local_34);
        *(undefined4 *)((int)pvVar4 + 0x158) = *(undefined4 *)((int)param_1 + 0x158);
        iVar3 = FUN_0010b0f4(param_1,0);
        *(undefined4 *)((int)pvVar4 + 0x9c) = *(undefined4 *)(iVar3 + 0x10);
        if ((*(byte *)((int)param_1 + 0x15) & 2) != 0) {
          uVar5 = *(undefined4 *)(param_2 + 8);
          uVar6 = FUN_0010b180(param_1,*(undefined4 *)((int)param_1 + 0x84));
          FUN_0010c18e(pvVar4,uVar6,0,uVar5);
        }
        *(undefined4 *)((int)pvVar4 + 0x124) = *(undefined4 *)((int)param_1 + 0x124);
        *(undefined1 *)((int)pvVar4 + 0x120) = *(undefined1 *)((int)param_1 + 0x120);
        *(undefined4 *)((int)pvVar4 + 0xc) = *(undefined4 *)((int)param_1 + 0xc);
        iVar3 = *(int *)((int)param_1 + 4);
        FUN_001a7d72(param_1);
        _memcpy(param_1,pvVar4,0x164);
        FUN_000e9596(*(undefined4 *)(iVar3 + 0x158),iVar3,param_1);
        FUN_0010b3fe(iVar2,*(undefined4 *)(param_2 + 8));
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00159c72 @ 0x159c72 (1994 bytes) */
int FUN_00159c72(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  int local_4c;
  int local_28;
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) != 0x1c) {
    return 0;
  }
  if ((*(uint *)(param_1 + 0xb8) & 1) != 0) {
    return 0;
  }
  if ((*(uint *)(param_1 + 0xb8) & 2) != 0) {
    return 0;
  }
  if ((*(uint *)(param_1 + 0xd0) & 1) != 0) {
    return 0;
  }
  if ((*(uint *)(param_1 + 0xd0) & 2) != 0) {
    return 0;
  }
  cVar7 = FUN_000f5a1e(param_1,1);
  if (cVar7 == '\0') {
    return 0;
  }
  cVar7 = FUN_000f5a1e(param_1,2);
  if (cVar7 == '\0') {
    return 0;
  }
  iVar8 = FUN_0010b180(param_1,1);
  iVar9 = FUN_0010b180(param_1,2);
  iVar11 = *(int *)(iVar9 + 0x88);
  if ((((*(int *)(iVar11 + 8) == 0x13) && (*(char *)(iVar9 + 0x120) == '\0')) &&
      (*(int *)(iVar9 + 0x124) == 0)) &&
     ((((*(byte *)(iVar9 + 0x15) & 2) == 0 && ((*(uint *)(iVar9 + 0xb8) & 1) == 0)) &&
      (((*(uint *)(iVar9 + 0xb8) & 2) == 0 &&
       (((*(uint *)(iVar9 + 0xd0) & 1) == 0 && ((*(uint *)(iVar9 + 0xd0) & 2) == 0)))))))) {
    cVar7 = FUN_000f5a1e(iVar9,1);
    if (cVar7 != '\0') {
      uVar10 = FUN_0010b180(iVar9,1);
      cVar7 = FUN_00150398(iVar8,uVar10);
      if (cVar7 != '\0') {
        local_4c = FUN_0010b180(iVar9,2);
        goto LAB_00159de5;
      }
    }
    iVar11 = *(int *)(iVar9 + 0x88);
  }
  if ((((((*(int *)(iVar11 + 8) == 0x13) && (*(char *)(iVar9 + 0x120) == '\0')) &&
        (*(int *)(iVar9 + 0x124) == 0)) &&
       (((*(byte *)(iVar9 + 0x15) & 2) == 0 && ((*(uint *)(iVar9 + 0xb8) & 1) == 0)))) &&
      (((*(uint *)(iVar9 + 0xb8) & 2) == 0 &&
       (((*(uint *)(iVar9 + 0xd0) & 1) == 0 && ((*(uint *)(iVar9 + 0xd0) & 2) == 0)))))) &&
     (cVar7 = FUN_000f5a1e(iVar9,1), cVar7 != '\0')) {
    uVar10 = FUN_0010b180(iVar9,2);
    cVar7 = FUN_00150398(iVar8,uVar10);
    if (cVar7 != '\0') {
      local_4c = FUN_0010b180(iVar9,1);
      goto LAB_00159de5;
    }
  }
  iVar11 = *(int *)(iVar8 + 0x88);
  if (((((*(int *)(iVar11 + 8) == 0x13) && (*(char *)(iVar8 + 0x120) == '\0')) &&
       (*(int *)(iVar8 + 0x124) == 0)) &&
      (((*(byte *)(iVar8 + 0x15) & 2) == 0 && ((*(uint *)(iVar8 + 0xb8) & 1) == 0)))) &&
     (((*(uint *)(iVar8 + 0xb8) & 2) == 0 &&
      (((*(uint *)(iVar8 + 0xd0) & 1) == 0 && ((*(uint *)(iVar8 + 0xd0) & 2) == 0)))))) {
    cVar7 = FUN_000f5a1e(iVar8,1);
    if (cVar7 == '\0') {
      iVar11 = *(int *)(iVar8 + 0x88);
    }
    else {
      uVar10 = FUN_0010b180(iVar8,1);
      cVar7 = FUN_00150398(iVar9,uVar10);
      if (cVar7 != '\0') {
        local_4c = FUN_0010b180(iVar8,2);
        iVar8 = iVar9;
        goto LAB_00159de5;
      }
      iVar11 = *(int *)(iVar8 + 0x88);
    }
  }
  if (*(int *)(iVar11 + 8) != 0x13) {
    return 0;
  }
  if (*(char *)(iVar8 + 0x120) != '\0') {
    return 0;
  }
  if (*(int *)(iVar8 + 0x124) != 0) {
    return 0;
  }
  if ((*(byte *)(iVar8 + 0x15) & 2) != 0) {
    return 0;
  }
  if ((*(uint *)(iVar8 + 0xb8) & 1) != 0) {
    return 0;
  }
  if ((*(uint *)(iVar8 + 0xb8) & 2) != 0) {
    return 0;
  }
  if ((*(uint *)(iVar8 + 0xd0) & 1) != 0) {
    return 0;
  }
  if ((*(uint *)(iVar8 + 0xd0) & 2) != 0) {
    return 0;
  }
  cVar7 = FUN_000f5a1e(iVar8,1);
  if (cVar7 == '\0') {
    return 0;
  }
  uVar10 = FUN_0010b180(iVar8,2);
  cVar7 = FUN_00150398(iVar9,uVar10);
  if (cVar7 == '\0') {
    return 0;
  }
  local_4c = FUN_0010b180(iVar8,1);
  iVar8 = iVar9;
LAB_00159de5:
  if ((((*(char *)(local_4c + 0x120) == '\0') && (*(int *)(local_4c + 0x124) == 0)) &&
      ((*(uint *)(local_4c + 0xb8) & 1) == 0)) &&
     ((((((*(uint *)(local_4c + 0xb8) & 2) == 0 && ((*(byte *)(local_4c + 0x15) & 2) == 0)) &&
        ((iVar11 = FUN_0010b180(local_4c,1), *(int *)(*(int *)(iVar11 + 0x88) + 8) == 0x1c ||
         ((*(char *)(iVar11 + 0x120) == '\0' && (*(int *)(iVar11 + 0x124) == 0)))))) &&
       ((*(uint *)(iVar11 + 0xb8) & 1) == 0)) &&
      ((((((*(uint *)(iVar11 + 0xb8) & 2) == 0 && ((*(uint *)(iVar11 + 0xd0) & 1) == 0)) &&
         ((*(uint *)(iVar11 + 0xd0) & 2) == 0)) &&
        ((cVar7 = FUN_000f5a1e(iVar11,1), cVar7 != '\0' &&
         (cVar7 = FUN_000f5a1e(iVar11,2), cVar7 != '\0')))) && ((*(byte *)(iVar11 + 0x15) & 2) == 0)
       ))))) {
    uVar10 = FUN_0010b180(iVar11,1);
    cVar7 = FUN_00150398(iVar8,uVar10);
    if (cVar7 != '\0') {
      uVar10 = FUN_0010b180(iVar11,2);
      cVar7 = FUN_00150398(iVar8,uVar10);
      if (cVar7 != '\0') {
        iVar8 = FUN_0010b0f4(local_4c,0);
        iVar8 = FUN_000f5ede(*(undefined4 *)(iVar8 + 0x10));
        iVar9 = FUN_0010b0f4(iVar11,0);
        iVar9 = FUN_000f5ede(*(undefined4 *)(iVar9 + 0x10));
        uVar2 = *(uint *)(param_1 + 0x14);
        uVar10 = *(undefined4 *)(param_1 + 0x94);
        uVar3 = *(undefined4 *)(param_1 + 0x98);
        iVar12 = FUN_00109e42(param_1,param_2);
        uVar1 = *(undefined1 *)(param_1 + 0x120);
        uVar4 = *(undefined4 *)(param_1 + 0x124);
        iVar13 = FUN_0010b0f4(param_1,0);
        uVar5 = *(undefined4 *)(iVar13 + 0x10);
        if ((*(byte *)(param_1 + 0x15) & 2) == 0) {
          local_28 = 0;
        }
        else {
          local_28 = FUN_0010b180(param_1,*(undefined4 *)(param_1 + 0x84));
        }
        uVar6 = *(undefined4 *)(param_2 + 8);
        uVar14 = FUN_0010b180(param_1,1);
        FUN_0010b3fe(uVar14,uVar6);
        uVar6 = *(undefined4 *)(param_2 + 8);
        uVar14 = FUN_0010b180(param_1,2);
        FUN_0010b3fe(uVar14,uVar6);
        iVar13 = *(int *)(param_1 + 4);
        FUN_001a7d72(param_1);
        FUN_0010d8fc(param_1,0x13,*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x9c) = uVar5;
        *(int *)(param_1 + 0x160) = iVar12 + *(int *)(param_2 + 0x46c);
        *(undefined4 *)(param_1 + 0x94) = uVar10;
        *(undefined4 *)(param_1 + 0x98) = uVar3;
        *(undefined1 *)(param_1 + 0x120) = uVar1;
        *(undefined4 *)(param_1 + 0x124) = uVar4;
        if ((uVar2 & 2) != 0) {
          *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 2;
        }
        if (local_28 != 0) {
          FUN_0010c18e(param_1,local_28,0,*(undefined4 *)(param_2 + 8));
          if (*(int *)(param_2 + 0x46c) < *(int *)(local_28 + 0x160)) {
            *(int *)(local_28 + 0x160) = *(int *)(local_28 + 0x160) + 1;
          }
          else {
            *(int *)(local_28 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
          }
        }
        FUN_000e9596(*(undefined4 *)(iVar13 + 0x158),iVar13,param_1);
        FUN_0010ba02(param_1,1,iVar11,0,*(undefined4 *)(param_2 + 8));
        uVar10 = *(undefined4 *)(PTR_DAT_00213485 + iVar9 * 4);
        iVar9 = FUN_0010b0f4(param_1,1);
        *(undefined4 *)(iVar9 + 0x10) = uVar10;
        if (*(int *)(param_2 + 0x46c) < *(int *)(iVar11 + 0x160)) {
          *(int *)(iVar11 + 0x160) = *(int *)(iVar11 + 0x160) + 1;
        }
        else {
          *(int *)(iVar11 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
        }
        FUN_0010ba02(param_1,2,local_4c,0,*(undefined4 *)(param_2 + 8));
        uVar10 = *(undefined4 *)(PTR_DAT_00213485 + iVar8 * 4);
        iVar11 = FUN_0010b0f4(param_1,2);
        *(undefined4 *)(iVar11 + 0x10) = uVar10;
        if (*(int *)(param_2 + 0x46c) < *(int *)(local_4c + 0x160)) {
          *(int *)(local_4c + 0x160) = *(int *)(local_4c + 0x160) + 1;
        }
        else {
          *(int *)(local_4c + 0x160) = *(int *)(param_2 + 0x46c) + 1;
        }
        FUN_000f5d78(param_1);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0015a444 @ 0x15a444 (2904 bytes) */
int FUN_0015a444(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char cVar10;
  char cVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int *piVar15;
  int iVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 local_78;
  int local_74;
  int local_70;
  byte local_6c;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) != 0x12) {
    return 0;
  }
  if ((*(byte *)(param_1 + 0x15) & 2) == 0) {
    local_70 = 0;
    iVar12 = FUN_0010b180(param_1,1);
    iVar12 = *(int *)(*(int *)(iVar12 + 0x88) + 8);
  }
  else {
    local_70 = FUN_0010b180(param_1,*(undefined4 *)(param_1 + 0x84));
    iVar12 = FUN_0010b180(param_1,1);
    iVar12 = *(int *)(*(int *)(iVar12 + 0x88) + 8);
  }
  if (iVar12 == 0x12) {
    uVar13 = FUN_0010b180(param_1,1);
    cVar10 = FUN_0010a62e(uVar13,param_2);
    if ((cVar10 != '\0') &&
       ((uint)*(byte *)(param_1 + 0xc) + (uint)*(byte *)(param_1 + 0xd) +
        (uint)*(byte *)(param_1 + 0xe) + (uint)*(byte *)(param_1 + 0xf) == 1)) {
      iVar12 = FUN_0010b180(param_1,1);
      bVar1 = *(byte *)(iVar12 + 0xc);
      iVar12 = FUN_0010b180(param_1,1);
      bVar2 = *(byte *)(iVar12 + 0xd);
      iVar12 = FUN_0010b180(param_1,1);
      bVar3 = *(byte *)(iVar12 + 0xe);
      iVar12 = FUN_0010b180(param_1,1);
      if ((uint)bVar1 + (uint)bVar2 + (uint)bVar3 + (uint)*(byte *)(iVar12 + 0xf) == 1) {
        uVar13 = FUN_0010b180(param_1,2);
        uVar14 = FUN_0010b180(param_1,1);
        uVar14 = FUN_0010b180(uVar14,1);
        cVar10 = FUN_00150398(uVar14,uVar13);
        if (cVar10 != '\0') {
          uVar13 = FUN_0010b180(param_1,2);
          uVar14 = FUN_0010b180(param_1,1);
          uVar14 = FUN_0010b180(uVar14,2);
          cVar10 = FUN_00150398(uVar14,uVar13);
          if (((((cVar10 != '\0') &&
                (iVar12 = FUN_0010b180(param_1,1), (*(byte *)(iVar12 + 0xb8) & 2) == 0)) &&
               (iVar12 = FUN_0010b180(param_1,1), (*(byte *)(iVar12 + 0xd0) & 2) == 0)) &&
              ((iVar12 = FUN_0010b180(param_1,1), *(char *)(iVar12 + 0x120) == '\0' &&
               (iVar12 = FUN_0010b180(param_1,1), *(int *)(iVar12 + 0x124) == 0)))) &&
             (((*(byte *)(param_1 + 0xd0) & 2) == 0 &&
              (iVar12 = FUN_0010b180(param_1,1),
              (*(byte *)(param_1 + 0xd0) & 1) == (*(byte *)(iVar12 + 0xb8) & 1))))) {
            iVar12 = FUN_0010b180(param_1,1);
            local_6c = *(byte *)(iVar12 + 0xd0) & 1;
            if ((*(byte *)(param_1 + 0xd0) & 1) == local_6c) {
              local_74 = FUN_0010b180(param_1,1);
              local_78 = 2;
              goto LAB_0015a6e2;
            }
          }
        }
      }
    }
  }
  iVar12 = FUN_0010b180(param_1,2);
  if (*(int *)(*(int *)(iVar12 + 0x88) + 8) != 0x12) {
    return 0;
  }
  uVar13 = FUN_0010b180(param_1,2);
  cVar10 = FUN_0010a62e(uVar13,param_2);
  if (cVar10 == '\0') {
    return 0;
  }
  if ((uint)*(byte *)(param_1 + 0xc) + (uint)*(byte *)(param_1 + 0xd) +
      (uint)*(byte *)(param_1 + 0xe) + (uint)*(byte *)(param_1 + 0xf) != 1) {
    return 0;
  }
  iVar12 = FUN_0010b180(param_1,2);
  bVar1 = *(byte *)(iVar12 + 0xc);
  iVar12 = FUN_0010b180(param_1,2);
  bVar2 = *(byte *)(iVar12 + 0xd);
  iVar12 = FUN_0010b180(param_1,2);
  bVar3 = *(byte *)(iVar12 + 0xe);
  iVar12 = FUN_0010b180(param_1,2);
  if ((uint)bVar1 + (uint)bVar2 + (uint)bVar3 + (uint)*(byte *)(iVar12 + 0xf) != 1) {
    return 0;
  }
  uVar13 = FUN_0010b180(param_1,1);
  uVar14 = FUN_0010b180(param_1,2);
  uVar14 = FUN_0010b180(uVar14,1);
  cVar10 = FUN_00150398(uVar14,uVar13);
  if (cVar10 == '\0') {
    return 0;
  }
  uVar13 = FUN_0010b180(param_1,1);
  uVar14 = FUN_0010b180(param_1,2);
  uVar14 = FUN_0010b180(uVar14,2);
  cVar10 = FUN_00150398(uVar14,uVar13);
  if (cVar10 == '\0') {
    return 0;
  }
  iVar12 = FUN_0010b180(param_1,2);
  if ((*(byte *)(iVar12 + 0xb8) & 2) != 0) {
    return 0;
  }
  iVar12 = FUN_0010b180(param_1,2);
  if ((*(byte *)(iVar12 + 0xd0) & 2) != 0) {
    return 0;
  }
  iVar12 = FUN_0010b180(param_1,2);
  if (*(char *)(iVar12 + 0x120) != '\0') {
    return 0;
  }
  iVar12 = FUN_0010b180(param_1,2);
  if (*(int *)(iVar12 + 0x124) != 0) {
    return 0;
  }
  if ((*(byte *)(param_1 + 0xb8) & 2) != 0) {
    return 0;
  }
  iVar12 = FUN_0010b180(param_1,2);
  if ((*(byte *)(param_1 + 0xb8) & 1) != (*(byte *)(iVar12 + 0xb8) & 1)) {
    return 0;
  }
  iVar12 = FUN_0010b180(param_1,2);
  local_6c = *(byte *)(iVar12 + 0xd0) & 1;
  if ((*(byte *)(param_1 + 0xb8) & 1) != local_6c) {
    return 0;
  }
  local_74 = FUN_0010b180(param_1,2);
  local_78 = 1;
LAB_0015a6e2:
  iVar12 = FUN_0010b0f4(local_74,0);
  uVar13 = *(undefined4 *)(iVar12 + 0x10);
  iVar12 = FUN_0010b0f4(param_1,0);
  uVar14 = *(undefined4 *)(iVar12 + 0x10);
  iVar12 = FUN_0010b0f4(local_74,1);
  local_28 = *(undefined4 *)(iVar12 + 0x10);
  iVar12 = FUN_000f5ede(uVar13);
  uVar4 = *(undefined1 *)((int)&local_28 + iVar12);
  iVar12 = FUN_0010b0f4(local_74,2);
  local_24 = *(undefined4 *)(iVar12 + 0x10);
  iVar12 = FUN_000f5ede(uVar13);
  uVar5 = *(undefined1 *)((int)local_20 + iVar12 + -4);
  iVar12 = FUN_0010b0f4(param_1,local_78);
  local_20[0] = *(undefined4 *)(iVar12 + 0x10);
  iVar12 = FUN_000f5ede(uVar14);
  uVar6 = *(undefined1 *)((int)local_20 + iVar12);
  (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = CONCAT11(uVar5,uVar4);
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(uVar6,(undefined2)local_2c);
  local_2c = CONCAT13(4,(undefined3)local_2c);
  piVar15 = (int *)FUN_0010b180(local_74,1);
  cVar10 = (**(code **)(*piVar15 + 0x5c))(piVar15);
  piVar15 = *(int **)(*(int *)(param_2 + 8) + 0x54);
  cVar11 = (**(code **)(*piVar15 + 0x108))(piVar15,&local_2c);
  uVar13 = local_2c;
  if (cVar11 == '\0') {
    (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = CONCAT11(uVar6,uVar4);
    (*(unsigned char *)((unsigned char *)&(local_2c) + 3)) = SUB41(uVar13,3);
    (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(uVar5,(undefined2)local_2c);
  }
  piVar15 = *(int **)(*(int *)(param_2 + 8) + 0x54);
  cVar11 = (**(code **)(*piVar15 + 0x108))(piVar15,&local_2c);
  uVar13 = local_2c;
  if (cVar11 == '\0') {
    (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = CONCAT11(uVar5,uVar6);
    (*(unsigned char *)((unsigned char *)&(local_2c) + 3)) = SUB41(uVar13,3);
    (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(uVar4,(undefined2)local_2c);
  }
  piVar15 = *(int **)(*(int *)(param_2 + 8) + 0x54);
  cVar11 = (**(code **)(*piVar15 + 0x108))(piVar15,&local_2c);
  uVar13 = local_2c;
  if (cVar11 == '\0') {
    (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = CONCAT11(uVar4,uVar6);
    (*(unsigned char *)((unsigned char *)&(local_2c) + 3)) = SUB41(uVar13,3);
    (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(uVar5,(undefined2)local_2c);
  }
  piVar15 = *(int **)(*(int *)(param_2 + 8) + 0x54);
  cVar11 = (**(code **)(*piVar15 + 0x108))(piVar15,&local_2c);
  uVar13 = local_2c;
  if (cVar11 == '\0') {
    (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = CONCAT11(uVar6,uVar5);
    (*(unsigned char *)((unsigned char *)&(local_2c) + 3)) = SUB41(uVar13,3);
    (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(uVar4,(undefined2)local_2c);
  }
  piVar15 = *(int **)(*(int *)(param_2 + 8) + 0x54);
  cVar11 = (**(code **)(*piVar15 + 0x108))(piVar15,&local_2c);
  uVar13 = local_2c;
  if (cVar11 == '\0') {
    (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = CONCAT11(uVar4,uVar5);
    (*(unsigned char *)((unsigned char *)&(local_2c) + 3)) = SUB41(uVar13,3);
    (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(uVar6,(undefined2)local_2c);
  }
  if ((cVar10 != '\0') &&
     (piVar15 = *(int **)(*(int *)(param_2 + 8) + 0x54),
     cVar11 = (**(code **)(*piVar15 + 0x108))(piVar15,&local_2c), cVar11 == '\0')) {
    return 0;
  }
  piVar15 = *(int **)(*(int *)(param_2 + 8) + 0x54);
  cVar11 = (**(code **)(*piVar15 + 0x108))(piVar15,&local_2c);
  if (cVar11 == '\0') {
    piVar15 = *(int **)(*(int *)(param_2 + 8) + 0x54);
    cVar11 = (**(code **)(*piVar15 + 0x100))(piVar15,&local_2c);
    uVar13 = local_2c;
    if (cVar11 == '\0') {
      (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = CONCAT11(uVar6,uVar4);
      (*(unsigned char *)((unsigned char *)&(local_2c) + 3)) = SUB41(uVar13,3);
      (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(uVar5,(undefined2)local_2c);
    }
    piVar15 = *(int **)(*(int *)(param_2 + 8) + 0x54);
    cVar11 = (**(code **)(*piVar15 + 0x100))(piVar15,&local_2c);
    uVar13 = local_2c;
    if (cVar11 == '\0') {
      (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = CONCAT11(uVar5,uVar6);
      (*(unsigned char *)((unsigned char *)&(local_2c) + 3)) = SUB41(uVar13,3);
      (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(uVar4,(undefined2)local_2c);
    }
    piVar15 = *(int **)(*(int *)(param_2 + 8) + 0x54);
    cVar11 = (**(code **)(*piVar15 + 0x100))(piVar15,&local_2c);
    uVar13 = local_2c;
    if (cVar11 == '\0') {
      (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = CONCAT11(uVar4,uVar6);
      (*(unsigned char *)((unsigned char *)&(local_2c) + 3)) = SUB41(uVar13,3);
      (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(uVar5,(undefined2)local_2c);
    }
    piVar15 = *(int **)(*(int *)(param_2 + 8) + 0x54);
    cVar11 = (**(code **)(*piVar15 + 0x100))(piVar15,&local_2c);
    uVar13 = local_2c;
    if (cVar11 == '\0') {
      (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = CONCAT11(uVar6,uVar5);
      (*(unsigned char *)((unsigned char *)&(local_2c) + 3)) = SUB41(uVar13,3);
      (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(uVar4,(undefined2)local_2c);
    }
    piVar15 = *(int **)(*(int *)(param_2 + 8) + 0x54);
    cVar11 = (**(code **)(*piVar15 + 0x100))(piVar15,&local_2c);
    uVar13 = local_2c;
    if (cVar11 == '\0') {
      (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = CONCAT11(uVar4,uVar5);
      (*(unsigned char *)((unsigned char *)&(local_2c) + 3)) = SUB41(uVar13,3);
      (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(uVar6,(undefined2)local_2c);
    }
    piVar15 = *(int **)(*(int *)(param_2 + 8) + 0x54);
    cVar11 = (**(code **)(*piVar15 + 0x100))(piVar15,&local_2c);
    if (cVar11 == '\0') {
      return 0;
    }
  }
  iVar12 = FUN_0010b180(local_74,1);
  if (cVar10 != '\0') {
    iVar16 = FUN_0010b0f4(iVar12,0);
    uVar13 = *(undefined4 *)(iVar16 + 0x10);
    uVar17 = FUN_0010b180(local_74,2);
    iVar16 = FUN_0010b0f4(uVar17,0);
    uVar13 = FUN_000f5892(uVar13,*(undefined4 *)(iVar16 + 0x10));
    uVar17 = FUN_0010b180(param_1,local_78);
    iVar16 = FUN_0010b0f4(uVar17,0);
    uVar13 = FUN_000f5892(uVar13,*(undefined4 *)(iVar16 + 0x10));
    *(undefined4 *)(iVar12 + 0x9c) = uVar13;
    uVar13 = FUN_000f5fea(uVar13);
    uVar13 = FUN_000f5b96(DAT_001cc5a0,uVar13);
    iVar16 = FUN_0010b0f4(iVar12,1);
    *(undefined4 *)(iVar16 + 0x10) = uVar13;
    iVar16 = FUN_0010b0f4(iVar12,2);
    *(undefined4 *)(iVar16 + 0x10) = uVar13;
  }
  uVar7 = *(uint *)(param_1 + 0x14);
  uVar13 = *(undefined4 *)(param_1 + 0x94);
  uVar17 = *(undefined4 *)(param_1 + 0x98);
  iVar16 = FUN_00109e42(param_1,param_2);
  uVar4 = *(undefined1 *)(param_1 + 0x120);
  uVar8 = *(undefined4 *)(param_1 + 0x124);
  uVar9 = *(undefined4 *)(param_2 + 8);
  uVar18 = FUN_0010b180(param_1,local_78);
  FUN_0010b3fe(uVar18,uVar9);
  FUN_001a7d72(param_1);
  FUN_0010d8fc(param_1,0x1c,*(undefined4 *)(param_2 + 8));
  *(undefined4 *)(param_1 + 0x9c) = uVar14;
  *(int *)(param_1 + 0x160) = iVar16 + *(int *)(param_2 + 0x46c);
  *(undefined4 *)(param_1 + 0x94) = uVar13;
  *(undefined4 *)(param_1 + 0x98) = uVar17;
  *(undefined1 *)(param_1 + 0x120) = uVar4;
  *(undefined4 *)(param_1 + 0x124) = uVar8;
  if ((uVar7 & 2) != 0) {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 2;
  }
  if (local_70 != 0) {
    FUN_0010c18e(param_1,local_70,0,*(undefined4 *)(param_2 + 8));
    if (*(int *)(param_2 + 0x46c) < *(int *)(local_70 + 0x160)) {
      *(int *)(local_70 + 0x160) = *(int *)(local_70 + 0x160) + 1;
    }
    else {
      *(int *)(local_70 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
    }
  }
  FUN_000e9596(*(undefined4 *)(local_74 + 0x158),local_74,param_1);
  FUN_0010ba02(param_1,1,iVar12,0,*(undefined4 *)(param_2 + 8));
  FUN_00109c0e(param_1 + 0xa4,1,local_6c);
  uVar13 = local_2c;
  iVar12 = FUN_0010b0f4(param_1,1);
  *(undefined4 *)(iVar12 + 0x10) = uVar13;
  iVar12 = *(int *)(param_2 + 0x46c);
  iVar16 = FUN_0010b180(local_74,1);
  if (iVar12 < *(int *)(iVar16 + 0x160)) {
    *(int *)(iVar16 + 0x160) = *(int *)(iVar16 + 0x160) + 1;
  }
  else {
    *(int *)(iVar16 + 0x160) = iVar12 + 1;
  }
  FUN_000fa0d2(param_1,param_2,2,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  FUN_0010b3fe(local_74,*(undefined4 *)(param_2 + 8));
  return 1;
}

/* FUN_0015afa4 @ 0x15afa4 (1208 bytes) */
int FUN_0015afa4(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  byte local_30;
  byte local_2c;
  uint local_1c;
  int local_18;
  int local_14;
  
  iVar2 = FUN_0010b0f4(param_2,0);
  iVar2 = *(int *)(iVar2 + 0x10);
  iVar3 = FUN_0010b0f4(param_1,0);
  if ((((*(int *)(iVar3 + 0x10) == iVar2) && ((char)param_1[0x48] == (char)param_2[0x48])) &&
      (param_1[0x49] == param_2[0x49])) && (param_1[0x21] == param_2[0x21])) {
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
    iVar2 = iVar2 + 1;
    if (iVar2 <= param_1[0x21]) {
      do {
        iVar3 = FUN_0010b180(param_1,iVar2);
        iVar4 = FUN_0010b180(param_2,iVar2);
        if (iVar3 != iVar4) {
          return;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 <= param_1[0x21]);
    }
    iVar2 = FUN_0010b180(param_1,1);
    iVar3 = FUN_0010b180(param_2,1);
    if (iVar2 == iVar3) {
      iVar2 = FUN_0010b180(param_1,2);
      iVar3 = FUN_0010b180(param_2,2);
      if (iVar2 == iVar3) {
        iVar2 = FUN_0010b0f4(param_2,1);
        iVar2 = *(int *)(iVar2 + 0x10);
        iVar3 = FUN_0010b0f4(param_1,1);
        if (*(int *)(iVar3 + 0x10) == iVar2) {
          iVar2 = FUN_0010b0f4(param_2,2);
          iVar2 = *(int *)(iVar2 + 0x10);
          iVar3 = FUN_0010b0f4(param_1,2);
          if (*(int *)(iVar3 + 0x10) == iVar2) {
            if (((byte)param_1[0x2e] & 1) == ((byte)param_2[0x2e] & 1)) {
              if (((((byte)param_1[0x34] & 1) == ((byte)param_2[0x34] & 1)) &&
                  (((byte)((uint)param_1[0x2e] >> 1) & 1) == ((byte)((uint)param_2[0x2e] >> 1) & 1))
                  ) && (local_2c = (byte)((uint)param_1[0x34] >> 1) & 1,
                       local_2c == ((byte)((uint)param_2[0x34] >> 1) & 1))) goto LAB_0015b1d1;
            }
          }
        }
      }
    }
    iVar2 = FUN_0010b180(param_1,1);
    iVar3 = FUN_0010b180(param_2,2);
    if (iVar2 == iVar3) {
      iVar2 = FUN_0010b180(param_1,2);
      iVar3 = FUN_0010b180(param_2,1);
      if (iVar2 == iVar3) {
        iVar2 = FUN_0010b0f4(param_2,2);
        iVar2 = *(int *)(iVar2 + 0x10);
        iVar3 = FUN_0010b0f4(param_1,1);
        if (*(int *)(iVar3 + 0x10) == iVar2) {
          iVar2 = FUN_0010b0f4(param_2,1);
          iVar2 = *(int *)(iVar2 + 0x10);
          iVar3 = FUN_0010b0f4(param_1,2);
          if (*(int *)(iVar3 + 0x10) == iVar2) {
            if (((byte)param_1[0x2e] & 1) == ((byte)param_2[0x34] & 1)) {
              if (((((byte)param_1[0x34] & 1) == ((byte)param_2[0x2e] & 1)) &&
                  (((byte)((uint)param_1[0x2e] >> 1) & 1) == ((byte)((uint)param_2[0x34] >> 1) & 1))
                  ) && (local_30 = (byte)((uint)param_1[0x34] >> 1) & 1,
                       local_30 == ((byte)((uint)param_2[0x2e] >> 1) & 1))) {
LAB_0015b1d1:
                puVar6 = (uint *)param_2[4];
                local_1c = puVar6[1] - 1;
                if (-1 < (int)local_1c) {
                  local_14 = local_1c * 4;
                  do {
                    if (local_1c < *puVar6) {
                      uVar1 = puVar6[1];
                      if (uVar1 <= local_1c) {
                        _memset((void *)(puVar6[2] + uVar1 * 4),0,(local_1c - uVar1) * 4 + 4);
                        puVar6[1] = local_1c + 1;
                      }
                      piVar5 = (int *)(local_14 + puVar6[2]);
                    }
                    else {
                      piVar5 = (int *)FUN_001a7f7c(puVar6,local_1c);
                    }
                    iVar2 = *piVar5;
                    iVar3 = *(int *)(iVar2 + 0x84);
                    iVar4 = iVar3;
                    if ((*(byte *)(iVar2 + 0x15) & 2) == 0) {
LAB_0015b24b:
                      if (0 < iVar4) {
                        local_18 = 1;
                        do {
                          piVar5 = (int *)FUN_0010b180(iVar2,local_18);
                          if (param_2 == piVar5) {
                            FUN_0010ba02(iVar2,local_18,param_1,1,*(undefined4 *)(param_3 + 8));
                            break;
                          }
                          local_18 = local_18 + 1;
                        } while (local_18 <= iVar4);
                      }
                    }
                    else {
                      iVar4 = iVar3 + -1;
                      piVar5 = (int *)FUN_0010b180(iVar2,iVar3);
                      if (param_2 != piVar5) goto LAB_0015b24b;
                      FUN_0010c18e(iVar2,param_1,1,*(undefined4 *)(param_3 + 8));
                    }
                    local_1c = local_1c - 1;
                    local_14 = local_14 + -4;
                    if (local_1c == 0xffffffff) break;
                    puVar6 = (uint *)param_2[4];
                  } while( true );
                }
                (**(code **)(*param_2 + 0xc))(param_2,1,*(undefined4 *)(param_3 + 8));
                FUN_001507b4();
                return;
              }
            }
          }
        }
      }
    }
  }
  return;
}

/* FUN_0015b45c @ 0x15b45c (783 bytes) */
int FUN_0015b45c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  uint uVar12;
  int local_24;
  uint local_1c;
  uint local_18;
  int local_14;
  undefined4 local_10;
  
  if ((*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x12) ||
     (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x13)) {
    uVar5 = FUN_0010b180(param_1,1);
    uVar6 = FUN_0010b180(param_1,2);
    cVar4 = FUN_0010a62e(uVar5,param_2);
    if ((cVar4 == '\0') &&
       (((cVar4 = FUN_0010a67e(uVar5,param_2), cVar4 == '\0' &&
         (cVar4 = FUN_0010a62e(uVar6,param_2), cVar4 == '\0')) &&
        (cVar4 = FUN_0010a67e(uVar6,param_2), cVar4 == '\0')))) {
      local_10 = *(undefined4 *)(*(int *)(param_2 + 8) + 0xbc);
      local_18 = 0;
      local_1c = 2;
      local_14 = FUN_001a7bca(local_10,8);
      iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 8);
      iVar7 = FUN_0010b180(param_1,1);
      puVar11 = *(uint **)(iVar7 + 0x10);
      uVar12 = puVar11[1] - 1;
      if (-1 < (int)uVar12) {
        local_24 = uVar12 * 4;
        do {
          if (uVar12 < *puVar11) {
            uVar2 = puVar11[1];
            if (uVar2 <= uVar12) {
              _memset((void *)(puVar11[2] + uVar2 * 4),0,(uVar12 - uVar2) * 4 + 4);
              puVar11[1] = uVar12 + 1;
            }
            piVar8 = (int *)(local_24 + puVar11[2]);
          }
          else {
            piVar8 = (int *)FUN_001a7f7c(puVar11,uVar12);
          }
          iVar3 = *piVar8;
          if ((iVar1 == *(int *)(*(int *)(iVar3 + 0x88) + 8)) && (param_1 != iVar3)) {
            iVar9 = FUN_0010b180(iVar3,1);
            iVar10 = FUN_0010b180(param_1,1);
            if (iVar9 == iVar10) {
              iVar9 = FUN_0010b180(iVar3,2);
              iVar10 = FUN_0010b180(param_1,2);
              if (iVar9 != iVar10) goto LAB_0015b62a;
LAB_0015b68a:
              uVar2 = local_18;
              if (local_18 < local_1c) {
                iVar9 = local_18 * 4;
                _memset((void *)(iVar9 + local_14),0,4);
                local_18 = uVar2 + 1;
                *(int *)(iVar9 + local_14) = iVar3;
              }
              else {
                piVar8 = (int *)FUN_001a7f7c(&local_1c,local_18);
                *piVar8 = iVar3;
              }
            }
            else {
LAB_0015b62a:
              iVar9 = FUN_0010b180(iVar3,2);
              iVar10 = FUN_0010b180(param_1,1);
              if (iVar9 == iVar10) {
                iVar9 = FUN_0010b180(iVar3,1);
                iVar10 = FUN_0010b180(param_1,2);
                if (iVar9 == iVar10) goto LAB_0015b68a;
              }
            }
          }
          uVar12 = uVar12 - 1;
          local_24 = local_24 + -4;
          if (uVar12 == 0xffffffff) break;
          puVar11 = *(uint **)(iVar7 + 0x10);
        } while( true );
      }
      while (local_18 != 0) {
        uVar12 = local_18 - 1;
        if (uVar12 < local_18) {
          piVar8 = (int *)(local_14 + uVar12 * 4);
        }
        else {
          piVar8 = (int *)0x0;
        }
        iVar1 = *piVar8;
        FUN_001a7f3c(&local_1c,uVar12);
        if ((*(byte *)(iVar1 + 0x14) & 1) != 0) {
          ((int (*)())FUN_0015afa4)(param_1,iVar1,param_2);
        }
      }
      FUN_001a7aba(local_10,local_14);
    }
  }
  return;
}

/* FUN_0015b788 @ 0x15b788 (3193 bytes) */
int FUN_0015b788(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 uVar13;
  int iVar14;
  int *piVar15;
  bool bVar16;
  int local_6c;
  int local_68;
  int local_64;
  char local_60;
  int aiStack_54 [4];
  int local_44 [3];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  byte local_26;
  bool local_25;
  byte local_24;
  byte local_23 [19];
  
  iVar9 = *param_1;
  bVar16 = *(int *)(*(int *)(iVar9 + 0x88) + 8) == 0x13;
  if (bVar16) {
    cVar3 = FUN_0014fd92(param_1,param_2);
    if (cVar3 == '\0') {
      return 0;
    }
    iVar9 = *param_1;
  }
  iVar7 = FUN_0010b180(*param_2,param_2[1]);
  if ((iVar9 != iVar7) &&
     (iVar9 = *param_2, iVar7 = FUN_0010b180(*param_1,param_1[1]), iVar9 != iVar7)) {
    uVar8 = FUN_0010b180(*param_1,param_1[1]);
    local_30 = FUN_0010b180(uVar8,1);
    uVar8 = FUN_0010b180(*param_1,param_1[1]);
    local_2c = FUN_0010b180(uVar8,2);
    uVar8 = FUN_0010b180(*param_1,param_1[1]);
    iVar9 = FUN_0010b0f4(uVar8,1);
    local_38 = *(undefined4 *)(iVar9 + 0x10);
    uVar8 = FUN_0010b180(*param_1,param_1[1]);
    iVar9 = FUN_0010b0f4(uVar8,2);
    local_34 = *(undefined4 *)(iVar9 + 0x10);
    iVar9 = FUN_0010b180(*param_1,param_1[1]);
    local_23[5] = *(byte *)(iVar9 + 0xb8) & 1;
    iVar9 = FUN_0010b180(*param_1,param_1[1]);
    local_23[6] = *(byte *)(iVar9 + 0xd0) & 1;
    iVar9 = FUN_0010b180(*param_1,param_1[1]);
    local_23[3] = (byte)(*(uint *)(iVar9 + 0xb8) >> 1) & 1;
    iVar9 = FUN_0010b180(*param_1,param_1[1]);
    local_23[4] = (byte)(*(uint *)(iVar9 + 0xd0) >> 1) & 1;
    uVar8 = FUN_0010b180(*param_2,param_2[1]);
    aiStack_54[1] = FUN_0010b180(uVar8,1);
    uVar8 = FUN_0010b180(*param_2,param_2[1]);
    aiStack_54[2] = FUN_0010b180(uVar8,2);
    uVar10 = param_2[1] & 0x80000001;
    if ((int)uVar10 < 0) {
      uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
    }
    uVar8 = FUN_0010b180(*param_2,uVar10 + 1);
    aiStack_54[3] = uVar8;
    uVar11 = FUN_0010b180(*param_2,param_2[1]);
    iVar9 = FUN_0010b0f4(uVar11,1);
    local_44[0] = *(undefined4 *)(iVar9 + 0x10);
    uVar11 = FUN_0010b180(*param_2,param_2[1]);
    iVar9 = FUN_0010b0f4(uVar11,2);
    local_44[1] = *(undefined4 *)(iVar9 + 0x10);
    uVar10 = param_2[1] & 0x80000001;
    if ((int)uVar10 < 0) {
      uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
    }
    iVar9 = FUN_0010b0f4(*param_2,uVar10 + 1);
    local_44[2] = *(undefined4 *)(iVar9 + 0x10);
    iVar9 = FUN_0010b0f4(*param_2,param_2[1]);
    local_44[0] = FUN_000f5610(local_44[0],*(undefined4 *)(iVar9 + 0x10));
    iVar9 = FUN_0010b0f4(*param_2,param_2[1]);
    local_44[1] = FUN_000f5610(local_44[1],*(undefined4 *)(iVar9 + 0x10));
    iVar9 = FUN_0010b180(*param_2,param_2[1]);
    local_26 = *(byte *)(iVar9 + 0xb8) & 1;
    iVar9 = FUN_0010b180(*param_2,param_2[1]);
    local_25 = (bool)(*(byte *)(iVar9 + 0xd0) & 1);
    uVar10 = param_2[1];
    iVar9 = *param_2;
    uVar12 = uVar10 & 0x80000001;
    if ((int)uVar12 < 0) {
      local_24 = *(byte *)(iVar9 + 0xb8 + ((uVar12 - 1 | 0xfffffffe) + 1) * 0x18);
    }
    else {
      local_24 = *(byte *)(iVar9 + 0xb8 + uVar12 * 0x18);
    }
    local_24 = local_24 & 1;
    if (!bVar16) {
      iVar7 = uVar10 * 0x18 + 0x80;
      local_26 = (*(byte *)(iVar9 + 0x20 + iVar7) & 1) != local_26;
      local_25 = (bool)(*(byte *)(iVar9 + 0x20 + iVar7) & 1) != local_25;
    }
    iVar9 = FUN_0010b180(iVar9,uVar10);
    local_23[0] = (byte)(*(uint *)(iVar9 + 0xb8) >> 1) & 1;
    iVar9 = FUN_0010b180(*param_2,param_2[1]);
    local_23[1] = (byte)(*(uint *)(iVar9 + 0xd0) >> 1) & 1;
    uVar10 = param_2[1] & 0x80000001;
    if ((int)uVar10 < 0) {
      uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
    }
    bVar4 = (byte)(*(uint *)(*param_2 + 0xb8 + uVar10 * 0x18) >> 1) & 1;
    local_23[2] = bVar4;
    local_6c = 0;
    local_68 = 1;
    local_64 = 0;
    do {
      iVar7 = local_64 + 1;
      iVar9 = iVar7 % 3;
      if ((aiStack_54[iVar7] == aiStack_54[local_6c + 9]) &&
         (aiStack_54[iVar9 + 1] == aiStack_54[local_68 + 9])) {
LAB_0015bbf1:
        if (((bVar16) ||
            ((((local_23[local_6c + 3] == local_23[local_64] &&
               (local_23[local_68 + 3] == local_23[iVar9])) &&
              (local_23[local_6c + 5] == (&local_26)[local_64])) &&
             (local_23[local_68 + 5] == (&local_26)[iVar9])))) &&
           ((cVar3 = FUN_000f575e(aiStack_54[local_6c + 7],aiStack_54[local_64 + 4]), cVar3 != '\0'
            && (cVar3 = FUN_000f575e(aiStack_54[local_68 + 7],aiStack_54[iVar9 + 4]), cVar3 != '\0')
            ))) {
          if (param_4 == '\0') {
            return 1;
          }
          if (local_64 == 2) {
            uVar11 = *(undefined4 *)(param_3 + 8);
            uVar13 = FUN_0010b180(*param_2,param_2[1]);
            FUN_0010ba02(uVar13,2,uVar8,1,uVar11);
            bVar2 = local_24;
            iVar9 = FUN_0010b180(*param_2,param_2[1]);
            FUN_00109c0e(iVar9 + 0xbc,1,bVar2);
            iVar9 = FUN_0010b180(*param_2,param_2[1]);
            FUN_00109c0e(iVar9 + 0xbc,2,bVar4);
            iVar9 = local_44[2];
            uVar8 = FUN_0010b180(*param_2,param_2[1]);
            iVar7 = FUN_0010b0f4(uVar8,2);
            bVar4 = local_26;
            *(int *)(iVar7 + 0x10) = iVar9;
            iVar9 = FUN_0010b180(*param_2,param_2[1]);
            FUN_00109c0e(iVar9 + 0xa4,1,bVar4);
            bVar4 = local_23[0];
            iVar9 = FUN_0010b180(*param_2,param_2[1]);
            FUN_00109c0e(iVar9 + 0xa4,2,bVar4);
            iVar9 = local_44[0];
            uVar8 = FUN_0010b180(*param_2,param_2[1]);
            iVar7 = FUN_0010b0f4(uVar8,1);
            *(int *)(iVar7 + 0x10) = iVar9;
            uVar10 = param_2[1] & 0x80000001;
            if ((int)uVar10 < 0) {
              uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
            }
            FUN_0010ba02(*param_2,uVar10 + 1,aiStack_54[2],1,*(undefined4 *)(param_3 + 8));
            iVar9 = local_44[1];
            uVar10 = param_2[1] & 0x80000001;
            if ((int)uVar10 < 0) {
              uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
            }
            iVar7 = FUN_0010b0f4(*param_2,uVar10 + 1);
            *(int *)(iVar7 + 0x10) = iVar9;
            uVar10 = param_2[1] & 0x80000001;
            if ((int)uVar10 < 0) {
              uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
            }
            FUN_00109c0e(*param_2 + 0xa4 + uVar10 * 0x18,1,local_25);
            bVar4 = local_23[1];
          }
          else {
            if (local_64 != 1) goto LAB_0015bc94;
            uVar11 = *(undefined4 *)(param_3 + 8);
            uVar13 = FUN_0010b180(*param_2,param_2[1]);
            FUN_0010ba02(uVar13,1,uVar8,1,uVar11);
            bVar2 = local_24;
            iVar9 = FUN_0010b180(*param_2,param_2[1]);
            FUN_00109c0e(iVar9 + 0xa4,1,bVar2);
            iVar9 = FUN_0010b180(*param_2,param_2[1]);
            FUN_00109c0e(iVar9 + 0xa4,2,bVar4);
            iVar9 = local_44[2];
            uVar8 = FUN_0010b180(*param_2,param_2[1]);
            iVar7 = FUN_0010b0f4(uVar8,1);
            bVar1 = local_25;
            *(int *)(iVar7 + 0x10) = iVar9;
            iVar9 = FUN_0010b180(*param_2,param_2[1]);
            FUN_00109c0e(iVar9 + 0xbc,1,bVar1);
            bVar4 = local_23[1];
            iVar9 = FUN_0010b180(*param_2,param_2[1]);
            FUN_00109c0e(iVar9 + 0xbc,2,bVar4);
            iVar9 = local_44[1];
            uVar8 = FUN_0010b180(*param_2,param_2[1]);
            iVar7 = FUN_0010b0f4(uVar8,2);
            *(int *)(iVar7 + 0x10) = iVar9;
            uVar10 = param_2[1] & 0x80000001;
            if ((int)uVar10 < 0) {
              uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
            }
            FUN_0010ba02(*param_2,uVar10 + 1,aiStack_54[1],1,*(undefined4 *)(param_3 + 8));
            iVar9 = local_44[0];
            uVar10 = param_2[1] & 0x80000001;
            if ((int)uVar10 < 0) {
              uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
            }
            iVar7 = FUN_0010b0f4(*param_2,uVar10 + 1);
            *(int *)(iVar7 + 0x10) = iVar9;
            uVar10 = param_2[1] & 0x80000001;
            if ((int)uVar10 < 0) {
              uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
            }
            FUN_00109c0e(*param_2 + 0xa4 + uVar10 * 0x18,1,local_26);
            bVar4 = local_23[0];
          }
          uVar10 = param_2[1] & 0x80000001;
          if ((int)uVar10 < 0) {
            uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
          }
          FUN_00109c0e(*param_2 + 0xa4 + uVar10 * 0x18,2,bVar4);
          if (!bVar16) {
            FUN_00109c0e(*param_2 + 0x8c + param_2[1] * 0x18,1,0);
          }
          iVar9 = FUN_0010b0f4(*param_2,0);
          uVar8 = FUN_000f5fea(*(undefined4 *)(iVar9 + 0x10));
          uVar8 = FUN_000f5b96(DAT_001cc5a0,uVar8);
          iVar9 = FUN_0010b0f4(*param_2,param_2[1]);
          *(undefined4 *)(iVar9 + 0x10) = uVar8;
LAB_0015bc94:
          uVar8 = FUN_0010b180(*param_2,param_2[1]);
          iVar9 = FUN_0010b0f4(uVar8,1);
          uVar8 = *(undefined4 *)(iVar9 + 0x10);
          uVar11 = FUN_0010b180(*param_2,param_2[1]);
          iVar9 = FUN_0010b0f4(uVar11,2);
          uVar11 = *(undefined4 *)(iVar9 + 0x10);
          uVar13 = FUN_0010b180(*param_2,param_2[1]);
          FUN_0010b0f4(uVar13,0);
          local_60 = (char)uVar8;
          if ((local_60 == '\x04') && ((char)uVar11 == '\x04')) {
            uVar5 = 1;
          }
          else {
            uVar5 = 0;
          }
          if (((char)((uint)uVar8 >> 8) == '\x04') && ((char)((uint)uVar11 >> 8) == '\x04')) {
            uVar6 = 1;
          }
          else {
            uVar6 = 0;
          }
          if (((char)((uint)uVar8 >> 0x10) == '\x04') && ((char)((uint)uVar11 >> 0x10) == '\x04')) {
            iVar9 = 1;
          }
          else {
            iVar9 = 0;
          }
          local_60 = (char)((uint)uVar8 >> 0x18);
          if ((local_60 == '\x04') && ((char)((uint)uVar11 >> 0x18) == '\x04')) {
            iVar7 = 1;
          }
          else {
            iVar7 = 0;
          }
          iVar14 = FUN_0010b180(*param_2,param_2[1]);
          *(uint *)(iVar14 + 0x9c) = (uint)CONCAT11(uVar6,uVar5) | iVar9 << 0x10 | iVar7 << 0x18;
          uVar8 = FUN_0010b180(*param_1,param_1[1]);
          FUN_001507b4(param_3,uVar8,param_3);
          if (param_5 != '\0') {
            piVar15 = (int *)FUN_0010b180(*param_2,param_2[1]);
            uVar8 = *(undefined4 *)(param_3 + 8);
            uVar11 = FUN_0010b180(*param_1,param_1[1]);
            FUN_0010ba02(*param_2,param_2[1],uVar11,1,uVar8);
            cVar3 = FUN_0010a67e(piVar15,param_3);
            if (cVar3 != '\0') {
              (**(code **)(*piVar15 + 0xc))(piVar15,1,*(undefined4 *)(param_3 + 8));
              return 1;
            }
          }
          return 1;
        }
      }
      else if ((aiStack_54[iVar7] == aiStack_54[local_68 + 9]) &&
              (aiStack_54[local_6c + 9] == aiStack_54[iVar9 + 1])) {
        local_6c = 1;
        local_68 = 0;
        goto LAB_0015bbf1;
      }
      local_64 = iVar7;
    } while (iVar7 != 3);
  }
  return 0;
}

/* FUN_0015c402 @ 0x15c402 (6027 bytes) */
int FUN_0015c402(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  undefined4 uVar16;
  int iVar17;
  undefined4 uVar18;
  int iVar19;
  int *piVar20;
  bool bVar21;
  int local_78;
  int local_74;
  char local_68;
  char local_64;
  int local_60;
  int aiStack_5c [4];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  byte local_28 [4];
  bool local_24;
  byte local_23;
  byte local_22 [4];
  bool local_1e;
  byte local_1d;
  
  iVar14 = *param_1;
  bVar21 = *(int *)(*(int *)(iVar14 + 0x88) + 8) == 0x13;
  if (bVar21) {
    cVar5 = FUN_0014fd92(param_1,param_2);
    if (cVar5 == '\0') {
      return 0;
    }
    iVar14 = *param_1;
  }
  iVar10 = FUN_0010b180(*param_2,param_2[1]);
  if ((iVar14 == iVar10) ||
     (iVar14 = *param_2, iVar10 = FUN_0010b180(*param_1,param_1[1]), iVar14 == iVar10)) {
    return 0;
  }
  uVar11 = FUN_0010b180(*param_1,param_1[1]);
  local_4c = FUN_0010b180(uVar11,1);
  uVar11 = FUN_0010b180(*param_1,param_1[1]);
  local_48 = FUN_0010b180(uVar11,2);
  uVar12 = param_1[1] & 0x80000001;
  if ((int)uVar12 < 0) {
    uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
  }
  uVar11 = FUN_0010b180(*param_1,uVar12 + 1);
  local_44 = uVar11;
  uVar13 = FUN_0010b180(*param_1,param_1[1]);
  iVar14 = FUN_0010b0f4(uVar13,1);
  local_40 = *(undefined4 *)(iVar14 + 0x10);
  uVar13 = FUN_0010b180(*param_1,param_1[1]);
  iVar14 = FUN_0010b0f4(uVar13,2);
  local_3c = *(undefined4 *)(iVar14 + 0x10);
  uVar12 = param_1[1] & 0x80000001;
  if ((int)uVar12 < 0) {
    uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
  }
  iVar14 = FUN_0010b0f4(*param_1,uVar12 + 1);
  local_38 = *(undefined4 *)(iVar14 + 0x10);
  iVar14 = FUN_0010b0f4(*param_1,param_1[1]);
  local_40 = FUN_000f5610(local_40,*(undefined4 *)(iVar14 + 0x10));
  iVar14 = FUN_0010b0f4(*param_1,param_1[1]);
  local_3c = FUN_000f5610(local_3c,*(undefined4 *)(iVar14 + 0x10));
  iVar14 = FUN_0010b180(*param_1,param_1[1]);
  local_22[3] = *(byte *)(iVar14 + 0xb8) & 1;
  iVar14 = FUN_0010b180(*param_1,param_1[1]);
  local_1e = (bool)(*(byte *)(iVar14 + 0xd0) & 1);
  uVar12 = param_1[1];
  iVar14 = *param_1;
  uVar15 = uVar12 & 0x80000001;
  if ((int)uVar15 < 0) {
    local_1d = *(byte *)(iVar14 + 0xb8 + ((uVar15 - 1 | 0xfffffffe) + 1) * 0x18);
  }
  else {
    local_1d = *(byte *)(iVar14 + 0xb8 + uVar15 * 0x18);
  }
  local_1d = local_1d & 1;
  if (!bVar21) {
    iVar10 = uVar12 * 0x18 + 0x80;
    local_22[3] = (*(byte *)(iVar14 + 0x20 + iVar10) & 1) != local_22[3];
    local_1e = (bool)(*(byte *)(iVar14 + 0x20 + iVar10) & 1) != local_1e;
  }
  iVar14 = FUN_0010b180(iVar14,uVar12);
  local_22[0] = (byte)(*(uint *)(iVar14 + 0xb8) >> 1) & 1;
  iVar14 = FUN_0010b180(*param_1,param_1[1]);
  local_22[1] = (byte)(*(uint *)(iVar14 + 0xd0) >> 1) & 1;
  uVar12 = param_1[1] & 0x80000001;
  if ((int)uVar12 < 0) {
    uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
  }
  bVar6 = (byte)(*(uint *)(*param_1 + 0xb8 + uVar12 * 0x18) >> 1) & 1;
  local_22[2] = bVar6;
  uVar13 = FUN_0010b180(*param_2,param_2[1]);
  local_34 = FUN_0010b180(uVar13,1);
  uVar13 = FUN_0010b180(*param_2,param_2[1]);
  local_30 = FUN_0010b180(uVar13,2);
  uVar12 = param_2[1] & 0x80000001;
  if ((int)uVar12 < 0) {
    uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
  }
  uVar13 = FUN_0010b180(*param_2,uVar12 + 1);
  local_2c = uVar13;
  uVar16 = FUN_0010b180(*param_2,param_2[1]);
  iVar14 = FUN_0010b0f4(uVar16,1);
  aiStack_5c[1] = *(undefined4 *)(iVar14 + 0x10);
  uVar16 = FUN_0010b180(*param_2,param_2[1]);
  iVar14 = FUN_0010b0f4(uVar16,2);
  aiStack_5c[2] = *(undefined4 *)(iVar14 + 0x10);
  uVar12 = param_2[1] & 0x80000001;
  if ((int)uVar12 < 0) {
    uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
  }
  iVar14 = FUN_0010b0f4(*param_2,uVar12 + 1);
  aiStack_5c[3] = *(undefined4 *)(iVar14 + 0x10);
  iVar14 = FUN_0010b0f4(*param_2,param_2[1]);
  aiStack_5c[1] = FUN_000f5610(aiStack_5c[1],*(undefined4 *)(iVar14 + 0x10));
  iVar14 = FUN_0010b0f4(*param_2,param_2[1]);
  aiStack_5c[2] = FUN_000f5610(aiStack_5c[2],*(undefined4 *)(iVar14 + 0x10));
  iVar14 = FUN_0010b180(*param_2,param_2[1]);
  local_28[3] = *(byte *)(iVar14 + 0xb8) & 1;
  iVar14 = FUN_0010b180(*param_2,param_2[1]);
  local_24 = (bool)(*(byte *)(iVar14 + 0xd0) & 1);
  uVar12 = param_2[1];
  iVar14 = *param_2;
  uVar15 = uVar12 & 0x80000001;
  if ((int)uVar15 < 0) {
    local_23 = *(byte *)(iVar14 + 0xb8 + ((uVar15 - 1 | 0xfffffffe) + 1) * 0x18);
  }
  else {
    local_23 = *(byte *)(iVar14 + 0xb8 + uVar15 * 0x18);
  }
  local_23 = local_23 & 1;
  if (!bVar21) {
    iVar10 = uVar12 * 0x18 + 0x80;
    local_28[3] = (*(byte *)(iVar14 + 0x20 + iVar10) & 1) != local_28[3];
    local_24 = (bool)(*(byte *)(iVar14 + 0x20 + iVar10) & 1) != local_24;
  }
  iVar14 = FUN_0010b180(iVar14,uVar12);
  local_28[0] = (byte)(*(uint *)(iVar14 + 0xb8) >> 1) & 1;
  iVar14 = FUN_0010b180(*param_2,param_2[1]);
  local_28[1] = (byte)(*(uint *)(iVar14 + 0xd0) >> 1) & 1;
  uVar12 = param_2[1] & 0x80000001;
  if ((int)uVar12 < 0) {
    uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
  }
  bVar7 = (byte)(*(uint *)(*param_2 + 0xb8 + uVar12 * 0x18) >> 1) & 1;
  local_28[2] = bVar7;
  local_60 = 0;
  iVar14 = local_60;
  do {
    local_60 = iVar14;
    iVar14 = local_60 + 1;
    iVar19 = iVar14 % 3;
    iVar10 = aiStack_5c[local_60 + 10];
    iVar17 = 0;
    do {
      iVar1 = iVar17 + 1;
      local_74 = iVar1 % 3;
      local_78 = iVar17;
      if ((iVar10 == aiStack_5c[iVar17 + 4]) &&
         (aiStack_5c[iVar19 + 10] == aiStack_5c[local_74 + 4])) {
        bVar3 = false;
LAB_0015c9ee:
        iVar17 = local_74;
        if (((bVar21) ||
            ((((local_28[local_78 + 6] == local_28[local_60] &&
               (local_28[local_74 + 6] == local_28[iVar19])) &&
              (local_28[local_78 + 9] == local_28[local_60 + 3])) &&
             (local_28[local_74 + 9] == local_28[iVar19 + 3])))) &&
           (((cVar5 = FUN_000f575e(aiStack_5c[local_78 + 7],aiStack_5c[iVar14]), cVar5 != '\0' &&
             (cVar5 = FUN_000f575e(aiStack_5c[local_74 + 7],aiStack_5c[iVar19 + 1]), cVar5 != '\0'))
            || ((cVar5 = FUN_000f575e(aiStack_5c[iVar14],aiStack_5c[local_78 + 7]), cVar5 != '\0' &&
                (cVar5 = FUN_000f575e(aiStack_5c[iVar19 + 1],aiStack_5c[local_74 + 7]),
                cVar5 != '\0')))))) {
          if (bVar3) {
            local_74 = local_78;
            local_78 = iVar17;
          }
          if (param_4 == '\0') {
            return 1;
          }
          bVar2 = true;
          goto LAB_0015c9be;
        }
      }
      else {
        if ((iVar10 == aiStack_5c[local_74 + 4]) &&
           (aiStack_5c[iVar17 + 4] == aiStack_5c[iVar19 + 10])) {
          bVar3 = true;
          local_78 = local_74;
          local_74 = iVar17;
          goto LAB_0015c9ee;
        }
        bVar3 = false;
      }
      iVar17 = iVar1;
    } while (iVar1 != 3);
    bVar2 = false;
LAB_0015c9be:
    if (iVar14 == 3) {
      if (!bVar2) {
        return 0;
      }
      break;
    }
  } while (!bVar2);
  if (local_60 == 2) {
    uVar16 = *(undefined4 *)(param_3 + 8);
    uVar18 = FUN_0010b180(*param_2,param_2[1]);
    FUN_0010ba02(uVar18,2,uVar13,1,uVar16);
    bVar4 = local_23;
    iVar14 = FUN_0010b180(*param_2,param_2[1]);
    FUN_00109c0e(iVar14 + 0xbc,1,bVar4);
    iVar14 = FUN_0010b180(*param_2,param_2[1]);
    FUN_00109c0e(iVar14 + 0xbc,2,bVar7);
    iVar14 = aiStack_5c[3];
    uVar13 = FUN_0010b180(*param_2,param_2[1]);
    iVar10 = FUN_0010b0f4(uVar13,2);
    bVar7 = local_28[3];
    *(int *)(iVar10 + 0x10) = iVar14;
    iVar14 = FUN_0010b180(*param_2,param_2[1]);
    FUN_00109c0e(iVar14 + 0xa4,1,bVar7);
    bVar7 = local_28[0];
    iVar14 = FUN_0010b180(*param_2,param_2[1]);
    FUN_00109c0e(iVar14 + 0xa4,2,bVar7);
    iVar14 = aiStack_5c[1];
    uVar13 = FUN_0010b180(*param_2,param_2[1]);
    iVar10 = FUN_0010b0f4(uVar13,1);
    *(int *)(iVar10 + 0x10) = iVar14;
    uVar12 = param_2[1] & 0x80000001;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
    }
    FUN_0010ba02(*param_2,uVar12 + 1,local_30,1,*(undefined4 *)(param_3 + 8));
    iVar14 = aiStack_5c[2];
    uVar12 = param_2[1] & 0x80000001;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
    }
    iVar10 = FUN_0010b0f4(*param_2,uVar12 + 1);
    *(int *)(iVar10 + 0x10) = iVar14;
    uVar12 = param_2[1] & 0x80000001;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
    }
    FUN_00109c0e(*param_2 + 0xa4 + uVar12 * 0x18,1,local_24);
    bVar7 = local_28[1];
LAB_0015d1ea:
    uVar12 = param_2[1] & 0x80000001;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
    }
    FUN_00109c0e(*param_2 + 0xa4 + uVar12 * 0x18,2,bVar7);
    if (!bVar21) {
      FUN_00109c0e(*param_2 + 0x8c + param_2[1] * 0x18,1,0);
    }
    iVar14 = FUN_0010b0f4(*param_2,0);
    uVar13 = FUN_000f5fea(*(undefined4 *)(iVar14 + 0x10));
    uVar13 = FUN_000f5b96(DAT_001cc5a0,uVar13);
    iVar14 = FUN_0010b0f4(*param_2,param_2[1]);
    *(undefined4 *)(iVar14 + 0x10) = uVar13;
  }
  else if (local_60 == 1) {
    uVar16 = *(undefined4 *)(param_3 + 8);
    uVar18 = FUN_0010b180(*param_2,param_2[1]);
    FUN_0010ba02(uVar18,1,uVar13,1,uVar16);
    bVar4 = local_23;
    iVar14 = FUN_0010b180(*param_2,param_2[1]);
    FUN_00109c0e(iVar14 + 0xa4,1,bVar4);
    iVar14 = FUN_0010b180(*param_2,param_2[1]);
    FUN_00109c0e(iVar14 + 0xa4,2,bVar7);
    iVar14 = aiStack_5c[3];
    uVar13 = FUN_0010b180(*param_2,param_2[1]);
    iVar10 = FUN_0010b0f4(uVar13,1);
    bVar2 = local_24;
    *(int *)(iVar10 + 0x10) = iVar14;
    iVar14 = FUN_0010b180(*param_2,param_2[1]);
    FUN_00109c0e(iVar14 + 0xbc,1,bVar2);
    bVar7 = local_28[1];
    iVar14 = FUN_0010b180(*param_2,param_2[1]);
    FUN_00109c0e(iVar14 + 0xbc,2,bVar7);
    iVar14 = aiStack_5c[2];
    uVar13 = FUN_0010b180(*param_2,param_2[1]);
    iVar10 = FUN_0010b0f4(uVar13,2);
    *(int *)(iVar10 + 0x10) = iVar14;
    uVar12 = param_2[1] & 0x80000001;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
    }
    FUN_0010ba02(*param_2,uVar12 + 1,local_34,1,*(undefined4 *)(param_3 + 8));
    iVar14 = aiStack_5c[1];
    uVar12 = param_2[1] & 0x80000001;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
    }
    iVar10 = FUN_0010b0f4(*param_2,uVar12 + 1);
    *(int *)(iVar10 + 0x10) = iVar14;
    uVar12 = param_2[1] & 0x80000001;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
    }
    FUN_00109c0e(*param_2 + 0xa4 + uVar12 * 0x18,1,local_28[3]);
    bVar7 = local_28[0];
    goto LAB_0015d1ea;
  }
  if (local_78 == 2) {
    uVar13 = *(undefined4 *)(param_3 + 8);
    uVar16 = FUN_0010b180(*param_1,param_1[1]);
    FUN_0010ba02(uVar16,2,uVar11,1,uVar13);
    bVar7 = local_1d;
    iVar14 = FUN_0010b180(*param_1,param_1[1]);
    FUN_00109c0e(iVar14 + 0xbc,1,bVar7);
    iVar14 = FUN_0010b180(*param_1,param_1[1]);
    FUN_00109c0e(iVar14 + 0xbc,2,bVar6);
    uVar11 = local_38;
    uVar13 = FUN_0010b180(*param_1,param_1[1]);
    iVar14 = FUN_0010b0f4(uVar13,2);
    bVar6 = local_22[3];
    *(undefined4 *)(iVar14 + 0x10) = uVar11;
    iVar14 = FUN_0010b180(*param_1,param_1[1]);
    FUN_00109c0e(iVar14 + 0xa4,1,bVar6);
    bVar6 = local_22[0];
    iVar14 = FUN_0010b180(*param_1,param_1[1]);
    FUN_00109c0e(iVar14 + 0xa4,2,bVar6);
    uVar11 = local_40;
    uVar13 = FUN_0010b180(*param_1,param_1[1]);
    iVar14 = FUN_0010b0f4(uVar13,1);
    *(undefined4 *)(iVar14 + 0x10) = uVar11;
    uVar12 = param_1[1] & 0x80000001;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
    }
    FUN_0010ba02(*param_1,uVar12 + 1,local_48,1,*(undefined4 *)(param_3 + 8));
    uVar11 = local_3c;
    uVar12 = param_1[1] & 0x80000001;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
    }
    iVar14 = FUN_0010b0f4(*param_1,uVar12 + 1);
    *(undefined4 *)(iVar14 + 0x10) = uVar11;
    uVar12 = param_1[1] & 0x80000001;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
    }
    FUN_00109c0e(*param_1 + 0xa4 + uVar12 * 0x18,1,local_1e);
    bVar6 = local_22[1];
LAB_0015d48d:
    uVar12 = param_1[1] & 0x80000001;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
    }
    FUN_00109c0e(*param_1 + 0xa4 + uVar12 * 0x18,2,bVar6);
    if (!bVar21) {
      FUN_00109c0e(*param_1 + 0x8c + param_1[1] * 0x18,1,0);
    }
    iVar14 = FUN_0010b0f4(*param_1,0);
    uVar11 = FUN_000f5fea(*(undefined4 *)(iVar14 + 0x10));
    uVar11 = FUN_000f5b96(DAT_001cc5a0,uVar11);
    iVar14 = FUN_0010b0f4(*param_1,param_1[1]);
    *(undefined4 *)(iVar14 + 0x10) = uVar11;
  }
  else if (local_78 == 1) {
    uVar13 = *(undefined4 *)(param_3 + 8);
    uVar16 = FUN_0010b180(*param_1,param_1[1]);
    FUN_0010ba02(uVar16,1,uVar11,1,uVar13);
    bVar7 = local_1d;
    iVar14 = FUN_0010b180(*param_1,param_1[1]);
    FUN_00109c0e(iVar14 + 0xa4,1,bVar7);
    iVar14 = FUN_0010b180(*param_1,param_1[1]);
    FUN_00109c0e(iVar14 + 0xa4,2,bVar6);
    uVar11 = local_38;
    uVar13 = FUN_0010b180(*param_1,param_1[1]);
    iVar14 = FUN_0010b0f4(uVar13,1);
    bVar2 = local_1e;
    *(undefined4 *)(iVar14 + 0x10) = uVar11;
    iVar14 = FUN_0010b180(*param_1,param_1[1]);
    FUN_00109c0e(iVar14 + 0xbc,1,bVar2);
    bVar6 = local_22[1];
    iVar14 = FUN_0010b180(*param_1,param_1[1]);
    FUN_00109c0e(iVar14 + 0xbc,2,bVar6);
    uVar11 = local_3c;
    uVar13 = FUN_0010b180(*param_1,param_1[1]);
    iVar14 = FUN_0010b0f4(uVar13,2);
    *(undefined4 *)(iVar14 + 0x10) = uVar11;
    uVar12 = param_1[1] & 0x80000001;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
    }
    FUN_0010ba02(*param_1,uVar12 + 1,local_4c,1,*(undefined4 *)(param_3 + 8));
    uVar11 = local_40;
    uVar12 = param_1[1] & 0x80000001;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
    }
    iVar14 = FUN_0010b0f4(*param_1,uVar12 + 1);
    *(undefined4 *)(iVar14 + 0x10) = uVar11;
    uVar12 = param_1[1] & 0x80000001;
    if ((int)uVar12 < 0) {
      uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
    }
    FUN_00109c0e(*param_1 + 0xa4 + uVar12 * 0x18,1,local_22[3]);
    bVar6 = local_22[0];
    goto LAB_0015d48d;
  }
  uVar11 = FUN_0010b180(*param_1,param_1[1]);
  iVar14 = FUN_0010b0f4(uVar11,1);
  uVar11 = *(undefined4 *)(iVar14 + 0x10);
  uVar13 = FUN_0010b180(*param_1,param_1[1]);
  iVar14 = FUN_0010b0f4(uVar13,2);
  uVar13 = *(undefined4 *)(iVar14 + 0x10);
  uVar16 = FUN_0010b180(*param_1,param_1[1]);
  FUN_0010b0f4(uVar16,0);
  if (((char)uVar11 == '\x04') && (local_68 = (char)uVar13, local_68 == '\x04')) {
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
  }
  if (((char)((uint)uVar11 >> 8) == '\x04') && ((char)((uint)uVar13 >> 8) == '\x04')) {
    uVar9 = 1;
  }
  else {
    uVar9 = 0;
  }
  if (((char)((uint)uVar11 >> 0x10) == '\x04') && ((char)((uint)uVar13 >> 0x10) == '\x04')) {
    iVar14 = 1;
  }
  else {
    iVar14 = 0;
  }
  if (((char)((uint)uVar11 >> 0x18) == '\x04') &&
     (local_68 = (char)((uint)uVar13 >> 0x18), local_68 == '\x04')) {
    iVar10 = 1;
  }
  else {
    iVar10 = 0;
  }
  iVar17 = FUN_0010b180(*param_1,param_1[1]);
  *(uint *)(iVar17 + 0x9c) = (uint)CONCAT11(uVar9,uVar8) | iVar14 << 0x10 | iVar10 << 0x18;
  uVar11 = FUN_0010b180(*param_2,param_2[1]);
  iVar14 = FUN_0010b0f4(uVar11,1);
  uVar11 = *(undefined4 *)(iVar14 + 0x10);
  uVar13 = FUN_0010b180(*param_2,param_2[1]);
  iVar14 = FUN_0010b0f4(uVar13,2);
  uVar13 = *(undefined4 *)(iVar14 + 0x10);
  uVar16 = FUN_0010b180(*param_2,param_2[1]);
  FUN_0010b0f4(uVar16,0);
  if (((char)uVar11 == '\x04') && (local_64 = (char)uVar13, local_64 == '\x04')) {
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
  }
  if (((char)((uint)uVar11 >> 8) == '\x04') && ((char)((uint)uVar13 >> 8) == '\x04')) {
    uVar9 = 1;
  }
  else {
    uVar9 = 0;
  }
  if (((char)((uint)uVar11 >> 0x10) == '\x04') && ((char)((uint)uVar13 >> 0x10) == '\x04')) {
    iVar14 = 1;
  }
  else {
    iVar14 = 0;
  }
  if (((char)((uint)uVar11 >> 0x18) == '\x04') &&
     (local_64 = (char)((uint)uVar13 >> 0x18), local_64 == '\x04')) {
    iVar10 = 1;
  }
  else {
    iVar10 = 0;
  }
  iVar17 = FUN_0010b180(*param_2,param_2[1]);
  *(uint *)(iVar17 + 0x9c) = (uint)CONCAT11(uVar9,uVar8) | iVar14 << 0x10 | iVar10 << 0x18;
  uVar11 = FUN_0010b180(*param_2,param_2[1]);
  FUN_001507b4(param_3,uVar11,param_3);
  uVar11 = FUN_0010b180(*param_1,param_1[1]);
  FUN_001507b4(param_3,uVar11,param_3);
  iVar14 = local_78;
  if (!bVar3) {
    iVar14 = local_74;
    local_74 = local_78;
  }
  if (param_5 == '\0') {
    return 1;
  }
  cVar5 = FUN_000f575e(aiStack_5c[local_74 + 7],aiStack_5c[local_60 + 1]);
  if ((cVar5 == '\0') ||
     (cVar5 = FUN_000f575e(aiStack_5c[iVar14 + 7],aiStack_5c[iVar19 + 1]), cVar5 == '\0')) {
    cVar5 = FUN_000f575e(aiStack_5c[local_60 + 1],aiStack_5c[local_74 + 7]);
    if ((cVar5 == '\0') ||
       (cVar5 = FUN_000f575e(aiStack_5c[iVar19 + 1],aiStack_5c[iVar14 + 7]), cVar5 == '\0')) {
      piVar20 = (int *)0x0;
      goto LAB_0015cdf3;
    }
    piVar20 = (int *)FUN_0010b180(*param_1,param_1[1]);
    uVar11 = *(undefined4 *)(param_3 + 8);
    uVar13 = FUN_0010b180(*param_2,param_2[1]);
    FUN_0010ba02(*param_1,param_1[1],uVar13,1,uVar11);
    iVar14 = FUN_0010b0f4(*param_2,param_2[1]);
    uVar11 = *(undefined4 *)(iVar14 + 0x10);
  }
  else {
    piVar20 = (int *)FUN_0010b180(*param_2,param_2[1]);
    uVar11 = *(undefined4 *)(param_3 + 8);
    uVar13 = FUN_0010b180(*param_1,param_1[1]);
    FUN_0010ba02(*param_2,param_2[1],uVar13,1,uVar11);
    iVar14 = FUN_0010b0f4(*param_1,param_1[1]);
    uVar11 = *(undefined4 *)(iVar14 + 0x10);
    param_1 = param_2;
  }
  iVar14 = FUN_0010b0f4(*param_1,param_1[1]);
  *(undefined4 *)(iVar14 + 0x10) = uVar11;
LAB_0015cdf3:
  cVar5 = FUN_0010a67e(piVar20,param_3);
  if (cVar5 == '\0') {
    return 1;
  }
  (**(code **)(*piVar20 + 0xc))(piVar20,1,*(undefined4 *)(param_3 + 8));
  return 1;
}

/* FUN_0015db8e @ 0x15db8e (315 bytes) */
int FUN_0015db8e(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  char cVar1;
  char cVar2;
  char cVar3;
  
  cVar1 = FUN_0015049a(param_1,param_3);
  cVar2 = FUN_0015049a(param_2,param_3);
  if (cVar1 != '\0') {
    cVar3 = ((int (*)())FUN_0015b788)(param_2,param_1,param_3,1,1);
    if (cVar3 != '\0') {
      FUN_0010b180(*param_1,param_1[1]);
      ((int (*)())FUN_0015b45c)();
      return;
    }
  }
  if (cVar2 != '\0') {
    cVar3 = ((int (*)())FUN_0015b788)(param_1,param_2,param_3,1,1);
    if (cVar3 != '\0') {
      FUN_0010b180(*param_1,param_1[1]);
      ((int (*)())FUN_0015b45c)();
      return;
    }
  }
  if ((cVar1 != '\0') && (cVar2 != '\0')) {
    cVar1 = ((int (*)())FUN_0015c402)(param_1,param_2,param_3,1,1);
    if (cVar1 != '\0') {
      FUN_0010b180(*param_1,param_1[1]);
      ((int (*)())FUN_0015b45c)();
      return;
    }
  }
  return;
}

/* FUN_0015dcca @ 0x15dcca (1186 bytes) */
int FUN_0015dcca(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  undefined4 param_3;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  uint local_24;
  int local_20;
  int aiStack_1c [4];
  
  *param_2 = 0;
  aiStack_1c[1] = FUN_0010b180(*param_1,3 - param_1[1]);
  uVar7 = FUN_0010b180(*param_1,param_1[1]);
  aiStack_1c[2] = FUN_0010b180(uVar7,1);
  uVar7 = FUN_0010b180(*param_1,param_1[1]);
  aiStack_1c[3] = FUN_0010b180(uVar7,2);
  iVar13 = 0;
  iVar11 = 1;
  do {
    cVar4 = FUN_0010a62e(aiStack_1c[iVar11],param_3);
    iVar13 = iVar13 + (uint)(cVar4 == '\0');
    iVar11 = iVar11 + 1;
  } while (iVar11 != 4);
  if (1 < iVar13) {
    iVar11 = *(int *)(*(int *)(*param_1 + 0x88) + 8);
    cVar4 = FUN_0015049a(param_1,param_3);
    local_20 = 1;
    do {
      iVar13 = aiStack_1c[local_20];
      cVar5 = FUN_0010a67e(iVar13,param_3);
      if ((cVar5 == '\0') && (cVar5 = FUN_0010a62e(iVar13,param_3), cVar5 == '\0')) {
        puVar12 = *(uint **)(iVar13 + 0x10);
        uVar1 = puVar12[1];
        if (0 < (int)uVar1) {
          local_24 = 0;
          while( true ) {
            if (local_24 < *puVar12) {
              uVar2 = puVar12[1];
              if (uVar2 <= local_24) {
                _memset((void *)(puVar12[2] + uVar2 * 4),0,(local_24 - uVar2) * 4 + 4);
                puVar12[1] = local_24 + 1;
              }
              iVar3 = *(int *)(puVar12[2] + local_24 * 4);
              iVar9 = *(int *)(*(int *)(iVar3 + 0x88) + 8);
            }
            else {
              piVar8 = (int *)FUN_001a7f7c(puVar12,local_24);
              iVar3 = *piVar8;
              iVar9 = *(int *)(*(int *)(iVar3 + 0x88) + 8);
            }
            if (((iVar11 == iVar9) && (iVar3 != *param_1)) &&
               (iVar9 = FUN_0010b180(*param_1,param_1[1]), iVar3 != iVar9)) {
              iVar9 = FUN_0010b180(iVar3,1);
              if ((iVar13 == iVar9) &&
                 (iVar9 = FUN_0010b180(iVar3,2), iVar11 == *(int *)(*(int *)(iVar9 + 0x88) + 8))) {
                uVar7 = FUN_0010b180(iVar3,2);
                uVar10 = FUN_0010b180(iVar3,1);
                cVar5 = FUN_0014fcd2(uVar10,uVar7,param_3);
                if (cVar5 != '\0') {
                  *param_2 = iVar3;
                  param_2[1] = 2;
                  cVar5 = FUN_0015049a(param_2,param_3);
                  if ((cVar4 != '\0') &&
                     (cVar6 = ((int (*)())FUN_0015b788)(param_2,param_1,param_3,0,0), cVar6 != '\0')) {
                    return;
                  }
                  if ((cVar5 != '\0') &&
                     (cVar6 = ((int (*)())FUN_0015b788)(param_1,param_2,param_3,0,0), cVar6 != '\0')) {
                    return;
                  }
                  if (((cVar4 != '\0') && (cVar5 != '\0')) &&
                     (cVar5 = ((int (*)())FUN_0015c402)(param_1,param_2,param_3,0,0), cVar5 != '\0')) {
                    return;
                  }
                }
              }
              iVar9 = FUN_0010b180(iVar3,2);
              if ((iVar13 == iVar9) &&
                 (iVar9 = FUN_0010b180(iVar3,1), iVar11 == *(int *)(*(int *)(iVar9 + 0x88) + 8))) {
                uVar7 = FUN_0010b180(iVar3,1);
                uVar10 = FUN_0010b180(iVar3,2);
                cVar5 = FUN_0014fcd2(uVar10,uVar7,param_3);
                if (cVar5 != '\0') {
                  *param_2 = iVar3;
                  param_2[1] = 1;
                  cVar5 = FUN_0015049a(param_2,param_3);
                  if ((cVar4 != '\0') &&
                     (cVar6 = ((int (*)())FUN_0015b788)(param_2,param_1,param_3,0,0), cVar6 != '\0')) {
                    return;
                  }
                  if ((cVar5 != '\0') &&
                     (cVar6 = ((int (*)())FUN_0015b788)(param_1,param_2,param_3,0,0), cVar6 != '\0')) {
                    return;
                  }
                  if (((cVar4 != '\0') && (cVar5 != '\0')) &&
                     (cVar5 = ((int (*)())FUN_0015c402)(param_1,param_2,param_3,0,0), cVar5 != '\0')) {
                    return;
                  }
                }
              }
            }
            local_24 = local_24 + 1;
            if (uVar1 == local_24) break;
            puVar12 = *(uint **)(iVar13 + 0x10);
          }
        }
      }
      local_20 = local_20 + 1;
    } while (local_20 != 4);
    *param_2 = 0;
  }
  return;
}

/* FUN_0015e16c @ 0x15e16c (461 bytes) */
int FUN_0015e16c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined1 local_1d;
  int local_1c [4];
  
  local_1c[2] = 0;
  local_1c[3] = 0;
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x12) {
    iVar1 = FUN_0010b180(param_1,1);
    if (*(int *)(*(int *)(iVar1 + 0x88) + 8) == 0x12) goto LAB_0015e2e6;
  }
  else if ((*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x13) &&
          (iVar1 = FUN_0010b180(param_1,1), *(int *)(*(int *)(iVar1 + 0x88) + 8) == 0x13)) {
LAB_0015e2e6:
    local_1c[3] = 1;
    local_1c[2] = param_1;
  }
  local_1c[0] = 0;
  local_1c[1] = 0;
  if (local_1c[2] != 0) {
    ((int (*)())FUN_0015dcca)(local_1c + 2,local_1c,param_2);
  }
  if (local_1c[0] == 0) {
    local_1d = 0;
    iVar1 = *(int *)(param_1 + 0x88);
    if (*(int *)(iVar1 + 8) == 0x12) goto LAB_0015e27e;
LAB_0015e20c:
    local_1c[2] = 0;
    if ((*(int *)(iVar1 + 8) != 0x13) ||
       (iVar1 = FUN_0010b180(param_1,2), *(int *)(*(int *)(iVar1 + 0x88) + 8) != 0x13))
    goto LAB_0015e216;
  }
  else {
    *(int *)(param_2 + 0x1f8) = *(int *)(param_2 + 0x1f8) + 1;
    ((int (*)())FUN_0015db8e)(local_1c,local_1c + 2,param_2);
    local_1d = 1;
    iVar1 = *(int *)(param_1 + 0x88);
    if (*(int *)(iVar1 + 8) != 0x12) goto LAB_0015e20c;
LAB_0015e27e:
    local_1c[2] = 0;
    iVar1 = FUN_0010b180(param_1,2);
    if (*(int *)(*(int *)(iVar1 + 0x88) + 8) != 0x12) goto LAB_0015e216;
  }
  local_1c[3] = 2;
  local_1c[2] = param_1;
LAB_0015e216:
  if ((local_1c[2] != 0) && (((int (*)())FUN_0015dcca)(local_1c + 2,local_1c,param_2), local_1c[0] != 0)) {
    *(int *)(param_2 + 0x1f8) = *(int *)(param_2 + 0x1f8) + 1;
    ((int (*)())FUN_0015db8e)(local_1c,local_1c + 2,param_2);
    return 1;
  }
  return local_1d;
}

/* FUN_0015e33a @ 0x15e33a (2007 bytes) */
int FUN_0015e33a(param_1, param_2)
  void *param_1;
  int param_2;
{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char cVar8;
  byte bVar9;
  char cVar10;
  int *piVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  uint uVar19;
  void *pvVar20;
  byte bVar21;
  int iVar22;
  int iVar23;
  longdouble lVar24;
  int local_a8;
  int local_98;
  int local_5c;
  undefined4 local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  iVar2 = *(int *)(param_2 + 8);
  if (((param_1 != (void *)0x0) && (*(int *)(*(int *)((int)param_1 + 0x88) + 8) == 0x12)) &&
     (*(int *)((int)param_1 + 0x124) == 0)) {
    local_98 = 1;
    local_a8 = 0x98;
    do {
      piVar11 = (int *)FUN_0010b180(param_1,local_98);
      cVar8 = (**(code **)(*piVar11 + 100))(piVar11);
      if (((cVar8 != '\0') && ((char)piVar11[0x48] == '\0')) &&
         (((*(byte *)((int)piVar11 + 0x15) & 2) == 0 && (piVar11[0x49] != 0)))) {
        lVar24 = (longdouble)FUN_0010fd78(piVar11[0x49]);
        local_3c = (float)lVar24;
        local_38 = (float)lVar24;
        local_34 = (float)lVar24;
        local_30 = (float)lVar24;
        iVar12 = FUN_0010b0f4(param_1,0);
        local_20[0] = *(undefined4 *)(iVar12 + 0x10);
        iVar12 = FUN_0010b0f4(param_1,0);
        uVar13 = FUN_000f5fea(*(undefined4 *)(iVar12 + 0x10));
        local_24 = FUN_000f5b96(DAT_001cc5a0,uVar13);
        iVar12 = (**(code **)(**(int **)(iVar2 + 0x54) + 0x154))
                           (*(int **)(iVar2 + 0x54),param_2,&local_3c,&local_24);
        if (iVar12 != 0) {
          iVar3 = *(int *)((int)param_1 + 4);
          iVar14 = FUN_00109e42(param_1,param_2);
          uVar1 = *(undefined1 *)((int)param_1 + 0x120);
          iVar15 = FUN_0010b0f4(param_1,0);
          uVar13 = *(undefined4 *)(iVar15 + 0x10);
          piVar16 = (int *)FUN_0010b180(piVar11,1);
          iVar15 = FUN_0010b0f4(piVar11,1);
          uVar17 = *(undefined4 *)(iVar15 + 0x10);
          iVar15 = FUN_0010b0f4(param_1,local_98);
          uVar17 = FUN_000f5610(uVar17,*(undefined4 *)(iVar15 + 0x10));
          uVar4 = piVar11[0x2e];
          uVar5 = *(uint *)(local_a8 + 0x20 + (int)param_1);
          if (((uVar4 & 2) == 0) && ((uVar5 & 2) == 0)) {
            local_40 = 0;
          }
          else {
            local_40 = 1;
          }
          iVar22 = (local_98 != 2) + 1;
          uVar18 = FUN_0010b180(param_1,iVar22);
          iVar15 = FUN_0010b0f4(param_1,iVar22);
          uVar6 = *(undefined4 *)(iVar15 + 0x10);
          uVar19 = *(uint *)((int)param_1 + iVar22 * 0x18 + 0xa0);
          bVar21 = (byte)uVar19 & 1;
          bVar9 = (byte)(uVar19 >> 1) & 1;
          uVar19 = *(uint *)((int)param_1 + 0x14);
          if ((uVar19 & 0x200) == 0) {
            local_5c = 0;
          }
          else {
            local_5c = FUN_0010b180(param_1,*(undefined4 *)((int)param_1 + 0x84));
            uVar19 = *(uint *)((int)param_1 + 0x14);
          }
          uVar7 = *(undefined4 *)((int)param_1 + 0x98);
          pvVar20 = (void *)FUN_0010a17a(0x14,*(undefined4 *)(param_2 + 8));
          *(undefined4 *)((int)pvVar20 + 0x94) = *(undefined4 *)((int)pvVar20 + 0x14c);
          *(undefined4 *)((int)pvVar20 + 0x98) = uVar7;
          if ((uVar19 & 2) != 0) {
            *(uint *)((int)pvVar20 + 0x14) = *(uint *)((int)pvVar20 + 0x14) | 2;
          }
          *(undefined4 *)((int)pvVar20 + 0xc) = *(undefined4 *)((int)param_1 + 0xc);
          *(undefined4 *)((int)pvVar20 + 0x9c) = uVar13;
          *(undefined1 *)((int)pvVar20 + 0x120) = uVar1;
          FUN_0010ba02(pvVar20,1,piVar16,0,iVar2);
          iVar15 = FUN_0010b0f4(pvVar20,1);
          *(undefined4 *)(iVar15 + 0x10) = uVar17;
          FUN_00109c0e((int)pvVar20 + 0xa4,1,((byte)uVar4 & 1) != ((byte)uVar5 & 1));
          FUN_00109c0e((int)pvVar20 + 0xa4,2,local_40);
          cVar8 = FUN_0010bc1e(pvVar20,2,iVar12,0,0,iVar2);
          uVar13 = local_24;
          iVar15 = FUN_0010b0f4(pvVar20,2);
          *(undefined4 *)(iVar15 + 0x10) = uVar13;
          FUN_0010ba02(pvVar20,2,iVar12,0,iVar2);
          cVar10 = FUN_0010bc1e(pvVar20,3,uVar18,bVar9,bVar21,iVar2);
          iVar15 = FUN_0010b0f4(pvVar20,3);
          *(undefined4 *)(iVar15 + 0x10) = uVar6;
          FUN_00109c0e((int)pvVar20 + 0xd4,1,bVar21);
          FUN_00109c0e((int)pvVar20 + 0xd4,2,bVar9);
          if (local_5c != 0) {
            FUN_0010c18e(pvVar20,local_5c,0,iVar2);
          }
          uVar13 = local_24;
          *(int *)((int)pvVar20 + 0x160) = iVar14 + *(int *)(param_2 + 0x46c);
          if (cVar10 != '\0' && cVar8 != '\0') {
            iVar14 = 1;
            do {
              if (*(char *)((int)local_20 + iVar14 + -1) == '\x01') {
                *(undefined1 *)(iVar14 + -1 + (int)&local_24) = 4;
              }
              iVar14 = iVar14 + 1;
            } while (iVar14 != 5);
            iVar14 = FUN_0010b0f4(pvVar20,2);
            *(undefined4 *)(iVar14 + 0x10) = uVar13;
            iVar14 = FUN_0010b0f4(iVar12,0);
            local_28 = *(undefined4 *)(iVar14 + 0x10);
            local_2c = local_24;
            iVar14 = 1;
            do {
              bVar9 = *(byte *)((int)&local_30 + iVar14 + 3);
              if (bVar9 != 4) {
                *(undefined1 *)((int)&local_28 + (uint)bVar9) = 0;
              }
              iVar14 = iVar14 + 1;
            } while (iVar14 != 5);
            *(undefined4 *)(iVar12 + 0x9c) = local_28;
            iVar14 = *(int *)(param_2 + 0x46c);
            cVar8 = (**(code **)(*piVar16 + 0x5c))(piVar16);
            if ((cVar8 == '\0') || (cVar8 = FUN_0010a62e(piVar11,param_2), cVar8 != '\0')) {
              if (iVar14 < piVar16[0x58]) {
                piVar16[0x58] = piVar16[0x58] + 1;
              }
              else {
                piVar16[0x58] = iVar14 + 1;
              }
            }
            else {
              iVar15 = FUN_0010a1c2(piVar16,*(undefined4 *)(param_2 + 8),0);
              *(undefined4 *)(iVar15 + 0x94) = *(undefined4 *)(iVar15 + 0x14c);
              *(undefined4 *)(iVar15 + 0x98) = 0x31;
              FUN_000e9596(piVar16[0x56],piVar16,iVar15);
              iVar23 = iVar14 + 1;
              *(int *)(iVar15 + 0x160) = iVar23;
              iVar22 = FUN_0010b180(iVar15,1);
              if (iVar14 < *(int *)(iVar22 + 0x160)) {
                *(int *)(iVar22 + 0x160) = *(int *)(iVar22 + 0x160) + 1;
              }
              else {
                *(int *)(iVar22 + 0x160) = iVar23;
              }
              if (1 < *(int *)(iVar15 + 0x84)) {
                iVar22 = FUN_0010b180(iVar15,2);
                if (iVar14 < *(int *)(iVar22 + 0x160)) {
                  *(int *)(iVar22 + 0x160) = *(int *)(iVar22 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar22 + 0x160) = iVar23;
                }
              }
              FUN_0010ba02(pvVar20,1,iVar15,0,iVar2);
            }
            if (iVar14 < *(int *)(iVar12 + 0x160)) {
              *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + 1;
            }
            else {
              *(int *)(iVar12 + 0x160) = iVar14 + 1;
            }
            FUN_001a7d72(param_1);
            _memcpy(param_1,pvVar20,0x164);
            FUN_000e9596(*(undefined4 *)(iVar3 + 0x158),iVar3,param_1);
            FUN_0010b3fe(piVar11,*(undefined4 *)(param_2 + 8));
            return 1;
          }
        }
      }
      local_98 = local_98 + 1;
      local_a8 = local_a8 + 0x18;
    } while (local_98 != 3);
  }
  return 0;
}

/* FUN_0015eb12 @ 0x15eb12 (81 bytes) */
int FUN_0015eb12(param_1)
  undefined4 param_1;
{
  undefined1 uVar1;
  int iVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  iVar2 = FUN_0010b0f4(param_1,0);
  uVar1 = FUN_000f7dda(param_1,1,*(undefined4 *)(iVar2 + 0x10),&local_1c);
  return uVar1;
}

/* FUN_0015eb64 @ 0x15eb64 (3348 bytes) */
int FUN_0015eb64(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  undefined1 uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  byte bVar14;
  uint uVar15;
  int iVar16;
  uint local_90;
  int local_84;
  char local_7d;
  byte local_7c;
  undefined4 local_5c;
  undefined4 local_58;
  uint local_54;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  cVar2 = (**(code **)(*param_1 + 100))(param_1);
  if ((cVar2 != '\0') && (cVar2 = (**(code **)(*param_2 + 100))(param_2), cVar2 != '\0')) {
    uVar6 = FUN_0010b180(param_2,1);
    uVar7 = FUN_0010b180(param_1,1);
    cVar2 = FUN_001503ee(uVar7,uVar6);
    if (cVar2 == '\0') {
      iVar8 = FUN_0010b180(param_1,1);
      iVar9 = FUN_0010b180(param_2,1);
      if (iVar8 != iVar9) {
        iVar8 = FUN_0010b0f4(param_1,1);
        uVar6 = *(undefined4 *)(iVar8 + 0x10);
        uVar7 = *(undefined4 *)(param_3 + 8);
        uVar10 = FUN_0010b180(param_1,1);
        cVar2 = FUN_0010a2a8(uVar10,uVar7,uVar6);
        iVar8 = FUN_0010b0f4(param_2,1);
        uVar6 = *(undefined4 *)(iVar8 + 0x10);
        uVar7 = *(undefined4 *)(param_3 + 8);
        uVar10 = FUN_0010b180(param_2,1);
        cVar3 = FUN_0010a2a8(uVar10,uVar7,uVar6);
        if ((cVar2 != '\0') || (cVar3 != '\0')) {
          if (((*(byte *)(param_2 + 0x2e) & 1) != (*(byte *)(param_1 + 0x2e) & 1)) &&
             ((cVar3 == '\0' || (cVar4 = ((int (*)())FUN_0015eb12)(param_2), cVar4 == '\0')))) {
            if (cVar2 == '\0') {
              return 0;
            }
            cVar4 = ((int (*)())FUN_0015eb12)(param_1);
            if (cVar4 == '\0') {
              return 0;
            }
            if ((((byte)((uint)param_1[0x2e] >> 1) & 1) != ((byte)((uint)param_2[0x2e] >> 1) & 1))
               && ((((param_1[0x2e] & 2U) == 0 || (cVar3 == '\0')) && ((param_2[0x2e] & 2U) == 0))))
            {
              return 0;
            }
          }
          if (((((char)param_2[0x48] == (char)param_1[0x48]) ||
               (((char)param_2[0x48] != '\0' && (cVar3 != '\0')))) ||
              (((char)param_1[0x48] != '\0' && (cVar2 != '\0')))) &&
             (((param_1[0x49] == param_2[0x49] ||
               ((cVar3 != '\0' && (cVar4 = ((int (*)())FUN_0015eb12)(param_2), cVar4 != '\0')))) ||
              ((cVar2 != '\0' && (cVar4 = ((int (*)())FUN_0015eb12)(param_1), cVar4 != '\0')))))) {
            iVar8 = FUN_0010b0f4(param_1,0);
            local_20 = *(undefined4 *)(iVar8 + 0x10);
            iVar8 = FUN_0010b0f4(param_2,0);
            local_24 = *(undefined4 *)(iVar8 + 0x10);
            iVar8 = 1;
            do {
              if ((*(char *)((int)&local_24 + iVar8 + 3) != '\x01') &&
                 (*(char *)((int)&local_28 + iVar8 + 3) != '\x01')) {
                return 0;
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 != 5);
            cVar4 = FUN_000e1402(*(undefined4 *)(param_3 + 8),0x30);
            if ((cVar4 == '\0') || (((*(unsigned char *)((unsigned char *)&(local_20) + 3)) != '\0' && ((*(unsigned char *)((unsigned char *)&(local_24) + 3)) != '\0')))) {
              local_84 = param_1[0x49];
              if (local_84 != param_2[0x49]) {
                if ((cVar3 == '\0') || (cVar4 = ((int (*)())FUN_0015eb12)(param_2), cVar4 == '\0')) {
                  local_84 = param_2[0x49];
                }
                else {
                  local_84 = param_1[0x49];
                }
              }
              local_7d = (char)param_1[0x48];
              if ((char)param_2[0x48] != local_7d) {
                if ((cVar3 == '\0') || (cVar4 = ((int (*)())FUN_0015eb12)(param_2), cVar4 == '\0')) {
                  local_7d = (char)param_2[0x48];
                }
                else {
                  local_7d = (char)param_1[0x48];
                }
              }
              local_90 = param_1[0x2e];
              local_7c = (byte)local_90 & 1;
              uVar15 = param_2[0x2e];
              if (local_7c != ((byte)uVar15 & 1)) {
                if ((cVar3 == '\0') || (cVar4 = ((int (*)())FUN_0015eb12)(param_2), cVar4 == '\0')) {
                  if ((cVar2 == '\0') || (cVar4 = ((int (*)())FUN_0015eb12)(param_1), cVar4 == '\0')) {
                    local_7c = 0;
                    local_90 = param_1[0x2e];
                    uVar15 = param_2[0x2e];
                  }
                  else {
                    uVar15 = param_2[0x2e];
                    local_7c = (byte)uVar15 & 1;
                    local_90 = param_1[0x2e];
                  }
                }
                else {
                  local_90 = param_1[0x2e];
                  local_7c = (byte)local_90 & 1;
                  uVar15 = param_2[0x2e];
                }
              }
              bVar14 = (byte)(local_90 >> 1) & 1;
              bVar5 = (byte)(uVar15 >> 1) & 1;
              if (((bVar14 != bVar5) && (cVar3 == '\0')) && (bVar14 = 0, cVar2 != '\0')) {
                bVar14 = bVar5;
              }
              iVar8 = FUN_0010b0f4(param_1,1);
              local_28 = *(undefined4 *)(iVar8 + 0x10);
              iVar8 = FUN_0010b0f4(param_2,1);
              local_2c = *(undefined4 *)(iVar8 + 0x10);
              local_30 = FUN_000f5892(local_24,local_20);
              piVar11 = (int *)FUN_0010f654(0xa2,*(undefined4 *)(param_3 + 8));
              piVar11[0x25] = piVar11[0x53];
              piVar11[0x26] = 0x36;
              piVar11[0x21] = 2;
              uVar6 = *(undefined4 *)(param_3 + 8);
              if (cVar3 == '\0') {
                uVar7 = FUN_0010b180(param_2,1);
              }
              else {
                uVar7 = FUN_0010b180(param_1,1);
              }
              FUN_0010ba02(piVar11,1,uVar7,0,uVar6);
              iVar8 = *(int *)(param_3 + 0x46c);
              iVar9 = FUN_0010b180(piVar11,1);
              if (iVar8 < *(int *)(iVar9 + 0x160)) {
                *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
              }
              else {
                *(int *)(iVar9 + 0x160) = iVar8 + 1;
              }
              uVar6 = *(undefined4 *)(param_3 + 8);
              if (cVar3 == '\0') {
                uVar7 = FUN_0010b180(param_1,1);
              }
              else {
                uVar7 = FUN_0010b180(param_2,1);
              }
              FUN_0010ba02(piVar11,2,uVar7,0,uVar6);
              iVar8 = *(int *)(param_3 + 0x46c);
              iVar9 = FUN_0010b180(piVar11,2);
              if (iVar8 < *(int *)(iVar9 + 0x160)) {
                *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
              }
              else {
                *(int *)(iVar9 + 0x160) = iVar8 + 1;
              }
              iVar8 = FUN_0010b180(param_1,1);
              *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + -1;
              FUN_0010ba02(param_1,1,piVar11,0,*(undefined4 *)(param_3 + 8));
              piVar11[0x58] = *(int *)(param_3 + 0x46c) + 1;
              piVar11[0x27] = DAT_001cc6d4;
              uVar6 = DAT_001cc5a4;
              iVar8 = FUN_0010b0f4(piVar11,1);
              *(undefined4 *)(iVar8 + 0x10) = uVar6;
              iVar8 = FUN_0010b0f4(piVar11,2);
              *(undefined4 *)(iVar8 + 0x10) = DAT_001cc5a0;
              iVar8 = FUN_0010b0f4(param_1,1);
              *(undefined4 *)(iVar8 + 0x10) = uVar6;
              if (cVar3 == '\0') {
                local_58 = 1;
                local_5c = 2;
              }
              else {
                local_58 = 2;
                local_5c = 1;
              }
              local_54 = 0;
              iVar8 = 0;
              do {
                iVar9 = FUN_0010b0f4(param_1,0);
                if ((*(char *)(iVar8 + 0x10 + iVar9) == '\0') &&
                   ((cVar2 == '\0' || (cVar3 != '\0')))) {
                  FUN_0010b0f4(param_2,0);
                  uVar15 = (uint)*(byte *)((int)&local_28 + iVar8);
                  (**(code **)(*piVar11 + 0x88))(piVar11,local_5c,uVar15,uVar15);
                  *(undefined1 *)(uVar15 + 0x9c + (int)piVar11) = 0;
                  (**(code **)(*piVar11 + 0x88))(piVar11,local_58,uVar15,4);
                  iVar9 = *param_1;
LAB_0015f219:
                  (**(code **)(iVar9 + 0x88))(param_1,1,iVar8,uVar15);
                  local_54 = local_54 | 1 << ((byte)uVar15 & 0x1f);
                }
                else {
                  iVar9 = FUN_0010b0f4(param_2,0);
                  if ((*(char *)(iVar8 + 0x10 + iVar9) == '\0') && (cVar3 == '\0')) {
                    uVar15 = (uint)*(byte *)((int)&local_2c + iVar8);
                    (**(code **)(*piVar11 + 0x88))(piVar11,local_58,uVar15,uVar15);
                    (**(code **)(*piVar11 + 0x88))(piVar11,local_5c,uVar15,4);
                    *(undefined1 *)(uVar15 + 0x9c + (int)piVar11) = 0;
                    iVar9 = *param_1;
                    goto LAB_0015f219;
                  }
                  (**(code **)(*piVar11 + 0x88))(piVar11,2,iVar8,4);
                }
                iVar8 = iVar8 + 1;
                if (iVar8 == 4) {
                  iVar8 = 0;
                  do {
                    if ((*(char *)((int)&local_30 + iVar8) == '\0') &&
                       (iVar9 = FUN_0010b0f4(param_1,1), *(char *)(iVar8 + 0x10 + iVar9) == '\x04'))
                    {
                      if ((local_54 & 1) == 0) {
                        iVar9 = 0;
                        uVar15 = 1;
                      }
                      else if ((local_54 & 2) == 0) {
                        iVar9 = 1;
                        uVar15 = 2;
                      }
                      else if ((local_54 & 4) == 0) {
                        iVar9 = 2;
                        uVar15 = 4;
                      }
                      else {
                        iVar9 = 3;
                        uVar15 = 0;
                      }
                      local_54 = local_54 ^ uVar15;
                      (**(code **)(*param_1 + 0x88))(param_1,1,iVar8,iVar9);
                      if (cVar3 == '\0') {
                        uVar1 = *(undefined1 *)((int)&local_28 + iVar8);
                      }
                      else {
                        uVar1 = *(undefined1 *)((int)&local_2c + iVar8);
                      }
                      (**(code **)(*piVar11 + 0x88))(piVar11,2,iVar9,uVar1);
                      *(undefined1 *)(iVar9 + 0x9c + (int)piVar11) = 0;
                    }
                    iVar8 = iVar8 + 1;
                  } while (iVar8 != 4);
                  FUN_000e956e(param_1[0x56],param_1,piVar11);
                  param_1[0x27] = local_30;
                  FUN_00109c0e(param_1 + 0x29,1,local_7c);
                  FUN_00109c0e(param_1 + 0x29,2,bVar14);
                  param_1[0x49] = local_84;
                  *(char *)(param_1 + 0x48) = local_7d;
                  FUN_0010ba02(param_1,param_1[0x21],0,0,*(undefined4 *)(param_3 + 8));
                  param_1[0x21] = param_1[0x21] + -1;
                  param_1[5] = param_1[5] & 0xfffffdff;
                  if ((*(byte *)((int)param_2 + 0x15) & 2) != 0) {
                    iVar8 = FUN_0010b180(param_2,param_2[0x21]);
                    local_48 = 0;
                    local_44 = 0;
                    local_34 = 0;
                    FUN_0010a980(param_2,&local_48);
                    FUN_0010c568(param_1,&local_48,0,*(undefined4 *)(param_3 + 8));
                    if (*(int *)(param_3 + 0x46c) < *(int *)(iVar8 + 0x160)) {
                      *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar8 + 0x160) = *(int *)(param_3 + 0x46c) + 1;
                    }
                  }
                  piVar12 = (int *)FUN_0010b180(piVar11,1);
                  cVar2 = (**(code **)(*piVar12 + 0x60))(piVar12);
                  if (cVar2 != '\0') {
                    uVar6 = *(undefined4 *)(param_3 + 8);
                    uVar7 = FUN_0010b180(piVar11,1);
                    FUN_00111842(uVar7,piVar11,uVar6);
                  }
                  FUN_0010b3fe(param_2,*(undefined4 *)(param_3 + 8));
                  if ((*(byte *)(param_2 + 5) & 1) != 0) {
                    piVar12 = (int *)FUN_0010b180(piVar11,1);
                    cVar2 = (**(code **)(*piVar12 + 0x5c))(piVar12);
                    if (cVar2 != '\0') {
                      uVar6 = *(undefined4 *)(param_3 + 8);
                      uVar7 = FUN_0010b180(piVar11,1);
                      iVar9 = FUN_0010a1c2(uVar7,uVar6,0);
                      iVar8 = *(int *)(param_3 + 0x46c);
                      *(undefined4 *)(iVar9 + 0x94) = *(undefined4 *)(iVar9 + 0x14c);
                      *(undefined4 *)(iVar9 + 0x98) = 0x31;
                      uVar6 = FUN_0010b180(piVar11,1);
                      iVar13 = FUN_0010b180(piVar11,1);
                      FUN_000e9596(*(undefined4 *)(iVar13 + 0x158),uVar6,iVar9);
                      iVar16 = iVar8 + 1;
                      *(int *)(iVar9 + 0x160) = iVar16;
                      iVar13 = FUN_0010b180(piVar11,1);
                      *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + -1;
                      iVar13 = FUN_0010b180(iVar9,1);
                      if (iVar8 < *(int *)(iVar13 + 0x160)) {
                        *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar13 + 0x160) = iVar16;
                      }
                      if (1 < *(int *)(iVar9 + 0x84)) {
                        iVar13 = FUN_0010b180(iVar9,2);
                        if (iVar8 < *(int *)(iVar13 + 0x160)) {
                          *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar13 + 0x160) = iVar16;
                        }
                      }
                      FUN_0010ba02(piVar11,1,iVar9,0,*(undefined4 *)(param_3 + 8));
                      return 1;
                    }
                  }
                  return 1;
                }
              } while( true );
            }
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_0015f878 @ 0x15f878 (2206 bytes) */
int FUN_0015f878(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *piVar10;
  int *piVar11;
  undefined1 uVar12;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  cVar3 = (**(code **)(*param_1 + 100))(param_1);
  if ((cVar3 != '\0') && (cVar3 = (**(code **)(*param_2 + 100))(param_2), cVar3 != '\0')) {
    uVar4 = FUN_0010b180(param_2,1);
    uVar5 = FUN_0010b180(param_1,1);
    cVar3 = FUN_001503ee(uVar5,uVar4);
    if (cVar3 == '\0') {
      iVar6 = FUN_0010b180(param_1,1);
      iVar7 = FUN_0010b180(param_2,1);
      if (((iVar6 != iVar7) && ((char)param_2[0x48] == (char)param_1[0x48])) &&
         (param_1[0x49] == param_2[0x49])) {
        iVar6 = FUN_0010b0f4(param_1,0);
        local_20 = *(undefined4 *)(iVar6 + 0x10);
        iVar6 = FUN_0010b0f4(param_1,param_1[0x21]);
        local_24 = FUN_000f5e2c(*(undefined4 *)(iVar6 + 0x10));
        iVar6 = FUN_0010b0f4(param_2,0);
        local_24 = FUN_000f5862(local_24,*(undefined4 *)(iVar6 + 0x10));
        iVar6 = 1;
        do {
          if ((*(char *)((int)&local_24 + iVar6 + 3) != '\x01') &&
             (*(char *)((int)&local_28 + iVar6 + 3) != '\x01')) {
            return 0;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 != 5);
        if ((local_24 != DAT_001cc6d4) &&
           ((cVar3 = FUN_000e1402(*(undefined4 *)(param_3 + 8),0x30), cVar3 == '\0' ||
            (((*(unsigned char *)((unsigned char *)&(local_20) + 3)) != '\0' && ((*(unsigned char *)((unsigned char *)&(local_24) + 3)) != '\0')))))) {
          local_28 = FUN_000f5892(local_24,local_20);
          iVar6 = FUN_0010b0f4(param_1,1);
          local_2c = *(undefined4 *)(iVar6 + 0x10);
          iVar6 = FUN_0010b0f4(param_2,1);
          local_30 = *(undefined4 *)(iVar6 + 0x10);
          local_38 = DAT_001cc6d4;
          local_50 = DAT_001cc5a4;
          iVar7 = 0;
          iVar6 = 1;
          local_4c = local_50;
          local_48 = local_50;
          local_44 = local_50;
          local_40 = local_50;
          local_3c = local_50;
          local_34 = local_38;
          do {
            if (*(char *)((int)&local_2c + iVar6 + 3) == '\0') {
              uVar12 = (undefined1)iVar7;
              if (*(char *)((int)&local_24 + iVar6 + 3) == '\0') {
                *(undefined1 *)((int)&local_40 + iVar6 + 3) =
                     *(undefined1 *)((int)&local_30 + iVar6 + 3);
                *(undefined1 *)((int)&local_4c + iVar6 + 3) = uVar12;
              }
              else if (*(char *)((int)&local_28 + iVar6 + 3) == '\0') {
                *(undefined1 *)((int)&local_44 + iVar6 + 3) = uVar12;
                *(undefined1 *)((int)&local_48 + iVar6 + 3) =
                     *(undefined1 *)((int)&local_34 + iVar6 + 3);
              }
              *(undefined1 *)((int)&local_38 + iVar6 + 3) = 0;
              *(undefined1 *)((int)&local_3c + iVar6 + 3) = 0;
              *(undefined1 *)((int)&local_50 + iVar6 + 3) = uVar12;
              *(undefined1 *)((int)&local_54 + iVar6 + 3) = uVar12;
            }
            iVar7 = iVar7 + 1;
            iVar6 = iVar6 + 1;
          } while (iVar7 != 4);
          uVar4 = *(undefined4 *)(param_3 + 8);
          uVar5 = FUN_0010b180(param_1,1);
          uVar8 = ((int (*)())FUN_00110f42)(2,local_34,uVar5,param_3,uVar4,0);
          uVar4 = *(undefined4 *)(param_3 + 8);
          uVar5 = FUN_0010b180(param_2,1);
          uVar9 = ((int (*)())FUN_00110f42)(2,local_38,uVar5,param_3,uVar4,0);
          uVar5 = local_3c;
          iVar6 = FUN_0010b0f4(uVar8,1);
          uVar4 = local_40;
          *(undefined4 *)(iVar6 + 0x10) = uVar5;
          iVar6 = FUN_0010b0f4(uVar8,2);
          uVar5 = local_44;
          *(undefined4 *)(iVar6 + 0x10) = uVar4;
          iVar6 = FUN_0010b0f4(uVar9,1);
          uVar4 = local_48;
          *(undefined4 *)(iVar6 + 0x10) = uVar5;
          iVar6 = FUN_0010b0f4(uVar9,2);
          *(undefined4 *)(iVar6 + 0x10) = uVar4;
          uVar1 = param_2[0x2e];
          local_74 = 0;
          local_70 = 0;
          local_60 = 0;
          if ((*(byte *)((int)param_2 + 0x15) & 2) != 0) {
            FUN_0010a980(param_2,&local_74);
          }
          iVar6 = param_1[0x49];
          uVar2 = param_1[0x2e];
          local_8c = 0;
          local_88 = 0;
          local_78 = 0;
          uVar4 = FUN_0010b0f4(param_1,1);
          FUN_0010a40a(&local_8c,uVar4);
          local_5c = 0;
          local_58 = 0;
          local_54 = 0;
          FUN_00109d1c(param_1,&local_5c,0xffffffff);
          iVar7 = param_1[1];
          FUN_001a7d72(param_1);
          FUN_0010d8fc(param_1,0x12,*(undefined4 *)(param_3 + 8));
          FUN_000e9596(*(undefined4 *)(iVar7 + 0x158),iVar7,param_1);
          FUN_00109d48(param_1,&local_5c);
          *(char *)(param_1 + 0x48) = (char)param_2[0x48];
          param_1[0x49] = iVar6;
          uVar4 = FUN_0010b0f4(param_1,1);
          FUN_0010a40a(uVar4,&local_8c);
          FUN_0010b85e(param_1,2,param_2,1);
          param_1[0x25] = param_1[0x53];
          param_1[0x26] = 0;
          param_1[0x27] = local_28;
          FUN_0010ba02(param_1,1,uVar8,0,*(undefined4 *)(param_3 + 8));
          FUN_00109c0e(param_1 + 0x29,1,(byte)uVar2 & 1);
          FUN_00109c0e(param_1 + 0x29,2,(byte)(uVar2 >> 1) & 1);
          uVar4 = local_4c;
          iVar6 = FUN_0010b0f4(param_1,1);
          *(undefined4 *)(iVar6 + 0x10) = uVar4;
          FUN_0010ba02(param_1,2,uVar9,0,*(undefined4 *)(param_3 + 8));
          FUN_00109c0e(param_1 + 0x2f,1,(byte)uVar1 & 1);
          FUN_00109c0e(param_1 + 0x2f,2,(byte)(uVar1 >> 1) & 1);
          uVar4 = local_50;
          iVar6 = FUN_0010b0f4(param_1,2);
          *(undefined4 *)(iVar6 + 0x10) = uVar4;
          FUN_000e956e(param_1[0x56],param_1,uVar9);
          FUN_000e956e(param_1[0x56],param_1,uVar8);
          if (local_70 != 0) {
            FUN_0010c568(param_1,&local_74,0,*(undefined4 *)(param_3 + 8));
            if (*(int *)(param_3 + 0x46c) < *(int *)(local_70 + 0x160)) {
              *(int *)(local_70 + 0x160) = *(int *)(local_70 + 0x160) + 1;
            }
            else {
              *(int *)(local_70 + 0x160) = *(int *)(param_3 + 0x46c) + 1;
            }
          }
          cVar3 = (**(code **)(*param_2 + 0x60))(param_2);
          piVar11 = param_2;
          if (cVar3 != '\0') {
            piVar11 = (int *)FUN_0010b180(param_2,1);
          }
          uVar4 = FUN_0010b180(piVar11,1);
          piVar10 = (int *)FUN_00110110(uVar4,param_3,0);
          cVar3 = (**(code **)(*piVar10 + 0x5c))(piVar10);
          if (cVar3 == '\0') {
            iVar6 = *(int *)(param_3 + 0x46c);
            iVar7 = FUN_0010b180(param_2,1);
            if (iVar6 < *(int *)(iVar7 + 0x160)) {
              *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
            }
            else {
              *(int *)(iVar7 + 0x160) = iVar6 + 1;
            }
          }
          else {
            FUN_0010ba02(piVar11,1,piVar10,0,*(undefined4 *)(param_3 + 8));
            if (*(int *)(param_3 + 0x46c) < piVar10[0x58]) {
              piVar10[0x58] = piVar10[0x58] + 1;
            }
            else {
              piVar10[0x58] = *(int *)(param_3 + 0x46c) + 1;
            }
          }
          piVar11 = (int *)FUN_0010b180(uVar8,1);
          cVar3 = (**(code **)(*piVar11 + 0x60))(piVar11);
          if (cVar3 != '\0') {
            uVar4 = *(undefined4 *)(param_3 + 8);
            uVar5 = FUN_0010b180(uVar8,1);
            FUN_00111842(uVar5,uVar8,uVar4);
          }
          piVar11 = (int *)FUN_0010b180(uVar9,1);
          cVar3 = (**(code **)(*piVar11 + 0x60))(piVar11);
          if (cVar3 != '\0') {
            uVar4 = *(undefined4 *)(param_3 + 8);
            uVar5 = FUN_0010b180(uVar9,1);
            FUN_00111842(uVar5,uVar9,uVar4);
          }
          FUN_0010b3fe(param_2,*(undefined4 *)(param_3 + 8));
          return 1;
        }
      }
    }
  }
  return 0;
}

/* FUN_0016011e @ 0x16011e (3095 bytes) */
int FUN_0016011e(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  int *piVar13;
  uint uVar14;
  int local_ac;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_60;
  undefined4 local_5c;
  int *local_58;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  cVar1 = (**(code **)(*param_1 + 100))(param_1);
  if ((cVar1 != '\0') && (cVar1 = (**(code **)(*param_2 + 100))(param_2), cVar1 != '\0')) {
    uVar2 = FUN_0010b180(param_2,1);
    uVar3 = FUN_0010b180(param_1,1);
    cVar1 = FUN_001503ee(uVar3,uVar2);
    if (cVar1 == '\0') {
      iVar4 = FUN_0010b180(param_1,1);
      iVar5 = FUN_0010b180(param_2,1);
      if (iVar4 != iVar5) {
        iVar4 = FUN_0010b0f4(param_1,0);
        local_20 = *(undefined4 *)(iVar4 + 0x10);
        iVar4 = FUN_0010b0f4(param_2,0);
        local_24 = *(undefined4 *)(iVar4 + 0x10);
        iVar4 = 1;
        do {
          if ((*(char *)((int)&local_24 + iVar4 + 3) != '\x01') &&
             (*(char *)((int)&local_28 + iVar4 + 3) != '\x01')) {
            return 0;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 != 5);
        cVar1 = FUN_000e1402(*(undefined4 *)(param_3 + 8),0x30);
        if ((cVar1 == '\0') || (((*(unsigned char *)((unsigned char *)&(local_20) + 3)) != '\0' && ((*(unsigned char *)((unsigned char *)&(local_24) + 3)) != '\0')))) {
          iVar4 = FUN_0010b0f4(param_1,1);
          local_28 = *(undefined4 *)(iVar4 + 0x10);
          iVar4 = FUN_0010b0f4(param_2,1);
          local_2c = *(undefined4 *)(iVar4 + 0x10);
          local_5c = 0;
          local_58 = (int *)0x0;
          local_48 = 0;
          if ((*(byte *)((int)param_2 + 0x15) & 2) != 0) {
            FUN_0010a980(param_2,&local_5c);
          }
          piVar13 = local_58;
          if (local_58 == (int *)0x0) {
            local_ac = DAT_001cc6d4;
          }
          else {
            iVar4 = FUN_0010b0f4(local_58,0);
            local_ac = *(int *)(iVar4 + 0x10);
          }
          if ((((piVar13 != (int *)0x0) && (param_1[0x49] == 0)) &&
              ((cVar1 = (**(code **)(*piVar13 + 100))(piVar13), cVar1 != '\0' ||
               (cVar1 = FUN_0010a62e(piVar13,param_3), cVar1 == '\0')))) &&
             ((((local_ac != DAT_001cc5a8 && ((*(byte *)((int)piVar13 + 0x15) & 2) == 0)) &&
               (cVar1 = FUN_000f5f28(local_ac), cVar1 != '\0')) &&
              ((cVar1 = FUN_000f5f28(local_20), cVar1 != '\0' &&
               (cVar1 = FUN_000f5f28(local_24), cVar1 != '\0')))))) {
            if (((((byte)param_1[0x2e] & 1) == ((byte)param_2[0x2e] & 1)) &&
                ((((byte)((uint)param_1[0x2e] >> 1) & 1) == ((byte)((uint)param_2[0x2e] >> 1) & 1)
                 && ((char)param_2[0x48] == (char)param_1[0x48])))) &&
               (param_1[0x49] == param_2[0x49])) {
              iVar4 = FUN_000f5ede(local_20);
              iVar5 = FUN_000f5ede(local_24);
              uVar6 = FUN_000f5ede(local_ac);
              iVar7 = FUN_000f5892(local_24,local_20);
              local_30 = iVar7;
              iVar8 = FUN_0010b0f4(piVar13,0);
              FUN_000f58e8(*(undefined4 *)(iVar8 + 0x10),iVar7);
              local_30 = FUN_000f5892(local_ac,local_30);
              uVar2 = *(undefined4 *)(param_3 + 8);
              uVar3 = FUN_0010b180(param_2,1);
              piVar9 = (int *)((int (*)())FUN_00110f42)(3,local_30,uVar3,param_3,uVar2,0x3f800000);
              uVar2 = *(undefined4 *)(param_3 + 8);
              uVar3 = FUN_0010b180(param_1,1);
              piVar10 = (int *)((int (*)())FUN_00110f42)(3,local_30,uVar3,param_3,uVar2,0x3f800000);
              piVar11 = (int *)((int (*)())FUN_00110f42)(2,local_30,piVar13,param_3,*(undefined4 *)(param_3 + 8),
                                            0);
              if (*(int *)(param_3 + 0x46c) < piVar13[0x58]) {
                piVar13[0x58] = piVar13[0x58] + 1;
              }
              else {
                piVar13[0x58] = *(int *)(param_3 + 0x46c) + 1;
              }
              local_38 = DAT_001cc6d4;
              uVar14 = DAT_001cc5a0 & 0xffffff;
              uVar12 = (uint)*(byte *)((int)&local_28 + iVar4);
              local_34 = local_38;
              *(undefined1 *)((int)&local_34 + uVar12) = 0;
              (**(code **)(*piVar10 + 0x88))(piVar10,1,uVar12,uVar12);
              uVar12 = (uint)*(byte *)((int)&local_2c + iVar5);
              *(undefined1 *)((int)&local_38 + uVar12) = 0;
              (**(code **)(*piVar9 + 0x88))(piVar9,1,uVar12,uVar12);
              (**(code **)(*piVar11 + 0x88))(piVar11,1,uVar6,uVar6);
              (**(code **)(*piVar11 + 0x88))(piVar11,2,iVar4,iVar4);
              (**(code **)(*piVar11 + 0x88))(piVar11,2,iVar5,iVar5);
              local_8c = 0xffffffff;
              local_88 = 0xffffffff;
              local_84 = 0xffffffff;
              local_80 = 0xffffffff;
              uVar12 = 0;
              do {
                iVar4 = FUN_0010b0f4(piVar10,1);
                if (uVar12 != *(byte *)(uVar12 + 0x10 + iVar4)) {
                  if (((int)local_8c < 0) && (uVar6 != uVar12)) {
                    (**(code **)(*piVar10 + 0x88))(piVar10,2,uVar12,uVar12);
                    *(undefined1 *)((int)&local_34 + uVar12) = 0;
                    local_8c = uVar12;
                  }
                  else if ((int)local_88 < 0) {
                    (**(code **)(*piVar10 + 0x88))(piVar10,3,uVar12,uVar12);
                    *(undefined1 *)((int)&local_34 + uVar12) = 0;
                    local_88 = uVar12;
                  }
                }
                iVar4 = FUN_0010b0f4(piVar9,1);
                if (uVar12 != *(byte *)(uVar12 + 0x10 + iVar4)) {
                  if (((int)local_84 < 0) && (uVar6 != uVar12)) {
                    (**(code **)(*piVar9 + 0x88))(piVar9,2,uVar12,uVar12);
                    *(undefined1 *)((int)&local_38 + uVar12) = 0;
                    local_84 = uVar12;
                  }
                  else if ((int)local_80 < 0) {
                    (**(code **)(*piVar9 + 0x88))(piVar9,3,uVar12,uVar12);
                    *(undefined1 *)((int)&local_38 + uVar12) = 0;
                    local_80 = uVar12;
                  }
                }
                uVar12 = uVar12 + 1;
              } while (uVar12 != 4);
              piVar10[0x27] = local_34;
              piVar9[0x27] = local_38;
              local_74 = 0;
              local_70 = 0;
              local_60 = 0;
              uVar2 = FUN_0010b0f4(param_1,1);
              FUN_0010a40a(&local_74,uVar2);
              local_44 = 0;
              local_40 = 0;
              local_3c = 0;
              FUN_00109d1c(param_1,&local_44,0xffffffff);
              iVar4 = param_1[1];
              FUN_001a7d72(param_1);
              FUN_0010da48(param_1,0x14,*(undefined4 *)(param_3 + 8));
              FUN_000e9596(*(undefined4 *)(iVar4 + 0x158),iVar4,param_1);
              FUN_00109d48(param_1,&local_44);
              *(char *)(param_1 + 0x48) = (char)param_2[0x48];
              param_1[0x49] = 0;
              param_1[0x25] = param_1[0x53];
              param_1[0x26] = 0;
              param_1[0x27] = local_30;
              uVar2 = FUN_0010b0f4(param_1,1);
              FUN_0010a40a(uVar2,&local_74);
              FUN_0010ba02(param_1,1,piVar10,0,*(undefined4 *)(param_3 + 8));
              FUN_00109c0e(param_1 + 0x29,1,*(byte *)(param_2 + 0x2e) & 1);
              FUN_0010b85e(param_1,2,param_2,1);
              FUN_0010ba02(param_1,2,piVar9,0,*(undefined4 *)(param_3 + 8));
              FUN_00109c0e(param_1 + 0x2f,1,0);
              FUN_0010ba02(param_1,3,piVar11,0,*(undefined4 *)(param_3 + 8));
              iVar4 = FUN_0010b0f4(param_1,3);
              *(uint *)(iVar4 + 0x10) = uVar14 | 0x4000000;
              iVar4 = 0;
              do {
                iVar5 = FUN_0010b0f4(param_1,1);
                if (*(char *)(iVar4 + 0x10 + iVar5) == '\x04') {
                  iVar5 = FUN_0010b0f4(param_1,2);
                  if (*(char *)(iVar4 + 0x10 + iVar5) == '\x04') {
                    if (*(char *)((int)&local_30 + iVar4) == '\0') {
                      (**(code **)(*param_1 + 0x88))(param_1,1,iVar4,local_88);
                    }
                  }
                  else {
                    (**(code **)(*param_1 + 0x88))(param_1,1,iVar4,local_8c);
                  }
                }
                iVar5 = FUN_0010b0f4(param_1,2);
                if (*(char *)(iVar4 + 0x10 + iVar5) == '\x04') {
                  iVar5 = FUN_0010b0f4(param_1,1);
                  if (*(char *)(iVar4 + 0x10 + iVar5) == '\x04') {
                    if (*(char *)((int)&local_30 + iVar4) == '\0') {
                      (**(code **)(*param_1 + 0x88))(param_1,2,iVar4,local_80);
                    }
                  }
                  else {
                    (**(code **)(*param_1 + 0x88))(param_1,2,iVar4,local_84);
                  }
                }
                iVar4 = iVar4 + 1;
              } while (iVar4 != 4);
              FUN_000e956e(param_1[0x56],param_1,piVar9);
              FUN_000e956e(param_1[0x56],param_1,piVar10);
              FUN_000e956e(param_1[0x56],param_1,piVar11);
              cVar1 = (**(code **)(*param_2 + 0x60))(param_2);
              piVar13 = param_2;
              if (cVar1 != '\0') {
                piVar13 = (int *)FUN_0010b180(param_2,1);
              }
              uVar2 = FUN_0010b180(piVar13,1);
              piVar11 = (int *)FUN_00110110(uVar2,param_3,0);
              cVar1 = (**(code **)(*piVar11 + 0x5c))(piVar11);
              if (cVar1 == '\0') {
                iVar4 = *(int *)(param_3 + 0x46c);
                iVar5 = FUN_0010b180(param_2,1);
                if (iVar4 < *(int *)(iVar5 + 0x160)) {
                  *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar5 + 0x160) = iVar4 + 1;
                }
              }
              else {
                FUN_0010ba02(piVar13,1,piVar11,0,*(undefined4 *)(param_3 + 8));
                if (*(int *)(param_3 + 0x46c) < piVar11[0x58]) {
                  piVar11[0x58] = piVar11[0x58] + 1;
                }
                else {
                  piVar11[0x58] = *(int *)(param_3 + 0x46c) + 1;
                }
              }
              piVar13 = (int *)FUN_0010b180(piVar10,1);
              cVar1 = (**(code **)(*piVar13 + 0x60))(piVar13);
              if (cVar1 != '\0') {
                uVar2 = *(undefined4 *)(param_3 + 8);
                uVar3 = FUN_0010b180(piVar10,1);
                FUN_00111842(uVar3,piVar10,uVar2);
              }
              piVar13 = (int *)FUN_0010b180(piVar9,1);
              cVar1 = (**(code **)(*piVar13 + 0x60))(piVar13);
              if (cVar1 != '\0') {
                uVar2 = *(undefined4 *)(param_3 + 8);
                uVar3 = FUN_0010b180(piVar9,1);
                FUN_00111842(uVar3,piVar9,uVar2);
              }
              FUN_0010b3fe(param_2,*(undefined4 *)(param_3 + 8));
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_00160d3e @ 0x160d3e (3057 bytes) */
int FUN_00160d3e(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  bool bVar12;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  uint local_8c;
  uint local_88;
  int *local_84;
  int local_80;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_60;
  undefined4 local_5c;
  int *local_58;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  cVar2 = (**(code **)(*param_1 + 100))(param_1);
  if ((cVar2 != '\0') && (cVar2 = (**(code **)(*param_2 + 100))(param_2), cVar2 != '\0')) {
    uVar3 = FUN_0010b180(param_2,1);
    uVar4 = FUN_0010b180(param_1,1);
    cVar2 = FUN_001503ee(uVar4,uVar3);
    if (cVar2 == '\0') {
      iVar5 = FUN_0010b180(param_1,1);
      iVar6 = FUN_0010b180(param_2,1);
      if (iVar5 != iVar6) {
        iVar5 = FUN_0010b0f4(param_1,0);
        local_20 = *(undefined4 *)(iVar5 + 0x10);
        iVar5 = FUN_0010b0f4(param_2,0);
        local_24 = *(undefined4 *)(iVar5 + 0x10);
        uVar3 = local_24;
        iVar6 = 1;
        do {
          if ((*(char *)((int)&local_24 + iVar6 + 3) != '\x01') &&
             (*(char *)((int)&local_28 + iVar6 + 3) != '\x01')) {
            return 0;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 != 5);
        if (((*(unsigned char *)((unsigned char *)&(local_20) + 3)) != '\0') &&
           ((*(unsigned char *)((unsigned char *)&(local_24) + 3)) = (char)((uint)*(undefined4 *)(iVar5 + 0x10) >> 0x18),
           (*(unsigned char *)((unsigned char *)&(local_24) + 3)) != '\0')) {
          local_24 = uVar3;
          iVar5 = FUN_0010b0f4(param_1,1);
          local_28 = *(undefined4 *)(iVar5 + 0x10);
          iVar5 = FUN_0010b0f4(param_2,1);
          local_2c = *(undefined4 *)(iVar5 + 0x10);
          local_5c = 0;
          local_58 = (int *)0x0;
          local_48 = 0;
          if ((*(byte *)((int)param_2 + 0x15) & 2) != 0) {
            FUN_0010a980(param_2,&local_5c);
          }
          piVar10 = local_58;
          bVar12 = local_58 != (int *)0x0;
          iVar5 = DAT_001cc6d4;
          if (bVar12) {
            iVar5 = FUN_0010b0f4(local_58,0);
            iVar5 = *(int *)(iVar5 + 0x10);
          }
          iVar6 = param_1[0x49];
          if ((((piVar10 == (int *)0x0) || (iVar6 != 0)) ||
              ((cVar2 = (**(code **)(*piVar10 + 100))(piVar10), cVar2 == '\0' &&
               (cVar2 = FUN_0010a62e(piVar10,param_3), cVar2 != '\0')))) ||
             ((((iVar5 == DAT_001cc5a8 || (cVar2 = FUN_000f5f28(iVar5), cVar2 == '\0')) ||
               (cVar2 = FUN_000f5f28(local_20), cVar2 == '\0')) ||
              (cVar2 = FUN_000f5f28(local_24), cVar2 == '\0')))) {
            if (((((byte)param_1[0x2e] & 1) == ((byte)param_2[0x2e] & 1)) &&
                (((byte)((uint)param_1[0x2e] >> 1) & 1) == ((byte)((uint)param_2[0x2e] >> 1) & 1)))
               && (((char)param_2[0x48] == (char)param_1[0x48] && (param_1[0x49] == param_2[0x49])))
               ) {
              local_30 = FUN_000f5892(local_24,local_20);
              local_a4 = -1;
              local_a0 = -1;
              local_9c = -1;
              local_98 = -1;
              iVar5 = 0;
              do {
                iVar11 = local_a4;
                iVar1 = local_9c;
                if (*(char *)((int)&local_20 + iVar5) == '\0') {
                  iVar11 = iVar5;
                  if ((-1 < local_a4) && (iVar11 = local_a4, local_a0 < 0)) {
                    local_a0 = iVar5;
                  }
                }
                else if (((*(char *)((int)&local_24 + iVar5) == '\0') &&
                         (iVar1 = iVar5, -1 < local_9c)) && (iVar1 = local_9c, local_98 < 0)) {
                  local_98 = iVar5;
                }
                local_9c = iVar1;
                local_a4 = iVar11;
                iVar5 = iVar5 + 1;
              } while (iVar5 != 4);
              uVar3 = *(undefined4 *)(param_3 + 8);
              uVar4 = FUN_0010b180(param_2,1);
              piVar7 = (int *)((int (*)())FUN_00110f42)(3,local_30,uVar4,param_3,uVar3,0x3f800000);
              uVar3 = *(undefined4 *)(param_3 + 8);
              uVar4 = FUN_0010b180(param_1,1);
              piVar8 = (int *)((int (*)())FUN_00110f42)(3,local_30,uVar4,param_3,uVar3,0x3f800000);
              local_38 = DAT_001cc6d4;
              uVar9 = (uint)*(byte *)((int)&local_28 + local_a4);
              local_34 = local_38;
              *(undefined1 *)((int)&local_34 + uVar9) = 0;
              (**(code **)(*piVar8 + 0x88))(piVar8,1,uVar9,uVar9);
              if (-1 < local_a0) {
                uVar9 = (uint)*(byte *)((int)&local_28 + local_a0);
                *(undefined1 *)((int)&local_34 + uVar9) = 0;
                (**(code **)(*piVar8 + 0x88))(piVar8,1,uVar9,uVar9);
              }
              uVar9 = (uint)*(byte *)((int)&local_2c + local_9c);
              *(undefined1 *)((int)&local_38 + uVar9) = 0;
              (**(code **)(*piVar7 + 0x88))(piVar7,1,uVar9,uVar9);
              if (-1 < local_98) {
                uVar9 = (uint)*(byte *)((int)&local_2c + local_98);
                *(undefined1 *)((int)&local_38 + uVar9) = 0;
                (**(code **)(*piVar7 + 0x88))(piVar7,1,uVar9,uVar9);
              }
              local_8c = 0xffffffff;
              local_88 = 0xffffffff;
              uVar9 = 0;
              do {
                iVar5 = FUN_0010b0f4(piVar8,1);
                if ((*(byte *)(uVar9 + 0x10 + iVar5) != uVar9) && ((int)local_8c < 0)) {
                  (**(code **)(*piVar8 + 0x88))(piVar8,2,uVar9,uVar9);
                  *(undefined1 *)((int)&local_34 + uVar9) = 0;
                  local_8c = uVar9;
                }
                iVar5 = FUN_0010b0f4(piVar7,1);
                if ((*(byte *)(uVar9 + 0x10 + iVar5) != uVar9) && ((int)local_88 < 0)) {
                  (**(code **)(*piVar7 + 0x88))(piVar7,2,uVar9,uVar9);
                  *(undefined1 *)((int)&local_38 + uVar9) = 0;
                  local_88 = uVar9;
                }
                uVar9 = uVar9 + 1;
              } while (uVar9 != 4);
              piVar8[0x27] = local_34;
              piVar7[0x27] = local_38;
              local_74 = 0;
              local_70 = 0;
              local_60 = 0;
              uVar3 = FUN_0010b0f4(param_1,1);
              FUN_0010a40a(&local_74,uVar3);
              local_44 = 0;
              local_40 = 0;
              local_3c = 0;
              FUN_00109d1c(param_1,&local_44,0xffffffff);
              iVar5 = param_1[1];
              FUN_001a7d72(param_1);
              FUN_0010d8fc(param_1,0x13,*(undefined4 *)(param_3 + 8));
              FUN_000e9596(*(undefined4 *)(iVar5 + 0x158),iVar5,param_1);
              FUN_00109d48(param_1,&local_44);
              *(char *)(param_1 + 0x48) = (char)param_2[0x48];
              param_1[0x49] = iVar6;
              param_1[0x25] = param_1[0x53];
              param_1[0x26] = 0;
              param_1[0x27] = local_30;
              uVar3 = FUN_0010b0f4(param_1,1);
              FUN_0010a40a(uVar3,&local_74);
              FUN_0010ba02(param_1,1,piVar8,0,*(undefined4 *)(param_3 + 8));
              FUN_00109c0e(param_1 + 0x29,1,*(byte *)(param_2 + 0x2e) & 1);
              FUN_0010b85e(param_1,2,param_2,1);
              FUN_0010ba02(param_1,2,piVar7,0,*(undefined4 *)(param_3 + 8));
              FUN_00109c0e(param_1 + 0x2f,1,0);
              iVar5 = 0;
              do {
                iVar6 = FUN_0010b0f4(param_1,1);
                if (*(char *)(iVar5 + 0x10 + iVar6) == '\x04') {
                  iVar6 = FUN_0010b0f4(param_1,2);
                  if (*(char *)(iVar5 + 0x10 + iVar6) == '\x04') {
                    if (*(char *)((int)&local_30 + iVar5) == '\0') {
                      (**(code **)(*param_1 + 0x88))(param_1,1,iVar5,0xffffffff);
                    }
                  }
                  else {
                    (**(code **)(*param_1 + 0x88))(param_1,1,iVar5,local_8c);
                  }
                }
                iVar6 = FUN_0010b0f4(param_1,2);
                if (*(char *)(iVar5 + 0x10 + iVar6) == '\x04') {
                  iVar6 = FUN_0010b0f4(param_1,1);
                  if (*(char *)(iVar5 + 0x10 + iVar6) == '\x04') {
                    if (*(char *)((int)&local_30 + iVar5) == '\0') {
                      (**(code **)(*param_1 + 0x88))(param_1,2,iVar5,0xffffffff);
                    }
                  }
                  else {
                    (**(code **)(*param_1 + 0x88))(param_1,2,iVar5,local_88);
                  }
                }
                iVar5 = iVar5 + 1;
              } while (iVar5 != 4);
              FUN_000e956e(param_1[0x56],param_1,piVar7);
              FUN_000e956e(param_1[0x56],param_1,piVar8);
              if (bVar12) {
                FUN_0010c568(param_1,&local_5c,0,*(undefined4 *)(param_3 + 8));
                if (*(int *)(param_3 + 0x46c) < piVar10[0x58]) {
                  piVar10[0x58] = piVar10[0x58] + 1;
                }
                else {
                  piVar10[0x58] = *(int *)(param_3 + 0x46c) + 1;
                }
              }
              cVar2 = (**(code **)(*param_2 + 0x60))(param_2);
              if (cVar2 == '\0') {
                local_84 = param_2;
              }
              else {
                local_84 = (int *)FUN_0010b180(param_2,1);
              }
              iVar5 = FUN_0010b180(local_84,1);
              if (iVar5 == 0) {
                iVar5 = local_84[0x2c];
              }
              else {
                iVar5 = FUN_0010b180(local_84,1);
                iVar5 = *(int *)(iVar5 + 0x98);
              }
              if (iVar5 == 0x31) {
                iVar5 = FUN_0010b180(local_84,1);
                iVar6 = FUN_0010a1c2(iVar5,*(undefined4 *)(param_3 + 8),0);
                *(undefined4 *)(iVar6 + 0x94) = *(undefined4 *)(iVar6 + 0x14c);
                *(undefined4 *)(iVar6 + 0x98) = 0x31;
                FUN_000e9596(*(undefined4 *)(iVar5 + 0x158),iVar5,iVar6);
                *(int *)(iVar6 + 0x160) = *(int *)(param_3 + 0x46c) + 1;
                if (0 < *(int *)(iVar6 + 0x84)) {
                  local_80 = 1;
                  do {
                    iVar5 = *(int *)(param_3 + 0x46c);
                    iVar11 = FUN_0010b180(iVar6,local_80);
                    if (iVar5 < *(int *)(iVar11 + 0x160)) {
                      *(int *)(iVar11 + 0x160) = *(int *)(iVar11 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar11 + 0x160) = iVar5 + 1;
                    }
                    local_80 = local_80 + 1;
                  } while (local_80 <= *(int *)(iVar6 + 0x84));
                }
                FUN_0010ba02(local_84,1,iVar6,0,*(undefined4 *)(param_3 + 8));
              }
              else {
                iVar5 = *(int *)(param_3 + 0x46c);
                iVar6 = FUN_0010b180(param_2,1);
                if (iVar5 < *(int *)(iVar6 + 0x160)) {
                  *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar6 + 0x160) = iVar5 + 1;
                }
              }
              piVar10 = (int *)FUN_0010b180(piVar8,1);
              cVar2 = (**(code **)(*piVar10 + 0x60))(piVar10);
              if (cVar2 != '\0') {
                uVar3 = *(undefined4 *)(param_3 + 8);
                uVar4 = FUN_0010b180(piVar8,1);
                FUN_00111842(uVar4,piVar8,uVar3);
              }
              piVar10 = (int *)FUN_0010b180(piVar7,1);
              cVar2 = (**(code **)(*piVar10 + 0x60))(piVar10);
              if (cVar2 != '\0') {
                uVar3 = *(undefined4 *)(param_3 + 8);
                uVar4 = FUN_0010b180(piVar7,1);
                FUN_00111842(uVar4,piVar7,uVar3);
              }
              FUN_0010b3fe(param_2,*(undefined4 *)(param_3 + 8));
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_00161938 @ 0x161938 (6378 bytes) */
int FUN_00161938(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  float *pfVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  code *pcVar5;
  bool bVar6;
  char cVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int *local_11c;
  int *local_118;
  int *local_110;
  int local_10c;
  int local_108;
  int *local_104;
  int local_100;
  int local_fc;
  int *local_f8;
  int local_f4;
  int local_ec;
  int local_e0;
  int local_d4;
  int local_cc;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  uVar4 = *(undefined4 *)(param_3 + 8);
  cVar7 = (**(code **)(*param_1 + 100))(param_1);
  if (((cVar7 != '\0') && (*(int *)(param_2[0x22] + 8) == 0x12)) ||
     ((cVar7 = (**(code **)(*param_2 + 100))(param_2), cVar7 != '\0' &&
      (*(int *)(param_1[0x22] + 8) == 0x12)))) {
    iVar8 = FUN_0010b0f4(param_1,1);
    uVar10 = *(undefined4 *)(iVar8 + 0x10);
    uVar9 = FUN_0010b180(param_1,1);
    cVar7 = FUN_0010a2a8(uVar9,uVar4,uVar10);
    iVar8 = FUN_0010b0f4(param_2,1);
    uVar10 = *(undefined4 *)(iVar8 + 0x10);
    uVar9 = FUN_0010b180(param_2,1);
    FUN_0010a2a8(uVar9,uVar4,uVar10);
    if ((((char)param_2[0x48] == (char)param_1[0x48]) && (param_1[0x49] == param_2[0x49])) &&
       (cVar7 == '\0')) {
      iVar8 = FUN_0010b0f4(param_1,0);
      local_20 = *(int *)(iVar8 + 0x10);
      iVar8 = FUN_0010b0f4(param_1,param_1[0x21]);
      local_24 = FUN_000f5e2c(*(undefined4 *)(iVar8 + 0x10));
      iVar8 = FUN_0010b0f4(param_2,0);
      local_24 = FUN_000f5862(local_24,*(undefined4 *)(iVar8 + 0x10));
      iVar8 = 1;
      do {
        if ((*(char *)((int)&local_24 + iVar8 + 3) != '\x01') &&
           (*(char *)((int)&local_28 + iVar8 + 3) != '\x01')) {
          return 0;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 != 5);
      cVar7 = FUN_000e1402(uVar4,0x30);
      if ((cVar7 == '\0') || (((*(unsigned char *)((unsigned char *)&(local_20) + 3)) != '\0' && ((*(unsigned char *)((unsigned char *)&(local_24) + 3)) != '\0')))) {
        cVar7 = (**(code **)(*param_1 + 100))(param_1);
        if (cVar7 == '\0') {
          local_2c = local_24;
          local_28 = local_20;
          local_118 = param_2;
          local_11c = param_1;
        }
        else {
          local_2c = local_20;
          local_28 = local_24;
          local_118 = param_1;
          local_11c = param_2;
        }
        cVar7 = FUN_0014fef8(local_11c);
        if ((cVar7 != '\0') &&
           ((*(byte *)(local_11c + 0x34) & 1) == (*(byte *)(local_11c + 0x2e) & 1))) {
          uVar10 = FUN_0010b180(local_11c,1);
          uVar9 = FUN_0010b180(local_118,1);
          cVar7 = FUN_001503ee(uVar9,uVar10);
          if (cVar7 == '\0') {
            uVar10 = FUN_0010b180(local_11c,2);
            uVar9 = FUN_0010b180(local_118,1);
            cVar7 = FUN_001503ee(uVar9,uVar10);
            if (cVar7 == '\0') {
              iVar8 = FUN_0010b180(local_118,1);
              iVar11 = FUN_0010b180(local_11c,1);
              if (iVar8 != iVar11) {
                iVar8 = FUN_0010b180(local_118,1);
                iVar11 = FUN_0010b180(local_11c,2);
                if ((iVar8 != iVar11) && (cVar7 = FUN_0010a62e(param_2,param_3), cVar7 != '\0')) {
                  local_30 = FUN_000f5892(local_24,local_20);
                  iVar8 = param_1[0x49];
                  iVar11 = FUN_0010b0f4(local_11c,1);
                  local_34 = *(int *)(iVar11 + 0x10);
                  iVar11 = FUN_0010b0f4(local_11c,2);
                  local_38 = *(int *)(iVar11 + 0x10);
                  iVar11 = FUN_0010b0f4(local_118,1);
                  local_3c = *(int *)(iVar11 + 0x10);
                  piVar12 = (int *)FUN_0010b180(local_11c,1);
                  cVar7 = (**(code **)(*piVar12 + 0x60))(piVar12);
                  if (cVar7 == '\0') {
                    uVar10 = FUN_0010b180(local_11c,1);
                    local_110 = (int *)((int (*)())FUN_00110f42)(3,DAT_001cc6d4,uVar10,param_3,uVar4,0x3f800000);
                    if (0 < local_110[0x21]) {
                      iVar11 = 1;
                      do {
                        iVar14 = *(int *)(param_3 + 0x46c);
                        iVar13 = FUN_0010b180(local_110,iVar11);
                        if (iVar14 < *(int *)(iVar13 + 0x160)) {
                          *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar13 + 0x160) = iVar14 + 1;
                        }
                        iVar11 = iVar11 + 1;
                      } while (iVar11 <= local_110[0x21]);
                    }
                    iVar11 = local_34;
                    local_40 = 0;
                    local_44 = 0;
                    iVar14 = FUN_0010b0f4(local_110,1);
                    *(int *)(iVar14 + 0x10) = iVar11;
                    local_10c = 2;
                    local_108 = 3;
                  }
                  else {
                    uVar10 = FUN_0010b180(local_11c,1);
                    local_110 = (int *)FUN_0010a1c2(uVar10,uVar4,0);
                    local_110[0x58] = *(int *)(param_3 + 0x46c) + 1;
                    local_110[0x25] = local_110[0x53];
                    if (0 < local_110[0x21]) {
                      iVar11 = 1;
                      do {
                        iVar14 = *(int *)(param_3 + 0x46c);
                        iVar13 = FUN_0010b180(local_110,iVar11);
                        if (iVar14 < *(int *)(iVar13 + 0x160)) {
                          *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar13 + 0x160) = iVar14 + 1;
                        }
                        iVar11 = iVar11 + 1;
                      } while (iVar11 <= local_110[0x21]);
                    }
                    local_10c = ((int (*)())FUN_00110362)(local_110,0x3f800000,&local_40);
                    if (local_10c == 0) {
                      FUN_00110d96(local_110,0x3f800000,local_110[0x21] + 1,uVar4);
                      local_10c = local_110[0x21];
                      local_40 = 0;
                      iVar11 = *(int *)(param_3 + 0x46c);
                      iVar14 = FUN_0010b180(local_110,local_10c);
                      if (iVar11 < *(int *)(iVar14 + 0x160)) {
                        *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar14 + 0x160) = iVar11 + 1;
                      }
                    }
                    local_108 = ((int (*)())FUN_00110362)(local_110,0,&local_44);
                    if (local_108 == 0) {
                      FUN_00110d96(local_110,0,local_110[0x21] + 1,uVar4);
                      local_108 = local_110[0x21];
                      local_44 = 0;
                      iVar11 = *(int *)(param_3 + 0x46c);
                      iVar14 = FUN_0010b180(local_110,local_108);
                      if (iVar11 < *(int *)(iVar14 + 0x160)) {
                        *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar14 + 0x160) = iVar11 + 1;
                      }
                    }
                    iVar11 = DAT_001cc5a4;
                    if (0 < local_110[0x21]) {
                      iVar14 = 1;
                      do {
                        if (iVar14 == 0) {
                          local_110[0x27] = iVar11;
                        }
                        else {
                          iVar13 = FUN_0010b0f4(local_110,iVar14);
                          *(int *)(iVar13 + 0x10) = iVar11;
                        }
                        iVar14 = iVar14 + 1;
                      } while (iVar14 <= local_110[0x21]);
                    }
                    local_ec = 0;
                    do {
                      if ((*(char *)((int)&local_28 + local_ec) == '\0') &&
                         (bVar3 = *(byte *)((int)&local_34 + local_ec), 0 < local_110[0x21])) {
                        iVar11 = 1;
                        do {
                          iVar14 = FUN_0010b0f4(uVar10,iVar11);
                          if (*(char *)(bVar3 + 0x10 + iVar14) != '\x04') {
                            pcVar5 = *(code **)(*local_110 + 0x88);
                            iVar14 = FUN_0010b0f4(uVar10,iVar11);
                            (*pcVar5)(local_110,iVar11,local_ec,
                                      *(undefined1 *)(bVar3 + 0x10 + iVar14));
                            break;
                          }
                          iVar11 = iVar11 + 1;
                        } while (iVar11 <= local_110[0x21]);
                      }
                      local_ec = local_ec + 1;
                    } while (local_ec != 4);
                    local_110[0x27] = local_28;
                  }
                  local_34 = DAT_001cc5a4;
                  iVar11 = 0;
                  do {
                    if (*(char *)((int)&local_28 + iVar11) == '\0') {
                      *(char *)((int)&local_34 + iVar11) = (char)iVar11;
                    }
                    iVar11 = iVar11 + 1;
                  } while (iVar11 != 4);
                  piVar12 = (int *)FUN_0010b180(local_11c,2);
                  cVar7 = (**(code **)(*piVar12 + 0x60))(piVar12);
                  if (cVar7 == '\0') {
                    uVar10 = FUN_0010b180(local_11c,2);
                    local_104 = (int *)((int (*)())FUN_00110f42)(3,local_28,uVar10,param_3,uVar4,0x3f800000);
                    if (0 < local_104[0x21]) {
                      iVar11 = 1;
                      do {
                        iVar14 = *(int *)(param_3 + 0x46c);
                        iVar13 = FUN_0010b180(local_104,iVar11);
                        if (iVar14 < *(int *)(iVar13 + 0x160)) {
                          *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar13 + 0x160) = iVar14 + 1;
                        }
                        iVar11 = iVar11 + 1;
                      } while (iVar11 <= local_104[0x21]);
                    }
                    iVar11 = local_38;
                    local_48 = 0;
                    local_4c = 0;
                    iVar14 = FUN_0010b0f4(local_104,1);
                    *(int *)(iVar14 + 0x10) = iVar11;
                    local_100 = 2;
                    local_fc = 3;
                  }
                  else {
                    uVar10 = FUN_0010b180(local_11c,2);
                    local_104 = (int *)FUN_0010a1c2(uVar10,uVar4,0);
                    local_104[0x58] = *(int *)(param_3 + 0x46c) + 1;
                    local_104[0x25] = local_104[0x53];
                    if (0 < local_104[0x21]) {
                      iVar11 = 1;
                      do {
                        iVar14 = *(int *)(param_3 + 0x46c);
                        iVar13 = FUN_0010b180(local_104,iVar11);
                        if (iVar14 < *(int *)(iVar13 + 0x160)) {
                          *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar13 + 0x160) = iVar14 + 1;
                        }
                        iVar11 = iVar11 + 1;
                      } while (iVar11 <= local_104[0x21]);
                    }
                    local_100 = ((int (*)())FUN_00110362)(local_104,0x3f800000,&local_48);
                    if (local_100 == 0) {
                      FUN_00110d96(local_104,0x3f800000,local_104[0x21] + 1,uVar4);
                      local_100 = local_104[0x21];
                      local_48 = 0;
                      iVar11 = *(int *)(param_3 + 0x46c);
                      iVar14 = FUN_0010b180(local_104,local_100);
                      if (iVar11 < *(int *)(iVar14 + 0x160)) {
                        *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar14 + 0x160) = iVar11 + 1;
                      }
                    }
                    local_fc = ((int (*)())FUN_00110362)(local_104,0,&local_4c);
                    if (local_fc == 0) {
                      FUN_00110d96(local_104,0,local_104[0x21] + 1,uVar4);
                      local_fc = local_104[0x21];
                      local_4c = 0;
                      iVar11 = *(int *)(param_3 + 0x46c);
                      iVar14 = FUN_0010b180(local_104,local_fc);
                      if (iVar11 < *(int *)(iVar14 + 0x160)) {
                        *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar14 + 0x160) = iVar11 + 1;
                      }
                    }
                    iVar11 = DAT_001cc5a4;
                    if (0 < local_104[0x21]) {
                      iVar14 = 1;
                      do {
                        if (iVar14 == 0) {
                          local_104[0x27] = iVar11;
                        }
                        else {
                          iVar13 = FUN_0010b0f4(local_104,iVar14);
                          *(int *)(iVar13 + 0x10) = iVar11;
                        }
                        iVar14 = iVar14 + 1;
                      } while (iVar14 <= local_104[0x21]);
                    }
                    local_e0 = 0;
                    do {
                      if ((*(char *)((int)&local_28 + local_e0) == '\0') &&
                         (bVar3 = *(byte *)((int)&local_34 + local_e0), 0 < local_104[0x21])) {
                        iVar11 = 1;
                        do {
                          iVar14 = FUN_0010b0f4(uVar10,iVar11);
                          if (*(char *)(bVar3 + 0x10 + iVar14) != '\x04') {
                            pcVar5 = *(code **)(*local_104 + 0x88);
                            iVar14 = FUN_0010b0f4(uVar10,iVar11);
                            (*pcVar5)(local_104,iVar11,local_e0,
                                      *(undefined1 *)(bVar3 + 0x10 + iVar14));
                            break;
                          }
                          iVar11 = iVar11 + 1;
                        } while (iVar11 <= local_104[0x21]);
                      }
                      local_e0 = local_e0 + 1;
                    } while (local_e0 != 4);
                    local_104[0x27] = local_28;
                  }
                  local_38 = DAT_001cc5a4;
                  iVar11 = 0;
                  do {
                    if (*(char *)((int)&local_28 + iVar11) == '\0') {
                      *(char *)((int)&local_38 + iVar11) = (char)iVar11;
                    }
                    iVar11 = iVar11 + 1;
                  } while (iVar11 != 4);
                  cVar7 = (**(code **)(*local_118 + 0x60))(local_118);
                  if (cVar7 == '\0') {
                    uVar10 = FUN_0010b180(local_118,1);
                    local_f8 = (int *)((int (*)())FUN_00110f42)(2,local_2c,uVar10,param_3,uVar4,0);
                    if (0 < local_f8[0x21]) {
                      iVar11 = 1;
                      do {
                        iVar14 = *(int *)(param_3 + 0x46c);
                        iVar13 = FUN_0010b180(local_f8,iVar11);
                        if (iVar14 < *(int *)(iVar13 + 0x160)) {
                          *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar13 + 0x160) = iVar14 + 1;
                        }
                        iVar11 = iVar11 + 1;
                      } while (iVar11 <= local_f8[0x21]);
                    }
                    iVar11 = local_3c;
                    local_50 = 0;
                    iVar14 = FUN_0010b0f4(local_f8,1);
                    *(int *)(iVar14 + 0x10) = iVar11;
                    local_f4 = 2;
                  }
                  else {
                    uVar10 = FUN_0010b180(local_118,1);
                    local_f8 = (int *)FUN_0010a1c2(uVar10,uVar4,0);
                    local_f8[0x58] = *(int *)(param_3 + 0x46c) + 1;
                    local_f8[0x25] = local_f8[0x53];
                    if (0 < local_f8[0x21]) {
                      iVar11 = 1;
                      do {
                        iVar14 = *(int *)(param_3 + 0x46c);
                        iVar13 = FUN_0010b180(local_f8,iVar11);
                        if (iVar14 < *(int *)(iVar13 + 0x160)) {
                          *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar13 + 0x160) = iVar14 + 1;
                        }
                        iVar11 = iVar11 + 1;
                      } while (iVar11 <= local_f8[0x21]);
                    }
                    local_f4 = ((int (*)())FUN_00110362)(local_f8,0,&local_50);
                    if (local_f4 == 0) {
                      FUN_00110d96(local_f8,0,local_f8[0x21] + 1,uVar4);
                      local_f4 = local_f8[0x21];
                      local_50 = 0;
                      iVar11 = *(int *)(param_3 + 0x46c);
                      iVar14 = FUN_0010b180(local_f8,local_f4);
                      if (iVar11 < *(int *)(iVar14 + 0x160)) {
                        *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar14 + 0x160) = iVar11 + 1;
                      }
                    }
                    iVar11 = DAT_001cc5a4;
                    if (0 < local_f8[0x21]) {
                      iVar14 = 1;
                      do {
                        if (iVar14 == 0) {
                          local_f8[0x27] = iVar11;
                        }
                        else {
                          iVar13 = FUN_0010b0f4(local_f8,iVar14);
                          *(int *)(iVar13 + 0x10) = iVar11;
                        }
                        iVar14 = iVar14 + 1;
                      } while (iVar14 <= local_f8[0x21]);
                    }
                    local_d4 = 0;
                    do {
                      if ((*(char *)((int)&local_2c + local_d4) == '\0') &&
                         (bVar3 = *(byte *)((int)&local_3c + local_d4), 0 < local_f8[0x21])) {
                        iVar11 = 1;
                        do {
                          iVar14 = FUN_0010b0f4(uVar10,iVar11);
                          if (*(char *)(bVar3 + 0x10 + iVar14) != '\x04') {
                            pcVar5 = *(code **)(*local_f8 + 0x88);
                            iVar14 = FUN_0010b0f4(uVar10,iVar11);
                            (*pcVar5)(local_f8,iVar11,local_d4,
                                      *(undefined1 *)(bVar3 + 0x10 + iVar14));
                            break;
                          }
                          iVar11 = iVar11 + 1;
                        } while (iVar11 <= local_f8[0x21]);
                      }
                      local_d4 = local_d4 + 1;
                    } while (local_d4 != 4);
                    local_f8[0x27] = local_2c;
                  }
                  local_3c = DAT_001cc5a4;
                  iVar11 = 0;
                  do {
                    if (*(char *)((int)&local_2c + iVar11) == '\0') {
                      *(char *)((int)&local_3c + iVar11) = (char)iVar11;
                    }
                    iVar11 = iVar11 + 1;
                  } while (iVar11 != 4);
                  local_cc = 0;
                  do {
                    if (*(char *)((int)&local_28 + local_cc) == '\0') {
                      *(char *)((int)&local_3c + local_cc) = (char)local_cc;
                      (**(code **)(*local_f8 + 0x88))(local_f8,local_f4,local_cc,local_50);
                      *(undefined1 *)(local_cc + 0x9c + (int)local_f8) = 0;
                      bVar3 = *(byte *)((int)&local_34 + local_cc);
                      if (0 < local_110[0x21]) {
                        iVar11 = 1;
                        bVar6 = false;
                        do {
                          iVar14 = FUN_0010b0f4(local_110,iVar11);
                          bVar2 = *(byte *)(bVar3 + 0x10 + iVar14);
                          uVar15 = (uint)bVar2;
                          if ((((bVar2 != 4) &&
                               (iVar14 = FUN_0010b180(local_110,iVar11),
                               ((int)*(char *)(iVar14 + 0x15c) >> (bVar2 & 0x1f) & 1U) != 0)) &&
                              (pfVar1 = (float *)(iVar14 + 0x20 + uVar15 * 0x18), *pfVar1 == 0.0))
                             && (!NAN(*pfVar1))) {
                            (**(code **)(*local_110 + 0x88))(local_110,iVar11,uVar15,4);
                            (**(code **)(*local_110 + 0x88))(local_110,local_10c,uVar15,local_40);
                            bVar6 = true;
                          }
                          iVar11 = iVar11 + 1;
                        } while (iVar11 <= local_110[0x21]);
                        if (bVar6) goto LAB_0016229c;
                      }
                      bVar3 = *(byte *)((int)&local_38 + local_cc);
                      if (0 < local_104[0x21]) {
                        iVar11 = 1;
                        do {
                          iVar14 = FUN_0010b0f4(local_104,iVar11);
                          bVar2 = *(byte *)(bVar3 + 0x10 + iVar14);
                          uVar15 = (uint)bVar2;
                          if (((bVar2 != 4) &&
                              (iVar14 = FUN_0010b180(local_104,iVar11),
                              ((int)*(char *)(iVar14 + 0x15c) >> (bVar2 & 0x1f) & 1U) != 0)) &&
                             ((pfVar1 = (float *)(iVar14 + 0x20 + uVar15 * 0x18), *pfVar1 == 0.0 &&
                              (!NAN(*pfVar1))))) {
                            (**(code **)(*local_104 + 0x88))(local_104,iVar11,uVar15,4);
                            (**(code **)(*local_104 + 0x88))(local_104,local_100,uVar15,local_48);
                          }
                          iVar11 = iVar11 + 1;
                        } while (iVar11 <= local_104[0x21]);
                      }
                    }
LAB_0016229c:
                    local_cc = local_cc + 1;
                    if (local_cc == 4) {
                      iVar11 = 0;
                      do {
                        if (*(char *)((int)&local_2c + iVar11) == '\0') {
                          (**(code **)(*local_110 + 0x88))(local_110,local_108,iVar11,local_44);
                          *(undefined1 *)(iVar11 + 0x9c + (int)local_110) = 0;
                          (**(code **)(*local_104 + 0x88))(local_104,local_fc,iVar11,local_4c);
                          *(undefined1 *)(iVar11 + 0x9c + (int)local_104) = 0;
                        }
                        iVar11 = iVar11 + 1;
                      } while (iVar11 != 4);
                      iVar11 = 0;
                      piVar12 = &local_3c;
                      do {
                        if (*(char *)((int)&local_30 + iVar11) == '\0') {
                          cVar7 = (char)iVar11;
                          if ((char)piVar12[2] == '\x04') {
                            *(char *)(piVar12 + 2) = cVar7;
                          }
                          if ((char)piVar12[1] == '\x04') {
                            *(char *)(piVar12 + 1) = cVar7;
                          }
                          if ((char)*piVar12 == '\x04') {
                            *(char *)piVar12 = cVar7;
                          }
                        }
                        iVar11 = iVar11 + 1;
                        piVar12 = (int *)((int)piVar12 + 1);
                      } while (iVar11 != 4);
                      local_74 = 0;
                      local_70 = 0;
                      local_60 = 0;
                      if ((*(byte *)((int)param_2 + 0x15) & 2) != 0) {
                        FUN_0010a980(param_2,&local_74);
                      }
                      local_8c = 0;
                      local_88 = 0;
                      local_78 = 0;
                      local_a4 = 0;
                      local_a0 = 0;
                      local_90 = 0;
                      local_bc = 0;
                      local_b8 = 0;
                      local_a8 = 0;
                      uVar10 = FUN_0010b0f4(local_118,1);
                      FUN_0010a40a(&local_bc,uVar10);
                      uVar10 = FUN_0010b0f4(local_11c,1);
                      FUN_0010a40a(&local_8c,uVar10);
                      uVar10 = FUN_0010b0f4(local_11c,2);
                      FUN_0010a40a(&local_a4,uVar10);
                      local_5c = 0;
                      local_58 = 0;
                      local_54 = 0;
                      FUN_00109d1c(param_1,&local_5c,0xffffffff);
                      iVar11 = param_1[1];
                      FUN_001a7d72(param_1);
                      FUN_0010da48(param_1,0x14,uVar4);
                      FUN_000e9596(*(undefined4 *)(iVar11 + 0x158),iVar11,param_1);
                      param_1[0x25] = param_1[0x53];
                      param_1[0x26] = 0;
                      FUN_00109d48(param_1,&local_5c);
                      *(char *)(param_1 + 0x48) = (char)param_2[0x48];
                      param_1[0x49] = iVar8;
                      param_1[0x27] = local_30;
                      uVar10 = FUN_0010b0f4(param_1,1);
                      FUN_0010a40a(uVar10,&local_8c);
                      FUN_0010ba02(param_1,1,local_110,0,uVar4);
                      FUN_000e956e(param_1[0x56],param_1,local_110);
                      iVar8 = local_34;
                      iVar11 = FUN_0010b0f4(param_1,1);
                      *(int *)(iVar11 + 0x10) = iVar8;
                      uVar10 = FUN_0010b0f4(param_1,2);
                      FUN_0010a40a(uVar10,&local_a4);
                      FUN_0010ba02(param_1,2,local_104,0,uVar4);
                      FUN_000e956e(param_1[0x56],param_1,local_104);
                      iVar8 = local_38;
                      iVar11 = FUN_0010b0f4(param_1,2);
                      *(int *)(iVar11 + 0x10) = iVar8;
                      FUN_00109c0e(param_1 + 0x2f,1,0);
                      uVar10 = FUN_0010b0f4(param_1,3);
                      FUN_0010a40a(uVar10,&local_bc);
                      FUN_0010ba02(param_1,3,local_f8,0,uVar4);
                      FUN_000e956e(param_1[0x56],param_1,local_f8);
                      iVar8 = local_3c;
                      iVar11 = FUN_0010b0f4(param_1,3);
                      *(int *)(iVar11 + 0x10) = iVar8;
                      if (local_70 != 0) {
                        FUN_0010c568(param_1,&local_74,0,uVar4);
                        if (*(int *)(param_3 + 0x46c) < *(int *)(local_70 + 0x160)) {
                          *(int *)(local_70 + 0x160) = *(int *)(local_70 + 0x160) + 1;
                        }
                        else {
                          *(int *)(local_70 + 0x160) = *(int *)(param_3 + 0x46c) + 1;
                        }
                      }
                      iVar8 = *(int *)(param_3 + 0x46c);
                      iVar11 = FUN_0010b180(param_2,1);
                      if (iVar8 < *(int *)(iVar11 + 0x160)) {
                        *(int *)(iVar11 + 0x160) = *(int *)(iVar11 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar11 + 0x160) = iVar8 + 1;
                      }
                      if (local_11c == param_2) {
                        iVar8 = *(int *)(param_3 + 0x46c);
                        iVar11 = FUN_0010b180(param_2,2);
                        if (iVar8 < *(int *)(iVar11 + 0x160)) {
                          *(int *)(iVar11 + 0x160) = *(int *)(iVar11 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar11 + 0x160) = iVar8 + 1;
                        }
                      }
                      FUN_0010b3fe(param_2,uVar4);
                      return 1;
                    }
                  } while( true );
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_0016322a @ 0x16322a (3793 bytes) */
int FUN_0016322a(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  int *piVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  char local_e1;
  int *local_e0;
  int *local_dc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  cVar3 = (**(code **)(*param_1 + 100))(param_1);
  if (((cVar3 != '\0') && (*(int *)(param_2[0x22] + 8) == 0x13)) ||
     ((cVar3 = (**(code **)(*param_2 + 100))(param_2), cVar3 != '\0' &&
      (*(int *)(param_1[0x22] + 8) == 0x13)))) {
    iVar5 = FUN_0010b0f4(param_1,1);
    uVar7 = *(undefined4 *)(iVar5 + 0x10);
    uVar8 = *(undefined4 *)(param_3 + 8);
    uVar6 = FUN_0010b180(param_1,1);
    local_e1 = FUN_0010a2a8(uVar6,uVar8,uVar7);
    iVar5 = FUN_0010b0f4(param_2,1);
    uVar7 = *(undefined4 *)(iVar5 + 0x10);
    uVar8 = *(undefined4 *)(param_3 + 8);
    uVar6 = FUN_0010b180(param_2,1);
    cVar3 = FUN_0010a2a8(uVar6,uVar8,uVar7);
    if (((char)param_2[0x48] == (char)param_1[0x48]) && (param_1[0x49] == param_2[0x49])) {
      iVar5 = FUN_0010b0f4(param_1,0);
      local_20 = *(undefined4 *)(iVar5 + 0x10);
      iVar5 = FUN_0010b0f4(param_2,0);
      local_24 = *(undefined4 *)(iVar5 + 0x10);
      iVar5 = 1;
      do {
        if ((*(char *)((int)&local_24 + iVar5 + 3) != '\x01') &&
           (*(char *)((int)&local_28 + iVar5 + 3) != '\x01')) {
          return 0;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 != 5);
      cVar4 = FUN_000e1402(*(undefined4 *)(param_3 + 8),0x30);
      if ((cVar4 == '\0') || (((*(unsigned char *)((unsigned char *)&(local_20) + 3)) != '\0' && ((*(unsigned char *)((unsigned char *)&(local_24) + 3)) != '\0')))) {
        cVar4 = (**(code **)(*param_1 + 100))(param_1);
        uVar7 = local_20;
        if (cVar4 == '\0') {
          local_20 = local_24;
          local_24 = uVar7;
          local_dc = param_2;
          local_e0 = param_1;
          local_e1 = cVar3;
        }
        else {
          local_dc = param_1;
          local_e0 = param_2;
        }
        if (local_e1 == '\0') {
          uVar7 = FUN_0010b180(local_e0,1);
          uVar8 = FUN_0010b180(local_dc,1);
          cVar3 = FUN_001503ee(uVar8,uVar7);
          if (cVar3 == '\0') {
            uVar7 = FUN_0010b180(local_e0,2);
            uVar8 = FUN_0010b180(local_dc,1);
            cVar3 = FUN_001503ee(uVar8,uVar7);
            if (cVar3 == '\0') {
              iVar5 = FUN_0010b180(local_dc,1);
              iVar9 = FUN_0010b180(local_e0,1);
              if (iVar5 != iVar9) {
                iVar5 = FUN_0010b180(local_dc,1);
                iVar9 = FUN_0010b180(local_e0,2);
                if ((iVar5 != iVar9) && (cVar3 = FUN_0010a62e(param_2,param_3), cVar3 != '\0')) {
                  local_28 = FUN_000f5892(local_24,local_20);
                  iVar5 = param_1[0x49];
                  uVar7 = *(undefined4 *)(param_3 + 8);
                  uVar8 = FUN_0010b180(local_e0,1);
                  piVar10 = (int *)((int (*)())FUN_00110f42)(2,local_28,uVar8,param_3,uVar7,0);
                  uVar7 = *(undefined4 *)(param_3 + 8);
                  uVar8 = FUN_0010b180(local_e0,2);
                  piVar11 = (int *)((int (*)())FUN_00110f42)(2,local_28,uVar8,param_3,uVar7,0);
                  uVar7 = *(undefined4 *)(param_3 + 8);
                  uVar8 = FUN_0010b180(local_dc,1);
                  piVar12 = (int *)((int (*)())FUN_00110f42)(2,local_28,uVar8,param_3,uVar7,0);
                  iVar9 = FUN_0010b0f4(local_e0,1);
                  local_2c = *(undefined4 *)(iVar9 + 0x10);
                  iVar9 = FUN_0010b0f4(local_e0,2);
                  local_30 = *(undefined4 *)(iVar9 + 0x10);
                  iVar9 = FUN_0010b0f4(local_dc,1);
                  local_34 = *(undefined4 *)(iVar9 + 0x10);
                  local_40 = DAT_001cc6d4;
                  local_c8 = -1;
                  local_c4 = -1;
                  local_c0 = -1;
                  local_bc = -1;
                  iVar13 = 0;
                  iVar9 = -1;
                  iVar18 = -1;
                  do {
                    iVar16 = iVar9;
                    iVar19 = iVar18;
                    iVar1 = local_c8;
                    iVar2 = local_c4;
                    if (*(char *)((int)&local_20 + iVar13) == '\0') {
                      iVar1 = iVar13;
                      if (((-1 < local_c8) && (iVar1 = local_c8, iVar2 = iVar13, -1 < local_c4)) &&
                         (iVar2 = local_c4, local_c0 < 0)) {
                        local_c0 = iVar13;
                      }
                    }
                    else if ((((*(char *)((int)&local_24 + iVar13) == '\0') &&
                              (iVar16 = iVar13, -1 < iVar9)) &&
                             (iVar16 = iVar9, iVar19 = iVar13, -1 < iVar18)) &&
                            (iVar19 = iVar18, local_bc < 0)) {
                      local_bc = iVar13;
                    }
                    local_c4 = iVar2;
                    local_c8 = iVar1;
                    iVar13 = iVar13 + 1;
                    iVar9 = iVar16;
                    iVar18 = iVar19;
                  } while (iVar13 != 4);
                  uVar14 = (uint)*(byte *)((int)&local_2c + iVar16);
                  uVar17 = (uint)*(byte *)((int)&local_30 + iVar16);
                  local_38 = local_40;
                  *(undefined1 *)((int)&local_38 + uVar14) = 0;
                  local_3c = local_40;
                  *(undefined1 *)((int)&local_3c + uVar17) = 0;
                  (**(code **)(*piVar10 + 0x88))(piVar10,1,uVar14,uVar14);
                  (**(code **)(*piVar11 + 0x88))(piVar11,1,uVar17,uVar17);
                  if (0 < iVar19) {
                    uVar14 = (uint)*(byte *)((int)&local_2c + iVar19);
                    uVar17 = (uint)*(byte *)((int)&local_30 + iVar19);
                    *(undefined1 *)((int)&local_38 + uVar14) = 0;
                    *(undefined1 *)((int)&local_3c + uVar17) = 0;
                    (**(code **)(*piVar10 + 0x88))(piVar10,1,uVar14,uVar14);
                    (**(code **)(*piVar11 + 0x88))(piVar11,1,uVar17,uVar17);
                    if (0 < local_bc) {
                      uVar14 = (uint)*(byte *)((int)&local_2c + local_bc);
                      uVar17 = (uint)*(byte *)((int)&local_30 + local_bc);
                      *(undefined1 *)((int)&local_38 + uVar14) = 0;
                      *(undefined1 *)((int)&local_3c + uVar17) = 0;
                      (**(code **)(*piVar10 + 0x88))(piVar10,1,uVar14,uVar14);
                      (**(code **)(*piVar11 + 0x88))(piVar11,1,uVar17,uVar17);
                    }
                  }
                  uVar14 = (uint)*(byte *)((int)&local_34 + local_c8);
                  *(undefined1 *)((int)&local_40 + uVar14) = 0;
                  (**(code **)(*piVar12 + 0x88))(piVar12,1,uVar14,uVar14);
                  if (-1 < local_c4) {
                    uVar14 = (uint)*(byte *)((int)&local_34 + local_c4);
                    *(undefined1 *)((int)&local_40 + uVar14) = 0;
                    (**(code **)(*piVar12 + 0x88))(piVar12,1,uVar14,uVar14);
                    if (-1 < local_c0) {
                      uVar14 = (uint)*(byte *)((int)&local_34 + local_c0);
                      *(undefined1 *)((int)&local_40 + uVar14) = 0;
                      (**(code **)(*piVar12 + 0x88))(piVar12,1,uVar14,uVar14);
                    }
                  }
                  local_b8 = 0xffffffff;
                  local_b4 = 0xffffffff;
                  local_b0 = 0xffffffff;
                  uVar14 = 0;
                  do {
                    iVar9 = FUN_0010b0f4(piVar10,1);
                    if ((uVar14 != *(byte *)(uVar14 + 0x10 + iVar9)) && ((int)local_b8 < 0)) {
                      (**(code **)(*piVar10 + 0x88))(piVar10,2,uVar14,uVar14);
                      *(undefined1 *)((int)&local_38 + uVar14) = 0;
                      local_b8 = uVar14;
                    }
                    iVar9 = FUN_0010b0f4(piVar11,1);
                    if ((uVar14 != *(byte *)(uVar14 + 0x10 + iVar9)) && ((int)local_b4 < 0)) {
                      (**(code **)(*piVar11 + 0x88))(piVar11,2,uVar14,uVar14);
                      *(undefined1 *)((int)&local_3c + uVar14) = 0;
                      local_b4 = uVar14;
                    }
                    iVar9 = FUN_0010b0f4(piVar12,1);
                    if ((uVar14 != *(byte *)(uVar14 + 0x10 + iVar9)) && ((int)local_b0 < 0)) {
                      (**(code **)(*piVar12 + 0x88))(piVar12,2,uVar14,uVar14);
                      *(undefined1 *)((int)&local_40 + uVar14) = 0;
                      local_b0 = uVar14;
                    }
                    uVar14 = uVar14 + 1;
                  } while (uVar14 != 4);
                  piVar10[0x27] = local_38;
                  piVar11[0x27] = local_3c;
                  piVar12[0x27] = local_40;
                  uVar14 = param_2[5];
                  if ((uVar14 & 0x200) == 0) {
                    iVar9 = 0;
                  }
                  else {
                    iVar9 = FUN_0010b180(param_2,param_2[0x21]);
                    uVar14 = param_2[5];
                  }
                  local_64 = 0;
                  local_60 = 0;
                  local_50 = 0;
                  if ((uVar14 & 0x200) != 0) {
                    FUN_0010a980(param_2,&local_64);
                  }
                  iVar18 = param_1[1];
                  local_7c = 0;
                  local_78 = 0;
                  local_68 = 0;
                  local_94 = 0;
                  local_90 = 0;
                  local_80 = 0;
                  local_ac = 0;
                  local_a8 = 0;
                  local_98 = 0;
                  uVar7 = FUN_0010b0f4(local_dc,1);
                  FUN_0010a40a(&local_ac,uVar7);
                  uVar7 = FUN_0010b0f4(local_e0,1);
                  FUN_0010a40a(&local_7c,uVar7);
                  uVar7 = FUN_0010b0f4(local_e0,2);
                  FUN_0010a40a(&local_94,uVar7);
                  local_4c = 0;
                  local_48 = 0;
                  local_44 = 0;
                  FUN_00109d1c(param_1,&local_4c,0xffffffff);
                  FUN_001a7d72(param_1);
                  FUN_0010da48(param_1,0x14,*(undefined4 *)(param_3 + 8));
                  if (iVar9 != 0) {
                    FUN_0010c568(param_1,&local_64,0,*(undefined4 *)(param_3 + 8));
                    if (*(int *)(param_3 + 0x46c) < *(int *)(iVar9 + 0x160)) {
                      *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar9 + 0x160) = *(int *)(param_3 + 0x46c) + 1;
                    }
                  }
                  FUN_00109d48(param_1,&local_4c);
                  *(char *)(param_1 + 0x48) = (char)param_2[0x48];
                  param_1[0x49] = iVar5;
                  uVar7 = FUN_0010b0f4(param_1,3);
                  FUN_0010a40a(uVar7,&local_ac);
                  uVar7 = FUN_0010b0f4(param_1,1);
                  FUN_0010a40a(uVar7,&local_7c);
                  uVar7 = FUN_0010b0f4(param_1,2);
                  FUN_0010a40a(uVar7,&local_94);
                  iVar5 = 0;
                  do {
                    if (*(char *)((int)&local_28 + iVar5) == '\0') {
                      iVar9 = FUN_0010b0f4(param_1,1);
                      if (*(char *)(iVar5 + 0x10 + iVar9) == '\x04') {
                        (**(code **)(*param_1 + 0x88))(param_1,1,iVar5,local_b8);
                      }
                      iVar9 = FUN_0010b0f4(param_1,2);
                      if (*(char *)(iVar5 + 0x10 + iVar9) == '\x04') {
                        (**(code **)(*param_1 + 0x88))(param_1,2,iVar5,local_b4);
                      }
                      iVar9 = FUN_0010b0f4(param_1,3);
                      if (*(char *)(iVar5 + 0x10 + iVar9) == '\x04') {
                        (**(code **)(*param_1 + 0x88))(param_1,3,iVar5,local_b0);
                      }
                    }
                    iVar5 = iVar5 + 1;
                  } while (iVar5 != 4);
                  param_1[0x25] = param_1[0x53];
                  param_1[0x26] = 0;
                  FUN_000e9596(*(undefined4 *)(iVar18 + 0x158),iVar18,param_1);
                  FUN_0010ba02(param_1,1,piVar10,0,*(undefined4 *)(param_3 + 8));
                  FUN_0010ba02(param_1,2,piVar11,0,*(undefined4 *)(param_3 + 8));
                  FUN_0010ba02(param_1,3,piVar12,0,*(undefined4 *)(param_3 + 8));
                  FUN_000e956e(param_1[0x56],param_1,piVar10);
                  FUN_000e956e(param_1[0x56],param_1,piVar11);
                  FUN_000e956e(param_1[0x56],param_1,piVar12);
                  param_1[0x27] = local_28;
                  iVar5 = *(int *)(param_3 + 0x46c);
                  iVar9 = FUN_0010b180(param_2,1);
                  if (iVar5 < *(int *)(iVar9 + 0x160)) {
                    *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar9 + 0x160) = iVar5 + 1;
                  }
                  if (local_e0 == param_2) {
                    iVar5 = *(int *)(param_3 + 0x46c);
                    iVar9 = FUN_0010b180(local_e0,2);
                    if (iVar5 < *(int *)(iVar9 + 0x160)) {
                      *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar9 + 0x160) = iVar5 + 1;
                    }
                  }
                  piVar15 = (int *)FUN_0010b180(piVar10,1);
                  cVar3 = (**(code **)(*piVar15 + 0x60))(piVar15);
                  if (cVar3 != '\0') {
                    uVar7 = *(undefined4 *)(param_3 + 8);
                    uVar8 = FUN_0010b180(piVar10,1);
                    FUN_00111842(uVar8,piVar10,uVar7);
                  }
                  piVar10 = (int *)FUN_0010b180(piVar11,1);
                  cVar3 = (**(code **)(*piVar10 + 0x60))(piVar10);
                  if (cVar3 != '\0') {
                    uVar7 = *(undefined4 *)(param_3 + 8);
                    uVar8 = FUN_0010b180(piVar11,1);
                    FUN_00111842(uVar8,piVar11,uVar7);
                  }
                  piVar10 = (int *)FUN_0010b180(piVar12,1);
                  cVar3 = (**(code **)(*piVar10 + 0x60))(piVar10);
                  if (cVar3 != '\0') {
                    uVar7 = *(undefined4 *)(param_3 + 8);
                    uVar8 = FUN_0010b180(piVar12,1);
                    FUN_00111842(uVar8,piVar12,uVar7);
                  }
                  FUN_0010b3fe(param_2,*(undefined4 *)(param_3 + 8));
                  return 1;
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_00164104 @ 0x164104 (3602 bytes) */
int FUN_00164104(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  float fVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  char *pcVar19;
  longdouble lVar20;
  float *local_138;
  float *local_134;
  float *local_130;
  float *local_12c;
  int local_10c;
  int *local_104;
  int *local_100;
  int local_ec;
  int local_e4;
  int local_dc;
  int local_8c;
  int *local_84;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_60;
  float local_5c [4];
  float local_4c [4];
  float local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_104 = param_1;
  cVar7 = (**(code **)(*param_1 + 100))(param_1);
  if (cVar7 == '\0') {
    return 0;
  }
  cVar7 = (**(code **)(*param_2 + 100))(param_2);
  if (cVar7 == '\0') {
    return 0;
  }
  iVar8 = FUN_0010b180(param_2,1);
  if (iVar8 == 0) {
    iVar8 = param_2[0x2c];
  }
  else {
    iVar8 = FUN_0010b180(param_2,1);
    iVar8 = *(int *)(iVar8 + 0x98);
  }
  cVar7 = FUN_0012df9c(iVar8);
  if (cVar7 == '\0') {
    return 0;
  }
  iVar8 = FUN_0010b0f4(param_1,0);
  local_20 = *(int *)(iVar8 + 0x10);
  iVar8 = FUN_0010b0f4(param_2,0);
  local_24 = *(undefined4 *)(iVar8 + 0x10);
  iVar8 = 1;
  do {
    if ((*(char *)((int)&local_24 + iVar8 + 3) != '\x01') &&
       (*(char *)((int)&local_28 + iVar8 + 3) != '\x01')) {
      return 0;
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 != 5);
  cVar7 = FUN_000e1402(*(undefined4 *)(param_3 + 8),0x30);
  if (cVar7 != '\0') {
    if ((*(unsigned char *)((unsigned char *)&(local_20) + 3)) == '\0') {
      return 0;
    }
    if ((*(unsigned char *)((unsigned char *)&(local_24) + 3)) == '\0') {
      return 0;
    }
  }
  if ((char)param_2[0x48] != '\0') {
    return 0;
  }
  local_10c = param_1[0x49];
  iVar8 = param_2[0x49];
  iVar9 = FUN_0010b180(param_1,1);
  iVar10 = FUN_0010b180(param_2,1);
  if (iVar9 == iVar10) {
    uVar18 = param_1[0x2e];
    if ((((byte)param_2[0x2e] & 1) == ((byte)uVar18 & 1)) &&
       (((byte)((uint)param_2[0x2e] >> 1) & 1) == ((byte)(uVar18 >> 1) & 1))) {
      iVar9 = FUN_0010b6e4(param_2,1);
      iVar10 = FUN_0010b6e4(param_1,1);
      if ((iVar9 == iVar10) && (local_10c == iVar8)) {
        iVar8 = FUN_0010b0f4(param_1,1);
        local_28 = *(undefined4 *)(iVar8 + 0x10);
        iVar8 = FUN_0010b0f4(param_2,1);
        local_2c = *(undefined4 *)(iVar8 + 0x10);
        local_30 = DAT_001cc5a4;
        iVar8 = 1;
        do {
          if (*(char *)((int)&local_24 + iVar8 + 3) == '\0') {
            *(undefined1 *)((int)&local_34 + iVar8 + 3) =
                 *(undefined1 *)((int)&local_2c + iVar8 + 3);
          }
          else if (*(char *)((int)&local_28 + iVar8 + 3) == '\0') {
            *(undefined1 *)((int)&local_34 + iVar8 + 3) =
                 *(undefined1 *)((int)&local_30 + iVar8 + 3);
          }
          uVar14 = local_30;
          iVar8 = iVar8 + 1;
        } while (iVar8 != 5);
        iVar8 = 1;
        do {
          cVar7 = *(char *)((int)&local_28 + iVar8 + 3);
          if (cVar7 != '\x01') {
            *(char *)((int)&local_24 + iVar8 + 3) = cVar7;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 != 5);
        param_1[0x27] = local_20;
        iVar8 = FUN_0010b0f4(param_1,1);
        *(undefined4 *)(iVar8 + 0x10) = uVar14;
        FUN_0010ba02(param_1,param_1[0x21],0,0,*(undefined4 *)(param_3 + 8));
        param_1[0x21] = param_1[0x21] + -1;
        param_1[5] = param_1[5] & 0xfffffdff;
        uVar18 = param_2[5];
        if ((uVar18 & 0x200) == 0) {
          iVar8 = 0;
        }
        else {
          iVar8 = FUN_0010b180(param_2,param_2[0x21]);
          uVar18 = param_2[5];
        }
        local_74 = 0;
        local_70 = 0;
        local_60 = 0;
        if ((uVar18 & 0x200) != 0) {
          FUN_0010a980(param_2,&local_74);
        }
        if (iVar8 != 0) {
          FUN_0010c568(param_1,&local_74,0,*(undefined4 *)(param_3 + 8));
          if (*(int *)(param_3 + 0x46c) < *(int *)(iVar8 + 0x160)) {
            *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
          }
          else {
            *(int *)(iVar8 + 0x160) = *(int *)(param_3 + 0x46c) + 1;
          }
        }
        goto LAB_0016490a;
      }
      goto LAB_00164263;
    }
  }
  else {
LAB_00164263:
    uVar18 = param_1[0x2e];
  }
  if (((((uVar18 & 1) == 0) && ((uVar18 & 2) == 0)) && ((char)param_1[0x48] == '\0')) &&
     (param_1[0x49] == 0)) {
    bVar5 = true;
    iVar9 = 0;
    do {
      iVar10 = FUN_0010b0f4(param_1,0);
      if ((*(char *)(iVar9 + 0x10 + iVar10) == '\x01') &&
         (iVar10 = FUN_0010b0f4(param_2,0), *(char *)(iVar9 + 0x10 + iVar10) == '\x01')) {
        bVar5 = false;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != 4);
    if ((bVar5) &&
       ((cVar7 = FUN_000f7c08(param_1,1,param_1,param_3), cVar7 != '\0' ||
        (((*(byte *)((int)param_2 + 0x15) & 2) == 0 &&
         (cVar7 = FUN_000f7c08(param_2,1,param_2,param_3), cVar7 != '\0')))))) {
      return 0;
    }
  }
  pfVar11 = local_4c;
  do {
    *pfVar11 = NAN;
    pfVar11 = pfVar11 + 1;
  } while (&local_3c != pfVar11);
  if (iVar8 == 0) {
    if (local_10c == 0) {
      local_ec = 0;
      local_138 = local_4c;
      do {
        iVar8 = FUN_0010b0f4(param_2,0);
        if (*(char *)(local_ec + 0x10 + iVar8) == '\x01') {
          *local_138 = 0.0;
        }
        else {
          iVar8 = FUN_0010b0f4(param_2,1);
          bVar1 = *(byte *)(local_ec + 0x10 + iVar8);
          iVar8 = FUN_0010b180(param_2,1);
          if (((int)*(char *)(iVar8 + 0x15c) >> (bVar1 & 0x1f) & 1U) == 0) {
            return 0;
          }
          *local_138 = *(float *)(iVar8 + 0x20 + (uint)bVar1 * 0x18);
        }
        local_ec = local_ec + 1;
        local_138 = local_138 + 1;
      } while (local_ec != 4);
      local_100 = param_2;
      local_10c = 0;
    }
    else {
      local_100 = param_2;
      piVar2 = local_104;
LAB_001642c7:
      local_104 = piVar2;
      lVar20 = (longdouble)FUN_0010fd78(local_10c);
      local_e4 = 0;
      local_134 = local_4c;
      do {
        iVar8 = FUN_0010b0f4(local_100,0);
        if (*(char *)(local_e4 + 0x10 + iVar8) == '\x01') {
          *local_134 = 0.0;
        }
        else {
          iVar8 = FUN_0010b0f4(local_100,1);
          bVar1 = *(byte *)(local_e4 + 0x10 + iVar8);
          iVar8 = FUN_0010b180(local_100,1);
          if (((int)*(char *)(iVar8 + 0x15c) >> (bVar1 & 0x1f) & 1U) == 0) {
            return 0;
          }
          *local_134 = (float)lVar20 * *(float *)(iVar8 + 0x20 + (uint)bVar1 * 0x18);
        }
        local_e4 = local_e4 + 1;
        local_134 = local_134 + 1;
      } while (local_e4 != 4);
    }
  }
  else {
    if (local_10c == 0) {
      local_10c = iVar8;
      piVar2 = param_2;
      local_100 = local_104;
      goto LAB_001642c7;
    }
    lVar20 = (longdouble)FUN_0010fd78(iVar8);
    local_dc = 0;
    local_130 = local_4c;
    do {
      iVar8 = FUN_0010b0f4(param_2,0);
      if (*(char *)(local_dc + 0x10 + iVar8) == '\x01') {
        *local_130 = 0.0;
      }
      else {
        iVar8 = FUN_0010b0f4(param_2,1);
        bVar1 = *(byte *)(local_dc + 0x10 + iVar8);
        iVar8 = FUN_0010b180(param_2,1);
        if (((int)*(char *)(iVar8 + 0x15c) >> (bVar1 & 0x1f) & 1U) == 0) {
          return 0;
        }
        *local_130 = (float)lVar20 * *(float *)(iVar8 + 0x20 + (uint)bVar1 * 0x18);
      }
      local_dc = local_dc + 1;
      local_130 = local_130 + 1;
    } while (local_dc != 4);
    local_100 = param_2;
  }
  pfVar11 = local_5c;
  do {
    *pfVar11 = NAN;
    pfVar11 = pfVar11 + 1;
  } while (local_4c != pfVar11);
  lVar20 = (longdouble)FUN_0010fd78(local_10c);
  local_34 = local_20;
  iVar8 = 1;
  do {
    cVar7 = *(char *)((int)&local_28 + iVar8 + 3);
    if (cVar7 != '\x01') {
      *(char *)((int)&local_38 + iVar8 + 3) = cVar7;
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 != 5);
  iVar8 = 0;
  local_12c = local_5c;
  do {
    iVar9 = FUN_0010b0f4(param_1,0);
    if (*(char *)(iVar8 + 0x10 + iVar9) == '\0') {
      *local_12c = (float)lVar20;
    }
    else {
      FUN_0010b0f4(param_2,0);
      *local_12c = 0.0;
    }
    iVar8 = iVar8 + 1;
    local_12c = local_12c + 1;
  } while (iVar8 != 4);
  uVar12 = FUN_000f5fea(local_34);
  uVar14 = DAT_001cc5a0;
  local_38 = FUN_000f5b96(DAT_001cc5a0,uVar12);
  piVar2 = *(int **)(*(int *)(param_3 + 8) + 0x54);
  iVar8 = (**(code **)(*piVar2 + 0x154))(piVar2,param_3,local_5c,&local_38);
  uVar12 = FUN_000f5fea(local_34);
  local_3c = (float)FUN_000f5b96(uVar14,uVar12);
  piVar2 = *(int **)(*(int *)(param_3 + 8) + 0x54);
  iVar9 = (**(code **)(*piVar2 + 0x154))(piVar2,param_3,local_4c,&local_3c);
  if (iVar8 == 0) {
    return 1;
  }
  if (iVar9 == 0) {
    return 1;
  }
  if (*(int *)(param_3 + 0x46c) < *(int *)(iVar8 + 0x160)) {
    *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
  }
  else {
    *(int *)(iVar8 + 0x160) = *(int *)(param_3 + 0x46c) + 1;
  }
  if (*(int *)(param_3 + 0x46c) < *(int *)(iVar9 + 0x160)) {
    *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
  }
  else {
    *(int *)(iVar9 + 0x160) = *(int *)(param_3 + 0x46c) + 1;
  }
  *(undefined4 *)(iVar9 + 0x9c) = DAT_001cc6d0;
  iVar10 = local_104[0x48];
  iVar13 = FUN_00109e42(param_1,param_3);
  uVar14 = FUN_0010b180(local_104,1);
  iVar15 = FUN_0010b0f4(local_104,1);
  local_30 = *(undefined4 *)(iVar15 + 0x10);
  iVar15 = FUN_0010b0f4(local_104,0);
  iVar15 = FUN_000f5950(*(undefined4 *)(iVar15 + 0x10));
  iVar16 = FUN_0010b0f4(local_104,1);
  cVar7 = *(char *)(iVar15 + 0x10 + iVar16);
  iVar15 = 0;
  pcVar19 = (char *)&local_30;
  do {
    if (*(char *)((int)&local_34 + iVar15) == '\0') {
      if ((local_5c[iVar15] != 0.0) || (NAN(local_5c[iVar15]))) {
        if (*pcVar19 == '\x04') {
          *pcVar19 = (char)iVar15;
        }
      }
      else {
        *pcVar19 = cVar7;
      }
    }
    else {
      *pcVar19 = '\x04';
    }
    iVar15 = iVar15 + 1;
    pcVar19 = pcVar19 + 1;
  } while (iVar15 != 4);
  uVar18 = local_104[0x2e];
  uVar3 = local_100[0x2e];
  uVar17 = param_2[5];
  if ((uVar17 & 0x200) == 0) {
    local_8c = 0;
  }
  else {
    local_8c = FUN_0010b180(param_2,param_2[0x21]);
    uVar17 = param_2[5];
  }
  local_74 = 0;
  local_70 = 0;
  local_60 = 0;
  if ((uVar17 & 0x200) != 0) {
    FUN_0010a980(param_2,&local_74);
  }
  iVar15 = param_1[0x26];
  iVar16 = param_1[0x25];
  uVar17 = param_1[5];
  iVar4 = param_1[3];
  local_84 = (int *)param_1[1];
  if (param_2 == local_84) {
    local_84 = (int *)param_2[1];
  }
  FUN_001a7d72(param_1);
  FUN_0010da48(param_1,0x14,*(undefined4 *)(param_3 + 8));
  param_1[0x25] = iVar16;
  param_1[0x26] = iVar15;
  if ((uVar17 & 2) != 0) {
    param_1[5] = param_1[5] | 2;
  }
  param_1[3] = iVar4;
  param_1[0x27] = local_34;
  *(char *)(param_1 + 0x48) = (char)iVar10;
  param_1[0x49] = 0;
  FUN_0010ba02(param_1,1,uVar14,0,*(undefined4 *)(param_3 + 8));
  uVar14 = local_30;
  iVar10 = FUN_0010b0f4(param_1,1);
  *(undefined4 *)(iVar10 + 0x10) = uVar14;
  FUN_00109c0e(param_1 + 0x29,1,(byte)uVar18 & 1);
  FUN_00109c0e(param_1 + 0x29,2,(byte)(uVar18 >> 1) & 1);
  FUN_0010ba02(param_1,2,iVar8,0,*(undefined4 *)(param_3 + 8));
  uVar14 = local_38;
  iVar8 = FUN_0010b0f4(param_1,2);
  *(undefined4 *)(iVar8 + 0x10) = uVar14;
  FUN_0010ba02(param_1,3,iVar9,0,*(undefined4 *)(param_3 + 8));
  fVar6 = local_3c;
  iVar8 = FUN_0010b0f4(param_1,3);
  *(float *)(iVar8 + 0x10) = fVar6;
  FUN_00109c0e(param_1 + 0x35,1,(byte)uVar3 & 1);
  FUN_00109c0e(param_1 + 0x35,2,(byte)(uVar3 >> 1) & 1);
  param_1[0x58] = iVar13 + *(int *)(param_3 + 0x46c);
  if (local_8c != 0) {
    FUN_0010c568(param_1,&local_74,0,*(undefined4 *)(param_3 + 8));
    if (*(int *)(param_3 + 0x46c) < *(int *)(local_8c + 0x160)) {
      *(int *)(local_8c + 0x160) = *(int *)(local_8c + 0x160) + 1;
    }
    else {
      *(int *)(local_8c + 0x160) = *(int *)(param_3 + 0x46c) + 1;
    }
  }
  FUN_000e9596(local_84[0x56],local_84,param_1);
LAB_0016490a:
  FUN_0010b3fe(param_2,*(undefined4 *)(param_3 + 8));
  return 1;
}

/* FUN_00164f1e @ 0x164f1e (272 bytes) */
int FUN_00164f1e(param_1, param_2)
  int *param_1;
  int param_2;
{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = (**(code **)(*param_1 + 100))(param_1);
  if ((((cVar1 != '\0') || (*(int *)(param_1[0x22] + 8) == 0x13)) &&
      ((*(byte *)((int)param_1 + 0x15) & 2) != 0)) &&
     ((*(byte *)(*(int *)(*(int *)(param_2 + 8) + 0x54) + 9) & 1) != 0)) {
    uVar2 = FUN_0010b180(param_1,param_1[0x21]);
    cVar1 = ((int (*)())FUN_0015eb64)(param_1,uVar2,param_2);
    if (((((cVar1 != '\0') || (cVar1 = ((int (*)())FUN_0016011e)(param_1,uVar2,param_2), cVar1 != '\0')) ||
         ((cVar1 = ((int (*)())FUN_00160d3e)(param_1,uVar2,param_2), cVar1 != '\0' ||
          ((cVar1 = ((int (*)())FUN_0015f878)(param_1,uVar2,param_2), cVar1 != '\0' ||
           (cVar1 = ((int (*)())FUN_0016322a)(param_1,uVar2,param_2), cVar1 != '\0')))))) ||
        (cVar1 = ((int (*)())FUN_00161938)(param_1,uVar2,param_2), cVar1 != '\0')) ||
       (cVar1 = ((int (*)())FUN_00164104)(param_1,uVar2,param_2), cVar1 != '\0')) {
      return 1;
    }
  }
  return 0;
}

/* FUN_0016502e @ 0x16502e (2012 bytes) */
int FUN_0016502e(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined1 uVar17;
  int *local_d0;
  char local_c9;
  int *local_bc;
  byte local_8c;
  byte local_7c;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  
  iVar2 = *(int *)(param_2 + 8);
  if (((((param_1 != (int *)0x0) && ((*(byte *)((int)param_1 + 0x15) & 2) != 0)) &&
       ((char)param_1[0x48] == '\0')) &&
      ((param_1[0x49] == 0 &&
       (piVar9 = (int *)FUN_0010b180(param_1,param_1[0x21]), (char)piVar9[0x48] == '\0')))) &&
     (piVar9[0x49] == 0)) {
    cVar6 = (**(code **)(*param_1 + 100))(param_1);
    local_c9 = (**(code **)(*piVar9 + 100))(piVar9);
    if ((cVar6 != '\0') && (local_c9 != '\0')) {
      iVar10 = FUN_0010b180(param_1,1);
      iVar16 = FUN_0010b180(piVar9,1);
      if (iVar10 == iVar16) {
        return 0;
      }
    }
    cVar7 = FUN_000f5f5e(piVar9);
    cVar8 = FUN_000f5f5e(param_1);
    if ((cVar7 != '\0') || (cVar8 != '\0')) {
      iVar10 = FUN_0010b0f4(piVar9,0);
      local_2c = *(int *)(iVar10 + 0x10);
      iVar10 = FUN_0010b0f4(param_1,0);
      local_24 = *(int *)(iVar10 + 0x10);
      if ((local_24 != DAT_001cc5a8) && (DAT_001cc5a8 != local_2c)) {
        local_d0 = piVar9;
        if (cVar6 == '\0') {
          if (local_c9 == '\0') {
            return 0;
          }
          local_d0 = param_1;
          local_c9 = '\0';
          param_1 = piVar9;
        }
        cVar6 = FUN_0010a62e(local_d0,param_2);
        if (cVar6 == '\0') {
          cVar6 = (**(code **)(*local_d0 + 0x4c))(local_d0);
          local_20 = DAT_001cc5a0;
        }
        else {
          cVar6 = (**(code **)(*local_d0 + 100))(local_d0);
          local_20 = DAT_001cc5a0;
        }
        DAT_001cc5a0 = local_20;
        if (cVar6 != '\0') {
          iVar10 = 1;
          do {
            if ((*(char *)((int)&local_28 + iVar10 + 3) != '\x01') &&
               (*(char *)((int)&local_30 + iVar10 + 3) != '\x01')) {
              return 0;
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 != 5);
          local_44 = 0;
          local_40 = 0x3f800000;
          local_3c = 0;
          local_38 = 0;
          iVar10 = (**(code **)(**(int **)(iVar2 + 0x54) + 0x154))
                             (*(int **)(iVar2 + 0x54),param_2,&local_44,&local_20);
          if (iVar10 != 0) {
            iVar11 = FUN_000f5ede(local_2c);
            iVar12 = FUN_000f5ede(local_24);
            iVar16 = iVar12;
            if (iVar12 < 0) {
              iVar16 = iVar11;
            }
            if (local_20 == DAT_001cc5a0) {
              local_20 = *(int *)(&DAT_001cc6c0 + iVar16 * 4);
            }
            else if (iVar16 == 0) {
              uVar3 = (uint)local_20 >> 8;
              uVar17 = (undefined1)local_20;
              (*(unsigned short *)((unsigned char *)&(local_20) + 0)) = CONCAT11(uVar17,(char)uVar3);
              cVar6 = (**(code **)(**(int **)(iVar2 + 0x54) + 0x100))
                                (*(int **)(iVar2 + 0x54),&local_20);
              if (cVar6 == '\0') {
                return 0;
              }
            }
            uVar13 = FUN_0010b180(param_1,1);
            if (local_c9 == '\0') {
              local_bc = local_d0;
            }
            else {
              local_bc = (int *)FUN_0010b180(local_d0,1);
            }
            iVar16 = param_1[1];
            iVar11 = param_1[0x56];
            uVar3 = param_1[5];
            iVar14 = FUN_00109e42(param_1,param_2);
            uVar4 = param_1[0x2e];
            iVar15 = FUN_0010b0f4(param_1,1);
            local_30 = *(undefined4 *)(iVar15 + 0x10);
            if (local_c9 == '\0') {
              local_34 = DAT_001cc5a0;
              local_7c = 0;
              local_8c = 0;
            }
            else {
              local_8c = (byte)local_d0[0x2e] & 1;
              local_7c = (byte)((uint)local_d0[0x2e] >> 1) & 1;
              iVar15 = FUN_0010b0f4(local_d0,1);
              local_34 = *(int *)(iVar15 + 0x10);
            }
            iVar15 = param_1[0x26];
            iVar5 = param_1[0x25];
            FUN_001a7d72(param_1);
            if (iVar12 < 0) {
              FUN_0010da48(param_1,0x26,*(undefined4 *)(param_2 + 8));
            }
            else {
              FUN_0010da48(param_1,0x24,*(undefined4 *)(param_2 + 8));
            }
            iVar12 = FUN_0010b0f4(param_1,1);
            *(int *)(iVar12 + 0x10) = DAT_001cc5a0;
            FUN_0010ba02(param_1,1,iVar10,0,iVar2);
            iVar10 = local_20;
            iVar12 = FUN_0010b0f4(param_1,1);
            *(int *)(iVar12 + 0x10) = iVar10;
            FUN_0010ba02(param_1,2,local_bc,0,iVar2);
            FUN_00109c0e(param_1 + 0x2f,1,local_8c);
            FUN_00109c0e(param_1 + 0x2f,2,local_7c);
            FUN_0010ba02(param_1,3,uVar13,0,iVar2);
            FUN_00109c0e(param_1 + 0x35,1,(byte)uVar4 & 1);
            FUN_00109c0e(param_1 + 0x35,2,(byte)(uVar4 >> 1) & 1);
            iVar10 = FUN_000f5950(local_24);
            uVar17 = *(undefined1 *)((int)&local_30 + iVar10);
            iVar10 = FUN_000f5950(local_2c);
            uVar1 = *(undefined1 *)((int)&local_34 + iVar10);
            local_28 = local_24;
            iVar10 = 1;
            do {
              cVar6 = *(char *)((int)&local_30 + iVar10 + 3);
              if (cVar6 != '\x01') {
                *(char *)((int)&local_2c + iVar10 + 3) = cVar6;
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 != 5);
            param_1[0x27] = local_24;
            param_1[0x25] = iVar5;
            param_1[0x26] = iVar15;
            iVar10 = 0;
            do {
              if (*(char *)((int)&local_28 + iVar10) == '\x01') {
                (**(code **)(*param_1 + 0x88))(param_1,2,iVar10,4);
                (**(code **)(*param_1 + 0x88))(param_1,3,iVar10,4);
                (**(code **)(*param_1 + 0x88))(param_1,1,iVar10,4);
              }
              else if (*(char *)((int)&local_24 + iVar10) == '\0') {
                (**(code **)(*param_1 + 0x88))(param_1,2,iVar10,uVar1);
                (**(code **)(*param_1 + 0x88))
                          (param_1,3,iVar10,*(undefined1 *)((int)&local_30 + iVar10));
              }
              else if (*(char *)((int)&local_2c + iVar10) == '\0') {
                (**(code **)(*param_1 + 0x88))
                          (param_1,2,iVar10,*(undefined1 *)((int)&local_34 + iVar10));
                (**(code **)(*param_1 + 0x88))(param_1,3,iVar10,uVar17);
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 != 4);
            if ((uVar3 & 2) != 0) {
              param_1[5] = param_1[5] | 2;
            }
            param_1[0x58] = iVar14 + *(int *)(param_2 + 0x46c);
            FUN_000e9596(iVar11,iVar16,param_1);
            if ((*(byte *)((int)local_d0 + 0x15) & 2) != 0) {
              uVar13 = FUN_0010b180(local_d0,local_d0[0x21]);
              FUN_0010c18e(param_1,uVar13,0,iVar2);
            }
            if (local_c9 != '\0') {
              (**(code **)(*local_d0 + 0xc))(local_d0,0,*(undefined4 *)(param_2 + 8));
              return 1;
            }
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_00165812 @ 0x165812 (522 bytes) */
int FUN_00165812(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (*(int *)(*(int *)(param_3 + 0x88) + 8) != 0x25) {
    return 0;
  }
  piVar2 = (int *)FUN_0010b180(param_3,1);
  cVar1 = (**(code **)(*piVar2 + 0x5c))(piVar2);
  if (cVar1 != '\0') {
    piVar2 = (int *)FUN_0010b180(param_3,2);
    cVar1 = (**(code **)(*piVar2 + 0x5c))(piVar2);
    if (cVar1 != '\0') {
      piVar2 = (int *)FUN_0010b180(param_3,3);
      cVar1 = (**(code **)(*piVar2 + 0x5c))(piVar2);
      if (cVar1 != '\0') {
        uVar5 = FUN_0010b180(param_3,1);
        uVar6 = FUN_0010b180(param_3,2);
        uVar7 = FUN_0010b180(param_3,3);
        iVar3 = FUN_0010b180(uVar5,1);
        iVar4 = FUN_0010b180(uVar6,1);
        if (iVar3 == iVar4) {
          iVar3 = FUN_0010b180(uVar5,2);
          iVar4 = FUN_0010b180(uVar6,2);
          if (iVar3 == iVar4) {
            iVar3 = FUN_0010b180(uVar6,1);
            iVar4 = FUN_0010b180(uVar7,1);
            if (iVar3 == iVar4) {
              FUN_0010b180(uVar6,2);
              FUN_0010b180(uVar7,2);
            }
          }
        }
        goto LAB_00165878;
      }
    }
  }
  iVar3 = FUN_0010b180(param_3,1);
  iVar4 = FUN_0010b180(param_3,2);
  if (iVar3 == iVar4) {
    FUN_0010b180(param_3,2);
    FUN_0010b180(param_3,3);
  }
LAB_00165878:
  iVar3 = FUN_0010b180(param_3,1);
  iVar4 = FUN_0010b180(param_3,2);
  if (iVar3 == iVar4) {
    FUN_0010b180(param_3,2);
    FUN_0010b180(param_3,3);
  }
  return 0;
}

/* FUN_00165a1c @ 0x165a1c (1146 bytes) */
int FUN_00165a1c(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  byte local_38;
  
  iVar2 = *(int *)(*(int *)(param_3 + 0x88) + 8);
  if ((iVar2 != 0x17) && (iVar2 != 0x19)) {
    return 0;
  }
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
  if (iVar2 < param_2) {
    return 0;
  }
  if ((*(byte *)(param_3 + 0x15) & 2) != 0) {
    return 0;
  }
  if (*(char *)(param_3 + 0x120) != '\0') {
    return 0;
  }
  if (*(int *)(param_3 + 0x124) != 0) {
    return 0;
  }
  piVar3 = *(int **)(*(int *)(param_4 + 8) + 0x54);
  cVar1 = (**(code **)(*piVar3 + 0x88))(piVar3);
  if ((cVar1 == '\0') &&
     (cVar1 = FUN_00119170(*(undefined4 *)(param_1[0x22] + 8),*(undefined4 *)(param_4 + 8)),
     cVar1 == '\0')) {
    return 0;
  }
  FUN_0010b180(param_1,param_2);
  piVar3 = (int *)FUN_0010b180(param_3,1);
  piVar4 = (int *)FUN_0010b180(param_3,2);
  if (piVar3 != piVar4) {
    cVar1 = (**(code **)(*piVar3 + 0x5c))(piVar3);
    if (cVar1 == '\0') {
      return 0;
    }
    cVar1 = (**(code **)(*piVar4 + 0x5c))(piVar4);
    if (cVar1 == '\0') {
      return 0;
    }
    if (*(int *)(piVar3[0x22] + 8) != *(int *)(piVar4[0x22] + 8)) {
      return 0;
    }
    iVar2 = FUN_0010b180(piVar3,1);
    iVar5 = FUN_0010b180(piVar4,1);
    if (iVar2 != iVar5) {
      return 0;
    }
    iVar2 = (**(code **)(*piVar3 + 0x14))(piVar3);
    if (1 < iVar2) {
      iVar2 = FUN_0010b180(piVar3,2);
      iVar5 = FUN_0010b180(piVar4,2);
      if (iVar2 != iVar5) {
        return 0;
      }
    }
  }
  if ((((byte)(*(uint *)(param_3 + 0xb8) >> 1) & 1) == ((byte)(*(uint *)(param_3 + 0xd0) >> 1) & 1))
     && (local_38 = (byte)*(uint *)(param_3 + 0xb8) & 1,
        ((byte)*(uint *)(param_3 + 0xd0) & 1 ^ 1) == local_38)) {
    iVar2 = FUN_0010b0f4(param_3,2);
    iVar2 = *(int *)(iVar2 + 0x10);
    iVar5 = FUN_0010b0f4(param_3,1);
    if (*(int *)(iVar5 + 0x10) == iVar2) {
      iVar2 = *(int *)(param_4 + 0x46c);
      cVar1 = (**(code **)(*piVar3 + 0x5c))(piVar3);
      if (cVar1 == '\0') {
        if (iVar2 < piVar3[0x58]) {
          piVar3[0x58] = piVar3[0x58] + 1;
        }
        else {
          piVar3[0x58] = iVar2 + 1;
        }
        uVar7 = *(undefined4 *)(param_4 + 8);
        piVar4 = piVar3;
      }
      else {
        piVar4 = (int *)FUN_0010a1c2(piVar3,*(undefined4 *)(param_4 + 8),0);
        piVar4[0x25] = piVar4[0x53];
        piVar4[0x26] = 0x31;
        FUN_000e9596(piVar3[0x56],piVar3,piVar4);
        iVar5 = iVar2 + 1;
        piVar4[0x58] = iVar5;
        iVar6 = FUN_0010b180(piVar4,1);
        if (iVar2 < *(int *)(iVar6 + 0x160)) {
          *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
        }
        else {
          *(int *)(iVar6 + 0x160) = iVar5;
        }
        if (1 < piVar4[0x21]) {
          iVar6 = FUN_0010b180(piVar4,2);
          if (iVar2 < *(int *)(iVar6 + 0x160)) {
            *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
          }
          else {
            *(int *)(iVar6 + 0x160) = iVar5;
          }
        }
        uVar7 = *(undefined4 *)(param_4 + 8);
      }
      FUN_0010ba02(param_1,param_2,piVar4,0,uVar7);
      iVar2 = FUN_0010b0f4(param_3,1);
      uVar7 = *(undefined4 *)(iVar2 + 0x10);
      iVar2 = FUN_0010b0f4(param_1,param_2);
      iVar2 = FUN_000f5610(uVar7,*(undefined4 *)(iVar2 + 0x10));
      if (param_2 == 0) {
        param_1[0x27] = iVar2;
      }
      else {
        iVar5 = FUN_0010b0f4(param_1,param_2);
        *(int *)(iVar5 + 0x10) = iVar2;
      }
      cVar1 = FUN_00119170(*(undefined4 *)(param_1[0x22] + 8),*(undefined4 *)(param_4 + 8));
      if (cVar1 == '\0') {
        FUN_00109c0e(param_1 + param_2 * 6 + 0x23,2,1);
      }
      else {
        FUN_00109c0e(param_1 + param_2 * 6 + 0x23,2,0);
      }
      if (*(int *)(*(int *)(param_3 + 0x88) + 8) == 0x19) {
        FUN_00109c0e(param_1 + param_2 * 6 + 0x23,1,1);
      }
      *(int *)(param_4 + 0x1bc) = *(int *)(param_4 + 0x1bc) + 1;
      FUN_0010b3fe(param_3,*(undefined4 *)(param_4 + 8));
      return 1;
    }
  }
  return 0;
}

/* FUN_00165e96 @ 0x165e96 (6789 bytes) */
int FUN_00165e96(param_1, param_2)
  void *param_1;
  int param_2;
{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  bool bVar6;
  char cVar7;
  byte bVar8;
  char cVar9;
  char cVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  void *pvVar22;
  undefined4 uVar23;
  byte bVar24;
  byte bVar25;
  int iVar26;
  bool bVar27;
  undefined1 local_199;
  int local_198;
  int local_194;
  int local_190;
  int local_18c;
  int local_188;
  int local_160;
  int local_15c;
  int local_148;
  int local_140;
  int local_12c;
  int local_128;
  int local_120;
  int local_11c;
  int *local_118;
  int *local_114;
  int *local_110;
  int local_10c;
  int local_d8;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_2c = 0x3f800000;
  local_28 = 0x3f800000;
  local_24 = 0x3f800000;
  local_20 = 0x3f800000;
  local_3c = 0x3f000000;
  local_38 = 0x3f000000;
  local_34 = 0x3f000000;
  local_30 = 0x3f000000;
  local_4c = 0x40000000;
  local_48 = 0x40000000;
  local_44 = 0x40000000;
  local_40 = 0x40000000;
  iVar13 = *(int *)(*(int *)((int)param_1 + 0x88) + 8);
  if (iVar13 == 0x12) {
LAB_00166360:
    local_199 = 0;
  }
  else {
    if (iVar13 != 0x14) {
      return 0;
    }
    piVar11 = (int *)FUN_0010b180(param_1,1);
    piVar12 = (int *)FUN_0010b180(param_1,2);
    iVar13 = piVar11[0x22];
    if (((*(int *)(iVar13 + 8) == 0x12) || (*(int *)(iVar13 + 8) == 0x9b)) ||
       (*(int *)(iVar13 + 8) == 0x9a)) {
      local_198 = 1;
      local_194 = 2;
LAB_00166b38:
      local_15c = *(int *)((int)param_1 + 0x124);
      iVar13 = FUN_0010b0f4(param_1,0);
      cVar7 = FUN_000f7dda(param_1,local_194,*(undefined4 *)(iVar13 + 0x10),&local_3c);
      if (cVar7 == '\0') {
        iVar13 = FUN_0010b0f4(param_1,0);
        cVar7 = FUN_000f7dda(param_1,local_194,*(undefined4 *)(iVar13 + 0x10),&local_4c);
        if (cVar7 == '\0') {
          return 0;
        }
        local_15c = local_15c + 1;
        piVar12 = *(int **)(*(int *)(param_2 + 8) + 0x54);
        cVar7 = (**(code **)(*piVar12 + 0xfc))(piVar12,local_15c,param_1);
        if (cVar7 == '\0') {
          return 0;
        }
        local_160 = 1;
      }
      else {
        local_15c = local_15c + -1;
        piVar12 = *(int **)(*(int *)(param_2 + 8) + 0x54);
        cVar7 = (**(code **)(*piVar12 + 0xfc))(piVar12,local_15c,param_1);
        if (cVar7 == '\0') {
          return 0;
        }
        local_160 = 0;
      }
      iVar13 = FUN_0010b180(piVar11,1);
      local_148 = FUN_0010b180(piVar11,2);
      iVar16 = FUN_0010b6e4(param_1,3);
      if ((*(byte *)((int)piVar11 + 0x15) & 2) != 0) {
        return 0;
      }
      iVar17 = FUN_0010b0f4(param_1,local_198);
      cVar7 = FUN_000f56f0(*(undefined4 *)(iVar17 + 0x10),DAT_001cc5a0);
      if (cVar7 == '\0') {
        return 0;
      }
      iVar17 = FUN_0010b6e4(param_1,local_198);
      if (iVar17 != 0) {
        return 0;
      }
      iVar17 = FUN_0010b180(param_1,3);
      if (local_148 == iVar17) {
        iVar17 = FUN_0010b0f4(piVar11,2);
        uVar2 = *(undefined4 *)(iVar17 + 0x10);
        iVar17 = FUN_0010b0f4(param_1,3);
        cVar7 = FUN_000f56f0(*(undefined4 *)(iVar17 + 0x10),uVar2);
        if ((cVar7 == '\0') || (iVar17 = FUN_0010b6e4(piVar11,2), iVar16 != iVar17))
        goto LAB_00166c79;
        if (*(int *)(piVar11[0x22] + 8) == 0x9a) {
          local_190 = 2;
          local_18c = 1;
          bVar27 = true;
          bVar6 = false;
        }
        else {
          local_190 = 2;
          local_18c = 1;
          bVar27 = false;
          bVar6 = false;
        }
      }
      else {
LAB_00166c79:
        iVar17 = FUN_0010b180(param_1,3);
        if (iVar13 != iVar17) {
          return 0;
        }
        iVar17 = FUN_0010b0f4(piVar11,1);
        uVar2 = *(undefined4 *)(iVar17 + 0x10);
        iVar17 = FUN_0010b0f4(param_1,3);
        cVar7 = FUN_000f56f0(*(undefined4 *)(iVar17 + 0x10),uVar2);
        if (cVar7 == '\0') {
          return 0;
        }
        iVar17 = FUN_0010b6e4(piVar11,1);
        if (iVar16 != iVar17) {
          return 0;
        }
        local_148 = iVar13;
        if (*(int *)(piVar11[0x22] + 8) == 0x9a) {
          local_190 = 1;
          local_18c = 2;
          bVar27 = false;
          bVar6 = true;
        }
        else {
          local_190 = 1;
          local_18c = 2;
          bVar27 = false;
          bVar6 = false;
        }
      }
      cVar7 = FUN_0010a62e(piVar11,param_2);
      if ((((cVar7 == '\0') || ((*(byte *)((int)param_1 + 0xe8) & 2) != 0)) ||
          ((*(byte *)((int)param_1 + local_198 * 0x18 + 0xa0) & 2) != 0)) ||
         (((*(byte *)(piVar11 + 0x2e) & 2) != 0 || ((*(byte *)(piVar11 + 0x34) & 2) != 0)))) {
        return 0;
      }
      iVar13 = FUN_0010b0f4(param_1,local_198);
      uVar18 = FUN_000f5bdc(*(undefined4 *)(iVar13 + 0x10));
      iVar13 = FUN_0010b0f4(piVar11,0);
      uVar19 = FUN_000f5fea(*(undefined4 *)(iVar13 + 0x10));
      if (uVar19 < uVar18) {
        return 0;
      }
      if (uVar19 != (uVar18 & uVar19)) {
        return 0;
      }
      if ((char)piVar11[0x48] != '\0') {
        return 0;
      }
      if (piVar11[0x49] != 0) {
        return 0;
      }
      if (((*(byte *)(piVar11 + local_190 * 6 + 0x28) & 1) != 0) || (bVar27)) {
        iVar13 = 1;
      }
      else {
        iVar13 = 0;
      }
      if (((*(byte *)(piVar11 + local_18c * 6 + 0x28) & 1) != 0) || (bVar6)) {
        iVar16 = 1;
      }
      else {
        iVar16 = 0;
      }
      bVar8 = (DAT_001cc5c0)[(iVar13 * 8 |
                (uint)(*(byte *)((int)param_1 + local_194 * 0x18 + 0xa0) & 1) |
                (uint)(*(byte *)((int)param_1 + local_198 * 0x18 + 0xa0) & 1) * 2 |
                (uint)(*(byte *)((int)param_1 + 0xe8) & 1) << 2 | iVar16 << 4 | local_160 << 5) * 4]
      ;
      if ((bVar8 & 1) == 0) goto LAB_00166360;
      *(int *)(param_2 + 0x1b0) = *(int *)(param_2 + 0x1b0) + 1;
      iVar13 = FUN_0010b0f4(param_1,0);
      uVar2 = *(undefined4 *)(iVar13 + 0x10);
      uVar1 = *(undefined1 *)((int)param_1 + 0x120);
      if ((*(byte *)((int)param_1 + 0x15) & 2) == 0) {
        local_140 = 0;
      }
      else {
        local_140 = FUN_0010b180(param_1,*(undefined4 *)((int)param_1 + 0x84));
      }
      iVar16 = FUN_00109e42(param_1,param_2);
      iVar13 = *(int *)((int)param_1 + 4);
      if (0 < *(int *)((int)param_1 + 0x84)) {
        iVar17 = 1;
        do {
          FUN_0010ba02(param_1,iVar17,0,0,*(undefined4 *)(param_2 + 8));
          iVar17 = iVar17 + 1;
        } while (iVar17 <= *(int *)((int)param_1 + 0x84));
      }
      uVar23 = *(undefined4 *)((int)param_1 + 0x98);
      uVar14 = *(undefined4 *)((int)param_1 + 0x94);
      uVar18 = *(uint *)((int)param_1 + 0x14);
      FUN_001a7d72(param_1);
      FUN_0010d8fc(param_1,0x12,*(undefined4 *)(param_2 + 8));
      *(undefined4 *)((int)param_1 + 0x9c) = uVar2;
      if ((bVar8 & 2) == 0) {
        local_12c = local_190;
        local_128 = local_18c;
      }
      else {
        local_12c = local_18c;
        local_128 = local_190;
      }
      *(undefined4 *)((int)param_1 + 0x94) = uVar14;
      *(undefined4 *)((int)param_1 + 0x98) = uVar23;
      if ((uVar18 & 2) != 0) {
        *(uint *)((int)param_1 + 0x14) = *(uint *)((int)param_1 + 0x14) | 2;
      }
      uVar2 = *(undefined4 *)(param_2 + 8);
      uVar23 = FUN_0010b180(piVar11,local_12c);
      FUN_0010ba02(param_1,1,uVar23,0,uVar2);
      uVar2 = *(undefined4 *)(param_2 + 8);
      uVar23 = FUN_0010b180(piVar11,local_128);
      FUN_0010ba02(param_1,2,uVar23,0,uVar2);
      iVar17 = FUN_0010b0f4(piVar11,local_12c);
      uVar2 = *(undefined4 *)(iVar17 + 0x10);
      iVar17 = FUN_0010b0f4(param_1,1);
      *(undefined4 *)(iVar17 + 0x10) = uVar2;
      iVar17 = FUN_0010b0f4(piVar11,local_128);
      uVar2 = *(undefined4 *)(iVar17 + 0x10);
      iVar17 = FUN_0010b0f4(param_1,2);
      *(undefined4 *)(iVar17 + 0x10) = uVar2;
      FUN_00109c0e((int)param_1 + 0xa4,1,bVar8 >> 2 & 1);
      FUN_00109c0e((int)param_1 + 0xbc,1,bVar8 >> 3 & 1);
      *(int *)((int)param_1 + 0x160) = iVar16 + *(int *)(param_2 + 0x46c);
      *(undefined1 *)((int)param_1 + 0x120) = uVar1;
      *(int *)((int)param_1 + 0x124) = local_15c;
      if (local_140 != 0) {
        FUN_0010c18e(param_1,local_140,0,*(undefined4 *)(param_2 + 8));
      }
      FUN_000e9596(*(undefined4 *)(iVar13 + 0x158),iVar13,param_1);
      iVar13 = FUN_00109e42(local_148,param_2);
      *(int *)(local_148 + 0x160) = iVar13 + -1 + *(int *)(param_2 + 0x46c);
      (**(code **)(*piVar11 + 0xc))(piVar11,0,*(undefined4 *)(param_2 + 8));
      local_199 = 0;
    }
    else {
      iVar13 = piVar12[0x22];
      if (((*(int *)(iVar13 + 8) == 0x12) || (*(int *)(iVar13 + 8) == 0x9b)) ||
         (*(int *)(iVar13 + 8) == 0x9a)) {
        local_198 = 2;
        local_194 = 1;
        piVar11 = piVar12;
        goto LAB_00166b38;
      }
      iVar13 = FUN_0010b0f4(param_1,0);
      cVar7 = FUN_000f7dda(param_1,2,*(undefined4 *)(iVar13 + 0x10),&local_2c);
      if (cVar7 == '\0') {
        return 0;
      }
      if (*(int *)((int)param_1 + 0x124) == 1) {
        iVar13 = FUN_0010b0f4(param_1,0);
        cVar7 = FUN_000f7dda(param_1,3,*(undefined4 *)(iVar13 + 0x10),&local_3c);
        if (cVar7 != '\0') {
          return 0;
        }
      }
      *(int *)(param_2 + 0x1b0) = *(int *)(param_2 + 0x1b0) + 1;
      uVar14 = FUN_0010b180(param_1,1);
      uVar18 = *(uint *)((int)param_1 + 0xb8);
      iVar13 = FUN_0010b0f4(param_1,1);
      uVar2 = *(undefined4 *)(iVar13 + 0x10);
      uVar15 = FUN_0010b180(param_1,3);
      uVar19 = *(uint *)((int)param_1 + 0xe8);
      iVar13 = FUN_0010b0f4(param_1,3);
      uVar23 = *(undefined4 *)(iVar13 + 0x10);
      bVar8 = *(byte *)((int)param_1 + 0xd0);
      if ((*(byte *)((int)param_1 + 0x15) & 2) == 0) {
        local_188 = 0;
      }
      else {
        local_188 = FUN_0010b180(param_1,*(undefined4 *)((int)param_1 + 0x84));
      }
      iVar16 = FUN_00109e42(param_1,param_2);
      uVar1 = *(undefined1 *)((int)param_1 + 0x120);
      uVar3 = *(undefined4 *)((int)param_1 + 0x124);
      iVar13 = *(int *)((int)param_1 + 4);
      iVar17 = FUN_0010b0f4(param_1,0);
      uVar21 = *(undefined4 *)(iVar17 + 0x10);
      uVar20 = *(undefined4 *)((int)param_1 + 0x98);
      uVar4 = *(undefined4 *)((int)param_1 + 0x94);
      uVar5 = *(uint *)((int)param_1 + 0x14);
      FUN_001a7d72(param_1);
      FUN_0010d8fc(param_1,0x12,*(undefined4 *)(param_2 + 8));
      *(undefined4 *)((int)param_1 + 0x94) = uVar4;
      *(undefined4 *)((int)param_1 + 0x98) = uVar20;
      if ((uVar5 & 2) != 0) {
        *(uint *)((int)param_1 + 0x14) = *(uint *)((int)param_1 + 0x14) | 2;
      }
      *(undefined4 *)((int)param_1 + 0x9c) = uVar21;
      if (local_188 != 0) {
        FUN_0010c18e(param_1,local_188,0,*(undefined4 *)(param_2 + 8));
      }
      FUN_0010ba02(param_1,1,uVar14,0,*(undefined4 *)(param_2 + 8));
      iVar26 = (int)param_1 + 0xa4;
      FUN_00109c0e(iVar26,1,(byte)uVar18 & 1);
      FUN_00109c0e(iVar26,2,(byte)(uVar18 >> 1) & 1);
      iVar17 = FUN_0010b0f4(param_1,1);
      *(undefined4 *)(iVar17 + 0x10) = uVar2;
      FUN_0010ba02(param_1,2,uVar15,0,*(undefined4 *)(param_2 + 8));
      FUN_00109c0e((int)param_1 + 0xbc,1,(byte)uVar19 & 1);
      FUN_00109c0e((int)param_1 + 0xbc,2,(byte)(uVar19 >> 1) & 1);
      iVar17 = FUN_0010b0f4(param_1,2);
      *(undefined4 *)(iVar17 + 0x10) = uVar23;
      FUN_00109c0e(iVar26,1,(*(byte *)((int)param_1 + 0xb8) & 1) != (bVar8 & 1));
      *(undefined1 *)((int)param_1 + 0x120) = uVar1;
      *(undefined4 *)((int)param_1 + 0x124) = uVar3;
      if (local_188 != 0) {
        FUN_0010c18e(param_1,local_188,0,*(undefined4 *)(param_2 + 8));
      }
      *(int *)((int)param_1 + 0x160) = iVar16 + *(int *)(param_2 + 0x46c);
      FUN_000e9596(*(undefined4 *)(iVar13 + 0x158),iVar13,param_1);
      local_199 = 1;
    }
  }
  iVar13 = FUN_0010b180(param_1,1);
  if (*(int *)(*(int *)(iVar13 + 0x88) + 8) == 0x13) {
    local_120 = 1;
    local_11c = 2;
  }
  else {
    iVar13 = FUN_0010b180(param_1,2);
    if (*(int *)(*(int *)(iVar13 + 0x88) + 8) != 0x13) {
      return local_199;
    }
    local_120 = 2;
    local_11c = 1;
  }
  piVar11 = (int *)FUN_0010b180(param_1,local_120);
  local_114 = (int *)FUN_0010b180(param_1,local_11c);
  if ((local_120 != 1) || (local_110 = local_114, *(int *)(local_114[0x22] + 8) != 0x13)) {
    local_110 = (int *)0x0;
  }
  local_10c = piVar11[0x58] - *(int *)(param_2 + 0x46c);
  local_118 = piVar11;
  if (local_10c < 0) {
    iVar13 = 0;
LAB_001673a0:
    local_10c = 0;
LAB_001673aa:
    iVar16 = iVar13;
    iVar17 = local_10c;
    if (iVar13 != 1) goto LAB_0016647d;
  }
  else {
    iVar13 = local_10c;
    if (local_10c < 2) goto LAB_001673a0;
    if (local_110 == (int *)0x0) {
      return local_199;
    }
    iVar16 = local_110[0x58] - *(int *)(param_2 + 0x46c);
    iVar13 = 0;
    if (-1 < iVar16) {
      iVar13 = iVar16;
    }
    iVar16 = local_10c;
    iVar17 = iVar13;
    if (iVar13 < local_10c) {
      local_120 = 2;
      local_11c = 1;
      local_118 = local_110;
      local_114 = piVar11;
      local_110 = piVar11;
      goto LAB_001673aa;
    }
LAB_0016647d:
    local_10c = iVar17;
    iVar13 = iVar16;
    if (local_10c != 1) {
      return local_199;
    }
  }
  iVar16 = local_11c;
  iVar17 = FUN_0010b0f4(param_1,local_120);
  uVar18 = FUN_000f5bdc(*(undefined4 *)(iVar17 + 0x10));
  iVar17 = FUN_0010b0f4(local_118,0);
  uVar19 = FUN_000f5fea(*(undefined4 *)(iVar17 + 0x10));
  if (((((uVar18 <= uVar19) && (uVar19 == (uVar18 & uVar19))) && ((char)local_118[0x48] == '\0')) &&
      (local_118[0x49] == 0)) &&
     ((iVar13 < 2 ||
      (((*(byte *)((int)local_118 + 0x16) & 2) == 0 &&
       (((cVar7 = FUN_0010a62e(param_1,param_2), cVar7 == '\0' || (local_114[0x20] == 0)) ||
        ((cVar7 = FUN_0012dfd8(local_114[0x26]), cVar7 == '\0' ||
         (((*(byte *)(local_114 + 5) & 2) != 0 ||
          (cVar7 = (**(code **)(*local_114 + 0x50))(local_114), cVar7 != '\0')))))))))))) {
    cVar7 = (**(code **)(*local_114 + 0x5c))(local_114);
    if (cVar7 == '\0') goto LAB_0016654f;
    piVar11 = (int *)FUN_0010b180(local_118,1);
    cVar7 = (**(code **)(*piVar11 + 0x5c))(piVar11);
    if (cVar7 == '\0') {
      piVar11 = (int *)FUN_0010b180(local_118,2);
      cVar7 = (**(code **)(*piVar11 + 0x5c))(piVar11);
      if (cVar7 == '\0') goto LAB_0016654f;
    }
  }
  if (local_110 == (int *)0x0) {
    return local_199;
  }
  if (local_10c != 1) {
    return local_199;
  }
  iVar13 = FUN_0010b0f4(param_1,local_11c);
  uVar18 = FUN_000f5bdc(*(undefined4 *)(iVar13 + 0x10));
  iVar13 = FUN_0010b0f4(local_110,0);
  uVar19 = FUN_000f5fea(*(undefined4 *)(iVar13 + 0x10));
  if (uVar19 < uVar18) {
    return local_199;
  }
  if (uVar19 != (uVar18 & uVar19)) {
    return local_199;
  }
  if ((char)local_110[0x48] != '\0') {
    return local_199;
  }
  if (local_110[0x49] != 0) {
    return local_199;
  }
  iVar13 = local_11c;
  piVar11 = (int *)FUN_0010b180(param_1,local_11c);
  cVar7 = (**(code **)(*piVar11 + 0x5c))(piVar11);
  if (cVar7 == '\0') {
    local_11c = local_120;
    local_118 = local_110;
    local_120 = iVar13;
  }
  else {
    piVar11 = (int *)FUN_0010b180(local_110,1);
    cVar7 = (**(code **)(*piVar11 + 0x5c))(piVar11);
    if (cVar7 != '\0') {
      return local_199;
    }
    piVar11 = (int *)FUN_0010b180(local_110,2);
    cVar7 = (**(code **)(*piVar11 + 0x5c))(piVar11);
    if (cVar7 != '\0') {
      return local_199;
    }
    local_11c = local_120;
    local_120 = iVar16;
    local_118 = local_110;
  }
LAB_0016654f:
  uVar15 = FUN_0010b180(param_1,local_11c);
  iVar13 = FUN_0010b0f4(param_1,local_11c);
  uVar2 = *(undefined4 *)(iVar13 + 0x10);
  iVar13 = FUN_0010b0f4(param_1,local_120);
  uVar23 = *(undefined4 *)(iVar13 + 0x10);
  uVar18 = *(uint *)((int)param_1 + local_11c * 0x18 + 0xa0);
  bVar8 = (byte)(uVar18 >> 1) & 1;
  bVar24 = (byte)uVar18 & 1;
  uVar1 = *(undefined1 *)((int)param_1 + 0x120);
  uVar14 = *(undefined4 *)((int)param_1 + 0x124);
  local_64 = 0;
  local_60 = 0;
  local_50 = 0;
  bVar27 = (*(byte *)((int)param_1 + 0x15) & 2) != 0;
  if (bVar27) {
    FUN_0010a980(param_1,&local_64);
  }
  iVar16 = FUN_00109e42(param_1,param_2);
  iVar13 = *(int *)((int)param_1 + 4);
  iVar17 = FUN_0010b0f4(param_1,0);
  uVar3 = *(undefined4 *)(iVar17 + 0x10);
  iVar17 = FUN_0010b0f4(local_118,2);
  uVar21 = *(undefined4 *)(iVar17 + 0x10);
  iVar17 = FUN_0010b0f4(local_118,1);
  uVar18 = *(uint *)((int)param_1 + local_120 * 0x18 + 0xa0);
  bVar25 = (byte)uVar18 & 1;
  uVar20 = FUN_000f5610(*(undefined4 *)(iVar17 + 0x10),uVar23);
  uVar21 = FUN_000f5610(uVar21,uVar23);
  uVar23 = *(undefined4 *)((int)param_1 + 0x98);
  uVar19 = *(uint *)((int)param_1 + 0x14);
  pvVar22 = (void *)FUN_0010a17a(0x14,*(undefined4 *)(param_2 + 8));
  if ((uVar19 & 2) != 0) {
    *(uint *)((int)pvVar22 + 0x14) = *(uint *)((int)pvVar22 + 0x14) | 2;
  }
  *(undefined4 *)((int)pvVar22 + 0xc) = *(undefined4 *)((int)param_1 + 0xc);
  *(undefined4 *)((int)pvVar22 + 0x94) = *(undefined4 *)((int)pvVar22 + 0x14c);
  *(undefined4 *)((int)pvVar22 + 0x98) = uVar23;
  *(undefined4 *)((int)pvVar22 + 0x9c) = uVar3;
  *(undefined1 *)((int)pvVar22 + 0x120) = uVar1;
  *(undefined4 *)((int)pvVar22 + 0x124) = uVar14;
  uVar23 = *(undefined4 *)(param_2 + 8);
  uVar14 = FUN_0010b180(local_118,1);
  cVar7 = FUN_0010bc1e(pvVar22,1,uVar14,1,bVar25,uVar23);
  uVar23 = *(undefined4 *)(param_2 + 8);
  uVar14 = FUN_0010b180(local_118,2);
  cVar9 = FUN_0010bc1e(pvVar22,2,uVar14,1,0,uVar23);
  cVar10 = FUN_0010bc1e(pvVar22,3,uVar15,bVar8,bVar24,*(undefined4 *)(param_2 + 8));
  iVar17 = FUN_0010b0f4(pvVar22,1);
  *(undefined4 *)(iVar17 + 0x10) = uVar20;
  iVar17 = FUN_0010b0f4(pvVar22,2);
  *(undefined4 *)(iVar17 + 0x10) = uVar21;
  iVar17 = FUN_0010b0f4(pvVar22,3);
  *(undefined4 *)(iVar17 + 0x10) = uVar2;
  if ((uVar18 & 2) == 0) {
    if ((uVar18 & 1) == 0) {
      FUN_00109c0e((int)pvVar22 + 0xa4,2,(uint)local_118[0x2e] >> 1 & 1);
      bVar25 = *(byte *)(local_118 + 0x2e) & 1;
    }
    else {
      FUN_00109c0e((int)pvVar22 + 0xa4,2,(uint)local_118[0x2e] >> 1 & 1);
      bVar25 = *(byte *)(local_118 + 0x2e) & 1 ^ 1;
    }
    FUN_00109c0e((int)pvVar22 + 0xa4,1,bVar25);
    FUN_00109c0e((int)pvVar22 + 0xbc,2,(uint)local_118[0x34] >> 1 & 1);
    FUN_00109c0e((int)pvVar22 + 0xbc,1,*(byte *)(local_118 + 0x34) & 1);
  }
  else {
    FUN_00109c0e((int)pvVar22 + 0xa4,2,1);
    FUN_00109c0e((int)pvVar22 + 0xa4,1,bVar25);
    FUN_00109c0e((int)pvVar22 + 0xbc,2,1);
    FUN_00109c0e((int)pvVar22 + 0xbc,1,0);
  }
  FUN_00109c0e((int)pvVar22 + 0xd4,2,bVar8);
  FUN_00109c0e((int)pvVar22 + 0xd4,1,bVar24);
  if (bVar27) {
    FUN_0010c568(pvVar22,&local_64,0,*(undefined4 *)(param_2 + 8));
  }
  *(int *)((int)pvVar22 + 0x160) = iVar16 + *(int *)(param_2 + 0x46c);
  if (cVar10 != '\0' && (cVar9 != '\0' && cVar7 != '\0')) {
    *(int *)(param_2 + 0x1b0) = *(int *)(param_2 + 0x1b0) + 1;
    iVar16 = *(int *)(param_2 + 0x46c);
    iVar17 = FUN_0010b180(local_118,1);
    if (iVar16 < *(int *)(iVar17 + 0x160)) {
      *(int *)(iVar17 + 0x160) = *(int *)(iVar17 + 0x160) + 1;
    }
    else {
      *(int *)(iVar17 + 0x160) = iVar16 + 1;
    }
    iVar16 = *(int *)(param_2 + 0x46c);
    iVar17 = FUN_0010b180(local_118,2);
    if (iVar16 < *(int *)(iVar17 + 0x160)) {
      *(int *)(iVar17 + 0x160) = *(int *)(iVar17 + 0x160) + 1;
    }
    else {
      *(int *)(iVar17 + 0x160) = iVar16 + 1;
    }
    FUN_001a7d72(param_1);
    _memcpy(param_1,pvVar22,0x164);
    FUN_000e9596(*(undefined4 *)(iVar13 + 0x158),iVar13,param_1);
    cVar7 = FUN_0010b3fe(local_118,*(undefined4 *)(param_2 + 8));
    if (cVar7 == '\0') {
      local_d8 = 1;
      do {
        piVar11 = (int *)FUN_0010b180(local_118,local_d8);
        cVar7 = (**(code **)(*piVar11 + 0x5c))(piVar11);
        if (cVar7 == '\0') {
          if (*(int *)(param_2 + 0x46c) < piVar11[0x58]) {
            piVar11[0x58] = piVar11[0x58] + 1;
          }
          else {
            piVar11[0x58] = *(int *)(param_2 + 0x46c) + 1;
          }
        }
        else {
          iVar17 = FUN_0010a1c2(piVar11,*(undefined4 *)(param_2 + 8),0);
          *(undefined4 *)(iVar17 + 0x94) = *(undefined4 *)(iVar17 + 0x14c);
          *(undefined4 *)(iVar17 + 0x98) = 0x31;
          FUN_0010ba02(pvVar22,1,iVar17,0,*(undefined4 *)(param_2 + 8));
          FUN_000e9596(*(undefined4 *)(iVar13 + 0x158),iVar13,iVar17);
          *(int *)(iVar17 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
          iVar16 = *(int *)(param_2 + 0x46c);
          iVar26 = FUN_0010b180(iVar17,1);
          if (iVar16 < *(int *)(iVar26 + 0x160)) {
            *(int *)(iVar26 + 0x160) = *(int *)(iVar26 + 0x160) + 1;
          }
          else {
            *(int *)(iVar26 + 0x160) = iVar16 + 1;
          }
          if (1 < *(int *)(iVar17 + 0x84)) {
            iVar16 = *(int *)(param_2 + 0x46c);
            iVar17 = FUN_0010b180(iVar17,2);
            if (iVar16 < *(int *)(iVar17 + 0x160)) {
              *(int *)(iVar17 + 0x160) = *(int *)(iVar17 + 0x160) + 1;
            }
            else {
              *(int *)(iVar17 + 0x160) = iVar16 + 1;
            }
          }
        }
        local_d8 = local_d8 + 1;
      } while (local_d8 != 3);
    }
  }
  return local_199;
}

/* FUN_00167924 @ 0x167924 (125 bytes) */
int FUN_00167924(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_0010b0f4(param_1,0);
  iVar2 = *(int *)(iVar2 + 0x10);
  iVar3 = FUN_0010b0f4(param_2,0);
  iVar3 = *(int *)(iVar3 + 0x10);
  cVar1 = FUN_000e1402(*(undefined4 *)(param_3 + 8),0x30);
  if (cVar1 != '\0') {
    if (iVar2 == DAT_001cc5a8) {
      if (iVar2 != iVar3) {
        return 0;
      }
    }
    else if (DAT_001cc5a8 == iVar3) {
      return 0;
    }
  }
  return 1;
}

/* FUN_001679a2 @ 0x1679a2 (1532 bytes) */
int FUN_001679a2(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  undefined4 uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  undefined4 *local_74;
  int local_6c;
  int local_68;
  int local_64;
  undefined4 local_4c [4];
  int aiStack_3c [5];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  cVar3 = FUN_001195a6(*(undefined4 *)(param_3 + 8),*param_1);
  if (((cVar3 != '\0') && (iVar5 = *param_1, (*(byte *)(iVar5 + 0x15) & 2) != 0)) &&
     (piVar4 = (int *)FUN_0010b180(iVar5,*(undefined4 *)(iVar5 + 0x84)),
     *(int *)(*(int *)(*param_1 + 0x88) + 8) == *(int *)(piVar4[0x22] + 8))) {
    iVar5 = FUN_0010b0f4(piVar4,0);
    local_14 = *(undefined4 *)(iVar5 + 0x10);
    iVar5 = FUN_0010b0f4(*param_1,0);
    local_10 = *(undefined4 *)(iVar5 + 0x10);
    iVar5 = 1;
    do {
      if ((*(char *)((int)&local_14 + iVar5 + 3) != '\x01') &&
         (*(char *)((int)&local_18 + iVar5 + 3) != '\x01')) {
        return 0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != 5);
    iVar5 = *param_1;
    if ((*(char *)(iVar5 + 0x120) == (char)piVar4[0x48]) &&
       (*(int *)(iVar5 + 0x124) == piVar4[0x49])) {
      if (param_2 == '\0') {
        cVar3 = ((int (*)())FUN_00167924)(iVar5,piVar4,param_3);
        if (cVar3 == '\0') {
          return 0;
        }
        iVar5 = *param_1;
      }
      iVar6 = 0;
      do {
        aiStack_3c[iVar6] = iVar6;
        iVar6 = iVar6 + 1;
      } while (iVar6 != 5);
      cVar3 = FUN_00118f7a(*(undefined4 *)(*(int *)(iVar5 + 0x88) + 8),*(undefined4 *)(param_3 + 8))
      ;
      if (cVar3 != '\0') {
        iVar5 = FUN_0010b180(*param_1,1);
        iVar6 = FUN_0010b180(piVar4,2);
        if (iVar5 == iVar6) {
          iVar5 = FUN_0010b180(*param_1,2);
          iVar6 = FUN_0010b180(piVar4,1);
          if (iVar5 == iVar6) {
            aiStack_3c[1] = 2;
            aiStack_3c[2] = 1;
          }
        }
      }
      local_6c = 1;
      while (iVar5 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1), local_6c <= iVar5) {
        iVar6 = FUN_0010b180(*param_1,local_6c);
        iVar5 = aiStack_3c[local_6c];
        iVar7 = FUN_0010b180(piVar4,iVar5);
        if (iVar6 != iVar7) {
          return 0;
        }
        uVar1 = *(uint *)(*param_1 + 0xa0 + local_6c * 0x18);
        if (((byte)uVar1 & 1) != ((byte)piVar4[iVar5 * 6 + 0x28] & 1)) {
          return 0;
        }
        if (((byte)(uVar1 >> 1) & 1) != ((byte)((uint)piVar4[iVar5 * 6 + 0x28] >> 1) & 1)) {
          return 0;
        }
        piVar8 = (int *)FUN_0010b180(*param_1,local_6c);
        cVar3 = (**(code **)(*piVar8 + 0x48))(piVar8);
        if (cVar3 == '\0') {
LAB_00167b89:
          local_6c = local_6c + 1;
        }
        else {
          iVar6 = FUN_0010b0f4(*param_1,local_6c);
          local_28 = *(undefined4 *)(iVar6 + 0x10);
          iVar5 = FUN_0010b0f4(piVar4,iVar5);
          local_18 = *(undefined4 *)(iVar5 + 0x10);
          piVar8 = *(int **)(*(int *)(param_3 + 8) + 0x54);
          cVar3 = (**(code **)(*piVar8 + 0x100))(piVar8,&local_28);
          if (cVar3 == '\0') goto LAB_00167b89;
          piVar8 = *(int **)(*(int *)(param_3 + 8) + 0x54);
          cVar3 = (**(code **)(*piVar8 + 0x100))(piVar8,&local_18);
          if (cVar3 == '\0') goto LAB_00167b89;
          local_1c = local_28;
          iVar5 = 1;
          do {
            if (*(char *)((int)&local_1c + iVar5 + 3) == '\x04') {
              *(undefined1 *)((int)&local_1c + iVar5 + 3) =
                   *(undefined1 *)((int)&local_20 + iVar5 + 3);
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 != 5);
          piVar8 = *(int **)(*(int *)(param_3 + 8) + 0x54);
          cVar3 = (**(code **)(*piVar8 + 0x100))(piVar8,&local_18);
          if (cVar3 == '\0') {
            return 0;
          }
          local_6c = local_6c + 1;
        }
      }
      iVar5 = FUN_0010b0f4(*param_1,0);
      local_20 = *(undefined4 *)(iVar5 + 0x10);
      puVar10 = local_4c;
      for (iVar5 = 1; iVar6 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1),
          iVar5 <= iVar6; iVar5 = iVar5 + 1) {
        iVar6 = FUN_0010b0f4(*param_1,iVar5);
        *puVar10 = *(undefined4 *)(iVar6 + 0x10);
        puVar10 = puVar10 + 1;
      }
      local_68 = 0;
      do {
        iVar5 = FUN_0010b0f4(piVar4,0);
        if (*(char *)(local_68 + 0x10 + iVar5) != '\x01') {
          iVar5 = FUN_0010b0f4(piVar4,0);
          *(undefined1 *)((int)&local_20 + local_68) = *(undefined1 *)(local_68 + 0x10 + iVar5);
          local_64 = 1;
          piVar8 = aiStack_3c;
          puVar9 = (undefined1 *)((int)local_4c + local_68);
          while( true ) {
            piVar8 = piVar8 + 1;
            iVar5 = (**(code **)(*piVar4 + 0x14))(piVar4);
            if (iVar5 < local_64) break;
            iVar5 = FUN_0010b0f4(piVar4,*piVar8);
            *puVar9 = *(undefined1 *)(local_68 + 0x10 + iVar5);
            local_64 = local_64 + 1;
            puVar9 = puVar9 + 4;
          }
        }
        local_68 = local_68 + 1;
      } while (local_68 != 4);
      iVar5 = FUN_0010b0f4(*param_1,*(undefined4 *)(*param_1 + 0x84));
      local_24 = *(undefined4 *)(iVar5 + 0x10);
      iVar5 = 0;
      do {
        iVar6 = FUN_0010b0f4(piVar4,0);
        if (*(char *)(iVar5 + 0x10 + iVar6) != '\x01') {
          *(undefined1 *)((int)&local_24 + iVar5) = 4;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 != 4);
      iVar5 = 1;
      puVar10 = local_4c;
      while( true ) {
        iVar6 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1);
        if (iVar6 < iVar5) {
          *(undefined4 *)(*param_1 + 0x9c) = local_20;
          local_74 = local_4c;
          for (iVar5 = 1; iVar6 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1),
              iVar5 <= iVar6; iVar5 = iVar5 + 1) {
            uVar2 = *local_74;
            iVar6 = FUN_0010b0f4(*param_1,iVar5);
            *(undefined4 *)(iVar6 + 0x10) = uVar2;
            local_74 = local_74 + 1;
          }
          if ((*(byte *)((int)piVar4 + 0x15) & 2) == 0) {
            iVar5 = *param_1;
            FUN_0010ba02(iVar5,*(undefined4 *)(iVar5 + 0x84),0,0,*(undefined4 *)(param_3 + 8));
            *(int *)(iVar5 + 0x84) = *(int *)(iVar5 + 0x84) + -1;
            *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) & 0xfffffdff;
            return 1;
          }
          iVar6 = FUN_0010b180(piVar4,piVar4[0x21]);
          FUN_0010c18e(*param_1,iVar6,0,*(undefined4 *)(param_3 + 8));
          uVar2 = local_24;
          iVar5 = *param_1;
          if (*(int *)(iVar5 + 0x84) == 0) {
            *(undefined4 *)(iVar5 + 0x9c) = local_24;
          }
          else {
            iVar5 = FUN_0010b0f4(iVar5,*(int *)(iVar5 + 0x84));
            *(undefined4 *)(iVar5 + 0x10) = uVar2;
          }
          if (*(int *)(iVar6 + 0x160) <= *(int *)(param_3 + 0x46c)) {
            *(int *)(iVar6 + 0x160) = *(int *)(param_3 + 0x46c) + 1;
            return 1;
          }
          *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
          return 1;
        }
        piVar8 = *(int **)(*(int *)(param_3 + 8) + 0x54);
        cVar3 = (**(code **)(*piVar8 + 0x100))(piVar8,puVar10);
        if (cVar3 == '\0') break;
        iVar5 = iVar5 + 1;
        puVar10 = puVar10 + 1;
      }
    }
  }
  return 0;
}

/* FUN_00167f9e @ 0x167f9e (114 bytes) */
int FUN_00167f9e(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  iVar1 = param_2;
  if ((*(byte *)(param_1 + 0x15) & 2) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0010b180(param_1,*(undefined4 *)(param_1 + 0x84));
  }
  cVar2 = ((int (*)())FUN_001679a2)(&param_1,0,iVar1);
  if (cVar2 == '\0') {
    return 0;
  }
  *(int *)(iVar1 + 0x1fc) = *(int *)(iVar1 + 0x1fc) + 1;
  FUN_0010b3fe(uVar3,*(undefined4 *)(iVar1 + 8));
  return 1;
}

/* FUN_00168010 @ 0x168010 (4855 bytes) */
int FUN_00168010(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  bool bVar5;
  char cVar6;
  undefined1 uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int *piVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  uint uVar17;
  int *piVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  int local_244;
  int local_240;
  int local_228;
  int local_224;
  undefined1 local_21d;
  int local_21c;
  int *local_218;
  int *local_214;
  int local_1e0;
  byte local_1bc;
  byte local_1ac;
  undefined4 local_194;
  undefined4 local_190;
  uint local_44;
  uint local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  int local_24;
  int local_20 [4];
  
  iVar2 = *(int *)(param_2 + 8);
  local_24 = 0;
  local_24 = FUN_001505ca(param_1,0,param_3,param_2,&local_28,&local_24);
  if (local_24 < *(int *)(iVar2 + 0x3e0)) {
    return param_1;
  }
  local_194 = FUN_0010b180(param_1,3);
  local_1ac = (byte)param_1[0x3a];
  local_1bc = (byte)((uint)param_1[0x3a] >> 1);
  iVar8 = FUN_0010b0f4(param_1,3);
  local_190 = *(undefined4 *)(iVar8 + 0x10);
  if (param_3 == 0x14) {
    local_21d = (undefined1)param_1[0x48];
    if ((*(byte *)((int)param_1 + 0x15) & 2) == 0) {
      local_21c = 0;
    }
    else {
      local_21c = FUN_0010b180(param_1,param_1[0x21]);
    }
    local_224 = param_1[0x49];
    uVar15 = FUN_0010b180(param_1,1);
    uVar3 = param_1[0x2e];
    iVar8 = FUN_0010b0f4(param_1,1);
    uVar13 = *(undefined4 *)(iVar8 + 0x10);
    uVar16 = FUN_0010b180(param_1,2);
    uVar17 = param_1[0x34];
    iVar8 = FUN_0010b0f4(param_1,2);
    uVar4 = *(undefined4 *)(iVar8 + 0x10);
    local_194 = FUN_0010b180(param_1,3);
    local_1ac = (byte)param_1[0x3a];
    local_1bc = (byte)((uint)param_1[0x3a] >> 1);
    iVar8 = FUN_0010b0f4(param_1,3);
    local_190 = *(undefined4 *)(iVar8 + 0x10);
    iVar8 = param_1[1];
    iVar21 = FUN_0010b0f4(param_1,0);
    iVar21 = *(int *)(iVar21 + 0x10);
    uVar19 = param_1[5];
    local_228 = param_1[0x54];
    iVar10 = param_1[0x26];
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    FUN_00109d1c(param_1,&local_34,0xffffffff);
    iVar11 = param_1[0x25];
    uVar20 = param_1[5];
    FUN_001a7d72(param_1);
    FUN_0010d8fc(param_1,0x13,*(undefined4 *)(param_2 + 8));
    if ((uVar19 & 0x4000) == 0) {
      uVar19 = param_1[5] & 0xffffbfff;
      param_1[5] = uVar19;
    }
    else {
      uVar19 = param_1[5] | 0x4000;
      param_1[5] = uVar19;
    }
    param_1[0x25] = iVar11;
    param_1[0x26] = iVar10;
    if ((uVar20 & 2) != 0) {
      param_1[5] = uVar19 | 2;
    }
    param_1[0x27] = iVar21;
    FUN_0010ba02(param_1,1,uVar15,0,*(undefined4 *)(param_2 + 8));
    FUN_00109c0e(param_1 + 0x29,1,(byte)uVar3 & 1);
    FUN_00109c0e(param_1 + 0x29,2,(byte)(uVar3 >> 1) & 1);
    iVar21 = FUN_0010b0f4(param_1,1);
    *(undefined4 *)(iVar21 + 0x10) = uVar13;
    FUN_0010ba02(param_1,2,uVar16,0,*(undefined4 *)(param_2 + 8));
    FUN_00109c0e(param_1 + 0x2f,1,(byte)uVar17 & 1);
    FUN_00109c0e(param_1 + 0x2f,2,(byte)(uVar17 >> 1) & 1);
    iVar21 = FUN_0010b0f4(param_1,2);
    *(undefined4 *)(iVar21 + 0x10) = uVar4;
    FUN_00109d48(param_1,&local_34);
    FUN_000e9596(*(undefined4 *)(iVar8 + 0x158),iVar8,param_1);
    bVar5 = true;
    param_3 = 0x13;
  }
  else {
    bVar5 = false;
    local_228 = 0;
    local_224 = 0;
    local_21d = 0;
    local_21c = 0;
  }
  local_1ac = local_1ac & 1;
  local_1bc = local_1bc & 1;
  iVar8 = FUN_0010b0f4(param_1,0);
  iVar8 = *(int *)(iVar8 + 0x10);
  local_20[0] = iVar8;
  iVar21 = 0;
  do {
    if (*(char *)((int)local_20 + iVar21) == '\0') {
      local_240 = *(int *)(PTR_DAT_0021345d + iVar21 * 4);
      local_244 = *(int *)(PTR_DAT_00213485 + iVar21 * 4);
      break;
    }
    iVar21 = iVar21 + 1;
  } while (iVar21 != 4);
  local_218 = param_1;
  do {
    uVar3 = local_218[5];
    local_218[5] = uVar3 | 0x100000;
    iVar21 = ((uVar3 & 0x4000) >> 0xe) + 1;
    piVar9 = (int *)FUN_0010b180(local_218,iVar21);
    if (param_3 != *(int *)(piVar9[0x22] + 8)) break;
    iVar10 = FUN_0010b0f4(local_218,iVar21);
    iVar10 = *(int *)(iVar10 + 0x10);
    iVar11 = FUN_0010b0f4(piVar9,1);
    iVar11 = *(int *)(iVar11 + 0x10);
    iVar12 = FUN_000f5610(iVar11,iVar10);
    if (iVar11 != iVar12) {
      iVar11 = FUN_0010b0f4(piVar9,1);
      *(int *)(iVar11 + 0x10) = iVar12;
    }
    iVar11 = FUN_0010b0f4(piVar9,2);
    iVar11 = *(int *)(iVar11 + 0x10);
    iVar12 = FUN_000f5610(iVar11,iVar10);
    if (iVar11 != iVar12) {
      iVar11 = FUN_0010b0f4(piVar9,2);
      *(int *)(iVar11 + 0x10) = iVar12;
    }
    iVar11 = FUN_0010b0f4(piVar9,0);
    if (*(int *)(iVar11 + 0x10) != iVar8) {
      piVar9[0x27] = local_20[0];
    }
    uVar13 = FUN_000f5fea(local_20[0]);
    iVar11 = FUN_000f5b96(DAT_001cc5a0,uVar13);
    if (iVar10 != iVar11) {
      if (iVar21 == 0) {
        local_218[0x27] = iVar11;
      }
      else {
        iVar21 = FUN_0010b0f4(local_218,iVar21);
        *(int *)(iVar21 + 0x10) = iVar11;
      }
    }
    local_218 = piVar9;
  } while (piVar9 != local_28);
  piVar9 = local_28;
  local_218[5] = local_218[5] | 0x100000;
  local_38 = *(undefined4 *)(*(int *)(param_2 + 8) + 0xb8);
  local_40 = 0;
  local_44 = 2;
  local_3c = FUN_001a7bca(local_38,8);
  *(int *)(param_2 + 0x1c8) = *(int *)(param_2 + 0x1c8) + 1;
  if (param_1 != piVar9) {
    iVar8 = 0;
    do {
      while (iVar21 = piVar9[0x53], local_44 <= local_40) {
        piVar14 = (int *)FUN_001a7f7c(&local_44,local_40);
        *piVar14 = iVar21;
        piVar9[0x53] = iVar8;
        iVar8 = iVar8 + 1;
        piVar9 = (int *)piVar9[2];
        if (param_1 == piVar9) goto LAB_001683b2;
      }
      iVar10 = local_40 * 4;
      *(undefined4 *)(iVar10 + local_3c) = 0;
      local_40 = local_40 + 1;
      *(int *)(iVar10 + local_3c) = iVar21;
      piVar9[0x53] = iVar8;
      iVar8 = iVar8 + 1;
      piVar9 = (int *)piVar9[2];
    } while (param_1 != piVar9);
  }
LAB_001683b2:
  piVar9 = local_28;
  if (2 < local_24) {
    local_214 = param_1;
    piVar14 = param_1;
    do {
      piVar9 = (int *)FUN_0010b180(piVar14,((uint)piVar14[5] >> 0xe & 1) + 1);
      uVar17 = (uint)piVar14[5] >> 0xe & 1;
      uVar3 = piVar14[uVar17 * 6 + 0x2e];
      iVar8 = FUN_0010b0f4(piVar14,uVar17 + 1);
      uVar13 = *(undefined4 *)(iVar8 + 0x10);
      piVar18 = (int *)FUN_0010b180(piVar9,((uint)piVar9[5] >> 0xe & 1) + 1);
      uVar19 = (uint)piVar9[5] >> 0xe & 1;
      uVar17 = piVar9[uVar19 * 6 + 0x2e];
      iVar8 = FUN_0010b0f4(piVar9,uVar19 + 1);
      uVar4 = *(undefined4 *)(iVar8 + 0x10);
      iVar8 = FUN_0010b180(local_214,((uint)local_214[5] >> 0xe & 1 ^ 1) + 1);
      uVar20 = (uint)local_214[5] >> 0xe & 1 ^ 1;
      uVar19 = local_214[uVar20 * 6 + 0x2e];
      iVar21 = FUN_0010b0f4(local_214,uVar20 + 1);
      uVar15 = *(undefined4 *)(iVar21 + 0x10);
      FUN_0010ba02(piVar14,((uint)piVar14[5] >> 0xe & 1) + 1,piVar18,0,iVar2);
      FUN_00109c0e(piVar14 + ((uint)piVar14[5] >> 0xe & 1) * 6 + 0x29,1,(byte)uVar17 & 1);
      FUN_00109c0e(piVar14 + ((uint)piVar14[5] >> 0xe & 1) * 6 + 0x29,2,(byte)(uVar17 >> 1) & 1);
      iVar21 = FUN_0010b0f4(piVar14,((uint)piVar14[5] >> 0xe & 1) + 1);
      *(undefined4 *)(iVar21 + 0x10) = uVar4;
      FUN_0010ba02(local_214,((uint)local_214[5] >> 0xe & 1 ^ 1) + 1,piVar9,0,iVar2);
      FUN_00109c0e(local_214 + ((uint)local_214[5] >> 0xe & 1 ^ 1) * 6 + 0x29,1,(byte)uVar3 & 1);
      FUN_00109c0e(local_214 + ((uint)local_214[5] >> 0xe & 1 ^ 1) * 6 + 0x29,2,
                   (byte)(uVar3 >> 1) & 1);
      iVar21 = FUN_0010b0f4(local_214,((uint)local_214[5] >> 0xe & 1 ^ 1) + 1);
      *(undefined4 *)(iVar21 + 0x10) = uVar13;
      FUN_0010ba02(piVar9,((uint)piVar9[5] >> 0xe & 1) + 1,iVar8,0,iVar2);
      FUN_00109c0e(piVar9 + ((uint)piVar9[5] >> 0xe & 1) * 6 + 0x29,1,(byte)uVar19 & 1);
      FUN_00109c0e(piVar9 + ((uint)piVar9[5] >> 0xe & 1) * 6 + 0x29,2,(byte)(uVar19 >> 1) & 1);
      iVar21 = FUN_0010b0f4(piVar9,((uint)piVar9[5] >> 0xe & 1) + 1);
      *(undefined4 *)(iVar21 + 0x10) = uVar15;
      if (piVar9[0x53] < *(int *)(iVar8 + 0x14c)) {
        FUN_001a7d72(piVar9);
        FUN_000e956e(local_214[0x56],local_214,piVar9);
      }
      local_24 = local_24 + -2;
      piVar14 = piVar18;
      local_214 = piVar9;
      piVar9 = local_28;
    } while (2 < local_24);
  }
  for (; param_1 != piVar9; piVar9 = (int *)piVar9[2]) {
    uVar3 = piVar9[0x53];
    if (uVar3 < local_44) {
      if (local_40 <= uVar3) {
        _memset((void *)(local_3c + local_40 * 4),0,(uVar3 - local_40) * 4 + 4);
        local_40 = uVar3 + 1;
      }
      piVar9[0x53] = *(int *)(local_3c + uVar3 * 4);
      bVar1 = *(byte *)((int)piVar9 + 0x16);
    }
    else {
      piVar14 = (int *)FUN_001a7f7c(&local_44,uVar3);
      piVar9[0x53] = *piVar14;
      bVar1 = *(byte *)((int)piVar9 + 0x16);
    }
    if ((bVar1 & 0x10) != 0) {
      iVar8 = FUN_0010b0f4(piVar9,1);
      cVar6 = FUN_000f5672(*(undefined4 *)(iVar8 + 0x10));
      if (cVar6 == '\0') {
        iVar8 = FUN_0010b180(piVar9,1);
        if ((*(byte *)(iVar8 + 0x16) & 0x10) != 0) {
          uVar13 = FUN_0010b180(piVar9,1);
          iVar8 = FUN_0010b0f4(uVar13,0);
          cVar6 = FUN_000f5f28(*(undefined4 *)(iVar8 + 0x10));
          if (cVar6 != '\0') goto LAB_0016858f;
        }
      }
      else {
LAB_0016858f:
        iVar8 = FUN_0010b0f4(piVar9,2);
        cVar6 = FUN_000f5672(*(undefined4 *)(iVar8 + 0x10));
        if (cVar6 == '\0') {
          iVar8 = FUN_0010b180(piVar9,2);
          if ((*(byte *)(iVar8 + 0x16) & 0x10) != 0) {
            uVar13 = FUN_0010b180(piVar9,2);
            iVar8 = FUN_0010b0f4(uVar13,0);
            cVar6 = FUN_000f5f28(*(undefined4 *)(iVar8 + 0x10));
            if (cVar6 != '\0') goto LAB_001685fb;
          }
        }
        else {
LAB_001685fb:
          piVar9[0x27] = local_240;
          iVar8 = ((uint)piVar9[5] >> 0xe & 1) + 1;
          iVar21 = FUN_0010b0f4(piVar9,iVar8);
          if (*(int *)(iVar21 + 0x10) == DAT_001cc5a0) {
            if (iVar8 == 0) {
              piVar9[0x27] = local_244;
            }
            else {
              iVar8 = FUN_0010b0f4(piVar9,iVar8);
              *(int *)(iVar8 + 0x10) = local_244;
            }
          }
        }
      }
      for (local_1e0 = 1; iVar8 = (**(code **)(*piVar9 + 0x14))(piVar9), local_1e0 <= iVar8;
          local_1e0 = local_1e0 + 1) {
        iVar8 = FUN_0010b180(piVar9,local_1e0);
        if ((*(byte *)(iVar8 + 0x16) & 0x10) != 0) {
          iVar8 = FUN_0010b0f4(iVar8,0);
          uVar13 = *(undefined4 *)(iVar8 + 0x10);
          cVar6 = FUN_000f5f28(uVar13);
          if (cVar6 != '\0') {
            uVar7 = FUN_000f5ede(uVar13);
            local_34 = DAT_001cc5a4;
            iVar8 = 0;
            do {
              iVar21 = FUN_0010b0f4(piVar9,0);
              if (*(char *)(iVar8 + 0x10 + iVar21) != '\x01') {
                *(undefined1 *)((int)&local_34 + iVar8) = uVar7;
              }
              iVar21 = local_34;
              iVar8 = iVar8 + 1;
            } while (iVar8 != 4);
            if (local_1e0 == 0) {
              piVar9[0x27] = local_34;
            }
            else {
              iVar8 = FUN_0010b0f4(piVar9,local_1e0);
              *(int *)(iVar8 + 0x10) = iVar21;
            }
          }
        }
      }
    }
  }
  iVar8 = 1;
  do {
    while( true ) {
      iVar21 = (**(code **)(*param_1 + 0x14))(param_1);
      if (iVar21 < iVar8) {
        for (; param_1 != local_28; local_28 = (int *)local_28[2]) {
          if ((local_28[5] & 0x100000U) != 0) {
            local_28[5] = local_28[5] & 0xffefffff;
          }
        }
        param_1[5] = param_1[5] & 0xffefffff;
        if (bVar5) {
          uVar15 = FUN_0010b180(param_1,1);
          uVar3 = param_1[0x2e];
          iVar8 = FUN_0010b0f4(param_1,1);
          uVar13 = *(undefined4 *)(iVar8 + 0x10);
          uVar16 = FUN_0010b180(param_1,2);
          uVar17 = param_1[0x34];
          iVar8 = FUN_0010b0f4(param_1,2);
          uVar4 = *(undefined4 *)(iVar8 + 0x10);
          iVar8 = param_1[1];
          iVar21 = FUN_0010b0f4(param_1,0);
          iVar21 = *(int *)(iVar21 + 0x10);
          iVar10 = param_1[0x26];
          iVar11 = param_1[0x25];
          uVar19 = param_1[5];
          local_34 = 0;
          local_30 = 0;
          local_2c = 0;
          FUN_00109d1c(param_1,&local_34,0xffffffff);
          FUN_001a7d72(param_1);
          FUN_0010da48(param_1,0x14,*(undefined4 *)(param_2 + 8));
          FUN_00109d48(param_1,&local_34);
          *(undefined1 *)(param_1 + 0x48) = 0;
          param_1[0x49] = 0;
          param_1[0x25] = iVar11;
          param_1[0x26] = iVar10;
          if ((uVar19 & 2) != 0) {
            param_1[5] = param_1[5] | 2;
          }
          param_1[0x27] = iVar21;
          param_1[0x54] = local_228;
          FUN_0010ba02(param_1,1,uVar15,0,*(undefined4 *)(param_2 + 8));
          FUN_00109c0e(param_1 + 0x29,1,(byte)uVar3 & 1);
          FUN_00109c0e(param_1 + 0x29,2,(byte)(uVar3 >> 1) & 1);
          iVar21 = FUN_0010b0f4(param_1,1);
          *(undefined4 *)(iVar21 + 0x10) = uVar13;
          FUN_0010ba02(param_1,2,uVar16,0,*(undefined4 *)(param_2 + 8));
          FUN_00109c0e(param_1 + 0x2f,1,(byte)uVar17 & 1);
          FUN_00109c0e(param_1 + 0x2f,2,(byte)(uVar17 >> 1) & 1);
          iVar21 = FUN_0010b0f4(param_1,2);
          *(undefined4 *)(iVar21 + 0x10) = uVar4;
          FUN_0010ba02(param_1,3,local_194,0,*(undefined4 *)(param_2 + 8));
          FUN_00109c0e(param_1 + 0x35,1,local_1ac);
          FUN_00109c0e(param_1 + 0x35,2,local_1bc);
          iVar21 = FUN_0010b0f4(param_1,3);
          *(undefined4 *)(iVar21 + 0x10) = local_190;
          *(undefined1 *)(param_1 + 0x48) = local_21d;
          param_1[0x49] = local_224;
          if (local_21c != 0) {
            FUN_0010c18e(param_1,local_21c,0,iVar2);
          }
          FUN_000e9596(*(undefined4 *)(iVar8 + 0x158),iVar8,param_1);
        }
        FUN_001a7aba(local_38,local_3c);
        return param_1;
      }
      iVar21 = FUN_0010b180(param_1,iVar8);
      if ((*(byte *)(iVar21 + 0x16) & 0x10) != 0) break;
LAB_00168674:
      iVar8 = iVar8 + 1;
    }
    iVar21 = FUN_0010b0f4(iVar21,0);
    uVar13 = *(undefined4 *)(iVar21 + 0x10);
    cVar6 = FUN_000f5f28(uVar13);
    if (cVar6 == '\0') goto LAB_00168674;
    uVar7 = FUN_000f5ede(uVar13);
    local_34 = DAT_001cc5a4;
    iVar21 = 0;
    do {
      iVar10 = FUN_0010b0f4(param_1,0);
      if (*(char *)(iVar21 + 0x10 + iVar10) != '\x01') {
        *(undefined1 *)((int)&local_34 + iVar21) = uVar7;
      }
      iVar10 = local_34;
      iVar21 = iVar21 + 1;
    } while (iVar21 != 4);
    if (iVar8 == 0) {
      param_1[0x27] = local_34;
      iVar8 = 1;
    }
    else {
      iVar21 = FUN_0010b0f4(param_1,iVar8);
      *(int *)(iVar21 + 0x10) = iVar10;
      iVar8 = iVar8 + 1;
    }
  } while( true );
}

/* FUN_0016932c @ 0x16932c (1315 bytes) */
int FUN_0016932c(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  byte bVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int iVar17;
  uint uVar18;
  undefined4 local_64;
  int *local_54;
  uint local_48;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  uVar18 = ~param_2 & 3;
  iVar11 = FUN_0010b180(param_1,param_2);
  local_54 = (int *)FUN_0010b180(iVar11,1);
  piVar12 = (int *)FUN_0010b180(iVar11,2);
  piVar13 = (int *)FUN_0010b180(param_1,uVar18);
  iVar14 = FUN_0010b0f4(param_1,uVar18);
  uVar1 = *(undefined4 *)(iVar14 + 0x10);
  iVar14 = FUN_0010b0f4(iVar11,1);
  uVar15 = *(undefined4 *)(iVar14 + 0x10);
  iVar14 = FUN_0010b0f4(iVar11,2);
  local_20[0] = *(undefined4 *)(iVar14 + 0x10);
  cVar4 = FUN_000f5672(uVar1);
  cVar5 = FUN_000f5672(uVar15);
  cVar6 = FUN_000f5672(local_20[0]);
  if ((cVar5 == '\0') && (cVar6 == '\0')) {
    return;
  }
  if (cVar4 == '\0') {
    return;
  }
  cVar4 = FUN_000f6a7e(param_1,param_2,iVar11,param_3);
  if (cVar4 == '\0') {
    return;
  }
  if (cVar5 == '\0') {
    if (cVar6 != '\0') {
      local_48 = 1;
      local_20[0] = uVar15;
      goto LAB_00169476;
    }
  }
  else if (cVar6 != '\0') {
    cVar4 = (**(code **)(*piVar12 + 0x48))(piVar12);
    if ((cVar4 != '\0') || (cVar4 = (**(code **)(*piVar12 + 0x4c))(piVar12), cVar4 != '\0')) {
      local_48 = 1;
      local_20[0] = uVar15;
      goto LAB_00169476;
    }
    cVar4 = (**(code **)(*local_54 + 0x48))(local_54);
    if ((cVar4 == '\0') && (cVar4 = (**(code **)(*local_54 + 0x4c))(local_54), cVar4 == '\0')) {
      return;
    }
  }
  local_48 = 2;
  local_54 = piVar12;
LAB_00169476:
  cVar4 = (**(code **)(*piVar13 + 0x48))(piVar13);
  if ((cVar4 == '\0') && (cVar4 = (**(code **)(*piVar13 + 0x4c))(piVar13), cVar4 == '\0')) {
    return;
  }
  uVar15 = FUN_0010a1c2(iVar11,*(undefined4 *)(param_3 + 8),0);
  uVar16 = FUN_0010a1c2(param_1,*(undefined4 *)(param_3 + 8),0);
  iVar14 = uVar18 * 0x18 + 0x80;
  bVar7 = *(byte *)(param_1 + 0x20 + iVar14) & 1;
  bVar8 = *(byte *)(iVar11 + 0xa0 + local_48 * 0x18) & 1;
  cVar4 = FUN_0010bc1e(param_1,uVar18,local_54,1,bVar8,*(undefined4 *)(param_3 + 8));
  FUN_00109c0e(param_1 + 0xc + iVar14,1,bVar8);
  iVar14 = FUN_0010b0f4(param_1,param_2);
  local_24 = *(undefined4 *)(iVar14 + 0x10);
  local_28 = local_20[0];
  iVar14 = 0;
  do {
    iVar17 = FUN_0010b0f4(param_1,0);
    if (*(char *)(iVar14 + 0x10 + iVar17) != '\x01') {
      *(undefined1 *)((int)local_20 + iVar14) =
           *(undefined1 *)((int)&local_28 + (uint)*(byte *)((int)local_20 + iVar14 + -4));
    }
    iVar14 = iVar14 + 1;
  } while (iVar14 != 4);
  local_2c = DAT_001cc5b0;
  iVar14 = 0;
  do {
    iVar17 = FUN_0010b0f4(param_1,0);
    if (*(char *)(iVar14 + 0x10 + iVar17) == '\x01') {
      *(undefined1 *)((int)&local_2c + iVar14) = 4;
      *(undefined1 *)((int)local_20 + iVar14) = 4;
    }
    uVar2 = local_20[0];
    iVar14 = iVar14 + 1;
  } while (iVar14 != 4);
  iVar14 = FUN_0010b0f4(param_1,uVar18);
  uVar3 = local_2c;
  *(undefined4 *)(iVar14 + 0x10) = uVar2;
  iVar14 = FUN_0010b0f4(param_1,param_2);
  *(undefined4 *)(iVar14 + 0x10) = uVar3;
  *(undefined4 *)(iVar11 + 0x9c) = DAT_001cc5ac;
  cVar5 = FUN_0010bc1e(iVar11,local_48,piVar13,1,bVar7,*(undefined4 *)(param_3 + 8));
  FUN_00109c0e(iVar11 + 0x8c + local_48 * 0x18,1,bVar7);
  iVar14 = FUN_0010b0f4(iVar11,~local_48 & 3);
  uVar2 = *(undefined4 *)(iVar14 + 0x10);
  uVar9 = FUN_000f56ae(uVar1);
  uVar10 = FUN_000f56ae(uVar2);
  (*(unsigned int *)((unsigned char *)&(local_64) + 1)) = (undefined3)((uint)DAT_001cc5a4 >> 8);
  local_64 = CONCAT31((*(unsigned int *)((unsigned char *)&(local_64) + 1)),uVar9);
  iVar14 = FUN_0010b0f4(iVar11,local_48);
  *(undefined4 *)(iVar14 + 0x10) = local_64;
  iVar14 = FUN_0010b0f4(iVar11,~local_48 & 3);
  *(uint *)(iVar14 + 0x10) = CONCAT31((*(unsigned int *)((unsigned char *)&(local_64) + 1)),uVar10);
  if (cVar5 != '\0' && cVar4 != '\0') {
    FUN_001a7d72(iVar11);
    FUN_000e956e(*(undefined4 *)(param_1 + 0x158),param_1,iVar11);
    *(int *)(param_3 + 0x1c0) = *(int *)(param_3 + 0x1c0) + 1;
    return;
  }
  iVar14 = *(int *)(iVar11 + 4);
  FUN_001a7d72(iVar11);
  FUN_00109d86(iVar11,uVar15);
  FUN_000e9596(*(undefined4 *)(iVar14 + 0x158),iVar14,iVar11);
  FUN_001a7d72(param_1);
  FUN_00109d86(param_1,uVar16);
  FUN_000e9596();
  return;
}

/* FUN_00169850 @ 0x169850 (500 bytes) */
int FUN_00169850(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int *param_2;
  int param_3;
  undefined4 param_4;
  uint param_5;
  int param_6;
{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  do {
    while (cVar1 = (**(code **)(*param_2 + 100))(param_2), cVar1 == '\0') {
LAB_0016986b:
      cVar1 = (**(code **)(*param_2 + 0x24))(param_2);
      if ((((cVar1 == '\0') || (cVar1 = FUN_0010a62e(param_2,param_6), cVar1 == '\0')) ||
          ((char)param_2[0x48] != '\0')) ||
         (piVar5 = *(int **)(*(int *)(param_6 + 8) + 0x54),
         cVar1 = (**(code **)(*piVar5 + 0xfc))(piVar5,param_3 + param_2[0x49],param_2),
         cVar1 == '\0')) {
        return 0;
      }
      do {
        if ((*(byte *)((int)param_2 + 0x15) & 2) == 0) {
          return 1;
        }
        param_2 = (int *)FUN_0010b180(param_2,param_2[0x21]);
        iVar2 = FUN_0010b0f4(param_2,0);
        uVar3 = FUN_000f5fea(*(undefined4 *)(iVar2 + 0x10));
      } while ((param_5 & uVar3) == 0);
    }
    for (iVar2 = 1; iVar4 = (**(code **)(*param_2 + 0x14))(param_2), iVar2 <= iVar4;
        iVar2 = iVar2 + 1) {
      if ((((param_2[iVar2 * 6 + 0x28] & 1U) != 0) || ((param_2[iVar2 * 6 + 0x28] & 2U) != 0)) ||
         (cVar1 = FUN_000f5a1e(param_2,iVar2), cVar1 == '\0')) goto LAB_0016986b;
    }
    if (((char)param_2[0x48] != '\0') || (param_2[0x49] != 0)) goto LAB_0016986b;
    if ((param_2[0x20] != 0) &&
       (((cVar1 = FUN_0012dfd8(param_2[0x26]), cVar1 != '\0' && ((*(byte *)(param_2 + 5) & 2) == 0))
        && (cVar1 = (**(code **)(*param_2 + 0x50))(param_2), cVar1 == '\0')))) {
      iVar2 = 4;
      piVar5 = param_2;
      do {
        if ((byte)((char)piVar5[0x27] - 2U) < 2) goto LAB_0016986b;
        piVar5 = (int *)((int)piVar5 + 1);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_0010b0f4(param_2,0);
    iVar2 = FUN_0010b7c8(param_2,0);
    if (((iVar2 != 0) || ((param_2[5] & 2U) != 0)) ||
       (((param_2[5] & 0x200U) != 0 || (cVar1 = FUN_0010a62e(param_2,param_6), cVar1 == '\0'))))
    goto LAB_0016986b;
    param_2 = (int *)FUN_0010b180(param_2,1);
  } while( true );
}

/* FUN_00169a44 @ 0x169a44 (2410 bytes) */
int FUN_00169a44(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  char cVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined4 uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int *piVar19;
  int local_d4;
  char local_cd;
  int *local_cc;
  byte local_c5;
  undefined4 local_50;
  int local_4c;
  undefined4 local_3c;
  undefined1 local_38 [4];
  float local_34;
  int local_20 [4];
  
  uVar2 = *(undefined4 *)(param_4 + 8);
  local_d4 = *(int *)(*(int *)(param_3 + 0x88) + 8);
  if (param_1 == 0) {
    iVar12 = 0;
    if (local_d4 == 0x14) goto LAB_00169cae;
LAB_00169a8a:
    if (local_d4 == 0x12) {
      if (iVar12 == 0x12) {
        local_cd = '\0';
        goto LAB_00169bba;
      }
      goto LAB_00169b5d;
    }
    if (local_d4 == 0x13) {
      if ((iVar12 == 0x14) || (iVar12 == 0x13)) {
        local_d4 = 0x13;
        local_cd = '\0';
        goto LAB_00169aa9;
      }
      goto LAB_00169b5d;
    }
  }
  else {
    iVar12 = *(int *)(*(int *)(param_1 + 0x88) + 8);
    if (local_d4 != 0x14) goto LAB_00169a8a;
LAB_00169cae:
    iVar12 = FUN_0010b0f4(param_3,0);
    cVar11 = FUN_000f7e7e(param_3,2,*(undefined4 *)(iVar12 + 0x10),local_38);
    if (cVar11 != '\0') {
      local_cc = (int *)FUN_0010b180(param_3,1);
      iVar12 = FUN_0010b0f4(param_3,0);
      uVar3 = *(undefined4 *)(iVar12 + 0x10);
      iVar12 = FUN_0010b0f4(param_3,param_2);
      uVar13 = FUN_000f5bdc(*(undefined4 *)(iVar12 + 0x10));
      if ((FLOAT_001c5b9c <= local_34) || (NAN(local_34) || NAN(FLOAT_001c5b9c))) {
        local_c5 = 0;
      }
      else {
        local_34 = (float)((uint)local_34 ^ _DAT_001cc6e0);
        local_c5 = 1;
      }
      cVar11 = ((undefined4 (*)())FUN_0010fdec)(local_34,local_20);
      if (((cVar11 != '\0') && (local_20[0] != 0)) &&
         (cVar11 = ((int (*)())FUN_00169850)(param_3,local_cc,local_20[0],uVar3,uVar13,param_4), cVar11 != '\0'))
      {
        local_d4 = 0x14;
        local_cd = '\0';
        do {
          piVar19 = local_cc;
          if (*(int *)(local_cc[0x22] + 8) == 0x13) {
            iVar12 = 1;
            do {
              piVar19 = (int *)FUN_0010b180(local_cc,iVar12);
              cVar11 = (**(code **)(*piVar19 + 0x24))(piVar19);
              if (((cVar11 != '\0') && (cVar11 = FUN_0010a62e(piVar19,param_4), cVar11 != '\0')) &&
                 (((char)piVar19[0x48] == '\0' &&
                  (((*(byte *)((int)piVar19 + 0x15) & 2) == 0 &&
                   (piVar4 = *(int **)(*(int *)(param_4 + 8) + 0x54),
                   cVar11 = (**(code **)(*piVar4 + 0xfc))
                                      (piVar4,piVar19[0x49] + local_20[0],param_3), cVar11 != '\0'))
                  )))) break;
              iVar12 = iVar12 + 1;
              piVar19 = local_cc;
            } while (iVar12 != 3);
          }
          iVar12 = piVar19[0x49] + local_20[0];
          piVar4 = *(int **)(*(int *)(param_4 + 8) + 0x54);
          cVar11 = (**(code **)(*piVar4 + 0xfc))(piVar4,iVar12,param_3);
          if (cVar11 != '\0') {
            *(int *)(param_4 + 0x1c4) = *(int *)(param_4 + 0x1c4) + 1;
            piVar19[0x49] = iVar12;
            if (local_cd == '\0') {
              uVar15 = FUN_0010b180(param_3,3);
              iVar12 = FUN_0010b0f4(param_3,1);
              uVar5 = *(undefined4 *)(iVar12 + 0x10);
              iVar12 = FUN_0010b0f4(param_3,3);
              uVar6 = *(undefined4 *)(iVar12 + 0x10);
              uVar14 = *(uint *)(param_3 + 0xb8);
              uVar7 = *(uint *)(param_3 + 0xe8);
              uVar1 = *(undefined1 *)(param_3 + 0x120);
              uVar8 = *(undefined4 *)(param_3 + 0x124);
              local_50 = 0;
              local_4c = 0;
              local_3c = 0;
              uVar16 = *(uint *)(param_3 + 0x14);
              if ((uVar16 & 0x200) != 0) {
                FUN_0010a980(param_3,&local_50);
                uVar16 = *(uint *)(param_3 + 0x14);
              }
              uVar9 = *(undefined4 *)(param_3 + 0x98);
              uVar10 = *(undefined4 *)(param_3 + 0x94);
              iVar17 = FUN_00109e42(param_3,param_4);
              iVar12 = *(int *)(param_3 + 4);
              FUN_001a7d72(param_3);
              if (0 < *(int *)(param_3 + 0x84)) {
                iVar18 = 1;
                do {
                  FUN_0010ba02(param_3,iVar18,0,0,uVar2);
                  iVar18 = iVar18 + 1;
                } while (iVar18 <= *(int *)(param_3 + 0x84));
              }
              FUN_0010d8fc(param_3,0x12,*(undefined4 *)(param_4 + 8));
              *(undefined4 *)(param_3 + 0x94) = uVar10;
              *(undefined4 *)(param_3 + 0x98) = uVar9;
              if ((uVar16 & 2) != 0) {
                *(uint *)(param_3 + 0x14) = *(uint *)(param_3 + 0x14) | 2;
              }
              *(undefined4 *)(param_3 + 0x9c) = uVar3;
              FUN_0010ba02(param_3,1,local_cc,0,uVar2);
              FUN_0010ba02(param_3,2,uVar15,0,uVar2);
              iVar18 = FUN_0010b0f4(param_3,1);
              *(undefined4 *)(iVar18 + 0x10) = uVar5;
              iVar18 = FUN_0010b0f4(param_3,2);
              *(undefined4 *)(iVar18 + 0x10) = uVar6;
              FUN_00109c0e(param_3 + 0xa4,2,(byte)(uVar14 >> 1) & 1);
              FUN_00109c0e(param_3 + 0xbc,2,(byte)(uVar7 >> 1) & 1);
              FUN_00109c0e(param_3 + 0xa4,1,local_c5 != ((byte)uVar14 & 1));
              FUN_00109c0e(param_3 + 0xbc,1,(byte)uVar7 & 1);
              *(undefined1 *)(param_3 + 0x120) = uVar1;
              *(undefined4 *)(param_3 + 0x124) = uVar8;
              if (local_4c != 0) {
                FUN_0010c568(param_3,&local_50,0,uVar2);
              }
              FUN_000e9596(*(undefined4 *)(iVar12 + 0x158),iVar12,param_3);
              *(int *)(param_3 + 0x160) = iVar17 + *(int *)(param_4 + 0x46c);
              local_d4 = 0x12;
              local_cd = '\x01';
            }
          }
          do {
            if ((*(byte *)((int)local_cc + 0x15) & 2) == 0) goto LAB_00169aa0;
            local_cc = (int *)FUN_0010b180(local_cc,local_cc[0x21]);
            iVar12 = FUN_0010b0f4(local_cc,0);
            uVar14 = FUN_000f5fea(*(undefined4 *)(iVar12 + 0x10));
          } while ((uVar13 & uVar14) == 0);
        } while( true );
      }
      local_d4 = 0x14;
      local_cd = '\0';
      goto LAB_00169aa9;
    }
LAB_00169b5d:
    param_3 = ((int (*)())FUN_00168010)(param_3,param_4,local_d4);
    if (((*(byte *)(param_1 + 0x15) & 2) == 0) || (param_2 != *(int *)(param_1 + 0x84))) {
      FUN_0010ba02(param_1,param_2,param_3,0,uVar2);
    }
    else {
      FUN_0010c18e(param_1,param_3,0,uVar2);
    }
  }
  local_cd = '\0';
LAB_00169aa0:
  if (local_d4 != 0x12) {
LAB_00169aa9:
    if ((0x11 < local_d4) && (local_d4 < 0x15)) {
      iVar12 = FUN_0010b180(param_3,1);
      if (((*(int *)(*(int *)(iVar12 + 0x88) + 8) == 0x13) &&
          (((cVar11 = FUN_0010a62e(iVar12,param_4), cVar11 != '\0' &&
            (*(char *)(iVar12 + 0x120) == '\0')) && (*(int *)(iVar12 + 0x124) == 0)))) &&
         ((*(byte *)(param_3 + 0xb8) & 2) == 0)) {
        ((int (*)())FUN_0016932c)(param_3,1,param_4);
      }
      iVar12 = FUN_0010b180(param_3,2);
      if (((*(int *)(*(int *)(iVar12 + 0x88) + 8) == 0x13) &&
          (cVar11 = FUN_0010a62e(iVar12,param_4), cVar11 != '\0')) &&
         ((*(char *)(iVar12 + 0x120) == '\0' &&
          ((*(int *)(iVar12 + 0x124) == 0 && ((*(byte *)(param_3 + 0xd0) & 2) == 0)))))) {
        ((int (*)())FUN_0016932c)(param_3,2,param_4);
      }
    }
    return local_cd;
  }
LAB_00169bba:
  iVar12 = FUN_0010b180(param_3,1);
  if (((((*(int *)(*(int *)(iVar12 + 0x88) + 8) == 0x12) &&
        (cVar11 = FUN_0010a62e(iVar12,param_4), cVar11 != '\0')) &&
       (*(char *)(iVar12 + 0x120) == '\0')) &&
      ((*(int *)(iVar12 + 0x124) == 0 && ((*(byte *)(param_3 + 0xb8) & 2) == 0)))) &&
     (((*(byte *)(param_3 + 0xd0) & 2) != 0 &&
      (((*(byte *)(iVar12 + 0xb8) & 2) == 0 && ((*(byte *)(iVar12 + 0xd0) & 2) == 0)))))) {
    ((int (*)())FUN_0016932c)(param_3,1,param_4);
  }
  iVar12 = FUN_0010b180(param_3,2);
  if (*(int *)(*(int *)(iVar12 + 0x88) + 8) != 0x12) {
    return local_cd;
  }
  cVar11 = FUN_0010a62e(iVar12,param_4);
  if (cVar11 == '\0') {
    return local_cd;
  }
  if (*(char *)(iVar12 + 0x120) != '\0') {
    return local_cd;
  }
  if (*(int *)(iVar12 + 0x124) != 0) {
    return local_cd;
  }
  if ((*(byte *)(param_3 + 0xb8) & 2) != 0) {
    return local_cd;
  }
  if ((*(byte *)(param_3 + 0xd0) & 2) == 0) {
    return local_cd;
  }
  if ((*(byte *)(iVar12 + 0xb8) & 2) != 0) {
    return local_cd;
  }
  if ((*(byte *)(iVar12 + 0xd0) & 2) != 0) {
    return local_cd;
  }
  ((int (*)())FUN_0016932c)(param_3,2,param_4);
  return local_cd;
}

/* FUN_0016a3b6 @ 0x16a3b6 (367 bytes) */
int FUN_0016a3b6(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int *param_2;
  int param_3;
  undefined4 param_4;
  uint param_5;
  int param_6;
{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  *(int *)(param_6 + 0x1ac) = *(int *)(param_6 + 0x1ac) + 1;
  do {
    while (cVar1 = (**(code **)(*param_2 + 100))(param_2), cVar1 == '\0') {
LAB_0016a3d7:
      uVar3 = param_2[5];
LAB_0016a3da:
      param_2[0x49] = param_2[0x49] + param_3;
      while( true ) {
        if ((uVar3 & 0x200) == 0) {
          return;
        }
        param_2 = (int *)FUN_0010b180(param_2,param_2[0x21]);
        iVar2 = FUN_0010b0f4(param_2,0);
        uVar3 = FUN_000f5fea(*(undefined4 *)(iVar2 + 0x10));
        if ((param_5 & uVar3) != 0) break;
        uVar3 = param_2[5];
      }
    }
    for (iVar2 = 1; iVar4 = (**(code **)(*param_2 + 0x14))(param_2), iVar2 <= iVar4;
        iVar2 = iVar2 + 1) {
      if ((((param_2[iVar2 * 6 + 0x28] & 1U) != 0) || ((param_2[iVar2 * 6 + 0x28] & 2U) != 0)) ||
         (cVar1 = FUN_000f5a1e(param_2,iVar2), cVar1 == '\0')) goto LAB_0016a3d7;
    }
    if (((char)param_2[0x48] != '\0') || (param_2[0x49] != 0)) goto LAB_0016a3d7;
    if ((param_2[0x20] != 0) &&
       (((cVar1 = FUN_0012dfd8(param_2[0x26]), cVar1 != '\0' && ((*(byte *)(param_2 + 5) & 2) == 0))
        && (cVar1 = (**(code **)(*param_2 + 0x50))(param_2), cVar1 == '\0')))) {
      iVar2 = 4;
      piVar5 = param_2;
      do {
        if ((byte)((char)piVar5[0x27] - 2U) < 2) goto LAB_0016a3d7;
        piVar5 = (int *)((int)piVar5 + 1);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_0010b0f4(param_2,0);
    iVar2 = FUN_0010b7c8(param_2,0);
    if (iVar2 != 0) goto LAB_0016a3d7;
    uVar3 = param_2[5];
    if (((uVar3 & 2) != 0) || ((uVar3 & 0x200) != 0)) goto LAB_0016a3da;
    param_2 = (int *)FUN_0010b180(param_2,1);
  } while( true );
}

/* FUN_0016a526 @ 0x16a526 (154 bytes) */
int FUN_0016a526(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  char cVar2;
  
  cVar2 = (**(code **)(*param_2 + 100))(param_2);
  if ((((cVar2 != '\0') && ((char)param_2[0x48] == '\0')) &&
      ((*(byte *)((int)param_2 + 0x15) & 2) == 0)) && (iVar1 = param_2[0x49], iVar1 != 0)) {
    cVar2 = ((int (*)())FUN_00169850)(param_1,param_3,iVar1,param_5,param_6,param_4);
    if (cVar2 != '\0') {
      ((int (*)())FUN_0016a3b6)(param_2,param_3,iVar1,param_5,param_6,param_4);
      param_2[0x49] = 0;
    }
  }
  return;
}

/* FUN_0016a5c0 @ 0x16a5c0 (3025 bytes) */
int FUN_0016a5c0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int *piVar14;
  int iVar15;
  uint *puVar16;
  uint *local_58;
  undefined1 local_45;
  int local_2c;
  int local_28;
  uint local_1c;
  uint local_18;
  int local_14;
  undefined4 local_10;
  
  local_10 = *(undefined4 *)(*(int *)(param_2 + 8) + 0xbc);
  local_18 = 0;
  local_1c = 2;
  local_14 = FUN_001a7bca(local_10,8);
  uVar1 = local_18;
  if (local_18 < local_1c) {
    iVar2 = local_18 * 4;
    _memset((void *)(local_14 + iVar2),0,4);
    local_18 = uVar1 + 1;
    piVar6 = (int *)(iVar2 + local_14);
  }
  else {
    piVar6 = (int *)FUN_001a7f7c(&local_1c,local_18);
  }
  local_58 = &local_1c;
  *piVar6 = param_1;
  local_45 = 0;
  do {
    uVar1 = local_18 - 1;
    if (uVar1 < local_18) {
      piVar6 = (int *)(local_14 + uVar1 * 4);
    }
    else {
      piVar6 = (int *)0x0;
    }
    iVar2 = *piVar6;
    FUN_001a7f3c(local_58,uVar1);
    iVar15 = *(int *)(*(int *)(iVar2 + 0x88) + 8);
    iVar3 = *(int *)(iVar2 + 0x124);
    if (iVar15 - 0x12U < 3) {
      iVar7 = FUN_0010b0f4(iVar2,0);
      uVar4 = *(undefined4 *)(iVar7 + 0x10);
      iVar7 = FUN_0010b0f4(iVar2,1);
      uVar8 = FUN_000f5bdc(*(undefined4 *)(iVar7 + 0x10));
      iVar7 = FUN_0010b0f4(iVar2,2);
      uVar9 = FUN_000f5bdc(*(undefined4 *)(iVar7 + 0x10));
      piVar6 = (int *)FUN_0010b180(iVar2,1);
      piVar10 = (int *)FUN_0010b180(iVar2,2);
      if (iVar15 == 0x13) {
        cVar5 = FUN_0010a62e(piVar6,param_2);
        if ((cVar5 != '\0') && (cVar5 = FUN_0010a62e(piVar10,param_2), cVar5 != '\0')) {
          ((int (*)())FUN_0016a526)(iVar2,piVar6,piVar10,param_2,uVar4,uVar9);
          ((int (*)())FUN_0016a526)(iVar2,piVar10,piVar6,param_2,uVar4,uVar8);
        }
        if (iVar3 != 0) {
          cVar5 = ((int (*)())FUN_00169850)(iVar2,piVar6,iVar3,uVar4,uVar8,param_2);
          if (cVar5 == '\0') {
            cVar5 = ((int (*)())FUN_00169850)(iVar2,piVar10,iVar3,uVar4,uVar9,param_2);
            if (cVar5 != '\0') {
              ((int (*)())FUN_0016a3b6)(iVar2,piVar10,iVar3,uVar4,uVar9,param_2);
              *(undefined4 *)(iVar2 + 0x124) = 0;
              goto LAB_0016a850;
            }
          }
          else {
            ((int (*)())FUN_0016a3b6)(iVar2,piVar6,iVar3,uVar4,uVar8,param_2);
            uVar1 = local_18;
            *(undefined4 *)(iVar2 + 0x124) = 0;
            if (local_18 < local_1c) {
              iVar2 = local_18 * 4;
              _memset((void *)(iVar2 + local_14),0,4);
              local_18 = uVar1 + 1;
              *(int **)(iVar2 + local_14) = piVar6;
            }
            else {
              puVar11 = (undefined4 *)FUN_001a7f7c(local_58,local_18);
              *puVar11 = piVar6;
            }
          }
        }
      }
      else if (iVar15 == 0x14) {
        cVar5 = FUN_0010a62e(piVar6,param_2);
        if ((cVar5 != '\0') && (cVar5 = FUN_0010a62e(piVar10,param_2), cVar5 != '\0')) {
          ((int (*)())FUN_0016a526)(iVar2,piVar6,piVar10,param_2,uVar4,uVar9);
          ((int (*)())FUN_0016a526)(iVar2,piVar10,piVar6,param_2,uVar4,uVar8);
          cVar5 = (**(code **)(*piVar6 + 100))(piVar6);
          if (cVar5 != '\0') {
            local_2c = 1;
            puVar16 = (uint *)(piVar6 + 0x2e);
            iVar15 = (**(code **)(*piVar6 + 0x14))(piVar6);
            while (local_2c <= iVar15) {
              if ((((*puVar16 & 1) != 0) || ((*puVar16 & 2) != 0)) ||
                 (cVar5 = FUN_000f5a1e(piVar6,local_2c), cVar5 == '\0')) goto LAB_0016ac6a;
              local_2c = local_2c + 1;
              puVar16 = puVar16 + 6;
              iVar15 = (**(code **)(*piVar6 + 0x14))(piVar6);
            }
            if (((char)piVar6[0x48] == '\0') && (piVar6[0x49] == 0)) {
              if (((piVar6[0x20] != 0) &&
                  ((cVar5 = FUN_0012dfd8(piVar6[0x26]), cVar5 != '\0' &&
                   ((*(byte *)(piVar6 + 5) & 2) == 0)))) &&
                 (cVar5 = (**(code **)(*piVar6 + 0x50))(piVar6), cVar5 == '\0')) {
                iVar15 = 4;
                piVar14 = piVar6;
                do {
                  if ((byte)((char)piVar14[0x27] - 2U) < 2) goto LAB_0016ac6a;
                  piVar14 = (int *)((int)piVar14 + 1);
                  iVar15 = iVar15 + -1;
                } while (iVar15 != 0);
              }
              FUN_0010b0f4(piVar6,0);
              iVar15 = FUN_0010b7c8(piVar6,0);
              if (((iVar15 == 0) && ((piVar6[5] & 2U) == 0)) && ((piVar6[5] & 0x200U) == 0)) {
                *(int *)(param_2 + 0x17c) = *(int *)(param_2 + 0x17c) + 1;
                uVar12 = *(undefined4 *)(param_2 + 8);
                uVar13 = FUN_0010b180(piVar6,1);
                FUN_0010ba02(iVar2,1,uVar13,0,uVar12);
                iVar15 = *(int *)(param_2 + 0x46c);
                iVar7 = FUN_0010b180(piVar6,1);
                if (iVar15 < *(int *)(iVar7 + 0x160)) {
                  *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar7 + 0x160) = iVar15 + 1;
                }
                FUN_0010b3fe(piVar6,*(undefined4 *)(param_2 + 8));
              }
            }
          }
LAB_0016ac6a:
          cVar5 = (**(code **)(*piVar10 + 100))(piVar10);
          if (cVar5 != '\0') {
            local_28 = 1;
            puVar16 = (uint *)(piVar10 + 0x2e);
            iVar15 = (**(code **)(*piVar10 + 0x14))(piVar10);
            while (local_28 <= iVar15) {
              if ((((*puVar16 & 1) != 0) || ((*puVar16 & 2) != 0)) ||
                 (cVar5 = FUN_000f5a1e(piVar10,local_28), cVar5 == '\0')) goto LAB_0016a9a0;
              local_28 = local_28 + 1;
              puVar16 = puVar16 + 6;
              iVar15 = (**(code **)(*piVar10 + 0x14))(piVar10);
            }
            if (((char)piVar10[0x48] == '\0') && (piVar10[0x49] == 0)) {
              if ((piVar10[0x20] != 0) &&
                 (((cVar5 = FUN_0012dfd8(piVar10[0x26]), cVar5 != '\0' &&
                   ((*(byte *)(piVar10 + 5) & 2) == 0)) &&
                  (cVar5 = (**(code **)(*piVar10 + 0x50))(piVar10), cVar5 == '\0')))) {
                iVar15 = 4;
                piVar14 = piVar10;
                do {
                  if ((byte)((char)piVar14[0x27] - 2U) < 2) goto LAB_0016a9a0;
                  piVar14 = (int *)((int)piVar14 + 1);
                  iVar15 = iVar15 + -1;
                } while (iVar15 != 0);
              }
              FUN_0010b0f4(piVar10,0);
              iVar15 = FUN_0010b7c8(piVar10,0);
              if (((iVar15 == 0) && ((piVar10[5] & 2U) == 0)) && ((piVar10[5] & 0x200U) == 0)) {
                *(int *)(param_2 + 0x17c) = *(int *)(param_2 + 0x17c) + 1;
                uVar12 = *(undefined4 *)(param_2 + 8);
                uVar13 = FUN_0010b180(piVar10,1);
                FUN_0010ba02(iVar2,2,uVar13,0,uVar12);
                iVar15 = *(int *)(param_2 + 0x46c);
                iVar7 = FUN_0010b180(piVar10,1);
                if (iVar15 < *(int *)(iVar7 + 0x160)) {
                  *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar7 + 0x160) = iVar15 + 1;
                }
                FUN_0010b3fe(piVar10,*(undefined4 *)(param_2 + 8));
              }
            }
          }
        }
LAB_0016a9a0:
        if (iVar3 != 0) {
          uVar12 = FUN_0010b180(iVar2,3);
          iVar15 = FUN_0010b0f4(iVar2,3);
          uVar13 = FUN_000f5bdc(*(undefined4 *)(iVar15 + 0x10));
          cVar5 = ((int (*)())FUN_00169850)(iVar2,uVar12,iVar3,uVar4,uVar13,param_2);
          if (cVar5 != '\0') {
            cVar5 = ((int (*)())FUN_00169850)(iVar2,piVar6,iVar3,uVar4,uVar8,param_2);
            if (cVar5 == '\0') {
              cVar5 = ((int (*)())FUN_00169850)(iVar2,piVar10,iVar3,uVar4,uVar9,param_2);
              if (cVar5 == '\0') break;
              ((int (*)())FUN_0016a3b6)(iVar2,piVar10,iVar3,uVar4,uVar9,param_2);
              uVar1 = local_18;
              *(undefined4 *)(iVar2 + 0x124) = 0;
              if (local_18 < local_1c) {
                iVar15 = local_18 * 4;
                _memset((void *)(iVar15 + local_14),0,4);
                local_18 = uVar1 + 1;
                puVar11 = (undefined4 *)(iVar15 + local_14);
              }
              else {
                puVar11 = (undefined4 *)FUN_001a7f7c(local_58,local_18);
              }
              *puVar11 = piVar10;
            }
            else {
              ((int (*)())FUN_0016a3b6)(iVar2,piVar6,iVar3,uVar4,uVar8,param_2);
              uVar1 = local_18;
              *(undefined4 *)(iVar2 + 0x124) = 0;
              if (local_18 < local_1c) {
                iVar15 = local_18 * 4;
                _memset((void *)(iVar15 + local_14),0,4);
                local_18 = uVar1 + 1;
                *(int **)(iVar15 + local_14) = piVar6;
              }
              else {
                puVar11 = (undefined4 *)FUN_001a7f7c(local_58,local_18);
                *puVar11 = piVar6;
              }
            }
            ((int (*)())FUN_0016a3b6)(iVar2,uVar12,iVar3,uVar4,uVar13,param_2);
            uVar1 = local_18;
            if (local_18 < local_1c) {
              iVar2 = local_18 * 4;
              _memset((void *)(iVar2 + local_14),0,4);
              local_18 = uVar1 + 1;
              *(undefined4 *)(iVar2 + local_14) = uVar12;
            }
            else {
              puVar11 = (undefined4 *)FUN_001a7f7c(local_58,local_18);
              *puVar11 = uVar12;
            }
          }
        }
      }
      else if (((iVar15 == 0x12) && (iVar3 != 0)) &&
              ((cVar5 = ((int (*)())FUN_00169850)(iVar2,piVar6,iVar3,uVar4,uVar8,param_2), cVar5 != '\0' &&
               (cVar5 = ((int (*)())FUN_00169850)(iVar2,piVar10,iVar3,uVar4,uVar9,param_2), cVar5 != '\0')))) {
        *(undefined4 *)(iVar2 + 0x124) = 0;
        if (param_1 == iVar2) {
          local_45 = 1;
        }
        ((int (*)())FUN_0016a3b6)(iVar2,piVar6,iVar3,uVar4,uVar8,param_2);
        uVar1 = local_18;
        if (local_18 < local_1c) {
          iVar15 = local_18 * 4;
          _memset((void *)(iVar15 + local_14),0,4);
          local_18 = uVar1 + 1;
          puVar11 = (undefined4 *)(iVar15 + local_14);
        }
        else {
          puVar11 = (undefined4 *)FUN_001a7f7c(local_58,local_18);
        }
        *puVar11 = piVar6;
        if (piVar6 != piVar10) {
          ((int (*)())FUN_0016a3b6)(iVar2,piVar10,iVar3,uVar4,uVar9,param_2);
LAB_0016a850:
          uVar1 = local_18;
          if (local_18 < local_1c) {
            iVar2 = local_18 * 4;
            _memset((void *)(iVar2 + local_14),0,4);
            local_18 = uVar1 + 1;
            *(int **)(iVar2 + local_14) = piVar10;
          }
          else {
            puVar11 = (undefined4 *)FUN_001a7f7c(local_58,local_18);
            *puVar11 = piVar10;
          }
        }
      }
    }
  } while (local_18 != 0);
  FUN_001a7aba(local_10,local_14);
  return local_45;
}

/* FUN_0016b1ae @ 0x16b1ae (428 bytes) */
int FUN_0016b1ae(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  int local_38;
  int local_34;
  undefined4 local_20 [4];
  
  cVar1 = FUN_00183844(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  iVar2 = FUN_0010b0f4(param_1,1);
  local_20[0] = *(undefined4 *)(iVar2 + 0x10);
  local_38 = -1;
  local_34 = 0;
  do {
    iVar3 = FUN_0010b0f4(param_1,0);
    iVar2 = local_38;
    if (*(char *)(local_34 + 0x10 + iVar3) != '\x01') {
      uVar6 = (uint)*(byte *)((int)local_20 + local_34);
      piVar4 = (int *)FUN_0010b180(param_1,1);
      cVar1 = (**(code **)(*piVar4 + 0x60))(piVar4);
      if (cVar1 != '\0') {
        uVar5 = FUN_0010a088(piVar4,uVar6);
        iVar2 = FUN_0010b0f4(piVar4,uVar5);
        uVar6 = (uint)*(byte *)(uVar6 + 0x10 + iVar2);
        piVar4 = (int *)FUN_0010b180(piVar4,uVar5);
      }
      cVar1 = FUN_0012df9c(piVar4[0x26]);
      if (cVar1 == '\0') {
        return 0;
      }
      if (((int)(char)piVar4[0x57] >> ((byte)uVar6 & 0x1f) & 1U) == 0) {
        return 0;
      }
      uVar5 = ((float (*)())FUN_0011048e)(param_1,1,piVar4[uVar6 * 6 + 8]);
      uVar5 = ((float (*)())FUN_0011042e)(param_1,1,uVar5);
      cVar1 = ((bool (*)())FUN_00110958)(param_1,uVar5,0);
      iVar3 = ~-(uint)(cVar1 == '\0') + 3;
      iVar2 = iVar3;
      if ((local_38 != -1) && (iVar2 = local_38, iVar3 != local_38)) {
        return 0;
      }
    }
    local_38 = iVar2;
    local_34 = local_34 + 1;
    if (local_34 == 4) {
      *(int *)(param_2 + 0x1ec) = *(int *)(param_2 + 0x1ec) + 1;
      FUN_00112450(param_1,local_38,0,*(undefined4 *)(param_2 + 8));
      return 1;
    }
  } while( true );
}

/* FUN_0016b35a @ 0x16b35a (1183 bytes) */
int FUN_0016b35a(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_2c = 0x3f000000;
  local_28 = 0x3f000000;
  local_24 = 0x3f000000;
  local_20 = 0x3f000000;
  iVar5 = *(int *)(param_1 + 0x88);
  if (*(int *)(iVar5 + 8) == 0x24) {
    uVar11 = FUN_00118f66(0x25);
    *(undefined4 *)(param_1 + 0x88) = uVar11;
    FUN_00109c0e(param_1 + 0xa4,1,1);
    FUN_00109c0e(param_1 + 0xa4,2,1);
    uVar11 = 1;
    iVar5 = *(int *)(param_1 + 0x88);
  }
  else if (*(int *)(iVar5 + 8) == 0x26) {
    uVar11 = FUN_00118f66(0x25);
    *(undefined4 *)(param_1 + 0x88) = uVar11;
    FUN_00109c0e(param_1 + 0xa4,1,*(byte *)(param_1 + 0xb8) & 1 ^ 1);
    FUN_0010fe82(param_1,2,3,param_3);
    uVar11 = 1;
    iVar5 = *(int *)(param_1 + 0x88);
  }
  else {
    uVar11 = 0;
  }
  if ((*(int *)(iVar5 + 8) != 0x25) || ((*(byte *)(*(int *)(param_3 + 0x3f4) + 0x30) & 8) == 0)) {
    return uVar11;
  }
  if (param_2 != '\0') {
    iVar5 = FUN_0010b180(param_1,1);
    iVar6 = FUN_0010b0f4(iVar5,0);
    uVar1 = *(undefined4 *)(iVar6 + 0x10);
    if ((*(byte *)(param_1 + 0xb8) & 2) != 0) {
      return uVar11;
    }
    if (*(int *)(*(int *)(iVar5 + 0x88) + 8) != 0x12) {
      return uVar11;
    }
    if ((((*(byte *)(iVar5 + 0x15) & 2) == 0) && (*(char *)(iVar5 + 0x120) == '\0')) &&
       (*(int *)(iVar5 + 0x124) == 0)) {
      iVar6 = FUN_0010b180(iVar5,1);
      uVar7 = 0;
      if (iVar6 != 0) {
        iVar6 = FUN_0010b180(iVar5,1);
        uVar7 = *(undefined4 *)(iVar6 + 0x98);
      }
      cVar3 = FUN_0012e014(uVar7);
      if (cVar3 == '\0') {
        piVar8 = (int *)FUN_0010b180(iVar5,1);
        cVar3 = (**(code **)(*piVar8 + 0x5c))(piVar8);
        if (cVar3 == '\0') {
          return uVar11;
        }
      }
      if (((*(uint *)(iVar5 + 0xb8) & 2) == 0) &&
         (bVar4 = *(byte *)(param_1 + 0xb8) & 1, (*(byte *)(iVar5 + 0xd0) & 1) == bVar4)) {
        if (bVar4 == ((byte)*(uint *)(iVar5 + 0xb8) & 1)) {
          return uVar11;
        }
        cVar3 = FUN_000f7dda(iVar5,2,uVar1,&local_2c);
        if (cVar3 == '\0') {
          return uVar11;
        }
        uVar11 = FUN_00118f66(0x9d);
        *(undefined4 *)(param_1 + 0x88) = uVar11;
        iVar6 = FUN_0010b0f4(iVar5,1);
        uVar11 = *(undefined4 *)(iVar6 + 0x10);
        iVar6 = FUN_0010b0f4(param_1,1);
        uVar11 = FUN_000f5610(uVar11,*(undefined4 *)(iVar6 + 0x10));
        iVar6 = FUN_0010b0f4(param_1,1);
        *(undefined4 *)(iVar6 + 0x10) = uVar11;
        FUN_00109c0e(param_1 + 0xa4,1,0);
        FUN_0010fe82(param_1,2,3,param_3);
        iVar6 = *(int *)(param_3 + 0x3f4);
        iVar2 = *(int *)(iVar6 + 0x46c);
        piVar8 = (int *)FUN_0010b180(iVar5,1);
        cVar3 = (**(code **)(*piVar8 + 0x5c))(piVar8);
        if ((cVar3 == '\0') || (cVar3 = FUN_0010a62e(piVar8,iVar6), cVar3 != '\0')) {
          FUN_0010ba02(param_1,1,piVar8,0,param_3);
          if (iVar2 < piVar8[0x58]) {
            piVar8[0x58] = piVar8[0x58] + 1;
          }
          else {
            piVar8[0x58] = iVar2 + 1;
          }
        }
        else {
          iVar9 = FUN_0010a1c2(piVar8,param_3,0);
          *(undefined4 *)(iVar9 + 0x94) = *(undefined4 *)(iVar9 + 0x14c);
          FUN_000e9596(piVar8[0x56],piVar8,iVar9);
          FUN_0010ba02(param_1,1,iVar9,0,param_3);
          *(int *)(iVar9 + 0x160) = *(int *)(iVar6 + 0x46c) + 1;
          if (0 < *(int *)(iVar9 + 0x84)) {
            iVar6 = 1;
            do {
              iVar10 = FUN_0010b180(iVar9,iVar6);
              if (iVar2 < *(int *)(iVar10 + 0x160)) {
                *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + 1;
              }
              else {
                *(int *)(iVar10 + 0x160) = iVar2 + 1;
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 <= *(int *)(iVar9 + 0x84));
          }
        }
        FUN_0010b3fe(iVar5,param_3);
        return 1;
      }
    }
  }
  return uVar11;
}

/* FUN_0016b7fa @ 0x16b7fa (3991 bytes) */
int FUN_0016b7fa(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  char cVar3;
  byte bVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  float fVar9;
  float fVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  byte bVar15;
  int *local_128;
  int local_124;
  int local_f0;
  bool local_dc;
  bool local_c1;
  int *local_b0;
  undefined1 local_ac [4];
  float local_a8;
  undefined1 local_94 [4];
  float local_90;
  undefined1 local_7c [4];
  float local_78;
  undefined1 local_64 [4];
  float local_60;
  undefined1 local_4c [4];
  undefined4 local_48;
  undefined1 local_34 [4];
  undefined4 local_30;
  
  iVar1 = *(int *)(param_3 + 8);
  if (*(int *)(iVar1 + 0x3d4) <=
      *(int *)(*(int *)(iVar1 + 0x3f4) + 0x214) + *(int *)(*(int *)(iVar1 + 0x3f4) + 0x218)) {
    return 0;
  }
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x84) < 1) {
    return 0;
  }
  iVar6 = FUN_0010b180(param_1,1);
  if (iVar6 == 0) {
    return 0;
  }
  ((int (*)())FUN_0016b35a)(param_1,param_2,iVar1);
  ((int (*)())FUN_0016b35a)(iVar6,param_2,iVar1);
  iVar7 = *(int *)(param_1 + 0x88);
  if ((*(int *)(iVar7 + 8) == 0x25) && (*(int *)(*(int *)(iVar6 + 0x88) + 8) == 0x25)) {
    cVar3 = FUN_000f6cc2(param_1,1);
    if (cVar3 == '\0') {
      iVar7 = *(int *)(param_1 + 0x88);
    }
    else {
      iVar7 = FUN_0010b0f4(iVar6,0);
      cVar3 = FUN_000f7e7e(iVar6,2,*(undefined4 *)(iVar7 + 0x10),local_34);
      if (cVar3 != '\0') {
        iVar7 = FUN_0010b0f4(iVar6,0);
        cVar3 = FUN_000f7e7e(iVar6,3,*(undefined4 *)(iVar7 + 0x10),local_4c);
        if (cVar3 != '\0') {
          *(int *)(param_3 + 0x214) = *(int *)(param_3 + 0x214) + 1;
          piVar8 = (int *)FUN_0010b180(iVar6,1);
          cVar3 = (**(code **)(*piVar8 + 0x5c))(piVar8);
          local_128 = piVar8;
          if ((cVar3 != '\0') && (cVar3 = FUN_0010a62e(piVar8,param_3), cVar3 == '\0')) {
            local_128 = (int *)FUN_0010a1c2(piVar8,iVar1,0);
            local_128[0x25] = local_128[0x53];
            FUN_000e9596(piVar8[0x56],piVar8,local_128);
            local_128[0x58] = *(int *)(param_3 + 0x46c);
            if (0 < local_128[0x21]) {
              local_124 = 1;
              do {
                iVar7 = *(int *)(param_3 + 0x46c);
                iVar14 = FUN_0010b180(local_128,local_124);
                iVar12 = *(int *)(iVar14 + 0x160);
                if (*(int *)(iVar14 + 0x160) <= iVar7) {
                  iVar12 = iVar7;
                }
                *(int *)(iVar14 + 0x160) = iVar12 + 1;
                local_124 = local_124 + 1;
              } while (local_124 <= local_128[0x21]);
            }
          }
          uVar13 = ((float (*)())FUN_001100e2)(iVar6,local_30);
          uVar11 = ((float (*)())FUN_001100e2)(iVar6,local_48);
          uVar13 = ((float (*)())FUN_001102fa)(iVar6,uVar13);
          uVar11 = ((float (*)())FUN_001102fa)(iVar6,uVar11);
          uVar13 = ((float (*)())FUN_0011048e)(param_1,1,uVar13);
          uVar11 = ((float (*)())FUN_0011048e)(param_1,1,uVar11);
          fVar9 = (float)((float (*)())FUN_0011042e)(param_1,1,uVar13);
          fVar10 = (float)((float (*)())FUN_0011042e)(param_1,1,uVar11);
          if ((0.0 <= fVar9) || (0.0 <= fVar10)) {
            if ((fVar9 < 0.0) || (fVar10 < 0.0)) {
              uVar2 = *(uint *)(iVar6 + 0xb8);
              cVar3 = (**(code **)(*local_128 + 0x5c))(local_128);
              if (cVar3 == '\0') {
                local_b0 = local_128;
              }
              else {
                iVar7 = *(int *)(param_3 + 0x46c);
                local_b0 = (int *)FUN_0010a1c2(local_128,*(undefined4 *)(param_3 + 8),0);
                iVar12 = local_b0[0x53];
                iVar14 = FUN_0010b0f4(local_b0,0);
                *(int *)(iVar14 + 8) = iVar12;
                local_b0[0x58] = iVar7;
                iVar12 = 1;
                while (iVar14 = (**(code **)(*local_b0 + 0x14))(local_b0), iVar12 <= iVar14) {
                  iVar14 = FUN_0010b180(local_b0,iVar12);
                  if (iVar7 < *(int *)(iVar14 + 0x160)) {
                    *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + 1;
                    iVar12 = iVar12 + 1;
                  }
                  else {
                    *(int *)(iVar14 + 0x160) = iVar7 + 1;
                    iVar12 = iVar12 + 1;
                  }
                }
                FUN_000e956e(local_128[0x56],local_128,local_b0);
              }
              FUN_0010ba02(param_1,1,local_b0,0,iVar1);
              if (*(int *)(param_3 + 0x46c) < local_b0[0x58]) {
                local_b0[0x58] = local_b0[0x58] + 1;
              }
              else {
                local_b0[0x58] = *(int *)(param_3 + 0x46c) + 1;
              }
              FUN_00109c0e(param_1 + 0xa4,1,(byte)uVar2 & 1);
              FUN_00109c0e(param_1 + 0xa4,2,(byte)(uVar2 >> 1) & 1);
              iVar7 = FUN_0010b0f4(iVar6,1);
              uVar13 = *(undefined4 *)(iVar7 + 0x10);
              iVar7 = FUN_0010b0f4(param_1,1);
              uVar13 = FUN_000f5610(uVar13,*(undefined4 *)(iVar7 + 0x10));
              iVar7 = FUN_0010b0f4(param_1,1);
              *(undefined4 *)(iVar7 + 0x10) = uVar13;
              if ((fVar9 < 0.0) || (0.0 <= fVar10)) {
                FUN_0010fe82(param_1,2,3,iVar1);
              }
              uVar5 = FUN_0010b3fe(iVar6,iVar1);
              return uVar5;
            }
          }
          else if ((fVar9 < 0.0) || (fVar10 < 0.0)) {
            uVar13 = 3;
            goto LAB_0016bf89;
          }
          uVar13 = 2;
LAB_0016bf89:
          FUN_00112450(param_1,uVar13,0,iVar1);
          return 0;
        }
      }
      iVar7 = *(int *)(param_1 + 0x88);
    }
  }
  if (*(int *)(iVar7 + 8) == 0x8b) {
    local_f0 = *(int *)(param_1 + 300);
    iVar6 = FUN_0010b0f4(param_1,0);
    cVar3 = FUN_000f7e7e(param_1,2,*(undefined4 *)(iVar6 + 0x10),local_64);
    if (cVar3 == '\0') {
      iVar6 = FUN_0010b0f4(param_1,0);
      cVar3 = FUN_000f7e7e(param_1,1,*(undefined4 *)(iVar6 + 0x10),local_64);
      if (cVar3 == '\0') {
        return 0;
      }
      FUN_0010fe82(param_1,1,2,iVar1);
      local_f0 = *(int *)(PTR_DAT_002139fd + local_f0 * 4);
      *(int *)(param_1 + 300) = local_f0;
    }
    iVar6 = FUN_0010b180(param_1,1);
    if (((*(byte *)(param_1 + 0xb8) & 2) == 0) && ((*(byte *)(param_1 + 0xd0) & 2) == 0)) {
      if (*(int *)(*(int *)(iVar6 + 0x88) + 8) == 0x12) {
        if ((((local_60 == FLOAT_001c5b9c) && (!NAN(local_60) && !NAN(FLOAT_001c5b9c))) &&
            (*(char *)(iVar6 + 0x120) == '\0')) && ((*(byte *)(iVar6 + 0x15) & 2) == 0)) {
          iVar7 = FUN_0010b0f4(param_1,1);
          uVar13 = *(undefined4 *)(iVar7 + 0x10);
          *(int *)(param_3 + 0x218) = *(int *)(param_3 + 0x218) + 1;
          uVar11 = FUN_0010b180(param_1,2);
          FUN_0010b3fe(uVar11,iVar1);
          uVar11 = FUN_0010b180(iVar6,1);
          FUN_0010ba02(param_1,1,uVar11,0,iVar1);
          iVar7 = FUN_0010b0f4(iVar6,1);
          uVar11 = FUN_000f5610(*(undefined4 *)(iVar7 + 0x10),uVar13);
          iVar7 = FUN_0010b0f4(param_1,1);
          *(undefined4 *)(iVar7 + 0x10) = uVar11;
          iVar7 = *(int *)(param_3 + 0x46c);
          iVar12 = FUN_0010b180(iVar6,1);
          if (iVar7 < *(int *)(iVar12 + 0x160)) {
            *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + 1;
          }
          else {
            *(int *)(iVar12 + 0x160) = iVar7 + 1;
          }
          FUN_00109c0e(param_1 + 0xa4,2,*(uint *)(iVar6 + 0xb8) >> 1 & 1);
          uVar11 = FUN_0010b180(iVar6,2);
          FUN_0010ba02(param_1,2,uVar11,0,iVar1);
          iVar7 = FUN_0010b0f4(iVar6,2);
          uVar13 = FUN_000f5610(*(undefined4 *)(iVar7 + 0x10),uVar13);
          iVar7 = FUN_0010b0f4(param_1,2);
          *(undefined4 *)(iVar7 + 0x10) = uVar13;
          iVar7 = *(int *)(param_3 + 0x46c);
          iVar12 = FUN_0010b180(iVar6,2);
          if (iVar7 < *(int *)(iVar12 + 0x160)) {
            *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + 1;
          }
          else {
            *(int *)(iVar12 + 0x160) = iVar7 + 1;
          }
          FUN_00109c0e(param_1 + 0xbc,2,*(uint *)(iVar6 + 0xd0) >> 1 & 1);
          bVar15 = *(byte *)(param_1 + 0xb8) & 1;
          bVar4 = bVar15;
          if ((*(byte *)(iVar6 + 0xb8) & 1) != 0) {
            bVar4 = bVar15 ^ 1;
          }
          if ((*(byte *)(iVar6 + 0xd0) & 1) != 0) {
            bVar15 = bVar15 ^ 1;
          }
          FUN_00109c0e(param_1 + 0xa4,1,bVar4);
          FUN_00109c0e(param_1 + 0xbc,1,bVar15 ^ 1);
          uVar5 = FUN_0010b3fe(iVar6,iVar1);
          return uVar5;
        }
      }
      iVar7 = FUN_0010b0f4(param_1,0);
      cVar3 = FUN_000f7e7e(param_1,2,*(undefined4 *)(iVar7 + 0x10),local_7c);
      if ((*(int *)(*(int *)(iVar6 + 0x88) + 8) == 0x25) && (cVar3 != '\0')) {
        if (((local_78 == FLOAT_001c5b9c) && (!NAN(local_78) && !NAN(FLOAT_001c5b9c))) &&
           (((*(byte *)(iVar6 + 0x15) & 2) == 0 ||
            (cVar3 = FUN_000f6a7e(param_1,1,iVar6,param_3), cVar3 != '\0')))) {
          iVar7 = FUN_0010b0f4(iVar6,0);
          cVar3 = FUN_000f7e7e(iVar6,2,*(undefined4 *)(iVar7 + 0x10),local_94);
          if (cVar3 != '\0') {
            iVar7 = FUN_0010b0f4(iVar6,0);
            cVar3 = FUN_000f7e7e(iVar6,3,*(undefined4 *)(iVar7 + 0x10),local_ac);
            if (cVar3 != '\0') {
              *(int *)(param_3 + 0x218) = *(int *)(param_3 + 0x218) + 1;
              switch(local_f0) {
              case 0:
                local_dc = local_60 == local_90;
                local_c1 = local_60 == local_a8;
                break;
              case 1:
                local_dc = local_60 != local_90;
                local_c1 = local_60 != local_a8;
                break;
              case 2:
                local_dc = local_60 < local_90;
                local_c1 = local_60 < local_a8;
                break;
              case 3:
                local_dc = local_60 <= local_90;
                local_c1 = local_60 <= local_a8;
                break;
              case 4:
                local_dc = local_90 < local_60;
                local_c1 = local_a8 < local_60;
                break;
              case 5:
                local_dc = local_90 <= local_60;
                local_c1 = local_a8 <= local_60;
                break;
              default:
                goto switchD_0016bb43_default;
              }
              iVar7 = FUN_0010b0f4(param_1,1);
              uVar13 = *(undefined4 *)(iVar7 + 0x10);
              iVar7 = FUN_0010b0f4(iVar6,1);
              uVar13 = FUN_000f5610(*(undefined4 *)(iVar7 + 0x10),uVar13);
              FUN_0010b85e(param_1,1,iVar6,1);
              iVar7 = FUN_0010b0f4(param_1,1);
              *(undefined4 *)(iVar7 + 0x10) = uVar13;
              if (local_dc == local_c1) {
                if (local_dc == false) {
                  FUN_000fa0d2(param_1,param_3,1,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
                  piVar8 = (int *)0x0;
                }
                else {
                  FUN_000fa0d2(param_1,param_3,1,0,0,0,0);
                  piVar8 = (int *)0x0;
                }
              }
              else {
                piVar8 = (int *)FUN_0010b180(iVar6,1);
                if (*(int *)(param_3 + 0x46c) < piVar8[0x58]) {
                  piVar8[0x58] = piVar8[0x58] + 1;
                }
                else {
                  piVar8[0x58] = *(int *)(param_3 + 0x46c) + 1;
                }
                *(int *)(param_1 + 300) = ((int)((uint)local_dc << 0x1f) >> 0x1f) + 4;
              }
              uVar5 = FUN_0010b3fe(iVar6,iVar1);
              if (piVar8 == (int *)0x0) {
                return uVar5;
              }
              cVar3 = (**(code **)(*piVar8 + 0x5c))(piVar8);
              if (cVar3 == '\0') {
                return uVar5;
              }
              cVar3 = FUN_0010a62e(piVar8,param_3);
              if (cVar3 == '\0') {
                iVar6 = *(int *)(param_3 + 0x46c);
                piVar8[0x58] = piVar8[0x58] + -1;
                piVar8 = (int *)FUN_0010a1c2(piVar8,*(undefined4 *)(param_3 + 8),0);
                iVar7 = piVar8[0x53];
                iVar12 = FUN_0010b0f4(piVar8,0);
                *(int *)(iVar12 + 8) = iVar7;
                iVar7 = iVar6 + 1;
                piVar8[0x58] = iVar7;
                iVar12 = 1;
                while (iVar14 = (**(code **)(*piVar8 + 0x14))(piVar8), iVar12 <= iVar14) {
                  iVar14 = FUN_0010b180(piVar8,iVar12);
                  if (iVar6 < *(int *)(iVar14 + 0x160)) {
                    *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + 1;
                    iVar12 = iVar12 + 1;
                  }
                  else {
                    *(int *)(iVar14 + 0x160) = iVar7;
                    iVar12 = iVar12 + 1;
                  }
                }
                FUN_0010ba02(param_1,1,piVar8,0,iVar1);
                FUN_000e956e(*(undefined4 *)(param_1 + 0x158),param_1,piVar8);
                return uVar5;
              }
              return uVar5;
            }
          }
        }
      }
    }
  }
switchD_0016bb43_default:
  return 0;
}

/* FUN_0016c7ac @ 0x16c7ac (4232 bytes) */
int FUN_0016c7ac(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  int *piVar16;
  int *piVar17;
  uint uVar18;
  undefined4 uVar19;
  int *piVar20;
  int iVar21;
  int *piVar22;
  byte bVar23;
  undefined4 *puVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int local_d0;
  int local_cc;
  int *local_c8;
  int local_c4;
  int *local_c0;
  int local_bc;
  uint local_b8;
  int local_b4;
  int local_b0;
  int local_98;
  undefined1 local_85;
  int *local_84;
  int local_7c;
  byte local_75;
  int local_70;
  uint local_50;
  int local_4c;
  int local_44;
  int local_40;
  int local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x10) + 4);
  iVar21 = uVar1 << 2;
  iVar8 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_2 + 8) + 0xbc),iVar21);
  iVar9 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_2 + 8) + 0xbc),iVar21);
  iVar21 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_2 + 8) + 0xbc),iVar21);
  if (0 < (int)uVar1) {
    local_98 = 0;
    uVar18 = 0;
    do {
      puVar2 = *(uint **)(param_1 + 0x10);
      if (uVar18 < *puVar2) {
        uVar3 = puVar2[1];
        if (uVar3 <= uVar18) {
          _memset((void *)(puVar2[2] + uVar3 * 4),0,(uVar18 - uVar3) * 4 + 4);
          puVar2[1] = uVar18 + 1;
        }
        local_84 = (int *)(puVar2[2] + uVar18 * 4);
      }
      else {
        local_84 = (int *)FUN_001a7f7c(puVar2,uVar18);
      }
      local_b8 = uVar18 + 1;
      local_84 = (int *)*local_84;
      iVar26 = uVar18 * 4;
      *(int *)(iVar8 + iVar26) = (int)local_84;
      puVar24 = (undefined4 *)(iVar9 + iVar26);
      *puVar24 = 0;
      piVar10 = (int *)(iVar26 + iVar21);
      *piVar10 = 0;
      bVar5 = false;
      if (*(int *)(local_84[0x22] + 8) == 0x13) {
        while ((((*(byte *)((int)local_84 + 0x15) & 2) == 0 &&
                (cVar6 = FUN_0010a62e(local_84,param_2), cVar6 != '\0')) &&
               ((char)local_84[0x48] == '\0'))) {
          piVar20 = (int *)local_84[4];
          if (*piVar20 == 0) {
            piVar20 = (int *)FUN_001a7f7c(piVar20,0);
          }
          else {
            if (piVar20[1] == 0) {
              *(undefined4 *)piVar20[2] = 0;
              piVar20[1] = 1;
            }
            piVar20 = (int *)piVar20[2];
          }
          piVar20 = (int *)*piVar20;
          bVar4 = false;
          local_d0 = 0x98;
          for (iVar25 = 1; iVar11 = (**(code **)(*piVar20 + 0x14))(piVar20), iVar25 <= iVar11;
              iVar25 = iVar25 + 1) {
            piVar22 = (int *)FUN_0010b180(piVar20,iVar25);
            if (local_84 == piVar22) {
              iVar11 = FUN_0010b0f4(piVar20,iVar25);
              cVar6 = FUN_000f59e0(*(undefined4 *)(iVar11 + 0x10));
              if ((cVar6 == '\0') || ((*(byte *)(local_d0 + 0x20 + (int)piVar20) & 2) != 0)) {
                bVar4 = true;
                *piVar10 = iVar25;
              }
              else {
                *piVar10 = iVar25;
              }
            }
            local_d0 = local_d0 + 0x18;
          }
          if ((bVar4) || (bVar5 = true, local_84 = piVar20, *(int *)(piVar20[0x22] + 8) != 0x13))
          break;
        }
      }
      if (bVar5) {
        if (((*(byte *)((int)local_84 + 0x15) & 2) != 0) ||
           ((*(int *)(local_84[0x22] + 8) != 0x12 && (*(int *)(local_84[0x22] + 8) != 0x14))))
        goto LAB_0016c984;
        *puVar24 = local_84;
        local_98 = local_98 + 1;
      }
      else if (((*(int *)(local_84[0x22] + 8) == 0x14) &&
               ((*(byte *)((int)local_84 + 0x15) & 2) == 0)) &&
              ((iVar25 = FUN_0010b180(local_84,1), param_1 == iVar25 ||
               (iVar25 = FUN_0010b180(local_84,2), param_1 == iVar25)))) {
        *puVar24 = local_84;
        iVar26 = FUN_0010b180(local_84,1);
        if (param_1 == iVar26) {
          iVar26 = 1;
        }
        else {
          iVar26 = 2;
        }
        *piVar10 = iVar26;
        local_98 = local_98 + 1;
      }
      else {
LAB_0016c984:
        *(int *)(iVar8 + iVar26) = 0;
      }
      uVar18 = local_b8;
    } while (uVar1 != local_b8);
    if (1 < local_98) {
      iVar26 = 0;
      local_85 = 0;
      do {
        iVar25 = iVar26 * 4;
        piVar20 = (int *)(iVar8 + iVar25);
        piVar10 = (int *)*piVar20;
        if (((piVar10 != (int *)0x0) && ((*(byte *)(piVar10 + 5) & 1) != 0)) &&
           (piVar22 = (int *)(iVar9 + iVar25), (*(byte *)(*piVar22 + 0x14) & 1) != 0)) {
          for (local_7c = 1; iVar11 = (**(code **)(*piVar10 + 0x14))(piVar10), local_7c <= iVar11;
              local_7c = local_7c + 1) {
            iVar11 = FUN_0010b180(*piVar20,local_7c);
            if (param_1 == iVar11) {
              iVar11 = FUN_0010b0f4(*piVar20,local_7c);
              local_b0 = *(int *)(iVar11 + 0x10);
              local_75 = (byte)(*(uint *)(*piVar20 + 0xa0 + local_7c * 0x18) >> 1) & 1;
              goto LAB_0016cb1b;
            }
            piVar10 = (int *)*piVar20;
          }
          local_7c = 0;
          local_75 = 0;
LAB_0016cb1b:
          iVar11 = iVar26 + 1;
          if (iVar11 < (int)uVar1) {
            iVar12 = iVar11 * 4;
            local_34 = (int *)(iVar8 + iVar12);
            local_30 = (int *)(iVar21 + iVar12);
            local_2c = (int *)(iVar12 + iVar9);
            local_38 = 0;
            iVar12 = 3 - local_7c;
            do {
              piVar10 = (int *)*local_34;
              if (((piVar10 != (int *)0x0) && ((*(byte *)(piVar10 + 5) & 1) != 0)) &&
                 (((*(byte *)(*local_2c + 0x14) & 1) != 0 &&
                  ((piVar10 != (int *)*piVar20 && (*piVar22 == *local_2c)))))) {
                if ((*(int *)(iVar21 + iVar25) != *local_30) &&
                   (((*(int *)(*(int *)(*piVar22 + 0x88) + 8) != 0x14 ||
                     (*(int *)(iVar21 + iVar25) == 3)) || (*local_30 == 3)))) {
                  bVar7 = 0;
                  for (local_70 = 1; iVar13 = (**(code **)(*piVar10 + 0x14))(piVar10),
                      local_70 <= iVar13; local_70 = local_70 + 1) {
                    iVar13 = FUN_0010b180(*local_34,local_70);
                    if (param_1 == iVar13) {
                      iVar13 = FUN_0010b0f4(*local_34,local_70);
                      local_b4 = *(int *)(iVar13 + 0x10);
                      piVar10 = (int *)*local_34;
                      bVar7 = (byte)((uint)piVar10[local_70 * 6 + 0x28] >> 1) & 1;
                      if ((local_b4 == local_b0) && (bVar23 = local_75, local_75 == bVar7))
                      goto LAB_0016cdb7;
                    }
                    else {
                      piVar10 = (int *)*local_34;
                    }
                  }
                  local_70 = 0;
                  bVar23 = bVar7;
LAB_0016cdb7:
                  if ((local_b4 == local_b0) && (local_75 == bVar23)) {
                    *(int *)(param_2 + 0x1cc) = *(int *)(param_2 + 0x1cc) + 1;
                    if (*piVar20 != *piVar22) {
                      piVar10 = *(int **)(*piVar20 + 0x10);
                      if (*piVar10 == 0) {
                        piVar10 = (int *)FUN_001a7f7c(piVar10,0);
                      }
                      else {
                        if (piVar10[1] == 0) {
                          *(undefined4 *)piVar10[2] = 0;
                          piVar10[1] = 1;
                        }
                        piVar10 = (int *)piVar10[2];
                      }
                      piVar10 = (int *)*piVar10;
                      uVar14 = FUN_0010b180(*piVar20,iVar12);
                      iVar13 = FUN_0010b0f4(*piVar20,iVar12);
                      iVar13 = *(int *)(iVar13 + 0x10);
                      piVar16 = (int *)*piVar20;
                      uVar18 = piVar16[iVar12 * 6 + 0x28];
                      bVar7 = *(byte *)(piVar16 + local_7c * 6 + 0x28);
                      (**(code **)(*piVar16 + 0xc))(piVar16,1,*(undefined4 *)(param_2 + 8));
                      local_c8 = piVar10 + 0x29;
                      local_cc = 0x98;
                      for (iVar27 = 1; iVar15 = (**(code **)(*piVar10 + 0x14))(piVar10),
                          iVar27 <= iVar15; iVar27 = iVar27 + 1) {
                        iVar15 = FUN_0010b180(piVar10,iVar27);
                        if (iVar15 == *piVar20) {
                          FUN_0010ba02(piVar10,iVar27,uVar14,1,*(undefined4 *)(param_2 + 8));
                          if (iVar27 == 0) {
                            piVar10[0x27] = iVar13;
                          }
                          else {
                            iVar15 = FUN_0010b0f4(piVar10,iVar27);
                            *(int *)(iVar15 + 0x10) = iVar13;
                          }
                          FUN_00109c0e(local_c8,2,(byte)(uVar18 >> 1) & 1);
                          FUN_00109c0e(local_c8,1,
                                       (bool)(*(byte *)(local_cc + 0x20 + (int)piVar10) & 1) !=
                                       ((bVar7 & 1) != ((byte)uVar18 & 1)));
                        }
                        local_cc = local_cc + 0x18;
                        local_c8 = local_c8 + 6;
                      }
                    }
                    if (*local_34 != *local_2c) {
                      piVar10 = *(int **)(*local_34 + 0x10);
                      if (*piVar10 == 0) {
                        piVar10 = (int *)FUN_001a7f7c(piVar10,0);
                      }
                      else {
                        if (piVar10[1] == 0) {
                          *(undefined4 *)piVar10[2] = 0;
                          piVar10[1] = 1;
                        }
                        piVar10 = (int *)piVar10[2];
                      }
                      piVar10 = (int *)*piVar10;
                      iVar27 = 3 - local_70;
                      uVar14 = FUN_0010b180(*local_34,iVar27);
                      iVar13 = FUN_0010b0f4(*local_34,iVar27);
                      iVar13 = *(int *)(iVar13 + 0x10);
                      piVar16 = (int *)*local_34;
                      uVar18 = piVar16[iVar27 * 6 + 0x28];
                      bVar7 = *(byte *)(piVar16 + local_70 * 6 + 0x28);
                      (**(code **)(*piVar16 + 0xc))(piVar16,1,*(undefined4 *)(param_2 + 8));
                      local_c0 = piVar10 + 0x29;
                      local_c4 = 0x98;
                      for (iVar27 = 1; iVar15 = (**(code **)(*piVar10 + 0x14))(piVar10),
                          iVar27 <= iVar15; iVar27 = iVar27 + 1) {
                        iVar15 = FUN_0010b180(piVar10,iVar27);
                        if (iVar15 == *local_34) {
                          FUN_0010ba02(piVar10,iVar27,uVar14,1,*(undefined4 *)(param_2 + 8));
                          if (iVar27 == 0) {
                            piVar10[0x27] = iVar13;
                          }
                          else {
                            iVar15 = FUN_0010b0f4(piVar10,iVar27);
                            *(int *)(iVar15 + 0x10) = iVar13;
                          }
                          FUN_00109c0e(local_c0,2,(byte)(uVar18 >> 1) & 1);
                          FUN_00109c0e(local_c0,1,
                                       (bool)(*(byte *)(local_c4 + 0x20 + (int)piVar10) & 1) !=
                                       ((bVar7 & 1) != ((byte)uVar18 & 1)));
                        }
                        local_c4 = local_c4 + 0x18;
                        local_c0 = local_c0 + 6;
                      }
                    }
                    piVar10 = (int *)FUN_0010a17a(0x13,*(undefined4 *)(param_2 + 8));
                    FUN_0010ba02(piVar10,1,param_1,1,*(undefined4 *)(param_2 + 8));
                    iVar13 = FUN_0010b0f4(piVar10,1);
                    *(int *)(iVar13 + 0x10) = local_b0;
                    FUN_00109c0e(piVar10 + 0x29,2,local_75);
                    piVar10[0x25] = piVar10[0x53];
                    piVar10[0x26] = 0;
                    iVar13 = FUN_0010b0f4(*local_2c,0);
                    piVar10[0x27] = *(int *)(iVar13 + 0x10);
                    *(undefined1 *)(piVar10 + 0x48) = *(undefined1 *)(*local_2c + 0x120);
                    piVar10[0x49] = *(int *)(*local_2c + 0x124);
                    iVar13 = *local_2c;
                    local_50 = *(int *)(*(int *)(iVar13 + 0x10) + 4) - 1;
                    if (-1 < (int)local_50) {
                      local_40 = local_50 * 4;
                      do {
                        puVar2 = *(uint **)(iVar13 + 0x10);
                        if (local_50 < *puVar2) {
                          uVar18 = puVar2[1];
                          if (uVar18 <= local_50) {
                            _memset((void *)(puVar2[2] + uVar18 * 4),0,(local_50 - uVar18) * 4 + 4);
                            puVar2[1] = local_50 + 1;
                          }
                          piVar16 = (int *)(local_40 + puVar2[2]);
                        }
                        else {
                          piVar16 = (int *)FUN_001a7f7c(puVar2,local_50);
                        }
                        iVar13 = *piVar16;
                        iVar27 = *(int *)(iVar13 + 0x84);
                        iVar15 = iVar27;
                        if ((*(byte *)(iVar13 + 0x15) & 2) == 0) {
LAB_0016d116:
                          if (0 < iVar15) {
                            local_4c = 1;
                            do {
                              iVar27 = FUN_0010b180(iVar13,local_4c);
                              if (iVar27 == *local_2c) {
                                FUN_0010ba02(iVar13,local_4c,piVar10,1,*(undefined4 *)(param_2 + 8))
                                ;
                                break;
                              }
                              local_4c = local_4c + 1;
                            } while (local_4c <= iVar15);
                          }
                        }
                        else {
                          iVar15 = iVar27 + -1;
                          iVar27 = FUN_0010b180(iVar13,iVar27);
                          if (iVar27 != *local_2c) goto LAB_0016d116;
                          FUN_0010c18e(iVar13,piVar10,1,*(undefined4 *)(param_2 + 8));
                        }
                        local_50 = local_50 - 1;
                        local_40 = local_40 + -4;
                        if (local_50 == 0xffffffff) break;
                        iVar13 = *local_2c;
                      } while( true );
                    }
                    iVar13 = FUN_0010b0f4(piVar10,0);
                    uVar14 = FUN_000f5fea(*(undefined4 *)(iVar13 + 0x10));
                    uVar14 = FUN_000f5b96(DAT_001cc5a0,uVar14);
                    iVar13 = FUN_0010b0f4(piVar10,2);
                    *(undefined4 *)(iVar13 + 0x10) = uVar14;
                    FUN_000e9596(*(undefined4 *)(*local_2c + 0x158),*local_2c,piVar10);
                    if (*piVar20 == *piVar22) {
                      piVar16 = (int *)*local_2c;
LAB_0016d5da:
                      (**(code **)(*piVar16 + 0xc))(piVar16,1,*(undefined4 *)(param_2 + 8));
                      iVar13 = FUN_0010a17a(0x12,*(undefined4 *)(param_2 + 8));
                      uVar14 = *(undefined4 *)(param_2 + 8);
                      uVar19 = FUN_0010b180(*local_2c,3);
                      FUN_0010ba02(iVar13,2,uVar19,1,uVar14);
                      uVar14 = *(undefined4 *)(param_2 + 8);
                      uVar19 = FUN_0010b0f4(*local_2c,3);
                      FUN_0010bc9c(iVar13,2,uVar19,uVar14);
                      if (((*piVar20 == *piVar22) && (local_7c == 1)) ||
                         ((*local_34 == *local_2c && (local_70 == 1)))) {
                        uVar14 = *(undefined4 *)(param_2 + 8);
                        uVar19 = FUN_0010b180(*local_2c,2);
                        FUN_0010ba02(iVar13,1,uVar19,1,uVar14);
                        uVar14 = *(undefined4 *)(param_2 + 8);
                        uVar19 = 2;
                      }
                      else {
                        uVar14 = *(undefined4 *)(param_2 + 8);
                        uVar19 = FUN_0010b180(*local_2c,1);
                        FUN_0010ba02(iVar13,1,uVar19,1,uVar14);
                        uVar14 = *(undefined4 *)(param_2 + 8);
                        uVar19 = 1;
                      }
                      uVar19 = FUN_0010b0f4(*local_2c,uVar19);
                      FUN_0010bc9c(iVar13,1,uVar19,uVar14);
                      FUN_00109c0e(iVar13 + 0xa4,1,
                                   (*(byte *)(*local_2c + 0xd0) & 1) !=
                                   (*(byte *)(*local_2c + 0xb8) & 1));
                      *(undefined4 *)(iVar13 + 0x94) = *(undefined4 *)(iVar13 + 0x14c);
                      *(undefined4 *)(iVar13 + 0x98) = 0;
                      iVar27 = FUN_0010b0f4(*local_2c,0);
                      *(undefined4 *)(iVar13 + 0x9c) = *(undefined4 *)(iVar27 + 0x10);
                      FUN_0010ba02(piVar10,2,iVar13,1,*(undefined4 *)(param_2 + 8));
                      FUN_000e956e(piVar10[0x56],piVar10,iVar13);
                    }
                    else {
                      piVar16 = (int *)*local_2c;
                      if ((int *)*local_34 == piVar16) goto LAB_0016d5da;
                      FUN_0010ba02(piVar10,2,piVar16,1,*(undefined4 *)(param_2 + 8));
                      *(undefined1 *)(*local_2c + 0x120) = 0;
                      *(undefined4 *)(*local_2c + 0x124) = 0;
                    }
                    *local_34 = (int)piVar10;
                    *local_2c = 0;
                    *local_30 = 0;
                    while (piVar16 = piVar10, *(int *)(piVar16[0x22] + 8) == 0x13) {
                      uVar18 = piVar16[5];
                      if ((uVar18 & 0x200) != 0) goto LAB_0016d585;
                      cVar6 = FUN_0010a62e(piVar16,param_2);
                      if ((cVar6 == '\0') || ((char)piVar16[0x48] != '\0')) break;
                      piVar10 = (int *)piVar16[4];
                      if (*piVar10 == 0) {
                        piVar10 = (int *)FUN_001a7f7c(piVar10,0);
                      }
                      else {
                        if (piVar10[1] == 0) {
                          *(undefined4 *)piVar10[2] = 0;
                          piVar10[1] = 1;
                        }
                        piVar10 = (int *)piVar10[2];
                      }
                      piVar10 = (int *)*piVar10;
                      bVar5 = false;
                      local_bc = 0x98;
                      for (local_44 = 1; iVar13 = (**(code **)(*piVar10 + 0x14))(piVar10),
                          local_44 <= iVar13; local_44 = local_44 + 1) {
                        piVar17 = (int *)FUN_0010b180(piVar10,local_44);
                        if (piVar17 == piVar16) {
                          iVar13 = FUN_0010b0f4(piVar10,local_44);
                          cVar6 = FUN_000f59e0(*(undefined4 *)(iVar13 + 0x10));
                          if ((cVar6 == '\0') ||
                             ((*(byte *)(local_bc + 0x20 + (int)piVar10) & 2) != 0)) {
                            bVar5 = true;
                          }
                          *local_30 = local_44;
                        }
                        local_bc = local_bc + 0x18;
                      }
                      if (bVar5) break;
                    }
                    uVar18 = piVar16[5];
LAB_0016d585:
                    if (((uVar18 & 0x200) == 0) &&
                       ((*(int *)(piVar16[0x22] + 8) == 0x12 ||
                        (*(int *)(piVar16[0x22] + 8) == 0x14)))) {
                      *local_2c = (int)piVar16;
                    }
                    else {
                      *local_34 = 0;
                    }
                    if ((*(byte *)(*piVar20 + 0x14) & 1) == 0) {
                      local_85 = 1;
                      break;
                    }
                    local_85 = 1;
                  }
                }
              }
              local_38 = local_38 + 1;
              local_34 = local_34 + 1;
              local_30 = local_30 + 1;
              local_2c = local_2c + 1;
            } while (uVar1 - iVar11 != local_38);
          }
        }
        iVar26 = iVar26 + 1;
        if ((int)uVar1 <= iVar26) {
          FUN_001a7aba(*(undefined4 *)(*(int *)(param_2 + 8) + 0xbc),iVar21);
          FUN_001a7aba(*(undefined4 *)(*(int *)(param_2 + 8) + 0xbc),iVar9);
          FUN_001a7aba(*(undefined4 *)(*(int *)(param_2 + 8) + 0xbc),iVar8);
          return local_85;
        }
      } while( true );
    }
  }
  return 0;
}

/* FUN_0016d834 @ 0x16d834 (1043 bytes) */
int FUN_0016d834(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  uint local_40;
  uint local_34;
  int *local_30;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x31) {
    iVar4 = FUN_0010b0f4(param_1,1);
    cVar3 = FUN_000f59e0(*(undefined4 *)(iVar4 + 0x10));
    if (cVar3 == '\0') {
      piVar5 = (int *)FUN_0010b180(param_1,1);
      cVar3 = (**(code **)(*piVar5 + 0x5c))(piVar5);
      if (((cVar3 == '\0') && ((*(byte *)((int)piVar5 + 0x15) & 2) == 0)) &&
         ((cVar3 = FUN_001195a6(*(undefined4 *)(param_2 + 8),piVar5), cVar3 != '\0' ||
          (cVar3 = FUN_00119104(*(undefined4 *)(piVar5[0x22] + 8),*(undefined4 *)(param_2 + 8)),
          cVar3 != '\0')))) {
        iVar4 = FUN_0010b0f4(param_1,1);
        local_20[0] = *(undefined4 *)(iVar4 + 0x10);
        uVar9 = 0;
        do {
          iVar4 = FUN_0010b0f4(param_1,0);
          if ((((*(char *)(uVar9 + 0x10 + iVar4) != '\x01') &&
               (bVar2 = *(byte *)((int)local_20 + uVar9), bVar2 != 4)) && (uVar9 != bVar2)) &&
             (iVar4 = FUN_0010b0f4(piVar5,0), *(char *)(bVar2 + 0x10 + iVar4) != '\x01')) {
            return;
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 != 4);
        puVar10 = (uint *)piVar5[4];
        if (puVar10[1] != 0) {
          uVar9 = 0;
          do {
            if (uVar9 < *puVar10) {
              uVar1 = puVar10[1];
              if (uVar1 <= uVar9) {
                _memset((void *)(puVar10[2] + uVar1 * 4),0,(uVar9 - uVar1) * 4 + 4);
                puVar10[1] = uVar9 + 1;
              }
              piVar6 = (int *)(puVar10[2] + uVar9 * 4);
            }
            else {
              piVar6 = (int *)FUN_001a7f7c(puVar10,uVar9);
            }
            iVar4 = *piVar6;
            if (((*(byte *)(iVar4 + 0x15) & 2) != 0) &&
               (piVar6 = (int *)FUN_0010b180(iVar4,*(undefined4 *)(iVar4 + 0x84)), piVar5 == piVar6)
               ) {
              return;
            }
            uVar9 = uVar9 + 1;
            puVar10 = (uint *)piVar5[4];
          } while (uVar9 < puVar10[1]);
        }
        *(int *)(param_2 + 0x164) = *(int *)(param_2 + 0x164) + 1;
        local_24 = DAT_001cc5a4;
        FUN_0010b0f4(piVar5,0);
        uVar9 = 0;
        local_30 = piVar5;
        do {
          iVar4 = FUN_0010b0f4(param_1,0);
          if (*(char *)(uVar9 + 0x10 + iVar4) != '\x01') {
            bVar2 = *(byte *)((int)local_20 + uVar9);
            if ((bVar2 != 4) && (bVar2 != uVar9)) {
              cVar3 = FUN_001195a6(*(undefined4 *)(param_2 + 8),piVar5);
              if (cVar3 != '\0') {
                for (iVar4 = 1; iVar11 = (**(code **)(*piVar5 + 0x14))(piVar5), iVar4 <= iVar11;
                    iVar4 = iVar4 + 1) {
                  iVar11 = FUN_0010b0f4(piVar5,iVar4);
                  (**(code **)(*piVar5 + 0x88))
                            (piVar5,iVar4,uVar9,*(undefined1 *)(bVar2 + 0x10 + iVar11));
                }
              }
              iVar4 = FUN_0010b0f4(piVar5,0);
              if (*(char *)(uVar9 + 0x10 + iVar4) != '\0') {
                *(undefined1 *)(local_30 + 0x27) = 0;
              }
              *(byte *)((int)local_20 + (uVar9 - 4)) = bVar2;
            }
          }
          uVar9 = uVar9 + 1;
          local_30 = (int *)((int)local_30 + 1);
        } while (uVar9 != 4);
        puVar10 = (uint *)piVar5[4];
        if (puVar10[1] != 0) {
          local_40 = 0;
          do {
            if (local_40 < *puVar10) {
              uVar9 = puVar10[1];
              if (uVar9 <= local_40) {
                _memset((void *)(puVar10[2] + uVar9 * 4),0,(local_40 - uVar9) * 4 + 4);
                puVar10[1] = local_40 + 1;
              }
              puVar8 = (undefined4 *)(puVar10[2] + local_40 * 4);
            }
            else {
              puVar8 = (undefined4 *)FUN_001a7f7c(puVar10,local_40);
            }
            local_40 = local_40 + 1;
            piVar6 = (int *)*puVar8;
            iVar11 = 1;
            iVar4 = (**(code **)(*piVar6 + 0x14))(piVar6);
            if (0 < iVar4) {
              do {
                piVar7 = (int *)FUN_0010b180(piVar6,iVar11);
                if (piVar5 == piVar7) {
                  local_34 = 0;
                  iVar4 = FUN_0010b0f4(piVar6,iVar11);
                  uVar9 = (uint)*(byte *)(iVar4 + 0x10);
                  if (uVar9 == (local_24 & 0xff)) goto LAB_0016db72;
                  do {
                    iVar4 = 3;
                    do {
                      iVar4 = iVar4 + -1;
                    } while (iVar4 != 0);
                    while( true ) {
                      uVar1 = local_34 + 1;
                      if (uVar1 == 4) goto LAB_0016daf7;
                      iVar4 = FUN_0010b0f4(piVar6,iVar11);
                      uVar9 = (uint)*(byte *)(local_34 + 0x11 + iVar4);
                      iVar4 = local_34 - 3;
                      local_34 = uVar1;
                      if (uVar9 != *(byte *)((int)local_20 + iVar4)) break;
LAB_0016db72:
                      if (uVar9 == local_34) {
                        (**(code **)(*piVar6 + 0x88))(piVar6,iVar11,local_34,local_34);
                      }
                      else {
                        (**(code **)(*piVar6 + 0x88))(piVar6,iVar11,local_34,local_34);
                      }
                    }
                  } while( true );
                }
LAB_0016daf7:
                iVar11 = iVar11 + 1;
                iVar4 = (**(code **)(*piVar6 + 0x14))(piVar6);
              } while (iVar11 <= iVar4);
            }
            puVar10 = (uint *)piVar5[4];
          } while (local_40 < puVar10[1]);
        }
      }
    }
  }
  return;
}

/* FUN_0016dc48 @ 0x16dc48 (1563 bytes) */
int FUN_0016dc48(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
  int param_4;
{
  byte bVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_40;
  int local_3c;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
  uVar3 = *(undefined4 *)(param_4 + 8);
  iVar10 = *(int *)(param_3[0x22] + 8);
  iVar8 = FUN_0010b0f4(param_3,0);
  local_10 = *(int *)(iVar8 + 0x10);
  if ((iVar10 - 0x1cU < 2) && (cVar7 = FUN_000f5f28(local_10), cVar7 != '\0')) {
    uVar9 = 0;
    local_78 = 1;
    while (iVar10 = (**(code **)(*param_3 + 0x14))(param_3), local_78 <= iVar10) {
      iVar10 = FUN_0010b180(param_3,local_78);
      if ((((*(int *)(*(int *)(iVar10 + 0x88) + 8) == 0x13) &&
           (cVar7 = FUN_0010a62e(iVar10,param_4), cVar7 != '\0')) && (*(int *)(iVar10 + 0x124) == 0)
          ) && ((*(char *)(iVar10 + 0x120) == '\0' && ((*(byte *)(iVar10 + 0x15) & 2) == 0)))) {
        iVar8 = FUN_0010b0f4(iVar10,1);
        uVar4 = *(undefined4 *)(iVar8 + 0x10);
        iVar8 = FUN_0010b0f4(iVar10,2);
        uVar5 = *(undefined4 *)(iVar8 + 0x10);
        cVar7 = FUN_000f5672(uVar4);
        if ((cVar7 != '\0') && (cVar7 = FUN_000f5672(uVar5), cVar7 != '\0')) goto LAB_0016dce1;
        cVar7 = FUN_000f5672(uVar4);
        if (cVar7 == '\0') {
          cVar7 = FUN_000f5672(uVar5);
          if (cVar7 == '\0') goto LAB_0016dce1;
          iVar8 = FUN_0010b180(iVar10,2);
          local_74 = FUN_0010b180(iVar10,1);
          local_14 = uVar5;
          local_70 = 2;
          local_6c = 1;
        }
        else {
          iVar8 = FUN_0010b180(iVar10,1);
          local_14 = uVar4;
          local_74 = FUN_0010b180(iVar10,2);
          local_70 = 1;
          local_6c = 2;
        }
        iVar11 = 0;
        do {
          if (*(char *)((int)&local_14 + iVar11) != '\x04') {
            uVar2 = *(undefined1 *)((int)&local_14 + iVar11);
            goto LAB_0016ddc7;
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 != 4);
        uVar2 = 0;
LAB_0016ddc7:
        iVar11 = FUN_0010b0f4(iVar10,local_6c);
        local_18 = *(undefined4 *)(iVar11 + 0x10);
        iVar11 = FUN_0010b0f4(param_3,local_78);
        local_1c = *(undefined4 *)(iVar11 + 0x10);
        *(int *)(param_4 + 0x284) = *(int *)(param_4 + 0x284) + 1;
        if (*(int *)(param_4 + 0x46c) < *(int *)(local_74 + 0x160)) {
          *(int *)(local_74 + 0x160) = *(int *)(local_74 + 0x160) + 1;
        }
        else {
          *(int *)(local_74 + 0x160) = *(int *)(param_4 + 0x46c) + 1;
        }
        if (*(int *)(param_4 + 0x46c) < *(int *)(iVar8 + 0x160)) {
          *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
        }
        else {
          *(int *)(iVar8 + 0x160) = *(int *)(param_4 + 0x46c) + 1;
        }
        local_40 = 0;
        local_3c = 0;
        local_2c = 0;
        if ((*(byte *)((int)param_3 + 0x15) & 2) != 0) {
          FUN_0010a980(param_3,&local_40);
          FUN_0010ba02(param_3,param_3[0x21],0,0,uVar3);
          param_3[0x21] = param_3[0x21] + -1;
          param_3[5] = param_3[5] & 0xfffffdff;
        }
        local_28 = 0;
        local_24 = 0;
        local_20 = 0;
        FUN_00109d1c(param_3,&local_28,0xffffffff);
        iVar8 = param_3[0x49];
        iVar6 = param_3[0x48];
        iVar11 = param_3[2];
        param_3[0x49] = 0;
        *(undefined1 *)(param_3 + 0x48) = 0;
        FUN_001a7d72(param_3);
        iVar12 = FUN_0010a1c2(param_3,uVar3,0);
        *(undefined4 *)(iVar12 + 0x94) = *(undefined4 *)(iVar12 + 0x14c);
        *(undefined4 *)(iVar12 + 0x98) = 0;
        piVar13 = (int *)FUN_00109cd4(iVar10,param_3,uVar3,0);
        piVar13[0x25] = piVar13[0x53];
        piVar13[0x26] = 0;
        FUN_0010ba02(piVar13,local_6c,iVar12,0,uVar3);
        FUN_0010b3fe(iVar10,uVar3);
        FUN_000e956e(*(undefined4 *)(iVar11 + 0x158),iVar11,iVar12);
        FUN_000e9596(*(undefined4 *)(iVar12 + 0x158),iVar12,piVar13);
        if ((local_78 == 1) && (iVar11 = FUN_0010b180(iVar12,2), iVar10 == iVar11)) {
          FUN_0010ba02(iVar12,2,local_74,0,uVar3);
        }
        FUN_0010ba02(iVar12,local_78,local_74,0,uVar3);
        iVar10 = 1;
        do {
          bVar1 = *(byte *)((int)&local_20 + iVar10 + 3);
          if (bVar1 != 4) {
            *(undefined1 *)((int)&local_20 + iVar10 + 3) =
                 *(undefined1 *)((int)&local_18 + (uint)bVar1);
          }
          uVar9 = local_1c;
          iVar10 = iVar10 + 1;
        } while (iVar10 != 5);
        if (local_78 == 0) {
          *(undefined4 *)(iVar12 + 0x9c) = local_1c;
        }
        else {
          iVar10 = FUN_0010b0f4(iVar12,local_78);
          *(undefined4 *)(iVar10 + 0x10) = uVar9;
        }
        *(int *)(iVar12 + 0x160) = *(int *)(param_4 + 0x46c) + 1;
        if (local_3c != 0) {
          FUN_0010c568(piVar13,&local_40,0,uVar3);
        }
        FUN_00109d48(piVar13,&local_28);
        *(char *)(piVar13 + 0x48) = (char)iVar6;
        piVar13[0x49] = iVar8;
        piVar13[0x27] = local_10;
        iVar10 = 0;
        do {
          if (*(char *)((int)&local_10 + iVar10) == '\x01') {
            (**(code **)(*piVar13 + 0x88))(piVar13,1,iVar10,4);
            (**(code **)(*piVar13 + 0x88))(piVar13,2,iVar10,4);
          }
          else {
            (**(code **)(*piVar13 + 0x88))(piVar13,local_70,iVar10,uVar2);
            (**(code **)(*piVar13 + 0x88))(piVar13,local_6c,iVar10,iVar10);
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 != 4);
        uVar9 = 1;
        local_78 = local_78 + 1;
      }
      else {
LAB_0016dce1:
        local_78 = local_78 + 1;
      }
    }
  }
  else {
    uVar9 = 0;
  }
  return uVar9;
}

/* FUN_0016e264 @ 0x16e264 (139 bytes) */
int FUN_0016e264(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    while ((((*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x3a ||
             (*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x3b)) && ((*(byte *)(iVar2 + 0xb8) & 1) == 0)
            ) && (*(char *)(iVar2 + 0x120) == '\0'))) {
      iVar1 = FUN_0010b0f4(iVar2,0);
      iVar1 = FUN_000f5ede(*(undefined4 *)(iVar1 + 0x10));
      if (iVar1 < 0) {
        return 0;
      }
      if (iVar1 == param_2) {
        *param_1 = iVar2;
        return 1;
      }
      if ((*(byte *)(iVar2 + 0x15) & 2) == 0) {
        return 0;
      }
      iVar2 = FUN_0010b180(iVar2,*(undefined4 *)(iVar2 + 0x84));
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  return 0;
}

/* FUN_0016e2f0 @ 0x16e2f0 (1032 bytes) */
int FUN_0016e2f0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  int *param_4;
  uint *param_5;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  float fVar8;
  undefined4 local_30;
  undefined1 local_2c [4];
  float local_28;
  int *local_14;
  int *local_10;
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x37) {
    iVar2 = FUN_0010b0f4(param_1,0);
    iVar2 = FUN_000f5ede(*(undefined4 *)(iVar2 + 0x10));
    if ((((-1 < iVar2) && (local_10 = (int *)FUN_0010b180(param_1,1), (char)local_10[0x48] == '\0'))
        && ((*(uint *)(param_1 + 0xb8) & 1) == 0)) && ((*(uint *)(param_1 + 0xb8) & 2) == 0)) {
      iVar2 = FUN_0010b0f4(param_1,1);
      uVar7 = (uint)*(byte *)(iVar2 + 0x13);
      iVar2 = *(int *)(local_10[0x22] + 8);
      cVar1 = ((int (*)())FUN_0016e264)(&local_10,uVar7);
      if (cVar1 == '\0') {
        cVar1 = (**(code **)(*local_10 + 100))(local_10);
        if (cVar1 == '\0') {
          if (iVar2 != 0x13) {
            if ((iVar2 != 0x12) && (iVar2 != 0x9b)) {
              return 0;
            }
            local_14 = (int *)FUN_0010b180(local_10,1);
            piVar4 = (int *)FUN_0010b180(local_10,2);
            if (piVar4 != local_14) {
              return 0;
            }
            if ((local_10[0x2e] & 1U) != 0) {
              return 0;
            }
            if ((local_10[0x2e] & 2U) != 0) {
              return 0;
            }
            if ((local_10[0x34] & 1U) != 0) {
              return 0;
            }
            if ((local_10[0x34] & 2U) != 0) {
              return 0;
            }
            iVar2 = FUN_0010b0f4(local_10,2);
            iVar2 = *(int *)(iVar2 + 0x10);
            iVar5 = FUN_0010b0f4(local_10,1);
            if (*(int *)(iVar5 + 0x10) != iVar2) {
              return 0;
            }
            iVar2 = FUN_0010b0f4(local_10,1);
            cVar1 = ((int (*)())FUN_0016e264)(&local_14,*(undefined1 *)(uVar7 + 0x10 + iVar2));
            if (cVar1 == '\0') {
              return 0;
            }
            *param_4 = 2;
            *param_3 = 0;
            uVar3 = FUN_0010b180(local_14,1);
            *param_2 = uVar3;
            iVar2 = FUN_0010b0f4(local_14,1);
            *param_5 = (uint)*(byte *)(iVar2 + 0x13);
            return 1;
          }
          if ((local_10[0x2e] & 1U) != 0) {
            return 0;
          }
          if ((local_10[0x2e] & 2U) != 0) {
            return 0;
          }
          if ((local_10[0x34] & 1U) != 0) {
            return 0;
          }
          if ((local_10[0x34] & 2U) != 0) {
            return 0;
          }
          local_14 = (int *)FUN_0010b180(local_10,1);
          piVar4 = (int *)FUN_0010b180(local_10,2);
          cVar1 = (**(code **)(*piVar4 + 0x48))(piVar4);
          if (cVar1 == '\0') {
            cVar1 = (**(code **)(*local_14 + 0x48))(local_14);
            if (cVar1 == '\0') {
              return 0;
            }
            uVar3 = 2;
            local_30 = 1;
            piVar6 = local_14;
            local_14 = piVar4;
          }
          else {
            uVar3 = 1;
            local_30 = 2;
            piVar6 = piVar4;
          }
          iVar2 = FUN_0010b0f4(local_10,uVar3);
          cVar1 = ((int (*)())FUN_0016e264)(&local_14,*(undefined1 *)(uVar7 + 0x10 + iVar2));
          if (cVar1 == '\0') {
            return 0;
          }
          iVar2 = FUN_0010b0f4(local_10,0);
          cVar1 = FUN_000f7e7e(local_10,local_30,*(undefined4 *)(iVar2 + 0x10),local_2c);
          if (cVar1 == '\0') {
            *param_3 = piVar6;
          }
          else {
            fVar8 = (float)(int)local_28;
            if (local_28 != fVar8) {
              return 0;
            }
            if (NAN(local_28) || NAN(fVar8)) {
              return 0;
            }
            *param_4 = (int)local_28;
            *param_3 = 0;
          }
        }
        else {
          local_14 = (int *)FUN_0010b180(local_10,1);
          if ((local_10[0x2e] & 1U) != 0) {
            return 0;
          }
          if ((local_10[0x2e] & 2U) != 0) {
            return 0;
          }
          cVar1 = ((int (*)())FUN_0016e264)(&local_14,uVar7);
          if (cVar1 == '\0') {
            return 0;
          }
          *param_4 = 1 << ((char)local_14[0x49] + (char)local_10[0x49] & 0x1fU);
          *param_3 = 0;
        }
        uVar3 = FUN_0010b180(local_14,1);
        *param_2 = uVar3;
        piVar4 = local_14;
      }
      else {
        *param_4 = 1 << ((byte)local_10[0x49] & 0x1f);
        *param_3 = 0;
        uVar3 = FUN_0010b180(local_10,1);
        *param_2 = uVar3;
        piVar4 = local_10;
      }
      iVar2 = FUN_0010b0f4(piVar4,1);
      *param_5 = (uint)*(byte *)(iVar2 + 0x13);
      return 1;
    }
  }
  return 0;
}

/* FUN_0016e6f8 @ 0x16e6f8 (2577 bytes) */
int FUN_0016e6f8(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int local_90;
  int local_88;
  int local_84;
  int *local_80;
  int *local_7c;
  int local_74;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44 [4];
  int local_40;
  int *local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int *local_24;
  undefined1 local_1d [13];
  
  cVar3 = FUN_000e1402(*(undefined4 *)(param_4 + 8),0x1e);
  if ((cVar3 == '\0') || ((*(byte *)(param_3 + 0x16) & 0x40) != 0)) {
    return 0;
  }
  local_24 = (int *)0x0;
  local_28 = 0;
  local_30 = 0;
  local_34 = 0;
  local_38 = 0;
  local_54 = 0;
  local_40 = 0;
  local_48 = 4;
  local_4c = 4;
  cVar3 = ((int (*)())FUN_0016e2f0)(param_3,&local_3c,&local_2c,&local_38,local_44);
  if (cVar3 == '\0') {
    return 0;
  }
  if (local_38 < 0) {
    return 0;
  }
  if (2 < local_38) {
    return 0;
  }
  iVar5 = FUN_0010b0f4(param_3,0);
  local_90 = *(int *)(iVar5 + 0x10);
  iVar5 = FUN_0010b0f4(param_3,0);
  iVar5 = FUN_000f5ede(*(undefined4 *)(iVar5 + 0x10));
  if ((*(byte *)(param_3 + 0x15) & 2) == 0) {
    local_7c = (int *)0x0;
  }
  else {
    local_7c = (int *)FUN_0010b180(param_3,*(undefined4 *)(param_3 + 0x84));
  }
  cVar3 = *(char *)(param_3 + 0x120);
  piVar7 = local_7c;
  if (local_7c == (int *)0x0) {
    local_54 = local_38;
    local_40 = local_38;
    local_80 = (int *)0x0;
    local_7c = (int *)0x0;
    local_88 = -1;
    local_84 = -1;
  }
  else {
    cVar4 = FUN_0010a62e(local_7c,param_4);
    if (((((cVar4 == '\0') ||
          (cVar4 = ((int (*)())FUN_0016e2f0)(local_7c,&local_24,&local_30,&local_54,&local_48), cVar4 == '\0'))
         || (local_2c != local_30)) ||
        ((cVar4 = FUN_0015036c(local_3c,local_24), cVar4 == '\0' || (local_38 != local_54)))) ||
       ((char)local_7c[0x48] != cVar3)) {
      local_24 = (int *)0x0;
      local_80 = (int *)0x0;
      local_88 = -1;
      local_84 = -1;
      piVar7 = (int *)0x0;
      local_54 = local_38;
      local_40 = local_38;
    }
    else {
      iVar6 = FUN_0010b0f4(local_7c,0);
      local_90 = FUN_000f5892(local_90,*(undefined4 *)(iVar6 + 0x10));
      iVar6 = FUN_0010b0f4(local_7c,0);
      local_88 = FUN_000f5ede(*(undefined4 *)(iVar6 + 0x10));
      if (((*(byte *)((int)local_7c + 0x15) & 2) == 0) ||
         (piVar8 = (int *)FUN_0010b180(local_7c,local_7c[0x21]), piVar8 == (int *)0x0)) {
        local_40 = local_38;
        local_80 = (int *)0x0;
        local_7c = (int *)0x0;
        local_84 = -1;
      }
      else {
        cVar4 = FUN_0010a62e(piVar8,param_4);
        if ((((cVar4 == '\0') ||
             (cVar4 = ((int (*)())FUN_0016e2f0)(piVar8,&local_28,&local_34,&local_40,&local_4c), cVar4 == '\0'))
            || (local_30 != local_34)) ||
           (((cVar4 = FUN_0015036c(local_24,local_28), cVar4 == '\0' || (local_38 != local_40)) ||
            ((char)piVar8[0x48] != cVar3)))) {
          local_28 = 0;
          local_80 = (int *)0x0;
          local_84 = -1;
          local_7c = piVar8;
          local_40 = local_38;
        }
        else {
          iVar6 = FUN_0010b0f4(piVar8,0);
          local_90 = FUN_000f5892(local_90,*(undefined4 *)(iVar6 + 0x10));
          iVar6 = FUN_0010b0f4(piVar8,0);
          local_84 = FUN_000f5ede(*(undefined4 *)(iVar6 + 0x10));
          local_7c = (int *)0x0;
          local_80 = piVar8;
        }
      }
    }
  }
  if (local_2c != 0) {
    if (piVar7 != (int *)0x0) {
      FUN_000d9384(*(undefined4 *)(*(int *)(param_4 + 8) + 0xdc),*(byte *)(param_4 + 0x30) & 1);
    }
    return 1;
  }
  cVar4 = (**(code **)(*local_3c + 0x5c))(local_3c);
  if (cVar4 != '\0') {
    local_3c[0x27] = local_90;
    local_74 = 1;
    while( true ) {
      iVar6 = (**(code **)(*local_3c + 0x14))(local_3c);
      if (iVar6 < local_74) break;
      iVar6 = FUN_0010b0f4(local_3c,local_74);
      *(undefined4 *)(iVar6 + 0x10) = DAT_001cc5a0;
      (**(code **)(*local_3c + 0x88))(local_3c,local_74,3,4);
      local_74 = local_74 + 1;
    }
  }
  FUN_00150998(param_3,piVar7,local_80,param_4);
  iVar6 = 0;
  if (piVar7 != (int *)0x0) {
    (**(code **)(*piVar7 + 0xc))(piVar7,0,*(undefined4 *)(param_4 + 8));
    if (local_80 == (int *)0x0) {
      iVar6 = 1;
    }
    else {
      (**(code **)(*local_80 + 0xc))(local_80,0,*(undefined4 *)(param_4 + 8));
      iVar6 = 2;
    }
  }
  if (local_38 == 2) {
    iVar6 = iVar6 + -1;
  }
  cVar4 = (**(code **)(*local_3c + 0x5c))(local_3c);
  if (cVar4 == '\0') {
    if (local_24 == (int *)0x0) {
      local_24 = local_3c;
    }
    if (-1 < iVar6) {
      if (0 < iVar6) {
        iVar9 = 0;
        do {
          local_3c[0x58] = local_3c[0x58] + -1;
          iVar9 = iVar9 + 1;
        } while (iVar6 != iVar9);
      }
      goto LAB_0016ead1;
    }
    iVar9 = local_3c[0x58];
    piVar7 = local_3c;
    if (iVar9 <= *(int *)(param_4 + 0x46c)) {
      local_3c[0x58] = *(int *)(param_4 + 0x46c) + 1;
      goto LAB_0016ead1;
    }
  }
  else {
    if (local_24 != (int *)0x0) {
      if ((0 < iVar6) &&
         ((local_28 == 0 ||
          (FUN_0010b3fe(local_28,*(undefined4 *)(param_4 + 8)), iVar6 != 1 && -1 < iVar6 + -1)))) {
        FUN_0010b3fe(local_24,*(undefined4 *)(param_4 + 8));
      }
      goto LAB_0016ead1;
    }
    if (-1 < iVar6) goto LAB_0016ead1;
    iVar6 = *(int *)(param_4 + 0x46c);
    local_24 = (int *)FUN_0010a1c2(local_3c,*(undefined4 *)(param_4 + 8),0);
    local_24[0x25] = local_24[0x53];
    local_24[0x26] = 0x31;
    FUN_000e9596(local_3c[0x56],local_3c,local_24);
    iVar10 = iVar6 + 1;
    local_24[0x58] = iVar10;
    iVar9 = FUN_0010b180(local_24,1);
    if (iVar6 < *(int *)(iVar9 + 0x160)) {
      *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
    }
    else {
      *(int *)(iVar9 + 0x160) = iVar10;
    }
    if (local_24[0x21] < 2) goto LAB_0016ead1;
    piVar7 = (int *)FUN_0010b180(local_24,2);
    iVar9 = piVar7[0x58];
    if (iVar9 <= iVar6) {
      piVar7[0x58] = iVar10;
      goto LAB_0016ead1;
    }
  }
  piVar7[0x58] = iVar9 + 1;
LAB_0016ead1:
  local_50 = DAT_001cc5a4;
  *(undefined1 *)((int)&local_50 + iVar5) = local_44[0];
  if (-1 < local_88) {
    *(char *)((int)&local_50 + local_88) = (char)local_48;
  }
  if (-1 < local_84) {
    *(char *)((int)&local_50 + local_84) = (char)local_4c;
  }
  iVar5 = *(int *)(param_3 + 4);
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  FUN_00109d1c(param_3,&local_60,0xffffffff);
  FUN_001a7d72(param_3);
  local_1d[0] = 0;
  if (local_38 == 0) {
    FUN_0010db52(param_3,0x31,*(undefined4 *)(param_4 + 8));
    *(int *)(param_3 + 0x9c) = local_90;
    FUN_000e9596(*(undefined4 *)(iVar5 + 0x158),iVar5,param_3);
    FUN_000fa0d2(param_3,param_4,1,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
    FUN_00109d48(param_3,&local_60);
    if (local_7c != (int *)0x0) {
      FUN_0010c18e(param_3,local_7c,0,*(undefined4 *)(param_4 + 8));
    }
    FUN_00155bf2(param_1,param_2,param_3,param_4,local_1d);
    return 1;
  }
  if (local_38 == 1) {
    FUN_0010db52(param_3,0x31,*(undefined4 *)(param_4 + 8));
    FUN_00109d48(param_3,&local_60);
    *(int *)(param_3 + 0x9c) = local_90;
    FUN_000e9596(*(undefined4 *)(iVar5 + 0x158),iVar5,param_3);
    FUN_0010ba02(param_3,1,local_3c,0,*(undefined4 *)(param_4 + 8));
    uVar1 = local_50;
    iVar5 = FUN_0010b0f4(param_3,1);
    *(undefined4 *)(iVar5 + 0x10) = uVar1;
    FUN_00109c0e(param_3 + 0xa4,2,1);
    *(undefined4 *)(param_3 + 0x94) = *(undefined4 *)(param_3 + 0x14c);
    *(undefined4 *)(param_3 + 0x98) = 0;
    if (local_7c != (int *)0x0) {
      FUN_0010c18e(param_3,local_7c,0,*(undefined4 *)(param_4 + 8));
    }
    *(char *)(param_3 + 0x120) = cVar3;
    FUN_00155bf2(param_1,param_2,param_3,param_4,local_1d);
    return 1;
  }
  FUN_0010d8fc(param_3,0x13,*(undefined4 *)(param_4 + 8));
  *(int *)(param_3 + 0x9c) = local_90;
  FUN_00109d48(param_3,&local_60);
  FUN_000e9596(*(undefined4 *)(iVar5 + 0x158),iVar5,param_3);
  FUN_0010ba02(param_3,1,local_3c,0,*(undefined4 *)(param_4 + 8));
  FUN_0010ba02(param_3,2,local_24,0,*(undefined4 *)(param_4 + 8));
  uVar1 = local_50;
  iVar5 = FUN_0010b0f4(param_3,1);
  uVar2 = local_50;
  *(undefined4 *)(iVar5 + 0x10) = uVar1;
  iVar5 = FUN_0010b0f4(param_3,2);
  *(undefined4 *)(iVar5 + 0x10) = uVar2;
  if (local_7c != (int *)0x0) {
    FUN_0010c18e(param_3,local_7c,0,*(undefined4 *)(param_4 + 8));
  }
  *(char *)(param_3 + 0x120) = cVar3;
  *(undefined4 *)(param_3 + 0x94) = *(undefined4 *)(param_3 + 0x14c);
  *(undefined4 *)(param_3 + 0x98) = 0;
  return 1;
}

/* FUN_0016f114 @ 0x16f114 (3237 bytes) */
int FUN_0016f114(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  int *piVar17;
  int *piVar18;
  byte bVar19;
  byte bVar20;
  byte bVar21;
  byte bVar22;
  byte bVar23;
  int local_b8;
  int local_b4;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int *local_60;
  undefined4 local_50;
  int local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20 [4];
  
  if ((*(byte *)(param_1 + 0x15) & 2) == 0) {
    return 0;
  }
  iVar9 = FUN_0010b180(param_1,*(undefined4 *)(param_1 + 0x84));
  if (iVar9 == 0) {
    return 0;
  }
  if ((*(byte *)(*(int *)(*(int *)(param_2 + 8) + 0x54) + 9) & 1) == 0) {
    return 0;
  }
  iVar10 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  iVar12 = *(int *)(*(int *)(iVar9 + 0x88) + 8);
  if (iVar10 == 0x12) {
    if (iVar12 != 0x14) {
      return 0;
    }
    local_b4 = param_1;
    local_b8 = iVar9;
  }
  else {
    if (iVar10 != 0x14) {
      return 0;
    }
    if (iVar12 != 0x12) {
      return 0;
    }
    local_b8 = param_1;
    local_b4 = iVar9;
  }
  if (*(char *)(local_b4 + 0x120) != *(char *)(local_b8 + 0x120)) {
    return 0;
  }
  if (*(int *)(local_b4 + 0x124) != *(int *)(local_b8 + 0x124)) {
    return 0;
  }
  iVar10 = FUN_0010b0f4(local_b4,0);
  local_28 = *(undefined4 *)(iVar10 + 0x10);
  iVar10 = FUN_0010b0f4(local_b8,0);
  local_24 = *(undefined4 *)(iVar10 + 0x10);
  iVar10 = 1;
  do {
    if ((*(char *)((int)&local_2c + iVar10 + 3) != '\x01') &&
       (*(char *)((int)&local_28 + iVar10 + 3) != '\x01')) {
      return 0;
    }
    iVar10 = iVar10 + 1;
  } while (iVar10 != 5);
  piVar11 = (int *)FUN_0010b180(local_b4,1);
  cVar3 = (**(code **)(*piVar11 + 0x60))(piVar11);
  if (cVar3 != '\0') {
    return 0;
  }
  piVar11 = (int *)FUN_0010b180(local_b4,2);
  cVar3 = (**(code **)(*piVar11 + 0x60))(piVar11);
  if (cVar3 != '\0') {
    return 0;
  }
  iVar10 = FUN_0014fbbc(local_b4,1);
  iVar12 = FUN_0014fbbc(local_b4,2);
  iVar13 = FUN_0014fbbc(local_b8,1);
  iVar14 = FUN_0014fbbc(local_b8,2);
  iVar15 = FUN_0014fbbc(local_b8,3);
  uVar1 = *(uint *)(local_b8 + 0xb8);
  bVar19 = (byte)uVar1 & 1;
  bVar4 = (byte)(uVar1 >> 1) & 1;
  uVar2 = *(uint *)(local_b8 + 0xd0);
  bVar21 = (byte)uVar2 & 1;
  bVar5 = (byte)(uVar2 >> 1) & 1;
  bVar22 = (byte)*(uint *)(local_b8 + 0xe8) & 1;
  bVar6 = (byte)(*(uint *)(local_b8 + 0xe8) >> 1) & 1;
  bVar20 = (byte)*(uint *)(local_b4 + 0xb8) & 1;
  bVar7 = (byte)(*(uint *)(local_b4 + 0xb8) >> 1) & 1;
  bVar23 = (byte)*(uint *)(local_b4 + 0xd0) & 1;
  bVar8 = (byte)(*(uint *)(local_b4 + 0xd0) >> 1) & 1;
  if ((((iVar10 == iVar13) && (iVar12 == iVar15)) && (bVar4 == bVar7)) &&
     ((bVar6 == bVar8 && (bVar22 == bVar23)))) {
    if ((uVar2 & 1) == 0) {
      if (bVar19 != bVar20) goto LAB_0016f38f;
    }
    else if (bVar19 == bVar20) goto LAB_0016f38f;
    local_94 = 1;
    local_90 = 3;
    local_8c = 2;
    goto LAB_0016f440;
  }
LAB_0016f38f:
  if (((iVar10 == iVar14) && (iVar12 == iVar15)) &&
     ((bVar5 == bVar7 && ((bVar6 == bVar8 && (bVar22 == bVar23)))))) {
    if ((uVar1 & 1) == 0) {
      if (bVar21 == bVar20) {
LAB_0016fa27:
        local_94 = 2;
        local_90 = 3;
        local_8c = 1;
        goto LAB_0016f440;
      }
    }
    else if (bVar21 != bVar20) goto LAB_0016fa27;
  }
  if ((((iVar12 == iVar13) && (iVar10 == iVar15)) && (bVar4 == bVar8)) &&
     ((bVar6 == bVar7 && (bVar22 == bVar20)))) {
    if ((uVar2 & 1) == 0) {
      if (bVar19 == bVar23) {
LAB_0016f9a7:
        local_94 = 3;
        local_90 = 1;
        local_8c = 2;
        goto LAB_0016f440;
      }
    }
    else if (bVar19 != bVar23) goto LAB_0016f9a7;
  }
  if (iVar12 != iVar14) {
    return 0;
  }
  if (iVar10 != iVar15) {
    return 0;
  }
  if (bVar5 != bVar8) {
    return 0;
  }
  if (bVar6 != bVar7) {
    return 0;
  }
  if (bVar22 != bVar20) {
    return 0;
  }
  if ((uVar1 & 1) == 0) {
    if (bVar21 != bVar23) {
      return 0;
    }
  }
  else if (bVar21 == bVar23) {
    return 0;
  }
  local_94 = 3;
  local_90 = 2;
  local_8c = 1;
LAB_0016f440:
  local_50 = 0;
  local_4c = 0;
  local_3c = 0;
  if ((*(byte *)(iVar9 + 0x15) & 2) != 0) {
    FUN_0010a980(iVar9,&local_50);
  }
  iVar12 = *(int *)(local_b4 + 0x160) - *(int *)(param_2 + 0x46c);
  iVar10 = 0;
  if (-1 < iVar12) {
    iVar10 = iVar12;
  }
  if (local_b4 == param_1) {
    iVar12 = FUN_0010b0f4(local_b4,0);
    local_2c = *(int *)(iVar12 + 0x10);
    iVar12 = FUN_0010b0f4(local_b4,1);
    local_30 = *(undefined4 *)(iVar12 + 0x10);
    iVar12 = FUN_0010b0f4(local_b4,2);
    local_34 = *(undefined4 *)(iVar12 + 0x10);
    iVar12 = FUN_0010b0f4(local_b8,local_8c);
    local_38 = *(undefined4 *)(iVar12 + 0x10);
    local_20[0] = local_2c;
    iVar12 = 1;
    do {
      cVar3 = *(char *)((int)&local_28 + iVar12 + 3);
      if (cVar3 != '\x01') {
        *(char *)((int)local_20 + iVar12 + -1) = cVar3;
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 != 5);
    iVar12 = FUN_0010b180(local_b4,1);
    *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + -1;
    iVar12 = FUN_0010b180(local_b4,2);
    *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + -1;
    iVar12 = *(int *)(local_b4 + 4);
    FUN_001a7d72(local_b4);
    piVar11 = (int *)FUN_00109cd4(local_b8,local_b4,*(undefined4 *)(param_2 + 8),0);
    FUN_000e9596(*(undefined4 *)(iVar12 + 0x158),iVar12,piVar11);
    piVar11[0x27] = local_20[0];
    iVar12 = piVar11[0x53];
    iVar13 = FUN_0010b0f4(piVar11,0);
    *(int *)(iVar13 + 8) = iVar12;
    piVar16 = (int *)FUN_0010b180(local_b8,local_94);
    piVar17 = (int *)FUN_0010b180(local_b8,local_90);
    piVar18 = (int *)FUN_0010b180(local_b8,local_8c);
    cVar3 = (**(code **)(*piVar18 + 0x60))(piVar18);
    if (cVar3 == '\0') {
      piVar18 = (int *)FUN_0010f654(0xa2,*(undefined4 *)(param_2 + 8));
      FUN_000e956e(piVar11[0x56],piVar11,piVar18);
      piVar18[0x21] = 1;
      piVar18[0x25] = piVar18[0x53];
      piVar18[0x26] = 0x36;
      piVar18[0x27] = local_20[0];
      iVar12 = FUN_0010b180(piVar11,local_8c);
      FUN_0010ba02(piVar18,1,iVar12,0,*(undefined4 *)(param_2 + 8));
      if (*(int *)(param_2 + 0x46c) < *(int *)(iVar12 + 0x160)) {
        *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + 1;
      }
      else {
        *(int *)(iVar12 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
      }
      local_74 = 0;
      do {
        if (*(char *)((int)local_20 + local_74 + -4) != '\x01') {
          (**(code **)(*piVar18 + 0x88))
                    (piVar18,1,local_74,*(undefined1 *)((int)&local_38 + local_74));
          (**(code **)(*piVar11 + 0x88))(piVar11,local_8c,local_74,local_74);
        }
        local_74 = local_74 + 1;
      } while (local_74 != 4);
      piVar18[0x21] = 2;
      FUN_000fa0d2(piVar18,param_2,2,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
      local_70 = 0;
      do {
        if (*(char *)((int)&local_2c + local_70) != '\x01') {
          (**(code **)(*piVar18 + 0x88))(piVar18,1,local_70,4);
          (**(code **)(*piVar18 + 0x88))(piVar18,2,local_70,local_70);
        }
        local_70 = local_70 + 1;
      } while (local_70 != 4);
      FUN_0010ba02(piVar11,local_8c,piVar18,0,*(undefined4 *)(param_2 + 8));
      piVar18[0x58] = *(int *)(param_2 + 0x46c) + 1;
    }
    else {
      local_6c = piVar18[0x21];
      local_68 = 0;
      local_60 = piVar18;
      do {
        if (*(char *)((int)&local_2c + local_68) != '\x01') {
          local_6c = local_6c + 1;
          piVar18[0x21] = local_6c;
          FUN_000fa0d2(piVar18,param_2,local_6c,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
          (**(code **)(*piVar18 + 0x88))(piVar18,local_6c,local_68,local_68);
          *(undefined1 *)(local_60 + 0x27) = 0;
        }
        local_68 = local_68 + 1;
        local_60 = (int *)((int)local_60 + 1);
      } while (local_68 != 4);
      if (*(int *)(param_2 + 0x46c) < piVar18[0x58]) {
        piVar18[0x58] = piVar18[0x58] + 1;
      }
      else {
        piVar18[0x58] = *(int *)(param_2 + 0x46c) + 1;
      }
    }
    local_64 = 0;
    do {
      if (*(char *)((int)&local_2c + local_64) != '\x01') {
        cVar3 = (**(code **)(*piVar16 + 0x60))(piVar16);
        if (cVar3 == '\0') {
          (**(code **)(*piVar11 + 0x88))
                    (piVar11,local_94,local_64,*(undefined1 *)((int)&local_30 + local_64));
        }
        else {
          iVar12 = FUN_0010b0f4(piVar16,0);
          iVar12 = FUN_000f5970(*(undefined4 *)(iVar12 + 0x10));
          (**(code **)(*piVar16 + 0x88))
                    (piVar16,1,iVar12,*(undefined1 *)((int)&local_30 + local_64));
          (**(code **)(*piVar11 + 0x88))(piVar11,local_94,local_64,iVar12);
          *(undefined1 *)(iVar12 + 0x9c + (int)piVar16) = 0;
        }
        cVar3 = (**(code **)(*piVar17 + 0x60))(piVar17);
        if (cVar3 == '\0') {
          (**(code **)(*piVar11 + 0x88))
                    (piVar11,local_90,local_64,*(undefined1 *)((int)&local_34 + local_64));
        }
        else {
          iVar12 = FUN_0010b0f4(piVar17,0);
          iVar12 = FUN_000f5970(*(undefined4 *)(iVar12 + 0x10));
          (**(code **)(*piVar17 + 0x88))
                    (piVar17,1,iVar12,*(undefined1 *)((int)&local_34 + local_64));
          (**(code **)(*piVar11 + 0x88))(piVar11,local_90,local_64,iVar12);
          *(undefined1 *)(iVar12 + 0x9c + (int)piVar17) = 0;
        }
        (**(code **)(*piVar11 + 0x88))(piVar11,local_8c,local_64,local_64);
      }
      local_64 = local_64 + 1;
    } while (local_64 != 4);
    if (*(int *)(param_2 + 0x46c) < piVar16[0x58]) {
      piVar16[0x58] = piVar16[0x58] + 1;
    }
    else {
      piVar16[0x58] = *(int *)(param_2 + 0x46c) + 1;
    }
    if (*(int *)(param_2 + 0x46c) < piVar17[0x58]) {
      piVar17[0x58] = piVar17[0x58] + 1;
    }
    else {
      piVar17[0x58] = *(int *)(param_2 + 0x46c) + 1;
    }
    if (local_4c != 0) {
      FUN_0010c568(piVar11,&local_50,0,*(undefined4 *)(param_2 + 8));
      if (*(int *)(param_2 + 0x46c) < *(int *)(local_4c + 0x160)) {
        *(int *)(local_4c + 0x160) = *(int *)(local_4c + 0x160) + 1;
      }
      else {
        *(int *)(local_4c + 0x160) = *(int *)(param_2 + 0x46c) + 1;
      }
    }
    piVar11[0x58] = iVar10 + *(int *)(param_2 + 0x46c);
    FUN_0010b3fe(iVar9,*(undefined4 *)(param_2 + 8));
  }
  return 0;
}

/* FUN_0016fdba @ 0x16fdba (4724 bytes) */
int FUN_0016fdba(param_1, param_2)
  int param_1;
  int param_2;
{
  char *pcVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  bool bVar5;
  char cVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int *piVar15;
  int *piVar16;
  int iVar17;
  byte bVar18;
  byte bVar19;
  byte local_f4;
  int local_d0;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  float local_b4;
  int *local_a0;
  int *local_9c;
  uint local_88;
  int local_80;
  int local_7c;
  int local_74;
  int local_70;
  undefined4 local_68;
  float local_64;
  undefined4 local_50;
  int local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  if ((*(byte *)(param_1 + 0x15) & 2) == 0) {
    return 0;
  }
  iVar8 = FUN_0010b180(param_1,*(undefined4 *)(param_1 + 0x84));
  if (iVar8 == 0) {
    return 0;
  }
  if ((*(byte *)(*(int *)(*(int *)(param_2 + 8) + 0x54) + 9) & 1) == 0) {
    return 0;
  }
  iVar17 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  iVar10 = *(int *)(*(int *)(iVar8 + 0x88) + 8);
  iVar9 = FUN_0010b0f4(param_1,*(undefined4 *)(param_1 + 0x84));
  local_20[0] = *(undefined4 *)(iVar9 + 0x10);
  if (iVar17 == 0x31) {
    if (iVar10 != 0x14) {
      return 0;
    }
    iVar17 = FUN_0010b0f4(param_1,0);
    local_68 = *(undefined4 *)(iVar17 + 0x10);
    iVar17 = 0;
    do {
      pcVar1 = (char *)((int)local_20 + iVar17);
      if (*pcVar1 == '\x04') {
        if (*(char *)((int)&local_68 + iVar17) == '\0') {
          *pcVar1 = (char)iVar17;
        }
      }
      else {
        *pcVar1 = '\x04';
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 != 4);
    local_d0 = param_1;
    iVar17 = iVar8;
  }
  else {
    if (iVar17 != 0x14) {
      return 0;
    }
    iVar17 = param_1;
    local_d0 = iVar8;
    if (iVar10 != 0x31) {
      return 0;
    }
  }
  if (*(char *)(local_d0 + 0x120) != *(char *)(iVar17 + 0x120)) {
    return 0;
  }
  if (*(int *)(local_d0 + 0x124) != *(int *)(iVar17 + 0x124)) {
    return 0;
  }
  iVar10 = FUN_0010b0f4(local_d0,0);
  local_24 = *(int *)(iVar10 + 0x10);
  iVar10 = FUN_0010b0f4(iVar17,0);
  local_28 = *(undefined4 *)(iVar10 + 0x10);
  cVar6 = FUN_000e1402(*(undefined4 *)(param_2 + 8),0x30);
  if (cVar6 != '\0') {
    if ((*(unsigned char *)((unsigned char *)&(local_24) + 3)) == '\0') {
      return 0;
    }
    if ((*(unsigned char *)((unsigned char *)&(local_28) + 3)) == '\0') {
      return 0;
    }
  }
  iVar10 = 1;
  do {
    if ((*(char *)((int)&local_28 + iVar10 + 3) != '\x01') &&
       (*(char *)((int)&local_2c + iVar10 + 3) != '\x01')) {
      return 0;
    }
    iVar10 = iVar10 + 1;
  } while (iVar10 != 5);
  piVar11 = (int *)FUN_0010b180(local_d0,1);
  cVar6 = (**(code **)(*piVar11 + 0x60))(piVar11);
  if (cVar6 != '\0') {
    return 0;
  }
  iVar10 = FUN_0014fbbc(local_d0,1);
  iVar9 = FUN_0014fbbc(iVar17,1);
  iVar12 = FUN_0014fbbc(iVar17,2);
  iVar13 = FUN_0014fbbc(iVar17,3);
  bVar18 = (byte)*(uint *)(iVar17 + 0xb8) & 1;
  bVar19 = (byte)*(uint *)(iVar17 + 0xd0) & 1;
  local_f4 = (byte)(*(uint *)(iVar17 + 0xe8) >> 1);
  bVar7 = local_f4 & 1;
  uVar14 = *(uint *)(local_d0 + 0xb8);
  local_f4 = (byte)(uVar14 >> 1);
  local_f4 = local_f4 & 1;
  if ((iVar10 == iVar9) && (((byte)(*(uint *)(iVar17 + 0xb8) >> 1) & 1) == local_f4)) {
    if ((uVar14 & 1) == 0) {
      if (bVar18 != bVar19) goto LAB_00170024;
    }
    else if (bVar18 == bVar19) goto LAB_00170024;
    local_c0 = 1;
    local_bc = 2;
    local_b8 = 3;
    local_b4 = FLOAT_001c5ba4;
  }
  else {
LAB_00170024:
    if ((iVar10 == iVar12) && (((byte)(*(uint *)(iVar17 + 0xd0) >> 1) & 1) == local_f4)) {
      if ((uVar14 & 1) == 0) {
        if (bVar18 == bVar19) {
LAB_001708e6:
          local_c0 = 2;
          local_bc = 1;
          local_b8 = 3;
          local_b4 = FLOAT_001c5ba4;
          goto LAB_00170091;
        }
      }
      else if (bVar18 != bVar19) goto LAB_001708e6;
    }
    if (iVar10 != iVar13) {
      return 0;
    }
    if (bVar7 != local_f4) {
      return 0;
    }
    if (((byte)*(uint *)(iVar17 + 0xe8) & 1) != ((byte)uVar14 & 1)) {
      return 0;
    }
    local_c0 = 3;
    local_bc = 1;
    local_b8 = 2;
    local_b4 = 0.0;
  }
LAB_00170091:
  local_50 = 0;
  local_4c = 0;
  local_3c = 0;
  if ((*(byte *)(iVar8 + 0x15) & 2) != 0) {
    FUN_0010a980(iVar8,&local_50);
  }
  iVar10 = *(int *)(local_d0 + 0x160) - *(int *)(param_2 + 0x46c);
  iVar8 = 0;
  if (-1 < iVar10) {
    iVar8 = iVar10;
  }
  iVar10 = FUN_0010b0f4(local_d0,1);
  local_34 = *(undefined4 *)(iVar10 + 0x10);
  iVar10 = FUN_0010b0f4(iVar17,local_bc);
  local_38 = *(undefined4 *)(iVar10 + 0x10);
  iVar10 = FUN_0010b0f4(iVar17,local_b8);
  local_2c = *(undefined4 *)(iVar10 + 0x10);
  local_30 = local_24;
  iVar10 = 1;
  do {
    cVar6 = *(char *)((int)&local_2c + iVar10 + 3);
    if (cVar6 != '\x01') {
      *(char *)((int)&local_34 + iVar10 + 3) = cVar6;
    }
    iVar10 = iVar10 + 1;
  } while (iVar10 != 5);
  FUN_0010b3fe(local_d0,*(undefined4 *)(param_2 + 8));
  piVar11 = (int *)FUN_0010b180(iVar17,local_c0);
  local_a0 = (int *)FUN_0010b180(iVar17,local_bc);
  local_9c = (int *)FUN_0010b180(iVar17,local_b8);
  iVar10 = *(int *)(param_1 + 4);
  FUN_001a7d72(param_1);
  if ((*(byte *)(iVar17 + 0x15) & 2) != 0) {
    uVar2 = *(undefined4 *)(param_2 + 8);
    uVar14 = *(uint *)(param_2 + 0x30) >> 7;
    if ((uVar14 & 1) != 0) {
      iVar9 = FUN_0010b180(iVar17,*(undefined4 *)(iVar17 + 0x84));
      puVar3 = *(uint **)(iVar9 + 0x10);
      if (0 < (int)puVar3[1]) {
        local_88 = 0;
        do {
          if (local_88 < *puVar3) {
            uVar4 = puVar3[1];
            if (uVar4 <= local_88) {
              _memset((void *)(puVar3[2] + uVar4 * 4),0,(local_88 - uVar4) * 4 + 4);
              puVar3[1] = local_88 + 1;
            }
            piVar15 = (int *)(puVar3[2] + local_88 * 4);
          }
          else {
            piVar15 = (int *)FUN_001a7f7c(puVar3,local_88);
          }
          if (iVar17 == *piVar15) {
            FUN_001a7f3c(puVar3,local_88);
            iVar9 = FUN_0010b180(iVar17,*(undefined4 *)(iVar17 + 0x84));
            *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + -1;
            break;
          }
          local_88 = local_88 + 1;
        } while ((int)local_88 < (int)puVar3[1]);
      }
    }
    FUN_0010ba02(iVar17,*(undefined4 *)(iVar17 + 0x84),0,(byte)uVar14 & 1,uVar2);
    *(int *)(iVar17 + 0x84) = *(int *)(iVar17 + 0x84) + -1;
    *(uint *)(iVar17 + 0x14) = *(uint *)(iVar17 + 0x14) & 0xfffffdff;
  }
  piVar15 = (int *)FUN_00109cd4(iVar17,param_1,*(undefined4 *)(param_2 + 8),0);
  FUN_000e9596(*(undefined4 *)(iVar10 + 0x158),iVar10,piVar15);
  piVar15[0x27] = local_30;
  iVar17 = piVar15[0x53];
  iVar10 = FUN_0010b0f4(piVar15,0);
  *(int *)(iVar10 + 8) = iVar17;
  cVar6 = (**(code **)(*local_a0 + 0x60))(local_a0);
  if (cVar6 == '\0') {
    piVar16 = (int *)FUN_0010f654(0xa2,*(undefined4 *)(param_2 + 8));
    FUN_000e956e(piVar15[0x56],piVar15,piVar16);
    piVar16[0x21] = 1;
    piVar16[0x25] = piVar16[0x53];
    piVar16[0x26] = 0x36;
    piVar16[0x27] = local_30;
    iVar17 = FUN_0010b180(piVar15,local_bc);
    FUN_0010ba02(piVar16,1,iVar17,0,*(undefined4 *)(param_2 + 8));
    if (*(int *)(param_2 + 0x46c) < *(int *)(iVar17 + 0x160)) {
      *(int *)(iVar17 + 0x160) = *(int *)(iVar17 + 0x160) + 1;
    }
    else {
      *(int *)(iVar17 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
    }
    piVar16[0x21] = 2;
    FUN_000fa0d2(piVar16,param_2,2,local_b4,local_b4,local_b4,local_b4);
    iVar17 = 0;
    do {
      if (*(char *)((int)&local_28 + iVar17) != '\x01') {
        (**(code **)(*piVar16 + 0x88))(piVar16,1,iVar17,*(undefined1 *)((int)&local_38 + iVar17));
        (**(code **)(*piVar16 + 0x88))(piVar16,2,iVar17,4);
        (**(code **)(*piVar15 + 0x88))(piVar15,local_bc,iVar17,iVar17);
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 != 4);
    iVar17 = 0;
    do {
      if (*(char *)((int)local_20 + iVar17 + -4) != '\x01') {
        (**(code **)(*piVar16 + 0x88))(piVar16,1,iVar17,4);
        (**(code **)(*piVar16 + 0x88))(piVar16,2,iVar17,iVar17);
        (**(code **)(*piVar15 + 0x88))(piVar15,local_bc,iVar17,iVar17);
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 != 4);
    FUN_0010ba02(piVar15,local_bc,piVar16,0,*(undefined4 *)(param_2 + 8));
    piVar16[0x58] = *(int *)(param_2 + 0x46c) + 1;
  }
  else {
    cVar6 = FUN_0010a62e(local_a0,param_2);
    if (cVar6 == '\0') {
      local_a0[0x58] = local_a0[0x58] + -1;
      local_a0 = (int *)FUN_0010a1c2(local_a0,*(undefined4 *)(param_2 + 8),0);
      FUN_000e956e(*(undefined4 *)(param_1 + 0x158),param_1,local_a0);
      local_a0[0x58] = *(int *)(param_2 + 0x46c) + 1;
    }
    if (1 < local_a0[0x21]) {
      bVar5 = false;
      local_80 = 2;
      do {
        iVar17 = FUN_0010b0f4(local_a0,0);
        cVar6 = FUN_000f7e7e(local_a0,local_80,*(undefined4 *)(iVar17 + 0x10),&local_68);
        if (cVar6 != '\0') {
          if ((local_b4 == local_64) && (!NAN(local_b4) && !NAN(local_64))) {
            iVar17 = -1;
            iVar10 = 0;
            do {
              iVar9 = FUN_0010b0f4(local_a0,local_80);
              if (*(char *)(iVar10 + 0x10 + iVar9) != '\x04') {
                iVar17 = iVar10;
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 != 4);
            iVar10 = 0;
            do {
              if (*(char *)((int)local_20 + iVar10) != '\x04') {
                (**(code **)(*piVar15 + 0x88))(piVar15,local_bc,iVar10,iVar17);
                bVar5 = true;
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 != 4);
            if (bVar5) goto LAB_001704e6;
          }
        }
        local_80 = local_80 + 1;
      } while (local_80 <= local_a0[0x21]);
      if (bVar5) goto LAB_001704e6;
    }
    iVar10 = local_a0[0x21] + 1;
    local_a0[0x21] = iVar10;
    FUN_000fa0d2(local_a0,param_2,iVar10,local_b4,local_b4,local_b4,local_b4);
    iVar17 = FUN_0010b0f4(local_a0,iVar10);
    *(undefined4 *)(iVar17 + 0x10) = DAT_001cc5a4;
    local_7c = 0;
    do {
      iVar17 = FUN_0010b0f4(local_a0,0);
      if (*(char *)(local_7c + 0x10 + iVar17) != '\0') {
        (**(code **)(*local_a0 + 0x88))(local_a0,iVar10,local_7c,local_7c);
        *(undefined1 *)(local_7c + 0x9c + (int)local_a0) = 0;
        goto LAB_00170b5a;
      }
      local_7c = local_7c + 1;
    } while (local_7c != 4);
    local_7c = -1;
LAB_00170b5a:
    iVar17 = 0;
    do {
      if (*(char *)((int)local_20 + iVar17) != '\x04') {
        (**(code **)(*piVar15 + 0x88))(piVar15,local_bc,iVar17,local_7c);
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 != 4);
  }
LAB_001704e6:
  cVar6 = (**(code **)(*local_9c + 0x60))(local_9c);
  if (cVar6 == '\0') {
    piVar16 = (int *)FUN_0010f654(0xa2,*(undefined4 *)(param_2 + 8));
    FUN_000e956e(piVar15[0x56],piVar15,piVar16);
    piVar16[0x21] = 1;
    piVar16[0x25] = piVar16[0x53];
    piVar16[0x26] = 0x36;
    piVar16[0x27] = local_30;
    iVar17 = FUN_0010b180(piVar15,local_b8);
    FUN_0010ba02(piVar16,1,iVar17,0,*(undefined4 *)(param_2 + 8));
    if (*(int *)(param_2 + 0x46c) < *(int *)(iVar17 + 0x160)) {
      *(int *)(iVar17 + 0x160) = *(int *)(iVar17 + 0x160) + 1;
    }
    else {
      *(int *)(iVar17 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
    }
    piVar16[0x21] = 2;
    FUN_000fa0d2(piVar16,param_2,2,0,0,0,0);
    iVar17 = 0;
    do {
      if (*(char *)((int)&local_28 + iVar17) != '\x01') {
        (**(code **)(*piVar16 + 0x88))(piVar16,1,iVar17,*(undefined1 *)((int)&local_2c + iVar17));
        (**(code **)(*piVar16 + 0x88))(piVar16,2,iVar17,4);
        (**(code **)(*piVar15 + 0x88))(piVar15,local_b8,iVar17,iVar17);
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 != 4);
    iVar17 = 0;
    do {
      if (*(char *)((int)local_20 + iVar17 + -4) != '\x01') {
        (**(code **)(*piVar16 + 0x88))(piVar16,1,iVar17,4);
        (**(code **)(*piVar16 + 0x88))(piVar16,2,iVar17,iVar17);
        (**(code **)(*piVar15 + 0x88))(piVar15,local_b8,iVar17,iVar17);
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 != 4);
    FUN_0010ba02(piVar15,local_b8,piVar16,0,*(undefined4 *)(param_2 + 8));
    piVar16[0x58] = *(int *)(param_2 + 0x46c) + 1;
  }
  else {
    cVar6 = FUN_0010a62e(local_9c,param_2);
    if (cVar6 == '\0') {
      local_9c[0x58] = local_9c[0x58] + -1;
      local_9c = (int *)FUN_0010a1c2(local_9c,*(undefined4 *)(param_2 + 8),0);
      FUN_000e956e(*(undefined4 *)(param_1 + 0x158),param_1,local_9c);
      local_9c[0x58] = *(int *)(param_2 + 0x46c) + 1;
    }
    if (1 < local_9c[0x21]) {
      bVar5 = false;
      local_74 = 2;
      do {
        iVar17 = FUN_0010b0f4(local_9c,0);
        cVar6 = FUN_000f7e7e(local_9c,local_74,*(undefined4 *)(iVar17 + 0x10),&local_68);
        if (((cVar6 != '\0') && (local_64 == 0.0)) && (!NAN(local_64))) {
          iVar17 = -1;
          iVar10 = 0;
          do {
            iVar9 = FUN_0010b0f4(local_9c,local_74);
            if (*(char *)(iVar10 + 0x10 + iVar9) != '\x04') {
              iVar17 = iVar10;
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 != 4);
          iVar10 = 0;
          do {
            if (*(char *)((int)local_20 + iVar10) != '\x04') {
              (**(code **)(*piVar15 + 0x88))(piVar15,local_b8,iVar10,iVar17);
              bVar5 = true;
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 != 4);
          if (bVar5) goto LAB_00170718;
        }
        local_74 = local_74 + 1;
      } while (local_74 <= local_9c[0x21]);
      if (bVar5) goto LAB_00170718;
    }
    iVar10 = local_9c[0x21] + 1;
    local_9c[0x21] = iVar10;
    FUN_000fa0d2(local_9c,param_2,iVar10,0,0,0,0);
    iVar17 = FUN_0010b0f4(local_9c,iVar10);
    *(undefined4 *)(iVar17 + 0x10) = DAT_001cc5a4;
    local_70 = 0;
    do {
      iVar17 = FUN_0010b0f4(local_9c,0);
      if (*(char *)(local_70 + 0x10 + iVar17) != '\0') {
        (**(code **)(*local_9c + 0x88))(local_9c,iVar10,local_70,local_70);
        *(undefined1 *)(local_70 + 0x9c + (int)local_9c) = 0;
        goto LAB_00170a51;
      }
      local_70 = local_70 + 1;
    } while (local_70 != 4);
    local_70 = -1;
LAB_00170a51:
    iVar17 = 0;
    do {
      if (*(char *)((int)local_20 + iVar17) != '\x04') {
        (**(code **)(*piVar15 + 0x88))(piVar15,local_b8,iVar17,local_70);
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 != 4);
  }
LAB_00170718:
  iVar17 = 0;
  do {
    if (*(char *)((int)local_20 + iVar17 + -4) != '\x01') {
      cVar6 = (**(code **)(*piVar11 + 0x60))(piVar11);
      if (cVar6 == '\0') {
        (**(code **)(*piVar15 + 0x88))
                  (piVar15,local_c0,iVar17,*(undefined1 *)((int)&local_34 + iVar17));
      }
      else {
        iVar10 = FUN_0010b0f4(piVar11,0);
        iVar10 = FUN_000f5970(*(undefined4 *)(iVar10 + 0x10));
        (**(code **)(*piVar11 + 0x88))(piVar11,1,iVar10,*(undefined1 *)((int)&local_34 + iVar17));
        (**(code **)(*piVar15 + 0x88))(piVar15,local_c0,iVar17,iVar10);
        *(undefined1 *)(iVar10 + 0x9c + (int)piVar11) = 0;
      }
    }
    iVar17 = iVar17 + 1;
  } while (iVar17 != 4);
  if (*(int *)(param_2 + 0x46c) < piVar11[0x58]) {
    piVar11[0x58] = piVar11[0x58] + 1;
  }
  else {
    piVar11[0x58] = *(int *)(param_2 + 0x46c) + 1;
  }
  if (local_4c != 0) {
    FUN_0010c568(piVar15,&local_50,0,*(undefined4 *)(param_2 + 8));
    if (*(int *)(param_2 + 0x46c) < *(int *)(local_4c + 0x160)) {
      *(int *)(local_4c + 0x160) = *(int *)(local_4c + 0x160) + 1;
    }
    else {
      *(int *)(local_4c + 0x160) = *(int *)(param_2 + 0x46c) + 1;
    }
  }
  piVar15[0x58] = iVar8 + *(int *)(param_2 + 0x46c);
  return 0;
}

/* FUN_0017102e @ 0x17102e (2220 bytes) */
int FUN_0017102e(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_74;
  uint local_70;
  float local_6c;
  int *local_68;
  int local_5c;
  int local_58;
  int local_50;
  undefined1 local_44 [4];
  float local_40;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if ((*(byte *)((int)param_1 + 0x15) & 2) == 0) {
    return 0;
  }
  iVar6 = FUN_0010b180(param_1,param_1[0x21]);
  if (iVar6 == 0) {
    return 0;
  }
  if ((*(byte *)(*(int *)(*(int *)(param_2 + 8) + 0x54) + 9) & 1) == 0) {
    return 0;
  }
  iVar10 = *(int *)(param_1[0x22] + 8);
  if (2 < iVar10 - 0x12U) {
    return 0;
  }
  if ((char)param_1[0x48] != '\0') {
    return 0;
  }
  if (param_1[0x49] != 0) {
    return 0;
  }
  local_8c = 1;
LAB_001710af:
  iVar7 = (**(code **)(*param_1 + 0x14))(param_1);
  if (iVar7 < (int)local_8c) {
    return 0;
  }
  iVar7 = FUN_0010b180(param_1,local_8c);
  if ((iVar7 == iVar6) && ((param_1[local_8c * 6 + 0x28] & 2U) == 0)) {
    if (iVar10 == 0x12) {
      if ((param_1[local_8c * 6 + 0x28] & 1U) == 0) {
        local_88 = local_8c ^ 3;
        local_80 = 0xffffffff;
LAB_0017113c:
        if ((int)local_8c < 0) {
          return 0;
        }
        local_84 = 0xffffffff;
LAB_00171151:
        iVar6 = FUN_0010b0f4(param_1,0);
        local_20 = *(int *)(iVar6 + 0x10);
        iVar6 = FUN_0010b0f4(param_1,local_8c);
        local_24 = *(undefined4 *)(iVar6 + 0x10);
        iVar6 = (**(code **)(*param_1 + 0x14))(param_1);
        iVar6 = FUN_0010b0f4(param_1,iVar6 + 1);
        local_28 = *(undefined4 *)(iVar6 + 0x10);
        cVar5 = FUN_000e1402(*(undefined4 *)(param_2 + 8),0x30);
        if (cVar5 != '\0') {
          if ((*(unsigned char *)((unsigned char *)&(local_20) + 3)) == '\0') {
            return 0;
          }
          if ((*(unsigned char *)((unsigned char *)&(local_28) + 3)) != '\x04') {
            return 0;
          }
        }
        iVar6 = 0;
        do {
          if (*(char *)((int)&local_20 + iVar6) == '\0') {
            if (*(char *)((int)&local_28 + iVar6) != '\x04') {
              return 0;
            }
          }
          else if (*(char *)((int)&local_28 + iVar6) != '\x04') {
            *(char *)((int)&local_20 + iVar6) = '\0';
            *(char *)((int)&local_24 + iVar6) = (char)iVar6;
          }
          uVar1 = local_24;
          iVar6 = iVar6 + 1;
        } while (iVar6 != 4);
        iVar6 = FUN_0010b0f4(param_1,local_8c);
        *(undefined4 *)(iVar6 + 0x10) = uVar1;
        param_1[0x27] = local_20;
        iVar6 = FUN_0010b180(param_1,local_8c);
        *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + -1;
        uVar1 = *(undefined4 *)(param_2 + 8);
        uVar8 = *(uint *)(param_2 + 0x30) >> 7;
        if ((uVar8 & 1) != 0) {
          iVar6 = FUN_0010b180(param_1,param_1[0x21]);
          puVar2 = *(uint **)(iVar6 + 0x10);
          if (0 < (int)puVar2[1]) {
            local_74 = 0;
            do {
              if (local_74 < *puVar2) {
                uVar3 = puVar2[1];
                if (uVar3 <= local_74) {
                  _memset((void *)(puVar2[2] + uVar3 * 4),0,(local_74 - uVar3) * 4 + 4);
                  puVar2[1] = local_74 + 1;
                }
                piVar9 = (int *)(puVar2[2] + local_74 * 4);
              }
              else {
                piVar9 = (int *)FUN_001a7f7c(puVar2,local_74);
              }
              if (param_1 == (int *)*piVar9) {
                FUN_001a7f3c(puVar2,local_74);
                iVar6 = FUN_0010b180(param_1,param_1[0x21]);
                *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + -1;
                break;
              }
              local_74 = local_74 + 1;
            } while ((int)local_74 < (int)puVar2[1]);
          }
        }
        FUN_0010ba02(param_1,param_1[0x21],0,(byte)uVar8 & 1,uVar1);
        param_1[0x21] = param_1[0x21] + -1;
        param_1[5] = param_1[5] & 0xfffffdff;
        local_70 = 1;
LAB_001712ac:
        do {
          iVar6 = (**(code **)(*param_1 + 0x14))(param_1);
          if (iVar6 < (int)local_70) {
            return 0;
          }
          if (local_70 == local_80) {
            local_6c = FLOAT_001c5ba4;
LAB_001712eb:
            local_68 = (int *)FUN_0010b180(param_1,local_70);
            iVar6 = FUN_0010b0f4(param_1,local_70);
            local_2c = *(undefined4 *)(iVar6 + 0x10);
            cVar5 = (**(code **)(*local_68 + 0x60))(local_68);
            if (cVar5 == '\0') {
              piVar9 = (int *)FUN_0010f654(0xa2,*(undefined4 *)(param_2 + 8));
              FUN_000e956e(param_1[0x56],param_1,piVar9);
              piVar9[0x21] = 1;
              piVar9[0x25] = piVar9[0x53];
              piVar9[0x26] = 0x36;
              piVar9[0x27] = local_20;
              FUN_0010ba02(piVar9,1,local_68,0,*(undefined4 *)(param_2 + 8));
              piVar9[0x21] = 2;
              FUN_000fa0d2(piVar9,param_2,2,local_6c,local_6c,local_6c,local_6c);
              iVar6 = 0;
              do {
                if (*(char *)((int)&local_20 + iVar6) != '\x01') {
                  if (*(char *)((int)&local_28 + iVar6) == '\x04') {
                    (**(code **)(*piVar9 + 0x88))
                              (piVar9,1,iVar6,*(undefined1 *)((int)&local_2c + iVar6));
                    (**(code **)(*piVar9 + 0x88))(piVar9,2,iVar6,4);
                  }
                  else {
                    (**(code **)(*piVar9 + 0x88))(piVar9,2,iVar6,iVar6);
                    (**(code **)(*piVar9 + 0x88))(piVar9,1,iVar6,4);
                  }
                  (**(code **)(*param_1 + 0x88))(param_1,local_70,iVar6,iVar6);
                }
                iVar6 = iVar6 + 1;
              } while (iVar6 != 4);
              FUN_0010ba02(param_1,local_70,piVar9,0,*(undefined4 *)(param_2 + 8));
              piVar9[0x58] = *(int *)(param_2 + 0x46c) + 1;
              local_70 = local_70 + 1;
              goto LAB_001712ac;
            }
            cVar5 = FUN_0010a62e(local_68,param_2);
            if (cVar5 == '\0') {
              local_68 = (int *)FUN_0010a1c2(local_68,*(undefined4 *)(param_2 + 8),0);
              FUN_000e956e(param_1[0x56],param_1,local_68);
              local_68[0x58] = *(int *)(param_2 + 0x46c) + 1;
            }
            if (1 < local_68[0x21]) {
              bVar4 = false;
              local_5c = 2;
              do {
                iVar6 = FUN_0010b0f4(local_68,0);
                cVar5 = FUN_000f7e7e(local_68,local_5c,*(undefined4 *)(iVar6 + 0x10),local_44);
                if (cVar5 != '\0') {
                  if ((local_6c == local_40) && (!NAN(local_6c) && !NAN(local_40))) {
                    local_58 = -1;
                    iVar6 = 0;
                    do {
                      iVar10 = FUN_0010b0f4(local_68,local_5c);
                      if (*(char *)(iVar6 + 0x10 + iVar10) != '\x04') {
                        local_58 = iVar6;
                      }
                      iVar6 = iVar6 + 1;
                    } while (iVar6 != 4);
                    iVar6 = 0;
                    do {
                      if (*(char *)((int)&local_28 + iVar6) != '\x04') {
                        (**(code **)(*param_1 + 0x88))(param_1,local_70,iVar6,local_58);
                        bVar4 = true;
                      }
                      iVar6 = iVar6 + 1;
                    } while (iVar6 != 4);
                    if (bVar4) {
                      local_70 = local_70 + 1;
                      goto LAB_001712ac;
                    }
                  }
                }
                local_5c = local_5c + 1;
              } while (local_5c <= local_68[0x21]);
              if (bVar4) {
                local_70 = local_70 + 1;
                goto LAB_001712ac;
              }
            }
            iVar10 = local_68[0x21] + 1;
            local_68[0x21] = iVar10;
            FUN_000fa0d2(local_68,param_2,iVar10,local_6c,local_6c,local_6c,local_6c);
            iVar6 = FUN_0010b0f4(local_68,iVar10);
            *(undefined4 *)(iVar6 + 0x10) = DAT_001cc5a4;
            local_50 = 0;
            do {
              iVar6 = FUN_0010b0f4(local_68,0);
              if (*(char *)(local_50 + 0x10 + iVar6) != '\0') {
                (**(code **)(*local_68 + 0x88))(local_68,iVar10,local_50,local_50);
                *(undefined1 *)(local_50 + 0x9c + (int)local_68) = 0;
                goto LAB_001715eb;
              }
              local_50 = local_50 + 1;
            } while (local_50 != 4);
            local_50 = -1;
LAB_001715eb:
            iVar6 = 0;
            do {
              if (*(char *)((int)&local_28 + iVar6) != '\x04') {
                (**(code **)(*param_1 + 0x88))(param_1,local_70,iVar6,local_50);
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 != 4);
            local_70 = local_70 + 1;
            goto LAB_001712ac;
          }
          if ((local_70 == local_88) || (local_70 == local_84)) {
            local_6c = 0.0;
            goto LAB_001712eb;
          }
          local_70 = local_70 + 1;
        } while( true );
      }
    }
    else if (iVar10 == 0x13) {
      if ((*(byte *)(param_1 + 0x34) & 1) == (*(byte *)(param_1 + 0x2e) & 1)) {
        local_80 = local_8c ^ 3;
        local_88 = 0xffffffff;
        goto LAB_0017113c;
      }
    }
    else if (iVar10 == 0x14) {
      if (local_8c == 3) {
        if ((*(byte *)(param_1 + 0x3a) & 1) == 0) {
          local_8c = 3;
          local_88 = 1;
          local_84 = 2;
          local_80 = 0xffffffff;
          goto LAB_00171151;
        }
      }
      else if (((int)local_8c < 3) &&
              ((*(byte *)(param_1 + 0x34) & 1) == (*(byte *)(param_1 + 0x2e) & 1))) {
        local_80 = local_8c ^ 3;
        local_88 = 3;
        goto LAB_0017113c;
      }
    }
  }
  local_8c = local_8c + 1;
  goto LAB_001710af;
}

/* FUN_001718da @ 0x1718da (5810 bytes) */
int FUN_001718da(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  char cVar7;
  byte bVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int *piVar18;
  undefined4 uVar19;
  int *piVar20;
  int *piVar21;
  byte local_150;
  int *local_114;
  int *local_110;
  int *local_10c;
  int *local_108;
  int *local_104;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_c0;
  undefined4 local_b4;
  int local_b0;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_58;
  int local_54 [5];
  undefined4 local_40;
  int local_3c [2];
  undefined4 local_34;
  undefined1 uStack_31;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20 [4];
  
  local_110 = param_1;
  if ((*(byte *)((int)param_1 + 0x15) & 2) == 0) {
    return 0;
  }
  piVar9 = (int *)FUN_0010b180(param_1,param_1[0x21]);
  if (piVar9 == (int *)0x0) {
    return 0;
  }
  if ((*(byte *)(*(int *)(*(int *)(param_2 + 8) + 0x54) + 9) & 1) == 0) {
    return 0;
  }
  iVar10 = *(int *)(piVar9[0x22] + 8);
  if (*(int *)(param_1[0x22] + 8) == 0x12) {
    if (iVar10 == 0x12) {
      local_108 = (int *)FUN_0010b180(param_1,1);
      piVar18 = (int *)FUN_0010b180(param_1,2);
      local_104 = (int *)FUN_0010b180(piVar9,1);
      piVar20 = (int *)FUN_0010b180(piVar9,2);
      if (local_108 == piVar20) {
        FUN_0010fe82(piVar9,1,2,*(undefined4 *)(param_2 + 8));
        bVar4 = true;
        bVar5 = false;
        local_10c = piVar18;
      }
      else {
        local_10c = local_108;
        if (piVar18 == local_104) {
          FUN_0010fe82(param_1,1,2,*(undefined4 *)(param_2 + 8));
          bVar4 = false;
          bVar5 = true;
          local_108 = piVar18;
          local_104 = piVar20;
        }
        else if (piVar18 == piVar20) {
          FUN_0010fe82(piVar9,1,2,*(undefined4 *)(param_2 + 8));
          FUN_0010fe82(param_1,1,2,*(undefined4 *)(param_2 + 8));
          bVar4 = true;
          bVar5 = true;
          local_108 = piVar18;
        }
        else {
          if (local_108 != local_104) {
            return 0;
          }
          bVar4 = false;
          bVar5 = false;
          local_10c = piVar18;
          local_108 = local_104;
          local_104 = piVar20;
        }
      }
      iVar10 = FUN_0010b0f4(param_1,0);
      local_2c = *(int *)(iVar10 + 0x10);
      iVar10 = FUN_0010b0f4(piVar9,0);
      local_28 = *(int *)(iVar10 + 0x10);
      if ((((local_10c != local_104) && (piVar9[0x49] == param_1[0x49])) &&
          ((char)piVar9[0x48] == (char)param_1[0x48])) &&
         ((local_2c != DAT_001cc5a8 && (DAT_001cc5a8 != *(int *)(iVar10 + 0x10))))) {
        iVar10 = 1;
        do {
          if ((*(char *)((int)&local_2c + iVar10 + 3) != '\x01') &&
             (*(char *)((int)&local_30 + iVar10 + 3) != '\x01')) goto LAB_0017223e;
          iVar10 = iVar10 + 1;
        } while (iVar10 != 5);
        if ((((((byte)piVar9[0x2e] & 1) == ((byte)param_1[0x2e] & 1)) &&
             ((*(byte *)(param_1 + 0x34) & 1) == (*(byte *)(piVar9 + 0x34) & 1))) &&
            (((byte)((uint)piVar9[0x2e] >> 1) & 1) == ((byte)((uint)param_1[0x2e] >> 1) & 1))) &&
           (cVar7 = FUN_001503ee(local_104,local_10c), cVar7 == '\0')) {
          *(int *)(param_2 + 0x280) = *(int *)(param_2 + 0x280) + 1;
          local_24 = FUN_000f5892(local_28,local_2c);
          piVar18 = (int *)((int (*)())FUN_00110f42)(2,local_24,local_10c,param_2,*(undefined4 *)(param_2 + 8),
                                        0x3f800000);
          if (*(int *)(param_2 + 0x46c) < local_104[0x58]) {
            local_104[0x58] = local_104[0x58] + 1;
          }
          else {
            local_104[0x58] = *(int *)(param_2 + 0x46c) + 1;
          }
          piVar20 = (int *)((int (*)())FUN_00110f42)(2,local_24,local_104,param_2,*(undefined4 *)(param_2 + 8),
                                        0x3f800000);
          iVar10 = FUN_0010b0f4(param_1,2);
          uVar14 = *(undefined4 *)(iVar10 + 0x10);
          iVar10 = FUN_0010b0f4(piVar18,1);
          *(undefined4 *)(iVar10 + 0x10) = uVar14;
          iVar10 = FUN_0010b0f4(piVar9,2);
          uVar14 = *(undefined4 *)(iVar10 + 0x10);
          iVar10 = FUN_0010b0f4(piVar20,1);
          *(undefined4 *)(iVar10 + 0x10) = uVar14;
          local_9c = 0;
          local_98 = 0;
          local_88 = 0;
          local_54[0] = 0;
          local_54[1] = 0;
          local_40 = 0;
          local_84 = 0;
          local_80 = 0;
          local_70 = 0;
          local_6c = 0;
          local_68 = 0;
          local_58 = 0;
          uVar14 = FUN_0010b0f4(piVar9,1);
          FUN_0010a40a(&local_9c,uVar14);
          uVar14 = FUN_0010b0f4(piVar9,2);
          FUN_0010a40a(local_54,uVar14);
          uVar14 = FUN_0010b0f4(param_1,1);
          FUN_0010a40a(&local_84,uVar14);
          uVar14 = FUN_0010b0f4(param_1,2);
          FUN_0010a40a(&local_6c,uVar14);
          iVar10 = FUN_0010b0f4(param_1,1);
          local_30 = *(undefined4 *)(iVar10 + 0x10);
          iVar10 = FUN_0010b0f4(piVar9,1);
          local_20[0] = *(int *)(iVar10 + 0x10);
          local_3c[0] = 0;
          local_3c[1] = 0;
          local_34 = 0;
          FUN_00109d1c(param_1,local_3c,0xffffffff);
          local_b4 = 0;
          local_b0 = 0;
          local_a0 = 0;
          if ((*(byte *)((int)piVar9 + 0x15) & 2) != 0) {
            FUN_0010a980(piVar9,&local_b4);
          }
          iVar10 = param_1[1];
          FUN_001a7d72(param_1);
          FUN_0010da48(param_1,0x14,*(undefined4 *)(param_2 + 8));
          FUN_000e9596(*(undefined4 *)(iVar10 + 0x158),iVar10,param_1);
          FUN_00109d48(param_1,local_3c);
          *(char *)(param_1 + 0x48) = (char)piVar9[0x48];
          param_1[0x49] = piVar9[0x49];
          uVar14 = FUN_0010b0f4(param_1,3);
          FUN_0010a40a(uVar14,&local_84);
          uVar14 = FUN_0010b0f4(param_1,1);
          FUN_0010a40a(uVar14,&local_6c);
          uVar14 = FUN_0010b0f4(param_1,2);
          FUN_0010a40a(uVar14,local_54);
          FUN_0010ba02(param_1,1,piVar18,0,*(undefined4 *)(param_2 + 8));
          FUN_0010ba02(param_1,2,piVar20,0,*(undefined4 *)(param_2 + 8));
          FUN_00109c0e(param_1 + 0x29,1,0);
          param_1[0x25] = param_1[0x53];
          param_1[0x26] = 0;
          param_1[0x27] = local_24;
          local_f4 = 0;
          do {
            if (*(char *)((int)local_20 + local_f4 + -4) == '\0') {
              (**(code **)(*param_1 + 0x88))(param_1,1,local_f4,local_f4);
              (**(code **)(*param_1 + 0x88))(param_1,2,local_f4,local_f4);
              iVar10 = FUN_0010b0f4(piVar20,1);
              cVar7 = *(char *)(local_f4 + 0x10 + iVar10);
              iVar10 = FUN_0010b0f4(piVar18,1);
              if (cVar7 == '\x04') {
                if (*(char *)(local_f4 + 0x10 + iVar10) == '\x04') goto LAB_00172846;
                (**(code **)(*piVar20 + 0x88))(piVar20,2,local_f4,local_f4);
                iVar10 = *param_1;
                uVar1 = *(undefined1 *)((int)&local_30 + local_f4);
              }
              else {
                (**(code **)(*piVar18 + 0x88))(piVar18,2,local_f4,local_f4);
                iVar10 = *param_1;
                uVar1 = *(undefined1 *)((int)local_20 + local_f4);
              }
              (**(code **)(iVar10 + 0x88))(param_1,3,local_f4,uVar1);
            }
            else {
              (**(code **)(*param_1 + 0x88))(param_1,1,local_f4,4);
              (**(code **)(*param_1 + 0x88))(param_1,2,local_f4,4);
              (**(code **)(*param_1 + 0x88))(param_1,3,local_f4,4);
            }
LAB_00172846:
            local_f4 = local_f4 + 1;
            if (local_f4 == 4) {
              FUN_000e956e(param_1[0x56],param_1,piVar20);
              FUN_000e956e(param_1[0x56],param_1,piVar18);
              if (local_b0 != 0) {
                FUN_0010c568(param_1,&local_b4,0,*(undefined4 *)(param_2 + 8));
                if (*(int *)(param_2 + 0x46c) < *(int *)(local_b0 + 0x160)) {
                  *(int *)(local_b0 + 0x160) = *(int *)(local_b0 + 0x160) + 1;
                }
                else {
                  *(int *)(local_b0 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
                }
              }
              for (local_f0 = 1; iVar10 = (**(code **)(*piVar9 + 0x14))(piVar9), local_f0 <= iVar10;
                  local_f0 = local_f0 + 1) {
                piVar21 = (int *)FUN_0010b180(piVar9,local_f0);
                if ((((*(byte *)(piVar9 + 5) & 1) == 0) ||
                    (cVar7 = (**(code **)(*piVar21 + 0x5c))(piVar21), cVar7 == '\0')) ||
                   (cVar7 = FUN_0010a62e(piVar21,param_2), cVar7 != '\0')) {
                  cVar7 = (**(code **)(*piVar21 + 0x60))(piVar21);
                  if (((cVar7 != '\0') && ((*(byte *)(piVar9 + 5) & 1) == 0)) &&
                     (local_108 != piVar21)) {
                    FUN_0010b3fe(piVar21,*(undefined4 *)(param_2 + 8));
                  }
                }
                else {
                  FUN_0010a656(piVar21,param_2);
                  uVar12 = *(uint *)(param_2 + 0x30) >> 7;
                  iVar10 = FUN_00110110(piVar21,param_2,(byte)uVar12 & 1);
                  FUN_0010ba02(piVar9,local_f0,iVar10,0,*(undefined4 *)(param_2 + 8));
                  if ((uVar12 & 1) == 0) {
                    if (*(int *)(param_2 + 0x46c) < *(int *)(iVar10 + 0x160)) {
                      *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar10 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
                    }
                  }
                  piVar21[0x58] = piVar21[0x58] + -1;
                }
              }
              piVar21 = (int *)FUN_0010b180(piVar18,1);
              cVar7 = (**(code **)(*piVar21 + 0x60))(piVar21);
              if (cVar7 != '\0') {
                uVar14 = *(undefined4 *)(param_2 + 8);
                uVar19 = FUN_0010b180(piVar18,1);
                FUN_00111842(uVar19,piVar18,uVar14);
              }
              piVar18 = (int *)FUN_0010b180(piVar20,1);
              cVar7 = (**(code **)(*piVar18 + 0x60))(piVar18);
              if (cVar7 != '\0') {
                uVar14 = *(undefined4 *)(param_2 + 8);
                uVar19 = FUN_0010b180(piVar20,1);
                FUN_00111842(uVar19,piVar20,uVar14);
              }
              FUN_0010b3fe(piVar9,*(undefined4 *)(param_2 + 8));
              if (bVar4) {
                FUN_0010fe82(piVar9,1,2,*(undefined4 *)(param_2 + 8));
              }
              return 1;
            }
          } while( true );
        }
      }
LAB_0017223e:
      if (bVar4) {
        FUN_0010fe82(piVar9,1,2,*(undefined4 *)(param_2 + 8));
      }
      if (!bVar5) {
        return 0;
      }
      FUN_0010fe82(param_1,1,2,*(undefined4 *)(param_2 + 8));
      return 0;
    }
    cVar7 = (**(code **)(*piVar9 + 100))(piVar9);
    local_114 = piVar9;
    if (cVar7 != '\0') goto LAB_0017196e;
  }
  cVar7 = (**(code **)(*param_1 + 100))(param_1);
  if (cVar7 == '\0') {
    return 0;
  }
  if (iVar10 != 0x12) {
    return 0;
  }
  local_114 = param_1;
  local_110 = piVar9;
LAB_0017196e:
  iVar10 = FUN_0010b180(local_114,1);
  iVar11 = FUN_0010b180(local_110,1);
  if (iVar10 == iVar11) {
    local_ec = 1;
    local_e8 = 2;
  }
  else {
    iVar10 = FUN_0010b180(local_114,1);
    iVar11 = FUN_0010b180(local_110,2);
    if (iVar10 != iVar11) {
      return 0;
    }
    local_ec = 2;
    local_e8 = 1;
  }
  iVar10 = FUN_0010b0f4(param_1,0);
  local_20[0] = *(int *)(iVar10 + 0x10);
  iVar10 = FUN_0010b0f4(piVar9,0);
  local_24 = *(int *)(iVar10 + 0x10);
  if ((piVar9[0x49] == param_1[0x49]) && ((char)piVar9[0x48] == (char)param_1[0x48])) {
    local_150 = (byte)local_114[0x2e] & 1;
    if ((local_150 == ((byte)local_110[local_ec * 6 + 0x28] & 1)) &&
       (((byte)((uint)local_114[0x2e] >> 1) & 1) ==
        ((byte)((uint)local_110[local_ec * 6 + 0x28] >> 1) & 1))) {
      iVar11 = 1;
      do {
        if ((*(char *)((int)&local_28 + iVar11 + 3) != '\x01') &&
           (*(char *)((int)local_20 + iVar11 + -1) != '\x01')) {
          return 0;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 != 5);
      if ((local_20[0] != DAT_001cc5a8) && (DAT_001cc5a8 != *(int *)(iVar10 + 0x10))) {
        *(int *)(param_2 + 0x280) = *(int *)(param_2 + 0x280) + 1;
        uVar12 = *(uint *)(param_2 + 0x30) >> 7;
        bVar8 = (byte)uVar12 & 1;
        local_e4 = param_1[0x58] - *(int *)(param_2 + 0x46c);
        if (local_e4 < 0) {
          local_e4 = 0;
        }
        iVar10 = param_1[4];
        iVar11 = param_1[0x53];
        iVar2 = param_1[0x26];
        iVar6 = param_1[0x48];
        iVar3 = param_1[0x49];
        local_28 = local_20[0];
        iVar13 = 1;
        do {
          cVar7 = *(char *)((int)&local_28 + iVar13 + 3);
          if (cVar7 != '\x01') {
            *(char *)((int)&local_2c + iVar13 + 3) = cVar7;
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 != 5);
        iVar13 = FUN_0010b0f4(local_110,local_e8);
        local_2c = *(int *)(iVar13 + 0x10);
        iVar13 = 0;
        do {
          if (*(char *)((int)&local_28 + iVar13) == '\0') {
            *(char *)((int)&local_2c + iVar13) = (char)iVar13;
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 != 4);
        iVar13 = FUN_0010b0f4(local_110,local_ec);
        local_54[0] = *(int *)(iVar13 + 0x10);
        iVar13 = FUN_0010b0f4(local_114,1);
        local_30 = *(undefined4 *)(iVar13 + 0x10);
        iVar13 = 1;
        do {
          if (*(char *)((int)&local_58 + iVar13 + 3) == '\x04') {
            *(undefined1 *)((int)&local_58 + iVar13 + 3) = (&uStack_31)[iVar13];
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 != 5);
        uVar14 = FUN_0010b180(local_110,local_e8);
        iVar13 = FUN_00110110(uVar14,param_2,bVar8);
        iVar15 = FUN_0010b180(local_110,local_ec);
        iVar16 = FUN_0010f654(0xa2,*(undefined4 *)(param_2 + 8));
        FUN_000e956e(param_1[0x56],param_1,iVar16);
        *(undefined4 *)(iVar16 + 0x84) = 1;
        *(undefined4 *)(iVar16 + 0x94) = *(undefined4 *)(iVar16 + 0x14c);
        *(undefined4 *)(iVar16 + 0x98) = 0x36;
        *(int *)(iVar16 + 0x9c) = local_28;
        FUN_0010ba02(iVar16,1,iVar13,0,*(undefined4 *)(param_2 + 8));
        iVar17 = FUN_0010b0f4(local_110,local_e8);
        uVar14 = *(undefined4 *)(iVar17 + 0x10);
        iVar17 = FUN_0010b0f4(iVar16,1);
        *(undefined4 *)(iVar17 + 0x10) = uVar14;
        if (*(int *)(param_2 + 0x46c) < *(int *)(iVar13 + 0x160)) {
          *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
        }
        else {
          *(int *)(iVar13 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
        }
        *(undefined4 *)(iVar16 + 0x84) = 2;
        FUN_000fa0d2(iVar16,param_2,2,0,0,0,0);
        iVar13 = FUN_0010b0f4(local_114,1);
        uVar14 = *(undefined4 *)(iVar13 + 0x10);
        iVar13 = FUN_0010b0f4(iVar16,2);
        *(undefined4 *)(iVar13 + 0x10) = uVar14;
        iVar13 = *(int *)(param_2 + 0x46c);
        iVar17 = FUN_0010b180(iVar16,2);
        if (iVar13 < *(int *)(iVar17 + 0x160)) {
          *(int *)(iVar17 + 0x160) = *(int *)(iVar17 + 0x160) + 1;
        }
        else {
          *(int *)(iVar17 + 0x160) = iVar13 + 1;
        }
        *(undefined4 *)(iVar16 + 0x160) = *(undefined4 *)(param_2 + 0x46c);
        piVar18 = (int *)FUN_0010b180(iVar16,1);
        cVar7 = (**(code **)(*piVar18 + 0x60))(piVar18);
        if (cVar7 != '\0') {
          uVar14 = *(undefined4 *)(param_2 + 8);
          uVar19 = FUN_0010b180(iVar16,1);
          FUN_00111842(uVar19,iVar16,uVar14);
        }
        local_3c[0] = DAT_001cc5a4;
        if ((*(byte *)((int)piVar9 + 0x15) & 2) == 0) {
          local_c0 = 0;
        }
        else {
          local_c0 = FUN_0010b180(piVar9,piVar9[0x21]);
          if (local_c0 != 0) {
            iVar13 = FUN_0010b0f4(param_1,param_1[0x21]);
            local_3c[0] = *(int *)(iVar13 + 0x10);
            iVar13 = 1;
            do {
              if (*(char *)((int)&local_2c + iVar13 + 3) == '\0') {
                *(undefined1 *)((int)&local_40 + iVar13 + 3) = 4;
              }
              iVar13 = iVar13 + 1;
            } while (iVar13 != 5);
          }
        }
        if (0 < param_1[0x21]) {
          iVar13 = 1;
          do {
            iVar17 = FUN_0010b180(param_1,iVar13);
            *(int *)(iVar17 + 0x160) = *(int *)(iVar17 + 0x160) + -1;
            if ((uVar12 & 1) != 0) {
              iVar17 = FUN_0010b180(param_1,iVar13);
              FUN_001a805e(*(undefined4 *)(iVar17 + 0x10),param_1);
            }
            iVar13 = iVar13 + 1;
          } while (iVar13 <= param_1[0x21]);
        }
        local_6c = 0;
        local_68 = 0;
        local_58 = 0;
        local_84 = 0;
        local_80 = 0;
        local_70 = 0;
        uVar14 = FUN_0010b0f4(local_110,local_e8);
        FUN_0010a40a(&local_6c,uVar14);
        uVar14 = FUN_0010b0f4(local_110,local_ec);
        FUN_0010a40a(&local_84,uVar14);
        iVar13 = param_1[1];
        FUN_001a7d72(param_1);
        FUN_0010d8fc(param_1,0x12,*(undefined4 *)(param_2 + 8));
        FUN_000e9596(*(undefined4 *)(iVar13 + 0x158),iVar13,param_1);
        param_1[0x58] = local_e4 + *(int *)(param_2 + 0x46c);
        param_1[4] = iVar10;
        *(char *)(param_1 + 0x48) = (char)iVar6;
        param_1[0x49] = iVar3;
        param_1[0x27] = local_28;
        param_1[0x25] = iVar11;
        param_1[0x26] = iVar2;
        uVar14 = FUN_0010b0f4(param_1,local_e8);
        FUN_0010a474(uVar14,&local_6c);
        FUN_0010ba02(param_1,local_e8,iVar16,0,*(undefined4 *)(param_2 + 8));
        iVar10 = local_2c;
        if ((uVar12 & 1) == 0) {
          if (*(int *)(param_2 + 0x46c) < *(int *)(iVar16 + 0x160)) {
            *(int *)(iVar16 + 0x160) = *(int *)(iVar16 + 0x160) + 1;
          }
          else {
            *(int *)(iVar16 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
          }
        }
        if (local_e8 == 0) {
          param_1[0x27] = local_2c;
        }
        else {
          iVar11 = FUN_0010b0f4(param_1,local_e8);
          *(int *)(iVar11 + 0x10) = iVar10;
        }
        uVar14 = FUN_0010b0f4(param_1,local_ec);
        FUN_0010a474(uVar14,&local_84);
        FUN_0010ba02(param_1,local_ec,iVar15,0,*(undefined4 *)(param_2 + 8));
        iVar10 = local_54[0];
        if ((uVar12 & 1) == 0) {
          if (*(int *)(param_2 + 0x46c) < *(int *)(iVar15 + 0x160)) {
            *(int *)(iVar15 + 0x160) = *(int *)(iVar15 + 0x160) + 1;
          }
          else {
            *(int *)(iVar15 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
          }
        }
        if (local_ec == 0) {
          param_1[0x27] = local_54[0];
        }
        else {
          iVar11 = FUN_0010b0f4(param_1,local_ec);
          *(int *)(iVar11 + 0x10) = iVar10;
        }
        if ((local_c0 != 0) && (local_3c[0] != DAT_001cc5a4)) {
          FUN_0010c18e(param_1,local_c0,bVar8,*(undefined4 *)(param_2 + 8));
          iVar10 = local_3c[0];
          iVar11 = FUN_0010b0f4(param_1,3);
          *(int *)(iVar11 + 0x10) = iVar10;
          if ((uVar12 & 1) == 0) {
            if (*(int *)(param_2 + 0x46c) < *(int *)(local_c0 + 0x160)) {
              *(int *)(local_c0 + 0x160) = *(int *)(local_c0 + 0x160) + 1;
            }
            else {
              *(int *)(local_c0 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
            }
          }
        }
        FUN_0010b1fe(piVar9,*(undefined4 *)(param_2 + 8),0);
        return 0;
      }
    }
  }
  return 0;
}

/* FUN_00172f94 @ 0x172f94 (1165 bytes) */
int FUN_00172f94(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  int local_38;
  int *local_28;
  int local_20;
  
  if (*(int *)(param_1[0x22] + 8) == 0x13) {
    piVar6 = (int *)FUN_0010b180(param_1,1);
    piVar7 = (int *)FUN_0010b180(param_1,2);
    if ((((((*(int *)(piVar6[0x22] + 8) == 0x37) &&
           (cVar5 = FUN_0010a62e(piVar6,param_2), cVar5 != '\0')) &&
          ((*(byte *)((int)piVar6 + 0x15) & 2) == 0)) &&
         (((char)piVar6[0x48] == '\0' && (piVar6[0x49] == 0)))) &&
        ((*(int *)(piVar7[0x22] + 8) == 0x37 &&
         ((cVar5 = FUN_0010a62e(piVar7,param_2), cVar5 != '\0' &&
          ((*(byte *)((int)piVar7 + 0x15) & 2) == 0)))))) &&
       (((char)piVar7[0x48] == '\0' && (piVar7[0x49] == 0)))) {
      bVar12 = (*(byte *)(param_1 + 0x34) & 1) != (*(byte *)(param_1 + 0x2e) & 1);
      iVar4 = param_1[0x48];
      iVar11 = param_1[0x49];
      iVar1 = param_1[0x53];
      local_38 = param_1[0x58] - *(int *)(param_2 + 0x46c);
      if (local_38 < 0) {
        local_38 = 0;
      }
      iVar2 = param_1[0x25];
      iVar3 = param_1[0x26];
      iVar8 = FUN_0010b0f4(param_1,0);
      iVar8 = *(int *)(iVar8 + 0x10);
      iVar9 = FUN_0010a17a(0x12,*(undefined4 *)(param_2 + 8));
      FUN_0010b85e(iVar9,1,piVar6,1);
      FUN_0010b85e(iVar9,2,piVar7,1);
      *(int *)(iVar9 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
      *(undefined4 *)(iVar9 + 0x94) = *(undefined4 *)(iVar9 + 0x14c);
      *(undefined4 *)(iVar9 + 0x98) = 0;
      *(int *)(iVar9 + 0x9c) = DAT_001cc5a8;
      FUN_000e956e(param_1[0x56],param_1,iVar9);
      if (bVar12) {
        local_28 = (int *)FUN_0010a17a(0x37,*(undefined4 *)(param_2 + 8));
        local_28[0x58] = *(int *)(param_2 + 0x46c) + 1;
        local_28[0x25] = local_28[0x53];
        local_28[0x26] = 0;
        local_28[0x27] = DAT_001cc5a8;
        iVar10 = FUN_0010b0f4(local_28,1);
        *(undefined4 *)(iVar10 + 0x10) = DAT_001cc5a4;
        (**(code **)(*local_28 + 0x88))(local_28,1,3,3);
        FUN_000e956e(param_1[0x56],param_1,local_28);
        FUN_001a7d72(param_1);
        FUN_0010db52(param_1,0x31,*(undefined4 *)(param_2 + 8));
        FUN_0010ba02(param_1,1,local_28,0,*(undefined4 *)(param_2 + 8));
        FUN_000e9596(local_28[0x56],local_28,param_1);
        FUN_00109c0e(param_1 + 0x29,1,1);
      }
      else {
        FUN_001a7d72(param_1);
        FUN_0010d5e0(param_1,0x37,*(undefined4 *)(param_2 + 8));
        local_28 = param_1;
        FUN_000e9596(*(undefined4 *)(iVar9 + 0x158),iVar9,param_1);
      }
      FUN_0010ba02(local_28,1,iVar9,0,*(undefined4 *)(param_2 + 8));
      *(char *)(param_1 + 0x48) = (char)iVar4;
      param_1[0x49] = iVar11;
      param_1[0x53] = iVar1;
      param_1[0x58] = local_38 + *(int *)(param_2 + 0x46c);
      iVar11 = FUN_0010b0f4(param_1,0);
      *(int *)(iVar11 + 8) = iVar2;
      *(int *)(iVar11 + 0xc) = iVar3;
      param_1[0x27] = iVar8;
      if (bVar12) {
        local_20 = 0;
        do {
          iVar11 = FUN_0010b0f4(param_1,0);
          if (*(char *)(local_20 + 0x10 + iVar11) != '\x01') {
            (**(code **)(*param_1 + 0x88))(param_1,1,local_20,3);
          }
          local_20 = local_20 + 1;
        } while (local_20 != 4);
      }
      (**(code **)(*piVar6 + 0xc))(piVar6,0,*(undefined4 *)(param_2 + 8));
      (**(code **)(*piVar7 + 0xc))(piVar7,0,*(undefined4 *)(param_2 + 8));
      return 1;
    }
  }
  return 0;
}

/* FUN_0017342a @ 0x17342a (438 bytes) */
undefined4 FUN_0017342a(int param_1,int param_2,float param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_24 [4];
  float local_20;
  
  if (((((*(char *)(param_1 + 0x120) == '\0') && (*(int *)(param_1 + 0x124) == 0)) &&
       ((*(uint *)(param_1 + 0xb8) & 1) == 0)) &&
      (((*(uint *)(param_1 + 0xb8) & 2) == 0 && ((*(uint *)(param_1 + 0xd0) & 1) == 0)))) &&
     (((*(uint *)(param_1 + 0xd0) & 2) == 0 && (*(int *)(*(int *)(param_1 + 0x88) + 8) == param_2)))
     ) {
    iVar2 = FUN_0010b0f4(param_1,0);
    cVar1 = FUN_000f7e7e(param_1,1,*(undefined4 *)(iVar2 + 0x10),local_24);
    if (cVar1 != '\0') {
      if ((param_3 == local_20) && (!NAN(param_3) && !NAN(local_20))) {
        uVar4 = FUN_0010b180(param_1,2);
        iVar2 = FUN_0010b0f4(param_1,2);
        uVar3 = *(undefined4 *)(iVar2 + 0x10);
        uVar5 = FUN_0010b180(param_1,1);
        FUN_0010ba02(param_1,2,uVar5,0,param_4);
        iVar2 = FUN_0010b0f4(param_1,1);
        uVar5 = *(undefined4 *)(iVar2 + 0x10);
        iVar2 = FUN_0010b0f4(param_1,2);
        *(undefined4 *)(iVar2 + 0x10) = uVar5;
        FUN_0010ba02(param_1,1,uVar4,0,param_4);
        iVar2 = FUN_0010b0f4(param_1,1);
        *(undefined4 *)(iVar2 + 0x10) = uVar3;
        return uVar4;
      }
    }
    iVar2 = FUN_0010b0f4(param_1,0);
    cVar1 = FUN_000f7e7e(param_1,2,*(undefined4 *)(iVar2 + 0x10),local_24);
    if (cVar1 != '\0') {
      if ((param_3 == local_20) && (!NAN(param_3) && !NAN(local_20))) {
        uVar3 = FUN_0010b180(param_1,1);
        return uVar3;
      }
    }
  }
  return 0;
}

/* FUN_001735e0 @ 0x1735e0 (1699 bytes) */
int FUN_001735e0(param_1, param_2)
  int *param_1;
  int param_2;
{
  byte bVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 local_7c;
  int *local_74;
  int local_70;
  int local_64;
  int local_60;
  int local_58;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  iVar13 = *(int *)(param_2 + 8);
  cVar4 = (**(code **)(**(int **)(iVar13 + 0x54) + 0x80))(*(int **)(iVar13 + 0x54));
  if (cVar4 == '\0') {
    return 0;
  }
  local_70 = ((undefined4 (*)())FUN_0017342a)(param_1,0x17,0,iVar13);
  if (local_70 == 0) {
    local_70 = ((undefined4 (*)())FUN_0017342a)(param_1,0x19,0x3f800000,iVar13);
    if (local_70 == 0) {
      return 0;
    }
    local_74 = (int *)((undefined4 (*)())FUN_0017342a)(local_70,0x17,0,iVar13);
  }
  else {
    local_74 = (int *)((undefined4 (*)())FUN_0017342a)(local_70,0x19,0x3f800000,iVar13);
  }
  if (local_74 == (int *)0x0) {
    return 0;
  }
  if ((*(byte *)(local_70 + 0x15) & 2) != 0) {
    return 0;
  }
  if ((*(byte *)((int)local_74 + 0x15) & 2) == 0) {
    *(int *)(param_2 + 0x1a8) = *(int *)(param_2 + 0x1a8) + 1;
    iVar5 = FUN_0010b0f4(param_1,0);
    local_20[0] = *(undefined4 *)(iVar5 + 0x10);
    local_24 = DAT_001cc5a4;
    iVar5 = 0;
    do {
      if (*(char *)((int)local_20 + iVar5) != '\x01') {
        iVar6 = FUN_0010b0f4(param_1,1);
        bVar1 = *(byte *)(iVar5 + 0x10 + iVar6);
        iVar6 = FUN_0010b0f4(local_70,1);
        *(undefined1 *)((int)local_20 + iVar5 + -4) = *(undefined1 *)(bVar1 + 0x10 + iVar6);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != 4);
    iVar5 = *(int *)(param_2 + 0x46c);
    iVar6 = 0;
    if (-1 < param_1[0x58] - iVar5) {
      iVar6 = param_1[0x58] - iVar5;
    }
    local_44 = 0;
    local_40 = 0;
    local_30 = 0;
    uVar7 = FUN_0010b0f4(param_1,0);
    FUN_0010a40a(&local_44,uVar7);
    iVar2 = param_1[2];
    if (iVar5 < local_74[0x58]) {
      local_74[0x58] = local_74[0x58] + 1;
    }
    else {
      local_74[0x58] = iVar5 + 1;
    }
    FUN_0010b3fe(local_70,iVar13);
    if ((*(byte *)((int)param_1 + 0x15) & 2) == 0) {
      local_64 = 0;
    }
    else {
      local_64 = FUN_0010b180(param_1,param_1[0x21]);
    }
    local_7c = DAT_001cc5a0;
    if (local_64 != 0) {
      iVar8 = FUN_0010b0f4(param_1,param_1[0x21]);
      local_7c = *(undefined4 *)(iVar8 + 0x10);
    }
    FUN_001a7d72(param_1);
    local_60 = FUN_00119314(local_74[0x22],local_74,param_2);
    cVar4 = FUN_000f5a1e(param_1,1);
    if ((cVar4 == '\0') || (cVar4 = FUN_000f5a1e(local_70,1), cVar4 == '\0')) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    cVar4 = (**(code **)(*local_74 + 0x24))(local_74);
    if (((cVar4 == '\0') || (cVar4 = FUN_0010a62e(local_74,param_2), cVar4 == '\0')) ||
       ((!bVar3 &&
        ((((local_60 != 0 && (local_60 != 3)) && (local_60 != 4)) &&
         ((local_60 != 5 && (local_60 != 7)))))))) {
      FUN_0010db52(param_1,0x31,iVar13);
      FUN_0010ba02(param_1,1,local_74,0,iVar13);
      iVar8 = FUN_0010b0f4(param_1,1);
      *(undefined4 *)(iVar8 + 0x10) = DAT_001cc5a0;
      local_60 = 0;
      bVar3 = false;
    }
    else {
      if (0 < local_74[0x21]) {
        iVar8 = 1;
        do {
          iVar10 = FUN_0010b180(local_74,iVar8);
          if (iVar5 < *(int *)(iVar10 + 0x160)) {
            *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + 1;
          }
          else {
            *(int *)(iVar10 + 0x160) = iVar5 + 1;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 <= local_74[0x21]);
      }
      param_1 = (int *)FUN_00109cd4(local_74,param_1,iVar13,0);
      FUN_0010b3fe(local_74,iVar13);
      if (((*(byte *)(local_74 + 5) & 1) != 0) && (0 < local_74[0x21])) {
        local_58 = 1;
        do {
          piVar9 = (int *)FUN_0010b180(param_1,local_58);
          cVar4 = (**(code **)(*piVar9 + 0x5c))(piVar9);
          if (cVar4 != '\0') {
            iVar8 = iVar5 + 1;
            piVar9[0x58] = iVar8;
            iVar10 = FUN_0010a1c2(piVar9,iVar13,0);
            FUN_0010ba02(param_1,local_58,iVar10,0,iVar13);
            FUN_000e9596(piVar9[0x56],piVar9,iVar10);
            *(int *)(iVar10 + 0x160) = iVar8;
            uVar7 = *(undefined4 *)(iVar10 + 0x14c);
            iVar11 = FUN_0010b0f4(iVar10,0);
            *(undefined4 *)(iVar11 + 8) = uVar7;
            if (0 < *(int *)(iVar10 + 0x84)) {
              iVar11 = 1;
              do {
                iVar12 = FUN_0010b180(iVar10,iVar11);
                if (iVar5 < *(int *)(iVar12 + 0x160)) {
                  *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar12 + 0x160) = iVar8;
                }
                iVar11 = iVar11 + 1;
              } while (iVar11 <= *(int *)(iVar10 + 0x84));
            }
          }
          local_58 = local_58 + 1;
        } while (local_58 <= local_74[0x21]);
      }
    }
    param_1[0x58] = iVar5 + iVar6;
    uVar7 = FUN_0010b0f4(param_1,0);
    FUN_0010a40a(uVar7,&local_44);
    *(undefined1 *)(param_1 + 0x48) = 1;
    FUN_000e956e(*(undefined4 *)(iVar2 + 0x158),iVar2,param_1);
    if (local_64 != 0) {
      FUN_0010c18e(param_1,local_64,0,iVar13);
      iVar13 = FUN_0010b0f4(param_1,param_1[0x21]);
      *(undefined4 *)(iVar13 + 0x10) = local_7c;
    }
    if ((!bVar3) && (local_60 == 0)) {
      for (iVar13 = 1; iVar5 = (**(code **)(*param_1 + 0x14))(param_1), iVar13 <= iVar5;
          iVar13 = iVar13 + 1) {
        iVar5 = FUN_0010b0f4(param_1,iVar13);
        uVar7 = DAT_001cc5a4;
        local_28 = *(undefined4 *)(iVar5 + 0x10);
        local_2c = DAT_001cc5a4;
        iVar5 = 1;
        do {
          if (*(char *)((int)local_20 + iVar5 + -1) == '\0') {
            *(undefined1 *)((int)&local_30 + iVar5 + 3) =
                 *(undefined1 *)((int)&local_28 + (uint)*(byte *)((int)&local_28 + iVar5 + 3));
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 != 5);
        iVar5 = FUN_0010b0f4(param_1,iVar13);
        *(undefined4 *)(iVar5 + 0x10) = uVar7;
      }
    }
    return 1;
  }
  return 0;
}

/* FUN_00173c8c @ 0x173c8c (342 bytes) */
int FUN_00173c8c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(char *)(param_1 + 0x21) == '\0') {
      cVar1 = *(char *)(param_2 + 0x1c);
      if (cVar1 == *(char *)(param_3 + 0x1c)) {
        iVar2 = *(int *)(param_2 + 0x14) - *(int *)(param_3 + 0x14);
        if (iVar2 != 0) {
          return iVar2;
        }
        cVar1 = *(char *)(param_3 + 0x5c);
        if (*(char *)(param_2 + 0x5c) == cVar1) {
          iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x60))(*(int **)(param_1 + 8),param_2);
          iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x60))(*(int **)(param_1 + 8),param_3);
          if (iVar2 - iVar3 != 0) {
            return iVar2 - iVar3;
          }
          iVar2 = *(int *)(param_2 + 0xc) - *(int *)(param_3 + 0xc);
          goto joined_r0x00173d79;
        }
      }
    }
    else {
      cVar1 = *(char *)(param_2 + 0x1c);
      if (cVar1 == *(char *)(param_3 + 0x1c)) {
        iVar2 = (**(code **)(**(int **)(param_1 + 8) + 100))(*(int **)(param_1 + 8),param_2);
        iVar3 = (**(code **)(**(int **)(param_1 + 8) + 100))(*(int **)(param_1 + 8),param_3);
        if (iVar2 - iVar3 != 0) {
          return iVar2 - iVar3;
        }
        iVar2 = *(int *)(param_2 + 0xc) - *(int *)(param_3 + 0xc);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar2 = *(int *)(param_2 + 0x14) - *(int *)(param_3 + 0x14);
joined_r0x00173d79:
        if (iVar2 != 0) {
          return iVar2;
        }
        return *(int *)(param_3 + 0x10) - *(int *)(param_2 + 0x10);
      }
    }
  }
  else {
    iVar2 = *(int *)(param_2 + 0x10) - *(int *)(param_3 + 0x10);
    if (iVar2 != 0) {
      return -iVar2;
    }
    iVar2 = *(int *)(param_2 + 0xc) - *(int *)(param_3 + 0xc);
    if (iVar2 != 0) {
      return iVar2;
    }
    cVar1 = *(char *)(param_2 + 0x1c);
    if (cVar1 == *(char *)(param_3 + 0x1c)) {
      iVar2 = *(int *)(param_2 + 0x14) - *(int *)(param_3 + 0x14);
      if (iVar2 != 0) {
        return iVar2;
      }
      cVar1 = *(char *)(param_3 + 0x5c);
      if (*(char *)(param_2 + 0x5c) == cVar1) {
        return 0;
      }
    }
  }
  if (cVar1 == '\0') {
    iVar2 = -1;
  }
  else {
    iVar2 = 1;
  }
  return iVar2;
}

/* FUN_00173de2 @ 0x173de2 (252 bytes) */
int FUN_00173de2(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x114) != '\0') {
    cVar1 = FUN_001a7c84(param_1 + 0x30);
    if (cVar1 == '\0') {
      if ((*(int *)(param_1 + 0x24) <= *(int *)(param_1 + 0x128)) &&
         (cVar1 = FUN_001a7c84(param_1 + 0x48), cVar1 == '\0')) {
        *(bool *)(param_1 + 0x114) = *(int *)(param_1 + 0x10c) <= param_3;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x114) = 0;
    }
    if (*(char *)(param_1 + 0x114) != '\0') {
      return;
    }
    *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(param_1 + 0x28);
    return;
  }
  cVar1 = FUN_001a7c84(param_1 + 0x48);
  if (cVar1 == '\0') {
    cVar1 = FUN_001a7c84(param_1 + 0x30);
    if ((cVar1 != '\0') ||
       ((*(int *)(param_1 + 0x11c) < *(int *)(param_1 + 0x118) &&
        (param_2 < *(int *)(param_1 + 0x24))))) goto LAB_00173e39;
    iVar2 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x120);
    if (iVar2 < 8) {
      *(bool *)(param_1 + 0x114) = *(int *)(param_1 + 0x10c) - iVar2 < param_3;
      goto LAB_00173e39;
    }
  }
  *(undefined1 *)(param_1 + 0x114) = 1;
LAB_00173e39:
  if (*(char *)(param_1 + 0x114) != '\0') {
    *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x11c);
    *(undefined4 *)(param_1 + 0x128) = 0;
  }
  return;
}

/* FUN_00173ede @ 0x173ede (48 bytes) */
int FUN_00173ede(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((*(int *)(param_1 + 0x94) == *(int *)(param_2 + 0x94)) &&
     (*(int *)(param_1 + 0x98) == *(int *)(param_2 + 0x98))) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_00173f0e @ 0x173f0e (23 bytes) */
int FUN_00173f0e(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x98) * 0x10000 + *(int *)(param_1 + 0x94);
}

/* FUN_00173f26 @ 0x173f26 (515 bytes) */
int FUN_00173f26(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  int iVar7;
  int local_60;
  uint local_44;
  int local_24;
  uint local_20 [5];
  
  cVar1 = param_4;
  if (param_4 == '\0') {
    iVar4 = 1;
    piVar6 = param_1;
    do {
      local_20[iVar4] = piVar6[0x53];
      iVar4 = iVar4 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar4 != 5);
    uVar2 = param_1[0x50];
    iVar4 = param_1[0x67];
  }
  else {
    iVar4 = 1;
    piVar6 = param_1;
    do {
      local_20[iVar4] = piVar6[0x57];
      iVar4 = iVar4 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar4 != 5);
    piVar6 = *(int **)(*param_1 + 0x54);
    uVar2 = (**(code **)(*piVar6 + 0x13c))(piVar6,*param_1);
    iVar4 = param_1[0x68];
  }
  if ((int)uVar2 < 1) {
    local_20[0] = 0xffffffff;
  }
  else {
    local_24 = 0x7fffffff;
    local_20[0] = 0xffffffff;
    local_44 = 0;
    do {
      if ((cVar1 != '\0') ||
         ((*(uint *)(param_1[0x4b] + 8 + (local_44 >> 5) * 4) >> ((byte)local_44 & 0x1f) & 1) != 0))
      {
        if (iVar4 < (int)local_44) {
          if (-1 < (int)local_20[0]) goto LAB_001740a5;
          local_20[0] = local_44;
          break;
        }
        local_60 = 0x7fffffff;
        iVar7 = 1;
        pcVar5 = (char *)&param_2;
        do {
          if (*pcVar5 != '\0') {
            iVar3 = param_3 - *(int *)(local_20[iVar7] + local_44 * 4);
            if (local_60 <= iVar3) {
              iVar3 = local_60;
            }
            local_60 = iVar3;
            if (iVar3 < 0) goto LAB_0017408a;
          }
          iVar7 = iVar7 + 1;
          pcVar5 = pcVar5 + 1;
        } while (iVar7 != 5);
        if ((-1 < local_60) && (local_60 < local_24)) {
          local_20[0] = local_44;
          local_24 = local_60;
        }
      }
LAB_0017408a:
      local_44 = local_44 + 1;
    } while (uVar2 != local_44);
    if (-1 < (int)local_20[0]) {
LAB_001740a5:
      if (cVar1 == '\0') {
        uVar2 = param_1[0x67];
        if (param_1[0x67] < (int)local_20[0]) {
          uVar2 = local_20[0];
        }
        param_1[0x67] = uVar2;
      }
      else {
        uVar2 = param_1[0x68];
        if (param_1[0x68] < (int)local_20[0]) {
          uVar2 = local_20[0];
        }
        param_1[0x68] = uVar2;
      }
      iVar4 = 1;
      pcVar5 = (char *)&param_2;
      do {
        if (*pcVar5 != '\0') {
          *(int *)(local_20[iVar4] + local_20[0] * 4) = param_1[10];
        }
        iVar4 = iVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (iVar4 != 5);
      return local_20[0];
    }
  }
  return local_20[0];
}

