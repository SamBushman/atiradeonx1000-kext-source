#include "decls.h"

/* FUN_0011aeb6 @ 0x11aeb6 (25 bytes) */
int FUN_0011aeb6()
{
  DAT_00210f48 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_0011aed0 @ 0x11aed0 (25 bytes) */
int FUN_0011aed0()
{
  DAT_00210f5c = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_0011aeea @ 0x11aeea (25 bytes) */
int FUN_0011aeea()
{
  DAT_00210f70 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_0011af04 @ 0x11af04 (25 bytes) */
int FUN_0011af04()
{
  DAT_00210f84 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_0011af1e @ 0x11af1e (25 bytes) */
int FUN_0011af1e()
{
  DAT_00210ea8 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_0011af38 @ 0x11af38 (25 bytes) */
int FUN_0011af38()
{
  DAT_00210ebc = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_0011af52 @ 0x11af52 (25 bytes) */
int FUN_0011af52()
{
  DAT_00210ed0 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_0011af6c @ 0x11af6c (25 bytes) */
int FUN_0011af6c()
{
  DAT_00210ee4 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_0011af86 @ 0x11af86 (25 bytes) */
int FUN_0011af86()
{
  DAT_00211e48 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_0011afa0 @ 0x11afa0 (25 bytes) */
int FUN_0011afa0()
{
  DAT_0021221c = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_001251fc @ 0x1251fc (10 bytes) */
int FUN_001251fc(param_1)
  int param_1;
{
  return param_1;
}

/* FUN_00125206 @ 0x125206 (100 bytes) */
int FUN_00125206(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_10;
  
  if (*(int *)(param_1 + 0x84) < 1) {
LAB_0012521b:
    local_10 = 0;
  }
  else {
    local_10 = 0;
    iVar3 = 1;
    do {
      iVar2 = FUN_0010b180(param_1,iVar3);
      iVar1 = local_10;
      if ((((iVar2 != 0) && (param_1 != iVar2)) && (iVar1 = iVar2, local_10 != 0)) &&
         (iVar1 = local_10, local_10 != iVar2)) goto LAB_0012521b;
      local_10 = iVar1;
      iVar3 = iVar3 + 1;
    } while (iVar3 <= *(int *)(param_1 + 0x84));
  }
  return local_10;
}

/* FUN_0012526a @ 0x12526a (71 bytes) */
int FUN_0012526a(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  if (0 < *(int *)(param_1 + 0x84)) {
    iVar2 = 1;
    do {
      iVar1 = FUN_0010b180(param_1,iVar2);
      if (iVar1 == 0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= *(int *)(param_1 + 0x84));
  }
  return 1;
}

/* FUN_001252b2 @ 0x1252b2 (154 bytes) */
int FUN_001252b2(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int local_10;
  
  if (((*(int *)(param_1 + 0x84) != 1) || (iVar1 = FUN_0010b180(param_1,1), iVar1 == 0)) &&
     (1 < *(int *)(param_1 + 0x84))) {
    local_10 = 2;
    do {
      iVar1 = FUN_0010b180(param_1,local_10 + -1);
      iVar2 = FUN_0010b180(param_1,local_10);
      if ((iVar1 != iVar2) || (iVar1 = FUN_0010b180(param_1,local_10), iVar1 == 0)) {
        return 0;
      }
      local_10 = local_10 + 1;
    } while (local_10 <= *(int *)(param_1 + 0x84));
  }
  return 1;
}

/* FUN_0012534c @ 0x12534c (138 bytes) */
int FUN_0012534c(param_1)
  int param_1;
{
  int iVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int local_20;
  
  iVar1 = *(int *)(param_1 + 0x378);
  iVar3 = *(int *)(iVar1 + 8);
  do {
    if (iVar3 == 0) {
      return 1;
    }
    cVar2 = FUN_000e9792(iVar1);
    if (cVar2 != '\0') {
      uVar4 = 1;
      local_20 = 0;
      iVar3 = *(int *)(iVar1 + 0xd4);
      if (*(int *)(iVar3 + 4) != 0) {
        do {
          iVar3 = *(int *)(*(int *)(iVar3 + 8) + local_20);
          if ((iVar3 != 0) && (cVar2 = FUN_000e977a(iVar3), cVar2 != '\0')) {
            return 0;
          }
          uVar4 = uVar4 + 1;
          local_20 = local_20 + 4;
          iVar3 = *(int *)(iVar1 + 0xd4);
        } while (uVar4 <= *(uint *)(iVar3 + 4));
      }
    }
    iVar1 = *(int *)(iVar1 + 8);
    iVar3 = *(int *)(iVar1 + 8);
  } while( true );
}

/* FUN_001253d6 @ 0x1253d6 (51 bytes) */
int FUN_001253d6(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  char cVar1;
  
  if ((*(byte *)(param_2 + 0x14) & 0x40) != 0) {
    cVar1 = FUN_00137fb8(param_1,*(undefined4 *)(param_2 + 0x94));
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}

/* FUN_0012540a @ 0x12540a (310 bytes) */
int FUN_0012540a(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_10;
  
  iVar3 = *(int *)(param_1 + 0xb0);
  if (*(int *)(iVar3 + 0x84) < 1) {
    local_10 = 1;
  }
  else {
    local_10 = 1;
    iVar5 = 0x18;
    iVar4 = param_1;
    do {
      iVar3 = ((int (*)())FUN_0012a37e)(*(undefined4 *)(iVar5 + 0x8c + iVar3),param_2,
                           *(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(iVar4 + 0x214) = *(undefined4 *)(iVar3 + 0xb0);
      local_10 = local_10 + 1;
      iVar5 = iVar5 + 0x18;
      iVar3 = *(int *)(param_1 + 0xb0);
      iVar4 = iVar4 + 4;
    } while (local_10 <= *(int *)(iVar3 + 0x84));
  }
  cVar2 = FUN_000e1402(*(undefined4 *)(param_1 + 0x238),7);
  if (((cVar2 != '\0') && (cVar2 = FUN_000e1402(*(undefined4 *)(param_1 + 0x238),9), cVar2 != '\0'))
     && (*(int *)(*(int *)(param_1 + 0xb0) + 0x80) != 0)) {
    piVar1 = *(int **)(*(int *)(param_1 + 0xb0) + 0x8c);
    cVar2 = (**(code **)(*piVar1 + 0x18))(piVar1);
    if (((cVar2 != '\0') && (*(int *)(*(int *)(param_1 + 0xb0) + 0x84) != 0)) &&
       ((*(byte *)(*(int *)(param_1 + 0xb0) + 0x15) & 2) == 0)) {
      iVar3 = ((int (*)())FUN_0012a37e)(piVar1,param_2,*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x210 + local_10 * 4) = *(undefined4 *)(iVar3 + 0xb0);
    }
  }
  return;
}

/* FUN_00125540 @ 0x125540 (1002 bytes) */
int FUN_00125540(param_1)
  int param_1;
{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  byte local_5c;
  uint local_54;
  uint local_50;
  int local_4c;
  uint local_48;
  int local_44;
  int local_40;
  undefined1 local_3c [16];
  int local_2c;
  int *local_24;
  int local_20;
  
  iVar8 = *(int *)(*(int *)(param_1 + 0x3b0) + 4);
  uVar11 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  uVar13 = iVar8 + 0x1fU >> 5;
  iVar3 = uVar13 * 4 + 0xc;
  puVar4 = (undefined4 *)FUN_001a7bca(uVar11,iVar3);
  puVar1 = puVar4 + 1;
  *puVar4 = uVar11;
  puVar4[2] = iVar8;
  puVar4[1] = uVar13;
  if (uVar13 != 0) {
    uVar12 = 0;
    puVar5 = puVar1;
    do {
      puVar5[2] = 0;
      uVar12 = uVar12 + 1;
      puVar5 = puVar5 + 1;
    } while (uVar12 < uVar13);
  }
  uVar11 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar6 = (undefined4 *)FUN_001a7bca(uVar11,iVar3);
  puVar5 = puVar6 + 1;
  *puVar6 = uVar11;
  puVar6[2] = iVar8;
  puVar6[1] = uVar13;
  if (uVar13 != 0) {
    uVar12 = 0;
    puVar7 = puVar5;
    do {
      puVar7[2] = 0;
      uVar12 = uVar12 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar12 < uVar13);
  }
  FUN_001a868e(local_3c,*(undefined4 *)(*(int *)(param_1 + 0x3a0) + 4));
  iVar3 = local_2c;
  while (iVar3 != 0) {
    local_2c = iVar3;
    if ((((-1 < *(int *)(iVar3 + 0x1c)) &&
         ((*(uint *)(*(int *)(param_1 + 0x3a4) + 8 + (*(uint *)(iVar3 + 0x1c) >> 5) * 4) >>
           ((byte)*(uint *)(iVar3 + 0x1c) & 0x1f) & 1) != 0)) || (*(int *)(iVar3 + 4) == 0x3b)) ||
       ((*(int *)(iVar3 + 4) == 0x2c && (*(char *)(param_1 + 0x3a8) != '\0')))) {
      if (*puVar5 != 0) {
        uVar13 = 0;
        puVar7 = puVar5;
        do {
          puVar7[2] = 0;
          uVar13 = uVar13 + 1;
          puVar7 = puVar7 + 1;
        } while (uVar13 < *puVar5);
      }
      if (*puVar1 != 0) {
        uVar12 = 0;
        uVar13 = *puVar1;
        puVar7 = puVar1;
        do {
          puVar7[2] = 0;
          uVar12 = uVar12 + 1;
          puVar7 = puVar7 + 1;
        } while (uVar12 < uVar13);
      }
      uVar13 = 1;
      local_40 = 0;
      iVar8 = *(int *)(iVar3 + 0x18);
      if (*(int *)(iVar8 + 4) != 0) {
        do {
          iVar8 = *(int *)(*(int *)(iVar8 + 8) + local_40);
          if ((*(byte *)(iVar8 + 0x14) & 1) != 0) {
            uVar12 = *(uint *)(*(int *)(iVar8 + 0x158) + 0xb4);
            puVar4[(uVar12 >> 5) + 3] = puVar4[(uVar12 >> 5) + 3] | 1 << ((byte)uVar12 & 0x1f);
          }
          uVar13 = uVar13 + 1;
          local_40 = local_40 + 4;
          iVar8 = *(int *)(iVar3 + 0x18);
        } while (uVar13 <= *(uint *)(iVar8 + 4));
      }
      local_20 = 0;
      local_44 = 0;
      for (local_48 = 1; local_48 <= *(uint *)(*(int *)(iVar3 + 0x18) + 4); local_48 = local_48 + 1)
      {
        local_20 = *(int *)(*(int *)(*(int *)(iVar3 + 0x18) + 8) + local_44);
        if ((*(byte *)(local_20 + 0x14) & 1) != 0) {
          iVar8 = *(int *)(local_20 + 0x158);
          local_24 = (int *)0x0;
          local_50 = 1;
          local_4c = 0;
          iVar9 = *(int *)(iVar8 + 0xf4);
          if (*(int *)(iVar9 + 4) != 0) {
            do {
              local_24 = *(int **)(*(int *)(iVar9 + 8) + local_4c);
              uVar13 = (uint)local_24[0x2d] >> 5;
              local_5c = (byte)local_24[0x2d] & 0x1f;
              if (((uint)puVar6[uVar13 + 3] >> local_5c & 1) == 0) {
                uVar11 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
                puVar10 = (undefined4 *)FUN_001a7bca(uVar11,0x168);
                *puVar10 = uVar11;
                puVar2 = puVar10 + 1;
                FUN_0010f790(puVar2,*(undefined4 *)(param_1 + 8));
                uVar11 = FUN_000e97bc(local_24);
                puVar10[0x22] = uVar11;
                FUN_0010a3c2(puVar2,0,iVar3);
                if (*(int *)(iVar3 + 4) == 0x2c) {
                  puVar10[0x28] = DAT_001cc404;
                  uVar12 = puVar4[uVar13 + 3];
                }
                else {
                  uVar12 = puVar4[uVar13 + 3];
                }
                if ((uVar12 >> local_5c & 1) == 0) {
                  puVar4[uVar13 + 3] = uVar12 | 1 << local_5c;
                  ((int (*)())FUN_0012a42e)(iVar3,puVar2);
                }
                local_54 = 1 << local_5c;
                FUN_000e9540(local_24,puVar2);
                (**(code **)(*local_24 + 0x48))(local_24);
                puVar6[uVar13 + 3] = puVar6[uVar13 + 3] | local_54;
              }
              local_50 = local_50 + 1;
              local_4c = local_4c + 4;
              iVar9 = *(int *)(iVar8 + 0xf4);
            } while (local_50 <= *(uint *)(iVar9 + 4));
          }
        }
        local_44 = local_44 + 4;
      }
    }
    FUN_001a856e(local_3c);
    iVar3 = local_2c;
  }
  if (puVar1 != (uint *)0x0) {
    FUN_001a7aba(*puVar4,puVar4);
  }
  if (puVar5 != (uint *)0x0) {
    FUN_001a7aba(*puVar6,puVar6);
  }
  return;
}

/* FUN_00125948 @ 0x125948 (1312 bytes) */
int FUN_00125948(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  int iVar11;
  int local_40;
  byte local_35;
  undefined1 uStack_29;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  cVar3 = FUN_000e1402(*(undefined4 *)(param_2 + 8),6);
  if (cVar3 != '\0') {
    local_40 = 1;
    piVar7 = *(int **)(param_1 + 0xb0);
    iVar11 = param_1;
    while( true ) {
      iVar4 = (**(code **)(*piVar7 + 0x14))(piVar7);
      if (iVar4 < local_40) break;
      piVar1 = (int *)(iVar11 + 0x214);
      cVar3 = (**(code **)(**(int **)(iVar11 + 0x214) + 100))(*(int **)(iVar11 + 0x214));
      if (cVar3 == '\0') {
LAB_0012598a:
        piVar7 = *(int **)(param_1 + 0xb0);
      }
      else {
        cVar3 = FUN_0012dfd8(*(undefined4 *)(*(int *)(iVar11 + 0x214) + 0x98));
        if (cVar3 == '\0') {
LAB_001259da:
          piVar7 = *(int **)(param_1 + 0xb0);
        }
        else {
          cVar3 = ((int (*)())FUN_001253d6)(param_2,*(undefined4 *)(iVar11 + 0x214));
          if (cVar3 == '\0') {
            iVar4 = *(int *)(iVar11 + 0x214);
            if (*(char *)(iVar4 + 0x120) != '\0') goto LAB_0012598a;
            if (*(int *)(iVar4 + 0x124) != 0) goto LAB_001259da;
            FUN_0010b0f4(iVar4,0);
            iVar4 = FUN_0010b7c8(iVar4,0);
            if (iVar4 != 0) goto LAB_00125db9;
            iVar4 = *(int *)(iVar11 + 0x214);
            iVar5 = FUN_0010b180(iVar4,1);
            if (iVar5 == 0) {
              uVar6 = *(undefined4 *)(iVar4 + 0xb0);
            }
            else {
              iVar4 = FUN_0010b180(iVar4,1);
              uVar6 = *(undefined4 *)(iVar4 + 0x98);
            }
            cVar3 = FUN_0012df9c(uVar6);
            if (cVar3 == '\0') {
              iVar4 = *piVar1;
              iVar5 = FUN_0010b180(iVar4,1);
              if (iVar5 == 0) {
                uVar6 = *(undefined4 *)(iVar4 + 0xb0);
              }
              else {
                iVar4 = FUN_0010b180(iVar4,1);
                uVar6 = *(undefined4 *)(iVar4 + 0x98);
              }
              cVar3 = FUN_0012dfba(uVar6);
              if (cVar3 == '\0') goto LAB_0012598a;
            }
            iVar4 = *piVar1;
            FUN_0010b0f4(iVar4,1);
            iVar4 = FUN_0010b7c8(iVar4,1);
            if (iVar4 == 0) {
              iVar4 = *piVar1;
            }
            else {
              iVar4 = FUN_0010b7c8(*piVar1,1);
              if (iVar4 != 1) goto LAB_001259da;
              piVar7 = *(int **)(param_1 + 0xb0);
              iVar4 = *piVar1;
              if (piVar7[0x56] != *(int *)(iVar4 + 0x158)) goto LAB_00125993;
            }
            iVar4 = FUN_0010b180(iVar4,1);
            uVar10 = *(uint *)(*piVar1 + 0xb8);
            local_35 = (byte)(uVar10 >> 1) & 1;
            uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xa0 + local_40 * 0x18);
            if ((uVar2 & 2) == 0) {
              if ((uVar2 & 1) == 0) {
                if ((uVar10 & 1) == 0) goto LAB_00125e02;
              }
              else if ((uVar10 & 1) != 0) {
LAB_00125e02:
                uVar10 = 0;
                goto LAB_00125b91;
              }
              uVar10 = 1;
            }
            else {
              uVar10 = uVar10 >> 1 & 1;
              local_35 = 1;
            }
LAB_00125b91:
            piVar7 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
            cVar3 = (**(code **)(*piVar7 + 0x11c))
                              (piVar7,*(int *)(param_1 + 0xb0),local_40,iVar4,local_35,uVar10,
                               *(int *)(param_1 + 0x238));
            if (cVar3 != '\0') {
              cVar3 = FUN_000f6a7e(*(undefined4 *)(param_1 + 0xb0),local_40,*piVar1,param_2);
              if (cVar3 == '\0') goto LAB_0012598a;
              *(int *)(param_2 + 0xa4) = *(int *)(param_2 + 0xa4) + 1;
              iVar8 = *(int *)(param_1 + 0xb0);
              iVar5 = local_40 * 0x18 + 0x80;
              if ((*(byte *)(iVar8 + 0x20 + iVar5) & 2) == 0) {
                if ((*(byte *)(*piVar1 + 0xb8) & 2) != 0) {
                  FUN_00109c0e(iVar8 + 0xc + iVar5,2,1);
                  iVar8 = *(int *)(param_1 + 0xb0);
                }
                if ((*(byte *)(iVar8 + 0x20 + iVar5) & 1) == 0) {
                  if ((*(byte *)(*piVar1 + 0xb8) & 1) == 0) goto LAB_00125e20;
LAB_00125c58:
                  uVar6 = 1;
                }
                else {
                  if ((*(byte *)(*piVar1 + 0xb8) & 1) == 0) goto LAB_00125c58;
LAB_00125e20:
                  uVar6 = 0;
                }
                FUN_00109c0e(iVar8 + 0x8c + local_40 * 0x18,1,uVar6);
                iVar8 = *(int *)(param_1 + 0xb0);
              }
              iVar5 = FUN_0010b0f4(iVar8,local_40);
              local_20[0] = *(undefined4 *)(iVar5 + 0x10);
              cVar3 = FUN_0011902c(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                                   *(undefined4 *)(param_1 + 0x238));
              if (cVar3 == '\0') {
                local_20[0] = FUN_000f5b96(local_20[0],*(undefined4 *)(iVar11 + 0x228));
              }
              iVar5 = FUN_0010b0f4(*piVar1,1);
              uVar6 = DAT_001cc400;
              local_24 = *(undefined4 *)(iVar5 + 0x10);
              local_28 = DAT_001cc400;
              pcVar9 = (char *)(param_1 + 0x224 + local_40 * 4);
              iVar5 = 1;
              do {
                if (*pcVar9 != '\0') {
                  (&uStack_29)[iVar5] =
                       *(undefined1 *)((int)local_20 + (*(byte *)((int)local_20 + iVar5 + -1) - 4));
                }
                iVar5 = iVar5 + 1;
                pcVar9 = pcVar9 + 1;
              } while (iVar5 != 5);
              if (local_40 == 0) {
                *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x9c) = DAT_001cc400;
              }
              else {
                iVar5 = FUN_0010b0f4(*(int *)(param_1 + 0xb0),local_40);
                *(undefined4 *)(iVar5 + 0x10) = uVar6;
              }
              uVar6 = *(undefined4 *)(iVar4 + 0x8c);
              FUN_0010a3c2(*(undefined4 *)(param_1 + 0xb0),local_40,uVar6);
              ((int (*)())FUN_0012a9e6)(uVar6,local_40,*(undefined4 *)(param_1 + 0xb0));
              *piVar1 = iVar4;
              piVar7 = *(int **)(param_1 + 0xb0);
              goto LAB_00125993;
            }
          }
LAB_00125db9:
          piVar7 = *(int **)(param_1 + 0xb0);
        }
      }
LAB_00125993:
      local_40 = local_40 + 1;
      iVar11 = iVar11 + 4;
    }
  }
  return;
}

/* FUN_00125e68 @ 0x125e68 (609 bytes) */
int FUN_00125e68(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  undefined4 param_3;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  cVar1 = FUN_000e1402(*(undefined4 *)(param_1 + 8),5);
  if ((cVar1 != '\0') && (cVar1 = (**(code **)(*param_2 + 100))(param_2), cVar1 != '\0')) {
    for (iVar5 = 1; iVar2 = (**(code **)(*param_2 + 0x14))(param_2), iVar5 <= iVar2;
        iVar5 = iVar5 + 1) {
      if ((param_2[iVar5 * 6 + 0x28] & 1U) != 0) {
        return 0;
      }
      if ((param_2[iVar5 * 6 + 0x28] & 2U) != 0) {
        return 0;
      }
      cVar1 = FUN_000f5a1e(param_2,iVar5);
      if (cVar1 == '\0') {
        return 0;
      }
    }
    if (((char)param_2[0x48] == '\0') && (param_2[0x49] == 0)) {
      if ((param_2[0x20] != 0) &&
         (((cVar1 = FUN_0012dfd8(param_2[0x26]), cVar1 != '\0' &&
           ((*(byte *)(param_2 + 5) & 2) == 0)) &&
          (cVar1 = (**(code **)(*param_2 + 0x50))(param_2), cVar1 == '\0')))) {
        iVar5 = 4;
        piVar4 = param_2;
        do {
          if ((byte)((char)piVar4[0x27] - 2U) < 2) {
            return 0;
          }
          piVar4 = (int *)((int)piVar4 + 1);
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      FUN_0010b0f4(param_2,0);
      iVar5 = FUN_0010b7c8(param_2,0);
      if (((iVar5 == 0) && ((param_2[5] & 2U) == 0)) &&
         (((param_2[5] & 0x200U) == 0 && (cVar1 = FUN_0012dfd8(param_2[0x26]), cVar1 != '\0')))) {
        iVar5 = FUN_0010b180(param_2,1);
        if (iVar5 == 0) {
          iVar5 = param_2[0x2c];
        }
        else {
          iVar5 = FUN_0010b180(param_2,1);
          iVar5 = *(int *)(iVar5 + 0x98);
        }
        cVar1 = FUN_0012dff6(iVar5);
        if (cVar1 == '\0') {
          iVar5 = FUN_0010b180(param_2,1);
          if (iVar5 == 0) {
            iVar5 = param_2[0x2c];
          }
          else {
            iVar5 = FUN_0010b180(param_2,1);
            iVar5 = *(int *)(iVar5 + 0x98);
          }
          if (((iVar5 != 0x31) && (cVar1 = ((int (*)())FUN_001253d6)(param_1,param_2), cVar1 == '\0')) &&
             (*(int *)(param_1 + 0xa0) < *(int *)(*(int *)(param_1 + 8) + 900))) {
            uVar3 = ((int (*)())FUN_0012a37e)(param_2[0x29],*(undefined4 *)(param_1 + 0x394),
                                 *(int *)(param_1 + 8));
            FUN_000eb51a(param_3,param_2[0x23],uVar3);
            (**(code **)(*param_2 + 0xc))(param_2,0,*(undefined4 *)(param_1 + 8));
            param_2[5] = param_2[5] | 0x400;
            *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + 1;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_001260ca @ 0x1260ca (593 bytes) */
int FUN_001260ca(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  uint *local_34;
  int local_30;
  uint local_20;
  uint local_1c;
  int *local_18;
  undefined4 local_14;
  int *local_10;
  
  local_14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_1c = 0;
  local_20 = 2;
  local_18 = (int *)FUN_001a7bca(local_14,8);
  *(undefined4 *)(*(int *)(param_1 + 0x394) + 0x10c) = 0x10;
  iVar2 = *(int *)(param_1 + 0x394);
  if (local_1c < local_20) {
    local_18[local_1c] = 0;
    piVar3 = local_18 + local_1c;
    local_1c = local_1c + 1;
  }
  else {
    piVar3 = (int *)FUN_001a7f7c(&local_20,local_1c);
  }
  local_34 = &local_20;
  *piVar3 = iVar2;
  do {
    if (local_20 == 0) {
      piVar3 = (int *)FUN_001a7f7c(local_34,0);
    }
    else {
      piVar3 = local_18;
      if (local_1c == 0) {
        *local_18 = 0;
        local_1c = 1;
      }
    }
    piVar3 = (int *)*piVar3;
    FUN_001a7f3c(local_34,0);
    local_10 = (int *)0x0;
    uVar5 = 1;
    local_30 = 0;
    iVar2 = piVar3[0x34];
    if (*(int *)(iVar2 + 4) != 0) {
      do {
        local_10 = *(int **)(*(int *)(iVar2 + 8) + local_30);
        if ((local_10 != (int *)0x0) && (local_10[0x43] == 0)) {
          if (piVar3[0x2e] < local_10[0x2e]) {
            local_10[0x43] = piVar3[0x43] << 2;
          }
          else {
            cVar1 = (**(code **)(*local_10 + 0x34))(local_10);
            if (cVar1 == '\0') {
              cVar1 = (**(code **)(*piVar3 + 0x24))(piVar3);
              if (cVar1 == '\0') {
                cVar1 = (**(code **)(*local_10 + 0x28))(local_10);
                if (cVar1 == '\0') {
                  local_10[0x43] = piVar3[0x43];
                }
                else {
                  local_10[0x43] = piVar3[0x43] * 2;
                }
              }
              else {
                iVar2 = 1;
                if (0 < piVar3[0x43] / 2) {
                  iVar2 = piVar3[0x43] / 2;
                }
                local_10[0x43] = iVar2;
              }
            }
            else {
              local_10[0x43] = *(int *)(local_10[0x49] + 0x10c);
            }
          }
          if (local_1c < local_20) {
            local_18[local_1c] = 0;
            piVar4 = local_18 + local_1c;
            local_1c = local_1c + 1;
          }
          else {
            piVar4 = (int *)FUN_001a7f7c(local_34,local_1c);
          }
          *piVar4 = (int)local_10;
        }
        uVar5 = uVar5 + 1;
        local_30 = local_30 + 4;
        iVar2 = piVar3[0x34];
      } while (uVar5 <= *(uint *)(iVar2 + 4));
    }
  } while (local_1c != 0);
  FUN_001a7aba(local_14,local_18);
  return;
}

/* FUN_00126338 @ 0x126338 (153 bytes) */
int FUN_00126338(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  iVar1 = *(int *)(param_1 + 0x468);
  if (*(int *)(param_2 + 0x150) <= iVar1) {
    uVar2 = param_3[1];
    if (uVar2 < *param_3) {
      _memset((void *)(uVar2 * 4 + param_3[2]),0,4);
      param_3[1] = uVar2 + 1;
      piVar3 = (int *)(uVar2 * 4 + param_3[2]);
    }
    else {
      piVar3 = (int *)FUN_001a7f7c(param_3,uVar2);
    }
    *piVar3 = param_2;
    uVar2 = param_3[1];
    *(uint *)(param_2 + 0x150) = iVar1 + 1 + (uVar2 - 1);
    return uVar2 - 1;
  }
  return (*(int *)(param_2 + 0x150) - iVar1) + -1;
}

/* FUN_001263d2 @ 0x1263d2 (784 bytes) */
int FUN_001263d2(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  uint *param_1;
  int param_2;
  int *param_3;
  int param_4;
  uint param_5;
  int param_6;
  int param_7;
  int param_8;
  uint *param_9;
  uint param_10;
{
  uint uVar1;
  int *piVar2;
  code *pcVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  
  piVar5 = (int *)FUN_0010a17a(0x31,param_7);
  piVar5[0x25] = param_2;
  piVar5[0x26] = 0;
  if (param_5 < *param_1) {
    uVar1 = param_1[1];
    if (uVar1 <= param_5) {
      _memset((void *)(param_1[2] + uVar1 * 4),0,(param_5 - uVar1) * 4 + 4);
      param_1[1] = param_5 + 1;
      uVar1 = *param_1;
      goto joined_r0x00126624;
    }
  }
  else {
    FUN_001a7f7c(param_1,param_5);
  }
  uVar1 = *param_1;
joined_r0x00126624:
  if (param_5 < uVar1) {
    uVar1 = param_1[1];
    if (uVar1 <= param_5) {
      _memset((void *)(param_1[2] + uVar1 * 4),0,(param_5 - uVar1) * 4 + 4);
      param_1[1] = param_5 + 1;
    }
    puVar8 = (undefined4 *)(param_1[2] + param_5 * 4);
  }
  else {
    puVar8 = (undefined4 *)FUN_001a7f7c(param_1,param_5);
  }
  FUN_0010ba02(piVar5,1,*puVar8,0,param_7);
  if (param_4 != '\0') {
    piVar5[5] = piVar5[5] | 0x40;
  }
  piVar2 = *(int **)(*(int *)(param_7 + 0x54) + 100);
  pcVar3 = *(code **)(*piVar2 + 0x20);
  if (param_5 < *param_1) {
    uVar1 = param_1[1];
    if (uVar1 <= param_5) {
      _memset((void *)(param_1[2] + uVar1 * 4),0,(param_5 - uVar1) * 4 + 4);
      param_1[1] = param_5 + 1;
    }
    puVar8 = (undefined4 *)(param_1[2] + param_5 * 4);
  }
  else {
    puVar8 = (undefined4 *)FUN_001a7f7c(param_1,param_5);
  }
  cVar4 = (*pcVar3)(piVar2,*puVar8);
  if ((cVar4 != '\0') && ((*(byte *)(param_6 + 0xd) & 2) == 0)) {
    piVar5[5] = piVar5[5] | 0x1000;
    *(uint *)(param_6 + 0xc) = *(uint *)(param_6 + 0xc) | 0x200;
  }
  FUN_000e9512(param_6,piVar5);
  piVar5[5] = piVar5[5] | 0x40000000;
  if (*param_3 != DAT_001cc408) {
    piVar5[0x27] = *param_3;
    iVar9 = 0;
    do {
      iVar6 = FUN_0010b0f4(piVar5,0);
      if (*(char *)(iVar9 + 0x10 + iVar6) == '\x01') {
        (**(code **)(*piVar5 + 0x88))(piVar5,1,iVar9,4);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != 4);
  }
  if (param_8 != '\0') {
    if (param_10 < *param_9) {
      uVar1 = param_9[1];
      if (uVar1 <= param_10) {
        _memset((void *)(param_9[2] + uVar1 * 4),0,(param_10 - uVar1) * 4 + 4);
        param_9[1] = param_10 + 1;
      }
      puVar8 = (undefined4 *)(param_9[2] + param_10 * 4);
    }
    else {
      puVar8 = (undefined4 *)FUN_001a7f7c(param_9,param_10);
    }
    uVar7 = ((int (*)())FUN_00126338)();
    *puVar8 = uVar7;
  }
  return;
}

/* FUN_001266e2 @ 0x1266e2 (971 bytes) */
int FUN_001266e2(param_1)
  int param_1;
{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  uint local_1c;
  uint local_18;
  int local_14;
  undefined4 local_10;
  
  local_10 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_18 = 0;
  local_1c = 2;
  local_14 = FUN_001a7bca(local_10,8);
  iVar4 = *(int *)(param_1 + 0x378);
  iVar9 = *(int *)(iVar4 + 8);
  while (iVar9 != 0) {
    piVar2 = *(int **)(iVar4 + 0x98);
    iVar9 = piVar2[2];
    while (iVar9 != 0) {
      if (((*(byte *)(piVar2 + 5) & 1) != 0) &&
         (iVar9 = (**(code **)(*piVar2 + 0x7c))(piVar2), uVar1 = local_18, iVar9 != 0)) {
        if (local_18 < local_1c) {
          iVar5 = local_18 * 4;
          _memset((void *)(iVar5 + local_14),0,4);
          local_18 = uVar1 + 1;
          piVar8 = (int *)(iVar5 + local_14);
        }
        else {
          piVar8 = (int *)FUN_001a7f7c(&local_1c,local_18);
        }
        *piVar8 = iVar9;
        *(undefined1 *)(iVar9 + 0x134) = 1;
      }
      piVar2 = (int *)piVar2[2];
      iVar9 = piVar2[2];
    }
    iVar4 = *(int *)(iVar4 + 8);
    iVar9 = *(int *)(iVar4 + 8);
  }
  while ((local_18 != 0 && (*(int *)(param_1 + 0x22c) < *(int *)(*(int *)(param_1 + 8) + 0x3a0)))) {
    uVar1 = local_18 - 1;
    if (uVar1 < local_18) {
      puVar3 = (undefined4 *)(local_14 + uVar1 * 4);
    }
    else {
      puVar3 = (undefined4 *)0x0;
    }
    piVar2 = (int *)*puVar3;
    FUN_001a7f3c(&local_1c,uVar1);
    *(undefined1 *)(piVar2 + 0x4d) = 0;
    iVar4 = ((int (*)())FUN_00125206)(piVar2);
    if (iVar4 != 0) {
      while (piVar8 = (int *)piVar2[4], piVar8[1] != 0) {
        if (*piVar8 == 0) {
          piVar8 = (int *)FUN_001a7f7c(piVar8,0);
        }
        else {
          if (piVar8[1] == 0) {
            *(undefined4 *)piVar8[2] = 0;
            piVar8[1] = 1;
          }
          piVar8 = (int *)piVar8[2];
        }
        piVar8 = (int *)*piVar8;
        iVar9 = piVar8[0x22];
        if (*(int *)(iVar9 + 8) == 0x8e) {
          if (0 < piVar8[0x21]) {
            iVar9 = 1;
            do {
              piVar6 = (int *)FUN_0010b180(piVar8,iVar9);
              if (piVar6 == piVar2) {
                FUN_0010ba02(piVar8,iVar9,iVar4,1,*(undefined4 *)(param_1 + 8));
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 <= piVar8[0x21]);
            iVar9 = piVar8[0x22];
          }
          if (((*(int *)(iVar9 + 8) == 0x8e) &&
              (piVar6 = (int *)(**(code **)(*piVar8 + 0x7c))(piVar8), piVar2 != piVar6)) &&
             (iVar9 = (**(code **)(*piVar8 + 0x7c))(piVar8), *(char *)(iVar9 + 0x134) == '\0')) {
            uVar7 = (**(code **)(*piVar8 + 0x7c))(piVar8);
            uVar1 = local_18;
            if (local_18 < local_1c) {
              iVar9 = local_18 * 4;
              _memset((void *)(iVar9 + local_14),0,4);
              local_18 = uVar1 + 1;
              puVar3 = (undefined4 *)(iVar9 + local_14);
            }
            else {
              puVar3 = (undefined4 *)FUN_001a7f7c(&local_1c,local_18);
            }
            *puVar3 = uVar7;
            iVar9 = (**(code **)(*piVar8 + 0x7c))(piVar8);
            *(undefined1 *)(iVar9 + 0x134) = 0;
          }
        }
        else {
          iVar9 = 1;
          while (iVar5 = (**(code **)(*piVar8 + 0x14))(piVar8), iVar9 <= iVar5) {
            piVar6 = (int *)FUN_0010b180(piVar8,iVar9);
            if (piVar6 == piVar2) {
              FUN_0010ba02(piVar8,iVar9,iVar4,1,*(undefined4 *)(param_1 + 8));
              iVar9 = iVar9 + 1;
            }
            else {
              iVar9 = iVar9 + 1;
            }
          }
          if (((*(byte *)((int)piVar8 + 0x15) & 2) != 0) &&
             (piVar6 = (int *)FUN_0010b180(piVar8,piVar8[0x21]), piVar6 == piVar2)) {
            FUN_0010c18e(piVar8,iVar4,1,*(undefined4 *)(param_1 + 8));
          }
        }
      }
      FUN_00109e42(piVar2,param_1);
      (**(code **)(*piVar2 + 0xc))(piVar2,1,*(undefined4 *)(param_1 + 8));
      *(int *)(param_1 + 0x22c) = *(int *)(param_1 + 0x22c) + 1;
    }
  }
  FUN_001a7aba(local_10,local_14);
  return;
}

/* FUN_00126aca @ 0x126aca (4091 bytes) */
int FUN_00126aca(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int *param_2;
  uint *param_3;
  uint *param_4;
  uint *param_5;
  uint *param_6;
  uint *param_7;
  int *param_8;
{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  uint *puVar11;
  int iVar12;
  int iVar13;
  undefined1 *puVar14;
  uint uVar15;
  uint local_80;
  int *local_74;
  undefined4 local_68;
  int local_40;
  uint local_3c;
  int local_38;
  
  param_3[1] = 0;
  param_4[1] = 0;
  param_5[1] = 0;
  param_6[1] = 0;
  param_7[1] = 0;
  local_3c = 1;
  local_38 = 0;
  iVar8 = param_2[0x34];
  if (*(int *)(iVar8 + 4) != 0) {
    do {
      iVar12 = *(int *)(local_38 + *(int *)(iVar8 + 8));
      if (iVar12 != 0) {
        uVar3 = FUN_000e9c92(iVar12,param_2);
        local_74 = *(int **)(iVar12 + 0x98);
        if (local_74[2] == 0) {
          iVar8 = param_2[0x34];
        }
        else {
LAB_00126b89:
          do {
            if (((*(byte *)(local_74 + 5) & 1) != 0) &&
               (iVar8 = (**(code **)(*local_74 + 0x7c))(local_74), iVar8 != 0)) {
              piVar9 = (int *)FUN_0010b180(iVar8,uVar3);
              if ((piVar9[0x20] == 0) ||
                 (((cVar2 = FUN_0012dfd8(piVar9[0x26]), cVar2 == '\0' ||
                   ((*(byte *)(piVar9 + 5) & 2) != 0)) ||
                  (cVar2 = (**(code **)(*piVar9 + 0x50))(piVar9), cVar2 != '\0')))) {
                cVar2 = (**(code **)(*piVar9 + 0x60))(piVar9);
                if (cVar2 != '\0') {
LAB_00126bcc:
                  uVar7 = ((int (*)())FUN_00126338)();
                  uVar15 = ((int (*)())FUN_00126338)();
                  uVar5 = param_4[1];
                  if (uVar5 < *param_4) {
                    _memset((void *)(uVar5 * 4 + param_4[2]),0,4);
                    param_4[1] = uVar5 + 1;
                    piVar9 = (int *)(uVar5 * 4 + param_4[2]);
                  }
                  else {
                    piVar9 = (int *)FUN_001a7f7c(param_4,uVar5);
                  }
                  *piVar9 = uVar15 * 0x10000 + uVar7;
                  if (uVar15 < *param_5) {
                    uVar5 = param_5[1];
                    if (uVar5 <= uVar15) {
                      _memset((void *)(param_5[2] + uVar5 * 4),0,(uVar15 - uVar5) * 4 + 4);
                      param_5[1] = uVar15 + 1;
                    }
                    puVar11 = (uint *)(param_5[2] + uVar15 * 4);
                  }
                  else {
                    puVar11 = (uint *)FUN_001a7f7c(param_5,uVar15);
                  }
                  *puVar11 = uVar15;
                  if (uVar7 < *param_5) {
                    uVar5 = param_5[1];
                    if (uVar5 <= uVar7) {
                      _memset((void *)(param_5[2] + uVar5 * 4),0,(uVar7 - uVar5) * 4 + 4);
                      param_5[1] = uVar7 + 1;
                    }
                    puVar11 = (uint *)(param_5[2] + uVar7 * 4);
                  }
                  else {
                    puVar11 = (uint *)FUN_001a7f7c(param_5,uVar7);
                  }
                  *puVar11 = uVar7;
                  if (uVar15 < *param_3) {
                    uVar5 = param_3[1];
                    if (uVar5 <= uVar15) {
                      _memset((void *)(param_3[2] + uVar5 * 4),0,(uVar15 - uVar5) * 4 + 4);
                      param_3[1] = uVar15 + 1;
                    }
                    puVar14 = (undefined1 *)(param_3[2] + uVar15 * 4);
                  }
                  else {
                    puVar14 = (undefined1 *)FUN_001a7f7c(param_3,uVar15);
                  }
                  *puVar14 = 1;
                  if (uVar15 < *param_5) {
                    uVar5 = param_5[1];
                    if (uVar5 <= uVar15) {
                      _memset((void *)(param_5[2] + uVar5 * 4),0,(uVar15 - uVar5) * 4 + 4);
                      param_5[1] = uVar15 + 1;
                    }
                    puVar11 = (uint *)(param_5[2] + uVar15 * 4);
                  }
                  else {
                    puVar11 = (uint *)FUN_001a7f7c(param_5,uVar15);
                  }
                  uVar5 = *puVar11;
                  if (uVar5 < *param_7) {
                    uVar15 = param_7[1];
                    if (uVar15 <= uVar5) {
                      _memset((void *)(param_7[2] + uVar15 * 4),0,(uVar5 - uVar15) * 4 + 4);
                      param_7[1] = uVar5 + 1;
                    }
                  }
                  else {
                    FUN_001a7f7c(param_7,uVar5);
                  }
                  if (uVar7 < *param_5) {
                    uVar5 = param_5[1];
                    if (uVar5 <= uVar7) {
                      _memset((void *)(param_5[2] + uVar5 * 4),0,(uVar7 - uVar5) * 4 + 4);
                      param_5[1] = uVar7 + 1;
                    }
                    puVar11 = (uint *)(param_5[2] + uVar7 * 4);
                  }
                  else {
                    puVar11 = (uint *)FUN_001a7f7c(param_5,uVar7);
                  }
                  uVar5 = *puVar11;
                  if (uVar5 < *param_7) {
                    uVar7 = param_7[1];
                    if (uVar7 <= uVar5) {
                      _memset((void *)(param_7[2] + uVar7 * 4),0,(uVar5 - uVar7) * 4 + 4);
                      param_7[1] = uVar5 + 1;
                      local_74 = (int *)local_74[2];
                      if (local_74[2] == 0) break;
                      goto LAB_00126b89;
                    }
                  }
                  else {
                    FUN_001a7f7c(param_7,uVar5);
                  }
                }
              }
              else {
                iVar12 = FUN_0010b0f4(iVar8,0);
                iVar13 = FUN_0010b0f4(piVar9,0);
                if (((iVar12 != iVar13) || (*(int *)(iVar8 + 0x98) != piVar9[0x26])) ||
                   (((byte)(*(uint *)(iVar8 + 0x14) >> 6) & 1) != ((byte)((uint)piVar9[5] >> 6) & 1)
                   )) goto LAB_00126bcc;
              }
            }
            local_74 = (int *)local_74[2];
          } while (local_74[2] != 0);
          iVar8 = param_2[0x34];
        }
      }
      local_38 = local_38 + 4;
      local_3c = local_3c + 1;
    } while (local_3c <= *(uint *)(iVar8 + 4));
  }
  local_80 = param_4[1] - 1;
  if (-1 < (int)local_80) {
    local_40 = local_80 * 4;
    do {
      if (local_80 < *param_4) {
        uVar5 = param_4[1];
        if (uVar5 <= local_80) {
          _memset((void *)(param_4[2] + uVar5 * 4),0,(local_80 - uVar5) * 4 + 4);
          param_4[1] = local_80 + 1;
        }
        local_68 = *(undefined4 *)(local_40 + param_4[2]);
        uVar5 = ((int (*)())FUN_001251fc)();
        if (uVar5 < *param_3) goto LAB_00126dd9;
LAB_00126e9b:
        pcVar6 = (char *)FUN_001a7f7c(param_3,uVar5);
      }
      else {
        puVar4 = (undefined4 *)FUN_001a7f7c(param_4,local_80);
        local_68 = *puVar4;
        uVar5 = ((int (*)())FUN_001251fc)();
        if (*param_3 <= uVar5) goto LAB_00126e9b;
LAB_00126dd9:
        uVar7 = param_3[1];
        if (uVar7 <= uVar5) {
          _memset((void *)(param_3[2] + uVar7 * 4),0,(uVar5 - uVar7) * 4 + 4);
          param_3[1] = uVar5 + 1;
        }
        pcVar6 = (char *)(param_3[2] + uVar5 * 4);
      }
      if (*pcVar6 == '\0') {
        uVar5 = param_6[1];
        if (uVar5 < *param_6) {
          _memset((void *)(uVar5 * 4 + param_6[2]),0,4);
          param_6[1] = uVar5 + 1;
          puVar4 = (undefined4 *)(uVar5 * 4 + param_6[2]);
        }
        else {
          puVar4 = (undefined4 *)FUN_001a7f7c(param_6,uVar5);
        }
        *puVar4 = local_68;
        FUN_001a7f3c(param_4,local_80);
      }
      local_80 = local_80 - 1;
      local_40 = local_40 + -4;
    } while (local_80 != 0xffffffff);
  }
  do {
    do {
      if ((param_6[1] == 0) && (param_4[1] == 0)) {
        *(uint *)(param_1 + 0x468) = *(int *)(param_1 + 0x468) + param_7[1];
        return;
      }
LAB_00126fe9:
      if (param_6[1] != 0) {
        uVar7 = param_6[1];
        uVar5 = uVar7 - 1;
        if (uVar5 < *param_6) {
          if (uVar7 <= uVar5) {
            _memset((void *)(param_6[2] + uVar7 * 4),0,(uVar5 - uVar7) * 4 + 4);
            param_6[1] = uVar7;
          }
          piVar9 = (int *)(param_6[2] + uVar5 * 4);
        }
        else {
          piVar9 = (int *)FUN_001a7f7c(param_6,uVar5);
        }
        uVar15 = *piVar9 >> 0x10;
        uVar7 = ((int (*)())FUN_001251fc)();
        FUN_001a7f3c(param_6,uVar5);
        if (uVar7 < *param_7) {
          uVar5 = param_7[1];
          if (uVar5 <= uVar7) {
            _memset((void *)(param_7[2] + uVar5 * 4),0,(uVar7 - uVar5) * 4 + 4);
            param_7[1] = uVar7 + 1;
          }
        }
        else {
          FUN_001a7f7c(param_7,uVar7);
        }
        if (uVar7 < *param_7) {
          uVar5 = param_7[1];
          if (uVar5 <= uVar7) {
            _memset((void *)(param_7[2] + uVar5 * 4),0,(uVar7 - uVar5) * 4 + 4);
            param_7[1] = uVar7 + 1;
          }
          puVar4 = (undefined4 *)(param_7[2] + uVar7 * 4);
        }
        else {
          puVar4 = (undefined4 *)FUN_001a7f7c(param_7,uVar7);
        }
        iVar8 = FUN_0010b0f4(*puVar4,0);
        iVar8 = *(int *)(iVar8 + 0x10);
        if (uVar7 < *param_7) {
          uVar5 = param_7[1];
          if (uVar5 <= uVar7) {
            _memset((void *)(param_7[2] + uVar5 * 4),0,(uVar7 - uVar5) * 4 + 4);
            param_7[1] = uVar7 + 1;
          }
          piVar9 = (int *)(param_7[2] + uVar7 * 4);
        }
        else {
          piVar9 = (int *)FUN_001a7f7c(param_7,uVar7);
        }
        bVar1 = (byte)(*(uint *)(*piVar9 + 0x14) >> 6) & 1;
        piVar9 = (int *)FUN_000eac0c(param_2,0);
        cVar2 = (**(code **)(*piVar9 + 0x2c))(piVar9);
        if (cVar2 == '\0') {
LAB_00127108:
          cVar2 = (**(code **)(*param_2 + 0x38))(param_2);
          if (cVar2 == '\0') {
            uVar3 = *(undefined4 *)(param_1 + 8);
            piVar9 = param_2;
            if (uVar15 < *param_5) {
              uVar5 = param_5[1];
              if (uVar5 <= uVar15) {
                _memset((void *)(param_5[2] + uVar5 * 4),0,(uVar15 - uVar5) * 4 + 4);
                param_5[1] = uVar15 + 1;
              }
              puVar4 = (undefined4 *)(param_5[2] + uVar15 * 4);
            }
            else {
              puVar4 = (undefined4 *)FUN_001a7f7c(param_5,uVar15);
            }
          }
          else {
            piVar9 = (int *)FUN_000eac0c(param_2,0);
            uVar3 = *(undefined4 *)(param_1 + 8);
            if (uVar15 < *param_5) {
              uVar5 = param_5[1];
              if (uVar5 <= uVar15) {
                _memset((void *)(param_5[2] + uVar5 * 4),0,(uVar15 - uVar5) * 4 + 4);
                param_5[1] = uVar15 + 1;
              }
              puVar4 = (undefined4 *)(param_5[2] + uVar15 * 4);
            }
            else {
              puVar4 = (undefined4 *)FUN_001a7f7c(param_5,uVar15);
            }
          }
          ((int (*)())FUN_001263d2)(bVar1,*puVar4,piVar9,uVar3,0,0,0xffffffff);
        }
        else {
          piVar9 = (int *)FUN_000eac7c(param_2,0);
          cVar2 = (**(code **)(*piVar9 + 0x34))(piVar9);
          if (cVar2 == '\0') goto LAB_00127108;
          uVar3 = FUN_000eac0c(param_2,0);
          uVar10 = FUN_000eac0c(uVar3,0);
          uVar3 = *(undefined4 *)(param_1 + 8);
          if (uVar15 < *param_5) {
            uVar5 = param_5[1];
            if (uVar5 <= uVar15) {
              _memset((void *)(param_5[2] + uVar5 * 4),0,(uVar15 - uVar5) * 4 + 4);
              param_5[1] = uVar15 + 1;
            }
            puVar4 = (undefined4 *)(param_5[2] + uVar15 * 4);
          }
          else {
            puVar4 = (undefined4 *)FUN_001a7f7c(param_5,uVar15);
          }
          ((int (*)())FUN_001263d2)(bVar1,*puVar4,uVar10,uVar3,0,0,0xffffffff);
          uVar3 = FUN_000eac0c(param_2,0);
          uVar10 = FUN_000eac0c(uVar3,1);
          uVar3 = *(undefined4 *)(param_1 + 8);
          if (uVar15 < *param_5) {
            uVar5 = param_5[1];
            if (uVar5 <= uVar15) {
              _memset((void *)(param_5[2] + uVar5 * 4),0,(uVar15 - uVar5) * 4 + 4);
              param_5[1] = uVar15 + 1;
            }
            puVar4 = (undefined4 *)(param_5[2] + uVar15 * 4);
          }
          else {
            puVar4 = (undefined4 *)FUN_001a7f7c(param_5,uVar15);
          }
          ((int (*)())FUN_001263d2)(bVar1,*puVar4,uVar10,uVar3,0,0,0xffffffff);
        }
        if (iVar8 == DAT_001cc408) {
          if (uVar15 < *param_5) {
            uVar5 = param_5[1];
            if (uVar5 <= uVar15) {
              _memset((void *)(param_5[2] + uVar5 * 4),0,(uVar15 - uVar5) * 4 + 4);
              param_5[1] = uVar15 + 1;
            }
            *(uint *)(param_5[2] + uVar15 * 4) = uVar7;
          }
          else {
            puVar11 = (uint *)FUN_001a7f7c(param_5,uVar15);
            *puVar11 = uVar7;
          }
        }
        uVar5 = param_4[1] - 1;
        if (-1 < (int)uVar5) {
          iVar8 = uVar5 * 4;
          do {
            if (uVar5 < *param_4) {
              uVar7 = param_4[1];
              if (uVar7 <= uVar5) {
                _memset((void *)(param_4[2] + uVar7 * 4),0,(uVar5 - uVar7) * 4 + 4);
                param_4[1] = uVar5 + 1;
              }
              uVar3 = *(undefined4 *)(iVar8 + param_4[2]);
              uVar7 = ((int (*)())FUN_001251fc)();
            }
            else {
              puVar4 = (undefined4 *)FUN_001a7f7c(param_4,uVar5);
              uVar3 = *puVar4;
              uVar7 = ((int (*)())FUN_001251fc)();
            }
            if (uVar15 == uVar7) {
              uVar7 = param_6[1];
              if (uVar7 < *param_6) {
                _memset((void *)(uVar7 * 4 + param_6[2]),0,4);
                param_6[1] = uVar7 + 1;
                puVar4 = (undefined4 *)(uVar7 * 4 + param_6[2]);
              }
              else {
                puVar4 = (undefined4 *)FUN_001a7f7c(param_6,uVar7);
              }
              *puVar4 = uVar3;
              FUN_001a7f3c(param_4,uVar5);
              break;
            }
            uVar5 = uVar5 - 1;
            iVar8 = iVar8 + -4;
          } while (uVar5 != 0xffffffff);
        }
        goto LAB_00126fe9;
      }
    } while (param_4[1] == 0);
    uVar7 = param_4[1];
    uVar5 = uVar7 - 1;
    if (uVar5 < *param_4) {
      if (uVar7 <= uVar5) {
        _memset((void *)(param_4[2] + uVar7 * 4),0,(uVar5 - uVar7) * 4 + 4);
        param_4[1] = uVar7;
      }
      puVar4 = (undefined4 *)(param_4[2] + uVar5 * 4);
    }
    else {
      puVar4 = (undefined4 *)FUN_001a7f7c(param_4,uVar5);
    }
    uVar3 = *puVar4;
    uVar10 = ((int (*)())FUN_001251fc)();
    FUN_001a7f3c(param_4,uVar5);
    *(int *)(*(int *)(param_1 + 8) + 0x108) = *(int *)(*(int *)(param_1 + 8) + 0x108) + 1;
    piVar9 = (int *)FUN_000eac0c(param_2,0);
    cVar2 = (**(code **)(*piVar9 + 0x2c))(piVar9);
    if (cVar2 == '\0') {
LAB_00126f33:
      (**(code **)(*param_2 + 0x38))(param_2);
    }
    else {
      piVar9 = (int *)FUN_000eac7c(param_2,0);
      cVar2 = (**(code **)(*piVar9 + 0x34))(piVar9);
      if (cVar2 == '\0') goto LAB_00126f33;
    }
    ((int (*)())FUN_001263d2)(0,uVar10,param_2,*(undefined4 *)(param_1 + 8),1,param_5,uVar10);
    uVar5 = param_6[1];
    if (uVar5 < *param_6) {
      _memset((void *)(uVar5 * 4 + param_6[2]),0,4);
      param_6[1] = uVar5 + 1;
      puVar4 = (undefined4 *)(uVar5 * 4 + param_6[2]);
    }
    else {
      puVar4 = (undefined4 *)FUN_001a7f7c(param_6,uVar5);
    }
    *puVar4 = uVar3;
    *param_8 = *param_8 + 1;
  } while( true );
}

/* FUN_00127ac6 @ 0x127ac6 (824 bytes) */
int FUN_00127ac6(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int local_20 [4];
  
  iVar1 = FUN_000edd54(param_1);
  iVar2 = FUN_001a7d8a(param_1 + 0x370);
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
  *puVar3 = uVar4;
  puVar3[4] = uVar4;
  puVar3[2] = 0;
  puVar3[1] = 2;
  uVar4 = FUN_001a7bca(uVar4,8);
  puVar3[3] = uVar4;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
  *puVar5 = uVar4;
  puVar5[4] = uVar4;
  puVar5[2] = 0;
  puVar5[1] = 2;
  uVar4 = FUN_001a7bca(uVar4,8);
  puVar5[3] = uVar4;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar6 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
  *puVar6 = uVar4;
  puVar6[4] = uVar4;
  puVar6[2] = 0;
  puVar6[1] = 2;
  uVar4 = FUN_001a7bca(uVar4,8);
  puVar6[3] = uVar4;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar7 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
  *puVar7 = uVar4;
  puVar7[4] = uVar4;
  puVar7[2] = 0;
  puVar7[1] = 2;
  uVar4 = FUN_001a7bca(uVar4,8);
  puVar7[3] = uVar4;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar8 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
  *puVar8 = uVar4;
  puVar8[4] = uVar4;
  puVar8[2] = 0;
  puVar8[1] = 2;
  uVar4 = FUN_001a7bca(uVar4,8);
  puVar8[3] = uVar4;
  local_20[0] = 0;
  if (0 < iVar2) {
    iVar9 = 1;
    do {
      ((int (*)())FUN_00126aca)(param_1,*(undefined4 *)(iVar1 + iVar9 * 4),puVar3 + 1,puVar5 + 1,puVar6 + 1,
                   puVar7 + 1,puVar8 + 1,local_20);
      iVar9 = iVar9 + 1;
    } while (iVar9 <= iVar2);
  }
  if (puVar8 + 1 != (undefined4 *)0x0) {
    FUN_001a7aba(puVar8[4],puVar8[3]);
    FUN_001a7aba(*puVar8,puVar8);
  }
  if (puVar7 + 1 != (undefined4 *)0x0) {
    FUN_001a7aba(puVar7[4],puVar7[3]);
    FUN_001a7aba(*puVar7,puVar7);
  }
  if (puVar6 + 1 != (undefined4 *)0x0) {
    FUN_001a7aba(puVar6[4],puVar6[3]);
    FUN_001a7aba(*puVar6,puVar6);
  }
  if (puVar5 + 1 != (undefined4 *)0x0) {
    FUN_001a7aba(puVar5[4],puVar5[3]);
    FUN_001a7aba(*puVar5,puVar5);
  }
  if (puVar3 + 1 != (undefined4 *)0x0) {
    FUN_001a7aba(puVar3[4],puVar3[3]);
    FUN_001a7aba(*puVar3,puVar3);
  }
  if (local_20[0] != 0) {
    FUN_000e1c3e(*(undefined4 *)(param_1 + 8),
                 "SSA : Phi Replace -> %d added temps to break cycles\n",local_20[0]);
  }
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffb | 0x40;
  return;
}

/* FUN_00127e92 @ 0x127e92 (1209 bytes) */
int FUN_00127e92(param_1)
  int param_1;
{
  uint uVar1;
  undefined4 uVar2;
  bool bVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int local_78;
  int *local_6c;
  int local_68;
  int *local_64;
  uint local_5c;
  uint local_54;
  int *apiStack_44 [2];
  int local_3c [4];
  uint local_2c;
  uint local_28;
  int local_24;
  undefined4 local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  undefined4 local_10;
  int iVar9;
  
  local_10 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_18 = 0;
  local_1c = 2;
  local_14 = FUN_001a7bca(local_10,8);
  uVar1 = local_18;
  uVar2 = *(undefined4 *)(param_1 + 0x394);
  if (local_18 < local_1c) {
    iVar8 = local_18 * 4;
    _memset((void *)(local_14 + iVar8),0,4);
    local_18 = uVar1 + 1;
    puVar7 = (undefined4 *)(iVar8 + local_14);
  }
  else {
    puVar7 = (undefined4 *)FUN_001a7f7c(&local_1c,local_18);
  }
  *puVar7 = uVar2;
  local_78 = *(int *)(param_1 + 0x394);
  local_20 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_28 = 0;
  local_2c = 2;
  local_24 = FUN_001a7bca(local_20,8);
  do {
    piVar11 = *(int **)(local_78 + 0x98);
    for (piVar4 = (int *)(*(int **)(local_78 + 0x98))[2]; piVar4 != (int *)0x0;
        piVar4 = (int *)piVar4[2]) {
      if ((((*(int *)(piVar11[0x22] + 8) != 0x8e) &&
           (cVar6 = (**(code **)(*piVar11 + 0x68))(piVar11), cVar6 == '\0')) &&
          (cVar6 = FUN_00131f06(piVar11), cVar6 == '\0')) &&
         (((piVar11[0x21] != 0 && ((*(byte *)(piVar11 + 5) & 8) == 0)) &&
          (cVar6 = FUN_0010a320(piVar11), cVar6 == '\0')))) {
        piVar10 = (int *)piVar11[0x56];
        if (piVar11[0x21] < 1) {
          local_68 = 0;
        }
        else {
          local_68 = 0;
          do {
            local_68 = local_68 + 1;
            iVar8 = FUN_0010b180(piVar11,local_68);
            apiStack_44[local_68] = *(int **)(iVar8 + 0x158);
          } while (local_68 < piVar11[0x21]);
        }
        piVar5 = apiStack_44[1];
        local_28 = 0;
        local_6c = piVar10;
        if (piVar10 != (int *)0x0) {
          local_64 = piVar10;
          if (local_68 < 0) goto LAB_00128080;
          do {
            if (piVar10 == piVar5) {
              iVar8 = 0;
            }
            else {
              iVar9 = 0;
              do {
                iVar8 = iVar9 + 1;
                if (local_68 < iVar8) goto LAB_00128080;
                piVar12 = local_3c + iVar9;
                iVar9 = iVar8;
              } while (piVar10 != (int *)*piVar12);
            }
            local_6c = (int *)local_3c[iVar8 + -1];
            bVar3 = true;
            piVar12 = piVar10;
            while( true ) {
              cVar6 = (**(code **)(*piVar12 + 0x2c))(piVar12);
              if (cVar6 != '\0') {
                if (local_28 < local_2c) {
                  iVar8 = local_28 * 4;
                  *(undefined4 *)(iVar8 + local_24) = 0;
                  local_28 = local_28 + 1;
                  puVar7 = (undefined4 *)(iVar8 + local_24);
                }
                else {
                  puVar7 = (undefined4 *)FUN_001a7f7c(&local_2c,local_28);
                }
                *puVar7 = piVar12;
              }
              if ((bVar3) ||
                 (piVar10 = (int *)piVar12[0x3b], local_64 = piVar12, piVar10 == (int *)0x0))
              goto LAB_001281e3;
              if (-1 < local_68) break;
LAB_00128080:
              bVar3 = false;
              piVar12 = piVar10;
            }
          } while( true );
        }
        local_64 = (int *)0x0;
LAB_001281e3:
        cVar6 = (**(code **)(*local_6c + 0x2c))(local_6c);
        if (cVar6 == '\0') {
          local_64 = local_6c;
        }
        if (local_28 != 0) {
          local_5c = 0;
          do {
            if (local_5c < local_2c) {
              piVar10 = (int *)(local_24 + local_5c * 4);
            }
            else {
              piVar10 = (int *)FUN_001a7f7c(&local_2c,local_5c);
            }
            iVar8 = *(int *)(*piVar10 + 0x98);
            iVar9 = *(int *)(iVar8 + 8);
            while (iVar9 != 0) {
              if ((((*(byte *)(iVar8 + 0x14) & 1) != 0) &&
                  (*(int *)(*(int *)(iVar8 + 0x88) + 8) == 0x8e)) &&
                 (piVar10 = (int *)FUN_0010b180(iVar8,1), piVar11 == piVar10)) {
                bVar3 = false;
                goto LAB_00128250;
              }
              iVar8 = *(int *)(iVar8 + 8);
              iVar9 = *(int *)(iVar8 + 8);
            }
            bVar3 = true;
LAB_00128250:
            local_5c = local_5c + 1;
            if (!bVar3) goto LAB_00127f6a;
          } while (local_5c < local_28);
        }
        if ((local_64 != (int *)piVar11[0x56]) && (local_64[0x43] < *(int *)(piVar11[0x56] + 0x10c))
           ) {
          FUN_00109e26(piVar11);
          piVar11[5] = piVar11[5] | 1;
          FUN_000e9512(local_64,piVar11);
          piVar11 = (int *)(*(int *)(*(int *)(param_1 + 8) + 0x3f4) + 0x1b8);
          *piVar11 = *piVar11 + 1;
        }
      }
LAB_00127f6a:
      piVar11 = piVar4;
    }
    cVar6 = FUN_000e9802(local_78);
    if (cVar6 == '\0') {
      uVar1 = local_18 - 1;
      if (uVar1 < local_18) {
        piVar11 = (int *)(local_14 + uVar1 * 4);
      }
      else {
        piVar11 = (int *)0x0;
      }
      local_78 = *piVar11;
      FUN_001a7f3c(&local_1c,uVar1);
    }
    else {
      iVar8 = *(int *)(local_78 + 0xf0);
      if (*(uint *)(iVar8 + 4) == 0) {
        piVar11 = (int *)0x0;
      }
      else {
        piVar11 = *(int **)(iVar8 + 8);
      }
      local_78 = *piVar11;
      if (1 < *(uint *)(iVar8 + 4)) {
        local_54 = 1;
        do {
          while (uVar1 = local_18, uVar2 = *(undefined4 *)(*(int *)(iVar8 + 8) + local_54 * 4),
                local_1c <= local_18) {
            puVar7 = (undefined4 *)FUN_001a7f7c(&local_1c,local_18);
            *puVar7 = uVar2;
            local_54 = local_54 + 1;
            if (*(uint *)(iVar8 + 4) <= local_54) goto joined_r0x001281aa;
          }
          iVar9 = local_18 * 4;
          _memset((void *)(iVar9 + local_14),0,4);
          local_18 = uVar1 + 1;
          *(undefined4 *)(iVar9 + local_14) = uVar2;
          local_54 = local_54 + 1;
        } while (local_54 < *(uint *)(iVar8 + 4));
      }
    }
joined_r0x001281aa:
    if (local_18 == 0) {
      FUN_001a7aba(local_20,local_24);
      FUN_001a7aba(local_10,local_14);
      return;
    }
  } while( true );
}

/* FUN_0012837e @ 0x12837e (7573 bytes) */
int FUN_0012837e(param_1)
  int param_1;
{
  uint *puVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int *local_c8;
  int local_c4;
  uint *local_c0;
  uint *local_bc;
  uint *local_b8;
  uint local_70;
  uint local_64;
  int local_60;
  int *local_5c;
  int local_40;
  uint local_38;
  uint local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  undefined4 *local_20 [4];
  
  local_2c = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_34 = 0;
  local_38 = 2;
  local_30 = FUN_001a7bca(local_2c,8);
  uVar13 = local_34;
  uVar4 = *(undefined4 *)(param_1 + 0x394);
  if (local_34 < local_38) {
    iVar7 = local_34 * 4;
    _memset((void *)(local_30 + iVar7),0,4);
    local_34 = uVar13 + 1;
    puVar3 = (undefined4 *)(iVar7 + local_30);
  }
  else {
    puVar3 = (undefined4 *)FUN_001a7f7c(&local_38,local_34);
  }
  *puVar3 = uVar4;
  local_c8 = *(int **)(param_1 + 0x394);
  local_c8[0x2f] = 0;
  local_c8[0x43] = 0x10;
  *(int *)(param_1 + 0x468) = *(int *)(param_1 + 0x468) + 1;
  *(int *)(param_1 + 0x46c) = *(int *)(param_1 + 0x46c) + *(int *)(*(int *)(param_1 + 8) + 0x68) * 4
  ;
  *(undefined1 *)(param_1 + 0x334) = 0;
  cVar2 = FUN_000e1402(*(int *)(param_1 + 8),7);
  if (cVar2 != '\0') {
    iVar7 = *(int *)(param_1 + 8);
    uVar4 = *(undefined4 *)(iVar7 + 0xbc);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
    *puVar3 = uVar4;
    puVar3[4] = uVar4;
    puVar3[2] = 0;
    puVar3[1] = 2;
    uVar4 = FUN_001a7bca(uVar4,8);
    puVar3[3] = uVar4;
    *(undefined4 **)(iVar7 + 0x11c) = puVar3 + 1;
    iVar7 = *(int *)(param_1 + 8);
    uVar4 = *(undefined4 *)(iVar7 + 0xbc);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
    *puVar3 = uVar4;
    puVar3[4] = uVar4;
    puVar3[2] = 0;
    puVar3[1] = 2;
    uVar4 = FUN_001a7bca(uVar4,8);
    puVar3[3] = uVar4;
    *(undefined4 **)(iVar7 + 0x120) = puVar3 + 1;
    iVar7 = *(int *)(param_1 + 8);
    uVar4 = *(undefined4 *)(iVar7 + 0xbc);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x1c);
    *puVar3 = uVar4;
    puVar1 = puVar3 + 1;
    puVar3[4] = PTR_FUN_002139b1;
    puVar3[5] = PTR_FUN_00213991;
    puVar3[6] = uVar4;
    puVar3[1] = 1;
    iVar5 = 0;
    uVar13 = 1;
    do {
      uVar13 = uVar13 * 2;
      if (0x3ff < uVar13) break;
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0x20);
    *puVar1 = uVar13;
    puVar3[2] = 0;
    pvVar6 = (void *)FUN_001a7bca(uVar4,*puVar1 << 2);
    puVar3[3] = pvVar6;
    _memset(pvVar6,0,*puVar1 << 2);
    *(uint **)(iVar7 + 0x124) = puVar1;
    iVar7 = *(int *)(param_1 + 8);
    uVar4 = *(undefined4 *)(iVar7 + 0xbc);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x1c);
    *puVar3 = uVar4;
    puVar1 = puVar3 + 1;
    puVar3[4] = PTR_FUN_00213989;
    puVar3[5] = PTR_FUN_002139b5;
    puVar3[6] = uVar4;
    puVar3[1] = 1;
    uVar13 = 1;
    iVar5 = 0x20;
    do {
      uVar13 = uVar13 * 2;
      if (0x3ff < uVar13) break;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    *puVar1 = uVar13;
    puVar3[2] = 0;
    pvVar6 = (void *)FUN_001a7bca(uVar4,*puVar1 << 2);
    puVar3[3] = pvVar6;
    _memset(pvVar6,0,*puVar1 << 2);
    *(uint **)(iVar7 + 0x128) = puVar1;
    iVar7 = *(int *)(param_1 + 8);
    uVar4 = *(undefined4 *)(iVar7 + 0xbc);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x1c);
    *puVar3 = uVar4;
    puVar1 = puVar3 + 1;
    puVar3[4] = PTR_FUN_002139a5;
    puVar3[5] = PTR_FUN_002139a1;
    puVar3[6] = uVar4;
    puVar3[1] = 1;
    uVar13 = 1;
    iVar5 = 0x20;
    do {
      uVar13 = uVar13 * 2;
      if (0x3ff < uVar13) break;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    *puVar1 = uVar13;
    puVar3[2] = 0;
    pvVar6 = (void *)FUN_001a7bca(uVar4,*puVar1 << 2);
    puVar3[3] = pvVar6;
    _memset(pvVar6,0,*puVar1 << 2);
    *(uint **)(iVar7 + 300) = puVar1;
    iVar7 = *(int *)(param_1 + 8);
    uVar4 = *(undefined4 *)(iVar7 + 0xbc);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x1c);
    *puVar3 = uVar4;
    puVar1 = puVar3 + 1;
    puVar3[4] = PTR_FUN_00213999;
    puVar3[5] = PTR_FUN_002139ad;
    puVar3[6] = uVar4;
    puVar3[1] = 1;
    uVar13 = 1;
    iVar5 = 0x20;
    do {
      uVar13 = uVar13 * 2;
      if (0x3ff < uVar13) break;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    *puVar1 = uVar13;
    puVar3[2] = 0;
    pvVar6 = (void *)FUN_001a7bca(uVar4,*puVar1 << 2);
    puVar3[3] = pvVar6;
    _memset(pvVar6,0,*puVar1 << 2);
    *(uint **)(iVar7 + 0x130) = puVar1;
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x2c);
    *puVar3 = uVar4;
    iVar7 = *(int *)(param_1 + 8);
    puVar3[1] = 0x7ffffffe;
    puVar3[2] = 0;
    *(undefined1 *)(puVar3 + 3) = 0;
    *(undefined1 *)((int)puVar3 + 0xd) = 0;
    puVar3[4] = 0;
    puVar3[5] = 4;
    *(undefined1 *)(puVar3 + 7) = 0;
    puVar3[8] = 0;
    *(undefined4 **)(iVar7 + 0x134) = puVar3 + 1;
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x34);
    *puVar3 = uVar4;
    iVar7 = *(int *)(param_1 + 8);
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0xffffffff;
    puVar3[4] = 0;
    puVar3[5] = 0;
    *(undefined1 *)(puVar3 + 6) = 0;
    puVar3[7] = 0;
    puVar3[8] = 0;
    *(undefined1 *)(puVar3 + 9) = 0;
    puVar3[10] = 0;
    *(undefined1 *)(puVar3 + 0xb) = 0;
    puVar3[0xc] = 0;
    *(undefined4 **)(iVar7 + 0x138) = puVar3 + 1;
    piVar11 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    (**(code **)(*piVar11 + 0x124))(piVar11,*(int *)(param_1 + 8));
    piVar11 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    (**(code **)(*piVar11 + 0x128))(piVar11,*(int *)(param_1 + 8));
    FUN_00186ad8(*(undefined4 *)(param_1 + 8));
    FUN_00186ade(*(undefined4 *)(param_1 + 8));
  }
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
  *puVar3 = uVar4;
  puVar3[4] = uVar4;
  puVar3[2] = 0;
  puVar3[1] = 2;
  uVar4 = FUN_001a7bca(uVar4,8);
  puVar3[3] = uVar4;
  *(undefined4 **)(param_1 + 0x3f8) = puVar3 + 1;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
  *puVar3 = uVar4;
  puVar3[4] = uVar4;
  puVar3[2] = 0;
  puVar3[1] = 2;
  uVar4 = FUN_001a7bca(uVar4,8);
  puVar3[3] = uVar4;
  *(undefined4 **)(param_1 + 0x3fc) = puVar3 + 1;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
  *puVar3 = uVar4;
  puVar3[4] = uVar4;
  puVar3[2] = 0;
  puVar3[1] = 2;
  uVar4 = FUN_001a7bca(uVar4,8);
  puVar3[3] = uVar4;
  *(undefined4 **)(param_1 + 0x400) = puVar3 + 1;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
  *puVar3 = uVar4;
  puVar3[4] = uVar4;
  puVar3[2] = 0;
  puVar3[1] = 2;
  uVar4 = FUN_001a7bca(uVar4,8);
  puVar3[3] = uVar4;
  *(undefined4 **)(param_1 + 0x404) = puVar3 + 1;
  piVar11 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  cVar2 = (**(code **)(*piVar11 + 0xc0))(piVar11);
  if (cVar2 != '\0') {
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
    *puVar3 = uVar4;
    puVar3[4] = uVar4;
    puVar3[2] = 0;
    puVar3[1] = 2;
    uVar4 = FUN_001a7bca(uVar4,8);
    puVar3[3] = uVar4;
    *(undefined4 **)(param_1 + 0x410) = puVar3 + 1;
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
    *puVar3 = uVar4;
    puVar3[4] = uVar4;
    puVar3[2] = 0;
    puVar3[1] = 2;
    uVar4 = FUN_001a7bca(uVar4,8);
    puVar3[3] = uVar4;
    *(undefined4 **)(param_1 + 0x414) = puVar3 + 1;
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
    *puVar3 = uVar4;
    puVar3[4] = uVar4;
    puVar3[2] = 0;
    puVar3[1] = 2;
    uVar4 = FUN_001a7bca(uVar4,8);
    puVar3[3] = uVar4;
    *(undefined4 **)(param_1 + 0x418) = puVar3 + 1;
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
    *puVar3 = uVar4;
    puVar3[4] = uVar4;
    puVar3[2] = 0;
    puVar3[1] = 2;
    uVar4 = FUN_001a7bca(uVar4,8);
    puVar3[3] = uVar4;
    *(undefined4 **)(param_1 + 0x40c) = puVar3 + 1;
  }
  local_c4 = -1;
  local_c0 = (uint *)0x0;
  local_bc = (uint *)0x0;
  local_b8 = (uint *)0x0;
  do {
    if (local_c8[0x3b] != 0) {
      local_c8[0x2f] = *(int *)(local_c8[0x3b] + 0xbc) + 1;
    }
    cVar2 = FUN_000e1402(*(undefined4 *)(param_1 + 8),7);
    if (cVar2 != '\0') {
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
      puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x1c);
      *puVar3 = uVar4;
      local_c0 = puVar3 + 1;
      puVar3[4] = PTR_FUN_002139a9;
      puVar3[5] = PTR_FUN_002139bd;
      puVar3[6] = uVar4;
      puVar3[1] = 1;
      iVar7 = 0;
      uVar13 = 1;
      do {
        uVar13 = uVar13 * 2;
        if (0xff < uVar13) {
          *local_c0 = uVar13;
          goto LAB_001295e9;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 != 0x20);
      *local_c0 = uVar13;
LAB_001295e9:
      puVar3[2] = 0;
      pvVar6 = (void *)FUN_001a7bca(uVar4,*local_c0 << 2);
      puVar3[3] = pvVar6;
      _memset(pvVar6,0,*local_c0 << 2);
      puVar1 = *(uint **)(param_1 + 0x3f8);
      uVar13 = puVar1[1];
      if (uVar13 < *puVar1) {
        _memset((void *)(uVar13 * 4 + puVar1[2]),0,4);
        puVar1[1] = uVar13 + 1;
        piVar11 = (int *)(uVar13 * 4 + puVar1[2]);
      }
      else {
        piVar11 = (int *)FUN_001a7f7c(puVar1,uVar13);
      }
      *piVar11 = (int)local_c0;
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
      puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x1c);
      *puVar3 = uVar4;
      local_bc = puVar3 + 1;
      puVar3[4] = PTR_FUN_002139b9;
      puVar3[5] = PTR_FUN_0021398d;
      puVar3[6] = uVar4;
      puVar3[1] = 1;
      uVar13 = 1;
      iVar7 = 0x20;
      do {
        uVar13 = uVar13 * 2;
        if (0xff < uVar13) {
          *local_bc = uVar13;
          goto LAB_001296f8;
        }
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      *local_bc = uVar13;
LAB_001296f8:
      puVar3[2] = 0;
      pvVar6 = (void *)FUN_001a7bca(uVar4,*local_bc << 2);
      puVar3[3] = pvVar6;
      _memset(pvVar6,0,*local_bc << 2);
      puVar1 = *(uint **)(param_1 + 0x3fc);
      uVar13 = puVar1[1];
      if (uVar13 < *puVar1) {
        _memset((void *)(uVar13 * 4 + puVar1[2]),0,4);
        puVar1[1] = uVar13 + 1;
        piVar11 = (int *)(uVar13 * 4 + puVar1[2]);
      }
      else {
        piVar11 = (int *)FUN_001a7f7c(puVar1,uVar13);
      }
      *piVar11 = (int)local_bc;
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
      puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x1c);
      *puVar3 = uVar4;
      local_b8 = puVar3 + 1;
      puVar3[4] = PTR_FUN_00213995;
      puVar3[5] = PTR_FUN_0021399d;
      puVar3[6] = uVar4;
      puVar3[1] = 1;
      iVar7 = 0;
      uVar13 = 1;
      do {
        uVar13 = uVar13 * 2;
        if (0xff < uVar13) {
          *local_b8 = uVar13;
          goto LAB_00129807;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 != 0x20);
      *local_b8 = uVar13;
LAB_00129807:
      puVar3[2] = 0;
      pvVar6 = (void *)FUN_001a7bca(uVar4,*local_b8 << 2);
      puVar3[3] = pvVar6;
      _memset(pvVar6,0,*local_b8 << 2);
      puVar1 = *(uint **)(param_1 + 0x400);
      uVar13 = puVar1[1];
      if (uVar13 < *puVar1) {
        _memset((void *)(uVar13 * 4 + puVar1[2]),0,4);
        puVar1[1] = uVar13 + 1;
        piVar11 = (int *)(uVar13 * 4 + puVar1[2]);
      }
      else {
        piVar11 = (int *)FUN_001a7f7c(puVar1,uVar13);
      }
      *piVar11 = (int)local_b8;
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
      puVar10 = (undefined4 *)FUN_001a7bca(uVar4,0x20c);
      *puVar10 = uVar4;
      puVar10[2] = 0x1000;
      puVar10[1] = 0x80;
      uVar13 = 0;
      puVar3 = puVar10 + 1;
      do {
        puVar3[2] = 0;
        uVar13 = uVar13 + 1;
        puVar3 = puVar3 + 1;
      } while (uVar13 < 0x80);
      local_c8[0x48] = (int)(puVar10 + 1);
      puVar1 = *(uint **)(param_1 + 0x404);
      uVar13 = puVar1[1];
      if (uVar13 < *puVar1) {
        _memset((void *)(uVar13 * 4 + puVar1[2]),0,4);
        puVar1[1] = uVar13 + 1;
        puVar3 = (undefined4 *)(uVar13 * 4 + puVar1[2]);
      }
      else {
        puVar3 = (undefined4 *)FUN_001a7f7c(puVar1,uVar13);
      }
      *puVar3 = local_c8;
      local_c4 = local_c4 + 1;
    }
    piVar11 = (int *)local_c8[0x26];
    if (piVar11[2] != 0) {
LAB_00128a63:
      if ((*(byte *)(piVar11 + 5) & 1) == 0) break;
      cVar2 = FUN_000e1402(*(undefined4 *)(param_1 + 8),7);
      if (cVar2 != '\0') {
        local_c8[0x45] = (int)local_c0;
        local_c8[0x46] = (int)local_bc;
        local_c8[0x47] = (int)local_b8;
      }
      cVar2 = (**(code **)(*piVar11 + 0x34))(piVar11);
      if ((cVar2 != '\0') || (cVar2 = (**(code **)(*piVar11 + 0x38))(piVar11), cVar2 != '\0'))
      break;
      cVar2 = (**(code **)(*piVar11 + 0x28))(piVar11);
      if (cVar2 != '\0') {
        *(uint *)(piVar11[0x56] + 0xc) = *(uint *)(piVar11[0x56] + 0xc) | 1;
        *(uint *)(piVar11[0x56] + 0xc) = *(uint *)(piVar11[0x56] + 0xc) | 2;
      }
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
      puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x240);
      *puVar3 = uVar4;
      puVar3 = puVar3 + 1;
      FUN_00183c52(puVar3,piVar11,*(undefined4 *)(param_1 + 8));
      piVar8 = (int *)piVar11[0x23];
      local_20[0] = puVar3;
      if (piVar8 != (int *)0x0) {
        iVar7 = piVar11[0x26];
        cVar2 = FUN_0012dfd8(iVar7);
        if (cVar2 != '\0') {
          if ((*(byte *)(piVar8 + 9) & 2) == 0) {
            cVar2 = (**(code **)(*piVar8 + 0x18))(piVar8);
            if (cVar2 != '\0') {
              piVar11[0x25] = piVar11[0x53];
              piVar11[0x26] = 0;
            }
          }
          else {
            piVar11[0x25] = piVar8[4];
            piVar11[0x26] = 0;
            piVar11[5] = piVar11[5] | 0x40;
          }
        }
        if (iVar7 == 0x21) {
          *(uint *)(piVar11[0x56] + 0xc) = *(uint *)(piVar11[0x56] + 0xc) | 4;
        }
        else if (iVar7 == 0x30) {
          *(uint *)(piVar11[0x56] + 0xc) = *(uint *)(piVar11[0x56] + 0xc) | 0x10;
        }
      }
      puVar3 = local_20;
      if (*(int *)(piVar11[0x22] + 8) == 0x8e) {
        iVar7 = (**(code **)(*piVar11 + 0x7c))(piVar11);
        *(undefined4 **)(iVar7 + 0x130) = puVar3;
        piVar11[0x54] = *(int *)(param_1 + 0x468);
        cVar2 = FUN_000e1402(*(undefined4 *)(param_1 + 8),7);
        if ((cVar2 == '\0') ||
           (*(int *)(*(int *)(param_1 + 8) + 0x388) <= *(int *)(param_1 + 0x14c))) {
LAB_00128c6c:
          if (piVar11[0x20] < 1) {
            iVar7 = piVar11[0x20];
          }
          else {
            local_40 = 0;
            piVar8 = piVar11;
            do {
              FUN_000eb51a(local_c8,piVar8[0x23],local_20[0]);
              local_40 = local_40 + 1;
              piVar8 = piVar8 + 6;
            } while (local_40 < piVar11[0x20]);
            iVar7 = piVar11[0x20];
          }
          if (((iVar7 != 0) && (cVar2 = FUN_0012dfd8(piVar11[0x26]), cVar2 != '\0')) &&
             (((*(byte *)(piVar11 + 5) & 2) == 0 &&
              ((cVar2 = (**(code **)(*piVar11 + 0x50))(piVar11), cVar2 == '\0' &&
               ((*(byte *)(piVar11 + 5) & 0x40) == 0)))))) {
            iVar7 = piVar11[0x53];
            iVar5 = FUN_0010b0f4(piVar11,0);
            *(int *)(iVar5 + 8) = iVar7;
          }
        }
        else {
          uVar4 = (**(code **)(*piVar11 + 0x7c))(piVar11);
          cVar2 = ((int (*)())FUN_001252b2)(uVar4);
          if (cVar2 == '\0') {
            cVar2 = FUN_00186556(param_1,local_c4,local_c4,local_20,local_c8);
            if (cVar2 == '\0') goto LAB_00128c6c;
          }
          else {
            iVar7 = FUN_0010b180(piVar11,1);
            puVar1 = *(uint **)(*(int *)(iVar7 + 0x8c) + 0x2c);
            uVar14 = puVar1[1];
            uVar13 = uVar14 - 1;
            if (uVar13 < *puVar1) {
              if (uVar14 <= uVar13) {
                _memset((void *)(puVar1[2] + uVar14 * 4),0,(uVar13 - uVar14) * 4 + 4);
                puVar1[1] = uVar14;
              }
              puVar3 = (undefined4 *)(puVar1[2] + uVar13 * 4);
            }
            else {
              puVar3 = (undefined4 *)FUN_001a7f7c(puVar1,uVar13);
            }
            FUN_000eb51a(local_c8,piVar11[0x23],*puVar3);
            (**(code **)(*piVar11 + 0xc))(piVar11,0,*(undefined4 *)(param_1 + 8));
            piVar11[5] = piVar11[5] | 0x400;
            *(int *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + 1;
          }
        }
        break;
      }
      cVar2 = ((int (*)())FUN_00125e68)(param_1,piVar11,local_c8);
      if (cVar2 != '\0') break;
      ((int (*)())FUN_0012540a)(local_20[0],*(undefined4 *)(param_1 + 0x394));
      ((int (*)())FUN_00125948)(local_20[0],param_1);
      cVar2 = FUN_00186556(param_1,local_c4,0,local_20,local_c8);
      if (cVar2 != '\0') break;
      piVar8 = *(int **)(*(int *)(param_1 + 8) + 0x54);
      cVar2 = (**(code **)(*piVar8 + 0xc0))(piVar8);
      if (cVar2 != '\0') {
        FUN_00115426(param_1,local_20[0]);
      }
      cVar2 = FUN_000e1402(*(undefined4 *)(param_1 + 8),7);
      if ((((cVar2 == '\0') || (cVar2 = FUN_000e1402(*(undefined4 *)(param_1 + 8),9), cVar2 == '\0')
           ) || (cVar2 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0xd), cVar2 == '\0')) ||
         ((cVar2 = (**(code **)(*local_c8 + 0x24))(local_c8), cVar2 == '\0' || (local_c8[0x50] == 0)
          ))) {
        if (0 < piVar11[0x21]) {
          iVar7 = 1;
          local_5c = piVar11;
          do {
            FUN_0010ba02(piVar11,iVar7,local_20[0][iVar7 + 0x84],0,*(undefined4 *)(param_1 + 8));
            iVar5 = FUN_0010b0f4(piVar11,iVar7);
            *(undefined4 *)(iVar5 + 8) = 0xffffffff;
            *(undefined4 *)(iVar5 + 0xc) = 0x46;
            local_5c[0x29] = 0;
            cVar2 = (**(code **)(*(int *)local_20[0][iVar7 + 0x84] + 0x74))
                              ((int *)local_20[0][iVar7 + 0x84]);
            if (cVar2 != '\0') {
              *(undefined1 *)(param_1 + 0x334) = 1;
            }
            iVar7 = iVar7 + 1;
            local_5c = local_5c + 6;
          } while (iVar7 <= piVar11[0x21]);
        }
        goto LAB_00128c6c;
      }
      iVar7 = local_c8[0x4d];
      piVar11 = (int *)FUN_000e9b0e(local_c8);
      iVar5 = FUN_000e9b7c(iVar7);
      FUN_00133a48(param_1,local_c8,iVar7,&local_24,&local_28);
      FUN_000e981c(local_c8);
      if (local_bc != (uint *)0x0) {
        if (*local_bc == 0) {
          uVar13 = local_bc[2];
        }
        else {
          uVar14 = 0;
          uVar13 = local_bc[2];
          do {
            iVar7 = *(int *)(uVar13 + uVar14 * 4);
            if (iVar7 != 0) {
              FUN_001a7aba(local_bc[5],iVar7);
              uVar13 = local_bc[2];
            }
            uVar14 = uVar14 + 1;
          } while (uVar14 < *local_bc);
        }
        FUN_001a7aba(local_bc[5],uVar13);
        if (local_bc != (uint *)0x0) {
          FUN_001a7aba(local_bc[-1],local_bc + -1);
        }
      }
      local_c8[0x46] = 0;
      if (local_b8 != (uint *)0x0) {
        if (*local_b8 == 0) {
          uVar13 = local_b8[2];
        }
        else {
          uVar14 = 0;
          uVar13 = local_b8[2];
          do {
            iVar7 = *(int *)(uVar13 + uVar14 * 4);
            if (iVar7 != 0) {
              FUN_001a7aba(local_b8[5],iVar7);
              uVar13 = local_b8[2];
            }
            uVar14 = uVar14 + 1;
          } while (uVar14 < *local_b8);
        }
        FUN_001a7aba(local_b8[5],uVar13);
        if (local_b8 != (uint *)0x0) {
          FUN_001a7aba(local_b8[-1],local_b8 + -1);
        }
      }
      local_c8[0x47] = 0;
      if (local_c0 != (uint *)0x0) {
        if (*local_c0 == 0) {
          uVar13 = local_c0[2];
        }
        else {
          uVar14 = 0;
          uVar13 = local_c0[2];
          do {
            iVar7 = *(int *)(uVar13 + uVar14 * 4);
            if (iVar7 != 0) {
              FUN_001a7aba(local_c0[5],iVar7);
              uVar13 = local_c0[2];
            }
            uVar14 = uVar14 + 1;
          } while (uVar14 < *local_c0);
        }
        FUN_001a7aba(local_c0[5],uVar13);
        if (local_c0 != (uint *)0x0) {
          FUN_001a7aba(local_c0[-1],local_c0 + -1);
        }
      }
      local_c8[0x45] = 0;
      FUN_001a7f3c(*(undefined4 *)(param_1 + 0x3f8),local_c4);
      FUN_001a7f3c(*(undefined4 *)(param_1 + 0x3fc),local_c4);
      FUN_001a7f3c(*(undefined4 *)(param_1 + 0x400),local_c4);
      FUN_001a7f3c(*(undefined4 *)(param_1 + 0x404),local_c4);
      local_c4 = local_c4 + -1;
      *(int **)(local_24 + 0xec) = piVar11;
      piVar8 = (int *)piVar11[0x3c];
      if (*piVar8 == 0) {
        piVar8 = (int *)FUN_001a7f7c(piVar8,0);
      }
      else {
        if (piVar8[1] == 0) {
          *(undefined4 *)piVar8[2] = 0;
          piVar8[1] = 1;
        }
        piVar8 = (int *)piVar8[2];
      }
      *piVar8 = local_24;
      piVar8 = *(int **)(local_28 + 0xf0);
      if (*piVar8 == 0) {
        piVar8 = (int *)FUN_001a7f7c(piVar8,0);
      }
      else {
        if (piVar8[1] == 0) {
          *(undefined4 *)piVar8[2] = 0;
          piVar8[1] = 1;
        }
        piVar8 = (int *)piVar8[2];
      }
      *piVar8 = iVar5;
      *(int *)(iVar5 + 0xec) = local_28;
      local_c8 = piVar11;
    }
LAB_00128e0c:
    local_28 = 0;
    local_64 = 1;
    local_60 = 0;
    iVar7 = local_c8[0x34];
    if (*(int *)(iVar7 + 4) != 0) {
      do {
        local_28 = *(int *)(local_60 + *(int *)(iVar7 + 8));
        if (local_28 != 0) {
          iVar7 = FUN_000e9c92(local_28,local_c8);
          piVar11 = *(int **)(local_28 + 0x98);
          if (piVar11[2] != 0) {
            do {
              if (((*(byte *)(piVar11 + 5) & 1) != 0) &&
                 (piVar8 = (int *)(**(code **)(*piVar11 + 0x7c))(piVar11), piVar8 != (int *)0x0)) {
                iVar9 = ((int (*)())FUN_0012a37e)(piVar8[0x23],*(undefined4 *)(param_1 + 0x394),
                                     *(undefined4 *)(param_1 + 8));
                FUN_0010ba02(piVar8,iVar7,*(undefined4 *)(iVar9 + 0xb0),0,
                             *(undefined4 *)(param_1 + 8));
                iVar5 = piVar8[0x4e];
                iVar12 = 0;
                do {
                  *(undefined4 *)(iVar12 + *(int *)(iVar7 * 4 + iVar5)) =
                       *(undefined4 *)(iVar12 + iVar9 + 0x20);
                  iVar12 = iVar12 + 4;
                } while (iVar12 != 0x10);
                if ((((piVar8[0x20] != 0) && (cVar2 = FUN_0012dfd8(piVar8[0x26]), cVar2 != '\0')) &&
                    ((*(byte *)(piVar8 + 5) & 2) == 0)) &&
                   ((cVar2 = (**(code **)(*piVar8 + 0x50))(piVar8), cVar2 == '\0' &&
                    ((*(byte *)(piVar8 + 5) & 0x40) == 0)))) {
                  iVar5 = piVar8[0x53];
                  iVar9 = FUN_0010b0f4(piVar8,0);
                  *(int *)(iVar9 + 8) = iVar5;
                }
              }
              piVar11 = (int *)piVar11[2];
            } while (piVar11[2] != 0);
          }
        }
        local_64 = local_64 + 1;
        local_60 = local_60 + 4;
        iVar7 = local_c8[0x34];
      } while (local_64 <= *(uint *)(iVar7 + 4));
    }
    cVar2 = FUN_000e9802(local_c8);
    if (cVar2 == '\0') {
      FUN_000e981c(local_c8);
      cVar2 = FUN_000e1402(*(undefined4 *)(param_1 + 8),7);
      if (cVar2 != '\0') {
        if (local_b8 != (uint *)0x0) {
          if (*local_b8 == 0) {
            uVar13 = local_b8[2];
          }
          else {
            uVar14 = 0;
            uVar13 = local_b8[2];
            do {
              iVar7 = *(int *)(uVar13 + uVar14 * 4);
              if (iVar7 != 0) {
                FUN_001a7aba(local_b8[5],iVar7);
                uVar13 = local_b8[2];
              }
              uVar14 = uVar14 + 1;
            } while (uVar14 < *local_b8);
          }
          FUN_001a7aba(local_b8[5],uVar13);
          if (local_b8 != (uint *)0x0) {
            FUN_001a7aba(local_b8[-1],local_b8 + -1);
          }
        }
        local_c8[0x47] = 0;
        if (local_bc != (uint *)0x0) {
          if (*local_bc == 0) {
            uVar13 = local_bc[2];
          }
          else {
            uVar14 = 0;
            uVar13 = local_bc[2];
            do {
              iVar7 = *(int *)(uVar13 + uVar14 * 4);
              if (iVar7 != 0) {
                FUN_001a7aba(local_bc[5],iVar7);
                uVar13 = local_bc[2];
              }
              uVar14 = uVar14 + 1;
            } while (uVar14 < *local_bc);
          }
          FUN_001a7aba(local_bc[5],uVar13);
          if (local_bc != (uint *)0x0) {
            FUN_001a7aba(local_bc[-1],local_bc + -1);
          }
        }
        local_c8[0x46] = 0;
        if (local_c0 != (uint *)0x0) {
          if (*local_c0 == 0) {
            uVar13 = local_c0[2];
          }
          else {
            uVar14 = 0;
            uVar13 = local_c0[2];
            do {
              iVar7 = *(int *)(uVar13 + uVar14 * 4);
              if (iVar7 != 0) {
                FUN_001a7aba(local_c0[5],iVar7);
                uVar13 = local_c0[2];
              }
              uVar14 = uVar14 + 1;
            } while (uVar14 < *local_c0);
          }
          FUN_001a7aba(local_c0[5],uVar13);
          if (local_c0 != (uint *)0x0) {
            FUN_001a7aba(local_c0[-1],local_c0 + -1);
          }
        }
        local_c8[0x45] = 0;
        FUN_001a7f3c(*(undefined4 *)(param_1 + 0x3f8),local_c4);
        FUN_001a7f3c(*(undefined4 *)(param_1 + 0x3fc),local_c4);
        FUN_001a7f3c(*(undefined4 *)(param_1 + 0x400),local_c4);
        FUN_001a7f3c(*(undefined4 *)(param_1 + 0x404),local_c4);
        local_c4 = local_c4 + -1;
      }
      iVar7 = local_c8[0x3b];
      uVar13 = local_34 - 1;
      if (uVar13 < local_34) {
        local_c8 = (int *)(local_30 + uVar13 * 4);
      }
      else {
        local_c8 = (int *)0x0;
      }
      local_c8 = (int *)*local_c8;
      FUN_001a7f3c(&local_38,uVar13);
      if ((iVar7 != 0) && (iVar7 != local_c8[0x3b])) {
        do {
          FUN_000e981c(iVar7);
          iVar7 = *(int *)(iVar7 + 0xec);
          cVar2 = FUN_000e1402(*(undefined4 *)(param_1 + 8),7);
          if (cVar2 != '\0') {
            FUN_001a7f3c(*(undefined4 *)(param_1 + 0x3f8),local_c4);
            FUN_001a7f3c(*(undefined4 *)(param_1 + 0x3fc),local_c4);
            FUN_001a7f3c(*(undefined4 *)(param_1 + 0x400),local_c4);
            FUN_001a7f3c(*(undefined4 *)(param_1 + 0x404),local_c4);
            local_c4 = local_c4 + -1;
          }
        } while ((iVar7 != 0) && (iVar7 != local_c8[0x3b]));
      }
    }
    else {
      iVar7 = local_c8[0x3c];
      if (*(uint *)(iVar7 + 4) == 0) {
        local_c8 = (int *)0x0;
      }
      else {
        local_c8 = *(int **)(iVar7 + 8);
      }
      local_c8 = (int *)*local_c8;
      if (1 < *(uint *)(iVar7 + 4)) {
        local_70 = 1;
        do {
          while (uVar13 = local_34, uVar4 = *(undefined4 *)(*(int *)(iVar7 + 8) + local_70 * 4),
                local_34 < local_38) {
            iVar5 = local_34 * 4;
            _memset((void *)(iVar5 + local_30),0,4);
            local_34 = uVar13 + 1;
            *(undefined4 *)(iVar5 + local_30) = uVar4;
            local_70 = local_70 + 1;
            if (*(uint *)(iVar7 + 4) <= local_70) goto LAB_0012908c;
          }
          puVar3 = (undefined4 *)FUN_001a7f7c(&local_38,local_34);
          *puVar3 = uVar4;
          local_70 = local_70 + 1;
        } while (local_70 < *(uint *)(iVar7 + 4));
      }
    }
LAB_0012908c:
    if (local_34 == 0) {
      piVar11 = *(int **)(*(int *)(param_1 + 8) + 0x54);
      cVar2 = (**(code **)(*piVar11 + 0xc0))(piVar11);
      if (cVar2 != '\0') {
        FUN_00114c42(param_1,2,*(undefined4 *)(param_1 + 0x414));
        cVar2 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x3f);
        if (cVar2 != '\0') {
          FUN_001157ce(param_1,1,*(undefined4 *)(param_1 + 0x410));
          piVar11 = *(int **)(*(int *)(param_1 + 8) + 0x54);
          cVar2 = (**(code **)(*piVar11 + 200))(piVar11);
          if (cVar2 != '\0') {
            FUN_001157ce(param_1,2,*(undefined4 *)(param_1 + 0x414));
          }
        }
      }
      iVar7 = *(int *)(param_1 + 0x3f8);
      if (iVar7 != 0) {
        FUN_001a7aba(*(undefined4 *)(iVar7 + 0xc),*(undefined4 *)(iVar7 + 8));
        FUN_001a7aba(*(undefined4 *)(iVar7 + -4),iVar7 + -4);
      }
      iVar7 = *(int *)(param_1 + 0x3fc);
      if (iVar7 != 0) {
        FUN_001a7aba(*(undefined4 *)(iVar7 + 0xc),*(undefined4 *)(iVar7 + 8));
        FUN_001a7aba(*(undefined4 *)(iVar7 + -4),iVar7 + -4);
      }
      iVar7 = *(int *)(param_1 + 0x400);
      if (iVar7 != 0) {
        FUN_001a7aba(*(undefined4 *)(iVar7 + 0xc),*(undefined4 *)(iVar7 + 8));
        FUN_001a7aba(*(undefined4 *)(iVar7 + -4),iVar7 + -4);
      }
      iVar7 = *(int *)(param_1 + 0x404);
      if (iVar7 != 0) {
        FUN_001a7aba(*(undefined4 *)(iVar7 + 0xc),*(undefined4 *)(iVar7 + 8));
        FUN_001a7aba(*(undefined4 *)(iVar7 + -4),iVar7 + -4);
      }
      FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xbc),
                   *(undefined4 *)(*(int *)(param_1 + 8) + 0x11c));
      cVar2 = FUN_000e1402(*(undefined4 *)(param_1 + 8),7);
      if ((cVar2 != '\0') && (cVar2 = FUN_000e1402(*(undefined4 *)(param_1 + 8),9), cVar2 != '\0'))
      {
        FUN_001833da(*(undefined4 *)(param_1 + 8));
        FUN_001833e0(*(undefined4 *)(param_1 + 8));
      }
      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0xc;
      FUN_000f0346(param_1,"ssa_build");
      FUN_001a7aba(local_2c,local_30);
      return;
    }
  } while( true );
  piVar11 = (int *)piVar11[2];
  if (piVar11[2] == 0) goto LAB_00128e0c;
  goto LAB_00128a63;
}

/* FUN_0012a21c @ 0x12a21c (137 bytes) */
int FUN_0012a21c(param_1)
  int param_1;
{
  uint uVar1;
  char cVar2;
  uint *puVar3;
  uint uVar4;
  
  FUN_001325a8(param_1);
  FUN_000fb140(param_1);
  ((int (*)())FUN_00125540)(param_1);
  ((int (*)())FUN_0012837e)(param_1);
  cVar2 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0xe);
  if (cVar2 != '\0') {
    ((int (*)())FUN_001260ca)(param_1);
    ((int (*)())FUN_00127e92)(param_1);
  }
  FUN_000ee14e(param_1);
  puVar3 = *(uint **)(param_1 + 0x3a4);
  if (*puVar3 != 0) {
    uVar4 = 0;
    uVar1 = *puVar3;
    do {
      puVar3[2] = 0;
      uVar4 = uVar4 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar4 < uVar1);
  }
  FUN_000f24c4();
  return;
}

/* FUN_0012a2a6 @ 0x12a2a6 (30 bytes) */
int FUN_0012a2a6(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
                    
                    
  (**(code **)(PTR_PTR_00213559 + param_2 * 0x10 + 0xc))();
  return;
}

/* FUN_0012a2c4 @ 0x12a2c4 (39 bytes) */
int FUN_0012a2c4(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x2c) + 4);
  *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
  FUN_001a7f3c(*(int *)(param_1 + 0x2c),iVar1 + -1);
  return;
}

/* FUN_0012a2ec @ 0x12a2ec (57 bytes) */
int FUN_0012a2ec(param_1)
  int param_1;
{
  char *pcVar1;
  int iVar2;
  
  if (*(int *)(*(int *)(param_1 + 0x30) + 0x98) != 8) {
    iVar2 = 0;
    pcVar1 = &STACKARG(0x8);
    do {
      if (*pcVar1 == '\0') {
        *(undefined1 *)(iVar2 + 0x9c + *(int *)(param_1 + 0x30)) = 0;
      }
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 1;
    } while (iVar2 != 4);
  }
  return *(undefined4 *)(param_1 + 0x34);
}

/* FUN_0012a326 @ 0x12a326 (87 bytes) */
int FUN_0012a326(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  char cVar2;
  
  if ((*(byte *)(param_1 + 9) & 2) == 0) {
    cVar2 = (**(code **)(*param_1 + 0x18))(param_1);
    if (cVar2 != '\0') {
      *(undefined4 *)(param_2 + 0x94) = *(undefined4 *)(param_2 + 0x14c);
      *(undefined4 *)(param_2 + 0x98) = 0;
      return;
    }
  }
  else {
    iVar1 = param_1[1];
    *(int *)(param_2 + 0x94) = param_1[4];
    *(int *)(param_2 + 0x98) = iVar1;
    *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x40;
  }
  return;
}

/* FUN_0012a37e @ 0x12a37e (175 bytes) */
int FUN_0012a37e(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  
  puVar1 = (uint *)param_1[0xb];
  if (puVar1[1] != 0) {
    uVar2 = puVar1[1];
    uVar5 = uVar2 - 1;
    if (uVar5 < *puVar1) {
      if (uVar2 <= uVar5) {
        _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar5 - uVar2) * 4 + 4);
        puVar1[1] = uVar2;
      }
      puVar3 = (undefined4 *)(puVar1[2] + uVar5 * 4);
    }
    else {
      puVar3 = (undefined4 *)FUN_001a7f7c(puVar1,uVar5);
    }
    return *puVar3;
  }
  uVar4 = (**(code **)(*param_1 + 8))(param_1,param_2,param_3);
  FUN_000eb51a(param_2,param_1,uVar4);
  return uVar4;
}

/* FUN_0012a42e @ 0x12a42e (108 bytes) */
int FUN_0012a42e(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = *(uint **)(param_1 + 0x18);
  uVar2 = puVar1[1];
  if (uVar2 < *puVar1) {
    _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
    puVar1[1] = uVar2 + 1;
    *(undefined4 *)(uVar2 * 4 + puVar1[2]) = param_2;
    return;
  }
  puVar3 = (undefined4 *)FUN_001a7f7c(puVar1,uVar2);
  *puVar3 = param_2;
  return;
}

/* FUN_0012a49a @ 0x12a49a (332 bytes) */
int FUN_0012a49a(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  char cVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  
  piVar3 = *(int **)(*(int *)(*(int *)(param_3 + 0x3f4) + 0x354) + 300);
  uVar4 = *(undefined4 *)(param_3 + 0xb8);
  puVar7 = (undefined4 *)FUN_001a7bca(uVar4,0x168);
  *puVar7 = uVar4;
  puVar1 = puVar7 + 1;
  FUN_0010ee6a(puVar1,param_3);
  iVar5 = *piVar3;
  iVar9 = 0;
  puVar8 = puVar1;
  do {
    *(byte *)(puVar7 + 0x58) = *(byte *)(puVar7 + 0x58) | (byte)(1 << ((byte)iVar9 & 0x1f));
    puVar8[7] = 3;
    iVar2 = iVar9 + *(int *)(param_1 + 8) * 4;
    if (iVar5 < iVar2) {
      puVar8[8] = 0;
    }
    else {
      puVar8[8] = piVar3[iVar2 + 1];
    }
    iVar9 = iVar9 + 1;
    puVar8 = puVar8 + 6;
  } while (iVar9 != 4);
  FUN_0010a3c2(puVar1,0,param_1);
  uVar4 = *(undefined4 *)(param_3 + 0xbc);
  puVar8 = (undefined4 *)FUN_001a7bca(uVar4,0x240);
  *puVar8 = uVar4;
  puVar8 = puVar8 + 1;
  FUN_00183c52(puVar8,puVar1,param_3);
  cVar6 = FUN_000e1402(param_3,7);
  if (cVar6 != '\0') {
    FUN_00185344(puVar8);
    FUN_00183630(puVar8);
  }
  ((int (*)())FUN_0012a42e)(param_1,puVar1);
  (**(code **)(*param_2 + 0xc))(param_2,puVar1);
  ((int (*)())FUN_0012a326)(param_1,puVar1);
  return puVar8;
}

/* FUN_0012a628 @ 0x12a628 (235 bytes) */
int FUN_0012a628(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = FUN_0010ed70(0xa4,param_3);
  FUN_0010a3c2(iVar3,0,param_1);
  *(undefined4 *)(iVar3 + 0x9c) = DAT_001cc40c;
  *(undefined4 *)(iVar3 + 300) = *(undefined4 *)(param_1 + 8);
  uVar1 = *(undefined4 *)(param_3 + 0xbc);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar1,0x240);
  *puVar4 = uVar1;
  puVar4 = puVar4 + 1;
  FUN_00183c52(puVar4,iVar3,param_3);
  cVar2 = FUN_000e1402(param_3,7);
  if (cVar2 != '\0') {
    FUN_00185344(puVar4);
    FUN_00183630(puVar4);
  }
  ((int (*)())FUN_0012a42e)(param_1,iVar3);
  (**(code **)(*param_2 + 0xc))(param_2,iVar3);
  ((int (*)())FUN_0012a326)(param_1,iVar3);
  return puVar4;
}

/* FUN_0012a734 @ 0x12a734 (126 bytes) */
int FUN_0012a734(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  puVar1 = *(uint **)(param_1 + 0x2c);
  uVar2 = puVar1[1];
  uVar4 = uVar2 - 1;
  if (uVar4 < *puVar1) {
    if (uVar2 <= uVar4) {
      _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar4 - uVar2) * 4 + 4);
      puVar1[1] = uVar2;
    }
    *(undefined4 *)(puVar1[2] + uVar4 * 4) = param_2;
    return;
  }
  puVar3 = (undefined4 *)FUN_001a7f7c(puVar1,uVar4);
  *puVar3 = param_2;
  return;
}

/* FUN_0012a7b2 @ 0x12a7b2 (144 bytes) */
int FUN_0012a7b2(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = *(uint **)(param_1 + 0x2c);
  if ((puVar1[1] != 0) && (param_2 == *(int *)(param_1 + 0x28))) {
    ((int (*)())FUN_0012a734)();
    return;
  }
  *(int *)(param_1 + 0x28) = param_2;
  uVar2 = puVar1[1];
  if (uVar2 < *puVar1) {
    _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
    puVar1[1] = uVar2 + 1;
    *(undefined4 *)(uVar2 * 4 + puVar1[2]) = param_3;
    return;
  }
  puVar3 = (undefined4 *)FUN_001a7f7c(puVar1,uVar2);
  *puVar3 = param_3;
  return;
}

/* FUN_0012a842 @ 0x12a842 (178 bytes) */
int FUN_0012a842(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  
  puVar5 = *(uint **)(param_1 + 0x14);
  if (puVar5[1] != 0) {
    uVar6 = 0;
    do {
      if (uVar6 < *puVar5) {
        uVar1 = puVar5[1];
        puVar4 = puVar5;
        if (uVar1 <= uVar6) {
          _memset((void *)(puVar5[2] + uVar1 * 4),0,(uVar6 - uVar1) * 4 + 4);
          puVar5[1] = uVar6 + 1;
          puVar4 = *(uint **)(param_1 + 0x14);
        }
        iVar2 = *(int *)(puVar5[2] + uVar6 * 4);
        puVar5 = puVar4;
      }
      else {
        piVar3 = (int *)FUN_001a7f7c(puVar5,uVar6);
        puVar5 = *(uint **)(param_1 + 0x14);
        iVar2 = *piVar3;
      }
      if (iVar2 == param_2) {
        FUN_001a7f3c();
        return;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < puVar5[1]);
  }
  return;
}

/* FUN_0012a8f4 @ 0x12a8f4 (241 bytes) */
int FUN_0012a8f4(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  
  puVar6 = *(uint **)(param_1 + 0x14);
  if (puVar6[1] != 0) {
    uVar7 = 0;
    do {
      if (uVar7 < *puVar6) {
        uVar2 = puVar6[1];
        puVar5 = puVar6;
        if (uVar2 <= uVar7) {
          _memset((void *)(puVar6[2] + uVar2 * 4),0,(uVar7 - uVar2) * 4 + 4);
          puVar6[1] = uVar7 + 1;
          puVar5 = *(uint **)(param_1 + 0x14);
        }
        iVar1 = *(int *)(puVar6[2] + uVar7 * 4);
        puVar6 = puVar5;
      }
      else {
        piVar3 = (int *)FUN_001a7f7c(puVar6,uVar7);
        puVar6 = *(uint **)(param_1 + 0x14);
        iVar1 = *piVar3;
      }
      if (iVar1 == param_2) {
        if (*puVar6 <= uVar7) {
          puVar4 = (undefined4 *)FUN_001a7f7c(puVar6,uVar7);
          *puVar4 = param_3;
          return;
        }
        uVar2 = puVar6[1];
        if (uVar2 <= uVar7) {
          _memset((void *)(puVar6[2] + uVar2 * 4),0,(uVar7 - uVar2) * 4 + 4);
          puVar6[1] = uVar7 + 1;
        }
        *(undefined4 *)(puVar6[2] + uVar7 * 4) = param_3;
        return;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < puVar6[1]);
  }
  return;
}

/* FUN_0012a9e6 @ 0x12a9e6 (154 bytes) */
int FUN_0012a9e6(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if (1 < param_2) {
    if (param_1 != *(int *)(param_3 + 0xa4)) {
      iVar5 = 1;
      iVar4 = param_3;
      do {
        iVar5 = iVar5 + 1;
        if (param_2 == iVar5) goto LAB_0012aa26;
        piVar3 = (int *)(iVar4 + 0xbc);
        iVar4 = iVar4 + 0x18;
      } while (param_1 != *piVar3);
    }
    return;
  }
LAB_0012aa26:
  puVar1 = *(uint **)(param_1 + 0x14);
  uVar2 = puVar1[1];
  if (uVar2 < *puVar1) {
    _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
    puVar1[1] = uVar2 + 1;
    *(int *)(uVar2 * 4 + puVar1[2]) = param_3;
  }
  else {
    piVar3 = (int *)FUN_001a7f7c(puVar1,uVar2);
    *piVar3 = param_3;
  }
  return;
}

/* FUN_0012aa80 @ 0x12aa80 (325 bytes) */
int FUN_0012aa80(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  *param_1 = PTR_DAT_002139e9 + 8;
  param_1[1] = param_3;
  param_1[2] = param_2;
  param_1[3] = param_4;
  param_1[4] = 0xffffffff;
  param_1[7] = 0xffffffff;
  iVar1 = *(int *)(param_5 + 0x8c);
  param_1[8] = iVar1;
  *(int *)(param_5 + 0x8c) = iVar1 + 1;
  param_1[9] = 0;
  param_1[10] = 0xffffffff;
  uVar3 = *(undefined4 *)(param_5 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar3,0x14);
  *puVar2 = uVar3;
  puVar2[4] = uVar3;
  puVar2[2] = 0;
  puVar2[1] = 2;
  uVar3 = FUN_001a7bca(uVar3,8);
  puVar2[3] = uVar3;
  param_1[5] = puVar2 + 1;
  uVar3 = *(undefined4 *)(param_5 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar3,0x14);
  *puVar2 = uVar3;
  puVar2[4] = uVar3;
  puVar2[2] = 0;
  puVar2[1] = 2;
  uVar3 = FUN_001a7bca(uVar3,8);
  puVar2[3] = uVar3;
  param_1[6] = puVar2 + 1;
  uVar3 = *(undefined4 *)(param_5 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar3,0x14);
  *puVar2 = uVar3;
  puVar2[4] = uVar3;
  puVar2[2] = 0;
  puVar2[1] = 2;
  uVar3 = FUN_001a7bca(uVar3,8);
  puVar2[3] = uVar3;
  param_1[0xb] = puVar2 + 1;
  return;
}

/* FUN_0012ac02 @ 0x12ac02 (325 bytes) */
int FUN_0012ac02(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  *param_1 = PTR_DAT_002139e9 + 8;
  param_1[1] = param_3;
  param_1[2] = param_2;
  param_1[3] = param_4;
  param_1[4] = 0xffffffff;
  param_1[7] = 0xffffffff;
  iVar1 = *(int *)(param_5 + 0x8c);
  param_1[8] = iVar1;
  *(int *)(param_5 + 0x8c) = iVar1 + 1;
  param_1[9] = 0;
  param_1[10] = 0xffffffff;
  uVar3 = *(undefined4 *)(param_5 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar3,0x14);
  *puVar2 = uVar3;
  puVar2[4] = uVar3;
  puVar2[2] = 0;
  puVar2[1] = 2;
  uVar3 = FUN_001a7bca(uVar3,8);
  puVar2[3] = uVar3;
  param_1[5] = puVar2 + 1;
  uVar3 = *(undefined4 *)(param_5 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar3,0x14);
  *puVar2 = uVar3;
  puVar2[4] = uVar3;
  puVar2[2] = 0;
  puVar2[1] = 2;
  uVar3 = FUN_001a7bca(uVar3,8);
  puVar2[3] = uVar3;
  param_1[6] = puVar2 + 1;
  uVar3 = *(undefined4 *)(param_5 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar3,0x14);
  *puVar2 = uVar3;
  puVar2[4] = uVar3;
  puVar2[2] = 0;
  puVar2[1] = 2;
  uVar3 = FUN_001a7bca(uVar3,8);
  puVar2[3] = uVar3;
  param_1[0xb] = puVar2 + 1;
  return;
}

/* FUN_0012ad84 @ 0x12ad84 (471 bytes) */
int FUN_0012ad84(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  
  if ((*(byte *)(param_3 + 0x31) & 0x40) != 0) {
    iVar7 = *(int *)(param_3 + 8);
    uVar3 = *(undefined4 *)(iVar7 + 0xb8);
    puVar2 = (undefined4 *)FUN_001a7bca(uVar3,0x168);
    *puVar2 = uVar3;
    puVar1 = puVar2 + 1;
    FUN_0010de3c(puVar1,iVar7);
    puVar2[0x28] = param_2;
    puVar2[0x51] = *(undefined4 *)(param_1 + 8);
    puVar2[0x50] = *(undefined4 *)(param_1 + 4);
    uVar3 = FUN_0012eb84(*(undefined4 *)(param_3 + 0x3a0),0x2c,0,0);
    FUN_0010a3c2(puVar1,0,uVar3);
    FUN_0010a3c2(puVar1,2,uVar3);
    iVar4 = FUN_0010b0f4(puVar1,2);
    *(undefined4 *)(iVar4 + 0x10) = DAT_001cc410;
    ((int (*)())FUN_0012a42e)(uVar3,puVar1);
    iVar4 = *(int *)(iVar7 + 0xf0) + -1;
    *(int *)(iVar7 + 0xf0) = iVar4;
    uVar5 = FUN_0012eb2a(*(undefined4 *)(param_3 + 0x3a0),0,iVar4,0);
    *(undefined4 *)(param_1 + 0x3c) = uVar5;
    FUN_0010a3c2(puVar1,1,uVar5);
    ((int (*)())FUN_0012a9e6)(*(undefined4 *)(param_1 + 0x3c),1,puVar1);
    ((int (*)())FUN_0012a9e6)(uVar3,2,puVar1);
    *(undefined4 **)(param_1 + 0x30) = puVar1;
    return *(int *)(param_1 + 0x3c);
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    if (*(int *)(*(int *)(param_1 + 0x30) + 0x98) != 0x18) {
      iVar7 = 0;
      pcVar6 = (char *)&param_2;
      do {
        if (*pcVar6 == '\0') {
          *(undefined1 *)(iVar7 + 0x9c + *(int *)(param_1 + 0x30)) = 0;
          if (*(int *)(param_1 + 0x34) != 0) {
            *(undefined1 *)(iVar7 + 0x9c + *(int *)(param_1 + 0x34)) = 0;
          }
        }
        iVar7 = iVar7 + 1;
        pcVar6 = pcVar6 + 1;
      } while (iVar7 != 4);
    }
    return *(int *)(param_1 + 0x3c);
  }
  iVar7 = *(int *)(param_1 + 0x3c);
  if (*(int *)(param_1 + 0x3c) == 0) {
    iVar7 = param_1;
  }
  return iVar7;
}

/* FUN_0012af7a @ 0x12af7a (1423 bytes) */
int FUN_0012af7a(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  char cVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  undefined4 local_34 [3];
  undefined4 local_28;
  undefined1 uStack_25;
  undefined4 local_24;
  undefined4 *local_20 [4];
  
  if (*(int *)(param_1 + 0x36c) != 0) {
    puVar1 = *(uint **)(*(int *)(*(int *)(param_1 + 0x36c) + 0x8c) + 0x2c);
    uVar2 = puVar1[1];
    uVar16 = uVar2 - 1;
    if (uVar16 < *puVar1) {
      if (uVar16 < uVar2) {
        puVar8 = (undefined4 *)(puVar1[2] + uVar16 * 4);
      }
      else {
        _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar16 - uVar2) * 4 + 4);
        puVar1[1] = uVar2;
        puVar8 = (undefined4 *)(puVar1[2] + uVar16 * 4);
      }
    }
    else {
      puVar8 = (undefined4 *)FUN_001a7f7c(puVar1,uVar16);
    }
    return (undefined4 *)*puVar8;
  }
  iVar12 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(iVar12 + 0x3f4);
  local_24 = DAT_001cc40c;
  bVar6 = false;
  iVar14 = 1;
  puVar8 = local_34;
  iVar15 = iVar3;
  do {
    iVar4 = *(int *)(iVar15 + 0x10);
    if (iVar4 == 1) {
      *puVar8 = 0;
    }
    else if (iVar4 == 2) {
      *puVar8 = 0x3f800000;
    }
    else if (iVar4 == 0) {
      *puVar8 = 0;
      (&uStack_25)[iVar14] = 1;
      bVar6 = true;
    }
    iVar14 = iVar14 + 1;
    puVar8 = puVar8 + 1;
    iVar15 = iVar15 + 4;
  } while (iVar14 != 5);
  uVar9 = FUN_0010dbb8(0x31,iVar12);
  *(undefined4 *)(param_1 + 0x36c) = uVar9;
  FUN_000fa0d2(uVar9,*(undefined4 *)(*(int *)(param_1 + 8) + 0x3f4),1,local_34[0],local_34[1],
               local_34[2],local_28);
  iVar12 = *(int *)(*(int *)(param_1 + 0x36c) + 0xa4);
  piVar5 = *(int **)(iVar12 + 0x18);
  if (*piVar5 == 0) {
    puVar8 = (undefined4 *)FUN_001a7f7c(piVar5,0);
  }
  else {
    if (piVar5[1] == 0) {
      *(undefined4 *)piVar5[2] = 0;
      piVar5[1] = 1;
    }
    puVar8 = (undefined4 *)piVar5[2];
  }
  uVar9 = *puVar8;
  if (*(int *)(*(int *)(iVar12 + 0x2c) + 4) == 0) {
    uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
    puVar8 = (undefined4 *)FUN_001a7bca(uVar13,0x240);
    *puVar8 = uVar13;
    puVar8 = puVar8 + 1;
    FUN_00183c52(puVar8,uVar9,*(undefined4 *)(param_1 + 8));
    cVar7 = FUN_000e1402(*(undefined4 *)(param_1 + 8),7);
    if (cVar7 != '\0') {
      FUN_00185344(puVar8);
      FUN_00183630(puVar8);
    }
    ((int (*)())FUN_0012a7b2)(iVar12,param_2[0x2c],puVar8);
  }
  ((int (*)())FUN_0012a9e6)(iVar12,1,uVar9);
  if (bVar6) {
    uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
    puVar10 = (undefined4 *)FUN_001a7bca(uVar13,0x168);
    *puVar10 = uVar13;
    puVar8 = puVar10 + 1;
    FUN_0010e55e(puVar8,*(undefined4 *)(param_1 + 8));
    (**(code **)(**(int **)(param_1 + 0x394) + 0xc))(*(int **)(param_1 + 0x394),puVar8);
    iVar15 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar15;
    uVar11 = FUN_0012eb84(*(undefined4 *)(iVar3 + 0x3a0),0,iVar15,0);
    puVar10[0x24] = uVar11;
    iVar12 = FUN_0010b0f4(puVar8,0);
    *(int *)(iVar12 + 8) = iVar15;
    *(undefined4 *)(iVar12 + 0xc) = 0;
    uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
    puVar10 = (undefined4 *)FUN_001a7bca(uVar13,0x240);
    *puVar10 = uVar13;
    puVar10 = puVar10 + 1;
    FUN_00183c52(puVar10,puVar8,*(undefined4 *)(param_1 + 8));
    cVar7 = FUN_000e1402(*(undefined4 *)(param_1 + 8),7);
    if (cVar7 != '\0') {
      FUN_00185344(puVar10);
      FUN_00183630(puVar10);
    }
    ((int (*)())FUN_0012a42e)(uVar11,puVar8);
    FUN_000eb51a(param_2,uVar11,puVar10);
    *(undefined4 *)(*(int *)(param_1 + 0x36c) + 0x9c) = local_24;
    FUN_0010c18e(*(undefined4 *)(param_1 + 0x36c),puVar8,0,*(undefined4 *)(param_1 + 8));
    *(undefined4 *)(*(int *)(param_1 + 0x36c) + 0xbc) = uVar11;
    ((int (*)())FUN_0012a9e6)(uVar11,2,*(undefined4 *)(param_1 + 0x36c));
  }
  FUN_0010ba02(*(undefined4 *)(param_1 + 0x36c),1,uVar9,0,*(undefined4 *)(param_1 + 8));
  uVar9 = *(undefined4 *)(*(int *)(param_1 + 0x36c) + 0x14c);
  iVar12 = FUN_0010b0f4(*(int *)(param_1 + 0x36c),0);
  *(undefined4 *)(iVar12 + 8) = uVar9;
  *(undefined4 *)(iVar12 + 0xc) = 0;
  iVar12 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar12;
  uVar13 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar12,0);
  *(undefined4 *)(*(int *)(param_1 + 0x36c) + 0x8c) = uVar13;
  ((int (*)())FUN_0012a42e)(uVar13,*(undefined4 *)(param_1 + 0x36c));
  (**(code **)(*param_2 + 0xc))(param_2,*(undefined4 *)(param_1 + 0x36c));
  uVar9 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar8 = (undefined4 *)FUN_001a7bca(uVar9,0x240);
  *puVar8 = uVar9;
  FUN_00183c52(puVar8 + 1,*(undefined4 *)(param_1 + 0x36c),*(undefined4 *)(param_1 + 8));
  local_20[0] = puVar8 + 1;
  FUN_00186556(iVar3,0,0,local_20,param_2);
  FUN_000eb51a(param_2,uVar13,local_20[0]);
  ((int (*)())FUN_0012a326)(uVar13,*(undefined4 *)(param_1 + 0x36c));
  return local_20[0];
}

/* FUN_0012b572 @ 0x12b572 (290 bytes) */
int FUN_0012b572(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint *puVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 4) != 0x1a) {
    puVar4 = (undefined4 *)((int (*)())FUN_0012af7a)();
    return puVar4;
  }
  iVar5 = (**(code **)(**(int **)(param_3 + 0x54) + 0x50))
                    (*(int **)(param_3 + 0x54),*(undefined4 *)(param_1 + 8),param_3);
  FUN_0010a3c2(iVar5,0,param_1);
  *(undefined4 *)(iVar5 + 0x9c) = DAT_001cc40c;
  ((int (*)())FUN_0012a42e)(param_1,iVar5);
  uVar2 = *(undefined4 *)(param_3 + 0xbc);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar2,0x240);
  *puVar4 = uVar2;
  puVar4 = puVar4 + 1;
  FUN_00183c52(puVar4,iVar5,param_3);
  cVar3 = FUN_000e1402(param_3,7);
  if (cVar3 != '\0') {
    FUN_00185344(puVar4);
    FUN_00183630(puVar4);
  }
  puVar1 = (uint *)(*(int *)(param_3 + 0x54) + 8);
  *puVar1 = *puVar1 | 0x20;
  (**(code **)(*param_2 + 0xc))(param_2,iVar5);
  ((int (*)())FUN_0012a326)(param_1,iVar5);
  return puVar4;
}

/* FUN_0012b6b8 @ 0x12b6b8 (265 bytes) */
int FUN_0012b6b8(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 *puVar4;
  
  uVar2 = *(undefined4 *)(param_3 + 0xb8);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar2,0x168);
  *puVar4 = uVar2;
  puVar1 = puVar4 + 1;
  FUN_0010ef86(puVar1,0xfa,param_3);
  FUN_0010a3c2(puVar1,0,param_1);
  puVar4[0x28] = DAT_001cc40c;
  puVar4[6] = puVar4[6] & 0xffff7fff;
  uVar2 = *(undefined4 *)(param_3 + 0xbc);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar2,0x240);
  *puVar4 = uVar2;
  puVar4 = puVar4 + 1;
  FUN_00183c52(puVar4,puVar1,param_3);
  cVar3 = FUN_000e1402(param_3,7);
  if (cVar3 != '\0') {
    FUN_00185344(puVar4);
    FUN_00183630(puVar4);
  }
  ((int (*)())FUN_0012a42e)(param_1,puVar1);
  (**(code **)(*param_2 + 0xc))(param_2,puVar1);
  ((int (*)())FUN_0012a326)(param_1,puVar1);
  return puVar4;
}

/* FUN_0012b804 @ 0x12b804 (235 bytes) */
int FUN_0012b804(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  uVar1 = *(undefined4 *)(param_3 + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar3 = uVar1;
  puVar3 = puVar3 + 1;
  FUN_0010e916(puVar3,param_1,param_3);
  FUN_0010a3c2(puVar3,0,param_1);
  uVar1 = *(undefined4 *)(param_3 + 0xbc);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar1,0x240);
  *puVar4 = uVar1;
  puVar4 = puVar4 + 1;
  FUN_00183c52(puVar4,puVar3,param_3);
  cVar2 = FUN_000e1402(param_3,7);
  if (cVar2 != '\0') {
    FUN_00185344(puVar4);
    FUN_00183630(puVar4);
  }
  ((int (*)())FUN_0012a42e)(param_1,puVar3);
  (**(code **)(*param_2 + 0xc))(param_2,puVar3);
  ((int (*)())FUN_0012a326)(param_1,puVar3);
  return puVar4;
}

/* FUN_0012b932 @ 0x12b932 (231 bytes) */
int FUN_0012b932(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  uVar1 = *(undefined4 *)(param_3 + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar3 = uVar1;
  puVar3 = puVar3 + 1;
  FUN_0010ee6a(puVar3,param_3);
  FUN_0010a3c2(puVar3,0,param_1);
  uVar1 = *(undefined4 *)(param_3 + 0xbc);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar1,0x240);
  *puVar4 = uVar1;
  puVar4 = puVar4 + 1;
  FUN_00183c52(puVar4,puVar3,param_3);
  cVar2 = FUN_000e1402(param_3,7);
  if (cVar2 != '\0') {
    FUN_00185344(puVar4);
    FUN_00183630(puVar4);
  }
  ((int (*)())FUN_0012a42e)(param_1,puVar3);
  (**(code **)(*param_2 + 0xc))(param_2,puVar3);
  ((int (*)())FUN_0012a326)(param_1,puVar3);
  return puVar4;
}

/* FUN_0012ba5c @ 0x12ba5c (334 bytes) */
int FUN_0012ba5c(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  ((int (*)())FUN_0012aa80)(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fcfc8;
  param_1[4] = param_2;
  *(int *)(param_5 + 0x7c) = *(int *)(param_5 + 0x7c) + 1;
  if (param_3 == 3) {
    if (*(int *)(*(int *)(param_5 + 0x54) + 0x24) <= param_2) {
      FUN_000e27ca(param_5,10);
    }
  }
  else if (param_3 == 4) {
    if (*(int *)(*(int *)(param_5 + 0x54) + 0x28) <= param_2) {
      FUN_000e27ca(param_5,0xc);
    }
  }
  else if ((param_3 == 2) && (*(int *)(*(int *)(param_5 + 0x54) + 0x2c) <= param_2)) {
    FUN_000e27ca(param_5,0xb);
  }
  uVar1 = *(undefined4 *)(param_5 + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar3 = uVar1;
  puVar3 = puVar3 + 1;
  FUN_0010ebaa(puVar3,param_1,param_5);
  piVar2 = *(int **)(*(int *)(param_5 + 0x3f4) + 0x394);
  (**(code **)(*piVar2 + 0xc))(piVar2,puVar3);
  FUN_0010a3c2(puVar3,0,param_1);
  ((int (*)())FUN_0012a42e)(param_1,puVar3);
  return;
}

/* FUN_0012bbdc @ 0x12bbdc (334 bytes) */
int FUN_0012bbdc(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  ((int (*)())FUN_0012aa80)(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fcfc8;
  param_1[4] = param_2;
  *(int *)(param_5 + 0x7c) = *(int *)(param_5 + 0x7c) + 1;
  if (param_3 == 3) {
    if (*(int *)(*(int *)(param_5 + 0x54) + 0x24) <= param_2) {
      FUN_000e27ca(param_5,10);
    }
  }
  else if (param_3 == 4) {
    if (*(int *)(*(int *)(param_5 + 0x54) + 0x28) <= param_2) {
      FUN_000e27ca(param_5,0xc);
    }
  }
  else if ((param_3 == 2) && (*(int *)(*(int *)(param_5 + 0x54) + 0x2c) <= param_2)) {
    FUN_000e27ca(param_5,0xb);
  }
  uVar1 = *(undefined4 *)(param_5 + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar3 = uVar1;
  puVar3 = puVar3 + 1;
  FUN_0010ebaa(puVar3,param_1,param_5);
  piVar2 = *(int **)(*(int *)(param_5 + 0x3f4) + 0x394);
  (**(code **)(*piVar2 + 0xc))(piVar2,puVar3);
  FUN_0010a3c2(puVar3,0,param_1);
  ((int (*)())FUN_0012a42e)(param_1,puVar3);
  return;
}

/* FUN_0012bd5c @ 0x12bd5c (72 bytes) */
int FUN_0012bd5c(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())FUN_0012aa80)(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fcf88;
  param_1[4] = param_2;
  return;
}

/* FUN_0012bda4 @ 0x12bda4 (72 bytes) */
int FUN_0012bda4(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())FUN_0012aa80)(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fcf88;
  param_1[4] = param_2;
  return;
}

/* FUN_0012bdec @ 0x12bdec (88 bytes) */
int FUN_0012bdec(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  
  ((int (*)())FUN_0012aa80)(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fcec8;
  iVar1 = *(int *)(param_5 + 0x78);
  param_1[4] = iVar1;
  param_1[7] = iVar1;
  *(int *)(param_5 + 0x78) = iVar1 + 1;
  *(undefined1 *)(param_1 + 0xc) = 0;
  return;
}

/* FUN_0012be44 @ 0x12be44 (400 bytes) */
int FUN_0012be44(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_20 [4];
  
  ((int (*)())FUN_0012bdec)(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139c1 + 8;
  iVar1 = *(int *)(param_5 + 0x3f4);
  local_20[0] = DAT_001cc418;
  uVar2 = (**(code **)(**(int **)(param_5 + 0x54) + 0xa4))
                    (*(int **)(param_5 + 0x54),local_20,param_5);
  uVar3 = FUN_0012eb84(*(undefined4 *)(iVar1 + 0x3a0),0x10,uVar2,0);
  uVar2 = *(undefined4 *)(param_5 + 0xb8);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar2,0x168);
  *puVar4 = uVar2;
  puVar4 = puVar4 + 1;
  FUN_0010e916(puVar4,param_1,param_5);
  FUN_000e9540(*(undefined4 *)(iVar1 + 0x394),puVar4);
  FUN_0010a3c2(puVar4,0,uVar3);
  ((int (*)())FUN_0012a42e)(uVar3,puVar4);
  uVar5 = FUN_0010dbb8(0x31,param_5);
  FUN_0010a3c2(uVar5,1,uVar3);
  uVar2 = local_20[0];
  iVar6 = FUN_0010b0f4(uVar5,1);
  *(undefined4 *)(iVar6 + 0x10) = uVar2;
  FUN_0010a3c2(uVar5,0,param_1);
  ((int (*)())FUN_0012a42e)(param_1,uVar5);
  FUN_000e9512(*(undefined4 *)(iVar1 + 0x394),uVar5);
  return;
}

/* FUN_0012c00e @ 0x12c00e (371 bytes) */
int FUN_0012c00e(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  ((int (*)())FUN_0012bdec)(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139d9 + 8;
  iVar1 = *(int *)(param_5 + 0x3f4);
  iVar2 = *(int *)(iVar1 + 0x38 + param_2 * 4);
  if (iVar2 == 0) {
    uVar4 = FUN_0012eb84(*(undefined4 *)(iVar1 + 0x3a0),0x10,param_2,0);
    uVar3 = *(undefined4 *)(param_5 + 0xb8);
    puVar5 = (undefined4 *)FUN_001a7bca(uVar3,0x168);
    *puVar5 = uVar3;
    puVar5 = puVar5 + 1;
    FUN_0010e916(puVar5,param_1,param_5);
    FUN_000e9540(*(undefined4 *)(iVar1 + 0x394),puVar5);
    FUN_0010a3c2(puVar5,0,uVar4);
    ((int (*)())FUN_0012a42e)(uVar4,puVar5);
    *(undefined4 **)(iVar1 + 0x38 + param_2 * 4) = puVar5;
  }
  else {
    uVar4 = *(undefined4 *)(iVar2 + 0x8c);
  }
  uVar3 = FUN_0010dbb8(0x31,param_5);
  FUN_0010a3c2(uVar3,1,uVar4);
  FUN_0010a3c2(uVar3,0,param_1);
  ((int (*)())FUN_0012a42e)(param_1,uVar3);
  FUN_000e9512(*(undefined4 *)(iVar1 + 0x394),uVar3);
  return;
}

/* FUN_0012c1be @ 0x12c1be (371 bytes) */
int FUN_0012c1be(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  ((int (*)())FUN_0012bdec)(param_1,param_2,param_3,param_4,param_5);
  *param_1 = PTR_DAT_002139d9 + 8;
  iVar1 = *(int *)(param_5 + 0x3f4);
  iVar2 = *(int *)(iVar1 + 0x38 + param_2 * 4);
  if (iVar2 == 0) {
    uVar4 = FUN_0012eb84(*(undefined4 *)(iVar1 + 0x3a0),0x10,param_2,0);
    uVar3 = *(undefined4 *)(param_5 + 0xb8);
    puVar5 = (undefined4 *)FUN_001a7bca(uVar3,0x168);
    *puVar5 = uVar3;
    puVar5 = puVar5 + 1;
    FUN_0010e916(puVar5,param_1,param_5);
    FUN_000e9540(*(undefined4 *)(iVar1 + 0x394),puVar5);
    FUN_0010a3c2(puVar5,0,uVar4);
    ((int (*)())FUN_0012a42e)(uVar4,puVar5);
    *(undefined4 **)(iVar1 + 0x38 + param_2 * 4) = puVar5;
  }
  else {
    uVar4 = *(undefined4 *)(iVar2 + 0x8c);
  }
  uVar3 = FUN_0010dbb8(0x31,param_5);
  FUN_0010a3c2(uVar3,1,uVar4);
  FUN_0010a3c2(uVar3,0,param_1);
  ((int (*)())FUN_0012a42e)(param_1,uVar3);
  FUN_000e9512(*(undefined4 *)(iVar1 + 0x394),uVar3);
  return;
}

/* FUN_0012c36e @ 0x12c36e (88 bytes) */
int FUN_0012c36e(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  
  ((int (*)())FUN_0012aa80)(param_1,param_2,param_3,param_4,param_5);
  *param_1 = &PTR_FUN_001fcec8;
  iVar1 = *(int *)(param_5 + 0x78);
  param_1[4] = iVar1;
  param_1[7] = iVar1;
  *(int *)(param_5 + 0x78) = iVar1 + 1;
  *(undefined1 *)(param_1 + 0xc) = 0;
  return;
}

