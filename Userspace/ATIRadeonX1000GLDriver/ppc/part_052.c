#include "decls.h"

/* FUN_00197b30 @ 0x197b30 (692 bytes) */
int FUN_00197b30(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int *piVar1;
  undefined2 uVar4;
  int iVar2;
  int iVar3;
  byte bVar5;
  int iVar6;
  int iVar7;
  
  piVar1 = (int *)FUN_00105594(param_2,1);
  uVar4 = thunk_FUN_00134de8(*(undefined4 *)(param_4 + 0x6c4),piVar1);
  iVar2 = (**(code **)(**(int **)(param_4 + 0x30c) + 0x7c))(*(int **)(param_4 + 0x30c),param_2);
  if (iVar2 == 0) {
    FUN_001054ec(param_2,0);
  }
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x16]) = 2;
  *(undefined2 *)(param_1[0x18] * 0x48 + param_1[0x16] + 0xe) = uVar4;
  iVar2 = *(int *)(param_2 + 0x134);
  iVar6 = *(int *)(*(int *)(param_2 + 0x88) + 8);
  if (iVar6 != 0x77) {
    *(char *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x19) = (char)iVar2;
    iVar7 = param_1[0x18];
    iVar3 = param_1[0x16];
    uVar4 = thunk_FUN_00134de8(*(undefined4 *)(param_4 + 0x6c4),param_2);
    *(undefined2 *)(iVar7 * 0x48 + iVar3 + 0xc) = uVar4;
  }
  else {
    *(undefined2 *)(param_1[0x18] * 0x48 + param_1[0x16] + 0xc) = 0;
    *(undefined4 *)(param_1[0x17] + 0x9370) = 1;
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x19) = 0;
  }
  iVar3 = (**(code **)(*piVar1 + 0x80))(piVar1);
  if (iVar3 == 0) {
    *(undefined4 *)(iVar2 * 4 + param_1[0x17] + 0x9378) = 1;
  }
  if (*(int *)(PTR_DAT_001e913c + iVar6 * 0x38 + 0xc) != -1) {
    *(char *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x1a) =
         (char)*(int *)(PTR_DAT_001e913c + iVar6 * 0x38 + 0xc);
  }
  bVar5 = 0xc;
  iVar2 = *(int *)(iVar2 * 0xc + *(int *)(*(int *)(param_4 + 0x6c4) + 0x78) + 4);
  if (((iVar2 != 2) && (bVar5 = 8, iVar2 != 3)) && (bVar5 = 0, iVar2 == 1)) {
    bVar5 = 0xe;
  }
  if (iVar6 != 0x77) {
    if (iVar6 - 0x75U < 2) {
      *(byte *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x1f) = bVar5 & 7;
    }
    else {
      *(byte *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x1f) = bVar5;
    }
  }
  else {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x1f) = 0;
  }
  piVar1 = (int *)FUN_00105594(param_2,1);
  iVar2 = (**(code **)(*piVar1 + 0x80))();
  if (iVar2 != 0) {
                    
                    
    (**(code **)(*param_1 + 0x154))(param_1,1,param_2,param_4);
    return;
  }
  return;
}

/* FUN_00197de4 @ 0x197de4 (232 bytes) */
int FUN_00197de4(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_38 [9];
  
  iVar3 = FUN_00105594(param_5,param_2);
  iVar4 = FUN_001054ec(param_5,param_2);
  iVar5 = 0;
  local_38[0] = *(undefined4 *)(iVar4 + 0x10);
  iVar4 = 4;
  do {
    uVar2 = (uint)*(byte *)((int)local_38 + iVar5);
    if (uVar2 < 4) goto LAB_00197e50;
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar2 = 0;
LAB_00197e50:
  fVar1 = *(float *)(uVar2 * 0x18 + iVar3 + 0x20);
  if (fVar1 == FLOAT_001aa0d4) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x14;
  }
  else if (fVar1 == FLOAT_001aa10c) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x16;
  }
  else if (fVar1 == FLOAT_001aa0e8) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x15;
  }
  return;
}

/* FUN_00197ecc @ 0x197ecc (232 bytes) */
int FUN_00197ecc(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_38 [9];
  
  iVar3 = FUN_00105594(param_5,param_2);
  iVar4 = FUN_001054ec(param_5,param_2);
  iVar5 = 0;
  local_38[0] = *(undefined4 *)(iVar4 + 0x10);
  iVar4 = 4;
  do {
    uVar2 = (uint)*(byte *)((int)local_38 + iVar5);
    if (uVar2 < 4) goto LAB_00197f38;
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar2 = 0;
LAB_00197f38:
  fVar1 = *(float *)(uVar2 * 0x18 + iVar3 + 0x20);
  if (fVar1 == FLOAT_001aa0d4) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x10;
  }
  else if (fVar1 == FLOAT_001aa10c) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x12;
  }
  else if (fVar1 == FLOAT_001aa0e8) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x11;
  }
  return;
}

/* FUN_00197fb4 @ 0x197fb4 (208 bytes) */
int FUN_00197fb4(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
  if (param_2 != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0xc) =
         (*(unsigned short *)((unsigned char *)&(param_5) + 2));
    iVar4 = *(int *)(param_1 + 0x60);
    iVar1 = *(int *)(param_1 + 0x58);
    iVar2 = FUN_001054ec(param_4,0);
    uVar3 = FUN_00195424(*(undefined4 *)(iVar2 + 0x10));
    *(undefined1 *)(iVar4 * 0x48 + iVar1 + 0x14) = uVar3;
  }
  if (param_3 != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x18) =
         (*(unsigned short *)((unsigned char *)&(param_5) + 2));
    iVar4 = *(int *)(param_1 + 0x60);
    iVar1 = *(int *)(param_1 + 0x58);
    iVar2 = FUN_001054ec(param_4,0);
    *(bool *)(iVar4 * 0x48 + iVar1 + 0x20) = *(char *)(iVar2 + 0x13) == '\0';
  }
  return;
}

/* FUN_00198084 @ 0x198084 (296 bytes) */
int FUN_00198084(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_4 + 0x98);
  iVar4 = *(int *)(param_4 + 0x94);
  if (iVar6 == 9) {
    iVar1 = iVar4 + 1;
    iVar3 = *(int *)(*(int *)(param_1 + 0x5c) + 0x9374);
    if (iVar1 <= iVar3) {
      iVar1 = iVar3;
    }
    *(int *)(*(int *)(param_1 + 0x5c) + 0x9374) = iVar1;
  }
  uVar5 = (undefined1)iVar4;
  if ((param_2 != 0) && (iVar6 != 8)) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x16) = uVar5;
    iVar3 = *(int *)(param_1 + 0x60);
    iVar4 = *(int *)(param_1 + 0x58);
    iVar1 = FUN_001054ec(param_4,0);
    uVar2 = FUN_00195424(*(undefined4 *)(iVar1 + 0x10));
    *(undefined1 *)(iVar3 * 0x48 + iVar4 + 0x15) = uVar2;
  }
  if (param_3 != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x22) = uVar5;
    if (iVar6 == 8) {
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x23) = 1;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x60);
      iVar4 = *(int *)(param_1 + 0x58);
      iVar6 = FUN_001054ec(param_4,0);
      *(bool *)(iVar1 * 0x48 + iVar4 + 0x21) = *(char *)(iVar6 + 0x13) == '\0';
    }
  }
  return;
}

