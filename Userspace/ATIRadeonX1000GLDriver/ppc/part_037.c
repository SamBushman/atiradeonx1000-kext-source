#include "decls.h"

/* FUN_0015f44c @ 0x15f44c (3792 bytes) */
int FUN_0015f44c(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int *param_3;
  int param_4;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  float fVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  int *piVar16;
  undefined4 uVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_b8[0];
  undefined4 local_b4;
  undefined4 local_b0;
  int local_ac;
  undefined4 local_a8;
  int local_a0 [5];
  undefined4 *local_8c;
  undefined4 *local_88[0];
  undefined4 *local_84;
  undefined4 *local_80;
  undefined4 *local_7c;
  undefined4 local_70;
  
  piVar16 = (int *)0x0;
  if ((param_3[5] & 0x200U) != 0) {
    piVar16 = (int *)FUN_00105594(param_3,param_3[0x21]);
  }
  uVar14 = *(undefined4 *)(param_4 + 8);
  if ((piVar16 == (int *)0x0) || (iVar6 = (**(code **)(*piVar16 + 0x60))(piVar16), iVar6 == 0)) {
    if ((param_1 != 0) &&
       (((param_3 != (int *)0x0 && (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x8e)) &&
        (iVar6 = (**(code **)(*param_3 + 0x60))(param_3), iVar6 != 0)))) {
      iVar11 = FUN_001084b8(0x31,*(undefined4 *)(param_4 + 8));
      iVar6 = *(int *)(param_4 + 0x478);
      *(undefined4 *)(iVar11 + 0x98) = 0;
      *(int *)(iVar11 + 0x160) = iVar6 + 1;
      *(undefined4 *)(iVar11 + 0x94) = *(undefined4 *)(iVar11 + 0x14c);
      FUN_00106004(iVar11,1,param_3,0,*(undefined4 *)(param_4 + 8));
      iVar6 = FUN_001054ec(param_3,0);
      *(undefined4 *)(iVar11 + 0x9c) = *(undefined4 *)(iVar6 + 0x10);
      FUN_000f4698(iVar11,1,param_4);
      FUN_000e7738(param_3[0x56],param_3,iVar11);
      *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) | 0x80000000;
      FUN_00106004(param_1,param_2,iVar11,0,*(undefined4 *)(param_4 + 8));
      return 0;
    }
    return 0;
  }
  iVar6 = FUN_001054ec(param_3,param_3[0x21]);
  uVar12 = *(undefined4 *)(iVar6 + 0x10);
  iVar6 = FUN_001054ec(piVar16,0);
  local_c8 = *(undefined4 *)(iVar6 + 0x10);
  if (0 < param_3[0x21]) {
    iVar6 = 1;
    do {
      iVar11 = FUN_00105594(param_3,iVar6);
      if ((*(int *)(iVar11 + 0x98) != 0x33) ||
         (iVar11 = FUN_00105594(param_3,iVar6), *(int *)(iVar11 + 300) == 3)) {
        bVar1 = true;
        goto LAB_0015f564;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 <= param_3[0x21]);
  }
  bVar1 = false;
LAB_0015f564:
  iVar6 = *(int *)(param_3[0x22] + 8);
  if (!bVar1) goto LAB_0015fd14;
  piVar7 = (int *)FUN_00105594(piVar16,1);
  if (((piVar7[0x20] == 0) || (iVar11 = FUN_00126760(piVar7[0x26]), iVar11 == 0)) ||
     (((piVar7[5] & 2U) != 0 || (iVar11 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar11 != 0)))) {
    iVar11 = FUN_001054ec(piVar16,1);
    uVar17 = *(undefined4 *)(iVar11 + 0x10);
    iVar11 = FUN_001054ec(param_3,0);
    iVar11 = FUN_00146624(uVar17,*(undefined4 *)(iVar11 + 0x10));
    if (iVar11 != 0) goto LAB_0015f5cc;
  }
  else {
LAB_0015f5cc:
    if (iVar6 - 0x12U < 3) {
      iVar11 = (**(code **)(*piVar16 + 0x14))(piVar16);
      local_a0[1] = 0;
      local_b0 = 0;
      local_ac = 0;
      if (iVar11 < 1) {
        local_a0[2] = 0;
        local_a0[4] = 0;
        local_a0[3] = 0;
        goto LAB_0015f7bc;
      }
      iVar15 = 1;
      local_a0[4] = 0;
      uVar13 = 0;
      local_a0[3] = 0;
      do {
        iVar9 = FUN_00105594(piVar16,iVar15);
        if (*(int *)(iVar9 + 0x98) == 0x33) {
          iVar18 = FUN_001054ec(piVar16,iVar15);
          uVar21 = 0;
          local_bc = *(undefined4 *)(iVar18 + 0x10);
          do {
            bVar4 = *(byte *)((int)&local_bc + uVar21);
            if ((bVar4 != 4) &&
               (iVar18 = FUN_001054ec(param_3,0), *(char *)(uVar21 + iVar18 + 0x10) == '\x01')) {
              fVar5 = *(float *)((uint)bVar4 * 0x18 + iVar9 + 0x20);
              local_70 = 0;
              if (fVar5 == 0.0) {
                local_a0[3] = local_a0[3] | 1 << (uVar21 & 0x3f);
              }
              else {
                local_70 = 0x3f800000;
                if (fVar5 == 1.0) {
                  local_a0[4] = local_a0[4] | 1 << (uVar21 & 0x3f);
                }
                else {
                  uVar13 = uVar13 | 1 << (uVar21 & 0x3f);
                }
              }
            }
            bVar1 = uVar21 != 3;
            uVar21 = uVar21 + 1;
          } while (bVar1);
        }
        else {
          FUN_00104d3c(param_3,&local_b0);
          local_ac = iVar9;
        }
        iVar15 = iVar15 + 1;
      } while (iVar15 <= iVar11);
      local_a0[2] = 0;
      if ((local_a0[4] != 0) &&
         ((1 < iVar6 - 0x13U || (local_a0[2] = 6, (param_3[0x2e] & 1U) != (param_3[0x34] & 1U))))) {
        if (iVar6 == 0x12) {
          local_a0[2] = 2;
          if ((param_3[0x34] & 1U) != 0) {
            uVar21 = param_3[0x2e];
            local_a0[2] = 4;
            goto joined_r0x0015f784;
          }
        }
        else {
          if (iVar6 == 0x14) {
            uVar21 = param_3[0x3a];
            local_a0[2] = 1;
joined_r0x0015f784:
            if ((uVar21 & 1) == 0) goto LAB_0015f7a8;
          }
          local_a0[2] = -1;
        }
      }
LAB_0015f7a8:
      if ((uVar13 == 0) && (-1 < local_a0[2])) {
LAB_0015f7bc:
        uVar13 = 2;
        bVar1 = local_a0[4] == 0;
        iVar11 = FUN_001054ec(param_3,0);
        local_8c = &local_bc;
        local_88[0] = &local_c8;
        local_bc = *(undefined4 *)(iVar11 + 0x10);
        local_84 = local_8c;
        local_80 = local_88[0];
        local_7c = local_8c;
        do {
          iVar15 = 3 - uVar13;
          iVar11 = (**(code **)(*param_3 + 0x14))(param_3);
          if (iVar11 < iVar15) {
            FUN_00106004(param_3,param_3[0x21],0,0,uVar14);
            param_3[0x21] = param_3[0x21] + -1;
            param_3[5] = param_3[5] & 0xfffffdff;
            if (local_ac != 0) {
              iVar6 = FUN_001054ec(param_3,0);
              iVar11 = 0;
              piVar7 = local_a0;
              local_b8[0] = *(int *)(iVar6 + 0x10);
              iVar6 = 4;
              do {
                if (*(char *)((int)&local_b8 + iVar11) != '\x01') {
                  *(undefined1 *)piVar7 = 4;
                }
                iVar11 = iVar11 + 1;
                piVar7 = (int *)((int)piVar7 + 1);
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
              if (local_a0[0] != DAT_001b0050) {
                FUN_00106b48(param_3,&local_b0,0,uVar14);
                if (*(int *)(param_4 + 0x478) < *(int *)(local_ac + 0x160)) {
                  *(int *)(local_ac + 0x160) = *(int *)(local_ac + 0x160) + 1;
                }
                else {
                  *(int *)(local_ac + 0x160) = *(int *)(param_4 + 0x478) + 1;
                }
              }
            }
            (**(code **)(*param_3 + 0x14))(param_3);
            FUN_00105894(piVar16,uVar14);
            return 1;
          }
          uVar12 = FUN_00105594(param_3,iVar15);
          if ((bVar1) || ((local_a0[3] == 0 && (iVar6 == 0x13)))) {
            uVar21 = local_a0[2] >> (uVar13 & 0x3f);
            if ((uVar21 & 1) == 0) goto LAB_0015f88c;
            iVar11 = 2;
            dVar24 = (double)FLOAT_001aa0e8;
          }
          else {
            uVar21 = local_a0[2] >> (uVar13 & 0x3f);
            if ((uVar21 & 1) == 0) {
LAB_0015f88c:
              iVar11 = 2;
              dVar24 = (double)FLOAT_001aa0d4;
            }
            else {
              iVar11 = 3;
              dVar24 = (double)FLOAT_001aa0e8;
            }
          }
          bVar3 = local_a0[3] != 0;
          iVar18 = 0;
          piVar8 = (int *)((int (*)())FUN_0010bed0)(dVar24,iVar11,DAT_001b0174,uVar12,param_4,uVar14);
          iVar9 = FUN_001054ec(param_3,iVar15);
          local_b8[0] = *(int *)(iVar9 + 0x10);
          piVar7 = piVar8;
          do {
            if (*(char *)((int)&local_b8 + iVar18) != '\x04') {
              (**(code **)(*piVar8 + 0x88))(piVar8,1,iVar18);
              *(undefined1 *)(piVar7 + 0x27) = 0;
              (**(code **)(*param_3 + 0x88))(param_3,iVar15,iVar18,iVar18);
            }
            bVar2 = iVar18 != 3;
            piVar7 = (int *)((int)piVar7 + 1);
            iVar18 = iVar18 + 1;
          } while (bVar2);
          dVar22 = (double)FLOAT_001aa0d4;
          dVar23 = (double)FLOAT_001aa0e8;
          iVar9 = -1;
          iVar18 = -1;
          iVar19 = 0;
          piVar7 = piVar8;
          do {
            iVar10 = FUN_001054ec(piVar8,1);
            if ((*(char *)(iVar19 + iVar10 + 0x10) == '\x04') &&
               (*(char *)(iVar19 + (int)local_8c) == '\x01')) {
              if ((iVar11 == 3) || (dVar24 == dVar23)) {
                if (iVar9 < 0) {
                  (**(code **)(*piVar8 + 0x88))(piVar8,2,iVar19,iVar19);
                  *(undefined1 *)(piVar7 + 0x27) = 0;
                  iVar9 = iVar19;
                  goto LAB_0015fa2c;
                }
                if (iVar11 != 3) goto LAB_0015f9e8;
              }
              else {
LAB_0015f9e8:
                if (dVar24 != dVar22) break;
              }
              if (-1 < iVar18) break;
              (**(code **)(*piVar8 + 0x88))(piVar8,iVar11,iVar19,iVar19);
              *(undefined1 *)(piVar7 + 0x27) = 0;
              iVar18 = iVar19;
            }
LAB_0015fa2c:
            bVar2 = iVar19 != 3;
            piVar7 = (int *)((int)piVar7 + 1);
            iVar19 = iVar19 + 1;
          } while (bVar2);
          if (!bVar1) {
            uVar20 = 0;
            piVar7 = param_3;
            do {
              if ((((local_a0[4] >> (uVar20 & 0x3f) & 1U) != 0) &&
                  (*(char *)(uVar20 + (int)local_88[0]) != '\x01')) &&
                 (*(char *)(uVar20 + (int)local_84) == '\x01')) {
                if ((uVar21 & 1) == 0) {
                  (**(code **)(*param_3 + 0x88))(param_3,iVar15,uVar20,iVar18);
                }
                else {
                  (**(code **)(*param_3 + 0x88))(param_3,iVar15,uVar20,iVar9);
                }
                *(undefined1 *)(piVar7 + 0x27) = 0;
              }
              bVar2 = uVar20 != 3;
              piVar7 = (int *)((int)piVar7 + 1);
              uVar20 = uVar20 + 1;
            } while (bVar2);
          }
          if (bVar3) {
            uVar21 = 0;
            piVar7 = param_3;
            do {
              if ((((local_a0[3] >> (uVar21 & 0x3f) & 1U) != 0) &&
                  (*(char *)(uVar21 + (int)local_80) != '\x01')) &&
                 (*(char *)(uVar21 + (int)local_7c) == '\x01')) {
                (**(code **)(*param_3 + 0x88))(param_3,iVar15,uVar21,iVar18);
                *(undefined1 *)(piVar7 + 0x27) = 0;
              }
              bVar3 = uVar21 != 3;
              piVar7 = (int *)((int)piVar7 + 1);
              uVar21 = uVar21 + 1;
            } while (bVar3);
          }
          piVar7 = (int *)FUN_00105594(piVar8,1);
          iVar11 = (**(code **)(*piVar7 + 0x60))();
          if (iVar11 != 0) {
            uVar12 = FUN_00105594(piVar8,1);
            FUN_0010c670(uVar12,piVar8,uVar14);
          }
          uVar13 = uVar13 - 1;
          FUN_000e7700(param_3[0x56],param_3,piVar8);
          FUN_00106004(param_3,iVar15,piVar8,0,uVar14);
        } while( true );
      }
    }
  }
  if ((piVar16[0x26] != 0x33) ||
     (iVar6 = FUN_00105594(param_3,param_3[0x21]), *(int *)(iVar6 + 300) == 3)) {
    iVar11 = FUN_001084b8(0x31,*(undefined4 *)(param_4 + 8));
    iVar6 = *(int *)(param_4 + 0x478);
    *(undefined4 *)(iVar11 + 0x98) = 0;
    *(int *)(iVar11 + 0x160) = iVar6 + 1;
    *(undefined4 *)(iVar11 + 0x94) = *(undefined4 *)(iVar11 + 0x14c);
    FUN_00106004(iVar11,1,piVar16,0,*(undefined4 *)(param_4 + 8));
    uVar14 = FUN_00105594(param_3,param_3[0x21]);
    iVar6 = FUN_001054ec(uVar14,0);
    *(undefined4 *)(iVar11 + 0x9c) = *(undefined4 *)(iVar6 + 0x10);
    FUN_000f4698(iVar11,1,param_4);
    iVar6 = param_3[0x21];
    *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) | 0x80000000;
    iVar6 = FUN_00105594(param_3,iVar6);
    uVar17 = *(undefined4 *)(iVar6 + 0x158);
    uVar14 = FUN_00105594(param_3,param_3[0x21]);
    FUN_000e7738(uVar17,uVar14,iVar11);
    FUN_00106804(param_3,iVar11,0,*(undefined4 *)(param_4 + 8));
    iVar6 = FUN_001054ec(param_3,param_3[0x21]);
    *(undefined4 *)(iVar6 + 0x10) = uVar12;
    return 1;
  }
LAB_0015fd14:
  FUN_00106004(param_3,param_3[0x21],0,0,*(undefined4 *)(param_4 + 8));
  iVar6 = piVar16[0x58];
  param_3[0x21] = param_3[0x21] + -1;
  param_3[5] = param_3[5] & 0xfffffdff;
  piVar16[0x58] = iVar6 + -1;
  iVar6 = FUN_001049c4(piVar16,param_4);
  bVar1 = iVar6 != 0;
  if (bVar1) {
    (**(code **)(*piVar16 + 0xc))(piVar16,0,*(undefined4 *)(param_4 + 8));
  }
  local_a8 = 0;
  local_b0 = 0;
  local_ac = 0;
  FUN_00103f18(param_3,&local_b0,0xffffffff);
  iVar6 = FUN_0010445c(param_3,*(undefined4 *)(param_4 + 8),0);
  FUN_000e7738(*(undefined4 *)(param_3[1] + 0x158),param_3[1],iVar6);
  *(int *)(iVar6 + 0x160) = *(int *)(param_4 + 0x478) + 1;
  *(undefined4 *)(iVar6 + 0x94) = *(undefined4 *)(iVar6 + 0x14c);
  FUN_0010a1c0(param_3,0xa2,*(undefined4 *)(param_4 + 8));
  uVar14 = *(undefined4 *)(iVar6 + 0x158);
  param_3[0x21] = piVar16[0x21] + 1;
  FUN_000e7738(uVar14,iVar6,param_3);
  iVar11 = FUN_001054ec(iVar6,0);
  local_b8[0] = *(int *)(iVar11 + 0x10);
  iVar11 = FUN_001054ec(piVar16,0);
  iVar15 = 0;
  local_c0 = *(undefined4 *)(iVar11 + 0x10);
  iVar11 = 4;
  do {
    if (*(char *)((int)&local_c0 + iVar15) != '\x01') {
      *(char *)((int)&local_b8 + iVar15) = *(char *)((int)&local_c0 + iVar15);
    }
    iVar15 = iVar15 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  iVar11 = FUN_00105594(piVar16,1);
  if (*(int *)(iVar11 + 0x98) == 0) {
    FUN_00106804(iVar6,iVar11,0,*(undefined4 *)(param_4 + 8));
    if (!bVar1) {
      if (*(int *)(param_4 + 0x478) < *(int *)(iVar11 + 0x160)) {
        *(int *)(iVar11 + 0x160) = *(int *)(iVar11 + 0x160) + 1;
      }
      else {
        *(int *)(iVar11 + 0x160) = *(int *)(param_4 + 0x478) + 1;
      }
    }
    param_3[0x21] = param_3[0x21] + -1;
    FUN_00106004(param_3,1,iVar6,0,*(undefined4 *)(param_4 + 8));
    uVar14 = DAT_001b004c;
    iVar11 = FUN_001054ec(param_3,1);
    iVar15 = 2;
    *(undefined4 *)(iVar11 + 0x10) = uVar14;
  }
  else {
    FUN_00106004(param_3,2,iVar6,0,*(undefined4 *)(param_4 + 8));
    uVar14 = DAT_001b004c;
    iVar15 = FUN_001054ec(param_3,2);
    *(undefined4 *)(iVar15 + 0x10) = uVar14;
    FUN_00106004(param_3,1,iVar11,0,*(undefined4 *)(param_4 + 8));
    iVar11 = FUN_001054ec(piVar16,1);
    uVar14 = *(undefined4 *)(iVar11 + 0x10);
    iVar11 = FUN_001054ec(param_3,1);
    iVar15 = 3;
    *(undefined4 *)(iVar11 + 0x10) = uVar14;
  }
  iVar11 = FUN_001054ec(iVar6,0);
  local_b4 = *(undefined4 *)(iVar11 + 0x10);
  if (1 < piVar16[0x21]) {
    iVar11 = 2;
    do {
      uVar14 = FUN_00105594(piVar16,iVar11);
      FUN_00106004(param_3,iVar15,uVar14,0,*(undefined4 *)(param_4 + 8));
      if (!bVar1) {
        iVar9 = FUN_00105594(piVar16,iVar11);
        if (*(int *)(param_4 + 0x478) < *(int *)(iVar9 + 0x160)) {
          *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
        }
        else {
          *(int *)(iVar9 + 0x160) = *(int *)(param_4 + 0x478) + 1;
        }
      }
      iVar9 = FUN_001054ec(piVar16,iVar11);
      iVar9 = *(int *)(iVar9 + 0x10);
      if (iVar15 == 0) {
        param_3[0x27] = iVar9;
      }
      else {
        iVar18 = FUN_001054ec(param_3,iVar15);
        *(int *)(iVar18 + 0x10) = iVar9;
      }
      iVar18 = FUN_001054ec(piVar16,iVar11);
      iVar9 = 0;
      local_bc = *(undefined4 *)(iVar18 + 0x10);
      iVar18 = 4;
      do {
        if (*(char *)((int)&local_b4 + iVar9) != '\x04') {
          *(undefined1 *)((int)&local_bc + iVar9) = 4;
        }
        uVar14 = local_bc;
        iVar9 = iVar9 + 1;
        iVar18 = iVar18 + -1;
      } while (iVar18 != 0);
      iVar11 = iVar11 + 1;
      iVar9 = FUN_001054ec(param_3,iVar15);
      iVar15 = iVar15 + 1;
      *(undefined4 *)(iVar9 + 0x10) = uVar14;
    } while (iVar11 <= piVar16[0x21]);
  }
  param_3[0x27] = local_b8[0];
  param_3[0x25] = param_3[0x53];
  param_3[0x26] = 0x36;
  FUN_00103f44(param_3,&local_b0);
  param_3[0x56] = *(int *)(iVar6 + 0x158);
  local_c4 = 0;
  FUN_0014abdc(param_3,param_4,&local_c4);
  ((int (*)())FUN_00160320)(param_1,param_2,param_3,param_4,&local_c4);
  return 1;
}

/* FUN_00160320 @ 0x160320 (2960 bytes) */
int FUN_00160320(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int *param_3;
  int param_4;
  undefined4 *param_5;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int *piVar8;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_58;
  uint local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  uint local_30;
  uint local_2c;
  uint local_28;
  undefined4 local_24;
  
  iVar2 = (**(code **)(*param_3 + 0x60))(param_3);
  if (iVar2 != 0) {
    param_3 = (int *)FUN_00105594(param_3,1);
  }
  iVar2 = (**(code **)(*param_3 + 100))(param_3);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = FUN_00126760(param_3[0x26]);
  if (iVar2 == 0) {
    return 0;
  }
  if (((((param_3[5] & 0x200U) != 0) && (iVar2 = FUN_000f31e8(param_3,1), iVar2 != 0)) &&
      (param_3[0x48] == 0)) &&
     (((param_3[0x49] == 0 && ((param_3[0x2e] & 1U) == 0)) && ((param_3[0x2e] & 2U) == 0)))) {
    if (((param_3[0x20] != 0) && (iVar2 = FUN_00126760(param_3[0x26]), iVar2 != 0)) &&
       (((param_3[5] & 2U) == 0 && (iVar2 = (**(code **)(*param_3 + 0x50))(param_3), iVar2 == 0))))
    {
      iVar2 = 4;
      piVar8 = param_3;
      do {
        if (*(byte *)(piVar8 + 0x27) - 2 < 2) goto LAB_001605dc;
        piVar8 = (int *)((int)piVar8 + 1);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    if (*(int *)(param_4 + 0x17c) < *(int *)(*(int *)(param_4 + 8) + 0x660)) {
      iVar3 = FUN_00105594(param_3,1);
      iVar4 = FUN_00105594(param_3,param_3[0x21]);
      iVar2 = FUN_001054ec(param_3,0);
      local_60 = *(undefined4 *)(iVar2 + 0x10);
      iVar5 = FUN_001054ec(iVar4,0);
      iVar2 = 0;
      local_64 = *(undefined4 *)(iVar5 + 0x10);
      iVar5 = 4;
      do {
        if ((*(char *)((int)&local_60 + iVar2) != '\x01') &&
           (*(char *)((int)&local_64 + iVar2) != '\x01')) goto LAB_001605dc;
        iVar2 = iVar2 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      if (((*(uint *)(iVar4 + 0x14) & 0x200) != 0) &&
         (iVar2 = FUN_00105594(iVar4,*(undefined4 *)(iVar4 + 0x84)), iVar3 == iVar2)) {
        *(int *)(param_4 + 0x17c) = *(int *)(param_4 + 0x17c) + 1;
        iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
        if ((iVar2 < param_2) &&
           (((param_1[5] & 0x200U) != 0 &&
            (piVar8 = (int *)FUN_00105594(param_1,param_1[0x21]), param_3 == piVar8)))) {
          FUN_00106804(param_1,iVar4,0,*(undefined4 *)(param_4 + 8));
          iVar3 = *(int *)(param_4 + 0x478);
          iVar2 = *(int *)(iVar4 + 0x160);
          if (iVar3 < iVar2) {
LAB_00160588:
            *(int *)(iVar4 + 0x160) = iVar2 + 1;
            goto LAB_00160590;
          }
        }
        else {
          FUN_00106004(param_1,param_2,iVar4,0,*(undefined4 *)(param_4 + 8));
          iVar3 = *(int *)(param_4 + 0x478);
          iVar2 = *(int *)(iVar4 + 0x160);
          if (iVar3 < iVar2) goto LAB_00160588;
        }
        *(int *)(iVar4 + 0x160) = iVar3 + 1;
LAB_00160590:
        FUN_00105894(param_3,*(undefined4 *)(param_4 + 8));
        *param_5 = 1;
        return 1;
      }
    }
  }
LAB_001605dc:
  iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
  if (param_2 <= iVar2) {
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
    if (((param_2 <= iVar2) && (param_3[0x48] == 0)) && (param_3[0x49] == 0)) {
      if (((param_3[0x20] != 0) && (iVar2 = FUN_00126760(param_3[0x26]), iVar2 != 0)) &&
         (((param_3[5] & 2U) == 0 && (iVar2 = (**(code **)(*param_3 + 0x50))(param_3), iVar2 == 0)))
         ) {
        iVar2 = 4;
        piVar8 = param_3;
        do {
          if (*(byte *)(piVar8 + 0x27) - 2 < 2) {
            return 0;
          }
          piVar8 = (int *)((int)piVar8 + 1);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      FUN_001054ec(param_3,0);
      iVar2 = FUN_00105dbc(param_3,0);
      if (((iVar2 == 0) && (*(int *)(param_1[0x22] + 8) != 0x8e)) &&
         (iVar2 = (**(code **)(*param_1 + 0x60))(param_1), iVar2 == 0)) {
        iVar2 = (**(code **)(*param_1 + 0x28))(param_1);
        if (iVar2 != 0) {
          piVar8 = (int *)FUN_00105594(param_3,1);
          iVar2 = (**(code **)(*piVar8 + 0x5c))();
          if (iVar2 != 0) {
            return 0;
          }
        }
        iVar2 = (**(code **)(*param_1 + 0x28))(param_1);
        if (iVar2 != 0) {
          iVar2 = FUN_00105594(param_3,1);
          if (iVar2 == 0) {
            iVar2 = param_3[0x2c];
          }
          else {
            iVar2 = FUN_00105594(param_3,1);
            iVar2 = *(int *)(iVar2 + 0x98);
          }
          iVar2 = FUN_00126708(iVar2);
          if (iVar2 != 0) {
            return 0;
          }
        }
        if (*(int *)(param_4 + 0x17c) < *(int *)(*(int *)(param_4 + 8) + 0x660)) {
          piVar8 = (int *)FUN_00105594(param_1,param_2);
          if (param_3 == piVar8) {
            iVar2 = FUN_001054ec(piVar8,0);
            FUN_000f3908(&local_30,*(undefined4 *)(iVar2 + 0x10));
            local_5c = local_30;
          }
          else {
            iVar2 = (**(code **)(*piVar8 + 0x60))();
            if (iVar2 == 0) {
              return 0;
            }
            piVar7 = (int *)FUN_00105594(piVar8,1);
            if (param_3 != piVar7) {
              return 0;
            }
            iVar2 = FUN_001054ec(piVar8,0);
            FUN_000f3908(&local_2c,*(undefined4 *)(iVar2 + 0x10));
            local_5c = local_2c;
          }
          iVar2 = FUN_001054ec(param_3,1);
          local_58 = *(undefined4 *)(iVar2 + 0x10);
          if ((param_3[5] & 0x200U) == 0) {
            iVar2 = FUN_001054ec(param_1,param_2);
            FUN_000f3398(&local_28,*(undefined4 *)(iVar2 + 0x10));
            local_54 = local_28;
            if (((local_5c << 0x18 | (local_5c >> 8 & 0xff) << 0x10 | (local_5c >> 0x10 & 0xff) << 8
                 | local_5c >> 0x18) <
                 (local_28 << 0x18 | (local_28 >> 8 & 0xff) << 0x10 | (local_28 >> 0x10 & 0xff) << 8
                 | local_28 >> 0x18)) && ((param_1[5] & 2U) != 0)) {
              iVar2 = FUN_001054ec(param_3,0);
              param_1[0x27] = *(int *)(iVar2 + 0x10);
            }
          }
          else {
            piVar8 = (int *)FUN_00105594(param_3,param_3[0x21]);
            piVar7 = (int *)FUN_00105594(param_3,1);
            if (((piVar8 == piVar7) && ((param_3[0x2e] & 2U) == 0)) && ((param_3[0x2e] & 1U) == 0))
            {
              iVar2 = 0;
              iVar3 = 4;
              do {
                if (*(char *)((int)&local_5c + iVar2) == '\0') {
                  *(undefined1 *)((int)&local_58 + iVar2) =
                       *(undefined1 *)((int)&DAT_001b004c + iVar2);
                }
                iVar2 = iVar2 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            else {
              iVar2 = (**(code **)(*piVar8 + 100))(piVar8);
              if (iVar2 == 0) {
                return 0;
              }
              iVar2 = FUN_00105594(param_3,1);
              iVar3 = FUN_00105594(piVar8,1);
              if (iVar2 != iVar3) {
                return 0;
              }
              if (((uint)param_3[0x2e] >> 1 & 1) != ((uint)piVar8[0x2e] >> 1 & 1)) {
                return 0;
              }
              if ((param_3[0x2e] & 1U) != (piVar8[0x2e] & 1U)) {
                return 0;
              }
              if (piVar8[0x48] != 0) {
                return 0;
              }
              if (piVar8[0x49] != 0) {
                return 0;
              }
              iVar2 = FUN_001054ec(piVar8,0);
              local_54 = *(uint *)(iVar2 + 0x10);
              iVar2 = FUN_001054ec(piVar8,1);
              local_50 = *(undefined4 *)(iVar2 + 0x10);
              iVar2 = FUN_001054ec(param_1,param_2);
              FUN_000f3398(&local_24,*(undefined4 *)(iVar2 + 0x10));
              iVar2 = 0;
              local_4c = local_24;
              iVar3 = 4;
              do {
                if ((*(char *)((int)&local_4c + iVar2) != '\0') &&
                   (*(char *)((int)&local_5c + iVar2) == '\0')) {
                  if (*(char *)((int)&local_54 + iVar2) != '\0') {
                    return 0;
                  }
                  *(undefined1 *)((int)&local_58 + iVar2) = *(undefined1 *)((int)&local_50 + iVar2);
                }
                iVar2 = iVar2 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
          }
          iVar2 = FUN_00149de4(param_1,param_2,param_3,&local_58,*(undefined4 *)(param_4 + 8));
          if (iVar2 != 0) goto LAB_00160e58;
        }
      }
    }
    return 0;
  }
  if ((param_1[5] & 0x200U) == 0) {
    return 0;
  }
  piVar8 = (int *)FUN_00105594(param_1,param_1[0x21]);
  if (param_3 != piVar8) {
    return 0;
  }
  if ((param_3[5] & 0x200U) != 0) {
    return 0;
  }
  if (param_3[0x48] != 0) {
    return 0;
  }
  if (param_3[0x49] != 0) {
    return 0;
  }
  if ((param_3[0x2e] & 1U) != 0) {
    return 0;
  }
  if ((param_3[0x2e] & 2U) != 0) {
    return 0;
  }
  if (((param_3[0x20] != 0) && (iVar2 = FUN_00126760(param_3[0x26]), iVar2 != 0)) &&
     (((param_3[5] & 2U) == 0 && (iVar2 = (**(code **)(*param_3 + 0x50))(param_3), iVar2 == 0)))) {
    iVar2 = 4;
    piVar8 = param_3;
    do {
      if (*(byte *)(piVar8 + 0x27) - 2 < 2) {
        return 0;
      }
      piVar8 = (int *)((int)piVar8 + 1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_001054ec(param_3,0);
  iVar2 = FUN_00105dbc(param_3,0);
  if (iVar2 != 0) {
    return 0;
  }
  piVar8 = (int *)FUN_00105594(param_3,1);
  if (piVar8[0x20] == 0) {
    return 0;
  }
  iVar2 = FUN_00126760(piVar8[0x26]);
  if (iVar2 == 0) {
    return 0;
  }
  if ((piVar8[5] & 2U) != 0) {
    return 0;
  }
  iVar2 = (**(code **)(*piVar8 + 0x50))(piVar8);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = FUN_000f31e8(param_3,1);
  if (iVar2 == 0) {
    return 0;
  }
  piVar8 = (int *)FUN_00105594(param_3,1);
  iVar2 = (**(code **)(*piVar8 + 0x5c))();
  if (iVar2 != 0) {
    return 0;
  }
  if (*(int *)(*(int *)(param_4 + 8) + 0x660) <= *(int *)(param_4 + 0x17c)) {
    return 0;
  }
  iVar2 = FUN_001054ec(param_3,0);
  FUN_000f3908(auStack_38,*(undefined4 *)(iVar2 + 0x10));
  iVar2 = FUN_001054ec(param_1,0);
  FUN_000f3968(auStack_34,*(undefined4 *)(iVar2 + 0x10),DAT_001b017c);
  *(int *)(param_4 + 0x17c) = *(int *)(param_4 + 0x17c) + 1;
  iVar2 = FUN_0010497c(param_3,param_4);
  if (iVar2 == 0) {
    uVar6 = FUN_00105594(param_3,1);
    FUN_00106804(param_1,uVar6,0,*(undefined4 *)(param_4 + 8));
    param_3[0x58] = param_3[0x58] + -1;
    iVar2 = FUN_00105594(param_3,1);
    if (*(int *)(param_4 + 0x478) < *(int *)(iVar2 + 0x160)) {
      *(int *)(iVar2 + 0x160) = *(int *)(iVar2 + 0x160) + 1;
    }
    else {
      *(int *)(iVar2 + 0x160) = *(int *)(param_4 + 0x478) + 1;
    }
    goto LAB_00160e58;
  }
  iVar2 = (**(code **)(*param_1 + 100))(param_1);
  if (iVar2 == 0) {
LAB_0016086c:
    uVar6 = FUN_00105594(param_3,1);
    FUN_00106804(param_1,uVar6,0,*(undefined4 *)(param_4 + 8));
  }
  else {
    iVar2 = FUN_00105594(param_1,1);
    iVar3 = FUN_00105594(param_3,1);
    if (((iVar2 != iVar3) || (param_1[0x48] != param_3[0x48])) || (param_1[0x49] != param_3[0x49]))
    goto LAB_0016086c;
    if (((param_1[0x2e] & 1U) != (param_3[0x2e] & 1U)) ||
       (((uint)param_1[0x2e] >> 1 & 1) != ((uint)param_3[0x2e] >> 1 & 1))) goto LAB_0016086c;
    iVar2 = FUN_001054ec(param_3,0);
    uVar1 = *(uint *)(iVar2 + 0x10);
    iVar2 = FUN_001054ec(param_1,0);
    local_48 = *(uint *)(iVar2 + 0x10);
    uVar1 = (uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 |
            uVar1 >> 0x18) &
            (local_48 << 0x18 | (local_48 >> 8 & 0xff) << 0x10 | (local_48 >> 0x10 & 0xff) << 8 |
            local_48 >> 0x18);
    local_54 = uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
    param_1[0x27] = local_54;
    iVar2 = FUN_001054ec(param_1,1);
    local_58 = *(undefined4 *)(iVar2 + 0x10);
    iVar3 = FUN_001054ec(param_3,1);
    iVar2 = 0;
    local_5c = *(uint *)(iVar3 + 0x10);
    iVar3 = 4;
    do {
      if (*(char *)((int)&local_58 + iVar2) == '\x04') {
        *(undefined1 *)((int)&local_58 + iVar2) = *(undefined1 *)((int)&local_5c + iVar2);
      }
      uVar6 = local_58;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar2 = FUN_001054ec(param_1,1);
    *(undefined4 *)(iVar2 + 0x10) = uVar6;
    FUN_00106004(param_1,param_1[0x21],0,0,*(undefined4 *)(param_4 + 8));
    param_1[0x21] = param_1[0x21] + -1;
    param_1[5] = param_1[5] & 0xfffffdff;
    iVar2 = FUN_00105594(param_1,1);
    *(int *)(iVar2 + 0x160) = *(int *)(iVar2 + 0x160) + -1;
  }
  (**(code **)(*param_3 + 0xc))(param_3,0,*(undefined4 *)(param_4 + 8));
LAB_00160e58:
  *param_5 = 1;
  return 1;
}

/* FUN_00160eb0 @ 0x160eb0 (2188 bytes) */
int FUN_00160eb0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  double dVar16;
  undefined4 local_98;
  int *local_94;
  int local_90;
  int local_8c;
  int local_88[0];
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  undefined1 local_74 [3];
  undefined1 uStack_71;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  int *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_48;
  int local_44;
  
  iVar4 = FUN_000e07dc(*(undefined4 *)(param_4 + 8),0x1e);
  if ((iVar4 != 0) && ((*(uint *)(param_3 + 0x14) & 0x400000) == 0)) {
    local_78 = 0;
    local_6c = 4;
    local_94 = (int *)0x0;
    local_90 = 0;
    local_88[0] = 0;
    local_84 = 0;
    local_80 = 0;
    local_7c = 0;
    local_70 = 4;
    iVar4 = FUN_0015b974(param_3,&local_64,&local_8c,&local_80,local_74);
    if ((iVar4 != 0) && ((-1 < local_80 && (local_80 < 3)))) {
      iVar4 = FUN_001054ec(param_3,0);
      iVar4 = *(int *)(iVar4 + 0x10);
      iVar5 = FUN_001054ec(param_3,0);
      piVar14 = (int *)0x0;
      iVar5 = FUN_000f37b8(*(undefined4 *)(iVar5 + 0x10));
      if ((*(uint *)(param_3 + 0x14) & 0x200) != 0) {
        piVar14 = (int *)FUN_00105594(param_3,*(undefined4 *)(param_3 + 0x84));
      }
      bVar1 = piVar14 == (int *)0x0;
      iVar11 = *(int *)(param_3 + 0x120);
      if (bVar1) {
        piVar13 = (int *)0x0;
        piVar12 = (int *)0x0;
        local_78 = local_80;
        iVar6 = -1;
        local_7c = local_80;
        iVar8 = -1;
      }
      else {
        iVar6 = FUN_0010497c(piVar14,param_4);
        if (((((iVar6 == 0) ||
              (iVar6 = FUN_0015b974(piVar14,&local_94,&local_88,&local_7c,&local_70), iVar6 == 0))
             || (local_8c != local_88[0])) ||
            ((iVar6 = FUN_0014700c(local_64,local_94), iVar6 == 0 || (local_80 != local_7c)))) ||
           (iVar11 != piVar14[0x48])) {
          bVar1 = true;
          piVar13 = (int *)0x0;
          iVar6 = -1;
          iVar8 = -1;
          local_94 = (int *)0x0;
          piVar12 = piVar14;
          piVar14 = (int *)0x0;
          local_7c = local_80;
          local_78 = local_80;
        }
        else {
          iVar6 = FUN_001054ec(piVar14,0);
          FUN_000f2f84(&local_48,iVar4,*(undefined4 *)(iVar6 + 0x10));
          iVar4 = FUN_001054ec(piVar14,0);
          iVar6 = FUN_000f37b8(*(undefined4 *)(iVar4 + 0x10));
          iVar4 = local_48;
          if (((piVar14[5] & 0x200U) == 0) ||
             (piVar7 = (int *)FUN_00105594(piVar14,piVar14[0x21]), piVar7 == (int *)0x0)) {
            piVar13 = (int *)0x0;
            iVar8 = -1;
            local_78 = local_80;
            piVar12 = (int *)0x0;
          }
          else {
            iVar8 = FUN_0010497c(piVar7,param_4);
            if ((((iVar8 == 0) ||
                 (iVar8 = FUN_0015b974(piVar7,&local_90,&local_84,&local_78,&local_6c), iVar8 == 0))
                || (local_88[0] != local_84)) ||
               (((iVar8 = FUN_0014700c(local_94,local_90), iVar8 == 0 || (local_80 != local_78)) ||
                (iVar11 != piVar7[0x48])))) {
              piVar13 = (int *)0x0;
              iVar8 = -1;
              local_90 = 0;
              piVar12 = piVar7;
              local_78 = local_80;
            }
            else {
              iVar4 = FUN_001054ec(piVar7,0);
              FUN_000f2f84(&local_44,local_48,*(undefined4 *)(iVar4 + 0x10));
              iVar4 = FUN_001054ec(piVar7,0);
              iVar8 = FUN_000f37b8(*(undefined4 *)(iVar4 + 0x10));
              iVar4 = local_44;
              piVar12 = (int *)0x0;
              piVar13 = piVar7;
            }
          }
        }
      }
      if (local_8c == 0) {
        iVar9 = (**(code **)(*local_64 + 0x5c))();
        if (iVar9 != 0) {
          local_64[0x27] = iVar4;
          iVar9 = 1;
          while( true ) {
            iVar10 = (**(code **)(*local_64 + 0x14))();
            uVar2 = DAT_001b004c;
            if (iVar10 < iVar9) break;
            iVar10 = FUN_001054ec(local_64,iVar9);
            *(undefined4 *)(iVar10 + 0x10) = uVar2;
            (**(code **)(*local_64 + 0x88))(local_64,iVar9,3,4);
            iVar9 = iVar9 + 1;
          }
        }
        FUN_00147704(param_3,piVar14,piVar13,param_4);
        if (bVar1) {
          iVar9 = 0;
        }
        else {
          iVar9 = 1;
          (**(code **)(*piVar14 + 0xc))(piVar14,0,*(undefined4 *)(param_4 + 8));
          if (piVar13 != (int *)0x0) {
            iVar9 = 2;
            (**(code **)(*piVar13 + 0xc))(piVar13,0,*(undefined4 *)(param_4 + 8));
          }
        }
        if (local_80 == 2) {
          iVar9 = iVar9 + -1;
        }
        iVar10 = (**(code **)(*local_64 + 0x5c))();
        if (iVar10 == 0) {
          if (local_94 == (int *)0x0) {
            local_94 = local_64;
          }
          if (iVar9 < 0) {
            if (*(int *)(param_4 + 0x478) < local_64[0x58]) {
              local_64[0x58] = local_64[0x58] + 1;
            }
            else {
              local_64[0x58] = *(int *)(param_4 + 0x478) + 1;
            }
          }
          else if (0 < iVar9) {
            do {
              local_64[0x58] = local_64[0x58] + -1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
        }
        else if (local_94 == (int *)0x0) {
          if (iVar9 < 0) {
            iVar10 = *(int *)(param_4 + 0x478);
            local_94 = (int *)FUN_0010445c(local_64,*(undefined4 *)(param_4 + 8),0);
            iVar15 = iVar10 + 1;
            local_94[0x26] = 0x31;
            local_94[0x25] = local_94[0x53];
            FUN_000e7738(local_64[0x56],local_64,local_94);
            local_94[0x58] = iVar15;
            iVar9 = FUN_00105594(local_94,1);
            if (iVar10 < *(int *)(iVar9 + 0x160)) {
              *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
            }
            else {
              *(int *)(iVar9 + 0x160) = iVar15;
            }
            if (1 < local_94[0x21]) {
              iVar9 = FUN_00105594(local_94,2);
              if (iVar10 < *(int *)(iVar9 + 0x160)) {
                *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
              }
              else {
                *(int *)(iVar9 + 0x160) = iVar15;
              }
            }
          }
        }
        else if ((0 < iVar9) &&
                ((local_90 == 0 ||
                 (FUN_00105894(local_90,*(undefined4 *)(param_4 + 8)), 0 < iVar9 + -1)))) {
          FUN_00105894(local_94,*(undefined4 *)(param_4 + 8));
        }
        local_68 = DAT_001b0050;
        *(undefined1 *)((int)&local_68 + iVar5) = uStack_71;
        if (-1 < iVar6) {
          *(char *)((int)&local_68 + iVar6) = (char)local_70;
        }
        if (-1 < iVar8) {
          *(char *)((int)&local_68 + iVar8) = (char)local_6c;
        }
        local_60 = 0;
        local_5c = 0;
        local_58 = 0;
        iVar5 = *(int *)(param_3 + 4);
        FUN_00103f18(param_3,&local_60,0xffffffff);
        FUN_0019401c(param_3);
        local_98 = 0;
        if (local_80 == 0) {
          FUN_00108448(param_3,0x31,*(undefined4 *)(param_4 + 8));
          *(int *)(param_3 + 0x9c) = iVar4;
          FUN_000e7738(*(undefined4 *)(iVar5 + 0x158),iVar5,param_3);
          dVar16 = (double)FLOAT_001aa0e8;
          FUN_000f79c4(dVar16,dVar16,dVar16,dVar16,param_3,param_4,1);
          FUN_00103f44(param_3,&local_60);
          if (piVar12 != (int *)0x0) {
            FUN_00106804(param_3,piVar12,0,*(undefined4 *)(param_4 + 8));
          }
        }
        else {
          if (local_80 != 1) {
            FUN_00108174(param_3,0x13,*(undefined4 *)(param_4 + 8));
            *(int *)(param_3 + 0x9c) = iVar4;
            FUN_00103f44(param_3,&local_60);
            FUN_000e7738(*(undefined4 *)(iVar5 + 0x158),iVar5,param_3);
            FUN_00106004(param_3,1,local_64,0,*(undefined4 *)(param_4 + 8));
            FUN_00106004(param_3,2,local_94,0,*(undefined4 *)(param_4 + 8));
            uVar2 = local_68;
            iVar4 = FUN_001054ec(param_3,1);
            uVar3 = local_68;
            *(undefined4 *)(iVar4 + 0x10) = uVar2;
            iVar4 = FUN_001054ec(param_3,2);
            *(undefined4 *)(iVar4 + 0x10) = uVar3;
            if (piVar12 != (int *)0x0) {
              FUN_00106804(param_3,piVar12,0,*(undefined4 *)(param_4 + 8));
            }
            *(undefined4 *)(param_3 + 0x98) = 0;
            *(int *)(param_3 + 0x120) = iVar11;
            *(undefined4 *)(param_3 + 0x94) = *(undefined4 *)(param_3 + 0x14c);
            return 1;
          }
          FUN_00108448(param_3,0x31,*(undefined4 *)(param_4 + 8));
          FUN_00103f44(param_3,&local_60);
          *(int *)(param_3 + 0x9c) = iVar4;
          FUN_000e7738(*(undefined4 *)(iVar5 + 0x158),iVar5,param_3);
          FUN_00106004(param_3,1,local_64,0,*(undefined4 *)(param_4 + 8));
          uVar2 = local_68;
          iVar4 = FUN_001054ec(param_3,1);
          *(undefined4 *)(iVar4 + 0x10) = uVar2;
          FUN_00103d50(param_3 + 0xa4,2,1);
          *(undefined4 *)(param_3 + 0x98) = 0;
          *(undefined4 *)(param_3 + 0x94) = *(undefined4 *)(param_3 + 0x14c);
          if (piVar12 != (int *)0x0) {
            FUN_00106804(param_3,piVar12,0,*(undefined4 *)(param_4 + 8));
          }
          *(int *)(param_3 + 0x120) = iVar11;
        }
        ((int (*)())FUN_00160320)(param_1,param_2,param_3,param_4,&local_98);
        return 1;
      }
      if (!bVar1) {
        FUN_000da09c(*(undefined4 *)(*(int *)(param_4 + 8) + 0x398),*(uint *)(param_4 + 0x30) & 1);
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_00161748 @ 0x161748 (2688 bytes) */
int FUN_00161748(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  bool bVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined4 local_88[0];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78 [6];
  undefined4 local_60;
  int local_58 [5];
  
  iVar7 = (**(code **)(*param_1 + 100))();
  if ((iVar7 != 0) && (iVar7 = (**(code **)(*param_2 + 100))(param_2), iVar7 != 0)) {
    uVar8 = FUN_00105594(param_1,1);
    uVar9 = FUN_00105594(param_2,1);
    iVar7 = FUN_00146de0(uVar8,uVar9);
    if (iVar7 == 0) {
      iVar7 = FUN_00105594(param_1,1);
      iVar10 = FUN_00105594(param_2,1);
      if (iVar7 != iVar10) {
        uVar8 = FUN_00105594(param_1,1);
        uVar9 = *(undefined4 *)(param_3 + 8);
        iVar7 = FUN_001054ec(param_1,1);
        iVar7 = FUN_0010453c(uVar8,uVar9,*(undefined4 *)(iVar7 + 0x10));
        uVar8 = FUN_00105594(param_2,1);
        uVar9 = *(undefined4 *)(param_3 + 8);
        bVar1 = iVar7 == 0;
        iVar7 = FUN_001054ec(param_2,1);
        iVar7 = FUN_0010453c(uVar8,uVar9,*(undefined4 *)(iVar7 + 0x10));
        if ((!bVar1) || (iVar7 != 0)) {
          if (((param_1[0x2e] & 1U) != (param_2[0x2e] & 1U)) &&
             ((iVar7 == 0 || (iVar10 = FUN_00151318(param_2), iVar10 == 0)))) {
            if (bVar1) {
              return 0;
            }
            iVar10 = FUN_00151318(param_1);
            if (iVar10 == 0) {
              return 0;
            }
            if ((((uint)param_1[0x2e] >> 1 & 1) != ((uint)param_2[0x2e] >> 1 & 1)) &&
               ((((param_1[0x2e] & 2U) == 0 || (iVar7 == 0)) && ((param_2[0x2e] & 2U) == 0)))) {
              return 0;
            }
          }
          if ((((param_2[0x48] == param_1[0x48]) || ((param_2[0x48] != 0 && (iVar7 != 0)))) ||
              ((param_1[0x48] != 0 && (!bVar1)))) &&
             (((param_1[0x49] == param_2[0x49] ||
               ((iVar7 != 0 && (iVar10 = FUN_00151318(param_2), iVar10 != 0)))) ||
              ((!bVar1 && (iVar10 = FUN_00151318(param_1), iVar10 != 0)))))) {
            iVar10 = FUN_001054ec(param_1,0);
            local_88[0] = *(undefined4 *)(iVar10 + 0x10);
            iVar11 = FUN_001054ec(param_2,0);
            iVar10 = 0;
            local_84 = *(undefined4 *)(iVar11 + 0x10);
            iVar11 = 4;
            do {
              if ((*(char *)((int)&local_88 + iVar10) != '\x01') &&
                 (*(char *)((int)&local_84 + iVar10) != '\x01')) {
                return 0;
              }
              iVar10 = iVar10 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            iVar10 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x30);
            if ((iVar10 == 0) || (((char)local_88[0] != '\0' && ((char)local_84 != '\0')))) {
              iVar10 = param_2[0x49];
              if ((param_1[0x49] != iVar10) && (iVar7 != 0)) {
                iVar10 = FUN_00151318(param_2);
                if (iVar10 == 0) {
                  iVar10 = param_2[0x49];
                }
                else {
                  iVar10 = param_1[0x49];
                }
              }
              bVar4 = iVar7 == 0;
              iVar7 = param_2[0x48];
              if ((param_1[0x48] != iVar7) && (!bVar4)) {
                iVar7 = FUN_00151318(param_2);
                if (iVar7 == 0) {
                  iVar7 = param_2[0x48];
                }
                else {
                  iVar7 = param_1[0x48];
                }
              }
              uVar17 = param_1[0x2e];
              uVar15 = param_2[0x2e];
              uVar16 = uVar17 & 1;
              if (uVar16 != (uVar15 & 1)) {
                if ((bVar4) || (iVar11 = FUN_00151318(param_2), iVar11 == 0)) {
                  if ((bVar1) || (iVar11 = FUN_00151318(param_1), iVar11 == 0)) {
                    uVar17 = param_1[0x2e];
                    uVar16 = 0;
                    uVar15 = param_2[0x2e];
                  }
                  else {
                    uVar15 = param_2[0x2e];
                    uVar17 = param_1[0x2e];
                    uVar16 = uVar15 & 1;
                  }
                }
                else {
                  uVar17 = param_1[0x2e];
                  uVar15 = param_2[0x2e];
                  uVar16 = uVar17 & 1;
                }
              }
              uVar6 = uVar15 >> 1 & 1;
              uVar17 = uVar17 >> 1 & 1;
              uVar15 = uVar6;
              if (((uVar17 != uVar6) && (uVar15 = uVar17, bVar4)) && (uVar15 = uVar6, bVar1)) {
                uVar15 = 0;
              }
              iVar11 = FUN_001054ec(param_1,1);
              local_80 = *(undefined4 *)(iVar11 + 0x10);
              iVar11 = FUN_001054ec(param_2,1);
              local_7c = *(undefined4 *)(iVar11 + 0x10);
              FUN_000f2f84(local_58,local_84,local_88[0]);
              local_78[0] = local_58[0];
              piVar12 = (int *)FUN_0010a240(0xa2,*(undefined4 *)(param_3 + 8));
              piVar12[0x26] = 0x36;
              piVar12[0x25] = piVar12[0x53];
              piVar12[0x21] = 2;
              if (bVar4) {
                uVar8 = FUN_00105594(param_2,1);
              }
              else {
                uVar8 = FUN_00105594(param_1,1);
              }
              FUN_00106004(piVar12,1,uVar8,0,*(undefined4 *)(param_3 + 8));
              iVar11 = FUN_00105594(piVar12,1);
              if (*(int *)(param_3 + 0x478) < *(int *)(iVar11 + 0x160)) {
                *(int *)(iVar11 + 0x160) = *(int *)(iVar11 + 0x160) + 1;
              }
              else {
                *(int *)(iVar11 + 0x160) = *(int *)(param_3 + 0x478) + 1;
              }
              if (bVar4) {
                uVar8 = FUN_00105594(param_1,1);
              }
              else {
                uVar8 = FUN_00105594(param_2,1);
              }
              FUN_00106004(piVar12,2,uVar8,0,*(undefined4 *)(param_3 + 8));
              iVar11 = FUN_00105594(piVar12,2);
              if (*(int *)(param_3 + 0x478) < *(int *)(iVar11 + 0x160)) {
                *(int *)(iVar11 + 0x160) = *(int *)(iVar11 + 0x160) + 1;
              }
              else {
                *(int *)(iVar11 + 0x160) = *(int *)(param_3 + 0x478) + 1;
              }
              iVar11 = FUN_00105594(param_1,1);
              *(int *)(iVar11 + 0x160) = *(int *)(iVar11 + 0x160) + -1;
              FUN_00106004(param_1,1,piVar12,0,*(undefined4 *)(param_3 + 8));
              iVar11 = DAT_001b0174;
              uVar9 = DAT_001b0050;
              piVar12[0x58] = *(int *)(param_3 + 0x478) + 1;
              piVar12[0x27] = iVar11;
              iVar11 = FUN_001054ec(piVar12,1);
              uVar8 = DAT_001b004c;
              *(undefined4 *)(iVar11 + 0x10) = uVar9;
              iVar11 = FUN_001054ec(piVar12,2);
              *(undefined4 *)(iVar11 + 0x10) = uVar8;
              iVar11 = FUN_001054ec(param_1,1);
              *(undefined4 *)(iVar11 + 0x10) = uVar9;
              if (bVar4) {
                uVar9 = 1;
                uVar8 = 2;
              }
              else {
                uVar9 = 2;
                uVar8 = 1;
              }
              uVar17 = 0;
              iVar11 = 0;
              do {
                iVar13 = FUN_001054ec(param_1,0);
                if ((*(char *)(iVar11 + iVar13 + 0x10) != '\0') || ((!bVar1 && (bVar4)))) {
                  iVar13 = FUN_001054ec(param_2,0);
                  if ((*(char *)(iVar11 + iVar13 + 0x10) == '\0') && (bVar4)) {
                    uVar6 = (uint)*(byte *)((int)&local_7c + iVar11);
                    (**(code **)(*piVar12 + 0x88))(piVar12,uVar9,uVar6,uVar6);
                    (**(code **)(*piVar12 + 0x88))(piVar12,uVar8,uVar6,4);
                    *(undefined1 *)((int)piVar12 + uVar6 + 0x9c) = 0;
                    pcVar5 = *(code **)(*param_1 + 0x88);
                    goto LAB_00161e24;
                  }
                  (**(code **)(*piVar12 + 0x88))(piVar12,2,iVar11,4);
                }
                else {
                  FUN_001054ec(param_2,0);
                  uVar6 = (uint)*(byte *)((int)&local_80 + iVar11);
                  (**(code **)(*piVar12 + 0x88))(piVar12,uVar8,uVar6,uVar6);
                  *(undefined1 *)((int)piVar12 + uVar6 + 0x9c) = 0;
                  (**(code **)(*piVar12 + 0x88))(piVar12,uVar9,uVar6,4);
                  pcVar5 = *(code **)(*param_1 + 0x88);
LAB_00161e24:
                  uVar17 = uVar17 | 1 << (uVar6 & 0x3f);
                  (*pcVar5)(param_1,1,iVar11,uVar6);
                }
                bVar2 = iVar11 == 3;
                iVar11 = iVar11 + 1;
                if (bVar2) {
                  iVar11 = 0;
                  do {
                    if ((*(char *)((int)local_78 + iVar11) == '\0') &&
                       (iVar13 = FUN_001054ec(param_1,1),
                       *(char *)(iVar11 + iVar13 + 0x10) == '\x04')) {
                      if ((uVar17 & 1) == 0) {
                        iVar13 = 0;
                        uVar6 = 1;
                      }
                      else if ((uVar17 & 2) == 0) {
                        iVar13 = 1;
                        uVar6 = 2;
                      }
                      else if ((uVar17 & 4) == 0) {
                        iVar13 = 2;
                        uVar6 = 4;
                      }
                      else {
                        iVar13 = 3;
                        uVar6 = 0;
                      }
                      uVar17 = uVar17 ^ uVar6;
                      (**(code **)(*param_1 + 0x88))(param_1,1,iVar11,iVar13);
                      if (bVar4) {
                        uVar3 = *(undefined1 *)((int)&local_80 + iVar11);
                      }
                      else {
                        uVar3 = *(undefined1 *)((int)&local_7c + iVar11);
                      }
                      (**(code **)(*piVar12 + 0x88))(piVar12,2,iVar13,uVar3);
                      *(undefined1 *)((int)piVar12 + iVar13 + 0x9c) = 0;
                    }
                    bVar1 = iVar11 != 3;
                    iVar11 = iVar11 + 1;
                  } while (bVar1);
                  FUN_000e7700(param_1[0x56],param_1,piVar12);
                  param_1[0x27] = local_78[0];
                  FUN_00103d50(param_1 + 0x29,1,uVar16);
                  FUN_00103d50(param_1 + 0x29,2,uVar15);
                  param_1[0x49] = iVar10;
                  param_1[0x48] = iVar7;
                  FUN_00106004(param_1,param_1[0x21],0,0,*(undefined4 *)(param_3 + 8));
                  param_1[5] = param_1[5] & 0xfffffdff;
                  uVar16 = param_2[5];
                  param_1[0x21] = param_1[0x21] + -1;
                  if ((uVar16 & 0x200) != 0) {
                    iVar7 = FUN_00105594(param_2,param_2[0x21]);
                    local_60 = 0;
                    local_78[1] = 0;
                    local_78[2] = 0;
                    FUN_00104d3c(param_2,local_78 + 1);
                    FUN_00106b48(param_1,local_78 + 1,0,*(undefined4 *)(param_3 + 8));
                    if (*(int *)(param_3 + 0x478) < *(int *)(iVar7 + 0x160)) {
                      *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar7 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                    }
                  }
                  piVar14 = (int *)FUN_00105594(piVar12,1);
                  iVar7 = (**(code **)(*piVar14 + 0x60))();
                  if (iVar7 != 0) {
                    uVar8 = FUN_00105594(piVar12,1);
                    FUN_0010c670(uVar8,piVar12,*(undefined4 *)(param_3 + 8));
                  }
                  FUN_00105894(param_2,*(undefined4 *)(param_3 + 8));
                  if ((param_2[5] & 1U) != 0) {
                    piVar14 = (int *)FUN_00105594(piVar12,1);
                    iVar7 = (**(code **)(*piVar14 + 0x5c))();
                    if (iVar7 != 0) {
                      uVar8 = FUN_00105594(piVar12,1);
                      iVar7 = FUN_0010445c(uVar8,*(undefined4 *)(param_3 + 8),0);
                      iVar11 = *(int *)(param_3 + 0x478);
                      *(undefined4 *)(iVar7 + 0x94) = *(undefined4 *)(iVar7 + 0x14c);
                      *(undefined4 *)(iVar7 + 0x98) = 0x31;
                      iVar10 = FUN_00105594(piVar12,1);
                      uVar9 = *(undefined4 *)(iVar10 + 0x158);
                      uVar8 = FUN_00105594(piVar12,1);
                      iVar13 = iVar11 + 1;
                      FUN_000e7738(uVar9,uVar8,iVar7);
                      *(int *)(iVar7 + 0x160) = iVar13;
                      iVar10 = FUN_00105594(piVar12,1);
                      *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + -1;
                      iVar10 = FUN_00105594(iVar7,1);
                      if (iVar11 < *(int *)(iVar10 + 0x160)) {
                        *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar10 + 0x160) = iVar13;
                      }
                      if (1 < *(int *)(iVar7 + 0x84)) {
                        iVar10 = FUN_00105594(iVar7,2);
                        if (iVar11 < *(int *)(iVar10 + 0x160)) {
                          *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar10 + 0x160) = iVar13;
                        }
                      }
                      FUN_00106004(piVar12,1,iVar7,0,*(undefined4 *)(param_3 + 8));
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

/* FUN_001621c8 @ 0x1621c8 (2804 bytes) */
int FUN_001621c8(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  float *pfVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  int iVar11;
  float *pfVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int *piVar17;
  int *piVar18;
  int iVar19;
  int iVar20;
  double dVar21;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  int local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  float local_b8 [4];
  float local_a8 [4];
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_84;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  
  iVar6 = (**(code **)(*param_1 + 100))();
  if (iVar6 == 0) {
    return 0;
  }
  iVar6 = (**(code **)(*param_2 + 100))(param_2);
  if (iVar6 == 0) {
    return 0;
  }
  iVar6 = FUN_00105594(param_2,1);
  if (iVar6 == 0) {
    iVar6 = param_2[0x2c];
  }
  else {
    iVar6 = FUN_00105594(param_2,1);
    iVar6 = *(int *)(iVar6 + 0x98);
  }
  iVar6 = FUN_00126708(iVar6);
  if (iVar6 == 0) {
    return 0;
  }
  iVar6 = FUN_001054ec(param_1,0);
  local_d8 = *(int *)(iVar6 + 0x10);
  iVar7 = FUN_001054ec(param_2,0);
  iVar6 = 0;
  local_d4 = *(undefined4 *)(iVar7 + 0x10);
  iVar7 = 4;
  do {
    if ((*(char *)((int)&local_d8 + iVar6) != '\x01') &&
       (*(char *)((int)&local_d4 + iVar6) != '\x01')) {
      return 0;
    }
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar6 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x30);
  if (iVar6 != 0) {
    if ((char)local_d8 == '\0') {
      return 0;
    }
    if ((char)local_d4 == '\0') {
      return 0;
    }
  }
  if (param_2[0x48] != 0) {
    return 0;
  }
  iVar16 = param_1[0x49];
  iVar6 = param_2[0x49];
  iVar7 = FUN_00105594(param_1,1);
  iVar8 = FUN_00105594(param_2,1);
  if (iVar7 == iVar8) {
    uVar13 = param_1[0x2e];
    if (((param_2[0x2e] & 1U) == (uVar13 & 1)) &&
       (((uint)param_2[0x2e] >> 1 & 1) == (uVar13 >> 1 & 1))) {
      iVar7 = FUN_00105c5c(param_2,1);
      iVar8 = FUN_00105c5c(param_1,1);
      if ((iVar7 == iVar8) && (iVar16 == iVar6)) {
        iVar6 = FUN_001054ec(param_1,1);
        local_d0 = *(undefined4 *)(iVar6 + 0x10);
        iVar6 = FUN_001054ec(param_2,1);
        local_cc = *(undefined4 *)(iVar6 + 0x10);
        local_c8 = DAT_001b0050;
        iVar6 = 0;
        iVar7 = 4;
        do {
          if (*(char *)((int)&local_d8 + iVar6) == '\0') {
            *(undefined1 *)((int)&local_c8 + iVar6) = *(undefined1 *)((int)&local_d0 + iVar6);
          }
          else if (*(char *)((int)&local_d4 + iVar6) == '\0') {
            *(undefined1 *)((int)&local_c8 + iVar6) = *(undefined1 *)((int)&local_cc + iVar6);
          }
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar6 = 0;
        iVar7 = 4;
        do {
          if (*(char *)((int)&local_d4 + iVar6) != '\x01') {
            *(char *)((int)&local_d8 + iVar6) = *(char *)((int)&local_d4 + iVar6);
          }
          uVar10 = local_c8;
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        param_1[0x27] = local_d8;
        iVar6 = FUN_001054ec(param_1,1);
        *(undefined4 *)(iVar6 + 0x10) = uVar10;
        iVar6 = 0;
        FUN_00106004(param_1,param_1[0x21],0,0,*(undefined4 *)(param_3 + 8));
        param_1[5] = param_1[5] & 0xfffffdff;
        uVar13 = param_2[5];
        param_1[0x21] = param_1[0x21] + -1;
        if ((uVar13 & 0x200) != 0) {
          iVar6 = FUN_00105594(param_2,param_2[0x21]);
          uVar13 = param_2[5];
        }
        local_84 = 0;
        local_98 = 0;
        local_94 = 0;
        if ((uVar13 & 0x200) != 0) {
          FUN_00104d3c(param_2,&local_98);
        }
        if (iVar6 != 0) {
          FUN_00106b48(param_1,&local_98,0,*(undefined4 *)(param_3 + 8));
          if (*(int *)(param_3 + 0x478) < *(int *)(iVar6 + 0x160)) {
            *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
          }
          else {
            *(int *)(iVar6 + 0x160) = *(int *)(param_3 + 0x478) + 1;
          }
        }
        FUN_00105894(param_2,*(undefined4 *)(param_3 + 8));
        return 1;
      }
      goto LAB_00162370;
    }
  }
  else {
LAB_00162370:
    uVar13 = param_1[0x2e];
  }
  if (((((uVar13 & 1) == 0) && ((uVar13 & 2) == 0)) && (param_1[0x48] == 0)) && (param_1[0x49] == 0)
     ) {
    bVar2 = true;
    iVar7 = 0;
    do {
      iVar8 = FUN_001054ec(param_1,0);
      if ((*(char *)(iVar7 + iVar8 + 0x10) == '\x01') &&
         (iVar8 = FUN_001054ec(param_2,0), *(char *)(iVar7 + iVar8 + 0x10) == '\x01')) {
        bVar2 = false;
      }
      bVar1 = iVar7 != 3;
      iVar7 = iVar7 + 1;
    } while (bVar1);
    if ((bVar2) &&
       ((iVar7 = FUN_000f5a0c(param_1,1,param_1,param_3), iVar7 != 0 ||
        (((param_2[5] & 0x200U) == 0 &&
         (iVar7 = FUN_000f5a0c(param_2,1,param_2,param_3), iVar7 != 0)))))) {
      return 0;
    }
  }
  iVar7 = 4;
  pfVar12 = local_a8;
  pfVar4 = local_b8;
  do {
    *pfVar4 = NAN;
    pfVar4 = pfVar4 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  piVar17 = param_1;
  piVar18 = param_2;
  if (iVar6 == 0) {
    iVar6 = iVar16;
    if (iVar16 == 0) {
      iVar6 = 0;
      pfVar4 = local_b8;
      do {
        iVar7 = FUN_001054ec(param_2,0);
        if (*(char *)(iVar6 + iVar7 + 0x10) == '\x01') {
          *pfVar4 = 0.0;
        }
        else {
          iVar7 = FUN_001054ec(param_2,1);
          uVar13 = (uint)*(byte *)(iVar6 + iVar7 + 0x10);
          iVar7 = FUN_00105594(param_2,1);
          if (((int)*(char *)(iVar7 + 0x15c) >> (uVar13 & 0x3f) & 1U) == 0) {
            return 0;
          }
          *pfVar4 = *(float *)(uVar13 * 0x18 + iVar7 + 0x20);
        }
        bVar2 = iVar6 != 3;
        pfVar4 = pfVar4 + 1;
        iVar6 = iVar6 + 1;
      } while (bVar2);
      iVar16 = 0;
      goto LAB_001627ec;
    }
  }
  else {
    piVar17 = param_2;
    piVar18 = param_1;
    if (iVar16 != 0) {
      iVar7 = 0;
      dVar21 = (double)((double (*)())FUN_0010aad4)(iVar6);
      pfVar4 = local_b8;
      do {
        iVar6 = FUN_001054ec(param_2,0);
        if (*(char *)(iVar7 + iVar6 + 0x10) == '\x01') {
          *pfVar4 = 0.0;
        }
        else {
          iVar6 = FUN_001054ec(param_2,1);
          uVar13 = (uint)*(byte *)(iVar7 + iVar6 + 0x10);
          iVar6 = FUN_00105594(param_2,1);
          if (((int)*(char *)(iVar6 + 0x15c) >> (uVar13 & 0x3f) & 1U) == 0) {
            return 0;
          }
          *pfVar4 = (float)(dVar21 * (double)*(float *)(uVar13 * 0x18 + iVar6 + 0x20));
        }
        bVar2 = iVar7 != 3;
        pfVar4 = pfVar4 + 1;
        iVar7 = iVar7 + 1;
        piVar17 = param_1;
        piVar18 = param_2;
      } while (bVar2);
      goto LAB_001627ec;
    }
  }
  iVar16 = iVar6;
  iVar6 = 0;
  dVar21 = (double)((double (*)())FUN_0010aad4)(iVar16);
  pfVar4 = local_b8;
  do {
    iVar7 = FUN_001054ec(piVar18,0);
    if (*(char *)(iVar6 + iVar7 + 0x10) == '\x01') {
      *pfVar4 = 0.0;
    }
    else {
      iVar7 = FUN_001054ec(piVar18,1);
      uVar13 = (uint)*(byte *)(iVar6 + iVar7 + 0x10);
      iVar7 = FUN_00105594(piVar18,1);
      if (((int)*(char *)(iVar7 + 0x15c) >> (uVar13 & 0x3f) & 1U) == 0) {
        return 0;
      }
      *pfVar4 = (float)(dVar21 * (double)*(float *)(uVar13 * 0x18 + iVar7 + 0x20));
    }
    bVar2 = iVar6 != 3;
    pfVar4 = pfVar4 + 1;
    iVar6 = iVar6 + 1;
  } while (bVar2);
LAB_001627ec:
  local_68 = &local_98;
  iVar6 = 4;
  pfVar4 = pfVar12;
  do {
    *pfVar4 = NAN;
    pfVar4 = pfVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  dVar21 = (double)((double (*)())FUN_0010aad4)(iVar16);
  iVar6 = 0;
  local_c4 = local_d8;
  iVar7 = 4;
  do {
    if (*(char *)((int)&local_d4 + iVar6) != '\x01') {
      *(char *)((int)&local_c4 + iVar6) = *(char *)((int)&local_d4 + iVar6);
    }
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar6 = 0;
  pfVar4 = pfVar12;
  do {
    iVar7 = FUN_001054ec(param_1,0);
    if (*(char *)(iVar6 + iVar7 + 0x10) == '\0') {
      *pfVar4 = (float)dVar21;
    }
    else {
      FUN_001054ec(param_2,0);
      *pfVar4 = 0.0;
    }
    uVar10 = DAT_001b004c;
    bVar2 = iVar6 != 3;
    pfVar4 = pfVar4 + 1;
    iVar6 = iVar6 + 1;
  } while (bVar2);
  FUN_000f3908(&local_78,local_c4);
  FUN_000f3340(&local_74,uVar10,local_78);
  local_c0 = local_74;
  piVar9 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
  iVar6 = (**(code **)(*piVar9 + 0x154))(piVar9,param_3,pfVar12,&local_c0);
  FUN_000f3908(&local_70,local_c4);
  FUN_000f3340(&local_6c,uVar10,local_70);
  local_bc = local_6c;
  piVar9 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
  iVar7 = (**(code **)(*piVar9 + 0x154))(piVar9,param_3,local_b8[0],&local_bc);
  if ((iVar6 != 0) && (iVar7 != 0)) {
    if (*(int *)(param_3 + 0x478) < *(int *)(iVar6 + 0x160)) {
      *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
    }
    else {
      *(int *)(iVar6 + 0x160) = *(int *)(param_3 + 0x478) + 1;
    }
    if (*(int *)(param_3 + 0x478) < *(int *)(iVar7 + 0x160)) {
      *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
    }
    else {
      *(int *)(iVar7 + 0x160) = *(int *)(param_3 + 0x478) + 1;
    }
    *(undefined4 *)(iVar7 + 0x9c) = DAT_001b0170;
    iVar15 = piVar17[0x48];
    iVar16 = FUN_00104054(param_1,param_3);
    uVar10 = FUN_00105594(piVar17,1);
    iVar8 = FUN_001054ec(piVar17,1);
    local_c8 = *(undefined4 *)(iVar8 + 0x10);
    iVar8 = FUN_001054ec(piVar17,0);
    iVar8 = FUN_000f30d4(*(undefined4 *)(iVar8 + 0x10));
    iVar11 = FUN_001054ec(piVar17,1);
    uVar3 = *(undefined1 *)(iVar8 + iVar11 + 0x10);
    iVar11 = 4;
    iVar8 = 0;
    do {
      if (*(char *)((int)&local_c4 + iVar8) == '\0') {
        if (*pfVar12 == FLOAT_001aa0d4) {
          *(undefined1 *)((int)&local_c8 + iVar8) = uVar3;
        }
        else if (*(char *)((int)&local_c8 + iVar8) == '\x04') {
          *(char *)((int)&local_c8 + iVar8) = (char)iVar8;
        }
      }
      else {
        *(undefined1 *)((int)&local_c8 + iVar8) = 4;
      }
      iVar8 = iVar8 + 1;
      pfVar12 = pfVar12 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    uVar14 = param_2[5];
    iVar8 = 0;
    uVar13 = piVar17[0x2e];
    uVar5 = piVar18[0x2e];
    if ((uVar14 & 0x200) != 0) {
      iVar8 = FUN_00105594(param_2,param_2[0x21]);
      uVar14 = param_2[5];
    }
    local_84 = 0;
    local_98 = 0;
    local_94 = 0;
    if ((uVar14 & 0x200) != 0) {
      FUN_00104d3c(param_2,local_68);
    }
    piVar17 = (int *)param_1[1];
    uVar14 = param_1[5];
    iVar19 = param_1[0x26];
    iVar20 = param_1[0x25];
    iVar11 = param_1[3];
    if (param_2 == piVar17) {
      piVar17 = (int *)param_2[1];
    }
    FUN_0019401c(param_1);
    FUN_00108304(param_1,0x14,*(undefined4 *)(param_3 + 8));
    param_1[0x25] = iVar20;
    param_1[0x26] = iVar19;
    if ((uVar14 & 2) != 0) {
      param_1[5] = param_1[5] | 2;
    }
    param_1[3] = iVar11;
    param_1[0x27] = local_c4;
    param_1[0x49] = 0;
    param_1[0x48] = iVar15;
    FUN_00106004(param_1,1,uVar10,0,*(undefined4 *)(param_3 + 8));
    uVar10 = local_c8;
    iVar11 = FUN_001054ec(param_1,1);
    *(undefined4 *)(iVar11 + 0x10) = uVar10;
    FUN_00103d50(param_1 + 0x29,1,uVar13 & 1);
    FUN_00103d50(param_1 + 0x29,2,uVar13 >> 1 & 1);
    FUN_00106004(param_1,2,iVar6,0,*(undefined4 *)(param_3 + 8));
    uVar10 = local_c0;
    iVar6 = FUN_001054ec(param_1,2);
    *(undefined4 *)(iVar6 + 0x10) = uVar10;
    FUN_00106004(param_1,3,iVar7,0,*(undefined4 *)(param_3 + 8));
    uVar10 = local_bc;
    iVar6 = FUN_001054ec(param_1,3);
    *(undefined4 *)(iVar6 + 0x10) = uVar10;
    FUN_00103d50(param_1 + 0x35,1,uVar5 & 1);
    FUN_00103d50(param_1 + 0x35,2,uVar5 >> 1 & 1);
    param_1[0x58] = iVar16 + *(int *)(param_3 + 0x478);
    if (iVar8 != 0) {
      FUN_00106b48(param_1,local_68,0,*(undefined4 *)(param_3 + 8));
      if (*(int *)(param_3 + 0x478) < *(int *)(iVar8 + 0x160)) {
        *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
      }
      else {
        *(int *)(iVar8 + 0x160) = *(int *)(param_3 + 0x478) + 1;
      }
    }
    FUN_000e7738(piVar17[0x56],piVar17,param_1);
    FUN_00105894(param_2,*(undefined4 *)(param_3 + 8));
    return 1;
  }
  return 1;
}

/* FUN_00162cc0 @ 0x162cc0 (316 bytes) */
int FUN_00162cc0(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 100))();
  if ((((iVar1 != 0) || (*(int *)(param_1[0x22] + 8) == 0x13)) && ((param_1[5] & 0x200U) != 0)) &&
     ((*(uint *)(*(int *)(*(int *)(param_2 + 8) + 0x30c) + 8) & 0x100) != 0)) {
    uVar2 = FUN_00105594(param_1,param_1[0x21]);
    iVar1 = ((int (*)())FUN_00161748)(param_1,uVar2,param_2);
    if (((((iVar1 != 0) || (iVar1 = FUN_00151a74(param_1,uVar2,param_2), iVar1 != 0)) ||
         ((iVar1 = FUN_001524b8(param_1,uVar2,param_2), iVar1 != 0 ||
          ((iVar1 = FUN_00151370(param_1,uVar2,param_2), iVar1 != 0 ||
           (iVar1 = FUN_001541f0(param_1,uVar2,param_2), iVar1 != 0)))))) ||
        (iVar1 = FUN_00152ea8(param_1,uVar2,param_2), iVar1 != 0)) ||
       (iVar1 = ((int (*)())FUN_001621c8)(param_1,uVar2,param_2), iVar1 != 0)) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00162dfc @ 0x162dfc (1532 bytes) */
int FUN_00162dfc(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 local_88[0];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c [6];
  undefined4 local_54 [10];
  
  iVar2 = FUN_0011379c(*(undefined4 *)(param_3 + 8),*param_1);
  if ((iVar2 != 0) && (iVar2 = *param_1, (*(uint *)(iVar2 + 0x14) & 0x200) != 0)) {
    piVar3 = (int *)FUN_00105594(iVar2,*(undefined4 *)(iVar2 + 0x84));
    if (*(int *)(*(int *)(*param_1 + 0x88) + 8) == *(int *)(piVar3[0x22] + 8)) {
      iVar2 = FUN_001054ec(*param_1,0);
      local_84 = *(undefined4 *)(iVar2 + 0x10);
      iVar4 = FUN_001054ec(piVar3,0);
      iVar2 = 0;
      local_88[0] = *(undefined4 *)(iVar4 + 0x10);
      iVar4 = 4;
      do {
        if ((*(char *)((int)&local_84 + iVar2) != '\x01') &&
           (*(char *)((int)&local_88 + iVar2) != '\x01')) {
          return 0;
        }
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      iVar2 = *param_1;
      if ((*(int *)(iVar2 + 0x120) == piVar3[0x48]) && (*(int *)(iVar2 + 0x124) == piVar3[0x49])) {
        if (param_2 == 0) {
          iVar2 = FUN_00156cb8(iVar2,piVar3,param_3);
          if (iVar2 == 0) {
            return 0;
          }
          iVar2 = *param_1;
        }
        iVar11 = 5;
        iVar4 = 0;
        piVar5 = local_6c;
        do {
          *piVar5 = iVar4;
          piVar5 = piVar5 + 1;
          iVar4 = iVar4 + 1;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
        iVar2 = FUN_00112f78(*(undefined4 *)(*(int *)(iVar2 + 0x88) + 8),
                             *(undefined4 *)(param_3 + 8));
        if (iVar2 != 0) {
          iVar2 = FUN_00105594(*param_1,1);
          iVar4 = FUN_00105594(piVar3,2);
          if (iVar2 == iVar4) {
            iVar2 = FUN_00105594(*param_1,2);
            iVar4 = FUN_00105594(piVar3,1);
            if (iVar2 == iVar4) {
              local_6c[1] = 2;
              local_6c[2] = 1;
            }
          }
        }
        for (iVar2 = 1; iVar4 = (**(code **)(*(int *)*param_1 + 0x14))(), iVar2 <= iVar4;
            iVar2 = iVar2 + 1) {
          iVar4 = FUN_00105594(*param_1,iVar2);
          iVar8 = local_6c[iVar2];
          iVar11 = FUN_00105594(piVar3,iVar8);
          if (iVar4 != iVar11) {
            return 0;
          }
          uVar6 = *(uint *)(iVar2 * 0x18 + *param_1 + 0xa0);
          if ((uVar6 & 1) != (piVar3[iVar8 * 6 + 0x28] & 1U)) {
            return 0;
          }
          if ((uVar6 >> 1 & 1) != ((uint)piVar3[iVar8 * 6 + 0x28] >> 1 & 1)) {
            return 0;
          }
          piVar5 = (int *)FUN_00105594(*param_1,iVar2);
          iVar4 = (**(code **)(*piVar5 + 0x48))();
          if (iVar4 != 0) {
            iVar4 = FUN_001054ec(*param_1,iVar2);
            local_70 = *(undefined4 *)(iVar4 + 0x10);
            iVar4 = FUN_001054ec(piVar3,iVar8);
            local_80 = *(undefined4 *)(iVar4 + 0x10);
            piVar5 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
            iVar4 = (**(code **)(*piVar5 + 0x100))(piVar5,&local_70);
            if (iVar4 != 0) {
              piVar5 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
              iVar4 = (**(code **)(*piVar5 + 0x100))(piVar5,&local_80);
              if (iVar4 != 0) {
                iVar4 = 0;
                local_7c = local_70;
                iVar11 = 4;
                do {
                  if (*(char *)(iVar4 + (int)&local_80) == '\x04') {
                    *(undefined1 *)(iVar4 + (int)&local_80) =
                         *(undefined1 *)((int)&local_7c + iVar4);
                  }
                  iVar4 = iVar4 + 1;
                  iVar11 = iVar11 + -1;
                } while (iVar11 != 0);
                piVar5 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
                iVar4 = (**(code **)(*piVar5 + 0x100))(piVar5,&local_80);
                if (iVar4 == 0) {
                  return 0;
                }
              }
            }
          }
        }
        iVar2 = FUN_001054ec(*param_1,0);
        puVar10 = local_54;
        local_78 = *(undefined4 *)(iVar2 + 0x10);
        for (iVar2 = 1; iVar4 = (**(code **)(*(int *)*param_1 + 0x14))(), iVar2 <= iVar4;
            iVar2 = iVar2 + 1) {
          iVar4 = FUN_001054ec(*param_1,iVar2);
          *puVar10 = *(undefined4 *)(iVar4 + 0x10);
          puVar10 = puVar10 + 1;
        }
        iVar2 = 0;
        do {
          iVar4 = FUN_001054ec(piVar3,0);
          if (*(char *)(iVar2 + iVar4 + 0x10) != '\x01') {
            iVar4 = FUN_001054ec(piVar3,0);
            iVar11 = 1;
            piVar5 = local_6c;
            *(undefined1 *)((int)&local_78 + iVar2) = *(undefined1 *)(iVar2 + iVar4 + 0x10);
            puVar9 = (undefined1 *)((int)local_54 + iVar2);
            while( true ) {
              piVar5 = piVar5 + 1;
              iVar4 = (**(code **)(*piVar3 + 0x14))(piVar3);
              if (iVar4 < iVar11) break;
              iVar11 = iVar11 + 1;
              iVar4 = FUN_001054ec(piVar3,*piVar5);
              *puVar9 = *(undefined1 *)(iVar2 + iVar4 + 0x10);
              puVar9 = puVar9 + 4;
            }
          }
          bVar1 = iVar2 != 3;
          iVar2 = iVar2 + 1;
        } while (bVar1);
        iVar4 = 0;
        iVar2 = FUN_001054ec(*param_1,*(undefined4 *)(*param_1 + 0x84));
        local_74 = *(undefined4 *)(iVar2 + 0x10);
        do {
          iVar2 = FUN_001054ec(piVar3,0);
          if (*(char *)(iVar4 + iVar2 + 0x10) != '\x01') {
            *(undefined1 *)((int)&local_74 + iVar4) = 4;
          }
          bVar1 = iVar4 != 3;
          iVar4 = iVar4 + 1;
        } while (bVar1);
        iVar2 = 1;
        puVar10 = local_54;
        while( true ) {
          iVar4 = (**(code **)(*(int *)*param_1 + 0x14))();
          if (iVar4 < iVar2) {
            puVar10 = local_54;
            *(undefined4 *)(*param_1 + 0x9c) = local_78;
            for (iVar2 = 1; iVar4 = (**(code **)(*(int *)*param_1 + 0x14))(), iVar2 <= iVar4;
                iVar2 = iVar2 + 1) {
              uVar7 = *puVar10;
              iVar4 = FUN_001054ec(*param_1,iVar2);
              puVar10 = puVar10 + 1;
              *(undefined4 *)(iVar4 + 0x10) = uVar7;
            }
            if ((piVar3[5] & 0x200U) == 0) {
              iVar2 = *param_1;
              FUN_00106004(iVar2,*(undefined4 *)(iVar2 + 0x84),0,0,*(undefined4 *)(param_3 + 8));
              *(int *)(iVar2 + 0x84) = *(int *)(iVar2 + 0x84) + -1;
              *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xfffffdff;
              return 1;
            }
            iVar2 = FUN_00105594(piVar3,piVar3[0x21]);
            FUN_00106804(*param_1,iVar2,0,*(undefined4 *)(param_3 + 8));
            uVar7 = local_74;
            if (*(int *)(*param_1 + 0x84) == 0) {
              *(undefined4 *)(*param_1 + 0x9c) = local_74;
            }
            else {
              iVar4 = FUN_001054ec();
              *(undefined4 *)(iVar4 + 0x10) = uVar7;
            }
            if (*(int *)(iVar2 + 0x160) <= *(int *)(param_3 + 0x478)) {
              *(int *)(iVar2 + 0x160) = *(int *)(param_3 + 0x478) + 1;
              return 1;
            }
            *(int *)(iVar2 + 0x160) = *(int *)(iVar2 + 0x160) + 1;
            return 1;
          }
          piVar5 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
          iVar4 = (**(code **)(*piVar5 + 0x100))(piVar5,puVar10);
          if (iVar4 == 0) break;
          iVar2 = iVar2 + 1;
          puVar10 = puVar10 + 1;
        }
      }
    }
  }
  return 0;
}

/* FUN_001633f8 @ 0x1633f8 (128 bytes) */
int FUN_001633f8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iStack00000018;
  
  uVar2 = 0;
  iStack00000018 = param_1;
  if ((*(uint *)(param_1 + 0x14) & 0x200) != 0) {
    uVar2 = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84));
  }
  iVar1 = ((int (*)())FUN_00162dfc)(&STACKARG(0x18),0,param_2);
  if (iVar1 != 0) {
    *(int *)(param_2 + 0x1fc) = *(int *)(param_2 + 0x1fc) + 1;
    FUN_00105894(uVar2,*(undefined4 *)(param_2 + 8));
  }
  return iVar1 != 0;
}

/* FUN_00163478 @ 0x163478 (1308 bytes) */
int FUN_00163478(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88[0];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  undefined4 local_68;
  
  uVar10 = *(undefined4 *)(param_4 + 8);
  iVar11 = *(int *)(param_3[0x22] + 8);
  iVar3 = FUN_001054ec(param_3,0);
  local_98 = *(int *)(iVar3 + 0x10);
  if ((iVar11 - 0x1cU < 2) && (iVar3 = FUN_000f3824(), iVar3 != 0)) {
    uVar12 = 0;
    for (iVar3 = 1; iVar11 = (**(code **)(*param_3 + 0x14))(param_3), iVar3 <= iVar11;
        iVar3 = iVar3 + 1) {
      iVar11 = FUN_00105594(param_3,iVar3);
      if ((((*(int *)(*(int *)(iVar11 + 0x88) + 8) == 0x13) &&
           (iVar4 = FUN_0010497c(iVar11,param_4), iVar4 != 0)) && (*(int *)(iVar11 + 0x124) == 0))
         && ((*(int *)(iVar11 + 0x120) == 0 && ((*(uint *)(iVar11 + 0x14) & 0x200) == 0)))) {
        iVar4 = FUN_001054ec(iVar11,1);
        uVar9 = *(undefined4 *)(iVar4 + 0x10);
        iVar4 = FUN_001054ec(iVar11,2);
        uVar8 = *(undefined4 *)(iVar4 + 0x10);
        iVar4 = FUN_000f2c5c(uVar9);
        if ((iVar4 == 0) || (iVar4 = FUN_000f2c5c(uVar8), iVar4 == 0)) {
          iVar4 = FUN_000f2c5c(uVar9);
          if (iVar4 == 0) {
            iVar4 = FUN_000f2c5c(uVar8);
            if (iVar4 == 0) goto LAB_00163950;
            iVar4 = FUN_00105594(iVar11,2);
            iVar5 = FUN_00105594(iVar11,1);
            uVar12 = 2;
            local_94 = uVar8;
            uVar8 = 1;
          }
          else {
            iVar4 = FUN_00105594(iVar11,1);
            local_94 = uVar9;
            iVar5 = FUN_00105594(iVar11,2);
            uVar12 = 1;
            uVar8 = 2;
          }
          iVar2 = 0;
          iVar14 = 4;
          do {
            if (*(char *)((int)&local_94 + iVar2) != '\x04') {
              uVar7 = *(undefined1 *)((int)&local_94 + iVar2);
              goto LAB_00163628;
            }
            iVar2 = iVar2 + 1;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
          uVar7 = 0;
LAB_00163628:
          iVar2 = FUN_001054ec(iVar11,uVar8);
          local_90 = *(undefined4 *)(iVar2 + 0x10);
          iVar2 = FUN_001054ec(param_3,iVar3);
          local_8c = *(undefined4 *)(iVar2 + 0x10);
          *(int *)(param_4 + 0x284) = *(int *)(param_4 + 0x284) + 1;
          if (*(int *)(param_4 + 0x478) < *(int *)(iVar5 + 0x160)) {
            *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + 1;
          }
          else {
            *(int *)(iVar5 + 0x160) = *(int *)(param_4 + 0x478) + 1;
          }
          if (*(int *)(param_4 + 0x478) < *(int *)(iVar4 + 0x160)) {
            *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
          }
          else {
            *(int *)(iVar4 + 0x160) = *(int *)(param_4 + 0x478) + 1;
          }
          local_7c = 0;
          local_78 = 0;
          local_68 = 0;
          if ((param_3[5] & 0x200U) != 0) {
            FUN_00104d3c(param_3,&local_7c);
            FUN_00106004(param_3,param_3[0x21],0,0,uVar10);
            param_3[0x21] = param_3[0x21] + -1;
            param_3[5] = param_3[5] & 0xfffffdff;
          }
          local_88[0] = 0;
          local_84 = 0;
          local_80 = 0;
          FUN_00103f18(param_3,&local_88,0xffffffff);
          iVar2 = param_3[0x49];
          iVar14 = param_3[0x48];
          param_3[0x49] = 0;
          param_3[0x48] = 0;
          iVar13 = param_3[2];
          FUN_0019401c(param_3);
          iVar4 = FUN_0010445c(param_3,uVar10,0);
          *(undefined4 *)(iVar4 + 0x98) = 0;
          *(undefined4 *)(iVar4 + 0x94) = *(undefined4 *)(iVar4 + 0x14c);
          piVar6 = (int *)FUN_00103ebc(iVar11,param_3,uVar10,0);
          piVar6[0x26] = 0;
          piVar6[0x25] = piVar6[0x53];
          FUN_00106004(piVar6,uVar8,iVar4,0,uVar10);
          FUN_00105894(iVar11,uVar10);
          FUN_000e7700(*(undefined4 *)(iVar13 + 0x158),iVar13,iVar4);
          FUN_000e7738(*(undefined4 *)(iVar4 + 0x158),iVar4,piVar6);
          if ((iVar3 == 1) && (iVar13 = FUN_00105594(iVar4,2), iVar11 == iVar13)) {
            FUN_00106004(iVar4,2,iVar5,0,uVar10);
          }
          FUN_00106004(iVar4,iVar3,iVar5,0,uVar10);
          iVar5 = 4;
          iVar11 = 0;
          do {
            if (*(byte *)((int)&local_8c + iVar11) != 4) {
              *(undefined1 *)((int)&local_8c + iVar11) =
                   *(undefined1 *)((int)&local_90 + (uint)*(byte *)((int)&local_8c + iVar11));
            }
            uVar9 = local_8c;
            iVar11 = iVar11 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          if (iVar3 == 0) {
            *(undefined4 *)(iVar4 + 0x9c) = local_8c;
          }
          else {
            iVar11 = FUN_001054ec(iVar4,iVar3);
            *(undefined4 *)(iVar11 + 0x10) = uVar9;
          }
          *(int *)(iVar4 + 0x160) = *(int *)(param_4 + 0x478) + 1;
          if (local_78 != 0) {
            FUN_00106b48(piVar6,&local_7c,0,uVar10);
          }
          FUN_00103f44(piVar6,&local_88);
          piVar6[0x48] = iVar14;
          piVar6[0x49] = iVar2;
          iVar11 = 0;
          piVar6[0x27] = local_98;
          do {
            if (*(char *)((int)&local_98 + iVar11) == '\x01') {
              (**(code **)(*piVar6 + 0x88))(piVar6,1,iVar11,4);
              (**(code **)(*piVar6 + 0x88))(piVar6,2,iVar11,4);
            }
            else {
              (**(code **)(*piVar6 + 0x88))(piVar6,uVar12,iVar11,uVar7);
              (**(code **)(*piVar6 + 0x88))(piVar6,uVar8,iVar11,iVar11);
            }
            bVar1 = iVar11 != 3;
            iVar11 = iVar11 + 1;
          } while (bVar1);
          uVar12 = 1;
        }
      }
LAB_00163950: ;
    }
  }
  else {
    uVar12 = 0;
  }
  return uVar12;
}

/* FUN_00163994 @ 0x163994 (3864 bytes) */
int FUN_00163994(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  int *piVar12;
  uint uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint *puVar21;
  int iVar22;
  int iVar23;
  double dVar24;
  undefined4 local_b8[0];
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  int local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  int local_98;
  undefined4 local_88[0];
  undefined4 local_84;
  float local_80;
  
  if ((*(uint *)(param_1 + 0x14) & 0x200) == 0) {
    return 0;
  }
  iVar4 = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84));
  if (iVar4 == 0) {
    return 0;
  }
  if ((*(uint *)(*(int *)(*(int *)(param_2 + 8) + 0x30c) + 8) & 0x100) == 0) {
    return 0;
  }
  iVar20 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  iVar22 = *(int *)(*(int *)(iVar4 + 0x88) + 8);
  iVar5 = FUN_001054ec(param_1,*(undefined4 *)(param_1 + 0x84));
  local_b8[0] = *(undefined4 *)(iVar5 + 0x10);
  if (iVar20 == 0x31) {
    if (iVar22 != 0x14) {
      return 0;
    }
    iVar5 = FUN_001054ec(param_1,0);
    iVar22 = 0;
    local_84 = *(undefined4 *)(iVar5 + 0x10);
    iVar23 = 4;
    do {
      if (*(char *)((int)&local_b8 + iVar22) == '\x04') {
        if (*(char *)((int)&local_84 + iVar22) == '\0') {
          *(char *)((int)&local_b8 + iVar22) = (char)iVar22;
        }
      }
      else {
        *(undefined1 *)((int)&local_b8 + iVar22) = 4;
      }
      iVar22 = iVar22 + 1;
      iVar23 = iVar23 + -1;
      iVar5 = iVar4;
      iVar20 = param_1;
    } while (iVar23 != 0);
  }
  else {
    if (iVar20 != 0x14) {
      return 0;
    }
    iVar5 = param_1;
    iVar20 = iVar4;
    if (iVar22 != 0x31) {
      return 0;
    }
  }
  if (*(int *)(iVar20 + 0x120) != *(int *)(iVar5 + 0x120)) {
    return 0;
  }
  if (*(int *)(iVar20 + 0x124) != *(int *)(iVar5 + 0x124)) {
    return 0;
  }
  iVar22 = FUN_001054ec(iVar20,0);
  local_b4 = *(int *)(iVar22 + 0x10);
  iVar22 = FUN_001054ec(iVar5,0);
  local_b0 = *(undefined4 *)(iVar22 + 0x10);
  iVar22 = FUN_000e07dc(*(undefined4 *)(param_2 + 8),0x30);
  if (iVar22 != 0) {
    if ((char)local_b4 == '\0') {
      return 0;
    }
    if ((char)local_b0 == '\0') {
      return 0;
    }
  }
  iVar22 = 0;
  iVar23 = 4;
  do {
    if ((*(char *)((int)&local_b4 + iVar22) != '\x01') &&
       (*(char *)((int)&local_b0 + iVar22) != '\x01')) {
      return 0;
    }
    iVar22 = iVar22 + 1;
    iVar23 = iVar23 + -1;
  } while (iVar23 != 0);
  piVar6 = (int *)FUN_00105594(iVar20,1);
  iVar22 = (**(code **)(*piVar6 + 0x60))();
  if (iVar22 != 0) {
    return 0;
  }
  iVar22 = FUN_001466f4(iVar20,1);
  iVar23 = FUN_001466f4(iVar5,1);
  iVar7 = FUN_001466f4(iVar5,2);
  iVar8 = FUN_001466f4(iVar5,3);
  uVar18 = *(uint *)(iVar5 + 0xb8) & 1;
  uVar11 = *(uint *)(iVar5 + 0xd0) & 1;
  uVar19 = *(uint *)(iVar20 + 0xb8) & 1;
  uVar13 = *(uint *)(iVar20 + 0xb8) >> 1 & 1;
  if ((iVar22 == iVar23) && ((*(uint *)(iVar5 + 0xb8) >> 1 & 1) == uVar13)) {
    if (uVar19 == 0) {
      if (uVar18 != uVar11) goto LAB_00163c00;
    }
    else if (uVar18 == uVar11) goto LAB_00163c00;
    uVar14 = 1;
    dVar24 = (double)FLOAT_001aa0e8;
    uVar15 = 2;
    uVar16 = 3;
  }
  else {
LAB_00163c00:
    if ((iVar22 == iVar7) && ((*(uint *)(iVar5 + 0xd0) >> 1 & 1) == uVar13)) {
      if (uVar19 == 0) {
        if (uVar18 != uVar11) goto LAB_00163c2c;
      }
      else if (uVar18 == uVar11) goto LAB_00163c2c;
      uVar14 = 2;
      dVar24 = (double)FLOAT_001aa0e8;
      uVar15 = 1;
      uVar16 = 3;
    }
    else {
LAB_00163c2c:
      if (iVar22 != iVar8) {
        return 0;
      }
      if ((*(uint *)(iVar5 + 0xe8) >> 1 & 1) != uVar13) {
        return 0;
      }
      if ((*(uint *)(iVar5 + 0xe8) & 1) != uVar19) {
        return 0;
      }
      uVar14 = 3;
      dVar24 = (double)FLOAT_001aa0d4;
      uVar15 = 1;
      uVar16 = 2;
    }
  }
  local_88[0] = 0;
  local_9c = 0;
  local_98 = 0;
  if ((*(uint *)(iVar4 + 0x14) & 0x200) != 0) {
    FUN_00104d3c(iVar4,&local_9c);
  }
  iVar4 = *(int *)(iVar20 + 0x160) - *(int *)(param_2 + 0x478);
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  iVar22 = FUN_001054ec(iVar20,1);
  local_a4 = *(undefined4 *)(iVar22 + 0x10);
  iVar22 = FUN_001054ec(iVar5,uVar15);
  local_a0 = *(undefined4 *)(iVar22 + 0x10);
  iVar22 = FUN_001054ec(iVar5,uVar16);
  local_ac = *(undefined4 *)(iVar22 + 0x10);
  iVar23 = 4;
  local_a8 = local_b4;
  iVar22 = 0;
  do {
    if (*(char *)((int)&local_b0 + iVar22) != '\x01') {
      *(char *)((int)&local_a8 + iVar22) = *(char *)((int)&local_b0 + iVar22);
    }
    iVar22 = iVar22 + 1;
    iVar23 = iVar23 + -1;
  } while (iVar23 != 0);
  FUN_00105894(iVar20,*(undefined4 *)(param_2 + 8));
  piVar6 = (int *)FUN_00105594(iVar5,uVar14);
  piVar9 = (int *)FUN_00105594(iVar5,uVar15);
  piVar10 = (int *)FUN_00105594(iVar5,uVar16);
  iVar20 = *(int *)(param_1 + 4);
  FUN_0019401c(param_1);
  if ((*(uint *)(iVar5 + 0x14) & 0x200) != 0) {
    uVar17 = *(undefined4 *)(param_2 + 8);
    uVar18 = *(uint *)(param_2 + 0x30) >> 7 & 1;
    if (uVar18 != 0) {
      iVar22 = FUN_00105594(iVar5,*(undefined4 *)(iVar5 + 0x84));
      puVar21 = *(uint **)(iVar22 + 0x10);
      uVar11 = puVar21[1];
      if (0 < (int)uVar11) {
        uVar19 = 0;
        do {
          if (uVar19 < *puVar21) {
            if (uVar11 <= uVar19) {
              _memset((void *)(uVar11 * 4 + puVar21[2]),0,(uVar19 - uVar11) * 4 + 4);
              puVar21[1] = uVar19 + 1;
            }
            piVar12 = (int *)(uVar19 * 4 + puVar21[2]);
          }
          else {
            piVar12 = (int *)FUN_0019423c(puVar21,uVar19);
          }
          if (iVar5 == *piVar12) {
            FUN_00194208(puVar21,uVar19);
            iVar22 = FUN_00105594(iVar5,*(undefined4 *)(iVar5 + 0x84));
            *(int *)(iVar22 + 0x160) = *(int *)(iVar22 + 0x160) + -1;
            break;
          }
          uVar11 = puVar21[1];
          uVar19 = uVar19 + 1;
        } while ((int)uVar19 < (int)uVar11);
      }
    }
    FUN_00106004(iVar5,*(undefined4 *)(iVar5 + 0x84),0,uVar18,uVar17);
    *(int *)(iVar5 + 0x84) = *(int *)(iVar5 + 0x84) + -1;
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) & 0xfffffdff;
  }
  piVar12 = (int *)FUN_00103ebc(iVar5,param_1,*(undefined4 *)(param_2 + 8),0);
  FUN_000e7738(*(undefined4 *)(iVar20 + 0x158),iVar20,piVar12);
  iVar20 = piVar12[0x53];
  piVar12[0x27] = local_a8;
  iVar5 = FUN_001054ec(piVar12,0);
  *(int *)(iVar5 + 8) = iVar20;
  iVar5 = (**(code **)(*piVar9 + 0x60))(piVar9);
  if (iVar5 == 0) {
    piVar9 = (int *)FUN_0010a240(0xa2,*(undefined4 *)(param_2 + 8));
    FUN_000e7700(piVar12[0x56],piVar12,piVar9);
    piVar9[0x21] = 1;
    piVar9[0x25] = piVar9[0x53];
    piVar9[0x26] = 0x36;
    piVar9[0x27] = local_a8;
    iVar5 = FUN_00105594(piVar12,uVar15);
    FUN_00106004(piVar9,1,iVar5,0,*(undefined4 *)(param_2 + 8));
    if (*(int *)(param_2 + 0x478) < *(int *)(iVar5 + 0x160)) {
      *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + 1;
    }
    else {
      *(int *)(iVar5 + 0x160) = *(int *)(param_2 + 0x478) + 1;
    }
    piVar9[0x21] = 2;
    iVar5 = 0;
    FUN_000f79c4(dVar24,dVar24,dVar24,dVar24,piVar9,param_2,2);
    do {
      if (*(char *)((int)&local_b0 + iVar5) != '\x01') {
        (**(code **)(*piVar9 + 0x88))(piVar9,1,iVar5,*(undefined1 *)((int)&local_a0 + iVar5));
        (**(code **)(*piVar9 + 0x88))(piVar9,2,iVar5,4);
        (**(code **)(*piVar12 + 0x88))(piVar12,uVar15,iVar5,iVar5);
      }
      bVar1 = iVar5 != 3;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    iVar5 = 0;
    do {
      if (*(char *)((int)&local_b4 + iVar5) != '\x01') {
        (**(code **)(*piVar9 + 0x88))(piVar9,1,iVar5,4);
        (**(code **)(*piVar9 + 0x88))(piVar9,2,iVar5,iVar5);
        (**(code **)(*piVar12 + 0x88))(piVar12,uVar15,iVar5,iVar5);
      }
      bVar1 = iVar5 != 3;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    FUN_00106004(piVar12,uVar15,piVar9,0,*(undefined4 *)(param_2 + 8));
    piVar9[0x58] = *(int *)(param_2 + 0x478) + 1;
  }
  else {
    iVar5 = FUN_0010497c(piVar9,param_2);
    if (iVar5 == 0) {
      piVar9[0x58] = piVar9[0x58] + -1;
      piVar9 = (int *)FUN_0010445c(piVar9,*(undefined4 *)(param_2 + 8),0);
      FUN_000e7700(*(undefined4 *)(param_1 + 0x158),param_1,piVar9);
      piVar9[0x58] = *(int *)(param_2 + 0x478) + 1;
    }
    iVar5 = piVar9[0x21];
    if (1 < iVar5) {
      bVar1 = false;
      iVar20 = 2;
      do {
        iVar5 = FUN_001054ec(piVar9,0);
        iVar5 = FUN_000f5cf0(piVar9,iVar20,*(undefined4 *)(iVar5 + 0x10),&local_84);
        if ((iVar5 != 0) && (dVar24 == (double)local_80)) {
          iVar5 = -1;
          iVar22 = 0;
          do {
            iVar23 = FUN_001054ec(piVar9,iVar20);
            if (*(char *)(iVar22 + iVar23 + 0x10) != '\x04') {
              iVar5 = iVar22;
            }
            bVar2 = iVar22 != 3;
            iVar22 = iVar22 + 1;
          } while (bVar2);
          iVar22 = 0;
          do {
            if (*(char *)((int)&local_b8 + iVar22) != '\x04') {
              bVar1 = true;
              (**(code **)(*piVar12 + 0x88))(piVar12,uVar15,iVar22,iVar5);
            }
            bVar2 = iVar22 != 3;
            iVar22 = iVar22 + 1;
          } while (bVar2);
          if (bVar1) goto LAB_00164300;
        }
        iVar5 = piVar9[0x21];
        iVar20 = iVar20 + 1;
      } while (iVar20 <= iVar5);
      if (bVar1) goto LAB_00164300;
    }
    iVar5 = iVar5 + 1;
    piVar9[0x21] = iVar5;
    FUN_000f79c4(dVar24,dVar24,dVar24,dVar24,piVar9,param_2,iVar5);
    uVar17 = DAT_001b0050;
    iVar20 = FUN_001054ec(piVar9,iVar5);
    *(undefined4 *)(iVar20 + 0x10) = uVar17;
    iVar20 = 0;
    do {
      iVar22 = FUN_001054ec(piVar9,0);
      if (*(char *)(iVar20 + iVar22 + 0x10) != '\0') {
        (**(code **)(*piVar9 + 0x88))(piVar9,iVar5,iVar20,iVar20);
        *(undefined1 *)((int)piVar9 + iVar20 + 0x9c) = 0;
        goto LAB_001642bc;
      }
      bVar1 = iVar20 != 3;
      iVar20 = iVar20 + 1;
    } while (bVar1);
    iVar20 = -1;
LAB_001642bc:
    iVar5 = 0;
    do {
      if (*(char *)((int)&local_b8 + iVar5) != '\x04') {
        (**(code **)(*piVar12 + 0x88))(piVar12,uVar15,iVar5,iVar20);
      }
      bVar1 = iVar5 != 3;
      iVar5 = iVar5 + 1;
    } while (bVar1);
  }
LAB_00164300:
  iVar5 = (**(code **)(*piVar10 + 0x60))(piVar10);
  if (iVar5 == 0) {
    piVar9 = (int *)FUN_0010a240(0xa2,*(undefined4 *)(param_2 + 8));
    FUN_000e7700(piVar12[0x56],piVar12,piVar9);
    piVar9[0x21] = 1;
    piVar9[0x25] = piVar9[0x53];
    piVar9[0x26] = 0x36;
    piVar9[0x27] = local_a8;
    iVar5 = FUN_00105594(piVar12,uVar16);
    FUN_00106004(piVar9,1,iVar5,0,*(undefined4 *)(param_2 + 8));
    if (*(int *)(param_2 + 0x478) < *(int *)(iVar5 + 0x160)) {
      *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + 1;
    }
    else {
      *(int *)(iVar5 + 0x160) = *(int *)(param_2 + 0x478) + 1;
    }
    dVar24 = (double)FLOAT_001aa0d4;
    piVar9[0x21] = 2;
    iVar5 = 0;
    FUN_000f79c4(dVar24,dVar24,dVar24,dVar24,piVar9,param_2,2);
    do {
      if (*(char *)((int)&local_b0 + iVar5) != '\x01') {
        (**(code **)(*piVar9 + 0x88))(piVar9,1,iVar5,*(undefined1 *)((int)&local_ac + iVar5));
        (**(code **)(*piVar9 + 0x88))(piVar9,2,iVar5,4);
        (**(code **)(*piVar12 + 0x88))(piVar12,uVar16,iVar5,iVar5);
      }
      bVar1 = iVar5 != 3;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    iVar5 = 0;
    do {
      if (*(char *)((int)&local_b4 + iVar5) != '\x01') {
        (**(code **)(*piVar9 + 0x88))(piVar9,1,iVar5,4);
        (**(code **)(*piVar9 + 0x88))(piVar9,2,iVar5,iVar5);
        (**(code **)(*piVar12 + 0x88))(piVar12,uVar16,iVar5,iVar5);
      }
      bVar1 = iVar5 != 3;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    FUN_00106004(piVar12,uVar16,piVar9,0,*(undefined4 *)(param_2 + 8));
    piVar9[0x58] = *(int *)(param_2 + 0x478) + 1;
  }
  else {
    iVar5 = FUN_0010497c(piVar10,param_2);
    if (iVar5 == 0) {
      piVar10[0x58] = piVar10[0x58] + -1;
      piVar10 = (int *)FUN_0010445c(piVar10,*(undefined4 *)(param_2 + 8),0);
      FUN_000e7700(*(undefined4 *)(param_1 + 0x158),param_1,piVar10);
      piVar10[0x58] = *(int *)(param_2 + 0x478) + 1;
    }
    fVar3 = FLOAT_001aa0d4;
    iVar5 = piVar10[0x21];
    if (1 < iVar5) {
      bVar1 = false;
      iVar20 = 2;
      do {
        iVar5 = FUN_001054ec(piVar10,0);
        iVar5 = FUN_000f5cf0(piVar10,iVar20,*(undefined4 *)(iVar5 + 0x10),&local_84);
        if ((iVar5 != 0) && (local_80 == fVar3)) {
          iVar5 = -1;
          iVar22 = 0;
          do {
            iVar23 = FUN_001054ec(piVar10,iVar20);
            if (*(char *)(iVar22 + iVar23 + 0x10) != '\x04') {
              iVar5 = iVar22;
            }
            bVar2 = iVar22 != 3;
            iVar22 = iVar22 + 1;
          } while (bVar2);
          iVar22 = 0;
          do {
            if (*(char *)((int)&local_b8 + iVar22) != '\x04') {
              bVar1 = true;
              (**(code **)(*piVar12 + 0x88))(piVar12,uVar16,iVar22,iVar5);
            }
            bVar2 = iVar22 != 3;
            iVar22 = iVar22 + 1;
          } while (bVar2);
          if (bVar1) goto LAB_00164744;
        }
        iVar5 = piVar10[0x21];
        iVar20 = iVar20 + 1;
      } while (iVar20 <= iVar5);
      if (bVar1) goto LAB_00164744;
    }
    iVar5 = iVar5 + 1;
    dVar24 = (double)FLOAT_001aa0d4;
    piVar10[0x21] = iVar5;
    FUN_000f79c4(dVar24,dVar24,dVar24,dVar24,piVar10,param_2,iVar5);
    uVar15 = DAT_001b0050;
    iVar20 = FUN_001054ec(piVar10,iVar5);
    *(undefined4 *)(iVar20 + 0x10) = uVar15;
    iVar20 = 0;
    do {
      iVar22 = FUN_001054ec(piVar10,0);
      if (*(char *)(iVar20 + iVar22 + 0x10) != '\0') {
        (**(code **)(*piVar10 + 0x88))(piVar10,iVar5,iVar20,iVar20);
        *(undefined1 *)((int)piVar10 + iVar20 + 0x9c) = 0;
        goto LAB_00164700;
      }
      bVar1 = iVar20 != 3;
      iVar20 = iVar20 + 1;
    } while (bVar1);
    iVar20 = -1;
LAB_00164700:
    iVar5 = 0;
    do {
      if (*(char *)((int)&local_b8 + iVar5) != '\x04') {
        (**(code **)(*piVar12 + 0x88))(piVar12,uVar16,iVar5,iVar20);
      }
      bVar1 = iVar5 != 3;
      iVar5 = iVar5 + 1;
    } while (bVar1);
  }
LAB_00164744:
  iVar5 = 0;
  do {
    if (*(char *)((int)&local_b4 + iVar5) != '\x01') {
      iVar20 = (**(code **)(*piVar6 + 0x60))(piVar6);
      if (iVar20 == 0) {
        (**(code **)(*piVar12 + 0x88))(piVar12,uVar14,iVar5,*(undefined1 *)((int)&local_a4 + iVar5))
        ;
      }
      else {
        iVar20 = FUN_001054ec(piVar6,0);
        iVar20 = FUN_000f3108(*(undefined4 *)(iVar20 + 0x10));
        (**(code **)(*piVar6 + 0x88))(piVar6,1,iVar20,*(undefined1 *)((int)&local_a4 + iVar5));
        (**(code **)(*piVar12 + 0x88))(piVar12,uVar14,iVar5,iVar20);
        *(undefined1 *)((int)piVar6 + iVar20 + 0x9c) = 0;
      }
    }
    bVar1 = iVar5 != 3;
    iVar5 = iVar5 + 1;
  } while (bVar1);
  if (*(int *)(param_2 + 0x478) < piVar6[0x58]) {
    piVar6[0x58] = piVar6[0x58] + 1;
  }
  else {
    piVar6[0x58] = *(int *)(param_2 + 0x478) + 1;
  }
  if (local_98 != 0) {
    FUN_00106b48(piVar12,&local_9c,0,*(undefined4 *)(param_2 + 8));
    if (*(int *)(param_2 + 0x478) < *(int *)(local_98 + 0x160)) {
      *(int *)(local_98 + 0x160) = *(int *)(local_98 + 0x160) + 1;
    }
    else {
      *(int *)(local_98 + 0x160) = *(int *)(param_2 + 0x478) + 1;
    }
  }
  piVar12[0x58] = iVar4 + *(int *)(param_2 + 0x478);
  return 0;
}

/* FUN_001648ac @ 0x1648ac (456 bytes) */
int FUN_001648ac(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    if (*(int *)(param_1 + 0x24) == 0) {
      iVar1 = *(int *)(param_2 + 0x1c);
      if (iVar1 == *(int *)(param_3 + 0x1c)) {
        iVar1 = *(int *)(param_2 + 0x14) - *(int *)(param_3 + 0x14);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = *(int *)(param_3 + 0x5c);
        if (*(int *)(param_2 + 0x5c) == iVar1) {
          iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x60))();
          iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x60))(*(int **)(param_1 + 8),param_3);
          if (iVar1 - iVar2 != 0) {
            return iVar1 - iVar2;
          }
          iVar1 = *(int *)(param_2 + 0xc) - *(int *)(param_3 + 0xc);
          goto joined_r0x00164a48;
        }
      }
    }
    else {
      iVar1 = *(int *)(param_2 + 0x1c);
      if (iVar1 == *(int *)(param_3 + 0x1c)) {
        iVar1 = (**(code **)(**(int **)(param_1 + 8) + 100))();
        iVar2 = (**(code **)(**(int **)(param_1 + 8) + 100))(*(int **)(param_1 + 8),param_3);
        if (iVar1 - iVar2 != 0) {
          return iVar1 - iVar2;
        }
        iVar1 = *(int *)(param_2 + 0xc) - *(int *)(param_3 + 0xc);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = *(int *)(param_2 + 0x14) - *(int *)(param_3 + 0x14);
joined_r0x00164a48:
        if (iVar1 != 0) {
          return iVar1;
        }
        return *(int *)(param_3 + 0x10) - *(int *)(param_2 + 0x10);
      }
    }
  }
  else {
    iVar1 = *(int *)(param_2 + 0x10) - *(int *)(param_3 + 0x10);
    if (iVar1 != 0) {
      return -iVar1;
    }
    iVar1 = *(int *)(param_2 + 0xc) - *(int *)(param_3 + 0xc);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = *(int *)(param_2 + 0x1c);
    if (iVar1 == *(int *)(param_3 + 0x1c)) {
      iVar1 = *(int *)(param_2 + 0x14) - *(int *)(param_3 + 0x14);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = *(int *)(param_3 + 0x5c);
      if (*(int *)(param_2 + 0x5c) == iVar1) {
        return 0;
      }
    }
  }
  iVar2 = -1;
  if (iVar1 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}

/* FUN_00164a74 @ 0x164a74 (312 bytes) */
int FUN_00164a74(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x118) != 0) {
    iVar1 = FUN_00193f08(param_1 + 0x34);
    if (iVar1 == 0) {
      if ((*(int *)(param_1 + 0x28) <= *(int *)(param_1 + 300)) &&
         (iVar1 = FUN_00193f08(param_1 + 0x4c), iVar1 == 0)) {
        *(uint *)(param_1 + 0x118) = (uint)(*(int *)(param_1 + 0x110) <= param_3);
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x118) = 0;
    }
    if (*(int *)(param_1 + 0x118) != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x2c);
    return;
  }
  iVar1 = FUN_00193f08(param_1 + 0x4c);
  if (iVar1 == 0) {
    iVar1 = FUN_00193f08(param_1 + 0x34);
    if ((iVar1 != 0) ||
       ((*(int *)(param_1 + 0x120) < *(int *)(param_1 + 0x11c) &&
        (param_2 < *(int *)(param_1 + 0x28))))) goto LAB_00164b7c;
    iVar1 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x124);
    if (iVar1 < 8) {
      *(uint *)(param_1 + 0x118) = (uint)(*(int *)(param_1 + 0x110) - iVar1 < param_3);
      goto LAB_00164b7c;
    }
  }
  *(undefined4 *)(param_1 + 0x118) = 1;
LAB_00164b7c:
  if (*(int *)(param_1 + 0x118) != 0) {
    *(undefined4 *)(param_1 + 300) = 0;
    *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x120);
  }
  return;
}

/* FUN_00164bec @ 0x164bec (520 bytes) */
int FUN_00164bec(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 uStack0000001c;
  int local_28 [6];
  
  bVar2 = param_4 == 0;
  uStack0000001c = param_2;
  if (bVar2) {
    iVar13 = 4;
    iVar9 = 0;
    piVar4 = param_1;
    do {
      piVar1 = piVar4 + 0x54;
      piVar4 = piVar4 + 1;
      *(int *)((int)local_28 + iVar9) = *piVar1;
      iVar9 = iVar9 + 4;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    uVar5 = param_1[0x51];
    iVar9 = param_1[0x68];
  }
  else {
    iVar13 = 4;
    iVar9 = 0;
    piVar4 = param_1;
    do {
      piVar1 = piVar4 + 0x58;
      piVar4 = piVar4 + 1;
      *(int *)((int)local_28 + iVar9) = *piVar1;
      iVar9 = iVar9 + 4;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    uVar5 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x13c))();
    iVar9 = param_1[0x69];
  }
  uVar6 = 0xffffffff;
  if (0 < (int)uVar5) {
    iVar13 = 0x7fffffff;
    uVar7 = uVar6;
    uVar8 = 0;
    do {
      uVar6 = uVar8;
      if ((!bVar2) ||
         ((*(uint *)((uVar6 >> 3 & 0x1ffffffc) + param_1[0x4c] + 8) >> (uVar6 & 0x1f) & 1) != 0)) {
        if (iVar9 < (int)uVar6) {
          if (-1 < (int)uVar7) goto LAB_00164d6c;
          break;
        }
        iVar14 = 4;
        iVar11 = 0x7fffffff;
        pcVar10 = (char *)&STACKARG(0x1c);
        iVar12 = 0;
        do {
          if (*pcVar10 != '\0') {
            iVar3 = param_3 - *(int *)(*(int *)((int)local_28 + iVar12) + uVar6 * 4);
            if (iVar3 < iVar11) {
              iVar11 = iVar3;
            }
            if (iVar11 < 0) goto LAB_00164d58;
          }
          pcVar10 = pcVar10 + 1;
          iVar12 = iVar12 + 4;
          iVar14 = iVar14 + -1;
        } while (iVar14 != 0);
        if ((-1 < iVar11) && (iVar11 < iVar13)) {
          uVar7 = uVar6;
          iVar13 = iVar11;
        }
      }
LAB_00164d58:
      uVar8 = uVar6 + 1;
      uVar6 = uVar7;
    } while (uVar5 != uVar8);
    uVar7 = uVar6;
    if (-1 < (int)uVar6) {
LAB_00164d6c:
      uVar6 = uVar7;
      if (bVar2) {
        uVar5 = param_1[0x68];
        if (param_1[0x68] < (int)uVar6) {
          uVar5 = uVar6;
        }
        param_1[0x68] = uVar5;
      }
      else {
        uVar5 = param_1[0x69];
        if (param_1[0x69] < (int)uVar6) {
          uVar5 = uVar6;
        }
        param_1[0x69] = uVar5;
      }
      iVar13 = 4;
      pcVar10 = (char *)&STACKARG(0x1c);
      iVar9 = 0;
      do {
        if (*pcVar10 != '\0') {
          *(int *)(*(int *)((int)local_28 + iVar9) + uVar6 * 4) = param_1[0xb];
        }
        pcVar10 = pcVar10 + 1;
        iVar9 = iVar9 + 4;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
    }
  }
  return uVar6;
}

/* FUN_00164df4 @ 0x164df4 (136 bytes) */
int FUN_00164df4(param_1)
  int *param_1;
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x7c))();
  if (iVar1 == 0) {
    if ((param_1[5] & 0x8000U) == 0) {
      iVar1 = param_1[0x22];
    }
    else {
      iVar1 = param_1[0x22];
      if ((*(int *)(iVar1 + 4) != 1) && (param_1[0x21] == 0)) {
        return 1;
      }
    }
    if (*(int *)(iVar1 + 8) != 0xa4) {
      return 0;
    }
  }
  return 1;
}

/* FUN_00164e7c @ 0x164e7c (324 bytes) */
int FUN_00164e7c(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int *param_2;
  int *param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_28;
  
  if (param_6 == 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x54))();
    if (iVar1 != 0) {
      return local_28;
    }
    if ((((*(int *)(param_2[0x22] + 4) != 1) &&
         ((iVar1 = (**(code **)(*param_3 + 0x54))(param_3), iVar1 == 0 ||
          (iVar1 = FUN_001045e4(param_3), iVar1 != 0)))) &&
        ((iVar1 = (**(code **)(*param_3 + 0x5c))(param_3), iVar1 == 0 ||
         (iVar1 = (**(code **)(*param_2 + 0x28))(param_2), iVar1 == 0)))) &&
       ((iVar1 = (**(code **)(*param_3 + 0x60))(param_3), iVar1 == 0 &&
        (iVar1 = FUN_00104644(param_2), iVar1 == 0)))) {
      uVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x78))();
      return uVar2;
    }
  }
  else if (param_6 == 1) {
    return 1;
  }
  return 0;
}

/* FUN_00164fc0 @ 0x164fc0 (84 bytes) */
int FUN_00164fc0(param_1)
  int param_1;
{
  int iVar1;
  
  if ((0 < *(int *)(param_1 + 0x80)) &&
     ((((*(int *)(*(int *)(param_1 + 0x88) + 4) == 1 || ((*(uint *)(param_1 + 0x14) & 0x40) != 0))
       || (iVar1 = *(int *)(param_1 + 0x98), iVar1 == 0x20)) || ((iVar1 == 0x21 || (iVar1 == 0x22)))
      ))) {
    return 1;
  }
  return 0;
}

/* FUN_00165014 @ 0x165014 (1520 bytes) */
int FUN_00165014(param_1)
  int *param_1;
{
  uint *puVar1;
  uint *puVar2;
  bool bVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  int *piVar15;
  int *piVar16;
  int iVar17;
  undefined4 uVar18;
  uint uVar19;
  
  iVar6 = param_1[1];
  iVar17 = *(int *)(iVar6 + 900);
  if (*(int *)(iVar17 + 8) != 0) {
    do {
      iVar6 = param_1[0x51];
      uVar19 = iVar6 + 0x1fU >> 5;
      uVar18 = *(undefined4 *)(*param_1 + 0x378);
      puVar7 = (undefined4 *)FUN_00193e18(uVar18,uVar19 * 4 + 0xc);
      puVar14 = puVar7 + 1;
      *puVar7 = uVar18;
      puVar7[1] = uVar19;
      puVar7[2] = iVar6;
      if (uVar19 != 0) {
        puVar7 = puVar14;
        if (uVar19 == 0) {
          uVar19 = 1;
        }
        do {
          puVar7[2] = 0;
          puVar7 = puVar7 + 1;
          uVar19 = uVar19 - 1;
        } while (uVar19 != 0);
      }
      *(undefined4 **)(iVar17 + 0x104) = puVar14;
      iVar6 = param_1[0x51];
      uVar19 = iVar6 + 0x1fU >> 5;
      uVar18 = *(undefined4 *)(*param_1 + 0x378);
      puVar7 = (undefined4 *)FUN_00193e18(uVar18,uVar19 * 4 + 0xc);
      puVar14 = puVar7 + 1;
      *puVar7 = uVar18;
      puVar7[1] = uVar19;
      puVar7[2] = iVar6;
      if (uVar19 != 0) {
        puVar7 = puVar14;
        if (uVar19 == 0) {
          uVar19 = 1;
        }
        do {
          puVar7[2] = 0;
          puVar7 = puVar7 + 1;
          uVar19 = uVar19 - 1;
        } while (uVar19 != 0);
      }
      *(undefined4 **)(iVar17 + 0x100) = puVar14;
      *(undefined4 *)(iVar17 + 0x118) = *(undefined4 *)(param_1[1] + 0x474);
      iVar17 = *(int *)(iVar17 + 8);
    } while (*(int *)(iVar17 + 8) != 0);
    iVar6 = param_1[1];
  }
  *(int *)(iVar6 + 0x474) = *(int *)(iVar6 + 0x474) + 1;
  iVar8 = param_1[1];
  iVar6 = *(int *)(*(int *)(iVar8 + 900) + 8);
  iVar17 = *(int *)(iVar8 + 900);
  if (iVar6 != 0) {
    do {
      iVar8 = iVar6;
      piVar5 = (int *)(*(int **)(iVar17 + 0x98))[2];
      piVar16 = *(int **)(iVar17 + 0x98);
      if (piVar5 != (int *)0x0) {
        do {
          piVar10 = piVar5;
          if (((piVar16[5] & 1U) != 0) && (0 < piVar16[0x21])) {
            iVar8 = 1;
            uVar19 = 0;
            iVar6 = 0;
            do {
              piVar5 = (int *)FUN_00105594(piVar16,iVar8);
              if (((piVar5[5] & 0x40U) == 0) || (iVar9 = FUN_00126760(piVar5[0x26]), iVar9 == 0)) {
                iVar9 = (**(code **)(*piVar5 + 0x5c))(piVar5);
                if (((iVar9 != 0) || (iVar9 = (**(code **)(*piVar5 + 0x60))(piVar5), iVar9 != 0)) &&
                   (0 < piVar5[0x21])) {
                  iVar9 = 1;
                  do {
                    piVar10 = (int *)FUN_00105594(piVar5,iVar9);
                    iVar11 = (**(code **)(*piVar10 + 0x5c))();
                    if (iVar11 == 0) {
                      if (((piVar10[5] & 0x40U) != 0) &&
                         (iVar11 = FUN_00126760(piVar10[0x26]), iVar11 != 0)) {
                        iVar11 = (**(code **)(*piVar16 + 0x7c))(piVar16);
                        if (iVar11 == 0) {
                          uVar4 = piVar10[0x25];
                          iVar11 = (uVar4 >> 3 & 0x1ffffffc) + *(int *)(iVar17 + 0x100);
                        }
                        else {
                          piVar15 = (int *)0x0;
                          if (uVar19 < *(uint *)(*(int *)(iVar17 + 0xd4) + 4)) {
                            piVar15 = (int *)(iVar6 + *(int *)(*(int *)(iVar17 + 0xd4) + 8));
                          }
                          uVar4 = piVar10[0x25];
                          iVar11 = (uVar4 >> 3 & 0x1ffffffc) + *(int *)(*piVar15 + 0x104);
                        }
                        *(uint *)(iVar11 + 8) = 1 << (uVar4 & 0x1f) | *(uint *)(iVar11 + 8);
                      }
                    }
                    else if (0 < piVar10[0x21]) {
                      iVar11 = 1;
                      do {
                        iVar12 = FUN_00105594(piVar10,iVar11);
                        if (((*(uint *)(iVar12 + 0x14) & 0x40) != 0) &&
                           (iVar13 = FUN_00126760(*(undefined4 *)(iVar12 + 0x98)), iVar13 != 0)) {
                          iVar13 = (**(code **)(*piVar16 + 0x7c))(piVar16);
                          if (iVar13 == 0) {
                            uVar4 = *(uint *)(iVar12 + 0x94);
                            iVar12 = (uVar4 >> 3 & 0x1ffffffc) + *(int *)(iVar17 + 0x100);
                          }
                          else {
                            piVar15 = (int *)0x0;
                            if (uVar19 < *(uint *)(*(int *)(iVar17 + 0xd4) + 4)) {
                              piVar15 = (int *)(iVar6 + *(int *)(*(int *)(iVar17 + 0xd4) + 8));
                            }
                            uVar4 = *(uint *)(iVar12 + 0x94);
                            iVar12 = (uVar4 >> 3 & 0x1ffffffc) + *(int *)(*piVar15 + 0x104);
                          }
                          *(uint *)(iVar12 + 8) = 1 << (uVar4 & 0x1f) | *(uint *)(iVar12 + 8);
                        }
                        iVar11 = iVar11 + 1;
                      } while (iVar11 <= piVar10[0x21]);
                    }
                    iVar9 = iVar9 + 1;
                  } while (iVar9 <= piVar5[0x21]);
                }
              }
              else {
                iVar9 = (**(code **)(*piVar16 + 0x7c))(piVar16);
                if (iVar9 == 0) {
                  uVar4 = piVar5[0x25];
                  iVar9 = (uVar4 >> 3 & 0x1ffffffc) + *(int *)(iVar17 + 0x100);
                }
                else {
                  piVar10 = (int *)0x0;
                  if (uVar19 < *(uint *)(*(int *)(iVar17 + 0xd4) + 4)) {
                    piVar10 = (int *)(iVar6 + *(int *)(*(int *)(iVar17 + 0xd4) + 8));
                  }
                  uVar4 = piVar5[0x25];
                  iVar9 = (uVar4 >> 3 & 0x1ffffffc) + *(int *)(*piVar10 + 0x104);
                }
                *(uint *)(iVar9 + 8) = 1 << (uVar4 & 0x1f) | *(uint *)(iVar9 + 8);
              }
              iVar8 = iVar8 + 1;
              uVar19 = uVar19 + 1;
              iVar6 = iVar6 + 4;
            } while (iVar8 <= piVar16[0x21]);
            piVar10 = (int *)piVar16[2];
          }
          piVar5 = (int *)piVar10[2];
          piVar16 = piVar10;
        } while ((int *)piVar10[2] != (int *)0x0);
        iVar8 = *(int *)(iVar17 + 8);
      }
      iVar6 = *(int *)(iVar8 + 8);
      iVar17 = iVar8;
    } while (*(int *)(iVar8 + 8) != 0);
    iVar8 = param_1[1];
  }
  iVar6 = FUN_000ec5b8(iVar8);
  do {
    bVar3 = false;
    for (iVar17 = 1; iVar8 = FUN_00194034(param_1[1] + 0x37c), iVar17 <= iVar8; iVar17 = iVar17 + 1)
    {
      piVar5 = *(int **)(iVar6 + iVar17 * 4);
      iVar8 = (**(code **)(*piVar5 + 0x20))(piVar5);
      if (iVar8 == 0) {
        iVar8 = 0;
        for (uVar19 = 1; uVar19 <= *(uint *)(piVar5[0x34] + 4); uVar19 = uVar19 + 1) {
          iVar9 = *(int *)(*(int *)(piVar5[0x34] + 8) + iVar8);
          if (iVar9 != 0) {
            piVar16 = (int *)piVar5[0x41];
            iVar11 = *(int *)(iVar9 + 0x100);
            iVar9 = *piVar16;
            if (iVar9 != 0) {
              if (iVar9 == 0) {
                iVar9 = 1;
              }
              do {
                puVar1 = (uint *)(iVar11 + 8);
                iVar11 = iVar11 + 4;
                piVar16[2] = piVar16[2] | *puVar1;
                piVar16 = piVar16 + 1;
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
            }
          }
          iVar8 = iVar8 + 4;
        }
        piVar16 = (int *)piVar5[0x40];
        iVar8 = piVar5[0x41];
        iVar9 = *piVar16;
        if (iVar9 != 0) {
          iVar11 = iVar8;
          piVar5 = piVar16;
          iVar12 = iVar9;
          if ((piVar16[2] | *(uint *)(iVar8 + 8)) == piVar16[2]) {
            do {
              if (iVar12 + -1 == 0) goto LAB_001655a8;
              puVar1 = (uint *)(piVar5 + 3);
              puVar2 = (uint *)(iVar11 + 0xc);
              iVar11 = iVar11 + 4;
              piVar5 = piVar5 + 1;
              iVar12 = iVar12 + -1;
            } while ((*puVar1 | *puVar2) == *puVar1);
          }
          if (iVar9 != 0) {
            if (iVar9 == 0) {
              iVar9 = 1;
            }
            do {
              puVar1 = (uint *)(iVar8 + 8);
              iVar8 = iVar8 + 4;
              piVar16[2] = piVar16[2] | *puVar1;
              piVar16 = piVar16 + 1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
          bVar3 = true;
        }
      }
LAB_001655a8: ;
    }
    if (!bVar3) {
      return;
    }
  } while( true );
}

/* FUN_00165604 @ 0x165604 (388 bytes) */
int FUN_00165604(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar3 = 0;
  do {
    iVar1 = iVar3 * 4 + param_1;
    piVar5 = *(int **)(iVar1 + 0x10);
    if (piVar5 == (int *)0x0) {
      *(int **)(iVar1 + 0x10) = param_2;
      return param_2;
    }
    if (((*(int *)(piVar5[0x22] + 8) == *(int *)(param_2[0x22] + 8)) &&
        (piVar5[0x48] == param_2[0x48])) && (piVar5[0x49] == param_2[0x49])) {
      iVar1 = FUN_001054ec(piVar5,0);
      iVar4 = *(int *)(iVar1 + 0x10);
      iVar1 = FUN_001054ec(param_2,0);
      if (iVar4 == *(int *)(iVar1 + 0x10)) {
        iVar1 = 1;
        while( true ) {
          iVar4 = (**(code **)(*piVar5 + 0x14))(piVar5);
          if (iVar4 < iVar1) {
            return piVar5;
          }
          iVar4 = FUN_00105594(piVar5,iVar1);
          iVar2 = FUN_00105594(param_2,iVar1);
          if (iVar4 != iVar2) break;
          if (((piVar5[iVar1 * 6 + 0x28] & 1U) != (param_2[iVar1 * 6 + 0x28] & 1U)) ||
             (((uint)piVar5[iVar1 * 6 + 0x28] >> 1 & 1) !=
              ((uint)param_2[iVar1 * 6 + 0x28] >> 1 & 1))) break;
          iVar4 = FUN_001054ec(piVar5,iVar1);
          iVar2 = *(int *)(iVar4 + 0x10);
          iVar4 = FUN_001054ec(param_2,iVar1);
          if (iVar2 != *(int *)(iVar4 + 0x10)) break;
          iVar1 = iVar1 + 1;
        }
      }
    }
    iVar3 = iVar3 + 1;
    if (0x1f < iVar3) {
      return param_2;
    }
  } while( true );
}

/* FUN_00165788 @ 0x165788 (628 bytes) */
int FUN_00165788(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  
  iVar6 = 1;
  do {
    iVar5 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar5 < iVar6) {
      return;
    }
    piVar1 = (int *)FUN_00105594(param_1,iVar6);
    iVar5 = (**(code **)(*param_1 + 0x60))(param_1);
    if ((iVar5 == 0) && (iVar5 = (**(code **)(*piVar1 + 0x5c))(piVar1), iVar5 != 0)) {
LAB_00165840:
      iVar7 = 1;
      iVar5 = (**(code **)(*piVar1 + 0x60))(piVar1);
      if ((iVar5 != 0) || (iVar7 = (**(code **)(*piVar1 + 0x14))(piVar1), 0 < iVar7)) {
        iVar5 = 1;
        do {
          uVar3 = FUN_00105594(piVar1,iVar5);
          uVar3 = (**(code **)(*param_1 + 0x94))(param_1,uVar3,param_2);
          iVar4 = FUN_001054ec(piVar1,iVar5);
          iVar5 = iVar5 + 1;
          uVar8 = *(undefined4 *)(iVar4 + 0x10);
          iVar4 = FUN_001054ec(param_1,uVar3);
          *(undefined4 *)(iVar4 + 0x10) = uVar8;
        } while (iVar5 <= iVar7);
      }
    }
    else {
      iVar5 = (**(code **)(*piVar1 + 0x60))(piVar1);
      if (iVar5 != 0) {
        piVar2 = (int *)FUN_00105594(piVar1,1);
        iVar5 = (**(code **)(*piVar2 + 0x5c))();
        if (iVar5 == 0) goto LAB_00165840;
      }
      iVar5 = (**(code **)(*piVar1 + 0x60))(piVar1);
      if (iVar5 != 0) {
        piVar2 = (int *)FUN_00105594(piVar1,1);
        iVar5 = (**(code **)(*piVar2 + 0x5c))();
        if (iVar5 != 0) {
          piVar1 = (int *)FUN_00105594(piVar1,1);
          for (iVar5 = 1; iVar7 = (**(code **)(*piVar1 + 0x14))(piVar1), iVar5 <= iVar7;
              iVar5 = iVar5 + 1) {
            uVar3 = FUN_00105594(piVar1,iVar5);
            uVar3 = (**(code **)(*param_1 + 0x94))(param_1,uVar3,param_2);
            iVar7 = FUN_001054ec(piVar1,iVar5);
            uVar8 = *(undefined4 *)(iVar7 + 0x10);
            iVar7 = FUN_001054ec(param_1,uVar3);
            *(undefined4 *)(iVar7 + 0x10) = uVar8;
          }
        }
      }
    }
    iVar6 = iVar6 + 1;
  } while( true );
}

/* FUN_001659fc @ 0x1659fc (384 bytes) */
int FUN_001659fc(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int *piVar7;
  int iVar8;
  
  piVar7 = *(int **)(param_2 + 0x38);
  if (((((piVar7[5] & 0x20U) == 0) && (piVar7[0x20] != 0)) &&
      (iVar3 = FUN_00126760(piVar7[0x26]), iVar3 != 0)) && ((piVar7[5] & 2U) == 0)) {
    (**(code **)(*piVar7 + 0x50))(piVar7);
  }
  pcVar4 = *(char **)(param_2 + 0x60);
  if (pcVar4 == (char *)0x0) {
    iVar2 = *(int *)(param_2 + 0x38);
    iVar8 = 4;
    iVar3 = param_2;
    do {
      if ((*(char *)(iVar2 + 0xc) != '\0') && (0 < *(int *)(iVar3 + 0x48))) {
        return;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    iVar3 = *(int *)(*param_1 + 0x3c4) + 1;
    *(int *)(*param_1 + 0x3c4) = iVar3;
    *(int *)(*(int *)(param_2 + 0x38) + 0x94) = iVar3;
    *(uint *)(*(int *)(param_2 + 0x38) + 0x14) =
         *(uint *)(*(int *)(param_2 + 0x38) + 0x14) & 0xffffffbf;
  }
  else {
    iVar2 = 4;
    iVar3 = 0;
    pcVar5 = pcVar4;
    pcVar6 = pcVar4;
    do {
      if (((*pcVar5 != '\0') && (*(int *)(pcVar6 + 0x18) != 0)) &&
         (0 < *(int *)(iVar3 * 4 + *(int *)(pcVar6 + 0x18) + 0x48))) {
        return;
      }
      iVar3 = iVar3 + 1;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar2 = *(int *)(*param_1 + 0x3c4) + 1;
    *(int *)(*param_1 + 0x3c4) = iVar2;
    for (iVar3 = *(int *)(*(int *)(pcVar4 + 8) + 0x38); iVar3 != 0;
        iVar3 = FUN_00105594(iVar3,*(undefined4 *)(iVar3 + 0x84))) {
      uVar1 = *(uint *)(iVar3 + 0x14);
      *(int *)(iVar3 + 0x94) = iVar2;
      *(uint *)(iVar3 + 0x14) = uVar1 & 0xffffffbf;
      if ((uVar1 & 0x200) == 0) {
        return;
      }
    }
  }
  return;
}

/* FUN_00165b7c @ 0x165b7c (448 bytes) */
int FUN_00165b7c(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uStack0000002c;
  
  uVar7 = *(undefined4 *)(*param_1 + 0x378);
  uStack0000002c = param_6;
  puVar1 = (undefined4 *)FUN_00193e18(uVar7,0x24);
  uVar2 = DAT_001b0194;
  *puVar1 = uVar7;
  puVar1[4] = 1;
  puVar1[7] = uVar2;
  puVar1[1] = param_2;
  puVar1[3] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[8] = 0;
  puVar1[2] = param_3;
  uVar2 = ((int (*)())FUN_00164e7c)(param_1,*(undefined4 *)(param_2 + 0x38),*(undefined4 *)(param_3 + 0x38),0,
                       param_4,0);
  puVar1[5] = param_4;
  puVar1[4] = uVar2;
  puVar1[6] = param_5;
  uVar2 = (**(code **)(*(int *)param_1[3] + 0x20))
                    ((int *)param_1[3],*(undefined4 *)(param_2 + 0x38));
  puVar1[8] = uVar2;
  puVar1[7] = uStack0000002c;
  puVar6 = *(uint **)(param_2 + 0x40);
  uVar5 = puVar6[1];
  if (uVar5 < *puVar6) {
    _memset((void *)(uVar5 * 4 + puVar6[2]),0,4);
    puVar3 = (undefined4 *)(uVar5 * 4 + puVar6[2]);
    puVar6[1] = uVar5 + 1;
  }
  else {
    puVar3 = (undefined4 *)FUN_0019423c(puVar6,uVar5);
  }
  *puVar3 = puVar1 + 1;
  puVar6 = *(uint **)(param_3 + 0x44);
  uVar5 = puVar6[1];
  if (uVar5 < *puVar6) {
    _memset((void *)(uVar5 * 4 + puVar6[2]),0,4);
    puVar3 = (undefined4 *)(uVar5 * 4 + puVar6[2]);
    puVar6[1] = uVar5 + 1;
  }
  else {
    puVar3 = (undefined4 *)FUN_0019423c(puVar6,uVar5);
  }
  *puVar3 = puVar1 + 1;
  iVar8 = 4;
  pcVar4 = (char *)&STACKARG(0x2c);
  do {
    if (*pcVar4 != '\0') {
      *(int *)(param_2 + 0x48) = *(int *)(param_2 + 0x48) + 1;
    }
    pcVar4 = pcVar4 + 1;
    param_2 = param_2 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *(int *)(param_3 + 0x34) = *(int *)(param_3 + 0x34) + 1;
  return;
}

/* FUN_00165d3c @ 0x165d3c (584 bytes) */
int FUN_00165d3c(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 *param_3;
  undefined4 param_4;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint *puVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  int iVar13;
  
  uVar9 = *(undefined4 *)(param_1[6] + 4);
  *(undefined4 *)(param_2 + 0x150) = uVar9;
  uVar11 = *(undefined4 *)(*param_1 + 0x378);
  puVar3 = (undefined4 *)FUN_00193e18(uVar11,0x74);
  puVar1 = PTR_DAT_001e9138;
  puVar12 = puVar3 + 1;
  puVar2 = PTR_DAT_001e8b48 + 8;
  *puVar3 = uVar11;
  puVar3[1] = puVar2;
  puVar3[0xc] = 0xffffffff;
  puVar3[1] = puVar1 + 8;
  puVar3[0x10] = uVar9;
  iVar13 = 4;
  puVar3[0x1c] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[0xd] = 0;
  puVar3[0xe] = 0;
  puVar3[0xf] = param_2;
  puVar3[0x11] = 0;
  puVar3[0x12] = 0;
  puVar3[0x17] = 0;
  puVar3[0x18] = 0;
  puVar3[0x19] = 0;
  puVar3[0x1a] = 0;
  puVar3[0x1b] = 0;
  puVar4 = puVar12;
  do {
    puVar4[0x12] = 0;
    puVar4 = puVar4 + 1;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  puVar3[4] = 0;
  puVar3[7] = 1;
  puVar3[5] = 0;
  puVar3[6] = 1;
  puVar3[8] = 0;
  puVar3[9] = 0;
  puVar3[10] = 0;
  puVar3[0xb] = 0;
  uVar9 = (**(code **)(*(int *)param_1[2] + 0x4c))((int *)param_1[2],param_2);
  puVar3[0x17] = uVar9;
  uVar9 = *(undefined4 *)(*param_1 + 0x378);
  puVar4 = (undefined4 *)FUN_00193e18(uVar9,0x14);
  *puVar4 = uVar9;
  puVar4[1] = 2;
  puVar4[4] = uVar9;
  puVar4[2] = 0;
  uVar9 = FUN_00193e18(uVar9,8);
  puVar4[3] = uVar9;
  puVar3[0x12] = puVar4 + 1;
  uVar9 = *(undefined4 *)(*param_1 + 0x378);
  puVar4 = (undefined4 *)FUN_00193e18(uVar9,0x14);
  *puVar4 = uVar9;
  puVar4[1] = 2;
  puVar4[4] = uVar9;
  puVar4[2] = 0;
  uVar9 = FUN_00193e18(uVar9,8);
  puVar4[3] = uVar9;
  puVar3[0x11] = puVar4 + 1;
  puVar3[0xc] = 0xffffffff;
  puVar3[0xe] = 0;
  puVar3[0xd] = param_4;
  uVar11 = param_3[7];
  uVar9 = param_3[1];
  uVar5 = param_3[2];
  uVar7 = param_3[5];
  uVar6 = param_3[6];
  puVar3[4] = *param_3;
  puVar3[5] = uVar9;
  puVar3[6] = uVar5;
  puVar3[9] = uVar7;
  puVar3[10] = uVar6;
  puVar3[0xb] = uVar11;
  puVar10 = (uint *)param_1[6];
  uVar8 = puVar10[1];
  if (uVar8 < *puVar10) {
    _memset((void *)(uVar8 * 4 + puVar10[2]),0,4);
    puVar10[1] = uVar8 + 1;
    puVar4 = (undefined4 *)(uVar8 * 4 + puVar10[2]);
  }
  else {
    puVar4 = (undefined4 *)FUN_0019423c(puVar10,uVar8);
  }
  *puVar4 = puVar12;
  ((int (*)())FUN_00172078)(param_1[2],puVar12);
  return puVar12;
}

/* FUN_00165fa8 @ 0x165fa8 (720 bytes) */
int FUN_00165fa8(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint *puVar9;
  undefined4 uVar10;
  uint uVar11;
  uint *puVar12;
  int iVar13;
  
  uVar11 = ((uint *)param_1[5])[1];
  uVar4 = 0;
  if (uVar11 != 0) {
    uVar7 = 0;
    puVar12 = (uint *)param_1[5];
    uVar4 = uVar11;
    do {
      if (uVar7 < *puVar12) {
        puVar9 = puVar12;
        if (uVar4 <= uVar7) {
          _memset((void *)(uVar4 * 4 + puVar12[2]),0,(uVar7 - uVar4) * 4 + 4);
          puVar12[1] = uVar7 + 1;
          puVar9 = (uint *)param_1[5];
        }
        piVar3 = (int *)(uVar7 * 4 + puVar12[2]);
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar12,uVar7);
        puVar9 = (uint *)param_1[5];
      }
      if (param_2 == *(int *)(*piVar3 + 0x38)) {
        if (uVar7 < *puVar9) {
          uVar4 = puVar9[1];
          if (uVar4 <= uVar7) {
            _memset((void *)(uVar4 * 4 + puVar9[2]),0,(uVar7 - uVar4) * 4 + 4);
            puVar9[1] = uVar7 + 1;
          }
          puVar5 = (undefined4 *)(uVar7 * 4 + puVar9[2]);
        }
        else {
          puVar5 = (undefined4 *)FUN_0019423c(puVar9,uVar7);
        }
        return (undefined4 *)*puVar5;
      }
      uVar4 = puVar9[1];
      uVar7 = uVar7 + 1;
      puVar12 = puVar9;
    } while (uVar7 < uVar4);
  }
  uVar10 = *(undefined4 *)(*param_1 + 0x378);
  puVar6 = (undefined4 *)FUN_00193e18(uVar10,0x74);
  puVar1 = PTR_DAT_001e9138;
  puVar8 = puVar6 + 1;
  puVar2 = PTR_DAT_001e8b48 + 8;
  *puVar6 = uVar10;
  puVar6[1] = puVar2;
  puVar6[0xc] = 0xffffffff;
  puVar6[1] = puVar1 + 8;
  puVar6[0xf] = param_2;
  iVar13 = 4;
  puVar6[0x10] = uVar4;
  puVar6[0x1c] = 0;
  puVar6[2] = 0;
  puVar6[3] = 0;
  puVar6[0xd] = 0;
  puVar6[0xe] = 0;
  puVar6[0x11] = 0;
  puVar6[0x12] = 0;
  puVar6[0x17] = 0;
  puVar6[0x18] = 0;
  puVar6[0x19] = 0;
  puVar6[0x1a] = 0;
  puVar6[0x1b] = 0;
  puVar5 = puVar8;
  do {
    puVar5[0x12] = 0;
    puVar5 = puVar5 + 1;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  puVar6[4] = 0;
  puVar6[7] = 1;
  puVar6[5] = 0;
  puVar6[6] = 1;
  puVar6[8] = 0;
  puVar6[9] = 0;
  puVar6[10] = 0;
  puVar6[0xb] = 0;
  uVar10 = *(undefined4 *)(*param_1 + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar10,0x14);
  *puVar5 = uVar10;
  puVar5[1] = 2;
  puVar5[4] = uVar10;
  puVar5[2] = 0;
  uVar10 = FUN_00193e18(uVar10,8);
  puVar5[3] = uVar10;
  puVar6[0x12] = puVar5 + 1;
  uVar10 = *(undefined4 *)(*param_1 + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar10,0x14);
  *puVar5 = uVar10;
  puVar5[1] = 2;
  puVar5[4] = uVar10;
  puVar5[2] = 0;
  uVar10 = FUN_00193e18(uVar10,8);
  puVar5[3] = uVar10;
  puVar6[0x11] = puVar5 + 1;
  puVar6[0xc] = 0;
  puVar12 = (uint *)param_1[5];
  uVar4 = puVar12[1];
  if (uVar4 < *puVar12) {
    _memset((void *)(uVar4 * 4 + puVar12[2]),0,4);
    piVar3 = (int *)(uVar4 * 4 + puVar12[2]);
    puVar12[1] = uVar4 + 1;
  }
  else {
    piVar3 = (int *)FUN_0019423c(puVar12,uVar4);
  }
  *piVar3 = (int)puVar8;
  return puVar8;
}

/* FUN_0016629c @ 0x16629c (1448 bytes) */
int FUN_0016629c(param_1)
  undefined4 *param_1;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  int iVar18;
  int iVar19;
  int local_58 [4];
  int local_48 [4];
  
  piVar14 = (int *)0x0;
  iVar13 = param_1[0x27];
  do {
    while( true ) {
      if (*(int *)(iVar13 + 8) == 0) {
        if (piVar14 != (int *)0x0) {
          (**(code **)(*piVar14 + 4))(piVar14);
        }
        return 0;
      }
      iVar2 = (**(code **)(**(int **)(iVar13 + 0x38) + 0x14))();
      if (1 < iVar2) break;
LAB_00166334:
      iVar2 = *(int *)(iVar13 + 8);
      FUN_0019401c(iVar13);
      iVar13 = iVar2;
    }
    iVar7 = 0;
    local_58[0] = DAT_001b0198;
    iVar18 = 4;
    iVar2 = iVar13;
    do {
      if (0 < *(int *)(iVar2 + 0x48)) {
        *(undefined1 *)((int)local_58 + iVar7) = 0;
      }
      iVar7 = iVar7 + 1;
      iVar2 = iVar2 + 4;
      iVar18 = iVar18 + -1;
    } while (iVar18 != 0);
    if (local_58[0] == DAT_001b0198) goto LAB_00166334;
    iVar2 = *(int *)(iVar13 + 0x38);
    if (piVar14 == (int *)0x0) {
      piVar14 = (int *)FUN_001043f0(0x12,*param_1);
    }
    iVar18 = piVar14[0x53];
    iVar7 = FUN_001054ec(piVar14,0);
    *(undefined4 *)(iVar7 + 0xc) = 0;
    *(int *)(iVar7 + 8) = iVar18;
    iVar7 = FUN_001054ec(iVar2,0);
    piVar14[0x27] = *(int *)(iVar7 + 0x10);
    iVar7 = FUN_001054ec(piVar14,0);
    FUN_000f3908(local_48,*(undefined4 *)(iVar7 + 0x10));
    piVar14[3] = local_48[0];
    uVar3 = FUN_00105594(iVar2,1);
    FUN_00106004(piVar14,1,uVar3,0,*param_1);
    iVar7 = FUN_001054ec(iVar2,1);
    uVar3 = *(undefined4 *)(iVar7 + 0x10);
    iVar7 = FUN_001054ec(piVar14,1);
    *(undefined4 *)(iVar7 + 0x10) = uVar3;
    uVar3 = FUN_00105594(iVar2,2);
    FUN_00106004(piVar14,2,uVar3,0,*param_1);
    iVar7 = FUN_001054ec(iVar2,2);
    uVar3 = *(undefined4 *)(iVar7 + 0x10);
    iVar7 = FUN_001054ec(piVar14,2);
    *(undefined4 *)(iVar7 + 0x10) = uVar3;
    FUN_00103d50(piVar14 + 0x2f,1,*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x9a);
    iVar2 = (**(code **)(*(int *)param_1[2] + 0xc))((int *)param_1[2],piVar14);
    if (iVar2 != 0) {
      *(int **)(iVar13 + 0x38) = piVar14;
      *(undefined4 *)(iVar13 + 0x2c) = 0xffffffff;
      uVar3 = (**(code **)(*(int *)param_1[2] + 0x4c))((int *)param_1[2],piVar14);
      *(undefined4 *)(iVar13 + 0x58) = uVar3;
      iVar2 = FUN_000e07dc(*param_1,0x28);
      if (iVar2 != 0) {
        iVar2 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar13);
        uVar3 = 1;
        if (iVar2 != 0) goto LAB_001664ec;
      }
      uVar3 = 0;
LAB_001664ec:
      *(undefined4 *)(iVar13 + 0x5c) = uVar3;
      uVar15 = 0;
      ((int (*)())FUN_00172078)(param_1[2],iVar13);
      puVar17 = *(uint **)(iVar13 + 0x44);
      uVar12 = puVar17[1];
      if (0 < (int)uVar12) {
        while( true ) {
          if (uVar15 < *puVar17) {
            uVar10 = puVar17[1];
            if (uVar10 <= uVar15) {
              _memset((void *)(uVar10 * 4 + puVar17[2]),0,(uVar15 - uVar10) * 4 + 4);
              puVar17[1] = uVar15 + 1;
            }
            puVar4 = (undefined4 *)(uVar15 * 4 + puVar17[2]);
          }
          else {
            puVar4 = (undefined4 *)FUN_0019423c(puVar17,uVar15);
          }
          uVar15 = uVar15 + 1;
          piVar14 = (int *)*puVar4;
          if (piVar14[2] == 0) {
            iVar7 = *piVar14;
            iVar18 = 4;
            iVar2 = iVar7;
            piVar9 = piVar14;
            do {
              if (*(char *)(piVar9 + 6) != '\0') {
                *(int *)(iVar2 + 0x48) = *(int *)(iVar2 + 0x48) + 1;
              }
              piVar9 = (int *)((int)piVar9 + 1);
              iVar2 = iVar2 + 4;
              iVar18 = iVar18 + -1;
            } while (iVar18 != 0);
            iVar2 = (**(code **)(*(int *)param_1[3] + 0x20))
                              ((int *)param_1[3],*(undefined4 *)(iVar7 + 0x38));
            piVar14[7] = iVar2;
          }
          if (uVar12 == uVar15) break;
          puVar17 = *(uint **)(iVar13 + 0x44);
        }
      }
      puVar17 = *(uint **)(iVar13 + 0x40);
      uVar12 = puVar17[1];
      uVar15 = uVar12 - 1;
      if (-1 < (int)uVar15) {
        iVar2 = uVar15 * 4;
        uVar10 = 0;
        while( true ) {
          if (uVar15 < *puVar17) {
            uVar5 = puVar17[1];
            if (uVar5 <= uVar15) {
              _memset((void *)(uVar5 * 4 + puVar17[2]),0,(uVar15 - uVar5) * 4 + 4);
              puVar17[1] = uVar15 + 1;
            }
            piVar14 = (int *)(iVar2 + puVar17[2]);
          }
          else {
            piVar14 = (int *)FUN_0019423c(puVar17,uVar15);
          }
          iVar7 = *piVar14;
          iVar18 = *(int *)(iVar7 + 4);
          if (*(int *)(iVar18 + 0x2c) < 0) {
            if (*(int *)(iVar7 + 8) == 0) {
              FUN_00106004(*(undefined4 *)(iVar18 + 0x38),*(undefined4 *)(iVar7 + 0x10),
                           *(undefined4 *)(iVar13 + 0x38),0,*param_1);
              iVar1 = *(int *)(iVar18 + 0x34);
              if (iVar1 == 0) {
                FUN_0019401c(iVar18);
                iVar1 = *(int *)(iVar18 + 0x34);
              }
              puVar17 = *(uint **)(iVar18 + 0x44);
              *(int *)(iVar18 + 0x34) = iVar1 + 1;
              uVar5 = puVar17[1];
              uVar16 = uVar5 - 1;
              if (-1 < (int)uVar16) {
                iVar1 = uVar16 * 4;
                uVar11 = 0;
                while( true ) {
                  if (uVar16 < *puVar17) {
                    uVar6 = puVar17[1];
                    if (uVar6 <= uVar16) {
                      _memset((void *)(uVar6 * 4 + puVar17[2]),0,(uVar16 - uVar6) * 4 + 4);
                      puVar17[1] = uVar16 + 1;
                    }
                    piVar14 = (int *)(iVar1 + puVar17[2]);
                  }
                  else {
                    piVar14 = (int *)FUN_0019423c(puVar17,uVar16);
                  }
                  piVar14 = (int *)*piVar14;
                  if (((piVar14[2] == 0) && (piVar14[4] == *(int *)(iVar7 + 0x10))) &&
                     (0 < piVar14[5])) {
                    iVar8 = *piVar14;
                    iVar19 = 4;
                    do {
                      if (*(char *)(piVar14 + 6) != '\0') {
                        *(int *)(iVar8 + 0x48) = *(int *)(iVar8 + 0x48) + -1;
                      }
                      piVar14 = (int *)((int)piVar14 + 1);
                      iVar8 = iVar8 + 4;
                      iVar19 = iVar19 + -1;
                    } while (iVar19 != 0);
                    FUN_00194208(*(undefined4 *)(iVar18 + 0x44),uVar16);
                  }
                  uVar11 = uVar11 + 1;
                  uVar16 = uVar16 - 1;
                  iVar1 = iVar1 + -4;
                  if (uVar5 == uVar11) break;
                  puVar17 = *(uint **)(iVar18 + 0x44);
                }
              }
            }
          }
          else {
            (**(code **)(**(int **)(iVar18 + 0x38) + 0x60))();
            FUN_00194208(*(undefined4 *)(iVar13 + 0x40),uVar15);
          }
          uVar10 = uVar10 + 1;
          uVar15 = uVar15 - 1;
          iVar2 = iVar2 + -4;
          if (uVar12 == uVar10) break;
          puVar17 = *(uint **)(iVar13 + 0x40);
        }
      }
      FUN_0019401c(iVar13);
      return iVar13;
    }
    iVar13 = *(int *)(iVar13 + 8);
  } while( true );
}

/* FUN_00166844 @ 0x166844 (456 bytes) */
int FUN_00166844(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  uint *puVar12;
  undefined4 uVar13;
  uint uVar14;
  int iVar15;
  
  uVar14 = 0;
  puVar12 = *(uint **)(param_2 + 0x44);
  uVar10 = puVar12[1];
  if (0 < (int)uVar10) {
    while( true ) {
      if (uVar14 < *puVar12) {
        uVar3 = puVar12[1];
        if (uVar3 <= uVar14) {
          _memset((void *)(uVar3 * 4 + puVar12[2]),0,(uVar14 - uVar3) * 4 + 4);
          puVar12[1] = uVar14 + 1;
        }
        puVar4 = (undefined4 *)(uVar14 * 4 + puVar12[2]);
      }
      else {
        puVar4 = (undefined4 *)FUN_0019423c(puVar12,uVar14);
      }
      piVar11 = (int *)*puVar4;
      if (piVar11[7] == 1) {
        uVar13 = *(undefined4 *)(*param_1 + 0x378);
        puVar4 = (undefined4 *)FUN_00193e18(uVar13,0x24);
        uVar1 = DAT_001b0194;
        *puVar4 = uVar13;
        puVar4[1] = 0;
        iVar7 = 0;
        puVar4[7] = uVar1;
        puVar4[4] = 1;
        iVar8 = piVar11[6];
        iVar2 = *piVar11;
        iVar6 = piVar11[3];
        puVar4[3] = 0;
        puVar4[5] = 0;
        puVar4[6] = 0;
        puVar4[8] = 0;
        iVar15 = 4;
        puVar4[7] = iVar8;
        puVar4[1] = iVar2;
        puVar4[4] = iVar6;
        puVar4[2] = param_3;
        piVar9 = piVar11;
        do {
          if (*(char *)(piVar9 + 6) != '\0') {
            iVar2 = iVar7 * 4 + *piVar11;
            *(int *)(iVar2 + 0x48) = *(int *)(iVar2 + 0x48) + 1;
          }
          iVar7 = iVar7 + 1;
          piVar9 = (int *)((int)piVar9 + 1);
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
        puVar4[8] = 1;
        puVar12 = *(uint **)(param_3 + 0x44);
        uVar10 = puVar12[1];
        if (uVar10 < *puVar12) {
          _memset((void *)(uVar10 * 4 + puVar12[2]),0,4);
          puVar5 = (undefined4 *)(uVar10 * 4 + puVar12[2]);
          puVar12[1] = uVar10 + 1;
        }
        else {
          puVar5 = (undefined4 *)FUN_0019423c(puVar12,uVar10);
        }
        *puVar5 = puVar4 + 1;
        return;
      }
      uVar14 = uVar14 + 1;
      if (uVar10 == uVar14) break;
      puVar12 = *(uint **)(param_2 + 0x44);
    }
  }
  return;
}

/* FUN_00166a0c @ 0x166a0c (412 bytes) */
int FUN_00166a0c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  
  uVar6 = 0;
  puVar9 = *(uint **)(param_2 + 0x40);
  uVar4 = puVar9[1];
  if (0 < (int)uVar4) {
    while( true ) {
      if (uVar6 < *puVar9) {
        uVar1 = puVar9[1];
        if (uVar1 <= uVar6) {
          _memset((void *)(uVar1 * 4 + puVar9[2]),0,(uVar6 - uVar1) * 4 + 4);
          puVar9[1] = uVar6 + 1;
        }
        piVar2 = (int *)(uVar6 * 4 + puVar9[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar9,uVar6);
      }
      iVar7 = *piVar2;
      if (*(int *)(iVar7 + 8) == 0) {
        iVar5 = *(int *)(iVar7 + 4);
        uVar8 = 0;
        puVar9 = *(uint **)(iVar5 + 0x44);
        uVar1 = puVar9[1];
        if (0 < (int)uVar1) {
          while( true ) {
            if (uVar8 < *puVar9) {
              uVar3 = puVar9[1];
              if (uVar3 <= uVar8) {
                _memset((void *)(uVar3 * 4 + puVar9[2]),0,(uVar8 - uVar3) * 4 + 4);
                puVar9[1] = uVar8 + 1;
              }
              piVar2 = (int *)(uVar8 * 4 + puVar9[2]);
            }
            else {
              piVar2 = (int *)FUN_0019423c(puVar9,uVar8);
            }
            piVar2 = (int *)*piVar2;
            if ((((piVar2[2] == 0) && (param_2 != *piVar2)) && (piVar2[4] == *(int *)(iVar7 + 0x10))
                ) && ((piVar2[5] == *(int *)(iVar7 + 0x14) &&
                      ((*(uint *)(*(int *)(*piVar2 + 0x38) + 0x14) & 0x40) != 0)))) {
              return 1;
            }
            uVar8 = uVar8 + 1;
            if (uVar1 == uVar8) break;
            puVar9 = *(uint **)(iVar5 + 0x44);
          }
        }
      }
      uVar6 = uVar6 + 1;
      if (uVar4 == uVar6) break;
      puVar9 = *(uint **)(param_2 + 0x40);
    }
  }
  return 0;
}

/* FUN_00166ba8 @ 0x166ba8 (340 bytes) */
int FUN_00166ba8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int *piVar9;
  
  if (*(int *)(param_1 + 0x2c) < *(int *)(param_2 + 0x30)) {
LAB_00166ce4:
    uVar5 = 0;
  }
  else {
    iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))
                      (*(int **)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38));
    if (iVar1 != 0) {
      puVar8 = *(uint **)(param_2 + 0x44);
      uVar7 = 0;
      uVar6 = puVar8[1];
      if (0 < (int)uVar6) {
        while( true ) {
          if (uVar7 < *puVar8) {
            uVar2 = puVar8[1];
            if (uVar2 <= uVar7) {
              _memset((void *)(uVar2 * 4 + puVar8[2]),0,(uVar7 - uVar2) * 4 + 4);
              puVar8[1] = uVar7 + 1;
            }
            puVar3 = (undefined4 *)(uVar7 * 4 + puVar8[2]);
          }
          else {
            puVar3 = (undefined4 *)FUN_0019423c(puVar8,uVar7);
          }
          piVar9 = (int *)*puVar3;
          if ((((piVar9[2] == 0) &&
               (iVar1 = *piVar9,
               *(int *)(*(int *)(iVar1 + 0x38) + 0x158) == *(int *)(param_1 + 0x10))) &&
              (iVar4 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))(), iVar4 != 0)) &&
             ((piVar9[7] != 0 && (*(int *)(param_1 + 0x124) <= *(int *)(iVar1 + 0x2c)))))
          goto LAB_00166ce4;
          uVar7 = uVar7 + 1;
          if (uVar6 == uVar7) break;
          puVar8 = *(uint **)(param_2 + 0x44);
        }
      }
    }
    uVar5 = 1;
  }
  return uVar5;
}

/* FUN_00166cfc @ 0x166cfc (1024 bytes) */
int FUN_00166cfc(param_1)
  int param_1;
{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  
  uVar8 = 0;
  FUN_00193f08(param_1 + 0x34);
  FUN_00193f08(param_1 + 0x4c);
  FUN_00193f08(param_1 + 100);
  FUN_00193f08(param_1 + 0x7c);
  FUN_00193fa4(param_1 + 0x94);
  puVar10 = *(uint **)(param_1 + 0x18);
  uVar6 = puVar10[1];
  if (0 < (int)uVar6) {
    while( true ) {
      if (uVar8 < *puVar10) {
        uVar1 = puVar10[1];
        if (uVar1 <= uVar8) {
          _memset((void *)(uVar1 * 4 + puVar10[2]),0,(uVar8 - uVar1) * 4 + 4);
          puVar10[1] = uVar8 + 1;
        }
        puVar2 = (undefined4 *)(uVar8 * 4 + puVar10[2]);
      }
      else {
        puVar2 = (undefined4 *)FUN_0019423c(puVar10,uVar8);
      }
      uVar8 = uVar8 + 1;
      piVar7 = (int *)*puVar2;
      uVar9 = 0;
      *(undefined4 *)(piVar7[0xe] + 0x150) = 0;
      puVar10 = (uint *)piVar7[0x10];
      uVar1 = puVar10[1];
      if (0 < (int)uVar1) {
        while( true ) {
          if (uVar9 < *puVar10) {
            uVar3 = puVar10[1];
            if (uVar3 <= uVar9) {
              _memset((void *)(uVar3 * 4 + puVar10[2]),0,(uVar9 - uVar3) * 4 + 4);
              puVar10[1] = uVar9 + 1;
            }
            piVar4 = (int *)(uVar9 * 4 + puVar10[2]);
          }
          else {
            piVar4 = (int *)FUN_0019423c(puVar10,uVar9);
          }
          uVar9 = uVar9 + 1;
          iVar5 = *piVar4;
          if (iVar5 != 0) {
            FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
          }
          if (uVar1 == uVar9) break;
          puVar10 = (uint *)piVar7[0x10];
        }
      }
      iVar5 = piVar7[0x18];
      if (iVar5 != 0) {
        *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + -1;
        iVar5 = piVar7[0x18];
        if ((*(int *)(iVar5 + 0x10) < 1) && (iVar5 != 0)) {
          FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
        }
      }
      iVar5 = piVar7[0x10];
      if (iVar5 != 0) {
        FUN_00193cc0(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8));
        FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
      }
      iVar5 = piVar7[0x11];
      if (iVar5 != 0) {
        FUN_00193cc0(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8));
        FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
      }
      (**(code **)(*piVar7 + 4))(piVar7);
      if (uVar6 == uVar8) break;
      puVar10 = *(uint **)(param_1 + 0x18);
    }
  }
  puVar10 = *(uint **)(param_1 + 0x14);
  uVar8 = 0;
  uVar6 = puVar10[1];
  if (0 < (int)uVar6) {
    while( true ) {
      if (uVar8 < *puVar10) {
        uVar1 = puVar10[1];
        if (uVar1 <= uVar8) {
          _memset((void *)(uVar1 * 4 + puVar10[2]),0,(uVar8 - uVar1) * 4 + 4);
          puVar10[1] = uVar8 + 1;
        }
        puVar2 = (undefined4 *)(uVar8 * 4 + puVar10[2]);
      }
      else {
        puVar2 = (undefined4 *)FUN_0019423c(puVar10,uVar8);
      }
      uVar8 = uVar8 + 1;
      piVar7 = (int *)*puVar2;
      uVar9 = 0;
      puVar10 = (uint *)piVar7[0x10];
      uVar1 = puVar10[1];
      if (0 < (int)uVar1) {
        while( true ) {
          if (uVar9 < *puVar10) {
            uVar3 = puVar10[1];
            if (uVar3 <= uVar9) {
              _memset((void *)(uVar3 * 4 + puVar10[2]),0,(uVar9 - uVar3) * 4 + 4);
              puVar10[1] = uVar9 + 1;
            }
            piVar4 = (int *)(uVar9 * 4 + puVar10[2]);
          }
          else {
            piVar4 = (int *)FUN_0019423c(puVar10,uVar9);
          }
          uVar9 = uVar9 + 1;
          iVar5 = *piVar4;
          if (iVar5 != 0) {
            FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
          }
          if (uVar1 == uVar9) break;
          puVar10 = (uint *)piVar7[0x10];
        }
      }
      iVar5 = piVar7[0x18];
      if (iVar5 != 0) {
        *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + -1;
        iVar5 = piVar7[0x18];
        if ((*(int *)(iVar5 + 0x10) < 1) && (iVar5 != 0)) {
          FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
        }
      }
      iVar5 = piVar7[0x10];
      if (iVar5 != 0) {
        FUN_00193cc0(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8));
        FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
      }
      iVar5 = piVar7[0x11];
      if (iVar5 != 0) {
        FUN_00193cc0(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8));
        FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
      }
      (**(code **)(*piVar7 + 4))(piVar7);
      if (uVar6 == uVar8) break;
      puVar10 = *(uint **)(param_1 + 0x14);
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0x18) + 4) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x14) + 4) = 0;
  return;
}

/* FUN_001670fc @ 0x1670fc (2424 bytes) */
int FUN_001670fc(param_1)
  int *param_1;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  uint uVar17;
  uint uVar18;
  undefined4 uVar19;
  uint *puVar20;
  int iVar21;
  int iVar22;
  uint local_68 [4];
  int local_58;
  uint local_54;
  
  uVar19 = *(undefined4 *)(*param_1 + 0x378);
  uVar18 = *(uint *)(param_1[6] + 4);
  puVar5 = (undefined4 *)FUN_00193e18(uVar19,0x10);
  piVar13 = puVar5 + 1;
  puVar5[1] = 1;
  *puVar5 = uVar19;
  puVar5[2] = 0x20;
  iVar11 = 0;
  piVar4 = piVar13;
  do {
    bVar1 = iVar11 == -1;
    piVar4[2] = 0;
    iVar11 = iVar11 + 1;
    piVar4 = piVar4 + 1;
  } while (bVar1);
  iVar6 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),uVar18 << 2);
  iVar11 = *piVar13;
  if (iVar11 != 0) {
    piVar4 = piVar13;
    if (iVar11 == 0) {
      iVar11 = 1;
    }
    do {
      piVar4[2] = 0;
      piVar4 = piVar4 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  ((int (*)())FUN_00172000)(param_1[2]);
  iVar21 = 4;
  iVar11 = 0;
  do {
    *(undefined4 *)(iVar11 + (int)local_68) = 0;
    iVar11 = iVar11 + 4;
    iVar21 = iVar21 + -1;
  } while (iVar21 != 0);
  uVar15 = uVar18 - 1;
  if ((int)uVar15 < 0) {
    iVar21 = 0;
    bVar1 = false;
    local_58 = 0;
  }
  else {
    iVar11 = uVar15 * 4;
    iVar10 = iVar11 + 4;
    puVar16 = (uint *)(iVar6 + iVar11);
    iVar21 = 0;
    bVar1 = false;
    local_58 = 0;
    uVar14 = 0;
    local_54 = uVar18;
    do {
      puVar20 = (uint *)param_1[6];
      if (uVar15 < *puVar20) {
        uVar7 = puVar20[1];
        if (uVar7 <= uVar15) {
          _memset((void *)(uVar7 * 4 + puVar20[2]),0,(uVar15 - uVar7) * 4 + 4);
          puVar20[1] = uVar18;
        }
        piVar4 = (int *)(iVar11 + puVar20[2]);
      }
      else {
        piVar4 = (int *)FUN_0019423c(puVar20,uVar15);
      }
      iVar12 = *piVar4;
      iVar3 = FUN_000e07dc(*param_1,0x28);
      if (iVar3 == 0) {
LAB_001672b8:
        uVar19 = 0;
      }
      else {
        iVar3 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar12);
        uVar19 = 1;
        if (iVar3 == 0) goto LAB_001672b8;
      }
      *(undefined4 *)(iVar12 + 0x5c) = uVar19;
      uVar7 = 0;
      uVar19 = (**(code **)(*(int *)param_1[2] + 0x4c))
                         ((int *)param_1[2],*(undefined4 *)(iVar12 + 0x38));
      *(undefined4 *)(iVar12 + 0x58) = uVar19;
      (**(code **)(*(int *)param_1[2] + 0x48))((int *)param_1[2],iVar12);
      (**(code **)(*(int *)param_1[2] + 0x44))((int *)param_1[2],iVar12);
      ((int (*)())FUN_00172078)(param_1[2],iVar12);
      *puVar16 = 0;
      puVar20 = *(uint **)(iVar12 + 0x40);
      uVar17 = puVar20[1];
      if (0 < (int)uVar17) {
        while( true ) {
          if (uVar7 < *puVar20) {
            uVar9 = puVar20[1];
            if (uVar9 <= uVar7) {
              _memset((void *)(uVar9 * 4 + puVar20[2]),0,(uVar7 - uVar9) * 4 + 4);
              puVar20[1] = uVar7 + 1;
            }
            piVar4 = (int *)(uVar7 * 4 + puVar20[2]);
          }
          else {
            piVar4 = (int *)FUN_0019423c(puVar20,uVar7);
          }
          uVar7 = uVar7 + 1;
          iVar8 = *piVar4;
          iVar3 = *(int *)(iVar12 + 0x14);
          iVar22 = *(int *)(iVar8 + 4);
          *(int *)(iVar22 + 0x34) = *(int *)(iVar22 + 0x34) + 1;
          iVar8 = *(int *)(iVar8 + 0xc) + *(int *)(iVar22 + 0x14);
          if (iVar3 < iVar8) {
            iVar3 = iVar8;
          }
          iVar8 = *(int *)(iVar22 + 0x3c);
          *(int *)(iVar12 + 0x14) = iVar3;
          if ((int)uVar15 < iVar8) {
            uVar9 = *(int *)(iVar6 + iVar8 * 4) << (iVar8 - uVar15 & 0x3f) | *puVar16;
            *puVar16 = uVar9;
            *puVar16 = uVar9 | 1 << ((*(int *)(iVar22 + 0x3c) - uVar15) - 1 & 0x3f);
          }
          if (uVar17 == uVar7) break;
          puVar20 = *(uint **)(iVar12 + 0x40);
        }
      }
      iVar3 = *(int *)(iVar12 + 0xc);
      if (iVar21 < iVar3) {
        iVar21 = iVar3;
      }
      if (*(int *)(*(int *)(*param_1 + 0x30c) + 0x54) <= iVar21) {
        FUN_000e1534(*param_1,0xf);
      }
      iVar8 = (**(code **)(*(int *)param_1[3] + 0x20))
                        ((int *)param_1[3],*(undefined4 *)(iVar12 + 0x38));
      if ((iVar8 != 0) ||
         (iVar8 = (**(code **)(*(int *)param_1[3] + 0x24))
                            ((int *)param_1[3],*(undefined4 *)(iVar12 + 0x38)), iVar8 != 0)) {
        if (iVar3 < 4) {
          local_68[iVar3] = local_68[iVar3] + 1;
        }
        if (0 < iVar3) {
          bVar1 = true;
        }
        param_1[0x65] = param_1[0x65] + 1;
        iVar3 = (**(code **)(**(int **)(iVar12 + 0x38) + 0x30))();
        if (iVar3 != 0) {
          uVar7 = *(uint *)(*(int *)(iVar12 + 0x38) + 0x134);
          if ((int)uVar7 < 0x20) {
            if ((int)uVar7 < 0) goto LAB_0016753c;
          }
          else {
            FUN_000e1534(*param_1,0xf);
          }
          uVar17 = uVar7 >> 3 & 0x1ffffffc;
          *(uint *)((int)piVar13 + uVar17 + 8) =
               1 << (uVar7 & 0x1f) | *(uint *)((int)piVar13 + uVar17 + 8);
        }
      }
LAB_0016753c:
      *(uint *)(iVar12 + 0x10) = uVar15;
      if (*(int *)(iVar12 + 0x1c) == 0) {
        iVar3 = (**(code **)(*(int *)param_1[2] + 0x28))
                          ((int *)param_1[2],*(undefined4 *)(iVar12 + 0x38));
        uVar19 = 0;
        if (iVar3 != 0) goto LAB_00167574;
      }
      else {
LAB_00167574:
        uVar19 = 1;
      }
      puVar20 = *(uint **)(iVar12 + 0x44);
      uVar17 = 0;
      *(undefined4 *)(iVar12 + 0x1c) = uVar19;
      uVar7 = puVar20[1];
      if (0 < (int)uVar7) {
        do {
          if (uVar17 < *puVar20) {
            uVar9 = puVar20[1];
            if (uVar9 <= uVar17) {
              _memset((void *)(uVar9 * 4 + puVar20[2]),0,(uVar17 - uVar9) * 4 + 4);
              puVar20[1] = uVar17 + 1;
            }
            piVar4 = (int *)(uVar17 * 4 + puVar20[2]);
          }
          else {
            piVar4 = (int *)FUN_0019423c(puVar20,uVar17);
          }
          uVar17 = uVar17 + 1;
          piVar4 = (int *)*piVar4;
          if (piVar4[2] == 0) {
            iVar8 = *piVar4;
            iVar22 = 4;
            iVar3 = iVar8;
            do {
              if (*(char *)(piVar4 + 6) != '\0') {
                *(int *)(iVar3 + 0x48) = *(int *)(iVar3 + 0x48) + 1;
              }
              piVar4 = (int *)((int)piVar4 + 1);
              iVar3 = iVar3 + 4;
              iVar22 = iVar22 + -1;
            } while (iVar22 != 0);
            if ((*(int *)(iVar8 + 0x1c) != 0) || (uVar19 = 0, *(int *)(iVar12 + 0x1c) != 0)) {
              uVar19 = 1;
            }
            *(undefined4 *)(iVar8 + 0x1c) = uVar19;
            iVar3 = (**(code **)(*(int *)param_1[3] + 0x20))
                              ((int *)param_1[3],*(undefined4 *)(iVar12 + 0x38));
            if ((iVar3 == 0) &&
               (iVar3 = (**(code **)(*(int *)param_1[3] + 0x24))
                                  ((int *)param_1[3],*(undefined4 *)(iVar12 + 0x38)), iVar3 == 0)) {
              iVar22 = *(int *)(iVar8 + 0xc);
              iVar3 = *(int *)(iVar12 + 0xc);
              if (iVar22 < *(int *)(iVar12 + 0xc)) {
LAB_001676d0:
                iVar22 = iVar3;
              }
            }
            else {
              iVar22 = *(int *)(iVar8 + 0xc);
              iVar3 = *(int *)(iVar12 + 0xc) + 1;
              if (iVar22 < iVar3) goto LAB_001676d0;
            }
            *(int *)(iVar8 + 0xc) = iVar22;
          }
          if (uVar7 == uVar17) break;
          puVar20 = *(uint **)(iVar12 + 0x44);
        } while( true );
      }
      uVar17 = 0;
      iVar3 = iVar10;
      uVar7 = uVar18;
      do {
        if ((1 << (uVar17 & 0x3f) & *puVar16) != 0) {
          puVar20 = (uint *)param_1[6];
          if (uVar7 < *puVar20) {
            uVar9 = puVar20[1];
            if (uVar9 <= uVar7) {
              _memset((void *)(uVar9 * 4 + puVar20[2]),0,(uVar7 - uVar9) * 4 + 4);
              puVar20[1] = uVar7 + 1;
            }
            piVar4 = (int *)(iVar3 + puVar20[2]);
          }
          else {
            piVar4 = (int *)FUN_0019423c(puVar20,uVar7);
          }
          if (*(int *)(*piVar4 + 0x5c) == 0) {
            iVar8 = *(int *)(*piVar4 + 0x58);
            if (iVar8 == 1) {
              *(int *)(iVar12 + 0x24) = *(int *)(iVar12 + 0x24) + 1;
            }
            else if (iVar8 == 2) {
              *(int *)(iVar12 + 0x28) = *(int *)(iVar12 + 0x28) + 1;
            }
          }
          else {
            *(int *)(iVar12 + 0x20) = *(int *)(iVar12 + 0x20) + 1;
          }
        }
        uVar7 = uVar7 + 1;
        bVar2 = uVar17 != 0x1f;
        iVar3 = iVar3 + 4;
        uVar17 = uVar17 + 1;
      } while (bVar2);
      if (local_58 < *(int *)(iVar12 + 0x14)) {
        local_58 = *(int *)(iVar12 + 0x14);
      }
      uVar14 = uVar14 + 1;
      uVar15 = uVar15 - 1;
      uVar18 = uVar18 - 1;
      iVar10 = iVar10 + -4;
      puVar16 = puVar16 + -1;
      iVar11 = iVar11 + -4;
    } while (uVar14 != local_54);
  }
  iVar10 = (**(code **)(*(int *)param_1[2] + 0x5c))();
  param_1[0x44] = local_58;
  param_1[0x45] = iVar10;
  param_1[9] = (uint)(local_58 <= iVar10);
  iVar11 = *(int *)(*(int *)(*param_1 + 0x30c) + 0x54);
  if (4 < iVar11) {
    iVar10 = 4;
    param_1[10] = 8;
    iVar11 = 0;
    iVar21 = 0;
    do {
      iVar3 = *(int *)(iVar21 + (int)local_68);
      if (iVar11 < iVar3) {
        iVar11 = iVar3;
      }
      iVar21 = iVar21 + 4;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    iVar11 = (**(code **)(*(int *)param_1[2] + 0x58))((int *)param_1[2],iVar11,local_58);
    param_1[8] = iVar11;
    goto LAB_00167a18;
  }
  if (-1 < iVar21) {
    iVar3 = 0;
    puVar16 = local_68;
    do {
      iVar3 = iVar3 + 1;
      if (iVar3 <= iVar21) {
        puVar20 = local_68 + iVar3;
        iVar12 = iVar3;
        do {
          uVar18 = *puVar16;
          if ((int)uVar18 < (int)*puVar20) {
            *puVar16 = *puVar20;
            *puVar20 = uVar18;
          }
          iVar12 = iVar12 + 1;
          puVar20 = puVar20 + 1;
        } while (iVar12 <= iVar21);
      }
      puVar16 = puVar16 + 1;
    } while (iVar3 <= iVar21);
  }
  iVar11 = iVar11 - iVar21;
  if (iVar11 + -1 < 1) {
    param_1[10] = local_68[0];
  }
  else {
    uVar18 = local_68[1];
    if ((int)local_68[1] < (int)local_68[0] / iVar11) {
      uVar18 = (int)local_68[0] / iVar11;
    }
    param_1[10] = uVar18;
    if ((int)(iVar11 * uVar18) < (int)local_68[0]) {
      param_1[10] = uVar18 + 1;
    }
    if ((iVar11 + -1 == 2) && ((int)local_68[0] < (int)(local_68[1] << 1))) {
      iVar11 = ((int)local_68[0] >> 1) + (uint)((int)local_68[0] < 0 && (local_68[0] & 1) != 0);
      if ((int)local_68[2] < iVar11) {
        local_68[2] = iVar11;
      }
      if ((int)(local_68[2] << 1) < (int)local_68[0]) {
        local_68[2] = local_68[2] + 1;
      }
      if ((int)local_68[2] < param_1[10]) {
        param_1[10] = local_68[2];
      }
    }
  }
  iVar11 = (**(code **)(*(int *)param_1[2] + 0x58))((int *)param_1[2],local_68[0],local_58,iVar10);
  param_1[8] = iVar11;
  if (iVar11 == 0) {
    if ((bVar1) && (iVar11 = puVar5[2], iVar11 != 0)) {
      uVar15 = 0;
      uVar18 = 0;
      do {
        if ((*(uint *)((int)piVar13 + (uVar15 >> 3 & 0x1ffffffc) + 8) >> (uVar15 & 0x1f) & 1) != 0)
        {
          uVar18 = uVar18 + 1;
        }
        uVar15 = uVar15 + 1;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      if (6 < uVar18) goto LAB_00167a04;
    }
    iVar11 = param_1[10];
    if (iVar11 < 0x400) {
      iVar11 = 0x400;
    }
  }
  else {
LAB_00167a04:
    iVar11 = param_1[10];
    if (iVar11 < 1) {
      iVar11 = 1;
    }
  }
  param_1[10] = iVar11;
LAB_00167a18:
  if (piVar13 != (int *)0x0) {
    FUN_00193cc0(*puVar5,puVar5);
  }
  FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),iVar6);
  return;
}

/* FUN_00167a74 @ 0x167a74 (244 bytes) */
int FUN_00167a74(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  
  uVar6 = 0;
  puVar7 = *(uint **)(param_1 + 0x40);
  iVar5 = *(int *)(param_1 + 0x2c);
  uVar4 = puVar7[1];
  if (0 < (int)uVar4) {
    while( true ) {
      if (uVar6 < *puVar7) {
        uVar1 = puVar7[1];
        if (uVar1 <= uVar6) {
          _memset((void *)(uVar1 * 4 + puVar7[2]),0,(uVar6 - uVar1) * 4 + 4);
          puVar7[1] = uVar6 + 1;
        }
        piVar2 = (int *)(uVar6 * 4 + puVar7[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar7,uVar6);
      }
      uVar6 = uVar6 + 1;
      iVar3 = *piVar2;
      if (((*(int *)(iVar3 + 8) == 0) && (*(char *)(param_2 + iVar3 + 0x18) != '\0')) &&
         (iVar3 = *(int *)(*(int *)(iVar3 + 4) + 0x2c), iVar5 < iVar3)) {
        iVar5 = iVar3;
      }
      if (uVar4 == uVar6) break;
      puVar7 = *(uint **)(param_1 + 0x40);
    }
  }
  return iVar5;
}

/* FUN_00167b68 @ 0x167b68 (692 bytes) */
int FUN_00167b68(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  bool bVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  undefined4 uStack00000020;
  uint local_58 [7];
  
  uStack00000020 = param_3;
  if (param_2 != 1) {
    uVar3 = 0;
    uVar4 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x138))();
    iVar9 = param_1[0x66];
  }
  else {
    uVar3 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x138))();
    uVar4 = param_1[0x51];
    iVar9 = uVar3 + param_1[0x67];
  }
  uVar10 = 0xffffffff;
  if ((int)uVar3 < (int)uVar4) {
    iVar12 = uVar3 << 2;
    iVar8 = 4;
    uVar13 = uVar3;
    do {
      bVar1 = (*(uint *)((uVar13 >> 3 & 0x1ffffffc) + param_1[0x4c] + 8) >> (uVar13 & 0x1f) & 1) !=
              0;
      if ((bVar1) && (iVar9 < (int)uVar13)) {
        if ((int)uVar10 < 0) {
          uVar10 = uVar13;
        }
        break;
      }
      local_58[0] = 0;
      iVar6 = 0;
      iVar14 = 4;
      piVar7 = param_1;
      do {
        iVar5 = *(int *)(piVar7[0x4d] + iVar12);
        if (((iVar5 != 0) && (0 < *(int *)(iVar6 * 4 + iVar5 + 0x48))) &&
           (*(uint **)(iVar5 + 0x60) != (uint *)0x0)) {
          local_58[0] = local_58[0] | **(uint **)(iVar5 + 0x60);
        }
        iVar6 = iVar6 + 1;
        piVar7 = piVar7 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      if (bVar1) {
        iVar14 = 0;
        iVar6 = 0;
        pcVar11 = (char *)&STACKARG(0x20);
        piVar7 = param_1;
        do {
          if ((*(char *)((int)local_58 + iVar14) == '\0') &&
             ((*(int *)(piVar7[0x4d] + iVar12) == 0 ||
              (*(int *)(iVar14 * 4 + *(int *)(piVar7[0x4d] + iVar12) + 0x48) < 1)))) {
            cVar2 = *pcVar11;
            if (cVar2 == '\0') {
              iVar6 = iVar6 + 1;
            }
LAB_00167d14:
            if (((cVar2 != '\0') && (iVar5 = *(int *)(param_1[1] + 0x38), iVar5 != 0)) &&
               ((*(uint *)(iVar5 + 0x94) == uVar13 &&
                ((((iVar5 = FUN_000f313c(iVar5,iVar14), iVar5 != 0 &&
                   (iVar5 = *(int *)(piVar7[0x4d] + iVar12), iVar5 != 0)) &&
                  (*(int *)(iVar5 + 0x38) == *(int *)(param_1[1] + 0x38))) &&
                 (iVar5 = ((int (*)())FUN_00167a74)(iVar5,iVar14), iVar5 == param_1[0xb])))))) goto LAB_00167cf0;
            bVar1 = true;
          }
          else {
            cVar2 = '\0';
            if (*pcVar11 == '\0') goto LAB_00167d14;
LAB_00167cf0:
            bVar1 = false;
          }
          iVar14 = iVar14 + 1;
          if (!bVar1) goto LAB_00167db4;
          pcVar11 = pcVar11 + 1;
          piVar7 = piVar7 + 1;
        } while (iVar14 != 4);
        if (((int)uVar10 < 0) || (iVar6 < iVar8)) {
          iVar8 = iVar6;
          uVar10 = uVar13;
        }
      }
LAB_00167db4:
      uVar13 = uVar13 + 1;
      iVar12 = iVar12 + 4;
    } while (uVar13 != uVar4);
  }
  if (param_2 != 1) {
    iVar9 = param_1[0x66];
    if (param_1[0x66] < (int)(uVar10 - uVar3)) {
      iVar9 = uVar10 - uVar3;
    }
    param_1[0x66] = iVar9;
  }
  else {
    iVar9 = param_1[0x67];
    if (param_1[0x67] < (int)(uVar10 - uVar3)) {
      iVar9 = uVar10 - uVar3;
    }
    param_1[0x67] = iVar9;
  }
  return uVar10;
}

/* FUN_00167e1c @ 0x167e1c (216 bytes) */
int FUN_00167e1c(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_28 [2];
  
  iVar3 = *(int *)(*param_1 + 0x6c4);
  iVar2 = FUN_001043f0(0x31,*param_1);
  *(undefined4 *)(iVar2 + 0x98) = 0;
  *(undefined4 *)(iVar2 + 0x94) = *(undefined4 *)(iVar2 + 0x14c);
  *(undefined4 *)(iVar2 + 0x9c) = param_3;
  FUN_00106004(iVar2,1,param_2,0,*param_1);
  FUN_000f3908(local_28,param_3);
  uVar1 = *(uint *)(param_2 + 0x14);
  *(undefined4 *)(iVar2 + 0xc) = local_28[0];
  if ((uVar1 & 0x20) == 0) {
    *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xffffffdf;
  }
  else {
    *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x20;
  }
  FUN_000f35c4(iVar2);
  *(int *)(iVar3 + 0x23c) = *(int *)(iVar3 + 0x23c) + 1;
  ((int (*)())FUN_00165d3c)(param_1,iVar2,param_5,param_4);
  return;
}

/* FUN_00167ef4 @ 0x167ef4 (1396 bytes) */
int FUN_00167ef4(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  piVar8 = *(int **)(param_2 + 0x38);
  iVar1 = (**(code **)(*piVar8 + 0x14))(piVar8);
  if ((iVar1 < 3) || (*(int *)(piVar8[0x22] + 8) == 0x14)) goto LAB_00168120;
  iVar1 = FUN_00105594(piVar8,1);
  if (*(int *)(iVar1 + 0x98) != 0) {
    piVar2 = (int *)FUN_00105594(piVar8,1);
    iVar1 = (**(code **)(*piVar2 + 0x60))();
    if (iVar1 == 0) goto LAB_00168120;
    uVar3 = FUN_00105594(piVar8,1);
    iVar1 = FUN_00105594(uVar3,1);
    if (*(int *)(iVar1 + 0x98) != 0) goto LAB_00168120;
  }
  iVar1 = FUN_00105594(piVar8,2);
  if (*(int *)(iVar1 + 0x98) != 0) {
    piVar2 = (int *)FUN_00105594(piVar8,2);
    iVar1 = (**(code **)(*piVar2 + 0x60))();
    if (iVar1 == 0) goto LAB_00168120;
    uVar3 = FUN_00105594(piVar8,2);
    iVar1 = FUN_00105594(uVar3,1);
    if (*(int *)(iVar1 + 0x98) != 0) goto LAB_00168120;
  }
  iVar1 = FUN_00105594(piVar8,3);
  if (*(int *)(iVar1 + 0x98) != 0) {
    piVar2 = (int *)FUN_00105594(piVar8,3);
    iVar1 = (**(code **)(*piVar2 + 0x60))();
    if (iVar1 != 0) {
      uVar3 = FUN_00105594(piVar8,3);
      iVar1 = FUN_00105594(uVar3,1);
      if (*(int *)(iVar1 + 0x98) == 0) goto LAB_00168060;
    }
LAB_00168120:
    iVar1 = -1;
    for (iVar4 = 1; iVar5 = (**(code **)(*piVar8 + 0x14))(piVar8), iVar4 <= iVar5; iVar4 = iVar4 + 1
        ) {
      piVar2 = (int *)FUN_00105594(piVar8,iVar4);
      iVar5 = (**(code **)(*piVar2 + 0x60))();
      if (iVar5 != 0) {
        piVar2 = (int *)FUN_00105594(piVar2,1);
      }
      if (piVar2[0x26] == 1) {
        iVar5 = piVar2[0x25];
        if ((piVar2[5] & 0x40U) == 0) {
          iVar9 = *param_1;
          piVar10 = *(int **)(iVar9 + 0x30c);
          iVar6 = (**(code **)(*piVar10 + 0x138))(piVar10,iVar9);
          iVar7 = (**(code **)(*piVar10 + 0x140))(piVar10,iVar9);
          iVar9 = (**(code **)(*piVar10 + 0x13c))(piVar10,iVar9);
          iVar5 = iVar5 + iVar6 + iVar7 + iVar9;
        }
        if (iVar1 < 0) {
          iVar1 = iVar5;
        }
        if (((*(int *)(piVar2[0x22] + 8) != 0x8e) || ((piVar2[5] & 0x40U) != 0)) &&
           ((piVar2[0x56] == param_1[4] ||
            (*(int *)(param_1[1] + 0x474) == *(int *)(piVar2[0x56] + 0x118))))) {
          iVar1 = iVar5;
        }
      }
    }
    iVar4 = 1;
    do {
      iVar5 = (**(code **)(*piVar8 + 0x14))(piVar8);
      if (iVar5 < iVar4) {
        return 0;
      }
      piVar2 = (int *)FUN_00105594(piVar8,iVar4);
      iVar5 = (**(code **)(*piVar2 + 0x60))();
      if (iVar5 != 0) {
        piVar2 = (int *)FUN_00105594(piVar2,1);
      }
      if (piVar2[0x26] == 1) {
        iVar5 = piVar2[0x25];
        if ((piVar2[5] & 0x40U) == 0) {
          iVar9 = *param_1;
          piVar10 = *(int **)(iVar9 + 0x30c);
          iVar6 = (**(code **)(*piVar10 + 0x138))(piVar10,iVar9);
          iVar7 = (**(code **)(*piVar10 + 0x140))(piVar10,iVar9);
          iVar9 = (**(code **)(*piVar10 + 0x13c))(piVar10,iVar9);
          iVar5 = iVar5 + iVar6 + iVar7 + iVar9;
        }
        if (iVar5 != iVar1) {
          if (((*(int *)(piVar2[0x22] + 8) != 0x8e) || ((piVar2[5] & 0x40U) != 0)) &&
             ((piVar2[0x56] == param_1[4] ||
              (*(int *)(param_1[1] + 0x474) == *(int *)(piVar2[0x56] + 0x118))))) {
            iVar1 = FUN_001054ec(piVar8,iVar4);
            FUN_000f32cc(&local_40,*(undefined4 *)(iVar1 + 0x10));
            uVar3 = FUN_00105594(piVar8,iVar4);
            iVar1 = ((int (*)())FUN_00167e1c)(param_1,uVar3,local_40,param_1[0xb],param_2 + 0xc);
            FUN_00106004(piVar8,iVar4,*(undefined4 *)(iVar1 + 0x38),0,*param_1);
            iVar5 = FUN_001054ec(piVar8,iVar4);
            FUN_000f3398(local_3c,*(undefined4 *)(iVar5 + 0x10));
            ((int (*)())FUN_00165b7c)(param_1,iVar1,param_2,iVar4,0,local_3c[0]);
            FUN_0019401c(param_2);
            return iVar1;
          }
          piVar2[0x26] = 0;
        }
      }
      iVar4 = iVar4 + 1;
    } while( true );
  }
LAB_00168060:
  uVar3 = FUN_00105594(piVar8,1);
  iVar1 = FUN_001054ec(piVar8,1);
  FUN_000f32cc(&local_48,*(undefined4 *)(iVar1 + 0x10));
  iVar1 = ((int (*)())FUN_00167e1c)(param_1,uVar3,local_48,param_1[0xb],param_2 + 0xc);
  FUN_00106004(piVar8,1,*(undefined4 *)(iVar1 + 0x38),0,*param_1);
  iVar4 = FUN_001054ec(piVar8,1);
  FUN_000f3398(&local_44,*(undefined4 *)(iVar4 + 0x10));
  ((int (*)())FUN_00165b7c)(param_1,iVar1,param_2,1,0,local_44);
  uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x38) + 0x94);
  iVar4 = FUN_001054ec(*(int *)(iVar1 + 0x38),0);
  *(undefined4 *)(iVar4 + 8) = uVar3;
  *(undefined4 *)(iVar4 + 0xc) = 1;
  *(undefined4 *)(iVar1 + 100) = 1;
  FUN_0019401c(param_2);
  return iVar1;
}

/* FUN_00168468 @ 0x168468 (2328 bytes) */
int FUN_00168468(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int *param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  undefined4 uVar18;
  uint *puVar19;
  undefined4 local_88[0];
  undefined4 local_84;
  undefined4 local_80 [6];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_58 [4];
  
  bVar1 = 0 < param_5;
  if (bVar1) {
    piVar3 = (int *)FUN_00105594(param_3,param_5);
    iVar5 = param_5;
  }
  else {
    piVar3 = (int *)FUN_00105594(param_3,param_4);
    iVar5 = param_4;
  }
  if ((piVar3[0x56] == param_1[4]) && (iVar4 = ((int (*)())FUN_00164df4)(piVar3), iVar4 == 0)) {
    puVar19 = (uint *)param_1[6];
    uVar17 = piVar3[0x54];
    if (uVar17 < *puVar19) {
      uVar12 = puVar19[1];
      if (uVar12 <= uVar17) {
        _memset((void *)(uVar12 * 4 + puVar19[2]),0,(uVar17 - uVar12) * 4 + 4);
        puVar19[1] = uVar17 + 1;
      }
      piVar8 = (int *)(uVar17 * 4 + puVar19[2]);
    }
    else {
      piVar8 = (int *)FUN_0019423c(puVar19,uVar17);
    }
    iVar4 = *piVar8;
    iVar16 = 0;
  }
  else {
    iVar4 = ((int (*)())FUN_00165fa8)(param_1,piVar3);
    iVar16 = 1;
  }
  if (((param_3[5] & 0x200U) == 0) || (iVar5 != param_3[0x21])) {
    iVar15 = (**(code **)(*param_3 + 0x14))(param_3);
    if (iVar5 <= iVar15) {
      iVar15 = FUN_001054ec(param_3,iVar5);
      uVar7 = *(undefined4 *)(iVar15 + 0x10);
      if (bVar1) {
        iVar15 = FUN_001054ec(*(undefined4 *)(param_2 + 0x38),param_4);
        FUN_000f3398(&local_68,*(undefined4 *)(iVar15 + 0x10));
        piVar8 = (int *)FUN_00105594(*(undefined4 *)(param_2 + 0x38),param_4);
        if (param_3 != piVar8) {
          piVar8 = (int *)FUN_00105594(*(undefined4 *)(param_2 + 0x38),param_4);
          iVar15 = (**(code **)(*piVar8 + 0x60))();
          if (iVar15 != 0) {
            uVar18 = FUN_00105594(*(undefined4 *)(param_2 + 0x38),param_4);
            FUN_00105594(uVar18,1);
          }
          uVar18 = FUN_00105594(*(undefined4 *)(param_2 + 0x38),param_4);
          iVar15 = FUN_001054ec(uVar18,1);
          FUN_000f3340(&local_64,*(undefined4 *)(iVar15 + 0x10),local_68);
          FUN_000f3398(&local_60,local_64);
          local_68 = local_60;
        }
        FUN_000f3340(&local_5c,uVar7,local_68);
        uVar7 = local_5c;
      }
      FUN_000f3398(local_58,uVar7);
      bVar2 = iVar16 == 0;
      local_88[0] = local_58[0];
      iVar15 = 0;
      puVar6 = &local_88;
LAB_00168844:
      piVar8 = puVar6 + 2;
      do {
        local_84 = piVar3[3] & local_88[0];
        if ((piVar3[3] & local_88[0]) != 0) {
          uVar18 = *(undefined4 *)(*param_1 + 0x378);
          puVar9 = (undefined4 *)FUN_00193e18(uVar18,0x24);
          uVar7 = DAT_001b0194;
          puVar13 = puVar9 + 1;
          *puVar9 = uVar18;
          puVar9[1] = iVar4;
          puVar9[4] = 1;
          puVar9[7] = uVar7;
          puVar9[3] = 0;
          puVar9[5] = 0;
          puVar9[6] = 0;
          puVar9[8] = 0;
          puVar9[2] = param_2;
          uVar7 = ((int (*)())FUN_00164e7c)(param_1,piVar3,param_3,0,param_4,0);
          puVar9[4] = uVar7;
          puVar9[5] = param_4;
          puVar9[6] = param_5;
          puVar9[7] = local_84;
          if (((iVar15 == 0) && (piVar10 = (int *)FUN_00105594(param_3,iVar5), piVar3 != piVar10))
             && ((iVar11 = (**(code **)(*param_3 + 0x5c))(param_3), iVar11 == 0 || (!bVar1)))) {
            FUN_00106004(param_3,iVar5,piVar3,0,*param_1);
          }
          if ((*(uint *)(*(int *)(param_2 + 0x38) + 0x14) & 0x8000) == 0) {
            iVar11 = (**(code **)(*piVar3 + 0x54))(piVar3);
            piVar10 = piVar3;
            if ((iVar11 != 0) && (piVar3[0x21] != 0)) {
              piVar10 = (int *)FUN_00105594(piVar3,1);
            }
            uVar7 = (**(code **)(*(int *)param_1[3] + 0x20))((int *)param_1[3],piVar10);
            puVar9[8] = uVar7;
          }
          puVar19 = *(uint **)(iVar4 + 0x40);
          uVar17 = puVar19[1];
          if (uVar17 < *puVar19) {
            _memset((void *)(uVar17 * 4 + puVar19[2]),0,4);
            piVar10 = (int *)(uVar17 * 4 + puVar19[2]);
            puVar19[1] = uVar17 + 1;
          }
          else {
            piVar10 = (int *)FUN_0019423c(puVar19,uVar17);
          }
          *piVar10 = (int)puVar13;
          puVar19 = *(uint **)(param_2 + 0x44);
          uVar17 = puVar19[1];
          if (uVar17 < *puVar19) {
            _memset((void *)(uVar17 * 4 + puVar19[2]),0,4);
            piVar10 = (int *)(uVar17 * 4 + puVar19[2]);
            puVar19[1] = uVar17 + 1;
          }
          else {
            piVar10 = (int *)FUN_0019423c(puVar19,uVar17);
          }
          *piVar10 = (int)puVar13;
          iVar15 = iVar15 + 1;
          *piVar8 = (int)puVar13;
          puVar6 = puVar6 + 1;
          piVar8 = piVar8 + 1;
        }
        if (bVar2) {
          uVar17 = ((uint)*(byte *)((int)&local_88 + iVar16 + 3) << 0x18 |
                    (uint)*(byte *)((int)&local_88 + iVar16 + 2) << 0x10 |
                    (uint)*(byte *)((int)&local_88 + iVar16 + 1) << 8 |
                   (uint)*(byte *)(iVar16 + (int)&local_88)) -
                   ((uint)*(byte *)((int)local_80 + iVar16 + -1) << 0x18 |
                    (uint)*(byte *)((int)local_80 + iVar16 + -2) << 0x10 |
                    (uint)*(byte *)((int)local_80 + iVar16 + -3) << 8 |
                   (uint)*(byte *)((int)local_80 + iVar16 + -4));
          local_88[0] = uVar17 * 0x1000000 | (uVar17 & 0xff00) << 8 | uVar17 >> 8 & 0xff00 |
                     uVar17 >> 0x18;
        }
        else {
          local_88[0] = 0;
        }
        if ((local_88[0] == 0) || ((piVar3[5] & 0x200U) == 0)) {
LAB_00168ab0:
          if (iVar15 < 1) {
            return;
          }
          iVar5 = 0;
          puVar6 = local_80;
          do {
            iVar5 = iVar5 + 1;
            if (iVar5 < iVar15) {
              piVar3 = (int *)*puVar6;
              puVar9 = local_80 + iVar5;
              iVar4 = 0;
              do {
                piVar8 = (int *)*puVar9;
                if ((*(uint *)(*(int *)(*piVar3 + 0x38) + 0xc) &
                    *(uint *)(*(int *)(*piVar8 + 0x38) + 0xc)) != 0) {
                  uVar7 = *(undefined4 *)(*param_1 + 0x378);
                  puVar13 = (undefined4 *)FUN_00193e18(uVar7,0x24);
                  *puVar13 = uVar7;
                  puVar13[1] = 0;
                  uVar7 = DAT_001b0194;
                  iVar11 = *piVar8;
                  puVar13[1] = iVar11;
                  iVar16 = *piVar3;
                  puVar13[4] = 1;
                  puVar13[7] = uVar7;
                  puVar13[3] = 3;
                  puVar13[2] = iVar16;
                  puVar13[5] = 0;
                  puVar13[6] = 0;
                  puVar13[8] = 0;
                  uVar7 = ((int (*)())FUN_00164e7c)(param_1,*(undefined4 *)(iVar11 + 0x38),
                                       *(undefined4 *)(iVar16 + 0x38),0,0,3);
                  iVar11 = *piVar8;
                  iVar16 = *piVar3;
                  puVar13[4] = uVar7;
                  puVar13[7] = *(uint *)(*(int *)(iVar16 + 0x38) + 0xc) &
                               *(uint *)(*(int *)(iVar11 + 0x38) + 0xc);
                  puVar19 = *(uint **)(puVar13[1] + 0x40);
                  uVar17 = puVar19[1];
                  if (uVar17 < *puVar19) {
                    _memset((void *)(uVar17 * 4 + puVar19[2]),0,4);
                    puVar14 = (undefined4 *)(uVar17 * 4 + puVar19[2]);
                    puVar19[1] = uVar17 + 1;
                  }
                  else {
                    puVar14 = (undefined4 *)FUN_0019423c(puVar19,uVar17);
                  }
                  *puVar14 = puVar13 + 1;
                  puVar19 = *(uint **)(puVar13[2] + 0x44);
                  uVar17 = puVar19[1];
                  if (uVar17 < *puVar19) {
                    _memset((void *)(uVar17 * 4 + puVar19[2]),0,4);
                    puVar14 = (undefined4 *)(uVar17 * 4 + puVar19[2]);
                    puVar19[1] = uVar17 + 1;
                  }
                  else {
                    puVar14 = (undefined4 *)FUN_0019423c(puVar19,uVar17);
                  }
                  *puVar14 = puVar13 + 1;
                }
                iVar4 = iVar4 + 1;
                puVar9 = puVar9 + 1;
              } while (iVar15 - iVar5 != iVar4);
            }
            puVar6 = puVar6 + 1;
          } while (iVar5 != iVar15);
          return;
        }
        piVar10 = (int *)FUN_00105594(piVar3,piVar3[0x21]);
        iVar4 = (**(code **)(*piVar10 + 0x50))();
        if (iVar4 != 0) goto LAB_00168ab0;
        piVar3 = (int *)FUN_00105594(piVar3,piVar3[0x21]);
        if ((piVar3[0x56] == param_1[4]) && (iVar4 = ((int (*)())FUN_00164df4)(), iVar4 == 0)) goto LAB_00168b48;
        iVar16 = 1;
        bVar2 = false;
        iVar4 = ((int (*)())FUN_00165fa8)(param_1,piVar3);
      } while( true );
    }
    uVar18 = *(undefined4 *)(*param_1 + 0x378);
    puVar6 = (undefined4 *)FUN_00193e18(uVar18,0x24);
    uVar7 = DAT_001b0194;
    *puVar6 = uVar18;
    puVar6[4] = 1;
    puVar6[1] = iVar4;
    puVar6[7] = uVar7;
    puVar6[3] = 0;
    puVar6[5] = 0;
    puVar6[6] = 0;
    puVar6[8] = 0;
    puVar6[2] = param_2;
    uVar7 = ((int (*)())FUN_00164e7c)(param_1,piVar3,param_3,0,param_4,0);
    puVar6[5] = param_4;
    puVar6[4] = uVar7;
    puVar6[6] = param_5;
    puVar6[7] = piVar3[3];
  }
  else {
    FUN_00105594(param_3,iVar5);
    iVar5 = FUN_000e07dc(*param_1,0x26);
    if (((iVar5 != 0) && (iVar5 = FUN_000e07dc(*param_1,0x25), iVar5 != 0)) &&
       ((param_3[5] & 0x20U) == 0)) {
      return;
    }
    uVar18 = *(undefined4 *)(*param_1 + 0x378);
    puVar6 = (undefined4 *)FUN_00193e18(uVar18,0x24);
    uVar7 = DAT_001b0194;
    *puVar6 = uVar18;
    puVar6[4] = 1;
    puVar6[1] = iVar4;
    puVar6[3] = 3;
    puVar6[7] = uVar7;
    puVar6[8] = 0;
    puVar6[5] = 0;
    puVar6[6] = 0;
    puVar6[2] = param_2;
    uVar7 = ((int (*)())FUN_00164e7c)(param_1,piVar3,param_3,0,0,3);
    puVar6[4] = uVar7;
    puVar6[7] = param_3[3];
  }
  puVar19 = *(uint **)(iVar4 + 0x40);
  uVar17 = puVar19[1];
  if (uVar17 < *puVar19) {
    _memset((void *)(uVar17 * 4 + puVar19[2]),0,4);
    piVar3 = (int *)(uVar17 * 4 + puVar19[2]);
    puVar19[1] = uVar17 + 1;
  }
  else {
    piVar3 = (int *)FUN_0019423c(puVar19,uVar17);
  }
  *piVar3 = (int)(puVar6 + 1);
  puVar19 = *(uint **)(param_2 + 0x44);
  uVar17 = puVar19[1];
  if (uVar17 < *puVar19) {
    _memset((void *)(uVar17 * 4 + puVar19[2]),0,4);
    piVar3 = (int *)(uVar17 * 4 + puVar19[2]);
    puVar19[1] = uVar17 + 1;
  }
  else {
    piVar3 = (int *)FUN_0019423c(puVar19,uVar17);
  }
  *piVar3 = (int)(puVar6 + 1);
  return;
LAB_00168b48:
  puVar19 = (uint *)param_1[6];
  uVar17 = piVar3[0x54];
  if (uVar17 < *puVar19) {
    uVar12 = puVar19[1];
    if (uVar12 <= uVar17) {
      _memset((void *)(uVar12 * 4 + puVar19[2]),0,(uVar17 - uVar12) * 4 + 4);
      puVar19[1] = uVar17 + 1;
    }
    piVar8 = (int *)(uVar17 * 4 + puVar19[2]);
  }
  else {
    piVar8 = (int *)FUN_0019423c(puVar19,uVar17);
  }
  iVar4 = *piVar8;
  goto LAB_00168844;
}

/* FUN_00168d80 @ 0x168d80 (3548 bytes) */
int FUN_00168d80(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined1 uVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int *piVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  undefined4 uVar22;
  int iVar23;
  uint *puVar24;
  int *piVar25;
  undefined4 *puVar26;
  int local_88[0];
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  undefined4 local_64;
  undefined4 local_60;
  
  piVar25 = *(int **)(param_2 + 0x38);
  iVar6 = (**(code **)(*(int *)param_1[2] + 0x40))((int *)param_1[2],piVar25,&local_88,&local_84);
  if (iVar6 == 0) {
    return 0;
  }
  param_1[0x6a] = param_1[0x6a] + 1;
  iVar7 = ((int (*)())FUN_00165d3c)(param_1,iVar6,param_2 + 0xc,*(undefined4 *)(param_2 + 0x30));
  local_60 = FUN_00105594(piVar25,1);
  local_64 = FUN_00105594(piVar25,2);
  iVar8 = FUN_001054ec(piVar25,1);
  local_80 = *(uint *)(iVar8 + 0x10);
  iVar8 = FUN_001054ec(piVar25,2);
  local_7c = *(uint *)(iVar8 + 0x10);
  iVar8 = FUN_001054ec(piVar25,0);
  uVar4 = piVar25[5];
  local_68 = piVar25[0x2e] & 1;
  local_70 = (uint)piVar25[0x2e] >> 1 & 1;
  local_6c = piVar25[0x34] & 1;
  local_74 = (uint)piVar25[0x34] >> 1 & 1;
  iVar18 = *(int *)(iVar8 + 0x10);
  uVar17 = uVar4 >> 1 & 1;
  uVar14 = uVar4 >> 5 & 1;
  iVar15 = piVar25[0x26];
  iVar16 = piVar25[0x25];
  iVar12 = piVar25[0x48];
  iVar13 = piVar25[0x49];
  iVar8 = piVar25[3];
  local_78 = 0;
  if ((uVar4 & 0x200) != 0) {
    local_78 = FUN_00105594(piVar25,piVar25[0x21]);
  }
  iVar5 = *(int *)(*(int *)(iVar6 + 0x88) + 8);
  piVar19 = piVar25;
  if (iVar5 == 0x13) {
    ((int (*)())FUN_0017212c)(param_1[2],param_2);
    if (*(int *)(piVar25[0x22] + 8) == 0x1c) {
      FUN_00108304(piVar25,0x1e,*param_1);
      FUN_00106004(piVar25,3,iVar6,0,*param_1);
      uVar9 = DAT_001b01a0;
      iVar5 = FUN_001054ec(piVar25,3);
      *(undefined4 *)(iVar5 + 0x10) = uVar9;
      (**(code **)(*piVar25 + 0x88))(piVar25,3,2,local_84);
      uVar4 = local_80;
      iVar5 = FUN_001054ec(piVar25,1);
      uVar3 = local_7c;
      *(uint *)(iVar5 + 0x10) = uVar4;
      iVar5 = FUN_001054ec(piVar25,2);
      *(uint *)(iVar5 + 0x10) = uVar3;
      if (local_88[0] < 2) {
        puVar20 = (undefined1 *)((int)&local_80 + local_88[0] + 1);
        puVar21 = (undefined1 *)((int)&local_7c + local_88[0] + 1);
        iVar5 = local_88[0];
        do {
          iVar23 = iVar5 + 1;
          uVar1 = *puVar20;
          puVar20 = puVar20 + 1;
          (**(code **)(*piVar25 + 0x88))(piVar25,1,iVar5,uVar1);
          uVar1 = *puVar21;
          puVar21 = puVar21 + 1;
          (**(code **)(*piVar25 + 0x88))(piVar25,2,iVar5,uVar1);
          iVar5 = iVar23;
        } while (iVar23 != 2);
      }
      (**(code **)(*piVar25 + 0x88))(piVar25,1,2,4);
      (**(code **)(*piVar25 + 0x88))(piVar25,2,2,4);
    }
    else {
      piVar19 = (int *)0x0;
      if (*(int *)(piVar25[0x22] + 8) == 0x1d) {
        FUN_00108304(piVar25,0xa3,*param_1);
        FUN_00106004(piVar25,3,iVar6,0,*param_1);
        uVar9 = DAT_001b01a0;
        iVar5 = FUN_001054ec(piVar25,3);
        *(undefined4 *)(iVar5 + 0x10) = uVar9;
        (**(code **)(*piVar25 + 0x88))(piVar25,3,3,local_84);
        uVar4 = local_80;
        iVar5 = FUN_001054ec(piVar25,1);
        uVar3 = local_7c;
        *(uint *)(iVar5 + 0x10) = uVar4;
        iVar5 = FUN_001054ec(piVar25,2);
        *(uint *)(iVar5 + 0x10) = uVar3;
        if (local_88[0] < 3) {
          puVar20 = (undefined1 *)((int)&local_80 + local_88[0] + 1);
          puVar21 = (undefined1 *)((int)&local_7c + local_88[0] + 1);
          iVar5 = local_88[0];
          do {
            iVar23 = iVar5 + 1;
            uVar1 = *puVar20;
            puVar20 = puVar20 + 1;
            (**(code **)(*piVar25 + 0x88))(piVar25,1,iVar5,uVar1);
            uVar1 = *puVar21;
            puVar21 = puVar21 + 1;
            (**(code **)(*piVar25 + 0x88))(piVar25,2,iVar5,uVar1);
            iVar5 = iVar23;
          } while (iVar23 != 3);
        }
        (**(code **)(*piVar25 + 0x88))(piVar25,1,3,4);
        (**(code **)(*piVar25 + 0x88))(piVar25,2,3,4);
        piVar19 = piVar25;
      }
    }
    if (uVar17 == 0) {
      piVar19[0x25] = iVar16;
      piVar19[0x26] = iVar15;
      if (uVar14 == 0) {
        piVar19[5] = piVar19[5] & 0xffffffdf;
      }
      else {
        piVar19[5] = piVar19[5] | 0x20;
      }
    }
    else {
      FUN_0010469c(piVar19,param_1[1],iVar15,iVar16);
    }
    piVar19[0x27] = iVar18;
    piVar19[0x48] = iVar12;
    piVar19[0x49] = iVar13;
    piVar19[3] = iVar8;
    FUN_00106004(piVar19,1,local_60,0,*param_1);
    FUN_00103d50(piVar19 + 0x29,2,local_70);
    FUN_00103d50(piVar19 + 0x29,1,local_68);
    FUN_00106004(piVar19,2,local_64,0,*param_1);
    FUN_00103d50(piVar19 + 0x2f,2,local_74);
    FUN_00103d50(piVar19 + 0x2f,1,local_6c);
  }
  else {
    if (iVar5 != 0x14) {
      if (iVar5 != 0x1c) {
        return iVar7;
      }
      ((int (*)())FUN_0017212c)(param_1[2],param_2);
      FUN_00108304(piVar25,0x14,*param_1);
      if (uVar17 == 0) {
        piVar25[0x25] = iVar16;
        piVar25[0x26] = iVar15;
        if (uVar14 == 0) {
          piVar25[5] = piVar25[5] & 0xffffffdf;
        }
        else {
          piVar25[5] = piVar25[5] | 0x20;
        }
      }
      else {
        FUN_0010469c(piVar25,param_1[1],iVar15,iVar16);
      }
      piVar25[0x48] = iVar12;
      piVar25[0x49] = iVar13;
      piVar25[3] = iVar8;
      FUN_00106004(piVar25,1,local_60,0,*param_1);
      FUN_00103d50(piVar25 + 0x29,2,local_70);
      FUN_00103d50(piVar25 + 0x29,1,local_68);
      FUN_00106004(piVar25,2,local_64,0,*param_1);
      FUN_00103d50(piVar25 + 0x2f,2,local_74);
      FUN_00103d50(piVar25 + 0x2f,1,local_6c);
      FUN_00106004(piVar25,3,iVar6,0,*param_1);
      piVar25[0x27] = iVar18;
      puVar2 = PTR_DAT_001e8b8c;
      uVar9 = *(undefined4 *)(PTR_DAT_001e8b8c + (local_80 & 0xff) * 4);
      iVar8 = FUN_001054ec(piVar25,1);
      *(undefined4 *)(iVar8 + 0x10) = uVar9;
      uVar9 = *(undefined4 *)(puVar2 + (local_7c & 0xff) * 4);
      iVar8 = FUN_001054ec(piVar25,2);
      *(undefined4 *)(iVar8 + 0x10) = uVar9;
      uVar9 = DAT_001b019c;
      iVar8 = FUN_001054ec(piVar25,3);
      *(undefined4 *)(iVar8 + 0x10) = uVar9;
      FUN_000f35c4(piVar25);
      if (local_78 != 0) {
        FUN_00106804(piVar25,local_78,0,*param_1);
      }
      uVar9 = (**(code **)(*(int *)param_1[2] + 0x4c))((int *)param_1[2],piVar25);
      *(undefined4 *)(param_2 + 0x58) = uVar9;
      iVar8 = FUN_000e07dc(*param_1,0x28);
      if (iVar8 != 0) {
        iVar8 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],param_2);
        uVar9 = 1;
        if (iVar8 != 0) goto LAB_001699c4;
      }
      uVar9 = 0;
LAB_001699c4:
      *(undefined4 *)(param_2 + 0x5c) = uVar9;
      (**(code **)(*(int *)param_1[2] + 0x48))((int *)param_1[2],param_2);
      ((int (*)())FUN_00172078)(param_1[2],param_2);
      uVar22 = *(undefined4 *)(*param_1 + 0x378);
      puVar10 = (undefined4 *)FUN_00193e18(uVar22,0x24);
      uVar9 = DAT_001b0194;
      *puVar10 = uVar22;
      puVar10[1] = iVar7;
      puVar10[7] = uVar9;
      puVar10[3] = 0;
      puVar10[4] = 1;
      puVar10[5] = 0;
      puVar10[6] = 0;
      puVar10[8] = 0;
      puVar10[2] = param_2;
      uVar9 = ((int (*)())FUN_00164e7c)(param_1,iVar6,piVar25,0,3,0);
      puVar10[4] = uVar9;
      puVar10[5] = 3;
      puVar10[7] = 0;
      *(undefined1 *)(puVar10 + 7) = 1;
      puVar24 = *(uint **)(iVar7 + 0x40);
      uVar4 = puVar24[1];
      if (uVar4 < *puVar24) {
        _memset((void *)(uVar4 * 4 + puVar24[2]),0,4);
        piVar25 = (int *)(uVar4 * 4 + puVar24[2]);
        puVar24[1] = uVar4 + 1;
      }
      else {
        piVar25 = (int *)FUN_0019423c(puVar24,uVar4);
      }
      *piVar25 = (int)(puVar10 + 1);
      puVar24 = *(uint **)(param_2 + 0x44);
      uVar4 = puVar24[1];
      if (uVar4 < *puVar24) {
        _memset((void *)(uVar4 * 4 + puVar24[2]),0,4);
        piVar25 = (int *)(uVar4 * 4 + puVar24[2]);
        puVar24[1] = uVar4 + 1;
      }
      else {
        piVar25 = (int *)FUN_0019423c(puVar24,uVar4);
      }
      *piVar25 = (int)(puVar10 + 1);
      ((int (*)())FUN_00166844)(param_1,param_2,iVar7);
      iVar8 = *(int *)(param_2 + 0x34);
      iVar6 = *(int *)(param_2 + 0x30);
      *(undefined4 *)(iVar7 + 0x48) = 1;
      *(int *)(param_2 + 0x34) = iVar8 + 1;
      if (iVar6 < param_1[0xb] + puVar10[4]) {
        iVar6 = param_1[0xb] + puVar10[4];
      }
      *(int *)(param_2 + 0x30) = iVar6;
      return iVar7;
    }
    ((int (*)())FUN_0017212c)(param_1[2],param_2);
    if (*(int *)(piVar25[0x22] + 8) == 0x1e) {
      FUN_00108304(piVar25,0x14,*param_1);
      piVar25[0x27] = iVar18;
      puVar2 = PTR_DAT_001e8b8c;
      uVar9 = *(undefined4 *)
               (PTR_DAT_001e8b8c + (uint)*(byte *)((int)&local_80 + (1 - local_88[0])) * 4);
      iVar18 = FUN_001054ec(piVar25,1);
      *(undefined4 *)(iVar18 + 0x10) = uVar9;
      uVar9 = *(undefined4 *)(puVar2 + (uint)*(byte *)((int)&local_7c + (1 - local_88[0])) * 4);
      iVar18 = FUN_001054ec(piVar25,2);
      *(undefined4 *)(iVar18 + 0x10) = uVar9;
      uVar9 = *(undefined4 *)(puVar2 + local_84 * 4);
      iVar18 = FUN_001054ec(piVar25,3);
      *(undefined4 *)(iVar18 + 0x10) = uVar9;
      FUN_000f35c4(piVar25);
    }
    else {
      piVar19 = (int *)0x0;
      if (*(int *)(piVar25[0x22] + 8) == 0xa3) {
        FUN_00108304(piVar25,0x1e,*param_1);
        uVar4 = local_80;
        piVar25[0x27] = iVar18;
        iVar18 = FUN_001054ec(piVar25,1);
        uVar3 = local_7c;
        *(uint *)(iVar18 + 0x10) = uVar4;
        iVar18 = FUN_001054ec(piVar25,2);
        *(uint *)(iVar18 + 0x10) = uVar3;
        if (local_88[0] < 2) {
          puVar20 = (undefined1 *)((int)&local_80 + local_88[0] + 1);
          puVar21 = (undefined1 *)((int)&local_7c + local_88[0] + 1);
          iVar18 = local_88[0];
          do {
            iVar5 = iVar18 + 1;
            uVar1 = *puVar20;
            puVar20 = puVar20 + 1;
            (**(code **)(*piVar25 + 0x88))(piVar25,1,iVar18,uVar1);
            uVar1 = *puVar21;
            puVar21 = puVar21 + 1;
            (**(code **)(*piVar25 + 0x88))(piVar25,2,iVar18,uVar1);
            iVar18 = iVar5;
          } while (iVar5 != 2);
        }
        (**(code **)(*piVar25 + 0x88))(piVar25,1,2,4);
        (**(code **)(*piVar25 + 0x88))(piVar25,2,2,4);
        uVar9 = DAT_001b01a0;
        iVar18 = FUN_001054ec(piVar25,3);
        *(undefined4 *)(iVar18 + 0x10) = uVar9;
        (**(code **)(*piVar25 + 0x88))(piVar25,3,2,local_84);
        piVar19 = piVar25;
      }
    }
    if (uVar17 == 0) {
      piVar19[0x25] = iVar16;
      piVar19[0x26] = iVar15;
      if (uVar14 == 0) {
        piVar19[5] = piVar19[5] & 0xffffffdf;
      }
      else {
        piVar19[5] = piVar19[5] | 0x20;
      }
    }
    else {
      FUN_0010469c(piVar19,param_1[1],iVar15,iVar16);
    }
    piVar19[0x48] = iVar12;
    piVar19[0x49] = iVar13;
    piVar19[3] = iVar8;
    FUN_00106004(piVar19,1,local_60,0,*param_1);
    FUN_00103d50(piVar19 + 0x29,2,local_70);
    FUN_00103d50(piVar19 + 0x29,1,local_68);
    FUN_00106004(piVar19,2,local_64,0,*param_1);
    FUN_00103d50(piVar19 + 0x2f,2,local_74);
    FUN_00103d50(piVar19 + 0x2f,1,local_6c);
    FUN_00106004(piVar19,3,iVar6,0,*param_1);
  }
  if (local_78 != 0) {
    FUN_00106804(piVar19,local_78,0,*param_1);
  }
  uVar9 = (**(code **)(*(int *)param_1[2] + 0x4c))((int *)param_1[2],piVar19);
  *(undefined4 *)(param_2 + 0x58) = uVar9;
  iVar8 = FUN_000e07dc(*param_1,0x28);
  if (iVar8 != 0) {
    iVar8 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],param_2);
    uVar9 = 1;
    if (iVar8 != 0) goto LAB_00169620;
  }
  uVar9 = 0;
LAB_00169620:
  *(undefined4 *)(param_2 + 0x5c) = uVar9;
  (**(code **)(*(int *)param_1[2] + 0x48))((int *)param_1[2],param_2);
  ((int (*)())FUN_00172078)(param_1[2],param_2);
  uVar22 = *(undefined4 *)(*param_1 + 0x378);
  puVar10 = (undefined4 *)FUN_00193e18(uVar22,0x24);
  uVar9 = DAT_001b0194;
  puVar26 = puVar10 + 1;
  *puVar10 = uVar22;
  puVar10[1] = iVar7;
  puVar10[7] = uVar9;
  puVar10[3] = 0;
  puVar10[4] = 1;
  puVar10[5] = 0;
  puVar10[6] = 0;
  puVar10[8] = 0;
  puVar10[2] = param_2;
  uVar9 = ((int (*)())FUN_00164e7c)(param_1,iVar6,piVar19,0,3,0);
  puVar10[4] = uVar9;
  puVar10[5] = 3;
  puVar10[7] = 0;
  *(undefined1 *)((int)puVar26 + local_84 + 0x18) = 1;
  puVar24 = *(uint **)(iVar7 + 0x40);
  uVar4 = puVar24[1];
  if (uVar4 < *puVar24) {
    _memset((void *)(uVar4 * 4 + puVar24[2]),0,4);
    puVar11 = (undefined4 *)(uVar4 * 4 + puVar24[2]);
    puVar24[1] = uVar4 + 1;
  }
  else {
    puVar11 = (undefined4 *)FUN_0019423c(puVar24,uVar4);
  }
  *puVar11 = puVar26;
  puVar24 = *(uint **)(param_2 + 0x44);
  uVar4 = puVar24[1];
  if (uVar4 < *puVar24) {
    _memset((void *)(uVar4 * 4 + puVar24[2]),0,4);
    puVar11 = (undefined4 *)(uVar4 * 4 + puVar24[2]);
    puVar24[1] = uVar4 + 1;
  }
  else {
    puVar11 = (undefined4 *)FUN_0019423c(puVar24,uVar4);
  }
  *puVar11 = puVar26;
  ((int (*)())FUN_00166844)(param_1,param_2,iVar7);
  *(int *)(param_2 + 0x34) = *(int *)(param_2 + 0x34) + 1;
  *(undefined4 *)(local_84 * 4 + iVar7 + 0x48) = 1;
  iVar6 = *(int *)(param_2 + 0x30);
  if (*(int *)(param_2 + 0x30) < param_1[0xb] + puVar10[4]) {
    iVar6 = param_1[0xb] + puVar10[4];
  }
  *(int *)(param_2 + 0x30) = iVar6;
  return iVar7;
}

/* FUN_00169b70 @ 0x169b70 (700 bytes) */
int FUN_00169b70(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  undefined1 auStack_48 [8];
  int local_40;
  
  uVar8 = 0;
  FUN_001940a8(auStack_48);
  puVar10 = *(uint **)(param_1 + 0x18);
  uVar7 = puVar10[1];
  if (0 < (int)uVar7) {
    do {
      if (uVar8 < *puVar10) {
        uVar2 = puVar10[1];
        if (uVar2 <= uVar8) {
          _memset((void *)(uVar2 * 4 + puVar10[2]),0,(uVar8 - uVar2) * 4 + 4);
          puVar10[1] = uVar8 + 1;
        }
        piVar3 = (int *)(uVar8 * 4 + puVar10[2]);
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar10,uVar8);
      }
      iVar6 = *piVar3;
      uVar2 = 0;
      puVar10 = *(uint **)(iVar6 + 0x44);
      uVar9 = puVar10[1];
      if (0 < (int)uVar9) {
        while( true ) {
          if (uVar2 < *puVar10) {
            uVar4 = puVar10[1];
            if (uVar4 <= uVar2) {
              _memset((void *)(uVar4 * 4 + puVar10[2]),0,(uVar2 - uVar4) * 4 + 4);
              puVar10[1] = uVar2 + 1;
            }
            piVar3 = (int *)(uVar2 * 4 + puVar10[2]);
          }
          else {
            piVar3 = (int *)FUN_0019423c(puVar10,uVar2);
          }
          uVar2 = uVar2 + 1;
          iVar1 = *(int *)(*(int *)*piVar3 + 0x18) + ((int *)*piVar3)[3];
          iVar11 = *(int *)(iVar6 + 0x18);
          if (*(int *)(iVar6 + 0x18) < iVar1) {
            iVar11 = iVar1;
          }
          *(int *)(iVar6 + 0x18) = iVar11;
          if (uVar9 == uVar2) break;
          puVar10 = *(uint **)(iVar6 + 0x44);
        }
      }
      iVar11 = local_40;
      if ((*(uint *)(*(int *)(iVar6 + 0x38) + 0x14) & 2) != 0) {
        do {
          iVar1 = iVar11;
          iVar11 = 0;
          if (*(int *)(iVar1 + 8) == 0) goto LAB_00169d08;
          iVar11 = *(int *)(iVar1 + 8);
        } while (*(int *)(iVar6 + 0x18) <= *(int *)(iVar1 + 0x18));
        FUN_00193f44(iVar6,iVar1);
        iVar11 = *(int *)(iVar1 + 8);
LAB_00169d08:
        if (iVar11 == 0) {
          FUN_00193f64(auStack_48,iVar6);
        }
      }
      uVar8 = uVar8 + 1;
      if (uVar7 == uVar8) break;
      puVar10 = *(uint **)(param_1 + 0x18);
    } while( true );
  }
  *(undefined4 *)(param_1 + 0xf4) = 0;
  while (iVar6 = FUN_00193f08(auStack_48), iVar6 == 0) {
    (**(code **)(**(int **)(param_1 + 8) + 8))();
    iVar6 = local_40;
    (**(code **)(**(int **)(param_1 + 8) + 0x10))
              (*(int **)(param_1 + 8),*(undefined4 *)(local_40 + 0x38));
    iVar11 = *(int *)(iVar6 + 8);
    FUN_0019401c(iVar6);
    while (iVar1 = iVar11, iVar11 = *(int *)(iVar1 + 8), iVar11 != 0) {
      iVar5 = (**(code **)(**(int **)(param_1 + 8) + 0xc))
                        (*(int **)(param_1 + 8),*(undefined4 *)(iVar1 + 0x38));
      if (iVar5 != 0) {
        (**(code **)(**(int **)(param_1 + 8) + 0x10))
                  (*(int **)(param_1 + 8),*(undefined4 *)(iVar1 + 0x38));
        *(undefined4 *)(iVar1 + 0x68) = 1;
        *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + 1;
        *(undefined4 *)(iVar6 + 0x68) = 1;
        FUN_0019401c(iVar1);
      }
    }
    if (*(int *)(iVar6 + 0x68) != 0) {
      *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + 1;
    }
  }
  return;
}

/* FUN_00169e30 @ 0x169e30 (1848 bytes) */
int FUN_00169e30(param_1)
  int *param_1;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  undefined4 uVar13;
  int iVar14;
  int local_38 [3];
  
  iVar2 = *(int *)(*param_1 + 0x324) << 2;
  iVar7 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),iVar2);
  iVar8 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),iVar2);
  iVar2 = param_1[1];
  piVar11 = (int *)(*(int **)(iVar2 + 900))[2];
  piVar12 = *(int **)(iVar2 + 900);
  if (piVar11 != (int *)0x0) {
    do {
      piVar4 = piVar11;
      piVar11 = (int *)((int *)piVar12[0x26])[2];
      piVar5 = (int *)piVar12[0x26];
      if (piVar11 != (int *)0x0) {
        do {
          piVar4 = piVar11;
          if ((piVar5[5] & 1U) != 0) {
            *(int *)(iVar7 + piVar5[0x53] * 4) = piVar5[0x53];
            *(undefined4 *)(piVar5[0x53] * 4 + iVar8) = 0;
            iVar2 = FUN_001054ec(piVar5,0);
            FUN_000f3908(local_38,*(undefined4 *)(iVar2 + 0x10));
            piVar5[3] = local_38[0];
            FUN_00106004(piVar5,0,0,0,*param_1);
            iVar2 = (**(code **)(*piVar12 + 0x14))(piVar12);
            if (iVar2 != 0) {
              piVar5[5] = piVar5[5] | 0x20;
            }
            iVar2 = (**(code **)(*piVar5 + 0x7c))(piVar5);
            if (iVar2 == 0) {
              if ((*(int *)(piVar5[0x22] + 8) == 0x32) &&
                 (iVar2 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0xd0))(), iVar2 == 0)) {
                piVar4 = (int *)piVar5[2];
                piVar5[5] = piVar5[5] | 0x20;
                goto LAB_0016a118;
              }
              if (0 < piVar5[0x21]) {
                iVar2 = 1;
                do {
                  piVar11 = (int *)FUN_00105594(piVar5,iVar2);
                  iVar3 = (**(code **)(*piVar11 + 0x5c))();
                  if ((iVar3 == 0) && (iVar3 = (**(code **)(*piVar11 + 0x60))(piVar11), iVar3 == 0))
                  {
                    if (piVar11[0x56] != piVar5[0x56]) {
                      piVar11[5] = piVar11[5] | 0x20;
                    }
                  }
                  else if (0 < piVar11[0x21]) {
                    iVar3 = 1;
                    do {
                      piVar4 = (int *)FUN_00105594(piVar11,iVar3);
                      iVar9 = (**(code **)(*piVar4 + 0x5c))();
                      if (iVar9 == 0) {
                        if (piVar4[0x56] != piVar5[0x56]) {
                          piVar4[5] = piVar4[5] | 0x20;
                        }
                      }
                      else if (0 < piVar4[0x21]) {
                        iVar9 = 1;
                        do {
                          iVar10 = FUN_00105594(piVar4,iVar9);
                          if (*(int *)(iVar10 + 0x158) != piVar5[0x56]) {
                            *(uint *)(iVar10 + 0x14) = *(uint *)(iVar10 + 0x14) | 0x20;
                          }
                          iVar9 = iVar9 + 1;
                        } while (iVar9 <= piVar4[0x21]);
                      }
                      iVar3 = iVar3 + 1;
                    } while (iVar3 <= piVar11[0x21]);
                  }
                  iVar2 = iVar2 + 1;
                } while (iVar2 <= piVar5[0x21]);
              }
            }
            else {
              piVar5[5] = piVar5[5] | 0x20;
              if (0 < piVar5[0x21]) {
                iVar2 = 1;
                do {
                  iVar9 = FUN_00105594(piVar5,iVar2);
                  iVar3 = piVar5[0x21];
                  iVar2 = iVar2 + 1;
                  *(uint *)(iVar9 + 0x14) = *(uint *)(iVar9 + 0x14) | 0x20;
                } while (iVar2 <= iVar3);
              }
            }
            piVar4 = (int *)piVar5[2];
          }
LAB_0016a118:
          piVar11 = (int *)piVar4[2];
          piVar5 = piVar4;
        } while ((int *)piVar4[2] != (int *)0x0);
        piVar4 = (int *)piVar12[2];
      }
      piVar11 = (int *)piVar4[2];
      piVar12 = piVar4;
    } while ((int *)piVar4[2] != (int *)0x0);
    iVar2 = param_1[1];
  }
  iVar3 = *(int *)(*(int *)(iVar2 + 900) + 8);
  iVar9 = *(int *)(iVar2 + 900);
  if (iVar3 != 0) {
    do {
      iVar2 = iVar3;
      piVar11 = (int *)(*(int **)(iVar9 + 0x98))[2];
      piVar12 = *(int **)(iVar9 + 0x98);
      if (piVar11 != (int *)0x0) {
        do {
          piVar5 = piVar11;
          if ((piVar12[5] & 1U) != 0) {
            if ((piVar12[5] & 0x200U) == 0) {
              iVar2 = (**(code **)(*piVar12 + 100))(piVar12);
              if (iVar2 == 0) {
LAB_0016a1fc:
                uVar1 = piVar12[5];
LAB_0016a200:
                if ((uVar1 & 0x20) != 0) {
                  iVar2 = FUN_001952d8(piVar12[0x53],iVar7);
                  *(undefined4 *)(iVar2 * 4 + iVar8) = 1;
                }
                piVar5 = (int *)piVar12[2];
                goto LAB_0016a42c;
              }
              for (iVar2 = 1; iVar3 = (**(code **)(*piVar12 + 0x14))(piVar12), iVar2 <= iVar3;
                  iVar2 = iVar2 + 1) {
                if ((((piVar12[iVar2 * 6 + 0x28] & 1U) != 0) ||
                    ((piVar12[iVar2 * 6 + 0x28] & 2U) != 0)) ||
                   (iVar3 = FUN_000f31e8(piVar12,iVar2), iVar3 == 0)) goto LAB_0016a1fc;
              }
              if ((piVar12[0x48] != 0) || (piVar12[0x49] != 0)) goto LAB_0016a1fc;
              if (((piVar12[0x20] != 0) &&
                  ((iVar2 = FUN_00126760(piVar12[0x26]), iVar2 != 0 && ((piVar12[5] & 2U) == 0))))
                 && (iVar2 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar2 == 0)) {
                iVar2 = 4;
                piVar11 = piVar12;
                do {
                  if (*(byte *)(piVar11 + 0x27) - 2 < 2) goto LAB_0016a1fc;
                  piVar11 = (int *)((int)piVar11 + 1);
                  iVar2 = iVar2 + -1;
                } while (iVar2 != 0);
              }
              FUN_001054ec(piVar12,0);
              iVar2 = FUN_00105dbc(piVar12,0);
              if (iVar2 != 0) goto LAB_0016a1fc;
              uVar1 = piVar12[5];
              if (((uVar1 & 2) != 0) || ((uVar1 & 0x200) != 0)) goto LAB_0016a200;
              iVar3 = piVar12[0x53];
              iVar2 = FUN_00105594(piVar12,1);
              uVar13 = *(undefined4 *)(iVar2 + 0x14c);
              iVar3 = FUN_001952d8(iVar3,iVar7);
              iVar2 = FUN_001952d8(uVar13,iVar7);
              if (((*(int *)(iVar8 + iVar2 * 4) == 0) && (*(int *)(iVar8 + iVar3 * 4) == 0)) &&
                 ((piVar12[5] & 0x20U) == 0)) {
                iVar10 = FUN_00105594(piVar12,1);
                uVar13 = 0;
                if ((*(uint *)(iVar10 + 0x14) & 0x20) != 0) goto LAB_0016a3d8;
              }
              else {
LAB_0016a3d8:
                uVar13 = 1;
              }
              *(undefined4 *)(iVar8 + iVar2 * 4) = uVar13;
              *(undefined4 *)(iVar8 + iVar3 * 4) = uVar13;
              iVar10 = iVar3;
              if (iVar2 <= iVar3) goto LAB_0016a3ec;
            }
            else {
              iVar3 = piVar12[0x53];
              iVar2 = FUN_00105594(piVar12,piVar12[0x21]);
              uVar13 = *(undefined4 *)(iVar2 + 0x14c);
              iVar3 = FUN_001952d8(iVar3,iVar7);
              iVar2 = FUN_001952d8(uVar13,iVar7);
              if (((*(int *)(iVar8 + iVar2 * 4) == 0) && (*(int *)(iVar8 + iVar3 * 4) == 0)) &&
                 ((piVar12[5] & 0x20U) == 0)) {
                iVar10 = FUN_00105594(piVar12,piVar12[0x21]);
                uVar13 = 0;
                if ((*(uint *)(iVar10 + 0x14) & 0x20) != 0) goto LAB_0016a20c;
              }
              else {
LAB_0016a20c:
                uVar13 = 1;
              }
              *(undefined4 *)(iVar8 + iVar2 * 4) = uVar13;
              *(undefined4 *)(iVar8 + iVar3 * 4) = uVar13;
              iVar10 = iVar3;
              if (iVar2 <= iVar3) {
LAB_0016a3ec:
                iVar10 = iVar2;
                iVar2 = iVar3;
              }
            }
            FUN_00195330(iVar10,iVar2,iVar7);
            piVar5 = (int *)piVar12[2];
          }
LAB_0016a42c:
          piVar11 = (int *)piVar5[2];
          piVar12 = piVar5;
        } while ((int *)piVar5[2] != (int *)0x0);
        iVar2 = *(int *)(iVar9 + 8);
      }
      iVar3 = *(int *)(iVar2 + 8);
      iVar9 = iVar2;
    } while (*(int *)(iVar2 + 8) != 0);
    iVar2 = param_1[1];
  }
  iVar3 = *(int *)(*(int *)(iVar2 + 900) + 8);
  if (iVar3 == 0) {
    iVar10 = 0;
    iVar9 = 0;
  }
  else {
    iVar10 = 0;
    iVar9 = 0;
    iVar2 = *(int *)(iVar2 + 900);
    do {
      iVar6 = iVar3;
      iVar3 = *(int *)(*(int *)(iVar2 + 0x98) + 8);
      iVar14 = *(int *)(iVar2 + 0x98);
      if (iVar3 != 0) {
        do {
          iVar6 = iVar3;
          if ((*(uint *)(iVar14 + 0x14) & 1) != 0) {
            iVar3 = FUN_001952d8(*(undefined4 *)(iVar14 + 0x14c),iVar7);
            if (*(int *)(iVar3 * 4 + iVar8) == 0) {
              uVar1 = *(uint *)(iVar14 + 0x14) & 0xffffffdf;
              *(uint *)(iVar14 + 0x14) = uVar1;
            }
            else {
              uVar1 = *(uint *)(iVar14 + 0x14) | 0x20;
              *(uint *)(iVar14 + 0x14) = uVar1;
            }
            if ((uVar1 & 0x20) != 0) {
              iVar9 = iVar9 + 1;
            }
            iVar6 = *(int *)(iVar14 + 8);
            iVar10 = iVar10 + 1;
          }
          iVar3 = *(int *)(iVar6 + 8);
          iVar14 = iVar6;
        } while (*(int *)(iVar6 + 8) != 0);
        iVar6 = *(int *)(iVar2 + 8);
      }
      iVar3 = *(int *)(iVar6 + 8);
      iVar2 = iVar6;
    } while (*(int *)(iVar6 + 8) != 0);
  }
  FUN_000e0e0c(*param_1,"Scheduler : %d out of %d instructions are marked global\n",iVar9,iVar10);
  FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),iVar8);
  FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),iVar7);
  return;
}

/* FUN_0016a568 @ 0x16a568 (6080 bytes) */
int FUN_0016a568(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  int *piVar4;
  int *piVar5;
  undefined *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  void *pvVar12;
  int iVar13;
  uint uVar14;
  int *piVar15;
  undefined4 *puVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  undefined4 *puVar25;
  uint *puVar26;
  undefined4 uVar27;
  uint *puVar28;
  undefined4 uVar29;
  undefined1 auStack_78 [8];
  int local_70;
  uint local_58;
  int local_54;
  
  iVar7 = FUN_000e07dc(*param_1,0x24);
  uVar20 = 0x7fffffff;
  if (iVar7 == 0) {
    uVar20 = 0;
  }
  param_1[4] = param_2;
  ((int (*)())FUN_00172000)(param_1[2]);
  FUN_001940a8(auStack_78);
  piVar4 = (int *)(*(int **)(param_1[4] + 0x98))[2];
  if (piVar4 != (int *)0x0) {
    uVar21 = 0;
    bVar2 = false;
    piVar15 = *(int **)(param_1[4] + 0x98);
    do {
      piVar5 = piVar4;
      if ((piVar15[5] & 1U) != 0) {
        piVar15[5] = piVar15[5] & 0xffffefff;
        piVar15[0x54] = 0;
        iVar7 = (**(code **)(*piVar15 + 0x34))(piVar15);
        if ((iVar7 == 0) && (iVar7 = (**(code **)(*piVar15 + 0x38))(piVar15), iVar7 == 0)) {
          iVar7 = ((int (*)())FUN_00164df4)(piVar15);
          if (iVar7 == 0) {
            iVar7 = ((int (*)())FUN_00164fc0)(piVar15);
            if (((iVar7 != 0) ||
                (iVar7 = (**(code **)(*(int *)param_1[3] + 0x2c))((int *)param_1[3],piVar15),
                iVar7 != 0)) ||
               (iVar7 = (**(code **)(*(int *)param_1[3] + 0x28))((int *)param_1[3],piVar15),
               iVar7 != 0)) {
              bVar2 = true;
            }
            piVar15[0x54] = uVar21;
            uVar27 = *(undefined4 *)(*param_1 + 0x378);
            puVar16 = (undefined4 *)FUN_00193e18(uVar27,0x74);
            puVar3 = PTR_DAT_001e9138;
            puVar25 = puVar16 + 1;
            puVar6 = PTR_DAT_001e8b48 + 8;
            *puVar16 = uVar27;
            puVar16[1] = puVar6;
            puVar16[0xc] = 0xffffffff;
            puVar16[1] = puVar3 + 8;
            puVar16[0x11] = 0;
            puVar16[0x1c] = 0;
            iVar7 = 4;
            puVar16[2] = 0;
            puVar16[3] = 0;
            puVar16[0xd] = 0;
            puVar16[0xe] = 0;
            puVar16[0xf] = piVar15;
            puVar16[0x10] = uVar21;
            puVar16[0x12] = 0;
            puVar16[0x17] = 0;
            puVar16[0x18] = 0;
            puVar16[0x19] = 0;
            puVar16[0x1a] = 0;
            puVar16[0x1b] = 0;
            puVar11 = puVar25;
            do {
              puVar11[0x12] = 0;
              puVar11 = puVar11 + 1;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
            puVar16[4] = 0;
            puVar16[7] = 1;
            puVar16[5] = 0;
            puVar16[6] = 1;
            puVar16[8] = 0;
            puVar16[9] = 0;
            puVar16[10] = 0;
            puVar16[0xb] = 0;
            uVar27 = *(undefined4 *)(*param_1 + 0x378);
            puVar11 = (undefined4 *)FUN_00193e18(uVar27,0x14);
            *puVar11 = uVar27;
            puVar11[1] = 2;
            puVar11[4] = uVar27;
            puVar11[2] = 0;
            uVar27 = FUN_00193e18(uVar27,8);
            puVar11[3] = uVar27;
            puVar16[0x12] = puVar11 + 1;
            uVar27 = *(undefined4 *)(*param_1 + 0x378);
            puVar11 = (undefined4 *)FUN_00193e18(uVar27,0x14);
            *puVar11 = uVar27;
            puVar11[1] = 2;
            puVar11[2] = 0;
            puVar11[4] = uVar27;
            uVar27 = FUN_00193e18(uVar27,8);
            puVar11[3] = uVar27;
            puVar16[0x11] = puVar11 + 1;
            if (0 < piVar15[0x21]) {
              iVar7 = 1;
              bVar1 = false;
              do {
                ((int (*)())FUN_00168468)(param_1,puVar25,piVar15,iVar7,0);
                piVar4 = (int *)FUN_00105594(piVar15,iVar7);
                iVar17 = (**(code **)(*piVar4 + 0x5c))();
                if (iVar17 == 0) {
                  piVar4 = (int *)FUN_00105594(piVar15,iVar7);
                  iVar17 = (**(code **)(*piVar4 + 0x60))();
                  if (iVar17 != 0) goto LAB_0016a958;
                  FUN_00105594(piVar15,iVar7);
                  iVar17 = FUN_001045e4();
                  if ((iVar17 != 0) &&
                     (iVar17 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0xd4))(), iVar17 != 0))
                  goto LAB_0016a958;
                }
                else {
LAB_0016a958:
                  piVar4 = (int *)FUN_00105594(piVar15,iVar7);
                  iVar17 = (**(code **)(*piVar4 + 0x60))();
                  if (iVar17 != 0) {
                    piVar5 = (int *)FUN_00105594(piVar4,1);
                    iVar17 = (**(code **)(*piVar5 + 0x5c))();
                    if (iVar17 != 0) {
                      piVar4 = (int *)FUN_00105594(piVar4,1);
                    }
                  }
                  for (iVar17 = 1; iVar18 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar17 <= iVar18;
                      iVar17 = iVar17 + 1) {
                    ((int (*)())FUN_00168468)(param_1,puVar25,piVar4,iVar7,iVar17);
                  }
                }
                FUN_00105594(piVar15,iVar7);
                iVar17 = FUN_00104644();
                if (iVar17 != 0) {
                  bVar1 = true;
                }
                iVar7 = iVar7 + 1;
              } while (iVar7 <= piVar15[0x21]);
              if (bVar1) {
                puVar26 = (uint *)puVar16[0x12];
                uVar14 = 0;
                uVar22 = puVar26[1];
                if (0 < (int)uVar22) {
                  while( true ) {
                    if (uVar14 < *puVar26) {
                      uVar9 = puVar26[1];
                      if (uVar9 <= uVar14) {
                        _memset((void *)(uVar9 * 4 + puVar26[2]),0,(uVar14 - uVar9) * 4 + 4);
                        puVar26[1] = uVar14 + 1;
                      }
                      puVar11 = (undefined4 *)(uVar14 * 4 + puVar26[2]);
                    }
                    else {
                      puVar11 = (undefined4 *)FUN_0019423c(puVar26,uVar14);
                    }
                    iVar17 = *(int *)*puVar11;
                    iVar7 = FUN_00104644(*(undefined4 *)(iVar17 + 0x38));
                    if (iVar7 == 0) {
                      uVar9 = 0;
                      do {
                        puVar26 = (uint *)puVar16[0x12];
                        if (uVar9 < *puVar26) {
                          uVar8 = puVar26[1];
                          if (uVar8 <= uVar9) {
                            _memset((void *)(uVar8 * 4 + puVar26[2]),0,(uVar9 - uVar8) * 4 + 4);
                            puVar26[1] = uVar9 + 1;
                          }
                          puVar11 = (undefined4 *)(uVar9 * 4 + puVar26[2]);
                        }
                        else {
                          puVar11 = (undefined4 *)FUN_0019423c(puVar26,uVar9);
                        }
                        iVar18 = *(int *)*puVar11;
                        iVar7 = FUN_00104644(*(undefined4 *)(iVar18 + 0x38));
                        if ((iVar7 != 0) && (*(int *)(iVar17 + 0x3c) < *(int *)(iVar18 + 0x3c))) {
                          uVar29 = *(undefined4 *)(*param_1 + 0x378);
                          puVar11 = (undefined4 *)FUN_00193e18(uVar29,0x24);
                          uVar27 = DAT_001b0194;
                          *puVar11 = uVar29;
                          puVar11[4] = 1;
                          puVar11[1] = iVar17;
                          puVar11[7] = uVar27;
                          puVar11[3] = 5;
                          puVar11[5] = 0;
                          puVar11[6] = 0;
                          puVar11[8] = 0;
                          puVar11[2] = iVar18;
                          uVar27 = ((int (*)())FUN_00164e7c)(param_1,*(undefined4 *)(iVar17 + 0x38),
                                                *(undefined4 *)(iVar18 + 0x38),0,0,5);
                          puVar11[4] = uVar27;
                          puVar26 = *(uint **)(iVar17 + 0x40);
                          uVar8 = puVar26[1];
                          if (uVar8 < *puVar26) {
                            _memset((void *)(uVar8 * 4 + puVar26[2]),0,4);
                            piVar4 = (int *)(uVar8 * 4 + puVar26[2]);
                            puVar26[1] = uVar8 + 1;
                          }
                          else {
                            piVar4 = (int *)FUN_0019423c(puVar26,uVar8);
                          }
                          *piVar4 = (int)(puVar11 + 1);
                          puVar26 = *(uint **)(iVar18 + 0x44);
                          uVar8 = puVar26[1];
                          if (uVar8 < *puVar26) {
                            _memset((void *)(uVar8 * 4 + puVar26[2]),0,4);
                            piVar4 = (int *)(uVar8 * 4 + puVar26[2]);
                            puVar26[1] = uVar8 + 1;
                          }
                          else {
                            piVar4 = (int *)FUN_0019423c(puVar26,uVar8);
                          }
                          *piVar4 = (int)(puVar11 + 1);
                        }
                        uVar9 = uVar9 + 1;
                      } while (uVar22 != uVar9);
                    }
                    uVar14 = uVar14 + 1;
                    if (uVar22 == uVar14) break;
                    puVar26 = (uint *)puVar16[0x12];
                  }
                }
              }
            }
            if (*(int *)(piVar15[0x22] + 4) == 1) {
              FUN_00193f64(auStack_78,puVar25);
            }
            if (uVar20 == uVar21) {
              uVar14 = uVar21 - 1;
              if (-1 < (int)uVar14) {
                iVar7 = uVar14 * 4;
                uVar22 = 0;
                do {
                  puVar26 = (uint *)param_1[6];
                  if (uVar14 < *puVar26) {
                    uVar9 = puVar26[1];
                    if (uVar9 <= uVar14) {
                      _memset((void *)(uVar9 * 4 + puVar26[2]),0,(uVar14 - uVar9) * 4 + 4);
                      puVar26[1] = uVar14 + 1;
                    }
                    piVar4 = (int *)(iVar7 + puVar26[2]);
                  }
                  else {
                    piVar4 = (int *)FUN_0019423c(puVar26,uVar14);
                  }
                  iVar17 = *piVar4;
                  iVar18 = *(int *)(iVar17 + 0x38);
                  if (((*(uint *)(iVar18 + 0x14) & 2) == 0) &&
                     (*(int *)(*(int *)(iVar18 + 0x88) + 4) != 1)) {
                    uVar29 = *(undefined4 *)(*param_1 + 0x378);
                    puVar11 = (undefined4 *)FUN_00193e18(uVar29,0x24);
                    uVar27 = DAT_001b0194;
                    *puVar11 = uVar29;
                    puVar11[1] = iVar17;
                    puVar11[7] = uVar27;
                    puVar11[8] = 0;
                    puVar11[4] = 1;
                    puVar11[5] = 0;
                    puVar11[6] = 0;
                    puVar11[2] = puVar25;
                    puVar11[3] = 1;
                    uVar27 = ((int (*)())FUN_00164e7c)(param_1,iVar18,piVar15,0,0,1);
                    puVar11[4] = uVar27;
                    puVar26 = *(uint **)(iVar17 + 0x40);
                    uVar9 = puVar26[1];
                    if (uVar9 < *puVar26) {
                      _memset((void *)(uVar9 * 4 + puVar26[2]),0,4);
                      puVar10 = (undefined4 *)(uVar9 * 4 + puVar26[2]);
                      puVar26[1] = uVar9 + 1;
                    }
                    else {
                      puVar10 = (undefined4 *)FUN_0019423c(puVar26,uVar9);
                    }
                    *puVar10 = puVar11 + 1;
                    puVar26 = (uint *)puVar16[0x12];
                    uVar9 = puVar26[1];
                    if (uVar9 < *puVar26) {
                      _memset((void *)(uVar9 * 4 + puVar26[2]),0,4);
                      puVar10 = (undefined4 *)(uVar9 * 4 + puVar26[2]);
                      puVar26[1] = uVar9 + 1;
                    }
                    else {
                      puVar10 = (undefined4 *)FUN_0019423c(puVar26,uVar9);
                    }
                    *puVar10 = puVar11 + 1;
                  }
                  uVar22 = uVar22 + 1;
                  uVar14 = uVar14 - 1;
                  iVar7 = iVar7 + -4;
                } while (uVar22 != uVar21);
              }
            }
            else if ((int)uVar20 < (int)uVar21) {
              puVar26 = (uint *)param_1[6];
              uVar14 = uVar21 - 1;
              if (uVar14 < *puVar26) {
                uVar22 = puVar26[1];
                if (uVar22 <= uVar14) {
                  _memset((void *)(uVar22 * 4 + puVar26[2]),0,(uVar14 - uVar22) * 4 + 4);
                  puVar26[1] = uVar21;
                }
                piVar4 = (int *)(uVar14 * 4 + puVar26[2]);
              }
              else {
                piVar4 = (int *)FUN_0019423c(puVar26,uVar14);
              }
              iVar17 = *piVar4;
              iVar7 = *(int *)(iVar17 + 0x38);
              if (*(int *)(*(int *)(iVar7 + 0x88) + 4) != 1) {
                uVar29 = *(undefined4 *)(*param_1 + 0x378);
                puVar11 = (undefined4 *)FUN_00193e18(uVar29,0x24);
                uVar27 = DAT_001b0194;
                *puVar11 = uVar29;
                puVar11[1] = iVar17;
                puVar11[7] = uVar27;
                puVar11[8] = 0;
                puVar11[3] = 1;
                puVar11[4] = 1;
                puVar11[5] = 0;
                puVar11[6] = 0;
                puVar11[2] = puVar25;
                uVar27 = ((int (*)())FUN_00164e7c)(param_1,iVar7,piVar15,0,0,1);
                puVar11[4] = uVar27;
                puVar26 = *(uint **)(iVar17 + 0x40);
                uVar14 = puVar26[1];
                if (uVar14 < *puVar26) {
                  _memset((void *)(uVar14 * 4 + puVar26[2]),0,4);
                  piVar4 = (int *)(uVar14 * 4 + puVar26[2]);
                  puVar26[1] = uVar14 + 1;
                }
                else {
                  piVar4 = (int *)FUN_0019423c(puVar26,uVar14);
                }
                *piVar4 = (int)(puVar11 + 1);
                puVar26 = (uint *)puVar16[0x12];
                uVar14 = puVar26[1];
                if (uVar14 < *puVar26) {
                  _memset((void *)(uVar14 * 4 + puVar26[2]),0,4);
                  piVar4 = (int *)(uVar14 * 4 + puVar26[2]);
                  puVar26[1] = uVar14 + 1;
                }
                else {
                  piVar4 = (int *)FUN_0019423c(puVar26,uVar14);
                }
                *piVar4 = (int)(puVar11 + 1);
              }
            }
            puVar26 = (uint *)param_1[6];
            uVar14 = puVar26[1];
            if (uVar14 < *puVar26) {
              _memset((void *)(uVar14 * 4 + puVar26[2]),0,4);
              piVar4 = (int *)(uVar14 * 4 + puVar26[2]);
              puVar26[1] = uVar14 + 1;
            }
            else {
              piVar4 = (int *)FUN_0019423c(puVar26,uVar14);
            }
            *piVar4 = (int)puVar25;
            uVar21 = uVar21 + 1;
            piVar5 = (int *)piVar15[2];
          }
          else {
            if (((((piVar15[0x20] == 0) || (iVar7 = FUN_00126760(piVar15[0x26]), iVar7 == 0)) ||
                 ((piVar15[5] & 2U) != 0)) ||
                ((iVar7 = (**(code **)(*piVar15 + 0x50))(piVar15), iVar7 != 0 ||
                 ((piVar15[5] & 0x40U) != 0)))) ||
               (((piVar15[5] & 0x20U) == 0 && (iVar7 = FUN_000e07dc(*param_1,0x25), iVar7 != 0))))
            goto LAB_0016b038;
            iVar7 = *(int *)(*param_1 + 0x3c4) + 1;
            *(int *)(*param_1 + 0x3c4) = iVar7;
            piVar5 = (int *)piVar15[2];
            piVar15[0x25] = iVar7;
          }
        }
        else {
LAB_0016b038:
          piVar5 = (int *)piVar15[2];
        }
      }
      piVar4 = (int *)piVar5[2];
      piVar15 = piVar5;
    } while ((int *)piVar5[2] != (int *)0x0);
    if (bVar2) {
      uVar27 = *(undefined4 *)(*param_1 + 0x378);
      puVar11 = (undefined4 *)FUN_00193e18(uVar27,0x1c);
      puVar26 = puVar11 + 1;
      *puVar11 = uVar27;
      uVar20 = 1;
      puVar11[4] = ((unsigned char *)0x00164bac);
      puVar11[1] = 1;
      puVar11[5] = ((unsigned char *)0x00164bd8);
      iVar7 = 0x20;
      puVar11[6] = uVar27;
      do {
        uVar20 = uVar20 << 1;
        if (0xf < uVar20) break;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      *puVar26 = uVar20;
      puVar11[2] = 0;
      pvVar12 = (void *)FUN_00193e18(uVar27,*puVar26 << 2);
      puVar11[3] = pvVar12;
      _memset(pvVar12,0,*puVar26 << 2);
      uVar21 = uVar21 - 1;
      if (-1 < (int)uVar21) {
        iVar7 = uVar21 * 4;
        local_54 = 0;
        iVar17 = 0;
        iVar18 = 0;
        local_58 = uVar21;
        do {
          puVar28 = (uint *)param_1[6];
          if (uVar21 < *puVar28) {
            uVar20 = puVar28[1];
            if (uVar20 <= uVar21) {
              _memset((void *)(uVar20 * 4 + puVar28[2]),0,(uVar21 - uVar20) * 4 + 4);
              puVar28[1] = uVar21 + 1;
            }
            piVar4 = (int *)(iVar7 + puVar28[2]);
          }
          else {
            piVar4 = (int *)FUN_0019423c(puVar28,uVar21);
          }
          iVar23 = *piVar4;
          piVar4 = *(int **)(iVar23 + 0x38);
          iVar13 = ((int (*)())FUN_00164fc0)(piVar4);
          if (iVar13 != 0) {
            iVar13 = FUN_00194834(puVar26,piVar4);
            if (iVar13 != 0) {
              puVar28 = (uint *)param_1[6];
              uVar20 = *(uint *)(iVar13 + 0x150);
              if (uVar20 < *puVar28) {
                uVar14 = puVar28[1];
                if (uVar14 <= uVar20) {
                  _memset((void *)(uVar14 * 4 + puVar28[2]),0,(uVar20 - uVar14) * 4 + 4);
                  puVar28[1] = uVar20 + 1;
                }
                piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
              }
              else {
                piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
              }
              iVar24 = *piVar15;
              uVar29 = *(undefined4 *)(*param_1 + 0x378);
              puVar16 = (undefined4 *)FUN_00193e18(uVar29,0x24);
              uVar27 = DAT_001b0194;
              *puVar16 = uVar29;
              puVar16[1] = iVar23;
              puVar16[7] = uVar27;
              puVar16[4] = 1;
              puVar16[5] = 0;
              puVar16[6] = 0;
              puVar16[8] = 0;
              puVar16[2] = iVar24;
              puVar16[3] = 1;
              uVar27 = ((int (*)())FUN_00164e7c)(param_1,piVar4,iVar13,0,0,1);
              puVar16[4] = uVar27;
              puVar28 = *(uint **)(iVar23 + 0x40);
              uVar20 = puVar28[1];
              if (uVar20 < *puVar28) {
                _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
                piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
                puVar28[1] = uVar20 + 1;
              }
              else {
                piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
              }
              *piVar15 = (int)(puVar16 + 1);
              puVar28 = *(uint **)(iVar24 + 0x44);
              uVar20 = puVar28[1];
              if (uVar20 < *puVar28) {
                _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
                piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
                puVar28[1] = uVar20 + 1;
              }
              else {
                piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
              }
              *piVar15 = (int)(puVar16 + 1);
              FUN_00194720(puVar26,iVar13);
            }
            FUN_00194d44(puVar26,piVar4);
          }
          iVar24 = (**(code **)(*(int *)param_1[3] + 0x28))((int *)param_1[3],piVar4);
          iVar13 = iVar17;
          if ((iVar24 != 0) && (iVar13 = iVar23, iVar17 != 0)) {
            uVar29 = *(undefined4 *)(*param_1 + 0x378);
            puVar16 = (undefined4 *)FUN_00193e18(uVar29,0x24);
            uVar27 = DAT_001b0194;
            *puVar16 = uVar29;
            puVar16[7] = uVar27;
            puVar16[1] = iVar23;
            puVar16[4] = 1;
            puVar16[5] = 0;
            puVar16[6] = 0;
            puVar16[8] = 0;
            puVar16[2] = iVar17;
            puVar16[3] = 4;
            uVar27 = ((int (*)())FUN_00164e7c)(param_1,piVar4,*(undefined4 *)(iVar17 + 0x38),0,0,4);
            puVar16[4] = uVar27;
            puVar28 = *(uint **)(iVar23 + 0x40);
            uVar20 = puVar28[1];
            if (uVar20 < *puVar28) {
              _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
              piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
              puVar28[1] = uVar20 + 1;
            }
            else {
              piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
            }
            *piVar15 = (int)(puVar16 + 1);
            puVar28 = *(uint **)(iVar17 + 0x44);
            uVar20 = puVar28[1];
            if (uVar20 < *puVar28) {
              _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
              piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
              puVar28[1] = uVar20 + 1;
            }
            else {
              piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
            }
            *piVar15 = (int)(puVar16 + 1);
          }
          iVar17 = (**(code **)(*(int *)param_1[3] + 0x2c))((int *)param_1[3],piVar4);
          iVar24 = iVar18;
          if ((iVar17 != 0) && (iVar24 = iVar23, iVar18 != 0)) {
            uVar29 = *(undefined4 *)(*param_1 + 0x378);
            puVar16 = (undefined4 *)FUN_00193e18(uVar29,0x24);
            uVar27 = DAT_001b0194;
            *puVar16 = uVar29;
            puVar16[7] = uVar27;
            puVar16[1] = iVar23;
            puVar16[4] = 1;
            puVar16[5] = 0;
            puVar16[6] = 0;
            puVar16[8] = 0;
            puVar16[2] = iVar18;
            puVar16[3] = 4;
            uVar27 = ((int (*)())FUN_00164e7c)(param_1,piVar4,*(undefined4 *)(iVar18 + 0x38),0,0,4);
            puVar16[4] = uVar27;
            puVar28 = *(uint **)(iVar23 + 0x40);
            uVar20 = puVar28[1];
            if (uVar20 < *puVar28) {
              _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
              piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
              puVar28[1] = uVar20 + 1;
            }
            else {
              piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
            }
            *piVar15 = (int)(puVar16 + 1);
            puVar28 = *(uint **)(iVar18 + 0x44);
            uVar20 = puVar28[1];
            if (uVar20 < *puVar28) {
              _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
              piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
              puVar28[1] = uVar20 + 1;
            }
            else {
              piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
            }
            *piVar15 = (int)(puVar16 + 1);
          }
          if (0 < piVar4[0x21]) {
            iVar17 = 1;
            do {
              FUN_00105594(piVar4,iVar17);
              iVar18 = ((int (*)())FUN_00164fc0)();
              if (iVar18 != 0) {
                uVar27 = FUN_00105594(piVar4,iVar17);
                piVar15 = (int *)FUN_00194834(puVar26,uVar27);
                if ((piVar15 != (int *)0x0) && (piVar4 != piVar15)) {
                  puVar28 = (uint *)param_1[6];
                  uVar20 = piVar15[0x54];
                  if (uVar20 < *puVar28) {
                    uVar14 = puVar28[1];
                    if (uVar14 <= uVar20) {
                      _memset((void *)(uVar14 * 4 + puVar28[2]),0,(uVar20 - uVar14) * 4 + 4);
                      puVar28[1] = uVar20 + 1;
                    }
                    piVar5 = (int *)(uVar20 * 4 + puVar28[2]);
                  }
                  else {
                    piVar5 = (int *)FUN_0019423c(puVar28,uVar20);
                  }
                  iVar18 = *piVar5;
                  uVar29 = *(undefined4 *)(*param_1 + 0x378);
                  puVar16 = (undefined4 *)FUN_00193e18(uVar29,0x24);
                  uVar27 = DAT_001b0194;
                  *puVar16 = uVar29;
                  puVar16[7] = uVar27;
                  puVar16[1] = iVar23;
                  puVar16[3] = 2;
                  puVar16[4] = 1;
                  puVar16[5] = 0;
                  puVar16[6] = 0;
                  puVar16[8] = 0;
                  puVar16[2] = iVar18;
                  uVar27 = ((int (*)())FUN_00164e7c)(param_1,piVar4,piVar15,iVar17,0,2);
                  puVar16[4] = uVar27;
                  puVar28 = *(uint **)(iVar23 + 0x40);
                  uVar20 = puVar28[1];
                  if (uVar20 < *puVar28) {
                    _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
                    piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
                    puVar28[1] = uVar20 + 1;
                  }
                  else {
                    piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
                  }
                  *piVar15 = (int)(puVar16 + 1);
                  puVar28 = *(uint **)(iVar18 + 0x44);
                  uVar20 = puVar28[1];
                  if (uVar20 < *puVar28) {
                    _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
                    piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
                    puVar28[1] = uVar20 + 1;
                  }
                  else {
                    piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
                  }
                  *piVar15 = (int)(puVar16 + 1);
                }
              }
              iVar17 = iVar17 + 1;
            } while (iVar17 <= piVar4[0x21]);
          }
          iVar17 = (**(code **)(*piVar4 + 0x28))(piVar4);
          if ((iVar17 != 0) && (iVar24 != 0)) {
            uVar29 = *(undefined4 *)(*param_1 + 0x378);
            puVar16 = (undefined4 *)FUN_00193e18(uVar29,0x24);
            uVar27 = DAT_001b0194;
            *puVar16 = uVar29;
            puVar16[7] = uVar27;
            puVar16[1] = iVar23;
            puVar16[4] = 1;
            puVar16[5] = 0;
            puVar16[6] = 0;
            puVar16[8] = 0;
            puVar16[2] = iVar24;
            puVar16[3] = 4;
            uVar27 = ((int (*)())FUN_00164e7c)(param_1,piVar4,*(undefined4 *)(iVar24 + 0x38),0,0,4);
            puVar16[4] = uVar27;
            puVar28 = *(uint **)(iVar23 + 0x40);
            uVar20 = puVar28[1];
            if (uVar20 < *puVar28) {
              _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
              piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
              puVar28[1] = uVar20 + 1;
            }
            else {
              piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
            }
            *piVar15 = (int)(puVar16 + 1);
            puVar28 = *(uint **)(iVar24 + 0x44);
            uVar20 = puVar28[1];
            if (uVar20 < *puVar28) {
              _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
              piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
              puVar28[1] = uVar20 + 1;
            }
            else {
              piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
            }
            *piVar15 = (int)(puVar16 + 1);
          }
          iVar17 = (**(code **)(*piVar4 + 0x24))(piVar4);
          if (((iVar17 != 0) && ((piVar4[5] & 2U) == 0)) && (iVar13 != 0)) {
            uVar29 = *(undefined4 *)(*param_1 + 0x378);
            puVar16 = (undefined4 *)FUN_00193e18(uVar29,0x24);
            uVar27 = DAT_001b0194;
            *puVar16 = uVar29;
            puVar16[7] = uVar27;
            puVar16[1] = iVar23;
            puVar16[8] = 0;
            puVar16[4] = 1;
            puVar16[5] = 0;
            puVar16[6] = 0;
            puVar16[2] = iVar13;
            puVar16[3] = 4;
            uVar27 = ((int (*)())FUN_00164e7c)(param_1,piVar4,*(undefined4 *)(iVar13 + 0x38),0,0,4);
            puVar16[4] = uVar27;
            puVar28 = *(uint **)(iVar23 + 0x40);
            uVar20 = puVar28[1];
            if (uVar20 < *puVar28) {
              _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
              piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
              puVar28[1] = uVar20 + 1;
            }
            else {
              piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
            }
            *piVar15 = (int)(puVar16 + 1);
            puVar28 = *(uint **)(iVar13 + 0x44);
            uVar20 = puVar28[1];
            if (uVar20 < *puVar28) {
              _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
              piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
              puVar28[1] = uVar20 + 1;
            }
            else {
              piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
            }
            *piVar15 = (int)(puVar16 + 1);
          }
          iVar17 = (**(code **)(*(int *)param_1[3] + 0x20))((int *)param_1[3],piVar4);
          if ((iVar17 != 0) && (iVar17 = FUN_00193f08(auStack_78), iVar17 == 0)) {
            iVar18 = *(int *)(local_70 + 8);
            iVar17 = local_70;
            while (iVar18 != 0) {
              uVar29 = *(undefined4 *)(*param_1 + 0x378);
              puVar16 = (undefined4 *)FUN_00193e18(uVar29,0x24);
              uVar27 = DAT_001b0194;
              *puVar16 = uVar29;
              puVar16[7] = uVar27;
              puVar16[1] = iVar23;
              puVar16[4] = 1;
              puVar16[5] = 0;
              puVar16[6] = 0;
              puVar16[8] = 0;
              puVar16[2] = iVar17;
              puVar16[3] = 4;
              uVar27 = ((int (*)())FUN_00164e7c)(param_1,piVar4,*(undefined4 *)(iVar17 + 0x38),0,0,4);
              puVar16[4] = uVar27;
              puVar28 = *(uint **)(iVar23 + 0x40);
              uVar20 = puVar28[1];
              if (uVar20 < *puVar28) {
                _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
                piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
                puVar28[1] = uVar20 + 1;
              }
              else {
                piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
              }
              *piVar15 = (int)(puVar16 + 1);
              puVar28 = *(uint **)(iVar17 + 0x44);
              uVar20 = puVar28[1];
              if (uVar20 < *puVar28) {
                _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
                piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
                puVar28[1] = uVar20 + 1;
              }
              else {
                piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
              }
              *piVar15 = (int)(puVar16 + 1);
              iVar17 = *(int *)(iVar17 + 8);
              iVar18 = *(int *)(iVar17 + 8);
            }
          }
          if (((*(int *)(param_1[1] + 0x33c) != 0) &&
              (*(int *)(*(int *)(*param_1 + 0x30c) + 0x20) <
               *(int *)(*(int *)(param_1[1] + 0x33c) + 300))) &&
             (iVar17 = (**(code **)(*(int *)param_1[2] + 0x28))((int *)param_1[2],piVar4),
             iVar17 != 0)) {
            iVar18 = *(int *)(local_70 + 8);
            iVar17 = local_70;
            while (iVar19 = iVar18, iVar19 != 0) {
              if (*(int *)(iVar17 + 0x38) == *(int *)(param_1[1] + 0x33c)) {
                uVar29 = *(undefined4 *)(*param_1 + 0x378);
                puVar16 = (undefined4 *)FUN_00193e18(uVar29,0x24);
                uVar27 = DAT_001b0194;
                *puVar16 = uVar29;
                puVar16[7] = uVar27;
                puVar16[1] = iVar23;
                puVar16[3] = 2;
                puVar16[4] = 1;
                puVar16[5] = 0;
                puVar16[6] = 0;
                puVar16[8] = 0;
                puVar16[2] = iVar17;
                uVar27 = ((int (*)())FUN_00164e7c)(param_1,piVar4,*(undefined4 *)(iVar17 + 0x38),0,0,2);
                puVar16[4] = uVar27;
                puVar28 = *(uint **)(iVar23 + 0x40);
                uVar20 = puVar28[1];
                if (uVar20 < *puVar28) {
                  _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
                  piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
                  puVar28[1] = uVar20 + 1;
                }
                else {
                  piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
                }
                *piVar15 = (int)(puVar16 + 1);
                puVar28 = *(uint **)(iVar17 + 0x44);
                uVar20 = puVar28[1];
                if (uVar20 < *puVar28) {
                  _memset((void *)(uVar20 * 4 + puVar28[2]),0,4);
                  piVar15 = (int *)(uVar20 * 4 + puVar28[2]);
                  puVar28[1] = uVar20 + 1;
                }
                else {
                  piVar15 = (int *)FUN_0019423c(puVar28,uVar20);
                }
                *piVar15 = (int)(puVar16 + 1);
                iVar19 = *(int *)(iVar17 + 8);
              }
              iVar17 = iVar19;
              iVar18 = *(int *)(iVar19 + 8);
            }
          }
          uVar21 = uVar21 - 1;
          iVar7 = iVar7 + -4;
          local_54 = local_54 + 1;
          iVar17 = iVar13;
          iVar18 = iVar24;
        } while (local_54 != local_58 + 1);
      }
      if (puVar26 != (uint *)0x0) {
        uVar20 = *puVar26;
        if (uVar20 == 0) {
          iVar7 = puVar11[3];
        }
        else {
          iVar7 = puVar11[3];
          uVar21 = 0;
          do {
            if (*(int *)(uVar21 * 4 + iVar7) != 0) {
              FUN_00193cc0(puVar11[6]);
              uVar20 = *puVar26;
              iVar7 = puVar11[3];
            }
            uVar21 = uVar21 + 1;
          } while (uVar21 < uVar20);
        }
        FUN_00193cc0(puVar11[6],iVar7);
        FUN_00193cc0(*puVar11,puVar11);
      }
    }
  }
  return;
}

/* FUN_0016bd70 @ 0x16bd70 (1140 bytes) */
int FUN_0016bd70(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint *puVar17;
  undefined4 uVar18;
  uint uVar19;
  uint local_68;
  uint local_64;
  int local_60;
  undefined4 local_5c;
  
  local_5c = *(undefined4 *)(*param_1 + 0x378);
  uVar11 = *(uint *)(param_1[6] + 4);
  local_64 = 0;
  local_68 = 2;
  local_60 = FUN_00193e18(local_5c,8);
  if (0 < (int)uVar11) {
    uVar14 = 0;
    puVar10 = (uint *)0x0;
    do {
      puVar17 = (uint *)param_1[6];
      if (uVar14 < *puVar17) {
        uVar3 = puVar17[1];
        if (uVar3 <= uVar14) {
          _memset((void *)(uVar3 * 4 + puVar17[2]),0,(uVar14 - uVar3) * 4 + 4);
          puVar17[1] = uVar14 + 1;
        }
        piVar4 = (int *)(uVar14 * 4 + puVar17[2]);
      }
      else {
        piVar4 = (int *)FUN_0019423c(puVar17,uVar14);
      }
      iVar13 = *piVar4;
      if (((((*(int *)(iVar13 + 0x60) == 0) &&
            (piVar4 = *(int **)(iVar13 + 0x38), piVar4[0x20] != 0)) &&
           (iVar5 = FUN_00126760(piVar4[0x26]), iVar5 != 0)) &&
          (((piVar4[5] & 2U) == 0 && (iVar5 = (**(code **)(*piVar4 + 0x50))(piVar4), iVar5 == 0))))
         && ((*(uint *)(*(int *)(iVar13 + 0x38) + 0x14) & 0x20) == 0)) {
        if (puVar10 == (uint *)0x0) {
          uVar18 = *(undefined4 *)(*param_1 + 0x378);
          puVar6 = (undefined4 *)FUN_00193e18(uVar18,0x2c);
          uVar3 = DAT_001b01a8;
          uVar2 = DAT_001b0198;
          puVar10 = puVar6 + 1;
          *puVar6 = uVar18;
          puVar6[1] = uVar3;
          puVar6[6] = 0x7fffffff;
          puVar6[2] = 0xffffffff;
          iVar5 = 4;
          puVar6[4] = uVar2;
          puVar6[5] = 0;
          puVar6[3] = 0;
          puVar17 = puVar10;
          do {
            puVar17[6] = 0;
            puVar17 = puVar17 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        uVar3 = local_64;
        *(uint **)(iVar13 + 0x60) = puVar10;
        puVar10[4] = 1;
        *puVar10 = *(uint *)(*(int *)(iVar13 + 0x38) + 0xc);
        if (local_64 < local_68) {
          iVar5 = local_64 * 4;
          _memset((void *)(iVar5 + local_60),0,4);
          local_64 = uVar3 + 1;
          piVar4 = (int *)(iVar5 + local_60);
        }
        else {
          piVar4 = (int *)FUN_0019423c(&local_68,local_64);
        }
        *piVar4 = iVar13;
        while (uVar3 = DAT_001b01a8, local_64 != 0) {
          piVar4 = (int *)0x0;
          if (local_64 - 1 < local_64) {
            piVar4 = (int *)((local_64 - 1) * 4 + local_60);
          }
          iVar5 = *piVar4;
          FUN_00194208(&local_68);
          puVar17 = *(uint **)(iVar5 + 0x40);
          uVar15 = 0;
          uVar3 = puVar17[1];
          if (0 < (int)uVar3) {
            while( true ) {
              if (uVar15 < *puVar17) {
                uVar7 = puVar17[1];
                if (uVar7 <= uVar15) {
                  _memset((void *)(uVar7 * 4 + puVar17[2]),0,(uVar15 - uVar7) * 4 + 4);
                  puVar17[1] = uVar15 + 1;
                }
                piVar4 = (int *)(uVar15 * 4 + puVar17[2]);
              }
              else {
                piVar4 = (int *)FUN_0019423c(puVar17,uVar15);
              }
              iVar16 = *piVar4;
              if (*(int *)(iVar16 + 8) == 0) {
                iVar12 = *(int *)(iVar16 + 4);
                uVar19 = 0;
                puVar17 = *(uint **)(iVar12 + 0x44);
                uVar7 = puVar17[1];
                if (0 < (int)uVar7) {
                  while( true ) {
                    if (uVar19 < *puVar17) {
                      uVar8 = puVar17[1];
                      if (uVar8 <= uVar19) {
                        _memset((void *)(uVar8 * 4 + puVar17[2]),0,(uVar19 - uVar8) * 4 + 4);
                        puVar17[1] = uVar19 + 1;
                      }
                      puVar6 = (undefined4 *)(uVar19 * 4 + puVar17[2]);
                    }
                    else {
                      puVar6 = (undefined4 *)FUN_0019423c(puVar17,uVar19);
                    }
                    uVar8 = local_64;
                    piVar4 = (int *)*puVar6;
                    if (((piVar4[2] == 0) && (piVar4[4] == *(int *)(iVar16 + 0x10))) &&
                       ((piVar4[5] == *(int *)(iVar16 + 0x14) && (*(int *)(*piVar4 + 0x60) == 0))))
                    {
                      *(uint **)(*piVar4 + 0x60) = puVar10;
                      puVar10[4] = puVar10[4] + 1;
                      *puVar10 = *puVar10 | *(uint *)(*(int *)(*piVar4 + 0x38) + 0xc);
                      iVar9 = *piVar4;
                      if (local_64 < local_68) {
                        iVar1 = local_64 * 4;
                        _memset((void *)(iVar1 + local_60),0,4);
                        local_64 = uVar8 + 1;
                        piVar4 = (int *)(iVar1 + local_60);
                      }
                      else {
                        piVar4 = (int *)FUN_0019423c(&local_68,local_64);
                      }
                      *piVar4 = iVar9;
                    }
                    uVar19 = uVar19 + 1;
                    if (uVar7 == uVar19) break;
                    puVar17 = *(uint **)(iVar12 + 0x44);
                  }
                }
              }
              uVar15 = uVar15 + 1;
              if (uVar3 == uVar15) break;
              puVar17 = *(uint **)(iVar5 + 0x40);
            }
          }
        }
        if (puVar10[4] == 1) {
          *(undefined4 *)(iVar13 + 0x60) = 0;
          *puVar10 = uVar3;
          puVar10[4] = 0;
        }
        else {
          puVar10 = (uint *)0x0;
        }
      }
      uVar14 = uVar14 + 1;
    } while (uVar11 != uVar14);
    if (puVar10 != (uint *)0x0) {
      FUN_00193cc0(puVar10[-1],puVar10 + -1);
    }
  }
  FUN_00193cc0(local_5c,local_60);
  return;
}

/* FUN_0016c1fc @ 0x16c1fc (1092 bytes) */
int FUN_0016c1fc(param_1)
  int *param_1;
{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  void *pvVar12;
  int iVar13;
  
  piVar9 = (int *)param_1[0xc];
  iVar4 = *piVar9;
  if (iVar4 == 0) {
    iVar4 = piVar9[1];
    if (iVar4 == 0) goto LAB_0016c27c;
  }
  else if (piVar9[1] != 0) goto LAB_0016c27c;
  if (((*(int *)(iVar4 + 100) == 0) && (*(int *)(iVar4 + 0x60) == 0)) &&
     (*(int *)(*(int *)(iVar4 + 0x38) + 0x98) == 1)) {
    *(undefined4 *)(*(int *)(iVar4 + 0x38) + 0x98) = 0;
    piVar9 = (int *)param_1[0xc];
  }
LAB_0016c27c:
  iVar4 = 0;
  while( true ) {
    iVar13 = piVar9[iVar4];
    if ((((iVar13 != 0) && (piVar9 = *(int **)(iVar13 + 0x38), piVar9[0x20] != 0)) &&
        ((iVar5 = FUN_00126760(piVar9[0x26]), iVar5 != 0 &&
         (((piVar9[5] & 2U) == 0 && (iVar5 = (**(code **)(*piVar9 + 0x50))(piVar9), iVar5 == 0))))))
       && ((piVar9[5] & 0x40U) != 0)) {
      iVar5 = piVar9[0x25];
      iVar11 = 0;
      piVar10 = param_1;
      do {
        iVar6 = FUN_001054ec(piVar9,0);
        if (*(char *)(iVar11 + iVar6 + 0x10) != '\x01') {
          *(int *)(piVar10[0x4d] + iVar5 * 4) = iVar13;
        }
        bVar2 = iVar11 != 3;
        piVar10 = piVar10 + 1;
        iVar11 = iVar11 + 1;
      } while (bVar2);
    }
    if (4 < iVar4 + 1) break;
    piVar9 = (int *)param_1[0xc];
    iVar4 = iVar4 + 1;
  }
  iVar4 = param_1[0xc];
  iVar13 = 0;
  do {
    iVar5 = iVar13 * 4;
    iVar13 = iVar13 + 1;
    iVar4 = *(int *)(iVar5 + iVar4);
    if (iVar4 != 0) {
      piVar9 = *(int **)(iVar4 + 0x38);
      iVar5 = FUN_000e07dc(*param_1,0x25);
      if (iVar5 == 0) {
LAB_0016c3e0:
        iVar5 = piVar9[0x20];
      }
      else {
        iVar5 = 0;
        if (piVar9[0x20] != 0) {
          iVar5 = FUN_00126760(piVar9[0x26]);
          if ((((iVar5 != 0) && ((piVar9[5] & 2U) == 0)) &&
              (iVar5 = (**(code **)(*piVar9 + 0x50))(piVar9), iVar5 == 0)) &&
             (((piVar9[5] & 0x40U) == 0 && ((piVar9[5] & 0x20U) == 0)))) {
            if ((*(int *)(iVar4 + 0x60) == 0) ||
               (iVar5 = *(int *)(*(int *)(iVar4 + 0x60) + 4), iVar5 < 0)) {
              iVar11 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x7c))
                                 (*(int **)(*param_1 + 0x30c),piVar9);
              iVar5 = DAT_001b0194;
              if (iVar11 != 0) {
                if (*(int **)(iVar4 + 0x60) == (int *)0x0) {
                  iVar5 = piVar9[3];
                }
                else {
                  iVar5 = **(int **)(iVar4 + 0x60);
                }
              }
              iVar5 = ((int (*)())FUN_00167b68)(param_1,piVar9[0x26],iVar5);
              if (iVar5 < 0) {
                iVar5 = param_1[0x52];
                iVar11 = param_1[0x53];
                param_1[0x52] = iVar5 + 1;
                if (iVar11 < iVar5 + 1) {
                  piVar10 = param_1;
                  do {
                    pvVar12 = (void *)piVar10[0x4d];
                    pvVar7 = (void *)FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),iVar11 << 3);
                    iVar6 = param_1[0x53];
                    piVar10[0x4d] = (int)pvVar7;
                    piVar10 = piVar10 + 1;
                    _memcpy(pvVar7,pvVar12,iVar6 << 2);
                    FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),pvVar12);
                  } while (piVar10 != param_1 + 4);
                  param_1[0x53] = iVar11 << 1;
                }
                iVar11 = iVar5 * 4;
                iVar6 = 4;
                piVar10 = param_1;
                do {
                  piVar1 = piVar10 + 0x4d;
                  piVar10 = piVar10 + 1;
                  *(undefined4 *)(iVar11 + *piVar1) = 0;
                  iVar6 = iVar6 + -1;
                } while (iVar6 != 0);
              }
              else {
                iVar11 = iVar5 << 2;
              }
              iVar6 = 0;
              piVar10 = param_1;
              do {
                iVar8 = FUN_001054ec(piVar9,0);
                if (*(char *)(iVar6 + iVar8 + 0x10) != '\x01') {
                  *(int *)(piVar10[0x4d] + iVar11) = iVar4;
                }
                bVar2 = iVar6 != 3;
                piVar10 = piVar10 + 1;
                iVar6 = iVar6 + 1;
              } while (bVar2);
              if (*(int *)(iVar4 + 0x60) != 0) {
                *(int *)(*(int *)(iVar4 + 0x60) + 4) = iVar5;
              }
            }
            else {
              iVar11 = 0;
              piVar10 = param_1;
              do {
                iVar6 = FUN_001054ec(piVar9,0);
                if (*(char *)(iVar11 + iVar6 + 0x10) != '\x01') {
                  *(int *)(piVar10[0x4d] + iVar5 * 4) = iVar4;
                }
                bVar2 = iVar11 != 3;
                piVar10 = piVar10 + 1;
                iVar11 = iVar11 + 1;
              } while (bVar2);
            }
            piVar9[0x25] = iVar5;
            piVar9[5] = piVar9[5] | 0x40;
            goto LAB_0016c620;
          }
          goto LAB_0016c3e0;
        }
      }
      if (((iVar5 != 0) && (iVar4 = FUN_00126760(piVar9[0x26]), iVar4 != 0)) &&
         (((piVar9[5] & 2U) == 0 && (iVar4 = (**(code **)(*piVar9 + 0x50))(piVar9), iVar4 == 0)))) {
        uVar3 = piVar9[5];
        if ((uVar3 & 0x20) == 0) {
          iVar4 = FUN_000e07dc(*param_1,0x25);
          if (iVar4 != 0) goto LAB_0016c620;
          uVar3 = piVar9[5];
        }
        if ((uVar3 & 0x40) == 0) {
          iVar4 = *(int *)(*param_1 + 0x3c4) + 1;
          *(int *)(*param_1 + 0x3c4) = iVar4;
          piVar9[0x25] = iVar4;
        }
      }
    }
LAB_0016c620:
    if (4 < iVar13) {
      return;
    }
    iVar4 = param_1[0xc];
  } while( true );
}

/* FUN_0016c640 @ 0x16c640 (816 bytes) */
int FUN_0016c640(param_1)
  undefined4 *param_1;
{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  int *piVar12;
  
  iVar6 = 0;
  ((int (*)())FUN_0016c1fc)();
  iVar4 = param_1[0xc];
  iVar10 = 0;
  iVar5 = *(int *)(*(int *)(param_1[4] + 0xcc) + 4);
  do {
    iVar8 = *(int *)(iVar6 * 4 + iVar4);
    if (iVar8 != 0) {
      iVar10 = *(int *)(iVar8 + 0x38);
      uVar9 = 0;
      FUN_000e7688(param_1[4],iVar10);
      ((int (*)())FUN_00165788)(iVar10,*param_1);
      *(uint *)(iVar10 + 0x14) = *(uint *)(iVar10 + 0x14) | 4;
      puVar11 = *(uint **)(iVar8 + 0x44);
      uVar7 = puVar11[1];
      if (0 < (int)uVar7) {
        while( true ) {
          if (uVar9 < *puVar11) {
            uVar2 = puVar11[1];
            if (uVar2 <= uVar9) {
              _memset((void *)(uVar2 * 4 + puVar11[2]),0,(uVar9 - uVar2) * 4 + 4);
              puVar11[1] = uVar9 + 1;
            }
            puVar3 = (undefined4 *)(uVar9 * 4 + puVar11[2]);
          }
          else {
            puVar3 = (undefined4 *)FUN_0019423c(puVar11,uVar9);
          }
          uVar9 = uVar9 + 1;
          piVar12 = (int *)*puVar3;
          if (((piVar12[2] == 0) &&
              (iVar4 = (**(code **)(**(int **)(*piVar12 + 0x38) + 0x5c))(), iVar4 != 0)) &&
             (*(int *)(*(int *)(*piVar12 + 0x38) + 0x158) == 0)) {
            FUN_000e7738(param_1[4],iVar5);
            *(uint *)(*(int *)(*piVar12 + 0x38) + 0x14) =
                 *(uint *)(*(int *)(*piVar12 + 0x38) + 0x14) | 4;
            iVar5 = *(int *)(*piVar12 + 0x38);
          }
          if (uVar7 == uVar9) break;
          puVar11 = *(uint **)(iVar8 + 0x44);
        }
      }
      iVar4 = param_1[0xc];
    }
    bVar1 = iVar6 != 4;
    iVar6 = iVar6 + 1;
  } while (bVar1);
  iVar6 = *(int *)(iVar4 + 0x1c);
  for (iVar4 = *(int *)(*(int *)(iVar4 + 0x1c) + 8); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    iVar8 = *(int *)(iVar6 + 0x38);
    if ((*(int *)(iVar8 + 0x98) == 0x45) || (*(int *)(iVar8 + 0x98) == 0x44)) {
      FUN_000e7738(param_1[4],iVar5,iVar8);
      *(uint *)(iVar8 + 0x14) = *(uint *)(iVar8 + 0x14) | 4;
      iVar5 = iVar8;
      if (iVar10 == 0) {
        iVar10 = iVar8;
      }
    }
    else {
      uVar9 = 0;
      FUN_000e7688(param_1[4],iVar8);
      ((int (*)())FUN_00165788)(iVar8,*param_1);
      *(uint *)(iVar8 + 0x14) = *(uint *)(iVar8 + 0x14) | 4;
      puVar11 = *(uint **)(iVar6 + 0x44);
      uVar7 = puVar11[1];
      iVar10 = iVar8;
      if (0 < (int)uVar7) {
        while( true ) {
          if (uVar9 < *puVar11) {
            uVar2 = puVar11[1];
            if (uVar2 <= uVar9) {
              _memset((void *)(uVar2 * 4 + puVar11[2]),0,(uVar9 - uVar2) * 4 + 4);
              puVar11[1] = uVar9 + 1;
            }
            puVar3 = (undefined4 *)(uVar9 * 4 + puVar11[2]);
          }
          else {
            puVar3 = (undefined4 *)FUN_0019423c(puVar11,uVar9);
          }
          uVar9 = uVar9 + 1;
          piVar12 = (int *)*puVar3;
          if (((piVar12[2] == 0) &&
              (iVar10 = (**(code **)(**(int **)(*piVar12 + 0x38) + 0x5c))(), iVar10 != 0)) &&
             (*(int *)(*(int *)(*piVar12 + 0x38) + 0x158) == 0)) {
            FUN_000e7738(param_1[4],iVar5);
            *(uint *)(*(int *)(*piVar12 + 0x38) + 0x14) =
                 *(uint *)(*(int *)(*piVar12 + 0x38) + 0x14) | 4;
            iVar5 = *(int *)(*piVar12 + 0x38);
          }
          iVar10 = iVar8;
          if (uVar7 == uVar9) break;
          puVar11 = *(uint **)(iVar6 + 0x44);
        }
      }
    }
    iVar6 = iVar4;
  }
  if (iVar10 != 0) {
    *(uint *)(iVar10 + 0x14) = *(uint *)(iVar10 + 0x14) & 0xfffffffb;
  }
  return iVar10;
}

/* FUN_0016c970 @ 0x16c970 (1108 bytes) */
int FUN_0016c970(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  char *pcVar10;
  int iVar11;
  
  piVar9 = *(int **)(param_2 + 0x38);
  if (((((piVar9[5] & 0x20U) == 0) && (piVar9[0x20] != 0)) &&
      (iVar2 = FUN_00126760(piVar9[0x26]), iVar2 != 0)) && ((piVar9[5] & 2U) == 0)) {
    (**(code **)(*piVar9 + 0x50))(piVar9);
  }
  pcVar10 = *(char **)(param_2 + 0x60);
  if (pcVar10 != (char *)0x0) {
    iVar4 = 4;
    iVar2 = 0;
    pcVar6 = pcVar10;
    pcVar8 = pcVar10;
    do {
      if (((*pcVar6 != '\0') && (*(int *)(pcVar8 + 0x18) != 0)) &&
         (0 < *(int *)(iVar2 * 4 + *(int *)(pcVar8 + 0x18) + 0x48))) {
        return;
      }
      iVar2 = iVar2 + 1;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    uVar5 = *(uint *)(pcVar10 + 4);
    if ((-1 < (int)uVar5) && ((int)uVar5 < param_1[0x51])) {
      iVar2 = *(int *)(pcVar10 + 0x14);
      if (iVar2 == 0) {
        iVar4 = param_1[0x4c];
        uVar3 = uVar5 >> 3 & 0x1ffffffc;
      }
      else {
        iVar4 = param_1[0x4c];
        uVar3 = uVar5 >> 3 & 0x1ffffffc;
        if ((*(uint *)(uVar3 + iVar4 + 8) >> (uVar5 & 0x1f) & 1) != 0) goto LAB_0016cd84;
      }
      if ((*(uint *)(uVar3 + iVar4 + 8) >> (uVar5 & 0x1f) & 1) == 0) {
        return;
      }
      iVar2 = 4;
      piVar9 = param_1;
      pcVar6 = pcVar10;
      do {
        if (*pcVar6 != '\0') {
          *(int *)(*(int *)(pcVar10 + 4) * 4 + piVar9[0x54]) = param_1[0xb];
        }
        pcVar6 = pcVar6 + 1;
        piVar9 = piVar9 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return;
    }
    iVar2 = *(int *)(pcVar10 + 0x14);
LAB_0016cd84:
    iVar4 = (**(code **)(*(int *)param_1[3] + 0x18))();
    if ((iVar4 <= iVar2) &&
       (iVar4 = ((int (*)())FUN_00164bec)(param_1,*(undefined4 *)pcVar10,iVar2,1), -1 < iVar4)) {
      iVar7 = param_1[0x51];
      iVar2 = *(int *)(*(int *)(pcVar10 + 8) + 0x38);
      while( true ) {
        if (iVar2 == 0) {
          return;
        }
        *(int *)(iVar2 + 0x94) = iVar4 + iVar7;
        if ((*(uint *)(iVar2 + 0x14) & 0x200) == 0) break;
        iVar2 = FUN_00105594(iVar2,*(undefined4 *)(iVar2 + 0x84));
      }
      return;
    }
    iVar2 = ((int (*)())FUN_00164bec)(param_1,*(undefined4 *)pcVar10,iVar2,0);
    bVar1 = iVar2 < 0;
    if (bVar1) {
      iVar2 = *(int *)(*param_1 + 0x3c4) + 1;
      *(int *)(*param_1 + 0x3c4) = iVar2;
    }
    iVar4 = *(int *)(*(int *)(pcVar10 + 8) + 0x38);
    while( true ) {
      if (iVar4 == 0) {
        return;
      }
      *(int *)(iVar4 + 0x94) = iVar2;
      if (bVar1) {
        uVar5 = *(uint *)(iVar4 + 0x14) & 0xffffffbf;
        *(uint *)(iVar4 + 0x14) = uVar5;
      }
      else {
        uVar5 = *(uint *)(iVar4 + 0x14) | 0x40;
        *(uint *)(iVar4 + 0x14) = uVar5;
      }
      if ((uVar5 & 0x200) == 0) break;
      iVar4 = FUN_00105594(iVar4,*(undefined4 *)(iVar4 + 0x84));
    }
    return;
  }
  iVar7 = *(int *)(param_2 + 0x38);
  iVar11 = 4;
  iVar2 = iVar7;
  iVar4 = param_2;
  do {
    if ((*(char *)(iVar2 + 0xc) != '\0') && (0 < *(int *)(iVar4 + 0x48))) {
      return;
    }
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  uVar5 = *(uint *)(iVar7 + 0x94);
  if (((*(uint *)(iVar7 + 0x14) & 0x40) == 0) || (param_1[0x51] <= (int)uVar5)) {
    iVar2 = *(int *)(param_2 + 0x2c);
LAB_0016cd5c:
    iVar4 = (**(code **)(*(int *)param_1[3] + 0x18))();
    if ((iVar2 < iVar4) ||
       (iVar4 = ((int (*)())FUN_00164bec)(param_1,*(undefined4 *)(*(int *)(param_2 + 0x38) + 0xc),iVar2,1),
       iVar4 < 0)) {
      iVar2 = ((int (*)())FUN_00164bec)(param_1,*(undefined4 *)(*(int *)(param_2 + 0x38) + 0xc),iVar2,0);
      bVar1 = iVar2 < 0;
      if (bVar1) {
        iVar2 = *(int *)(*param_1 + 0x3c4) + 1;
        *(int *)(*param_1 + 0x3c4) = iVar2;
      }
      *(int *)(*(int *)(param_2 + 0x38) + 0x94) = iVar2;
      iVar2 = *(int *)(param_2 + 0x38);
      if (bVar1) {
        *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xffffffbf;
      }
      else {
        *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x40;
      }
    }
    else {
      *(int *)(*(int *)(param_2 + 0x38) + 0x94) = iVar4 + param_1[0x51];
    }
  }
  else {
    iVar2 = *(int *)(param_2 + 0x2c);
    if (iVar2 == 0) {
      iVar4 = param_1[0x4c];
      uVar3 = uVar5 >> 3 & 0x1ffffffc;
    }
    else {
      iVar4 = param_1[0x4c];
      uVar3 = uVar5 >> 3 & 0x1ffffffc;
      if ((*(uint *)(uVar3 + iVar4 + 8) >> (uVar5 & 0x1f) & 1) != 0) goto LAB_0016cd5c;
    }
    if ((*(uint *)(uVar3 + iVar4 + 8) >> (uVar5 & 0x1f) & 1) != 0) {
      iVar4 = 4;
      iVar2 = 0;
      piVar9 = param_1;
      while( true ) {
        if (*(char *)(iVar7 + iVar2 + 0xc) != '\0') {
          *(int *)(piVar9[0x54] + uVar5 * 4) = param_1[0xb];
        }
        iVar2 = iVar2 + 1;
        piVar9 = piVar9 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) break;
        iVar7 = *(int *)(param_2 + 0x38);
      }
    }
  }
  return;
}

/* FUN_0016cdc4 @ 0x16cdc4 (1516 bytes) */
int FUN_0016cdc4(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  bool bVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  int *piVar14;
  undefined4 local_48 [7];
  
  uVar11 = 0;
  puVar13 = *(uint **)(param_2 + 0x44);
  piVar9 = *(int **)(param_2 + 0x38);
  uVar8 = puVar13[1];
  if (0 < (int)uVar8) {
    while( true ) {
      if (uVar11 < *puVar13) {
        uVar3 = puVar13[1];
        if (uVar3 <= uVar11) {
          _memset((void *)(uVar3 * 4 + puVar13[2]),0,(uVar11 - uVar3) * 4 + 4);
          puVar13[1] = uVar11 + 1;
        }
        puVar4 = (undefined4 *)(uVar11 * 4 + puVar13[2]);
      }
      else {
        puVar4 = (undefined4 *)FUN_0019423c(puVar13,uVar11);
      }
      uVar11 = uVar11 + 1;
      piVar14 = (int *)*puVar4;
      if (piVar14[2] == 0) {
        iVar12 = *piVar14;
        iVar5 = (**(code **)(*piVar9 + 0x60))(piVar9);
        if ((iVar5 != 0) && (iVar5 = (**(code **)(**(int **)(iVar12 + 0x38) + 0x5c))(), iVar5 != 0))
        {
          FUN_0019401c(iVar12);
        }
        iVar5 = iVar12;
        do {
          if (((((*(char *)(piVar14 + 6) != '\0') &&
                (iVar7 = *(int *)(iVar5 + 0x48) + -1, *(int *)(iVar5 + 0x48) = iVar7, iVar7 == 0))
               && (piVar10 = *(int **)(iVar12 + 0x38), (piVar10[5] & 0x20U) == 0)) &&
              ((piVar10[0x20] != 0 && (iVar7 = FUN_00126760(piVar10[0x26]), iVar7 != 0)))) &&
             (((piVar10[5] & 2U) == 0 &&
              ((iVar7 = (**(code **)(*piVar10 + 0x50))(piVar10), iVar7 == 0 &&
               (iVar7 = FUN_000e07dc(*param_1,0x25), iVar7 != 0)))))) {
            if (param_1[0x58] == 0) {
              if ((int)param_1[0x51] <= *(int *)(*(int *)(iVar12 + 0x38) + 0x94)) {
                ((int (*)())FUN_001659fc)(param_1,iVar12);
              }
            }
            else {
              ((int (*)())FUN_0016c970)(param_1,iVar12);
            }
          }
          iVar5 = iVar5 + 4;
          piVar14 = (int *)((int)piVar14 + 1);
        } while (iVar12 + 0x10 != iVar5);
      }
      if (uVar8 == uVar11) break;
      puVar13 = *(uint **)(param_2 + 0x44);
    }
  }
  iVar5 = FUN_000e07dc(*param_1,0x26);
  if (iVar5 != 0) {
    iVar12 = 1;
    iVar5 = FUN_000e07dc(*param_1,0x25);
    if (iVar5 != 0) {
      for (; iVar5 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar12 <= iVar5; iVar12 = iVar12 + 1) {
        uVar6 = FUN_00105594(piVar9,iVar12);
        while (iVar5 = FUN_00105594(uVar6,0), iVar5 != 0) {
          uVar6 = FUN_00105594(uVar6,0);
        }
        FUN_00106004(piVar9,iVar12,uVar6,0,*param_1);
      }
      goto LAB_0016d0d8;
    }
  }
  if (((piVar9[5] & 0x200U) != 0) &&
     (iVar5 = FUN_00105594(piVar9,piVar9[0x21]), (*(uint *)(iVar5 + 0x14) & 1) == 0)) {
    FUN_00106004(piVar9,piVar9[0x21],0,0,*param_1);
    piVar9[5] = piVar9[5] & 0xfffffdff;
    uVar8 = *(uint *)(iVar5 + 0x14);
    piVar9[0x21] = piVar9[0x21] + -1;
    if ((uVar8 & 0x200) != 0) {
      uVar6 = FUN_00105594(iVar5,*(undefined4 *)(iVar5 + 0x84));
      FUN_00106804(piVar9,uVar6,0,*param_1);
    }
  }
LAB_0016d0d8:
  iVar5 = FUN_000e07dc(*param_1,0x25);
  if ((iVar5 != 0) && (iVar5 = *(int *)(param_2 + 0x60), iVar5 != 0)) {
    iVar12 = *(int *)(iVar5 + 4);
    if (-1 < iVar12) {
      piVar9[0x25] = iVar12;
      piVar9[5] = piVar9[5] | 0x40;
      iVar5 = 0;
      puVar4 = param_1;
      do {
        iVar7 = FUN_001054ec(piVar9,0);
        if (*(char *)(iVar5 + iVar7 + 0x10) != '\x01') {
          *(int *)(puVar4[0x4d] + iVar12 * 4) = param_2;
          if ((puVar4[0x54] != 0) && (*(int *)(*(int *)(param_2 + 0x60) + 0x14) == 0)) {
            *(undefined4 *)(puVar4[0x54] + iVar12 * 4) = 0x7fffffff;
          }
        }
        bVar1 = iVar5 != 3;
        puVar4 = puVar4 + 1;
        iVar5 = iVar5 + 1;
      } while (bVar1);
      iVar5 = *(int *)(param_2 + 0x60);
    }
    if (*(int *)(param_2 + 0x2c) < *(int *)(iVar5 + 0x14)) {
      *(int *)(iVar5 + 0x14) = *(int *)(param_2 + 0x2c);
    }
    iVar5 = 0;
    do {
      iVar12 = FUN_001054ec(piVar9,0);
      if (*(char *)(iVar5 + iVar12 + 0x10) != '\x01') {
        *(int *)(iVar5 * 4 + *(int *)(param_2 + 0x60) + 0x18) = param_2;
      }
      bVar1 = iVar5 != 3;
      iVar5 = iVar5 + 1;
    } while (bVar1);
  }
  piVar14 = *(int **)(param_2 + 0x38);
  if (((((piVar14[5] & 0x20U) == 0) && (piVar14[0x20] != 0)) &&
      (iVar5 = FUN_00126760(piVar14[0x26]), iVar5 != 0)) &&
     (((piVar14[5] & 2U) == 0 && (iVar5 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar5 == 0)))) {
    if ((*(int *)(param_2 + 0x60) == 0) ||
       (iVar5 = *(int *)(*(int *)(param_2 + 0x60) + 8), iVar5 == 0)) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(iVar5 + 0x38);
    }
    iVar12 = FUN_000e07dc(*param_1,0x26);
    if ((iVar12 != 0) && (iVar12 = FUN_000e07dc(*param_1,0x25), iVar12 != 0)) {
      if (iVar5 == 0) {
        if ((*(uint *)(*(int *)(param_2 + 0x38) + 0x14) & 0x200) != 0) {
          FUN_00106004(piVar9,piVar9[0x21],0,0,*param_1);
          piVar9[0x21] = piVar9[0x21] + -1;
          piVar9[5] = piVar9[5] & 0xfffffdff;
        }
      }
      else {
        FUN_00106004(iVar5,0,*(undefined4 *)(param_2 + 0x38),0,*param_1);
        FUN_00106804(piVar9,iVar5,0,*param_1);
      }
    }
    if ((*(int *)(param_2 + 0x60) != 0) &&
       (iVar5 = FUN_001054ec(piVar9,0), *(int *)(iVar5 + 0x10) != DAT_001b0198)) {
      iVar5 = *(int *)(param_2 + 0x60);
      if ((*(int *)(iVar5 + 8) == 0) || (*(int *)(*(int *)(iVar5 + 8) + 0x2c) != param_1[0xb])) {
        iVar12 = FUN_001054ec(*(undefined4 *)(param_2 + 0x38),0);
        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar12 + 0x10);
      }
      else {
        iVar12 = FUN_001054ec(*(undefined4 *)(param_2 + 0x38),0);
        pcVar2 = (char *)(iVar5 + 0xc);
        iVar5 = 0;
        local_48[0] = *(undefined4 *)(iVar12 + 0x10);
        iVar12 = 4;
        do {
          if (*(char *)((int)local_48 + iVar5) != '\x01') {
            *pcVar2 = *(char *)((int)local_48 + iVar5);
          }
          iVar5 = iVar5 + 1;
          pcVar2 = pcVar2 + 1;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
      *(int *)(*(int *)(param_2 + 0x60) + 8) = param_2;
    }
  }
  return;
}

/* FUN_0016d3b0 @ 0x16d3b0 (392 bytes) */
int FUN_0016d3b0(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x38) + 0x5c))(*(int **)(param_2 + 0x38));
  if (iVar1 == 0) {
    (**(code **)(*(int *)param_1[2] + 0x74))((int *)param_1[2],param_2,param_1[0xc]);
  }
  else {
    FUN_00193f64(param_1 + 0x25,param_2);
  }
  iVar1 = param_1[0xb];
  *(int *)(param_2 + 0x2c) = iVar1;
  *(int *)(param_2 + 0x30) = iVar1;
  (**(code **)(*(int *)param_1[2] + 0x10))((int *)param_1[2],*(undefined4 *)(param_2 + 0x38));
  ((int (*)())FUN_0017212c)(param_1[2],param_2);
  (**(code **)(*(int *)param_1[3] + 0x10))((int *)param_1[3],param_2);
  ((int (*)())FUN_0016cdc4)(param_1,param_2);
  iVar1 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0xd4))();
  if ((iVar1 != 0) && ((*(uint *)(*(int *)(param_2 + 0x38) + 0x14) & 0x1000) != 0)) {
    ((int (*)())FUN_0016e1a4)(param_1);
  }
  ((int (*)())FUN_00170bcc)(param_1,param_2);
  iVar1 = (**(code **)(*(int *)param_1[3] + 0x20))
                    ((int *)param_1[3],*(undefined4 *)(param_2 + 0x38));
  if (((iVar1 != 0) ||
      (iVar1 = (**(code **)(*(int *)param_1[3] + 0x24))
                         ((int *)param_1[3],*(undefined4 *)(param_2 + 0x38)), iVar1 != 0)) &&
     (param_1[0x4a] <= *(int *)(param_2 + 0xc))) {
    param_1[0x4b] = param_1[0x4b] + 1;
  }
  return;
}

/* FUN_0016d538 @ 0x16d538 (1996 bytes) */
int FUN_0016d538(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  uint *puVar15;
  undefined4 local_58 [8];
  
  FUN_001045e4(*(undefined4 *)(param_2 + 0x38));
  if (param_1[0x61] < 0) {
    if (*(int *)(*(int *)(param_2 + 0x38) + 0x98) == 0x3a) {
      param_1[0x61] = 1;
    }
    else {
      param_1[0x61] = *(int *)(*(int *)(*param_1 + 0x30c) + 0x1c);
    }
  }
  iVar10 = *(int *)(param_2 + 0x38);
  iVar12 = 0;
  iVar3 = FUN_001054ec(iVar10,1);
  FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
  do {
    iVar3 = FUN_001054ec(iVar10,0);
    if (*(char *)(iVar12 + iVar3 + 0x10) != '\x01') {
      iVar3 = FUN_001054ec(iVar10,1);
      uVar7 = (uint)*(byte *)(iVar12 + iVar3 + 0x10);
      goto LAB_0016d5f8;
    }
    bVar1 = iVar12 != 3;
    iVar12 = iVar12 + 1;
  } while (bVar1);
  uVar7 = 4;
LAB_0016d5f8:
  iVar3 = param_1[0x61];
  if (0 < iVar3) {
    uVar11 = 0;
    piVar5 = param_1;
    do {
      if (piVar5[0x5c] != 0) {
        iVar3 = FUN_00105594(*(undefined4 *)(piVar5[0x5c] + 0x38),1);
        iVar12 = FUN_00105594(iVar10,1);
        if (iVar3 == iVar12) {
          iVar12 = piVar5[0x5c];
          iVar13 = *(int *)(iVar12 + 0x38);
          iVar8 = uVar11 + (((int)uVar11 >> 2) + (uint)((int)uVar11 < 0 && (uVar11 & 3) != 0)) * -4;
          iVar3 = FUN_001054ec(iVar13,1);
          if ((uVar7 == *(byte *)(iVar8 + iVar3 + 0x10)) &&
             (iVar3 = (**(code **)(**(int **)(iVar13 + 0x88) + 0x18))(),
             iVar3 == *(int *)(iVar10 + 300))) {
            FUN_00106004(iVar10,1,iVar13,0,*param_1);
            uVar14 = *(undefined4 *)(PTR_DAT_001e8b8c + iVar8 * 4);
            iVar3 = FUN_001054ec(iVar10,1);
            *(undefined4 *)(iVar3 + 0x10) = uVar14;
            if (*(int *)(iVar12 + 0x6c) != 0) {
              *(int *)(param_2 + 0x6c) = *(int *)(iVar12 + 0x6c);
            }
            puVar15 = *(uint **)(param_2 + 0x40);
            uVar11 = 0;
            *(int *)(iVar12 + 0x6c) = param_2;
            uVar7 = puVar15[1];
            if ((int)uVar7 < 1) {
              return 1;
            }
            while( true ) {
              if (uVar11 < *puVar15) {
                uVar4 = puVar15[1];
                if (uVar4 <= uVar11) {
                  _memset((void *)(uVar4 * 4 + puVar15[2]),0,(uVar11 - uVar4) * 4 + 4);
                  puVar15[1] = uVar11 + 1;
                }
                piVar5 = (int *)(uVar11 * 4 + puVar15[2]);
              }
              else {
                piVar5 = (int *)FUN_0019423c(puVar15,uVar11);
              }
              uVar11 = uVar11 + 1;
              iVar3 = *piVar5;
              iVar10 = *(int *)(iVar3 + 4);
              if (*(int *)(iVar3 + 8) == 0) {
                local_58[0] = 0;
                *(undefined1 *)((int)local_58 + iVar8) = 1;
                ((int (*)())FUN_00165b7c)(param_1,iVar12,iVar10,*(undefined4 *)(iVar3 + 0x10),
                             *(undefined4 *)(iVar3 + 0x14),local_58[0]);
                *(int *)(iVar10 + 0x34) = *(int *)(iVar10 + 0x34) + -1;
              }
              if (uVar7 == uVar11) break;
              puVar15 = *(uint **)(param_2 + 0x40);
            }
            return 1;
          }
        }
        iVar3 = param_1[0x61];
      }
      uVar11 = uVar11 + 1;
      piVar5 = piVar5 + 1;
    } while ((int)uVar11 < iVar3);
    if (0 < iVar3) {
      iVar12 = param_1[0x5c];
      if (iVar12 == 0) {
        uVar9 = 0;
        iVar3 = 0;
      }
      else {
        uVar4 = 0;
        uVar11 = 0xffffffff;
        piVar5 = param_1;
        do {
          if ((*(int *)((uVar4 + (((int)uVar4 >> 2) + (uint)((int)uVar4 < 0 && (uVar4 & 3) != 0)) *
                                 -4) * 4 + iVar12 + 0x48) == 0) &&
             (((int)uVar11 < 0 ||
              (*(int *)(iVar12 + 0x2c) < *(int *)(param_1[uVar11 + 0x5c] + 0x2c))))) {
            uVar11 = uVar4;
          }
          uVar4 = uVar4 + 1;
          iVar3 = iVar3 + -1;
          uVar9 = uVar11;
          if (iVar3 == 0) break;
          iVar12 = piVar5[0x5d];
          piVar5 = piVar5 + 1;
          uVar9 = uVar4;
        } while (iVar12 != 0);
        if ((int)uVar9 < 0) {
          return 0;
        }
        iVar3 = uVar9 + (((int)uVar9 >> 2) + (uint)((int)uVar9 < 0 && (uVar9 & 3) != 0)) * -4;
      }
      uVar4 = uVar9 - iVar3;
      uVar11 = uVar4 + 4;
      piVar5 = param_1 + uVar4 + 0x5c;
      do {
        if ((((*(uint *)(*(int *)(*param_1 + 0x30c) + 8) & 0x200) == 0) && (*piVar5 != 0)) &&
           (uVar4 != uVar9)) {
          iVar12 = FUN_00105594(*(undefined4 *)(*piVar5 + 0x38),1);
          iVar8 = FUN_00105594(iVar10,1);
          if (iVar12 == iVar8) {
            iVar12 = *piVar5;
            piVar6 = *(int **)(iVar12 + 0x38);
            if (*(int *)(iVar10 + 300) == 0) {
              if (*(int *)(piVar6[0x22] + 8) == 0xa6) goto LAB_0016d91c;
            }
            else if (*(int *)(piVar6[0x22] + 8) == 0x2b) {
LAB_0016d91c:
              if ((param_1[uVar9 + 0x5c] == 0) ||
                 (iVar8 = ((int (*)())FUN_00167a74)(param_1[uVar9 + 0x5c],iVar3), iVar8 < *(int *)(iVar12 + 0x2c)
                 )) {
                *(undefined1 *)((int)piVar6 + iVar3 + 0x9c) = 0;
                (**(code **)(*piVar6 + 0x88))(piVar6,1,iVar3,uVar7);
                *(undefined1 *)((int)piVar6 + iVar3 + 0xc) = 1;
                iVar8 = *param_1;
                param_1[uVar9 + 0x5c] = iVar12;
                FUN_00106004(iVar10,1,piVar6,0,iVar8);
                uVar14 = *(undefined4 *)(PTR_DAT_001e8b8c + iVar3 * 4);
                iVar10 = FUN_001054ec(iVar10,1);
                *(undefined4 *)(iVar10 + 0x10) = uVar14;
                if (*(int *)(iVar12 + 0x6c) != 0) {
                  *(int *)(param_2 + 0x6c) = *(int *)(iVar12 + 0x6c);
                }
                puVar15 = *(uint **)(param_2 + 0x40);
                uVar11 = 0;
                *(int *)(iVar12 + 0x6c) = param_2;
                uVar7 = puVar15[1];
                if ((int)uVar7 < 1) {
                  return 1;
                }
                while( true ) {
                  if (uVar11 < *puVar15) {
                    uVar4 = puVar15[1];
                    if (uVar4 <= uVar11) {
                      _memset((void *)(uVar4 * 4 + puVar15[2]),0,(uVar11 - uVar4) * 4 + 4);
                      puVar15[1] = uVar11 + 1;
                    }
                    piVar5 = (int *)(uVar11 * 4 + puVar15[2]);
                  }
                  else {
                    piVar5 = (int *)FUN_0019423c(puVar15,uVar11);
                  }
                  uVar11 = uVar11 + 1;
                  iVar10 = *piVar5;
                  iVar8 = *(int *)(iVar10 + 4);
                  if (*(int *)(iVar10 + 8) == 0) {
                    local_58[0] = 0;
                    *(undefined1 *)((int)local_58 + iVar3) = 1;
                    ((int (*)())FUN_00165b7c)(param_1,iVar12,iVar8,*(undefined4 *)(iVar10 + 0x10),
                                 *(undefined4 *)(iVar10 + 0x14),local_58[0]);
                    *(int *)(iVar8 + 0x34) = *(int *)(iVar8 + 0x34) + -1;
                  }
                  if (uVar7 == uVar11) break;
                  puVar15 = *(uint **)(param_2 + 0x40);
                }
                return 1;
              }
            }
          }
        }
        uVar4 = uVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (uVar11 != uVar4);
      iVar12 = (**(code **)(*(int *)param_1[2] + 0x80))
                         ((int *)param_1[2],param_1[0x60],*(undefined4 *)(iVar10 + 300),
                          *(undefined4 *)(iVar10 + 0x130),*(int *)(iVar10 + 0x98) == 0x3a);
      puVar2 = PTR_DAT_001e8b64;
      param_1[0x60] = iVar12;
      *(undefined4 *)(iVar12 + 0x98) = 0x20;
      *(uint *)(iVar12 + 0x94) = ((int)uVar9 >> 2) + (uint)((int)uVar9 < 0 && (uVar9 & 3) != 0);
      *(undefined4 *)(param_1[0x60] + 0x9c) = *(undefined4 *)(puVar2 + iVar3 * 4);
      iVar12 = param_1[0x60];
      uVar14 = FUN_00105594(iVar10,1);
      FUN_00106004(iVar12,1,uVar14,0,*param_1);
      puVar2 = PTR_DAT_001e8b8c;
      uVar14 = *(undefined4 *)(PTR_DAT_001e8b8c + uVar7 * 4);
      iVar12 = FUN_001054ec(param_1[0x60],1);
      *(undefined4 *)(iVar12 + 0x10) = uVar14;
      *(undefined4 *)(param_1[0x60] + 0xc) = 0;
      *(undefined1 *)(param_1[0x60] + iVar3 + 0xc) = 1;
      iVar12 = (**(code **)(*(int *)param_1[2] + 0xc))((int *)param_1[2],param_1[0x60]);
      if (iVar12 != 0) {
        iVar12 = ((int (*)())FUN_00165d3c)(param_1,param_1[0x60],param_2 + 0xc,param_1[0xb]);
        param_1[0x60] = 0;
        param_1[uVar9 + 0x5c] = iVar12;
        FUN_00106004(iVar10,1,*(undefined4 *)(iVar12 + 0x38),0,*param_1);
        uVar14 = *(undefined4 *)(puVar2 + iVar3 * 4);
        iVar10 = FUN_001054ec(iVar10,1);
        *(undefined4 *)(iVar10 + 0x10) = uVar14;
        uVar11 = 0;
        puVar15 = *(uint **)(param_2 + 0x40);
        *(int *)(iVar12 + 0x6c) = param_2;
        uVar7 = puVar15[1];
        if (0 < (int)uVar7) {
          while( true ) {
            if (uVar11 < *puVar15) {
              uVar4 = puVar15[1];
              if (uVar4 <= uVar11) {
                _memset((void *)(uVar4 * 4 + puVar15[2]),0,(uVar11 - uVar4) * 4 + 4);
                puVar15[1] = uVar11 + 1;
              }
              piVar5 = (int *)(uVar11 * 4 + puVar15[2]);
            }
            else {
              piVar5 = (int *)FUN_0019423c(puVar15,uVar11);
            }
            uVar11 = uVar11 + 1;
            iVar10 = *piVar5;
            uVar14 = *(undefined4 *)(iVar10 + 4);
            if (*(int *)(iVar10 + 8) == 0) {
              local_58[0] = 0;
              *(undefined1 *)((int)local_58 + iVar3) = 1;
              ((int (*)())FUN_00165b7c)(param_1,iVar12,uVar14,*(undefined4 *)(iVar10 + 0x10),
                           *(undefined4 *)(iVar10 + 0x14),local_58[0]);
            }
            if (uVar7 == uVar11) break;
            puVar15 = *(uint **)(param_2 + 0x40);
          }
        }
        ((int (*)())FUN_0016d3b0)(param_1,iVar12);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0016dd04 @ 0x16dd04 (616 bytes) */
int FUN_0016dd04(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined4 uVar14;
  code *pcVar15;
  int iVar16;
  
  iVar9 = 0;
  uVar7 = *(undefined4 *)(param_2 + 0x38);
  FUN_00104644(uVar7);
  piVar2 = param_1;
  piVar11 = param_1;
  do {
    if (piVar11[0x62] != 0) {
      iVar16 = *(int *)(piVar11[0x62] + 0x38);
      iVar13 = *(int *)(iVar16 + 0x130);
      iVar10 = *(int *)(iVar16 + 0x134);
      iVar8 = *(int *)(iVar16 + 300);
      iVar3 = FUN_00105c5c(uVar7,0);
      iVar4 = FUN_00105594(uVar7,1);
      if (iVar13 == *(int *)(iVar4 + 0x94)) {
        if ((iVar10 <= iVar3) && (iVar3 < iVar10 + iVar8)) goto LAB_0016ddd8;
        if (iVar8 == 0x10) {
          if ((iVar10 <= iVar3) && (iVar3 < iVar10 + 0x20)) {
            *(undefined4 *)(iVar16 + 300) = 0x20;
LAB_0016ddd8:
            FUN_00106004(uVar7,1,iVar16,0,*param_1);
            *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(piVar2[0x62] + 0x6c);
            *(int *)(piVar2[0x62] + 0x6c) = param_2;
            return 1;
          }
          if ((iVar10 + -0x10 <= iVar3) && (iVar3 < iVar10 + 0x10)) {
            *(undefined4 *)(iVar16 + 300) = 0x20;
            *(int *)(iVar16 + 0x134) = iVar10 + -0x10;
            goto LAB_0016ddd8;
          }
        }
      }
    }
    bVar1 = iVar9 == 1;
    piVar2 = piVar2 + 1;
    piVar11 = piVar11 + 1;
    iVar9 = iVar9 + 1;
    if (bVar1) {
      iVar9 = 0;
      piVar2 = param_1;
      do {
        if (piVar2[0x62] == 0) {
          if (iVar9 < 0) {
            return 0;
          }
          uVar14 = *(undefined4 *)(*param_1 + 0x374);
          puVar5 = (undefined4 *)FUN_00193e18(uVar14,0x168);
          *puVar5 = uVar14;
          puVar12 = puVar5 + 1;
          FUN_00109a80(puVar12,0xfa,*param_1);
          uVar6 = FUN_00105c5c(uVar7,0);
          puVar5[0x27] = 0x45;
          puVar5[0x26] = iVar9;
          iVar3 = FUN_00105594(uVar7,1);
          uVar14 = DAT_001b0194;
          puVar5[0x4d] = *(undefined4 *)(iVar3 + 0x94);
          puVar5[0x4c] = 0x10;
          puVar5[0x4e] = (((int)uVar6 >> 4) + (uint)((int)uVar6 < 0 && (uVar6 & 0xf) != 0)) * 0x10;
          puVar5[4] = uVar14;
          pcVar15 = *(code **)(puVar5[1] + 0x94);
          uVar14 = FUN_00105594(uVar7,1);
          (*pcVar15)(puVar12,uVar14,*param_1);
          iVar3 = ((int (*)())FUN_00165d3c)(param_1,puVar12,param_2 + 0xc,param_1[0xb]);
          iVar4 = *param_1;
          param_1[iVar9 + 0x62] = iVar3;
          FUN_00106004(uVar7,1,puVar12,0,iVar4);
          *(int *)(iVar3 + 0x6c) = param_2;
          ((int (*)())FUN_0016d3b0)(param_1,iVar3);
          return 1;
        }
        bVar1 = iVar9 != 1;
        piVar2 = piVar2 + 1;
        iVar9 = iVar9 + 1;
      } while (bVar1);
      return 0;
    }
  } while( true );
}

/* FUN_0016df8c @ 0x16df8c (536 bytes) */
int FUN_0016df8c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  ((int (*)())FUN_00166ba8)();
  iVar2 = param_1 + 0xf8;
  if (*(int *)(param_2 + 0x68) == 0) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))
                      (*(int **)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38));
    if ((iVar2 == 0) &&
       (iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))
                          (*(int **)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38)), iVar2 == 0)) {
      if (((*(int *)(param_2 + 0x58) == 0) &&
          (iVar2 = FUN_001045e4(*(undefined4 *)(param_2 + 0x38)), iVar2 == 0)) &&
         (iVar2 = FUN_00104644(*(undefined4 *)(param_2 + 0x38)), iVar2 == 0)) {
        ((int (*)())FUN_0016d3b0)(param_1,param_2);
        return;
      }
      piVar4 = *(int **)(param_2 + 0x38);
      if ((((piVar4[5] & 0x20U) == 0) && (piVar4[0x20] != 0)) &&
         ((iVar2 = FUN_00126760(piVar4[0x26]), iVar2 != 0 &&
          (((piVar4[5] & 2U) == 0 && (iVar2 = (**(code **)(*piVar4 + 0x50))(piVar4), iVar2 == 0)))))
         ) {
        iVar3 = 4;
        iVar2 = param_2;
        while (*(int *)(iVar2 + 0x48) < 1) {
          iVar2 = iVar2 + 4;
          iVar3 = iVar3 + -1;
          if (iVar3 == 0) {
            ((int (*)())FUN_00170da0)(param_1,param_2);
            return;
          }
        }
      }
      iVar2 = param_1 + 0x4c;
      iVar3 = *(int *)(param_1 + 0x54);
      iVar1 = *(int *)(iVar3 + 8);
      while (iVar1 != 0) {
        iVar1 = ((int (*)())FUN_001648ac)(param_1,param_2,iVar3,0);
        if (0 < iVar1) {
LAB_0016e148:
          FUN_00193f44(param_2,iVar3);
          return;
        }
        iVar3 = *(int *)(iVar3 + 8);
        iVar1 = *(int *)(iVar3 + 8);
      }
    }
    else {
      iVar2 = param_1 + 0x34;
      iVar3 = *(int *)(param_1 + 0x3c);
      iVar1 = *(int *)(iVar3 + 8);
      while (iVar1 != 0) {
        iVar1 = ((int (*)())FUN_001648ac)(param_1,param_2,iVar3,0);
        if (0 < iVar1) goto LAB_0016e148;
        iVar3 = *(int *)(iVar3 + 8);
        iVar1 = *(int *)(iVar3 + 8);
      }
    }
  }
  FUN_00193f64(iVar2,param_2);
  return;
}

/* FUN_0016e1a4 @ 0x16e1a4 (1668 bytes) */
int FUN_0016e1a4(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  
  iVar9 = param_1[0x61];
  if (0 < iVar9) {
    uVar11 = 0;
    puVar13 = param_1;
    do {
      iVar14 = puVar13[0x5c];
      iVar10 = uVar11 + (((int)uVar11 >> 2) + (uint)((int)uVar11 < 0 && (uVar11 & 3) != 0)) * -4;
      if ((iVar14 != 0) && (*(int *)(iVar14 + 0x2c) < (int)param_1[0xb])) {
        iVar22 = iVar10 * 4;
        puVar13[0x5c] = 0;
        puVar1 = PTR_DAT_001eb254;
        if ((0 < *(int *)(iVar22 + iVar14 + 0x48)) &&
           (iVar16 = *(int *)(iVar14 + 0x6c), iVar16 != 0)) {
          do {
            iVar9 = FUN_001054ec(*(undefined4 *)(iVar16 + 0x38),1);
            if (*(int *)(iVar9 + 0x10) == *(int *)(puVar1 + iVar22)) {
              iVar20 = 4;
              iVar9 = iVar16;
LAB_0016e258:
              if (*(int *)(iVar9 + 0x48) < 1) goto code_r0x0016e264;
              uVar5 = FUN_0010445c(*(undefined4 *)(iVar16 + 0x38),*param_1,0);
              uVar6 = FUN_00105594(*(undefined4 *)(iVar14 + 0x38),1);
              FUN_00106004(uVar5,1,uVar6,0,*param_1);
              iVar9 = FUN_001054ec(*(undefined4 *)(iVar14 + 0x38),1);
              uVar6 = *(undefined4 *)(puVar1 + (uint)*(byte *)(iVar10 + iVar9 + 0x10) * 4);
              iVar9 = FUN_001054ec(uVar5,1);
              *(undefined4 *)(iVar9 + 0x10) = uVar6;
              uVar7 = 0;
              iVar9 = ((int (*)())FUN_00165d3c)(param_1,uVar5,iVar16 + 0xc,param_1[0xb]);
              puVar18 = *(uint **)(iVar16 + 0x40);
              uVar19 = puVar18[1];
              if (0 < (int)uVar19) {
                while( true ) {
                  if (uVar7 < *puVar18) {
                    uVar2 = puVar18[1];
                    if (uVar2 <= uVar7) {
                      _memset((void *)(uVar2 * 4 + puVar18[2]),0,(uVar7 - uVar2) * 4 + 4);
                      puVar18[1] = uVar7 + 1;
                    }
                    puVar8 = (undefined4 *)(uVar7 * 4 + puVar18[2]);
                  }
                  else {
                    puVar8 = (undefined4 *)FUN_0019423c(puVar18,uVar7);
                  }
                  uVar7 = uVar7 + 1;
                  piVar15 = (int *)*puVar8;
                  iVar23 = 1;
                  iVar20 = piVar15[1];
                  if (*(int *)(iVar20 + 0x2c) < 0) {
                    for (; iVar3 = (**(code **)(**(int **)(iVar20 + 0x38) + 0x14))(),
                        iVar23 <= iVar3; iVar23 = iVar23 + 1) {
                      iVar3 = FUN_00105594(*(undefined4 *)(iVar20 + 0x38),iVar23);
                      if (iVar3 == *(int *)(iVar16 + 0x38)) {
                        FUN_00106004(*(undefined4 *)(iVar20 + 0x38),iVar23,uVar5,0,*param_1);
                      }
                    }
                    *piVar15 = iVar9;
                    puVar18 = *(uint **)(iVar9 + 0x40);
                    uVar2 = puVar18[1];
                    if (uVar2 < *puVar18) {
                      _memset((void *)(uVar2 * 4 + puVar18[2]),0,4);
                      puVar8 = (undefined4 *)(uVar2 * 4 + puVar18[2]);
                      puVar18[1] = uVar2 + 1;
                    }
                    else {
                      puVar8 = (undefined4 *)FUN_0019423c(puVar18,uVar2);
                    }
                    *puVar8 = piVar15;
                    iVar21 = 4;
                    iVar23 = iVar9;
                    iVar3 = iVar16;
                    do {
                      if (*(char *)(piVar15 + 6) != '\0') {
                        *(int *)(iVar23 + 0x48) = *(int *)(iVar23 + 0x48) + 1;
                        *(int *)(iVar3 + 0x48) = *(int *)(iVar3 + 0x48) + -1;
                      }
                      piVar15 = (int *)((int)piVar15 + 1);
                      iVar23 = iVar23 + 4;
                      iVar3 = iVar3 + 4;
                      iVar21 = iVar21 + -1;
                    } while (iVar21 != 0);
                    puVar18 = *(uint **)(iVar20 + 0x44);
                    uVar2 = puVar18[1];
                    uVar17 = uVar2 - 1;
                    if (-1 < (int)uVar17) {
                      iVar23 = uVar17 * 4;
                      uVar12 = 0;
                      while( true ) {
                        if (uVar17 < *puVar18) {
                          uVar4 = puVar18[1];
                          if (uVar4 <= uVar17) {
                            _memset((void *)(uVar4 * 4 + puVar18[2]),0,(uVar17 - uVar4) * 4 + 4);
                            puVar18[1] = uVar17 + 1;
                          }
                          puVar8 = (undefined4 *)(iVar23 + puVar18[2]);
                        }
                        else {
                          puVar8 = (undefined4 *)FUN_0019423c(puVar18,uVar17);
                        }
                        if ((iVar14 == *(int *)*puVar8) &&
                           (*(char *)((int)*puVar8 + iVar10 + 0x18) != '\0')) {
                          FUN_00194208(*(undefined4 *)(iVar20 + 0x44),uVar17);
                          *(int *)(iVar22 + iVar14 + 0x48) = *(int *)(iVar22 + iVar14 + 0x48) + -1;
                        }
                        uVar12 = uVar12 + 1;
                        uVar17 = uVar17 - 1;
                        iVar23 = iVar23 + -4;
                        if (uVar2 == uVar12) break;
                        puVar18 = *(uint **)(iVar20 + 0x44);
                      }
                    }
                    iVar23 = *(int *)(iVar20 + 0x34);
                    if (iVar23 == 0) {
                      FUN_0019401c(iVar20);
                      iVar23 = *(int *)(iVar20 + 0x34);
                    }
                    *(int *)(iVar20 + 0x34) = iVar23 + 1;
                  }
                  if (uVar19 == uVar7) break;
                  puVar18 = *(uint **)(iVar16 + 0x40);
                }
              }
              ((int (*)())FUN_0016df8c)(param_1,iVar9);
            }
LAB_0016e574:
            iVar16 = *(int *)(iVar16 + 0x6c);
          } while (iVar16 != 0);
          iVar9 = param_1[0x61];
        }
      }
      uVar11 = uVar11 + 1;
      puVar13 = puVar13 + 1;
    } while ((int)uVar11 < iVar9);
  }
  puVar13 = param_1;
  do {
    iVar9 = puVar13[0x62];
    if ((iVar9 != 0) && (*(int *)(iVar9 + 0x2c) < (int)param_1[0xb])) {
      puVar13[0x62] = 0;
      for (iVar10 = *(int *)(iVar9 + 0x6c); iVar10 != 0; iVar10 = *(int *)(iVar10 + 0x6c)) {
        iVar22 = 4;
        iVar14 = iVar10;
        while (*(int *)(iVar14 + 0x48) < 1) {
          iVar14 = iVar14 + 4;
          iVar22 = iVar22 + -1;
          if (iVar22 == 0) goto LAB_0016e800;
        }
        uVar5 = FUN_0010445c(*(undefined4 *)(iVar10 + 0x38),*param_1,0);
        uVar6 = FUN_00105594(*(undefined4 *)(iVar9 + 0x38),1);
        FUN_00106004(uVar5,1,uVar6,0,*param_1);
        iVar14 = ((int (*)())FUN_00165d3c)(param_1,uVar5,iVar10 + 0xc,param_1[0xb]);
        puVar18 = *(uint **)(iVar10 + 0x40);
        uVar19 = 0;
        uVar11 = puVar18[1];
        if (0 < (int)uVar11) {
          while( true ) {
            if (uVar19 < *puVar18) {
              uVar7 = puVar18[1];
              if (uVar7 <= uVar19) {
                _memset((void *)(uVar7 * 4 + puVar18[2]),0,(uVar19 - uVar7) * 4 + 4);
                puVar18[1] = uVar19 + 1;
              }
              puVar8 = (undefined4 *)(uVar19 * 4 + puVar18[2]);
            }
            else {
              puVar8 = (undefined4 *)FUN_0019423c(puVar18,uVar19);
            }
            uVar19 = uVar19 + 1;
            piVar15 = (int *)*puVar8;
            iVar16 = 1;
            iVar22 = piVar15[1];
            if (*(int *)(iVar22 + 0x2c) < 0) {
              for (; iVar20 = (**(code **)(**(int **)(iVar22 + 0x38) + 0x14))(), iVar16 <= iVar20;
                  iVar16 = iVar16 + 1) {
                iVar20 = FUN_00105594(*(undefined4 *)(iVar22 + 0x38),iVar16);
                if (iVar20 == *(int *)(iVar10 + 0x38)) {
                  FUN_00106004(*(undefined4 *)(iVar22 + 0x38),iVar16,uVar5,0,*param_1);
                }
              }
              *piVar15 = iVar14;
              puVar18 = *(uint **)(iVar14 + 0x40);
              uVar7 = puVar18[1];
              if (uVar7 < *puVar18) {
                _memset((void *)(uVar7 * 4 + puVar18[2]),0,4);
                puVar8 = (undefined4 *)(uVar7 * 4 + puVar18[2]);
                puVar18[1] = uVar7 + 1;
              }
              else {
                puVar8 = (undefined4 *)FUN_0019423c(puVar18,uVar7);
              }
              *puVar8 = piVar15;
              iVar23 = 4;
              iVar16 = iVar14;
              iVar20 = iVar10;
              do {
                if (*(char *)(piVar15 + 6) != '\0') {
                  *(int *)(iVar16 + 0x48) = *(int *)(iVar16 + 0x48) + 1;
                  *(int *)(iVar20 + 0x48) = *(int *)(iVar20 + 0x48) + -1;
                }
                piVar15 = (int *)((int)piVar15 + 1);
                iVar16 = iVar16 + 4;
                iVar20 = iVar20 + 4;
                iVar23 = iVar23 + -1;
              } while (iVar23 != 0);
              iVar16 = *(int *)(iVar22 + 0x34);
              if (iVar16 == 0) {
                FUN_0019401c(iVar22);
                iVar16 = *(int *)(iVar22 + 0x34);
              }
              *(int *)(iVar22 + 0x34) = iVar16 + 1;
            }
            if (uVar11 == uVar19) break;
            puVar18 = *(uint **)(iVar10 + 0x40);
          }
        }
        ((int (*)())FUN_0016df8c)(param_1,iVar14);
LAB_0016e800: ;
      }
    }
    puVar13 = puVar13 + 1;
    if (param_1 + 2 == puVar13) {
      return;
    }
  } while( true );
code_r0x0016e264:
  iVar9 = iVar9 + 4;
  iVar20 = iVar20 + -1;
  if (iVar20 == 0) goto LAB_0016e574;
  goto LAB_0016e258;
}

/* FUN_0016e828 @ 0x16e828 (1640 bytes) */
int FUN_0016e828(param_1)
  int *param_1;
{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar7 = param_1[0xb];
  (**(code **)(*(int *)param_1[3] + 0x14))((int *)param_1[3],param_1[0xc]);
  (**(code **)(*(int *)param_1[2] + 0x14))();
  puVar4 = (undefined4 *)param_1[0xc];
  iVar10 = 5;
  param_1[0xb] = param_1[0xb] + 1;
  puVar3 = puVar4;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  FUN_00193fa4(puVar4 + 5);
  iVar10 = param_1[0x15];
  for (iVar9 = *(int *)(param_1[0x15] + 8); iVar9 != 0; iVar9 = *(int *)(iVar9 + 8)) {
    FUN_0019401c(iVar10);
    FUN_00193f64(param_1 + 0x1f,iVar10);
    iVar10 = iVar9;
  }
  iVar10 = param_1[0xf];
  for (iVar9 = *(int *)(param_1[0xf] + 8); iVar9 != 0; iVar9 = *(int *)(iVar9 + 8)) {
    FUN_0019401c(iVar10);
    FUN_00193f64(param_1 + 0x1f,iVar10);
    iVar10 = iVar9;
  }
  param_1[0x44] = 0;
  param_1[0x48] = -1;
  param_1[0x47] = -1;
  iVar10 = param_1[0x21];
  if (*(int *)(iVar10 + 8) == 0) {
    iVar8 = -1;
    iVar9 = -1;
  }
  else {
    iVar8 = -1;
    iVar9 = -1;
    do {
      if (param_1[0x44] < *(int *)(iVar10 + 0x14)) {
        param_1[0x44] = *(int *)(iVar10 + 0x14);
      }
      iVar5 = (**(code **)(*(int *)param_1[3] + 0x20))
                        ((int *)param_1[3],*(undefined4 *)(iVar10 + 0x38));
      if ((iVar5 == 0) &&
         (iVar5 = (**(code **)(*(int *)param_1[3] + 0x24))
                            ((int *)param_1[3],*(undefined4 *)(iVar10 + 0x38)), iVar5 == 0)) {
        iVar5 = *(int *)(iVar10 + 0xc);
        if (*(int *)(iVar10 + 0xc) < param_1[0x47]) {
          iVar5 = param_1[0x47];
        }
        iVar9 = param_1[0xb];
        param_1[0x47] = iVar5;
      }
      else {
        iVar5 = *(int *)(iVar10 + 0xc);
        if (*(int *)(iVar10 + 0xc) < param_1[0x48]) {
          iVar5 = param_1[0x48];
        }
        iVar8 = param_1[0xb];
        param_1[0x48] = iVar5;
      }
      iVar10 = *(int *)(iVar10 + 8);
    } while (*(int *)(iVar10 + 8) != 0);
  }
  iVar10 = param_1[0x1b];
  if (*(int *)(iVar10 + 8) == 0) {
    bVar1 = iVar8 < 0;
    bVar2 = iVar9 < 0;
  }
  else {
    bVar1 = iVar8 < 0;
    bVar2 = iVar9 < 0;
    do {
      if (param_1[0x44] < *(int *)(iVar10 + 0x14)) {
        param_1[0x44] = *(int *)(iVar10 + 0x14);
      }
      iVar5 = (**(code **)(*(int *)param_1[3] + 0x20))
                        ((int *)param_1[3],*(undefined4 *)(iVar10 + 0x38));
      if ((iVar5 == 0) &&
         (iVar5 = (**(code **)(*(int *)param_1[3] + 0x24))
                            ((int *)param_1[3],*(undefined4 *)(iVar10 + 0x38)), iVar5 == 0)) {
        iVar5 = *(int *)(iVar10 + 0xc);
        if (*(int *)(iVar10 + 0xc) < param_1[0x47]) {
          iVar5 = param_1[0x47];
        }
        param_1[0x47] = iVar5;
        if (bVar2) {
          iVar5 = *(int *)(iVar10 + 0x30);
        }
        else {
          iVar5 = *(int *)(iVar10 + 0x30);
          if (iVar9 <= iVar5) goto LAB_0016eb08;
        }
        bVar2 = iVar5 < 0;
        iVar9 = iVar5;
      }
      else {
        iVar5 = *(int *)(iVar10 + 0xc);
        if (*(int *)(iVar10 + 0xc) < param_1[0x48]) {
          iVar5 = param_1[0x48];
        }
        param_1[0x48] = iVar5;
        if (bVar1) {
          iVar5 = *(int *)(iVar10 + 0x30);
        }
        else {
          iVar5 = *(int *)(iVar10 + 0x30);
          if (iVar8 <= iVar5) goto LAB_0016eb08;
        }
        bVar1 = iVar5 < 0;
        iVar8 = iVar5;
      }
LAB_0016eb08:
      iVar10 = *(int *)(iVar10 + 8);
    } while (*(int *)(iVar10 + 8) != 0);
  }
  iVar10 = param_1[0x40];
  iVar5 = *(int *)(iVar10 + 8);
  while (iVar5 != 0) {
    if (param_1[0x44] < *(int *)(iVar10 + 0x14)) {
      param_1[0x44] = *(int *)(iVar10 + 0x14);
    }
    iVar5 = *(int *)(iVar10 + 0xc);
    if (*(int *)(iVar10 + 0xc) < param_1[0x47]) {
      iVar5 = param_1[0x47];
    }
    param_1[0x47] = iVar5;
    if (bVar2) {
      iVar5 = *(int *)(iVar10 + 0x30);
LAB_0016eb7c:
      bVar2 = iVar5 < 0;
      iVar9 = iVar5;
    }
    else {
      iVar5 = *(int *)(iVar10 + 0x30);
      bVar2 = false;
      if (iVar5 < iVar9) goto LAB_0016eb7c;
    }
    iVar10 = *(int *)(iVar10 + 8);
    iVar5 = *(int *)(iVar10 + 8);
  }
  iVar10 = (**(code **)(*(int *)param_1[2] + 0x5c))();
  param_1[0x45] = iVar10;
  param_1[9] = (uint)(param_1[0x44] <= iVar10);
  if (bVar2) {
    if (bVar1) goto LAB_0016ec14;
  }
  else if (((bVar1) || (param_1[0x46] == 0)) || (iVar9 <= iVar8)) {
    if (iVar9 <= param_1[0xb]) {
      iVar9 = param_1[0xb];
    }
    param_1[0xb] = iVar9;
    goto LAB_0016ec14;
  }
  if (iVar8 <= param_1[0xb]) {
    iVar8 = param_1[0xb];
  }
  param_1[0xb] = iVar8;
LAB_0016ec14:
  iVar10 = *(int *)(param_1[0x21] + 8);
  if (iVar10 == 0) {
    iVar9 = 0;
    iVar8 = 0;
  }
  else {
    iVar9 = 0;
    iVar8 = 0;
    iVar5 = param_1[0x21];
    do {
      iVar6 = iVar10;
      FUN_0019401c(iVar5);
      ((int (*)())FUN_0016df8c)(param_1,iVar5);
      iVar10 = (**(code **)(*(int *)param_1[3] + 0x20))
                         ((int *)param_1[3],*(undefined4 *)(iVar5 + 0x38));
      if ((iVar10 != 0) ||
         (iVar10 = (**(code **)(*(int *)param_1[3] + 0x24))
                             ((int *)param_1[3],*(undefined4 *)(iVar5 + 0x38)), iVar10 != 0)) {
        if (iVar8 < *(int *)(iVar5 + 0x14)) {
          iVar8 = *(int *)(iVar5 + 0x14);
        }
        if (*(int *)(iVar5 + 0xc) == param_1[0x48]) {
          iVar9 = iVar9 + 1;
        }
      }
      iVar10 = *(int *)(iVar6 + 8);
      iVar5 = iVar6;
    } while (iVar10 != 0);
  }
  iVar10 = param_1[0x1b];
  for (iVar5 = *(int *)(param_1[0x1b] + 8); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
    iVar6 = ((int (*)())FUN_00166ba8)(param_1,iVar10);
    if (iVar6 != 0) {
      FUN_0019401c(iVar10);
      ((int (*)())FUN_0016df8c)(param_1,iVar10);
      iVar6 = (**(code **)(*(int *)param_1[3] + 0x20))
                        ((int *)param_1[3],*(undefined4 *)(iVar10 + 0x38));
      if ((iVar6 != 0) ||
         (iVar6 = (**(code **)(*(int *)param_1[3] + 0x24))
                            ((int *)param_1[3],*(undefined4 *)(iVar10 + 0x38)), iVar6 != 0)) {
        if (iVar8 < *(int *)(iVar10 + 0x14)) {
          iVar8 = *(int *)(iVar10 + 0x14);
        }
        if (*(int *)(iVar10 + 0xc) == param_1[0x48]) {
          iVar9 = iVar9 + 1;
        }
      }
    }
    iVar10 = iVar5;
  }
  iVar10 = FUN_00193f08(param_1 + 0x3e);
  if ((((iVar10 == 0) && (iVar10 = FUN_00193f08(param_1 + 0x13), iVar10 != 0)) &&
      (iVar10 = FUN_00193f08(param_1 + 0xd), iVar10 != 0)) &&
     (iVar10 = FUN_00194034(param_1 + 0x3e), iVar10 == param_1[0x3d])) {
    iVar10 = param_1[0x40];
    for (iVar5 = *(int *)(param_1[0x40] + 8); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
      FUN_0019401c(iVar10);
      *(undefined4 *)(iVar10 + 0x68) = 0;
      FUN_00193f64(param_1 + 0x13,iVar10);
      iVar10 = iVar5;
    }
  }
  iVar10 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0xd4))();
  if ((iVar10 != 0) && (iVar10 = (**(code **)(*(int *)param_1[2] + 0x18))(), iVar10 != 0)) {
    ((int (*)())FUN_0016e1a4)(param_1);
  }
  ((int (*)())FUN_00164a74)(param_1,iVar9,iVar8);
  return param_1[0xb] - iVar7;
}

/* FUN_0016ee90 @ 0x16ee90 (284 bytes) */
int FUN_0016ee90(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*(int *)param_1[2] + 0x50))();
  if (iVar1 == 0) goto LAB_0016ef60;
  iVar1 = FUN_000e07dc(*param_1,0x28);
  if (iVar1 == 0) {
LAB_0016ef04:
    iVar2 = 0;
  }
  else {
    iVar2 = 1;
    iVar1 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],param_2);
    if (iVar1 == 0) goto LAB_0016ef04;
  }
  iVar1 = (**(code **)(*(int *)param_1[2] + 0x4c))
                    ((int *)param_1[2],*(undefined4 *)(param_2 + 0x38));
  if ((iVar1 != *(int *)(param_2 + 0x58)) || (iVar2 != *(int *)(param_2 + 0x5c))) {
    ((int (*)())FUN_0017212c)(param_1[2],param_2);
    *(int *)(param_2 + 0x58) = iVar1;
    *(int *)(param_2 + 0x5c) = iVar2;
    ((int (*)())FUN_00172078)(param_1[2],param_2);
  }
LAB_0016ef60:
  iVar1 = ((int (*)())FUN_00166ba8)(param_1,param_2);
  if (iVar1 != 0) {
    ((int (*)())FUN_0016df8c)(param_1,param_2);
    return;
  }
  FUN_00193f64(param_1 + 0x19,param_2);
  return;
}

/* FUN_0016ff54 @ 0x16ff54 (6564 bytes) */
int FUN_0016ff54(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  uint *puVar26;
  uint uVar27;
  undefined4 uVar28;
  int *piVar29;
  undefined4 uVar30;
  int iVar31;
  uint local_78;
  uint local_74;
  int local_70;
  undefined4 local_6c;
  uint local_68;
  uint local_64 [6];
  undefined4 in_stack_ffffffb8;
  undefined4 in_stack_ffffffbc;
  
  iVar4 = param_1[0x46];
  if (iVar4 == 0) {
    iVar25 = param_1[0x15];
  }
  else {
    iVar25 = param_1[0xf];
  }
  bVar1 = true;
  iVar19 = 0;
  iVar17 = 0;
  iVar18 = 0;
  while (*(int *)(iVar25 + 8) != 0) {
    piVar9 = *(int **)(iVar25 + 0x38);
    if ((iVar4 == 0) && (param_2 < *(int *)(iVar25 + 0x10))) goto LAB_00170868;
    iVar4 = FUN_001045e4(piVar9);
    if (iVar4 == 0) {
      iVar4 = FUN_00104644(piVar9);
      if (iVar4 != 0) {
        iVar4 = ((int (*)())FUN_0016dd04)(param_1,iVar25);
        iVar17 = iVar17 + 1;
        goto joined_r0x00170058;
      }
      iVar4 = *(int *)(iVar25 + 0x60);
      iVar18 = iVar18 + 1;
      if (iVar4 == 0) {
LAB_0017036c:
        iVar4 = FUN_000e07dc(*param_1,0x25);
        if ((iVar4 != 0) &&
           (((((*(int *)(iVar25 + 0x60) == 0 || (*(int *)(*(int *)(iVar25 + 0x60) + 4) < 0)) &&
              (piVar9[0x26] == 1)) && ((*(int *)(iVar25 + 100) == 0 && ((piVar9[5] & 0x40U) == 0))))
            && ((piVar9[5] & 0x20U) == 0)))) {
          iVar14 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x7c))
                             (*(int **)(*param_1 + 0x30c),piVar9);
          iVar4 = DAT_001b0194;
          if (iVar14 != 0) {
            if (*(int **)(iVar25 + 0x60) == (int *)0x0) {
              iVar4 = piVar9[3];
            }
            else {
              iVar4 = **(int **)(iVar25 + 0x60);
            }
          }
          iVar4 = ((int (*)())FUN_00167b68)(param_1,1,iVar4);
          iVar14 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x138))();
          if ((iVar4 < 0) || (iVar14 + 4 <= iVar4)) {
            if ((*(int *)(iVar25 + 0x58) == 2) &&
               (iVar4 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar25),
               iVar4 != 0)) {
              ((int (*)())FUN_0017212c)(param_1[2],iVar25);
              (**(code **)(*(int *)param_1[2] + 0x38))((int *)param_1[2],iVar25);
              ((int (*)())FUN_00172078)(param_1[2],iVar25);
            }
            piVar9[0x26] = 0;
          }
        }
        iVar4 = (**(code **)(*(int *)param_1[3] + 0xc))((int *)param_1[3],piVar9);
        if (iVar4 == 0) {
          iVar4 = *(int *)(iVar25 + 8);
          bVar1 = false;
          FUN_0019401c(iVar25);
          FUN_00193f64(param_1 + 0x1f,iVar25);
          iVar25 = iVar4;
        }
        else {
          if ((*(uint *)(*(int *)(*param_1 + 0x30c) + 8) & 0x200) == 0) {
            iVar4 = (**(code **)(*(int *)param_1[2] + 0xc))((int *)param_1[2],piVar9);
            if (iVar4 != 0) goto LAB_001705f8;
            iVar4 = (**(code **)(*(int *)param_1[2] + 0x24))();
            if (iVar4 != 0) {
              iVar4 = ((int (*)())FUN_00167ef4)(param_1,iVar25);
              if (iVar4 != 0) {
                return iVar4;
              }
              goto LAB_001705f8;
            }
            iVar4 = FUN_000e07dc(*param_1,0x28);
            if (iVar4 != 0) {
              iVar4 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar25);
              if ((iVar4 != 0) &&
                 (iVar4 = (**(code **)(*(int *)param_1[2] + 0x2c))
                                    ((int *)param_1[2],iVar25,param_1 + 0x4d), iVar4 != 0))
              goto LAB_001705f8;
              iVar12 = 0;
              iVar14 = 0;
              iVar4 = 0;
              iVar13 = 0;
              do {
                iVar15 = *(int *)(param_1[0xc] + iVar13 * 4);
                if (iVar15 != 0) {
                  iVar12 = iVar12 + 1;
                  iVar31 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar15);
                  iVar4 = iVar15;
                  if (iVar31 != 0) {
                    iVar14 = iVar14 + 1;
                  }
                }
                bVar1 = iVar13 != 4;
                iVar13 = iVar13 + 1;
              } while (bVar1);
              if ((iVar12 == 1) && (iVar14 == 1)) {
                (**(code **)(*(int *)param_1[2] + 8))();
                iVar14 = (**(code **)(*(int *)param_1[2] + 0xc))
                                   ((int *)param_1[2],*(undefined4 *)(iVar25 + 0x38));
                if (iVar14 != 0) {
                  (**(code **)(*(int *)param_1[2] + 0x10))
                            ((int *)param_1[2],*(undefined4 *)(iVar25 + 0x38));
                  iVar14 = (**(code **)(*(int *)param_1[2] + 0x2c))
                                     ((int *)param_1[2],iVar4,param_1 + 0x4d);
                  if (iVar14 != 0) {
                    (**(code **)(*(int *)param_1[2] + 8))();
                    (**(code **)(*(int *)param_1[2] + 0x10))
                              ((int *)param_1[2],*(undefined4 *)(iVar4 + 0x38));
                    FUN_0019401c(iVar25);
                    return iVar25;
                  }
                }
                (**(code **)(*(int *)param_1[2] + 8))();
                (**(code **)(*(int *)param_1[2] + 0x10))
                          ((int *)param_1[2],*(undefined4 *)(iVar4 + 0x38));
              }
            }
          }
          else {
            iVar4 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar25);
            if ((iVar4 == 0) || (iVar4 = FUN_000e07dc(*param_1,0x28), iVar4 == 0)) {
              iVar4 = (**(code **)(*(int *)param_1[2] + 0xc))((int *)param_1[2],piVar9);
            }
            else {
              iVar4 = (**(code **)(*(int *)param_1[2] + 0x2c))
                                ((int *)param_1[2],iVar25,param_1 + 0x4d);
            }
            if (iVar4 != 0) goto LAB_001705f8;
          }
          iVar14 = *(int *)(iVar25 + 8);
          FUN_0019401c(iVar25);
          iVar4 = FUN_000e07dc(*param_1,0x27);
          if ((((iVar4 != 0) && (iVar4 = FUN_000e07dc(*param_1,0x2b), iVar4 == 0)) &&
              (param_1[0x46] == 0)) &&
             ((*(int *)(iVar25 + 0x60) == 0 || ((*(uint *)(param_1[1] + 0x30) & 0x2000) != 0)))) {
            iVar4 = (**(code **)(*(int *)param_1[2] + 0x3c))((int *)param_1[2],piVar9);
            if (iVar4 - 1U < 3) {
              bVar1 = false;
              FUN_00193f64(param_1 + (iVar4 - 1U) * 6 + 0x2b,iVar25);
              iVar25 = iVar14;
              goto LAB_00170838;
            }
          }
          FUN_00193f64(param_1 + 0x1f,iVar25);
          bVar1 = false;
          iVar25 = iVar14;
        }
      }
      else {
        if (-1 < *(int *)(iVar4 + 4)) {
          iVar4 = FUN_000e07dc(*param_1,0x25);
          if (iVar4 != 0) {
            if (((piVar9[0x20] != 0) && (iVar4 = FUN_00126760(piVar9[0x26]), iVar4 != 0)) &&
               ((piVar9[5] & 2U) == 0)) {
              (**(code **)(*piVar9 + 0x50))(piVar9);
            }
            iVar12 = 4;
            iVar14 = *(int *)(*(int *)(iVar25 + 0x60) + 4);
            iVar4 = 0;
            piVar11 = param_1;
            do {
              iVar13 = iVar4 << 2;
              iVar15 = *(int *)(iVar14 * 4 + piVar11[0x4d]);
              uVar3 = 0;
              if (iVar15 != 0) {
                iVar13 = iVar4 * 4;
                uVar3 = *(undefined4 *)(iVar13 + iVar15 + 0x48);
              }
              *(undefined4 *)((int)local_64 + iVar13) = uVar3;
              iVar4 = iVar4 + 1;
              piVar11 = piVar11 + 1;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
            puVar26 = *(uint **)(iVar25 + 0x44);
            uVar22 = 0;
            uVar20 = puVar26[1];
            if (0 < (int)uVar20) {
              while( true ) {
                if (uVar22 < *puVar26) {
                  uVar24 = puVar26[1];
                  if (uVar24 <= uVar22) {
                    _memset((void *)(uVar24 * 4 + puVar26[2]),0,(uVar22 - uVar24) * 4 + 4);
                    puVar26[1] = uVar22 + 1;
                  }
                  puVar16 = (undefined4 *)(uVar22 * 4 + puVar26[2]);
                }
                else {
                  puVar16 = (undefined4 *)FUN_0019423c(puVar26,uVar22);
                }
                uVar22 = uVar22 + 1;
                piVar11 = (int *)*puVar16;
                iVar4 = *piVar11;
                if (((((piVar11[2] == 0) && (piVar29 = *(int **)(iVar4 + 0x38), piVar29[0x20] != 0))
                     && ((iVar12 = FUN_00126760(piVar29[0x26]), iVar12 != 0 &&
                         (((piVar29[5] & 2U) == 0 &&
                          (iVar12 = (**(code **)(*piVar29 + 0x50))(piVar29), iVar12 == 0)))))) &&
                    (iVar4 = *(int *)(iVar4 + 0x38), (*(uint *)(iVar4 + 0x14) & 0x40) != 0)) &&
                   (iVar14 == *(int *)(iVar4 + 0x94))) {
                  iVar12 = 4;
                  iVar4 = 0;
                  do {
                    if (*(char *)(piVar11 + 6) != '\0') {
                      *(int *)((int)local_64 + iVar4) = *(int *)((int)local_64 + iVar4) + -1;
                    }
                    piVar11 = (int *)((int)piVar11 + 1);
                    iVar4 = iVar4 + 4;
                    iVar12 = iVar12 + -1;
                  } while (iVar12 != 0);
                }
                if (uVar20 == uVar22) break;
                puVar26 = *(uint **)(iVar25 + 0x44);
              }
            }
            iVar4 = 0;
            do {
              iVar14 = FUN_001054ec(piVar9,0);
              if ((*(char *)(iVar4 + iVar14 + 0x10) != '\x01') && (0 < (int)local_64[iVar4]))
              goto LAB_00170968;
              bVar2 = iVar4 != 3;
              iVar4 = iVar4 + 1;
            } while (bVar2);
          }
          iVar4 = *(int *)(iVar25 + 0x60);
          if (iVar4 == 0) goto LAB_0017036c;
        }
        if (*(int *)(iVar4 + 8) == 0) goto LAB_0017036c;
        if (*(int *)(*(int *)(iVar4 + 8) + 0x2c) == param_1[0xb]) {
          iVar14 = FUN_001054ec(piVar9,0);
          pcVar5 = (char *)(iVar4 + 0xc);
          iVar4 = 0;
          local_68 = *(uint *)(iVar14 + 0x10);
          iVar14 = 4;
          do {
            if ((*pcVar5 != '\x01') && (*(char *)((int)local_64 + iVar4 + -4) != '\x01'))
            goto LAB_00170320;
            iVar4 = iVar4 + 1;
            pcVar5 = pcVar5 + 1;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
          iVar4 = *(int *)(iVar25 + 0x60);
        }
        iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 8) + 0x38) + 0x98);
        if (iVar4 == piVar9[0x26]) goto LAB_0017036c;
        if (piVar9[0x26] == 1) {
          piVar9[0x26] = 0;
          goto LAB_0017036c;
        }
        if (((piVar9[5] & 0x20U) == 0) && (iVar4 == 1)) {
          piVar9[0x26] = 1;
          goto LAB_0017036c;
        }
LAB_00170968:
        iVar25 = *(int *)(iVar25 + 8);
      }
    }
    else {
      iVar4 = ((int (*)())FUN_0016d538)(param_1,iVar25);
      iVar19 = iVar19 + 1;
joined_r0x00170058:
      if (iVar4 != 0) {
LAB_001705f8:
        FUN_0019401c(iVar25);
        return iVar25;
      }
LAB_00170320:
      iVar4 = *(int *)(iVar25 + 8);
      FUN_0019401c(iVar25);
      FUN_00193f64(param_1 + 0x1f,iVar25);
      iVar25 = iVar4;
    }
LAB_00170838:
    iVar4 = param_1[0x46];
  }
  if (iVar4 == 0) {
LAB_00170868:
    if (((0 < iVar19) || (0 < iVar17)) &&
       ((iVar18 == 0 && (iVar4 = FUN_00193f08(param_1 + 0x19), iVar4 != 0)))) {
      iVar4 = 5;
      piVar9 = (int *)param_1[0xc];
      do {
        if (*piVar9 != 0) goto LAB_001708c4;
        piVar9 = piVar9 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      iVar4 = FUN_00193f08((int *)param_1[0xc] + 5);
      if (iVar4 != 0) {
        if (0 >= iVar19) {
          if (iVar17 < 1) {
            return 0;
          }
          (**(code **)(*(int *)param_1[2] + 0x1c))();
          return 0;
        }
        iVar4 = param_1[0x61];
        if (0 < iVar4) {
          uVar20 = 0;
          piVar9 = param_1;
          do {
            local_64[1] = piVar9[0x5c];
            local_64[0] = uVar20 + (((int)uVar20 >> 2) +
                                   (uint)((int)uVar20 < 0 && (uVar20 & 3) != 0)) * -4;
            iVar25 = *(int *)(local_64[1] + 0x6c);
            if (iVar25 != 0) {
              iVar4 = local_64[0] * 4;
              do {
                iVar17 = FUN_001054ec(*(undefined4 *)(iVar25 + 0x38),1);
                if (*(int *)(iVar17 + 0x10) == *(int *)(PTR_DAT_001e8b8c + iVar4)) {
                  iVar19 = 4;
                  iVar17 = iVar25;
LAB_0016f038:
                  if (*(int *)(iVar17 + 0x48) < 1) goto code_r0x0016f044;
                  FUN_000f31f8(&local_68,DAT_001b0190,*(undefined4 *)(*(int *)(iVar25 + 0x38) + 0xc)
                              );
                  iVar17 = ((int (*)())FUN_00167e1c)(param_1,*(undefined4 *)(iVar25 + 0x38),local_68,param_1[0xb]
                                        ,iVar25 + 0xc);
                  puVar26 = *(uint **)(iVar25 + 0x40);
                  uVar22 = puVar26[1];
                  uVar24 = uVar22 - 1;
                  if (-1 < (int)uVar24) {
                    iVar19 = uVar24 * 4;
                    uVar23 = 0;
                    while( true ) {
                      if (uVar24 < *puVar26) {
                        uVar10 = puVar26[1];
                        if (uVar10 <= uVar24) {
                          _memset((void *)(uVar10 * 4 + puVar26[2]),0,(uVar24 - uVar10) * 4 + 4);
                          puVar26[1] = uVar24 + 1;
                        }
                        puVar16 = (undefined4 *)(iVar19 + puVar26[2]);
                      }
                      else {
                        puVar16 = (undefined4 *)FUN_0019423c(puVar26,uVar24);
                      }
                      piVar11 = (int *)*puVar16;
                      iVar14 = 1;
                      iVar18 = piVar11[1];
                      if (*(int *)(iVar18 + 0x2c) < 0) {
                        for (; iVar12 = (**(code **)(**(int **)(iVar18 + 0x38) + 0x14))(),
                            iVar14 <= iVar12; iVar14 = iVar14 + 1) {
                          iVar12 = FUN_00105594(*(undefined4 *)(iVar18 + 0x38),iVar14);
                          if (iVar12 == *(int *)(iVar25 + 0x38)) {
                            FUN_00106004(*(undefined4 *)(iVar18 + 0x38),iVar14,
                                         *(undefined4 *)(iVar17 + 0x38),0,*param_1);
                          }
                        }
                        *piVar11 = iVar17;
                        FUN_00194208(*(undefined4 *)(iVar25 + 0x40),uVar24);
                        puVar26 = *(uint **)(iVar17 + 0x40);
                        uVar10 = puVar26[1];
                        if (uVar10 < *puVar26) {
                          _memset((void *)(uVar10 * 4 + puVar26[2]),0,4);
                          puVar16 = (undefined4 *)(uVar10 * 4 + puVar26[2]);
                          puVar26[1] = uVar10 + 1;
                        }
                        else {
                          puVar16 = (undefined4 *)FUN_0019423c(puVar26,uVar10);
                        }
                        *puVar16 = piVar11;
                        iVar14 = *(int *)(iVar18 + 0x34);
                        if (iVar14 == 0) {
                          FUN_0019401c(iVar18);
                          iVar14 = *(int *)(iVar18 + 0x34);
                        }
                        *(int *)(iVar18 + 0x34) = iVar14 + 1;
                        iVar13 = 4;
                        iVar14 = iVar17;
                        iVar12 = iVar25;
                        do {
                          if (*(char *)(piVar11 + 6) != '\0') {
                            *(int *)(iVar14 + 0x48) = *(int *)(iVar14 + 0x48) + 1;
                            *(int *)(iVar12 + 0x48) = *(int *)(iVar12 + 0x48) + -1;
                          }
                          piVar11 = (int *)((int)piVar11 + 1);
                          iVar14 = iVar14 + 4;
                          iVar12 = iVar12 + 4;
                          iVar13 = iVar13 + -1;
                        } while (iVar13 != 0);
                        puVar26 = *(uint **)(iVar18 + 0x44);
                        uVar10 = puVar26[1];
                        uVar27 = uVar10 - 1;
                        if (-1 < (int)uVar27) {
                          iVar14 = uVar27 * 4;
                          uVar21 = 0;
                          while( true ) {
                            if (uVar27 < *puVar26) {
                              uVar6 = puVar26[1];
                              if (uVar6 <= uVar27) {
                                _memset((void *)(uVar6 * 4 + puVar26[2]),0,(uVar27 - uVar6) * 4 + 4)
                                ;
                                puVar26[1] = uVar27 + 1;
                              }
                              puVar16 = (undefined4 *)(iVar14 + puVar26[2]);
                            }
                            else {
                              puVar16 = (undefined4 *)FUN_0019423c(puVar26,uVar27);
                            }
                            piVar11 = (int *)*puVar16;
                            if ((local_64[1] == *piVar11) &&
                               (*(char *)((int)piVar11 + local_64[0] + 0x18) != '\0')) {
                              FUN_00194208(*(undefined4 *)(iVar18 + 0x44),uVar27);
                              piVar11[1] = iVar17;
                              puVar26 = *(uint **)(iVar17 + 0x44);
                              uVar6 = puVar26[1];
                              if (uVar6 < *puVar26) {
                                _memset((void *)(uVar6 * 4 + puVar26[2]),0,4);
                                puVar16 = (undefined4 *)(uVar6 * 4 + puVar26[2]);
                                puVar26[1] = uVar6 + 1;
                              }
                              else {
                                puVar16 = (undefined4 *)FUN_0019423c(puVar26,uVar6);
                              }
                              *puVar16 = piVar11;
                            }
                            uVar21 = uVar21 + 1;
                            uVar27 = uVar27 - 1;
                            iVar14 = iVar14 + -4;
                            if (uVar10 == uVar21) break;
                            puVar26 = *(uint **)(iVar18 + 0x44);
                          }
                        }
                      }
                      uVar23 = uVar23 + 1;
                      uVar24 = uVar24 - 1;
                      iVar19 = iVar19 + -4;
                      if (uVar22 == uVar23) break;
                      puVar26 = *(uint **)(iVar25 + 0x40);
                    }
                  }
                  ((int (*)())FUN_00165b7c)(param_1,iVar25,iVar17,1,0,
                               *(undefined4 *)(*(int *)(iVar17 + 0x38) + 0xc));
                  uVar3 = *(undefined4 *)(iVar25 + 0x38);
                  *(int *)(iVar17 + 0x34) = *(int *)(iVar17 + 0x34) + -1;
                  iVar18 = *(int *)(iVar25 + 0x2c);
                  iVar19 = ((int (*)())FUN_00164e7c)(param_1,uVar3,*(undefined4 *)(iVar17 + 0x38),0,1,0);
                  iVar18 = iVar18 + iVar19;
                  if (*(int *)(iVar17 + 0x30) < iVar18) {
                    *(int *)(iVar17 + 0x30) = iVar18;
                  }
                  ((int (*)())FUN_0016ee90)(param_1,iVar17);
                }
LAB_0016f3cc:
                iVar25 = *(int *)(iVar25 + 0x6c);
              } while (iVar25 != 0);
              iVar4 = param_1[0x61];
            }
            uVar20 = uVar20 + 1;
            piVar9 = piVar9 + 1;
          } while ((int)uVar20 < iVar4);
        }
        iVar4 = FUN_00193f08(param_1 + 0x13);
        if (iVar4 == 0) {
          iVar25 = param_1[0x15];
          iVar4 = (**(code **)(*(int *)param_1[2] + 0xc))
                            ((int *)param_1[2],*(undefined4 *)(iVar25 + 0x38));
          if ((iVar4 != 0) &&
             (iVar4 = (**(code **)(*(int *)param_1[3] + 0xc))
                                ((int *)param_1[3],*(undefined4 *)(iVar25 + 0x38)), iVar4 != 0)) {
            FUN_0019401c(iVar25);
            return iVar25;
          }
        }
        return 0;
      }
    }
LAB_001708c4:
    iVar4 = FUN_00193f08(param_1 + 0x13);
  }
  else {
    iVar4 = FUN_00193f08(param_1 + 0xd);
  }
  if ((iVar4 != 0) || (!bVar1)) {
    return 0;
  }
  if (param_1[0x46] == 0) {
    iVar4 = param_1[0x15];
  }
  else {
    iVar4 = param_1[0xf];
  }
  do {
    if (*(int *)(iVar4 + 8) == 0) {
LAB_0016f574:
      iVar4 = (**(code **)(*(int *)param_1[2] + 0x24))();
      if (iVar4 != 0) {
        (**(code **)(*(int *)param_1[2] + 0x7c))();
      }
      return 0;
    }
    if ((param_1[0x46] == 0) && (param_2 < *(int *)(iVar4 + 0x10))) {
      return 0;
    }
    iVar25 = (**(code **)(*(int *)param_1[2] + 0xc))
                       ((int *)param_1[2],*(undefined4 *)(iVar4 + 0x38));
    if (iVar25 == 0) {
      iVar25 = (**(code **)(*(int *)param_1[2] + 0x24))();
      if (iVar25 != 0) {
        iVar25 = ((int (*)())FUN_00167ef4)(param_1,iVar4);
        if (iVar25 != 0) {
          return iVar25;
        }
        goto LAB_0016f530;
      }
    }
    else {
LAB_0016f530:
      iVar25 = (**(code **)(*(int *)param_1[3] + 0xc))
                         ((int *)param_1[3],*(undefined4 *)(iVar4 + 0x38));
      if (iVar25 != 0) {
        if (*(int *)(iVar4 + 8) != 0) {
          local_6c = *(undefined4 *)(*param_1 + 0x378);
          local_74 = 0;
          local_78 = 2;
          local_70 = FUN_00193e18(local_6c,8);
          local_64[2] = *(undefined4 *)(*param_1 + 0x378);
          local_64[0] = 0;
          local_68 = 2;
          local_64[1] = FUN_00193e18(local_64[2],8);
          uVar7 = *(undefined4 *)(*param_1 + 0x378);
          local_64[3] = 2;
          local_64[4] = 0;
          local_64[5] = FUN_00193e18(uVar7,8);
          uVar30 = *(undefined4 *)(*param_1 + 0x378);
          iVar25 = *(int *)(iVar4 + 0x60);
          puVar8 = (undefined4 *)FUN_00193e18(uVar30,0x2c);
          uVar20 = local_64[4];
          uVar28 = DAT_001b01a8;
          uVar3 = DAT_001b0198;
          *puVar8 = uVar30;
          puVar8[4] = uVar3;
          puVar8[1] = uVar28;
          puVar8[2] = 0xffffffff;
          puVar8[5] = 0;
          puVar8[6] = 0x7fffffff;
          iVar17 = 4;
          puVar8[3] = 0;
          puVar16 = puVar8 + 1;
          do {
            puVar16[6] = 0;
            puVar16 = puVar16 + 1;
            iVar17 = iVar17 + -1;
          } while (iVar17 != 0);
          *(undefined4 **)(iVar4 + 0x60) = puVar8 + 1;
          puVar8[5] = 1;
          uVar3 = *(undefined4 *)(*(int *)(iVar4 + 0x38) + 0xc);
          puVar16 = *(undefined4 **)(iVar4 + 0x60);
          *(int *)(iVar25 + 0x10) = *(int *)(iVar25 + 0x10) + -1;
          *puVar16 = uVar3;
          if (local_64[4] < local_64[3]) {
            iVar17 = local_64[4] * 4;
            _memset((void *)(iVar17 + local_64[5]),0,4);
            local_64[4] = uVar20 + 1;
            piVar9 = (int *)(iVar17 + local_64[5]);
          }
          else {
            piVar9 = (int *)FUN_0019423c(local_64 + 3,local_64[4]);
          }
          *piVar9 = iVar4;
LAB_0016fcc0:
          do {
            uVar20 = local_74;
            if (local_64[4] == 0) {
              if (0 < (int)local_74) {
                uVar24 = 0;
                uVar22 = 1;
                iVar25 = 0;
                do {
                  if (uVar24 < local_78) {
                    if (local_74 <= uVar24) {
                      _memset((void *)(local_74 * 4 + local_70),0,(uVar24 - local_74) * 4 + 4);
                      local_74 = uVar22;
                    }
                    piVar9 = (int *)(iVar25 + local_70);
                  }
                  else {
                    piVar9 = (int *)FUN_0019423c(&local_78,uVar24);
                  }
                  iVar19 = *piVar9;
                  ((int (*)())FUN_0017212c)(param_1[2],iVar19);
                  iVar17 = *(int *)(iVar19 + 0x38);
                  FUN_000f31f8(&STACKARG(0xffffffb8),DAT_001b0190,*(undefined4 *)(iVar17 + 0xc));
                  uVar3 = DAT_001b01a4;
                  *(undefined4 *)(iVar17 + 0x9c) = in_stack_ffffffb8;
                  iVar17 = *(int *)(iVar19 + 0x38);
                  FUN_000f3340(&STACKARG(0xffffffbc),uVar3,*(undefined4 *)(iVar17 + 0xc));
                  iVar17 = FUN_001054ec(iVar17,1);
                  *(undefined4 *)(iVar17 + 0x10) = in_stack_ffffffbc;
                  uVar3 = (**(code **)(*(int *)param_1[2] + 0x4c))
                                    ((int *)param_1[2],*(undefined4 *)(iVar19 + 0x38));
                  *(undefined4 *)(iVar19 + 0x58) = uVar3;
                  if (uVar24 < local_68) {
                    if (local_64[0] <= uVar24) {
                      _memset((void *)(local_64[0] * 4 + local_64[1]),0,
                              (uVar24 - local_64[0]) * 4 + 4);
                      local_64[0] = uVar22;
                    }
                    puVar16 = (undefined4 *)(iVar25 + local_64[1]);
                  }
                  else {
                    puVar16 = (undefined4 *)FUN_0019423c(&local_68,uVar24);
                  }
                  ((int (*)())FUN_00165b7c)(param_1,*puVar16,iVar19,1,0,
                               *(undefined4 *)(*(int *)(iVar19 + 0x38) + 0xc));
                  ((int (*)())FUN_00172078)(param_1[2],iVar19);
                  if (uVar24 < local_68) {
                    if (local_64[0] <= uVar24) {
                      _memset((void *)(local_64[0] * 4 + local_64[1]),0,
                              (uVar24 - local_64[0]) * 4 + 4);
                      local_64[0] = uVar22;
                    }
                    piVar9 = (int *)(iVar25 + local_64[1]);
                  }
                  else {
                    piVar9 = (int *)FUN_0019423c(&local_68,uVar24);
                  }
                  if (-1 < *(int *)(*piVar9 + 0x2c)) {
                    *(int *)(iVar19 + 0x34) = *(int *)(iVar19 + 0x34) + -1;
                    ((int (*)())FUN_0016ee90)(param_1,iVar19);
                  }
                  uVar24 = uVar24 + 1;
                  uVar22 = uVar22 + 1;
                  iVar25 = iVar25 + 4;
                } while (uVar20 != uVar24);
              }
              FUN_0019401c(iVar4);
              FUN_00193cc0(uVar7,local_64[5]);
              FUN_00193cc0(local_64[2],local_64[1]);
              FUN_00193cc0(local_6c,local_70);
              return iVar4;
            }
            piVar9 = (int *)0x0;
            if (local_64[4] - 1 < local_64[4]) {
              piVar9 = (int *)((local_64[4] - 1) * 4 + local_64[5]);
            }
            iVar17 = *piVar9;
            FUN_00194208(local_64 + 3);
            puVar26 = *(uint **)(iVar17 + 0x40);
            uVar22 = 0;
            uVar20 = puVar26[1];
          } while ((int)uVar20 < 1);
          do {
            if (uVar22 < *puVar26) {
              uVar24 = puVar26[1];
              if (uVar24 <= uVar22) {
                _memset((void *)(uVar24 * 4 + puVar26[2]),0,(uVar22 - uVar24) * 4 + 4);
                puVar26[1] = uVar22 + 1;
              }
              piVar9 = (int *)(uVar22 * 4 + puVar26[2]);
            }
            else {
              piVar9 = (int *)FUN_0019423c(puVar26,uVar22);
            }
            iVar19 = *piVar9;
            if (*(int *)(iVar19 + 8) == 0) {
              iVar18 = *(int *)(iVar19 + 4);
              uVar23 = 0;
              puVar26 = *(uint **)(iVar18 + 0x44);
              uVar24 = puVar26[1];
              if (0 < (int)uVar24) {
                do {
                  if (uVar23 < *puVar26) {
                    uVar10 = puVar26[1];
                    if (uVar10 <= uVar23) {
                      _memset((void *)(uVar10 * 4 + puVar26[2]),0,(uVar23 - uVar10) * 4 + 4);
                      puVar26[1] = uVar23 + 1;
                    }
                    puVar16 = (undefined4 *)(uVar23 * 4 + puVar26[2]);
                  }
                  else {
                    puVar16 = (undefined4 *)FUN_0019423c(puVar26,uVar23);
                  }
                  piVar9 = (int *)*puVar16;
                  if ((((piVar9[2] == 0) && (iVar14 = *piVar9, iVar17 != iVar14)) &&
                      (piVar9[4] == *(int *)(iVar19 + 0x10))) &&
                     (piVar9[5] == *(int *)(iVar19 + 0x14))) {
                    if (((*(int *)(iVar14 + 0x2c) < 0) ||
                        ((*(uint *)(*(int *)(iVar14 + 0x38) + 0x14) & 0x40) == 0)) &&
                       (iVar14 = ((int (*)())FUN_00166a0c)(param_1), uVar10 = local_64[4], iVar14 == 0)) {
                      if (*(int *)(*piVar9 + 0x60) != *(int *)(iVar4 + 0x60)) {
                        *(int *)(*piVar9 + 0x60) = *(int *)(iVar4 + 0x60);
                        *(int *)(*(int *)(iVar4 + 0x60) + 0x10) =
                             *(int *)(*(int *)(iVar4 + 0x60) + 0x10) + 1;
                        **(uint **)(iVar4 + 0x60) =
                             **(uint **)(iVar4 + 0x60) | *(uint *)(*(int *)(*piVar9 + 0x38) + 0xc);
                        *(int *)(iVar25 + 0x10) = *(int *)(iVar25 + 0x10) + -1;
                        iVar14 = *piVar9;
                        if (local_64[4] < local_64[3]) {
                          iVar12 = local_64[4] * 4;
                          _memset((void *)(iVar12 + local_64[5]),0,4);
                          local_64[4] = uVar10 + 1;
                          piVar9 = (int *)(iVar12 + local_64[5]);
                        }
                        else {
                          piVar9 = (int *)FUN_0019423c(local_64 + 3,local_64[4]);
                        }
                        *piVar9 = iVar14;
                      }
                    }
                    else {
                      uVar10 = local_74;
                      if ((int)local_74 < 1) {
                        iVar14 = *piVar9;
                      }
                      else {
                        uVar27 = 0;
                        do {
                          if (uVar27 < local_78) {
                            if (local_74 <= uVar27) {
                              _memset((void *)(local_74 * 4 + local_70),0,
                                      (uVar27 - local_74) * 4 + 4);
                              local_74 = uVar27 + 1;
                            }
                            piVar11 = (int *)(uVar27 * 4 + local_70);
                          }
                          else {
                            piVar11 = (int *)FUN_0019423c(&local_78,uVar27);
                          }
                          iVar12 = FUN_00105594(*(undefined4 *)(*piVar11 + 0x38),1);
                          iVar14 = *piVar9;
                          if (iVar12 == *(int *)(iVar14 + 0x38)) {
                            if (uVar27 < local_78) {
                              if (local_74 <= uVar27) {
                                _memset((void *)(local_74 * 4 + local_70),0,
                                        (uVar27 - local_74) * 4 + 4);
                                local_74 = uVar27 + 1;
                              }
                              piVar11 = (int *)(uVar27 * 4 + local_70);
                            }
                            else {
                              piVar11 = (int *)FUN_0019423c(&local_78,uVar27);
                            }
                            iVar14 = *piVar11;
                            *(uint *)(*(int *)(iVar14 + 0x38) + 0xc) =
                                 *(uint *)(*(int *)(iVar14 + 0x38) + 0xc) | piVar9[6];
                            **(uint **)(iVar14 + 0x60) = **(uint **)(iVar14 + 0x60) | piVar9[6];
                            goto LAB_0016fafc;
                          }
                          uVar27 = uVar27 + 1;
                        } while (uVar10 != uVar27);
                      }
                      uVar3 = DAT_001b0190;
                      iVar12 = *(int *)(iVar14 + 0x2c);
                      uVar28 = *(undefined4 *)(iVar14 + 0x38);
                      iVar14 = (**(code **)(*(int *)param_1[2] + 0x78))();
                      iVar14 = ((int (*)())FUN_00167e1c)(param_1,uVar28,uVar3,iVar12 + iVar14,*piVar9 + 0xc);
                      if (local_74 < local_78) {
                        iVar12 = local_74 * 4;
                        local_74 = local_74 + 1;
                        *(undefined4 *)(iVar12 + local_70) = 0;
                        piVar11 = (int *)(iVar12 + local_70);
                      }
                      else {
                        piVar11 = (int *)FUN_0019423c(&local_78);
                      }
                      *piVar11 = iVar14;
                      if (local_64[0] < local_68) {
                        iVar12 = local_64[0] * 4;
                        local_64[0] = local_64[0] + 1;
                        *(undefined4 *)(iVar12 + local_64[1]) = 0;
                        piVar11 = (int *)(iVar12 + local_64[1]);
                      }
                      else {
                        piVar11 = (int *)FUN_0019423c(&local_68);
                      }
                      *piVar11 = *piVar9;
                      *(int *)(*(int *)(iVar14 + 0x38) + 0xc) = piVar9[6];
                      FUN_00106804(*(undefined4 *)(iVar14 + 0x38),*(undefined4 *)(iVar17 + 0x38),0,
                                   *param_1);
                      *(undefined4 *)(iVar14 + 0x60) = *(undefined4 *)(iVar4 + 0x60);
                      *(int *)(*(int *)(iVar4 + 0x60) + 0x10) =
                           *(int *)(*(int *)(iVar4 + 0x60) + 0x10) + 1;
                      **(uint **)(iVar4 + 0x60) = **(uint **)(iVar4 + 0x60) | piVar9[6];
LAB_0016fafc:
                      if ((piVar9[4] < 1) || (piVar9[5] != 0)) {
LAB_0016fb44:
                        iVar12 = *piVar9;
                      }
                      else {
                        iVar13 = FUN_00105594(*(undefined4 *)(iVar18 + 0x38));
                        iVar12 = *piVar9;
                        if (iVar13 == *(int *)(iVar12 + 0x38)) {
                          FUN_00106004(*(undefined4 *)(iVar18 + 0x38),piVar9[4],
                                       *(undefined4 *)(iVar14 + 0x38),0,*param_1);
                          goto LAB_0016fb44;
                        }
                      }
                      iVar31 = 4;
                      iVar15 = 0;
                      piVar11 = piVar9;
                      iVar13 = iVar14;
                      do {
                        if (*(char *)(piVar11 + 6) != '\0') {
                          iVar12 = iVar15 * 4 + iVar12;
                          *(int *)(iVar12 + 0x48) = *(int *)(iVar12 + 0x48) + -1;
                          *(int *)(iVar13 + 0x48) = *(int *)(iVar13 + 0x48) + 1;
                          iVar12 = *piVar9;
                        }
                        iVar15 = iVar15 + 1;
                        piVar11 = (int *)((int)piVar11 + 1);
                        iVar13 = iVar13 + 4;
                        iVar31 = iVar31 + -1;
                      } while (iVar31 != 0);
                      FUN_00194374(*(undefined4 *)(iVar12 + 0x40),piVar9);
                      if (-1 < *(int *)(*piVar9 + 0x2c)) {
                        *(int *)(iVar18 + 0x34) = *(int *)(iVar18 + 0x34) + 1;
                      }
                      *piVar9 = iVar14;
                      puVar26 = *(uint **)(iVar14 + 0x40);
                      uVar10 = puVar26[1];
                      if (uVar10 < *puVar26) {
                        _memset((void *)(uVar10 * 4 + puVar26[2]),0,4);
                        puVar16 = (undefined4 *)(uVar10 * 4 + puVar26[2]);
                        puVar26[1] = uVar10 + 1;
                      }
                      else {
                        puVar16 = (undefined4 *)FUN_0019423c(puVar26,uVar10);
                      }
                      *puVar16 = piVar9;
                    }
                  }
                  uVar23 = uVar23 + 1;
                  if (uVar24 == uVar23) break;
                  puVar26 = *(uint **)(iVar18 + 0x44);
                } while( true );
              }
            }
            uVar22 = uVar22 + 1;
            if (uVar20 == uVar22) goto LAB_0016fcc0;
            puVar26 = *(uint **)(iVar17 + 0x40);
          } while( true );
        }
        goto LAB_0016f574;
      }
    }
    iVar4 = *(int *)(iVar4 + 8);
  } while( true );
code_r0x0016f044:
  iVar17 = iVar17 + 4;
  iVar19 = iVar19 + -1;
  if (iVar19 == 0) goto LAB_0016f3cc;
  goto LAB_0016f038;
}

/* FUN_00170990 @ 0x170990 (572 bytes) */
int FUN_00170990(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (((*(int *)(param_1 + 0x118) == 0) && (iVar2 = FUN_00193f08(param_1 + 0x4c), iVar2 == 0)) &&
     (*(int *)(param_1 + 0x20) != 0)) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x54) + 0x10);
    iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x84))();
    iVar2 = iVar2 + iVar3;
  }
  else {
    iVar2 = 0x7fffffff;
  }
  while ((iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x20))(), iVar3 == 0 &&
         (iVar3 = ((int (*)())FUN_0016ff54)(param_1,iVar2), iVar3 != 0))) {
    ((int (*)())FUN_0016d3b0)(param_1,iVar3);
  }
  iVar2 = 0;
  iVar3 = 0;
  while( true ) {
    while( true ) {
      iVar4 = FUN_00193f08(iVar3 + param_1 + 0xac);
      if (iVar4 != 0) break;
      uVar5 = *(undefined4 *)(iVar3 + param_1 + 0xb4);
      FUN_0019401c(uVar5);
      iVar4 = (**(code **)(**(int **)(param_1 + 8) + 0x20))();
      if ((iVar4 == 0) && (iVar4 = ((int (*)())FUN_00168d80)(param_1,uVar5), iVar4 != 0)) {
        ((int (*)())FUN_0016d3b0)(param_1,iVar4);
      }
      else {
        FUN_00193f64(param_1 + 0x7c,uVar5);
      }
    }
    bVar1 = iVar2 == 2;
    iVar2 = iVar2 + 1;
    if (bVar1) break;
    iVar3 = iVar2 * 0x18;
  }
  while (((iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x20))(), iVar2 == 0 &&
          (*(int *)(param_1 + 0x118) == 0)) && (iVar2 = ((int (*)())FUN_0016629c)(param_1), iVar2 != 0))) {
    ((int (*)())FUN_0016d3b0)(param_1,iVar2);
  }
  iVar2 = ((int (*)())FUN_0016c640)(param_1);
  if (iVar2 == 0) {
    (**(code **)(**(int **)(param_1 + 8) + 0x7c))();
  }
  ((int (*)())FUN_0016e828)(param_1);
  iVar3 = FUN_00193f08(param_1 + 0x4c);
  if ((iVar3 == 0) || (iVar3 = FUN_00193f08(param_1 + 0x34), iVar3 == 0)) {
    uVar5 = 0;
  }
  else {
    iVar3 = FUN_00193f08(param_1 + 100);
    uVar5 = 1;
    if (iVar3 == 0) {
      iVar3 = ((int (*)())FUN_0016c640)(param_1);
      if (iVar3 == 0) {
        *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x80;
      }
      ((int (*)())FUN_0016e828)(param_1);
      uVar5 = 0;
    }
  }
  return uVar5;
}

/* FUN_00170bcc @ 0x170bcc (468 bytes) */
int FUN_00170bcc(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  
  puVar10 = *(uint **)(param_2 + 0x40);
  uVar3 = puVar10[1];
  if (0 < (int)uVar3) {
    uVar8 = 0;
    uVar4 = 1;
    iVar5 = 0;
    while( true ) {
      if (uVar8 < *puVar10) {
        uVar1 = puVar10[1];
        puVar11 = puVar10;
        if (uVar1 <= uVar8) {
          _memset((void *)(uVar1 * 4 + puVar10[2]),0,(uVar8 - uVar1) * 4 + 4);
          puVar10[1] = uVar4;
          puVar11 = *(uint **)(param_2 + 0x40);
        }
        piVar2 = (int *)(iVar5 + puVar10[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar10,uVar8);
        puVar11 = *(uint **)(param_2 + 0x40);
      }
      iVar6 = *(int *)(param_2 + 0x2c);
      iVar9 = *(int *)(*piVar2 + 4);
      iVar7 = *(int *)(iVar9 + 0x30);
      *(int *)(iVar9 + 0x34) = *(int *)(iVar9 + 0x34) + -1;
      if (uVar8 < *puVar11) {
        uVar1 = puVar11[1];
        if (uVar1 <= uVar8) {
          _memset((void *)(uVar1 * 4 + puVar11[2]),0,(uVar8 - uVar1) * 4 + 4);
          puVar11[1] = uVar4;
        }
        piVar2 = (int *)(iVar5 + puVar11[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar11,uVar8);
      }
      if (iVar7 < iVar6 + *(int *)(*piVar2 + 0xc)) {
        puVar10 = *(uint **)(param_2 + 0x40);
        iVar6 = *(int *)(param_2 + 0x2c);
        if (uVar8 < *puVar10) {
          uVar1 = puVar10[1];
          if (uVar1 <= uVar8) {
            _memset((void *)(uVar1 * 4 + puVar10[2]),0,(uVar8 - uVar1) * 4 + 4);
            puVar10[1] = uVar4;
          }
          piVar2 = (int *)(iVar5 + puVar10[2]);
        }
        else {
          piVar2 = (int *)FUN_0019423c(puVar10,uVar8);
        }
        iVar6 = iVar6 + *(int *)(*piVar2 + 0xc);
      }
      else {
        iVar6 = *(int *)(iVar9 + 0x30);
      }
      *(int *)(iVar9 + 0x30) = iVar6;
      if (*(int *)(iVar9 + 0x34) == 0) {
        ((int (*)())FUN_0016ee90)(param_1,iVar9);
      }
      uVar8 = uVar8 + 1;
      uVar4 = uVar4 + 1;
      iVar5 = iVar5 + 4;
      if (uVar3 == uVar8) break;
      puVar10 = *(uint **)(param_2 + 0x40);
    }
  }
  return;
}

/* FUN_00170da0 @ 0x170da0 (204 bytes) */
int FUN_00170da0(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(param_2 + 0x2c) = uVar1;
  *(undefined4 *)(param_2 + 0x30) = uVar1;
  ((int (*)())FUN_0017212c)(*(undefined4 *)(param_1 + 8));
  ((int (*)())FUN_0016cdc4)(param_1,param_2);
  ((int (*)())FUN_00170bcc)(param_1,param_2);
  iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))
                    (*(int **)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38));
  if (((iVar2 != 0) ||
      (iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))
                         (*(int **)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38)), iVar2 != 0)) &&
     (*(int *)(param_1 + 0x128) <= *(int *)(param_2 + 0xc))) {
    *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + 1;
  }
  *(uint *)(*(int *)(param_2 + 0x38) + 0x14) =
       *(uint *)(*(int *)(param_2 + 0x38) + 0x14) & 0xfffffffe;
  return;
}

/* FUN_00170e6c @ 0x170e6c (2212 bytes) */
int FUN_00170e6c(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  uint *puVar14;
  int *piVar15;
  int iVar16;
  int local_48;
  int local_44;
  undefined1 auStack_40 [8];
  int local_38;
  
  ((int (*)())FUN_0016a568)();
  ((int (*)())FUN_0016bd70)(param_1);
  ((int (*)())FUN_001670fc)(param_1);
  piVar3 = (int *)param_1[0x4c];
  iVar2 = *piVar3;
  if (iVar2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    do {
      piVar3[2] = 0;
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = param_1[0x51];
  if (0 < iVar2) {
    uVar7 = 0;
    do {
      uVar8 = uVar7 >> 3 & 0x1ffffffc;
      uVar11 = uVar7 & 0x1f;
      if (((*(uint *)(uVar8 + *(int *)(param_1[1] + 0x430) + 8) >> uVar11 & 1) != 0) &&
         ((*(uint *)(uVar8 + *(int *)(param_2 + 0x104) + 8) >> uVar11 & 1) == 0)) {
        *(uint *)(uVar8 + param_1[0x4c] + 8) = 1 << uVar11 | *(uint *)(uVar8 + param_1[0x4c] + 8);
      }
      iVar2 = 4;
      piVar3 = param_1;
      do {
        piVar12 = piVar3 + 0x4d;
        piVar3 = piVar3 + 1;
        *(undefined4 *)(uVar7 * 4 + *piVar12) = 0;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      iVar2 = param_1[0x51];
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < iVar2);
  }
  if (param_1[0x58] != 0) {
    piVar3 = param_1;
    while( true ) {
      if (0 < iVar2) {
        iVar2 = 0;
        do {
          iVar9 = iVar2 * 4;
          iVar2 = iVar2 + 1;
          *(undefined4 *)(iVar9 + piVar3[0x54]) = 0;
        } while (iVar2 < param_1[0x51]);
      }
      iVar2 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x13c))();
      if (0 < iVar2) {
        iVar9 = 0;
        do {
          iVar5 = iVar9 * 4;
          iVar9 = iVar9 + 1;
          *(undefined4 *)(iVar5 + piVar3[0x58]) = 0;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      piVar3 = piVar3 + 1;
      if (param_1 + 4 == piVar3) break;
      iVar2 = param_1[0x51];
    }
  }
  puVar14 = (uint *)param_1[5];
  uVar7 = puVar14[1];
  if (uVar7 != 0) {
    uVar11 = 0;
    do {
      if (uVar11 < *puVar14) {
        if (uVar7 <= uVar11) {
          _memset((void *)(uVar7 * 4 + puVar14[2]),0,(uVar11 - uVar7) * 4 + 4);
          puVar14[1] = uVar11 + 1;
        }
        piVar3 = (int *)(uVar11 * 4 + puVar14[2]);
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar14,uVar11);
      }
      uVar11 = uVar11 + 1;
      iVar9 = *piVar3;
      piVar3 = *(int **)(iVar9 + 0x38);
      iVar2 = piVar3[0x25];
      if ((((piVar3[0x20] != 0) && (iVar5 = FUN_00126760(piVar3[0x26]), iVar5 != 0)) &&
          ((piVar3[5] & 2U) == 0)) &&
         ((iVar5 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar5 == 0 && ((piVar3[5] & 0x40U) != 0)))
         ) {
        local_48 = piVar3[3];
        if (*(int *)(iVar9 + 0x60) != 0) {
          *(int *)(*(int *)(iVar9 + 0x60) + 8) = iVar9;
          *(int *)(*(int *)(iVar9 + 0x60) + 4) = iVar2;
          local_48 = **(int **)(iVar9 + 0x60);
        }
        iVar16 = 4;
        iVar5 = 0;
        piVar12 = param_1;
        do {
          if (*(char *)((int)&local_48 + iVar5) != '\0') {
            *(int *)(piVar12[0x4d] + iVar2 * 4) = iVar9;
            if (piVar12[0x54] != 0) {
              *(undefined4 *)(piVar12[0x54] + iVar2 * 4) = 0x7fffffff;
            }
            if (*(int *)(iVar9 + 0x60) != 0) {
              *(int *)(iVar5 * 4 + *(int *)(iVar9 + 0x60) + 0x18) = iVar9;
              *(undefined4 *)(*(int *)(iVar9 + 0x60) + 0x14) = 0;
            }
          }
          iVar5 = iVar5 + 1;
          piVar12 = piVar12 + 1;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
        if (piVar3[0x26] == 1) {
          iVar5 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x138))();
          iVar9 = param_1[0x67];
          if (param_1[0x67] < iVar2 - iVar5) {
            iVar9 = iVar2 - iVar5;
          }
          param_1[0x67] = iVar9;
        }
        else {
          iVar9 = param_1[0x66];
          if (param_1[0x66] < iVar2) {
            iVar9 = iVar2;
          }
          param_1[0x66] = iVar9;
          if (iVar2 <= param_1[0x68]) {
            iVar2 = param_1[0x68];
          }
          param_1[0x68] = iVar2;
        }
      }
      puVar14 = (uint *)param_1[5];
      uVar7 = puVar14[1];
    } while (uVar11 < uVar7);
  }
  iVar2 = 4;
  piVar3 = param_1;
  do {
    piVar3[0x5c] = 0;
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 0;
  piVar3 = param_1;
  do {
    bVar1 = iVar2 != 1;
    piVar3[0x62] = 0;
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (bVar1);
  iVar2 = FUN_000e07dc(*param_1,0x47);
  if ((iVar2 != 0) && (iVar2 = FUN_000e07dc(*param_1,0x24), iVar2 != 0)) {
    ((int (*)())FUN_00169b70)(param_1);
  }
  uVar11 = 0;
  (**(code **)(*(int *)param_1[2] + 8))();
  (**(code **)(*(int *)param_1[3] + 8))();
  param_1[0x46] = 1;
  param_1[0x4a] = -1;
  param_1[0x4b] = 0;
  param_1[0xb] = 1;
  param_1[0x47] = -1;
  param_1[0x48] = -1;
  param_1[0x49] = 0;
  FUN_001940a8(auStack_40);
  puVar14 = (uint *)param_1[6];
  uVar7 = puVar14[1];
  if (0 < (int)uVar7) {
    while( true ) {
      if (uVar11 < *puVar14) {
        uVar8 = puVar14[1];
        if (uVar8 <= uVar11) {
          _memset((void *)(uVar8 * 4 + puVar14[2]),0,(uVar11 - uVar8) * 4 + 4);
          puVar14[1] = uVar11 + 1;
        }
        piVar3 = (int *)(uVar11 * 4 + puVar14[2]);
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar14,uVar11);
      }
      if (*(int *)(*piVar3 + 0x34) == 0) {
        FUN_00193f64(auStack_40);
      }
      uVar11 = uVar11 + 1;
      if (uVar7 == uVar11) break;
      puVar14 = (uint *)param_1[6];
    }
  }
  iVar9 = *(int *)(local_38 + 8);
  iVar2 = local_38;
  while (iVar5 = iVar9, iVar5 != 0) {
    FUN_0019401c(iVar2);
    ((int (*)())FUN_0016ee90)(param_1,iVar2);
    iVar9 = (**(code **)(*(int *)param_1[3] + 0x20))
                      ((int *)param_1[3],*(undefined4 *)(iVar2 + 0x38));
    if ((iVar9 == 0) &&
       (iVar9 = (**(code **)(*(int *)param_1[3] + 0x24))
                          ((int *)param_1[3],*(undefined4 *)(iVar2 + 0x38)), iVar9 == 0)) {
      iVar9 = *(int *)(iVar2 + 0xc);
      if (*(int *)(iVar2 + 0xc) < param_1[0x47]) {
        iVar9 = param_1[0x47];
      }
      param_1[0x47] = iVar9;
    }
    else {
      iVar9 = *(int *)(iVar2 + 0xc);
      if (*(int *)(iVar2 + 0xc) < param_1[0x48]) {
        iVar9 = param_1[0x48];
      }
      param_1[0x48] = iVar9;
    }
    iVar2 = iVar5;
    iVar9 = *(int *)(iVar5 + 8);
  }
  piVar3 = param_1 + 0xd;
  param_1[0x46] = 0;
  iVar2 = FUN_00193f08(piVar3);
  if ((iVar2 == 0) && (param_1[0x47] + -1 <= param_1[0x48])) {
    param_1[0x4a] = param_1[0x48];
    param_1[0x46] = 1;
  }
  piVar12 = (int *)(*(int **)(param_1[4] + 0x98))[2];
  if (piVar12 != (int *)0x0) {
    piVar10 = (int *)0x0;
    piVar15 = *(int **)(param_1[4] + 0x98);
    do {
      piVar13 = piVar12;
      iVar2 = (**(code **)(*piVar15 + 0x34))(piVar15);
      if ((iVar2 == 0) && (iVar2 = (**(code **)(*piVar15 + 0x38))(piVar15), iVar2 == 0)) {
        iVar2 = ((int (*)())FUN_00164df4)(piVar15);
        if (iVar2 == 0) {
          FUN_0019401c(piVar15);
          piVar15[0x56] = 0;
        }
        else {
          piVar15[5] = piVar15[5] | 4;
          piVar10 = piVar15;
        }
      }
      else {
        piVar15[5] = piVar15[5] & 0xfffffffb;
      }
      piVar12 = (int *)piVar13[2];
      piVar15 = piVar13;
    } while (piVar12 != (int *)0x0);
    if (piVar10 != (int *)0x0) {
      piVar10[5] = piVar10[5] & 0xfffffffb;
    }
  }
  piVar12 = param_1 + 0x13;
  iVar2 = FUN_00193f08(piVar12);
  if ((((iVar2 == 0) || (iVar2 = FUN_00193f08(piVar3), iVar2 == 0)) ||
      (iVar2 = FUN_00193f08(param_1 + 0x19), iVar2 == 0)) ||
     (iVar2 = FUN_00193f08(param_1 + 0x3e), iVar2 == 0)) {
    iVar2 = ((int (*)())FUN_0016c640)(param_1);
    if ((iVar2 == 0) && (iVar2 = FUN_00193f08(param_1 + 0x25), iVar2 != 0)) {
      iVar2 = FUN_00193f08(param_1 + 0x3e);
      if (((iVar2 == 0) && (iVar2 = FUN_00193f08(piVar12), iVar2 != 0)) &&
         ((iVar2 = FUN_00193f08(piVar3), iVar2 != 0 &&
          (iVar2 = FUN_00194034(param_1 + 0x3e), iVar2 == param_1[0x3d])))) {
        iVar2 = param_1[0x40];
        for (iVar9 = *(int *)(param_1[0x40] + 8); iVar9 != 0; iVar9 = *(int *)(iVar9 + 8)) {
          FUN_0019401c(iVar2);
          *(undefined4 *)(iVar2 + 0x68) = 0;
          FUN_00193f64(piVar12,iVar2);
          iVar2 = iVar9;
        }
      }
    }
    else {
      ((int (*)())FUN_0016e828)(param_1);
    }
    do {
      iVar2 = ((int (*)())FUN_00170990)(param_1);
    } while (iVar2 == 0);
    ((int (*)())FUN_0016c640)(param_1);
    puVar6 = (undefined4 *)param_1[0xc];
    iVar2 = 5;
    puVar4 = puVar6;
    do {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  else {
    ((int (*)())FUN_0016c640)(param_1);
    puVar6 = (undefined4 *)param_1[0xc];
    iVar2 = 5;
    puVar4 = puVar6;
    do {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_00193fa4(puVar6 + 5);
  iVar2 = (**(code **)(*(int *)param_1[3] + 0x1c))();
  if (iVar2 != 0) {
    iVar2 = *(int *)(param_2 + 0xd0);
    iVar9 = 0;
    local_44 = 0;
    for (uVar7 = 1; uVar7 <= *(uint *)(iVar2 + 4); uVar7 = uVar7 + 1) {
      local_44 = *(int *)(*(int *)(iVar2 + 8) + iVar9);
      if (local_44 != 0) {
        *(undefined4 *)(local_44 + 0xdc) = 1;
      }
      iVar9 = iVar9 + 4;
    }
  }
  ((int (*)())FUN_00166cfc)(param_1);
  return;
}

/* FUN_00171714 @ 0x171714 (1812 bytes) */
int FUN_00171714(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  
  param_1[1] = param_2;
  *param_1 = *(int *)(param_2 + 8);
  iVar4 = FUN_0010ddcc();
  param_1[2] = iVar4;
  iVar4 = FUN_0010ddd8(*param_1);
  param_1[3] = iVar4;
  uVar11 = *(undefined4 *)(*param_1 + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar11,0x14);
  *puVar5 = uVar11;
  puVar5[1] = 2;
  puVar5[4] = uVar11;
  puVar5[2] = 0;
  uVar11 = FUN_00193e18(uVar11,8);
  puVar5[3] = uVar11;
  param_1[5] = (int)(puVar5 + 1);
  uVar11 = *(undefined4 *)(*param_1 + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar11,0x14);
  *puVar5 = uVar11;
  puVar5[1] = 2;
  puVar5[2] = 0;
  puVar5[4] = uVar11;
  uVar11 = FUN_00193e18(uVar11,8);
  puVar5[3] = uVar11;
  param_1[6] = (int)(puVar5 + 1);
  uVar11 = *(undefined4 *)(*param_1 + 0x378);
  puVar6 = (undefined4 *)FUN_00193e18(uVar11,0x30);
  *puVar6 = uVar11;
  FUN_001940a8(puVar6 + 6);
  iVar4 = 5;
  puVar5 = puVar6 + 1;
  do {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0xc] = (int)(puVar6 + 1);
  iVar4 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x138))();
  iVar7 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x140))();
  iVar4 = iVar4 + iVar7;
  param_1[0x51] = iVar4;
  uVar2 = iVar4 + 0x1fU >> 5;
  uVar11 = *(undefined4 *)(*param_1 + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar11,uVar2 * 4 + 0xc);
  piVar10 = puVar5 + 1;
  *puVar5 = uVar11;
  puVar5[1] = uVar2;
  puVar5[2] = iVar4;
  if (uVar2 != 0) {
    iVar4 = *piVar10;
    piVar12 = piVar10;
    if (iVar4 == 0) {
      iVar4 = 1;
    }
    do {
      piVar12[2] = 0;
      piVar12 = piVar12 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  param_1[0x4c] = (int)piVar10;
  iVar4 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x13c))();
  bVar1 = iVar4 < 1;
  piVar10 = param_1;
  do {
    iVar7 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),param_1[0x51] << 2);
    piVar10[0x4d] = iVar7;
    if (bVar1) {
      piVar10[0x54] = 0;
      piVar10[0x58] = 0;
    }
    else {
      iVar8 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),param_1[0x51] << 2);
      iVar7 = *param_1;
      piVar10[0x54] = iVar8;
      iVar7 = FUN_00193e18(*(undefined4 *)(iVar7 + 0x378),iVar4 << 2);
      piVar10[0x58] = iVar7;
    }
    piVar10 = piVar10 + 1;
  } while (piVar10 != param_1 + 4);
  param_1[0x53] = param_1[0x51];
  param_1[0x60] = 0;
  param_1[0x61] = -1;
  param_1[0x52] = param_1[0x51];
  param_1[100] = 0;
  param_1[0x65] = 0;
  param_1[0x66] = -1;
  param_1[0x67] = -1;
  param_1[0x68] = -1;
  param_1[0x69] = -1;
  param_1[0x6a] = 0;
  iVar4 = FUN_000e79d0(*(undefined4 *)(param_1[1] + 0x3a0));
  if (iVar4 == 1) {
    iVar4 = param_1[1];
    puVar5 = (undefined4 *)0x0;
    iVar7 = *(int *)(*(int *)(iVar4 + 0x3a0) + 0xd0);
    if (*(int *)(iVar7 + 4) != 0) {
      puVar5 = *(undefined4 **)(iVar7 + 8);
    }
    piVar14 = *(int **)(*(int *)(iVar4 + 0x3a0) + 0xa0);
    uVar11 = *puVar5;
    piVar12 = (int *)piVar14[1];
    if (piVar12 != (int *)0x0) {
      do {
        piVar13 = piVar12;
        iVar4 = (**(code **)(*piVar14 + 0x34))(piVar14);
        if ((iVar4 == 0) && (iVar4 = (**(code **)(*piVar14 + 0x38))(piVar14), iVar4 == 0)) {
          FUN_0019401c(piVar14);
          FUN_000e76c4(uVar11,piVar14);
        }
        piVar12 = (int *)piVar13[1];
        piVar14 = piVar13;
      } while (piVar12 != (int *)0x0);
      iVar4 = param_1[1];
    }
    *(undefined4 *)(iVar4 + 0x3a4) = uVar11;
  }
  iVar4 = FUN_000e79dc(*(undefined4 *)(param_1[1] + 0x3a8));
  if (iVar4 == 1) {
    iVar4 = param_1[1];
    puVar5 = (undefined4 *)0x0;
    iVar7 = *(int *)(*(int *)(iVar4 + 0x3a8) + 0xd4);
    if (*(int *)(iVar7 + 4) != 0) {
      puVar5 = *(undefined4 **)(iVar7 + 8);
    }
    piVar14 = *(int **)(*(int *)(iVar4 + 0x3a8) + 0x98);
    uVar11 = *puVar5;
    piVar12 = (int *)piVar14[2];
    if (piVar12 == (int *)0x0) goto LAB_00171ba0;
    do {
      piVar13 = piVar12;
      iVar4 = (**(code **)(*piVar14 + 0x34))(piVar14);
      if ((iVar4 == 0) && (iVar4 = (**(code **)(*piVar14 + 0x38))(piVar14), iVar4 == 0)) {
        iVar4 = (**(code **)(*piVar14 + 0x68))(piVar14);
        if (iVar4 != 0) {
          piVar12 = (int *)FUN_00105594(piVar14,1);
          iVar4 = (**(code **)(*piVar12 + 0x50))();
          if (iVar4 != 0) goto LAB_00171b84;
        }
        FUN_0019401c(piVar14);
        FUN_000e7688(uVar11,piVar14);
      }
LAB_00171b84:
      piVar12 = (int *)piVar13[2];
      piVar14 = piVar13;
    } while (piVar12 != (int *)0x0);
  }
  iVar4 = param_1[1];
LAB_00171ba0:
  (**(code **)(*(int *)param_1[2] + 0x70))((int *)param_1[2],iVar4);
  FUN_000ed7e4(param_1[1],"sched_preprocess");
  iVar4 = FUN_000e07dc(*param_1,0x43);
  if (iVar4 != 0) {
    FUN_00184ab4(param_1,param_2);
  }
  ((int (*)())FUN_00169e30)(param_1);
  ((int (*)())FUN_00165014)(param_1);
  iVar4 = *(int *)(param_1[1] + 900);
  iVar7 = *(int *)(iVar4 + 8);
  while (iVar7 != 0) {
    iVar7 = FUN_00194034(iVar4 + 0x90);
    if (2 < iVar7) {
      ((int (*)())FUN_00170e6c)(param_1,iVar4);
      param_1[100] = param_1[100] + param_1[0xb];
      *(undefined4 *)(iVar4 + 0x118) = *(undefined4 *)(param_1[1] + 0x474);
    }
    iVar4 = *(int *)(iVar4 + 8);
    iVar7 = *(int *)(iVar4 + 8);
  }
  if (!bVar1) {
    param_1[0x66] = param_1[0x68];
  }
  if (-1 < param_1[0x66]) {
    iVar4 = 0;
    do {
      iVar7 = iVar4 + 1;
      FUN_00130444(param_1[1],iVar4);
      iVar4 = iVar7;
    } while (iVar7 <= param_1[0x66]);
  }
  iVar4 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x138))();
  if (-1 < param_1[0x67]) {
    iVar7 = 0;
    do {
      iVar8 = iVar4 + iVar7;
      iVar7 = iVar7 + 1;
      FUN_00130444(param_1[1],iVar8);
    } while (iVar7 <= param_1[0x67]);
  }
  iVar7 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x140))();
  if (-1 < param_1[0x69]) {
    iVar8 = 0;
    do {
      iVar9 = iVar4 + iVar7 + iVar8;
      iVar8 = iVar8 + 1;
      FUN_00130444(param_1[1],iVar9);
    } while (iVar8 <= param_1[0x69]);
  }
  FUN_000e0e0c(*param_1,"Scheduler : Total cycles %d\n",param_1[100]);
  FUN_000e0e0c(*param_1,"Scheduler : Total dot-product transformed %d\n",param_1[0x6a]);
  FUN_000ed7e4(param_1[1],"schedule_inst");
  FUN_00138080(param_2);
  iVar4 = param_1[0x4c];
  piVar12 = param_1;
  if (iVar4 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
  }
  do {
    if (!bVar1) {
      FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),piVar12[0x54]);
      FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),piVar12[0x58]);
    }
    piVar14 = piVar12 + 1;
    FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),piVar12[0x4d]);
    piVar12 = piVar14;
  } while (piVar10 != piVar14);
  iVar4 = param_1[0xc];
  if (iVar4 != 0) {
    puVar3 = PTR_DAT_001e8b48 + 8;
    *(undefined **)(iVar4 + 0x14) = puVar3;
    *(undefined **)(iVar4 + 0x20) = puVar3;
    FUN_00193cc0(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
  }
  iVar4 = param_1[6];
  if (iVar4 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar4 + 0xc),*(undefined4 *)(iVar4 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
  }
  iVar4 = param_1[5];
  if (iVar4 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar4 + 0xc),*(undefined4 *)(iVar4 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
    return;
  }
  return;
}

/* FUN_00171e68 @ 0x171e68 (248 bytes) */
int FUN_00171e68(param_1)
  int param_1;
{
  bool bVar1;
  undefined4 *puVar2;
  int iVar4;
  undefined1 auStack_1d8 [52];
  undefined1 auStack_1a4 [24];
  undefined1 auStack_18c [24];
  undefined1 auStack_174 [24];
  undefined1 auStack_15c [24];
  undefined1 auStack_144 [24];
  undefined4 auStack_12c [18];
  undefined4 uStack_e4;
  undefined1 local_e0 [200];
  undefined4 *puVar3;
  
  FUN_001940a8(auStack_1a4);
  FUN_001940a8(auStack_18c);
  FUN_001940a8(auStack_174);
  FUN_001940a8(auStack_15c);
  FUN_001940a8(auStack_144);
  iVar4 = 1;
  puVar2 = auStack_12c;
  do {
    FUN_001940a8(puVar2);
    bVar1 = iVar4 != -1;
    puVar2 = puVar2 + 6;
    iVar4 = iVar4 + -1;
  } while (bVar1);
  FUN_001940a8(local_e0);
  iVar4 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x42);
  if (iVar4 != 0) {
    FUN_0018401c(auStack_1d8,param_1);
  }
  ((int (*)())FUN_00171714)(auStack_1d8,param_1);
  puVar2 = &uStack_e4;
  do {
    puVar3 = puVar2 + -6;
    *puVar3 = PTR_DAT_001e8b48 + 8;
    puVar2[-3] = PTR_DAT_001e8b48 + 8;
    puVar2 = puVar3;
  } while (puVar3 != auStack_12c);
  return;
}

/* FUN_00172000 @ 0x172000 (20 bytes) */
int FUN_00172000(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

/* FUN_00172078 @ 0x172078 (180 bytes) */
int FUN_00172078(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  (**(code **)(*param_1 + 0x4c))(param_1,*(undefined4 *)(param_2 + 0x38));
  iVar1 = *(int *)(param_2 + 0x58);
  if (iVar1 == 3) {
    param_1[3] = param_1[3] + 1;
    param_1[4] = param_1[4] + 1;
  }
  else if (*(int *)(param_2 + 0x5c) == 0) {
    if (iVar1 == 1) {
      param_1[3] = param_1[3] + 1;
    }
    else if (iVar1 == 2) {
      param_1[4] = param_1[4] + 1;
    }
  }
  else {
    param_1[5] = param_1[5] + 1;
  }
  return;
}

/* FUN_0017212c @ 0x17212c (216 bytes) */
int FUN_0017212c(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x58);
  iVar1 = (**(code **)(*param_1 + 0x4c))(param_1,*(undefined4 *)(param_2 + 0x38));
  if (iVar2 != iVar1) {
    (**(code **)(*param_1 + 0x50))(param_1);
  }
  iVar1 = *(int *)(param_2 + 0x58);
  if (iVar1 == 3) {
    param_1[3] = param_1[3] + -1;
    param_1[4] = param_1[4] + -1;
  }
  else if (*(int *)(param_2 + 0x5c) == 0) {
    if (iVar1 == 1) {
      param_1[3] = param_1[3] + -1;
    }
    else if (iVar1 == 2) {
      param_1[4] = param_1[4] + -1;
    }
  }
  else {
    param_1[5] = param_1[5] + -1;
  }
  return;
}

