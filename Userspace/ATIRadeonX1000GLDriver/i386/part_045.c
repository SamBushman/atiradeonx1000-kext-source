#include "decls.h"

/* FUN_0017412a @ 0x17412a (191 bytes) */
int FUN_0017412a(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int *param_2;
  int *param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_10 [2];
  
  if (param_6 == 0) {
    cVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x54))
                      (*(int **)(param_1 + 8),param_2,param_3,local_10);
    if (cVar1 != '\0') {
      return local_10[0];
    }
    if ((((*(int *)(param_2[0x22] + 4) != 1) &&
         ((cVar1 = (**(code **)(*param_3 + 0x54))(param_3), cVar1 == '\0' ||
          (cVar1 = FUN_0010a320(param_3), cVar1 != '\0')))) &&
        ((cVar1 = (**(code **)(*param_3 + 0x5c))(param_3), cVar1 == '\0' ||
         (cVar1 = (**(code **)(*param_2 + 0x28))(param_2), cVar1 == '\0')))) &&
       ((cVar1 = (**(code **)(*param_3 + 0x60))(param_3), cVar1 == '\0' &&
        (cVar1 = FUN_0010a35a(param_2), cVar1 == '\0')))) {
      uVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x78))(*(int **)(param_1 + 8));
      return uVar2;
    }
  }
  else if (param_6 == 1) {
    return 1;
  }
  return 0;
}

/* FUN_001741ea @ 0x1741ea (65 bytes) */
int FUN_001741ea(param_1)
  int param_1;
{
  int iVar1;
  
  if ((0 < *(int *)(param_1 + 0x80)) &&
     ((((*(int *)(*(int *)(param_1 + 0x88) + 4) == 1 || ((*(byte *)(param_1 + 0x14) & 0x40) != 0))
       || (iVar1 = *(int *)(param_1 + 0x98), iVar1 == 0x20)) || ((iVar1 == 0x21 || (iVar1 == 0x22)))
      ))) {
    return 1;
  }
  return 0;
}

/* FUN_0017422c @ 0x17422c (82 bytes) */
int FUN_0017422c(param_1)
  int *param_1;
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x7c))(param_1);
  if (iVar1 == 0) {
    if ((short)param_1[5] < 0) {
      iVar1 = param_1[0x22];
      if ((*(int *)(iVar1 + 4) != 1) && (param_1[0x21] == 0)) {
        return 1;
      }
    }
    else {
      iVar1 = param_1[0x22];
    }
    if (*(int *)(iVar1 + 8) != 0xa4) {
      return 0;
    }
  }
  return 1;
}

/* FUN_0017427e @ 0x17427e (1425 bytes) */
int FUN_0017427e(param_1)
  int *param_1;
{
  uint *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  int *piVar4;
  bool bVar5;
  char cVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  int iVar17;
  uint *puVar18;
  int local_64;
  int local_4c;
  int local_44;
  int local_40;
  int local_3c;
  uint local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  
  iVar12 = param_1[1];
  local_64 = *(int *)(iVar12 + 0x378);
  if (*(int *)(local_64 + 8) != 0) {
    do {
      uVar3 = *(undefined4 *)(*param_1 + 0xbc);
      iVar12 = param_1[0x50];
      uVar14 = iVar12 + 0x1fU >> 5;
      puVar7 = (undefined4 *)FUN_001a7bca(uVar3,uVar14 * 4 + 0xc);
      *puVar7 = uVar3;
      puVar7[2] = iVar12;
      puVar7[1] = uVar14;
      if (uVar14 != 0) {
        uVar15 = 0;
        puVar8 = puVar7 + 1;
        do {
          puVar8[2] = 0;
          uVar15 = uVar15 + 1;
          puVar8 = puVar8 + 1;
        } while (uVar15 < uVar14);
      }
      *(undefined4 **)(local_64 + 0x100) = puVar7 + 1;
      uVar3 = *(undefined4 *)(*param_1 + 0xbc);
      iVar12 = param_1[0x50];
      uVar14 = iVar12 + 0x1fU >> 5;
      puVar7 = (undefined4 *)FUN_001a7bca(uVar3,uVar14 * 4 + 0xc);
      *puVar7 = uVar3;
      puVar7[2] = iVar12;
      puVar7[1] = uVar14;
      if (uVar14 != 0) {
        uVar15 = 0;
        puVar8 = puVar7 + 1;
        do {
          puVar8[2] = 0;
          uVar15 = uVar15 + 1;
          puVar8 = puVar8 + 1;
        } while (uVar15 < uVar14);
      }
      *(undefined4 **)(local_64 + 0xfc) = puVar7 + 1;
      *(undefined4 *)(local_64 + 0x110) = *(undefined4 *)(param_1[1] + 0x468);
      local_64 = *(int *)(local_64 + 8);
    } while (*(int *)(local_64 + 8) != 0);
    iVar12 = param_1[1];
  }
  *(int *)(iVar12 + 0x468) = *(int *)(iVar12 + 0x468) + 1;
  iVar12 = param_1[1];
  local_20 = *(int *)(iVar12 + 0x378);
  if (*(int *)(local_20 + 8) != 0) {
    do {
      piVar4 = *(int **)(local_20 + 0x98);
      iVar12 = piVar4[2];
      while (iVar12 != 0) {
        if (((*(byte *)(piVar4 + 5) & 1) != 0) && (0 < piVar4[0x21])) {
          local_4c = 1;
          local_28 = 0;
          local_24 = 0;
          do {
            piVar9 = (int *)FUN_0010b180(piVar4,local_4c);
            if (((*(byte *)(piVar9 + 5) & 0x40) == 0) ||
               (cVar6 = FUN_0012dfd8(piVar9[0x26]), cVar6 == '\0')) {
              cVar6 = (**(code **)(*piVar9 + 0x5c))(piVar9);
              if (cVar6 == '\0') {
                cVar6 = (**(code **)(*piVar9 + 0x60))(piVar9);
                if (cVar6 == '\0') goto LAB_0017440c;
                iVar12 = piVar9[0x21];
              }
              else {
                iVar12 = piVar9[0x21];
              }
              if (0 < iVar12) {
                local_44 = 1;
                do {
                  piVar10 = (int *)FUN_0010b180(piVar9,local_44);
                  cVar6 = (**(code **)(*piVar10 + 0x5c))(piVar10);
                  if (cVar6 == '\0') {
                    if (((*(byte *)(piVar10 + 5) & 0x40) != 0) &&
                       (cVar6 = FUN_0012dfd8(piVar10[0x26]), cVar6 != '\0')) {
                      iVar12 = (**(code **)(*piVar4 + 0x7c))(piVar4);
                      if (iVar12 == 0) {
                        uVar14 = piVar10[0x25];
                        iVar12 = *(int *)(local_20 + 0xfc);
                      }
                      else {
                        if (local_28 < *(uint *)(*(int *)(local_20 + 0xd4) + 4)) {
                          piVar11 = (int *)(*(int *)(*(int *)(local_20 + 0xd4) + 8) + local_24);
                        }
                        else {
                          piVar11 = (int *)0x0;
                        }
                        uVar14 = piVar10[0x25];
                        iVar12 = *(int *)(*piVar11 + 0x100);
                      }
                      puVar16 = (uint *)(iVar12 + 8 + (uVar14 >> 5) * 4);
                      *puVar16 = *puVar16 | 1 << ((byte)uVar14 & 0x1f);
                    }
                  }
                  else if (0 < piVar10[0x21]) {
                    local_40 = 1;
                    do {
                      iVar12 = FUN_0010b180(piVar10,local_40);
                      if (((*(byte *)(iVar12 + 0x14) & 0x40) != 0) &&
                         (cVar6 = FUN_0012dfd8(*(undefined4 *)(iVar12 + 0x98)), cVar6 != '\0')) {
                        iVar13 = (**(code **)(*piVar4 + 0x7c))(piVar4);
                        if (iVar13 == 0) {
                          uVar14 = *(uint *)(iVar12 + 0x94);
                          iVar12 = *(int *)(local_20 + 0xfc);
                        }
                        else {
                          if (local_28 < *(uint *)(*(int *)(local_20 + 0xd4) + 4)) {
                            piVar11 = (int *)(*(int *)(*(int *)(local_20 + 0xd4) + 8) + local_24);
                          }
                          else {
                            piVar11 = (int *)0x0;
                          }
                          uVar14 = *(uint *)(iVar12 + 0x94);
                          iVar12 = *(int *)(*piVar11 + 0x100);
                        }
                        puVar16 = (uint *)(iVar12 + 8 + (uVar14 >> 5) * 4);
                        *puVar16 = *puVar16 | 1 << ((byte)uVar14 & 0x1f);
                      }
                      local_40 = local_40 + 1;
                    } while (local_40 <= piVar10[0x21]);
                  }
                  local_44 = local_44 + 1;
                } while (local_44 <= piVar9[0x21]);
              }
            }
            else {
              iVar12 = (**(code **)(*piVar4 + 0x7c))(piVar4);
              if (iVar12 == 0) {
                uVar14 = piVar9[0x25];
                iVar12 = *(int *)(local_20 + 0xfc);
              }
              else {
                if (local_28 < *(uint *)(*(int *)(local_20 + 0xd4) + 4)) {
                  piVar10 = (int *)(*(int *)(*(int *)(local_20 + 0xd4) + 8) + local_24);
                }
                else {
                  piVar10 = (int *)0x0;
                }
                uVar14 = piVar9[0x25];
                iVar12 = *(int *)(*piVar10 + 0x100);
              }
              puVar16 = (uint *)(iVar12 + 8 + (uVar14 >> 5) * 4);
              *puVar16 = *puVar16 | 1 << ((byte)uVar14 & 0x1f);
            }
LAB_0017440c:
            local_4c = local_4c + 1;
            local_28 = local_28 + 1;
            local_24 = local_24 + 4;
          } while (local_4c <= piVar4[0x21]);
        }
        piVar4 = (int *)piVar4[2];
        iVar12 = piVar4[2];
      }
      local_20 = *(int *)(local_20 + 8);
    } while (*(int *)(local_20 + 8) != 0);
    iVar12 = param_1[1];
  }
  iVar12 = FUN_000ede1c(iVar12);
  do {
    bVar5 = false;
    local_3c = 1;
    iVar13 = FUN_001a7d8a(param_1[1] + 0x370);
    if (0 < iVar13) {
      do {
        piVar4 = *(int **)(iVar12 + local_3c * 4);
        cVar6 = (**(code **)(*piVar4 + 0x20))(piVar4);
        if (cVar6 == '\0') {
          local_30 = 1;
          local_2c = 0;
          iVar13 = piVar4[0x34];
          if (*(int *)(iVar13 + 4) != 0) {
            do {
              iVar13 = *(int *)(*(int *)(iVar13 + 8) + local_2c);
              if (iVar13 != 0) {
                puVar16 = (uint *)piVar4[0x40];
                iVar13 = *(int *)(iVar13 + 0xfc);
                if (*puVar16 != 0) {
                  uVar15 = 0;
                  uVar14 = *puVar16;
                  do {
                    puVar16[2] = puVar16[2] | *(uint *)(iVar13 + 8);
                    uVar15 = uVar15 + 1;
                    puVar16 = puVar16 + 1;
                    iVar13 = iVar13 + 4;
                  } while (uVar15 < uVar14);
                }
              }
              local_30 = local_30 + 1;
              local_2c = local_2c + 4;
              iVar13 = piVar4[0x34];
            } while (local_30 <= *(uint *)(iVar13 + 4));
          }
          iVar13 = piVar4[0x40];
          puVar16 = (uint *)piVar4[0x3f];
          if (*puVar16 != 0) {
            if ((puVar16[2] | *(uint *)(iVar13 + 8)) == puVar16[2]) {
              uVar14 = 0;
              iVar17 = iVar13;
              puVar18 = puVar16;
              do {
                uVar14 = uVar14 + 1;
                if (*puVar16 == uVar14) goto LAB_0017475a;
                puVar1 = puVar18 + 3;
                puVar2 = (uint *)(iVar17 + 0xc);
                puVar18 = puVar18 + 1;
                iVar17 = iVar17 + 4;
              } while ((*puVar1 | *puVar2) == *puVar1);
            }
            if (*puVar16 != 0) {
              uVar15 = 0;
              uVar14 = *puVar16;
              do {
                puVar16[2] = puVar16[2] | *(uint *)(iVar13 + 8);
                uVar15 = uVar15 + 1;
                puVar16 = puVar16 + 1;
                iVar13 = iVar13 + 4;
              } while (uVar15 < uVar14);
            }
            bVar5 = true;
          }
        }
LAB_0017475a:
        local_3c = local_3c + 1;
        iVar13 = FUN_001a7d8a(param_1[1] + 0x370);
      } while (local_3c <= iVar13);
    }
    if (!bVar5) {
      return;
    }
  } while( true );
}

/* FUN_00174810 @ 0x174810 (299 bytes) */
int FUN_00174810(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint *puVar1;
  int *piVar2;
  char *pcVar3;
  uint uVar4;
  char cVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  
  piVar2 = *(int **)(param_2 + 0x38);
  if (((((*(byte *)(piVar2 + 5) & 0x20) == 0) && (piVar2[0x20] != 0)) &&
      (cVar5 = FUN_0012dfd8(piVar2[0x26]), cVar5 != '\0')) && ((*(byte *)(piVar2 + 5) & 2) == 0)) {
    (**(code **)(*piVar2 + 0x50))(piVar2);
  }
  pcVar3 = *(char **)(param_2 + 0x60);
  if (pcVar3 == (char *)0x0) {
    iVar9 = *(int *)(param_2 + 0x38);
    iVar7 = 0;
    iVar10 = param_2;
    while ((*(char *)(iVar9 + 0xc) == '\0' || (*(int *)(iVar10 + 0x48) < 1))) {
      iVar7 = iVar7 + 1;
      iVar9 = iVar9 + 1;
      iVar10 = iVar10 + 4;
      if (iVar7 == 4) {
        iVar9 = *(int *)(*param_1 + 0x108) + 1;
        *(int *)(*param_1 + 0x108) = iVar9;
        *(int *)(*(int *)(param_2 + 0x38) + 0x94) = iVar9;
        puVar1 = (uint *)(*(int *)(param_2 + 0x38) + 0x14);
        *puVar1 = *puVar1 & 0xffffffbf;
        return;
      }
    }
  }
  else {
    iVar9 = 0;
    pcVar6 = pcVar3;
    pcVar8 = pcVar3;
    do {
      if (((*pcVar6 != '\0') && (*(int *)(pcVar8 + 0x18) != 0)) &&
         (0 < *(int *)(*(int *)(pcVar8 + 0x18) + 0x48 + iVar9 * 4))) {
        return;
      }
      iVar9 = iVar9 + 1;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 4;
    } while (iVar9 != 4);
    iVar10 = *(int *)(*param_1 + 0x108) + 1;
    *(int *)(*param_1 + 0x108) = iVar10;
    for (iVar9 = *(int *)(*(int *)(pcVar3 + 8) + 0x38); iVar9 != 0;
        iVar9 = FUN_0010b180(iVar9,*(undefined4 *)(iVar9 + 0x84))) {
      *(int *)(iVar9 + 0x94) = iVar10;
      uVar4 = *(uint *)(iVar9 + 0x14);
      *(uint *)(iVar9 + 0x14) = uVar4 & 0xffffffbf;
      if ((uVar4 & 0x200) == 0) {
        return;
      }
    }
  }
  return;
}

/* FUN_0017493c @ 0x17493c (366 bytes) */
int FUN_0017493c(param_1, param_2)
  int param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte local_30;
  byte local_20;
  int local_14;
  
  iVar4 = 0;
  do {
    piVar1 = *(int **)(param_1 + 0x10 + iVar4 * 4);
    if (piVar1 == (int *)0x0) {
      *(int **)(param_1 + 0x10 + iVar4 * 4) = param_2;
      return param_2;
    }
    if (((*(int *)(piVar1[0x22] + 8) == *(int *)(param_2[0x22] + 8)) &&
        ((char)piVar1[0x48] == (char)param_2[0x48])) && (piVar1[0x49] == param_2[0x49])) {
      iVar2 = FUN_0010b0f4(param_2,0);
      iVar2 = *(int *)(iVar2 + 0x10);
      iVar3 = FUN_0010b0f4(piVar1,0);
      if (*(int *)(iVar3 + 0x10) == iVar2) {
        local_14 = 1;
        while( true ) {
          iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1);
          if (iVar2 < local_14) {
            return piVar1;
          }
          iVar2 = FUN_0010b180(piVar1,local_14);
          iVar3 = FUN_0010b180(param_2,local_14);
          if (iVar2 != iVar3) break;
          local_30 = (byte)piVar1[local_14 * 6 + 0x28] & 1;
          if ((local_30 != ((byte)param_2[local_14 * 6 + 0x28] & 1)) ||
             (local_20 = (byte)((uint)piVar1[local_14 * 6 + 0x28] >> 1) & 1,
             local_20 != ((byte)((uint)param_2[local_14 * 6 + 0x28] >> 1) & 1))) break;
          iVar2 = FUN_0010b0f4(param_2,local_14);
          iVar2 = *(int *)(iVar2 + 0x10);
          iVar3 = FUN_0010b0f4(piVar1,local_14);
          if (*(int *)(iVar3 + 0x10) != iVar2) break;
          local_14 = local_14 + 1;
        }
      }
    }
    iVar4 = iVar4 + 1;
    if (0x1f < iVar4) {
      return param_2;
    }
  } while( true );
}

/* FUN_00174aaa @ 0x174aaa (533 bytes) */
int FUN_00174aaa(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int local_24;
  int local_1c;
  int local_18;
  int local_10;
  
  local_24 = 1;
  iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
  if (0 < iVar2) {
    do {
      piVar3 = (int *)FUN_0010b180(param_1,local_24);
      cVar1 = (**(code **)(*param_1 + 0x60))(param_1);
      if ((cVar1 == '\0') && (cVar1 = (**(code **)(*piVar3 + 0x5c))(piVar3), cVar1 != '\0')) {
LAB_00174b3c:
        cVar1 = (**(code **)(*piVar3 + 0x60))(piVar3);
        if (cVar1 == '\0') {
          local_1c = (**(code **)(*piVar3 + 0x14))(piVar3);
          if (local_1c < 1) goto LAB_00174bc4;
        }
        else {
          local_1c = 1;
        }
        local_18 = 1;
        do {
          uVar5 = FUN_0010b180(piVar3,local_18);
          uVar6 = (**(code **)(*param_1 + 0x94))(param_1,uVar5,param_2);
          iVar2 = FUN_0010b0f4(piVar3,local_18);
          uVar5 = *(undefined4 *)(iVar2 + 0x10);
          iVar2 = FUN_0010b0f4(param_1,uVar6);
          *(undefined4 *)(iVar2 + 0x10) = uVar5;
          local_18 = local_18 + 1;
        } while (local_18 <= local_1c);
      }
      else {
        cVar1 = (**(code **)(*piVar3 + 0x60))(piVar3);
        if (cVar1 != '\0') {
          piVar4 = (int *)FUN_0010b180(piVar3,1);
          cVar1 = (**(code **)(*piVar4 + 0x5c))(piVar4);
          if (cVar1 == '\0') goto LAB_00174b3c;
        }
        cVar1 = (**(code **)(*piVar3 + 0x60))(piVar3);
        if (cVar1 != '\0') {
          piVar4 = (int *)FUN_0010b180(piVar3,1);
          cVar1 = (**(code **)(*piVar4 + 0x5c))(piVar4);
          if (cVar1 != '\0') {
            piVar3 = (int *)FUN_0010b180(piVar3,1);
            for (local_10 = 1; iVar2 = (**(code **)(*piVar3 + 0x14))(piVar3), local_10 <= iVar2;
                local_10 = local_10 + 1) {
              uVar5 = FUN_0010b180(piVar3,local_10);
              uVar6 = (**(code **)(*param_1 + 0x94))(param_1,uVar5,param_2);
              iVar2 = FUN_0010b0f4(piVar3,local_10);
              uVar5 = *(undefined4 *)(iVar2 + 0x10);
              iVar2 = FUN_0010b0f4(param_1,uVar6);
              *(undefined4 *)(iVar2 + 0x10) = uVar5;
            }
          }
        }
      }
LAB_00174bc4:
      local_24 = local_24 + 1;
      iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
    } while (local_24 <= iVar2);
  }
  return;
}

/* FUN_00174cc0 @ 0x174cc0 (468 bytes) */
int FUN_00174cc0(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *piVar7;
  char *pcVar8;
  uint *local_24;
  uint local_20;
  
  uVar6 = *(undefined4 *)(*param_1 + 0xbc);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar6,0x24);
  *puVar5 = uVar6;
  puVar1 = puVar5 + 1;
  puVar5[1] = 0;
  puVar5[2] = 0;
  puVar5[3] = 0;
  puVar5[4] = 1;
  puVar5[5] = 0;
  puVar5[6] = 0;
  puVar5[7] = DAT_001cc6f4;
  *(undefined1 *)(puVar5 + 8) = 0;
  puVar5[1] = param_2;
  puVar5[2] = param_3;
  uVar6 = ((int (*)())FUN_0017412a)(param_1,*(undefined4 *)(param_2 + 0x38),*(undefined4 *)(param_3 + 0x38),0,
                       param_4,0);
  puVar5[4] = uVar6;
  puVar5[5] = param_4;
  puVar5[6] = param_5;
  uVar4 = (**(code **)(*(int *)param_1[3] + 0x20))
                    ((int *)param_1[3],*(undefined4 *)(param_2 + 0x38));
  *(undefined1 *)(puVar5 + 8) = uVar4;
  puVar5[7] = param_6;
  puVar2 = *(uint **)(param_2 + 0x40);
  uVar3 = puVar2[1];
  if (uVar3 < *puVar2) {
    _memset((void *)(uVar3 * 4 + puVar2[2]),0,4);
    puVar2[1] = uVar3 + 1;
    *(undefined4 **)(uVar3 * 4 + puVar2[2]) = puVar1;
    local_24 = *(uint **)(param_3 + 0x44);
    local_20 = local_24[1];
    if (*local_24 <= local_20) {
LAB_00174e80:
      piVar7 = (int *)FUN_001a7f7c(local_24,local_20);
      goto LAB_00174e28;
    }
  }
  else {
    piVar7 = (int *)FUN_001a7f7c(puVar2,uVar3);
    *piVar7 = (int)puVar1;
    local_24 = *(uint **)(param_3 + 0x44);
    local_20 = local_24[1];
    if (*local_24 <= local_20) goto LAB_00174e80;
  }
  _memset((void *)(local_20 * 4 + local_24[2]),0,4);
  local_24[1] = local_20 + 1;
  piVar7 = (int *)(local_20 * 4 + local_24[2]);
LAB_00174e28:
  *piVar7 = (int)puVar1;
  pcVar8 = (char *)&param_6;
  do {
    if (*pcVar8 != '\0') {
      *(int *)(param_2 + 0x48) = *(int *)(param_2 + 0x48) + 1;
    }
    pcVar8 = pcVar8 + 1;
    param_2 = param_2 + 4;
  } while (pcVar8 != &STACKARG(0x1c));
  *(int *)(param_3 + 0x34) = *(int *)(param_3 + 0x34) + 1;
  return;
}

/* FUN_00174e94 @ 0x174e94 (645 bytes) */
int FUN_00174e94(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 *param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  
  uVar6 = *(undefined4 *)(param_1[6] + 4);
  *(undefined4 *)(param_2 + 0x150) = uVar6;
  uVar2 = *(undefined4 *)(*param_1 + 0xbc);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar2,0x70);
  *puVar5 = uVar2;
  puVar1 = puVar5 + 1;
  puVar5[1] = PTR_DAT_00213441 + 8;
  puVar5[2] = 0;
  puVar5[3] = 0;
  puVar5[1] = PTR_DAT_00213a31 + 8;
  puVar5[0xc] = 0xffffffff;
  puVar5[0xd] = 0;
  puVar5[0xe] = 0;
  puVar5[0xf] = param_2;
  puVar5[0x10] = uVar6;
  puVar5[0x11] = 0;
  puVar5[0x12] = 0;
  puVar5[0x17] = 0;
  *(undefined1 *)(puVar5 + 0x18) = 0;
  puVar5[0x19] = 0;
  *(undefined1 *)(puVar5 + 0x1a) = 0;
  *(undefined1 *)((int)puVar5 + 0x69) = 0;
  puVar5[0x1b] = 0;
  iVar9 = 4;
  puVar7 = puVar1;
  do {
    puVar7[0x12] = 0;
    puVar7 = puVar7 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  puVar5[4] = 0;
  puVar5[5] = 0;
  puVar5[6] = 1;
  puVar5[7] = 1;
  *(undefined1 *)(puVar5 + 8) = 0;
  puVar5[9] = 0;
  puVar5[10] = 0;
  puVar5[0xb] = 0;
  uVar6 = (**(code **)(*(int *)param_1[2] + 0x4c))((int *)param_1[2],param_2);
  puVar5[0x17] = uVar6;
  uVar6 = *(undefined4 *)(*param_1 + 0xbc);
  puVar7 = (undefined4 *)FUN_001a7bca(uVar6,0x14);
  *puVar7 = uVar6;
  puVar7[4] = uVar6;
  puVar7[2] = 0;
  puVar7[1] = 2;
  uVar6 = FUN_001a7bca(uVar6,8);
  puVar7[3] = uVar6;
  puVar5[0x12] = puVar7 + 1;
  uVar6 = *(undefined4 *)(*param_1 + 0xbc);
  puVar7 = (undefined4 *)FUN_001a7bca(uVar6,0x14);
  *puVar7 = uVar6;
  puVar7[4] = uVar6;
  puVar7[2] = 0;
  puVar7[1] = 2;
  uVar6 = FUN_001a7bca(uVar6,8);
  puVar7[3] = uVar6;
  puVar5[0x11] = puVar7 + 1;
  puVar5[0xc] = 0xffffffff;
  puVar5[0xe] = 0;
  puVar5[0xd] = param_4;
  puVar5[4] = *param_3;
  puVar5[5] = param_3[1];
  puVar5[6] = param_3[2];
  puVar5[9] = param_3[5];
  puVar5[10] = param_3[6];
  puVar5[0xb] = param_3[7];
  puVar3 = (uint *)param_1[6];
  uVar4 = puVar3[1];
  if (uVar4 < *puVar3) {
    _memset((void *)(uVar4 * 4 + puVar3[2]),0,4);
    puVar3[1] = uVar4 + 1;
    *(undefined4 **)(uVar4 * 4 + puVar3[2]) = puVar1;
    ((int (*)())FUN_00182640)(param_1[2],puVar1);
    return puVar1;
  }
  piVar8 = (int *)FUN_001a7f7c(puVar3,uVar4);
  *piVar8 = (int)puVar1;
  ((int (*)())FUN_00182640)(param_1[2],puVar1);
  return puVar1;
}

/* FUN_0017514e @ 0x17514e (1519 bytes) */
int FUN_0017514e(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int local_30;
  undefined1 uStack_21;
  undefined4 local_20;
  
  local_30 = *(int *)(param_1 + 0x98);
  while (*(int *)(local_30 + 8) != 0) {
    iVar1 = (**(code **)(**(int **)(local_30 + 0x38) + 0x14))(*(int **)(local_30 + 0x38));
    if (1 < iVar1) {
      iVar2 = 1;
      iVar1 = local_30;
      do {
        if (0 < *(int *)(iVar1 + 0x48)) {
          (&uStack_21)[iVar2] = 0;
        }
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 4;
        local_20 = DAT_001cc6f8;
      } while (iVar2 != 5);
    }
    iVar1 = *(int *)(local_30 + 8);
    FUN_001a7d72(local_30);
    local_30 = iVar1;
  }
  return 0;
}

/* FUN_0017573e @ 0x17573e (412 bytes) */
int FUN_0017573e(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int *piVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  uint *puVar10;
  uint uVar11;
  
  puVar10 = *(uint **)(param_2 + 0x44);
  uVar3 = puVar10[1];
  if ((int)uVar3 < 1) {
    return;
  }
  uVar11 = 0;
  while( true ) {
    if (uVar11 < *puVar10) {
      uVar4 = puVar10[1];
      if (uVar4 <= uVar11) {
        _memset((void *)(puVar10[2] + uVar4 * 4),0,(uVar11 - uVar4) * 4 + 4);
        puVar10[1] = uVar11 + 1;
      }
      piVar6 = *(int **)(puVar10[2] + uVar11 * 4);
      cVar2 = (char)piVar6[7];
    }
    else {
      piVar6 = (int *)FUN_001a7f7c(puVar10,uVar11);
      piVar6 = (int *)*piVar6;
      cVar2 = (char)piVar6[7];
    }
    if (cVar2 == '\x01') break;
    uVar11 = uVar11 + 1;
    if (uVar3 == uVar11) {
      return;
    }
    puVar10 = *(uint **)(param_2 + 0x44);
  }
  uVar5 = *(undefined4 *)(*param_1 + 0xbc);
  puVar7 = (undefined4 *)FUN_001a7bca(uVar5,0x24);
  *puVar7 = uVar5;
  puVar7[1] = 0;
  puVar7[2] = 0;
  puVar7[3] = 0;
  puVar7[4] = 1;
  puVar7[5] = 0;
  puVar7[6] = 0;
  puVar7[7] = DAT_001cc6f4;
  *(undefined1 *)(puVar7 + 8) = 0;
  puVar7[1] = *piVar6;
  puVar7[2] = param_3;
  puVar7[4] = piVar6[3];
  puVar7[7] = piVar6[6];
  iVar8 = 0;
  piVar9 = piVar6;
  do {
    if ((char)piVar9[6] != '\0') {
      piVar1 = (int *)(*piVar6 + 0x48 + iVar8 * 4);
      *piVar1 = *piVar1 + 1;
    }
    iVar8 = iVar8 + 1;
    piVar9 = (int *)((int)piVar9 + 1);
  } while (iVar8 != 4);
  *(undefined1 *)(puVar7 + 8) = 1;
  puVar10 = *(uint **)(param_3 + 0x44);
  uVar3 = puVar10[1];
  if (*puVar10 <= uVar3) {
    piVar6 = (int *)FUN_001a7f7c(puVar10,uVar3);
    *piVar6 = (int)(puVar7 + 1);
    return;
  }
  _memset((void *)(uVar3 * 4 + puVar10[2]),0,4);
  puVar10[1] = uVar3 + 1;
  *(undefined4 **)(uVar3 * 4 + puVar10[2]) = puVar7 + 1;
  return;
}

/* FUN_001758da @ 0x1758da (370 bytes) */
int FUN_001758da(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint *puVar7;
  uint uVar8;
  uint local_1c;
  
  puVar7 = *(uint **)(param_2 + 0x40);
  uVar1 = puVar7[1];
  if ((int)uVar1 < 1) {
    return 0;
  }
  local_1c = 0;
  if (*puVar7 == 0) goto LAB_001759ac;
  do {
    uVar2 = puVar7[1];
    if (uVar2 <= local_1c) {
      _memset((void *)(puVar7[2] + uVar2 * 4),0,(local_1c - uVar2) * 4 + 4);
      puVar7[1] = local_1c + 1;
    }
    piVar6 = (int *)(puVar7[2] + local_1c * 4);
    while( true ) {
      iVar3 = *piVar6;
      if (*(int *)(iVar3 + 8) == 0) {
        iVar4 = *(int *)(iVar3 + 4);
        puVar7 = *(uint **)(iVar4 + 0x44);
        uVar2 = puVar7[1];
        if (0 < (int)uVar2) {
          uVar8 = 0;
          while( true ) {
            if (uVar8 < *puVar7) {
              uVar5 = puVar7[1];
              if (uVar5 <= uVar8) {
                _memset((void *)(puVar7[2] + uVar5 * 4),0,(uVar8 - uVar5) * 4 + 4);
                puVar7[1] = uVar8 + 1;
              }
              piVar6 = (int *)(puVar7[2] + uVar8 * 4);
            }
            else {
              piVar6 = (int *)FUN_001a7f7c(puVar7,uVar8);
            }
            piVar6 = (int *)*piVar6;
            if ((((piVar6[2] == 0) && (param_2 != *piVar6)) && (piVar6[4] == *(int *)(iVar3 + 0x10))
                ) && ((piVar6[5] == *(int *)(iVar3 + 0x14) &&
                      ((*(byte *)(*(int *)(*piVar6 + 0x38) + 0x14) & 0x40) != 0)))) {
              return 1;
            }
            uVar8 = uVar8 + 1;
            if (uVar2 == uVar8) break;
            puVar7 = *(uint **)(iVar4 + 0x44);
          }
        }
      }
      local_1c = local_1c + 1;
      if (uVar1 == local_1c) {
        return 0;
      }
      puVar7 = *(uint **)(param_2 + 0x40);
      if (local_1c < *puVar7) break;
LAB_001759ac:
      piVar6 = (int *)FUN_001a7f7c(puVar7,local_1c);
    }
  } while( true );
}

/* FUN_00175a4c @ 0x175a4c (260 bytes) */
int FUN_00175a4c(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  int *piVar6;
  uint *puVar7;
  uint uVar8;
  
  if (*(int *)(param_1 + 0x28) < *(int *)(param_2 + 0x30)) {
    return 0;
  }
  cVar5 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))
                    (*(int **)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38));
  if (cVar5 != '\0') {
    puVar7 = *(uint **)(param_2 + 0x44);
    uVar1 = puVar7[1];
    if (0 < (int)uVar1) {
      uVar8 = 0;
      while( true ) {
        if (uVar8 < *puVar7) {
          uVar2 = puVar7[1];
          if (uVar2 <= uVar8) {
            _memset((void *)(puVar7[2] + uVar2 * 4),0,(uVar8 - uVar2) * 4 + 4);
            puVar7[1] = uVar8 + 1;
          }
          piVar6 = (int *)(puVar7[2] + uVar8 * 4);
        }
        else {
          piVar6 = (int *)FUN_001a7f7c(puVar7,uVar8);
        }
        piVar6 = (int *)*piVar6;
        if (piVar6[2] == 0) {
          iVar3 = *piVar6;
          iVar4 = *(int *)(iVar3 + 0x38);
          if ((((*(int *)(iVar4 + 0x158) == *(int *)(param_1 + 0x10)) &&
               (cVar5 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))
                                  (*(int **)(param_1 + 0xc),iVar4), cVar5 != '\0')) &&
              ((char)piVar6[7] != '\0')) && (*(int *)(param_1 + 0x120) <= *(int *)(iVar3 + 0x2c))) {
            return 0;
          }
        }
        uVar8 = uVar8 + 1;
        if (uVar1 == uVar8) break;
        puVar7 = *(uint **)(param_2 + 0x44);
      }
    }
  }
  return 1;
}

/* FUN_00175b50 @ 0x175b50 (180 bytes) */
int FUN_00175b50(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  uint uVar7;
  int local_10;
  
  local_10 = *(int *)(param_1 + 0x2c);
  puVar6 = *(uint **)(param_1 + 0x40);
  uVar1 = puVar6[1];
  if (0 < (int)uVar1) {
    uVar7 = 0;
    while( true ) {
      if (uVar7 < *puVar6) {
        uVar2 = puVar6[1];
        if (uVar2 <= uVar7) {
          _memset((void *)(puVar6[2] + uVar2 * 4),0,(uVar7 - uVar2) * 4 + 4);
          puVar6[1] = uVar7 + 1;
        }
        piVar5 = (int *)(puVar6[2] + uVar7 * 4);
      }
      else {
        piVar5 = (int *)FUN_001a7f7c(puVar6,uVar7);
      }
      uVar7 = uVar7 + 1;
      iVar3 = *piVar5;
      iVar4 = local_10;
      if (((*(int *)(iVar3 + 8) == 0) && (*(char *)(param_2 + 0x18 + iVar3) != '\0')) &&
         (iVar4 = *(int *)(*(int *)(iVar3 + 4) + 0x2c), iVar4 <= local_10)) {
        iVar4 = local_10;
      }
      local_10 = iVar4;
      if (uVar1 == uVar7) break;
      puVar6 = *(uint **)(param_1 + 0x40);
    }
  }
  return local_10;
}

/* FUN_00175c04 @ 0x175c04 (648 bytes) */
int FUN_00175c04(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint local_50;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  int local_2c;
  char *local_28;
  int *local_24;
  int local_20;
  uint local_10;
  
  if (param_2 == 1) {
    piVar7 = *(int **)(*param_1 + 0x54);
    local_40 = (**(code **)(*piVar7 + 0x138))(piVar7,*param_1);
    uVar3 = param_1[0x50];
    local_3c = local_40 + param_1[0x66];
  }
  else {
    piVar7 = *(int **)(*param_1 + 0x54);
    uVar3 = (**(code **)(*piVar7 + 0x138))(piVar7,*param_1);
    local_3c = param_1[0x65];
    local_40 = 0;
  }
  if ((int)local_40 < (int)uVar3) {
    local_20 = local_40 << 2;
    local_34 = 4;
    local_38 = 0xffffffff;
    uVar8 = local_40;
    do {
      uVar4 = *(uint *)(param_1[0x4b] + 8 + (uVar8 >> 5) * 4) >> ((byte)uVar8 & 0x1f);
      if (((uVar4 & 1) != 0) && (local_3c < (int)uVar8)) {
        if ((int)local_38 < 0) {
          local_38 = uVar8;
        }
        break;
      }
      iVar6 = 0;
      local_50 = 0;
      piVar7 = param_1;
      do {
        iVar5 = *(int *)(piVar7[0x4c] + local_20);
        if (((iVar5 != 0) && (0 < *(int *)(iVar5 + 0x48 + iVar6 * 4))) &&
           (*(uint **)(iVar5 + 0x60) != (uint *)0x0)) {
          local_50 = local_50 | **(uint **)(iVar5 + 0x60);
        }
        iVar6 = iVar6 + 1;
        piVar7 = piVar7 + 1;
      } while (iVar6 != 4);
      local_10 = local_50;
      if ((uVar4 & 1) != 0) {
        local_24 = param_1;
        iVar6 = 0;
        local_2c = 0;
        local_28 = &STACKARG(0xc);
        do {
          if ((*(char *)((int)&local_10 + iVar6) == '\0') &&
             ((*(int *)(local_24[0x4c] + local_20) == 0 ||
              (*(int *)(*(int *)(local_24[0x4c] + local_20) + 0x48 + iVar6 * 4) < 1)))) {
            local_2c = local_2c + (uint)(*local_28 == '\0');
LAB_00175d5d:
            if (((*local_28 != '\0') && (iVar5 = *(int *)(param_1[1] + 0x38), iVar5 != 0)) &&
               ((*(uint *)(iVar5 + 0x94) == uVar8 &&
                ((((cVar2 = FUN_000f5990(iVar5,iVar6), cVar2 != '\0' &&
                   (iVar5 = *(int *)(local_24[0x4c] + local_20), iVar5 != 0)) &&
                  (*(int *)(iVar5 + 0x38) == *(int *)(param_1[1] + 0x38))) &&
                 (iVar5 = ((int (*)())FUN_00175b50)(iVar5,iVar6), iVar5 == param_1[10])))))) goto LAB_00175dc6;
            bVar1 = true;
          }
          else {
            if (*local_28 == '\0') goto LAB_00175d5d;
LAB_00175dc6:
            bVar1 = false;
          }
          iVar6 = iVar6 + 1;
          if (!bVar1) goto LAB_00175df8;
          local_28 = local_28 + 1;
          local_24 = local_24 + 1;
        } while (iVar6 != 4);
        if (((int)local_38 < 0) || (local_2c < local_34)) {
          local_34 = local_2c;
          local_38 = uVar8;
        }
      }
LAB_00175df8:
      uVar8 = uVar8 + 1;
      local_20 = local_20 + 4;
    } while (uVar3 != uVar8);
  }
  else {
    local_38 = 0xffffffff;
  }
  if (param_2 == 1) {
    iVar6 = param_1[0x66];
    if (param_1[0x66] < (int)(local_38 - local_40)) {
      iVar6 = local_38 - local_40;
    }
    param_1[0x66] = iVar6;
    return local_38;
  }
  iVar6 = param_1[0x65];
  if (param_1[0x65] < (int)(local_38 - local_40)) {
    iVar6 = local_38 - local_40;
  }
  param_1[0x65] = iVar6;
  return local_38;
}

/* FUN_00175e8c @ 0x175e8c (1073 bytes) */
int FUN_00175e8c(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  uint *puVar7;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  
  FUN_001a7c84(param_1 + 0x30);
  FUN_001a7c84(param_1 + 0x48);
  FUN_001a7c84(param_1 + 0x60);
  FUN_001a7c84(param_1 + 0x78);
  FUN_001a7d22(param_1 + 0x90);
  puVar7 = *(uint **)(param_1 + 0x18);
  uVar1 = puVar7[1];
  if (0 < (int)uVar1) {
    local_2c = 0;
    if (*puVar7 == 0) goto LAB_00176027;
    do {
      uVar2 = puVar7[1];
      if (uVar2 <= local_2c) {
        _memset((void *)(puVar7[2] + uVar2 * 4),0,(local_2c - uVar2) * 4 + 4);
        puVar7[1] = local_2c + 1;
      }
      piVar6 = (int *)(puVar7[2] + local_2c * 4);
      while( true ) {
        local_2c = local_2c + 1;
        piVar6 = (int *)*piVar6;
        *(undefined4 *)(piVar6[0xe] + 0x150) = 0;
        puVar7 = (uint *)piVar6[0x10];
        uVar2 = puVar7[1];
        if (0 < (int)uVar2) {
          local_28 = 0;
          while( true ) {
            if (local_28 < *puVar7) {
              uVar4 = puVar7[1];
              if (uVar4 <= local_28) {
                _memset((void *)(puVar7[2] + uVar4 * 4),0,(local_28 - uVar4) * 4 + 4);
                puVar7[1] = local_28 + 1;
              }
              piVar5 = (int *)(puVar7[2] + local_28 * 4);
            }
            else {
              piVar5 = (int *)FUN_001a7f7c(puVar7,local_28);
            }
            local_28 = local_28 + 1;
            iVar3 = *piVar5;
            if (iVar3 != 0) {
              FUN_001a7aba(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
            }
            if (uVar2 == local_28) break;
            puVar7 = (uint *)piVar6[0x10];
          }
        }
        if (piVar6[0x18] != 0) {
          piVar5 = (int *)(piVar6[0x18] + 0x10);
          *piVar5 = *piVar5 + -1;
          iVar3 = piVar6[0x18];
          if ((*(int *)(iVar3 + 0x10) < 1) && (iVar3 != 0)) {
            FUN_001a7aba(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
          }
        }
        iVar3 = piVar6[0x10];
        if (iVar3 != 0) {
          FUN_001a7aba(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
          FUN_001a7aba(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
        }
        iVar3 = piVar6[0x11];
        if (iVar3 != 0) {
          FUN_001a7aba(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
          FUN_001a7aba(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
        }
        (**(code **)(*piVar6 + 4))(piVar6);
        if (uVar1 == local_2c) goto LAB_00176071;
        puVar7 = *(uint **)(param_1 + 0x18);
        if (local_2c < *puVar7) break;
LAB_00176027:
        piVar6 = (int *)FUN_001a7f7c(puVar7,local_2c);
      }
    } while( true );
  }
LAB_00176071:
  puVar7 = *(uint **)(param_1 + 0x14);
  uVar1 = puVar7[1];
  if ((int)uVar1 < 1) {
LAB_0017624d:
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 4) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x14) + 4) = 0;
    return;
  }
  local_30 = 0;
  if (*puVar7 == 0) goto LAB_001761b1;
  do {
    uVar2 = puVar7[1];
    if (uVar2 <= local_30) {
      _memset((void *)(puVar7[2] + uVar2 * 4),0,(local_30 - uVar2) * 4 + 4);
      puVar7[1] = local_30 + 1;
    }
    piVar6 = (int *)(puVar7[2] + local_30 * 4);
    while( true ) {
      local_30 = local_30 + 1;
      piVar6 = (int *)*piVar6;
      puVar7 = (uint *)piVar6[0x10];
      uVar2 = puVar7[1];
      if (0 < (int)uVar2) {
        local_34 = 0;
        while( true ) {
          if (local_34 < *puVar7) {
            uVar4 = puVar7[1];
            if (uVar4 <= local_34) {
              _memset((void *)(puVar7[2] + uVar4 * 4),0,(local_34 - uVar4) * 4 + 4);
              puVar7[1] = local_34 + 1;
            }
            piVar5 = (int *)(puVar7[2] + local_34 * 4);
          }
          else {
            piVar5 = (int *)FUN_001a7f7c(puVar7,local_34);
          }
          local_34 = local_34 + 1;
          iVar3 = *piVar5;
          if (iVar3 != 0) {
            FUN_001a7aba(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
          }
          if (uVar2 == local_34) break;
          puVar7 = (uint *)piVar6[0x10];
        }
      }
      if (piVar6[0x18] != 0) {
        piVar5 = (int *)(piVar6[0x18] + 0x10);
        *piVar5 = *piVar5 + -1;
        iVar3 = piVar6[0x18];
        if ((*(int *)(iVar3 + 0x10) < 1) && (iVar3 != 0)) {
          FUN_001a7aba(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
        }
      }
      iVar3 = piVar6[0x10];
      if (iVar3 != 0) {
        FUN_001a7aba(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
        FUN_001a7aba(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
      }
      iVar3 = piVar6[0x11];
      if (iVar3 != 0) {
        FUN_001a7aba(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
        FUN_001a7aba(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
      }
      (**(code **)(*piVar6 + 4))(piVar6);
      if (uVar1 == local_30) goto LAB_0017624d;
      puVar7 = *(uint **)(param_1 + 0x14);
      if (local_30 < *puVar7) break;
LAB_001761b1:
      piVar6 = (int *)FUN_001a7f7c(puVar7,local_30);
    }
  } while( true );
}

/* FUN_001762be @ 0x1762be (2371 bytes) */
int FUN_001762be(param_1)
  int *param_1;
{
  uint *puVar1;
  bool bVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  byte local_84;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_68;
  int local_64;
  int local_5c;
  int local_38;
  int local_34;
  uint *local_30;
  int local_28;
  int local_24;
  int local_20 [5];
  
  iVar11 = *(int *)(param_1[6] + 4);
  uVar10 = *(undefined4 *)(*param_1 + 0xbc);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar10,0x10);
  puVar1 = puVar5 + 1;
  *puVar5 = uVar10;
  puVar5[2] = 0x20;
  puVar5[1] = 1;
  puVar5[3] = 0;
  iVar6 = FUN_001a7bca(*(undefined4 *)(*param_1 + 0xbc),iVar11 * 4);
  if (*puVar1 != 0) {
    uVar12 = 0;
    uVar15 = *puVar1;
    puVar7 = puVar1;
    do {
      puVar7[2] = 0;
      uVar12 = uVar12 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar12 < uVar15);
  }
  ((int (*)())FUN_001825e0)(param_1[2]);
  iVar8 = 0;
  do {
    local_20[iVar8 + 1] = 0;
    iVar8 = iVar8 + 1;
  } while (iVar8 != 4);
  local_68 = iVar11 - 1;
  if ((int)local_68 < 0) {
    local_64 = 0;
    local_5c = 0;
    bVar2 = false;
  }
  else {
    local_28 = local_68 * 4;
    local_34 = local_28 + 4;
    local_30 = (uint *)(iVar6 + local_28);
    local_5c = 0;
    bVar2 = false;
    local_64 = 0;
    do {
      puVar7 = (uint *)param_1[6];
      if (local_68 < *puVar7) {
        uVar15 = puVar7[1];
        if (uVar15 <= local_68) {
          _memset((void *)(puVar7[2] + uVar15 * 4),0,(local_68 - uVar15) * 4 + 4);
          puVar7[1] = local_68 + 1;
        }
        piVar9 = (int *)(local_28 + puVar7[2]);
      }
      else {
        piVar9 = (int *)FUN_001a7f7c(puVar7,local_68);
      }
      local_74 = local_68 + 1;
      iVar11 = *piVar9;
      cVar3 = FUN_000e1402(*param_1,0x28);
      if ((cVar3 == '\0') ||
         (cVar3 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar11), cVar3 == '\0')
         ) {
        uVar4 = 0;
      }
      else {
        uVar4 = 1;
      }
      *(undefined1 *)(iVar11 + 0x5c) = uVar4;
      uVar10 = (**(code **)(*(int *)param_1[2] + 0x4c))
                         ((int *)param_1[2],*(undefined4 *)(iVar11 + 0x38));
      *(undefined4 *)(iVar11 + 0x58) = uVar10;
      (**(code **)(*(int *)param_1[2] + 0x48))((int *)param_1[2],iVar11);
      (**(code **)(*(int *)param_1[2] + 0x44))((int *)param_1[2],iVar11);
      ((int (*)())FUN_00182640)(param_1[2],iVar11);
      *local_30 = 0;
      puVar7 = *(uint **)(iVar11 + 0x40);
      uVar15 = puVar7[1];
      if (0 < (int)uVar15) {
        local_70 = 0;
        while( true ) {
          if (local_70 < *puVar7) {
            uVar12 = puVar7[1];
            if (uVar12 <= local_70) {
              _memset((void *)(puVar7[2] + uVar12 * 4),0,(local_70 - uVar12) * 4 + 4);
              puVar7[1] = local_70 + 1;
            }
            piVar9 = (int *)(puVar7[2] + local_70 * 4);
          }
          else {
            piVar9 = (int *)FUN_001a7f7c(puVar7,local_70);
          }
          local_70 = local_70 + 1;
          iVar8 = *piVar9;
          iVar14 = *(int *)(iVar8 + 4);
          *(int *)(iVar14 + 0x34) = *(int *)(iVar14 + 0x34) + 1;
          iVar13 = *(int *)(iVar8 + 0xc) + *(int *)(iVar14 + 0x14);
          iVar8 = *(int *)(iVar11 + 0x14);
          if (*(int *)(iVar11 + 0x14) < iVar13) {
            iVar8 = iVar13;
          }
          *(int *)(iVar11 + 0x14) = iVar8;
          iVar8 = *(int *)(iVar14 + 0x3c);
          if ((int)local_68 < iVar8) {
            uVar12 = *(int *)(iVar6 + iVar8 * 4) << ((char)iVar8 - (byte)local_68 & 0x1f) |
                     *local_30;
            *local_30 = uVar12;
            *local_30 = uVar12 | 1 << (~(byte)local_68 + (char)*(undefined4 *)(iVar14 + 0x3c) & 0x1f
                                      );
          }
          if (uVar15 == local_70) break;
          puVar7 = *(uint **)(iVar11 + 0x40);
        }
      }
      iVar8 = *(int *)(iVar11 + 0xc);
      if (local_5c < iVar8) {
        local_5c = iVar8;
      }
      if (local_5c < *(int *)(*(int *)(*param_1 + 0x54) + 0x54)) {
        cVar3 = (**(code **)(*(int *)param_1[3] + 0x20))
                          ((int *)param_1[3],*(undefined4 *)(iVar11 + 0x38));
        if (cVar3 != '\0') goto LAB_0017656a;
LAB_001769c7:
        cVar3 = (**(code **)(*(int *)param_1[3] + 0x24))
                          ((int *)param_1[3],*(undefined4 *)(iVar11 + 0x38));
        if (cVar3 != '\0') goto LAB_0017656a;
      }
      else {
        FUN_000e27ca(*param_1,0xf);
        cVar3 = (**(code **)(*(int *)param_1[3] + 0x20))
                          ((int *)param_1[3],*(undefined4 *)(iVar11 + 0x38));
        if (cVar3 == '\0') goto LAB_001769c7;
LAB_0017656a:
        if (iVar8 < 4) {
          local_20[iVar8 + 1] = local_20[iVar8 + 1] + 1;
        }
        if (0 < iVar8) {
          bVar2 = true;
        }
        param_1[100] = param_1[100] + 1;
        cVar3 = (**(code **)(**(int **)(iVar11 + 0x38) + 0x30))(*(int **)(iVar11 + 0x38));
        if (cVar3 != '\0') {
          uVar15 = *(uint *)(*(int *)(iVar11 + 0x38) + 0x134);
          if ((int)uVar15 < 0x20) {
            if ((int)uVar15 < 0) goto LAB_001765cf;
          }
          else {
            FUN_000e27ca(*param_1,0xf);
          }
          puVar5[(uVar15 >> 5) + 3] = puVar5[(uVar15 >> 5) + 3] | 1 << ((byte)uVar15 & 0x1f);
        }
      }
LAB_001765cf:
      *(uint *)(iVar11 + 0x10) = local_68;
      if ((*(char *)(iVar11 + 0x1c) == '\0') &&
         (cVar3 = (**(code **)(*(int *)param_1[2] + 0x28))
                            ((int *)param_1[2],*(undefined4 *)(iVar11 + 0x38)), cVar3 == '\0')) {
        *(undefined1 *)(iVar11 + 0x1c) = 0;
        puVar7 = *(uint **)(iVar11 + 0x44);
        uVar15 = puVar7[1];
      }
      else {
        *(undefined1 *)(iVar11 + 0x1c) = 1;
        puVar7 = *(uint **)(iVar11 + 0x44);
        uVar15 = puVar7[1];
      }
      if (0 < (int)uVar15) {
        local_78 = 0;
        if (*puVar7 == 0) goto LAB_001766ac;
        do {
          uVar12 = puVar7[1];
          if (uVar12 <= local_78) {
            _memset((void *)(puVar7[2] + uVar12 * 4),0,(local_78 - uVar12) * 4 + 4);
            puVar7[1] = local_78 + 1;
          }
          piVar9 = (int *)(puVar7[2] + local_78 * 4);
          while( true ) {
            local_78 = local_78 + 1;
            piVar9 = (int *)*piVar9;
            if (piVar9[2] == 0) {
              iVar8 = *piVar9;
              iVar13 = 0;
              iVar14 = iVar8;
              do {
                if ((char)piVar9[6] != '\0') {
                  *(int *)(iVar14 + 0x48) = *(int *)(iVar14 + 0x48) + 1;
                }
                iVar13 = iVar13 + 1;
                piVar9 = (int *)((int)piVar9 + 1);
                iVar14 = iVar14 + 4;
              } while (iVar13 != 4);
              if ((*(char *)(iVar8 + 0x1c) == '\0') && (*(char *)(iVar11 + 0x1c) == '\0')) {
                *(undefined1 *)(iVar8 + 0x1c) = 0;
                cVar3 = (**(code **)(*(int *)param_1[3] + 0x20))
                                  ((int *)param_1[3],*(undefined4 *)(iVar11 + 0x38));
              }
              else {
                *(undefined1 *)(iVar8 + 0x1c) = 1;
                cVar3 = (**(code **)(*(int *)param_1[3] + 0x20))
                                  ((int *)param_1[3],*(undefined4 *)(iVar11 + 0x38));
              }
              if ((cVar3 == '\0') &&
                 (cVar3 = (**(code **)(*(int *)param_1[3] + 0x24))
                                    ((int *)param_1[3],*(undefined4 *)(iVar11 + 0x38)),
                 cVar3 == '\0')) {
                iVar14 = *(int *)(iVar8 + 0xc);
                if (*(int *)(iVar8 + 0xc) < *(int *)(iVar11 + 0xc)) {
                  iVar14 = *(int *)(iVar11 + 0xc);
                }
                *(int *)(iVar8 + 0xc) = iVar14;
              }
              else {
                iVar13 = *(int *)(iVar11 + 0xc) + 1;
                iVar14 = *(int *)(iVar8 + 0xc);
                if (*(int *)(iVar8 + 0xc) < iVar13) {
                  iVar14 = iVar13;
                }
                *(int *)(iVar8 + 0xc) = iVar14;
              }
            }
            if (uVar15 == local_78) goto LAB_001766fa;
            puVar7 = *(uint **)(iVar11 + 0x44);
            if (local_78 < *puVar7) break;
LAB_001766ac:
            piVar9 = (int *)FUN_001a7f7c(puVar7,local_78);
          }
        } while( true );
      }
LAB_001766fa:
      local_38 = local_34;
      local_20[0] = 0;
      do {
        while ((*local_30 & 1 << ((byte)local_20[0] & 0x1f)) != 0) {
          puVar7 = (uint *)param_1[6];
          if (local_74 < *puVar7) {
            uVar15 = puVar7[1];
            if (uVar15 <= local_74) {
              _memset((void *)(puVar7[2] + uVar15 * 4),0,(local_74 - uVar15) * 4 + 4);
              puVar7[1] = local_74 + 1;
            }
            piVar9 = (int *)(local_38 + puVar7[2]);
          }
          else {
            piVar9 = (int *)FUN_001a7f7c(puVar7,local_74);
          }
          local_74 = local_74 + 1;
          if (*(char *)(*piVar9 + 0x5c) == '\0') {
            iVar8 = *(int *)(*piVar9 + 0x58);
            if (iVar8 == 1) {
              *(int *)(iVar11 + 0x24) = *(int *)(iVar11 + 0x24) + 1;
            }
            else if (iVar8 == 2) {
              *(int *)(iVar11 + 0x28) = *(int *)(iVar11 + 0x28) + 1;
            }
          }
          else {
            *(int *)(iVar11 + 0x20) = *(int *)(iVar11 + 0x20) + 1;
          }
          local_20[0] = local_20[0] + 1;
          local_38 = local_38 + 4;
          if (local_20[0] == 0x20) goto LAB_00176776;
        }
        local_74 = local_74 + 1;
        local_20[0] = local_20[0] + 1;
        local_38 = local_38 + 4;
      } while (local_20[0] != 0x20);
LAB_00176776:
      iVar8 = *(int *)(iVar11 + 0x14);
      if (*(int *)(iVar11 + 0x14) <= local_64) {
        iVar8 = local_64;
      }
      local_68 = local_68 - 1;
      local_34 = local_34 + -4;
      local_30 = local_30 + -1;
      local_28 = local_28 + -4;
      local_64 = iVar8;
    } while (local_68 != 0xffffffff);
  }
  iVar8 = (**(code **)(*(int *)param_1[2] + 0x5c))((int *)param_1[2]);
  *(bool *)((int)param_1 + 0x21) = local_64 <= iVar8;
  param_1[0x43] = local_64;
  param_1[0x44] = iVar8;
  iVar11 = *(int *)(*(int *)(*param_1 + 0x54) + 0x54);
  if (iVar11 < 5) {
    if (-1 < local_5c) {
      local_24 = 1;
      if (0 < local_5c) {
        do {
          piVar9 = local_20 + local_24 + 1;
          iVar14 = local_24;
          do {
            iVar13 = local_20[local_24];
            if (iVar13 < *piVar9) {
              local_20[local_24] = *piVar9;
              *piVar9 = iVar13;
            }
            iVar14 = iVar14 + 1;
            piVar9 = piVar9 + 1;
          } while (iVar14 <= local_5c);
          local_24 = local_24 + 1;
        } while (local_24 <= local_5c);
      }
    }
    iVar11 = iVar11 - local_5c;
    if (iVar11 + -1 < 1) {
      param_1[9] = local_20[1];
    }
    else {
      iVar14 = local_20[1] / iVar11;
      if (local_20[1] / iVar11 <= local_20[2]) {
        iVar14 = local_20[2];
      }
      param_1[9] = iVar14;
      if (iVar11 * iVar14 < local_20[1]) {
        param_1[9] = iVar14 + 1;
      }
      if ((iVar11 + -1 == 2) && (local_20[1] < local_20[2] * 2)) {
        iVar11 = local_20[1] / 2;
        if (local_20[1] / 2 <= local_20[3]) {
          iVar11 = local_20[3];
        }
        if (iVar11 * 2 < local_20[1]) {
          iVar11 = iVar11 + 1;
        }
        if (iVar11 < param_1[9]) {
          param_1[9] = iVar11;
        }
      }
    }
    cVar3 = (**(code **)(*(int *)param_1[2] + 0x58))((int *)param_1[2],local_20[1],local_64,iVar8);
    *(char *)(param_1 + 8) = cVar3;
    if (cVar3 == '\0') {
      if ((bVar2) && (puVar5[2] != 0)) {
        uVar15 = 0;
        uVar12 = 0;
        do {
          local_84 = (byte)uVar15 & 0x1f;
          uVar12 = (uVar12 + 1) - (uint)(((uint)puVar5[(uVar15 >> 5) + 3] >> local_84 & 1) == 0);
          uVar15 = uVar15 + 1;
        } while (uVar15 != puVar5[2]);
        if (6 < uVar12) {
          iVar11 = param_1[9];
          if (iVar11 < 1) {
            iVar11 = 1;
          }
          param_1[9] = iVar11;
          goto LAB_00176825;
        }
      }
      iVar11 = param_1[9];
      if (iVar11 < 0x400) {
        iVar11 = 0x400;
      }
      param_1[9] = iVar11;
    }
    else {
      iVar11 = param_1[9];
      if (iVar11 < 1) {
        iVar11 = 1;
      }
      param_1[9] = iVar11;
    }
  }
  else {
    param_1[9] = 8;
    iVar11 = 0;
    iVar14 = 1;
    do {
      if (iVar11 < local_20[iVar14]) {
        iVar11 = local_20[iVar14];
      }
      iVar14 = iVar14 + 1;
    } while (iVar14 != 5);
    uVar4 = (**(code **)(*(int *)param_1[2] + 0x58))((int *)param_1[2],iVar11,local_64,iVar8);
    *(undefined1 *)(param_1 + 8) = uVar4;
  }
LAB_00176825:
  if (puVar1 != (uint *)0x0) {
    FUN_001a7aba(*puVar5,puVar5);
  }
  FUN_001a7aba(*(undefined4 *)(*param_1 + 0xbc),iVar6);
  return;
}

/* FUN_00176c02 @ 0x176c02 (763 bytes) */
int FUN_00176c02(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  undefined4 *local_24;
  
  puVar9 = (uint *)param_1[5];
  if (puVar9[1] != 0) {
    uVar10 = 0;
    do {
      if (uVar10 < *puVar9) {
        uVar2 = puVar9[1];
        puVar8 = puVar9;
        if (uVar2 <= uVar10) {
          _memset((void *)(puVar9[2] + uVar2 * 4),0,(uVar10 - uVar2) * 4 + 4);
          puVar9[1] = uVar10 + 1;
          puVar8 = (uint *)param_1[5];
        }
        iVar7 = *(int *)(*(int *)(puVar9[2] + uVar10 * 4) + 0x38);
        puVar9 = puVar8;
      }
      else {
        piVar3 = (int *)FUN_001a7f7c(puVar9,uVar10);
        puVar9 = (uint *)param_1[5];
        iVar7 = *(int *)(*piVar3 + 0x38);
      }
      if (param_2 == iVar7) {
        if (uVar10 < *puVar9) {
          uVar2 = puVar9[1];
          if (uVar2 <= uVar10) {
            _memset((void *)(puVar9[2] + uVar2 * 4),0,(uVar10 - uVar2) * 4 + 4);
            puVar9[1] = uVar10 + 1;
          }
          local_24 = *(undefined4 **)(puVar9[2] + uVar10 * 4);
        }
        else {
          local_24 = (undefined4 *)FUN_001a7f7c(puVar9,uVar10);
          local_24 = (undefined4 *)*local_24;
        }
        return local_24;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < puVar9[1]);
  }
  uVar10 = puVar9[1];
  uVar6 = *(undefined4 *)(*param_1 + 0xbc);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar6,0x70);
  *puVar4 = uVar6;
  puVar1 = puVar4 + 1;
  puVar4[1] = PTR_DAT_00213441 + 8;
  puVar4[2] = 0;
  puVar4[3] = 0;
  puVar4[1] = PTR_DAT_00213a31 + 8;
  puVar4[0xc] = 0xffffffff;
  puVar4[0xd] = 0;
  puVar4[0xe] = 0;
  puVar4[0xf] = param_2;
  puVar4[0x10] = uVar10;
  puVar4[0x11] = 0;
  puVar4[0x12] = 0;
  puVar4[0x17] = 0;
  *(undefined1 *)(puVar4 + 0x18) = 0;
  puVar4[0x19] = 0;
  *(undefined1 *)(puVar4 + 0x1a) = 0;
  *(undefined1 *)((int)puVar4 + 0x69) = 0;
  puVar4[0x1b] = 0;
  iVar7 = 4;
  puVar5 = puVar1;
  do {
    puVar5[0x12] = 0;
    puVar5 = puVar5 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar4[4] = 0;
  puVar4[5] = 0;
  puVar4[6] = 1;
  puVar4[7] = 1;
  *(undefined1 *)(puVar4 + 8) = 0;
  puVar4[9] = 0;
  puVar4[10] = 0;
  puVar4[0xb] = 0;
  uVar6 = *(undefined4 *)(*param_1 + 0xbc);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar6,0x14);
  *puVar5 = uVar6;
  puVar5[4] = uVar6;
  puVar5[2] = 0;
  puVar5[1] = 2;
  uVar6 = FUN_001a7bca(uVar6,8);
  puVar5[3] = uVar6;
  puVar4[0x12] = puVar5 + 1;
  uVar6 = *(undefined4 *)(*param_1 + 0xbc);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar6,0x14);
  *puVar5 = uVar6;
  puVar5[4] = uVar6;
  puVar5[2] = 0;
  puVar5[1] = 2;
  uVar6 = FUN_001a7bca(uVar6,8);
  puVar5[3] = uVar6;
  puVar4[0x11] = puVar5 + 1;
  puVar4[0xc] = 0;
  puVar9 = (uint *)param_1[5];
  uVar10 = puVar9[1];
  if (uVar10 < *puVar9) {
    _memset((void *)(uVar10 * 4 + puVar9[2]),0,4);
    puVar9[1] = uVar10 + 1;
    piVar3 = (int *)(uVar10 * 4 + puVar9[2]);
  }
  else {
    piVar3 = (int *)FUN_001a7f7c(puVar9,uVar10);
  }
  *piVar3 = (int)puVar1;
  return puVar1;
}

/* FUN_00176f3a @ 0x176f3a (215 bytes) */
int FUN_00176f3a(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(*param_1 + 0x3f4);
  iVar3 = FUN_0010a17a(0x31,*param_1);
  *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(iVar3 + 0x14c);
  *(undefined4 *)(iVar3 + 0x98) = 0;
  *(undefined4 *)(iVar3 + 0x9c) = param_3;
  FUN_0010ba02(iVar3,1,param_2,0,*param_1);
  uVar4 = FUN_000f5fea(param_3);
  *(undefined4 *)(iVar3 + 0xc) = uVar4;
  if ((*(byte *)(param_2 + 0x14) & 0x20) == 0) {
    *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xffffffdf;
  }
  else {
    *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 0x20;
  }
  FUN_000f5d78(iVar3);
  piVar1 = (int *)(iVar2 + 0x23c);
  *piVar1 = *piVar1 + 1;
  ((int (*)())FUN_00174e94)();
  return;
}

/* FUN_00177012 @ 0x177012 (1602 bytes) */
int FUN_00177012(param_1, param_2)
  int *param_1;
  int param_2;
{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int local_3c;
  int local_38;
  int *local_34;
  int local_20;
  int local_10;
  
  piVar1 = *(int **)(param_2 + 0x38);
  iVar4 = (**(code **)(*piVar1 + 0x14))(piVar1);
  if ((iVar4 < 3) || (*(int *)(piVar1[0x22] + 8) == 0x14)) goto LAB_00177082;
  iVar4 = FUN_0010b180(piVar1,1);
  if (*(int *)(iVar4 + 0x98) != 0) {
    piVar5 = (int *)FUN_0010b180(piVar1,1);
    cVar3 = (**(code **)(*piVar5 + 0x60))(piVar5);
    if (cVar3 == '\0') goto LAB_00177082;
    uVar7 = FUN_0010b180(piVar1,1);
    iVar4 = FUN_0010b180(uVar7,1);
    if (*(int *)(iVar4 + 0x98) != 0) goto LAB_00177082;
  }
  iVar4 = FUN_0010b180(piVar1,2);
  if (*(int *)(iVar4 + 0x98) != 0) {
    piVar5 = (int *)FUN_0010b180(piVar1,2);
    cVar3 = (**(code **)(*piVar5 + 0x60))(piVar5);
    if (cVar3 == '\0') goto LAB_00177082;
    uVar7 = FUN_0010b180(piVar1,2);
    iVar4 = FUN_0010b180(uVar7,1);
    if (*(int *)(iVar4 + 0x98) != 0) goto LAB_00177082;
  }
  iVar4 = FUN_0010b180(piVar1,3);
  if (*(int *)(iVar4 + 0x98) != 0) {
    piVar5 = (int *)FUN_0010b180(piVar1,3);
    cVar3 = (**(code **)(*piVar5 + 0x60))(piVar5);
    if (cVar3 != '\0') {
      uVar7 = FUN_0010b180(piVar1,3);
      iVar4 = FUN_0010b180(uVar7,1);
      if (*(int *)(iVar4 + 0x98) == 0) goto LAB_001774f5;
    }
LAB_00177082:
    local_3c = -1;
    local_38 = 1;
    iVar4 = (**(code **)(*piVar1 + 0x14))(piVar1);
    if (0 < iVar4) {
      do {
        local_34 = (int *)FUN_0010b180(piVar1,local_38);
        cVar3 = (**(code **)(*local_34 + 0x60))(local_34);
        if (cVar3 != '\0') {
          local_34 = (int *)FUN_0010b180(local_34,1);
        }
        if (local_34[0x26] == 1) {
          iVar4 = local_34[0x25];
          if ((*(byte *)(local_34 + 5) & 0x40) == 0) {
            iVar9 = *param_1;
            piVar5 = *(int **)(iVar9 + 0x54);
            iVar6 = (**(code **)(*piVar5 + 0x138))(piVar5,iVar9);
            iVar10 = (**(code **)(*piVar5 + 0x140))(piVar5,iVar9);
            iVar9 = (**(code **)(*piVar5 + 0x13c))(piVar5,iVar9);
            iVar4 = iVar4 + iVar6 + iVar10 + iVar9;
            iVar9 = iVar4;
            if (-1 < local_3c) {
              iVar9 = local_3c;
            }
            iVar6 = *(int *)(local_34[0x22] + 8);
            local_3c = iVar9;
          }
          else {
            iVar9 = iVar4;
            if (-1 < local_3c) {
              iVar9 = local_3c;
            }
            iVar6 = *(int *)(local_34[0x22] + 8);
            local_3c = iVar9;
          }
          if (((iVar6 != 0x8e) || ((*(byte *)(local_34 + 5) & 0x40) != 0)) &&
             ((local_34[0x56] == param_1[4] ||
              (*(int *)(param_1[1] + 0x468) == *(int *)(local_34[0x56] + 0x110))))) {
            local_3c = iVar4;
          }
        }
        local_38 = local_38 + 1;
        iVar4 = (**(code **)(*piVar1 + 0x14))(piVar1);
      } while (local_38 <= iVar4);
    }
    local_10 = 1;
    iVar4 = (**(code **)(*piVar1 + 0x14))(piVar1);
    if (0 < iVar4) {
      do {
        piVar5 = (int *)FUN_0010b180(piVar1,local_10);
        cVar3 = (**(code **)(*piVar5 + 0x60))(piVar5);
        if (cVar3 != '\0') {
          piVar5 = (int *)FUN_0010b180(piVar5,1);
        }
        if (piVar5[0x26] == 1) {
          local_20 = piVar5[0x25];
          if ((*(byte *)(piVar5 + 5) & 0x40) == 0) {
            iVar4 = *param_1;
            piVar2 = *(int **)(iVar4 + 0x54);
            iVar9 = (**(code **)(*piVar2 + 0x138))(piVar2,iVar4);
            iVar6 = (**(code **)(*piVar2 + 0x140))(piVar2,iVar4);
            iVar4 = (**(code **)(*piVar2 + 0x13c))(piVar2,iVar4);
            local_20 = local_20 + iVar9 + iVar6 + iVar4;
          }
          if (local_20 != local_3c) {
            if (*(int *)(piVar5[0x22] + 8) == 0x8e) {
              if ((*(byte *)(piVar5 + 5) & 0x40) != 0) {
                iVar4 = piVar5[0x56];
                if (iVar4 == param_1[4]) goto LAB_001772c6;
                goto LAB_00177216;
              }
            }
            else {
              iVar4 = piVar5[0x56];
              if (iVar4 == param_1[4]) goto LAB_001772c6;
LAB_00177216:
              if (*(int *)(param_1[1] + 0x468) == *(int *)(iVar4 + 0x110)) {
LAB_001772c6:
                iVar4 = FUN_0010b0f4(piVar1,local_10);
                uVar7 = FUN_000f5b3c(*(undefined4 *)(iVar4 + 0x10));
                iVar4 = param_1[10];
                uVar8 = FUN_0010b180(piVar1,local_10);
                iVar4 = ((int (*)())FUN_00176f3a)(param_1,uVar8,uVar7,iVar4,param_2 + 0xc);
                FUN_0010ba02(piVar1,local_10,*(undefined4 *)(iVar4 + 0x38),0,*param_1);
                iVar9 = FUN_0010b0f4(piVar1,local_10);
                uVar7 = FUN_000f5bdc(*(undefined4 *)(iVar9 + 0x10));
                ((int (*)())FUN_00174cc0)(param_1,iVar4,param_2,local_10,0,uVar7);
                FUN_001a7d72(param_2);
                return iVar4;
              }
            }
            piVar5[0x26] = 0;
          }
        }
        local_10 = local_10 + 1;
        iVar4 = (**(code **)(*piVar1 + 0x14))(piVar1);
      } while (local_10 <= iVar4);
    }
    return 0;
  }
LAB_001774f5:
  uVar7 = FUN_0010b180(piVar1,1);
  iVar4 = FUN_0010b0f4(piVar1,1);
  uVar8 = FUN_000f5b3c(*(undefined4 *)(iVar4 + 0x10));
  iVar4 = ((int (*)())FUN_00176f3a)(param_1,uVar7,uVar8,param_1[10],param_2 + 0xc);
  FUN_0010ba02(piVar1,1,*(undefined4 *)(iVar4 + 0x38),0,*param_1);
  iVar9 = FUN_0010b0f4(piVar1,1);
  uVar7 = FUN_000f5bdc(*(undefined4 *)(iVar9 + 0x10));
  ((int (*)())FUN_00174cc0)(param_1,iVar4,param_2,1,0,uVar7);
  uVar7 = *(undefined4 *)(*(int *)(iVar4 + 0x38) + 0x94);
  iVar9 = FUN_0010b0f4(*(int *)(iVar4 + 0x38),0);
  *(undefined4 *)(iVar9 + 8) = uVar7;
  *(undefined4 *)(iVar9 + 0xc) = 1;
  *(undefined1 *)(iVar4 + 100) = 1;
  FUN_001a7d72(param_2);
  return iVar4;
}

/* FUN_00177654 @ 0x177654 (3040 bytes) */
int FUN_00177654(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int *param_3;
  int param_4;
  int param_5;
{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  char cVar7;
  undefined1 uVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  int *piVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  int *local_90;
  int local_8c;
  int local_84;
  int local_64;
  uint local_60;
  uint local_38;
  int local_34;
  int *local_30;
  int local_2c [7];
  
  if (param_5 < 1) {
    local_90 = (int *)FUN_0010b180(param_3,param_4);
    local_8c = param_4;
    if (local_90[0x56] == param_1[4]) goto LAB_00177e02;
  }
  else {
    local_90 = (int *)FUN_0010b180(param_3,param_5);
    local_8c = param_5;
    if (local_90[0x56] == param_1[4]) {
LAB_00177e02:
      cVar7 = ((int (*)())FUN_0017422c)();
      if (cVar7 == '\0') {
        uVar2 = local_90[0x54];
        puVar1 = (uint *)param_1[6];
        if (uVar2 < *puVar1) {
          uVar4 = puVar1[1];
          if (uVar4 <= uVar2) {
            _memset((void *)(puVar1[2] + uVar4 * 4),0,(uVar2 - uVar4) * 4 + 4);
            puVar1[1] = uVar2 + 1;
          }
          piVar12 = (int *)(puVar1[2] + uVar2 * 4);
        }
        else {
          piVar12 = (int *)FUN_001a7f7c(puVar1,uVar2);
        }
        local_84 = *piVar12;
        bVar6 = false;
        goto LAB_001776c8;
      }
    }
  }
  local_84 = ((int (*)())FUN_00176c02)(param_1,local_90);
  bVar6 = true;
LAB_001776c8:
  if (((*(byte *)((int)param_3 + 0x15) & 2) == 0) || (local_8c != param_3[0x21])) {
    iVar9 = (**(code **)(*param_3 + 0x14))(param_3);
    if (iVar9 < local_8c) {
      uVar11 = *(undefined4 *)(*param_1 + 0xbc);
      puVar10 = (undefined4 *)FUN_001a7bca(uVar11,0x24);
      *puVar10 = uVar11;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 1;
      puVar10[5] = 0;
      puVar10[6] = 0;
      puVar10[7] = DAT_001cc6f4;
      *(undefined1 *)(puVar10 + 8) = 0;
      puVar10[1] = local_84;
      puVar10[2] = param_2;
      uVar11 = ((int (*)())FUN_0017412a)(param_1,local_90,param_3,0,param_4,0);
      puVar10[4] = uVar11;
      puVar10[5] = param_4;
      puVar10[6] = param_5;
      puVar10[7] = local_90[3];
      puVar1 = *(uint **)(local_84 + 0x40);
      uVar2 = puVar1[1];
      if (uVar2 < *puVar1) {
        _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
        puVar1[1] = uVar2 + 1;
        piVar12 = (int *)(uVar2 * 4 + puVar1[2]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar1,uVar2);
      }
      *piVar12 = (int)(puVar10 + 1);
      puVar1 = *(uint **)(param_2 + 0x44);
      uVar2 = puVar1[1];
      if (uVar2 < *puVar1) {
        _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
        puVar1[1] = uVar2 + 1;
        piVar12 = (int *)(uVar2 * 4 + puVar1[2]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar1,uVar2);
      }
      *piVar12 = (int)(puVar10 + 1);
    }
    else {
      iVar9 = FUN_0010b0f4(param_3,local_8c);
      uVar11 = *(undefined4 *)(iVar9 + 0x10);
      if (0 < param_5) {
        iVar9 = FUN_0010b0f4(*(undefined4 *)(param_2 + 0x38),param_4);
        uVar13 = FUN_000f5bdc(*(undefined4 *)(iVar9 + 0x10));
        piVar12 = (int *)FUN_0010b180(*(undefined4 *)(param_2 + 0x38),param_4);
        if (param_3 != piVar12) {
          piVar12 = (int *)FUN_0010b180(*(undefined4 *)(param_2 + 0x38),param_4);
          cVar7 = (**(code **)(*piVar12 + 0x60))(piVar12);
          if (cVar7 != '\0') {
            uVar14 = FUN_0010b180(*(undefined4 *)(param_2 + 0x38),param_4);
            FUN_0010b180(uVar14,1);
          }
          uVar14 = FUN_0010b180(*(undefined4 *)(param_2 + 0x38),param_4);
          iVar9 = FUN_0010b0f4(uVar14,1);
          uVar13 = FUN_000f5b96(*(undefined4 *)(iVar9 + 0x10),uVar13);
          uVar13 = FUN_000f5bdc(uVar13);
        }
        uVar11 = FUN_000f5b96(uVar11,uVar13);
      }
      local_38 = FUN_000f5bdc(uVar11);
      local_64 = 0;
LAB_00177930:
      local_60 = local_38 & local_90[3];
      if (local_60 != 0) goto LAB_001779f6;
      while (!bVar6) {
        while( true ) {
          local_38 = local_38 - local_60;
          if ((local_38 == 0) || ((*(byte *)((int)local_90 + 0x15) & 2) == 0)) goto LAB_00177b6f;
          piVar12 = (int *)FUN_0010b180(local_90,local_90[0x21]);
          cVar7 = (**(code **)(*piVar12 + 0x50))(piVar12);
          if (cVar7 != '\0') goto LAB_00177b6f;
          local_90 = (int *)FUN_0010b180(local_90,local_90[0x21]);
          if ((local_90[0x56] == param_1[4]) && (cVar7 = ((int (*)())FUN_0017422c)(), cVar7 == '\0')) {
            uVar2 = local_90[0x54];
            puVar1 = (uint *)param_1[6];
            if (uVar2 < *puVar1) {
              uVar4 = puVar1[1];
              if (uVar4 <= uVar2) {
                _memset((void *)(puVar1[2] + uVar4 * 4),0,(uVar2 - uVar4) * 4 + 4);
                puVar1[1] = uVar2 + 1;
              }
              local_84 = *(int *)(puVar1[2] + uVar2 * 4);
            }
            else {
              piVar12 = (int *)FUN_001a7f7c(puVar1,uVar2);
              local_84 = *piVar12;
            }
            goto LAB_00177930;
          }
          local_84 = ((int (*)())FUN_00176c02)(param_1,local_90);
          bVar6 = true;
          local_60 = local_38 & local_90[3];
          if (local_60 == 0) break;
LAB_001779f6:
          uVar11 = *(undefined4 *)(*param_1 + 0xbc);
          puVar15 = (undefined4 *)FUN_001a7bca(uVar11,0x24);
          *puVar15 = uVar11;
          puVar10 = puVar15 + 1;
          puVar15[1] = 0;
          puVar15[2] = 0;
          puVar15[3] = 0;
          puVar15[4] = 1;
          puVar15[5] = 0;
          puVar15[6] = 0;
          puVar15[7] = DAT_001cc6f4;
          *(undefined1 *)(puVar15 + 8) = 0;
          puVar15[1] = local_84;
          puVar15[2] = param_2;
          uVar11 = ((int (*)())FUN_0017412a)(param_1,local_90,param_3,0,param_4,0);
          puVar15[4] = uVar11;
          puVar15[5] = param_4;
          puVar15[6] = param_5;
          puVar15[7] = local_60;
          if (((local_64 == 0) &&
              (piVar12 = (int *)FUN_0010b180(param_3,local_8c), local_90 != piVar12)) &&
             ((cVar7 = (**(code **)(*param_3 + 0x5c))(param_3), cVar7 == '\0' || (param_5 < 1)))) {
            FUN_0010ba02(param_3,local_8c,local_90,0,*param_1);
          }
          if (-1 < *(short *)(*(int *)(param_2 + 0x38) + 0x14)) {
            cVar7 = (**(code **)(*local_90 + 0x54))(local_90);
            piVar12 = local_90;
            if ((cVar7 != '\0') && (local_90[0x21] != 0)) {
              piVar12 = (int *)FUN_0010b180(local_90,1);
            }
            uVar8 = (**(code **)(*(int *)param_1[3] + 0x20))((int *)param_1[3],piVar12);
            *(undefined1 *)(puVar15 + 8) = uVar8;
          }
          puVar1 = *(uint **)(local_84 + 0x40);
          uVar2 = puVar1[1];
          if (uVar2 < *puVar1) {
            _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
            puVar1[1] = uVar2 + 1;
            piVar12 = (int *)(uVar2 * 4 + puVar1[2]);
          }
          else {
            piVar12 = (int *)FUN_001a7f7c(puVar1,uVar2);
          }
          *piVar12 = (int)puVar10;
          puVar1 = *(uint **)(param_2 + 0x44);
          uVar2 = puVar1[1];
          if (uVar2 < *puVar1) {
            _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
            puVar1[1] = uVar2 + 1;
            piVar12 = (int *)(uVar2 * 4 + puVar1[2]);
          }
          else {
            piVar12 = (int *)FUN_001a7f7c(puVar1,uVar2);
          }
          *piVar12 = (int)puVar10;
          local_2c[local_64] = (int)puVar10;
          local_64 = local_64 + 1;
          if (bVar6) goto LAB_00177b6f;
        }
      }
LAB_00177b6f:
      if (0 < local_64) {
        iVar9 = 0;
joined_r0x00177b87:
        do {
          while (iVar5 = iVar9 + 1, local_64 <= iVar5) {
            iVar9 = iVar5;
            if (iVar5 == local_64) {
              return;
            }
          }
          piVar12 = (int *)local_2c[iVar9];
          local_30 = local_2c + iVar5;
          local_34 = 0;
          do {
            while (piVar3 = (int *)*local_30,
                  (*(uint *)(*(int *)(*piVar3 + 0x38) + 0xc) &
                  *(uint *)(*(int *)(*piVar12 + 0x38) + 0xc)) != 0) {
              uVar11 = *(undefined4 *)(*param_1 + 0xbc);
              puVar10 = (undefined4 *)FUN_001a7bca(uVar11,0x24);
              *puVar10 = uVar11;
              puVar15 = puVar10 + 1;
              puVar10[1] = 0;
              puVar10[2] = 0;
              puVar10[3] = 0;
              puVar10[4] = 1;
              puVar10[5] = 0;
              puVar10[6] = 0;
              puVar10[7] = DAT_001cc6f4;
              *(undefined1 *)(puVar10 + 8) = 0;
              puVar10[1] = *piVar3;
              puVar10[2] = *piVar12;
              puVar10[3] = 3;
              uVar11 = ((int (*)())FUN_0017412a)(param_1,*(undefined4 *)(puVar10[1] + 0x38),
                                    *(undefined4 *)(puVar10[2] + 0x38),0,0,3);
              puVar10[4] = uVar11;
              puVar10[7] = *(uint *)(*(int *)(*piVar12 + 0x38) + 0xc) &
                           *(uint *)(*(int *)(*piVar3 + 0x38) + 0xc);
              puVar1 = *(uint **)(puVar10[1] + 0x40);
              uVar2 = puVar1[1];
              if (uVar2 < *puVar1) {
                _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
                puVar1[1] = uVar2 + 1;
                puVar16 = (undefined4 *)(uVar2 * 4 + puVar1[2]);
              }
              else {
                puVar16 = (undefined4 *)FUN_001a7f7c(puVar1,uVar2);
              }
              *puVar16 = puVar15;
              puVar1 = *(uint **)(puVar10[2] + 0x44);
              uVar2 = puVar1[1];
              if (uVar2 < *puVar1) {
                _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
                puVar1[1] = uVar2 + 1;
                *(undefined4 **)(uVar2 * 4 + puVar1[2]) = puVar15;
              }
              else {
                puVar10 = (undefined4 *)FUN_001a7f7c(puVar1,uVar2);
                *puVar10 = puVar15;
              }
              local_34 = local_34 + 1;
              local_30 = local_30 + 1;
              iVar9 = iVar5;
              if (local_34 == local_64 - iVar5) goto joined_r0x00177b87;
            }
            local_34 = local_34 + 1;
            local_30 = local_30 + 1;
            iVar9 = iVar5;
          } while (local_34 != local_64 - iVar5);
        } while( true );
      }
    }
  }
  else {
    FUN_0010b180(param_3,local_8c);
    cVar7 = FUN_000e1402(*param_1,0x26);
    if (((cVar7 == '\0') || (cVar7 = FUN_000e1402(*param_1,0x25), cVar7 == '\0')) ||
       ((*(byte *)(param_3 + 5) & 0x20) != 0)) {
      uVar11 = *(undefined4 *)(*param_1 + 0xbc);
      puVar15 = (undefined4 *)FUN_001a7bca(uVar11,0x24);
      *puVar15 = uVar11;
      puVar10 = puVar15 + 1;
      puVar15[1] = 0;
      puVar15[2] = 0;
      puVar15[3] = 0;
      puVar15[4] = 1;
      puVar15[5] = 0;
      puVar15[6] = 0;
      puVar15[7] = DAT_001cc6f4;
      *(undefined1 *)(puVar15 + 8) = 0;
      puVar15[1] = local_84;
      puVar15[2] = param_2;
      puVar15[3] = 3;
      uVar11 = ((int (*)())FUN_0017412a)(param_1,local_90,param_3,0,0,3);
      puVar15[4] = uVar11;
      puVar15[7] = param_3[3];
      puVar1 = *(uint **)(local_84 + 0x40);
      uVar2 = puVar1[1];
      if (uVar2 < *puVar1) {
        _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
        puVar1[1] = uVar2 + 1;
        piVar12 = (int *)(uVar2 * 4 + puVar1[2]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar1,uVar2);
      }
      *piVar12 = (int)puVar10;
      puVar1 = *(uint **)(param_2 + 0x44);
      uVar2 = puVar1[1];
      if (uVar2 < *puVar1) {
        _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
        puVar1[1] = uVar2 + 1;
        *(undefined4 **)(uVar2 * 4 + puVar1[2]) = puVar10;
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar1,uVar2);
        *piVar12 = (int)puVar10;
      }
    }
  }
  return;
}

/* FUN_00178234 @ 0x178234 (5181 bytes) */
int FUN_00178234(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  byte bVar10;
  undefined1 uVar11;
  char cVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  undefined4 *puVar20;
  int *piVar21;
  undefined4 *puVar22;
  int iVar23;
  byte bVar24;
  byte bVar25;
  byte bVar26;
  int local_8c;
  int *local_84;
  int *local_70;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20 [4];
  
  local_84 = *(int **)(param_2 + 0x38);
  iVar13 = (**(code **)(*(int *)param_1[2] + 0x40))((int *)param_1[2],local_84,local_20,&local_24);
  if (iVar13 == 0) {
    return 0;
  }
  param_1[0x69] = param_1[0x69] + 1;
  iVar14 = ((int (*)())FUN_00174e94)(param_1,iVar13,param_2 + 0xc,*(undefined4 *)(param_2 + 0x30));
  uVar15 = FUN_0010b180(local_84,1);
  uVar16 = FUN_0010b180(local_84,2);
  iVar17 = FUN_0010b0f4(local_84,1);
  local_28 = *(uint *)(iVar17 + 0x10);
  iVar17 = FUN_0010b0f4(local_84,2);
  local_2c = *(uint *)(iVar17 + 0x10);
  iVar17 = FUN_0010b0f4(local_84,0);
  iVar17 = *(int *)(iVar17 + 0x10);
  iVar1 = local_84[0x26];
  iVar2 = local_84[0x25];
  uVar3 = local_84[5];
  uVar18 = uVar3 >> 1;
  uVar19 = uVar3 >> 5;
  uVar11 = (undefined1)local_84[0x48];
  iVar4 = local_84[0x49];
  bVar24 = (byte)local_84[0x2e] & 1;
  bVar25 = (byte)local_84[0x34] & 1;
  bVar10 = (byte)((uint)local_84[0x2e] >> 1) & 1;
  bVar26 = (byte)((uint)local_84[0x34] >> 1) & 1;
  iVar5 = local_84[3];
  if ((uVar3 & 0x200) == 0) {
    local_8c = 0;
    iVar23 = *(int *)(iVar13 + 0x88);
    iVar6 = *(int *)(iVar23 + 8);
  }
  else {
    local_8c = FUN_0010b180(local_84,local_84[0x21]);
    iVar23 = *(int *)(iVar13 + 0x88);
    iVar6 = *(int *)(iVar23 + 8);
  }
  if (iVar6 == 0x13) {
    ((int (*)())FUN_001826a6)(param_1[2],param_2);
    if (*(int *)(local_84[0x22] + 8) == 0x1c) {
      FUN_0010da48(local_84,0x1e,*param_1);
      FUN_0010ba02(local_84,3,iVar13,0,*param_1);
      iVar23 = FUN_0010b0f4(local_84,3);
      *(undefined4 *)(iVar23 + 0x10) = DAT_001cc700;
      (**(code **)(*local_84 + 0x88))(local_84,3,2,local_24);
      uVar9 = local_28;
      iVar23 = FUN_0010b0f4(local_84,1);
      uVar3 = local_2c;
      *(uint *)(iVar23 + 0x10) = uVar9;
      iVar23 = FUN_0010b0f4(local_84,2);
      *(uint *)(iVar23 + 0x10) = uVar3;
      if (local_20[0] < 2) {
        local_50 = (int)&local_28 + local_20[0];
        local_4c = (int)&local_2c + local_20[0];
        iVar23 = local_20[0];
        do {
          iVar6 = iVar23 + 1;
          (**(code **)(*local_84 + 0x88))(local_84,1,iVar23,*(undefined1 *)(local_50 + 1));
          (**(code **)(*local_84 + 0x88))(local_84,2,iVar23,*(undefined1 *)(local_4c + 1));
          local_50 = local_50 + 1;
          local_4c = local_4c + 1;
          iVar23 = iVar6;
        } while (iVar6 != 2);
      }
      (**(code **)(*local_84 + 0x88))(local_84,1,2,4);
      (**(code **)(*local_84 + 0x88))(local_84,2,2,4);
    }
    else if (*(int *)(local_84[0x22] + 8) == 0x1d) {
      FUN_0010da48(local_84,0xa3,*param_1);
      FUN_0010ba02(local_84,3,iVar13,0,*param_1);
      iVar23 = FUN_0010b0f4(local_84,3);
      *(undefined4 *)(iVar23 + 0x10) = DAT_001cc700;
      (**(code **)(*local_84 + 0x88))(local_84,3,3,local_24);
      uVar9 = local_28;
      iVar23 = FUN_0010b0f4(local_84,1);
      uVar3 = local_2c;
      *(uint *)(iVar23 + 0x10) = uVar9;
      iVar23 = FUN_0010b0f4(local_84,2);
      *(uint *)(iVar23 + 0x10) = uVar3;
      if (local_20[0] < 3) {
        local_48 = (int)&local_28 + local_20[0];
        local_44 = (int)&local_2c + local_20[0];
        iVar23 = local_20[0];
        do {
          iVar6 = iVar23 + 1;
          (**(code **)(*local_84 + 0x88))(local_84,1,iVar23,*(undefined1 *)(local_48 + 1));
          (**(code **)(*local_84 + 0x88))(local_84,2,iVar23,*(undefined1 *)(local_44 + 1));
          local_48 = local_48 + 1;
          local_44 = local_44 + 1;
          iVar23 = iVar6;
        } while (iVar6 != 3);
      }
      (**(code **)(*local_84 + 0x88))(local_84,1,3,4);
      (**(code **)(*local_84 + 0x88))(local_84,2,3,4);
    }
    else {
      local_84 = (int *)0x0;
    }
    if ((uVar18 & 1) == 0) {
      local_84[0x25] = iVar2;
      local_84[0x26] = iVar1;
      if ((uVar19 & 1) == 0) {
        local_84[5] = local_84[5] & 0xffffffdf;
      }
      else {
        local_84[5] = local_84[5] | 0x20;
      }
    }
    else {
      FUN_0010a38c(local_84,param_1[1],iVar1,iVar2);
    }
    local_84[0x27] = iVar17;
    *(undefined1 *)(local_84 + 0x48) = uVar11;
    local_84[0x49] = iVar4;
    local_84[3] = iVar5;
    FUN_0010ba02(local_84,1,uVar15,0,*param_1);
    FUN_00109c0e(local_84 + 0x29,2,bVar10);
    FUN_00109c0e(local_84 + 0x29,1,bVar24);
    FUN_0010ba02(local_84,2,uVar16,0,*param_1);
    FUN_00109c0e(local_84 + 0x2f,2,bVar26);
    FUN_00109c0e(local_84 + 0x2f,1,bVar25);
    if (local_8c != 0) {
      FUN_0010c18e(local_84,local_8c,0,*param_1);
    }
    uVar15 = (**(code **)(*(int *)param_1[2] + 0x4c))((int *)param_1[2],local_84);
    *(undefined4 *)(param_2 + 0x58) = uVar15;
    cVar12 = FUN_000e1402(*param_1,0x28);
    if ((cVar12 == '\0') ||
       (cVar12 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],param_2), cVar12 == '\0'
       )) {
      uVar11 = 0;
    }
    else {
      uVar11 = 1;
    }
    *(undefined1 *)(param_2 + 0x5c) = uVar11;
    (**(code **)(*(int *)param_1[2] + 0x48))((int *)param_1[2],param_2);
    ((int (*)())FUN_00182640)(param_1[2],param_2);
    uVar15 = *(undefined4 *)(*param_1 + 0xbc);
    puVar22 = (undefined4 *)FUN_001a7bca(uVar15,0x24);
    *puVar22 = uVar15;
    puVar20 = puVar22 + 1;
    puVar22[1] = 0;
    puVar22[2] = 0;
    puVar22[3] = 0;
    puVar22[4] = 1;
    puVar22[5] = 0;
    puVar22[6] = 0;
    puVar22[7] = DAT_001cc6f4;
    *(undefined1 *)(puVar22 + 8) = 0;
    puVar22[1] = iVar14;
    puVar22[2] = param_2;
    uVar15 = ((int (*)())FUN_0017412a)(param_1,iVar13,local_84,0,3,0);
    puVar22[4] = uVar15;
    puVar22[5] = 3;
    puVar22[7] = 0;
    *(undefined1 *)(local_24 + 0x18 + (int)puVar20) = 1;
    puVar7 = *(uint **)(iVar14 + 0x40);
    uVar3 = puVar7[1];
    if (uVar3 < *puVar7) {
      _memset((void *)(uVar3 * 4 + puVar7[2]),0,4);
      puVar7[1] = uVar3 + 1;
      piVar21 = (int *)(uVar3 * 4 + puVar7[2]);
    }
    else {
      piVar21 = (int *)FUN_001a7f7c(puVar7,uVar3);
    }
    *piVar21 = (int)puVar20;
    puVar7 = *(uint **)(param_2 + 0x44);
    uVar3 = puVar7[1];
    if (uVar3 < *puVar7) {
      _memset((void *)(uVar3 * 4 + puVar7[2]),0,4);
      puVar7[1] = uVar3 + 1;
      puVar22 = (undefined4 *)(uVar3 * 4 + puVar7[2]);
    }
    else {
      puVar22 = (undefined4 *)FUN_001a7f7c(puVar7,uVar3);
    }
  }
  else {
    if (*(int *)(iVar23 + 8) != 0x14) {
      if (*(int *)(iVar23 + 8) != 0x1c) {
        return iVar14;
      }
      ((int (*)())FUN_001826a6)(param_1[2],param_2);
      FUN_0010da48(local_84,0x14,*param_1);
      if ((uVar18 & 1) == 0) {
        local_84[0x25] = iVar2;
        local_84[0x26] = iVar1;
        if ((uVar19 & 1) == 0) {
          local_84[5] = local_84[5] & 0xffffffdf;
        }
        else {
          local_84[5] = local_84[5] | 0x20;
        }
      }
      else {
        FUN_0010a38c(local_84,param_1[1],iVar1,iVar2);
      }
      *(undefined1 *)(local_84 + 0x48) = uVar11;
      local_84[0x49] = iVar4;
      local_84[3] = iVar5;
      FUN_0010ba02(local_84,1,uVar15,0,*param_1);
      FUN_00109c0e(local_84 + 0x29,2,bVar10);
      FUN_00109c0e(local_84 + 0x29,1,bVar24);
      FUN_0010ba02(local_84,2,uVar16,0,*param_1);
      FUN_00109c0e(local_84 + 0x2f,2,bVar26);
      FUN_00109c0e(local_84 + 0x2f,1,bVar25);
      FUN_0010ba02(local_84,3,iVar13,0,*param_1);
      local_84[0x27] = iVar17;
      uVar15 = *(undefined4 *)(PTR_DAT_00213485 + (local_28 >> 0x18) * 4);
      iVar17 = FUN_0010b0f4(local_84,1);
      *(undefined4 *)(iVar17 + 0x10) = uVar15;
      uVar15 = *(undefined4 *)(PTR_DAT_00213485 + (local_2c >> 0x18) * 4);
      iVar17 = FUN_0010b0f4(local_84,2);
      *(undefined4 *)(iVar17 + 0x10) = uVar15;
      iVar17 = FUN_0010b0f4(local_84,3);
      *(undefined4 *)(iVar17 + 0x10) = DAT_001cc6fc;
      FUN_000f5d78(local_84);
      if (local_8c != 0) {
        FUN_0010c18e(local_84,local_8c,0,*param_1);
      }
      uVar15 = (**(code **)(*(int *)param_1[2] + 0x4c))((int *)param_1[2],local_84);
      *(undefined4 *)(param_2 + 0x58) = uVar15;
      cVar12 = FUN_000e1402(*param_1,0x28);
      if ((cVar12 == '\0') ||
         (cVar12 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],param_2),
         cVar12 == '\0')) {
        uVar11 = 0;
      }
      else {
        uVar11 = 1;
      }
      *(undefined1 *)(param_2 + 0x5c) = uVar11;
      (**(code **)(*(int *)param_1[2] + 0x48))((int *)param_1[2],param_2);
      ((int (*)())FUN_00182640)(param_1[2],param_2);
      uVar15 = *(undefined4 *)(*param_1 + 0xbc);
      puVar20 = (undefined4 *)FUN_001a7bca(uVar15,0x24);
      *puVar20 = uVar15;
      puVar20[1] = 0;
      puVar20[2] = 0;
      puVar20[3] = 0;
      puVar20[4] = 1;
      puVar20[5] = 0;
      puVar20[6] = 0;
      puVar20[7] = DAT_001cc6f4;
      *(undefined1 *)(puVar20 + 8) = 0;
      puVar20[1] = iVar14;
      puVar20[2] = param_2;
      puVar20[3] = 0;
      uVar15 = ((int (*)())FUN_0017412a)(param_1,iVar13,local_84,0,3,0);
      puVar20[4] = uVar15;
      puVar20[5] = 3;
      puVar20[7] = 0;
      *(undefined1 *)(puVar20 + 7) = 1;
      puVar7 = *(uint **)(iVar14 + 0x40);
      uVar3 = puVar7[1];
      if (uVar3 < *puVar7) {
        _memset((void *)(uVar3 * 4 + puVar7[2]),0,4);
        puVar7[1] = uVar3 + 1;
        piVar21 = (int *)(uVar3 * 4 + puVar7[2]);
      }
      else {
        piVar21 = (int *)FUN_001a7f7c(puVar7,uVar3);
      }
      *piVar21 = (int)(puVar20 + 1);
      puVar7 = *(uint **)(param_2 + 0x44);
      uVar3 = puVar7[1];
      if (uVar3 < *puVar7) {
        _memset((void *)(uVar3 * 4 + puVar7[2]),0,4);
        puVar7[1] = uVar3 + 1;
        piVar21 = (int *)(uVar3 * 4 + puVar7[2]);
      }
      else {
        piVar21 = (int *)FUN_001a7f7c(puVar7,uVar3);
      }
      *piVar21 = (int)(puVar20 + 1);
      ((int (*)())FUN_0017573e)(param_1,param_2,iVar14);
      *(undefined4 *)(iVar14 + 0x48) = 1;
      *(int *)(param_2 + 0x34) = *(int *)(param_2 + 0x34) + 1;
      iVar13 = *(int *)(param_2 + 0x30);
      if (*(int *)(param_2 + 0x30) < param_1[10] + puVar20[4]) {
        iVar13 = param_1[10] + puVar20[4];
      }
      *(int *)(param_2 + 0x30) = iVar13;
      return iVar14;
    }
    ((int (*)())FUN_001826a6)(param_1[2],param_2);
    local_70 = local_84;
    if (*(int *)(local_84[0x22] + 8) == 0x1e) {
      FUN_0010da48(local_84,0x14,*param_1);
      local_84[0x27] = iVar17;
      uVar8 = *(undefined4 *)
               (PTR_DAT_00213485 + (uint)*(byte *)((int)&local_28 + (1 - local_20[0])) * 4);
      iVar17 = FUN_0010b0f4(local_84,1);
      *(undefined4 *)(iVar17 + 0x10) = uVar8;
      uVar8 = *(undefined4 *)
               (PTR_DAT_00213485 + (uint)*(byte *)((int)&local_2c + (1 - local_20[0])) * 4);
      iVar17 = FUN_0010b0f4(local_84,2);
      *(undefined4 *)(iVar17 + 0x10) = uVar8;
      uVar8 = *(undefined4 *)(PTR_DAT_00213485 + local_24 * 4);
      iVar17 = FUN_0010b0f4(local_84,3);
      *(undefined4 *)(iVar17 + 0x10) = uVar8;
      FUN_000f5d78(local_84);
    }
    else if (*(int *)(local_84[0x22] + 8) == 0xa3) {
      FUN_0010da48(local_84,0x1e,*param_1);
      uVar9 = local_28;
      local_84[0x27] = iVar17;
      iVar17 = FUN_0010b0f4(local_84,1);
      uVar3 = local_2c;
      *(uint *)(iVar17 + 0x10) = uVar9;
      iVar17 = FUN_0010b0f4(local_84,2);
      *(uint *)(iVar17 + 0x10) = uVar3;
      if (local_20[0] < 2) {
        local_40 = (int)&local_28 + local_20[0];
        local_3c = (int)&local_2c + local_20[0];
        iVar17 = local_20[0];
        do {
          iVar23 = iVar17 + 1;
          (**(code **)(*local_84 + 0x88))(local_84,1,iVar17,*(undefined1 *)(local_40 + 1));
          (**(code **)(*local_84 + 0x88))(local_84,2,iVar17,*(undefined1 *)(local_3c + 1));
          local_40 = local_40 + 1;
          local_3c = local_3c + 1;
          iVar17 = iVar23;
        } while (iVar23 != 2);
      }
      (**(code **)(*local_84 + 0x88))(local_84,1,2,4);
      (**(code **)(*local_84 + 0x88))(local_84,2,2,4);
      iVar17 = FUN_0010b0f4(local_84,3);
      *(undefined4 *)(iVar17 + 0x10) = DAT_001cc700;
      (**(code **)(*local_84 + 0x88))(local_84,3,2,local_24);
    }
    else {
      local_70 = (int *)0x0;
    }
    if ((uVar18 & 1) == 0) {
      local_70[0x25] = iVar2;
      local_70[0x26] = iVar1;
      if ((uVar19 & 1) == 0) {
        local_70[5] = local_70[5] & 0xffffffdf;
      }
      else {
        local_70[5] = local_70[5] | 0x20;
      }
    }
    else {
      FUN_0010a38c(local_70,param_1[1],iVar1,iVar2);
    }
    *(undefined1 *)(local_70 + 0x48) = uVar11;
    local_70[0x49] = iVar4;
    local_70[3] = iVar5;
    FUN_0010ba02(local_70,1,uVar15,0,*param_1);
    FUN_00109c0e(local_70 + 0x29,2,bVar10);
    FUN_00109c0e(local_70 + 0x29,1,bVar24);
    FUN_0010ba02(local_70,2,uVar16,0,*param_1);
    FUN_00109c0e(local_70 + 0x2f,2,bVar26);
    FUN_00109c0e(local_70 + 0x2f,1,bVar25);
    FUN_0010ba02(local_70,3,iVar13,0,*param_1);
    if (local_8c != 0) {
      FUN_0010c18e(local_70,local_8c,0,*param_1);
    }
    uVar15 = (**(code **)(*(int *)param_1[2] + 0x4c))((int *)param_1[2],local_70);
    *(undefined4 *)(param_2 + 0x58) = uVar15;
    cVar12 = FUN_000e1402(*param_1,0x28);
    if ((cVar12 == '\0') ||
       (cVar12 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],param_2), cVar12 == '\0'
       )) {
      uVar11 = 0;
    }
    else {
      uVar11 = 1;
    }
    *(undefined1 *)(param_2 + 0x5c) = uVar11;
    (**(code **)(*(int *)param_1[2] + 0x48))((int *)param_1[2],param_2);
    ((int (*)())FUN_00182640)(param_1[2],param_2);
    uVar15 = *(undefined4 *)(*param_1 + 0xbc);
    puVar22 = (undefined4 *)FUN_001a7bca(uVar15,0x24);
    *puVar22 = uVar15;
    puVar20 = puVar22 + 1;
    puVar22[1] = 0;
    puVar22[2] = 0;
    puVar22[3] = 0;
    puVar22[4] = 1;
    puVar22[5] = 0;
    puVar22[6] = 0;
    puVar22[7] = DAT_001cc6f4;
    *(undefined1 *)(puVar22 + 8) = 0;
    puVar22[1] = iVar14;
    puVar22[2] = param_2;
    uVar15 = ((int (*)())FUN_0017412a)(param_1,iVar13,local_70,0,3,0);
    puVar22[4] = uVar15;
    puVar22[5] = 3;
    puVar22[7] = 0;
    *(undefined1 *)(local_24 + 0x18 + (int)puVar20) = 1;
    puVar7 = *(uint **)(iVar14 + 0x40);
    uVar3 = puVar7[1];
    if (uVar3 < *puVar7) {
      _memset((void *)(uVar3 * 4 + puVar7[2]),0,4);
      puVar7[1] = uVar3 + 1;
      piVar21 = (int *)(uVar3 * 4 + puVar7[2]);
    }
    else {
      piVar21 = (int *)FUN_001a7f7c(puVar7,uVar3);
    }
    *piVar21 = (int)puVar20;
    puVar7 = *(uint **)(param_2 + 0x44);
    uVar3 = puVar7[1];
    if (uVar3 < *puVar7) {
      _memset((void *)(uVar3 * 4 + puVar7[2]),0,4);
      puVar7[1] = uVar3 + 1;
      puVar22 = (undefined4 *)(uVar3 * 4 + puVar7[2]);
    }
    else {
      puVar22 = (undefined4 *)FUN_001a7f7c(puVar7,uVar3);
    }
  }
  *puVar22 = puVar20;
  ((int (*)())FUN_0017573e)(param_1,param_2,iVar14);
  *(undefined4 *)(iVar14 + 0x48 + local_24 * 4) = 1;
  *(int *)(param_2 + 0x34) = *(int *)(param_2 + 0x34) + 1;
  iVar13 = *(int *)(param_2 + 0x30);
  if (*(int *)(param_2 + 0x30) < param_1[10] + puVar20[3]) {
    iVar13 = param_1[10] + puVar20[3];
  }
  *(int *)(param_2 + 0x30) = iVar13;
  return iVar14;
}

/* FUN_00179680 @ 0x179680 (671 bytes) */
int FUN_00179680(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  uint local_44;
  uint local_3c;
  undefined1 local_24 [8];
  int local_1c;
  
  FUN_001a7e06(local_24);
  puVar9 = *(uint **)(param_1 + 0x18);
  uVar1 = puVar9[1];
  if ((int)uVar1 < 1) {
LAB_00179833:
    *(undefined4 *)(param_1 + 0xf0) = 0;
    while (cVar5 = FUN_001a7c84(local_24), cVar5 == '\0') {
      (**(code **)(**(int **)(param_1 + 8) + 8))(*(int **)(param_1 + 8));
      iVar8 = local_1c;
      (**(code **)(**(int **)(param_1 + 8) + 0x10))
                (*(int **)(param_1 + 8),*(undefined4 *)(local_1c + 0x38));
      iVar3 = *(int *)(iVar8 + 8);
      FUN_001a7d72(iVar8);
      for (iVar6 = *(int *)(iVar3 + 8); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
        cVar5 = (**(code **)(**(int **)(param_1 + 8) + 0xc))
                          (*(int **)(param_1 + 8),*(undefined4 *)(iVar3 + 0x38));
        if (cVar5 != '\0') {
          (**(code **)(**(int **)(param_1 + 8) + 0x10))
                    (*(int **)(param_1 + 8),*(undefined4 *)(iVar3 + 0x38));
          *(undefined1 *)(iVar3 + 0x65) = 1;
          *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf0) + 1;
          *(undefined1 *)(iVar8 + 0x65) = 1;
          FUN_001a7d72(iVar3);
        }
        iVar3 = iVar6;
      }
      if (*(char *)(iVar8 + 0x65) != '\0') {
        *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf0) + 1;
      }
    }
    return;
  }
  local_3c = 0;
  if (*puVar9 == 0) goto LAB_001797b9;
LAB_001796bc:
  uVar2 = puVar9[1];
  if (uVar2 <= local_3c) {
    _memset((void *)(puVar9[2] + uVar2 * 4),0,(local_3c - uVar2) * 4 + 4);
    puVar9[1] = local_3c + 1;
  }
  piVar7 = (int *)(puVar9[2] + local_3c * 4);
  do {
    iVar3 = *piVar7;
    puVar9 = *(uint **)(iVar3 + 0x44);
    uVar2 = puVar9[1];
    if (0 < (int)uVar2) {
      local_44 = 0;
      while( true ) {
        if (local_44 < *puVar9) {
          uVar4 = puVar9[1];
          if (uVar4 <= local_44) {
            _memset((void *)(puVar9[2] + uVar4 * 4),0,(local_44 - uVar4) * 4 + 4);
            puVar9[1] = local_44 + 1;
          }
          piVar7 = *(int **)(puVar9[2] + local_44 * 4);
          iVar8 = *(int *)(*piVar7 + 0x18) + piVar7[3];
          iVar6 = *(int *)(iVar3 + 0x18);
          if (*(int *)(iVar3 + 0x18) < iVar8) {
            iVar6 = iVar8;
          }
          *(int *)(iVar3 + 0x18) = iVar6;
        }
        else {
          piVar7 = (int *)FUN_001a7f7c(puVar9,local_44);
          iVar8 = *(int *)(*(int *)*piVar7 + 0x18) + ((int *)*piVar7)[3];
          iVar6 = *(int *)(iVar3 + 0x18);
          if (*(int *)(iVar3 + 0x18) < iVar8) {
            iVar6 = iVar8;
          }
          *(int *)(iVar3 + 0x18) = iVar6;
        }
        if (uVar2 == local_44 + 1) break;
        local_44 = local_44 + 1;
        puVar9 = *(uint **)(iVar3 + 0x44);
      }
    }
    iVar6 = local_1c;
    if ((*(byte *)(*(int *)(iVar3 + 0x38) + 0x14) & 2) != 0) {
      do {
        iVar8 = iVar6;
        if (*(int *)(iVar8 + 8) == 0) goto LAB_0017978d;
        iVar6 = *(int *)(iVar8 + 8);
      } while (*(int *)(iVar3 + 0x18) <= *(int *)(iVar8 + 0x18));
      FUN_001a7cb8(iVar3,iVar8);
LAB_0017978d:
      if (*(int *)(iVar8 + 8) == 0) {
        FUN_001a7cd6(local_24,iVar3);
      }
    }
    local_3c = local_3c + 1;
    if (uVar1 == local_3c) goto LAB_00179833;
    puVar9 = *(uint **)(param_1 + 0x18);
    if (local_3c < *puVar9) goto LAB_001796bc;
LAB_001797b9:
    piVar7 = (int *)FUN_001a7f7c(puVar9,local_3c);
  } while( true );
}

/* FUN_00179928 @ 0x179928 (1788 bytes) */
int FUN_00179928(param_1)
  int *param_1;
{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int *local_4c;
  int local_48;
  int local_44;
  int local_3c;
  int local_38;
  int local_2c;
  int local_28;
  int local_20;
  
  iVar6 = *(int *)(*param_1 + 0x68);
  iVar3 = FUN_001a7bca(*(undefined4 *)(*param_1 + 0xbc),iVar6 * 4);
  iVar4 = FUN_001a7bca(*(undefined4 *)(*param_1 + 0xbc),iVar6);
  iVar6 = param_1[1];
  local_4c = *(int **)(iVar6 + 0x378);
  if (local_4c[2] != 0) {
    do {
      piVar11 = (int *)local_4c[0x26];
      iVar6 = piVar11[2];
      while (iVar6 != 0) {
        while ((*(byte *)(piVar11 + 5) & 1) != 0) {
          *(int *)(iVar3 + piVar11[0x53] * 4) = piVar11[0x53];
          *(undefined1 *)(iVar4 + piVar11[0x53]) = 0;
          iVar6 = FUN_0010b0f4(piVar11,0);
          iVar6 = FUN_000f5fea(*(undefined4 *)(iVar6 + 0x10));
          piVar11[3] = iVar6;
          FUN_0010ba02(piVar11,0,0,0,*param_1);
          cVar2 = (**(code **)(*local_4c + 0x14))(local_4c);
          if (cVar2 != '\0') {
            piVar11[5] = piVar11[5] | 0x20;
          }
          iVar6 = (**(code **)(*piVar11 + 0x7c))(piVar11);
          if (iVar6 == 0) {
            if ((*(int *)(piVar11[0x22] + 8) == 0x32) &&
               (cVar2 = (**(code **)(**(int **)(*param_1 + 0x54) + 0xd0))
                                  (*(int **)(*param_1 + 0x54)), cVar2 == '\0')) {
              piVar11[5] = piVar11[5] | 0x20;
            }
            else if (0 < piVar11[0x21]) {
              local_28 = 1;
              do {
                piVar10 = (int *)FUN_0010b180(piVar11,local_28);
                cVar2 = (**(code **)(*piVar10 + 0x5c))(piVar10);
                if ((cVar2 == '\0') &&
                   (cVar2 = (**(code **)(*piVar10 + 0x60))(piVar10), cVar2 == '\0')) {
                  if (piVar10[0x56] != piVar11[0x56]) {
                    piVar10[5] = piVar10[5] | 0x20;
                  }
                }
                else if (0 < piVar10[0x21]) {
                  local_3c = 1;
                  do {
                    piVar9 = (int *)FUN_0010b180(piVar10,local_3c);
                    cVar2 = (**(code **)(*piVar9 + 0x5c))(piVar9);
                    if (cVar2 == '\0') {
                      if (piVar9[0x56] != piVar11[0x56]) {
                        piVar9[5] = piVar9[5] | 0x20;
                      }
                    }
                    else if (0 < piVar9[0x21]) {
                      local_38 = 1;
                      do {
                        iVar6 = FUN_0010b180(piVar9,local_38);
                        if (*(int *)(iVar6 + 0x158) != piVar11[0x56]) {
                          *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) | 0x20;
                        }
                        local_38 = local_38 + 1;
                      } while (local_38 <= piVar9[0x21]);
                    }
                    local_3c = local_3c + 1;
                  } while (local_3c <= piVar10[0x21]);
                }
                local_28 = local_28 + 1;
              } while (local_28 <= piVar11[0x21]);
            }
            break;
          }
          piVar11[5] = piVar11[5] | 0x20;
          if (piVar11[0x21] < 1) break;
          iVar6 = 1;
          do {
            iVar5 = FUN_0010b180(piVar11,iVar6);
            *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x20;
            iVar6 = iVar6 + 1;
          } while (iVar6 <= piVar11[0x21]);
          piVar11 = (int *)piVar11[2];
          if (piVar11[2] == 0) goto LAB_00179a7a;
        }
        piVar11 = (int *)piVar11[2];
        iVar6 = piVar11[2];
      }
LAB_00179a7a:
      local_4c = (int *)local_4c[2];
    } while (local_4c[2] != 0);
    iVar6 = param_1[1];
  }
  local_20 = *(int *)(iVar6 + 0x378);
  if (*(int *)(local_20 + 8) != 0) {
    do {
      piVar11 = *(int **)(local_20 + 0x98);
      iVar6 = piVar11[2];
      while (iVar6 != 0) {
        if ((piVar11[5] & 1U) != 0) {
          if ((piVar11[5] & 0x200U) == 0) {
            cVar2 = (**(code **)(*piVar11 + 100))(piVar11);
            if (cVar2 == '\0') {
LAB_00179cb7:
              uVar7 = piVar11[5];
            }
            else {
              iVar5 = 1;
              iVar6 = (**(code **)(*piVar11 + 0x14))(piVar11);
              if (0 < iVar6) {
                do {
                  if ((((piVar11[iVar5 * 6 + 0x28] & 1U) != 0) ||
                      ((piVar11[iVar5 * 6 + 0x28] & 2U) != 0)) ||
                     (cVar2 = FUN_000f5a1e(piVar11,iVar5), cVar2 == '\0')) goto LAB_00179cb7;
                  iVar5 = iVar5 + 1;
                  iVar6 = (**(code **)(*piVar11 + 0x14))(piVar11);
                } while (iVar5 <= iVar6);
              }
              if (((char)piVar11[0x48] != '\0') || (piVar11[0x49] != 0)) goto LAB_00179cb7;
              if (((piVar11[0x20] != 0) &&
                  ((cVar2 = FUN_0012dfd8(piVar11[0x26]), cVar2 != '\0' &&
                   ((*(byte *)(piVar11 + 5) & 2) == 0)))) &&
                 (cVar2 = (**(code **)(*piVar11 + 0x50))(piVar11), cVar2 == '\0')) {
                iVar6 = 0;
                piVar10 = piVar11;
                do {
                  if ((byte)((char)piVar10[0x27] - 2U) < 2) goto LAB_00179cb7;
                  iVar6 = iVar6 + 1;
                  piVar10 = (int *)((int)piVar10 + 1);
                } while (iVar6 != 4);
              }
              FUN_0010b0f4(piVar11,0);
              iVar6 = FUN_0010b7c8(piVar11,0);
              if (iVar6 != 0) goto LAB_00179cb7;
              uVar7 = piVar11[5];
              if (((uVar7 & 2) == 0) && ((uVar7 & 0x200) == 0)) {
                iVar6 = piVar11[0x53];
                iVar5 = FUN_0010b180(piVar11,1);
                uVar1 = *(undefined4 *)(iVar5 + 0x14c);
                local_2c = FUN_001a8f90(iVar6,iVar3);
                iVar6 = FUN_001a8f90(uVar1,iVar3);
                if ((*(char *)(iVar4 + iVar6) == '\0') &&
                   (((*(char *)(iVar4 + local_2c) == '\0' && ((*(byte *)(piVar11 + 5) & 0x20) == 0))
                    && (iVar5 = FUN_0010b180(piVar11,1), (*(byte *)(iVar5 + 0x14) & 0x20) == 0)))) {
                  cVar2 = '\0';
                }
                else {
                  cVar2 = '\x01';
                }
                *(char *)(iVar4 + iVar6) = cVar2;
                *(char *)(iVar4 + local_2c) = cVar2;
                iVar5 = iVar6;
                if (iVar6 <= local_2c) {
                  iVar5 = local_2c;
                  local_2c = iVar6;
                }
                FUN_001a8fcc(local_2c,iVar5,iVar3);
                goto LAB_00179b69;
              }
            }
            if ((uVar7 & 0x20) != 0) {
              iVar6 = FUN_001a8f90(piVar11[0x53],iVar3);
              *(undefined1 *)(iVar4 + iVar6) = 1;
            }
          }
          else {
            iVar6 = piVar11[0x53];
            iVar5 = FUN_0010b180(piVar11,piVar11[0x21]);
            uVar1 = *(undefined4 *)(iVar5 + 0x14c);
            iVar6 = FUN_001a8f90(iVar6,iVar3);
            iVar5 = FUN_001a8f90(uVar1,iVar3);
            if (((*(char *)(iVar4 + iVar5) == '\0') && (*(char *)(iVar4 + iVar6) == '\0')) &&
               (((*(byte *)(piVar11 + 5) & 0x20) == 0 &&
                (iVar8 = FUN_0010b180(piVar11,piVar11[0x21]), (*(byte *)(iVar8 + 0x14) & 0x20) == 0)
                ))) {
              cVar2 = '\0';
            }
            else {
              cVar2 = '\x01';
            }
            *(char *)(iVar4 + iVar5) = cVar2;
            *(char *)(iVar4 + iVar6) = cVar2;
            iVar8 = iVar5;
            if (iVar5 <= iVar6) {
              iVar8 = iVar6;
              iVar6 = iVar5;
            }
            FUN_001a8fcc(iVar6,iVar8,iVar3);
          }
        }
LAB_00179b69:
        piVar11 = (int *)piVar11[2];
        iVar6 = piVar11[2];
      }
      local_20 = *(int *)(local_20 + 8);
    } while (*(int *)(local_20 + 8) != 0);
    iVar6 = param_1[1];
  }
  iVar6 = *(int *)(iVar6 + 0x378);
  if (*(int *)(iVar6 + 8) == 0) {
    local_48 = 0;
    local_44 = 0;
  }
  else {
    local_48 = 0;
    local_44 = 0;
    do {
      iVar8 = *(int *)(iVar6 + 0x98);
      iVar5 = *(int *)(iVar8 + 8);
      while (iVar5 != 0) {
        while ((*(byte *)(iVar8 + 0x14) & 1) != 0) {
          iVar5 = FUN_001a8f90(*(undefined4 *)(iVar8 + 0x14c),iVar3);
          if (*(char *)(iVar4 + iVar5) == '\0') {
            uVar7 = *(uint *)(iVar8 + 0x14) & 0xffffffdf;
            *(uint *)(iVar8 + 0x14) = uVar7;
          }
          else {
            uVar7 = *(uint *)(iVar8 + 0x14) | 0x20;
            *(uint *)(iVar8 + 0x14) = uVar7;
          }
          local_44 = (local_44 + 1) - (uint)((uVar7 & 0x20) == 0);
          local_48 = local_48 + 1;
          iVar8 = *(int *)(iVar8 + 8);
          if (*(int *)(iVar8 + 8) == 0) goto LAB_00179c18;
        }
        iVar8 = *(int *)(iVar8 + 8);
        iVar5 = *(int *)(iVar8 + 8);
      }
LAB_00179c18:
      iVar6 = *(int *)(iVar6 + 8);
    } while (*(int *)(iVar6 + 8) != 0);
  }
  FUN_000e1c3e(*param_1,"Scheduler : %d out of %d instructions are marked global\n",local_44,
               local_48);
  FUN_001a7aba(*(undefined4 *)(*param_1 + 0xbc),iVar4);
  FUN_001a7aba(*(undefined4 *)(*param_1 + 0xbc),iVar3);
  return;
}

/* FUN_0017a024 @ 0x17a024 (8044 bytes) */
int FUN_0017a024(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  undefined4 *puVar6;
  int iVar7;
  void *pvVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  int *piVar12;
  undefined4 *puVar13;
  int *piVar14;
  int iVar15;
  uint uVar16;
  uint *puVar17;
  uint *puVar18;
  int local_148;
  uint local_140;
  uint local_13c;
  int *local_138;
  uint local_e4;
  int local_e0;
  int local_dc;
  uint local_b8;
  uint local_70;
  int local_58;
  int local_50;
  uint local_48;
  uint local_44;
  int local_40;
  undefined1 local_34 [8];
  int local_2c;
  
  cVar5 = FUN_000e1402(*param_1,0x24);
  if (cVar5 == '\0') {
    local_140 = 0;
  }
  else {
    local_140 = 0x7fffffff;
  }
  param_1[4] = param_2;
  ((int (*)())FUN_001825e0)(param_1[2]);
  FUN_001a7e06(local_34);
  local_138 = *(int **)(param_1[4] + 0x98);
  if (local_138[2] != 0) {
    local_13c = 0;
    bVar3 = false;
    do {
      if ((local_138[5] & 1U) != 0) {
        local_138[5] = local_138[5] & 0xffffefff;
        local_138[0x54] = 0;
        cVar5 = (**(code **)(*local_138 + 0x34))(local_138);
        if ((cVar5 == '\0') && (cVar5 = (**(code **)(*local_138 + 0x38))(local_138), cVar5 == '\0'))
        {
          cVar5 = ((int (*)())FUN_0017422c)();
          if (cVar5 == '\0') {
            cVar5 = ((int (*)())FUN_001741ea)();
            if (((cVar5 != '\0') ||
                (cVar5 = (**(code **)(*(int *)param_1[3] + 0x2c))((int *)param_1[3],local_138),
                cVar5 != '\0')) ||
               (cVar5 = (**(code **)(*(int *)param_1[3] + 0x28))((int *)param_1[3],local_138),
               cVar5 != '\0')) {
              bVar3 = true;
            }
            local_138[0x54] = local_13c;
            uVar11 = *(undefined4 *)(*param_1 + 0xbc);
            puVar13 = (undefined4 *)FUN_001a7bca(uVar11,0x70);
            *puVar13 = uVar11;
            puVar6 = puVar13 + 1;
            puVar13[1] = PTR_DAT_00213441 + 8;
            puVar13[2] = 0;
            puVar13[3] = 0;
            puVar13[1] = PTR_DAT_00213a31 + 8;
            puVar13[0xc] = 0xffffffff;
            puVar13[0xd] = 0;
            puVar13[0xe] = 0;
            puVar13[0xf] = local_138;
            puVar13[0x10] = local_13c;
            puVar13[0x11] = 0;
            puVar13[0x12] = 0;
            puVar13[0x17] = 0;
            *(undefined1 *)(puVar13 + 0x18) = 0;
            puVar13[0x19] = 0;
            *(undefined1 *)(puVar13 + 0x1a) = 0;
            *(undefined1 *)((int)puVar13 + 0x69) = 0;
            puVar13[0x1b] = 0;
            iVar7 = 0;
            puVar10 = puVar6;
            do {
              puVar10[0x12] = 0;
              iVar7 = iVar7 + 1;
              puVar10 = puVar10 + 1;
            } while (iVar7 != 4);
            puVar13[4] = 0;
            puVar13[5] = 0;
            puVar13[6] = 1;
            puVar13[7] = 1;
            *(undefined1 *)(puVar13 + 8) = 0;
            puVar13[9] = 0;
            puVar13[10] = 0;
            puVar13[0xb] = 0;
            uVar11 = *(undefined4 *)(*param_1 + 0xbc);
            puVar10 = (undefined4 *)FUN_001a7bca(uVar11,0x14);
            *puVar10 = uVar11;
            puVar10[4] = uVar11;
            puVar10[2] = 0;
            puVar10[1] = 2;
            uVar11 = FUN_001a7bca(uVar11,8);
            puVar10[3] = uVar11;
            puVar13[0x12] = puVar10 + 1;
            uVar11 = *(undefined4 *)(*param_1 + 0xbc);
            puVar10 = (undefined4 *)FUN_001a7bca(uVar11,0x14);
            *puVar10 = uVar11;
            puVar10[4] = uVar11;
            puVar10[2] = 0;
            puVar10[1] = 2;
            uVar11 = FUN_001a7bca(uVar11,8);
            puVar10[3] = uVar11;
            puVar13[0x11] = puVar10 + 1;
            if (0 < local_138[0x21]) {
              local_148 = 1;
              bVar4 = false;
              do {
                ((int (*)())FUN_00177654)(param_1,puVar6,local_138,local_148,0);
                piVar9 = (int *)FUN_0010b180(local_138,local_148);
                cVar5 = (**(code **)(*piVar9 + 0x5c))(piVar9);
                if (cVar5 == '\0') {
                  piVar9 = (int *)FUN_0010b180(local_138,local_148);
                  cVar5 = (**(code **)(*piVar9 + 0x60))(piVar9);
                  if (cVar5 != '\0') goto LAB_0017ba3a;
                  uVar11 = FUN_0010b180(local_138,local_148);
                  cVar5 = FUN_0010a320(uVar11);
                  if ((cVar5 != '\0') &&
                     (cVar5 = (**(code **)(**(int **)(*param_1 + 0x54) + 0xd4))
                                        (*(int **)(*param_1 + 0x54)), cVar5 != '\0'))
                  goto LAB_0017ba3a;
                }
                else {
LAB_0017ba3a:
                  piVar9 = (int *)FUN_0010b180(local_138,local_148);
                  cVar5 = (**(code **)(*piVar9 + 0x60))(piVar9);
                  if (cVar5 != '\0') {
                    piVar12 = (int *)FUN_0010b180(piVar9,1);
                    cVar5 = (**(code **)(*piVar12 + 0x5c))(piVar12);
                    if (cVar5 != '\0') {
                      piVar9 = (int *)FUN_0010b180(piVar9,1);
                    }
                  }
                  for (iVar7 = 1; iVar15 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar7 <= iVar15;
                      iVar7 = iVar7 + 1) {
                    ((int (*)())FUN_00177654)(param_1,puVar6,piVar9,local_148,iVar7);
                  }
                }
                uVar11 = FUN_0010b180(local_138,local_148);
                cVar5 = FUN_0010a35a(uVar11);
                if (cVar5 != '\0') {
                  bVar4 = true;
                }
                local_148 = local_148 + 1;
              } while (local_148 <= local_138[0x21]);
              if (bVar4) {
                puVar17 = (uint *)puVar13[0x12];
                uVar16 = puVar17[1];
                if (0 < (int)uVar16) {
                  local_44 = 0;
                  while( true ) {
                    if (local_44 < *puVar17) {
                      uVar1 = puVar17[1];
                      if (uVar1 <= local_44) {
                        _memset((void *)(puVar17[2] + uVar1 * 4),0,(local_44 - uVar1) * 4 + 4);
                        puVar17[1] = local_44 + 1;
                      }
                      puVar10 = (undefined4 *)(puVar17[2] + local_44 * 4);
                    }
                    else {
                      puVar10 = (undefined4 *)FUN_001a7f7c(puVar17,local_44);
                    }
                    iVar7 = *(int *)*puVar10;
                    cVar5 = FUN_0010a35a(*(undefined4 *)(iVar7 + 0x38));
                    if (cVar5 == '\0') {
                      local_48 = 0;
                      do {
                        puVar17 = (uint *)puVar13[0x12];
                        if (local_48 < *puVar17) {
                          uVar1 = puVar17[1];
                          if (uVar1 <= local_48) {
                            _memset((void *)(puVar17[2] + uVar1 * 4),0,(local_48 - uVar1) * 4 + 4);
                            puVar17[1] = local_48 + 1;
                          }
                          puVar10 = (undefined4 *)(puVar17[2] + local_48 * 4);
                        }
                        else {
                          puVar10 = (undefined4 *)FUN_001a7f7c(puVar17,local_48);
                        }
                        iVar15 = *(int *)*puVar10;
                        cVar5 = FUN_0010a35a(*(undefined4 *)(iVar15 + 0x38));
                        if ((cVar5 != '\0') && (*(int *)(iVar7 + 0x3c) < *(int *)(iVar15 + 0x3c))) {
                          uVar11 = *(undefined4 *)(*param_1 + 0xbc);
                          puVar10 = (undefined4 *)FUN_001a7bca(uVar11,0x24);
                          *puVar10 = uVar11;
                          puVar10[1] = 0;
                          puVar10[2] = 0;
                          puVar10[3] = 0;
                          puVar10[4] = 1;
                          puVar10[5] = 0;
                          puVar10[6] = 0;
                          puVar10[7] = DAT_001cc6f4;
                          *(undefined1 *)(puVar10 + 8) = 0;
                          puVar10[1] = iVar7;
                          puVar10[2] = iVar15;
                          puVar10[3] = 5;
                          uVar11 = ((int (*)())FUN_0017412a)(param_1,*(undefined4 *)(iVar7 + 0x38),
                                                *(undefined4 *)(iVar15 + 0x38),0,0,5);
                          puVar10[4] = uVar11;
                          puVar17 = *(uint **)(iVar7 + 0x40);
                          uVar1 = puVar17[1];
                          if (uVar1 < *puVar17) {
                            _memset((void *)(uVar1 * 4 + puVar17[2]),0,4);
                            puVar17[1] = uVar1 + 1;
                            piVar9 = (int *)(uVar1 * 4 + puVar17[2]);
                          }
                          else {
                            piVar9 = (int *)FUN_001a7f7c(puVar17,uVar1);
                          }
                          *piVar9 = (int)(puVar10 + 1);
                          puVar17 = *(uint **)(iVar15 + 0x44);
                          uVar1 = puVar17[1];
                          if (uVar1 < *puVar17) {
                            _memset((void *)(uVar1 * 4 + puVar17[2]),0,4);
                            puVar17[1] = uVar1 + 1;
                            piVar9 = (int *)(uVar1 * 4 + puVar17[2]);
                          }
                          else {
                            piVar9 = (int *)FUN_001a7f7c(puVar17,uVar1);
                          }
                          *piVar9 = (int)(puVar10 + 1);
                        }
                        local_48 = local_48 + 1;
                      } while (uVar16 != local_48);
                    }
                    local_44 = local_44 + 1;
                    if (uVar16 == local_44) break;
                    puVar17 = (uint *)puVar13[0x12];
                  }
                }
              }
            }
            if (*(int *)(local_138[0x22] + 4) == 1) {
              FUN_001a7cd6(local_34,puVar6);
            }
            if (local_140 == local_13c) {
              uVar16 = local_13c - 1;
              if (-1 < (int)uVar16) {
                local_50 = uVar16 * 4;
                do {
                  puVar17 = (uint *)param_1[6];
                  if (uVar16 < *puVar17) {
                    uVar1 = puVar17[1];
                    if (uVar1 <= uVar16) {
                      _memset((void *)(puVar17[2] + uVar1 * 4),0,(uVar16 - uVar1) * 4 + 4);
                      puVar17[1] = uVar16 + 1;
                    }
                    piVar9 = (int *)(local_50 + puVar17[2]);
                  }
                  else {
                    piVar9 = (int *)FUN_001a7f7c(puVar17,uVar16);
                  }
                  iVar7 = *piVar9;
                  iVar15 = *(int *)(iVar7 + 0x38);
                  if (((*(byte *)(iVar15 + 0x14) & 2) == 0) &&
                     (*(int *)(*(int *)(iVar15 + 0x88) + 4) != 1)) {
                    uVar11 = *(undefined4 *)(*param_1 + 0xbc);
                    puVar10 = (undefined4 *)FUN_001a7bca(uVar11,0x24);
                    *puVar10 = uVar11;
                    puVar10[1] = 0;
                    puVar10[2] = 0;
                    puVar10[3] = 0;
                    puVar10[4] = 1;
                    puVar10[5] = 0;
                    puVar10[6] = 0;
                    puVar10[7] = DAT_001cc6f4;
                    *(undefined1 *)(puVar10 + 8) = 0;
                    puVar10[1] = iVar7;
                    puVar10[2] = puVar6;
                    puVar10[3] = 1;
                    uVar11 = ((int (*)())FUN_0017412a)(param_1,iVar15,local_138,0,0,1);
                    puVar10[4] = uVar11;
                    puVar17 = *(uint **)(iVar7 + 0x40);
                    uVar1 = puVar17[1];
                    if (uVar1 < *puVar17) {
                      _memset((void *)(uVar1 * 4 + puVar17[2]),0,4);
                      puVar17[1] = uVar1 + 1;
                      piVar9 = (int *)(uVar1 * 4 + puVar17[2]);
                    }
                    else {
                      piVar9 = (int *)FUN_001a7f7c(puVar17,uVar1);
                    }
                    *piVar9 = (int)(puVar10 + 1);
                    puVar17 = (uint *)puVar13[0x12];
                    uVar1 = puVar17[1];
                    if (uVar1 < *puVar17) {
                      _memset((void *)(uVar1 * 4 + puVar17[2]),0,4);
                      puVar17[1] = uVar1 + 1;
                      piVar9 = (int *)(uVar1 * 4 + puVar17[2]);
                    }
                    else {
                      piVar9 = (int *)FUN_001a7f7c(puVar17,uVar1);
                    }
                    *piVar9 = (int)(puVar10 + 1);
                  }
                  uVar16 = uVar16 - 1;
                  local_50 = local_50 + -4;
                } while (uVar16 != 0xffffffff);
              }
            }
            else if ((int)local_140 < (int)local_13c) {
              uVar16 = local_13c - 1;
              puVar17 = (uint *)param_1[6];
              if (uVar16 < *puVar17) {
                uVar1 = puVar17[1];
                if (uVar1 <= uVar16) {
                  _memset((void *)(puVar17[2] + uVar1 * 4),0,(uVar16 - uVar1) * 4 + 4);
                  puVar17[1] = local_13c;
                }
                piVar9 = (int *)(puVar17[2] + uVar16 * 4);
              }
              else {
                piVar9 = (int *)FUN_001a7f7c(puVar17,uVar16);
              }
              iVar7 = *piVar9;
              iVar15 = *(int *)(iVar7 + 0x38);
              if (*(int *)(*(int *)(iVar15 + 0x88) + 4) != 1) {
                uVar11 = *(undefined4 *)(*param_1 + 0xbc);
                puVar10 = (undefined4 *)FUN_001a7bca(uVar11,0x24);
                *puVar10 = uVar11;
                puVar10[1] = 0;
                puVar10[2] = 0;
                puVar10[3] = 0;
                puVar10[4] = 1;
                puVar10[5] = 0;
                puVar10[6] = 0;
                puVar10[7] = DAT_001cc6f4;
                *(undefined1 *)(puVar10 + 8) = 0;
                puVar10[1] = iVar7;
                puVar10[2] = puVar6;
                puVar10[3] = 1;
                uVar11 = ((int (*)())FUN_0017412a)(param_1,iVar15,local_138,0,0,1);
                puVar10[4] = uVar11;
                puVar17 = *(uint **)(iVar7 + 0x40);
                uVar16 = puVar17[1];
                if (uVar16 < *puVar17) {
                  _memset((void *)(uVar16 * 4 + puVar17[2]),0,4);
                  puVar17[1] = uVar16 + 1;
                  piVar9 = (int *)(uVar16 * 4 + puVar17[2]);
                }
                else {
                  piVar9 = (int *)FUN_001a7f7c(puVar17,uVar16);
                }
                *piVar9 = (int)(puVar10 + 1);
                puVar17 = (uint *)puVar13[0x12];
                uVar16 = puVar17[1];
                if (uVar16 < *puVar17) {
                  _memset((void *)(uVar16 * 4 + puVar17[2]),0,4);
                  puVar17[1] = uVar16 + 1;
                  piVar9 = (int *)(uVar16 * 4 + puVar17[2]);
                }
                else {
                  piVar9 = (int *)FUN_001a7f7c(puVar17,uVar16);
                }
                *piVar9 = (int)(puVar10 + 1);
              }
            }
            puVar17 = (uint *)param_1[6];
            uVar16 = puVar17[1];
            if (uVar16 < *puVar17) {
              _memset((void *)(uVar16 * 4 + puVar17[2]),0,4);
              puVar17[1] = uVar16 + 1;
              piVar9 = (int *)(uVar16 * 4 + puVar17[2]);
            }
            else {
              piVar9 = (int *)FUN_001a7f7c(puVar17,uVar16);
            }
            *piVar9 = (int)puVar6;
            local_13c = local_13c + 1;
          }
          else if (((((local_138[0x20] != 0) &&
                     (cVar5 = FUN_0012dfd8(local_138[0x26]), cVar5 != '\0')) &&
                    ((*(byte *)(local_138 + 5) & 2) == 0)) &&
                   ((cVar5 = (**(code **)(*local_138 + 0x50))(local_138), cVar5 == '\0' &&
                    ((local_138[5] & 0x40U) == 0)))) &&
                  (((local_138[5] & 0x20U) != 0 ||
                   (cVar5 = FUN_000e1402(*param_1,0x25), cVar5 == '\0')))) {
            iVar7 = local_138[0x26];
            iVar15 = *(int *)(*param_1 + 0x108) + 1;
            *(int *)(*param_1 + 0x108) = iVar15;
            local_138[0x25] = iVar15;
            local_138[0x26] = iVar7;
          }
        }
      }
      local_138 = (int *)local_138[2];
    } while (local_138[2] != 0);
    if (bVar3) {
      uVar11 = *(undefined4 *)(*param_1 + 0xbc);
      puVar6 = (undefined4 *)FUN_001a7bca(uVar11,0x1c);
      *puVar6 = uVar11;
      puVar17 = puVar6 + 1;
      puVar6[4] = FUN_00173ede;
      puVar6[5] = FUN_00173f0e;
      puVar6[6] = uVar11;
      puVar6[1] = 1;
      iVar7 = 0;
      uVar16 = 1;
      do {
        uVar16 = uVar16 * 2;
        if (0xf < uVar16) {
          *puVar17 = uVar16;
          goto LAB_0017a271;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 != 0x20);
      *puVar17 = uVar16;
LAB_0017a271:
      puVar6[2] = 0;
      pvVar8 = (void *)FUN_001a7bca(uVar11,*puVar17 << 2);
      puVar6[3] = pvVar8;
      _memset(pvVar8,0,*puVar17 << 2);
      local_e4 = local_13c - 1;
      if (-1 < (int)local_e4) {
        local_58 = local_e4 * 4;
        local_e0 = 0;
        local_dc = 0;
        do {
          puVar18 = (uint *)param_1[6];
          if (local_e4 < *puVar18) {
            uVar16 = puVar18[1];
            if (uVar16 <= local_e4) {
              _memset((void *)(puVar18[2] + uVar16 * 4),0,(local_e4 - uVar16) * 4 + 4);
              puVar18[1] = local_e4 + 1;
            }
            piVar9 = (int *)(local_58 + puVar18[2]);
          }
          else {
            piVar9 = (int *)FUN_001a7f7c(puVar18,local_e4);
          }
          iVar7 = *piVar9;
          piVar9 = *(int **)(iVar7 + 0x38);
          cVar5 = ((int (*)())FUN_001741ea)();
          if (cVar5 != '\0') {
            iVar15 = FUN_001a84b2(puVar17,piVar9);
            if (iVar15 != 0) {
              uVar16 = *(uint *)(iVar15 + 0x150);
              puVar18 = (uint *)param_1[6];
              if (uVar16 < *puVar18) {
                uVar1 = puVar18[1];
                if (uVar1 <= uVar16) {
                  _memset((void *)(puVar18[2] + uVar1 * 4),0,(uVar16 - uVar1) * 4 + 4);
                  puVar18[1] = uVar16 + 1;
                }
                piVar12 = (int *)(puVar18[2] + uVar16 * 4);
              }
              else {
                piVar12 = (int *)FUN_001a7f7c(puVar18,uVar16);
              }
              iVar2 = *piVar12;
              uVar11 = *(undefined4 *)(*param_1 + 0xbc);
              puVar10 = (undefined4 *)FUN_001a7bca(uVar11,0x24);
              *puVar10 = uVar11;
              puVar10[4] = 1;
              puVar10[5] = 0;
              puVar10[6] = 0;
              puVar10[7] = DAT_001cc6f4;
              *(undefined1 *)(puVar10 + 8) = 0;
              puVar10[1] = iVar7;
              puVar10[2] = iVar2;
              puVar10[3] = 1;
              uVar11 = ((int (*)())FUN_0017412a)(param_1,piVar9,iVar15,0,0,1);
              puVar10[4] = uVar11;
              puVar18 = *(uint **)(iVar7 + 0x40);
              uVar16 = puVar18[1];
              if (uVar16 < *puVar18) {
                _memset((void *)(uVar16 * 4 + puVar18[2]),0,4);
                puVar18[1] = uVar16 + 1;
                piVar12 = (int *)(uVar16 * 4 + puVar18[2]);
              }
              else {
                piVar12 = (int *)FUN_001a7f7c(puVar18,uVar16);
              }
              *piVar12 = (int)(puVar10 + 1);
              puVar18 = *(uint **)(iVar2 + 0x44);
              uVar16 = puVar18[1];
              if (uVar16 < *puVar18) {
                _memset((void *)(uVar16 * 4 + puVar18[2]),0,4);
                puVar18[1] = uVar16 + 1;
                piVar12 = (int *)(uVar16 * 4 + puVar18[2]);
              }
              else {
                piVar12 = (int *)FUN_001a7f7c(puVar18,uVar16);
              }
              *piVar12 = (int)(puVar10 + 1);
              FUN_001a83e0(puVar17,iVar15);
            }
            FUN_001a89d8(puVar17,piVar9);
          }
          cVar5 = (**(code **)(*(int *)param_1[3] + 0x28))((int *)param_1[3],piVar9);
          iVar15 = local_e0;
          if ((cVar5 != '\0') && (iVar15 = iVar7, local_e0 != 0)) {
            uVar11 = *(undefined4 *)(*param_1 + 0xbc);
            puVar13 = (undefined4 *)FUN_001a7bca(uVar11,0x24);
            *puVar13 = uVar11;
            puVar10 = puVar13 + 1;
            puVar13[4] = 1;
            puVar13[5] = 0;
            puVar13[6] = 0;
            puVar13[7] = DAT_001cc6f4;
            *(undefined1 *)(puVar13 + 8) = 0;
            puVar13[1] = iVar7;
            puVar13[2] = local_e0;
            puVar13[3] = 4;
            uVar11 = ((int (*)())FUN_0017412a)(param_1,piVar9,*(undefined4 *)(local_e0 + 0x38),0,0,4);
            puVar13[4] = uVar11;
            puVar18 = *(uint **)(iVar7 + 0x40);
            uVar16 = puVar18[1];
            if (uVar16 < *puVar18) {
              _memset((void *)(uVar16 * 4 + puVar18[2]),0,4);
              puVar18[1] = uVar16 + 1;
              *(undefined4 **)(uVar16 * 4 + puVar18[2]) = puVar10;
              puVar18 = *(uint **)(local_e0 + 0x44);
              local_b8 = puVar18[1];
              if (local_b8 < *puVar18) goto LAB_0017a639;
LAB_0017b22f:
              piVar12 = (int *)FUN_001a7f7c(puVar18,local_b8);
            }
            else {
              piVar12 = (int *)FUN_001a7f7c(puVar18,uVar16);
              *piVar12 = (int)puVar10;
              puVar18 = *(uint **)(local_e0 + 0x44);
              local_b8 = puVar18[1];
              if (*puVar18 <= local_b8) goto LAB_0017b22f;
LAB_0017a639:
              _memset((void *)(local_b8 * 4 + puVar18[2]),0,4);
              puVar18[1] = local_b8 + 1;
              piVar12 = (int *)(local_b8 * 4 + puVar18[2]);
            }
            *piVar12 = (int)puVar10;
          }
          local_e0 = iVar15;
          cVar5 = (**(code **)(*(int *)param_1[3] + 0x2c))((int *)param_1[3],piVar9);
          iVar15 = local_dc;
          if ((cVar5 != '\0') && (iVar15 = iVar7, local_dc != 0)) {
            uVar11 = *(undefined4 *)(*param_1 + 0xbc);
            puVar10 = (undefined4 *)FUN_001a7bca(uVar11,0x24);
            *puVar10 = uVar11;
            puVar10[4] = 1;
            puVar10[5] = 0;
            puVar10[6] = 0;
            puVar10[7] = DAT_001cc6f4;
            *(undefined1 *)(puVar10 + 8) = 0;
            puVar10[1] = iVar7;
            puVar10[2] = local_dc;
            puVar10[3] = 4;
            uVar11 = ((int (*)())FUN_0017412a)(param_1,piVar9,*(undefined4 *)(local_dc + 0x38),0,0,4);
            puVar10[4] = uVar11;
            puVar18 = *(uint **)(iVar7 + 0x40);
            uVar16 = puVar18[1];
            if (uVar16 < *puVar18) {
              _memset((void *)(uVar16 * 4 + puVar18[2]),0,4);
              puVar18[1] = uVar16 + 1;
              piVar12 = (int *)(uVar16 * 4 + puVar18[2]);
            }
            else {
              piVar12 = (int *)FUN_001a7f7c(puVar18,uVar16);
            }
            *piVar12 = (int)(puVar10 + 1);
            puVar18 = *(uint **)(local_dc + 0x44);
            uVar16 = puVar18[1];
            if (uVar16 < *puVar18) {
              _memset((void *)(uVar16 * 4 + puVar18[2]),0,4);
              puVar18[1] = uVar16 + 1;
              piVar12 = (int *)(uVar16 * 4 + puVar18[2]);
            }
            else {
              piVar12 = (int *)FUN_001a7f7c(puVar18,uVar16);
            }
            *piVar12 = (int)(puVar10 + 1);
          }
          local_dc = iVar15;
          if (0 < piVar9[0x21]) {
            local_40 = 1;
            do {
              while( true ) {
                FUN_0010b180(piVar9,local_40);
                cVar5 = ((int (*)())FUN_001741ea)();
                if (cVar5 != '\0') break;
LAB_0017a81c:
                local_40 = local_40 + 1;
                if (piVar9[0x21] < local_40) goto LAB_0017aa10;
              }
              uVar11 = FUN_0010b180(piVar9,local_40);
              piVar12 = (int *)FUN_001a84b2(puVar17,uVar11);
              if ((piVar12 == (int *)0x0) || (piVar9 == piVar12)) goto LAB_0017a81c;
              uVar16 = piVar12[0x54];
              puVar18 = (uint *)param_1[6];
              if (uVar16 < *puVar18) {
                uVar1 = puVar18[1];
                if (uVar1 <= uVar16) {
                  _memset((void *)(puVar18[2] + uVar1 * 4),0,(uVar16 - uVar1) * 4 + 4);
                  puVar18[1] = uVar16 + 1;
                }
                piVar14 = (int *)(puVar18[2] + uVar16 * 4);
              }
              else {
                piVar14 = (int *)FUN_001a7f7c(puVar18,uVar16);
              }
              iVar15 = *piVar14;
              uVar11 = *(undefined4 *)(*param_1 + 0xbc);
              puVar10 = (undefined4 *)FUN_001a7bca(uVar11,0x24);
              *puVar10 = uVar11;
              puVar10[4] = 1;
              puVar10[5] = 0;
              puVar10[6] = 0;
              puVar10[7] = DAT_001cc6f4;
              *(undefined1 *)(puVar10 + 8) = 0;
              puVar10[1] = iVar7;
              puVar10[2] = iVar15;
              puVar10[3] = 2;
              uVar11 = ((int (*)())FUN_0017412a)(param_1,piVar9,piVar12,local_40,0,2);
              puVar10[4] = uVar11;
              puVar18 = *(uint **)(iVar7 + 0x40);
              uVar16 = puVar18[1];
              if (uVar16 < *puVar18) {
                _memset((void *)(uVar16 * 4 + puVar18[2]),0,4);
                puVar18[1] = uVar16 + 1;
                piVar12 = (int *)(uVar16 * 4 + puVar18[2]);
              }
              else {
                piVar12 = (int *)FUN_001a7f7c(puVar18,uVar16);
              }
              *piVar12 = (int)(puVar10 + 1);
              puVar18 = *(uint **)(iVar15 + 0x44);
              uVar16 = puVar18[1];
              if (uVar16 < *puVar18) {
                _memset((void *)(uVar16 * 4 + puVar18[2]),0,4);
                puVar18[1] = uVar16 + 1;
                piVar12 = (int *)(uVar16 * 4 + puVar18[2]);
              }
              else {
                piVar12 = (int *)FUN_001a7f7c(puVar18,uVar16);
              }
              *piVar12 = (int)(puVar10 + 1);
              local_40 = local_40 + 1;
            } while (local_40 <= piVar9[0x21]);
          }
LAB_0017aa10:
          cVar5 = (**(code **)(*piVar9 + 0x28))(piVar9);
          if ((cVar5 != '\0') && (local_dc != 0)) {
            uVar11 = *(undefined4 *)(*param_1 + 0xbc);
            puVar10 = (undefined4 *)FUN_001a7bca(uVar11,0x24);
            *puVar10 = uVar11;
            puVar10[4] = 1;
            puVar10[5] = 0;
            puVar10[6] = 0;
            puVar10[7] = DAT_001cc6f4;
            *(undefined1 *)(puVar10 + 8) = 0;
            puVar10[1] = iVar7;
            puVar10[2] = local_dc;
            puVar10[3] = 4;
            uVar11 = ((int (*)())FUN_0017412a)(param_1,piVar9,*(undefined4 *)(local_dc + 0x38),0,0,4);
            puVar10[4] = uVar11;
            puVar18 = *(uint **)(iVar7 + 0x40);
            uVar16 = puVar18[1];
            if (uVar16 < *puVar18) {
              _memset((void *)(uVar16 * 4 + puVar18[2]),0,4);
              puVar18[1] = uVar16 + 1;
              piVar12 = (int *)(uVar16 * 4 + puVar18[2]);
            }
            else {
              piVar12 = (int *)FUN_001a7f7c(puVar18,uVar16);
            }
            *piVar12 = (int)(puVar10 + 1);
            puVar18 = *(uint **)(local_dc + 0x44);
            uVar16 = puVar18[1];
            if (uVar16 < *puVar18) {
              _memset((void *)(uVar16 * 4 + puVar18[2]),0,4);
              puVar18[1] = uVar16 + 1;
              piVar12 = (int *)(uVar16 * 4 + puVar18[2]);
            }
            else {
              piVar12 = (int *)FUN_001a7f7c(puVar18,uVar16);
            }
            *piVar12 = (int)(puVar10 + 1);
          }
          cVar5 = (**(code **)(*piVar9 + 0x24))(piVar9);
          if (((cVar5 != '\0') && ((*(byte *)(piVar9 + 5) & 2) == 0)) && (local_e0 != 0)) {
            uVar11 = *(undefined4 *)(*param_1 + 0xbc);
            puVar10 = (undefined4 *)FUN_001a7bca(uVar11,0x24);
            *puVar10 = uVar11;
            puVar10[4] = 1;
            puVar10[5] = 0;
            puVar10[6] = 0;
            puVar10[7] = DAT_001cc6f4;
            *(undefined1 *)(puVar10 + 8) = 0;
            puVar10[1] = iVar7;
            puVar10[2] = local_e0;
            puVar10[3] = 4;
            uVar11 = ((int (*)())FUN_0017412a)(param_1,piVar9,*(undefined4 *)(local_e0 + 0x38),0,0,4);
            puVar10[4] = uVar11;
            puVar18 = *(uint **)(iVar7 + 0x40);
            uVar16 = puVar18[1];
            if (uVar16 < *puVar18) {
              _memset((void *)(uVar16 * 4 + puVar18[2]),0,4);
              puVar18[1] = uVar16 + 1;
              piVar12 = (int *)(uVar16 * 4 + puVar18[2]);
            }
            else {
              piVar12 = (int *)FUN_001a7f7c(puVar18,uVar16);
            }
            *piVar12 = (int)(puVar10 + 1);
            puVar18 = *(uint **)(local_e0 + 0x44);
            uVar16 = puVar18[1];
            if (uVar16 < *puVar18) {
              _memset((void *)(uVar16 * 4 + puVar18[2]),0,4);
              puVar18[1] = uVar16 + 1;
              piVar12 = (int *)(uVar16 * 4 + puVar18[2]);
            }
            else {
              piVar12 = (int *)FUN_001a7f7c(puVar18,uVar16);
            }
            *piVar12 = (int)(puVar10 + 1);
          }
          cVar5 = (**(code **)(*(int *)param_1[3] + 0x20))((int *)param_1[3],piVar9);
          if ((cVar5 != '\0') && (cVar5 = FUN_001a7c84(local_34), cVar5 == '\0')) {
            iVar15 = *(int *)(local_2c + 8);
            iVar2 = local_2c;
            while (iVar15 != 0) {
              uVar11 = *(undefined4 *)(*param_1 + 0xbc);
              puVar13 = (undefined4 *)FUN_001a7bca(uVar11,0x24);
              *puVar13 = uVar11;
              puVar10 = puVar13 + 1;
              puVar13[4] = 1;
              puVar13[5] = 0;
              puVar13[6] = 0;
              puVar13[7] = DAT_001cc6f4;
              *(undefined1 *)(puVar13 + 8) = 0;
              puVar13[1] = iVar7;
              puVar13[2] = iVar2;
              puVar13[3] = 4;
              uVar11 = ((int (*)())FUN_0017412a)(param_1,piVar9,*(undefined4 *)(iVar2 + 0x38),0,0,4);
              puVar13[4] = uVar11;
              puVar18 = *(uint **)(iVar7 + 0x40);
              uVar16 = puVar18[1];
              if (uVar16 < *puVar18) {
                _memset((void *)(uVar16 * 4 + puVar18[2]),0,4);
                puVar18[1] = uVar16 + 1;
                *(undefined4 **)(uVar16 * 4 + puVar18[2]) = puVar10;
                puVar18 = *(uint **)(iVar2 + 0x44);
                local_70 = puVar18[1];
                if (local_70 < *puVar18) goto LAB_0017ae26;
LAB_0017af46:
                piVar12 = (int *)FUN_001a7f7c(puVar18,local_70);
              }
              else {
                piVar12 = (int *)FUN_001a7f7c(puVar18,uVar16);
                *piVar12 = (int)puVar10;
                puVar18 = *(uint **)(iVar2 + 0x44);
                local_70 = puVar18[1];
                if (*puVar18 <= local_70) goto LAB_0017af46;
LAB_0017ae26:
                _memset((void *)(local_70 * 4 + puVar18[2]),0,4);
                puVar18[1] = local_70 + 1;
                piVar12 = (int *)(local_70 * 4 + puVar18[2]);
              }
              *piVar12 = (int)puVar10;
              iVar2 = *(int *)(iVar2 + 8);
              iVar15 = *(int *)(iVar2 + 8);
            }
          }
          if (((*(int *)(param_1[1] + 0x33c) != 0) &&
              (*(int *)(*(int *)(*param_1 + 0x54) + 0x20) <
               *(int *)(*(int *)(param_1[1] + 0x33c) + 300))) &&
             (cVar5 = (**(code **)(*(int *)param_1[2] + 0x28))((int *)param_1[2],piVar9),
             cVar5 != '\0')) {
            iVar15 = *(int *)(local_2c + 8);
            iVar2 = local_2c;
            while (iVar15 != 0) {
              if (*(int *)(iVar2 + 0x38) == *(int *)(param_1[1] + 0x33c)) {
                uVar11 = *(undefined4 *)(*param_1 + 0xbc);
                puVar13 = (undefined4 *)FUN_001a7bca(uVar11,0x24);
                *puVar13 = uVar11;
                puVar10 = puVar13 + 1;
                puVar13[4] = 1;
                puVar13[5] = 0;
                puVar13[6] = 0;
                puVar13[7] = DAT_001cc6f4;
                *(undefined1 *)(puVar13 + 8) = 0;
                puVar13[1] = iVar7;
                puVar13[2] = iVar2;
                puVar13[3] = 2;
                uVar11 = ((int (*)())FUN_0017412a)(param_1,piVar9,*(undefined4 *)(iVar2 + 0x38),0,0,2);
                puVar13[4] = uVar11;
                puVar18 = *(uint **)(iVar7 + 0x40);
                uVar16 = puVar18[1];
                if (uVar16 < *puVar18) {
                  _memset((void *)(uVar16 * 4 + puVar18[2]),0,4);
                  puVar18[1] = uVar16 + 1;
                  piVar12 = (int *)(uVar16 * 4 + puVar18[2]);
                }
                else {
                  piVar12 = (int *)FUN_001a7f7c(puVar18,uVar16);
                }
                *piVar12 = (int)puVar10;
                puVar18 = *(uint **)(iVar2 + 0x44);
                uVar16 = puVar18[1];
                if (uVar16 < *puVar18) {
                  _memset((void *)(uVar16 * 4 + puVar18[2]),0,4);
                  puVar18[1] = uVar16 + 1;
                  *(undefined4 **)(uVar16 * 4 + puVar18[2]) = puVar10;
                }
                else {
                  piVar12 = (int *)FUN_001a7f7c(puVar18,uVar16);
                  *piVar12 = (int)puVar10;
                }
              }
              iVar2 = *(int *)(iVar2 + 8);
              iVar15 = *(int *)(iVar2 + 8);
            }
          }
          local_e4 = local_e4 - 1;
          local_58 = local_58 + -4;
        } while (local_e4 != 0xffffffff);
      }
      if (puVar17 != (uint *)0x0) {
        if (*puVar17 == 0) {
          iVar7 = puVar6[3];
        }
        else {
          uVar16 = 0;
          iVar7 = puVar6[3];
          do {
            iVar15 = *(int *)(iVar7 + uVar16 * 4);
            if (iVar15 != 0) {
              FUN_001a7aba(puVar6[6],iVar15);
              iVar7 = puVar6[3];
            }
            uVar16 = uVar16 + 1;
          } while (uVar16 < *puVar17);
        }
        FUN_001a7aba(puVar6[6],iVar7);
        if (puVar17 != (uint *)0x0) {
          FUN_001a7aba(*puVar6,puVar6);
        }
      }
    }
  }
  return;
}

/* FUN_0017bfe0 @ 0x17bfe0 (1180 bytes) */
int FUN_0017bfe0(param_1)
  int *param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  char cVar10;
  int *piVar11;
  undefined4 *puVar12;
  uint *puVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint *local_58;
  uint local_54;
  uint local_44;
  uint local_2c;
  uint local_28;
  int local_24;
  undefined4 local_20;
  
  uVar2 = *(uint *)(param_1[6] + 4);
  local_20 = *(undefined4 *)(*param_1 + 0xbc);
  local_28 = 0;
  local_2c = 2;
  local_24 = FUN_001a7bca(local_20,8);
  if (0 < (int)uVar2) {
    local_54 = 0;
    local_58 = (uint *)0x0;
    do {
      puVar13 = (uint *)param_1[6];
      if (local_54 < *puVar13) {
        uVar1 = puVar13[1];
        if (uVar1 <= local_54) {
          _memset((void *)(puVar13[2] + uVar1 * 4),0,(local_54 - uVar1) * 4 + 4);
          puVar13[1] = local_54 + 1;
        }
        iVar3 = *(int *)(puVar13[2] + local_54 * 4);
        iVar14 = *(int *)(iVar3 + 0x60);
      }
      else {
        piVar11 = (int *)FUN_001a7f7c(puVar13,local_54);
        iVar3 = *piVar11;
        iVar14 = *(int *)(iVar3 + 0x60);
      }
      if (((((iVar14 == 0) && (piVar11 = *(int **)(iVar3 + 0x38), piVar11[0x20] != 0)) &&
           (cVar10 = FUN_0012dfd8(piVar11[0x26]), cVar10 != '\0')) &&
          (((*(byte *)(piVar11 + 5) & 2) == 0 &&
           (cVar10 = (**(code **)(*piVar11 + 0x50))(piVar11), cVar10 == '\0')))) &&
         ((*(byte *)(*(int *)(iVar3 + 0x38) + 0x14) & 0x20) == 0)) {
        if (local_58 == (uint *)0x0) {
          uVar9 = *(undefined4 *)(*param_1 + 0xbc);
          puVar12 = (undefined4 *)FUN_001a7bca(uVar9,0x2c);
          *puVar12 = uVar9;
          local_58 = puVar12 + 1;
          puVar12[1] = DAT_001cc708;
          puVar12[2] = 0xffffffff;
          puVar12[3] = 0;
          puVar12[4] = DAT_001cc6f8;
          puVar12[5] = 0;
          puVar12[6] = 0x7fffffff;
          iVar14 = 4;
          puVar13 = local_58;
          do {
            puVar13[6] = 0;
            puVar13 = puVar13 + 1;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
        }
        uVar1 = local_28;
        *(uint **)(iVar3 + 0x60) = local_58;
        local_58[4] = 1;
        *local_58 = *(uint *)(*(int *)(iVar3 + 0x38) + 0xc);
        if (local_28 < local_2c) {
          iVar14 = local_28 * 4;
          _memset((void *)(iVar14 + local_24),0,4);
          local_28 = uVar1 + 1;
          piVar11 = (int *)(iVar14 + local_24);
        }
        else {
          piVar11 = (int *)FUN_001a7f7c(&local_2c,local_28);
        }
        *piVar11 = iVar3;
LAB_0017c142:
        if (local_28 != 0) {
          uVar1 = local_28 - 1;
          if (uVar1 < local_28) {
            piVar11 = (int *)(local_24 + uVar1 * 4);
          }
          else {
            piVar11 = (int *)0x0;
          }
          iVar14 = *piVar11;
          FUN_001a7f3c(&local_2c,uVar1);
          puVar13 = *(uint **)(iVar14 + 0x40);
          uVar1 = puVar13[1];
          if (0 < (int)uVar1) {
            local_44 = 0;
            if (*puVar13 == 0) goto LAB_0017c2a9;
            do {
              uVar4 = puVar13[1];
              if (uVar4 <= local_44) {
                _memset((void *)(puVar13[2] + uVar4 * 4),0,(local_44 - uVar4) * 4 + 4);
                puVar13[1] = local_44 + 1;
              }
              piVar11 = (int *)(puVar13[2] + local_44 * 4);
              while( true ) {
                iVar5 = *piVar11;
                if (*(int *)(iVar5 + 8) == 0) {
                  iVar6 = *(int *)(iVar5 + 4);
                  puVar13 = *(uint **)(iVar6 + 0x44);
                  uVar4 = puVar13[1];
                  if (0 < (int)uVar4) {
                    uVar16 = 0;
                    while( true ) {
                      if (uVar16 < *puVar13) {
                        uVar7 = puVar13[1];
                        if (uVar7 <= uVar16) {
                          _memset((void *)(puVar13[2] + uVar7 * 4),0,(uVar16 - uVar7) * 4 + 4);
                          puVar13[1] = uVar16 + 1;
                        }
                        piVar11 = (int *)(puVar13[2] + uVar16 * 4);
                      }
                      else {
                        piVar11 = (int *)FUN_001a7f7c(puVar13,uVar16);
                      }
                      uVar7 = local_28;
                      piVar11 = (int *)*piVar11;
                      if (((piVar11[2] == 0) && (piVar11[4] == *(int *)(iVar5 + 0x10))) &&
                         ((piVar11[5] == *(int *)(iVar5 + 0x14) && (*(int *)(*piVar11 + 0x60) == 0))
                         )) {
                        *(uint **)(*piVar11 + 0x60) = local_58;
                        local_58[4] = local_58[4] + 1;
                        *local_58 = *local_58 | *(uint *)(*(int *)(*piVar11 + 0x38) + 0xc);
                        iVar8 = *piVar11;
                        if (local_28 < local_2c) {
                          iVar15 = local_28 * 4;
                          _memset((void *)(iVar15 + local_24),0,4);
                          local_28 = uVar7 + 1;
                          *(int *)(iVar15 + local_24) = iVar8;
                        }
                        else {
                          piVar11 = (int *)FUN_001a7f7c(&local_2c,local_28);
                          *piVar11 = iVar8;
                        }
                      }
                      uVar16 = uVar16 + 1;
                      if (uVar4 == uVar16) break;
                      puVar13 = *(uint **)(iVar6 + 0x44);
                    }
                  }
                }
                local_44 = local_44 + 1;
                if (uVar1 == local_44) goto LAB_0017c142;
                puVar13 = *(uint **)(iVar14 + 0x40);
                if (local_44 < *puVar13) break;
LAB_0017c2a9:
                piVar11 = (int *)FUN_001a7f7c(puVar13,local_44);
              }
            } while( true );
          }
          goto LAB_0017c142;
        }
        if (local_58[4] == 1) {
          *(undefined4 *)(iVar3 + 0x60) = 0;
          *local_58 = DAT_001cc708;
          local_58[4] = 0;
        }
        else {
          local_58 = (uint *)0x0;
        }
      }
      local_54 = local_54 + 1;
    } while (uVar2 != local_54);
    if (local_58 != (uint *)0x0) {
      FUN_001a7aba(local_58[-1],local_58 + -1);
    }
  }
  FUN_001a7aba(local_20,local_24);
  return;
}

/* FUN_0017c498 @ 0x17c498 (1225 bytes) */
int FUN_0017c498(param_1)
  int *param_1;
{
  void *pvVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  void *pvVar7;
  int iVar8;
  int *piVar9;
  int local_4c;
  int local_48;
  int local_40;
  int local_38;
  int local_34;
  int *local_2c;
  int *local_28;
  int local_24;
  
  piVar3 = (int *)param_1[0xb];
  iVar4 = *piVar3;
  if (iVar4 == 0) {
    iVar4 = piVar3[1];
    if ((((iVar4 != 0) && (*(char *)(iVar4 + 100) == '\0')) && (*(int *)(iVar4 + 0x60) == 0)) &&
       (*(int *)(*(int *)(iVar4 + 0x38) + 0x98) == 1)) {
      *(undefined4 *)(*(int *)(iVar4 + 0x38) + 0x98) = 0;
      piVar3 = (int *)param_1[0xb];
    }
  }
  else if (((piVar3[1] == 0) && (*(char *)(iVar4 + 100) == '\0')) &&
          ((*(int *)(iVar4 + 0x60) == 0 && (*(int *)(*(int *)(iVar4 + 0x38) + 0x98) == 1)))) {
    *(undefined4 *)(*(int *)(iVar4 + 0x38) + 0x98) = 0;
    piVar3 = (int *)param_1[0xb];
  }
  local_4c = 0;
  while( true ) {
    iVar4 = piVar3[local_4c];
    local_4c = local_4c + 1;
    if (((iVar4 != 0) && (piVar3 = *(int **)(iVar4 + 0x38), piVar3[0x20] != 0)) &&
       ((cVar2 = FUN_0012dfd8(piVar3[0x26]), cVar2 != '\0' &&
        ((((*(byte *)(piVar3 + 5) & 2) == 0 &&
          (cVar2 = (**(code **)(*piVar3 + 0x50))(piVar3), cVar2 == '\0')) &&
         ((*(byte *)(piVar3 + 5) & 0x40) != 0)))))) {
      iVar8 = piVar3[0x25];
      local_28 = param_1;
      local_48 = 0;
      do {
        iVar5 = FUN_0010b0f4(piVar3,0);
        if (*(char *)(local_48 + 0x10 + iVar5) != '\x01') {
          *(int *)(local_28[0x4c] + iVar8 * 4) = iVar4;
        }
        local_48 = local_48 + 1;
        local_28 = local_28 + 1;
      } while (local_48 != 4);
    }
    if (4 < local_4c) break;
    piVar3 = (int *)param_1[0xb];
  }
  iVar4 = param_1[0xb];
  local_24 = 0;
  do {
    iVar4 = *(int *)(iVar4 + local_24 * 4);
    local_24 = local_24 + 1;
    if (iVar4 != 0) {
      piVar3 = *(int **)(iVar4 + 0x38);
      cVar2 = FUN_000e1402(*param_1,0x25);
      if (((((cVar2 == '\0') || (piVar3[0x20] == 0)) ||
           ((cVar2 = FUN_0012dfd8(piVar3[0x26]), cVar2 == '\0' ||
            (((*(byte *)(piVar3 + 5) & 2) != 0 ||
             (cVar2 = (**(code **)(*piVar3 + 0x50))(piVar3), cVar2 != '\0')))))) ||
          ((piVar3[5] & 0x40U) != 0)) || ((piVar3[5] & 0x20U) != 0)) {
        if ((((piVar3[0x20] != 0) && (cVar2 = FUN_0012dfd8(piVar3[0x26]), cVar2 != '\0')) &&
            ((*(byte *)(piVar3 + 5) & 2) == 0)) &&
           (cVar2 = (**(code **)(*piVar3 + 0x50))(piVar3), cVar2 == '\0')) {
          uVar6 = piVar3[5];
          if ((uVar6 & 0x20) == 0) {
            cVar2 = FUN_000e1402(*param_1,0x25);
            if (cVar2 != '\0') goto LAB_0017c54d;
            uVar6 = piVar3[5];
          }
          if ((uVar6 & 0x40) == 0) {
            iVar4 = piVar3[0x26];
            iVar8 = *(int *)(*param_1 + 0x108) + 1;
            *(int *)(*param_1 + 0x108) = iVar8;
            piVar3[0x25] = iVar8;
            piVar3[0x26] = iVar4;
          }
        }
      }
      else {
        if ((*(int *)(iVar4 + 0x60) == 0) ||
           (local_40 = *(int *)(*(int *)(iVar4 + 0x60) + 4), local_40 < 0)) {
          cVar2 = (**(code **)(**(int **)(*param_1 + 0x54) + 0x7c))
                            (*(int **)(*param_1 + 0x54),piVar3);
          iVar8 = DAT_001cc6f4;
          if (cVar2 != '\0') {
            if (*(int **)(iVar4 + 0x60) == (int *)0x0) {
              iVar8 = piVar3[3];
            }
            else {
              iVar8 = **(int **)(iVar4 + 0x60);
            }
          }
          local_40 = ((int (*)())FUN_00175c04)(param_1,piVar3[0x26],iVar8);
          if (local_40 < 0) {
            local_40 = param_1[0x51];
            param_1[0x51] = local_40 + 1;
            iVar8 = param_1[0x52];
            if (iVar8 < local_40 + 1) {
              local_2c = param_1;
              do {
                pvVar1 = (void *)local_2c[0x4c];
                pvVar7 = (void *)FUN_001a7bca(*(undefined4 *)(*param_1 + 0xbc),iVar8 << 3);
                local_2c[0x4c] = (int)pvVar7;
                _memcpy(pvVar7,pvVar1,param_1[0x52] << 2);
                FUN_001a7aba(*(undefined4 *)(*param_1 + 0xbc),pvVar1);
                local_2c = local_2c + 1;
              } while (local_2c != param_1 + 4);
              param_1[0x52] = iVar8 * 2;
            }
            iVar8 = 4;
            piVar9 = param_1;
            do {
              *(undefined4 *)(local_40 * 4 + piVar9[0x4c]) = 0;
              piVar9 = piVar9 + 1;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
          local_38 = 0;
          piVar9 = param_1;
          do {
            iVar8 = FUN_0010b0f4(piVar3,0);
            if (*(char *)(local_38 + 0x10 + iVar8) != '\x01') {
              *(int *)(piVar9[0x4c] + local_40 * 4) = iVar4;
            }
            local_38 = local_38 + 1;
            piVar9 = piVar9 + 1;
          } while (local_38 != 4);
          if (*(int *)(iVar4 + 0x60) != 0) {
            *(int *)(*(int *)(iVar4 + 0x60) + 4) = local_40;
          }
        }
        else {
          local_34 = 0;
          piVar9 = param_1;
          do {
            iVar8 = FUN_0010b0f4(piVar3,0);
            if (*(char *)(local_34 + 0x10 + iVar8) != '\x01') {
              *(int *)(piVar9[0x4c] + local_40 * 4) = iVar4;
            }
            local_34 = local_34 + 1;
            piVar9 = piVar9 + 1;
          } while (local_34 != 4);
        }
        piVar3[5] = piVar3[5] | 0x40;
        piVar3[0x25] = local_40;
      }
    }
LAB_0017c54d:
    if (4 < local_24) {
      return;
    }
    iVar4 = param_1[0xb];
  } while( true );
}

/* FUN_0017c962 @ 0x17c962 (803 bytes) */
int FUN_0017c962(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint local_38;
  uint local_34;
  int local_2c;
  int local_28;
  
  ((int (*)())FUN_0017c498)(param_1);
  local_28 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + 0xcc) + 4);
  iVar8 = 0;
  local_2c = 0;
  iVar7 = *(int *)(param_1 + 0x2c);
  do {
    iVar1 = *(int *)(iVar7 + local_2c * 4);
    if (iVar1 != 0) {
      iVar8 = *(int *)(iVar1 + 0x38);
      FUN_000e9512(*(undefined4 *)(param_1 + 0x10),iVar8);
      ((int (*)())FUN_00174aaa)();
      *(uint *)(iVar8 + 0x14) = *(uint *)(iVar8 + 0x14) | 4;
      puVar10 = *(uint **)(iVar1 + 0x44);
      uVar2 = puVar10[1];
      if (0 < (int)uVar2) {
        local_38 = 0;
        while( true ) {
          if (local_38 < *puVar10) {
            uVar4 = puVar10[1];
            if (uVar4 <= local_38) {
              _memset((void *)(puVar10[2] + uVar4 * 4),0,(local_38 - uVar4) * 4 + 4);
              puVar10[1] = local_38 + 1;
            }
            piVar6 = *(int **)(puVar10[2] + local_38 * 4);
            iVar7 = piVar6[2];
          }
          else {
            piVar6 = (int *)FUN_001a7f7c(puVar10,local_38);
            piVar6 = (int *)*piVar6;
            iVar7 = piVar6[2];
          }
          if (((iVar7 == 0) &&
              (cVar5 = (**(code **)(**(int **)(*piVar6 + 0x38) + 0x5c))(*(int **)(*piVar6 + 0x38)),
              cVar5 != '\0')) && (*(int *)(*(int *)(*piVar6 + 0x38) + 0x158) == 0)) {
            FUN_000e9596(*(undefined4 *)(param_1 + 0x10),local_28,*(int *)(*piVar6 + 0x38));
            puVar10 = (uint *)(*(int *)(*piVar6 + 0x38) + 0x14);
            *puVar10 = *puVar10 | 4;
            local_28 = *(int *)(*piVar6 + 0x38);
          }
          if (uVar2 == local_38 + 1) break;
          local_38 = local_38 + 1;
          puVar10 = *(uint **)(iVar1 + 0x44);
        }
      }
      iVar7 = *(int *)(param_1 + 0x2c);
    }
    local_2c = local_2c + 1;
  } while (local_2c != 5);
  iVar1 = *(int *)(iVar7 + 0x1c);
  iVar7 = *(int *)(*(int *)(iVar7 + 0x1c) + 8);
  while (iVar7 != 0) {
    iVar3 = *(int *)(iVar1 + 0x38);
    if ((*(int *)(iVar3 + 0x98) == 0x45) || (*(int *)(iVar3 + 0x98) == 0x44)) {
      FUN_000e9596(*(undefined4 *)(param_1 + 0x10),local_28,iVar3);
      *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 4;
      iVar9 = iVar3;
      if (iVar8 != 0) {
        iVar9 = iVar8;
      }
      iVar1 = iVar7;
      iVar7 = *(int *)(iVar7 + 8);
      iVar8 = iVar9;
      local_28 = iVar3;
    }
    else {
      FUN_000e9512(*(undefined4 *)(param_1 + 0x10),iVar3);
      ((int (*)())FUN_00174aaa)();
      *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 4;
      puVar10 = *(uint **)(iVar1 + 0x44);
      uVar2 = puVar10[1];
      if (0 < (int)uVar2) {
        local_34 = 0;
        while( true ) {
          if (local_34 < *puVar10) {
            uVar4 = puVar10[1];
            if (uVar4 <= local_34) {
              _memset((void *)(puVar10[2] + uVar4 * 4),0,(local_34 - uVar4) * 4 + 4);
              puVar10[1] = local_34 + 1;
            }
            piVar6 = *(int **)(puVar10[2] + local_34 * 4);
            iVar8 = piVar6[2];
          }
          else {
            piVar6 = (int *)FUN_001a7f7c(puVar10,local_34);
            piVar6 = (int *)*piVar6;
            iVar8 = piVar6[2];
          }
          if (((iVar8 == 0) &&
              (cVar5 = (**(code **)(**(int **)(*piVar6 + 0x38) + 0x5c))(*(int **)(*piVar6 + 0x38)),
              cVar5 != '\0')) && (*(int *)(*(int *)(*piVar6 + 0x38) + 0x158) == 0)) {
            FUN_000e9596(*(undefined4 *)(param_1 + 0x10),local_28,*(int *)(*piVar6 + 0x38));
            puVar10 = (uint *)(*(int *)(*piVar6 + 0x38) + 0x14);
            *puVar10 = *puVar10 | 4;
            local_28 = *(int *)(*piVar6 + 0x38);
          }
          if (uVar2 == local_34 + 1) break;
          local_34 = local_34 + 1;
          puVar10 = *(uint **)(iVar1 + 0x44);
        }
      }
      iVar1 = iVar7;
      iVar7 = *(int *)(iVar7 + 8);
      iVar8 = iVar3;
    }
  }
  if (iVar8 != 0) {
    *(uint *)(iVar8 + 0x14) = *(uint *)(iVar8 + 0x14) & 0xfffffffb;
  }
  return iVar8;
}

/* FUN_0017cc86 @ 0x17cc86 (1042 bytes) */
int FUN_0017cc86(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint *puVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  int *piVar10;
  bool bVar11;
  int local_18;
  uint local_14;
  byte local_10;
  
  piVar10 = *(int **)(param_2 + 0x38);
  if (((((*(byte *)(piVar10 + 5) & 0x20) == 0) && (piVar10[0x20] != 0)) &&
      (cVar3 = FUN_0012dfd8(piVar10[0x26]), cVar3 != '\0')) && ((*(byte *)(piVar10 + 5) & 2) == 0))
  {
    (**(code **)(*piVar10 + 0x50))(piVar10);
  }
  pcVar2 = *(char **)(param_2 + 0x60);
  if (pcVar2 == (char *)0x0) {
    iVar9 = *(int *)(param_2 + 0x38);
    iVar5 = iVar9;
    iVar6 = param_2;
    do {
      if ((*(char *)(iVar5 + 0xc) != '\0') && (0 < *(int *)(iVar6 + 0x48))) {
        return;
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 4;
    } while (iVar5 != iVar9 + 4);
    uVar7 = *(uint *)(iVar9 + 0x94);
    if (((*(byte *)(iVar9 + 0x14) & 0x40) != 0) && ((int)uVar7 < param_1[0x50])) {
      if (*(int *)(param_2 + 0x2c) == 0) {
        iVar5 = param_1[0x4b];
      }
      else {
        local_10 = (byte)uVar7 & 0x1f;
        iVar5 = param_1[0x4b];
        if ((*(uint *)(iVar5 + 8 + (uVar7 >> 5) * 4) >> local_10 & 1) != 0) goto LAB_0017cfc2;
      }
      local_10 = (byte)uVar7 & 0x1f;
      local_14 = uVar7 >> 5;
      if ((*(uint *)(iVar5 + 8 + local_14 * 4) >> local_10 & 1) == 0) {
        return;
      }
      local_18 = 0;
      cVar3 = *(char *)(iVar9 + 0xc);
      piVar10 = param_1;
      while( true ) {
        if (cVar3 != '\0') {
          *(int *)(piVar10[0x53] + uVar7 * 4) = param_1[10];
        }
        local_18 = local_18 + 1;
        piVar10 = piVar10 + 1;
        if (local_18 == 4) break;
        cVar3 = *(char *)(*(int *)(param_2 + 0x38) + 0xc + local_18);
      }
      return;
    }
LAB_0017cfc2:
    iVar9 = *(int *)(param_2 + 0x2c);
    iVar5 = (**(code **)(*(int *)param_1[3] + 0x18))((int *)param_1[3]);
    if ((iVar5 <= iVar9) &&
       (iVar5 = FUN_00173f26(param_1,*(undefined4 *)(*(int *)(param_2 + 0x38) + 0xc),iVar9,1),
       -1 < iVar5)) {
      *(int *)(*(int *)(param_2 + 0x38) + 0x94) = iVar5 + param_1[0x50];
      return;
    }
    iVar9 = FUN_00173f26(param_1,*(undefined4 *)(*(int *)(param_2 + 0x38) + 0xc),iVar9,0);
    bVar11 = iVar9 < 0;
    if (bVar11) {
      iVar9 = *(int *)(*param_1 + 0x108) + 1;
      *(int *)(*param_1 + 0x108) = iVar9;
    }
    *(int *)(*(int *)(param_2 + 0x38) + 0x94) = iVar9;
    if (bVar11) {
      puVar1 = (uint *)(*(int *)(param_2 + 0x38) + 0x14);
      *puVar1 = *puVar1 & 0xffffffbf;
      return;
    }
    puVar1 = (uint *)(*(int *)(param_2 + 0x38) + 0x14);
    *puVar1 = *puVar1 | 0x40;
    return;
  }
  iVar9 = 0;
  pcVar4 = pcVar2;
  pcVar8 = pcVar2;
  do {
    if (((*pcVar4 != '\0') && (*(int *)(pcVar8 + 0x18) != 0)) &&
       (0 < *(int *)(*(int *)(pcVar8 + 0x18) + 0x48 + iVar9 * 4))) {
      return;
    }
    iVar9 = iVar9 + 1;
    pcVar4 = pcVar4 + 1;
    pcVar8 = pcVar8 + 4;
  } while (iVar9 != 4);
  uVar7 = *(uint *)(pcVar2 + 4);
  if (((int)uVar7 < 0) || (param_1[0x50] <= (int)uVar7)) {
LAB_0017ccfc:
    iVar9 = *(int *)(pcVar2 + 0x14);
    iVar5 = (**(code **)(*(int *)param_1[3] + 0x18))((int *)param_1[3]);
    if ((iVar9 < iVar5) || (iVar5 = FUN_00173f26(param_1,*(undefined4 *)pcVar2,iVar9,1), iVar5 < 0))
    {
      iVar9 = FUN_00173f26(param_1,*(undefined4 *)pcVar2,iVar9,0);
      bVar11 = iVar9 < 0;
      if (bVar11) {
        iVar9 = *(int *)(*param_1 + 0x108) + 1;
        *(int *)(*param_1 + 0x108) = iVar9;
      }
      bVar11 = !bVar11;
      iVar5 = *(int *)(*(int *)(pcVar2 + 8) + 0x38);
      if (iVar5 != 0) {
        *(int *)(iVar5 + 0x94) = iVar9;
        if (!bVar11) goto LAB_0017ce68;
        do {
          uVar7 = *(uint *)(iVar5 + 0x14) | 0x40;
          *(uint *)(iVar5 + 0x14) = uVar7;
          while( true ) {
            if ((uVar7 & 0x200) == 0) {
              return;
            }
            iVar5 = FUN_0010b180(iVar5,*(undefined4 *)(iVar5 + 0x84));
            if (iVar5 == 0) {
              return;
            }
            *(int *)(iVar5 + 0x94) = iVar9;
            if (bVar11) break;
LAB_0017ce68:
            uVar7 = *(uint *)(iVar5 + 0x14) & 0xffffffbf;
            *(uint *)(iVar5 + 0x14) = uVar7;
          }
        } while( true );
      }
    }
    else {
      iVar9 = param_1[0x50];
      for (iVar6 = *(int *)(*(int *)(pcVar2 + 8) + 0x38);
          (iVar6 != 0 &&
          (*(int *)(iVar6 + 0x94) = iVar5 + iVar9, (*(byte *)(iVar6 + 0x15) & 2) != 0));
          iVar6 = FUN_0010b180(iVar6,*(undefined4 *)(iVar6 + 0x84))) {
      }
    }
  }
  else {
    if (*(int *)(pcVar2 + 0x14) == 0) {
      iVar9 = param_1[0x4b];
    }
    else {
      iVar9 = param_1[0x4b];
      if ((*(uint *)(iVar9 + 8 + (uVar7 >> 5) * 4) >> ((byte)uVar7 & 0x1f) & 1) != 0)
      goto LAB_0017ccfc;
    }
    if ((*(uint *)(iVar9 + 8 + (uVar7 >> 5) * 4) >> ((byte)uVar7 & 0x1f) & 1) != 0) {
      pcVar4 = pcVar2;
      piVar10 = param_1;
      do {
        if (*pcVar4 != '\0') {
          *(int *)(piVar10[0x53] + *(int *)(pcVar2 + 4) * 4) = param_1[10];
        }
        pcVar4 = pcVar4 + 1;
        piVar10 = piVar10 + 1;
      } while (pcVar4 != pcVar2 + 4);
      return;
    }
  }
  return;
}

/* FUN_0017d098 @ 0x17d098 (1593 bytes) */
int FUN_0017d098(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  char cVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char *pcVar10;
  uint *puVar11;
  int iVar12;
  undefined4 *puVar13;
  int iVar14;
  uint local_48;
  char cStack_21;
  undefined4 local_20;
  
  puVar11 = *(uint **)(param_2 + 0x44);
  uVar1 = puVar11[1];
  piVar2 = *(int **)(param_2 + 0x38);
  if (0 < (int)uVar1) {
    local_48 = 0;
    while( true ) {
      if (local_48 < *puVar11) {
        uVar3 = puVar11[1];
        if (uVar3 <= local_48) {
          _memset((void *)(puVar11[2] + uVar3 * 4),0,(local_48 - uVar3) * 4 + 4);
          puVar11[1] = local_48 + 1;
        }
        piVar6 = *(int **)(puVar11[2] + local_48 * 4);
        iVar14 = piVar6[2];
      }
      else {
        piVar6 = (int *)FUN_001a7f7c(puVar11,local_48);
        piVar6 = (int *)*piVar6;
        iVar14 = piVar6[2];
      }
      if (iVar14 == 0) {
        iVar14 = *piVar6;
        cVar5 = (**(code **)(*piVar2 + 0x60))(piVar2);
        if ((cVar5 != '\0') &&
           (cVar5 = (**(code **)(**(int **)(iVar14 + 0x38) + 0x5c))(*(int **)(iVar14 + 0x38)),
           cVar5 != '\0')) {
          FUN_001a7d72(iVar14);
        }
        iVar12 = iVar14;
        do {
          if ((((((char)piVar6[6] != '\0') &&
                (iVar7 = *(int *)(iVar12 + 0x48) + -1, *(int *)(iVar12 + 0x48) = iVar7, iVar7 == 0))
               && (piVar4 = *(int **)(iVar14 + 0x38), (*(byte *)(piVar4 + 5) & 0x20) == 0)) &&
              ((piVar4[0x20] != 0 && (cVar5 = FUN_0012dfd8(piVar4[0x26]), cVar5 != '\0')))) &&
             (((*(byte *)(piVar4 + 5) & 2) == 0 &&
              ((cVar5 = (**(code **)(*piVar4 + 0x50))(piVar4), cVar5 == '\0' &&
               (cVar5 = FUN_000e1402(*param_1,0x25), cVar5 != '\0')))))) {
            if (param_1[0x57] == 0) {
              if ((int)param_1[0x50] <= *(int *)(*(int *)(iVar14 + 0x38) + 0x94)) {
                ((int (*)())FUN_00174810)(param_1,iVar14);
              }
            }
            else {
              ((int (*)())FUN_0017cc86)(param_1,iVar14);
            }
          }
          piVar6 = (int *)((int)piVar6 + 1);
          iVar12 = iVar12 + 4;
        } while (iVar14 + 0x10 != iVar12);
      }
      if (uVar1 == local_48 + 1) break;
      local_48 = local_48 + 1;
      puVar11 = *(uint **)(param_2 + 0x44);
    }
  }
  cVar5 = FUN_000e1402(*param_1,0x26);
  if ((cVar5 == '\0') || (cVar5 = FUN_000e1402(*param_1,0x25), cVar5 == '\0')) {
    if (((*(byte *)((int)piVar2 + 0x15) & 2) != 0) &&
       (iVar14 = FUN_0010b180(piVar2,piVar2[0x21]), (*(byte *)(iVar14 + 0x14) & 1) == 0)) {
      FUN_0010ba02(piVar2,piVar2[0x21],0,0,*param_1);
      piVar2[0x21] = piVar2[0x21] + -1;
      piVar2[5] = piVar2[5] & 0xfffffdff;
      if ((*(byte *)(iVar14 + 0x15) & 2) != 0) {
        uVar8 = *param_1;
        uVar9 = FUN_0010b180(iVar14,*(undefined4 *)(iVar14 + 0x84));
        FUN_0010c18e(piVar2,uVar9,0,uVar8);
      }
    }
  }
  else {
    for (iVar14 = 1; iVar12 = (**(code **)(*piVar2 + 0x14))(piVar2), iVar14 <= iVar12;
        iVar14 = iVar14 + 1) {
      uVar8 = FUN_0010b180(piVar2,iVar14);
      while (iVar12 = FUN_0010b180(uVar8,0), iVar12 != 0) {
        uVar8 = FUN_0010b180(uVar8,0);
      }
      FUN_0010ba02(piVar2,iVar14,uVar8,0,*param_1);
    }
  }
  cVar5 = FUN_000e1402(*param_1,0x25);
  if ((cVar5 != '\0') && (iVar14 = *(int *)(param_2 + 0x60), iVar14 != 0)) {
    iVar12 = *(int *)(iVar14 + 4);
    if (-1 < iVar12) {
      piVar2[0x25] = iVar12;
      piVar2[5] = piVar2[5] | 0x40;
      iVar14 = 0;
      puVar13 = param_1;
      do {
        iVar7 = FUN_0010b0f4(piVar2,0);
        if (*(char *)(iVar14 + 0x10 + iVar7) != '\x01') {
          *(int *)(puVar13[0x4c] + iVar12 * 4) = param_2;
          if ((puVar13[0x53] != 0) && (*(int *)(*(int *)(param_2 + 0x60) + 0x14) == 0)) {
            *(undefined4 *)(puVar13[0x53] + iVar12 * 4) = 0x7fffffff;
          }
        }
        iVar14 = iVar14 + 1;
        puVar13 = puVar13 + 1;
      } while (iVar14 != 4);
      iVar14 = *(int *)(param_2 + 0x60);
    }
    if (*(int *)(param_2 + 0x2c) < *(int *)(iVar14 + 0x14)) {
      *(int *)(iVar14 + 0x14) = *(int *)(param_2 + 0x2c);
    }
    iVar14 = 0;
    do {
      iVar12 = FUN_0010b0f4(piVar2,0);
      if (*(char *)(iVar14 + 0x10 + iVar12) != '\x01') {
        *(int *)(*(int *)(param_2 + 0x60) + 0x18 + iVar14 * 4) = param_2;
      }
      iVar14 = iVar14 + 1;
    } while (iVar14 != 4);
  }
  piVar6 = *(int **)(param_2 + 0x38);
  if (((((*(byte *)(piVar6 + 5) & 0x20) == 0) && (piVar6[0x20] != 0)) &&
      (cVar5 = FUN_0012dfd8(piVar6[0x26]), cVar5 != '\0')) &&
     (((*(byte *)(piVar6 + 5) & 2) == 0 &&
      (cVar5 = (**(code **)(*piVar6 + 0x50))(piVar6), cVar5 == '\0')))) {
    if ((*(int *)(param_2 + 0x60) == 0) ||
       (iVar14 = *(int *)(*(int *)(param_2 + 0x60) + 8), iVar14 == 0)) {
      iVar14 = 0;
    }
    else {
      iVar14 = *(int *)(iVar14 + 0x38);
    }
    cVar5 = FUN_000e1402(*param_1,0x26);
    if ((cVar5 != '\0') && (cVar5 = FUN_000e1402(*param_1,0x25), cVar5 != '\0')) {
      if (iVar14 == 0) {
        if ((*(byte *)(*(int *)(param_2 + 0x38) + 0x15) & 2) != 0) {
          FUN_0010ba02(piVar2,piVar2[0x21],0,0,*param_1);
          piVar2[0x21] = piVar2[0x21] + -1;
          piVar2[5] = piVar2[5] & 0xfffffdff;
        }
      }
      else {
        FUN_0010ba02(iVar14,0,*(undefined4 *)(param_2 + 0x38),0,*param_1);
        FUN_0010c18e(piVar2,iVar14,0,*param_1);
      }
    }
    if ((*(int *)(param_2 + 0x60) != 0) &&
       (iVar14 = FUN_0010b0f4(piVar2,0), *(int *)(iVar14 + 0x10) != DAT_001cc6f8)) {
      iVar14 = *(int *)(param_2 + 0x60);
      iVar12 = *(int *)(iVar14 + 8);
      if ((iVar12 == 0) || (*(int *)(iVar12 + 0x2c) != param_1[10])) {
        iVar12 = FUN_0010b0f4(*(undefined4 *)(param_2 + 0x38),0);
        *(undefined4 *)(iVar14 + 0xc) = *(undefined4 *)(iVar12 + 0x10);
      }
      else {
        iVar14 = FUN_0010b0f4(*(undefined4 *)(param_2 + 0x38),0);
        local_20 = *(undefined4 *)(iVar14 + 0x10);
        pcVar10 = (char *)(*(int *)(param_2 + 0x60) + 0xc);
        iVar14 = 1;
        do {
          if ((&cStack_21)[iVar14] != '\x01') {
            *pcVar10 = (&cStack_21)[iVar14];
          }
          iVar14 = iVar14 + 1;
          pcVar10 = pcVar10 + 1;
        } while (iVar14 != 5);
      }
      *(int *)(*(int *)(param_2 + 0x60) + 8) = param_2;
    }
  }
  return;
}

/* FUN_0017d6d2 @ 0x17d6d2 (269 bytes) */
int FUN_0017d6d2(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  char cVar2;
  
  cVar2 = (**(code **)(**(int **)(param_2 + 0x38) + 0x5c))(*(int **)(param_2 + 0x38));
  if (cVar2 == '\0') {
    (**(code **)(*(int *)param_1[2] + 0x74))((int *)param_1[2],param_2,param_1[0xb]);
  }
  else {
    FUN_001a7cd6(param_1 + 0x24,param_2);
  }
  iVar1 = param_1[10];
  *(int *)(param_2 + 0x30) = iVar1;
  *(int *)(param_2 + 0x2c) = iVar1;
  (**(code **)(*(int *)param_1[2] + 0x10))((int *)param_1[2],*(undefined4 *)(param_2 + 0x38));
  ((int (*)())FUN_001826a6)(param_1[2],param_2);
  (**(code **)(*(int *)param_1[3] + 0x10))((int *)param_1[3],param_2);
  ((int (*)())FUN_0017d098)(param_1,param_2);
  cVar2 = (**(code **)(**(int **)(*param_1 + 0x54) + 0xd4))(*(int **)(*param_1 + 0x54));
  if ((cVar2 != '\0') && ((*(byte *)(*(int *)(param_2 + 0x38) + 0x15) & 0x10) != 0)) {
    ((int (*)())FUN_0017e5b2)(param_1);
  }
  ((int (*)())FUN_00181156)(param_1,param_2);
  cVar2 = (**(code **)(*(int *)param_1[3] + 0x20))
                    ((int *)param_1[3],*(undefined4 *)(param_2 + 0x38));
  if (((cVar2 != '\0') ||
      (cVar2 = (**(code **)(*(int *)param_1[3] + 0x24))
                         ((int *)param_1[3],*(undefined4 *)(param_2 + 0x38)), cVar2 != '\0')) &&
     (param_1[0x49] <= *(int *)(param_2 + 0xc))) {
    param_1[0x4a] = param_1[0x4a] + 1;
  }
  return;
}

/* FUN_0017d7e0 @ 0x17d7e0 (2287 bytes) */
int FUN_0017d7e0(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_68;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  undefined4 local_20 [4];
  
  FUN_0010a320(*(undefined4 *)(param_2 + 0x38));
  if (param_1[0x60] < 0) {
    if (*(int *)(*(int *)(param_2 + 0x38) + 0x98) == 0x3a) {
      param_1[0x60] = 1;
    }
    else {
      param_1[0x60] = *(int *)(*(int *)(*param_1 + 0x54) + 0x1c);
    }
  }
  iVar7 = *(int *)(param_2 + 0x38);
  iVar3 = FUN_0010b0f4(iVar7,1);
  FUN_000f5672(*(undefined4 *)(iVar3 + 0x10));
  iVar3 = 0;
  do {
    iVar4 = FUN_0010b0f4(iVar7,0);
    if (*(char *)(iVar3 + 0x10 + iVar4) != '\x01') {
      iVar4 = FUN_0010b0f4(iVar7,1);
      local_60 = (uint)*(byte *)(iVar3 + 0x10 + iVar4);
      goto LAB_0017d863;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 4);
  local_60 = 4;
LAB_0017d863:
  if (0 < param_1[0x60]) {
    local_30 = param_1;
    local_5c = 0;
    do {
      if (local_30[0x5b] != 0) {
        iVar3 = FUN_0010b180(*(undefined4 *)(local_30[0x5b] + 0x38),1);
        iVar4 = FUN_0010b180(iVar7,1);
        if (iVar3 == iVar4) {
          iVar3 = local_30[0x5b];
          iVar4 = *(int *)(iVar3 + 0x38);
          local_68 = local_5c & 0x80000003;
          if ((int)local_68 < 0) {
            local_68 = (local_68 - 1 | 0xfffffffc) + 1;
          }
          iVar9 = FUN_0010b0f4(iVar4,1);
          if ((local_60 == *(byte *)(local_68 + 0x10 + iVar9)) &&
             (cVar2 = (**(code **)(**(int **)(iVar4 + 0x88) + 0x18))(*(int **)(iVar4 + 0x88)),
             *(char *)(iVar7 + 300) == cVar2)) {
            FUN_0010ba02(iVar7,1,iVar4,0,*param_1);
            uVar6 = *(undefined4 *)(PTR_DAT_00213485 + local_68 * 4);
            iVar7 = FUN_0010b0f4(iVar7,1);
            *(undefined4 *)(iVar7 + 0x10) = uVar6;
            if (*(int *)(iVar3 + 0x68) != 0) {
              *(int *)(param_2 + 0x68) = *(int *)(iVar3 + 0x68);
            }
            *(int *)(iVar3 + 0x68) = param_2;
            puVar12 = *(uint **)(param_2 + 0x40);
            uVar11 = puVar12[1];
            if ((int)uVar11 < 1) {
              return 1;
            }
            local_78 = 0;
            while( true ) {
              if (local_78 < *puVar12) {
                uVar10 = puVar12[1];
                if (uVar10 <= local_78) {
                  _memset((void *)(puVar12[2] + uVar10 * 4),0,(local_78 - uVar10) * 4 + 4);
                  puVar12[1] = local_78 + 1;
                }
                piVar8 = (int *)(puVar12[2] + local_78 * 4);
              }
              else {
                piVar8 = (int *)FUN_001a7f7c(puVar12,local_78);
              }
              local_78 = local_78 + 1;
              iVar7 = *piVar8;
              iVar4 = *(int *)(iVar7 + 4);
              if (*(int *)(iVar7 + 8) == 0) {
                local_20[0] = 0;
                *(undefined1 *)((int)local_20 + local_68) = 1;
                ((int (*)())FUN_00174cc0)(param_1,iVar3,iVar4,*(undefined4 *)(iVar7 + 0x10),
                             *(undefined4 *)(iVar7 + 0x14),local_20[0]);
                piVar8 = (int *)(iVar4 + 0x34);
                *piVar8 = *piVar8 + -1;
              }
              if (uVar11 == local_78) break;
              puVar12 = *(uint **)(param_2 + 0x40);
            }
            return 1;
          }
        }
      }
      local_5c = local_5c + 1;
      uVar11 = param_1[0x60];
      local_30 = local_30 + 1;
    } while ((int)local_5c < (int)uVar11);
    if (0 < (int)uVar11) {
      iVar3 = param_1[0x5b];
      if (iVar3 == 0) {
        local_58 = 0;
        local_3c = 0;
      }
      else {
        local_34 = param_1;
        uVar10 = 0;
        local_58 = 0xffffffff;
        do {
          uVar5 = uVar10 & 0x80000003;
          if ((int)uVar5 < 0) {
            uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
          }
          if ((*(int *)(iVar3 + 0x48 + uVar5 * 4) == 0) &&
             (((int)local_58 < 0 ||
              (*(int *)(iVar3 + 0x2c) < *(int *)(param_1[local_58 + 0x5b] + 0x2c))))) {
            local_58 = uVar10;
          }
          uVar10 = uVar10 + 1;
          uVar5 = local_58;
          if (uVar10 == uVar11) break;
          iVar3 = local_34[0x5c];
          local_34 = local_34 + 1;
          uVar5 = uVar10;
        } while (iVar3 != 0);
        local_58 = uVar5;
        if ((int)local_58 < 0) {
          return 0;
        }
        local_3c = local_58 & 0x80000003;
        if ((int)local_3c < 0) {
          local_3c = (local_3c - 1 | 0xfffffffc) + 1;
        }
      }
      uVar10 = local_58 - local_3c;
      uVar11 = uVar10 + 4;
      local_38 = param_1 + uVar10 + 0x5b;
      do {
        if ((((*(byte *)(*(int *)(*param_1 + 0x54) + 9) & 2) == 0) && (*local_38 != 0)) &&
           (uVar10 != local_58)) {
          iVar3 = FUN_0010b180(*(undefined4 *)(*local_38 + 0x38),1);
          iVar4 = FUN_0010b180(iVar7,1);
          if (iVar3 == iVar4) {
            iVar3 = *local_38;
            piVar8 = *(int **)(iVar3 + 0x38);
            if (*(char *)(iVar7 + 300) == '\0') {
              if (*(int *)(piVar8[0x22] + 8) == 0xa6) goto LAB_0017de98;
            }
            else if (*(int *)(piVar8[0x22] + 8) == 0x2b) {
LAB_0017de98:
              if ((param_1[local_58 + 0x5b] == 0) ||
                 (iVar4 = ((int (*)())FUN_00175b50)(param_1[local_58 + 0x5b],local_3c),
                 iVar4 < *(int *)(iVar3 + 0x2c))) {
                *(undefined1 *)(local_3c + 0x9c + (int)piVar8) = 0;
                (**(code **)(*piVar8 + 0x88))(piVar8,1,local_3c,local_60);
                *(undefined1 *)((int)piVar8 + local_3c + 0xc) = 1;
                param_1[local_58 + 0x5b] = iVar3;
                FUN_0010ba02(iVar7,1,piVar8,0,*param_1);
                uVar6 = *(undefined4 *)(PTR_DAT_00213485 + local_3c * 4);
                iVar7 = FUN_0010b0f4(iVar7,1);
                *(undefined4 *)(iVar7 + 0x10) = uVar6;
                if (*(int *)(iVar3 + 0x68) != 0) {
                  *(int *)(param_2 + 0x68) = *(int *)(iVar3 + 0x68);
                }
                *(int *)(iVar3 + 0x68) = param_2;
                puVar12 = *(uint **)(param_2 + 0x40);
                uVar11 = puVar12[1];
                if ((int)uVar11 < 1) {
                  return 1;
                }
                local_74 = 0;
                while( true ) {
                  if (local_74 < *puVar12) {
                    uVar10 = puVar12[1];
                    if (uVar10 <= local_74) {
                      _memset((void *)(puVar12[2] + uVar10 * 4),0,(local_74 - uVar10) * 4 + 4);
                      puVar12[1] = local_74 + 1;
                    }
                    piVar8 = (int *)(puVar12[2] + local_74 * 4);
                  }
                  else {
                    piVar8 = (int *)FUN_001a7f7c(puVar12,local_74);
                  }
                  local_74 = local_74 + 1;
                  iVar7 = *piVar8;
                  iVar4 = *(int *)(iVar7 + 4);
                  if (*(int *)(iVar7 + 8) == 0) {
                    local_20[0] = 0;
                    *(undefined1 *)((int)local_20 + local_3c) = 1;
                    ((int (*)())FUN_00174cc0)(param_1,iVar3,iVar4,*(undefined4 *)(iVar7 + 0x10),
                                 *(undefined4 *)(iVar7 + 0x14),local_20[0]);
                    piVar8 = (int *)(iVar4 + 0x34);
                    *piVar8 = *piVar8 + -1;
                  }
                  if (uVar11 == local_74) break;
                  puVar12 = *(uint **)(param_2 + 0x40);
                }
                return 1;
              }
            }
          }
        }
        uVar10 = uVar10 + 1;
        local_38 = local_38 + 1;
      } while (uVar11 != uVar10);
      iVar3 = (**(code **)(*(int *)param_1[2] + 0x80))
                        ((int *)param_1[2],param_1[0x5f],*(undefined1 *)(iVar7 + 300),
                         *(undefined1 *)(iVar7 + 0x130),*(int *)(iVar7 + 0x98) == 0x3a);
      param_1[0x5f] = iVar3;
      uVar11 = local_58;
      if ((int)local_58 < 0) {
        uVar11 = local_58 + 3;
      }
      *(int *)(iVar3 + 0x94) = (int)uVar11 >> 2;
      *(undefined4 *)(iVar3 + 0x98) = 0x20;
      *(undefined4 *)(param_1[0x5f] + 0x9c) = *(undefined4 *)(PTR_DAT_0021345d + local_3c * 4);
      iVar3 = *param_1;
      uVar6 = FUN_0010b180(iVar7,1);
      FUN_0010ba02(param_1[0x5f],1,uVar6,0,iVar3);
      puVar1 = PTR_DAT_00213485;
      uVar6 = *(undefined4 *)(PTR_DAT_00213485 + local_60 * 4);
      iVar3 = FUN_0010b0f4(param_1[0x5f],1);
      *(undefined4 *)(iVar3 + 0x10) = uVar6;
      *(undefined4 *)(param_1[0x5f] + 0xc) = 0;
      *(undefined1 *)(param_1[0x5f] + 0xc + local_3c) = 1;
      cVar2 = (**(code **)(*(int *)param_1[2] + 0xc))((int *)param_1[2],param_1[0x5f]);
      if (cVar2 != '\0') {
        iVar3 = ((int (*)())FUN_00174e94)(param_1,param_1[0x5f],param_2 + 0xc,param_1[10]);
        param_1[0x5f] = 0;
        param_1[local_58 + 0x5b] = iVar3;
        FUN_0010ba02(iVar7,1,*(undefined4 *)(iVar3 + 0x38),0,*param_1);
        uVar6 = *(undefined4 *)(puVar1 + local_3c * 4);
        iVar7 = FUN_0010b0f4(iVar7,1);
        *(undefined4 *)(iVar7 + 0x10) = uVar6;
        *(int *)(iVar3 + 0x68) = param_2;
        puVar12 = *(uint **)(param_2 + 0x40);
        uVar11 = puVar12[1];
        if (0 < (int)uVar11) {
          local_70 = 0;
          while( true ) {
            if (local_70 < *puVar12) {
              uVar10 = puVar12[1];
              if (uVar10 <= local_70) {
                _memset((void *)(puVar12[2] + uVar10 * 4),0,(local_70 - uVar10) * 4 + 4);
                puVar12[1] = local_70 + 1;
              }
              iVar7 = *(int *)(puVar12[2] + local_70 * 4);
              uVar6 = *(undefined4 *)(iVar7 + 4);
              iVar4 = *(int *)(iVar7 + 8);
            }
            else {
              piVar8 = (int *)FUN_001a7f7c(puVar12,local_70);
              iVar7 = *piVar8;
              uVar6 = *(undefined4 *)(iVar7 + 4);
              iVar4 = *(int *)(iVar7 + 8);
            }
            if (iVar4 == 0) {
              local_20[0] = 0;
              *(undefined1 *)((int)local_20 + local_3c) = 1;
              ((int (*)())FUN_00174cc0)(param_1,iVar3,uVar6,*(undefined4 *)(iVar7 + 0x10),
                           *(undefined4 *)(iVar7 + 0x14),local_20[0]);
            }
            if (uVar11 == local_70 + 1) break;
            local_70 = local_70 + 1;
            puVar12 = *(uint **)(param_2 + 0x40);
          }
        }
        ((int (*)())FUN_0017d6d2)(param_1,iVar3);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0017e0d0 @ 0x17e0d0 (769 bytes) */
int FUN_0017e0d0(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  int local_34;
  int local_24;
  int *local_20;
  
  uVar1 = *(undefined4 *)(param_2 + 0x38);
  FUN_0010a35a(uVar1);
  local_20 = param_1;
  local_34 = 0;
  do {
    if (local_20[0x61] != 0) {
      iVar11 = *(int *)(local_20[0x61] + 0x38);
      iVar2 = *(int *)(iVar11 + 0x130);
      iVar3 = *(int *)(iVar11 + 0x134);
      iVar4 = *(int *)(iVar11 + 300);
      iVar6 = FUN_0010b6e4(uVar1,0);
      iVar7 = FUN_0010b180(uVar1,1);
      if (iVar2 == *(int *)(iVar7 + 0x94)) {
        if ((iVar3 <= iVar6) && (iVar6 < iVar3 + iVar4)) goto LAB_0017e1e0;
        if (iVar4 == 0x10) {
          if ((iVar3 <= iVar6) && (iVar6 < iVar3 + 0x20)) {
            *(undefined4 *)(iVar11 + 300) = 0x20;
LAB_0017e1e0:
            FUN_0010ba02(uVar1,1,iVar11,0,*param_1);
            *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(param_1[local_34 + 0x61] + 0x68);
            *(int *)(param_1[local_34 + 0x61] + 0x68) = param_2;
            return 1;
          }
          if ((iVar3 + -0x10 <= iVar6) && (iVar6 < iVar3 + 0x10)) {
            *(undefined4 *)(iVar11 + 300) = 0x20;
            *(int *)(iVar11 + 0x134) = iVar3 + -0x10;
            goto LAB_0017e1e0;
          }
        }
      }
    }
    local_34 = local_34 + 1;
    local_20 = local_20 + 1;
    if (local_34 == 2) {
      local_24 = 0;
      piVar8 = param_1;
      do {
        if (piVar8[0x61] == 0) {
          if (local_24 < 0) {
            return 0;
          }
          uVar12 = *(undefined4 *)(*param_1 + 0xb8);
          puVar9 = (undefined4 *)FUN_001a7bca(uVar12,0x168);
          *puVar9 = uVar12;
          piVar8 = puVar9 + 1;
          FUN_0010ef86(piVar8,0xfa,*param_1);
          uVar10 = FUN_0010b6e4(uVar1,0);
          puVar9[0x26] = local_24;
          puVar9[0x27] = 0x45;
          iVar11 = FUN_0010b180(uVar1,1);
          puVar9[0x4d] = *(undefined4 *)(iVar11 + 0x94);
          if ((int)uVar10 < 0) {
            uVar10 = uVar10 + 0xf;
          }
          puVar9[0x4e] = uVar10 & 0xfffffff0;
          puVar9[0x4c] = 0x10;
          puVar9[4] = DAT_001cc6f4;
          pcVar5 = *(code **)(*piVar8 + 0x94);
          iVar11 = *param_1;
          uVar12 = FUN_0010b180(uVar1,1);
          (*pcVar5)(piVar8,uVar12,iVar11);
          iVar11 = ((int (*)())FUN_00174e94)(param_1,piVar8,param_2 + 0xc,param_1[10]);
          param_1[local_24 + 0x61] = iVar11;
          FUN_0010ba02(uVar1,1,piVar8,0,*param_1);
          *(int *)(iVar11 + 0x68) = param_2;
          ((int (*)())FUN_0017d6d2)(param_1,iVar11);
          return 1;
        }
        local_24 = local_24 + 1;
        piVar8 = piVar8 + 1;
      } while (local_24 != 2);
      return 0;
    }
  } while( true );
}

/* FUN_0017e3f2 @ 0x17e3f2 (448 bytes) */
int FUN_0017e3f2(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  ((int (*)())FUN_00175a4c)(param_1,param_2);
  if (*(char *)(param_2 + 0x65) == '\0') {
    cVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))
                      (*(int **)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38));
    if ((cVar2 != '\0') ||
       (cVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))
                          (*(int **)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38)), cVar2 != '\0')
       ) {
      iVar4 = *(int *)(param_1 + 0x38);
      iVar3 = *(int *)(iVar4 + 8);
      while( true ) {
        if (iVar3 == 0) {
          FUN_001a7cd6();
          return;
        }
        iVar3 = FUN_00173c8c(param_1,param_2,iVar4,0);
        if (0 < iVar3) break;
        iVar4 = *(int *)(iVar4 + 8);
        iVar3 = *(int *)(iVar4 + 8);
      }
LAB_0017e567:
      FUN_001a7cb8();
      return;
    }
    if (((*(int *)(param_2 + 0x58) == 0) &&
        (cVar2 = FUN_0010a320(*(undefined4 *)(param_2 + 0x38)), cVar2 == '\0')) &&
       (cVar2 = FUN_0010a35a(*(undefined4 *)(param_2 + 0x38)), cVar2 == '\0')) {
      ((int (*)())FUN_0017d6d2)();
      return;
    }
    piVar1 = *(int **)(param_2 + 0x38);
    if ((((*(byte *)(piVar1 + 5) & 0x20) == 0) && (piVar1[0x20] != 0)) &&
       ((cVar2 = FUN_0012dfd8(piVar1[0x26]), cVar2 != '\0' &&
        (((*(byte *)(piVar1 + 5) & 2) == 0 &&
         (cVar2 = (**(code **)(*piVar1 + 0x50))(piVar1), cVar2 == '\0')))))) {
      iVar3 = 4;
      iVar4 = param_2;
      while (*(int *)(iVar4 + 0x48) < 1) {
        iVar4 = iVar4 + 4;
        iVar3 = iVar3 + -1;
        if (iVar3 == 0) {
          ((int (*)())FUN_0018135c)();
          return;
        }
      }
    }
    iVar4 = *(int *)(param_1 + 0x50);
    iVar3 = *(int *)(iVar4 + 8);
    while (iVar3 != 0) {
      iVar3 = FUN_00173c8c(param_1,param_2,iVar4,0);
      if (0 < iVar3) goto LAB_0017e567;
      iVar4 = *(int *)(iVar4 + 8);
      iVar3 = *(int *)(iVar4 + 8);
    }
  }
  FUN_001a7cd6();
  return;
}

/* FUN_0017e5b2 @ 0x17e5b2 (1938 bytes) */
int FUN_0017e5b2(param_1)
  undefined4 *param_1;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  uint *puVar14;
  int iVar15;
  int iVar16;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_70;
  uint local_64;
  uint local_54;
  int local_4c;
  undefined4 *local_34;
  int local_30;
  undefined4 *local_28;
  
  if (0 < (int)param_1[0x60]) {
    local_28 = param_1;
    local_70 = 0;
    do {
      iVar1 = local_28[0x5b];
      local_7c = local_70 & 0x80000003;
      if ((int)local_7c < 0) {
        local_7c = (local_7c - 1 | 0xfffffffc) + 1;
      }
      if (((iVar1 != 0) && (*(int *)(iVar1 + 0x2c) < (int)param_1[10])) &&
         (local_28[0x5b] = 0, 0 < *(int *)(iVar1 + 0x48 + local_7c * 4))) {
        iVar6 = *(int *)(iVar1 + 0x68);
        while (iVar6 != 0) {
          iVar5 = FUN_0010b0f4(*(undefined4 *)(iVar6 + 0x38),1);
          if (*(int *)(iVar5 + 0x10) == *(int *)(PTR_DAT_00213485 + local_7c * 4)) {
            iVar11 = 4;
            iVar5 = *(int *)(iVar6 + 0x48);
            iVar15 = iVar6;
            while (iVar5 < 1) {
              iVar11 = iVar11 + -1;
              if (iVar11 == 0) goto LAB_0017e658;
              iVar5 = *(int *)(iVar15 + 0x4c);
              iVar15 = iVar15 + 4;
            }
            uVar8 = FUN_0010a1c2(*(undefined4 *)(iVar6 + 0x38),*param_1,0);
            uVar2 = *param_1;
            uVar9 = FUN_0010b180(*(undefined4 *)(iVar1 + 0x38),1);
            FUN_0010ba02(uVar8,1,uVar9,0,uVar2);
            iVar5 = FUN_0010b0f4(*(undefined4 *)(iVar1 + 0x38),1);
            uVar2 = *(undefined4 *)(PTR_DAT_00213485 + (uint)*(byte *)(local_7c + 0x10 + iVar5) * 4)
            ;
            iVar5 = FUN_0010b0f4(uVar8,1);
            *(undefined4 *)(iVar5 + 0x10) = uVar2;
            iVar5 = ((int (*)())FUN_00174e94)(param_1,uVar8,iVar6 + 0xc,param_1[10]);
            puVar14 = *(uint **)(iVar6 + 0x40);
            uVar3 = puVar14[1];
            if (0 < (int)uVar3) {
              local_64 = 0;
              while( true ) {
                if (local_64 < *puVar14) {
                  uVar4 = puVar14[1];
                  if (uVar4 <= local_64) {
                    _memset((void *)(puVar14[2] + uVar4 * 4),0,(local_64 - uVar4) * 4 + 4);
                    puVar14[1] = local_64 + 1;
                  }
                  piVar10 = *(int **)(puVar14[2] + local_64 * 4);
                  iVar11 = piVar10[1];
                  iVar15 = *(int *)(iVar11 + 0x2c);
                }
                else {
                  piVar10 = (int *)FUN_001a7f7c(puVar14,local_64);
                  piVar10 = (int *)*piVar10;
                  iVar11 = piVar10[1];
                  iVar15 = *(int *)(iVar11 + 0x2c);
                }
                if (iVar15 < 0) {
                  iVar16 = 1;
                  iVar15 = (**(code **)(**(int **)(iVar11 + 0x38) + 0x14))(*(int **)(iVar11 + 0x38))
                  ;
                  if (0 < iVar15) {
                    do {
                      iVar15 = FUN_0010b180(*(undefined4 *)(iVar11 + 0x38),iVar16);
                      if (iVar15 == *(int *)(iVar6 + 0x38)) {
                        FUN_0010ba02(*(undefined4 *)(iVar11 + 0x38),iVar16,uVar8,0,*param_1);
                      }
                      iVar16 = iVar16 + 1;
                      iVar15 = (**(code **)(**(int **)(iVar11 + 0x38) + 0x14))
                                         (*(int **)(iVar11 + 0x38));
                    } while (iVar16 <= iVar15);
                  }
                  *piVar10 = iVar5;
                  puVar14 = *(uint **)(iVar5 + 0x40);
                  uVar4 = puVar14[1];
                  if (uVar4 < *puVar14) {
                    _memset((void *)(uVar4 * 4 + puVar14[2]),0,4);
                    puVar14[1] = uVar4 + 1;
                    piVar12 = (int *)(uVar4 * 4 + puVar14[2]);
                  }
                  else {
                    piVar12 = (int *)FUN_001a7f7c(puVar14,uVar4);
                  }
                  *piVar12 = (int)piVar10;
                  iVar13 = 4;
                  iVar15 = iVar5;
                  iVar16 = iVar6;
                  do {
                    if ((char)piVar10[6] != '\0') {
                      *(int *)(iVar15 + 0x48) = *(int *)(iVar15 + 0x48) + 1;
                      *(int *)(iVar16 + 0x48) = *(int *)(iVar16 + 0x48) + -1;
                    }
                    piVar10 = (int *)((int)piVar10 + 1);
                    iVar15 = iVar15 + 4;
                    iVar16 = iVar16 + 4;
                    iVar13 = iVar13 + -1;
                  } while (iVar13 != 0);
                  puVar14 = *(uint **)(iVar11 + 0x44);
                  local_54 = puVar14[1] - 1;
                  if (-1 < (int)local_54) {
                    local_30 = local_54 * 4;
                    while( true ) {
                      if (local_54 < *puVar14) {
                        uVar4 = puVar14[1];
                        if (uVar4 <= local_54) {
                          _memset((void *)(puVar14[2] + uVar4 * 4),0,(local_54 - uVar4) * 4 + 4);
                          puVar14[1] = local_54 + 1;
                        }
                        piVar10 = *(int **)(local_30 + puVar14[2]);
                        iVar15 = *piVar10;
                      }
                      else {
                        puVar7 = (undefined4 *)FUN_001a7f7c(puVar14,local_54);
                        piVar10 = (int *)*puVar7;
                        iVar15 = *piVar10;
                      }
                      if ((iVar1 == iVar15) && (*(char *)(local_7c + 0x18 + (int)piVar10) != '\0'))
                      {
                        FUN_001a7f3c(*(undefined4 *)(iVar11 + 0x44),local_54);
                        piVar10 = (int *)(iVar1 + 0x48 + local_7c * 4);
                        *piVar10 = *piVar10 + -1;
                      }
                      local_54 = local_54 - 1;
                      local_30 = local_30 + -4;
                      if (local_54 == 0xffffffff) break;
                      puVar14 = *(uint **)(iVar11 + 0x44);
                    }
                  }
                  if (*(int *)(iVar11 + 0x34) == 0) {
                    FUN_001a7d72(iVar11);
                  }
                  *(int *)(iVar11 + 0x34) = *(int *)(iVar11 + 0x34) + 1;
                }
                local_84 = local_64 + 1;
                local_64 = local_84;
                if (uVar3 == local_84) break;
                puVar14 = *(uint **)(iVar6 + 0x40);
              }
            }
            ((int (*)())FUN_0017e3f2)(param_1,iVar5);
            iVar6 = *(int *)(iVar6 + 0x68);
          }
          else {
LAB_0017e658:
            iVar6 = *(int *)(iVar6 + 0x68);
          }
        }
      }
      local_70 = local_70 + 1;
      local_28 = local_28 + 1;
    } while ((int)local_70 < (int)param_1[0x60]);
  }
  local_34 = param_1;
  do {
    iVar1 = local_34[0x61];
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x2c) < (int)param_1[10])) {
      local_34[0x61] = 0;
      local_4c = *(int *)(iVar1 + 0x68);
      if (local_4c != 0) {
LAB_0017e6ba:
        iVar5 = 4;
        iVar6 = local_4c;
LAB_0017e6c2:
        if (*(int *)(iVar6 + 0x48) < 1) break;
        uVar8 = FUN_0010a1c2(*(undefined4 *)(local_4c + 0x38),*param_1,0);
        uVar2 = *param_1;
        uVar9 = FUN_0010b180(*(undefined4 *)(iVar1 + 0x38),1);
        FUN_0010ba02(uVar8,1,uVar9,0,uVar2);
        iVar6 = ((int (*)())FUN_00174e94)(param_1,uVar8,local_4c + 0xc,param_1[10]);
        puVar14 = *(uint **)(local_4c + 0x40);
        uVar3 = puVar14[1];
        if (0 < (int)uVar3) {
          local_80 = 0;
          while( true ) {
            if (local_80 < *puVar14) {
              uVar4 = puVar14[1];
              if (uVar4 <= local_80) {
                _memset((void *)(puVar14[2] + uVar4 * 4),0,(local_80 - uVar4) * 4 + 4);
                puVar14[1] = local_80 + 1;
              }
              piVar10 = *(int **)(puVar14[2] + local_80 * 4);
              iVar5 = piVar10[1];
              iVar11 = *(int *)(iVar5 + 0x2c);
            }
            else {
              piVar10 = (int *)FUN_001a7f7c(puVar14,local_80);
              piVar10 = (int *)*piVar10;
              iVar5 = piVar10[1];
              iVar11 = *(int *)(iVar5 + 0x2c);
            }
            if (iVar11 < 0) {
              iVar15 = 1;
              iVar11 = (**(code **)(**(int **)(iVar5 + 0x38) + 0x14))(*(int **)(iVar5 + 0x38));
              if (0 < iVar11) {
                do {
                  iVar11 = FUN_0010b180(*(undefined4 *)(iVar5 + 0x38),iVar15);
                  if (iVar11 == *(int *)(local_4c + 0x38)) {
                    FUN_0010ba02(*(undefined4 *)(iVar5 + 0x38),iVar15,uVar8,0,*param_1);
                  }
                  iVar15 = iVar15 + 1;
                  iVar11 = (**(code **)(**(int **)(iVar5 + 0x38) + 0x14))(*(int **)(iVar5 + 0x38));
                } while (iVar15 <= iVar11);
              }
              *piVar10 = iVar6;
              puVar14 = *(uint **)(iVar6 + 0x40);
              uVar4 = puVar14[1];
              if (uVar4 < *puVar14) {
                _memset((void *)(uVar4 * 4 + puVar14[2]),0,4);
                puVar14[1] = uVar4 + 1;
                piVar12 = (int *)(uVar4 * 4 + puVar14[2]);
              }
              else {
                piVar12 = (int *)FUN_001a7f7c(puVar14,uVar4);
              }
              *piVar12 = (int)piVar10;
              iVar16 = 4;
              iVar11 = iVar6;
              iVar15 = local_4c;
              do {
                if ((char)piVar10[6] != '\0') {
                  *(int *)(iVar11 + 0x48) = *(int *)(iVar11 + 0x48) + 1;
                  *(int *)(iVar15 + 0x48) = *(int *)(iVar15 + 0x48) + -1;
                }
                piVar10 = (int *)((int)piVar10 + 1);
                iVar11 = iVar11 + 4;
                iVar15 = iVar15 + 4;
                iVar16 = iVar16 + -1;
              } while (iVar16 != 0);
              if (*(int *)(iVar5 + 0x34) == 0) {
                FUN_001a7d72(iVar5);
                *(int *)(iVar5 + 0x34) = *(int *)(iVar5 + 0x34) + 1;
              }
              else {
                *(int *)(iVar5 + 0x34) = *(int *)(iVar5 + 0x34) + 1;
              }
            }
            if (uVar3 == local_80 + 1) break;
            local_80 = local_80 + 1;
            puVar14 = *(uint **)(local_4c + 0x40);
          }
        }
        ((int (*)())FUN_0017e3f2)(param_1,iVar6);
        local_4c = *(int *)(local_4c + 0x68);
        goto LAB_0017e6de;
      }
    }
LAB_0017e6e5:
    local_34 = local_34 + 1;
    if (param_1 + 2 == local_34) {
      return;
    }
  } while( true );
  iVar6 = iVar6 + 4;
  iVar5 = iVar5 + -1;
  if (iVar5 == 0) goto code_r0x0017e6d5;
  goto LAB_0017e6c2;
code_r0x0017e6d5:
  local_4c = *(int *)(local_4c + 0x68);
LAB_0017e6de:
  if (local_4c == 0) goto LAB_0017e6e5;
  goto LAB_0017e6ba;
}

/* FUN_0017ed44 @ 0x17ed44 (1537 bytes) */
int FUN_0017ed44(param_1)
  int *param_1;
{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int *local_30;
  int local_18;
  int local_14;
  int local_10;
  
  iVar2 = param_1[10];
  (**(code **)(*(int *)param_1[3] + 0x14))((int *)param_1[3],param_1[0xb]);
  (**(code **)(*(int *)param_1[2] + 0x14))((int *)param_1[2]);
  param_1[10] = param_1[10] + 1;
  puVar3 = (undefined4 *)param_1[0xb];
  iVar7 = 0;
  puVar8 = puVar3;
  do {
    *puVar8 = 0;
    iVar7 = iVar7 + 1;
    puVar8 = puVar8 + 1;
  } while (iVar7 != 5);
  FUN_001a7d22(puVar3 + 5);
  iVar7 = *(int *)(param_1[0x14] + 8);
  if (iVar7 != 0) {
    iVar10 = param_1[0x14];
    do {
      FUN_001a7d72(iVar10);
      FUN_001a7cd6(param_1 + 0x1e,iVar10);
      piVar1 = (int *)(iVar7 + 8);
      iVar10 = iVar7;
      iVar7 = *piVar1;
    } while (*piVar1 != 0);
  }
  local_30 = param_1 + 0x1e;
  iVar7 = param_1[0xe];
  for (iVar10 = *(int *)(param_1[0xe] + 8); iVar10 != 0; iVar10 = *(int *)(iVar10 + 8)) {
    FUN_001a7d72(iVar7);
    FUN_001a7cd6(local_30,iVar7);
    iVar7 = iVar10;
  }
  param_1[0x43] = 0;
  param_1[0x46] = -1;
  param_1[0x47] = -1;
  iVar7 = param_1[0x20];
  if (*(int *)(iVar7 + 8) == 0) {
    local_18 = -1;
    iVar10 = -1;
  }
  else {
    local_18 = -1;
    iVar10 = -1;
    do {
      while( true ) {
        if (param_1[0x43] < *(int *)(iVar7 + 0x14)) {
          param_1[0x43] = *(int *)(iVar7 + 0x14);
        }
        cVar5 = (**(code **)(*(int *)param_1[3] + 0x20))
                          ((int *)param_1[3],*(undefined4 *)(iVar7 + 0x38));
        if ((cVar5 == '\0') &&
           (cVar5 = (**(code **)(*(int *)param_1[3] + 0x24))
                              ((int *)param_1[3],*(undefined4 *)(iVar7 + 0x38)), cVar5 == '\0'))
        break;
        iVar6 = *(int *)(iVar7 + 0xc);
        if (*(int *)(iVar7 + 0xc) < param_1[0x47]) {
          iVar6 = param_1[0x47];
        }
        param_1[0x47] = iVar6;
        local_18 = param_1[10];
        iVar7 = *(int *)(iVar7 + 8);
        if (*(int *)(iVar7 + 8) == 0) goto LAB_0017eeeb;
      }
      iVar10 = *(int *)(iVar7 + 0xc);
      if (*(int *)(iVar7 + 0xc) < param_1[0x46]) {
        iVar10 = param_1[0x46];
      }
      param_1[0x46] = iVar10;
      iVar10 = param_1[10];
      iVar7 = *(int *)(iVar7 + 8);
    } while (*(int *)(iVar7 + 8) != 0);
  }
LAB_0017eeeb:
  iVar6 = param_1[0x1a];
  iVar7 = *(int *)(iVar6 + 8);
joined_r0x0017eefc:
  if (iVar7 != 0) {
    do {
      if (param_1[0x43] < *(int *)(iVar6 + 0x14)) {
        param_1[0x43] = *(int *)(iVar6 + 0x14);
      }
      cVar5 = (**(code **)(*(int *)param_1[3] + 0x20))
                        ((int *)param_1[3],*(undefined4 *)(iVar6 + 0x38));
      if ((cVar5 == '\0') &&
         (cVar5 = (**(code **)(*(int *)param_1[3] + 0x24))
                            ((int *)param_1[3],*(undefined4 *)(iVar6 + 0x38)), cVar5 == '\0')) {
        iVar7 = *(int *)(iVar6 + 0xc);
        if (*(int *)(iVar6 + 0xc) < param_1[0x46]) {
          iVar7 = param_1[0x46];
        }
        param_1[0x46] = iVar7;
        if ((iVar10 < 0) || (*(int *)(iVar6 + 0x30) < iVar10)) goto LAB_0017ef9f;
      }
      else {
        iVar7 = *(int *)(iVar6 + 0xc);
        if (*(int *)(iVar6 + 0xc) < param_1[0x47]) {
          iVar7 = param_1[0x47];
        }
        param_1[0x47] = iVar7;
        if ((local_18 < 0) || (*(int *)(iVar6 + 0x30) < local_18)) {
          local_18 = *(int *)(iVar6 + 0x30);
        }
      }
      iVar6 = *(int *)(iVar6 + 8);
      if (*(int *)(iVar6 + 8) == 0) break;
    } while( true );
  }
  iVar6 = param_1[0x3f];
  iVar7 = *(int *)(iVar6 + 8);
  while (iVar7 != 0) {
    while( true ) {
      if (param_1[0x43] < *(int *)(iVar6 + 0x14)) {
        param_1[0x43] = *(int *)(iVar6 + 0x14);
      }
      iVar7 = *(int *)(iVar6 + 0xc);
      if (*(int *)(iVar6 + 0xc) < param_1[0x46]) {
        iVar7 = param_1[0x46];
      }
      param_1[0x46] = iVar7;
      if ((iVar10 < 0) || (*(int *)(iVar6 + 0x30) < iVar10)) break;
      iVar6 = *(int *)(iVar6 + 8);
      if (*(int *)(iVar6 + 8) == 0) goto LAB_0017f008;
    }
    iVar10 = *(int *)(iVar6 + 0x30);
    iVar6 = *(int *)(iVar6 + 8);
    iVar7 = *(int *)(iVar6 + 8);
  }
LAB_0017f008:
  iVar7 = (**(code **)(*(int *)param_1[2] + 0x5c))((int *)param_1[2]);
  param_1[0x44] = iVar7;
  *(bool *)((int)param_1 + 0x21) = param_1[0x43] <= iVar7;
  if (iVar10 < 0) {
    if (local_18 < 0) goto LAB_0017f057;
    iVar7 = param_1[10];
    if (param_1[10] < local_18) {
      iVar7 = local_18;
    }
    param_1[10] = iVar7;
LAB_0017f20a:
    iVar7 = param_1[0x20];
    iVar10 = *(int *)(iVar7 + 8);
  }
  else {
    if (local_18 < 0) {
      if (iVar10 <= param_1[10]) {
        iVar10 = param_1[10];
      }
      param_1[10] = iVar10;
    }
    else {
      if (((char)param_1[0x45] != '\0') && (local_18 < iVar10)) {
        iVar7 = param_1[10];
        if (param_1[10] < local_18) {
          iVar7 = local_18;
        }
        param_1[10] = iVar7;
        goto LAB_0017f20a;
      }
      if (iVar10 <= param_1[10]) {
        iVar10 = param_1[10];
      }
      param_1[10] = iVar10;
    }
LAB_0017f057:
    iVar7 = param_1[0x20];
    iVar10 = *(int *)(iVar7 + 8);
  }
  if (iVar10 == 0) {
    local_14 = 0;
    local_10 = 0;
  }
  else {
    local_14 = 0;
    local_10 = 0;
    do {
      FUN_001a7d72(iVar7);
      ((int (*)())FUN_0017e3f2)(param_1,iVar7);
      cVar5 = (**(code **)(*(int *)param_1[3] + 0x20))
                        ((int *)param_1[3],*(undefined4 *)(iVar7 + 0x38));
      if ((cVar5 == '\0') &&
         (cVar5 = (**(code **)(*(int *)param_1[3] + 0x24))
                            ((int *)param_1[3],*(undefined4 *)(iVar7 + 0x38)), cVar5 == '\0')) {
        iVar4 = *(int *)(iVar10 + 8);
      }
      else {
        iVar6 = *(int *)(iVar7 + 0x14);
        if (*(int *)(iVar7 + 0x14) <= local_10) {
          iVar6 = local_10;
        }
        iVar9 = local_14 + 1;
        if (*(int *)(iVar7 + 0xc) != param_1[0x47]) {
          iVar9 = local_14;
        }
        iVar4 = *(int *)(iVar10 + 8);
        local_10 = iVar6;
        local_14 = iVar9;
      }
      iVar7 = iVar10;
      iVar10 = iVar4;
    } while (iVar4 != 0);
  }
  iVar7 = param_1[0x1a];
  iVar10 = *(int *)(param_1[0x1a] + 8);
joined_r0x0017f104:
  do {
    if (iVar10 == 0) {
      cVar5 = FUN_001a7c84(param_1 + 0x3d);
      if ((((cVar5 == '\0') && (cVar5 = FUN_001a7c84(param_1 + 0x12), cVar5 != '\0')) &&
          (cVar5 = FUN_001a7c84(param_1 + 0xc), cVar5 != '\0')) &&
         (iVar7 = FUN_001a7d8a(param_1 + 0x3d), iVar7 == param_1[0x3c])) {
        iVar7 = param_1[0x3f];
        for (iVar10 = *(int *)(param_1[0x3f] + 8); iVar10 != 0; iVar10 = *(int *)(iVar10 + 8)) {
          FUN_001a7d72(iVar7);
          *(undefined1 *)(iVar7 + 0x65) = 0;
          FUN_001a7cd6(param_1 + 0x12,iVar7);
          iVar7 = iVar10;
        }
      }
      cVar5 = (**(code **)(**(int **)(*param_1 + 0x54) + 0xd4))(*(int **)(*param_1 + 0x54));
      if ((cVar5 != '\0') &&
         (cVar5 = (**(code **)(*(int *)param_1[2] + 0x18))((int *)param_1[2]), cVar5 != '\0')) {
        ((int (*)())FUN_0017e5b2)(param_1);
      }
      FUN_00173de2(param_1,local_14,local_10);
      return param_1[10] - iVar2;
    }
    cVar5 = ((int (*)())FUN_00175a4c)(param_1,iVar7);
    if (cVar5 != '\0') {
      FUN_001a7d72(iVar7);
      ((int (*)())FUN_0017e3f2)(param_1,iVar7);
      cVar5 = (**(code **)(*(int *)param_1[3] + 0x20))
                        ((int *)param_1[3],*(undefined4 *)(iVar7 + 0x38));
      if ((cVar5 != '\0') ||
         (cVar5 = (**(code **)(*(int *)param_1[3] + 0x24))
                            ((int *)param_1[3],*(undefined4 *)(iVar7 + 0x38)), cVar5 != '\0')) {
        iVar6 = *(int *)(iVar7 + 0x14);
        if (*(int *)(iVar7 + 0x14) <= local_10) {
          iVar6 = local_10;
        }
        iVar9 = local_14 + 1;
        if (*(int *)(iVar7 + 0xc) != param_1[0x47]) {
          iVar9 = local_14;
        }
        iVar7 = iVar10;
        iVar10 = *(int *)(iVar10 + 8);
        local_14 = iVar9;
        local_10 = iVar6;
        goto joined_r0x0017f104;
      }
    }
    iVar7 = iVar10;
    iVar10 = *(int *)(iVar10 + 8);
  } while( true );
LAB_0017ef9f:
  iVar10 = *(int *)(iVar6 + 0x30);
  iVar6 = *(int *)(iVar6 + 8);
  iVar7 = *(int *)(iVar6 + 8);
  goto joined_r0x0017eefc;
}

/* FUN_0017f346 @ 0x17f346 (221 bytes) */
int FUN_0017f346(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  char local_11;
  
  cVar1 = (**(code **)(*(int *)param_1[2] + 0x50))((int *)param_1[2]);
  if (cVar1 != '\0') {
    cVar1 = FUN_000e1402(*param_1,0x28);
    if ((cVar1 == '\0') ||
       (cVar1 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],param_2), cVar1 == '\0'))
    {
      local_11 = '\0';
    }
    else {
      local_11 = '\x01';
    }
    iVar2 = (**(code **)(*(int *)param_1[2] + 0x4c))
                      ((int *)param_1[2],*(undefined4 *)(param_2 + 0x38));
    if ((iVar2 != *(int *)(param_2 + 0x58)) || (local_11 != *(char *)(param_2 + 0x5c))) {
      ((int (*)())FUN_001826a6)(param_1[2],param_2);
      *(int *)(param_2 + 0x58) = iVar2;
      *(char *)(param_2 + 0x5c) = local_11;
      ((int (*)())FUN_00182640)(param_1[2],param_2);
    }
  }
  cVar1 = ((int (*)())FUN_00175a4c)(param_1,param_2);
  if (cVar1 == '\0') {
    FUN_001a7cd6();
    return;
  }
  ((int (*)())FUN_0017e3f2)();
  return;
}

/* FUN_001804f8 @ 0x1804f8 (6900 bytes) */
int FUN_001804f8(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  uint *puVar15;
  char *pcVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int *piVar20;
  int local_94;
  uint uVar21;
  uint uVar22;
  uint local_70;
  int local_6c;
  uint local_64;
  uint local_60;
  int *local_5c;
  int *local_58;
  uint local_54;
  int local_50;
  uint local_4c;
  uint *local_48;
  uint local_44;
  uint local_40;
  int *local_3c;
  uint *local_38;
  uint local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  undefined4 local_24;
  int *local_20 [4];
  
  if ((char)param_1[0x45] == '\0') {
    local_6c = param_1[0x14];
  }
  else {
    local_6c = param_1[0xe];
  }
  uVar3 = true;
  local_64 = 0;
  local_60 = 0;
  local_5c = (int *)0x0;
  iVar12 = *(int *)(local_6c + 8);
  iVar18 = local_6c;
  while ((iVar12 != 0 &&
         ((piVar7 = *(int **)(iVar18 + 0x38), (char)param_1[0x45] != '\0' ||
          (*(int *)(iVar18 + 0x10) <= param_2))))) {
    cVar4 = FUN_0010a320(piVar7);
    if (cVar4 == '\0') {
      cVar4 = FUN_0010a35a(piVar7);
      if (cVar4 == '\0') {
        local_5c = (int *)((int)local_5c + 1);
        iVar12 = *(int *)(iVar18 + 0x60);
        if (iVar12 != 0) {
          if (-1 < *(int *)(iVar12 + 4)) {
            cVar4 = FUN_000e1402(*param_1,0x25);
            if (cVar4 != '\0') {
              if (((piVar7[0x20] != 0) && (cVar4 = FUN_0012dfd8(piVar7[0x26]), cVar4 != '\0')) &&
                 ((*(byte *)(piVar7 + 5) & 2) == 0)) {
                (**(code **)(*piVar7 + 0x50))(piVar7);
              }
              iVar12 = *(int *)(*(int *)(iVar18 + 0x60) + 4);
              iVar5 = 0;
              piVar11 = param_1;
              do {
                iVar17 = *(int *)(iVar12 * 4 + piVar11[0x4c]);
                piVar20 = (int *)0x0;
                if (iVar17 != 0) {
                  piVar20 = *(int **)(iVar17 + 0x48 + iVar5 * 4);
                }
                (&local_30)[iVar5] = piVar20;
                iVar5 = iVar5 + 1;
                piVar11 = piVar11 + 1;
              } while (iVar5 != 4);
              puVar15 = *(uint **)(iVar18 + 0x44);
              uVar21 = puVar15[1];
              if (0 < (int)uVar21) {
                uVar22 = 0;
                while( true ) {
                  if (uVar22 < *puVar15) {
                    uVar1 = puVar15[1];
                    if (uVar1 <= uVar22) {
                      _memset((void *)(puVar15[2] + uVar1 * 4),0,(uVar22 - uVar1) * 4 + 4);
                      puVar15[1] = uVar22 + 1;
                    }
                    piVar11 = (int *)(puVar15[2] + uVar22 * 4);
                  }
                  else {
                    piVar11 = (int *)FUN_001a7f7c(puVar15,uVar22);
                  }
                  uVar22 = uVar22 + 1;
                  puVar15 = (uint *)*piVar11;
                  local_4c = *puVar15;
                  if (((((puVar15[2] == 0) &&
                        (piVar11 = *(int **)(local_4c + 0x38), piVar11[0x20] != 0)) &&
                       ((cVar4 = FUN_0012dfd8(piVar11[0x26]), cVar4 != '\0' &&
                        (((*(byte *)(piVar11 + 5) & 2) == 0 &&
                         (cVar4 = (**(code **)(*piVar11 + 0x50))(piVar11), cVar4 == '\0')))))) &&
                      ((*(byte *)(*(int *)(local_4c + 0x38) + 0x14) & 0x40) != 0)) &&
                     (iVar12 == *(int *)(*(int *)(local_4c + 0x38) + 0x94))) {
                    iVar17 = 1;
                    iVar5 = (int)&local_2c;
                    do {
                      if ((char)puVar15[6] != '\0') {
                        *(int *)(iVar5 + 0xfffffffcU) = *(int *)(iVar5 + 0xfffffffcU) + -1;
                      }
                      iVar17 = iVar17 + 1;
                      iVar5 = iVar5 + 4;
                      puVar15 = (uint *)((int)puVar15 + 1);
                    } while (iVar17 != 5);
                  }
                  if (uVar21 == uVar22) break;
                  puVar15 = *(uint **)(iVar18 + 0x44);
                }
              }
              iVar12 = 0;
              do {
                iVar5 = FUN_0010b0f4(piVar7,0);
                if ((*(char *)(iVar12 + 0x10 + iVar5) != '\x01') && (0 < (int)(&local_30)[iVar12]))
                {
                  local_6c = *(int *)(iVar18 + 8);
                  goto LAB_001805c3;
                }
                iVar12 = iVar12 + 1;
              } while (iVar12 != 4);
            }
            iVar12 = *(int *)(iVar18 + 0x60);
            if (iVar12 == 0) goto LAB_001807c0;
          }
          if (*(int *)(iVar12 + 8) != 0) {
            if (*(int *)(*(int *)(iVar12 + 8) + 0x2c) == param_1[10]) {
              iVar12 = FUN_0010b0f4(piVar7,0);
              local_20[0] = *(int **)(iVar12 + 0x10);
              iVar12 = *(int *)(iVar18 + 0x60);
              pcVar16 = (char *)(iVar12 + 0xc);
              iVar5 = 1;
              do {
                if ((*pcVar16 != '\x01') && (*(char *)((int)local_20 + iVar5 + -1) != '\x01')) {
                  local_6c = *(int *)(iVar18 + 8);
                  FUN_001a7d72(iVar18);
                  FUN_001a7cd6(param_1 + 0x1e,iVar18);
                  goto LAB_001805c3;
                }
                iVar5 = iVar5 + 1;
                pcVar16 = pcVar16 + 1;
              } while (iVar5 != 5);
            }
            iVar12 = *(int *)(*(int *)(*(int *)(iVar12 + 8) + 0x38) + 0x98);
            if (iVar12 != piVar7[0x26]) {
              if (piVar7[0x26] == 1) {
                piVar7[0x26] = 0;
              }
              else {
                if (((*(byte *)(piVar7 + 5) & 0x20) != 0) || (iVar12 != 1)) {
                  local_6c = *(int *)(iVar18 + 8);
                  goto LAB_001805c3;
                }
                piVar7[0x26] = 1;
              }
            }
          }
        }
LAB_001807c0:
        cVar4 = FUN_000e1402(*param_1,0x25);
        if ((cVar4 != '\0') &&
           (((((*(int *)(iVar18 + 0x60) == 0 || (*(int *)(*(int *)(iVar18 + 0x60) + 4) < 0)) &&
              (piVar7[0x26] == 1)) &&
             ((*(char *)(iVar18 + 100) == '\0' && ((piVar7[5] & 0x40U) == 0)))) &&
            ((piVar7[5] & 0x20U) == 0)))) {
          cVar4 = (**(code **)(**(int **)(*param_1 + 0x54) + 0x7c))
                            (*(int **)(*param_1 + 0x54),piVar7);
          iVar12 = DAT_001cc6f4;
          if (cVar4 != '\0') {
            if (*(int **)(iVar18 + 0x60) == (int *)0x0) {
              iVar12 = piVar7[3];
            }
            else {
              iVar12 = **(int **)(iVar18 + 0x60);
            }
          }
          iVar12 = ((int (*)())FUN_00175c04)(param_1,1,iVar12);
          piVar11 = *(int **)(*param_1 + 0x54);
          iVar5 = (**(code **)(*piVar11 + 0x138))(piVar11,*param_1);
          if ((iVar12 < 0) || (iVar5 + 4 <= iVar12)) {
            if ((*(int *)(iVar18 + 0x58) == 2) &&
               (cVar4 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar18),
               cVar4 != '\0')) {
              ((int (*)())FUN_001826a6)(param_1[2],iVar18);
              (**(code **)(*(int *)param_1[2] + 0x38))((int *)param_1[2],iVar18);
              ((int (*)())FUN_00182640)(param_1[2],iVar18);
            }
            piVar7[0x26] = 0;
          }
        }
        cVar4 = (**(code **)(*(int *)param_1[3] + 0xc))((int *)param_1[3],piVar7);
        if (cVar4 == '\0') {
          local_6c = *(int *)(iVar18 + 8);
          FUN_001a7d72(iVar18);
        }
        else {
          if ((*(byte *)(*(int *)(*param_1 + 0x54) + 9) & 2) == 0) {
            cVar4 = (**(code **)(*(int *)param_1[2] + 0xc))((int *)param_1[2],piVar7);
            if (cVar4 != '\0') {
LAB_00180e70:
              FUN_001a7d72(iVar18);
              return iVar18;
            }
            cVar4 = (**(code **)(*(int *)param_1[2] + 0x24))((int *)param_1[2]);
            if (cVar4 != '\0') {
              iVar12 = ((int (*)())FUN_00177012)(param_1,iVar18);
              if (iVar12 != 0) {
                return iVar12;
              }
              goto LAB_00180e70;
            }
            cVar4 = FUN_000e1402(*param_1,0x28);
            if (cVar4 != '\0') {
              cVar4 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar18);
              if ((cVar4 != '\0') &&
                 (cVar4 = (**(code **)(*(int *)param_1[2] + 0x2c))
                                    ((int *)param_1[2],iVar18,param_1 + 0x4c), cVar4 != '\0')) {
                FUN_001a7d72(iVar18);
                return iVar18;
              }
              local_48 = (uint *)0x0;
              local_44 = 0;
              local_40 = 0;
              iVar12 = 0;
              do {
                uVar21 = *(uint *)(param_1[0xb] + iVar12 * 4);
                if (uVar21 != 0) {
                  local_48 = (uint *)((int)local_48 + 1);
                  cVar4 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],uVar21);
                  local_40 = uVar21;
                  if (cVar4 != '\0') {
                    local_44 = local_44 + 1;
                  }
                }
                iVar12 = iVar12 + 1;
              } while (iVar12 != 5);
              if ((local_48 == (uint *)((int)&MACH_HEADER.magic + 1)) && (local_44 == 1)) {
                (**(code **)(*(int *)param_1[2] + 8))((int *)param_1[2]);
                cVar4 = (**(code **)(*(int *)param_1[2] + 0xc))
                                  ((int *)param_1[2],*(undefined4 *)(iVar18 + 0x38));
                if (cVar4 != '\0') {
                  (**(code **)(*(int *)param_1[2] + 0x10))
                            ((int *)param_1[2],*(undefined4 *)(iVar18 + 0x38));
                  cVar4 = (**(code **)(*(int *)param_1[2] + 0x2c))
                                    ((int *)param_1[2],local_40,param_1 + 0x4c);
                  if (cVar4 != '\0') {
                    (**(code **)(*(int *)param_1[2] + 8))((int *)param_1[2]);
                    (**(code **)(*(int *)param_1[2] + 0x10))
                              ((int *)param_1[2],*(undefined4 *)(local_40 + 0x38));
                    goto LAB_00180e3e;
                  }
                }
                (**(code **)(*(int *)param_1[2] + 8))((int *)param_1[2]);
                (**(code **)(*(int *)param_1[2] + 0x10))
                          ((int *)param_1[2],*(undefined4 *)(local_40 + 0x38));
              }
            }
          }
          else {
            cVar4 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],iVar18);
            if ((cVar4 == '\0') || (cVar4 = FUN_000e1402(*param_1,0x28), cVar4 == '\0')) {
              cVar4 = (**(code **)(*(int *)param_1[2] + 0xc))((int *)param_1[2],piVar7);
              if (cVar4 != '\0') {
LAB_00180e3e:
                FUN_001a7d72(iVar18);
                return iVar18;
              }
            }
            else {
              cVar4 = (**(code **)(*(int *)param_1[2] + 0x2c))
                                ((int *)param_1[2],iVar18,param_1 + 0x4c);
              if (cVar4 != '\0') {
                FUN_001a7d72(iVar18);
                return iVar18;
              }
            }
          }
          local_6c = *(int *)(iVar18 + 8);
          FUN_001a7d72(iVar18);
          cVar4 = FUN_000e1402(*param_1,0x27);
          if ((((cVar4 != '\0') && (cVar4 = FUN_000e1402(*param_1,0x2b), cVar4 == '\0')) &&
              ((char)param_1[0x45] == '\0')) &&
             ((*(int *)(iVar18 + 0x60) == 0 || ((*(byte *)(param_1[1] + 0x31) & 0x20) != 0)))) {
            iVar12 = (**(code **)(*(int *)param_1[2] + 0x3c))((int *)param_1[2],piVar7);
            if (iVar12 - 1U < 3) {
              FUN_001a7cd6(param_1 + (iVar12 - 1U) * 6 + 0x2a,iVar18);
              uVar3 = false;
              goto LAB_001805c3;
            }
          }
        }
        FUN_001a7cd6(param_1 + 0x1e,iVar18);
        uVar3 = false;
      }
      else {
        local_60 = local_60 + 1;
        cVar4 = ((int (*)())FUN_0017e0d0)(param_1,iVar18);
        if (cVar4 != '\0') goto LAB_00180e3e;
        local_6c = *(int *)(iVar18 + 8);
        FUN_001a7d72(iVar18);
        FUN_001a7cd6(param_1 + 0x1e,iVar18);
      }
    }
    else {
      local_64 = local_64 + 1;
      cVar4 = ((int (*)())FUN_0017d7e0)(param_1,iVar18);
      if (cVar4 != '\0') {
        FUN_001a7d72(iVar18);
        return iVar18;
      }
      local_6c = *(int *)(iVar18 + 8);
      FUN_001a7d72(iVar18);
      FUN_001a7cd6(param_1 + 0x1e,iVar18);
    }
LAB_001805c3:
    iVar12 = *(int *)(local_6c + 8);
    iVar18 = local_6c;
  }
  if ((char)param_1[0x45] == '\0') {
    if (((0 < (int)local_64) || (0 < (int)local_60)) &&
       ((local_5c == (int *)0x0 && (cVar4 = FUN_001a7c84(param_1 + 0x18), cVar4 != '\0')))) {
      iVar12 = 5;
      piVar7 = (int *)param_1[0xb];
      do {
        if (*piVar7 != 0) goto LAB_001805f7;
        piVar7 = piVar7 + 1;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      cVar4 = FUN_001a7c84((int *)param_1[0xb] + 5);
      if (cVar4 != '\0') {
        if ((int)local_64 < 1) {
          if ((int)local_60 < 1) {
            return 0;
          }
          (**(code **)(*(int *)param_1[2] + 0x1c))((int *)param_1[2]);
          return 0;
        }
        if (0 < param_1[0x60]) {
          local_60 = 0;
          local_20[0] = param_1;
          do {
            iVar12 = local_20[0][0x5b];
            local_64 = local_60 & 0x80000003;
            if ((int)local_64 < 0) {
              local_64 = (local_64 - 1 | 0xfffffffc) + 1;
            }
            iVar18 = *(int *)(iVar12 + 0x68);
            while (iVar18 != 0) {
              iVar5 = FUN_0010b0f4(*(undefined4 *)(iVar18 + 0x38),1);
              if (*(int *)(iVar5 + 0x10) == *(int *)(PTR_DAT_00213485 + local_64 * 4)) {
                iVar17 = 0;
                iVar5 = *(int *)(iVar18 + 0x48);
                iVar19 = iVar18;
                while (iVar5 < 1) {
                  iVar17 = iVar17 + 1;
                  if (iVar17 == 4) goto LAB_0017f495;
                  iVar5 = *(int *)(iVar19 + 0x4c);
                  iVar19 = iVar19 + 4;
                }
                uVar13 = FUN_000f5a44(DAT_001cc6f0,*(undefined4 *)(*(int *)(iVar18 + 0x38) + 0xc));
                iVar5 = ((int (*)())FUN_00176f3a)(param_1,*(undefined4 *)(iVar18 + 0x38),uVar13,param_1[10],
                                     iVar18 + 0xc);
                puVar15 = *(uint **)(iVar18 + 0x40);
                local_54 = puVar15[1] - 1;
                if (-1 < (int)local_54) {
                  local_28 = (int *)(local_54 * 4);
                  local_24 = local_54;
                  while( true ) {
                    if (local_54 < *puVar15) {
                      uVar21 = puVar15[1];
                      if (uVar21 <= local_54) {
                        _memset((void *)(puVar15[2] + uVar21 * 4),0,(local_54 - uVar21) * 4 + 4);
                        puVar15[1] = local_54 + 1;
                      }
                      piVar7 = *(int **)((int)local_28 + puVar15[2]);
                      local_4c = piVar7[1];
                      iVar17 = *(int *)(local_4c + 0x2c);
                    }
                    else {
                      piVar7 = (int *)FUN_001a7f7c(puVar15,local_54);
                      piVar7 = (int *)*piVar7;
                      local_4c = piVar7[1];
                      iVar17 = *(int *)(local_4c + 0x2c);
                    }
                    if (iVar17 < 0) {
                      iVar19 = 1;
                      iVar17 = (**(code **)(**(int **)(local_4c + 0x38) + 0x14))
                                         (*(int **)(local_4c + 0x38));
                      if (0 < iVar17) {
                        do {
                          iVar17 = FUN_0010b180(*(undefined4 *)(local_4c + 0x38),iVar19);
                          if (iVar17 == *(int *)(iVar18 + 0x38)) {
                            FUN_0010ba02(*(undefined4 *)(local_4c + 0x38),iVar19,
                                         *(undefined4 *)(iVar5 + 0x38),0,*param_1);
                          }
                          iVar19 = iVar19 + 1;
                          iVar17 = (**(code **)(**(int **)(local_4c + 0x38) + 0x14))
                                             (*(int **)(local_4c + 0x38));
                        } while (iVar19 <= iVar17);
                      }
                      *piVar7 = iVar5;
                      FUN_001a7f3c(*(undefined4 *)(iVar18 + 0x40),local_54);
                      local_48 = *(uint **)(iVar5 + 0x40);
                      local_44 = local_48[1];
                      if (local_44 < *local_48) {
                        iVar17 = local_44 * 4;
                        _memset((void *)(iVar17 + local_48[2]),0,4);
                        local_48[1] = local_44 + 1;
                        piVar11 = (int *)(iVar17 + local_48[2]);
                      }
                      else {
                        piVar11 = (int *)FUN_001a7f7c(local_48,local_44);
                      }
                      *piVar11 = (int)piVar7;
                      if (*(int *)(local_4c + 0x34) == 0) {
                        FUN_001a7d72(local_4c);
                      }
                      *(int *)(local_4c + 0x34) = *(int *)(local_4c + 0x34) + 1;
                      iVar8 = 0;
                      iVar17 = iVar5;
                      iVar19 = iVar18;
                      do {
                        if ((char)piVar7[6] != '\0') {
                          *(int *)(iVar17 + 0x48) = *(int *)(iVar17 + 0x48) + 1;
                          *(int *)(iVar19 + 0x48) = *(int *)(iVar19 + 0x48) + -1;
                        }
                        iVar8 = iVar8 + 1;
                        piVar7 = (int *)((int)piVar7 + 1);
                        iVar17 = iVar17 + 4;
                        iVar19 = iVar19 + 4;
                      } while (iVar8 != 4);
                      puVar15 = *(uint **)(local_4c + 0x44);
                      local_40 = puVar15[1] - 1;
                      if (-1 < (int)local_40) {
                        local_30 = (int *)(local_40 * 4);
                        local_2c = (int *)local_40;
                        while( true ) {
                          if (local_40 < *puVar15) {
                            uVar21 = puVar15[1];
                            if (uVar21 <= local_40) {
                              _memset((void *)(puVar15[2] + uVar21 * 4),0,
                                      (local_40 - uVar21) * 4 + 4);
                              puVar15[1] = local_40 + 1;
                            }
                            local_3c = *(int **)((int)local_30 + puVar15[2]);
                            iVar17 = *local_3c;
                          }
                          else {
                            puVar14 = (undefined4 *)FUN_001a7f7c(puVar15,local_40);
                            local_3c = (int *)*puVar14;
                            iVar17 = *local_3c;
                          }
                          if ((iVar12 == iVar17) &&
                             (*(char *)(local_64 + 0x18 + (int)local_3c) != '\0')) {
                            FUN_001a7f3c(*(undefined4 *)(local_4c + 0x44),local_40);
                            local_3c[1] = iVar5;
                            local_38 = *(uint **)(iVar5 + 0x44);
                            local_34 = local_38[1];
                            if (local_34 < *local_38) {
                              iVar17 = local_34 * 4;
                              _memset((void *)(iVar17 + local_38[2]),0,4);
                              local_38[1] = local_34 + 1;
                              *(int **)(iVar17 + local_38[2]) = local_3c;
                            }
                            else {
                              puVar14 = (undefined4 *)FUN_001a7f7c(local_38,local_34);
                              *puVar14 = local_3c;
                            }
                          }
                          local_40 = local_40 - 1;
                          local_30 = local_30 + -1;
                          if (local_40 == 0xffffffff) break;
                          puVar15 = *(uint **)(local_4c + 0x44);
                        }
                      }
                    }
                    local_54 = local_54 - 1;
                    local_28 = (int *)((int)local_28 + -4);
                    if (local_54 == 0xffffffff) break;
                    puVar15 = *(uint **)(iVar18 + 0x40);
                  }
                }
                ((int (*)())FUN_00174cc0)(param_1,iVar18,iVar5,1,0,*(undefined4 *)(*(int *)(iVar5 + 0x38) + 0xc))
                ;
                *(int *)(iVar5 + 0x34) = *(int *)(iVar5 + 0x34) + -1;
                iVar17 = *(int *)(iVar18 + 0x2c);
                iVar19 = ((int (*)())FUN_0017412a)(param_1,*(undefined4 *)(iVar18 + 0x38),
                                      *(undefined4 *)(iVar5 + 0x38),0,1,0);
                iVar17 = iVar17 + iVar19;
                if (*(int *)(iVar5 + 0x30) < iVar17) {
                  *(int *)(iVar5 + 0x30) = iVar17;
                }
                ((int (*)())FUN_0017f346)(param_1,iVar5);
                iVar18 = *(int *)(iVar18 + 0x68);
              }
              else {
LAB_0017f495:
                iVar18 = *(int *)(iVar18 + 0x68);
              }
            }
            local_60 = local_60 + 1;
            local_20[0] = local_20[0] + 1;
          } while ((int)local_60 < param_1[0x60]);
        }
        cVar4 = FUN_001a7c84(param_1 + 0x12);
        if (cVar4 == '\0') {
          iVar12 = param_1[0x14];
          cVar4 = (**(code **)(*(int *)param_1[2] + 0xc))
                            ((int *)param_1[2],*(undefined4 *)(iVar12 + 0x38));
          if ((cVar4 != '\0') &&
             (cVar4 = (**(code **)(*(int *)param_1[3] + 0xc))
                                ((int *)param_1[3],*(undefined4 *)(iVar12 + 0x38)), cVar4 != '\0'))
          {
            FUN_001a7d72(iVar12);
            return iVar12;
          }
        }
        return 0;
      }
    }
LAB_001805f7:
    cVar4 = FUN_001a7c84(param_1 + 0x12);
  }
  else {
    cVar4 = FUN_001a7c84(param_1 + 0xc);
  }
  if ((cVar4 != '\0') || (!(bool)uVar3)) {
    return 0;
  }
  if ((char)param_1[0x45] == '\0') {
    local_94 = param_1[0x14];
  }
  else {
    local_94 = param_1[0xe];
  }
  while (*(int *)(local_94 + 8) != 0) {
    while( true ) {
      if (((char)param_1[0x45] == '\0') && (param_2 < *(int *)(local_94 + 0x10))) goto LAB_001800ef;
      cVar4 = (**(code **)(*(int *)param_1[2] + 0xc))
                        ((int *)param_1[2],*(undefined4 *)(local_94 + 0x38));
      if (cVar4 == '\0') break;
      cVar4 = (**(code **)(*(int *)param_1[3] + 0xc))
                        ((int *)param_1[3],*(undefined4 *)(local_94 + 0x38));
      if ((cVar4 != '\0') || (local_94 = *(int *)(local_94 + 8), *(int *)(local_94 + 8) == 0))
      goto LAB_0017f9fe;
    }
    cVar4 = (**(code **)(*(int *)param_1[2] + 0x24))((int *)param_1[2]);
    if (cVar4 == '\0') {
      local_94 = *(int *)(local_94 + 8);
    }
    else {
      iVar12 = ((int (*)())FUN_00177012)(param_1,local_94);
      if (iVar12 != 0) {
        return iVar12;
      }
      cVar4 = (**(code **)(*(int *)param_1[3] + 0xc))
                        ((int *)param_1[3],*(undefined4 *)(local_94 + 0x38));
      if (cVar4 != '\0') break;
      local_94 = *(int *)(local_94 + 8);
    }
  }
LAB_0017f9fe:
  if (*(int *)(local_94 + 8) == 0) {
    cVar4 = (**(code **)(*(int *)param_1[2] + 0x24))((int *)param_1[2]);
    if (cVar4 == '\0') {
LAB_001800ef:
      local_94 = 0;
    }
    else {
      (**(code **)(*(int *)param_1[2] + 0x7c))((int *)param_1[2]);
      local_94 = 0;
    }
  }
  else {
    local_20[0] = *(int **)(*param_1 + 0xbc);
    local_28 = (int *)0x0;
    local_2c = (int *)0x2;
    local_24 = FUN_001a7bca(local_20[0],8);
    local_30 = *(int **)(*param_1 + 0xbc);
    local_38 = (uint *)0x0;
    local_3c = (int *)0x2;
    local_34 = FUN_001a7bca(local_30,8);
    local_40 = *(undefined4 *)(*param_1 + 0xbc);
    local_48 = (uint *)0x0;
    local_4c = 2;
    local_44 = FUN_001a7bca(local_40,8);
    iVar12 = *(int *)(local_94 + 0x60);
    uVar13 = *(undefined4 *)(*param_1 + 0xbc);
    puVar6 = (undefined4 *)FUN_001a7bca(uVar13,0x2c);
    puVar15 = local_48;
    *puVar6 = uVar13;
    puVar6[1] = DAT_001cc708;
    puVar6[2] = 0xffffffff;
    puVar6[3] = 0;
    puVar6[4] = DAT_001cc6f8;
    puVar6[5] = 0;
    puVar6[6] = 0x7fffffff;
    iVar18 = 0;
    puVar14 = puVar6 + 1;
    do {
      puVar14[6] = 0;
      iVar18 = iVar18 + 1;
      puVar14 = puVar14 + 1;
    } while (iVar18 != 4);
    *(undefined4 **)(local_94 + 0x60) = puVar6 + 1;
    puVar6[5] = 1;
    **(undefined4 **)(local_94 + 0x60) = *(undefined4 *)(*(int *)(local_94 + 0x38) + 0xc);
    piVar7 = (int *)(iVar12 + 0x10);
    *piVar7 = *piVar7 + -1;
    if (local_48 < local_4c) {
      iVar18 = (int)local_48 * 4;
      _memset((void *)(iVar18 + local_44),0,4);
      local_48 = (uint *)((int)puVar15 + 1);
      piVar7 = (int *)(iVar18 + local_44);
    }
    else {
      piVar7 = (int *)FUN_001a7f7c(&local_4c,local_48);
    }
    *piVar7 = local_94;
LAB_0017fb8c:
    if (local_48 != (uint *)0x0) {
      uVar21 = (int)local_48 - 1;
      if (uVar21 < local_48) {
        piVar7 = (int *)(local_44 + uVar21 * 4);
      }
      else {
        piVar7 = (int *)0x0;
      }
      iVar18 = *piVar7;
      FUN_001a7f3c(&local_4c,uVar21);
      puVar15 = *(uint **)(iVar18 + 0x40);
      uVar21 = puVar15[1];
      if (0 < (int)uVar21) {
        uVar22 = 0;
        if (*puVar15 == 0) goto LAB_0017fca4;
LAB_0017fbe3:
        uVar1 = puVar15[1];
        if (uVar1 <= uVar22) {
          _memset((void *)(puVar15[2] + uVar1 * 4),0,(uVar22 - uVar1) * 4 + 4);
          puVar15[1] = uVar22 + 1;
        }
        piVar7 = (int *)(puVar15[2] + uVar22 * 4);
        do {
          iVar5 = *piVar7;
          if (*(int *)(iVar5 + 8) == 0) {
            iVar17 = *(int *)(iVar5 + 4);
            puVar15 = *(uint **)(iVar17 + 0x44);
            uVar1 = puVar15[1];
            if (0 < (int)uVar1) {
              local_70 = 0;
              do {
                if (local_70 < *puVar15) {
                  uVar2 = puVar15[1];
                  if (uVar2 <= local_70) {
                    _memset((void *)(puVar15[2] + uVar2 * 4),0,(local_70 - uVar2) * 4 + 4);
                    puVar15[1] = local_70 + 1;
                  }
                  piVar7 = (int *)(puVar15[2] + local_70 * 4);
                }
                else {
                  piVar7 = (int *)FUN_001a7f7c(puVar15,local_70);
                }
                piVar7 = (int *)*piVar7;
                if ((((piVar7[2] == 0) && (iVar19 = *piVar7, iVar18 != iVar19)) &&
                    (piVar7[4] == *(int *)(iVar5 + 0x10))) && (piVar7[5] == *(int *)(iVar5 + 0x14)))
                {
                  if (((*(int *)(iVar19 + 0x2c) < 0) ||
                      ((*(byte *)(*(int *)(iVar19 + 0x38) + 0x14) & 0x40) == 0)) &&
                     (cVar4 = ((int (*)())FUN_001758da)(param_1,iVar19), puVar15 = local_48, cVar4 == '\0')) {
                    if (*(int *)(*piVar7 + 0x60) != *(int *)(local_94 + 0x60)) {
                      *(int *)(*piVar7 + 0x60) = *(int *)(local_94 + 0x60);
                      piVar11 = (int *)(*(int *)(local_94 + 0x60) + 0x10);
                      *piVar11 = *piVar11 + 1;
                      **(uint **)(local_94 + 0x60) =
                           **(uint **)(local_94 + 0x60) | *(uint *)(*(int *)(*piVar7 + 0x38) + 0xc);
                      piVar11 = (int *)(iVar12 + 0x10);
                      *piVar11 = *piVar11 + -1;
                      iVar19 = *piVar7;
                      if (local_48 < local_4c) {
                        iVar8 = (int)local_48 * 4;
                        _memset((void *)(iVar8 + local_44),0,4);
                        local_48 = (uint *)((int)puVar15 + 1);
                        *(int *)(iVar8 + local_44) = iVar19;
                      }
                      else {
                        piVar7 = (int *)FUN_001a7f7c(&local_4c,local_48);
                        *piVar7 = iVar19;
                      }
                    }
                  }
                  else {
                    piVar11 = local_28;
                    if ((int)local_28 < 1) {
                      iVar19 = *piVar7;
                    }
                    else {
                      piVar20 = (int *)0x0;
                      do {
                        if (piVar20 < local_2c) {
                          if (local_28 <= piVar20) {
                            _memset((void *)(local_24 + (int)local_28 * 4),0,
                                    ((int)piVar20 - (int)local_28) * 4 + 4);
                            local_28 = (int *)((int)piVar20 + 1);
                          }
                          piVar9 = (int *)(local_24 + (int)piVar20 * 4);
                        }
                        else {
                          piVar9 = (int *)FUN_001a7f7c(&local_2c,piVar20);
                        }
                        iVar8 = FUN_0010b180(*(undefined4 *)(*piVar9 + 0x38),1);
                        iVar19 = *piVar7;
                        if (iVar8 == *(int *)(iVar19 + 0x38)) {
                          if (piVar20 < local_2c) {
                            if (local_28 <= piVar20) {
                              _memset((void *)(local_24 + (int)local_28 * 4),0,
                                      ((int)piVar20 - (int)local_28) * 4 + 4);
                              local_28 = (int *)((int)piVar20 + 1);
                            }
                            piVar11 = (int *)(local_24 + (int)piVar20 * 4);
                          }
                          else {
                            piVar11 = (int *)FUN_001a7f7c(&local_2c,piVar20);
                          }
                          local_50 = *piVar11;
                          *(uint *)(*(int *)(local_50 + 0x38) + 0xc) =
                               *(uint *)(*(int *)(local_50 + 0x38) + 0xc) | piVar7[6];
                          **(uint **)(local_50 + 0x60) = **(uint **)(local_50 + 0x60) | piVar7[6];
                          goto LAB_0017febe;
                        }
                        piVar20 = (int *)((int)piVar20 + 1);
                      } while (piVar11 != piVar20);
                    }
                    iVar8 = *(int *)(iVar19 + 0x2c);
                    iVar10 = (**(code **)(*(int *)param_1[2] + 0x78))((int *)param_1[2]);
                    local_50 = ((int (*)())FUN_00176f3a)(param_1,*(undefined4 *)(*piVar7 + 0x38),DAT_001cc6f0,
                                            iVar8 + iVar10,iVar19 + 0xc);
                    if (local_28 < local_2c) {
                      iVar19 = (int)local_28 * 4;
                      *(undefined4 *)(iVar19 + local_24) = 0;
                      local_28 = (int *)((int)local_28 + 1);
                      piVar11 = (int *)(iVar19 + local_24);
                    }
                    else {
                      piVar11 = (int *)FUN_001a7f7c(&local_2c,local_28);
                    }
                    *piVar11 = local_50;
                    if (local_38 < local_3c) {
                      iVar19 = (int)local_38 * 4;
                      *(undefined4 *)(iVar19 + local_34) = 0;
                      local_38 = (uint *)((int)local_38 + 1);
                      piVar11 = (int *)(iVar19 + local_34);
                    }
                    else {
                      piVar11 = (int *)FUN_001a7f7c(&local_3c,local_38);
                    }
                    *piVar11 = *piVar7;
                    *(int *)(*(int *)(local_50 + 0x38) + 0xc) = piVar7[6];
                    FUN_0010c18e(*(undefined4 *)(local_50 + 0x38),*(undefined4 *)(iVar18 + 0x38),0,
                                 *param_1);
                    *(undefined4 *)(local_50 + 0x60) = *(undefined4 *)(local_94 + 0x60);
                    piVar11 = (int *)(*(int *)(local_94 + 0x60) + 0x10);
                    *piVar11 = *piVar11 + 1;
                    **(uint **)(local_94 + 0x60) = **(uint **)(local_94 + 0x60) | piVar7[6];
LAB_0017febe:
                    if (((0 < piVar7[4]) && (piVar7[5] == 0)) &&
                       (iVar19 = FUN_0010b180(*(undefined4 *)(iVar17 + 0x38),piVar7[4]),
                       iVar19 == *(int *)(*piVar7 + 0x38))) {
                      FUN_0010ba02(*(undefined4 *)(iVar17 + 0x38),piVar7[4],
                                   *(undefined4 *)(local_50 + 0x38),0,*param_1);
                    }
                    iVar8 = 0;
                    piVar11 = piVar7;
                    iVar19 = local_50;
                    do {
                      if ((char)piVar11[6] != '\0') {
                        piVar20 = (int *)(*piVar7 + 0x48 + iVar8 * 4);
                        *piVar20 = *piVar20 + -1;
                        *(int *)(iVar19 + 0x48) = *(int *)(iVar19 + 0x48) + 1;
                      }
                      iVar8 = iVar8 + 1;
                      piVar11 = (int *)((int)piVar11 + 1);
                      iVar19 = iVar19 + 4;
                    } while (iVar8 != 4);
                    FUN_001a805e(*(undefined4 *)(*piVar7 + 0x40),piVar7);
                    if (-1 < *(int *)(*piVar7 + 0x2c)) {
                      *(int *)(iVar17 + 0x34) = *(int *)(iVar17 + 0x34) + 1;
                    }
                    *piVar7 = local_50;
                    puVar15 = *(uint **)(local_50 + 0x40);
                    uVar2 = puVar15[1];
                    if (uVar2 < *puVar15) {
                      _memset((void *)(uVar2 * 4 + puVar15[2]),0,4);
                      puVar15[1] = uVar2 + 1;
                      *(int **)(uVar2 * 4 + puVar15[2]) = piVar7;
                    }
                    else {
                      piVar11 = (int *)FUN_001a7f7c(puVar15,uVar2);
                      *piVar11 = (int)piVar7;
                    }
                  }
                }
                local_70 = local_70 + 1;
                if (uVar1 == local_70) break;
                puVar15 = *(uint **)(iVar17 + 0x44);
              } while( true );
            }
          }
          uVar22 = uVar22 + 1;
          if (uVar21 == uVar22) break;
          puVar15 = *(uint **)(iVar18 + 0x40);
          if (uVar22 < *puVar15) goto LAB_0017fbe3;
LAB_0017fca4:
          piVar7 = (int *)FUN_001a7f7c(puVar15,uVar22);
        } while( true );
      }
      goto LAB_0017fb8c;
    }
    if (0 < (int)local_28) {
      local_5c = (int *)0x0;
      local_58 = (int *)0x1;
      local_54 = 0;
      piVar7 = local_28;
      do {
        if (local_5c < local_2c) {
          if (local_28 <= local_5c) {
            _memset((void *)(local_24 + (int)local_28 * 4),0,((int)local_5c - (int)local_28) * 4 + 4
                   );
            local_28 = local_58;
          }
          piVar11 = (int *)(local_54 + local_24);
        }
        else {
          piVar11 = (int *)FUN_001a7f7c(&local_2c,local_5c);
        }
        iVar12 = *piVar11;
        ((int (*)())FUN_001826a6)(param_1[2],iVar12);
        uVar13 = FUN_000f5a44(DAT_001cc6f0,*(undefined4 *)(*(int *)(iVar12 + 0x38) + 0xc));
        *(undefined4 *)(*(int *)(iVar12 + 0x38) + 0x9c) = uVar13;
        uVar13 = FUN_000f5b96(DAT_001cc704,*(undefined4 *)(*(int *)(iVar12 + 0x38) + 0xc));
        iVar18 = FUN_0010b0f4(*(undefined4 *)(iVar12 + 0x38),1);
        *(undefined4 *)(iVar18 + 0x10) = uVar13;
        uVar13 = (**(code **)(*(int *)param_1[2] + 0x4c))
                           ((int *)param_1[2],*(undefined4 *)(iVar12 + 0x38));
        *(undefined4 *)(iVar12 + 0x58) = uVar13;
        uVar13 = *(undefined4 *)(*(int *)(iVar12 + 0x38) + 0xc);
        if (local_5c < local_3c) {
          if (local_38 <= local_5c) {
            _memset((void *)(local_34 + (int)local_38 * 4),0,((int)local_5c - (int)local_38) * 4 + 4
                   );
            local_38 = (uint *)local_58;
          }
          puVar14 = (undefined4 *)(local_54 + local_34);
        }
        else {
          puVar14 = (undefined4 *)FUN_001a7f7c(&local_3c,local_5c);
        }
        ((int (*)())FUN_00174cc0)(param_1,*puVar14,iVar12,1,0,uVar13);
        ((int (*)())FUN_00182640)(param_1[2],iVar12);
        if (local_5c < local_3c) {
          if (local_38 <= local_5c) {
            _memset((void *)(local_34 + (int)local_38 * 4),0,((int)local_5c - (int)local_38) * 4 + 4
                   );
            local_38 = (uint *)local_58;
          }
          piVar11 = (int *)(local_54 + local_34);
        }
        else {
          piVar11 = (int *)FUN_001a7f7c(&local_3c,local_5c);
        }
        if (-1 < *(int *)(*piVar11 + 0x2c)) {
          *(int *)(iVar12 + 0x34) = *(int *)(iVar12 + 0x34) + -1;
          ((int (*)())FUN_0017f346)(param_1,iVar12);
        }
        local_5c = (int *)((int)local_5c + 1);
        local_58 = (int *)((int)local_58 + 1);
        local_54 = local_54 + 4;
      } while (piVar7 != local_5c);
    }
    FUN_001a7d72(local_94);
    FUN_001a7aba(local_40,local_44);
    FUN_001a7aba(local_30,local_34);
    FUN_001a7aba(local_20[0],local_24);
  }
  return local_94;
}

/* FUN_00180f62 @ 0x180f62 (500 bytes) */
int FUN_00180f62(param_1)
  int param_1;
{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int local_14;
  int local_10;
  
  if (((*(char *)(param_1 + 0x114) == '\0') && (cVar2 = FUN_001a7c84(param_1 + 0x48), cVar2 == '\0')
      ) && (*(char *)(param_1 + 0x20) != '\0')) {
    iVar4 = *(int *)(*(int *)(param_1 + 0x50) + 0x10);
    iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x84))(*(int **)(param_1 + 8));
    iVar4 = iVar4 + iVar3;
  }
  else {
    iVar4 = 0x7fffffff;
  }
  while( true ) {
    local_14 = param_1 + 0x48;
    cVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x20))(*(int **)(param_1 + 8));
    if ((cVar2 != '\0') || (iVar3 = ((int (*)())FUN_001804f8)(param_1,iVar4), iVar3 == 0)) break;
    ((int (*)())FUN_0017d6d2)(param_1,iVar3);
  }
  local_10 = 0;
LAB_00180fb9:
  do {
    iVar4 = param_1 + 0xa8 + local_10 * 0x18;
    cVar2 = FUN_001a7c84(iVar4);
    while (cVar2 == '\0') {
      uVar1 = *(undefined4 *)(iVar4 + 8);
      FUN_001a7d72(uVar1);
      cVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x20))(*(int **)(param_1 + 8));
      if ((cVar2 != '\0') || (iVar4 = ((int (*)())FUN_00178234)(param_1,uVar1), iVar4 == 0)) {
        FUN_001a7cd6(param_1 + 0x78,uVar1);
        goto LAB_00180fb9;
      }
      ((int (*)())FUN_0017d6d2)(param_1,iVar4);
      iVar4 = param_1 + 0xa8 + local_10 * 0x18;
      cVar2 = FUN_001a7c84(iVar4);
    }
    local_10 = local_10 + 1;
    if (local_10 == 3) {
      cVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x20))(*(int **)(param_1 + 8));
      while (((cVar2 == '\0' && (*(char *)(param_1 + 0x114) == '\0')) &&
             (iVar4 = ((int (*)())FUN_0017514e)(param_1), iVar4 != 0))) {
        ((int (*)())FUN_0017d6d2)(param_1,iVar4);
        cVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x20))(*(int **)(param_1 + 8));
      }
      iVar4 = ((int (*)())FUN_0017c962)(param_1);
      if (iVar4 == 0) {
        (**(code **)(**(int **)(param_1 + 8) + 0x7c))(*(int **)(param_1 + 8));
      }
      ((int (*)())FUN_0017ed44)(param_1);
      cVar2 = FUN_001a7c84(local_14);
      if ((cVar2 != '\0') && (cVar2 = FUN_001a7c84(param_1 + 0x30), cVar2 != '\0')) {
        cVar2 = FUN_001a7c84(param_1 + 0x60);
        if (cVar2 != '\0') {
          return 1;
        }
        iVar3 = ((int (*)())FUN_0017c962)(param_1);
        if (iVar3 == 0) {
          *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) | 0x80;
        }
        ((int (*)())FUN_0017ed44)(param_1);
        return 0;
      }
      return 0;
    }
  } while( true );
}

/* FUN_00181156 @ 0x181156 (518 bytes) */
int FUN_00181156(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint *puVar7;
  uint *puVar8;
  uint local_20;
  uint local_18;
  int local_14;
  
  puVar7 = *(uint **)(param_2 + 0x40);
  uVar1 = puVar7[1];
  if (0 < (int)uVar1) {
    local_20 = 0;
    local_18 = 1;
    local_14 = 0;
    while( true ) {
      if (local_20 < *puVar7) {
        uVar2 = puVar7[1];
        puVar8 = puVar7;
        if (uVar2 <= local_20) {
          _memset((void *)(puVar7[2] + uVar2 * 4),0,(local_20 - uVar2) * 4 + 4);
          puVar7[1] = local_18;
          puVar8 = *(uint **)(param_2 + 0x40);
        }
        piVar6 = (int *)(local_14 + puVar7[2]);
      }
      else {
        piVar6 = (int *)FUN_001a7f7c(puVar7,local_20);
        puVar8 = *(uint **)(param_2 + 0x40);
      }
      iVar3 = *(int *)(*piVar6 + 4);
      *(int *)(iVar3 + 0x34) = *(int *)(iVar3 + 0x34) + -1;
      iVar4 = *(int *)(iVar3 + 0x30);
      iVar5 = *(int *)(param_2 + 0x2c);
      if (local_20 < *puVar8) {
        uVar2 = puVar8[1];
        if (uVar2 <= local_20) {
          _memset((void *)(puVar8[2] + uVar2 * 4),0,(local_20 - uVar2) * 4 + 4);
          puVar8[1] = local_18;
        }
        piVar6 = (int *)(local_14 + puVar8[2]);
      }
      else {
        piVar6 = (int *)FUN_001a7f7c(puVar8,local_20);
      }
      if (iVar4 < iVar5 + *(int *)(*piVar6 + 0xc)) {
        iVar4 = *(int *)(param_2 + 0x2c);
        puVar7 = *(uint **)(param_2 + 0x40);
        if (local_20 < *puVar7) {
          uVar2 = puVar7[1];
          if (uVar2 <= local_20) {
            _memset((void *)(puVar7[2] + uVar2 * 4),0,(local_20 - uVar2) * 4 + 4);
            puVar7[1] = local_18;
          }
          piVar6 = (int *)(local_14 + puVar7[2]);
        }
        else {
          piVar6 = (int *)FUN_001a7f7c(puVar7,local_20);
        }
        *(int *)(iVar3 + 0x30) = *(int *)(*piVar6 + 0xc) + iVar4;
        iVar4 = *(int *)(iVar3 + 0x34);
      }
      else {
        *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(iVar3 + 0x30);
        iVar4 = *(int *)(iVar3 + 0x34);
      }
      if (iVar4 == 0) {
        ((int (*)())FUN_0017f346)(param_1,iVar3);
      }
      if (uVar1 == local_20 + 1) break;
      local_14 = local_14 + 4;
      local_18 = local_18 + 1;
      local_20 = local_20 + 1;
      puVar7 = *(uint **)(param_2 + 0x40);
    }
  }
  return;
}

/* FUN_0018135c @ 0x18135c (140 bytes) */
int FUN_0018135c(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  undefined4 uVar2;
  char cVar3;
  
  uVar2 = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  *(undefined4 *)(param_2 + 0x2c) = uVar2;
  ((int (*)())FUN_001826a6)(*(undefined4 *)(param_1 + 8),param_2);
  ((int (*)())FUN_0017d098)(param_1,param_2);
  ((int (*)())FUN_00181156)(param_1,param_2);
  cVar3 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))
                    (*(int **)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38));
  if (((cVar3 != '\0') ||
      (cVar3 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))
                         (*(int **)(param_1 + 0xc),*(undefined4 *)(param_2 + 0x38)), cVar3 != '\0'))
     && (*(int *)(param_1 + 0x124) <= *(int *)(param_2 + 0xc))) {
    *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + 1;
  }
  puVar1 = (uint *)(*(int *)(param_2 + 0x38) + 0x14);
  *puVar1 = *puVar1 & 0xfffffffe;
  return;
}

/* FUN_001813e8 @ 0x1813e8 (2049 bytes) */
int FUN_001813e8(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  char cVar3;
  uint *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  int *piVar13;
  uint uVar14;
  int *piVar15;
  int *local_70;
  uint local_48;
  int *local_38;
  undefined1 local_2c [8];
  int local_24;
  int local_14;
  int local_10;
  
  ((int (*)())FUN_0017a024)(param_1,param_2);
  ((int (*)())FUN_0017bfe0)(param_1);
  ((int (*)())FUN_001762be)(param_1);
  puVar4 = (uint *)param_1[0x4b];
  if (*puVar4 != 0) {
    uVar10 = 0;
    uVar14 = *puVar4;
    do {
      puVar4[2] = 0;
      uVar10 = uVar10 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar10 < uVar14);
  }
  if (0 < param_1[0x50]) {
    uVar14 = 0;
    do {
      uVar10 = uVar14 >> 5;
      bVar7 = (byte)uVar14 & 0x1f;
      if (((*(uint *)(*(int *)(param_1[1] + 0x424) + 8 + uVar10 * 4) >> bVar7 & 1) != 0) &&
         ((*(uint *)(*(int *)(param_2 + 0x100) + 8 + uVar10 * 4) >> bVar7 & 1) == 0)) {
        puVar4 = (uint *)(param_1[0x4b] + 8 + uVar10 * 4);
        *puVar4 = *puVar4 | 1 << bVar7;
      }
      iVar8 = 4;
      piVar5 = param_1;
      do {
        *(undefined4 *)(piVar5[0x4c] + uVar14 * 4) = 0;
        piVar5 = piVar5 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      uVar14 = uVar14 + 1;
    } while ((int)uVar14 < param_1[0x50]);
  }
  if (param_1[0x57] != 0) {
    piVar5 = param_1;
    do {
      if (0 < param_1[0x50]) {
        iVar8 = 0;
        do {
          *(undefined4 *)(piVar5[0x53] + iVar8 * 4) = 0;
          iVar8 = iVar8 + 1;
        } while (iVar8 < param_1[0x50]);
      }
      piVar15 = *(int **)(*param_1 + 0x54);
      iVar8 = (**(code **)(*piVar15 + 0x13c))(piVar15,*param_1);
      if (0 < iVar8) {
        iVar11 = 0;
        do {
          *(undefined4 *)(piVar5[0x57] + iVar11 * 4) = 0;
          iVar11 = iVar11 + 1;
        } while (iVar8 != iVar11);
      }
      piVar5 = piVar5 + 1;
    } while (param_1 + 4 != piVar5);
  }
  puVar4 = (uint *)param_1[5];
  if (puVar4[1] != 0) {
    local_48 = 0;
    do {
      if (local_48 < *puVar4) {
        uVar14 = puVar4[1];
        if (uVar14 <= local_48) {
          _memset((void *)(puVar4[2] + uVar14 * 4),0,(local_48 - uVar14) * 4 + 4);
          puVar4[1] = local_48 + 1;
        }
        iVar8 = *(int *)(puVar4[2] + local_48 * 4);
        piVar5 = *(int **)(iVar8 + 0x38);
        iVar11 = piVar5[0x25];
        iVar9 = piVar5[0x20];
      }
      else {
        piVar5 = (int *)FUN_001a7f7c(puVar4,local_48);
        iVar8 = *piVar5;
        piVar5 = *(int **)(iVar8 + 0x38);
        iVar11 = piVar5[0x25];
        iVar9 = piVar5[0x20];
      }
      if ((((iVar9 != 0) && (cVar3 = FUN_0012dfd8(piVar5[0x26]), cVar3 != '\0')) &&
          ((*(byte *)(piVar5 + 5) & 2) == 0)) &&
         ((cVar3 = (**(code **)(*piVar5 + 0x50))(piVar5), cVar3 == '\0' &&
          ((*(byte *)(piVar5 + 5) & 0x40) != 0)))) {
        local_10 = piVar5[3];
        if (*(int *)(iVar8 + 0x60) != 0) {
          *(int *)(*(int *)(iVar8 + 0x60) + 8) = iVar8;
          *(int *)(*(int *)(iVar8 + 0x60) + 4) = iVar11;
          local_10 = **(int **)(iVar8 + 0x60);
        }
        local_70 = param_1;
        iVar9 = 0;
        do {
          if (*(char *)((int)&local_10 + iVar9) != '\0') {
            *(int *)(local_70[0x4c] + iVar11 * 4) = iVar8;
            if (local_70[0x53] != 0) {
              *(undefined4 *)(local_70[0x53] + iVar11 * 4) = 0x7fffffff;
            }
            if (*(int *)(iVar8 + 0x60) != 0) {
              *(int *)(*(int *)(iVar8 + 0x60) + 0x18 + iVar9 * 4) = iVar8;
              *(undefined4 *)(*(int *)(iVar8 + 0x60) + 0x14) = 0;
            }
          }
          iVar9 = iVar9 + 1;
          local_70 = local_70 + 1;
        } while (iVar9 != 4);
        if (piVar5[0x26] == 1) {
          piVar5 = *(int **)(*param_1 + 0x54);
          iVar9 = (**(code **)(*piVar5 + 0x138))(piVar5,*param_1);
          iVar8 = param_1[0x66];
          if (param_1[0x66] < iVar11 - iVar9) {
            iVar8 = iVar11 - iVar9;
          }
          param_1[0x66] = iVar8;
        }
        else {
          iVar8 = param_1[0x65];
          if (param_1[0x65] < iVar11) {
            iVar8 = iVar11;
          }
          param_1[0x65] = iVar8;
          iVar8 = param_1[0x67];
          if (param_1[0x67] < iVar11) {
            iVar8 = iVar11;
          }
          param_1[0x67] = iVar8;
        }
      }
      local_48 = local_48 + 1;
      puVar4 = (uint *)param_1[5];
    } while (local_48 < puVar4[1]);
  }
  iVar8 = 0;
  piVar5 = param_1;
  do {
    piVar5[0x5b] = 0;
    iVar8 = iVar8 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar8 != 4);
  iVar8 = 0;
  piVar5 = param_1;
  do {
    piVar5[0x61] = 0;
    iVar8 = iVar8 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar8 != 2);
  cVar3 = FUN_000e1402(*param_1,0x47);
  if ((cVar3 != '\0') && (cVar3 = FUN_000e1402(*param_1,0x24), cVar3 != '\0')) {
    ((int (*)())FUN_00179680)(param_1);
  }
  (**(code **)(*(int *)param_1[2] + 8))((int *)param_1[2]);
  (**(code **)(*(int *)param_1[3] + 8))((int *)param_1[3]);
  param_1[10] = 1;
  *(undefined1 *)(param_1 + 0x45) = 1;
  param_1[0x46] = -1;
  param_1[0x47] = -1;
  param_1[0x48] = 0;
  param_1[0x49] = -1;
  param_1[0x4a] = 0;
  FUN_001a7e06(local_2c);
  puVar4 = (uint *)param_1[6];
  uVar14 = puVar4[1];
  if (0 < (int)uVar14) {
    uVar10 = 0;
    while( true ) {
      if (uVar10 < *puVar4) {
        uVar1 = puVar4[1];
        if (uVar1 <= uVar10) {
          _memset((void *)(puVar4[2] + uVar1 * 4),0,(uVar10 - uVar1) * 4 + 4);
          puVar4[1] = uVar10 + 1;
        }
        iVar8 = *(int *)(puVar4[2] + uVar10 * 4);
        iVar11 = *(int *)(iVar8 + 0x34);
      }
      else {
        piVar5 = (int *)FUN_001a7f7c(puVar4,uVar10);
        iVar8 = *piVar5;
        iVar11 = *(int *)(iVar8 + 0x34);
      }
      if (iVar11 == 0) {
        FUN_001a7cd6(local_2c,iVar8);
      }
      if (uVar14 == uVar10 + 1) break;
      uVar10 = uVar10 + 1;
      puVar4 = (uint *)param_1[6];
    }
  }
  iVar11 = *(int *)(local_24 + 8);
  iVar8 = local_24;
  while (iVar9 = iVar11, iVar9 != 0) {
    FUN_001a7d72(iVar8);
    ((int (*)())FUN_0017f346)(param_1,iVar8);
    cVar3 = (**(code **)(*(int *)param_1[3] + 0x20))
                      ((int *)param_1[3],*(undefined4 *)(iVar8 + 0x38));
    if ((cVar3 == '\0') &&
       (cVar3 = (**(code **)(*(int *)param_1[3] + 0x24))
                          ((int *)param_1[3],*(undefined4 *)(iVar8 + 0x38)), cVar3 == '\0')) {
      iVar11 = *(int *)(iVar8 + 0xc);
      if (*(int *)(iVar8 + 0xc) < param_1[0x46]) {
        iVar11 = param_1[0x46];
      }
      param_1[0x46] = iVar11;
      iVar11 = *(int *)(iVar9 + 8);
      iVar8 = iVar9;
    }
    else {
      iVar11 = *(int *)(iVar8 + 0xc);
      if (*(int *)(iVar8 + 0xc) < param_1[0x47]) {
        iVar11 = param_1[0x47];
      }
      param_1[0x47] = iVar11;
      iVar11 = *(int *)(iVar9 + 8);
      iVar8 = iVar9;
    }
  }
  *(undefined1 *)(param_1 + 0x45) = 0;
  piVar5 = param_1 + 0xc;
  cVar3 = FUN_001a7c84(piVar5);
  if ((cVar3 == '\0') && (param_1[0x46] + -1 <= param_1[0x47])) {
    *(undefined1 *)(param_1 + 0x45) = 1;
    param_1[0x49] = param_1[0x47];
  }
  piVar15 = (int *)(*(int **)(param_1[4] + 0x98))[2];
  if (piVar15 != (int *)0x0) {
    local_38 = (int *)0x0;
    piVar13 = *(int **)(param_1[4] + 0x98);
    do {
      cVar3 = (**(code **)(*piVar13 + 0x34))(piVar13);
      if ((cVar3 == '\0') && (cVar3 = (**(code **)(*piVar13 + 0x38))(piVar13), cVar3 == '\0')) {
        cVar3 = ((int (*)())FUN_0017422c)();
        if (cVar3 == '\0') {
          FUN_001a7d72(piVar13);
          piVar13[0x56] = 0;
          goto LAB_001818ca;
        }
        piVar13[5] = piVar13[5] | 4;
        piVar2 = (int *)piVar15[2];
        local_38 = piVar13;
      }
      else {
        piVar13[5] = piVar13[5] & 0xfffffffb;
LAB_001818ca:
        piVar2 = (int *)piVar15[2];
      }
      piVar13 = piVar15;
      piVar15 = piVar2;
    } while (piVar2 != (int *)0x0);
    if (local_38 != (int *)0x0) {
      local_38[5] = local_38[5] & 0xfffffffb;
    }
  }
  piVar15 = param_1 + 0x12;
  cVar3 = FUN_001a7c84(piVar15);
  if ((((cVar3 == '\0') || (cVar3 = FUN_001a7c84(piVar5), cVar3 == '\0')) ||
      (cVar3 = FUN_001a7c84(param_1 + 0x18), cVar3 == '\0')) ||
     (cVar3 = FUN_001a7c84(param_1 + 0x3d), cVar3 == '\0')) {
    iVar8 = ((int (*)())FUN_0017c962)(param_1);
    if ((iVar8 == 0) && (cVar3 = FUN_001a7c84(param_1 + 0x24), cVar3 != '\0')) {
      cVar3 = FUN_001a7c84(param_1 + 0x3d);
      if (((cVar3 == '\0') && (cVar3 = FUN_001a7c84(piVar15), cVar3 != '\0')) &&
         ((cVar3 = FUN_001a7c84(piVar5), cVar3 != '\0' &&
          (iVar8 = FUN_001a7d8a(param_1 + 0x3d), iVar8 == param_1[0x3c])))) {
        iVar8 = param_1[0x3f];
        for (iVar11 = *(int *)(param_1[0x3f] + 8); iVar11 != 0; iVar11 = *(int *)(iVar11 + 8)) {
          FUN_001a7d72(iVar8);
          *(undefined1 *)(iVar8 + 0x65) = 0;
          FUN_001a7cd6(piVar15,iVar8);
          iVar8 = iVar11;
        }
      }
    }
    else {
      ((int (*)())FUN_0017ed44)(param_1);
    }
    do {
      cVar3 = ((int (*)())FUN_00180f62)(param_1);
    } while (cVar3 == '\0');
    ((int (*)())FUN_0017c962)(param_1);
    puVar6 = (undefined4 *)param_1[0xb];
    iVar8 = 0;
    puVar12 = puVar6;
    do {
      *puVar12 = 0;
      iVar8 = iVar8 + 1;
      puVar12 = puVar12 + 1;
    } while (iVar8 != 5);
  }
  else {
    ((int (*)())FUN_0017c962)(param_1);
    puVar6 = (undefined4 *)param_1[0xb];
    iVar8 = 0;
    puVar12 = puVar6;
    do {
      *puVar12 = 0;
      iVar8 = iVar8 + 1;
      puVar12 = puVar12 + 1;
    } while (iVar8 != 5);
  }
  FUN_001a7d22(puVar6 + 5);
  cVar3 = (**(code **)(*(int *)param_1[3] + 0x1c))((int *)param_1[3]);
  if (cVar3 != '\0') {
    local_14 = 0;
    uVar14 = 1;
    iVar11 = 0;
    iVar8 = *(int *)(param_2 + 0xd0);
    if (*(int *)(iVar8 + 4) != 0) {
      do {
        local_14 = *(int *)(*(int *)(iVar8 + 8) + iVar11);
        if (local_14 != 0) {
          *(undefined1 *)(local_14 + 0xdc) = 1;
        }
        uVar14 = uVar14 + 1;
        iVar11 = iVar11 + 4;
      } while (uVar14 <= *(uint *)(iVar8 + 4));
    }
  }
  ((int (*)())FUN_00175e8c)(param_1);
  return;
}

/* FUN_00181bf2 @ 0x181bf2 (1984 bytes) */
int FUN_00181bf2(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint *puVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  int iVar14;
  int *piVar15;
  int *local_20;
  
  param_1[1] = param_2;
  iVar3 = *(int *)(param_2 + 8);
  *param_1 = iVar3;
  iVar3 = FUN_001133e6(iVar3);
  param_1[2] = iVar3;
  iVar3 = FUN_001133f4(*param_1);
  param_1[3] = iVar3;
  uVar5 = *(undefined4 *)(*param_1 + 0xbc);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
  *puVar4 = uVar5;
  puVar4[4] = uVar5;
  puVar4[2] = 0;
  puVar4[1] = 2;
  uVar5 = FUN_001a7bca(uVar5,8);
  puVar4[3] = uVar5;
  param_1[5] = (int)(puVar4 + 1);
  uVar5 = *(undefined4 *)(*param_1 + 0xbc);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
  *puVar4 = uVar5;
  puVar4[4] = uVar5;
  puVar4[2] = 0;
  puVar4[1] = 2;
  uVar5 = FUN_001a7bca(uVar5,8);
  puVar4[3] = uVar5;
  param_1[6] = (int)(puVar4 + 1);
  uVar5 = *(undefined4 *)(*param_1 + 0xbc);
  puVar6 = (undefined4 *)FUN_001a7bca(uVar5,0x30);
  *puVar6 = uVar5;
  FUN_001a7e06(puVar6 + 6);
  iVar3 = 0;
  puVar4 = puVar6 + 1;
  do {
    *puVar4 = 0;
    iVar3 = iVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar3 != 5);
  param_1[0xb] = (int)(puVar6 + 1);
  piVar13 = *(int **)(*param_1 + 0x54);
  iVar3 = (**(code **)(*piVar13 + 0x138))(piVar13,*param_1);
  piVar13 = *(int **)(*param_1 + 0x54);
  iVar7 = (**(code **)(*piVar13 + 0x140))(piVar13,*param_1);
  iVar3 = iVar3 + iVar7;
  param_1[0x50] = iVar3;
  uVar5 = *(undefined4 *)(*param_1 + 0xbc);
  uVar12 = iVar3 + 0x1fU >> 5;
  puVar4 = (undefined4 *)FUN_001a7bca(uVar5,uVar12 * 4 + 0xc);
  puVar1 = puVar4 + 1;
  *puVar4 = uVar5;
  puVar4[2] = iVar3;
  puVar4[1] = uVar12;
  if (uVar12 != 0) {
    uVar11 = 0;
    uVar12 = *puVar1;
    puVar9 = puVar1;
    do {
      puVar9[2] = 0;
      uVar11 = uVar11 + 1;
      puVar9 = puVar9 + 1;
    } while (uVar11 < uVar12);
  }
  param_1[0x4b] = (int)puVar1;
  piVar13 = *(int **)(*param_1 + 0x54);
  iVar3 = (**(code **)(*piVar13 + 0x13c))(piVar13,*param_1);
  local_20 = param_1;
  do {
    iVar7 = FUN_001a7bca(*(undefined4 *)(*param_1 + 0xbc),param_1[0x50] << 2);
    local_20[0x4c] = iVar7;
    if (iVar3 < 1) {
      local_20[0x53] = 0;
      local_20[0x57] = 0;
    }
    else {
      iVar7 = FUN_001a7bca(*(undefined4 *)(*param_1 + 0xbc),param_1[0x50] << 2);
      local_20[0x53] = iVar7;
      iVar7 = FUN_001a7bca(*(undefined4 *)(*param_1 + 0xbc),iVar3 << 2);
      local_20[0x57] = iVar7;
    }
    local_20 = local_20 + 1;
  } while (local_20 != param_1 + 4);
  param_1[0x51] = param_1[0x50];
  param_1[0x52] = param_1[0x50];
  param_1[99] = 0;
  param_1[100] = 0;
  param_1[0x65] = -1;
  param_1[0x66] = -1;
  param_1[0x67] = -1;
  param_1[0x68] = -1;
  param_1[0x69] = 0;
  param_1[0x5f] = 0;
  param_1[0x60] = -1;
  iVar7 = FUN_000e97aa(*(undefined4 *)(param_1[1] + 0x394));
  if (iVar7 == 1) {
    iVar8 = param_1[1];
    iVar7 = *(int *)(*(int *)(iVar8 + 0x394) + 0xd0);
    if (*(int *)(iVar7 + 4) == 0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = *(undefined4 **)(iVar7 + 8);
    }
    uVar5 = *puVar4;
    piVar13 = *(int **)(*(int *)(iVar8 + 0x394) + 0xa0);
    piVar15 = (int *)piVar13[1];
    if (piVar15 != (int *)0x0) {
      do {
        cVar2 = (**(code **)(*piVar13 + 0x34))(piVar13);
        if ((cVar2 == '\0') && (cVar2 = (**(code **)(*piVar13 + 0x38))(piVar13), cVar2 == '\0')) {
          FUN_001a7d72(piVar13);
          FUN_000e9540(uVar5,piVar13);
          piVar10 = (int *)piVar15[1];
        }
        else {
          piVar10 = (int *)piVar15[1];
        }
        piVar13 = piVar15;
        piVar15 = piVar10;
      } while (piVar10 != (int *)0x0);
      iVar8 = param_1[1];
    }
    *(undefined4 *)(iVar8 + 0x398) = uVar5;
  }
  iVar7 = FUN_000e97bc(*(undefined4 *)(param_1[1] + 0x39c));
  if (iVar7 == 1) {
    iVar7 = param_1[1];
    iVar8 = *(int *)(*(int *)(iVar7 + 0x39c) + 0xd4);
    if (*(int *)(iVar8 + 4) == 0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = *(undefined4 **)(iVar8 + 8);
    }
    uVar5 = *puVar4;
    piVar13 = *(int **)(*(int *)(iVar7 + 0x39c) + 0x98);
    piVar15 = (int *)piVar13[2];
    if (piVar15 != (int *)0x0) {
      do {
        cVar2 = (**(code **)(*piVar13 + 0x34))(piVar13);
        if ((cVar2 == '\0') && (cVar2 = (**(code **)(*piVar13 + 0x38))(piVar13), cVar2 == '\0')) {
          cVar2 = (**(code **)(*piVar13 + 0x68))(piVar13);
          if (cVar2 != '\0') {
            piVar10 = (int *)FUN_0010b180(piVar13,1);
            cVar2 = (**(code **)(*piVar10 + 0x50))(piVar10);
            if (cVar2 != '\0') goto LAB_001822a5;
          }
          FUN_001a7d72(piVar13);
          FUN_000e9512(uVar5,piVar13);
          piVar10 = (int *)piVar15[2];
        }
        else {
LAB_001822a5:
          piVar10 = (int *)piVar15[2];
        }
        piVar13 = piVar15;
        piVar15 = piVar10;
      } while (piVar10 != (int *)0x0);
      iVar7 = param_1[1];
    }
  }
  else {
    iVar7 = param_1[1];
  }
  (**(code **)(*(int *)param_1[2] + 0x70))((int *)param_1[2],iVar7);
  FUN_000f0346(param_1[1],"sched_preprocess");
  cVar2 = FUN_000e1402(*param_1,0x43);
  if (cVar2 != '\0') {
    FUN_001972e2(param_1,param_2);
  }
  ((int (*)())FUN_00179928)(param_1);
  ((int (*)())FUN_0017427e)(param_1);
  iVar8 = *(int *)(param_1[1] + 0x378);
  iVar7 = *(int *)(iVar8 + 8);
  while (iVar7 != 0) {
    while (iVar7 = FUN_001a7d8a(iVar8 + 0x90), iVar7 < 3) {
      iVar8 = *(int *)(iVar8 + 8);
      if (*(int *)(iVar8 + 8) == 0) goto LAB_00181fb4;
    }
    ((int (*)())FUN_001813e8)(param_1,iVar8);
    param_1[99] = param_1[99] + param_1[10];
    *(undefined4 *)(iVar8 + 0x110) = *(undefined4 *)(param_1[1] + 0x468);
    iVar8 = *(int *)(iVar8 + 8);
    iVar7 = *(int *)(iVar8 + 8);
  }
LAB_00181fb4:
  if (0 < iVar3) {
    param_1[0x65] = param_1[0x67];
  }
  if (-1 < param_1[0x65]) {
    iVar7 = 0;
    do {
      FUN_00137b7e(param_1[1],iVar7);
      iVar7 = iVar7 + 1;
    } while (iVar7 <= param_1[0x65]);
  }
  piVar13 = *(int **)(*param_1 + 0x54);
  iVar7 = (**(code **)(*piVar13 + 0x138))(piVar13,*param_1);
  if (-1 < param_1[0x66]) {
    iVar8 = 0;
    do {
      FUN_00137b7e(param_1[1],iVar7 + iVar8);
      iVar8 = iVar8 + 1;
    } while (iVar8 <= param_1[0x66]);
  }
  piVar13 = *(int **)(*param_1 + 0x54);
  iVar8 = (**(code **)(*piVar13 + 0x140))(piVar13,*param_1);
  if (-1 < param_1[0x68]) {
    iVar14 = 0;
    do {
      FUN_00137b7e(param_1[1],iVar7 + iVar8 + iVar14);
      iVar14 = iVar14 + 1;
    } while (iVar14 <= param_1[0x68]);
  }
  FUN_000e1c3e(*param_1,"Scheduler : Total cycles %d\n",param_1[99]);
  FUN_000e1c3e(*param_1,"Scheduler : Total dot-product transformed %d\n",param_1[0x69]);
  FUN_000f0346(param_1[1],"schedule_inst");
  FUN_0013fa08(param_2);
  iVar7 = param_1[0x4b];
  piVar13 = param_1;
  if (iVar7 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar7 + -4),iVar7 + -4);
  }
  do {
    if (0 < iVar3) {
      FUN_001a7aba(*(undefined4 *)(*param_1 + 0xbc),piVar13[0x53]);
      FUN_001a7aba(*(undefined4 *)(*param_1 + 0xbc),piVar13[0x57]);
    }
    FUN_001a7aba(*(undefined4 *)(*param_1 + 0xbc),piVar13[0x4c]);
    piVar13 = piVar13 + 1;
  } while (local_20 != piVar13);
  iVar3 = param_1[0xb];
  if (iVar3 != 0) {
    *(undefined **)(iVar3 + 0x20) = PTR_DAT_00213441 + 8;
    *(undefined **)(iVar3 + 0x14) = PTR_DAT_00213441 + 8;
    FUN_001a7aba(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
  }
  iVar3 = param_1[6];
  if (iVar3 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
  }
  iVar3 = param_1[5];
  if (iVar3 == 0) {
    return;
  }
  FUN_001a7aba(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
  FUN_001a7aba();
  return;
}

/* FUN_0018240c @ 0x18240c (288 bytes) */
int FUN_0018240c(param_1)
  int param_1;
{
  char cVar1;
  int *piVar2;
  int iVar4;
  undefined1 local_1c4 [48];
  undefined1 local_194 [24];
  undefined1 local_17c [24];
  undefined1 local_164 [24];
  undefined1 local_14c [24];
  undefined1 local_134 [24];
  int local_11c [18];
  int local_d4;
  undefined1 local_d0 [192];
  int *piVar3;
  
  FUN_001a7e06(local_194);
  FUN_001a7e06(local_17c);
  FUN_001a7e06(local_164);
  FUN_001a7e06(local_14c);
  FUN_001a7e06(local_134);
  iVar4 = 1;
  piVar2 = local_11c;
  do {
    FUN_001a7e06(piVar2);
    piVar2 = piVar2 + 6;
    iVar4 = iVar4 + -1;
  } while (iVar4 != -2);
  FUN_001a7e06(local_d0);
  cVar1 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x42);
  if (cVar1 != '\0') {
    FUN_001966d4(local_1c4,param_1);
  }
  ((int (*)())FUN_00181bf2)(local_1c4,param_1);
  piVar2 = &local_d4;
  do {
    piVar3 = piVar2 + -6;
    piVar2[-3] = (int)(PTR_DAT_00213441 + 8);
    *piVar3 = (int)(PTR_DAT_00213441 + 8);
    piVar2 = piVar3;
  } while (piVar3 != local_11c);
  return;
}

/* FUN_001825e0 @ 0x1825e0 (29 bytes) */
int FUN_001825e0(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}

/* FUN_001825fe @ 0x1825fe (66 bytes) */
int FUN_001825fe(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 < iVar1) {
    iVar3 = *(int *)(param_1 + 0x14);
    if (iVar3 < iVar1 - iVar2) {
      return iVar1;
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 0x14);
    if (iVar3 < iVar2 - iVar1) {
      return iVar2;
    }
  }
  return (iVar3 + iVar1 + iVar2) / 2;
}

/* FUN_00182640 @ 0x182640 (101 bytes) */
int FUN_00182640(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  (**(code **)(*param_1 + 0x4c))(param_1,*(undefined4 *)(param_2 + 0x38));
  iVar1 = *(int *)(param_2 + 0x58);
  if (iVar1 == 3) {
    param_1[3] = param_1[3] + 1;
    param_1[4] = param_1[4] + 1;
    return;
  }
  if (*(char *)(param_2 + 0x5c) == '\0') {
    if (iVar1 == 1) {
      param_1[3] = param_1[3] + 1;
      return;
    }
    if (iVar1 == 2) {
      param_1[4] = param_1[4] + 1;
      return;
    }
  }
  else {
    param_1[5] = param_1[5] + 1;
  }
  return;
}

/* FUN_001826a6 @ 0x1826a6 (122 bytes) */
int FUN_001826a6(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 0x58);
  iVar2 = (**(code **)(*param_1 + 0x4c))(param_1,*(undefined4 *)(param_2 + 0x38));
  if (iVar1 != iVar2) {
    (**(code **)(*param_1 + 0x50))(param_1);
  }
  iVar1 = *(int *)(param_2 + 0x58);
  if (iVar1 == 3) {
    param_1[3] = param_1[3] + -1;
    param_1[4] = param_1[4] + -1;
    return;
  }
  if (*(char *)(param_2 + 0x5c) == '\0') {
    if (iVar1 == 1) {
      param_1[3] = param_1[3] + -1;
      return;
    }
    if (iVar1 == 2) {
      param_1[4] = param_1[4] + -1;
      return;
    }
  }
  else {
    param_1[5] = param_1[5] + -1;
  }
  return;
}

/* FUN_00182720 @ 0x182720 (110 bytes) */
int FUN_00182720(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 0x4c))(param_1,param_2);
  cVar1 = (**(code **)(*param_1 + 0x30))(param_1,param_2);
  if (iVar2 == 3) {
    param_1[3] = param_1[3] + 1;
    param_1[4] = param_1[4] + 1;
    return;
  }
  if (cVar1 == '\0') {
    if (iVar2 == 1) {
      param_1[3] = param_1[3] + 1;
      return;
    }
    if (iVar2 == 2) {
      param_1[4] = param_1[4] + 1;
      return;
    }
  }
  else {
    param_1[5] = param_1[5] + 1;
  }
  return;
}

/* FUN_0018278e @ 0x18278e (67 bytes) */
int FUN_0018278e(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x14) < *(int *)(param_1 + 0xc)) {
    return *(int *)(param_2 + 0x20) + *(int *)(param_2 + 0x28);
  }
  if (*(int *)(param_1 + 0x10) <= *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x14)) {
    return *(int *)(param_2 + 0x20) + *(int *)(param_2 + 0x24) + *(int *)(param_2 + 0x28);
  }
  return *(int *)(param_2 + 0x20) + *(int *)(param_2 + 0x24);
}

/* FUN_001827d2 @ 0x1827d2 (165 bytes) */
int FUN_001827d2(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_10;
  
  iVar5 = *(int *)(param_1 + 0xc);
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 < iVar5) {
    iVar4 = *(int *)(param_1 + 0x14);
    iVar6 = iVar5;
    local_10 = iVar2;
    if ((iVar5 - iVar2) + 2 <= iVar4) {
LAB_00182838:
      uVar1 = iVar4 + iVar5 + iVar2;
      iVar5 = (int)uVar1 / 2;
      if ((uVar1 & 1) == 0) {
        return iVar5;
      }
      return iVar5 + 1;
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0x14);
    iVar6 = iVar2;
    local_10 = iVar5;
    if ((iVar2 - iVar5) + 2 <= iVar4) goto LAB_00182838;
  }
  iVar4 = *(int *)(param_2 + 0x58);
  iVar3 = iVar6;
  if (iVar4 != 3) {
    if (*(char *)(param_2 + 0x5c) != '\0') {
      return local_10;
    }
    iVar3 = iVar5;
    if ((iVar4 == 1) || (iVar3 = iVar2, iVar4 == 2)) {
      if (iVar3 != iVar6) {
        return local_10;
      }
    }
    else {
      iVar3 = 0;
    }
  }
  return iVar3;
}

/* FUN_00182878 @ 0x182878 (59 bytes) */
int FUN_00182878(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  int *piVar2;
  
  if (*(int *)(param_2 + 0x58) == 0) {
    param_1 = param_3 + 5;
    FUN_001a7cd6();
    return;
  }
  iVar1 = 0;
  piVar2 = param_3;
  do {
    if (*piVar2 == 0) {
      param_3[iVar1] = param_2;
      return;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 != 5);
  return;
}

/* FUN_001828b4 @ 0x1828b4 (69 bytes) */
int FUN_001828b4(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  
  if (*(char *)(*(int *)(param_1 + 8) + 0x3ec) != '\0') {
    return 1;
  }
  if (param_2 < 0x10) {
    if (param_3 < 0x10) {
      uVar1 = 0;
      goto LAB_001828d1;
    }
    if (param_4 <= param_3 * 4) {
      uVar1 = 0;
      goto LAB_001828d1;
    }
  }
  uVar1 = 1;
LAB_001828d1:
  *(undefined1 *)(*(int *)(param_1 + 8) + 0x3ec) = uVar1;
  return uVar1;
}

/* FUN_001828fa @ 0x1828fa (123 bytes) */
int FUN_001828fa(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    FUN_0010ab40(param_2,param_3);
    return param_2;
  }
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  FUN_0010ac30(puVar2 + 1,(-(param_3 == '\0') & 0x7bU) + 0x2b,*(undefined4 *)(param_1 + 8));
  return puVar2 + 1;
}

/* FUN_00182992 @ 0x182992 (114 bytes) */
int FUN_00182992(param_1, param_2)
  int *param_1;
  int param_2;
{
  char cVar1;
  
  ((int (*)())FUN_001826a6)(param_1,param_2);
  (**(code **)(*param_1 + 0x38))(param_1,param_2);
  cVar1 = (**(code **)(*param_1 + 0xc))(param_1,*(undefined4 *)(param_2 + 0x38));
  if (cVar1 != '\0') {
    ((int (*)())FUN_00182640)(param_1,param_2);
    return 1;
  }
  (**(code **)(*param_1 + 0x38))(param_1,param_2);
  ((int (*)())FUN_00182640)(param_1,param_2);
  return 0;
}

/* FUN_00182a04 @ 0x182a04 (672 bytes) */
int FUN_00182a04(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = param_1[0x56];
  uVar3 = FUN_0010b180(param_1,param_2);
  iVar4 = FUN_0010a17a(0x31,param_3);
  *(undefined4 *)(iVar4 + 0x94) = *(undefined4 *)(iVar4 + 0x14c);
  *(undefined4 *)(iVar4 + 0x98) = 0;
  FUN_0010ba02(iVar4,1,uVar3,0,param_3);
  iVar5 = FUN_0010b0f4(param_1,param_2);
  uVar3 = FUN_000f5bdc(*(undefined4 *)(iVar5 + 0x10));
  FUN_0010ba02(param_1,param_2,iVar4,0,param_3);
  uVar6 = FUN_000f5a44(DAT_001cc710,uVar3);
  *(undefined4 *)(iVar4 + 0x9c) = uVar6;
  uVar6 = FUN_000f5b96(DAT_001cc70c,uVar3);
  iVar5 = FUN_0010b0f4(iVar4,1);
  *(undefined4 *)(iVar5 + 0x10) = uVar6;
  *(undefined4 *)(iVar4 + 0xc) = uVar3;
  if ((*(byte *)(param_1 + param_2 * 6 + 0x28) & 2) == 0) {
    iVar7 = ((int (*)())FUN_0017493c)(iVar8,iVar4);
    iVar5 = *(int *)(iVar7 + 0x158);
  }
  else {
    FUN_00109c0e(param_1 + param_2 * 6 + 0x23,2,0);
    FUN_00109c0e(iVar4 + 0xa4,2,1);
    iVar7 = ((int (*)())FUN_0017493c)(iVar8,iVar4);
    iVar5 = *(int *)(iVar7 + 0x158);
  }
  if (iVar5 == 0) {
    piVar1 = (int *)(*(int *)(param_3 + 0x3f4) + 0x238);
    *piVar1 = *piVar1 + 1;
    cVar2 = (**(code **)(*param_1 + 0x28))(param_1);
    if (cVar2 == '\0') {
      FUN_000e956e(iVar8,param_1,iVar7);
    }
    else {
      piVar1 = (int *)param_1[1];
      while( true ) {
        if (piVar1 == (int *)0x0) {
          FUN_000e9540(iVar8,iVar7);
          return iVar7;
        }
        cVar2 = (**(code **)(*piVar1 + 0x28))(piVar1);
        if (cVar2 == '\0') break;
        piVar1 = (int *)piVar1[1];
      }
      FUN_000e9596(iVar8,piVar1,iVar7);
    }
  }
  else {
    iVar5 = 1;
    iVar8 = (**(code **)(*param_1 + 0x14))(param_1);
    if (0 < iVar8) {
      do {
        iVar8 = FUN_0010b180(param_1,iVar5);
        if (iVar4 == iVar8) {
          FUN_0010ba02(param_1,iVar5,iVar7,0,param_3);
        }
        iVar5 = iVar5 + 1;
        iVar8 = (**(code **)(*param_1 + 0x14))(param_1);
      } while (iVar5 <= iVar8);
    }
  }
  return iVar7;
}

/* FUN_00182ca4 @ 0x182ca4 (363 bytes) */
int FUN_00182ca4(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint *puVar6;
  uint uVar7;
  uint local_14;
  int local_10;
  
  cVar3 = (**(code **)(**(int **)(param_2 + 0x38) + 0x28))(*(int **)(param_2 + 0x38));
  if (cVar3 != '\0') {
    cVar3 = (**(code **)(*param_1 + 0x20))(param_1,*(undefined4 *)(param_2 + 0x38));
    if (cVar3 != '\0') {
      param_1[2] = *(int *)(param_2 + 0x2c);
    }
  }
  puVar6 = *(uint **)(param_2 + 0x44);
  uVar1 = puVar6[1];
  if (0 < (int)uVar1) {
    uVar7 = 0;
    local_14 = 1;
    local_10 = 0;
    while( true ) {
      if (uVar7 < *puVar6) {
        uVar2 = puVar6[1];
        if (uVar2 <= uVar7) {
          _memset((void *)(puVar6[2] + uVar2 * 4),0,(uVar7 - uVar2) * 4 + 4);
          puVar6[1] = local_14;
        }
        piVar5 = (int *)(local_10 + puVar6[2]);
      }
      else {
        piVar5 = (int *)FUN_001a7f7c(puVar6,uVar7);
      }
      if (*(char *)(*piVar5 + 0x1c) != '\0') {
        puVar6 = *(uint **)(param_2 + 0x44);
        if (uVar7 < *puVar6) {
          uVar2 = puVar6[1];
          if (uVar2 <= uVar7) {
            _memset((void *)(puVar6[2] + uVar2 * 4),0,(uVar7 - uVar2) * 4 + 4);
            puVar6[1] = local_14;
          }
          puVar4 = (undefined4 *)(local_10 + puVar6[2]);
        }
        else {
          puVar4 = (undefined4 *)FUN_001a7f7c(puVar6,uVar7);
        }
        if (param_1[1] <= *(int *)(*(int *)*puVar4 + 0x2c)) {
          puVar6 = (uint *)(*(int *)(param_2 + 0x38) + 0x14);
          *puVar6 = *puVar6 | 0x1000;
          param_1[1] = *(int *)(param_2 + 0x2c);
        }
      }
      uVar7 = uVar7 + 1;
      local_14 = local_14 + 1;
      local_10 = local_10 + 4;
      if (uVar1 == uVar7) break;
      puVar6 = *(uint **)(param_2 + 0x44);
    }
  }
  return;
}

/* FUN_00182e10 @ 0x182e10 (104 bytes) */
int FUN_00182e10(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_10;
  
  local_10 = param_1;
  iVar4 = 1;
  do {
    if (*(int *)(param_1 + 0x20) == *(int *)(local_10 + 0x24)) {
      return 1;
    }
    iVar3 = 0;
    iVar2 = param_1;
    while (iVar3 = iVar3 + 1, iVar3 != iVar4) {
      piVar1 = (int *)(iVar2 + 0x24);
      iVar2 = iVar2 + 4;
      if (*(int *)(local_10 + 0x24) == *piVar1) {
        return 1;
      }
    }
    do {
      iVar4 = iVar4 + 1;
      if (iVar4 == 4) {
        return 0;
      }
      local_10 = local_10 + 4;
    } while (iVar4 < 1);
  } while( true );
}

/* FUN_00182e78 @ 0x182e78 (745 bytes) */
int FUN_00182e78(param_1)
  int param_1;
{
  char cVar1;
  
  cVar1 = FUN_000e1402(*(undefined4 *)(param_1 + 0x238),9);
  if (cVar1 != '\0') {
    cVar1 = FUN_000e1402(*(undefined4 *)(param_1 + 0x238),0x30);
    if (cVar1 != '\0') {
      FUN_00192ad8();
      return;
    }
  }
  return;
}

/* FUN_00182eca @ 0x182eca (57 bytes) */
int FUN_00182eca(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_2 + 8) = uVar1;
  FUN_0010fe82(param_1,1,2,param_3);
  return;
}