/* FUN_001981ac @ 0x1981ac (8500 bytes) */
int FUN_001981ac(param_1, param_2)
  int *param_1;
  int *param_2;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  uint uVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  uint uVar18;
  int *piVar19;
  int iVar20;
  uint uVar21;
  undefined4 uVar22;
  int *piVar23;
  int *piVar24;
  byte in_xer_so;
  int iVar25;
  undefined4 local_f8;
  undefined4 local_f4;
  int local_f0;
  undefined4 local_ec [4];
  undefined4 local_dc [4];
  undefined1 local_cc [16];
  undefined4 local_bc [4];
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_9c;
  undefined4 local_98;
  int local_88;
  uint local_84;
  int *local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  int local_68;
  int local_64;
  undefined *local_60;
  undefined1 *local_5c;
  
  uVar10 = FUN_0019786c(param_1,&local_9c,&local_ac,param_2,&local_f8,&local_f4);
  local_6c = uVar10 & 1;
  local_70 = uVar10 >> 1 & 1;
  local_68 = *(int *)(param_2[0x22] + 8);
  local_5c = local_cc;
  iVar25 = 4;
  local_78 = uVar10 >> 4 & 1;
  local_74 = uVar10 >> 2 & 1;
  iVar8 = 0;
  do {
    *(undefined4 *)(iVar8 + (int)local_bc) = 0;
    *(undefined4 *)(iVar8 + (int)local_dc) = 0;
    *(undefined4 *)(iVar8 + (int)local_ec) = 0;
    *(undefined4 *)(local_5c + iVar8) = 0;
    iVar8 = iVar8 + 4;
    iVar25 = iVar25 + -1;
  } while (iVar25 != 0);
  iVar8 = (**(code **)(*param_2 + 0x14))(param_2);
  uVar6 = local_6c;
  uVar10 = local_70;
  if (local_68 == 0xb4) {
    iVar8 = 3;
LAB_00198290:
    iVar25 = 1;
    piVar19 = param_2 + 0x26;
    bVar1 = local_6c != 0;
    bVar2 = local_70 != 0;
    local_64 = (uint)(byte)(((int)local_78 < 0) << 3 | (0 < (int)local_78) << 2 |
                            (local_78 == 0) << 1 | in_xer_so & 1) << 0x1c;
    local_60 = &DAT_001b81b8;
    do {
      iVar11 = FUN_001054ec(param_2,iVar25);
      iVar11 = *(int *)(iVar11 + 0x10);
      local_f0 = -1;
      piVar12 = (int *)FUN_00105594(param_2,iVar25);
      iVar20 = *(int *)(local_60 + -0x56f8);
      iVar13 = (**(code **)(*piVar12 + 0x60))();
      if (iVar13 == 0) {
        local_7c = 0;
        local_80 = (int *)0x0;
      }
      else {
        local_80 = piVar12;
        iVar11 = FUN_001054ec(piVar12,1);
        uVar17 = *(undefined4 *)(iVar11 + 0x10);
        iVar11 = FUN_001054ec(param_2,iVar25);
        iVar20 = *(int *)(iVar11 + 0x10);
        FUN_000f2bdc(&local_88,uVar17,iVar20);
        iVar11 = local_88;
        piVar12 = (int *)FUN_00105594(local_80,1);
        FUN_00106004(param_2,iVar25,piVar12,0,param_1[3]);
        if (iVar25 == 0) {
          local_7c = 1;
          param_2[0x27] = iVar11;
        }
        else {
          iVar13 = FUN_001054ec(param_2,iVar25);
          *(int *)(iVar13 + 0x10) = iVar11;
          local_7c = 1;
        }
      }
      iVar13 = piVar12[0x26];
      if (iVar13 != 0x2c) {
        if (iVar13 == 0x29) {
          local_f0 = (**(code **)(*param_1 + 0x158))(param_1,param_2,iVar25,param_1[3]);
LAB_0019852c:
          bVar3 = iVar25 == 3;
          bVar5 = (byte)((uint)local_64 >> 0x18);
          if ((bVar3) && (!(bool)(bVar5 >> 5 & 1))) {
            local_ec[2] = 0x11;
          }
          if (bVar1) {
            uVar17 = local_9c;
            if (bVar3) {
              if (!(bool)(bVar5 >> 5 & 1)) goto LAB_00199cdc;
              if (local_74 != 0) {
                uVar17 = local_98;
              }
            }
            iVar15 = FUN_0019534c(iVar11,uVar17);
            iVar16 = FUN_001953b8(iVar11,uVar17);
            local_bc[iVar25] = 0x14;
            iVar13 = iVar25;
            if (iVar15 == 0) {
              if (iVar16 != 0) {
                uVar21 = 1;
                piVar23 = param_1 + 0xe;
                piVar14 = param_1;
                do {
                  piVar24 = (int *)piVar14[7];
                  iVar15 = uVar21 - 1;
                  if ((piVar12 == piVar24) ||
                     ((((((((piVar24 != (int *)0x0 && (piVar12 != (int *)0x0)) &&
                           (piVar24[0x20] != 0)) &&
                          ((iVar16 = FUN_00126760(piVar24[0x26]), iVar16 != 0 &&
                           ((piVar24[5] & 2U) == 0)))) &&
                         ((iVar16 = (**(code **)(*piVar24 + 0x50))(piVar24), iVar16 == 0 &&
                          ((piVar12[0x20] != 0 &&
                           (iVar16 = FUN_00126760(piVar12[0x26]), iVar16 != 0)))))) &&
                        ((piVar12[5] & 2U) == 0)) &&
                       (((iVar16 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar16 == 0 &&
                         ((*(uint *)(piVar14[7] + 0x14) & 0x40) != 0)) &&
                        ((piVar12[5] & 0x40U) != 0)))) &&
                      (*(int *)(piVar14[7] + 0x94) == piVar12[0x25])))) {
                    uVar9 = param_1[0x20];
                    *piVar23 = local_f0;
                    param_1[0x20] = 1 << (uVar21 & 0x3f) | uVar9;
                    goto LAB_00199c88;
                  }
                  bVar4 = uVar21 != 3;
                  piVar23 = piVar23 + 1;
                  piVar14 = piVar14 + 1;
                  uVar21 = uVar21 + 1;
                } while (bVar4);
                iVar15 = 3;
LAB_00199c88:
                pcVar7 = *(code **)(*param_1 + 0xf8);
                goto joined_r0x00199c90;
              }
            }
            else {
              if (iVar16 == 0) {
                uVar21 = 1;
                piVar23 = param_1 + 0x12;
                piVar14 = param_1;
                do {
                  piVar24 = (int *)piVar14[10];
                  iVar15 = uVar21 - 1;
                  if ((piVar12 == piVar24) ||
                     ((((((piVar24 != (int *)0x0 && (piVar12 != (int *)0x0)) &&
                         ((piVar24[0x20] != 0 &&
                          ((iVar16 = FUN_00126760(piVar24[0x26]), iVar16 != 0 &&
                           ((piVar24[5] & 2U) == 0)))))) &&
                        (iVar16 = (**(code **)(*piVar24 + 0x50))(piVar24), iVar16 == 0)) &&
                       (((piVar12[0x20] != 0 && (iVar16 = FUN_00126760(piVar12[0x26]), iVar16 != 0))
                        && ((piVar12[5] & 2U) == 0)))) &&
                      (((iVar16 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar16 == 0 &&
                        ((*(uint *)(piVar14[10] + 0x14) & 0x40) != 0)) &&
                       (((piVar12[5] & 0x40U) != 0 &&
                        (*(int *)(piVar14[10] + 0x94) == piVar12[0x25])))))))) {
                    uVar9 = param_1[0x21];
                    *piVar23 = local_f0;
                    param_1[0x21] = 1 << (uVar21 & 0x3f) | uVar9;
                    goto LAB_00199b44;
                  }
                  bVar4 = uVar21 != 3;
                  piVar23 = piVar23 + 1;
                  piVar14 = piVar14 + 1;
                  uVar21 = uVar21 + 1;
                } while (bVar4);
                iVar15 = 3;
LAB_00199b44:
                pcVar7 = *(code **)(*param_1 + 0xf4);
              }
              else {
                uVar21 = 1;
                piVar23 = param_1;
                piVar14 = param_1;
                do {
                  piVar24 = (int *)piVar23[7];
                  iVar15 = uVar21 - 1;
                  if (((piVar12 == piVar24) ||
                      ((((piVar24 != (int *)0x0 && (piVar12 != (int *)0x0)) &&
                        ((piVar24[0x20] != 0 &&
                         ((((((iVar16 = FUN_00126760(piVar24[0x26]), iVar16 != 0 &&
                              ((piVar24[5] & 2U) == 0)) &&
                             (iVar16 = (**(code **)(*piVar24 + 0x50))(piVar24), iVar16 == 0)) &&
                            ((piVar12[0x20] != 0 &&
                             (iVar16 = FUN_00126760(piVar12[0x26]), iVar16 != 0)))) &&
                           ((piVar12[5] & 2U) == 0)) &&
                          ((iVar16 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar16 == 0 &&
                           ((*(uint *)(piVar23[7] + 0x14) & 0x40) != 0)))))))) &&
                       (((piVar12[5] & 0x40U) != 0 && (*(int *)(piVar23[7] + 0x94) == piVar12[0x25])
                        ))))) &&
                     ((piVar24 = (int *)piVar23[10], piVar12 == piVar24 ||
                      ((((((piVar24 != (int *)0x0 && (piVar12 != (int *)0x0)) &&
                          (piVar24[0x20] != 0)) &&
                         ((iVar16 = FUN_00126760(piVar24[0x26]), iVar16 != 0 &&
                          ((piVar24[5] & 2U) == 0)))) &&
                        (((iVar16 = (**(code **)(*piVar24 + 0x50))(piVar24), iVar16 == 0 &&
                          ((piVar12[0x20] != 0 &&
                           (iVar16 = FUN_00126760(piVar12[0x26]), iVar16 != 0)))) &&
                         ((piVar12[5] & 2U) == 0)))) &&
                       ((((iVar16 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar16 == 0 &&
                          ((*(uint *)(piVar23[10] + 0x14) & 0x40) != 0)) &&
                         ((piVar12[5] & 0x40U) != 0)) &&
                        (*(int *)(piVar23[10] + 0x94) == piVar12[0x25])))))))) {
                    uVar18 = param_1[0x20];
                    uVar9 = param_1[0x21];
                    uVar21 = 1 << (uVar21 & 0x3f);
                    piVar14[0x12] = local_f0;
                    param_1[0x20] = uVar21 | uVar18;
                    param_1[0x21] = uVar21 | uVar9;
                    piVar14[0xe] = local_f0;
                    goto LAB_001999e8;
                  }
                  bVar4 = uVar21 != 3;
                  piVar23 = piVar23 + 1;
                  uVar21 = uVar21 + 1;
                  piVar14 = piVar14 + 1;
                } while (bVar4);
                iVar15 = 3;
LAB_001999e8:
                (**(code **)(*param_1 + 0xf4))(param_1,iVar25,local_bc,local_dc,iVar15,iVar11);
                pcVar7 = *(code **)(*param_1 + 0xf8);
joined_r0x00199c90:
                if (bVar3) {
                  if ((bool)((byte)((uint)local_64 >> 0x1d) & 1)) {
                    iVar13 = 3;
                  }
                  else {
                    iVar13 = 1;
                  }
                }
              }
              (*pcVar7)(param_1,iVar13,local_bc,local_dc,iVar15,iVar11);
            }
          }
LAB_00199cdc:
          if (bVar2) {
            iVar11 = FUN_001054ec(param_2,iVar25);
            uVar22 = *(undefined4 *)(iVar11 + 0x10);
            uVar17 = local_ac;
            if ((bVar3) && (local_74 != 0)) {
              uVar17 = local_a8;
            }
            iVar11 = FUN_0019534c(uVar22,uVar17);
            iVar13 = FUN_001953b8(uVar22,uVar17);
            local_ec[iVar25] = 0x10;
            if (iVar11 != 0) {
              uVar21 = 1;
              piVar23 = param_1 + 0x12;
              piVar14 = param_1;
              do {
                piVar24 = (int *)piVar14[10];
                iVar11 = uVar21 - 1;
                if ((piVar12 == piVar24) ||
                   ((((piVar24 != (int *)0x0 && (piVar12 != (int *)0x0)) &&
                     ((piVar24[0x20] != 0 &&
                      ((((iVar15 = FUN_00126760(piVar24[0x26]), iVar15 != 0 &&
                         ((piVar24[5] & 2U) == 0)) &&
                        (iVar15 = (**(code **)(*piVar24 + 0x50))(piVar24), iVar15 == 0)) &&
                       ((piVar12[0x20] != 0 && (iVar15 = FUN_00126760(piVar12[0x26]), iVar15 != 0)))
                       ))))) &&
                    ((((piVar12[5] & 2U) == 0 &&
                      ((iVar15 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar15 == 0 &&
                       ((*(uint *)(piVar14[10] + 0x14) & 0x40) != 0)))) &&
                     (((piVar12[5] & 0x40U) != 0 && (*(int *)(piVar14[10] + 0x94) == piVar12[0x25]))
                     )))))) {
                  uVar9 = param_1[0x21];
                  *piVar23 = local_f0;
                  param_1[0x21] = 1 << (uVar21 & 0x3f) | uVar9;
                  goto LAB_00199e60;
                }
                bVar4 = uVar21 != 3;
                piVar23 = piVar23 + 1;
                piVar14 = piVar14 + 1;
                uVar21 = uVar21 + 1;
              } while (bVar4);
              iVar11 = 3;
LAB_00199e60:
              iVar15 = iVar25;
              if (bVar3) {
                if ((bool)((byte)((uint)local_64 >> 0x1d) & 1)) {
                  iVar15 = 3;
                }
                else {
                  iVar15 = 1;
                }
              }
              (**(code **)(*param_1 + 0xfc))(param_1,iVar15,local_ec,local_5c,iVar11,uVar22);
            }
            if (iVar13 != 0) {
              uVar21 = 1;
              piVar23 = param_1 + 0xe;
              piVar14 = param_1;
              do {
                piVar24 = (int *)piVar14[7];
                iVar11 = uVar21 - 1;
                if ((piVar12 == piVar24) ||
                   (((((piVar24 != (int *)0x0 && (piVar12 != (int *)0x0)) && (piVar24[0x20] != 0))
                     && ((((iVar13 = FUN_00126760(piVar24[0x26]), iVar13 != 0 &&
                           ((piVar24[5] & 2U) == 0)) &&
                          ((iVar13 = (**(code **)(*piVar24 + 0x50))(piVar24), iVar13 == 0 &&
                           ((piVar12[0x20] != 0 &&
                            (iVar13 = FUN_00126760(piVar12[0x26]), iVar13 != 0)))))) &&
                         ((piVar12[5] & 2U) == 0)))) &&
                    ((((iVar13 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar13 == 0 &&
                       ((*(uint *)(piVar14[7] + 0x14) & 0x40) != 0)) && ((piVar12[5] & 0x40U) != 0))
                     && (*(int *)(piVar14[7] + 0x94) == piVar12[0x25])))))) {
                  uVar9 = param_1[0x20];
                  *piVar23 = local_f0;
                  param_1[0x20] = 1 << (uVar21 & 0x3f) | uVar9;
                  goto LAB_00199fdc;
                }
                bVar4 = uVar21 != 3;
                piVar23 = piVar23 + 1;
                piVar14 = piVar14 + 1;
                uVar21 = uVar21 + 1;
              } while (bVar4);
              iVar11 = 3;
LAB_00199fdc:
              iVar13 = iVar25;
              if (bVar3) {
                if ((bool)((byte)((uint)local_64 >> 0x1d) & 1)) {
                  iVar13 = 3;
                }
                else {
                  iVar13 = 1;
                }
              }
              (**(code **)(*param_1 + 0x100))(param_1,iVar13,local_ec,local_5c,iVar11,uVar22);
            }
          }
        }
        else {
          if ((((piVar12[0x20] != 0) && (iVar13 = FUN_00126760(iVar13), iVar13 != 0)) &&
              ((piVar12[5] & 2U) == 0)) &&
             (iVar13 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar13 == 0)) {
            local_f0 = FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),piVar12);
            iVar13 = (**(code **)(*piVar12 + 0x80))(piVar12);
            if (iVar13 != 0) {
              (**(code **)(*param_1 + 0x154))(param_1,iVar25,param_2,param_1[3]);
            }
            goto LAB_0019852c;
          }
          iVar13 = (**(code **)(*piVar12 + 0x50))(piVar12);
          if (iVar13 != 0) {
            local_f0 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),piVar12);
            goto LAB_0019852c;
          }
          iVar13 = (**(code **)(*piVar12 + 0x48))(piVar12);
          if (iVar13 != 0) {
            if (piVar12[0x26] == 0x33) {
              iVar13 = (**(code **)(*param_1 + 0xdc))(param_1,piVar12,&local_f0);
              if (iVar13 == 0) {
                if ((iVar25 != 3) || ((bool)((byte)((uint)local_64 >> 0x1d) & 1))) {
                  if (bVar1) {
                    (**(code **)(*param_1 + 0xd4))(param_1,iVar25,local_bc,local_dc,param_2);
                  }
                  if (bVar2) {
                    (**(code **)(*param_1 + 0xd8))(param_1,iVar25,local_ec,local_5c,param_2);
                  }
                }
                else {
                  local_ec[2] = 0x11;
                  (**(code **)(*param_1 + 0xd8))(param_1,3,local_ec,local_5c,param_2);
                  local_ec[1] = local_ec[3];
                }
                goto LAB_0019a030;
              }
            }
            else {
              local_f0 = piVar12[0x25];
              FUN_00196370(param_1,local_f0,piVar12);
              local_f0 = (**(code **)(*param_1 + 0xe0))(param_1,local_f0);
            }
            goto LAB_0019852c;
          }
          iVar13 = (**(code **)(*piVar12 + 0x5c))(piVar12);
          if (iVar13 == 0) goto LAB_0019852c;
          if ((iVar25 != 3) || ((bool)((byte)((uint)local_64 >> 0x1d) & 1))) {
            if (bVar1) {
              (**(code **)(*param_1 + 0xec))(param_1,iVar25,local_bc,local_dc,iVar11);
            }
            if (bVar2) {
              (**(code **)(*param_1 + 0xf0))(param_1,iVar25,local_ec,local_5c,iVar11);
            }
          }
          else {
            local_ec[2] = 0x11;
            (**(code **)(*param_1 + 0xf0))(param_1,1,local_ec,local_5c,iVar11);
          }
          FUN_000f3398(&local_84,iVar11);
          uVar21 = local_84 & 0xff;
          bVar3 = (local_84 & 0xffffff00) == 0;
          iVar13 = *(int *)(piVar12[0x22] + 8);
          iVar11 = (**(code **)(*piVar12 + 0x14))(piVar12);
          if (!bVar3) {
            param_1[0x20] = iVar11 * 4 - 2U | param_1[0x20];
            (**(code **)(*param_1 + 0xe4))
                      (param_1,*(undefined4 *)(PTR_DAT_001e913c + iVar13 * 0x38 + 0xc));
          }
          bVar4 = -1 < (int)-uVar21;
          if (!bVar4) {
            param_1[0x21] = iVar11 * 4 - 2U | param_1[0x21];
            (**(code **)(*param_1 + 0xe8))
                      (param_1,*(undefined4 *)(PTR_DAT_001e913c + iVar13 * 0x38 + 0xc));
          }
          if (iVar11 < 2) {
            if (iVar11 != 1) goto LAB_0019a030;
            piVar14 = (int *)FUN_00105594(piVar12,1);
            if ((((piVar14[0x20] == 0) || (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0)) ||
                ((piVar14[5] & 2U) != 0)) ||
               (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0)) {
              piVar14 = (int *)FUN_00105594(piVar12,1);
              iVar11 = (**(code **)(*piVar14 + 0x50))();
              if (iVar11 != 0) goto LAB_001994a8;
              piVar14 = (int *)FUN_00105594(piVar12,1);
              iVar13 = 0;
              iVar11 = (**(code **)(*piVar14 + 0x48))();
              if (iVar11 != 0) {
                iVar11 = FUN_00105594(piVar12,1);
                uVar22 = *(undefined4 *)(iVar11 + 0x94);
                uVar17 = FUN_00105594(piVar12,1);
                FUN_00196370(param_1,uVar22,uVar17);
                iVar13 = (**(code **)(*param_1 + 0xe0))(param_1,uVar22);
              }
            }
            else {
LAB_001994a8:
              uVar22 = *(undefined4 *)(param_1[3] + 0x6c4);
              uVar17 = FUN_00105594(piVar12,1);
              iVar13 = thunk_FUN_00134de8(uVar22,uVar17);
            }
            if (!bVar3) {
              iVar11 = FUN_00105594(piVar12,1);
              if ((((((iVar11 != param_1[7]) && (iVar11 = FUN_00105594(piVar12,1), iVar11 != 0)) &&
                    ((param_1[7] != 0 &&
                     ((piVar14 = (int *)FUN_00105594(piVar12,1), piVar14[0x20] != 0 &&
                      (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0)))))) &&
                   ((piVar14[5] & 2U) == 0)) &&
                  (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                    (piVar14 = (int *)param_1[7], piVar14[0x20] != 0)) &&
                   (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0)))) &&
                 ((((piVar14[5] & 2U) == 0 &&
                   (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0)) &&
                  ((iVar11 = FUN_00105594(piVar12,1), (*(uint *)(iVar11 + 0x14) & 0x40) != 0 &&
                   ((*(uint *)(param_1[7] + 0x14) & 0x40) != 0)))))) {
                FUN_00105594(piVar12,1);
              }
              param_1[0xe] = iVar13;
            }
            if (!bVar4) {
              iVar11 = FUN_00105594(piVar12,1);
              if (((((iVar11 != param_1[10]) && (iVar11 = FUN_00105594(piVar12,1), iVar11 != 0)) &&
                   ((param_1[10] != 0 &&
                    (((piVar14 = (int *)FUN_00105594(piVar12,1), piVar14[0x20] != 0 &&
                      (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0)) &&
                     ((piVar14[5] & 2U) == 0)))))) &&
                  ((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                   (piVar14 = (int *)param_1[10], piVar14[0x20] != 0)))) &&
                 ((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0 &&
                  ((((piVar14[5] & 2U) == 0 &&
                    (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0)) &&
                   ((iVar11 = FUN_00105594(piVar12,1), (*(uint *)(iVar11 + 0x14) & 0x40) != 0 &&
                    ((*(uint *)(param_1[10] + 0x14) & 0x40) != 0)))))))) {
                FUN_00105594(piVar12,1);
              }
              param_1[0x12] = iVar13;
            }
          }
          else {
            piVar14 = (int *)FUN_00105594(piVar12,1);
            if ((((piVar14[0x20] == 0) || (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0)) ||
                ((piVar14[5] & 2U) != 0)) ||
               (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0)) {
              piVar14 = (int *)FUN_00105594(piVar12,1);
              iVar11 = (**(code **)(*piVar14 + 0x50))();
              if (iVar11 != 0) goto LAB_00198950;
              piVar14 = (int *)FUN_00105594(piVar12,1);
              iVar15 = 0;
              iVar11 = (**(code **)(*piVar14 + 0x48))();
              if (iVar11 != 0) {
                iVar11 = FUN_00105594(piVar12,1);
                uVar22 = *(undefined4 *)(iVar11 + 0x94);
                uVar17 = FUN_00105594(piVar12,1);
                FUN_00196370(param_1,uVar22,uVar17);
                iVar15 = (**(code **)(*param_1 + 0xe0))(param_1,uVar22);
              }
            }
            else {
LAB_00198950:
              uVar22 = *(undefined4 *)(param_1[3] + 0x6c4);
              uVar17 = FUN_00105594(piVar12,1);
              iVar15 = thunk_FUN_00134de8(uVar22,uVar17);
            }
            piVar14 = (int *)FUN_00105594(piVar12,2);
            if (((piVar14[0x20] == 0) || (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0)) ||
               (((piVar14[5] & 2U) != 0 ||
                (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0)))) {
              piVar14 = (int *)FUN_00105594(piVar12,2);
              iVar11 = (**(code **)(*piVar14 + 0x50))();
              if (iVar11 != 0) goto LAB_00198a1c;
              piVar14 = (int *)FUN_00105594(piVar12,2);
              iVar16 = 0;
              iVar11 = (**(code **)(*piVar14 + 0x48))();
              if (iVar11 != 0) {
                iVar11 = FUN_00105594(piVar12,2);
                uVar22 = *(undefined4 *)(iVar11 + 0x94);
                uVar17 = FUN_00105594(piVar12,2);
                FUN_00196370(param_1,uVar22,uVar17);
                iVar16 = (**(code **)(*param_1 + 0xe0))(param_1,uVar22);
              }
            }
            else {
LAB_00198a1c:
              uVar22 = *(undefined4 *)(param_1[3] + 0x6c4);
              uVar17 = FUN_00105594(piVar12,2);
              iVar16 = thunk_FUN_00134de8(uVar22,uVar17);
            }
            if (bVar3) {
LAB_00198f54:
              bVar3 = false;
            }
            else {
              iVar11 = FUN_00105594(piVar12,1);
              if (((iVar11 != param_1[8]) &&
                  (((((iVar11 = FUN_00105594(piVar12,1), iVar11 == 0 || (param_1[8] == 0)) ||
                     ((piVar14 = (int *)FUN_00105594(piVar12,1), piVar14[0x20] == 0 ||
                      (((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0 ||
                        ((piVar14[5] & 2U) != 0)) ||
                       (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0)))))) ||
                    ((piVar14 = (int *)param_1[8], piVar14[0x20] == 0 ||
                     (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0)))) ||
                   (((piVar14[5] & 2U) != 0 ||
                    (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0 ||
                      (iVar11 = FUN_00105594(piVar12,1), (*(uint *)(iVar11 + 0x14) & 0x40) == 0)) ||
                     (((*(uint *)(param_1[8] + 0x14) & 0x40) == 0 ||
                      (iVar11 = FUN_00105594(piVar12,1),
                      *(int *)(iVar11 + 0x94) != *(int *)(param_1[8] + 0x94))))))))))) ||
                 ((iVar11 = FUN_00105594(piVar12,2), iVar11 != param_1[7] &&
                  ((((iVar11 = FUN_00105594(piVar12,2), iVar11 == 0 || (param_1[7] == 0)) ||
                    (piVar14 = (int *)FUN_00105594(piVar12,2), piVar14[0x20] == 0)) ||
                   (((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0 || ((piVar14[5] & 2U) != 0))
                    || ((((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0 ||
                          ((piVar14 = (int *)param_1[7], piVar14[0x20] == 0 ||
                           (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0)))) ||
                         ((piVar14[5] & 2U) != 0)) ||
                        ((((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0 ||
                           (iVar11 = FUN_00105594(piVar12,2), (*(uint *)(iVar11 + 0x14) & 0x40) == 0
                           )) || ((*(uint *)(param_1[7] + 0x14) & 0x40) == 0)) ||
                         (iVar11 = FUN_00105594(piVar12,2),
                         *(int *)(iVar11 + 0x94) != *(int *)(param_1[7] + 0x94))))))))))))) {
                iVar11 = FUN_00105594(piVar12,1);
                if (((iVar11 == param_1[7]) ||
                    ((((iVar11 = FUN_00105594(piVar12,1), iVar11 != 0 && (param_1[7] != 0)) &&
                      ((piVar14 = (int *)FUN_00105594(piVar12,1), piVar14[0x20] != 0 &&
                       ((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0 &&
                        ((piVar14[5] & 2U) == 0)))))) &&
                     (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                       ((((piVar14 = (int *)param_1[7], piVar14[0x20] != 0 &&
                          (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0)) &&
                         ((piVar14[5] & 2U) == 0)) &&
                        ((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                         (iVar11 = FUN_00105594(piVar12,1), (*(uint *)(iVar11 + 0x14) & 0x40) != 0))
                        )))) && (((*(uint *)(param_1[7] + 0x14) & 0x40) != 0 &&
                                 (iVar11 = FUN_00105594(piVar12,1),
                                 *(int *)(iVar11 + 0x94) == *(int *)(param_1[7] + 0x94))))))))) &&
                   ((iVar11 = FUN_00105594(piVar12,2), iVar11 == param_1[8] ||
                    (((((iVar11 = FUN_00105594(piVar12,2), iVar11 != 0 && (param_1[8] != 0)) &&
                       ((piVar14 = (int *)FUN_00105594(piVar12,2), piVar14[0x20] != 0 &&
                        (((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0 &&
                          ((piVar14[5] & 2U) == 0)) &&
                         (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0)))))) &&
                      ((piVar14 = (int *)param_1[8], piVar14[0x20] != 0 &&
                       (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0)))) &&
                     (((piVar14[5] & 2U) == 0 &&
                      (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                        (iVar11 = FUN_00105594(piVar12,2), (*(uint *)(iVar11 + 0x14) & 0x40) != 0))
                       && (((*(uint *)(param_1[8] + 0x14) & 0x40) != 0 &&
                           (iVar11 = FUN_00105594(piVar12,2),
                           *(int *)(iVar11 + 0x94) == *(int *)(param_1[8] + 0x94))))))))))))) {
                  param_1[0xe] = iVar15;
                  param_1[0xf] = iVar16;
                  if ((iVar13 == 0x9a) && (bVar3 = true, (piVar19[8] & 2U) == 0)) goto LAB_00198f58;
                }
                goto LAB_00198f54;
              }
              bVar3 = false;
              param_1[0xf] = iVar15;
              param_1[0xe] = iVar16;
            }
