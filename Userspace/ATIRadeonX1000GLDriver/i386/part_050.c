#include "decls.h"

/* FUN_0019ccce @ 0x19ccce (257 bytes) */
int FUN_0019ccce(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int *param_3;
  int param_4;
  int param_5;
{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int local_38;
  int local_34;
  int local_30;
  int *local_24;
  int local_20 [5];
  
  local_38 = 0;
  do {
    local_30 = 2;
    piVar5 = param_2;
    do {
      local_34 = 1;
      iVar3 = (**(code **)(*piVar5 + 0x14))(piVar5);
      if (0 < iVar3) {
        do {
          piVar4 = (int *)FUN_0010b180(piVar5,local_34);
          cVar2 = (**(code **)(*piVar4 + 0x60))(piVar4);
          if (cVar2 == '\0') {
LAB_0019cd6e:
            cVar2 = (**(code **)(*piVar4 + 0x48))(piVar4);
            if ((cVar2 != '\0') && (piVar4[0x4b] == 3)) {
              if (local_38 < 1) {
LAB_0019cd8a:
                local_20[local_38 + -1] = (int)piVar4;
                local_38 = local_38 + 1;
                if (param_5 + param_4 < local_38) {
                  return 0;
                }
              }
              else if (local_24 != piVar4) {
                iVar3 = 0;
                do {
                  if (iVar3 + 1 == local_38) goto LAB_0019cd8a;
                  piVar1 = local_20 + iVar3;
                  iVar3 = iVar3 + 1;
                } while (piVar4 != (int *)*piVar1);
              }
            }
          }
          else {
            cVar2 = FUN_0010a62e(piVar4,*(undefined4 *)(*(int *)(param_1 + 8) + 0x3f4));
            if (cVar2 != '\0') {
              piVar4 = (int *)FUN_0010b180(piVar4,1);
              goto LAB_0019cd6e;
            }
          }
          local_34 = local_34 + 1;
          iVar3 = (**(code **)(*piVar5 + 0x14))(piVar5);
        } while (local_34 <= iVar3);
      }
      local_30 = local_30 + -1;
      if (local_30 == 0) {
        return 1;
      }
      piVar5 = param_3;
    } while (local_30 != 2);
  } while( true );
}

/* FUN_0019cdd0 @ 0x19cdd0 (510 bytes) */
int FUN_0019cdd0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int *param_3;
  undefined4 param_4;
  int param_5;
{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int *local_38;
  int local_34;
  int local_30;
  int *local_24;
  int local_20 [5];
  
  local_48 = 0;
  do {
    local_44 = 0;
    piVar6 = param_2;
    do {
      if (piVar6 != (int *)0x0) {
        local_40 = 1;
        iVar3 = (**(code **)(*piVar6 + 0x14))(piVar6);
        if (0 < iVar3) {
          do {
            local_38 = (int *)FUN_0010b180(piVar6,local_40);
            cVar2 = (**(code **)(*local_38 + 0x60))(local_38);
            if (cVar2 == '\0') {
              local_3c = local_40;
              piVar5 = local_38;
              local_38 = piVar6;
LAB_0019ce2b:
              cVar2 = (**(code **)(*piVar5 + 0x48))(piVar5);
              if ((cVar2 != '\0') && (piVar5[0x4b] == 3)) {
                if (local_48 < 1) {
                  iVar3 = 0;
LAB_0019cf46:
                  local_20[local_48 + -1] = (int)piVar5;
                  local_48 = local_48 + 1;
                }
                else if (piVar5 == local_24) {
                  iVar3 = 0;
                }
                else {
                  iVar4 = 0;
                  do {
                    iVar3 = iVar4 + 1;
                    if (iVar3 == local_48) goto LAB_0019cf46;
                    piVar1 = local_20 + iVar4;
                    iVar4 = iVar3;
                  } while (piVar5 != (int *)*piVar1);
                }
                if (iVar3 < param_5) {
                  local_34 = 0;
                  do {
                    iVar3 = FUN_0010b0f4(local_38,local_3c);
                    if (*(char *)(local_34 + 0x10 + iVar3) != '\x04') {
                      (**(code **)(*local_38 + 0x88))(local_38,local_3c,local_34,3);
                    }
                    local_34 = local_34 + 1;
                  } while (local_34 != 4);
                  *(undefined1 *)((int)piVar5 + 0x9f) = 0;
                }
                else {
                  local_30 = 0;
                  do {
                    iVar3 = FUN_0010b0f4(local_38,local_3c);
                    if (*(char *)(local_30 + 0x10 + iVar3) != '\x04') {
                      (**(code **)(*local_38 + 0x88))(local_38,local_3c,local_30,0);
                    }
                    local_30 = local_30 + 1;
                  } while (local_30 != 4);
                  *(undefined1 *)(piVar5 + 0x27) = 0;
                }
              }
            }
            else {
              cVar2 = FUN_0010a62e(local_38,*(undefined4 *)(*(int *)(param_1 + 8) + 0x3f4));
              if (cVar2 != '\0') {
                piVar5 = (int *)FUN_0010b180(local_38,1);
                local_3c = 1;
                goto LAB_0019ce2b;
              }
            }
            local_40 = local_40 + 1;
            iVar3 = (**(code **)(*piVar6 + 0x14))(piVar6);
          } while (local_40 <= iVar3);
        }
      }
      local_44 = local_44 + 1;
      if (local_44 == 2) {
        return;
      }
      piVar6 = param_3;
    } while (local_44 != 0);
  } while( true );
}

/* FUN_0019cfce @ 0x19cfce (57 bytes) */
int FUN_0019cfce(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x88);
  if ((*(int *)(iVar1 + 8) == 0x1e) || (*(int *)(iVar1 + 8) == 0x1d)) {
    return 1;
  }
  if ((*(int *)(iVar1 + 8) != 0x1c) && (*(int *)(iVar1 + 8) != 0xa3)) {
    return 0;
  }
  return 2;
}

/* FUN_0019d008 @ 0x19d008 (166 bytes) */
int FUN_0019d008(param_1)
  int *param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint local_10;
  
  (**(code **)(*param_1 + 0x5c))(param_1);
  iVar1 = *(int *)(param_1[0x22] + 8);
  iVar3 = FUN_0010b180(param_1,1);
  uVar2 = *(uint *)(iVar3 + 0x94);
  iVar3 = (**(code **)(*param_1 + 0x14))(param_1);
  if (iVar3 < 2) {
    local_10 = 0;
  }
  else {
    iVar3 = FUN_0010b180(param_1,2);
    local_10 = *(uint *)(iVar3 + 0x94) & 0xfff;
  }
  iVar3 = FUN_0010b0f4(param_1,0);
  return local_10 |
         iVar1 << 0x19 | (uint)(*(char *)(iVar3 + 0x13) != '\x01') << 0x18 | (uVar2 & 0xfff) << 0xc;
}

/* FUN_0019d0ae @ 0x19d0ae (217 bytes) */
int FUN_0019d0ae(param_1, param_2)
  int *param_1;
  int *param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = (**(code **)(*param_1 + 0x5c))(param_1);
  if (cVar1 != '\0') {
    (**(code **)(*param_2 + 0x5c))(param_2);
  }
  if (*(int *)(param_1[0x22] + 8) == *(int *)(param_2[0x22] + 8)) {
    iVar2 = FUN_0010b0f4(param_1,0);
    cVar1 = *(char *)(iVar2 + 0x13);
    iVar2 = FUN_0010b0f4(param_2,0);
    if (*(char *)(iVar2 + 0x13) == cVar1) {
      iVar2 = FUN_0010b180(param_1,1);
      iVar3 = FUN_0010b180(param_2,1);
      if (iVar2 == iVar3) {
        iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
        if (1 < iVar2) {
          iVar2 = FUN_0010b180(param_1,2);
          iVar3 = FUN_0010b180(param_2,2);
          if (iVar2 != iVar3) {
            return 0xffffffff;
          }
        }
        return 0;
      }
    }
  }
  return 0xffffffff;
}

/* FUN_0019d188 @ 0x19d188 (405 bytes) */
int FUN_0019d188(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int *param_3;
{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  cVar2 = (**(code **)(*param_1 + 0x28))(param_1);
  if (cVar2 != '\0') {
    return 1;
  }
  if (*(int *)(param_1[0x22] + 4) == 1) {
    return 1;
  }
  iVar3 = *(int *)(param_1[0x22] + 8);
  iVar5 = iVar3;
  if ((iVar3 - 0x1cU < 3) || (iVar3 == 0xa3)) {
    if ((iVar3 == 0x1d) ||
       ((iVar3 == 0xa3 || (iVar3 = FUN_0010b0f4(param_1,0), *(char *)(iVar3 + 0x13) == '\0')))) {
      iVar4 = 0x97;
    }
    else {
      iVar4 = -1;
    }
LAB_0019d2a8:
    iVar3 = iVar4;
    if (iVar5 < 0) goto LAB_0019d2f3;
  }
  else {
    if ((((((iVar3 != 0x37) && (iVar3 != 0x3a)) && (iVar3 != 0x3b)) &&
         (((iVar3 != 0x3e && (iVar3 != 0x3f)) &&
          ((iVar3 != 0x40 && ((iVar3 != 0x41 && (iVar3 != 0x42)))))))) && (iVar3 != 0x43)) &&
       ((iVar3 != 0x4c && (iVar3 != 0x4d)))) {
      iVar4 = FUN_0010b0f4(param_1,0);
      uVar1 = *(undefined4 *)(iVar4 + 0x10);
      if (((char)uVar1 != '\0') &&
         (((char)((uint)uVar1 >> 8) != '\0' && ((char)((uint)uVar1 >> 0x10) != '\0')))) {
        iVar5 = -1;
      }
      iVar4 = -1;
      if ((char)((uint)uVar1 >> 0x18) == '\0') {
        iVar4 = iVar3;
      }
      goto LAB_0019d2a8;
    }
    iVar5 = FUN_0010b0f4(param_1,0);
    uVar1 = *(undefined4 *)(iVar5 + 0x10);
    if ((((char)uVar1 != '\0') && ((char)((uint)uVar1 >> 8) != '\0')) &&
       ((char)((uint)uVar1 >> 0x10) != '\0')) goto LAB_0019d2f3;
    iVar5 = 0x98;
  }
  if (-1 < *param_2) {
    return 0;
  }
  *param_2 = iVar5;
LAB_0019d2f3:
  if (iVar3 < 0) {
    return 1;
  }
  if (-1 < *param_3) {
    return 0;
  }
  *param_3 = iVar3;
  return 1;
}

/* FUN_0019d31e @ 0x19d31e (115 bytes) */
int FUN_0019d31e(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  char cVar1;
  undefined4 uVar2;
  int local_14;
  int local_10 [2];
  
  local_10[0] = -1;
  local_14 = -1;
  if ((short)param_2[5] < 0) {
LAB_0019d37f:
    uVar2 = 0;
  }
  else {
    cVar1 = (**(code **)(*param_2 + 0x28))(param_2);
    if (cVar1 == '\0') {
      ((int (*)())FUN_0019d188)(param_2,local_10,&local_14);
      if (local_10[0] < 0) {
        if (-1 < local_14) {
          return 2;
        }
        goto LAB_0019d37f;
      }
      if (local_14 < 0) {
        return 1;
      }
    }
    uVar2 = 3;
  }
  return uVar2;
}

/* FUN_0019d392 @ 0x19d392 (273 bytes) */
int FUN_0019d392(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  undefined4 uVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  cVar2 = (**(code **)(*param_2 + 0x30))(param_2);
  if (cVar2 != '\0') {
    iVar4 = FUN_0010b0f4(param_2,1);
    uVar3 = FUN_0019cc06(*(undefined4 *)(iVar4 + 0x10));
    return uVar3;
  }
  cVar2 = (**(code **)(*param_2 + 0x5c))(param_2);
  if (cVar2 == '\0') {
    iVar6 = 1;
    iVar4 = (**(code **)(*param_2 + 0x14))(param_2);
    if (0 < iVar4) {
      do {
        iVar4 = FUN_0010b0f4(param_2,iVar6);
        uVar1 = *(undefined4 *)(iVar4 + 0x10);
        piVar5 = (int *)FUN_0010b180(param_2,iVar6);
        cVar2 = (**(code **)(*piVar5 + 0x5c))(piVar5);
        if (cVar2 == '\0') {
          cVar2 = FUN_0019cb9c(uVar1);
        }
        else {
          cVar2 = FUN_0019cc30(uVar1);
        }
        if (cVar2 == '\0') {
          return 0;
        }
        iVar6 = iVar6 + 1;
        iVar4 = (**(code **)(*param_2 + 0x14))(param_2);
      } while (iVar6 <= iVar4);
    }
  }
  else {
    iVar4 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar4 != 1) {
      iVar4 = FUN_0010b0f4(param_2,2);
      iVar4 = *(int *)(iVar4 + 0x10);
      iVar6 = FUN_0010b0f4(param_2,1);
      if (*(int *)(iVar6 + 0x10) != iVar4) {
        return 0;
      }
    }
  }
  return 1;
}

/* FUN_0019d4a4 @ 0x19d4a4 (462 bytes) */
int FUN_0019d4a4(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int *param_2;
  int param_3;
  int param_4;
  int *param_5;
{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  *param_5 = 0;
  iVar2 = FUN_0010b0f4(param_2,param_3);
  uVar6 = *(uint *)(iVar2 + 0x10);
  cVar1 = (**(code **)(*param_2 + 0x28))(param_2);
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*param_2 + 0x5c))(param_2);
    if (cVar1 != '\0') {
      cVar1 = FUN_000f5a1e(param_2,1);
      if (cVar1 == '\0') {
        return;
      }
      iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
      if (iVar2 == 1) {
        return;
      }
      FUN_000f5a1e(param_2,2);
      return;
    }
    piVar3 = (int *)FUN_0010b180(param_2,param_3);
    cVar1 = (**(code **)(*piVar3 + 0x5c))(piVar3);
    if (cVar1 != '\0') {
      cVar1 = FUN_0019cc30(uVar6);
      if (cVar1 != '\0') {
        return;
      }
      goto LAB_0019d532;
    }
    cVar1 = FUN_0019cb9c(uVar6);
  }
  else {
    if (param_3 != 1) {
      return;
    }
    cVar1 = FUN_0019cc06(uVar6);
  }
  if (cVar1 != '\0') {
    return;
  }
LAB_0019d532:
  iVar5 = (uVar6 & 0xff) * 0x7d + (uVar6 >> 8 & 0xff) * 0x19 + (uVar6 >> 0x10 & 0xff) * 5 +
          (uVar6 >> 0x18);
  iVar2 = *param_5;
  iVar4 = *(int *)(&DAT_001cc7a0 + (iVar2 + iVar5 * 4) * 4);
  if (DAT_001cf004 != iVar4) {
    do {
      *(int *)(param_4 + iVar2 * 4) = iVar4;
      iVar2 = *param_5 + 1;
      *param_5 = iVar2;
      iVar4 = *(int *)(&DAT_001cc7a0 + (iVar2 + iVar5 * 4) * 4);
    } while (DAT_001cf004 != iVar4);
  }
  if ((char)uVar6 != '\x04') {
    uVar6 = uVar6 & 0xffffff00;
  }
  if ((char)(uVar6 >> 8) != '\x04') {
    uVar6 = CONCAT22((short)(uVar6 >> 0x10),CONCAT11(1,(char)uVar6));
  }
  if ((char)(uVar6 >> 0x10) != '\x04') {
    uVar6 = uVar6 & 0xff00ffff | 0x20000;
  }
  if ((char)(uVar6 >> 0x18) != '\x04') {
    uVar6 = uVar6 & 0xffffff | 0x3000000;
  }
  iVar2 = FUN_0010b0f4(param_2,param_3);
  *(uint *)(iVar2 + 0x10) = uVar6;
  return;
}

/* FUN_0019d672 @ 0x19d672 (2654 bytes) */
int FUN_0019d672(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  byte bVar6;
  undefined4 *puVar7;
  int iVar8;
  void *pvVar9;
  int *piVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  undefined4 uVar16;
  uint uVar17;
  char local_84;
  int *local_70;
  int local_4c;
  int local_38;
  int local_34;
  char local_30;
  char cStack_25;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar2 = *(int *)(param_2 + 0x378);
  iVar8 = *(int *)(iVar2 + 8);
  do {
    if (iVar8 == 0) {
      return;
    }
    uVar11 = *(undefined4 *)(param_1[2] + 0xbc);
    puVar7 = (undefined4 *)FUN_001a7bca(uVar11,0x1c);
    *puVar7 = uVar11;
    puVar1 = puVar7 + 1;
    puVar7[4] = FUN_0019d0ae;
    puVar7[5] = FUN_0019d008;
    puVar7[6] = uVar11;
    puVar7[1] = 1;
    iVar8 = 0;
    uVar17 = 1;
    do {
      uVar17 = uVar17 * 2;
      if (0xf < uVar17) break;
      iVar8 = iVar8 + 1;
    } while (iVar8 != 0x20);
    *puVar1 = uVar17;
    puVar7[2] = 0;
    pvVar9 = (void *)FUN_001a7bca(uVar11,*puVar1 << 2);
    puVar7[3] = pvVar9;
    _memset(pvVar9,0,*puVar1 << 2);
    local_70 = *(int **)(iVar2 + 0x98);
    iVar8 = local_70[2];
    while (iVar8 != 0) {
      while ((*(byte *)(local_70 + 5) & 1) != 0) {
        if ((*(int *)(local_70[0x22] + 8) != 0x31) && (*(int *)(local_70[0x22] + 8) != 0x30)) {
LAB_0019d78d:
          local_38 = 1;
          iVar8 = (**(code **)(*local_70 + 0x14))(local_70);
          if (0 < iVar8) {
            do {
              piVar10 = (int *)FUN_0010b180(local_70,local_38);
              cVar5 = (**(code **)(*piVar10 + 0x5c))(piVar10);
              if (cVar5 != '\0') {
                piVar14 = (int *)FUN_001a84b2(puVar1,piVar10);
                if (piVar14 == (int *)0x0) {
                  FUN_001a89d8(puVar1,piVar10);
                }
                else if (piVar10 != piVar14) {
                  iVar8 = FUN_0010b0f4(piVar14,0);
                  local_24 = *(int *)(iVar8 + 0x10);
                  iVar8 = FUN_0010b0f4(piVar10,0);
                  local_20 = *(undefined4 *)(iVar8 + 0x10);
                  iVar8 = 1;
                  do {
                    cVar5 = *(char *)((int)&local_24 + iVar8 + 3);
                    if (cVar5 != '\x01') {
                      (&cStack_25)[iVar8] = cVar5;
                    }
                    iVar8 = iVar8 + 1;
                  } while (iVar8 != 5);
                  piVar14[0x27] = local_24;
                  uVar11 = FUN_000f5fea(local_24);
                  uVar11 = FUN_000f5b96(DAT_001cf000,uVar11);
                  iVar8 = FUN_0010b0f4(piVar14,1);
                  *(undefined4 *)(iVar8 + 0x10) = uVar11;
                  iVar8 = (**(code **)(*piVar14 + 0x14))(piVar14);
                  if (1 < iVar8) {
                    iVar8 = FUN_0010b0f4(piVar14,2);
                    *(undefined4 *)(iVar8 + 0x10) = uVar11;
                  }
                  FUN_0010ba02(local_70,local_38,piVar14,0,param_1[2]);
                  (**(code **)(*piVar10 + 0xc))(piVar10,0,param_1[2]);
                }
              }
              local_38 = local_38 + 1;
              iVar8 = (**(code **)(*local_70 + 0x14))(local_70);
            } while (local_38 <= iVar8);
          }
          break;
        }
        piVar10 = (int *)FUN_0010b180(local_70,1);
        cVar5 = (**(code **)(*piVar10 + 0x5c))(piVar10);
        if ((cVar5 == '\0') || ((*(byte *)(local_70 + 0x2e) & 2) != 0)) goto LAB_0019d78d;
        piVar10 = (int *)FUN_0010b180(local_70,1);
        iVar8 = local_70[0x49];
        if (*(int *)(piVar10[0x22] + 8) == 0x99) {
          iVar8 = local_70[0x49] + 1;
        }
        cVar5 = (**(code **)(**(int **)(param_1[2] + 0x54) + 0xfc))
                          (*(int **)(param_1[2] + 0x54),iVar8,0);
        if (cVar5 == '\0') goto LAB_0019d78d;
        iVar15 = local_70[1];
        iVar3 = local_70[0x25];
        iVar4 = local_70[0x26];
        iVar12 = FUN_0010b0f4(local_70,0);
        iVar12 = *(int *)(iVar12 + 0x10);
        iVar13 = FUN_0010b0f4(local_70,1);
        uVar11 = *(undefined4 *)(iVar13 + 0x10);
        iVar13 = local_70[0x48];
        bVar6 = *(byte *)(local_70 + 0x2e) & 1;
        uVar17 = local_70[5];
        if ((uVar17 & 0x200) == 0) {
          local_4c = 0;
        }
        else {
          local_4c = FUN_0010b180(local_70,local_70[0x21]);
        }
        FUN_001a7d72(local_70);
        FUN_0010d8fc(local_70,0x12,*(undefined4 *)(param_2 + 8));
        local_70[0x25] = iVar3;
        local_70[0x26] = iVar4;
        local_70[0x27] = iVar12;
        *(char *)(local_70 + 0x48) = (char)iVar13;
        local_70[0x49] = iVar8;
        if ((uVar17 & 0x40) == 0) {
          local_70[5] = local_70[5] & 0xffffffbf;
        }
        else {
          local_70[5] = local_70[5] | 0x40;
        }
        if ((uVar17 & 2) != 0) {
          FUN_0010a38c(local_70,*(undefined4 *)(param_1[2] + 0x3f4),iVar4,iVar3);
        }
        if (local_4c != 0) {
          FUN_0010c18e(local_70,local_4c,0,param_1[2]);
        }
        FUN_000e9596(iVar2,iVar15,local_70);
        iVar8 = *(int *)(piVar10[0x22] + 8);
        if (iVar8 == 0x9a) {
          iVar8 = param_1[2];
          uVar16 = FUN_0010b180(piVar10,1);
          FUN_0010ba02(local_70,1,uVar16,0,iVar8);
          iVar8 = param_1[2];
          uVar16 = FUN_0010b180(piVar10,2);
          FUN_0010ba02(local_70,2,uVar16,0,iVar8);
          iVar8 = FUN_0010b0f4(local_70,1);
          *(undefined4 *)(iVar8 + 0x10) = uVar11;
          iVar8 = FUN_0010b0f4(local_70,2);
          *(undefined4 *)(iVar8 + 0x10) = uVar11;
          FUN_00109c0e(local_70 + 0x29,1,bVar6);
          bVar6 = bVar6 ^ 1;
LAB_0019de76:
          FUN_00109c0e(local_70 + 0x2f,1,bVar6);
          (**(code **)(*piVar10 + 0xc))(piVar10,0,param_1[2]);
        }
        else {
          if (iVar8 < 0x9b) {
            if (iVar8 == 0x99) {
              iVar8 = param_1[2];
              uVar16 = FUN_0010b180(piVar10,1);
              FUN_0010ba02(local_70,1,uVar16,0,iVar8);
              uVar16 = 0x3f000000;
LAB_0019de03:
              FUN_000fa0d2(local_70,param_2,2,uVar16,uVar16,uVar16,uVar16);
              iVar8 = FUN_0010b0f4(local_70,1);
              *(undefined4 *)(iVar8 + 0x10) = uVar11;
              FUN_00109c0e(local_70 + 0x29,1,bVar6 ^ 1);
              goto LAB_0019de76;
            }
          }
          else {
            if (iVar8 == 0x9b) {
              iVar8 = param_1[2];
              uVar16 = FUN_0010b180(piVar10,1);
              FUN_0010ba02(local_70,1,uVar16,0,iVar8);
              iVar8 = param_1[2];
              uVar16 = FUN_0010b180(piVar10,2);
              FUN_0010ba02(local_70,2,uVar16,0,iVar8);
              iVar8 = FUN_0010b0f4(local_70,1);
              *(undefined4 *)(iVar8 + 0x10) = uVar11;
              iVar8 = FUN_0010b0f4(local_70,2);
              *(undefined4 *)(iVar8 + 0x10) = uVar11;
              FUN_00109c0e(local_70 + 0x29,1,bVar6);
              goto LAB_0019de76;
            }
            if (iVar8 == 0x9c) {
              iVar8 = param_1[2];
              uVar16 = FUN_0010b180(piVar10,1);
              FUN_0010ba02(local_70,1,uVar16,0,iVar8);
              uVar16 = 0x3f800000;
              goto LAB_0019de03;
            }
          }
          (**(code **)(*piVar10 + 0xc))(piVar10,0,param_1[2]);
        }
        local_70 = (int *)local_70[2];
        if (local_70[2] == 0) goto LAB_0019d802;
      }
      local_70 = (int *)local_70[2];
      iVar8 = local_70[2];
    }
LAB_0019d802:
    if (puVar1 != (uint *)0x0) {
      if (*puVar1 == 0) {
        iVar8 = puVar7[3];
      }
      else {
        uVar17 = 0;
        iVar8 = puVar7[3];
        do {
          iVar15 = *(int *)(iVar8 + uVar17 * 4);
          if (iVar15 != 0) {
            FUN_001a7aba(puVar7[6],iVar15);
            iVar8 = puVar7[3];
          }
          uVar17 = uVar17 + 1;
        } while (uVar17 < *puVar1);
      }
      FUN_001a7aba(puVar7[6],iVar8);
      if (puVar1 != (uint *)0x0) {
        FUN_001a7aba(*puVar7,puVar7);
      }
    }
    piVar10 = *(int **)(iVar2 + 0x98);
    iVar8 = piVar10[2];
    while (iVar8 != 0) {
      while ((*(byte *)(piVar10 + 5) & 1) != 0) {
        cVar5 = FUN_000e1402(param_1[2],0x41);
        if (cVar5 != '\0') {
          local_34 = 1;
          while (iVar8 = (**(code **)(*piVar10 + 0x14))(piVar10), local_34 <= iVar8) {
            piVar14 = (int *)FUN_0010b180(piVar10,local_34);
            iVar8 = (**(code **)(*piVar14 + 0x80))(piVar14);
            iVar15 = FUN_0010b0f4(piVar10,local_34);
            uVar16 = FUN_000f60ae(*(undefined4 *)(iVar15 + 0x10));
            iVar15 = FUN_0010b0f4(piVar10,local_34);
            uVar11 = *(undefined4 *)(iVar15 + 0x10);
            if ((((iVar8 == 0) ||
                 (((iVar15 = FUN_0010b0f4(iVar8,0), *(char *)(iVar15 + 0x12) != '\x01' &&
                   (*(int *)(iVar8 + 0xb4) != DAT_001cf018)) ||
                  ((char)((uint)uVar16 >> 0x10) == '\0')))) ||
                ((char)((uint)uVar11 >> 0x10) != '\x03')) ||
               (((local_84 = (char)uVar16, local_84 == '\0' ||
                 (local_30 = (char)uVar11, local_30 != '\0')) &&
                (((char)((uint)uVar16 >> 8) == '\0' || ((char)((uint)uVar11 >> 8) != '\x01')))))) {
              local_34 = local_34 + 1;
            }
            else {
              *(int *)(iVar8 + 0xb4) = DAT_001cf018;
              *(undefined1 *)(iVar8 + 0x9e) = 0;
              *(undefined1 *)(iVar8 + 0xe) = 1;
              if (local_34 == 0) {
                piVar10[0x27] = DAT_001cf000;
                local_34 = 1;
              }
              else {
                iVar8 = FUN_0010b0f4(piVar10,local_34);
                *(int *)(iVar8 + 0x10) = DAT_001cf000;
                local_34 = local_34 + 1;
              }
            }
          }
        }
        if (*(int *)(piVar10[0x22] + 8) == 0x8e) break;
        (**(code **)(*param_1 + 0x6c))(param_1,piVar10);
        piVar10 = (int *)piVar10[2];
        if (piVar10[2] == 0) goto LAB_0019d8da;
      }
      piVar10 = (int *)piVar10[2];
      iVar8 = piVar10[2];
    }
LAB_0019d8da:
    iVar2 = *(int *)(iVar2 + 8);
    iVar8 = *(int *)(iVar2 + 8);
  } while( true );
}

