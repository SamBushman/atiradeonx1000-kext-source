#include "decls.h"

/* FUN_001486e8 @ 0x1486e8 (664 bytes) */
int FUN_001486e8(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  int *piVar13;
  undefined4 local_4c;
  undefined4 local_48 [8];
  
  if ((param_1[5] & 2U) != 0) {
    iVar3 = FUN_001054ec(param_1,0);
    uVar2 = *(uint *)(iVar3 + 0x10);
    iVar3 = FUN_000f2e18(uVar2);
    if ((iVar3 != 0) && (iVar3 = FUN_000e07dc(*(undefined4 *)(param_2 + 8),0x31), iVar3 != 0)) {
      iVar10 = param_1[0x26];
      iVar3 = param_1[0x25];
      piVar4 = (int *)FUN_00105594(param_1,1);
      for (iVar9 = 4;
          ((iVar7 = (**(code **)(*piVar4 + 0x30))(piVar4), iVar7 == 0 &&
           (iVar7 = (**(code **)(*piVar4 + 0x40))(piVar4), iVar7 == 0)) && (iVar9 != 0));
          iVar9 = iVar9 + -1) {
        puVar12 = *(uint **)(param_2 + 0x3c4);
        uVar11 = 0;
        uVar8 = puVar12[1];
        if (0 < (int)uVar8) {
          do {
            if (uVar11 < *puVar12) {
              if (uVar8 <= uVar11) {
                _memset((void *)(uVar8 * 4 + puVar12[2]),0,(uVar11 - uVar8) * 4 + 4);
                puVar12[1] = uVar11 + 1;
              }
              puVar5 = (undefined4 *)(uVar11 * 4 + puVar12[2]);
            }
            else {
              puVar5 = (undefined4 *)FUN_0019423c(puVar12,uVar11);
            }
            piVar13 = (int *)*puVar5;
            if (((param_1 != piVar13) && (iVar10 == piVar13[0x26])) &&
               ((iVar3 == piVar13[0x25] &&
                (piVar6 = (int *)FUN_00105594(piVar13,1), piVar4 == piVar6)))) {
              *(int *)(param_2 + 0x168) = *(int *)(param_2 + 0x168) + 1;
              iVar3 = FUN_001054ec(piVar13,0);
              uVar8 = *(uint *)(iVar3 + 0x10);
              uVar2 = (uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
                      uVar2 >> 0x18) &
                      (uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 |
                      uVar8 >> 0x18);
              param_1[0x27] =
                   uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
              iVar3 = FUN_001054ec(param_1,1);
              local_4c = *(undefined4 *)(iVar3 + 0x10);
              iVar9 = FUN_001054ec(piVar13,1);
              iVar3 = 0;
              local_48[0] = *(undefined4 *)(iVar9 + 0x10);
              iVar9 = 4;
              do {
                if (*(char *)((int)local_48 + iVar3 + -4) == '\x04') {
                  *(undefined1 *)((int)local_48 + iVar3 + -4) =
                       *(undefined1 *)((int)local_48 + iVar3);
                }
                uVar1 = local_4c;
                iVar3 = iVar3 + 1;
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
              iVar3 = FUN_001054ec(param_1,1);
              *(undefined4 *)(iVar3 + 0x10) = uVar1;
              (**(code **)(*piVar13 + 0xc))(piVar13,0,*(undefined4 *)(param_2 + 8));
              piVar4[0x58] = piVar4[0x58] + -1;
              return;
            }
            puVar12 = *(uint **)(param_2 + 0x3c4);
            uVar11 = uVar11 + 1;
            uVar8 = puVar12[1];
          } while ((int)uVar11 < (int)uVar8);
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

/* FUN_00148980 @ 0x148980 (1036 bytes) */
int FUN_00148980(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 local_58 [4];
  int local_48 [5];
  
  iVar2 = FUN_000e07dc(*(undefined4 *)(param_2 + 8),0x30);
  if ((((iVar2 != 0) && ((*(uint *)(param_1 + 0xb8) & 1) == 0)) &&
      ((*(uint *)(param_1 + 0xb8) & 2) == 0)) && ((*(uint *)(param_1 + 0x14) & 0x200) == 0)) {
    iVar2 = FUN_001054ec(param_1,0);
    iVar10 = *(int *)(iVar2 + 0x10);
    iVar2 = FUN_001054ec(param_1,1);
    uVar11 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = FUN_000f2c5c(uVar11);
    if (iVar2 != 0) {
      piVar3 = (int *)FUN_00105594(param_1,1);
      iVar2 = FUN_00113420(*(undefined4 *)(piVar3[0x22] + 8),*(undefined4 *)(param_2 + 8));
      if (((iVar2 == 0) && (iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3), iVar2 != 0)) &&
         ((piVar3[5] & 0x200U) == 0)) {
        iVar2 = FUN_001054ec(piVar3,0);
        iVar2 = FUN_000f3824(*(undefined4 *)(iVar2 + 0x10));
        if ((iVar2 == 0) && (iVar2 = FUN_001467e8(piVar3,param_2), iVar2 != 0)) {
          iVar8 = *(int *)(param_2 + 0x478);
          *(int *)(param_2 + 0x174) = *(int *)(param_2 + 0x174) + 1;
          iVar2 = FUN_0010497c(piVar3,param_2);
          piVar4 = piVar3;
          if (iVar2 == 0) {
            iVar9 = iVar8 + 1;
            piVar4 = (int *)FUN_0010445c(piVar3,*(undefined4 *)(param_2 + 8),0);
            FUN_000e7738(piVar3[0x56],piVar3,piVar4);
            iVar12 = piVar4[0x53];
            piVar3[0x58] = piVar3[0x58] + -1;
            piVar4[0x58] = iVar9;
            iVar2 = FUN_001054ec(piVar4,0);
            *(int *)(iVar2 + 8) = iVar12;
            for (iVar2 = 1; iVar12 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar2 <= iVar12;
                iVar2 = iVar2 + 1) {
              piVar7 = (int *)FUN_00105594(piVar4,iVar2);
              iVar12 = (**(code **)(*piVar7 + 0x5c))();
              if (iVar12 == 0) {
                if (iVar8 < piVar7[0x58]) {
                  piVar7[0x58] = piVar7[0x58] + 1;
                }
                else {
                  piVar7[0x58] = iVar9;
                }
              }
              else {
                iVar12 = FUN_0010445c(piVar7,*(undefined4 *)(param_2 + 8),0);
                uVar13 = *(undefined4 *)(iVar12 + 0x14c);
                iVar5 = FUN_001054ec(iVar12,0);
                *(undefined4 *)(iVar5 + 8) = uVar13;
                *(int *)(iVar12 + 0x160) = iVar9;
                FUN_00106004(piVar4,iVar2,iVar12,0,*(undefined4 *)(param_2 + 8));
                FUN_000e7700(piVar7[0x56],piVar7,iVar12);
                if (0 < *(int *)(iVar12 + 0x84)) {
                  iVar5 = 1;
                  do {
                    iVar6 = FUN_00105594(iVar12,iVar5);
                    if (iVar8 < *(int *)(iVar6 + 0x160)) {
                      *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar6 + 0x160) = iVar9;
                    }
                    iVar5 = iVar5 + 1;
                  } while (iVar5 <= *(int *)(iVar12 + 0x84));
                }
              }
            }
          }
          piVar4[0x27] = iVar10;
          for (iVar2 = 1; iVar10 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar2 <= iVar10;
              iVar2 = iVar2 + 1) {
            iVar10 = FUN_001054ec(piVar3,iVar2);
            FUN_000f2bdc(local_48,*(undefined4 *)(iVar10 + 0x10),uVar11);
            iVar10 = local_48[0];
            if (iVar2 == 0) {
              piVar4[0x27] = local_48[0];
            }
            else {
              iVar8 = FUN_001054ec(piVar4,iVar2);
              *(int *)(iVar8 + 0x10) = iVar10;
            }
          }
          iVar2 = FUN_0010497c(param_1,param_2);
          if (iVar2 != 0) {
            if (*(int *)(param_1 + 0x120) != 0) {
              piVar4[0x48] = 1;
              *(undefined4 *)(param_1 + 0x120) = 0;
            }
            piVar7 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
            iVar10 = *(int *)(param_1 + 0x124) + piVar3[0x49];
            iVar2 = (**(code **)(*piVar7 + 0xfc))(piVar7,iVar10,param_1);
            if (iVar2 != 0) {
              piVar4[0x49] = iVar10;
              *(undefined4 *)(param_1 + 0x124) = 0;
            }
          }
          iVar2 = 0;
          local_58[0] = DAT_001b0050;
          do {
            iVar10 = FUN_001054ec(param_1,0);
            if (*(char *)(iVar2 + iVar10 + 0x10) != '\x01') {
              *(undefined1 *)((int)local_58 + iVar2) = *(undefined1 *)((int)&DAT_001b004c + iVar2);
            }
            uVar11 = local_58[0];
            bVar1 = iVar2 != 3;
            iVar2 = iVar2 + 1;
          } while (bVar1);
          iVar2 = FUN_001054ec(param_1,1);
          *(undefined4 *)(iVar2 + 0x10) = uVar11;
          FUN_00106004(param_1,1,piVar4,0,*(undefined4 *)(param_2 + 8));
          return;
        }
      }
    }
  }
  return;
}

/* FUN_00148d8c @ 0x148d8c (1872 bytes) */
int FUN_00148d8c(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int *local_4c [7];
  
  iVar6 = FUN_001054ec(param_1,1);
  local_58 = *(undefined4 *)(iVar6 + 0x10);
  iVar6 = FUN_001054ec(param_1,0);
  local_54 = *(undefined4 *)(iVar6 + 0x10);
  piVar7 = (int *)FUN_00105594(param_1,1);
  if (((param_1[0x2e] & 1U) != 0) || ((param_1[0x2e] & 2U) != 0)) {
    iVar6 = 0;
    local_4c[0] = DAT_001b0180;
    local_4c[1] = (int *)DAT_001b0184;
    local_4c[2] = (int *)DAT_001b0188;
    local_4c[3] = (int *)DAT_001b018c;
    do {
      if (*(char *)((int)&local_54 + iVar6) == '\0') {
        iVar8 = (**(code **)(*piVar7 + 0x24))(piVar7);
        if ((((iVar8 == 0) || (iVar8 = FUN_0010497c(piVar7,param_2), iVar8 == 0)) ||
            (piVar7[0x48] != 0)) || (iVar8 = FUN_00147398(piVar7), iVar8 == 0)) {
          return 0;
        }
        iVar8 = FUN_001054ec(piVar7,0);
        bVar3 = *(byte *)((int)&local_58 + iVar6);
        local_50 = *(undefined4 *)(iVar8 + 0x10);
        cVar2 = *(char *)((int)&local_50 + (uint)bVar3);
        piVar9 = piVar7;
        while (cVar2 == '\x01') {
          piVar9 = (int *)FUN_00105594(piVar9,piVar9[0x21]);
          iVar8 = (**(code **)(*piVar9 + 0x24))();
          if (iVar8 == 0) {
            return 0;
          }
          iVar8 = FUN_0010497c(piVar9,param_2);
          if (iVar8 == 0) {
            return 0;
          }
          if (piVar9[0x48] != 0) {
            return 0;
          }
          iVar8 = FUN_00147398(piVar9);
          if (iVar8 == 0) {
            return 0;
          }
          iVar8 = FUN_001054ec(piVar9,0);
          local_50 = *(undefined4 *)(iVar8 + 0x10);
          cVar2 = *(char *)((int)&local_50 + (uint)bVar3);
        }
        if (iVar6 < 1) {
LAB_00148f68:
          local_4c[iVar6] = piVar9;
        }
        else if (local_4c[0] != piVar9) {
          iVar12 = 0;
          iVar8 = iVar6;
          do {
            iVar12 = iVar12 + 1;
            iVar8 = iVar8 + -1;
            if (iVar8 == 0) goto LAB_00148f68;
          } while (local_4c[iVar12] != piVar9);
        }
      }
      bVar1 = iVar6 != 3;
      iVar6 = iVar6 + 1;
    } while (bVar1);
    iVar6 = 0;
    uVar4 = param_1[0x2e] & 1;
    uVar10 = (uint)param_1[0x2e] >> 1 & 1;
    do {
      if ((*(char *)((int)&local_54 + iVar6) == '\0') &&
         (piVar9 = local_4c[iVar6], piVar9 != (int *)0x0)) {
        *(int *)(param_2 + 0x16c) = *(int *)(param_2 + 0x16c) + 1;
        iVar12 = *(int *)(piVar9[0x22] + 8);
        iVar8 = (**(code **)(*piVar9 + 0x14))(piVar9);
        if (iVar8 == 1) {
          if (uVar10 == 0) {
LAB_001490f4:
            if (uVar4 != 0) {
              if ((piVar9[0x2e] & 1U) == 0) {
                iVar8 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,piVar9,1);
                if (iVar8 == 0) {
                  FUN_00103d50(piVar9 + 0x29,1,1);
                }
              }
              else {
                FUN_00103d50(piVar9 + 0x29,1,0);
              }
            }
          }
          else {
            if ((uVar4 != 0) || (iVar8 = FUN_000f5e8c(piVar9,1), iVar8 == 0)) {
              FUN_00103d50(piVar9 + 0x29,2,1);
              if (uVar4 != 0) {
                iVar8 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,piVar9,1);
                if (iVar8 == 0) {
                  FUN_00103d50(piVar9 + 0x29,1,1);
                }
                goto LAB_0014937c;
              }
            }
            FUN_00103d50(piVar9 + 0x29,1,0);
          }
        }
        else if (iVar12 == 0x13) {
          if (uVar10 == 0) goto LAB_001490f4;
          FUN_00103d50(piVar9 + 0x29,2,1);
          FUN_00103d50(piVar9 + 0x2f,2,1);
          if (uVar4 == 0) {
LAB_001491e8:
            FUN_00103d50(piVar9 + 0x29,1,0);
          }
          else {
            iVar8 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,piVar9,1);
            if (iVar8 == 0) {
              FUN_00103d50(piVar9 + 0x29,1,1);
            }
          }
          FUN_00103d50(piVar9 + 0x2f,1,0);
        }
        else if (iVar12 == 0x12) {
          if (uVar10 == 0) {
            if (uVar4 != 0) {
              if ((piVar9[0x2e] & 1U) == 0) {
                iVar8 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,piVar9,1);
                if (iVar8 == 0) {
                  FUN_00103d50(piVar9 + 0x29,1,1);
                }
              }
              else {
                FUN_00103d50(piVar9 + 0x29,1,0);
              }
              if ((piVar9[0x34] & 1U) == 0) {
                iVar8 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,piVar9,2);
                if (iVar8 == 0) {
                  FUN_00103d50(piVar9 + 0x2f,1,1);
                }
              }
              else {
                FUN_00103d50(piVar9 + 0x2f,1,0);
              }
            }
          }
          else {
            FUN_00103d50(piVar9 + 0x29,2,1);
            FUN_00103d50(piVar9 + 0x2f,2,1);
            if (uVar4 == 0) goto LAB_001491e8;
            iVar8 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,piVar9,1);
            if (iVar8 == 0) {
              FUN_00103d50(piVar9 + 0x29,1,1);
            }
            iVar8 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,piVar9,2);
            if (iVar8 == 0) {
              FUN_00103d50(piVar9 + 0x2f,1,1);
            }
          }
        }
        else if (iVar12 - 0x24U < 3) {
          iVar8 = 2;
          piVar11 = piVar9 + 0x2c;
          piVar13 = piVar9 + 0x2f;
          do {
            if (uVar10 == 0) {
              if (uVar4 != 0) {
                if ((piVar11[8] & 1U) != 0) goto LAB_00149328;
                iVar12 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,piVar9,iVar8);
                if (iVar12 == 0) {
                  FUN_00103d50(piVar11 + 3,1,1);
                }
              }
            }
            else {
              FUN_00103d50(piVar13,2,1);
              if (uVar4 == 0) {
LAB_00149328:
                FUN_00103d50(piVar13,1,0);
              }
              else {
                iVar12 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,piVar9,iVar8);
                if (iVar12 == 0) {
                  FUN_00103d50(piVar13,1,1);
                }
              }
            }
            bVar1 = iVar8 != 3;
            piVar13 = piVar13 + 6;
            piVar11 = piVar11 + 6;
            iVar8 = iVar8 + 1;
          } while (bVar1);
        }
      }
LAB_0014937c:
      bVar1 = iVar6 != 3;
      iVar6 = iVar6 + 1;
    } while (bVar1);
    *(int *)(param_2 + 0x16c) = *(int *)(param_2 + 0x16c) + 1;
    FUN_00103d50(param_1 + 0x29,2,0);
    FUN_00103d50(param_1 + 0x29,1,0);
  }
  iVar6 = FUN_000f3824(local_54);
  if (((((iVar6 == 0) || (iVar6 = FUN_000f31e8(param_1,1), iVar6 == 0)) &&
       (iVar6 = FUN_000f2c5c(local_58), iVar6 != 0)) &&
      (((char)local_58 == '\x04' && (iVar6 = FUN_0010497c(piVar7,param_2), iVar6 != 0)))) &&
     ((iVar6 = FUN_00113128(*(undefined4 *)(piVar7[0x22] + 8),*(undefined4 *)(param_2 + 8)),
      iVar6 != 0 && (iVar6 = FUN_0011379c(*(undefined4 *)(param_2 + 8),piVar7), iVar6 != 0)))) {
    *(int *)(param_2 + 0x16c) = *(int *)(param_2 + 0x16c) + 1;
    iVar6 = FUN_001054ec(param_1,0);
    uVar5 = DAT_001b004c;
    piVar7[0x27] = *(int *)(iVar6 + 0x10);
    iVar6 = FUN_001054ec(param_1,1);
    *(undefined4 *)(iVar6 + 0x10) = uVar5;
    iVar6 = 0;
    do {
      if (*(char *)((int)&local_54 + iVar6) == '\x01') {
        (**(code **)(*param_1 + 0x88))(param_1,1,iVar6,4);
      }
      bVar1 = iVar6 != 3;
      iVar6 = iVar6 + 1;
    } while (bVar1);
  }
  return 1;
}

/* FUN_001494dc @ 0x1494dc (2168 bytes) */
int FUN_001494dc(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 *param_3;
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  int *local_5c;
  int *local_58;
  int local_4c;
  int *local_48;
  int local_38 [3];
  
  iVar3 = FUN_00126760(param_1[0x26]);
  if (iVar3 != 0) {
    iVar3 = (**(code **)(*param_1 + 100))(param_1);
    if (iVar3 != 0) {
      for (iVar3 = 1; iVar4 = (**(code **)(*param_1 + 0x14))(param_1), iVar3 <= iVar4;
          iVar3 = iVar3 + 1) {
        if ((((param_1[iVar3 * 6 + 0x28] & 1U) != 0) || ((param_1[iVar3 * 6 + 0x28] & 2U) != 0)) ||
           (iVar4 = FUN_000f31e8(param_1,iVar3), iVar4 == 0)) goto LAB_00149a40;
      }
      if ((param_1[0x48] == 0) && (param_1[0x49] == 0)) {
        if (((param_1[0x20] != 0) &&
            ((iVar3 = FUN_00126760(param_1[0x26]), iVar3 != 0 && ((param_1[5] & 2U) == 0)))) &&
           (iVar3 = (**(code **)(*param_1 + 0x50))(param_1), iVar3 == 0)) {
          iVar3 = 4;
          piVar8 = param_1;
          do {
            if (*(byte *)(piVar8 + 0x27) - 2 < 2) goto LAB_00149a40;
            piVar8 = (int *)((int)piVar8 + 1);
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        FUN_001054ec(param_1,0);
        iVar3 = FUN_00105dbc(param_1,0);
        if (iVar3 == 0) {
          piVar8 = (int *)(param_1[5] & 2);
          if ((piVar8 == (int *)0x0) && ((param_1[5] & 0x200U) != 0)) {
            local_5c = piVar8;
            local_58 = piVar8;
            local_48 = piVar8;
            FUN_00104d3c(param_1,&local_5c);
            piVar8 = local_58;
            piVar5 = (int *)FUN_00105594(param_1,1);
            if ((-1 < piVar5[5]) &&
               (((((piVar5[5] & 0x200U) == 0 &&
                  (iVar3 = (**(code **)(*piVar5 + 0x24))(), iVar3 != 0)) &&
                 (iVar3 = FUN_0010497c(piVar5,param_2), iVar3 != 0)) &&
                (iVar3 = FUN_0011320c(*(undefined4 *)(piVar5[0x22] + 8),*(undefined4 *)(param_2 + 8)
                                     ), iVar3 == 0)))) {
              iVar3 = FUN_001054ec(param_1,0);
              local_64 = *(int *)(iVar3 + 0x10);
              iVar3 = local_4c;
              piVar9 = piVar8;
LAB_00149704:
              FUN_0010ae20(param_1,piVar5,param_2);
              iVar4 = (**(code **)(*piVar5 + 100))(piVar5);
              if (iVar4 != 0) {
                for (iVar4 = 1; iVar7 = (**(code **)(*piVar5 + 0x14))(piVar5), iVar4 <= iVar7;
                    iVar4 = iVar4 + 1) {
                  if ((((piVar5[iVar4 * 6 + 0x28] & 1U) != 0) ||
                      ((piVar5[iVar4 * 6 + 0x28] & 2U) != 0)) ||
                     (iVar7 = FUN_000f31e8(piVar5,iVar4), iVar7 == 0)) goto LAB_001499ec;
                }
                if ((piVar5[0x48] == 0) && (piVar5[0x49] == 0)) {
                  if ((piVar5[0x20] != 0) &&
                     (((iVar4 = FUN_00126760(piVar5[0x26]), iVar4 != 0 && ((piVar5[5] & 2U) == 0))
                      && (iVar4 = (**(code **)(*piVar5 + 0x50))(piVar5), iVar4 == 0)))) {
                    iVar4 = 4;
                    piVar8 = piVar5;
                    do {
                      if (*(byte *)(piVar8 + 0x27) - 2 < 2) goto LAB_001499ec;
                      piVar8 = (int *)((int)piVar8 + 1);
                      iVar4 = iVar4 + -1;
                    } while (iVar4 != 0);
                  }
                  FUN_001054ec(piVar5,0);
                  iVar4 = FUN_00105dbc(piVar5,0);
                  if (((iVar4 == 0) && ((piVar5[5] & 2U) == 0)) &&
                     (((piVar5[5] & 0x200U) == 0 &&
                      (piVar8 = (int *)FUN_00105594(piVar5,1), piVar8 == piVar9)))) {
                    iVar7 = FUN_001054ec(piVar8,0);
                    iVar4 = 0;
                    local_68 = *(undefined4 *)(iVar7 + 0x10);
                    iVar7 = 4;
                    do {
                      if (*(char *)((int)&local_68 + iVar4) != '\x01') {
                        *(char *)((int)&local_64 + iVar4) = *(char *)((int)&local_68 + iVar4);
                      }
                      iVar4 = iVar4 + 1;
                      iVar7 = iVar7 + -1;
                    } while (iVar7 != 0);
                    piVar9 = (int *)0x0;
                    piVar8[0x58] = piVar8[0x58] + -1;
                    if ((piVar8[5] & 0x200U) != 0) {
                      piVar9 = (int *)FUN_00105594(piVar8,piVar8[0x21]);
                    }
                    local_60 = DAT_001b0050;
                    iVar7 = 4;
                    iVar4 = 0;
                    do {
                      if (*(char *)((int)&local_64 + iVar4) != '\x01') {
                        *(undefined1 *)((int)&local_60 + iVar4) =
                             *(undefined1 *)((int)&DAT_001b004c + iVar4);
                      }
                      uVar6 = local_60;
                      iVar4 = iVar4 + 1;
                      iVar7 = iVar7 + -1;
                    } while (iVar7 != 0);
                    iVar4 = FUN_001054ec(param_1,1);
                    *(undefined4 *)(iVar4 + 0x10) = uVar6;
                  }
                }
              }
LAB_001499ec:
              if (piVar9 != (int *)0x0) {
                FUN_00106804(param_1,piVar9,0,*(undefined4 *)(param_2 + 8));
                if (param_1[0x21] == 0) {
                  param_1[0x27] = iVar3;
                }
                else {
                  iVar4 = FUN_001054ec(param_1);
                  *(int *)(iVar4 + 0x10) = iVar3;
                }
              }
              param_1[0x27] = local_64;
              *param_3 = 0;
              return 1;
            }
            if (((((piVar5[0x20] != 0) && (iVar3 = FUN_00126760(piVar5[0x26]), iVar3 != 0)) &&
                 (((piVar5[5] & 2U) == 0 &&
                  ((iVar3 = (**(code **)(*piVar5 + 0x50))(piVar5), iVar3 == 0 &&
                   (iVar3 = FUN_0010497c(piVar5,param_2), iVar3 != 0)))))) && (-1 < piVar8[5])) &&
               (((((piVar8[5] & 0x200U) == 0 &&
                  (iVar3 = (**(code **)(*piVar8 + 0x24))(piVar8), iVar3 != 0)) &&
                 (iVar3 = FUN_0010497c(piVar8,param_2), iVar3 != 0)) &&
                (iVar3 = FUN_0011320c(*(undefined4 *)(piVar8[0x22] + 8),*(undefined4 *)(param_2 + 8)
                                     ), iVar3 == 0)))) {
              FUN_000f36b8(local_38,local_4c);
              local_64 = local_38[0];
              iVar3 = FUN_001054ec(param_1,1);
              iVar3 = *(int *)(iVar3 + 0x10);
              piVar9 = piVar5;
              piVar5 = piVar8;
              goto LAB_00149704;
            }
          }
        }
      }
    }
LAB_00149a40:
    iVar3 = (**(code **)(*param_1 + 100))(param_1);
    if (((iVar3 != 0) && (param_1[0x48] == 0)) &&
       ((param_1[0x49] == 0 && (((param_1[0x2e] & 1U) == 0 && ((param_1[0x2e] & 2U) == 0)))))) {
      if ((param_1[0x20] != 0) &&
         (((iVar3 = FUN_00126760(param_1[0x26]), iVar3 != 0 && ((param_1[5] & 2U) == 0)) &&
          (iVar3 = (**(code **)(*param_1 + 0x50))(param_1), iVar3 == 0)))) {
        iVar3 = 4;
        piVar8 = param_1;
        do {
          if (*(byte *)(piVar8 + 0x27) - 2 < 2) {
            return 0;
          }
          piVar8 = (int *)((int)piVar8 + 1);
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      FUN_001054ec(param_1,0);
      iVar3 = FUN_00105dbc(param_1,0);
      if (iVar3 == 0) {
        piVar8 = (int *)FUN_00105594(param_1,1);
        if ((((-1 < piVar8[5]) && ((piVar8[5] & 0x200U) == 0)) &&
            ((iVar3 = (**(code **)(*piVar8 + 0x24))(), iVar3 != 0 &&
             ((iVar3 = FUN_0010497c(piVar8,param_2), iVar3 != 0 &&
              (iVar3 = FUN_0011320c(*(undefined4 *)(piVar8[0x22] + 8),*(undefined4 *)(param_2 + 8)),
              iVar3 == 0)))))) &&
           ((iVar3 = FUN_000f3884(param_1), iVar3 != 0 && (iVar3 = FUN_000f3884(piVar8), iVar3 != 0)
            ))) {
          iVar3 = FUN_00113174(*(undefined4 *)(piVar8[0x22] + 8),*(undefined4 *)(param_2 + 8));
          if ((iVar3 == 0) &&
             (iVar3 = FUN_001131c0(*(undefined4 *)(piVar8[0x22] + 8),*(undefined4 *)(param_2 + 8)),
             iVar3 == 0)) {
            iVar3 = FUN_001054ec(piVar8,0);
            iVar3 = FUN_000f30d4(*(undefined4 *)(iVar3 + 0x10));
            iVar4 = FUN_001054ec(param_1,0);
            uVar6 = FUN_000f30d4(*(undefined4 *)(iVar4 + 0x10));
            for (iVar4 = 1; iVar7 = (**(code **)(*piVar8 + 0x14))(piVar8), iVar4 <= iVar7;
                iVar4 = iVar4 + 1) {
              iVar7 = FUN_001054ec(piVar8,iVar4);
              uVar2 = DAT_001b0050;
              cVar1 = *(char *)(iVar3 + iVar7 + 0x10);
              iVar7 = FUN_001054ec(piVar8,iVar4);
              *(undefined4 *)(iVar7 + 0x10) = uVar2;
              if (cVar1 != '\x04') {
                (**(code **)(*piVar8 + 0x88))(piVar8,iVar4,uVar6,cVar1);
              }
            }
          }
          iVar3 = 0;
          uVar6 = DAT_001b004c;
          if ((param_1[5] & 0x200U) != 0) {
            iVar3 = FUN_00105594(param_1,param_1[0x21]);
            iVar4 = FUN_001054ec(param_1,param_1[0x21]);
            uVar6 = *(undefined4 *)(iVar4 + 0x10);
          }
          iVar4 = FUN_001054ec(param_1,0);
          iVar4 = *(int *)(iVar4 + 0x10);
          iVar7 = param_1[3];
          FUN_0010ae20(param_1,piVar8,param_2);
          param_1[0x27] = iVar4;
          param_1[3] = iVar7;
          if (iVar3 != 0) {
            FUN_00106804(param_1,iVar3,0,*(undefined4 *)(param_2 + 8));
            iVar3 = FUN_001054ec(param_1,param_1[0x21]);
            *(undefined4 *)(iVar3 + 0x10) = uVar6;
          }
          *param_3 = 0;
          return 1;
        }
      }
    }
  }
  return 0;
}

/* FUN_00149d54 @ 0x149d54 (144 bytes) */
int FUN_00149d54(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = param_3 * 0x18 + 0x80;
  uVar2 = *(uint *)(param_1 + iVar1 + 0x20);
  uVar3 = *(uint *)(param_2 + iVar1 + 0x20);
  if (((uVar2 & 1) == (uVar3 & 1)) && ((uVar2 >> 1 & 1) == (uVar3 >> 1 & 1))) {
    iVar1 = FUN_001054ec(param_1,param_3);
    iVar4 = *(int *)(iVar1 + 0x10);
    iVar1 = FUN_001054ec(param_2,param_3);
    if (iVar4 == *(int *)(iVar1 + 0x10)) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00149de4 @ 0x149de4 (2740 bytes) */
int FUN_00149de4(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int *param_3;
  undefined4 *param_4;
  int param_5;
{
  bool bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  code *pcVar14;
  uint uVar15;
  int iVar16;
  int *piVar17;
  double dVar18;
  undefined4 local_68;
  undefined4 local_64 [3];
  undefined4 local_58 [5];
  
  (**(code **)(*param_3 + 100))(param_3);
  (**(code **)(*param_1 + 0x60))(param_1);
  iVar4 = (**(code **)(*param_1 + 0x58))(param_1);
  if (iVar4 == 0) {
    iVar4 = FUN_001054ec(param_1,param_2);
    local_68 = *(undefined4 *)(iVar4 + 0x10);
    FUN_000f2bdc(local_58,*param_4,local_68);
    piVar17 = *(int **)(param_5 + 0x30c);
    local_68 = local_58[0];
    pcVar14 = *(code **)(*piVar17 + 0x104);
    uVar5 = FUN_00105594(param_3,1);
    iVar4 = (*pcVar14)(piVar17,param_1,param_2,&local_68,uVar5);
    if (iVar4 != 0) {
      piVar17 = (int *)FUN_00105594(param_3,1);
      piVar6 = (int *)FUN_00105594(param_1,param_2);
      iVar4 = (**(code **)(*piVar6 + 0x60))();
      if ((iVar4 == 0) || ((param_3[0x2e] & 1U) == 0)) {
        iVar13 = *(int *)(param_5 + 0x6c4);
        iVar4 = (**(code **)(*piVar6 + 0x60))(piVar6);
        if (iVar4 == 0) {
          uVar15 = param_3[0x2e] & 1;
          if ((param_1[param_2 * 6 + 0x28] & 2U) == 0) {
            uVar12 = -(param_3[0x2e] & 2U) >> 0x1f;
          }
          else {
            uVar12 = 1;
            uVar15 = 0;
          }
          uVar15 = param_1[param_2 * 6 + 0x28] & 1U ^ uVar15;
          iVar4 = (**(code **)(**(int **)(param_5 + 0x30c) + 0x11c))
                            (*(int **)(param_5 + 0x30c),param_1,param_2,piVar17,uVar12,uVar15,
                             param_5);
          if (iVar4 == 0) {
            return 0;
          }
          *(int *)(iVar13 + 0x17c) = *(int *)(iVar13 + 0x17c) + 1;
          iVar4 = (**(code **)(*piVar17 + 0x5c))(piVar17);
          if ((iVar4 == 0) || (iVar4 = FUN_0010497c(param_3,iVar13), iVar4 != 0)) {
            piVar6 = piVar17;
            if (*(int *)(iVar13 + 0x478) < piVar17[0x58]) {
              piVar17[0x58] = piVar17[0x58] + 1;
            }
            else {
              piVar17[0x58] = *(int *)(iVar13 + 0x478) + 1;
            }
          }
          else {
            piVar6 = (int *)FUN_0010445c(piVar17,param_5,0);
            piVar6[0x26] = 0x31;
            piVar6[0x25] = piVar6[0x53];
            FUN_000e7738(piVar17[0x56],piVar17,piVar6);
            piVar6[0x58] = *(int *)(iVar13 + 0x478) + 1;
            iVar4 = FUN_00105594(piVar6,1);
            if (*(int *)(iVar13 + 0x478) < *(int *)(iVar4 + 0x160)) {
              *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
            }
            else {
              *(int *)(iVar4 + 0x160) = *(int *)(iVar13 + 0x478) + 1;
            }
            if (1 < piVar6[0x21]) {
              iVar4 = FUN_00105594(piVar6,2);
              if (*(int *)(iVar13 + 0x478) < *(int *)(iVar4 + 0x160)) {
                *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
              }
              else {
                *(int *)(iVar4 + 0x160) = *(int *)(iVar13 + 0x478) + 1;
              }
            }
          }
          FUN_00106004(param_1,param_2,piVar6,0,param_5);
          iVar4 = (**(code **)(*param_3 + 0x14))(param_3);
          if ((param_3[5] & 0x200U) != 0) {
            iVar4 = iVar4 + 1;
          }
          iVar8 = param_3[0x21];
          if (iVar4 < iVar8) {
            if ((param_3[5] & 0x200U) != 0) {
              iVar8 = iVar8 + -1;
            }
            iVar4 = (**(code **)(*param_3 + 0x14))(param_3);
            while (iVar4 = iVar4 + 1, iVar4 <= iVar8) {
              iVar9 = FUN_00105594(param_3,iVar4);
              if (*(int *)(iVar13 + 0x478) < *(int *)(iVar9 + 0x160)) {
                *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
              }
              else {
                *(int *)(iVar9 + 0x160) = *(int *)(iVar13 + 0x478) + 1;
              }
              pcVar14 = *(code **)(*param_1 + 0x94);
              uVar5 = FUN_00105594(param_3,iVar4);
              (*pcVar14)(param_1,uVar5,param_5);
            }
          }
          uVar5 = local_68;
          iVar4 = FUN_001054ec(param_1,param_2);
          *(undefined4 *)(iVar4 + 0x10) = uVar5;
          FUN_00103d50(param_1 + param_2 * 6 + 0x23,2,uVar12);
          FUN_00103d50(param_1 + param_2 * 6 + 0x23,1,uVar15);
        }
        else {
          *(int *)(iVar13 + 0x17c) = *(int *)(iVar13 + 0x17c) + 1;
          iVar4 = (**(code **)(*piVar17 + 0x60))(piVar17);
          if (iVar4 == 0) {
            iVar4 = FUN_001054ec(param_3,1);
            iVar8 = 0;
            local_64[0] = *(undefined4 *)(iVar4 + 0x10);
            do {
              iVar4 = FUN_001054ec(piVar6,1);
              uVar15 = (uint)*(byte *)(iVar8 + iVar4 + 0x10);
              if (uVar15 != 4) {
                (**(code **)(*piVar6 + 0x88))
                          (piVar6,1,iVar8,*(undefined1 *)((int)local_64 + uVar15));
                FUN_001054ec(param_3,0);
              }
              bVar1 = iVar8 != 3;
              iVar8 = iVar8 + 1;
            } while (bVar1);
            iVar4 = (**(code **)(*piVar17 + 0x5c))(piVar17);
            if ((iVar4 == 0) || (iVar4 = FUN_0010497c(param_3,iVar13), iVar4 != 0)) {
              piVar7 = piVar17;
              if (*(int *)(iVar13 + 0x478) < piVar17[0x58]) {
                piVar17[0x58] = piVar17[0x58] + 1;
              }
              else {
                piVar17[0x58] = *(int *)(iVar13 + 0x478) + 1;
              }
            }
            else {
              piVar7 = (int *)FUN_0010445c(piVar17,param_5,0);
              piVar7[0x26] = 0x31;
              piVar7[0x25] = piVar7[0x53];
              FUN_000e7738(piVar17[0x56],piVar17,piVar7);
              piVar7[0x58] = *(int *)(iVar13 + 0x478) + 1;
              iVar4 = FUN_00105594(piVar7,1);
              if (*(int *)(iVar13 + 0x478) < *(int *)(iVar4 + 0x160)) {
                *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
              }
              else {
                *(int *)(iVar4 + 0x160) = *(int *)(iVar13 + 0x478) + 1;
              }
              if (1 < piVar7[0x21]) {
                iVar4 = FUN_00105594(piVar7,2);
                if (*(int *)(iVar13 + 0x478) < *(int *)(iVar4 + 0x160)) {
                  *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar4 + 0x160) = *(int *)(iVar13 + 0x478) + 1;
                }
              }
            }
            FUN_00106004(piVar6,1,piVar7,0,param_5);
            if (((param_1[param_2 * 6 + 0x28] & 2U) != 0) || (uVar5 = 0, (param_3[0x2e] & 2U) != 0))
            {
              uVar5 = 1;
            }
            FUN_00103d50(param_1 + param_2 * 6 + 0x23,2,uVar5);
            uVar5 = FUN_00105594(piVar6,1);
            if ((param_1[5] & 0x200U) == 0) {
              iVar4 = param_1[0x21];
            }
            else {
              iVar4 = param_1[0x21] + -1;
            }
            iVar13 = (**(code **)(*param_1 + 0x14))(param_1);
            do {
              iVar13 = iVar13 + 1;
              if (iVar4 < iVar13) goto LAB_0014a868;
              piVar17 = (int *)FUN_00105594(param_1,iVar13);
            } while (param_3 != piVar17);
            FUN_00106004(param_1,iVar13,uVar5,0,param_5);
          }
          else {
            iVar4 = FUN_00104054(piVar6,iVar13);
            piVar7 = piVar6;
            if (1 < iVar4) {
              piVar7 = (int *)FUN_0010445c(piVar6,param_5,0);
              piVar7[0x26] = 0x36;
              piVar7[0x25] = piVar7[0x53];
              FUN_000e7700(param_1[0x56],param_1,piVar7);
              FUN_00106004(param_1,param_2,piVar7,0,param_5);
              iVar4 = piVar7[0x21];
              piVar6[0x58] = piVar6[0x58] + -1;
              piVar7[0x58] = *(int *)(iVar13 + 0x478) + 1;
              if (0 < iVar4) {
                iVar4 = 1;
                do {
                  iVar8 = FUN_00105594(piVar7,iVar4);
                  if (*(int *)(iVar13 + 0x478) < *(int *)(iVar8 + 0x160)) {
                    *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar8 + 0x160) = *(int *)(iVar13 + 0x478) + 1;
                  }
                  iVar4 = iVar4 + 1;
                } while (iVar4 <= piVar7[0x21]);
              }
            }
            iVar8 = 0;
            iVar4 = 0;
            do {
              iVar9 = FUN_001054ec(piVar7,1);
              uVar15 = (uint)*(byte *)(iVar8 + iVar9 + 0x10);
              iVar9 = FUN_001054ec(param_3,1);
              bVar2 = *(byte *)(uVar15 + iVar9 + 0x10);
              iVar9 = FUN_001054ec(piVar17,1);
              if (uVar15 != 4) {
                if (*(char *)((uint)bVar2 + iVar9 + 0x10) == '\x04') {
                  (**(code **)(*piVar7 + 0x88))(piVar7,1,iVar8,4);
                  if (1 < piVar17[0x21]) {
                    iVar11 = 2;
                    iVar9 = 0x30;
                    do {
                      iVar10 = FUN_001054ec(piVar17,iVar11);
                      cVar3 = *(char *)(iVar8 + iVar10 + 0x10);
                      if (cVar3 != '\x04') {
                        iVar10 = FUN_00105594(piVar17,iVar11);
                        iVar16 = piVar7[0x21];
                        dVar18 = (double)*(float *)(iVar9 + iVar10 + 0x20);
                        if (1 < iVar16) {
                          iVar10 = 2;
                          do {
                            iVar16 = FUN_00105594(piVar7,iVar10);
                            if (dVar18 == (double)*(float *)(iVar4 + iVar16 + 0x20)) {
                              (**(code **)(*piVar7 + 0x88))(piVar7,iVar10,iVar8,cVar3);
                              goto LAB_0014a214;
                            }
                            iVar16 = piVar7[0x21];
                            iVar10 = iVar10 + 1;
                          } while (iVar10 <= iVar16);
                        }
                        iVar16 = iVar16 + 1;
                        piVar7[0x21] = iVar16;
                        FUN_000f79c4(dVar18,dVar18,dVar18,dVar18,piVar7,iVar13,iVar16);
                        uVar5 = DAT_001b0050;
                        iVar10 = FUN_001054ec(piVar7,iVar16);
                        *(undefined4 *)(iVar10 + 0x10) = uVar5;
                        (**(code **)(*piVar7 + 0x88))(piVar7,iVar16,iVar8,cVar3);
                        iVar10 = FUN_00105594(piVar7,iVar16);
                        if (*(int *)(iVar13 + 0x478) < *(int *)(iVar10 + 0x160)) {
                          *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar10 + 0x160) = *(int *)(iVar13 + 0x478) + 1;
                        }
                      }
LAB_0014a214:
                      iVar11 = iVar11 + 1;
                      iVar9 = iVar9 + 0x18;
                    } while (iVar11 <= piVar17[0x21]);
                  }
                }
                else {
                  (**(code **)(*piVar7 + 0x88))(piVar7,1,iVar8);
                }
              }
              bVar1 = iVar8 != 3;
              iVar4 = iVar4 + 0x18;
              iVar8 = iVar8 + 1;
            } while (bVar1);
            iVar4 = FUN_00105594(piVar17,1);
            FUN_00106004(piVar7,1,iVar4,0,param_5);
            if (*(int *)(iVar13 + 0x478) < *(int *)(iVar4 + 0x160)) {
              *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
            }
            else {
              *(int *)(iVar4 + 0x160) = *(int *)(iVar13 + 0x478) + 1;
            }
            if (((param_1[param_2 * 6 + 0x28] & 2U) != 0) || (uVar5 = 0, (param_3[0x2e] & 2U) != 0))
            {
              uVar5 = 1;
            }
            FUN_00103d50(param_1 + param_2 * 6 + 0x23,2,uVar5);
            if ((param_1[5] & 0x200U) == 0) {
              iVar13 = param_1[0x21];
            }
            else {
              iVar13 = param_1[0x21] + -1;
            }
            iVar8 = (**(code **)(*param_1 + 0x14))(param_1);
            do {
              iVar8 = iVar8 + 1;
              if (iVar13 < iVar8) goto LAB_0014a868;
              piVar17 = (int *)FUN_00105594(param_1,iVar8);
            } while (param_3 != piVar17);
            FUN_00106004(param_1,iVar8,iVar4,0,param_5);
          }
        }
LAB_0014a868:
        FUN_00105894(param_3,param_5);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0014a898 @ 0x14a898 (128 bytes) */
int FUN_0014a898(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 local_28 [6];
  
  iVar3 = 0;
  iVar2 = FUN_001054ec(param_1,*(undefined4 *)(param_1 + 0x84));
  local_28[0] = *(undefined4 *)(iVar2 + 0x10);
  while ((iVar2 = FUN_001054ec(param_2,0), *(char *)(iVar3 + iVar2 + 0x10) == '\x01' ||
         (*(char *)((int)local_28 + iVar3) != '\x04'))) {
    bVar1 = iVar3 == 3;
    iVar3 = iVar3 + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_0014a918 @ 0x14a918 (708 bytes) */
int FUN_0014a918(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int local_48 [2];
  int *local_40;
  undefined4 local_30;
  int local_28 [4];
  
  uVar1 = *(uint *)(*(int *)(*(int *)(param_3 + 8) + 0x30c) + 8);
  if ((((uVar1 & 0x800) != 0) && ((uVar1 & 0x1000) != 0)) &&
     (iVar3 = FUN_000e07dc(*(int *)(param_3 + 8),0x38), iVar3 != 0)) {
    piVar4 = (int *)FUN_00105594(param_1,param_2);
    iVar3 = FUN_001054ec(param_1,param_2);
    local_48[0] = *(int *)(iVar3 + 0x10);
    iVar3 = (**(code **)(*piVar4 + 0x30))(piVar4);
    if (((iVar3 != 0) && (iVar3 = FUN_0010497c(piVar4,param_3), iVar3 != 0)) &&
       ((piVar4[5] & 0x200U) == 0)) {
      iVar3 = FUN_000f3190(local_48[0]);
      if (iVar3 == 0) {
        FUN_000f2bdc(local_28,piVar4[0x50],local_48[0]);
        iVar3 = 0;
        local_48[0] = local_28[0];
        piVar4[0x50] = local_28[0];
        iVar6 = 4;
        piVar2 = piVar4 + 0x27;
        do {
          if (*(char *)((int)local_48 + iVar3) == '\x04') {
            *(undefined1 *)piVar2 = 1;
          }
          else {
            *(undefined1 *)piVar2 = 0;
            *(char *)((int)local_48 + iVar3) = (char)iVar3;
          }
          iVar3 = iVar3 + 1;
          piVar2 = (int *)((int)piVar2 + 1);
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      local_30 = 0;
      local_48[1] = 0;
      local_40 = (int *)0x0;
      if ((param_1[5] & 0x200U) != 0) {
        FUN_00104d3c(param_1,local_48 + 1);
      }
      piVar2 = local_40;
      iVar3 = (**(code **)(*param_1 + 100))(param_1);
      if (((iVar3 == 0) ||
          (((piVar2 != (int *)0x0 &&
            ((iVar3 = (**(code **)(*piVar2 + 0x30))(piVar2), iVar3 == 0 ||
             (iVar3 = ((int (*)())FUN_0014a898)(param_1,piVar2), iVar3 == 0)))) ||
           ((param_1[param_2 * 6 + 0x28] & 1U) != 0)))) ||
         (((((param_1[param_2 * 6 + 0x28] & 2U) != 0 || (param_1[0x48] != 0)) ||
           (param_1[0x49] != 0)) || (iVar3 = FUN_0010497c(param_1,param_3), iVar3 == 0)))) {
        iVar6 = FUN_001054ec(param_1,param_2);
        iVar3 = local_48[0];
        if (*(int *)(iVar6 + 0x10) != local_48[0]) {
          if (param_2 == 0) {
            param_1[0x27] = local_48[0];
            return 1;
          }
          iVar6 = FUN_001054ec(param_1,param_2);
          *(int *)(iVar6 + 0x10) = iVar3;
          return 1;
        }
      }
      else {
        iVar3 = param_1[2];
        FUN_0019401c(piVar4);
        FUN_0019401c(param_1);
        uVar5 = FUN_00103ebc(piVar4,param_1,*(undefined4 *)(param_3 + 8),1);
        FUN_000e7700(*(undefined4 *)(iVar3 + 0x158),iVar3,uVar5);
        if (piVar2 != (int *)0x0) {
          FUN_00106b48(uVar5,local_48 + 1,0,*(undefined4 *)(param_3 + 8));
        }
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_0014abdc @ 0x14abdc (220 bytes) */
int FUN_0014abdc(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*param_1 + 0x60))();
  if (iVar1 != 0) {
    param_1 = (int *)FUN_00105594(param_1,1);
  }
  iVar1 = (**(code **)(*param_1 + 100))(param_1);
  uVar3 = 0;
  if (iVar1 != 0) {
    FUN_001479f8(param_1,param_2);
    ((int (*)())FUN_00148d8c)(param_1,param_2);
    ((int (*)())FUN_00148980)(param_1,param_2);
    uVar2 = ((int (*)())FUN_0014a918)(param_1,1,param_2);
    iVar1 = ((int (*)())FUN_001494dc)(param_1,param_2,param_3);
    uVar3 = 1;
    if (iVar1 == 0) {
      uVar3 = uVar2;
    }
  }
  return uVar3;
}

/* FUN_0014acb8 @ 0x14acb8 (1172 bytes) */
int FUN_0014acb8(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  
  uVar9 = *(undefined4 *)(param_2 + 8);
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (*(int *)(param_1[0x22] + 8) != 0x13) {
    return 0;
  }
  if (param_1[0x48] != 0) {
    return 0;
  }
  if (param_1[0x49] != 0) {
    return 0;
  }
  iVar3 = FUN_00105594(param_1,1);
  iVar4 = FUN_00105594(param_1,2);
  iVar1 = *(int *)(*(int *)(iVar3 + 0x88) + 8);
  if ((((iVar1 == 0x1c) || (iVar1 == 0x1d)) && (*(int *)(iVar3 + 0x120) == 0)) &&
     (iVar1 = FUN_000f48ec(param_1,1), iVar1 != 0)) {
    iVar1 = FUN_001054ec(param_1,2);
    iVar1 = FUN_000f2c5c(*(undefined4 *)(iVar1 + 0x10));
    if (iVar1 != 0) {
      iVar1 = FUN_0010497c(iVar3,param_2);
      uVar8 = 1;
      if (iVar1 != 0) goto LAB_0014adfc;
    }
  }
  iVar1 = *(int *)(*(int *)(iVar4 + 0x88) + 8);
  if ((iVar1 != 0x1c) && (iVar1 != 0x1d)) {
    return 0;
  }
  if (*(int *)(iVar4 + 0x120) != 0) {
    return 0;
  }
  iVar1 = FUN_000f48ec(param_1,2);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_001054ec(param_1,1);
  iVar1 = FUN_000f2c5c(*(undefined4 *)(iVar1 + 0x10));
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_0010497c(iVar4,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  uVar8 = 2;
LAB_0014adfc:
  iVar1 = FUN_00105594(param_1,uVar8);
  uVar6 = DAT_001b0170;
  local_4c = 0x3f800000;
  local_58 = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  iVar3 = FUN_000f5c0c(iVar1,1,DAT_001b0170,&local_58);
  if (iVar3 == 0) {
    iVar3 = FUN_000f5c0c(iVar1,2,uVar6,&local_58);
    if (iVar3 == 0) {
      return 0;
    }
    iVar4 = 1;
    iVar3 = 2;
  }
  else {
    iVar4 = 2;
    iVar3 = 1;
  }
  uVar2 = *(uint *)(iVar4 * 0x18 + iVar1 + 0xa0);
  if (((uVar2 & 1) == 0) && ((uVar2 & 2) == 0)) {
    *(int *)(param_2 + 0x1f0) = *(int *)(param_2 + 0x1f0) + 1;
    iVar5 = FUN_00105594(iVar1,iVar3);
    iVar11 = ((int)-(uVar8 ^ 1) >> 0x1f) + 2;
    *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + -1;
    uVar6 = FUN_00105594(param_1,iVar11);
    iVar5 = FUN_001054ec(param_1,0);
    iVar7 = *(int *)(iVar5 + 0x10);
    iVar11 = FUN_001054ec(param_1,iVar11);
    iVar5 = 0;
    local_68 = *(undefined4 *)(iVar11 + 0x10);
    iVar11 = 4;
    do {
      uVar8 = (uint)*(byte *)((int)&local_68 + iVar5);
      if (uVar8 != 4) goto LAB_0014af34;
      iVar5 = iVar5 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    uVar8 = 0xffffffff;
LAB_0014af34:
    iVar5 = 0;
    if ((param_1[5] & 0x200U) != 0) {
      iVar5 = FUN_00105594(param_1,param_1[0x21]);
    }
    local_64 = 0;
    local_60 = 0;
    local_5c = 0;
    FUN_00103f18(param_1,&local_64,0xffffffff);
    iVar10 = param_1[0x53];
    iVar11 = param_1[1];
    FUN_0019401c(param_1);
    FUN_00108174(param_1,*(undefined4 *)(*(int *)(iVar1 + 0x88) + 8),*(undefined4 *)(param_2 + 8));
    FUN_00103f44(param_1,&local_64);
    FUN_000e7738(*(undefined4 *)(iVar11 + 0x158),iVar11,param_1);
    iVar11 = *(int *)(iVar1 + 0x120);
    param_1[0x49] = *(int *)(iVar1 + 0x124);
    param_1[0x48] = iVar11;
    param_1[0x25] = iVar10;
    param_1[0x26] = 0;
    param_1[0x27] = iVar7;
    param_1[0x53] = iVar10;
    FUN_00106004(param_1,iVar3,uVar6,0,uVar9);
    iVar11 = *(int *)(PTR_DAT_001e8b8c + uVar8 * 4);
    if (iVar3 == 0) {
      param_1[0x27] = iVar11;
    }
    else {
      iVar7 = FUN_001054ec(param_1,iVar3);
      *(int *)(iVar7 + 0x10) = iVar11;
    }
    if (*(int *)(param_1[0x22] + 8) == 0x1c) {
      (**(code **)(*param_1 + 0x88))(param_1,iVar3,3,4);
    }
    iVar3 = FUN_00105594(iVar1,iVar4);
    FUN_00106004(param_1,iVar4,iVar3,0,uVar9);
    iVar11 = FUN_001054ec(iVar1,iVar4);
    iVar11 = *(int *)(iVar11 + 0x10);
    if (iVar4 == 0) {
      param_1[0x27] = iVar11;
    }
    else {
      iVar7 = FUN_001054ec(param_1,iVar4);
      *(int *)(iVar7 + 0x10) = iVar11;
    }
    iVar11 = iVar1 + iVar4 * 0x18 + 0x80;
    FUN_00103d50(param_1 + iVar4 * 6 + 0x23,1,*(uint *)(iVar11 + 0x20) & 1);
    FUN_00103d50(param_1 + iVar4 * 6 + 0x23,2,*(uint *)(iVar11 + 0x20) >> 1 & 1);
    if (iVar5 != 0) {
      FUN_00106804(param_1,iVar5,0,uVar9);
    }
    if (*(int *)(param_2 + 0x478) < *(int *)(iVar3 + 0x160)) {
      *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + 1;
    }
    else {
      *(int *)(iVar3 + 0x160) = *(int *)(param_2 + 0x478) + 1;
    }
    FUN_00105894(iVar1,uVar9);
  }
  return 0;
}

/* FUN_0014b150 @ 0x14b150 (1748 bytes) */
int FUN_0014b150(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined1 uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int iVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  int iVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_88;
  int local_78;
  int local_74;
  int local_70;
  undefined4 *local_6c;
  undefined4 *local_68;
  undefined4 *local_64;
  undefined4 *local_60;
  
  if ((*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x12) && (*(int *)(param_1 + 0x120) == 0)) {
    iVar4 = FUN_00105594(param_1,1);
    iVar5 = FUN_00105594(param_1,2);
    iVar21 = *(int *)(*(int *)(iVar4 + 0x88) + 8);
    iVar18 = *(int *)(*(int *)(iVar5 + 0x88) + 8);
    iVar6 = FUN_00105594(iVar4,3);
    iVar7 = FUN_00105594(iVar5,3);
    if (((((*(uint *)(param_1 + 0xb8) & 1) == 0) &&
         ((((*(uint *)(param_1 + 0xb8) & 2) == 0 && (iVar8 = FUN_000f48ec(param_1,1), iVar8 != 0))
          && (iVar21 == 0x14)))) &&
        ((((iVar21 = FUN_0010497c(iVar4,param_2), iVar21 != 0 && (*(int *)(iVar4 + 0x120) == 0)) &&
          (*(int *)(iVar4 + 0x124) == 0)) &&
         (((*(uint *)(iVar4 + 0xe8) & 2) == 0 && (iVar21 = FUN_000f48ec(iVar4,3), iVar21 != 0))))))
       && ((*(int *)(*(int *)(iVar6 + 0x88) + 8) == 0x13 &&
           (((iVar21 = FUN_0010497c(iVar6,param_2), iVar21 != 0 && (*(int *)(iVar6 + 0x120) == 0))
            && (*(int *)(iVar6 + 0x124) == *(int *)(param_1 + 0x124))))))) {
      uVar22 = 1;
      uVar23 = 2;
      iVar7 = iVar6;
      local_74 = iVar4;
      local_70 = iVar5;
    }
    else {
      if ((*(uint *)(param_1 + 0xd0) & 1) != 0) {
        return 0;
      }
      if ((*(uint *)(param_1 + 0xd0) & 2) != 0) {
        return 0;
      }
      iVar6 = FUN_000f48ec(param_1,2);
      if (iVar6 == 0) {
        return 0;
      }
      if (iVar18 != 0x14) {
        return 0;
      }
      iVar6 = FUN_0010497c(iVar5,param_2);
      if (iVar6 == 0) {
        return 0;
      }
      if (*(int *)(iVar5 + 0x120) != 0) {
        return 0;
      }
      if (*(int *)(iVar5 + 0x124) != 0) {
        return 0;
      }
      if ((*(uint *)(iVar5 + 0xe8) & 2) != 0) {
        return 0;
      }
      iVar6 = FUN_000f48ec(iVar5,3);
      if (iVar6 == 0) {
        return 0;
      }
      if (*(int *)(*(int *)(iVar7 + 0x88) + 8) != 0x13) {
        return 0;
      }
      iVar6 = FUN_0010497c(iVar7,param_2);
      if (iVar6 == 0) {
        return 0;
      }
      if (*(int *)(iVar7 + 0x120) != 0) {
        return 0;
      }
      if (*(int *)(iVar7 + 0x124) != *(int *)(param_1 + 0x124)) {
        return 0;
      }
      uVar22 = 2;
      uVar23 = 1;
      local_74 = iVar5;
      local_70 = iVar4;
    }
    iVar4 = FUN_00104800(local_70,iVar7);
    if (iVar4 != 0) {
      *(int *)(param_2 + 0x1dc) = *(int *)(param_2 + 0x1dc) + 1;
      local_78 = *(int *)(iVar7 + 0x160) - *(int *)(param_2 + 0x478);
      if (local_78 < 0) {
        local_78 = 0;
      }
      uVar14 = *(undefined4 *)(iVar7 + 0x120);
      iVar4 = 0;
      uVar15 = *(undefined4 *)(iVar7 + 0x124);
      FUN_001054ec(iVar7,0);
      if ((*(uint *)(iVar7 + 0x14) & 0x200) != 0) {
        iVar4 = FUN_00105594(iVar7,*(undefined4 *)(iVar7 + 0x84));
      }
      uVar16 = *(undefined4 *)(iVar7 + 0x98);
      uVar9 = FUN_00105594(iVar7,1);
      uVar10 = FUN_00105594(iVar7,2);
      local_d0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_88 = 0;
      local_e4 = 0;
      local_e0 = 0;
      uVar11 = FUN_001054ec(iVar7,1);
      local_64 = &local_9c;
      FUN_00104730(local_64,uVar11);
      uVar11 = FUN_001054ec(iVar7,2);
      local_60 = &local_e4;
      FUN_00104730(local_60,uVar11);
      iVar5 = *(int *)(param_1 + 0x160) - *(int *)(param_2 + 0x478);
      uVar13 = *(uint *)(local_74 + 0xe8);
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      uVar11 = *(undefined4 *)(param_1 + 0x120);
      iVar18 = 0;
      uVar17 = *(undefined4 *)(param_1 + 0x124);
      iVar6 = FUN_001054ec(param_1,0);
      uVar20 = *(undefined4 *)(iVar6 + 0x10);
      if ((*(uint *)(param_1 + 0x14) & 0x200) != 0) {
        iVar18 = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84));
      }
      local_a0 = 0;
      local_cc = 0;
      local_c8 = 0;
      local_b8 = 0;
      local_b4 = 0;
      local_b0 = 0;
      uVar19 = *(undefined4 *)(param_1 + 0x98);
      uVar12 = FUN_001054ec(param_1,uVar22);
      local_6c = &local_cc;
      FUN_00104730(local_6c,uVar12);
      uVar12 = FUN_001054ec(param_1,uVar23);
      local_68 = &local_b4;
      FUN_00104730(local_68,uVar12);
      local_e8 = DAT_001b0050;
      local_f4 = DAT_001b0050;
      local_f0 = DAT_001b0050;
      local_ec = DAT_001b0050;
      iVar6 = FUN_001054ec(iVar7,1);
      local_104 = *(undefined4 *)(iVar6 + 0x10);
      iVar6 = FUN_001054ec(iVar7,2);
      local_100 = *(undefined4 *)(iVar6 + 0x10);
      iVar6 = FUN_001054ec(local_74,3);
      local_fc = *(undefined4 *)(iVar6 + 0x10);
      iVar6 = FUN_001054ec(param_1,uVar23);
      local_f8 = *(undefined4 *)(iVar6 + 0x10);
      iVar6 = FUN_001054ec(param_1,uVar22);
      iVar21 = 0;
      local_108 = *(undefined4 *)(iVar6 + 0x10);
      iVar6 = 4;
      do {
        cVar2 = *(char *)((int)&local_f8 + iVar21);
        if (cVar2 != '\x04') {
          uVar3 = (uint)*(byte *)((int)&local_108 + iVar21);
          *(byte *)((int)&local_e8 + uVar3) = *(byte *)((int)&local_108 + iVar21);
          *(char *)((int)&local_f4 + uVar3) = cVar2;
          uVar1 = *(undefined1 *)((int)&local_104 + (uint)*(byte *)((int)&local_fc + uVar3));
          *(undefined1 *)((int)&local_ec + uVar3) =
               *(undefined1 *)((int)&local_100 + (uint)*(byte *)((int)&local_fc + uVar3));
          *(undefined1 *)((int)&local_f0 + uVar3) = uVar1;
        }
        iVar21 = iVar21 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      iVar6 = FUN_001054ec(local_74,0);
      iVar21 = *(int *)(iVar7 + 4);
      uVar22 = *(undefined4 *)(iVar6 + 0x10);
      FUN_0019401c(iVar7);
      FUN_00108304(iVar7,0x14,*(undefined4 *)(param_2 + 8));
      FUN_000e7738(*(undefined4 *)(iVar21 + 0x158),iVar21,iVar7);
      *(undefined4 *)(iVar7 + 0x120) = uVar14;
      *(undefined4 *)(iVar7 + 0x124) = uVar15;
      *(undefined4 *)(iVar7 + 0x9c) = uVar22;
      iVar6 = *(int *)(param_2 + 0x478);
      *(undefined4 *)(iVar7 + 0x98) = uVar16;
      *(int *)(iVar7 + 0x160) = local_78 + iVar6;
      *(undefined4 *)(iVar7 + 0x94) = *(undefined4 *)(iVar7 + 0x14c);
      FUN_00106004(iVar7,1,uVar9,0,*(undefined4 *)(param_2 + 8));
      uVar22 = FUN_001054ec(iVar7,1);
      FUN_00104730(uVar22,local_64);
      uVar22 = local_f0;
      iVar6 = FUN_001054ec(iVar7,1);
      *(undefined4 *)(iVar6 + 0x10) = uVar22;
      FUN_00106004(iVar7,2,uVar10,0,*(undefined4 *)(param_2 + 8));
      uVar22 = FUN_001054ec(iVar7,2);
      FUN_00104730(uVar22,local_60);
      uVar22 = local_ec;
      iVar6 = FUN_001054ec(iVar7,2);
      *(undefined4 *)(iVar6 + 0x10) = uVar22;
      FUN_00106004(iVar7,3,local_70,0,*(undefined4 *)(param_2 + 8));
      uVar22 = FUN_001054ec(iVar7,3);
      FUN_00104730(uVar22,local_68);
      uVar22 = local_f4;
      iVar6 = FUN_001054ec(iVar7,3);
      *(undefined4 *)(iVar6 + 0x10) = uVar22;
      if ((uVar13 & 1) != 0) {
        FUN_00103d50(iVar7 + 0xd4,1,(*(uint *)(iVar7 + 0xe8) ^ 1) & 1);
      }
      uVar22 = local_e8;
      iVar6 = FUN_001054ec(local_74,3);
      *(undefined4 *)(iVar6 + 0x10) = uVar22;
      if (iVar4 != 0) {
        FUN_00106804(iVar7,iVar4,0,*(undefined4 *)(param_2 + 8));
      }
      iVar7 = *(int *)(param_1 + 4);
      FUN_0019401c(param_1);
      FUN_00108448(param_1,0x31,*(undefined4 *)(param_2 + 8));
      FUN_000e7738(*(undefined4 *)(iVar7 + 0x158),iVar7,param_1);
      *(undefined4 *)(param_1 + 0x120) = uVar11;
      *(undefined4 *)(param_1 + 0x124) = uVar17;
      *(undefined4 *)(param_1 + 0x9c) = uVar20;
      iVar7 = *(int *)(param_2 + 0x478);
      *(undefined4 *)(param_1 + 0x98) = uVar19;
      *(int *)(param_1 + 0x160) = iVar5 + iVar7;
      *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x14c);
      FUN_00106004(param_1,1,local_74,0,*(undefined4 *)(param_2 + 8));
      uVar22 = FUN_001054ec(param_1,1);
      FUN_00104730(uVar22,local_6c);
      if (iVar18 != 0) {
        FUN_00106804(param_1,iVar18,0,*(undefined4 *)(param_2 + 8));
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_0014b82c @ 0x14b82c (1420 bytes) */
int FUN_0014b82c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
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
  int iVar19;
  undefined4 uVar20;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_84;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 *local_64;
  undefined4 *local_60;
  
  iVar4 = FUN_001470dc(param_1,param_2,param_4);
  if (iVar4 == 0) {
LAB_0014b954:
    uVar7 = 0;
  }
  else {
    iVar4 = FUN_00105594(param_1,1);
    iVar5 = FUN_00105594(param_1,2);
    iVar19 = *(int *)(*(int *)(iVar5 + 0x88) + 8);
    if (((((*(int *)(*(int *)(iVar4 + 0x88) + 8) == 0x13) && ((*(uint *)(param_1 + 0xb8) & 2) == 0))
         && (iVar6 = FUN_000f48ec(param_1,1), iVar6 != 0)) &&
        ((*(int *)(iVar4 + 0x120) == 0 && (*(int *)(iVar4 + 0x124) == 0)))) &&
       ((param_4 == 0 || (iVar6 = FUN_0010497c(iVar4,param_2), iVar6 != 0)))) {
      iVar6 = 1;
      uVar7 = 2;
      iVar19 = iVar5;
    }
    else {
      if ((((iVar19 != 0x13) || ((*(uint *)(param_1 + 0xd0) & 2) != 0)) ||
          ((iVar19 = FUN_000f48ec(param_1,2), iVar19 == 0 ||
           ((*(int *)(iVar5 + 0x120) != 0 || (*(int *)(iVar5 + 0x124) != 0)))))) ||
         ((param_4 != 0 && (iVar19 = FUN_0010497c(iVar5,param_2), iVar19 == 0)))) goto LAB_0014b954;
      iVar6 = 2;
      uVar7 = 1;
      iVar19 = iVar4;
      iVar4 = iVar5;
    }
    *(int *)(param_2 + 0x1d4) = *(int *)(param_2 + 0x1d4) + 1;
    iVar5 = *(int *)(param_1 + 0x160) - *(int *)(param_2 + 0x478);
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    uVar12 = *(undefined4 *)(param_1 + 0x10);
    uVar13 = *(undefined4 *)(param_1 + 0x14c);
    uVar14 = *(undefined4 *)(param_1 + 0x98);
    uVar15 = *(undefined4 *)(param_1 + 0x120);
    uVar16 = *(undefined4 *)(param_1 + 0x124);
    iVar8 = FUN_001054ec(param_1,0);
    uVar17 = *(undefined4 *)(iVar8 + 0x10);
    local_6c = 0;
    if ((*(uint *)(param_1 + 0x14) & 0x200) != 0) {
      local_6c = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84));
    }
    bVar1 = local_6c != 0;
    local_68 = DAT_001b004c;
    if (bVar1) {
      iVar8 = FUN_001054ec(param_1,*(undefined4 *)(param_1 + 0x84));
      local_68 = *(undefined4 *)(iVar8 + 0x10);
    }
    iVar8 = FUN_001054ec(param_1,iVar6);
    uVar18 = *(undefined4 *)(iVar8 + 0x10);
    uVar3 = *(uint *)(iVar6 * 0x18 + param_1 + 0xa0);
    uVar9 = FUN_00105594(iVar4,1);
    local_70 = FUN_00105594(iVar4,2);
    iVar6 = FUN_001054ec(iVar4,1);
    uVar20 = *(undefined4 *)(iVar6 + 0x10);
    iVar6 = FUN_001054ec(iVar4,2);
    uVar11 = *(undefined4 *)(iVar6 + 0x10);
    local_84 = 0;
    local_c8 = 0;
    local_c4 = 0;
    local_b4 = 0;
    local_b0 = 0;
    local_ac = 0;
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    uVar10 = FUN_001054ec(iVar4,1);
    FUN_00104730(&local_c8,uVar10);
    uVar10 = FUN_001054ec(iVar4,2);
    local_64 = &local_b0;
    FUN_00104730(local_64,uVar10);
    uVar7 = FUN_001054ec(param_1,uVar7);
    local_60 = &local_98;
    FUN_00104730(local_60,uVar7);
    if (0 < *(int *)(param_1 + 0x84)) {
      iVar6 = 1;
      do {
        iVar8 = FUN_00105594(param_1,iVar6);
        *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + -1;
        if (param_3 != 0) {
          iVar8 = FUN_00105594(param_1,iVar6);
          FUN_00194374(*(undefined4 *)(iVar8 + 0x10),param_1);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 <= *(int *)(param_1 + 0x84));
    }
    iVar6 = *(int *)(param_1 + 4);
    FUN_0019401c(param_1);
    FUN_00108304(param_1,0x14,*(undefined4 *)(param_2 + 8));
    bVar2 = param_3 == 0;
    FUN_000e7738(*(undefined4 *)(iVar6 + 0x158),iVar6,param_1);
    iVar6 = *(int *)(param_2 + 0x478);
    *(undefined4 *)(param_1 + 0x10) = uVar12;
    *(undefined4 *)(param_1 + 0x120) = uVar15;
    *(int *)(param_1 + 0x160) = iVar5 + iVar6;
    *(undefined4 *)(param_1 + 0x124) = uVar16;
    *(undefined4 *)(param_1 + 0x9c) = uVar17;
    *(undefined4 *)(param_1 + 0x94) = uVar13;
    *(undefined4 *)(param_1 + 0x98) = uVar14;
    uVar7 = FUN_001054ec(param_1,1);
    FUN_001047a8(uVar7,&local_c8);
    iVar5 = FUN_0010af38(uVar9,param_2,param_3);
    FUN_00106004(param_1,1,iVar5,param_3,*(undefined4 *)(param_2 + 8));
    if (bVar2) {
      if (*(int *)(param_2 + 0x478) < *(int *)(iVar5 + 0x160)) {
        *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + 1;
      }
      else {
        *(int *)(iVar5 + 0x160) = *(int *)(param_2 + 0x478) + 1;
      }
    }
    FUN_000f2bdc(&local_78,uVar20,uVar18);
    iVar5 = FUN_001054ec(param_1,1);
    *(undefined4 *)(iVar5 + 0x10) = local_78;
    if ((uVar3 & 1) != 0) {
      FUN_00103d50(param_1 + 0xa4,1,(*(uint *)(param_1 + 0xb8) ^ 1) & 1);
    }
    uVar7 = FUN_001054ec(param_1,2);
    FUN_001047a8(uVar7,local_64);
    iVar5 = FUN_0010af38(local_70,param_2,param_3);
    FUN_00106004(param_1,2,iVar5,param_3,*(undefined4 *)(param_2 + 8));
    if (bVar2) {
      if (*(int *)(param_2 + 0x478) < *(int *)(iVar5 + 0x160)) {
        *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + 1;
      }
      else {
        *(int *)(iVar5 + 0x160) = *(int *)(param_2 + 0x478) + 1;
      }
    }
    FUN_000f2bdc(&local_74,uVar11,uVar18);
    iVar5 = FUN_001054ec(param_1,2);
    *(undefined4 *)(iVar5 + 0x10) = local_74;
    uVar7 = FUN_001054ec(param_1,3);
    FUN_001047a8(uVar7,local_60);
    FUN_00106004(param_1,3,iVar19,param_3,*(undefined4 *)(param_2 + 8));
    if (bVar2) {
      if (*(int *)(param_2 + 0x478) < *(int *)(iVar19 + 0x160)) {
        *(int *)(iVar19 + 0x160) = *(int *)(iVar19 + 0x160) + 1;
      }
      else {
        *(int *)(iVar19 + 0x160) = *(int *)(param_2 + 0x478) + 1;
      }
    }
    if (bVar1) {
      FUN_00106804(param_1,local_6c,param_3,*(undefined4 *)(param_2 + 8));
      iVar5 = FUN_001054ec(param_1,*(undefined4 *)(param_1 + 0x84));
      *(undefined4 *)(iVar5 + 0x10) = local_68;
      if (bVar2) {
        if (*(int *)(param_2 + 0x478) < *(int *)(local_6c + 0x160)) {
          *(int *)(local_6c + 0x160) = *(int *)(local_6c + 0x160) + 1;
        }
        else {
          *(int *)(local_6c + 0x160) = *(int *)(param_2 + 0x478) + 1;
        }
      }
    }
    FUN_0010564c(iVar4,*(undefined4 *)(param_2 + 8),param_3);
    uVar7 = 1;
  }
  return uVar7;
}

/* FUN_0014bdbc @ 0x14bdbc (1912 bytes) */
int FUN_0014bdbc(param_1, param_2)
  void *param_1;
  int param_2;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  void *pvVar11;
  int *piVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint uVar16;
  int iVar17;
  undefined4 uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  int local_b4;
  undefined4 local_a4;
  undefined4 local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  int *local_84;
  undefined4 local_80;
  int local_7c;
  int *local_78;
  undefined4 local_74;
  int local_70;
  int local_6c;
  
  iVar21 = *(int *)(param_2 + 8);
  iVar6 = FUN_000e07dc(iVar21,0x2a);
  if (((iVar6 == 0) && (param_1 != (void *)0x0)) &&
     (*(int *)(*(int *)((int)param_1 + 0x88) + 8) == 0x13)) {
    iVar6 = FUN_001054ec(param_1,0);
    iVar17 = 1;
    local_c8 = *(undefined4 *)(iVar6 + 0x10);
    iVar6 = 0x98;
    do {
      iVar7 = FUN_00105594(param_1,iVar17);
      if (((*(int *)(*(int *)(iVar7 + 0x88) + 8) == 0x12) && (*(int *)(iVar7 + 0x120) == 0)) &&
         ((*(int *)(iVar7 + 0x124) == 0 &&
          (((*(uint *)((int)param_1 + iVar6 + 0x20) & 2) == 0 &&
           ((*(uint *)(iVar7 + 0x14) & 0x200) == 0)))))) {
        iVar8 = FUN_001054ec(param_1,iVar17);
        fVar3 = FLOAT_001aa114;
        local_c4 = *(undefined4 *)(iVar8 + 0x10);
        iVar8 = 1;
        local_6c = (int)param_1 + iVar6;
        do {
          iVar9 = FUN_001054ec(iVar7,iVar8);
          local_c0 = *(undefined4 *)(iVar9 + 0x10);
          uVar16 = 0;
          iVar9 = FUN_001054ec(iVar7,0);
          local_bc = *(undefined4 *)(iVar9 + 0x10);
          iVar9 = FUN_00105594(iVar7,iVar8);
          iVar22 = 4;
          bVar1 = true;
          iVar13 = 0;
          do {
            if (*(char *)((int)&local_c8 + iVar13) != '\0') goto LAB_0014bf78;
            uVar5 = (uint)*(byte *)((int)&local_c0 + (uint)*(byte *)((int)&local_c4 + iVar13));
            if ((*(char *)((int)&local_bc + (uint)*(byte *)((int)&local_c4 + iVar13)) == '\0') &&
               (((int)*(char *)(iVar9 + 0x15c) >> (uVar5 & 0x3f) & 1U) != 0)) {
              fVar2 = *(float *)(uVar5 * 0x18 + iVar9 + 0x20);
              if (fVar2 == fVar3) {
                if (0 < (int)uVar16) goto LAB_0014bf74;
                uVar16 = 0xffffffff;
              }
              else {
                if ((fVar2 != FLOAT_001aa0e8) || ((int)uVar16 < 0)) goto LAB_0014bf74;
                uVar16 = 1;
              }
            }
            else {
LAB_0014bf74:
              bVar1 = false;
            }
LAB_0014bf78:
            iVar13 = iVar13 + 1;
            iVar22 = iVar22 + -1;
          } while (iVar22 != 0);
          if ((bVar1) &&
             ((iVar13 = (**(code **)(**(int **)(iVar21 + 0x30c) + 0x88))(), iVar13 != 0 ||
              ((*(uint *)(iVar8 * 0x18 + iVar9 + 0xa0) & 2) == 0)))) {
            local_78 = *(int **)((int)param_1 + 4);
            local_7c = FUN_00104054(param_1,param_2);
            local_80 = *(undefined4 *)((int)param_1 + 0x120);
            iVar13 = (iVar17 == 1) + 1;
            uVar14 = *(undefined4 *)((int)param_1 + 0x124);
            local_84 = (int *)FUN_00105594(param_1,iVar13);
            iVar9 = FUN_001054ec(param_1,iVar13);
            uVar15 = *(undefined4 *)(iVar9 + 0x10);
            local_70 = iVar13 * 0x18 + 0x80;
            uVar5 = *(uint *)((int)param_1 + iVar13 * 0x18 + 0xa0);
            local_88 = uVar5 & 1;
            local_8c = uVar5 >> 1 & 1;
            iVar9 = FUN_001054ec(param_1,iVar17);
            uVar18 = *(undefined4 *)(iVar9 + 0x10);
            iVar22 = (iVar8 == 1) + 1;
            local_90 = *(uint *)(local_6c + 0x20) & 1;
            piVar10 = (int *)FUN_00105594(iVar7,iVar22);
            iVar9 = FUN_001054ec(iVar7,iVar22);
            uVar5 = *(uint *)(iVar22 * 0x18 + iVar7 + 0xa0);
            local_94 = uVar5 >> 1 & 1;
            FUN_000f2bdc(&local_98,*(undefined4 *)(iVar9 + 0x10),uVar18);
            uVar19 = *(uint *)((int)param_1 + 0x14);
            uVar4 = *(uint *)(iVar8 * 0x18 + iVar7 + 0xa0);
            local_a4 = 0;
            local_b8 = 0;
            local_b4 = 0;
            local_74 = local_98;
            if ((uVar19 & 0x200) != 0) {
              FUN_00104d3c(param_1,&local_b8);
              uVar19 = *(uint *)((int)param_1 + 0x14);
            }
            uVar18 = *(undefined4 *)((int)param_1 + 0x98);
            pvVar11 = (void *)FUN_001043f0(0x14,*(undefined4 *)(param_2 + 8));
            if ((uVar19 & 2) != 0) {
              *(uint *)((int)pvVar11 + 0x14) = *(uint *)((int)pvVar11 + 0x14) | 2;
            }
            *(undefined4 *)((int)pvVar11 + 0xc) = *(undefined4 *)((int)param_1 + 0xc);
            *(undefined4 *)((int)pvVar11 + 0x94) = *(undefined4 *)((int)pvVar11 + 0x14c);
            *(undefined4 *)((int)pvVar11 + 0x98) = uVar18;
            *(undefined4 *)((int)pvVar11 + 0x120) = local_80;
            *(undefined4 *)((int)pvVar11 + 0x9c) = local_c8;
            *(undefined4 *)((int)pvVar11 + 0x124) = uVar14;
            FUN_00106004(pvVar11,iVar13,local_84,0,iVar21);
            iVar9 = FUN_001054ec(pvVar11,iVar13);
            *(undefined4 *)(iVar9 + 0x10) = uVar15;
            iVar9 = (int)pvVar11 + local_70 + 0xc;
            FUN_00103d50(iVar9,2,local_8c);
            FUN_00103d50(iVar9,1,local_88);
            iVar13 = *(int *)(param_2 + 0x478);
            iVar9 = (**(code **)(*piVar10 + 0x5c))(piVar10);
            if (iVar9 != 0) {
              piVar10 = (int *)FUN_0010445c(piVar10,*(undefined4 *)(param_2 + 8),0);
              iVar22 = piVar10[0x53];
              iVar9 = FUN_001054ec(piVar10,0);
              *(int *)(iVar9 + 8) = iVar22;
              piVar10[0x58] = iVar13;
            }
            uVar5 = local_90 ^ uVar5 & 1;
            iVar9 = FUN_00106230(pvVar11,iVar17,piVar10,local_94,uVar5,iVar21);
            iVar22 = FUN_001054ec(pvVar11,iVar17);
            *(undefined4 *)(iVar22 + 0x10) = local_74;
            iVar22 = (int)pvVar11 + iVar6 + 0xc;
            FUN_00103d50(iVar22,2,local_94);
            FUN_00103d50(iVar22,1,uVar5);
            piVar12 = local_84;
            iVar22 = (**(code **)(*local_84 + 0x5c))(local_84);
            if (iVar22 != 0) {
              piVar12 = (int *)FUN_0010445c(local_84,*(undefined4 *)(param_2 + 8),0);
              iVar20 = piVar12[0x53];
              iVar22 = FUN_001054ec(piVar12,0);
              *(int *)(iVar22 + 8) = iVar20;
              piVar12[0x58] = iVar13;
            }
            uVar16 = local_88 ^ local_90 ^ uVar4 & 1 ^ uVar16 >> 0x1f;
            iVar22 = FUN_00106230(pvVar11,3,piVar12,local_8c,uVar16,iVar21);
            iVar20 = FUN_001054ec(pvVar11,3);
            *(undefined4 *)(iVar20 + 0x10) = uVar15;
            FUN_00103d50((int)pvVar11 + 0xd4,2,local_8c);
            FUN_00103d50((int)pvVar11 + 0xd4,1,uVar16);
            if (local_b4 != 0) {
              FUN_00106b48(pvVar11,&local_b8,0,iVar21);
            }
            *(int *)((int)pvVar11 + 0x160) = local_7c + *(int *)(param_2 + 0x478);
            if (iVar22 != 0 && iVar9 != 0) {
              *(int *)(param_2 + 0x1d0) = *(int *)(param_2 + 0x1d0) + 1;
              iVar6 = (**(code **)(*piVar10 + 0x5c))(piVar10);
              if (iVar6 != 0) {
                for (iVar6 = 1; iVar17 = (**(code **)(*piVar10 + 0x14))(piVar10), iVar6 <= iVar17;
                    iVar6 = iVar6 + 1) {
                  iVar17 = FUN_00105594(piVar10,iVar6);
                  if (iVar13 < *(int *)(iVar17 + 0x160)) {
                    *(int *)(iVar17 + 0x160) = *(int *)(iVar17 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar17 + 0x160) = iVar13 + 1;
                  }
                }
                FUN_000e7738(local_78[0x56],local_78,piVar10);
                local_78 = piVar10;
              }
              if (*(int *)(param_2 + 0x478) < piVar10[0x58]) {
                piVar10[0x58] = piVar10[0x58] + 1;
              }
              else {
                piVar10[0x58] = *(int *)(param_2 + 0x478) + 1;
              }
              iVar6 = (**(code **)(*piVar12 + 0x5c))(piVar12);
              if (iVar6 != 0) {
                for (iVar6 = 1; iVar17 = (**(code **)(*piVar12 + 0x14))(piVar12), iVar6 <= iVar17;
                    iVar6 = iVar6 + 1) {
                  iVar17 = FUN_00105594(piVar12,iVar6);
                  if (iVar13 < *(int *)(iVar17 + 0x160)) {
                    *(int *)(iVar17 + 0x160) = *(int *)(iVar17 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar17 + 0x160) = iVar13 + 1;
                  }
                }
                FUN_000e7738(local_78[0x56],local_78,piVar12);
                local_78 = piVar12;
              }
              if (*(int *)(param_2 + 0x478) < piVar12[0x58]) {
                piVar12[0x58] = piVar12[0x58] + 1;
              }
              else {
                piVar12[0x58] = *(int *)(param_2 + 0x478) + 1;
              }
              FUN_0019401c(param_1);
              _memcpy(param_1,pvVar11,0x164);
              FUN_000e7738(local_78[0x56],local_78,param_1);
              FUN_00105894(iVar7,iVar21);
              return 1;
            }
          }
          bVar1 = iVar8 != 2;
          iVar8 = iVar8 + 1;
        } while (bVar1);
      }
      bVar1 = iVar17 != 2;
      iVar6 = iVar6 + 0x18;
      iVar17 = iVar17 + 1;
    } while (bVar1);
  }
  return 0;
}

/* FUN_0014c534 @ 0x14c534 (208 bytes) */
int FUN_0014c534(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_48 [9];
  
  iVar3 = 0;
  iVar4 = 0;
  *param_1 = DAT_001b0050;
  do {
    iVar2 = FUN_001054ec(param_2,param_3);
    local_48[0] = *(undefined4 *)(iVar2 + 0x10);
    if (*(char *)((int)local_48 + iVar4) != '\x04') {
      *(char *)((int)param_1 + iVar3) = *(char *)((int)local_48 + iVar4);
      iVar3 = iVar3 + 1;
    }
    bVar1 = iVar4 != 3;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  iVar4 = 0;
  do {
    iVar2 = FUN_001054ec(param_4,param_5);
    local_48[0] = *(undefined4 *)(iVar2 + 0x10);
    if ((iVar3 < 4) && (*(char *)((int)local_48 + iVar4) != '\x04')) {
      *(char *)((int)param_1 + iVar3) = *(char *)((int)local_48 + iVar4);
      iVar3 = iVar3 + 1;
    }
    bVar1 = iVar4 != 3;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  return param_1;
}

/* FUN_0014c604 @ 0x14c604 (972 bytes) */
int FUN_0014c604(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
  undefined4 *param_5;
  int *param_6;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_68;
  undefined4 local_64 [3];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [4];
  
  local_64[0] = 0;
  local_68 = 0;
  iVar1 = FUN_00147b8c(param_1,1,param_2,1,param_3,0,&local_68);
  iVar2 = FUN_00147b8c(param_1,1,param_2,2,param_3,0,&local_68);
  iVar3 = FUN_00147b8c(param_1,2,param_2,2,param_3,0,local_64);
  iVar4 = FUN_00147b8c(param_1,2,param_2,1,param_3,0,local_64);
  if ((iVar1 == 0) || (iVar3 == 0)) {
    if (iVar2 == 0) {
      return 0;
    }
    if (iVar4 == 0) {
      return 0;
    }
    if (iVar1 == 0) {
      ((int (*)())FUN_0014c534)(&local_48,param_1,1,param_2,2);
      *param_4 = local_48;
      ((int (*)())FUN_0014c534)(&local_44,param_1,2,param_2,1);
      *param_5 = local_44;
      uVar5 = FUN_00105594(param_1,1);
      iVar2 = FUN_00146670(param_4,uVar5,local_68,*(undefined4 *)(param_3 + 8));
      if (iVar2 == 0) {
LAB_0014c8e4:
        ((int (*)())FUN_0014c534)(&local_40,param_2,1,param_1,2);
        *param_4 = local_40;
        ((int (*)())FUN_0014c534)(local_3c,param_2,2,param_1,1);
        *param_5 = local_3c[0];
        uVar5 = FUN_00105594(param_1,1);
        iVar2 = FUN_00146670(param_4,uVar5,local_68,*(undefined4 *)(param_3 + 8));
        if (iVar2 == 0) {
          return 0;
        }
        uVar5 = FUN_00105594(param_1,2);
        iVar2 = FUN_00146670(param_5,uVar5,local_64[0],*(undefined4 *)(param_3 + 8));
        if (iVar2 == 0) {
          return 0;
        }
      }
      else {
        uVar5 = FUN_00105594(param_1,2);
        iVar2 = FUN_00146670(param_5,uVar5,local_64[0],*(undefined4 *)(param_3 + 8));
        if (iVar2 == 0) goto LAB_0014c8e4;
      }
      FUN_00147b8c(param_1,1,param_2,2,param_3,1,&local_68);
      FUN_00147b8c(param_1,2,param_2,1,param_3,1,local_64);
      goto LAB_0014c848;
    }
  }
  ((int (*)())FUN_0014c534)(&local_58,param_1,1,param_2,1);
  *param_4 = local_58;
  ((int (*)())FUN_0014c534)(&local_54,param_1,2,param_2,2);
  *param_5 = local_54;
  uVar5 = FUN_00105594(param_1,1);
  iVar2 = FUN_00146670(param_4,uVar5,local_68,*(undefined4 *)(param_3 + 8));
  if (iVar2 == 0) {
LAB_0014c778:
    ((int (*)())FUN_0014c534)(&local_50,param_2,1,param_1,1);
    *param_4 = local_50;
    ((int (*)())FUN_0014c534)(&local_4c,param_2,2,param_1,2);
    *param_5 = local_4c;
    uVar5 = FUN_00105594(param_1,1);
    iVar2 = FUN_00146670(param_4,uVar5,local_68,*(undefined4 *)(param_3 + 8));
    if (iVar2 == 0) {
      return 0;
    }
    uVar5 = FUN_00105594(param_1,2);
    iVar2 = FUN_00146670(param_5,uVar5,local_64[0],*(undefined4 *)(param_3 + 8));
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    uVar5 = FUN_00105594(param_1,2);
    iVar2 = FUN_00146670(param_5,uVar5,local_64[0],*(undefined4 *)(param_3 + 8));
    if (iVar2 == 0) goto LAB_0014c778;
  }
  FUN_00147b8c(param_1,1,param_2,1,param_3,1,&local_68);
  FUN_00147b8c(param_1,2,param_2,2,param_3,1,local_64);
LAB_0014c848:
  *param_6 = iVar1;
  return 1;
}

/* FUN_0014c9d0 @ 0x14c9d0 (284 bytes) */
int FUN_0014c9d0(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  int local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  iVar1 = (**(code **)(*param_1 + 0x5c))();
  if (iVar1 != 0) {
    iVar1 = FUN_001054ec(param_1,0);
    uVar2 = *(undefined4 *)(iVar1 + 0x10);
    iVar1 = FUN_001054ec(param_2,0);
    FUN_000f2f84(&local_28,uVar2,*(undefined4 *)(iVar1 + 0x10));
    param_1[0x27] = local_28;
    iVar1 = FUN_001054ec(param_1,1);
    uVar2 = *(undefined4 *)(iVar1 + 0x10);
    iVar1 = FUN_001054ec(param_2,1);
    FUN_000f2fe0(&local_24,uVar2,*(undefined4 *)(iVar1 + 0x10));
    iVar1 = FUN_001054ec(param_1,1);
    *(undefined4 *)(iVar1 + 0x10) = local_24;
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar1 == 2) {
      iVar1 = FUN_001054ec(param_1,2);
      uVar2 = *(undefined4 *)(iVar1 + 0x10);
      iVar1 = FUN_001054ec(param_2,2);
      FUN_000f2fe0(local_20,uVar2,*(undefined4 *)(iVar1 + 0x10));
      iVar1 = FUN_001054ec(param_1,2);
      *(undefined4 *)(iVar1 + 0x10) = local_20[0];
    }
  }
  return;
}

/* FUN_0014caec @ 0x14caec (988 bytes) */
int FUN_0014caec(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  double dVar7;
  undefined4 local_58;
  undefined4 local_54;
  int local_50 [9];
  undefined4 local_2c;
  
  if ((((param_1 != (int *)0x0) && (*(int *)(param_1[0x22] + 8) == 0x14)) &&
      ((uint)*(byte *)(param_1 + 3) + (uint)*(byte *)((int)param_1 + 0xd) +
       (uint)*(byte *)((int)param_1 + 0xe) + (uint)*(byte *)((int)param_1 + 0xf) == 1)) &&
     (((param_1[0x3a] & 1U) == 0 && ((param_1[0x3a] & 2U) == 0)))) {
    iVar1 = (**(code **)(*param_1 + 0x14))();
    if ((param_1[5] & 0x200U) != 0) {
      iVar1 = iVar1 + 1;
    }
    if (param_1[0x21] <= iVar1) {
      iVar2 = FUN_00105594(param_1,3);
      iVar1 = *(int *)(*(int *)(iVar2 + 0x88) + 8);
      if (((iVar1 == 0x13) || (iVar1 == 0x36)) &&
         (((uint)*(byte *)(iVar2 + 0xc) + (uint)*(byte *)(iVar2 + 0xd) +
           (uint)*(byte *)(iVar2 + 0xe) + (uint)*(byte *)(iVar2 + 0xf) == 1 &&
          (((*(int *)(iVar2 + 0x120) == 0 &&
            (local_50[0] = *(int *)(iVar2 + 0x124), local_50[0] == 0)) &&
           (iVar1 = ((int (*)())FUN_0014c604)(param_1,iVar2,param_2,&local_58,&local_54,local_50), iVar1 != 0))))
         )) {
        *(int *)(param_2 + 0x1e0) = *(int *)(param_2 + 0x1e0) + 1;
        pvVar3 = (void *)FUN_001043f0(0x1e,*(undefined4 *)(param_2 + 8));
        iVar1 = FUN_001054ec(pvVar3,1);
        *(undefined4 *)(iVar1 + 0x10) = local_58;
        iVar1 = FUN_001054ec(pvVar3,2);
        *(undefined4 *)(iVar1 + 0x10) = local_54;
        if (local_50[0] == 0) {
          uVar4 = FUN_00105594(param_1,1);
          uVar5 = FUN_00105594(iVar2,2);
          ((int (*)())FUN_0014c9d0)(uVar4,uVar5);
          uVar4 = FUN_00105594(param_1,2);
          uVar5 = FUN_00105594(iVar2,1);
          ((int (*)())FUN_0014c9d0)(uVar4,uVar5);
        }
        else {
          uVar4 = FUN_00105594(param_1,1);
          uVar5 = FUN_00105594(iVar2,1);
          ((int (*)())FUN_0014c9d0)(uVar4,uVar5);
          uVar4 = FUN_00105594(param_1,2);
          uVar5 = FUN_00105594(iVar2,2);
          ((int (*)())FUN_0014c9d0)(uVar4,uVar5);
        }
        uVar4 = FUN_00105594(param_1,1);
        FUN_00106004(pvVar3,1,uVar4,0,*(undefined4 *)(param_2 + 8));
        uVar4 = FUN_00105594(param_1,2);
        FUN_00106004(pvVar3,2,uVar4,0,*(undefined4 *)(param_2 + 8));
        FUN_00103d50((int)pvVar3 + 0xa4,1,param_1[0x2e] & 1);
        FUN_00103d50((int)pvVar3 + 0xbc,1,param_1[0x34] & 1);
        FUN_00103d50((int)pvVar3 + 0xa4,2,(uint)param_1[0x2e] >> 1 & 1);
        FUN_00103d50((int)pvVar3 + 0xbc,2,(uint)param_1[0x34] >> 1 & 1);
        dVar7 = (double)FLOAT_001aa0d4;
        FUN_000f79c4(dVar7,dVar7,dVar7,dVar7,pvVar3,param_2,3);
        *(int *)((int)pvVar3 + 0x98) = param_1[0x26];
        *(undefined4 *)((int)pvVar3 + 0x94) = *(undefined4 *)((int)pvVar3 + 0x14c);
        local_50[1] = 0;
        local_50[2] = 0;
        local_50[3] = 0;
        FUN_00103f18(param_1,local_50 + 1,0xffffffff);
        FUN_00103f44(pvVar3,local_50 + 1);
        iVar1 = FUN_001054ec(param_1,0);
        *(undefined4 *)((int)pvVar3 + 0x9c) = *(undefined4 *)(iVar1 + 0x10);
        if ((param_1[5] & 0x200U) != 0) {
          local_2c = 0;
          local_50[4] = 0;
          local_50[5] = 0;
          FUN_00104d3c(param_1,local_50 + 4);
          FUN_00106b48(pvVar3,local_50 + 4,0,*(undefined4 *)(param_2 + 8));
        }
        iVar1 = param_1[0x48];
        iVar6 = param_1[3];
        *(int *)((int)pvVar3 + 0x124) = param_1[0x49];
        *(int *)((int)pvVar3 + 0x120) = iVar1;
        *(int *)((int)pvVar3 + 0xc) = iVar6;
        iVar1 = param_1[1];
        FUN_0019401c(param_1);
        _memcpy(param_1,pvVar3,0x164);
        FUN_000e7738(*(undefined4 *)(iVar1 + 0x158),iVar1,param_1);
        FUN_00105894(iVar2,*(undefined4 *)(param_2 + 8));
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0014cec8 @ 0x14cec8 (940 bytes) */
int FUN_0014cec8(param_1, param_2)
  void *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_58;
  undefined4 local_54;
  int local_50 [5];
  float local_3c;
  
  if (((((param_1 != (void *)0x0) && (*(int *)(*(int *)((int)param_1 + 0x88) + 8) == 0x14)) &&
       ((uint)*(byte *)((int)param_1 + 0xc) + (uint)*(byte *)((int)param_1 + 0xd) +
        (uint)*(byte *)((int)param_1 + 0xe) + (uint)*(byte *)((int)param_1 + 0xf) == 1)) &&
      ((((*(uint *)((int)param_1 + 0xe8) & 1) == 0 && ((*(uint *)((int)param_1 + 0xe8) & 2) == 0))
       && ((iVar1 = FUN_00105594(param_1,3), *(int *)(*(int *)(iVar1 + 0x88) + 8) == 0x1e &&
           (((uint)*(byte *)(iVar1 + 0xc) + (uint)*(byte *)(iVar1 + 0xd) +
             (uint)*(byte *)(iVar1 + 0xe) + (uint)*(byte *)(iVar1 + 0xf) == 1 &&
            (*(int *)(iVar1 + 0x120) == 0)))))))) && (iVar6 = *(int *)(iVar1 + 0x124), iVar6 == 0))
  {
    iVar2 = FUN_001054ec(iVar1,0);
    iVar2 = FUN_000f5cf0(iVar1,3,*(undefined4 *)(iVar2 + 0x10),local_50 + 4);
    if ((((iVar2 != 0) && (local_3c == FLOAT_001aa0d4)) && (local_50[4] == 2)) &&
       (local_50[0] = iVar6,
       iVar6 = ((int (*)())FUN_0014c604)(param_1,iVar1,param_2,&local_58,&local_54,local_50), iVar6 != 0)) {
      pvVar3 = (void *)FUN_001043f0(0x1c,*(undefined4 *)(param_2 + 8));
      iVar6 = FUN_001054ec(pvVar3,1);
      *(undefined4 *)(iVar6 + 0x10) = local_58;
      iVar6 = FUN_001054ec(pvVar3,2);
      *(undefined4 *)(iVar6 + 0x10) = local_54;
      if (local_50[0] == 0) {
        uVar4 = FUN_00105594(param_1,1);
        uVar5 = FUN_00105594(iVar1,2);
        ((int (*)())FUN_0014c9d0)(uVar4,uVar5);
        uVar4 = FUN_00105594(param_1,2);
        uVar5 = FUN_00105594(iVar1,1);
        ((int (*)())FUN_0014c9d0)(uVar4,uVar5);
      }
      else {
        uVar4 = FUN_00105594(param_1,1);
        uVar5 = FUN_00105594(iVar1,1);
        ((int (*)())FUN_0014c9d0)(uVar4,uVar5);
        uVar4 = FUN_00105594(param_1,2);
        uVar5 = FUN_00105594(iVar1,2);
        ((int (*)())FUN_0014c9d0)(uVar4,uVar5);
      }
      uVar4 = FUN_00105594(param_1,1);
      FUN_00106004(pvVar3,1,uVar4,0,*(undefined4 *)(param_2 + 8));
      uVar4 = FUN_00105594(param_1,2);
      FUN_00106004(pvVar3,2,uVar4,0,*(undefined4 *)(param_2 + 8));
      FUN_00103d50((int)pvVar3 + 0xa4,1,*(uint *)((int)param_1 + 0xb8) & 1);
      FUN_00103d50((int)pvVar3 + 0xbc,1,*(uint *)((int)param_1 + 0xd0) & 1);
      FUN_00103d50((int)pvVar3 + 0xa4,2,*(uint *)((int)param_1 + 0xb8) >> 1 & 1);
      FUN_00103d50((int)pvVar3 + 0xbc,2,*(uint *)((int)param_1 + 0xd0) >> 1 & 1);
      *(undefined4 *)((int)pvVar3 + 0x98) = *(undefined4 *)((int)param_1 + 0x98);
      *(undefined4 *)((int)pvVar3 + 0x94) = *(undefined4 *)((int)pvVar3 + 0x14c);
      local_50[3] = 0;
      local_50[1] = 0;
      local_50[2] = 0;
      FUN_00103f18(param_1,local_50 + 1,0xffffffff);
      FUN_00103f44(pvVar3,local_50 + 1);
      *(undefined4 *)((int)pvVar3 + 0x158) = *(undefined4 *)((int)param_1 + 0x158);
      iVar6 = FUN_001054ec(param_1,0);
      *(undefined4 *)((int)pvVar3 + 0x9c) = *(undefined4 *)(iVar6 + 0x10);
      if ((*(uint *)((int)param_1 + 0x14) & 0x200) != 0) {
        uVar4 = FUN_00105594(param_1,*(undefined4 *)((int)param_1 + 0x84));
        FUN_00106804(pvVar3,uVar4,0,*(undefined4 *)(param_2 + 8));
      }
      uVar4 = *(undefined4 *)((int)param_1 + 0x120);
      uVar5 = *(undefined4 *)((int)param_1 + 0xc);
      *(undefined4 *)((int)pvVar3 + 0x124) = *(undefined4 *)((int)param_1 + 0x124);
      *(undefined4 *)((int)pvVar3 + 0x120) = uVar4;
      *(undefined4 *)((int)pvVar3 + 0xc) = uVar5;
      iVar6 = *(int *)((int)param_1 + 4);
      FUN_0019401c(param_1);
      _memcpy(param_1,pvVar3,0x164);
      FUN_000e7738(*(undefined4 *)(iVar6 + 0x158),iVar6,param_1);
      FUN_00105894(iVar1,*(undefined4 *)(param_2 + 8));
      return 1;
    }
  }
  return 0;
}

/* FUN_0014d274 @ 0x14d274 (1664 bytes) */
int FUN_0014d274(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  
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
  iVar3 = FUN_000f31e8(param_1,1);
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = FUN_000f31e8(param_1,2);
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = FUN_00105594(param_1,1);
  iVar4 = FUN_00105594(param_1,2);
  iVar2 = *(int *)(iVar4 + 0x88);
  if ((((*(int *)(iVar2 + 8) == 0x13) && (*(int *)(iVar4 + 0x120) == 0)) &&
      (*(int *)(iVar4 + 0x124) == 0)) &&
     ((((*(uint *)(iVar4 + 0x14) & 0x200) == 0 && ((*(uint *)(iVar4 + 0xb8) & 1) == 0)) &&
      (((*(uint *)(iVar4 + 0xb8) & 2) == 0 &&
       (((*(uint *)(iVar4 + 0xd0) & 1) == 0 && ((*(uint *)(iVar4 + 0xd0) & 2) == 0)))))))) {
    iVar2 = FUN_000f31e8(iVar4,1);
    if (iVar2 != 0) {
      uVar5 = FUN_00105594(iVar4,1);
      iVar2 = FUN_00147044(iVar3,uVar5);
      if (iVar2 != 0) {
        iVar2 = FUN_00105594(iVar4,2);
        goto LAB_0014d5ac;
      }
    }
    iVar2 = *(int *)(iVar4 + 0x88);
  }
  if ((((((*(int *)(iVar2 + 8) == 0x13) && (*(int *)(iVar4 + 0x120) == 0)) &&
        (*(int *)(iVar4 + 0x124) == 0)) &&
       (((*(uint *)(iVar4 + 0x14) & 0x200) == 0 && ((*(uint *)(iVar4 + 0xb8) & 1) == 0)))) &&
      (((*(uint *)(iVar4 + 0xb8) & 2) == 0 &&
       (((*(uint *)(iVar4 + 0xd0) & 1) == 0 && ((*(uint *)(iVar4 + 0xd0) & 2) == 0)))))) &&
     (iVar2 = FUN_000f31e8(iVar4,1), iVar2 != 0)) {
    uVar5 = FUN_00105594(iVar4,2);
    iVar2 = FUN_00147044(iVar3,uVar5);
    if (iVar2 != 0) {
      iVar2 = FUN_00105594(iVar4,1);
      goto LAB_0014d5ac;
    }
  }
  iVar2 = *(int *)(iVar3 + 0x88);
  if (((((*(int *)(iVar2 + 8) == 0x13) && (*(int *)(iVar3 + 0x120) == 0)) &&
       (*(int *)(iVar3 + 0x124) == 0)) &&
      (((*(uint *)(iVar3 + 0x14) & 0x200) == 0 && ((*(uint *)(iVar3 + 0xb8) & 1) == 0)))) &&
     (((*(uint *)(iVar3 + 0xb8) & 2) == 0 &&
      (((*(uint *)(iVar3 + 0xd0) & 1) == 0 && ((*(uint *)(iVar3 + 0xd0) & 2) == 0)))))) {
    iVar2 = FUN_000f31e8(iVar3,1);
    if (iVar2 != 0) {
      uVar5 = FUN_00105594(iVar3,1);
      iVar2 = FUN_00147044(iVar4,uVar5);
      if (iVar2 != 0) {
        iVar2 = FUN_00105594(iVar3,2);
        iVar3 = iVar4;
        goto LAB_0014d5ac;
      }
    }
    iVar2 = *(int *)(iVar3 + 0x88);
  }
  if (*(int *)(iVar2 + 8) != 0x13) {
    return 0;
  }
  if (*(int *)(iVar3 + 0x120) != 0) {
    return 0;
  }
  if (*(int *)(iVar3 + 0x124) != 0) {
    return 0;
  }
  if ((*(uint *)(iVar3 + 0x14) & 0x200) != 0) {
    return 0;
  }
  if ((*(uint *)(iVar3 + 0xb8) & 1) != 0) {
    return 0;
  }
  if ((*(uint *)(iVar3 + 0xb8) & 2) != 0) {
    return 0;
  }
  if ((*(uint *)(iVar3 + 0xd0) & 1) != 0) {
    return 0;
  }
  if ((*(uint *)(iVar3 + 0xd0) & 2) != 0) {
    return 0;
  }
  iVar2 = FUN_000f31e8(iVar3,1);
  if (iVar2 == 0) {
    return 0;
  }
  uVar5 = FUN_00105594(iVar3,2);
  iVar2 = FUN_00147044(iVar4,uVar5);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = FUN_00105594(iVar3,1);
  iVar3 = iVar4;
LAB_0014d5ac:
  if ((((*(int *)(iVar2 + 0x120) == 0) && (*(int *)(iVar2 + 0x124) == 0)) &&
      ((*(uint *)(iVar2 + 0xb8) & 1) == 0)) &&
     ((((((*(uint *)(iVar2 + 0xb8) & 2) == 0 && ((*(uint *)(iVar2 + 0x14) & 0x200) == 0)) &&
        ((iVar4 = FUN_00105594(iVar2,1), *(int *)(*(int *)(iVar4 + 0x88) + 8) == 0x1c ||
         ((*(int *)(iVar4 + 0x120) == 0 && (*(int *)(iVar4 + 0x124) == 0)))))) &&
       ((*(uint *)(iVar4 + 0xb8) & 1) == 0)) &&
      ((((((*(uint *)(iVar4 + 0xb8) & 2) == 0 && ((*(uint *)(iVar4 + 0xd0) & 1) == 0)) &&
         ((*(uint *)(iVar4 + 0xd0) & 2) == 0)) &&
        ((iVar6 = FUN_000f31e8(iVar4,1), iVar6 != 0 && (iVar6 = FUN_000f31e8(iVar4,2), iVar6 != 0)))
        ) && ((*(uint *)(iVar4 + 0x14) & 0x200) == 0)))))) {
    uVar5 = FUN_00105594(iVar4,1);
    iVar6 = FUN_00147044(iVar3,uVar5);
    if (iVar6 != 0) {
      uVar5 = FUN_00105594(iVar4,2);
      iVar3 = FUN_00147044(iVar3,uVar5);
      if (iVar3 != 0) {
        iVar3 = FUN_001054ec(iVar2,0);
        iVar13 = 0;
        iVar3 = FUN_000f37b8(*(undefined4 *)(iVar3 + 0x10));
        iVar6 = FUN_001054ec(iVar4,0);
        iVar6 = FUN_000f37b8(*(undefined4 *)(iVar6 + 0x10));
        uVar1 = *(uint *)(param_1 + 0x14);
        uVar5 = *(undefined4 *)(param_1 + 0x94);
        uVar10 = *(undefined4 *)(param_1 + 0x98);
        iVar7 = FUN_00104054(param_1,param_2);
        uVar11 = *(undefined4 *)(param_1 + 0x120);
        uVar12 = *(undefined4 *)(param_1 + 0x124);
        iVar8 = FUN_001054ec(param_1,0);
        uVar15 = *(undefined4 *)(iVar8 + 0x10);
        if ((*(uint *)(param_1 + 0x14) & 0x200) != 0) {
          iVar13 = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84));
        }
        uVar9 = FUN_00105594(param_1,1);
        FUN_00105894(uVar9,*(undefined4 *)(param_2 + 8));
        uVar9 = FUN_00105594(param_1,2);
        FUN_00105894(uVar9,*(undefined4 *)(param_2 + 8));
        iVar14 = *(int *)(param_1 + 4);
        FUN_0019401c(param_1);
        FUN_00108174(param_1,0x13,*(undefined4 *)(param_2 + 8));
        *(undefined4 *)(param_1 + 0x9c) = uVar15;
        iVar8 = *(int *)(param_2 + 0x478);
        *(undefined4 *)(param_1 + 0x94) = uVar5;
        *(undefined4 *)(param_1 + 0x98) = uVar10;
        *(int *)(param_1 + 0x160) = iVar7 + iVar8;
        *(undefined4 *)(param_1 + 0x120) = uVar11;
        *(undefined4 *)(param_1 + 0x124) = uVar12;
        if ((uVar1 & 2) != 0) {
          *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 2;
        }
        if (iVar13 != 0) {
          FUN_00106804(param_1,iVar13,0,*(undefined4 *)(param_2 + 8));
          if (*(int *)(param_2 + 0x478) < *(int *)(iVar13 + 0x160)) {
            *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
          }
          else {
            *(int *)(iVar13 + 0x160) = *(int *)(param_2 + 0x478) + 1;
          }
        }
        FUN_000e7738(*(undefined4 *)(iVar14 + 0x158),iVar14,param_1);
        FUN_00106004(param_1,1,iVar4,0,*(undefined4 *)(param_2 + 8));
        uVar5 = *(undefined4 *)(PTR_DAT_001e8b8c + iVar6 * 4);
        iVar6 = FUN_001054ec(param_1,1);
        *(undefined4 *)(iVar6 + 0x10) = uVar5;
        if (*(int *)(param_2 + 0x478) < *(int *)(iVar4 + 0x160)) {
          *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
        }
        else {
          *(int *)(iVar4 + 0x160) = *(int *)(param_2 + 0x478) + 1;
        }
        FUN_00106004(param_1,2,iVar2,0,*(undefined4 *)(param_2 + 8));
        uVar5 = *(undefined4 *)(PTR_DAT_001e8b8c + iVar3 * 4);
        iVar3 = FUN_001054ec(param_1,2);
        *(undefined4 *)(iVar3 + 0x10) = uVar5;
        if (*(int *)(param_2 + 0x478) < *(int *)(iVar2 + 0x160)) {
          *(int *)(iVar2 + 0x160) = *(int *)(iVar2 + 0x160) + 1;
        }
        else {
          *(int *)(iVar2 + 0x160) = *(int *)(param_2 + 0x478) + 1;
        }
        FUN_000f35c4(param_1);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0014d8f8 @ 0x14d8f8 (2528 bytes) */
int FUN_0014d8f8(param_1, param_2)
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
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  undefined4 uVar16;
  int iVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  double dVar21;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c [4];
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) != 0x12) {
    return 0;
  }
  iVar17 = 0;
  if ((*(uint *)(param_1 + 0x14) & 0x200) != 0) {
    iVar17 = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84));
  }
  iVar8 = FUN_00105594(param_1,1);
  if (*(int *)(*(int *)(iVar8 + 0x88) + 8) == 0x12) {
    uVar9 = FUN_00105594(param_1,1);
    iVar8 = FUN_0010497c(uVar9,param_2);
    if ((iVar8 != 0) &&
       ((uint)*(byte *)(param_1 + 0xc) + (uint)*(byte *)(param_1 + 0xd) +
        (uint)*(byte *)(param_1 + 0xe) + (uint)*(byte *)(param_1 + 0xf) == 1)) {
      iVar8 = FUN_00105594(param_1,1);
      bVar1 = *(byte *)(iVar8 + 0xc);
      iVar8 = FUN_00105594(param_1,1);
      bVar2 = *(byte *)(iVar8 + 0xd);
      iVar8 = FUN_00105594(param_1,1);
      bVar3 = *(byte *)(iVar8 + 0xe);
      iVar8 = FUN_00105594(param_1,1);
      if ((uint)bVar1 + (uint)bVar2 + (uint)bVar3 + (uint)*(byte *)(iVar8 + 0xf) == 1) {
        uVar9 = FUN_00105594(param_1,1);
        uVar9 = FUN_00105594(uVar9,1);
        uVar10 = FUN_00105594(param_1,2);
        iVar8 = FUN_00147044(uVar9,uVar10);
        if (iVar8 != 0) {
          uVar9 = FUN_00105594(param_1,1);
          uVar9 = FUN_00105594(uVar9,2);
          uVar10 = FUN_00105594(param_1,2);
          iVar8 = FUN_00147044(uVar9,uVar10);
          if (((((iVar8 != 0) &&
                (iVar8 = FUN_00105594(param_1,1), (*(uint *)(iVar8 + 0xb8) & 2) == 0)) &&
               (iVar8 = FUN_00105594(param_1,1), (*(uint *)(iVar8 + 0xd0) & 2) == 0)) &&
              ((iVar8 = FUN_00105594(param_1,1), *(int *)(iVar8 + 0x120) == 0 &&
               (iVar8 = FUN_00105594(param_1,1), *(int *)(iVar8 + 0x124) == 0)))) &&
             (((*(uint *)(param_1 + 0xd0) & 2) == 0 &&
              (iVar8 = FUN_00105594(param_1,1),
              (*(uint *)(iVar8 + 0xb8) & 1) == (*(uint *)(param_1 + 0xd0) & 1))))) {
            iVar8 = FUN_00105594(param_1,1);
            uVar15 = *(uint *)(iVar8 + 0xd0) & 1;
            if (uVar15 == (*(uint *)(param_1 + 0xd0) & 1)) {
              iVar8 = FUN_00105594(param_1,1);
              uVar9 = 2;
              goto LAB_0014dd2c;
            }
          }
        }
      }
    }
  }
  iVar8 = FUN_00105594(param_1,2);
  if (*(int *)(*(int *)(iVar8 + 0x88) + 8) != 0x12) {
    return 0;
  }
  uVar9 = FUN_00105594(param_1,2);
  iVar8 = FUN_0010497c(uVar9,param_2);
  if (iVar8 == 0) {
    return 0;
  }
  if ((uint)*(byte *)(param_1 + 0xc) + (uint)*(byte *)(param_1 + 0xd) +
      (uint)*(byte *)(param_1 + 0xe) + (uint)*(byte *)(param_1 + 0xf) != 1) {
    return 0;
  }
  iVar8 = FUN_00105594(param_1,2);
  bVar1 = *(byte *)(iVar8 + 0xc);
  iVar8 = FUN_00105594(param_1,2);
  bVar2 = *(byte *)(iVar8 + 0xd);
  iVar8 = FUN_00105594(param_1,2);
  bVar3 = *(byte *)(iVar8 + 0xe);
  iVar8 = FUN_00105594(param_1,2);
  if ((uint)bVar1 + (uint)bVar2 + (uint)bVar3 + (uint)*(byte *)(iVar8 + 0xf) != 1) {
    return 0;
  }
  uVar9 = FUN_00105594(param_1,2);
  uVar9 = FUN_00105594(uVar9,1);
  uVar10 = FUN_00105594(param_1,1);
  iVar8 = FUN_00147044(uVar9,uVar10);
  if (iVar8 == 0) {
    return 0;
  }
  uVar9 = FUN_00105594(param_1,2);
  uVar9 = FUN_00105594(uVar9,2);
  uVar10 = FUN_00105594(param_1,1);
  iVar8 = FUN_00147044(uVar9,uVar10);
  if (iVar8 == 0) {
    return 0;
  }
  iVar8 = FUN_00105594(param_1,2);
  if ((*(uint *)(iVar8 + 0xb8) & 2) != 0) {
    return 0;
  }
  iVar8 = FUN_00105594(param_1,2);
  if ((*(uint *)(iVar8 + 0xd0) & 2) != 0) {
    return 0;
  }
  iVar8 = FUN_00105594(param_1,2);
  if (*(int *)(iVar8 + 0x120) != 0) {
    return 0;
  }
  iVar8 = FUN_00105594(param_1,2);
  if (*(int *)(iVar8 + 0x124) != 0) {
    return 0;
  }
  if ((*(uint *)(param_1 + 0xb8) & 2) != 0) {
    return 0;
  }
  iVar8 = FUN_00105594(param_1,2);
  if ((*(uint *)(iVar8 + 0xb8) & 1) != (*(uint *)(param_1 + 0xb8) & 1)) {
    return 0;
  }
  iVar8 = FUN_00105594(param_1,2);
  uVar15 = *(uint *)(iVar8 + 0xd0) & 1;
  if (uVar15 != (*(uint *)(param_1 + 0xb8) & 1)) {
    return 0;
  }
  iVar8 = FUN_00105594(param_1,2);
  uVar9 = 1;
LAB_0014dd2c:
  iVar11 = FUN_001054ec(iVar8,0);
  uVar18 = *(undefined4 *)(iVar11 + 0x10);
  iVar11 = FUN_001054ec(param_1,0);
  uVar10 = *(undefined4 *)(iVar11 + 0x10);
  iVar11 = FUN_001054ec(iVar8,1);
  local_60 = *(undefined4 *)(iVar11 + 0x10);
  iVar11 = FUN_000f37b8(uVar18);
  uVar4 = *(undefined1 *)((int)&local_60 + iVar11);
  iVar11 = FUN_001054ec(iVar8,2);
  local_64 = *(undefined4 *)(iVar11 + 0x10);
  iVar11 = FUN_000f37b8(uVar18);
  uVar5 = *(undefined1 *)((int)&local_64 + iVar11);
  iVar11 = FUN_001054ec(param_1,uVar9);
  local_68 = *(undefined4 *)(iVar11 + 0x10);
  iVar11 = FUN_000f37b8(uVar10);
  uVar6 = *(undefined1 *)((int)&local_68 + iVar11);
  local_5c = CONCAT13(uVar4,CONCAT12(uVar5,4));
  (*(unsigned short *)((unsigned char *)&(local_5c) + 2)) = CONCAT11(uVar6,4);
  piVar12 = (int *)FUN_00105594(iVar8,1);
  iVar11 = (**(code **)(*piVar12 + 0x5c))();
  piVar12 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
  iVar13 = (**(code **)(*piVar12 + 0x108))(piVar12,&local_5c);
  if (iVar13 == 0) {
    (*(unsigned short *)((unsigned char *)&(local_5c) + 2)) = CONCAT11(uVar5,(undefined1)local_5c);
    local_5c = CONCAT22(CONCAT11(uVar4,uVar6),(*(unsigned short *)((unsigned char *)&(local_5c) + 2)));
  }
  piVar12 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
  iVar13 = (**(code **)(*piVar12 + 0x108))(piVar12,&local_5c);
  if (iVar13 == 0) {
    (*(unsigned short *)((unsigned char *)&(local_5c) + 2)) = CONCAT11(uVar4,(undefined1)local_5c);
    local_5c = CONCAT22(CONCAT11(uVar6,uVar5),(*(unsigned short *)((unsigned char *)&(local_5c) + 2)));
  }
  piVar12 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
  iVar13 = (**(code **)(*piVar12 + 0x108))(piVar12,&local_5c);
  if (iVar13 == 0) {
    (*(unsigned short *)((unsigned char *)&(local_5c) + 2)) = CONCAT11(uVar5,(undefined1)local_5c);
    local_5c = CONCAT22(CONCAT11(uVar6,uVar4),(*(unsigned short *)((unsigned char *)&(local_5c) + 2)));
  }
  piVar12 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
  iVar13 = (**(code **)(*piVar12 + 0x108))(piVar12,&local_5c);
  if (iVar13 == 0) {
    (*(unsigned short *)((unsigned char *)&(local_5c) + 2)) = CONCAT11(uVar4,(undefined1)local_5c);
    local_5c = CONCAT22(CONCAT11(uVar5,uVar6),(*(unsigned short *)((unsigned char *)&(local_5c) + 2)));
  }
  piVar12 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
  iVar13 = (**(code **)(*piVar12 + 0x108))(piVar12,&local_5c);
  if (iVar13 == 0) {
    (*(unsigned short *)((unsigned char *)&(local_5c) + 2)) = CONCAT11(uVar6,(undefined1)local_5c);
    local_5c = CONCAT22(CONCAT11(uVar5,uVar4),(*(unsigned short *)((unsigned char *)&(local_5c) + 2)));
  }
  if ((iVar11 != 0) &&
     (piVar12 = *(int **)(*(int *)(param_2 + 8) + 0x30c),
     iVar13 = (**(code **)(*piVar12 + 0x108))(piVar12,&local_5c), iVar13 == 0)) {
    return 0;
  }
  piVar12 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
  iVar13 = (**(code **)(*piVar12 + 0x108))(piVar12,&local_5c);
  if (iVar13 == 0) {
    piVar12 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
    iVar13 = (**(code **)(*piVar12 + 0x100))(piVar12,&local_5c);
    if (iVar13 == 0) {
      (*(unsigned short *)((unsigned char *)&(local_5c) + 2)) = CONCAT11(uVar5,(undefined1)local_5c);
      local_5c = CONCAT22(CONCAT11(uVar4,uVar6),(*(unsigned short *)((unsigned char *)&(local_5c) + 2)));
    }
    piVar12 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
    iVar13 = (**(code **)(*piVar12 + 0x100))(piVar12,&local_5c);
    if (iVar13 == 0) {
      (*(unsigned short *)((unsigned char *)&(local_5c) + 2)) = CONCAT11(uVar4,(undefined1)local_5c);
      local_5c = CONCAT22(CONCAT11(uVar6,uVar5),(*(unsigned short *)((unsigned char *)&(local_5c) + 2)));
    }
    piVar12 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
    iVar13 = (**(code **)(*piVar12 + 0x100))(piVar12,&local_5c);
    if (iVar13 == 0) {
      (*(unsigned short *)((unsigned char *)&(local_5c) + 2)) = CONCAT11(uVar5,(undefined1)local_5c);
      local_5c = CONCAT22(CONCAT11(uVar6,uVar4),(*(unsigned short *)((unsigned char *)&(local_5c) + 2)));
    }
    piVar12 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
    iVar13 = (**(code **)(*piVar12 + 0x100))(piVar12,&local_5c);
    if (iVar13 == 0) {
      (*(unsigned short *)((unsigned char *)&(local_5c) + 2)) = CONCAT11(uVar4,(undefined1)local_5c);
      local_5c = CONCAT22(CONCAT11(uVar5,uVar6),(*(unsigned short *)((unsigned char *)&(local_5c) + 2)));
    }
    piVar12 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
    iVar13 = (**(code **)(*piVar12 + 0x100))(piVar12,&local_5c);
    if (iVar13 == 0) {
      (*(unsigned short *)((unsigned char *)&(local_5c) + 2)) = CONCAT11(uVar6,(undefined1)local_5c);
      local_5c = CONCAT22(CONCAT11(uVar5,uVar4),(*(unsigned short *)((unsigned char *)&(local_5c) + 2)));
    }
    piVar12 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
    iVar13 = (**(code **)(*piVar12 + 0x100))(piVar12,&local_5c);
    if (iVar13 == 0) {
      return 0;
    }
  }
  iVar13 = FUN_00105594(iVar8,1);
  if (iVar11 != 0) {
    iVar11 = FUN_001054ec(iVar13,0);
    uVar20 = *(undefined4 *)(iVar11 + 0x10);
    uVar18 = FUN_00105594(iVar8,2);
    iVar11 = FUN_001054ec(uVar18,0);
    FUN_000f2f84(&local_58,uVar20,*(undefined4 *)(iVar11 + 0x10));
    uVar18 = FUN_00105594(param_1,uVar9);
    iVar11 = FUN_001054ec(uVar18,0);
    FUN_000f2f84(&local_54,local_58,*(undefined4 *)(iVar11 + 0x10));
    uVar18 = DAT_001b004c;
    *(undefined4 *)(iVar13 + 0x9c) = local_54;
    FUN_000f3908(&local_50,local_54);
    FUN_000f3340(local_4c,uVar18,local_50);
    iVar11 = FUN_001054ec(iVar13,1);
    *(undefined4 *)(iVar11 + 0x10) = local_4c[0];
    iVar11 = FUN_001054ec(iVar13,2);
    *(undefined4 *)(iVar11 + 0x10) = local_4c[0];
  }
  uVar7 = *(uint *)(param_1 + 0x14);
  uVar18 = *(undefined4 *)(param_1 + 0x94);
  uVar20 = *(undefined4 *)(param_1 + 0x98);
  iVar14 = FUN_00104054(param_1,param_2);
  uVar16 = *(undefined4 *)(param_1 + 0x120);
  uVar19 = *(undefined4 *)(param_1 + 0x124);
  uVar9 = FUN_00105594(param_1,uVar9);
  FUN_00105894(uVar9,*(undefined4 *)(param_2 + 8));
  FUN_0019401c(param_1);
  FUN_00108174(param_1,0x1c,*(undefined4 *)(param_2 + 8));
  *(undefined4 *)(param_1 + 0x9c) = uVar10;
  iVar11 = *(int *)(param_2 + 0x478);
  *(undefined4 *)(param_1 + 0x94) = uVar18;
  *(undefined4 *)(param_1 + 0x98) = uVar20;
  *(int *)(param_1 + 0x160) = iVar14 + iVar11;
  *(undefined4 *)(param_1 + 0x120) = uVar16;
  *(undefined4 *)(param_1 + 0x124) = uVar19;
  if ((uVar7 & 2) != 0) {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 2;
  }
  if (iVar17 != 0) {
    FUN_00106804(param_1,iVar17,0,*(undefined4 *)(param_2 + 8));
    if (*(int *)(param_2 + 0x478) < *(int *)(iVar17 + 0x160)) {
      *(int *)(iVar17 + 0x160) = *(int *)(iVar17 + 0x160) + 1;
    }
    else {
      *(int *)(iVar17 + 0x160) = *(int *)(param_2 + 0x478) + 1;
    }
  }
  FUN_000e7738(*(undefined4 *)(iVar8 + 0x158),iVar8,param_1);
  FUN_00106004(param_1,1,iVar13,0,*(undefined4 *)(param_2 + 8));
  FUN_00103d50(param_1 + 0xa4,1,uVar15);
  uVar9 = local_5c;
  iVar17 = FUN_001054ec(param_1,1);
  *(undefined4 *)(iVar17 + 0x10) = uVar9;
  iVar17 = FUN_00105594(iVar8,1);
  if (*(int *)(param_2 + 0x478) < *(int *)(iVar17 + 0x160)) {
    *(int *)(iVar17 + 0x160) = *(int *)(iVar17 + 0x160) + 1;
  }
  else {
    *(int *)(iVar17 + 0x160) = *(int *)(param_2 + 0x478) + 1;
  }
  dVar21 = (double)FLOAT_001aa0e8;
  FUN_000f79c4(dVar21,dVar21,dVar21,dVar21,param_1,param_2,2);
  FUN_00105894(iVar8,*(undefined4 *)(param_2 + 8));
  return 1;
}

/* FUN_0014e2dc @ 0x14e2dc (1032 bytes) */
int FUN_0014e2dc(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  
  iVar1 = FUN_001054ec(param_1,0);
  iVar9 = *(int *)(iVar1 + 0x10);
  iVar1 = FUN_001054ec(param_2,0);
  if ((((iVar9 == *(int *)(iVar1 + 0x10)) && (param_1[0x48] == param_2[0x48])) &&
      (param_1[0x49] == param_2[0x49])) && (param_1[0x21] == param_2[0x21])) {
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
    iVar1 = iVar1 + 1;
    if (iVar1 <= param_1[0x21]) {
      do {
        iVar9 = FUN_00105594(param_1,iVar1);
        iVar2 = FUN_00105594(param_2,iVar1);
        if (iVar9 != iVar2) {
          return;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 <= param_1[0x21]);
    }
    iVar1 = FUN_00105594(param_1,1);
    iVar9 = FUN_00105594(param_2,1);
    if (iVar1 == iVar9) {
      iVar1 = FUN_00105594(param_1,2);
      iVar9 = FUN_00105594(param_2,2);
      if (iVar1 == iVar9) {
        iVar1 = FUN_001054ec(param_1,1);
        iVar9 = *(int *)(iVar1 + 0x10);
        iVar1 = FUN_001054ec(param_2,1);
        if (iVar9 == *(int *)(iVar1 + 0x10)) {
          iVar1 = FUN_001054ec(param_1,2);
          iVar9 = *(int *)(iVar1 + 0x10);
          iVar1 = FUN_001054ec(param_2,2);
          if (iVar9 == *(int *)(iVar1 + 0x10)) {
            if ((param_1[0x2e] & 1U) == (param_2[0x2e] & 1U)) {
              if ((((param_1[0x34] & 1U) == (param_2[0x34] & 1U)) &&
                  (((uint)param_1[0x2e] >> 1 & 1) == ((uint)param_2[0x2e] >> 1 & 1))) &&
                 (((uint)param_1[0x34] >> 1 & 1) == ((uint)param_2[0x34] >> 1 & 1)))
              goto LAB_0014e578;
            }
          }
        }
      }
    }
    iVar1 = FUN_00105594(param_1,1);
    iVar9 = FUN_00105594(param_2,2);
    if (iVar1 == iVar9) {
      iVar1 = FUN_00105594(param_1,2);
      iVar9 = FUN_00105594(param_2,1);
      if (iVar1 == iVar9) {
        iVar1 = FUN_001054ec(param_1,1);
        iVar9 = *(int *)(iVar1 + 0x10);
        iVar1 = FUN_001054ec(param_2,2);
        if (iVar9 == *(int *)(iVar1 + 0x10)) {
          iVar1 = FUN_001054ec(param_1,2);
          iVar9 = *(int *)(iVar1 + 0x10);
          iVar1 = FUN_001054ec(param_2,1);
          if (iVar9 == *(int *)(iVar1 + 0x10)) {
            if ((param_1[0x2e] & 1U) == (param_2[0x34] & 1U)) {
              if ((((param_1[0x34] & 1U) == (param_2[0x2e] & 1U)) &&
                  (((uint)param_1[0x2e] >> 1 & 1) == ((uint)param_2[0x34] >> 1 & 1))) &&
                 (((uint)param_1[0x34] >> 1 & 1) == ((uint)param_2[0x2e] >> 1 & 1))) {
LAB_0014e578:
                puVar10 = (uint *)param_2[4];
                uVar6 = puVar10[1];
                uVar7 = uVar6 - 1;
                if ((int)uVar7 < 0) {
LAB_0014e690:
                  (**(code **)(*param_2 + 0xc))(param_2,1,*(undefined4 *)(param_3 + 8));
                  FUN_001474c8(param_3,param_1,param_3);
                  return;
                }
                iVar1 = uVar7 * 4;
                uVar5 = 0;
                do {
                  if (uVar7 < *puVar10) {
                    uVar3 = puVar10[1];
                    if (uVar3 <= uVar7) {
                      _memset((void *)(uVar3 * 4 + puVar10[2]),0,(uVar7 - uVar3) * 4 + 4);
                      puVar10[1] = uVar7 + 1;
                    }
                    piVar4 = (int *)(iVar1 + puVar10[2]);
                  }
                  else {
                    piVar4 = (int *)FUN_0019423c(puVar10,uVar7);
                  }
                  iVar9 = *piVar4;
                  iVar2 = *(int *)(iVar9 + 0x84);
                  if ((*(uint *)(iVar9 + 0x14) & 0x200) == 0) {
LAB_0014e650:
                    if (0 < iVar2) {
                      iVar8 = 1;
                      do {
                        piVar4 = (int *)FUN_00105594(iVar9,iVar8);
                        if (param_2 == piVar4) {
                          FUN_00106004(iVar9,iVar8,param_1,1,*(undefined4 *)(param_3 + 8));
                          break;
                        }
                        iVar8 = iVar8 + 1;
                      } while (iVar8 <= iVar2);
                    }
                  }
                  else {
                    piVar4 = (int *)FUN_00105594(iVar9,iVar2);
                    iVar2 = iVar2 + -1;
                    if (param_2 != piVar4) goto LAB_0014e650;
                    FUN_00106804(iVar9,param_1,1,*(undefined4 *)(param_3 + 8));
                  }
                  uVar5 = uVar5 + 1;
                  uVar7 = uVar7 - 1;
                  iVar1 = iVar1 + -4;
                  if (uVar6 == uVar5) goto LAB_0014e690;
                  puVar10 = (uint *)param_2[4];
                } while( true );
              }
            }
          }
        }
      }
    }
  }
  return;
}

/* FUN_0014e6e4 @ 0x14e6e4 (744 bytes) */
int FUN_0014e6e4(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  uint local_48;
  uint local_44;
  int local_40;
  undefined4 local_3c;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  if ((iVar1 == 0x12) || (iVar1 == 0x13)) {
    uVar7 = FUN_00105594(param_1,1);
    uVar8 = FUN_00105594(param_1,2);
    iVar1 = FUN_0010497c(uVar7,param_2);
    if ((iVar1 == 0) &&
       (((iVar1 = FUN_001049c4(uVar7,param_2), iVar1 == 0 &&
         (iVar1 = FUN_0010497c(uVar8,param_2), iVar1 == 0)) &&
        (local_44 = FUN_001049c4(uVar8,param_2), local_44 == 0)))) {
      local_3c = *(undefined4 *)(*(int *)(param_2 + 8) + 0x378);
      local_48 = 2;
      local_40 = FUN_00193e18(local_3c,8);
      iVar9 = *(int *)(*(int *)(param_1 + 0x88) + 8);
      iVar1 = FUN_00105594(param_1,1);
      puVar13 = *(uint **)(iVar1 + 0x10);
      uVar2 = puVar13[1];
      uVar14 = uVar2 - 1;
      if (-1 < (int)uVar14) {
        iVar11 = uVar14 * 4;
        uVar10 = 0;
        do {
          if (uVar14 < *puVar13) {
            uVar3 = puVar13[1];
            if (uVar3 <= uVar14) {
              _memset((void *)(uVar3 * 4 + puVar13[2]),0,(uVar14 - uVar3) * 4 + 4);
              puVar13[1] = uVar14 + 1;
            }
            piVar4 = (int *)(iVar11 + puVar13[2]);
          }
          else {
            piVar4 = (int *)FUN_0019423c(puVar13,uVar14);
          }
          iVar12 = *piVar4;
          if ((iVar9 == *(int *)(*(int *)(iVar12 + 0x88) + 8)) && (param_1 != iVar12)) {
            iVar5 = FUN_00105594(iVar12,1);
            iVar6 = FUN_00105594(param_1,1);
            if (iVar5 == iVar6) {
              iVar5 = FUN_00105594(iVar12,2);
              iVar6 = FUN_00105594(param_1,2);
              if (iVar5 != iVar6) goto LAB_0014e874;
LAB_0014e8bc:
              uVar3 = local_44;
              if (local_44 < local_48) {
                iVar5 = local_44 * 4;
                _memset((void *)(iVar5 + local_40),0,4);
                local_44 = uVar3 + 1;
                piVar4 = (int *)(iVar5 + local_40);
              }
              else {
                piVar4 = (int *)FUN_0019423c(&local_48,local_44);
              }
              *piVar4 = iVar12;
            }
            else {
LAB_0014e874:
              iVar5 = FUN_00105594(iVar12,2);
              iVar6 = FUN_00105594(param_1,1);
              if (iVar5 == iVar6) {
                iVar5 = FUN_00105594(iVar12,1);
                iVar6 = FUN_00105594(param_1,2);
                if (iVar5 == iVar6) goto LAB_0014e8bc;
              }
            }
          }
          uVar10 = uVar10 + 1;
          uVar14 = uVar14 - 1;
          iVar11 = iVar11 + -4;
          if (uVar10 == uVar2) break;
          puVar13 = *(uint **)(iVar1 + 0x10);
        } while( true );
      }
      while (local_44 != 0) {
        piVar4 = (int *)0x0;
        if (local_44 - 1 < local_44) {
          piVar4 = (int *)((local_44 - 1) * 4 + local_40);
        }
        iVar1 = *piVar4;
        FUN_00194208(&local_48);
        if ((*(uint *)(iVar1 + 0x14) & 1) != 0) {
          ((int (*)())FUN_0014e2dc)(param_1,iVar1,param_2);
        }
      }
      FUN_00193cc0(local_3c,local_40);
    }
  }
  return;
}

/* FUN_0014e9e4 @ 0x14e9e4 (2620 bytes) */
int FUN_0014e9e4(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint local_b8 [21];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54 [3];
  
  iVar13 = *param_1;
  bVar1 = *(int *)(*(int *)(iVar13 + 0x88) + 8) == 0x13;
  if (bVar1) {
    iVar13 = FUN_0014699c();
    if (iVar13 == 0) {
      return 0;
    }
    iVar13 = *param_1;
  }
  iVar2 = FUN_00105594(*param_2,param_2[1]);
  if ((iVar13 != iVar2) &&
     (iVar2 = *param_2, iVar13 = FUN_00105594(*param_1,param_1[1]), iVar2 != iVar13)) {
    uVar3 = FUN_00105594(*param_1,param_1[1]);
    local_b8[6] = FUN_00105594(uVar3,1);
    uVar3 = FUN_00105594(*param_1,param_1[1]);
    local_b8[7] = FUN_00105594(uVar3,2);
    uVar3 = FUN_00105594(*param_1,param_1[1]);
    iVar13 = FUN_001054ec(uVar3,1);
    local_b8[0] = *(uint *)(iVar13 + 0x10);
    uVar3 = FUN_00105594(*param_1,param_1[1]);
    iVar13 = FUN_001054ec(uVar3,2);
    local_b8[1] = *(undefined4 *)(iVar13 + 0x10);
    iVar13 = FUN_00105594(*param_1,param_1[1]);
    local_b8[2] = *(uint *)(iVar13 + 0xb8) & 1;
    iVar13 = FUN_00105594(*param_1,param_1[1]);
    local_b8[3] = *(uint *)(iVar13 + 0xd0) & 1;
    iVar13 = FUN_00105594(*param_1,param_1[1]);
    local_b8[4] = *(uint *)(iVar13 + 0xb8) >> 1 & 1;
    iVar13 = FUN_00105594(*param_1,param_1[1]);
    local_b8[5] = *(uint *)(iVar13 + 0xd0) >> 1 & 1;
    uVar3 = FUN_00105594(*param_2,param_2[1]);
    local_b8[0xb] = FUN_00105594(uVar3,1);
    uVar3 = FUN_00105594(*param_2,param_2[1]);
    local_b8[0xc] = FUN_00105594(uVar3,2);
    uVar7 = param_2[1];
    uVar3 = FUN_00105594(*param_2,uVar7 + (((int)uVar7 >> 1) +
                                          (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0)) * -2 + 1);
    local_b8[0xd] = uVar3;
    uVar4 = FUN_00105594(*param_2,param_2[1]);
    iVar13 = FUN_001054ec(uVar4,1);
    local_b8[0xe] = *(undefined4 *)(iVar13 + 0x10);
    uVar4 = FUN_00105594(*param_2,param_2[1]);
    iVar13 = FUN_001054ec(uVar4,2);
    uVar7 = param_2[1];
    local_b8[0xf] = *(undefined4 *)(iVar13 + 0x10);
    iVar13 = FUN_001054ec(*param_2,uVar7 + (((int)uVar7 >> 1) +
                                           (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0)) * -2 + 1);
    uVar7 = local_b8[0xe];
    local_b8[0x10] = *(undefined4 *)(iVar13 + 0x10);
    iVar13 = FUN_001054ec(*param_2,param_2[1]);
    FUN_000f2bdc(&local_58,uVar7,*(undefined4 *)(iVar13 + 0x10));
    uVar7 = local_b8[0xf];
    local_b8[0xe] = local_58;
    iVar13 = FUN_001054ec(*param_2,param_2[1]);
    FUN_000f2bdc(local_54,uVar7,*(undefined4 *)(iVar13 + 0x10));
    local_b8[0xf] = local_54[0];
    iVar13 = FUN_00105594(*param_2,param_2[1]);
    local_b8[0x11] = *(uint *)(iVar13 + 0xb8) & 1;
    iVar13 = FUN_00105594(*param_2,param_2[1]);
    uVar7 = param_2[1];
    local_b8[0x12] = *(uint *)(iVar13 + 0xd0) & 1;
    local_b8[0x13] =
         *(uint *)((uVar7 + (((int)uVar7 >> 1) + (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0)) * -2) *
                   0x18 + *param_2 + 0xb8) & 1;
    if (!bVar1) {
      iVar13 = *param_2 + uVar7 * 0x18 + 0x80;
      local_b8[0x11] = (uint)((*(uint *)(iVar13 + 0x20) & 1) != local_b8[0x11]);
      local_b8[0x12] = *(uint *)(iVar13 + 0x20) & 1 ^ local_b8[0x12];
    }
    iVar13 = FUN_00105594();
    iVar11 = 1;
    local_b8[8] = *(uint *)(iVar13 + 0xb8) >> 1 & 1;
    iVar12 = 0;
    iVar13 = FUN_00105594(*param_2,param_2[1]);
    uVar7 = param_2[1];
    iVar2 = 0;
    local_b8[9] = *(uint *)(iVar13 + 0xd0) >> 1 & 1;
    uVar7 = *(uint *)((uVar7 + (((int)uVar7 >> 1) + (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0)) * -2
                      ) * 0x18 + *param_2 + 0xb8) >> 1 & 1;
    local_b8[10] = uVar7;
    iVar13 = 0;
    do {
      iVar14 = iVar13 + 1;
      uVar8 = *(uint *)((int)local_b8 + iVar2 + 0x18);
      uVar9 = *(uint *)((int)local_b8 + iVar12 + 0x2c);
      iVar10 = iVar14 % 3;
      if ((uVar9 == uVar8) && (local_b8[iVar10 + 0xb] == local_b8[iVar11 + 6])) {
LAB_0014edd0:
        if (((bVar1) ||
            ((((*(int *)((int)local_b8 + iVar2 + 0x10) == *(int *)((int)local_b8 + iVar12 + 0x20) &&
               (local_b8[iVar11 + 4] == local_b8[iVar10 + 8])) &&
              (*(int *)((int)local_b8 + iVar2 + 8) == *(int *)((int)local_b8 + iVar12 + 0x44))) &&
             (local_b8[iVar11 + 2] == local_b8[iVar10 + 0x11])))) &&
           ((iVar5 = FUN_000f2da8(*(undefined4 *)((int)local_b8 + iVar2),
                                  *(undefined4 *)((int)local_b8 + iVar12 + 0x38)), iVar5 != 0 &&
            (iVar10 = FUN_000f2da8(local_b8[iVar11],local_b8[iVar10 + 0xe]), iVar10 != 0)))) {
          if (param_4 != 0) {
            if (iVar13 == 2) {
              uVar4 = FUN_00105594(*param_2,param_2[1]);
              FUN_00106004(uVar4,2,uVar3,1,*(undefined4 *)(param_3 + 8));
              iVar13 = FUN_00105594(*param_2,param_2[1]);
              FUN_00103d50(iVar13 + 0xbc,1,local_b8[0x13]);
              iVar13 = FUN_00105594(*param_2,param_2[1]);
              FUN_00103d50(iVar13 + 0xbc,2,uVar7);
              uVar3 = FUN_00105594(*param_2,param_2[1]);
              uVar7 = local_b8[0x10];
              iVar13 = FUN_001054ec(uVar3,2);
              *(uint *)(iVar13 + 0x10) = uVar7;
              iVar13 = FUN_00105594(*param_2,param_2[1]);
              FUN_00103d50(iVar13 + 0xa4,1,local_b8[0x11]);
              iVar13 = FUN_00105594(*param_2,param_2[1]);
              FUN_00103d50(iVar13 + 0xa4,2,local_b8[8]);
              uVar3 = FUN_00105594(*param_2,param_2[1]);
              uVar7 = local_b8[0xe];
              iVar13 = FUN_001054ec(uVar3,1);
              *(uint *)(iVar13 + 0x10) = uVar7;
              uVar7 = param_2[1];
              FUN_00106004(*param_2,uVar7 + (((int)uVar7 >> 1) +
                                            (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0)) * -2 + 1,
                           local_b8[0xc],1,*(undefined4 *)(param_3 + 8));
              uVar7 = local_b8[0xf];
              uVar8 = param_2[1];
              iVar13 = FUN_001054ec(*param_2,uVar8 + (((int)uVar8 >> 1) +
                                                     (uint)((int)uVar8 < 0 && (uVar8 & 1) != 0)) *
                                                     -2 + 1);
              *(uint *)(iVar13 + 0x10) = uVar7;
              uVar7 = param_2[1];
              FUN_00103d50((uVar7 + (((int)uVar7 >> 1) + (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0))
                                    * -2) * 0x18 + *param_2 + 0xa4,1,local_b8[0x12]);
              uVar7 = param_2[1];
              FUN_00103d50((uVar7 + (((int)uVar7 >> 1) + (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0))
                                    * -2) * 0x18 + *param_2 + 0xa4,2,local_b8[9]);
              if (!bVar1) {
                FUN_00103d50(param_2[1] * 0x18 + *param_2 + 0x8c,1,0);
              }
              uVar3 = DAT_001b004c;
              iVar11 = *param_2;
              iVar2 = param_2[1];
              iVar13 = FUN_001054ec(iVar11,0);
              FUN_000f3908(local_b8 + 0x14,*(undefined4 *)(iVar13 + 0x10));
              FUN_000f3340(&local_64,uVar3,local_b8[0x14]);
              iVar13 = FUN_001054ec(iVar11,iVar2);
              *(undefined4 *)(iVar13 + 0x10) = local_64;
            }
            else if (iVar13 == 1) {
              uVar4 = FUN_00105594(*param_2,param_2[1]);
              FUN_00106004(uVar4,1,uVar3,1,*(undefined4 *)(param_3 + 8));
              iVar13 = FUN_00105594(*param_2,param_2[1]);
              FUN_00103d50(iVar13 + 0xa4,1,local_b8[0x13]);
              iVar13 = FUN_00105594(*param_2,param_2[1]);
              FUN_00103d50(iVar13 + 0xa4,2,uVar7);
              uVar3 = FUN_00105594(*param_2,param_2[1]);
              uVar7 = local_b8[0x10];
              iVar13 = FUN_001054ec(uVar3,1);
              *(uint *)(iVar13 + 0x10) = uVar7;
              iVar13 = FUN_00105594(*param_2,param_2[1]);
              FUN_00103d50(iVar13 + 0xbc,1,local_b8[0x12]);
              iVar13 = FUN_00105594(*param_2,param_2[1]);
              FUN_00103d50(iVar13 + 0xbc,2,local_b8[9]);
              uVar3 = FUN_00105594(*param_2,param_2[1]);
              uVar7 = local_b8[0xf];
              iVar13 = FUN_001054ec(uVar3,2);
              *(uint *)(iVar13 + 0x10) = uVar7;
              uVar7 = param_2[1];
              FUN_00106004(*param_2,uVar7 + (((int)uVar7 >> 1) +
                                            (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0)) * -2 + 1,
                           local_b8[0xb],1,*(undefined4 *)(param_3 + 8));
              uVar7 = local_b8[0xe];
              uVar8 = param_2[1];
              iVar13 = FUN_001054ec(*param_2,uVar8 + (((int)uVar8 >> 1) +
                                                     (uint)((int)uVar8 < 0 && (uVar8 & 1) != 0)) *
                                                     -2 + 1);
              *(uint *)(iVar13 + 0x10) = uVar7;
              uVar7 = param_2[1];
              FUN_00103d50((uVar7 + (((int)uVar7 >> 1) + (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0))
                                    * -2) * 0x18 + *param_2 + 0xa4,1,local_b8[0x11]);
              uVar7 = param_2[1];
              FUN_00103d50((uVar7 + (((int)uVar7 >> 1) + (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0))
                                    * -2) * 0x18 + *param_2 + 0xa4,2,local_b8[8]);
              if (!bVar1) {
                FUN_00103d50(param_2[1] * 0x18 + *param_2 + 0x8c,1,0);
              }
              uVar3 = DAT_001b004c;
              iVar11 = *param_2;
              iVar2 = param_2[1];
              iVar13 = FUN_001054ec(iVar11,0);
              FUN_000f3908(&local_60,*(undefined4 *)(iVar13 + 0x10));
              FUN_000f3340(&local_5c,uVar3,local_60);
              iVar13 = FUN_001054ec(iVar11,iVar2);
              *(undefined4 *)(iVar13 + 0x10) = local_5c;
            }
            uVar3 = FUN_00105594(*param_2,param_2[1]);
            iVar13 = FUN_001054ec(uVar3,1);
            uVar7 = *(uint *)(iVar13 + 0x10);
            uVar3 = FUN_00105594(*param_2,param_2[1]);
            iVar13 = FUN_001054ec(uVar3,2);
            uVar8 = *(uint *)(iVar13 + 0x10);
            uVar3 = FUN_00105594(*param_2,param_2[1]);
            FUN_001054ec(uVar3,0);
            if ((uVar7 >> 0x18 != 4) || (iVar13 = 1, uVar8 >> 0x18 != 4)) {
              iVar13 = 0;
            }
            if (((uVar7 >> 0x10 & 0xff) != 4) || (iVar2 = 1, (uVar8 >> 0x10 & 0xff) != 4)) {
              iVar2 = 0;
            }
            if (((uVar7 >> 8 & 0xff) != 4) || (iVar11 = 1, (uVar8 >> 8 & 0xff) != 4)) {
              iVar11 = 0;
            }
            if (((uVar7 & 0xff) != 4) || (uVar7 = 1, (uVar8 & 0xff) != 4)) {
              uVar7 = 0;
            }
            iVar12 = FUN_00105594(*param_2,param_2[1]);
            *(uint *)(iVar12 + 0x9c) = uVar7 | iVar11 << 8 | iVar2 << 0x10 | iVar13 << 0x18;
            uVar3 = FUN_00105594(*param_1,param_1[1]);
            FUN_001474c8(param_3,uVar3,param_3);
            if (param_5 != 0) {
              piVar6 = (int *)FUN_00105594(*param_2,param_2[1]);
              iVar13 = param_2[1];
              iVar2 = *param_2;
              uVar3 = FUN_00105594(*param_1,param_1[1]);
              FUN_00106004(iVar2,iVar13,uVar3,1,*(undefined4 *)(param_3 + 8));
              iVar13 = FUN_001049c4(piVar6,param_3);
              if (iVar13 != 0) {
                (**(code **)(*piVar6 + 0xc))(piVar6,1,*(undefined4 *)(param_3 + 8));
                return 1;
              }
            }
          }
          return 1;
        }
      }
      else if ((uVar9 == local_b8[iVar11 + 6]) && (uVar8 == local_b8[iVar10 + 0xb])) {
        iVar11 = 0;
        iVar2 = 4;
        goto LAB_0014edd0;
      }
      iVar12 = iVar12 + 4;
      iVar13 = iVar14;
    } while (iVar14 != 3);
  }
  return 0;
}

/* FUN_0014f420 @ 0x14f420 (4784 bytes) */
int FUN_0014f420(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint *puVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iStack00000020;
  int iStack00000024;
  int iStack00000028;
  uint local_f8 [7];
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  uint local_c8 [4];
  undefined4 local_b8;
  undefined4 local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4 [4];
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
  int local_64;
  uint local_60;
  undefined4 local_5c;
  uint *local_58;
  uint *local_54;
  
  iVar16 = *param_1;
  bVar1 = *(int *)(*(int *)(iVar16 + 0x88) + 8) != 0x13;
  iStack00000020 = param_3;
  iStack00000024 = param_4;
  iStack00000028 = param_5;
  if (!bVar1) {
    iVar16 = FUN_0014699c();
    if (iVar16 == 0) {
      return 0;
    }
    iVar16 = *param_1;
  }
  iVar3 = FUN_00105594(*param_2,param_2[1]);
  if ((iVar16 == iVar3) ||
     (iVar3 = *param_2, iVar16 = FUN_00105594(*param_1,param_1[1]), iVar3 == iVar16)) {
    return 0;
  }
  uVar4 = FUN_00105594(*param_1,param_1[1]);
  local_a4[0] = FUN_00105594(uVar4,1);
  uVar4 = FUN_00105594(*param_1,param_1[1]);
  local_a4[1] = FUN_00105594(uVar4,2);
  uVar9 = param_1[1];
  local_a4[2] = FUN_00105594(*param_1,uVar9 + (((int)uVar9 >> 1) +
                                              (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) * -2 + 1);
  local_5c = local_a4[2];
  uVar4 = FUN_00105594(*param_1,param_1[1]);
  iVar16 = FUN_001054ec(uVar4,1);
  local_f8[3] = *(undefined4 *)(iVar16 + 0x10);
  uVar4 = FUN_00105594(*param_1,param_1[1]);
  iVar16 = FUN_001054ec(uVar4,2);
  uVar9 = param_1[1];
  local_f8[4] = *(undefined4 *)(iVar16 + 0x10);
  iVar16 = FUN_001054ec(*param_1,uVar9 + (((int)uVar9 >> 1) +
                                         (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) * -2 + 1);
  uVar9 = local_f8[3];
  local_f8[5] = *(undefined4 *)(iVar16 + 0x10);
  iVar16 = FUN_001054ec(*param_1,param_1[1]);
  FUN_000f2bdc(&local_70,uVar9,*(undefined4 *)(iVar16 + 0x10));
  uVar9 = local_f8[4];
  local_f8[3] = local_70;
  iVar16 = FUN_001054ec(*param_1,param_1[1]);
  FUN_000f2bdc(&local_6c,uVar9,*(undefined4 *)(iVar16 + 0x10));
  local_f8[4] = local_6c;
  iVar16 = FUN_00105594(*param_1,param_1[1]);
  local_f8[6] = *(uint *)(iVar16 + 0xb8) & 1;
  iVar16 = FUN_00105594(*param_1,param_1[1]);
  uVar9 = param_1[1];
  local_dc = *(uint *)(iVar16 + 0xd0) & 1;
  local_d8 = *(uint *)((uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) *
                                -2) * 0x18 + *param_1 + 0xb8) & 1;
  if (bVar1) {
    iVar16 = *param_1 + uVar9 * 0x18 + 0x80;
    local_f8[6] = (uint)((*(uint *)(iVar16 + 0x20) & 1) != local_f8[6]);
    local_dc = *(uint *)(iVar16 + 0x20) & 1 ^ local_dc;
  }
  iVar16 = FUN_00105594();
  local_d4 = *(uint *)(iVar16 + 0xb8) >> 1 & 1;
  iVar16 = FUN_00105594(*param_1,param_1[1]);
  uVar9 = param_1[1];
  local_d0 = *(uint *)(iVar16 + 0xd0) >> 1 & 1;
  local_cc = *(uint *)((uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) *
                                -2) * 0x18 + *param_1 + 0xb8) >> 1 & 1;
  local_60 = local_cc;
  uVar4 = FUN_00105594(*param_2,param_2[1]);
  local_c8[0] = FUN_00105594(uVar4,1);
  uVar4 = FUN_00105594(*param_2,param_2[1]);
  local_c8[1] = FUN_00105594(uVar4,2);
  uVar9 = param_2[1];
  uVar5 = FUN_00105594(*param_2,uVar9 + (((int)uVar9 >> 1) +
                                        (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) * -2 + 1);
  local_c8[2] = uVar5;
  uVar4 = FUN_00105594(*param_2,param_2[1]);
  iVar16 = FUN_001054ec(uVar4,1);
  local_c8[3] = *(undefined4 *)(iVar16 + 0x10);
  uVar4 = FUN_00105594(*param_2,param_2[1]);
  iVar16 = FUN_001054ec(uVar4,2);
  uVar9 = param_2[1];
  local_b8 = *(undefined4 *)(iVar16 + 0x10);
  iVar16 = FUN_001054ec(*param_2,uVar9 + (((int)uVar9 >> 1) +
                                         (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) * -2 + 1);
  uVar9 = local_c8[3];
  local_b4 = *(undefined4 *)(iVar16 + 0x10);
  iVar16 = FUN_001054ec(*param_2,param_2[1]);
  FUN_000f2bdc(local_f8 + 0x18,uVar9,*(undefined4 *)(iVar16 + 0x10));
  uVar4 = local_b8;
  local_c8[3] = local_a4[3];
  iVar16 = FUN_001054ec(*param_2,param_2[1]);
  FUN_000f2bdc(&local_94,uVar4,*(undefined4 *)(iVar16 + 0x10));
  local_b8 = local_94;
  iVar16 = FUN_00105594(*param_2,param_2[1]);
  local_b0 = *(uint *)(iVar16 + 0xb8) & 1;
  iVar16 = FUN_00105594(*param_2,param_2[1]);
  uVar9 = param_2[1];
  local_ac = *(uint *)(iVar16 + 0xd0) & 1;
  local_a8 = *(uint *)((uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) *
                                -2) * 0x18 + *param_2 + 0xb8) & 1;
  if (bVar1) {
    iVar16 = *param_2 + uVar9 * 0x18 + 0x80;
    local_b0 = (uint)((*(uint *)(iVar16 + 0x20) & 1) != local_b0);
    local_ac = *(uint *)(iVar16 + 0x20) & 1 ^ local_ac;
  }
  iVar16 = FUN_00105594();
  local_f8[0] = *(uint *)(iVar16 + 0xb8) >> 1 & 1;
  iVar3 = 0;
  iVar16 = FUN_00105594(*param_2,param_2[1]);
  uVar9 = param_2[1];
  local_f8[1] = *(uint *)(iVar16 + 0xd0) >> 1 & 1;
  local_68 = 0;
  uVar9 = *(uint *)((uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) * -2)
                    * 0x18 + *param_2 + 0xb8) >> 1 & 1;
  local_58 = local_f8 + 0x12;
  local_f8[2] = uVar9;
  local_54 = local_f8 + 0xf;
LAB_0014f8d0:
  uVar14 = *(uint *)((int)local_f8 + iVar3 + 0x30);
  iVar18 = local_68 + 1;
  iVar10 = iVar18 % 3;
  iVar16 = 0;
  puVar15 = local_f8 + 0x15;
  do {
    iVar17 = iVar16 + 1;
    iVar13 = iVar17 % 3;
    if ((uVar14 == *puVar15) && (local_f8[iVar10 + 0xc] == local_f8[iVar13 + 0x15])) {
      local_64 = 0;
      iVar11 = iVar16;
      iVar16 = iVar13;
LAB_0014f980:
      iVar12 = iVar11;
      iVar13 = iVar16;
      if (bVar1) {
        iVar7 = iVar11 * 4;
        if ((((local_f8[iVar11 + 9] != *(uint *)((int)local_f8 + iVar3)) ||
             (local_f8[iVar16 + 9] != local_f8[iVar10])) ||
            (local_f8[iVar11 + 6] != *(uint *)(iVar3 + (int)local_58))) ||
           (local_f8[iVar16 + 6] != local_f8[iVar10 + 0x12])) goto LAB_0014fa98;
      }
      else {
        iVar7 = iVar11 << 2;
      }
      iVar6 = FUN_000f2da8(*(undefined4 *)((int)local_f8 + iVar7 + 0xc),
                           *(undefined4 *)(iVar3 + (int)local_54));
      if (((iVar6 != 0) &&
          (iVar6 = FUN_000f2da8(local_f8[iVar16 + 3],local_f8[iVar10 + 0xf]), iVar6 != 0)) ||
         ((iVar7 = FUN_000f2da8(*(undefined4 *)(iVar3 + (int)local_54),
                                *(undefined4 *)((int)local_f8 + iVar7 + 0xc)), iVar7 != 0 &&
          (iVar7 = FUN_000f2da8(local_f8[iVar10 + 0xf],local_f8[iVar16 + 3]), iVar7 != 0)))) {
        if (local_64 != 0) {
          iVar12 = iVar16;
          iVar13 = iVar11;
        }
        if (iStack00000024 == 0) {
          return 1;
        }
        bVar2 = true;
        goto LAB_0014fa80;
      }
    }
    else {
      if ((uVar14 == local_f8[iVar13 + 0x15]) && (*puVar15 == local_f8[iVar10 + 0xc])) {
        local_64 = 1;
        iVar11 = iVar13;
        goto LAB_0014f980;
      }
      local_64 = 0;
      iVar12 = iVar16;
    }
LAB_0014fa98:
    puVar15 = puVar15 + 1;
    iVar16 = iVar17;
  } while (iVar17 != 3);
  bVar2 = false;
LAB_0014fa80:
  if (iVar18 != 3) {
    iVar3 = iVar3 + 4;
    if (bVar2) goto LAB_0014fad0;
    local_68 = iVar18;
    goto LAB_0014f8d0;
  }
  if (!bVar2) {
    return 0;
  }
LAB_0014fad0:
  if (local_68 == 2) {
    uVar4 = FUN_00105594(*param_2,param_2[1]);
    FUN_00106004(uVar4,2,uVar5,1,*(undefined4 *)(iStack00000020 + 8));
    iVar16 = FUN_00105594(*param_2,param_2[1]);
    FUN_00103d50(iVar16 + 0xbc,1,local_a8);
    iVar16 = FUN_00105594(*param_2,param_2[1]);
    FUN_00103d50(iVar16 + 0xbc,2,uVar9);
    uVar5 = FUN_00105594(*param_2,param_2[1]);
    uVar4 = local_b4;
    iVar16 = FUN_001054ec(uVar5,2);
    *(undefined4 *)(iVar16 + 0x10) = uVar4;
    iVar16 = FUN_00105594(*param_2,param_2[1]);
    FUN_00103d50(iVar16 + 0xa4,1,local_b0);
    iVar16 = FUN_00105594(*param_2,param_2[1]);
    FUN_00103d50(iVar16 + 0xa4,2,local_f8[0]);
    uVar4 = FUN_00105594(*param_2,param_2[1]);
    uVar9 = local_c8[3];
    iVar16 = FUN_001054ec(uVar4,1);
    *(uint *)(iVar16 + 0x10) = uVar9;
    uVar9 = param_2[1];
    FUN_00106004(*param_2,uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) *
                                  -2 + 1,local_c8[1],1,*(undefined4 *)(iStack00000020 + 8));
    uVar4 = local_b8;
    uVar9 = param_2[1];
    iVar16 = FUN_001054ec(*param_2,uVar9 + (((int)uVar9 >> 1) +
                                           (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) * -2 + 1);
    *(undefined4 *)(iVar16 + 0x10) = uVar4;
    uVar9 = param_2[1];
    FUN_00103d50((uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) * -2) *
                 0x18 + *param_2 + 0xa4,1,local_ac);
    uVar9 = param_2[1];
    FUN_00103d50((uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) * -2) *
                 0x18 + *param_2 + 0xa4,2,local_f8[1]);
    if (bVar1) {
      FUN_00103d50(param_2[1] * 0x18 + *param_2 + 0x8c,1,0);
    }
    uVar4 = DAT_001b004c;
    iVar18 = *param_2;
    iVar3 = param_2[1];
    iVar16 = FUN_001054ec(iVar18,0);
    FUN_000f3908(&local_90,*(undefined4 *)(iVar16 + 0x10));
    FUN_000f3340(&local_8c,uVar4,local_90);
    iVar16 = FUN_001054ec(iVar18,iVar3);
    *(undefined4 *)(iVar16 + 0x10) = local_8c;
  }
  else if (local_68 == 1) {
    uVar4 = FUN_00105594(*param_2,param_2[1]);
    FUN_00106004(uVar4,1,uVar5,1,*(undefined4 *)(iStack00000020 + 8));
    iVar16 = FUN_00105594(*param_2,param_2[1]);
    FUN_00103d50(iVar16 + 0xa4,1,local_a8);
    iVar16 = FUN_00105594(*param_2,param_2[1]);
    FUN_00103d50(iVar16 + 0xa4,2,uVar9);
    uVar5 = FUN_00105594(*param_2,param_2[1]);
    uVar4 = local_b4;
    iVar16 = FUN_001054ec(uVar5,1);
    *(undefined4 *)(iVar16 + 0x10) = uVar4;
    iVar16 = FUN_00105594(*param_2,param_2[1]);
    FUN_00103d50(iVar16 + 0xbc,1,local_ac);
    iVar16 = FUN_00105594(*param_2,param_2[1]);
    FUN_00103d50(iVar16 + 0xbc,2,local_f8[1]);
    uVar5 = FUN_00105594(*param_2,param_2[1]);
    uVar4 = local_b8;
    iVar16 = FUN_001054ec(uVar5,2);
    *(undefined4 *)(iVar16 + 0x10) = uVar4;
    uVar9 = param_2[1];
    FUN_00106004(*param_2,uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) *
                                  -2 + 1,local_c8[0],1,*(undefined4 *)(iStack00000020 + 8));
    uVar9 = local_c8[3];
    uVar14 = param_2[1];
    iVar16 = FUN_001054ec(*param_2,uVar14 + (((int)uVar14 >> 1) +
                                            (uint)((int)uVar14 < 0 && (uVar14 & 1) != 0)) * -2 + 1);
    *(uint *)(iVar16 + 0x10) = uVar9;
    uVar9 = param_2[1];
    FUN_00103d50((uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) * -2) *
                 0x18 + *param_2 + 0xa4,1,local_b0);
    uVar9 = param_2[1];
    FUN_00103d50((uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) * -2) *
                 0x18 + *param_2 + 0xa4,2,local_f8[0]);
    if (bVar1) {
      FUN_00103d50(param_2[1] * 0x18 + *param_2 + 0x8c,1,0);
    }
    uVar4 = DAT_001b004c;
    iVar18 = *param_2;
    iVar3 = param_2[1];
    iVar16 = FUN_001054ec(iVar18,0);
    FUN_000f3908(&local_88,*(undefined4 *)(iVar16 + 0x10));
    FUN_000f3340(&local_84,uVar4,local_88);
    iVar16 = FUN_001054ec(iVar18,iVar3);
    *(undefined4 *)(iVar16 + 0x10) = local_84;
  }
  if (iVar12 == 2) {
    uVar4 = FUN_00105594(*param_1,param_1[1]);
    FUN_00106004(uVar4,2,local_5c,1,*(undefined4 *)(iStack00000020 + 8));
    iVar16 = FUN_00105594(*param_1,param_1[1]);
    FUN_00103d50(iVar16 + 0xbc,1,local_d8);
    iVar16 = FUN_00105594(*param_1,param_1[1]);
    FUN_00103d50(iVar16 + 0xbc,2,local_60);
    uVar4 = FUN_00105594(*param_1,param_1[1]);
    uVar9 = local_f8[5];
    iVar16 = FUN_001054ec(uVar4,2);
    *(uint *)(iVar16 + 0x10) = uVar9;
    iVar16 = FUN_00105594(*param_1,param_1[1]);
    FUN_00103d50(iVar16 + 0xa4,1,local_f8[6]);
    iVar16 = FUN_00105594(*param_1,param_1[1]);
    FUN_00103d50(iVar16 + 0xa4,2,local_d4);
    uVar4 = FUN_00105594(*param_1,param_1[1]);
    uVar9 = local_f8[3];
    iVar16 = FUN_001054ec(uVar4,1);
    *(uint *)(iVar16 + 0x10) = uVar9;
    uVar9 = param_1[1];
    FUN_00106004(*param_1,uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) *
                                  -2 + 1,local_a4[1],1,*(undefined4 *)(iStack00000020 + 8));
    uVar9 = local_f8[4];
    uVar14 = param_1[1];
    iVar16 = FUN_001054ec(*param_1,uVar14 + (((int)uVar14 >> 1) +
                                            (uint)((int)uVar14 < 0 && (uVar14 & 1) != 0)) * -2 + 1);
    *(uint *)(iVar16 + 0x10) = uVar9;
    uVar9 = param_1[1];
    FUN_00103d50((uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) * -2) *
                 0x18 + *param_1 + 0xa4,1,local_dc);
    uVar9 = param_1[1];
    FUN_00103d50((uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) * -2) *
                 0x18 + *param_1 + 0xa4,2,local_d0);
    if (bVar1) {
      FUN_00103d50(param_1[1] * 0x18 + *param_1 + 0x8c,1,0);
    }
    uVar4 = DAT_001b004c;
    iVar18 = *param_1;
    iVar3 = param_1[1];
    iVar16 = FUN_001054ec(iVar18,0);
    FUN_000f3908(&local_80,*(undefined4 *)(iVar16 + 0x10));
    FUN_000f3340(&local_7c,uVar4,local_80);
    iVar16 = FUN_001054ec(iVar18,iVar3);
    *(undefined4 *)(iVar16 + 0x10) = local_7c;
  }
  else if (iVar12 == 1) {
    uVar4 = FUN_00105594(*param_1,param_1[1]);
    FUN_00106004(uVar4,1,local_5c,1,*(undefined4 *)(iStack00000020 + 8));
    iVar16 = FUN_00105594(*param_1,param_1[1]);
    FUN_00103d50(iVar16 + 0xa4,1,local_d8);
    iVar16 = FUN_00105594(*param_1,param_1[1]);
    FUN_00103d50(iVar16 + 0xa4,2,local_60);
    uVar4 = FUN_00105594(*param_1,param_1[1]);
    uVar9 = local_f8[5];
    iVar16 = FUN_001054ec(uVar4,1);
    *(uint *)(iVar16 + 0x10) = uVar9;
    iVar16 = FUN_00105594(*param_1,param_1[1]);
    FUN_00103d50(iVar16 + 0xbc,1,local_dc);
    iVar16 = FUN_00105594(*param_1,param_1[1]);
    FUN_00103d50(iVar16 + 0xbc,2,local_d0);
    uVar4 = FUN_00105594(*param_1,param_1[1]);
    uVar9 = local_f8[4];
    iVar16 = FUN_001054ec(uVar4,2);
    *(uint *)(iVar16 + 0x10) = uVar9;
    uVar9 = param_1[1];
    FUN_00106004(*param_1,uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) *
                                  -2 + 1,local_a4[0],1,*(undefined4 *)(iStack00000020 + 8));
    uVar9 = local_f8[3];
    uVar14 = param_1[1];
    iVar16 = FUN_001054ec(*param_1,uVar14 + (((int)uVar14 >> 1) +
                                            (uint)((int)uVar14 < 0 && (uVar14 & 1) != 0)) * -2 + 1);
    *(uint *)(iVar16 + 0x10) = uVar9;
    uVar9 = param_1[1];
    FUN_00103d50((uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) * -2) *
                 0x18 + *param_1 + 0xa4,1,local_f8[6]);
    uVar9 = param_1[1];
    FUN_00103d50((uVar9 + (((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0)) * -2) *
                 0x18 + *param_1 + 0xa4,2,local_d4);
    if (bVar1) {
      FUN_00103d50(param_1[1] * 0x18 + *param_1 + 0x8c,1,0);
    }
    uVar4 = DAT_001b004c;
    iVar18 = *param_1;
    iVar3 = param_1[1];
    iVar16 = FUN_001054ec(iVar18,0);
    FUN_000f3908(&local_78,*(undefined4 *)(iVar16 + 0x10));
    FUN_000f3340(&local_74,uVar4,local_78);
    iVar16 = FUN_001054ec(iVar18,iVar3);
    *(undefined4 *)(iVar16 + 0x10) = local_74;
  }
  uVar4 = FUN_00105594(*param_1,param_1[1]);
  iVar16 = FUN_001054ec(uVar4,1);
  uVar14 = *(uint *)(iVar16 + 0x10);
  uVar4 = FUN_00105594(*param_1,param_1[1]);
  iVar16 = FUN_001054ec(uVar4,2);
  uVar9 = *(uint *)(iVar16 + 0x10);
  uVar4 = FUN_00105594(*param_1,param_1[1]);
  FUN_001054ec(uVar4,0);
  if ((uVar14 >> 0x18 != 4) || (iVar16 = 1, uVar9 >> 0x18 != 4)) {
    iVar16 = 0;
  }
  if (((uVar14 >> 0x10 & 0xff) != 4) || (iVar3 = 1, (uVar9 >> 0x10 & 0xff) != 4)) {
    iVar3 = 0;
  }
  if (((uVar14 >> 8 & 0xff) != 4) || (iVar18 = 1, (uVar9 >> 8 & 0xff) != 4)) {
    iVar18 = 0;
  }
  if (((uVar14 & 0xff) != 4) || (uVar14 = 1, (uVar9 & 0xff) != 4)) {
    uVar14 = 0;
  }
  iVar17 = FUN_00105594(*param_1,param_1[1]);
  *(uint *)(iVar17 + 0x9c) = uVar14 | iVar18 << 8 | iVar3 << 0x10 | iVar16 << 0x18;
  uVar4 = FUN_00105594(*param_2,param_2[1]);
  iVar16 = FUN_001054ec(uVar4,1);
  uVar14 = *(uint *)(iVar16 + 0x10);
  uVar4 = FUN_00105594(*param_2,param_2[1]);
  iVar16 = FUN_001054ec(uVar4,2);
  uVar9 = *(uint *)(iVar16 + 0x10);
  uVar4 = FUN_00105594(*param_2,param_2[1]);
  FUN_001054ec(uVar4,0);
  if ((uVar14 >> 0x18 != 4) || (iVar16 = 1, uVar9 >> 0x18 != 4)) {
    iVar16 = 0;
  }
  if (((uVar14 >> 0x10 & 0xff) != 4) || (iVar3 = 1, (uVar9 >> 0x10 & 0xff) != 4)) {
    iVar3 = 0;
  }
  if (((uVar14 >> 8 & 0xff) != 4) || (iVar18 = 1, (uVar9 >> 8 & 0xff) != 4)) {
    iVar18 = 0;
  }
  if (((uVar14 & 0xff) != 4) || (uVar14 = 1, (uVar9 & 0xff) != 4)) {
    uVar14 = 0;
  }
  iVar17 = FUN_00105594(*param_2,param_2[1]);
  *(uint *)(iVar17 + 0x9c) = uVar14 | iVar18 << 8 | iVar3 << 0x10 | iVar16 << 0x18;
  uVar4 = FUN_00105594(*param_2,param_2[1]);
  FUN_001474c8(iStack00000020,uVar4,iStack00000020);
  uVar4 = FUN_00105594(*param_1,param_1[1]);
  FUN_001474c8(iStack00000020,uVar4,iStack00000020);
  iVar16 = local_68;
  iVar3 = iVar12;
  if (local_64 != 0) {
    iVar3 = iVar13;
    iVar13 = iVar12;
  }
  if (iStack00000028 == 0) {
    return 1;
  }
  iVar18 = FUN_000f2da8(local_f8[iVar3 + 3],local_f8[local_68 + 0xf]);
  if ((iVar18 == 0) ||
     (iVar18 = FUN_000f2da8(local_f8[iVar13 + 3],local_f8[iVar10 + 0xf]), iVar18 == 0)) {
    iVar16 = FUN_000f2da8(local_f8[iVar16 + 0xf],local_f8[iVar3 + 3]);
    if ((iVar16 == 0) ||
       (iVar16 = FUN_000f2da8(local_f8[iVar10 + 0xf],local_f8[iVar13 + 3]), iVar16 == 0)) {
      piVar8 = (int *)0x0;
      goto LAB_00150668;
    }
    piVar8 = (int *)FUN_00105594(*param_1,param_1[1]);
    iVar3 = *param_1;
    iVar16 = param_1[1];
    uVar4 = FUN_00105594(*param_2,param_2[1]);
    FUN_00106004(iVar3,iVar16,uVar4,1,*(undefined4 *)(iStack00000020 + 8));
    iVar3 = param_2[1];
    iVar16 = *param_2;
    iVar18 = param_1[1];
    iVar10 = *param_1;
  }
  else {
    piVar8 = (int *)FUN_00105594(*param_2,param_2[1]);
    iVar3 = *param_2;
    iVar16 = param_2[1];
    uVar4 = FUN_00105594(*param_1,param_1[1]);
    FUN_00106004(iVar3,iVar16,uVar4,1,*(undefined4 *)(iStack00000020 + 8));
    iVar3 = param_1[1];
    iVar16 = *param_1;
    iVar18 = param_2[1];
    iVar10 = *param_2;
  }
  iVar16 = FUN_001054ec(iVar16,iVar3);
  uVar4 = *(undefined4 *)(iVar16 + 0x10);
  iVar16 = FUN_001054ec(iVar10,iVar18);
  *(undefined4 *)(iVar16 + 0x10) = uVar4;
LAB_00150668:
  iVar16 = FUN_001049c4(piVar8,iStack00000020);
  if (iVar16 == 0) {
    return 1;
  }
  (**(code **)(*piVar8 + 0xc))(piVar8,1,*(undefined4 *)(iStack00000020 + 8));
  return 1;
}

/* FUN_001506d0 @ 0x1506d0 (256 bytes) */
int FUN_001506d0(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_00146cd8(param_1,param_3);
  iVar2 = FUN_00146cd8(param_2,param_3);
  if ((((iVar1 == 0) || (iVar3 = ((int (*)())FUN_0014e9e4)(param_2,param_1,param_3,1,1), iVar3 == 0)) &&
      ((iVar2 == 0 || (iVar3 = ((int (*)())FUN_0014e9e4)(param_1,param_2,param_3,1,1), iVar3 == 0)))) &&
     (((iVar1 == 0 || (iVar2 == 0)) ||
      (iVar1 = ((int (*)())FUN_0014f420)(param_1,param_2,param_3,1,1), iVar1 == 0)))) {
    return;
  }
  uVar4 = FUN_00105594(*param_1,param_1[1]);
  ((int (*)())FUN_0014e6e4)(uVar4,param_3);
  return;
}

/* FUN_001507d0 @ 0x1507d0 (964 bytes) */
int FUN_001507d0(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  undefined4 param_3;
{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  int iVar15;
  int local_48 [6];
  
  *param_2 = 0;
  iVar13 = 0;
  local_48[0] = FUN_00105594(*param_1,3 - param_1[1]);
  iVar15 = 0;
  uVar3 = FUN_00105594(*param_1,param_1[1]);
  local_48[1] = FUN_00105594(uVar3,1);
  uVar3 = FUN_00105594(*param_1,param_1[1]);
  local_48[2] = FUN_00105594(uVar3,2);
  do {
    iVar4 = FUN_0010497c(*(undefined4 *)((int)local_48 + iVar13),param_3);
    if (iVar4 == 0) {
      iVar15 = iVar15 + 1;
    }
    bVar1 = iVar13 != 8;
    iVar13 = iVar13 + 4;
  } while (bVar1);
  if (1 < iVar15) {
    iVar4 = 0;
    iVar15 = *(int *)(*(int *)(*param_1 + 0x88) + 8);
    iVar13 = FUN_00146cd8(param_1,param_3);
    bVar1 = iVar13 != 0;
    do {
      iVar11 = *(int *)((int)local_48 + iVar4);
      iVar13 = FUN_001049c4(iVar11,param_3);
      if ((iVar13 == 0) && (iVar13 = FUN_0010497c(iVar11,param_3), iVar13 == 0)) {
        puVar14 = *(uint **)(iVar11 + 0x10);
        uVar12 = 0;
        uVar10 = puVar14[1];
        if (0 < (int)uVar10) {
          while( true ) {
            if (uVar12 < *puVar14) {
              uVar5 = puVar14[1];
              if (uVar5 <= uVar12) {
                _memset((void *)(uVar5 * 4 + puVar14[2]),0,(uVar12 - uVar5) * 4 + 4);
                puVar14[1] = uVar12 + 1;
              }
              piVar6 = (int *)(uVar12 * 4 + puVar14[2]);
            }
            else {
              piVar6 = (int *)FUN_0019423c(puVar14,uVar12);
            }
            iVar13 = *piVar6;
            if (((iVar15 == *(int *)(*(int *)(iVar13 + 0x88) + 8)) && (iVar13 != *param_1)) &&
               (iVar7 = FUN_00105594(*param_1,param_1[1]), iVar13 != iVar7)) {
              iVar7 = FUN_00105594(iVar13,1);
              if ((iVar11 == iVar7) &&
                 (iVar7 = FUN_00105594(iVar13,2), iVar15 == *(int *)(*(int *)(iVar7 + 0x88) + 8))) {
                uVar3 = FUN_00105594(iVar13,1);
                uVar8 = FUN_00105594(iVar13,2);
                iVar7 = FUN_00146868(uVar3,uVar8,param_3);
                if (iVar7 != 0) {
                  *param_2 = iVar13;
                  param_2[1] = 2;
                  iVar7 = FUN_00146cd8(param_2,param_3);
                  if ((bVar1) && (iVar9 = ((int (*)())FUN_0014e9e4)(param_2,param_1,param_3,0,0), iVar9 != 0)) {
                    return;
                  }
                  if ((iVar7 != 0) &&
                     (iVar9 = ((int (*)())FUN_0014e9e4)(param_1,param_2,param_3,0,0), iVar9 != 0)) {
                    return;
                  }
                  if (((bVar1) && (iVar7 != 0)) &&
                     (iVar7 = ((int (*)())FUN_0014f420)(param_1,param_2,param_3,0,0), iVar7 != 0)) {
                    return;
                  }
                }
              }
              iVar7 = FUN_00105594(iVar13,2);
              if ((iVar11 == iVar7) &&
                 (iVar7 = FUN_00105594(iVar13,1), iVar15 == *(int *)(*(int *)(iVar7 + 0x88) + 8))) {
                uVar3 = FUN_00105594(iVar13,2);
                uVar8 = FUN_00105594(iVar13,1);
                iVar7 = FUN_00146868(uVar3,uVar8,param_3);
                if (iVar7 != 0) {
                  *param_2 = iVar13;
                  param_2[1] = 1;
                  iVar13 = FUN_00146cd8(param_2,param_3);
                  if ((bVar1) && (iVar7 = ((int (*)())FUN_0014e9e4)(param_2,param_1,param_3,0,0), iVar7 != 0)) {
                    return;
                  }
                  if ((iVar13 != 0) &&
                     (iVar7 = ((int (*)())FUN_0014e9e4)(param_1,param_2,param_3,0,0), iVar7 != 0)) {
                    return;
                  }
                  if (((bVar1) && (iVar13 != 0)) &&
                     (iVar13 = ((int (*)())FUN_0014f420)(param_1,param_2,param_3,0,0), iVar13 != 0)) {
                    return;
                  }
                }
              }
            }
            uVar12 = uVar12 + 1;
            if (uVar10 == uVar12) break;
            puVar14 = *(uint **)(iVar11 + 0x10);
          }
        }
      }
      bVar2 = iVar4 != 8;
      iVar4 = iVar4 + 4;
    } while (bVar2);
    *param_2 = 0;
  }
  return;
}

/* FUN_00150b94 @ 0x150b94 (420 bytes) */
int FUN_00150b94(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int local_28 [6];
  
  local_28[1] = 0;
  local_28[0] = 0;
  iVar3 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  if (iVar3 == 0x12) {
    iVar3 = FUN_00105594(param_1,1);
    if (*(int *)(*(int *)(iVar3 + 0x88) + 8) == 0x12) {
LAB_00150c04:
      local_28[1] = 1;
      local_28[0] = param_1;
    }
  }
  else if ((iVar3 == 0x13) &&
          (iVar3 = FUN_00105594(param_1,1), *(int *)(*(int *)(iVar3 + 0x88) + 8) == 0x13))
  goto LAB_00150c04;
  local_28[3] = 0;
  local_28[2] = 0;
  if (local_28[0] != 0) {
    ((int (*)())FUN_001507d0)(local_28,local_28 + 2,param_2);
  }
  bVar1 = local_28[2] != 0;
  if (bVar1) {
    *(int *)(param_2 + 0x1f8) = *(int *)(param_2 + 0x1f8) + 1;
    ((int (*)())FUN_001506d0)(local_28 + 2,local_28,param_2);
  }
  local_28[0] = 0;
  iVar3 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  if (iVar3 == 0x12) {
    iVar3 = FUN_00105594(param_1,2);
    if (*(int *)(*(int *)(iVar3 + 0x88) + 8) != 0x12) goto LAB_00150cd0;
  }
  else if ((iVar3 != 0x13) ||
          (iVar3 = FUN_00105594(param_1,2), *(int *)(*(int *)(iVar3 + 0x88) + 8) != 0x13))
  goto LAB_00150cd0;
  local_28[1] = 2;
  local_28[0] = param_1;
LAB_00150cd0:
  if (local_28[0] == 0) {
    local_28[2] = local_28[0];
  }
  else {
    ((int (*)())FUN_001507d0)(local_28,local_28 + 2,param_2);
  }
  bVar2 = local_28[2] != 0;
  if (bVar2) {
    *(int *)(param_2 + 0x1f8) = *(int *)(param_2 + 0x1f8) + 1;
    ((int (*)())FUN_001506d0)(local_28 + 2,local_28,param_2);
  }
  return bVar2 || bVar1;
}

/* FUN_00150d38 @ 0x150d38 (1504 bytes) */
int FUN_00150d38(param_1, param_2)
  void *param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  void *pvVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  uint *puVar14;
  int iVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int iVar18;
  double dVar19;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  undefined4 local_5c;
  int local_58;
  int local_54;
  
  iVar15 = *(int *)(param_2 + 8);
  if (((param_1 != (void *)0x0) && (*(int *)(*(int *)((int)param_1 + 0x88) + 8) == 0x12)) &&
     (*(int *)((int)param_1 + 0x124) == 0)) {
    iVar13 = 1;
    puVar14 = (uint *)((int)param_1 + 0xb8);
    do {
      piVar5 = (int *)FUN_00105594(param_1,iVar13);
      iVar6 = (**(code **)(*piVar5 + 100))();
      if (((iVar6 != 0) && (piVar5[0x48] == 0)) &&
         (((piVar5[5] & 0x200U) == 0 && (piVar5[0x49] != 0)))) {
        dVar19 = (double)((double (*)())FUN_0010aad4)();
        local_7c = (float)dVar19;
        local_88 = (float)dVar19;
        local_84 = (float)dVar19;
        local_80 = (float)dVar19;
        iVar6 = FUN_001054ec(param_1,0);
        uVar17 = DAT_001b004c;
        local_98 = *(undefined4 *)(iVar6 + 0x10);
        iVar6 = FUN_001054ec(param_1,0);
        FUN_000f3908(&local_78,*(undefined4 *)(iVar6 + 0x10));
        FUN_000f3340(&local_74,uVar17,local_78);
        local_94 = local_74;
        iVar6 = (**(code **)(**(int **)(iVar15 + 0x30c) + 0x154))
                          (*(int **)(iVar15 + 0x30c),param_2,&local_88,&local_94);
        if (iVar6 != 0) {
          local_54 = *(int *)((int)param_1 + 4);
          local_58 = FUN_00104054(param_1,param_2);
          local_5c = *(undefined4 *)((int)param_1 + 0x120);
          iVar7 = FUN_001054ec(param_1,0);
          uVar11 = *(undefined4 *)(iVar7 + 0x10);
          piVar8 = (int *)FUN_00105594(piVar5,1);
          iVar7 = FUN_001054ec(piVar5,1);
          uVar17 = *(undefined4 *)(iVar7 + 0x10);
          iVar7 = FUN_001054ec(param_1,iVar13);
          FUN_000f2bdc(&local_70,uVar17,*(undefined4 *)(iVar7 + 0x10));
          uVar17 = local_70;
          local_60 = (*puVar14 ^ piVar5[0x2e]) & 1;
          if (((piVar5[0x2e] & 2U) != 0) || (local_64 = 0, (*puVar14 & 2) != 0)) {
            local_64 = 1;
          }
          iVar18 = 2 - (uint)(iVar13 == 2);
          local_68 = FUN_00105594(param_1,iVar18);
          iVar7 = FUN_001054ec(param_1,iVar18);
          uVar4 = *(uint *)((int)param_1 + 0x14);
          uVar12 = *(undefined4 *)(iVar7 + 0x10);
          uVar3 = *(uint *)((int)param_1 + iVar18 * 0x18 + 0xa0);
          local_6c = 0;
          uVar2 = uVar3 & 1;
          uVar3 = uVar3 >> 1 & 1;
          if ((uVar4 & 0x200) != 0) {
            local_6c = FUN_00105594(param_1,*(undefined4 *)((int)param_1 + 0x84));
            uVar4 = *(uint *)((int)param_1 + 0x14);
          }
          uVar16 = *(undefined4 *)((int)param_1 + 0x98);
          pvVar9 = (void *)FUN_001043f0(0x14,*(undefined4 *)(param_2 + 8));
          *(undefined4 *)((int)pvVar9 + 0x98) = uVar16;
          *(undefined4 *)((int)pvVar9 + 0x94) = *(undefined4 *)((int)pvVar9 + 0x14c);
          if ((uVar4 & 2) != 0) {
            *(uint *)((int)pvVar9 + 0x14) = *(uint *)((int)pvVar9 + 0x14) | 2;
          }
          *(undefined4 *)((int)pvVar9 + 0xc) = *(undefined4 *)((int)param_1 + 0xc);
          *(undefined4 *)((int)pvVar9 + 0x120) = local_5c;
          *(undefined4 *)((int)pvVar9 + 0x9c) = uVar11;
          FUN_00106004(pvVar9,1,piVar8,0,iVar15);
          iVar7 = FUN_001054ec(pvVar9,1);
          *(undefined4 *)(iVar7 + 0x10) = uVar17;
          FUN_00103d50((int)pvVar9 + 0xa4,1,local_60);
          FUN_00103d50((int)pvVar9 + 0xa4,2,local_64);
          iVar7 = FUN_00106230(pvVar9,2,iVar6,0,0,iVar15);
          uVar17 = local_94;
          iVar18 = FUN_001054ec(pvVar9,2);
          *(undefined4 *)(iVar18 + 0x10) = uVar17;
          FUN_00106004(pvVar9,2,iVar6,0,iVar15);
          iVar18 = FUN_00106230(pvVar9,3,local_68,uVar3,uVar2,iVar15);
          iVar10 = FUN_001054ec(pvVar9,3);
          *(undefined4 *)(iVar10 + 0x10) = uVar12;
          FUN_00103d50((int)pvVar9 + 0xd4,1,uVar2);
          FUN_00103d50((int)pvVar9 + 0xd4,2,uVar3);
          if (local_6c != 0) {
            FUN_00106804(pvVar9,local_6c,0,iVar15);
          }
          *(int *)((int)pvVar9 + 0x160) = local_58 + *(int *)(param_2 + 0x478);
          if (iVar18 != 0 && iVar7 != 0) {
            iVar13 = 0;
            iVar7 = 4;
            do {
              if (*(char *)((int)&local_98 + iVar13) == '\x01') {
                *(undefined1 *)(iVar13 + (int)&local_94) = 4;
              }
              uVar17 = local_94;
              iVar13 = iVar13 + 1;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
            iVar13 = FUN_001054ec(pvVar9,2);
            *(undefined4 *)(iVar13 + 0x10) = uVar17;
            iVar13 = FUN_001054ec(iVar6,0);
            iVar7 = 0;
            local_8c = local_94;
            local_90 = *(undefined4 *)(iVar13 + 0x10);
            iVar13 = 4;
            do {
              if (*(byte *)((int)&local_8c + iVar7) != 4) {
                *(undefined1 *)((int)&local_90 + (uint)*(byte *)((int)&local_8c + iVar7)) = 0;
              }
              iVar7 = iVar7 + 1;
              iVar13 = iVar13 + -1;
            } while (iVar13 != 0);
            *(undefined4 *)(iVar6 + 0x9c) = local_90;
            iVar7 = *(int *)(param_2 + 0x478);
            iVar13 = (**(code **)(*piVar8 + 0x5c))(piVar8);
            if ((iVar13 == 0) || (iVar13 = FUN_0010497c(piVar5,param_2), iVar13 != 0)) {
              if (iVar7 < piVar8[0x58]) {
                piVar8[0x58] = piVar8[0x58] + 1;
              }
              else {
                piVar8[0x58] = iVar7 + 1;
              }
            }
            else {
              iVar10 = iVar7 + 1;
              iVar13 = FUN_0010445c(piVar8,*(undefined4 *)(param_2 + 8),0);
              *(undefined4 *)(iVar13 + 0x98) = 0x31;
              *(undefined4 *)(iVar13 + 0x94) = *(undefined4 *)(iVar13 + 0x14c);
              FUN_000e7738(piVar8[0x56],piVar8,iVar13);
              *(int *)(iVar13 + 0x160) = iVar10;
              iVar18 = FUN_00105594(iVar13,1);
              if (iVar7 < *(int *)(iVar18 + 0x160)) {
                *(int *)(iVar18 + 0x160) = *(int *)(iVar18 + 0x160) + 1;
              }
              else {
                *(int *)(iVar18 + 0x160) = iVar10;
              }
              if (1 < *(int *)(iVar13 + 0x84)) {
                iVar18 = FUN_00105594(iVar13,2);
                if (iVar7 < *(int *)(iVar18 + 0x160)) {
                  *(int *)(iVar18 + 0x160) = *(int *)(iVar18 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar18 + 0x160) = iVar10;
                }
              }
              FUN_00106004(pvVar9,1,iVar13,0,iVar15);
            }
            if (iVar7 < *(int *)(iVar6 + 0x160)) {
              *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
            }
            else {
              *(int *)(iVar6 + 0x160) = iVar7 + 1;
            }
            FUN_0019401c(param_1);
            _memcpy(param_1,pvVar9,0x164);
            FUN_000e7738(*(undefined4 *)(local_54 + 0x158),local_54,param_1);
            FUN_00105894(piVar5,*(undefined4 *)(param_2 + 8));
            return 1;
          }
        }
      }
      bVar1 = iVar13 != 2;
      puVar14 = puVar14 + 6;
      iVar13 = iVar13 + 1;
    } while (bVar1);
  }
  return 0;
}

/* FUN_00151318 @ 0x151318 (88 bytes) */
int FUN_00151318(param_1)
  undefined4 param_1;
{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_1c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  iVar1 = FUN_001054ec(param_1,0);
  FUN_000f5c0c(param_1,1,*(undefined4 *)(iVar1 + 0x10),&local_28);
  return;
}

/* FUN_00151370 @ 0x151370 (1792 bytes) */
int FUN_00151370(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  undefined4 local_c8;
  undefined4 local_c4;
  int local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  int local_b4;
  int local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  int local_84;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  int local_50 [5];
  
  iVar4 = (**(code **)(*param_1 + 100))();
  if ((iVar4 != 0) && (iVar4 = (**(code **)(*param_2 + 100))(param_2), iVar4 != 0)) {
    uVar5 = FUN_00105594(param_1,1);
    uVar6 = FUN_00105594(param_2,1);
    iVar4 = FUN_00146de0(uVar5,uVar6);
    if (iVar4 == 0) {
      iVar4 = FUN_00105594(param_1,1);
      iVar7 = FUN_00105594(param_2,1);
      if (((iVar4 != iVar7) && (param_2[0x48] == param_1[0x48])) && (param_1[0x49] == param_2[0x49])
         ) {
        iVar4 = FUN_001054ec(param_1,0);
        local_c8 = *(undefined4 *)(iVar4 + 0x10);
        iVar4 = FUN_001054ec(param_1,param_1[0x21]);
        FUN_000f36b8(&local_58,*(undefined4 *)(iVar4 + 0x10));
        local_c4 = local_58;
        iVar4 = FUN_001054ec(param_2,0);
        FUN_000f2f28(&local_54,local_58,*(undefined4 *)(iVar4 + 0x10));
        iVar4 = DAT_001b0174;
        iVar7 = 0;
        local_c4 = local_54;
        iVar12 = 4;
        do {
          if ((*(char *)((int)&local_c8 + iVar7) != '\x01') &&
             (*(char *)((int)&local_c4 + iVar7) != '\x01')) {
            return 0;
          }
          iVar7 = iVar7 + 1;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
        if ((local_54 != DAT_001b0174) &&
           ((iVar7 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x30), iVar7 == 0 ||
            (((char)local_c8 != '\0' && ((char)local_c4 != '\0')))))) {
          FUN_000f2f84(local_50,local_c4,local_c8);
          local_c0 = local_50[0];
          iVar7 = FUN_001054ec(param_1,1);
          local_bc = *(undefined4 *)(iVar7 + 0x10);
          iVar7 = FUN_001054ec(param_2,1);
          iVar12 = 0;
          local_b8 = *(undefined4 *)(iVar7 + 0x10);
          local_b0 = iVar4;
          local_98 = DAT_001b0050;
          iVar7 = 4;
          local_b4 = iVar4;
          local_ac = DAT_001b0050;
          local_a8 = DAT_001b0050;
          local_a4 = DAT_001b0050;
          local_a0 = DAT_001b0050;
          local_9c = DAT_001b0050;
          do {
            if (*(char *)((int)&local_c0 + iVar12) == '\0') {
              uVar1 = (undefined1)iVar12;
              if (*(char *)((int)&local_c8 + iVar12) == '\0') {
                *(undefined1 *)((int)&local_ac + iVar12) = *(undefined1 *)((int)&local_bc + iVar12);
                *(undefined1 *)((int)&local_a0 + iVar12) = uVar1;
              }
              else if (*(char *)((int)&local_c4 + iVar12) == '\0') {
                *(undefined1 *)((int)&local_a4 + iVar12) = *(undefined1 *)((int)&local_b8 + iVar12);
                *(undefined1 *)((int)&local_a8 + iVar12) = uVar1;
              }
              *(undefined1 *)((int)&local_b0 + iVar12) = 0;
              *(undefined1 *)((int)&local_98 + iVar12) = uVar1;
              *(undefined1 *)((int)&local_b4 + iVar12) = 0;
              *(undefined1 *)((int)&local_9c + iVar12) = uVar1;
            }
            iVar4 = local_b4;
            iVar12 = iVar12 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          uVar5 = FUN_00105594(param_1,1);
          uVar8 = ((int (*)())FUN_0010bed0)((double)FLOAT_001aa0d4,2,iVar4,uVar5,param_3,
                               *(undefined4 *)(param_3 + 8));
          iVar4 = local_b0;
          uVar5 = FUN_00105594(param_2,1);
          uVar9 = ((int (*)())FUN_0010bed0)((double)FLOAT_001aa0d4,2,iVar4,uVar5,param_3,
                               *(undefined4 *)(param_3 + 8));
          uVar5 = local_ac;
          iVar4 = FUN_001054ec(uVar8,1);
          uVar6 = local_a8;
          *(undefined4 *)(iVar4 + 0x10) = uVar5;
          iVar4 = FUN_001054ec(uVar8,2);
          uVar5 = local_a4;
          *(undefined4 *)(iVar4 + 0x10) = uVar6;
          iVar4 = FUN_001054ec(uVar9,1);
          uVar6 = local_a0;
          *(undefined4 *)(iVar4 + 0x10) = uVar5;
          iVar4 = FUN_001054ec(uVar9,2);
          uVar3 = param_2[0x2e];
          *(undefined4 *)(iVar4 + 0x10) = uVar6;
          local_88 = 0;
          local_84 = 0;
          local_74 = 0;
          if ((param_2[5] & 0x200U) != 0) {
            FUN_00104d3c(param_2,&local_88);
          }
          uVar2 = param_1[0x2e];
          local_70 = 0;
          local_6c = 0;
          local_5c = 0;
          iVar7 = param_1[0x49];
          uVar5 = FUN_001054ec(param_1,1);
          FUN_00104730(&local_70,uVar5);
          local_94 = 0;
          local_90 = 0;
          local_8c = 0;
          FUN_00103f18(param_1,&local_94,0xffffffff);
          iVar4 = param_1[1];
          FUN_0019401c(param_1);
          FUN_00108174(param_1,0x12,*(undefined4 *)(param_3 + 8));
          FUN_000e7738(*(undefined4 *)(iVar4 + 0x158),iVar4,param_1);
          FUN_00103f44(param_1,&local_94);
          iVar4 = param_2[0x48];
          param_1[0x49] = iVar7;
          param_1[0x48] = iVar4;
          uVar5 = FUN_001054ec(param_1,1);
          FUN_00104730(uVar5,&local_70);
          FUN_00105e54(param_1,2,param_2,1);
          param_1[0x27] = local_c0;
          param_1[0x25] = param_1[0x53];
          param_1[0x26] = 0;
          FUN_00106004(param_1,1,uVar8,0,*(undefined4 *)(param_3 + 8));
          FUN_00103d50(param_1 + 0x29,1,uVar2 & 1);
          FUN_00103d50(param_1 + 0x29,2,uVar2 >> 1 & 1);
          uVar5 = local_9c;
          iVar4 = FUN_001054ec(param_1,1);
          *(undefined4 *)(iVar4 + 0x10) = uVar5;
          FUN_00106004(param_1,2,uVar9,0,*(undefined4 *)(param_3 + 8));
          FUN_00103d50(param_1 + 0x2f,1,uVar3 & 1);
          FUN_00103d50(param_1 + 0x2f,2,uVar3 >> 1 & 1);
          uVar5 = local_98;
          iVar4 = FUN_001054ec(param_1,2);
          *(undefined4 *)(iVar4 + 0x10) = uVar5;
          FUN_000e7700(param_1[0x56],param_1,uVar9);
          FUN_000e7700(param_1[0x56],param_1,uVar8);
          if (local_84 != 0) {
            FUN_00106b48(param_1,&local_88,0,*(undefined4 *)(param_3 + 8));
            if (*(int *)(param_3 + 0x478) < *(int *)(local_84 + 0x160)) {
              *(int *)(local_84 + 0x160) = *(int *)(local_84 + 0x160) + 1;
            }
            else {
              *(int *)(local_84 + 0x160) = *(int *)(param_3 + 0x478) + 1;
            }
          }
          iVar4 = (**(code **)(*param_2 + 0x60))(param_2);
          piVar10 = param_2;
          if (iVar4 != 0) {
            piVar10 = (int *)FUN_00105594(param_2,1);
          }
          uVar5 = FUN_00105594(piVar10,1);
          piVar11 = (int *)FUN_0010af38(uVar5,param_3,0);
          iVar4 = (**(code **)(*piVar11 + 0x5c))();
          if (iVar4 == 0) {
            iVar4 = FUN_00105594(param_2,1);
            if (*(int *)(param_3 + 0x478) < *(int *)(iVar4 + 0x160)) {
              *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
            }
            else {
              *(int *)(iVar4 + 0x160) = *(int *)(param_3 + 0x478) + 1;
            }
          }
          else {
            FUN_00106004(piVar10,1,piVar11,0,*(undefined4 *)(param_3 + 8));
            if (*(int *)(param_3 + 0x478) < piVar11[0x58]) {
              piVar11[0x58] = piVar11[0x58] + 1;
            }
            else {
              piVar11[0x58] = *(int *)(param_3 + 0x478) + 1;
            }
          }
          piVar10 = (int *)FUN_00105594(uVar8,1);
          iVar4 = (**(code **)(*piVar10 + 0x60))();
          if (iVar4 != 0) {
            uVar5 = FUN_00105594(uVar8,1);
            FUN_0010c670(uVar5,uVar8,*(undefined4 *)(param_3 + 8));
          }
          piVar10 = (int *)FUN_00105594(uVar9,1);
          iVar4 = (**(code **)(*piVar10 + 0x60))();
          if (iVar4 != 0) {
            uVar5 = FUN_00105594(uVar9,1);
            FUN_0010c670(uVar5,uVar9,*(undefined4 *)(param_3 + 8));
          }
          FUN_00105894(param_2,*(undefined4 *)(param_3 + 8));
          return 1;
        }
      }
    }
  }
  return 0;
}

/* FUN_00151a74 @ 0x151a74 (2624 bytes) */
int FUN_00151a74(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_b8;
  int local_b4;
  int local_b0 [5];
  int *local_9c;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_74;
  int local_68;
  undefined1 auStack_64 [4];
  int local_60 [6];
  
  iVar3 = (**(code **)(*param_1 + 100))();
  if ((iVar3 != 0) && (iVar3 = (**(code **)(*param_2 + 100))(param_2), iVar3 != 0)) {
    uVar4 = FUN_00105594(param_1,1);
    uVar5 = FUN_00105594(param_2,1);
    iVar3 = FUN_00146de0(uVar4,uVar5);
    if (iVar3 == 0) {
      iVar3 = FUN_00105594(param_1,1);
      iVar6 = FUN_00105594(param_2,1);
      if (iVar3 != iVar6) {
        iVar3 = FUN_001054ec(param_1,0);
        local_c8 = *(undefined4 *)(iVar3 + 0x10);
        iVar6 = FUN_001054ec(param_2,0);
        iVar3 = 0;
        local_c4 = *(undefined4 *)(iVar6 + 0x10);
        iVar6 = 4;
        do {
          if ((*(char *)((int)&local_c8 + iVar3) != '\x01') &&
             (*(char *)((int)&local_c4 + iVar3) != '\x01')) {
            return 0;
          }
          iVar3 = iVar3 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        iVar3 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x30);
        if ((iVar3 == 0) || (((char)local_c8 != '\0' && ((char)local_c4 != '\0')))) {
          iVar3 = FUN_001054ec(param_1,1);
          local_c0 = *(undefined4 *)(iVar3 + 0x10);
          iVar3 = FUN_001054ec(param_2,1);
          local_bc = *(undefined4 *)(iVar3 + 0x10);
          local_8c = 0;
          local_b0[4] = 0;
          local_9c = (int *)0x0;
          if ((param_2[5] & 0x200U) != 0) {
            FUN_00104d3c(param_2,local_b0 + 4);
          }
          piVar13 = local_9c;
          bVar1 = local_9c != (int *)0x0;
          iVar3 = DAT_001b0174;
          if (bVar1) {
            iVar3 = FUN_001054ec(local_9c,0);
            iVar3 = *(int *)(iVar3 + 0x10);
          }
          if ((((bVar1) && (param_1[0x49] == 0)) &&
              ((iVar6 = (**(code **)(*piVar13 + 100))(piVar13), iVar6 != 0 ||
               (iVar6 = FUN_0010497c(piVar13,param_3), iVar6 == 0)))) &&
             ((((iVar3 != DAT_001b0054 && ((piVar13[5] & 0x200U) == 0)) &&
               (iVar6 = FUN_000f3824(iVar3), iVar6 != 0)) &&
              ((iVar6 = FUN_000f3824(local_c8), iVar6 != 0 &&
               (iVar6 = FUN_000f3824(local_c4), iVar6 != 0)))))) {
            if ((((param_1[0x2e] & 1U) == (param_2[0x2e] & 1U)) &&
                ((((uint)param_1[0x2e] >> 1 & 1) == ((uint)param_2[0x2e] >> 1 & 1) &&
                 (param_2[0x48] == param_1[0x48])))) && (param_1[0x49] == param_2[0x49])) {
              iVar6 = FUN_000f37b8(local_c8);
              iVar7 = FUN_000f37b8(local_c4);
              uVar8 = FUN_000f37b8(iVar3);
              FUN_000f2f84(&local_68,local_c4,local_c8);
              local_b8 = local_68;
              iVar9 = FUN_001054ec(piVar13,0);
              FUN_000f302c(auStack_64,*(undefined4 *)(iVar9 + 0x10),local_b8);
              FUN_000f2f84(local_60,iVar3,local_b8);
              local_b8 = local_60[0];
              uVar4 = FUN_00105594(param_2,1);
              piVar10 = (int *)((int (*)())FUN_0010bed0)((double)FLOAT_001aa0e8,3,local_60[0],uVar4,param_3,
                                            *(undefined4 *)(param_3 + 8));
              iVar3 = local_b8;
              uVar4 = FUN_00105594(param_1,1);
              piVar11 = (int *)((int (*)())FUN_0010bed0)((double)FLOAT_001aa0e8,3,iVar3,uVar4,param_3,
                                            *(undefined4 *)(param_3 + 8));
              piVar12 = (int *)((int (*)())FUN_0010bed0)((double)FLOAT_001aa0d4,2,local_b8,piVar13,param_3,
                                            *(undefined4 *)(param_3 + 8));
              if (*(int *)(param_3 + 0x478) < piVar13[0x58]) {
                piVar13[0x58] = piVar13[0x58] + 1;
              }
              else {
                piVar13[0x58] = *(int *)(param_3 + 0x478) + 1;
              }
              uVar14 = (uint)*(byte *)((int)&local_c0 + iVar6);
              local_b4 = DAT_001b0174;
              *(undefined1 *)((int)&local_b4 + uVar14) = 0;
              local_b0[0] = DAT_001b0174;
              uVar16 = 0xffffffff;
              uVar17 = 0xffffffff;
              uVar18 = 0xffffffff;
              uVar2 = DAT_001b004c & 0xffffff00;
              (**(code **)(*piVar11 + 0x88))(piVar11,1,uVar14,uVar14);
              uVar15 = (uint)*(byte *)((int)&local_bc + iVar7);
              *(undefined1 *)((int)local_b0 + uVar15) = 0;
              uVar14 = 0xffffffff;
              uVar19 = 0;
              (**(code **)(*piVar10 + 0x88))(piVar10,1,uVar15,uVar15);
              (**(code **)(*piVar12 + 0x88))(piVar12,1,uVar8,uVar8);
              (**(code **)(*piVar12 + 0x88))(piVar12,2,iVar6,iVar6);
              (**(code **)(*piVar12 + 0x88))(piVar12,2,iVar7,iVar7);
              do {
                iVar3 = FUN_001054ec(piVar11,1);
                if (uVar19 != *(byte *)(uVar19 + iVar3 + 0x10)) {
                  if (((int)uVar16 < 0) && (uVar8 != uVar19)) {
                    (**(code **)(*piVar11 + 0x88))(piVar11,2,uVar19,uVar19);
                    *(undefined1 *)((int)&local_b4 + uVar19) = 0;
                    uVar16 = uVar19;
                  }
                  else if ((int)uVar17 < 0) {
                    (**(code **)(*piVar11 + 0x88))(piVar11,3,uVar19,uVar19);
                    *(undefined1 *)((int)&local_b4 + uVar19) = 0;
                    uVar17 = uVar19;
                  }
                }
                iVar3 = FUN_001054ec(piVar10,1);
                if (uVar19 != *(byte *)(uVar19 + iVar3 + 0x10)) {
                  if (((int)uVar18 < 0) && (uVar8 != uVar19)) {
                    (**(code **)(*piVar10 + 0x88))(piVar10,2,uVar19,uVar19);
                    *(undefined1 *)((int)local_b0 + uVar19) = 0;
                    uVar18 = uVar19;
                  }
                  else if ((int)uVar14 < 0) {
                    (**(code **)(*piVar10 + 0x88))(piVar10,3,uVar19,uVar19);
                    *(undefined1 *)((int)local_b0 + uVar19) = 0;
                    uVar14 = uVar19;
                  }
                }
                bVar1 = uVar19 != 3;
                uVar19 = uVar19 + 1;
              } while (bVar1);
              piVar11[0x27] = local_b4;
              local_88 = 0;
              piVar10[0x27] = local_b0[0];
              local_84 = 0;
              local_74 = 0;
              uVar4 = FUN_001054ec(param_1,1);
              FUN_00104730(&local_88,uVar4);
              local_b0[1] = 0;
              local_b0[2] = 0;
              local_b0[3] = 0;
              FUN_00103f18(param_1,local_b0 + 1,0xffffffff);
              iVar3 = param_1[1];
              FUN_0019401c(param_1);
              FUN_00108304(param_1,0x14,*(undefined4 *)(param_3 + 8));
              iVar6 = 0;
              FUN_000e7738(*(undefined4 *)(iVar3 + 0x158),iVar3,param_1);
              FUN_00103f44(param_1,local_b0 + 1);
              param_1[0x48] = param_2[0x48];
              param_1[0x25] = param_1[0x53];
              param_1[0x27] = local_b8;
              param_1[0x26] = 0;
              param_1[0x49] = 0;
              uVar4 = FUN_001054ec(param_1,1);
              FUN_00104730(uVar4,&local_88);
              FUN_00106004(param_1,1,piVar11,0,*(undefined4 *)(param_3 + 8));
              FUN_00103d50(param_1 + 0x29,1,param_2[0x2e] & 1);
              FUN_00105e54(param_1,2,param_2,1);
              FUN_00106004(param_1,2,piVar10,0,*(undefined4 *)(param_3 + 8));
              FUN_00103d50(param_1 + 0x2f,1,0);
              FUN_00106004(param_1,3,piVar12,0,*(undefined4 *)(param_3 + 8));
              iVar3 = FUN_001054ec(param_1,3);
              *(uint *)(iVar3 + 0x10) = uVar2 | 4;
              do {
                iVar3 = FUN_001054ec(param_1,1);
                if (*(char *)(iVar6 + iVar3 + 0x10) == '\x04') {
                  iVar3 = FUN_001054ec(param_1,2);
                  if (*(char *)(iVar6 + iVar3 + 0x10) == '\x04') {
                    if (*(char *)((int)&local_b8 + iVar6) == '\0') {
                      (**(code **)(*param_1 + 0x88))(param_1,1,iVar6,uVar17);
                    }
                  }
                  else {
                    (**(code **)(*param_1 + 0x88))(param_1,1,iVar6,uVar16);
                  }
                }
                iVar3 = FUN_001054ec(param_1,2);
                if (*(char *)(iVar6 + iVar3 + 0x10) == '\x04') {
                  iVar3 = FUN_001054ec(param_1,1);
                  if (*(char *)(iVar6 + iVar3 + 0x10) == '\x04') {
                    if (*(char *)((int)&local_b8 + iVar6) == '\0') {
                      (**(code **)(*param_1 + 0x88))(param_1,2,iVar6,uVar14);
                    }
                  }
                  else {
                    (**(code **)(*param_1 + 0x88))(param_1,2,iVar6,uVar18);
                  }
                }
                bVar1 = iVar6 != 3;
                iVar6 = iVar6 + 1;
              } while (bVar1);
              FUN_000e7700(param_1[0x56],param_1,piVar10);
              FUN_000e7700(param_1[0x56],param_1,piVar11);
              FUN_000e7700(param_1[0x56],param_1,piVar12);
              iVar3 = (**(code **)(*param_2 + 0x60))(param_2);
              piVar13 = param_2;
              if (iVar3 != 0) {
                piVar13 = (int *)FUN_00105594(param_2,1);
              }
              uVar4 = FUN_00105594(piVar13,1);
              piVar12 = (int *)FUN_0010af38(uVar4,param_3,0);
              iVar3 = (**(code **)(*piVar12 + 0x5c))();
              if (iVar3 == 0) {
                iVar3 = FUN_00105594(param_2,1);
                if (*(int *)(param_3 + 0x478) < *(int *)(iVar3 + 0x160)) {
                  *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar3 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                }
              }
              else {
                FUN_00106004(piVar13,1,piVar12,0,*(undefined4 *)(param_3 + 8));
                if (*(int *)(param_3 + 0x478) < piVar12[0x58]) {
                  piVar12[0x58] = piVar12[0x58] + 1;
                }
                else {
                  piVar12[0x58] = *(int *)(param_3 + 0x478) + 1;
                }
              }
              piVar13 = (int *)FUN_00105594(piVar11,1);
              iVar3 = (**(code **)(*piVar13 + 0x60))();
              if (iVar3 != 0) {
                uVar4 = FUN_00105594(piVar11,1);
                FUN_0010c670(uVar4,piVar11,*(undefined4 *)(param_3 + 8));
              }
              piVar13 = (int *)FUN_00105594(piVar10,1);
              iVar3 = (**(code **)(*piVar13 + 0x60))();
              if (iVar3 != 0) {
                uVar4 = FUN_00105594(piVar10,1);
                FUN_0010c670(uVar4,piVar10,*(undefined4 *)(param_3 + 8));
              }
              FUN_00105894(param_2,*(undefined4 *)(param_3 + 8));
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_001524b8 @ 0x1524b8 (2540 bytes) */
int FUN_001524b8(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  int local_98;
  int local_94;
  int local_90 [5];
  int *local_7c;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_54;
  int local_48 [3];
  
  iVar5 = (**(code **)(*param_1 + 100))();
  if ((iVar5 != 0) && (iVar5 = (**(code **)(*param_2 + 100))(param_2), iVar5 != 0)) {
    uVar6 = FUN_00105594(param_1,1);
    uVar7 = FUN_00105594(param_2,1);
    iVar5 = FUN_00146de0(uVar6,uVar7);
    if (iVar5 == 0) {
      iVar5 = FUN_00105594(param_1,1);
      iVar8 = FUN_00105594(param_2,1);
      if (iVar5 != iVar8) {
        iVar5 = FUN_001054ec(param_1,0);
        local_a8 = *(undefined4 *)(iVar5 + 0x10);
        iVar8 = FUN_001054ec(param_2,0);
        iVar5 = 0;
        local_a4 = *(undefined4 *)(iVar8 + 0x10);
        uVar6 = local_a4;
        iVar19 = 4;
        do {
          if ((*(char *)((int)&local_a8 + iVar5) != '\x01') &&
             (*(char *)((int)&local_a4 + iVar5) != '\x01')) {
            return 0;
          }
          iVar5 = iVar5 + 1;
          iVar19 = iVar19 + -1;
        } while (iVar19 != 0);
        if (((char)local_a8 != '\0') &&
           ((*(unsigned char *)((unsigned char *)&(local_a4) + 3)) = (char)*(undefined4 *)(iVar8 + 0x10), (char)local_a4 != '\0')) {
          local_a4 = uVar6;
          iVar5 = FUN_001054ec(param_1,1);
          local_a0 = *(undefined4 *)(iVar5 + 0x10);
          iVar5 = FUN_001054ec(param_2,1);
          local_9c = *(undefined4 *)(iVar5 + 0x10);
          local_6c = 0;
          local_90[4] = 0;
          local_7c = (int *)0x0;
          if ((param_2[5] & 0x200U) != 0) {
            FUN_00104d3c(param_2,local_90 + 4);
          }
          piVar11 = local_7c;
          bVar2 = local_7c == (int *)0x0;
          iVar5 = DAT_001b0174;
          if (!bVar2) {
            iVar5 = FUN_001054ec(local_7c,0);
            iVar5 = *(int *)(iVar5 + 0x10);
          }
          iVar8 = param_1[0x49];
          if ((((bVar2) || (iVar8 != 0)) ||
              ((iVar19 = (**(code **)(*piVar11 + 100))(piVar11), iVar19 == 0 &&
               (iVar19 = FUN_0010497c(piVar11,param_3), iVar19 != 0)))) ||
             ((((iVar5 == DAT_001b0054 || (iVar5 = FUN_000f3824(iVar5), iVar5 == 0)) ||
               (iVar5 = FUN_000f3824(local_a8), iVar5 == 0)) ||
              (iVar5 = FUN_000f3824(local_a4), iVar5 == 0)))) {
            if ((((param_1[0x2e] & 1U) == (param_2[0x2e] & 1U)) &&
                (((uint)param_1[0x2e] >> 1 & 1) == ((uint)param_2[0x2e] >> 1 & 1))) &&
               ((param_2[0x48] == param_1[0x48] && (param_1[0x49] == param_2[0x49])))) {
              iVar16 = -1;
              bVar1 = true;
              FUN_000f2f84(local_48,local_a4,local_a8);
              iVar19 = -1;
              local_98 = local_48[0];
              iVar20 = 4;
              iVar4 = 0;
              iVar5 = -1;
              iVar14 = -1;
              bVar3 = bVar1;
              do {
                iVar13 = iVar5;
                iVar15 = iVar14;
                if (*(char *)((int)&local_a8 + iVar4) == '\0') {
                  iVar13 = iVar4;
                  if ((-1 < iVar5) && (iVar13 = iVar5, bVar3)) {
                    bVar3 = iVar4 < 0;
                    iVar19 = iVar4;
                  }
                }
                else if (((*(char *)((int)&local_a4 + iVar4) == '\0') &&
                         (iVar15 = iVar4, -1 < iVar14)) && (iVar15 = iVar14, bVar1)) {
                  bVar1 = iVar4 < 0;
                  iVar16 = iVar4;
                }
                iVar4 = iVar4 + 1;
                iVar20 = iVar20 + -1;
                iVar5 = iVar13;
                iVar14 = iVar15;
              } while (iVar20 != 0);
              uVar6 = FUN_00105594(param_2,1);
              piVar9 = (int *)((int (*)())FUN_0010bed0)((double)FLOAT_001aa0e8,3,local_48[0],uVar6,param_3,
                                           *(undefined4 *)(param_3 + 8));
              iVar5 = local_98;
              uVar6 = FUN_00105594(param_1,1);
              piVar10 = (int *)((int (*)())FUN_0010bed0)((double)FLOAT_001aa0e8,3,iVar5,uVar6,param_3,
                                            *(undefined4 *)(param_3 + 8));
              uVar12 = (uint)*(byte *)((int)&local_a0 + iVar13);
              local_94 = DAT_001b0174;
              local_90[0] = DAT_001b0174;
              *(undefined1 *)((int)&local_94 + uVar12) = 0;
              (**(code **)(*piVar10 + 0x88))(piVar10,1,uVar12,uVar12);
              if (!bVar3) {
                uVar12 = (uint)*(byte *)((int)&local_a0 + iVar19);
                *(undefined1 *)((int)&local_94 + uVar12) = 0;
                (**(code **)(*piVar10 + 0x88))(piVar10,1,uVar12,uVar12);
              }
              uVar12 = (uint)*(byte *)((int)&local_9c + iVar15);
              *(undefined1 *)((int)local_90 + uVar12) = 0;
              (**(code **)(*piVar9 + 0x88))(piVar9,1,uVar12,uVar12);
              if (!bVar1) {
                uVar12 = (uint)*(byte *)((int)&local_9c + iVar16);
                *(undefined1 *)((int)local_90 + uVar12) = 0;
                (**(code **)(*piVar9 + 0x88))(piVar9,1,uVar12,uVar12);
              }
              uVar12 = 0xffffffff;
              uVar17 = 0xffffffff;
              uVar18 = 0;
              do {
                iVar5 = FUN_001054ec(piVar10,1);
                if ((uVar18 != *(byte *)(uVar18 + iVar5 + 0x10)) && ((int)uVar12 < 0)) {
                  (**(code **)(*piVar10 + 0x88))(piVar10,2,uVar18,uVar18);
                  *(undefined1 *)((int)&local_94 + uVar18) = 0;
                  uVar12 = uVar18;
                }
                iVar5 = FUN_001054ec(piVar9,1);
                if ((uVar18 != *(byte *)(uVar18 + iVar5 + 0x10)) && ((int)uVar17 < 0)) {
                  (**(code **)(*piVar9 + 0x88))(piVar9,2,uVar18,uVar18);
                  *(undefined1 *)((int)local_90 + uVar18) = 0;
                  uVar17 = uVar18;
                }
                bVar3 = uVar18 != 3;
                uVar18 = uVar18 + 1;
              } while (bVar3);
              piVar10[0x27] = local_94;
              local_68 = 0;
              piVar9[0x27] = local_90[0];
              local_64 = 0;
              local_54 = 0;
              uVar6 = FUN_001054ec(param_1,1);
              FUN_00104730(&local_68,uVar6);
              local_90[1] = 0;
              local_90[2] = 0;
              local_90[3] = 0;
              FUN_00103f18(param_1,local_90 + 1,0xffffffff);
              iVar5 = param_1[1];
              FUN_0019401c(param_1);
              FUN_00108174(param_1,0x13,*(undefined4 *)(param_3 + 8));
              iVar19 = 0;
              FUN_000e7738(*(undefined4 *)(iVar5 + 0x158),iVar5,param_1);
              FUN_00103f44(param_1,local_90 + 1);
              param_1[0x48] = param_2[0x48];
              param_1[0x25] = param_1[0x53];
              param_1[0x27] = local_98;
              param_1[0x49] = iVar8;
              param_1[0x26] = 0;
              uVar6 = FUN_001054ec(param_1,1);
              FUN_00104730(uVar6,&local_68);
              FUN_00106004(param_1,1,piVar10,0,*(undefined4 *)(param_3 + 8));
              FUN_00103d50(param_1 + 0x29,1,param_2[0x2e] & 1);
              FUN_00105e54(param_1,2,param_2,1);
              FUN_00106004(param_1,2,piVar9,0,*(undefined4 *)(param_3 + 8));
              FUN_00103d50(param_1 + 0x2f,1,0);
              do {
                iVar5 = FUN_001054ec(param_1,1);
                if (*(char *)(iVar19 + iVar5 + 0x10) == '\x04') {
                  iVar5 = FUN_001054ec(param_1,2);
                  if (*(char *)(iVar19 + iVar5 + 0x10) == '\x04') {
                    if (*(char *)((int)&local_98 + iVar19) == '\0') {
                      (**(code **)(*param_1 + 0x88))(param_1,1,iVar19,0xffffffff);
                    }
                  }
                  else {
                    (**(code **)(*param_1 + 0x88))(param_1,1,iVar19,uVar12);
                  }
                }
                iVar5 = FUN_001054ec(param_1,2);
                if (*(char *)(iVar19 + iVar5 + 0x10) == '\x04') {
                  iVar5 = FUN_001054ec(param_1,1);
                  if (*(char *)(iVar19 + iVar5 + 0x10) == '\x04') {
                    if (*(char *)((int)&local_98 + iVar19) == '\0') {
                      (**(code **)(*param_1 + 0x88))(param_1,2,iVar19,0xffffffff);
                    }
                  }
                  else {
                    (**(code **)(*param_1 + 0x88))(param_1,2,iVar19,uVar17);
                  }
                }
                bVar3 = iVar19 != 3;
                iVar19 = iVar19 + 1;
              } while (bVar3);
              FUN_000e7700(param_1[0x56],param_1,piVar9);
              FUN_000e7700(param_1[0x56],param_1,piVar10);
              if (!bVar2) {
                FUN_00106b48(param_1,local_90 + 4,0,*(undefined4 *)(param_3 + 8));
                if (*(int *)(param_3 + 0x478) < piVar11[0x58]) {
                  piVar11[0x58] = piVar11[0x58] + 1;
                }
                else {
                  piVar11[0x58] = *(int *)(param_3 + 0x478) + 1;
                }
              }
              iVar5 = (**(code **)(*param_2 + 0x60))(param_2);
              piVar11 = param_2;
              if (iVar5 != 0) {
                piVar11 = (int *)FUN_00105594(param_2,1);
              }
              iVar5 = FUN_00105594(piVar11,1);
              if (iVar5 == 0) {
                iVar5 = piVar11[0x2c];
              }
              else {
                iVar5 = FUN_00105594(piVar11,1);
                iVar5 = *(int *)(iVar5 + 0x98);
              }
              if (iVar5 == 0x31) {
                iVar5 = FUN_00105594(piVar11,1);
                iVar8 = FUN_0010445c(iVar5,*(undefined4 *)(param_3 + 8),0);
                *(undefined4 *)(iVar8 + 0x98) = 0x31;
                *(undefined4 *)(iVar8 + 0x94) = *(undefined4 *)(iVar8 + 0x14c);
                FUN_000e7738(*(undefined4 *)(iVar5 + 0x158),iVar5,iVar8);
                *(int *)(iVar8 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                if (0 < *(int *)(iVar8 + 0x84)) {
                  iVar5 = 1;
                  do {
                    iVar19 = FUN_00105594(iVar8,iVar5);
                    if (*(int *)(param_3 + 0x478) < *(int *)(iVar19 + 0x160)) {
                      *(int *)(iVar19 + 0x160) = *(int *)(iVar19 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar19 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                    }
                    iVar5 = iVar5 + 1;
                  } while (iVar5 <= *(int *)(iVar8 + 0x84));
                }
                FUN_00106004(piVar11,1,iVar8,0,*(undefined4 *)(param_3 + 8));
              }
              else {
                iVar5 = FUN_00105594(param_2,1);
                if (*(int *)(param_3 + 0x478) < *(int *)(iVar5 + 0x160)) {
                  *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar5 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                }
              }
              piVar11 = (int *)FUN_00105594(piVar10,1);
              iVar5 = (**(code **)(*piVar11 + 0x60))();
              if (iVar5 != 0) {
                uVar6 = FUN_00105594(piVar10,1);
                FUN_0010c670(uVar6,piVar10,*(undefined4 *)(param_3 + 8));
              }
              piVar11 = (int *)FUN_00105594(piVar9,1);
              iVar5 = (**(code **)(*piVar11 + 0x60))();
              if (iVar5 != 0) {
                uVar6 = FUN_00105594(piVar9,1);
                FUN_0010c670(uVar6,piVar9,*(undefined4 *)(param_3 + 8));
              }
              FUN_00105894(param_2,*(undefined4 *)(param_3 + 8));
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_00152ea8 @ 0x152ea8 (4932 bytes) */
int FUN_00152ea8(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  byte bVar2;
  float fVar3;
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  undefined4 uVar13;
  int *piVar14;
  int *piVar15;
  int *piVar16;
  int *piVar17;
  undefined4 uVar18;
  code *pcVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined4 local_128;
  undefined4 local_124;
  int local_120;
  int local_11c;
  int local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  int local_e4;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_8c;
  undefined4 local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  undefined4 *local_74;
  undefined *local_70;
  int *local_6c;
  int *local_68;
  int *local_64;
  
  uVar18 = *(undefined4 *)(param_3 + 8);
  iVar6 = (**(code **)(*param_1 + 100))();
  if (((iVar6 != 0) && (*(int *)(param_2[0x22] + 8) == 0x12)) ||
     ((iVar6 = (**(code **)(*param_2 + 100))(param_2), iVar6 != 0 &&
      (*(int *)(param_1[0x22] + 8) == 0x12)))) {
    uVar7 = FUN_00105594(param_1,1);
    iVar6 = FUN_001054ec(param_1,1);
    iVar6 = FUN_0010453c(uVar7,uVar18,*(undefined4 *)(iVar6 + 0x10));
    uVar7 = FUN_00105594(param_2,1);
    iVar8 = FUN_001054ec(param_2,1);
    FUN_0010453c(uVar7,uVar18,*(undefined4 *)(iVar8 + 0x10));
    if (((param_2[0x48] == param_1[0x48]) && (param_1[0x49] == param_2[0x49])) && (iVar6 == 0)) {
      iVar6 = FUN_001054ec(param_1,0);
      local_128 = *(int *)(iVar6 + 0x10);
      iVar6 = FUN_001054ec(param_1,param_1[0x21]);
      FUN_000f36b8(&local_88,*(undefined4 *)(iVar6 + 0x10));
      local_124 = local_88;
      iVar6 = FUN_001054ec(param_2,0);
      FUN_000f2f28(&local_84,local_88,*(undefined4 *)(iVar6 + 0x10));
      iVar6 = 0;
      local_124 = local_84;
      iVar8 = 4;
      do {
        if ((*(char *)((int)&local_128 + iVar6) != '\x01') &&
           (*(char *)((int)&local_124 + iVar6) != '\x01')) {
          return 0;
        }
        iVar6 = iVar6 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      iVar6 = FUN_000e07dc(uVar18,0x30);
      if ((iVar6 == 0) || (((char)local_128 != '\0' && ((char)local_124 != '\0')))) {
        iVar6 = (**(code **)(*param_1 + 100))(param_1);
        if (iVar6 == 0) {
          local_11c = local_124;
          local_120 = local_128;
          piVar14 = param_2;
          piVar17 = param_1;
        }
        else {
          local_11c = local_128;
          local_120 = local_124;
          piVar14 = param_1;
          piVar17 = param_2;
        }
        iVar6 = FUN_00147238(piVar17);
        if ((iVar6 != 0) && ((piVar17[0x2e] & 1U) == (piVar17[0x34] & 1U))) {
          uVar7 = FUN_00105594(piVar14,1);
          uVar9 = FUN_00105594(piVar17,1);
          iVar6 = FUN_00146de0(uVar7,uVar9);
          if (iVar6 == 0) {
            uVar7 = FUN_00105594(piVar14,1);
            uVar9 = FUN_00105594(piVar17,2);
            iVar6 = FUN_00146de0(uVar7,uVar9);
            if (iVar6 == 0) {
              iVar6 = FUN_00105594(piVar14,1);
              iVar8 = FUN_00105594(piVar17,1);
              if (iVar6 != iVar8) {
                iVar6 = FUN_00105594(piVar14,1);
                iVar8 = FUN_00105594(piVar17,2);
                if ((iVar6 != iVar8) && (iVar6 = FUN_0010497c(param_2,param_3), iVar6 != 0)) {
                  FUN_000f2f84(&local_80,local_124,local_128);
                  local_118 = local_80;
                  local_78 = param_1[0x49];
                  iVar6 = FUN_001054ec(piVar17,1);
                  local_114 = *(undefined4 *)(iVar6 + 0x10);
                  iVar6 = FUN_001054ec(piVar17,2);
                  local_110 = *(undefined4 *)(iVar6 + 0x10);
                  iVar6 = FUN_001054ec(piVar14,1);
                  local_10c = *(undefined4 *)(iVar6 + 0x10);
                  piVar10 = (int *)FUN_00105594(piVar17,1);
                  iVar6 = (**(code **)(*piVar10 + 0x60))();
                  uVar7 = DAT_001b0174;
                  if (iVar6 == 0) {
                    uVar9 = FUN_00105594(piVar17,1);
                    piVar10 = (int *)((int (*)())FUN_0010bed0)((double)FLOAT_001aa0e8,3,uVar7,uVar9,param_3,
                                                  uVar18);
                    if (0 < piVar10[0x21]) {
                      iVar6 = 1;
                      do {
                        iVar8 = FUN_00105594(piVar10,iVar6);
                        if (*(int *)(param_3 + 0x478) < *(int *)(iVar8 + 0x160)) {
                          *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar8 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                        }
                        iVar6 = iVar6 + 1;
                      } while (iVar6 <= piVar10[0x21]);
                    }
                    uVar7 = local_114;
                    local_104 = 0;
                    iVar6 = 3;
                    local_108 = 0;
                    iVar8 = FUN_001054ec(piVar10,1);
                    local_6c = &local_120;
                    *(undefined4 *)(iVar8 + 0x10) = uVar7;
                    local_7c = 2;
                    local_70 = &DAT_001b2eb8;
                  }
                  else {
                    uVar7 = FUN_00105594(piVar17,1);
                    uVar24 = FUN_0010445c(uVar7,uVar18,0);
                    piVar10 = (int *)((ulonglong)uVar24 >> 0x20);
                    uVar9 = (undefined4)uVar24;
                    piVar10[0x58] = *(int *)(param_3 + 0x478) + 1;
                    piVar10[0x25] = piVar10[0x53];
                    if (0 < piVar10[0x21]) {
                      iVar6 = 1;
                      do {
                        uVar24 = FUN_00105594(piVar10,iVar6);
                        iVar8 = (int)((ulonglong)uVar24 >> 0x20);
                        uVar9 = (undefined4)uVar24;
                        if (*(int *)(param_3 + 0x478) < *(int *)(iVar8 + 0x160)) {
                          *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar8 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                        }
                        iVar6 = iVar6 + 1;
                      } while (iVar6 <= piVar10[0x21]);
                    }
                    uVar24 = ((int (*)())FUN_0010b184)((double)FLOAT_001aa0e8,piVar10,uVar9,&local_108);
                    local_7c = (int)((ulonglong)uVar24 >> 0x20);
                    if (local_7c == 0) {
                      FUN_0010bd50((double)FLOAT_001aa0e8,piVar10,(int)uVar24,piVar10[0x21] + 1,
                                   uVar18);
                      local_7c = piVar10[0x21];
                      local_108 = 0;
                      uVar25 = FUN_00105594(piVar10,local_7c);
                      iVar6 = (int)((ulonglong)uVar25 >> 0x20);
                      uVar24 = CONCAT44(local_7c,(int)uVar25);
                      if (*(int *)(param_3 + 0x478) < *(int *)(iVar6 + 0x160)) {
                        *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar6 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                        uVar24 = CONCAT44(local_7c,(int)uVar25);
                      }
                    }
                    local_7c = (int)((ulonglong)uVar24 >> 0x20);
                    uVar24 = ((int (*)())FUN_0010b184)((double)FLOAT_001aa0d4,piVar10,(int)uVar24,&local_104);
                    iVar6 = (int)((ulonglong)uVar24 >> 0x20);
                    if (iVar6 == 0) {
                      FUN_0010bd50((double)FLOAT_001aa0d4,piVar10,(int)uVar24,piVar10[0x21] + 1,
                                   uVar18);
                      iVar6 = piVar10[0x21];
                      local_104 = 0;
                      iVar8 = FUN_00105594(piVar10,iVar6);
                      if (*(int *)(param_3 + 0x478) < *(int *)(iVar8 + 0x160)) {
                        *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar8 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                      }
                    }
                    iVar8 = DAT_001b0050;
                    iVar4 = piVar10[0x21];
                    if (iVar4 < 1) {
                      local_70 = &DAT_001b2eb8;
                    }
                    else {
                      iVar22 = 1;
                      local_70 = &DAT_001b2eb8;
                      do {
                        if (iVar22 == 0) {
                          piVar10[0x27] = iVar8;
                        }
                        else {
                          iVar4 = FUN_001054ec(piVar10,iVar22);
                          *(int *)(iVar4 + 0x10) = iVar8;
                          iVar4 = piVar10[0x21];
                        }
                        iVar22 = iVar22 + 1;
                      } while (iVar22 <= iVar4);
                    }
                    iVar8 = 0;
                    local_6c = &local_120;
                    do {
                      if ((*(char *)(iVar8 + (int)local_6c) == '\0') &&
                         (bVar2 = *(byte *)((int)&local_114 + iVar8), 0 < piVar10[0x21])) {
                        iVar4 = 1;
                        do {
                          iVar22 = FUN_001054ec(uVar7,iVar4);
                          if (*(char *)((uint)bVar2 + iVar22 + 0x10) != '\x04') {
                            pcVar19 = *(code **)(*piVar10 + 0x88);
                            iVar22 = FUN_001054ec(uVar7,iVar4);
                            (*pcVar19)(piVar10,iVar4,iVar8,
                                       *(undefined1 *)((uint)bVar2 + iVar22 + 0x10));
                            break;
                          }
                          iVar4 = iVar4 + 1;
                        } while (iVar4 <= piVar10[0x21]);
                      }
                      bVar1 = iVar8 != 3;
                      iVar8 = iVar8 + 1;
                    } while (bVar1);
                    piVar10[0x27] = local_120;
                  }
                  iVar4 = 4;
                  local_114 = *(undefined4 *)(local_70 + -0x2e68);
                  iVar8 = 0;
                  do {
                    if (*(char *)(iVar8 + (int)local_6c) == '\0') {
                      *(char *)((int)&local_114 + iVar8) = (char)iVar8;
                    }
                    iVar8 = iVar8 + 1;
                    iVar4 = iVar4 + -1;
                  } while (iVar4 != 0);
                  piVar11 = (int *)FUN_00105594(piVar17,2);
                  iVar4 = (**(code **)(*piVar11 + 0x60))();
                  iVar8 = local_120;
                  if (iVar4 == 0) {
                    uVar7 = FUN_00105594(piVar17,2);
                    piVar11 = (int *)((int (*)())FUN_0010bed0)((double)FLOAT_001aa0e8,3,iVar8,uVar7,param_3,
                                                  uVar18);
                    if (0 < piVar11[0x21]) {
                      iVar8 = 1;
                      do {
                        iVar4 = FUN_00105594(piVar11,iVar8);
                        if (*(int *)(param_3 + 0x478) < *(int *)(iVar4 + 0x160)) {
                          *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar4 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                        }
                        iVar8 = iVar8 + 1;
                      } while (iVar8 <= piVar11[0x21]);
                    }
                    uVar7 = local_110;
                    local_fc = 0;
                    uVar9 = 2;
                    local_100 = 0;
                    iVar8 = FUN_001054ec(piVar11,1);
                    *(undefined4 *)(iVar8 + 0x10) = uVar7;
                    iVar8 = 3;
                  }
                  else {
                    uVar7 = FUN_00105594(piVar17,2);
                    uVar24 = FUN_0010445c(uVar7,uVar18,0);
                    piVar11 = (int *)((ulonglong)uVar24 >> 0x20);
                    uVar9 = (undefined4)uVar24;
                    piVar11[0x58] = *(int *)(param_3 + 0x478) + 1;
                    piVar11[0x25] = piVar11[0x53];
                    if (0 < piVar11[0x21]) {
                      iVar8 = 1;
                      do {
                        uVar24 = FUN_00105594(piVar11,iVar8);
                        iVar4 = (int)((ulonglong)uVar24 >> 0x20);
                        uVar9 = (undefined4)uVar24;
                        if (*(int *)(param_3 + 0x478) < *(int *)(iVar4 + 0x160)) {
                          *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar4 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                        }
                        iVar8 = iVar8 + 1;
                      } while (iVar8 <= piVar11[0x21]);
                    }
                    uVar24 = ((int (*)())FUN_0010b184)((double)FLOAT_001aa0e8,piVar11,uVar9,&local_100);
                    if ((int)((ulonglong)uVar24 >> 0x20) == 0) {
                      FUN_0010bd50((double)FLOAT_001aa0e8,piVar11,(int)uVar24,piVar11[0x21] + 1,
                                   uVar18);
                      iVar4 = piVar11[0x21];
                      local_100 = 0;
                      uVar25 = FUN_00105594(piVar11,iVar4);
                      iVar8 = (int)((ulonglong)uVar25 >> 0x20);
                      uVar24 = CONCAT44(iVar4,(int)uVar25);
                      if (*(int *)(param_3 + 0x478) < *(int *)(iVar8 + 0x160)) {
                        *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar8 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                        uVar24 = CONCAT44(iVar4,(int)uVar25);
                      }
                    }
                    uVar9 = (undefined4)((ulonglong)uVar24 >> 0x20);
                    uVar24 = ((int (*)())FUN_0010b184)((double)FLOAT_001aa0d4,piVar11,(int)uVar24,&local_fc);
                    iVar8 = (int)((ulonglong)uVar24 >> 0x20);
                    if (iVar8 == 0) {
                      FUN_0010bd50((double)FLOAT_001aa0d4,piVar11,(int)uVar24,piVar11[0x21] + 1,
                                   uVar18);
                      iVar8 = piVar11[0x21];
                      local_fc = 0;
                      iVar4 = FUN_00105594(piVar11,iVar8);
                      if (*(int *)(param_3 + 0x478) < *(int *)(iVar4 + 0x160)) {
                        *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar4 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                      }
                    }
                    iVar4 = piVar11[0x21];
                    if (0 < iVar4) {
                      iVar20 = 1;
                      iVar22 = *(int *)(local_70 + -0x2e68);
                      do {
                        if (iVar20 == 0) {
                          piVar11[0x27] = iVar22;
                        }
                        else {
                          iVar4 = FUN_001054ec(piVar11,iVar20);
                          *(int *)(iVar4 + 0x10) = iVar22;
                          iVar4 = piVar11[0x21];
                        }
                        iVar20 = iVar20 + 1;
                      } while (iVar20 <= iVar4);
                    }
                    iVar4 = 0;
                    do {
                      if ((*(char *)(iVar4 + (int)local_6c) == '\0') &&
                         (bVar2 = *(byte *)((int)&local_114 + iVar4), 0 < piVar11[0x21])) {
                        iVar22 = 1;
                        do {
                          iVar20 = FUN_001054ec(uVar7,iVar22);
                          if (*(char *)((uint)bVar2 + iVar20 + 0x10) != '\x04') {
                            pcVar19 = *(code **)(*piVar11 + 0x88);
                            iVar20 = FUN_001054ec(uVar7,iVar22);
                            (*pcVar19)(piVar11,iVar22,iVar4,
                                       *(undefined1 *)((uint)bVar2 + iVar20 + 0x10));
                            break;
                          }
                          iVar22 = iVar22 + 1;
                        } while (iVar22 <= piVar11[0x21]);
                      }
                      bVar1 = iVar4 != 3;
                      iVar4 = iVar4 + 1;
                    } while (bVar1);
                    piVar11[0x27] = local_120;
                  }
                  iVar22 = 4;
                  local_110 = *(undefined4 *)(local_70 + -0x2e68);
                  iVar4 = 0;
                  do {
                    if (*(char *)(iVar4 + (int)local_6c) == '\0') {
                      *(char *)((int)&local_110 + iVar4) = (char)iVar4;
                    }
                    iVar4 = iVar4 + 1;
                    iVar22 = iVar22 + -1;
                  } while (iVar22 != 0);
                  iVar22 = (**(code **)(*piVar14 + 0x60))(piVar14);
                  iVar4 = local_11c;
                  if (iVar22 == 0) {
                    uVar7 = FUN_00105594(piVar14,1);
                    piVar12 = (int *)((int (*)())FUN_0010bed0)((double)FLOAT_001aa0d4,2,iVar4,uVar7,param_3,
                                                  uVar18);
                    if (0 < piVar12[0x21]) {
                      iVar4 = 1;
                      do {
                        iVar22 = FUN_00105594(piVar12,iVar4);
                        if (*(int *)(param_3 + 0x478) < *(int *)(iVar22 + 0x160)) {
                          *(int *)(iVar22 + 0x160) = *(int *)(iVar22 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar22 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                        }
                        iVar4 = iVar4 + 1;
                      } while (iVar4 <= piVar12[0x21]);
                    }
                    uVar7 = local_10c;
                    local_f8 = 0;
                    iVar4 = FUN_001054ec(piVar12,1);
                    *(undefined4 *)(iVar4 + 0x10) = uVar7;
                    iVar4 = 2;
                    local_68 = &local_11c;
                  }
                  else {
                    uVar7 = FUN_00105594(piVar14,1);
                    uVar24 = FUN_0010445c(uVar7,uVar18,0);
                    piVar12 = (int *)((ulonglong)uVar24 >> 0x20);
                    uVar13 = (undefined4)uVar24;
                    piVar12[0x58] = *(int *)(param_3 + 0x478) + 1;
                    piVar12[0x25] = piVar12[0x53];
                    if (0 < piVar12[0x21]) {
                      iVar4 = 1;
                      do {
                        uVar24 = FUN_00105594(piVar12,iVar4);
                        iVar22 = (int)((ulonglong)uVar24 >> 0x20);
                        uVar13 = (undefined4)uVar24;
                        if (*(int *)(param_3 + 0x478) < *(int *)(iVar22 + 0x160)) {
                          *(int *)(iVar22 + 0x160) = *(int *)(iVar22 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar22 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                        }
                        iVar4 = iVar4 + 1;
                      } while (iVar4 <= piVar12[0x21]);
                    }
                    uVar24 = ((int (*)())FUN_0010b184)((double)FLOAT_001aa0d4,piVar12,uVar13,&local_f8);
                    iVar4 = (int)((ulonglong)uVar24 >> 0x20);
                    if (iVar4 == 0) {
                      FUN_0010bd50((double)FLOAT_001aa0d4,piVar12,(int)uVar24,piVar12[0x21] + 1,
                                   uVar18);
                      iVar4 = piVar12[0x21];
                      local_f8 = 0;
                      iVar22 = FUN_00105594(piVar12,iVar4);
                      if (*(int *)(param_3 + 0x478) < *(int *)(iVar22 + 0x160)) {
                        *(int *)(iVar22 + 0x160) = *(int *)(iVar22 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar22 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                      }
                    }
                    iVar22 = piVar12[0x21];
                    if (0 < iVar22) {
                      iVar20 = 1;
                      iVar23 = *(int *)(local_70 + -0x2e68);
                      do {
                        if (iVar20 == 0) {
                          piVar12[0x27] = iVar23;
                        }
                        else {
                          iVar22 = FUN_001054ec(piVar12,iVar20);
                          *(int *)(iVar22 + 0x10) = iVar23;
                          iVar22 = piVar12[0x21];
                        }
                        iVar20 = iVar20 + 1;
                      } while (iVar20 <= iVar22);
                    }
                    iVar22 = 0;
                    local_68 = &local_11c;
                    local_74 = &local_10c;
                    do {
                      if ((*(char *)(iVar22 + (int)local_68) == '\0') &&
                         (bVar2 = *(byte *)(iVar22 + (int)local_74), 0 < piVar12[0x21])) {
                        iVar20 = 1;
                        do {
                          iVar23 = FUN_001054ec(uVar7,iVar20);
                          if (*(char *)((uint)bVar2 + iVar23 + 0x10) != '\x04') {
                            pcVar19 = *(code **)(*piVar12 + 0x88);
                            iVar23 = FUN_001054ec(uVar7,iVar20);
                            (*pcVar19)(piVar12,iVar20,iVar22,
                                       *(undefined1 *)((uint)bVar2 + iVar23 + 0x10));
                            break;
                          }
                          iVar20 = iVar20 + 1;
                        } while (iVar20 <= piVar12[0x21]);
                      }
                      bVar1 = iVar22 != 3;
                      iVar22 = iVar22 + 1;
                    } while (bVar1);
                    piVar12[0x27] = local_11c;
                  }
                  iVar22 = 0;
                  local_10c = *(undefined4 *)(local_70 + -0x2e68);
                  iVar20 = 4;
                  do {
                    if (*(char *)(iVar22 + (int)local_68) == '\0') {
                      *(char *)((int)&local_10c + iVar22) = (char)iVar22;
                    }
                    iVar22 = iVar22 + 1;
                    iVar20 = iVar20 + -1;
                  } while (iVar20 != 0);
                  local_64 = piVar12 + 0x27;
                  iVar22 = 0;
                  do {
                    if (*(char *)(iVar22 + (int)local_6c) == '\0') {
                      *(char *)((int)&local_10c + iVar22) = (char)iVar22;
                      (**(code **)(*piVar12 + 0x88))(piVar12,iVar4,iVar22,local_f8);
                      *(undefined1 *)local_64 = 0;
                      fVar3 = FLOAT_001aa0d4;
                      bVar2 = *(byte *)((int)&local_114 + iVar22);
                      if (0 < piVar10[0x21]) {
                        iVar20 = 1;
                        bVar1 = false;
                        do {
                          iVar23 = FUN_001054ec(piVar10,iVar20);
                          uVar21 = (uint)*(byte *)((uint)bVar2 + iVar23 + 0x10);
                          if (((uVar21 != 4) &&
                              (iVar23 = FUN_00105594(piVar10,iVar20),
                              ((int)*(char *)(iVar23 + 0x15c) >> (uVar21 & 0x3f) & 1U) != 0)) &&
                             (*(float *)(uVar21 * 0x18 + iVar23 + 0x20) == fVar3)) {
                            bVar1 = true;
                            (**(code **)(*piVar10 + 0x88))(piVar10,iVar20,uVar21,4);
                            (**(code **)(*piVar10 + 0x88))(piVar10,local_7c,uVar21,local_108);
                          }
                          iVar20 = iVar20 + 1;
                        } while (iVar20 <= piVar10[0x21]);
                        if (bVar1) goto LAB_00153df4;
                      }
                      fVar3 = FLOAT_001aa0d4;
                      bVar2 = *(byte *)((int)&local_110 + iVar22);
                      if (0 < piVar11[0x21]) {
                        iVar20 = 1;
                        do {
                          iVar23 = FUN_001054ec(piVar11,iVar20);
                          uVar21 = (uint)*(byte *)((uint)bVar2 + iVar23 + 0x10);
                          if (((uVar21 != 4) &&
                              (iVar23 = FUN_00105594(piVar11,iVar20),
                              ((int)*(char *)(iVar23 + 0x15c) >> (uVar21 & 0x3f) & 1U) != 0)) &&
                             (*(float *)(uVar21 * 0x18 + iVar23 + 0x20) == fVar3)) {
                            (**(code **)(*piVar11 + 0x88))(piVar11,iVar20,uVar21,4);
                            (**(code **)(*piVar11 + 0x88))(piVar11,uVar9,uVar21,local_100);
                          }
                          iVar20 = iVar20 + 1;
                        } while (iVar20 <= piVar11[0x21]);
                      }
                    }
LAB_00153df4:
                    bVar1 = iVar22 == 3;
                    iVar22 = iVar22 + 1;
                    local_64 = (int *)((int)local_64 + 1);
                    if (bVar1) {
                      iVar4 = 0;
                      piVar16 = piVar11 + 0x27;
                      piVar15 = piVar10 + 0x27;
                      do {
                        if (*(char *)(iVar4 + (int)local_68) == '\0') {
                          (**(code **)(*piVar10 + 0x88))(piVar10,iVar6,iVar4,local_104);
                          *(undefined1 *)piVar15 = 0;
                          (**(code **)(*piVar11 + 0x88))(piVar11,iVar8,iVar4,local_fc);
                          *(undefined1 *)piVar16 = 0;
                        }
                        bVar1 = iVar4 != 3;
                        piVar15 = (int *)((int)piVar15 + 1);
                        piVar16 = (int *)((int)piVar16 + 1);
                        iVar4 = iVar4 + 1;
                      } while (bVar1);
                      iVar6 = 0;
                      iVar8 = 4;
                      do {
                        if (*(char *)((int)&local_118 + iVar6) == '\0') {
                          uVar5 = (undefined1)iVar6;
                          if (*(char *)((int)&local_114 + iVar6) == '\x04') {
                            *(undefined1 *)((int)&local_114 + iVar6) = uVar5;
                          }
                          if (*(char *)((int)&local_110 + iVar6) == '\x04') {
                            *(undefined1 *)((int)&local_110 + iVar6) = uVar5;
                          }
                          if (*(char *)((int)&local_10c + iVar6) == '\x04') {
                            *(undefined1 *)((int)&local_10c + iVar6) = uVar5;
                          }
                        }
                        iVar6 = iVar6 + 1;
                        iVar8 = iVar8 + -1;
                      } while (iVar8 != 0);
                      local_e8 = 0;
                      local_e4 = 0;
                      local_d4 = 0;
                      if ((param_2[5] & 0x200U) != 0) {
                        FUN_00104d3c(param_2,&local_e8);
                      }
                      local_d0 = 0;
                      local_cc = 0;
                      local_bc = 0;
                      local_b8 = 0;
                      local_b4 = 0;
                      local_a4 = 0;
                      local_a0 = 0;
                      local_9c = 0;
                      local_8c = 0;
                      uVar7 = FUN_001054ec(piVar14,1);
                      FUN_00104730(&local_a0,uVar7);
                      uVar7 = FUN_001054ec(piVar17,1);
                      FUN_00104730(&local_d0,uVar7);
                      uVar7 = FUN_001054ec(piVar17,2);
                      FUN_00104730(&local_b8,uVar7);
                      local_f4 = 0;
                      local_f0 = 0;
                      local_ec = 0;
                      FUN_00103f18(param_1,&local_f4,0xffffffff);
                      iVar6 = param_1[1];
                      FUN_0019401c(param_1);
                      FUN_00108304(param_1,0x14,uVar18);
                      FUN_000e7738(*(undefined4 *)(iVar6 + 0x158),iVar6,param_1);
                      param_1[0x26] = 0;
                      param_1[0x25] = param_1[0x53];
                      FUN_00103f44(param_1,&local_f4);
                      param_1[0x48] = param_2[0x48];
                      param_1[0x27] = local_118;
                      param_1[0x49] = local_78;
                      uVar7 = FUN_001054ec(param_1,1);
                      FUN_00104730(uVar7,&local_d0);
                      FUN_00106004(param_1,1,piVar10,0,uVar18);
                      FUN_000e7700(param_1[0x56],param_1,piVar10);
                      uVar7 = local_114;
                      iVar6 = FUN_001054ec(param_1,1);
                      *(undefined4 *)(iVar6 + 0x10) = uVar7;
                      uVar7 = FUN_001054ec(param_1,2);
                      FUN_00104730(uVar7,&local_b8);
                      FUN_00106004(param_1,2,piVar11,0,uVar18);
                      FUN_000e7700(param_1[0x56],param_1,piVar11);
                      uVar7 = local_110;
                      iVar6 = FUN_001054ec(param_1,2);
                      *(undefined4 *)(iVar6 + 0x10) = uVar7;
                      FUN_00103d50(param_1 + 0x2f,1,0);
                      uVar7 = FUN_001054ec(param_1,3);
                      FUN_00104730(uVar7,&local_a0);
                      FUN_00106004(param_1,3,piVar12,0,uVar18);
                      FUN_000e7700(param_1[0x56],param_1,piVar12);
                      uVar7 = local_10c;
                      iVar6 = FUN_001054ec(param_1,3);
                      *(undefined4 *)(iVar6 + 0x10) = uVar7;
                      if (local_e4 != 0) {
                        FUN_00106b48(param_1,&local_e8,0,uVar18);
                        if (*(int *)(param_3 + 0x478) < *(int *)(local_e4 + 0x160)) {
                          *(int *)(local_e4 + 0x160) = *(int *)(local_e4 + 0x160) + 1;
                        }
                        else {
                          *(int *)(local_e4 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                        }
                      }
                      iVar6 = FUN_00105594(param_2,1);
                      if (*(int *)(param_3 + 0x478) < *(int *)(iVar6 + 0x160)) {
                        *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar6 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                      }
                      if (piVar17 == param_2) {
                        iVar6 = FUN_00105594(param_2,2);
                        if (*(int *)(param_3 + 0x478) < *(int *)(iVar6 + 0x160)) {
                          *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
                        }
                        else {
                          *(int *)(iVar6 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                        }
                      }
                      FUN_00105894(param_2,uVar18);
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

/* FUN_001541f0 @ 0x1541f0 (3020 bytes) */
int FUN_001541f0(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int *piVar21;
  undefined4 uVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  undefined4 local_e8;
  undefined4 local_e4;
  int local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  int local_d0;
  int local_cc;
  int local_c8 [9];
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_5c;
  int local_58 [3];
  
  iVar4 = (**(code **)(*param_1 + 100))();
  if (((iVar4 != 0) && (*(int *)(param_2[0x22] + 8) == 0x13)) ||
     ((iVar4 = (**(code **)(*param_2 + 100))(param_2), iVar4 != 0 &&
      (*(int *)(param_1[0x22] + 8) == 0x13)))) {
    uVar5 = FUN_00105594(param_1,1);
    uVar22 = *(undefined4 *)(param_3 + 8);
    iVar4 = FUN_001054ec(param_1,1);
    iVar4 = FUN_0010453c(uVar5,uVar22,*(undefined4 *)(iVar4 + 0x10));
    uVar5 = FUN_00105594(param_2,1);
    uVar22 = *(undefined4 *)(param_3 + 8);
    iVar6 = FUN_001054ec(param_2,1);
    iVar6 = FUN_0010453c(uVar5,uVar22,*(undefined4 *)(iVar6 + 0x10));
    if ((param_2[0x48] == param_1[0x48]) && (param_1[0x49] == param_2[0x49])) {
      iVar7 = FUN_001054ec(param_1,0);
      local_e8 = *(undefined4 *)(iVar7 + 0x10);
      iVar8 = FUN_001054ec(param_2,0);
      iVar7 = 0;
      local_e4 = *(undefined4 *)(iVar8 + 0x10);
      iVar8 = 4;
      do {
        if ((*(char *)((int)&local_e8 + iVar7) != '\x01') &&
           (*(char *)((int)&local_e4 + iVar7) != '\x01')) {
          return 0;
        }
        iVar7 = iVar7 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      iVar7 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x30);
      if ((iVar7 == 0) || (((char)local_e8 != '\0' && ((char)local_e4 != '\0')))) {
        iVar7 = (**(code **)(*param_1 + 100))(param_1);
        uVar5 = local_e8;
        piVar12 = param_2;
        piVar21 = param_1;
        if (iVar7 == 0) {
          local_e8 = local_e4;
          local_e4 = uVar5;
          piVar12 = param_1;
          piVar21 = param_2;
          iVar4 = iVar6;
        }
        if (iVar4 == 0) {
          uVar5 = FUN_00105594(piVar21,1);
          uVar22 = FUN_00105594(piVar12,1);
          iVar4 = FUN_00146de0(uVar5,uVar22);
          if (iVar4 == 0) {
            uVar5 = FUN_00105594(piVar21,1);
            uVar22 = FUN_00105594(piVar12,2);
            iVar4 = FUN_00146de0(uVar5,uVar22);
            if (iVar4 == 0) {
              iVar4 = FUN_00105594(piVar21,1);
              iVar6 = FUN_00105594(piVar12,1);
              if (iVar4 != iVar6) {
                iVar4 = FUN_00105594(piVar21,1);
                iVar6 = FUN_00105594(piVar12,2);
                if ((iVar4 != iVar6) && (iVar4 = FUN_0010497c(param_2,param_3), iVar4 != 0)) {
                  iVar8 = -1;
                  bVar3 = true;
                  bVar2 = false;
                  FUN_000f2f84(local_58,local_e4,local_e8);
                  local_e0 = local_58[0];
                  iVar16 = param_1[0x49];
                  uVar5 = FUN_00105594(piVar12,1);
                  iVar7 = -1;
                  piVar9 = (int *)((int (*)())FUN_0010bed0)((double)FLOAT_001aa0d4,2,local_58[0],uVar5,param_3,
                                               *(undefined4 *)(param_3 + 8));
                  iVar4 = local_e0;
                  uVar5 = FUN_00105594(piVar12,2);
                  iVar18 = -1;
                  piVar10 = (int *)((int (*)())FUN_0010bed0)((double)FLOAT_001aa0d4,2,iVar4,uVar5,param_3,
                                                *(undefined4 *)(param_3 + 8));
                  iVar4 = local_e0;
                  uVar5 = FUN_00105594(piVar21,1);
                  iVar19 = -1;
                  piVar11 = (int *)((int (*)())FUN_0010bed0)((double)FLOAT_001aa0d4,2,iVar4,uVar5,param_3,
                                                *(undefined4 *)(param_3 + 8));
                  iVar4 = FUN_001054ec(piVar12,1);
                  local_dc = *(undefined4 *)(iVar4 + 0x10);
                  iVar4 = FUN_001054ec(piVar12,2);
                  local_d8 = *(undefined4 *)(iVar4 + 0x10);
                  iVar4 = FUN_001054ec(piVar21,1);
                  local_d4 = *(undefined4 *)(iVar4 + 0x10);
                  local_c8[0] = DAT_001b0174;
                  iVar14 = 0;
                  local_d0 = DAT_001b0174;
                  iVar25 = 4;
                  local_cc = DAT_001b0174;
                  iVar4 = -1;
                  iVar6 = -1;
                  bVar1 = bVar3;
                  do {
                    iVar15 = iVar4;
                    iVar17 = iVar6;
                    if (*(char *)((int)&local_e8 + iVar14) == '\0') {
                      iVar17 = iVar14;
                      if (-1 < iVar6) {
                        if (bVar3) {
                          bVar3 = iVar14 < 0;
                          iVar17 = iVar6;
                          iVar7 = iVar14;
                        }
                        else {
                          iVar17 = iVar6;
                          if (iVar8 < 0) {
                            iVar8 = iVar14;
                          }
                        }
                      }
                    }
                    else if ((*(char *)((int)&local_e4 + iVar14) == '\0') &&
                            (iVar15 = iVar14, -1 < iVar4)) {
                      if (bVar1) {
                        bVar1 = iVar14 < 0;
                        bVar2 = 0 < iVar14;
                        iVar15 = iVar4;
                        iVar18 = iVar14;
                      }
                      else {
                        iVar15 = iVar4;
                        if (iVar19 < 0) {
                          iVar19 = iVar14;
                        }
                      }
                    }
                    iVar14 = iVar14 + 1;
                    iVar25 = iVar25 + -1;
                    iVar4 = iVar15;
                    iVar6 = iVar17;
                  } while (iVar25 != 0);
                  uVar23 = (uint)*(byte *)((int)&local_d8 + iVar15);
                  uVar13 = (uint)*(byte *)((int)&local_dc + iVar15);
                  *(undefined1 *)((int)&local_cc + uVar23) = 0;
                  *(undefined1 *)((int)&local_d0 + uVar13) = 0;
                  (**(code **)(*piVar9 + 0x88))(piVar9,1,uVar13,uVar13);
                  (**(code **)(*piVar10 + 0x88))(piVar10,1,uVar23,uVar23);
                  if (bVar2) {
                    uVar23 = (uint)*(byte *)((int)&local_d8 + iVar18);
                    uVar13 = (uint)*(byte *)((int)&local_dc + iVar18);
                    *(undefined1 *)((int)&local_cc + uVar23) = 0;
                    *(undefined1 *)((int)&local_d0 + uVar13) = 0;
                    (**(code **)(*piVar9 + 0x88))(piVar9,1,uVar13,uVar13);
                    (**(code **)(*piVar10 + 0x88))(piVar10,1,uVar23,uVar23);
                    if (0 < iVar19) {
                      uVar23 = (uint)*(byte *)((int)&local_d8 + iVar19);
                      uVar13 = (uint)*(byte *)((int)&local_dc + iVar19);
                      *(undefined1 *)((int)&local_cc + uVar23) = 0;
                      *(undefined1 *)((int)&local_d0 + uVar13) = 0;
                      (**(code **)(*piVar9 + 0x88))(piVar9,1,uVar13,uVar13);
                      (**(code **)(*piVar10 + 0x88))(piVar10,1,uVar23,uVar23);
                    }
                  }
                  uVar13 = (uint)*(byte *)((int)&local_d4 + iVar17);
                  *(undefined1 *)((int)local_c8 + uVar13) = 0;
                  (**(code **)(*piVar11 + 0x88))(piVar11,1,uVar13,uVar13);
                  if (!bVar3) {
                    uVar13 = (uint)*(byte *)((int)&local_d4 + iVar7);
                    *(undefined1 *)((int)local_c8 + uVar13) = 0;
                    (**(code **)(*piVar11 + 0x88))(piVar11,1,uVar13,uVar13);
                    if (-1 < iVar8) {
                      uVar13 = (uint)*(byte *)((int)&local_d4 + iVar8);
                      *(undefined1 *)((int)local_c8 + uVar13) = 0;
                      (**(code **)(*piVar11 + 0x88))(piVar11,1,uVar13,uVar13);
                    }
                  }
                  uVar13 = 0xffffffff;
                  uVar23 = 0xffffffff;
                  uVar20 = 0xffffffff;
                  uVar24 = 0;
                  do {
                    iVar4 = FUN_001054ec(piVar9,1);
                    if ((uVar24 != *(byte *)(uVar24 + iVar4 + 0x10)) && ((int)uVar13 < 0)) {
                      (**(code **)(*piVar9 + 0x88))(piVar9,2,uVar24,uVar24);
                      *(undefined1 *)((int)&local_d0 + uVar24) = 0;
                      uVar13 = uVar24;
                    }
                    iVar4 = FUN_001054ec(piVar10,1);
                    if ((uVar24 != *(byte *)(uVar24 + iVar4 + 0x10)) && ((int)uVar23 < 0)) {
                      (**(code **)(*piVar10 + 0x88))(piVar10,2,uVar24,uVar24);
                      *(undefined1 *)((int)&local_cc + uVar24) = 0;
                      uVar23 = uVar24;
                    }
                    iVar4 = FUN_001054ec(piVar11,1);
                    if ((uVar24 != *(byte *)(uVar24 + iVar4 + 0x10)) && ((int)uVar20 < 0)) {
                      (**(code **)(*piVar11 + 0x88))(piVar11,2,uVar24,uVar24);
                      *(undefined1 *)((int)local_c8 + uVar24) = 0;
                      uVar20 = uVar24;
                    }
                    bVar3 = uVar24 != 3;
                    uVar24 = uVar24 + 1;
                  } while (bVar3);
                  iVar4 = 0;
                  piVar9[0x27] = local_d0;
                  piVar10[0x27] = local_cc;
                  piVar11[0x27] = local_c8[0];
                  uVar24 = param_2[5];
                  if ((uVar24 & 0x200) != 0) {
                    iVar4 = FUN_00105594(param_2,param_2[0x21]);
                    uVar24 = param_2[5];
                  }
                  local_c8[4] = 0;
                  local_c8[5] = 0;
                  local_a4 = 0;
                  if ((uVar24 & 0x200) != 0) {
                    FUN_00104d3c(param_2,local_c8 + 4);
                  }
                  local_a0 = 0;
                  local_9c = 0;
                  local_8c = 0;
                  local_88 = 0;
                  local_84 = 0;
                  local_74 = 0;
                  local_70 = 0;
                  local_6c = 0;
                  local_5c = 0;
                  iVar6 = param_1[1];
                  uVar5 = FUN_001054ec(piVar21,1);
                  FUN_00104730(&local_70,uVar5);
                  uVar5 = FUN_001054ec(piVar12,1);
                  FUN_00104730(&local_a0,uVar5);
                  uVar5 = FUN_001054ec(piVar12,2);
                  FUN_00104730(&local_88,uVar5);
                  local_c8[3] = 0;
                  local_c8[1] = 0;
                  local_c8[2] = 0;
                  FUN_00103f18(param_1,local_c8 + 1,0xffffffff);
                  FUN_0019401c(param_1);
                  FUN_00108304(param_1,0x14,*(undefined4 *)(param_3 + 8));
                  if (iVar4 != 0) {
                    FUN_00106b48(param_1,local_c8 + 4,0,*(undefined4 *)(param_3 + 8));
                    if (*(int *)(param_3 + 0x478) < *(int *)(iVar4 + 0x160)) {
                      *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar4 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                    }
                  }
                  FUN_00103f44(param_1,local_c8 + 1);
                  iVar4 = param_2[0x48];
                  param_1[0x49] = iVar16;
                  param_1[0x48] = iVar4;
                  uVar5 = FUN_001054ec(param_1,3);
                  FUN_00104730(uVar5,&local_70);
                  iVar4 = 0;
                  uVar5 = FUN_001054ec(param_1,1);
                  FUN_00104730(uVar5,&local_a0);
                  uVar5 = FUN_001054ec(param_1,2);
                  FUN_00104730(uVar5,&local_88);
                  do {
                    if (*(char *)((int)&local_e0 + iVar4) == '\0') {
                      iVar7 = FUN_001054ec(param_1,1);
                      if (*(char *)(iVar4 + iVar7 + 0x10) == '\x04') {
                        (**(code **)(*param_1 + 0x88))(param_1,1,iVar4,uVar13);
                      }
                      iVar7 = FUN_001054ec(param_1,2);
                      if (*(char *)(iVar4 + iVar7 + 0x10) == '\x04') {
                        (**(code **)(*param_1 + 0x88))(param_1,2,iVar4,uVar23);
                      }
                      iVar7 = FUN_001054ec(param_1,3);
                      if (*(char *)(iVar4 + iVar7 + 0x10) == '\x04') {
                        (**(code **)(*param_1 + 0x88))(param_1,3,iVar4,uVar20);
                      }
                    }
                    bVar3 = iVar4 != 3;
                    iVar4 = iVar4 + 1;
                  } while (bVar3);
                  param_1[0x26] = 0;
                  param_1[0x25] = param_1[0x53];
                  FUN_000e7738(*(undefined4 *)(iVar6 + 0x158),iVar6,param_1);
                  FUN_00106004(param_1,1,piVar9,0,*(undefined4 *)(param_3 + 8));
                  FUN_00106004(param_1,2,piVar10,0,*(undefined4 *)(param_3 + 8));
                  FUN_00106004(param_1,3,piVar11,0,*(undefined4 *)(param_3 + 8));
                  FUN_000e7700(param_1[0x56],param_1,piVar9);
                  FUN_000e7700(param_1[0x56],param_1,piVar10);
                  FUN_000e7700(param_1[0x56],param_1,piVar11);
                  param_1[0x27] = local_e0;
                  iVar4 = FUN_00105594(param_2,1);
                  if (*(int *)(param_3 + 0x478) < *(int *)(iVar4 + 0x160)) {
                    *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar4 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                  }
                  if (piVar12 == param_2) {
                    iVar4 = FUN_00105594(piVar12,2);
                    if (*(int *)(param_3 + 0x478) < *(int *)(iVar4 + 0x160)) {
                      *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar4 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                    }
                  }
                  piVar12 = (int *)FUN_00105594(piVar9,1);
                  iVar4 = (**(code **)(*piVar12 + 0x60))();
                  if (iVar4 != 0) {
                    uVar5 = FUN_00105594(piVar9,1);
                    FUN_0010c670(uVar5,piVar9,*(undefined4 *)(param_3 + 8));
                  }
                  piVar12 = (int *)FUN_00105594(piVar10,1);
                  iVar4 = (**(code **)(*piVar12 + 0x60))();
                  if (iVar4 != 0) {
                    uVar5 = FUN_00105594(piVar10,1);
                    FUN_0010c670(uVar5,piVar10,*(undefined4 *)(param_3 + 8));
                  }
                  piVar12 = (int *)FUN_00105594(piVar11,1);
                  iVar4 = (**(code **)(*piVar12 + 0x60))();
                  if (iVar4 != 0) {
                    uVar5 = FUN_00105594(piVar11,1);
                    FUN_0010c670(uVar5,piVar11,*(undefined4 *)(param_3 + 8));
                  }
                  FUN_00105894(param_2,*(undefined4 *)(param_3 + 8));
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

/* FUN_00154dc0 @ 0x154dc0 (1700 bytes) */
int FUN_00154dc0(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int *piVar19;
  undefined4 local_88;
  int local_84;
  int local_80;
  int local_7c;
  undefined4 local_78;
  int local_74 [7];
  int local_58;
  int local_54;
  
  iVar18 = *(int *)(param_2 + 8);
  if (((((param_1 != (int *)0x0) && ((param_1[5] & 0x200U) != 0)) && (param_1[0x48] == 0)) &&
      ((param_1[0x49] == 0 &&
       (piVar8 = (int *)FUN_00105594(param_1,param_1[0x21]), piVar8[0x48] == 0)))) &&
     (piVar8[0x49] == 0)) {
    iVar9 = (**(code **)(*param_1 + 100))(param_1);
    iVar10 = (**(code **)(*piVar8 + 100))(piVar8);
    if ((iVar9 != 0) && (iVar10 != 0)) {
      iVar11 = FUN_00105594(param_1,1);
      iVar12 = FUN_00105594(piVar8,1);
      if (iVar11 == iVar12) {
        return 0;
      }
    }
    iVar11 = FUN_000f3884(piVar8);
    iVar12 = FUN_000f3884(param_1);
    if ((iVar11 != 0) || (iVar12 != 0)) {
      iVar11 = FUN_001054ec(piVar8,0);
      local_7c = *(int *)(iVar11 + 0x10);
      iVar11 = FUN_001054ec(param_1,0);
      local_84 = *(int *)(iVar11 + 0x10);
      if ((local_84 != DAT_001b0054) && (DAT_001b0054 != local_7c)) {
        piVar19 = piVar8;
        if (iVar9 == 0) {
          if (iVar10 == 0) {
            return 0;
          }
          iVar10 = 0;
          piVar19 = param_1;
          param_1 = piVar8;
        }
        iVar9 = FUN_0010497c(piVar19,param_2);
        if (iVar9 == 0) {
          pcVar5 = *(code **)(*piVar19 + 0x4c);
        }
        else {
          pcVar5 = *(code **)(*piVar19 + 100);
        }
        iVar9 = (*pcVar5)(piVar19);
        if (iVar9 != 0) {
          iVar9 = 0;
          iVar11 = 4;
          do {
            if ((*(char *)((int)&local_84 + iVar9) != '\x01') &&
               (*(char *)((int)&local_7c + iVar9) != '\x01')) {
              return 0;
            }
            iVar9 = iVar9 + 1;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
          local_74[2] = 0x3f800000;
          local_74[4] = 0;
          local_88 = DAT_001b004c;
          local_74[1] = 0;
          local_74[3] = 0;
          iVar9 = (**(code **)(**(int **)(iVar18 + 0x30c) + 0x154))
                            (*(int **)(iVar18 + 0x30c),param_2,local_74 + 1,&local_88);
          if (iVar9 != 0) {
            iVar12 = FUN_000f37b8(local_7c);
            iVar13 = FUN_000f37b8(local_84);
            iVar11 = iVar13;
            if (-1 >= iVar13) {
              iVar11 = iVar12;
            }
            if (local_88 == DAT_001b004c) {
              local_88 = *(int *)(&DAT_001b0160 + iVar11 * 4);
            }
            else if (iVar11 == 0) {
              uVar7 = (uint)local_88 >> 0x18;
              uVar6 = (uint)local_88 >> 0x10;
              local_88 = CONCAT13((char)uVar6,CONCAT12((char)uVar7,(*(unsigned short *)((unsigned char *)&(local_88) + 2))));
              iVar11 = (**(code **)(**(int **)(iVar18 + 0x30c) + 0x100))
                                 (*(int **)(iVar18 + 0x30c),&local_88);
              if (iVar11 == 0) {
                return 0;
              }
            }
            bVar1 = iVar10 == 0;
            uVar14 = FUN_00105594(param_1,1);
            piVar8 = piVar19;
            if (!bVar1) {
              piVar8 = (int *)FUN_00105594(piVar19,1);
            }
            uVar6 = param_1[5];
            local_54 = param_1[1];
            local_58 = param_1[0x56];
            iVar10 = FUN_00104054(param_1,param_2);
            uVar7 = param_1[0x2e];
            iVar11 = FUN_001054ec(param_1,1);
            local_78 = *(undefined4 *)(iVar11 + 0x10);
            if (bVar1) {
              uVar17 = 0;
              uVar16 = 0;
              local_74[0] = DAT_001b004c;
            }
            else {
              uVar16 = piVar19[0x2e] & 1;
              uVar17 = (uint)piVar19[0x2e] >> 1 & 1;
              iVar11 = FUN_001054ec(piVar19,1);
              local_74[0] = *(int *)(iVar11 + 0x10);
            }
            iVar11 = param_1[0x26];
            iVar12 = param_1[0x25];
            FUN_0019401c(param_1);
            if (-1 < iVar13) {
              FUN_00108304(param_1,0x24,*(undefined4 *)(param_2 + 8));
            }
            else {
              FUN_00108304(param_1,0x26,*(undefined4 *)(param_2 + 8));
            }
            iVar13 = DAT_001b004c;
            iVar15 = FUN_001054ec(param_1,1);
            *(int *)(iVar15 + 0x10) = iVar13;
            FUN_00106004(param_1,1,iVar9,0,iVar18);
            iVar9 = local_88;
            iVar13 = FUN_001054ec(param_1,1);
            *(int *)(iVar13 + 0x10) = iVar9;
            FUN_00106004(param_1,2,piVar8,0,iVar18);
            FUN_00103d50(param_1 + 0x2f,1,uVar16);
            FUN_00103d50(param_1 + 0x2f,2,uVar17);
            FUN_00106004(param_1,3,uVar14,0,iVar18);
            FUN_00103d50(param_1 + 0x35,1,uVar7 & 1);
            FUN_00103d50(param_1 + 0x35,2,uVar7 >> 1 & 1);
            iVar9 = FUN_000f30d4(local_84);
            uVar3 = *(undefined1 *)((int)&local_78 + iVar9);
            iVar13 = FUN_000f30d4(local_7c);
            iVar9 = 0;
            local_80 = local_84;
            uVar4 = *(undefined1 *)((int)local_74 + iVar13);
            iVar13 = 4;
            do {
              if (*(char *)((int)&local_7c + iVar9) != '\x01') {
                *(char *)((int)&local_80 + iVar9) = *(char *)((int)&local_7c + iVar9);
              }
              iVar9 = iVar9 + 1;
              iVar13 = iVar13 + -1;
            } while (iVar13 != 0);
            iVar9 = 0;
            param_1[0x25] = iVar12;
            param_1[0x27] = local_80;
            param_1[0x26] = iVar11;
            do {
              if (*(char *)((int)&local_80 + iVar9) == '\x01') {
                (**(code **)(*param_1 + 0x88))(param_1,2,iVar9,4);
                (**(code **)(*param_1 + 0x88))(param_1,3,iVar9,4);
                (**(code **)(*param_1 + 0x88))(param_1,1,iVar9,4);
              }
              else if (*(char *)((int)&local_84 + iVar9) == '\0') {
                (**(code **)(*param_1 + 0x88))(param_1,2,iVar9,uVar4);
                (**(code **)(*param_1 + 0x88))
                          (param_1,3,iVar9,*(undefined1 *)((int)&local_78 + iVar9));
              }
              else if (*(char *)((int)&local_7c + iVar9) == '\0') {
                (**(code **)(*param_1 + 0x88))
                          (param_1,2,iVar9,*(undefined1 *)((int)local_74 + iVar9));
                (**(code **)(*param_1 + 0x88))(param_1,3,iVar9,uVar3);
              }
              bVar2 = iVar9 != 3;
              iVar9 = iVar9 + 1;
            } while (bVar2);
            if ((uVar6 & 2) != 0) {
              param_1[5] = param_1[5] | 2;
            }
            param_1[0x58] = iVar10 + *(int *)(param_2 + 0x478);
            FUN_000e7738(local_58,local_54,param_1);
            if ((piVar19[5] & 0x200U) != 0) {
              uVar14 = FUN_00105594(piVar19,piVar19[0x21]);
              FUN_00106804(param_1,uVar14,0,iVar18);
            }
            if (!bVar1) {
              (**(code **)(*piVar19 + 0xc))(piVar19,0,*(undefined4 *)(param_2 + 8));
            }
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_0015546c @ 0x15546c (488 bytes) */
int FUN_0015546c(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (*(int *)(*(int *)(param_3 + 0x88) + 8) != 0x25) {
    return 0;
  }
  piVar1 = (int *)FUN_00105594(param_3,1);
  iVar2 = (**(code **)(*piVar1 + 0x5c))();
  if (iVar2 != 0) {
    piVar1 = (int *)FUN_00105594(param_3,2);
    iVar2 = (**(code **)(*piVar1 + 0x5c))();
    if (iVar2 != 0) {
      piVar1 = (int *)FUN_00105594(param_3,3);
      iVar2 = (**(code **)(*piVar1 + 0x5c))();
      if (iVar2 != 0) {
        uVar4 = FUN_00105594(param_3,1);
        uVar5 = FUN_00105594(param_3,2);
        uVar6 = FUN_00105594(param_3,3);
        iVar2 = FUN_00105594(uVar4,1);
        iVar3 = FUN_00105594(uVar5,1);
        if (iVar2 == iVar3) {
          iVar2 = FUN_00105594(uVar4,2);
          iVar3 = FUN_00105594(uVar5,2);
          if (iVar2 == iVar3) {
            iVar2 = FUN_00105594(uVar5,1);
            iVar3 = FUN_00105594(uVar6,1);
            if (iVar2 == iVar3) {
              FUN_00105594(uVar5,2);
              FUN_00105594(uVar6,2);
            }
          }
        }
        goto LAB_00155544;
      }
    }
  }
  iVar2 = FUN_00105594(param_3,1);
  iVar3 = FUN_00105594(param_3,2);
  if (iVar2 == iVar3) {
    FUN_00105594(param_3,2);
    FUN_00105594(param_3,3);
  }
LAB_00155544:
  iVar2 = FUN_00105594(param_3,1);
  iVar3 = FUN_00105594(param_3,2);
  if (iVar2 == iVar3) {
    FUN_00105594(param_3,2);
    FUN_00105594(param_3,3);
  }
  return 0;
}

/* FUN_00155654 @ 0x155654 (1036 bytes) */
int FUN_00155654(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int local_28 [2];
  
  iVar1 = *(int *)(*(int *)(param_3 + 0x88) + 8);
  if ((iVar1 != 0x17) && (iVar1 != 0x19)) {
    return 0;
  }
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar1 = (**(code **)(*param_1 + 0x14))();
  if (iVar1 < param_2) {
    return 0;
  }
  if ((*(uint *)(param_3 + 0x14) & 0x200) != 0) {
    return 0;
  }
  if (*(int *)(param_3 + 0x120) != 0) {
    return 0;
  }
  if (*(int *)(param_3 + 0x124) != 0) {
    return 0;
  }
  iVar1 = (**(code **)(**(int **)(*(int *)(param_4 + 8) + 0x30c) + 0x88))();
  if ((iVar1 == 0) &&
     (iVar1 = FUN_00113258(*(undefined4 *)(param_1[0x22] + 8),*(undefined4 *)(param_4 + 8)),
     iVar1 == 0)) {
    return 0;
  }
  FUN_00105594(param_1,param_2);
  piVar2 = (int *)FUN_00105594(param_3,1);
  piVar3 = (int *)FUN_00105594(param_3,2);
  if (piVar2 != piVar3) {
    iVar1 = (**(code **)(*piVar2 + 0x5c))(piVar2);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = (**(code **)(*piVar3 + 0x5c))(piVar3);
    if (iVar1 == 0) {
      return 0;
    }
    if (*(int *)(piVar2[0x22] + 8) != *(int *)(piVar3[0x22] + 8)) {
      return 0;
    }
    iVar1 = FUN_00105594(piVar2,1);
    iVar4 = FUN_00105594(piVar3,1);
    if (iVar1 != iVar4) {
      return 0;
    }
    iVar1 = (**(code **)(*piVar2 + 0x14))(piVar2);
    if (1 < iVar1) {
      iVar1 = FUN_00105594(piVar2,2);
      iVar4 = FUN_00105594(piVar3,2);
      if (iVar1 != iVar4) {
        return 0;
      }
    }
  }
  if (((*(uint *)(param_3 + 0xb8) >> 1 & 1) == (*(uint *)(param_3 + 0xd0) >> 1 & 1)) &&
     ((*(uint *)(param_3 + 0xb8) & 1) == (*(uint *)(param_3 + 0xd0) & 1 ^ 1))) {
    iVar1 = FUN_001054ec(param_3,1);
    iVar4 = *(int *)(iVar1 + 0x10);
    iVar1 = FUN_001054ec(param_3,2);
    if (iVar4 == *(int *)(iVar1 + 0x10)) {
      iVar4 = *(int *)(param_4 + 0x478);
      iVar1 = (**(code **)(*piVar2 + 0x5c))(piVar2);
      if (iVar1 == 0) {
        if (iVar4 < piVar2[0x58]) {
          piVar2[0x58] = piVar2[0x58] + 1;
        }
        else {
          piVar2[0x58] = iVar4 + 1;
        }
        FUN_00106004(param_1,param_2,piVar2,0,*(undefined4 *)(param_4 + 8));
      }
      else {
        iVar1 = FUN_0010445c(piVar2,*(undefined4 *)(param_4 + 8),0);
        *(undefined4 *)(iVar1 + 0x98) = 0x31;
        *(undefined4 *)(iVar1 + 0x94) = *(undefined4 *)(iVar1 + 0x14c);
        iVar6 = iVar4 + 1;
        FUN_000e7738(piVar2[0x56],piVar2,iVar1);
        *(int *)(iVar1 + 0x160) = iVar6;
        iVar5 = FUN_00105594(iVar1,1);
        if (iVar4 < *(int *)(iVar5 + 0x160)) {
          *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + 1;
        }
        else {
          *(int *)(iVar5 + 0x160) = iVar6;
        }
        if (1 < *(int *)(iVar1 + 0x84)) {
          iVar5 = FUN_00105594(iVar1,2);
          if (iVar4 < *(int *)(iVar5 + 0x160)) {
            *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + 1;
          }
          else {
            *(int *)(iVar5 + 0x160) = iVar6;
          }
        }
        FUN_00106004(param_1,param_2,iVar1,0,*(undefined4 *)(param_4 + 8));
      }
      iVar1 = FUN_001054ec(param_3,1);
      uVar7 = *(undefined4 *)(iVar1 + 0x10);
      iVar1 = FUN_001054ec(param_1,param_2);
      FUN_000f2bdc(local_28,uVar7,*(undefined4 *)(iVar1 + 0x10));
      if (param_2 == 0) {
        param_1[0x27] = local_28[0];
      }
      else {
        iVar1 = FUN_001054ec(param_1,param_2);
        *(int *)(iVar1 + 0x10) = local_28[0];
      }
      iVar1 = FUN_00113258(*(undefined4 *)(param_1[0x22] + 8),*(undefined4 *)(param_4 + 8));
      if (iVar1 == 0) {
        FUN_00103d50(param_1 + param_2 * 6 + 0x23,2,1);
      }
      else {
        FUN_00103d50(param_1 + param_2 * 6 + 0x23,2,0);
      }
      if (*(int *)(*(int *)(param_3 + 0x88) + 8) == 0x19) {
        FUN_00103d50(param_1 + param_2 * 6 + 0x23,1,1);
      }
      *(int *)(param_4 + 0x1bc) = *(int *)(param_4 + 0x1bc) + 1;
      FUN_00105894(param_3,*(undefined4 *)(param_4 + 8));
      return 1;
    }
  }
  return 0;
}

/* FUN_00155a60 @ 0x155a60 (4688 bytes) */
int FUN_00155a60(param_1, param_2)
  void *param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  void *pvVar15;
  int iVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  int iVar21;
  int iVar22;
  undefined4 uVar23;
  int *piVar24;
  undefined4 uVar25;
  int iVar26;
  int *piVar27;
  undefined4 uVar28;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  undefined4 local_78;
  undefined4 local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  int local_5c;
  uint local_58;
  
  local_c4 = 0x3f800000;
  local_d0 = 0x3f800000;
  local_cc = 0x3f800000;
  local_c8 = 0x3f800000;
  local_b4 = 0x3f000000;
  local_a4 = 0x40000000;
  local_c0 = 0x3f000000;
  local_bc = 0x3f000000;
  local_b8 = 0x3f000000;
  local_b0 = 0x40000000;
  local_ac = 0x40000000;
  local_a8 = 0x40000000;
  iVar3 = *(int *)(*(int *)((int)param_1 + 0x88) + 8);
  if (iVar3 == 0x12) {
LAB_001563cc:
    uVar10 = 0;
  }
  else {
    if (iVar3 != 0x14) {
      return 0;
    }
    piVar8 = (int *)FUN_00105594(param_1,1);
    piVar9 = (int *)FUN_00105594(param_1,2);
    iVar3 = *(int *)(piVar8[0x22] + 8);
    if (((iVar3 == 0x12) || (iVar3 == 0x9b)) || (iVar3 == 0x9a)) {
      iVar3 = 1;
      iVar22 = 2;
LAB_00155dd0:
      iVar26 = *(int *)((int)param_1 + 0x124);
      iVar21 = FUN_001054ec(param_1,0);
      iVar21 = FUN_000f5c0c(param_1,iVar22,*(undefined4 *)(iVar21 + 0x10),&local_c0);
      if (iVar21 == 0) {
        iVar21 = FUN_001054ec(param_1,0);
        iVar21 = FUN_000f5c0c(param_1,iVar22,*(undefined4 *)(iVar21 + 0x10),&local_b0);
        if (iVar21 == 0) {
          return 0;
        }
        iVar26 = iVar26 + 1;
        piVar9 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
        iVar21 = (**(code **)(*piVar9 + 0xfc))(piVar9,iVar26,param_1);
        if (iVar21 == 0) {
          return 0;
        }
        iVar21 = 1;
      }
      else {
        iVar26 = iVar26 + -1;
        piVar9 = *(int **)(*(int *)(param_2 + 8) + 0x30c);
        iVar21 = 0;
        iVar14 = (**(code **)(*piVar9 + 0xfc))(piVar9,iVar26,param_1);
        if (iVar14 == 0) {
          return 0;
        }
      }
      iVar16 = FUN_00105594(piVar8,1);
      iVar14 = FUN_00105594(piVar8,2);
      iVar12 = FUN_00105c5c(param_1,3);
      if ((piVar8[5] & 0x200U) != 0) {
        return 0;
      }
      iVar13 = FUN_001054ec(param_1,iVar3);
      iVar13 = FUN_000f2d18(*(undefined4 *)(iVar13 + 0x10),DAT_001b004c);
      if (iVar13 == 0) {
        return 0;
      }
      iVar13 = FUN_00105c5c(param_1,iVar3);
      if (iVar13 != 0) {
        return 0;
      }
      iVar13 = FUN_00105594(param_1,3);
      if (iVar14 == iVar13) {
        iVar13 = FUN_001054ec(param_1,3);
        uVar10 = *(undefined4 *)(iVar13 + 0x10);
        iVar13 = FUN_001054ec(piVar8,2);
        iVar13 = FUN_000f2d18(uVar10,*(undefined4 *)(iVar13 + 0x10));
        if ((iVar13 == 0) || (iVar13 = FUN_00105c5c(piVar8,2), iVar12 != iVar13)) goto LAB_00155f5c;
        if (*(int *)(piVar8[0x22] + 8) == 0x9a) {
          iVar12 = 2;
          iVar16 = 1;
          bVar1 = true;
          bVar2 = false;
        }
        else {
          iVar12 = 2;
          iVar16 = 1;
          bVar1 = false;
          bVar2 = false;
        }
      }
      else {
LAB_00155f5c:
        iVar14 = FUN_00105594(param_1,3);
        if (iVar16 != iVar14) {
          return 0;
        }
        iVar14 = FUN_001054ec(param_1,3);
        uVar10 = *(undefined4 *)(iVar14 + 0x10);
        iVar14 = FUN_001054ec(piVar8,1);
        iVar14 = FUN_000f2d18(uVar10,*(undefined4 *)(iVar14 + 0x10));
        if (iVar14 == 0) {
          return 0;
        }
        iVar14 = FUN_00105c5c(piVar8,1);
        if (iVar12 != iVar14) {
          return 0;
        }
        iVar14 = iVar16;
        if (*(int *)(piVar8[0x22] + 8) == 0x9a) {
          iVar12 = 1;
          iVar16 = 2;
          bVar1 = false;
          bVar2 = true;
        }
        else {
          iVar12 = 1;
          iVar16 = 2;
          bVar1 = false;
          bVar2 = false;
        }
      }
      iVar13 = FUN_0010497c(piVar8,param_2);
      if ((((iVar13 == 0) || ((*(uint *)((int)param_1 + 0xe8) & 2) != 0)) ||
          ((*(uint *)((int)param_1 + iVar3 * 0x18 + 0xa0) & 2) != 0)) ||
         (((piVar8[0x2e] & 2U) != 0 || ((piVar8[0x34] & 2U) != 0)))) {
        return 0;
      }
      iVar13 = FUN_001054ec(param_1,iVar3);
      FUN_000f3398(&local_70,*(undefined4 *)(iVar13 + 0x10));
      iVar13 = FUN_001054ec(piVar8,0);
      FUN_000f3908(&local_6c,*(undefined4 *)(iVar13 + 0x10));
      if ((local_6c << 0x18 | (local_6c >> 8 & 0xff) << 0x10 | (local_6c >> 0x10 & 0xff) << 8 |
          local_6c >> 0x18) <
          (local_70 << 0x18 | (local_70 >> 8 & 0xff) << 0x10 | (local_70 >> 0x10 & 0xff) << 8 |
          local_70 >> 0x18)) {
        return 0;
      }
      if (local_6c != (local_6c & local_70)) {
        return 0;
      }
      if (piVar8[0x48] != 0) {
        return 0;
      }
      if (piVar8[0x49] != 0) {
        return 0;
      }
      if (((piVar8[iVar12 * 6 + 0x28] & 1U) != 0) || (iVar13 = 0, bVar1)) {
        iVar13 = 1;
      }
      if (((piVar8[iVar16 * 6 + 0x28] & 1U) != 0) || (iVar7 = 0, bVar2)) {
        iVar7 = 1;
      }
      uVar4 = *(uint *)(&DAT_001b0060 +
                       (*(uint *)((int)param_1 + iVar22 * 0x18 + 0xa0) & 1 |
                        (*(uint *)((int)param_1 + iVar3 * 0x18 + 0xa0) & 1) << 1 |
                        (*(uint *)((int)param_1 + 0xe8) & 1) << 2 | iVar13 << 3 | iVar7 << 4 |
                       iVar21 << 5) * 4);
      if (-1 < (int)uVar4) goto LAB_001563cc;
      iVar22 = 0;
      *(int *)(param_2 + 0x1b0) = *(int *)(param_2 + 0x1b0) + 1;
      iVar3 = FUN_001054ec(param_1,0);
      uVar11 = *(undefined4 *)(iVar3 + 0x10);
      uVar10 = *(undefined4 *)((int)param_1 + 0x120);
      if ((*(uint *)((int)param_1 + 0x14) & 0x200) != 0) {
        iVar22 = FUN_00105594(param_1,*(undefined4 *)((int)param_1 + 0x84));
      }
      iVar3 = FUN_00104054(param_1,param_2);
      iVar21 = *(int *)((int)param_1 + 4);
      if (0 < *(int *)((int)param_1 + 0x84)) {
        iVar13 = 1;
        do {
          iVar7 = iVar13 + 1;
          FUN_00106004(param_1,iVar13,0,0,*(undefined4 *)(param_2 + 8));
          iVar13 = iVar7;
        } while (iVar7 <= *(int *)((int)param_1 + 0x84));
      }
      uVar5 = *(uint *)((int)param_1 + 0x14);
      uVar19 = *(undefined4 *)((int)param_1 + 0x98);
      uVar20 = *(undefined4 *)((int)param_1 + 0x94);
      FUN_0019401c(param_1);
      FUN_00108174(param_1,0x12,*(undefined4 *)(param_2 + 8));
      *(undefined4 *)((int)param_1 + 0x9c) = uVar11;
      iVar13 = iVar12;
      if ((uVar4 & 0x40000000) == 0) {
        iVar13 = iVar16;
        iVar16 = iVar12;
      }
      *(undefined4 *)((int)param_1 + 0x94) = uVar20;
      *(undefined4 *)((int)param_1 + 0x98) = uVar19;
      if ((uVar5 & 2) != 0) {
        *(uint *)((int)param_1 + 0x14) = *(uint *)((int)param_1 + 0x14) | 2;
      }
      uVar11 = FUN_00105594(piVar8,iVar16);
      FUN_00106004(param_1,1,uVar11,0,*(undefined4 *)(param_2 + 8));
      uVar11 = FUN_00105594(piVar8,iVar13);
      FUN_00106004(param_1,2,uVar11,0,*(undefined4 *)(param_2 + 8));
      iVar16 = FUN_001054ec(piVar8,iVar16);
      uVar11 = *(undefined4 *)(iVar16 + 0x10);
      iVar16 = FUN_001054ec(param_1,1);
      *(undefined4 *)(iVar16 + 0x10) = uVar11;
      iVar16 = FUN_001054ec(piVar8,iVar13);
      uVar11 = *(undefined4 *)(iVar16 + 0x10);
      iVar16 = FUN_001054ec(param_1,2);
      *(undefined4 *)(iVar16 + 0x10) = uVar11;
      FUN_00103d50((int)param_1 + 0xa4,1,uVar4 >> 0x1d & 1);
      FUN_00103d50((int)param_1 + 0xbc,1,uVar4 >> 0x1c & 1);
      iVar16 = *(int *)(param_2 + 0x478);
      *(undefined4 *)((int)param_1 + 0x120) = uVar10;
      *(int *)((int)param_1 + 0x124) = iVar26;
      *(int *)((int)param_1 + 0x160) = iVar3 + iVar16;
      if (iVar22 != 0) {
        FUN_00106804(param_1,iVar22,0,*(undefined4 *)(param_2 + 8));
      }
      uVar10 = 0;
      FUN_000e7738(*(undefined4 *)(iVar21 + 0x158),iVar21,param_1);
      iVar21 = *(int *)(param_2 + 0x478);
      iVar22 = FUN_00104054(iVar14,param_2);
      iVar3 = *piVar8;
      *(int *)(iVar14 + 0x160) = iVar21 + iVar22 + -1;
      (**(code **)(iVar3 + 0xc))(piVar8,0,*(undefined4 *)(param_2 + 8));
    }
    else {
      iVar3 = *(int *)(piVar9[0x22] + 8);
      if (((iVar3 == 0x12) || (iVar3 == 0x9b)) || (iVar3 == 0x9a)) {
        iVar3 = 2;
        iVar22 = 1;
        piVar8 = piVar9;
        goto LAB_00155dd0;
      }
      iVar3 = FUN_001054ec(param_1,0);
      iVar3 = FUN_000f5c0c(param_1,2,*(undefined4 *)(iVar3 + 0x10),&local_d0);
      if (iVar3 == 0) {
        return 0;
      }
      if (*(int *)((int)param_1 + 0x124) == 1) {
        iVar3 = FUN_001054ec(param_1,0);
        iVar3 = FUN_000f5c0c(param_1,3,*(undefined4 *)(iVar3 + 0x10),&local_c0);
        if (iVar3 != 0) {
          return 0;
        }
      }
      iVar22 = 0;
      *(int *)(param_2 + 0x1b0) = *(int *)(param_2 + 0x1b0) + 1;
      uVar10 = FUN_00105594(param_1,1);
      uVar4 = *(uint *)((int)param_1 + 0xb8);
      iVar3 = FUN_001054ec(param_1,1);
      uVar19 = *(undefined4 *)(iVar3 + 0x10);
      uVar11 = FUN_00105594(param_1,3);
      uVar5 = *(uint *)((int)param_1 + 0xe8);
      iVar3 = FUN_001054ec(param_1,3);
      local_58 = *(uint *)((int)param_1 + 0xd0) & 1;
      uVar20 = *(undefined4 *)(iVar3 + 0x10);
      if ((*(uint *)((int)param_1 + 0x14) & 0x200) != 0) {
        iVar22 = FUN_00105594(param_1,*(undefined4 *)((int)param_1 + 0x84));
      }
      local_5c = FUN_00104054(param_1,param_2);
      uVar17 = *(undefined4 *)((int)param_1 + 0x120);
      uVar18 = *(undefined4 *)((int)param_1 + 0x124);
      iVar21 = *(int *)((int)param_1 + 4);
      iVar3 = FUN_001054ec(param_1,0);
      uVar6 = *(uint *)((int)param_1 + 0x14);
      uVar23 = *(undefined4 *)(iVar3 + 0x10);
      uVar25 = *(undefined4 *)((int)param_1 + 0x98);
      uVar28 = *(undefined4 *)((int)param_1 + 0x94);
      FUN_0019401c(param_1);
      FUN_00108174(param_1,0x12,*(undefined4 *)(param_2 + 8));
      *(undefined4 *)((int)param_1 + 0x94) = uVar28;
      *(undefined4 *)((int)param_1 + 0x98) = uVar25;
      if ((uVar6 & 2) != 0) {
        *(uint *)((int)param_1 + 0x14) = *(uint *)((int)param_1 + 0x14) | 2;
      }
      *(undefined4 *)((int)param_1 + 0x9c) = uVar23;
      if (iVar22 != 0) {
        FUN_00106804(param_1,iVar22,0,*(undefined4 *)(param_2 + 8));
      }
      iVar26 = (int)param_1 + 0xa4;
      FUN_00106004(param_1,1,uVar10,0,*(undefined4 *)(param_2 + 8));
      FUN_00103d50(iVar26,1,uVar4 & 1);
      FUN_00103d50(iVar26,2,uVar4 >> 1 & 1);
      iVar3 = FUN_001054ec(param_1,1);
      *(undefined4 *)(iVar3 + 0x10) = uVar19;
      FUN_00106004(param_1,2,uVar11,0,*(undefined4 *)(param_2 + 8));
      FUN_00103d50((int)param_1 + 0xbc,1,uVar5 & 1);
      FUN_00103d50((int)param_1 + 0xbc,2,uVar5 >> 1 & 1);
      iVar3 = FUN_001054ec(param_1,2);
      uVar4 = *(uint *)((int)param_1 + 0xb8);
      *(undefined4 *)(iVar3 + 0x10) = uVar20;
      FUN_00103d50(iVar26,1,local_58 ^ uVar4 & 1);
      *(undefined4 *)((int)param_1 + 0x120) = uVar17;
      *(undefined4 *)((int)param_1 + 0x124) = uVar18;
      if (iVar22 != 0) {
        FUN_00106804(param_1,iVar22,0,*(undefined4 *)(param_2 + 8));
      }
      uVar11 = *(undefined4 *)(iVar21 + 0x158);
      uVar10 = 1;
      *(int *)((int)param_1 + 0x160) = local_5c + *(int *)(param_2 + 0x478);
      FUN_000e7738(uVar11,iVar21,param_1);
    }
  }
  iVar3 = FUN_00105594(param_1,1);
  if (*(int *)(*(int *)(iVar3 + 0x88) + 8) == 0x13) {
    iVar3 = 1;
    iVar22 = 2;
  }
  else {
    iVar3 = FUN_00105594(param_1,2);
    if (*(int *)(*(int *)(iVar3 + 0x88) + 8) != 0x13) {
      return uVar10;
    }
    iVar3 = 2;
    iVar22 = 1;
  }
  piVar8 = (int *)FUN_00105594(param_1,iVar3);
  piVar9 = (int *)FUN_00105594(param_1,iVar22);
  if ((iVar3 != 1) || (piVar27 = piVar9, *(int *)(piVar9[0x22] + 8) != 0x13)) {
    piVar27 = (int *)0x0;
  }
  iVar21 = piVar8[0x58] - *(int *)(param_2 + 0x478);
  if (iVar21 < 0) {
    bVar2 = false;
    bVar1 = false;
LAB_00156484:
    iVar21 = 0;
    piVar24 = piVar8;
LAB_001564cc:
    piVar8 = piVar24;
    iVar26 = iVar21;
    if (!bVar2) goto LAB_001564d0;
  }
  else {
    bVar1 = 1 < iVar21;
    bVar2 = iVar21 == 1;
    if (!bVar1) goto LAB_00156484;
    if (piVar27 == (int *)0x0) {
      return uVar10;
    }
    iVar26 = piVar27[0x58] - *(int *)(param_2 + 0x478);
    if (iVar26 < 0) {
      iVar26 = 0;
    }
    if (iVar26 < iVar21) {
      bVar1 = 1 < iVar26;
      bVar2 = iVar26 == 1;
      iVar3 = 2;
      iVar22 = 1;
      piVar24 = piVar27;
      piVar27 = piVar8;
      piVar9 = piVar8;
      goto LAB_001564cc;
    }
LAB_001564d0:
    iVar21 = 1;
    if (iVar26 != 1) {
      return uVar10;
    }
  }
  iVar26 = FUN_001054ec(param_1,iVar3);
  FUN_000f3398(&local_88,*(undefined4 *)(iVar26 + 0x10));
  iVar26 = FUN_001054ec(piVar8,0);
  FUN_000f3908(&local_84,*(undefined4 *)(iVar26 + 0x10));
  if ((((((local_88 << 0x18 | (local_88 >> 8 & 0xff) << 0x10 | (local_88 >> 0x10 & 0xff) << 8 |
          local_88 >> 0x18) <=
          (local_84 << 0x18 | (local_84 >> 8 & 0xff) << 0x10 | (local_84 >> 0x10 & 0xff) << 8 |
          local_84 >> 0x18)) && (local_84 == (local_84 & local_88))) && (piVar8[0x48] == 0)) &&
      (piVar8[0x49] == 0)) &&
     ((!bVar1 ||
      (((piVar8[5] & 0x20000U) == 0 &&
       (((iVar26 = FUN_0010497c(param_1,param_2), iVar26 == 0 || (piVar9[0x20] == 0)) ||
        ((iVar26 = FUN_00126760(piVar9[0x26]), iVar26 == 0 ||
         (((piVar9[5] & 2U) != 0 || (iVar26 = (**(code **)(*piVar9 + 0x50))(piVar9), iVar26 != 0))))
        )))))))) {
    iVar14 = (**(code **)(*piVar9 + 0x5c))(piVar9);
    iVar26 = iVar22;
    if (iVar14 == 0) goto LAB_00156744;
    piVar9 = (int *)FUN_00105594(piVar8,1);
    iVar14 = (**(code **)(*piVar9 + 0x5c))();
    if (iVar14 == 0) {
      piVar9 = (int *)FUN_00105594(piVar8,2);
      iVar14 = (**(code **)(*piVar9 + 0x5c))();
      if (iVar14 == 0) goto LAB_00156744;
    }
  }
  if (piVar27 == (int *)0x0) {
    return uVar10;
  }
  if (iVar21 != 1) {
    return uVar10;
  }
  iVar21 = FUN_001054ec(param_1,iVar22);
  FUN_000f3398(&local_80,*(undefined4 *)(iVar21 + 0x10));
  iVar21 = FUN_001054ec(piVar27,0);
  FUN_000f3908(&local_7c,*(undefined4 *)(iVar21 + 0x10));
  if ((local_7c << 0x18 | (local_7c >> 8 & 0xff) << 0x10 | (local_7c >> 0x10 & 0xff) << 8 |
      local_7c >> 0x18) <
      (local_80 << 0x18 | (local_80 >> 8 & 0xff) << 0x10 | (local_80 >> 0x10 & 0xff) << 8 |
      local_80 >> 0x18)) {
    return uVar10;
  }
  if (local_7c != (local_7c & local_80)) {
    return uVar10;
  }
  if (piVar27[0x48] != 0) {
    return uVar10;
  }
  if (piVar27[0x49] != 0) {
    return uVar10;
  }
  piVar8 = (int *)FUN_00105594(param_1,iVar22);
  iVar21 = (**(code **)(*piVar8 + 0x5c))();
  iVar26 = iVar3;
  iVar3 = iVar22;
  piVar8 = piVar27;
  if (iVar21 != 0) {
    piVar9 = (int *)FUN_00105594(piVar27,1);
    iVar22 = (**(code **)(*piVar9 + 0x5c))();
    if (iVar22 != 0) {
      return uVar10;
    }
    piVar9 = (int *)FUN_00105594(piVar27,2);
    iVar22 = (**(code **)(*piVar9 + 0x5c))();
    if (iVar22 != 0) {
      return uVar10;
    }
  }
LAB_00156744:
  local_60 = FUN_00105594(param_1,iVar26);
  iVar22 = FUN_001054ec(param_1,iVar26);
  uVar20 = *(undefined4 *)(iVar22 + 0x10);
  iVar22 = FUN_001054ec(param_1,iVar3);
  bVar1 = (*(uint *)((int)param_1 + 0x14) & 0x200) != 0;
  uVar4 = *(uint *)((int)param_1 + iVar26 * 0x18 + 0xa0);
  local_68 = uVar4 & 1;
  local_64 = uVar4 >> 1 & 1;
  local_8c = 0;
  local_a0 = 0;
  local_9c = 0;
  uVar17 = *(undefined4 *)(iVar22 + 0x10);
  uVar11 = *(undefined4 *)((int)param_1 + 0x120);
  uVar19 = *(undefined4 *)((int)param_1 + 0x124);
  if (bVar1) {
    FUN_00104d3c(param_1,&local_a0);
  }
  iVar22 = FUN_00104054(param_1,param_2);
  iVar26 = *(int *)((int)param_1 + 4);
  iVar21 = FUN_001054ec(param_1,0);
  uVar18 = *(undefined4 *)(iVar21 + 0x10);
  iVar21 = FUN_001054ec(piVar8,2);
  uVar23 = *(undefined4 *)(iVar21 + 0x10);
  iVar21 = FUN_001054ec(piVar8,1);
  uVar5 = *(uint *)((int)param_1 + iVar3 * 0x18 + 0xa0);
  uVar4 = uVar5 & 1;
  FUN_000f2bdc(&local_78,*(undefined4 *)(iVar21 + 0x10),uVar17);
  FUN_000f2bdc(&local_74,uVar23,uVar17);
  uVar6 = *(uint *)((int)param_1 + 0x14);
  uVar17 = *(undefined4 *)((int)param_1 + 0x98);
  pvVar15 = (void *)FUN_001043f0(0x14,*(undefined4 *)(param_2 + 8));
  if ((uVar6 & 2) != 0) {
    *(uint *)((int)pvVar15 + 0x14) = *(uint *)((int)pvVar15 + 0x14) | 2;
  }
  *(undefined4 *)((int)pvVar15 + 0xc) = *(undefined4 *)((int)param_1 + 0xc);
  *(undefined4 *)((int)pvVar15 + 0x94) = *(undefined4 *)((int)pvVar15 + 0x14c);
  *(undefined4 *)((int)pvVar15 + 0x98) = uVar17;
  *(undefined4 *)((int)pvVar15 + 0x9c) = uVar18;
  *(undefined4 *)((int)pvVar15 + 0x120) = uVar11;
  *(undefined4 *)((int)pvVar15 + 0x124) = uVar19;
  uVar11 = FUN_00105594(piVar8,1);
  iVar3 = FUN_00106230(pvVar15,1,uVar11,1,uVar4,*(undefined4 *)(param_2 + 8));
  uVar11 = FUN_00105594(piVar8,2);
  iVar21 = FUN_00106230(pvVar15,2,uVar11,1,0,*(undefined4 *)(param_2 + 8));
  iVar14 = FUN_00106230(pvVar15,3,local_60,local_64,local_68,*(undefined4 *)(param_2 + 8));
  iVar16 = FUN_001054ec(pvVar15,1);
  *(undefined4 *)(iVar16 + 0x10) = local_78;
  iVar16 = FUN_001054ec(pvVar15,2);
  *(undefined4 *)(iVar16 + 0x10) = local_74;
  iVar16 = FUN_001054ec(pvVar15,3);
  *(undefined4 *)(iVar16 + 0x10) = uVar20;
  if ((uVar5 & 2) == 0) {
    if (uVar4 == 0) {
      FUN_00103d50((int)pvVar15 + 0xa4,2,(uint)piVar8[0x2e] >> 1 & 1);
      uVar4 = piVar8[0x2e] & 1;
    }
    else {
      FUN_00103d50((int)pvVar15 + 0xa4,2,(uint)piVar8[0x2e] >> 1 & 1);
      uVar4 = piVar8[0x2e] & 1U ^ 1;
    }
    FUN_00103d50((int)pvVar15 + 0xa4,1,uVar4);
    FUN_00103d50((int)pvVar15 + 0xbc,2,(uint)piVar8[0x34] >> 1 & 1);
    FUN_00103d50((int)pvVar15 + 0xbc,1,piVar8[0x34] & 1);
  }
  else {
    FUN_00103d50((int)pvVar15 + 0xa4,2,1);
    FUN_00103d50((int)pvVar15 + 0xa4,1,uVar4);
    FUN_00103d50((int)pvVar15 + 0xbc,2,1);
    FUN_00103d50((int)pvVar15 + 0xbc,1,0);
  }
  FUN_00103d50((int)pvVar15 + 0xd4,2,local_64);
  FUN_00103d50((int)pvVar15 + 0xd4,1,local_68);
  if (bVar1) {
    FUN_00106b48(pvVar15,&local_a0,0,*(undefined4 *)(param_2 + 8));
  }
  *(int *)((int)pvVar15 + 0x160) = iVar22 + *(int *)(param_2 + 0x478);
  if (iVar14 != 0 && (iVar21 != 0 && iVar3 != 0)) {
    *(int *)(param_2 + 0x1b0) = *(int *)(param_2 + 0x1b0) + 1;
    iVar3 = FUN_00105594(piVar8,1);
    if (*(int *)(param_2 + 0x478) < *(int *)(iVar3 + 0x160)) {
      *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + 1;
    }
    else {
      *(int *)(iVar3 + 0x160) = *(int *)(param_2 + 0x478) + 1;
    }
    iVar3 = FUN_00105594(piVar8,2);
    if (*(int *)(param_2 + 0x478) < *(int *)(iVar3 + 0x160)) {
      *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + 1;
    }
    else {
      *(int *)(iVar3 + 0x160) = *(int *)(param_2 + 0x478) + 1;
    }
    FUN_0019401c(param_1);
    _memcpy(param_1,pvVar15,0x164);
    FUN_000e7738(*(undefined4 *)(iVar26 + 0x158),iVar26,param_1);
    iVar3 = FUN_00105894(piVar8,*(undefined4 *)(param_2 + 8));
    if (iVar3 == 0) {
      iVar3 = 1;
      do {
        piVar9 = (int *)FUN_00105594(piVar8,iVar3);
        iVar22 = (**(code **)(*piVar9 + 0x5c))();
        if (iVar22 == 0) {
          if (*(int *)(param_2 + 0x478) < piVar9[0x58]) {
            piVar9[0x58] = piVar9[0x58] + 1;
          }
          else {
            piVar9[0x58] = *(int *)(param_2 + 0x478) + 1;
          }
        }
        else {
          iVar22 = FUN_0010445c(piVar9,*(undefined4 *)(param_2 + 8),0);
          *(undefined4 *)(iVar22 + 0x98) = 0x31;
          *(undefined4 *)(iVar22 + 0x94) = *(undefined4 *)(iVar22 + 0x14c);
          FUN_00106004(pvVar15,1,iVar22,0,*(undefined4 *)(param_2 + 8));
          FUN_000e7738(*(undefined4 *)(iVar26 + 0x158),iVar26,iVar22);
          *(int *)(iVar22 + 0x160) = *(int *)(param_2 + 0x478) + 1;
          iVar21 = FUN_00105594(iVar22,1);
          if (*(int *)(param_2 + 0x478) < *(int *)(iVar21 + 0x160)) {
            *(int *)(iVar21 + 0x160) = *(int *)(iVar21 + 0x160) + 1;
          }
          else {
            *(int *)(iVar21 + 0x160) = *(int *)(param_2 + 0x478) + 1;
          }
          if (1 < *(int *)(iVar22 + 0x84)) {
            iVar22 = FUN_00105594(iVar22,2);
            if (*(int *)(param_2 + 0x478) < *(int *)(iVar22 + 0x160)) {
              *(int *)(iVar22 + 0x160) = *(int *)(iVar22 + 0x160) + 1;
            }
            else {
              *(int *)(iVar22 + 0x160) = *(int *)(param_2 + 0x478) + 1;
            }
          }
        }
        bVar1 = iVar3 != 2;
        iVar3 = iVar3 + 1;
      } while (bVar1);
    }
  }
  return uVar10;
}

/* FUN_00156cb8 @ 0x156cb8 (144 bytes) */
int FUN_00156cb8(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_001054ec(param_1,0);
  iVar4 = *(int *)(iVar1 + 0x10);
  iVar1 = FUN_001054ec(param_2,0);
  iVar3 = *(int *)(iVar1 + 0x10);
  iVar1 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x30);
  if (iVar1 == 0) {
LAB_00156d30:
    uVar2 = 1;
  }
  else {
    if (iVar4 == DAT_001b0054) {
      if (iVar4 == iVar3) goto LAB_00156d30;
    }
    else if (DAT_001b0054 != iVar3) goto LAB_00156d30;
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_00156d48 @ 0x156d48 (3600 bytes) */
int FUN_00156d48(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  undefined1 uVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  int iVar20;
  int iVar21;
  int *piVar22;
  int iVar23;
  int local_c8;
  int local_c4;
  int *local_c0;
  int local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  uint local_b0;
  uint local_ac;
  int local_a8;
  undefined4 local_a4;
  int local_98;
  int local_94;
  undefined4 local_90;
  int local_8c;
  undefined4 local_88;
  uint local_84;
  uint local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int *local_60;
  
  local_c4 = 0;
  iVar15 = *(int *)(param_2 + 8);
  local_c4 = FUN_00146b0c(param_1,0,param_3,param_2,&local_c0,&local_c4);
  if (*(int *)(iVar15 + 0x6ac) <= local_c4) {
    local_88 = FUN_00105594(param_1,3);
    local_84 = param_1[0x3a] & 1;
    local_80 = (uint)param_1[0x3a] >> 1 & 1;
    iVar8 = FUN_001054ec(param_1,3);
    uVar14 = *(undefined4 *)(iVar8 + 0x10);
    if (param_3 == 0x14) {
      local_78 = param_1[0x48];
      local_7c = 0;
      if ((param_1[5] & 0x200U) != 0) {
        local_7c = FUN_00105594(param_1,param_1[0x21]);
      }
      local_74 = param_1[0x49];
      uVar16 = FUN_00105594(param_1,1);
      uVar2 = param_1[0x2e];
      iVar8 = FUN_001054ec(param_1,1);
      uVar19 = *(undefined4 *)(iVar8 + 0x10);
      uVar17 = FUN_00105594(param_1,2);
      uVar3 = param_1[0x34];
      iVar8 = FUN_001054ec(param_1,2);
      uVar18 = *(undefined4 *)(iVar8 + 0x10);
      local_88 = FUN_00105594(param_1,3);
      local_84 = param_1[0x3a] & 1;
      local_80 = (uint)param_1[0x3a] >> 1 & 1;
      iVar8 = FUN_001054ec(param_1,3);
      iVar20 = param_1[1];
      uVar14 = *(undefined4 *)(iVar8 + 0x10);
      iVar8 = FUN_001054ec(param_1,0);
      local_60 = &local_bc;
      uVar5 = param_1[5];
      iVar7 = *(int *)(iVar8 + 0x10);
      local_b4 = 0;
      local_bc = 0;
      local_b8 = 0;
      local_70 = param_1[0x54];
      iVar8 = param_1[0x26];
      FUN_00103f18(param_1,local_60,0xffffffff);
      uVar4 = param_1[5];
      iVar23 = param_1[0x25];
      FUN_0019401c(param_1);
      FUN_00108174(param_1,0x13,*(undefined4 *)(param_2 + 8));
      if ((uVar5 & 0x4000) == 0) {
        uVar5 = param_1[5] & 0xffffbfff;
        param_1[5] = uVar5;
      }
      else {
        uVar5 = param_1[5] | 0x4000;
        param_1[5] = uVar5;
      }
      param_1[0x25] = iVar23;
      param_1[0x26] = iVar8;
      if ((uVar4 & 2) != 0) {
        param_1[5] = uVar5 | 2;
      }
      param_1[0x27] = iVar7;
      param_3 = 0x13;
      FUN_00106004(param_1,1,uVar16,0,*(undefined4 *)(param_2 + 8));
      FUN_00103d50(param_1 + 0x29,1,uVar2 & 1);
      FUN_00103d50(param_1 + 0x29,2,uVar2 >> 1 & 1);
      iVar8 = FUN_001054ec(param_1,1);
      *(undefined4 *)(iVar8 + 0x10) = uVar19;
      FUN_00106004(param_1,2,uVar17,0,*(undefined4 *)(param_2 + 8));
      FUN_00103d50(param_1 + 0x2f,1,uVar3 & 1);
      FUN_00103d50(param_1 + 0x2f,2,uVar3 >> 1 & 1);
      iVar8 = FUN_001054ec(param_1,2);
      *(undefined4 *)(iVar8 + 0x10) = uVar18;
      FUN_00103f44(param_1,local_60);
      FUN_000e7738(*(undefined4 *)(iVar20 + 0x158),iVar20,param_1);
      local_6c = 1;
    }
    else {
      local_6c = 0;
      local_70 = 0;
      local_74 = 0;
      local_78 = 0;
      local_7c = 0;
    }
    iVar8 = FUN_001054ec(param_1,0);
    iVar7 = 0;
    iVar8 = *(int *)(iVar8 + 0x10);
    local_c8 = iVar8;
    iVar23 = 4;
    do {
      piVar11 = param_1;
      if (*(char *)((int)&local_c8 + iVar7) == '\0') {
        local_64 = *(int *)(PTR_DAT_001e8b8c + iVar7 * 4);
        local_68 = *(int *)(PTR_DAT_001e8b64 + iVar7 * 4);
        break;
      }
      iVar7 = iVar7 + 1;
      iVar23 = iVar23 + -1;
    } while (iVar23 != 0);
    do {
      uVar2 = piVar11[5];
      piVar11[5] = uVar2 | 0x100000;
      iVar7 = ((uVar2 & 0x4000) >> 0xe) + 1;
      piVar9 = (int *)FUN_00105594(piVar11,iVar7);
      if (param_3 != *(int *)(piVar9[0x22] + 8)) break;
      iVar23 = FUN_001054ec(piVar11,iVar7);
      iVar20 = *(int *)(iVar23 + 0x10);
      iVar23 = FUN_001054ec(piVar9,1);
      iVar21 = *(int *)(iVar23 + 0x10);
      FUN_000f2bdc(&local_98,iVar21,iVar20);
      iVar23 = local_98;
      if (iVar21 != local_98) {
        iVar21 = FUN_001054ec(piVar9,1);
        *(int *)(iVar21 + 0x10) = iVar23;
      }
      iVar23 = FUN_001054ec(piVar9,2);
      iVar21 = *(int *)(iVar23 + 0x10);
      FUN_000f2bdc(&local_94,iVar21,iVar20);
      iVar23 = local_94;
      if (iVar21 != local_94) {
        iVar21 = FUN_001054ec(piVar9,2);
        *(int *)(iVar21 + 0x10) = iVar23;
      }
      iVar23 = FUN_001054ec(piVar9,0);
      if (*(int *)(iVar23 + 0x10) != iVar8) {
        piVar9[0x27] = local_c8;
      }
      iVar23 = DAT_001b004c;
      FUN_000f3908(&local_90,local_c8);
      FUN_000f3340(&local_8c,iVar23,local_90);
      iVar23 = local_8c;
      if (iVar20 != local_8c) {
        if (iVar7 == 0) {
          piVar11[0x27] = local_8c;
        }
        else {
          iVar7 = FUN_001054ec(piVar11,iVar7);
          *(int *)(iVar7 + 0x10) = iVar23;
        }
      }
      piVar11 = piVar9;
    } while (piVar9 != local_c0);
    piVar22 = local_c0;
    piVar11[5] = piVar11[5] | 0x100000;
    local_a4 = *(undefined4 *)(*(int *)(param_2 + 8) + 0x374);
    local_b0 = 2;
    local_ac = 0;
    local_a8 = FUN_00193e18(local_a4,8);
    *(int *)(param_2 + 0x1c8) = *(int *)(param_2 + 0x1c8) + 1;
    piVar11 = param_1;
    piVar9 = param_1;
    if (param_1 != piVar22) {
      iVar8 = 0;
      do {
        iVar7 = piVar22[0x53];
        if (local_ac < local_b0) {
          iVar23 = local_ac * 4;
          local_ac = local_ac + 1;
          *(undefined4 *)(iVar23 + local_a8) = 0;
          piVar10 = (int *)(iVar23 + local_a8);
        }
        else {
          piVar10 = (int *)FUN_0019423c(&local_b0);
        }
        *piVar10 = iVar7;
        piVar22[0x53] = iVar8;
        iVar8 = iVar8 + 1;
        piVar22 = (int *)piVar22[2];
      } while (param_1 != piVar22);
    }
    for (; piVar22 = local_c0, 2 < local_c4; local_c4 = local_c4 + -2) {
      piVar22 = (int *)FUN_00105594(piVar9,((uint)piVar9[5] >> 0xe & 1) + 1);
      uVar2 = piVar9[5];
      iVar8 = 0xb0;
      if ((uVar2 & 0x4000) == 0) {
        iVar8 = 0x98;
      }
      uVar3 = *(uint *)((int)piVar9 + iVar8 + 0x20);
      iVar8 = 0xb0;
      if ((uVar2 & 0x4000) == 0) {
        iVar8 = 0x98;
      }
      uVar4 = *(uint *)((int)piVar9 + iVar8 + 0x20);
      iVar8 = FUN_001054ec(piVar9,(uVar2 >> 0xe & 1) + 1);
      uVar16 = *(undefined4 *)(iVar8 + 0x10);
      piVar10 = (int *)FUN_00105594(piVar22,((uint)piVar22[5] >> 0xe & 1) + 1);
      uVar2 = piVar22[5];
      iVar8 = 0xb0;
      if ((uVar2 & 0x4000) == 0) {
        iVar8 = 0x98;
      }
      uVar5 = *(uint *)((int)piVar22 + iVar8 + 0x20);
      iVar8 = 0xb0;
      if ((uVar2 & 0x4000) == 0) {
        iVar8 = 0x98;
      }
      uVar6 = *(uint *)((int)piVar22 + iVar8 + 0x20);
      iVar8 = FUN_001054ec(piVar22,(uVar2 >> 0xe & 1) + 1);
      uVar19 = *(undefined4 *)(iVar8 + 0x10);
      iVar7 = FUN_00105594(piVar11,((uint)piVar11[5] >> 0xe & 1 ^ 1) + 1);
      uVar13 = (uint)piVar11[5] >> 0xe & 1 ^ 1;
      uVar2 = piVar11[uVar13 * 6 + 0x2e];
      iVar8 = FUN_001054ec(piVar11,uVar13 + 1);
      uVar17 = *(undefined4 *)(iVar8 + 0x10);
      FUN_00106004(piVar9,((uint)piVar9[5] >> 0xe & 1) + 1,piVar10,0,iVar15);
      iVar8 = 0xb0;
      if ((piVar9[5] & 0x4000U) == 0) {
        iVar8 = 0x98;
      }
      FUN_00103d50((int)piVar9 + iVar8 + 0xc,1,uVar5 & 1);
      iVar8 = 0xb0;
      if ((piVar9[5] & 0x4000U) == 0) {
        iVar8 = 0x98;
      }
      FUN_00103d50((int)piVar9 + iVar8 + 0xc,2,uVar6 >> 1 & 1);
      iVar8 = FUN_001054ec(piVar9,((uint)piVar9[5] >> 0xe & 1) + 1);
      *(undefined4 *)(iVar8 + 0x10) = uVar19;
      FUN_00106004(piVar11,((uint)piVar11[5] >> 0xe & 1 ^ 1) + 1,piVar22,0,iVar15);
      FUN_00103d50(piVar11 + ((uint)piVar11[5] >> 0xe & 1 ^ 1) * 6 + 0x29,1,uVar3 & 1);
      FUN_00103d50(piVar11 + ((uint)piVar11[5] >> 0xe & 1 ^ 1) * 6 + 0x29,2,uVar4 >> 1 & 1);
      iVar8 = FUN_001054ec(piVar11,((uint)piVar11[5] >> 0xe & 1 ^ 1) + 1);
      *(undefined4 *)(iVar8 + 0x10) = uVar16;
      FUN_00106004(piVar22,((uint)piVar22[5] >> 0xe & 1) + 1,iVar7,0,iVar15);
      iVar8 = 0xb0;
      if ((piVar22[5] & 0x4000U) == 0) {
        iVar8 = 0x98;
      }
      FUN_00103d50((int)piVar22 + iVar8 + 0xc,1,uVar2 & 1);
      iVar8 = 0xb0;
      if ((piVar22[5] & 0x4000U) == 0) {
        iVar8 = 0x98;
      }
      FUN_00103d50((int)piVar22 + iVar8 + 0xc,2,uVar2 >> 1 & 1);
      iVar8 = FUN_001054ec(piVar22,((uint)piVar22[5] >> 0xe & 1) + 1);
      *(undefined4 *)(iVar8 + 0x10) = uVar17;
      if (piVar22[0x53] < *(int *)(iVar7 + 0x14c)) {
        FUN_0019401c(piVar22);
        FUN_000e7700(piVar11[0x56],piVar11,piVar22);
      }
      piVar11 = piVar22;
      piVar9 = piVar10;
    }
    for (; param_1 != piVar22; piVar22 = (int *)piVar22[2]) {
      uVar2 = piVar22[0x53];
      if (uVar2 < local_b0) {
        if (local_ac <= uVar2) {
          _memset((void *)(local_ac * 4 + local_a8),0,(uVar2 - local_ac) * 4 + 4);
          local_ac = uVar2 + 1;
        }
        piVar11 = (int *)(uVar2 * 4 + local_a8);
      }
      else {
        piVar11 = (int *)FUN_0019423c(&local_b0,uVar2);
      }
      piVar22[0x53] = *piVar11;
      if ((piVar22[5] & 0x100000U) != 0) {
        iVar8 = FUN_001054ec(piVar22,1);
        iVar8 = FUN_000f2c5c(*(undefined4 *)(iVar8 + 0x10));
        if (iVar8 == 0) {
          iVar8 = FUN_00105594(piVar22,1);
          if ((*(uint *)(iVar8 + 0x14) & 0x100000) != 0) {
            uVar16 = FUN_00105594(piVar22,1);
            iVar8 = FUN_001054ec(uVar16,0);
            iVar8 = FUN_000f3824(*(undefined4 *)(iVar8 + 0x10));
            if (iVar8 != 0) goto LAB_00157678;
          }
        }
        else {
LAB_00157678:
          iVar8 = FUN_001054ec(piVar22,2);
          iVar8 = FUN_000f2c5c(*(undefined4 *)(iVar8 + 0x10));
          if (iVar8 == 0) {
            iVar8 = FUN_00105594(piVar22,2);
            if ((*(uint *)(iVar8 + 0x14) & 0x100000) != 0) {
              uVar16 = FUN_00105594(piVar22,2);
              iVar8 = FUN_001054ec(uVar16,0);
              iVar8 = FUN_000f3824(*(undefined4 *)(iVar8 + 0x10));
              if (iVar8 != 0) goto LAB_001576d0;
            }
          }
          else {
LAB_001576d0:
            iVar7 = ((uint)piVar22[5] >> 0xe & 1) + 1;
            piVar22[0x27] = local_68;
            iVar8 = FUN_001054ec(piVar22,iVar7);
            if (*(int *)(iVar8 + 0x10) == DAT_001b004c) {
              if (iVar7 == 0) {
                piVar22[0x27] = local_64;
              }
              else {
                iVar8 = FUN_001054ec(piVar22,iVar7);
                *(int *)(iVar8 + 0x10) = local_64;
              }
            }
          }
        }
        for (iVar8 = 1; iVar7 = (**(code **)(*piVar22 + 0x14))(piVar22), iVar8 <= iVar7;
            iVar8 = iVar8 + 1) {
          iVar7 = FUN_00105594(piVar22,iVar8);
          if ((*(uint *)(iVar7 + 0x14) & 0x100000) != 0) {
            iVar7 = FUN_001054ec(iVar7,0);
            uVar16 = *(undefined4 *)(iVar7 + 0x10);
            iVar7 = FUN_000f3824(uVar16);
            if (iVar7 != 0) {
              uVar12 = FUN_000f37b8(uVar16);
              iVar7 = 0;
              local_bc = DAT_001b0050;
              do {
                iVar23 = FUN_001054ec(piVar22,0);
                if (*(char *)(iVar7 + iVar23 + 0x10) != '\x01') {
                  *(undefined1 *)((int)&local_bc + iVar7) = uVar12;
                }
                iVar23 = local_bc;
                bVar1 = iVar7 != 3;
                iVar7 = iVar7 + 1;
              } while (bVar1);
              if (iVar8 == 0) {
                piVar22[0x27] = local_bc;
              }
              else {
                iVar7 = FUN_001054ec(piVar22,iVar8);
                *(int *)(iVar7 + 0x10) = iVar23;
              }
            }
          }
        }
      }
    }
    for (iVar8 = 1; iVar7 = (**(code **)(*param_1 + 0x14))(param_1), iVar8 <= iVar7;
        iVar8 = iVar8 + 1) {
      iVar7 = FUN_00105594(param_1,iVar8);
      if ((*(uint *)(iVar7 + 0x14) & 0x100000) != 0) {
        iVar7 = FUN_001054ec(iVar7,0);
        uVar16 = *(undefined4 *)(iVar7 + 0x10);
        iVar7 = FUN_000f3824(uVar16);
        if (iVar7 != 0) {
          uVar12 = FUN_000f37b8(uVar16);
          iVar7 = 0;
          local_bc = DAT_001b0050;
          do {
            iVar23 = FUN_001054ec(param_1,0);
            if (*(char *)(iVar7 + iVar23 + 0x10) != '\x01') {
              *(undefined1 *)((int)&local_bc + iVar7) = uVar12;
            }
            iVar23 = local_bc;
            bVar1 = iVar7 != 3;
            iVar7 = iVar7 + 1;
          } while (bVar1);
          if (iVar8 == 0) {
            param_1[0x27] = local_bc;
          }
          else {
            iVar7 = FUN_001054ec(param_1,iVar8);
            *(int *)(iVar7 + 0x10) = iVar23;
          }
        }
      }
    }
    for (; param_1 != local_c0; local_c0 = (int *)local_c0[2]) {
      if ((local_c0[5] & 0x100000U) != 0) {
        local_c0[5] = local_c0[5] & 0xffefffff;
      }
    }
    param_1[5] = param_1[5] & 0xffefffff;
    if (local_6c != 0) {
      uVar16 = FUN_00105594(param_1,1);
      uVar2 = param_1[0x2e];
      iVar8 = FUN_001054ec(param_1,1);
      uVar19 = *(undefined4 *)(iVar8 + 0x10);
      uVar17 = FUN_00105594(param_1,2);
      uVar3 = param_1[0x34];
      iVar8 = FUN_001054ec(param_1,2);
      uVar18 = *(undefined4 *)(iVar8 + 0x10);
      iVar7 = param_1[1];
      iVar8 = FUN_001054ec(param_1,0);
      uVar4 = param_1[5];
      iVar23 = *(int *)(iVar8 + 0x10);
      local_b4 = 0;
      local_bc = 0;
      local_b8 = 0;
      iVar8 = param_1[0x26];
      iVar20 = param_1[0x25];
      FUN_00103f18(param_1,&local_bc,0xffffffff);
      FUN_0019401c(param_1);
      FUN_00108304(param_1,0x14,*(undefined4 *)(param_2 + 8));
      FUN_00103f44(param_1,&local_bc);
      param_1[0x49] = 0;
      param_1[0x25] = iVar20;
      param_1[0x26] = iVar8;
      param_1[0x48] = 0;
      if ((uVar4 & 2) != 0) {
        param_1[5] = param_1[5] | 2;
      }
      param_1[0x27] = iVar23;
      param_1[0x54] = local_70;
      FUN_00106004(param_1,1,uVar16,0,*(undefined4 *)(param_2 + 8));
      FUN_00103d50(param_1 + 0x29,1,uVar2 & 1);
      FUN_00103d50(param_1 + 0x29,2,uVar2 >> 1 & 1);
      iVar8 = FUN_001054ec(param_1,1);
      *(undefined4 *)(iVar8 + 0x10) = uVar19;
      FUN_00106004(param_1,2,uVar17,0,*(undefined4 *)(param_2 + 8));
      FUN_00103d50(param_1 + 0x2f,1,uVar3 & 1);
      FUN_00103d50(param_1 + 0x2f,2,uVar3 >> 1 & 1);
      iVar8 = FUN_001054ec(param_1,2);
      *(undefined4 *)(iVar8 + 0x10) = uVar18;
      FUN_00106004(param_1,3,local_88,0,*(undefined4 *)(param_2 + 8));
      FUN_00103d50(param_1 + 0x35,1,local_84);
      FUN_00103d50(param_1 + 0x35,2,local_80);
      iVar8 = FUN_001054ec(param_1,3);
      *(undefined4 *)(iVar8 + 0x10) = uVar14;
      param_1[0x48] = local_78;
      param_1[0x49] = local_74;
      if (local_7c != 0) {
        FUN_00106804(param_1,local_7c,0,iVar15);
      }
      FUN_000e7738(*(undefined4 *)(iVar7 + 0x158),iVar7,param_1);
    }
    FUN_00193cc0(local_a4,local_a8);
  }
  return param_1;
}

/* FUN_00157b78 @ 0x157b78 (1172 bytes) */
int FUN_00157b78(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c [5];
  
  uVar2 = ~param_2 & 3;
  iVar6 = FUN_00105594();
  piVar7 = (int *)FUN_00105594(iVar6,1);
  piVar8 = (int *)FUN_00105594(iVar6,2);
  piVar9 = (int *)FUN_00105594(param_1,uVar2);
  iVar10 = FUN_001054ec(param_1,uVar2);
  uVar17 = *(undefined4 *)(iVar10 + 0x10);
  iVar10 = FUN_001054ec(iVar6,1);
  uVar18 = *(undefined4 *)(iVar10 + 0x10);
  iVar10 = FUN_001054ec(iVar6,2);
  local_68 = *(undefined4 *)(iVar10 + 0x10);
  iVar10 = FUN_000f2c5c(uVar17);
  iVar11 = FUN_000f2c5c(uVar18);
  iVar12 = FUN_000f2c5c(local_68);
  if ((iVar11 == 0) && (iVar12 == 0)) {
    return;
  }
  if (iVar10 == 0) {
    return;
  }
  iVar10 = FUN_000f45f8(param_1,param_2,iVar6,param_3);
  if (iVar10 == 0) {
    return;
  }
  if (iVar11 == 0) {
    if (iVar12 != 0) {
LAB_00157ce4:
      uVar16 = 1;
      local_68 = uVar18;
      goto LAB_00157cf8;
    }
  }
  else if (iVar12 != 0) {
    iVar10 = (**(code **)(*piVar8 + 0x48))(piVar8);
    if ((iVar10 != 0) || (iVar10 = (**(code **)(*piVar8 + 0x4c))(piVar8), iVar10 != 0))
    goto LAB_00157ce4;
    iVar10 = (**(code **)(*piVar7 + 0x48))(piVar7);
    if ((iVar10 == 0) && (iVar10 = (**(code **)(*piVar7 + 0x4c))(piVar7), iVar10 == 0)) {
      return;
    }
  }
  uVar16 = 2;
  piVar7 = piVar8;
LAB_00157cf8:
  iVar10 = (**(code **)(*piVar9 + 0x48))(piVar9);
  if ((iVar10 != 0) || (iVar10 = (**(code **)(*piVar9 + 0x4c))(piVar9), iVar10 != 0)) {
    uVar18 = FUN_0010445c(iVar6,*(undefined4 *)(param_3 + 8),0);
    uVar13 = FUN_0010445c(param_1,*(undefined4 *)(param_3 + 8),0);
    iVar11 = param_1 + uVar2 * 0x18 + 0x80;
    uVar3 = *(uint *)(uVar16 * 0x18 + iVar6 + 0xa0) & 1;
    uVar4 = *(uint *)(iVar11 + 0x20) & 1;
    iVar10 = FUN_00106230(param_1,uVar2,piVar7,1,uVar3,*(undefined4 *)(param_3 + 8));
    iVar12 = 0;
    FUN_00103d50(iVar11 + 0xc,1,uVar3);
    iVar11 = FUN_001054ec(param_1,param_2);
    local_64 = *(undefined4 *)(iVar11 + 0x10);
    local_60 = local_68;
    do {
      iVar11 = FUN_001054ec(param_1,0);
      if (*(char *)(iVar12 + iVar11 + 0x10) != '\x01') {
        *(undefined1 *)((int)&local_68 + iVar12) =
             *(undefined1 *)((int)local_5c + (*(byte *)((int)&local_64 + iVar12) - 4));
      }
      bVar1 = iVar12 != 3;
      iVar12 = iVar12 + 1;
    } while (bVar1);
    iVar11 = 0;
    local_5c[0] = DAT_001b005c;
    do {
      iVar12 = FUN_001054ec(param_1,0);
      if (*(char *)(iVar11 + iVar12 + 0x10) == '\x01') {
        *(undefined1 *)((int)local_5c + iVar11) = 4;
        *(undefined1 *)((int)&local_68 + iVar11) = 4;
      }
      uVar19 = local_68;
      bVar1 = iVar11 != 3;
      iVar11 = iVar11 + 1;
    } while (bVar1);
    iVar11 = FUN_001054ec(param_1,uVar2);
    uVar5 = local_5c[0];
    *(undefined4 *)(iVar11 + 0x10) = uVar19;
    iVar11 = FUN_001054ec(param_1,param_2);
    uVar19 = DAT_001b0058;
    *(undefined4 *)(iVar11 + 0x10) = uVar5;
    *(undefined4 *)(iVar6 + 0x9c) = uVar19;
    iVar11 = FUN_00106230(iVar6,uVar16,piVar9,1,uVar4,*(undefined4 *)(param_3 + 8));
    FUN_00103d50(uVar16 * 0x18 + iVar6 + 0x8c,1,uVar4);
    iVar12 = FUN_001054ec(iVar6,~uVar16 & 3);
    uVar19 = *(undefined4 *)(iVar12 + 0x10);
    iVar12 = FUN_000f2cac(uVar17);
    iVar14 = FUN_000f2cac(uVar19);
    uVar2 = DAT_001b0050 & 0xffffff;
    uVar3 = DAT_001b0050 & 0xffffff;
    iVar15 = FUN_001054ec(iVar6,uVar16);
    *(uint *)(iVar15 + 0x10) = iVar12 << 0x18 | uVar2;
    iVar12 = FUN_001054ec(iVar6,~uVar16 & 3);
    *(uint *)(iVar12 + 0x10) = iVar14 << 0x18 | uVar3;
    if (iVar11 == 0 || iVar10 == 0) {
      iVar10 = *(int *)(iVar6 + 4);
      FUN_0019401c(iVar6);
      FUN_00103f84(iVar6,uVar18);
      FUN_000e7738(*(undefined4 *)(iVar10 + 0x158),iVar10,iVar6);
      iVar6 = *(int *)(param_1 + 4);
      FUN_0019401c(param_1);
      FUN_00103f84(param_1,uVar13);
      FUN_000e7738(*(undefined4 *)(iVar6 + 0x158),iVar6,param_1);
      return;
    }
    FUN_0019401c(iVar6);
    FUN_000e7700(*(undefined4 *)(param_1 + 0x158),param_1,iVar6);
    *(int *)(param_3 + 0x1c0) = *(int *)(param_3 + 0x1c0) + 1;
  }
  return;
}

/* FUN_0015800c @ 0x15800c (600 bytes) */
int FUN_0015800c(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int *param_2;
  int param_3;
  undefined4 param_4;
  uint param_5;
  int param_6;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint local_28 [4];
  
LAB_0015802c:
  do {
    iVar1 = (**(code **)(*param_2 + 100))(param_2);
    if (iVar1 != 0) {
      for (iVar1 = 1; iVar2 = (**(code **)(*param_2 + 0x14))(param_2), iVar1 <= iVar2;
          iVar1 = iVar1 + 1) {
        if ((((param_2[iVar1 * 6 + 0x28] & 1U) != 0) || ((param_2[iVar1 * 6 + 0x28] & 2U) != 0)) ||
           (iVar2 = FUN_000f31e8(param_2,iVar1), iVar2 == 0)) goto LAB_00158170;
      }
      if ((param_2[0x48] == 0) && (param_2[0x49] == 0)) {
        if (((param_2[0x20] != 0) &&
            ((iVar1 = FUN_00126760(param_2[0x26]), iVar1 != 0 && ((param_2[5] & 2U) == 0)))) &&
           (iVar1 = (**(code **)(*param_2 + 0x50))(param_2), iVar1 == 0)) {
          iVar1 = 4;
          piVar3 = param_2;
          do {
            if (*(byte *)(piVar3 + 0x27) - 2 < 2) goto LAB_00158170;
            piVar3 = (int *)((int)piVar3 + 1);
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
        FUN_001054ec(param_2,0);
        iVar1 = FUN_00105dbc(param_2,0);
        if ((((iVar1 == 0) && ((param_2[5] & 2U) == 0)) && ((param_2[5] & 0x200U) == 0)) &&
           (iVar1 = FUN_0010497c(param_2,param_6), iVar1 != 0)) {
          param_2 = (int *)FUN_00105594(param_2,1);
          goto LAB_0015802c;
        }
      }
    }
LAB_00158170:
    iVar1 = (**(code **)(*param_2 + 0x24))(param_2);
    if (((iVar1 == 0) || (iVar1 = FUN_0010497c(param_2,param_6), iVar1 == 0)) ||
       ((param_2[0x48] != 0 ||
        (piVar3 = *(int **)(*(int *)(param_6 + 8) + 0x30c),
        iVar1 = (**(code **)(*piVar3 + 0xfc))(piVar3,param_3 + param_2[0x49],param_2), iVar1 == 0)))
       ) {
      return 0;
    }
    do {
      if ((param_2[5] & 0x200U) == 0) {
        return 1;
      }
      param_2 = (int *)FUN_00105594(param_2,param_2[0x21]);
      iVar1 = FUN_001054ec(param_2,0);
      FUN_000f3908(local_28,*(undefined4 *)(iVar1 + 0x10));
    } while ((param_5 & local_28[0]) == 0);
  } while( true );
}

/* FUN_00158264 @ 0x158264 (1824 bytes) */
int FUN_00158264(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  bool bVar19;
  double dVar20;
  int local_a8;
  undefined1 auStack_a4 [4];
  float local_a0;
  int local_8c;
  int local_88;
  int local_78;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  undefined4 local_54;
  
  uVar16 = *(undefined4 *)(param_4 + 8);
  iVar18 = *(int *)(*(int *)(param_3 + 0x88) + 8);
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  }
  if (iVar18 == 0x14) {
    iVar2 = FUN_001054ec(param_3,0);
    iVar2 = FUN_000f5cf0(param_3,2,*(undefined4 *)(iVar2 + 0x10),auStack_a4);
    if (iVar2 == 0) goto LAB_00158720;
    piVar3 = (int *)FUN_00105594(param_3,1);
    iVar18 = FUN_001054ec(param_3,0);
    uVar15 = *(undefined4 *)(iVar18 + 0x10);
    iVar18 = FUN_001054ec(param_3,param_2);
    uVar4 = FUN_000f3398(&local_68,*(undefined4 *)(iVar18 + 0x10));
    dVar20 = (double)local_a0;
    bVar19 = dVar20 < (double)FLOAT_001aa0d4;
    if (bVar19) {
      dVar20 = -dVar20;
    }
    iVar18 = ((undefined4 (*)())FUN_0010ab8c)(dVar20,uVar4,&local_a8);
    if (((iVar18 != 0) && (local_a8 != 0)) &&
       (iVar18 = ((int (*)())FUN_0015800c)(param_3,piVar3,local_a8,uVar15,local_68,param_4), iVar18 != 0)) {
      iVar18 = 0x14;
      iVar2 = 0;
      do {
        piVar5 = piVar3;
        if (*(int *)(piVar3[0x22] + 8) == 0x13) {
          iVar17 = 1;
          do {
            piVar5 = (int *)FUN_00105594(piVar3,iVar17);
            iVar6 = (**(code **)(*piVar5 + 0x24))();
            if (((iVar6 != 0) && (iVar6 = FUN_0010497c(piVar5,param_4), iVar6 != 0)) &&
               ((piVar5[0x48] == 0 &&
                (((piVar5[5] & 0x200U) == 0 &&
                 (piVar7 = *(int **)(*(int *)(param_4 + 8) + 0x30c),
                 iVar6 = (**(code **)(*piVar7 + 0xfc))(piVar7,piVar5[0x49] + local_a8,param_3),
                 iVar6 != 0)))))) break;
            bVar1 = iVar17 != 2;
            iVar17 = iVar17 + 1;
            piVar5 = piVar3;
          } while (bVar1);
        }
        piVar7 = *(int **)(*(int *)(param_4 + 8) + 0x30c);
        iVar6 = piVar5[0x49] + local_a8;
        iVar17 = (**(code **)(*piVar7 + 0xfc))(piVar7,iVar6,param_3);
        if (iVar17 != 0) {
          *(int *)(param_4 + 0x1c4) = *(int *)(param_4 + 0x1c4) + 1;
          piVar5[0x49] = iVar6;
          if (iVar2 == 0) {
            local_54 = FUN_00105594(param_3,3);
            iVar18 = FUN_001054ec(param_3,1);
            uVar13 = *(undefined4 *)(iVar18 + 0x10);
            iVar18 = FUN_001054ec(param_3,3);
            uVar8 = *(uint *)(param_3 + 0xe8);
            uVar4 = *(undefined4 *)(param_3 + 0x120);
            uVar10 = *(undefined4 *)(param_3 + 0x124);
            local_60 = (uint)bVar19 ^ *(uint *)(param_3 + 0xb8) & 1;
            local_58 = *(uint *)(param_3 + 0xb8) >> 1 & 1;
            local_5c = uVar8 >> 1 & 1;
            uVar9 = *(uint *)(param_3 + 0x14);
            uVar14 = *(undefined4 *)(iVar18 + 0x10);
            local_8c = iVar2;
            local_88 = iVar2;
            local_78 = iVar2;
            if ((uVar9 & 0x200) != 0) {
              FUN_00104d3c(param_3,&local_8c);
              uVar9 = *(uint *)(param_3 + 0x14);
            }
            uVar11 = *(undefined4 *)(param_3 + 0x98);
            uVar12 = *(undefined4 *)(param_3 + 0x94);
            iVar17 = FUN_00104054(param_3,param_4);
            iVar2 = *(int *)(param_3 + 4);
            FUN_0019401c(param_3);
            if (0 < *(int *)(param_3 + 0x84)) {
              iVar18 = 1;
              do {
                iVar6 = iVar18 + 1;
                FUN_00106004(param_3,iVar18,0,0,uVar16);
                iVar18 = iVar6;
              } while (iVar6 <= *(int *)(param_3 + 0x84));
            }
            FUN_00108174(param_3,0x12,*(undefined4 *)(param_4 + 8));
            *(undefined4 *)(param_3 + 0x94) = uVar12;
            *(undefined4 *)(param_3 + 0x98) = uVar11;
            if ((uVar9 & 2) != 0) {
              *(uint *)(param_3 + 0x14) = *(uint *)(param_3 + 0x14) | 2;
            }
            *(undefined4 *)(param_3 + 0x9c) = uVar15;
            FUN_00106004(param_3,1,piVar3,0,uVar16);
            FUN_00106004(param_3,2,local_54,0,uVar16);
            iVar18 = FUN_001054ec(param_3,1);
            *(undefined4 *)(iVar18 + 0x10) = uVar13;
            iVar18 = FUN_001054ec(param_3,2);
            *(undefined4 *)(iVar18 + 0x10) = uVar14;
            FUN_00103d50(param_3 + 0xa4,2,local_58);
            FUN_00103d50(param_3 + 0xbc,2,local_5c);
            FUN_00103d50(param_3 + 0xa4,1,local_60);
            FUN_00103d50(param_3 + 0xbc,1,uVar8 & 1);
            *(undefined4 *)(param_3 + 0x120) = uVar4;
            *(undefined4 *)(param_3 + 0x124) = uVar10;
            if (local_88 != 0) {
              FUN_00106b48(param_3,&local_8c,0,uVar16);
            }
            iVar18 = 0x12;
            FUN_000e7738(*(undefined4 *)(iVar2 + 0x158),iVar2,param_3);
            iVar2 = 1;
            *(int *)(param_3 + 0x160) = iVar17 + *(int *)(param_4 + 0x478);
          }
        }
        do {
          if ((piVar3[5] & 0x200U) == 0) goto LAB_00158714;
          piVar3 = (int *)FUN_00105594(piVar3,piVar3[0x21]);
          iVar17 = FUN_001054ec(piVar3,0);
          FUN_000f3908(&local_64,*(undefined4 *)(iVar17 + 0x10));
        } while ((local_68 & local_64) == 0);
      } while( true );
    }
    iVar18 = 0x14;
    iVar2 = 0;
    bVar19 = false;
LAB_00158770:
    if (bVar19) {
      return iVar2;
    }
    if (0x14 < iVar18) {
      return iVar2;
    }
    iVar18 = FUN_00105594(param_3,1);
    if ((((*(int *)(*(int *)(iVar18 + 0x88) + 8) == 0x13) &&
         (iVar17 = FUN_0010497c(iVar18,param_4), iVar17 != 0)) && (*(int *)(iVar18 + 0x120) == 0))
       && ((*(int *)(iVar18 + 0x124) == 0 && ((*(uint *)(param_3 + 0xb8) & 2) == 0)))) {
      ((int (*)())FUN_00157b78)(param_3,1,param_4);
    }
    iVar18 = FUN_00105594(param_3,2);
    if (*(int *)(*(int *)(iVar18 + 0x88) + 8) != 0x13) {
      return iVar2;
    }
    iVar17 = FUN_0010497c(iVar18,param_4);
    if (iVar17 == 0) {
      return iVar2;
    }
    if (*(int *)(iVar18 + 0x120) != 0) {
      return iVar2;
    }
    if (*(int *)(iVar18 + 0x124) != 0) {
      return iVar2;
    }
    uVar8 = *(uint *)(param_3 + 0xd0);
  }
  else {
    if (iVar18 == 0x12) {
      if (iVar2 != 0x12) {
LAB_00158720:
        param_3 = ((int (*)())FUN_00156d48)(param_3,param_4,iVar18);
        if (((*(uint *)(param_1 + 0x14) & 0x200) == 0) || (param_2 != *(int *)(param_1 + 0x84))) {
          FUN_00106004(param_1,param_2,param_3,0,uVar16);
        }
        else {
          FUN_00106804(param_1,param_3,0,uVar16);
        }
        goto LAB_00158964;
      }
      iVar2 = 0;
    }
    else {
      if (iVar18 == 0x13) {
        if ((iVar2 == 0x14) || (iVar2 == 0x13)) {
          iVar18 = 0x13;
          iVar2 = 0;
          bVar19 = false;
          goto LAB_00158770;
        }
        goto LAB_00158720;
      }
LAB_00158964:
      iVar2 = 0;
LAB_00158714:
      bVar19 = iVar18 < 0x12;
      if (iVar18 != 0x12) goto LAB_00158770;
    }
    iVar18 = FUN_00105594(param_3,1);
    if (((((*(int *)(*(int *)(iVar18 + 0x88) + 8) == 0x12) &&
          (iVar17 = FUN_0010497c(iVar18,param_4), iVar17 != 0)) && (*(int *)(iVar18 + 0x120) == 0))
        && ((*(int *)(iVar18 + 0x124) == 0 && ((*(uint *)(param_3 + 0xb8) & 2) == 0)))) &&
       (((*(uint *)(param_3 + 0xd0) & 2) != 0 &&
        (((*(uint *)(iVar18 + 0xb8) & 2) == 0 && ((*(uint *)(iVar18 + 0xd0) & 2) == 0)))))) {
      ((int (*)())FUN_00157b78)(param_3,1,param_4);
    }
    iVar18 = FUN_00105594(param_3,2);
    if (*(int *)(*(int *)(iVar18 + 0x88) + 8) != 0x12) {
      return iVar2;
    }
    iVar17 = FUN_0010497c(iVar18,param_4);
    if (iVar17 == 0) {
      return iVar2;
    }
    if (*(int *)(iVar18 + 0x120) != 0) {
      return iVar2;
    }
    if (*(int *)(iVar18 + 0x124) != 0) {
      return iVar2;
    }
    if ((*(uint *)(param_3 + 0xb8) & 2) != 0) {
      return iVar2;
    }
    if ((*(uint *)(param_3 + 0xd0) & 2) == 0) {
      return iVar2;
    }
    if ((*(uint *)(iVar18 + 0xb8) & 2) != 0) {
      return iVar2;
    }
    uVar8 = *(uint *)(iVar18 + 0xd0);
  }
  if ((uVar8 & 2) == 0) {
    ((int (*)())FUN_00157b78)(param_3,2,param_4);
  }
  return iVar2;
}

/* FUN_00158988 @ 0x158988 (496 bytes) */
int FUN_00158988(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int *param_2;
  int param_3;
  undefined4 param_4;
  uint param_5;
  int param_6;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint local_28 [5];
  
  *(int *)(param_6 + 0x1ac) = *(int *)(param_6 + 0x1ac) + 1;
LAB_001589b0:
  do {
    iVar2 = (**(code **)(*param_2 + 100))(param_2);
    if (iVar2 == 0) {
LAB_00158b48:
      iVar2 = param_2[0x49];
LAB_00158b4c:
      uVar1 = param_2[5];
    }
    else {
      for (iVar2 = 1; iVar3 = (**(code **)(*param_2 + 0x14))(param_2), iVar2 <= iVar3;
          iVar2 = iVar2 + 1) {
        if ((param_2[iVar2 * 6 + 0x28] & 1U) != 0) goto LAB_00158b48;
        if (((param_2[iVar2 * 6 + 0x28] & 2U) != 0) ||
           (iVar3 = FUN_000f31e8(param_2,iVar2), iVar3 == 0)) goto LAB_00158b3c;
      }
      if (param_2[0x48] == 0) {
        iVar2 = param_2[0x49];
        if (iVar2 != 0) goto LAB_00158b4c;
        if ((((param_2[0x20] != 0) && (iVar2 = FUN_00126760(param_2[0x26]), iVar2 != 0)) &&
            ((param_2[5] & 2U) == 0)) &&
           (iVar2 = (**(code **)(*param_2 + 0x50))(param_2), iVar2 == 0)) {
          iVar2 = 4;
          piVar4 = param_2;
          do {
            if (*(byte *)(piVar4 + 0x27) - 2 < 2) goto LAB_00158b48;
            piVar4 = (int *)((int)piVar4 + 1);
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
        FUN_001054ec(param_2,0);
        iVar2 = FUN_00105dbc(param_2,0);
        if (iVar2 != 0) goto LAB_00158b48;
        uVar1 = param_2[5];
        if (((uVar1 & 2) == 0) && ((uVar1 & 0x200) == 0)) {
          param_2 = (int *)FUN_00105594(param_2,1);
          goto LAB_001589b0;
        }
        iVar2 = param_2[0x49];
      }
      else {
LAB_00158b3c:
        iVar2 = param_2[0x49];
        uVar1 = param_2[5];
      }
    }
    param_2[0x49] = param_3 + iVar2;
    while( true ) {
      if ((uVar1 & 0x200) == 0) {
        return;
      }
      param_2 = (int *)FUN_00105594(param_2,param_2[0x21]);
      iVar2 = FUN_001054ec(param_2,0);
      FUN_000f3908(local_28,*(undefined4 *)(iVar2 + 0x10));
      if ((param_5 & local_28[0]) != 0) break;
      uVar1 = param_2[5];
    }
  } while( true );
}

/* FUN_00158b78 @ 0x158b78 (196 bytes) */
int FUN_00158b78(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_2 + 100))(param_2);
  if ((((iVar1 != 0) && (param_2[0x48] == 0)) && ((param_2[5] & 0x200U) == 0)) &&
     ((iVar1 = param_2[0x49], iVar1 != 0 &&
      (iVar2 = ((int (*)())FUN_0015800c)(param_1,param_3,iVar1,param_5,param_6,param_4), iVar2 != 0)))) {
    ((int (*)())FUN_00158988)(param_2,param_3,iVar1,param_5,param_6,param_4);
    param_2[0x49] = 0;
  }
  return;
}

/* FUN_00158c3c @ 0x158c3c (2460 bytes) */
int FUN_00158c3c(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *piVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  int iVar16;
  uint local_68;
  uint local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50 [6];
  
  local_5c = *(undefined4 *)(*(int *)(param_2 + 8) + 0x378);
  local_68 = 2;
  local_64 = 0;
  local_60 = FUN_00193e18(local_5c,8);
  uVar3 = local_64;
  if (local_64 < local_68) {
    iVar13 = local_64 * 4;
    _memset((void *)(local_60 + iVar13),0,4);
    local_64 = uVar3 + 1;
    piVar4 = (int *)(iVar13 + local_60);
  }
  else {
    piVar4 = (int *)FUN_0019423c(&local_68,local_64);
  }
  *piVar4 = param_1;
  uVar11 = 0;
  do {
    piVar4 = (int *)0x0;
    if (local_64 - 1 < local_64) {
      piVar4 = (int *)((local_64 - 1) * 4 + local_60);
    }
    iVar16 = *piVar4;
    FUN_00194208(&local_68);
    iVar13 = *(int *)(iVar16 + 0x124);
    iVar14 = *(int *)(*(int *)(iVar16 + 0x88) + 8);
    if (iVar14 - 0x12U < 3) {
      iVar5 = FUN_001054ec(iVar16,0);
      uVar12 = *(undefined4 *)(iVar5 + 0x10);
      iVar5 = FUN_001054ec(iVar16,1);
      FUN_000f3398(&local_58,*(undefined4 *)(iVar5 + 0x10));
      uVar1 = local_58;
      iVar5 = FUN_001054ec(iVar16,2);
      FUN_000f3398(&local_54,*(undefined4 *)(iVar5 + 0x10));
      uVar2 = local_54;
      piVar4 = (int *)FUN_00105594(iVar16,1);
      piVar6 = (int *)FUN_00105594(iVar16,2);
      if (iVar14 == 0x13) {
        iVar14 = FUN_0010497c(piVar4,param_2);
        if ((iVar14 != 0) && (iVar14 = FUN_0010497c(piVar6,param_2), iVar14 != 0)) {
          ((int (*)())FUN_00158b78)(iVar16,piVar4,piVar6,param_2,uVar12,uVar2);
          ((int (*)())FUN_00158b78)(iVar16,piVar6,piVar4,param_2,uVar12,uVar1);
        }
        if (iVar13 != 0) {
          iVar14 = ((int (*)())FUN_0015800c)(iVar16,piVar4,iVar13,uVar12,uVar1,param_2);
          if (iVar14 == 0) {
            iVar14 = ((int (*)())FUN_0015800c)(iVar16,piVar6,iVar13,uVar12,uVar2,param_2);
            if (iVar14 != 0) {
              ((int (*)())FUN_00158988)(iVar16,piVar6,iVar13,uVar12,uVar2,param_2);
              *(undefined4 *)(iVar16 + 0x124) = 0;
              goto LAB_00158fc8;
            }
          }
          else {
            ((int (*)())FUN_00158988)(iVar16,piVar4,iVar13,uVar12,uVar1,param_2);
            uVar3 = local_64;
            *(undefined4 *)(iVar16 + 0x124) = 0;
            if (local_64 < local_68) {
              iVar13 = local_64 * 4;
              _memset((void *)(iVar13 + local_60),0,4);
              local_64 = uVar3 + 1;
              puVar7 = (undefined4 *)(iVar13 + local_60);
            }
            else {
              puVar7 = (undefined4 *)FUN_0019423c(&local_68,local_64);
            }
            *puVar7 = piVar4;
          }
        }
      }
      else if (iVar14 == 0x14) {
        iVar14 = FUN_0010497c(piVar4,param_2);
        if ((iVar14 != 0) && (iVar14 = FUN_0010497c(piVar6,param_2), iVar14 != 0)) {
          ((int (*)())FUN_00158b78)(iVar16,piVar4,piVar6,param_2,uVar12,uVar2);
          ((int (*)())FUN_00158b78)(iVar16,piVar6,piVar4,param_2,uVar12,uVar1);
          iVar14 = (**(code **)(*piVar4 + 100))(piVar4);
          if (iVar14 != 0) {
            puVar15 = (uint *)(piVar4 + 0x2e);
            for (iVar14 = 1; iVar5 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar14 <= iVar5;
                iVar14 = iVar14 + 1) {
              uVar3 = *puVar15;
              puVar15 = puVar15 + 6;
              if ((((uVar3 & 1) != 0) || ((uVar3 & 2) != 0)) ||
                 (iVar5 = FUN_000f31e8(piVar4,iVar14), iVar5 == 0)) goto LAB_00159218;
            }
            if ((piVar4[0x48] == 0) && (piVar4[0x49] == 0)) {
              if (((piVar4[0x20] != 0) &&
                  ((iVar14 = FUN_00126760(piVar4[0x26]), iVar14 != 0 && ((piVar4[5] & 2U) == 0))))
                 && (iVar14 = (**(code **)(*piVar4 + 0x50))(piVar4), iVar14 == 0)) {
                iVar14 = 4;
                piVar10 = piVar4;
                do {
                  if (*(byte *)(piVar10 + 0x27) - 2 < 2) goto LAB_00159218;
                  piVar10 = (int *)((int)piVar10 + 1);
                  iVar14 = iVar14 + -1;
                } while (iVar14 != 0);
              }
              FUN_001054ec(piVar4,0);
              iVar14 = FUN_00105dbc(piVar4,0);
              if (((iVar14 == 0) && ((piVar4[5] & 2U) == 0)) && ((piVar4[5] & 0x200U) == 0)) {
                *(int *)(param_2 + 0x17c) = *(int *)(param_2 + 0x17c) + 1;
                uVar8 = FUN_00105594(piVar4,1);
                FUN_00106004(iVar16,1,uVar8,0,*(undefined4 *)(param_2 + 8));
                iVar14 = FUN_00105594(piVar4,1);
                if (*(int *)(param_2 + 0x478) < *(int *)(iVar14 + 0x160)) {
                  *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar14 + 0x160) = *(int *)(param_2 + 0x478) + 1;
                }
                FUN_00105894(piVar4,*(undefined4 *)(param_2 + 8));
              }
            }
          }
LAB_00159218:
          iVar14 = (**(code **)(*piVar6 + 100))(piVar6);
          if (iVar14 != 0) {
            puVar15 = (uint *)(piVar6 + 0x2e);
            for (iVar14 = 1; iVar5 = (**(code **)(*piVar6 + 0x14))(piVar6), iVar14 <= iVar5;
                iVar14 = iVar14 + 1) {
              uVar3 = *puVar15;
              puVar15 = puVar15 + 6;
              if ((((uVar3 & 1) != 0) || ((uVar3 & 2) != 0)) ||
                 (iVar5 = FUN_000f31e8(piVar6,iVar14), iVar5 == 0)) goto LAB_001593b8;
            }
            if ((piVar6[0x48] == 0) && (piVar6[0x49] == 0)) {
              if ((piVar6[0x20] != 0) &&
                 (((iVar14 = FUN_00126760(piVar6[0x26]), iVar14 != 0 && ((piVar6[5] & 2U) == 0)) &&
                  (iVar14 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar14 == 0)))) {
                iVar14 = 4;
                piVar10 = piVar6;
                do {
                  if (*(byte *)(piVar10 + 0x27) - 2 < 2) goto LAB_001593b8;
                  piVar10 = (int *)((int)piVar10 + 1);
                  iVar14 = iVar14 + -1;
                } while (iVar14 != 0);
              }
              FUN_001054ec(piVar6,0);
              iVar14 = FUN_00105dbc(piVar6,0);
              if (((iVar14 == 0) && ((piVar6[5] & 2U) == 0)) && ((piVar6[5] & 0x200U) == 0)) {
                *(int *)(param_2 + 0x17c) = *(int *)(param_2 + 0x17c) + 1;
                uVar8 = FUN_00105594(piVar6,1);
                FUN_00106004(iVar16,2,uVar8,0,*(undefined4 *)(param_2 + 8));
                iVar14 = FUN_00105594(piVar6,1);
                if (*(int *)(param_2 + 0x478) < *(int *)(iVar14 + 0x160)) {
                  *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar14 + 0x160) = *(int *)(param_2 + 0x478) + 1;
                }
                FUN_00105894(piVar6,*(undefined4 *)(param_2 + 8));
              }
            }
          }
        }
LAB_001593b8:
        if (iVar13 != 0) {
          uVar9 = FUN_00105594(iVar16,3);
          iVar14 = FUN_001054ec(iVar16,3);
          FUN_000f3398(local_50,*(undefined4 *)(iVar14 + 0x10));
          uVar8 = local_50[0];
          iVar14 = ((int (*)())FUN_0015800c)(iVar16,uVar9,iVar13,uVar12,local_50[0],param_2);
          if (iVar14 != 0) {
            iVar14 = ((int (*)())FUN_0015800c)(iVar16,piVar4,iVar13,uVar12,uVar1,param_2);
            if (iVar14 == 0) {
              iVar14 = ((int (*)())FUN_0015800c)(iVar16,piVar6,iVar13,uVar12,uVar2,param_2);
              if (iVar14 == 0) break;
              ((int (*)())FUN_00158988)(iVar16,piVar6,iVar13,uVar12,uVar2,param_2);
              uVar3 = local_64;
              *(undefined4 *)(iVar16 + 0x124) = 0;
              if (local_64 < local_68) {
                iVar14 = local_64 * 4;
                _memset((void *)(iVar14 + local_60),0,4);
                local_64 = uVar3 + 1;
                puVar7 = (undefined4 *)(iVar14 + local_60);
              }
              else {
                puVar7 = (undefined4 *)FUN_0019423c(&local_68,local_64);
              }
              *puVar7 = piVar6;
            }
            else {
              ((int (*)())FUN_00158988)(iVar16,piVar4,iVar13,uVar12,uVar1,param_2);
              uVar3 = local_64;
              *(undefined4 *)(iVar16 + 0x124) = 0;
              if (local_64 < local_68) {
                iVar14 = local_64 * 4;
                _memset((void *)(iVar14 + local_60),0,4);
                local_64 = uVar3 + 1;
                puVar7 = (undefined4 *)(iVar14 + local_60);
              }
              else {
                puVar7 = (undefined4 *)FUN_0019423c(&local_68,local_64);
              }
              *puVar7 = piVar4;
            }
            ((int (*)())FUN_00158988)(iVar16,uVar9,iVar13,uVar12,uVar8,param_2);
            uVar3 = local_64;
            if (local_64 < local_68) {
              iVar13 = local_64 * 4;
              _memset((void *)(iVar13 + local_60),0,4);
              local_64 = uVar3 + 1;
              puVar7 = (undefined4 *)(iVar13 + local_60);
            }
            else {
              puVar7 = (undefined4 *)FUN_0019423c(&local_68,local_64);
            }
            *puVar7 = uVar9;
          }
        }
      }
      else if (((iVar14 == 0x12) && (iVar13 != 0)) &&
              ((iVar14 = ((int (*)())FUN_0015800c)(iVar16,piVar4,iVar13,uVar12,uVar1,param_2), iVar14 != 0 &&
               (iVar14 = ((int (*)())FUN_0015800c)(iVar16,piVar6,iVar13,uVar12,uVar2,param_2), iVar14 != 0)))) {
        *(undefined4 *)(iVar16 + 0x124) = 0;
        if (param_1 == iVar16) {
          uVar11 = 1;
        }
        ((int (*)())FUN_00158988)(iVar16,piVar4,iVar13,uVar12,uVar1,param_2);
        uVar3 = local_64;
        if (local_64 < local_68) {
          iVar14 = local_64 * 4;
          _memset((void *)(iVar14 + local_60),0,4);
          local_64 = uVar3 + 1;
          puVar7 = (undefined4 *)(iVar14 + local_60);
        }
        else {
          puVar7 = (undefined4 *)FUN_0019423c(&local_68,local_64);
        }
        *puVar7 = piVar4;
        if (piVar4 != piVar6) {
          ((int (*)())FUN_00158988)(iVar16,piVar6,iVar13,uVar12,uVar2,param_2);
LAB_00158fc8:
          uVar3 = local_64;
          if (local_64 < local_68) {
            iVar13 = local_64 * 4;
            _memset((void *)(iVar13 + local_60),0,4);
            local_64 = uVar3 + 1;
            puVar7 = (undefined4 *)(iVar13 + local_60);
          }
          else {
            puVar7 = (undefined4 *)FUN_0019423c(&local_68,local_64);
          }
          *puVar7 = piVar6;
        }
      }
    }
  } while (local_64 != 0);
  FUN_00193cc0(local_5c,local_60);
  return uVar11;
}

/* FUN_001595f0 @ 0x1595f0 (420 bytes) */
int FUN_001595f0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 local_38 [4];
  undefined4 local_28;
  float local_24;
  
  iVar2 = FUN_0017361c();
  if (iVar2 == 0) {
LAB_0015977c:
    uVar6 = 0;
  }
  else {
    iVar2 = FUN_001054ec(param_1,1);
    local_38[0] = *(undefined4 *)(iVar2 + 0x10);
    iVar7 = 0;
    iVar2 = -1;
    do {
      iVar3 = FUN_001054ec(param_1,0);
      iVar5 = iVar2;
      if (*(char *)(iVar7 + iVar3 + 0x10) != '\x01') {
        uVar8 = (uint)*(byte *)((int)local_38 + iVar7);
        piVar4 = (int *)FUN_00105594(param_1,1);
        iVar5 = (**(code **)(*piVar4 + 0x60))();
        if (iVar5 != 0) {
          uVar6 = FUN_001042bc(piVar4,uVar8);
          iVar5 = FUN_001054ec(piVar4,uVar6);
          uVar8 = (uint)*(byte *)(uVar8 + iVar5 + 0x10);
          piVar4 = (int *)FUN_00105594(piVar4,uVar6);
        }
        iVar5 = FUN_00126708(piVar4[0x26]);
        if ((iVar5 == 0) || (((int)*(char *)(piVar4 + 0x57) >> (uVar8 & 0x3f) & 1U) == 0))
        goto LAB_0015977c;
        ((void (*)())FUN_0010b2dc)(&local_28,param_1,1,piVar4[uVar8 * 6 + 8]);
        ((void (*)())FUN_0010b284)(&local_24,param_1,1,local_28);
        iVar5 = ((bool (*)())FUN_0010b820)((double)local_24,(double)FLOAT_001aa0d4,param_1);
        iVar5 = (iVar5 == 0) + 2;
        if ((iVar2 != -1) && (bVar1 = iVar5 != iVar2, iVar5 = iVar2, bVar1)) goto LAB_0015977c;
      }
      bVar1 = iVar7 != 3;
      iVar7 = iVar7 + 1;
      iVar2 = iVar5;
    } while (bVar1);
    *(int *)(param_2 + 0x1ec) = *(int *)(param_2 + 0x1ec) + 1;
    FUN_0010d15c(param_1,iVar5,0,*(undefined4 *)(param_2 + 8));
    uVar6 = 1;
  }
  return uVar6;
}

/* FUN_00159794 @ 0x159794 (964 bytes) */
int FUN_00159794(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28 [2];
  
  iVar2 = *(int *)(param_1 + 0x88);
  local_2c = 0x3f000000;
  local_38 = 0x3f000000;
  local_34 = 0x3f000000;
  local_30 = 0x3f000000;
  if (*(int *)(iVar2 + 8) == 0x24) {
    uVar3 = FUN_00112f54(0x25);
    *(undefined4 *)(param_1 + 0x88) = uVar3;
    FUN_00103d50(param_1 + 0xa4,1,1);
    FUN_00103d50(param_1 + 0xa4,2,1);
    iVar2 = *(int *)(param_1 + 0x88);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
    if (*(int *)(iVar2 + 8) == 0x26) {
      uVar3 = 1;
      uVar10 = FUN_00112f54(0x25);
      *(undefined4 *)(param_1 + 0x88) = uVar10;
      FUN_00103d50(param_1 + 0xa4,1,*(uint *)(param_1 + 0xb8) & 1 ^ 1);
      FUN_0010ac38(param_1,2,3,param_3);
      iVar2 = *(int *)(param_1 + 0x88);
    }
  }
  if (((*(int *)(iVar2 + 8) == 0x25) && ((*(uint *)(*(int *)(param_3 + 0x6c4) + 0x30) & 8) != 0)) &&
     (param_2 != 0)) {
    iVar2 = FUN_00105594(param_1,1);
    iVar4 = FUN_001054ec(iVar2,0);
    uVar10 = *(undefined4 *)(iVar4 + 0x10);
    if ((((*(uint *)(param_1 + 0xb8) & 2) == 0) && (*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x12))
       && (((*(uint *)(iVar2 + 0x14) & 0x200) == 0 &&
           ((*(int *)(iVar2 + 0x120) == 0 && (*(int *)(iVar2 + 0x124) == 0)))))) {
      iVar4 = FUN_00105594(iVar2,1);
      uVar7 = 0;
      if (iVar4 != 0) {
        iVar4 = FUN_00105594(iVar2,1);
        uVar7 = *(undefined4 *)(iVar4 + 0x98);
      }
      iVar4 = FUN_001267b8(uVar7);
      if (iVar4 == 0) {
        piVar5 = (int *)FUN_00105594(iVar2,1);
        iVar4 = (**(code **)(*piVar5 + 0x5c))();
        if (iVar4 == 0) {
          return uVar3;
        }
      }
      if (((((*(uint *)(iVar2 + 0xb8) & 2) == 0) &&
           (uVar1 = *(uint *)(param_1 + 0xb8) & 1, uVar1 == (*(uint *)(iVar2 + 0xd0) & 1))) &&
          (uVar1 != (*(uint *)(iVar2 + 0xb8) & 1))) &&
         (iVar4 = FUN_000f5c0c(iVar2,2,uVar10,&local_38), iVar4 != 0)) {
        uVar3 = FUN_00112f54(0x9d);
        *(undefined4 *)(param_1 + 0x88) = uVar3;
        iVar4 = FUN_001054ec(iVar2,1);
        uVar3 = *(undefined4 *)(iVar4 + 0x10);
        iVar4 = FUN_001054ec(param_1,1);
        FUN_000f2bdc(local_28,uVar3,*(undefined4 *)(iVar4 + 0x10));
        iVar4 = FUN_001054ec(param_1,1);
        *(undefined4 *)(iVar4 + 0x10) = local_28[0];
        FUN_00103d50(param_1 + 0xa4,1,0);
        FUN_0010ac38(param_1,2,3,param_3);
        iVar9 = *(int *)(param_3 + 0x6c4);
        iVar8 = *(int *)(iVar9 + 0x478);
        piVar5 = (int *)FUN_00105594(iVar2,1);
        iVar4 = (**(code **)(*piVar5 + 0x5c))();
        if ((iVar4 == 0) || (iVar4 = FUN_0010497c(piVar5,iVar9), iVar4 != 0)) {
          FUN_00106004(param_1,1,piVar5,0,param_3);
          if (iVar8 < piVar5[0x58]) {
            piVar5[0x58] = piVar5[0x58] + 1;
          }
          else {
            piVar5[0x58] = iVar8 + 1;
          }
        }
        else {
          iVar4 = FUN_0010445c(piVar5,param_3,0);
          *(undefined4 *)(iVar4 + 0x94) = *(undefined4 *)(iVar4 + 0x14c);
          FUN_000e7738(piVar5[0x56],piVar5,iVar4);
          FUN_00106004(param_1,1,iVar4,0,param_3);
          *(int *)(iVar4 + 0x160) = *(int *)(iVar9 + 0x478) + 1;
          if (0 < *(int *)(iVar4 + 0x84)) {
            iVar9 = 1;
            do {
              iVar6 = FUN_00105594(iVar4,iVar9);
              if (iVar8 < *(int *)(iVar6 + 0x160)) {
                *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
              }
              else {
                *(int *)(iVar6 + 0x160) = iVar8 + 1;
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 <= *(int *)(iVar4 + 0x84));
          }
        }
        FUN_00105894(iVar2,param_3);
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}

/* FUN_00159b58 @ 0x159b58 (2844 bytes) */
int FUN_00159b58(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  float fVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  double dVar13;
  undefined1 auStack_118 [4];
  undefined4 local_114;
  undefined1 auStack_100 [4];
  undefined4 local_fc;
  undefined1 auStack_e8 [4];
  float local_e4;
  undefined1 auStack_d0 [4];
  float local_cc;
  undefined1 auStack_b8 [4];
  float local_b4;
  undefined1 auStack_a0 [4];
  float local_9c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  float local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c [3];
  float local_50;
  
  iVar12 = *(int *)(param_3 + 8);
  if ((((*(int *)(*(int *)(iVar12 + 0x6c4) + 0x214) + *(int *)(*(int *)(iVar12 + 0x6c4) + 0x218) <
         *(int *)(iVar12 + 0x6a0)) && (param_1 != 0)) && (0 < *(int *)(param_1 + 0x84))) &&
     (iVar2 = FUN_00105594(param_1,1), iVar2 != 0)) {
    ((int (*)())FUN_00159794)(param_1,param_2,iVar12);
    ((int (*)())FUN_00159794)(iVar2,param_2,iVar12);
    iVar8 = *(int *)(param_1 + 0x88);
    if ((*(int *)(iVar8 + 8) == 0x25) && (*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x25)) {
      iVar8 = FUN_000f48ec(param_1,1);
      if (iVar8 != 0) {
        iVar8 = FUN_001054ec(iVar2,0);
        iVar8 = FUN_000f5cf0(iVar2,2,*(undefined4 *)(iVar8 + 0x10),auStack_118);
        if (iVar8 != 0) {
          iVar8 = FUN_001054ec(iVar2,0);
          iVar8 = FUN_000f5cf0(iVar2,3,*(undefined4 *)(iVar8 + 0x10),auStack_100);
          if (iVar8 != 0) {
            *(int *)(param_3 + 0x214) = *(int *)(param_3 + 0x214) + 1;
            piVar3 = (int *)FUN_00105594(iVar2,1);
            iVar8 = (**(code **)(*piVar3 + 0x5c))();
            piVar4 = piVar3;
            if ((iVar8 != 0) && (iVar8 = FUN_0010497c(piVar3,param_3), iVar8 == 0)) {
              piVar4 = (int *)FUN_0010445c(piVar3,iVar12,0);
              piVar4[0x25] = piVar4[0x53];
              FUN_000e7738(piVar3[0x56],piVar3,piVar4);
              piVar4[0x58] = *(int *)(param_3 + 0x478);
              if (0 < piVar4[0x21]) {
                iVar8 = 1;
                do {
                  iVar6 = FUN_00105594(piVar4,iVar8);
                  if (*(int *)(param_3 + 0x478) < *(int *)(iVar6 + 0x160)) {
                    *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar6 + 0x160) = *(int *)(param_3 + 0x478) + 1;
                  }
                  iVar8 = iVar8 + 1;
                } while (iVar8 <= piVar4[0x21]);
              }
            }
            ((float * (*)())FUN_0010aee8)(&local_88,iVar2,local_114);
            ((float * (*)())FUN_0010aee8)(&local_84,iVar2,local_fc);
            ((void (*)())FUN_0010b118)(&local_80,iVar2,local_88);
            ((void (*)())FUN_0010b118)(&local_7c,iVar2,local_84);
            ((void (*)())FUN_0010b2dc)(&local_78,param_1,1,local_80);
            ((void (*)())FUN_0010b2dc)(&local_74,param_1,1,local_7c);
            ((void (*)())FUN_0010b284)(&local_70,param_1,1,local_78);
            ((void (*)())FUN_0010b284)(&local_6c,param_1,1,local_74);
            local_50 = local_70;
            if ((FLOAT_001aa0d4 <= local_70) || (local_50 = local_6c, FLOAT_001aa0d4 <= local_6c)) {
              if ((FLOAT_001aa0d4 > local_70) || (local_50 = local_6c, local_6c < FLOAT_001aa0d4)) {
                uVar11 = *(uint *)(iVar2 + 0xb8);
                iVar8 = (**(code **)(*piVar4 + 0x5c))(piVar4);
                piVar3 = piVar4;
                if (iVar8 != 0) {
                  iVar6 = *(int *)(param_3 + 0x478);
                  piVar3 = (int *)FUN_0010445c(piVar4,*(undefined4 *)(param_3 + 8),0);
                  iVar10 = piVar3[0x53];
                  iVar8 = FUN_001054ec(piVar3,0);
                  *(int *)(iVar8 + 8) = iVar10;
                  piVar3[0x58] = iVar6;
                  for (iVar8 = 1; iVar10 = (**(code **)(*piVar3 + 0x14))(piVar3), iVar8 <= iVar10;
                      iVar8 = iVar8 + 1) {
                    iVar10 = FUN_00105594(piVar3,iVar8);
                    if (iVar6 < *(int *)(iVar10 + 0x160)) {
                      *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar10 + 0x160) = iVar6 + 1;
                    }
                  }
                  FUN_000e7700(piVar4[0x56],piVar4,piVar3);
                }
                FUN_00106004(param_1,1,piVar3,0,iVar12);
                if (*(int *)(param_3 + 0x478) < piVar3[0x58]) {
                  piVar3[0x58] = piVar3[0x58] + 1;
                }
                else {
                  piVar3[0x58] = *(int *)(param_3 + 0x478) + 1;
                }
                FUN_00103d50(param_1 + 0xa4,1,uVar11 & 1);
                FUN_00103d50(param_1 + 0xa4,2,uVar11 >> 1 & 1);
                iVar8 = FUN_001054ec(iVar2,1);
                uVar5 = *(undefined4 *)(iVar8 + 0x10);
                iVar8 = FUN_001054ec(param_1,1);
                FUN_000f2bdc(&local_68,uVar5,*(undefined4 *)(iVar8 + 0x10));
                iVar8 = FUN_001054ec(param_1,1);
                fVar1 = FLOAT_001aa0d4;
                *(undefined4 *)(iVar8 + 0x10) = local_68;
                if ((local_70 < fVar1) || (local_50 = local_6c, fVar1 <= local_6c)) {
                  FUN_0010ac38(param_1,2,3,iVar12);
                }
                uVar5 = FUN_00105894(iVar2,iVar12);
                return uVar5;
              }
              uVar5 = 2;
            }
            else {
              uVar5 = 3;
            }
            FUN_0010d15c(param_1,uVar5,0,iVar12);
            return 0;
          }
        }
      }
      iVar8 = *(int *)(param_1 + 0x88);
    }
    if (*(int *)(iVar8 + 8) == 0x8b) {
      iVar8 = *(int *)(param_1 + 300);
      iVar2 = FUN_001054ec(param_1,0);
      iVar2 = FUN_000f5cf0(param_1,2,*(undefined4 *)(iVar2 + 0x10),auStack_e8);
      if (iVar2 == 0) {
        iVar2 = FUN_001054ec(param_1,0);
        iVar2 = FUN_000f5cf0(param_1,1,*(undefined4 *)(iVar2 + 0x10),auStack_e8);
        if (iVar2 == 0) {
          return 0;
        }
        FUN_0010ac38(param_1,1,2,iVar12);
        iVar8 = *(int *)(PTR_DAT_001e90f8 + iVar8 * 4);
        *(int *)(param_1 + 300) = iVar8;
      }
      iVar2 = FUN_00105594(param_1,1);
      if (((*(uint *)(param_1 + 0xb8) & 2) == 0) && ((*(uint *)(param_1 + 0xd0) & 2) == 0)) {
        if ((*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x12) &&
           (((local_e4 == FLOAT_001aa0d4 && (*(int *)(iVar2 + 0x120) == 0)) &&
            ((*(uint *)(iVar2 + 0x14) & 0x200) == 0)))) {
          iVar8 = FUN_001054ec(param_1,1);
          uVar9 = *(undefined4 *)(iVar8 + 0x10);
          *(int *)(param_3 + 0x218) = *(int *)(param_3 + 0x218) + 1;
          uVar5 = FUN_00105594(param_1,2);
          FUN_00105894(uVar5,iVar12);
          uVar5 = FUN_00105594(iVar2,1);
          FUN_00106004(param_1,1,uVar5,0,iVar12);
          iVar8 = FUN_001054ec(iVar2,1);
          FUN_000f2bdc(&local_64,*(undefined4 *)(iVar8 + 0x10),uVar9);
          iVar8 = FUN_001054ec(param_1,1);
          *(undefined4 *)(iVar8 + 0x10) = local_64;
          iVar8 = FUN_00105594(iVar2,1);
          if (*(int *)(param_3 + 0x478) < *(int *)(iVar8 + 0x160)) {
            *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
          }
          else {
            *(int *)(iVar8 + 0x160) = *(int *)(param_3 + 0x478) + 1;
          }
          FUN_00103d50(param_1 + 0xa4,2,*(uint *)(iVar2 + 0xb8) >> 1 & 1);
          uVar5 = FUN_00105594(iVar2,2);
          FUN_00106004(param_1,2,uVar5,0,iVar12);
          iVar8 = FUN_001054ec(iVar2,2);
          FUN_000f2bdc(&local_60,*(undefined4 *)(iVar8 + 0x10),uVar9);
          iVar8 = FUN_001054ec(param_1,2);
          *(undefined4 *)(iVar8 + 0x10) = local_60;
          iVar8 = FUN_00105594(iVar2,2);
          if (*(int *)(param_3 + 0x478) < *(int *)(iVar8 + 0x160)) {
            *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
          }
          else {
            *(int *)(iVar8 + 0x160) = *(int *)(param_3 + 0x478) + 1;
          }
          FUN_00103d50(param_1 + 0xbc,2,*(uint *)(iVar2 + 0xd0) >> 1 & 1);
          uVar11 = *(uint *)(param_1 + 0xb8) & 1;
          uVar7 = uVar11;
          if ((*(uint *)(iVar2 + 0xb8) & 1) != 0) {
            uVar7 = uVar11 ^ 1;
          }
          if ((*(uint *)(iVar2 + 0xd0) & 1) != 0) {
            uVar11 = uVar11 ^ 1;
          }
          FUN_00103d50(param_1 + 0xa4,1,uVar7);
          FUN_00103d50(param_1 + 0xbc,1,uVar11 ^ 1);
          uVar5 = FUN_00105894(iVar2,iVar12);
          return uVar5;
        }
        iVar6 = FUN_001054ec(param_1,0);
        iVar6 = FUN_000f5cf0(param_1,2,*(undefined4 *)(iVar6 + 0x10),auStack_d0);
        if (((*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x25) && (iVar6 != 0)) &&
           ((local_cc == FLOAT_001aa0d4 &&
            (((*(uint *)(iVar2 + 0x14) & 0x200) == 0 ||
             (iVar6 = FUN_000f45f8(param_1,1,iVar2,param_3), iVar6 != 0)))))) {
          iVar6 = FUN_001054ec(iVar2,0);
          iVar6 = FUN_000f5cf0(iVar2,2,*(undefined4 *)(iVar6 + 0x10),auStack_b8);
          if (iVar6 != 0) {
            iVar6 = FUN_001054ec(iVar2,0);
            iVar6 = FUN_000f5cf0(iVar2,3,*(undefined4 *)(iVar6 + 0x10),auStack_a0);
            if (iVar6 != 0) {
              *(int *)(param_3 + 0x218) = *(int *)(param_3 + 0x218) + 1;
              switch(iVar8) {
              case 0:
                uVar11 = (uint)(local_e4 == local_9c);
                uVar7 = (uint)(local_e4 == local_b4);
                break;
              case 1:
                uVar11 = (uint)(local_e4 != local_9c);
                uVar7 = (uint)(local_e4 != local_b4);
                break;
              case 2:
                uVar11 = (uint)(local_e4 < local_9c);
                uVar7 = (uint)(local_e4 < local_b4);
                break;
              case 3:
                uVar11 = (uint)(local_e4 <= local_9c);
                uVar7 = (uint)(local_e4 <= local_b4);
                break;
              case 4:
                uVar11 = (uint)(local_9c < local_e4);
                uVar7 = (uint)(local_b4 < local_e4);
                break;
              case 5:
                uVar11 = (uint)(local_9c <= local_e4);
                uVar7 = (uint)(local_b4 <= local_e4);
                break;
              default:
                goto switchD_0015a394_default;
              }
              iVar8 = FUN_001054ec(iVar2,1);
              uVar5 = *(undefined4 *)(iVar8 + 0x10);
              iVar8 = FUN_001054ec(param_1,1);
              FUN_000f2bdc(local_5c,uVar5,*(undefined4 *)(iVar8 + 0x10));
              FUN_00105e54(param_1,1,iVar2,1);
              iVar8 = FUN_001054ec(param_1,1);
              *(undefined4 *)(iVar8 + 0x10) = local_5c[0];
              if (uVar7 == uVar11) {
                fVar1 = FLOAT_001aa0e8;
                if (uVar7 != 0) {
                  fVar1 = FLOAT_001aa0d4;
                }
                dVar13 = (double)fVar1;
                piVar4 = (int *)0x0;
                FUN_000f79c4(dVar13,dVar13,dVar13,dVar13,param_1,param_3,1);
              }
              else {
                piVar4 = (int *)FUN_00105594(iVar2,1);
                if (*(int *)(param_3 + 0x478) < piVar4[0x58]) {
                  piVar4[0x58] = piVar4[0x58] + 1;
                }
                else {
                  piVar4[0x58] = *(int *)(param_3 + 0x478) + 1;
                }
                *(uint *)(param_1 + 300) = (uVar7 ^ 1) + 3;
              }
              uVar5 = FUN_00105894(iVar2,iVar12);
              if (piVar4 == (int *)0x0) {
                return uVar5;
              }
              iVar2 = (**(code **)(*piVar4 + 0x5c))(piVar4);
              if (iVar2 == 0) {
                return uVar5;
              }
              iVar2 = FUN_0010497c(piVar4,param_3);
              if (iVar2 == 0) {
                iVar8 = *(int *)(param_3 + 0x478);
                piVar4[0x58] = piVar4[0x58] + -1;
                iVar6 = iVar8 + 1;
                piVar4 = (int *)FUN_0010445c(piVar4,*(undefined4 *)(param_3 + 8),0);
                iVar10 = piVar4[0x53];
                iVar2 = FUN_001054ec(piVar4,0);
                *(int *)(iVar2 + 8) = iVar10;
                piVar4[0x58] = iVar6;
                for (iVar2 = 1; iVar10 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar2 <= iVar10;
                    iVar2 = iVar2 + 1) {
                  iVar10 = FUN_00105594(piVar4,iVar2);
                  if (iVar8 < *(int *)(iVar10 + 0x160)) {
                    *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar10 + 0x160) = iVar6;
                  }
                }
                FUN_00106004(param_1,1,piVar4,0,iVar12);
                FUN_000e7700(*(undefined4 *)(param_1 + 0x158),param_1,piVar4);
                return uVar5;
              }
              return uVar5;
            }
          }
        }
      }
    }
  }
switchD_0015a394_default:
  return 0;
}

/* FUN_0015a68c @ 0x15a68c (3608 bytes) */
int FUN_0015a68c(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int *piVar19;
  int *piVar20;
  int *piVar21;
  undefined4 uVar22;
  uint uVar23;
  uint *puVar24;
  int *piVar25;
  int iVar26;
  int iStack00000018;
  undefined4 local_88;
  undefined4 local_84;
  int local_80;
  undefined4 local_7c;
  undefined4 local_78;
  int local_74;
  int local_70;
  uint local_6c;
  int local_68;
  int local_64;
  int *local_60;
  int local_5c;
  int local_58;
  int local_54;
  
  uVar17 = *(uint *)(*(int *)(param_1 + 0x10) + 4);
  iVar5 = uVar17 << 2;
  iStack00000018 = param_1;
  iVar3 = FUN_00193e18(*(undefined4 *)(*(int *)(param_2 + 8) + 0x378),iVar5);
  iVar4 = FUN_00193e18(*(undefined4 *)(*(int *)(param_2 + 8) + 0x378),iVar5);
  iVar5 = FUN_00193e18(*(undefined4 *)(*(int *)(param_2 + 8) + 0x378),iVar5);
  if (0 < (int)uVar17) {
    uVar23 = 0;
    iVar16 = 0;
    iVar18 = 0;
    do {
      puVar24 = *(uint **)(iStack00000018 + 0x10);
      if (uVar23 < *puVar24) {
        uVar6 = puVar24[1];
        if (uVar6 <= uVar23) {
          _memset((void *)(uVar6 * 4 + puVar24[2]),0,(uVar23 - uVar6) * 4 + 4);
          puVar24[1] = uVar23 + 1;
        }
        puVar7 = (undefined4 *)(iVar18 + puVar24[2]);
      }
      else {
        puVar7 = (undefined4 *)FUN_0019423c(puVar24,uVar23);
      }
      uVar23 = uVar23 + 1;
      piVar20 = (int *)*puVar7;
      bVar2 = false;
      *(int **)(iVar18 + iVar3) = piVar20;
      *(undefined4 *)(iVar18 + iVar4) = 0;
      *(undefined4 *)(iVar18 + iVar5) = 0;
      while ((((*(int *)(piVar20[0x22] + 8) == 0x13 && ((piVar20[5] & 0x200U) == 0)) &&
              (iVar9 = FUN_0010497c(piVar20,param_2), iVar9 != 0)) && (piVar20[0x48] == 0))) {
        piVar10 = (int *)piVar20[4];
        if (*piVar10 == 0) {
          puVar7 = (undefined4 *)FUN_0019423c(piVar10,0);
        }
        else {
          if (piVar10[1] == 0) {
            *(undefined4 *)piVar10[2] = 0;
            piVar10[1] = 1;
          }
          puVar7 = (undefined4 *)piVar10[2];
        }
        piVar10 = (int *)*puVar7;
        bVar1 = false;
        puVar24 = (uint *)(piVar10 + 0x2e);
        for (iVar9 = 1; iVar8 = (**(code **)(*piVar10 + 0x14))(piVar10), iVar9 <= iVar8;
            iVar9 = iVar9 + 1) {
          piVar19 = (int *)FUN_00105594(piVar10,iVar9);
          if (piVar20 == piVar19) {
            iVar8 = FUN_001054ec(piVar10,iVar9);
            iVar8 = FUN_000f3190(*(undefined4 *)(iVar8 + 0x10));
            if ((iVar8 == 0) || ((*puVar24 & 2) != 0)) {
              bVar1 = true;
            }
            *(int *)(iVar18 + iVar5) = iVar9;
          }
          puVar24 = puVar24 + 6;
        }
        if (bVar1) break;
        bVar2 = true;
        piVar20 = piVar10;
      }
      if (bVar2) {
        if (((piVar20[5] & 0x200U) != 0) ||
           ((*(int *)(piVar20[0x22] + 8) != 0x12 && (*(int *)(piVar20[0x22] + 8) != 0x14))))
        goto LAB_0015a760;
        *(undefined4 *)(iVar18 + iVar4) = piVar20;
        iVar16 = iVar16 + 1;
      }
      else if (((*(int *)(piVar20[0x22] + 8) == 0x14) && ((piVar20[5] & 0x200U) == 0)) &&
              ((iVar9 = FUN_00105594(piVar20,1), iStack00000018 == iVar9 ||
               (iVar9 = FUN_00105594(piVar20,2), iStack00000018 == iVar9)))) {
        *(undefined4 *)(iVar18 + iVar4) = piVar20;
        iVar8 = FUN_00105594(piVar20,1);
        iVar9 = 2;
        if (iStack00000018 == iVar8) {
          iVar9 = 1;
        }
        iVar16 = iVar16 + 1;
        *(int *)(iVar18 + iVar5) = iVar9;
      }
      else {
LAB_0015a760:
        *(undefined4 *)(iVar18 + iVar3) = 0;
      }
      iVar18 = iVar18 + 4;
    } while (uVar17 != uVar23);
    if (1 < iVar16) {
      iVar16 = 0;
      uVar22 = 0;
      do {
        iVar18 = iVar16 * 4;
        piVar20 = (int *)(iVar3 + iVar18);
        if ((*(int *)(iVar3 + iVar18) == 0) ||
           ((*(uint *)(*(int *)(iVar3 + iVar18) + 0x14) & 1) == 0)) {
LAB_0015a9bc:
          iVar16 = iVar16 + 1;
        }
        else {
          local_60 = (int *)(iVar4 + iVar18);
          iVar9 = 1;
          if ((*(uint *)(*(int *)(iVar4 + iVar18) + 0x14) & 1) == 0) goto LAB_0015a9bc;
          for (; iVar8 = (**(code **)(*(int *)*piVar20 + 0x14))(), iVar9 <= iVar8; iVar9 = iVar9 + 1
              ) {
            iVar8 = FUN_00105594(*piVar20,iVar9);
            if (iStack00000018 == iVar8) {
              iVar8 = FUN_001054ec(*piVar20,iVar9);
              local_5c = *(int *)(iVar8 + 0x10);
              local_6c = *(uint *)(iVar9 * 0x18 + *piVar20 + 0xa0) >> 1 & 1;
              local_68 = iVar9;
              goto LAB_0015aa4c;
            }
          }
          local_68 = 0;
          local_6c = 0;
LAB_0015aa4c:
          local_70 = iVar16 + 1;
          iVar16 = local_70;
          if (local_70 < (int)uVar17) {
            iVar16 = local_70 * 4;
            piVar21 = (int *)(iVar4 + iVar16);
            piVar19 = (int *)(iVar3 + iVar16);
            local_64 = 3 - local_68;
            piVar10 = (int *)(iVar5 + iVar16);
            iVar9 = 0;
            local_54 = local_64 * 0x18 + 0x80;
            do {
              piVar11 = (int *)*piVar19;
              if ((((piVar11 != (int *)0x0) && ((piVar11[5] & 1U) != 0)) &&
                  ((*(uint *)(*piVar21 + 0x14) & 1) != 0)) &&
                 ((piVar11 != (int *)*piVar20 && (*local_60 == *piVar21)))) {
                if ((*(int *)(iVar5 + iVar18) != *piVar10) &&
                   (((*(int *)(*(int *)(*local_60 + 0x88) + 8) != 0x14 ||
                     (*(int *)(iVar5 + iVar18) == 3)) || (*piVar10 == 3)))) {
                  uVar23 = 0;
                  for (iVar16 = 1; iVar8 = (**(code **)(*piVar11 + 0x14))(), iVar16 <= iVar8;
                      iVar16 = iVar16 + 1) {
                    iVar8 = FUN_00105594(*piVar19,iVar16);
                    if (iStack00000018 == iVar8) {
                      iVar8 = FUN_001054ec(*piVar19,iVar16);
                      local_58 = *(int *)(iVar8 + 0x10);
                      piVar11 = (int *)*piVar19;
                      uVar23 = (uint)piVar11[iVar16 * 6 + 0x28] >> 1 & 1;
                      if ((local_58 == local_5c) && (uVar6 = local_6c, local_6c == uVar23))
                      goto LAB_0015abb0;
                    }
                    else {
                      piVar11 = (int *)*piVar19;
                    }
                  }
                  local_74 = 0;
                  uVar6 = uVar23;
                  iVar16 = local_74;
LAB_0015abb0:
                  local_74 = iVar16;
                  if ((local_58 == local_5c) && (local_6c == uVar6)) {
                    *(int *)(param_2 + 0x1cc) = *(int *)(param_2 + 0x1cc) + 1;
                    iVar16 = *piVar20;
                    if (iVar16 != *local_60) {
                      piVar11 = *(int **)(iVar16 + 0x10);
                      if (*piVar11 == 0) {
                        puVar7 = (undefined4 *)FUN_0019423c(piVar11,0);
                        iVar16 = *piVar20;
                      }
                      else {
                        if (piVar11[1] == 0) {
                          *(undefined4 *)piVar11[2] = 0;
                          piVar11[1] = 1;
                          iVar16 = *piVar20;
                        }
                        puVar7 = (undefined4 *)piVar11[2];
                      }
                      piVar25 = (int *)*puVar7;
                      piVar13 = piVar25 + 0x26;
                      local_78 = FUN_00105594(iVar16,local_64);
                      iVar16 = FUN_001054ec(*piVar20,local_64);
                      piVar11 = (int *)*piVar20;
                      iVar16 = *(int *)(iVar16 + 0x10);
                      uVar6 = *(uint *)((int)piVar11 + local_54 + 0x20);
                      uVar23 = piVar11[local_68 * 6 + 0x28];
                      (**(code **)(*piVar11 + 0xc))(piVar11,1,*(undefined4 *)(param_2 + 8));
                      for (iVar8 = 1; iVar12 = (**(code **)(*piVar25 + 0x14))(piVar25),
                          iVar8 <= iVar12; iVar8 = iVar8 + 1) {
                        iVar12 = FUN_00105594(piVar25,iVar8);
                        if (iVar12 == *piVar20) {
                          FUN_00106004(piVar25,iVar8,local_78,1,*(undefined4 *)(param_2 + 8));
                          if (iVar8 == 0) {
                            piVar25[0x27] = iVar16;
                          }
                          else {
                            iVar12 = FUN_001054ec(piVar25,iVar8);
                            *(int *)(iVar12 + 0x10) = iVar16;
                          }
                          FUN_00103d50(piVar13 + 3,2,uVar6 >> 1 & 1);
                          FUN_00103d50(piVar13 + 3,1,(uVar23 ^ uVar6) & 1 ^ piVar13[8] & 1U);
                        }
                        piVar13 = piVar13 + 6;
                      }
                    }
                    iVar16 = *piVar19;
                    if (iVar16 != *piVar21) {
                      piVar11 = *(int **)(iVar16 + 0x10);
                      if (*piVar11 == 0) {
                        puVar7 = (undefined4 *)FUN_0019423c(piVar11,0);
                        iVar16 = *piVar19;
                      }
                      else {
                        if (piVar11[1] == 0) {
                          *(undefined4 *)piVar11[2] = 0;
                          piVar11[1] = 1;
                          iVar16 = *piVar19;
                        }
                        puVar7 = (undefined4 *)piVar11[2];
                      }
                      piVar25 = (int *)*puVar7;
                      iVar8 = 3 - local_74;
                      piVar13 = piVar25 + 0x26;
                      local_7c = FUN_00105594(iVar16,iVar8);
                      iVar16 = FUN_001054ec(*piVar19,iVar8);
                      piVar11 = (int *)*piVar19;
                      iVar16 = *(int *)(iVar16 + 0x10);
                      uVar6 = piVar11[iVar8 * 6 + 0x28];
                      uVar23 = piVar11[local_74 * 6 + 0x28];
                      (**(code **)(*piVar11 + 0xc))(piVar11,1,*(undefined4 *)(param_2 + 8));
                      for (iVar8 = 1; iVar12 = (**(code **)(*piVar25 + 0x14))(piVar25),
                          iVar8 <= iVar12; iVar8 = iVar8 + 1) {
                        iVar12 = FUN_00105594(piVar25,iVar8);
                        if (iVar12 == *piVar19) {
                          FUN_00106004(piVar25,iVar8,local_7c,1,*(undefined4 *)(param_2 + 8));
                          if (iVar8 == 0) {
                            piVar25[0x27] = iVar16;
                          }
                          else {
                            iVar12 = FUN_001054ec(piVar25,iVar8);
                            *(int *)(iVar12 + 0x10) = iVar16;
                          }
                          FUN_00103d50(piVar13 + 3,2,uVar6 >> 1 & 1);
                          FUN_00103d50(piVar13 + 3,1,(uVar23 ^ uVar6) & 1 ^ piVar13[8] & 1U);
                        }
                        piVar13 = piVar13 + 6;
                      }
                    }
                    piVar11 = (int *)FUN_001043f0(0x13,*(undefined4 *)(param_2 + 8));
                    FUN_00106004(piVar11,1,iStack00000018,1,*(undefined4 *)(param_2 + 8));
                    iVar16 = FUN_001054ec(piVar11,1);
                    *(int *)(iVar16 + 0x10) = local_5c;
                    FUN_00103d50(piVar11 + 0x29,2,local_6c);
                    piVar11[0x26] = 0;
                    piVar11[0x25] = piVar11[0x53];
                    iVar16 = FUN_001054ec(*piVar21,0);
                    piVar11[0x27] = *(int *)(iVar16 + 0x10);
                    piVar11[0x48] = *(int *)(*piVar21 + 0x120);
                    piVar11[0x49] = *(int *)(*piVar21 + 0x124);
                    iVar16 = *piVar21;
                    iVar8 = *(int *)(*(int *)(iVar16 + 0x10) + 4);
                    uVar23 = iVar8 - 1;
                    if (-1 < (int)uVar23) {
                      iVar12 = uVar23 * 4;
                      local_80 = 0;
                      do {
                        puVar24 = *(uint **)(iVar16 + 0x10);
                        if (uVar23 < *puVar24) {
                          uVar6 = puVar24[1];
                          if (uVar6 <= uVar23) {
                            _memset((void *)(uVar6 * 4 + puVar24[2]),0,(uVar23 - uVar6) * 4 + 4);
                            puVar24[1] = uVar23 + 1;
                          }
                          piVar13 = (int *)(iVar12 + puVar24[2]);
                        }
                        else {
                          piVar13 = (int *)FUN_0019423c(puVar24,uVar23);
                        }
                        iVar16 = *piVar13;
                        iVar26 = *(int *)(iVar16 + 0x84);
                        if ((*(uint *)(iVar16 + 0x14) & 0x200) == 0) {
LAB_0015b040:
                          if (0 < iVar26) {
                            iVar14 = 1;
                            do {
                              iVar15 = FUN_00105594(iVar16,iVar14);
                              if (iVar15 == *piVar21) {
                                FUN_00106004(iVar16,iVar14,piVar11,1,*(undefined4 *)(param_2 + 8));
                                break;
                              }
                              iVar14 = iVar14 + 1;
                            } while (iVar14 <= iVar26);
                          }
                        }
                        else {
                          iVar14 = FUN_00105594(iVar16,iVar26);
                          iVar26 = iVar26 + -1;
                          if (iVar14 != *piVar21) goto LAB_0015b040;
                          FUN_00106804(iVar16,piVar11,1,*(undefined4 *)(param_2 + 8));
                        }
                        uVar23 = uVar23 - 1;
                        iVar12 = iVar12 + -4;
                        local_80 = local_80 + 1;
                        if (iVar8 == local_80) break;
                        iVar16 = *piVar21;
                      } while( true );
                    }
                    uVar22 = DAT_001b004c;
                    iVar16 = FUN_001054ec(piVar11,0);
                    FUN_000f3908(&local_88,*(undefined4 *)(iVar16 + 0x10));
                    FUN_000f3340(&local_84,uVar22,local_88);
                    uVar22 = local_84;
                    iVar16 = FUN_001054ec(piVar11,2);
                    *(undefined4 *)(iVar16 + 0x10) = uVar22;
                    FUN_000e7738(*(undefined4 *)(*piVar21 + 0x158),*piVar21,piVar11);
                    if (*piVar20 == *local_60) {
                      piVar13 = (int *)*piVar21;
LAB_0015b134:
                      (**(code **)(*piVar13 + 0xc))(piVar13,1,*(undefined4 *)(param_2 + 8));
                      iVar16 = FUN_001043f0(0x12,*(undefined4 *)(param_2 + 8));
                      uVar22 = FUN_00105594(*piVar21,3);
                      FUN_00106004(iVar16,2,uVar22,1,*(undefined4 *)(param_2 + 8));
                      uVar22 = FUN_001054ec(*piVar21,3);
                      FUN_001062c0(iVar16,2,uVar22,*(undefined4 *)(param_2 + 8));
                      if ((*piVar20 == *local_60) && (local_68 == 1)) {
                        iVar8 = *piVar21;
LAB_0015b1ec:
                        uVar22 = FUN_00105594(iVar8,2);
                        FUN_00106004(iVar16,1,uVar22,1,*(undefined4 *)(param_2 + 8));
                        iVar8 = *piVar21;
                        uVar22 = 2;
                      }
                      else {
                        iVar8 = *piVar21;
                        if ((*piVar19 == iVar8) && (local_74 == 1)) goto LAB_0015b1ec;
                        uVar22 = FUN_00105594(iVar8,1);
                        FUN_00106004(iVar16,1,uVar22,1,*(undefined4 *)(param_2 + 8));
                        iVar8 = *piVar21;
                        uVar22 = 1;
                      }
                      uVar22 = FUN_001054ec(iVar8,uVar22);
                      FUN_001062c0(iVar16,1,uVar22,*(undefined4 *)(param_2 + 8));
                      FUN_00103d50(iVar16 + 0xa4,1,
                                   (*(uint *)(*piVar21 + 0xd0) ^ *(uint *)(*piVar21 + 0xb8)) & 1);
                      *(undefined4 *)(iVar16 + 0x98) = 0;
                      *(undefined4 *)(iVar16 + 0x94) = *(undefined4 *)(iVar16 + 0x14c);
                      iVar8 = FUN_001054ec(*piVar21,0);
                      *(undefined4 *)(iVar16 + 0x9c) = *(undefined4 *)(iVar8 + 0x10);
                      FUN_00106004(piVar11,2,iVar16,1,*(undefined4 *)(param_2 + 8));
                      FUN_000e7700(piVar11[0x56],piVar11,iVar16);
                    }
                    else {
                      piVar13 = (int *)*piVar21;
                      if ((int *)*piVar19 == piVar13) goto LAB_0015b134;
                      FUN_00106004(piVar11,2,piVar13,1,*(undefined4 *)(param_2 + 8));
                      *(undefined4 *)(*piVar21 + 0x120) = 0;
                      *(undefined4 *)(*piVar21 + 0x124) = 0;
                    }
                    *piVar19 = (int)piVar11;
                    *piVar21 = 0;
                    *piVar10 = 0;
                    while (piVar13 = piVar11, *(int *)(piVar13[0x22] + 8) == 0x13) {
                      uVar23 = piVar13[5];
                      if ((uVar23 & 0x200) != 0) goto LAB_0015b3f0;
                      iVar16 = FUN_0010497c(piVar13,param_2);
                      if ((iVar16 == 0) || (piVar13[0x48] != 0)) break;
                      piVar11 = (int *)piVar13[4];
                      if (*piVar11 == 0) {
                        puVar7 = (undefined4 *)FUN_0019423c(piVar11,0);
                      }
                      else {
                        if (piVar11[1] == 0) {
                          *(undefined4 *)piVar11[2] = 0;
                          piVar11[1] = 1;
                        }
                        puVar7 = (undefined4 *)piVar11[2];
                      }
                      piVar11 = (int *)*puVar7;
                      bVar2 = false;
                      puVar24 = (uint *)(piVar11 + 0x2e);
                      for (iVar16 = 1; iVar8 = (**(code **)(*piVar11 + 0x14))(piVar11),
                          iVar16 <= iVar8; iVar16 = iVar16 + 1) {
                        piVar25 = (int *)FUN_00105594(piVar11,iVar16);
                        if (piVar25 == piVar13) {
                          iVar8 = FUN_001054ec(piVar11,iVar16);
                          iVar8 = FUN_000f3190(*(undefined4 *)(iVar8 + 0x10));
                          if ((iVar8 == 0) || ((*puVar24 & 2) != 0)) {
                            bVar2 = true;
                          }
                          *piVar10 = iVar16;
                        }
                        puVar24 = puVar24 + 6;
                      }
                      if (bVar2) break;
                    }
                    uVar23 = piVar13[5];
LAB_0015b3f0:
                    if (((uVar23 & 0x200) == 0) &&
                       ((*(int *)(piVar13[0x22] + 8) == 0x12 ||
                        (*(int *)(piVar13[0x22] + 8) == 0x14)))) {
                      *piVar21 = (int)piVar13;
                    }
                    else {
                      *piVar19 = 0;
                    }
                    if ((*(uint *)(*piVar20 + 0x14) & 1) == 0) {
                      uVar22 = 1;
                      iVar16 = local_70;
                      break;
                    }
                    uVar22 = 1;
                  }
                }
              }
              iVar9 = iVar9 + 1;
              piVar19 = piVar19 + 1;
              piVar10 = piVar10 + 1;
              piVar21 = piVar21 + 1;
              iVar16 = local_70;
            } while (uVar17 - local_70 != iVar9);
          }
        }
        if ((int)uVar17 <= iVar16) {
          FUN_00193cc0(*(undefined4 *)(*(int *)(param_2 + 8) + 0x378),iVar5);
          FUN_00193cc0(*(undefined4 *)(*(int *)(param_2 + 8) + 0x378),iVar4);
          FUN_00193cc0(*(undefined4 *)(*(int *)(param_2 + 8) + 0x378),iVar3);
          return uVar22;
        }
      } while( true );
    }
  }
  return 0;
}

/* FUN_0015b4a4 @ 0x15b4a4 (1044 bytes) */
int FUN_0015b4a4(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  int iVar13;
  undefined4 local_48;
  undefined4 local_44 [6];
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x31) {
    iVar3 = FUN_001054ec(param_1,1);
    iVar3 = FUN_000f3190(*(undefined4 *)(iVar3 + 0x10));
    if (iVar3 == 0) {
      piVar4 = (int *)FUN_00105594(param_1,1);
      iVar3 = (**(code **)(*piVar4 + 0x5c))();
      if (((iVar3 == 0) && ((piVar4[5] & 0x200U) == 0)) &&
         ((iVar3 = FUN_0011379c(*(undefined4 *)(param_2 + 8),piVar4), iVar3 != 0 ||
          (iVar3 = FUN_001131c0(*(undefined4 *)(piVar4[0x22] + 8),*(undefined4 *)(param_2 + 8)),
          iVar3 != 0)))) {
        iVar3 = FUN_001054ec(param_1,1);
        uVar9 = 0;
        local_48 = *(undefined4 *)(iVar3 + 0x10);
        do {
          iVar3 = FUN_001054ec(param_1,0);
          if ((((*(char *)(uVar9 + iVar3 + 0x10) != '\x01') &&
               (uVar11 = (uint)*(byte *)((int)local_44 + (uVar9 - 4)), uVar11 != 4)) &&
              (uVar9 != uVar11)) &&
             (iVar3 = FUN_001054ec(piVar4,0), *(char *)(uVar11 + iVar3 + 0x10) != '\x01')) {
            return;
          }
          bVar1 = uVar9 != 3;
          uVar9 = uVar9 + 1;
        } while (bVar1);
        puVar12 = (uint *)piVar4[4];
        uVar11 = 0;
        uVar9 = puVar12[1];
        if (uVar9 != 0) {
          do {
            if (uVar11 < *puVar12) {
              if (uVar9 <= uVar11) {
                _memset((void *)(uVar9 * 4 + puVar12[2]),0,(uVar11 - uVar9) * 4 + 4);
                puVar12[1] = uVar11 + 1;
              }
              piVar5 = (int *)(uVar11 * 4 + puVar12[2]);
            }
            else {
              piVar5 = (int *)FUN_0019423c(puVar12,uVar11);
            }
            iVar3 = *piVar5;
            if (((*(uint *)(iVar3 + 0x14) & 0x200) != 0) &&
               (piVar5 = (int *)FUN_00105594(iVar3,*(undefined4 *)(iVar3 + 0x84)), piVar4 == piVar5)
               ) {
              return;
            }
            puVar12 = (uint *)piVar4[4];
            uVar11 = uVar11 + 1;
            uVar9 = puVar12[1];
          } while (uVar11 < uVar9);
        }
        local_44[0] = DAT_001b0050;
        *(int *)(param_2 + 0x164) = *(int *)(param_2 + 0x164) + 1;
        uVar9 = 0;
        FUN_001054ec(piVar4,0);
        piVar5 = piVar4;
        do {
          iVar3 = FUN_001054ec(param_1,0);
          if (*(char *)(uVar9 + iVar3 + 0x10) != '\x01') {
            bVar2 = *(byte *)((int)local_44 + (uVar9 - 4));
            uVar11 = (uint)bVar2;
            if ((uVar11 != 4) && (uVar11 != uVar9)) {
              iVar10 = 1;
              iVar3 = FUN_0011379c(*(undefined4 *)(param_2 + 8),piVar4);
              if (iVar3 != 0) {
                for (; iVar3 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar10 <= iVar3;
                    iVar10 = iVar10 + 1) {
                  iVar3 = FUN_001054ec(piVar4,iVar10);
                  (**(code **)(*piVar4 + 0x88))
                            (piVar4,iVar10,uVar9,*(undefined1 *)(uVar11 + iVar3 + 0x10));
                }
              }
              iVar3 = FUN_001054ec(piVar4,0);
              if (*(char *)(uVar9 + iVar3 + 0x10) != '\0') {
                *(undefined1 *)(piVar5 + 0x27) = 0;
              }
              *(byte *)((int)local_44 + uVar9) = bVar2;
            }
          }
          bVar1 = uVar9 != 3;
          piVar5 = (int *)((int)piVar5 + 1);
          uVar9 = uVar9 + 1;
        } while (bVar1);
        puVar12 = (uint *)piVar4[4];
        uVar11 = 0;
        uVar9 = puVar12[1];
        if (uVar9 != 0) {
          do {
            if (uVar11 < *puVar12) {
              if (uVar9 <= uVar11) {
                _memset((void *)(uVar9 * 4 + puVar12[2]),0,(uVar11 - uVar9) * 4 + 4);
                puVar12[1] = uVar11 + 1;
              }
              puVar6 = (undefined4 *)(uVar11 * 4 + puVar12[2]);
            }
            else {
              puVar6 = (undefined4 *)FUN_0019423c(puVar12,uVar11);
            }
            uVar11 = uVar11 + 1;
            piVar5 = (int *)*puVar6;
            for (iVar3 = 1; iVar10 = (**(code **)(*piVar5 + 0x14))(piVar5), iVar3 <= iVar10;
                iVar3 = iVar3 + 1) {
              piVar7 = (int *)FUN_00105594(piVar5,iVar3);
              if (piVar4 == piVar7) {
                iVar10 = 0;
                do {
                  iVar8 = FUN_001054ec(piVar5,iVar3);
                  iVar13 = 3;
                  if (*(char *)(iVar10 + iVar8 + 0x10) == *(char *)((int)local_44 + iVar10)) {
                    (**(code **)(*piVar5 + 0x88))(piVar5,iVar3,iVar10,iVar10);
                  }
                  else {
                    do {
                      iVar13 = iVar13 + -1;
                    } while (iVar13 != 0);
                  }
                  bVar1 = iVar10 != 3;
                  iVar10 = iVar10 + 1;
                } while (bVar1);
              }
            }
            puVar12 = (uint *)piVar4[4];
            uVar9 = puVar12[1];
          } while (uVar11 < uVar9);
        }
      }
    }
  }
  return;
}

/* FUN_0015b8b8 @ 0x15b8b8 (188 bytes) */
int FUN_0015b8b8(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  while( true ) {
    if (((iVar2 == 0) ||
        (((iVar1 = *(int *)(*(int *)(iVar2 + 0x88) + 8), iVar1 != 0x3a && (iVar1 != 0x3b)) ||
         ((*(uint *)(iVar2 + 0xb8) & 1) != 0)))) || (*(int *)(iVar2 + 0x120) != 0)) {
      return 0;
    }
    iVar1 = FUN_001054ec(iVar2,0);
    iVar1 = FUN_000f37b8(*(undefined4 *)(iVar1 + 0x10));
    if (iVar1 < 0) {
      return 0;
    }
    if (iVar1 == param_2) break;
    if ((*(uint *)(iVar2 + 0x14) & 0x200) == 0) {
      return 0;
    }
    iVar2 = FUN_00105594(iVar2,*(undefined4 *)(iVar2 + 0x84));
  }
  *param_1 = iVar2;
  return 1;
}

/* FUN_0015b974 @ 0x15b974 (972 bytes) */
int FUN_0015b974(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  uint *param_4;
  uint *param_5;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int *local_68;
  int *local_64;
  undefined1 auStack_60 [4];
  float local_5c;
  longlong local_48;
  undefined4 local_40;
  uint uStack_3c;
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x37) {
    iVar1 = FUN_001054ec(param_1,0);
    iVar1 = FUN_000f37b8(*(undefined4 *)(iVar1 + 0x10));
    if ((((-1 < iVar1) && (local_68 = (int *)FUN_00105594(param_1,1), local_68[0x48] == 0)) &&
        ((*(uint *)(param_1 + 0xb8) & 1) == 0)) && ((*(uint *)(param_1 + 0xb8) & 2) == 0)) {
      iVar1 = FUN_001054ec(param_1,1);
      uVar5 = (uint)*(byte *)(iVar1 + 0x13);
      iVar7 = *(int *)(local_68[0x22] + 8);
      iVar1 = ((int (*)())FUN_0015b8b8)(&local_68,uVar5);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*local_68 + 100))();
        if (iVar1 == 0) {
          if (iVar7 == 0x13) {
            if ((local_68[0x2e] & 1U) != 0) {
              return 0;
            }
            if ((local_68[0x2e] & 2U) != 0) {
              return 0;
            }
            if ((local_68[0x34] & 1U) != 0) {
              return 0;
            }
            if ((local_68[0x34] & 2U) != 0) {
              return 0;
            }
            local_64 = (int *)FUN_00105594(local_68,1);
            piVar3 = (int *)FUN_00105594(local_68,2);
            iVar1 = (**(code **)(*piVar3 + 0x48))();
            if (iVar1 == 0) {
              iVar1 = (**(code **)(*local_64 + 0x48))();
              if (iVar1 == 0) {
                return 0;
              }
              uVar2 = 2;
              uVar4 = 1;
              piVar6 = local_64;
              local_64 = piVar3;
            }
            else {
              uVar2 = 1;
              uVar4 = 2;
              piVar6 = piVar3;
            }
            iVar1 = FUN_001054ec(local_68,uVar2);
            iVar1 = ((int (*)())FUN_0015b8b8)(&local_64,*(undefined1 *)(uVar5 + iVar1 + 0x10));
            piVar3 = local_68;
            if (iVar1 == 0) {
              return 0;
            }
            iVar1 = FUN_001054ec(local_68,0);
            iVar1 = FUN_000f5cf0(piVar3,uVar4,*(undefined4 *)(iVar1 + 0x10),auStack_60);
            if (iVar1 == 0) {
              *param_3 = piVar6;
            }
            else {
              local_40 = 0x43300000;
              uVar5 = (uint)local_5c;
              local_48 = (longlong)(int)uVar5;
              uStack_3c = uVar5 ^ 0x80000000;
              if (local_5c != (float)((double)CONCAT44(0x43300000,uStack_3c) - DOUBLE_001aa1e0)) {
                return 0;
              }
              *param_4 = uVar5;
              *param_3 = 0;
            }
            uVar2 = FUN_00105594(local_64,1);
            *param_2 = uVar2;
            piVar3 = local_64;
            goto LAB_0015bc04;
          }
          if ((iVar7 != 0x12) && (iVar7 != 0x9b)) {
            return 0;
          }
          local_64 = (int *)FUN_00105594(local_68,1);
          piVar3 = (int *)FUN_00105594(local_68,2);
          if (piVar3 != local_64) {
            return 0;
          }
          if ((local_68[0x2e] & 1U) != 0) {
            return 0;
          }
          if ((local_68[0x2e] & 2U) != 0) {
            return 0;
          }
          if ((local_68[0x34] & 1U) != 0) {
            return 0;
          }
          if ((local_68[0x34] & 2U) != 0) {
            return 0;
          }
          iVar1 = FUN_001054ec(local_68,1);
          iVar7 = *(int *)(iVar1 + 0x10);
          iVar1 = FUN_001054ec(local_68,2);
          if (iVar7 != *(int *)(iVar1 + 0x10)) {
            return 0;
          }
          iVar1 = FUN_001054ec(local_68,1);
          iVar1 = ((int (*)())FUN_0015b8b8)(&local_64,*(undefined1 *)(uVar5 + iVar1 + 0x10));
          if (iVar1 == 0) {
            return 0;
          }
          uVar5 = 2;
        }
        else {
          local_64 = (int *)FUN_00105594(local_68,1);
          if ((local_68[0x2e] & 1U) != 0) {
            return 0;
          }
          if ((local_68[0x2e] & 2U) != 0) {
            return 0;
          }
          iVar1 = ((int (*)())FUN_0015b8b8)(&local_64,uVar5);
          if (iVar1 == 0) {
            return 0;
          }
          uVar5 = 1 << (local_64[0x49] + local_68[0x49] & 0x3fU);
        }
        *param_4 = uVar5;
        *param_3 = 0;
        uVar2 = FUN_00105594(local_64,1);
        *param_2 = uVar2;
        piVar3 = local_64;
      }
      else {
        *param_4 = 1 << (local_68[0x49] & 0x3fU);
        *param_3 = 0;
        uVar2 = FUN_00105594(local_68,1);
        *param_2 = uVar2;
        piVar3 = local_68;
      }
LAB_0015bc04:
      iVar1 = FUN_001054ec(piVar3,1);
      *param_5 = (uint)*(byte *)(iVar1 + 0x13);
      return 1;
    }
  }
  return 0;
}

/* FUN_0015bd40 @ 0x15bd40 (2452 bytes) */
int FUN_0015bd40(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int *piVar18;
  int *piVar19;
  int *piVar20;
  uint uVar21;
  uint uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  uint uVar26;
  int *piVar27;
  double dVar28;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
  undefined4 local_58;
  
  if ((*(uint *)(param_1 + 0x14) & 0x200) == 0) {
    return 0;
  }
  iVar11 = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84));
  if (iVar11 == 0) {
    return 0;
  }
  if ((*(uint *)(*(int *)(*(int *)(param_2 + 8) + 0x30c) + 8) & 0x100) == 0) {
    return 0;
  }
  iVar7 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  iVar9 = *(int *)(*(int *)(iVar11 + 0x88) + 8);
  if (iVar7 == 0x12) {
    iVar7 = iVar11;
    iVar17 = param_1;
    if (iVar9 != 0x14) {
      return 0;
    }
  }
  else {
    if (iVar7 != 0x14) {
      return 0;
    }
    iVar7 = param_1;
    iVar17 = iVar11;
    if (iVar9 != 0x12) {
      return 0;
    }
  }
  if (*(int *)(iVar17 + 0x120) != *(int *)(iVar7 + 0x120)) {
    return 0;
  }
  if (*(int *)(iVar17 + 0x124) != *(int *)(iVar7 + 0x124)) {
    return 0;
  }
  iVar9 = FUN_001054ec(iVar17,0);
  local_80 = *(undefined4 *)(iVar9 + 0x10);
  iVar12 = FUN_001054ec(iVar7,0);
  iVar9 = 0;
  local_84 = *(undefined4 *)(iVar12 + 0x10);
  iVar12 = 4;
  do {
    if ((*(char *)((int)&local_80 + iVar9) != '\x01') &&
       (*(char *)((int)&local_84 + iVar9) != '\x01')) {
      return 0;
    }
    iVar9 = iVar9 + 1;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  piVar13 = (int *)FUN_00105594(iVar17,1);
  iVar9 = (**(code **)(*piVar13 + 0x60))();
  if (iVar9 != 0) {
    return 0;
  }
  piVar13 = (int *)FUN_00105594(iVar17,2);
  iVar9 = (**(code **)(*piVar13 + 0x60))();
  if (iVar9 != 0) {
    return 0;
  }
  iVar9 = FUN_001466f4(iVar17,1);
  iVar12 = FUN_001466f4(iVar17,2);
  iVar14 = FUN_001466f4(iVar7,1);
  iVar15 = FUN_001466f4(iVar7,2);
  iVar16 = FUN_001466f4(iVar7,3);
  uVar2 = *(uint *)(iVar7 + 0xd0) & 1;
  uVar3 = *(uint *)(iVar7 + 0xe8) & 1;
  uVar4 = *(uint *)(iVar7 + 0xb8) & 1;
  uVar26 = *(uint *)(iVar7 + 0xd0) >> 1 & 1;
  uVar21 = *(uint *)(iVar7 + 0xe8) >> 1 & 1;
  uVar5 = *(uint *)(iVar17 + 0xb8) & 1;
  uVar6 = *(uint *)(iVar17 + 0xd0) & 1;
  uVar8 = *(uint *)(iVar7 + 0xb8) >> 1 & 1;
  uVar22 = *(uint *)(iVar17 + 0xb8) >> 1 & 1;
  uVar10 = *(uint *)(iVar17 + 0xd0) >> 1 & 1;
  if ((((iVar9 == iVar14) && (iVar12 == iVar16)) && (uVar8 == uVar22)) &&
     ((uVar21 == uVar10 && (uVar3 == uVar6)))) {
    if (uVar2 == 0) {
      if (uVar4 != uVar5) goto LAB_0015bf6c;
    }
    else if (uVar4 == uVar5) goto LAB_0015bf6c;
    uVar23 = 1;
    uVar24 = 3;
    uVar25 = 2;
    goto LAB_0015c078;
  }
LAB_0015bf6c:
  if (((iVar9 == iVar15) && (iVar12 == iVar16)) &&
     ((uVar26 == uVar22 && ((uVar21 == uVar10 && (uVar3 == uVar6)))))) {
    if (uVar4 == 0) {
      if (uVar2 != uVar5) goto LAB_0015bfb0;
    }
    else if (uVar2 == uVar5) goto LAB_0015bfb0;
    uVar23 = 2;
    uVar24 = 3;
    uVar25 = 1;
    goto LAB_0015c078;
  }
LAB_0015bfb0:
  if ((((iVar12 == iVar14) && (iVar9 == iVar16)) && (uVar8 == uVar10)) &&
     ((uVar21 == uVar22 && (uVar3 == uVar5)))) {
    if (uVar2 == 0) {
      if (uVar4 != uVar6) goto LAB_0015bff4;
    }
    else if (uVar4 == uVar6) goto LAB_0015bff4;
    uVar23 = 3;
    uVar24 = 1;
    uVar25 = 2;
  }
  else {
LAB_0015bff4:
    if (iVar12 != iVar15) {
      return 0;
    }
    if (iVar9 != iVar16) {
      return 0;
    }
    if (uVar26 != uVar10) {
      return 0;
    }
    if (uVar21 != uVar22) {
      return 0;
    }
    if (uVar3 != uVar5) {
      return 0;
    }
    if (uVar4 == 0) {
      if (uVar2 != uVar6) {
        return 0;
      }
    }
    else if (uVar2 == uVar6) {
      return 0;
    }
    uVar23 = 3;
    uVar24 = 2;
    uVar25 = 1;
  }
LAB_0015c078:
  local_58 = 0;
  local_6c = 0;
  local_68 = 0;
  if ((*(uint *)(iVar11 + 0x14) & 0x200) != 0) {
    FUN_00104d3c(iVar11,&local_6c);
  }
  iVar9 = *(int *)(iVar17 + 0x160) - *(int *)(param_2 + 0x478);
  if (iVar9 < 0) {
    iVar9 = 0;
  }
  if (iVar17 == param_1) {
    iVar12 = FUN_001054ec(iVar17,0);
    local_7c = *(int *)(iVar12 + 0x10);
    iVar12 = FUN_001054ec(iVar17,1);
    local_78 = *(undefined4 *)(iVar12 + 0x10);
    iVar12 = FUN_001054ec(iVar17,2);
    local_74 = *(undefined4 *)(iVar12 + 0x10);
    iVar12 = FUN_001054ec(iVar7,uVar25);
    local_70 = *(undefined4 *)(iVar12 + 0x10);
    iVar14 = 4;
    local_88 = local_7c;
    iVar12 = 0;
    do {
      if (*(char *)((int)&local_84 + iVar12) != '\x01') {
        *(char *)((int)&local_88 + iVar12) = *(char *)((int)&local_84 + iVar12);
      }
      iVar12 = iVar12 + 1;
      iVar14 = iVar14 + -1;
    } while (iVar14 != 0);
    iVar12 = FUN_00105594(iVar17,1);
    *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + -1;
    iVar12 = FUN_00105594(iVar17,2);
    iVar14 = *(int *)(iVar17 + 4);
    *(int *)(iVar12 + 0x160) = *(int *)(iVar12 + 0x160) + -1;
    FUN_0019401c(iVar17);
    piVar13 = (int *)FUN_00103ebc(iVar7,iVar17,*(undefined4 *)(param_2 + 8),0);
    FUN_000e7738(*(undefined4 *)(iVar14 + 0x158),iVar14,piVar13);
    iVar12 = piVar13[0x53];
    piVar13[0x27] = local_88;
    iVar17 = FUN_001054ec(piVar13,0);
    *(int *)(iVar17 + 8) = iVar12;
    piVar18 = (int *)FUN_00105594(iVar7,uVar23);
    piVar19 = (int *)FUN_00105594(iVar7,uVar24);
    piVar20 = (int *)FUN_00105594(iVar7,uVar25);
    iVar7 = (**(code **)(*piVar20 + 0x60))();
    if (iVar7 == 0) {
      piVar20 = (int *)FUN_0010a240(0xa2,*(undefined4 *)(param_2 + 8));
      FUN_000e7700(piVar13[0x56],piVar13,piVar20);
      piVar20[0x21] = 1;
      piVar20[0x25] = piVar20[0x53];
      piVar20[0x26] = 0x36;
      piVar20[0x27] = local_88;
      iVar7 = FUN_00105594(piVar13,uVar25);
      FUN_00106004(piVar20,1,iVar7,0,*(undefined4 *)(param_2 + 8));
      if (*(int *)(param_2 + 0x478) < *(int *)(iVar7 + 0x160)) {
        *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
      }
      else {
        *(int *)(iVar7 + 0x160) = *(int *)(param_2 + 0x478) + 1;
      }
      iVar7 = 0;
      do {
        if (*(char *)((int)&local_84 + iVar7) != '\x01') {
          (**(code **)(*piVar20 + 0x88))(piVar20,1,iVar7,*(undefined1 *)((int)&local_70 + iVar7));
          (**(code **)(*piVar13 + 0x88))(piVar13,uVar25,iVar7,iVar7);
        }
        bVar1 = iVar7 != 3;
        iVar7 = iVar7 + 1;
      } while (bVar1);
      dVar28 = (double)FLOAT_001aa0e8;
      piVar20[0x21] = 2;
      iVar7 = 0;
      FUN_000f79c4(dVar28,dVar28,dVar28,dVar28,piVar20,param_2,2);
      do {
        if (*(char *)((int)&local_7c + iVar7) != '\x01') {
          (**(code **)(*piVar20 + 0x88))(piVar20,1,iVar7,4);
          (**(code **)(*piVar20 + 0x88))(piVar20,2,iVar7,iVar7);
        }
        bVar1 = iVar7 != 3;
        iVar7 = iVar7 + 1;
      } while (bVar1);
      FUN_00106004(piVar13,uVar25,piVar20,0,*(undefined4 *)(param_2 + 8));
      piVar20[0x58] = *(int *)(param_2 + 0x478) + 1;
    }
    else {
      iVar17 = piVar20[0x21];
      iVar7 = 0;
      piVar27 = piVar20;
      do {
        if (*(char *)((int)&local_7c + iVar7) != '\x01') {
          iVar17 = iVar17 + 1;
          dVar28 = (double)FLOAT_001aa0e8;
          piVar20[0x21] = iVar17;
          FUN_000f79c4(dVar28,dVar28,dVar28,dVar28,piVar20,param_2,iVar17);
          (**(code **)(*piVar20 + 0x88))(piVar20,iVar17,iVar7,iVar7);
          *(undefined1 *)(piVar27 + 0x27) = 0;
        }
        bVar1 = iVar7 != 3;
        piVar27 = (int *)((int)piVar27 + 1);
        iVar7 = iVar7 + 1;
      } while (bVar1);
      if (*(int *)(param_2 + 0x478) < piVar20[0x58]) {
        piVar20[0x58] = piVar20[0x58] + 1;
      }
      else {
        piVar20[0x58] = *(int *)(param_2 + 0x478) + 1;
      }
    }
    iVar7 = 0;
    do {
      if (*(char *)((int)&local_7c + iVar7) != '\x01') {
        iVar17 = (**(code **)(*piVar18 + 0x60))(piVar18);
        if (iVar17 == 0) {
          (**(code **)(*piVar13 + 0x88))
                    (piVar13,uVar23,iVar7,*(undefined1 *)((int)&local_78 + iVar7));
        }
        else {
          iVar17 = FUN_001054ec(piVar18,0);
          iVar17 = FUN_000f3108(*(undefined4 *)(iVar17 + 0x10));
          (**(code **)(*piVar18 + 0x88))(piVar18,1,iVar17,*(undefined1 *)((int)&local_78 + iVar7));
          (**(code **)(*piVar13 + 0x88))(piVar13,uVar23,iVar7,iVar17);
          *(undefined1 *)((int)piVar18 + iVar17 + 0x9c) = 0;
        }
        iVar17 = (**(code **)(*piVar19 + 0x60))(piVar19);
        if (iVar17 == 0) {
          (**(code **)(*piVar13 + 0x88))
                    (piVar13,uVar24,iVar7,*(undefined1 *)((int)&local_74 + iVar7));
        }
        else {
          iVar17 = FUN_001054ec(piVar19,0);
          iVar17 = FUN_000f3108(*(undefined4 *)(iVar17 + 0x10));
          (**(code **)(*piVar19 + 0x88))(piVar19,1,iVar17,*(undefined1 *)((int)&local_74 + iVar7));
          (**(code **)(*piVar13 + 0x88))(piVar13,uVar24,iVar7,iVar17);
          *(undefined1 *)((int)piVar19 + iVar17 + 0x9c) = 0;
        }
        (**(code **)(*piVar13 + 0x88))(piVar13,uVar25,iVar7,iVar7);
      }
      bVar1 = iVar7 != 3;
      iVar7 = iVar7 + 1;
    } while (bVar1);
    if (*(int *)(param_2 + 0x478) < piVar18[0x58]) {
      piVar18[0x58] = piVar18[0x58] + 1;
    }
    else {
      piVar18[0x58] = *(int *)(param_2 + 0x478) + 1;
    }
    if (*(int *)(param_2 + 0x478) < piVar19[0x58]) {
      piVar19[0x58] = piVar19[0x58] + 1;
    }
    else {
      piVar19[0x58] = *(int *)(param_2 + 0x478) + 1;
    }
    if (local_68 != 0) {
      FUN_00106b48(piVar13,&local_6c,0,*(undefined4 *)(param_2 + 8));
      if (*(int *)(param_2 + 0x478) < *(int *)(local_68 + 0x160)) {
        *(int *)(local_68 + 0x160) = *(int *)(local_68 + 0x160) + 1;
      }
      else {
        *(int *)(local_68 + 0x160) = *(int *)(param_2 + 0x478) + 1;
      }
    }
    piVar13[0x58] = iVar9 + *(int *)(param_2 + 0x478);
    FUN_00105894(iVar11,*(undefined4 *)(param_2 + 8));
  }
  return 0;
}

/* FUN_0015c6d4 @ 0x15c6d4 (2012 bytes) */
int FUN_0015c6d4(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  float fVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint *puVar18;
  double dVar19;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 auStack_78 [4];
  float local_74;
  
  if ((param_1[5] & 0x200U) == 0) {
    return 0;
  }
  iVar5 = FUN_00105594(param_1,param_1[0x21]);
  if (iVar5 == 0) {
    return 0;
  }
  if ((*(uint *)(*(int *)(*(int *)(param_2 + 8) + 0x30c) + 8) & 0x100) == 0) {
    return 0;
  }
  iVar15 = *(int *)(param_1[0x22] + 8);
  if (2 < iVar15 - 0x12U) {
    return 0;
  }
  if (param_1[0x48] != 0) {
    return 0;
  }
  uVar17 = 1;
  if (param_1[0x49] != 0) {
    return 0;
  }
LAB_0015c82c:
  iVar6 = (**(code **)(*param_1 + 0x14))(param_1);
  if (iVar6 < (int)uVar17) {
    return 0;
  }
  iVar6 = FUN_00105594(param_1,uVar17);
  if ((iVar6 == iVar5) && ((param_1[uVar17 * 6 + 0x28] & 2U) == 0)) {
    if (iVar15 == 0x12) {
      if ((param_1[uVar17 * 6 + 0x28] & 1U) == 0) {
        uVar11 = uVar17 ^ 3;
        uVar13 = 0xffffffff;
LAB_0015c79c:
        if ((int)uVar17 < 0) {
          return 0;
        }
        uVar12 = 0xffffffff;
LAB_0015c880:
        iVar5 = FUN_001054ec(param_1,0);
        local_88 = *(int *)(iVar5 + 0x10);
        iVar5 = FUN_001054ec(param_1,uVar17);
        local_84 = *(undefined4 *)(iVar5 + 0x10);
        iVar5 = (**(code **)(*param_1 + 0x14))(param_1);
        iVar5 = FUN_001054ec(param_1,iVar5 + 1);
        local_80 = *(undefined4 *)(iVar5 + 0x10);
        iVar5 = FUN_000e07dc(*(undefined4 *)(param_2 + 8),0x30);
        if (iVar5 != 0) {
          if ((char)local_88 == '\0') {
            return 0;
          }
          if ((char)local_80 != '\x04') {
            return 0;
          }
        }
        iVar5 = 0;
        iVar15 = 4;
        do {
          if (*(char *)((int)&local_88 + iVar5) == '\0') {
            if (*(char *)((int)&local_80 + iVar5) != '\x04') {
              return 0;
            }
          }
          else if (*(char *)((int)&local_80 + iVar5) != '\x04') {
            *(undefined1 *)((int)&local_88 + iVar5) = 0;
            *(char *)((int)&local_84 + iVar5) = (char)iVar5;
          }
          uVar14 = local_84;
          iVar5 = iVar5 + 1;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
        iVar5 = FUN_001054ec(param_1,uVar17);
        *(undefined4 *)(iVar5 + 0x10) = uVar14;
        param_1[0x27] = local_88;
        iVar5 = FUN_00105594(param_1,uVar17);
        *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + -1;
        uVar14 = *(undefined4 *)(param_2 + 8);
        uVar17 = *(uint *)(param_2 + 0x30) >> 7 & 1;
        if (uVar17 != 0) {
          iVar5 = FUN_00105594(param_1,param_1[0x21]);
          puVar18 = *(uint **)(iVar5 + 0x10);
          uVar7 = puVar18[1];
          if (0 < (int)uVar7) {
            uVar16 = 0;
            do {
              if (uVar16 < *puVar18) {
                if (uVar7 <= uVar16) {
                  _memset((void *)(uVar7 * 4 + puVar18[2]),0,(uVar16 - uVar7) * 4 + 4);
                  puVar18[1] = uVar16 + 1;
                }
                piVar8 = (int *)(uVar16 * 4 + puVar18[2]);
              }
              else {
                piVar8 = (int *)FUN_0019423c(puVar18,uVar16);
              }
              if (param_1 == (int *)*piVar8) {
                FUN_00194208(puVar18,uVar16);
                iVar5 = FUN_00105594(param_1,param_1[0x21]);
                *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + -1;
                break;
              }
              uVar7 = puVar18[1];
              uVar16 = uVar16 + 1;
            } while ((int)uVar16 < (int)uVar7);
          }
        }
        uVar7 = 1;
        FUN_00106004(param_1,param_1[0x21],0,uVar17,uVar14);
        param_1[0x21] = param_1[0x21] + -1;
        param_1[5] = param_1[5] & 0xfffffdff;
        do {
          iVar5 = (**(code **)(*param_1 + 0x14))(param_1);
          if (iVar5 < (int)uVar7) {
            return 0;
          }
          fVar3 = FLOAT_001aa0e8;
          if (((uVar7 == uVar13) || (fVar3 = FLOAT_001aa0d4, uVar7 == uVar11)) || (uVar7 == uVar12))
          {
            dVar19 = (double)fVar3;
            piVar8 = (int *)FUN_00105594(param_1,uVar7);
            iVar5 = FUN_001054ec(param_1,uVar7);
            local_7c = *(undefined4 *)(iVar5 + 0x10);
            iVar5 = (**(code **)(*piVar8 + 0x60))(piVar8);
            if (iVar5 == 0) {
              iVar5 = 0;
              piVar9 = (int *)FUN_0010a240(0xa2,*(undefined4 *)(param_2 + 8));
              FUN_000e7700(param_1[0x56],param_1,piVar9);
              piVar9[0x21] = 1;
              piVar9[0x25] = piVar9[0x53];
              piVar9[0x26] = 0x36;
              piVar9[0x27] = local_88;
              FUN_00106004(piVar9,1,piVar8,0,*(undefined4 *)(param_2 + 8));
              piVar9[0x21] = 2;
              FUN_000f79c4(dVar19,dVar19,dVar19,dVar19,piVar9,param_2,2);
              do {
                if (*(char *)((int)&local_88 + iVar5) != '\x01') {
                  if (*(char *)((int)&local_80 + iVar5) == '\x04') {
                    (**(code **)(*piVar9 + 0x88))(piVar9,1,iVar5,auStack_78[iVar5 + -4]);
                    uVar14 = 2;
                    pcVar4 = *(code **)(*piVar9 + 0x88);
                  }
                  else {
                    (**(code **)(*piVar9 + 0x88))(piVar9,2,iVar5,iVar5);
                    uVar14 = 1;
                    pcVar4 = *(code **)(*piVar9 + 0x88);
                  }
                  (*pcVar4)(piVar9,uVar14,iVar5,4);
                  (**(code **)(*param_1 + 0x88))(param_1,uVar7,iVar5,iVar5);
                }
                bVar1 = iVar5 != 3;
                iVar5 = iVar5 + 1;
              } while (bVar1);
              FUN_00106004(param_1,uVar7,piVar9,0,*(undefined4 *)(param_2 + 8));
              piVar9[0x58] = *(int *)(param_2 + 0x478) + 1;
            }
            else {
              iVar5 = FUN_0010497c(piVar8,param_2);
              if (iVar5 == 0) {
                piVar8 = (int *)FUN_0010445c(piVar8,*(undefined4 *)(param_2 + 8),0);
                FUN_000e7700(param_1[0x56],param_1,piVar8);
                piVar8[0x58] = *(int *)(param_2 + 0x478) + 1;
              }
              iVar5 = piVar8[0x21];
              if (1 < iVar5) {
                bVar1 = false;
                iVar15 = 2;
                do {
                  iVar5 = FUN_001054ec(piVar8,0);
                  iVar5 = FUN_000f5cf0(piVar8,iVar15,*(undefined4 *)(iVar5 + 0x10),auStack_78);
                  if ((iVar5 != 0) && (dVar19 == (double)local_74)) {
                    iVar5 = -1;
                    iVar6 = 0;
                    do {
                      iVar10 = FUN_001054ec(piVar8,iVar15);
                      if (*(char *)(iVar6 + iVar10 + 0x10) != '\x04') {
                        iVar5 = iVar6;
                      }
                      bVar2 = iVar6 != 3;
                      iVar6 = iVar6 + 1;
                    } while (bVar2);
                    iVar6 = 0;
                    do {
                      if (*(char *)((int)&local_80 + iVar6) != '\x04') {
                        bVar1 = true;
                        (**(code **)(*param_1 + 0x88))(param_1,uVar7,iVar6,iVar5);
                      }
                      bVar2 = iVar6 != 3;
                      iVar6 = iVar6 + 1;
                    } while (bVar2);
                    if (bVar1) goto LAB_0015ce60;
                  }
                  iVar5 = piVar8[0x21];
                  iVar15 = iVar15 + 1;
                } while (iVar15 <= iVar5);
                if (bVar1) goto LAB_0015ce60;
              }
              iVar5 = iVar5 + 1;
              piVar8[0x21] = iVar5;
              FUN_000f79c4(dVar19,dVar19,dVar19,dVar19,piVar8,param_2,iVar5);
              uVar14 = DAT_001b0050;
              iVar15 = FUN_001054ec(piVar8,iVar5);
              *(undefined4 *)(iVar15 + 0x10) = uVar14;
              iVar15 = 0;
              do {
                iVar6 = FUN_001054ec(piVar8,0);
                if (*(char *)(iVar15 + iVar6 + 0x10) != '\0') {
                  (**(code **)(*piVar8 + 0x88))(piVar8,iVar5,iVar15,iVar15);
                  *(undefined1 *)((int)piVar8 + iVar15 + 0x9c) = 0;
                  goto LAB_0015ce20;
                }
                bVar1 = iVar15 != 3;
                iVar15 = iVar15 + 1;
              } while (bVar1);
              iVar15 = -1;
LAB_0015ce20:
              iVar5 = 0;
              do {
                if (*(char *)((int)&local_80 + iVar5) != '\x04') {
                  (**(code **)(*param_1 + 0x88))(param_1,uVar7,iVar5,iVar15);
                }
                bVar1 = iVar5 != 3;
                iVar5 = iVar5 + 1;
              } while (bVar1);
            }
          }
LAB_0015ce60:
          uVar7 = uVar7 + 1;
        } while( true );
      }
    }
    else if (iVar15 == 0x13) {
      if ((param_1[0x2e] & 1U) == (param_1[0x34] & 1U)) {
        uVar13 = uVar17 ^ 3;
        uVar11 = 0xffffffff;
        goto LAB_0015c79c;
      }
    }
    else if (iVar15 == 0x14) {
      if (uVar17 == 3) {
        if ((param_1[0x3a] & 1U) == 0) {
          uVar17 = 3;
          uVar11 = 1;
          uVar12 = 2;
          uVar13 = 0xffffffff;
          goto LAB_0015c880;
        }
      }
      else if (((int)uVar17 < 3) && ((param_1[0x2e] & 1U) == (param_1[0x34] & 1U))) {
        uVar13 = uVar17 ^ 3;
        uVar11 = 3;
        goto LAB_0015c79c;
      }
    }
  }
  uVar17 = uVar17 + 1;
  goto LAB_0015c82c;
}

/* FUN_0015ceb0 @ 0x15ceb0 (4236 bytes) */
int FUN_0015ceb0(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int *piVar24;
  int iVar25;
  int iVar26;
  double dVar27;
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4 [3];
  int local_e8 [5];
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_8c;
  undefined4 local_88;
  int local_84;
  undefined4 local_74;
  int local_68;
  int *local_64;
  undefined *local_60;
  
  if ((param_1[5] & 0x200U) == 0) {
    return 0;
  }
  piVar7 = (int *)FUN_00105594(param_1,param_1[0x21]);
  if (piVar7 == (int *)0x0) {
    return 0;
  }
  if ((*(uint *)(*(int *)(*(int *)(param_2 + 8) + 0x30c) + 8) & 0x100) == 0) {
    return 0;
  }
  iVar25 = *(int *)(piVar7[0x22] + 8);
  if (*(int *)(param_1[0x22] + 8) == 0x12) {
    if (iVar25 == 0x12) {
      piVar9 = (int *)FUN_00105594(param_1,1);
      piVar10 = (int *)FUN_00105594(param_1,2);
      piVar11 = (int *)FUN_00105594(piVar7,1);
      piVar16 = (int *)FUN_00105594(piVar7,2);
      bVar1 = piVar9 == piVar16;
      if (bVar1) {
        bVar1 = piVar10 == piVar11;
        FUN_0010ac38(piVar7,1,2,*(undefined4 *)(param_2 + 8));
        bVar4 = true;
        bVar3 = false;
        piVar24 = piVar9;
        piVar16 = piVar11;
      }
      else {
        piVar24 = piVar10;
        if (piVar10 == piVar11) {
          FUN_0010ac38(param_1,1,2,*(undefined4 *)(param_2 + 8));
          bVar4 = false;
          bVar3 = true;
          piVar10 = piVar9;
        }
        else {
          bVar1 = piVar10 == piVar16;
          if (bVar1) {
            bVar1 = piVar9 == piVar11;
            FUN_0010ac38(piVar7,1,2,*(undefined4 *)(param_2 + 8));
            FUN_0010ac38(param_1,1,2,*(undefined4 *)(param_2 + 8));
            bVar4 = true;
            bVar3 = true;
            piVar16 = piVar11;
            piVar10 = piVar9;
          }
          else {
            if (piVar9 != piVar11) {
              return 0;
            }
            bVar4 = false;
            bVar3 = false;
            piVar24 = piVar11;
          }
        }
      }
      iVar25 = FUN_001054ec(param_1,0);
      local_fc = *(int *)(iVar25 + 0x10);
      iVar25 = FUN_001054ec(piVar7,0);
      local_100 = *(int *)(iVar25 + 0x10);
      if ((((!bVar1) && (piVar7[0x49] == param_1[0x49])) && (piVar7[0x48] == param_1[0x48])) &&
         ((local_fc != DAT_001b0054 && (DAT_001b0054 != *(int *)(iVar25 + 0x10))))) {
        iVar8 = 4;
        local_64 = &local_100;
        iVar25 = 0;
        do {
          if ((*(char *)(iVar25 + (int)&local_100) != '\x01') &&
             (*(char *)((int)&local_fc + iVar25) != '\x01')) goto LAB_0015d1a4;
          iVar25 = iVar25 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        if (((((piVar7[0x2e] & 1U) == (param_1[0x2e] & 1U)) &&
             ((piVar7[0x34] & 1U) == (param_1[0x34] & 1U))) &&
            (((uint)piVar7[0x2e] >> 1 & 1) == ((uint)param_1[0x2e] >> 1 & 1))) &&
           (iVar25 = FUN_00146de0(piVar16,piVar10), iVar25 == 0)) {
          *(int *)(param_2 + 0x280) = *(int *)(param_2 + 0x280) + 1;
          FUN_000f2f84(&local_68,local_100,local_fc);
          local_104 = local_68;
          piVar10 = (int *)((int (*)())FUN_0010bed0)((double)FLOAT_001aa0e8,2,local_68,piVar10,param_2,
                                        *(undefined4 *)(param_2 + 8));
          if (*(int *)(param_2 + 0x478) < piVar16[0x58]) {
            piVar16[0x58] = piVar16[0x58] + 1;
          }
          else {
            piVar16[0x58] = *(int *)(param_2 + 0x478) + 1;
          }
          piVar16 = (int *)((int (*)())FUN_0010bed0)((double)FLOAT_001aa0e8,2,local_104,piVar16,param_2,
                                        *(undefined4 *)(param_2 + 8));
          iVar25 = FUN_001054ec(param_1,2);
          uVar13 = *(undefined4 *)(iVar25 + 0x10);
          iVar25 = FUN_001054ec(piVar10,1);
          *(undefined4 *)(iVar25 + 0x10) = uVar13;
          iVar25 = FUN_001054ec(piVar7,2);
          uVar13 = *(undefined4 *)(iVar25 + 0x10);
          iVar25 = FUN_001054ec(piVar16,1);
          *(undefined4 *)(iVar25 + 0x10) = uVar13;
          local_a0 = 0;
          local_9c = 0;
          local_8c = 0;
          local_e8[0] = 0;
          local_e8[1] = 0;
          local_d4 = 0;
          local_b8 = 0;
          local_b4 = 0;
          local_a4 = 0;
          local_d0 = 0;
          local_cc = 0;
          local_bc = 0;
          uVar13 = FUN_001054ec(piVar7,1);
          FUN_00104730(&local_a0,uVar13);
          uVar13 = FUN_001054ec(piVar7,2);
          FUN_00104730(local_e8,uVar13);
          uVar13 = FUN_001054ec(param_1,1);
          FUN_00104730(&local_b8,uVar13);
          uVar13 = FUN_001054ec(param_1,2);
          FUN_00104730(&local_d0,uVar13);
          iVar25 = FUN_001054ec(param_1,1);
          local_f8 = *(int *)(iVar25 + 0x10);
          iVar25 = FUN_001054ec(piVar7,1);
          local_108 = *(int *)(iVar25 + 0x10);
          local_f4[0] = 0;
          local_f4[1] = 0;
          local_f4[2] = 0;
          FUN_00103f18(param_1,local_f4,0xffffffff);
          local_88 = 0;
          local_84 = 0;
          local_74 = 0;
          if ((piVar7[5] & 0x200U) != 0) {
            FUN_00104d3c(piVar7,&local_88);
          }
          iVar25 = param_1[1];
          FUN_0019401c(param_1);
          FUN_00108304(param_1,0x14,*(undefined4 *)(param_2 + 8));
          FUN_000e7738(*(undefined4 *)(iVar25 + 0x158),iVar25,param_1);
          FUN_00103f44(param_1,local_f4);
          iVar25 = piVar7[0x49];
          param_1[0x48] = piVar7[0x48];
          param_1[0x49] = iVar25;
          uVar13 = FUN_001054ec(param_1,3);
          FUN_00104730(uVar13,&local_b8);
          uVar13 = FUN_001054ec(param_1,1);
          FUN_00104730(uVar13,&local_d0);
          uVar13 = FUN_001054ec(param_1,2);
          FUN_00104730(uVar13,local_e8);
          FUN_00106004(param_1,1,piVar10,0,*(undefined4 *)(param_2 + 8));
          FUN_00106004(param_1,2,piVar16,0,*(undefined4 *)(param_2 + 8));
          FUN_00103d50(param_1 + 0x29,1,0);
          param_1[0x26] = 0;
          iVar25 = 0;
          param_1[0x25] = param_1[0x53];
          param_1[0x27] = local_104;
          do {
            if (*(char *)((int)&local_104 + iVar25) == '\0') {
              (**(code **)(*param_1 + 0x88))(param_1,1,iVar25,iVar25);
              (**(code **)(*param_1 + 0x88))(param_1,2,iVar25,iVar25);
              iVar8 = FUN_001054ec(piVar16,1);
              cVar2 = *(char *)(iVar25 + iVar8 + 0x10);
              iVar8 = FUN_001054ec(piVar10,1);
              if (cVar2 == '\x04') {
                if (*(char *)(iVar25 + iVar8 + 0x10) == '\x04') goto LAB_0015d5cc;
                (**(code **)(*piVar16 + 0x88))(piVar16,2,iVar25,iVar25);
                piVar9 = &local_f8;
                pcVar5 = *(code **)(*param_1 + 0x88);
              }
              else {
                (**(code **)(*piVar10 + 0x88))(piVar10,2,iVar25,iVar25);
                piVar9 = &local_108;
                pcVar5 = *(code **)(*param_1 + 0x88);
              }
              (*pcVar5)(param_1,3,iVar25,*(undefined1 *)(iVar25 + (int)piVar9));
            }
            else {
              (**(code **)(*param_1 + 0x88))(param_1,1,iVar25,4);
              (**(code **)(*param_1 + 0x88))(param_1,2,iVar25,4);
              (**(code **)(*param_1 + 0x88))(param_1,3,iVar25,4);
            }
LAB_0015d5cc:
            bVar1 = iVar25 == 3;
            iVar25 = iVar25 + 1;
            if (bVar1) {
              FUN_000e7700(param_1[0x56],param_1,piVar16);
              FUN_000e7700(param_1[0x56],param_1,piVar10);
              if (local_84 != 0) {
                FUN_00106b48(param_1,&local_88,0,*(undefined4 *)(param_2 + 8));
                if (*(int *)(param_2 + 0x478) < *(int *)(local_84 + 0x160)) {
                  *(int *)(local_84 + 0x160) = *(int *)(local_84 + 0x160) + 1;
                }
                else {
                  *(int *)(local_84 + 0x160) = *(int *)(param_2 + 0x478) + 1;
                }
              }
              for (iVar25 = 1; iVar8 = (**(code **)(*piVar7 + 0x14))(piVar7), iVar25 <= iVar8;
                  iVar25 = iVar25 + 1) {
                piVar9 = (int *)FUN_00105594(piVar7,iVar25);
                if ((((piVar7[5] & 1U) == 0) ||
                    (iVar8 = (**(code **)(*piVar9 + 0x5c))(), iVar8 == 0)) ||
                   (iVar8 = FUN_0010497c(piVar9,param_2), iVar8 != 0)) {
                  iVar8 = (**(code **)(*piVar9 + 0x60))(piVar9);
                  if (((iVar8 != 0) && ((piVar7[5] & 1U) == 0)) && (piVar24 != piVar9)) {
                    FUN_00105894(piVar9,*(undefined4 *)(param_2 + 8));
                  }
                }
                else {
                  FUN_001049a0(piVar9,param_2);
                  uVar18 = *(uint *)(param_2 + 0x30) >> 7 & 1;
                  iVar8 = FUN_0010af38(piVar9,param_2,uVar18);
                  FUN_00106004(piVar7,iVar25,iVar8,0,*(undefined4 *)(param_2 + 8));
                  if (uVar18 == 0) {
                    if (*(int *)(param_2 + 0x478) < *(int *)(iVar8 + 0x160)) {
                      *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar8 + 0x160) = *(int *)(param_2 + 0x478) + 1;
                    }
                  }
                  piVar9[0x58] = piVar9[0x58] + -1;
                }
              }
              piVar9 = (int *)FUN_00105594(piVar10,1);
              iVar25 = (**(code **)(*piVar9 + 0x60))();
              if (iVar25 != 0) {
                uVar13 = FUN_00105594(piVar10,1);
                FUN_0010c670(uVar13,piVar10,*(undefined4 *)(param_2 + 8));
              }
              piVar10 = (int *)FUN_00105594(piVar16,1);
              iVar25 = (**(code **)(*piVar10 + 0x60))();
              if (iVar25 != 0) {
                uVar13 = FUN_00105594(piVar16,1);
                FUN_0010c670(uVar13,piVar16,*(undefined4 *)(param_2 + 8));
              }
              FUN_00105894(piVar7,*(undefined4 *)(param_2 + 8));
              if (bVar4) {
                FUN_0010ac38(piVar7,1,2,*(undefined4 *)(param_2 + 8));
                return 1;
              }
              return 1;
            }
          } while( true );
        }
      }
LAB_0015d1a4:
      if (bVar4) {
        FUN_0010ac38(piVar7,1,2,*(undefined4 *)(param_2 + 8));
      }
      if (!bVar3) {
        return 0;
      }
      FUN_0010ac38(param_1,1,2,*(undefined4 *)(param_2 + 8));
      return 0;
    }
    iVar8 = (**(code **)(*piVar7 + 100))();
    piVar16 = piVar7;
    piVar10 = param_1;
    if (iVar8 != 0) goto LAB_0015cf80;
  }
  iVar8 = (**(code **)(*param_1 + 100))(param_1);
  if (iVar8 == 0) {
    return 0;
  }
  piVar16 = param_1;
  piVar10 = piVar7;
  if (iVar25 != 0x12) {
    return 0;
  }
LAB_0015cf80:
  iVar25 = FUN_00105594(piVar16,1);
  iVar8 = FUN_00105594(piVar10,1);
  if (iVar25 == iVar8) {
    iVar25 = 1;
    iVar8 = 2;
  }
  else {
    iVar25 = FUN_00105594(piVar16,1);
    iVar8 = FUN_00105594(piVar10,2);
    if (iVar25 != iVar8) {
      return 0;
    }
    iVar25 = 2;
    iVar8 = 1;
  }
  iVar12 = FUN_001054ec(param_1,0);
  local_108 = *(int *)(iVar12 + 0x10);
  iVar12 = FUN_001054ec(piVar7,0);
  local_104 = *(int *)(iVar12 + 0x10);
  if ((piVar7[0x49] == param_1[0x49]) && (piVar7[0x48] == param_1[0x48])) {
    if (((piVar16[0x2e] & 1U) == (piVar10[iVar25 * 6 + 0x28] & 1U)) &&
       (((uint)piVar16[0x2e] >> 1 & 1) == ((uint)piVar10[iVar25 * 6 + 0x28] >> 1 & 1))) {
      iVar6 = 0;
      iVar26 = 4;
      do {
        if ((*(char *)((int)&local_104 + iVar6) != '\x01') &&
           (*(char *)((int)&local_108 + iVar6) != '\x01')) {
          return 0;
        }
        iVar6 = iVar6 + 1;
        iVar26 = iVar26 + -1;
      } while (iVar26 != 0);
      if ((local_108 != DAT_001b0054) && (DAT_001b0054 != *(int *)(iVar12 + 0x10))) {
        *(int *)(param_2 + 0x280) = *(int *)(param_2 + 0x280) + 1;
        iVar12 = param_1[0x58] - *(int *)(param_2 + 0x478);
        uVar18 = *(uint *)(param_2 + 0x30) >> 7 & 1;
        if (iVar12 < 0) {
          iVar12 = 0;
        }
        iVar26 = 4;
        iVar19 = param_1[4];
        iVar20 = param_1[0x53];
        iVar21 = param_1[0x26];
        iVar22 = param_1[0x48];
        iVar6 = 0;
        iVar23 = param_1[0x49];
        local_64 = &local_100;
        local_100 = local_108;
        do {
          if (*(char *)((int)&local_104 + iVar6) != '\x01') {
            *(char *)(iVar6 + (int)&local_100) = *(char *)((int)&local_104 + iVar6);
          }
          iVar6 = iVar6 + 1;
          iVar26 = iVar26 + -1;
        } while (iVar26 != 0);
        iVar26 = FUN_001054ec(piVar10,iVar8);
        iVar6 = 0;
        local_fc = *(int *)(iVar26 + 0x10);
        iVar26 = 4;
        do {
          if (*(char *)(iVar6 + (int)local_64) == '\0') {
            *(char *)((int)&local_fc + iVar6) = (char)iVar6;
          }
          iVar6 = iVar6 + 1;
          iVar26 = iVar26 + -1;
        } while (iVar26 != 0);
        iVar6 = FUN_001054ec(piVar10,iVar25);
        local_e8[0] = *(int *)(iVar6 + 0x10);
        iVar26 = FUN_001054ec(piVar16,1);
        iVar6 = 0;
        local_f8 = *(int *)(iVar26 + 0x10);
        iVar26 = 4;
        do {
          if (*(char *)((int)local_e8 + iVar6) == '\x04') {
            *(undefined1 *)((int)local_e8 + iVar6) = *(undefined1 *)((int)&local_f8 + iVar6);
          }
          iVar6 = iVar6 + 1;
          iVar26 = iVar26 + -1;
        } while (iVar26 != 0);
        uVar13 = FUN_00105594(piVar10,iVar8);
        iVar6 = FUN_0010af38(uVar13,param_2,uVar18);
        iVar26 = FUN_00105594(piVar10,iVar25);
        iVar14 = FUN_0010a240(0xa2,*(undefined4 *)(param_2 + 8));
        FUN_000e7700(param_1[0x56],param_1,iVar14);
        *(undefined4 *)(iVar14 + 0x84) = 1;
        *(undefined4 *)(iVar14 + 0x94) = *(undefined4 *)(iVar14 + 0x14c);
        *(undefined4 *)(iVar14 + 0x98) = 0x36;
        *(int *)(iVar14 + 0x9c) = local_100;
        FUN_00106004(iVar14,1,iVar6,0,*(undefined4 *)(param_2 + 8));
        iVar15 = FUN_001054ec(piVar10,iVar8);
        uVar13 = *(undefined4 *)(iVar15 + 0x10);
        iVar15 = FUN_001054ec(iVar14,1);
        *(undefined4 *)(iVar15 + 0x10) = uVar13;
        if (*(int *)(param_2 + 0x478) < *(int *)(iVar6 + 0x160)) {
          *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
        }
        else {
          *(int *)(iVar6 + 0x160) = *(int *)(param_2 + 0x478) + 1;
        }
        dVar27 = (double)FLOAT_001aa0d4;
        *(undefined4 *)(iVar14 + 0x84) = 2;
        FUN_000f79c4(dVar27,dVar27,dVar27,dVar27,iVar14,param_2,2);
        iVar6 = FUN_001054ec(piVar16,1);
        uVar13 = *(undefined4 *)(iVar6 + 0x10);
        iVar6 = FUN_001054ec(iVar14,2);
        *(undefined4 *)(iVar6 + 0x10) = uVar13;
        iVar6 = FUN_00105594(iVar14,2);
        if (*(int *)(param_2 + 0x478) < *(int *)(iVar6 + 0x160)) {
          *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
        }
        else {
          *(int *)(iVar6 + 0x160) = *(int *)(param_2 + 0x478) + 1;
        }
        *(undefined4 *)(iVar14 + 0x160) = *(undefined4 *)(param_2 + 0x478);
        piVar16 = (int *)FUN_00105594(iVar14,1);
        iVar6 = (**(code **)(*piVar16 + 0x60))();
        if (iVar6 != 0) {
          uVar13 = FUN_00105594(iVar14,1);
          FUN_0010c670(uVar13,iVar14,*(undefined4 *)(param_2 + 8));
        }
        iVar6 = 0;
        local_60 = &DAT_001acec0;
        local_f4[0] = DAT_001b0050;
        if (((piVar7[5] & 0x200U) != 0) && (iVar6 = FUN_00105594(piVar7,piVar7[0x21]), iVar6 != 0))
        {
          iVar17 = FUN_001054ec(param_1,param_1[0x21]);
          iVar15 = 0;
          local_f4[0] = *(int *)(iVar17 + 0x10);
          iVar17 = 4;
          do {
            if (*(char *)(iVar15 + (int)local_64) == '\0') {
              *(undefined1 *)((int)local_f4 + iVar15) = 4;
            }
            iVar15 = iVar15 + 1;
            iVar17 = iVar17 + -1;
          } while (iVar17 != 0);
        }
        if (0 < param_1[0x21]) {
          iVar15 = 1;
          do {
            iVar17 = FUN_00105594(param_1,iVar15);
            *(int *)(iVar17 + 0x160) = *(int *)(iVar17 + 0x160) + -1;
            if (uVar18 != 0) {
              iVar17 = FUN_00105594(param_1,iVar15);
              FUN_00194374(*(undefined4 *)(iVar17 + 0x10),param_1);
            }
            iVar15 = iVar15 + 1;
          } while (iVar15 <= param_1[0x21]);
        }
        local_a4 = 0;
        local_d0 = 0;
        local_cc = 0;
        local_bc = 0;
        local_b8 = 0;
        local_b4 = 0;
        uVar13 = FUN_001054ec(piVar10,iVar8);
        FUN_00104730(&local_d0,uVar13);
        uVar13 = FUN_001054ec(piVar10,iVar25);
        FUN_00104730(&local_b8,uVar13);
        iVar15 = param_1[1];
        FUN_0019401c(param_1);
        FUN_00108174(param_1,0x12,*(undefined4 *)(param_2 + 8));
        bVar1 = uVar18 == 0;
        FUN_000e7738(*(undefined4 *)(iVar15 + 0x158),iVar15,param_1);
        iVar15 = *(int *)(param_2 + 0x478);
        param_1[4] = iVar19;
        param_1[0x58] = iVar12 + iVar15;
        param_1[0x27] = local_100;
        param_1[0x48] = iVar22;
        param_1[0x49] = iVar23;
        param_1[0x25] = iVar20;
        param_1[0x26] = iVar21;
        uVar13 = FUN_001054ec(param_1,iVar8);
        FUN_001047a8(uVar13,&local_d0);
        FUN_00106004(param_1,iVar8,iVar14,0,*(undefined4 *)(param_2 + 8));
        iVar12 = local_fc;
        if (bVar1) {
          if (*(int *)(param_2 + 0x478) < *(int *)(iVar14 + 0x160)) {
            *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + 1;
          }
          else {
            *(int *)(iVar14 + 0x160) = *(int *)(param_2 + 0x478) + 1;
          }
        }
        if (iVar8 == 0) {
          param_1[0x27] = local_fc;
        }
        else {
          iVar8 = FUN_001054ec(param_1,iVar8);
          *(int *)(iVar8 + 0x10) = iVar12;
        }
        uVar13 = FUN_001054ec(param_1,iVar25);
        FUN_001047a8(uVar13,&local_b8);
        FUN_00106004(param_1,iVar25,iVar26,0,*(undefined4 *)(param_2 + 8));
        iVar8 = local_e8[0];
        if (bVar1) {
          if (*(int *)(param_2 + 0x478) < *(int *)(iVar26 + 0x160)) {
            *(int *)(iVar26 + 0x160) = *(int *)(iVar26 + 0x160) + 1;
          }
          else {
            *(int *)(iVar26 + 0x160) = *(int *)(param_2 + 0x478) + 1;
          }
        }
        if (iVar25 == 0) {
          param_1[0x27] = local_e8[0];
        }
        else {
          iVar25 = FUN_001054ec(param_1,iVar25);
          *(int *)(iVar25 + 0x10) = iVar8;
        }
        if ((iVar6 != 0) && (local_f4[0] != *(int *)((*(unsigned char *)0x00003190) + (int)local_60))) {
          FUN_00106804(param_1,iVar6,uVar18,*(undefined4 *)(param_2 + 8));
          iVar25 = local_f4[0];
          iVar8 = FUN_001054ec(param_1,3);
          *(int *)(iVar8 + 0x10) = iVar25;
          if (bVar1) {
            if (*(int *)(param_2 + 0x478) < *(int *)(iVar6 + 0x160)) {
              *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
            }
            else {
              *(int *)(iVar6 + 0x160) = *(int *)(param_2 + 0x478) + 1;
            }
          }
        }
        FUN_0010564c(piVar7,*(undefined4 *)(param_2 + 8),0);
        return 0;
      }
    }
  }
  return 0;
}

/* FUN_0015df44 @ 0x15df44 (936 bytes) */
int FUN_0015df44(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  
  if (*(int *)(param_1[0x22] + 8) == 0x13) {
    piVar4 = (int *)FUN_00105594(param_1,1);
    piVar5 = (int *)FUN_00105594(param_1,2);
    if ((((((*(int *)(piVar4[0x22] + 8) == 0x37) &&
           (iVar6 = FUN_0010497c(piVar4,param_2), iVar6 != 0)) && ((piVar4[5] & 0x200U) == 0)) &&
         ((piVar4[0x48] == 0 && (piVar4[0x49] == 0)))) &&
        ((*(int *)(piVar5[0x22] + 8) == 0x37 &&
         ((iVar6 = FUN_0010497c(piVar5,param_2), iVar6 != 0 && ((piVar5[5] & 0x200U) == 0)))))) &&
       ((piVar5[0x48] == 0 && (piVar5[0x49] == 0)))) {
      iVar13 = param_1[0x58] - *(int *)(param_2 + 0x478);
      iVar6 = param_1[0x48];
      iVar11 = param_1[0x49];
      iVar12 = param_1[0x53];
      if (iVar13 < 0) {
        iVar13 = 0;
      }
      iVar14 = param_1[0x25];
      bVar1 = ((param_1[0x34] ^ param_1[0x2e]) & 1U) != 0;
      iVar15 = param_1[0x26];
      iVar8 = FUN_001054ec(param_1,0);
      iVar16 = *(int *)(iVar8 + 0x10);
      iVar9 = FUN_001043f0(0x12,*(undefined4 *)(param_2 + 8));
      FUN_00105e54(iVar9,1,piVar4,1);
      FUN_00105e54(iVar9,2,piVar5,1);
      iVar8 = DAT_001b0054;
      iVar3 = *(int *)(param_2 + 0x478);
      *(undefined4 *)(iVar9 + 0x94) = *(undefined4 *)(iVar9 + 0x14c);
      *(undefined4 *)(iVar9 + 0x98) = 0;
      *(int *)(iVar9 + 0x9c) = iVar8;
      iVar10 = param_1[0x56];
      *(int *)(iVar9 + 0x160) = iVar3 + 1;
      FUN_000e7700(iVar10,param_1,iVar9);
      if (bVar1) {
        piVar7 = (int *)FUN_001043f0(0x37,*(undefined4 *)(param_2 + 8));
        iVar3 = *(int *)(param_2 + 0x478);
        piVar7[0x27] = iVar8;
        piVar7[0x58] = iVar3 + 1;
        piVar7[0x25] = piVar7[0x53];
        uVar2 = DAT_001b0050;
        piVar7[0x26] = 0;
        iVar8 = FUN_001054ec(piVar7,1);
        *(undefined4 *)(iVar8 + 0x10) = uVar2;
        (**(code **)(*piVar7 + 0x88))(piVar7,1,3,3);
        FUN_000e7700(param_1[0x56],param_1,piVar7);
        FUN_0019401c(param_1);
        FUN_00108448(param_1,0x31,*(undefined4 *)(param_2 + 8));
        FUN_00106004(param_1,1,piVar7,0,*(undefined4 *)(param_2 + 8));
        FUN_000e7738(piVar7[0x56],piVar7,param_1);
        FUN_00103d50(param_1 + 0x29,1,1);
      }
      else {
        FUN_0019401c(param_1);
        FUN_00107da8(param_1,0x37,*(undefined4 *)(param_2 + 8));
        FUN_000e7738(*(undefined4 *)(iVar9 + 0x158),iVar9,param_1);
        piVar7 = param_1;
      }
      FUN_00106004(piVar7,1,iVar9,0,*(undefined4 *)(param_2 + 8));
      param_1[0x48] = iVar6;
      param_1[0x49] = iVar11;
      param_1[0x53] = iVar12;
      param_1[0x58] = iVar13 + *(int *)(param_2 + 0x478);
      iVar6 = FUN_001054ec(param_1,0);
      param_1[0x27] = iVar16;
      *(int *)(iVar6 + 0xc) = iVar15;
      *(int *)(iVar6 + 8) = iVar14;
      if (bVar1) {
        iVar6 = 0;
        do {
          iVar11 = FUN_001054ec(param_1,0);
          if (*(char *)(iVar6 + iVar11 + 0x10) != '\x01') {
            (**(code **)(*param_1 + 0x88))(param_1,1,iVar6,3);
          }
          bVar1 = iVar6 != 3;
          iVar6 = iVar6 + 1;
        } while (bVar1);
      }
      (**(code **)(*piVar4 + 0xc))(piVar4,0,*(undefined4 *)(param_2 + 8));
      (**(code **)(*piVar5 + 0xc))(piVar5,0,*(undefined4 *)(param_2 + 8));
      return 1;
    }
  }
  return 0;
}

/* FUN_0015e2f4 @ 0x15e2f4 (416 bytes) */
undefined4
FUN_0015e2f4(double param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_48 [4];
  float local_44;
  
  if (((((*(int *)(param_2 + 0x120) == 0) && (*(int *)(param_2 + 0x124) == 0)) &&
       ((*(uint *)(param_2 + 0xb8) & 1) == 0)) &&
      (((*(uint *)(param_2 + 0xb8) & 2) == 0 && ((*(uint *)(param_2 + 0xd0) & 1) == 0)))) &&
     (((*(uint *)(param_2 + 0xd0) & 2) == 0 && (*(int *)(*(int *)(param_2 + 0x88) + 8) == param_3)))
     ) {
    iVar1 = FUN_001054ec(param_2,0);
    iVar1 = FUN_000f5cf0(param_2,1,*(undefined4 *)(iVar1 + 0x10),auStack_48);
    if ((iVar1 != 0) && (param_1 == (double)local_44)) {
      uVar2 = FUN_00105594(param_2,2);
      iVar1 = FUN_001054ec(param_2,2);
      uVar4 = *(undefined4 *)(iVar1 + 0x10);
      uVar3 = FUN_00105594(param_2,1);
      FUN_00106004(param_2,2,uVar3,0,param_5);
      iVar1 = FUN_001054ec(param_2,1);
      uVar3 = *(undefined4 *)(iVar1 + 0x10);
      iVar1 = FUN_001054ec(param_2,2);
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      FUN_00106004(param_2,1,uVar2,0,param_5);
      iVar1 = FUN_001054ec(param_2,1);
      *(undefined4 *)(iVar1 + 0x10) = uVar4;
      return uVar2;
    }
    iVar1 = FUN_001054ec(param_2,0);
    iVar1 = FUN_000f5cf0(param_2,2,*(undefined4 *)(iVar1 + 0x10),auStack_48);
    if ((iVar1 != 0) && ((double)local_44 == param_1)) {
      uVar2 = FUN_00105594(param_2,1);
      return uVar2;
    }
  }
  return 0;
}

/* FUN_0015e494 @ 0x15e494 (1444 bytes) */
int FUN_0015e494(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_64;
  
  iVar16 = *(int *)(param_2 + 8);
  iVar3 = (**(code **)(**(int **)(iVar16 + 0x30c) + 0x80))();
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = ((undefined4 (*)())FUN_0015e2f4)((double)FLOAT_001aa0d4,param_1,0x17);
  if (iVar3 == 0) {
    iVar3 = ((undefined4 (*)())FUN_0015e2f4)((double)FLOAT_001aa0e8,param_1,0x19);
    if (iVar3 == 0) {
      return 0;
    }
    piVar4 = (int *)((undefined4 (*)())FUN_0015e2f4)((double)FLOAT_001aa0d4,iVar3,0x17);
  }
  else {
    piVar4 = (int *)((undefined4 (*)())FUN_0015e2f4)((double)FLOAT_001aa0e8,iVar3,0x19);
  }
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  if ((*(uint *)(iVar3 + 0x14) & 0x200) != 0) {
    return 0;
  }
  if ((piVar4[5] & 0x200U) != 0) {
    return 0;
  }
  *(int *)(param_2 + 0x1a8) = *(int *)(param_2 + 0x1a8) + 1;
  iVar5 = FUN_001054ec(param_1,0);
  iVar17 = 0;
  local_84 = DAT_001b0050;
  local_88 = *(undefined4 *)(iVar5 + 0x10);
  do {
    if (*(char *)((int)&local_88 + iVar17) != '\x01') {
      iVar5 = FUN_001054ec(param_1,1);
      bVar2 = *(byte *)(iVar17 + iVar5 + 0x10);
      iVar5 = FUN_001054ec(iVar3,1);
      *(undefined1 *)((int)&local_84 + iVar17) = *(undefined1 *)((uint)bVar2 + iVar5 + 0x10);
    }
    bVar1 = iVar17 != 3;
    iVar17 = iVar17 + 1;
  } while (bVar1);
  iVar17 = *(int *)(param_2 + 0x478);
  iVar5 = param_1[0x58] - iVar17;
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  local_64 = 0;
  local_78 = 0;
  local_74 = 0;
  uVar6 = FUN_001054ec(param_1,0);
  FUN_00104730(&local_78,uVar6);
  iVar13 = param_1[2];
  if (iVar17 < piVar4[0x58]) {
    piVar4[0x58] = piVar4[0x58] + 1;
  }
  else {
    piVar4[0x58] = iVar17 + 1;
  }
  FUN_00105894(iVar3,iVar16);
  iVar14 = 0;
  if ((param_1[5] & 0x200U) != 0) {
    iVar14 = FUN_00105594(param_1,param_1[0x21]);
  }
  uVar6 = DAT_001b004c;
  if (iVar14 != 0) {
    iVar7 = FUN_001054ec(param_1,param_1[0x21]);
    uVar6 = *(undefined4 *)(iVar7 + 0x10);
  }
  FUN_0019401c(param_1);
  iVar7 = FUN_001134bc(piVar4[0x22],piVar4,param_2);
  iVar8 = FUN_000f31e8(param_1,1);
  if (iVar8 != 0) {
    iVar3 = FUN_000f31e8(iVar3,1);
    bVar1 = true;
    if (iVar3 != 0) goto LAB_0015e6ec;
  }
  bVar1 = false;
LAB_0015e6ec:
  iVar3 = (**(code **)(*piVar4 + 0x24))(piVar4);
  if (((iVar3 == 0) || (iVar3 = FUN_0010497c(piVar4,param_2), iVar3 == 0)) ||
     ((bVar1 = !bVar1, bVar1 &&
      ((((iVar7 != 0 && (iVar7 != 3)) && (iVar7 != 4)) && ((iVar7 != 5 && (iVar7 != 7)))))))) {
    FUN_00108448(param_1,0x31,iVar16);
    iVar7 = 0;
    bVar1 = true;
    FUN_00106004(param_1,1,piVar4,0,iVar16);
    uVar12 = DAT_001b004c;
    iVar3 = FUN_001054ec(param_1,1);
    *(undefined4 *)(iVar3 + 0x10) = uVar12;
  }
  else {
    iVar3 = 1;
    if (0 < piVar4[0x21]) {
      do {
        iVar8 = FUN_00105594(piVar4,iVar3);
        if (iVar17 < *(int *)(iVar8 + 0x160)) {
          *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
        }
        else {
          *(int *)(iVar8 + 0x160) = iVar17 + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= piVar4[0x21]);
    }
    param_1 = (int *)FUN_00103ebc(piVar4,param_1,iVar16,0);
    FUN_00105894(piVar4,iVar16);
    if (((piVar4[5] & 1U) != 0) && (iVar3 = 1, 0 < piVar4[0x21])) {
      do {
        piVar9 = (int *)FUN_00105594(param_1,iVar3);
        iVar8 = (**(code **)(*piVar9 + 0x5c))();
        if (iVar8 != 0) {
          iVar15 = iVar17 + 1;
          piVar9[0x58] = iVar15;
          iVar8 = FUN_0010445c(piVar9,iVar16,0);
          FUN_00106004(param_1,iVar3,iVar8,0,iVar16);
          FUN_000e7738(piVar9[0x56],piVar9,iVar8);
          uVar12 = *(undefined4 *)(iVar8 + 0x14c);
          *(int *)(iVar8 + 0x160) = iVar15;
          iVar10 = FUN_001054ec(iVar8,0);
          *(undefined4 *)(iVar10 + 8) = uVar12;
          if (0 < *(int *)(iVar8 + 0x84)) {
            iVar10 = 1;
            do {
              iVar11 = FUN_00105594(iVar8,iVar10);
              if (iVar17 < *(int *)(iVar11 + 0x160)) {
                *(int *)(iVar11 + 0x160) = *(int *)(iVar11 + 0x160) + 1;
              }
              else {
                *(int *)(iVar11 + 0x160) = iVar15;
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 <= *(int *)(iVar8 + 0x84));
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= piVar4[0x21]);
    }
  }
  param_1[0x58] = iVar17 + iVar5;
  uVar12 = FUN_001054ec(param_1,0);
  FUN_00104730(uVar12,&local_78);
  uVar12 = *(undefined4 *)(iVar13 + 0x158);
  param_1[0x48] = 1;
  FUN_000e7700(uVar12,iVar13,param_1);
  if (iVar14 != 0) {
    FUN_00106804(param_1,iVar14,0,iVar16);
    iVar3 = FUN_001054ec(param_1,param_1[0x21]);
    *(undefined4 *)(iVar3 + 0x10) = uVar6;
  }
  if ((bVar1) && (iVar7 == 0)) {
    for (iVar3 = 1; iVar16 = (**(code **)(*param_1 + 0x14))(param_1), iVar3 <= iVar16;
        iVar3 = iVar3 + 1) {
      iVar16 = FUN_001054ec(param_1,iVar3);
      iVar5 = 0;
      local_7c = DAT_001b0050;
      local_80 = *(undefined4 *)(iVar16 + 0x10);
      iVar16 = 4;
      do {
        if (*(char *)((int)&local_88 + iVar5) == '\0') {
          *(undefined1 *)((int)&local_7c + iVar5) =
               *(undefined1 *)((int)&local_80 + (uint)*(byte *)((int)&local_84 + iVar5));
        }
        uVar6 = local_7c;
        iVar5 = iVar5 + 1;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
      iVar16 = FUN_001054ec(param_1,iVar3);
      *(undefined4 *)(iVar16 + 0x10) = uVar6;
    }
  }
  return 1;
}

/* FUN_0015ea3c @ 0x15ea3c (2564 bytes) */
int FUN_0015ea3c(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int *param_3;
  int param_4;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
  undefined4 local_64;
  int local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  local_70 = 0;
  if ((((param_1 != 0) && (*(int *)(*(int *)(param_1 + 0x88) + 8) != 0x8e)) &&
      ((param_3[5] & 0x200U) != 0)) && (iVar3 = FUN_00126760(param_3[0x26]), iVar3 != 0)) {
    iVar3 = (**(code **)(*param_3 + 100))(param_3);
    if (((iVar3 == 0) || (param_3[0x48] != 0)) ||
       ((param_3[0x49] != 0 || (((param_3[0x2e] & 1U) != 0 || ((param_3[0x2e] & 2U) != 0)))))) {
      iVar3 = (**(code **)(*param_3 + 100))(param_3);
      if (iVar3 == 0) {
        piVar4 = (int *)FUN_00105594(param_3,param_3[0x21]);
        iVar3 = (**(code **)(*piVar4 + 100))();
        if ((((iVar3 != 0) && ((piVar4[5] & 0x200U) == 0)) && (piVar4[0x48] == 0)) &&
           (((piVar4[0x49] == 0 && ((piVar4[0x2e] & 1U) == 0)) &&
            ((uVar11 = piVar4[0x2e] & 2, uVar11 == 0 &&
             (iVar3 = FUN_000f5a0c(piVar4,1,piVar4,param_4), iVar3 != 0)))))) {
          *(int *)(param_4 + 0x228) = *(int *)(param_4 + 0x228) + 1;
          iVar5 = param_3[1];
          FUN_0019401c(param_3);
          local_5c = uVar11;
          local_58 = uVar11;
          local_54 = uVar11;
          FUN_00103f18(param_3,&local_5c,0xffffffff);
          iVar3 = FUN_0010445c(param_3,*(undefined4 *)(param_4 + 8),0);
          *(int *)(iVar3 + 0x160) = *(int *)(param_4 + 0x478) + 1;
          *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(iVar3 + 0x14c);
          FUN_00106004(iVar3,*(undefined4 *)(iVar3 + 0x84),0,0,*(undefined4 *)(param_4 + 8));
          uVar6 = *(undefined4 *)(iVar5 + 0x158);
          *(int *)(iVar3 + 0x84) = *(int *)(iVar3 + 0x84) + -1;
          *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffdff;
          FUN_000e7738(uVar6,iVar5,iVar3);
          FUN_0010a1c0(param_3,0xa2,*(undefined4 *)(param_4 + 8));
          iVar9 = 0;
          FUN_000e7738(*(undefined4 *)(iVar3 + 0x158),iVar3,param_3);
          iVar5 = FUN_001054ec(iVar3,0);
          uVar6 = *(undefined4 *)(iVar5 + 0x10);
          iVar5 = FUN_001054ec(iVar3,0);
          local_68 = *(int *)(iVar5 + 0x10);
          iVar5 = FUN_001054ec(piVar4,0);
          local_64 = *(undefined4 *)(iVar5 + 0x10);
          do {
            iVar5 = FUN_001054ec(iVar3,0);
            if (*(char *)(iVar9 + iVar5 + 0x10) != '\x01') {
              *(undefined1 *)((int)&local_64 + iVar9) = 1;
            }
            bVar2 = iVar9 != 3;
            iVar9 = iVar9 + 1;
          } while (bVar2);
          iVar9 = FUN_001054ec(piVar4,0);
          iVar5 = 0;
          local_6c = *(undefined4 *)(iVar9 + 0x10);
          iVar9 = 4;
          do {
            if (*(char *)((int)&local_6c + iVar5) != '\x01') {
              *(char *)((int)&local_68 + iVar5) = *(char *)((int)&local_6c + iVar5);
            }
            iVar5 = iVar5 + 1;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
          param_3[0x27] = local_68;
          param_3[0x25] = param_3[0x53];
          param_3[0x26] = 0x36;
          FUN_00103f44(param_3,&local_5c);
          param_3[0x21] = 2;
          FUN_00106004(param_3,1,iVar3,0,*(undefined4 *)(param_4 + 8));
          uVar7 = DAT_001b004c;
          FUN_000f3908(&local_48,uVar6);
          FUN_000f3340(&local_44,uVar7,local_48);
          iVar3 = FUN_001054ec(param_3,1);
          *(undefined4 *)(iVar3 + 0x10) = local_44;
          uVar6 = FUN_00105594(piVar4,1);
          FUN_00106004(param_3,2,uVar6,0,*(undefined4 *)(param_4 + 8));
          iVar3 = FUN_001054ec(piVar4,1);
          uVar6 = *(undefined4 *)(iVar3 + 0x10);
          FUN_000f3908(&local_40,local_64);
          FUN_000f3340(local_3c,uVar6,local_40);
          iVar3 = FUN_001054ec(param_3,2);
          *(undefined4 *)(iVar3 + 0x10) = local_3c[0];
          FUN_00105894(piVar4,*(undefined4 *)(param_4 + 8));
          FUN_00160320(param_1,param_2,param_3,param_4,&local_70);
          return 1;
        }
      }
    }
    else {
      bVar2 = true;
      iVar3 = 0;
      piVar4 = (int *)FUN_00105594(param_3,param_3[0x21]);
      do {
        iVar5 = FUN_001054ec(param_3,0);
        if (((*(char *)(iVar3 + iVar5 + 0x10) == '\x01') &&
            (iVar5 = FUN_001054ec(piVar4,0), *(char *)(iVar3 + iVar5 + 0x10) == '\x01')) &&
           ((piVar4[5] & 0x200U) != 0)) {
          bVar2 = false;
        }
        bVar1 = iVar3 != 3;
        iVar3 = iVar3 + 1;
      } while (bVar1);
      if (bVar2) {
        iVar3 = FUN_000f5a0c(param_3,1,param_3,param_4);
        if (iVar3 == 0) {
          iVar3 = (**(code **)(*piVar4 + 100))(piVar4);
          if (iVar3 == 0) {
            return 0;
          }
          uVar11 = piVar4[5] & 0x200;
          if (uVar11 != 0) {
            return 0;
          }
          iVar3 = FUN_000f5a0c(piVar4,1,piVar4,param_4);
          if (iVar3 == 0) {
            return 0;
          }
          *(int *)(param_4 + 0x228) = *(int *)(param_4 + 0x228) + 1;
          local_5c = uVar11;
          local_58 = uVar11;
          local_54 = uVar11;
          FUN_00103f18(param_3,&local_5c,0xffffffff);
          uVar6 = FUN_00105594(param_3,1);
          iVar3 = FUN_001054ec(param_3,0);
          local_60 = *(int *)(iVar3 + 0x10);
          iVar5 = FUN_001054ec(piVar4,1);
          iVar3 = 0;
          local_64 = *(undefined4 *)(iVar5 + 0x10);
          iVar5 = 4;
          do {
            if (*(char *)((int)&local_60 + iVar3) != '\x01') {
              *(undefined1 *)((int)&local_64 + iVar3) = 4;
            }
            iVar3 = iVar3 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          iVar5 = FUN_001054ec(piVar4,0);
          iVar3 = 0;
          local_78 = *(undefined4 *)(iVar5 + 0x10);
          iVar5 = 4;
          do {
            if (*(char *)((int)&local_78 + iVar3) != '\x01') {
              *(char *)((int)&local_60 + iVar3) = *(char *)((int)&local_78 + iVar3);
            }
            iVar3 = iVar3 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          iVar3 = FUN_001054ec(param_3,1);
          iVar5 = param_3[1];
          uVar7 = *(undefined4 *)(iVar3 + 0x10);
          FUN_0019401c(param_3);
          FUN_0010a1c0(param_3,0xa2,*(undefined4 *)(param_4 + 8));
          FUN_00103f44(param_3,&local_5c);
          param_3[0x26] = 0x36;
          param_3[0x25] = param_3[0x53];
          param_3[0x27] = local_60;
          param_3[0x21] = 2;
          FUN_00106004(param_3,1,uVar6,0,*(undefined4 *)(param_4 + 8));
          iVar3 = FUN_001054ec(param_3,1);
          *(undefined4 *)(iVar3 + 0x10) = uVar7;
          uVar6 = FUN_00105594(piVar4,1);
          FUN_00106004(param_3,2,uVar6,0,*(undefined4 *)(param_4 + 8));
          uVar6 = local_64;
          iVar3 = FUN_001054ec(param_3,2);
          *(undefined4 *)(iVar3 + 0x10) = uVar6;
          FUN_000e7738(*(undefined4 *)(iVar5 + 0x158),iVar5,param_3);
          FUN_00105894(piVar4,*(undefined4 *)(param_4 + 8));
        }
        else {
          *(int *)(param_4 + 0x228) = *(int *)(param_4 + 0x228) + 1;
          local_54 = 0;
          local_5c = 0;
          local_58 = 0;
          FUN_00103f18(param_3,&local_5c,0xffffffff);
          uVar6 = FUN_00105594(param_3,1);
          iVar3 = FUN_001054ec(param_3,0);
          local_68 = *(int *)(iVar3 + 0x10);
          iVar5 = FUN_001054ec(piVar4,0);
          iVar3 = 0;
          local_74 = *(undefined4 *)(iVar5 + 0x10);
          iVar5 = 4;
          do {
            if (*(char *)((int)&local_74 + iVar3) != '\x01') {
              *(char *)((int)&local_68 + iVar3) = *(char *)((int)&local_74 + iVar3);
            }
            iVar3 = iVar3 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          iVar3 = 0;
          local_64 = DAT_001b004c;
          do {
            iVar5 = FUN_001054ec(param_3,0);
            if (*(char *)(iVar3 + iVar5 + 0x10) != '\x01') {
              *(undefined1 *)((int)&local_64 + iVar3) = 4;
            }
            bVar2 = iVar3 != 3;
            iVar3 = iVar3 + 1;
          } while (bVar2);
          iVar3 = 0;
          iVar5 = 4;
          do {
            if (*(char *)((int)&local_68 + iVar3) == '\x01') {
              *(undefined1 *)((int)&local_64 + iVar3) = 4;
            }
            iVar3 = iVar3 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          iVar3 = FUN_001054ec(param_3,1);
          local_60 = *(int *)(iVar3 + 0x10);
          iVar5 = param_3[1];
          FUN_0019401c(param_3);
          FUN_0010a1c0(param_3,0xa2,*(undefined4 *)(param_4 + 8));
          FUN_00103f44(param_3,&local_5c);
          param_3[0x26] = 0x36;
          param_3[0x25] = param_3[0x53];
          param_3[0x27] = local_68;
          iVar3 = (**(code **)(*piVar4 + 0x60))(piVar4);
          if (iVar3 == 0) {
            param_3[0x21] = 2;
            FUN_00106004(param_3,1,piVar4,0,*(undefined4 *)(param_4 + 8));
            uVar7 = local_64;
            iVar3 = FUN_001054ec(param_3,1);
            *(undefined4 *)(iVar3 + 0x10) = uVar7;
            FUN_00106004(param_3,2,uVar6,0,*(undefined4 *)(param_4 + 8));
            iVar3 = local_60;
            iVar9 = FUN_001054ec(param_3,2);
            *(int *)(iVar9 + 0x10) = iVar3;
          }
          else {
            param_3[0x21] = piVar4[0x21] + 1;
            if (0 < piVar4[0x21]) {
              iVar3 = 1;
              do {
                uVar7 = FUN_00105594(piVar4,iVar3);
                FUN_00106004(param_3,iVar3,uVar7,0,*(undefined4 *)(param_4 + 8));
                iVar9 = FUN_001054ec(piVar4,iVar3);
                iVar9 = *(int *)(iVar9 + 0x10);
                if (iVar3 == 0) {
                  param_3[0x27] = iVar9;
                }
                else {
                  iVar8 = FUN_001054ec(param_3,iVar3);
                  *(int *)(iVar8 + 0x10) = iVar9;
                }
                iVar3 = iVar3 + 1;
              } while (iVar3 <= piVar4[0x21]);
            }
            piVar4[0x58] = piVar4[0x58] + -1;
            iVar3 = FUN_00105594(piVar4,1);
            if (*(int *)(param_4 + 0x478) < *(int *)(iVar3 + 0x160)) {
              *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + 1;
            }
            else {
              *(int *)(iVar3 + 0x160) = *(int *)(param_4 + 0x478) + 1;
            }
            iVar3 = param_3[0x21];
            iVar9 = 0;
            do {
              if ((*(char *)((int)&local_60 + iVar9) != '\x04') && (0 < iVar3)) {
                iVar8 = 1;
                do {
                  iVar10 = iVar8 + 1;
                  (**(code **)(*param_3 + 0x88))(param_3,iVar8,iVar9,4);
                  iVar3 = param_3[0x21];
                  iVar8 = iVar10;
                } while (iVar10 <= iVar3);
              }
              bVar2 = iVar9 != 3;
              iVar9 = iVar9 + 1;
            } while (bVar2);
            FUN_00106004(param_3,iVar3,uVar6,0,*(undefined4 *)(param_4 + 8));
            iVar3 = local_60;
            if (param_3[0x21] == 0) {
              param_3[0x27] = local_60;
            }
            else {
              iVar9 = FUN_001054ec(param_3);
              *(int *)(iVar9 + 0x10) = iVar3;
            }
          }
          FUN_000e7738(*(undefined4 *)(iVar5 + 0x158),iVar5,param_3);
          FUN_0010564c(piVar4,*(undefined4 *)(param_4 + 8),0);
          iVar3 = (**(code **)(*piVar4 + 100))(piVar4);
          if (iVar3 == 0) {
            return 1;
          }
        }
        FUN_00160320(param_1,param_2,param_3,param_4,&local_70);
        return 1;
      }
    }
  }
  return 0;
}