LAB_00198f58:
            if (bVar4) {
LAB_0019941c:
              bVar4 = false;
            }
            else {
              iVar11 = FUN_00105594(piVar12,1);
              if (((iVar11 != param_1[0xb]) &&
                  (((((((iVar11 = FUN_00105594(piVar12,1), iVar11 == 0 || (param_1[0xb] == 0)) ||
                       (piVar14 = (int *)FUN_00105594(piVar12,1), piVar14[0x20] == 0)) ||
                      ((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0 ||
                       ((piVar14[5] & 2U) != 0)))) ||
                     (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0)) ||
                    (((piVar14 = (int *)param_1[0xb], piVar14[0x20] == 0 ||
                      (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0)) ||
                     (((piVar14[5] & 2U) != 0 ||
                      (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0 ||
                        (iVar11 = FUN_00105594(piVar12,1), (*(uint *)(iVar11 + 0x14) & 0x40) == 0))
                       || ((*(uint *)(param_1[0xb] + 0x14) & 0x40) == 0)))))))) ||
                   (iVar11 = FUN_00105594(piVar12,1),
                   *(int *)(iVar11 + 0x94) != *(int *)(param_1[0xb] + 0x94))))) ||
                 ((iVar11 = FUN_00105594(piVar12,2), iVar11 != param_1[10] &&
                  ((((iVar11 = FUN_00105594(piVar12,2), iVar11 == 0 || (param_1[10] == 0)) ||
                    ((piVar14 = (int *)FUN_00105594(piVar12,2), piVar14[0x20] == 0 ||
                     ((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0 || ((piVar14[5] & 2U) != 0)
                      ))))) ||
                   (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0 ||
                     (((piVar14 = (int *)param_1[10], piVar14[0x20] == 0 ||
                       (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0)) ||
                      ((piVar14[5] & 2U) != 0)))) ||
                    (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0 ||
                      (iVar11 = FUN_00105594(piVar12,2), (*(uint *)(iVar11 + 0x14) & 0x40) == 0)) ||
                     (((*(uint *)(param_1[10] + 0x14) & 0x40) == 0 ||
                      (iVar11 = FUN_00105594(piVar12,2),
                      *(int *)(iVar11 + 0x94) != *(int *)(param_1[10] + 0x94))))))))))))) {
                iVar11 = FUN_00105594(piVar12,1);
                if (((iVar11 == param_1[10]) ||
                    ((((iVar11 = FUN_00105594(piVar12,1), iVar11 != 0 && (param_1[10] != 0)) &&
                      (((piVar14 = (int *)FUN_00105594(piVar12,1), piVar14[0x20] != 0 &&
                        ((((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0 &&
                           ((piVar14[5] & 2U) == 0)) &&
                          (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0)) &&
                         ((piVar14 = (int *)param_1[10], piVar14[0x20] != 0 &&
                          (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0)))))) &&
                       ((piVar14[5] & 2U) == 0)))) &&
                     (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                       (iVar11 = FUN_00105594(piVar12,1), (*(uint *)(iVar11 + 0x14) & 0x40) != 0))
                      && (((*(uint *)(param_1[10] + 0x14) & 0x40) != 0 &&
                          (iVar11 = FUN_00105594(piVar12,1),
                          *(int *)(iVar11 + 0x94) == *(int *)(param_1[10] + 0x94))))))))) &&
                   ((iVar11 = FUN_00105594(piVar12,2), iVar11 == param_1[0xb] ||
                    (((((iVar11 = FUN_00105594(piVar12,2), iVar11 != 0 && (param_1[0xb] != 0)) &&
                       (piVar14 = (int *)FUN_00105594(piVar12,2), piVar14[0x20] != 0)) &&
                      (((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0 &&
                        ((piVar14[5] & 2U) == 0)) &&
                       ((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                        ((piVar14 = (int *)param_1[0xb], piVar14[0x20] != 0 &&
                         (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0)))))))) &&
                     (((piVar14[5] & 2U) == 0 &&
                      ((((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                         (iVar11 = FUN_00105594(piVar12,2), (*(uint *)(iVar11 + 0x14) & 0x40) != 0))
                        && ((*(uint *)(param_1[0xb] + 0x14) & 0x40) != 0)) &&
                       (iVar11 = FUN_00105594(piVar12,2),
                       *(int *)(iVar11 + 0x94) == *(int *)(param_1[0xb] + 0x94))))))))))) {
                  param_1[0x12] = iVar15;
                  param_1[0x13] = iVar16;
                  if ((iVar13 == 0x9a) && (bVar4 = true, (piVar19[8] & 2U) == 0)) goto LAB_00199420;
                }
                goto LAB_0019941c;
              }
              bVar4 = false;
              param_1[0x13] = iVar15;
              param_1[0x12] = iVar16;
            }
LAB_00199420:
            if ((bVar3) || (bVar4)) {
              FUN_00103d50(piVar19 + 3,1,piVar19[8] & 1U ^ 1);
            }
          }
        }
LAB_0019a030:
        if (local_7c != 0) {
          if (bVar2) {
            (**(code **)(*param_1 + 0x10c))(param_1,iVar25,local_5c,local_80,iVar20);
          }
          if (bVar1) {
            (**(code **)(*param_1 + 0x108))(param_1,iVar25,local_dc,local_80,iVar20);
          }
          FUN_00106004(param_2,iVar25,local_80,0,param_1[3]);
          if (iVar25 == 0) {
            param_2[0x27] = iVar20;
          }
          else {
            iVar11 = FUN_001054ec(param_2,iVar25);
            *(int *)(iVar11 + 0x10) = iVar20;
          }
        }
      }
      iVar25 = iVar25 + 1;
      piVar19 = piVar19 + 6;
    } while (iVar25 <= iVar8);
  }
  else if (0 < iVar8) goto LAB_00198290;
  (**(code **)(*param_1 + 0x118))(param_1,param_1[0x20],param_1 + 0xd,param_1[0x21],param_1 + 0x11);
  (**(code **)(*param_1 + 0x11c))
            (param_1,param_2,local_6c,local_bc,local_dc,local_70,local_ec,local_5c);
  if (param_2[0x26] == 0x2c) {
LAB_0019a1f4:
    pcVar7 = *(code **)(*param_1 + 0x124);
  }
  else {
    if ((((param_2[0x20] != 0) && (iVar8 = FUN_00126760(param_2[0x26]), iVar8 != 0)) &&
        (((param_2[5] & 2U) == 0 && (iVar8 = (**(code **)(*param_2 + 0x50))(param_2), iVar8 == 0))))
       || (iVar8 = (**(code **)(*param_2 + 0x50))(param_2), iVar8 != 0)) {
      pcVar7 = *(code **)(*param_1 + 0x120);
      uVar17 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),param_2);
      (*pcVar7)(param_1,local_6c,local_70,param_2,uVar17);
      goto LAB_0019a230;
    }
    if ((param_2[5] & 2U) != 0) goto LAB_0019a1f4;
    if ((param_2[5] & 0x80000U) == 0) goto LAB_0019a230;
    pcVar7 = *(code **)(*param_1 + 0x128);
  }
  (*pcVar7)(param_1,local_6c,local_70,param_2);
LAB_0019a230:
  if (uVar6 != 0) {
    (**(code **)(*param_1 + 300))(param_1,local_f8,local_68,param_2);
  }
  if (uVar10 != 0) {
    (**(code **)(*param_1 + 0x130))(param_1,local_f4,local_68,param_2);
  }
  return;
}

/* FUN_0019a2e0 @ 0x19a2e0 (16 bytes) */
int FUN_0019a2e0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 < param_1) {
    return param_1;
  }
  return param_2;
}

