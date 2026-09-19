#include "decls.h"

/* FUN_001494d0 @ 0x1494d0 (310 bytes) */
int FUN_001494d0(param_1, param_2, param_3)
  undefined4 *param_1;
  int *param_2;
  undefined4 param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  while( true ) {
    piVar2 = (int *)param_2[4];
    if (piVar2[1] == 0) break;
    if (*piVar2 == 0) {
      piVar2 = (int *)FUN_001a7f7c(piVar2,0);
    }
    else {
      if (piVar2[1] == 0) {
        *(undefined4 *)piVar2[2] = 0;
        piVar2[1] = 1;
      }
      piVar2 = (int *)piVar2[2];
    }
    iVar1 = *piVar2;
    iVar3 = *(int *)(iVar1 + 0x84);
    iVar4 = iVar3;
    if ((*(byte *)(iVar1 + 0x15) & 2) != 0) {
      iVar4 = iVar3 + -1;
      piVar2 = (int *)FUN_0010b180(iVar1,iVar3);
      if (param_2 == piVar2) {
        FUN_0010c18e(iVar1,param_3,1,*param_1);
      }
    }
    if (0 < iVar4) {
      iVar3 = 1;
      do {
        piVar2 = (int *)FUN_0010b180(iVar1,iVar3);
        if (param_2 == piVar2) {
          FUN_0010ba02(iVar1,iVar3,param_3,1,*param_1);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= iVar4);
    }
  }
  *(int *)(param_1[1] + 0x1b4) = *(int *)(param_1[1] + 0x1b4) + 1;
                    
                    
  (**(code **)(*param_2 + 0xc))();
  return;
}

/* FUN_00149606 @ 0x149606 (526 bytes) */
int FUN_00149606(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  cVar2 = FUN_0010a4c8(param_2,param_3);
  if (cVar2 == '\0') {
    cVar2 = FUN_0010a4c8(param_3,param_2);
    if (cVar2 == '\0') {
      return 0;
    }
    iVar7 = *(int *)(param_2 + 0x84);
    iVar8 = iVar7;
    if ((*(byte *)(param_2 + 0x15) & 2) != 0) {
      iVar8 = iVar7 + -1;
      iVar7 = FUN_0010b180(param_2,iVar7);
      if ((param_4 != '\0') && (param_3 == iVar7)) {
        return 0;
      }
    }
    if (0 < iVar8) {
      iVar7 = 1;
      do {
        iVar3 = FUN_0010b180(param_2,iVar7);
        if (param_3 == iVar3) {
          return 0;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 <= iVar8);
    }
    puVar6 = *(uint **)(param_3 + 0x10);
    if (puVar6[1] != 0) {
      uVar9 = 0;
      do {
        if (uVar9 < *puVar6) {
          uVar1 = puVar6[1];
          if (uVar1 <= uVar9) {
            _memset((void *)(puVar6[2] + uVar1 * 4),0,(uVar9 - uVar1) * 4 + 4);
            puVar6[1] = uVar9 + 1;
          }
          piVar4 = (int *)(puVar6[2] + uVar9 * 4);
        }
        else {
          piVar4 = (int *)FUN_001a7f7c(puVar6,uVar9);
        }
        if ((*piVar4 != 0) && (cVar2 = FUN_0010a4c8(param_2,*piVar4), cVar2 == '\0')) {
          return 0;
        }
        uVar9 = uVar9 + 1;
        puVar6 = *(uint **)(param_3 + 0x10);
      } while (uVar9 < puVar6[1]);
    }
  }
  else {
    iVar7 = *(int *)(param_3 + 0x84);
    iVar8 = iVar7;
    if ((*(byte *)(param_3 + 0x15) & 2) != 0) {
      iVar8 = iVar7 + -1;
      iVar7 = FUN_0010b180(param_3,iVar7);
      if ((param_4 != '\0') && (param_2 == iVar7)) {
        return 0;
      }
    }
    if (iVar8 < 1) {
      iVar7 = *(int *)(param_3 + 0x84);
    }
    else {
      iVar7 = 1;
      do {
        iVar3 = FUN_0010b180(param_3,iVar7);
        if (param_2 == iVar3) {
          return 0;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 <= iVar8);
      iVar7 = *(int *)(param_3 + 0x84);
    }
    if (0 < iVar7) {
      iVar7 = 1;
      do {
        uVar5 = FUN_0010b180(param_3,iVar7);
        cVar2 = FUN_0010a4c8(uVar5,param_2);
        if (cVar2 == '\0') {
          return 0;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 <= *(int *)(param_3 + 0x84));
    }
  }
  return 1;
}

/* FUN_00149814 @ 0x149814 (116 bytes) */
int FUN_00149814(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined1 *param_4;
{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = ((int (*)())FUN_00149606)(param_1,param_2,param_3,0);
  if (cVar1 == '\0') {
    cVar1 = ((int (*)())FUN_00149606)(param_1,param_3,param_2,0);
    if (cVar1 != '\0') {
      *param_4 = 1;
      return 1;
    }
    uVar2 = 0;
  }
  else {
    *param_4 = 0;
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_00149888 @ 0x149888 (38 bytes) */
int FUN_00149888(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = FUN_0010b0f4(param_2,0);
  FUN_000f5fea(*(undefined4 *)(iVar1 + 0x10));
  return;
}

/* FUN_001498ae @ 0x1498ae (56 bytes) */
int FUN_001498ae(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_00149344(param_1,param_2);
  uVar2 = ((int (*)())FUN_00149888)(param_1,param_2);
  return uVar1 & ~uVar2;
}

/* FUN_001498e6 @ 0x1498e6 (194 bytes) */
int FUN_001498e6(param_1, param_2, param_3, param_4, param_5)
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
  undefined4 local_14;
  undefined4 local_10;
  
  FUN_00149350(param_1,param_2,param_4);
  iVar1 = *(int *)(param_2 + 0x84) + -1 + (uint)((*(uint *)(param_2 + 0x14) & 0x200) == 0);
  if (0 < iVar1) {
    iVar4 = 1;
    do {
      iVar2 = FUN_0010b180(param_2,iVar4);
      iVar3 = FUN_0010b180(param_4,iVar4);
      if (iVar2 != iVar3) {
        return 0;
      }
      iVar2 = FUN_0010b0f4(param_2,iVar4);
      local_10 = *(undefined4 *)(iVar2 + 0x10);
      iVar2 = FUN_0010b0f4(param_4,iVar4);
      local_14 = *(undefined4 *)(iVar2 + 0x10);
      if (*(char *)((int)&local_14 + param_5) != *(char *)((int)&local_10 + param_3)) {
        return 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= iVar1);
  }
  return 1;
}

/* FUN_001499a8 @ 0x1499a8 (4561 bytes) */
int FUN_001499a8(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int *param_3;
  int *param_4;
{
  int *piVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  undefined4 uVar9;
  char *pcVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int *piVar16;
  int *local_120;
  int *local_110;
  undefined4 *local_10c;
  undefined4 *local_108;
  int local_f0;
  uint local_e8;
  uint local_e4;
  int *local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_c8;
  int local_c0;
  uint local_b8;
  uint local_ac;
  uint local_9c;
  int local_98;
  int *local_94;
  int *local_90;
  uint local_8c;
  uint local_88;
  uint local_80;
  int local_74;
  uint local_6c;
  int local_54;
  int local_50;
  int *local_4c;
  int *local_48;
  int local_30 [5];
  int local_1c [2];
  undefined4 local_14;
  byte bStack_11;
  undefined4 local_10;
  
  FUN_00149350(param_1,param_2,param_3);
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
    iVar13 = 5;
    piVar6 = param_4;
    do {
      piVar6[1] = 0;
      piVar6 = piVar6 + 1;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  local_f0 = param_2[0x21];
  if ((*(byte *)((int)param_2 + 0x15) & 2) != 0) {
    if ((*(byte *)((int)param_3 + 0x15) & 2) != 0) {
      piVar6 = (int *)FUN_0010b180(param_2,local_f0);
      piVar7 = (int *)FUN_0010b180(param_3,param_3[0x21]);
      if (((piVar6 != piVar7) && (param_3 != piVar6)) && (param_2 != piVar7)) {
        cVar5 = (**(code **)(*piVar6 + 0x60))(piVar6);
        if ((cVar5 != '\0') || (cVar5 = (**(code **)(*piVar7 + 0x60))(piVar7), cVar5 != '\0')) {
          return 0;
        }
        iVar13 = 0;
        do {
          *(undefined1 *)(iVar13 + (int)local_30) = 0;
          local_30[iVar13 + 1] = 0;
          *(char *)((int)local_1c + iVar13) = (char)iVar13;
          iVar13 = iVar13 + 1;
        } while (iVar13 != 4);
        iVar13 = FUN_0010b0f4(param_2,local_f0);
        local_10 = *(undefined4 *)(iVar13 + 0x10);
        local_e8 = 0;
        do {
          if (*(char *)((int)&local_10 + local_e8) != '\x04') {
            local_e0 = (int *)local_30[local_e8 + 1];
            if (piVar6 == local_e0) {
              if (local_e8 != *(byte *)((int)local_1c + local_e8)) goto LAB_0014a325;
              *(undefined1 *)(local_e8 + (int)local_30) = 1;
            }
            else if (local_e0 == (int *)0x0) {
              *(undefined1 *)(local_e8 + (int)local_30) = 1;
              local_30[local_e8 + 1] = (int)piVar6;
              *(char *)((int)local_1c + local_e8) = (char)local_e8;
            }
            else {
LAB_0014a325:
              pcVar10 = (char *)(local_e8 + (int)local_30);
              if (*pcVar10 != '\0') {
LAB_0014a3e3:
                bVar4 = false;
                goto LAB_0014a3ed;
              }
              local_e4 = (uint)*(byte *)((int)local_1c + local_e8);
              *pcVar10 = '\x01';
              local_30[local_e8 + 1] = (int)piVar6;
              *(char *)((int)local_1c + local_e8) = (char)local_e8;
              iVar13 = 0;
              do {
                if ((local_e0 == (int *)local_30[iVar13 + 1]) &&
                   (local_e4 == *(byte *)((int)local_1c + iVar13))) goto LAB_0014a863;
                iVar13 = iVar13 + 1;
              } while (iVar13 != 4);
              uVar15 = 0;
              local_110 = local_30;
              while( true ) {
                piVar16 = (int *)local_110[1];
                if (piVar16 == (int *)0x0) break;
                uVar8 = (uint)*(byte *)((int)local_1c + uVar15);
                uVar14 = local_e4;
                if ((uVar15 != uVar8) &&
                   ((iVar2 = piVar16[0x53], iVar13 = local_e0[0x53],
                    iVar2 != iVar13 && iVar13 <= iVar2 || ((iVar2 == iVar13 && (local_e4 < uVar8))))
                   )) {
                  local_110[1] = (int)local_e0;
                  *(undefined1 *)((int)local_1c + uVar15) = (undefined1)local_e4;
                  uVar14 = uVar8;
                  local_e0 = piVar16;
                }
                local_e4 = uVar14;
                uVar15 = uVar15 + 1;
                local_110 = local_110 + 1;
                if (uVar15 == 4) goto LAB_0014a3e3;
              }
              local_30[uVar15 + 1] = (int)local_e0;
              *(undefined1 *)((int)local_1c + uVar15) = (undefined1)local_e4;
            }
          }
LAB_0014a863:
          local_e8 = local_e8 + 1;
        } while (local_e8 != 4);
        bVar4 = true;
LAB_0014a3ed:
        iVar13 = FUN_0010b0f4(param_3,local_f0);
        local_10 = *(undefined4 *)(iVar13 + 0x10);
        local_dc = 0;
        do {
          if (*(char *)((int)&local_10 + local_dc) != '\x04') {
            piVar6 = (int *)local_30[local_dc + 1];
            if (piVar7 == piVar6) {
              if (*(byte *)((int)local_1c + local_dc) != local_dc) goto LAB_0014a451;
              *(undefined1 *)((int)local_30 + local_dc) = 1;
            }
            else if (piVar6 == (int *)0x0) {
              *(undefined1 *)(local_dc + (int)local_30) = 1;
              local_30[local_dc + 1] = (int)piVar7;
              *(char *)((int)local_1c + local_dc) = (char)local_dc;
            }
            else {
LAB_0014a451:
              pcVar10 = (char *)(local_dc + (int)local_30);
              if (*pcVar10 != '\0') {
LAB_0014a4f9:
                bVar3 = false;
                goto LAB_0014a4fb;
              }
              local_d8 = (uint)*(byte *)((int)local_1c + local_dc);
              *pcVar10 = '\x01';
              local_30[local_dc + 1] = (int)piVar7;
              *(char *)((int)local_1c + local_dc) = (char)local_dc;
              iVar13 = 0;
              do {
                if ((piVar6 == (int *)local_30[iVar13 + 1]) &&
                   (local_d8 == *(byte *)((int)local_1c + iVar13))) goto LAB_0014a828;
                iVar13 = iVar13 + 1;
              } while (iVar13 != 4);
              uVar15 = 0;
              while( true ) {
                piVar16 = (int *)local_30[uVar15 + 1];
                if (piVar16 == (int *)0x0) break;
                uVar8 = (uint)*(byte *)((int)local_1c + uVar15);
                uVar14 = local_d8;
                if ((uVar15 != uVar8) &&
                   ((iVar2 = piVar16[0x53], iVar13 = piVar6[0x53],
                    iVar2 != iVar13 && iVar13 <= iVar2 || ((iVar2 == iVar13 && (local_d8 < uVar8))))
                   )) {
                  local_30[uVar15 + 1] = (int)piVar6;
                  *(undefined1 *)((int)local_1c + uVar15) = (undefined1)local_d8;
                  piVar6 = piVar16;
                  uVar14 = uVar8;
                }
                local_d8 = uVar14;
                uVar15 = uVar15 + 1;
                if (uVar15 == 4) goto LAB_0014a4f9;
              }
              local_30[uVar15 + 1] = (int)piVar6;
              *(undefined1 *)((int)local_1c + uVar15) = (undefined1)local_d8;
            }
          }
LAB_0014a828:
          local_dc = local_dc + 1;
        } while (local_dc != 4);
        bVar3 = true;
LAB_0014a4fb:
        if (!bVar4) {
          return 0;
        }
        if (!bVar3) {
          return 0;
        }
        puVar11 = (undefined4 *)(param_1 + 0xc);
        uVar15 = *(uint *)(param_1 + 0x10);
        if (uVar15 == 0) {
          local_10c = *(undefined4 **)(param_1 + 0x18);
        }
        else {
          local_d4 = 0;
          local_10c = *(undefined4 **)(param_1 + 0x18);
          do {
            if (*(uint *)(param_1 + 0x10) <= local_d4) {
              uVar14 = local_d4 + 1;
              if (*(uint *)(param_1 + 0x14) < uVar14) {
                uVar8 = (*(uint *)(param_1 + 0x14) << 4) / 10;
                if (uVar8 < uVar14) {
                  uVar8 = uVar14;
                }
                *(uint *)(param_1 + 0x14) = uVar8;
                uVar9 = FUN_001a7bca(*puVar11,uVar8 << 5);
                *(undefined4 *)(param_1 + 0x18) = uVar9;
                if (*(int *)(param_1 + 0x10) != 0) {
                  local_c8 = 0;
                  iVar13 = 0;
                  puVar12 = local_10c;
                  do {
                    iVar2 = *(int *)(param_1 + 0x18);
                    *(undefined4 *)(iVar13 + iVar2) = *puVar12;
                    *(undefined4 *)(iVar13 + 4 + iVar2) = puVar12[1];
                    *(undefined4 *)(iVar13 + 8 + iVar2) = puVar12[2];
                    *(undefined4 *)(iVar13 + 0xc + iVar2) = puVar12[3];
                    *(undefined4 *)(iVar13 + 0x10 + iVar2) = puVar12[4];
                    *(undefined4 *)(iVar13 + 0x14 + iVar2) = puVar12[5];
                    *(undefined4 *)(iVar13 + 0x18 + iVar2) = puVar12[6];
                    *(undefined4 *)(iVar13 + 0x1c + iVar2) = puVar12[7];
                    local_c8 = local_c8 + 1;
                    iVar13 = iVar13 + 0x20;
                    puVar12 = puVar12 + 8;
                  } while (local_c8 < *(uint *)(param_1 + 0x10));
                }
                FUN_001a7aba(*puVar11,local_10c);
                local_10c = *(undefined4 **)(param_1 + 0x18);
              }
              *(uint *)(param_1 + 0x10) = uVar14;
            }
            piVar6 = local_10c + local_d4 * 8;
            if (piVar6[6] != 0) {
              local_c0 = 0;
              do {
                if (local_30[local_c0 + 1] != 0) {
                  iVar13 = 0;
                  piVar7 = piVar6;
                  while ((local_30[local_c0 + 1] != piVar7[1] ||
                         (*(char *)((int)local_1c + local_c0) !=
                          *(char *)((int)piVar6 + iVar13 + 0x14)))) {
                    iVar13 = iVar13 + 1;
                    piVar7 = piVar7 + 1;
                    if (iVar13 == 4) goto LAB_0014a693;
                  }
                  if ((iVar13 == -1) ||
                     ((*(char *)(local_c0 + (int)local_30) != '\0' &&
                      ((iVar13 != local_c0 || (*(char *)((int)piVar6 + iVar13) == '\0')))))) break;
                }
                local_c0 = local_c0 + 1;
                if (local_c0 == 4) goto LAB_0014a8d8;
              } while( true );
            }
LAB_0014a693:
            local_d4 = local_d4 + 1;
          } while (uVar15 != local_d4);
          local_b8 = 0;
          do {
            if (*(uint *)(param_1 + 0x10) <= local_b8) {
              uVar14 = local_b8 + 1;
              if (*(uint *)(param_1 + 0x14) < uVar14) {
                uVar8 = (*(uint *)(param_1 + 0x14) << 4) / 10;
                if (uVar8 < uVar14) {
                  uVar8 = uVar14;
                }
                *(uint *)(param_1 + 0x14) = uVar8;
                uVar9 = FUN_001a7bca(*puVar11,uVar8 << 5);
                *(undefined4 *)(param_1 + 0x18) = uVar9;
                if (*(int *)(param_1 + 0x10) != 0) {
                  local_ac = 0;
                  iVar13 = 0;
                  puVar12 = local_10c;
                  do {
                    iVar2 = *(int *)(param_1 + 0x18);
                    *(undefined4 *)(iVar13 + iVar2) = *puVar12;
                    *(undefined4 *)(iVar13 + 4 + iVar2) = puVar12[1];
                    *(undefined4 *)(iVar13 + 8 + iVar2) = puVar12[2];
                    *(undefined4 *)(iVar13 + 0xc + iVar2) = puVar12[3];
                    *(undefined4 *)(iVar13 + 0x10 + iVar2) = puVar12[4];
                    *(undefined4 *)(iVar13 + 0x14 + iVar2) = puVar12[5];
                    *(undefined4 *)(iVar13 + 0x18 + iVar2) = puVar12[6];
                    *(undefined4 *)(iVar13 + 0x1c + iVar2) = puVar12[7];
                    local_ac = local_ac + 1;
                    iVar13 = iVar13 + 0x20;
                    puVar12 = puVar12 + 8;
                  } while (local_ac < *(uint *)(param_1 + 0x10));
                }
                FUN_001a7aba(*puVar11,local_10c);
                local_10c = *(undefined4 **)(param_1 + 0x18);
              }
              *(uint *)(param_1 + 0x10) = uVar14;
            }
            piVar6 = local_10c + local_b8 * 8;
            iVar13 = 0;
            local_120 = piVar6;
            local_48 = piVar6;
            while (((*(char *)(iVar13 + (int)local_30) == (char)*local_48 &&
                    (local_120[1] == local_30[iVar13 + 1])) &&
                   (*(char *)((int)local_1c + iVar13) == *(char *)((int)piVar6 + iVar13 + 0x14)))) {
              iVar13 = iVar13 + 1;
              local_48 = (int *)((int)local_48 + 1);
              local_120 = local_120 + 1;
              if (iVar13 == 4) goto LAB_0014a8d8;
            }
            local_b8 = local_b8 + 1;
          } while (uVar15 != local_b8);
        }
        if (*(uint *)(param_1 + 0x10) <= uVar15) {
          uVar14 = uVar15 + 1;
          if (*(uint *)(param_1 + 0x14) < uVar14) {
            uVar8 = (*(uint *)(param_1 + 0x14) << 4) / 10;
            if (uVar8 < uVar14) {
              uVar8 = uVar14;
            }
            *(uint *)(param_1 + 0x14) = uVar8;
            uVar9 = FUN_001a7bca(*puVar11,uVar8 << 5);
            *(undefined4 *)(param_1 + 0x18) = uVar9;
            if (*(int *)(param_1 + 0x10) != 0) {
              local_9c = 0;
              iVar13 = 0;
              puVar12 = local_10c;
              do {
                iVar2 = *(int *)(param_1 + 0x18);
                *(undefined4 *)(iVar13 + iVar2) = *puVar12;
                *(undefined4 *)(iVar13 + 4 + iVar2) = puVar12[1];
                *(undefined4 *)(iVar13 + 8 + iVar2) = puVar12[2];
                *(undefined4 *)(iVar13 + 0xc + iVar2) = puVar12[3];
                *(undefined4 *)(iVar13 + 0x10 + iVar2) = puVar12[4];
                *(undefined4 *)(iVar13 + 0x14 + iVar2) = puVar12[5];
                *(undefined4 *)(iVar13 + 0x18 + iVar2) = puVar12[6];
                *(undefined4 *)(iVar13 + 0x1c + iVar2) = puVar12[7];
                local_9c = local_9c + 1;
                iVar13 = iVar13 + 0x20;
                puVar12 = puVar12 + 8;
              } while (local_9c < *(uint *)(param_1 + 0x10));
            }
            FUN_001a7aba(*puVar11,local_10c);
            local_10c = *(undefined4 **)(param_1 + 0x18);
          }
          *(uint *)(param_1 + 0x10) = uVar14;
        }
        piVar6 = local_10c + uVar15 * 8;
        local_14 = 0;
        local_1c[1] = 0;
        *piVar6 = local_30[0];
        piVar6[1] = local_30[1];
        piVar6[2] = local_30[2];
        piVar6[3] = local_30[3];
        piVar6[4] = local_30[4];
        piVar6[5] = local_1c[0];
        piVar6[6] = 0;
        piVar6[7] = 0;
LAB_0014a8d8:
        param_4[local_f0 + 1] = (int)piVar6;
        *param_4 = *param_4 + 1;
      }
    }
    local_f0 = local_f0 + -1;
  }
  if (0 < local_f0) {
    local_4c = param_4;
    local_98 = 1;
    do {
      piVar6 = (int *)FUN_0010b180(param_2,local_98);
      piVar7 = (int *)FUN_0010b180(param_3,local_98);
      if (piVar6 != piVar7) {
        cVar5 = (**(code **)(*piVar6 + 0x60))(piVar6);
        if (cVar5 != '\0') {
          return 0;
        }
        cVar5 = (**(code **)(*piVar7 + 0x60))(piVar7);
        if (cVar5 != '\0') {
          return 0;
        }
        iVar13 = 0;
        do {
          *(undefined1 *)(iVar13 + (int)local_30) = 0;
          local_30[iVar13 + 1] = 0;
          *(char *)((int)local_1c + iVar13) = (char)iVar13;
          iVar13 = iVar13 + 1;
        } while (iVar13 != 4);
        iVar13 = FUN_0010b0f4(param_2,local_98);
        uVar9 = *(undefined4 *)(iVar13 + 0x10);
        local_50 = 1;
        do {
          while (local_8c = (uint)(&bStack_11)[local_50], (&bStack_11)[local_50] != 4) {
            iVar13 = 0;
            do {
              if ((piVar6 == (int *)local_30[iVar13 + 1]) &&
                 (local_8c == *(byte *)((int)local_1c + iVar13))) goto LAB_00149faf;
              iVar13 = iVar13 + 1;
            } while (iVar13 != 4);
            uVar15 = 0;
            piVar16 = local_30;
            local_94 = piVar6;
            while( true ) {
              piVar1 = (int *)piVar16[1];
              if (piVar1 == (int *)0x0) break;
              uVar8 = (uint)*(byte *)((int)local_1c + uVar15);
              uVar14 = local_8c;
              if ((uVar15 != uVar8) &&
                 ((iVar2 = piVar1[0x53], iVar13 = local_94[0x53], iVar2 != iVar13 && iVar13 <= iVar2
                  || ((iVar2 == iVar13 && (local_8c < uVar8)))))) {
                piVar16[1] = (int)local_94;
                *(undefined1 *)((int)local_1c + uVar15) = (undefined1)local_8c;
                local_94 = piVar1;
                uVar14 = uVar8;
              }
              local_8c = uVar14;
              uVar15 = uVar15 + 1;
              piVar16 = piVar16 + 1;
              if (uVar15 == 4) {
                bVar4 = false;
                goto LAB_00149bb5;
              }
            }
            local_30[uVar15 + 1] = (int)local_94;
            *(undefined1 *)((int)local_1c + uVar15) = (undefined1)local_8c;
            local_50 = local_50 + 1;
            if (local_50 == 5) goto LAB_00149fbd;
          }
LAB_00149faf:
          local_50 = local_50 + 1;
        } while (local_50 != 5);
LAB_00149fbd:
        bVar4 = true;
LAB_00149bb5:
        local_10 = uVar9;
        iVar13 = FUN_0010b0f4(param_3,local_98);
        uVar9 = *(undefined4 *)(iVar13 + 0x10);
        local_54 = 1;
        do {
          while (local_88 = (uint)(&bStack_11)[local_54], (&bStack_11)[local_54] != 4) {
            iVar13 = 0;
            do {
              if ((piVar7 == (int *)local_30[iVar13 + 1]) &&
                 (local_88 == *(byte *)((int)local_1c + iVar13))) goto LAB_00149f86;
              iVar13 = iVar13 + 1;
            } while (iVar13 != 4);
            uVar15 = 0;
            piVar6 = local_30;
            local_90 = piVar7;
            while( true ) {
              piVar16 = (int *)piVar6[1];
              if (piVar16 == (int *)0x0) break;
              uVar8 = (uint)*(byte *)((int)local_1c + uVar15);
              uVar14 = local_88;
              if ((uVar15 != uVar8) &&
                 ((iVar2 = piVar16[0x53], iVar13 = local_90[0x53],
                  iVar2 != iVar13 && iVar13 <= iVar2 || ((iVar2 == iVar13 && (local_88 < uVar8))))))
              {
                piVar6[1] = (int)local_90;
                *(undefined1 *)((int)local_1c + uVar15) = (undefined1)local_88;
                local_90 = piVar16;
                uVar14 = uVar8;
              }
              local_88 = uVar14;
              uVar15 = uVar15 + 1;
              piVar6 = piVar6 + 1;
              if (uVar15 == 4) {
                bVar3 = false;
                goto LAB_00149c6f;
              }
            }
            local_30[uVar15 + 1] = (int)local_90;
            *(undefined1 *)((int)local_1c + uVar15) = (undefined1)local_88;
            local_54 = local_54 + 1;
            if (local_54 == 5) goto LAB_00149f94;
          }
LAB_00149f86:
          local_54 = local_54 + 1;
        } while (local_54 != 5);
LAB_00149f94:
        bVar3 = true;
LAB_00149c6f:
        if (!bVar4) {
          return 0;
        }
        if (!bVar3) {
          return 0;
        }
        puVar11 = (undefined4 *)(param_1 + 0xc);
        uVar15 = *(uint *)(param_1 + 0x10);
        local_10 = uVar9;
        if (uVar15 == 0) {
          local_108 = *(undefined4 **)(param_1 + 0x18);
        }
        else {
          local_80 = 0;
          local_108 = *(undefined4 **)(param_1 + 0x18);
          do {
            if (*(uint *)(param_1 + 0x10) <= local_80) {
              uVar14 = local_80 + 1;
              if (*(uint *)(param_1 + 0x14) < uVar14) {
                uVar8 = (*(uint *)(param_1 + 0x14) << 4) / 10;
                if (uVar8 < uVar14) {
                  uVar8 = uVar14;
                }
                *(uint *)(param_1 + 0x14) = uVar8;
                uVar9 = FUN_001a7bca(*puVar11,uVar8 << 5);
                *(undefined4 *)(param_1 + 0x18) = uVar9;
                if (*(int *)(param_1 + 0x10) != 0) {
                  uVar8 = 0;
                  iVar13 = 0;
                  puVar12 = local_108;
                  do {
                    iVar2 = *(int *)(param_1 + 0x18);
                    *(undefined4 *)(iVar13 + iVar2) = *puVar12;
                    *(undefined4 *)(iVar13 + 4 + iVar2) = puVar12[1];
                    *(undefined4 *)(iVar13 + 8 + iVar2) = puVar12[2];
                    *(undefined4 *)(iVar13 + 0xc + iVar2) = puVar12[3];
                    *(undefined4 *)(iVar13 + 0x10 + iVar2) = puVar12[4];
                    *(undefined4 *)(iVar13 + 0x14 + iVar2) = puVar12[5];
                    *(undefined4 *)(iVar13 + 0x18 + iVar2) = puVar12[6];
                    *(undefined4 *)(iVar13 + 0x1c + iVar2) = puVar12[7];
                    uVar8 = uVar8 + 1;
                    iVar13 = iVar13 + 0x20;
                    puVar12 = puVar12 + 8;
                  } while (uVar8 < *(uint *)(param_1 + 0x10));
                }
                FUN_001a7aba(*puVar11,local_108);
                local_108 = *(undefined4 **)(param_1 + 0x18);
              }
              *(uint *)(param_1 + 0x10) = uVar14;
            }
            piVar6 = local_108 + local_80 * 8;
            if (piVar6[6] != 0) {
              local_74 = 0;
              do {
                if (local_30[local_74 + 1] != 0) {
                  iVar13 = 0;
                  piVar7 = piVar6;
                  while ((local_30[local_74 + 1] != piVar7[1] ||
                         (*(char *)((int)local_1c + local_74) !=
                          *(char *)((int)piVar6 + iVar13 + 0x14)))) {
                    iVar13 = iVar13 + 1;
                    piVar7 = piVar7 + 1;
                    if (iVar13 == 4) goto LAB_00149dd8;
                  }
                  if ((iVar13 == -1) ||
                     ((*(char *)(local_74 + (int)local_30) != '\0' &&
                      ((iVar13 != local_74 || (*(char *)((int)piVar6 + iVar13) == '\0')))))) break;
                }
                local_74 = local_74 + 1;
                if (local_74 == 4) goto LAB_00149e79;
              } while( true );
            }
LAB_00149dd8:
            local_80 = local_80 + 1;
          } while (uVar15 != local_80);
          local_6c = 0;
          do {
            if (*(uint *)(param_1 + 0x10) <= local_6c) {
              uVar14 = local_6c + 1;
              if (*(uint *)(param_1 + 0x14) < uVar14) {
                uVar8 = (*(uint *)(param_1 + 0x14) << 4) / 10;
                if (uVar8 < uVar14) {
                  uVar8 = uVar14;
                }
                *(uint *)(param_1 + 0x14) = uVar8;
                uVar9 = FUN_001a7bca(*puVar11,uVar8 << 5);
                *(undefined4 *)(param_1 + 0x18) = uVar9;
                if (*(int *)(param_1 + 0x10) != 0) {
                  uVar8 = 0;
                  iVar13 = 0;
                  puVar12 = local_108;
                  do {
                    iVar2 = *(int *)(param_1 + 0x18);
                    *(undefined4 *)(iVar13 + iVar2) = *puVar12;
                    *(undefined4 *)(iVar13 + 4 + iVar2) = puVar12[1];
                    *(undefined4 *)(iVar13 + 8 + iVar2) = puVar12[2];
                    *(undefined4 *)(iVar13 + 0xc + iVar2) = puVar12[3];
                    *(undefined4 *)(iVar13 + 0x10 + iVar2) = puVar12[4];
                    *(undefined4 *)(iVar13 + 0x14 + iVar2) = puVar12[5];
                    *(undefined4 *)(iVar13 + 0x18 + iVar2) = puVar12[6];
                    *(undefined4 *)(iVar13 + 0x1c + iVar2) = puVar12[7];
                    uVar8 = uVar8 + 1;
                    iVar13 = iVar13 + 0x20;
                    puVar12 = puVar12 + 8;
                  } while (uVar8 < *(uint *)(param_1 + 0x10));
                }
                FUN_001a7aba(*puVar11,local_108);
                local_108 = *(undefined4 **)(param_1 + 0x18);
              }
              *(uint *)(param_1 + 0x10) = uVar14;
            }
            piVar6 = local_108 + local_6c * 8;
            iVar13 = 0;
            piVar7 = piVar6;
            local_120 = piVar6;
            while (((*(char *)(iVar13 + (int)local_30) == (char)*piVar7 &&
                    (local_120[1] == local_30[iVar13 + 1])) &&
                   (*(char *)((int)local_1c + iVar13) == *(char *)((int)piVar6 + iVar13 + 0x14)))) {
              iVar13 = iVar13 + 1;
              piVar7 = (int *)((int)piVar7 + 1);
              local_120 = local_120 + 1;
              if (iVar13 == 4) goto LAB_00149e79;
            }
            local_6c = local_6c + 1;
          } while (uVar15 != local_6c);
        }
        if (*(uint *)(param_1 + 0x10) <= uVar15) {
          uVar14 = uVar15 + 1;
          if (*(uint *)(param_1 + 0x14) < uVar14) {
            uVar8 = (*(uint *)(param_1 + 0x14) << 4) / 10;
            if (uVar8 < uVar14) {
              uVar8 = uVar14;
            }
            *(uint *)(param_1 + 0x14) = uVar8;
            uVar9 = FUN_001a7bca(*puVar11,uVar8 << 5);
            *(undefined4 *)(param_1 + 0x18) = uVar9;
            if (*(int *)(param_1 + 0x10) != 0) {
              uVar8 = 0;
              iVar13 = 0;
              puVar12 = local_108;
              do {
                iVar2 = *(int *)(param_1 + 0x18);
                *(undefined4 *)(iVar2 + iVar13) = *puVar12;
                *(undefined4 *)(iVar2 + 4 + iVar13) = puVar12[1];
                *(undefined4 *)(iVar2 + 8 + iVar13) = puVar12[2];
                *(undefined4 *)(iVar2 + 0xc + iVar13) = puVar12[3];
                *(undefined4 *)(iVar2 + 0x10 + iVar13) = puVar12[4];
                *(undefined4 *)(iVar2 + 0x14 + iVar13) = puVar12[5];
                *(undefined4 *)(iVar2 + 0x18 + iVar13) = puVar12[6];
                *(undefined4 *)(iVar2 + 0x1c + iVar13) = puVar12[7];
                uVar8 = uVar8 + 1;
                iVar13 = iVar13 + 0x20;
                puVar12 = puVar12 + 8;
              } while (uVar8 < *(uint *)(param_1 + 0x10));
            }
            FUN_001a7aba(*puVar11,local_108);
            local_108 = *(undefined4 **)(param_1 + 0x18);
          }
          *(uint *)(param_1 + 0x10) = uVar14;
        }
        piVar6 = local_108 + uVar15 * 8;
        local_14 = 0;
        local_1c[1] = 0;
        *piVar6 = local_30[0];
        piVar6[1] = local_30[1];
        piVar6[2] = local_30[2];
        piVar6[3] = local_30[3];
        piVar6[4] = local_30[4];
        piVar6[5] = local_1c[0];
        piVar6[6] = 0;
        piVar6[7] = 0;
LAB_00149e79:
        local_4c[2] = (int)piVar6;
        *param_4 = *param_4 + 1;
      }
      local_98 = local_98 + 1;
      local_4c = local_4c + 1;
    } while (local_98 <= local_f0);
  }
  iVar13 = 0;
  do {
    if (param_4[1] != 0) {
      piVar6 = (int *)(param_4[1] + 0x1c);
      *piVar6 = *piVar6 + 1;
    }
    iVar13 = iVar13 + 1;
    param_4 = param_4 + 1;
  } while (iVar13 != 5);
  return 1;
}

/* FUN_0014ab7a @ 0x14ab7a (608 bytes) */
int FUN_0014ab7a(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  FUN_001195a6(*param_1,param_2);
  FUN_001195a6(*param_1,param_3);
  iVar2 = FUN_0010b0f4(param_2,0);
  local_34 = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = FUN_0010b0f4(param_3,0);
  local_20[0] = *(undefined4 *)(iVar2 + 0x10);
  if (param_2 == param_3) {
    local_34 = DAT_001cc57c;
  }
  iVar2 = 0;
  pbVar4 = &STACKARG(0x10);
  pbVar5 = pbVar4;
  do {
    if (*(char *)((int)local_20 + iVar2) != '\x01') {
      *(char *)((int)&local_34 + (uint)*pbVar5) = *(char *)((int)local_20 + iVar2);
    }
    iVar2 = iVar2 + 1;
    pbVar5 = pbVar5 + 1;
  } while (iVar2 != 4);
  *(undefined4 *)(param_2 + 0x9c) = local_34;
  iVar2 = *(int *)(param_3 + 0x84);
  if ((*(byte *)(param_3 + 0x15) & 2) != 0) {
    iVar6 = FUN_0010b0f4(param_2,iVar2);
    local_2c = *(undefined4 *)(iVar6 + 0x10);
    iVar6 = FUN_0010b0f4(param_3,iVar2);
    local_30 = *(undefined4 *)(iVar6 + 0x10);
    if (param_2 == param_3) {
      local_2c = DAT_001cc570;
    }
    iVar6 = 1;
    pbVar5 = pbVar4;
    do {
      if (*(char *)((int)&local_34 + iVar6 + 3) != '\x04') {
        *(byte *)((int)&local_2c + (uint)*pbVar5) = *pbVar5;
      }
      uVar1 = local_2c;
      iVar6 = iVar6 + 1;
      pbVar5 = pbVar5 + 1;
    } while (iVar6 != 5);
    iVar6 = FUN_0010b0f4(param_2,iVar2);
    *(undefined4 *)(iVar6 + 0x10) = uVar1;
    iVar2 = iVar2 + -1;
  }
  if (0 < iVar2) {
    iVar6 = 1;
    do {
      iVar3 = FUN_0010b0f4(param_2,iVar6);
      local_30 = *(undefined4 *)(iVar3 + 0x10);
      iVar3 = FUN_0010b0f4(param_3,iVar6);
      local_2c = *(undefined4 *)(iVar3 + 0x10);
      if (param_2 == param_3) {
        local_30 = DAT_001cc570;
      }
      iVar3 = 1;
      pbVar5 = pbVar4;
      do {
        if (*(char *)((int)local_20 + iVar3 + -1) != '\x01') {
          *(undefined1 *)((int)&local_30 + (uint)*pbVar5) =
               *(undefined1 *)((int)&local_30 + iVar3 + 3);
        }
        uVar1 = local_30;
        iVar3 = iVar3 + 1;
        pbVar5 = pbVar5 + 1;
      } while (iVar3 != 5);
      iVar3 = FUN_0010b0f4(param_2,iVar6);
      *(undefined4 *)(iVar3 + 0x10) = uVar1;
      iVar6 = iVar6 + 1;
    } while (iVar6 <= iVar2);
  }
  local_24 = *(undefined4 *)(param_2 + 0xc);
  local_28 = *(undefined4 *)(param_3 + 0xc);
  if (param_2 == param_3) {
    local_24 = DAT_001cc578;
  }
  iVar2 = 1;
  do {
    if (*(char *)((int)&local_2c + iVar2 + 3) != '\0') {
      *(undefined1 *)((int)local_20 + (*pbVar4 - 4)) = 1;
    }
    iVar2 = iVar2 + 1;
    pbVar4 = pbVar4 + 1;
  } while (iVar2 != 5);
  *(undefined4 *)(param_2 + 0xc) = local_24;
  return;
}

/* FUN_0014adda @ 0x14adda (382 bytes) */
int FUN_0014adda(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_14;
  undefined4 local_10;
  
  FUN_001195a6(*param_1,param_2);
  iVar3 = FUN_0010b0f4(param_2,0);
  local_10 = *(undefined4 *)(iVar3 + 0x10);
  uVar1 = *(undefined1 *)((int)&local_10 + param_3);
  *(undefined1 *)((int)&local_10 + param_3) = *(undefined1 *)((int)&local_10 + param_4);
  *(undefined1 *)((int)&local_10 + param_4) = uVar1;
  *(undefined4 *)(param_2 + 0x9c) = local_10;
  iVar3 = *(int *)(param_2 + 0x84);
  if ((*(byte *)(param_2 + 0x15) & 2) != 0) {
    iVar5 = FUN_0010b0f4(param_2,iVar3);
    local_14 = *(undefined4 *)(iVar5 + 0x10);
    uVar1 = *(undefined1 *)((int)&local_14 + param_3);
    *(undefined1 *)((int)&local_14 + param_3) = *(undefined1 *)((int)&local_14 + param_4);
    *(undefined1 *)((int)&local_14 + param_4) = uVar1;
    if (*(char *)((int)&local_14 + param_3) != '\x04') {
      *(char *)((int)&local_14 + param_3) = (char)param_3;
    }
    if (*(char *)((int)&local_14 + param_4) != '\x04') {
      *(char *)((int)&local_14 + param_4) = (char)param_4;
    }
    uVar2 = local_14;
    iVar5 = FUN_0010b0f4(param_2,iVar3);
    *(undefined4 *)(iVar5 + 0x10) = uVar2;
    iVar3 = iVar3 + -1;
  }
  if (0 < iVar3) {
    iVar5 = 1;
    do {
      iVar4 = FUN_0010b0f4(param_2,iVar5);
      local_14 = *(undefined4 *)(iVar4 + 0x10);
      uVar1 = *(undefined1 *)((int)&local_14 + param_3);
      *(undefined1 *)((int)&local_14 + param_3) = *(undefined1 *)((int)&local_14 + param_4);
      *(undefined1 *)((int)&local_14 + param_4) = uVar1;
      uVar2 = local_14;
      iVar4 = FUN_0010b0f4(param_2,iVar5);
      *(undefined4 *)(iVar4 + 0x10) = uVar2;
      iVar5 = iVar5 + 1;
    } while (iVar5 <= iVar3);
    uVar1 = *(undefined1 *)(param_2 + 0xc + param_3);
    *(undefined1 *)(param_2 + 0xc + param_3) = *(undefined1 *)(param_2 + 0xc + param_4);
    *(undefined1 *)(param_2 + 0xc + param_4) = uVar1;
    return;
  }
  uVar1 = *(undefined1 *)(param_2 + 0xc + param_3);
  *(undefined1 *)(param_2 + 0xc + param_3) = *(undefined1 *)(param_2 + 0xc + param_4);
  *(undefined1 *)(param_2 + 0xc + param_4) = uVar1;
  return;
}

/* FUN_0014af58 @ 0x14af58 (353 bytes) */
int FUN_0014af58(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  uint *puVar5;
  uint local_24;
  uint local_20;
  
  if ((*(int *)(param_2[0x22] + 8) == 0x8e) ||
     (cVar1 = (**(code **)(*param_2 + 0x5c))(param_2), cVar1 != '\0')) {
    uVar2 = ((int (*)())FUN_00149888)(param_1,param_2);
    return uVar2;
  }
  local_24 = DAT_001cc578;
  puVar5 = (uint *)param_2[4];
  if (puVar5[1] != 0) {
    local_20 = 0;
    do {
      if (local_20 < *puVar5) {
        uVar2 = puVar5[1];
        if (uVar2 <= local_20) {
          _memset((void *)(puVar5[2] + uVar2 * 4),0,(local_20 - uVar2) * 4 + 4);
          puVar5[1] = local_20 + 1;
        }
        piVar3 = (int *)(puVar5[2] + local_20 * 4);
      }
      else {
        piVar3 = (int *)FUN_001a7f7c(puVar5,local_20);
      }
      local_20 = local_20 + 1;
      piVar3 = (int *)*piVar3;
      if (piVar3 != (int *)0x0) {
        if ((*(int *)(piVar3[0x22] + 8) == 0x8e) ||
           (cVar1 = (**(code **)(*piVar3 + 0x5c))(piVar3), cVar1 != '\0')) {
          uVar2 = ((int (*)())FUN_00149888)(param_1,piVar3);
          local_24 = local_24 | uVar2;
        }
        if ((*(byte *)((int)piVar3 + 0x15) & 2) == 0) {
          if (param_2 == (int *)0x0) {
LAB_0014b072:
            uVar2 = ((int (*)())FUN_001498ae)(param_1,piVar3);
            local_24 = local_24 | uVar2;
          }
        }
        else {
          piVar4 = (int *)FUN_0010b180(piVar3,piVar3[0x21]);
          if (piVar4 == param_2) goto LAB_0014b072;
        }
      }
      puVar5 = (uint *)param_2[4];
    } while (local_20 < puVar5[1]);
  }
  uVar2 = ((int (*)())FUN_00149888)(param_1,param_2);
  return uVar2 & local_24;
}

/* FUN_0014b0ba @ 0x14b0ba (1709 bytes) */
int FUN_0014b0ba(param_1, param_2, param_3, param_4)
  int *param_1;
  int *param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  char cVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint local_68;
  uint local_50;
  uint local_3c;
  int local_38;
  uint local_34;
  int local_30;
  uint local_28;
  uint local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  ((int (*)())FUN_0014af58)(param_1,param_2);
  if (param_3 == param_4) {
    return 1;
  }
  if ((*(int *)(param_2[0x22] + 8) == 0x8e) ||
     (cVar2 = (**(code **)(*param_2 + 0x5c))(param_2), cVar2 != '\0')) {
    return 0;
  }
  local_1c = *(undefined4 *)(*param_1 + 0xbc);
  local_24 = 0;
  local_28 = 2;
  local_20 = FUN_001a7bca(local_1c,8);
  puVar6 = (uint *)param_2[4];
  if (puVar6[1] != 0) {
    uVar11 = 0;
    local_34 = 1;
    local_30 = 0;
    do {
      local_68 = 0;
      do {
        while( true ) {
          if (local_68 < uVar11) {
            if (uVar11 < *puVar6) {
              uVar1 = puVar6[1];
              puVar7 = puVar6;
              if (uVar1 <= uVar11) {
                _memset((void *)(puVar6[2] + uVar1 * 4),0,(uVar11 - uVar1) * 4 + 4);
                puVar6[1] = local_34;
                puVar7 = (uint *)param_2[4];
              }
              piVar3 = (int *)(local_30 + puVar6[2]);
            }
            else {
              piVar3 = (int *)FUN_001a7f7c(puVar6,uVar11);
              puVar7 = (uint *)param_2[4];
            }
            iVar10 = *piVar3;
            if (local_68 < *puVar7) {
              uVar1 = puVar7[1];
              puVar6 = puVar7;
              if (uVar1 <= local_68) {
                _memset((void *)(puVar7[2] + uVar1 * 4),0,(local_68 - uVar1) * 4 + 4);
                puVar7[1] = local_68 + 1;
                puVar6 = (uint *)param_2[4];
              }
              piVar3 = (int *)(puVar7[2] + local_68 * 4);
            }
            else {
              piVar3 = (int *)FUN_001a7f7c(puVar7,local_68);
              puVar6 = (uint *)param_2[4];
            }
            if (iVar10 == *piVar3) goto LAB_0014b25e;
          }
          if (uVar11 == local_68) break;
LAB_0014b162:
          local_68 = local_68 + 1;
          if (uVar11 < local_68) goto LAB_0014b25e;
        }
        if (uVar11 < *puVar6) {
          uVar1 = puVar6[1];
          if (uVar1 <= uVar11) {
            _memset((void *)(puVar6[2] + uVar1 * 4),0,(uVar11 - uVar1) * 4 + 4);
            puVar6[1] = local_34;
          }
          piVar3 = *(int **)(local_30 + puVar6[2]);
        }
        else {
          puVar4 = (undefined4 *)FUN_001a7f7c(puVar6,uVar11);
          piVar3 = (int *)*puVar4;
        }
        if (piVar3 == (int *)0x0) {
          puVar6 = (uint *)param_2[4];
          goto LAB_0014b162;
        }
        if ((*(int *)(piVar3[0x22] + 8) == 0x8e) ||
           (cVar2 = (**(code **)(*piVar3 + 0x5c))(piVar3), cVar2 != '\0')) {
          local_10 = ((int (*)())FUN_00149888)(param_1,piVar3);
          if (*(char *)((int)&local_10 + param_3) != '\0') goto LAB_0014b5c3;
        }
        if ((*(byte *)((int)piVar3 + 0x15) & 2) == 0) {
          if (param_2 == (int *)0x0) {
LAB_0014b6c0:
            uVar1 = local_24;
            if (local_24 < local_28) {
              iVar10 = local_24 * 4;
              _memset((void *)(iVar10 + local_20),0,4);
              local_24 = uVar1 + 1;
              puVar4 = (undefined4 *)(iVar10 + local_20);
            }
            else {
              puVar4 = (undefined4 *)FUN_001a7f7c(&local_28,local_24);
            }
            *puVar4 = piVar3;
            puVar6 = (uint *)param_2[4];
            goto LAB_0014b162;
          }
        }
        else {
          piVar5 = (int *)FUN_0010b180(piVar3,piVar3[0x21]);
          if (piVar5 == param_2) goto LAB_0014b6c0;
        }
        puVar6 = (uint *)param_2[4];
        local_68 = local_68 + 1;
      } while (local_68 <= uVar11);
LAB_0014b25e:
      uVar11 = uVar11 + 1;
      local_34 = local_34 + 1;
      local_30 = local_30 + 4;
    } while (uVar11 < puVar6[1]);
  }
  while (local_24 != 0) {
    uVar11 = local_24 - 1;
    if (uVar11 < local_24) {
      piVar3 = (int *)(local_20 + uVar11 * 4);
    }
    else {
      piVar3 = (int *)0x0;
    }
    iVar10 = *piVar3;
    FUN_001a7f3c(&local_28,uVar11);
    local_10 = ((int (*)())FUN_0014af58)(param_1,iVar10);
    local_14 = ((int (*)())FUN_001498ae)(param_1,iVar10);
    if (*(char *)((int)&local_14 + param_3) != '\0') {
      cVar2 = FUN_001195a6(*param_1,iVar10);
      if (((cVar2 == '\0') || (*(char *)((int)&local_14 + param_4) != '\0')) ||
         (*(char *)((int)&local_10 + param_4) != '\0')) goto LAB_0014b5c3;
      puVar6 = *(uint **)(iVar10 + 0x10);
      if (puVar6[1] != 0) {
        uVar11 = 0;
        local_3c = 1;
        local_38 = 0;
        do {
          local_50 = 0;
          do {
            while( true ) {
              if (local_50 < uVar11) {
                if (uVar11 < *puVar6) {
                  uVar1 = puVar6[1];
                  puVar7 = puVar6;
                  if (uVar1 <= uVar11) {
                    _memset((void *)(puVar6[2] + uVar1 * 4),0,(uVar11 - uVar1) * 4 + 4);
                    puVar6[1] = local_3c;
                    puVar7 = *(uint **)(iVar10 + 0x10);
                  }
                  piVar3 = (int *)(local_38 + puVar6[2]);
                }
                else {
                  piVar3 = (int *)FUN_001a7f7c(puVar6,uVar11);
                  puVar7 = *(uint **)(iVar10 + 0x10);
                }
                iVar8 = *piVar3;
                if (local_50 < *puVar7) {
                  uVar1 = puVar7[1];
                  puVar6 = puVar7;
                  if (uVar1 <= local_50) {
                    _memset((void *)(puVar7[2] + uVar1 * 4),0,(local_50 - uVar1) * 4 + 4);
                    puVar7[1] = local_50 + 1;
                    puVar6 = *(uint **)(iVar10 + 0x10);
                  }
                  piVar3 = (int *)(puVar7[2] + local_50 * 4);
                }
                else {
                  piVar3 = (int *)FUN_001a7f7c(puVar7,local_50);
                  puVar6 = *(uint **)(iVar10 + 0x10);
                }
                if (iVar8 == *piVar3) goto LAB_0014b430;
              }
              if (uVar11 == local_50) break;
LAB_0014b334:
              local_50 = local_50 + 1;
              if (uVar11 < local_50) goto LAB_0014b430;
            }
            if (uVar11 < *puVar6) {
              uVar1 = puVar6[1];
              if (uVar1 <= uVar11) {
                _memset((void *)(puVar6[2] + uVar1 * 4),0,(uVar11 - uVar1) * 4 + 4);
                puVar6[1] = local_3c;
              }
              piVar3 = *(int **)(local_38 + puVar6[2]);
            }
            else {
              puVar4 = (undefined4 *)FUN_001a7f7c(puVar6,uVar11);
              piVar3 = (int *)*puVar4;
            }
            if (piVar3 == (int *)0x0) {
              puVar6 = *(uint **)(iVar10 + 0x10);
              goto LAB_0014b334;
            }
            if ((*(int *)(piVar3[0x22] + 8) == 0x8e) ||
               (cVar2 = (**(code **)(*piVar3 + 0x5c))(piVar3), cVar2 != '\0')) {
              local_18 = ((int (*)())FUN_00149888)(param_1,piVar3);
              if (*(char *)((int)&local_18 + param_3) != '\0') goto LAB_0014b5c3;
            }
            if ((*(byte *)((int)piVar3 + 0x15) & 2) == 0) {
              if (iVar10 == 0) {
LAB_0014b529:
                uVar1 = local_24;
                if (local_24 < local_28) {
                  iVar8 = local_24 * 4;
                  _memset((void *)(iVar8 + local_20),0,4);
                  local_24 = uVar1 + 1;
                  puVar4 = (undefined4 *)(iVar8 + local_20);
                }
                else {
                  puVar4 = (undefined4 *)FUN_001a7f7c(&local_28,local_24);
                }
                *puVar4 = piVar3;
                puVar6 = *(uint **)(iVar10 + 0x10);
                goto LAB_0014b334;
              }
            }
            else {
              iVar8 = FUN_0010b180(piVar3,piVar3[0x21]);
              if (iVar8 == iVar10) goto LAB_0014b529;
            }
            puVar6 = *(uint **)(iVar10 + 0x10);
            local_50 = local_50 + 1;
          } while (local_50 <= uVar11);
LAB_0014b430:
          uVar11 = uVar11 + 1;
          local_3c = local_3c + 1;
          local_38 = local_38 + 4;
        } while (uVar11 < puVar6[1]);
      }
    }
  }
  uVar9 = 1;
LAB_0014b5c5:
  FUN_001a7aba(local_1c,local_20);
  return uVar9;
LAB_0014b5c3:
  uVar9 = 0;
  goto LAB_0014b5c5;
}

/* FUN_0014b784 @ 0x14b784 (1654 bytes) */
int FUN_0014b784(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined1 uVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int *local_a8;
  int local_74;
  int local_70;
  undefined4 *local_6c;
  undefined4 *local_68;
  undefined4 *local_64;
  undefined4 *local_60;
  int local_50 [4];
  uint local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  uint local_28;
  uint local_24;
  undefined1 local_20 [16];
  
  uVar4 = ((int (*)())FUN_00149888)(param_1,param_2);
  local_28 = ((int (*)())FUN_0014af58)(param_1,param_2);
  local_2c = ((int (*)())FUN_001498ae)(param_1,param_2);
  uVar5 = ((int (*)())FUN_00149888)(param_1,param_3);
  local_30 = ((int (*)())FUN_0014af58)(param_1,param_3);
  local_34 = ((int (*)())FUN_001498ae)(param_1,param_3);
  uVar2 = DAT_001cc574;
  local_38 = DAT_001cc578;
  local_3c = DAT_001cc578;
  *param_4 = DAT_001cc574;
  *param_5 = uVar2;
  if ((*(byte *)(param_2 + 0x15) & 2) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_0010b180(param_2,*(undefined4 *)(param_2 + 0x84));
  }
  if (iVar6 != param_3) {
    iVar6 = 0;
    do {
      if (*(char *)((int)&local_2c + iVar6) != '\0') {
        *(undefined1 *)((int)&local_38 + iVar6) = 0;
        *(undefined1 *)((int)&local_3c + iVar6) = 1;
        local_50[iVar6] = param_2;
        local_20[iVar6] = (char)iVar6;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != 4);
  }
  if ((*(byte *)(param_3 + 0x15) & 2) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_0010b180(param_3,*(undefined4 *)(param_3 + 0x84));
  }
  if (iVar6 != param_2) {
    iVar6 = 0;
    do {
      if (*(char *)((int)&local_34 + iVar6) != '\0') {
        if (*(char *)((int)&local_3c + iVar6) == '\0') {
          *(undefined1 *)((int)&local_38 + iVar6) = 0;
          *(char *)((int)&local_3c + iVar6) = '\x01';
          local_50[iVar6] = param_3;
          local_20[iVar6] = (char)iVar6;
        }
        else {
          if ((*(byte *)(param_3 + 0x15) & 2) == 0) {
            iVar11 = 0;
          }
          else {
            iVar11 = FUN_0010b180(param_3,*(undefined4 *)(param_3 + 0x84));
          }
          if ((*(byte *)(param_2 + 0x15) & 2) == 0) {
            iVar9 = 0;
          }
          else {
            iVar9 = FUN_0010b180(param_2,*(undefined4 *)(param_2 + 0x84));
          }
          if (iVar11 != iVar9) {
            return 0;
          }
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != 4);
  }
  local_60 = param_4;
  iVar6 = 0;
  do {
    if (*(char *)((int)&local_28 + iVar6) != '\0') {
      uVar7 = (undefined1)iVar6;
      if (*(char *)((int)&local_3c + iVar6) == '\0') {
        *(undefined1 *)((int)&local_38 + iVar6) = 1;
        *(char *)((int)&local_3c + iVar6) = '\x01';
        local_50[iVar6] = param_2;
        local_20[iVar6] = uVar7;
        *(undefined1 *)local_60 = uVar7;
      }
      else {
        iVar11 = 0;
        if ((char)local_3c == '\0') goto LAB_0014bac0;
        do {
          do {
            iVar9 = iVar11 + 1;
            if (iVar9 == 4) {
              return 0;
            }
            iVar1 = iVar11 + 1;
            iVar11 = iVar9;
          } while (*(char *)((int)&local_3c + iVar1) != '\0');
LAB_0014bac0:
          cVar3 = ((int (*)())FUN_0014b0ba)(param_1,param_2,iVar6,iVar11);
        } while (cVar3 == '\0');
        *(undefined1 *)((int)&local_38 + iVar11) = 1;
        *(undefined1 *)((int)&local_3c + iVar11) = 1;
        local_50[iVar11] = param_2;
        local_20[iVar11] = uVar7;
        *(char *)local_60 = (char)iVar11;
      }
    }
    iVar6 = iVar6 + 1;
    local_60 = (undefined4 *)((int)local_60 + 1);
  } while (iVar6 != 4);
  if ((*(byte *)(param_3 + 0x15) & 2) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_0010b180(param_3,*(undefined4 *)(param_3 + 0x84));
  }
  if (iVar6 == param_2) {
    iVar6 = 0;
    puVar8 = param_5;
    do {
      if (*(char *)((int)&local_34 + iVar6) != '\0') {
        *(undefined1 *)puVar8 = *(undefined1 *)((int)param_4 + iVar6);
      }
      iVar6 = iVar6 + 1;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    } while (iVar6 != 4);
  }
  local_64 = param_5;
  iVar6 = 0;
  local_a8 = local_50;
  do {
    if (*(char *)((int)&local_30 + iVar6) != '\0') {
      uVar7 = (undefined1)iVar6;
      if (*(char *)((int)&local_3c + iVar6) == '\0') {
        *(undefined1 *)((int)&local_38 + iVar6) = 1;
        *(char *)((int)&local_3c + iVar6) = '\x01';
        *local_a8 = param_3;
        local_20[iVar6] = uVar7;
        *(undefined1 *)local_64 = uVar7;
      }
      else if ((*(char *)((int)&local_38 + iVar6) == '\0') ||
              (cVar3 = ((int (*)())FUN_001498e6)(param_1,*local_a8,local_20[iVar6],param_3,iVar6), cVar3 == '\0')
              ) {
        iVar11 = 0;
        if ((char)local_3c == '\0') goto LAB_0014bb66;
        do {
          do {
            iVar9 = iVar11 + 1;
            if (iVar9 == 4) {
              return 0;
            }
            iVar1 = iVar11 + 1;
            iVar11 = iVar9;
          } while (*(char *)((int)&local_3c + iVar1) != '\0');
LAB_0014bb66:
          cVar3 = ((int (*)())FUN_0014b0ba)(param_1,param_3,iVar6,iVar11);
        } while (cVar3 == '\0');
        *(undefined1 *)((int)&local_38 + iVar11) = 1;
        *(undefined1 *)((int)&local_3c + iVar11) = 1;
        local_50[iVar11] = param_3;
        local_20[iVar11] = uVar7;
        *(char *)local_64 = (char)iVar11;
      }
    }
    iVar6 = iVar6 + 1;
    local_a8 = local_a8 + 1;
    local_64 = (undefined4 *)((int)local_64 + 1);
  } while (iVar6 != 4);
  if ((*(byte *)(param_2 + 0x15) & 2) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_0010b180(param_2,*(undefined4 *)(param_2 + 0x84));
  }
  if (iVar6 == param_3) {
    iVar6 = 0;
    puVar8 = param_4;
    do {
      if (*(char *)((int)&local_2c + iVar6) != '\0') {
        *(undefined1 *)puVar8 = *(undefined1 *)((int)param_5 + iVar6);
      }
      iVar6 = iVar6 + 1;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    } while (iVar6 != 4);
  }
  uVar10 = ~local_28;
  local_68 = param_4;
  local_74 = 0;
  do {
    local_24 = uVar4 & uVar10;
    if (local_20[local_74 + -4] != '\0') {
      iVar6 = 0;
      do {
        if ((*(char *)((int)&local_38 + iVar6) != '\0') &&
           (cVar3 = ((int (*)())FUN_001498e6)(param_1,local_50[iVar6],local_20[iVar6],param_2,local_74),
           cVar3 != '\0')) {
          *(char *)local_68 = (char)iVar6;
          goto LAB_0014bc68;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 != 4);
      iVar6 = 0;
      while (*(char *)((int)&local_3c + iVar6) != '\0') {
        iVar6 = iVar6 + 1;
        if (iVar6 == 4) {
          return 0;
        }
      }
      *(undefined1 *)((int)&local_38 + iVar6) = 1;
      *(undefined1 *)((int)&local_3c + iVar6) = 1;
      local_50[iVar6] = param_2;
      local_20[iVar6] = (undefined1)local_74;
      *(char *)local_68 = (char)iVar6;
    }
LAB_0014bc68:
    local_74 = local_74 + 1;
    local_68 = (undefined4 *)((int)local_68 + 1);
  } while (local_74 != 4);
  uVar4 = ~local_30;
  local_6c = param_5;
  local_70 = 0;
  do {
    local_40 = uVar5 & uVar4;
    if (*(char *)((int)&local_40 + local_70) != '\0') {
      iVar6 = 0;
      do {
        if ((*(char *)((int)&local_38 + iVar6) != '\0') &&
           (cVar3 = ((int (*)())FUN_001498e6)(param_1,local_50[iVar6],local_20[iVar6],param_3,local_70),
           cVar3 != '\0')) {
          *(char *)local_6c = (char)iVar6;
          goto LAB_0014bd71;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 != 4);
      iVar6 = 0;
      while (*(char *)((int)&local_3c + iVar6) != '\0') {
        iVar6 = iVar6 + 1;
        if (iVar6 == 4) {
          return 0;
        }
      }
      *(undefined1 *)((int)&local_38 + iVar6) = 1;
      *(undefined1 *)((int)&local_3c + iVar6) = 1;
      local_50[iVar6] = param_3;
      local_20[iVar6] = (undefined1)local_70;
      *(char *)local_6c = (char)iVar6;
    }
LAB_0014bd71:
    local_70 = local_70 + 1;
    local_6c = (undefined4 *)((int)local_6c + 1);
    if (local_70 == 4) {
      return 1;
    }
  } while( true );
}

/* FUN_0014bdfa @ 0x14bdfa (76 bytes) */
int FUN_0014bdfa(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined1 uVar1;
  
  FUN_00149350(param_1,param_2,param_3);
  uVar1 = ((int (*)())FUN_0014b784)(param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}

/* FUN_0014be46 @ 0x14be46 (167 bytes) */
int FUN_0014be46(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  char cVar1;
  
  *param_4 = param_2;
  param_4[1] = param_3;
  cVar1 = FUN_00149350(param_1,param_2,param_3);
  if ((((cVar1 != '\0') &&
       (cVar1 = ((int (*)())FUN_0014bdfa)(param_1,param_2,param_3,param_4 + 2,param_4 + 3), cVar1 != '\0')) &&
      (cVar1 = ((int (*)())FUN_00149814)(param_1,param_2,param_3,param_4 + 4), cVar1 != '\0')) &&
     (cVar1 = ((int (*)())FUN_001499a8)(param_1,param_2,param_3,param_4 + 5), cVar1 != '\0')) {
    return 1;
  }
  return 0;
}

/* FUN_0014beee @ 0x14beee (2076 bytes) */
int FUN_0014beee(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint local_90;
  int local_80;
  uint local_7c;
  byte *local_64;
  uint local_60;
  int local_5c;
  uint local_58;
  int local_54;
  uint local_44;
  uint local_40;
  int local_3c;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20 [4];
  
  local_28 = *(undefined4 *)(*param_1 + 0xbc);
  local_30 = 0;
  local_34 = 2;
  local_2c = FUN_001a7bca(local_28,8);
  local_38 = *(undefined4 *)(*param_1 + 0xbc);
  local_40 = 0;
  local_44 = 2;
  local_3c = FUN_001a7bca(local_38,8);
  uVar13 = local_30;
  if (local_30 < local_34) {
    iVar1 = local_30 * 4;
    _memset((void *)(iVar1 + local_2c),0,4);
    local_30 = uVar13 + 1;
    puVar6 = (undefined4 *)(iVar1 + local_2c);
  }
  else {
    puVar6 = (undefined4 *)FUN_001a7f7c(&local_34,local_30);
  }
  uVar13 = local_40;
  iVar1 = param_3;
  *puVar6 = param_2;
  if (local_40 < local_44) {
    iVar12 = local_40 * 4;
    _memset((void *)(iVar12 + local_3c),0,4);
    local_40 = uVar13 + 1;
    piVar3 = (int *)(iVar12 + local_3c);
  }
  else {
    piVar3 = (int *)FUN_001a7f7c(&local_44,local_40);
  }
  *piVar3 = iVar1;
  do {
    do {
      do {
        if (local_30 == 0) {
          FUN_001a7aba(local_38,local_3c);
          FUN_001a7aba(local_28,local_2c);
          return;
        }
        uVar13 = local_30 - 1;
        if (uVar13 < local_30) {
          piVar3 = (int *)(local_2c + uVar13 * 4);
        }
        else {
          piVar3 = (int *)0x0;
        }
        iVar1 = *piVar3;
        FUN_001a7f3c(&local_34,uVar13);
        uVar13 = local_40 - 1;
        if (uVar13 < local_40) {
          piVar3 = (int *)(local_3c + uVar13 * 4);
        }
        else {
          piVar3 = (int *)0x0;
        }
        iVar12 = *piVar3;
        FUN_001a7f3c(&local_44,uVar13);
        param_3 = iVar12;
      } while (iVar12 == DAT_001cc574);
      puVar8 = *(uint **)(iVar1 + 0x10);
      if (puVar8[1] != 0) {
        uVar13 = 0;
        local_58 = 1;
        local_54 = 0;
        do {
          local_90 = 0;
          do {
            while( true ) {
              if (local_90 < uVar13) {
                if (uVar13 < *puVar8) {
                  uVar10 = puVar8[1];
                  puVar9 = puVar8;
                  if (uVar10 <= uVar13) {
                    _memset((void *)(puVar8[2] + uVar10 * 4),0,(uVar13 - uVar10) * 4 + 4);
                    puVar8[1] = local_58;
                    puVar9 = *(uint **)(iVar1 + 0x10);
                  }
                  piVar3 = (int *)(local_54 + puVar8[2]);
                }
                else {
                  piVar3 = (int *)FUN_001a7f7c(puVar8,uVar13);
                  puVar9 = *(uint **)(iVar1 + 0x10);
                }
                iVar12 = *piVar3;
                if (local_90 < *puVar9) {
                  uVar10 = puVar9[1];
                  puVar8 = puVar9;
                  if (uVar10 <= local_90) {
                    _memset((void *)(puVar9[2] + uVar10 * 4),0,(local_90 - uVar10) * 4 + 4);
                    puVar9[1] = local_90 + 1;
                    puVar8 = *(uint **)(iVar1 + 0x10);
                  }
                  piVar3 = (int *)(puVar9[2] + local_90 * 4);
                }
                else {
                  piVar3 = (int *)FUN_001a7f7c(puVar9,local_90);
                  puVar8 = *(uint **)(iVar1 + 0x10);
                }
                if (iVar12 == *piVar3) goto LAB_0014c4fd;
              }
              if (uVar13 == local_90) break;
LAB_0014c40f:
              local_90 = local_90 + 1;
              if (uVar13 < local_90) goto LAB_0014c4fd;
            }
            if (uVar13 < *puVar8) {
              uVar10 = puVar8[1];
              if (uVar10 <= uVar13) {
                _memset((void *)(puVar8[2] + uVar10 * 4),0,(uVar13 - uVar10) * 4 + 4);
                puVar8[1] = local_58;
              }
              iVar12 = *(int *)(local_54 + puVar8[2]);
            }
            else {
              piVar3 = (int *)FUN_001a7f7c(puVar8,uVar13);
              iVar12 = *piVar3;
            }
            if (iVar12 == 0) {
              puVar8 = *(uint **)(iVar1 + 0x10);
              goto LAB_0014c40f;
            }
            iVar11 = *(int *)(iVar12 + 0x84) + -1 + (uint)((*(uint *)(iVar12 + 0x14) & 0x200) == 0);
            if (0 < iVar11) {
              local_80 = 1;
              do {
                iVar4 = FUN_0010b180(iVar12,local_80);
                if (iVar1 == iVar4) {
                  iVar4 = FUN_0010b0f4(iVar12,local_80);
                  iVar4 = *(int *)(iVar4 + 0x10);
                  iVar7 = 1;
                  do {
                    bVar2 = *(byte *)((int)local_20 + iVar7 + -1);
                    if (bVar2 != 4) {
                      *(undefined1 *)((int)local_20 + iVar7 + -1) =
                           *(undefined1 *)((int)&param_3 + (uint)bVar2);
                    }
                    iVar7 = iVar7 + 1;
                  } while (iVar7 != 5);
                  local_20[0] = iVar4;
                  iVar7 = FUN_0010b0f4(iVar12,local_80);
                  *(int *)(iVar7 + 0x10) = iVar4;
                }
                local_80 = local_80 + 1;
              } while (local_80 <= iVar11);
              puVar8 = *(uint **)(iVar1 + 0x10);
              goto LAB_0014c40f;
            }
            puVar8 = *(uint **)(iVar1 + 0x10);
            local_90 = local_90 + 1;
          } while (local_90 <= uVar13);
LAB_0014c4fd:
          uVar13 = uVar13 + 1;
          local_58 = local_58 + 1;
          local_54 = local_54 + 4;
        } while (uVar13 < puVar8[1]);
      }
    } while (puVar8[1] == 0);
    local_7c = 0;
    local_60 = 1;
    local_5c = 0;
    do {
      uVar13 = 0;
      do {
        while( true ) {
          if (uVar13 < local_7c) {
            if (local_7c < *puVar8) {
              uVar10 = puVar8[1];
              puVar9 = puVar8;
              if (uVar10 <= local_7c) {
                _memset((void *)(puVar8[2] + uVar10 * 4),0,(local_7c - uVar10) * 4 + 4);
                puVar8[1] = local_60;
                puVar9 = *(uint **)(iVar1 + 0x10);
              }
              piVar3 = (int *)(local_5c + puVar8[2]);
            }
            else {
              piVar3 = (int *)FUN_001a7f7c(puVar8,local_7c);
              puVar9 = *(uint **)(iVar1 + 0x10);
            }
            iVar12 = *piVar3;
            if (uVar13 < *puVar9) {
              uVar10 = puVar9[1];
              puVar8 = puVar9;
              if (uVar10 <= uVar13) {
                _memset((void *)(puVar9[2] + uVar10 * 4),0,(uVar13 - uVar10) * 4 + 4);
                puVar9[1] = uVar13 + 1;
                puVar8 = *(uint **)(iVar1 + 0x10);
              }
              piVar3 = (int *)(puVar9[2] + uVar13 * 4);
            }
            else {
              piVar3 = (int *)FUN_001a7f7c(puVar9,uVar13);
              puVar8 = *(uint **)(iVar1 + 0x10);
            }
            if (iVar12 == *piVar3) goto LAB_0014c142;
          }
          if (local_7c == uVar13) break;
LAB_0014c087:
          uVar13 = uVar13 + 1;
          if (local_7c < uVar13) goto LAB_0014c142;
        }
        if (local_7c < *puVar8) {
          uVar10 = puVar8[1];
          if (uVar10 <= local_7c) {
            _memset((void *)(puVar8[2] + uVar10 * 4),0,(local_7c - uVar10) * 4 + 4);
            puVar8[1] = local_60;
          }
          iVar12 = *(int *)(local_5c + puVar8[2]);
        }
        else {
          piVar3 = (int *)FUN_001a7f7c(puVar8,local_7c);
          iVar12 = *piVar3;
        }
        if (iVar12 == 0) {
          puVar8 = *(uint **)(iVar1 + 0x10);
          goto LAB_0014c087;
        }
        if ((*(byte *)(iVar12 + 0x15) & 2) == 0) {
          if (iVar1 == 0) {
LAB_0014c277:
            local_20[0] = DAT_001cc574;
            local_24 = ((int (*)())FUN_001498ae)(param_1,iVar12);
            uVar10 = 0;
            local_64 = (byte *)&param_3;
            do {
              if (*(char *)((int)local_20 + (uVar10 - 4)) != '\0') {
                bVar2 = *local_64;
                uVar5 = (uint)bVar2;
                if (uVar5 != uVar10) {
                  ((int (*)())FUN_0014adda)(param_1,iVar12,uVar10,uVar5);
                  *(byte *)((int)local_20 + uVar10) = bVar2;
                  *(char *)((int)local_20 + uVar5) = (char)uVar10;
                }
              }
              uVar5 = local_30;
              uVar10 = uVar10 + 1;
              local_64 = local_64 + 1;
            } while (uVar10 != 4);
            if (local_30 < local_34) {
              iVar11 = local_30 * 4;
              _memset((void *)(iVar11 + local_2c),0,4);
              local_30 = uVar5 + 1;
              piVar3 = (int *)(iVar11 + local_2c);
            }
            else {
              piVar3 = (int *)FUN_001a7f7c(&local_34,local_30);
            }
            iVar11 = local_20[0];
            uVar10 = local_40;
            *piVar3 = iVar12;
            if (local_40 < local_44) {
              iVar12 = local_40 * 4;
              _memset((void *)(iVar12 + local_3c),0,4);
              local_40 = uVar10 + 1;
              piVar3 = (int *)(iVar12 + local_3c);
            }
            else {
              piVar3 = (int *)FUN_001a7f7c(&local_44,local_40);
            }
            *piVar3 = iVar11;
            puVar8 = *(uint **)(iVar1 + 0x10);
            goto LAB_0014c087;
          }
        }
        else {
          iVar11 = FUN_0010b180(iVar12,*(undefined4 *)(iVar12 + 0x84));
          if (iVar11 == iVar1) goto LAB_0014c277;
        }
        puVar8 = *(uint **)(iVar1 + 0x10);
        uVar13 = uVar13 + 1;
      } while (uVar13 <= local_7c);
LAB_0014c142:
      local_7c = local_7c + 1;
      local_60 = local_60 + 1;
      local_5c = local_5c + 4;
    } while (local_7c < puVar8[1]);
  } while( true );
}

/* FUN_0014c73c @ 0x14c73c (621 bytes) */
int FUN_0014c73c(param_1, param_2)
  undefined4 *param_1;
  int *param_2;
{
  int iVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  int local_1c;
  int local_18;
  uint local_10;
  
  piVar5 = param_2 + 5;
  local_1c = *param_2;
  local_18 = param_2[1];
  if ((char)param_2[4] != '\0') {
    local_1c = param_2[1];
    local_18 = *param_2;
  }
  cVar3 = FUN_000e1402(*param_1,0x30);
  if (cVar3 != '\0') {
    iVar9 = ((int (*)())FUN_00149888)(param_1,local_1c);
    if (iVar9 == 0x1000000) {
      return -1;
    }
    iVar9 = ((int (*)())FUN_00149888)(param_1,local_18);
    if (iVar9 == 0x1000000) {
      return -1;
    }
  }
  puVar8 = *(uint **)(local_1c + 0x10);
  if (puVar8[1] != 0) {
    local_10 = 0;
    do {
      if (local_10 < *puVar8) {
        uVar10 = puVar8[1];
        if (uVar10 <= local_10) {
          _memset((void *)(puVar8[2] + uVar10 * 4),0,(local_10 - uVar10) * 4 + 4);
          puVar8[1] = local_10 + 1;
        }
        piVar4 = (int *)(puVar8[2] + local_10 * 4);
      }
      else {
        piVar4 = (int *)FUN_001a7f7c(puVar8,local_10);
      }
      iVar9 = *piVar4;
      if (((iVar9 != 0) &&
          ((*(int *)(*(int *)(iVar9 + 0x88) + 8) == 0x8e ||
           (((local_18 != iVar9 && ((*(byte *)(iVar9 + 0x15) & 2) != 0)) &&
            (iVar9 = FUN_0010b180(iVar9,*(undefined4 *)(iVar9 + 0x84)), local_1c == iVar9)))))) &&
         (puVar8 = *(uint **)(local_18 + 0x10), puVar8[1] != 0)) {
        uVar10 = 0;
        do {
          if (uVar10 < *puVar8) {
            uVar2 = puVar8[1];
            if (uVar2 <= uVar10) {
              _memset((void *)(puVar8[2] + uVar2 * 4),0,(uVar10 - uVar2) * 4 + 4);
              puVar8[1] = uVar10 + 1;
            }
            iVar9 = *(int *)(puVar8[2] + uVar10 * 4);
          }
          else {
            piVar4 = (int *)FUN_001a7f7c(puVar8,uVar10);
            iVar9 = *piVar4;
          }
          if (iVar9 != 0) {
            if (*(int *)(*(int *)(iVar9 + 0x88) + 8) == 0x8e) {
              return -1;
            }
            if (((local_1c != iVar9) && ((*(byte *)(iVar9 + 0x15) & 2) != 0)) &&
               (iVar9 = FUN_0010b180(iVar9,*(undefined4 *)(iVar9 + 0x84)), local_18 == iVar9)) {
              return -1;
            }
          }
          uVar10 = uVar10 + 1;
          puVar8 = *(uint **)(local_18 + 0x10);
        } while (uVar10 < puVar8[1]);
      }
      local_10 = local_10 + 1;
      puVar8 = *(uint **)(local_1c + 0x10);
    } while (local_10 < puVar8[1]);
  }
  iVar7 = 0;
  iVar9 = 0;
  iVar6 = 0;
  do {
    iVar1 = piVar5[1];
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) == 0)) {
      iVar7 = iVar7 + 1;
      if (iVar9 == 0) {
        iVar9 = *(int *)(iVar1 + 0x1c);
      }
      else if (*(int *)(iVar1 + 0x1c) < iVar9) {
        iVar9 = *(int *)(iVar1 + 0x1c);
      }
    }
    iVar6 = iVar6 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar6 != 5);
  return iVar7 * -3000 + 1000 + iVar9 * 0xfa;
}

/* FUN_0014c9aa @ 0x14c9aa (5477 bytes) */
int FUN_0014c9aa(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  undefined4 *puVar16;
  undefined1 *puVar17;
  int iVar18;
  uint uVar19;
  undefined1 *local_e0;
  int local_b4;
  int local_ac;
  int local_a8;
  int *local_a4;
  int local_94;
  int local_74;
  int local_6c;
  int local_68;
  int local_60;
  uint local_5c;
  int local_58;
  int local_54;
  int local_50;
  char cStack_49;
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
  
  local_60 = param_4;
  local_b4 = 0;
LAB_0014c9d4:
  puVar1 = *(undefined1 **)(local_60 + 4);
  if (puVar1 != (undefined1 *)0x0) {
    local_ac = *(int *)(puVar1 + 0x18);
    if (local_ac == 0) {
      iVar5 = 0;
      puVar17 = puVar1;
      do {
        if (*(int *)(puVar17 + 4) != 0) {
          iVar5 = *(int *)(puVar1 + iVar5 * 4 + 4);
          uVar19 = 1;
          goto LAB_0014cc58;
        }
        iVar5 = iVar5 + 1;
        puVar17 = puVar17 + 4;
      } while (iVar5 != 4);
      uVar19 = 0;
      iVar5 = 0;
LAB_0014cc58:
      iVar6 = 0;
      puVar17 = puVar1;
      do {
        if ((iVar5 != *(int *)(puVar17 + 4)) && (*(int *)(puVar17 + 4) != 0)) {
          local_58 = *(int *)(puVar1 + iVar6 * 4 + 4);
          uVar19 = uVar19 + 1;
          goto LAB_0014cc81;
        }
        iVar6 = iVar6 + 1;
        puVar17 = puVar17 + 4;
      } while (iVar6 != 4);
      local_58 = 0;
LAB_0014cc81:
      iVar6 = 0;
      puVar17 = puVar1;
      do {
        iVar15 = *(int *)(puVar17 + 4);
        iVar8 = local_58;
        if (((iVar5 != iVar15) && (local_58 != iVar15)) && (iVar15 != 0)) {
          iVar6 = *(int *)(puVar1 + iVar6 * 4 + 4);
          local_54 = iVar6;
          if (iVar6 == 0) goto LAB_0014ddb7;
          iVar15 = 0;
          local_5c = uVar19 + 2;
          puVar17 = puVar1;
          goto LAB_0014dd93;
        }
        iVar6 = iVar6 + 1;
        puVar17 = puVar17 + 4;
      } while (iVar6 != 4);
      local_54 = 0;
      local_50 = 0;
      local_5c = uVar19;
      goto LAB_0014ccb9;
    }
    goto LAB_0014c9f9;
  }
  goto LAB_0014cbdb;
  while( true ) {
    iVar15 = iVar15 + 1;
    puVar17 = puVar17 + 4;
    if (iVar15 == 4) break;
LAB_0014dd93:
    iVar10 = *(int *)(puVar17 + 4);
    if (((iVar5 != iVar10) && (local_58 != iVar10)) && ((iVar10 != iVar6 && (iVar10 != 0)))) {
      iVar15 = *(int *)(puVar1 + iVar15 * 4 + 4);
      local_50 = iVar15;
      if (iVar15 == 0) goto LAB_0014ccb9;
      uVar19 = 0;
      goto LAB_0014decb;
    }
  }
LAB_0014ddb7:
  local_50 = 0;
  local_5c = uVar19 + 1;
  goto LAB_0014ccb9;
  while (uVar19 = uVar19 + 1, uVar19 != 4) {
LAB_0014decb:
    if (uVar19 == (byte)puVar1[uVar19 + 0x14]) {
      iVar10 = *(int *)(puVar1 + uVar19 * 4 + 4);
      if (((iVar10 != iVar15) && (local_54 = iVar15, local_50 = iVar10, iVar10 != iVar6)) &&
         ((iVar8 = iVar15, local_54 = iVar6, local_58 != iVar10 &&
          (iVar8 = local_58, iVar5 == iVar10)))) {
        iVar5 = iVar15;
      }
      break;
    }
  }
LAB_0014ccb9:
  local_58 = iVar8;
  local_a8 = *(int *)(iVar5 + 8);
  local_a4 = *(int **)(local_a8 + 0x158);
  cVar4 = FUN_0010a4c8(local_a8,local_58);
  if (cVar4 != '\0') {
    local_a8 = *(int *)(local_58 + 8);
    local_a4 = *(int **)(local_a8 + 0x158);
  }
  if (local_54 != 0) {
    cVar4 = FUN_0010a4c8(local_a8,local_54);
    if (cVar4 != '\0') {
      local_a8 = *(int *)(local_54 + 8);
      local_a4 = *(int **)(local_a8 + 0x158);
    }
    if ((local_50 != 0) && (cVar4 = FUN_0010a4c8(local_a8,local_50), cVar4 != '\0')) {
      local_a8 = *(int *)(local_50 + 8);
      local_a4 = *(int **)(local_a8 + 0x158);
    }
  }
  FUN_0010a4c8(iVar5,local_a8);
  FUN_0010a4c8(local_58,local_a8);
  if (local_54 != 0) {
    FUN_0010a4c8(local_54,local_a8);
  }
  if (local_50 != 0) {
    FUN_0010a4c8(local_50,local_a8);
  }
  iVar6 = *(int *)(*(int *)(local_a8 + 0x88) + 8);
  while ((iVar6 == 0x8e &&
         (local_a8 = *(int *)(local_a8 + 8), *(int *)(*(int *)(local_a8 + 0x88) + 8) == 0x8e))) {
    local_a8 = *(int *)(local_a8 + 8);
    iVar6 = *(int *)(*(int *)(local_a8 + 0x88) + 8);
  }
  cVar4 = (**(code **)(*local_a4 + 0x1c))(local_a4);
  if (cVar4 == '\0') {
    cVar4 = (**(code **)(*local_a4 + 0x2c))(local_a4);
    piVar2 = local_a4;
  }
  else {
    if (*(int *)(local_a4[0x34] + 4) == 0) {
      puVar16 = (undefined4 *)0x0;
    }
    else {
      puVar16 = *(undefined4 **)(local_a4[0x34] + 8);
    }
    piVar2 = (int *)*puVar16;
    local_a8 = FUN_000e9f24(piVar2);
    cVar4 = (**(code **)(*piVar2 + 0x2c))(piVar2);
  }
  if (cVar4 == '\0') {
    iVar6 = piVar2[0x2b];
    uVar14 = *(undefined4 *)(iVar6 + 8);
  }
  else {
    if (*(int *)(piVar2[0x34] + 4) == 0) {
      puVar16 = (undefined4 *)0x0;
    }
    else {
      puVar16 = *(undefined4 **)(piVar2[0x34] + 8);
    }
    local_a4 = (int *)*puVar16;
    cVar4 = FUN_000e96e8(local_a4,piVar2[0x50]);
    if (cVar4 == '\0') {
      if (*(uint *)(piVar2[0x34] + 4) < 2) {
        puVar16 = (undefined4 *)0x0;
      }
      else {
        puVar16 = (undefined4 *)(*(int *)(piVar2[0x34] + 8) + 4);
      }
      local_a4 = (int *)*puVar16;
    }
    local_a8 = FUN_000e9f24(local_a4);
    iVar6 = local_a4[0x2b];
    uVar14 = *(undefined4 *)(iVar6 + 8);
    piVar2 = local_a4;
  }
  local_e0 = puVar1;
  if (local_5c == 2) {
    local_24 = DAT_001cc57c;
    local_34 = DAT_001cc570;
    iVar15 = 0;
    local_30 = local_34;
    do {
      if (iVar5 == *(int *)(local_e0 + 4)) {
        *(undefined1 *)((int)&local_24 + (uint)(byte)puVar1[iVar15 + 0x14]) = 0;
        *(undefined1 *)((int)&local_30 + (uint)(byte)puVar1[iVar15 + 0x14]) = puVar1[iVar15 + 0x14];
      }
      iVar15 = iVar15 + 1;
      local_e0 = local_e0 + 4;
    } while (iVar15 != 4);
    iVar15 = 0;
    do {
      if (*(char *)((int)&local_24 + iVar15) == '\x01') {
        *(undefined1 *)((int)&local_24 + iVar15) = 0;
        *(char *)((int)&local_34 + iVar15) = (char)iVar15;
        break;
      }
      iVar15 = iVar15 + 1;
    } while (iVar15 != 4);
    iVar5 = ((int (*)())FUN_00110f42)(2,local_24,iVar5,iVar6,uVar14,0);
    *(undefined4 *)(iVar5 + 0x160) = *(undefined4 *)(iVar6 + 0x46c);
    iVar15 = FUN_0010b0f4(iVar5,0);
    uVar7 = FUN_000f5fea(*(undefined4 *)(iVar15 + 0x10));
    uVar9 = local_30;
    *(undefined4 *)(iVar5 + 0xc) = uVar7;
    iVar15 = FUN_0010b0f4(iVar5,1);
    uVar7 = local_34;
    *(undefined4 *)(iVar15 + 0x10) = uVar9;
    iVar15 = FUN_0010b0f4(iVar5,2);
    *(undefined4 *)(iVar15 + 0x10) = uVar7;
    local_34 = DAT_001cc57c;
    local_30 = DAT_001cc570;
    iVar15 = 0;
    puVar17 = puVar1;
    local_24 = local_30;
    do {
      if (local_58 == *(int *)(puVar17 + 4)) {
        *(undefined1 *)((int)&local_34 + (uint)(byte)puVar1[iVar15 + 0x14]) = 0;
        *(undefined1 *)((int)&local_30 + (uint)(byte)puVar1[iVar15 + 0x14]) = puVar1[iVar15 + 0x14];
      }
      iVar15 = iVar15 + 1;
      puVar17 = puVar17 + 4;
    } while (iVar15 != 4);
    iVar15 = 0;
    do {
      if (*(char *)((int)&local_34 + iVar15) == '\x01') {
        *(undefined1 *)((int)&local_34 + iVar15) = 0;
        *(char *)((int)&local_24 + iVar15) = (char)iVar15;
        break;
      }
      iVar15 = iVar15 + 1;
    } while (iVar15 != 4);
    iVar15 = ((int (*)())FUN_00110f42)(2,local_34,local_58,iVar6,uVar14,0);
    *(undefined4 *)(iVar15 + 0x160) = *(undefined4 *)(iVar6 + 0x46c);
    iVar6 = FUN_0010b0f4(iVar15,0);
    uVar9 = FUN_000f5fea(*(undefined4 *)(iVar6 + 0x10));
    uVar7 = local_30;
    *(undefined4 *)(iVar15 + 0xc) = uVar9;
    iVar6 = FUN_0010b0f4(iVar15,1);
    uVar9 = local_24;
    *(undefined4 *)(iVar6 + 0x10) = uVar7;
    iVar6 = FUN_0010b0f4(iVar15,2);
    *(undefined4 *)(iVar6 + 0x10) = uVar9;
    iVar6 = FUN_0010a17a(0x12,uVar14);
    *(undefined4 *)(iVar6 + 0x94) = *(undefined4 *)(iVar6 + 0x14c);
    *(undefined4 *)(iVar6 + 0x98) = 0;
    *(undefined4 *)(iVar6 + 0x124) = 0;
    *(undefined1 *)(iVar6 + 0x120) = 0;
    iVar8 = FUN_0010b180(iVar5,1);
    iVar10 = FUN_0010b0f4(iVar5,2);
    local_24 = *(undefined4 *)(iVar10 + 0x10);
    local_94 = 0;
    do {
      if (*(char *)((int)&local_24 + local_94) != '\x04') goto LAB_0014d216;
      local_94 = local_94 + 1;
    } while (local_94 != 4);
    local_94 = -1;
LAB_0014d216:
    iVar10 = FUN_0010b180(iVar15,1);
    iVar11 = FUN_0010b0f4(iVar15,2);
    uVar7 = *(undefined4 *)(iVar11 + 0x10);
    iVar11 = 0;
    do {
      if (*(char *)((int)&local_30 + iVar11) != '\x04') goto LAB_0014d272;
      iVar11 = iVar11 + 1;
    } while (iVar11 != 4);
    iVar11 = -1;
LAB_0014d272:
    uVar9 = DAT_001cc57c;
    local_2c = DAT_001cc570;
    iVar12 = 0;
    puVar17 = puVar1;
    local_28 = local_2c;
    do {
      if (iVar8 == *(int *)(puVar17 + 4)) {
        *(undefined1 *)((int)&local_34 + iVar12) = 0;
        *(undefined1 *)((int)&local_28 + iVar12) = puVar1[iVar12 + 0x14];
        *(char *)((int)&local_2c + iVar12) = (char)iVar11;
      }
      else if (iVar10 == *(int *)(puVar17 + 4)) {
        *(undefined1 *)((int)&local_34 + iVar12) = 0;
        *(undefined1 *)((int)&local_28 + iVar12) = (undefined1)local_94;
        *(undefined1 *)((int)&local_2c + iVar12) = puVar1[iVar12 + 0x14];
      }
      iVar12 = iVar12 + 1;
      puVar17 = puVar17 + 4;
    } while (iVar12 != 4);
    *(undefined4 *)(iVar6 + 0x9c) = DAT_001cc57c;
    local_34 = uVar9;
    local_30 = uVar7;
    FUN_0010ba02(iVar6,1,iVar5,1,uVar14);
    FUN_00109c0e(iVar6 + 0xa4,1,0);
    FUN_00109c0e(iVar6 + 0xa4,2,0);
    uVar7 = local_28;
    iVar8 = FUN_0010b0f4(iVar6,1);
    *(undefined4 *)(iVar8 + 0x10) = uVar7;
    FUN_0010ba02(iVar6,2,iVar15,1,uVar14);
    FUN_00109c0e(iVar6 + 0xbc,1,0);
    FUN_00109c0e(iVar6 + 0xbc,2,0);
    uVar14 = local_2c;
    iVar8 = FUN_0010b0f4(iVar6,2);
    *(undefined4 *)(iVar8 + 0x10) = uVar14;
    iVar8 = FUN_0010b0f4(iVar6,0);
    uVar14 = FUN_000f5fea(*(undefined4 *)(iVar8 + 0x10));
    *(undefined4 *)(iVar6 + 0xc) = uVar14;
    FUN_000e956e(piVar2,local_a8,iVar5);
    FUN_000e956e(piVar2,local_a8,iVar15);
    FUN_000e956e(piVar2,local_a8,iVar6);
    *(int *)(puVar1 + 0x18) = iVar6;
  }
  else if ((1 < local_5c) && (local_5c < 5)) {
    local_2c = DAT_001cc57c;
    local_34 = DAT_001cc570;
    iVar15 = 0;
    local_28 = local_34;
    do {
      if (iVar5 == *(int *)(local_e0 + 4)) {
        *(undefined1 *)((int)&local_2c + (uint)(byte)puVar1[iVar15 + 0x14]) = 0;
        *(undefined1 *)((int)&local_28 + (uint)(byte)puVar1[iVar15 + 0x14]) = puVar1[iVar15 + 0x14];
      }
      iVar15 = iVar15 + 1;
      local_e0 = local_e0 + 4;
    } while (iVar15 != 4);
    iVar15 = 0;
    do {
      if (*(char *)((int)&local_2c + iVar15) == '\x01') {
        *(undefined1 *)((int)&local_2c + iVar15) = 0;
        *(char *)((int)&local_34 + iVar15) = (char)iVar15;
        break;
      }
      iVar15 = iVar15 + 1;
    } while (iVar15 != 4);
    iVar5 = ((int (*)())FUN_00110f42)(2,local_2c,iVar5,iVar6,uVar14,0x3f800000);
    *(undefined4 *)(iVar5 + 0x160) = *(undefined4 *)(iVar6 + 0x46c);
    iVar15 = FUN_0010b0f4(iVar5,0);
    uVar7 = FUN_000f5fea(*(undefined4 *)(iVar15 + 0x10));
    uVar9 = local_28;
    *(undefined4 *)(iVar5 + 0xc) = uVar7;
    iVar15 = FUN_0010b0f4(iVar5,1);
    uVar7 = local_34;
    *(undefined4 *)(iVar15 + 0x10) = uVar9;
    iVar15 = FUN_0010b0f4(iVar5,2);
    *(undefined4 *)(iVar15 + 0x10) = uVar7;
    local_34 = DAT_001cc57c;
    local_30 = DAT_001cc570;
    iVar15 = 0;
    puVar17 = puVar1;
    local_2c = local_30;
    local_28 = local_30;
    do {
      if (local_58 == *(int *)(puVar17 + 4)) {
        *(undefined1 *)((int)&local_34 + (uint)(byte)puVar1[iVar15 + 0x14]) = 0;
        *(undefined1 *)((int)&local_28 + (uint)(byte)puVar1[iVar15 + 0x14]) = puVar1[iVar15 + 0x14];
      }
      iVar15 = iVar15 + 1;
      puVar17 = puVar17 + 4;
    } while (iVar15 != 4);
    iVar15 = 0;
    do {
      if (*(char *)((int)&local_34 + iVar15) == '\x01') {
        *(undefined1 *)((int)&local_34 + iVar15) = 0;
        *(char *)((int)&local_2c + iVar15) = (char)iVar15;
        break;
      }
      iVar15 = iVar15 + 1;
    } while (iVar15 != 4);
    iVar15 = 0;
    do {
      if (*(char *)((int)&local_34 + iVar15) == '\x01') {
        *(undefined1 *)((int)&local_34 + iVar15) = 0;
        *(char *)((int)&local_30 + iVar15) = (char)iVar15;
        break;
      }
      iVar15 = iVar15 + 1;
    } while (iVar15 != 4);
    iVar15 = ((int (*)())FUN_00110f42)(3,local_34,local_58,iVar6,uVar14,0x3f800000);
    *(undefined4 *)(iVar15 + 0x160) = *(undefined4 *)(iVar6 + 0x46c);
    iVar8 = FUN_0010b0f4(iVar15,0);
    uVar9 = FUN_000f5fea(*(undefined4 *)(iVar8 + 0x10));
    uVar7 = local_28;
    *(undefined4 *)(iVar15 + 0xc) = uVar9;
    iVar8 = FUN_0010b0f4(iVar15,1);
    uVar9 = local_2c;
    *(undefined4 *)(iVar8 + 0x10) = uVar7;
    iVar8 = FUN_0010b0f4(iVar15,2);
    uVar7 = local_30;
    *(undefined4 *)(iVar8 + 0x10) = uVar9;
    iVar8 = FUN_0010b0f4(iVar15,3);
    *(undefined4 *)(iVar8 + 0x10) = uVar7;
    local_30 = DAT_001cc57c;
    local_2c = DAT_001cc570;
    iVar8 = 0;
    puVar17 = puVar1;
    local_28 = local_2c;
    do {
      if (local_54 == *(int *)(puVar17 + 4)) {
        *(undefined1 *)((int)&local_30 + (uint)(byte)puVar1[iVar8 + 0x14]) = 0;
        *(undefined1 *)((int)&local_2c + (uint)(byte)puVar1[iVar8 + 0x14]) = puVar1[iVar8 + 0x14];
      }
      iVar8 = iVar8 + 1;
      puVar17 = puVar17 + 4;
    } while (iVar8 != 4);
    iVar8 = 0;
    do {
      if (*(char *)((int)&local_30 + iVar8) == '\x01') {
        *(undefined1 *)((int)&local_30 + iVar8) = 0;
        *(char *)((int)&local_28 + iVar8) = (char)iVar8;
        break;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 != 4);
    iVar8 = ((int (*)())FUN_00110f42)(2,local_30,local_54,iVar6,uVar14,0);
    *(undefined4 *)(iVar8 + 0x160) = *(undefined4 *)(iVar6 + 0x46c);
    iVar6 = FUN_0010b0f4(iVar8,0);
    uVar9 = FUN_000f5fea(*(undefined4 *)(iVar6 + 0x10));
    uVar7 = local_2c;
    *(undefined4 *)(iVar8 + 0xc) = uVar9;
    iVar6 = FUN_0010b0f4(iVar8,1);
    uVar9 = local_28;
    *(undefined4 *)(iVar6 + 0x10) = uVar7;
    iVar6 = FUN_0010b0f4(iVar8,2);
    *(undefined4 *)(iVar6 + 0x10) = uVar9;
    iVar6 = FUN_0010a17a(0x14,uVar14);
    *(undefined4 *)(iVar6 + 0x94) = *(undefined4 *)(iVar6 + 0x14c);
    *(undefined4 *)(iVar6 + 0x98) = 0;
    *(undefined4 *)(iVar6 + 0x124) = 0;
    *(undefined1 *)(iVar6 + 0x120) = 0;
    iVar10 = FUN_0010b180(iVar5,1);
    iVar11 = FUN_0010b0f4(iVar5,2);
    local_28 = *(undefined4 *)(iVar11 + 0x10);
    local_74 = 0;
    do {
      if (*(char *)((int)&local_28 + local_74) != '\x04') goto LAB_0014d816;
      local_74 = local_74 + 1;
    } while (local_74 != 4);
    local_74 = -1;
LAB_0014d816:
    iVar11 = FUN_0010b180(iVar15,1);
    iVar12 = FUN_0010b0f4(iVar15,2);
    local_2c = *(undefined4 *)(iVar12 + 0x10);
    iVar12 = FUN_0010b0f4(iVar15,3);
    local_30 = *(undefined4 *)(iVar12 + 0x10);
    local_6c = 0;
    do {
      if (*(char *)((int)&local_2c + local_6c) != '\x04') goto LAB_0014d883;
      local_6c = local_6c + 1;
    } while (local_6c != 4);
    local_6c = -1;
LAB_0014d883:
    local_68 = 0;
    do {
      if (*(char *)((int)&local_30 + local_68) != '\x04') goto LAB_0014d8ab;
      local_68 = local_68 + 1;
    } while (local_68 != 4);
    local_68 = -1;
LAB_0014d8ab:
    iVar12 = FUN_0010b180(iVar8,1);
    iVar13 = FUN_0010b0f4(iVar8,2);
    local_34 = *(undefined4 *)(iVar13 + 0x10);
    iVar13 = 0;
    do {
      if (*(char *)((int)&local_34 + iVar13) != '\x04') goto LAB_0014d8f5;
      iVar13 = iVar13 + 1;
    } while (iVar13 != 4);
    iVar13 = -1;
LAB_0014d8f5:
    local_38 = DAT_001cc57c;
    local_44 = DAT_001cc570;
    iVar18 = 0;
    puVar16 = &local_44;
    local_e0 = puVar1;
    local_40 = local_44;
    local_3c = local_44;
    local_24 = local_44;
    do {
      iVar3 = *(int *)(local_e0 + 4);
      if (iVar10 == iVar3) {
        *(undefined1 *)(puVar16 + 3) = 0;
        *(undefined1 *)(puVar16 + 2) = puVar1[iVar18 + 0x14];
        *(undefined1 *)(puVar16 + 1) = (undefined1)local_6c;
        *(char *)puVar16 = (char)iVar13;
      }
      else if (iVar11 == iVar3) {
        *(undefined1 *)(puVar16 + 3) = 0;
        *(undefined1 *)(puVar16 + 2) = (undefined1)local_74;
        *(undefined1 *)(puVar16 + 1) = puVar1[iVar18 + 0x14];
        *(char *)puVar16 = (char)iVar13;
      }
      else if (iVar12 == iVar3) {
        *(undefined1 *)(puVar16 + 3) = 0;
        *(undefined1 *)(puVar16 + 2) = (undefined1)local_74;
        *(undefined1 *)(puVar16 + 1) = (undefined1)local_68;
        *(undefined1 *)puVar16 = puVar1[iVar18 + 0x14];
      }
      else if ((local_50 != 0) && (local_50 == iVar3)) {
        *(char *)((int)&local_24 + iVar18) = (char)iVar18;
      }
      iVar18 = iVar18 + 1;
      puVar16 = (undefined4 *)((int)puVar16 + 1);
      local_e0 = local_e0 + 4;
    } while (iVar18 != 4);
    *(undefined4 *)(iVar6 + 0x9c) = local_38;
    FUN_0010ba02(iVar6,1,iVar5,1,uVar14);
    FUN_00109c0e(iVar6 + 0xa4,1,0);
    FUN_00109c0e(iVar6 + 0xa4,2,0);
    uVar7 = local_3c;
    iVar10 = FUN_0010b0f4(iVar6,1);
    *(undefined4 *)(iVar10 + 0x10) = uVar7;
    FUN_0010ba02(iVar6,2,iVar15,1,uVar14);
    FUN_00109c0e(iVar6 + 0xbc,1,0);
    FUN_00109c0e(iVar6 + 0xbc,2,0);
    uVar7 = local_40;
    iVar10 = FUN_0010b0f4(iVar6,2);
    *(undefined4 *)(iVar10 + 0x10) = uVar7;
    FUN_0010ba02(iVar6,3,iVar8,1,uVar14);
    FUN_00109c0e(iVar6 + 0xd4,1,0);
    FUN_00109c0e(iVar6 + 0xd4,2,0);
    uVar7 = local_44;
    iVar10 = FUN_0010b0f4(iVar6,3);
    *(undefined4 *)(iVar10 + 0x10) = uVar7;
    if (local_50 == 0) {
      iVar10 = FUN_0010b0f4(iVar6,0);
      uVar14 = FUN_000f5fea(*(undefined4 *)(iVar10 + 0x10));
      *(undefined4 *)(iVar6 + 0xc) = uVar14;
    }
    else {
      FUN_0010c18e(iVar6,local_50,1,uVar14);
      uVar14 = local_24;
      iVar10 = FUN_0010b0f4(iVar6,4);
      *(undefined4 *)(iVar10 + 0x10) = uVar14;
      *(undefined4 *)(iVar6 + 0xc) = DAT_001cc580;
    }
    FUN_000e956e(piVar2,local_a8,iVar5);
    FUN_000e956e(piVar2,local_a8,iVar15);
    FUN_000e956e(piVar2,local_a8,iVar8);
    FUN_000e956e(piVar2,local_a8,iVar6);
    *(int *)(puVar1 + 0x18) = iVar6;
  }
  iVar5 = 4;
  puVar17 = puVar1;
  do {
    *puVar17 = 1;
    puVar17 = puVar17 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  local_ac = *(int *)(puVar1 + 0x18);
LAB_0014c9f9:
  iVar5 = FUN_0010b0f4(param_2,local_b4);
  local_48 = *(undefined4 *)(iVar5 + 0x10);
  iVar5 = 1;
  do {
    cVar4 = (&cStack_49)[iVar5];
    if (cVar4 != '\x04') {
      iVar6 = FUN_0010b180(param_2,local_b4);
      iVar15 = 0;
      puVar17 = puVar1;
      do {
        if ((iVar6 == *(int *)(puVar17 + 4)) && (cVar4 == puVar1[iVar15 + 0x14])) goto LAB_0014ca72;
        iVar15 = iVar15 + 1;
        puVar17 = puVar17 + 4;
      } while (iVar15 != 4);
      iVar15 = -1;
LAB_0014ca72:
      (&cStack_49)[iVar5] = (char)iVar15;
    }
    uVar14 = local_48;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 5);
  iVar5 = FUN_0010b0f4(param_2,local_b4);
  *(undefined4 *)(iVar5 + 0x10) = uVar14;
  if ((*(int *)(param_2 + 0x84) == local_b4) && ((*(byte *)(param_2 + 0x15) & 2) != 0)) {
    FUN_0010c18e(param_2,local_ac,1,*param_1);
  }
  else {
    FUN_0010ba02(param_2,local_b4,local_ac,1,*param_1);
  }
  iVar5 = FUN_0010b0f4(param_3,local_b4);
  local_20 = *(undefined4 *)(iVar5 + 0x10);
  iVar5 = 1;
  do {
    cVar4 = *(char *)((int)&local_24 + iVar5 + 3);
    if (cVar4 != '\x04') {
      iVar6 = FUN_0010b180(param_3,local_b4);
      iVar15 = 0;
      puVar17 = puVar1;
      do {
        if ((iVar6 == *(int *)(puVar17 + 4)) && (cVar4 == puVar1[iVar15 + 0x14])) goto LAB_0014cb63;
        iVar15 = iVar15 + 1;
        puVar17 = puVar17 + 4;
      } while (iVar15 != 4);
      iVar15 = -1;
LAB_0014cb63:
      *(char *)((int)&local_24 + iVar5 + 3) = (char)iVar15;
    }
    uVar14 = local_20;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 5);
  iVar5 = FUN_0010b0f4(param_3,local_b4);
  *(undefined4 *)(iVar5 + 0x10) = uVar14;
  if ((*(int *)(param_3 + 0x84) == local_b4) && ((*(byte *)(param_3 + 0x15) & 2) != 0)) {
    FUN_0010c18e(param_3,local_ac,1,*param_1);
  }
  else {
    FUN_0010ba02(param_3,local_b4,local_ac,1,*param_1);
  }
LAB_0014cbdb:
  local_b4 = local_b4 + 1;
  local_60 = local_60 + 4;
  if (local_b4 == 5) {
    return;
  }
  goto LAB_0014c9d4;
}

/* FUN_0014df10 @ 0x14df10 (946 bytes) */
int FUN_0014df10(param_1, param_2)
  undefined4 *param_1;
  int *param_2;
{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_30;
  int local_2c;
  int local_28;
  uint local_20;
  uint local_14;
  
  iVar6 = *param_2;
  iVar7 = param_2[1];
  local_30 = param_2[3];
  local_2c = param_2[2];
  if ((char)param_2[4] != '\0') {
    iVar6 = param_2[1];
    iVar7 = *param_2;
    local_30 = param_2[2];
    local_2c = param_2[3];
  }
  param_1[2] = param_1[2] + 1;
  if (0 < param_2[5]) {
    ((int (*)())FUN_0014c9aa)(param_1,iVar6,iVar7,param_2 + 5);
  }
  if ((*(byte *)(iVar6 + 0x15) & 2) == 0) {
    local_28 = 0;
  }
  else {
    local_28 = FUN_0010b180(iVar6,*(undefined4 *)(iVar6 + 0x84));
  }
  if (iVar7 == local_28) {
    uVar1 = *param_1;
    iVar5 = FUN_0010b180(iVar6,*(undefined4 *)(iVar6 + 0x84));
    puVar2 = *(uint **)(iVar5 + 0x10);
    if (0 < (int)puVar2[1]) {
      local_20 = 0;
      do {
        if (local_20 < *puVar2) {
          uVar3 = puVar2[1];
          if (uVar3 <= local_20) {
            _memset((void *)(puVar2[2] + uVar3 * 4),0,(local_20 - uVar3) * 4 + 4);
            puVar2[1] = local_20 + 1;
          }
          piVar4 = (int *)(puVar2[2] + local_20 * 4);
        }
        else {
          piVar4 = (int *)FUN_001a7f7c(puVar2,local_20);
        }
        if (iVar6 == *piVar4) {
          FUN_001a7f3c(puVar2,local_20);
          iVar5 = FUN_0010b180(iVar6,*(undefined4 *)(iVar6 + 0x84));
          *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + -1;
          break;
        }
        local_20 = local_20 + 1;
      } while ((int)local_20 < (int)puVar2[1]);
    }
    FUN_0010ba02(iVar6,*(undefined4 *)(iVar6 + 0x84),0,1,uVar1);
    *(int *)(iVar6 + 0x84) = *(int *)(iVar6 + 0x84) + -1;
    *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) & 0xfffffdff;
    local_28 = 0;
  }
  if ((*(byte *)(iVar7 + 0x15) & 2) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_0010b180(iVar7,*(undefined4 *)(iVar7 + 0x84));
  }
  if (iVar6 == iVar5) {
    uVar1 = *param_1;
    iVar5 = FUN_0010b180(iVar7,*(undefined4 *)(iVar7 + 0x84));
    puVar2 = *(uint **)(iVar5 + 0x10);
    if (0 < (int)puVar2[1]) {
      local_14 = 0;
      do {
        if (local_14 < *puVar2) {
          uVar3 = puVar2[1];
          if (uVar3 <= local_14) {
            _memset((void *)(puVar2[2] + uVar3 * 4),0,(local_14 - uVar3) * 4 + 4);
            puVar2[1] = local_14 + 1;
          }
          piVar4 = (int *)(puVar2[2] + local_14 * 4);
        }
        else {
          piVar4 = (int *)FUN_001a7f7c(puVar2,local_14);
        }
        if (iVar7 == *piVar4) {
          FUN_001a7f3c(puVar2,local_14);
          iVar5 = FUN_0010b180(iVar7,*(undefined4 *)(iVar7 + 0x84));
          *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + -1;
          break;
        }
        local_14 = local_14 + 1;
      } while ((int)local_14 < (int)puVar2[1]);
    }
    FUN_0010ba02(iVar7,*(undefined4 *)(iVar7 + 0x84),0,1,uVar1);
    *(int *)(iVar7 + 0x84) = *(int *)(iVar7 + 0x84) + -1;
    *(uint *)(iVar7 + 0x14) = *(uint *)(iVar7 + 0x14) & 0xfffffdff;
  }
  else if ((iVar5 != 0) && (local_28 != iVar5)) {
    FUN_0010c18e(iVar6,iVar5,1,*param_1);
    FUN_0010b0f4(iVar6,*(undefined4 *)(iVar6 + 0x84));
  }
  ((int (*)())FUN_0014beee)(param_1,iVar6,local_2c);
  ((int (*)())FUN_0014beee)(param_1,iVar7,local_30);
  ((int (*)())FUN_0014ab7a)(param_1,iVar6,iVar6,local_2c);
  ((int (*)())FUN_0014ab7a)(param_1,iVar6,iVar7,local_30);
  ((int (*)())FUN_001494d0)(param_1,iVar7,iVar6);
  return;
}

/* FUN_0014e2c2 @ 0x14e2c2 (6068 bytes) */
int FUN_0014e2c2(param_1)
  int *param_1;
{
  undefined4 uVar1;
  bool bVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  uint uVar13;
  int local_114;
  int local_110;
  int local_10c;
  uint local_108;
  int local_104;
  int *local_100;
  uint local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  uint local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  uint local_c4;
  uint local_b8;
  uint local_ac;
  uint local_a4;
  uint local_9c;
  uint local_98;
  uint local_90;
  uint local_70;
  undefined4 *local_58;
  uint local_50;
  int local_48;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  iVar5 = *(int *)(param_1[1] + 0x378);
  iVar6 = *(int *)(iVar5 + 8);
  while (iVar6 != 0) {
    iVar10 = *(int *)(iVar5 + 0x98);
    iVar6 = *(int *)(iVar10 + 8);
    while (iVar6 != 0) {
      while ((*(byte *)(iVar10 + 0x14) & 1) != 0) {
        local_20[0] = ((int (*)())FUN_00149888)(param_1,iVar10);
        if ((*(byte *)(iVar10 + 0x15) & 2) != 0) {
          iVar6 = FUN_0010b0f4(iVar10,*(undefined4 *)(iVar10 + 0x84));
          local_24 = *(undefined4 *)(iVar6 + 0x10);
          uVar11 = 0;
          if ((char)local_24 == '\0') goto LAB_0014e7e4;
          while (uVar9 = uVar11 + 1, uVar9 != 4) {
            iVar6 = uVar11 - 3;
            uVar11 = uVar9;
            if (*(byte *)((int)local_20 + iVar6) == uVar9) {
LAB_0014e7e4:
              *(undefined1 *)((int)local_20 + uVar11) = 1;
            }
          }
        }
        *(undefined4 *)(iVar10 + 0xc) = local_20[0];
        iVar10 = *(int *)(iVar10 + 8);
        if (*(int *)(iVar10 + 8) == 0) goto LAB_0014e33a;
      }
      iVar10 = *(int *)(iVar10 + 8);
      iVar6 = *(int *)(iVar10 + 8);
    }
LAB_0014e33a:
    iVar5 = *(int *)(iVar5 + 8);
    iVar6 = *(int *)(iVar5 + 8);
  }
  uVar1 = *(undefined4 *)(*param_1 + 0xbc);
  local_58 = (undefined4 *)FUN_001a7bca(uVar1,0x2c0);
  iVar5 = param_1[1];
  local_ec = *(int *)(iVar5 + 0x378);
  if (*(int *)(local_ec + 8) != 0) {
    local_f4 = 0;
    local_f0 = 0;
    local_40 = 0x10;
    local_50 = 0;
    do {
      local_e4 = *(int *)(local_ec + 0x98);
      iVar5 = *(int *)(local_e4 + 8);
      while (iVar5 != 0) {
        while ((((*(byte *)(local_e4 + 0x14) & 1) != 0 &&
                (cVar3 = FUN_001195a6(*(undefined4 *)(param_1[1] + 8),local_e4), cVar3 != '\0')) &&
               (local_e8 = *(int *)(param_1[1] + 0x378), *(int *)(local_e8 + 8) != 0))) {
          bVar2 = true;
          local_114 = local_f4 * 0x2c;
          do {
            iVar5 = *(int *)(local_e8 + 0x98);
            if (*(int *)(iVar5 + 8) != 0) {
              local_110 = local_114;
              do {
                while ((*(byte *)(iVar5 + 0x14) & 1) == 0) {
LAB_0014e46a:
                  iVar5 = *(int *)(iVar5 + 8);
                  if (*(int *)(iVar5 + 8) == 0) goto LAB_0014e5dd;
                }
                if (bVar2) {
                  local_e8 = local_ec;
                  bVar2 = false;
                  iVar5 = local_e4;
                  goto LAB_0014e46a;
                }
                cVar3 = FUN_001195a6(*(undefined4 *)(param_1[1] + 8),iVar5);
                if (cVar3 == '\0') goto LAB_0014e46a;
                iVar6 = local_f0 + 1;
                if (0x3ff < local_f0) goto LAB_0014e62b;
                uVar11 = local_50;
                if ((local_50 <= local_f4) && (uVar11 = local_f4 + 1, local_40 < uVar11)) {
                  uVar9 = (local_40 << 4) / 10;
                  local_40 = uVar11;
                  if (uVar11 <= uVar9) {
                    local_40 = uVar9;
                  }
                  puVar4 = (undefined4 *)FUN_001a7bca(uVar1,local_40 * 0x2c);
                  if (local_50 != 0) {
                    uVar9 = 0;
                    puVar7 = puVar4;
                    puVar8 = local_58;
                    do {
                      *puVar7 = *puVar8;
                      puVar7[1] = puVar8[1];
                      puVar7[2] = puVar8[2];
                      puVar7[3] = puVar8[3];
                      puVar7[4] = puVar8[4];
                      puVar7[5] = puVar8[5];
                      puVar7[6] = puVar8[6];
                      puVar7[7] = puVar8[7];
                      puVar7[8] = puVar8[8];
                      puVar7[9] = puVar8[9];
                      puVar7[10] = puVar8[10];
                      uVar9 = uVar9 + 1;
                      puVar8 = puVar8 + 0xb;
                      puVar7 = puVar7 + 0xb;
                    } while (local_50 != uVar9);
                  }
                  FUN_001a7aba(uVar1,local_58);
                  local_58 = puVar4;
                }
                local_50 = uVar11;
                cVar3 = ((int (*)())FUN_0014be46)(param_1,local_e4,iVar5,(int)local_58 + local_110);
                local_f0 = iVar6;
                if (cVar3 != '\0') {
                  local_f4 = local_f4 + 1;
                  local_114 = local_114 + 0x2c;
                  local_110 = local_110 + 0x2c;
                  bVar2 = false;
                  goto LAB_0014e46a;
                }
                bVar2 = false;
                iVar5 = *(int *)(iVar5 + 8);
              } while (*(int *)(iVar5 + 8) != 0);
            }
LAB_0014e5dd:
            local_e8 = *(int *)(local_e8 + 8);
          } while (*(int *)(local_e8 + 8) != 0);
          local_e4 = *(int *)(local_e4 + 8);
          if (*(int *)(local_e4 + 8) == 0) goto LAB_0014e611;
        }
        local_e4 = *(int *)(local_e4 + 8);
        iVar5 = *(int *)(local_e4 + 8);
      }
LAB_0014e611:
      local_ec = *(int *)(local_ec + 8);
    } while (*(int *)(local_ec + 8) != 0);
LAB_0014e62b:
    if ((int)local_f4 < 1) {
LAB_0014fa6b:
      iVar5 = param_1[1];
    }
    else {
      do {
        local_dc = 0xffffffff;
        local_d8 = 0;
        local_38 = 0;
        local_48 = 0;
        do {
          uVar11 = local_38 + 1;
          if (uVar11 == 0x81) break;
          uVar9 = local_50;
          if ((local_50 <= local_38) && (uVar9 = uVar11, local_40 < uVar11)) {
            local_40 = (local_40 << 4) / 10;
            if (local_40 < uVar11) {
              local_40 = uVar11;
            }
            puVar4 = (undefined4 *)FUN_001a7bca(uVar1,local_40 * 0x2c);
            if (local_50 != 0) {
              uVar13 = 0;
              puVar7 = puVar4;
              puVar8 = local_58;
              do {
                *puVar7 = *puVar8;
                puVar7[1] = puVar8[1];
                puVar7[2] = puVar8[2];
                puVar7[3] = puVar8[3];
                puVar7[4] = puVar8[4];
                puVar7[5] = puVar8[5];
                puVar7[6] = puVar8[6];
                puVar7[7] = puVar8[7];
                puVar7[8] = puVar8[8];
                puVar7[9] = puVar8[9];
                puVar7[10] = puVar8[10];
                uVar13 = uVar13 + 1;
                puVar8 = puVar8 + 0xb;
                puVar7 = puVar7 + 0xb;
              } while (uVar13 != local_50);
            }
            FUN_001a7aba(uVar1,local_58);
            local_58 = puVar4;
          }
          local_50 = uVar9;
          iVar5 = ((int (*)())FUN_0014c73c)(param_1,(int)local_58 + local_48);
          if ((local_dc == 0xffffffff) || (local_d8 < iVar5)) {
            local_dc = local_38;
            local_d8 = iVar5;
          }
          local_48 = local_48 + 0x2c;
          local_38 = uVar11;
        } while ((int)uVar11 < (int)local_f4);
        if (local_dc == 0xffffffff) {
LAB_0014f29c:
          iVar5 = param_1[1];
          goto LAB_0014f05d;
        }
        if (local_d8 < 0) break;
        uVar11 = local_50;
        if ((local_50 <= local_dc) && (uVar11 = local_dc + 1, local_40 < uVar11)) {
          local_40 = (local_40 << 4) / 10;
          if (local_40 < uVar11) {
            local_40 = uVar11;
          }
          puVar4 = (undefined4 *)FUN_001a7bca(uVar1,local_40 * 0x2c);
          if (local_50 != 0) {
            uVar9 = 0;
            puVar7 = puVar4;
            puVar8 = local_58;
            do {
              *puVar7 = *puVar8;
              puVar7[1] = puVar8[1];
              puVar7[2] = puVar8[2];
              puVar7[3] = puVar8[3];
              puVar7[4] = puVar8[4];
              puVar7[5] = puVar8[5];
              puVar7[6] = puVar8[6];
              puVar7[7] = puVar8[7];
              puVar7[8] = puVar8[8];
              puVar7[9] = puVar8[9];
              puVar7[10] = puVar8[10];
              uVar9 = uVar9 + 1;
              puVar8 = puVar8 + 0xb;
              puVar7 = puVar7 + 0xb;
            } while (uVar9 != local_50);
          }
          FUN_001a7aba(uVar1,local_58);
          local_58 = puVar4;
        }
        local_50 = uVar11;
        local_100 = local_58 + local_dc * 0xb;
        ((int (*)())FUN_0014df10)(param_1,local_100);
        if (0x17 < param_1[2]) goto LAB_0014fa6b;
        piVar12 = param_1 + 3;
        uVar11 = param_1[4];
        if (uVar11 == 0) {
          local_c4 = 0;
        }
        else {
          local_b8 = 0;
          local_c4 = 0;
          do {
            if ((uint)param_1[4] <= local_b8) {
              uVar9 = local_b8 + 1;
              if ((uint)param_1[5] < uVar9) {
                uVar13 = (uint)(param_1[5] << 4) / 10;
                if (uVar13 < uVar9) {
                  uVar13 = uVar9;
                }
                param_1[5] = uVar13;
                puVar4 = (undefined4 *)param_1[6];
                iVar5 = FUN_001a7bca(*piVar12,uVar13 << 5);
                param_1[6] = iVar5;
                if (param_1[4] != 0) {
                  local_ac = 0;
                  iVar5 = 0;
                  puVar7 = puVar4;
                  do {
                    iVar6 = param_1[6];
                    *(undefined4 *)(iVar6 + iVar5) = *puVar7;
                    *(undefined4 *)(iVar6 + 4 + iVar5) = puVar7[1];
                    *(undefined4 *)(iVar6 + 8 + iVar5) = puVar7[2];
                    *(undefined4 *)(iVar6 + 0xc + iVar5) = puVar7[3];
                    *(undefined4 *)(iVar6 + 0x10 + iVar5) = puVar7[4];
                    *(undefined4 *)(iVar6 + 0x14 + iVar5) = puVar7[5];
                    *(undefined4 *)(iVar6 + 0x18 + iVar5) = puVar7[6];
                    *(undefined4 *)(iVar6 + 0x1c + iVar5) = puVar7[7];
                    local_ac = local_ac + 1;
                    iVar5 = iVar5 + 0x20;
                    puVar7 = puVar7 + 8;
                  } while (local_ac < (uint)param_1[4]);
                }
                FUN_001a7aba(*piVar12,puVar4);
              }
              param_1[4] = uVar9;
            }
            puVar4 = (undefined4 *)param_1[6];
            puVar7 = puVar4 + local_b8 * 8;
            if (puVar7[6] != 0) {
              if (local_c4 < local_b8) {
                if ((uint)param_1[4] <= local_c4) {
                  uVar9 = local_c4 + 1;
                  if ((uint)param_1[5] < uVar9) {
                    uVar13 = (uint)(param_1[5] << 4) / 10;
                    if (uVar13 < uVar9) {
                      uVar13 = uVar9;
                    }
                    param_1[5] = uVar13;
                    iVar5 = FUN_001a7bca(*piVar12,uVar13 << 5);
                    param_1[6] = iVar5;
                    if (param_1[4] != 0) {
                      local_a4 = 0;
                      iVar5 = 0;
                      puVar8 = puVar4;
                      do {
                        iVar6 = param_1[6];
                        *(undefined4 *)(iVar6 + iVar5) = *puVar8;
                        *(undefined4 *)(iVar6 + 4 + iVar5) = puVar8[1];
                        *(undefined4 *)(iVar6 + 8 + iVar5) = puVar8[2];
                        *(undefined4 *)(iVar6 + 0xc + iVar5) = puVar8[3];
                        *(undefined4 *)(iVar6 + 0x10 + iVar5) = puVar8[4];
                        *(undefined4 *)(iVar6 + 0x14 + iVar5) = puVar8[5];
                        *(undefined4 *)(iVar6 + 0x18 + iVar5) = puVar8[6];
                        *(undefined4 *)(iVar6 + 0x1c + iVar5) = puVar8[7];
                        local_a4 = local_a4 + 1;
                        iVar5 = iVar5 + 0x20;
                        puVar8 = puVar8 + 8;
                      } while (local_a4 < (uint)param_1[4]);
                    }
                    FUN_001a7aba(*piVar12,puVar4);
                    puVar4 = (undefined4 *)param_1[6];
                  }
                  param_1[4] = uVar9;
                }
                local_3c = local_c4 + 1;
                puVar4[local_c4 * 8] = *puVar7;
                puVar4[local_c4 * 8 + 1] = puVar7[1];
                puVar4[local_c4 * 8 + 2] = puVar7[2];
                puVar4[local_c4 * 8 + 3] = puVar7[3];
                puVar4[local_c4 * 8 + 4] = puVar7[4];
                puVar4[local_c4 * 8 + 5] = puVar7[5];
                puVar4[local_c4 * 8 + 6] = puVar7[6];
                puVar4[local_c4 * 8 + 7] = puVar7[7];
                local_c4 = local_3c;
              }
              else {
                local_c4 = local_c4 + 1;
              }
            }
            local_b8 = local_b8 + 1;
          } while (uVar11 != local_b8);
        }
        if ((uint)param_1[5] < local_c4) {
          uVar11 = (uint)(param_1[5] << 4) / 10;
          if (uVar11 < local_c4) {
            uVar11 = local_c4;
          }
          param_1[5] = uVar11;
          puVar4 = (undefined4 *)param_1[6];
          iVar5 = FUN_001a7bca(*piVar12,uVar11 << 5);
          param_1[6] = iVar5;
          if (param_1[4] != 0) {
            local_9c = 0;
            iVar5 = 0;
            puVar7 = puVar4;
            do {
              iVar6 = param_1[6];
              *(undefined4 *)(iVar6 + iVar5) = *puVar7;
              *(undefined4 *)(iVar6 + 4 + iVar5) = puVar7[1];
              *(undefined4 *)(iVar6 + 8 + iVar5) = puVar7[2];
              *(undefined4 *)(iVar6 + 0xc + iVar5) = puVar7[3];
              *(undefined4 *)(iVar6 + 0x10 + iVar5) = puVar7[4];
              *(undefined4 *)(iVar6 + 0x14 + iVar5) = puVar7[5];
              *(undefined4 *)(iVar6 + 0x18 + iVar5) = puVar7[6];
              *(undefined4 *)(iVar6 + 0x1c + iVar5) = puVar7[7];
              local_9c = local_9c + 1;
              iVar5 = iVar5 + 0x20;
              puVar7 = puVar7 + 8;
            } while (local_9c < (uint)param_1[4]);
          }
          FUN_001a7aba(*piVar12,puVar4);
        }
        param_1[4] = local_c4;
        if (local_c4 != 0) {
          local_98 = 0;
          while( true ) {
            if (local_98 < (uint)param_1[4]) {
              *(undefined4 *)(local_98 * 0x20 + 0x1c + param_1[6]) = 0;
            }
            else {
              uVar11 = local_98 + 1;
              if ((uint)param_1[5] < uVar11) {
                uVar9 = (uint)(param_1[5] << 4) / 10;
                if (uVar9 < uVar11) {
                  uVar9 = uVar11;
                }
                param_1[5] = uVar9;
                puVar4 = (undefined4 *)param_1[6];
                iVar5 = FUN_001a7bca(*piVar12,uVar9 << 5);
                param_1[6] = iVar5;
                if (param_1[4] != 0) {
                  local_90 = 0;
                  iVar5 = 0;
                  puVar7 = puVar4;
                  do {
                    iVar6 = param_1[6];
                    *(undefined4 *)(iVar6 + iVar5) = *puVar7;
                    *(undefined4 *)(iVar6 + 4 + iVar5) = puVar7[1];
                    *(undefined4 *)(iVar6 + 8 + iVar5) = puVar7[2];
                    *(undefined4 *)(iVar6 + 0xc + iVar5) = puVar7[3];
                    *(undefined4 *)(iVar6 + 0x10 + iVar5) = puVar7[4];
                    *(undefined4 *)(iVar6 + 0x14 + iVar5) = puVar7[5];
                    *(undefined4 *)(iVar6 + 0x18 + iVar5) = puVar7[6];
                    *(undefined4 *)(iVar6 + 0x1c + iVar5) = puVar7[7];
                    local_90 = local_90 + 1;
                    iVar5 = iVar5 + 0x20;
                    puVar7 = puVar7 + 8;
                  } while (local_90 < (uint)param_1[4]);
                }
                FUN_001a7aba(*piVar12,puVar4);
              }
              param_1[4] = uVar11;
              *(undefined4 *)(local_98 * 0x20 + 0x1c + param_1[6]) = 0;
            }
            if (local_c4 <= local_98 + 1) break;
            local_34 = local_98 + 1;
            local_98 = local_34;
          }
        }
        uVar11 = local_50;
        if ((local_50 <= local_dc) && (uVar11 = local_dc + 1, local_40 < uVar11)) {
          local_40 = (local_40 << 4) / 10;
          if (local_40 < uVar11) {
            local_40 = uVar11;
          }
          puVar4 = (undefined4 *)FUN_001a7bca(uVar1,local_40 * 0x2c);
          if (local_50 != 0) {
            uVar9 = 0;
            puVar7 = puVar4;
            puVar8 = local_58;
            do {
              *puVar7 = *puVar8;
              puVar7[1] = puVar8[1];
              puVar7[2] = puVar8[2];
              puVar7[3] = puVar8[3];
              puVar7[4] = puVar8[4];
              puVar7[5] = puVar8[5];
              puVar7[6] = puVar8[6];
              puVar7[7] = puVar8[7];
              puVar7[8] = puVar8[8];
              puVar7[9] = puVar8[9];
              puVar7[10] = puVar8[10];
              uVar9 = uVar9 + 1;
              puVar8 = puVar8 + 0xb;
              puVar7 = puVar7 + 0xb;
            } while (uVar9 != local_50);
          }
          FUN_001a7aba(uVar1,local_58);
          local_100 = puVar4 + local_dc * 0xb;
          local_58 = puVar4;
        }
        local_50 = uVar11;
        local_d4 = *local_100;
        uVar11 = local_50;
        if ((local_50 <= local_dc) && (uVar11 = local_dc + 1, local_40 < uVar11)) {
          local_40 = (local_40 << 4) / 10;
          if (local_40 < uVar11) {
            local_40 = uVar11;
          }
          puVar4 = (undefined4 *)FUN_001a7bca(uVar1,local_40 * 0x2c);
          if (local_50 != 0) {
            uVar9 = 0;
            puVar7 = puVar4;
            puVar8 = local_58;
            do {
              *puVar7 = *puVar8;
              puVar7[1] = puVar8[1];
              puVar7[2] = puVar8[2];
              puVar7[3] = puVar8[3];
              puVar7[4] = puVar8[4];
              puVar7[5] = puVar8[5];
              puVar7[6] = puVar8[6];
              puVar7[7] = puVar8[7];
              puVar7[8] = puVar8[8];
              puVar7[9] = puVar8[9];
              puVar7[10] = puVar8[10];
              uVar9 = uVar9 + 1;
              puVar8 = puVar8 + 0xb;
              puVar7 = puVar7 + 0xb;
            } while (uVar9 != local_50);
          }
          FUN_001a7aba(uVar1,local_58);
          local_100 = puVar4 + local_dc * 0xb;
          local_58 = puVar4;
        }
        local_50 = uVar11;
        local_d0 = local_100[1];
        uVar11 = local_50;
        if ((local_50 <= local_dc) && (uVar11 = local_dc + 1, local_40 < uVar11)) {
          local_40 = (local_40 << 4) / 10;
          if (local_40 < uVar11) {
            local_40 = uVar11;
          }
          puVar4 = (undefined4 *)FUN_001a7bca(uVar1,local_40 * 0x2c);
          if (local_50 != 0) {
            uVar9 = 0;
            puVar7 = puVar4;
            puVar8 = local_58;
            do {
              *puVar7 = *puVar8;
              puVar7[1] = puVar8[1];
              puVar7[2] = puVar8[2];
              puVar7[3] = puVar8[3];
              puVar7[4] = puVar8[4];
              puVar7[5] = puVar8[5];
              puVar7[6] = puVar8[6];
              puVar7[7] = puVar8[7];
              puVar7[8] = puVar8[8];
              puVar7[9] = puVar8[9];
              puVar7[10] = puVar8[10];
              uVar9 = uVar9 + 1;
              puVar8 = puVar8 + 0xb;
              puVar7 = puVar7 + 0xb;
            } while (uVar9 != local_50);
          }
          FUN_001a7aba(uVar1,local_58);
          local_100 = puVar4 + local_dc * 0xb;
          local_58 = puVar4;
        }
        local_50 = uVar11;
        if ((char)local_100[4] != '\0') {
          if (local_dc < local_50) {
            local_d4 = local_100[1];
            uVar11 = local_50;
            puVar4 = local_58;
          }
          else {
            uVar11 = local_dc + 1;
            if (local_40 < uVar11) {
              local_40 = (local_40 << 4) / 10;
              if (local_40 < uVar11) {
                local_40 = uVar11;
              }
              puVar4 = (undefined4 *)FUN_001a7bca(uVar1,local_40 * 0x2c);
              if (local_50 != 0) {
                uVar9 = 0;
                puVar7 = local_58;
                puVar8 = puVar4;
                do {
                  *puVar8 = *puVar7;
                  puVar8[1] = puVar7[1];
                  puVar8[2] = puVar7[2];
                  puVar8[3] = puVar7[3];
                  puVar8[4] = puVar7[4];
                  puVar8[5] = puVar7[5];
                  puVar8[6] = puVar7[6];
                  puVar8[7] = puVar7[7];
                  puVar8[8] = puVar7[8];
                  puVar8[9] = puVar7[9];
                  puVar8[10] = puVar7[10];
                  uVar9 = uVar9 + 1;
                  puVar7 = puVar7 + 0xb;
                  puVar8 = puVar8 + 0xb;
                } while (uVar9 != local_50);
              }
              FUN_001a7aba(uVar1,local_58);
              local_100 = puVar4 + local_dc * 0xb;
              local_58 = puVar4;
            }
            local_d4 = local_100[1];
            puVar4 = local_58;
          }
          local_58 = puVar4;
          local_50 = uVar11;
          if ((uVar11 <= local_dc) && (local_50 = local_dc + 1, local_40 < local_50)) {
            local_40 = (local_40 << 4) / 10;
            if (local_40 < local_50) {
              local_40 = local_50;
            }
            local_58 = (undefined4 *)FUN_001a7bca(uVar1,local_40 * 0x2c);
            if (uVar11 != 0) {
              uVar9 = 0;
              puVar7 = puVar4;
              puVar8 = local_58;
              do {
                *puVar8 = *puVar7;
                puVar8[1] = puVar7[1];
                puVar8[2] = puVar7[2];
                puVar8[3] = puVar7[3];
                puVar8[4] = puVar7[4];
                puVar8[5] = puVar7[5];
                puVar8[6] = puVar7[6];
                puVar8[7] = puVar7[7];
                puVar8[8] = puVar7[8];
                puVar8[9] = puVar7[9];
                puVar8[10] = puVar7[10];
                uVar9 = uVar9 + 1;
                puVar7 = puVar7 + 0xb;
                puVar8 = puVar8 + 0xb;
              } while (uVar9 != uVar11);
            }
            FUN_001a7aba(uVar1,puVar4);
            local_100 = local_58 + local_dc * 0xb;
          }
          local_d0 = *local_100;
        }
        uVar11 = local_50;
        if ((local_50 <= local_dc) && (uVar11 = local_dc + 1, local_40 < uVar11)) {
          local_40 = (local_40 << 4) / 10;
          if (local_40 < uVar11) {
            local_40 = uVar11;
          }
          puVar4 = (undefined4 *)FUN_001a7bca(uVar1,local_40 * 0x2c);
          if (local_50 != 0) {
            uVar9 = 0;
            puVar7 = puVar4;
            puVar8 = local_58;
            do {
              *puVar7 = *puVar8;
              puVar7[1] = puVar8[1];
              puVar7[2] = puVar8[2];
              puVar7[3] = puVar8[3];
              puVar7[4] = puVar8[4];
              puVar7[5] = puVar8[5];
              puVar7[6] = puVar8[6];
              puVar7[7] = puVar8[7];
              puVar7[8] = puVar8[8];
              puVar7[9] = puVar8[9];
              puVar7[10] = puVar8[10];
              uVar9 = uVar9 + 1;
              puVar8 = puVar8 + 0xb;
              puVar7 = puVar7 + 0xb;
            } while (uVar9 != local_50);
          }
          FUN_001a7aba(uVar1,local_58);
          local_100 = puVar4 + local_dc * 0xb;
          local_58 = puVar4;
        }
        local_50 = uVar11;
        uVar11 = local_f4 - 1;
        uVar9 = local_50;
        if ((local_50 <= uVar11) && (uVar9 = local_f4, local_40 < local_f4)) {
          local_40 = (local_40 << 4) / 10;
          if (local_40 < local_f4) {
            local_40 = local_f4;
          }
          puVar4 = (undefined4 *)FUN_001a7bca(uVar1,local_40 * 0x2c);
          if (local_50 != 0) {
            uVar13 = 0;
            puVar7 = puVar4;
            puVar8 = local_58;
            do {
              *puVar7 = *puVar8;
              puVar7[1] = puVar8[1];
              puVar7[2] = puVar8[2];
              puVar7[3] = puVar8[3];
              puVar7[4] = puVar8[4];
              puVar7[5] = puVar8[5];
              puVar7[6] = puVar8[6];
              puVar7[7] = puVar8[7];
              puVar7[8] = puVar8[8];
              puVar7[9] = puVar8[9];
              puVar7[10] = puVar8[10];
              uVar13 = uVar13 + 1;
              puVar8 = puVar8 + 0xb;
              puVar7 = puVar7 + 0xb;
            } while (uVar13 != local_50);
          }
          FUN_001a7aba(uVar1,local_58);
          local_58 = puVar4;
        }
        local_50 = uVar9;
        local_104 = uVar11 * 0x2c;
        *local_100 = local_58[uVar11 * 0xb];
        local_100[1] = local_58[uVar11 * 0xb + 1];
        local_100[2] = local_58[uVar11 * 0xb + 2];
        local_100[3] = local_58[uVar11 * 0xb + 3];
        local_100[4] = local_58[uVar11 * 0xb + 4];
        local_100[5] = local_58[uVar11 * 0xb + 5];
        local_100[6] = local_58[uVar11 * 0xb + 6];
        local_100[7] = local_58[uVar11 * 0xb + 7];
        local_100[8] = local_58[uVar11 * 0xb + 8];
        local_100[9] = local_58[uVar11 * 0xb + 9];
        local_100[10] = local_58[uVar11 * 0xb + 10];
        if ((int)uVar11 < 1) goto LAB_0014f29c;
        local_70 = 0;
        local_108 = 1;
        local_10c = 0;
        local_f4 = uVar11;
        do {
          if (local_50 <= local_70) {
            if (local_40 < local_108) {
              uVar11 = (local_40 << 4) / 10;
              local_40 = local_108;
              if (local_108 <= uVar11) {
                local_40 = uVar11;
              }
              puVar4 = (undefined4 *)FUN_001a7bca(uVar1,local_40 * 0x2c);
              if (local_50 != 0) {
                uVar11 = 0;
                puVar7 = puVar4;
                puVar8 = local_58;
                do {
                  *puVar7 = *puVar8;
                  puVar7[1] = puVar8[1];
                  puVar7[2] = puVar8[2];
                  puVar7[3] = puVar8[3];
                  puVar7[4] = puVar8[4];
                  puVar7[5] = puVar8[5];
                  puVar7[6] = puVar8[6];
                  puVar7[7] = puVar8[7];
                  puVar7[8] = puVar8[8];
                  puVar7[9] = puVar8[9];
                  puVar7[10] = puVar8[10];
                  uVar11 = uVar11 + 1;
                  puVar8 = puVar8 + 0xb;
                  puVar7 = puVar7 + 0xb;
                } while (uVar11 != local_50);
              }
              FUN_001a7aba(uVar1,local_58);
              local_58 = puVar4;
            }
            local_50 = local_108;
          }
          piVar12 = (int *)((int)local_58 + local_10c);
          iVar5 = *piVar12;
          if (local_50 <= local_70) {
            if (local_40 < local_108) {
              uVar11 = (local_40 << 4) / 10;
              local_40 = local_108;
              if (local_108 <= uVar11) {
                local_40 = uVar11;
              }
              puVar4 = (undefined4 *)FUN_001a7bca(uVar1,local_40 * 0x2c);
              if (local_50 != 0) {
                uVar11 = 0;
                puVar7 = puVar4;
                puVar8 = local_58;
                do {
                  *puVar7 = *puVar8;
                  puVar7[1] = puVar8[1];
                  puVar7[2] = puVar8[2];
                  puVar7[3] = puVar8[3];
                  puVar7[4] = puVar8[4];
                  puVar7[5] = puVar8[5];
                  puVar7[6] = puVar8[6];
                  puVar7[7] = puVar8[7];
                  puVar7[8] = puVar8[8];
                  puVar7[9] = puVar8[9];
                  puVar7[10] = puVar8[10];
                  uVar11 = uVar11 + 1;
                  puVar8 = puVar8 + 0xb;
                  puVar7 = puVar7 + 0xb;
                } while (uVar11 != local_50);
              }
              FUN_001a7aba(uVar1,local_58);
              piVar12 = (int *)((int)puVar4 + local_10c);
              local_58 = puVar4;
            }
            local_50 = local_108;
          }
          iVar6 = local_d4;
          if (local_d0 != iVar5) {
            iVar6 = iVar5;
          }
          iVar5 = piVar12[1];
          if (local_d0 == piVar12[1]) {
            iVar5 = local_d4;
          }
          if (iVar6 == iVar5) {
LAB_0014eebf:
            local_108 = local_108 - 1;
            uVar11 = local_50;
            if ((local_50 <= local_70) && (uVar11 = local_70 + 1, local_40 < uVar11)) {
              local_40 = (local_40 << 4) / 10;
              if (local_40 < uVar11) {
                local_40 = uVar11;
              }
              puVar4 = (undefined4 *)FUN_001a7bca(uVar1,local_40 * 0x2c);
              if (local_50 != 0) {
                uVar9 = 0;
                puVar7 = puVar4;
                puVar8 = local_58;
                do {
                  *puVar7 = *puVar8;
                  puVar7[1] = puVar8[1];
                  puVar7[2] = puVar8[2];
                  puVar7[3] = puVar8[3];
                  puVar7[4] = puVar8[4];
                  puVar7[5] = puVar8[5];
                  puVar7[6] = puVar8[6];
                  puVar7[7] = puVar8[7];
                  puVar7[8] = puVar8[8];
                  puVar7[9] = puVar8[9];
                  puVar7[10] = puVar8[10];
                  uVar9 = uVar9 + 1;
                  puVar8 = puVar8 + 0xb;
                  puVar7 = puVar7 + 0xb;
                } while (uVar9 != local_50);
              }
              FUN_001a7aba(uVar1,local_58);
              piVar12 = (int *)((int)puVar4 + local_10c);
              local_58 = puVar4;
            }
            local_50 = uVar11;
            uVar11 = local_50;
            if ((local_50 <= local_f4 - 1) && (uVar11 = local_f4, local_40 < local_f4)) {
              uVar9 = (local_40 << 4) / 10;
              local_40 = local_f4;
              if (local_f4 <= uVar9) {
                local_40 = uVar9;
              }
              puVar4 = (undefined4 *)FUN_001a7bca(uVar1,local_40 * 0x2c);
              if (local_50 != 0) {
                uVar9 = 0;
                puVar7 = puVar4;
                puVar8 = local_58;
                do {
                  *puVar7 = *puVar8;
                  puVar7[1] = puVar8[1];
                  puVar7[2] = puVar8[2];
                  puVar7[3] = puVar8[3];
                  puVar7[4] = puVar8[4];
                  puVar7[5] = puVar8[5];
                  puVar7[6] = puVar8[6];
                  puVar7[7] = puVar8[7];
                  puVar7[8] = puVar8[8];
                  puVar7[9] = puVar8[9];
                  puVar7[10] = puVar8[10];
                  uVar9 = uVar9 + 1;
                  puVar8 = puVar8 + 0xb;
                  puVar7 = puVar7 + 0xb;
                } while (uVar9 != local_50);
              }
              FUN_001a7aba(uVar1,local_58);
              local_58 = puVar4;
            }
            local_50 = uVar11;
            *piVar12 = *(int *)(local_104 + -0x2c + (int)local_58);
            piVar12[1] = *(int *)(local_104 + -0x28 + (int)local_58);
            piVar12[2] = *(int *)(local_104 + -0x24 + (int)local_58);
            piVar12[3] = *(int *)(local_104 + -0x20 + (int)local_58);
            piVar12[4] = *(int *)(local_104 + -0x1c + (int)local_58);
            piVar12[5] = *(int *)(local_104 + -0x18 + (int)local_58);
            piVar12[6] = *(int *)(local_104 + -0x14 + (int)local_58);
            piVar12[7] = *(int *)(local_104 + -0x10 + (int)local_58);
            piVar12[8] = *(int *)(local_104 + -0xc + (int)local_58);
            piVar12[9] = *(int *)(local_104 + -8 + (int)local_58);
            piVar12[10] = *(int *)(local_104 + -4 + (int)local_58);
            local_10c = local_10c + -0x2c;
            local_104 = local_104 + -0x2c;
            local_f4 = local_f4 - 1;
            local_70 = local_70 - 1;
          }
          else {
            if (local_50 <= local_70) {
              if (local_40 < local_108) {
                uVar11 = (local_40 << 4) / 10;
                local_40 = local_108;
                if (local_108 <= uVar11) {
                  local_40 = uVar11;
                }
                puVar4 = (undefined4 *)FUN_001a7bca(uVar1,local_40 * 0x2c);
                if (local_50 != 0) {
                  uVar11 = 0;
                  puVar7 = puVar4;
                  puVar8 = local_58;
                  do {
                    *puVar7 = *puVar8;
                    puVar7[1] = puVar8[1];
                    puVar7[2] = puVar8[2];
                    puVar7[3] = puVar8[3];
                    puVar7[4] = puVar8[4];
                    puVar7[5] = puVar8[5];
                    puVar7[6] = puVar8[6];
                    puVar7[7] = puVar8[7];
                    puVar7[8] = puVar8[8];
                    puVar7[9] = puVar8[9];
                    puVar7[10] = puVar8[10];
                    uVar11 = uVar11 + 1;
                    puVar8 = puVar8 + 0xb;
                    puVar7 = puVar7 + 0xb;
                  } while (uVar11 != local_50);
                }
                FUN_001a7aba(uVar1,local_58);
                piVar12 = (int *)((int)puVar4 + local_10c);
                local_58 = puVar4;
              }
              local_50 = local_108;
            }
            cVar3 = ((int (*)())FUN_0014be46)(param_1,iVar6,iVar5,piVar12);
            if (cVar3 == '\0') goto LAB_0014eebf;
          }
          local_70 = local_70 + 1;
          local_10c = local_10c + 0x2c;
          local_108 = local_108 + 1;
        } while ((int)local_70 < (int)local_f4);
      } while (0 < (int)local_f4);
      iVar5 = param_1[1];
    }
  }
LAB_0014f05d:
  FUN_000f0346(iVar5,"post_pack_insts");
  FUN_001a7aba(uVar1,local_58);
  return;
}

/* FUN_0014fa92 @ 0x14fa92 (105 bytes) */
int FUN_0014fa92(param_1)
  int param_1;
{
  int local_28 [3];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_28[0] = *(int *)(param_1 + 8);
  local_1c = *(undefined4 *)(local_28[0] + 0xbc);
  local_18 = 0;
  local_14 = 0x10;
  local_10 = FUN_001a7bca(local_1c,0x200);
  FUN_00149328(local_28,param_1);
  ((int (*)())FUN_0014e2c2)(local_28);
  FUN_001a7aba(local_1c,local_10);
  return;
}

/* FUN_0014fb18 @ 0x14fb18 (21 bytes) */
int FUN_0014fb18(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_0010b180();
    return uVar1;
  }
  return param_3;
}

/* FUN_0014fb2e @ 0x14fb2e (43 bytes) */
int FUN_0014fb2e()
{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = &STACKARG(0x8);
  pcVar2 = &STACKARG(0x4);
  while ((*pcVar1 != '\x01' || (*pcVar2 == '\x04'))) {
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
    if (pcVar1 == &STACKARG(0xc)) {
      return 1;
    }
  }
  return 0;
}

/* FUN_0014fb5a @ 0x14fb5a (98 bytes) */
int FUN_0014fb5a(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  int param_3;
  int param_4;
{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = (**(code **)(*param_2 + 0x5c))(param_2);
  if ((cVar1 == '\0') && (param_3 == '\0')) {
    uVar2 = (**(code **)(**(int **)(param_4 + 0x54) + 0x100))(*(int **)(param_4 + 0x54),param_1);
    return uVar2;
  }
  uVar2 = (**(code **)(**(int **)(param_4 + 0x54) + 0x108))(*(int **)(param_4 + 0x54),param_1);
  return uVar2;
}

/* FUN_0014fbbc @ 0x14fbbc (67 bytes) */
int FUN_0014fbbc(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_0010b180(param_1,param_2);
  cVar1 = (**(code **)(*piVar2 + 0x60))(piVar2);
  if (cVar1 == '\0') {
    return piVar2;
  }
  piVar2 = (int *)FUN_0010b180();
  return piVar2;
}

/* FUN_0014fc00 @ 0x14fc00 (49 bytes) */
int FUN_0014fc00(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((*(char *)(param_1 + 0x120) == *(char *)(param_2 + 0x120)) &&
     (*(int *)(param_1 + 0x124) == *(int *)(param_2 + 0x124))) {
    return 1;
  }
  return 0;
}

/* FUN_0014fc32 @ 0x14fc32 (73 bytes) */
int FUN_0014fc32(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  char cVar1;
  
  cVar1 = FUN_0010a62e(param_1,param_2);
  if ((((cVar1 != '\0') && (*(char *)(param_1 + 0x120) == '\0')) && (*(int *)(param_1 + 0x124) == 0)
      ) && ((*(byte *)(param_1 + 0x15) & 2) == 0)) {
    return 1;
  }
  return 0;
}

/* FUN_0014fc7c @ 0x14fc7c (85 bytes) */
int FUN_0014fc7c(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int *piVar2;
  char cVar3;
  
  cVar3 = FUN_00140aa2(param_1);
  if (cVar3 != '\0') {
    piVar1 = *(int **)(param_2 + 0x394);
    for (piVar2 = *(int **)(param_1 + 0x158); piVar1 != piVar2; piVar2 = (int *)piVar2[0x3b]) {
      cVar3 = (**(code **)(*piVar2 + 0x24))(piVar2);
      if (cVar3 != '\0') {
        return 0;
      }
    }
  }
  return 1;
}

/* FUN_0014fcd2 @ 0x14fcd2 (139 bytes) */
int FUN_0014fcd2(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  undefined4 param_3;
{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)param_2[0x56];
  if (piVar2 == (int *)param_1[0x56]) {
    do {
      param_2 = (int *)param_2[1];
      cVar1 = (**(code **)(*param_2 + 0x34))(param_2);
      if (cVar1 != '\0') {
        return 0;
      }
    } while (param_2 != param_1);
  }
  else {
    cVar1 = (**(code **)(*piVar2 + 0x1c))(piVar2);
    if (cVar1 != '\0') {
      return 0;
    }
    FUN_000edd54(param_3);
    piVar2 = *(int **)(param_2[0x56] + 0xec);
    if (piVar2 != (int *)param_1[0x56]) {
      do {
        cVar1 = (**(code **)(*piVar2 + 0x1c))(piVar2);
        if (cVar1 != '\0') {
          return 0;
        }
        piVar2 = (int *)piVar2[0x3b];
      } while (piVar2 != (int *)param_1[0x56]);
    }
  }
  return 1;
}

/* FUN_0014fd5e @ 0x14fd5e (52 bytes) */
int FUN_0014fd5e(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  
  if (param_3 != '\0') {
    iVar1 = FUN_00109e42(param_1,param_2);
    if (iVar1 != *(int *)(*(int *)(param_1 + 0x10) + 4)) {
      return 0;
    }
  }
  return 1;
}

/* FUN_0014fd92 @ 0x14fd92 (358 bytes) */
int FUN_0014fd92(param_1, param_2)
  int *param_1;
  int *param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  iVar5 = FUN_0010b180(*param_1,param_1[1]);
  uVar1 = *(uint *)(iVar5 + 0xb8);
  iVar5 = FUN_0010b180(*param_1,param_1[1]);
  uVar2 = *(uint *)(iVar5 + 0xd0);
  uVar3 = *(uint *)(*param_1 + 0xa0 + param_1[1] * 0x18);
  uVar6 = param_1[1] & 0x80000001;
  if ((int)uVar6 < 0) {
    uVar6 = (uVar6 - 1 | 0xfffffffe) + 1;
  }
  uVar6 = *(uint *)(*param_1 + 0xb8 + uVar6 * 0x18);
  iVar5 = FUN_0010b180(*param_2,param_2[1]);
  uVar4 = *(uint *)(iVar5 + 0xb8);
  iVar5 = FUN_0010b180(*param_2,param_2[1]);
  uVar7 = param_2[1] & 0x80000001;
  if ((int)uVar7 < 0) {
    uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;
  }
  return ((-(uint)((uVar3 & 1) == 0) & 2) - 1) *
         ((-(uint)((uVar1 & 1) == 0) & 2) - 1) * ((-(uint)((uVar2 & 1) == 0) & 2) - 1) *
         ((-(uint)((uVar6 & 1) == 0) & 2) - 1) ==
         ((-(uint)((*(uint *)(*param_2 + 0xb8 + uVar7 * 0x18) & 1) == 0) & 2) - 1) *
         ((-(uint)((*(uint *)(*param_2 + 0xa0 + param_2[1] * 0x18) & 1) == 0) & 2) - 1) *
         ((-(uint)((uVar4 & 1) == 0) & 2) - 1) *
         ((-(uint)((*(uint *)(iVar5 + 0xd0) & 1) == 0) & 2) - 1);
}

/* FUN_0014fef8 @ 0x14fef8 (311 bytes) */
int FUN_0014fef8(param_1)
  int *param_1;
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  int local_2c;
  int local_24;
  
  if (*(int *)(param_1[0x22] + 8) != 0x12) {
    return 0;
  }
  local_2c = 0;
  do {
    iVar3 = FUN_0010b0f4(param_1,0);
    if (*(char *)(local_2c + 0x10 + iVar3) != '\x01') {
      bVar1 = false;
      local_24 = 1;
      iVar3 = (**(code **)(*param_1 + 0x14))(param_1);
      if (0 < iVar3) {
        do {
          iVar3 = FUN_0010b0f4(param_1,local_24);
          uVar6 = (uint)*(byte *)(local_2c + 0x10 + iVar3);
          piVar4 = (int *)FUN_0010b180(param_1,local_24);
          cVar2 = (**(code **)(*piVar4 + 0x60))(piVar4);
          if (cVar2 != '\0') {
            uVar5 = FUN_0010a088(piVar4,uVar6);
            iVar3 = FUN_0010b0f4(piVar4,uVar5);
            uVar6 = (uint)*(byte *)(uVar6 + 0x10 + iVar3);
            piVar4 = (int *)FUN_0010b180(piVar4,uVar5);
          }
          if (((((int)(char)piVar4[0x57] >> ((byte)uVar6 & 0x1f) & 1U) == 0) ||
              ((float)piVar4[uVar6 * 6 + 8] != 0.0)) || (NAN((float)piVar4[uVar6 * 6 + 8]))) {
            if (bVar1) {
              return 0;
            }
            bVar1 = true;
          }
          local_24 = local_24 + 1;
          iVar3 = (**(code **)(*param_1 + 0x14))(param_1);
        } while (local_24 <= iVar3);
      }
    }
    local_2c = local_2c + 1;
  } while (local_2c != 4);
  return 1;
}

/* FUN_00150030 @ 0x150030 (81 bytes) */
int FUN_00150030(param_1)
  int param_1;
{
  char cVar1;
  
  cVar1 = ((int (*)())FUN_0014fef8)(param_1);
  if (cVar1 == '\0') {
    switch(*(undefined4 *)(*(int *)(param_1 + 0x88) + 8)) {
    case 0x13:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x31:
    case 0x3e:
    case 0x3f:
    case 0x40:
      break;
    default:
      return 0;
    }
  }
  return 1;
}

/* FUN_0015013c @ 0x15013c (345 bytes) */
int FUN_0015013c(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) != 0x12) {
    return 0;
  }
  iVar5 = FUN_0010b180(param_1,1);
  iVar6 = FUN_0010b180(param_1,2);
  iVar1 = *(int *)(*(int *)(iVar6 + 0x88) + 8);
  if ((((*(int *)(*(int *)(iVar5 + 0x88) + 8) == 0x13) && ((*(byte *)(param_1 + 0xb8) & 2) == 0)) &&
      (cVar4 = FUN_000f6cc2(param_1,1), cVar4 != '\0')) &&
     ((*(char *)(iVar5 + 0x120) == '\0' && (*(int *)(iVar5 + 0x124) == 0)))) {
    if (param_3 == '\0') {
      bVar2 = true;
    }
    else {
      cVar4 = FUN_0010a62e(iVar5,param_2);
      if (cVar4 == '\0') goto LAB_001501a0;
      bVar2 = true;
    }
  }
  else {
LAB_001501a0:
    bVar2 = false;
  }
  if (((iVar1 == 0x13) && ((*(byte *)(param_1 + 0xd0) & 2) == 0)) &&
     ((cVar4 = FUN_000f6cc2(param_1,2), cVar4 != '\0' &&
      ((*(char *)(iVar6 + 0x120) == '\0' && (*(int *)(iVar6 + 0x124) == 0)))))) {
    if (param_3 == '\0') {
      bVar3 = true;
      goto LAB_001501aa;
    }
    cVar4 = FUN_0010a62e(iVar6,param_2);
    if (cVar4 != '\0') {
      bVar3 = true;
      goto LAB_001501aa;
    }
  }
  bVar3 = false;
LAB_001501aa:
  if ((!bVar2) && (!bVar3)) {
    return 0;
  }
  return 1;
}

/* FUN_00150296 @ 0x150296 (214 bytes) */
int FUN_00150296(param_1, param_2)
  int *param_1;
  int *param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = (**(code **)(*param_1 + 0x5c))(param_1);
  if (((cVar1 != '\0') && (cVar1 = (**(code **)(*param_2 + 0x5c))(param_2), cVar1 != '\0')) &&
     (*(int *)(param_1[0x22] + 8) == *(int *)(param_2[0x22] + 8))) {
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar2 == iVar3) {
      iVar2 = FUN_0010b180(param_1,1);
      iVar3 = FUN_0010b180(param_2,1);
      if (iVar2 == iVar3) {
        iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
        if (iVar2 != 2) {
          return 1;
        }
        iVar2 = FUN_0010b180(param_1,2);
        iVar3 = FUN_0010b180(param_2,2);
        if (iVar2 == iVar3) {
          return 1;
        }
      }
    }
  }
  return 0;
}

/* FUN_0015036c @ 0x15036c (43 bytes) */
int FUN_0015036c(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  
  if (param_1 != param_2) {
    cVar1 = ((int (*)())FUN_00150296)(param_1,param_2);
    if (cVar1 == '\0') {
      return 0;
    }
  }
  return 1;
}

/* FUN_00150398 @ 0x150398 (85 bytes) */
int FUN_00150398(param_1, param_2)
  int *param_1;
  int *param_2;
{
  char cVar1;
  undefined1 uVar2;
  
  if (param_1 == param_2) {
    return 1;
  }
  cVar1 = (**(code **)(*param_1 + 0x5c))(param_1);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*param_2 + 0x5c))(param_2);
    if (cVar1 != '\0') {
      uVar2 = ((int (*)())FUN_00150296)(param_1,param_2);
      return uVar2;
    }
  }
  return 0;
}

/* FUN_001503ee @ 0x1503ee (171 bytes) */
int FUN_001503ee(param_1, param_2)
  int *param_1;
  int *param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_10;
  
  cVar1 = (**(code **)(*param_1 + 0x5c))(param_1);
  if ((cVar1 != '\0') && (cVar1 = (**(code **)(*param_2 + 0x5c))(param_2), cVar1 != '\0')) {
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
    if (*(int *)(param_1[0x22] + 8) != *(int *)(param_2[0x22] + 8)) {
      return 1;
    }
    (**(code **)(*param_2 + 0x14))(param_2);
    if (0 < iVar2) {
      local_10 = 1;
      do {
        iVar3 = FUN_0010b180(param_1,local_10);
        iVar4 = FUN_0010b180(param_2,local_10);
        if (iVar3 != iVar4) {
          return 1;
        }
        local_10 = local_10 + 1;
      } while (local_10 <= iVar2);
    }
  }
  return 0;
}

/* FUN_0015049a @ 0x15049a (304 bytes) */
int FUN_0015049a(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  uint uVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  byte bVar6;
  
  iVar5 = FUN_0010b180(*param_1,param_1[1]);
  if (((*(byte *)(iVar5 + 0x15) & 2) == 0) &&
     ((cVar4 = FUN_0010a62e(iVar5,param_2), cVar4 != '\0' ||
      (cVar4 = FUN_0010a67e(iVar5,param_2), cVar4 != '\0')))) {
    uVar1 = param_1[1];
    iVar2 = *param_1;
    bVar6 = ~(byte)(*(uint *)(iVar2 + 0xa0 + uVar1 * 0x18) >> 1) & 1;
  }
  else {
    uVar1 = param_1[1];
    iVar2 = *param_1;
    bVar6 = 0;
  }
  uVar1 = uVar1 & 0x80000001;
  if ((int)uVar1 < 0) {
    bVar3 = (byte)(*(uint *)(iVar2 + 0xb8 + ((uVar1 - 1 | 0xfffffffe) + 1) * 0x18) >> 1);
    iVar2 = *(int *)(*(int *)(iVar5 + 0x88) + 8);
  }
  else {
    bVar3 = (byte)(*(uint *)(iVar2 + 0xb8 + uVar1 * 0x18) >> 1);
    iVar2 = *(int *)(*(int *)(iVar5 + 0x88) + 8);
  }
  bVar6 = ~bVar3 & bVar6;
  if (iVar2 == 0x12) {
    if ((*(char *)(iVar5 + 0x120) != '\0') || (*(int *)(iVar5 + 0x124) != 0)) {
      bVar6 = 0;
    }
    return bVar6;
  }
  return (*(byte *)(iVar5 + 0x120) ^ 1) & bVar6;
}

/* FUN_001505ca @ 0x1505ca (490 bytes) */
int FUN_001505ca(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int *param_5;
  int *param_6;
{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  param_2 = param_2 + 1;
  iVar3 = FUN_0010b180(param_1,1);
  iVar4 = FUN_0010b180(param_1,2);
  iVar1 = param_3;
  if ((param_2 == 1) && (iVar1 = 0x13, param_3 != 0x14)) {
    iVar1 = param_3;
  }
  iVar5 = param_2;
  if (iVar3 != iVar4) {
    if ((((*(int *)(*(int *)(iVar3 + 0x88) + 8) == iVar1) &&
         (cVar2 = ((int (*)())FUN_0014fc32)(iVar3,param_4), cVar2 != '\0')) &&
        ((*(uint *)(param_1 + 0xb8) & 1) == 0)) &&
       ((((*(uint *)(param_1 + 0xb8) & 2) == 0 && (iVar6 = FUN_0010b6e4(param_1,1), iVar6 == 0)) &&
        (*(int *)(param_1 + 0x158) == *(int *)(iVar3 + 0x158))))) {
      iVar5 = ((int (*)())FUN_001505ca)(iVar3,param_2,iVar1,param_4,param_5,param_6);
    }
    iVar3 = param_2;
    if (((*(int *)(*(int *)(iVar4 + 0x88) + 8) == iVar1) &&
        (cVar2 = ((int (*)())FUN_0014fc32)(iVar4,param_4), cVar2 != '\0')) &&
       (((*(uint *)(param_1 + 0xd0) & 1) == 0 &&
        ((((*(uint *)(param_1 + 0xd0) & 2) == 0 && (iVar6 = FUN_0010b6e4(param_1,2), iVar6 == 0)) &&
         (*(int *)(param_1 + 0x158) == *(int *)(iVar4 + 0x158))))))) {
      iVar3 = ((int (*)())FUN_001505ca)(iVar4,param_2,iVar1,param_4,param_5,param_6);
    }
    if ((param_2 != iVar5) || (param_2 != iVar3)) {
      if (iVar5 < iVar3) {
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x4000;
        return iVar3;
      }
      goto LAB_0015063c;
    }
  }
  if (param_2 <= *param_6) {
    return *param_6;
  }
  *param_5 = param_1;
  *param_6 = param_2;
LAB_0015063c:
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xffffbfff;
  return iVar5;
}

/* FUN_001507b4 @ 0x1507b4 (484 bytes) */
int FUN_001507b4(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int **local_48;
  int *local_3c;
  int local_38;
  int local_20;
  int *local_1c;
  int aiStack_18 [3];
  
  if ((((*(int *)(param_2[0x22] + 8) != 0x8e) &&
       (cVar2 = (**(code **)(*param_2 + 0x68))(param_2), cVar2 == '\0')) && (param_2[0x21] != 0)) &&
     ((*(byte *)(param_2 + 5) & 8) == 0)) {
    piVar3 = (int *)param_2[0x56];
    if (0 < param_2[0x21]) {
      iVar5 = 1;
      local_48 = &local_1c;
      do {
        iVar6 = FUN_0010b180(param_2,iVar5);
        *local_48 = *(int **)(iVar6 + 0x158);
        iVar5 = iVar5 + 1;
        local_48 = local_48 + 1;
      } while (iVar5 <= param_2[0x21]);
    }
    local_3c = piVar3;
    do {
      if (0 < param_2[0x21]) {
        if (piVar3 == local_1c) {
          local_38 = 1;
        }
        else {
          local_38 = 1;
          do {
            local_38 = local_38 + 1;
            if (param_2[0x21] < local_38) goto LAB_0015084d;
          } while (piVar3 != (int *)(&local_20)[local_38]);
        }
        local_3c = (int *)(&local_20)[local_38];
        if (local_38 != 0) goto LAB_001508ab;
      }
LAB_0015084d: ;
    } while ((piVar3 != (int *)0x0) && (piVar3 = (int *)piVar3[0x3b], piVar3 != (int *)0x0));
    local_38 = 0;
LAB_001508ab:
    cVar2 = (**(code **)(*local_3c + 0x2c))(local_3c);
    if (cVar2 != '\0') {
      FUN_00109e26(param_2);
      param_2[5] = param_2[5] | 1;
      FUN_000e9540();
      return;
    }
    FUN_0010b180(param_2,local_38);
    iVar5 = *(int *)(local_3c[0x28] + 4);
    if (iVar5 != 0) {
      iVar6 = param_2[0x21];
      iVar1 = local_3c[0x28];
      while( true ) {
        if (0 < iVar6) {
          iVar6 = 1;
          do {
            iVar4 = FUN_0010b180(param_2,iVar6);
            if ((iVar4 == iVar1) || (*(int *)(*(int *)(iVar1 + 0x88) + 8) == 0x8e)) {
              FUN_00109e26(param_2);
              param_2[5] = param_2[5] | 1;
              FUN_000e9596();
              return;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 <= param_2[0x21]);
        }
        if (*(int *)(iVar5 + 4) == 0) break;
        iVar6 = param_2[0x21];
        iVar1 = iVar5;
        iVar5 = *(int *)(iVar5 + 4);
      }
    }
  }
  return;
}

/* FUN_00150998 @ 0x150998 (649 bytes) */
int FUN_00150998(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  int local_28;
  int local_24;
  int local_18 [3];
  
  local_18[1] = FUN_0010b180(param_1,1);
  local_18[0] = local_18[1];
  if (param_2 != 0) {
    local_18[1] = FUN_0010b180(param_2,1);
  }
  bVar7 = local_18[1] != local_18[0];
  iVar4 = bVar7 + 1;
  local_18[2] = local_18[0];
  if (param_3 != 0) {
    local_18[2] = FUN_0010b180(param_3,1);
  }
  local_28 = iVar4;
  if (local_18[2] != local_18[1]) {
    if (iVar4 == 1) {
      local_18[1] = local_18[2];
      goto LAB_00150a24;
    }
    local_28 = bVar7 + 2;
    if (local_18[2] == local_18[0]) {
      local_28 = iVar4;
    }
  }
  if (local_28 == 0) {
    return;
  }
LAB_00150a24:
  local_24 = 0;
  do {
    piVar1 = (int *)local_18[local_24];
    if (piVar1 != (int *)0x0) {
      iVar4 = piVar1[0x22];
      iVar2 = *(int *)(iVar4 + 8);
      while ((iVar2 != 0x3a && (*(int *)(iVar4 + 8) != 0x3b))) {
        cVar3 = (**(code **)(*piVar1 + 100))(piVar1);
        if (cVar3 == '\0') {
          iVar4 = piVar1[0x22];
          if (*(int *)(iVar4 + 8) == 0x13) {
            piVar6 = (int *)FUN_0010b180(piVar1,1);
            piVar5 = (int *)FUN_0010b180(piVar1,2);
            cVar3 = (**(code **)(*piVar6 + 0x48))(piVar6);
            if (cVar3 == '\0') {
              FUN_0010b3fe(piVar5,*(undefined4 *)(param_4 + 8));
              piVar5 = piVar6;
            }
            else {
              FUN_0010b3fe(piVar6,*(undefined4 *)(param_4 + 8));
            }
            goto LAB_00150aca;
          }
          if ((*(int *)(iVar4 + 8) == 0x12) || (piVar5 = piVar1, *(int *)(iVar4 + 8) == 0x9b)) {
            piVar5 = (int *)FUN_0010b180(piVar1,1);
            (**(code **)(*piVar1 + 0xc))(piVar1,0,*(undefined4 *)(param_4 + 8));
            FUN_0010b3fe(piVar5,*(undefined4 *)(param_4 + 8));
            goto LAB_00150ae6;
          }
        }
        else {
          piVar5 = (int *)FUN_0010b180(piVar1,1);
LAB_00150aca:
          (**(code **)(*piVar1 + 0xc))(piVar1,0,*(undefined4 *)(param_4 + 8));
LAB_00150ae6:
          if (piVar5 == (int *)0x0) goto LAB_00150aa1;
          iVar4 = piVar5[0x22];
        }
        iVar2 = *(int *)(iVar4 + 8);
        piVar1 = piVar5;
      }
      if (((*(byte *)((int)piVar1 + 0x15) & 2) != 0) &&
         (piVar5 = (int *)FUN_0010b180(piVar1,piVar1[0x21]), piVar5 != (int *)0x0)) {
        if (((*(byte *)((int)piVar5 + 0x15) & 2) != 0) &&
           (piVar6 = (int *)FUN_0010b180(piVar5,piVar5[0x21]), piVar6 != (int *)0x0)) {
          (**(code **)(*piVar6 + 0xc))(piVar6,0,*(undefined4 *)(param_4 + 8));
        }
        (**(code **)(*piVar5 + 0xc))(piVar5,0,*(undefined4 *)(param_4 + 8));
      }
      (**(code **)(*piVar1 + 0xc))(piVar1,0,*(undefined4 *)(param_4 + 8));
    }
LAB_00150aa1:
    local_24 = local_24 + 1;
    if (local_28 == local_24) {
      return;
    }
  } while( true );
}

/* FUN_00150c22 @ 0x150c22 (345 bytes) */
int FUN_00150c22(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  int *piVar8;
  int iVar9;
  undefined4 uVar10;
  
  piVar8 = (int *)FUN_0010b180(param_1,1);
  iVar2 = *(int *)(param_1 + 0x124);
  cVar1 = *(char *)(param_1 + 0x120);
  bVar6 = true;
  bVar5 = true;
  while( true ) {
    cVar7 = (**(code **)(*piVar8 + 0x24))(piVar8);
    if (cVar7 == '\0') {
      return;
    }
    cVar7 = FUN_0010a62e(piVar8,param_2);
    if (cVar7 == '\0') {
      return;
    }
    if ((char)piVar8[0x48] != '\0') {
      bVar6 = false;
    }
    piVar3 = *(int **)(*(int *)(param_2 + 8) + 0x54);
    cVar7 = (**(code **)(*piVar3 + 0xfc))(piVar3,iVar2 + piVar8[0x49],piVar8);
    if (cVar7 == '\0') {
      bVar5 = false;
    }
    if ((*(byte *)((int)piVar8 + 0x15) & 2) == 0) break;
    piVar8 = (int *)FUN_0010b180(piVar8,piVar8[0x21]);
  }
  if (iVar2 != 0) {
    if (!bVar6) {
      return;
    }
    if (!bVar5) {
      return;
    }
  }
  uVar10 = 1;
  iVar9 = param_1;
  while( true ) {
    iVar9 = FUN_0010b180(iVar9,uVar10);
    if (iVar9 == 0) {
      return;
    }
    iVar4 = *(int *)(iVar9 + 0x124);
    if (iVar2 != 0) {
      *(int *)(param_2 + 0x170) = *(int *)(param_2 + 0x170) + 1;
      *(int *)(iVar9 + 0x124) = iVar2 + iVar4;
      *(undefined4 *)(param_1 + 0x124) = 0;
    }
    if (((cVar1 != '\0') && ((*(uint *)(param_1 + 0xb8) & 1) == 0)) &&
       ((*(uint *)(param_1 + 0xb8) & 2) == 0)) {
      *(int *)(param_2 + 0x170) = *(int *)(param_2 + 0x170) + 1;
      *(undefined1 *)(iVar9 + 0x120) = 1;
      *(undefined1 *)(param_1 + 0x120) = 0;
    }
    if ((*(byte *)(iVar9 + 0x15) & 2) == 0) break;
    uVar10 = *(undefined4 *)(iVar9 + 0x84);
  }
  return;
}

/* FUN_00150d7c @ 0x150d7c (978 bytes) */
int FUN_00150d7c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  undefined1 *param_7;
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 local_10;
  
  piVar4 = (int *)FUN_0010b180(param_1,param_2);
  piVar5 = (int *)FUN_0010b180(param_3,param_4);
  if (piVar4 != piVar5) {
    cVar3 = (**(code **)(*piVar4 + 0x5c))(piVar4);
    if ((cVar3 == '\0') || (cVar3 = (**(code **)(*piVar5 + 0x5c))(piVar5), cVar3 == '\0')) {
      cVar3 = (**(code **)(*piVar4 + 0x5c))(piVar4);
      if ((cVar3 == '\0') || (cVar3 = (**(code **)(*piVar5 + 0x5c))(piVar5), cVar3 != '\0')) {
        cVar3 = (**(code **)(*piVar4 + 0x5c))(piVar4);
        if ((cVar3 == '\0') && (cVar3 = (**(code **)(*piVar5 + 0x5c))(piVar5), cVar3 != '\0')) {
          piVar6 = *(int **)(*(int *)(param_5 + 8) + 0x54);
          cVar3 = (**(code **)(*piVar6 + 0x10c))
                            (piVar6,param_1,param_2,piVar4,param_5,param_6,0,&local_10);
          if (cVar3 == '\0') {
            return 0;
          }
          cVar3 = ((int (*)())FUN_00150296)(piVar5,local_10);
          if (cVar3 == '\0') {
            return 0;
          }
          *param_7 = 1;
        }
        else {
          piVar6 = piVar4;
          if ((*(byte *)((int)piVar4 + 0x15) & 2) == 0) {
            if ((*(byte *)((int)piVar5 + 0x15) & 2) == 0) {
              return 0;
            }
            piVar6 = (int *)FUN_0010b180(piVar5,piVar5[0x21]);
            if (piVar4 != piVar6) {
              return 0;
            }
            cVar3 = FUN_000f6c46(param_3,param_4);
            if (cVar3 == '\0') {
              return 0;
            }
            if (param_6 != '\0') {
              FUN_0010ba02(param_1,param_2,piVar5,0,*(undefined4 *)(param_5 + 8));
              if (*(int *)(param_5 + 0x46c) < piVar5[0x58]) {
                piVar5[0x58] = piVar5[0x58] + 1;
              }
              else {
                piVar5[0x58] = *(int *)(param_5 + 0x46c) + 1;
              }
              piVar4[0x58] = piVar4[0x58] + -1;
            }
          }
          else {
            do {
              if ((*(byte *)((int)piVar6 + 0x15) & 2) == 0) {
                return 0;
              }
              piVar6 = (int *)FUN_0010b180(piVar6,piVar6[0x21]);
            } while ((piVar5 != piVar6) || (cVar3 = FUN_000f6c46(param_1,param_2), cVar3 == '\0'));
            if (param_6 != '\0') {
              FUN_0010ba02(param_3,param_4,piVar4,0,*(undefined4 *)(param_5 + 8));
              if (*(int *)(param_5 + 0x46c) < piVar4[0x58]) {
                piVar4[0x58] = piVar4[0x58] + 1;
              }
              else {
                piVar4[0x58] = *(int *)(param_5 + 0x46c) + 1;
              }
              piVar5[0x58] = piVar5[0x58] + -1;
            }
          }
        }
        goto LAB_00150e98;
      }
      piVar6 = *(int **)(*(int *)(param_5 + 8) + 0x54);
      cVar3 = (**(code **)(*piVar6 + 0x10c))
                        (piVar6,param_3,param_4,piVar5,param_5,param_6,0,&local_10);
      if (cVar3 == '\0') {
        return 0;
      }
      cVar3 = ((int (*)())FUN_00150296)(piVar4,local_10);
    }
    else {
      cVar3 = ((int (*)())FUN_00150296)(piVar4,piVar5);
    }
    if (cVar3 == '\0') {
      return 0;
    }
  }
LAB_00150e98:
  if (((char)piVar4[0x48] == (char)piVar5[0x48]) && (piVar4[0x49] == piVar5[0x49])) {
    uVar1 = *(uint *)(param_1 + 0xa0 + param_2 * 0x18);
    uVar2 = *(uint *)(param_3 + 0xa0 + param_4 * 0x18);
    if ((((byte)uVar1 & 1) == ((byte)uVar2 & 1)) &&
       (((byte)(uVar1 >> 1) & 1) == ((byte)(uVar2 >> 1) & 1))) {
      iVar7 = FUN_0010b7c8(param_1,param_2);
      iVar8 = FUN_0010b7c8(param_3,param_4);
      if (iVar7 == iVar8) {
        iVar7 = FUN_0010b6e4(param_1,param_2);
        iVar8 = FUN_0010b6e4(param_3,param_4);
        if (iVar7 == iVar8) {
          return 1;
        }
      }
    }
  }
  return 0;
}

/* FUN_0015114e @ 0x15114e (2852 bytes) */
int FUN_0015114e(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int *param_3;
  int param_4;
{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int local_68;
  int local_64;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_1d [13];
  
  local_1d[0] = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x8e) {
    return 0;
  }
  if ((*(byte *)((int)param_3 + 0x15) & 2) == 0) {
    return 0;
  }
  cVar2 = FUN_0012dfd8(param_3[0x26]);
  if (cVar2 == '\0') {
    return 0;
  }
  cVar2 = (**(code **)(*param_3 + 100))(param_3);
  if ((((cVar2 == '\0') || ((char)param_3[0x48] != '\0')) || (param_3[0x49] != 0)) ||
     (((param_3[0x2e] & 1U) != 0 || ((param_3[0x2e] & 2U) != 0)))) {
    cVar2 = (**(code **)(*param_3 + 100))(param_3);
    if (cVar2 != '\0') {
      return 0;
    }
    piVar3 = (int *)FUN_0010b180(param_3,param_3[0x21]);
    cVar2 = (**(code **)(*piVar3 + 100))(piVar3);
    if (cVar2 == '\0') {
      return 0;
    }
    if ((*(byte *)((int)piVar3 + 0x15) & 2) != 0) {
      return 0;
    }
    if ((char)piVar3[0x48] != '\0') {
      return 0;
    }
    if (piVar3[0x49] != 0) {
      return 0;
    }
    if ((piVar3[0x2e] & 1U) != 0) {
      return 0;
    }
    if ((piVar3[0x2e] & 2U) != 0) {
      return 0;
    }
    cVar2 = FUN_000f7c08(piVar3,1,piVar3,param_4);
    if (cVar2 == '\0') {
      return 0;
    }
    *(int *)(param_4 + 0x228) = *(int *)(param_4 + 0x228) + 1;
    iVar9 = param_3[1];
    FUN_001a7d72(param_3);
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    FUN_00109d1c(param_3,&local_44,0xffffffff);
    iVar4 = FUN_0010a1c2(param_3,*(undefined4 *)(param_4 + 8),0);
    *(int *)(iVar4 + 0x160) = *(int *)(param_4 + 0x46c) + 1;
    *(undefined4 *)(iVar4 + 0x94) = *(undefined4 *)(iVar4 + 0x14c);
    FUN_0010ba02(iVar4,*(undefined4 *)(iVar4 + 0x84),0,0,*(undefined4 *)(param_4 + 8));
    *(int *)(iVar4 + 0x84) = *(int *)(iVar4 + 0x84) + -1;
    *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) & 0xfffffdff;
    FUN_000e9596(*(undefined4 *)(iVar9 + 0x158),iVar9,iVar4);
    FUN_0010f5da(param_3,0xa2,*(undefined4 *)(param_4 + 8));
    FUN_000e9596(*(undefined4 *)(iVar4 + 0x158),iVar4,param_3);
    iVar9 = FUN_0010b0f4(iVar4,0);
    uVar5 = *(undefined4 *)(iVar9 + 0x10);
    iVar9 = FUN_0010b0f4(iVar4,0);
    local_30 = *(int *)(iVar9 + 0x10);
    iVar9 = FUN_0010b0f4(piVar3,0);
    local_34 = *(undefined4 *)(iVar9 + 0x10);
    iVar9 = 0;
    do {
      iVar7 = FUN_0010b0f4(iVar4,0);
      if (*(char *)(iVar9 + 0x10 + iVar7) != '\x01') {
        *(undefined1 *)((int)&local_34 + iVar9) = 1;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != 4);
    iVar9 = FUN_0010b0f4(piVar3,0);
    local_2c = *(undefined4 *)(iVar9 + 0x10);
    iVar9 = 1;
    do {
      cVar2 = *(char *)((int)&local_30 + iVar9 + 3);
      if (cVar2 != '\x01') {
        *(char *)((int)&local_34 + iVar9 + 3) = cVar2;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != 5);
    param_3[0x25] = param_3[0x53];
    param_3[0x26] = 0x36;
    param_3[0x27] = local_30;
    FUN_00109d48(param_3,&local_44);
    param_3[0x21] = 2;
    FUN_0010ba02(param_3,1,iVar4,0,*(undefined4 *)(param_4 + 8));
    uVar5 = FUN_000f5fea(uVar5);
    uVar5 = FUN_000f5b96(DAT_001cc5a0,uVar5);
    iVar9 = FUN_0010b0f4(param_3,1);
    *(undefined4 *)(iVar9 + 0x10) = uVar5;
    uVar5 = *(undefined4 *)(param_4 + 8);
    uVar6 = FUN_0010b180(piVar3,1);
    FUN_0010ba02(param_3,2,uVar6,0,uVar5);
    uVar5 = FUN_000f5fea(local_34);
    iVar9 = FUN_0010b0f4(piVar3,1);
    uVar5 = FUN_000f5b96(*(undefined4 *)(iVar9 + 0x10),uVar5);
    iVar9 = FUN_0010b0f4(param_3,2);
    *(undefined4 *)(iVar9 + 0x10) = uVar5;
    uVar5 = *(undefined4 *)(param_4 + 8);
  }
  else {
    piVar3 = (int *)FUN_0010b180(param_3,param_3[0x21]);
    bVar1 = true;
    iVar9 = 0;
    do {
      iVar4 = FUN_0010b0f4(param_3,0);
      if (((*(char *)(iVar9 + 0x10 + iVar4) == '\x01') &&
          (iVar4 = FUN_0010b0f4(piVar3,0), *(char *)(iVar9 + 0x10 + iVar4) == '\x01')) &&
         ((*(byte *)((int)piVar3 + 0x15) & 2) != 0)) {
        bVar1 = false;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != 4);
    if (!bVar1) {
      return 0;
    }
    cVar2 = FUN_000f7c08(param_3,1,param_3,param_4);
    if (cVar2 != '\0') {
      *(int *)(param_4 + 0x228) = *(int *)(param_4 + 0x228) + 1;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      FUN_00109d1c(param_3,&local_44,0xffffffff);
      uVar5 = FUN_0010b180(param_3,1);
      iVar9 = FUN_0010b0f4(param_3,0);
      local_30 = *(int *)(iVar9 + 0x10);
      iVar9 = FUN_0010b0f4(piVar3,0);
      local_28 = *(undefined4 *)(iVar9 + 0x10);
      iVar9 = 1;
      do {
        cVar2 = *(char *)((int)&local_2c + iVar9 + 3);
        if (cVar2 != '\x01') {
          *(char *)((int)&local_34 + iVar9 + 3) = cVar2;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 != 5);
      local_34 = DAT_001cc5a0;
      iVar9 = 0;
      do {
        iVar4 = FUN_0010b0f4(param_3,0);
        if (*(char *)(iVar9 + 0x10 + iVar4) != '\x01') {
          *(undefined1 *)((int)&local_34 + iVar9) = 4;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 != 4);
      iVar9 = 1;
      do {
        if (*(char *)((int)&local_34 + iVar9 + 3) == '\x01') {
          *(undefined1 *)((int)&local_38 + iVar9 + 3) = 4;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 != 5);
      iVar9 = FUN_0010b0f4(param_3,1);
      local_38 = *(int *)(iVar9 + 0x10);
      iVar9 = param_3[1];
      FUN_001a7d72(param_3);
      FUN_0010f5da(param_3,0xa2,*(undefined4 *)(param_4 + 8));
      FUN_00109d48(param_3,&local_44);
      param_3[0x25] = param_3[0x53];
      param_3[0x26] = 0x36;
      param_3[0x27] = local_30;
      cVar2 = (**(code **)(*piVar3 + 0x60))(piVar3);
      if (cVar2 == '\0') {
        param_3[0x21] = 2;
        FUN_0010ba02(param_3,1,piVar3,0,*(undefined4 *)(param_4 + 8));
        uVar6 = local_34;
        iVar4 = FUN_0010b0f4(param_3,1);
        *(undefined4 *)(iVar4 + 0x10) = uVar6;
        FUN_0010ba02(param_3,2,uVar5,0,*(undefined4 *)(param_4 + 8));
        iVar4 = local_38;
        iVar7 = FUN_0010b0f4(param_3,2);
        *(int *)(iVar7 + 0x10) = iVar4;
      }
      else {
        param_3[0x21] = piVar3[0x21] + 1;
        if (0 < piVar3[0x21]) {
          local_68 = 1;
          do {
            uVar6 = *(undefined4 *)(param_4 + 8);
            uVar8 = FUN_0010b180(piVar3,local_68);
            FUN_0010ba02(param_3,local_68,uVar8,0,uVar6);
            iVar4 = FUN_0010b0f4(piVar3,local_68);
            iVar4 = *(int *)(iVar4 + 0x10);
            if (local_68 == 0) {
              param_3[0x27] = iVar4;
            }
            else {
              iVar7 = FUN_0010b0f4(param_3,local_68);
              *(int *)(iVar7 + 0x10) = iVar4;
            }
            local_68 = local_68 + 1;
          } while (local_68 <= piVar3[0x21]);
        }
        piVar3[0x58] = piVar3[0x58] + -1;
        iVar4 = *(int *)(param_4 + 0x46c);
        iVar7 = FUN_0010b180(piVar3,1);
        if (iVar4 < *(int *)(iVar7 + 0x160)) {
          *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
        }
        else {
          *(int *)(iVar7 + 0x160) = iVar4 + 1;
        }
        local_64 = 0;
        do {
          if ((*(char *)((int)&local_38 + local_64) != '\x04') && (0 < param_3[0x21])) {
            iVar4 = 1;
            do {
              (**(code **)(*param_3 + 0x88))(param_3,iVar4,local_64,4);
              iVar4 = iVar4 + 1;
            } while (iVar4 <= param_3[0x21]);
          }
          local_64 = local_64 + 1;
        } while (local_64 != 4);
        FUN_0010ba02(param_3,param_3[0x21],uVar5,0,*(undefined4 *)(param_4 + 8));
        iVar4 = local_38;
        if (param_3[0x21] == 0) {
          param_3[0x27] = local_38;
        }
        else {
          iVar7 = FUN_0010b0f4(param_3,param_3[0x21]);
          *(int *)(iVar7 + 0x10) = iVar4;
        }
      }
      FUN_000e9596(*(undefined4 *)(iVar9 + 0x158),iVar9,param_3);
      FUN_0010b1fe(piVar3,*(undefined4 *)(param_4 + 8),0);
      cVar2 = (**(code **)(*piVar3 + 100))(piVar3);
      if (cVar2 == '\0') {
        return 1;
      }
      goto LAB_0015180c;
    }
    cVar2 = (**(code **)(*piVar3 + 100))(piVar3);
    if (cVar2 == '\0') {
      return 0;
    }
    if ((*(byte *)((int)piVar3 + 0x15) & 2) != 0) {
      return 0;
    }
    cVar2 = FUN_000f7c08(piVar3,1,piVar3,param_4);
    if (cVar2 == '\0') {
      return 0;
    }
    *(int *)(param_4 + 0x228) = *(int *)(param_4 + 0x228) + 1;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    FUN_00109d1c(param_3,&local_44,0xffffffff);
    uVar5 = FUN_0010b180(param_3,1);
    iVar9 = FUN_0010b0f4(param_3,0);
    local_38 = *(int *)(iVar9 + 0x10);
    iVar9 = FUN_0010b0f4(piVar3,1);
    local_34 = *(undefined4 *)(iVar9 + 0x10);
    iVar9 = 1;
    do {
      if (*(char *)((int)&local_3c + iVar9 + 3) != '\x01') {
        *(undefined1 *)((int)&local_38 + iVar9 + 3) = 4;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != 5);
    iVar9 = FUN_0010b0f4(piVar3,0);
    local_24 = *(undefined4 *)(iVar9 + 0x10);
    iVar9 = 1;
    do {
      cVar2 = *(char *)((int)&local_28 + iVar9 + 3);
      if (cVar2 != '\x01') {
        *(char *)((int)&local_3c + iVar9 + 3) = cVar2;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != 5);
    iVar9 = FUN_0010b0f4(param_3,1);
    uVar6 = *(undefined4 *)(iVar9 + 0x10);
    iVar9 = param_3[1];
    FUN_001a7d72(param_3);
    FUN_0010f5da(param_3,0xa2,*(undefined4 *)(param_4 + 8));
    FUN_00109d48(param_3,&local_44);
    param_3[0x25] = param_3[0x53];
    param_3[0x26] = 0x36;
    param_3[0x21] = 2;
    param_3[0x27] = local_38;
    FUN_0010ba02(param_3,1,uVar5,0,*(undefined4 *)(param_4 + 8));
    iVar4 = FUN_0010b0f4(param_3,1);
    *(undefined4 *)(iVar4 + 0x10) = uVar6;
    uVar5 = *(undefined4 *)(param_4 + 8);
    uVar6 = FUN_0010b180(piVar3,1);
    FUN_0010ba02(param_3,2,uVar6,0,uVar5);
    uVar5 = local_34;
    iVar4 = FUN_0010b0f4(param_3,2);
    *(undefined4 *)(iVar4 + 0x10) = uVar5;
    FUN_000e9596(*(undefined4 *)(iVar9 + 0x158),iVar9,param_3);
    uVar5 = *(undefined4 *)(param_4 + 8);
  }
  FUN_0010b3fe(piVar3,uVar5);
LAB_0015180c:
  ((int (*)())FUN_00155bf2)(param_1,param_2,param_3,param_4,local_1d);
  return 1;
}

/* FUN_00151c7c @ 0x151c7c (4447 bytes) */
int FUN_00151c7c(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int *param_3;
  int param_4;
{
  float fVar1;
  undefined4 uVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  byte bVar14;
  int *local_a0;
  uint local_90;
  uint local_8c;
  uint local_88;
  int local_80;
  int local_7c;
  int local_70;
  float local_6c;
  int local_68;
  int local_64;
  bool local_5d;
  int local_58;
  int local_54;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  int local_3c;
  undefined4 local_38;
  char cStack_35;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_1d [13];
  
  if ((*(byte *)((int)param_3 + 0x15) & 2) == 0) {
    local_a0 = (int *)0x0;
  }
  else {
    local_a0 = (int *)FUN_0010b180(param_3,param_3[0x21]);
  }
  uVar9 = *(undefined4 *)(param_4 + 8);
  if ((local_a0 == (int *)0x0) || (cVar4 = (**(code **)(*local_a0 + 0x60))(local_a0), cVar4 == '\0')
     ) {
    if ((param_1 != 0) &&
       (((param_3 != (int *)0x0 && (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x8e)) &&
        (cVar4 = (**(code **)(*param_3 + 0x60))(param_3), cVar4 != '\0')))) {
      iVar5 = FUN_0010dbb8(0x31,*(undefined4 *)(param_4 + 8));
      *(int *)(iVar5 + 0x160) = *(int *)(param_4 + 0x46c) + 1;
      *(undefined4 *)(iVar5 + 0x94) = *(undefined4 *)(iVar5 + 0x14c);
      *(undefined4 *)(iVar5 + 0x98) = 0;
      FUN_0010ba02(iVar5,1,param_3,0,*(undefined4 *)(param_4 + 8));
      iVar6 = FUN_0010b0f4(param_3,0);
      *(undefined4 *)(iVar5 + 0x9c) = *(undefined4 *)(iVar6 + 0x10);
      FUN_000f6af0(iVar5,1,param_4);
      FUN_000e9596(param_3[0x56],param_3,iVar5);
      *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x80000000;
      FUN_0010ba02(param_1,param_2,iVar5,0,*(undefined4 *)(param_4 + 8));
      return 0;
    }
    return 0;
  }
  iVar5 = FUN_0010b0f4(param_3,param_3[0x21]);
  uVar10 = *(undefined4 *)(iVar5 + 0x10);
  iVar5 = FUN_0010b0f4(local_a0,0);
  local_24 = *(undefined4 *)(iVar5 + 0x10);
  if (0 < param_3[0x21]) {
    iVar5 = 1;
    do {
      iVar6 = FUN_0010b180(param_3,iVar5);
      if ((*(int *)(iVar6 + 0x98) != 0x33) ||
         (iVar6 = FUN_0010b180(param_3,iVar5), *(int *)(iVar6 + 300) == 3)) {
        bVar3 = true;
        goto LAB_00151d63;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= param_3[0x21]);
  }
  bVar3 = false;
LAB_00151d63:
  iVar5 = *(int *)(param_3[0x22] + 8);
  if (!bVar3) goto LAB_00151d7d;
  piVar7 = (int *)FUN_0010b180(local_a0,1);
  if (((piVar7[0x20] == 0) || (cVar4 = FUN_0012dfd8(piVar7[0x26]), cVar4 == '\0')) ||
     (((*(byte *)(piVar7 + 5) & 2) != 0 ||
      (cVar4 = (**(code **)(*piVar7 + 0x50))(piVar7), cVar4 != '\0')))) {
    iVar6 = FUN_0010b0f4(param_3,0);
    uVar2 = *(undefined4 *)(iVar6 + 0x10);
    iVar6 = FUN_0010b0f4(local_a0,1);
    cVar4 = ((int (*)())FUN_0014fb2e)(*(undefined4 *)(iVar6 + 0x10),uVar2);
    if (cVar4 != '\0') goto LAB_001522e4;
  }
  else {
LAB_001522e4:
    if (iVar5 - 0x12U < 3) {
      iVar6 = (**(code **)(*local_a0 + 0x14))(local_a0);
      local_4c = 0;
      local_48 = 0;
      local_38 = 0;
      if (iVar6 < 1) {
        local_80 = 0;
        local_90 = 0;
        local_8c = 0;
        goto LAB_0015233f;
      }
      local_7c = 1;
      local_90 = 0;
      local_8c = 0;
      local_88 = 0;
      do {
        iVar11 = FUN_0010b180(local_a0,local_7c);
        if (*(int *)(iVar11 + 0x98) == 0x33) {
          iVar12 = FUN_0010b0f4(local_a0,local_7c);
          local_2c = *(undefined4 *)(iVar12 + 0x10);
          iVar12 = 0;
          do {
            bVar14 = *(byte *)((int)&local_2c + iVar12);
            if ((bVar14 != 4) &&
               (iVar13 = FUN_0010b0f4(param_3,0), *(char *)(iVar12 + 0x10 + iVar13) == '\x01')) {
              fVar1 = *(float *)(iVar11 + 0x20 + (uint)bVar14 * 0x18);
              bVar14 = (byte)iVar12;
              if ((fVar1 != FLOAT_001c5b9c) || (NAN(fVar1) || NAN(FLOAT_001c5b9c))) {
                if ((fVar1 != FLOAT_001c5ba4) || (NAN(fVar1) || NAN(FLOAT_001c5ba4))) {
                  local_88 = local_88 | 1 << (bVar14 & 0x1f);
                }
                else {
                  local_90 = local_90 | 1 << (bVar14 & 0x1f);
                }
              }
              else {
                local_8c = local_8c | 1 << (bVar14 & 0x1f);
              }
            }
            iVar12 = iVar12 + 1;
          } while (iVar12 != 4);
        }
        else {
          FUN_0010a980(param_3,&local_4c);
          local_48 = iVar11;
        }
        local_7c = local_7c + 1;
      } while (local_7c <= iVar6);
      if (local_90 == 0) {
        local_80 = 0;
      }
      else if ((iVar5 - 0x13U < 2) &&
              ((*(byte *)(param_3 + 0x34) & 1) == (*(byte *)(param_3 + 0x2e) & 1))) {
        local_80 = 6;
      }
      else if (iVar5 == 0x12) {
        if ((*(byte *)(param_3 + 0x34) & 1) == 0) {
          local_80 = 2;
        }
        else {
          if ((*(byte *)(param_3 + 0x2e) & 1) != 0) goto LAB_00152d16;
          local_80 = 4;
        }
      }
      else if ((iVar5 == 0x14) && ((*(byte *)(param_3 + 0x3a) & 1) == 0)) {
        local_80 = 1;
      }
      else {
LAB_00152d16:
        local_80 = -1;
      }
      if ((local_88 == 0) && (-1 < local_80)) {
LAB_0015233f:
        iVar6 = FUN_0010b0f4(param_3,0);
        local_2c = *(undefined4 *)(iVar6 + 0x10);
        local_54 = 2;
        do {
          iVar6 = 3 - local_54;
          iVar11 = (**(code **)(*param_3 + 0x14))(param_3);
          if (iVar11 < iVar6) {
            FUN_0010ba02(param_3,param_3[0x21],0,0,uVar9);
            param_3[0x21] = param_3[0x21] + -1;
            param_3[5] = param_3[5] & 0xfffffdff;
            if (local_48 != 0) {
              iVar5 = FUN_0010b0f4(param_3,0);
              local_28 = *(undefined4 *)(iVar5 + 0x10);
              iVar5 = 0;
              do {
                if (*(char *)((int)&local_28 + iVar5) != '\x01') {
                  *(undefined1 *)((int)&local_3c + iVar5) = 4;
                }
                iVar5 = iVar5 + 1;
              } while (iVar5 != 4);
              if (local_3c != DAT_001cc5a4) {
                FUN_0010c568(param_3,&local_4c,0,uVar9);
                if (*(int *)(param_4 + 0x46c) < *(int *)(local_48 + 0x160)) {
                  *(int *)(local_48 + 0x160) = *(int *)(local_48 + 0x160) + 1;
                }
                else {
                  *(int *)(local_48 + 0x160) = *(int *)(param_4 + 0x46c) + 1;
                }
              }
            }
            (**(code **)(*param_3 + 0x14))(param_3);
            FUN_0010b3fe(local_a0,uVar9);
            return 1;
          }
          uVar10 = FUN_0010b180(param_3,iVar6);
          if ((local_90 == 0) || ((local_8c == 0 && (iVar5 == 0x13)))) {
            if ((local_80 >> ((byte)local_54 & 0x1f) & 1U) == 0) goto LAB_00152a38;
            local_70 = 2;
            local_6c = FLOAT_001c5ba4;
          }
          else if ((local_80 >> ((byte)local_54 & 0x1f) & 1U) == 0) {
LAB_00152a38:
            local_70 = 2;
            local_6c = 0.0;
          }
          else {
            local_70 = 3;
            local_6c = FLOAT_001c5ba4;
          }
          piVar8 = (int *)((int (*)())FUN_00110f42)(local_70,DAT_001cc6d4,uVar10,param_4,uVar9,local_6c);
          iVar11 = FUN_0010b0f4(param_3,iVar6);
          local_28 = *(undefined4 *)(iVar11 + 0x10);
          iVar11 = 0;
          piVar7 = piVar8;
          do {
            if (*(char *)((int)&local_28 + iVar11) != '\x04') {
              (**(code **)(*piVar8 + 0x88))(piVar8,1,iVar11,*(char *)((int)&local_28 + iVar11));
              *(undefined1 *)(piVar7 + 0x27) = 0;
              (**(code **)(*param_3 + 0x88))(param_3,iVar6,iVar11,iVar11);
            }
            iVar11 = iVar11 + 1;
            piVar7 = (int *)((int)piVar7 + 1);
          } while (iVar11 != 4);
          local_68 = -1;
          local_64 = -1;
          iVar11 = 0;
          piVar7 = piVar8;
          do {
            iVar12 = FUN_0010b0f4(piVar8,1);
            if ((*(char *)(iVar11 + 0x10 + iVar12) == '\x04') &&
               (*(char *)((int)&local_2c + iVar11) == '\x01')) {
              if (local_70 == 3) {
LAB_00152829:
                if (local_68 < 0) {
                  (**(code **)(*piVar8 + 0x88))(piVar8,2,iVar11,iVar11);
                  *(undefined1 *)(piVar7 + 0x27) = 0;
                  local_68 = iVar11;
                  goto LAB_001524cd;
                }
                if (local_70 != 3) goto LAB_0015283a;
              }
              else {
                if ((local_6c == FLOAT_001c5ba4) && (!NAN(local_6c) && !NAN(FLOAT_001c5ba4)))
                goto LAB_00152829;
LAB_0015283a:
                if ((local_6c != FLOAT_001c5b9c) || (NAN(local_6c) || NAN(FLOAT_001c5b9c))) break;
              }
              if (-1 < local_64) break;
              (**(code **)(*piVar8 + 0x88))(piVar8,local_70,iVar11,iVar11);
              *(undefined1 *)(piVar7 + 0x27) = 0;
              local_64 = iVar11;
            }
LAB_001524cd:
            iVar11 = iVar11 + 1;
            piVar7 = (int *)((int)piVar7 + 1);
          } while (iVar11 != 4);
          if (local_90 != 0) {
            iVar11 = 0;
            piVar7 = param_3;
            do {
              if (((((int)local_90 >> ((byte)iVar11 & 0x1f) & 1U) != 0) &&
                  (*(char *)((int)&local_24 + iVar11) != '\x01')) &&
                 (*(char *)((int)&local_2c + iVar11) == '\x01')) {
                if ((local_80 >> ((byte)local_54 & 0x1f) & 1U) == 0) {
                  iVar12 = *param_3;
                  iVar13 = local_64;
                }
                else {
                  iVar12 = *param_3;
                  iVar13 = local_68;
                }
                (**(code **)(iVar12 + 0x88))(param_3,iVar6,iVar11,iVar13);
                *(undefined1 *)(piVar7 + 0x27) = 0;
              }
              iVar11 = iVar11 + 1;
              piVar7 = (int *)((int)piVar7 + 1);
            } while (iVar11 != 4);
          }
          if (local_8c != 0) {
            iVar11 = 0;
            piVar7 = param_3;
            do {
              if (((((int)local_8c >> ((byte)iVar11 & 0x1f) & 1U) != 0) &&
                  (*(char *)((int)&local_24 + iVar11) != '\x01')) &&
                 (*(char *)((int)&local_2c + iVar11) == '\x01')) {
                (**(code **)(*param_3 + 0x88))(param_3,iVar6,iVar11,local_64);
                *(undefined1 *)(piVar7 + 0x27) = 0;
              }
              iVar11 = iVar11 + 1;
              piVar7 = (int *)((int)piVar7 + 1);
            } while (iVar11 != 4);
          }
          piVar7 = (int *)FUN_0010b180(piVar8,1);
          cVar4 = (**(code **)(*piVar7 + 0x60))(piVar7);
          if (cVar4 != '\0') {
            uVar10 = FUN_0010b180(piVar8,1);
            FUN_00111842(uVar10,piVar8,uVar9);
          }
          FUN_000e956e(param_3[0x56],param_3,piVar8);
          FUN_0010ba02(param_3,iVar6,piVar8,0,uVar9);
          local_54 = local_54 + -1;
        } while( true );
      }
    }
  }
  if ((local_a0[0x26] != 0x33) ||
     (iVar5 = FUN_0010b180(param_3,param_3[0x21]), *(int *)(iVar5 + 300) == 3)) {
    iVar5 = FUN_0010dbb8(0x31,*(undefined4 *)(param_4 + 8));
    *(int *)(iVar5 + 0x160) = *(int *)(param_4 + 0x46c) + 1;
    *(undefined4 *)(iVar5 + 0x94) = *(undefined4 *)(iVar5 + 0x14c);
    *(undefined4 *)(iVar5 + 0x98) = 0;
    FUN_0010ba02(iVar5,1,local_a0,0,*(undefined4 *)(param_4 + 8));
    uVar9 = FUN_0010b180(param_3,param_3[0x21]);
    iVar6 = FUN_0010b0f4(uVar9,0);
    *(undefined4 *)(iVar5 + 0x9c) = *(undefined4 *)(iVar6 + 0x10);
    FUN_000f6af0(iVar5,1,param_4);
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x80000000;
    uVar9 = FUN_0010b180(param_3,param_3[0x21]);
    iVar6 = FUN_0010b180(param_3,param_3[0x21]);
    FUN_000e9596(*(undefined4 *)(iVar6 + 0x158),uVar9,iVar5);
    FUN_0010c18e(param_3,iVar5,0,*(undefined4 *)(param_4 + 8));
    iVar5 = FUN_0010b0f4(param_3,param_3[0x21]);
    *(undefined4 *)(iVar5 + 0x10) = uVar10;
    return 1;
  }
LAB_00151d7d:
  FUN_0010ba02(param_3,param_3[0x21],0,0,*(undefined4 *)(param_4 + 8));
  param_3[0x21] = param_3[0x21] + -1;
  param_3[5] = param_3[5] & 0xfffffdff;
  local_a0[0x58] = local_a0[0x58] + -1;
  cVar4 = FUN_0010a67e(local_a0,param_4);
  if (cVar4 != '\0') {
    (**(code **)(*local_a0 + 0xc))(local_a0,0,*(undefined4 *)(param_4 + 8));
  }
  local_5d = cVar4 == '\0';
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  FUN_00109d1c(param_3,&local_4c,0xffffffff);
  iVar5 = FUN_0010a1c2(param_3,*(undefined4 *)(param_4 + 8),0);
  FUN_000e9596(*(undefined4 *)(param_3[1] + 0x158),param_3[1],iVar5);
  *(int *)(iVar5 + 0x160) = *(int *)(param_4 + 0x46c) + 1;
  *(undefined4 *)(iVar5 + 0x94) = *(undefined4 *)(iVar5 + 0x14c);
  FUN_0010f5da(param_3,0xa2,*(undefined4 *)(param_4 + 8));
  param_3[0x21] = local_a0[0x21] + 1;
  FUN_000e9596(*(undefined4 *)(iVar5 + 0x158),iVar5,param_3);
  iVar6 = FUN_0010b0f4(iVar5,0);
  local_34 = *(int *)(iVar6 + 0x10);
  iVar6 = FUN_0010b0f4(local_a0,0);
  local_30 = *(undefined4 *)(iVar6 + 0x10);
  iVar6 = 1;
  do {
    cVar4 = *(char *)((int)&local_34 + iVar6 + 3);
    if (cVar4 != '\x01') {
      (&cStack_35)[iVar6] = cVar4;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != 5);
  iVar6 = FUN_0010b180(local_a0,1);
  if (*(int *)(iVar6 + 0x98) == 0) {
    FUN_0010c18e(iVar5,iVar6,0,*(undefined4 *)(param_4 + 8));
    if (local_5d) {
      if (*(int *)(param_4 + 0x46c) < *(int *)(iVar6 + 0x160)) {
        *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
      }
      else {
        *(int *)(iVar6 + 0x160) = *(int *)(param_4 + 0x46c) + 1;
      }
    }
    param_3[0x21] = param_3[0x21] + -1;
    FUN_0010ba02(param_3,1,iVar5,0,*(undefined4 *)(param_4 + 8));
    iVar6 = FUN_0010b0f4(param_3,1);
    *(undefined4 *)(iVar6 + 0x10) = DAT_001cc5a0;
    local_58 = 2;
  }
  else {
    FUN_0010ba02(param_3,2,iVar5,0,*(undefined4 *)(param_4 + 8));
    iVar11 = FUN_0010b0f4(param_3,2);
    *(undefined4 *)(iVar11 + 0x10) = DAT_001cc5a0;
    FUN_0010ba02(param_3,1,iVar6,0,*(undefined4 *)(param_4 + 8));
    iVar6 = FUN_0010b0f4(local_a0,1);
    uVar9 = *(undefined4 *)(iVar6 + 0x10);
    iVar6 = FUN_0010b0f4(param_3,1);
    *(undefined4 *)(iVar6 + 0x10) = uVar9;
    local_58 = 3;
  }
  iVar6 = FUN_0010b0f4(iVar5,0);
  local_2c = *(undefined4 *)(iVar6 + 0x10);
  if (1 < local_a0[0x21]) {
    iVar6 = 2;
    do {
      uVar9 = *(undefined4 *)(param_4 + 8);
      uVar10 = FUN_0010b180(local_a0,iVar6);
      FUN_0010ba02(param_3,local_58,uVar10,0,uVar9);
      if (local_5d) {
        iVar11 = *(int *)(param_4 + 0x46c);
        iVar12 = FUN_0010b180(local_a0,iVar6);
        if (iVar11 < *(int *)(iVar12 + 0x160)) {
          *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + 1;
        }
        else {
          *(int *)(iVar12 + 0x160) = iVar11 + 1;
        }
      }
      iVar11 = FUN_0010b0f4(local_a0,iVar6);
      iVar11 = *(int *)(iVar11 + 0x10);
      if (local_58 == 0) {
        param_3[0x27] = iVar11;
      }
      else {
        iVar12 = FUN_0010b0f4(param_3,local_58);
        *(int *)(iVar12 + 0x10) = iVar11;
      }
      iVar11 = FUN_0010b0f4(local_a0,iVar6);
      uVar9 = *(undefined4 *)(iVar11 + 0x10);
      iVar11 = 1;
      do {
        if (*(char *)((int)&local_30 + iVar11 + 3) != '\x04') {
          *(undefined1 *)((int)&local_2c + iVar11 + 3) = 4;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 != 5);
      local_28 = uVar9;
      iVar11 = FUN_0010b0f4(param_3,local_58);
      *(undefined4 *)(iVar11 + 0x10) = uVar9;
      local_58 = local_58 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 <= local_a0[0x21]);
  }
  param_3[0x25] = param_3[0x53];
  param_3[0x26] = 0x36;
  param_3[0x27] = local_34;
  FUN_00109d48(param_3,&local_4c);
  param_3[0x56] = *(int *)(iVar5 + 0x158);
  local_1d[0] = 0;
  ((int (*)())FUN_00156a28)(param_3,param_4,local_1d);
  ((int (*)())FUN_00155bf2)(param_1,param_2,param_3,param_4,local_1d);
  return 1;
}

/* FUN_00152de4 @ 0x152de4 (1713 bytes) */
int FUN_00152de4(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  bool bVar17;
  bool local_cc;
  undefined4 local_b8;
  int local_b4;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_4c;
  undefined1 local_48 [4];
  float local_44;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20 [4];
  
  iVar16 = param_1[0x49];
  local_20[0] = 0;
  iVar14 = *(int *)(param_1[0x22] + 8);
  if (iVar14 == 0x13) {
    iVar14 = 1;
    while( true ) {
      iVar15 = FUN_0010b0f4(param_1,0);
      cVar9 = FUN_000f7e7e(param_1,iVar14,*(undefined4 *)(iVar15 + 0x10),local_48);
      if (cVar9 != '\0') break;
      iVar14 = iVar14 + 1;
      if (iVar14 == 3) {
        return param_1;
      }
    }
    cVar9 = ((undefined4 (*)())FUN_0010fdec)(local_44,local_20);
    if (cVar9 == '\0') {
      return param_1;
    }
    local_20[0] = iVar16 + local_20[0];
    if (iVar14 == 1) {
      iVar16 = 2;
      local_b8 = 0xffffffff;
      local_b4 = 2;
    }
    else {
      iVar16 = 2;
      local_b8 = 0xffffffff;
      local_b4 = 1;
    }
  }
  else if (iVar14 == 0x14) {
    iVar14 = FUN_0010b0f4(param_1,0);
    cVar9 = FUN_000f7e7e(param_1,3,*(undefined4 *)(iVar14 + 0x10),local_48);
    if (cVar9 == '\0') {
      return param_1;
    }
    if (local_44 != FLOAT_001c5bdc) {
      if (local_44 != FLOAT_001c5ba4) {
        return param_1;
      }
      if (NAN(local_44) || NAN(FLOAT_001c5ba4)) {
        return param_1;
      }
    }
    local_30 = 0x40000000;
    local_2c = 0x40000000;
    local_28 = 0x40000000;
    local_24 = 0x40000000;
    iVar14 = FUN_0010b0f4(param_1,0);
    cVar9 = FUN_000f7dda(param_1,1,*(undefined4 *)(iVar14 + 0x10),&local_30);
    if (cVar9 == '\0') {
      iVar14 = FUN_0010b0f4(param_1,0);
      cVar9 = FUN_000f7dda(param_1,2,*(undefined4 *)(iVar14 + 0x10),&local_30);
      if (cVar9 == '\0') {
        return param_1;
      }
      local_20[0] = iVar16 + 1;
      iVar16 = 3;
      local_b8 = 2;
      local_b4 = 1;
    }
    else {
      local_20[0] = iVar16 + 1;
      iVar16 = 3;
      local_b8 = 1;
      local_b4 = 2;
    }
  }
  else {
    if (iVar14 != 0x12) {
      return param_1;
    }
    iVar14 = FUN_0010b180(param_1,1);
    iVar15 = FUN_0010b180(param_1,2);
    if (iVar14 != iVar15) {
      return param_1;
    }
    iVar14 = FUN_0010b0f4(param_1,2);
    iVar14 = *(int *)(iVar14 + 0x10);
    iVar15 = FUN_0010b0f4(param_1,1);
    if (*(int *)(iVar15 + 0x10) != iVar14) {
      return param_1;
    }
    if (((byte)param_1[0x2e] & 1) != ((byte)param_1[0x34] & 1)) {
      return param_1;
    }
    if (((byte)((uint)param_1[0x2e] >> 1) & 1) != ((byte)((uint)param_1[0x34] >> 1) & 1)) {
      return param_1;
    }
    local_20[0] = iVar16 + 1;
    iVar16 = 1;
    local_b8 = 0xffffffff;
    local_b4 = 1;
  }
  cVar9 = (**(code **)(**(int **)(param_2 + 0x54) + 0xfc))
                    (*(int **)(param_2 + 0x54),local_20[0],param_1);
  if (cVar9 != '\0') {
    iVar14 = *(int *)(param_2 + 0x3f4);
    *(int *)(iVar14 + 0x158) = *(int *)(iVar14 + 0x158) + 1;
    if (iVar16 == 2) {
      local_cc = (bool)(*(byte *)(param_1 + local_b4 * 6 + 0x28) & 1) != local_44 < 0.0;
    }
    else {
      if (iVar16 == 3) {
        param_1[0x49] = local_20[0];
        FUN_000fa0d2(param_1,iVar14,local_b8,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
        FUN_000fa0d2(param_1,iVar14,3,0x3f000000,0x3f000000,0x3f000000,0x3f000000);
        FUN_00109c0e(param_1 + 0x35,1,local_44 < 0.0);
        return param_1;
      }
      if (iVar16 == 1) {
        local_cc = (bool)(*(byte *)(param_1 + local_b4 * 6 + 0x28) & 1);
      }
      else {
        local_cc = false;
      }
    }
    iVar16 = param_1[1];
    iVar15 = param_1[4];
    iVar10 = FUN_00109e42(param_1,iVar14);
    uVar1 = param_1[5];
    iVar2 = param_1[0x26];
    iVar3 = param_1[0x25];
    iVar11 = FUN_0010b0f4(param_1,0);
    iVar11 = *(int *)(iVar11 + 0x10);
    iVar8 = param_1[0x48];
    uVar12 = FUN_0010b180(param_1,local_b4);
    iVar4 = param_1[local_b4 * 6 + 0x26];
    iVar5 = param_1[local_b4 * 6 + 0x25];
    iVar13 = FUN_0010b0f4(param_1,local_b4);
    uVar6 = *(undefined4 *)(iVar13 + 0x10);
    uVar7 = param_1[local_b4 * 6 + 0x28];
    local_60 = 0;
    local_5c = 0;
    local_4c = 0;
    bVar17 = (*(byte *)((int)param_1 + 0x15) & 2) != 0;
    if (bVar17) {
      FUN_0010a980(param_1,&local_60);
    }
    (**(code **)(*param_1 + 0xc))(param_1,1,param_2);
    FUN_0010db52(param_1,0x31,param_2);
    if ((uVar1 & 2) != 0) {
      param_1[5] = param_1[5] | 2;
    }
    param_1[4] = iVar15;
    param_1[0x58] = iVar10 + *(int *)(iVar14 + 0x46c);
    param_1[0x25] = iVar3;
    param_1[0x26] = iVar2;
    iVar14 = FUN_0010b0f4(param_1,1);
    *(int *)(iVar14 + 8) = iVar5;
    *(int *)(iVar14 + 0xc) = iVar4;
    param_1[0x27] = iVar11;
    FUN_0010ba02(param_1,1,uVar12,1,param_2);
    iVar14 = FUN_0010b0f4(param_1,1);
    *(undefined4 *)(iVar14 + 0x10) = uVar6;
    FUN_00109c0e(param_1 + 0x29,2,(byte)(uVar7 >> 1) & 1);
    FUN_00109c0e(param_1 + 0x29,1,local_cc);
    *(char *)(param_1 + 0x48) = (char)iVar8;
    param_1[0x49] = local_20[0];
    if (bVar17) {
      FUN_0010c568(param_1,&local_60,1,param_2);
    }
    FUN_000e9596(*(undefined4 *)(iVar16 + 0x158),iVar16,param_1);
  }
  return param_1;
}

/* FUN_0015349e @ 0x15349e (581 bytes) */
int FUN_0015349e(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  uint *puVar8;
  uint uVar9;
  int *local_28;
  int local_24;
  undefined1 uStack_15;
  undefined4 local_14;
  undefined4 local_10;
  
  if ((*(byte *)(param_1 + 5) & 2) != 0) {
    iVar6 = FUN_0010b0f4(param_1,0);
    uVar1 = *(uint *)(iVar6 + 0x10);
    cVar5 = FUN_000f57b4(uVar1);
    if ((cVar5 != '\0') && (cVar5 = FUN_000e1402(*(undefined4 *)(param_2 + 8),0x31), cVar5 != '\0'))
    {
      iVar6 = param_1[0x26];
      iVar2 = param_1[0x25];
      local_28 = (int *)FUN_0010b180(param_1,1);
      local_24 = 4;
      while (cVar5 = (**(code **)(*local_28 + 0x30))(local_28), cVar5 == '\0') {
        cVar5 = (**(code **)(*local_28 + 0x40))(local_28);
        if (cVar5 != '\0') {
          return;
        }
        if (local_24 == 0) {
          return;
        }
        puVar8 = (uint *)local_28[4];
        if (0 < (int)puVar8[1]) {
          uVar9 = 0;
          do {
            if (uVar9 < *puVar8) {
              uVar3 = puVar8[1];
              if (uVar3 <= uVar9) {
                _memset((void *)(puVar8[2] + uVar3 * 4),0,(uVar9 - uVar3) * 4 + 4);
                puVar8[1] = uVar9 + 1;
              }
              piVar7 = (int *)(puVar8[2] + uVar9 * 4);
            }
            else {
              piVar7 = (int *)FUN_001a7f7c(puVar8,uVar9);
            }
            piVar7 = (int *)*piVar7;
            if (((param_1 != piVar7) && (iVar6 == piVar7[0x26])) && (iVar2 == piVar7[0x25])) {
              *(int *)(param_2 + 0x168) = *(int *)(param_2 + 0x168) + 1;
              iVar6 = FUN_0010b0f4(piVar7,0);
              param_1[0x27] = uVar1 & *(uint *)(iVar6 + 0x10);
              iVar6 = FUN_0010b0f4(param_1,1);
              local_10 = *(undefined4 *)(iVar6 + 0x10);
              iVar6 = FUN_0010b0f4(piVar7,1);
              local_14 = *(undefined4 *)(iVar6 + 0x10);
              iVar6 = 1;
              do {
                if (*(char *)((int)&local_14 + iVar6 + 3) == '\x04') {
                  *(undefined1 *)((int)&local_14 + iVar6 + 3) = (&uStack_15)[iVar6];
                }
                uVar4 = local_10;
                iVar6 = iVar6 + 1;
              } while (iVar6 != 5);
              iVar6 = FUN_0010b0f4(param_1,1);
              *(undefined4 *)(iVar6 + 0x10) = uVar4;
              (**(code **)(*piVar7 + 0xc))(piVar7,1,*(undefined4 *)(param_2 + 8));
              return;
            }
            uVar9 = uVar9 + 1;
            puVar8 = (uint *)local_28[4];
          } while ((int)uVar9 < (int)puVar8[1]);
        }
        if ((*(byte *)((int)local_28 + 0x15) & 2) == 0) {
          return;
        }
        local_28 = (int *)FUN_0010b180(local_28,local_28[0x21]);
        local_24 = local_24 + -1;
      }
    }
  }
  return;
}

/* FUN_001536e4 @ 0x1536e4 (624 bytes) */
int FUN_001536e4(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  uint *puVar9;
  uint uVar10;
  int *local_28;
  int local_24;
  undefined1 uStack_15;
  undefined4 local_14;
  undefined4 local_10;
  
  if ((*(byte *)(param_1 + 5) & 2) != 0) {
    iVar6 = FUN_0010b0f4(param_1,0);
    uVar1 = *(uint *)(iVar6 + 0x10);
    cVar5 = FUN_000f57b4(uVar1);
    if ((cVar5 != '\0') && (cVar5 = FUN_000e1402(*(undefined4 *)(param_2 + 8),0x31), cVar5 != '\0'))
    {
      iVar6 = param_1[0x26];
      iVar2 = param_1[0x25];
      local_28 = (int *)FUN_0010b180(param_1,1);
      local_24 = 4;
      while (cVar5 = (**(code **)(*local_28 + 0x30))(local_28), cVar5 == '\0') {
        cVar5 = (**(code **)(*local_28 + 0x40))(local_28);
        if (cVar5 != '\0') {
          return;
        }
        if (local_24 == 0) {
          return;
        }
        puVar9 = *(uint **)(param_2 + 0x3b8);
        if (0 < (int)puVar9[1]) {
          uVar10 = 0;
          do {
            if (uVar10 < *puVar9) {
              uVar3 = puVar9[1];
              if (uVar3 <= uVar10) {
                _memset((void *)(puVar9[2] + uVar3 * 4),0,(uVar10 - uVar3) * 4 + 4);
                puVar9[1] = uVar10 + 1;
              }
              piVar7 = (int *)(puVar9[2] + uVar10 * 4);
            }
            else {
              piVar7 = (int *)FUN_001a7f7c(puVar9,uVar10);
            }
            piVar7 = (int *)*piVar7;
            if ((((param_1 != piVar7) && (iVar6 == piVar7[0x26])) && (iVar2 == piVar7[0x25])) &&
               (piVar8 = (int *)FUN_0010b180(piVar7,1), local_28 == piVar8)) {
              *(int *)(param_2 + 0x168) = *(int *)(param_2 + 0x168) + 1;
              iVar6 = FUN_0010b0f4(piVar7,0);
              param_1[0x27] = uVar1 & *(uint *)(iVar6 + 0x10);
              iVar6 = FUN_0010b0f4(param_1,1);
              local_10 = *(undefined4 *)(iVar6 + 0x10);
              iVar6 = FUN_0010b0f4(piVar7,1);
              local_14 = *(undefined4 *)(iVar6 + 0x10);
              iVar6 = 1;
              do {
                if (*(char *)((int)&local_14 + iVar6 + 3) == '\x04') {
                  *(undefined1 *)((int)&local_14 + iVar6 + 3) = (&uStack_15)[iVar6];
                }
                uVar4 = local_10;
                iVar6 = iVar6 + 1;
              } while (iVar6 != 5);
              iVar6 = FUN_0010b0f4(param_1,1);
              *(undefined4 *)(iVar6 + 0x10) = uVar4;
              (**(code **)(*piVar7 + 0xc))(piVar7,0,*(undefined4 *)(param_2 + 8));
              local_28[0x58] = local_28[0x58] + -1;
              return;
            }
            uVar10 = uVar10 + 1;
            puVar9 = *(uint **)(param_2 + 0x3b8);
          } while ((int)uVar10 < (int)puVar9[1]);
        }
        if ((*(byte *)((int)local_28 + 0x15) & 2) == 0) {
          return;
        }
        local_28 = (int *)FUN_0010b180(local_28,local_28[0x21]);
        local_24 = local_24 + -1;
      }
    }
  }
  return;
}

/* FUN_00153954 @ 0x153954 (1173 bytes) */
int FUN_00153954(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *local_60;
  int local_50;
  int local_40;
  int local_3c;
  int local_34;
  undefined4 *local_30;
  undefined4 local_20 [4];
  
  cVar3 = FUN_000e1402(*(undefined4 *)(param_2 + 8),0x30);
  if ((((cVar3 != '\0') && ((*(uint *)(param_1 + 0xb8) & 1) == 0)) &&
      ((*(uint *)(param_1 + 0xb8) & 2) == 0)) && ((*(byte *)(param_1 + 0x15) & 2) == 0)) {
    iVar4 = FUN_0010b0f4(param_1,0);
    iVar4 = *(int *)(iVar4 + 0x10);
    iVar5 = FUN_0010b0f4(param_1,1);
    uVar1 = *(undefined4 *)(iVar5 + 0x10);
    cVar3 = FUN_000f5672(uVar1);
    if (cVar3 != '\0') {
      piVar6 = (int *)FUN_0010b180(param_1,1);
      iVar5 = FUN_001192a8(*(undefined4 *)(piVar6[0x22] + 8),*(undefined4 *)(param_2 + 8));
      if (((iVar5 == 0) && (cVar3 = (**(code **)(*piVar6 + 0x24))(piVar6), cVar3 != '\0')) &&
         ((*(byte *)((int)piVar6 + 0x15) & 2) == 0)) {
        iVar5 = FUN_0010b0f4(piVar6,0);
        cVar3 = FUN_000f5f28(*(undefined4 *)(iVar5 + 0x10));
        if ((cVar3 == '\0') && (cVar3 = ((int (*)())FUN_0014fc7c)(piVar6,param_2), cVar3 != '\0')) {
          *(int *)(param_2 + 0x174) = *(int *)(param_2 + 0x174) + 1;
          iVar5 = *(int *)(param_2 + 0x46c);
          cVar3 = FUN_0010a62e(piVar6,param_2);
          local_60 = piVar6;
          if (cVar3 == '\0') {
            local_60 = (int *)FUN_0010a1c2(piVar6,*(undefined4 *)(param_2 + 8),0);
            FUN_000e9596(piVar6[0x56],piVar6,local_60);
            piVar6[0x58] = piVar6[0x58] + -1;
            iVar7 = iVar5 + 1;
            local_60[0x58] = iVar7;
            iVar9 = local_60[0x53];
            iVar8 = FUN_0010b0f4(local_60,0);
            *(int *)(iVar8 + 8) = iVar9;
            local_50 = 1;
LAB_00153c91:
            do {
              iVar9 = (**(code **)(*local_60 + 0x14))(local_60);
              if (iVar9 < local_50) break;
              piVar10 = (int *)FUN_0010b180(local_60,local_50);
              cVar3 = (**(code **)(*piVar10 + 0x5c))(piVar10);
              if (cVar3 == '\0') {
                if (iVar5 < piVar10[0x58]) {
                  piVar10[0x58] = piVar10[0x58] + 1;
                  local_50 = local_50 + 1;
                  goto LAB_00153c91;
                }
                piVar10[0x58] = iVar7;
              }
              else {
                iVar9 = FUN_0010a1c2(piVar10,*(undefined4 *)(param_2 + 8),0);
                uVar2 = *(undefined4 *)(iVar9 + 0x14c);
                iVar8 = FUN_0010b0f4(iVar9,0);
                *(undefined4 *)(iVar8 + 8) = uVar2;
                *(int *)(iVar9 + 0x160) = iVar7;
                FUN_0010ba02(local_60,local_50,iVar9,0,*(undefined4 *)(param_2 + 8));
                FUN_000e956e(piVar10[0x56],piVar10,iVar9);
                if (0 < *(int *)(iVar9 + 0x84)) {
                  local_40 = 1;
                  do {
                    iVar8 = FUN_0010b180(iVar9,local_40);
                    if (iVar5 < *(int *)(iVar8 + 0x160)) {
                      *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar8 + 0x160) = iVar7;
                    }
                    local_40 = local_40 + 1;
                  } while (local_40 <= *(int *)(iVar9 + 0x84));
                }
              }
              local_50 = local_50 + 1;
            } while( true );
          }
          local_60[0x27] = iVar4;
          local_3c = 1;
          while (iVar4 = (**(code **)(*local_60 + 0x14))(local_60), local_3c <= iVar4) {
            iVar4 = FUN_0010b0f4(piVar6,local_3c);
            iVar4 = FUN_000f5610(*(undefined4 *)(iVar4 + 0x10),uVar1);
            if (local_3c == 0) {
              local_60[0x27] = iVar4;
              local_3c = 1;
            }
            else {
              iVar5 = FUN_0010b0f4(local_60,local_3c);
              *(int *)(iVar5 + 0x10) = iVar4;
              local_3c = local_3c + 1;
            }
          }
          cVar3 = FUN_0010a62e(param_1,param_2);
          if (cVar3 != '\0') {
            if (*(char *)(param_1 + 0x120) != '\0') {
              *(undefined1 *)(local_60 + 0x48) = 1;
              *(undefined1 *)(param_1 + 0x120) = 0;
            }
            iVar4 = *(int *)(param_1 + 0x124) + piVar6[0x49];
            piVar6 = *(int **)(*(int *)(param_2 + 8) + 0x54);
            cVar3 = (**(code **)(*piVar6 + 0xfc))(piVar6,iVar4,param_1);
            if (cVar3 != '\0') {
              local_60[0x49] = iVar4;
              *(undefined4 *)(param_1 + 0x124) = 0;
            }
          }
          local_20[0] = DAT_001cc5a4;
          local_34 = 0;
          local_30 = &DAT_001cc5a0;
          do {
            iVar4 = FUN_0010b0f4(param_1,0);
            if (*(char *)(local_34 + 0x10 + iVar4) != '\x01') {
              *(undefined1 *)((int)local_20 + local_34) = *(undefined1 *)local_30;
            }
            uVar1 = local_20[0];
            local_34 = local_34 + 1;
            local_30 = (undefined4 *)((int)local_30 + 1);
          } while (local_34 != 4);
          iVar4 = FUN_0010b0f4(param_1,1);
          *(undefined4 *)(iVar4 + 0x10) = uVar1;
          FUN_0010ba02(param_1,1,local_60,0,*(undefined4 *)(param_2 + 8));
        }
      }
    }
  }
  return;
}

/* FUN_00153dea @ 0x153dea (2220 bytes) */
int FUN_00153dea(param_1, param_2)
  int *param_1;
  int param_2;
{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int local_60;
  int local_44;
  int local_40;
  int iStack_3c;
  int *local_38 [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar5 = FUN_0010b0f4(param_1,1);
  local_20 = *(undefined4 *)(iVar5 + 0x10);
  iVar5 = FUN_0010b0f4(param_1,0);
  local_24 = *(undefined4 *)(iVar5 + 0x10);
  piVar6 = (int *)FUN_0010b180(param_1,1);
  if (((param_1[0x2e] & 1U) != 0) || ((param_1[0x2e] & 2U) != 0)) {
    local_38[0] = (int *)0x0;
    local_38[1] = (int *)0x0;
    local_38[2] = (int *)0x0;
    local_38[3] = (int *)0x0;
    iVar5 = 0;
    do {
      if (*(char *)((int)&local_24 + iVar5) == '\0') {
        cVar4 = (**(code **)(*piVar6 + 0x24))(piVar6);
        if ((((cVar4 == '\0') || (cVar4 = FUN_0010a62e(piVar6,param_2), cVar4 == '\0')) ||
            ((char)piVar6[0x48] != '\0')) || (cVar4 = ((int (*)())FUN_00150030)(piVar6), cVar4 == '\0')) {
          return 0;
        }
        iVar8 = FUN_0010b0f4(piVar6,0);
        local_28 = *(undefined4 *)(iVar8 + 0x10);
        bVar2 = *(byte *)((int)&local_20 + iVar5);
        cVar4 = *(char *)((int)&local_28 + (uint)bVar2);
        piVar9 = piVar6;
        while (cVar4 == '\x01') {
          piVar9 = (int *)FUN_0010b180(piVar9,piVar9[0x21]);
          cVar4 = (**(code **)(*piVar9 + 0x24))(piVar9);
          if (cVar4 == '\0') {
            return 0;
          }
          cVar4 = FUN_0010a62e(piVar9,param_2);
          if (cVar4 == '\0') {
            return 0;
          }
          if ((char)piVar9[0x48] != '\0') {
            return 0;
          }
          cVar4 = ((int (*)())FUN_00150030)(piVar9);
          if (cVar4 == '\0') {
            return 0;
          }
          iVar8 = FUN_0010b0f4(piVar9,0);
          local_28 = *(undefined4 *)(iVar8 + 0x10);
          cVar4 = *(char *)((int)&local_28 + (uint)bVar2);
        }
        if (iVar5 < 1) {
LAB_0015408b:
          local_38[iVar5] = piVar9;
        }
        else if (local_38[0] != piVar9) {
          iVar8 = 0;
          do {
            iVar8 = iVar8 + 1;
            if (iVar8 == iVar5) goto LAB_0015408b;
          } while (local_38[iVar8] != piVar9);
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != 4);
    uVar3 = param_1[0x2e];
    uVar7 = uVar3 >> 1;
    local_40 = 1;
    do {
      while ((*(char *)((int)&local_28 + local_40 + 3) != '\0' ||
             (piVar9 = (int *)(&iStack_3c)[local_40], piVar9 == (int *)0x0))) {
LAB_00153f63:
        local_40 = local_40 + 1;
        if (local_40 == 5) goto LAB_00153f71;
      }
      *(int *)(param_2 + 0x16c) = *(int *)(param_2 + 0x16c) + 1;
      iVar5 = *(int *)(piVar9[0x22] + 8);
      iVar8 = (**(code **)(*piVar9 + 0x14))(piVar9);
      if (iVar8 == 1) {
        if ((uVar7 & 1) != 0) {
          if (((uVar3 & 1) == 0) && (cVar4 = FUN_000f7ff0(piVar9,1), cVar4 != '\0')) {
            piVar10 = piVar9 + 0x29;
          }
          else {
            piVar10 = piVar9 + 0x29;
            FUN_00109c0e(piVar10,2,1);
            if ((uVar3 & 1) != 0) {
              cVar4 = ((undefined4 (*)())FUN_00140e9c)(piVar9,1,0);
              if (cVar4 == '\0') {
                FUN_00109c0e(piVar10,1,1);
              }
              goto LAB_00153f63;
            }
          }
          goto LAB_00154100;
        }
LAB_0015412b:
        if ((uVar3 & 1) != 0) {
          if ((*(byte *)(piVar9 + 0x2e) & 1) == 0) {
            cVar4 = ((undefined4 (*)())FUN_00140e9c)(piVar9,1,0);
            if (cVar4 == '\0') {
              FUN_00109c0e(piVar9 + 0x29,1,1);
            }
          }
          else {
            FUN_00109c0e(piVar9 + 0x29,1,0);
          }
        }
        goto LAB_00153f63;
      }
      if (iVar5 != 0x13) {
        if (iVar5 == 0x12) {
          if ((uVar7 & 1) == 0) {
            if ((uVar3 & 1) != 0) {
              if ((*(byte *)(piVar9 + 0x2e) & 1) == 0) {
                cVar4 = ((undefined4 (*)())FUN_00140e9c)(piVar9,1,0);
                if (cVar4 == '\0') {
                  FUN_00109c0e(piVar9 + 0x29,1,1);
                }
              }
              else {
                FUN_00109c0e(piVar9 + 0x29,1,0);
              }
              if ((*(byte *)(piVar9 + 0x34) & 1) == 0) {
                cVar4 = ((undefined4 (*)())FUN_00140e9c)(piVar9,2,0);
                if (cVar4 == '\0') {
                  FUN_00109c0e(piVar9 + 0x2f,1,1);
                }
              }
              else {
                FUN_00109c0e(piVar9 + 0x2f,1,0);
              }
            }
          }
          else {
            piVar10 = piVar9 + 0x29;
            FUN_00109c0e(piVar10,2,1);
            piVar1 = piVar9 + 0x2f;
            FUN_00109c0e(piVar1,2,1);
            if ((uVar3 & 1) == 0) {
              FUN_00109c0e(piVar10,1,0);
              FUN_00109c0e(piVar1,1,0);
            }
            else {
              cVar4 = ((undefined4 (*)())FUN_00140e9c)(piVar9,1,0);
              if (cVar4 == '\0') {
                FUN_00109c0e(piVar10,1,1);
              }
              cVar4 = ((undefined4 (*)())FUN_00140e9c)(piVar9,2,0);
              if (cVar4 == '\0') {
                FUN_00109c0e(piVar1,1,1);
              }
            }
          }
        }
        else if (iVar5 - 0x24U < 3) {
          local_44 = 2;
          local_60 = 0xb0;
          piVar10 = piVar9 + 0x2f;
          do {
            if ((uVar7 & 1) == 0) {
              if ((uVar3 & 1) != 0) {
                if ((*(byte *)(local_60 + 0x20 + (int)piVar9) & 1) != 0) goto LAB_00153f3a;
                cVar4 = ((undefined4 (*)())FUN_00140e9c)(piVar9,local_44,0);
                if (cVar4 == '\0') {
                  FUN_00109c0e((int)piVar9 + local_60 + 0xc,1,1);
                }
              }
            }
            else {
              FUN_00109c0e(piVar10,2,1);
              if ((uVar3 & 1) == 0) {
LAB_00153f3a:
                FUN_00109c0e(piVar10,1,0);
              }
              else {
                cVar4 = ((undefined4 (*)())FUN_00140e9c)(piVar9,local_44,0);
                if (cVar4 == '\0') {
                  FUN_00109c0e(piVar10,1,1);
                }
              }
            }
            local_44 = local_44 + 1;
            piVar10 = piVar10 + 6;
            local_60 = local_60 + 0x18;
          } while (local_44 != 4);
        }
        goto LAB_00153f63;
      }
      if ((uVar7 & 1) == 0) goto LAB_0015412b;
      piVar1 = piVar9 + 0x29;
      FUN_00109c0e(piVar1,2,1);
      piVar10 = piVar9 + 0x2f;
      FUN_00109c0e(piVar10,2,1);
      if ((uVar3 & 1) == 0) {
        FUN_00109c0e(piVar1,1,0);
      }
      else {
        cVar4 = ((undefined4 (*)())FUN_00140e9c)(piVar9,1,0);
        if (cVar4 == '\0') {
          FUN_00109c0e(piVar1,1,1);
        }
      }
LAB_00154100:
      FUN_00109c0e(piVar10,1,0);
      local_40 = local_40 + 1;
    } while (local_40 != 5);
LAB_00153f71:
    *(int *)(param_2 + 0x16c) = *(int *)(param_2 + 0x16c) + 1;
    FUN_00109c0e(param_1 + 0x29,2,0);
    FUN_00109c0e(param_1 + 0x29,1,0);
  }
  cVar4 = FUN_000f5f28(local_24);
  if (((((cVar4 == '\0') || (cVar4 = FUN_000f5a1e(param_1,1), cVar4 == '\0')) &&
       (cVar4 = FUN_000f5672(local_20), cVar4 != '\0')) &&
      (((*(unsigned char *)((unsigned char *)&(local_20) + 3)) == '\x04' && (cVar4 = FUN_0010a62e(piVar6,param_2), cVar4 != '\0')))) &&
     ((cVar4 = FUN_00119098(*(undefined4 *)(piVar6[0x22] + 8),*(undefined4 *)(param_2 + 8)),
      cVar4 != '\0' && (cVar4 = FUN_001195a6(*(undefined4 *)(param_2 + 8),piVar6), cVar4 != '\0'))))
  {
    *(int *)(param_2 + 0x16c) = *(int *)(param_2 + 0x16c) + 1;
    iVar5 = FUN_0010b0f4(param_1,0);
    piVar6[0x27] = *(int *)(iVar5 + 0x10);
    iVar5 = FUN_0010b0f4(param_1,1);
    *(undefined4 *)(iVar5 + 0x10) = DAT_001cc5a0;
    iVar5 = 0;
    do {
      if (*(char *)((int)&local_24 + iVar5) == '\x01') {
        (**(code **)(*param_1 + 0x88))(param_1,1,iVar5,4);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != 4);
  }
  return 1;
}

/* FUN_00154696 @ 0x154696 (2236 bytes) */
int FUN_00154696(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined1 *param_3;
{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 local_80;
  int local_7c;
  int *local_70;
  int local_68;
  int local_60;
  int local_54;
  undefined4 local_40;
  int *local_3c;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  cVar1 = FUN_0012dfd8(param_1[0x26]);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*param_1 + 100))(param_1);
    if (cVar1 != '\0') {
      for (iVar2 = 1; iVar4 = (**(code **)(*param_1 + 0x14))(param_1), iVar2 <= iVar4;
          iVar2 = iVar2 + 1) {
        if ((((param_1[iVar2 * 6 + 0x28] & 1U) != 0) || ((param_1[iVar2 * 6 + 0x28] & 2U) != 0)) ||
           (cVar1 = FUN_000f5a1e(param_1,iVar2), cVar1 == '\0')) goto LAB_001546d9;
      }
      if (((char)param_1[0x48] == '\0') && (param_1[0x49] == 0)) {
        if (((param_1[0x20] != 0) &&
            ((cVar1 = FUN_0012dfd8(param_1[0x26]), cVar1 != '\0' &&
             ((*(byte *)(param_1 + 5) & 2) == 0)))) &&
           (cVar1 = (**(code **)(*param_1 + 0x50))(param_1), cVar1 == '\0')) {
          iVar2 = 4;
          piVar3 = param_1;
          do {
            if ((byte)((char)piVar3[0x27] - 2U) < 2) goto LAB_001546d9;
            piVar3 = (int *)((int)piVar3 + 1);
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
        FUN_0010b0f4(param_1,0);
        iVar2 = FUN_0010b7c8(param_1,0);
        if (((iVar2 == 0) && ((param_1[5] & 2U) == 0)) && ((param_1[5] & 0x200U) != 0)) {
          local_40 = 0;
          local_3c = (int *)0x0;
          local_2c = 0;
          FUN_0010a980(param_1,&local_40);
          local_70 = local_3c;
          piVar3 = (int *)FUN_0010b180(param_1,1);
          if (((-1 < piVar3[5]) && ((piVar3[5] & 0x200U) == 0)) &&
             ((cVar1 = (**(code **)(*piVar3 + 0x24))(piVar3), cVar1 != '\0' &&
              ((cVar1 = FUN_0010a62e(piVar3,param_2), cVar1 != '\0' &&
               (cVar1 = FUN_0011913a(*(undefined4 *)(piVar3[0x22] + 8),*(undefined4 *)(param_2 + 8))
               , cVar1 == '\0')))))) {
            iVar2 = FUN_0010b0f4(param_1,0);
            local_24 = *(int *)(iVar2 + 0x10);
            local_7c = local_30;
            piVar7 = piVar3;
LAB_00154a89:
            FUN_00110000(param_1,piVar7,param_2);
            cVar1 = (**(code **)(*piVar7 + 100))(piVar7);
            if (cVar1 != '\0') {
              for (local_68 = 1; iVar2 = (**(code **)(*piVar7 + 0x14))(piVar7), local_68 <= iVar2;
                  local_68 = local_68 + 1) {
                if ((((piVar7[local_68 * 6 + 0x28] & 1U) != 0) ||
                    ((piVar7[local_68 * 6 + 0x28] & 2U) != 0)) ||
                   (cVar1 = FUN_000f5a1e(piVar7,local_68), cVar1 == '\0')) goto LAB_00154aac;
              }
              if (((char)piVar7[0x48] == '\0') && (piVar7[0x49] == 0)) {
                if (((piVar7[0x20] != 0) &&
                    ((cVar1 = FUN_0012dfd8(piVar7[0x26]), cVar1 != '\0' &&
                     ((*(byte *)(piVar7 + 5) & 2) == 0)))) &&
                   (cVar1 = (**(code **)(*piVar7 + 0x50))(piVar7), cVar1 == '\0')) {
                  iVar2 = 4;
                  piVar3 = piVar7;
                  do {
                    if ((byte)((char)piVar3[0x27] - 2U) < 2) goto LAB_00154aac;
                    piVar3 = (int *)((int)piVar3 + 1);
                    iVar2 = iVar2 + -1;
                  } while (iVar2 != 0);
                }
                FUN_0010b0f4(piVar7,0);
                iVar2 = FUN_0010b7c8(piVar7,0);
                if ((((iVar2 == 0) && ((piVar7[5] & 2U) == 0)) && ((piVar7[5] & 0x200U) == 0)) &&
                   (piVar3 = (int *)FUN_0010b180(piVar7,1), piVar3 == local_70)) {
                  iVar2 = FUN_0010b0f4(local_70,0);
                  local_20[0] = *(undefined4 *)(iVar2 + 0x10);
                  iVar2 = 1;
                  do {
                    cVar1 = *(char *)((int)local_20 + iVar2 + -1);
                    if (cVar1 != '\x01') {
                      *(char *)((int)&local_28 + iVar2 + 3) = cVar1;
                    }
                    iVar2 = iVar2 + 1;
                  } while (iVar2 != 5);
                  piVar3[0x58] = piVar3[0x58] + -1;
                  if ((*(byte *)((int)piVar3 + 0x15) & 2) == 0) {
                    local_70 = (int *)0x0;
                  }
                  else {
                    local_70 = (int *)FUN_0010b180(piVar3,piVar3[0x21]);
                  }
                  local_28 = DAT_001cc5a4;
                  iVar2 = 1;
                  puVar6 = &DAT_001cc5a0;
                  do {
                    if (*(char *)((int)&local_28 + iVar2 + 3) != '\x01') {
                      *(undefined1 *)((int)&local_2c + iVar2 + 3) = *(undefined1 *)puVar6;
                    }
                    uVar5 = local_28;
                    iVar2 = iVar2 + 1;
                    puVar6 = (undefined4 *)((int)puVar6 + 1);
                  } while (iVar2 != 5);
                  iVar2 = FUN_0010b0f4(param_1,1);
                  *(undefined4 *)(iVar2 + 0x10) = uVar5;
                }
              }
            }
LAB_00154aac:
            if (local_70 != (int *)0x0) {
              FUN_0010c18e(param_1,local_70,0,*(undefined4 *)(param_2 + 8));
              if (param_1[0x21] == 0) {
                param_1[0x27] = local_7c;
              }
              else {
                iVar2 = FUN_0010b0f4(param_1,param_1[0x21]);
                *(int *)(iVar2 + 0x10) = local_7c;
              }
            }
            param_1[0x27] = local_24;
            *param_3 = 0;
            return 1;
          }
          if ((((((piVar3[0x20] != 0) && (cVar1 = FUN_0012dfd8(piVar3[0x26]), cVar1 != '\0')) &&
                ((*(byte *)(piVar3 + 5) & 2) == 0)) &&
               ((cVar1 = (**(code **)(*piVar3 + 0x50))(piVar3), cVar1 == '\0' &&
                (cVar1 = FUN_0010a62e(piVar3,param_2), cVar1 != '\0')))) && (-1 < local_70[5])) &&
             ((((local_70[5] & 0x200U) == 0 &&
               (cVar1 = (**(code **)(*local_70 + 0x24))(local_70), cVar1 != '\0')) &&
              ((cVar1 = FUN_0010a62e(local_70,param_2), cVar1 != '\0' &&
               (cVar1 = FUN_0011913a(*(undefined4 *)(local_70[0x22] + 8),
                                     *(undefined4 *)(param_2 + 8)), cVar1 == '\0')))))) {
            local_24 = FUN_000f5e2c(local_30);
            iVar2 = FUN_0010b0f4(param_1,1);
            local_7c = *(int *)(iVar2 + 0x10);
            piVar7 = local_70;
            local_70 = piVar3;
            goto LAB_00154a89;
          }
        }
      }
    }
LAB_001546d9:
    cVar1 = (**(code **)(*param_1 + 100))(param_1);
    if (((cVar1 != '\0') && ((char)param_1[0x48] == '\0')) &&
       ((param_1[0x49] == 0 && (((param_1[0x2e] & 1U) == 0 && ((param_1[0x2e] & 2U) == 0)))))) {
      if ((param_1[0x20] != 0) &&
         (((cVar1 = FUN_0012dfd8(param_1[0x26]), cVar1 != '\0' &&
           ((*(byte *)(param_1 + 5) & 2) == 0)) &&
          (cVar1 = (**(code **)(*param_1 + 0x50))(param_1), cVar1 == '\0')))) {
        iVar2 = 0;
        piVar3 = param_1;
        do {
          if ((byte)((char)piVar3[0x27] - 2U) < 2) {
            return 0;
          }
          iVar2 = iVar2 + 1;
          piVar3 = (int *)((int)piVar3 + 1);
        } while (iVar2 != 4);
      }
      FUN_0010b0f4(param_1,0);
      iVar2 = FUN_0010b7c8(param_1,0);
      if (iVar2 == 0) {
        piVar3 = (int *)FUN_0010b180(param_1,1);
        if (((-1 < piVar3[5]) && ((piVar3[5] & 0x200U) == 0)) &&
           ((((cVar1 = (**(code **)(*piVar3 + 0x24))(piVar3), cVar1 != '\0' &&
              ((cVar1 = FUN_0010a62e(piVar3,param_2), cVar1 != '\0' &&
               (cVar1 = FUN_0011913a(*(undefined4 *)(piVar3[0x22] + 8),*(undefined4 *)(param_2 + 8))
               , cVar1 == '\0')))) && (cVar1 = FUN_000f5f5e(param_1), cVar1 != '\0')) &&
            (cVar1 = FUN_000f5f5e(piVar3), cVar1 != '\0')))) {
          cVar1 = FUN_001190ce(*(undefined4 *)(piVar3[0x22] + 8),*(undefined4 *)(param_2 + 8));
          if ((cVar1 == '\0') &&
             (cVar1 = FUN_00119104(*(undefined4 *)(piVar3[0x22] + 8),*(undefined4 *)(param_2 + 8)),
             cVar1 == '\0')) {
            iVar2 = FUN_0010b0f4(piVar3,0);
            iVar2 = FUN_000f5950(*(undefined4 *)(iVar2 + 0x10));
            iVar4 = FUN_0010b0f4(param_1,0);
            uVar5 = FUN_000f5950(*(undefined4 *)(iVar4 + 0x10));
            for (local_54 = 1; iVar4 = (**(code **)(*piVar3 + 0x14))(piVar3), local_54 <= iVar4;
                local_54 = local_54 + 1) {
              iVar4 = FUN_0010b0f4(piVar3,local_54);
              cVar1 = *(char *)(iVar2 + 0x10 + iVar4);
              iVar4 = FUN_0010b0f4(piVar3,local_54);
              *(undefined4 *)(iVar4 + 0x10) = DAT_001cc5a4;
              if (cVar1 != '\x04') {
                (**(code **)(*piVar3 + 0x88))(piVar3,local_54,uVar5,cVar1);
              }
            }
          }
          local_80 = DAT_001cc5a0;
          if ((*(byte *)((int)param_1 + 0x15) & 2) == 0) {
            local_60 = 0;
          }
          else {
            local_60 = FUN_0010b180(param_1,param_1[0x21]);
            iVar2 = FUN_0010b0f4(param_1,param_1[0x21]);
            local_80 = *(undefined4 *)(iVar2 + 0x10);
          }
          iVar2 = FUN_0010b0f4(param_1,0);
          iVar2 = *(int *)(iVar2 + 0x10);
          iVar4 = param_1[3];
          FUN_00110000(param_1,piVar3,param_2);
          param_1[0x27] = iVar2;
          param_1[3] = iVar4;
          if (local_60 != 0) {
            FUN_0010c18e(param_1,local_60,0,*(undefined4 *)(param_2 + 8));
            iVar2 = FUN_0010b0f4(param_1,param_1[0x21]);
            *(undefined4 *)(iVar2 + 0x10) = local_80;
          }
          *param_3 = 0;
          return 1;
        }
      }
    }
  }
  return 0;
}

/* FUN_00154f52 @ 0x154f52 (120 bytes) */
int FUN_00154f52(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  byte local_10;
  
  iVar3 = param_3 * 0x18 + 0x80;
  uVar1 = *(uint *)(param_1 + 0x20 + iVar3);
  local_10 = (byte)uVar1 & 1;
  uVar2 = *(uint *)(param_2 + 0x20 + iVar3);
  if ((local_10 == ((byte)uVar2 & 1)) && (((byte)(uVar1 >> 1) & 1) == ((byte)(uVar2 >> 1) & 1))) {
    iVar3 = FUN_0010b0f4(param_2,param_3);
    iVar3 = *(int *)(iVar3 + 0x10);
    iVar4 = FUN_0010b0f4(param_1,param_3);
    if (*(int *)(iVar4 + 0x10) == iVar3) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00154fca @ 0x154fca (3112 bytes) */
int FUN_00154fca(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int *param_3;
  undefined4 *param_4;
  int param_5;
{
  float *pfVar1;
  float fVar2;
  byte bVar3;
  code *pcVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  byte bVar14;
  int iVar15;
  bool bVar16;
  bool bVar17;
  int local_60;
  int local_5c;
  int *local_54;
  int *local_50;
  int local_44;
  int local_40;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  (**(code **)(*param_3 + 100))(param_3);
  (**(code **)(*param_1 + 0x60))(param_1);
  cVar6 = (**(code **)(*param_1 + 0x58))(param_1);
  if (cVar6 == '\0') {
    iVar7 = FUN_0010b0f4(param_1,param_2);
    local_20[0] = *(undefined4 *)(iVar7 + 0x10);
    local_20[0] = FUN_000f5610(*param_4,local_20[0]);
    pcVar4 = *(code **)(**(int **)(param_5 + 0x54) + 0x104);
    uVar8 = FUN_0010b180(param_3,1);
    cVar6 = (*pcVar4)(*(undefined4 *)(param_5 + 0x54),param_1,param_2,local_20,uVar8);
    if (cVar6 != '\0') {
      piVar9 = (int *)FUN_0010b180(param_3,1);
      piVar10 = (int *)FUN_0010b180(param_1,param_2);
      cVar6 = (**(code **)(*piVar10 + 0x60))(piVar10);
      if ((cVar6 == '\0') || ((*(byte *)(param_3 + 0x2e) & 1) == 0)) {
        iVar7 = *(int *)(param_5 + 0x3f4);
        cVar6 = (**(code **)(*piVar10 + 0x60))(piVar10);
        local_54 = piVar9;
        if (cVar6 == '\0') {
          bVar14 = (byte)param_3[0x2e] & 1;
          bVar16 = (param_1[param_2 * 6 + 0x28] & 2U) != 0;
          if (bVar16) {
            bVar14 = 0;
          }
          bVar16 = bVar16 || (param_3[0x2e] & 2U) != 0;
          bVar17 = ((byte)param_1[param_2 * 6 + 0x28] & 1) != bVar14;
          cVar6 = (**(code **)(**(int **)(param_5 + 0x54) + 0x11c))
                            (*(int **)(param_5 + 0x54),param_1,param_2,piVar9,bVar16,bVar17,param_5)
          ;
          if (cVar6 == '\0') {
            return 0;
          }
          *(int *)(iVar7 + 0x17c) = *(int *)(iVar7 + 0x17c) + 1;
          cVar6 = (**(code **)(*piVar9 + 0x5c))(piVar9);
          if ((cVar6 == '\0') || (cVar6 = FUN_0010a62e(param_3,iVar7), cVar6 != '\0')) {
            if (*(int *)(iVar7 + 0x46c) < piVar9[0x58]) {
              piVar9[0x58] = piVar9[0x58] + 1;
            }
            else {
              piVar9[0x58] = *(int *)(iVar7 + 0x46c) + 1;
            }
          }
          else {
            local_54 = (int *)FUN_0010a1c2(piVar9,param_5,0);
            local_54[0x25] = local_54[0x53];
            local_54[0x26] = 0x31;
            FUN_000e9596(piVar9[0x56],piVar9,local_54);
            local_54[0x58] = *(int *)(iVar7 + 0x46c) + 1;
            iVar11 = *(int *)(iVar7 + 0x46c);
            iVar12 = FUN_0010b180(local_54,1);
            if (iVar11 < *(int *)(iVar12 + 0x160)) {
              *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + 1;
            }
            else {
              *(int *)(iVar12 + 0x160) = iVar11 + 1;
            }
            if (1 < local_54[0x21]) {
              iVar11 = *(int *)(iVar7 + 0x46c);
              iVar12 = FUN_0010b180(local_54,2);
              if (iVar11 < *(int *)(iVar12 + 0x160)) {
                *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + 1;
              }
              else {
                *(int *)(iVar12 + 0x160) = iVar11 + 1;
              }
            }
          }
          FUN_0010ba02(param_1,param_2,local_54,0,param_5);
          iVar11 = (**(code **)(*param_3 + 0x14))(param_3);
          uVar5 = param_3[5];
          if ((uVar5 & 0x200) != 0) {
            iVar11 = iVar11 + 1;
          }
          if (iVar11 < param_3[0x21]) {
            iVar11 = param_3[0x21];
            iVar12 = (**(code **)(*param_3 + 0x14))(param_3);
            while (iVar12 = iVar12 + 1, iVar12 <= (int)(iVar11 + -1 + (uint)((uVar5 & 0x200) == 0)))
            {
              iVar15 = *(int *)(iVar7 + 0x46c);
              iVar13 = FUN_0010b180(param_3,iVar12);
              if (iVar15 < *(int *)(iVar13 + 0x160)) {
                *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
              }
              else {
                *(int *)(iVar13 + 0x160) = iVar15 + 1;
              }
              pcVar4 = *(code **)(*param_1 + 0x94);
              uVar8 = FUN_0010b180(param_3,iVar12);
              (*pcVar4)(param_1,uVar8,param_5);
            }
          }
          uVar8 = local_20[0];
          iVar7 = FUN_0010b0f4(param_1,param_2);
          *(undefined4 *)(iVar7 + 0x10) = uVar8;
          FUN_00109c0e(param_1 + param_2 * 6 + 0x23,2,bVar16);
          FUN_00109c0e(param_1 + param_2 * 6 + 0x23,1,bVar17);
        }
        else {
          *(int *)(iVar7 + 0x17c) = *(int *)(iVar7 + 0x17c) + 1;
          cVar6 = (**(code **)(*piVar9 + 0x60))(piVar9);
          if (cVar6 == '\0') {
            iVar11 = FUN_0010b0f4(param_3,1);
            local_24 = *(undefined4 *)(iVar11 + 0x10);
            iVar11 = 0;
            do {
              iVar12 = FUN_0010b0f4(piVar10,1);
              bVar14 = *(byte *)(iVar11 + 0x10 + iVar12);
              if (bVar14 != 4) {
                (**(code **)(*piVar10 + 0x88))
                          (piVar10,1,iVar11,*(undefined1 *)((int)local_20 + (bVar14 - 4)));
                FUN_0010b0f4(param_3,0);
              }
              iVar11 = iVar11 + 1;
            } while (iVar11 != 4);
            cVar6 = (**(code **)(*piVar9 + 0x5c))(piVar9);
            if ((cVar6 == '\0') || (cVar6 = FUN_0010a62e(param_3,iVar7), cVar6 != '\0')) {
              if (*(int *)(iVar7 + 0x46c) < piVar9[0x58]) {
                piVar9[0x58] = piVar9[0x58] + 1;
              }
              else {
                piVar9[0x58] = *(int *)(iVar7 + 0x46c) + 1;
              }
            }
            else {
              local_54 = (int *)FUN_0010a1c2(piVar9,param_5,0);
              local_54[0x25] = local_54[0x53];
              local_54[0x26] = 0x31;
              FUN_000e9596(piVar9[0x56],piVar9,local_54);
              local_54[0x58] = *(int *)(iVar7 + 0x46c) + 1;
              iVar11 = *(int *)(iVar7 + 0x46c);
              iVar12 = FUN_0010b180(local_54,1);
              if (iVar11 < *(int *)(iVar12 + 0x160)) {
                *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + 1;
              }
              else {
                *(int *)(iVar12 + 0x160) = iVar11 + 1;
              }
              if (1 < local_54[0x21]) {
                iVar7 = *(int *)(iVar7 + 0x46c);
                iVar11 = FUN_0010b180(local_54,2);
                if (iVar7 < *(int *)(iVar11 + 0x160)) {
                  *(int *)(iVar11 + 0x160) = *(int *)(iVar11 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar11 + 0x160) = iVar7 + 1;
                }
              }
            }
            FUN_0010ba02(piVar10,1,local_54,0,param_5);
            if (((*(byte *)(param_1 + param_2 * 6 + 0x28) & 2) == 0) && ((param_3[0x2e] & 2U) == 0))
            {
              uVar8 = 0;
            }
            else {
              uVar8 = 1;
            }
            FUN_00109c0e(param_1 + param_2 * 6 + 0x23,2,uVar8);
            iVar11 = FUN_0010b180(piVar10,1);
            if ((*(byte *)((int)param_1 + 0x15) & 2) == 0) {
              iVar7 = param_1[0x21];
            }
            else {
              iVar7 = param_1[0x21] + -1;
            }
            iVar12 = (**(code **)(*param_1 + 0x14))(param_1);
            do {
              iVar12 = iVar12 + 1;
              if (iVar7 < iVar12) goto LAB_00155287;
              piVar9 = (int *)FUN_0010b180(param_1,iVar12);
            } while (param_3 != piVar9);
          }
          else {
            iVar11 = FUN_00109e42(piVar10,iVar7);
            local_50 = piVar10;
            if (1 < iVar11) {
              local_50 = (int *)FUN_0010a1c2(piVar10,param_5,0);
              local_50[0x25] = local_50[0x53];
              local_50[0x26] = 0x36;
              FUN_000e956e(param_1[0x56],param_1,local_50);
              FUN_0010ba02(param_1,param_2,local_50,0,param_5);
              piVar10[0x58] = piVar10[0x58] + -1;
              local_50[0x58] = *(int *)(iVar7 + 0x46c) + 1;
              if (0 < local_50[0x21]) {
                local_44 = 1;
                do {
                  iVar11 = *(int *)(iVar7 + 0x46c);
                  iVar12 = FUN_0010b180(local_50,local_44);
                  if (iVar11 < *(int *)(iVar12 + 0x160)) {
                    *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar12 + 0x160) = iVar11 + 1;
                  }
                  local_44 = local_44 + 1;
                } while (local_44 <= local_50[0x21]);
              }
            }
            local_40 = 0;
            local_60 = 0;
            do {
              iVar11 = FUN_0010b0f4(local_50,1);
              bVar14 = *(byte *)(local_40 + 0x10 + iVar11);
              iVar11 = FUN_0010b0f4(param_3,1);
              bVar3 = *(byte *)(bVar14 + 0x10 + iVar11);
              iVar11 = FUN_0010b0f4(piVar9,1);
              cVar6 = *(char *)(bVar3 + 0x10 + iVar11);
              if (bVar14 != 4) {
                if (cVar6 == '\x04') {
                  (**(code **)(*local_50 + 0x88))(local_50,1,local_40,4);
                  if (1 < piVar9[0x21]) {
                    iVar11 = 2;
                    local_5c = 0x30;
                    do {
                      iVar12 = FUN_0010b0f4(piVar9,iVar11);
                      cVar6 = *(char *)(local_40 + 0x10 + iVar12);
                      if (cVar6 != '\x04') {
                        iVar12 = FUN_0010b180(piVar9,iVar11);
                        fVar2 = *(float *)(local_5c + 0x20 + iVar12);
                        if (1 < local_50[0x21]) {
                          iVar12 = 2;
                          do {
                            iVar15 = FUN_0010b180(local_50,iVar12);
                            pfVar1 = (float *)(local_60 + 0x20 + iVar15);
                            if ((fVar2 == *pfVar1) && (!NAN(fVar2) && !NAN(*pfVar1))) {
                              (**(code **)(*local_50 + 0x88))(local_50,iVar12,local_40,cVar6);
                              goto LAB_0015591b;
                            }
                            iVar12 = iVar12 + 1;
                          } while (iVar12 <= local_50[0x21]);
                        }
                        iVar15 = local_50[0x21] + 1;
                        local_50[0x21] = iVar15;
                        FUN_000fa0d2(local_50,iVar7,iVar15,fVar2,fVar2,fVar2,fVar2);
                        iVar12 = FUN_0010b0f4(local_50,iVar15);
                        *(undefined4 *)(iVar12 + 0x10) = DAT_001cc5a4;
                        (**(code **)(*local_50 + 0x88))(local_50,iVar15,local_40,cVar6);
                        iVar12 = FUN_0010b180(local_50,iVar15);
                        if (*(int *)(iVar7 + 0x46c) < *(int *)(iVar12 + 0x160)) {
                          *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar12 + 0x160) = *(int *)(iVar7 + 0x46c) + 1;
                        }
                      }
LAB_0015591b:
                      iVar11 = iVar11 + 1;
                      local_5c = local_5c + 0x18;
                    } while (iVar11 <= piVar9[0x21]);
                  }
                }
                else {
                  (**(code **)(*local_50 + 0x88))(local_50,1,local_40,cVar6);
                }
              }
              local_40 = local_40 + 1;
              local_60 = local_60 + 0x18;
            } while (local_40 != 4);
            iVar11 = FUN_0010b180(piVar9,1);
            FUN_0010ba02(local_50,1,iVar11,0,param_5);
            if (*(int *)(iVar7 + 0x46c) < *(int *)(iVar11 + 0x160)) {
              *(int *)(iVar11 + 0x160) = *(int *)(iVar11 + 0x160) + 1;
            }
            else {
              *(int *)(iVar11 + 0x160) = *(int *)(iVar7 + 0x46c) + 1;
            }
            if (((*(byte *)(param_1 + param_2 * 6 + 0x28) & 2) == 0) && ((param_3[0x2e] & 2U) == 0))
            {
              uVar8 = 0;
            }
            else {
              uVar8 = 1;
            }
            FUN_00109c0e(param_1 + param_2 * 6 + 0x23,2,uVar8);
            if ((*(byte *)((int)param_1 + 0x15) & 2) == 0) {
              iVar7 = param_1[0x21];
            }
            else {
              iVar7 = param_1[0x21] + -1;
            }
            iVar12 = (**(code **)(*param_1 + 0x14))(param_1);
            do {
              iVar12 = iVar12 + 1;
              if (iVar7 < iVar12) goto LAB_00155287;
              piVar9 = (int *)FUN_0010b180(param_1,iVar12);
            } while (param_3 != piVar9);
          }
          FUN_0010ba02(param_1,iVar12,iVar11,0,param_5);
        }
LAB_00155287:
        FUN_0010b3fe(param_3,param_5);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00155bf2 @ 0x155bf2 (2893 bytes) */
int FUN_00155bf2(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int *param_3;
  int param_4;
  undefined1 *param_5;
{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  undefined4 *puVar11;
  char cStack_39;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  cVar2 = (**(code **)(*param_3 + 0x60))(param_3);
  if (cVar2 != '\0') {
    param_3 = (int *)FUN_0010b180(param_3,1);
  }
  cVar2 = (**(code **)(*param_3 + 100))(param_3);
  if (cVar2 == '\0') {
    return 0;
  }
  cVar2 = FUN_0012dfd8(param_3[0x26]);
  if (cVar2 == '\0') {
    return 0;
  }
  if (((((*(byte *)((int)param_3 + 0x15) & 2) != 0) &&
       (cVar2 = FUN_000f5a1e(param_3,1), cVar2 != '\0')) && ((char)param_3[0x48] == '\0')) &&
     (((param_3[0x49] == 0 && ((param_3[0x2e] & 1U) == 0)) && ((param_3[0x2e] & 2U) == 0)))) {
    if (((param_3[0x20] != 0) && (cVar2 = FUN_0012dfd8(param_3[0x26]), cVar2 != '\0')) &&
       (((*(byte *)(param_3 + 5) & 2) == 0 &&
        (cVar2 = (**(code **)(*param_3 + 0x50))(param_3), cVar2 == '\0')))) {
      iVar3 = 0;
      piVar4 = param_3;
      do {
        if ((byte)((char)piVar4[0x27] - 2U) < 2) goto LAB_00155c45;
        iVar3 = iVar3 + 1;
        piVar4 = (int *)((int)piVar4 + 1);
      } while (iVar3 != 4);
    }
    if (*(int *)(param_4 + 0x17c) < *(int *)(*(int *)(param_4 + 8) + 0x394)) {
      iVar3 = FUN_0010b180(param_3,1);
      iVar5 = FUN_0010b180(param_3,param_3[0x21]);
      iVar7 = FUN_0010b0f4(iVar5,0);
      local_20[0] = *(undefined4 *)(iVar7 + 0x10);
      iVar7 = FUN_0010b0f4(param_3,0);
      local_38 = *(undefined4 *)(iVar7 + 0x10);
      iVar7 = 1;
      do {
        if (((&cStack_39)[iVar7] != '\x01') && (*(char *)((int)local_20 + iVar7 + -1) != '\x01'))
        goto LAB_00155c45;
        iVar7 = iVar7 + 1;
      } while (iVar7 != 5);
      if (((*(byte *)(iVar5 + 0x15) & 2) != 0) &&
         (iVar7 = FUN_0010b180(iVar5,*(undefined4 *)(iVar5 + 0x84)), iVar3 == iVar7)) {
        *(int *)(param_4 + 0x17c) = *(int *)(param_4 + 0x17c) + 1;
        iVar3 = (**(code **)(*param_1 + 0x14))(param_1);
        if ((iVar3 < param_2) &&
           (((*(byte *)((int)param_1 + 0x15) & 2) != 0 &&
            (piVar4 = (int *)FUN_0010b180(param_1,param_1[0x21]), param_3 == piVar4)))) {
          FUN_0010c18e(param_1,iVar5,0,*(undefined4 *)(param_4 + 8));
          iVar3 = *(int *)(param_4 + 0x46c);
          iVar7 = *(int *)(iVar5 + 0x160);
          if (iVar3 < iVar7) {
LAB_00155ff6:
            *(int *)(iVar5 + 0x160) = iVar7 + 1;
            goto LAB_00155fff;
          }
        }
        else {
          FUN_0010ba02(param_1,param_2,iVar5,0,*(undefined4 *)(param_4 + 8));
          iVar3 = *(int *)(param_4 + 0x46c);
          iVar7 = *(int *)(iVar5 + 0x160);
          if (iVar3 < iVar7) goto LAB_00155ff6;
        }
        *(int *)(iVar5 + 0x160) = iVar3 + 1;
LAB_00155fff:
        FUN_0010b3fe(param_3,*(undefined4 *)(param_4 + 8));
        *param_5 = 1;
        return 1;
      }
    }
  }
LAB_00155c45:
  iVar3 = (**(code **)(*param_1 + 0x14))(param_1);
  if (param_2 <= iVar3) {
    iVar3 = (**(code **)(*param_1 + 0x14))(param_1);
    if (((param_2 <= iVar3) && ((char)param_3[0x48] == '\0')) && (param_3[0x49] == 0)) {
      if (((param_3[0x20] != 0) && (cVar2 = FUN_0012dfd8(param_3[0x26]), cVar2 != '\0')) &&
         (((*(byte *)(param_3 + 5) & 2) == 0 &&
          (cVar2 = (**(code **)(*param_3 + 0x50))(param_3), cVar2 == '\0')))) {
        iVar3 = 0;
        piVar4 = param_3;
        do {
          if ((byte)((char)piVar4[0x27] - 2U) < 2) {
            return 0;
          }
          iVar3 = iVar3 + 1;
          piVar4 = (int *)((int)piVar4 + 1);
        } while (iVar3 != 4);
      }
      FUN_0010b0f4(param_3,0);
      iVar3 = FUN_0010b7c8(param_3,0);
      if (((iVar3 == 0) && (*(int *)(param_1[0x22] + 8) != 0x8e)) &&
         (cVar2 = (**(code **)(*param_1 + 0x60))(param_1), cVar2 == '\0')) {
        cVar2 = (**(code **)(*param_1 + 0x28))(param_1);
        if (cVar2 != '\0') {
          piVar4 = (int *)FUN_0010b180(param_3,1);
          cVar2 = (**(code **)(*piVar4 + 0x5c))(piVar4);
          if (cVar2 != '\0') {
            return 0;
          }
        }
        cVar2 = (**(code **)(*param_1 + 0x28))(param_1);
        if (cVar2 != '\0') {
          iVar3 = FUN_0010b180(param_3,1);
          if (iVar3 == 0) {
            iVar3 = param_3[0x2c];
          }
          else {
            iVar3 = FUN_0010b180(param_3,1);
            iVar3 = *(int *)(iVar3 + 0x98);
          }
          cVar2 = FUN_0012df9c(iVar3);
          if (cVar2 != '\0') {
            return 0;
          }
        }
        if ((*(int *)(param_4 + 0x17c) < *(int *)(*(int *)(param_4 + 8) + 0x394)) &&
           ((piVar8 = (int *)FUN_0010b180(param_1,param_2), piVar4 = param_3, param_3 == piVar8 ||
            ((cVar2 = (**(code **)(*piVar8 + 0x60))(piVar8), cVar2 != '\0' &&
             (piVar9 = (int *)FUN_0010b180(piVar8,1), piVar4 = piVar8, param_3 == piVar9)))))) {
          iVar3 = FUN_0010b0f4(piVar4,0);
          local_28 = FUN_000f5fea(*(undefined4 *)(iVar3 + 0x10));
          iVar3 = FUN_0010b0f4(param_3,1);
          local_2c = *(undefined4 *)(iVar3 + 0x10);
          if ((*(byte *)((int)param_3 + 0x15) & 2) == 0) {
            iVar3 = FUN_0010b0f4(param_1,param_2);
            uVar10 = FUN_000f5bdc(*(undefined4 *)(iVar3 + 0x10));
            if ((local_28 < uVar10) && ((*(byte *)(param_1 + 5) & 2) != 0)) {
              iVar3 = FUN_0010b0f4(param_3,0);
              param_1[0x27] = *(int *)(iVar3 + 0x10);
            }
          }
          else {
            piVar4 = (int *)FUN_0010b180(param_3,param_3[0x21]);
            piVar8 = (int *)FUN_0010b180(param_3,1);
            if (((piVar4 == piVar8) && ((param_3[0x2e] & 2U) == 0)) && ((param_3[0x2e] & 1U) == 0))
            {
              iVar3 = 1;
              puVar11 = &DAT_001cc5a0;
              do {
                if (*(char *)((int)&local_2c + iVar3 + 3) == '\0') {
                  *(undefined1 *)((int)&local_30 + iVar3 + 3) = *(undefined1 *)puVar11;
                }
                iVar3 = iVar3 + 1;
                puVar11 = (undefined4 *)((int)puVar11 + 1);
              } while (iVar3 != 5);
            }
            else {
              cVar2 = (**(code **)(*piVar4 + 100))(piVar4);
              if (cVar2 == '\0') {
                return 0;
              }
              iVar3 = FUN_0010b180(param_3,1);
              iVar5 = FUN_0010b180(piVar4,1);
              if (iVar3 != iVar5) {
                return 0;
              }
              if (((byte)((uint)param_3[0x2e] >> 1) & 1) != ((byte)((uint)piVar4[0x2e] >> 1) & 1)) {
                return 0;
              }
              if (((byte)param_3[0x2e] & 1) != ((byte)piVar4[0x2e] & 1)) {
                return 0;
              }
              if ((char)piVar4[0x48] != '\0') {
                return 0;
              }
              if (piVar4[0x49] != 0) {
                return 0;
              }
              iVar3 = FUN_0010b0f4(piVar4,0);
              local_30 = *(undefined4 *)(iVar3 + 0x10);
              iVar3 = FUN_0010b0f4(piVar4,1);
              local_34 = *(undefined4 *)(iVar3 + 0x10);
              iVar3 = FUN_0010b0f4(param_1,param_2);
              local_24 = FUN_000f5bdc(*(undefined4 *)(iVar3 + 0x10));
              iVar3 = 1;
              do {
                if ((*(char *)((int)&local_28 + iVar3 + 3) != '\0') &&
                   (*(char *)((int)&local_2c + iVar3 + 3) == '\0')) {
                  if (*(char *)((int)&local_34 + iVar3 + 3) != '\0') {
                    return 0;
                  }
                  *(undefined1 *)((int)&local_30 + iVar3 + 3) =
                       *(undefined1 *)((int)&local_38 + iVar3 + 3);
                }
                iVar3 = iVar3 + 1;
              } while (iVar3 != 5);
            }
          }
          cVar2 = ((int (*)())FUN_00154fca)(param_1,param_2,param_3,&local_2c,*(undefined4 *)(param_4 + 8));
          if (cVar2 != '\0') {
            *param_5 = 1;
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ((*(byte *)((int)param_1 + 0x15) & 2) == 0) {
    return 0;
  }
  piVar4 = (int *)FUN_0010b180(param_1,param_1[0x21]);
  if (param_3 != piVar4) {
    return 0;
  }
  if ((*(byte *)((int)param_3 + 0x15) & 2) != 0) {
    return 0;
  }
  if ((char)param_3[0x48] != '\0') {
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
  if (((param_3[0x20] != 0) && (cVar2 = FUN_0012dfd8(param_3[0x26]), cVar2 != '\0')) &&
     (((*(byte *)(param_3 + 5) & 2) == 0 &&
      (cVar2 = (**(code **)(*param_3 + 0x50))(param_3), cVar2 == '\0')))) {
    iVar3 = 0;
    piVar4 = param_3;
    do {
      if ((byte)((char)piVar4[0x27] - 2U) < 2) {
        return 0;
      }
      iVar3 = iVar3 + 1;
      piVar4 = (int *)((int)piVar4 + 1);
    } while (iVar3 != 4);
  }
  FUN_0010b0f4(param_3,0);
  iVar3 = FUN_0010b7c8(param_3,0);
  if (iVar3 != 0) {
    return 0;
  }
  piVar4 = (int *)FUN_0010b180(param_3,1);
  if (piVar4[0x20] == 0) {
    return 0;
  }
  cVar2 = FUN_0012dfd8(piVar4[0x26]);
  if (cVar2 == '\0') {
    return 0;
  }
  if ((*(byte *)(piVar4 + 5) & 2) != 0) {
    return 0;
  }
  cVar2 = (**(code **)(*piVar4 + 0x50))(piVar4);
  if (cVar2 != '\0') {
    return 0;
  }
  cVar2 = FUN_000f5a1e(param_3,1);
  if (cVar2 == '\0') {
    return 0;
  }
  piVar4 = (int *)FUN_0010b180(param_3,1);
  cVar2 = (**(code **)(*piVar4 + 0x5c))(piVar4);
  if (cVar2 != '\0') {
    return 0;
  }
  if (*(int *)(*(int *)(param_4 + 8) + 0x394) <= *(int *)(param_4 + 0x17c)) {
    return 0;
  }
  iVar3 = FUN_0010b0f4(param_3,0);
  FUN_000f5fea(*(undefined4 *)(iVar3 + 0x10));
  iVar3 = FUN_0010b0f4(param_1,0);
  FUN_000f6032(*(undefined4 *)(iVar3 + 0x10),DAT_001cc6dc);
  *(int *)(param_4 + 0x17c) = *(int *)(param_4 + 0x17c) + 1;
  cVar2 = FUN_0010a62e(param_3,param_4);
  if (cVar2 == '\0') {
    uVar1 = *(undefined4 *)(param_4 + 8);
    uVar6 = FUN_0010b180(param_3,1);
    FUN_0010c18e(param_1,uVar6,0,uVar1);
    param_3[0x58] = param_3[0x58] + -1;
    iVar3 = *(int *)(param_4 + 0x46c);
    iVar5 = FUN_0010b180(param_3,1);
    if (iVar3 < *(int *)(iVar5 + 0x160)) {
      *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + 1;
    }
    else {
      *(int *)(iVar5 + 0x160) = iVar3 + 1;
    }
    goto LAB_00155e5d;
  }
  cVar2 = (**(code **)(*param_1 + 100))(param_1);
  if (cVar2 == '\0') {
LAB_00155e12:
    uVar1 = *(undefined4 *)(param_4 + 8);
    uVar6 = FUN_0010b180(param_3,1);
    FUN_0010c18e(param_1,uVar6,0,uVar1);
  }
  else {
    iVar3 = FUN_0010b180(param_1,1);
    iVar5 = FUN_0010b180(param_3,1);
    if (((iVar3 != iVar5) || ((char)param_1[0x48] != (char)param_3[0x48])) ||
       (param_1[0x49] != param_3[0x49])) goto LAB_00155e12;
    if ((((byte)param_1[0x2e] & 1) != ((byte)param_3[0x2e] & 1)) ||
       (((byte)((uint)param_1[0x2e] >> 1) & 1) != ((byte)((uint)param_3[0x2e] >> 1) & 1)))
    goto LAB_00155e12;
    iVar3 = FUN_0010b0f4(param_3,0);
    uVar10 = *(uint *)(iVar3 + 0x10);
    iVar3 = FUN_0010b0f4(param_1,0);
    param_1[0x27] = uVar10 & *(uint *)(iVar3 + 0x10);
    iVar3 = FUN_0010b0f4(param_1,1);
    local_24 = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = FUN_0010b0f4(param_3,1);
    uVar1 = local_24;
    local_28 = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = 1;
    do {
      if (*(char *)((int)&local_28 + iVar3 + 3) == '\x04') {
        *(undefined1 *)((int)&local_28 + iVar3 + 3) = *(undefined1 *)((int)&local_2c + iVar3 + 3);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 5);
    iVar3 = FUN_0010b0f4(param_1,1);
    *(undefined4 *)(iVar3 + 0x10) = uVar1;
    FUN_0010ba02(param_1,param_1[0x21],0,0,*(undefined4 *)(param_4 + 8));
    param_1[0x21] = param_1[0x21] + -1;
    param_1[5] = param_1[5] & 0xfffffdff;
    iVar3 = FUN_0010b180(param_1,1);
    *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + -1;
  }
  (**(code **)(*param_3 + 0xc))(param_3,0,*(undefined4 *)(param_4 + 8));
LAB_00155e5d:
  *param_5 = 1;
  return 1;
}

/* FUN_00156740 @ 0x156740 (99 bytes) */
int FUN_00156740(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  undefined4 local_10;
  
  iVar1 = FUN_0010b0f4(param_1,*(undefined4 *)(param_1 + 0x84));
  local_10 = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = 0;
  while( true ) {
    iVar2 = FUN_0010b0f4(param_2,0);
    if ((*(char *)(iVar1 + 0x10 + iVar2) != '\x01') && (*(char *)((int)&local_10 + iVar1) == '\x04')
       ) break;
    iVar1 = iVar1 + 1;
    if (iVar1 == 4) {
      return 1;
    }
  }
  return 0;
}

/* FUN_001567a4 @ 0x1567a4 (643 bytes) */
int FUN_001567a4(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 local_28;
  int *local_24;
  undefined4 local_14;
  int local_10;
  
  uVar1 = *(uint *)(*(int *)(*(int *)(param_3 + 8) + 0x54) + 8);
  if ((((uVar1 & 0x800) != 0) && ((uVar1 & 0x1000) != 0)) &&
     (cVar3 = FUN_000e1402(*(int *)(param_3 + 8),0x38), cVar3 != '\0')) {
    piVar4 = (int *)FUN_0010b180(param_1,param_2);
    iVar5 = FUN_0010b0f4(param_1,param_2);
    local_10 = *(int *)(iVar5 + 0x10);
    cVar3 = (**(code **)(*piVar4 + 0x30))(piVar4);
    if (((cVar3 != '\0') && (cVar3 = FUN_0010a62e(piVar4,param_3), cVar3 != '\0')) &&
       ((*(byte *)((int)piVar4 + 0x15) & 2) == 0)) {
      cVar3 = FUN_000f59e0(local_10);
      if (cVar3 == '\0') {
        local_10 = FUN_000f5610(piVar4[0x50],local_10);
        piVar4[0x50] = local_10;
        iVar5 = 0;
        do {
          if (*(char *)((int)&local_10 + iVar5) == '\x04') {
            *(undefined1 *)(iVar5 + 0x9c + (int)piVar4) = 1;
          }
          else {
            *(undefined1 *)(iVar5 + 0x9c + (int)piVar4) = 0;
            *(char *)((int)&local_10 + iVar5) = (char)iVar5;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 != 4);
      }
      local_28 = 0;
      local_24 = (int *)0x0;
      local_14 = 0;
      if ((*(byte *)((int)param_1 + 0x15) & 2) != 0) {
        FUN_0010a980(param_1,&local_28);
      }
      piVar2 = local_24;
      cVar3 = (**(code **)(*param_1 + 100))(param_1);
      if (((cVar3 == '\0') ||
          (((piVar2 != (int *)0x0 &&
            ((cVar3 = (**(code **)(*piVar2 + 0x30))(piVar2), cVar3 == '\0' ||
             (cVar3 = ((int (*)())FUN_00156740)(param_1,piVar2), cVar3 == '\0')))) ||
           ((param_1[param_2 * 6 + 0x28] & 1U) != 0)))) ||
         (((((param_1[param_2 * 6 + 0x28] & 2U) != 0 || ((char)param_1[0x48] != '\0')) ||
           (param_1[0x49] != 0)) || (cVar3 = FUN_0010a62e(param_1,param_3), cVar3 == '\0')))) {
        iVar6 = FUN_0010b0f4(param_1,param_2);
        iVar5 = local_10;
        if (*(int *)(iVar6 + 0x10) != local_10) {
          if (param_2 == 0) {
            param_1[0x27] = local_10;
            return 1;
          }
          iVar6 = FUN_0010b0f4(param_1,param_2);
          *(int *)(iVar6 + 0x10) = iVar5;
          return 1;
        }
      }
      else {
        iVar5 = param_1[2];
        FUN_001a7d72(piVar4);
        FUN_001a7d72(param_1);
        uVar7 = FUN_00109cd4(piVar4,param_1,*(undefined4 *)(param_3 + 8),1);
        FUN_000e956e(*(undefined4 *)(iVar5 + 0x158),iVar5,uVar7);
        if (piVar2 != (int *)0x0) {
          FUN_0010c568(uVar7,&local_28,0,*(undefined4 *)(param_3 + 8));
        }
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_00156a28 @ 0x156a28 (175 bytes) */
int FUN_00156a28(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = (**(code **)(*param_1 + 0x60))(param_1);
  if (cVar1 != '\0') {
    param_1 = (int *)FUN_0010b180(param_1,1);
  }
  cVar1 = (**(code **)(*param_1 + 100))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  ((int (*)())FUN_00150c22)(param_1,param_2);
  ((int (*)())FUN_00153dea)(param_1,param_2);
  ((int (*)())FUN_00153954)(param_1,param_2);
  uVar2 = ((int (*)())FUN_001567a4)(param_1,1,param_2);
  cVar1 = ((int (*)())FUN_00154696)(param_1,param_2,param_3);
  if (cVar1 != '\0') {
    return 1;
  }
  return uVar2;
}

/* FUN_00156ad8 @ 0x156ad8 (1415 bytes) */
int FUN_00156ad8(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int local_68;
  int local_60;
  int local_5c;
  uint local_54;
  int local_50;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  uVar1 = *(undefined4 *)(param_2 + 8);
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (*(int *)(param_1[0x22] + 8) != 0x13) {
    return 0;
  }
  if ((char)param_1[0x48] != '\0') {
    return 0;
  }
  if (param_1[0x49] != 0) {
    return 0;
  }
  iVar4 = FUN_0010b180(param_1,1);
  iVar5 = FUN_0010b180(param_1,2);
  if ((((*(int *)(*(int *)(iVar4 + 0x88) + 8) == 0x1c) ||
       (*(int *)(*(int *)(iVar4 + 0x88) + 8) == 0x1d)) && (*(char *)(iVar4 + 0x120) == '\0')) &&
     (cVar3 = FUN_000f6cc2(param_1,1), cVar3 != '\0')) {
    iVar7 = FUN_0010b0f4(param_1,2);
    cVar3 = FUN_000f5672(*(undefined4 *)(iVar7 + 0x10));
    if ((cVar3 != '\0') && (cVar3 = FUN_0010a62e(iVar4,param_2), cVar3 != '\0')) {
      local_68 = 1;
      goto LAB_00156be1;
    }
  }
  if ((*(int *)(*(int *)(iVar5 + 0x88) + 8) != 0x1c) &&
     (*(int *)(*(int *)(iVar5 + 0x88) + 8) != 0x1d)) {
    return 0;
  }
  if (*(char *)(iVar5 + 0x120) != '\0') {
    return 0;
  }
  cVar3 = FUN_000f6cc2(param_1,2);
  if (cVar3 == '\0') {
    return 0;
  }
  iVar4 = FUN_0010b0f4(param_1,1);
  cVar3 = FUN_000f5672(*(undefined4 *)(iVar4 + 0x10));
  if (cVar3 == '\0') {
    return 0;
  }
  cVar3 = FUN_0010a62e(iVar5,param_2);
  if (cVar3 == '\0') {
    return 0;
  }
  local_68 = 2;
LAB_00156be1:
  iVar4 = FUN_0010b180(param_1,local_68);
  local_3c = 0x3f800000;
  local_38 = 0x3f800000;
  local_34 = 0x3f800000;
  local_30 = 0x3f800000;
  cVar3 = FUN_000f7dda(iVar4,1,DAT_001cc6d0,&local_3c);
  if (cVar3 == '\0') {
    cVar3 = FUN_000f7dda(iVar4,2,DAT_001cc6d0,&local_3c);
    if (cVar3 == '\0') {
      return 0;
    }
    local_5c = 1;
    local_60 = 2;
  }
  else {
    local_5c = 2;
    local_60 = 1;
  }
  uVar2 = *(uint *)(iVar4 + 0xa0 + local_5c * 0x18);
  if (((uVar2 & 1) == 0) && ((uVar2 & 2) == 0)) {
    *(int *)(param_2 + 0x1f0) = *(int *)(param_2 + 0x1f0) + 1;
    iVar5 = FUN_0010b180(iVar4,local_60);
    *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + -1;
    if (local_68 == 1) {
      uVar9 = 2;
    }
    else {
      uVar9 = 1;
    }
    uVar6 = FUN_0010b180(param_1,uVar9);
    iVar5 = FUN_0010b0f4(param_1,0);
    iVar5 = *(int *)(iVar5 + 0x10);
    iVar7 = FUN_0010b0f4(param_1,uVar9);
    local_20[0] = *(undefined4 *)(iVar7 + 0x10);
    iVar7 = 0;
    do {
      if (*(char *)((int)local_20 + iVar7) != '\x04') {
        local_54 = (uint)*(byte *)((int)local_20 + iVar7);
        goto LAB_00156ce2;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 != 4);
    local_54 = 0xffffffff;
LAB_00156ce2:
    if ((*(byte *)((int)param_1 + 0x15) & 2) == 0) {
      local_50 = 0;
    }
    else {
      local_50 = FUN_0010b180(param_1,param_1[0x21]);
    }
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    FUN_00109d1c(param_1,&local_2c,0xffffffff);
    iVar7 = param_1[0x53];
    iVar8 = param_1[1];
    FUN_001a7d72(param_1);
    FUN_0010d8fc(param_1,*(undefined4 *)(*(int *)(iVar4 + 0x88) + 8),*(undefined4 *)(param_2 + 8));
    FUN_00109d48(param_1,&local_2c);
    FUN_000e9596(*(undefined4 *)(iVar8 + 0x158),iVar8,param_1);
    param_1[0x53] = iVar7;
    param_1[0x49] = *(int *)(iVar4 + 0x124);
    *(undefined1 *)(param_1 + 0x48) = *(undefined1 *)(iVar4 + 0x120);
    param_1[0x25] = iVar7;
    param_1[0x26] = 0;
    param_1[0x27] = iVar5;
    FUN_0010ba02(param_1,local_60,uVar6,0,uVar1);
    iVar5 = *(int *)(PTR_DAT_00213485 + local_54 * 4);
    if (local_60 == 0) {
      param_1[0x27] = iVar5;
    }
    else {
      iVar7 = FUN_0010b0f4(param_1,local_60);
      *(int *)(iVar7 + 0x10) = iVar5;
    }
    if (*(int *)(param_1[0x22] + 8) == 0x1c) {
      (**(code **)(*param_1 + 0x88))(param_1,local_60,3,4);
    }
    iVar7 = FUN_0010b180(iVar4,local_5c);
    FUN_0010ba02(param_1,local_5c,iVar7,0,uVar1);
    iVar5 = FUN_0010b0f4(iVar4,local_5c);
    iVar5 = *(int *)(iVar5 + 0x10);
    if (local_5c == 0) {
      param_1[0x27] = iVar5;
    }
    else {
      iVar8 = FUN_0010b0f4(param_1,local_5c);
      *(int *)(iVar8 + 0x10) = iVar5;
    }
    iVar5 = local_5c * 0x18 + 0x80;
    FUN_00109c0e(param_1 + local_5c * 6 + 0x23,1,*(byte *)(iVar4 + 0x20 + iVar5) & 1);
    FUN_00109c0e(param_1 + local_5c * 6 + 0x23,2,*(uint *)(iVar4 + 0x20 + iVar5) >> 1 & 1);
    if (local_50 != 0) {
      FUN_0010c18e(param_1,local_50,0,uVar1);
    }
    if (*(int *)(param_2 + 0x46c) < *(int *)(iVar7 + 0x160)) {
      *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
    }
    else {
      *(int *)(iVar7 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
    }
    FUN_0010b3fe(iVar4,uVar1);
  }
  return 0;
}

/* FUN_00157068 @ 0x157068 (2646 bytes) */
int FUN_00157068(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  uint uVar17;
  int iVar18;
  undefined4 uVar19;
  undefined4 local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  int local_dc;
  int local_c0;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  if ((*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x12) && (*(char *)(param_1 + 0x120) == '\0')) {
    iVar10 = FUN_0010b180(param_1,1);
    local_f8 = FUN_0010b180(param_1,2);
    iVar18 = *(int *)(*(int *)(iVar10 + 0x88) + 8);
    iVar12 = *(int *)(*(int *)(local_f8 + 0x88) + 8);
    iVar11 = FUN_0010b180(iVar10,3);
    local_f4 = FUN_0010b180(local_f8,3);
    if (((((*(uint *)(param_1 + 0xb8) & 1) == 0) &&
         ((((*(uint *)(param_1 + 0xb8) & 2) == 0 && (cVar9 = FUN_000f6cc2(param_1,1), cVar9 != '\0')
           ) && (iVar18 == 0x14)))) &&
        ((((cVar9 = FUN_0010a62e(iVar10,param_2), cVar9 != '\0' &&
           (*(char *)(iVar10 + 0x120) == '\0')) && (*(int *)(iVar10 + 0x124) == 0)) &&
         (((*(byte *)(iVar10 + 0xe8) & 2) == 0 && (cVar9 = FUN_000f6cc2(iVar10,3), cVar9 != '\0'))))
        )) && ((*(int *)(*(int *)(iVar11 + 0x88) + 8) == 0x13 &&
               (((cVar9 = FUN_0010a62e(iVar11,param_2), cVar9 != '\0' &&
                 (*(char *)(iVar11 + 0x120) == '\0')) &&
                (*(int *)(iVar11 + 0x124) == *(int *)(param_1 + 0x124))))))) {
      local_100 = 1;
      uVar19 = 2;
      local_fc = local_f8;
      local_f8 = iVar10;
      local_f4 = iVar11;
    }
    else {
      if ((*(uint *)(param_1 + 0xd0) & 1) != 0) {
        return 0;
      }
      if ((*(uint *)(param_1 + 0xd0) & 2) != 0) {
        return 0;
      }
      cVar9 = FUN_000f6cc2(param_1,2);
      if (cVar9 == '\0') {
        return 0;
      }
      if (iVar12 != 0x14) {
        return 0;
      }
      cVar9 = FUN_0010a62e(local_f8,param_2);
      if (cVar9 == '\0') {
        return 0;
      }
      if (*(char *)(local_f8 + 0x120) != '\0') {
        return 0;
      }
      if (*(int *)(local_f8 + 0x124) != 0) {
        return 0;
      }
      if ((*(byte *)(local_f8 + 0xe8) & 2) != 0) {
        return 0;
      }
      cVar9 = FUN_000f6cc2(local_f8,3);
      if (cVar9 == '\0') {
        return 0;
      }
      if (*(int *)(*(int *)(local_f4 + 0x88) + 8) != 0x13) {
        return 0;
      }
      cVar9 = FUN_0010a62e(local_f4,param_2);
      if (cVar9 == '\0') {
        return 0;
      }
      if (*(char *)(local_f4 + 0x120) != '\0') {
        return 0;
      }
      if (*(int *)(local_f4 + 0x124) != *(int *)(param_1 + 0x124)) {
        return 0;
      }
      local_100 = 2;
      uVar19 = 1;
      local_fc = iVar10;
    }
    cVar9 = FUN_0010a4c8(local_fc,local_f4);
    if (cVar9 != '\0') {
      *(int *)(param_2 + 0x1dc) = *(int *)(param_2 + 0x1dc) + 1;
      iVar12 = *(int *)(local_f4 + 0x160) - *(int *)(param_2 + 0x46c);
      iVar18 = 0;
      if (-1 < iVar12) {
        iVar18 = iVar12;
      }
      uVar1 = *(undefined1 *)(local_f4 + 0x120);
      uVar4 = *(undefined4 *)(local_f4 + 0x124);
      FUN_0010b0f4(local_f4,0);
      if ((*(byte *)(local_f4 + 0x15) & 2) == 0) {
        local_dc = 0;
      }
      else {
        local_dc = FUN_0010b180(local_f4,*(undefined4 *)(local_f4 + 0x84));
      }
      uVar5 = *(undefined4 *)(local_f4 + 0x98);
      uVar13 = FUN_0010b180(local_f4,1);
      uVar14 = FUN_0010b180(local_f4,2);
      local_a0 = 0;
      local_9c = 0;
      local_8c = 0;
      local_58 = 0;
      local_54 = 0;
      local_44 = 0;
      uVar15 = FUN_0010b0f4(local_f4,1);
      FUN_0010a40a(&local_a0,uVar15);
      uVar15 = FUN_0010b0f4(local_f4,2);
      FUN_0010a40a(&local_58,uVar15);
      uVar6 = *(uint *)(local_f8 + 0xe8);
      iVar10 = *(int *)(param_1 + 0x160) - *(int *)(param_2 + 0x46c);
      iVar12 = 0;
      if (-1 < iVar10) {
        iVar12 = iVar10;
      }
      uVar2 = *(undefined1 *)(param_1 + 0x120);
      uVar15 = *(undefined4 *)(param_1 + 0x124);
      iVar10 = FUN_0010b0f4(param_1,0);
      uVar7 = *(undefined4 *)(iVar10 + 0x10);
      if ((*(byte *)(param_1 + 0x15) & 2) == 0) {
        local_c0 = 0;
      }
      else {
        local_c0 = FUN_0010b180(param_1,*(undefined4 *)(param_1 + 0x84));
      }
      uVar8 = *(undefined4 *)(param_1 + 0x98);
      local_70 = 0;
      local_6c = 0;
      local_5c = 0;
      local_88 = 0;
      local_84 = 0;
      local_74 = 0;
      uVar16 = FUN_0010b0f4(param_1,local_100);
      FUN_0010a40a(&local_70,uVar16);
      uVar16 = FUN_0010b0f4(param_1,uVar19);
      FUN_0010a40a(&local_88,uVar16);
      local_40 = DAT_001cc5a4;
      local_3c = local_40;
      local_38 = local_40;
      local_34 = local_40;
      iVar10 = FUN_0010b0f4(local_f4,1);
      local_24 = *(undefined4 *)(iVar10 + 0x10);
      iVar10 = FUN_0010b0f4(local_f4,2);
      local_28 = *(undefined4 *)(iVar10 + 0x10);
      iVar10 = FUN_0010b0f4(local_f8,3);
      local_2c = *(undefined4 *)(iVar10 + 0x10);
      iVar10 = FUN_0010b0f4(param_1,uVar19);
      local_30 = *(undefined4 *)(iVar10 + 0x10);
      iVar10 = FUN_0010b0f4(param_1,local_100);
      local_20[0] = *(undefined4 *)(iVar10 + 0x10);
      iVar10 = 1;
      do {
        cVar9 = *(char *)((int)&local_34 + iVar10 + 3);
        if (cVar9 != '\x04') {
          bVar3 = *(byte *)((int)local_20 + iVar10 + -1);
          uVar17 = (uint)bVar3;
          *(undefined1 *)((int)&local_38 + uVar17) =
               *(undefined1 *)((int)local_20 + (*(byte *)((int)&local_2c + uVar17) - 4));
          *(undefined1 *)((int)&local_3c + uVar17) =
               *(undefined1 *)((int)&local_28 + (uint)*(byte *)((int)&local_2c + uVar17));
          *(char *)((int)&local_34 + uVar17) = cVar9;
          *(byte *)((int)&local_40 + uVar17) = bVar3;
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 != 5);
      iVar10 = FUN_0010b0f4(local_f8,0);
      uVar19 = *(undefined4 *)(iVar10 + 0x10);
      iVar10 = *(int *)(local_f4 + 4);
      FUN_001a7d72(local_f4);
      FUN_0010da48(local_f4,0x14,*(undefined4 *)(param_2 + 8));
      FUN_000e9596(*(undefined4 *)(iVar10 + 0x158),iVar10,local_f4);
      *(undefined1 *)(local_f4 + 0x120) = uVar1;
      *(undefined4 *)(local_f4 + 0x124) = uVar4;
      *(undefined4 *)(local_f4 + 0x9c) = uVar19;
      *(int *)(local_f4 + 0x160) = iVar18 + *(int *)(param_2 + 0x46c);
      *(undefined4 *)(local_f4 + 0x94) = *(undefined4 *)(local_f4 + 0x14c);
      *(undefined4 *)(local_f4 + 0x98) = uVar5;
      FUN_0010ba02(local_f4,1,uVar13,0,*(undefined4 *)(param_2 + 8));
      uVar19 = FUN_0010b0f4(local_f4,1);
      FUN_0010a40a(uVar19,&local_a0);
      uVar19 = local_38;
      iVar18 = FUN_0010b0f4(local_f4,1);
      *(undefined4 *)(iVar18 + 0x10) = uVar19;
      FUN_0010ba02(local_f4,2,uVar14,0,*(undefined4 *)(param_2 + 8));
      uVar19 = FUN_0010b0f4(local_f4,2);
      FUN_0010a40a(uVar19,&local_58);
      uVar19 = local_3c;
      iVar18 = FUN_0010b0f4(local_f4,2);
      *(undefined4 *)(iVar18 + 0x10) = uVar19;
      FUN_0010ba02(local_f4,3,local_fc,0,*(undefined4 *)(param_2 + 8));
      uVar19 = FUN_0010b0f4(local_f4,3);
      FUN_0010a40a(uVar19,&local_88);
      uVar19 = local_34;
      iVar18 = FUN_0010b0f4(local_f4,3);
      *(undefined4 *)(iVar18 + 0x10) = uVar19;
      if ((uVar6 & 1) != 0) {
        FUN_00109c0e(local_f4 + 0xd4,1,(*(uint *)(local_f4 + 0xe8) ^ 1) & 1);
      }
      uVar19 = local_40;
      iVar18 = FUN_0010b0f4(local_f8,3);
      *(undefined4 *)(iVar18 + 0x10) = uVar19;
      if (local_dc != 0) {
        FUN_0010c18e(local_f4,local_dc,0,*(undefined4 *)(param_2 + 8));
      }
      iVar18 = *(int *)(param_1 + 4);
      FUN_001a7d72(param_1);
      FUN_0010db52(param_1,0x31,*(undefined4 *)(param_2 + 8));
      FUN_000e9596(*(undefined4 *)(iVar18 + 0x158),iVar18,param_1);
      *(undefined1 *)(param_1 + 0x120) = uVar2;
      *(undefined4 *)(param_1 + 0x124) = uVar15;
      *(undefined4 *)(param_1 + 0x9c) = uVar7;
      *(int *)(param_1 + 0x160) = iVar12 + *(int *)(param_2 + 0x46c);
      *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x14c);
      *(undefined4 *)(param_1 + 0x98) = uVar8;
      FUN_0010ba02(param_1,1,local_f8,0,*(undefined4 *)(param_2 + 8));
      uVar19 = FUN_0010b0f4(param_1,1);
      FUN_0010a40a(uVar19,&local_70);
      if (local_c0 != 0) {
        FUN_0010c18e(param_1,local_c0,0,*(undefined4 *)(param_2 + 8));
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_00157ac6 @ 0x157ac6 (2066 bytes) */
int FUN_00157ac6(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char cVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int iVar17;
  undefined4 local_b8;
  undefined4 local_ac;
  int local_a8;
  int local_a4;
  int local_8c;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_20;
  
  cVar10 = ((int (*)())FUN_0015013c)(param_1,param_2,param_4);
  if (cVar10 == '\0') {
LAB_00157b04:
    uVar11 = 0;
  }
  else {
    local_a4 = FUN_0010b180(param_1,1);
    iVar12 = FUN_0010b180(param_1,2);
    iVar17 = *(int *)(*(int *)(iVar12 + 0x88) + 8);
    if (((((*(int *)(*(int *)(local_a4 + 0x88) + 8) == 0x13) &&
          ((*(byte *)(param_1 + 0xb8) & 2) == 0)) &&
         (cVar10 = FUN_000f6cc2(param_1,1), cVar10 != '\0')) &&
        ((*(char *)(local_a4 + 0x120) == '\0' && (*(int *)(local_a4 + 0x124) == 0)))) &&
       ((param_4 == '\0' || (cVar10 = FUN_0010a62e(local_a4,param_2), cVar10 != '\0')))) {
      iVar17 = 1;
      local_ac = 2;
      local_a8 = iVar12;
    }
    else {
      if ((((iVar17 != 0x13) || ((*(byte *)(param_1 + 0xd0) & 2) != 0)) ||
          ((cVar10 = FUN_000f6cc2(param_1,2), cVar10 == '\0' ||
           ((*(char *)(iVar12 + 0x120) != '\0' || (*(int *)(iVar12 + 0x124) != 0)))))) ||
         ((param_4 != '\0' && (cVar10 = FUN_0010a62e(iVar12,param_2), cVar10 == '\0'))))
      goto LAB_00157b04;
      iVar17 = 2;
      local_ac = 1;
      local_a8 = local_a4;
      local_a4 = iVar12;
    }
    *(int *)(param_2 + 0x1d4) = *(int *)(param_2 + 0x1d4) + 1;
    iVar12 = *(int *)(param_1 + 0x160) - *(int *)(param_2 + 0x46c);
    if (iVar12 < 0) {
      iVar12 = 0;
    }
    uVar11 = *(undefined4 *)(param_1 + 0x10);
    uVar2 = *(undefined4 *)(param_1 + 0x14c);
    uVar3 = *(undefined4 *)(param_1 + 0x98);
    uVar1 = *(undefined1 *)(param_1 + 0x120);
    uVar4 = *(undefined4 *)(param_1 + 0x124);
    iVar13 = FUN_0010b0f4(param_1,0);
    uVar5 = *(undefined4 *)(iVar13 + 0x10);
    if ((*(byte *)(param_1 + 0x15) & 2) == 0) {
      local_8c = 0;
    }
    else {
      local_8c = FUN_0010b180(param_1,*(undefined4 *)(param_1 + 0x84));
    }
    local_b8 = DAT_001cc5a0;
    if (local_8c != 0) {
      iVar13 = FUN_0010b0f4(param_1,*(undefined4 *)(param_1 + 0x84));
      local_b8 = *(undefined4 *)(iVar13 + 0x10);
    }
    iVar13 = FUN_0010b0f4(param_1,iVar17);
    uVar6 = *(undefined4 *)(iVar13 + 0x10);
    uVar7 = *(uint *)(param_1 + 0xa0 + iVar17 * 0x18);
    uVar14 = FUN_0010b180(local_a4,1);
    uVar15 = FUN_0010b180(local_a4,2);
    iVar17 = FUN_0010b0f4(local_a4,1);
    uVar8 = *(undefined4 *)(iVar17 + 0x10);
    iVar17 = FUN_0010b0f4(local_a4,2);
    uVar9 = *(undefined4 *)(iVar17 + 0x10);
    local_34 = 0;
    local_30 = 0;
    local_20 = 0;
    local_4c = 0;
    local_48 = 0;
    local_38 = 0;
    local_64 = 0;
    local_60 = 0;
    local_50 = 0;
    uVar16 = FUN_0010b0f4(local_a4,1);
    FUN_0010a40a(&local_34,uVar16);
    uVar16 = FUN_0010b0f4(local_a4,2);
    FUN_0010a40a(&local_4c,uVar16);
    uVar16 = FUN_0010b0f4(param_1,local_ac);
    FUN_0010a40a(&local_64,uVar16);
    if (0 < *(int *)(param_1 + 0x84)) {
      iVar17 = 1;
      do {
        iVar13 = FUN_0010b180(param_1,iVar17);
        *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + -1;
        if (param_3 != '\0') {
          iVar13 = FUN_0010b180(param_1,iVar17);
          FUN_001a805e(*(undefined4 *)(iVar13 + 0x10),param_1);
        }
        iVar17 = iVar17 + 1;
      } while (iVar17 <= *(int *)(param_1 + 0x84));
    }
    iVar17 = *(int *)(param_1 + 4);
    FUN_001a7d72(param_1);
    FUN_0010da48(param_1,0x14,*(undefined4 *)(param_2 + 8));
    FUN_000e9596(*(undefined4 *)(iVar17 + 0x158),iVar17,param_1);
    *(int *)(param_1 + 0x160) = iVar12 + *(int *)(param_2 + 0x46c);
    *(undefined4 *)(param_1 + 0x10) = uVar11;
    *(undefined1 *)(param_1 + 0x120) = uVar1;
    *(undefined4 *)(param_1 + 0x124) = uVar4;
    *(undefined4 *)(param_1 + 0x9c) = uVar5;
    *(undefined4 *)(param_1 + 0x94) = uVar2;
    *(undefined4 *)(param_1 + 0x98) = uVar3;
    uVar11 = FUN_0010b0f4(param_1,1);
    FUN_0010a474(uVar11,&local_34);
    iVar17 = FUN_00110110(uVar14,param_2,param_3);
    FUN_0010ba02(param_1,1,iVar17,param_3,*(undefined4 *)(param_2 + 8));
    if (param_3 == '\0') {
      if (*(int *)(param_2 + 0x46c) < *(int *)(iVar17 + 0x160)) {
        *(int *)(iVar17 + 0x160) = *(int *)(iVar17 + 0x160) + 1;
      }
      else {
        *(int *)(iVar17 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
      }
    }
    uVar11 = FUN_000f5610(uVar8,uVar6);
    iVar17 = FUN_0010b0f4(param_1,1);
    *(undefined4 *)(iVar17 + 0x10) = uVar11;
    if ((uVar7 & 1) != 0) {
      FUN_00109c0e(param_1 + 0xa4,1,(*(uint *)(param_1 + 0xb8) ^ 1) & 1);
    }
    uVar11 = FUN_0010b0f4(param_1,2);
    FUN_0010a474(uVar11,&local_4c);
    iVar17 = FUN_00110110(uVar15,param_2,param_3);
    FUN_0010ba02(param_1,2,iVar17,param_3,*(undefined4 *)(param_2 + 8));
    if (param_3 == '\0') {
      if (*(int *)(param_2 + 0x46c) < *(int *)(iVar17 + 0x160)) {
        *(int *)(iVar17 + 0x160) = *(int *)(iVar17 + 0x160) + 1;
      }
      else {
        *(int *)(iVar17 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
      }
    }
    uVar11 = FUN_000f5610(uVar9,uVar6);
    iVar17 = FUN_0010b0f4(param_1,2);
    *(undefined4 *)(iVar17 + 0x10) = uVar11;
    uVar11 = FUN_0010b0f4(param_1,3);
    FUN_0010a474(uVar11,&local_64);
    FUN_0010ba02(param_1,3,local_a8,param_3,*(undefined4 *)(param_2 + 8));
    if (param_3 == '\0') {
      if (*(int *)(param_2 + 0x46c) < *(int *)(local_a8 + 0x160)) {
        *(int *)(local_a8 + 0x160) = *(int *)(local_a8 + 0x160) + 1;
      }
      else {
        *(int *)(local_a8 + 0x160) = *(int *)(param_2 + 0x46c) + 1;
      }
    }
    if (local_8c != 0) {
      FUN_0010c18e(param_1,local_8c,param_3,*(undefined4 *)(param_2 + 8));
      iVar17 = FUN_0010b0f4(param_1,*(undefined4 *)(param_1 + 0x84));
      *(undefined4 *)(iVar17 + 0x10) = local_b8;
      if (param_3 == '\0') {
        if (*(int *)(param_2 + 0x46c) < *(int *)(local_8c + 0x160)) {
          *(int *)(local_8c + 0x160) = *(int *)(local_8c + 0x160) + 1;
        }
        else {
          *(int *)(local_8c + 0x160) = *(int *)(param_2 + 0x46c) + 1;
        }
      }
    }
    FUN_0010b1fe(local_a4,*(undefined4 *)(param_2 + 8),param_3);
    uVar11 = 1;
  }
  return uVar11;
}