/* FUN_0019e0f4 @ 0x19e0f4 (1466 bytes) */
int FUN_0019e0f4(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int *param_3;
  undefined4 *param_4;
{
  code *pcVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *local_24;
  
  iVar5 = *(int *)(param_2 + 0x88);
  if (*(int *)(iVar5 + 8) == 0x1c) {
    local_24 = (int *)FUN_0010a17a(0x13,param_1[2]);
    local_24[0x25] = local_24[0x53];
    local_24[0x26] = 0;
    local_24[0x27] = DAT_001cf00c;
    *param_4 = 3;
    iVar5 = param_1[2];
    uVar4 = FUN_0010b0f4(param_2,1);
    FUN_0010bc9c(local_24,1,uVar4,iVar5);
    iVar5 = param_1[2];
    uVar4 = FUN_0010b0f4(param_2,2);
    FUN_0010bc9c(local_24,2,uVar4,iVar5);
    local_24[3] = 0;
    *(undefined1 *)((int)local_24 + 0xf) = 1;
    *param_3 = 2;
    while( true ) {
      iVar5 = FUN_0010b0f4(local_24,1);
      *(undefined4 *)(iVar5 + 0x10) = DAT_001cf004;
      pcVar1 = *(code **)(*local_24 + 0x88);
      iVar5 = *param_3;
      iVar6 = FUN_0010b0f4(param_2,1);
      (*pcVar1)(local_24,1,3,*(undefined1 *)(iVar5 + 0x10 + iVar6));
      iVar5 = FUN_0010b0f4(local_24,2);
      *(undefined4 *)(iVar5 + 0x10) = DAT_001cf004;
      pcVar1 = *(code **)(*local_24 + 0x88);
      iVar5 = *param_3;
      iVar6 = FUN_0010b0f4(param_2,2);
      (*pcVar1)(local_24,2,3,*(undefined1 *)(iVar5 + 0x10 + iVar6));
      cVar2 = (**(code **)(*param_1 + 0xc))(param_1,local_24);
      if (cVar2 != '\0') break;
      if (((*(byte *)(*(int *)(param_1[2] + 0x54) + 9) & 4) == 0) ||
         (iVar5 = *param_3, *param_3 = iVar5 + -1, iVar5 + -1 < 0)) {
        (**(code **)(*local_24 + 4))(local_24);
        return (int *)0x0;
      }
    }
  }
  else {
    if (*(int *)(iVar5 + 8) != 0x1e) {
      if (*(int *)(iVar5 + 8) == 0x1d) {
        piVar3 = (int *)FUN_0010a17a(0x1c,param_1[2]);
        piVar3[0x25] = piVar3[0x53];
        piVar3[0x26] = 0;
        piVar3[0x27] = DAT_001cf008;
        *param_4 = 1;
        *param_3 = 3;
        iVar5 = param_1[2];
        uVar4 = FUN_0010b0f4(param_2,1);
        FUN_0010bc9c(piVar3,1,uVar4,iVar5);
        iVar5 = param_1[2];
        uVar4 = FUN_0010b0f4(param_2,2);
        FUN_0010bc9c(piVar3,2,uVar4,iVar5);
        (**(code **)(*piVar3 + 0x88))(piVar3,1,3,4);
        (**(code **)(*piVar3 + 0x88))(piVar3,2,3,4);
        piVar3[3] = 0;
        *(undefined1 *)(piVar3 + 3) = 1;
        cVar2 = (**(code **)(*param_1 + 0xc))(param_1,piVar3);
        if (cVar2 != '\0') {
          return piVar3;
        }
        (**(code **)(*piVar3 + 4))(piVar3);
      }
      return (int *)0x0;
    }
    piVar3 = (int *)FUN_0010a17a(0x14,param_1[2]);
    piVar3[0x25] = piVar3[0x53];
    piVar3[0x26] = 0;
    piVar3[0x27] = DAT_001cf00c;
    *param_4 = 3;
    iVar5 = param_1[2];
    uVar4 = FUN_0010b0f4(param_2,1);
    FUN_0010bc9c(piVar3,1,uVar4,iVar5);
    iVar5 = param_1[2];
    uVar4 = FUN_0010b0f4(param_2,2);
    FUN_0010bc9c(piVar3,2,uVar4,iVar5);
    iVar5 = param_1[2];
    uVar4 = FUN_0010b0f4(param_2,3);
    FUN_0010bc9c(piVar3,3,uVar4,iVar5);
    piVar3[3] = 0;
    *(undefined1 *)((int)piVar3 + 0xf) = 1;
    *param_3 = 1;
    do {
      iVar5 = FUN_0010b0f4(piVar3,1);
      *(undefined4 *)(iVar5 + 0x10) = DAT_001cf004;
      pcVar1 = *(code **)(*piVar3 + 0x88);
      iVar5 = *param_3;
      iVar6 = FUN_0010b0f4(param_2,1);
      (*pcVar1)(piVar3,1,3,*(undefined1 *)(iVar5 + 0x10 + iVar6));
      iVar5 = FUN_0010b0f4(piVar3,2);
      *(undefined4 *)(iVar5 + 0x10) = DAT_001cf004;
      pcVar1 = *(code **)(*piVar3 + 0x88);
      iVar5 = *param_3;
      iVar6 = FUN_0010b0f4(param_2,2);
      (*pcVar1)(piVar3,2,3,*(undefined1 *)(iVar5 + 0x10 + iVar6));
      iVar5 = FUN_0010b0f4(piVar3,3);
      *(undefined4 *)(iVar5 + 0x10) = DAT_001cf004;
      pcVar1 = *(code **)(*piVar3 + 0x88);
      iVar5 = FUN_0010b0f4(param_2,3);
      (*pcVar1)(piVar3,3,3,*(undefined1 *)(iVar5 + 0x12));
      cVar2 = (**(code **)(*param_1 + 0xc))(param_1,piVar3);
      if (cVar2 != '\0') {
        return piVar3;
      }
      iVar5 = *param_3;
      *param_3 = iVar5 + -1;
    } while (-1 < iVar5 + -1);
    (**(code **)(*piVar3 + 4))(piVar3);
    local_24 = (int *)0x0;
  }
  return local_24;
}

/* FUN_0019e6ae @ 0x19e6ae (963 bytes) */
int FUN_0019e6ae(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  uint *puVar12;
  uint local_28;
  uint local_24;
  int local_14;
  undefined1 *local_10;
  
  if (param_3 <= param_4) {
    puVar10 = (undefined4 *)(param_2 + 0x48 + param_3 * 4);
    iVar4 = param_3;
    do {
      *puVar10 = 0;
      iVar4 = iVar4 + 1;
      puVar10 = puVar10 + 1;
    } while (iVar4 <= param_4);
  }
  puVar12 = *(uint **)(param_2 + 0x40);
  uVar1 = puVar12[1];
  if ((int)uVar1 < 1) {
    return;
  }
  local_28 = 0;
  if (*puVar12 == 0) goto LAB_0019e8da;
LAB_0019e6f9:
  uVar8 = puVar12[1];
  if (uVar8 <= local_28) {
    _memset((void *)(puVar12[2] + uVar8 * 4),0,(local_28 - uVar8) * 4 + 4);
    puVar12[1] = local_28 + 1;
  }
  piVar6 = (int *)(puVar12[2] + local_28 * 4);
  do {
    local_28 = local_28 + 1;
    iVar4 = *piVar6;
    if (*(int *)(iVar4 + 8) == 0) {
      if (param_3 <= param_4) {
        puVar9 = (undefined1 *)(param_3 + 0x18 + iVar4);
        iVar5 = param_3;
        do {
          *puVar9 = 0;
          iVar5 = iVar5 + 1;
          puVar9 = puVar9 + 1;
        } while (iVar5 <= param_4);
      }
      *(undefined1 *)(param_5 + 0x18 + iVar4) = 1;
      piVar6 = (int *)(param_2 + 0x48 + param_5 * 4);
      *piVar6 = *piVar6 + 1;
      iVar5 = *(int *)(iVar4 + 4);
      piVar6 = *(int **)(iVar5 + 0x38);
      if ((*(byte *)((int)piVar6 + 0x15) & 2) != 0) {
        FUN_0010b180(piVar6,piVar6[0x21]);
      }
      (**(code **)(*piVar6 + 0x28))(piVar6);
      cVar3 = (**(code **)(*piVar6 + 0x5c))(piVar6);
      if (cVar3 == '\0') {
        piVar7 = (int *)FUN_0010b180(piVar6,*(undefined4 *)(iVar4 + 0x10));
        cVar3 = (**(code **)(*piVar7 + 0x60))(piVar7);
        if (cVar3 == '\0') {
          local_14 = 0;
          do {
            iVar5 = FUN_0010b0f4(piVar6,*(undefined4 *)(iVar4 + 0x10));
            uVar8 = (uint)*(byte *)(local_14 + 0x10 + iVar5);
            if ((param_3 <= (int)uVar8) && ((int)uVar8 <= param_4)) {
              (**(code **)(*piVar6 + 0x88))(piVar6,*(undefined4 *)(iVar4 + 0x10),local_14,param_5);
            }
            local_14 = local_14 + 1;
          } while (local_14 != 4);
        }
      }
      else {
        iVar4 = (**(code **)(*piVar6 + 0x14))(piVar6);
        if (1 < iVar4) {
          FUN_0010b180(piVar6,1);
          FUN_0010b180(piVar6,2);
        }
        if (param_3 <= param_4) {
          local_10 = (undefined1 *)((int)piVar6 + param_3 + 0xc);
          iVar4 = param_3;
          do {
            local_10[0x90] = 1;
            *local_10 = 0;
            (**(code **)(*piVar6 + 0x88))(piVar6,1,iVar4,4);
            iVar11 = (**(code **)(*piVar6 + 0x14))(piVar6);
            if (iVar11 == 2) {
              (**(code **)(*piVar6 + 0x88))(piVar6,2,iVar4,4);
            }
            iVar4 = iVar4 + 1;
            local_10 = local_10 + 1;
          } while (iVar4 <= param_4);
        }
        *(undefined1 *)(param_5 + 0x9c + (int)piVar6) = 0;
        *(undefined1 *)((int)piVar6 + param_5 + 0xc) = 1;
        (**(code **)(*piVar6 + 0x88))(piVar6,1,param_5,param_5);
        iVar4 = (**(code **)(*piVar6 + 0x14))(piVar6);
        if (iVar4 == 2) {
          (**(code **)(*piVar6 + 0x88))(piVar6,2,param_5,param_5);
        }
        if (param_3 <= param_4) {
          puVar10 = (undefined4 *)(iVar5 + 0x48 + param_3 * 4);
          iVar4 = param_3;
          do {
            *puVar10 = 0;
            iVar4 = iVar4 + 1;
            puVar10 = puVar10 + 1;
          } while (iVar4 <= param_4);
        }
        puVar12 = *(uint **)(iVar5 + 0x40);
        uVar8 = puVar12[1];
        if (0 < (int)uVar8) {
          local_24 = 0;
          if (*puVar12 == 0) goto LAB_0019e88d;
          do {
            uVar2 = puVar12[1];
            if (uVar2 <= local_24) {
              _memset((void *)(puVar12[2] + uVar2 * 4),0,(local_24 - uVar2) * 4 + 4);
              puVar12[1] = local_24 + 1;
            }
            piVar6 = (int *)(puVar12[2] + local_24 * 4);
            while( true ) {
              local_24 = local_24 + 1;
              iVar4 = *piVar6;
              if (*(int *)(iVar4 + 8) == 0) {
                if (param_3 <= param_4) {
                  puVar9 = (undefined1 *)(param_3 + 0x18 + iVar4);
                  iVar11 = param_3;
                  do {
                    *puVar9 = 0;
                    iVar11 = iVar11 + 1;
                    puVar9 = puVar9 + 1;
                  } while (iVar11 <= param_4);
                }
                *(undefined1 *)(param_5 + 0x18 + iVar4) = 1;
                piVar6 = (int *)(iVar5 + 0x48 + param_5 * 4);
                *piVar6 = *piVar6 + 1;
              }
              if (uVar8 == local_24) goto LAB_0019e8c0;
              puVar12 = *(uint **)(iVar5 + 0x40);
              if (local_24 < *puVar12) break;
LAB_0019e88d:
              piVar6 = (int *)FUN_001a7f7c(puVar12,local_24);
            }
          } while( true );
        }
      }
    }
LAB_0019e8c0:
    if (uVar1 == local_28) {
      return;
    }
    puVar12 = *(uint **)(param_2 + 0x40);
    if (local_28 < *puVar12) goto LAB_0019e6f9;
LAB_0019e8da:
    piVar6 = (int *)FUN_001a7f7c(puVar12,local_28);
  } while( true );
}

/* FUN_0019ea72 @ 0x19ea72 (771 bytes) */
int FUN_0019ea72(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_20;
  
  local_20 = DAT_001cf014;
  piVar2 = *(int **)(param_2 + 0x60);
  if (piVar2 != (int *)0x0) {
    local_20 = DAT_001cf014 - *piVar2;
    iVar5 = piVar2[1];
    if (-1 < iVar5) {
      iVar6 = 0;
      do {
        iVar3 = *(int *)(*(int *)(param_3 + iVar6 * 4) + iVar5 * 4);
        if ((iVar3 != 0) && (*(int *)(iVar3 + 0x48 + iVar6 * 4) != 0)) {
          *(undefined1 *)((int)&local_20 + iVar6) = 0;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 != 4);
    }
  }
  iVar5 = local_20;
  if (local_20 == DAT_001cf010) {
    return 0;
  }
  piVar2 = *(int **)(param_2 + 0x38);
  FUN_000f60f4(piVar2);
  iVar6 = FUN_0010b0f4(piVar2,0);
  if (*(char *)(iVar6 + 0x13) == '\0') {
    if (iVar5 == DAT_001cf014) {
      local_38 = param_1[0x18];
      param_1[0x18] = local_38 + 1;
      if (2 < local_38 + 1) {
        param_1[0x18] = 0;
      }
    }
    else {
      local_38 = 0;
      while (*(char *)((int)&local_20 + local_38) == '\0') {
        local_38 = local_38 + 1;
        if (local_38 == 3) {
          return 0;
        }
      }
    }
    if (local_38 == -1) {
      return 0;
    }
    local_3c = 3;
  }
  else {
    if ((*(unsigned char *)((unsigned char *)&(local_20) + 3)) == '\0') {
      return 0;
    }
    iVar5 = FUN_0010b0f4(piVar2,0);
    local_3c = FUN_000f5950(*(undefined4 *)(iVar5 + 0x10));
    local_38 = 3;
  }
  *(undefined1 *)(local_3c + 0x9c + (int)piVar2) = 1;
  *(undefined1 *)((int)piVar2 + local_3c + 0xc) = 0;
  *(undefined1 *)(local_38 + 0x9c + (int)piVar2) = 0;
  *(undefined1 *)((int)piVar2 + local_38 + 0xc) = 1;
  if (*(int *)(PTR_DAT_00213a35 + *(int *)(piVar2[0x22] + 8) * 0x38 + 0x34) == 0) {
    for (local_34 = 1; iVar5 = (**(code **)(*piVar2 + 0x14))(piVar2), local_34 <= iVar5;
        local_34 = local_34 + 1) {
      iVar5 = FUN_0010b0f4(piVar2,local_34);
      uVar1 = *(undefined1 *)(local_3c + 0x10 + iVar5);
      (**(code **)(*piVar2 + 0x88))(piVar2,local_34,local_3c,4);
      (**(code **)(*piVar2 + 0x88))(piVar2,local_34,local_38,uVar1);
    }
  }
  cVar4 = (**(code **)(*param_1 + 0xc))(param_1,*(undefined4 *)(param_2 + 0x38));
  if (cVar4 == '\0') {
    *(undefined1 *)(local_3c + 0x9c + (int)piVar2) = 0;
    *(undefined1 *)((int)piVar2 + local_3c + 0xc) = 1;
    *(undefined1 *)(local_38 + 0x9c + (int)piVar2) = 1;
    *(undefined1 *)((int)piVar2 + local_38 + 0xc) = 0;
    if (*(int *)(PTR_DAT_00213a35 + *(int *)(piVar2[0x22] + 8) * 0x38 + 0x34) == 0) {
      for (local_30 = 1; iVar5 = (**(code **)(*piVar2 + 0x14))(piVar2), local_30 <= iVar5;
          local_30 = local_30 + 1) {
        iVar5 = FUN_0010b0f4(piVar2,local_30);
        uVar1 = *(undefined1 *)(local_38 + 0x10 + iVar5);
        (**(code **)(*piVar2 + 0x88))(piVar2,local_30,local_38,4);
        (**(code **)(*piVar2 + 0x88))(piVar2,local_30,local_3c,uVar1);
      }
    }
    return 0;
  }
  *(uint *)(param_2 + 0x58) = (local_38 == 3) + 1;
  if (*(int *)(param_2 + 0x60) != 0) {
    *(undefined1 *)(*(int *)(param_2 + 0x60) + local_38) = 1;
  }
  ((int (*)())FUN_0019e6ae)(param_1,param_2,local_3c,local_3c,local_38);
  return 1;
}

/* FUN_0019ed76 @ 0x19ed76 (664 bytes) */
int FUN_0019ed76(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined1 uVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  piVar2 = *(int **)(param_2 + 0x38);
  if (piVar2[0x20] == 0) {
LAB_0019ed98:
    uVar4 = piVar2[5];
  }
  else {
    cVar3 = FUN_0012dfd8(piVar2[0x26]);
    if (cVar3 == '\0') goto LAB_0019ed98;
    uVar4 = piVar2[5];
    if ((uVar4 & 2) == 0) {
      (**(code **)(*piVar2 + 0x50))(piVar2);
      uVar4 = piVar2[5];
    }
  }
  if ((uVar4 & 2) == 0) {
    cVar3 = (**(code **)(*piVar2 + 0x5c))(piVar2);
    if (cVar3 == '\0') {
      (**(code **)(*piVar2 + 0x28))(piVar2);
    }
  }
  iVar7 = *(int *)(PTR_DAT_00213a35 + *(int *)(piVar2[0x22] + 8) * 0x38 + 0x34);
  iVar5 = FUN_0010b0f4(piVar2,0);
  if (*(char *)(iVar5 + 0x13) != '\0') {
    if (iVar7 == 5) {
      local_2c = 0;
      local_28 = 2;
      local_24 = 3;
    }
    else {
      iVar5 = FUN_0010b0f4(piVar2,0);
      local_2c = FUN_000f5950(*(undefined4 *)(iVar5 + 0x10));
      local_24 = 3;
      local_28 = local_2c;
    }
    goto LAB_0019ee1a;
  }
  if (iVar7 == 0) {
    iVar5 = FUN_000f60f4(piVar2);
    if (iVar5 < 2) goto LAB_0019ede9;
    iVar5 = FUN_0010b0f4(piVar2,0);
    local_24 = FUN_000f5970(*(undefined4 *)(iVar5 + 0x10));
  }
  else {
LAB_0019ede9:
    local_24 = *(int *)(param_1 + 0x60);
    *(int *)(param_1 + 0x60) = local_24 + 1;
    if (2 < local_24 + 1) {
      *(undefined4 *)(param_1 + 0x60) = 0;
    }
  }
  local_2c = 3;
  local_28 = 3;
LAB_0019ee1a:
  puVar6 = (undefined1 *)((int)piVar2 + local_2c + 0xc);
  iVar5 = local_2c;
  do {
    puVar6[0x90] = 1;
    *puVar6 = 0;
    iVar5 = iVar5 + 1;
    puVar6 = puVar6 + 1;
  } while (iVar5 <= local_28);
  *(undefined1 *)(local_24 + 0x9c + (int)piVar2) = 0;
  *(undefined1 *)((int)piVar2 + local_24 + 0xc) = 1;
  *(uint *)(param_2 + 0x58) = (local_24 == 3) + 1;
  if (((iVar7 - 1U < 2) || (iVar7 == 5)) || (local_2c != local_28)) {
    *(undefined1 *)(param_2 + 0x5c) = 0;
  }
  else {
    local_20 = 1;
    while( true ) {
      iVar5 = (**(code **)(*piVar2 + 0x14))(piVar2);
      if (iVar5 < local_20) break;
      iVar5 = FUN_0010b0f4(piVar2,local_20);
      uVar1 = *(undefined1 *)(local_2c + 0x10 + iVar5);
      (**(code **)(*piVar2 + 0x88))(piVar2,local_20,local_2c,4);
      (**(code **)(*piVar2 + 0x88))(piVar2,local_20,local_24,uVar1);
      local_20 = local_20 + 1;
    }
    if (iVar7 == 0) {
      iVar7 = FUN_000f60f4(piVar2);
      if (1 < iVar7) {
        *(undefined1 *)(param_2 + 0x5c) = 0;
      }
    }
  }
  ((int (*)())FUN_0019e6ae)(param_1,param_2,local_2c,local_28,local_24);
  return;
}

/* FUN_0019f00e @ 0x19f00e (1343 bytes) */
int FUN_0019f00e(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *local_80;
  int local_70;
  int *local_6c;
  int local_68;
  int local_60;
  int local_58;
  int *local_54;
  int *local_50;
  int local_4c;
  int *local_48;
  int local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int local_30;
  int aiStack_28 [7];
  
  if (param_2 < 3) {
    if (*(char *)(param_2 + 0x30 + param_1) == '\0') {
      cVar2 = ((int (*)())FUN_0019f00e)(param_1,param_2 + 1,param_3,param_4);
      if (cVar2 != '\0') {
        return 1;
      }
    }
    else {
      piVar3 = param_3 + 3;
      local_3c = param_4 + 3;
      local_40 = piVar3;
      local_38 = local_3c;
      do {
        piVar4 = (int *)piVar3[-3];
        if ((((piVar4 == (int *)0x0) ||
             (piVar1 = *(int **)(param_1 + 0x18 + param_2 * 4), piVar4 == piVar1)) ||
            (((piVar1 != (int *)0x0 &&
              ((((piVar4[0x20] != 0 && (cVar2 = FUN_0012dfd8(piVar4[0x26]), cVar2 != '\0')) &&
                ((*(byte *)(piVar4 + 5) & 2) == 0)) &&
               ((cVar2 = (**(code **)(*piVar4 + 0x50))(piVar4), cVar2 == '\0' &&
                (piVar4 = *(int **)(param_1 + 0x18 + param_2 * 4), piVar4[0x20] != 0)))))) &&
             ((cVar2 = FUN_0012dfd8(piVar4[0x26]), cVar2 != '\0' &&
              ((((*(byte *)(piVar4 + 5) & 2) == 0 &&
                (cVar2 = (**(code **)(*piVar4 + 0x50))(piVar4), cVar2 == '\0')) &&
               (((*(byte *)(piVar3[-3] + 0x14) & 0x40) != 0 &&
                ((iVar5 = *(int *)(param_1 + 0x18 + param_2 * 4),
                 (*(byte *)(iVar5 + 0x14) & 0x40) != 0 &&
                 (*(int *)(piVar3[-3] + 0x94) == *(int *)(iVar5 + 0x94))))))))))))) &&
           (((piVar4 = (int *)*local_40, piVar4 == (int *)0x0 ||
             (piVar1 = *(int **)(param_1 + 0x24 + param_2 * 4), piVar4 == piVar1)) ||
            ((((((piVar1 != (int *)0x0 && (piVar4[0x20] != 0)) &&
                (cVar2 = FUN_0012dfd8(piVar4[0x26]), cVar2 != '\0')) &&
               (((*(byte *)(piVar4 + 5) & 2) == 0 &&
                (cVar2 = (**(code **)(*piVar4 + 0x50))(piVar4), cVar2 == '\0')))) &&
              (((piVar4 = *(int **)(param_1 + 0x24 + param_2 * 4), piVar4[0x20] != 0 &&
                ((cVar2 = FUN_0012dfd8(piVar4[0x26]), cVar2 != '\0' &&
                 ((*(byte *)(piVar4 + 5) & 2) == 0)))) &&
               (cVar2 = (**(code **)(*piVar4 + 0x50))(piVar4), cVar2 == '\0')))) &&
             ((((*(byte *)(*local_40 + 0x14) & 0x40) != 0 &&
               (iVar5 = *(int *)(param_1 + 0x24 + param_2 * 4),
               (*(byte *)(iVar5 + 0x14) & 0x40) != 0)) &&
              (*(int *)(*local_40 + 0x94) == *(int *)(iVar5 + 0x94))))))))) {
          piVar3[-3] = *(int *)(param_1 + 0x18 + param_2 * 4);
          *local_40 = *(int *)(param_1 + 0x24 + param_2 * 4);
          local_38[-3] = local_38[-3] + 1;
          *local_3c = *local_3c + 1;
          cVar2 = ((int (*)())FUN_0019f00e)(param_1,param_2 + 1,param_3,param_4);
          if (cVar2 != '\0') {
            return 1;
          }
          local_38[-3] = local_38[-3] + -1;
          *local_3c = *local_3c + -1;
          if (local_38[-3] == 0) {
            piVar3[-3] = 0;
          }
          if (*local_3c == 0) {
            *local_40 = 0;
          }
        }
        local_40 = local_40 + 1;
        piVar3 = piVar3 + 1;
        local_3c = local_3c + 1;
        local_38 = local_38 + 1;
      } while (param_3 + 6 != piVar3);
    }
    return 0;
  }
  piVar4 = param_4 + 3;
  iVar6 = 1;
  iVar5 = 4;
  piVar3 = param_4;
  local_80 = piVar4;
  do {
    *(int *)((int)aiStack_28 + iVar5) = *piVar3;
    *(int *)((int)aiStack_28 + iVar5 + 0xc) = *local_80;
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 4;
    piVar3 = piVar3 + 1;
    local_80 = local_80 + 1;
  } while (iVar6 != 4);
  local_44 = param_1;
  local_60 = 0;
  local_70 = param_1 + 0x10;
  do {
    local_50 = (int *)(local_70 + 8);
    local_48 = param_3;
    local_4c = 0;
    local_6c = param_4;
    do {
      if ((*(char *)(local_44 + 0x30) == '\0') && (*local_50 != 0)) {
        local_30 = 0;
        piVar3 = local_48;
        do {
          if (((int *)*piVar3 != (int *)0x0) &&
             ((piVar1 = (int *)*local_50, (int *)*piVar3 == piVar1 ||
              (((((piVar1 != (int *)0x0 && (piVar1[0x20] != 0)) &&
                 ((cVar2 = FUN_0012dfd8(piVar1[0x26]), cVar2 != '\0' &&
                  (((((*(byte *)(piVar1 + 5) & 2) == 0 &&
                     (cVar2 = (**(code **)(*piVar1 + 0x50))(piVar1), cVar2 == '\0')) &&
                    (piVar1 = (int *)*piVar3, piVar1[0x20] != 0)) &&
                   ((cVar2 = FUN_0012dfd8(piVar1[0x26]), cVar2 != '\0' &&
                    ((*(byte *)(piVar1 + 5) & 2) == 0)))))))) &&
                ((cVar2 = (**(code **)(*piVar1 + 0x50))(piVar1), cVar2 == '\0' &&
                 (((*(byte *)(*local_50 + 0x14) & 0x40) != 0 &&
                  ((*(byte *)(*piVar3 + 0x14) & 0x40) != 0)))))) &&
               (*(int *)(*local_50 + 0x94) == *(int *)(*piVar3 + 0x94))))))) {
            local_6c[local_30] = local_6c[local_30] + 1;
            goto LAB_0019f2ab;
          }
          local_30 = local_30 + 1;
          piVar3 = piVar3 + 1;
        } while (local_30 != 3);
        iVar5 = 0;
        piVar3 = local_48;
        while (*piVar3 != 0) {
          iVar5 = iVar5 + 1;
          piVar3 = piVar3 + 1;
          if (iVar5 == 3) {
            param_3 = param_3 + 3;
            local_58 = 1;
            local_68 = 4;
            local_54 = param_3;
            do {
              iVar5 = *(int *)((int)aiStack_28 + local_68);
              *param_4 = iVar5;
              iVar6 = *(int *)((int)aiStack_28 + local_68 + 0xc);
              *piVar4 = iVar6;
              if (iVar5 == 0) {
                param_3[-3] = 0;
              }
              if (iVar6 == 0) {
                *local_54 = 0;
              }
              local_58 = local_58 + 1;
              local_68 = local_68 + 4;
              param_4 = param_4 + 1;
              piVar4 = piVar4 + 1;
              local_54 = local_54 + 1;
              param_3 = param_3 + 1;
            } while (local_58 != 4);
            return 0;
          }
        }
        local_48[iVar5] = *local_50;
        local_6c[iVar5] = local_6c[iVar5] + 1;
      }
LAB_0019f2ab:
      local_50 = local_50 + 3;
      local_4c = local_4c + 0xc;
      local_6c = local_6c + 3;
      local_48 = local_48 + 3;
    } while (local_4c != 0x18);
    local_60 = local_60 + 1;
    local_70 = local_70 + 4;
    local_44 = local_44 + 1;
    if (local_60 == 3) {
      return 1;
    }
  } while( true );
}

/* FUN_0019f54e @ 0x19f54e (1296 bytes) */
int FUN_0019f54e(param_1, param_2)
  int *param_1;
  int *param_2;
{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *local_38;
  int *local_34;
  int *local_30;
  int local_24 [6];
  
  piVar2 = param_2 + 3;
  iVar6 = 0;
  iVar4 = 0;
  piVar3 = piVar2;
  piVar5 = param_2;
  do {
    *(undefined4 *)((int)local_24 + iVar4) = 0;
    *(undefined4 *)((int)local_24 + iVar4 + 0xc) = 0;
    *piVar5 = 0;
    *piVar3 = 0;
    iVar6 = iVar6 + 1;
    iVar4 = iVar4 + 4;
    piVar5 = piVar5 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar6 != 3);
  if (*param_1 != 0) {
    *param_2 = *param_1;
    local_24[0] = local_24[0] + 1;
  }
  if (param_1[1] != 0) {
    *piVar2 = param_1[1];
    local_24[3] = local_24[3] + 1;
  }
  local_34 = param_1;
  local_30 = param_1;
  do {
    if ((param_1[2] == 0) || (param_1[3] == 0)) {
LAB_0019f7b8:
      local_38 = param_1;
      piVar3 = param_1;
      do {
        if ((param_1[4] == 0) || (param_1[5] == 0)) {
LAB_0019f9bc:
          cVar1 = ((int (*)())FUN_0019f00e)(param_1,0,param_2,local_24);
          if (cVar1 != '\0') {
            return 1;
          }
          local_24[3] = local_24[3] + -1;
          if (local_24[3] == 0) {
            *piVar2 = 0;
          }
          iVar4 = local_24[4] + -1;
          if (local_24[4] + -1 == 0) {
            local_24[4] = local_24[4] + -1;
            param_2[4] = 0;
            iVar4 = local_24[4];
          }
        }
        else {
          piVar5 = (int *)*piVar2;
          if ((((piVar5 == (int *)0x0) || (piVar5 == (int *)piVar3[5])) ||
              (((((iVar4 = local_24[4], (int *)piVar3[5] != (int *)0x0 && (piVar5[0x20] != 0)) &&
                 (cVar1 = FUN_0012dfd8(piVar5[0x26]), iVar4 = local_24[4], cVar1 != '\0')) &&
                (((*(byte *)(piVar5 + 5) & 2) == 0 &&
                 (cVar1 = (**(code **)(*piVar5 + 0x50))(piVar5), iVar4 = local_24[4], cVar1 == '\0')
                 ))) && ((piVar5 = (int *)piVar3[5], piVar5[0x20] != 0 &&
                         (((cVar1 = FUN_0012dfd8(piVar5[0x26]), iVar4 = local_24[4], cVar1 != '\0'
                           && ((*(byte *)(piVar5 + 5) & 2) == 0)) &&
                          ((cVar1 = (**(code **)(*piVar5 + 0x50))(piVar5), iVar4 = local_24[4],
                           cVar1 == '\0' &&
                           ((((*(byte *)(*piVar2 + 0x14) & 0x40) != 0 &&
                             ((*(byte *)(piVar3[5] + 0x14) & 0x40) != 0)) &&
                            (*(int *)(*piVar2 + 0x94) == *(int *)(piVar3[5] + 0x94))))))))))))) &&
             (((piVar5 = (int *)param_2[4], piVar5 == (int *)0x0 || (piVar5 == (int *)local_38[4]))
              || ((iVar4 = local_24[4], (int *)local_38[4] != (int *)0x0 &&
                  ((((piVar5[0x20] != 0 &&
                     (cVar1 = FUN_0012dfd8(piVar5[0x26]), iVar4 = local_24[4], cVar1 != '\0')) &&
                    (((*(byte *)(piVar5 + 5) & 2) == 0 &&
                     (((cVar1 = (**(code **)(*piVar5 + 0x50))(piVar5), iVar4 = local_24[4],
                       cVar1 == '\0' && (piVar5 = (int *)local_38[4], piVar5[0x20] != 0)) &&
                      (cVar1 = FUN_0012dfd8(piVar5[0x26]), iVar4 = local_24[4], cVar1 != '\0'))))))
                   && ((((*(byte *)(piVar5 + 5) & 2) == 0 &&
                        (cVar1 = (**(code **)(*piVar5 + 0x50))(piVar5), iVar4 = local_24[4],
                        cVar1 == '\0')) &&
                       (((*(byte *)(param_2[4] + 0x14) & 0x40) != 0 &&
                        (((*(byte *)(local_38[4] + 0x14) & 0x40) != 0 &&
                         (*(int *)(param_2[4] + 0x94) == *(int *)(local_38[4] + 0x94)))))))))))))))
          {
            *piVar2 = piVar3[5];
            param_2[4] = local_38[4];
            local_24[4] = local_24[4] + 1;
            local_24[3] = local_24[3] + 1;
            goto LAB_0019f9bc;
          }
        }
        local_24[4] = iVar4;
        piVar3 = piVar3 + -1;
        local_38 = local_38 + 1;
      } while (param_1 + -2 != piVar3);
      local_24[0] = local_24[0] + -1;
      if (local_24[0] == 0) {
        *param_2 = 0;
      }
      iVar4 = local_24[1] + -1;
      if (local_24[1] + -1 == 0) {
        local_24[1] = local_24[1] + -1;
        param_2[1] = 0;
        iVar4 = local_24[1];
      }
    }
    else {
      piVar3 = (int *)*param_2;
      if ((((piVar3 == (int *)0x0) || (piVar3 == (int *)local_34[3])) ||
          ((((((iVar4 = local_24[1], (int *)local_34[3] != (int *)0x0 && (piVar3[0x20] != 0)) &&
              (cVar1 = FUN_0012dfd8(piVar3[0x26]), iVar4 = local_24[1], cVar1 != '\0')) &&
             (((*(byte *)(piVar3 + 5) & 2) == 0 &&
              (cVar1 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar4 = local_24[1], cVar1 == '\0'))))
            && (piVar3 = (int *)local_34[3], piVar3[0x20] != 0)) &&
           ((((cVar1 = FUN_0012dfd8(piVar3[0x26]), iVar4 = local_24[1], cVar1 != '\0' &&
              ((*(byte *)(piVar3 + 5) & 2) == 0)) &&
             (cVar1 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar4 = local_24[1], cVar1 == '\0')) &&
            ((((*(byte *)(*param_2 + 0x14) & 0x40) != 0 &&
              ((*(byte *)(local_34[3] + 0x14) & 0x40) != 0)) &&
             (*(int *)(*param_2 + 0x94) == *(int *)(local_34[3] + 0x94))))))))) &&
         (((piVar3 = (int *)param_2[1], piVar3 == (int *)0x0 || (piVar3 == (int *)local_30[2])) ||
          ((((iVar4 = local_24[1], (int *)local_30[2] != (int *)0x0 &&
             ((piVar3[0x20] != 0 &&
              (cVar1 = FUN_0012dfd8(piVar3[0x26]), iVar4 = local_24[1], cVar1 != '\0')))) &&
            ((*(byte *)(piVar3 + 5) & 2) == 0)) &&
           (((((cVar1 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar4 = local_24[1], cVar1 == '\0' &&
               (piVar3 = (int *)local_30[2], piVar3[0x20] != 0)) &&
              (cVar1 = FUN_0012dfd8(piVar3[0x26]), iVar4 = local_24[1], cVar1 != '\0')) &&
             (((*(byte *)(piVar3 + 5) & 2) == 0 &&
              (cVar1 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar4 = local_24[1], cVar1 == '\0'))))
            && (((*(byte *)(param_2[1] + 0x14) & 0x40) != 0 &&
                (((*(byte *)(local_30[2] + 0x14) & 0x40) != 0 &&
                 (*(int *)(param_2[1] + 0x94) == *(int *)(local_30[2] + 0x94))))))))))))) {
        *param_2 = local_34[3];
        param_2[1] = local_30[2];
        local_24[0] = local_24[0] + 1;
        local_24[1] = local_24[1] + 1;
        goto LAB_0019f7b8;
      }
    }
    local_24[1] = iVar4;
    local_34 = local_34 + -1;
    local_30 = local_30 + 1;
    if (param_1 + -2 == local_34) {
      return 0;
    }
  } while( true );
}

/* FUN_0019fa5e @ 0x19fa5e (124 bytes) */
int FUN_0019fa5e(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int aiStack_28 [7];
  
  piVar2 = aiStack_28 + 1;
  cVar3 = ((int (*)())FUN_0019f54e)(param_1,piVar2);
  *param_2 = 0;
  param_2[1] = 0;
  if (cVar3 != '\0') {
    iVar4 = 1;
    iVar5 = 4;
    do {
      if (*(int *)(iVar5 + -4 + (int)piVar2) == 0) {
        *param_2 = *param_2 + 1;
        iVar1 = *(int *)(iVar5 + 8 + (int)piVar2);
      }
      else {
        iVar1 = *(int *)(iVar5 + 8 + (int)piVar2);
      }
      if (iVar1 == 0) {
        param_2[1] = param_2[1] + 1;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar4 != 4);
  }
  return cVar3;
}

/* FUN_0019fada @ 0x19fada (292 bytes) */
int FUN_0019fada(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int local_10;
  
  piVar3 = (int *)(param_1 + 0x18 + param_3 * 0xc);
  local_10 = 0;
  while (((int *)*piVar3 == (int *)0x0 ||
         ((param_2 != (int *)*piVar3 &&
          (((((param_2 == (int *)0x0 || (param_2[0x20] == 0)) ||
             (cVar2 = FUN_0012dfd8(param_2[0x26]), cVar2 == '\0')) ||
            (((((*(byte *)(param_2 + 5) & 2) != 0 ||
               (cVar2 = (**(code **)(*param_2 + 0x50))(param_2), cVar2 != '\0')) ||
              ((piVar1 = (int *)*piVar3, piVar1[0x20] == 0 ||
               ((cVar2 = FUN_0012dfd8(piVar1[0x26]), cVar2 == '\0' ||
                ((*(byte *)(piVar1 + 5) & 2) != 0)))))) ||
             (cVar2 = (**(code **)(*piVar1 + 0x50))(piVar1), cVar2 != '\0')))) ||
           ((((*(byte *)(param_2 + 5) & 0x40) == 0 || ((*(byte *)(*piVar3 + 0x14) & 0x40) == 0)) ||
            (param_2[0x25] != *(int *)(*piVar3 + 0x94)))))))))) {
    local_10 = local_10 + 1;
    piVar3 = piVar3 + 1;
    if (local_10 == 3) {
      piVar3 = (int *)(param_1 + 0x18 + param_3 * 0xc);
      iVar4 = 0;
      do {
        if (*piVar3 == 0) {
          *(int **)(param_1 + 0x18 + (param_3 * 3 + iVar4) * 4) = param_2;
          return 1;
        }
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar4 != 3);
      return 0;
    }
  }
  return 1;
}

/* FUN_0019fbfe @ 0x19fbfe (1011 bytes) */
int FUN_0019fbfe(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int local_20;
  int local_1c;
  int local_10;
  
  local_10 = param_1;
  local_20 = 0;
  iVar5 = param_1;
  while (*(char *)(local_10 + 0x30) != '\0') {
    piVar6 = *(int **)(iVar5 + 0x18);
    if (((param_2 == piVar6) ||
        ((((((piVar6 != (int *)0x0 && (param_2 != (int *)0x0)) && (piVar6[0x20] != 0)) &&
           ((cVar3 = FUN_0012dfd8(piVar6[0x26]), cVar3 != '\0' && ((*(byte *)(piVar6 + 5) & 2) == 0)
            ))) && ((((cVar3 = (**(code **)(*piVar6 + 0x50))(piVar6), cVar3 == '\0' &&
                      ((param_2[0x20] != 0 && (cVar3 = FUN_0012dfd8(param_2[0x26]), cVar3 != '\0')))
                      ) && ((*(byte *)(param_2 + 5) & 2) == 0)) &&
                    (((cVar3 = (**(code **)(*param_2 + 0x50))(param_2), cVar3 == '\0' &&
                      ((*(byte *)(*(int *)(iVar5 + 0x18) + 0x14) & 0x40) != 0)) &&
                     ((*(byte *)(param_2 + 5) & 0x40) != 0)))))) &&
         (*(int *)(*(int *)(iVar5 + 0x18) + 0x94) == param_2[0x25])))) &&
       ((piVar6 = *(int **)(iVar5 + 0x24), param_3 == piVar6 ||
        (((((piVar6 != (int *)0x0 && (param_3 != (int *)0x0)) &&
           ((piVar6[0x20] != 0 &&
            ((cVar3 = FUN_0012dfd8(piVar6[0x26]), cVar3 != '\0' &&
             ((*(byte *)(piVar6 + 5) & 2) == 0)))))) &&
          (cVar3 = (**(code **)(*piVar6 + 0x50))(piVar6), cVar3 == '\0')) &&
         (((((param_3[0x20] != 0 && (cVar3 = FUN_0012dfd8(param_3[0x26]), cVar3 != '\0')) &&
            ((*(byte *)(param_3 + 5) & 2) == 0)) &&
           ((cVar3 = (**(code **)(*param_3 + 0x50))(param_3), cVar3 == '\0' &&
            ((*(byte *)(*(int *)(iVar5 + 0x24) + 0x14) & 0x40) != 0)))) &&
          (((*(byte *)(param_3 + 5) & 0x40) != 0 &&
           (*(int *)(*(int *)(iVar5 + 0x24) + 0x94) == param_3[0x25])))))))))) goto LAB_0019fc54;
    local_20 = local_20 + 1;
    local_10 = local_10 + 1;
    iVar5 = iVar5 + 4;
    if (local_20 == 3) goto LAB_0019fc54;
  }
  iVar5 = *(int *)(param_1 + 0x18 + local_20 * 4);
  iVar1 = *(int *)(param_1 + 0x24 + local_20 * 4);
  *(int **)(param_1 + 0x18 + local_20 * 4) = param_2;
  *(int **)(param_1 + 0x24 + local_20 * 4) = param_3;
  *(undefined1 *)(local_20 + 0x30 + param_1) = 1;
  local_1c = local_20 + 1;
  if (local_1c < 3) {
    piVar6 = (int *)(param_1 + 0x18 + local_1c * 4);
    do {
      piVar2 = (int *)*piVar6;
      if ((piVar2 != (int *)0x0) &&
         ((param_2 == piVar2 ||
          ((((param_2 != (int *)0x0 && (piVar2[0x20] != 0)) &&
            (cVar3 = FUN_0012dfd8(piVar2[0x26]), cVar3 != '\0')) &&
           (((((*(byte *)(piVar2 + 5) & 2) == 0 &&
              (cVar3 = (**(code **)(*piVar2 + 0x50))(piVar2), cVar3 == '\0')) &&
             ((param_2[0x20] != 0 &&
              ((cVar3 = FUN_0012dfd8(param_2[0x26]), cVar3 != '\0' &&
               ((*(byte *)(param_2 + 5) & 2) == 0)))))) &&
            ((cVar3 = (**(code **)(*param_2 + 0x50))(param_2), cVar3 == '\0' &&
             ((((*(byte *)(*piVar6 + 0x14) & 0x40) != 0 && ((*(byte *)(param_2 + 5) & 0x40) != 0))
              && (*(int *)(*piVar6 + 0x94) == param_2[0x25])))))))))))) {
        *piVar6 = 0;
      }
      piVar2 = (int *)piVar6[3];
      if ((piVar2 != (int *)0x0) &&
         ((param_3 == piVar2 ||
          ((((param_3 != (int *)0x0 && (piVar2[0x20] != 0)) &&
            ((cVar3 = FUN_0012dfd8(piVar2[0x26]), cVar3 != '\0' &&
             (((*(byte *)(piVar2 + 5) & 2) == 0 &&
              (cVar3 = (**(code **)(*piVar2 + 0x50))(piVar2), cVar3 == '\0')))))) &&
           (((param_3[0x20] != 0 &&
             ((((cVar3 = FUN_0012dfd8(param_3[0x26]), cVar3 != '\0' &&
                ((*(byte *)(param_3 + 5) & 2) == 0)) &&
               (cVar3 = (**(code **)(*param_3 + 0x50))(param_3), cVar3 == '\0')) &&
              (((*(byte *)(piVar6[3] + 0x14) & 0x40) != 0 && ((*(byte *)(param_3 + 5) & 0x40) != 0))
              )))) && (*(int *)(piVar6[3] + 0x94) == param_3[0x25])))))))) {
        piVar6[3] = 0;
      }
      local_1c = local_1c + 1;
      piVar6 = piVar6 + 1;
    } while (local_1c != 3);
  }
  if (((iVar5 == 0) || (cVar3 = ((int (*)())FUN_0019fada)(param_1,iVar5,0), cVar3 != '\0')) &&
     ((iVar1 == 0 || (cVar3 = ((int (*)())FUN_0019fada)(param_1,iVar1,1), cVar3 != '\0')))) {
LAB_0019fc54:
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

/* FUN_0019fff2 @ 0x19fff2 (1470 bytes) */
int FUN_0019fff2(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int *param_3;
  int param_4;
{
  int iVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_1 + 8 + param_4 * 8);
  if ((piVar5 == (int *)0x0) || (*(int *)(param_1 + 0xc + param_4 * 8) == 0)) {
    piVar5 = *(int **)(param_1 + param_4 * 4);
    if ((piVar5 == (int *)0x0) || (piVar5 == param_2)) {
LAB_001a0142:
      cVar3 = ((int (*)())FUN_0019fada)(param_1,param_2,param_4);
      if ((cVar3 != '\0') && (cVar3 = ((int (*)())FUN_0019fada)(param_1,param_3,param_4), cVar3 != '\0')) {
        *(int **)(param_1 + 8 + param_4 * 8) = param_2;
        *(int **)(param_1 + 0xc + param_4 * 8) = param_3;
        return 1;
      }
    }
    else {
      if ((param_2 != (int *)0x0) && (piVar5[0x20] != 0)) {
        cVar3 = FUN_0012dfd8(piVar5[0x26]);
        if (cVar3 == '\0') {
LAB_001a0482:
          piVar5 = *(int **)(param_1 + param_4 * 4);
        }
        else if ((*(byte *)(piVar5 + 5) & 2) == 0) {
          cVar3 = (**(code **)(*piVar5 + 0x50))(piVar5);
          if (cVar3 == '\0') {
            if (param_2[0x20] != 0) {
              cVar3 = FUN_0012dfd8(param_2[0x26]);
              if (cVar3 == '\0') goto LAB_001a037d;
              if ((*(byte *)(param_2 + 5) & 2) != 0) goto LAB_001a04cc;
              cVar3 = (**(code **)(*param_2 + 0x50))(param_2);
              if (cVar3 == '\0') {
                piVar5 = *(int **)(param_1 + param_4 * 4);
                if ((((*(byte *)(piVar5 + 5) & 0x40) != 0) && ((*(byte *)(param_2 + 5) & 0x40) != 0)
                    ) && (piVar5[0x25] == param_2[0x25])) goto LAB_001a0142;
                goto LAB_001a0088;
              }
            }
            goto LAB_001a0482;
          }
LAB_001a04cc:
          piVar5 = *(int **)(param_1 + param_4 * 4);
        }
        else {
LAB_001a037d:
          piVar5 = *(int **)(param_1 + param_4 * 4);
        }
      }
LAB_001a0088:
      if ((param_3 == piVar5) ||
         (((((piVar5 != (int *)0x0 && (param_3 != (int *)0x0)) &&
            ((piVar5[0x20] != 0 &&
             ((cVar3 = FUN_0012dfd8(piVar5[0x26]), cVar3 != '\0' &&
              ((*(byte *)(piVar5 + 5) & 2) == 0)))))) &&
           ((cVar3 = (**(code **)(*piVar5 + 0x50))(piVar5), cVar3 == '\0' &&
            ((((param_3[0x20] != 0 && (cVar3 = FUN_0012dfd8(param_3[0x26]), cVar3 != '\0')) &&
              ((*(byte *)(param_3 + 5) & 2) == 0)) &&
             ((cVar3 = (**(code **)(*param_3 + 0x50))(param_3), cVar3 == '\0' &&
              (iVar1 = *(int *)(param_1 + param_4 * 4), (*(byte *)(iVar1 + 0x14) & 0x40) != 0)))))))
           ) && (((*(byte *)(param_3 + 5) & 0x40) != 0 && (*(int *)(iVar1 + 0x94) == param_3[0x25]))
                )))) goto LAB_001a0142;
    }
LAB_001a0050:
    uVar4 = 0;
  }
  else {
    if (piVar5 == param_2) {
LAB_001a0414:
      piVar2 = *(int **)(param_1 + 0xc + param_4 * 8);
      if (param_3 != piVar2) {
        if (((piVar2 != (int *)0x0) && (param_3 != (int *)0x0)) && (piVar2[0x20] != 0)) {
          cVar3 = FUN_0012dfd8(piVar2[0x26]);
          if (cVar3 == '\0') {
LAB_001a01c2:
            piVar5 = *(int **)(param_1 + 8 + param_4 * 8);
          }
          else if ((*(byte *)(piVar2 + 5) & 2) == 0) {
            cVar3 = (**(code **)(*piVar2 + 0x50))(piVar2);
            if (cVar3 == '\0') {
              if (param_3[0x20] == 0) goto LAB_001a01c2;
              cVar3 = FUN_0012dfd8(param_3[0x26]);
              if (cVar3 == '\0') goto LAB_001a0464;
              if ((*(byte *)(param_3 + 5) & 2) == 0) {
                cVar3 = (**(code **)(*param_3 + 0x50))(param_3);
                if (cVar3 != '\0') goto LAB_001a01c2;
                iVar1 = *(int *)(param_1 + 0xc + param_4 * 8);
                if ((*(byte *)(iVar1 + 0x14) & 0x40) == 0) goto LAB_001a0464;
                if ((*(byte *)(param_3 + 5) & 0x40) != 0) {
                  if (*(int *)(iVar1 + 0x94) == param_3[0x25]) goto LAB_001a0353;
                  piVar5 = *(int **)(param_1 + 8 + param_4 * 8);
                  goto LAB_001a002e;
                }
              }
            }
LAB_001a0473:
            piVar5 = *(int **)(param_1 + 8 + param_4 * 8);
          }
          else {
LAB_001a0464:
            piVar5 = *(int **)(param_1 + 8 + param_4 * 8);
          }
        }
        goto LAB_001a002e;
      }
    }
    else {
      if ((param_2 != (int *)0x0) && (piVar5[0x20] != 0)) {
        cVar3 = FUN_0012dfd8(piVar5[0x26]);
        if (cVar3 != '\0') {
          if ((*(byte *)(piVar5 + 5) & 2) != 0) goto LAB_001a01c2;
          cVar3 = (**(code **)(*piVar5 + 0x50))(piVar5);
          if (cVar3 != '\0') goto LAB_001a0464;
          if (param_2[0x20] != 0) {
            cVar3 = FUN_0012dfd8(param_2[0x26]);
            if (cVar3 == '\0') goto LAB_001a01c2;
            if ((*(byte *)(param_2 + 5) & 2) != 0) goto LAB_001a0464;
            cVar3 = (**(code **)(*param_2 + 0x50))(param_2);
            if (cVar3 == '\0') {
              piVar5 = *(int **)(param_1 + 8 + param_4 * 8);
              if ((((*(byte *)(piVar5 + 5) & 0x40) != 0) && ((*(byte *)(param_2 + 5) & 0x40) != 0))
                 && (piVar5[0x25] == param_2[0x25])) goto LAB_001a0414;
              goto LAB_001a002e;
            }
          }
        }
        goto LAB_001a0473;
      }
LAB_001a002e:
      if (((param_3 != piVar5) &&
          ((((piVar5 == (int *)0x0 || (param_3 == (int *)0x0)) ||
            ((((piVar5[0x20] == 0 ||
               (((((cVar3 = FUN_0012dfd8(piVar5[0x26]), cVar3 == '\0' ||
                   ((*(byte *)(piVar5 + 5) & 2) != 0)) ||
                  (cVar3 = (**(code **)(*piVar5 + 0x50))(piVar5), cVar3 != '\0')) ||
                 ((param_3[0x20] == 0 || (cVar3 = FUN_0012dfd8(param_3[0x26]), cVar3 == '\0')))) ||
                ((*(byte *)(param_3 + 5) & 2) != 0)))) ||
              ((cVar3 = (**(code **)(*param_3 + 0x50))(param_3), cVar3 != '\0' ||
               (iVar1 = *(int *)(param_1 + 8 + param_4 * 8), (*(byte *)(iVar1 + 0x14) & 0x40) == 0))
              )) || ((*(byte *)(param_3 + 5) & 0x40) == 0)))) ||
           (*(int *)(iVar1 + 0x94) != param_3[0x25])))) ||
         ((piVar5 = *(int **)(param_1 + 0xc + param_4 * 8), param_2 != piVar5 &&
          (((((piVar5 == (int *)0x0 || (param_2 == (int *)0x0)) || (piVar5[0x20] == 0)) ||
            ((((cVar3 = FUN_0012dfd8(piVar5[0x26]), cVar3 == '\0' ||
               ((*(byte *)(piVar5 + 5) & 2) != 0)) ||
              ((cVar3 = (**(code **)(*piVar5 + 0x50))(piVar5), cVar3 != '\0' ||
               ((param_2[0x20] == 0 || (cVar3 = FUN_0012dfd8(param_2[0x26]), cVar3 == '\0')))))) ||
             ((*(byte *)(param_2 + 5) & 2) != 0)))) ||
           ((((cVar3 = (**(code **)(*param_2 + 0x50))(param_2), cVar3 != '\0' ||
              (iVar1 = *(int *)(param_1 + 0xc + param_4 * 8), (*(byte *)(iVar1 + 0x14) & 0x40) == 0)
              ) || ((*(byte *)(param_2 + 5) & 0x40) == 0)) ||
            (*(int *)(iVar1 + 0x94) != param_2[0x25])))))))) goto LAB_001a0050;
    }
LAB_001a0353:
    uVar4 = 1;
  }
  return uVar4;
}

/* FUN_001a05b0 @ 0x1a05b0 (237 bytes) */
int FUN_001a05b0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int *piVar1;
  int iVar2;
  char cVar3;
  
  piVar1 = *(int **)(param_1 + param_3 * 4);
  if (piVar1 == (int *)0x0) {
    cVar3 = ((int (*)())FUN_0019fada)(param_1,param_2,param_3);
    if (cVar3 != '\0') {
      *(int **)(param_1 + param_3 * 4) = param_2;
      return 1;
    }
  }
  else {
    if (piVar1 == param_2) {
      return 1;
    }
    if (((((param_2 != (int *)0x0) && (piVar1[0x20] != 0)) &&
         (cVar3 = FUN_0012dfd8(piVar1[0x26]), cVar3 != '\0')) &&
        (((((*(byte *)(piVar1 + 5) & 2) == 0 &&
           (cVar3 = (**(code **)(*piVar1 + 0x50))(piVar1), cVar3 == '\0')) &&
          ((param_2[0x20] != 0 &&
           ((cVar3 = FUN_0012dfd8(param_2[0x26]), cVar3 != '\0' &&
            ((*(byte *)(param_2 + 5) & 2) == 0)))))) &&
         (cVar3 = (**(code **)(*param_2 + 0x50))(param_2), cVar3 == '\0')))) &&
       (((iVar2 = *(int *)(param_1 + param_3 * 4), (*(byte *)(iVar2 + 0x14) & 0x40) != 0 &&
         ((*(byte *)(param_2 + 5) & 0x40) != 0)) && (*(int *)(iVar2 + 0x94) == param_2[0x25])))) {
      return 1;
    }
  }
  return 0;
}

/* FUN_001a069e @ 0x1a069e (1454 bytes) */
int FUN_001a069e(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int *param_2;
  int *param_3;
  undefined4 param_4;
  int param_5;
{
  bool bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int local_40;
  int *local_38;
  int local_30;
  int local_24;
  undefined4 local_20;
  
  iVar4 = *(int *)(param_1[0x22] + 8);
  if ((((iVar4 == 0x9e) || (iVar4 == 0xa0)) || (iVar4 == 0x9f)) || (iVar4 == 0xa1)) {
    piVar5 = (int *)FUN_0010b180(param_1,1);
    cVar2 = (**(code **)(*piVar5 + 0x5c))(piVar5);
    if (cVar2 != '\0') {
      return 0;
    }
    iVar4 = FUN_0010b0f4(param_1,0);
    if (((*(char *)(iVar4 + 0x10) == '\0') ||
        (iVar4 = FUN_0010b0f4(param_1,0), *(char *)(iVar4 + 0x11) == '\0')) ||
       (iVar4 = FUN_0010b0f4(param_1,0), *(char *)(iVar4 + 0x12) == '\0')) {
      uVar9 = FUN_0010b180(param_1,1);
      cVar2 = ((int (*)())FUN_001a05b0)(param_4,uVar9,0);
      if (cVar2 == '\0') {
        return 0;
      }
    }
    iVar4 = FUN_0010b0f4(param_1,0);
    if (*(char *)(iVar4 + 0x13) == '\0') {
      uVar9 = FUN_0010b180(param_1,1);
      cVar2 = ((int (*)())FUN_001a05b0)(param_4,uVar9,1);
      if (cVar2 == '\0') {
        return 0;
      }
    }
    return 1;
  }
  local_40 = 1;
  iVar4 = (**(code **)(*param_1 + 0x14))(param_1);
  if (0 < iVar4) {
    do {
      piVar5 = (int *)FUN_0010b180(param_1,local_40);
      cVar2 = (**(code **)(*piVar5 + 0x60))(piVar5);
      if (cVar2 != '\0') {
        piVar5 = (int *)FUN_0010b180(piVar5,1);
        (**(code **)(*piVar5 + 0x60))(piVar5);
      }
      cVar3 = (**(code **)(*piVar5 + 0x5c))(piVar5);
      if (cVar3 != '\0') {
        if (((piVar5[0x56] != 0) && (param_1[0x56] != 0)) && (param_1[0x56] != piVar5[0x56])) {
          FUN_001a7d72(piVar5);
          FUN_000e9596(param_1[0x56],param_1[1],piVar5);
        }
        iVar4 = *(int *)(piVar5[0x22] + 8);
        piVar6 = param_1;
        iVar7 = local_40;
        if (cVar2 != '\0') {
          piVar6 = (int *)FUN_0010b180(param_1,local_40);
          iVar7 = 1;
        }
        iVar7 = FUN_0010b0f4(piVar6,iVar7);
        uVar8 = FUN_000f5bdc(*(undefined4 *)(iVar7 + 0x10));
        if ((uVar8 & 0xffffff) != 0) {
          if ((-1 < *param_2) && (iVar4 != *param_2)) {
            return 0;
          }
          *param_2 = iVar4;
          iVar7 = (**(code **)(*piVar5 + 0x14))(piVar5);
          if (iVar7 == 1) {
            uVar9 = FUN_0010b180(piVar5,1);
            cVar2 = ((int (*)())FUN_001a05b0)(param_4,uVar9,0);
          }
          else {
            uVar9 = FUN_0010b180(piVar5,2);
            uVar10 = FUN_0010b180(piVar5,1);
            cVar2 = ((int (*)())FUN_0019fff2)(param_4,uVar10,uVar9,0);
          }
          if (cVar2 == '\0') {
            return 0;
          }
        }
        if ((char)(uVar8 >> 0x18) != '\0') {
          if ((-1 < *param_3) && (iVar4 != *param_3)) {
            return 0;
          }
          *param_3 = iVar4;
          iVar4 = (**(code **)(*piVar5 + 0x14))(piVar5);
          if (iVar4 == 1) {
            uVar9 = FUN_0010b180(piVar5,1);
            cVar2 = ((int (*)())FUN_001a05b0)(param_4,uVar9,1);
          }
          else {
            uVar9 = FUN_0010b180(piVar5,2);
            uVar10 = FUN_0010b180(piVar5,1);
            cVar2 = ((int (*)())FUN_0019fff2)(param_4,uVar10,uVar9,1);
          }
          if (cVar2 == '\0') {
            return 0;
          }
        }
      }
      local_40 = local_40 + 1;
      iVar4 = (**(code **)(*param_1 + 0x14))(param_1);
    } while (local_40 <= iVar4);
  }
  local_30 = 1;
LAB_001a08ca:
  do {
    iVar4 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar4 < local_30) {
      return 1;
    }
    piVar5 = (int *)FUN_0010b180(param_1,local_30);
    local_38 = param_1;
    cVar2 = (**(code **)(*piVar5 + 0x60))(piVar5);
    if (cVar2 == '\0') {
      bVar1 = false;
      iVar4 = local_30;
      piVar6 = piVar5;
    }
    else {
      piVar6 = (int *)FUN_0010b180(piVar5,1);
      (**(code **)(*piVar6 + 0x60))(piVar6);
      local_38 = piVar5;
      if (piVar6[0x26] == 0x33) {
        iVar4 = FUN_0010b0f4(piVar5,0);
        cVar2 = FUN_000f7e7e(piVar5,1,*(undefined4 *)(iVar4 + 0x10),&local_24);
        if (((cVar2 != '\0') && (local_24 == 2)) &&
           (cVar2 = (**(code **)(**(int **)(param_5 + 0x54) + 0xf0))
                              (*(int **)(param_5 + 0x54),local_20), cVar2 != '\0')) {
          local_30 = local_30 + 1;
          goto LAB_001a08ca;
        }
        cVar2 = FUN_0010a62e(piVar5,*(undefined4 *)(param_5 + 0x3f4));
        if (cVar2 == '\0') {
          iVar4 = 1;
          bVar1 = true;
          goto LAB_001a0911;
        }
      }
      iVar4 = 1;
      bVar1 = false;
    }
LAB_001a0911:
    cVar2 = (**(code **)(*piVar6 + 0x5c))(piVar6);
    if ((cVar2 == '\0') && ((bVar1 || (piVar6[0x26] != 0x33)))) {
      iVar4 = FUN_0010b0f4(local_38,iVar4);
      uVar8 = FUN_000f5bdc(*(undefined4 *)(iVar4 + 0x10));
      cVar2 = (char)(uVar8 >> 0x18);
      if ((uVar8 & 0xffffff) == 0) {
        if (cVar2 == '\0') goto LAB_001a0973;
        cVar2 = ((int (*)())FUN_0019fada)(param_4,piVar6,1);
        if (cVar2 == '\0') {
          return 0;
        }
        local_30 = local_30 + 1;
      }
      else {
        if (cVar2 != '\0') {
          cVar2 = ((int (*)())FUN_0019fbfe)(param_4,piVar6,piVar6);
          if (cVar2 == '\0') {
            return 0;
          }
          goto LAB_001a0973;
        }
        cVar2 = ((int (*)())FUN_0019fada)(param_4,piVar6,0);
        if (cVar2 == '\0') {
          return 0;
        }
        local_30 = local_30 + 1;
      }
    }
    else {
LAB_001a0973:
      local_30 = local_30 + 1;
    }
  } while( true );
}

/* FUN_001a0c4c @ 0x1a0c4c (104 bytes) */
int FUN_001a0c4c(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  char cVar1;
  undefined1 uVar2;
  undefined1 local_50 [52];
  undefined1 local_1c [8];
  undefined4 local_14;
  undefined4 local_10 [2];
  
  local_10[0] = 0xffffffff;
  local_14 = 0xffffffff;
  FUN_0019ca40(local_50);
  cVar1 = ((int (*)())FUN_001a069e)(param_1,local_10,&local_14,local_50,param_2);
  if (cVar1 == '\0') {
    return 0;
  }
  uVar2 = ((int (*)())FUN_0019fa5e)(local_50,local_1c);
  return uVar2;
}

/* FUN_001a0cb4 @ 0x1a0cb4 (1826 bytes) */
int FUN_001a0cb4(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  uint *puVar13;
  int iVar14;
  uint local_88;
  int local_80;
  int local_7c;
  undefined4 local_78;
  undefined1 local_71;
  uint local_4c;
  uint local_48;
  int local_44;
  undefined4 local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  undefined4 local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  undefined4 local_20;
  
  iVar12 = *(int *)(param_2 + 0x38);
  cVar5 = (**(code **)(*param_1 + 0x30))(param_1,iVar12);
  if ((cVar5 == '\0') ||
     ((iVar14 = *(int *)(PTR_DAT_00213a35 + *(int *)(*(int *)(iVar12 + 0x88) + 8) * 0x38 + 0x34),
      *(int *)(param_2 + 0x60) != 0 && (iVar6 = FUN_000f60f4(iVar12), iVar6 != 1)))) {
    return 0;
  }
  iVar6 = FUN_0010b0f4(iVar12,0);
  if (*(char *)(iVar6 + 0x13) == '\0') {
    if (iVar14 == 0) {
      iVar14 = FUN_0010b0f4(iVar12,0);
      local_78 = FUN_000f5970(*(undefined4 *)(iVar14 + 0x10));
      local_80 = 3;
      local_7c = 3;
    }
    else if (iVar14 - 1U < 2) {
      local_80 = 3;
      local_7c = 3;
      local_78 = 0;
    }
    else {
      local_80 = 3;
      local_7c = 3;
      local_78 = 0xffffffff;
    }
  }
  else if ((iVar14 == 5) && (*(int *)(param_2 + 0x60) == 0)) {
    local_80 = 0;
    local_7c = 2;
    local_78 = 3;
  }
  else {
    iVar14 = FUN_0010b0f4(iVar12,0);
    local_80 = FUN_000f5950(*(undefined4 *)(iVar14 + 0x10));
    local_78 = 3;
    local_7c = local_80;
  }
  local_20 = *(undefined4 *)(param_1[2] + 0xbc);
  local_28 = 0;
  local_2c = 2;
  local_24 = FUN_001a7bca(local_20,8);
  local_30 = *(undefined4 *)(param_1[2] + 0xbc);
  local_38 = 0;
  local_3c = 2;
  local_34 = FUN_001a7bca(local_30,8);
  local_40 = *(undefined4 *)(param_1[2] + 0xbc);
  local_48 = 0;
  local_4c = 2;
  local_44 = FUN_001a7bca(local_40,8);
  puVar13 = *(uint **)(param_2 + 0x40);
  uVar1 = puVar13[1];
  if ((int)uVar1 < 1) {
LAB_001a10f8:
    local_71 = 1;
joined_r0x001a1101:
    while (local_28 != 0) {
      uVar1 = local_28 - 1;
      if (uVar1 < local_28) {
        piVar11 = (int *)(local_24 + uVar1 * 4);
      }
      else {
        piVar11 = (int *)0x0;
      }
      iVar12 = *piVar11;
      FUN_001a7f3c(&local_2c,uVar1);
      uVar1 = local_38 - 1;
      if (uVar1 < local_38) {
        piVar11 = (int *)(local_34 + uVar1 * 4);
      }
      else {
        piVar11 = (int *)0x0;
      }
      iVar14 = *piVar11;
      FUN_001a7f3c(&local_3c,uVar1);
      uVar1 = local_48 - 1;
      if (uVar1 < local_48) {
        puVar10 = (undefined4 *)(local_44 + uVar1 * 4);
      }
      else {
        puVar10 = (undefined4 *)0x0;
      }
      uVar2 = *puVar10;
      FUN_001a7f3c(&local_4c,uVar1);
      if (iVar14 == 0) {
        *(undefined4 *)(iVar12 + 0x9c) = uVar2;
      }
      else {
        iVar12 = FUN_0010b0f4(iVar12,iVar14);
        *(undefined4 *)(iVar12 + 0x10) = uVar2;
      }
    }
    FUN_001a7aba(local_40,local_44);
    FUN_001a7aba(local_30,local_34);
    FUN_001a7aba(local_20,local_24);
    return local_71;
  }
  local_88 = 0;
  if (*puVar13 == 0) goto LAB_001a109e;
LAB_001a0e30:
  uVar9 = puVar13[1];
  if (uVar9 <= local_88) {
    _memset((void *)(puVar13[2] + uVar9 * 4),0,(local_88 - uVar9) * 4 + 4);
    puVar13[1] = local_88 + 1;
  }
  piVar11 = (int *)(puVar13[2] + local_88 * 4);
  do {
    iVar14 = *piVar11;
    if (*(int *)(iVar14 + 8) == 0) {
      puVar13 = *(uint **)(param_2 + 0x40);
      if (local_88 < *puVar13) {
        uVar9 = puVar13[1];
        if (uVar9 <= local_88) {
          _memset((void *)(puVar13[2] + uVar9 * 4),0,(local_88 - uVar9) * 4 + 4);
          puVar13[1] = local_88 + 1;
        }
        piVar11 = (int *)(puVar13[2] + local_88 * 4);
      }
      else {
        piVar11 = (int *)FUN_001a7f7c(puVar13,local_88);
      }
      piVar11 = *(int **)(*(int *)(*piVar11 + 4) + 0x38);
      if ((((*(byte *)((int)piVar11 + 0x15) & 2) != 0) &&
          (iVar6 = FUN_0010b180(piVar11,piVar11[0x21]), iVar12 == iVar6)) ||
         ((cVar5 = (**(code **)(*piVar11 + 0x28))(piVar11), cVar5 != '\0' &&
          ((*(byte *)(*(int *)(param_1[2] + 0x54) + 9) & 8) == 0)))) {
LAB_001a12a1:
        local_71 = 0;
        goto joined_r0x001a1101;
      }
      cVar5 = (**(code **)(*piVar11 + 0x5c))(piVar11);
      if (cVar5 != '\0') {
        iVar14 = (**(code **)(*piVar11 + 0x14))(piVar11);
        if (1 < iVar14) {
          iVar14 = FUN_0010b180(piVar11,1);
          iVar6 = FUN_0010b180(piVar11,2);
          if (iVar14 != iVar6) goto LAB_001a12a1;
        }
        goto LAB_001a1078;
      }
      iVar6 = piVar11[0x22];
      if ((((*(int *)(iVar6 + 8) == 0x9e) || (*(int *)(iVar6 + 8) == 0xa0)) ||
          (*(int *)(iVar6 + 8) == 0x9f)) || (*(int *)(iVar6 + 8) == 0xa1)) goto LAB_001a12a1;
      iVar6 = *(int *)(iVar14 + 0x10);
      if ((iVar6 < 1) || (*(int *)(iVar14 + 0x14) != 0)) {
        piVar7 = (int *)FUN_0010b180(piVar11,iVar6);
        cVar5 = (**(code **)(*piVar7 + 0x5c))(piVar7);
        if (cVar5 != '\0') {
          iVar6 = *(int *)(iVar14 + 0x10);
          goto LAB_001a0f47;
        }
      }
      else {
LAB_001a0f47:
        iVar6 = FUN_0010b0f4(piVar11,iVar6);
        uVar2 = *(undefined4 *)(iVar6 + 0x10);
        bVar4 = false;
        iVar6 = 0;
        do {
          iVar8 = FUN_0010b0f4(piVar11,*(undefined4 *)(iVar14 + 0x10));
          uVar9 = (uint)*(byte *)(iVar6 + 0x10 + iVar8);
          if ((local_80 <= (int)uVar9) && ((int)uVar9 <= local_7c)) {
            (**(code **)(*piVar11 + 0x88))(piVar11,*(undefined4 *)(iVar14 + 0x10),iVar6,local_78);
            bVar4 = true;
          }
          uVar9 = local_28;
          iVar6 = iVar6 + 1;
        } while (iVar6 != 4);
        if (bVar4) {
          if (local_28 < local_2c) {
            iVar6 = local_28 * 4;
            _memset((void *)(iVar6 + local_24),0,4);
            local_28 = uVar9 + 1;
            piVar7 = (int *)(iVar6 + local_24);
          }
          else {
            piVar7 = (int *)FUN_001a7f7c(&local_2c,local_28);
          }
          uVar9 = local_38;
          *piVar7 = (int)piVar11;
          uVar3 = *(undefined4 *)(iVar14 + 0x10);
          if (local_38 < local_3c) {
            iVar14 = local_38 * 4;
            _memset((void *)(iVar14 + local_34),0,4);
            local_38 = uVar9 + 1;
            puVar10 = (undefined4 *)(iVar14 + local_34);
          }
          else {
            puVar10 = (undefined4 *)FUN_001a7f7c(&local_3c,local_38);
          }
          uVar9 = local_48;
          *puVar10 = uVar3;
          if (local_48 < local_4c) {
            iVar14 = local_48 * 4;
            _memset((void *)(iVar14 + local_44),0,4);
            local_48 = uVar9 + 1;
            puVar10 = (undefined4 *)(iVar14 + local_44);
          }
          else {
            puVar10 = (undefined4 *)FUN_001a7f7c(&local_4c,local_48);
          }
          *puVar10 = uVar2;
        }
      }
      cVar5 = (**(code **)(*piVar11 + 0x5c))(piVar11);
      if ((cVar5 == '\0') && (cVar5 = (**(code **)(*piVar11 + 0x60))(piVar11), cVar5 == '\0')) {
        cVar5 = (**(code **)(*param_1 + 0x88))(param_1,piVar11);
        if (cVar5 == '\0') goto LAB_001a12a1;
        cVar5 = ((int (*)())FUN_001a0c4c)(piVar11,param_1[2]);
        if (cVar5 == '\0') {
          local_71 = 0;
          goto joined_r0x001a1101;
        }
      }
    }
LAB_001a1078:
    local_88 = local_88 + 1;
    if (uVar1 == local_88) goto LAB_001a10f8;
    puVar13 = *(uint **)(param_2 + 0x40);
    if (local_88 < *puVar13) goto LAB_001a0e30;
LAB_001a109e:
    piVar11 = (int *)FUN_001a7f7c(puVar13,local_88);
  } while( true );
}

/* FUN_001a141e @ 0x1a141e (6205 bytes) */
int FUN_001a141e(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int *piVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  uint uVar16;
  undefined4 uVar17;
  int iVar18;
  int local_d4;
  int local_d0;
  int local_cc;
  int *local_c8;
  uint *local_c4;
  uint *local_c0;
  undefined4 local_b8;
  int *local_ac;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_80;
  int local_78;
  undefined4 local_70;
  int local_6c;
  int local_68;
  int local_5c;
  int local_58;
  undefined4 uStack_44;
  uint local_40 [4];
  uint local_30;
  uint local_2c;
  int local_28;
  undefined4 local_24;
  int local_20 [4];
  
  iVar6 = param_2[0x56];
  iVar9 = *(int *)(param_1[2] + 0x3f4);
  cVar5 = FUN_000e1402(param_1[2],0x40);
  if (((cVar5 == '\0') || (*(int *)(param_2[0x22] + 8) != 0x77)) ||
     ((*(byte *)((int)param_2 + 0x17) & 2) != 0)) {
    local_ac = (int *)0x0;
  }
  else {
    local_24 = *(undefined4 *)(param_1[2] + 0xbc);
    local_2c = 0;
    local_30 = 2;
    local_28 = FUN_001a7bca(local_24,8);
    local_40[3] = *(undefined4 *)(param_1[2] + 0xbc);
    local_40[1] = 0;
    local_40[0] = 2;
    local_40[2] = FUN_001a7bca(local_40[3],8);
    iVar10 = *(int *)(iVar9 + 0x468) + 1;
    *(int *)(iVar9 + 0x468) = iVar10;
    iVar13 = FUN_0010b180(param_2,1);
    uVar16 = local_2c;
    *(int *)(iVar13 + 0x150) = iVar10;
    if (local_2c < local_30) {
      iVar1 = local_2c * 4;
      _memset((void *)(iVar1 + local_28),0,4);
      local_2c = uVar16 + 1;
      piVar7 = (int *)(iVar1 + local_28);
    }
    else {
      piVar7 = (int *)FUN_001a7f7c(&local_30,local_2c);
    }
    local_c0 = &local_30;
    *piVar7 = iVar13;
    bVar3 = false;
    bVar4 = false;
    do {
      uVar16 = local_2c - 1;
      if (uVar16 < local_2c) {
        piVar7 = (int *)(local_28 + uVar16 * 4);
      }
      else {
        piVar7 = (int *)0x0;
      }
      iVar1 = *piVar7;
      FUN_001a7f3c(local_c0,uVar16);
      cVar5 = FUN_001191a6(*(undefined4 *)(*(int *)(iVar1 + 0x88) + 8),param_1[2]);
      if (cVar5 != '\0') goto LAB_001a292e;
      cVar5 = FUN_001191dc(*(undefined4 *)(*(int *)(iVar1 + 0x88) + 8),param_1[2]);
      if (cVar5 != '\0') {
        iVar18 = *(int *)(iVar1 + 0x88);
        if (((*(int *)(iVar18 + 8) == 0x24) || (*(int *)(iVar18 + 8) == 0x25)) ||
           (*(int *)(iVar18 + 8) == 0x26)) {
          local_98 = 2;
        }
        else {
          local_98 = 1;
        }
        if (local_98 <= *(int *)(iVar1 + 0x84)) {
          local_d0 = local_98 * 0x18 + 0x8c + iVar1;
          local_d4 = local_98 * 0x18 + 0x80;
          do {
            piVar7 = (int *)FUN_0010b180(iVar1,local_98);
            if (iVar10 != piVar7[0x54]) {
              piVar7[0x54] = iVar10;
              cVar5 = FUN_001191a6(*(undefined4 *)(piVar7[0x22] + 8),param_1[2]);
              if (cVar5 != '\0') {
LAB_001a2c4f:
                bVar3 = true;
                break;
              }
              if ((*(byte *)(local_d4 + 0x20 + iVar1) & 1) != 0) {
                cVar5 = (**(code **)(*piVar7 + 0x48))(piVar7);
                if (cVar5 == '\0') {
                  cVar5 = FUN_0010a62e(piVar7,iVar9);
                  if (cVar5 == '\0') goto LAB_001a2c4f;
                  iVar18 = piVar7[0x22];
                  if (*(int *)(iVar18 + 8) == 0x31) {
                    FUN_00109c0e(piVar7 + 0x29,1,*(byte *)(piVar7 + 0x2e) & 1 ^ 1);
                  }
                  else if (*(int *)(iVar18 + 8) == 0x12) {
                    FUN_00109c0e(piVar7 + 0x29,1,*(byte *)(piVar7 + 0x2e) & 1 ^ 1);
                    FUN_00109c0e(piVar7 + 0x2f,1,*(byte *)(piVar7 + 0x34) & 1 ^ 1);
                  }
                  else if (*(int *)(iVar18 + 8) == 0x13) {
                    FUN_00109c0e(piVar7 + 0x29,1,*(byte *)(piVar7 + 0x2e) & 1 ^ 1);
                  }
                  else {
                    if (*(int *)(iVar18 + 8) == 0x14) {
                      FUN_00109c0e(piVar7 + 0x29,1,*(byte *)(piVar7 + 0x2e) & 1 ^ 1);
                    }
                    else {
                      if (((*(int *)(iVar18 + 8) != 0x24) && (*(int *)(iVar18 + 8) != 0x25)) &&
                         (*(int *)(iVar18 + 8) != 0x26)) goto LAB_001a2c4f;
                      cVar5 = ((undefined4 (*)())FUN_00140e9c)(piVar7,2,0);
                      if (cVar5 == '\0') {
                        FUN_00109c0e(piVar7 + 0x2f,1,*(byte *)(piVar7 + 0x34) & 1 ^ 1);
                      }
                      cVar5 = ((undefined4 (*)())FUN_00140e9c)(piVar7,3,0);
                      if (cVar5 != '\0') goto LAB_001a266a;
                    }
                    FUN_00109c0e(piVar7 + 0x35,1,*(byte *)(piVar7 + 0x3a) & 1 ^ 1);
                  }
LAB_001a266a:
                  uVar17 = 0;
                }
                else {
                  cVar5 = ((undefined4 (*)())FUN_00140e9c)(iVar1,local_98,0);
                  if (cVar5 != '\0') goto LAB_001a266a;
                  iVar18 = 0;
                  piVar12 = piVar7;
                  do {
                    iVar15 = FUN_0010b0f4(piVar7,0);
                    if ((*(char *)(iVar18 + 0x10 + iVar15) != '\x01') &&
                       (((((int)(char)piVar7[0x57] >> ((byte)iVar18 & 0x1f) & 1U) == 0 ||
                         (piVar12[7] != 2)) || ((float)piVar12[8] == 0.0)))) goto LAB_001a2c4f;
                    iVar18 = iVar18 + 1;
                    piVar12 = piVar12 + 6;
                  } while (iVar18 != 4);
                  if (bVar3) goto LAB_001a2c4f;
                  uVar17 = 1;
                }
                FUN_00109c0e(local_d0,1,uVar17);
              }
              cVar5 = FUN_001191dc(*(undefined4 *)(piVar7[0x22] + 8),param_1[2]);
              uVar16 = local_2c;
              if (cVar5 == '\0') {
                if (*(int *)(piVar7[0x22] + 8) == 0x31) {
                  iVar18 = param_1[2];
                  iVar15 = FUN_0010b180(piVar7,1);
                  cVar5 = FUN_001191a6(*(undefined4 *)(*(int *)(iVar15 + 0x88) + 8),iVar18);
                  if (cVar5 == '\0') {
                    iVar18 = param_1[2];
                    iVar15 = FUN_0010b180(piVar7,1);
                    cVar5 = FUN_001191dc(*(undefined4 *)(*(int *)(iVar15 + 0x88) + 8),iVar18);
                    if (cVar5 == '\0') goto LAB_001a26ef;
                  }
                  uVar16 = local_40[1];
                  if (local_40[1] < local_40[0]) {
                    iVar18 = local_40[1] * 4;
                    _memset((void *)(iVar18 + local_40[2]),0,4);
                    local_40[1] = uVar16 + 1;
                    puVar14 = (undefined4 *)(iVar18 + local_40[2]);
                  }
                  else {
                    puVar14 = (undefined4 *)FUN_001a7f7c(local_40,local_40[1]);
                  }
                  *puVar14 = piVar7;
                  bVar4 = true;
                }
              }
              else {
                if (local_2c < local_30) {
                  iVar18 = local_2c * 4;
                  _memset((void *)(iVar18 + local_28),0,4);
                  local_2c = uVar16 + 1;
                  puVar14 = (undefined4 *)(iVar18 + local_28);
                }
                else {
                  puVar14 = (undefined4 *)FUN_001a7f7c(local_c0,local_2c);
                }
                *puVar14 = piVar7;
              }
            }
LAB_001a26ef:
            local_98 = local_98 + 1;
            local_d4 = local_d4 + 0x18;
            local_d0 = local_d0 + 0x18;
          } while (local_98 <= *(int *)(iVar1 + 0x84));
        }
      }
    } while (local_2c != 0);
    if (bVar3) {
LAB_001a292e:
      *(int *)(iVar9 + 0x238) = *(int *)(iVar9 + 0x238) + 1;
      local_ac = (int *)FUN_0010a17a(0x31,param_1[2]);
      local_ac[0x25] = local_ac[0x53];
      local_ac[0x26] = 0;
      FUN_0010ba02(local_ac,1,iVar13,0,param_1[2]);
      FUN_0010ba02(param_2,1,local_ac,0,param_1[2]);
      local_ac[0x27] = DAT_001cf01c;
      iVar10 = FUN_0010b0f4(local_ac,1);
      *(undefined4 *)(iVar10 + 0x10) = DAT_001cf004;
      local_94 = 0;
      do {
        iVar10 = FUN_0010b0f4(param_2,1);
        bVar2 = *(byte *)(local_94 + 0x10 + iVar10);
        uVar16 = (uint)bVar2;
        if (bVar2 != 4) {
          (**(code **)(*local_ac + 0x88))(local_ac,1,uVar16,uVar16);
          *(undefined1 *)(uVar16 + 0x9c + (int)local_ac) = 0;
        }
        local_94 = local_94 + 1;
      } while (local_94 != 4);
      FUN_000e956e(iVar6,param_2,local_ac);
      local_ac[5] = local_ac[5] | 0x80000000;
    }
    else {
      if ((bVar4) && (local_40[1] != 0)) {
        do {
          uVar16 = local_40[1] - 1;
          if (uVar16 < local_40[1]) {
            piVar7 = (int *)(local_40[2] + uVar16 * 4);
          }
          else {
            piVar7 = (int *)0x0;
          }
          iVar10 = *piVar7;
          FUN_001a7f3c(local_40,uVar16);
          *(uint *)(iVar10 + 0x14) = *(uint *)(iVar10 + 0x14) | 0x80000000;
        } while (local_40[1] != 0);
      }
      local_ac = (int *)0x0;
    }
    FUN_001a7aba(local_40[3],local_40[2]);
    FUN_001a7aba(local_24,local_28);
  }
  cVar5 = (**(code **)(*param_2 + 0x28))(param_2);
  if (cVar5 == '\0') {
    uVar17 = 0;
    piVar7 = param_2;
  }
  else {
    uVar17 = 0;
    local_90 = 1;
    local_c8 = param_2 + 0x29;
    local_cc = 0x98;
    iVar10 = (**(code **)(*param_2 + 0x14))(param_2);
    if (0 < iVar10) {
      do {
        piVar7 = (int *)FUN_0010b180(param_2,local_90);
        cVar5 = (**(code **)(*piVar7 + 0x60))(piVar7);
        if (cVar5 == '\0') {
LAB_001a1f01:
          piVar7 = (int *)FUN_0010b180(param_2,local_90);
          cVar5 = (**(code **)(*piVar7 + 0x48))(piVar7);
          if (cVar5 == '\0') {
            piVar7 = (int *)FUN_0010b180(param_2,local_90);
            cVar5 = (**(code **)(*piVar7 + 0x60))(piVar7);
            if ((cVar5 == '\0') &&
               (((uVar16 = *(uint *)(local_cc + 0x20 + (int)param_2), (uVar16 & 2) == 0 &&
                 ((uVar16 & 1) == 0)) || (cVar5 = FUN_00153dea(param_2,iVar9), cVar5 != '\0'))))
            goto LAB_001a2124;
          }
          *(int *)(iVar9 + 0x238) = *(int *)(iVar9 + 0x238) + 1;
          piVar12 = (int *)FUN_0010a17a(0x31,param_1[2]);
          piVar12[0x25] = piVar12[0x53];
          piVar12[0x26] = 0;
          iVar10 = param_1[2];
          uVar17 = FUN_0010b180(param_2,local_90);
          FUN_0010ba02(piVar12,1,uVar17,0,iVar10);
          FUN_00109c0e(piVar12 + 0x29,2,*(uint *)(local_cc + 0x20 + (int)param_2) >> 1 & 1);
          FUN_00109c0e(piVar12 + 0x29,1,*(byte *)(local_cc + 0x20 + (int)param_2) & 1);
          iVar10 = FUN_0010b0f4(param_2,local_90);
          uVar17 = *(undefined4 *)(iVar10 + 0x10);
          iVar10 = FUN_0010b0f4(piVar12,1);
          *(undefined4 *)(iVar10 + 0x10) = uVar17;
          local_30 = DAT_001cf000;
          iVar10 = 0;
          piVar7 = piVar12;
          do {
            iVar13 = FUN_0010b0f4(param_2,local_90);
            if (*(char *)(iVar10 + 0x10 + iVar13) == '\x04') {
              *(undefined1 *)(piVar7 + 0x27) = 1;
              *(undefined1 *)((int)&local_30 + iVar10) = 4;
            }
            iVar10 = iVar10 + 1;
            piVar7 = (int *)((int)piVar7 + 1);
          } while (iVar10 != 4);
          FUN_000e956e(iVar6,param_2,piVar12);
          FUN_0010ba02(param_2,local_90,piVar12,0,param_1[2]);
          FUN_00109c0e(local_c8,2,0);
          FUN_00109c0e(local_c8,1,0);
          uVar16 = local_30;
          iVar10 = FUN_0010b0f4(param_2,local_90);
          *(uint *)(iVar10 + 0x10) = uVar16;
          if (local_ac == (int *)0x0) {
            uVar17 = 1;
            local_ac = piVar12;
          }
          else {
            uVar17 = 1;
          }
        }
        else {
          uVar8 = *(undefined4 *)(param_1[2] + 0x3f4);
          uVar11 = FUN_0010b180(param_2,local_90);
          uVar11 = FUN_0010b180(uVar11,1);
          cVar5 = FUN_0010a62e(uVar11,uVar8);
          if (cVar5 == '\0') goto LAB_001a1f01;
          iVar10 = param_1[2];
          uVar8 = FUN_0010b180(param_2,local_90);
          cVar5 = FUN_0011169e(uVar8,iVar10);
          if (cVar5 == '\0') goto LAB_001a1f01;
          iVar10 = param_1[2];
          uVar8 = FUN_0010b180(param_2,local_90);
          uVar8 = FUN_00111dca(uVar8,iVar10);
          FUN_0010ba02(param_2,local_90,uVar8,0,param_1[2]);
        }
LAB_001a2124:
        local_90 = local_90 + 1;
        local_cc = local_cc + 0x18;
        local_c8 = local_c8 + 6;
        iVar10 = (**(code **)(*param_2 + 0x14))(param_2);
      } while (local_90 <= iVar10);
    }
    piVar7 = local_ac;
    if (local_ac == (int *)0x0) {
      piVar7 = param_2;
    }
  }
  param_2 = piVar7;
  if (((*(int *)(param_2[0x22] + 8) == 0x9e) || (*(int *)(param_2[0x22] + 8) == 0xa0)) &&
     ((cVar5 = FUN_000f5a1e(param_2,1), cVar5 == '\0' ||
      (((param_2[0x2e] & 1U) != 0 || ((param_2[0x2e] & 2U) != 0)))))) {
    *(int *)(iVar9 + 0x238) = *(int *)(iVar9 + 0x238) + 1;
    piVar7 = (int *)FUN_0010a17a(0x31,param_1[2]);
    piVar7[0x25] = piVar7[0x53];
    piVar7[0x26] = 0;
    iVar10 = FUN_0010b0f4(param_2,0);
    uVar17 = *(undefined4 *)(iVar10 + 0x10);
    iVar10 = FUN_0010b0f4(piVar7,0);
    *(undefined4 *)(iVar10 + 0x10) = uVar17;
    iVar10 = param_1[2];
    uVar17 = FUN_0010b180(param_2,1);
    FUN_0010ba02(piVar7,1,uVar17,0,iVar10);
    FUN_00109c0e(piVar7 + 0x29,2,(uint)param_2[0x2e] >> 1 & 1);
    FUN_00109c0e(piVar7 + 0x29,1,*(byte *)(param_2 + 0x2e) & 1);
    iVar10 = FUN_0010b0f4(param_2,1);
    uVar17 = *(undefined4 *)(iVar10 + 0x10);
    iVar10 = FUN_0010b0f4(piVar7,1);
    *(undefined4 *)(iVar10 + 0x10) = uVar17;
    FUN_000e956e(iVar6,param_2,piVar7);
    FUN_0010ba02(param_2,1,piVar7,0,param_1[2]);
    FUN_00109c0e(param_2 + 0x29,2,0);
    FUN_00109c0e(param_2 + 0x29,1,0);
    iVar10 = FUN_0010b0f4(param_2,1);
    *(uint *)(iVar10 + 0x10) = DAT_001cf000;
    iVar10 = 0;
    do {
      iVar13 = FUN_0010b0f4(param_2,0);
      if (*(char *)(iVar10 + 0x10 + iVar13) == '\x01') {
        (**(code **)(*param_2 + 0x88))(param_2,1,iVar10,4);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 != 4);
    uVar17 = 1;
    cVar5 = (**(code **)(*param_1 + 0x88))(param_1,piVar7);
    param_2 = piVar7;
  }
  else {
    cVar5 = (**(code **)(*param_1 + 0x88))(param_1,param_2);
  }
  if (cVar5 == '\0') {
    for (local_8c = 1; iVar10 = (**(code **)(*param_2 + 0x14))(param_2), local_8c <= iVar10;
        local_8c = local_8c + 1) {
      local_20[0] = 0;
      (**(code **)(*param_1 + 0x68))(param_1,param_2,local_8c,local_40,local_20,param_1[2]);
      if (local_20[0] != 0) {
        if ((*(int *)(param_2[0x22] + 8) == 0x31) || (*(int *)(param_2[0x22] + 8) == 0x30)) {
          *(int *)(iVar9 + 0x238) = *(int *)(iVar9 + 0x238) + 1;
          local_88 = FUN_0010a17a(0x31,param_1[2]);
          FUN_00109d86(local_88,param_2);
          uVar16 = local_40[0];
          iVar10 = FUN_0010b0f4(local_88,1);
          *(uint *)(iVar10 + 0x10) = uVar16;
          uVar17 = FUN_000f5aec(local_40[0]);
          *(undefined4 *)(local_88 + 0x9c) = uVar17;
          FUN_000e956e(iVar6,param_2,local_88);
          iVar10 = local_20[0] + -1;
          if (1 < iVar10) {
            local_5c = 2;
            local_c4 = local_40 + 3;
            do {
              iVar10 = FUN_0010a17a(0x31,param_1[2]);
              FUN_00109d86(iVar10,param_2);
              uVar16 = local_c4[-2];
              iVar13 = FUN_0010b0f4(iVar10,1);
              *(uint *)(iVar13 + 0x10) = uVar16;
              uVar17 = FUN_000f5aec(local_c4[-2]);
              *(undefined4 *)(iVar10 + 0x9c) = uVar17;
              FUN_000e956e(iVar6,param_2,iVar10);
              if ((*(byte *)(param_2 + 5) & 2) == 0) {
                FUN_0010c18e(iVar10,local_88,0,param_1[2]);
                local_88 = iVar10;
              }
              *(int *)(iVar9 + 0x238) = *(int *)(iVar9 + 0x238) + 1;
              iVar10 = local_20[0] + -1;
              local_c4 = local_c4 + 1;
              bVar3 = local_5c < iVar10;
              local_5c = local_5c + 1;
            } while (bVar3);
          }
          uVar16 = local_40[iVar10];
          iVar10 = FUN_0010b0f4(param_2,1);
          *(uint *)(iVar10 + 0x10) = uVar16;
          iVar10 = FUN_000f5aec((&uStack_44)[local_20[0]]);
          param_2[0x27] = iVar10;
          if ((*(byte *)(param_2 + 5) & 2) == 0) {
            FUN_0010c18e(param_2,local_88,0,param_1[2]);
          }
        }
        else {
          piVar7 = (int *)FUN_0010b180(param_2,local_8c);
          if (local_20[0] < 1) {
            local_80 = 0;
          }
          else {
            local_80 = 0;
            local_58 = 1;
            do {
              *(int *)(iVar9 + 0x238) = *(int *)(iVar9 + 0x238) + 1;
              iVar10 = FUN_0010a17a(0x31,param_1[2]);
              *(undefined4 *)(iVar10 + 0x94) = *(undefined4 *)(iVar10 + 0x14c);
              *(undefined4 *)(iVar10 + 0x98) = 0;
              FUN_0010ba02(iVar10,1,piVar7,0,param_1[2]);
              uVar17 = (&uStack_44)[local_58];
              iVar13 = FUN_0010b0f4(iVar10,1);
              *(undefined4 *)(iVar13 + 0x10) = uVar17;
              uVar17 = FUN_000f5aec((&uStack_44)[local_58]);
              *(undefined4 *)(iVar10 + 0x9c) = uVar17;
              if (local_80 == 0) {
                if ((((piVar7[0x20] != 0) && (cVar5 = FUN_0012dfd8(piVar7[0x26]), cVar5 != '\0')) &&
                    ((*(byte *)(piVar7 + 5) & 2) == 0)) &&
                   (cVar5 = (**(code **)(*piVar7 + 0x50))(piVar7), cVar5 == '\0')) {
                  bVar3 = false;
                  uVar16 = 0;
                  iVar13 = iVar10;
                  do {
                    if (uVar16 == *(byte *)(uVar16 + (int)local_40)) {
                      *(undefined1 *)(iVar13 + 0x9c) = 1;
                      bVar3 = true;
                    }
                    uVar16 = uVar16 + 1;
                    iVar13 = iVar13 + 1;
                  } while (uVar16 != 4);
                  if (bVar3) {
                    FUN_0010c18e(iVar10,piVar7,0,param_1[2]);
                  }
                }
              }
              else {
                FUN_0010c18e(iVar10,local_80,0,param_1[2]);
              }
              iVar13 = FUN_0010b0f4(iVar10,0);
              if (*(int *)(iVar13 + 0x10) == DAT_001cf01c) {
                local_80 = FUN_0010b180(iVar10,*(undefined4 *)(iVar10 + 0x84));
              }
              else {
                FUN_000e956e(iVar6,param_2,iVar10);
                local_80 = iVar10;
              }
              bVar3 = local_58 < local_20[0];
              local_58 = local_58 + 1;
            } while (bVar3);
          }
          FUN_0010ba02(param_2,local_8c,local_80,0,param_1[2]);
        }
      }
    }
    uVar17 = 1;
  }
  cVar5 = ((int (*)())FUN_001a0c4c)(param_2,param_1[2]);
  if (cVar5 != '\0') {
    return uVar17;
  }
  local_78 = 1;
  iVar6 = (**(code **)(*param_2 + 0x14))(param_2);
  if (0 < iVar6) {
    do {
      piVar7 = (int *)FUN_0010b180(param_2,local_78);
      cVar5 = (**(code **)(*piVar7 + 0x60))(piVar7);
      if (cVar5 != '\0') {
        piVar7 = (int *)FUN_0010b180(piVar7,1);
      }
      cVar5 = (**(code **)(*piVar7 + 0x5c))(piVar7);
      if (cVar5 != '\0') {
        uVar8 = FUN_0010b180(piVar7,1);
        iVar6 = FUN_0010b0f4(piVar7,0);
        iVar6 = *(int *)(iVar6 + 0x10);
        iVar9 = FUN_0010b0f4(piVar7,1);
        uVar17 = *(undefined4 *)(iVar9 + 0x10);
        iVar9 = (**(code **)(*piVar7 + 0x14))(piVar7);
        if (iVar9 < 2) {
          local_70 = 0;
          local_6c = *(int *)(piVar7[0x22] + 8);
          local_68 = piVar7[1];
          FUN_001a7d72(piVar7);
          if (local_6c == 0x99) goto LAB_001a197a;
LAB_001a17f2:
          FUN_0010d8fc(piVar7,0x12,param_1[2]);
        }
        else {
          local_70 = FUN_0010b180(piVar7,2);
          iVar9 = FUN_0010b0f4(piVar7,2);
          local_b8 = *(undefined4 *)(iVar9 + 0x10);
          local_6c = *(int *)(piVar7[0x22] + 8);
          local_68 = piVar7[1];
          FUN_001a7d72(piVar7);
          if (local_6c != 0x99) goto LAB_001a17f2;
LAB_001a197a:
          FUN_0010da48(piVar7,0x14,param_1[2]);
        }
        iVar9 = piVar7[0x53];
        iVar10 = FUN_0010b0f4(piVar7,0);
        *(int *)(iVar10 + 8) = iVar9;
        *(undefined4 *)(iVar10 + 0xc) = 0;
        piVar7[0x27] = iVar6;
        FUN_0010ba02(piVar7,1,uVar8,0,param_1[2]);
        iVar6 = FUN_0010b0f4(piVar7,1);
        *(undefined4 *)(iVar6 + 0x10) = uVar17;
        if (local_6c == 0x99) {
          FUN_00109c0e(piVar7 + 0x29,1,1);
          FUN_000fa0d2(piVar7,*(undefined4 *)(param_1[2] + 0x3f4),2,0x3f800000,0x3f800000,0x3f800000
                       ,0x3f800000);
          FUN_000fa0d2(piVar7,*(undefined4 *)(param_1[2] + 0x3f4),3,0x3f000000,0x3f000000,0x3f000000
                       ,0x3f000000);
          piVar7[0x49] = 1;
        }
        else if (local_6c == 0x9c) {
          FUN_000fa0d2(piVar7,*(undefined4 *)(param_1[2] + 0x3f4),2,0x3f800000,0x3f800000,0x3f800000
                       ,0x3f800000);
          FUN_00109c0e(piVar7 + 0x29,1,1);
        }
        else {
          FUN_0010ba02(piVar7,2,local_70,0,param_1[2]);
          iVar6 = FUN_0010b0f4(piVar7,2);
          *(undefined4 *)(iVar6 + 0x10) = local_b8;
          FUN_00109c0e(piVar7 + 0x2f,1,local_6c == 0x9a);
        }
        FUN_000e9596(*(undefined4 *)(local_68 + 0x158),local_68,piVar7);
        cVar5 = ((int (*)())FUN_001a0c4c)(param_2,param_1[2]);
        if (cVar5 != '\0') {
          return 1;
        }
      }
      local_78 = local_78 + 1;
      iVar6 = (**(code **)(*param_2 + 0x14))(param_2);
    } while (local_78 <= iVar6);
  }
  return 1;
}

/* FUN_001a2c96 @ 0x1a2c96 (292 bytes) */
int FUN_001a2c96(param_1, param_2)
  int param_1;
  int *param_2;
{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_14;
  undefined4 local_10;
  
  if (-1 < (short)param_2[5]) {
    cVar1 = (**(code **)(*param_2 + 0x28))(param_2);
    if (cVar1 != '\0') {
      *(undefined4 *)(param_1 + 4) = 4;
      return;
    }
    ((int (*)())FUN_0019d188)(param_2,param_1 + 0x18,param_1 + 0x20);
    ((int (*)())FUN_001a069e)(param_2,param_1 + 0x1c,param_1 + 0x24,param_1 + 0x28,*(undefined4 *)(param_1 + 8));
    ((int (*)())FUN_0019fa5e)(param_1 + 0x28,&local_14);
    uVar2 = 0;
    if (*(int *)(param_1 + 0x5c) != 0) {
      ((int (*)())FUN_0019ccce)(param_1,*(int *)(param_1 + 0x5c),param_2,local_14,local_10);
      uVar2 = *(undefined4 *)(param_1 + 0x5c);
    }
    ((int (*)())FUN_0019cdd0)(param_1,uVar2,param_2,local_14,local_10);
    if (*(int *)(param_1 + 0x5c) == 0) {
      *(int **)(param_1 + 0x5c) = param_2;
    }
    if (-1 < *(int *)(param_1 + 0x18)) {
      *(uint *)(param_1 + 4) = (*(int *)(param_1 + 0x20) >> 0x1f & 0xfffffffeU) + 3;
      return;
    }
    *(uint *)(param_1 + 4) = ~(*(int *)(param_1 + 0x20) >> 0x1f) & 2;
  }
  return;
}

/* FUN_001a2dba @ 0x1a2dba (256 bytes) */
int FUN_001a2dba(param_1, param_2)
  int param_1;
  int *param_2;
{
  char cVar1;
  undefined1 local_58 [52];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (-1 < (short)param_2[5]) {
    cVar1 = (**(code **)(*param_2 + 0x28))(param_2);
    if (cVar1 != '\0') {
      return *(int *)(param_1 + 4) == 0;
    }
    local_10 = *(undefined4 *)(param_1 + 0x18);
    local_14 = *(undefined4 *)(param_1 + 0x1c);
    local_18 = *(undefined4 *)(param_1 + 0x20);
    local_1c = *(undefined4 *)(param_1 + 0x24);
    FUN_0019ca96(local_58,param_1 + 0x28);
    cVar1 = ((int (*)())FUN_0019d188)(param_2,&local_10,&local_18);
    if ((((cVar1 == '\0') ||
         (cVar1 = ((int (*)())FUN_001a069e)(param_2,&local_14,&local_1c,local_58,*(undefined4 *)(param_1 + 8)),
         cVar1 == '\0')) || (cVar1 = ((int (*)())FUN_0019fa5e)(local_58,&local_24), cVar1 == '\0')) ||
       ((*(int *)(param_1 + 0x5c) != 0 &&
        (cVar1 = ((int (*)())FUN_0019ccce)(param_1,*(int *)(param_1 + 0x5c),param_2,local_24,local_20),
        cVar1 == '\0')))) {
      return false;
    }
  }
  return true;
}

/* FUN_001a2eba @ 0x1a2eba (342 bytes) */
int FUN_001a2eba(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  if (((((((param_2[0x20] != 0) && (cVar2 = FUN_0012dfd8(param_2[0x26]), cVar2 != '\0')) &&
         ((*(byte *)(param_2 + 5) & 2) == 0)) &&
        ((cVar2 = (**(code **)(*param_2 + 0x50))(param_2), cVar2 == '\0' &&
         (uVar1 = param_2[5], (uVar1 & 0x20) == 0)))) &&
       (((uVar1 & 0x40) == 0 &&
        (((uVar1 & 2) == 0 && (cVar2 = (**(code **)(*param_2 + 0x5c))(param_2), cVar2 == '\0'))))))
      && (cVar2 = (**(code **)(*param_2 + 0x28))(param_2), cVar2 == '\0')) &&
     ((((iVar4 = *(int *)(param_2[0x22] + 8), iVar4 != 0x9e && (iVar4 != 0xa0)) && (iVar4 != 0x9f))
      && (((iVar4 != 0xa1 && (iVar4 = *(int *)(PTR_DAT_00213a35 + iVar4 * 0x38 + 0x34), iVar4 != 3))
          && (iVar4 != 8)))))) {
    iVar3 = FUN_0010b0f4(param_2,0);
    if (*(char *)(iVar3 + 0x13) == '\0') {
      if (iVar4 != 5) {
        if (iVar4 != 0) {
          return 1;
        }
        iVar4 = FUN_000f60f4(param_2);
        if (iVar4 != 4) {
          if (iVar4 < 2) {
            return 1;
          }
          if ((*(byte *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 9) & 4) != 0) {
            return 1;
          }
        }
      }
    }
    else if ((*(char *)(iVar3 + 0x13) == '\x01') && (1 < iVar4 - 1U)) {
      if (iVar4 == 5) {
        return 1;
      }
      iVar4 = FUN_000f60f4(param_2);
      if (iVar4 < 2) {
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_001a3010 @ 0x1a3010 (64 bytes) */
int FUN_001a3010(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 4;
  *(undefined4 *)(param_1 + 0x24) = 4;
  *(undefined4 *)(param_1 + 0x28) = 4;
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  return;
}

/* FUN_001a3050 @ 0x1a3050 (149 bytes) */
int FUN_001a3050(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  int *param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2[1];
  if (*param_2 == iVar1) {
    iVar2 = *param_3;
    iVar3 = param_3[1];
    if ((iVar2 != iVar3) && (iVar1 != 0)) {
      return 0;
    }
    if (iVar1 != param_2[2]) {
      return 1;
    }
    if (iVar1 == 0) {
      if (param_4 != '\0') {
        return 1;
      }
      if (iVar2 == iVar3) {
        return 1;
      }
      if (iVar2 == param_3[2]) {
        return 1;
      }
      if (iVar3 == param_3[2]) {
        return 1;
      }
    }
    else if ((iVar2 == iVar3) && (iVar2 == param_3[2])) {
      return 1;
    }
  }
  else {
    iVar2 = param_2[2];
    if (*param_2 == iVar2) {
      iVar1 = iVar2;
      if (*param_3 == param_3[2]) {
        return 1;
      }
    }
    else {
      if (iVar1 != iVar2) {
        return 1;
      }
      if (param_3[1] == param_3[2]) {
        return 1;
      }
    }
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}

/* FUN_001a30e6 @ 0x1a30e6 (65 bytes) */
int FUN_001a30e6(param_1, param_2)
  int *param_1;
  int param_2;
{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x30))(param_1,*(undefined4 *)(param_2 + 0x38));
  if ((cVar1 != '\0') &&
     ((*(int *)(param_2 + 0x60) == 0 || (*(int *)(*(int *)(param_2 + 0x60) + 8) == 0)))) {
    return 1;
  }
  return 0;
}

/* FUN_001a3128 @ 0x1a3128 (890 bytes) */
int FUN_001a3128(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined1 uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  char cVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  uint *local_58;
  uint local_54;
  int local_4c;
  uint local_48;
  int local_34;
  int local_30;
  int local_28;
  int local_24;
  int local_20;
  
  piVar2 = *(int **)(param_2 + 0x38);
  if ((((((*(int *)(param_2 + 0x60) == 0) && (piVar2[0x20] != 0)) &&
        (cVar7 = FUN_0012dfd8(piVar2[0x26]), cVar7 != '\0')) &&
       (((*(byte *)(piVar2 + 5) & 2) == 0 &&
        (cVar7 = (**(code **)(*piVar2 + 0x50))(piVar2), cVar7 == '\0')))) &&
      ((uVar3 = piVar2[5], (uVar3 & 0x20) == 0 && (((uVar3 & 0x40) == 0 && ((uVar3 & 2) == 0))))))
     && ((iVar12 = *(int *)(PTR_DAT_00213a39 + *(int *)(piVar2[0x22] + 8) * 0x38 + 0x34),
         iVar12 == 0 ||
         ((((iVar12 == 5 || (iVar12 == 1)) || (iVar12 == 2)) || ((iVar12 == 3 || (iVar12 == 8)))))))
     ) {
    local_4c = -1;
    bVar6 = false;
    local_20 = 0;
    do {
      iVar8 = FUN_0010b0f4(piVar2,0);
      iVar4 = local_4c;
      if ((*(char *)(local_20 + 0x10 + iVar8) == '\0') && (iVar4 = local_20, -1 < local_4c)) {
        cVar7 = FUN_0011902c(*(undefined4 *)(piVar2[0x22] + 8),param_1[2]);
        if (cVar7 == '\0') {
          return;
        }
        bVar6 = true;
        iVar4 = local_4c;
      }
      local_4c = iVar4;
      local_20 = local_20 + 1;
    } while (local_20 != 4);
    iVar4 = param_1[0xe];
    iVar8 = 0;
    if (iVar4 + 1 < 4) {
      iVar8 = iVar4 + 1;
    }
    param_1[0xe] = iVar8;
    if ((iVar4 != local_4c) || (bVar6)) {
      iVar13 = 4;
      iVar8 = param_2;
      do {
        *(undefined4 *)(iVar8 + 0x48) = 0;
        iVar8 = iVar8 + 4;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      local_58 = *(uint **)(param_2 + 0x40);
      uVar3 = local_58[1];
      if (0 < (int)uVar3) {
        local_48 = 0;
        while( true ) {
          if (local_48 < *local_58) {
            uVar5 = local_58[1];
            if (uVar5 <= local_48) {
              _memset((void *)(local_58[2] + uVar5 * 4),0,(local_48 - uVar5) * 4 + 4);
              local_58[1] = local_48 + 1;
            }
            piVar10 = (int *)(local_58[2] + local_48 * 4);
          }
          else {
            piVar10 = (int *)FUN_001a7f7c(local_58,local_48);
          }
          local_54 = local_48 + 1;
          iVar8 = *piVar10;
          if (*(int *)(iVar8 + 8) == 0) {
            *(undefined4 *)(iVar8 + 0x18) = 0;
            *(undefined1 *)(iVar4 + 0x18 + iVar8) = 1;
            piVar10 = (int *)(param_2 + 0x48 + iVar4 * 4);
            *piVar10 = *piVar10 + 1;
            piVar10 = *(int **)(*(int *)(iVar8 + 4) + 0x38);
            local_34 = 1;
            while (iVar8 = (**(code **)(*piVar10 + 0x14))(piVar10), local_34 <= iVar8) {
              piVar9 = (int *)FUN_0010b180(piVar10,local_34);
              if (piVar2 == piVar9) {
                local_30 = 0;
                do {
                  iVar8 = FUN_0010b0f4(piVar10,local_34);
                  if (*(char *)(local_30 + 0x10 + iVar8) != '\x04') {
                    (**(code **)(*piVar10 + 0x88))(piVar10,local_34,local_30,iVar4);
                  }
                  local_30 = local_30 + 1;
                } while (local_30 != 4);
                local_34 = local_34 + 1;
              }
              else {
                local_34 = local_34 + 1;
              }
            }
          }
          local_48 = local_54;
          if (uVar3 == local_54) break;
          local_58 = *(uint **)(param_2 + 0x40);
        }
      }
      piVar2[0x27] = DAT_001cf020;
      *(undefined1 *)(iVar4 + 0x9c + (int)piVar2) = 0;
      piVar2[3] = 0;
      *(undefined1 *)((int)piVar2 + iVar4 + 0xc) = 1;
      if (iVar12 == 0) {
        for (local_24 = 1; iVar12 = (**(code **)(*piVar2 + 0x14))(piVar2), local_24 <= iVar12;
            local_24 = local_24 + 1) {
          iVar12 = FUN_0010b0f4(piVar2,local_24);
          uVar1 = *(undefined1 *)(local_4c + 0x10 + iVar12);
          local_28 = 0;
          do {
            (**(code **)(*piVar2 + 0x88))(piVar2,local_24,local_28,uVar1);
            local_28 = local_28 + 1;
          } while (local_28 != 4);
        }
      }
      uVar11 = (**(code **)(*param_1 + 0x4c))(param_1,piVar2);
      *(undefined4 *)(param_2 + 0x58) = uVar11;
    }
  }
  return;
}

/* FUN_001a34a2 @ 0x1a34a2 (364 bytes) */
int FUN_001a34a2(param_1, param_2)
  int *param_1;
  int param_2;
{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_14;
  uint local_10;
  
  (**(code **)(*param_1 + 0x34))(param_1,param_2);
  piVar1 = *(int **)(param_2 + 0x38);
  iVar3 = piVar1[0x22];
  if ((*(int *)(iVar3 + 8) == 0x66) || (*(int *)(iVar3 + 8) == 0x36)) {
    FUN_00110cd2(piVar1,param_1[2]);
    piVar1[0x26] = 0;
    uVar2 = (**(code **)(*param_1 + 0x4c))(param_1,piVar1);
    *(undefined4 *)(param_2 + 0x58) = uVar2;
    return;
  }
  if ((*(int *)(iVar3 + 8) != 0x31) && (*(int *)(iVar3 + 8) != 0x13)) {
    uVar2 = (**(code **)(*param_1 + 0x4c))(param_1,piVar1);
    *(undefined4 *)(param_2 + 0x58) = uVar2;
    return;
  }
  iVar3 = (**(code **)(*piVar1 + 0x14))(piVar1);
  local_14 = 0xffffffff;
  local_10 = 0xffffffff;
  iVar5 = 0;
  do {
    iVar4 = FUN_0010b0f4(piVar1,0);
    if (*(char *)(iVar5 + 0x10 + iVar4) != '\x01') {
      iVar4 = FUN_0010b0f4(piVar1,1);
      local_14 = (uint)*(byte *)(iVar5 + 0x10 + iVar4);
      if (iVar3 == 2) {
        iVar4 = FUN_0010b0f4(piVar1,2);
        local_10 = (uint)*(byte *)(iVar5 + 0x10 + iVar4);
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 4);
  FUN_00110c0c(piVar1,local_14,local_10,0,0,param_1[2]);
  piVar1[0x26] = 1;
  uVar2 = (**(code **)(*param_1 + 0x4c))(param_1,piVar1);
  *(undefined4 *)(param_2 + 0x58) = uVar2;
  return;
}

/* FUN_001a360e @ 0x1a360e (490 bytes) */
int FUN_001a360e(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint local_24;
  uint local_20;
  
  iVar1 = *(int *)(param_2 + 0x378);
  iVar4 = *(int *)(iVar1 + 8);
  do {
    if (iVar4 == 0) {
      return;
    }
    iVar6 = *(int *)(iVar1 + 0x98);
    iVar4 = *(int *)(iVar6 + 8);
joined_r0x001a3644:
    if (iVar4 != 0) {
      do {
        if ((*(byte *)(iVar6 + 0x14) & 1) != 0) {
          iVar4 = *(int *)(iVar6 + 0x88);
          if (*(int *)(iVar4 + 8) != 0x8e) {
            (**(code **)(*param_1 + 0x6c))(param_1,iVar6);
            iVar4 = *(int *)(iVar6 + 0x88);
          }
          if ((*(int *)(iVar4 + 8) == 0x31) || (*(int *)(iVar4 + 8) == 0x30)) {
            piVar3 = (int *)FUN_0010b180(iVar6,1);
            cVar2 = (**(code **)(*piVar3 + 0x50))(piVar3);
            if (cVar2 != '\0') goto code_r0x001a36a4;
          }
        }
        iVar6 = *(int *)(iVar6 + 8);
        if (*(int *)(iVar6 + 8) == 0) break;
      } while( true );
    }
    piVar3 = *(int **)(iVar1 + 0xa0);
    iVar4 = piVar3[1];
    while (iVar4 != 0) {
      if ((*(byte *)(piVar3 + 5) & 1) != 0) {
        if (((*(int *)(piVar3[0x22] + 8) == 0x31) || (*(int *)(piVar3[0x22] + 8) == 0x13)) &&
           (cVar2 = (**(code **)(*param_1 + 0x30))(param_1,piVar3), cVar2 != '\0')) {
          iVar4 = (**(code **)(*piVar3 + 0x14))(piVar3);
          local_24 = 0xffffffff;
          local_20 = 0xffffffff;
          iVar6 = 0;
          do {
            iVar5 = FUN_0010b0f4(piVar3,0);
            if (*(char *)(iVar6 + 0x10 + iVar5) != '\x01') {
              iVar5 = FUN_0010b0f4(piVar3,1);
              local_24 = (uint)*(byte *)(iVar6 + 0x10 + iVar5);
              if (iVar4 == 2) {
                iVar5 = FUN_0010b0f4(piVar3,2);
                local_20 = (uint)*(byte *)(iVar6 + 0x10 + iVar5);
              }
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 != 4);
          FUN_00110c0c(piVar3,local_24,local_20,0,0,param_1[2]);
        }
        cVar2 = FUN_0011902c(*(undefined4 *)(piVar3[0x22] + 8),param_1[2]);
        if ((cVar2 != '\0') && (piVar3[0x26] == 0)) {
          piVar3[0x26] = 1;
        }
      }
      piVar3 = (int *)piVar3[1];
      iVar4 = piVar3[1];
    }
    iVar1 = *(int *)(iVar1 + 8);
    iVar4 = *(int *)(iVar1 + 8);
  } while( true );
code_r0x001a36a4:
  *(undefined4 *)(iVar6 + 0x9c) = DAT_001cf020;
  iVar6 = *(int *)(iVar6 + 8);
  iVar4 = *(int *)(iVar6 + 8);
  goto joined_r0x001a3644;
}

/* FUN_001a37f8 @ 0x1a37f8 (708 bytes) */
int FUN_001a37f8(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
  int *param_5;
{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = (int *)FUN_0010b180(param_2,param_3);
  cVar1 = (**(code **)(*piVar2 + 0x60))(piVar2);
  if (cVar1 != '\0') {
    piVar2 = (int *)FUN_0010b180(piVar2,1);
  }
  switch(piVar2[0x26]) {
  case 0:
    if ((*(byte *)(piVar2 + 5) & 0x40) == 0) {
      *param_5 = piVar2[0x25] + 0x80;
    }
    else {
      *param_5 = piVar2[0x25];
    }
    *param_4 = 0;
    return 1;
  case 1:
    if ((*(byte *)(piVar2 + 5) & 0x40) == 0) {
      *param_5 = piVar2[0x25] + 0x80;
    }
    else {
      *param_5 = piVar2[0x25];
    }
    *param_4 = 3;
    return 1;
  case 2:
    iVar3 = piVar2[0x25];
    break;
  default:
    return 0;
  case 0xc:
    iVar3 = piVar2[0x25] + 0x700;
    break;
  case 0x26:
    iVar3 = FUN_0010b180(piVar2,1);
    *param_5 = *(int *)(iVar3 + 0x14c) << 10;
    iVar3 = FUN_0010b0f4(piVar2,1);
    cVar1 = FUN_000f56f0(*(undefined4 *)(iVar3 + 0x10),DAT_001cf034);
    if (cVar1 == '\0') {
      iVar3 = FUN_0010b0f4(piVar2,1);
      cVar1 = FUN_000f56f0(*(undefined4 *)(iVar3 + 0x10),DAT_001cf030);
      if (cVar1 == '\0') {
        iVar3 = FUN_0010b0f4(piVar2,1);
        cVar1 = FUN_000f56f0(*(undefined4 *)(iVar3 + 0x10),DAT_001cf02c);
        if (cVar1 == '\0') {
          iVar3 = FUN_0010b0f4(piVar2,1);
          cVar1 = FUN_000f56f0(*(undefined4 *)(iVar3 + 0x10),DAT_001cf028);
          if (cVar1 != '\0') {
            iVar3 = *param_5;
            iVar4 = FUN_0010b6e4(piVar2,0);
            *param_5 = iVar3 + 0x400 + iVar4;
          }
        }
        else {
          iVar3 = *param_5;
          iVar4 = FUN_0010b6e4(piVar2,0);
          *param_5 = iVar3 + 0x300 + iVar4;
        }
      }
      else {
        iVar3 = *param_5;
        iVar4 = FUN_0010b6e4(piVar2,0);
        *param_5 = iVar3 + 0x200 + iVar4;
      }
    }
    else {
      iVar3 = *param_5;
      iVar4 = FUN_0010b6e4(piVar2,0);
      *param_5 = iVar3 + 0x100 + iVar4;
    }
    goto LAB_001a39be;
  case 0x28:
    iVar3 = FUN_0010b6e4(param_2,param_3);
    iVar3 = iVar3 + 0x500;
    break;
  case 0x29:
    iVar3 = FUN_0010b6e4(param_2,param_3);
    iVar3 = iVar3 + 0x600;
    goto LAB_001a3974;
  case 0x37:
    iVar3 = piVar2[0x25];
LAB_001a3974:
    *param_5 = iVar3;
    *param_4 = 1;
    return 1;
  }
  *param_5 = iVar3;
LAB_001a39be:
  *param_4 = 2;
  return 1;
}

/* FUN_001a3b9c @ 0x1a3b9c (457 bytes) */
int FUN_001a3b9c(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x4c))(param_1,param_2);
  if (iVar1 != 0) {
    if (iVar1 == 3) {
      param_1[7] = *(int *)(param_2[0x22] + 8);
      param_1[6] = *(int *)(param_2[0x22] + 8);
      iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
      if (0 < iVar1) {
        ((int (*)())FUN_001a37f8)(param_1,param_2,1,param_1 + 8,param_1 + 0xb);
        iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
        if (1 < iVar1) {
          ((int (*)())FUN_001a37f8)(param_1,param_2,2,param_1 + 9,param_1 + 0xc);
          iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
          if (2 < iVar1) {
            ((int (*)())FUN_001a37f8)(param_1,param_2,3,param_1 + 10,param_1 + 0xd);
          }
        }
      }
    }
    else if (iVar1 == 2) {
      param_1[7] = *(int *)(param_2[0x22] + 8);
      if (param_2[0x26] != 1) {
        param_1[6] = *(int *)(param_2[0x22] + 8);
      }
      iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
      if (0 < iVar1) {
        ((int (*)())FUN_001a37f8)(param_1,param_2,1,param_1 + 10,param_1 + 0xd);
        return;
      }
    }
    else {
      param_1[6] = *(int *)(param_2[0x22] + 8);
      if (param_2[0x26] == 1) {
        param_1[7] = *(int *)(param_2[0x22] + 8);
      }
      iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
      if (0 < iVar1) {
        ((int (*)())FUN_001a37f8)(param_1,param_2,1,param_1 + 8,param_1 + 0xb);
        iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
        if (1 < iVar1) {
          ((int (*)())FUN_001a37f8)(param_1,param_2,2,param_1 + 9,param_1 + 0xc);
        }
      }
    }
  }
  return;
}

/* FUN_001a3d66 @ 0x1a3d66 (647 bytes) */
int FUN_001a3d66(param_1, param_2)
  int *param_1;
  int *param_2;
{
  char cVar1;
  int iVar2;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  local_18 = param_1[8];
  local_14 = param_1[9];
  local_10 = param_1[10];
  local_24 = param_1[0xb];
  local_20 = param_1[0xc];
  local_1c = param_1[0xd];
  iVar2 = (**(code **)(*param_1 + 0x4c))(param_1,param_2);
  if (iVar2 != 0) {
    if (iVar2 == 3) {
      if (-1 < param_1[7]) {
        return 0;
      }
      if (-1 < param_1[6]) {
        return 0;
      }
      iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
      if (iVar2 < 1) {
        return 1;
      }
      ((int (*)())FUN_001a37f8)(param_1,param_2,1,&local_18,&local_24);
      iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
      if (1 < iVar2) {
        ((int (*)())FUN_001a37f8)(param_1,param_2,2,&local_14,&local_20);
        iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
        if (2 < iVar2) {
          ((int (*)())FUN_001a37f8)(param_1,param_2,3,&local_10,&local_1c);
        }
      }
      cVar1 = ((int (*)())FUN_001a3050)(param_1,&local_18,&local_24,*(int *)(param_2[0x22] + 8) == 0x14);
    }
    else if (iVar2 == 2) {
      if (-1 < param_1[7]) {
        return 0;
      }
      if ((-1 < param_1[6]) && (param_2[0x26] != 1)) {
        return 0;
      }
      iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
      if (iVar2 < 1) {
        return 1;
      }
      ((int (*)())FUN_001a37f8)(param_1,param_2,1,&local_10,&local_1c);
      cVar1 = ((int (*)())FUN_001a3050)(param_1,&local_18,&local_24,0);
    }
    else {
      if (-1 < param_1[6]) {
        return 0;
      }
      if ((-1 < param_1[7]) && (param_2[0x26] == 1)) {
        return 0;
      }
      iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
      if (iVar2 < 1) {
        return 1;
      }
      ((int (*)())FUN_001a37f8)(param_1,param_2,1,&local_18,&local_24);
      iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
      if (1 < iVar2) {
        ((int (*)())FUN_001a37f8)(param_1,param_2,2,&local_14,&local_20);
      }
      cVar1 = ((int (*)())FUN_001a3050)(param_1,&local_18,&local_24,0);
    }
    if (cVar1 == '\0') {
      return 0;
    }
  }
  return 1;
}

/* FUN_001a3fee @ 0x1a3fee (3159 bytes) */
int FUN_001a3fee(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int local_a8;
  int *local_a4;
  undefined1 local_95;
  int local_8c;
  int local_88;
  int local_84;
  int local_74;
  uint local_6c;
  uint local_68;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20 [4];
  
  iVar1 = param_2[0x56];
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x3f4);
  piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  (**(code **)(*piVar3 + 0x80))(piVar3);
  piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  cVar4 = (**(code **)(*piVar3 + 0x88))(piVar3);
  if (cVar4 == '\0') {
    local_95 = 0;
    local_a4 = param_2 + 0x29;
    local_a8 = 0x98;
    for (local_84 = 1; iVar5 = (**(code **)(*param_2 + 0x14))(param_2), local_84 <= iVar5;
        local_84 = local_84 + 1) {
      if ((*(byte *)(local_a8 + 0x20 + (int)param_2) & 2) != 0) {
        cVar4 = FUN_00119170(*(undefined4 *)(param_2[0x22] + 8),*(undefined4 *)(param_1 + 8));
        if (cVar4 == '\0') {
          uVar6 = FUN_0010b180(param_2,local_84);
          iVar5 = FUN_0010a17a(0x17,*(undefined4 *)(param_1 + 8));
          *(undefined4 *)(iVar5 + 0x94) = *(undefined4 *)(iVar5 + 0x14c);
          *(undefined4 *)(iVar5 + 0x98) = 0;
          iVar7 = FUN_0010b0f4(param_2,local_84);
          uVar9 = FUN_000f5bdc(*(undefined4 *)(iVar7 + 0x10));
          uVar10 = FUN_000f5a44(DAT_001cf024,uVar9);
          *(undefined4 *)(iVar5 + 0x9c) = uVar10;
          *(undefined4 *)(iVar5 + 0xc) = uVar9;
          FUN_00109c0e(iVar5 + 0xa4,1,0);
          FUN_00109c0e(iVar5 + 0xbc,1,1);
          FUN_0010ba02(iVar5,1,uVar6,0,*(undefined4 *)(param_1 + 8));
          FUN_0010ba02(iVar5,2,uVar6,0,*(undefined4 *)(param_1 + 8));
          iVar5 = FUN_0017493c(iVar1,iVar5);
          if (*(int *)(iVar5 + 0x158) == 0) {
            *(int *)(iVar2 + 0x238) = *(int *)(iVar2 + 0x238) + 1;
            FUN_000e956e(iVar1,param_2,iVar5);
          }
          FUN_0010ba02(param_2,local_84,iVar5,0,*(undefined4 *)(param_1 + 8));
          FUN_00109c0e((int)param_2 + local_a8 + 0xc,2,0);
          local_95 = 1;
        }
        else {
          FUN_00109c0e(local_a4,2,0);
          local_95 = 1;
        }
      }
      local_a8 = local_a8 + 0x18;
      local_a4 = local_a4 + 6;
    }
  }
  else {
    local_95 = 0;
  }
  piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  cVar4 = (**(code **)(*piVar3 + 0x84))(piVar3);
  if ((cVar4 == '\0') && (*(int *)(param_2[0x22] + 8) == 0x25)) {
    local_5c = 0;
    local_58 = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_30 = 0;
    uVar6 = FUN_0010b0f4(param_2,2);
    FUN_0010a40a(&local_5c,uVar6);
    uVar6 = FUN_0010b0f4(param_2,3);
    FUN_0010a40a(&local_44,uVar6);
    iVar5 = FUN_0010a17a(0x29,*(undefined4 *)(param_1 + 8));
    *(undefined4 *)(iVar5 + 0x94) = *(undefined4 *)(iVar5 + 0x14c);
    *(undefined4 *)(iVar5 + 0x98) = 0;
    iVar7 = FUN_0010b0f4(param_2,1);
    iVar7 = FUN_000f5bdc(*(undefined4 *)(iVar7 + 0x10));
    uVar6 = FUN_000f5a44(DAT_001cf024,iVar7);
    *(undefined4 *)(iVar5 + 0x9c) = uVar6;
    *(int *)(iVar5 + 0xc) = iVar7;
    FUN_0010b85e(iVar5,1,param_2,1);
    FUN_000fa0d2(iVar5,iVar2,2,0,0,0,0);
    *(int *)(iVar5 + 0x160) = *(int *)(iVar2 + 0x46c) + 2;
    FUN_000e956e(iVar1,param_2,iVar5);
    iVar12 = FUN_0010a17a(0x12,*(undefined4 *)(param_1 + 8));
    *(undefined4 *)(iVar12 + 0x94) = *(undefined4 *)(iVar12 + 0x14c);
    *(undefined4 *)(iVar12 + 0x98) = 0;
    iVar13 = FUN_0010b0f4(iVar5,0);
    *(undefined4 *)(iVar12 + 0x9c) = *(undefined4 *)(iVar13 + 0x10);
    *(int *)(iVar12 + 0xc) = iVar7;
    FUN_0010ba02(iVar12,1,iVar5,0,*(undefined4 *)(param_1 + 8));
    FUN_00109c0e(iVar12 + 0xa4,1,1);
    FUN_000fa0d2(iVar12,iVar2,2,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
    *(int *)(iVar12 + 0x160) = *(int *)(iVar2 + 0x46c) + 1;
    FUN_000e956e(iVar1,param_2,iVar12);
    iVar13 = FUN_0010a17a(0x13,*(undefined4 *)(param_1 + 8));
    *(undefined4 *)(iVar13 + 0x94) = *(undefined4 *)(iVar13 + 0x14c);
    *(undefined4 *)(iVar13 + 0x98) = 0;
    iVar11 = FUN_0010b0f4(iVar5,0);
    *(undefined4 *)(iVar13 + 0x9c) = *(undefined4 *)(iVar11 + 0x10);
    *(int *)(iVar13 + 0xc) = iVar7;
    FUN_0010ba02(iVar13,1,iVar5,0,*(undefined4 *)(param_1 + 8));
    uVar6 = FUN_0010b0f4(iVar13,2);
    FUN_0010a40a(uVar6,&local_5c);
    *(int *)(iVar13 + 0x160) = *(int *)(iVar2 + 0x46c) + 1;
    FUN_000e956e(iVar1,param_2,iVar13);
    iVar11 = param_2[0x58] - *(int *)(iVar2 + 0x46c);
    if (iVar11 < 0) {
      iVar11 = 0;
    }
    FUN_001a7d72(param_2);
    FUN_0010da48(param_2,0x14,*(undefined4 *)(iVar2 + 8));
    param_2[0x25] = param_2[0x53];
    param_2[0x26] = 0;
    iVar5 = FUN_0010b0f4(iVar5,0);
    param_2[0x27] = *(int *)(iVar5 + 0x10);
    param_2[3] = iVar7;
    FUN_0010ba02(param_2,1,iVar12,0,*(undefined4 *)(param_1 + 8));
    uVar6 = FUN_0010b0f4(param_2,2);
    FUN_0010a40a(uVar6,&local_44);
    FUN_0010ba02(param_2,3,iVar13,0,*(undefined4 *)(param_1 + 8));
    param_2[0x58] = iVar11 + *(int *)(iVar2 + 0x46c);
    FUN_000e9596(iVar1,iVar13,param_2);
  }
  local_8c = -1;
  local_88 = -1;
  local_74 = 1;
  iVar5 = (**(code **)(*param_2 + 0x14))(param_2);
  if (0 < iVar5) {
    do {
      uVar6 = FUN_0010b180(param_2,local_74);
      cVar4 = ((int (*)())FUN_001a37f8)(param_1,param_2,local_74,&local_24,&local_28);
      if (cVar4 != '\0') {
        if (local_24 == 2) {
          if ((local_8c < 0) || (local_8c == local_28)) {
            local_8c = local_28;
          }
          else {
            iVar5 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
            *(undefined4 *)(iVar5 + 0x94) = *(undefined4 *)(iVar5 + 0x14c);
            *(undefined4 *)(iVar5 + 0x98) = 0;
            FUN_0010ba02(iVar5,1,uVar6,0,*(undefined4 *)(param_1 + 8));
            iVar12 = 1;
            local_68 = 0;
            iVar7 = (**(code **)(*param_2 + 0x14))(param_2);
            if (0 < iVar7) {
              do {
                cVar4 = ((int (*)())FUN_001a37f8)(param_1,param_2,iVar12,&local_2c,local_20);
                if (((cVar4 != '\0') && (local_2c == local_24)) && (local_20[0] == local_28)) {
                  iVar7 = FUN_0010b0f4(param_2,iVar12);
                  uVar8 = FUN_000f5bdc(*(undefined4 *)(iVar7 + 0x10));
                  local_68 = local_68 | uVar8;
                  FUN_0010ba02(param_2,iVar12,iVar5,0,*(undefined4 *)(param_1 + 8));
                }
                iVar12 = iVar12 + 1;
                iVar7 = (**(code **)(*param_2 + 0x14))(param_2);
              } while (iVar12 <= iVar7);
            }
            uVar9 = FUN_000f5a44(DAT_001cf024,local_68);
            *(undefined4 *)(iVar5 + 0x9c) = uVar9;
            *(uint *)(iVar5 + 0xc) = local_68;
            iVar7 = FUN_0017493c(iVar1,iVar5);
            if (*(int *)(iVar7 + 0x158) == 0) {
              *(int *)(iVar2 + 0x238) = *(int *)(iVar2 + 0x238) + 1;
              FUN_000e956e(iVar1,param_2,iVar7);
              local_95 = 1;
            }
            else {
              iVar13 = 1;
              iVar12 = (**(code **)(*param_2 + 0x14))(param_2);
              if (0 < iVar12) {
                do {
                  iVar12 = FUN_0010b180(param_2,iVar13);
                  if (iVar5 == iVar12) {
                    FUN_0010ba02(param_2,iVar13,iVar7,0,*(undefined4 *)(param_1 + 8));
                  }
                  iVar13 = iVar13 + 1;
                  iVar12 = (**(code **)(*param_2 + 0x14))(param_2);
                } while (iVar13 <= iVar12);
              }
              local_95 = 1;
            }
          }
        }
        if (local_24 == 1) {
          if ((local_88 < 0) || (local_88 == local_28)) {
            local_88 = local_28;
          }
          else {
            iVar5 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
            *(undefined4 *)(iVar5 + 0x94) = *(undefined4 *)(iVar5 + 0x14c);
            *(undefined4 *)(iVar5 + 0x98) = 0;
            FUN_0010ba02(iVar5,1,uVar6,0,*(undefined4 *)(param_1 + 8));
            iVar12 = 1;
            local_6c = 0;
            iVar7 = (**(code **)(*param_2 + 0x14))(param_2);
            if (0 < iVar7) {
              do {
                local_2c = 4;
                cVar4 = ((int (*)())FUN_001a37f8)(param_1,param_2,iVar12,&local_2c,local_20);
                if (((cVar4 != '\0') && (local_2c == local_24)) && (local_20[0] == local_28)) {
                  iVar7 = FUN_0010b0f4(param_2,iVar12);
                  uVar8 = FUN_000f5bdc(*(undefined4 *)(iVar7 + 0x10));
                  local_6c = local_6c | uVar8;
                  FUN_0010ba02(param_2,iVar12,iVar5,0,*(undefined4 *)(param_1 + 8));
                }
                iVar12 = iVar12 + 1;
                iVar7 = (**(code **)(*param_2 + 0x14))(param_2);
              } while (iVar12 <= iVar7);
            }
            uVar6 = FUN_000f5a44(DAT_001cf024,local_6c);
            *(undefined4 *)(iVar5 + 0x9c) = uVar6;
            *(uint *)(iVar5 + 0xc) = local_6c;
            iVar7 = FUN_0017493c(iVar1,iVar5);
            if (*(int *)(iVar7 + 0x158) == 0) {
              *(int *)(iVar2 + 0x238) = *(int *)(iVar2 + 0x238) + 1;
              FUN_000e956e(iVar1,param_2,iVar7);
              local_95 = 1;
            }
            else {
              iVar13 = 1;
              iVar12 = (**(code **)(*param_2 + 0x14))(param_2);
              if (0 < iVar12) {
                do {
                  iVar12 = FUN_0010b180(param_2,iVar13);
                  if (iVar5 == iVar12) {
                    FUN_0010ba02(param_2,iVar13,iVar7,0,*(undefined4 *)(param_1 + 8));
                  }
                  iVar13 = iVar13 + 1;
                  iVar12 = (**(code **)(*param_2 + 0x14))(param_2);
                } while (iVar13 <= iVar12);
              }
              local_95 = 1;
            }
          }
        }
      }
      local_74 = local_74 + 1;
      iVar5 = (**(code **)(*param_2 + 0x14))(param_2);
    } while (local_74 <= iVar5);
  }
  return local_95;
}

/* FUN_001a4c4e @ 0x1a4c4e (651 bytes) */
int FUN_001a4c4e(param_1, param_2)
  int param_1;
  int *param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  if ((short)param_2[5] < 0) {
    return 0;
  }
  cVar1 = FUN_0011902c(*(undefined4 *)(param_2[0x22] + 8),*(undefined4 *)(param_1 + 8));
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
    if ((iVar2 < 3) && (*(int *)(param_2[0x22] + 8) != 0x32)) {
      return 1;
    }
  }
  else {
    iVar2 = FUN_000f60f4(param_2);
    if (((iVar2 < 2) && (iVar2 = *(int *)(param_2[0x22] + 8), iVar2 != 0xa5)) &&
       (((*(byte *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 10) & 1) != 0 ||
        ((iVar2 != 0x4c && (iVar2 != 0x4d)))))) {
      for (iVar2 = 0; iVar3 = (**(code **)(*param_2 + 0x14))(param_2), iVar2 <= iVar3;
          iVar2 = iVar2 + 1) {
        iVar3 = FUN_0010b7c8(param_2,iVar2);
        if (iVar3 != 0) {
          return 3;
        }
      }
      iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
      if (1 < iVar2) {
        piVar4 = (int *)FUN_0010b180(param_2,1);
        piVar5 = (int *)FUN_0010b180(param_2,2);
        iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
        if (2 < iVar2) {
          piVar6 = (int *)FUN_0010b180(param_2,3);
          if (piVar5 != piVar6) {
            return 3;
          }
          iVar2 = FUN_0010b0f4(param_2,2);
          iVar2 = *(int *)(iVar2 + 0x10);
          iVar3 = FUN_0010b0f4(param_2,3);
          if (*(int *)(iVar3 + 0x10) != iVar2) {
            return 3;
          }
          if ((*(byte *)(param_2 + 0x34) & 1) != (*(byte *)(param_2 + 0x3a) & 1)) {
            return 3;
          }
        }
        if (piVar4 != piVar5) {
          if (piVar4[0x20] == 0) {
            return 3;
          }
          cVar1 = FUN_0012dfd8(piVar4[0x26]);
          if (cVar1 == '\0') {
            return 3;
          }
          if ((*(byte *)(piVar4 + 5) & 2) != 0) {
            return 3;
          }
          cVar1 = (**(code **)(*piVar4 + 0x50))(piVar4);
          if (cVar1 != '\0') {
            return 3;
          }
          if (piVar5[0x20] == 0) {
            return 3;
          }
          cVar1 = FUN_0012dfd8(piVar5[0x26]);
          if (cVar1 == '\0') {
            return 3;
          }
          if ((*(byte *)(piVar5 + 5) & 2) != 0) {
            return 3;
          }
          cVar1 = (**(code **)(*piVar5 + 0x50))(piVar5);
          if (cVar1 != '\0') {
            return 3;
          }
          if (piVar4[0x26] != piVar5[0x26]) {
            return 3;
          }
          if (((*(byte *)(piVar4 + 5) & 0x40) != 0) && ((*(byte *)(piVar5 + 5) & 0x40) != 0)) {
            if (piVar4[0x25] != piVar5[0x25]) {
              return 3;
            }
            return 2;
          }
          cVar1 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x25);
          if (cVar1 == '\0') {
            return 3;
          }
          if ((*(byte *)(piVar4 + 5) & 0x20) != 0) {
            return 3;
          }
          if ((*(byte *)(piVar5 + 5) & 0x20) != 0) {
            return 3;
          }
        }
      }
      return 2;
    }
  }
  return 3;
}

/* FUN_001a4eda @ 0x1a4eda (355 bytes) */
int FUN_001a4eda(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (((*(byte *)(param_2 + 0x14) & 2) == 0) &&
     ((*(int *)(param_2 + 0x98) == 0 || (*(int *)(param_2 + 0x98) == 1)))) {
    iVar2 = *(int *)(param_2 + 0x88);
    iVar3 = *(int *)(iVar2 + 8);
    if ((iVar3 == 0x66) || (iVar3 == 0x36)) {
      return 1;
    }
    if (iVar3 == 0x31) {
      iVar2 = FUN_000f60f4(param_2);
      if (iVar2 == 1) {
        return 1;
      }
      iVar2 = *(int *)(param_2 + 0x88);
    }
    if (((*(int *)(iVar2 + 8) == 0x13) && (iVar2 = FUN_000f60f4(param_2), iVar2 == 1)) &&
       ((*(byte *)(param_2 + 0xd0) & 1) == (*(byte *)(param_2 + 0xb8) & 1))) {
      iVar2 = FUN_0010b180(param_2,1);
      iVar3 = FUN_0010b180(param_2,2);
      if (iVar2 == iVar3) {
        return 1;
      }
      piVar4 = (int *)FUN_0010b180(param_2,1);
      if (((((piVar4[0x20] != 0) && (cVar1 = FUN_0012dfd8(piVar4[0x26]), cVar1 != '\0')) &&
           (((*(byte *)(piVar4 + 5) & 2) == 0 &&
            ((cVar1 = (**(code **)(*piVar4 + 0x50))(piVar4), cVar1 == '\0' &&
             (piVar4 = (int *)FUN_0010b180(param_2,2), piVar4[0x20] != 0)))))) &&
          (cVar1 = FUN_0012dfd8(piVar4[0x26]), cVar1 != '\0')) &&
         (((*(byte *)(piVar4 + 5) & 2) == 0 &&
          (cVar1 = (**(code **)(*piVar4 + 0x50))(piVar4), cVar1 == '\0')))) {
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_001a503e @ 0x1a503e (10 bytes) */
int FUN_001a503e()
{
  return 0x80;
}

/* FUN_001a5048 @ 0x1a5048 (57 bytes) */
undefined4 FUN_001a5048(undefined4 param_1,float param_2)

{
  if (((param_2 != FLOAT_001c5b9c) && (param_2 != FLOAT_001c5bd4)) && (param_2 != FLOAT_001c5ba4)) {
    return 0;
  }
  return 1;
}

/* FUN_001a5082 @ 0x1a5082 (223 bytes) */
int FUN_001a5082(param_1)
  int param_1;
{
  float *pfVar1;
  int iVar2;
  longdouble lVar3;
  double dVar4;
  float fVar5;
  int local_38;
  int local_20;
  
  local_20 = 0;
  local_38 = param_1 + 0x1740;
  do {
    pfVar1 = (float *)(local_38 + 4);
    iVar2 = 0;
    dVar4 = (double)local_20 - DOUBLE_001cf3c8;
LAB_001a50e5:
    do {
      if (local_20 == 0) {
        if (iVar2 == 0) {
          *pfVar1 = FLOAT_001c5c68;
          iVar2 = 1;
          pfVar1 = pfVar1 + 1;
          goto LAB_001a50e5;
        }
        fVar5 = (float)iVar2 * FLOAT_001c5c28 * FLOAT_001c5c6c;
      }
      else {
        lVar3 = (longdouble)_pow(0,0x40000000,dVar4);
        fVar5 = (float)lVar3 * ((float)iVar2 * FLOAT_001c5c28 + FLOAT_001c5ba4);
      }
      *pfVar1 = fVar5;
      iVar2 = iVar2 + 1;
      pfVar1 = pfVar1 + 1;
    } while (iVar2 != 8);
    local_20 = local_20 + 1;
    local_38 = local_38 + 0x20;
    if (local_20 == 0x10) {
      return;
    }
  } while( true );
}

/* FUN_001a5162 @ 0x1a5162 (169 bytes) */
undefined4 FUN_001a5162(int param_1,float param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  
  if ((FLOAT_001c5b9c < param_2) && (-1 < (int)param_2)) {
    uVar1 = (uint)param_2 >> 0x17 & 0xff;
    *param_3 = uVar1;
    if (uVar1 == 0) {
      uVar1 = *param_3;
    }
    else {
      *param_3 = uVar1 - 0x78;
      if (0xf < uVar1 - 0x78) {
        return 0;
      }
      uVar1 = *param_3;
    }
    if (uVar1 == 0) {
      uVar1 = 0;
      do {
        if (param_2 == *(float *)(param_1 + 0x1744)) {
          *param_4 = uVar1;
          return 1;
        }
        uVar1 = uVar1 + 1;
        param_1 = param_1 + 4;
      } while (uVar1 != 8);
    }
    else {
      *param_4 = (uint)param_2 & 0x7fffff;
      if (((uint)param_2 & 0xfffff) == 0) {
        *param_4 = ((uint)param_2 & 0x7fffff) >> 0x14;
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_001a520c @ 0x1a520c (117 bytes) */
int FUN_001a520c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  char *pcVar4;
  float fVar5;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  
  fVar5 = 0.0;
  bVar1 = false;
  iVar3 = 1;
  pcVar4 = &STACKARG(0xc);
  do {
    if (*pcVar4 != '\x04') {
      if (bVar1) {
        if (fVar5 != *(float *)(param_2 + -4 + iVar3 * 4)) {
          return 0;
        }
        bVar1 = true;
      }
      else {
        fVar5 = *(float *)(param_2 + -4 + iVar3 * 4);
        bVar1 = true;
      }
    }
    iVar3 = iVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (iVar3 != 5);
  uVar2 = ((undefined4 (*)())FUN_001a5162)(param_1,fVar5,local_10,local_14);
  return uVar2;
}

/* FUN_001a5282 @ 0x1a5282 (293 bytes) */
int FUN_001a5282(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  float *param_3;
  int *param_4;
{
  undefined4 uVar1;
  bool bVar2;
  int *piVar3;
  float *pfVar4;
  int iVar5;
  float fVar6;
  float *local_44;
  undefined4 uStack_30;
  float local_2c [4];
  float local_1c [3];
  
  if (*param_4 == DAT_001cf044) {
    return 0;
  }
  local_44 = param_3;
  bVar2 = true;
  (*(unsigned char *)((unsigned char *)&(uStack_30) + 3)) = '\x01';
  fVar6 = 0.0;
  iVar5 = 0;
  piVar3 = param_4;
  do {
    if ((char)*piVar3 != '\x04') {
      if (bVar2) {
        fVar6 = *local_44;
        bVar2 = false;
      }
      else if (fVar6 == *local_44) {
        bVar2 = false;
      }
      else {
        (*(unsigned char *)((unsigned char *)&(uStack_30) + 3)) = '\0';
      }
    }
    iVar5 = iVar5 + 1;
    piVar3 = (int *)((int)piVar3 + 1);
    local_44 = local_44 + 1;
  } while (iVar5 != 4);
  if ((*(unsigned char *)((unsigned char *)&(uStack_30) + 3)) == '\0') {
    iVar5 = FUN_000f8aa6(param_2,param_3,*param_4);
  }
  else {
    pfVar4 = local_2c;
    do {
      *pfVar4 = NAN;
      pfVar4 = pfVar4 + 1;
    } while (pfVar4 != local_1c);
    iVar5 = 1;
    do {
      (&uStack_30)[iVar5] = fVar6;
      iVar5 = iVar5 + 1;
    } while (iVar5 != 5);
    iVar5 = FUN_000f8aa6(param_2,local_2c,DAT_001cf040);
  }
  if (iVar5 == 0) {
    uVar1 = *(undefined4 *)(param_2 + 0x3a0);
    iVar5 = FUN_000f80ae(uVar1,param_3,param_4);
    if ((iVar5 == 0) && (iVar5 = FUN_000f7a2e(uVar1,param_3,param_4), iVar5 == 0)) {
      return 0;
    }
  }
  return iVar5;
}

/* FUN_001a53a8 @ 0x1a53a8 (290 bytes) */
int FUN_001a53a8(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  float fVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  float *pfVar5;
  float local_34 [3];
  undefined4 local_28;
  byte bStack_25;
  undefined4 local_24;
  undefined4 local_20;
  
  local_20 = param_4;
  piVar3 = (int *)FUN_0010b180(param_2,param_3);
  cVar2 = (**(code **)(*piVar3 + 0x48))(piVar3);
  if (cVar2 == '\0') {
    return 0;
  }
  iVar4 = FUN_0010b0f4(param_2,param_3);
  local_24 = *(undefined4 *)(iVar4 + 0x10);
  iVar4 = 1;
  pfVar5 = local_34;
  do {
    pfVar5 = (float *)((int)pfVar5 + 4);
    pfVar5[0xffffffff] = 0.0;
    if (*(char *)((int)&local_24 + iVar4 + 3) == '\0') {
      if (((int)(char)piVar3[0x57] >> ((&bStack_25)[iVar4] & 0x1f) & 1U) == 0) {
        return 0;
      }
      fVar1 = (float)piVar3[(uint)(&bStack_25)[iVar4] * 6 + 8];
      if ((fVar1 != 0.0) && (fVar1 != FLOAT_001c5ba4)) {
        if (fVar1 != FLOAT_001c5bd4) {
          return 0;
        }
        if (NAN(fVar1) || NAN(FLOAT_001c5bd4)) {
          return 0;
        }
      }
      pfVar5[0xffffffff] = fVar1;
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 5) {
      FUN_000fa0d2(param_2,*(undefined4 *)(param_5 + 0x3f4),param_3,local_34[0],local_34[1],
                   local_34[2],local_28);
      return 1;
    }
  } while( true );
}

/* FUN_001a54ca @ 0x1a54ca (18 bytes) */
int FUN_001a54ca(param_1)
  int param_1;
{
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x2c) = 0x100;
  return;
}

/* FUN_001a54dc @ 0x1a54dc (310 bytes) */
int FUN_001a54dc(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  float *param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  float fVar1;
  bool bVar2;
  char cVar3;
  char *pcVar4;
  float *pfVar5;
  char *pcVar6;
  int iVar7;
  float local_20;
  
  *param_3 = 0xffffffff;
  pcVar4 = (char *)&param_4;
  pfVar5 = param_2;
  pcVar6 = pcVar4;
  while ((((*pcVar6 == '\x04' || (fVar1 = *pfVar5, fVar1 == 0.0)) || (fVar1 == FLOAT_001c5bd4)) ||
         ((fVar1 == FLOAT_001c5ba4 && (!NAN(fVar1) && !NAN(FLOAT_001c5ba4)))))) {
    pcVar6 = pcVar6 + 1;
    pfVar5 = pfVar5 + 1;
    if (pcVar6 == (char *)&param_5) {
      iVar7 = 1;
      do {
        if (*pcVar4 == '\x04') {
          param_2[iVar7 + -1] = 0.0;
        }
        iVar7 = iVar7 + 1;
        pcVar4 = pcVar4 + 1;
      } while (iVar7 != 5);
      return 1;
    }
  }
  cVar3 = FUN_000e1402(param_5,0x2f);
  if (cVar3 == '\0') {
    return 0;
  }
  bVar2 = true;
  local_20 = 0.0;
  pfVar5 = param_2;
  do {
    if (*pcVar4 != '\x04') {
      if (bVar2) {
        local_20 = *pfVar5;
        bVar2 = false;
      }
      else {
        if (local_20 != *pfVar5) {
          return 0;
        }
        if (NAN(local_20) || NAN(*pfVar5)) {
          return 0;
        }
      }
    }
    pcVar4 = pcVar4 + 1;
    pfVar5 = pfVar5 + 1;
    if (pcVar4 == (char *)&param_5) {
      cVar3 = (**(code **)(*param_1 + 0x98))(param_1,param_2,param_4);
      if (cVar3 != '\0') {
        iVar7 = 1;
        do {
          param_2[iVar7 + -1] = local_20;
          iVar7 = iVar7 + 1;
        } while (iVar7 != 5);
        *param_3 = 3;
        return 1;
      }
      return 0;
    }
  } while( true );
}

/* FUN_001a5612 @ 0x1a5612 (165 bytes) */
int FUN_001a5612(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_000e27f6(param_2,100);
  *puVar1 = PTR_DAT_002139f5 + 8;
  puVar1[2] = param_2;
  puVar1[1] = 0;
  *puVar1 = PTR_DAT_00213a05 + 8;
  FUN_0019ca40(puVar1 + 10);
  FUN_0019cafe(puVar1);
  puVar1[0x18] = 0;
  *puVar1 = PTR_DAT_00213a41 + 8;
  *(undefined4 **)(param_1 + 0x60) = puVar1;
  puVar1 = (undefined4 *)FUN_000e27f6(param_2,0xc);
  *puVar1 = PTR_DAT_00213a01 + 8;
  puVar1[1] = 1;
  puVar1[2] = 0;
  *(undefined4 **)(param_1 + 100) = puVar1;
  return;
}

/* FUN_001a56ca @ 0x1a56ca (502 bytes) */
int FUN_001a56ca(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_00130550(param_1,param_2,0);
  *param_1 = &PTR_FUN_001fdbc8;
  param_1[7] = 0;
  param_1[8] = 0x7fffffff;
  param_1[0xf] = 0x10;
  param_1[0x10] = 0x200;
  param_1[0x11] = 4;
  param_1[0x12] = 4;
  param_1[0x14] = 0x20;
  param_1[0x13] = 4;
  param_1[9] = 0x20;
  param_1[0xb] = 0x100;
  param_1[10] = 0x10;
  param_1[0xe] = 0x89;
  param_1[0x15] = 0x400;
  FUN_0011325a(param_1);
  FUN_00113210(param_1,0x2f);
  FUN_00113210(param_1,0x30);
  FUN_00113210(param_1,0x31);
  FUN_00113210(param_1,0x34);
  FUN_00113210(param_1,0x35);
  FUN_00113210(param_1,0x36);
  FUN_00113210(param_1,0x37);
  FUN_00113210(param_1,0x38);
  FUN_00113210(param_1,0x39);
  FUN_00113210(param_1,0x3a);
  FUN_00113210(param_1,0x3b);
  FUN_00113210(param_1,0x3c);
  FUN_00113210(param_1,0x3d);
  FUN_00113210(param_1,0x40);
  FUN_00113210(param_1,0x42);
  FUN_00113210(param_1,0x47);
  FUN_00113210(param_1,0x4a);
  FUN_00113210(param_1,0x4b);
  param_1[2] = param_1[2] & 0xfffdffff | 0x1d80;
  FUN_001b2fba(param_1);
  if (param_3 != '\0') {
    ((int (*)())FUN_001a5612)(param_1,param_2);
  }
  ((int (*)())FUN_001a5082)();
  return;
}

/* FUN_001a58de @ 0x1a58de (502 bytes) */
int FUN_001a58de(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_00130550(param_1,param_2,0);
  *param_1 = &PTR_FUN_001fdbc8;
  param_1[7] = 0;
  param_1[8] = 0x7fffffff;
  param_1[0xf] = 0x10;
  param_1[0x10] = 0x200;
  param_1[0x11] = 4;
  param_1[0x12] = 4;
  param_1[0x14] = 0x20;
  param_1[0x13] = 4;
  param_1[9] = 0x20;
  param_1[0xb] = 0x100;
  param_1[10] = 0x10;
  param_1[0xe] = 0x89;
  param_1[0x15] = 0x400;
  FUN_0011325a(param_1);
  FUN_00113210(param_1,0x2f);
  FUN_00113210(param_1,0x30);
  FUN_00113210(param_1,0x31);
  FUN_00113210(param_1,0x34);
  FUN_00113210(param_1,0x35);
  FUN_00113210(param_1,0x36);
  FUN_00113210(param_1,0x37);
  FUN_00113210(param_1,0x38);
  FUN_00113210(param_1,0x39);
  FUN_00113210(param_1,0x3a);
  FUN_00113210(param_1,0x3b);
  FUN_00113210(param_1,0x3c);
  FUN_00113210(param_1,0x3d);
  FUN_00113210(param_1,0x40);
  FUN_00113210(param_1,0x42);
  FUN_00113210(param_1,0x47);
  FUN_00113210(param_1,0x4a);
  FUN_00113210(param_1,0x4b);
  param_1[2] = param_1[2] & 0xfffdffff | 0x1d80;
  FUN_001b2fba(param_1);
  if (param_3 != '\0') {
    ((int (*)())FUN_001a5612)(param_1,param_2);
  }
  ((int (*)())FUN_001a5082)();
  return;
}

/* FUN_001a5af4 @ 0x1a5af4 (1555 bytes) */
int FUN_001a5af4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
  int param_4;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_5c;
  undefined1 local_4c;
  int local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  uVar1 = *(undefined4 *)(param_4 + 8);
  iVar7 = *(int *)(param_3[0x22] + 8);
  if (((((iVar7 == 0x5d) || (iVar7 == 0x29)) || (iVar7 == 0x5b)) ||
      ((iVar7 == 0x27 || (iVar7 == 0x5e)))) ||
     ((iVar7 == 0x2a || ((iVar7 == 0x5c || (iVar7 == 0x28)))))) {
    switch(iVar7) {
    case 0x27:
    case 0x5b:
      iVar7 = 1;
      local_68 = 2;
      local_64 = 3;
      local_60 = 2;
      local_4c = 1;
      local_5c = 1;
      break;
    case 0x28:
    case 0x5c:
      iVar7 = 2;
      local_68 = 1;
      local_64 = 2;
      local_60 = 3;
      local_4c = 0;
      local_5c = 0;
      break;
    case 0x29:
    case 0x5d:
      iVar7 = 1;
      local_68 = 2;
      local_64 = 3;
      local_60 = 2;
      local_4c = 0;
      local_5c = 0;
      break;
    case 0x2a:
    case 0x5e:
      iVar7 = 1;
      local_68 = 2;
      local_64 = 2;
      local_60 = 3;
      local_4c = 1;
      local_5c = 1;
      break;
    default:
      iVar7 = 0;
      local_68 = 0;
      local_64 = 0;
      local_60 = 0;
      local_4c = 0;
      local_5c = 0;
    }
    iVar3 = FUN_0010a17a(0x12,uVar1);
    uVar2 = *(uint *)(param_4 + 0x30);
    uVar4 = FUN_0010b180(param_3,iVar7);
    FUN_0010ba02(iVar3,iVar7,uVar4,uVar2 >> 7 & 1,uVar1);
    iVar5 = FUN_0010b0f4(param_3,iVar7);
    uVar4 = *(undefined4 *)(iVar5 + 0x10);
    iVar5 = FUN_0010b0f4(iVar3,iVar7);
    *(undefined4 *)(iVar5 + 0x10) = uVar4;
    iVar5 = iVar3 + iVar7 * 0x18 + 0x8c;
    FUN_00109c0e(iVar5,2,(uint)param_3[iVar7 * 6 + 0x28] >> 1 & 1);
    FUN_00109c0e(iVar5,1,*(byte *)(param_3 + iVar7 * 6 + 0x28) & 1);
    uVar2 = *(uint *)(param_4 + 0x30);
    uVar4 = FUN_0010b180(param_3,local_68);
    FUN_0010ba02(iVar3,local_68,uVar4,uVar2 >> 7 & 1,uVar1);
    iVar7 = FUN_0010b0f4(param_3,local_68);
    uVar4 = *(undefined4 *)(iVar7 + 0x10);
    iVar7 = FUN_0010b0f4(iVar3,local_68);
    *(undefined4 *)(iVar7 + 0x10) = uVar4;
    iVar7 = iVar3 + local_68 * 0x18 + 0x8c;
    FUN_00109c0e(iVar7,2,(uint)param_3[local_68 * 6 + 0x28] >> 1 & 1);
    FUN_00109c0e(iVar7,1,*(byte *)(param_3 + local_68 * 6 + 0x28) & 1 ^ 1);
    iVar7 = FUN_0010b0f4(param_3,0);
    *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(iVar7 + 0x10);
    *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(iVar3 + 0x14c);
    *(undefined4 *)(iVar3 + 0x98) = 0;
    FUN_001a7cb8(iVar3,param_3);
    if (-1 < *(char *)(param_4 + 0x30)) {
      *(int *)(iVar3 + 0x160) = *(int *)(param_4 + 0x46c) + 1;
    }
    *(int *)(iVar3 + 0x158) = param_3[0x56];
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    FUN_00109d1c(param_3,&local_28,0xffffffff);
    if ((*(byte *)((int)param_3 + 0x15) & 2) == 0) {
      local_30 = 0;
    }
    else {
      local_30 = FUN_0010b180(param_3,param_3[0x21]);
    }
    iVar7 = param_3[4];
    FUN_001a7d72(param_3);
    FUN_0010ba02(param_3,1,0,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar1);
    FUN_0010ba02(param_3,2,0,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar1);
    FUN_0010da48(param_3,0x25,*(undefined4 *)(param_4 + 8));
    FUN_00109d48(param_3,&local_28);
    param_3[4] = iVar7;
    FUN_0010ba02(param_3,1,iVar3,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar1);
    FUN_00109c0e(param_3 + 0x29,1,local_4c);
    FUN_00109c0e(param_3 + 0x29,2,local_5c);
    FUN_000fa0d2(param_3,param_4,local_60,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
    FUN_000fa0d2(param_3,param_4,local_64,0,0,0,0);
    param_3[0x25] = param_3[0x53];
    param_3[0x26] = 0;
    iVar7 = FUN_0010b0f4(iVar3,0);
    param_3[0x27] = *(int *)(iVar7 + 0x10);
    iVar7 = 0;
    do {
      iVar5 = FUN_0010b0f4(iVar3,0);
      if (*(char *)(iVar7 + 0x10 + iVar5) == '\x01') {
        for (iVar5 = 1; iVar6 = (**(code **)(*param_3 + 0x14))(param_3), iVar5 <= iVar6;
            iVar5 = iVar5 + 1) {
          (**(code **)(*param_3 + 0x88))(param_3,iVar5,iVar7,4);
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 != 4);
    if (local_30 != 0) {
      FUN_0010c18e(param_3,local_30,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar1);
    }
    param_3[0x56] = *(int *)(iVar3 + 0x158);
    FUN_001a7cee(param_3,iVar3);
    if (-1 < *(char *)(param_4 + 0x30)) {
      FUN_00199430(param_3,1,iVar3,param_4,*(undefined4 *)(param_4 + 8));
    }
  }
  return param_3;
}

/* FUN_001a61f2 @ 0x1a61f2 (5554 bytes) */
int FUN_001a61f2(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int *param_2;
  int param_3;
  int *param_4;
  int param_5;
{
  byte bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 uVar11;
  int *piVar12;
  int iVar13;
  undefined1 local_7d;
  int *local_78;
  uint local_6c;
  int local_64;
  int local_54;
  int local_50;
  int local_48;
  int local_40;
  int *local_3c;
  int local_38;
  uint local_30;
  int local_24;
  undefined1 local_1d [13];
  
  local_1d[0] = 0;
  cVar2 = (**(code **)(*param_4 + 0x60))(param_4);
  if (cVar2 != '\0') {
    piVar3 = (int *)FUN_0010b180(param_4,1);
    cVar2 = (**(code **)(*piVar3 + 0x60))(piVar3);
    if (cVar2 != '\0') {
      uVar6 = *(undefined4 *)(param_5 + 8);
      uVar11 = FUN_0010b180(param_4,1);
      FUN_00111842(uVar11,param_4,uVar6);
    }
  }
  cVar2 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x38);
  if (((cVar2 != '\0') && (param_2 != (int *)0x0)) &&
     (cVar2 = (**(code **)(*param_2 + 100))(param_2), cVar2 == '\0')) {
    FUN_001567a4(param_2,param_3,param_5);
  }
  cVar2 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x1b);
  if (cVar2 == '\0') {
    local_7d = 0;
  }
  else {
    local_7d = (**(code **)(*param_4 + 100))(param_4);
    cVar2 = FUN_00156a28(param_4,param_5,local_1d);
    if ((cVar2 != '\0') &&
       (param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
    if (((param_2 != (int *)0x0) &&
        (cVar2 = FUN_00155bf2(param_2,param_3,param_4,param_5,local_1d), cVar2 != '\0')) &&
       (param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
  }
  cVar2 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x1c);
  if (cVar2 == '\0') {
    cVar2 = FUN_00165812(param_2,param_3,param_4,param_5);
    if (cVar2 == '\0') goto LAB_001a62b3;
LAB_001a6729:
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    local_7d = 1;
    cVar2 = FUN_00165a1c(param_2,param_3,param_4,param_5);
    if (cVar2 != '\0') goto LAB_001a676a;
LAB_001a62d8:
    cVar2 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x1d);
  }
  else {
    cVar2 = FUN_00164f1e(param_4,param_5);
    if (cVar2 != '\0') {
      cVar2 = (**(code **)(*param_4 + 100))(param_4);
      if (((cVar2 != '\0') && ((*(byte *)((int)param_4 + 0x15) & 2) == 0)) &&
         (param_2 != (int *)0x0)) {
        FUN_00155bf2(param_2,param_3,param_4,param_5,local_1d);
      }
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      if (param_4 == (int *)0x0) {
        return 1;
      }
    }
    iVar4 = (**(code **)(*param_4 + 0x14))(param_4);
    if ((param_3 <= iVar4) && (cVar2 = FUN_00169a44(param_2,param_3,param_4,param_5), cVar2 != '\0')
       ) {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      if (param_4 == (int *)0x0) {
        return 1;
      }
      local_7d = 1;
    }
    cVar2 = FUN_00165e96(param_4,param_5);
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    }
    cVar2 = FUN_001582e0(param_4,param_5);
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    }
    cVar2 = FUN_00157ac6(param_4,param_5,0,1);
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    }
    cVar2 = FUN_00157068(param_4,param_5);
    if (cVar2 != '\0') {
      cVar2 = (**(code **)(*param_4 + 100))(param_4);
      if (((cVar2 != '\0') && ((*(byte *)((int)param_4 + 0x15) & 2) == 0)) &&
         (param_2 != (int *)0x0)) {
        FUN_00155bf2(param_2,param_3,param_4,param_5,local_1d);
      }
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      if (param_4 == (int *)0x0) {
        return 1;
      }
      local_7d = 1;
    }
    cVar2 = FUN_00159396(param_4,param_5);
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    }
    cVar2 = FUN_0015a444(param_4,param_5);
    if (cVar2 == '\0') {
      cVar2 = FUN_001718da(param_4,param_5);
      if (cVar2 == '\0') goto LAB_001a65e0;
LAB_001a6cc6:
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      cVar2 = FUN_0016f114(param_4,param_5);
      if (cVar2 != '\0') goto LAB_001a6cf5;
LAB_001a65f7:
      cVar2 = FUN_0016fdba(param_4,param_5);
      if (cVar2 == '\0') goto LAB_001a660e;
LAB_001a6d24:
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      cVar2 = FUN_0017102e(param_4,param_5);
      if (cVar2 != '\0') goto LAB_001a6d53;
LAB_001a6625:
      cVar2 = FUN_00159804(param_4,param_5);
      if (cVar2 == '\0') goto LAB_001a663c;
LAB_001a6d82:
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      cVar2 = FUN_0015e33a(param_4,param_5);
      if (cVar2 != '\0') goto LAB_001a6db1;
LAB_001a6653:
      cVar2 = FUN_00156ad8(param_4,param_5);
      if (cVar2 == '\0') goto LAB_001a666a;
LAB_001a6de0:
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      cVar2 = FUN_0016b1ae(param_4,param_5);
      if (cVar2 != '\0') goto LAB_001a6e0f;
LAB_001a6681:
      cVar2 = FUN_00172f94(param_4,param_5);
      if (cVar2 == '\0') goto LAB_001a6698;
LAB_001a6e3e:
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      cVar2 = FUN_001735e0(param_4,param_5);
      if (cVar2 != '\0') goto LAB_001a6e6d;
LAB_001a66af:
      cVar2 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x3c);
    }
    else {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      cVar2 = FUN_001718da(param_4,param_5);
      if (cVar2 != '\0') goto LAB_001a6cc6;
LAB_001a65e0:
      cVar2 = FUN_0016f114(param_4,param_5);
      if (cVar2 == '\0') goto LAB_001a65f7;
LAB_001a6cf5:
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      cVar2 = FUN_0016fdba(param_4,param_5);
      if (cVar2 != '\0') goto LAB_001a6d24;
LAB_001a660e:
      cVar2 = FUN_0017102e(param_4,param_5);
      if (cVar2 == '\0') goto LAB_001a6625;
LAB_001a6d53:
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      cVar2 = FUN_00159804(param_4,param_5);
      if (cVar2 != '\0') goto LAB_001a6d82;
LAB_001a663c:
      cVar2 = FUN_0015e33a(param_4,param_5);
      if (cVar2 == '\0') goto LAB_001a6653;
LAB_001a6db1:
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      cVar2 = FUN_00156ad8(param_4,param_5);
      if (cVar2 != '\0') goto LAB_001a6de0;
LAB_001a666a:
      cVar2 = FUN_0016b1ae(param_4,param_5);
      if (cVar2 == '\0') goto LAB_001a6681;
LAB_001a6e0f:
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      cVar2 = FUN_00172f94(param_4,param_5);
      if (cVar2 != '\0') goto LAB_001a6e3e;
LAB_001a6698:
      cVar2 = FUN_001735e0(param_4,param_5);
      if (cVar2 == '\0') goto LAB_001a66af;
LAB_001a6e6d:
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      cVar2 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x3c);
    }
    if ((cVar2 != '\0') && (cVar2 = FUN_0016dc48(param_2,param_3,param_4,param_5), cVar2 != '\0')) {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    }
    cVar2 = FUN_00159c72(param_4,param_5);
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    }
    cVar2 = FUN_0016a5c0(param_4,param_5);
    if (cVar2 != '\0') {
      local_7d = 1;
    }
    cVar2 = FUN_00165812(param_2,param_3,param_4,param_5);
    if (cVar2 != '\0') goto LAB_001a6729;
LAB_001a62b3:
    cVar2 = FUN_00165a1c(param_2,param_3,param_4,param_5);
    if (cVar2 == '\0') goto LAB_001a62d8;
LAB_001a676a:
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    local_7d = 1;
    cVar2 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x1d);
  }
  if (((((cVar2 != '\0') && (cVar2 = FUN_00167f9e(param_4,param_5), cVar2 != '\0')) &&
       (cVar2 = (**(code **)(*param_4 + 100))(param_4), cVar2 != '\0')) &&
      ((param_2 != (int *)0x0 &&
       (cVar2 = FUN_00155bf2(param_2,param_3,param_4,param_5,local_1d), cVar2 != '\0')))) &&
     (param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4), param_4 == (int *)0x0)) {
    return 1;
  }
  cVar2 = FUN_0016e6f8(param_2,param_3,param_4,param_5);
  if (cVar2 == '\0') {
    uVar6 = *(undefined4 *)(param_5 + 8);
    iVar4 = *(int *)(param_4[0x22] + 8);
  }
  else {
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    uVar6 = *(undefined4 *)(param_5 + 8);
    iVar4 = *(int *)(param_4[0x22] + 8);
  }
  if (iVar4 != 0x77) goto LAB_001a6331;
  cVar2 = FUN_000e1402(uVar6,0x3d);
  if (cVar2 == '\0') goto LAB_001a69c1;
  iVar4 = FUN_0010b0f4(param_4,1);
  cVar2 = FUN_000f5672(*(undefined4 *)(iVar4 + 0x10));
  if (cVar2 == '\0') goto LAB_001a6f3e;
  piVar3 = (int *)FUN_0010b180(param_4,1);
  if (*(int *)(piVar3[0x22] + 8) != 0x12) {
LAB_001a6f6a:
    uVar6 = *(undefined4 *)(param_5 + 8);
    goto LAB_001a6331;
  }
  if ((char)piVar3[0x48] != '\0') goto LAB_001a69c1;
  if (piVar3[0x49] != 0) goto LAB_001a6f3e;
  if ((*(byte *)((int)piVar3 + 0x15) & 2) != 0) goto LAB_001a6f6a;
  cVar2 = FUN_0010a62e(piVar3,param_5);
  if (cVar2 != '\0') {
    iVar4 = FUN_0010b0f4(piVar3,0);
    iVar4 = FUN_000f5ede(*(undefined4 *)(iVar4 + 0x10));
    if (iVar4 < 0) {
LAB_001a6f3e:
      uVar6 = *(undefined4 *)(param_5 + 8);
      goto LAB_001a6331;
    }
    local_78 = (int *)FUN_0010b180(piVar3,1);
    piVar12 = (int *)FUN_0010b180(piVar3,2);
    cVar2 = (**(code **)(*local_78 + 0x48))(local_78);
    if (cVar2 == '\0') {
      cVar2 = (**(code **)(*piVar12 + 0x48))(piVar12);
      if (cVar2 == '\0') goto LAB_001a6f6a;
      uVar11 = 2;
      local_64 = 1;
    }
    else {
      uVar11 = 1;
      local_64 = 2;
      local_78 = piVar12;
    }
    cVar2 = ((undefined4 (*)())FUN_00140e9c)(piVar3,uVar11,0xbf000000);
    if (cVar2 != '\0') {
      if ((piVar3[local_64 * 6 + 0x28] & 1U) != 0) goto LAB_001a6f3e;
      if ((piVar3[local_64 * 6 + 0x28] & 2U) != 0) goto LAB_001a6f6a;
      iVar5 = FUN_0010b0f4(piVar3,local_64);
      uVar8 = (uint)*(byte *)(iVar4 + 0x10 + iVar5);
      if (*(int *)(local_78[0x22] + 8) == 0x12) {
        if ((char)local_78[0x48] != '\0') goto LAB_001a6f3e;
        if (local_78[0x49] != 0) goto LAB_001a6f6a;
        iVar4 = FUN_0010b0f4(local_78,0);
        uVar9 = FUN_000f5ede(*(undefined4 *)(iVar4 + 0x10));
        if (uVar8 == uVar9) {
          cVar2 = FUN_0010a62e(local_78,param_5);
          if (cVar2 == '\0') goto LAB_001a6f3e;
          iVar4 = FUN_0010b180(local_78,1);
          iVar5 = FUN_0010b180(local_78,2);
          uVar9 = local_78[0x2e];
          if (iVar4 != iVar5) goto LAB_001a6f6a;
          if (((byte)uVar9 & 1) != ((byte)local_78[0x34] & 1)) {
            if ((uVar9 & 2) != 0) goto LAB_001a6f3e;
            if ((local_78[0x34] & 2U) != 0) goto LAB_001a6f6a;
            cVar2 = FUN_0010a656(iVar4,param_5);
            if (cVar2 != '\0') {
              iVar5 = FUN_0010b0f4(local_78,1);
              local_30 = (uint)*(byte *)(uVar8 + 0x10 + iVar5);
              iVar5 = FUN_0010b0f4(local_78,2);
              uVar8 = (uint)*(byte *)(uVar8 + 0x10 + iVar5);
              local_6c = uVar8;
              if ((uVar9 & 1) == 0) {
                local_6c = local_30;
                local_30 = uVar8;
              }
              if (*(int *)(*(int *)(iVar4 + 0x88) + 8) != 0x25) goto LAB_001a6f3e;
              cVar2 = ((undefined4 (*)())FUN_00140e9c)(iVar4,2,0x3f800000);
              if (cVar2 == '\0') goto LAB_001a6f6a;
              cVar2 = ((undefined4 (*)())FUN_00140e9c)(iVar4,3,0);
              if (cVar2 != '\0') {
                if ((*(byte *)(iVar4 + 0x15) & 2) != 0) goto LAB_001a6f3e;
                if ((*(uint *)(iVar4 + 0xb8) & 1) != 0) goto LAB_001a6f6a;
                if ((*(uint *)(iVar4 + 0xb8) & 2) == 0) {
                  FUN_001a7d72(piVar3);
                  FUN_001a7d72(local_78);
                  FUN_001a7d72(iVar4);
                  FUN_0010d8fc(piVar3,0x17,uVar6);
                  iVar4 = FUN_0010b180(iVar4,1);
                  if (*(int *)(param_5 + 0x46c) < *(int *)(iVar4 + 0x160)) {
                    *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar4 + 0x160) = *(int *)(param_5 + 0x46c) + 1;
                  }
                  if (*(int *)(param_5 + 0x46c) < *(int *)(iVar4 + 0x160)) {
                    *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar4 + 0x160) = *(int *)(param_5 + 0x46c) + 1;
                  }
                  FUN_0010ba02(piVar3,1,iVar4,0,uVar6);
                  FUN_0010ba02(piVar3,2,iVar4,0,uVar6);
                  piVar3[0x27] = *(int *)(PTR_DAT_0021345d + local_30 * 4);
                  FUN_0010c18e(piVar3,iVar4,0,uVar6);
                  uVar6 = DAT_001cf048;
                  iVar4 = FUN_0010b0f4(piVar3,1);
                  *(undefined4 *)(iVar4 + 0x10) = uVar6;
                  iVar4 = FUN_0010b0f4(piVar3,2);
                  *(undefined4 *)(iVar4 + 0x10) = uVar6;
                  iVar4 = FUN_0010b0f4(param_4,1);
                  *(undefined4 *)(iVar4 + 0x10) = uVar6;
                  (**(code **)(*param_4 + 0x88))(param_4,1,local_6c,local_6c);
                  (**(code **)(*param_4 + 0x88))(param_4,1,local_30,local_30);
                  (**(code **)(*piVar3 + 0x88))(piVar3,1,local_30,local_30);
                  (**(code **)(*piVar3 + 0x88))(piVar3,2,local_30,local_30);
                  FUN_00109c0e(piVar3 + 0x29,1,1);
                  FUN_00109c0e(piVar3 + 0x2f,1,1);
                  piVar3[0x25] = piVar3[0x53];
                  piVar3[0x26] = 0;
                  if (*(int *)(param_5 + 0x46c) < piVar3[0x58]) {
                    piVar3[0x58] = piVar3[0x58] + 1;
                  }
                  else {
                    piVar3[0x58] = *(int *)(param_5 + 0x46c) + 1;
                  }
                  FUN_000e956e(param_4[0x56],param_4,piVar3);
                  local_24 = *(int *)(PTR_DAT_0021345d + local_6c * 4);
                  pcVar10 = PTR_DAT_0021345d + local_30 * 4;
                  iVar4 = 0;
                  do {
                    if (*pcVar10 != '\x01') {
                      *(char *)((int)&local_24 + iVar4) = *pcVar10;
                    }
                    iVar4 = iVar4 + 1;
                    pcVar10 = pcVar10 + 1;
                  } while (iVar4 != 4);
                  param_4[0x27] = local_24;
                  param_4[5] = param_4[5] | 0x2000000;
                  param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
                  uVar6 = *(undefined4 *)(param_5 + 8);
                  goto LAB_001a6331;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_001a69c1:
  uVar6 = *(undefined4 *)(param_5 + 8);
LAB_001a6331:
  cVar2 = FUN_000e1402(uVar6,0x39);
  if (cVar2 != '\0') {
    FUN_00197636(param_4,*(undefined4 *)(param_5 + 8));
    for (iVar4 = 1; iVar5 = (**(code **)(*param_4 + 0x14))(param_4), iVar4 <= iVar5;
        iVar4 = iVar4 + 1) {
      uVar6 = FUN_0010b180(param_4,iVar4);
      FUN_00199430(param_4,iVar4,uVar6,param_5,*(undefined4 *)(param_5 + 8));
    }
    cVar2 = FUN_00199430(param_2,param_3,param_4,param_5,*(undefined4 *)(param_5 + 8));
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      local_7d = 1;
    }
  }
  piVar3 = (int *)((int (*)())FUN_001a5af4)(param_2,param_3,param_4,param_5);
  cVar2 = FUN_0016b7fa(piVar3,1,param_5);
  if (cVar2 != '\0') {
    piVar3 = (int *)FUN_0014fb18(param_2,param_3,piVar3);
    local_7d = 1;
  }
  cVar2 = FUN_001195a6(*(undefined4 *)(param_5 + 8),piVar3);
  if ((cVar2 != '\0') && ((*(byte *)((int)piVar3 + 0x15) & 2) == 0)) {
    for (local_54 = 1; iVar4 = (**(code **)(*piVar3 + 0x14))(piVar3), local_54 <= iVar4;
        local_54 = local_54 + 1) {
      iVar4 = FUN_0010b180(piVar3,local_54);
      if ((((*(int *)(*(int *)(iVar4 + 0x88) + 8) == 0x4c) &&
           (cVar2 = FUN_0010a62e(iVar4,param_5), cVar2 != '\0')) &&
          ((*(byte *)(iVar4 + 0x15) & 2) != 0)) &&
         (iVar5 = FUN_0010b180(iVar4,*(undefined4 *)(iVar4 + 0x84)),
         *(int *)(*(int *)(iVar5 + 0x88) + 8) == 0x4d)) {
        uVar6 = FUN_0010b180(iVar4,*(undefined4 *)(iVar4 + 0x84));
        cVar2 = FUN_0010a62e(uVar6,param_5);
        if ((cVar2 != '\0') &&
           (iVar5 = FUN_0010b180(iVar4,*(undefined4 *)(iVar4 + 0x84)),
           (*(byte *)(iVar5 + 0x15) & 2) == 0)) {
          uVar6 = FUN_0010b180(iVar4,*(undefined4 *)(iVar4 + 0x84));
          iVar5 = FUN_0010a1c2(piVar3,*(undefined4 *)(param_5 + 8),0);
          local_50 = 0;
          local_3c = piVar3;
          local_38 = iVar5;
          do {
            iVar7 = FUN_0010b0f4(piVar3,local_54);
            bVar1 = *(byte *)(local_50 + 0x10 + iVar7);
            if (bVar1 < 4) {
              cVar2 = FUN_000f5990(uVar6,bVar1);
              if (cVar2 == '\0') {
                *(undefined1 *)(local_38 + 0x9c) = 1;
              }
              else {
                *(undefined1 *)(local_3c + 0x27) = 1;
              }
            }
            local_50 = local_50 + 1;
            local_3c = (int *)((int)local_3c + 1);
            local_38 = local_38 + 1;
          } while (local_50 != 4);
          FUN_0010ba02(iVar5,local_54,uVar6,0,*(undefined4 *)(param_5 + 8));
          FUN_0010c18e(piVar3,iVar5,0,*(undefined4 *)(param_5 + 8));
          FUN_000e956e(piVar3[0x56],piVar3,iVar5);
          FUN_0010ba02(iVar4,*(undefined4 *)(iVar4 + 0x84),0,0,*(undefined4 *)(param_5 + 8));
          *(int *)(iVar4 + 0x84) = *(int *)(iVar4 + 0x84) + -1;
          *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) & 0xfffffdff;
          FUN_000f5d78(piVar3);
          FUN_000f5d78(iVar5);
          *(int *)(iVar5 + 0x160) = *(int *)(param_5 + 0x46c) + 1;
          if (0 < *(int *)(iVar5 + 0x84)) {
            local_48 = 1;
            do {
              if (local_48 != local_54) {
                piVar12 = (int *)FUN_0010b180(iVar5,local_48);
                cVar2 = (**(code **)(*piVar12 + 0x5c))(piVar12);
                if (cVar2 == '\0') {
                  iVar4 = *(int *)(param_5 + 0x46c);
                  iVar7 = FUN_0010b180(iVar5,local_48);
                  if (iVar4 < *(int *)(iVar7 + 0x160)) {
                    *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar7 + 0x160) = iVar4 + 1;
                  }
                }
                else {
                  uVar6 = *(undefined4 *)(param_5 + 8);
                  uVar11 = FUN_0010b180(iVar5,local_48);
                  iVar4 = FUN_0010a1c2(uVar11,uVar6,0);
                  FUN_0010ba02(iVar5,local_48,iVar4,0,*(undefined4 *)(param_5 + 8));
                  FUN_000e956e(*(undefined4 *)(iVar5 + 0x158),iVar5,iVar4);
                  if (0 < *(int *)(iVar4 + 0x84)) {
                    local_40 = 1;
                    do {
                      iVar7 = *(int *)(param_5 + 0x46c);
                      iVar13 = FUN_0010b180(iVar4,local_40);
                      if (iVar7 < *(int *)(iVar13 + 0x160)) {
                        *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar13 + 0x160) = iVar7 + 1;
                      }
                      local_40 = local_40 + 1;
                    } while (local_40 <= *(int *)(iVar4 + 0x84));
                  }
                }
              }
              local_48 = local_48 + 1;
            } while (local_48 <= *(int *)(iVar5 + 0x84));
          }
          break;
        }
      }
    }
  }
  cVar2 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x3a);
  if (cVar2 == '\0') {
    return local_7d;
  }
  if ((*(int *)(param_5 + 0x228) < *(int *)(*(int *)(param_5 + 8) + 0x398)) &&
     (cVar2 = FUN_0015114e(param_2,param_3,piVar3,param_5), cVar2 != '\0')) {
    piVar3 = (int *)FUN_0014fb18(param_2,param_3,piVar3);
    local_7d = 1;
  }
  cVar2 = FUN_00151c7c(param_2,param_3,piVar3,param_5);
  if (cVar2 != '\0') {
    FUN_0014fb18(param_2,param_3,piVar3);
    return 1;
  }
  return local_7d;
}

/* FUN_001a77ac @ 0x1a77ac (73 bytes) */
int FUN_001a77ac(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  int param_3;
  undefined4 *param_4;
{
  int iVar1;
  char cVar2;
  
  iVar1 = *(int *)(*(int *)(param_3 + 0x88) + 8);
  cVar2 = (**(code **)(*param_2 + 0x24))(param_2);
  if ((cVar2 != '\0') && (iVar1 - 0x9eU < 4)) {
    *param_4 = 2;
    return 1;
  }
  return 0;
}

/* FUN_001a77f6 @ 0x1a77f6 (69 bytes) */
int FUN_001a77f6(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  
  if (*(char *)(*(int *)(param_1 + 8) + 0x3ec) != '\0') {
    return 1;
  }
  if (param_2 < 0x18) {
    if (param_3 < 0x10) {
      uVar1 = 0;
      goto LAB_001a7813;
    }
    if (param_4 <= param_3 * 4) {
      uVar1 = 0;
      goto LAB_001a7813;
    }
  }
  uVar1 = 1;
LAB_001a7813:
  *(undefined1 *)(*(int *)(param_1 + 8) + 0x3ec) = uVar1;
  return uVar1;
}

/* FUN_001a783c @ 0x1a783c (92 bytes) */
int FUN_001a783c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  char cVar2;
  int *piVar3;
  
  cVar2 = FUN_000e1402(*(undefined4 *)(param_2 + 8),0x4a);
  if (cVar2 != '\0') {
    piVar3 = *(int **)(param_2 + 0x378);
    iVar1 = piVar3[2];
    while (iVar1 != 0) {
      cVar2 = (**(code **)(*piVar3 + 0x24))(piVar3);
      if (cVar2 != '\0') {
        piVar3 = (int *)FUN_00132bf2(param_2,piVar3);
      }
      piVar3 = (int *)piVar3[2];
      iVar1 = piVar3[2];
    }
  }
  return;
}

/* FUN_001a7898 @ 0x1a7898 (79 bytes) */
int FUN_001a7898(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  *param_1 = param_4;
  param_1[1] = param_3;
  param_1[2] = param_2;
  if (param_2 < 3) {
    param_1[5] = 0;
    return;
  }
  iVar1 = FUN_001a7bca(*(undefined4 *)(param_4 + 0xb4),param_2 * 4);
  param_1[5] = iVar1;
  return;
}

/* FUN_001a78e8 @ 0x1a78e8 (79 bytes) */
int FUN_001a78e8(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  *param_1 = param_4;
  param_1[1] = param_3;
  param_1[2] = param_2;
  if (param_2 < 3) {
    param_1[5] = 0;
    return;
  }
  iVar1 = FUN_001a7bca(*(undefined4 *)(param_4 + 0xb4),param_2 * 4);
  param_1[5] = iVar1;
  return;
}

/* FUN_001a7938 @ 0x1a7938 (97 bytes) */
int FUN_001a7938(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_3 + 0xb4);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x1c);
  *puVar2 = uVar1;
  ((int (*)())FUN_001a78e8)(puVar2 + 1,1,0x22,param_3);
  puVar2[3] = 1;
  puVar2[4] = param_1;
  puVar2[5] = param_2;
  return puVar2 + 1;
}