/* FUN_0019a2f0 @ 0x19a2f0 (120 bytes) */
int FUN_0019a2f0(param_1)
  int param_1;
{
  **(undefined4 **)(param_1 + 0x50) =
       *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0x30c) + 0x40);
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0xc) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x10) = *(undefined4 *)(param_1 + 0x58);
  *(int *)(*(int *)(param_1 + 0x50) + 0x14) = *(int *)(param_1 + 0x34) + 1;
  *(int *)(*(int *)(param_1 + 0x50) + 0x18) = *(int *)(param_1 + 0x38) + 1;
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x20) = *(undefined4 *)(param_1 + 0x30);
  *(int *)(*(int *)(param_1 + 0x50) + 0x24) = *(int *)(param_1 + 0x4c) + 1;
  return;
}

/* FUN_0019a368 @ 0x19a368 (28 bytes) */
int FUN_0019a368(param_1)
  int param_1;
{
  *(undefined1 *)(*(int *)(param_1 + 0x58) * 0x10 + *(int *)(param_1 + 0x44) + 3) = 0;
  return;
}

/* FUN_0019a384 @ 0x19a384 (56 bytes) */
int FUN_0019a384(param_1)
  int param_1;
{
  ((int (*)())FUN_0019a368)(param_1);
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  return;
}

/* FUN_0019a3bc @ 0x19a3bc (172 bytes) */
int FUN_0019a3bc(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x5c) + *(int *)(param_1 + 0x58);
  FUN_000e0e0c(*(undefined4 *)(param_1 + 0xc),
               "Assembler : emits %d cf, %d alu -> %d total instruction(s)\n",
               *(int *)(param_1 + 0x5c),*(int *)(param_1 + 0x58),iVar1,param_6,param_7,param_8);
  FUN_000e0e0c(*(undefined4 *)(param_1 + 0xc),
               "INFO:# of control flow %d, # of exec %d instructions\n",
               *(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58),iVar1,param_6,param_7
               ,param_8);
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x78);
    iVar2 = 0;
    if (iVar1 != 0) {
      iVar2 = (*(int *)(param_1 + 0x74) * 100) / iVar1;
    }
    FUN_000e0e0c(*(undefined4 *)(param_1 + 0xc),
                 "Assembler : of %d candidate alu instruction(s), %d are packed (%%%d)\n",iVar1,
                 *(int *)(param_1 + 0x74),iVar2,param_6,param_7,param_8);
    return;
  }
  return;
}

/* FUN_0019a484 @ 0x19a484 (132 bytes) */
int FUN_0019a484(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  **(undefined4 **)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x5c);
  if (*(int *)(param_1 + 0x5c) < 1) {
    return;
  }
  iVar3 = 0;
  iVar4 = 0;
  do {
    iVar3 = iVar3 + 1;
    iVar8 = iVar4 + *(int *)(param_1 + 0x40);
    puVar1 = (undefined4 *)(iVar4 + *(int *)(param_1 + 0x40));
    uVar2 = *(undefined4 *)(iVar8 + 4);
    iVar6 = iVar4 + *(int *)(param_1 + 0x54);
    uVar7 = *(undefined4 *)(iVar8 + 8);
    uVar5 = *(undefined4 *)(iVar8 + 0xc);
    iVar4 = iVar4 + 0x1c;
    *(undefined4 *)(iVar6 + 4) = *puVar1;
    *(undefined4 *)(iVar6 + 8) = uVar2;
    *(undefined4 *)(iVar6 + 0xc) = uVar7;
    *(undefined4 *)(iVar6 + 0x10) = uVar5;
    uVar2 = *(undefined4 *)(iVar8 + 0x10);
    uVar5 = *(undefined4 *)(iVar8 + 0x14);
    *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)(iVar8 + 0x18);
    *(undefined4 *)(iVar6 + 0x14) = uVar2;
    *(undefined4 *)(iVar6 + 0x18) = uVar5;
  } while (iVar3 < *(int *)(param_1 + 0x5c));
  return;
}

/* FUN_0019a508 @ 0x19a508 (4 bytes) */
int FUN_0019a508()
{
  return;
}

/* FUN_0019a50c @ 0x19a50c (4 bytes) */
int FUN_0019a50c()
{
  return;
}

/* FUN_0019a510 @ 0x19a510 (40 bytes) */
int FUN_0019a510(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x58) * 0x10;
  iVar2 = iVar1 + *(int *)(param_1 + 0x44);
  *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x44)) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 8) = 0;
  return;
}

/* FUN_0019a538 @ 0x19a538 (48 bytes) */
int FUN_0019a538(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(uint *)(PTR_DAT_001e9140 + *(int *)(*(int *)(param_2 + 0x88) + 8) * 0x38) >> 2 & 1;
}

/* FUN_0019a568 @ 0x19a568 (176 bytes) */
int FUN_0019a568(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = (param_2 * 5 + *(int *)(param_1 + 0x1c)) * 4;
  iVar1 = *(int *)(&DAT_001e6668 + iVar2);
  iVar2 = *(int *)(&DAT_001e66cc + iVar2);
  *(int *)(param_1 + 0x1c) = iVar1;
  if (iVar1 == -1) {
    *(undefined4 *)(param_1 + 0x1c) = 2;
  }
  else if (iVar2 < 1) {
    if (iVar2 < 0) {
      iVar2 = -iVar2;
      iVar1 = *(int *)(param_1 + 0x58);
      do {
        iVar1 = iVar1 + -1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      *(int *)(param_1 + 0x58) = iVar1;
    }
  }
  else {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      ((int (*)())FUN_0019a384)(param_1);
    } while (iVar1 != iVar2);
  }
  return;
}

/* FUN_0019a618 @ 0x19a618 (120 bytes) */
int FUN_0019a618(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  
  FUN_000e0e0c(*(int *)(param_1 + 0xc),"next_sp = %d, max = %d\n",*(undefined4 *)(param_1 + 0x58),
               *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0x30c) + 0x40),param_5,param_6,
               param_7,param_8);
  if ((*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x30c) + 0x40) < *(int *)(param_1 + 0x58)) ||
     (uVar1 = 0, 0x10 < *(int *)(param_1 + 0x5c))) {
    uVar1 = 1;
  }
  return uVar1;
}

/* FUN_0019a690 @ 0x19a690 (16 bytes) */
int FUN_0019a690(param_1)
  int param_1;
{
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  return;
}

/* FUN_0019a6a0 @ 0x19a6a0 (80 bytes) */
int FUN_0019a6a0(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  FUN_000e2c78(param_2,param_1,param_1[3]);
                    
                    
  (**(code **)(*param_1 + 0x88))(param_1,param_2);
  return;
}

/* FUN_0019a6f0 @ 0x19a6f0 (192 bytes) */
int FUN_0019a6f0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  float fVar1;
  
  *param_3 = 0;
  if (3 < param_2) {
    if (param_2 < 6) {
      return 4;
    }
    if (param_2 == 6) {
      return 5;
    }
  }
  fVar1 = *(float *)(param_2 * 0x18 + param_1 + 0x20);
  if (fVar1 == FLOAT_001aa0e8) {
    return 5;
  }
  if ((fVar1 != FLOAT_001aa0d4) && (fVar1 == FLOAT_001aa114)) {
    *param_3 = 1;
    return 5;
  }
  return 4;
}

/* FUN_0019a7b0 @ 0x19a7b0 (92 bytes) */
int FUN_0019a7b0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 8);
  if (((param_2 != 2) && (puVar2 = (undefined4 *)(param_1 + 0xc), param_2 != 3)) &&
     (puVar2 = (undefined4 *)0x0, param_2 == 1)) {
    puVar2 = (undefined4 *)(param_1 + 4);
  }
  puVar1 = (undefined4 *)(param_1 + 8);
  if (((param_3 != 2) && (puVar1 = (undefined4 *)(param_1 + 0xc), param_3 != 3)) &&
     (puVar1 = (undefined4 *)0x0, param_3 == 1)) {
    puVar1 = (undefined4 *)(param_1 + 4);
  }
  *puVar1 = *puVar2;
  return;
}

/* FUN_0019a80c @ 0x19a80c (156 bytes) */
int FUN_0019a80c(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00105594(param_2,1);
  iVar2 = (**(code **)(*piVar1 + 0x50))();
  if ((iVar2 != 0) && (*(int *)(param_2 + 0x144) != 0)) {
    return;
  }
                    
                    
  (**(code **)(*param_1 + 0x38))(param_1,param_2,param_3,param_4);
  return;
}

/* FUN_0019a8a8 @ 0x19a8a8 (4 bytes) */
int FUN_0019a8a8()
{
  return;
}

/* FUN_0019a8ac @ 0x19a8ac (16 bytes) */
int FUN_0019a8ac(param_1)
  int *param_1;
{
                    
                    
  (**(code **)(*param_1 + 0x38))();
  return;
}

/* FUN_0019a8bc @ 0x19a8bc (16 bytes) */
int FUN_0019a8bc(param_1)
  int *param_1;
{
                    
                    
  (**(code **)(*param_1 + 0x38))();
  return;
}

/* FUN_0019a8d4 @ 0x19a8d4 (128 bytes) */
int FUN_0019a8d4(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if ((1 < *(int *)(param_2 + 0x130)) && (*(int *)(param_1 + 0x5c) != 0x10)) {
    iVar1 = *(int *)(param_2 + 300);
    *(int *)(param_1 + 0x70) = iVar1;
    *(undefined4 *)(iVar1 * 0xc + *(int *)(param_1 + 0x60)) = *(undefined4 *)(param_1 + 0x58);
    *(undefined4 *)(*(int *)(param_1 + 0x70) * 0xc + *(int *)(param_1 + 0x60) + 8) =
         *(undefined4 *)(param_1 + 0x1c);
    ((int (*)())FUN_0019a568)(param_1,3);
    *(undefined4 *)(param_1 + 100) = 1;
  }
  return;
}

/* FUN_0019a954 @ 0x19a954 (92 bytes) */
int FUN_0019a954(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 100) != 0) {
    ((int (*)())FUN_0019a568)(param_1,3);
    *(undefined4 *)(*(int *)(param_1 + 0x70) * 0xc + *(int *)(param_1 + 0x60) + 4) =
         *(undefined4 *)(param_1 + 0x58);
    *(undefined4 *)(param_1 + 100) = 1;
  }
  return;
}

/* FUN_0019a9b0 @ 0x19a9b0 (44 bytes) */
int FUN_0019a9b0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x58);
  iVar1 = *(int *)(param_1 + 0x5c) * 0x1c + *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
  *(undefined4 *)(iVar1 + 0x18) = param_3;
  *(undefined4 *)(iVar1 + 0x10) = uVar2;
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  return;
}

/* FUN_0019a9dc @ 0x19a9dc (160 bytes) */
int FUN_0019a9dc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if ((1 < *(int *)(param_2 + 0x130)) && (*(int *)(param_1 + 0x5c) != 0x10)) {
    *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x58);
    *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x1c);
    iVar1 = *(int *)(param_2 + 300);
    *(int *)(param_1 + 0x70) = iVar1;
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(iVar1 * 0xc + *(int *)(param_1 + 0x60));
    ((int (*)())FUN_0019a568)(param_1,4);
    iVar1 = *(int *)(param_1 + 0x70) * 0xc;
    ((int (*)())FUN_0019a9b0)(param_1,*(undefined4 *)(iVar1 + *(int *)(param_1 + 0x60)),
                 *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x60) + 4));
    *(undefined4 *)(param_1 + 100) = 1;
  }
  return;
}

/* FUN_0019aa7c @ 0x19aa7c (92 bytes) */
int FUN_0019aa7c(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 100) != 0) {
    ((int (*)())FUN_0019a568)(param_1,3);
    *(undefined4 *)(param_1 + 0x70) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x68);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x6c);
    *(undefined4 *)(param_1 + 100) = 0;
  }
  return;
}

/* FUN_0019aaf4 @ 0x19aaf4 (100 bytes) */
int FUN_0019aaf4(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x40))(param_2);
  if (iVar1 == 0) {
    FUN_000e1534(param_6,0xf);
    return;
  }
  return;
}

/* FUN_0019ab60 @ 0x19ab60 (100 bytes) */
int FUN_0019ab60(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x40))(param_2);
  if (iVar1 == 0) {
    FUN_000e1534(param_4,0xf);
    return;
  }
  return;
}

/* FUN_0019abc4 @ 0x19abc4 (100 bytes) */
int FUN_0019abc4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 300) + 0x40))();
  if (iVar1 == 0) {
    FUN_000e1534(param_4,0xf);
    return;
  }
  return;
}

/* FUN_0019ac2c @ 0x19ac2c (120 bytes) */
int FUN_0019ac2c(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  
  ((int (*)())FUN_0019a568)(param_1,4);
  iVar2 = *(int *)(param_1 + 0x5c) * 0x1c;
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
  iVar1 = iVar2 + *(int *)(param_1 + 0x40);
  *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x40)) = param_2;
  *(undefined4 *)(iVar1 + 8) = 0x35;
  *(undefined4 *)(iVar1 + 0xc) = param_3;
  iVar2 = *(int *)(param_1 + 0x58);
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(int *)(iVar1 + 0x10) = iVar2 + -2;
  return;
}

/* FUN_0019aca4 @ 0x19aca4 (4 bytes) */
int FUN_0019aca4()
{
  return;
}

/* FUN_0019acb0 @ 0x19acb0 (328 bytes) */
int FUN_0019acb0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  
  *(int *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_4 + 0x30c);
  iVar4 = *(int *)(param_4 + 0x324) << 4;
  iVar1 = *(int *)(*(int *)(param_4 + 0x30c) + 0x40) << 4;
  if (iVar4 < iVar1) {
    iVar4 = iVar1;
  }
  uVar2 = FUN_00193e18(*(undefined4 *)(param_4 + 0x374),iVar4);
  *(undefined4 *)(param_1 + 0x44) = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_4 + 0x374),*(int *)(param_4 + 0x324) * 0x38);
  *(undefined4 *)(param_1 + 0x40) = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_4 + 0x374),900);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x54) = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_4 + 0x374),*(int *)(param_4 + 0x324) << 3);
  *(undefined4 *)(param_1 + 8) = uVar2;
  pvVar3 = (void *)FUN_000e14e4(param_4,0x28,param_3);
  *(void **)(param_1 + 0x50) = pvVar3;
  _memset(pvVar3,0,0x28);
  **(int **)(param_1 + 0x50) = iVar4;
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 4) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 8) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x70) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  return;
}

/* FUN_0019adf8 @ 0x19adf8 (136 bytes) */
int FUN_0019adf8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3d4) = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc);
    if (*(int *)(iVar2 + 0x3d4) == 0) {
      *(undefined4 *)(iVar2 + 0x3d4) = 1;
      iVar2 = *(int *)(param_1 + 0xc);
    }
    iVar1 = *(int *)(iVar2 + 0x3d4);
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0x374),*(undefined4 *)(param_1 + 0x60));
    uVar3 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x374),iVar1 * 0xc);
    *(undefined4 *)(param_1 + 0x60) = uVar3;
  }
  return;
}

/* FUN_0019ae80 @ 0x19ae80 (104 bytes) */
int FUN_0019ae80(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x9c);
  uVar1 = FUN_000e7d5c(param_2);
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,uVar1,*(undefined4 *)(param_2 + 0x134));
  return;
}

