#include "decls.h"

/* FUN_0013a8a4 @ 0x13a8a4 (2372 bytes) */
int FUN_0013a8a4(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined4 uVar16;
  uint uVar17;
  code *pcVar18;
  int iVar19;
  int *piVar20;
  undefined4 local_b8;
  uint local_a8;
  int local_a4;
  int local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  
  local_a0 = param_1 + 0x37c;
  iVar9 = FUN_00193e74(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),
                       *(int *)(*(int *)(param_1 + 8) + 0x324) << 2,1);
  iVar6 = *(int *)(local_a0 + 8);
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  iVar15 = *(int *)(iVar6 + 8);
  local_a4 = iVar6;
  if (*(int *)(iVar6 + 8) != 0) {
    do {
      iVar6 = iVar15;
      piVar7 = (int *)(*(int **)(local_a4 + 0x98))[2];
      piVar20 = *(int **)(local_a4 + 0x98);
      if (piVar7 != (int *)0x0) {
        do {
          piVar8 = piVar7;
          if ((piVar20[5] & 1U) != 0) {
            iVar6 = *(int *)(piVar20[0x22] + 8);
            for (iVar15 = 1; iVar10 = (**(code **)(*piVar20 + 0x14))(piVar20), iVar15 <= iVar10;
                iVar15 = iVar15 + 1) {
              piVar7 = (int *)FUN_00105594(piVar20,iVar15);
              local_b8 = *(uint *)(iVar9 + piVar7[0x53] * 4);
              if (iVar6 == 0x8e) {
LAB_0013a9dc:
                iVar10 = 0;
                iVar19 = 4;
                do {
                  *(byte *)((int)&local_b8 + iVar10) =
                       (byte)iVar10 & 0x3f | *(byte *)((int)&local_b8 + iVar10) & 0xc0 | 0x80;
                  iVar10 = iVar10 + 1;
                  iVar19 = iVar19 + -1;
                } while (iVar19 != 0);
LAB_0013ae00:
                *(uint *)(iVar9 + piVar7[0x53] * 4) = local_b8;
              }
              else {
                uVar16 = *(undefined4 *)(param_1 + 8);
                iVar10 = (**(code **)(*piVar7 + 0x24))();
                if (((iVar10 == 0) || (iVar10 = FUN_0011346c(uVar16,piVar7), iVar10 != 0)) ||
                   ((piVar7[5] & 0x400000U) != 0)) goto LAB_0013a9dc;
                bVar4 = false;
                bVar2 = false;
                uVar5 = 0xf;
                uVar13 = 0;
                uVar14 = 0;
                do {
                  iVar10 = FUN_001054ec(piVar20,iVar15);
                  uVar17 = (uint)*(byte *)(uVar14 + iVar10 + 0x10);
                  iVar10 = FUN_001054ec(piVar7,0);
                  if (*(char *)(uVar14 + iVar10 + 0x10) != '\x01') {
                    uVar5 = uVar5 & ~(1 << (uVar14 & 0x3f));
                  }
                  if (uVar17 != 4) {
                    if (uVar17 == 3) {
                      local_9c = local_b8 << 0x18 | local_9c & 0xffffff;
                      if (((int)local_9c < 0) &&
                         (local_98 = local_b8 << 0x18 | local_98 & 0xffffff, (local_b8 & 0x3f) != 3)
                         ) {
                        uVar5 = uVar5 & 0xfffffff7;
                        bVar4 = true;
                        local_94 = local_b8 << 0x18 | local_94 & 0xffffff;
                        uVar13 = uVar13 | 1 << (local_b8 & 0x3f);
                      }
                      else {
                        uVar5 = uVar5 & 0xfffffff7;
                        bVar4 = true;
                        local_90 = (local_b8 & 0xc0) << 0x18 | local_90 & 0xffffff | 0x3000000;
                        local_b8 = CONCAT31((*(unsigned int *)((unsigned char *)&(local_b8) + 0)),(char)(local_90 >> 0x18));
                      }
                    }
                    else {
                      local_8c = local_b8 << 0x18 | local_8c & 0xffffff;
                      if (((int)local_8c < 0) &&
                         (local_88 = local_b8 << 0x18 | local_88 & 0xffffff,
                         uVar17 == (local_b8 & 0x3f))) {
                        uVar5 = 0;
                        local_84 = (local_b8 & 0xc0) << 0x18 | local_84 & 0xffffff | 0x3000000;
                        local_b8 = CONCAT31((*(unsigned int *)((unsigned char *)&(local_b8) + 0)),(char)(local_84 >> 0x18));
                        local_80 = (uVar17 & 0x3f) << 0x18 |
                                   (*(byte *)((int)&local_b8 + uVar17) & 0xc0) << 0x18 |
                                   local_80 & 0xffffff;
                        *(char *)((int)&local_b8 + uVar17) = (char)(local_80 >> 0x18);
                      }
                      else {
                        uVar5 = uVar5 & ~(1 << (uVar17 & 0x3f));
                        bVar2 = true;
                        local_7c = (uVar17 & 0x3f) << 0x18 |
                                   (*(byte *)((int)&local_b8 + uVar17) & 0xc0) << 0x18 |
                                   local_7c & 0xffffff;
                        *(char *)((int)&local_b8 + uVar17) = (char)(local_7c >> 0x18);
                      }
                    }
                    *(byte *)((int)&local_b8 + uVar17) = *(byte *)((int)&local_b8 + uVar17) | 0x80;
                  }
                  bVar1 = uVar14 != 3;
                  uVar14 = uVar14 + 1;
                } while (bVar1);
                if (((((uVar5 != 0) && (bVar2)) && (bVar4)) &&
                    ((uVar14 = uVar5, uVar13 == 0 || (uVar14 = uVar13, (uVar5 & uVar13) != 0)))) &&
                   (uVar5 = FUN_0013a774(piVar7,uVar14,param_1), uVar5 != 0)) {
                  iVar10 = FUN_001054ec(piVar7,0);
                  if (*(char *)(iVar10 + 0x13) == '\x01') {
                    if ((piVar7[5] & 0x200U) != 0) {
                      piVar8 = (int *)FUN_00105594(piVar7,piVar7[0x21]);
                      bVar2 = false;
                      for (; piVar8 != (int *)0x0; piVar8 = (int *)FUN_00105594(piVar8,piVar8[0x21])
                          ) {
                        iVar10 = FUN_001054ec(piVar8,0);
                        if (*(char *)(iVar10 + 0x13) == '\x01') {
                          uVar5 = FUN_0013a774(piVar8,uVar5,param_1);
                          bVar2 = uVar5 == 0;
                        }
                        else {
                          iVar10 = (**(code **)(*piVar8 + 0x24))(piVar8);
                          if ((iVar10 == 0) ||
                             (iVar10 = FUN_0011346c(*(undefined4 *)(param_1 + 8),piVar8),
                             iVar10 != 0)) goto LAB_0013ae10;
                        }
                        if (bVar2) goto LAB_0013ae10;
                        if ((piVar8[5] & 0x200U) == 0) break;
                      }
                    }
                    if ((uVar5 & 1) == 0) {
                      if ((uVar5 & 2) == 0) {
                        iVar10 = 2;
                        iVar19 = 2;
                      }
                      else {
                        iVar10 = 1;
                        iVar19 = 1;
                      }
                    }
                    else {
                      iVar10 = 0;
                      iVar19 = 0;
                    }
                    iVar11 = FUN_001054ec(piVar7,0);
                    if ((*(char *)(iVar11 + 0x13) == '\x01') && ((piVar7[5] & 0x200U) != 0)) {
                      for (iVar11 = FUN_00105594(piVar7,piVar7[0x21]); iVar11 != 0;
                          iVar11 = FUN_00105594(iVar11,*(undefined4 *)(iVar11 + 0x84))) {
                        iVar12 = iVar9 + *(int *)(iVar11 + 0x14c) * 4;
                        local_78 = iVar19 << 0x18 |
                                   (*(byte *)(iVar12 + 3) & 0xc0) << 0x18 | local_78 & 0xffffff;
                        *(char *)(iVar12 + 3) = (char)(local_78 >> 0x18);
                        iVar12 = iVar9 + *(int *)(iVar11 + 0x14c) * 4;
                        local_74 = (uint)*(byte *)(iVar12 + 3) << 0x18 | local_74 & 0xffffff |
                                   0x80000000;
                        *(char *)(iVar12 + 3) = (char)(local_74 >> 0x18);
                        iVar12 = iVar9 + *(int *)(iVar11 + 0x14c) * 4;
                        local_70 = (uint)*(byte *)(iVar12 + iVar10) << 0x18 | local_70 & 0xffffff |
                                   0x80000000;
                        *(char *)(iVar12 + iVar10) = (char)(local_70 >> 0x18);
                        iVar12 = FUN_001054ec(iVar11,0);
                        if ((*(char *)(iVar12 + 0x13) != '\x01') ||
                           ((*(uint *)(iVar11 + 0x14) & 0x200) == 0)) break;
                      }
                    }
                    local_6c = iVar19 << 0x18 | (local_b8 & 0xc0) << 0x18 | local_6c & 0xffffff;
                    local_b8 = CONCAT31((*(unsigned int *)((unsigned char *)&(local_b8) + 0)),(char)(local_6c >> 0x18));
                  }
                  goto LAB_0013ae00;
                }
              }
LAB_0013ae10: ;
            }
            piVar8 = (int *)piVar20[2];
          }
          piVar7 = (int *)piVar8[2];
          piVar20 = piVar8;
        } while ((int *)piVar8[2] != (int *)0x0);
        iVar6 = *(int *)(local_a4 + 8);
      }
      iVar15 = *(int *)(iVar6 + 8);
      local_a4 = iVar6;
    } while (*(int *)(iVar6 + 8) != 0);
    iVar6 = *(int *)(local_a0 + 8);
  }
  iVar15 = *(int *)(iVar6 + 8);
  while (iVar10 = iVar15, iVar10 != 0) {
    piVar20 = *(int **)(iVar6 + 0x98);
    piVar7 = (int *)piVar20[2];
    if ((int *)piVar20[2] != (int *)0x0) {
      do {
        piVar8 = piVar7;
        if ((piVar20[5] & 1U) != 0) {
          iVar15 = (**(code **)(*piVar20 + 0x24))(piVar20);
          if ((iVar15 != 0) &&
             (iVar15 = FUN_0011346c(*(undefined4 *)(param_1 + 8),piVar20), iVar15 == 0)) {
            uVar5 = (uint)*(byte *)(piVar20[0x53] * 4 + iVar9 + 3);
            local_68 = uVar5 << 0x18 | local_68 & 0xffffff;
            if ((int)local_68 < 0) {
              local_64 = uVar5 << 0x18 | local_64 & 0xffffff;
              uVar5 = uVar5 & 0x3f;
              FUN_001054ec(piVar20,0);
              if (uVar5 != 3) {
                iVar15 = FUN_001054ec(piVar20,0);
                FUN_000f31f8(&local_a8,*(undefined4 *)(iVar15 + 0x10),piVar20[3]);
                local_b8 = local_a8;
                uVar13 = local_b8;
                (*(unsigned char *)((unsigned char *)&(local_b8) + 3)) = (char)local_a8;
                bVar2 = (char)local_b8 == '\0';
                local_b8 = uVar13;
                if (bVar2) {
                  (*(unsigned int *)((unsigned char *)&(local_b8) + 0)) = (undefined3)(local_a8 >> 8);
                  local_b8 = CONCAT31((*(unsigned int *)((unsigned char *)&(local_b8) + 0)),1);
                  *(undefined1 *)((int)&local_b8 + uVar5) = 0;
                  iVar15 = piVar20[0x22];
                  *(undefined1 *)((int)piVar20 + 0xf) = 0;
                  *(undefined1 *)((int)piVar20 + uVar5 + 0xc) = 1;
                  iVar15 = FUN_00113174(*(undefined4 *)(iVar15 + 8),*(undefined4 *)(param_1 + 8));
                  if (iVar15 == 0) {
                    for (iVar15 = 1; iVar10 = (**(code **)(*piVar20 + 0x14))(piVar20),
                        iVar15 <= iVar10; iVar15 = iVar15 + 1) {
                      iVar10 = FUN_00105594(piVar20,iVar15);
                      iVar19 = FUN_001054ec(piVar20,iVar15);
                      if (*(char *)(uVar5 + iVar19 + 0x10) != '\x04') {
                        FUN_001054ec(piVar20,iVar15);
                        FUN_001054ec(piVar20,iVar15);
                      }
                      pcVar18 = *(code **)(*piVar20 + 0x88);
                      iVar19 = FUN_001054ec(piVar20,iVar15);
                      (*pcVar18)(piVar20,iVar15,uVar5,*(undefined1 *)(iVar19 + 0x13));
                      (**(code **)(*piVar20 + 0x88))(piVar20,iVar15,3,4);
                      if (*(int *)(iVar10 + 0x98) == 0x33) {
                        (**(code **)(*piVar20 + 0x88))(piVar20,iVar15,uVar5,uVar5);
                        *(undefined1 *)(iVar10 + uVar5 + 0x9c) = 0;
                        *(undefined1 *)(iVar10 + uVar5 + 0xc) = 1;
                      }
                    }
                  }
                  piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
                  iVar15 = (**(code **)(*piVar7 + 0x7c))(piVar7,piVar20);
                  if (iVar15 != 0) {
                    piVar20[0x27] = local_b8;
                  }
                }
              }
            }
          }
          for (iVar15 = 1; iVar10 = (**(code **)(*piVar20 + 0x14))(piVar20), iVar15 <= iVar10;
              iVar15 = iVar15 + 1) {
            piVar7 = (int *)FUN_00105594(piVar20,iVar15);
            iVar19 = piVar7[0x53];
            iVar10 = (**(code **)(*piVar7 + 0x24))();
            if (iVar10 != 0) {
              iVar10 = iVar9 + iVar19 * 4;
              bVar3 = *(byte *)(iVar10 + 3);
              if (((int)((uint)bVar3 << 0x18) < 0) && ((bVar3 & 0x3f) != 3)) {
                iVar19 = 0;
                do {
                  iVar11 = FUN_001054ec(piVar20,iVar15);
                  if (*(char *)(iVar19 + iVar11 + 0x10) == '\x03') {
                    bVar3 = *(byte *)(iVar10 + 3);
                    local_60 = (uint)bVar3 << 0x18 | local_60 & 0xffffff;
                    (**(code **)(*piVar20 + 0x88))(piVar20,iVar15,iVar19,bVar3 & 0x3f);
                  }
                  bVar2 = iVar19 != 3;
                  iVar19 = iVar19 + 1;
                } while (bVar2);
              }
            }
          }
          piVar8 = (int *)piVar20[2];
        }
        piVar7 = (int *)piVar8[2];
        piVar20 = piVar8;
      } while ((int *)piVar8[2] != (int *)0x0);
      iVar10 = *(int *)(iVar6 + 8);
    }
    iVar6 = iVar10;
    iVar15 = *(int *)(iVar10 + 8);
  }
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),iVar9);
  return;
}

/* FUN_0013b1e8 @ 0x13b1e8 (520 bytes) */
int FUN_0013b1e8(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  uint *puVar10;
  int iVar11;
  
  piVar7 = (int *)0x0;
  for (uVar8 = 0; iVar6 = FUN_00104054(param_1,param_2), (int)uVar8 < iVar6; uVar8 = uVar8 + 1) {
    puVar10 = *(uint **)(param_1 + 0x10);
    if (uVar8 < *puVar10) {
      uVar3 = puVar10[1];
      if (uVar3 <= uVar8) {
        _memset((void *)(uVar3 * 4 + puVar10[2]),0,(uVar8 - uVar3) * 4 + 4);
        puVar10[1] = uVar8 + 1;
      }
      piVar4 = (int *)(uVar8 * 4 + puVar10[2]);
    }
    else {
      piVar4 = (int *)FUN_0019423c(puVar10,uVar8);
    }
    iVar6 = *piVar4;
    piVar4 = *(int **)(iVar6 + 0x158);
    if ((piVar4[3] & 0x40U) != 0) goto LAB_0013b3c4;
    if (*(int *)(*(int *)(iVar6 + 0x88) + 8) == 0x8e) {
      iVar2 = 0;
      do {
        iVar11 = iVar2;
        if (*(int *)(iVar6 + 0x84) <= iVar11) goto LAB_0013b2d8;
        iVar5 = FUN_00105594(iVar6,iVar11 + 1);
        iVar2 = iVar11 + 1;
      } while (param_1 != iVar5);
      piVar4 = (int *)FUN_000e9184(piVar4,iVar11);
    }
LAB_0013b2d8:
    iVar6 = (**(code **)(*piVar4 + 0x24))(piVar4);
    if ((iVar6 != 0) && (piVar4 = (int *)FUN_000e9184(piVar4,0), piVar4 == (int *)0x0))
    goto LAB_0013b3c4;
    bVar1 = piVar7 == (int *)0x0;
    piVar9 = piVar4;
    if ((!bVar1) && (piVar9 = piVar7, piVar7 != piVar4)) {
      do {
        iVar2 = piVar4[0x2f];
        iVar6 = piVar7[0x2f];
        if (iVar6 < iVar2) {
          piVar4 = (int *)piVar4[0x3c];
LAB_0013b318:
          if (piVar4 == (int *)0x0) goto LAB_0013b3c4;
          bVar1 = piVar7 == (int *)0x0;
        }
        else if (iVar2 < iVar6) {
          piVar7 = (int *)piVar7[0x3c];
          bVar1 = piVar7 == (int *)0x0;
        }
        else if (iVar2 == iVar6) {
          piVar4 = (int *)piVar4[0x3c];
          piVar7 = (int *)piVar7[0x3c];
          goto LAB_0013b318;
        }
        piVar9 = piVar4;
      } while ((!bVar1) && (piVar9 = piVar7, piVar7 != piVar4));
    }
    piVar7 = piVar9;
  }
  iVar6 = FUN_000e79d0(piVar7);
  if (((1 < iVar6) && (piVar7 = (int *)FUN_000e9184(piVar7,0), piVar7 == *(int **)(param_1 + 0x158))
      ) || (iVar6 = FUN_00139294(piVar7,*(undefined4 *)(param_2 + 0x3a0)), iVar6 == 0)) {
LAB_0013b3c4:
    piVar7 = (int *)0x0;
  }
  return piVar7;
}

/* FUN_0013b3f0 @ 0x13b3f0 (2308 bytes) */
int FUN_0013b3f0(param_1)
  int param_1;
{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  int *piVar12;
  uint uVar13;
  uint *puVar14;
  int iVar15;
  uint uVar16;
  uint *puVar17;
  int iVar18;
  int *piVar19;
  int *piVar20;
  undefined4 uVar21;
  int *piVar22;
  int iVar23;
  uint uVar24;
  uint *puVar25;
  
  iVar23 = *(int *)(param_1 + 0x3a8);
  while ((iVar23 != 0 && (iVar4 = FUN_000e79dc(iVar23), iVar4 != 0))) {
    *(uint *)(iVar23 + 0xc) = *(uint *)(iVar23 + 0xc) | 0x40;
    iVar23 = *(int *)(iVar23 + 0xf0);
  }
  iVar15 = *(int *)(param_1 + 0x3a0);
  uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar21,0x14);
  puVar14 = puVar5 + 1;
  *puVar5 = uVar21;
  puVar5[1] = 2;
  puVar5[2] = 0;
  puVar5[4] = uVar21;
  uVar21 = FUN_00193e18(uVar21,8);
  puVar5[3] = uVar21;
  iVar23 = *(int *)(param_1 + 900);
  for (iVar4 = *(int *)(*(int *)(param_1 + 900) + 8); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    if (iVar23 != iVar15) {
      iVar4 = FUN_00139294(iVar23,iVar15);
      if (iVar4 != 0) {
        iVar4 = *(int *)(iVar23 + 0x98);
        for (iVar3 = *(int *)(*(int *)(iVar23 + 0x98) + 8); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8))
        {
          iVar18 = 0;
          if ((*(uint *)(iVar4 + 0x14) & 1) != 0) {
            while (iVar18 < *(int *)(iVar4 + 0x84)) {
              iVar18 = iVar18 + 1;
              iVar3 = FUN_00105594(iVar4,iVar18);
              iVar6 = FUN_00139344();
              if ((((iVar6 != 0) && (*(int *)(*(int *)(iVar3 + 0x158) + 0xb8) == 0)) &&
                  (iVar6 = ((int (*)())FUN_0013b1e8)(iVar3,param_1), iVar6 != 0)) &&
                 (iVar6 != *(int *)(iVar3 + 0x158))) {
                piVar8 = *(int **)(iVar6 + 0xf0);
                while ((piVar8 != (int *)0x0 &&
                       (iVar7 = (**(code **)(*piVar8 + 0x24))(piVar8), iVar7 == 0))) {
                  uVar24 = piVar8[3];
                  if ((uVar24 & 0x40) != 0) goto LAB_0013b588;
                  piVar8 = (int *)piVar8[0x3c];
                }
                uVar24 = piVar8[3];
LAB_0013b588:
                if ((uVar24 & 0x800) == 0) {
                  uVar24 = puVar5[2];
                  if (uVar24 < *puVar14) {
                    _memset((void *)(uVar24 * 4 + puVar5[3]),0,4);
                    piVar8 = (int *)(uVar24 * 4 + puVar5[3]);
                    puVar5[2] = uVar24 + 1;
                  }
                  else {
                    piVar8 = (int *)FUN_0019423c(puVar14,uVar24);
                  }
                  *piVar8 = iVar3;
                  FUN_0010401c(iVar3);
                  *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 1;
                  FUN_000e76c4(iVar6,iVar3);
                }
              }
            }
            iVar3 = *(int *)(iVar4 + 8);
          }
          iVar4 = iVar3;
        }
      }
      iVar4 = *(int *)(iVar23 + 8);
    }
    iVar23 = iVar4;
  }
  uVar24 = puVar5[2];
  if (uVar24 == 0) {
    return;
  }
  uVar13 = 0;
LAB_0013b658:
  if (uVar13 < *puVar14) {
    if (uVar24 <= uVar13) {
      _memset((void *)(uVar24 * 4 + puVar5[3]),0,(uVar13 - uVar24) * 4 + 4);
      puVar5[2] = uVar13 + 1;
    }
    piVar8 = (int *)(uVar13 * 4 + puVar5[3]);
  }
  else {
    piVar8 = (int *)FUN_0019423c(puVar14,uVar13);
  }
  iVar23 = *piVar8;
  piVar8 = *(int **)(iVar23 + 0x158);
  if (piVar8 == (int *)0x0) {
    piVar20 = (int *)0x0;
    piVar12 = (int *)0x0;
  }
  else {
    piVar12 = (int *)0x0;
    piVar22 = piVar8;
    do {
      iVar4 = (**(code **)(*piVar22 + 0x14))(piVar22);
      if (iVar4 != 0) goto LAB_0013ba08;
      iVar4 = (**(code **)(*piVar22 + 0x24))(piVar22);
      piVar20 = piVar22;
      if (iVar4 != 0) break;
      iVar4 = (**(code **)(*piVar22 + 0x28))(piVar22);
      if (iVar4 == 0) {
        iVar4 = (**(code **)(*piVar22 + 0x34))(piVar22);
        if (iVar4 == 0) {
          iVar4 = (**(code **)(*piVar22 + 0x2c))(piVar22);
          if (iVar4 == 0) {
            piVar20 = (int *)FUN_000e9184(piVar22,0);
          }
          else {
            piVar20 = (int *)FUN_000e7e90(piVar22);
          }
        }
        else {
          piVar22 = (int *)piVar22[0x4b];
          piVar20 = (int *)FUN_000e7e90(piVar22);
        }
      }
      else {
        piVar22 = (int *)piVar22[0x4b];
        piVar20 = (int *)FUN_000e9184(piVar22,0);
      }
      piVar12 = piVar22;
      piVar22 = piVar20;
    } while (piVar20 != (int *)0x0);
  }
  uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar9 = (undefined4 *)FUN_00193e18(uVar21,0x134);
  *puVar9 = uVar21;
  piVar22 = puVar9 + 1;
  FUN_000ea3c0(piVar22,*(undefined4 *)(param_1 + 8));
  if (piVar12 == (int *)piVar20[0x4e]) {
    piVar20[0x4e] = (int)piVar22;
  }
  FUN_000ec370(param_1,piVar12,piVar22);
  FUN_000e977c(piVar20,piVar12,piVar22);
  FUN_000e8e4c(piVar22,piVar12);
  piVar19 = (int *)piVar20[0x4f];
  piVar20 = piVar8;
  piVar12 = piVar8;
  do {
    iVar4 = (**(code **)(*piVar12 + 0x28))(piVar12);
    if ((iVar4 != 0) && (piVar12 == piVar19)) {
      iVar4 = 0;
      for (uVar24 = 1; uVar24 <= *(uint *)(piVar12[0x35] + 4); uVar24 = uVar24 + 1) {
        piVar2 = *(int **)(*(int *)(piVar12[0x35] + 8) + iVar4);
        if ((piVar2 != (int *)0x0) && (piVar20 != piVar2)) goto LAB_0013b8e4;
        iVar4 = iVar4 + 4;
      }
      piVar2 = (int *)0x0;
LAB_0013b8e4:
      iVar4 = (**(code **)(*piVar2 + 0x18))(piVar2);
      if (iVar4 == 0) break;
    }
    iVar4 = (**(code **)(*piVar12 + 0x24))(piVar12);
    piVar20 = piVar12;
    if (iVar4 != 0) {
      piVar20 = (int *)FUN_000e920c(piVar12[0x4f],0);
    }
    iVar4 = (**(code **)(*piVar20 + 0x2c))(piVar20);
    if (iVar4 != 0) {
      piVar20 = (int *)piVar20[0x55];
    }
    piVar2 = (int *)FUN_000e920c(piVar20,0);
    piVar20 = piVar12;
    piVar12 = piVar2;
  } while( true );
  uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar9 = (undefined4 *)FUN_00193e18(uVar21,0x134);
  *puVar9 = uVar21;
  puVar10 = puVar9 + 1;
  FUN_000ea148(puVar10,*(undefined4 *)(param_1 + 8));
  puVar1 = PTR_DAT_001e9134;
  puVar9[0x4c] = piVar22;
  puVar9[1] = puVar1 + 8;
  FUN_000ec3ac(param_1,piVar2,puVar10);
  FUN_000e9948(piVar12,piVar2,puVar10);
  FUN_000e8e4c(piVar2,puVar10);
LAB_0013ba08:
  uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar9 = (undefined4 *)FUN_00193e18(uVar21,0x14);
  puVar17 = puVar9 + 1;
  *puVar9 = uVar21;
  puVar9[1] = 2;
  puVar9[2] = 0;
  puVar9[4] = uVar21;
  uVar21 = FUN_00193e18(uVar21,8);
  puVar9[3] = uVar21;
  uVar21 = FUN_00105594(iVar23,1);
  uVar24 = puVar9[2];
  if (uVar24 < (uint)puVar9[1]) {
    _memset((void *)(uVar24 * 4 + puVar9[3]),0,4);
    puVar10 = (undefined4 *)(uVar24 * 4 + puVar9[3]);
    puVar9[2] = uVar24 + 1;
  }
  else {
    puVar10 = (undefined4 *)FUN_0019423c(puVar17,uVar24);
  }
  *puVar10 = uVar21;
  uVar24 = puVar9[2];
  if (uVar24 != 0) {
    uVar11 = 0;
    do {
      if (uVar11 < *puVar17) {
        if (uVar24 <= uVar11) {
          _memset((void *)(uVar24 * 4 + puVar9[3]),0,(uVar11 - uVar24) * 4 + 4);
          puVar9[2] = uVar11 + 1;
        }
        puVar10 = (undefined4 *)(uVar11 * 4 + puVar9[3]);
      }
      else {
        puVar10 = (undefined4 *)FUN_0019423c(puVar17,uVar11);
      }
      uVar16 = uVar11 + 1;
      piVar20 = (int *)*puVar10;
      if ((int *)piVar20[0x56] != piVar22) {
        if (uVar11 == 0) {
          puVar25 = (uint *)piVar22[0x4b];
          uVar24 = puVar25[1];
          if (uVar24 < *puVar25) {
            _memset((void *)(uVar24 * 4 + puVar25[2]),0,4);
            puVar10 = (undefined4 *)(uVar24 * 4 + puVar25[2]);
            puVar25[1] = uVar24 + 1;
          }
          else {
            puVar10 = (undefined4 *)FUN_0019423c(puVar25,uVar24);
          }
          *puVar10 = piVar20;
        }
        if ((((piVar20[5] & 8U) == 0) && (*(int *)(piVar20[0x22] + 8) != 0x8e)) &&
           (piVar20[0x56] != *(int *)(param_1 + 0x3a0))) {
          uVar24 = 0;
          iVar23 = (**(code **)(*piVar20 + 0x50))(piVar20);
          if (iVar23 == 0) {
            for (; iVar23 = FUN_00104054(piVar20,param_1), (int)uVar24 < iVar23; uVar24 = uVar24 + 1
                ) {
              puVar25 = (uint *)piVar20[4];
              if (uVar24 < *puVar25) {
                uVar11 = puVar25[1];
                if (uVar11 <= uVar24) {
                  _memset((void *)(uVar11 * 4 + puVar25[2]),0,(uVar24 - uVar11) * 4 + 4);
                  puVar25[1] = uVar24 + 1;
                }
                piVar12 = (int *)(uVar24 * 4 + puVar25[2]);
              }
              else {
                piVar12 = (int *)FUN_0019423c(puVar25,uVar24);
              }
              if ((piVar22 != *(int **)(*piVar12 + 0x158)) &&
                 (piVar8 != *(int **)(*piVar12 + 0x158))) goto LAB_0013bd34;
            }
            FUN_0010401c(piVar20);
            piVar20[5] = piVar20[5] | 1;
            FUN_000e76c4(piVar22,piVar20);
            for (iVar23 = 1; iVar4 = (**(code **)(*piVar20 + 0x14))(piVar20), iVar23 < iVar4;
                iVar23 = iVar23 + 1) {
              uVar21 = FUN_00105594(piVar20,iVar23);
              uVar24 = puVar9[2];
              if (uVar24 < *puVar17) {
                _memset((void *)(uVar24 * 4 + puVar9[3]),0,4);
                puVar10 = (undefined4 *)(uVar24 * 4 + puVar9[3]);
                puVar9[2] = uVar24 + 1;
              }
              else {
                puVar10 = (undefined4 *)FUN_0019423c(puVar17,uVar24);
              }
              *puVar10 = uVar21;
            }
          }
        }
      }
LAB_0013bd34:
      uVar24 = puVar9[2];
      uVar11 = uVar16;
    } while (uVar16 < uVar24);
  }
  uVar24 = puVar5[2];
  uVar13 = uVar13 + 1;
  if (uVar24 <= uVar13) {
    return;
  }
  goto LAB_0013b658;
}

/* FUN_0013bd68 @ 0x13bd68 (1168 bytes) */
int FUN_0013bd68(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  int *piVar14;
  uint local_54;
  uint local_50;
  int local_4c;
  undefined4 local_48;
  
  bVar1 = param_2 == 0;
  iVar11 = *(int *)(param_1 + 0x2ac);
  iVar9 = *(int *)(param_1 + 8);
  *(int *)(param_1 + 0x2ac) = iVar11 + 1;
  iVar3 = *(int *)(iVar9 + 0x324);
  if (bVar1) {
    iVar7 = 0;
  }
  else {
    iVar7 = FUN_00193e18(*(undefined4 *)(iVar9 + 0x378),iVar3 << 2);
    iVar9 = *(int *)(param_1 + 900);
    for (iVar5 = *(int *)(*(int *)(param_1 + 900) + 8); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
      iVar4 = *(int *)(*(int *)(iVar9 + 0x98) + 8);
      iVar10 = *(int *)(iVar9 + 0x98);
      if (iVar4 != 0) {
        do {
          iVar5 = iVar4;
          if ((*(uint *)(iVar10 + 0x14) & 1) != 0) {
            iVar5 = *(int *)(iVar10 + 0x160) - *(int *)(param_1 + 0x478);
            if (iVar5 < 0) {
              iVar5 = 0;
            }
            *(int *)(*(int *)(iVar10 + 0x14c) * 4 + iVar7) = iVar5;
            iVar5 = *(int *)(iVar10 + 8);
          }
          iVar4 = *(int *)(iVar5 + 8);
          iVar10 = iVar5;
        } while (*(int *)(iVar5 + 8) != 0);
        iVar5 = *(int *)(iVar9 + 8);
      }
      iVar9 = iVar5;
    }
    iVar9 = *(int *)(param_1 + 8);
  }
  iVar5 = 0;
  *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
  *(int *)(param_1 + 0x478) = iVar3 * 4 + *(int *)(param_1 + 0x478);
  local_48 = *(undefined4 *)(iVar9 + 0x378);
  local_54 = 2;
  local_50 = 0;
  local_4c = FUN_00193e18(local_48,8);
  iVar3 = *(int *)(param_1 + 0x3c4);
  for (uVar12 = 1; uVar12 <= *(uint *)(iVar3 + 4); uVar12 = uVar12 + 1) {
    iVar9 = *(int *)(*(int *)(iVar3 + 8) + iVar5);
    if ((*(uint *)(iVar9 + 0x14) & 1) != 0) {
      iVar3 = FUN_001054ec(iVar9,0);
      uVar2 = local_50;
      if ((*(int *)(iVar3 + 0x10) != DAT_001b0014) &&
         (*(int *)(param_1 + 0x474) != *(int *)(iVar9 + 0x150))) {
        *(int *)(iVar9 + 0x150) = *(int *)(param_1 + 0x474);
        if (local_50 < local_54) {
          iVar3 = local_50 * 4;
          _memset((void *)(iVar3 + local_4c),0,4);
          local_50 = uVar2 + 1;
          piVar8 = (int *)(iVar3 + local_4c);
        }
        else {
          piVar8 = (int *)FUN_0019423c(&local_54,local_50);
        }
        *piVar8 = iVar9;
        do {
          piVar8 = (int *)0x0;
          if (local_50 - 1 < local_50) {
            piVar8 = (int *)((local_50 - 1) * 4 + local_4c);
          }
          iVar3 = *piVar8;
          FUN_00194208(&local_54);
          if (0 < *(int *)(iVar3 + 0x84)) {
            iVar9 = 1;
            do {
              iVar4 = FUN_00105594(iVar3,iVar9);
              uVar2 = local_50;
              if (iVar4 != 0) {
                if (*(int *)(param_1 + 0x478) < *(int *)(iVar4 + 0x160)) {
                  *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar4 + 0x160) = *(int *)(param_1 + 0x478) + 1;
                }
                if (*(int *)(param_1 + 0x474) != *(int *)(iVar4 + 0x150)) {
                  *(int *)(iVar4 + 0x150) = *(int *)(param_1 + 0x474);
                  if (local_50 < local_54) {
                    iVar10 = local_50 * 4;
                    _memset((void *)(iVar10 + local_4c),0,4);
                    local_50 = uVar2 + 1;
                    piVar8 = (int *)(iVar10 + local_4c);
                  }
                  else {
                    piVar8 = (int *)FUN_0019423c(&local_54,local_50);
                  }
                  *piVar8 = iVar4;
                }
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 <= *(int *)(iVar3 + 0x84));
          }
        } while (local_50 != 0);
      }
      iVar3 = *(int *)(param_1 + 0x3c4);
    }
    iVar5 = iVar5 + 4;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 900) + 8);
  if (iVar3 == 0) {
    uVar13 = 1;
  }
  else {
    uVar13 = 1;
    iVar11 = iVar11 * 4 + param_1;
    iVar9 = *(int *)(param_1 + 900);
    do {
      iVar5 = iVar3;
      piVar8 = (int *)(*(int **)(iVar9 + 0x98))[2];
      piVar14 = *(int **)(iVar9 + 0x98);
      if (piVar8 != (int *)0x0) {
        do {
          piVar6 = piVar8;
          if ((piVar14[5] & 1U) != 0) {
            iVar3 = (**(code **)(*piVar14 + 0x34))(piVar14);
            if ((iVar3 == 0) && (iVar3 = (**(code **)(*piVar14 + 0x38))(piVar14), iVar3 == 0)) {
              if ((!bVar1) && (iVar3 = (**(code **)(*piVar14 + 0x48))(piVar14), iVar3 == 0)) {
                iVar3 = piVar14[0x58] - *(int *)(param_1 + 0x478);
                if (iVar3 < 0) {
                  iVar3 = 0;
                }
                if (*(int *)(piVar14[0x53] * 4 + iVar7) != iVar3) {
                  uVar13 = 0;
                }
              }
              if (((*(int *)(param_1 + 0x474) != piVar14[0x54]) && ((piVar14[5] & 8U) == 0)) &&
                 ((piVar14[5] & 0x10U) == 0)) {
                (**(code **)(*piVar14 + 0x10))(piVar14,*(undefined4 *)(param_1 + 8));
                if ((piVar14[0x26] != 2) && (piVar14[0x26] != 0x33)) {
                  *(int *)(iVar11 + 0x2b0) = *(int *)(iVar11 + 0x2b0) + 1;
                  piVar6 = (int *)piVar14[2];
                  goto LAB_0013c188;
                }
              }
            }
            piVar6 = (int *)piVar14[2];
          }
LAB_0013c188:
          piVar8 = (int *)piVar6[2];
          piVar14 = piVar6;
        } while ((int *)piVar6[2] != (int *)0x0);
        iVar5 = *(int *)(iVar9 + 8);
      }
      iVar3 = *(int *)(iVar5 + 8);
      iVar9 = iVar5;
    } while (*(int *)(iVar5 + 8) != 0);
  }
  if (!bVar1) {
    FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),iVar7);
  }
  FUN_00193cc0(local_48,local_4c);
  return uVar13;
}

/* FUN_0013c210 @ 0x13c210 (976 bytes) */
int FUN_0013c210(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  int local_58;
  uint local_54;
  uint local_50;
  int local_4c;
  undefined4 local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  undefined4 local_38;
  
  iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x1c);
  if ((((iVar2 == 0) && (iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x1d), iVar2 == 0)) &&
      (iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x39), iVar2 == 0)) &&
     (iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x1b), iVar2 == 0)) {
    FUN_000e0e0c(*(undefined4 *)(param_1 + 8),
                 "Special : all peephole flags off -> bypass Rewrite()\n");
  }
  *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
  local_48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_50 = 0;
  local_54 = 2;
  local_4c = FUN_00193e18(local_48,8);
  local_38 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_44 = 2;
  local_40 = 0;
  local_3c = FUN_00193e18(local_38,8);
  iVar2 = *(int *)(param_1 + 0x3c4);
  uVar8 = 1;
  iVar7 = 0;
  do {
    uVar10 = local_50;
    if (*(uint *)(iVar2 + 4) < uVar8) {
      FUN_00193cc0(local_38,local_3c);
      FUN_00193cc0(local_48,local_4c);
      return;
    }
    local_58 = *(int *)(*(int *)(iVar2 + 8) + iVar7);
    if ((*(uint *)(local_58 + 0x14) & 1) != 0) {
      if (local_50 < local_54) {
        iVar2 = local_50 * 4;
        _memset((void *)(iVar2 + local_4c),0,4);
        local_50 = uVar10 + 1;
        puVar3 = (undefined4 *)(iVar2 + local_4c);
      }
      else {
        puVar3 = (undefined4 *)FUN_0019423c(&local_54,local_50);
      }
      uVar10 = local_40;
      *puVar3 = 0;
      if (local_40 < local_44) {
        iVar2 = local_40 * 4;
        _memset((void *)(iVar2 + local_3c),0,4);
        local_40 = uVar10 + 1;
        puVar3 = (undefined4 *)(iVar2 + local_3c);
      }
      else {
        puVar3 = (undefined4 *)FUN_0019423c(&local_44,local_40);
      }
      *puVar3 = 0;
      bVar1 = true;
      uVar10 = local_50;
      while (uVar10 != 0) {
        if (bVar1) {
          if ((local_58 == 0) || (*(int *)(param_1 + 0x474) == *(int *)(local_58 + 0x150))) {
            bVar1 = false;
          }
          else {
            *(int *)(local_58 + 0x150) = *(int *)(param_1 + 0x474);
            iVar2 = FUN_00105594(local_58,1);
            uVar10 = local_50;
            if (iVar2 == 0) {
              puVar3 = (undefined4 *)0x0;
              if (local_50 - 1 < local_50) {
                puVar3 = (undefined4 *)((local_50 - 1) * 4 + local_4c);
              }
              uVar9 = *puVar3;
LAB_0013c528:
              uVar6 = FUN_0013922c(&local_44);
              FUN_00139c78(local_58,uVar9,uVar6,param_1);
              goto LAB_0013c540;
            }
            if (local_50 < local_54) {
              iVar2 = local_50 * 4;
              _memset((void *)(iVar2 + local_4c),0,4);
              local_50 = uVar10 + 1;
              piVar4 = (int *)(iVar2 + local_4c);
            }
            else {
              piVar4 = (int *)FUN_0019423c(&local_54,local_50);
            }
            *piVar4 = local_58;
            uVar9 = FUN_0013a38c(local_58,&local_44,param_1);
LAB_0013c54c:
            local_58 = FUN_00105594(local_58,uVar9);
            bVar1 = true;
            uVar10 = local_50;
          }
        }
        else {
          piVar4 = (int *)0x0;
          if (uVar10 - 1 < uVar10) {
            piVar4 = (int *)((uVar10 - 1) * 4 + local_4c);
          }
          iVar2 = *piVar4;
          if (iVar2 != 0) {
            if (local_58 != 0) {
              iVar5 = FUN_00139190(&local_44,*(undefined4 *)(iVar2 + 0x84));
              uVar10 = local_50;
              if (iVar5 == 0) {
                uVar9 = FUN_0013a240(&local_44);
                local_58 = iVar2;
                goto LAB_0013c54c;
              }
            }
            FUN_00194208(&local_54,uVar10 - 1);
            FUN_00194208(&local_44,local_40 - 1);
            puVar3 = (undefined4 *)0x0;
            if (local_50 - 1 < local_50) {
              puVar3 = (undefined4 *)((local_50 - 1) * 4 + local_4c);
            }
            uVar9 = *puVar3;
            local_58 = iVar2;
            goto LAB_0013c528;
          }
          FUN_00194208(&local_54);
          FUN_00194208(&local_44,local_40 - 1);
          local_58 = iVar2;
LAB_0013c540:
          bVar1 = false;
          uVar10 = local_50;
        }
      }
      iVar2 = *(int *)(param_1 + 0x3c4);
    }
    uVar8 = uVar8 + 1;
    iVar7 = iVar7 + 4;
  } while( true );
}

/* FUN_0013c60c @ 0x13c60c (1100 bytes) */
int FUN_0013c60c(param_1)
  int param_1;
{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int local_58;
  uint local_54;
  uint local_50;
  int local_4c;
  undefined4 local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  undefined4 local_38;
  
  *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
  local_48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_50 = 0;
  local_54 = 2;
  local_4c = FUN_00193e18(local_48,8);
  local_38 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_44 = 2;
  local_40 = 0;
  local_3c = FUN_00193e18(local_38,8);
  iVar8 = *(int *)(param_1 + 0x3c4);
  uVar10 = 1;
  iVar9 = 0;
LAB_0013c9f4:
  uVar6 = local_50;
  if (*(uint *)(iVar8 + 4) < uVar10) {
    FUN_00193cc0(local_38,local_3c);
    FUN_00193cc0(local_48,local_4c);
    return;
  }
  local_58 = *(int *)(iVar9 + *(int *)(iVar8 + 8));
  if ((*(uint *)(local_58 + 0x14) & 1) != 0) {
    if (local_50 < local_54) {
      iVar8 = local_50 * 4;
      _memset((void *)(iVar8 + local_4c),0,4);
      local_50 = uVar6 + 1;
      puVar4 = (undefined4 *)(iVar8 + local_4c);
    }
    else {
      puVar4 = (undefined4 *)FUN_0019423c(&local_54,local_50);
    }
    uVar6 = local_40;
    *puVar4 = 0;
    if (local_40 < local_44) {
      iVar8 = local_40 * 4;
      _memset((void *)(iVar8 + local_3c),0,4);
      local_40 = uVar6 + 1;
      puVar4 = (undefined4 *)(iVar8 + local_3c);
    }
    else {
      puVar4 = (undefined4 *)FUN_0019423c(&local_44,local_40);
    }
    *puVar4 = 0;
    bVar2 = true;
    uVar6 = local_50;
LAB_0013c9e0:
    do {
      if (uVar6 == 0) goto code_r0x0013c9e8;
      if (bVar2) {
        if (local_58 != 0) {
          iVar8 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x14);
          if (iVar8 != 0) {
            local_58 = ((int (*)())FUN_00147f54)(local_58,*(undefined4 *)(param_1 + 8));
          }
          uVar6 = local_50;
          if (*(int *)(param_1 + 0x474) != *(int *)(local_58 + 0x150)) {
            *(int *)(local_58 + 0x150) = *(int *)(param_1 + 0x474);
            iVar8 = FUN_00105594(local_58,1);
            uVar6 = local_50;
            if (iVar8 == 0) goto LAB_0013c8f0;
            if (local_50 < local_54) {
              iVar8 = local_50 * 4;
              _memset((void *)(iVar8 + local_4c),0,4);
              local_50 = uVar6 + 1;
              piVar5 = (int *)(iVar8 + local_4c);
            }
            else {
              piVar5 = (int *)FUN_0019423c(&local_54,local_50);
            }
            uVar6 = local_40;
            *piVar5 = local_58;
            if (local_40 < local_44) {
              iVar8 = local_40 * 4;
              _memset((void *)(iVar8 + local_3c),0,4);
              local_40 = uVar6 + 1;
              puVar4 = (undefined4 *)(iVar8 + local_3c);
            }
            else {
              puVar4 = (undefined4 *)FUN_0019423c(&local_44,local_40);
            }
            *puVar4 = 1;
            local_58 = FUN_00105594(local_58,1);
LAB_0013c9c8:
            bVar2 = true;
            uVar6 = local_50;
            goto LAB_0013c9e0;
          }
        }
        bVar2 = false;
        goto LAB_0013c9e0;
      }
      uVar7 = uVar6 - 1;
      piVar5 = (int *)0x0;
      if (uVar7 < uVar6) {
        piVar5 = (int *)(uVar7 * 4 + local_4c);
      }
      iVar8 = *piVar5;
      if (iVar8 == 0) {
        FUN_00194208(&local_54,uVar7);
        FUN_00194208(&local_44,local_40 - 1);
        local_58 = iVar8;
      }
      else {
        if (local_58 != 0) {
          piVar5 = (int *)0x0;
          uVar6 = local_40 - 1;
          if (uVar6 < local_40) {
            piVar5 = (int *)(uVar6 * 4 + local_3c);
          }
          if (*piVar5 != *(int *)(iVar8 + 0x84)) {
            piVar5 = (int *)0x0;
            if (uVar6 < local_40) {
              piVar5 = (int *)(uVar6 * 4 + local_3c);
            }
            iVar11 = *piVar5;
            FUN_00194208(&local_44);
            uVar6 = local_40;
            if (local_40 < local_44) {
              iVar1 = local_40 * 4;
              _memset((void *)(iVar1 + local_3c),0,4);
              local_40 = uVar6 + 1;
              piVar5 = (int *)(iVar1 + local_3c);
            }
            else {
              piVar5 = (int *)FUN_0019423c(&local_44,local_40);
            }
            *piVar5 = iVar11 + 1;
            local_58 = FUN_00105594(iVar8,iVar11 + 1);
            goto LAB_0013c9c8;
          }
        }
        FUN_00194208(&local_54,uVar7);
        FUN_00194208(&local_44,local_40 - 1);
        local_58 = iVar8;
LAB_0013c8f0:
        puVar4 = (undefined4 *)0x0;
        if (local_50 - 1 < local_50) {
          puVar4 = (undefined4 *)((local_50 - 1) * 4 + local_4c);
        }
        puVar3 = (undefined4 *)0x0;
        if (local_40 - 1 < local_40) {
          puVar3 = (undefined4 *)((local_40 - 1) * 4 + local_3c);
        }
        FUN_00138fb4(local_58,*puVar4,*puVar3,param_1);
      }
      bVar2 = false;
      uVar6 = local_50;
    } while( true );
  }
  goto LAB_0013c9ec;
code_r0x0013c9e8:
  iVar8 = *(int *)(param_1 + 0x3c4);
LAB_0013c9ec:
  uVar10 = uVar10 + 1;
  iVar9 = iVar9 + 4;
  goto LAB_0013c9f4;
}

/* FUN_0013ca84 @ 0x13ca84 (112 bytes) */
int FUN_0013ca84(param_1)
  int *param_1;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1[0x22] + 8) == 0x8e) {
    iVar2 = (**(code **)(*param_1 + 0x7c))();
    uVar1 = *(undefined4 *)(iVar2 + 300);
  }
  else {
    uVar1 = 0;
    if ((param_1[5] & 0x200U) != 0) {
      uVar1 = FUN_00105594(param_1,param_1[0x21]);
      return uVar1;
    }
  }
  return uVar1;
}

/* FUN_0013caf4 @ 0x13caf4 (1644 bytes) */
int FUN_0013caf4(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  bool bVar16;
  
  iVar3 = FUN_000e9294();
  if (((iVar3 != 0) && (iVar3 = (**(code **)(*param_1 + 0x40))(param_1), iVar3 == 0)) &&
     ((iVar3 = FUN_000e7804(param_1), *(int *)(*(int *)(iVar3 + 0x88) + 8) == 0x8b ||
      (iVar3 = FUN_000e7804(param_1), *(int *)(*(int *)(iVar3 + 0x88) + 8) == 0x8c)))) {
    iVar3 = param_1[0x4f];
    iVar13 = param_1[0x4d];
    iVar12 = param_1[0x4e];
    piVar14 = *(int **)(iVar3 + 0x98);
    piVar1 = (int *)piVar14[2];
    if (piVar1 == (int *)0x0) {
      iVar10 = 0;
      iVar11 = 0;
      iVar15 = 2;
    }
    else {
      iVar10 = 0;
      iVar15 = 0;
      iVar11 = 0;
      do {
        piVar2 = piVar1;
        if ((piVar14[5] & 1U) != 0) {
          iVar5 = (**(code **)(*piVar14 + 0x34))(piVar14);
          if (((iVar5 == 0) && (iVar5 = (**(code **)(*piVar14 + 0x38))(piVar14), iVar5 == 0)) &&
             (*(int *)(piVar14[0x22] + 8) == 0x8e)) {
            piVar1 = (int *)FUN_00105594(piVar14,1);
            iVar10 = iVar10 + 1;
            if ((iVar13 == piVar1[0x56]) && (iVar5 = (**(code **)(*piVar1 + 100))(), iVar5 != 0)) {
              for (iVar5 = 1; iVar4 = (**(code **)(*piVar1 + 0x14))(piVar1), iVar5 <= iVar4;
                  iVar5 = iVar5 + 1) {
                if ((((piVar1[iVar5 * 6 + 0x28] & 1U) != 0) ||
                    ((piVar1[iVar5 * 6 + 0x28] & 2U) != 0)) ||
                   (iVar4 = FUN_000f31e8(piVar1,iVar5), iVar4 == 0)) goto LAB_0013cd68;
              }
              if ((piVar1[0x48] != 0) || (piVar1[0x49] != 0)) goto LAB_0013cd68;
              if ((piVar1[0x20] != 0) &&
                 (((iVar5 = FUN_00126760(piVar1[0x26]), iVar5 != 0 && ((piVar1[5] & 2U) == 0)) &&
                  (iVar5 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar5 == 0)))) {
                iVar5 = 4;
                piVar2 = piVar1;
                do {
                  if (*(byte *)(piVar2 + 0x27) - 2 < 2) goto LAB_0013cd68;
                  piVar2 = (int *)((int)piVar2 + 1);
                  iVar5 = iVar5 + -1;
                } while (iVar5 != 0);
              }
              FUN_001054ec(piVar1,0);
              iVar5 = FUN_00105dbc(piVar1,0);
              if (((iVar5 != 0) || ((piVar1[5] & 2U) != 0)) ||
                 (((piVar1[5] & 0x200U) != 0 || (*(int *)(piVar1[4] + 4) != 1)))) goto LAB_0013cd68;
              iVar15 = iVar15 + 1;
              bVar16 = true;
            }
            else {
LAB_0013cd68:
              iVar5 = FUN_00139034(piVar1,param_1,iVar13,iVar12);
              bVar16 = iVar5 != 0;
            }
            piVar1 = (int *)FUN_00105594(piVar14,2);
            if ((iVar12 == piVar1[0x56]) && (iVar5 = (**(code **)(*piVar1 + 100))(), iVar5 != 0)) {
              for (iVar5 = 1; iVar4 = (**(code **)(*piVar1 + 0x14))(piVar1), iVar5 <= iVar4;
                  iVar5 = iVar5 + 1) {
                if ((((piVar1[iVar5 * 6 + 0x28] & 1U) != 0) ||
                    ((piVar1[iVar5 * 6 + 0x28] & 2U) != 0)) ||
                   (iVar4 = FUN_000f31e8(piVar1,iVar5), iVar4 == 0)) goto LAB_0013cee8;
              }
              if ((piVar1[0x48] != 0) || (piVar1[0x49] != 0)) goto LAB_0013cee8;
              if (((piVar1[0x20] != 0) &&
                  ((iVar5 = FUN_00126760(piVar1[0x26]), iVar5 != 0 && ((piVar1[5] & 2U) == 0)))) &&
                 (iVar5 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar5 == 0)) {
                iVar5 = 4;
                piVar2 = piVar1;
                do {
                  if (*(byte *)(piVar2 + 0x27) - 2 < 2) goto LAB_0013cee8;
                  piVar2 = (int *)((int)piVar2 + 1);
                  iVar5 = iVar5 + -1;
                } while (iVar5 != 0);
              }
              FUN_001054ec(piVar1,0);
              iVar5 = FUN_00105dbc(piVar1,0);
              if ((((iVar5 != 0) || ((piVar1[5] & 2U) != 0)) || ((piVar1[5] & 0x200U) != 0)) ||
                 (*(int *)(piVar1[4] + 4) != 1)) goto LAB_0013cee8;
              iVar11 = iVar11 + 1;
            }
            else {
LAB_0013cee8:
              iVar5 = FUN_00139034(piVar1,param_1,iVar13,iVar12);
              if (iVar5 == 0) {
                return;
              }
            }
            if (!bVar16) {
              return;
            }
          }
          piVar2 = (int *)piVar14[2];
        }
        piVar1 = (int *)piVar2[2];
        piVar14 = piVar2;
      } while ((int *)piVar2[2] != (int *)0x0);
      iVar15 = iVar15 + 2;
    }
    iVar5 = FUN_00194034(iVar13 + 0x90);
    if (((iVar15 == iVar5) && (iVar15 = FUN_00194034(iVar12 + 0x90), iVar15 == iVar11 + 2)) &&
       (iVar10 != 0)) {
      uVar6 = FUN_000e9184(param_1,0);
      iVar10 = FUN_000e7804(param_1);
      uVar9 = DAT_001b001c;
      if (*(int *)(*(int *)(iVar10 + 0x88) + 8) == 0x8c) {
        iVar11 = FUN_001054ec(iVar10,1);
        uVar9 = *(undefined4 *)(iVar11 + 0x10);
        FUN_000ef970(param_2,iVar10);
        bVar16 = *(int *)(iVar10 + 300) != 7;
        iVar10 = FUN_00105594(iVar10,1);
      }
      else {
        bVar16 = false;
        FUN_0010d4cc(iVar10,param_3);
        FUN_000e7688(uVar6,iVar10);
      }
      piVar1 = *(int **)(iVar3 + 0x98);
      for (piVar14 = (int *)piVar1[2]; piVar14 != (int *)0x0; piVar14 = (int *)piVar14[2]) {
        iVar3 = (**(code **)(*piVar1 + 0x34))(piVar1);
        if ((iVar3 == 0) && (iVar3 = (**(code **)(*piVar1 + 0x38))(piVar1), iVar3 == 0)) {
          if (*(int *)(piVar1[0x22] + 8) == 0x8e) {
            uVar7 = FUN_00105594(piVar1,1);
            uVar8 = FUN_00105594(piVar1,2);
            iVar3 = FUN_00139034(uVar7,param_1,iVar13,iVar12);
            if (iVar3 == 0) {
              FUN_0019401c(uVar7);
              FUN_000e7688(uVar6,uVar7);
            }
            iVar3 = FUN_00139034(uVar8,param_1,iVar13,iVar12);
            if (iVar3 == 0) {
              FUN_0019401c(uVar8);
              FUN_000e7688(uVar6,uVar8);
            }
            FUN_0010d730(piVar1,iVar10,uVar9,param_3);
            if ((*(int *)(piVar1[0x22] + 8) != 0x31) && (bVar16)) {
              FUN_0010ac38(piVar1,2,3,param_3);
            }
            FUN_000e7688(uVar6,piVar1);
          }
          else {
            FUN_0019401c(piVar1);
            FUN_000e7688(uVar6,piVar1);
          }
        }
        piVar1 = piVar14;
      }
    }
  }
  return;
}

/* FUN_0013d160 @ 0x13d160 (576 bytes) */
int FUN_0013d160(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x13);
  if (iVar2 != 0) {
    iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x17);
    if (iVar2 != 0) {
      FUN_0011fb94(param_1);
    }
    ((int (*)())FUN_0013c60c)(param_1);
    local_1c = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    local_24 = 0;
    local_28 = 2;
    local_20 = FUN_00193e18(local_1c,8);
    piVar3 = *(int **)(param_1 + 900);
    iVar2 = piVar3[2];
    while (iVar2 != 0) {
      iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3);
      if (iVar2 != 0) {
        *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
        FUN_00139f84(piVar3,&local_28);
      }
      piVar3 = (int *)piVar3[2];
      iVar2 = piVar3[2];
    }
    iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x18);
    if (((iVar2 != 0) && (iVar2 = FUN_000e0830(*(undefined4 *)(param_1 + 8),0,3), iVar2 == 0)) &&
       ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x20000) == 0)) {
      FUN_001394b0(param_1);
      ((int (*)())FUN_0013b3f0)(param_1);
    }
    FUN_00193cc0(local_1c,local_20);
  }
  piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
  (**(code **)(*piVar3 + 0x110))(piVar3,param_1);
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffffff7f;
  iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x19);
  if (iVar2 != 0) {
    piVar3 = *(int **)(param_1 + 900);
    for (piVar1 = (int *)(*(int **)(param_1 + 900))[2]; piVar1 != (int *)0x0;
        piVar1 = (int *)piVar1[2]) {
      iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3);
      if (iVar2 != 0) {
        ((int (*)())FUN_0013caf4)(piVar3,param_1,*(undefined4 *)(param_1 + 8));
      }
      piVar3 = piVar1;
    }
  }
  iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x37);
  if (iVar2 != 0) {
    FUN_001121b4(param_1);
  }
  ((int (*)())FUN_0013c210)(param_1);
  ((int (*)())FUN_0013bd68)(param_1,0);
  FUN_000ed7e4(param_1,"rewrite");
  iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x1f);
  if (iVar2 != 0) {
    FUN_0012ccc0(param_1);
  }
  return;
}

/* FUN_0013d3b8 @ 0x13d3b8 (1128 bytes) */
int FUN_0013d3b8(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int *piVar10;
  
  iVar2 = *(int *)(param_1 + 900);
  for (iVar5 = *(int *)(*(int *)(param_1 + 900) + 8); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
    piVar3 = (int *)(*(int **)(iVar2 + 0x98))[2];
    piVar10 = *(int **)(iVar2 + 0x98);
    if (piVar3 != (int *)0x0) {
      do {
        piVar4 = piVar3;
        if ((piVar10[5] & 1U) != 0) {
          piVar3 = (int *)(**(code **)(*piVar10 + 0x7c))(piVar10);
          if ((((piVar3 != (int *)0x0) && (piVar3[0x20] != 0)) &&
              (iVar5 = FUN_00126760(piVar3[0x26]), iVar5 != 0)) &&
             ((((piVar3[5] & 2U) == 0 && (iVar5 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar5 == 0)
               ) && ((piVar3[5] & 0x40U) == 0)))) {
            iVar5 = FUN_0010445c(piVar3,*(undefined4 *)(param_1 + 8),0);
            uVar8 = DAT_001b0034;
            *(undefined4 *)(iVar5 + 0x94) = *(undefined4 *)(iVar5 + 0x14c);
            *(undefined4 *)(iVar5 + 0x9c) = uVar8;
            FUN_000e7700(iVar2,piVar3,iVar5);
            iVar6 = FUN_0010445c(piVar3,*(undefined4 *)(param_1 + 8),0);
            uVar8 = DAT_001b0030;
            *(undefined4 *)(iVar6 + 0x94) = *(undefined4 *)(iVar6 + 0x14c);
            *(undefined4 *)(iVar6 + 0x9c) = uVar8;
            FUN_000e7700(iVar2,piVar3,iVar6);
            iVar7 = FUN_0010445c(piVar3,*(undefined4 *)(param_1 + 8),0);
            *(undefined4 *)(iVar7 + 0x9c) = DAT_001b002c;
            *(undefined4 *)(iVar7 + 0x94) = *(undefined4 *)(iVar7 + 0x14c);
            FUN_000e7700(iVar2,piVar3,iVar7);
            piVar3[0x27] = DAT_001b0028;
            *(undefined4 *)(iVar5 + 300) = 0;
            *(int *)(iVar6 + 300) = iVar5;
            *(int *)(iVar7 + 300) = iVar6;
            piVar3[0x4b] = iVar7;
          }
          iVar5 = (**(code **)(*piVar10 + 0x24))(piVar10);
          if (((iVar5 != 0) && (piVar10[0x20] != 0)) &&
             ((iVar5 = FUN_00126760(piVar10[0x26]), iVar5 != 0 &&
              ((((piVar10[5] & 2U) == 0 &&
                (iVar5 = (**(code **)(*piVar10 + 0x50))(piVar10), iVar5 == 0)) &&
               (iVar5 = FUN_00113420(*(undefined4 *)(piVar10[0x22] + 8),*(undefined4 *)(param_1 + 8)
                                    ), iVar5 == 0)))))) {
            iVar5 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x32);
            if (iVar5 == 0) {
              iVar5 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x30);
              if (iVar5 != 0) {
                iVar5 = FUN_001054ec(piVar10,0);
                uVar9 = *(uint *)(iVar5 + 0x10);
                iVar5 = FUN_000f2e18(uVar9);
                if (iVar5 == 0) {
                  iVar6 = FUN_0010445c(piVar10,*(undefined4 *)(param_1 + 8),0);
                  *(uint *)(iVar6 + 0x9c) = uVar9 & 0xffffff00 | 1;
                  uVar8 = *(undefined4 *)(iVar6 + 0x14c);
                  iVar7 = FUN_001054ec(iVar6,0);
                  iVar5 = DAT_001b0024;
                  *(undefined4 *)(iVar7 + 8) = uVar8;
                  piVar10[0x27] = iVar5;
                  FUN_00106804(piVar10,iVar6,0,*(undefined4 *)(param_1 + 8));
                  FUN_000e7700(iVar2,piVar10,iVar6);
                  for (iVar5 = 1; iVar6 = (**(code **)(*piVar10 + 0x14))(piVar10), iVar5 <= iVar6;
                      iVar5 = iVar5 + 1) {
                    piVar3 = (int *)FUN_00105594(piVar10,iVar5);
                    iVar6 = (**(code **)(*piVar3 + 0x5c))();
                    if (iVar6 != 0) {
                      iVar6 = FUN_0010445c(piVar3,*(undefined4 *)(param_1 + 8),0);
                      uVar8 = *(undefined4 *)(iVar6 + 0x14c);
                      iVar7 = FUN_001054ec(iVar6,0);
                      *(undefined4 *)(iVar7 + 8) = uVar8;
                      FUN_000e7738(piVar3[0x56],piVar3,iVar6);
                      FUN_00106004(piVar10,iVar5,iVar6,0,*(undefined4 *)(param_1 + 8));
                    }
                  }
                }
              }
            }
            else {
              iVar5 = FUN_000f3a30(piVar10);
              if (1 < iVar5) {
                iVar6 = 0;
                piVar3 = (int *)PTR_DAT_001e8b64;
                do {
                  iVar7 = FUN_001054ec(piVar10,0);
                  if (*(char *)(iVar6 + iVar7 + 0x10) != '\x01') {
                    if (iVar5 < 2) {
                      piVar10[0x27] = *piVar3;
                      FUN_000f35c4(piVar10);
                    }
                    else {
                      iVar7 = FUN_0010445c(piVar10,*(undefined4 *)(param_1 + 8),0);
                      *(int *)(iVar7 + 0x9c) = *piVar3;
                      FUN_000e7700(iVar2,piVar10,iVar7);
                      if ((piVar10[5] & 0x200U) != 0) {
                        uVar8 = FUN_00105594(piVar10,piVar10[0x21]);
                        FUN_00106804(iVar7,uVar8,0,*(undefined4 *)(param_1 + 8));
                      }
                      FUN_00106804(piVar10,iVar7,0,*(undefined4 *)(param_1 + 8));
                    }
                    iVar5 = iVar5 + -1;
                  }
                  bVar1 = iVar6 != 3;
                  piVar3 = piVar3 + 1;
                  iVar6 = iVar6 + 1;
                } while (bVar1);
              }
            }
          }
          piVar4 = (int *)piVar10[2];
        }
        piVar3 = (int *)piVar4[2];
        piVar10 = piVar4;
      } while ((int *)piVar4[2] != (int *)0x0);
      iVar5 = *(int *)(iVar2 + 8);
    }
    iVar2 = iVar5;
  }
  return;
}

/* FUN_0013d820 @ 0x13d820 (540 bytes) */
int FUN_0013d820(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 local_48;
  undefined4 local_44;
  int local_40 [7];
  
  uVar7 = *(undefined4 *)(param_2 + 8);
  iVar4 = (**(code **)(*param_1 + 100))();
  if ((iVar4 != 0) && ((param_1[5] & 0x200U) != 0)) {
    piVar5 = (int *)FUN_00105594(param_1,1);
    piVar6 = (int *)FUN_00105594(param_1,param_1[0x21]);
    iVar4 = (**(code **)(*piVar5 + 0x48))(piVar5);
    if ((iVar4 != 0) && (iVar4 = (**(code **)(*piVar6 + 0x2c))(piVar6), iVar4 != 0)) {
      iVar4 = FUN_001054ec(piVar6,0);
      local_48 = *(undefined4 *)(iVar4 + 0x10);
      iVar8 = 0;
      iVar4 = FUN_001054ec(param_1,0);
      local_44 = *(undefined4 *)(iVar4 + 0x10);
      local_40[0] = piVar6[0x50];
      do {
        cVar2 = *(char *)((int)local_40 + iVar8 + -4);
        if (cVar2 == '\0') {
          if (*(char *)((int)&local_48 + iVar8) != '\0') {
            return;
          }
          iVar4 = FUN_001054ec(param_1,1);
          uVar3 = (uint)*(byte *)(iVar8 + iVar4 + 0x10);
          if (((int)*(char *)(piVar5 + 0x57) >> (uVar3 & 0x3f) & 1U) == 0) {
            return;
          }
          if (piVar5[uVar3 * 6 + 7] != 2) {
            return;
          }
          if (((float)piVar5[uVar3 * 6 + 8] != FLOAT_001aa0d4) ||
             (*(char *)((int)local_40 + iVar8) != '\x05')) {
            if ((float)piVar5[uVar3 * 6 + 8] != FLOAT_001aa0e8) {
              return;
            }
            if (*(char *)((int)local_40 + iVar8) != '\x03') {
              return;
            }
          }
        }
        else if (cVar2 != '\x01') {
          return;
        }
        bVar1 = iVar8 != 3;
        iVar8 = iVar8 + 1;
      } while (bVar1);
      FUN_00106004(param_1,1,piVar6,0,uVar7);
      uVar7 = DAT_001b0004;
      param_1[0x27] = DAT_001b0008;
      iVar4 = FUN_001054ec(param_1,1);
      *(undefined4 *)(iVar4 + 0x10) = uVar7;
      FUN_00106004(param_1,param_1[0x21],0,0,*(undefined4 *)(param_2 + 8));
      param_1[0x21] = param_1[0x21] + -1;
      param_1[5] = param_1[5] & 0xfffffdff;
    }
  }
  return;
}

/* FUN_0013da3c @ 0x13da3c (6436 bytes) */
int FUN_0013da3c(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  undefined4 uVar19;
  int *piVar20;
  uint *puVar21;
  uint uVar22;
  int iVar23;
  uint *puVar24;
  int local_c8;
  uint local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_b8;
  uint local_b4;
  uint local_b0;
  int local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  uint local_a0;
  int local_9c;
  undefined4 local_98;
  undefined4 local_88;
  uint local_84;
  uint local_80;
  undefined4 local_7c;
  uint local_78;
  int local_74;
  uint local_70;
  uint local_6c;
  int local_68;
  uint local_64;
  int local_60;
  undefined4 local_5c;
  int local_58;
  undefined *local_54;
  
  uVar6 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x4e);
  if (uVar6 == 0) {
    iVar14 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x4f);
    if (iVar14 == 0) goto LAB_0013dcf0;
    local_98 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    iVar17 = 0;
    local_a4 = 2;
    local_a0 = uVar6;
    local_9c = FUN_00193e18(local_98,8);
    iVar14 = *(int *)(param_1 + 0x3c4);
    local_b8 = 0;
    for (uVar6 = 1; uVar22 = local_a0, uVar6 <= *(uint *)(iVar14 + 4); uVar6 = uVar6 + 1) {
      iVar18 = *(int *)(iVar17 + *(int *)(iVar14 + 8));
      local_b8 = iVar18;
      if (((*(uint *)(iVar18 + 0x14) & 1) != 0) && (*(int *)(iVar18 + 0x98) == 6)) {
        if (local_a0 < local_a4) {
          iVar14 = local_a0 * 4;
          _memset((void *)(iVar14 + local_9c),0,4);
          local_a0 = uVar22 + 1;
          piVar7 = (int *)(iVar14 + local_9c);
        }
        else {
          piVar7 = (int *)FUN_0019423c(&local_a4,local_a0);
        }
        *piVar7 = iVar18;
        *(uint *)(local_b8 + 0x14) = *(uint *)(local_b8 + 0x14) & 0xfffffff7;
        *(uint *)(local_b8 + 0x14) = *(uint *)(local_b8 + 0x14) & 0xffffffef;
        iVar14 = *(int *)(param_1 + 0x3c4);
      }
      iVar17 = iVar17 + 4;
    }
    while (local_a0 != 0) {
      puVar9 = (undefined4 *)0x0;
      if (local_a0 - 1 < local_a0) {
        puVar9 = (undefined4 *)((local_a0 - 1) * 4 + local_9c);
      }
      uVar19 = *puVar9;
      FUN_00194208(&local_a4);
      FUN_000ef970(param_1,uVar19);
    }
  }
  else {
    local_98 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    local_a4 = 2;
    iVar17 = 0;
    local_a0 = 0;
    local_9c = FUN_00193e18(local_98,8);
    iVar14 = *(int *)(param_1 + 0x3c4);
    local_b8 = 0;
    for (uVar6 = 1; uVar22 = local_a0, uVar6 <= *(uint *)(iVar14 + 4); uVar6 = uVar6 + 1) {
      iVar18 = *(int *)(iVar17 + *(int *)(iVar14 + 8));
      local_b8 = iVar18;
      if (((*(uint *)(iVar18 + 0x14) & 1) != 0) && (*(int *)(iVar18 + 0x98) != 6)) {
        if (local_a0 < local_a4) {
          iVar14 = local_a0 * 4;
          _memset((void *)(iVar14 + local_9c),0,4);
          local_a0 = uVar22 + 1;
          piVar7 = (int *)(iVar14 + local_9c);
        }
        else {
          piVar7 = (int *)FUN_0019423c(&local_a4,local_a0);
        }
        *piVar7 = iVar18;
        *(uint *)(local_b8 + 0x14) = *(uint *)(local_b8 + 0x14) & 0xfffffff7;
        *(uint *)(local_b8 + 0x14) = *(uint *)(local_b8 + 0x14) & 0xffffffef;
        iVar14 = *(int *)(param_1 + 0x3c4);
      }
      iVar17 = iVar17 + 4;
    }
    while (local_a0 != 0) {
      puVar9 = (undefined4 *)0x0;
      if (local_a0 - 1 < local_a0) {
        puVar9 = (undefined4 *)((local_a0 - 1) * 4 + local_9c);
      }
      uVar19 = *puVar9;
      FUN_00194208(&local_a4);
      FUN_000ef970(param_1,uVar19);
    }
  }
  FUN_00193cc0(local_98,local_9c);
LAB_0013dcf0:
  local_a8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_b0 = 0;
  local_b4 = 2;
  local_ac = FUN_00193e18(local_a8,8);
  iVar14 = *(int *)(*(int *)(param_1 + 8) + 0x324) << 2;
  iVar18 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),iVar14);
  iVar8 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),iVar14);
  local_58 = param_1 + 0x37c;
  iVar14 = *(int *)(param_1 + 900);
  for (iVar17 = *(int *)(*(int *)(param_1 + 900) + 8); iVar17 != 0; iVar17 = *(int *)(iVar17 + 8)) {
    piVar20 = *(int **)(iVar14 + 0x98);
    piVar7 = (int *)piVar20[2];
    if ((int *)piVar20[2] != (int *)0x0) {
      do {
        piVar15 = piVar7;
        if ((piVar20[5] & 1U) != 0) {
          *(int *)(piVar20[0x53] * 4 + iVar18) = piVar20[0x53];
          *(undefined4 *)(iVar8 + piVar20[0x53] * 4) = 0;
          iVar17 = (**(code **)(*piVar20 + 0x48))(piVar20);
          if (iVar17 != 0) {
            piVar20[0x27] = DAT_001b0008;
          }
          piVar20[3] = 0;
          ((int (*)())FUN_0013d820)(piVar20,param_1);
          uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
          puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x14);
          *puVar9 = uVar19;
          puVar9[1] = 2;
          puVar9[2] = 0;
          puVar9[4] = uVar19;
          uVar19 = FUN_00193e18(uVar19,8);
          puVar9[3] = uVar19;
          piVar15 = (int *)piVar20[2];
          piVar20[4] = (int)(puVar9 + 1);
        }
        piVar7 = (int *)piVar15[2];
        piVar20 = piVar15;
      } while ((int *)piVar15[2] != (int *)0x0);
      iVar17 = *(int *)(iVar14 + 8);
    }
    iVar14 = iVar17;
  }
  iVar14 = *(int *)(param_1 + 0x3c4);
  iVar17 = 0;
  local_b8 = 0;
  for (uVar6 = 1; uVar6 <= *(uint *)(iVar14 + 4); uVar6 = uVar6 + 1) {
    iVar23 = *(int *)(iVar17 + *(int *)(iVar14 + 8));
    local_b8 = iVar23;
    if ((*(uint *)(iVar23 + 0x14) & 1) != 0) {
      iVar14 = FUN_001054ec(iVar23,0);
      FUN_000f3908(&local_88,*(undefined4 *)(iVar14 + 0x10));
      uVar22 = local_b0;
      iVar14 = local_b8;
      *(undefined4 *)(iVar23 + 0xc) = local_88;
      if (local_b0 < local_b4) {
        iVar23 = local_b0 * 4;
        _memset((void *)(iVar23 + local_ac),0,4);
        local_b0 = uVar22 + 1;
        piVar7 = (int *)(iVar23 + local_ac);
      }
      else {
        piVar7 = (int *)FUN_0019423c(&local_b4,local_b0);
      }
      *piVar7 = iVar14;
      iVar14 = *(int *)(param_1 + 0x3c4);
    }
    iVar17 = iVar17 + 4;
  }
  do {
    do {
      if (local_b0 == 0) {
        iVar14 = *(int *)(local_58 + 8);
        iVar17 = *(int *)(iVar14 + 8);
        if (*(int *)(iVar14 + 8) != 0) {
          do {
            iVar23 = iVar17;
            piVar7 = (int *)(*(int **)(iVar14 + 0x98))[2];
            piVar20 = *(int **)(iVar14 + 0x98);
            if (piVar7 != (int *)0x0) {
              do {
                piVar15 = piVar7;
                if ((piVar20[5] & 1U) != 0) {
                  iVar17 = FUN_001054ec(piVar20,0);
                  FUN_000f31f8(&local_74,*(undefined4 *)(iVar17 + 0x10),piVar20[3]);
                  iVar17 = local_74;
                  if (((((piVar20[0x20] != 0) && (iVar23 = FUN_00126760(piVar20[0x26]), iVar23 != 0)
                        ) && (((piVar20[5] & 2U) == 0 &&
                              (iVar23 = (**(code **)(*piVar20 + 0x50))(piVar20), iVar23 == 0)))) ||
                      ((iVar23 = FUN_00126708(piVar20[0x26]), iVar23 != 0 ||
                       (iVar23 = FUN_00126734(piVar20[0x26]), iVar23 != 0)))) &&
                     ((piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c),
                      iVar23 = (**(code **)(*piVar7 + 0x7c))(piVar7,piVar20), iVar23 != 0 &&
                      (iVar23 = FUN_001054ec(piVar20,0), iVar17 != *(int *)(iVar23 + 0x10))))) {
                    piVar20[0x27] = iVar17;
                  }
                  if (piVar20[3] != 0) {
                    iVar23 = piVar20[0x21];
                    if ((piVar20[5] & 0x200U) != 0) {
                      iVar23 = iVar23 + -1;
                    }
                    iVar11 = (**(code **)(*piVar20 + 0x60))(piVar20);
                    if (iVar11 != 0) {
                      if (0 < iVar23) {
                        iVar11 = 1;
                        do {
                          local_a4 = DAT_001b0020;
                          iVar12 = (**(code **)(*piVar20 + 0x14))(piVar20);
                          if (iVar11 <= iVar12) {
                            FUN_000f3c30(&local_70,piVar20,iVar11,param_1,iVar17);
                            iVar12 = DAT_001b0000;
                            local_a4 = local_70;
                            uVar6 = local_a4;
                            (*(unsigned char *)((unsigned char *)&(local_a4) + 3)) = (char)local_70;
                            (*(unsigned char *)((unsigned char *)&(local_a4) + 2)) = (char)(local_70 >> 8);
                            (*(unsigned char *)((unsigned char *)&(local_a4) + 1)) = (char)(local_70 >> 0x10);
                            (*(unsigned char *)((unsigned char *)&(local_a4) + 0)) = (char)(local_70 >> 0x18);
                            bVar3 = (char)local_a4 == '\0';
                            bVar4 = (*(unsigned char *)((unsigned char *)&(local_a4) + 2)) == '\0';
                            bVar2 = (*(unsigned char *)((unsigned char *)&(local_a4) + 1)) == '\0';
                            bVar1 = (*(unsigned char *)((unsigned char *)&(local_a4) + 0)) == '\0';
                            local_a4 = uVar6;
                            if (((bVar3 && bVar4) && bVar2) && bVar1) {
                              if (iVar11 == 0) {
                                piVar20[0x27] = DAT_001b0000;
                              }
                              else {
                                iVar13 = FUN_001054ec(piVar20,iVar11);
                                *(int *)(iVar13 + 0x10) = iVar12;
                              }
                            }
                          }
                          iVar11 = iVar11 + 1;
                        } while (iVar11 <= iVar23);
                      }
                      FUN_0010c37c(piVar20,*(undefined4 *)(param_1 + 8));
                      iVar23 = piVar20[0x21];
                      if ((piVar20[5] & 0x200U) != 0) {
                        iVar23 = iVar23 + -1;
                      }
                    }
                    if (0 < iVar23) {
                      iVar11 = 1;
                      do {
                        uVar6 = DAT_001b0020;
                        piVar7 = (int *)FUN_00105594(piVar20,iVar11);
                        iVar12 = (**(code **)(*piVar20 + 0x14))(piVar20);
                        if (iVar11 <= iVar12) {
                          FUN_000f3c30(&local_6c,piVar20,iVar11,param_1,iVar17);
                          uVar6 = local_6c;
                        }
                        iVar12 = FUN_001396d0(*(undefined4 *)(param_1 + 8),piVar20,iVar11,param_1);
                        uVar22 = DAT_001b0020;
                        if (iVar12 == 0) {
                          iVar12 = (**(code **)(*piVar20 + 0x14))(piVar20);
                          if (iVar11 <= iVar12) {
                            FUN_000f403c(&local_64,piVar20,iVar11,piVar20[3],param_1);
                            uVar22 = local_64;
                          }
                          if (piVar7 != (int *)0x0) {
                            if (((((piVar7[0x20] != 0) &&
                                  (iVar12 = FUN_00126760(piVar7[0x26]), iVar12 != 0)) &&
                                 ((piVar7[5] & 2U) == 0)) &&
                                (iVar12 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar12 == 0)) ||
                               ((iVar12 = FUN_00126708(piVar7[0x26]), iVar12 != 0 ||
                                (iVar12 = FUN_00126734(piVar7[0x26]), iVar12 != 0)))) {
                              while( true ) {
                                uVar5 = uVar22 & piVar7[3];
                                (*(unsigned char *)((unsigned char *)&(local_bc) + 3)) = (char)uVar5;
                                (*(unsigned char *)((unsigned char *)&(local_bc) + 2)) = (char)(uVar5 >> 8);
                                (*(unsigned char *)((unsigned char *)&(local_bc) + 1)) = (char)(uVar5 >> 0x10);
                                (*(unsigned char *)((unsigned char *)&(local_bc) + 0)) = (char)(uVar5 >> 0x18);
                                local_bc = uVar5;
                                if ((((char)local_bc != '\0' || (*(unsigned char *)((unsigned char *)&(local_bc) + 2)) != '\0') ||
                                    (*(unsigned char *)((unsigned char *)&(local_bc) + 1)) != '\0') || (*(unsigned char *)((unsigned char *)&(local_bc) + 0)) != '\0') break;
                                piVar7 = (int *)((int (*)())FUN_0013ca84)(piVar7);
                              }
                              FUN_00106004(piVar20,iVar11,piVar7,0,*(undefined4 *)(param_1 + 8));
                              iVar12 = FUN_001054ec(piVar20,iVar11);
                              FUN_000f3340(&local_60,*(undefined4 *)(iVar12 + 0x10),uVar6);
                              iVar12 = local_60;
                              iVar13 = FUN_001054ec(piVar20,iVar11);
                              if (*(int *)(iVar13 + 0x10) != DAT_001b0000) {
                                puVar21 = (uint *)piVar7[4];
                                uVar6 = puVar21[1];
                                if (uVar6 < *puVar21) {
                                  _memset((void *)(uVar6 * 4 + puVar21[2]),0,4);
                                  puVar9 = (undefined4 *)(uVar6 * 4 + puVar21[2]);
                                  puVar21[1] = uVar6 + 1;
                                }
                                else {
                                  puVar9 = (undefined4 *)FUN_0019423c(puVar21,uVar6);
                                }
                                *puVar9 = piVar20;
                              }
                              FUN_001396a0(piVar7,piVar20);
                              goto LAB_0013e80c;
                            }
                            puVar21 = (uint *)piVar7[4];
                            uVar6 = puVar21[1];
                            if (uVar6 < *puVar21) {
                              _memset((void *)(uVar6 * 4 + puVar21[2]),0,4);
                              puVar9 = (undefined4 *)(uVar6 * 4 + puVar21[2]);
                              puVar21[1] = uVar6 + 1;
                            }
                            else {
                              puVar9 = (undefined4 *)FUN_0019423c(puVar21,uVar6);
                            }
                            *puVar9 = piVar20;
                          }
                        }
                        else {
                          iVar12 = FUN_001045e4(piVar20);
                          uVar19 = DAT_001b0004;
                          if (iVar12 != 0) {
                            uVar19 = DAT_001b001c;
                          }
                          iVar12 = FUN_0011346c(*(undefined4 *)(param_1 + 8),piVar20);
                          if (iVar12 != 0) {
                            if (iVar11 == 1) {
                              puVar9 = &DAT_001b0018;
                            }
                            else {
                              puVar9 = &DAT_001b001c;
                            }
                            uVar19 = *puVar9;
                          }
                          FUN_000f3340(&local_68,uVar19,uVar6);
                          iVar12 = local_68;
                          iVar13 = FUN_00105594(piVar20,iVar11);
                          puVar21 = *(uint **)(iVar13 + 0x10);
                          if (puVar21 == (uint *)0x0) {
                            uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
                            puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x14);
                            puVar21 = puVar9 + 1;
                            *puVar9 = uVar19;
                            puVar9[1] = 2;
                            puVar9[2] = 0;
                            puVar9[4] = uVar19;
                            uVar19 = FUN_00193e18(uVar19,8);
                            puVar9[3] = uVar19;
                            *(uint **)(iVar13 + 0x10) = puVar21;
                          }
                          uVar6 = puVar21[1];
                          if (uVar6 < *puVar21) {
                            _memset((void *)(uVar6 * 4 + puVar21[2]),0,4);
                            puVar9 = (undefined4 *)(uVar6 * 4 + puVar21[2]);
                            puVar21[1] = uVar6 + 1;
                          }
                          else {
                            puVar9 = (undefined4 *)FUN_0019423c(puVar21,uVar6);
                          }
                          *puVar9 = piVar20;
LAB_0013e80c:
                          iVar13 = FUN_001054ec(piVar20,iVar11);
                          if (iVar12 != *(int *)(iVar13 + 0x10)) {
                            if (iVar11 == 0) {
                              piVar20[0x27] = iVar12;
                            }
                            else {
                              iVar13 = FUN_001054ec(piVar20,iVar11);
                              *(int *)(iVar13 + 0x10) = iVar12;
                            }
                          }
                        }
                        iVar11 = iVar11 + 1;
                      } while (iVar11 <= iVar23);
                    }
                  }
                  if ((((piVar20[0x20] == 0) || (iVar17 = FUN_00126760(piVar20[0x26]), iVar17 == 0))
                      || (((piVar20[5] & 2U) != 0 ||
                          (iVar17 = (**(code **)(*piVar20 + 0x50))(piVar20), iVar17 != 0)))) &&
                     ((iVar17 = FUN_00126708(piVar20[0x26]), iVar17 == 0 &&
                      (iVar17 = FUN_00126734(piVar20[0x26]), iVar17 == 0)))) {
                    piVar15 = (int *)piVar20[2];
                  }
                  else {
                    iVar17 = 0;
                    if (piVar20[3] != 0) {
                      iVar17 = ((int (*)())FUN_0013ca84)(piVar20);
                    }
                    iVar23 = FUN_001952d8(piVar20[0x53],iVar18);
                    while ((iVar17 != 0 &&
                           ((iVar11 = FUN_001952d8(*(undefined4 *)(iVar17 + 0x14c),iVar18),
                            iVar23 != iVar11 || (iVar11 = FUN_000f497c(iVar17,piVar20), iVar11 == 0)
                            )))) {
                      iVar17 = ((int (*)())FUN_0013ca84)(iVar17);
                    }
                    *(int *)(iVar8 + piVar20[0x53] * 4) = iVar17;
                    piVar15 = (int *)piVar20[2];
                  }
                }
                piVar7 = (int *)piVar15[2];
                piVar20 = piVar15;
              } while ((int *)piVar15[2] != (int *)0x0);
              iVar23 = *(int *)(iVar14 + 8);
            }
            iVar17 = *(int *)(iVar23 + 8);
            iVar14 = iVar23;
          } while (*(int *)(iVar23 + 8) != 0);
          iVar14 = *(int *)(local_58 + 8);
        }
        iVar17 = *(int *)(iVar14 + 8);
        while (iVar18 = iVar17, iVar18 != 0) {
          piVar7 = (int *)(*(int **)(iVar14 + 0x98))[2];
          piVar20 = *(int **)(iVar14 + 0x98);
          if (piVar7 != (int *)0x0) {
            do {
              piVar15 = piVar7;
              if ((piVar20[5] & 1U) != 0) {
                if (((((piVar20[0x20] != 0) && (iVar17 = FUN_00126760(piVar20[0x26]), iVar17 != 0))
                     && ((piVar20[5] & 2U) == 0)) &&
                    (iVar17 = (**(code **)(*piVar20 + 0x50))(piVar20), iVar17 == 0)) ||
                   ((iVar17 = FUN_00126708(piVar20[0x26]), iVar17 != 0 ||
                    (iVar17 = FUN_00126734(piVar20[0x26]), iVar17 != 0)))) {
                  iVar17 = FUN_001054ec(piVar20,0);
                  if (*(int *)(iVar17 + 0x10) != DAT_001b0014) {
                    FUN_0010d358(piVar20,*(undefined4 *)(param_1 + 8));
                  }
                  if ((piVar20[5] & 0x200U) != 0) {
                    iVar17 = *(int *)(iVar8 + piVar20[0x53] * 4);
                    if (iVar17 == 0) {
                      FUN_00106004(piVar20,piVar20[0x21],0,0,*(undefined4 *)(param_1 + 8));
                      piVar20[0x21] = piVar20[0x21] + -1;
                      piVar20[5] = piVar20[5] & 0xfffffdff;
                    }
                    else {
                      FUN_00106804(piVar20,iVar17,0,*(undefined4 *)(param_1 + 8));
                      iVar18 = DAT_001b0000;
                      if (piVar20[0x21] == 0) {
                        piVar20[0x27] = DAT_001b0000;
                      }
                      else {
                        iVar23 = FUN_001054ec(piVar20);
                        *(int *)(iVar23 + 0x10) = iVar18;
                      }
                      puVar21 = *(uint **)(iVar17 + 0x10);
                      uVar6 = puVar21[1];
                      if (uVar6 < *puVar21) {
                        _memset((void *)(uVar6 * 4 + puVar21[2]),0,4);
                        puVar9 = (undefined4 *)(uVar6 * 4 + puVar21[2]);
                        puVar21[1] = uVar6 + 1;
                      }
                      else {
                        puVar9 = (undefined4 *)FUN_0019423c(puVar21,uVar6);
                      }
                      *puVar9 = piVar20;
                      *(uint *)(iVar17 + 0x14) = *(uint *)(iVar17 + 0x14) | 0x400000;
                    }
                  }
                  if (((piVar20[0x48] != 0) || (piVar20[0x49] != 0)) &&
                     (((piVar20[5] & 0x200U) != 0 &&
                      (piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c),
                      iVar17 = (**(code **)(*piVar7 + 0x7c))(piVar7,piVar20), iVar17 == 0)))) {
                    iVar18 = FUN_0010445c(piVar20,*(undefined4 *)(param_1 + 8),0);
                    uVar19 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
                    puVar9 = (undefined4 *)FUN_00193e18(uVar19,0x14);
                    *puVar9 = uVar19;
                    puVar9[1] = 2;
                    puVar9[2] = 0;
                    puVar9[4] = uVar19;
                    uVar19 = FUN_00193e18(uVar19,8);
                    puVar9[3] = uVar19;
                    *(undefined4 **)(iVar18 + 0x10) = puVar9 + 1;
                    FUN_000e7700(iVar14,piVar20,iVar18);
                    iVar17 = piVar20[4];
                    FUN_0019401c(piVar20);
                    FUN_00108448(piVar20,0x31,*(undefined4 *)(param_1 + 8));
                    piVar20[4] = iVar17;
                    piVar20[0x25] = piVar20[0x53];
                    piVar20[0x26] = 0;
                    FUN_00106004(piVar20,1,iVar18,0,*(undefined4 *)(param_1 + 8));
                    uVar19 = FUN_00105594(iVar18,*(undefined4 *)(iVar18 + 0x84));
                    FUN_00106804(piVar20,uVar19,0,*(undefined4 *)(param_1 + 8));
                    iVar17 = DAT_001b0000;
                    if (piVar20[0x21] == 0) {
                      piVar20[0x27] = DAT_001b0000;
                    }
                    else {
                      iVar23 = FUN_001054ec(piVar20);
                      *(int *)(iVar23 + 0x10) = iVar17;
                    }
                    puVar21 = *(uint **)(iVar18 + 0x10);
                    uVar6 = puVar21[1];
                    if (uVar6 < *puVar21) {
                      _memset((void *)(uVar6 * 4 + puVar21[2]),0,4);
                      puVar9 = (undefined4 *)(uVar6 * 4 + puVar21[2]);
                      puVar21[1] = uVar6 + 1;
                    }
                    else {
                      puVar9 = (undefined4 *)FUN_0019423c(puVar21,uVar6);
                    }
                    *puVar9 = piVar20;
                    FUN_00106004(iVar18,*(undefined4 *)(iVar18 + 0x84),0,0,
                                 *(undefined4 *)(param_1 + 8));
                    iVar17 = *(int *)(iVar18 + 0x84) + -1;
                    *(int *)(iVar18 + 0x84) = iVar17;
                    *(uint *)(iVar18 + 0x14) = *(uint *)(iVar18 + 0x14) & 0xfffffdff;
                    *(int *)(iVar18 + 0x160) =
                         *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x6c4) + 0x478) + 1;
                    if (0 < iVar17) {
                      iVar17 = 1;
                      do {
                        iVar23 = FUN_00105594(iVar18,iVar17);
                        uVar6 = (*(uint **)(iVar23 + 0x10))[1];
                        if (uVar6 != 0) {
                          uVar22 = 0;
                          puVar21 = *(uint **)(iVar23 + 0x10);
                          do {
                            if (uVar22 < *puVar21) {
                              puVar24 = puVar21;
                              if (uVar6 <= uVar22) {
                                _memset((void *)(uVar6 * 4 + puVar21[2]),0,(uVar22 - uVar6) * 4 + 4)
                                ;
                                puVar21[1] = uVar22 + 1;
                                puVar24 = *(uint **)(iVar23 + 0x10);
                              }
                              piVar7 = (int *)(uVar22 * 4 + puVar21[2]);
                            }
                            else {
                              piVar7 = (int *)FUN_0019423c(puVar21,uVar22);
                              puVar24 = *(uint **)(iVar23 + 0x10);
                            }
                            if (piVar20 == (int *)*piVar7) {
                              FUN_00194208(puVar24,uVar22);
                              puVar21 = *(uint **)(iVar23 + 0x10);
                              uVar6 = puVar21[1];
                              if (uVar6 < *puVar21) {
                                _memset((void *)(uVar6 * 4 + puVar21[2]),0,4);
                                piVar7 = (int *)(uVar6 * 4 + puVar21[2]);
                                puVar21[1] = uVar6 + 1;
                              }
                              else {
                                piVar7 = (int *)FUN_0019423c(puVar21,uVar6);
                              }
                              *piVar7 = iVar18;
                              break;
                            }
                            uVar6 = puVar24[1];
                            uVar22 = uVar22 + 1;
                            puVar21 = puVar24;
                          } while (uVar22 < uVar6);
                        }
                        iVar17 = iVar17 + 1;
                      } while (iVar17 <= *(int *)(iVar18 + 0x84));
                    }
                    FUN_000e7738(iVar14,iVar18,piVar20);
                  }
                }
                piVar15 = (int *)piVar20[2];
              }
              piVar7 = (int *)piVar15[2];
              piVar20 = piVar15;
            } while ((int *)piVar15[2] != (int *)0x0);
            iVar18 = *(int *)(iVar14 + 8);
          }
          iVar14 = iVar18;
          iVar17 = *(int *)(iVar18 + 8);
        }
        iVar14 = *(int *)(param_1 + 0x3c4);
        iVar17 = 0;
        *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
        local_b8 = 0;
        for (uVar6 = 1; uVar22 = local_b0, uVar6 <= *(uint *)(iVar14 + 4); uVar6 = uVar6 + 1) {
          iVar18 = *(int *)(*(int *)(iVar14 + 8) + iVar17);
          local_b8 = iVar18;
          if ((*(uint *)(iVar18 + 0x14) & 1) != 0) {
            if (local_b0 < local_b4) {
              iVar14 = local_b0 * 4;
              _memset((void *)(iVar14 + local_ac),0,4);
              local_b0 = uVar22 + 1;
              piVar7 = (int *)(iVar14 + local_ac);
            }
            else {
              piVar7 = (int *)FUN_0019423c(&local_b4,local_b0);
            }
            *piVar7 = iVar18;
            iVar14 = *(int *)(param_1 + 0x3c4);
          }
          iVar17 = iVar17 + 4;
        }
        do {
          do {
            if (local_b0 == 0) {
              *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x20000;
              FUN_000ed7e4(param_1,"reduce");
              *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x80;
              FUN_00193cc0(local_a8,local_ac);
              return;
            }
            piVar7 = (int *)0x0;
            if (local_b0 - 1 < local_b0) {
              piVar7 = (int *)((local_b0 - 1) * 4 + local_ac);
            }
            iVar17 = *piVar7;
            FUN_00194208(&local_b4);
            iVar14 = *(int *)(iVar17 + 0x84);
            *(undefined4 *)(iVar17 + 0x150) = *(undefined4 *)(param_1 + 0x474);
            if ((*(uint *)(iVar17 + 0x14) & 0x200) != 0) {
              iVar14 = iVar14 + -1;
            }
          } while (iVar14 < 1);
          iVar18 = 1;
          do {
            piVar7 = (int *)FUN_00105594(iVar17,iVar18);
            uVar6 = local_b0;
            if (piVar7 != (int *)0x0) {
              if (*(int *)(param_1 + 0x474) != piVar7[0x54]) {
                if (local_b0 < local_b4) {
                  iVar8 = local_b0 * 4;
                  _memset((void *)(iVar8 + local_ac),0,4);
                  local_b0 = uVar6 + 1;
                  puVar9 = (undefined4 *)(iVar8 + local_ac);
                }
                else {
                  puVar9 = (undefined4 *)FUN_0019423c(&local_b4,local_b0);
                }
                *puVar9 = piVar7;
              }
              if (((((piVar7[0x20] != 0) && (iVar8 = FUN_00126760(piVar7[0x26]), iVar8 != 0)) &&
                   ((piVar7[5] & 2U) == 0)) &&
                  (iVar8 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar8 == 0)) ||
                 ((iVar8 = FUN_00126708(piVar7[0x26]), iVar8 != 0 ||
                  (iVar8 = FUN_00126734(piVar7[0x26]), iVar8 != 0)))) {
                iVar8 = FUN_001054ec(iVar17,iVar18);
                FUN_000f3398(&local_5c,*(undefined4 *)(iVar8 + 0x10));
                iVar8 = 0;
                local_c0 = local_5c;
                piVar20 = piVar7;
LAB_0013f320:
                do {
                  iVar23 = FUN_0012678c(piVar20[0x26]);
                  uVar6 = local_b0;
                  if (iVar23 == 0) {
                    if (*(int *)(param_1 + 0x474) != piVar20[0x54]) {
                      if (local_b0 < local_b4) {
                        iVar23 = local_b0 * 4;
                        _memset((void *)(iVar23 + local_ac),0,4);
                        puVar9 = (undefined4 *)(iVar23 + local_ac);
                        local_b0 = uVar6 + 1;
                      }
                      else {
                        puVar9 = (undefined4 *)FUN_0019423c(&local_b4,local_b0);
                      }
                      *puVar9 = piVar20;
                    }
                    local_a4 = piVar20[3];
                    if ((*(char *)((int)&local_c0 + iVar8) != '\0') &&
                       (*(char *)((int)&local_a4 + iVar8) == '\0')) {
                      iVar11 = piVar20[0x21];
                      iVar23 = FUN_001054ec(piVar20,iVar11);
                      local_c8 = *(int *)(iVar23 + 0x10);
                      if (*(char *)((int)&local_c8 + iVar8) == '\x04') {
                        *(char *)((int)&local_c8 + iVar8) = (char)iVar8;
                        iVar23 = local_c8;
                        if (iVar11 == 0) {
                          piVar20[0x27] = local_c8;
                        }
                        else {
                          iVar11 = FUN_001054ec(piVar20,iVar11);
                          *(int *)(iVar11 + 0x10) = iVar23;
                        }
                        piVar20 = (int *)FUN_00105594(piVar20,piVar20[0x21]);
                        if (piVar20 != (int *)0x0) goto LAB_0013f320;
                      }
                    }
                  }
                  bVar1 = iVar8 != 3;
                  iVar8 = iVar8 + 1;
                  piVar20 = piVar7;
                } while (bVar1);
              }
            }
            iVar18 = iVar18 + 1;
          } while (iVar18 <= iVar14);
        } while( true );
      }
      puVar9 = (undefined4 *)0x0;
      if (local_b0 - 1 < local_b0) {
        puVar9 = (undefined4 *)((local_b0 - 1) * 4 + local_ac);
      }
      piVar7 = (int *)*puVar9;
      FUN_00194208(&local_b4);
      iVar14 = (**(code **)(*piVar7 + 0x30))(piVar7);
      if (((iVar14 != 0) && (-1 < piVar7[0x4d])) &&
         (*(int *)(piVar7[0x4d] * 0xc + *(int *)(param_1 + 0x78) + 4) - 10U < 2)) {
        uVar19 = FUN_00105594(piVar7,1);
        piVar20 = (int *)FUN_001382b8(uVar19,3,&local_b8);
        if ((piVar20 != (int *)0x0) && (iVar14 = (**(code **)(*piVar20 + 0x50))(), iVar14 != 0)) {
          (**(code **)(*piVar7 + 0x88))(piVar7,1,3,4);
        }
      }
      if ((piVar7[5] & 0x200U) == 0) {
        iVar14 = piVar7[0x21];
      }
      else {
        iVar14 = piVar7[0x21] + -1;
      }
    } while (iVar14 < 1);
    iVar17 = 1;
    local_54 = &DAT_001ada48;
    do {
      piVar20 = (int *)FUN_00105594(piVar7,iVar17);
      if (piVar20 != (int *)0x0) {
        if ((((piVar20[0x20] == 0) || (iVar23 = FUN_00126760(piVar20[0x26]), iVar23 == 0)) ||
            (((piVar20[5] & 2U) != 0 ||
             (iVar23 = (**(code **)(*piVar20 + 0x50))(piVar20), iVar23 != 0)))) &&
           (iVar23 = FUN_00126708(piVar20[0x26]), iVar23 == 0)) {
          iVar23 = FUN_00126734(piVar20[0x26]);
          bVar1 = false;
          if (iVar23 != 0) goto LAB_0013e0ac;
        }
        else {
LAB_0013e0ac:
          bVar1 = true;
        }
        local_a4 = *(uint *)(local_54 + 0x25d8);
        iVar23 = (**(code **)(*piVar7 + 0x14))(piVar7);
        if (iVar17 <= iVar23) {
          FUN_000f403c(&local_84,piVar7,iVar17,piVar7[3],param_1);
          local_a4 = local_84;
        }
        iVar23 = DAT_001b0000;
        if ((((char)local_a4 == '\0' && (*(unsigned char *)((unsigned char *)&(local_a4) + 2)) == '\0') && (*(unsigned char *)((unsigned char *)&(local_a4) + 1)) == '\0') &&
            (*(unsigned char *)((unsigned char *)&(local_a4) + 0)) == '\0') {
          if (iVar17 == 0) {
            piVar7[0x27] = DAT_001b0000;
          }
          else {
            iVar11 = FUN_001054ec(piVar7,iVar17);
            *(int *)(iVar11 + 0x10) = iVar23;
          }
        }
        bVar1 = !bVar1;
        if (bVar1) {
          local_a4 = 0x1000000;
        }
        iVar23 = -1;
        while (local_a4 != 0) {
          if (*(int *)(piVar20[0x22] + 8) == 0x8e) {
            iVar11 = (**(code **)(*piVar20 + 0x7c))(piVar20);
            uVar6 = local_a4;
            if (iVar11 == 0) {
              iVar12 = 0;
            }
            else {
              iVar13 = iVar23;
              iVar16 = 0;
              do {
                iVar10 = FUN_001952d8(*(undefined4 *)(iVar11 + 0x14c),iVar18);
                iVar23 = FUN_001054ec(iVar11,0);
                FUN_000f3908(&local_80,*(undefined4 *)(iVar23 + 0x10));
                if ((iVar13 == iVar10) ||
                   (iVar23 = iVar13, iVar12 = iVar16, (local_80 & uVar6) != 0)) {
                  uVar6 = uVar6 | local_80;
                  iVar23 = iVar10;
                  if ((-1 < iVar13) && (iVar23 = iVar13, iVar13 != iVar10)) {
                    FUN_00195330(iVar13,iVar10,iVar18);
                  }
                  iVar12 = iVar11;
                  if (iVar16 != 0) {
                    *(undefined4 *)(iVar11 + 0xc) = 0;
                    *(int *)(iVar11 + 0x9c) = DAT_001b0014;
                    iVar12 = iVar16;
                  }
                }
                iVar11 = *(int *)(iVar11 + 300);
                iVar13 = iVar23;
                iVar16 = iVar12;
              } while (iVar11 != 0);
            }
            uVar22 = local_b0;
            if (*(uint *)(iVar12 + 0xc) != uVar6) {
              if (local_b0 < local_b4) {
                iVar11 = local_b0 * 4;
                _memset((void *)(iVar11 + local_ac),0,4);
                local_b0 = uVar22 + 1;
                piVar15 = (int *)(iVar11 + local_ac);
              }
              else {
                piVar15 = (int *)FUN_0019423c(&local_b4,local_b0);
              }
              *piVar15 = iVar12;
              *(uint *)(iVar12 + 0xc) = uVar6;
              FUN_000f31f8(&local_7c,DAT_001b0008,uVar6);
              *(undefined4 *)(iVar12 + 0x9c) = local_7c;
            }
            local_a4 = 0;
          }
          else {
            iVar11 = FUN_001054ec(piVar20,0);
            FUN_000f3908(&local_78,*(undefined4 *)(iVar11 + 0x10));
            uVar6 = local_78;
            if (((bVar1) || (iVar11 = iVar23, (local_78 & local_a4) != 0)) &&
               (iVar11 = FUN_001952d8(piVar20[0x53],iVar18), -1 < iVar23)) {
              FUN_00195330(iVar23,iVar11,iVar18);
              iVar11 = iVar23;
            }
            uVar22 = local_b0;
            uVar5 = piVar20[3];
            if (bVar1) {
              piVar20[3] = uVar6;
            }
            else {
              piVar20[3] = uVar6 & local_a4 | uVar5;
            }
            if (uVar5 != piVar20[3]) {
              if (local_b0 < local_b4) {
                iVar23 = local_b0 * 4;
                _memset((void *)(iVar23 + local_ac),0,4);
                local_b0 = uVar22 + 1;
                puVar9 = (undefined4 *)(iVar23 + local_ac);
              }
              else {
                puVar9 = (undefined4 *)FUN_0019423c(&local_b4,local_b0);
              }
              *puVar9 = piVar20;
            }
            if (bVar1) break;
            iVar23 = FUN_001055cc(piVar20);
            if (iVar23 == 0) {
              local_c4 = uVar6 & local_a4;
              uVar6 = (local_a4 << 0x18 | (local_a4 >> 8 & 0xff) << 0x10 |
                       (local_a4 >> 0x10 & 0xff) << 8 | local_a4 >> 0x18) -
                      (local_c4 << 0x18 | (local_c4 >> 8 & 0xff) << 0x10 |
                       (local_c4 >> 0x10 & 0xff) << 8 | local_c4 >> 0x18);
              local_a4 = uVar6 * 0x1000000 | (uVar6 & 0xff00) << 8 | uVar6 >> 8 & 0xff00 |
                         uVar6 >> 0x18;
            }
            iVar23 = iVar11;
            if (local_a4 != 0) {
              piVar20 = (int *)FUN_00105594(piVar20,piVar20[0x21]);
            }
          }
        }
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 <= iVar14);
  } while( true );
}

/* FUN_0013f3d4 @ 0x13f3d4 (2148 bytes) */
int FUN_0013f3d4(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  char cVar12;
  int iVar13;
  undefined4 uVar14;
  uint uVar15;
  bool bVar16;
  code *pcVar17;
  uint uVar18;
  uint *puVar19;
  int iVar20;
  int local_48;
  undefined4 local_44;
  int local_40 [2];
  int local_38 [2];
  
  uVar3 = param_1[5];
  if ((uVar3 & 0x200) == 0) {
    if ((uVar3 & 0x400000) == 0) {
      return true;
    }
    piVar4 = (int *)param_1[4];
    if (piVar4[1] != 1) {
      return false;
    }
    if (*piVar4 == 0) {
      puVar5 = (undefined4 *)FUN_0019423c(piVar4,0);
    }
    else {
      puVar5 = (undefined4 *)piVar4[2];
    }
    piVar4 = (int *)*puVar5;
    uVar3 = piVar4[5];
    if ((uVar3 & 0x200) != 0) {
      FUN_00105594(piVar4,piVar4[0x21]);
      uVar3 = piVar4[5];
    }
    bVar16 = (uVar3 & 0x400000) == 0;
  }
  else {
    if ((uVar3 & 0x400000) != 0) {
      return false;
    }
    bVar16 = true;
    piVar4 = (int *)FUN_00105594(param_1,param_1[0x21]);
  }
  iVar6 = (**(code **)(*piVar4 + 100))(piVar4);
  if (iVar6 != 0) {
    iVar6 = FUN_00105594(param_1,1);
    iVar7 = FUN_00105594(param_1,2);
    iVar8 = FUN_00105594(piVar4,1);
    if (iVar6 == iVar8) {
      uVar14 = 2;
      iVar8 = 1;
      iVar6 = iVar7;
    }
    else {
      if (iVar7 != iVar8) {
        return false;
      }
      uVar14 = 1;
      iVar8 = 2;
    }
    if ((param_1[0x48] == piVar4[0x48]) && (param_1[0x49] == piVar4[0x49])) {
      if ((((uint)param_1[iVar8 * 6 + 0x28] >> 1 & 1) == ((uint)piVar4[0x2e] >> 1 & 1)) &&
         ((param_1[iVar8 * 6 + 0x28] & 1U) == (piVar4[0x2e] & 1U))) {
        iVar7 = FUN_001054ec(param_1,0);
        local_48 = *(int *)(iVar7 + 0x10);
        iVar7 = FUN_001054ec(piVar4,0);
        iVar13 = 0;
        local_44 = *(undefined4 *)(iVar7 + 0x10);
        iVar20 = 4;
        do {
          if ((*(char *)((int)&local_48 + iVar13) != '\x01') &&
             (*(char *)((int)local_40 + iVar13 + -4) != '\x01')) {
            return false;
          }
          iVar13 = iVar13 + 1;
          iVar20 = iVar20 + -1;
        } while (iVar20 != 0);
        iVar13 = 0;
        FUN_000f2f84(local_38,local_48,*(undefined4 *)(iVar7 + 0x10));
        param_1[0x27] = local_38[0];
        local_48 = local_38[0];
        piVar9 = (int *)((int (*)())FUN_0010bed0)((double)FLOAT_001aa0d4,2,local_38[0],iVar6,param_2,
                                     *(undefined4 *)(param_2 + 8));
        do {
          if (*(char *)((int)&local_48 + iVar13) == '\0') {
            iVar6 = FUN_001054ec(piVar4,1);
            cVar12 = *(char *)(iVar13 + iVar6 + 0x10);
            if (cVar12 == '\x04') {
              pcVar17 = *(code **)(*piVar9 + 0x88);
              iVar6 = FUN_001054ec(param_1,uVar14);
              (*pcVar17)(piVar9,1,iVar13,*(undefined1 *)(iVar13 + iVar6 + 0x10));
            }
            else {
              (**(code **)(*piVar9 + 0x88))(piVar9,2,iVar13,iVar13);
            }
            iVar6 = FUN_001054ec(param_1,iVar8);
            cVar2 = *(char *)(iVar13 + iVar6 + 0x10);
            if (cVar2 == '\x04') {
              iVar6 = *param_1;
            }
            else {
              iVar6 = *param_1;
              cVar12 = cVar2;
            }
            (**(code **)(iVar6 + 0x88))(param_1,iVar8,iVar13,cVar12);
            (**(code **)(*param_1 + 0x88))(param_1,uVar14,iVar13,iVar13);
          }
          bVar1 = iVar13 != 3;
          iVar13 = iVar13 + 1;
        } while (bVar1);
        FUN_00106004(param_1,uVar14,piVar9,1,*(undefined4 *)(param_2 + 8));
        FUN_000e7700(param_1[0x56],param_1,piVar9);
        if (((param_1[5] & 0x200U) == 0) || ((piVar4[5] & 0x200U) != 0)) {
          if (((param_1[5] & 0x200U) == 0) || ((piVar4[5] & 0x200U) == 0)) {
            puVar19 = (uint *)piVar4[4];
            uVar3 = puVar19[1];
            uVar18 = uVar3 - 1;
            if (-1 < (int)uVar18) {
              iVar6 = uVar18 * 4;
              uVar15 = 0;
              do {
                if (uVar18 < *puVar19) {
                  uVar10 = puVar19[1];
                  if (uVar10 <= uVar18) {
                    _memset((void *)(uVar10 * 4 + puVar19[2]),0,(uVar18 - uVar10) * 4 + 4);
                    puVar19[1] = uVar18 + 1;
                  }
                  puVar5 = (undefined4 *)(iVar6 + puVar19[2]);
                }
                else {
                  puVar5 = (undefined4 *)FUN_0019423c(puVar19,uVar18);
                }
                piVar9 = (int *)*puVar5;
                for (iVar7 = 1; iVar8 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar7 <= iVar8;
                    iVar7 = iVar7 + 1) {
                  piVar11 = (int *)FUN_00105594(piVar9,iVar7);
                  if (piVar4 == piVar11) {
                    FUN_00106004(piVar9,iVar7,param_1,1,*(undefined4 *)(param_2 + 8));
                    goto LAB_0013fad0;
                  }
                }
                if (((piVar9[5] & 0x200U) != 0) &&
                   (piVar11 = (int *)FUN_00105594(piVar9,piVar9[0x21]), piVar4 == piVar11)) {
                  FUN_00106804(piVar9,param_1,1,*(undefined4 *)(param_2 + 8));
                }
LAB_0013fad0:
                uVar15 = uVar15 + 1;
                uVar18 = uVar18 - 1;
                iVar6 = iVar6 + -4;
                if (uVar15 == uVar3) break;
                puVar19 = (uint *)piVar4[4];
              } while( true );
            }
            uVar14 = *(undefined4 *)(param_2 + 8);
            iVar6 = FUN_00105594(piVar4,piVar4[0x21]);
            puVar19 = *(uint **)(iVar6 + 0x10);
            uVar3 = puVar19[1];
            if (0 < (int)uVar3) {
              uVar18 = 0;
              do {
                if (uVar18 < *puVar19) {
                  if (uVar3 <= uVar18) {
                    _memset((void *)(uVar3 * 4 + puVar19[2]),0,(uVar18 - uVar3) * 4 + 4);
                    puVar19[1] = uVar18 + 1;
                  }
                  piVar9 = (int *)(uVar18 * 4 + puVar19[2]);
                }
                else {
                  piVar9 = (int *)FUN_0019423c(puVar19,uVar18);
                }
                if (piVar4 == (int *)*piVar9) {
                  FUN_00194208(puVar19,uVar18);
                  iVar6 = FUN_00105594(piVar4,piVar4[0x21]);
                  *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + -1;
                  break;
                }
                uVar3 = puVar19[1];
                uVar18 = uVar18 + 1;
              } while ((int)uVar18 < (int)uVar3);
            }
            FUN_00106004(piVar4,piVar4[0x21],0,1,uVar14);
            piVar4[0x21] = piVar4[0x21] + -1;
            piVar4[5] = piVar4[5] & 0xfffffdff;
          }
          else {
            iVar7 = 0;
            iVar6 = FUN_001054ec(param_1,param_1[0x21]);
            local_40[0] = *(int *)(iVar6 + 0x10);
            do {
              iVar6 = FUN_001054ec(param_1,0);
              if (*(char *)(iVar7 + iVar6 + 0x10) != '\x01') {
                *(undefined1 *)((int)local_40 + iVar7) = 4;
              }
              bVar1 = iVar7 != 3;
              iVar7 = iVar7 + 1;
            } while (bVar1);
            uVar14 = *(undefined4 *)(param_2 + 8);
            iVar6 = FUN_00105594(param_1,param_1[0x21]);
            puVar19 = *(uint **)(iVar6 + 0x10);
            uVar3 = puVar19[1];
            if (0 < (int)uVar3) {
              uVar18 = 0;
              do {
                if (uVar18 < *puVar19) {
                  if (uVar3 <= uVar18) {
                    _memset((void *)(uVar3 * 4 + puVar19[2]),0,(uVar18 - uVar3) * 4 + 4);
                    puVar19[1] = uVar18 + 1;
                  }
                  piVar9 = (int *)(uVar18 * 4 + puVar19[2]);
                }
                else {
                  piVar9 = (int *)FUN_0019423c(puVar19,uVar18);
                }
                if (param_1 == (int *)*piVar9) {
                  FUN_00194208(puVar19,uVar18);
                  iVar6 = FUN_00105594(param_1,param_1[0x21]);
                  *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + -1;
                  break;
                }
                uVar3 = puVar19[1];
                uVar18 = uVar18 + 1;
              } while ((int)uVar18 < (int)uVar3);
            }
            FUN_00106004(param_1,param_1[0x21],0,1,uVar14);
            bVar1 = local_40[0] != DAT_001b0000;
            param_1[0x21] = param_1[0x21] + -1;
            param_1[5] = param_1[5] & 0xfffffdff;
            if (bVar1) {
              uVar14 = FUN_00105594(piVar4,piVar4[0x21]);
              FUN_00106804(param_1,uVar14,1,*(undefined4 *)(param_2 + 8));
              iVar6 = local_40[0];
              if (param_1[0x21] == 0) {
                param_1[0x27] = local_40[0];
              }
              else {
                iVar7 = FUN_001054ec(param_1);
                *(int *)(iVar7 + 0x10) = iVar6;
              }
            }
          }
        }
        else {
          uVar14 = *(undefined4 *)(param_2 + 8);
          iVar6 = FUN_00105594(param_1,param_1[0x21]);
          puVar19 = *(uint **)(iVar6 + 0x10);
          uVar3 = puVar19[1];
          if (0 < (int)uVar3) {
            uVar18 = 0;
            do {
              if (uVar18 < *puVar19) {
                if (uVar3 <= uVar18) {
                  _memset((void *)(uVar3 * 4 + puVar19[2]),0,(uVar18 - uVar3) * 4 + 4);
                  puVar19[1] = uVar18 + 1;
                }
                piVar9 = (int *)(uVar18 * 4 + puVar19[2]);
              }
              else {
                piVar9 = (int *)FUN_0019423c(puVar19,uVar18);
              }
              if (param_1 == (int *)*piVar9) {
                FUN_00194208(puVar19,uVar18);
                iVar6 = FUN_00105594(param_1,param_1[0x21]);
                *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + -1;
                break;
              }
              uVar3 = puVar19[1];
              uVar18 = uVar18 + 1;
            } while ((int)uVar18 < (int)uVar3);
          }
          FUN_00106004(param_1,param_1[0x21],0,1,uVar14);
          param_1[0x21] = param_1[0x21] + -1;
          param_1[5] = param_1[5] & 0xfffffdff;
        }
        if (*(int *)(piVar4[4] + 4) == 0) {
          (**(code **)(*piVar4 + 0xc))(piVar4,1,*(undefined4 *)(param_2 + 8));
        }
        if (bVar16 == false) {
          param_1[5] = param_1[5] | 0x400000;
          return false;
        }
        return bVar16;
      }
    }
  }
  return false;
}

/* FUN_0013fc38 @ 0x13fc38 (4516 bytes) */
int FUN_0013fc38(param_1)
  int param_1;
{
  char cVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  uint *puVar10;
  int *piVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  int *piVar16;
  int *piVar17;
  uint uVar18;
  bool bVar19;
  int iVar20;
  bool bVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  uint uVar26;
  uint *puVar27;
  uint uVar28;
  int *piVar29;
  uint uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  uint uVar33;
  uint local_88;
  uint local_84;
  undefined4 local_80;
  undefined4 local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54 [3];
  
  iVar6 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x30);
  uVar32 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar7 = (undefined4 *)FUN_00193e18(uVar32,0x14);
  puVar27 = puVar7 + 1;
  *puVar7 = uVar32;
  puVar7[1] = 2;
  puVar7[4] = uVar32;
  puVar7[2] = 0;
  uVar32 = FUN_00193e18(uVar32,8);
  puVar7[3] = uVar32;
  uVar32 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar8 = (undefined4 *)FUN_00193e18(uVar32,0x14);
  *puVar8 = uVar32;
  puVar8[1] = 2;
  puVar8[4] = uVar32;
  puVar8[2] = 0;
  uVar32 = FUN_00193e18(uVar32,8);
  puVar8[3] = uVar32;
  local_6c = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_74 = 0;
  local_78 = 2;
  local_70 = FUN_00193e18(local_6c,8);
  local_5c = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_64 = 0;
  local_68 = 2;
  local_60 = FUN_00193e18(local_5c,8);
  iVar24 = *(int *)(param_1 + 900);
  iVar4 = *(int *)(iVar24 + 8);
  do {
    if (iVar4 == 0) {
      FUN_00193cc0(local_5c,local_60);
      FUN_00193cc0(local_6c,local_70);
      return;
    }
    puVar7[2] = 0;
    puVar8[2] = 0;
    local_64 = 0;
    local_74 = 0;
    piVar11 = *(int **)(iVar24 + 0x98);
    for (piVar5 = (int *)(*(int **)(iVar24 + 0x98))[2]; piVar5 != (int *)0x0;
        piVar5 = (int *)piVar5[2]) {
      if ((piVar11[5] & 1U) != 0) {
        iVar4 = FUN_001054ec(piVar11,0);
        iVar4 = *(int *)(iVar4 + 0x10);
        if (((((*(int *)(piVar11[0x22] + 8) == 0x12) &&
              (iVar9 = ((int (*)())FUN_0013f3d4)(piVar11,param_1), iVar9 != 0)) && (iVar4 != DAT_001b0014)) &&
            ((iVar9 = DAT_001b0008, iVar6 == 0 || (iVar9 = DAT_001b000c, iVar4 != DAT_001b0010))))
           && (iVar4 != iVar9)) {
          uVar30 = puVar7[2];
          uVar25 = 0;
          if (uVar30 != 0) {
            do {
              if (uVar25 < *puVar27) {
                if (uVar30 <= uVar25) {
                  _memset((void *)(uVar30 * 4 + puVar7[3]),0,(uVar25 - uVar30) * 4 + 4);
                  puVar7[2] = uVar25 + 1;
                }
                piVar5 = (int *)(uVar25 * 4 + puVar7[3]);
              }
              else {
                piVar5 = (int *)FUN_0019423c(puVar27,uVar25);
              }
              iVar4 = *piVar5;
              for (iVar9 = 1; iVar13 = (**(code **)(*piVar11 + 0x14))(piVar11), iVar9 <= iVar13;
                  iVar9 = iVar9 + 1) {
                iVar13 = FUN_00105594(piVar11,iVar9);
                if (iVar4 == iVar13) {
                  uVar30 = puVar7[2];
                  if (uVar30 < *puVar27) {
                    _memset((void *)(uVar30 * 4 + puVar7[3]),0,4);
                    puVar7[2] = uVar30 + 1;
                    puVar12 = (undefined4 *)(uVar30 * 4 + puVar7[3]);
                  }
                  else {
                    puVar12 = (undefined4 *)FUN_0019423c(puVar27,uVar30);
                  }
                  *puVar12 = 0;
                  if (local_74 < local_78) {
                    iVar4 = local_74 * 4;
                    *(undefined4 *)(iVar4 + local_70) = 0;
                    local_74 = local_74 + 1;
                    puVar12 = (undefined4 *)(iVar4 + local_70);
                  }
                  else {
                    puVar12 = (undefined4 *)FUN_0019423c(&local_78);
                  }
                  *puVar12 = 0;
                  goto LAB_0013ff84;
                }
              }
              uVar30 = puVar7[2];
              uVar25 = uVar25 + 1;
            } while (uVar25 < uVar30);
          }
LAB_0013ff84:
          uVar32 = FUN_0013a644(piVar11);
          uVar30 = puVar7[2];
          if (uVar30 < *puVar27) {
            _memset((void *)(uVar30 * 4 + puVar7[3]),0,4);
            puVar7[2] = uVar30 + 1;
            piVar5 = (int *)(uVar30 * 4 + puVar7[3]);
          }
          else {
            piVar5 = (int *)FUN_0019423c(puVar27,uVar30);
          }
          *piVar5 = (int)piVar11;
          if (local_74 < local_78) {
            iVar4 = local_74 * 4;
            local_74 = local_74 + 1;
            *(undefined4 *)(iVar4 + local_70) = 0;
            puVar12 = (undefined4 *)(iVar4 + local_70);
          }
          else {
            puVar12 = (undefined4 *)FUN_0019423c(&local_78);
          }
          *puVar12 = uVar32;
          piVar5 = (int *)piVar11[2];
        }
        else {
          piVar5 = (int *)piVar11[2];
        }
      }
      piVar11 = piVar5;
    }
    if (puVar7[2] != 0) {
      uVar30 = 0;
      do {
        if (uVar30 < local_78) {
          if (local_74 <= uVar30) {
            _memset((void *)(local_74 * 4 + local_70),0,(uVar30 - local_74) * 4 + 4);
            local_74 = uVar30 + 1;
          }
          puVar10 = (uint *)(uVar30 * 4 + local_70);
        }
        else {
          puVar10 = (uint *)FUN_0019423c(&local_78,uVar30);
        }
        uVar25 = *puVar10;
        if (uVar30 < *puVar27) {
          uVar28 = puVar7[2];
          if (uVar28 <= uVar30) {
            _memset((void *)(uVar28 * 4 + puVar7[3]),0,(uVar30 - uVar28) * 4 + 4);
            puVar7[2] = uVar30 + 1;
            uVar28 = uVar30 + 1;
          }
          piVar11 = (int *)(uVar30 * 4 + puVar7[3]);
        }
        else {
          piVar11 = (int *)FUN_0019423c(puVar27,uVar30);
          uVar28 = puVar7[2];
        }
        uVar26 = uVar30 + 1;
        iVar4 = *piVar11;
        if ((iVar4 != 0) && (uVar26 < uVar28)) {
          iVar9 = uVar26 * 4;
          uVar30 = uVar30 + 2;
LAB_00140128:
          uVar33 = uVar30 - 1;
          if (uVar33 < *puVar27) {
            if (uVar28 <= uVar33) {
              _memset((void *)(uVar28 * 4 + puVar7[3]),0,(uVar33 - uVar28) * 4 + 4);
              puVar7[2] = uVar30;
            }
            puVar12 = (undefined4 *)(iVar9 + puVar7[3]);
          }
          else {
            puVar12 = (undefined4 *)FUN_0019423c(puVar27,uVar33);
          }
          piVar11 = (int *)*puVar12;
          if (piVar11 == (int *)0x0) goto LAB_00140d38;
          if (uVar33 < local_78) {
            if (local_74 <= uVar33) {
              _memset((void *)(local_74 * 4 + local_70),0,(uVar33 - local_74) * 4 + 4);
              local_74 = uVar30;
            }
            puVar10 = (uint *)(iVar9 + local_70);
          }
          else {
            puVar10 = (uint *)FUN_0019423c(&local_78,uVar33);
          }
          uVar28 = *puVar10;
          iVar13 = FUN_00139008(uVar25);
          iVar14 = FUN_00139008(uVar28);
          if (4 < iVar13 + iVar14) goto LAB_00140dc4;
          piVar15 = (int *)FUN_00105594(iVar4,1);
          piVar5 = (int *)FUN_00105594(iVar4,2);
          piVar16 = (int *)FUN_00105594(piVar11,1);
          piVar17 = (int *)FUN_00105594(piVar11,2);
          iVar13 = (*(uint *)(iVar4 + 0xb8) >> 1 & 1) + (*(uint *)(iVar4 + 0xb8) & 1) * 2;
          iVar20 = ((uint)piVar11[0x2e] >> 1 & 1) + (piVar11[0x2e] & 1U) * 2;
          iVar22 = (*(uint *)(iVar4 + 0xd0) >> 1 & 1) + (*(uint *)(iVar4 + 0xd0) & 1) * 2;
          iVar14 = ((uint)piVar11[0x34] >> 1 & 1) + (piVar11[0x34] & 1U) * 2;
          if ((piVar15 != piVar16) || (bVar19 = true, iVar13 != iVar20)) {
            bVar19 = false;
          }
          if ((piVar15 != piVar17) || (bVar2 = true, iVar13 != iVar14)) {
            bVar2 = false;
          }
          if ((piVar5 != piVar16) || (bVar21 = true, iVar22 != iVar20)) {
            bVar21 = false;
          }
          if ((piVar5 != piVar17) || (bVar3 = true, iVar22 != iVar14)) {
            bVar3 = false;
          }
          piVar29 = piVar17;
          if ((((!bVar19) && (piVar29 = piVar16, !bVar2)) &&
              (piVar5 = piVar15, piVar29 = piVar17, !bVar21)) && (piVar29 = piVar16, !bVar3))
          goto LAB_00140dc4;
          iVar9 = (**(code **)(*piVar5 + 0x60))(piVar5);
          if (iVar9 != 0) {
            piVar5 = (int *)FUN_00105594(piVar5,1);
          }
          iVar9 = (**(code **)(*piVar29 + 0x60))(piVar29);
          if (iVar9 == 0) {
            piVar15 = piVar29;
            piVar29 = (int *)0x0;
          }
          else {
            piVar15 = (int *)FUN_00105594(piVar29,1);
          }
          iVar9 = (**(code **)(*piVar5 + 0x48))(piVar5);
          if ((((iVar9 == 0) && (iVar9 = (**(code **)(*piVar15 + 0x48))(piVar15), iVar9 == 0)) &&
              ((iVar9 = (**(code **)(*piVar5 + 0x80))(piVar5), iVar9 == 0 &&
               (iVar9 = (**(code **)(*piVar15 + 0x80))(piVar15), iVar9 == 0)))) ||
             (iVar9 = FUN_0013905c(iVar4,piVar11), iVar9 == 0)) goto LAB_00140d38;
          if (uVar33 < *puVar27) {
            uVar18 = puVar7[2];
            if (uVar18 <= uVar33) {
              _memset((void *)(uVar18 * 4 + puVar7[3]),0,(uVar33 - uVar18) * 4 + 4);
              puVar7[2] = uVar30;
            }
            puVar12 = (undefined4 *)(uVar33 * 4 + puVar7[3]);
          }
          else {
            puVar12 = (undefined4 *)FUN_0019423c(puVar27,uVar33);
          }
          *puVar12 = 0;
          FUN_00106804(piVar11,iVar4,1,*(undefined4 *)(param_1 + 8));
          FUN_0019401c(piVar11);
          FUN_000e7738(*(undefined4 *)(iVar4 + 0x158),iVar4,piVar11);
          if (piVar29 != (int *)0x0) {
            FUN_0019401c(piVar29);
            FUN_000e7738(*(undefined4 *)(iVar4 + 0x158),iVar4,piVar29);
          }
          uVar30 = ~(uVar25 | uVar28) & 0xf;
          local_84 = DAT_001b0004;
          local_88 = DAT_001b0004;
          iVar9 = FUN_001054ec(piVar11,0);
          local_80 = *(int *)(iVar9 + 0x10);
          cVar1 = (char)local_80;
          if ((uVar25 & uVar28) == 0) {
            *(int *)(param_1 + 0x278) = *(int *)(param_1 + 0x278) + 1;
            FUN_00106804(piVar11,iVar4,1,*(undefined4 *)(param_1 + 8));
            uVar32 = DAT_001b0000;
            iVar4 = FUN_001054ec(piVar11,piVar11[0x21]);
            *(undefined4 *)(iVar4 + 0x10) = uVar32;
            uVar30 = 0;
            do {
              if (((int)uVar25 >> (uVar30 & 0x3f) & 1U) != 0) {
                (**(code **)(*piVar11 + 0x88))(piVar11,piVar11[0x21],uVar30,uVar30);
              }
              bVar19 = uVar30 != 3;
              uVar30 = uVar30 + 1;
            } while (bVar19);
          }
          else {
            uVar18 = 0;
            uVar33 = 0;
            *(int *)(param_1 + 0x278) = *(int *)(param_1 + 0x278) + 1;
            uVar32 = DAT_001b0000;
            do {
              if ((((int)(uVar25 & uVar28) >> (uVar33 & 0x3f) & 1U) != 0) && ((int)uVar18 < 4)) {
                uVar23 = uVar18;
                if (((int)uVar30 >> (uVar18 & 0x3f) & 1U) == 0) {
                  iVar9 = 4 - uVar18;
                  do {
                    uVar18 = uVar18 + 1;
                    iVar9 = iVar9 + -1;
                    if (iVar9 == 0) goto LAB_001405bc;
                    uVar23 = uVar18;
                  } while (((int)uVar30 >> (uVar18 & 0x3f) & 1U) == 0);
                }
                *(char *)((int)&local_88 + uVar33) = (char)uVar23;
                uVar18 = uVar23 + 1;
                *(undefined1 *)((int)&local_80 + uVar33) = 1;
                *(char *)((int)&local_84 + uVar23) = (char)uVar33;
                *(undefined1 *)((int)&local_80 + uVar23) = 0;
              }
LAB_001405bc:
              bVar19 = uVar33 != 3;
              uVar33 = uVar33 + 1;
            } while (bVar19);
            piVar11[0x27] = local_80;
            iVar9 = FUN_001054ec(piVar11,piVar11[0x21]);
            *(undefined4 *)(iVar9 + 0x10) = uVar32;
            uVar30 = 0;
            do {
              if (((int)uVar25 >> (uVar30 & 0x3f) & 1U) != 0) {
                (**(code **)(*piVar11 + 0x88))
                          (piVar11,piVar11[0x21],*(undefined1 *)((int)&local_88 + uVar30),
                           *(undefined1 *)((int)&local_88 + uVar30));
              }
              bVar19 = uVar30 != 3;
              uVar30 = uVar30 + 1;
            } while (bVar19);
            if ((cVar1 == '\0') || ((char)local_80 != '\0')) {
              piVar5 = (int *)0x0;
            }
            else {
              uVar32 = *(undefined4 *)(param_1 + 8);
              iVar9 = FUN_00105594(piVar11,piVar11[0x21]);
              puVar10 = *(uint **)(iVar9 + 0x10);
              uVar30 = puVar10[1];
              if (0 < (int)uVar30) {
                uVar33 = 0;
                do {
                  if (uVar33 < *puVar10) {
                    if (uVar30 <= uVar33) {
                      _memset((void *)(uVar30 * 4 + puVar10[2]),0,(uVar33 - uVar30) * 4 + 4);
                      puVar10[1] = uVar33 + 1;
                    }
                    piVar5 = (int *)(uVar33 * 4 + puVar10[2]);
                  }
                  else {
                    piVar5 = (int *)FUN_0019423c(puVar10,uVar33);
                  }
                  if ((int *)*piVar5 == piVar11) {
                    FUN_00194208(puVar10,uVar33);
                    iVar9 = FUN_00105594(piVar11,piVar11[0x21]);
                    *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + -1;
                    break;
                  }
                  uVar30 = puVar10[1];
                  uVar33 = uVar33 + 1;
                } while ((int)uVar33 < (int)uVar30);
              }
              FUN_00106004(piVar11,piVar11[0x21],0,1,uVar32);
              piVar11[0x21] = piVar11[0x21] + -1;
              piVar11[5] = piVar11[5] & 0xfffffdff;
              iVar9 = FUN_001054ec(piVar11);
              uVar31 = *(undefined4 *)(iVar9 + 0x10);
              piVar5 = (int *)FUN_0010445c(piVar11,*(undefined4 *)(param_1 + 8),0);
              uVar32 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
              puVar12 = (undefined4 *)FUN_00193e18(uVar32,0x14);
              puVar12[1] = 2;
              *puVar12 = uVar32;
              puVar12[2] = 0;
              puVar12[4] = uVar32;
              uVar32 = FUN_00193e18(uVar32,8);
              puVar12[3] = uVar32;
              piVar5[4] = (int)(puVar12 + 1);
              piVar5[0x58] = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x6c4) + 0x478);
              FUN_00106804(piVar11,iVar4,1,*(undefined4 *)(param_1 + 8));
              iVar13 = FUN_001054ec(piVar11,piVar11[0x21]);
              iVar9 = DAT_001b0010;
              *(undefined4 *)(iVar13 + 0x10) = uVar31;
              *(undefined1 *)((int)piVar11 + 0x9f) = 1;
              piVar5[0x27] = iVar9;
              FUN_000e7738(piVar11[0x56],piVar11,piVar5);
              FUN_00106804(piVar5,piVar11,1,*(undefined4 *)(param_1 + 8));
              uVar32 = DAT_001b0000;
              iVar9 = FUN_001054ec(piVar5,piVar5[0x21]);
              *(undefined4 *)(iVar9 + 0x10) = uVar32;
              uVar30 = 0;
              do {
                if ((((int)uVar28 >> (uVar30 & 0x3f) & 1U) != 0) && (uVar30 != 3)) {
                  (**(code **)(*piVar5 + 0x88))(piVar5,piVar5[0x21],uVar30,uVar30);
                }
                if ((((int)uVar25 >> (uVar30 & 0x3f) & 1U) != 0) &&
                   (cVar1 = *(char *)((int)&local_88 + uVar30), cVar1 != '\x03')) {
                  (**(code **)(*piVar5 + 0x88))(piVar5,piVar5[0x21],cVar1,cVar1);
                }
                bVar19 = uVar30 != 3;
                uVar30 = uVar30 + 1;
              } while (bVar19);
              iVar14 = piVar5[0x53];
              iVar13 = piVar11[0x26];
              iVar9 = FUN_001054ec(piVar5,0);
              *(int *)(iVar9 + 0xc) = iVar13;
              *(int *)(iVar9 + 8) = iVar14;
              for (iVar9 = 1; iVar13 = (**(code **)(*piVar5 + 0x14))(piVar5), iVar9 <= iVar13;
                  iVar9 = iVar9 + 1) {
                iVar13 = FUN_00105594(piVar5,iVar9);
                puVar10 = *(uint **)(iVar13 + 0x10);
                uVar30 = puVar10[1];
                if (uVar30 < *puVar10) {
                  _memset((void *)(uVar30 * 4 + puVar10[2]),0,4);
                  puVar12 = (undefined4 *)(uVar30 * 4 + puVar10[2]);
                  puVar10[1] = uVar30 + 1;
                }
                else {
                  puVar12 = (undefined4 *)FUN_0019423c(puVar10,uVar30);
                }
                *puVar12 = piVar5;
              }
            }
            uVar30 = local_84 & 0xff;
            for (iVar9 = 1; iVar13 = (**(code **)(*piVar11 + 0x14))(piVar11), iVar9 <= iVar13;
                iVar9 = iVar9 + 1) {
              iVar13 = FUN_001054ec(piVar11,iVar9);
              iVar14 = 0;
              iVar20 = 0;
              local_7c = *(undefined4 *)(iVar13 + 0x10);
              do {
                if (*(char *)((int)&local_80 + iVar20) == '\0') {
                  if ((piVar5 == (int *)0x0) || (iVar20 != 3)) {
                    iVar14 = iVar14 + 1;
                    (**(code **)(*piVar11 + 0x88))
                              (piVar11,iVar9,iVar20,
                               *(undefined1 *)
                                ((int)&local_7c + (uint)*(byte *)((int)&local_84 + iVar20)));
                  }
                  else {
                    (**(code **)(*piVar11 + 0x88))(piVar11,iVar9,3,4);
                    (**(code **)(*piVar5 + 0x88))
                              (piVar5,iVar9,3,*(undefined1 *)((int)&local_7c + uVar30));
                  }
                }
                else {
                  (**(code **)(*piVar11 + 0x88))(piVar11,iVar9,iVar20,4);
                  if (piVar5 != (int *)0x0) {
                    (**(code **)(*piVar5 + 0x88))(piVar5,iVar9,iVar20,4);
                  }
                }
                bVar19 = iVar20 != 3;
                iVar20 = iVar20 + 1;
              } while (bVar19);
              if (iVar14 == 1) {
                FUN_0010cfcc(&local_58,piVar11,iVar9,param_1);
                uVar32 = local_58;
                iVar13 = FUN_001054ec(piVar11,iVar9);
                *(undefined4 *)(iVar13 + 0x10) = uVar32;
              }
              if (piVar5 != (int *)0x0) {
                FUN_0010cfcc(local_54,piVar5,iVar9,param_1);
                uVar32 = local_54[0];
                iVar13 = FUN_001054ec(piVar5,iVar9);
                *(undefined4 *)(iVar13 + 0x10) = uVar32;
              }
            }
            puVar10 = (uint *)piVar11[4];
            uVar30 = puVar10[1];
            uVar25 = uVar30 - 1;
            if (-1 < (int)uVar25) {
              iVar9 = uVar25 * 4;
              uVar28 = 0;
              do {
                if (uVar25 < *puVar10) {
                  uVar33 = puVar10[1];
                  if (uVar33 <= uVar25) {
                    _memset((void *)(uVar33 * 4 + puVar10[2]),0,(uVar25 - uVar33) * 4 + 4);
                    puVar10[1] = uVar25 + 1;
                  }
                  puVar12 = (undefined4 *)(iVar9 + puVar10[2]);
                }
                else {
                  puVar12 = (undefined4 *)FUN_0019423c(puVar10,uVar25);
                }
                piVar15 = (int *)*puVar12;
                iVar13 = 1;
LAB_00140c04:
                iVar14 = (**(code **)(*piVar15 + 0x14))(piVar15);
                if (iVar13 <= iVar14) {
                  piVar16 = (int *)FUN_00105594(piVar15,iVar13);
                  if (piVar16 != piVar11) goto LAB_00140c00;
                  if (piVar5 != (int *)0x0) {
                    FUN_00106004(piVar15,iVar13,piVar5,1,*(undefined4 *)(param_1 + 8));
                  }
                  iVar14 = 0;
                  do {
                    iVar20 = FUN_001054ec(piVar15,iVar13);
                    uVar33 = (uint)*(byte *)(iVar14 + iVar20 + 0x10);
                    if (uVar33 != 4) {
                      (**(code **)(*piVar15 + 0x88))
                                (piVar15,iVar13,iVar14,*(undefined1 *)((int)&local_88 + uVar33));
                    }
                    bVar19 = iVar14 != 3;
                    iVar14 = iVar14 + 1;
                  } while (bVar19);
                }
                uVar28 = uVar28 + 1;
                uVar25 = uVar25 - 1;
                iVar9 = iVar9 + -4;
                if (uVar30 == uVar28) break;
                puVar10 = (uint *)piVar11[4];
              } while( true );
            }
            puVar10 = *(uint **)(iVar4 + 0x10);
            uVar30 = puVar10[1];
            uVar25 = uVar30 - 1;
            if (-1 < (int)uVar25) {
              iVar9 = uVar25 * 4;
              uVar28 = 0;
              do {
                if (uVar25 < *puVar10) {
                  uVar33 = puVar10[1];
                  if (uVar33 <= uVar25) {
                    _memset((void *)(uVar33 * 4 + puVar10[2]),0,(uVar25 - uVar33) * 4 + 4);
                    puVar10[1] = uVar25 + 1;
                  }
                  puVar12 = (undefined4 *)(iVar9 + puVar10[2]);
                }
                else {
                  puVar12 = (undefined4 *)FUN_0019423c(puVar10,uVar25);
                }
                piVar11 = (int *)*puVar12;
                for (iVar13 = 1; iVar14 = (**(code **)(*piVar11 + 0x14))(piVar11), iVar13 <= iVar14;
                    iVar13 = iVar13 + 1) {
                  iVar14 = FUN_00105594(piVar11,iVar13);
                  if (iVar4 == iVar14) {
                    if (piVar5 != (int *)0x0) {
                      FUN_00106004(piVar11,iVar13,piVar5,1,*(undefined4 *)(param_1 + 8));
                    }
                    break;
                  }
                }
                uVar28 = uVar28 + 1;
                uVar25 = uVar25 - 1;
                iVar9 = iVar9 + -4;
                if (uVar30 == uVar28) break;
                puVar10 = *(uint **)(iVar4 + 0x10);
              } while( true );
            }
          }
LAB_00140d38:
          uVar28 = puVar7[2];
        }
LAB_00140d3c:
        uVar30 = uVar26;
      } while (uVar26 < uVar28);
    }
    iVar24 = *(int *)(iVar24 + 8);
    iVar4 = *(int *)(iVar24 + 8);
  } while( true );
LAB_00140dc4:
  uVar28 = puVar7[2];
  iVar9 = iVar9 + 4;
  bVar19 = uVar28 <= uVar30;
  uVar30 = uVar30 + 1;
  if (bVar19) goto LAB_00140d3c;
  goto LAB_00140128;
LAB_00140c00:
  iVar13 = iVar13 + 1;
  goto LAB_00140c04;
}

/* FUN_00140e5c @ 0x140e5c (20 bytes) */
int FUN_00140e5c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

/* FUN_00140e70 @ 0x140e70 (12 bytes) */
int FUN_00140e70(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  *param_1 = *(undefined4 *)(param_3 + 0xc);
  return;
}

/* FUN_00140e7c @ 0x140e7c (456 bytes) */
int FUN_00140e7c(param_1, param_2, param_3)
  undefined4 *param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  int iVar2;
  
  if ((((((*(int *)(param_2[0x22] + 8) == *(int *)(param_3[0x22] + 8)) &&
         (iVar1 = FUN_0011379c(*param_1), iVar1 != 0)) &&
        (iVar1 = (**(code **)(*param_2 + 100))(param_2), iVar1 == 0)) &&
       ((param_2[0x20] != 0 && (iVar1 = FUN_00126760(param_2[0x26]), iVar1 != 0)))) &&
      (((param_2[5] & 2U) == 0 &&
       ((iVar1 = (**(code **)(*param_2 + 0x50))(param_2), iVar1 == 0 && (param_3[0x20] != 0)))))) &&
     ((iVar1 = FUN_00126760(param_3[0x26]), iVar1 != 0 &&
      (((((param_3[5] & 2U) == 0 && (iVar1 = (**(code **)(*param_3 + 0x50))(param_3), iVar1 == 0))
        && (param_2[0x48] == param_3[0x48])) && (param_2[0x49] == param_3[0x49])))))) {
    iVar1 = param_2[0x21];
    if ((param_2[5] & 0x200U) != 0) {
      iVar1 = iVar1 + -1;
    }
    if (iVar1 < 1) {
      return 1;
    }
    if (((param_3[0x2e] & 1U) == (param_2[0x2e] & 1U)) &&
       (iVar2 = 1, ((uint)param_2[0x2e] >> 1 & 1) == ((uint)param_3[0x2e] >> 1 & 1))) {
      do {
        iVar2 = iVar2 + 1;
        if (iVar1 < iVar2) {
          return 1;
        }
      } while (((param_3[iVar2 * 6 + 0x28] & 1U) == (param_2[iVar2 * 6 + 0x28] & 1U)) &&
              (((uint)param_3[iVar2 * 6 + 0x28] >> 1 & 1) ==
               ((uint)param_2[iVar2 * 6 + 0x28] >> 1 & 1)));
    }
  }
  return 0;
}

/* FUN_00141044 @ 0x141044 (76 bytes) */
int FUN_00141044(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined4 local_18 [3];
  
  iVar1 = FUN_001054ec(param_3,0);
  FUN_000f3908(local_18,*(undefined4 *)(iVar1 + 0x10));
  *param_1 = local_18[0];
  return param_1;
}

/* FUN_00141090 @ 0x141090 (112 bytes) */
int FUN_00141090(param_1, param_2, param_3)
  uint *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint local_28;
  uint local_24 [4];
  
  ((int (*)())FUN_00140e70)(&local_28);
  ((int (*)())FUN_00141044)(local_24,param_2,param_3);
  local_24[0] = ~local_24[0];
  *param_1 = local_28 &
             (local_24[0] << 0x18 | (local_24[0] & 0xff00) << 8 | local_24[0] >> 8 & 0xff00 |
             local_24[0] >> 0x18);
  return param_1;
}

/* FUN_00141100 @ 0x141100 (220 bytes) */
int FUN_00141100(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_48;
  undefined4 local_44 [8];
  
  ((int (*)())FUN_00140e7c)(param_1,param_2,param_4);
  iVar3 = *(int *)(param_2 + 0x84);
  if ((*(uint *)(param_2 + 0x14) & 0x200) != 0) {
    iVar3 = iVar3 + -1;
  }
  if (0 < iVar3) {
    iVar4 = 1;
    do {
      iVar1 = FUN_00105594(param_2,iVar4);
      iVar2 = FUN_00105594(param_4,iVar4);
      if (iVar1 != iVar2) {
        return 0;
      }
      iVar1 = FUN_001054ec(param_2,iVar4);
      local_48 = *(undefined4 *)(iVar1 + 0x10);
      iVar1 = FUN_001054ec(param_4,iVar4);
      local_44[0] = *(undefined4 *)(iVar1 + 0x10);
      if (*(char *)((int)local_44 + param_3 + -4) != *(char *)((int)local_44 + param_5)) {
        return 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= iVar3);
  }
  return 1;
}

/* FUN_001411dc @ 0x1411dc (636 bytes) */
int FUN_001411dc(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uStack00000024;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44 [7];
  
  bVar1 = param_2 == param_3;
  uStack00000024 = param_4;
  FUN_0011379c(*param_1);
  FUN_0011379c(*param_1,param_3);
  iVar3 = FUN_001054ec(param_2,0);
  local_44[0] = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = FUN_001054ec(param_3,0);
  local_58 = *(undefined4 *)(iVar3 + 0x10);
  if (bVar1) {
    local_44[0] = DAT_001b0044;
  }
  pbVar5 = (byte *)&STACKARG(0x24);
  iVar6 = 4;
  iVar3 = 0;
  pbVar4 = pbVar5;
  do {
    if (*(char *)((int)&local_58 + iVar3) != '\x01') {
      *(char *)((int)local_44 + (uint)*pbVar4) = *(char *)((int)&local_58 + iVar3);
    }
    iVar3 = iVar3 + 1;
    pbVar4 = pbVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *(undefined4 *)(param_2 + 0x9c) = local_44[0];
  iVar6 = *(int *)(param_3 + 0x84);
  iVar3 = iVar6;
  if ((*(uint *)(param_3 + 0x14) & 0x200) != 0) {
    iVar3 = FUN_001054ec(param_2,iVar6);
    local_4c = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = FUN_001054ec(param_3,iVar6);
    local_48 = *(undefined4 *)(iVar3 + 0x10);
    if (bVar1) {
      local_4c = DAT_001b0038;
    }
    iVar3 = 0;
    iVar7 = 4;
    pbVar4 = pbVar5;
    do {
      if (*(char *)((int)local_44 + iVar3 + -4) != '\x04') {
        *(byte *)((int)&local_4c + (uint)*pbVar4) = *pbVar4;
      }
      uVar2 = local_4c;
      iVar3 = iVar3 + 1;
      pbVar4 = pbVar4 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    iVar3 = iVar6 + -1;
    iVar6 = FUN_001054ec(param_2,iVar6);
    *(undefined4 *)(iVar6 + 0x10) = uVar2;
  }
  if (0 < iVar3) {
    iVar6 = 1;
    do {
      iVar7 = FUN_001054ec(param_2,iVar6);
      local_48 = *(undefined4 *)(iVar7 + 0x10);
      iVar7 = FUN_001054ec(param_3,iVar6);
      local_4c = *(undefined4 *)(iVar7 + 0x10);
      if (bVar1) {
        local_48 = DAT_001b0038;
      }
      iVar7 = 0;
      iVar8 = 4;
      pbVar4 = pbVar5;
      do {
        if (*(char *)((int)&local_58 + iVar7) != '\x01') {
          *(undefined1 *)((int)local_44 + (*pbVar4 - 4)) = *(undefined1 *)((int)&local_4c + iVar7);
        }
        uVar2 = local_48;
        iVar7 = iVar7 + 1;
        pbVar4 = pbVar4 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      iVar7 = iVar6 + 1;
      iVar6 = FUN_001054ec(param_2,iVar6);
      *(undefined4 *)(iVar6 + 0x10) = uVar2;
      iVar6 = iVar7;
    } while (iVar7 <= iVar3);
  }
  local_50 = *(undefined4 *)(param_3 + 0xc);
  local_54 = *(undefined4 *)(param_2 + 0xc);
  if (bVar1) {
    local_54 = DAT_001b0040;
  }
  iVar6 = 4;
  iVar3 = 0;
  do {
    if (*(char *)((int)&local_50 + iVar3) != '\0') {
      *(undefined1 *)((int)&local_54 + (uint)*pbVar5) = 1;
    }
    iVar3 = iVar3 + 1;
    pbVar5 = pbVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *(undefined4 *)(param_2 + 0xc) = local_54;
  return;
}

/* FUN_00141458 @ 0x141458 (332 bytes) */
int FUN_00141458(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 local_48;
  undefined4 local_44 [8];
  
  FUN_0011379c(*param_1);
  iVar4 = FUN_001054ec(param_2,0);
  local_48 = *(undefined4 *)(iVar4 + 0x10);
  uVar3 = *(uint *)(param_2 + 0x14);
  uVar1 = *(undefined1 *)((int)local_44 + param_3 + -4);
  *(undefined1 *)((int)local_44 + param_3 + -4) = *(undefined1 *)((int)local_44 + param_4 + -4);
  *(undefined1 *)((int)local_44 + param_4 + -4) = uVar1;
  iVar6 = *(int *)(param_2 + 0x84);
  *(undefined4 *)(param_2 + 0x9c) = local_48;
  iVar4 = iVar6;
  if ((uVar3 & 0x200) != 0) {
    iVar4 = FUN_001054ec(param_2,iVar6);
    local_44[0] = *(undefined4 *)(iVar4 + 0x10);
    uVar1 = *(undefined1 *)((int)local_44 + param_3);
    *(undefined1 *)((int)local_44 + param_3) = *(undefined1 *)((int)local_44 + param_4);
    *(undefined1 *)((int)local_44 + param_4) = uVar1;
    if (*(char *)((int)local_44 + param_3) != '\x04') {
      *(char *)((int)local_44 + param_3) = (char)param_3;
    }
    if (*(char *)((int)local_44 + param_4) != '\x04') {
      *(char *)((int)local_44 + param_4) = (char)param_4;
    }
    uVar2 = local_44[0];
    iVar4 = iVar6 + -1;
    iVar6 = FUN_001054ec(param_2,iVar6);
    *(undefined4 *)(iVar6 + 0x10) = uVar2;
  }
  if (0 < iVar4) {
    iVar6 = 1;
    do {
      iVar5 = FUN_001054ec(param_2,iVar6);
      iVar7 = iVar6 + 1;
      local_44[0] = *(undefined4 *)(iVar5 + 0x10);
      uVar1 = *(undefined1 *)((int)local_44 + param_3);
      *(undefined1 *)((int)local_44 + param_3) = *(undefined1 *)((int)local_44 + param_4);
      *(undefined1 *)((int)local_44 + param_4) = uVar1;
      uVar2 = local_44[0];
      iVar6 = FUN_001054ec(param_2,iVar6);
      *(undefined4 *)(iVar6 + 0x10) = uVar2;
      iVar6 = iVar7;
    } while (iVar7 <= iVar4);
  }
  uVar1 = *(undefined1 *)(param_2 + param_3 + 0xc);
  *(undefined1 *)(param_2 + param_3 + 0xc) = *(undefined1 *)(param_2 + param_4 + 0xc);
  *(undefined1 *)(param_2 + param_4 + 0xc) = uVar1;
  return;
}

/* FUN_001415a4 @ 0x1415a4 (272 bytes) */
int FUN_001415a4(param_1, param_2, param_3)
  undefined4 *param_1;
  int *param_2;
  undefined4 param_3;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  while (piVar1 = (int *)param_2[4], piVar1[1] != 0) {
    if (*piVar1 == 0) {
      piVar1 = (int *)FUN_0019423c(piVar1,0);
    }
    else {
      piVar1 = (int *)piVar1[2];
    }
    iVar2 = *piVar1;
    iVar3 = *(int *)(iVar2 + 0x84);
    iVar4 = iVar3;
    if ((*(uint *)(iVar2 + 0x14) & 0x200) != 0) {
      iVar4 = iVar3 + -1;
      piVar1 = (int *)FUN_00105594(iVar2,iVar3);
      if (param_2 == piVar1) {
        FUN_00106804(iVar2,param_3,1,*param_1);
      }
    }
    if (0 < iVar4) {
      iVar3 = 1;
      do {
        piVar1 = (int *)FUN_00105594(iVar2,iVar3);
        if (param_2 == piVar1) {
          FUN_00106004(iVar2,iVar3,param_3,1,*param_1);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= iVar4);
    }
  }
  *(int *)(param_1[1] + 0x1b4) = *(int *)(param_1[1] + 0x1b4) + 1;
                    
                    
  (**(code **)(*param_2 + 0xc))(param_2,1,*param_1);
  return;
}

/* FUN_001416b4 @ 0x1416b4 (508 bytes) */
int FUN_001416b4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  
  iVar1 = FUN_00104800(param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = FUN_00104800(param_3,param_2);
    if (iVar1 == 0) {
      return 0;
    }
    iVar6 = *(int *)(param_2 + 0x84);
    iVar1 = iVar6;
    if ((*(uint *)(param_2 + 0x14) & 0x200) != 0) {
      iVar1 = iVar6 + -1;
      iVar6 = FUN_00105594(param_2,iVar6);
      if ((param_4 != 0) && (param_3 == iVar6)) {
        return 0;
      }
    }
    if (0 < iVar1) {
      iVar6 = 1;
      do {
        iVar2 = FUN_00105594(param_2,iVar6);
        if (param_3 == iVar2) {
          return 0;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 <= iVar1);
    }
    puVar8 = *(uint **)(param_3 + 0x10);
    uVar4 = puVar8[1];
    if (uVar4 != 0) {
      uVar7 = 0;
      do {
        if (uVar7 < *puVar8) {
          if (uVar4 <= uVar7) {
            _memset((void *)(uVar4 * 4 + puVar8[2]),0,(uVar7 - uVar4) * 4 + 4);
            puVar8[1] = uVar7 + 1;
          }
          piVar5 = (int *)(uVar7 * 4 + puVar8[2]);
        }
        else {
          piVar5 = (int *)FUN_0019423c(puVar8,uVar7);
        }
        if ((*piVar5 != 0) && (iVar1 = FUN_00104800(param_2), iVar1 == 0)) {
          return 0;
        }
        puVar8 = *(uint **)(param_3 + 0x10);
        uVar7 = uVar7 + 1;
        uVar4 = puVar8[1];
      } while (uVar7 < uVar4);
    }
  }
  else {
    iVar6 = *(int *)(param_3 + 0x84);
    iVar1 = iVar6;
    if ((*(uint *)(param_3 + 0x14) & 0x200) != 0) {
      iVar1 = iVar6 + -1;
      iVar6 = FUN_00105594(param_3,iVar6);
      if ((param_4 != 0) && (param_2 == iVar6)) {
        return 0;
      }
    }
    if (0 < iVar1) {
      iVar6 = 1;
      do {
        iVar2 = FUN_00105594(param_3,iVar6);
        if (param_2 == iVar2) {
          return 0;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 <= iVar1);
    }
    if (0 < *(int *)(param_3 + 0x84)) {
      iVar1 = 1;
      do {
        uVar3 = FUN_00105594(param_3,iVar1);
        iVar6 = FUN_00104800(uVar3,param_2);
        if (iVar6 == 0) {
          return 0;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 <= *(int *)(param_3 + 0x84));
    }
  }
  return 1;
}

/* FUN_001418b0 @ 0x1418b0 (128 bytes) */
int FUN_001418b0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((int (*)())FUN_001416b4)();
  if (iVar1 == 0) {
    iVar1 = ((int (*)())FUN_001416b4)(param_1,param_3,param_2,0);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = 1;
      *param_4 = 1;
    }
  }
  else {
    uVar2 = 1;
    *param_4 = 0;
  }
  return uVar2;
}

/* FUN_00141930 @ 0x141930 (3700 bytes) */
int FUN_00141930(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int *param_3;
  int *param_4;
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  void *pvVar9;
  int *piVar10;
  void *pvVar11;
  byte *pbVar12;
  int *piVar13;
  byte *pbVar14;
  int *piVar15;
  byte *pbVar16;
  byte bVar19;
  int iVar17;
  byte *pbVar18;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  undefined4 *puVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  undefined4 local_88;
  int local_84 [4];
  byte local_74 [16];
  byte local_64 [4];
  undefined4 local_60;
  undefined4 local_5c;
  
  ((int (*)())FUN_00140e7c)();
  if (param_4 != (int *)0x0) {
    iVar25 = 5;
    *param_4 = 0;
    piVar4 = param_4;
    do {
      piVar4 = piVar4 + 1;
      *piVar4 = 0;
      iVar25 = iVar25 + -1;
    } while (iVar25 != 0);
  }
  iVar25 = param_2[0x21];
  if ((param_2[5] & 0x200U) == 0) goto LAB_001420b4;
  if ((param_3[5] & 0x200U) != 0) {
    piVar4 = (int *)FUN_00105594(param_2,iVar25);
    piVar5 = (int *)FUN_00105594(param_3,param_3[0x21]);
    if (((piVar4 != piVar5) && (param_3 != piVar4)) && (param_2 != piVar5)) {
      iVar6 = (**(code **)(*piVar4 + 0x60))(piVar4);
      if ((iVar6 != 0) || (iVar6 = (**(code **)(*piVar5 + 0x60))(piVar5), iVar6 != 0)) {
        return 0;
      }
      iVar6 = 4;
      bVar19 = 0;
      pbVar12 = local_64;
      piVar10 = local_84;
      do {
        *pbVar12 = bVar19;
        pbVar12 = pbVar12 + 1;
        *piVar10 = 0;
        bVar19 = bVar19 + 1;
        piVar10[4] = 0;
        piVar10 = piVar10 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      iVar6 = FUN_001054ec(param_2,iVar25);
      uVar7 = 0;
      local_88 = *(undefined4 *)(iVar6 + 0x10);
      piVar10 = local_84;
      pbVar12 = local_64;
      do {
        if (*(char *)((int)local_84 + (uVar7 - 4)) != '\x04') {
          piVar15 = (int *)piVar10[4];
          if (piVar4 == piVar15) {
            if (uVar7 == *pbVar12) {
              *piVar10 = 1;
            }
            else {
LAB_00141ae0:
              if (*piVar10 != 0) {
LAB_00141b90:
                bVar1 = false;
                goto LAB_00141b94;
              }
              pbVar16 = local_74;
              piVar10[4] = (int)piVar4;
              uVar21 = (uint)*pbVar12;
              *piVar10 = 1;
              *pbVar12 = (byte)uVar7;
              pbVar18 = pbVar16;
              pbVar14 = local_64;
              do {
                if ((piVar15 == *(int **)pbVar18) && (uVar21 == *pbVar14)) goto LAB_00141a9c;
                pbVar18 = pbVar18 + 4;
                pbVar14 = pbVar14 + 1;
              } while (local_64 != pbVar18);
              iVar6 = 4;
              uVar20 = 0;
              pbVar18 = local_64;
              while( true ) {
                piVar13 = *(int **)pbVar16;
                if (piVar13 == (int *)0x0) break;
                uVar22 = (uint)*pbVar18;
                if ((uVar20 != uVar22) &&
                   ((piVar15[0x53] < piVar13[0x53] ||
                    ((piVar13[0x53] == piVar15[0x53] && (uVar21 < uVar22)))))) {
                  *(int **)pbVar16 = piVar15;
                  *pbVar18 = (byte)uVar21;
                  uVar21 = uVar22;
                  piVar15 = piVar13;
                }
                uVar20 = uVar20 + 1;
                pbVar16 = pbVar16 + 4;
                pbVar18 = pbVar18 + 1;
                iVar6 = iVar6 + -1;
                if (iVar6 == 0) goto LAB_00141b90;
              }
              local_64[uVar20] = (byte)uVar21;
              *(int **)(local_74 + uVar20 * 4) = piVar15;
            }
          }
          else {
            if (piVar15 != (int *)0x0) goto LAB_00141ae0;
            piVar10[4] = (int)piVar4;
            *piVar10 = 1;
            *pbVar12 = (byte)uVar7;
          }
        }
LAB_00141a9c:
        bVar1 = uVar7 != 3;
        piVar10 = piVar10 + 1;
        pbVar12 = pbVar12 + 1;
        uVar7 = uVar7 + 1;
      } while (bVar1);
      bVar1 = true;
LAB_00141b94:
      iVar6 = FUN_001054ec(param_3,iVar25);
      uVar7 = 0;
      local_88 = *(undefined4 *)(iVar6 + 0x10);
      piVar4 = local_84;
      pbVar12 = local_64;
      do {
        if (*(char *)((int)local_84 + (uVar7 - 4)) != '\x04') {
          piVar10 = (int *)piVar4[4];
          if (piVar5 == piVar10) {
            if (*pbVar12 == uVar7) {
              local_84[uVar7] = 1;
            }
            else {
LAB_00141bd8:
              if (*piVar4 != 0) {
LAB_00141d00:
                bVar2 = false;
                goto LAB_00141d04;
              }
              uVar21 = (uint)*pbVar12;
              pbVar16 = local_74;
              *piVar4 = 1;
              piVar4[4] = (int)piVar5;
              *pbVar12 = (byte)uVar7;
              pbVar18 = pbVar16;
              pbVar14 = local_64;
              do {
                if ((piVar10 == *(int **)pbVar18) && (uVar21 == *pbVar14)) goto LAB_00141c78;
                pbVar18 = pbVar18 + 4;
                pbVar14 = pbVar14 + 1;
              } while (local_64 != pbVar18);
              iVar6 = 4;
              uVar20 = 0;
              pbVar18 = local_64;
              while( true ) {
                piVar15 = *(int **)pbVar16;
                if (piVar15 == (int *)0x0) break;
                uVar22 = (uint)*pbVar18;
                if ((uVar20 != uVar22) &&
                   ((piVar10[0x53] < piVar15[0x53] ||
                    ((piVar15[0x53] == piVar10[0x53] && (uVar21 < uVar22)))))) {
                  *(int **)pbVar16 = piVar10;
                  *pbVar18 = (byte)uVar21;
                  uVar21 = uVar22;
                  piVar10 = piVar15;
                }
                uVar20 = uVar20 + 1;
                pbVar16 = pbVar16 + 4;
                pbVar18 = pbVar18 + 1;
                iVar6 = iVar6 + -1;
                if (iVar6 == 0) goto LAB_00141d00;
              }
              local_64[uVar20] = (byte)uVar21;
              *(int **)(local_74 + uVar20 * 4) = piVar10;
            }
          }
          else {
            if (piVar10 != (int *)0x0) goto LAB_00141bd8;
            piVar4[4] = (int)piVar5;
            *piVar4 = 1;
            *pbVar12 = (byte)uVar7;
          }
        }
LAB_00141c78:
        bVar2 = uVar7 != 3;
        piVar4 = piVar4 + 1;
        pbVar12 = pbVar12 + 1;
        uVar7 = uVar7 + 1;
      } while (bVar2);
      bVar2 = true;
LAB_00141d04:
      if (!bVar1) {
        return 0;
      }
      if (!bVar2) {
        return 0;
      }
      puVar24 = (undefined4 *)(param_1 + 0xc);
      uVar7 = *(uint *)(param_1 + 0x10);
      if (uVar7 != 0) {
        iVar6 = *(int *)(param_1 + 0x18);
        uVar20 = 0;
        uVar21 = uVar7;
        do {
          if (uVar21 <= uVar20) {
            uVar21 = uVar20 + 1;
            if (*(uint *)(param_1 + 0x14) < uVar21) {
              uVar22 = (*(uint *)(param_1 + 0x14) << 4) / 10;
              *(uint *)(param_1 + 0x14) = uVar22;
              if (uVar22 < uVar21) {
                *(uint *)(param_1 + 0x14) = uVar21;
              }
              uVar8 = FUN_00193e18(*puVar24,*(int *)(param_1 + 0x14) * 0x2c);
              *(undefined4 *)(param_1 + 0x18) = uVar8;
              if (*(int *)(param_1 + 0x10) != 0) {
                uVar22 = 0;
                iVar23 = 0;
                do {
                  pvVar11 = (void *)(iVar23 + iVar6);
                  uVar22 = uVar22 + 1;
                  pvVar9 = (void *)(iVar23 + *(int *)(param_1 + 0x18));
                  iVar23 = iVar23 + 0x2c;
                  _memcpy(pvVar9,pvVar11,0x2c);
                } while (uVar22 < *(uint *)(param_1 + 0x10));
              }
              FUN_00193cc0(*puVar24,iVar6);
              iVar6 = *(int *)(param_1 + 0x18);
            }
            *(uint *)(param_1 + 0x10) = uVar21;
          }
          piVar4 = (int *)(uVar20 * 0x2c + iVar6);
          if (piVar4[9] != 0) {
            iVar23 = 0;
            pbVar12 = local_74;
            do {
              if (*(int *)pbVar12 != 0) {
                iVar26 = 4;
                iVar17 = 0;
                piVar5 = piVar4;
                while ((*(int *)pbVar12 != piVar5[4] ||
                       (local_64[iVar23] != *(byte *)((int)piVar4 + iVar17 + 0x20)))) {
                  iVar17 = iVar17 + 1;
                  piVar5 = piVar5 + 1;
                  iVar26 = iVar26 + -1;
                  if (iVar26 == 0) goto LAB_00142744;
                }
                if ((iVar17 == -1) ||
                   ((*(int *)(pbVar12 + -0x10) != 0 && ((iVar17 != iVar23 || (piVar4[iVar17] == 0)))
                    ))) break;
              }
              bVar1 = iVar23 == 3;
              pbVar12 = pbVar12 + 4;
              iVar23 = iVar23 + 1;
              if (bVar1) goto LAB_00142098;
            } while( true );
          }
LAB_00142744:
          uVar20 = uVar20 + 1;
          if (uVar7 == uVar20) goto LAB_00141e9c;
          uVar21 = *(uint *)(param_1 + 0x10);
        } while( true );
      }
      iVar6 = *(int *)(param_1 + 0x18);
      goto LAB_00141fd8;
    }
  }
  goto LAB_001420b0;
LAB_00141e9c:
  uVar21 = 0;
  iVar23 = 0;
  do {
    if (*(uint *)(param_1 + 0x10) <= uVar21) {
      uVar20 = uVar21 + 1;
      if (*(uint *)(param_1 + 0x14) < uVar20) {
        uVar22 = (*(uint *)(param_1 + 0x14) << 4) / 10;
        *(uint *)(param_1 + 0x14) = uVar22;
        if (uVar22 < uVar20) {
          *(uint *)(param_1 + 0x14) = uVar20;
        }
        uVar8 = FUN_00193e18(*puVar24,*(int *)(param_1 + 0x14) * 0x2c);
        *(undefined4 *)(param_1 + 0x18) = uVar8;
        if (*(int *)(param_1 + 0x10) != 0) {
          uVar22 = 0;
          iVar17 = 0;
          do {
            uVar22 = uVar22 + 1;
            _memcpy((void *)(iVar17 + *(int *)(param_1 + 0x18)),(void *)(iVar17 + iVar6),0x2c);
            iVar17 = iVar17 + 0x2c;
          } while (uVar22 < *(uint *)(param_1 + 0x10));
        }
        FUN_00193cc0(*puVar24,iVar6);
        iVar6 = *(int *)(param_1 + 0x18);
      }
      *(uint *)(param_1 + 0x10) = uVar20;
    }
    piVar4 = (int *)(iVar23 + iVar6);
    iVar17 = 4;
    pbVar12 = local_64;
    pbVar18 = (byte *)(piVar4 + 8);
    piVar5 = piVar4;
    piVar10 = local_84;
    while ((*piVar5 == *piVar10 && (piVar5[4] == piVar10[4]))) {
      bVar19 = *pbVar18;
      pbVar18 = pbVar18 + 1;
      bVar3 = *pbVar12;
      pbVar12 = pbVar12 + 1;
      if (bVar19 != bVar3) break;
      piVar5 = piVar5 + 1;
      piVar10 = piVar10 + 1;
      iVar17 = iVar17 + -1;
      if (iVar17 == 0) goto LAB_00142098;
    }
    uVar21 = uVar21 + 1;
    iVar23 = iVar23 + 0x2c;
  } while (uVar7 != uVar21);
  if (*(uint *)(param_1 + 0x10) <= uVar7) {
LAB_00141fd8:
    uVar21 = uVar7 + 1;
    if (*(uint *)(param_1 + 0x14) < uVar21) {
      uVar20 = (*(uint *)(param_1 + 0x14) << 4) / 10;
      *(uint *)(param_1 + 0x14) = uVar20;
      if (uVar20 < uVar21) {
        *(uint *)(param_1 + 0x14) = uVar21;
      }
      uVar8 = FUN_00193e18(*puVar24,*(int *)(param_1 + 0x14) * 0x2c);
      *(undefined4 *)(param_1 + 0x18) = uVar8;
      if (*(int *)(param_1 + 0x10) != 0) {
        uVar20 = 0;
        iVar23 = 0;
        do {
          uVar20 = uVar20 + 1;
          _memcpy((void *)(iVar23 + *(int *)(param_1 + 0x18)),(void *)(iVar23 + iVar6),0x2c);
          iVar23 = iVar23 + 0x2c;
        } while (uVar20 < *(uint *)(param_1 + 0x10));
      }
      FUN_00193cc0(*puVar24,iVar6);
      iVar6 = *(int *)(param_1 + 0x18);
    }
    *(uint *)(param_1 + 0x10) = uVar21;
  }
  piVar4 = (int *)(uVar7 * 0x2c + iVar6);
  local_60 = 0;
  local_5c = 0;
  _memcpy(piVar4,local_84,0x2c);
LAB_00142098:
  iVar6 = *param_4;
  param_4[iVar25 + 1] = (int)piVar4;
  *param_4 = iVar6 + 1;
LAB_001420b0:
  iVar25 = iVar25 + -1;
LAB_001420b4:
  if (iVar25 < 1) {
LAB_001426c8:
    iVar25 = 5;
    do {
      iVar6 = param_4[1];
      if (iVar6 != 0) {
        *(int *)(iVar6 + 0x28) = *(int *)(iVar6 + 0x28) + 1;
      }
      param_4 = param_4 + 1;
      iVar25 = iVar25 + -1;
    } while (iVar25 != 0);
    return 1;
  }
  iVar6 = 1;
  piVar4 = param_4;
LAB_001420c4:
  piVar5 = (int *)FUN_00105594(param_2,iVar6);
  piVar10 = (int *)FUN_00105594(param_3,iVar6);
  if (piVar5 != piVar10) {
    iVar23 = (**(code **)(*piVar5 + 0x60))(piVar5);
    if (iVar23 != 0) {
      return 0;
    }
    iVar23 = (**(code **)(*piVar10 + 0x60))(piVar10);
    if (iVar23 != 0) {
      return 0;
    }
    iVar23 = 4;
    bVar19 = 0;
    pbVar12 = local_64;
    piVar15 = local_84;
    do {
      *pbVar12 = bVar19;
      pbVar12 = pbVar12 + 1;
      *piVar15 = 0;
      bVar19 = bVar19 + 1;
      piVar15[4] = 0;
      piVar15 = piVar15 + 1;
      iVar23 = iVar23 + -1;
    } while (iVar23 != 0);
    iVar23 = FUN_001054ec(param_2,iVar6);
    iVar17 = 0;
    local_88 = *(undefined4 *)(iVar23 + 0x10);
    do {
      uVar7 = (uint)*(byte *)((int)local_84 + iVar17 + -4);
      if (uVar7 != 4) {
        pbVar14 = local_74;
        pbVar16 = local_64;
        iVar23 = 4;
        pbVar12 = pbVar14;
        pbVar18 = pbVar16;
        do {
          if ((piVar5 == *(int **)pbVar12) && (uVar7 == *pbVar18)) goto LAB_001421bc;
          pbVar12 = pbVar12 + 4;
          pbVar18 = pbVar18 + 1;
          iVar23 = iVar23 + -1;
        } while (iVar23 != 0);
        iVar23 = 4;
        uVar21 = 0;
        piVar15 = piVar5;
        while( true ) {
          piVar13 = *(int **)pbVar14;
          if (piVar13 == (int *)0x0) break;
          uVar20 = (uint)*pbVar16;
          if ((uVar21 != uVar20) &&
             ((piVar15[0x53] < piVar13[0x53] ||
              ((piVar13[0x53] == piVar15[0x53] && (uVar7 < uVar20)))))) {
            *(int **)pbVar14 = piVar15;
            *pbVar16 = (byte)uVar7;
            uVar7 = uVar20;
            piVar15 = piVar13;
          }
          uVar21 = uVar21 + 1;
          pbVar14 = pbVar14 + 4;
          pbVar16 = pbVar16 + 1;
          iVar23 = iVar23 + -1;
          if (iVar23 == 0) {
            bVar1 = false;
            goto LAB_0014225c;
          }
        }
        local_64[uVar21] = (byte)uVar7;
        *(int **)(local_74 + uVar21 * 4) = piVar15;
      }
LAB_001421bc:
      bVar1 = iVar17 != 3;
      iVar17 = iVar17 + 1;
    } while (bVar1);
    bVar1 = true;
LAB_0014225c:
    iVar23 = FUN_001054ec(param_3,iVar6);
    iVar17 = 0;
    local_88 = *(undefined4 *)(iVar23 + 0x10);
    do {
      uVar7 = (uint)*(byte *)((int)local_84 + iVar17 + -4);
      if (uVar7 != 4) {
        pbVar14 = local_74;
        pbVar16 = local_64;
        iVar23 = 4;
        pbVar12 = pbVar14;
        pbVar18 = pbVar16;
        do {
          if ((piVar10 == *(int **)pbVar12) && (uVar7 == *pbVar18)) goto LAB_001422b0;
          pbVar12 = pbVar12 + 4;
          pbVar18 = pbVar18 + 1;
          iVar23 = iVar23 + -1;
        } while (iVar23 != 0);
        iVar23 = 4;
        uVar21 = 0;
        piVar5 = piVar10;
        while( true ) {
          piVar15 = *(int **)pbVar14;
          if (piVar15 == (int *)0x0) break;
          uVar20 = (uint)*pbVar16;
          if ((uVar21 != uVar20) &&
             ((piVar5[0x53] < piVar15[0x53] || ((piVar15[0x53] == piVar5[0x53] && (uVar7 < uVar20)))
              ))) {
            *(int **)pbVar14 = piVar5;
            *pbVar16 = (byte)uVar7;
            uVar7 = uVar20;
            piVar5 = piVar15;
          }
          uVar21 = uVar21 + 1;
          pbVar14 = pbVar14 + 4;
          pbVar16 = pbVar16 + 1;
          iVar23 = iVar23 + -1;
          if (iVar23 == 0) {
            bVar2 = false;
            goto LAB_00142338;
          }
        }
        local_64[uVar21] = (byte)uVar7;
        *(int **)(local_74 + uVar21 * 4) = piVar5;
      }
LAB_001422b0:
      bVar2 = iVar17 != 3;
      iVar17 = iVar17 + 1;
    } while (bVar2);
    bVar2 = true;
LAB_00142338:
    if (!bVar1) {
      return 0;
    }
    if (!bVar2) {
      return 0;
    }
    puVar24 = (undefined4 *)(param_1 + 0xc);
    uVar7 = *(uint *)(param_1 + 0x10);
    if (uVar7 != 0) {
      iVar23 = *(int *)(param_1 + 0x18);
      uVar20 = 0;
      uVar21 = uVar7;
      do {
        if (uVar21 <= uVar20) {
          uVar21 = uVar20 + 1;
          if (*(uint *)(param_1 + 0x14) < uVar21) {
            uVar22 = (*(uint *)(param_1 + 0x14) << 4) / 10;
            *(uint *)(param_1 + 0x14) = uVar22;
            if (uVar22 < uVar21) {
              *(uint *)(param_1 + 0x14) = uVar21;
            }
            uVar8 = FUN_00193e18(*puVar24,*(int *)(param_1 + 0x14) * 0x2c);
            *(undefined4 *)(param_1 + 0x18) = uVar8;
            if (*(int *)(param_1 + 0x10) != 0) {
              uVar22 = 0;
              iVar17 = 0;
              do {
                uVar22 = uVar22 + 1;
                _memcpy((void *)(*(int *)(param_1 + 0x18) + iVar17),(void *)(iVar23 + iVar17),0x2c);
                iVar17 = iVar17 + 0x2c;
              } while (uVar22 < *(uint *)(param_1 + 0x10));
            }
            FUN_00193cc0(*puVar24,iVar23);
            iVar23 = *(int *)(param_1 + 0x18);
          }
          *(uint *)(param_1 + 0x10) = uVar21;
        }
        piVar5 = (int *)(uVar20 * 0x2c + iVar23);
        if (piVar5[9] != 0) {
          iVar17 = 0;
          pbVar12 = local_74;
          do {
            if (*(int *)pbVar12 != 0) {
              iVar27 = 4;
              iVar26 = 0;
              piVar10 = piVar5;
              while ((*(int *)pbVar12 != piVar10[4] ||
                     (local_64[iVar17] != *(byte *)((int)piVar5 + iVar26 + 0x20)))) {
                iVar26 = iVar26 + 1;
                piVar10 = piVar10 + 1;
                iVar27 = iVar27 + -1;
                if (iVar27 == 0) goto LAB_00142780;
              }
              if ((iVar26 == -1) ||
                 ((*(int *)(pbVar12 + -0x10) != 0 && ((iVar26 != iVar17 || (piVar5[iVar26] == 0)))))
                 ) break;
            }
            bVar1 = iVar17 == 3;
            pbVar12 = pbVar12 + 4;
            iVar17 = iVar17 + 1;
            if (bVar1) goto LAB_001426a8;
          } while( true );
        }
LAB_00142780:
        uVar20 = uVar20 + 1;
        if (uVar7 == uVar20) goto LAB_001424ac;
        uVar21 = *(uint *)(param_1 + 0x10);
      } while( true );
    }
    iVar23 = *(int *)(param_1 + 0x18);
    goto LAB_001425e8;
  }
  goto LAB_001426b8;
LAB_001424ac:
  uVar21 = 0;
  iVar17 = 0;
  do {
    if (*(uint *)(param_1 + 0x10) <= uVar21) {
      uVar20 = uVar21 + 1;
      if (*(uint *)(param_1 + 0x14) < uVar20) {
        uVar22 = (*(uint *)(param_1 + 0x14) << 4) / 10;
        *(uint *)(param_1 + 0x14) = uVar22;
        if (uVar22 < uVar20) {
          *(uint *)(param_1 + 0x14) = uVar20;
        }
        uVar8 = FUN_00193e18(*puVar24,*(int *)(param_1 + 0x14) * 0x2c);
        *(undefined4 *)(param_1 + 0x18) = uVar8;
        if (*(int *)(param_1 + 0x10) != 0) {
          uVar22 = 0;
          iVar26 = 0;
          do {
            pvVar11 = (void *)(iVar26 + iVar23);
            uVar22 = uVar22 + 1;
            pvVar9 = (void *)(iVar26 + *(int *)(param_1 + 0x18));
            iVar26 = iVar26 + 0x2c;
            _memcpy(pvVar9,pvVar11,0x2c);
          } while (uVar22 < *(uint *)(param_1 + 0x10));
        }
        FUN_00193cc0(*puVar24,iVar23);
        iVar23 = *(int *)(param_1 + 0x18);
      }
      *(uint *)(param_1 + 0x10) = uVar20;
    }
    piVar5 = (int *)(iVar17 + iVar23);
    iVar26 = 4;
    pbVar12 = local_64;
    pbVar18 = (byte *)(piVar5 + 8);
    piVar10 = piVar5;
    piVar15 = local_84;
    while ((*piVar10 == *piVar15 && (piVar10[4] == piVar15[4]))) {
      bVar19 = *pbVar18;
      pbVar18 = pbVar18 + 1;
      bVar3 = *pbVar12;
      pbVar12 = pbVar12 + 1;
      if (bVar19 != bVar3) break;
      piVar10 = piVar10 + 1;
      piVar15 = piVar15 + 1;
      iVar26 = iVar26 + -1;
      if (iVar26 == 0) goto LAB_001426a8;
    }
    uVar21 = uVar21 + 1;
    iVar17 = iVar17 + 0x2c;
  } while (uVar7 != uVar21);
  if (*(uint *)(param_1 + 0x10) <= uVar7) {
LAB_001425e8:
    uVar21 = uVar7 + 1;
    if (*(uint *)(param_1 + 0x14) < uVar21) {
      uVar20 = (*(uint *)(param_1 + 0x14) << 4) / 10;
      *(uint *)(param_1 + 0x14) = uVar20;
      if (uVar20 < uVar21) {
        *(uint *)(param_1 + 0x14) = uVar21;
      }
      uVar8 = FUN_00193e18(*puVar24,*(int *)(param_1 + 0x14) * 0x2c);
      *(undefined4 *)(param_1 + 0x18) = uVar8;
      if (*(int *)(param_1 + 0x10) != 0) {
        uVar20 = 0;
        iVar17 = 0;
        do {
          pvVar11 = (void *)(iVar23 + iVar17);
          uVar20 = uVar20 + 1;
          pvVar9 = (void *)(*(int *)(param_1 + 0x18) + iVar17);
          iVar17 = iVar17 + 0x2c;
          _memcpy(pvVar9,pvVar11,0x2c);
        } while (uVar20 < *(uint *)(param_1 + 0x10));
      }
      FUN_00193cc0(*puVar24,iVar23);
      iVar23 = *(int *)(param_1 + 0x18);
    }
    *(uint *)(param_1 + 0x10) = uVar21;
  }
  local_60 = 0;
  piVar5 = (int *)(uVar7 * 0x2c + iVar23);
  local_5c = 0;
  _memcpy(piVar5,local_84,0x2c);
LAB_001426a8:
  iVar23 = *param_4;
  piVar4[2] = (int)piVar5;
  *param_4 = iVar23 + 1;
LAB_001426b8:
  iVar6 = iVar6 + 1;
  piVar4 = piVar4 + 1;
  if (iVar25 < iVar6) goto LAB_001426c8;
  goto LAB_001420c4;
}

/* FUN_001427a4 @ 0x1427a4 (464 bytes) */
int FUN_001427a4(param_1, param_2, param_3)
  uint *param_1;
  undefined4 param_2;
  int *param_3;
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  uint uVar8;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c [3];
  
  if ((*(int *)(param_3[0x22] + 8) == 0x8e) ||
     (iVar1 = (**(code **)(*param_3 + 0x5c))(param_3), iVar1 != 0)) {
    ((int (*)())FUN_00141044)(&local_38,param_2,param_3);
    *param_1 = local_38;
  }
  else {
    puVar6 = (uint *)param_3[4];
    uVar4 = puVar6[1];
    uVar5 = DAT_001b0040;
    if (uVar4 != 0) {
      uVar8 = 0;
      do {
        if (uVar8 < *puVar6) {
          if (uVar4 <= uVar8) {
            _memset((void *)(uVar4 * 4 + puVar6[2]),0,(uVar8 - uVar4) * 4 + 4);
            puVar6[1] = uVar8 + 1;
          }
          puVar2 = (undefined4 *)(uVar8 * 4 + puVar6[2]);
        }
        else {
          puVar2 = (undefined4 *)FUN_0019423c(puVar6,uVar8);
        }
        uVar8 = uVar8 + 1;
        piVar7 = (int *)*puVar2;
        if (piVar7 != (int *)0x0) {
          if ((*(int *)(piVar7[0x22] + 8) == 0x8e) ||
             (iVar1 = (**(code **)(*piVar7 + 0x5c))(piVar7), iVar1 != 0)) {
            ((int (*)())FUN_00141044)(&local_34,param_2,piVar7);
            uVar5 = uVar5 | local_34;
          }
          piVar3 = (int *)0x0;
          if ((piVar7[5] & 0x200U) != 0) {
            piVar3 = (int *)FUN_00105594(piVar7,piVar7[0x21]);
          }
          if (piVar3 == param_3) {
            ((int (*)())FUN_00141090)(&local_30,param_2,piVar7);
            uVar5 = uVar5 | local_30;
          }
        }
        puVar6 = (uint *)param_3[4];
        uVar4 = puVar6[1];
      } while (uVar8 < uVar4);
    }
    ((int (*)())FUN_00141044)(local_2c,param_2,param_3);
    *param_1 = uVar5 & local_2c[0];
  }
  return param_1;
}

/* FUN_00142974 @ 0x142974 (1616 bytes) */
int FUN_00142974(param_1, param_2, param_3, param_4)
  int *param_1;
  int *param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  undefined4 uVar13;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  uint local_6c;
  uint local_68;
  int local_64;
  undefined4 local_60;
  undefined1 auStack_58 [4];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48 [4];
  
  ((int (*)())FUN_001427a4)(auStack_58,param_1,param_2);
  if (param_3 == param_4) {
    return 1;
  }
  if ((*(int *)(param_2[0x22] + 8) == 0x8e) ||
     (local_68 = (**(code **)(*param_2 + 0x5c))(param_2), local_68 != 0)) {
    return 0;
  }
  local_60 = *(undefined4 *)(*param_1 + 0x378);
  local_6c = 2;
  local_64 = FUN_00193e18(local_60,8);
  puVar11 = (uint *)param_2[4];
  if (puVar11[1] != 0) {
    uVar10 = 0;
    uVar5 = 1;
    iVar6 = 0;
    do {
      uVar9 = 0;
      do {
        if (uVar9 < uVar10) {
          if (uVar10 < *puVar11) {
            uVar1 = puVar11[1];
            puVar12 = puVar11;
            if (uVar1 <= uVar10) {
              _memset((void *)(uVar1 * 4 + puVar11[2]),0,(uVar10 - uVar1) * 4 + 4);
              puVar11[1] = uVar5;
              puVar12 = (uint *)param_2[4];
            }
            piVar2 = (int *)(iVar6 + puVar11[2]);
          }
          else {
            piVar2 = (int *)FUN_0019423c(puVar11,uVar10);
            puVar12 = (uint *)param_2[4];
          }
          iVar7 = *piVar2;
          if (uVar9 < *puVar12) {
            uVar1 = puVar12[1];
            puVar11 = puVar12;
            if (uVar1 <= uVar9) {
              _memset((void *)(uVar1 * 4 + puVar12[2]),0,(uVar9 - uVar1) * 4 + 4);
              puVar12[1] = uVar9 + 1;
              puVar11 = (uint *)param_2[4];
            }
            piVar2 = (int *)(uVar9 * 4 + puVar12[2]);
          }
          else {
            piVar2 = (int *)FUN_0019423c(puVar12,uVar9);
            puVar11 = (uint *)param_2[4];
          }
          if (iVar7 == *piVar2) break;
        }
        if (uVar10 == uVar9) {
          if (uVar10 < *puVar11) {
            uVar1 = puVar11[1];
            if (uVar1 <= uVar10) {
              _memset((void *)(uVar1 * 4 + puVar11[2]),0,(uVar10 - uVar1) * 4 + 4);
              puVar11[1] = uVar5;
            }
            puVar3 = (undefined4 *)(iVar6 + puVar11[2]);
          }
          else {
            puVar3 = (undefined4 *)FUN_0019423c(puVar11,uVar10);
          }
          piVar2 = (int *)*puVar3;
          if (piVar2 != (int *)0x0) {
            if ((*(int *)(piVar2[0x22] + 8) == 0x8e) ||
               (iVar7 = (**(code **)(*piVar2 + 0x5c))(piVar2), iVar7 != 0)) {
              ((int (*)())FUN_00141044)(&local_54,param_1,piVar2);
              local_78 = local_54;
              if (*(char *)((int)&local_78 + param_3) != '\0') goto LAB_00142f88;
            }
            piVar4 = (int *)0x0;
            if ((piVar2[5] & 0x200U) != 0) {
              piVar4 = (int *)FUN_00105594(piVar2,piVar2[0x21]);
            }
            uVar1 = local_68;
            if (piVar4 == param_2) {
              if (local_68 < local_6c) {
                iVar7 = local_68 * 4;
                _memset((void *)(iVar7 + local_64),0,4);
                local_68 = uVar1 + 1;
                puVar3 = (undefined4 *)(iVar7 + local_64);
              }
              else {
                puVar3 = (undefined4 *)FUN_0019423c(&local_6c,local_68);
              }
              *puVar3 = piVar2;
              puVar11 = (uint *)param_2[4];
              goto LAB_00142c3c;
            }
          }
          puVar11 = (uint *)param_2[4];
        }
LAB_00142c3c:
        uVar9 = uVar9 + 1;
      } while (uVar9 <= uVar10);
      uVar10 = uVar10 + 1;
      uVar5 = uVar5 + 1;
      iVar6 = iVar6 + 4;
    } while (uVar10 < puVar11[1]);
  }
  while (local_68 != 0) {
    piVar2 = (int *)0x0;
    if (local_68 - 1 < local_68) {
      piVar2 = (int *)((local_68 - 1) * 4 + local_64);
    }
    iVar6 = *piVar2;
    FUN_00194208(&local_6c);
    ((int (*)())FUN_001427a4)(&local_50,param_1,iVar6);
    local_78 = local_50;
    ((int (*)())FUN_00141090)(&local_4c,param_1,iVar6);
    local_74 = local_4c;
    if (*(char *)((int)&local_74 + param_3) != '\0') {
      iVar7 = FUN_0011379c(*param_1,iVar6);
      if (((iVar7 == 0) || (*(char *)((int)&local_74 + param_4) != '\0')) ||
         (*(char *)((int)&local_78 + param_4) != '\0')) goto LAB_00142f88;
      puVar11 = *(uint **)(iVar6 + 0x10);
      if (puVar11[1] != 0) {
        uVar10 = 0;
        uVar5 = 1;
        iVar7 = 0;
        do {
          uVar9 = 0;
          do {
            if (uVar9 < uVar10) {
              if (uVar10 < *puVar11) {
                uVar1 = puVar11[1];
                puVar12 = puVar11;
                if (uVar1 <= uVar10) {
                  _memset((void *)(uVar1 * 4 + puVar11[2]),0,(uVar10 - uVar1) * 4 + 4);
                  puVar11[1] = uVar5;
                  puVar12 = *(uint **)(iVar6 + 0x10);
                }
                piVar2 = (int *)(iVar7 + puVar11[2]);
              }
              else {
                piVar2 = (int *)FUN_0019423c(puVar11,uVar10);
                puVar12 = *(uint **)(iVar6 + 0x10);
              }
              iVar8 = *piVar2;
              if (uVar9 < *puVar12) {
                uVar1 = puVar12[1];
                puVar11 = puVar12;
                if (uVar1 <= uVar9) {
                  _memset((void *)(uVar1 * 4 + puVar12[2]),0,(uVar9 - uVar1) * 4 + 4);
                  puVar12[1] = uVar9 + 1;
                  puVar11 = *(uint **)(iVar6 + 0x10);
                }
                piVar2 = (int *)(uVar9 * 4 + puVar12[2]);
              }
              else {
                piVar2 = (int *)FUN_0019423c(puVar12,uVar9);
                puVar11 = *(uint **)(iVar6 + 0x10);
              }
              if (iVar8 == *piVar2) break;
            }
            if (uVar10 == uVar9) {
              if (uVar10 < *puVar11) {
                uVar1 = puVar11[1];
                if (uVar1 <= uVar10) {
                  _memset((void *)(uVar1 * 4 + puVar11[2]),0,(uVar10 - uVar1) * 4 + 4);
                  puVar11[1] = uVar5;
                }
                puVar3 = (undefined4 *)(iVar7 + puVar11[2]);
              }
              else {
                puVar3 = (undefined4 *)FUN_0019423c(puVar11,uVar10);
              }
              piVar2 = (int *)*puVar3;
              if (piVar2 != (int *)0x0) {
                if ((*(int *)(piVar2[0x22] + 8) == 0x8e) ||
                   (iVar8 = (**(code **)(*piVar2 + 0x5c))(piVar2), iVar8 != 0)) {
                  ((int (*)())FUN_00141044)(local_48,param_1,piVar2);
                  local_70 = local_48[0];
                  if (*(char *)((int)&local_70 + param_3) != '\0') goto LAB_00142f88;
                }
                iVar8 = 0;
                if ((piVar2[5] & 0x200U) != 0) {
                  iVar8 = FUN_00105594(piVar2,piVar2[0x21]);
                }
                uVar1 = local_68;
                if (iVar8 == iVar6) {
                  if (local_68 < local_6c) {
                    iVar8 = local_68 * 4;
                    _memset((void *)(iVar8 + local_64),0,4);
                    local_68 = uVar1 + 1;
                    puVar3 = (undefined4 *)(iVar8 + local_64);
                  }
                  else {
                    puVar3 = (undefined4 *)FUN_0019423c(&local_6c,local_68);
                  }
                  *puVar3 = piVar2;
                  puVar11 = *(uint **)(iVar6 + 0x10);
                  goto LAB_00142f38;
                }
              }
              puVar11 = *(uint **)(iVar6 + 0x10);
            }
LAB_00142f38:
            uVar9 = uVar9 + 1;
          } while (uVar9 <= uVar10);
          uVar10 = uVar10 + 1;
          uVar5 = uVar5 + 1;
          iVar7 = iVar7 + 4;
        } while (uVar10 < puVar11[1]);
      }
    }
  }
  uVar13 = 1;
LAB_00142f8c:
  FUN_00193cc0(local_60,local_64);
  return uVar13;
LAB_00142f88:
  uVar13 = 0;
  goto LAB_00142f8c;
}

/* FUN_00142fdc @ 0x142fdc (1672 bytes) */
int FUN_00142fdc(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined1 uVar8;
  int iVar9;
  undefined1 local_b8 [4];
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  undefined4 local_a4;
  uint local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  uint local_90;
  int local_8c [5];
  uint local_78;
  undefined1 auStack_74 [4];
  uint local_70;
  undefined4 local_6c;
  uint local_68;
  undefined1 auStack_64 [4];
  uint local_60;
  undefined4 local_5c [4];
  
  ((int (*)())FUN_00141044)(&local_78,param_1,param_2);
  ((int (*)())FUN_00140e70)(auStack_74,param_1,param_2);
  ((int (*)())FUN_001427a4)(&local_70,param_1,param_2);
  local_a8 = local_70;
  ((int (*)())FUN_00141090)(&local_6c,param_1,param_2);
  local_a4 = local_6c;
  ((int (*)())FUN_00141044)(&local_68,param_1,param_3);
  ((int (*)())FUN_00140e70)(auStack_64,param_1,param_3);
  ((int (*)())FUN_001427a4)(&local_60,param_1,param_3);
  local_a0 = local_60;
  ((int (*)())FUN_00141090)(local_5c,param_1,param_3);
  uVar2 = DAT_001b003c;
  iVar3 = 0;
  *param_4 = DAT_001b003c;
  *param_5 = uVar2;
  local_94 = DAT_001b0040;
  local_9c = local_5c[0];
  local_98 = DAT_001b0040;
  if ((*(uint *)(param_2 + 0x14) & 0x200) != 0) {
    iVar3 = FUN_00105594(param_2,*(undefined4 *)(param_2 + 0x84));
  }
  if (iVar3 != param_3) {
    iVar3 = 0;
    iVar9 = 4;
    piVar5 = local_8c;
    do {
      if (*(char *)((int)&local_a4 + iVar3) != '\0') {
        *(undefined1 *)((int)&local_98 + iVar3) = 0;
        *(undefined1 *)((int)&local_94 + iVar3) = 1;
        *piVar5 = param_2;
        local_b8[iVar3] = (char)iVar3;
      }
      iVar3 = iVar3 + 1;
      piVar5 = piVar5 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  iVar3 = 0;
  if ((*(uint *)(param_3 + 0x14) & 0x200) != 0) {
    iVar3 = FUN_00105594(param_3,*(undefined4 *)(param_3 + 0x84));
  }
  if (iVar3 != param_2) {
    iVar3 = 0;
    piVar5 = local_8c;
    do {
      if (*(char *)((int)&local_9c + iVar3) != '\0') {
        if (*(char *)((int)&local_94 + iVar3) == '\0') {
          *(undefined1 *)((int)&local_98 + iVar3) = 0;
          *(undefined1 *)((int)&local_94 + iVar3) = 1;
          *piVar5 = param_3;
          local_b8[iVar3] = (char)iVar3;
        }
        else {
          iVar9 = 0;
          if ((*(uint *)(param_3 + 0x14) & 0x200) != 0) {
            iVar9 = FUN_00105594(param_3,*(undefined4 *)(param_3 + 0x84));
          }
          iVar4 = 0;
          if ((*(uint *)(param_2 + 0x14) & 0x200) != 0) {
            iVar4 = FUN_00105594(param_2,*(undefined4 *)(param_2 + 0x84));
          }
          if (iVar9 != iVar4) {
            return 0;
          }
        }
      }
      bVar1 = iVar3 != 3;
      piVar5 = piVar5 + 1;
      iVar3 = iVar3 + 1;
    } while (bVar1);
  }
  iVar3 = 0;
  piVar5 = local_8c;
  puVar7 = param_4;
  do {
    if (*(char *)((int)&local_a8 + iVar3) != '\0') {
      iVar9 = 0;
      uVar8 = (undefined1)iVar3;
      if (*(char *)((int)&local_94 + iVar3) == '\0') {
        *piVar5 = param_2;
        *(undefined1 *)puVar7 = uVar8;
        *(undefined1 *)((int)&local_98 + iVar3) = 1;
        *(undefined1 *)((int)&local_94 + iVar3) = 1;
        local_b8[iVar3] = uVar8;
      }
      else {
        while ((*(char *)((int)&local_94 + iVar9) != '\0' ||
               (iVar4 = ((int (*)())FUN_00142974)(param_1,param_2,iVar3,iVar9), iVar4 == 0))) {
          bVar1 = iVar9 == 3;
          iVar9 = iVar9 + 1;
          if (bVar1) {
            return 0;
          }
        }
        *(undefined1 *)((int)&local_94 + iVar9) = 1;
        local_8c[iVar9] = param_2;
        *(undefined1 *)((int)&local_98 + iVar9) = 1;
        *(char *)puVar7 = (char)iVar9;
        local_b8[iVar9] = uVar8;
      }
    }
    bVar1 = iVar3 != 3;
    piVar5 = piVar5 + 1;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    iVar3 = iVar3 + 1;
  } while (bVar1);
  iVar3 = 0;
  if ((*(uint *)(param_3 + 0x14) & 0x200) != 0) {
    iVar3 = FUN_00105594(param_3,*(undefined4 *)(param_3 + 0x84));
  }
  if (iVar3 == param_2) {
    iVar9 = 4;
    iVar3 = 0;
    puVar7 = param_5;
    do {
      if (*(char *)((int)&local_9c + iVar3) != '\0') {
        *(undefined1 *)puVar7 = *(undefined1 *)((int)param_4 + iVar3);
      }
      iVar3 = iVar3 + 1;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  iVar3 = 0;
  piVar5 = local_8c;
  puVar7 = param_5;
  do {
    if (*(char *)((int)&local_a0 + iVar3) != '\0') {
      uVar8 = (undefined1)iVar3;
      if (*(char *)((int)&local_94 + iVar3) == '\0') {
        *(undefined1 *)((int)&local_98 + iVar3) = 1;
        *piVar5 = param_3;
        *(undefined1 *)puVar7 = uVar8;
        *(undefined1 *)((int)&local_94 + iVar3) = 1;
        local_b8[iVar3] = uVar8;
      }
      else if ((*(char *)((int)&local_98 + iVar3) == '\0') ||
              (iVar9 = ((int (*)())FUN_00141100)(param_1,*piVar5,local_b8[iVar3],param_3,iVar3), iVar9 == 0)) {
        iVar9 = 0;
        while ((*(char *)((int)&local_94 + iVar9) != '\0' ||
               (iVar4 = ((int (*)())FUN_00142974)(param_1,param_3,iVar3,iVar9), iVar4 == 0))) {
          bVar1 = iVar9 == 3;
          iVar9 = iVar9 + 1;
          if (bVar1) {
            return 0;
          }
        }
        *(undefined1 *)((int)&local_94 + iVar9) = 1;
        local_8c[iVar9] = param_3;
        *(undefined1 *)((int)&local_98 + iVar9) = 1;
        *(char *)puVar7 = (char)iVar9;
        local_b8[iVar9] = uVar8;
      }
    }
    bVar1 = iVar3 != 3;
    piVar5 = piVar5 + 1;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    iVar3 = iVar3 + 1;
  } while (bVar1);
  iVar3 = 0;
  if ((*(uint *)(param_2 + 0x14) & 0x200) != 0) {
    iVar3 = FUN_00105594(param_2,*(undefined4 *)(param_2 + 0x84));
  }
  if (iVar3 == param_3) {
    iVar9 = 4;
    iVar3 = 0;
    puVar7 = param_4;
    do {
      if (*(char *)((int)&local_a4 + iVar3) != '\0') {
        *(undefined1 *)puVar7 = *(undefined1 *)((int)param_5 + iVar3);
      }
      iVar3 = iVar3 + 1;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  iVar3 = 0;
  uVar6 = ~local_a8;
  do {
    local_ac = uVar6 << 0x18 | (uVar6 & 0xff00) << 8 | uVar6 >> 8 & 0xff00 | uVar6 >> 0x18;
    local_b4 = local_78 & local_ac;
    if (*(char *)((int)&local_b4 + iVar3) != '\0') {
      iVar9 = 0;
      do {
        if ((*(char *)((int)&local_98 + iVar9) != '\0') &&
           (iVar4 = ((int (*)())FUN_00141100)(param_1,local_8c[iVar9],local_b8[iVar9],param_2,iVar3), iVar4 != 0)
           ) {
          *(char *)param_4 = (char)iVar9;
          goto LAB_001434fc;
        }
        bVar1 = iVar9 != 3;
        iVar9 = iVar9 + 1;
      } while (bVar1);
      iVar9 = 0;
      iVar4 = 4;
      while (*(char *)((int)&local_94 + iVar9) != '\0') {
        iVar9 = iVar9 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
          return 0;
        }
      }
      *(undefined1 *)((int)&local_94 + iVar9) = 1;
      local_8c[iVar9] = param_2;
      *(undefined1 *)((int)&local_98 + iVar9) = 1;
      *(char *)param_4 = (char)iVar9;
      local_b8[iVar9] = (char)iVar3;
    }
LAB_001434fc:
    bVar1 = iVar3 != 3;
    param_4 = (undefined4 *)((int)param_4 + 1);
    iVar3 = iVar3 + 1;
  } while (bVar1);
  iVar3 = 0;
  uVar6 = ~local_a0;
  do {
    local_b0 = uVar6 << 0x18 | (uVar6 & 0xff00) << 8 | uVar6 >> 8 & 0xff00 | uVar6 >> 0x18;
    local_90 = local_68 & local_b0;
    if (*(char *)((int)local_8c + iVar3 + -4) != '\0') {
      iVar9 = 0;
      do {
        if ((*(char *)((int)&local_98 + iVar9) != '\0') &&
           (iVar4 = ((int (*)())FUN_00141100)(param_1,local_8c[iVar9],local_b8[iVar9],param_3,iVar3), iVar4 != 0)
           ) {
          *(char *)param_5 = (char)iVar9;
          goto LAB_001435e4;
        }
        bVar1 = iVar9 != 3;
        iVar9 = iVar9 + 1;
      } while (bVar1);
      iVar9 = 0;
      iVar4 = 4;
      while (*(char *)((int)&local_94 + iVar9) != '\0') {
        iVar9 = iVar9 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
          return 0;
        }
      }
      *(undefined1 *)((int)&local_94 + iVar9) = 1;
      local_8c[iVar9] = param_3;
      *(undefined1 *)((int)&local_98 + iVar9) = 1;
      *(char *)param_5 = (char)iVar9;
      local_b8[iVar9] = (char)iVar3;
    }
LAB_001435e4:
    bVar1 = iVar3 == 3;
    param_5 = (undefined4 *)((int)param_5 + 1);
    iVar3 = iVar3 + 1;
    if (bVar1) {
      return 1;
    }
  } while( true );
}

/* FUN_00143664 @ 0x143664 (80 bytes) */
int FUN_00143664(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())FUN_00140e7c)();
  ((int (*)())FUN_00142fdc)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* FUN_001436b4 @ 0x1436b4 (168 bytes) */
int FUN_001436b4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  int iVar1;
  
  *param_4 = param_2;
  param_4[1] = param_3;
  iVar1 = ((int (*)())FUN_00140e7c)();
  if ((((iVar1 != 0) &&
       (iVar1 = ((int (*)())FUN_00143664)(param_1,param_2,param_3,param_4 + 2,param_4 + 3), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_001418b0)(param_1,param_2,param_3,param_4 + 4), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_00141930)(param_1,param_2,param_3,param_4 + 5), iVar1 != 0)) {
    return 1;
  }
  return 0;
}

/* FUN_0014375c @ 0x14375c (1720 bytes) */
int FUN_0014375c(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  bool bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint *puVar16;
  uint *puVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int iStack00000020;
  int local_78;
  undefined4 local_74;
  uint local_70;
  uint local_6c;
  int local_68;
  undefined4 local_64;
  uint local_60;
  uint local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_48 [2];
  
  local_64 = *(undefined4 *)(*param_1 + 0x378);
  local_6c = 0;
  local_70 = 2;
  iStack00000020 = param_3;
  local_68 = FUN_00193e18(local_64,8);
  local_54 = *(undefined4 *)(*param_1 + 0x378);
  local_5c = 0;
  local_60 = 2;
  local_58 = FUN_00193e18(local_54,8);
  uVar9 = local_6c;
  if (local_6c < local_70) {
    iVar11 = local_6c * 4;
    _memset((void *)(iVar11 + local_68),0,4);
    local_6c = uVar9 + 1;
    puVar5 = (undefined4 *)(iVar11 + local_68);
  }
  else {
    puVar5 = (undefined4 *)FUN_0019423c(&local_70,local_6c);
  }
  uVar9 = local_5c;
  iVar11 = iStack00000020;
  *puVar5 = param_2;
  if (local_5c < local_60) {
    iVar15 = local_5c * 4;
    _memset((void *)(iVar15 + local_58),0,4);
    local_5c = uVar9 + 1;
    piVar6 = (int *)(iVar15 + local_58);
  }
  else {
    piVar6 = (int *)FUN_0019423c(&local_60,local_5c);
  }
  *piVar6 = iVar11;
  do {
    do {
      do {
        if (local_6c == 0) {
          FUN_00193cc0(local_54,local_58);
          FUN_00193cc0(local_64,local_68);
          return;
        }
        piVar6 = (int *)0x0;
        if (local_6c - 1 < local_6c) {
          piVar6 = (int *)((local_6c - 1) * 4 + local_68);
        }
        iVar11 = *piVar6;
        FUN_00194208(&local_70);
        piVar6 = (int *)0x0;
        if (local_5c - 1 < local_5c) {
          piVar6 = (int *)((local_5c - 1) * 4 + local_58);
        }
        iVar15 = *piVar6;
        FUN_00194208(&local_60);
        iStack00000020 = iVar15;
      } while (iVar15 == DAT_001b003c);
      puVar16 = *(uint **)(iVar11 + 0x10);
      if (puVar16[1] != 0) {
        uVar14 = 0;
        uVar9 = 1;
        iVar15 = 0;
        do {
          uVar13 = 0;
          do {
            if (uVar13 < uVar14) {
              if (uVar14 < *puVar16) {
                uVar4 = puVar16[1];
                puVar17 = puVar16;
                if (uVar4 <= uVar14) {
                  _memset((void *)(uVar4 * 4 + puVar16[2]),0,(uVar14 - uVar4) * 4 + 4);
                  puVar16[1] = uVar9;
                  puVar17 = *(uint **)(iVar11 + 0x10);
                }
                piVar6 = (int *)(iVar15 + puVar16[2]);
              }
              else {
                piVar6 = (int *)FUN_0019423c(puVar16,uVar14);
                puVar17 = *(uint **)(iVar11 + 0x10);
              }
              iVar18 = *piVar6;
              if (uVar13 < *puVar17) {
                uVar4 = puVar17[1];
                puVar16 = puVar17;
                if (uVar4 <= uVar13) {
                  _memset((void *)(uVar4 * 4 + puVar17[2]),0,(uVar13 - uVar4) * 4 + 4);
                  puVar17[1] = uVar13 + 1;
                  puVar16 = *(uint **)(iVar11 + 0x10);
                }
                piVar6 = (int *)(uVar13 * 4 + puVar17[2]);
              }
              else {
                piVar6 = (int *)FUN_0019423c(puVar17,uVar13);
                puVar16 = *(uint **)(iVar11 + 0x10);
              }
              if (iVar18 == *piVar6) break;
            }
            if (uVar14 == uVar13) {
              if (uVar14 < *puVar16) {
                uVar4 = puVar16[1];
                if (uVar4 <= uVar14) {
                  _memset((void *)(uVar4 * 4 + puVar16[2]),0,(uVar14 - uVar4) * 4 + 4);
                  puVar16[1] = uVar9;
                }
                piVar6 = (int *)(iVar15 + puVar16[2]);
              }
              else {
                piVar6 = (int *)FUN_0019423c(puVar16,uVar14);
              }
              iVar18 = *piVar6;
              if (iVar18 != 0) {
                iVar12 = *(int *)(iVar18 + 0x84);
                if ((*(uint *)(iVar18 + 0x14) & 0x200) != 0) {
                  iVar12 = iVar12 + -1;
                }
                if (0 < iVar12) {
                  iVar19 = 1;
                  do {
                    iVar7 = FUN_00105594(iVar18,iVar19);
                    if (iVar11 == iVar7) {
                      iVar7 = FUN_001054ec(iVar18,iVar19);
                      iVar8 = 0;
                      local_78 = *(int *)(iVar7 + 0x10);
                      iVar7 = 4;
                      do {
                        if (*(byte *)((int)&local_78 + iVar8) != 4) {
                          *(undefined1 *)((int)&local_78 + iVar8) =
                               *(undefined1 *)
                                ((int)&STACKARG(0x20) + (uint)*(byte *)((int)&local_78 + iVar8));
                        }
                        iVar3 = local_78;
                        iVar8 = iVar8 + 1;
                        iVar7 = iVar7 + -1;
                      } while (iVar7 != 0);
                      iVar7 = FUN_001054ec(iVar18,iVar19);
                      *(int *)(iVar7 + 0x10) = iVar3;
                    }
                    iVar19 = iVar19 + 1;
                  } while (iVar19 <= iVar12);
                }
              }
              puVar16 = *(uint **)(iVar11 + 0x10);
            }
            uVar13 = uVar13 + 1;
          } while (uVar13 <= uVar14);
          uVar14 = uVar14 + 1;
          uVar9 = uVar9 + 1;
          iVar15 = iVar15 + 4;
        } while (uVar14 < puVar16[1]);
      }
    } while (puVar16[1] == 0);
    uVar14 = 0;
    uVar9 = 1;
    iVar15 = 0;
    do {
      uVar13 = 0;
      do {
        if (uVar13 < uVar14) {
          if (uVar14 < *puVar16) {
            uVar4 = puVar16[1];
            puVar17 = puVar16;
            if (uVar4 <= uVar14) {
              _memset((void *)(uVar4 * 4 + puVar16[2]),0,(uVar14 - uVar4) * 4 + 4);
              puVar16[1] = uVar9;
              puVar17 = *(uint **)(iVar11 + 0x10);
            }
            piVar6 = (int *)(iVar15 + puVar16[2]);
          }
          else {
            piVar6 = (int *)FUN_0019423c(puVar16,uVar14);
            puVar17 = *(uint **)(iVar11 + 0x10);
          }
          iVar18 = *piVar6;
          if (uVar13 < *puVar17) {
            uVar4 = puVar17[1];
            puVar16 = puVar17;
            if (uVar4 <= uVar13) {
              _memset((void *)(uVar4 * 4 + puVar17[2]),0,(uVar13 - uVar4) * 4 + 4);
              puVar17[1] = uVar13 + 1;
              puVar16 = *(uint **)(iVar11 + 0x10);
            }
            piVar6 = (int *)(uVar13 * 4 + puVar17[2]);
          }
          else {
            piVar6 = (int *)FUN_0019423c(puVar17,uVar13);
            puVar16 = *(uint **)(iVar11 + 0x10);
          }
          if (iVar18 == *piVar6) break;
        }
        if (uVar14 == uVar13) {
          if (uVar14 < *puVar16) {
            uVar4 = puVar16[1];
            if (uVar4 <= uVar14) {
              _memset((void *)(uVar4 * 4 + puVar16[2]),0,(uVar14 - uVar4) * 4 + 4);
              puVar16[1] = uVar9;
            }
            piVar6 = (int *)(iVar15 + puVar16[2]);
          }
          else {
            piVar6 = (int *)FUN_0019423c(puVar16,uVar14);
          }
          iVar18 = *piVar6;
          if (iVar18 != 0) {
            iVar12 = 0;
            if ((*(uint *)(iVar18 + 0x14) & 0x200) != 0) {
              iVar12 = FUN_00105594(iVar18,*(undefined4 *)(iVar18 + 0x84));
            }
            if (iVar12 == iVar11) {
              local_78 = DAT_001b003c;
              ((int (*)())FUN_00141090)(local_48,param_1,iVar18);
              uVar4 = 0;
              pbVar10 = (byte *)&STACKARG(0x20);
              local_74 = local_48[0];
              do {
                if (*(char *)((int)&local_74 + uVar4) != '\0') {
                  bVar2 = *pbVar10;
                  uVar20 = (uint)bVar2;
                  if (uVar20 != uVar4) {
                    ((int (*)())FUN_00141458)(param_1,iVar18,uVar4,uVar20);
                    *(byte *)((int)&local_78 + uVar4) = bVar2;
                    *(char *)((int)&local_78 + uVar20) = (char)uVar4;
                  }
                }
                uVar20 = local_6c;
                bVar1 = uVar4 != 3;
                pbVar10 = pbVar10 + 1;
                uVar4 = uVar4 + 1;
              } while (bVar1);
              if (local_6c < local_70) {
                iVar12 = local_6c * 4;
                _memset((void *)(iVar12 + local_68),0,4);
                local_6c = uVar20 + 1;
                piVar6 = (int *)(iVar12 + local_68);
              }
              else {
                piVar6 = (int *)FUN_0019423c(&local_70,local_6c);
              }
              uVar4 = local_5c;
              iVar12 = local_78;
              *piVar6 = iVar18;
              if (local_5c < local_60) {
                iVar18 = local_5c * 4;
                _memset((void *)(iVar18 + local_58),0,4);
                local_5c = uVar4 + 1;
                piVar6 = (int *)(iVar18 + local_58);
              }
              else {
                piVar6 = (int *)FUN_0019423c(&local_60,local_5c);
              }
              *piVar6 = iVar12;
              puVar16 = *(uint **)(iVar11 + 0x10);
              goto LAB_00143da4;
            }
          }
          puVar16 = *(uint **)(iVar11 + 0x10);
        }
LAB_00143da4:
        uVar13 = uVar13 + 1;
      } while (uVar13 <= uVar14);
      uVar14 = uVar14 + 1;
      uVar9 = uVar9 + 1;
      iVar15 = iVar15 + 4;
    } while (uVar14 < puVar16[1]);
  } while( true );
}

/* FUN_00143e40 @ 0x143e40 (676 bytes) */
int FUN_00143e40(param_1, param_2)
  undefined4 *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  int local_28;
  int local_24 [2];
  
  piVar5 = param_2 + 5;
  iVar1 = *param_2;
  iVar7 = param_2[1];
  if (param_2[4] != 0) {
    iVar1 = param_2[1];
    iVar7 = *param_2;
  }
  iVar2 = FUN_000e07dc(*param_1,0x30);
  if ((iVar2 == 0) ||
     ((((int (*)())FUN_00141044)(&local_28,param_1,iVar1), local_28 != 1 &&
      (((int (*)())FUN_00141044)(local_24,param_1,iVar7), local_24[0] != 1)))) {
    puVar10 = *(uint **)(iVar1 + 0x10);
    uVar3 = puVar10[1];
    if (uVar3 != 0) {
      uVar8 = 0;
      do {
        if (uVar8 < *puVar10) {
          if (uVar3 <= uVar8) {
            _memset((void *)(uVar3 * 4 + puVar10[2]),0,(uVar8 - uVar3) * 4 + 4);
            puVar10[1] = uVar8 + 1;
          }
          piVar4 = (int *)(uVar8 * 4 + puVar10[2]);
        }
        else {
          piVar4 = (int *)FUN_0019423c(puVar10,uVar8);
        }
        iVar2 = *piVar4;
        if ((iVar2 != 0) &&
           ((*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x8e ||
            (((iVar7 != iVar2 && ((*(uint *)(iVar2 + 0x14) & 0x200) != 0)) &&
             (iVar2 = FUN_00105594(iVar2,*(undefined4 *)(iVar2 + 0x84)), iVar1 == iVar2)))))) {
          puVar10 = *(uint **)(iVar7 + 0x10);
          uVar3 = puVar10[1];
          if (uVar3 != 0) {
            uVar9 = 0;
            do {
              if (uVar9 < *puVar10) {
                if (uVar3 <= uVar9) {
                  _memset((void *)(uVar3 * 4 + puVar10[2]),0,(uVar9 - uVar3) * 4 + 4);
                  puVar10[1] = uVar9 + 1;
                }
                piVar4 = (int *)(uVar9 * 4 + puVar10[2]);
              }
              else {
                piVar4 = (int *)FUN_0019423c(puVar10,uVar9);
              }
              iVar2 = *piVar4;
              if ((iVar2 != 0) &&
                 ((*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x8e ||
                  (((iVar1 != iVar2 && ((*(uint *)(iVar2 + 0x14) & 0x200) != 0)) &&
                   (iVar2 = FUN_00105594(iVar2,*(undefined4 *)(iVar2 + 0x84)), iVar7 == iVar2))))))
              goto LAB_001440cc;
              puVar10 = *(uint **)(iVar7 + 0x10);
              uVar9 = uVar9 + 1;
              uVar3 = puVar10[1];
            } while (uVar9 < uVar3);
          }
        }
        puVar10 = *(uint **)(iVar1 + 0x10);
        uVar8 = uVar8 + 1;
        uVar3 = puVar10[1];
      } while (uVar8 < uVar3);
    }
    iVar2 = 5;
    iVar7 = 0;
    iVar1 = 0;
    do {
      iVar6 = piVar5[1];
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0x24) == 0)) {
        iVar7 = iVar7 + 1;
        if (iVar1 == 0) {
          iVar6 = *(int *)(iVar6 + 0x28);
        }
        else {
          iVar6 = *(int *)(iVar6 + 0x28);
          if (iVar1 <= iVar6) goto LAB_001440b0;
        }
        iVar1 = iVar6;
      }
LAB_001440b0:
      piVar5 = piVar5 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar1 = iVar7 * -3000 + 1000 + iVar1 * 0xfa;
  }
  else {
LAB_001440cc:
    iVar1 = -1;
  }
  return iVar1;
}

/* FUN_001440e4 @ 0x1440e4 (4680 bytes) */
int FUN_001440e4(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined1 uVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  uint uVar18;
  int iVar19;
  int *piVar20;
  int *piVar21;
  int iVar22;
  undefined4 *puVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4 [4];
  undefined4 local_b4;
  undefined4 local_b0 [2];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  int local_8c;
  int local_88;
  int local_84;
  undefined *local_80;
  undefined4 *local_7c;
  undefined *local_78;
  undefined4 *local_74;
  undefined4 *local_70;
  undefined4 *local_6c;
  undefined4 *local_68;
  undefined4 *local_64;
  undefined4 *local_60;
  undefined4 *local_5c;
  
  local_6c = local_c4 + 1;
  local_68 = local_c4 + 2;
  local_64 = local_c4 + 3;
  local_60 = &local_b4;
  local_5c = &local_d4;
  iVar22 = 0;
LAB_00144144:
  puVar23 = *(undefined4 **)(param_4 + 4);
  if (puVar23 != (undefined4 *)0x0) {
    iVar24 = puVar23[9];
    local_7c = &local_d8;
    if (iVar24 == 0) {
      iVar25 = 4;
      iVar24 = 0;
      puVar11 = puVar23;
      do {
        if (puVar11[4] != 0) {
          uVar15 = 1;
          iVar24 = puVar23[iVar24 + 4];
          goto LAB_001441e0;
        }
        iVar24 = iVar24 + 1;
        puVar11 = puVar11 + 1;
        iVar25 = iVar25 + -1;
      } while (iVar25 != 0);
      uVar15 = 0;
      iVar24 = 0;
LAB_001441e0:
      iVar26 = 4;
      iVar25 = 0;
      puVar11 = puVar23;
      do {
        if ((iVar24 != puVar11[4]) && (puVar11[4] != 0)) {
          uVar15 = uVar15 + 1;
          iVar25 = puVar23[iVar25 + 4];
          goto LAB_00144214;
        }
        iVar25 = iVar25 + 1;
        puVar11 = puVar11 + 1;
        iVar26 = iVar26 + -1;
      } while (iVar26 != 0);
      iVar25 = 0;
LAB_00144214:
      iVar27 = 4;
      iVar26 = 0;
      puVar11 = puVar23;
      do {
        iVar7 = puVar11[4];
        if (((iVar24 != iVar7) && (iVar25 != iVar7)) && (iVar7 != 0)) {
          uVar18 = uVar15 + 1;
          iVar26 = puVar23[iVar26 + 4];
          bVar1 = iVar26 == 0;
          if (bVar1) goto LAB_00144258;
          uVar15 = uVar15 + 2;
          iVar27 = 4;
          piVar20 = puVar23 + 4;
          puVar11 = puVar23;
          goto LAB_001442d4;
        }
        iVar26 = iVar26 + 1;
        puVar11 = puVar11 + 1;
        iVar27 = iVar27 + -1;
      } while (iVar27 != 0);
      bVar1 = true;
      iVar26 = 0;
      local_8c = 0;
      bVar2 = bVar1;
      goto LAB_00144264;
    }
    goto LAB_0014516c;
  }
  goto LAB_001452d4;
  while( true ) {
    piVar20 = piVar20 + 1;
    puVar11 = puVar11 + 1;
    iVar27 = iVar27 + -1;
    if (iVar27 == 0) break;
LAB_001442d4:
    iVar7 = puVar11[4];
    if (((iVar24 != iVar7) && (iVar25 != iVar7)) && ((iVar7 != iVar26 && (iVar7 != 0)))) {
      local_8c = *piVar20;
      bVar2 = local_8c == 0;
      if (bVar2) goto LAB_00144264;
      uVar18 = 0;
      iVar27 = 4;
      piVar20 = puVar23 + 4;
      pbVar10 = (byte *)(puVar23 + 8);
      goto LAB_00144334;
    }
  }
LAB_00144258:
  local_8c = 0;
  uVar15 = uVar18;
  bVar2 = true;
  goto LAB_00144264;
  while( true ) {
    uVar18 = uVar18 + 1;
    piVar20 = piVar20 + 1;
    iVar27 = iVar27 + -1;
    if (iVar27 == 0) break;
LAB_00144334:
    bVar3 = *pbVar10;
    pbVar10 = pbVar10 + 1;
    if (uVar18 == bVar3) {
      iVar27 = *piVar20;
      if (iVar27 != local_8c) {
        if (iVar27 == iVar26) {
          bVar1 = local_8c == 0;
          iVar7 = iVar25;
          iVar26 = local_8c;
        }
        else {
          iVar7 = local_8c;
          if ((iVar25 != iVar27) && (iVar7 = iVar25, iVar24 == iVar27)) {
            iVar24 = local_8c;
          }
        }
        iVar25 = iVar7;
        bVar2 = iVar27 == 0;
        local_8c = iVar27;
      }
      break;
    }
  }
LAB_00144264:
  iVar27 = *(int *)(iVar24 + 8);
  piVar20 = *(int **)(iVar27 + 0x158);
  iVar7 = FUN_00104800(iVar27,iVar25);
  if (iVar7 != 0) {
    iVar27 = *(int *)(iVar25 + 8);
    piVar20 = *(int **)(iVar27 + 0x158);
  }
  if (!bVar1) {
    iVar7 = FUN_00104800(iVar27,iVar26);
    if (iVar7 != 0) {
      iVar27 = *(int *)(iVar26 + 8);
      piVar20 = *(int **)(iVar27 + 0x158);
    }
    if ((!bVar2) && (iVar7 = FUN_00104800(iVar27,local_8c), iVar7 != 0)) {
      iVar27 = *(int *)(local_8c + 8);
      piVar20 = *(int **)(iVar27 + 0x158);
    }
  }
  FUN_00104800(iVar24,iVar27);
  FUN_00104800(iVar25,iVar27);
  if (!bVar1) {
    FUN_00104800(iVar26,iVar27);
  }
  if (!bVar2) {
    FUN_00104800(local_8c,iVar27);
  }
  iVar7 = *(int *)(*(int *)(iVar27 + 0x88) + 8);
  while (iVar7 == 0x8e) {
    iVar27 = *(int *)(iVar27 + 8);
    iVar7 = *(int *)(*(int *)(iVar27 + 0x88) + 8);
  }
  iVar7 = (**(code **)(*piVar20 + 0x1c))(piVar20);
  if (iVar7 != 0) {
    puVar11 = (undefined4 *)0x0;
    if (*(int *)(piVar20[0x34] + 4) != 0) {
      puVar11 = *(undefined4 **)(piVar20[0x34] + 8);
    }
    piVar20 = (int *)*puVar11;
    iVar27 = FUN_000e83bc(piVar20);
  }
  iVar7 = (**(code **)(*piVar20 + 0x2c))(piVar20);
  piVar21 = piVar20;
  if (iVar7 != 0) {
    puVar11 = (undefined4 *)0x0;
    if (*(int *)(piVar20[0x34] + 4) != 0) {
      puVar11 = *(undefined4 **)(piVar20[0x34] + 8);
    }
    piVar21 = (int *)*puVar11;
    iVar27 = FUN_000e78f8(piVar21,piVar20[0x54]);
    if (iVar27 == 0) {
      puVar11 = (undefined4 *)0x0;
      if (1 < *(uint *)(piVar20[0x34] + 4)) {
        puVar11 = (undefined4 *)(*(int *)(piVar20[0x34] + 8) + 4);
      }
      piVar21 = (int *)*puVar11;
    }
    iVar27 = FUN_000e83bc(piVar21);
  }
  uVar5 = DAT_001b0044;
  iVar7 = piVar21[0x2b];
  uVar17 = *(undefined4 *)(iVar7 + 8);
  if (uVar15 == 2) {
    iVar26 = 0;
    local_c4[0] = DAT_001b0038;
    local_c8 = DAT_001b0038;
    local_78 = &DAT_001b40f0;
    iVar13 = 4;
    local_80 = &DAT_001b40f0;
    local_d4 = DAT_001b0044;
    local_7c = &local_d8;
    puVar11 = puVar23;
    do {
      if (iVar24 == puVar11[4]) {
        *(undefined1 *)((int)&local_d4 + (uint)*(byte *)((int)puVar23 + iVar26 + 0x20)) = 0;
        bVar3 = *(byte *)((int)puVar23 + iVar26 + 0x20);
        *(byte *)((int)&local_c8 + (uint)bVar3) = bVar3;
      }
      iVar26 = iVar26 + 1;
      puVar11 = puVar11 + 1;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    iVar26 = 0;
    iVar13 = 4;
    do {
      if (*(char *)((int)&local_d4 + iVar26) == '\x01') {
        *(char *)((int)local_c4 + iVar26) = (char)iVar26;
        *(undefined1 *)((int)&local_d4 + iVar26) = 0;
        break;
      }
      iVar26 = iVar26 + 1;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    iVar24 = ((int (*)())FUN_0010bed0)((double)FLOAT_001aa0d4,2,uVar5,iVar24,iVar7,uVar17);
    *(undefined4 *)(iVar24 + 0x160) = *(undefined4 *)(iVar7 + 0x478);
    iVar26 = FUN_001054ec(iVar24,0);
    FUN_000f3908(&local_a8,*(undefined4 *)(iVar26 + 0x10));
    uVar5 = local_c8;
    *(undefined4 *)(iVar24 + 0xc) = local_a8;
    iVar26 = FUN_001054ec(iVar24,1);
    uVar6 = local_c4[0];
    *(undefined4 *)(iVar26 + 0x10) = uVar5;
    iVar26 = FUN_001054ec(iVar24,2);
    iVar13 = 0;
    local_c4[0] = *(undefined4 *)(local_78 + -0x40ac);
    local_d4 = *(undefined4 *)(local_80 + -0x40b8);
    *(undefined4 *)(iVar26 + 0x10) = uVar6;
    iVar26 = 4;
    puVar11 = puVar23;
    do {
      if (iVar25 == puVar11[4]) {
        *(undefined1 *)((int)local_7c + *(byte *)((int)puVar23 + iVar13 + 0x20) + 0x14) = 0;
        bVar3 = *(byte *)((int)puVar23 + iVar13 + 0x20);
        *(byte *)((int)local_7c + bVar3 + 0x10) = bVar3;
      }
      iVar13 = iVar13 + 1;
      puVar11 = puVar11 + 1;
      iVar26 = iVar26 + -1;
    } while (iVar26 != 0);
    local_70 = local_c4;
    iVar13 = 4;
    iVar26 = 0;
    do {
      if (*(char *)(iVar26 + (int)local_70) == '\x01') {
        *(char *)((int)local_7c + iVar26 + 4) = (char)iVar26;
        *(undefined1 *)((int)local_7c + iVar26 + 0x14) = 0;
        break;
      }
      iVar26 = iVar26 + 1;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    local_c8 = local_d4;
    iVar13 = ((int (*)())FUN_0010bed0)((double)FLOAT_001aa0d4,2,local_c4[0],iVar25,iVar7,uVar17);
    *(undefined4 *)(iVar13 + 0x160) = *(undefined4 *)(iVar7 + 0x478);
    iVar25 = FUN_001054ec(iVar13,0);
    FUN_000f3908(&local_a4,*(undefined4 *)(iVar25 + 0x10));
    uVar6 = local_c8;
    *(undefined4 *)(iVar13 + 0xc) = local_a4;
    iVar25 = FUN_001054ec(iVar13,1);
    uVar5 = local_d4;
    *(undefined4 *)(iVar25 + 0x10) = uVar6;
    iVar25 = FUN_001054ec(iVar13,2);
    iVar28 = 0;
    *(undefined4 *)(iVar25 + 0x10) = uVar5;
    iVar7 = FUN_001043f0(0x12,uVar17);
    *(undefined4 *)(iVar7 + 0x120) = 0;
    *(undefined4 *)(iVar7 + 0x98) = 0;
    *(undefined4 *)(iVar7 + 0x124) = 0;
    *(undefined4 *)(iVar7 + 0x94) = *(undefined4 *)(iVar7 + 0x14c);
    iVar25 = FUN_00105594(iVar24,1);
    iVar26 = FUN_001054ec(iVar24,2);
    local_d4 = *(undefined4 *)(iVar26 + 0x10);
    iVar26 = 4;
    do {
      if (*(char *)((int)&local_d4 + iVar28) != '\x04') goto LAB_0014488c;
      iVar28 = iVar28 + 1;
      iVar26 = iVar26 + -1;
    } while (iVar26 != 0);
    iVar28 = -1;
LAB_0014488c:
    iVar26 = FUN_00105594(iVar13,1);
    iVar19 = FUN_001054ec(iVar13,2);
    iVar29 = 0;
    local_c8 = *(undefined4 *)(iVar19 + 0x10);
    iVar19 = 4;
    do {
      if (*(char *)((int)&local_c8 + iVar29) != '\x04') goto LAB_001448d8;
      iVar29 = iVar29 + 1;
      iVar19 = iVar19 + -1;
    } while (iVar19 != 0);
    iVar29 = -1;
LAB_001448d8:
    iVar19 = 0;
    local_c4[0] = *(undefined4 *)(local_78 + -0x40ac);
    puVar16 = puVar23 + 8;
    local_d0 = *(undefined4 *)(local_80 + -0x40b8);
    iVar12 = 4;
    puVar11 = puVar23;
    local_cc = local_d0;
    do {
      if (iVar25 == puVar11[4]) {
        *(undefined1 *)(iVar19 + (int)local_70) = 0;
        local_74 = &local_cc;
        *(undefined1 *)((int)&local_d0 + iVar19) = *(undefined1 *)puVar16;
        *(char *)(iVar19 + (int)&local_cc) = (char)iVar29;
      }
      else if (iVar26 == puVar11[4]) {
        *(char *)((int)&local_d0 + iVar19) = (char)iVar28;
        *(undefined1 *)(iVar19 + (int)local_70) = 0;
        local_74 = &local_cc;
        *(undefined1 *)(iVar19 + (int)&local_cc) = *(undefined1 *)puVar16;
      }
      iVar19 = iVar19 + 1;
      puVar16 = (undefined4 *)((int)puVar16 + 1);
      puVar11 = puVar11 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    *(undefined4 *)(iVar7 + 0x9c) = local_c4[0];
    FUN_00106004(iVar7,1,iVar24,1,uVar17);
    FUN_00103d50(iVar7 + 0xa4,1,0);
    FUN_00103d50(iVar7 + 0xa4,2,0);
    uVar5 = local_d0;
    iVar25 = FUN_001054ec(iVar7,1);
    *(undefined4 *)(iVar25 + 0x10) = uVar5;
    FUN_00106004(iVar7,2,iVar13,1,uVar17);
    FUN_00103d50(iVar7 + 0xbc,1,0);
    FUN_00103d50(iVar7 + 0xbc,2,0);
    uVar5 = local_cc;
    iVar25 = FUN_001054ec(iVar7,2);
    *(undefined4 *)(iVar25 + 0x10) = uVar5;
    iVar25 = FUN_001054ec(iVar7,0);
    FUN_000f3908(&local_a0,*(undefined4 *)(iVar25 + 0x10));
    *(undefined4 *)(iVar7 + 0xc) = local_a0;
    FUN_000e7700(piVar21,iVar27,iVar24);
  }
  else {
    if (uVar15 < 2) {
      local_7c = &local_d8;
      goto LAB_0014514c;
    }
    local_7c = &local_d8;
    if (4 < uVar15) goto LAB_0014514c;
    local_78 = &DAT_001b40f0;
    iVar13 = 0;
    local_80 = &DAT_001b40f0;
    iVar28 = 4;
    local_c4[0] = DAT_001b0038;
    local_cc = DAT_001b0044;
    local_d0 = DAT_001b0038;
    puVar11 = puVar23;
    do {
      if (iVar24 == puVar11[4]) {
        *(undefined1 *)((int)&local_cc + (uint)*(byte *)((int)puVar23 + iVar13 + 0x20)) = 0;
        bVar3 = *(byte *)((int)puVar23 + iVar13 + 0x20);
        *(byte *)((int)&local_d0 + (uint)bVar3) = bVar3;
      }
      iVar13 = iVar13 + 1;
      puVar11 = puVar11 + 1;
      iVar28 = iVar28 + -1;
    } while (iVar28 != 0);
    local_74 = &local_cc;
    iVar28 = 4;
    iVar13 = 0;
    do {
      if (*(char *)(iVar13 + (int)local_74) == '\x01') {
        *(char *)((int)local_c4 + iVar13) = (char)iVar13;
        *(undefined1 *)((int)&local_cc + iVar13) = 0;
        break;
      }
      iVar13 = iVar13 + 1;
      iVar28 = iVar28 + -1;
    } while (iVar28 != 0);
    iVar24 = ((int (*)())FUN_0010bed0)((double)FLOAT_001aa0e8,2,uVar5,iVar24,iVar7,uVar17);
    *(undefined4 *)(iVar24 + 0x160) = *(undefined4 *)(iVar7 + 0x478);
    iVar13 = FUN_001054ec(iVar24,0);
    FUN_000f3908(&local_9c,*(undefined4 *)(iVar13 + 0x10));
    uVar5 = local_d0;
    *(undefined4 *)(iVar24 + 0xc) = local_9c;
    iVar13 = FUN_001054ec(iVar24,1);
    uVar6 = local_c4[0];
    *(undefined4 *)(iVar13 + 0x10) = uVar5;
    iVar13 = FUN_001054ec(iVar24,2);
    local_d0 = *(undefined4 *)(local_80 + -0x40b8);
    iVar28 = 0;
    local_c4[0] = *(undefined4 *)(local_78 + -0x40ac);
    *(undefined4 *)(iVar13 + 0x10) = uVar6;
    iVar13 = 4;
    puVar11 = puVar23;
    do {
      if (iVar25 == puVar11[4]) {
        *(undefined1 *)((int)local_7c + *(byte *)((int)puVar23 + iVar28 + 0x20) + 0x14) = 0;
        bVar3 = *(byte *)((int)puVar23 + iVar28 + 0x20);
        *(byte *)((int)local_7c + bVar3 + 8) = bVar3;
      }
      iVar28 = iVar28 + 1;
      puVar11 = puVar11 + 1;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    local_70 = local_c4;
    iVar28 = 4;
    iVar13 = 0;
    do {
      if (*(char *)(iVar13 + (int)local_70) == '\x01') {
        *(char *)((int)local_7c + iVar13 + 0xc) = (char)iVar13;
        *(undefined1 *)((int)local_7c + iVar13 + 0x14) = 0;
        break;
      }
      iVar13 = iVar13 + 1;
      iVar28 = iVar28 + -1;
    } while (iVar28 != 0);
    iVar13 = 0;
    iVar28 = 4;
    do {
      if (*(char *)(iVar13 + (int)local_70) == '\x01') {
        *(char *)((int)local_7c + iVar13 + 0x10) = (char)iVar13;
        *(undefined1 *)((int)local_7c + iVar13 + 0x14) = 0;
        break;
      }
      iVar13 = iVar13 + 1;
      iVar28 = iVar28 + -1;
    } while (iVar28 != 0);
    local_cc = local_d0;
    local_c8 = local_d0;
    iVar25 = ((int (*)())FUN_0010bed0)((double)FLOAT_001aa0e8,3,local_c4[0],iVar25,iVar7,uVar17);
    *(undefined4 *)(iVar25 + 0x160) = *(undefined4 *)(iVar7 + 0x478);
    iVar13 = FUN_001054ec(iVar25,0);
    FUN_000f3908(&local_98,*(undefined4 *)(iVar13 + 0x10));
    uVar5 = local_d0;
    *(undefined4 *)(iVar25 + 0xc) = local_98;
    iVar13 = FUN_001054ec(iVar25,1);
    uVar6 = local_cc;
    *(undefined4 *)(iVar13 + 0x10) = uVar5;
    iVar13 = FUN_001054ec(iVar25,2);
    uVar5 = local_c8;
    *(undefined4 *)(iVar13 + 0x10) = uVar6;
    iVar13 = FUN_001054ec(iVar25,3);
    iVar28 = 0;
    local_c8 = *(undefined4 *)(local_78 + -0x40ac);
    local_d0 = *(undefined4 *)(local_80 + -0x40b8);
    *(undefined4 *)(iVar13 + 0x10) = uVar5;
    iVar13 = 4;
    local_cc = local_d0;
    puVar11 = puVar23;
    do {
      if (iVar26 == puVar11[4]) {
        *(undefined1 *)((int)local_7c + *(byte *)((int)puVar23 + iVar28 + 0x20) + 0x10) = 0;
        bVar3 = *(byte *)((int)puVar23 + iVar28 + 0x20);
        *(byte *)((int)local_7c + bVar3 + 0xc) = bVar3;
      }
      iVar28 = iVar28 + 1;
      puVar11 = puVar11 + 1;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    iVar13 = 0;
    iVar28 = 4;
    do {
      if (*(char *)((int)&local_c8 + iVar13) == '\x01') {
        *(char *)((int)local_7c + iVar13 + 8) = (char)iVar13;
        *(undefined1 *)((int)local_7c + iVar13 + 0x10) = 0;
        break;
      }
      iVar13 = iVar13 + 1;
      iVar28 = iVar28 + -1;
    } while (iVar28 != 0);
    iVar13 = ((int (*)())FUN_0010bed0)((double)FLOAT_001aa0d4,2,local_c8,iVar26,iVar7,uVar17);
    *(undefined4 *)(iVar13 + 0x160) = *(undefined4 *)(iVar7 + 0x478);
    iVar28 = 0;
    iVar26 = FUN_001054ec(iVar13,0);
    FUN_000f3908(&local_94,*(undefined4 *)(iVar26 + 0x10));
    uVar6 = local_cc;
    *(undefined4 *)(iVar13 + 0xc) = local_94;
    iVar26 = FUN_001054ec(iVar13,1);
    uVar5 = local_d0;
    *(undefined4 *)(iVar26 + 0x10) = uVar6;
    iVar26 = FUN_001054ec(iVar13,2);
    *(undefined4 *)(iVar26 + 0x10) = uVar5;
    iVar7 = FUN_001043f0(0x14,uVar17);
    *(undefined4 *)(iVar7 + 0x120) = 0;
    *(undefined4 *)(iVar7 + 0x98) = 0;
    *(undefined4 *)(iVar7 + 0x124) = 0;
    *(undefined4 *)(iVar7 + 0x94) = *(undefined4 *)(iVar7 + 0x14c);
    local_84 = FUN_00105594(iVar24,1);
    iVar26 = FUN_001054ec(iVar24,2);
    local_d0 = *(undefined4 *)(iVar26 + 0x10);
    iVar26 = 4;
    do {
      if (*(char *)((int)&local_d0 + iVar28) != '\x04') goto LAB_00144dd8;
      iVar28 = iVar28 + 1;
      iVar26 = iVar26 + -1;
    } while (iVar26 != 0);
    iVar28 = -1;
LAB_00144dd8:
    local_88 = FUN_00105594(iVar25,1);
    iVar26 = FUN_001054ec(iVar25,2);
    local_cc = *(undefined4 *)(iVar26 + 0x10);
    iVar19 = 0;
    iVar26 = FUN_001054ec(iVar25,3);
    local_c8 = *(undefined4 *)(iVar26 + 0x10);
    iVar26 = 4;
    do {
      if (*(char *)(iVar19 + (int)local_74) != '\x04') goto LAB_00144e38;
      iVar19 = iVar19 + 1;
      iVar26 = iVar26 + -1;
    } while (iVar26 != 0);
    iVar19 = -1;
LAB_00144e38:
    iVar26 = 0;
    iVar29 = 4;
    do {
      if (*(char *)((int)&local_c8 + iVar26) != '\x04') goto LAB_00144e5c;
      iVar26 = iVar26 + 1;
      iVar29 = iVar29 + -1;
    } while (iVar29 != 0);
    iVar26 = -1;
LAB_00144e5c:
    iVar29 = FUN_00105594(iVar13,1);
    iVar12 = FUN_001054ec(iVar13,2);
    iVar14 = 0;
    local_c4[0] = *(undefined4 *)(iVar12 + 0x10);
    iVar12 = 4;
    do {
      if (*(char *)(iVar14 + (int)local_70) != '\x04') goto LAB_00144ea8;
      iVar14 = iVar14 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    iVar14 = -1;
LAB_00144ea8:
    local_d4 = *(undefined4 *)(local_80 + -0x40b8);
    puVar16 = puVar23 + 8;
    local_c4[1] = *(undefined4 *)(local_78 + -0x40ac);
    iVar30 = 4;
    iVar12 = 0;
    puVar11 = puVar23;
    do {
      iVar8 = puVar11[4];
      if (local_84 == iVar8) {
        *(undefined1 *)(iVar12 + (int)local_6c) = 0;
        uVar9 = *(undefined1 *)puVar16;
        *(char *)(iVar12 + (int)local_64) = (char)iVar19;
        *(undefined1 *)(iVar12 + (int)local_68) = uVar9;
        *(char *)(iVar12 + (int)local_60) = (char)iVar14;
      }
      else if (local_88 == iVar8) {
        *(undefined1 *)(iVar12 + (int)local_6c) = 0;
        *(char *)(iVar12 + (int)local_68) = (char)iVar28;
        uVar9 = *(undefined1 *)puVar16;
        *(char *)(iVar12 + (int)local_60) = (char)iVar14;
        *(undefined1 *)(iVar12 + (int)local_64) = uVar9;
      }
      else if (iVar29 == iVar8) {
        *(undefined1 *)(iVar12 + (int)local_6c) = 0;
        *(char *)(iVar12 + (int)local_68) = (char)iVar28;
        *(char *)(iVar12 + (int)local_64) = (char)iVar26;
        *(undefined1 *)(iVar12 + (int)local_60) = *(undefined1 *)puVar16;
      }
      else if ((!bVar2) && (local_8c == iVar8)) {
        *(char *)(iVar12 + (int)local_5c) = (char)iVar12;
      }
      iVar12 = iVar12 + 1;
      puVar16 = (undefined4 *)((int)puVar16 + 1);
      puVar11 = puVar11 + 1;
      iVar30 = iVar30 + -1;
    } while (iVar30 != 0);
    *(undefined4 *)(iVar7 + 0x9c) = local_c4[1];
    local_c4[2] = local_d4;
    local_c4[3] = local_d4;
    local_b4 = local_d4;
    FUN_00106004(iVar7,1,iVar24,1,uVar17);
    FUN_00103d50(iVar7 + 0xa4,1,0);
    FUN_00103d50(iVar7 + 0xa4,2,0);
    uVar5 = local_c4[2];
    iVar26 = FUN_001054ec(iVar7,1);
    *(undefined4 *)(iVar26 + 0x10) = uVar5;
    FUN_00106004(iVar7,2,iVar25,1,uVar17);
    FUN_00103d50(iVar7 + 0xbc,1,0);
    FUN_00103d50(iVar7 + 0xbc,2,0);
    uVar5 = local_c4[3];
    iVar26 = FUN_001054ec(iVar7,2);
    *(undefined4 *)(iVar26 + 0x10) = uVar5;
    FUN_00106004(iVar7,3,iVar13,1,uVar17);
    FUN_00103d50(iVar7 + 0xd4,1,0);
    FUN_00103d50(iVar7 + 0xd4,2,0);
    uVar5 = local_b4;
    iVar26 = FUN_001054ec(iVar7,3);
    *(undefined4 *)(iVar26 + 0x10) = uVar5;
    if (bVar2) {
      iVar26 = FUN_001054ec(iVar7,0);
      FUN_000f3908(&local_90,*(undefined4 *)(iVar26 + 0x10));
      *(undefined4 *)(iVar7 + 0xc) = local_90;
    }
    else {
      FUN_00106804(iVar7,local_8c,1,uVar17);
      uVar17 = local_d4;
      iVar26 = FUN_001054ec(iVar7,4);
      uVar5 = DAT_001b0048;
      *(undefined4 *)(iVar26 + 0x10) = uVar17;
      *(undefined4 *)(iVar7 + 0xc) = uVar5;
    }
    FUN_000e7700(piVar21,iVar27,iVar24);
    FUN_000e7700(piVar21,iVar27,iVar25);
  }
  FUN_000e7700(piVar21,iVar27,iVar13);
  FUN_000e7700(piVar21,iVar27,iVar7);
  puVar23[9] = iVar7;
LAB_0014514c:
  iVar24 = 4;
  puVar11 = puVar23;
  do {
    *puVar11 = 1;
    puVar11 = puVar11 + 1;
    iVar24 = iVar24 + -1;
  } while (iVar24 != 0);
  iVar24 = puVar23[9];
LAB_0014516c:
  iVar25 = FUN_001054ec(param_2,iVar22);
  iVar26 = 0;
  local_b0[0] = *(undefined4 *)(iVar25 + 0x10);
  do {
    cVar4 = *(char *)((int)local_b0 + iVar26);
    if (cVar4 != '\x04') {
      iVar25 = FUN_00105594(param_2,iVar22);
      iVar7 = 4;
      iVar27 = 0;
      puVar11 = puVar23;
      do {
        if ((iVar25 == puVar11[4]) && (cVar4 == *(char *)((int)puVar23 + iVar27 + 0x20))) {
          uVar9 = (undefined1)iVar27;
          goto LAB_001451cc;
        }
        iVar27 = iVar27 + 1;
        puVar11 = puVar11 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      uVar9 = 0xff;
LAB_001451cc:
      *(undefined1 *)((int)local_b0 + iVar26) = uVar9;
    }
    uVar5 = local_b0[0];
    bVar1 = iVar26 != 3;
    iVar26 = iVar26 + 1;
  } while (bVar1);
  iVar25 = FUN_001054ec(param_2,iVar22);
  *(undefined4 *)(iVar25 + 0x10) = uVar5;
  if ((*(int *)(param_2 + 0x84) == iVar22) && ((*(uint *)(param_2 + 0x14) & 0x200) != 0)) {
    FUN_00106804(param_2,iVar24,1,*param_1);
  }
  else {
    FUN_00106004(param_2,iVar22,iVar24,1,*param_1);
  }
  iVar25 = FUN_001054ec(param_3,iVar22);
  iVar26 = 0;
  local_d8 = *(undefined4 *)(iVar25 + 0x10);
  do {
    cVar4 = *(char *)(iVar26 + (int)local_7c);
    if (cVar4 != '\x04') {
      iVar25 = FUN_00105594(param_3,iVar22);
      iVar7 = 4;
      iVar27 = 0;
      puVar11 = puVar23;
      do {
        if ((iVar25 == puVar11[4]) && (cVar4 == *(char *)((int)puVar23 + iVar27 + 0x20))) {
          uVar9 = (undefined1)iVar27;
          goto LAB_00145280;
        }
        iVar27 = iVar27 + 1;
        puVar11 = puVar11 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      uVar9 = 0xff;
LAB_00145280:
      *(undefined1 *)(iVar26 + (int)local_7c) = uVar9;
    }
    uVar5 = local_d8;
    bVar1 = iVar26 != 3;
    iVar26 = iVar26 + 1;
  } while (bVar1);
  iVar25 = FUN_001054ec(param_3,iVar22);
  *(undefined4 *)(iVar25 + 0x10) = uVar5;
  if ((*(int *)(param_3 + 0x84) == iVar22) && ((*(uint *)(param_3 + 0x14) & 0x200) != 0)) {
    FUN_00106804(param_3,iVar24,1,*param_1);
  }
  else {
    FUN_00106004(param_3,iVar22,iVar24,1,*param_1);
  }
LAB_001452d4:
  bVar1 = iVar22 == 4;
  param_4 = param_4 + 4;
  iVar22 = iVar22 + 1;
  if (bVar1) {
    return;
  }
  goto LAB_00144144;
}

/* FUN_0014532c @ 0x14532c (836 bytes) */
int FUN_0014532c(param_1, param_2)
  undefined4 *param_1;
  int *param_2;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  
  iVar5 = param_2[3];
  iVar6 = param_2[2];
  iVar10 = param_2[1];
  iVar11 = *param_2;
  if (param_2[4] != 0) {
    iVar5 = param_2[2];
    iVar6 = param_2[3];
    iVar10 = *param_2;
    iVar11 = param_2[1];
  }
  param_1[2] = param_1[2] + 1;
  if (0 < param_2[5]) {
    ((int (*)())FUN_001440e4)(param_1,iVar11,iVar10,param_2 + 5);
  }
  iVar8 = 0;
  if ((*(uint *)(iVar11 + 0x14) & 0x200) != 0) {
    iVar8 = FUN_00105594(iVar11,*(undefined4 *)(iVar11 + 0x84));
  }
  if (iVar10 == iVar8) {
    uVar4 = *param_1;
    iVar8 = FUN_00105594(iVar11,*(undefined4 *)(iVar11 + 0x84));
    puVar9 = *(uint **)(iVar8 + 0x10);
    uVar1 = puVar9[1];
    if (0 < (int)uVar1) {
      uVar7 = 0;
      do {
        if (uVar7 < *puVar9) {
          if (uVar1 <= uVar7) {
            _memset((void *)(uVar1 * 4 + puVar9[2]),0,(uVar7 - uVar1) * 4 + 4);
            puVar9[1] = uVar7 + 1;
          }
          piVar2 = (int *)(uVar7 * 4 + puVar9[2]);
        }
        else {
          piVar2 = (int *)FUN_0019423c(puVar9,uVar7);
        }
        if (iVar11 == *piVar2) {
          FUN_00194208(puVar9,uVar7);
          iVar8 = FUN_00105594(iVar11,*(undefined4 *)(iVar11 + 0x84));
          *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + -1;
          break;
        }
        uVar1 = puVar9[1];
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < (int)uVar1);
    }
    iVar8 = 0;
    FUN_00106004(iVar11,*(undefined4 *)(iVar11 + 0x84),0,1,uVar4);
    *(int *)(iVar11 + 0x84) = *(int *)(iVar11 + 0x84) + -1;
    *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) & 0xfffffdff;
  }
  iVar3 = 0;
  if ((*(uint *)(iVar10 + 0x14) & 0x200) != 0) {
    iVar3 = FUN_00105594(iVar10,*(undefined4 *)(iVar10 + 0x84));
  }
  if (iVar11 == iVar3) {
    uVar4 = *param_1;
    iVar8 = FUN_00105594(iVar10,*(undefined4 *)(iVar10 + 0x84));
    puVar9 = *(uint **)(iVar8 + 0x10);
    uVar1 = puVar9[1];
    if (0 < (int)uVar1) {
      uVar7 = 0;
      do {
        if (uVar7 < *puVar9) {
          if (uVar1 <= uVar7) {
            _memset((void *)(uVar1 * 4 + puVar9[2]),0,(uVar7 - uVar1) * 4 + 4);
            puVar9[1] = uVar7 + 1;
          }
          piVar2 = (int *)(uVar7 * 4 + puVar9[2]);
        }
        else {
          piVar2 = (int *)FUN_0019423c(puVar9,uVar7);
        }
        if (iVar10 == *piVar2) {
          FUN_00194208(puVar9,uVar7);
          iVar8 = FUN_00105594(iVar10,*(undefined4 *)(iVar10 + 0x84));
          *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + -1;
          break;
        }
        uVar1 = puVar9[1];
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < (int)uVar1);
    }
    FUN_00106004(iVar10,*(undefined4 *)(iVar10 + 0x84),0,1,uVar4);
    *(int *)(iVar10 + 0x84) = *(int *)(iVar10 + 0x84) + -1;
    *(uint *)(iVar10 + 0x14) = *(uint *)(iVar10 + 0x14) & 0xfffffdff;
  }
  else if ((iVar3 != 0) && (iVar8 != iVar3)) {
    FUN_00106804(iVar11,iVar3,1,*param_1);
    FUN_001054ec(iVar11,*(undefined4 *)(iVar11 + 0x84));
  }
  ((int (*)())FUN_0014375c)(param_1,iVar11,iVar6);
  ((int (*)())FUN_0014375c)(param_1,iVar10,iVar5);
  ((int (*)())FUN_001411dc)(param_1,iVar11,iVar11,iVar6);
  ((int (*)())FUN_001411dc)(param_1,iVar11,iVar10,iVar5);
  ((int (*)())FUN_001415a4)(param_1,iVar10,iVar11);
  return;
}

/* FUN_00145670 @ 0x145670 (3828 bytes) */
int FUN_00145670(param_1)
  int *param_1;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  void *pvVar9;
  void *pvVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  int *piVar24;
  int iVar25;
  undefined4 local_68;
  undefined4 local_64 [3];
  undefined4 local_58;
  int local_54;
  
  iVar7 = *(int *)(param_1[1] + 900);
  for (iVar6 = *(int *)(*(int *)(param_1[1] + 900) + 8); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
    iVar2 = *(int *)(*(int *)(iVar7 + 0x98) + 8);
    iVar20 = *(int *)(iVar7 + 0x98);
    if (iVar2 != 0) {
      do {
        iVar6 = iVar2;
        if ((*(uint *)(iVar20 + 0x14) & 1) != 0) {
          ((int (*)())FUN_00141044)(&local_58,param_1,iVar20);
          local_68 = local_58;
          if ((*(uint *)(iVar20 + 0x14) & 0x200) != 0) {
            iVar6 = FUN_001054ec(iVar20,*(undefined4 *)(iVar20 + 0x84));
            uVar3 = 0;
            local_64[0] = *(undefined4 *)(iVar6 + 0x10);
            iVar6 = 4;
            do {
              if (*(byte *)((int)local_64 + uVar3) == uVar3) {
                *(undefined1 *)((int)local_64 + (uVar3 - 4)) = 1;
              }
              uVar3 = uVar3 + 1;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
          iVar6 = *(int *)(iVar20 + 8);
          *(undefined4 *)(iVar20 + 0xc) = local_68;
        }
        iVar2 = *(int *)(iVar6 + 8);
        iVar20 = iVar6;
      } while (*(int *)(iVar6 + 8) != 0);
      iVar6 = *(int *)(iVar7 + 8);
    }
    iVar7 = iVar6;
  }
  uVar11 = *(undefined4 *)(*param_1 + 0x378);
  iVar7 = FUN_00193e18(uVar11,0x2c0);
  iVar2 = param_1[1];
  iVar6 = *(int *)(*(int *)(iVar2 + 900) + 8);
  if (iVar6 != 0) {
    uVar12 = 0;
    iVar20 = 0;
    uVar3 = 0x10;
    uVar13 = 0;
    iVar2 = *(int *)(iVar2 + 900);
    do {
      iVar5 = iVar6;
      iVar6 = *(int *)(*(int *)(iVar2 + 0x98) + 8);
      iVar23 = *(int *)(iVar2 + 0x98);
      if (iVar6 != 0) {
        do {
          iVar5 = iVar6;
          if ((*(uint *)(iVar23 + 0x14) & 1) != 0) {
            iVar6 = FUN_0011379c(*(undefined4 *)(param_1[1] + 8),iVar23);
            if (iVar6 != 0) {
              bVar1 = true;
              iVar6 = *(int *)(param_1[1] + 900);
              for (iVar5 = *(int *)(*(int *)(param_1[1] + 900) + 8); iVar5 != 0;
                  iVar5 = *(int *)(iVar5 + 8)) {
                iVar16 = *(int *)(*(int *)(iVar6 + 0x98) + 8);
                if (iVar16 != 0) {
                  iVar25 = uVar12 * 0x2c;
                  iVar5 = *(int *)(iVar6 + 0x98);
                  do {
                    iVar4 = iVar16;
                    if ((*(uint *)(iVar5 + 0x14) & 1) != 0) {
                      if (bVar1) {
                        iVar4 = *(int *)(iVar23 + 8);
                        bVar1 = false;
                        iVar6 = iVar2;
                      }
                      else {
                        iVar16 = FUN_0011379c(*(undefined4 *)(param_1[1] + 8),iVar5);
                        if (iVar16 == 0) {
                          iVar4 = *(int *)(iVar5 + 8);
                        }
                        else {
                          bVar1 = 0x3ff < iVar20;
                          iVar20 = iVar20 + 1;
                          if (bVar1) goto LAB_00146530;
                          uVar15 = uVar13;
                          iVar16 = iVar7;
                          if ((uVar13 <= uVar12) && (uVar15 = uVar12 + 1, uVar3 < uVar15)) {
                            uVar3 = (uVar3 << 4) / 10;
                            if (uVar3 < uVar15) {
                              uVar3 = uVar15;
                            }
                            iVar16 = FUN_00193e18(uVar11,uVar3 * 0x2c);
                            if (uVar13 != 0) {
                              uVar21 = 0;
                              iVar4 = 0;
                              do {
                                uVar21 = uVar21 + 1;
                                _memcpy((void *)(iVar16 + iVar4),(void *)(iVar7 + iVar4),0x2c);
                                iVar4 = iVar4 + 0x2c;
                              } while (uVar13 != uVar21);
                            }
                            FUN_00193cc0(uVar11,iVar7);
                          }
                          iVar4 = ((int (*)())FUN_001436b4)(param_1,iVar23,iVar5,iVar16 + iVar25);
                          uVar13 = uVar15;
                          iVar7 = iVar16;
                          if (iVar4 == 0) {
                            iVar4 = *(int *)(iVar5 + 8);
                            bVar1 = false;
                          }
                          else {
                            iVar4 = *(int *)(iVar5 + 8);
                            uVar12 = uVar12 + 1;
                            iVar25 = iVar25 + 0x2c;
                            bVar1 = false;
                          }
                        }
                      }
                    }
                    iVar16 = *(int *)(iVar4 + 8);
                    iVar5 = iVar4;
                  } while (*(int *)(iVar4 + 8) != 0);
                  iVar5 = *(int *)(iVar6 + 8);
                }
                iVar6 = iVar5;
              }
            }
            iVar5 = *(int *)(iVar23 + 8);
          }
          iVar6 = *(int *)(iVar5 + 8);
          iVar23 = iVar5;
        } while (*(int *)(iVar5 + 8) != 0);
        iVar5 = *(int *)(iVar2 + 8);
      }
      iVar6 = *(int *)(iVar5 + 8);
      iVar2 = iVar5;
    } while (*(int *)(iVar5 + 8) != 0);
LAB_00146530:
    do {
      if ((int)uVar12 < 1) goto LAB_00146538;
      uVar15 = 0xffffffff;
      iVar2 = 0;
      iVar20 = 0;
      uVar21 = 0;
      iVar6 = iVar7;
      do {
        uVar18 = uVar13;
        iVar7 = iVar6;
        if ((uVar13 <= uVar21) && (uVar18 = uVar21 + 1, uVar3 < uVar18)) {
          uVar3 = (uVar3 << 4) / 10;
          if (uVar3 < uVar18) {
            uVar3 = uVar18;
          }
          iVar7 = FUN_00193e18(uVar11,uVar3 * 0x2c);
          if (uVar13 != 0) {
            uVar22 = 0;
            iVar23 = 0;
            do {
              uVar22 = uVar22 + 1;
              _memcpy((void *)(iVar7 + iVar23),(void *)(iVar6 + iVar23),0x2c);
              iVar23 = iVar23 + 0x2c;
            } while (uVar13 != uVar22);
          }
          FUN_00193cc0(uVar11,iVar6);
        }
        iVar6 = ((int (*)())FUN_00143e40)(param_1,iVar7 + iVar20);
        if ((uVar15 == 0xffffffff) || (iVar2 < iVar6)) {
          uVar15 = uVar21;
          iVar2 = iVar6;
        }
        uVar21 = uVar21 + 1;
        iVar20 = iVar20 + 0x2c;
      } while (((int)uVar21 < (int)uVar12) && (uVar13 = uVar18, iVar6 = iVar7, uVar21 != 0x80));
      if ((uVar15 == 0xffffffff) || (iVar2 < 0)) goto LAB_00146538;
      uVar13 = uVar18;
      if ((uVar18 <= uVar15) && (uVar13 = uVar15 + 1, uVar3 < uVar13)) {
        uVar3 = (uVar3 << 4) / 10;
        if (uVar3 < uVar13) {
          uVar3 = uVar13;
        }
        iVar6 = FUN_00193e18(uVar11,uVar3 * 0x2c);
        if (uVar18 != 0) {
          uVar21 = 0;
          iVar2 = 0;
          do {
            uVar21 = uVar21 + 1;
            _memcpy((void *)(iVar6 + iVar2),(void *)(iVar7 + iVar2),0x2c);
            iVar2 = iVar2 + 0x2c;
          } while (uVar21 != uVar18);
        }
        FUN_00193cc0(uVar11,iVar7);
        iVar7 = iVar6;
      }
      iVar6 = uVar15 * 0x2c;
      piVar14 = (int *)(iVar7 + iVar6);
      ((int (*)())FUN_0014532c)(param_1,piVar14);
      if (0x17 < param_1[2]) goto LAB_00146538;
      piVar24 = param_1 + 3;
      uVar21 = 0;
      uVar18 = param_1[4];
      if (uVar18 != 0) {
        uVar17 = 0;
        uVar22 = uVar18;
        uVar19 = uVar21;
        while( true ) {
          if (uVar22 <= uVar17) {
            uVar21 = uVar17 + 1;
            if ((uint)param_1[5] < uVar21) {
              uVar22 = (uint)(param_1[5] << 4) / 10;
              param_1[5] = uVar22;
              if (uVar22 < uVar21) {
                param_1[5] = uVar21;
              }
              iVar20 = param_1[6];
              iVar2 = FUN_00193e18(*piVar24,param_1[5] * 0x2c);
              param_1[6] = iVar2;
              if (param_1[4] != 0) {
                uVar22 = 0;
                iVar2 = 0;
                do {
                  pvVar9 = (void *)(iVar20 + iVar2);
                  uVar22 = uVar22 + 1;
                  pvVar8 = (void *)(param_1[6] + iVar2);
                  iVar2 = iVar2 + 0x2c;
                  _memcpy(pvVar8,pvVar9,0x2c);
                } while (uVar22 < (uint)param_1[4]);
              }
              FUN_00193cc0(*piVar24,iVar20);
            }
            param_1[4] = uVar21;
          }
          iVar2 = param_1[6];
          pvVar8 = (void *)(uVar17 * 0x2c + iVar2);
          uVar21 = uVar19;
          if ((*(int *)((int)pvVar8 + 0x24) != 0) && (uVar21 = uVar19 + 1, uVar19 < uVar17)) {
            if ((uint)param_1[4] <= uVar19) {
              if ((uint)param_1[5] < uVar21) {
                uVar22 = (uint)(param_1[5] << 4) / 10;
                param_1[5] = uVar22;
                if (uVar22 < uVar21) {
                  param_1[5] = uVar21;
                }
                iVar20 = FUN_00193e18(*piVar24,param_1[5] * 0x2c);
                param_1[6] = iVar20;
                if (param_1[4] != 0) {
                  uVar22 = 0;
                  iVar20 = 0;
                  do {
                    pvVar10 = (void *)(iVar2 + iVar20);
                    uVar22 = uVar22 + 1;
                    pvVar9 = (void *)(param_1[6] + iVar20);
                    iVar20 = iVar20 + 0x2c;
                    _memcpy(pvVar9,pvVar10,0x2c);
                  } while (uVar22 < (uint)param_1[4]);
                }
                FUN_00193cc0(*piVar24,iVar2);
                iVar2 = param_1[6];
              }
              param_1[4] = uVar21;
            }
            _memcpy((void *)(uVar19 * 0x2c + iVar2),pvVar8,0x2c);
          }
          uVar17 = uVar17 + 1;
          if (uVar18 == uVar17) break;
          uVar22 = param_1[4];
          uVar19 = uVar21;
        }
      }
      if ((uint)param_1[5] < uVar21) {
        uVar18 = (uint)(param_1[5] << 4) / 10;
        param_1[5] = uVar18;
        if (uVar18 < uVar21) {
          param_1[5] = uVar21;
        }
        iVar20 = param_1[6];
        iVar2 = FUN_00193e18(*piVar24,param_1[5] * 0x2c);
        param_1[6] = iVar2;
        if (param_1[4] != 0) {
          uVar18 = 0;
          iVar2 = 0;
          do {
            pvVar9 = (void *)(iVar20 + iVar2);
            uVar18 = uVar18 + 1;
            pvVar8 = (void *)(param_1[6] + iVar2);
            iVar2 = iVar2 + 0x2c;
            _memcpy(pvVar8,pvVar9,0x2c);
          } while (uVar18 < (uint)param_1[4]);
        }
        FUN_00193cc0(*piVar24,iVar20);
      }
      param_1[4] = uVar21;
      if (uVar21 != 0) {
        uVar18 = 0;
        do {
          uVar22 = uVar18 + 1;
          if ((uint)param_1[4] <= uVar18) {
            if ((uint)param_1[5] < uVar22) {
              uVar19 = (uint)(param_1[5] << 4) / 10;
              param_1[5] = uVar19;
              if (uVar19 < uVar22) {
                param_1[5] = uVar22;
              }
              iVar20 = param_1[6];
              iVar2 = FUN_00193e18(*piVar24,param_1[5] * 0x2c);
              param_1[6] = iVar2;
              if (param_1[4] != 0) {
                uVar19 = 0;
                iVar2 = 0;
                do {
                  pvVar9 = (void *)(iVar20 + iVar2);
                  uVar19 = uVar19 + 1;
                  pvVar8 = (void *)(param_1[6] + iVar2);
                  iVar2 = iVar2 + 0x2c;
                  _memcpy(pvVar8,pvVar9,0x2c);
                } while (uVar19 < (uint)param_1[4]);
              }
              FUN_00193cc0(*piVar24,iVar20);
            }
            param_1[4] = uVar22;
          }
          *(undefined4 *)(uVar18 * 0x2c + param_1[6] + 0x28) = 0;
          uVar18 = uVar22;
        } while (uVar22 < uVar21);
      }
      uVar21 = uVar13;
      iVar2 = iVar7;
      if ((uVar13 <= uVar15) && (uVar21 = uVar15 + 1, uVar3 < uVar21)) {
        uVar3 = (uVar3 << 4) / 10;
        if (uVar3 < uVar21) {
          uVar3 = uVar21;
        }
        iVar2 = FUN_00193e18(uVar11,uVar3 * 0x2c);
        if (uVar13 != 0) {
          uVar18 = 0;
          iVar20 = 0;
          do {
            uVar18 = uVar18 + 1;
            _memcpy((void *)(iVar2 + iVar20),(void *)(iVar7 + iVar20),0x2c);
            iVar20 = iVar20 + 0x2c;
          } while (uVar18 != uVar13);
        }
        FUN_00193cc0(uVar11,iVar7);
        piVar14 = (int *)(iVar2 + iVar6);
      }
      local_54 = *piVar14;
      uVar13 = uVar21;
      iVar7 = iVar2;
      if ((uVar21 <= uVar15) && (uVar13 = uVar15 + 1, uVar3 < uVar13)) {
        uVar3 = (uVar3 << 4) / 10;
        if (uVar3 < uVar13) {
          uVar3 = uVar13;
        }
        iVar7 = FUN_00193e18(uVar11,uVar3 * 0x2c);
        if (uVar21 != 0) {
          uVar18 = 0;
          iVar20 = 0;
          do {
            uVar18 = uVar18 + 1;
            _memcpy((void *)(iVar7 + iVar20),(void *)(iVar2 + iVar20),0x2c);
            iVar20 = iVar20 + 0x2c;
          } while (uVar18 != uVar21);
        }
        FUN_00193cc0(uVar11,iVar2);
        piVar14 = (int *)(iVar7 + iVar6);
      }
      iVar20 = piVar14[1];
      uVar21 = uVar13;
      iVar2 = iVar7;
      if ((uVar13 <= uVar15) && (uVar21 = uVar15 + 1, uVar3 < uVar21)) {
        uVar3 = (uVar3 << 4) / 10;
        if (uVar3 < uVar21) {
          uVar3 = uVar21;
        }
        iVar2 = FUN_00193e18(uVar11,uVar3 * 0x2c);
        if (uVar13 != 0) {
          uVar18 = 0;
          iVar23 = 0;
          do {
            uVar18 = uVar18 + 1;
            _memcpy((void *)(iVar23 + iVar2),(void *)(iVar23 + iVar7),0x2c);
            iVar23 = iVar23 + 0x2c;
          } while (uVar18 != uVar13);
        }
        FUN_00193cc0(uVar11,iVar7);
        piVar14 = (int *)(iVar2 + iVar6);
      }
      if (piVar14[4] != 0) {
        uVar13 = uVar21;
        iVar7 = iVar2;
        if ((uVar21 <= uVar15) && (uVar13 = uVar15 + 1, uVar3 < uVar13)) {
          uVar3 = (uVar3 << 4) / 10;
          if (uVar3 < uVar13) {
            uVar3 = uVar13;
          }
          iVar7 = FUN_00193e18(uVar11,uVar3 * 0x2c);
          if (uVar21 != 0) {
            uVar18 = 0;
            iVar20 = 0;
            do {
              uVar18 = uVar18 + 1;
              _memcpy((void *)(iVar20 + iVar7),(void *)(iVar20 + iVar2),0x2c);
              iVar20 = iVar20 + 0x2c;
            } while (uVar18 != uVar21);
          }
          FUN_00193cc0(uVar11,iVar2);
          piVar14 = (int *)(iVar7 + iVar6);
        }
        local_54 = piVar14[1];
        uVar21 = uVar13;
        iVar2 = iVar7;
        if ((uVar13 <= uVar15) && (uVar21 = uVar15 + 1, uVar3 < uVar21)) {
          uVar3 = (uVar3 << 4) / 10;
          if (uVar3 < uVar21) {
            uVar3 = uVar21;
          }
          iVar2 = FUN_00193e18(uVar11,uVar3 * 0x2c);
          if (uVar13 != 0) {
            uVar18 = 0;
            iVar20 = 0;
            do {
              uVar18 = uVar18 + 1;
              _memcpy((void *)(iVar20 + iVar2),(void *)(iVar20 + iVar7),0x2c);
              iVar20 = iVar20 + 0x2c;
            } while (uVar18 != uVar13);
          }
          FUN_00193cc0(uVar11,iVar7);
          piVar14 = (int *)(iVar2 + iVar6);
        }
        iVar20 = *piVar14;
      }
      uVar18 = uVar21;
      iVar23 = iVar2;
      if ((uVar21 <= uVar15) && (uVar18 = uVar15 + 1, uVar3 < uVar18)) {
        uVar3 = (uVar3 << 4) / 10;
        if (uVar3 < uVar18) {
          uVar3 = uVar18;
        }
        iVar23 = FUN_00193e18(uVar11,uVar3 * 0x2c);
        if (uVar21 != 0) {
          uVar13 = 0;
          iVar7 = 0;
          do {
            uVar13 = uVar13 + 1;
            _memcpy((void *)(iVar7 + iVar23),(void *)(iVar7 + iVar2),0x2c);
            iVar7 = iVar7 + 0x2c;
          } while (uVar13 != uVar21);
        }
        FUN_00193cc0(uVar11,iVar2);
        piVar14 = (int *)(iVar23 + iVar6);
      }
      uVar15 = uVar12 - 1;
      uVar13 = uVar18;
      iVar7 = iVar23;
      if ((uVar18 <= uVar15) && (uVar13 = uVar12, uVar3 < uVar12)) {
        uVar3 = (uVar3 << 4) / 10;
        if (uVar3 < uVar12) {
          uVar3 = uVar12;
        }
        iVar7 = FUN_00193e18(uVar11,uVar3 * 0x2c);
        if (uVar18 != 0) {
          uVar12 = 0;
          iVar6 = 0;
          do {
            uVar12 = uVar12 + 1;
            _memcpy((void *)(iVar6 + iVar7),(void *)(iVar6 + iVar23),0x2c);
            iVar6 = iVar6 + 0x2c;
          } while (uVar12 != uVar18);
        }
        FUN_00193cc0(uVar11,iVar23);
      }
      iVar6 = uVar15 * 0x2c;
      _memcpy(piVar14,(void *)(iVar6 + iVar7),0x2c);
      if ((int)uVar15 < 1) goto LAB_00146538;
      uVar21 = 0;
      uVar18 = 1;
      do {
        uVar12 = uVar13;
        iVar2 = iVar7;
        if ((uVar13 <= uVar21) && (uVar12 = uVar18, uVar3 < uVar18)) {
          uVar3 = (uVar3 << 4) / 10;
          if (uVar3 < uVar18) {
            uVar3 = uVar18;
          }
          iVar2 = FUN_00193e18(uVar11,uVar3 * 0x2c);
          if (uVar13 != 0) {
            uVar22 = 0;
            iVar23 = 0;
            do {
              uVar22 = uVar22 + 1;
              _memcpy((void *)(iVar2 + iVar23),(void *)(iVar7 + iVar23),0x2c);
              iVar23 = iVar23 + 0x2c;
            } while (uVar22 != uVar13);
          }
          FUN_00193cc0(uVar11,iVar7);
        }
        iVar16 = uVar21 * 0x2c;
        pvVar8 = (void *)(iVar2 + iVar16);
        iVar5 = *(int *)(iVar2 + iVar16);
        uVar22 = uVar12;
        iVar23 = iVar2;
        if ((uVar12 <= uVar21) && (uVar22 = uVar18, uVar3 < uVar18)) {
          uVar3 = (uVar3 << 4) / 10;
          if (uVar3 < uVar18) {
            uVar3 = uVar18;
          }
          iVar23 = FUN_00193e18(uVar11,uVar3 * 0x2c);
          if (uVar12 != 0) {
            uVar13 = 0;
            iVar7 = 0;
            do {
              uVar13 = uVar13 + 1;
              _memcpy((void *)(iVar23 + iVar7),(void *)(iVar2 + iVar7),0x2c);
              iVar7 = iVar7 + 0x2c;
            } while (uVar13 != uVar12);
          }
          FUN_00193cc0(uVar11,iVar2);
          pvVar8 = (void *)(iVar23 + iVar16);
        }
        if (iVar20 == iVar5) {
          iVar5 = local_54;
        }
        iVar2 = *(int *)((int)pvVar8 + 4);
        if (iVar20 == *(int *)((int)pvVar8 + 4)) {
          iVar2 = local_54;
        }
        uVar13 = uVar22;
        iVar7 = iVar23;
        if (iVar5 == iVar2) {
LAB_001463fc:
          uVar22 = uVar21 - 1;
          uVar18 = uVar18 - 1;
          uVar19 = uVar13;
          iVar2 = iVar7;
          if ((uVar13 <= uVar21) && (uVar19 = uVar21 + 1, uVar3 < uVar19)) {
            uVar3 = (uVar3 << 4) / 10;
            if (uVar3 < uVar19) {
              uVar3 = uVar19;
            }
            iVar2 = FUN_00193e18(uVar11,uVar3 * 0x2c);
            if (uVar13 != 0) {
              uVar12 = 0;
              iVar23 = 0;
              do {
                uVar12 = uVar12 + 1;
                _memcpy((void *)(iVar2 + iVar23),(void *)(iVar7 + iVar23),0x2c);
                iVar23 = iVar23 + 0x2c;
              } while (uVar12 != uVar13);
            }
            FUN_00193cc0(uVar11,iVar7);
            pvVar8 = (void *)(iVar2 + iVar16);
          }
          uVar12 = uVar15 - 1;
          iVar6 = iVar6 + -0x2c;
          uVar13 = uVar19;
          iVar7 = iVar2;
          if ((uVar19 <= uVar12) && (uVar13 = uVar15, uVar3 < uVar15)) {
            uVar3 = (uVar3 << 4) / 10;
            if (uVar3 < uVar15) {
              uVar3 = uVar15;
            }
            iVar7 = FUN_00193e18(uVar11,uVar3 * 0x2c);
            if (uVar19 != 0) {
              uVar15 = 0;
              iVar23 = 0;
              do {
                uVar15 = uVar15 + 1;
                _memcpy((void *)(iVar7 + iVar23),(void *)(iVar2 + iVar23),0x2c);
                iVar23 = iVar23 + 0x2c;
              } while (uVar15 != uVar19);
            }
            FUN_00193cc0(uVar11,iVar2);
          }
          _memcpy(pvVar8,(void *)(iVar6 + iVar7),0x2c);
        }
        else {
          if ((uVar22 <= uVar21) && (uVar13 = uVar18, uVar3 < uVar18)) {
            uVar3 = (uVar3 << 4) / 10;
            if (uVar3 < uVar18) {
              uVar3 = uVar18;
            }
            iVar7 = FUN_00193e18(uVar11,uVar3 * 0x2c);
            if (uVar22 != 0) {
              uVar12 = 0;
              iVar25 = 0;
              do {
                uVar12 = uVar12 + 1;
                _memcpy((void *)(iVar7 + iVar25),(void *)(iVar23 + iVar25),0x2c);
                iVar25 = iVar25 + 0x2c;
              } while (uVar12 != uVar22);
            }
            FUN_00193cc0(uVar11,iVar23);
            pvVar8 = (void *)(iVar7 + iVar16);
          }
          iVar2 = ((int (*)())FUN_001436b4)(param_1,iVar5,iVar2,pvVar8);
          uVar12 = uVar15;
          uVar22 = uVar21;
          if (iVar2 == 0) goto LAB_001463fc;
        }
        uVar21 = uVar22 + 1;
        uVar18 = uVar18 + 1;
        uVar15 = uVar12;
      } while ((int)uVar21 < (int)uVar12);
    } while( true );
  }
LAB_0014653c:
  FUN_000ed7e4(iVar2,"post_pack_insts");
  FUN_00193cc0(uVar11,iVar7);
  return;
LAB_00146538:
  iVar2 = param_1[1];
  goto LAB_0014653c;
}

/* FUN_0014657c @ 0x14657c (124 bytes) */
int FUN_0014657c(param_1)
  int param_1;
{
  int local_38 [3];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_38[0] = *(int *)(param_1 + 8);
  local_2c = *(undefined4 *)(local_38[0] + 0x378);
  local_28 = 0;
  local_24 = 0x10;
  local_20 = FUN_00193e18(local_2c,0x2c0);
  ((int (*)())FUN_00140e5c)(local_38,param_1);
  ((int (*)())FUN_00145670)(local_38);
  FUN_00193cc0(local_2c,local_20);
  return;
}

/* FUN_00146610 @ 0x146610 (20 bytes) */
int FUN_00146610(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_00105594();
    return uVar1;
  }
  return param_3;
}

/* FUN_00146624 @ 0x146624 (76 bytes) */
int FUN_00146624(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  
  uStack00000018 = param_1;
  iVar3 = 4;
  uStack0000001c = param_2;
  pcVar1 = (char *)&STACKARG(0x1c);
  pcVar2 = (char *)&STACKARG(0x18);
  while ((*pcVar1 != '\x01' || (*pcVar2 == '\x04'))) {
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00146670 @ 0x146670 (132 bytes) */
int FUN_00146670(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  int param_3;
  int param_4;
{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*param_2 + 0x5c))(param_2);
  if ((iVar1 == 0) && (param_3 == 0)) {
    piVar2 = *(int **)(param_4 + 0x30c);
    UNRECOVERED_JUMPTABLE = *(code **)(*piVar2 + 0x100);
  }
  else {
    piVar2 = *(int **)(param_4 + 0x30c);
    UNRECOVERED_JUMPTABLE = *(code **)(*piVar2 + 0x108);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(piVar2,param_1);
  return;
}

/* FUN_001466f4 @ 0x1466f4 (104 bytes) */
int FUN_001466f4()
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00105594();
  iVar2 = (**(code **)(*piVar1 + 0x60))();
  if (iVar2 != 0) {
    piVar1 = (int *)FUN_00105594(piVar1,1);
    return piVar1;
  }
  return piVar1;
}

/* FUN_00146788 @ 0x146788 (96 bytes) */
int FUN_00146788(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0010497c();
  if ((((iVar1 == 0) || (*(int *)(param_1 + 0x120) != 0)) || (*(int *)(param_1 + 0x124) != 0)) ||
     (uVar2 = 1, (*(uint *)(param_1 + 0x14) & 0x200) != 0)) {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_001467e8 @ 0x1467e8 (128 bytes) */
int FUN_001467e8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = FUN_00139344();
  if (iVar1 != 0) {
    piVar2 = *(int **)(param_2 + 0x3a0);
    for (piVar3 = *(int **)(param_1 + 0x158); piVar2 != piVar3; piVar3 = (int *)piVar3[0x3c]) {
      iVar1 = (**(code **)(*piVar3 + 0x24))(piVar3);
      if (iVar1 != 0) {
        return 0;
      }
    }
  }
  return 1;
}

/* FUN_00146868 @ 0x146868 (228 bytes) */
int FUN_00146868(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  undefined4 param_3;
{
  int iVar1;
  int *piVar2;
  
  if ((int *)param_2[0x56] == (int *)param_1[0x56]) {
    do {
      param_2 = (int *)param_2[1];
      iVar1 = (**(code **)(*param_2 + 0x34))(param_2);
      if (iVar1 != 0) {
        return 0;
      }
    } while (param_2 != param_1);
  }
  else {
    iVar1 = (**(code **)(*(int *)param_2[0x56] + 0x1c))();
    if (iVar1 != 0) {
      return 0;
    }
    FUN_000ec4f0(param_3);
    piVar2 = *(int **)(param_2[0x56] + 0xf0);
    if (piVar2 != (int *)param_1[0x56]) {
      do {
        iVar1 = (**(code **)(*piVar2 + 0x1c))(piVar2);
        if (iVar1 != 0) {
          return 0;
        }
        piVar2 = (int *)piVar2[0x3c];
      } while (piVar2 != (int *)param_1[0x56]);
    }
  }
  return 1;
}

/* FUN_0014699c @ 0x14699c (368 bytes) */
int FUN_0014699c(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = -1;
  iVar3 = FUN_00105594(*param_1,param_1[1]);
  if ((*(uint *)(iVar3 + 0xb8) & 1) == 0) {
    iVar8 = 1;
  }
  iVar3 = FUN_00105594(*param_1,param_1[1]);
  iVar6 = -1;
  if ((*(uint *)(iVar3 + 0xd0) & 1) == 0) {
    iVar6 = 1;
  }
  uVar5 = param_1[1];
  iVar3 = -1;
  if ((*(uint *)(uVar5 * 0x18 + *param_1 + 0xa0) & 1) == 0) {
    iVar3 = 1;
  }
  iVar1 = -1;
  if ((*(uint *)((uVar5 + (((int)uVar5 >> 1) + (uint)((int)uVar5 < 0 && (uVar5 & 1) != 0)) * -2) *
                 0x18 + *param_1 + 0xb8) & 1) == 0) {
    iVar1 = 1;
  }
  iVar4 = FUN_00105594(*param_2,param_2[1]);
  iVar9 = -1;
  if ((*(uint *)(iVar4 + 0xb8) & 1) == 0) {
    iVar9 = 1;
  }
  iVar4 = FUN_00105594(*param_2,param_2[1]);
  iVar7 = -1;
  if ((*(uint *)(iVar4 + 0xd0) & 1) == 0) {
    iVar7 = 1;
  }
  uVar5 = param_2[1];
  iVar4 = -1;
  if ((*(uint *)(uVar5 * 0x18 + *param_2 + 0xa0) & 1) == 0) {
    iVar4 = 1;
  }
  iVar2 = -1;
  if ((*(uint *)((uVar5 + (((int)uVar5 >> 1) + (uint)((int)uVar5 < 0 && (uVar5 & 1) != 0)) * -2) *
                 0x18 + *param_2 + 0xb8) & 1) == 0) {
    iVar2 = 1;
  }
  return iVar1 * iVar3 * iVar8 * iVar6 == iVar2 * iVar4 * iVar9 * iVar7;
}

/* FUN_00146b0c @ 0x146b0c (460 bytes) */
int FUN_00146b0c(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int *param_5;
  int *param_6;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  param_2 = param_2 + 1;
  iVar1 = FUN_00105594(param_1,1);
  iVar2 = FUN_00105594(param_1,2);
  if ((param_2 == 1) && (param_3 == 0x14)) {
    param_3 = 0x13;
  }
  iVar4 = param_2;
  if (iVar1 != iVar2) {
    if ((((*(int *)(*(int *)(iVar1 + 0x88) + 8) == param_3) &&
         (iVar3 = ((int (*)())FUN_00146788)(iVar1,param_4), iVar3 != 0)) &&
        ((*(uint *)(param_1 + 0xb8) & 1) == 0)) &&
       ((((*(uint *)(param_1 + 0xb8) & 2) == 0 && (iVar3 = FUN_00105c5c(param_1,1), iVar3 == 0)) &&
        (*(int *)(param_1 + 0x158) == *(int *)(iVar1 + 0x158))))) {
      iVar4 = ((int (*)())FUN_00146b0c)(iVar1,param_2,param_3,param_4,param_5,param_6);
    }
    iVar1 = param_2;
    if (((*(int *)(*(int *)(iVar2 + 0x88) + 8) == param_3) &&
        (iVar3 = ((int (*)())FUN_00146788)(iVar2,param_4), iVar3 != 0)) &&
       (((*(uint *)(param_1 + 0xd0) & 1) == 0 &&
        ((((*(uint *)(param_1 + 0xd0) & 2) == 0 && (iVar3 = FUN_00105c5c(param_1,2), iVar3 == 0)) &&
         (*(int *)(param_1 + 0x158) == *(int *)(iVar2 + 0x158))))))) {
      iVar1 = ((int (*)())FUN_00146b0c)(iVar2,param_2,param_3,param_4,param_5,param_6);
    }
    if ((param_2 != iVar4) || (param_2 != iVar1)) {
      if (iVar4 < iVar1) {
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x4000;
        return iVar1;
      }
      goto LAB_00146c90;
    }
  }
  if (param_2 <= *param_6) {
    return *param_6;
  }
  *param_5 = param_1;
  *param_6 = param_2;
LAB_00146c90:
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xffffbfff;
  return iVar4;
}

/* FUN_00146cd8 @ 0x146cd8 (264 bytes) */
int FUN_00146cd8(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = FUN_00105594(*param_1,param_1[1]);
  if (((*(uint *)(iVar2 + 0x14) & 0x200) == 0) &&
     ((iVar3 = FUN_0010497c(iVar2,param_2), iVar3 != 0 ||
      (iVar3 = FUN_001049c4(iVar2,param_2), iVar3 != 0)))) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  uVar5 = param_1[1];
  if (*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x12) {
    if ((*(int *)(iVar2 + 0x120) != 0) || (uVar1 = 0, *(int *)(iVar2 + 0x124) != 0)) {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = *(uint *)(iVar2 + 0x120);
  }
  return (uVar1 ^ 1) &
         (*(uint *)((uVar5 + (((int)uVar5 >> 1) + (uint)((int)uVar5 < 0 && (uVar5 & 1) != 0)) * -2)
                    * 0x18 + *param_1 + 0xb8) >> 1 & 1 ^ 1) &
         (*(uint *)(uVar5 * 0x18 + *param_1 + 0xa0) >> 1 & 1 ^ 1) & uVar4;
}

/* FUN_00146de0 @ 0x146de0 (252 bytes) */
int FUN_00146de0(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = (**(code **)(*param_1 + 0x5c))();
  if ((iVar1 != 0) && (iVar1 = (**(code **)(*param_2 + 0x5c))(param_2), iVar1 != 0)) {
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
    if (*(int *)(param_1[0x22] + 8) != *(int *)(param_2[0x22] + 8)) {
      return 1;
    }
    (**(code **)(*param_2 + 0x14))(param_2);
    if (0 < iVar1) {
      iVar4 = 1;
      do {
        iVar2 = FUN_00105594(param_1,iVar4);
        iVar3 = FUN_00105594(param_2,iVar4);
        if (iVar2 != iVar3) {
          return 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 <= iVar1);
    }
  }
  return 0;
}

/* FUN_00146edc @ 0x146edc (304 bytes) */
int FUN_00146edc(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x5c))();
  if (((iVar1 != 0) && (iVar1 = (**(code **)(*param_2 + 0x5c))(param_2), iVar1 != 0)) &&
     (*(int *)(param_1[0x22] + 8) == *(int *)(param_2[0x22] + 8))) {
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
    iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar1 == iVar2) {
      iVar1 = FUN_00105594(param_1,1);
      iVar2 = FUN_00105594(param_2,1);
      if (iVar1 == iVar2) {
        iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
        if (iVar1 == 2) {
          iVar1 = FUN_00105594(param_1,2);
          iVar2 = FUN_00105594(param_2,2);
          if (iVar1 != iVar2) {
            return 0;
          }
        }
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0014700c @ 0x14700c (56 bytes) */
int FUN_0014700c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if ((param_1 != param_2) && (iVar1 = ((int (*)())FUN_00146edc)(), iVar1 == 0)) {
    return 0;
  }
  return 1;
}

/* FUN_00147044 @ 0x147044 (152 bytes) */
int FUN_00147044(param_1, param_2)
  int *param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 1;
  if (param_1 != param_2) {
    iVar2 = (**(code **)(*param_1 + 0x5c))();
    if ((iVar2 != 0) && (iVar2 = (**(code **)(*param_2 + 0x5c))(param_2), iVar2 != 0)) {
      uVar1 = ((int (*)())FUN_00146edc)(param_1,param_2);
      return uVar1;
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* FUN_001470dc @ 0x1470dc (348 bytes) */
int FUN_001470dc(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  uVar3 = 0;
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x12) {
    iVar4 = FUN_00105594(param_1,1);
    iVar5 = FUN_00105594(param_1,2);
    iVar7 = *(int *)(*(int *)(iVar5 + 0x88) + 8);
    if (((((*(int *)(*(int *)(iVar4 + 0x88) + 8) == 0x13) && ((*(uint *)(param_1 + 0xb8) & 2) == 0))
         && (iVar6 = FUN_000f48ec(param_1,1), iVar6 != 0)) &&
        ((*(int *)(iVar4 + 0x120) == 0 && (*(int *)(iVar4 + 0x124) == 0)))) &&
       ((param_3 == 0 || (iVar4 = FUN_0010497c(iVar4,param_2), iVar4 != 0)))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((((iVar7 == 0x13) && ((*(uint *)(param_1 + 0xd0) & 2) == 0)) &&
        ((iVar4 = FUN_000f48ec(param_1,2), iVar4 != 0 &&
         ((*(int *)(iVar5 + 0x120) == 0 && (*(int *)(iVar5 + 0x124) == 0)))))) &&
       ((param_3 == 0 || (iVar4 = FUN_0010497c(iVar5,param_2), iVar4 != 0)))) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar1) || (uVar3 = 0, bVar2)) {
      uVar3 = 1;
    }
  }
  return uVar3;
}

/* FUN_00147238 @ 0x147238 (352 bytes) */
int FUN_00147238(param_1)
  int *param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  
  if (*(int *)(param_1[0x22] + 8) == 0x12) {
    iVar6 = 0;
    do {
      iVar2 = FUN_001054ec(param_1,0);
      if (*(char *)(iVar6 + iVar2 + 0x10) != '\x01') {
        bVar1 = false;
        for (iVar2 = 1; iVar4 = (**(code **)(*param_1 + 0x14))(param_1), iVar2 <= iVar4;
            iVar2 = iVar2 + 1) {
          iVar4 = FUN_001054ec(param_1,iVar2);
          uVar7 = (uint)*(byte *)(iVar6 + iVar4 + 0x10);
          piVar3 = (int *)FUN_00105594(param_1,iVar2);
          iVar4 = (**(code **)(*piVar3 + 0x60))();
          if (iVar4 != 0) {
            uVar5 = FUN_001042bc(piVar3,uVar7);
            iVar4 = FUN_001054ec(piVar3,uVar5);
            uVar7 = (uint)*(byte *)(uVar7 + iVar4 + 0x10);
            piVar3 = (int *)FUN_00105594(piVar3,uVar5);
          }
          if ((((int)*(char *)(piVar3 + 0x57) >> (uVar7 & 0x3f) & 1U) == 0) ||
             ((float)piVar3[uVar7 * 6 + 8] != FLOAT_001aa0d4)) {
            if (bVar1) goto LAB_0014736c;
            bVar1 = true;
          }
        }
      }
      bVar1 = iVar6 != 3;
      iVar6 = iVar6 + 1;
    } while (bVar1);
    uVar5 = 1;
  }
  else {
LAB_0014736c:
    uVar5 = 0;
  }
  return uVar5;
}

/* FUN_00147398 @ 0x147398 (120 bytes) */
int FUN_00147398(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_00147238)();
  if (iVar1 != 0) {
LAB_001474b4:
    return 1;
  }
  switch(*(undefined4 *)(*(int *)(param_1 + 0x88) + 8)) {
  case 0x13:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x31:
  case 0x3e:
  case 0x3f:
  case 0x40:
    goto LAB_001474b4;
  default:
    return 0;
  }
}

/* FUN_001474c8 @ 0x1474c8 (572 bytes) */
int FUN_001474c8(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int **ppiVar7;
  int iVar8;
  int *piVar9;
  int iStack_48;
  int *local_44 [11];
  
  if ((*(int *)(param_2[0x22] + 8) != 0x8e) &&
     (iVar3 = (**(code **)(*param_2 + 0x68))(param_2), iVar3 == 0)) {
    iVar3 = param_2[0x21];
    if ((iVar3 != 0) && ((param_2[5] & 8U) == 0)) {
      piVar5 = (int *)param_2[0x56];
      if (0 < iVar3) {
        iVar8 = 1;
        ppiVar7 = local_44;
        do {
          iVar3 = FUN_00105594(param_2,iVar8);
          iVar8 = iVar8 + 1;
          *ppiVar7 = *(int **)(iVar3 + 0x158);
          ppiVar7 = ppiVar7 + 1;
          iVar3 = param_2[0x21];
        } while (iVar8 <= iVar3);
      }
      piVar1 = piVar5;
      piVar9 = piVar5;
      do {
        piVar2 = piVar1;
        if (0 < iVar3) {
          iVar8 = 1;
          if (piVar2 == local_44[0]) {
            iVar4 = 4;
          }
          else {
            do {
              iVar8 = iVar8 + 1;
              if (iVar3 < iVar8) goto LAB_001475b8;
              iVar4 = iVar8 * 4;
            } while (piVar2 != (int *)(&iStack_48)[iVar8]);
          }
          piVar5 = *(int **)((int)&iStack_48 + iVar4);
          if (iVar8 != 0) goto LAB_001475e8;
        }
LAB_001475b8:
        piVar9 = piVar2;
      } while ((piVar2 != (int *)0x0) &&
              (piVar1 = (int *)piVar2[0x3c], (int *)piVar2[0x3c] != (int *)0x0));
      iVar8 = 0;
LAB_001475e8:
      iVar3 = (**(code **)(*piVar5 + 0x2c))(piVar5);
      if (iVar3 != 0) {
        FUN_0010401c(param_2);
        param_2[5] = param_2[5] | 1;
        FUN_000e76c4(piVar9,param_2);
        return;
      }
      FUN_00105594(param_2,iVar8);
      iVar3 = *(int *)(piVar5[0x28] + 4);
      if (iVar3 != 0) {
        iVar4 = param_2[0x21];
        iVar8 = piVar5[0x28];
        do {
          iVar6 = iVar3;
          if (0 < iVar4) {
            iVar3 = 1;
            do {
              iVar4 = FUN_00105594(param_2,iVar3);
              if ((iVar4 == iVar8) || (*(int *)(*(int *)(iVar8 + 0x88) + 8) == 0x8e)) {
                FUN_0010401c(param_2);
                param_2[5] = param_2[5] | 1;
                FUN_000e7738(piVar5,iVar8,param_2);
                return;
              }
              iVar4 = param_2[0x21];
              iVar3 = iVar3 + 1;
            } while (iVar3 <= iVar4);
          }
          iVar3 = *(int *)(iVar6 + 4);
          iVar8 = iVar6;
        } while (iVar3 != 0);
      }
    }
  }
  return;
}

/* FUN_00147704 @ 0x147704 (756 bytes) */
int FUN_00147704(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  bool bVar9;
  int local_38 [6];
  
  local_38[1] = FUN_00105594(param_1,1);
  local_38[0] = local_38[1];
  if (param_2 != 0) {
    local_38[1] = FUN_00105594(param_2,1);
  }
  bVar9 = local_38[1] == local_38[0];
  iVar5 = -(uint)bVar9 + 2;
  local_38[2] = local_38[0];
  if (param_3 != 0) {
    local_38[2] = FUN_00105594(param_3,1);
  }
  if (local_38[2] != local_38[1]) {
    if (iVar5 == 1) {
      local_38[1] = local_38[2];
      goto LAB_001477a8;
    }
    if (local_38[2] != local_38[0]) {
      iVar5 = -(uint)bVar9 + 3;
    }
  }
  if (iVar5 < 1) {
    return;
  }
LAB_001477a8:
  iVar6 = 0;
  piVar7 = local_38;
  do {
    piVar8 = (int *)*piVar7;
    if (piVar8 != (int *)0x0) {
      iVar1 = *(int *)(piVar8[0x22] + 8);
      while ((iVar1 != 0x3a && (iVar1 != 0x3b))) {
        iVar1 = (**(code **)(*piVar8 + 100))(piVar8);
        if (iVar1 == 0) {
          iVar2 = piVar8[0x22];
          iVar1 = *(int *)(iVar2 + 8);
          if (iVar1 == 0x13) {
            piVar3 = (int *)FUN_00105594(piVar8,1);
            piVar4 = (int *)FUN_00105594(piVar8,2);
            iVar1 = (**(code **)(*piVar3 + 0x48))(piVar3);
            if (iVar1 == 0) {
              FUN_00105894(piVar4,*(undefined4 *)(param_4 + 8));
            }
            else {
              FUN_00105894(piVar3,*(undefined4 *)(param_4 + 8));
              piVar3 = piVar4;
            }
            (**(code **)(*piVar8 + 0xc))(piVar8,0,*(undefined4 *)(param_4 + 8));
            goto LAB_001479a4;
          }
          if ((iVar1 == 0x12) || (iVar1 == 0x9b)) {
            piVar3 = (int *)FUN_00105594(piVar8,1);
            (**(code **)(*piVar8 + 0xc))(piVar8,0,*(undefined4 *)(param_4 + 8));
            FUN_00105894(piVar3,*(undefined4 *)(param_4 + 8));
            goto LAB_001479a4;
          }
        }
        else {
          piVar3 = (int *)FUN_00105594(piVar8,1);
          (**(code **)(*piVar8 + 0xc))(piVar8,0,*(undefined4 *)(param_4 + 8));
LAB_001479a4:
          if (piVar3 == (int *)0x0) goto LAB_001479ac;
          iVar2 = piVar3[0x22];
          piVar8 = piVar3;
        }
        iVar1 = *(int *)(iVar2 + 8);
      }
      if (((piVar8[5] & 0x200U) != 0) &&
         (piVar3 = (int *)FUN_00105594(piVar8,piVar8[0x21]), piVar3 != (int *)0x0)) {
        if (((piVar3[5] & 0x200U) != 0) &&
           (piVar4 = (int *)FUN_00105594(piVar3,piVar3[0x21]), piVar4 != (int *)0x0)) {
          (**(code **)(*piVar4 + 0xc))(piVar4,0,*(undefined4 *)(param_4 + 8));
        }
        (**(code **)(*piVar3 + 0xc))(piVar3,0,*(undefined4 *)(param_4 + 8));
      }
      (**(code **)(*piVar8 + 0xc))(piVar8,0,*(undefined4 *)(param_4 + 8));
    }
LAB_001479ac:
    iVar6 = iVar6 + 1;
    piVar7 = piVar7 + 1;
    if (iVar5 == iVar6) {
      return;
    }
  } while( true );
}

/* FUN_001479f8 @ 0x1479f8 (404 bytes) */
int FUN_001479f8(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  bVar1 = true;
  piVar4 = (int *)FUN_00105594(param_1,1);
  iVar8 = *(int *)(param_1 + 0x124);
  iVar7 = *(int *)(param_1 + 0x120);
  bVar2 = true;
  while( true ) {
    iVar6 = (**(code **)(*piVar4 + 0x24))(piVar4);
    if (iVar6 == 0) {
      return;
    }
    iVar6 = FUN_0010497c(piVar4,param_2);
    if (iVar6 == 0) break;
    if (piVar4[0x48] != 0) {
      bVar1 = false;
    }
    piVar5 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
    iVar6 = (**(code **)(*piVar5 + 0xfc))(piVar5,iVar8 + piVar4[0x49],piVar4);
    if (iVar6 == 0) {
      bVar2 = false;
    }
    if ((piVar4[5] & 0x200U) == 0) {
      if (((iVar8 == 0) || ((bVar1 && (bVar2)))) && (iVar6 = FUN_00105594(param_1,1), iVar6 != 0)) {
        do {
          iVar3 = *(int *)(iVar6 + 0x124);
          if (iVar8 != 0) {
            *(int *)(param_2 + 0x170) = *(int *)(param_2 + 0x170) + 1;
            *(int *)(iVar6 + 0x124) = iVar8 + iVar3;
            *(undefined4 *)(param_1 + 0x124) = 0;
          }
          if (((iVar7 != 0) && ((*(uint *)(param_1 + 0xb8) & 1) == 0)) &&
             ((*(uint *)(param_1 + 0xb8) & 2) == 0)) {
            *(int *)(param_2 + 0x170) = *(int *)(param_2 + 0x170) + 1;
            *(undefined4 *)(iVar6 + 0x120) = 1;
            *(undefined4 *)(param_1 + 0x120) = 0;
          }
        } while (((*(uint *)(iVar6 + 0x14) & 0x200) != 0) &&
                (iVar6 = FUN_00105594(iVar6,*(undefined4 *)(iVar6 + 0x84)), iVar6 != 0));
      }
      return;
    }
    piVar4 = (int *)FUN_00105594(piVar4,piVar4[0x21]);
  }
  return;
}

/* FUN_00147b8c @ 0x147b8c (968 bytes) */
int FUN_00147b8c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  undefined4 *param_7;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_48 [8];
  
  piVar1 = (int *)FUN_00105594();
  piVar2 = (int *)FUN_00105594(param_3,param_4);
  if (piVar1 != piVar2) {
    iVar3 = (**(code **)(*piVar1 + 0x5c))(piVar1);
    if ((iVar3 == 0) || (iVar3 = (**(code **)(*piVar2 + 0x5c))(piVar2), iVar3 == 0)) {
      iVar3 = (**(code **)(*piVar1 + 0x5c))(piVar1);
      if ((iVar3 == 0) || (iVar3 = (**(code **)(*piVar2 + 0x5c))(piVar2), iVar3 != 0)) {
        iVar3 = (**(code **)(*piVar1 + 0x5c))(piVar1);
        if ((iVar3 == 0) && (iVar3 = (**(code **)(*piVar2 + 0x5c))(piVar2), iVar3 != 0)) {
          piVar4 = *(int **)(*(int *)(param_5 + 8) + 0x30c);
          iVar3 = (**(code **)(*piVar4 + 0x10c))
                            (piVar4,param_1,param_2,piVar1,param_5,param_6,0,local_48);
          if (iVar3 == 0) {
            return 0;
          }
          iVar3 = ((int (*)())FUN_00146edc)(piVar2,local_48[0]);
          if (iVar3 == 0) {
            return 0;
          }
          *param_7 = 1;
        }
        else {
          piVar4 = piVar1;
          if ((piVar1[5] & 0x200U) == 0) {
            if ((piVar2[5] & 0x200U) == 0) {
              return 0;
            }
            piVar4 = (int *)FUN_00105594(piVar2,piVar2[0x21]);
            if (piVar1 != piVar4) {
              return 0;
            }
            iVar3 = FUN_000f485c(param_3,param_4);
            if (iVar3 == 0) {
              return 0;
            }
            if (param_6 != 0) {
              FUN_00106004(param_1,param_2,piVar2,0,*(undefined4 *)(param_5 + 8));
              if (*(int *)(param_5 + 0x478) < piVar2[0x58]) {
                piVar2[0x58] = piVar2[0x58] + 1;
              }
              else {
                piVar2[0x58] = *(int *)(param_5 + 0x478) + 1;
              }
              piVar1[0x58] = piVar1[0x58] + -1;
            }
          }
          else {
            do {
              if ((piVar4[5] & 0x200U) == 0) {
                return 0;
              }
              piVar4 = (int *)FUN_00105594(piVar4,piVar4[0x21]);
            } while ((piVar2 != piVar4) || (iVar3 = FUN_000f485c(param_1,param_2), iVar3 == 0));
            if (param_6 != 0) {
              FUN_00106004(param_3,param_4,piVar1,0,*(undefined4 *)(param_5 + 8));
              if (*(int *)(param_5 + 0x478) < piVar1[0x58]) {
                piVar1[0x58] = piVar1[0x58] + 1;
              }
              else {
                piVar1[0x58] = *(int *)(param_5 + 0x478) + 1;
              }
              piVar2[0x58] = piVar2[0x58] + -1;
            }
          }
        }
        goto LAB_00147e9c;
      }
      piVar4 = *(int **)(*(int *)(param_5 + 8) + 0x30c);
      iVar3 = (**(code **)(*piVar4 + 0x10c))
                        (piVar4,param_3,param_4,piVar2,param_5,param_6,0,local_48);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = ((int (*)())FUN_00146edc)(piVar1,local_48[0]);
    }
    else {
      iVar3 = ((int (*)())FUN_00146edc)(piVar1,piVar2);
    }
    if (iVar3 == 0) {
      return 0;
    }
  }
LAB_00147e9c:
  if ((piVar1[0x48] == piVar2[0x48]) && (piVar1[0x49] == piVar2[0x49])) {
    uVar7 = *(uint *)(param_2 * 0x18 + param_1 + 0xa0);
    uVar6 = *(uint *)(param_4 * 0x18 + param_3 + 0xa0);
    if (((uVar7 & 1) == (uVar6 & 1)) && ((uVar7 >> 1 & 1) == (uVar6 >> 1 & 1))) {
      iVar3 = FUN_00105dbc(param_1,param_2);
      iVar5 = FUN_00105dbc(param_3,param_4);
      if (iVar3 == iVar5) {
        iVar3 = FUN_00105c5c(param_1,param_2);
        iVar5 = FUN_00105c5c(param_3,param_4);
        if (iVar3 == iVar5) {
          return 1;
        }
      }
    }
  }
  return 0;
}

/* FUN_00147f54 @ 0x147f54 (1300 bytes) */
int FUN_00147f54(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  double dVar19;
  int local_a8 [5];
  undefined1 auStack_94 [4];
  float local_90;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_68;
  uint local_58;
  
  local_a8[0] = 0;
  iVar2 = *(int *)(param_1[0x22] + 8);
  iVar17 = param_1[0x49];
  if (iVar2 == 0x13) {
    iVar2 = 1;
    while( true ) {
      iVar4 = FUN_001054ec(param_1,0);
      iVar4 = FUN_000f5cf0(param_1,iVar2,*(undefined4 *)(iVar4 + 0x10),auStack_94);
      if (iVar4 != 0) break;
      bVar1 = iVar2 == 2;
      iVar2 = iVar2 + 1;
      if (bVar1) {
        return param_1;
      }
    }
    iVar4 = ((undefined4 (*)())FUN_0010ab8c)((double)local_90,iVar4,local_a8);
    if (iVar4 == 0) {
      return param_1;
    }
    local_a8[0] = iVar17 + local_a8[0];
    if (iVar2 == 1) {
      iVar17 = 2;
      uVar16 = 0xffffffff;
      iVar2 = 2;
    }
    else {
      iVar17 = 2;
      uVar16 = 0xffffffff;
      iVar2 = 1;
    }
  }
  else if (iVar2 == 0x14) {
    iVar2 = FUN_001054ec(param_1,0);
    iVar2 = FUN_000f5cf0(param_1,3,*(undefined4 *)(iVar2 + 0x10),auStack_94);
    if (iVar2 == 0) {
      return param_1;
    }
    if ((local_90 != FLOAT_001aa114) && (local_90 != FLOAT_001aa0e8)) {
      return param_1;
    }
    local_a8[4] = 0x40000000;
    local_a8[1] = 0x40000000;
    local_a8[2] = 0x40000000;
    local_a8[3] = 0x40000000;
    iVar2 = FUN_001054ec(param_1,0);
    iVar2 = FUN_000f5c0c(param_1,1,*(undefined4 *)(iVar2 + 0x10),local_a8 + 1);
    if (iVar2 == 0) {
      iVar2 = FUN_001054ec(param_1,0);
      iVar2 = FUN_000f5c0c(param_1,2,*(undefined4 *)(iVar2 + 0x10),local_a8 + 1);
      if (iVar2 == 0) {
        return param_1;
      }
      local_a8[0] = iVar17 + 1;
      iVar17 = 3;
      uVar16 = 2;
      iVar2 = 1;
    }
    else {
      local_a8[0] = iVar17 + 1;
      iVar17 = 3;
      uVar16 = 1;
      iVar2 = 2;
    }
  }
  else {
    if (iVar2 != 0x12) {
      return param_1;
    }
    iVar2 = FUN_00105594(param_1,1);
    iVar4 = FUN_00105594(param_1,2);
    if (iVar2 != iVar4) {
      return param_1;
    }
    iVar2 = FUN_001054ec(param_1,1);
    iVar4 = *(int *)(iVar2 + 0x10);
    iVar2 = FUN_001054ec(param_1,2);
    if (iVar4 != *(int *)(iVar2 + 0x10)) {
      return param_1;
    }
    if ((param_1[0x2e] & 1U) != (param_1[0x34] & 1U)) {
      return param_1;
    }
    if (((uint)param_1[0x2e] >> 1 & 1) != ((uint)param_1[0x34] >> 1 & 1)) {
      return param_1;
    }
    local_a8[0] = iVar17 + 1;
    iVar17 = 1;
    uVar16 = 0xffffffff;
    iVar2 = 1;
  }
  iVar4 = (**(code **)(**(int **)(param_2 + 0x30c) + 0xfc))
                    (*(int **)(param_2 + 0x30c),local_a8[0],param_1);
  if (iVar4 != 0) {
    iVar4 = *(int *)(param_2 + 0x6c4);
    *(int *)(iVar4 + 0x158) = *(int *)(iVar4 + 0x158) + 1;
    if (iVar17 == 2) {
      uVar15 = (uint)(local_90 < FLOAT_001aa0d4) ^ param_1[iVar2 * 6 + 0x28] & 1U;
    }
    else {
      if (iVar17 == 3) {
        dVar19 = (double)FLOAT_001aa0e8;
        param_1[0x49] = local_a8[0];
        FUN_000f79c4(dVar19,dVar19,dVar19,dVar19,param_1,iVar4,uVar16);
        dVar19 = (double)FLOAT_001aa10c;
        FUN_000f79c4(dVar19,dVar19,dVar19,dVar19,param_1,iVar4,3);
        FUN_00103d50(param_1 + 0x35,1,local_90 < FLOAT_001aa0d4);
        return param_1;
      }
      if (iVar17 == 1) {
        uVar15 = param_1[iVar2 * 6 + 0x28] & 1;
      }
      else {
        uVar15 = 0;
      }
    }
    iVar8 = param_1[1];
    iVar9 = param_1[4];
    iVar17 = FUN_00104054(param_1,iVar4);
    uVar3 = param_1[5];
    iVar11 = param_1[0x26];
    iVar13 = param_1[0x25];
    iVar5 = FUN_001054ec(param_1,0);
    iVar10 = *(int *)(iVar5 + 0x10);
    iVar7 = param_1[0x48];
    uVar16 = FUN_00105594(param_1,iVar2);
    iVar14 = param_1[iVar2 * 6 + 0x25];
    iVar18 = param_1[iVar2 * 6 + 0x26];
    iVar5 = FUN_001054ec(param_1,iVar2);
    uVar12 = *(undefined4 *)(iVar5 + 0x10);
    bVar1 = (param_1[5] & 0x200U) != 0;
    uVar6 = param_1[iVar2 * 6 + 0x28];
    local_68 = 0;
    local_7c = 0;
    local_78 = 0;
    local_58 = 0;
    if (bVar1) {
      FUN_00104d3c(param_1,&local_7c);
    }
    local_58 = (uint)bVar1;
    (**(code **)(*param_1 + 0xc))(param_1,1,param_2);
    FUN_00108448(param_1,0x31,param_2);
    if ((uVar3 & 2) != 0) {
      param_1[5] = param_1[5] | 2;
    }
    param_1[4] = iVar9;
    iVar2 = *(int *)(iVar4 + 0x478);
    param_1[0x25] = iVar13;
    param_1[0x26] = iVar11;
    param_1[0x58] = iVar17 + iVar2;
    iVar2 = FUN_001054ec(param_1,1);
    *(int *)(iVar2 + 0xc) = iVar18;
    *(int *)(iVar2 + 8) = iVar14;
    param_1[0x27] = iVar10;
    FUN_00106004(param_1,1,uVar16,1,param_2);
    iVar2 = FUN_001054ec(param_1,1);
    *(undefined4 *)(iVar2 + 0x10) = uVar12;
    FUN_00103d50(param_1 + 0x29,2,uVar6 >> 1 & 1);
    FUN_00103d50(param_1 + 0x29,1,uVar15);
    param_1[0x48] = iVar7;
    param_1[0x49] = local_a8[0];
    if (local_58 != 0) {
      FUN_00106b48(param_1,&local_7c,1,param_2);
    }
    FUN_000e7738(*(undefined4 *)(iVar8 + 0x158),iVar8,param_1);
  }
  return param_1;
}

/* FUN_0014846c @ 0x14846c (636 bytes) */
int FUN_0014846c(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  int *piVar12;
  undefined4 local_4c;
  undefined4 local_48 [8];
  
  if ((param_1[5] & 2U) != 0) {
    iVar3 = FUN_001054ec(param_1,0);
    uVar2 = *(uint *)(iVar3 + 0x10);
    iVar3 = FUN_000f2e18(uVar2);
    if ((iVar3 != 0) && (iVar3 = FUN_000e07dc(*(undefined4 *)(param_2 + 8),0x31), iVar3 != 0)) {
      iVar8 = param_1[0x26];
      iVar3 = param_1[0x25];
      piVar4 = (int *)FUN_00105594(param_1,1);
      for (iVar9 = 4;
          ((iVar6 = (**(code **)(*piVar4 + 0x30))(piVar4), iVar6 == 0 &&
           (iVar6 = (**(code **)(*piVar4 + 0x40))(piVar4), iVar6 == 0)) && (iVar9 != 0));
          iVar9 = iVar9 + -1) {
        puVar11 = (uint *)piVar4[4];
        uVar10 = 0;
        uVar7 = puVar11[1];
        if (0 < (int)uVar7) {
          do {
            if (uVar10 < *puVar11) {
              if (uVar7 <= uVar10) {
                _memset((void *)(uVar7 * 4 + puVar11[2]),0,(uVar10 - uVar7) * 4 + 4);
                puVar11[1] = uVar10 + 1;
              }
              puVar5 = (undefined4 *)(uVar10 * 4 + puVar11[2]);
            }
            else {
              puVar5 = (undefined4 *)FUN_0019423c(puVar11,uVar10);
            }
            piVar12 = (int *)*puVar5;
            if (((param_1 != piVar12) && (iVar8 == piVar12[0x26])) && (iVar3 == piVar12[0x25])) {
              *(int *)(param_2 + 0x168) = *(int *)(param_2 + 0x168) + 1;
              iVar3 = FUN_001054ec(piVar12,0);
              uVar7 = *(uint *)(iVar3 + 0x10);
              uVar2 = (uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
                      uVar2 >> 0x18) &
                      (uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 |
                      uVar7 >> 0x18);
              param_1[0x27] =
                   uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
              iVar3 = FUN_001054ec(param_1,1);
              local_4c = *(undefined4 *)(iVar3 + 0x10);
              iVar8 = FUN_001054ec(piVar12,1);
              iVar3 = 0;
              local_48[0] = *(undefined4 *)(iVar8 + 0x10);
              iVar8 = 4;
              do {
                if (*(char *)((int)local_48 + iVar3 + -4) == '\x04') {
                  *(undefined1 *)((int)local_48 + iVar3 + -4) =
                       *(undefined1 *)((int)local_48 + iVar3);
                }
                uVar1 = local_4c;
                iVar3 = iVar3 + 1;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
              iVar3 = FUN_001054ec(param_1,1);
              *(undefined4 *)(iVar3 + 0x10) = uVar1;
              (**(code **)(*piVar12 + 0xc))(piVar12,1,*(undefined4 *)(param_2 + 8));
              return;
            }
            puVar11 = (uint *)piVar4[4];
            uVar10 = uVar10 + 1;
            uVar7 = puVar11[1];
          } while ((int)uVar10 < (int)uVar7);
        }
        if ((piVar4[5] & 0x200U) == 0) {
          return;
        }
        piVar4 = (int *)FUN_00105594(piVar4,piVar4[0x21]);
      }
    }
  }
  return;
}