/* FUN_0019aee8 @ 0x19aee8 (88 bytes) */
int FUN_0019aee8(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
                    
                    
  (**(code **)(*param_1 + 0xa0))(param_1,0);
  return;
}

/* FUN_0019af40 @ 0x19af40 (252 bytes) */
int FUN_0019af40(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = param_2[0x4e];
  iVar4 = FUN_00194034(iVar5 + 0x90);
  if ((iVar4 < 3) && (iVar4 = FUN_000e79e8(iVar5), iVar4 != 0)) {
    piVar2 = (int *)0x0;
    if (*(int *)(*(int *)(iVar5 + 0xd0) + 4) != 0) {
      piVar2 = *(int **)(*(int *)(iVar5 + 0xd0) + 8);
    }
    if (*piVar2 == param_2[0x4f]) {
      return;
    }
  }
  iVar4 = (**(code **)(*param_2 + 0x40))(param_2);
  if (iVar4 != 0) {
    piVar2 = (int *)0x0;
    iVar4 = *(int *)(*(int *)(param_1 + 0x10) + 0x24);
    uVar3 = *(uint *)(iVar4 + 4);
    uVar1 = uVar3 - 1;
    if (uVar1 < uVar3) {
      piVar2 = (int *)(uVar1 * 4 + *(int *)(iVar4 + 8));
    }
    iVar4 = *piVar2;
    ((int (*)())FUN_0019a568)(param_1,4);
    *(int *)(iVar4 + 0x14) = *(int *)(param_1 + 0x58) + -2;
    return;
  }
  FUN_000e1534(*(undefined4 *)(param_1 + 0xc),0xf);
  return;
}

/* FUN_0019b03c @ 0x19b03c (908 bytes) */
int FUN_0019b03c(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int *param_3;
  undefined4 *param_4;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  undefined4 uVar13;
  
  *param_4 = 0;
  piVar4 = (int *)0x0;
  if (param_3 != (int *)0x0) {
    piVar8 = (int *)0x0;
    piVar9 = (int *)0x0;
    bVar2 = false;
    bVar1 = true;
    piVar10 = param_3;
    do {
      uVar11 = piVar10[5];
      if ((uVar11 & 1) != 0) {
        if ((uVar11 & 4) != 0) {
          bVar2 = true;
        }
        iVar3 = ((int (*)())FUN_0019a538)(*(undefined4 *)(param_1 + 0x88),piVar10);
        if (iVar3 == 0) {
          if ((uVar11 & 0x10000) == 0) {
            piVar8 = piVar10;
          }
        }
        else {
          piVar9 = piVar10;
          if (piVar10[0x26] == 1) {
            iVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),piVar10);
            piVar4 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
            iVar5 = (**(code **)(*piVar4 + 0x138))(piVar4,0);
            if ((uint)(iVar3 - iVar5) < 4) {
              iVar3 = (**(code **)(*piVar10 + 0x14))(piVar10);
              if (1 < iVar3) {
                iVar3 = FUN_00105594(piVar10,1);
                iVar5 = *(int *)(iVar3 + 0x94);
                iVar3 = FUN_00105594(piVar10,2);
                if (iVar5 != *(int *)(iVar3 + 0x94)) goto LAB_0019b168;
              }
              uVar11 = piVar10[5];
              goto LAB_0019b144;
            }
LAB_0019b168:
            uVar11 = piVar10[5];
          }
          bVar1 = false;
        }
      }
LAB_0019b144:
      piVar10 = (int *)piVar10[2];
    } while ((piVar10 != (int *)0x0) && ((uVar11 & 4) != 0));
    piVar4 = param_3;
    if ((piVar8 != (int *)0x0) && (piVar9 != (int *)0x0)) {
      if (bVar1) {
        *param_4 = 1;
      }
      else if (bVar2) {
        *(int *)(*(int *)(param_1 + 0x10) + 0x14) = *(int *)(*(int *)(param_1 + 0x10) + 0x14) + 1;
        piVar4 = (int *)piVar10[1];
        iVar3 = param_3[0x56];
        if (piVar4 == piVar9) {
          *(uint *)(piVar9[1] + 0x14) = *(uint *)(piVar9[1] + 0x14) & 0xfffffffb;
        }
        else {
          piVar9[5] = piVar9[5] & 0xfffffffb;
          FUN_0019401c(piVar9);
          FUN_000e7738(iVar3,piVar4,piVar9);
        }
        for (iVar5 = 1; iVar6 = (**(code **)(*piVar9 + 0x14))(piVar9), piVar4 = piVar8,
            iVar5 <= iVar6; iVar5 = iVar5 + 1) {
          iVar12 = piVar8[0x26];
          iVar6 = FUN_00105594(piVar9,iVar5);
          if (iVar12 == *(int *)(iVar6 + 0x98)) {
            iVar6 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),piVar8);
            uVar13 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
            uVar7 = FUN_00105594(piVar9,iVar5);
            iVar12 = thunk_FUN_00134de8(uVar13,uVar7);
            if (iVar6 == iVar12) {
              iVar6 = 1;
              piVar4 = (int *)FUN_001043f0(0x31,*(undefined4 *)(param_1 + 0xc));
              uVar7 = FUN_00130690(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),0);
              iVar5 = FUN_001054ec(piVar4,0);
              *(undefined4 *)(iVar5 + 0xc) = 0;
              *(undefined4 *)(iVar5 + 8) = uVar7;
              FUN_00106004(piVar4,1,piVar8,0,*(undefined4 *)(param_1 + 0xc));
              FUN_000e7700(iVar3,piVar8,piVar4);
              *(int *)(*(int *)(param_1 + 0x10) + 0x18) =
                   *(int *)(*(int *)(param_1 + 0x10) + 0x18) + 1;
              if (piVar4 == (int *)0x0) {
                return piVar8;
              }
              for (; iVar3 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar6 <= iVar3;
                  iVar6 = iVar6 + 1) {
                iVar5 = piVar8[0x26];
                iVar3 = FUN_00105594(piVar9,iVar6);
                if (iVar5 == *(int *)(iVar3 + 0x98)) {
                  iVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),piVar8
                                            );
                  uVar13 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
                  uVar7 = FUN_00105594(piVar9,iVar6);
                  iVar5 = thunk_FUN_00134de8(uVar13,uVar7);
                  if (iVar3 == iVar5) {
                    FUN_00106004(piVar9,iVar6,piVar4,0,*(undefined4 *)(param_1 + 0xc));
                  }
                }
              }
              return piVar4;
            }
          }
        }
      }
    }
  }
  return piVar4;
}

/* FUN_0019b3c8 @ 0x19b3c8 (728 bytes) */
int FUN_0019b3c8(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int local_38 [9];
  
  piVar5 = *(int **)(param_2 + 8);
  if (piVar5[2] == 0) {
    return;
  }
  do {
    iVar3 = (**(code **)(*param_1 + 8))(param_1);
    if (iVar3 != 0) {
      FUN_000e1534(param_1[3],5);
    }
    iVar3 = param_1[3];
    if (**(int **)(iVar3 + 0x6c4) == 0) {
      piVar4 = (int *)FUN_000e3b88(param_1[4],param_2,piVar5,local_38);
      if ((piVar4 == (int *)0x0) || (local_38[0] == 0)) {
        iVar3 = param_1[3];
      }
      else {
        iVar3 = param_1[3];
        piVar5 = piVar4;
      }
    }
    piVar4 = piVar5;
    if (**(int **)(iVar3 + 0x6c4) == 0) {
      piVar4 = (int *)((int (*)())FUN_0019b03c)(param_1,param_2,piVar5,param_1 + 0x1f);
      iVar3 = param_1[3];
    }
    iVar3 = FUN_00106cf8(piVar4,*(undefined4 *)(iVar3 + 0x6c4));
    if ((((iVar3 == 0) || (uVar2 = piVar4[5], (uVar2 & 4) != 0)) || ((int)uVar2 < 0)) ||
       ((uVar2 & 0x1000) != 0)) {
      (**(code **)(*param_1 + 0xbc))(param_1);
      piVar6 = piVar4;
      piVar5 = piVar4;
      do {
        if (piVar5 == (int *)0x0) break;
        uVar2 = piVar6[5];
        if ((uVar2 & 1) != 0) {
          if ((uVar2 & 0x10000) == 0) {
            iVar3 = (**(code **)(*piVar6 + 0x68))(piVar6);
            if (iVar3 != 0) {
              piVar5 = (int *)FUN_00105594(piVar6,1);
              iVar3 = (**(code **)(*piVar5 + 0x50))();
              if ((iVar3 != 0) && (piVar6[0x51] != 0)) {
                return;
              }
            }
            ((int (*)())FUN_0019a568)(param_1,2);
            (**(code **)(*piVar6 + 0x1c))(piVar6,param_1,0,param_1[3]);
          }
          else {
            iVar3 = (**(code **)(*piVar6 + 0x48))(piVar6);
            if (iVar3 != 0) {
              (**(code **)(*param_1 + 0xc0))(param_1,piVar6,param_1[3]);
            }
          }
          (**(code **)(*piVar6 + 0x20))(piVar6,param_1,0,param_1[3]);
          uVar2 = piVar6[5];
        }
        piVar6 = (int *)piVar6[2];
        piVar5 = (int *)(uVar2 & 4);
      } while (piVar6 != (int *)0x0);
      iVar3 = (**(code **)(*piVar4 + 0x24))(piVar4);
      if (iVar3 == 0) {
        piVar6 = (int *)piVar4[2];
      }
      else {
        (**(code **)(*param_1 + 0xc4))(param_1);
        piVar6 = (int *)piVar4[2];
      }
    }
    else {
      *(int *)(param_1[4] + 0xc) = *(int *)(param_1[4] + 0xc) + 1;
      piVar6 = (int *)piVar4[2];
    }
    do {
      piVar5 = piVar6;
      puVar1 = (uint *)(piVar4 + 5);
      if ((int *)piVar5[2] == (int *)0x0) {
        return;
      }
      piVar6 = (int *)piVar5[2];
      piVar4 = piVar5;
    } while ((*puVar1 & 4) != 0);
  } while( true );
}

/* FUN_0019b6a0 @ 0x19b6a0 (168 bytes) */
int FUN_0019b6a0(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  ((int (*)())FUN_0019a568)(param_1,3);
  piVar3 = (int *)0x0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x28);
  uVar2 = *(uint *)(iVar1 + 4);
  if (uVar2 - 1 < uVar2) {
    piVar3 = (int *)((uVar2 - 1) * 4 + *(int *)(iVar1 + 8));
  }
  iVar4 = *piVar3;
  FUN_00194208(iVar1,uVar2 - 1);
  uVar2 = *(uint *)(iVar4 + 0x10);
  *(int *)(iVar4 + 0x18) = *(int *)(param_1 + 0x58) + -2;
  if (uVar2 < *(uint *)(param_1 + 0x2c)) {
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x58) + -1;
    uVar2 = *(uint *)(iVar4 + 0x10);
  }
  if (uVar2 < *(uint *)(param_1 + 0x30)) {
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x58) + -1;
  }
  return;
}

/* FUN_0019b748 @ 0x19b748 (192 bytes) */
int FUN_0019b748(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  ((int (*)())FUN_0019a568)(param_1,4);
  iVar1 = *(int *)(param_1 + 0x5c);
  *(int *)(param_1 + 0x5c) = iVar1 + 1;
  iVar5 = iVar1 * 0x1c + *(int *)(param_1 + 0x40);
  *(undefined4 *)(iVar5 + 8) = 0x3e;
  iVar1 = *(int *)(param_1 + 0x58);
  *(undefined4 *)(iVar5 + 0xc) = param_2;
  *(undefined4 *)(iVar5 + 4) = param_3;
  *(int *)(iVar5 + 0x10) = iVar1 + -2;
  puVar4 = *(uint **)(*(int *)(param_1 + 0x10) + 0x28);
  uVar3 = puVar4[1];
  if (uVar3 < *puVar4) {
    _memset((void *)(uVar3 * 4 + puVar4[2]),0,4);
    piVar2 = (int *)(uVar3 * 4 + puVar4[2]);
    puVar4[1] = uVar3 + 1;
  }
  else {
    piVar2 = (int *)FUN_0019423c(puVar4,uVar3);
  }
  *piVar2 = iVar5;
  return;
}

/* FUN_0019b808 @ 0x19b808 (180 bytes) */
int FUN_0019b808(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)0x0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x24);
  uVar2 = *(uint *)(iVar1 + 4);
  if (uVar2 - 1 < uVar2) {
    piVar3 = (int *)((uVar2 - 1) * 4 + *(int *)(iVar1 + 8));
  }
  iVar4 = *piVar3;
  FUN_00194208(iVar1,uVar2 - 1);
  *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(param_1 + 0x58);
  if (*(int *)(iVar4 + 0x14) == 0) {
    uVar2 = *(uint *)(iVar4 + 0x10);
    *(uint *)(iVar4 + 0x14) = uVar2;
  }
  else {
    uVar2 = *(uint *)(iVar4 + 0x10);
  }
  if (uVar2 < *(uint *)(param_1 + 0x2c)) {
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x58);
    uVar2 = *(uint *)(iVar4 + 0x10);
  }
  if (uVar2 < *(uint *)(param_1 + 0x30)) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x58);
  }
  ((int (*)())FUN_0019a568)(param_1,3);
  return;
}

/* FUN_0019b8bc @ 0x19b8bc (96 bytes) */
int FUN_0019b8bc(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x90);
  *puVar1 = uVar2;
  puVar1[1] = &PTR_FUN_001eb808;
  puVar1[7] = 0;
  return puVar1 + 1;
}

/* FUN_0019b91c @ 0x19b91c (124 bytes) */
int FUN_0019b91c(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001eb808;
  FUN_00193cc0(*(undefined4 *)(param_1[3] + 0x374),param_1[2]);
  param_1[2] = 0;
  FUN_00193cc0(*(undefined4 *)(param_1[3] + 0x374),param_1[0x18]);
  param_1[0x11] = 0;
  *param_1 = PTR_DAT_001e914c + 8;
  return;
}

/* FUN_0019b9ac @ 0x19b9ac (124 bytes) */
int FUN_0019b9ac(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001eb808;
  FUN_00193cc0(*(undefined4 *)(param_1[3] + 0x374),param_1[2]);
  param_1[2] = 0;
  FUN_00193cc0(*(undefined4 *)(param_1[3] + 0x374),param_1[0x18]);
  param_1[0x11] = 0;
  *param_1 = PTR_DAT_001e914c + 8;
  return;
}

/* FUN_0019ba3c @ 0x19ba3c (136 bytes) */
int FUN_0019ba3c(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *param_1 = &PTR_FUN_001eb808;
  FUN_00193cc0(*(undefined4 *)(param_1[3] + 0x374),param_1[2]);
  param_1[2] = 0;
  FUN_00193cc0(*(undefined4 *)(param_1[3] + 0x374),param_1[0x18]);
  puVar1 = PTR_DAT_001e914c;
  param_1[0x11] = 0;
  *param_1 = puVar1 + 8;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  iVar3 = param_1[-1];
  if ((*(int *)(iVar3 + 0x28) != 0) &&
     (puVar2 = *(undefined4 **)(iVar3 + 0x14), puVar2 == param_1 + -1)) {
    _memset(puVar2,0,*(int *)(iVar3 + 8) - (int)puVar2);
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0x14);
  }
  return;
}

/* FUN_0019baf4 @ 0x19baf4 (1596 bytes) */
int FUN_0019baf4(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint *param_3;
{
  bool bVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined4 uVar16;
  
  iVar4 = (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + 0x30c) + 0x16c))();
  iVar2 = *(int *)(param_2[0x22] + 8);
  iVar4 = *(int *)(iVar2 * 0x38 + iVar4 + 0xc);
  if (iVar2 == 0x32) {
    uVar15 = param_3[3];
    bVar1 = true;
    uVar12 = param_3[1];
    uVar14 = param_3[2] >> 0x10 & 7;
    uVar13 = uVar12 >> 0xd & 7;
    param_3[1] = uVar14 << 0x16 |
                 uVar14 << 0x13 | uVar14 << 0x10 | uVar14 << 0xd | param_3[2] & 0xfe001fff;
    *(byte *)((int)param_3 + 3) = (byte)iVar4 | 0x40;
    param_3[2] = uVar13 << 0x16 | uVar13 << 0x13 | uVar13 << 0x10 | uVar12 & 0xfe00ffff;
    param_3[3] = (uVar15 & 0xfff81fff) >> 3 & 0x380000 |
                 (uVar15 & 0xffff1fff) >> 6 & 0x70000 | uVar15 >> 9 & 0xe000 | uVar15 & 0xffc01fff;
  }
  else if (iVar4 == -1) {
    if (iVar2 < 0x32) {
      if (iVar2 < 0x30) {
        if (iVar2 == 0x1c) {
          bVar1 = true;
          *(undefined1 *)((int)param_3 + 3) = 1;
          param_3[1] = param_3[1] & 0xfe3fffff | 0x1000000;
          param_3[2] = param_3[2] & 0xfe3fffff | 0x1000000;
        }
        else {
          if (iVar2 != 0x28) goto LAB_0019bc7c;
          uVar12 = param_3[1];
          bVar1 = true;
          *(undefined1 *)((int)param_3 + 3) = 10;
          param_3[1] = param_3[2];
          param_3[2] = uVar12;
        }
      }
      else {
LAB_0019bbfc:
        bVar1 = false;
        *(undefined1 *)((int)param_3 + 3) = 7;
        param_3[2] = param_3[1];
      }
    }
    else {
      if (iVar2 == 0x66) goto LAB_0019bbfc;
      if (iVar2 != 0xa5) goto LAB_0019bc7c;
      bVar1 = true;
      *(undefined1 *)((int)param_3 + 3) = 5;
      param_3[3] = param_3[2];
    }
  }
  else {
    *(byte *)((int)param_3 + 3) = (byte)iVar4;
LAB_0019bc7c:
    bVar1 = true;
  }
  iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
  if (iVar2 != 3) goto LAB_0019bee4;
  piVar5 = (int *)FUN_00105594(param_2,1);
  iVar2 = (**(code **)(*piVar5 + 0x60))();
  if (iVar2 == 0) {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = FUN_00105594(param_2,1);
    iVar2 = thunk_FUN_00134de8(uVar16,uVar6);
    iVar7 = FUN_00105594(param_2,1);
    iVar7 = *(int *)(iVar7 + 0x98);
  }
  else {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = FUN_00105594(param_2,1);
    uVar6 = FUN_00105594(uVar6,1);
    iVar2 = thunk_FUN_00134de8(uVar16,uVar6);
    uVar6 = FUN_00105594(param_2,1);
    iVar7 = FUN_00105594(uVar6,1);
    iVar7 = *(int *)(iVar7 + 0x98);
  }
  piVar5 = (int *)FUN_00105594(param_2,2);
  iVar8 = (**(code **)(*piVar5 + 0x60))();
  if (iVar8 == 0) {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = FUN_00105594(param_2,2);
    iVar8 = thunk_FUN_00134de8(uVar16,uVar6);
    iVar9 = FUN_00105594(param_2,2);
    iVar9 = *(int *)(iVar9 + 0x98);
  }
  else {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = FUN_00105594(param_2,2);
    uVar6 = FUN_00105594(uVar6,1);
    iVar8 = thunk_FUN_00134de8(uVar16,uVar6);
    uVar6 = FUN_00105594(param_2,2);
    iVar9 = FUN_00105594(uVar6,1);
    iVar9 = *(int *)(iVar9 + 0x98);
  }
  piVar5 = (int *)FUN_00105594(param_2,3);
  iVar10 = (**(code **)(*piVar5 + 0x60))();
  if (iVar10 == 0) {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = FUN_00105594(param_2,3);
    iVar11 = thunk_FUN_00134de8(uVar16,uVar6);
    iVar10 = FUN_00105594(param_2,3);
    iVar10 = *(int *)(iVar10 + 0x98);
  }
  else {
    uVar16 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = FUN_00105594(param_2,3);
    uVar6 = FUN_00105594(uVar6,1);
    iVar11 = thunk_FUN_00134de8(uVar16,uVar6);
    uVar6 = FUN_00105594(param_2,3);
    iVar10 = FUN_00105594(uVar6,1);
    iVar10 = *(int *)(iVar10 + 0x98);
  }
  if (((((iVar7 != 0) || (iVar9 != 0)) || (iVar10 != 0)) || ((iVar2 == iVar8 || (iVar8 == iVar11))))
     || (iVar2 == iVar11)) goto LAB_0019bee4;
  uVar3 = 0;
  if (iVar4 == 4) {
LAB_0019bed0:
    *(undefined1 *)((int)param_3 + 3) = uVar3;
  }
  else if (iVar4 == 0xb) {
    uVar3 = 1;
    goto LAB_0019bed0;
  }
  *(byte *)((int)param_3 + 3) = (byte)*param_3 | 0x80;
LAB_0019bee4:
  iVar2 = ((int (*)())FUN_0019a538)(*(undefined4 *)(param_1 + 0x88),param_2);
  if ((iVar2 != 0) && (bVar1)) {
    *(byte *)((int)param_3 + 3) = (byte)*param_3 | 0x40;
  }
  iVar2 = param_2[0x26];
  if ((iVar2 == 5) && (param_2[0x25] == 0)) {
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x58);
    iVar2 = param_2[0x26];
  }
  *param_3 = (*(uint *)(&DAT_001b2ad0 + iVar2 * 4) & 0xf) << 8 | *param_3 & 0xfffff0ff;
  iVar2 = FUN_00105dbc(param_2,0);
  if (iVar2 == 1) {
    *(undefined4 *)(param_1 + 0x24) = 1;
    *param_3 = *param_3 | 0x1000;
    uVar13 = FUN_00105c5c(param_2,0);
    uVar12 = *param_3;
  }
  else if (iVar2 == 2) {
    uVar13 = 0;
    *(undefined4 *)(param_1 + 0x24) = 1;
    uVar12 = *param_3 & 0x1fffffff | 0x20000000;
    *param_3 = uVar12;
  }
  else {
    uVar12 = *param_3;
    uVar13 = 0;
  }
  if (((uVar12 & 0xf00) == 0x200) || ((uVar12 & 0xf00) == 0x300)) {
    if (iVar2 == 0) {
      uVar13 = uVar13 + param_2[0x25];
    }
    else {
      uVar13 = uVar13 + *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x6c4) + 0x3f0);
    }
  }
  else if (iVar2 == 0) {
    iVar2 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),param_2);
    iVar4 = param_2[0x26];
    uVar13 = uVar13 + iVar2;
    if (iVar4 == 1) {
      piVar5 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
      iVar2 = (**(code **)(*piVar5 + 0x138))(piVar5,0);
      uVar13 = uVar13 - iVar2;
      uVar6 = ((int (*)())FUN_0019a2e0)(*(undefined4 *)(param_1 + 0x38),uVar13);
      *(undefined4 *)(param_1 + 0x38) = uVar6;
      iVar4 = param_2[0x26];
    }
    if (iVar4 == 0) {
      uVar6 = ((int (*)())FUN_0019a2e0)(*(undefined4 *)(param_1 + 0x34),uVar13);
      *(undefined4 *)(param_1 + 0x34) = uVar6;
      uVar12 = *param_3;
    }
    else {
      uVar12 = *param_3;
    }
  }
  *param_3 = (uVar13 & 0x7f) << 0xd | uVar12 & 0xfff01fff;
  iVar2 = FUN_001054ec(param_2,0);
  uVar12 = *(uint *)(iVar2 + 0x10);
  uVar12 = (uint)((uVar12 & 0xff) == 0) << 0x17 |
           (uint)((uVar12 >> 8 & 0xff) == 0) << 0x16 |
           (uint)((uVar12 >> 0x10 & 0xff) == 0) << 0x15 |
           (uint)(uVar12 >> 0x18 == 0) << 0x14 | *param_3 & 0xff0fffff;
  *param_3 = uVar12;
  if (param_2[0x48] != 0) {
    iVar2 = ((int (*)())FUN_0019a538)(*(undefined4 *)(param_1 + 0x88),param_2);
    if ((iVar2 == 0) || (!bVar1)) {
      *param_3 = uVar12 | 0x1000000;
    }
    else {
      *param_3 = uVar12 | 0x2000000;
    }
  }
  return;
}

/* FUN_0019c130 @ 0x19c130 (2376 bytes) */
int FUN_0019c130(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  int iVar18;
  uint uVar19;
  uint *puVar20;
  uint local_88;
  uint local_84;
  int local_80;
  uint local_7c [4];
  uint local_6c [5];
  uint local_58;
  uint *local_54;
  
  puVar20 = (uint *)(param_3 + 8);
  if (((param_5 != 2) && (puVar20 = (uint *)(param_3 + 0xc), param_5 != 3)) &&
     (puVar20 = (uint *)0x0, param_5 == 1)) {
    puVar20 = (uint *)(param_3 + 4);
  }
  piVar10 = (int *)FUN_00105594(param_2,param_4);
  if (piVar10[0x26] == 0x33) {
    if (param_4 < 2) {
      *puVar20 = *puVar20 & 0xffffe018;
      *(undefined4 *)(param_1 + 0x80) = 1;
    }
    else {
      uVar6 = *puVar20;
      uVar19 = *(uint *)(param_3 + 4) & 7;
      *puVar20 = uVar19 | uVar6 & 0xfffffff8;
      uVar8 = *(uint *)(param_3 + 4) & 0x10;
      *puVar20 = uVar8 | uVar19 | uVar6 & 0xffffffe8;
      uVar12 = *(uint *)(param_3 + 4) & 0x80000000;
      *puVar20 = uVar12 | uVar8 | uVar19 | uVar6 & 0x7fffffe8;
      uVar9 = *(uint *)(param_3 + 4) & 0x60000000;
      *puVar20 = uVar9 | uVar12 | uVar8 | uVar19 | uVar6 & 0x1fffffe8;
      *puVar20 = *(uint *)(param_3 + 4) & 0x1fe0 |
                 uVar9 | uVar12 | uVar8 | uVar19 | uVar6 & 0x1fffe008;
    }
    iVar11 = FUN_001054ec(param_2,param_4);
    uVar19 = *(uint *)(iVar11 + 0x10);
    uVar8 = *(uint *)(param_4 * 0x18 + param_2 + 0xa0) & 1;
    iVar11 = ((int (*)())FUN_0019a538)(*(undefined4 *)(param_1 + 0x88),param_2);
    if (iVar11 != 0) {
      if (param_4 != 1) {
        uVar19 = uVar19 >> 0x18;
      }
      uVar12 = ((int (*)())FUN_0019a6f0)(piVar10,uVar19 & 0xff,&local_80);
      uVar6 = *puVar20;
      uVar12 = uVar12 & 7;
      uVar19 = uVar12 << 0xd;
      *puVar20 = uVar19 | uVar6 & 0xffff1fff;
      uVar9 = uVar8 ^ 1;
      if (local_80 == 0) {
        uVar9 = uVar8;
      }
      *puVar20 = uVar9 << 0x19 | uVar19 | uVar6 & 0xfdff1fff;
      *puVar20 = uVar9 << 0x1c |
                 uVar12 << 0x16 |
                 uVar9 << 0x1b |
                 uVar12 << 0x13 |
                 uVar9 << 0x1a | uVar12 << 0x10 | uVar9 << 0x19 | uVar19 | uVar6 & 0xe0001fff;
      return;
    }
    uVar12 = ((int (*)())FUN_0019a6f0)(piVar10,uVar19 >> 0x18,&local_80);
    uVar6 = *puVar20;
    uVar12 = (uVar12 & 7) << 0xd;
    *puVar20 = uVar12 | uVar6 & 0xffff1fff;
    uVar9 = uVar8 ^ 1;
    if (local_80 == 0) {
      uVar9 = uVar8;
    }
    *puVar20 = uVar9 << 0x19 | uVar12 | uVar6 & 0xfdff1fff;
    uVar12 = ((int (*)())FUN_0019a6f0)(piVar10,uVar19 >> 0x10 & 0xff,&local_80);
    uVar6 = *puVar20;
    uVar12 = (uVar12 & 7) << 0x10;
    *puVar20 = uVar12 | uVar6 & 0xfff8ffff;
    uVar9 = uVar8 ^ 1;
    if (local_80 == 0) {
      uVar9 = uVar8;
    }
    *puVar20 = uVar9 << 0x1a | uVar12 | uVar6 & 0xfbf8ffff;
    uVar12 = ((int (*)())FUN_0019a6f0)(piVar10,uVar19 >> 8 & 0xff,&local_80);
    uVar6 = *puVar20;
    uVar12 = (uVar12 & 7) << 0x13;
    *puVar20 = uVar12 | uVar6 & 0xffc7ffff;
    uVar9 = uVar8 ^ 1;
    if (local_80 == 0) {
      uVar9 = uVar8;
    }
    *puVar20 = uVar9 << 0x1b | uVar12 | uVar6 & 0xf7c7ffff;
    uVar19 = ((int (*)())FUN_0019a6f0)(piVar10,uVar19 & 0xff,&local_80);
    uVar9 = *puVar20;
    uVar19 = (uVar19 & 7) << 0x16;
    *puVar20 = uVar19 | uVar9 & 0xfe3fffff;
    uVar12 = uVar8 ^ 1;
    if (local_80 == 0) {
      uVar12 = uVar8;
    }
    *puVar20 = uVar12 << 0x1c | uVar19 | uVar9 & 0xee3fffff;
    return;
  }
  iVar11 = (**(code **)(*piVar10 + 0x60))();
  if (iVar11 == 0) {
    iVar11 = FUN_00105dbc(param_2,param_4);
    iVar13 = piVar10[0x26];
    uVar17 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    piVar14 = piVar10;
LAB_0019c490:
    uVar19 = thunk_FUN_00134de8(uVar17,piVar14);
    *puVar20 = *(uint *)(&DAT_001b2c14 + iVar13 * 4) & 7 | *puVar20 & 0xfffffff8;
    if (iVar13 == 0x37) {
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x58);
    }
    else if (iVar13 == 1) {
      piVar14 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
      iVar15 = (**(code **)(*piVar14 + 0x138))(piVar14,0);
      uVar19 = uVar19 - iVar15;
    }
  }
  else {
    iVar11 = FUN_00105dbc(piVar10,1);
    iVar13 = FUN_00105594(piVar10,1);
    iVar13 = *(int *)(iVar13 + 0x98);
    if (iVar13 != 0x33) {
      uVar17 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
      piVar14 = (int *)FUN_00105594(piVar10,1);
      goto LAB_0019c490;
    }
    if (param_4 < 2) {
      uVar19 = 0;
      *puVar20 = *puVar20 & 0xfffffff8;
      *(undefined4 *)(param_1 + 0x80) = 1;
    }
    else {
      uVar6 = *puVar20;
      uVar8 = *(uint *)(param_3 + 4) & 7;
      *puVar20 = uVar8 | uVar6 & 0xfffffff8;
      uVar12 = *(uint *)(param_3 + 4) & 0x10;
      uVar19 = *(uint *)(param_3 + 4) >> 5 & 0xff;
      *puVar20 = uVar12 | uVar8 | uVar6 & 0xffffffe8;
      uVar9 = *(uint *)(param_3 + 4) & 0x80000000;
      *puVar20 = uVar9 | uVar12 | uVar8 | uVar6 & 0x7fffffe8;
      *puVar20 = *(uint *)(param_3 + 4) & 0x60000000 | uVar9 | uVar12 | uVar8 | uVar6 & 0x1fffffe8;
    }
  }
  iVar15 = FUN_00126708(piVar10[0x26]);
  iVar16 = (**(code **)(*piVar10 + 0x60))(piVar10);
  if (iVar16 != 0) {
    iVar15 = FUN_00105594(piVar10,1);
    if (iVar15 == 0) {
      iVar15 = piVar10[0x2c];
    }
    else {
      iVar15 = FUN_00105594(piVar10,1);
      iVar15 = *(int *)(iVar15 + 0x98);
    }
    iVar15 = FUN_00126708(iVar15);
  }
  if ((iVar15 != 0) && (*(uint *)(param_1 + 0x4c) < uVar19)) {
    *(uint *)(param_1 + 0x4c) = uVar19;
  }
  if (iVar11 - 1U < 2) {
    iVar11 = (**(code **)(*piVar10 + 0x60))(piVar10);
    if (iVar11 == 0) {
      uVar19 = FUN_00105c5c(param_2,param_4);
    }
    else {
      uVar19 = FUN_00105c5c(piVar10,1);
    }
    *(undefined4 *)(param_1 + 0x24) = 1;
    if (iVar13 == 0x28) {
      *(undefined4 *)(param_1 + 0x4c) = 0xff;
    }
    else if (iVar13 != 0x29) {
      if (iVar13 == 0x26) {
        *(undefined4 *)(param_1 + 0x4c) = 0xff;
        *puVar20 = *puVar20 | 0x10;
        iVar11 = (**(code **)(*piVar10 + 0x60))(piVar10);
        if (iVar11 == 0) {
          iVar11 = FUN_001054ec(piVar10,1);
          uVar17 = *(undefined4 *)(iVar11 + 0x10);
        }
        else {
          uVar17 = FUN_00105594(piVar10,1);
          iVar11 = FUN_001054ec(uVar17,1);
          uVar17 = *(undefined4 *)(iVar11 + 0x10);
        }
        iVar11 = FUN_000f2d18(uVar17,DAT_001b2d38);
        if (iVar11 != 0) {
          uVar8 = *puVar20 & 0x9fffffff;
          *puVar20 = uVar8;
          goto LAB_0019c710;
        }
        iVar11 = FUN_000f2d18(uVar17,DAT_001b2d34);
        if (iVar11 != 0) {
          uVar8 = *puVar20 & 0x9fffffff | 0x20000000;
          *puVar20 = uVar8;
          goto LAB_0019c710;
        }
        iVar11 = FUN_000f2d18(uVar17,DAT_001b2d30);
        if (iVar11 != 0) {
          uVar8 = *puVar20 & 0x9fffffff | 0x40000000;
          *puVar20 = uVar8;
          goto LAB_0019c710;
        }
        iVar11 = FUN_000f2d18(uVar17,DAT_001b2d2c);
        if (iVar11 != 0) {
          uVar8 = *puVar20 & 0x9fffffff | 0x60000000;
          *puVar20 = uVar8;
          goto LAB_0019c710;
        }
      }
      goto LAB_0019c70c;
    }
    uVar8 = *puVar20 & 0x9fffffff | 0x80000000;
    *puVar20 = uVar8;
  }
  else {
LAB_0019c70c:
    uVar8 = *puVar20;
  }
LAB_0019c710:
  *puVar20 = (uVar19 & 0xff) << 5 | uVar8 & 0xffffe01f;
  uVar19 = *(uint *)(param_4 * 0x18 + param_2 + 0xa0) & 1;
  iVar11 = FUN_001054ec(param_2,param_4);
  local_88 = *(uint *)(iVar11 + 0x10);
  iVar11 = (**(code **)(*piVar10 + 0x60))(piVar10);
  if (iVar11 == 0) {
    local_7c[0] = *(uint *)(&DAT_001b2be8 + (local_88 >> 0x18) * 4);
    local_7c[2] = *(uint *)(&DAT_001b2be8 + (local_88 >> 8 & 0xff) * 4);
    local_7c[3] = *(uint *)(&DAT_001b2be8 + (local_88 & 0xff) * 4);
    local_7c[1] = *(uint *)(&DAT_001b2be8 + (local_88 >> 0x10 & 0xff) * 4);
    local_6c[0] = uVar19;
    local_6c[1] = uVar19;
    local_6c[2] = uVar19;
    local_6c[3] = uVar19;
  }
  else {
    iVar11 = FUN_001054ec(piVar10,1);
    local_84 = local_88;
    FUN_000f2bdc(&local_58,*(undefined4 *)(iVar11 + 0x10),local_88);
    local_88 = local_58;
    iVar15 = 0;
    iVar11 = 0;
    local_54 = local_7c;
    do {
      bVar2 = *(byte *)((int)&local_84 + iVar15);
      if (bVar2 != 4) {
        if ((iVar13 == 0x33) || (bVar3 = *(byte *)((int)&local_88 + iVar15), bVar3 == 4)) {
          if (0 < piVar10[0x21]) {
            iVar16 = 1;
            do {
              iVar18 = FUN_001054ec(piVar10,iVar16);
              uVar8 = (uint)*(byte *)((uint)bVar2 + iVar18 + 0x10);
              if (uVar8 != 4) {
                uVar17 = FUN_00105594(piVar10,iVar16);
                uVar17 = ((int (*)())FUN_0019a6f0)(uVar17,uVar8,&local_80);
                *(undefined4 *)(iVar11 + (int)local_54) = uVar17;
                uVar8 = uVar19;
                if (local_80 != 0) {
                  uVar8 = (uint)(uVar19 == 0);
                }
                *(uint *)((int)local_6c + iVar11) = uVar8;
                break;
              }
              iVar16 = iVar16 + 1;
            } while (iVar16 <= piVar10[0x21]);
          }
        }
        else {
          *(uint *)((int)local_6c + iVar11) = uVar19;
          *(undefined4 *)(iVar11 + (int)local_7c) = *(undefined4 *)(&DAT_001b2be8 + (uint)bVar3 * 4)
          ;
        }
      }
      bVar1 = iVar15 != 3;
      iVar11 = iVar11 + 4;
      iVar15 = iVar15 + 1;
    } while (bVar1);
  }
  iVar11 = ((int (*)())FUN_0019a538)(*(undefined4 *)(param_1 + 0x88),param_2);
  if (iVar11 == 0) {
    uVar7 = *puVar20;
    uVar19 = (local_7c[0] & 7) << 0xd;
    *puVar20 = uVar19 | uVar7 & 0xffff1fff;
    uVar8 = (local_7c[1] & 7) << 0x10;
    *puVar20 = uVar8 | uVar19 | uVar7 & 0xfff81fff;
    uVar12 = (local_7c[2] & 7) << 0x13;
    *puVar20 = uVar12 | uVar8 | uVar19 | uVar7 & 0xffc01fff;
    uVar9 = (local_7c[3] & 7) << 0x16;
    *puVar20 = uVar9 | uVar12 | uVar8 | uVar19 | uVar7 & 0xfe001fff;
    uVar6 = (local_6c[0] & 1) << 0x19;
    *puVar20 = uVar6 | uVar9 | uVar12 | uVar8 | uVar19 | uVar7 & 0xfc001fff;
    uVar4 = (local_6c[1] & 1) << 0x1a;
    *puVar20 = uVar4 | uVar6 | uVar9 | uVar12 | uVar8 | uVar19 | uVar7 & 0xf8001fff;
    uVar5 = (local_6c[2] & 1) << 0x1b;
    *puVar20 = uVar5 | uVar4 | uVar6 | uVar9 | uVar12 | uVar8 | uVar19 | uVar7 & 0xf0001fff;
    uVar19 = (local_6c[3] & 1) << 0x1c |
             uVar5 | uVar4 | uVar6 | uVar9 | uVar12 | uVar8 | uVar19 | uVar7 & 0xe0001fff;
    *puVar20 = uVar19;
  }
  else {
    if (param_4 == 1) {
      uVar8 = *puVar20;
      uVar19 = (local_7c[3] & 7) << 0xd;
      *puVar20 = uVar19 | uVar8 & 0xffff1fff;
      uVar19 = (local_6c[3] & 1) << 0x19 | uVar19 | uVar8 & 0xfdff1fff;
      *puVar20 = uVar19;
    }
    else if (param_4 == 2) {
      uVar8 = *puVar20;
      uVar19 = (local_7c[0] & 7) << 0xd;
      *puVar20 = uVar19 | uVar8 & 0xffff1fff;
      uVar19 = (local_6c[0] & 1) << 0x19 | uVar19 | uVar8 & 0xfdff1fff;
      *puVar20 = uVar19;
    }
    else {
      uVar19 = *puVar20;
    }
    uVar19 = (uVar19 & 0x2000000) << 3 |
             (uVar19 & 0x2000000) << 2 |
             (uVar19 & 0x2000000) << 1 |
             (uVar19 & 0xe000) << 9 |
             (uVar19 & 0xe000) << 6 | (uVar19 & 0xe000) << 3 | uVar19 & 0xe200ffff;
    *puVar20 = uVar19;
  }
  if ((*(int *)(param_1 + 0x84) != 0) && ((uVar19 & 0x80000010) == 0)) {
    uVar8 = *(uint *)(param_3 + 0xc);
    *(uint *)(param_3 + 0xc) = uVar19 & 3 | uVar8 & 0xfffffffc;
    *(uint *)(param_3 + 0xc) = *puVar20 & 0x1fe0 | uVar19 & 3 | uVar8 & 0xffffe01c;
  }
  if ((*(int *)(param_1 + 0x80) != 0) && (param_4 == 2)) {
    uVar9 = *(uint *)(param_3 + 4);
    uVar19 = *puVar20 & 7;
    *(uint *)(param_3 + 4) = uVar19 | uVar9 & 0xfffffff8;
    uVar8 = *puVar20 & 0x1fe0;
    *(uint *)(param_3 + 4) = uVar8 | uVar19 | uVar9 & 0xffffe018;
    uVar12 = *puVar20 & 0x10;
    *(uint *)(param_3 + 4) = uVar12 | uVar8 | uVar19 | uVar9 & 0xffffe008;
    uVar6 = *puVar20;
    *(uint *)(param_3 + 4) = uVar6 & 0x80000000 | uVar12 | uVar8 | uVar19 | uVar9 & 0x7fffe008;
    *(uint *)(param_3 + 4) =
         *puVar20 & 0x60000000 | uVar6 & 0x80000000 | uVar12 | uVar8 | uVar19 | uVar9 & 0x1fffe008;
  }
  return;
}

/* FUN_0019ca78 @ 0x19ca78 (1916 bytes) */
int FUN_0019ca78(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint *param_3;
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  uint *puVar10;
  undefined4 uVar11;
  int local_48 [4];
  uint local_38;
  uint local_34 [2];
  
  puVar10 = param_3 + 3;
  *param_3 = *param_3 | 0x10000000;
  FUN_00105dbc(param_2,1);
  iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
  if (iVar3 == 2) {
    FUN_00105dbc(param_2,2);
  }
  piVar4 = (int *)FUN_00105594(param_2,1);
  iVar3 = (**(code **)(*piVar4 + 0x60))();
  if (iVar3 == 0) {
    iVar3 = piVar4[0x26];
  }
  else {
    iVar3 = FUN_00105594(piVar4,1);
    iVar3 = *(int *)(iVar3 + 0x98);
  }
  if (iVar3 == 0x37) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x58);
  }
  iVar5 = (**(code **)(*piVar4 + 0x60))(piVar4);
  if (iVar5 == 0) {
    uVar7 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),piVar4);
  }
  else {
    uVar11 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4);
    uVar6 = FUN_00105594(piVar4,1);
    uVar7 = thunk_FUN_00134de8(uVar11,uVar6);
  }
  if (iVar3 == 1) {
    piVar8 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
    iVar5 = (**(code **)(*piVar8 + 0x138))(piVar8,0);
    uVar7 = uVar7 - iVar5;
    uVar6 = ((int (*)())FUN_0019a2e0)(*(undefined4 *)(param_1 + 0x38),uVar7);
    *(undefined4 *)(param_1 + 0x38) = uVar6;
  }
  else if (iVar3 == 0) {
    uVar6 = ((int (*)())FUN_0019a2e0)(*(undefined4 *)(param_1 + 0x34),uVar7);
    *(undefined4 *)(param_1 + 0x34) = uVar6;
  }
  uVar2 = param_2[0x2e];
  if ((uVar2 & 2) == 0) {
    uVar9 = *puVar10;
  }
  else {
    uVar9 = *puVar10 | 8;
    *puVar10 = uVar9;
    uVar2 = param_2[0x2e];
  }
  if ((uVar2 & 1) != 0) {
    uVar9 = uVar9 | 0x2000000;
    *puVar10 = uVar9;
  }
  if ((param_2[0x34] & 1U) != 0) {
    uVar9 = uVar9 | 0x4000000;
    *puVar10 = uVar9;
  }
  if (piVar4[0x26] == 0x33) {
    uVar7 = param_3[1];
    if ((uVar7 & 0x80000010) == 0) {
      *puVar10 = uVar7 & 3 | uVar9 & 0xfffffffc;
      *puVar10 = param_3[1] & 0x1fe0 | uVar7 & 3 | uVar9 & 0xffffe01c;
    }
    else {
      uVar2 = param_3[2];
      if ((uVar2 & 0x80000010) == 0) {
        *puVar10 = uVar2 & 3 | uVar9 & 0xfffffffc;
        *puVar10 = param_3[2] & 0x1fe0 | uVar2 & 3 | uVar9 & 0xffffe01c;
      }
      else if (((uVar7 & 7) == 0) && ((uVar2 & 7) == 0)) {
        *puVar10 = uVar9 & 0xffffe01c | 2;
      }
      else {
        *puVar10 = uVar9 & 0xffffe01c;
      }
    }
    *(undefined4 *)(param_1 + 0x84) = 1;
    iVar3 = FUN_001054ec(param_2,1);
    uVar7 = ((int (*)())FUN_0019a6f0)(piVar4,(uint)*(byte *)(iVar3 + 0x13),local_48);
    uVar2 = *puVar10;
    uVar7 = (uVar7 & 7) << 0xd;
    *puVar10 = uVar7 | uVar2 & 0xffff1fff;
    uVar9 = uVar2 >> 0x19 & 1;
    if (local_48[0] != 0) {
      uVar9 = 1 - uVar9;
    }
    *puVar10 = (uVar9 & 1) << 0x19 | uVar7 | uVar2 & 0xfdff1fff;
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (1 < iVar3) {
      uVar6 = FUN_00105594(param_2,2);
      iVar3 = FUN_001054ec(param_2,2);
      uVar7 = ((int (*)())FUN_0019a6f0)(uVar6,(uint)*(byte *)(iVar3 + 0x10),local_48);
      uVar2 = *puVar10;
      uVar7 = (uVar7 & 7) << 0x10;
      *puVar10 = uVar7 | uVar2 & 0xfff8ffff;
      uVar9 = uVar2 >> 0x1a & 1;
      if (local_48[0] != 0) {
        uVar9 = 1 - uVar9;
      }
      *puVar10 = (uVar9 & 1) << 0x1a | uVar7 | uVar2 & 0xfbf8ffff;
    }
    goto LAB_0019d024;
  }
  *puVar10 = *(uint *)(&DAT_001b2c14 + iVar3 * 4) & 3 | uVar9 & 0xfffffffc;
  iVar3 = (**(code **)(*piVar4 + 0x60))(piVar4);
  if (iVar3 == 0) {
    iVar3 = FUN_00126708(piVar4[0x26]);
  }
  else {
    iVar3 = FUN_00105594(piVar4,1);
    iVar3 = FUN_00126708(*(undefined4 *)(iVar3 + 0x98));
  }
  if ((iVar3 != 0) && (*(uint *)(param_1 + 0x4c) < uVar7)) {
    *(uint *)(param_1 + 0x4c) = uVar7;
  }
  *puVar10 = (uVar7 & 0xff) << 5 | *puVar10 & 0xffffe01f;
  iVar3 = FUN_001054ec(param_2,1);
  uVar2 = *(uint *)(iVar3 + 0x10);
  iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
  uVar7 = uVar2;
  if (1 < iVar3) {
    iVar3 = FUN_001054ec(param_2,2);
    uVar7 = *(uint *)(iVar3 + 0x10);
  }
  iVar3 = (**(code **)(*piVar4 + 0x60))(piVar4);
  if (iVar3 == 0) {
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar3 < 2) {
      uVar2 = *(uint *)(&DAT_001b2be8 + (uVar2 & 0xff) * 4);
      uVar7 = uVar2;
    }
    else {
      uVar2 = *(uint *)(&DAT_001b2be8 + (uVar2 & 0xff) * 4);
      uVar7 = *(uint *)(&DAT_001b2be8 + (uVar7 >> 0x16 & 0x3fc));
    }
  }
  else {
    iVar3 = FUN_001054ec(piVar4,1);
    uVar6 = *(undefined4 *)(iVar3 + 0x10);
    FUN_000f2bdc(&local_38,uVar6,uVar2);
    if (((uVar2 & 0xff) == 4) || ((local_38 & 0xff) == 4)) {
      iVar3 = 1;
      if (0 < piVar4[0x21]) {
        do {
          iVar5 = FUN_001054ec(piVar4,iVar3);
          bVar1 = *(byte *)(iVar5 + 0x13);
          if (bVar1 != 4) {
            uVar11 = FUN_00105594(piVar4,iVar3);
            uVar2 = ((int (*)())FUN_0019a6f0)(uVar11,(uint)bVar1,local_48);
            goto LAB_0019cf10;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 <= piVar4[0x21]);
      }
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint *)(&DAT_001b2be8 + (local_38 & 0xff) * 4);
    }
LAB_0019cf10:
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (1 < iVar3) {
      FUN_000f2bdc(local_34,uVar6,uVar7);
      if ((uVar7 >> 0x18 != 4) && (local_34[0] >> 0x18 != 4)) {
        uVar7 = *(uint *)(&DAT_001b2be8 + (local_34[0] >> 0x18) * 4);
        goto LAB_0019d014;
      }
      iVar3 = 1;
      if (0 < piVar4[0x21]) {
        do {
          iVar5 = FUN_001054ec(piVar4,iVar3);
          bVar1 = *(byte *)(iVar5 + 0x10);
          if (bVar1 != 4) {
            uVar6 = FUN_00105594(piVar4,iVar3);
            uVar7 = ((int (*)())FUN_0019a6f0)(uVar6,(uint)bVar1,local_48);
            goto LAB_0019d014;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 <= piVar4[0x21]);
      }
    }
    uVar7 = 0;
  }
LAB_0019d014:
  *puVar10 = (uVar7 & 7) << 0x10 | (uVar2 & 7) << 0xd | *puVar10 & 0xfff81fff;
LAB_0019d024:
  iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + 0x30c) + 0x16c))();
  uVar7 = *(uint *)(*(int *)(param_2[0x22] + 8) * 0x38 + iVar3 + 0xc);
  if (uVar7 == 0xffffffff) {
    if (*(int *)(param_2[0x22] + 8) == 0x66) {
      *puVar10 = *puVar10 & 0xfe18ffff | 0x1450000;
    }
  }
  else {
    uVar2 = (uVar7 & 0xf) << 0x15 | *puVar10 & 0xfe1fffff;
    *puVar10 = uVar2;
    if (0xf < (int)uVar7) {
      *puVar10 = uVar2 | 4;
    }
  }
  iVar3 = FUN_001054ec(param_2,0);
  iVar3 = *(int *)(iVar3 + 0x10);
  if (iVar3 == DAT_001b2c10) {
    *puVar10 = *puVar10 & 0xe7ffffff;
  }
  else if (iVar3 == DAT_001b2c0c) {
    *puVar10 = *puVar10 & 0xe7ffffff | 0x8000000;
  }
  else if (iVar3 == DAT_001b2c08) {
    *puVar10 = *puVar10 & 0xe7ffffff | 0x10000000;
  }
  else if (iVar3 == DAT_001b2c04) {
    *puVar10 = *puVar10 & 0xe7ffffff | 0x18000000;
  }
  iVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),param_2);
  piVar4 = *(int **)(*(int *)(param_1 + 0xc) + 0x30c);
  iVar5 = (**(code **)(*piVar4 + 0x138))(piVar4,0);
  *puVar10 = (iVar3 - iVar5) * 0x80000 & 0x180000U | *puVar10 & 0xffe7ffff;
  if (param_2[0x48] != 0) {
    (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + 0x30c) + 0x80))();
    *param_3 = *param_3 | 0x2000000;
  }
  return;
}

/* FUN_0019d1f4 @ 0x19d1f4 (572 bytes) */
int FUN_0019d1f4(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar1 = *(int *)(param_1 + 0x58) * 8;
  if (*(int *)(iVar2 + iVar1) == 0) {
    *(int **)(iVar2 + iVar1) = param_2;
  }
  else {
    *(int **)(iVar2 + iVar1 + 4) = param_2;
  }
  puVar3 = (uint *)(*(int *)(param_1 + 0x58) * 0x10 + *(int *)(param_1 + 0x44));
  iVar1 = ((int (*)())FUN_0019a538)(*(undefined4 *)(param_1 + 0x88),param_2);
  if ((iVar1 == 0) || (*(int *)(param_1 + 0x7c) == 0)) {
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(undefined4 *)(param_1 + 0x80) = 0;
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (0 < iVar1) {
      ((int (*)())FUN_0019c130)(param_1,param_2,puVar3,1,1);
    }
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar1 < 2) {
      ((int (*)())FUN_0019a7b0)(puVar3,1,2);
    }
    else {
      ((int (*)())FUN_0019c130)(param_1,param_2,puVar3,2,2);
    }
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar1 < 3) {
      if (*(int *)(param_1 + 0x7c) == 0) {
        ((int (*)())FUN_0019a7b0)(puVar3,2,3);
      }
    }
    else {
      ((int (*)())FUN_0019c130)(param_1,param_2,puVar3,3,3);
    }
    ((int (*)())FUN_0019baf4)(param_1,param_2,puVar3);
  }
  else {
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (1 < iVar1) {
      FUN_00105594(param_2,1);
      FUN_00105594(param_2,2);
    }
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (0 < iVar1) {
      iVar1 = FUN_001054ec(param_2,1);
      FUN_000f2c5c(*(undefined4 *)(iVar1 + 0x10));
    }
    ((int (*)())FUN_0019ca78)(param_1,param_2,puVar3);
  }
  if (param_2[0x47] == 2) {
    *puVar3 = *puVar3 & 0xf7ffffff | 0x4000000;
  }
  else if (param_2[0x47] == 3) {
    *puVar3 = *puVar3 | 0xc000000;
  }
  return;
}

/* FUN_0019d430 @ 0x19d430 (68 bytes) */
int FUN_0019d430(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x8c) < 0) {
    uVar1 = FUN_00130690(param_2,0);
    *(undefined4 *)(param_1 + 0x8c) = uVar1;
  }
  return;
}

/* FUN_0019d474 @ 0x19d474 (4 bytes) */
int FUN_0019d474()
{
  return;
}

/* FUN_0019d478 @ 0x19d478 (140 bytes) */
int FUN_0019d478(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int in_r5;
  
  if (in_r5 == 0) {
    puVar3 = (undefined4 *)0x0;
    uVar2 = *(uint *)(*(int *)(param_1 + 0x94) + 4);
    uVar1 = uVar2 - 1;
    if (uVar1 < uVar2) {
      puVar3 = (undefined4 *)(uVar1 * 4 + *(int *)(*(int *)(param_1 + 0x94) + 8));
    }
    FUN_000e2bf4(param_2 + 0x24,*puVar3);
  }
                    
                    
  (**(code **)(*param_2 + 0x44))(param_2,*(undefined4 *)(param_1 + 0x10),in_r5);
  return;
}

/* FUN_0019d4e8 @ 0x19d4e8 (116 bytes) */
int FUN_0019d4e8(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_1 + 0x90);
  if (iVar1 == 0) {
    uVar2 = FUN_00130690(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),0);
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x378);
    puVar3 = (undefined4 *)FUN_00193e18(uVar4,0x168);
    *puVar3 = uVar4;
    FUN_00109554(puVar3 + 1,*(undefined4 *)(param_1 + 0xc));
    *(undefined4 **)(param_1 + 0x90) = puVar3 + 1;
    puVar3[0x27] = 0;
    puVar3[0x26] = uVar2;
    iVar1 = *(int *)(param_1 + 0x90);
  }
  return iVar1;
}

/* FUN_0019d590 @ 0x19d590 (528 bytes) */
int FUN_0019d590(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  
  iVar8 = param_2[0x4e];
  iVar4 = FUN_00194034(iVar8 + 0x90);
  if ((iVar4 < 3) && (iVar4 = FUN_000e79e8(iVar8), iVar4 != 0)) {
    piVar7 = (int *)0x0;
    if (*(int *)(*(int *)(iVar8 + 0xd0) + 4) != 0) {
      piVar7 = *(int **)(*(int *)(iVar8 + 0xd0) + 8);
    }
    if (*piVar7 == param_2[0x4f]) {
      return;
    }
  }
  iVar4 = (**(code **)(*param_2 + 0x40))(param_2);
  if (iVar4 == 0) {
    if ((param_2[0x51] == 0) || (*(int *)(*(int *)(param_1 + 0x94) + 4) != 2)) {
      if (**(int **)(param_4 + 0x6c4) == 0) {
        piVar7 = (int *)FUN_001043f0(0x57,param_4);
        iVar6 = ((int (*)())FUN_0019d4e8)(param_1);
        iVar4 = DAT_001b2d50;
        piVar7[0x25] = *(int *)(iVar6 + 0x94);
        piVar7[0x27] = iVar4;
        piVar7[0x26] = 0;
        FUN_00106004(piVar7,1,iVar6,0,param_4);
        uVar1 = DAT_001b2d4c;
        iVar4 = FUN_001054ec(piVar7,1);
        *(undefined4 *)(iVar4 + 0x10) = uVar1;
        (**(code **)(*piVar7 + 0x84))(piVar7,0);
        FUN_000e76c4(iVar8,piVar7);
        return;
      }
    }
    else {
      FUN_00194208(*(int *)(param_1 + 0x94),1);
      puVar9 = *(uint **)(param_1 + 0x94);
      uVar2 = puVar9[1];
      if (uVar2 < *puVar9) {
        _memset((void *)(uVar2 * 4 + puVar9[2]),0,4);
        puVar5 = (undefined4 *)(uVar2 * 4 + puVar9[2]);
        puVar9[1] = uVar2 + 1;
      }
      else {
        puVar5 = (undefined4 *)FUN_0019423c(puVar9,uVar2);
      }
      *puVar5 = 2;
    }
  }
  else {
    piVar7 = (int *)0x0;
    iVar4 = *(int *)(*(int *)(param_1 + 0x10) + 0x24);
    uVar3 = *(uint *)(iVar4 + 4);
    uVar2 = uVar3 - 1;
    if (uVar2 < uVar3) {
      piVar7 = (int *)(uVar2 * 4 + *(int *)(iVar4 + 8));
    }
    iVar4 = *piVar7;
    ((int (*)())FUN_0019a568)(param_1,4);
    *(int *)(iVar4 + 0x14) = *(int *)(param_1 + 0x58) + -2;
  }
  return;
}

/* FUN_0019d7a0 @ 0x19d7a0 (184 bytes) */
int FUN_0019d7a0(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (**(int **)(param_2 + 0xac) == 0) {
    iVar1 = ((int (*)())FUN_0019d4e8)(param_1);
    iVar3 = *(int *)(iVar1 + 0x94);
    piVar2 = (int *)FUN_001043f0(0x59,param_4);
    iVar1 = DAT_001b2d50;
    piVar2[0x25] = iVar3;
    piVar2[0x26] = 0;
    piVar2[0x27] = iVar1;
    (**(code **)(*piVar2 + 0x84))(piVar2,3);
    FUN_000e7688(param_2,piVar2);
  }
                    
                    
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  return;
}

