#include "decls.h"

/* FUN_00003930 @ 0x3930 (916 bytes) */
int FUN_00003930(param_1, param_2, param_3)
  int param_1;
  byte *param_2;
  undefined4 *param_3;
{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  undefined4 local_48 [8];
  
  puVar10 = (uint *)(param_1 + 0x55c);
  puVar10[(char)param_2[6] + 0x150] = 0;
  puVar10[(char)param_2[6] + 0x155] = 0;
  if (*param_2 == 1) {
    puVar10[(char)param_2[6] + 0x14b] = 0;
  }
  if ((puVar10[(char)param_2[7] + 0x14b] == 0) && (puVar10[(char)param_2[8] + 0x14b] == 0)) {
    iVar4 = *(int *)(param_1 + 0xac4);
    iVar8 = 0;
    puVar10[(char)param_2[6] + 0x14b] = 0;
    puVar10[iVar4 * 2 + 0x15b] = 0;
    puVar10[*(int *)(param_1 + 0xac4) * 2 + 0x15c] = 0;
    *(int *)(param_1 + 0x568) = (int)(char)param_2[6];
    *(int *)(param_1 + 0x56c) = (int)(char)param_2[7];
    *(int *)(param_1 + 0x570) = (int)(char)param_2[8];
    local_48[0] = *(undefined4 *)(param_2 + 0x10);
    iVar4 = *(int *)(param_2 + 0xc);
    do {
      *puVar10 = (uint)param_2[2];
      *(uint *)(param_1 + 0x560) = (uint)*param_2;
      *(byte *)(param_1 + 0x564) = param_2[4];
      if (iVar8 == 0) {
        *(undefined1 *)(param_1 + 0x574) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x574) = 1;
      }
      if (*puVar10 == 3) {
        uVar9 = *(int *)(param_1 + 0x580) * *(int *)(param_1 + 0x584);
      }
      else {
        uVar9 = (uint)(*(int *)(param_1 + 0x580) * *(int *)(param_1 + 0x584)) >> 1;
      }
      if (*(int *)(param_1 + 0x560) == 1) {
        if (uVar9 != 0) {
          iVar13 = iVar4;
          uVar11 = 0;
          do {
            uVar12 = uVar11 + 1;
            iVar4 = iVar13 + 0x1c;
            ((int (*)())FUN_00008510)(param_1,iVar13,local_48,uVar11,0);
            iVar13 = iVar4;
            uVar11 = uVar12;
          } while (uVar12 < uVar9);
        }
      }
      else {
        iVar13 = 0x19;
        puVar5 = (undefined4 *)(param_1 + 0x1442c);
        do {
          *puVar5 = 0;
          puVar5[-1] = *(int *)(param_1 + 0x14424) + -1;
          puVar5 = puVar5 + 3;
          iVar13 = iVar13 + -1;
        } while (iVar13 != 0);
        if (uVar9 != 0) {
          uVar11 = 0;
          do {
            if (*(char *)(iVar4 + 0x14) == '\0') {
              ((int (*)())FUN_00008510)(param_1,iVar4,local_48,uVar11,0);
            }
            else {
              ((int (*)())FUN_00008510)(param_1,iVar4,local_48,uVar11,1);
              ((int (*)())FUN_00008820)(param_1,iVar4,uVar11);
            }
            uVar11 = uVar11 + 1;
            iVar4 = iVar4 + 0x1c;
          } while (uVar11 < uVar9);
        }
        piVar2 = (int *)(param_1 + 0x1442c);
        iVar13 = 0;
        iVar7 = 0;
        iVar6 = 0x19;
        do {
          if (*piVar2 != 0) {
            iVar7 = iVar7 + *piVar2;
            iVar13 = iVar13 + 1;
          }
          iVar14 = (*(int *)(param_1 + 0x14424) - piVar2[-1]) + -1;
          if (iVar14 != 0) {
            iVar13 = iVar13 + 1;
            iVar7 = iVar7 + iVar14;
          }
          iVar6 = iVar6 + -1;
          piVar2 = piVar2 + 3;
        } while (iVar6 != 0);
        ((int (*)())FUN_00007850)(param_1,(iVar13 * 0x80 + iVar7) * 2 + 1000);
      }
      ((int (*)())FUN_00007f80)(param_1);
      if (*puVar10 == 3) break;
      bVar1 = iVar8 != 1;
      param_2 = param_2 + 1;
      iVar8 = iVar8 + 1;
    } while (bVar1);
    uVar3 = *(undefined4 *)(param_1 + 0xac4);
    *param_3 = 0;
    param_3[1] = uVar3;
    uVar3 = 0;
    *(uint *)(param_1 + 0xac4) = (*(int *)(param_1 + 0xac4) + 1U) % 10000;
  }
  else {
    uVar3 = 0xffffffff;
    puVar10[(char)param_2[6] + 0x14b] = 1;
  }
  return uVar3;
}

/* FUN_00003cd0 @ 0x3cd0 (672 bytes) */
int FUN_00003cd0(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined *puVar1;
  uint *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  char in_RESERVE;
  byte in_cr0;
  
  puVar1 = PTR_0000f1a0;
  piVar7 = *(int **)(param_1 + 0x34);
  if (*(int **)(param_1 + 0x38) <= piVar7 + 8) {
    puVar2 = *(uint **)(param_1 + 0x30);
    *puVar2 = (int)piVar7 - (int)puVar2 >> 2 | *puVar2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar5 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar5 + 0x20;
    *(int *)(param_1 + 0x30) = iVar5 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar5 + 0x20 + *(int *)(iVar5 + 0x10) * 4;
    *(undefined4 *)(iVar5 + 0x1c) = 0;
    piVar7 = *(int **)(param_1 + 0x34);
  }
  puVar2 = *(uint **)(param_1 + 0x30);
  *(int **)(param_1 + 0x34) = piVar7 + 8;
  piVar4 = piVar7 + 1;
  *puVar2 = (int)piVar7 - (int)puVar2 >> 2 | *puVar2;
  *(int **)(param_1 + 0x30) = piVar7;
  *piVar7 = param_2 * 0x1000000 + 0x19000000;
  piVar3 = piVar4;
  switch(param_2) {
  case 0:
    piVar6 = *(int **)(param_1 + 0x151b4);
    break;
  case 1:
    piVar6 = *(int **)(param_1 + 0x153bc);
    break;
  case 2:
    piVar6 = *(int **)(param_1 + 0x170);
    goto LAB_00003ed8;
  case 3:
    piVar6 = *(int **)(param_1 + 0x1d8);
    goto LAB_00003ed8;
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
    piVar6 = *(int **)(param_2 * 100 + param_1 + 0xb0);
    break;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
    piVar6 = *(int **)(param_2 * 100 + param_1 + 0x38c);
    break;
  case 0x11:
    piVar6 = *(int **)(param_1 + 0xa44);
LAB_00003ed8:
    piVar6 = (int *)*piVar6;
    piVar3 = piVar7 + 2;
    *piVar4 = *piVar6;
    piVar6 = piVar6 + 4;
    do {
      if (in_RESERVE != '\0') {
        iVar5 = storeWordConditionalIndexed(*piVar6 + 1,0,piVar6);
        *piVar6 = iVar5;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
  default:
    goto switchD_00003e00_default;
  }
  piVar3 = piVar7 + 2;
  piVar6 = (int *)*piVar6;
  *piVar4 = *piVar6;
  piVar6 = piVar6 + 4;
  do {
    if (in_RESERVE != '\0') {
      iVar5 = storeWordConditionalIndexed(*piVar6 + 1,0,piVar6);
      *piVar6 = iVar5;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
switchD_00003e00_default:
  iVar5 = 6;
  do {
    *piVar3 = -0x80000000;
    puVar1 = PTR_0000f1a0;
    piVar3 = piVar3 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  puVar2 = *(uint **)(param_1 + 0x30);
  *puVar2 = *(int *)(param_1 + 0x34) - (int)puVar2 >> 2 | *puVar2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar5 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar5 + 0x20;
  *(int *)(param_1 + 0x30) = iVar5 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar5 + 0x20 + *(int *)(iVar5 + 0x10) * 4;
  *(undefined4 *)(iVar5 + 0x1c) = 0;
  return;
}

/* FUN_00003fc0 @ 0x3fc0 (696 bytes) */
int FUN_00003fc0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  undefined4 *param_3;
  undefined4 *param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar7 = param_1 + 0x55c;
  if (((param_3[6] == 0) || ((int)param_2 < 0)) || (*(uint *)(param_1 + 0x54) <= param_2)) {
    return 0xfffffff9;
  }
  iVar2 = param_3[3];
  if (((iVar2 != 0x79757673) && (iVar2 != 0x32767579)) &&
     ((iVar2 != 0x61726762 && ((iVar2 != 0x72676261 && (iVar2 != 0x61723135)))))) {
    return 0xfffffffb;
  }
  if ((*(int *)(param_1 + 0x120) == 0) || (*(int *)(param_2 * 4 + iVar7 + 0x554) == 0)) {
    uVar1 = *(uint *)(param_1 + 0x11c);
    if ((uVar1 & 2) != 0) {
      ((int (*)())FUN_0000a110)(param_1,param_2,0);
      uVar1 = *(uint *)(param_1 + 0x11c);
    }
    if ((uVar1 & 4) != 0) {
      ((int (*)())FUN_00009c80)(param_1,param_2,0);
    }
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x11c);
    if ((uVar1 & 2) != 0) {
      ((int (*)())FUN_0000a110)(param_1,param_2,1);
      uVar1 = *(uint *)(param_1 + 0x11c);
    }
    if ((uVar1 & 4) != 0) {
      ((int (*)())FUN_00009c80)(param_1,param_2,1);
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + iVar7 + 0x56c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + iVar7 + 0x570) = 0;
  uVar3 = *param_3;
  uVar4 = param_3[1];
  uVar5 = param_3[3];
  iVar7 = FUN_00003350(param_1,param_1 + 0xa1c,*(undefined4 *)(param_1 + 0xa80),uVar3,uVar4,uVar5,
                       param_3[6]);
  uVar6 = 0xfffffffd;
  if (iVar7 != 0) {
    return 0xfffffffd;
  }
  ((int (*)())FUN_00003cd0)(param_1,0x11);
  uVar1 = param_3[3];
  if (uVar1 != 0x61726762) {
    if (uVar1 < 0x61726763) {
      if (uVar1 == 0x32767579) {
LAB_000041b8:
        ((int (*)())FUN_0000aa00)(param_1,param_2,param_3);
        goto LAB_000041dc;
      }
      if (uVar1 != 0x61723135) goto LAB_000041dc;
    }
    else if (uVar1 != 0x72676261) {
      if (uVar1 != 0x79757673) goto LAB_000041dc;
      goto LAB_000041b8;
    }
  }
  ((int (*)())FUN_0000a4e0)(param_1,param_2,param_3);
LAB_000041dc:
  FUN_00002d00(param_1,0,*(undefined4 *)(param_1 + 0xac4));
  ((int (*)())FUN_0000bf70)(param_1,param_3[6],param_3[1] * param_3[2],uVar3,uVar4,uVar5,uVar6,param_8);
  FUN_000029c0(param_1,0x11);
  FUN_00002930(param_1,param_1 + 0xa1c,0);
  uVar3 = *(undefined4 *)(param_1 + 0xac4);
  *param_4 = 0;
  param_4[1] = uVar3;
  *(uint *)(param_1 + 0xac4) = (*(int *)(param_1 + 0xac4) + 1U) % 10000;
  return 0;
}

/* FUN_00004280 @ 0x4280 (192 bytes) */
int FUN_00004280(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_3 + 0xcU & 0xff;
  *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + param_1 + 0x55c + 0x56c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + param_1 + 0x55c + 0x570) = 0;
  ((int (*)())FUN_00003cd0)(param_1,uVar1);
  ((int (*)())FUN_00009690)(param_1,param_2,param_3);
  FUN_000029c0(param_1,uVar1);
  uVar2 = *(undefined4 *)(param_1 + 0xac4);
  *param_4 = 0;
  param_4[1] = uVar2;
  *(uint *)(param_1 + 0xac4) = (*(int *)(param_1 + 0xac4) + 1U) % 10000;
  return 0;
}

/* FUN_00004340 @ 0x4340 (988 bytes) */
int FUN_00004340(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint param_3;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r4;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  undefined4 *puVar15;
  int iVar16;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  
  iVar13 = param_1 + 0x55c;
  uVar14 = *(uint *)(param_1 + 0x54);
  if ((uVar14 != param_3) || (uVar14 == 0)) {
    return 0xfffffff9;
  }
  if (uVar14 < 6) {
    uVar9 = *(int *)*param_2 + 0xf;
    uVar7 = uVar9 & 0xfffffff0;
    *(uint *)(param_1 + 0x578) = uVar7;
    uVar2 = *(int *)(*param_2 + 4) + 0xf;
    *(uint *)(param_1 + 0x57c) = uVar2 & 0xfffffff0;
    if ((uVar9 & 0xf0) != 0) {
      uVar7 = (uVar9 & 0xffffff00) + 0x100;
    }
    *(uint *)(param_1 + 0x588) = uVar7;
    *(uint *)(param_1 + 0x580) = uVar9 >> 4;
    *(uint *)(param_1 + 0x584) = uVar2 >> 4;
    iVar11 = 0;
    *(undefined2 *)(param_1 + 0x126) = 0;
    piVar12 = (int *)(param_1 + 0x14430);
    *(undefined2 *)(param_1 + 0x124) = 0;
    *(short *)(param_1 + 0x12a) = (short)*(undefined4 *)(param_1 + 0x578);
    *(short *)(param_1 + 0x128) = (short)*(undefined4 *)(param_1 + 0x57c);
    *(int *)(param_1 + 0x14424) = *(int *)(param_1 + 0x580) * *(int *)(param_1 + 0x584);
    do {
      iVar3 = _malloc(*(int *)(param_1 + 0x14424) << 2);
      *piVar12 = iVar3;
      if (iVar3 == 0) {
        if (0 < iVar11) {
          puVar15 = (undefined4 *)(param_1 + 0x14430);
          iVar13 = 0;
          do {
            uVar4 = *puVar15;
            iVar13 = iVar13 + 1;
            puVar15 = puVar15 + 3;
            _free(uVar4);
          } while (iVar13 != iVar11);
        }
        goto LAB_00004448;
      }
      bVar1 = iVar11 != 0x18;
      piVar12 = piVar12 + 3;
      iVar11 = iVar11 + 1;
    } while (bVar1);
    uVar2 = *(uint *)(param_1 + 0xa84);
    iVar11 = 0;
    uVar7 = uVar14;
    do {
      uVar9 = iVar11 + 10;
      iVar11 = iVar11 + 1;
      uVar2 = uVar2 | 1 << (uVar9 & 0x3f);
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
    *(uint *)(param_1 + 0xa84) = uVar2;
    if ((uVar14 < 5) && ((int)uVar14 < 5)) {
      uVar7 = uVar14 + 10;
      iVar11 = 0xf - uVar7;
      do {
        uVar9 = uVar7 & 0x3f;
        uVar7 = uVar7 + 1;
        uVar2 = uVar2 & ~(1 << uVar9);
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      *(uint *)(param_1 + 0xa84) = uVar2;
    }
    local_40 = *(undefined4 *)(param_1 + 0x578);
    local_3c = *(undefined4 *)(param_1 + 0x57c);
    local_34 = *(uint *)(param_1 + 0xa84) | 0x20000;
    *(uint *)(param_1 + 0xa84) = local_34;
    local_38 = 0;
    local_48 = 0;
    local_44 = 0;
    iVar11 = _io_connect_method_scalarI_scalarO
                       (*(undefined4 *)(param_1 + 0x14),0x15,&local_44,5,0,&local_48);
    if (iVar11 == 0) {
      local_44 = *(undefined4 *)(param_1 + 0xc);
      local_40 = *(uint *)(param_1 + 0x18) & 0xffff4000;
      local_3c = 1;
      iVar11 = _io_connect_method_scalarI_structureI
                         (*(undefined4 *)(param_1 + 0x14),0,&local_44,3,0,0);
      if (iVar11 == 0) {
        *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x578);
        *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x57c);
        iVar11 = FUN_00003350(param_1,param_1 + 0x1518c,*(undefined4 *)(param_1 + 0x151f0),
                              *(uint *)(param_1 + 0x578) >> 4,
                              (*(uint *)(param_1 + 0x57c) >> 1 & 0x7ffffff8) *
                              *(int *)(param_1 + 0x54),0x20,0);
        if (iVar11 == 0) {
          iVar11 = 0;
          iVar8 = param_1 + 0x151ec;
          iVar3 = param_1 + 0x1523c;
          *(undefined4 *)(param_1 + 0x58c) = *(undefined4 *)(param_1 + 0x151a4);
          uVar7 = *(uint *)(param_1 + 0x57c) >> 4;
          uVar2 = *(int *)(param_1 + 0x1518c) + 0xffU & 0xffffff00;
          do {
            puVar10 = (uint *)(iVar8 + 8);
            iVar16 = 4;
            do {
              *puVar10 = uVar2;
              puVar10 = puVar10 + 1;
              uVar2 = uVar2 + (uVar7 * *(int *)(param_1 + 0x151a4) & 0xfffffffc);
              iVar16 = iVar16 + -1;
            } while (iVar16 != 0);
            puVar10 = (uint *)(iVar3 + 8);
            iVar16 = 4;
            do {
              *puVar10 = uVar2;
              puVar10 = puVar10 + 1;
              uVar2 = uVar2 + (uVar7 * *(int *)(param_1 + 0x151a4) & 0xfffffffc);
              iVar16 = iVar16 + -1;
            } while (iVar16 != 0);
            bVar1 = iVar11 != 4;
            iVar8 = iVar8 + 0x10;
            iVar3 = iVar3 + 0x10;
            iVar11 = iVar11 + 1;
          } while (bVar1);
          ((int (*)())FUN_00003cd0)(param_1,0);
          uVar4 = *(undefined4 *)(param_1 + 0x153f8);
          uVar5 = 0x20;
          uVar6 = 0;
          uVar7 = *(uint *)(param_1 + 0x578) >> 4;
          iVar3 = (*(uint *)(param_1 + 0x57c) >> 4) * 0x18;
          iVar11 = FUN_00003350(param_1,param_1 + 0x15394,uVar4,uVar7,iVar3,0x20,0);
          if (iVar11 == 0) {
            fparam_1 = (double)((int (*)())FUN_00003cd0)(param_1,1);
            ((void (*)())FUN_00006d90)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                         in_stack_ffffff88,in_stack_ffffff90);
            ((int (*)())FUN_00005d70)(param_1,extraout_r4,uVar4,uVar7,iVar3,uVar5,uVar6,iVar8);
            DAT_0000f1a8 = *(undefined4 *)(param_1 + 0x578);
            DAT_0000f1a4 = *(undefined4 *)(param_1 + 0x57c);
            do {
              *(undefined4 *)(iVar13 + 0x38) = *(undefined4 *)(param_1 + 0x578);
              *(undefined4 *)(iVar13 + 0x3c) = *(undefined4 *)(param_1 + 0x57c);
              uVar4 = *(undefined4 *)(param_1 + 0x588);
              *(undefined4 *)(iVar13 + 0x44) = 0x59563132;
              *(undefined4 *)(iVar13 + 0x54) = 1;
              *(undefined4 *)(iVar13 + 0x40) = uVar4;
              iVar13 = iVar13 + 0x40;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
            return 0;
          }
        }
        goto LAB_00004448;
      }
    }
    uVar4 = 0xfffffffb;
  }
  else {
LAB_00004448:
    uVar4 = 0xfffffffd;
  }
  return uVar4;
}

/* FUN_00004740 @ 0x4740 (664 bytes) */
int FUN_00004740(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 *param_4;
  int param_5;
{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  
  iVar6 = param_2 * 4;
  iVar7 = param_1 + 0x55c;
  iVar3 = iVar6 + iVar7;
  if (*(int *)(iVar3 + 0x52c) != 0) {
    return;
  }
  if (*(int *)(iVar3 + 0x554) == 0) {
    if (*(int *)(param_1 + 0x120) != 0) {
      if (*(int *)(iVar3 + 0x540) == 1) {
        if (*(int *)(param_1 + 0x120) == 4) {
          ((int (*)())FUN_0000caa0)(param_1,param_1 + 0x14348 + param_2 * 0x14,param_1 + 0x143ac + param_2 * 0x18
                       ,1);
        }
        ((int (*)())FUN_0000caa0)(param_1,param_2 * 0x14 + param_1 + 0x14348,param_2 * 0x18 + param_1 + 0x143ac,2
                    );
        *(undefined4 *)(iVar6 + iVar7 + 0x554) = 1;
        goto LAB_00004810;
      }
      goto LAB_0000481c;
    }
  }
  else {
LAB_00004810:
    if (*(int *)(param_1 + 0x120) != 0) {
LAB_0000481c:
      if (*(int *)(iVar6 + iVar7 + 0x554) != 0) {
        uVar2 = *(uint *)(param_1 + 0x11c);
        if ((uVar2 & 2) != 0) {
          ((int (*)())FUN_0000a110)(param_1,param_2,1);
          uVar2 = *(uint *)(param_1 + 0x11c);
        }
        if ((uVar2 & 4) != 0) {
          ((int (*)())FUN_00009c80)(param_1,param_2,1);
        }
        fparam_1 = (double)((int (*)())FUN_0000b7f0)(param_1,param_2,1);
        goto LAB_000048e0;
      }
    }
  }
  uVar2 = *(uint *)(param_1 + 0x11c);
  if ((uVar2 & 2) != 0) {
    ((int (*)())FUN_0000a110)(param_1,param_2,0);
    uVar2 = *(uint *)(param_1 + 0x11c);
  }
  if ((uVar2 & 4) != 0) {
    ((int (*)())FUN_00009c80)(param_1,param_2,0);
  }
  fparam_1 = (double)((int (*)())FUN_0000b7f0)(param_1,param_2,0);
LAB_000048e0:
  *(int *)(param_1 + 0x118) = param_5;
  if (param_5 != 0) {
    *(undefined4 *)(param_1 + 0x114) = param_3;
    uVar4 = *param_4;
    *(undefined4 *)(param_1 + 0x110) = param_4[1];
    *(undefined4 *)(param_1 + 0x10c) = uVar4;
    ((void (*)())FUN_0000ae80)(param_1,fparam_1,in_f2,in_f3,in_f4);
  }
  puVar5 = *(uint **)(param_1 + 0x30);
  *puVar5 = *(int *)(param_1 + 0x34) - (int)puVar5 >> 2 | *puVar5;
  puVar1 = PTR_0000f1a0;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x2000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar6 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar6 + 0x20;
  *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
  *(undefined4 *)(iVar6 + 0x1c) = 0;
  if ((*(uint *)(*(int *)(param_1 + 0x40) + 0x14) & 2) == 0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0xc))
            (*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
             *(undefined4 *)(param_1 + 0xc));
  return;
}

/* FUN_000049f0 @ 0x49f0 (4 bytes) */
int FUN_000049f0()
{
  return;
}

/* FUN_00004a00 @ 0x4a00 (4 bytes) */
int FUN_00004a00()
{
  return;
}

/* FUN_00004a10 @ 0x4a10 (296 bytes) */
int FUN_00004a10(param_1, param_2, param_3, param_4)
  int param_1;
  char *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = param_1 + 0x55c;
  *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + iVar6 + 0x56c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + iVar6 + 0x570) = 0;
  uVar1 = *(undefined4 *)param_2;
  uVar5 = *(undefined4 *)(param_2 + 8);
  uVar4 = *(undefined4 *)(param_2 + 0xc);
  uVar3 = *(undefined4 *)(param_1 + 0xac4);
  iVar2 = *param_2 * 0x14 + iVar6;
  *(undefined4 *)(iVar2 + 0x13df0) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(iVar2 + 0x13dec) = uVar1;
  *(undefined4 *)(iVar2 + 0x13df4) = uVar5;
  *(undefined4 *)(iVar2 + 0x13df8) = uVar4;
  *(undefined4 *)(iVar2 + 0x13dfc) = *(undefined4 *)(param_2 + 0x10);
  uVar5 = param_3[1];
  uVar4 = param_3[2];
  uVar1 = param_3[3];
  iVar2 = *param_2 * 0x18 + iVar6;
  *(undefined4 *)(iVar2 + 0x13e50) = *param_3;
  *(undefined4 *)(iVar2 + 0x13e54) = uVar5;
  *(undefined4 *)(iVar2 + 0x13e58) = uVar4;
  *(undefined4 *)(iVar2 + 0x13e5c) = uVar1;
  uVar1 = param_3[4];
  *(undefined4 *)(iVar2 + 0x13e64) = param_3[5];
  *(undefined4 *)(iVar2 + 0x13e60) = uVar1;
  *(undefined4 *)(*param_2 * 4 + iVar6 + 0x540) = 1;
  param_4[1] = uVar3;
  *param_4 = 0;
  *(uint *)(param_1 + 0xac4) = (*(int *)(param_1 + 0xac4) + 1U) % 10000;
  return 0;
}

/* FUN_00004b40 @ 0x4b40 (1116 bytes) */
int FUN_00004b40(param_1)
  int param_1;
{
  undefined *puVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  puVar1 = PTR_0000f1a0;
  if (*(int *)(param_1 + 0x54) != 0) {
    uVar7 = 0;
    iVar6 = param_1 + 0x40;
    iVar5 = param_1 + 0x44;
    do {
      puVar4 = *(undefined4 **)(param_1 + 0x34);
      if (*(undefined4 **)(param_1 + 0x38) <= puVar4 + 0x10) {
        puVar3 = *(uint **)(param_1 + 0x30);
        *puVar3 = (int)puVar4 - (int)puVar3 >> 2 | *puVar3;
        *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
        **(undefined4 **)(param_1 + 0x34) = 0x1000000;
        _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,iVar6,iVar5,1);
        iVar2 = *(int *)(param_1 + 0x40);
        *(int *)(param_1 + 0x34) = iVar2 + 0x20;
        *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
        *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
        *(undefined4 *)(iVar2 + 0x1c) = 0;
        puVar4 = *(undefined4 **)(param_1 + 0x34);
      }
      puVar3 = *(uint **)(param_1 + 0x30);
      *(undefined4 **)(param_1 + 0x34) = puVar4 + 0x10;
      *puVar3 = (int)puVar4 - (int)puVar3 >> 2 | *puVar3;
      *(undefined4 **)(param_1 + 0x30) = puVar4;
      *puVar4 = 0x5000000;
      puVar4[1] = uVar7;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4 = *(undefined4 **)(param_1 + 0x34);
      if (*(undefined4 **)(param_1 + 0x38) <= puVar4 + 0x10) {
        puVar3 = *(uint **)(param_1 + 0x30);
        *puVar3 = (int)puVar4 - (int)puVar3 >> 2 | *puVar3;
        *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
        **(undefined4 **)(param_1 + 0x34) = 0x1000000;
        _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,iVar6,iVar5,1);
        iVar2 = *(int *)(param_1 + 0x40);
        *(int *)(param_1 + 0x34) = iVar2 + 0x20;
        *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
        *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
        *(undefined4 *)(iVar2 + 0x1c) = 0;
        puVar4 = *(undefined4 **)(param_1 + 0x34);
      }
      puVar3 = *(uint **)(param_1 + 0x30);
      *(undefined4 **)(param_1 + 0x34) = puVar4 + 0x10;
      *puVar3 = (int)puVar4 - (int)puVar3 >> 2 | *puVar3;
      *(undefined4 **)(param_1 + 0x30) = puVar4;
      *puVar4 = 0x6000000;
      puVar4[1] = uVar7;
      puVar4[2] = 0;
      puVar4[3] = 0x80;
      if ((*(uint *)(param_1 + 0x11c) & 1) != 0) {
        puVar4 = *(undefined4 **)(param_1 + 0x34);
        if (*(undefined4 **)(param_1 + 0x38) <= puVar4 + 0x10) {
          puVar3 = *(uint **)(param_1 + 0x30);
          *puVar3 = (int)puVar4 - (int)puVar3 >> 2 | *puVar3;
          *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
          **(undefined4 **)(param_1 + 0x34) = 0x1000000;
          _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,iVar6,iVar5,1)
          ;
          iVar2 = *(int *)(param_1 + 0x40);
          *(int *)(param_1 + 0x34) = iVar2 + 0x20;
          *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
          *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
          *(undefined4 *)(iVar2 + 0x1c) = 0;
          puVar4 = *(undefined4 **)(param_1 + 0x34);
        }
        puVar3 = *(uint **)(param_1 + 0x30);
        *(undefined4 **)(param_1 + 0x34) = puVar4 + 0x10;
        *puVar3 = (int)puVar4 - (int)puVar3 >> 2 | *puVar3;
        *(undefined4 **)(param_1 + 0x30) = puVar4;
        *puVar4 = 0x5000000;
        puVar4[1] = uVar7;
        puVar4[2] = 1;
        puVar4[3] = 0;
        puVar4 = *(undefined4 **)(param_1 + 0x34);
        if (*(undefined4 **)(param_1 + 0x38) <= puVar4 + 0x10) {
          puVar3 = *(uint **)(param_1 + 0x30);
          *puVar3 = (int)puVar4 - (int)puVar3 >> 2 | *puVar3;
          *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
          **(undefined4 **)(param_1 + 0x34) = 0x1000000;
          _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,iVar6,iVar5,1)
          ;
          iVar2 = *(int *)(param_1 + 0x40);
          *(int *)(param_1 + 0x34) = iVar2 + 0x20;
          *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
          *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
          *(undefined4 *)(iVar2 + 0x1c) = 0;
          puVar4 = *(undefined4 **)(param_1 + 0x34);
        }
        puVar3 = *(uint **)(param_1 + 0x30);
        *(undefined4 **)(param_1 + 0x34) = puVar4 + 0x10;
        *puVar3 = (int)puVar4 - (int)puVar3 >> 2 | *puVar3;
        *(undefined4 **)(param_1 + 0x30) = puVar4;
        *puVar4 = 0x6000000;
        puVar4[1] = uVar7;
        puVar4[2] = 1;
        puVar4[3] = 0x80;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_1 + 0x54));
  }
  puVar1 = PTR_0000f1a0;
  puVar3 = *(uint **)(param_1 + 0x30);
  *puVar3 = *(int *)(param_1 + 0x34) - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar5 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar5 + 0x20;
  *(int *)(param_1 + 0x30) = iVar5 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar5 + 0x20 + *(int *)(iVar5 + 0x10) * 4;
  *(undefined4 *)(iVar5 + 0x1c) = 0;
  ((int (*)())FUN_00004740)(param_1,0,(int)(char)*(undefined4 *)(param_1 + 0x114),param_1 + 0x10c,0);
  return;
}

/* FUN_00004fa0 @ 0x4fa0 (552 bytes) */
int FUN_00004fa0(param_1, param_2)
  int param_1;
  uint *param_2;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_48;
  int local_44;
  uint local_40;
  undefined4 local_3c;
  int local_38;
  uint local_34;
  
  uVar3 = *param_2;
  *(uint *)(param_1 + 0x5c) = uVar3;
  if (uVar3 < 9) {
    *(undefined4 *)(param_1 + 0x60) = 0x2d0;
    if ((*(int *)(param_1 + 0x57c) == 0x240) || (*(int *)(param_1 + 0x57c) == 0x120)) {
      *(undefined4 *)(param_1 + 100) = 0x240;
    }
    else {
      *(undefined4 *)(param_1 + 100) = 0x1e0;
    }
    uVar3 = *(uint *)(param_1 + 0x60);
    if ((uVar3 & 0xff) != 0) {
      uVar3 = (uVar3 & 0xffffff00) + 0x100;
    }
    iVar4 = *(int *)(param_1 + 0x5c);
    *(uint *)(param_1 + 0x68) = uVar3;
    if (iVar4 != 0) {
      iVar2 = param_1;
      iVar6 = iVar4;
      if (iVar4 == 0) {
        iVar6 = 1;
      }
      do {
        *(uint *)(iVar2 + 0x6c) = param_2[0x15];
        param_2 = param_2 + 1;
        *(uint *)(iVar2 + 0xbc) = *param_2;
        iVar2 = iVar2 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    uVar3 = 0;
    if (iVar4 != 0) {
      uVar5 = 0;
      iVar2 = param_1 + 0x218;
      iVar4 = param_1;
      do {
        iVar6 = FUN_00003350(param_1,iVar2,*(undefined4 *)(iVar4 + 0x538),0xc0,
                             *(undefined4 *)(param_1 + 100),8,*(undefined4 *)(iVar4 + 0x6c));
        if (iVar6 != 0) goto LAB_000051c0;
        uVar3 = *(uint *)(param_1 + 0x5c);
        uVar5 = uVar5 + 1;
        iVar2 = iVar2 + 100;
        iVar4 = iVar4 + 4;
      } while (uVar5 < uVar3);
    }
    local_48 = FUN_00003350(param_1,param_1 + 0x1b0,*(undefined4 *)(param_1 + 0x214),0x20,uVar3,0x20
                            ,0);
    if (local_48 == 0) {
      ((int (*)())FUN_00003cd0)(param_1,3);
      local_3c = *(undefined4 *)(param_1 + 0x57c);
      local_40 = *(undefined4 *)(param_1 + 0x578);
      local_34 = *(uint *)(param_1 + 0xa84) | 0x10000;
      *(uint *)(param_1 + 0xa84) = local_34;
      local_44 = local_48;
      local_38 = local_48;
      iVar4 = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(param_1 + 0x14),0x15,&local_44,5,0,&local_48);
      if (iVar4 == 0) {
        local_44 = *(int *)(param_1 + 0xc);
        local_40 = *(uint *)(param_1 + 0x18) & 0xffff4000;
        local_3c = 1;
        iVar4 = _io_connect_method_scalarI_structureI
                          (*(undefined4 *)(param_1 + 0x14),0,&local_44,3,0,0);
        if (iVar4 == 0) {
          return 0;
        }
      }
      uVar1 = 0xfffffffb;
    }
    else {
LAB_000051c0:
      uVar1 = 0xfffffffd;
    }
  }
  else {
    _puts("Number of subpicture bitmap exceed the maximum set.");
    uVar1 = 0xfffffffd;
  }
  return uVar1;
}

/* FUN_000051f0 @ 0x51f0 (136 bytes) */
int FUN_000051f0(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  
  FUN_000029c0(param_1,3);
  FUN_00002930(param_1,param_1 + 0x1b0,1);
  if (*(int *)(param_1 + 0x5c) != 0) {
    uVar1 = 0;
    iVar2 = param_1 + 0x218;
    do {
      uVar1 = uVar1 + 1;
      FUN_00002930(param_1,iVar2,0);
      iVar2 = iVar2 + 100;
    } while (uVar1 < *(uint *)(param_1 + 0x5c));
  }
  return 0;
}

/* FUN_00005280 @ 0x5280 (108 bytes) */
int FUN_00005280(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_28 = 0;
  local_24 = 0x92;
  local_20 = param_2;
  iVar2 = _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(param_1 + 0x14),0x10,&local_24,2,0,&local_28);
  uVar1 = 0xfffffffb;
  if ((iVar2 != -0x11) && (uVar1 = 0xfffffff9, iVar2 != -0x32)) {
    uVar1 = 0;
  }
  return uVar1;
}

/* FUN_000052f0 @ 0x52f0 (924 bytes) */
int FUN_000052f0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  byte *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  uint uVar1;
  undefined *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  byte bVar11;
  int iVar9;
  uint *puVar10;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint local_48 [10];
  
  puVar2 = PTR_0000f1a0;
  bVar11 = *param_2;
  if (*(int *)(param_1 + 0x558) != (int)(char)bVar11) {
    puVar12 = *(undefined4 **)(param_1 + 0x34);
    if (*(undefined4 **)(param_1 + 0x38) <= puVar12 + 0x10) {
      puVar3 = *(uint **)(param_1 + 0x30);
      *puVar3 = (int)puVar12 - (int)puVar3 >> 2 | *puVar3;
      *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
      **(undefined4 **)(param_1 + 0x34) = 0x1000000;
      _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar2,param_1 + 0x40,
                          param_1 + 0x44,1);
      iVar8 = *(int *)(param_1 + 0x40);
      *(int *)(param_1 + 0x34) = iVar8 + 0x20;
      *(int *)(param_1 + 0x30) = iVar8 + 0x1c;
      *(int *)(param_1 + 0x38) = iVar8 + 0x20 + *(int *)(iVar8 + 0x10) * 4;
      *(undefined4 *)(iVar8 + 0x1c) = 0;
      puVar12 = *(undefined4 **)(param_1 + 0x34);
    }
    puVar3 = *(uint **)(param_1 + 0x30);
    *(undefined4 **)(param_1 + 0x34) = puVar12 + 0x10;
    *puVar3 = (int)puVar12 - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(param_1 + 0x30) = puVar12;
    *puVar12 = 0xd000000;
    puVar12[1] = 2;
    puVar12[2] = 1;
    puVar2 = PTR_0000f1a0;
    puVar3 = *(uint **)(param_1 + 0x30);
    *puVar3 = *(int *)(param_1 + 0x34) - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar2,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar8 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar8 + 0x20;
    *(int *)(param_1 + 0x30) = iVar8 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar8 + 0x20 + *(int *)(iVar8 + 0x10) * 4;
    *(undefined4 *)(iVar8 + 0x1c) = 0;
    bVar11 = *param_2;
  }
  *(int *)(param_1 + 0x558) = (int)(char)bVar11;
  uVar4 = *(undefined4 *)(param_2 + 0x12);
  *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(param_2 + 0x16);
  *(undefined4 *)(param_1 + 0x10c) = uVar4;
  iVar8 = (int)*(short *)(param_2 + 2);
  iVar15 = (int)*(short *)(param_2 + 6);
  uVar14 = *(uint *)(param_2 + 0x28);
  local_48[0] = *(uint *)(param_2 + 2);
  local_48[1] = *(uint *)(param_2 + 6);
  if ((((iVar15 - iVar8 < 1) || ((int)*(short *)(param_2 + 8) - (int)*(short *)(param_2 + 4) < 1))
      || (iVar15 < 0)) ||
     (((iVar8 < 0 || (*(short *)(param_2 + 8) < 0)) || (*(short *)(param_2 + 4) < 0)))) {
    uVar4 = 0xfffffff9;
  }
  else {
    iVar8 = *(int *)(param_2 + 0x2c);
    uVar13 = 0;
    puVar3 = local_48 + 2;
    iVar15 = 4;
    do {
      uVar6 = 0xff;
      uVar1 = uVar14 >> (uVar13 & 0x3f) & 0xf;
      iVar9 = iVar8 + (uVar14 >> (uVar13 + 0x10 & 0x3f) & 0xf) * 4;
      if (uVar1 != 0xf) {
        uVar6 = uVar1 * 0xf;
      }
      *(uint *)(uVar13 + (int)puVar3) =
           uVar6 | (uint)*(byte *)(iVar9 + 3) << 0x18 | (uint)*(byte *)(iVar9 + 2) << 0x10 |
                   (uint)*(byte *)(iVar9 + 1) << 8;
      uVar13 = uVar13 + 4;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    uVar4 = 0x10;
    uVar14 = 0;
    puVar7 = local_48;
    iVar8 = 0x10;
    DAT_0000f1ac = (DAT_0000f1ac + 1U) -
                   ((DAT_0000f1ac + 1U) / *(uint *)(param_1 + 0x5c)) * *(uint *)(param_1 + 0x5c);
    puVar12 = (undefined4 *)((*(int *)(param_1 + 0x1b0) + 0xffU & 0xffffff00) + DAT_0000f1ac * 0x80)
    ;
    do {
      puVar5 = puVar12;
      uVar13 = uVar14 & 0xfffffffc;
      uVar1 = uVar14 & 3;
      uVar14 = uVar14 + 1;
      puVar10 = puVar7 + uVar1;
      *puVar5 = *(undefined4 *)((int)local_48 + uVar13 + 8);
      puVar5[1] = local_48[uVar1 + 2];
      iVar8 = iVar8 + -1;
      puVar12 = puVar5 + 2;
    } while (iVar8 != 0);
    ((int (*)())FUN_0000bf20)(param_1,puVar5 + -0x1e,0x80,puVar3,0x10,puVar7,puVar10,uVar14);
    ((int (*)())FUN_0000bf20)(param_1,*(undefined4 *)((char)*param_2 * 4 + param_1 + 0x6c),
                 *(int *)(param_1 + 100) * 0xc0,puVar3,uVar4,puVar7,puVar10,uVar14);
    ((int (*)())FUN_00003cd0)(param_1,*param_2 + 4 & 0xff);
    ((int (*)())FUN_0000cb00)(param_1,local_48[0],local_48[1],(char)*param_2 + 4,DAT_0000f1ac);
    FUN_000029c0(param_1,*param_2 + 4 & 0xff);
    uVar4 = 0;
  }
  return uVar4;
}

/* FUN_000056a0 @ 0x56a0 (512 bytes) */
int FUN_000056a0(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined *puVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar1 = PTR_0000f1a0;
  if (param_2 == *(int *)(param_1 + 0x558)) {
    puVar4 = *(undefined4 **)(param_1 + 0x34);
    if (*(undefined4 **)(param_1 + 0x38) <= puVar4 + 0x10) {
      puVar2 = *(uint **)(param_1 + 0x30);
      *puVar2 = (int)puVar4 - (int)puVar2 >> 2 | *puVar2;
      *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
      **(undefined4 **)(param_1 + 0x34) = 0x1000000;
      _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,param_1 + 0x40,
                          param_1 + 0x44,1);
      iVar3 = *(int *)(param_1 + 0x40);
      *(int *)(param_1 + 0x34) = iVar3 + 0x20;
      *(int *)(param_1 + 0x30) = iVar3 + 0x1c;
      *(int *)(param_1 + 0x38) = iVar3 + 0x20 + *(int *)(iVar3 + 0x10) * 4;
      *(undefined4 *)(iVar3 + 0x1c) = 0;
      puVar4 = *(undefined4 **)(param_1 + 0x34);
    }
    puVar2 = *(uint **)(param_1 + 0x30);
    *(undefined4 **)(param_1 + 0x34) = puVar4 + 0x10;
    *puVar2 = (int)puVar4 - (int)puVar2 >> 2 | *puVar2;
    *(undefined4 **)(param_1 + 0x30) = puVar4;
    *puVar4 = 0xd000000;
    puVar4[1] = 2;
    puVar4[2] = 1;
    puVar4[3] = *(undefined4 *)(param_1 + 0x60);
    puVar4[4] = *(undefined4 *)(param_1 + 100);
    puVar4[5] = *(undefined4 *)(param_1 + 0x68);
    puVar1 = PTR_0000f1a0;
    puVar2 = *(uint **)(param_1 + 0x30);
    *puVar2 = *(int *)(param_1 + 0x34) - (int)puVar2 >> 2 | *puVar2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar3 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar3 + 0x20;
    *(int *)(param_1 + 0x30) = iVar3 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar3 + 0x20 + *(int *)(iVar3 + 0x10) * 4;
    *(undefined4 *)(iVar3 + 0x1c) = 0;
  }
  if ((*(uint *)(*(int *)(param_1 + 0x40) + 0x14) & 2) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0xc))
              (*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(param_1 + 0xc));
  }
  return 0;
}

/* FUN_000058b0 @ 0x58b0 (1196 bytes) */
int FUN_000058b0(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x40);
  iVar4 = *(int *)(param_1 + 0x48);
  *(int *)(param_1 + 0x34) = iVar2 + 0x20;
  *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  iVar2 = *(int *)(param_1 + 0x14554) + 0x20;
  iVar1 = *(int *)(param_1 + 0x1455c) + 0x20;
  *(int *)(param_1 + 0x1511c) = iVar2;
  *(int *)(param_1 + 0x15124) = iVar2;
  iVar3 = *(int *)(*(int *)(param_1 + 0x14554) + 0x10);
  *(int *)(param_1 + 0x15140) = iVar1;
  *(int *)(param_1 + 0x15148) = iVar1;
  *(int *)(param_1 + 0x15120) = iVar3 * 4 + iVar2 + -4;
  *(int *)(param_1 + 0x15144) = *(int *)(*(int *)(param_1 + 0x1455c) + 0x10) * 4 + iVar1 + -4;
  *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | 1;
  *(undefined4 *)(iVar4 + 0x20) = 0x10a4;
  *(undefined4 *)(iVar4 + 0x24) = 0;
  *(undefined4 *)(iVar4 + 0x28) = 0x10a3;
  *(undefined4 *)(iVar4 + 0x2c) = 5;
  *(undefined4 *)(iVar4 + 0x30) = 0x10a2;
  *(undefined4 *)(iVar4 + 0x34) = 0;
  *(undefined4 *)(iVar4 + 0x38) = 0x850;
  *(undefined4 *)(iVar4 + 0x3c) = 0x102;
  *(undefined4 *)(iVar4 + 0x40) = 0x8a1;
  *(undefined4 *)(iVar4 + 0x44) = 0;
  *(undefined4 *)(iVar4 + 0x48) = 0x820;
  *(undefined4 *)(iVar4 + 0x4c) = 0x300856;
  *(undefined4 *)(iVar4 + 0x50) = 0x887;
  *(undefined4 *)(iVar4 + 0x54) = 0x10000;
  *(undefined4 *)(iVar4 + 0x58) = 0x82c;
  *(undefined4 *)(iVar4 + 0x5c) = 0x300;
  *(undefined4 *)(iVar4 + 0x60) = 0x84d;
  *(undefined4 *)(iVar4 + 100) = 0xffff;
  *(undefined4 *)(iVar4 + 0x68) = 0x84e;
  *(undefined4 *)(iVar4 + 0x6c) = 0;
  *(undefined4 *)(iVar4 + 0x70) = 0x877;
  *(undefined4 *)(iVar4 + 0x74) = 0;
  *(undefined4 *)(iVar4 + 0x78) = 0x888;
  *(undefined4 *)(iVar4 + 0x7c) = 0x3f800000;
  *(undefined4 *)(iVar4 + 0x80) = 0x889;
  *(undefined4 *)(iVar4 + 0x84) = 0x3f800000;
  *(undefined4 *)(iVar4 + 0x88) = 0x88a;
  *(undefined4 *)(iVar4 + 0x8c) = 0x3f800000;
  *(undefined4 *)(iVar4 + 0x90) = 0x88b;
  *(undefined4 *)(iVar4 + 0x94) = 0x3f800000;
  *(undefined **)(iVar4 + 0x98) = ((unsigned char *)0x00001002);
  *(undefined4 *)(iVar4 + 0x9c) = 0;
  *(undefined **)(iVar4 + 0xa0) = ((unsigned char *)0x00001008);
  *(undefined4 *)(iVar4 + 0xa4) = 0;
  *(undefined **)(iVar4 + 0xa8) = ((unsigned char *)0x00001004);
  *(undefined4 *)(iVar4 + 0xac) = 0x78888888;
  *(undefined **)(iVar4 + 0xb0) = ((unsigned char *)0x00001005);
  *(undefined4 *)(iVar4 + 0xb4) = 0x8888888;
  *(undefined4 *)(iVar4 + 0xb8) = 0x10a8;
  *(undefined4 *)(iVar4 + 0xbc) = 0;
  *(undefined4 *)(iVar4 + 0xc0) = 0x10ae;
  *(undefined4 *)(iVar4 + 0xc4) = 0;
  *(undefined4 *)(iVar4 + 200) = 0x12f5;
  *(undefined4 *)(iVar4 + 0xcc) = 0;
  *(undefined4 *)(iVar4 + 0xd0) = 0x1394;
  *(undefined4 *)(iVar4 + 0xd4) = 0;
  *(undefined4 *)(iVar4 + 0xd8) = 0x12f0;
  *(undefined4 *)(iVar4 + 0xdc) = 0;
  *(undefined4 *)(iVar4 + 0xe0) = 0x13c0;
  *(undefined4 *)(iVar4 + 0xe4) = 0;
  *(undefined4 *)(iVar4 + 0xe8) = 0x13c7;
  *(undefined4 *)(iVar4 + 0xec) = 0;
  *(undefined4 *)(iVar4 + 0xf0) = 0x1381;
  *(undefined4 *)(iVar4 + 0xf4) = 0;
  *(undefined4 *)(iVar4 + 0xf8) = 0x1383;
  *(undefined4 *)(iVar4 + 0xfc) = 0xf;
  *(undefined4 *)(iVar4 + 0x100) = 0x1386;
  *(undefined4 *)(iVar4 + 0x104) = 0;
  *(undefined4 *)(iVar4 + 0x108) = 0x10e9;
  *(undefined4 *)(iVar4 + 0x10c) = 0;
  *(undefined4 *)(iVar4 + 0x110) = 0x10ea;
  *(undefined4 *)(iVar4 + 0x114) = 0xa5294a5;
  *(undefined4 *)(iVar4 + 0x118) = 0x10f8;
  *(undefined4 *)(iVar4 + 0x11c) = 0;
  *(undefined4 *)(iVar4 + 0x120) = 0x10f9;
  *(undefined4 *)(iVar4 + 0x124) = 0x3ffffff;
  *(undefined4 *)(iVar4 + 0x128) = 0x10ec;
  *(undefined4 *)(iVar4 + 300) = 0;
  *(undefined4 *)(iVar4 + 0x130) = 0x10ed;
  *(undefined4 *)(iVar4 + 0x134) = 0x3ffffff;
  *(undefined4 *)(iVar4 + 0x138) = 0x10ee;
  *(undefined4 *)(iVar4 + 0x13c) = 0;
  *(undefined4 *)(iVar4 + 0x140) = 0x10ef;
  *(undefined4 *)(iVar4 + 0x144) = 0x3ffffff;
  *(undefined4 *)(iVar4 + 0x148) = 0x10f0;
  *(undefined4 *)(iVar4 + 0x14c) = 0;
  *(undefined4 *)(iVar4 + 0x150) = 0x10f1;
  *(undefined4 *)(iVar4 + 0x154) = 0x3ffffff;
  *(undefined4 *)(iVar4 + 0x158) = 0x10f2;
  *(undefined4 *)(iVar4 + 0x15c) = 0;
  *(undefined4 *)(iVar4 + 0x160) = 0x10f3;
  *(undefined4 *)(iVar4 + 0x164) = 0x3ffffff;
  *(undefined4 *)(iVar4 + 0x168) = 0x10f4;
  *(undefined4 *)(iVar4 + 0x16c) = 0xffff;
  *(undefined4 *)(iVar4 + 0x170) = 0x10fa;
  *(undefined4 *)(iVar4 + 0x174) = 0xffffff;
  *(undefined4 *)(iVar4 + 0x178) = 0x10fb;
  *(undefined4 *)(iVar4 + 0x17c) = 0;
  *(int *)(iVar4 + 0x14) = (iVar4 + 0x180) - (iVar4 + 0x20) >> 2;
  return;
}

/* FUN_00005d60 @ 0x5d60 (4 bytes) */
int FUN_00005d60()
{
  return;
}

/* FUN_00005d70 @ 0x5d70 (600 bytes) */
int FUN_00005d70(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  uint param_8;
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar10 = *(uint *)(param_1 + 0x57c);
  uVar5 = *(uint *)(param_1 + 0x578);
  puVar2 = (uint *)(*(int *)(param_1 + 0x15394) + 0xffU & 0xffffff00);
  if (uVar10 == 0) {
    uVar6 = 0;
    iVar1 = 0;
  }
  else {
    uVar4 = 0;
    uVar6 = 0;
    puVar7 = puVar2;
    do {
      puVar2 = puVar7;
      if (uVar5 != 0) {
        param_4 = uVar4 << 0x10;
        param_8 = 0;
        uVar9 = (uVar4 + 0x10) * 0x10000;
        uVar3 = param_4;
        uVar8 = uVar9;
        do {
          *(uint *)((int)puVar7 + param_8) = uVar3;
          param_8 = param_8 + 0x10;
          puVar2[1] = uVar8;
          uVar6 = uVar6 + 1;
          uVar8 = param_8 | uVar9;
          uVar3 = param_8 | param_4;
          puVar2[2] = uVar8;
          puVar2[3] = uVar3;
          puVar2 = puVar2 + 4;
        } while (param_8 < uVar5);
      }
      uVar4 = uVar4 + 0x10;
      puVar7 = puVar2;
    } while (uVar4 < uVar10);
    iVar1 = uVar6 << 2;
  }
  *(int *)(param_1 + 0x153fc) = iVar1;
  if (uVar10 != 0) {
    uVar4 = 0;
    puVar7 = puVar2;
    do {
      puVar2 = puVar7;
      if (uVar5 != 0) {
        param_4 = uVar4 << 0x10;
        param_8 = 0;
        uVar9 = (uVar4 + 8) * 0x10000;
        uVar3 = param_4;
        uVar8 = uVar9;
        do {
          *(uint *)((int)puVar7 + param_8) = uVar3;
          param_8 = param_8 + 0x10;
          puVar2[1] = uVar8;
          uVar6 = uVar6 + 1;
          uVar8 = param_8 | uVar9;
          uVar3 = param_8 | param_4;
          puVar2[2] = uVar8;
          puVar2[3] = uVar3;
          puVar2 = puVar2 + 4;
        } while (param_8 < uVar5);
      }
      uVar4 = uVar4 + 8;
      puVar7 = puVar2;
    } while (uVar4 < uVar10);
    iVar1 = uVar6 << 2;
  }
  uVar10 = uVar10 >> 1;
  uVar5 = uVar5 >> 1;
  *(int *)(param_1 + 0x15400) = iVar1;
  if (uVar10 != 0) {
    uVar4 = 0;
    do {
      if (uVar5 != 0) {
        param_4 = uVar4 << 0x10;
        uVar8 = 0;
        param_8 = (uVar4 + 8) * 0x10000;
        uVar9 = param_8;
        uVar3 = param_4;
        do {
          uVar8 = uVar8 + 8;
          *puVar2 = uVar3;
          puVar2[1] = uVar9;
          uVar3 = uVar8 | param_4;
          uVar9 = uVar8 | param_8;
          uVar6 = uVar6 + 1;
          puVar2[3] = uVar3;
          puVar2[2] = uVar9;
          puVar2 = puVar2 + 4;
        } while (uVar8 < uVar5);
      }
      uVar4 = uVar4 + 8;
    } while (uVar4 < uVar10);
    iVar1 = uVar6 << 2;
  }
  *(int *)(param_1 + 0x15404) = iVar1;
  if (uVar10 != 0) {
    param_4 = 0;
    do {
      if (uVar5 != 0) {
        uVar6 = param_4 << 0x10;
        uVar3 = 0;
        param_8 = (param_4 + 4) * 0x10000;
        uVar4 = param_8;
        uVar9 = uVar6;
        do {
          uVar3 = uVar3 + 8;
          *puVar2 = uVar9;
          puVar2[1] = uVar4;
          uVar9 = uVar3 | uVar6;
          uVar4 = uVar3 | param_8;
          puVar2[3] = uVar9;
          puVar2[2] = uVar4;
          puVar2 = puVar2 + 4;
        } while (uVar3 < uVar5);
      }
      param_4 = param_4 + 4;
    } while (param_4 < uVar10);
  }
  ((int (*)())FUN_0000bf20)(param_1,*(int *)(param_1 + 0x15394) + 0xffU & 0xffffff00,
               *(int *)(param_1 + 0x153a8) * *(int *)(param_1 + 0x153ac),param_4,uVar5,uVar6,puVar2,
               param_8);
  return;
}

/* FUN_00005fd0 @ 0x5fd0 (320 bytes) */
int FUN_00005fd0(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  uint local_40;
  undefined4 local_3c;
  uint local_30;
  
  bVar1 = param_2 != 0;
  local_58 = 0;
  if (bVar1) {
    local_44 = *(int *)(param_1 + 0x15148) - *(int *)(param_1 + 0x15140);
  }
  else {
    local_44 = *(int *)(param_1 + 0x15124) - *(int *)(param_1 + 0x1511c);
  }
  local_44 = local_44 >> 2;
  if (local_44 == 0) {
    return 1;
  }
  if (*(int *)(param_1 + 0x55c) == 3) {
    uVar4 = *(uint *)(param_1 + 0x57c);
    local_54 = 0;
  }
  else {
    local_54 = 1;
    uVar4 = *(uint *)(param_1 + 0x57c) >> 1;
    if (*(int *)(param_1 + 0x55c) == 2) {
      local_50 = 1;
      goto LAB_00006078;
    }
  }
  local_50 = 0;
LAB_00006078:
  local_4c = *(undefined4 *)(param_1 + 0x568);
  if (bVar1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x20;
  }
  local_40 = uVar2 | (*(byte *)(param_1 + 0x564) & 3) << 3 | 0x10080;
  if (bVar1) {
    local_3c = 0x8000;
  }
  else {
    local_3c = 0;
  }
  local_30 = uVar4 << 0x10 | *(uint *)(param_1 + 0x578);
  local_48 = param_2;
  iVar3 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 0x14),0x12,&local_54,0x38,0,&local_58);
  if (iVar3 == 0) {
    return 1;
  }
  return 0;
}

/* FUN_00006120 @ 0x6120 (252 bytes) */
int FUN_00006120(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = ((int (*)())FUN_00005fd0)(param_1,param_2);
  if (param_2 == 0) {
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),4,*(undefined4 *)PTR_0000f1a0,
                        param_1 + 0x14554,param_1 + 0x14558,1);
    iVar3 = *(int *)(param_1 + 0x14554);
    iVar1 = iVar3 + 0x20;
    *(int *)(param_1 + 0x1511c) = iVar1;
    *(int *)(param_1 + 0x15124) = iVar1;
    *(int *)(param_1 + 0x15120) = *(int *)(iVar3 + 0x10) * 4 + iVar1 + -4;
    *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + param_1 + 0xac8) = *(undefined4 *)(iVar3 + 0x18)
    ;
  }
  else {
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),5,*(undefined4 *)PTR_0000f1a0,
                        param_1 + 0x1455c,param_1 + 0x14560,1);
    iVar1 = *(int *)(param_1 + 0x1455c) + 0x20;
    *(int *)(param_1 + 0x15140) = iVar1;
    *(int *)(param_1 + 0x15148) = iVar1;
    *(int *)(param_1 + 0x15144) = *(int *)(*(int *)(param_1 + 0x1455c) + 0x10) * 4 + iVar1 + -4;
  }
  return uVar2;
}

/* FUN_00006230 @ 0x6230 (2900 bytes) */
int FUN_00006230(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  
  iVar7 = *(int *)(param_1 + 0x580);
  if (param_4 == 0) {
    uVar4 = *(uint *)(param_1 + 0x584);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x584) >> 1;
  }
  uVar1 = *(uint *)(param_1 + 0x58c) >> 2;
  if (param_3 == 1) {
    iVar8 = *(int *)(param_1 + 0x588);
    iVar10 = *(int *)(param_1 + 0x578);
    uVar9 = *(uint *)(param_1 + 0x57c);
    iVar6 = param_1 + 0x152b4;
    puVar2 = (undefined4 *)((int (*)())FUN_000096a0)(param_2);
    *puVar2 = 0x850;
    puVar2[1] = 0x102;
    puVar2[2] = 0x830;
    puVar2[3] = 2;
    puVar2[4] = 0x831;
    puVar2[5] = 0x1010101;
    puVar2[6] = 0x854;
    puVar2[7] = 0x26060006;
    puVar2[8] = 0x878;
    puVar2[9] = 0xf688f688;
    puVar2[10] = 0x824;
    puVar2[0xb] = 1;
    puVar2[0xc] = 0x825;
    puVar2[0xd] = 2;
    puVar2[0xe] = ((unsigned char *)0x0000101d);
    puVar2[0xf] = 0x28ffe040;
    puVar2[0x10] = 0x10c8;
    puVar2[0x11] = 0x50;
    puVar2[0x12] = 0x000010c0;
    puVar2[0x13] = 0x40002;
    puVar2[0x14] = 0x10c1;
    puVar2[0x15] = 0;
    puVar2[0x16] = 0x1100;
    puVar2[0x17] = 0x30000a92;
    puVar2[0x18] = 0x1101;
    puVar2[0x19] = 0x40000a92;
    puVar2[0x1a] = 0x1102;
    puVar2[0x1b] = 0x30000a92;
    puVar2[0x1c] = 0x1103;
    puVar2[0x1d] = 0x40000a92;
    puVar2[0x1e] = 0x110a;
    puVar2[0x1f] = 0x20000a92;
    puVar2[0x20] = 0x110b;
    puVar2[0x21] = 0x20000a92;
    puVar2[0x22] = 0x110c;
    puVar2[0x23] = 0x20000a92;
    puVar2[0x24] = 0x1104;
    puVar2[0x25] = 0x1492;
    puVar2[0x26] = 0x1105;
    puVar2[0x27] = 0x1492;
    puVar2[0x28] = 0x1106;
    puVar2[0x29] = 0x1492;
    puVar2[0x2a] = 0x1107;
    puVar2[0x2b] = 0x10001492;
    puVar2[0x2c] = 0x1108;
    puVar2[0x2d] = 0x10001492;
    puVar2[0x2e] = 0x1109;
    puVar2[0x2f] = 0x10001492;
    puVar2[0x30] = 0x1110;
    puVar2[0x31] = 0;
    puVar2[0x32] = 0x1111;
    puVar2[0x33] = 0;
    puVar2[0x34] = 0x1112;
    puVar2[0x35] = 0;
    puVar2[0x36] = 0x1113;
    puVar2[0x37] = 0;
    puVar2[0x38] = 0x111a;
    puVar2[0x39] = 0;
    puVar2[0x3a] = 0x111b;
    puVar2[0x3b] = 0;
    puVar2[0x3c] = 0x111c;
    puVar2[0x3d] = 0;
    puVar2[0x3e] = 0x1114;
    puVar2[0x3f] = 0x4000;
    puVar2[0x40] = 0x1115;
    puVar2[0x41] = 0x4000;
    puVar2[0x42] = 0x1116;
    puVar2[0x43] = 0x4000;
    puVar2[0x44] = 0x1117;
    puVar2[0x45] = 0x4000;
    puVar2[0x46] = 0x1118;
    puVar2[0x47] = 0x4000;
    puVar2[0x48] = 0x1119;
    puVar2[0x49] = 0x4000;
    uVar4 = (uVar4 - 1) * 0x800 | iVar7 - 1U | 0x80000000;
    puVar2[0x4a] = 0x1120;
    puVar2[0x4b] = uVar4;
    puVar2[0x4c] = 0x1121;
    puVar2[0x4d] = uVar4;
    puVar2[0x4e] = 0x1122;
    puVar2[0x4f] = uVar4;
    puVar2[0x50] = 0x1123;
    puVar2[0x51] = uVar4;
    uVar11 = iVar10 - 1;
    uVar4 = (uVar9 - 1) * 0x800 | uVar11 | 0x80000000;
    puVar2[0x52] = 0x1124;
    puVar2[0x53] = uVar4;
    puVar2[0x54] = 0x1127;
    puVar2[0x55] = uVar4;
    puVar2[0x56] = 0x112a;
    puVar2[0x57] = uVar4;
    uVar4 = uVar11 | ((uVar9 >> 1) - 1) * 0x800 | 0x80000000;
    puVar2[0x58] = 0x1125;
    puVar2[0x59] = uVar4;
    puVar2[0x5a] = 0x1126;
    puVar2[0x5b] = uVar4;
    puVar2[0x5c] = 0x1128;
    puVar2[0x5d] = uVar4;
    puVar2[0x5e] = 0x1129;
    puVar2[0x5f] = uVar4;
    puVar2[0x60] = 0x112b;
    puVar2[0x61] = uVar4;
    puVar2[0x62] = 0x112c;
    puVar2[99] = uVar4;
    puVar2[100] = 0x1130;
    puVar2[0x65] = 0x80108be4;
    puVar2[0x66] = 0x1131;
    puVar2[0x67] = 0x88108be4;
    puVar2[0x68] = 0x1132;
    puVar2[0x69] = 0x90108be4;
    puVar2[0x6a] = 0x1133;
    puVar2[0x6b] = 0x98108be4;
    puVar2[0x6c] = 0x1134;
    puVar2[0x6d] = 0xa0104000;
    puVar2[0x6e] = 0x1135;
    puVar2[0x6f] = 0xa8104000;
    puVar2[0x70] = 0x1136;
    puVar2[0x71] = 0xb0104000;
    puVar2[0x72] = 0x1137;
    puVar2[0x73] = 0xb8104000;
    puVar2[0x74] = 0x1138;
    puVar2[0x75] = 0xc0104000;
    puVar2[0x76] = 0x1139;
    puVar2[0x77] = 0xc8104000;
    puVar2[0x78] = 0x113a;
    puVar2[0x79] = 0xd0104036;
    puVar2[0x7a] = 0x113b;
    puVar2[0x7b] = 0xd8104036;
    puVar2[0x7c] = 0x113c;
    puVar2[0x7d] = 0xe0104036;
    puVar2[0x7e] = 0x1140;
    iVar7 = uVar1 - 1;
    puVar2[0x7f] = iVar7;
    puVar2[0x80] = 0x1141;
    puVar2[0x81] = iVar7;
    puVar2[0x82] = 0x1142;
    puVar2[0x83] = iVar7;
    puVar2[0x84] = 0x1143;
    puVar2[0x85] = iVar7;
    puVar2[0x86] = 0x114a;
    puVar2[0x87] = iVar8 + -1;
    puVar2[0x88] = 0x114b;
    iVar7 = iVar8 * 2 + -1;
    puVar2[0x89] = iVar7;
    puVar2[0x8a] = 0x114c;
    puVar2[0x8b] = iVar7;
    puVar2[0x8c] = 0x1180;
    puVar2[0x8d] = 0;
    puVar2[0x8e] = 0x11ad;
    puVar2[0x8f] = 0;
    puVar2[0x90] = 0x1189;
    puVar2[0x91] = 0;
    puVar2[0x92] = 0x1181;
    puVar2[0x93] = 5;
    puVar2[0x94] = 0x11a9;
    puVar2[0x95] = FUN_0000aa00;
    puVar2[0x96] = 0x11aa;
    puVar2[0x97] = 0xf;
    puVar2[0x98] = 0x11ab;
    puVar2[0x99] = 0xf;
    puVar2[0x9a] = 0x11ac;
    puVar3 = puVar2 + 0x9c;
    puVar2[0x9b] = 0xf;
  }
  else {
    uVar11 = *(uint *)(param_1 + 0x57c);
    iVar6 = param_1 + 0x15324;
    uVar9 = *(uint *)(param_1 + 0x588) >> 1;
    uVar4 = (uVar4 - 1) * 0x800 | iVar7 - 1U | 0x80000000;
    *param_2 = 0x1120;
    param_2[1] = uVar4;
    param_2[2] = 0x1121;
    param_2[3] = uVar4;
    param_2[4] = 0x1122;
    param_2[5] = uVar4;
    param_2[6] = 0x1123;
    param_2[7] = uVar4;
    uVar5 = (*(uint *)(param_1 + 0x578) >> 1) - 1;
    uVar4 = ((uVar11 >> 1) - 1) * 0x800 | uVar5 | 0x80000000;
    param_2[8] = 0x1124;
    param_2[9] = uVar4;
    param_2[10] = 0x1127;
    param_2[0xb] = uVar4;
    param_2[0xc] = 0x112a;
    param_2[0xd] = uVar4;
    uVar4 = uVar5 | ((uVar11 >> 2) - 1) * 0x800 | 0x80000000;
    param_2[0xe] = 0x1125;
    param_2[0xf] = uVar4;
    param_2[0x10] = 0x1126;
    param_2[0x11] = uVar4;
    param_2[0x12] = 0x1128;
    param_2[0x13] = uVar4;
    param_2[0x14] = 0x1129;
    param_2[0x15] = uVar4;
    param_2[0x16] = 0x112b;
    param_2[0x17] = uVar4;
    param_2[0x18] = 0x112c;
    param_2[0x19] = uVar4;
    param_2[0x1a] = 0x1130;
    param_2[0x1b] = 0x80108064;
    param_2[0x1c] = 0x1131;
    param_2[0x1d] = 0x88108064;
    param_2[0x1e] = 0x1132;
    param_2[0x1f] = 0x90108064;
    param_2[0x20] = 0x1133;
    param_2[0x21] = 0x98108064;
    param_2[0x22] = 0x1134;
    param_2[0x23] = 0xa0060003;
    param_2[0x24] = 0x1135;
    param_2[0x25] = 0xa8060003;
    param_2[0x26] = 0x1136;
    param_2[0x27] = 0xb0060003;
    param_2[0x28] = 0x1137;
    param_2[0x29] = 0xb8060003;
    param_2[0x2a] = 0x1138;
    param_2[0x2b] = 0xc0060003;
    param_2[0x2c] = 0x1139;
    param_2[0x2d] = 0xc8060003;
    param_2[0x2e] = 0x113a;
    param_2[0x2f] = 0xd0060077;
    param_2[0x30] = 0x113b;
    param_2[0x31] = 0xd8060077;
    param_2[0x32] = 0x113c;
    param_2[0x33] = 0xe0060077;
    param_2[0x34] = 0x1140;
    iVar7 = uVar1 - 1;
    param_2[0x35] = iVar7;
    param_2[0x36] = 0x1141;
    param_2[0x37] = iVar7;
    param_2[0x38] = 0x1142;
    param_2[0x39] = iVar7;
    param_2[0x3a] = 0x1143;
    param_2[0x3b] = iVar7;
    param_2[0x3c] = 0x114a;
    param_2[0x3d] = uVar9 - 1;
    param_2[0x3e] = 0x114b;
    iVar7 = uVar9 * 2 + -1;
    param_2[0x3f] = iVar7;
    param_2[0x40] = 0x114c;
    param_2[0x41] = iVar7;
    param_2[0x42] = 0x11a9;
    puVar3 = param_2 + 0x44;
    param_2[0x43] = 0x1b00;
  }
  iVar7 = ((int (*)())FUN_00009980)(puVar3,0x10000,0x1c,iVar6);
  return iVar7 - (int)param_2 >> 2;
}

/* FUN_00006d90 @ 0x6d90 (644 bytes) */
void FUN_00006d90(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  double dVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  
  fVar4 = FLOAT_0000d458;
  fVar15 = FLOAT_0000d454;
  fVar14 = FLOAT_0000d450;
  fVar13 = FLOAT_0000d44c;
  fVar11 = FLOAT_0000d444;
  fVar10 = FLOAT_0000d43c;
  dVar9 = DOUBLE_0000d418;
  uVar8 = (*(uint *)(param_1 + 0x57c) >> 1) + 0xf & 0xfffffff0;
  *(float *)(param_1 + 0x152cc) = FLOAT_0000d43c;
  *(float *)(param_1 + 0x152d0) = fVar10;
  fVar12 = FLOAT_0000d448;
  *(float *)(param_1 + 0x152b4) = FLOAT_0000d448;
  *(float *)(param_1 + 0x152b8) = fVar12;
  *(undefined4 *)(param_1 + 0x152dc) = 0;
  *(undefined4 *)(param_1 + 0x152e0) = 0;
  *(float *)(param_1 + 0x152bc) = fVar12;
  *(float *)(param_1 + 0x152c0) = fVar12;
  *(float *)(param_1 + 0x152ec) = fVar10;
  *(float *)(param_1 + 0x152f0) = fVar10;
  fVar1 = (float)((double)CONCAT44(0x43300000,*(undefined4 *)(param_1 + 0x578)) - dVar9);
  fVar6 = fVar4 / fVar1;
  fVar3 = fVar15 / (fVar1 * fVar14);
  *(undefined4 *)(param_1 + 0x152fc) = 0;
  fVar7 = fVar15 / (fVar1 * fVar11);
  *(undefined4 *)(param_1 + 0x15300) = 0;
  fVar2 = (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x57c)) - dVar9);
  *(undefined4 *)(param_1 + 0x1530c) = 0;
  *(undefined4 *)(param_1 + 0x15310) = 0;
  *(float *)(param_1 + 0x15330) = fVar12;
  *(float *)(param_1 + 0x15360) = fVar10;
  *(float *)(param_1 + 0x15384) = fVar6;
  *(float *)(param_1 + 0x152f4) = fVar3;
  *(float *)(param_1 + 0x152d4) = fVar3;
  fVar4 = fVar4 / fVar2;
  fVar5 = fVar13 / (fVar1 + fVar1);
  *(float *)(param_1 + 0x15364) = fVar7;
  fVar3 = (float)((double)CONCAT44(0x43300000,uVar8) - dVar9);
  *(float *)(param_1 + 0x15378) = fVar4;
  *(float *)(param_1 + 0x15318) = fVar4;
  *(float *)(param_1 + 0x152e4) = fVar5;
  *(float *)(param_1 + 0x152c4) = fVar5;
  *(float *)(param_1 + 0x152c8) = fVar13 / (fVar2 + fVar2);
  *(float *)(param_1 + 0x152d8) = fVar15 / (fVar2 * fVar14);
  *(float *)(param_1 + 0x15368) = fVar15 / (fVar3 * fVar11);
  *(float *)(param_1 + 0x15304) = fVar10 / fVar1;
  *(float *)(param_1 + 0x15314) = fVar10 / fVar1;
  *(float *)(param_1 + 0x152e8) = fVar13 / (fVar3 + fVar3);
  *(float *)(param_1 + 0x152f8) = fVar15 / (fVar3 * fVar14);
  *(float *)(param_1 + 0x15358) = fVar13 / fVar3;
  *(float *)(param_1 + 0x15388) = fVar11 / fVar2;
  *(float *)(param_1 + 0x15348) = fVar15 / (fVar2 * fVar11);
  *(undefined4 *)(param_1 + 0x1531c) = 0;
  *(undefined4 *)(param_1 + 0x15320) = 0;
  *(undefined4 *)(param_1 + 0x1534c) = 0;
  *(undefined4 *)(param_1 + 0x15350) = 0;
  *(undefined4 *)(param_1 + 0x1536c) = 0;
  *(undefined4 *)(param_1 + 0x15370) = 0;
  *(undefined4 *)(param_1 + 0x1537c) = 0;
  *(undefined4 *)(param_1 + 0x15380) = 0;
  *(undefined4 *)(param_1 + 0x1538c) = 0;
  *(undefined4 *)(param_1 + 0x15390) = 0;
  *(float *)(param_1 + 0x15324) = fVar12;
  *(float *)(param_1 + 0x15328) = fVar12;
  *(float *)(param_1 + 0x1532c) = fVar12;
  *(float *)(param_1 + 0x1533c) = fVar10;
  *(float *)(param_1 + 0x15340) = fVar10;
  *(float *)(param_1 + 0x1535c) = fVar10;
  *(float *)(param_1 + 0x15354) = fVar13 / fVar1;
  *(float *)(param_1 + 0x15308) = fVar10 / fVar2;
  *(float *)(param_1 + 0x15334) = fVar13 / fVar1;
  *(float *)(param_1 + 0x15344) = fVar7;
  *(float *)(param_1 + 0x15374) = fVar6;
  *(float *)(param_1 + 0x15338) = fVar13 / fVar2;
  uVar16 = ((int (*)())FUN_00006230)(param_1,*(undefined4 *)(param_1 + 0x15294),1,0);
  *(undefined4 *)(param_1 + 0x15298) = uVar16;
  uVar16 = ((int (*)())FUN_00006230)(param_1,*(undefined4 *)(param_1 + 0x1529c),2,0);
  uVar17 = *(undefined4 *)(param_1 + 0x57c);
  *(uint *)(param_1 + 0x57c) = uVar8 << 1;
  *(undefined4 *)(param_1 + 0x152a0) = uVar16;
  uVar16 = ((int (*)())FUN_00006230)(param_1,*(undefined4 *)(param_1 + 0x152a4),1,1);
  *(undefined4 *)(param_1 + 0x152a8) = uVar16;
  uVar16 = ((int (*)())FUN_00006230)(param_1,*(undefined4 *)(param_1 + 0x152ac),2,1);
  *(undefined4 *)(param_1 + 0x57c) = uVar17;
  *(undefined4 *)(param_1 + 0x152b0) = uVar16;
  return;
}

/* FUN_00007020 @ 0x7020 (592 bytes) */
int FUN_00007020(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (param_3 == 1) {
    iVar4 = *(int *)(param_1 + 0x588);
    if (*(int *)(param_1 + 0x55c) == 3) {
      _memcpy(param_2,*(undefined4 *)(param_1 + 0x15294),*(int *)(param_1 + 0x15298) << 2);
      iVar2 = *(int *)(param_1 + 0x15298);
    }
    else {
      _memcpy(param_2,*(undefined4 *)(param_1 + 0x152a4),*(int *)(param_1 + 0x152a8) << 2);
      iVar2 = *(int *)(param_1 + 0x152a8);
    }
    puVar3 = param_2 + iVar2;
    *puVar3 = 0x1144;
    iVar2 = iVar4 + -1;
    puVar3[1] = iVar2;
    puVar3[2] = 0x1147;
    puVar3[3] = iVar2;
    puVar3[4] = 0x1145;
    iVar4 = iVar4 * 2 + -1;
    puVar3[5] = iVar4;
    puVar3[6] = 0x1146;
    puVar3[7] = iVar4;
    puVar3[8] = 0x1148;
    puVar3[9] = iVar4;
    puVar3[10] = 0x1149;
    puVar3[0xb] = iVar4;
    puVar3 = puVar3 + 0xc;
    iVar4 = 0x1e;
    do {
      *puVar3 = 0x80000000;
      puVar3 = puVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  else {
    *param_2 = ((unsigned char *)0x00001040);
    puVar3 = param_2 + 2;
    param_2[1] = 0;
    uVar1 = *(uint *)(param_1 + 0x588) >> 1;
    if (*(int *)(param_1 + 0x55c) == 3) {
      _memcpy(puVar3,*(undefined4 *)(param_1 + 0x1529c),*(int *)(param_1 + 0x152a0) << 2);
      iVar4 = *(int *)(param_1 + 0x152a0);
    }
    else {
      _memcpy(puVar3,*(undefined4 *)(param_1 + 0x152ac),*(int *)(param_1 + 0x152b0) << 2);
      iVar4 = *(int *)(param_1 + 0x152b0);
    }
    puVar3 = puVar3 + iVar4;
    *puVar3 = 0x1144;
    iVar4 = uVar1 - 1;
    puVar3[1] = iVar4;
    puVar3[2] = 0x1147;
    puVar3[3] = iVar4;
    puVar3[4] = 0x1145;
    iVar4 = uVar1 * 2 + -1;
    puVar3[5] = iVar4;
    puVar3[6] = 0x1146;
    puVar3[7] = iVar4;
    puVar3[8] = 0x1148;
    puVar3[9] = iVar4;
    puVar3[10] = 0x1149;
    puVar3[0xb] = iVar4;
    puVar3 = puVar3 + 0xc;
    iVar4 = 0x1e;
    do {
      *puVar3 = 0x80000000;
      puVar3 = puVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return puVar3;
}

/* FUN_00007270 @ 0x7270 (544 bytes) */
int FUN_00007270(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint auStack_3f8 [244];
  
  puVar3 = &UNK_0000d5c4;
  iVar4 = (param_2[1] - *param_2) + 1;
  _memcpy(auStack_3f8,&UNK_0000d5c4 + *param_2 * 0x18,iVar4 * 0x18);
  iVar1 = (param_2[7] - param_2[6]) + 1;
  iVar5 = iVar4 + iVar1;
  _memcpy(auStack_3f8 + iVar4 * 6,&UNK_0000d4ec + param_2[6] * 0x18,iVar1 * 0x18);
  iVar1 = iVar5 + -1;
  auStack_3f8[iVar4 * 6] = auStack_3f8[iVar4 * 6] | 0x400;
  auStack_3f8[iVar1 * 6] = auStack_3f8[iVar1 * 6] | 4;
  auStack_3f8[iVar1 * 6 + 1] = auStack_3f8[iVar1 * 6 + 1] | 0x2000000;
  iVar1 = (param_2[5] - param_2[4]) + 1;
  iVar6 = iVar5 + iVar1;
  _memcpy(auStack_3f8 + iVar5 * 6,&UNK_0000d5c4 + param_2[4] * 0x18,iVar1 * 0x18);
  iVar4 = param_2[10];
  iVar1 = param_2[0xb];
  auStack_3f8[iVar5 * 6] = auStack_3f8[iVar5 * 6] | 4;
  iVar1 = (iVar1 - iVar4) + 1;
  iVar5 = iVar6 + iVar1;
  _memcpy(auStack_3f8 + iVar6 * 6,&UNK_0000d4ec + iVar4 * 0x18,iVar1 * 0x18);
  iVar1 = iVar5 + -1;
  auStack_3f8[iVar6 * 6] = auStack_3f8[iVar6 * 6] | 0x400;
  auStack_3f8[iVar1 * 6] = auStack_3f8[iVar1 * 6] | 4;
  auStack_3f8[iVar1 * 6 + 1] = auStack_3f8[iVar1 * 6 + 1] | 0x2000000;
  if (param_3 == 2) {
    puVar3 = &UNK_0000d474;
  }
  iVar4 = (param_2[9] - param_2[8]) + 1;
  iVar6 = iVar5 + iVar4;
  iVar1 = iVar6 + -1;
  _memcpy(auStack_3f8 + iVar5 * 6,puVar3 + param_2[8] * 0x18,iVar4 * 0x18);
  auStack_3f8[iVar5 * 6] = auStack_3f8[iVar5 * 6] | 4;
  auStack_3f8[iVar1 * 6] = auStack_3f8[iVar1 * 6] | 0x100;
  puVar2 = (undefined4 *)((int (*)())FUN_00009980)(param_1,0,(uint)(iVar6 * 0x18) >> 2,auStack_3f8);
  *puVar2 = 0x118e;
  puVar2[1] = 0;
  puVar2[2] = 0x118c;
  puVar2[3] = iVar1 * 0x10000;
  puVar2[4] = 0x118d;
  puVar2[5] = iVar1 * 0x10000;
  return puVar2 + 6;
}

/* FUN_00007490 @ 0x7490 (696 bytes) */
int FUN_00007490(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  int param_3;
  undefined4 *param_4;
  int param_5;
  int param_6;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  if (param_5 == 0) {
    if (*(int *)(param_1 + 0x55c) == 3) {
      puVar5 = &UNK_0000dd00 + param_2 * 0x34;
    }
    else {
      puVar5 = &UNK_0000d7ec + param_2 * 0x34;
    }
  }
  else if (*(int *)(param_1 + 0x55c) == 3) {
    puVar5 = &UNK_0000e658 + param_2 * 0x34;
  }
  else {
    puVar5 = &UNK_0000e144 + param_2 * 0x34;
  }
  if (param_6 != 1) {
    iVar1 = *(int *)(param_1 + 0x55c);
    if ((iVar1 == 3) && (param_2 < 3)) {
      uVar6 = *(uint *)(param_1 + 0x588) >> 1;
    }
    else {
      uVar6 = *(uint *)(param_1 + 0x588);
    }
    puVar7 = *(undefined4 **)(param_1 + 0x1517c);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x55c);
    if ((iVar1 == 3) && (param_2 < 3)) {
      uVar6 = *(uint *)(param_1 + 0x588);
    }
    else {
      uVar6 = *(int *)(param_1 + 0x588) << 1;
    }
    puVar7 = *(undefined4 **)(param_1 + 0x15174);
  }
  if (iVar1 == 3) {
    if ((((param_2 - 5 < 2) || (param_2 == 9)) || (param_2 == 10)) ||
       (((param_2 == 0xf || (param_2 == 0x10)) ||
        ((param_2 == 0x11 || (uVar4 = 0, param_2 == 0x12)))))) {
      uVar4 = 1;
    }
  }
  else {
    uVar4 = (uint)(iVar1 == 2);
  }
  *puVar7 = 0x1393;
  puVar7[1] = 10;
  puVar7[2] = 0x5c8;
  puVar7[3] = 0x20000;
  puVar7[4] = ((unsigned char *)0x00001040);
  puVar7[5] = 0;
  puVar3 = (undefined4 *)((int (*)())FUN_00007270)(puVar7 + 6,puVar5,param_6);
  *puVar3 = ((unsigned char *)0x00001041);
  puVar3[1] = *(undefined4 *)(puVar5 + 0x30);
  puVar3[2] = (param_3 + 5) * 0x10000 | 0xc0003a00;
  puVar3[3] = 0xc0000;
  *(int *)(param_1 + 0x15188) = (int)(puVar3 + 4) - (int)puVar7 >> 2;
  puVar3[4] = uVar4;
  puVar3[5] = uVar6;
  puVar3[6] = param_3 << 0x12 | 0x81d;
  puVar7 = puVar3 + 8;
  puVar3[7] = param_3;
  for (; param_3 != 0; param_3 = param_3 + -1) {
    uVar2 = *param_4;
    param_4 = param_4 + 1;
    *puVar7 = uVar2;
    puVar7 = puVar7 + 1;
  }
  *puVar7 = 0xdeadbeef;
  puVar7[1] = 0x1393;
  puVar7[2] = 10;
  if (param_6 != 1) {
    *(undefined4 **)(param_1 + 0x1517c) = puVar7 + 3;
  }
  else {
    *(undefined4 **)(param_1 + 0x15174) = puVar7 + 3;
  }
  return;
}

/* FUN_00007760 @ 0x7760 (204 bytes) */
int FUN_00007760(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  
  if (param_3 == 3) {
    if (param_1[5] != 0) {
      puVar1 = (undefined4 *)param_1[8];
      param_1[8] = (int)(puVar1 + 1);
      *puVar1 = param_2;
      return 1;
    }
  }
  else if (param_3 == 4) {
    if (param_1[10] != 0) {
      puVar1 = (undefined4 *)param_1[0xd];
      param_1[0xd] = (int)(puVar1 + 1);
      *puVar1 = param_2;
      return 1;
    }
  }
  else if ((param_3 == 1) && (*param_1 != 0)) {
    puVar1 = (undefined4 *)param_1[3];
    if (puVar1 <= (undefined4 *)param_1[4]) {
      param_1[3] = (int)(puVar1 + 1);
      param_1[1] = param_1[1] + 1;
      *puVar1 = param_2;
      return 1;
    }
    param_1[10] = 0;
    *param_1 = 0;
    param_1[5] = 0;
    return 0;
  }
  return 0;
}

/* FUN_00007850 @ 0x7850 (1416 bytes) */
int FUN_00007850(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  undefined *puVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  
  puVar8 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar8 + 0xe) {
    puVar3 = *(uint **)(param_1 + 0x30);
    *puVar3 = (int)puVar8 - (int)puVar3 >> 2 | *puVar3;
    puVar2 = PTR_0000f1a0;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar2,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar4 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar4 + 0x20;
    *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
    *(undefined4 *)(iVar4 + 0x1c) = 0;
    puVar8 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar3 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar8 + 0xe;
  *puVar3 = (int)puVar8 - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(param_1 + 0x30) = puVar8;
  *puVar8 = 0x12000000;
  puVar8[1] = 0;
  if (*(char *)(param_1 + 0x574) == '\0') {
    puVar8[2] = 0;
  }
  else {
    puVar8[2] = 1;
  }
  iVar4 = *(int *)(param_1 + 0x55c);
  if (iVar4 == 2) {
    puVar8[3] = 1;
  }
  else {
    puVar8[3] = 0;
    if (iVar4 == 3) {
      puVar8[4] = 0;
      goto LAB_00007998;
    }
  }
  puVar8[4] = 1;
LAB_00007998:
  puVar8[5] = 1;
  puVar8[6] = -0x80000000;
  puVar8[7] = -0x80000000;
  puVar8[8] = *(undefined4 *)(param_1 + 0x15400);
  puVar8[9] = *(undefined4 *)(param_1 + 0x568);
  puVar8[10] = *(undefined4 *)(param_1 + 0x56c);
  puVar8[0xb] = *(undefined4 *)(param_1 + 0x570);
  if (*(int *)(param_1 + 0x560) == 3) {
    puVar8[0xc] = 1;
  }
  else {
    puVar8[0xc] = 0;
  }
  puVar8[0xd] = 1;
  puVar9 = *(undefined4 **)(param_1 + 0x34);
  puVar6 = *(undefined4 **)(param_1 + 0x38);
  if (puVar6 <= puVar9 + 2) {
    puVar3 = *(uint **)(param_1 + 0x30);
    *puVar3 = (int)puVar9 - (int)puVar3 >> 2 | *puVar3;
    puVar2 = PTR_0000f1a0;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar2,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar4 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar4 + 0x20;
    *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
    *(undefined4 *)(iVar4 + 0x1c) = 0;
    puVar9 = *(undefined4 **)(param_1 + 0x34);
    puVar6 = *(undefined4 **)(param_1 + 0x38);
  }
  puVar10 = puVar9 + 2;
  *(undefined4 **)(param_1 + 0x34) = puVar10;
  *puVar9 = 0x80000000;
  puVar9[1] = 0x80000000;
  if (puVar6 <= puVar10 + param_2) {
    puVar3 = *(uint **)(param_1 + 0x30);
    *puVar3 = (int)puVar10 - (int)puVar3 >> 2 | *puVar3;
    puVar2 = PTR_0000f1a0;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar2,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar4 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar4 + 0x20;
    *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
    *(undefined4 *)(iVar4 + 0x1c) = 0;
    puVar10 = *(undefined4 **)(param_1 + 0x34);
  }
  *(undefined4 **)(param_1 + 0x34) = puVar10 + param_2;
  *(undefined4 **)(param_1 + 0x15164) = puVar10;
  *(undefined4 **)(param_1 + 0x1516c) = puVar10;
  *(undefined4 **)(param_1 + 0x15170) = puVar10;
  *(undefined4 **)(param_1 + 0x15168) = puVar10 + param_2 + -1;
  iVar4 = ((int (*)())FUN_00007020)(param_1,puVar10,1);
  iVar5 = *(int *)(param_1 + 0x15164);
  *(int *)(param_1 + 0x15174) = iVar4;
  puVar8[6] = iVar4 - iVar5 >> 2;
  iVar4 = *(int *)(param_1 + 0x15168) - iVar4;
  uVar7 = iVar4 >> 2;
  iVar5 = iVar5 + ((iVar4 >> 3) + (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0)) * 4;
  *(int *)(param_1 + 0x15178) = iVar5;
  iVar4 = ((int (*)())FUN_00007020)(param_1,iVar5,2);
  *(int *)(param_1 + 0x1517c) = iVar4;
  puVar8[7] = iVar4 - *(int *)(param_1 + 0x15164) >> 2;
  iVar12 = 0;
  iVar5 = param_1 + 0x14428;
  iVar4 = 0;
  do {
    iVar14 = iVar5 + iVar4;
    iVar11 = (*(int *)(param_1 + 0x14424) - *(int *)(iVar5 + iVar4)) + -1;
    if (iVar11 != 0) {
      piVar13 = *(int **)(param_1 + 0x15174);
      *(int **)(param_1 + 0x15174) = piVar13 + 2;
      ((int (*)())FUN_00007490)(param_1,iVar12,iVar11,*(int *)(iVar5 + iVar4) * 4 + *(int *)(iVar14 + 8) + 4,1,1)
      ;
      *piVar13 = (*(int *)(param_1 + 0x15174) - (int)piVar13 >> 2) + -2;
      piVar13[1] = *(int *)(param_1 + 0x15188);
      piVar13 = *(int **)(param_1 + 0x1517c);
      *(int **)(param_1 + 0x1517c) = piVar13 + 2;
      ((int (*)())FUN_00007490)(param_1,iVar12,iVar11,*(int *)(iVar5 + iVar4) * 4 + *(int *)(iVar14 + 8) + 4,1,2)
      ;
      *piVar13 = (*(int *)(param_1 + 0x1517c) - (int)piVar13 >> 2) + -2;
      piVar13[1] = *(int *)(param_1 + 0x15188);
    }
    if (*(int *)(iVar14 + 4) != 0) {
      piVar13 = *(int **)(param_1 + 0x15174);
      *(int **)(param_1 + 0x15174) = piVar13 + 2;
      ((int (*)())FUN_00007490)(param_1,iVar12,*(undefined4 *)(iVar14 + 4),*(undefined4 *)(iVar14 + 8),0,1);
      *piVar13 = (*(int *)(param_1 + 0x15174) - (int)piVar13 >> 2) + -2;
      piVar13[1] = *(int *)(param_1 + 0x15188);
      piVar13 = *(int **)(param_1 + 0x1517c);
      *(int **)(param_1 + 0x1517c) = piVar13 + 2;
      ((int (*)())FUN_00007490)(param_1,iVar12,*(undefined4 *)(iVar14 + 4),*(undefined4 *)(iVar14 + 8),0,2);
      *piVar13 = (*(int *)(param_1 + 0x1517c) - (int)piVar13 >> 2) + -2;
      piVar13[1] = *(int *)(param_1 + 0x15188);
    }
    bVar1 = iVar12 != 0x18;
    iVar4 = iVar4 + 0xc;
    iVar12 = iVar12 + 1;
  } while (bVar1);
  puVar8 = *(undefined4 **)(param_1 + 0x15174);
  *(undefined4 **)(param_1 + 0x15174) = puVar8 + 1;
  *puVar8 = 0;
  puVar8 = *(undefined4 **)(param_1 + 0x1517c);
  *(undefined4 **)(param_1 + 0x1517c) = puVar8 + 1;
  *puVar8 = 0;
  return;
}

/* FUN_00007de0 @ 0x7de0 (416 bytes) */
int FUN_00007de0(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(param_1 + 0x10);
  uVar3 = *(int *)(param_1 + 0x14) - (int)puVar5 >> 2;
  if (0x4001 < uVar3) {
    iVar1 = (uVar3 - 0x4002) / 0x4001 + 1;
    if (uVar3 == 0x4001) {
      iVar1 = 1;
    }
    do {
      *puVar5 = 0xffff1000;
      uVar3 = uVar3 - 0x4001;
      puVar5 = puVar5 + 0x4001;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    *(undefined4 **)(param_1 + 0x10) = puVar5;
  }
  if (uVar3 != 0) {
    if (uVar3 < 2) {
      puVar5 = *(undefined4 **)(param_1 + 0x10);
      *(undefined4 **)(param_1 + 0x10) = puVar5 + 1;
      *puVar5 = 0x80000000;
    }
    else {
      puVar4 = *(uint **)(param_1 + 0x10);
      *(uint **)(param_1 + 0x10) = puVar4 + 1;
      *puVar4 = (uVar3 - 2) * 0x10000 | 0xc0001000;
    }
  }
  puVar5 = *(undefined4 **)(param_1 + 0x18);
  iVar1 = *(int *)(param_1 + 4) - (int)puVar5 >> 2;
  uVar3 = iVar1 + 1;
  if (0x4001 < uVar3) {
    iVar2 = (iVar1 - 0x4001U) / 0x4001 + 1;
    if (iVar1 == 0x4000) {
      iVar2 = 1;
    }
    do {
      *puVar5 = 0xffff1000;
      uVar3 = uVar3 - 0x4001;
      puVar5 = puVar5 + 0x4001;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(undefined4 **)(param_1 + 0x18) = puVar5;
  }
  if (uVar3 == 0) {
    return;
  }
  if (1 < uVar3) {
    puVar4 = *(uint **)(param_1 + 0x18);
    *(uint **)(param_1 + 0x18) = puVar4 + 1;
    *puVar4 = (uVar3 - 2) * 0x10000 | 0xc0001000;
    return;
  }
  puVar5 = *(undefined4 **)(param_1 + 0x18);
  *(undefined4 **)(param_1 + 0x18) = puVar5 + 1;
  *puVar5 = 0x80000000;
  return;
}

/* FUN_00007f80 @ 0x7f80 (1072 bytes) */
int FUN_00007f80(param_1)
  int param_1;
{
  int *piVar1;
  bool bVar2;
  undefined *puVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int in_r6;
  int in_r7;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  
  piVar12 = (int *)(param_1 + 0x55c);
  iVar14 = *(int *)(param_1 + 0x568);
  if (*(int *)(param_1 + 0x560) == 1) {
    if (*(int *)(param_1 + 0x15124) == *(int *)(param_1 + 0x1511c)) {
      return;
    }
    iVar14 = ((int (*)())FUN_00006120)(param_1,0);
    if (iVar14 != 0) {
      return;
    }
    piVar12[*(int *)(param_1 + 0x568) + 0x14b] = 1;
    return;
  }
  if ((((*(int *)(param_1 + 0x55c) == 3) || (*(char *)(param_1 + 0x574) != '\0')) &&
      (*(int *)(param_1 + 0x15124) != *(int *)(param_1 + 0x1511c))) &&
     (iVar6 = ((int (*)())FUN_00006120)(param_1,0), iVar6 == 0)) {
    piVar12[*(int *)(param_1 + 0x568) + 0x14b] = 1;
  }
  if (*(int *)(param_1 + 0x15148) == *(int *)(param_1 + 0x15140)) {
    puVar10 = *(undefined4 **)(param_1 + 0x34);
    puVar7 = *(undefined4 **)(param_1 + 0x38);
  }
  else {
    iVar6 = ((int (*)())FUN_00006120)(param_1,1);
    if (iVar6 == 0) {
      iVar14 = *(int *)(param_1 + 0x15164);
      piVar12[*(int *)(param_1 + 0x568) + 0x14b] = 1;
      *(undefined4 *)(iVar14 + -0xc) = 0;
      goto LAB_000082e0;
    }
    iVar6 = *(int *)(param_1 + 0x15164);
    *(undefined4 *)(iVar6 + -8) = 0x5c8;
    *(undefined4 *)(iVar6 + -4) = 0x8000000;
    puVar3 = PTR_0000f1a0;
    puVar9 = *(undefined4 **)(param_1 + 0x34);
    puVar7 = *(undefined4 **)(param_1 + 0x38);
    if (puVar7 <= puVar9 + 2) {
      puVar4 = *(uint **)(param_1 + 0x30);
      in_r6 = param_1 + 0x40;
      in_r7 = param_1 + 0x44;
      *puVar4 = (int)puVar9 - (int)puVar4 >> 2 | *puVar4;
      *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
      **(undefined4 **)(param_1 + 0x34) = 0x1000000;
      _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar3,in_r6,in_r7,1);
      iVar6 = *(int *)(param_1 + 0x40);
      *(int *)(param_1 + 0x34) = iVar6 + 0x20;
      *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
      *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
      *(undefined4 *)(iVar6 + 0x1c) = 0;
      puVar9 = *(undefined4 **)(param_1 + 0x34);
      puVar7 = *(undefined4 **)(param_1 + 0x38);
    }
    puVar10 = puVar9 + 2;
    *(undefined4 **)(param_1 + 0x34) = puVar10;
    *puVar9 = 0x7eb;
    puVar9[1] = 0x4000;
  }
  puVar3 = PTR_0000f1a0;
  iVar13 = param_1 + 0x44;
  iVar6 = param_1 + 0x40;
  if (puVar7 <= puVar10 + 4) {
    puVar4 = *(uint **)(param_1 + 0x30);
    *puVar4 = (int)puVar10 - (int)puVar4 >> 2 | *puVar4;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar3,iVar6,iVar13,1);
    iVar5 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar5 + 0x20;
    *(int *)(param_1 + 0x30) = iVar5 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar5 + 0x20 + *(int *)(iVar5 + 0x10) * 4;
    *(undefined4 *)(iVar5 + 0x1c) = 0;
    puVar10 = *(undefined4 **)(param_1 + 0x34);
    in_r6 = iVar6;
    in_r7 = iVar13;
  }
  *(undefined4 **)(param_1 + 0x34) = puVar10 + 4;
  *puVar10 = 0x1393;
  uVar11 = 10;
  puVar10[1] = 10;
  uVar8 = 0x5c8;
  puVar10[2] = 0x5c8;
  puVar10[3] = 0x20000;
  iVar13 = 0;
  ((int (*)())FUN_00007de0)(param_1 + 0x15164);
  iVar6 = *(int *)(param_1 + 0x151a4);
  iVar5 = (*(uint *)(param_1 + 0x57c) >> 4) * iVar6;
  piVar15 = piVar12 + iVar14 * 4 + 0x5326;
  do {
    ((int (*)())FUN_0000bf20)(param_1,*piVar15,iVar5,in_r6,in_r7,uVar8,iVar6,uVar11);
    piVar1 = piVar15 + 0x14;
    piVar15 = piVar15 + 1;
    ((int (*)())FUN_0000bf20)(param_1,*piVar1,iVar5,in_r6,in_r7,uVar8,iVar6,uVar11);
    bVar2 = iVar13 != 3;
    iVar13 = iVar13 + 1;
  } while (bVar2);
LAB_000082e0:
  puVar3 = PTR_0000f1a0;
  puVar4 = *(uint **)(param_1 + 0x30);
  *puVar4 = *(int *)(param_1 + 0x34) - (int)puVar4 >> 2 | *puVar4;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar3,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar14 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar14 + 0x20;
  *(int *)(param_1 + 0x30) = iVar14 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar14 + 0x20 + *(int *)(iVar14 + 0x10) * 4;
  *(undefined4 *)(iVar14 + 0x1c) = 0;
  piVar12[*(int *)(param_1 + 0xac4) * 2 + 0x15c] = *(int *)(*(int *)(param_1 + 0x40) + 0x18);
  if (((*piVar12 != 3) && (*(char *)(param_1 + 0x574) == '\0')) &&
     (*(int *)(param_1 + 0x15124) != *(int *)(param_1 + 0x1511c))) {
    ((int (*)())FUN_00006120)(param_1,0);
    return;
  }
  return;
}

/* FUN_000083e0 @ 0x83e0 (300 bytes) */
int FUN_000083e0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (param_3 != 0) {
    iVar7 = param_1 + 0x15140;
  }
  else {
    iVar7 = param_1 + 0x1511c;
  }
  uVar1 = *(int *)(iVar7 + 8) + param_2 * 4;
  if (*(uint *)(iVar7 + 4) < uVar1) {
    if (param_3 != 0) {
      iVar3 = 0;
      iVar6 = 0;
      iVar4 = 0x19;
      piVar2 = (int *)(param_1 + 0x1442c);
      do {
        if (*piVar2 != 0) {
          iVar6 = iVar6 + *piVar2;
          iVar3 = iVar3 + 1;
        }
        iVar8 = (*(int *)(param_1 + 0x14424) - piVar2[-1]) + -1;
        if (iVar8 != 0) {
          iVar3 = iVar3 + 1;
          iVar6 = iVar6 + iVar8;
        }
        iVar4 = iVar4 + -1;
        piVar2 = piVar2 + 3;
      } while (iVar4 != 0);
      ((int (*)())FUN_00007850)(param_1,(iVar6 + iVar3 * 0x80) * 2 + 1000);
      ((int (*)())FUN_00007f80)(param_1);
      puVar5 = (undefined4 *)(param_1 + 0x1442c);
      iVar3 = 0x19;
      do {
        *puVar5 = 0;
        puVar5[-1] = *(int *)(param_1 + 0x14424) + -1;
        puVar5 = puVar5 + 3;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    else {
      ((int (*)())FUN_00006120)(param_1,0);
    }
    uVar1 = param_2 * 4 + *(int *)(iVar7 + 8);
  }
  *(uint *)(iVar7 + 8) = uVar1;
  return;
}

/* FUN_00008510 @ 0x8510 (372 bytes) */
int FUN_00008510(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 *param_3;
  uint param_4;
  undefined4 param_5;
{
  byte *pbVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  
  iVar8 = 6;
  iVar5 = 0;
  puVar7 = (uint *)*param_3;
  iVar2 = param_2;
  do {
    pbVar1 = (byte *)(iVar2 + 0x16);
    iVar2 = iVar2 + 1;
    iVar5 = iVar5 + (uint)*pbVar1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (iVar5 == 0) {
    *(undefined1 *)(param_1 + 0x590) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 0x590) = 0;
    puVar3 = (uint *)((int (*)())FUN_000083e0)(param_1,iVar5 + 2,param_5);
    uVar6 = 0x80000000;
    if (*(char *)(param_2 + 0x15) == '\0') {
      uVar6 = 0;
    }
    *puVar3 = -(uint)*(byte *)(param_2 + 0x1b) >> 0x19 & 0x40 |
              -(uint)*(byte *)(param_2 + 0x1a) >> 0x18 & 0x80 |
              -(uint)*(byte *)(param_2 + 0x19) >> 0x17 & 0x100 |
              -(uint)*(byte *)(param_2 + 0x18) >> 0x16 & 0x200 |
              -(uint)*(byte *)(param_2 + 0x17) >> 0x15 & 0x400 |
              -(uint)*(byte *)(param_2 + 0x16) >> 0x14 & 0x800 |
              uVar6 | (uint)*(byte *)(param_1 + 0x564) << 0x19;
    puVar4 = puVar3 + 2;
    uVar6 = param_4 / *(uint *)(param_1 + 0x580);
    puVar3[1] = uVar6 << 0x14 | (param_4 - uVar6 * *(uint *)(param_1 + 0x580)) * 0x10;
    if (iVar5 + 2 != 2) {
      do {
        *puVar4 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar4 = puVar4 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    *param_3 = puVar7;
  }
  return;
}

/* FUN_00008690 @ 0x8690 (344 bytes) */
int FUN_00008690(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  undefined4 *param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_5 == 3) {
    puVar2 = param_3 + 8;
    param_3[7] = *(undefined4 *)(param_2 + 0x18);
    *(int *)(param_2 + 0x18) = param_4 * 4 + *(int *)(param_2 + 0x18);
    param_3[5] = 1;
    param_3[8] = param_3[7];
    param_3[9] = *(int *)(param_2 + 0x18) + -8;
  }
  else if (param_5 == 4) {
    puVar2 = param_3 + 0xd;
    param_3[0xc] = *(undefined4 *)(param_2 + 0x20);
    *(int *)(param_2 + 0x20) = param_4 * 4 + *(int *)(param_2 + 0x20);
    param_3[10] = 1;
    param_3[0xd] = param_3[0xc];
    param_3[0xe] = *(int *)(param_2 + 0x20) + -8;
  }
  else {
    puVar2 = (undefined4 *)0x0;
    if (param_5 == 1) {
      param_3[2] = *(undefined4 *)(param_2 + 0x10);
      uVar1 = param_4 * 4 + *(int *)(param_2 + 0x10);
      *(uint *)(param_2 + 0x10) = uVar1;
      if (uVar1 < *(uint *)(param_2 + 0x14)) {
        param_3[1] = 1;
        puVar2 = param_3 + 3;
        *param_3 = 1;
        param_3[3] = param_3[2];
        param_3[4] = *(int *)(param_2 + 0x10) + -8;
      }
      else {
        *(uint *)(param_2 + 0x10) = uVar1 + param_4 * -4;
        ((int (*)())FUN_00007f80)(param_1);
        puVar2 = param_3 + 3;
        param_3[2] = *(undefined4 *)(param_2 + 0x10);
        *(int *)(param_2 + 0x10) = param_4 * 4 + *(int *)(param_2 + 0x10);
        param_3[1] = 1;
        *param_3 = 1;
        param_3[3] = param_3[2];
        param_3[4] = *(int *)(param_2 + 0x10) + -8;
      }
    }
  }
  return puVar2;
}

/* FUN_00008800 @ 0x8800 (28 bytes) */
int FUN_00008800(param_1)
  int param_1;
{
  *(undefined4 *)(*(int *)(param_1 + 0x15164) + -0xc) = 0;
  return;
}

/* FUN_00008820 @ 0x8820 (3588 bytes) */
int FUN_00008820(param_1, param_2, param_3)
  int param_1;
  short *param_2;
  uint param_3;
{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  
  iVar10 = param_1 + 0x55c;
  iVar8 = param_3 * 4;
  iVar9 = *(int *)(param_1 + 0x568);
  uVar12 = param_3 / *(uint *)(param_1 + 0x580);
  iVar11 = param_3 - uVar12 * *(uint *)(param_1 + 0x580);
  iVar7 = iVar11 + uVar12 * (*(uint *)(param_1 + 0x58c) >> 2);
  if (*(int *)(param_1 + 0x55c) == 3) {
    switch(*(undefined1 *)(param_2 + 10)) {
    default:
      return;
    case 1:
      iVar10 = iVar9 * 0x10 + iVar10;
      iVar9 = param_1 + 0x14428;
      *(uint *)(*(int *)(iVar10 + 0x14c98) + iVar7 * 4) = CONCAT22(param_2[1],*param_2);
      *(uint *)(iVar7 * 4 + *(int *)(iVar10 + 0x14ce8)) =
           ((int)param_2[1] - ((int)param_2[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar7 = *(int *)(param_1 + 0x14428);
        *(int *)(iVar7 * 4 + *(int *)(param_1 + 0x14430)) = iVar8;
        *(int *)(param_1 + 0x14428) = iVar7 + -1;
        return;
      }
      goto LAB_000089ac;
    case 2:
      iVar10 = iVar9 * 0x10 + iVar10;
      iVar9 = param_1 + 0x14434;
      *(uint *)(*(int *)(iVar10 + 0x14c9c) + iVar7 * 4) = CONCAT22(param_2[3],param_2[2]);
      *(uint *)(iVar7 * 4 + *(int *)(iVar10 + 0x14cec)) =
           ((int)param_2[3] - ((int)param_2[3] >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)param_2[2] - ((int)param_2[2] >> 0x1f)) >> 1 & 0xffff;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar7 = *(int *)(param_1 + 0x14434);
        *(int *)(iVar7 * 4 + *(int *)(param_1 + 0x1443c)) = iVar8;
        *(int *)(param_1 + 0x14434) = iVar7 + -1;
        return;
      }
LAB_000089ac:
      iVar7 = *(int *)(iVar9 + 4);
      *(int *)(iVar7 * 4 + *(int *)(iVar9 + 8)) = iVar8;
      *(int *)(iVar9 + 4) = iVar7 + 1;
      return;
    case 3:
      iVar7 = iVar7 * 4;
      iVar10 = iVar9 * 0x10 + iVar10;
      *(uint *)(*(int *)(iVar10 + 0x14c98) + iVar7) = CONCAT22(param_2[1],*param_2);
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14c9c)) = CONCAT22(param_2[3],param_2[2]);
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14ce8)) =
           ((int)param_2[1] - ((int)param_2[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14cec)) =
           ((int)param_2[3] - ((int)param_2[3] >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)param_2[2] - ((int)param_2[2] >> 0x1f)) >> 1 & 0xffff;
      if (*(char *)(param_1 + 0x590) != '\0') {
        iVar7 = *(int *)(param_1 + 0x14444);
        *(int *)(iVar7 * 4 + *(int *)(param_1 + 0x14448)) = iVar8;
        *(int *)(param_1 + 0x14444) = iVar7 + 1;
        return;
      }
      iVar7 = *(int *)(param_1 + 0x14440);
      *(int *)(iVar7 * 4 + *(int *)(param_1 + 0x14448)) = iVar8;
      *(int *)(param_1 + 0x14440) = iVar7 + -1;
      return;
    case 5:
      iVar7 = iVar7 * 4;
      sVar1 = param_2[5];
      iVar10 = iVar9 * 0x10 + iVar10;
      sVar2 = param_2[4];
      *(uint *)(*(int *)(iVar10 + 0x14c98) + iVar7) = CONCAT22(param_2[1],*param_2);
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14ca0)) = CONCAT22(sVar1,sVar2);
      sVar1 = param_2[5];
      sVar2 = param_2[4];
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14ce8)) =
           ((int)param_2[1] - ((int)param_2[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14cf0)) =
           ((int)sVar1 - ((int)sVar1 >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)sVar2 - ((int)sVar2 >> 0x1f)) >> 1 & 0xffff;
      iVar8 = iVar8 + *(int *)(param_1 + 0x153fc);
      iVar7 = param_1 + 0x14428 + (uint)*(byte *)(param_2 + 8) * 0xc;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar10 = *(int *)(iVar7 + 0x24);
        *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0x2c)) = iVar8;
        *(int *)(iVar7 + 0x24) = iVar10 + -1;
      }
      else {
        iVar10 = *(int *)(iVar7 + 0x28);
        *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0x2c)) = iVar8;
        *(int *)(iVar7 + 0x28) = iVar10 + 1;
      }
      iVar7 = param_1 + 0x14428 + (uint)*(byte *)(param_2 + 9) * 0xc;
      iVar10 = iVar7 + 0x3c;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar10 = *(int *)(iVar7 + 0x3c);
        *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0x44)) = iVar8;
        *(int *)(iVar7 + 0x3c) = iVar10 + -1;
        return;
      }
      break;
    case 6:
      iVar7 = iVar7 * 4;
      sVar1 = param_2[7];
      iVar10 = iVar9 * 0x10 + iVar10;
      sVar2 = param_2[6];
      *(uint *)(*(int *)(iVar10 + 0x14c9c) + iVar7) = CONCAT22(param_2[3],param_2[2]);
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14ca4)) = CONCAT22(sVar1,sVar2);
      sVar1 = param_2[7];
      sVar2 = param_2[6];
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14cec)) =
           ((int)param_2[3] - ((int)param_2[3] >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)param_2[2] - ((int)param_2[2] >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14cf4)) =
           ((int)sVar1 - ((int)sVar1 >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)sVar2 - ((int)sVar2 >> 0x1f)) >> 1 & 0xffff;
      iVar8 = iVar8 + *(int *)(param_1 + 0x153fc);
      iVar7 = param_1 + 0x14428 + (uint)*(byte *)((int)param_2 + 0x11) * 0xc;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar10 = *(int *)(iVar7 + 0x54);
        *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0x5c)) = iVar8;
        *(int *)(iVar7 + 0x54) = iVar10 + -1;
      }
      else {
        iVar10 = *(int *)(iVar7 + 0x58);
        *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0x5c)) = iVar8;
        *(int *)(iVar7 + 0x58) = iVar10 + 1;
      }
      iVar7 = param_1 + 0x14428 + (uint)*(byte *)((int)param_2 + 0x13) * 0xc;
      iVar10 = iVar7 + 0x6c;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar10 = *(int *)(iVar7 + 0x6c);
        *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0x74)) = iVar8;
        *(int *)(iVar7 + 0x6c) = iVar10 + -1;
        return;
      }
      break;
    case 7:
      iVar7 = iVar7 * 4;
      sVar4 = param_2[2];
      sVar5 = param_2[6];
      iVar10 = iVar9 * 0x10 + iVar10;
      sVar1 = param_2[3];
      sVar2 = param_2[5];
      sVar3 = param_2[7];
      sVar6 = param_2[4];
      *(uint *)(*(int *)(iVar10 + 0x14c98) + iVar7) = CONCAT22(param_2[1],*param_2);
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14c9c)) = CONCAT22(sVar1,sVar4);
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14ca0)) = CONCAT22(sVar2,sVar6);
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14ca4)) = CONCAT22(sVar3,sVar5);
      sVar1 = param_2[3];
      sVar2 = param_2[2];
      sVar3 = param_2[5];
      sVar4 = param_2[6];
      sVar5 = param_2[4];
      sVar6 = param_2[7];
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14ce8)) =
           ((int)param_2[1] - ((int)param_2[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14cec)) =
           ((int)sVar1 - ((int)sVar1 >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)sVar2 - ((int)sVar2 >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14cf0)) =
           ((int)sVar3 - ((int)sVar3 >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)sVar5 - ((int)sVar5 >> 0x1f)) >> 1 & 0xffff;
      *(uint *)(iVar7 + *(int *)(iVar10 + 0x14cf4)) =
           ((int)sVar6 - ((int)sVar6 >> 0x1f)) * 0x8000 & 0xffff0000U |
           (uint)((int)sVar4 - ((int)sVar4 >> 0x1f)) >> 1 & 0xffff;
      iVar8 = iVar8 + *(int *)(param_1 + 0x153fc);
      iVar7 = param_1 + 0x14428 +
              ((uint)*(byte *)((int)param_2 + 0x11) * 2 + (uint)*(byte *)(param_2 + 8)) * 0xc;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar10 = *(int *)(iVar7 + 0x84);
        *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0x8c)) = iVar8;
        *(int *)(iVar7 + 0x84) = iVar10 + -1;
      }
      else {
        iVar10 = *(int *)(iVar7 + 0x88);
        *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0x8c)) = iVar8;
        *(int *)(iVar7 + 0x88) = iVar10 + 1;
      }
      iVar7 = param_1 + 0x14428 +
              ((uint)*(byte *)((int)param_2 + 0x13) * 2 + (uint)*(byte *)(param_2 + 9)) * 0xc;
      iVar10 = iVar7 + 0xb4;
      if (*(char *)(param_1 + 0x590) == '\0') {
        iVar10 = *(int *)(iVar7 + 0xb4);
        *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0xbc)) = iVar8;
        *(int *)(iVar7 + 0xb4) = iVar10 + -1;
        return;
      }
    }
    iVar7 = *(int *)(iVar10 + 4);
    *(int *)(iVar7 * 4 + *(int *)(iVar10 + 8)) = iVar8;
    *(int *)(iVar10 + 4) = iVar7 + 1;
    return;
  }
  switch(*(undefined1 *)(param_2 + 10)) {
  default:
    goto switchD_00008894_caseD_0;
  case 1:
    iVar10 = iVar9 * 0x10 + iVar10;
    iVar9 = param_1 + 0x14428;
    *(uint *)(*(int *)(iVar10 + 0x14c98) + iVar7 * 4) = CONCAT22(param_2[1],*param_2);
    *(uint *)(iVar7 * 4 + *(int *)(iVar10 + 0x14ce8)) =
         ((int)param_2[1] - ((int)param_2[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
    iVar7 = (uint)*(byte *)(param_2 + 8) * 0xc;
    iVar10 = iVar9 + iVar7;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar11 = *(int *)(iVar9 + iVar7);
      *(int *)(iVar11 * 4 + *(int *)(iVar10 + 8)) = iVar8;
      *(int *)(iVar9 + iVar7) = iVar11 + -1;
      return;
    }
    break;
  case 2:
    iVar10 = iVar9 * 0x10 + iVar10;
    *(uint *)(*(int *)(iVar10 + 0x14c9c) + iVar7 * 4) = CONCAT22(param_2[3],param_2[2]);
    *(uint *)(iVar7 * 4 + *(int *)(iVar10 + 0x14cec)) =
         ((int)param_2[3] - ((int)param_2[3] >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)param_2[2] - ((int)param_2[2] >> 0x1f)) >> 1 & 0xffff;
    iVar7 = param_1 + 0x14428 + (uint)*(byte *)((int)param_2 + 0x11) * 0xc;
    iVar10 = iVar7 + 0x18;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar10 = *(int *)(iVar7 + 0x18);
      *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0x20)) = iVar8;
      *(int *)(iVar7 + 0x18) = iVar10 + -1;
      return;
    }
    break;
  case 3:
    iVar7 = iVar7 * 4;
    iVar10 = iVar9 * 0x10 + iVar10;
    *(uint *)(*(int *)(iVar10 + 0x14c98) + iVar7) = CONCAT22(param_2[1],*param_2);
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14c9c)) = CONCAT22(param_2[3],param_2[2]);
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14ce8)) =
         ((int)param_2[1] - ((int)param_2[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14cec)) =
         ((int)param_2[3] - ((int)param_2[3] >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)param_2[2] - ((int)param_2[2] >> 0x1f)) >> 1 & 0xffff;
    iVar7 = param_1 + 0x14428 +
            ((uint)*(byte *)((int)param_2 + 0x11) * 2 + (uint)*(byte *)(param_2 + 8)) * 0xc;
    iVar10 = iVar7 + 0x30;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar10 = *(int *)(iVar7 + 0x30);
      *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0x38)) = iVar8;
      *(int *)(iVar7 + 0x30) = iVar10 + -1;
      return;
    }
    break;
  case 5:
    iVar7 = iVar7 * 4;
    sVar1 = param_2[5];
    iVar10 = iVar9 * 0x10 + iVar10;
    sVar2 = param_2[4];
    *(uint *)(*(int *)(iVar10 + 0x14c98) + iVar7) = CONCAT22(param_2[1],*param_2);
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14ca0)) = CONCAT22(sVar1,sVar2);
    sVar1 = param_2[5];
    sVar2 = param_2[4];
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14ce8)) =
         ((int)param_2[1] - ((int)param_2[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14cf0)) =
         ((int)sVar1 - ((int)sVar1 >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)sVar2 - ((int)sVar2 >> 0x1f)) >> 1 & 0xffff;
    iVar7 = param_1 + 0x14428 + (uint)*(byte *)(param_2 + 8) * 0xc;
    iVar8 = (iVar11 + uVar12 * *(int *)(param_1 + 0x580) * 2) * 4 + *(int *)(param_1 + 0x153fc);
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar10 = *(int *)(iVar7 + 0x60);
      *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0x68)) = iVar8;
      *(int *)(iVar7 + 0x60) = iVar10 + -1;
    }
    else {
      iVar10 = *(int *)(iVar7 + 100);
      *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0x68)) = iVar8;
      *(int *)(iVar7 + 100) = iVar10 + 1;
    }
    iVar7 = param_1 + 0x14428 + (uint)*(byte *)(param_2 + 9) * 0xc;
    iVar8 = iVar8 + *(int *)(param_1 + 0x580) * 4;
    iVar10 = iVar7 + 0x78;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar10 = *(int *)(iVar7 + 0x78);
      *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0x80)) = iVar8;
      *(int *)(iVar7 + 0x78) = iVar10 + -1;
      return;
    }
    goto LAB_00009624;
  case 6:
    iVar7 = iVar7 * 4;
    sVar1 = param_2[7];
    iVar10 = iVar9 * 0x10 + iVar10;
    sVar2 = param_2[6];
    *(uint *)(*(int *)(iVar10 + 0x14c9c) + iVar7) = CONCAT22(param_2[3],param_2[2]);
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14ca4)) = CONCAT22(sVar1,sVar2);
    sVar1 = param_2[7];
    sVar2 = param_2[6];
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14cec)) =
         ((int)param_2[3] - ((int)param_2[3] >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)param_2[2] - ((int)param_2[2] >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14cf4)) =
         ((int)sVar1 - ((int)sVar1 >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)sVar2 - ((int)sVar2 >> 0x1f)) >> 1 & 0xffff;
    iVar7 = param_1 + 0x14428 + (uint)*(byte *)((int)param_2 + 0x11) * 0xc;
    iVar8 = (iVar11 + uVar12 * *(int *)(param_1 + 0x580) * 2) * 4 + *(int *)(param_1 + 0x153fc);
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar10 = *(int *)(iVar7 + 0x90);
      *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0x98)) = iVar8;
      *(int *)(iVar7 + 0x90) = iVar10 + -1;
    }
    else {
      iVar10 = *(int *)(iVar7 + 0x94);
      *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0x98)) = iVar8;
      *(int *)(iVar7 + 0x94) = iVar10 + 1;
    }
    iVar7 = param_1 + 0x14428 + (uint)*(byte *)((int)param_2 + 0x13) * 0xc;
    iVar8 = iVar8 + *(int *)(param_1 + 0x580) * 4;
    iVar10 = iVar7 + 0xa8;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar10 = *(int *)(iVar7 + 0xa8);
      *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0xb0)) = iVar8;
      *(int *)(iVar7 + 0xa8) = iVar10 + -1;
      return;
    }
    goto LAB_00009624;
  case 7:
    iVar7 = iVar7 * 4;
    sVar4 = param_2[2];
    sVar5 = param_2[6];
    iVar10 = iVar9 * 0x10 + iVar10;
    sVar1 = param_2[3];
    sVar2 = param_2[5];
    sVar3 = param_2[7];
    sVar6 = param_2[4];
    *(uint *)(*(int *)(iVar10 + 0x14c98) + iVar7) = CONCAT22(param_2[1],*param_2);
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14c9c)) = CONCAT22(sVar1,sVar4);
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14ca0)) = CONCAT22(sVar2,sVar6);
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14ca4)) = CONCAT22(sVar3,sVar5);
    sVar1 = param_2[3];
    sVar2 = param_2[2];
    sVar3 = param_2[5];
    sVar4 = param_2[6];
    sVar5 = param_2[4];
    sVar6 = param_2[7];
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14ce8)) =
         ((int)param_2[1] - ((int)param_2[1] >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)*param_2 - ((int)*param_2 >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14cec)) =
         ((int)sVar1 - ((int)sVar1 >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)sVar2 - ((int)sVar2 >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14cf0)) =
         ((int)sVar3 - ((int)sVar3 >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)sVar5 - ((int)sVar5 >> 0x1f)) >> 1 & 0xffff;
    *(uint *)(iVar7 + *(int *)(iVar10 + 0x14cf4)) =
         ((int)sVar6 - ((int)sVar6 >> 0x1f)) * 0x8000 & 0xffff0000U |
         (uint)((int)sVar4 - ((int)sVar4 >> 0x1f)) >> 1 & 0xffff;
    iVar7 = param_1 + 0x14428 +
            ((uint)*(byte *)((int)param_2 + 0x11) * 2 + (uint)*(byte *)(param_2 + 8)) * 0xc;
    iVar8 = (iVar11 + uVar12 * *(int *)(param_1 + 0x580) * 2) * 4 + *(int *)(param_1 + 0x153fc);
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar10 = *(int *)(iVar7 + 0xc0);
      *(int *)(iVar10 * 4 + *(int *)(iVar7 + 200)) = iVar8;
      *(int *)(iVar7 + 0xc0) = iVar10 + -1;
    }
    else {
      iVar10 = *(int *)(iVar7 + 0xc4);
      *(int *)(iVar10 * 4 + *(int *)(iVar7 + 200)) = iVar8;
      *(int *)(iVar7 + 0xc4) = iVar10 + 1;
    }
    iVar8 = iVar8 + *(int *)(param_1 + 0x580) * 4;
    iVar7 = param_1 + 0x14428 +
            ((uint)*(byte *)((int)param_2 + 0x13) * 2 + (uint)*(byte *)(param_2 + 9)) * 0xc;
    iVar10 = iVar7 + 0xf0;
    if (*(char *)(param_1 + 0x590) == '\0') {
      iVar10 = *(int *)(iVar7 + 0xf0);
      *(int *)(iVar10 * 4 + *(int *)(iVar7 + 0xf8)) = iVar8;
      *(int *)(iVar7 + 0xf0) = iVar10 + -1;
      return;
    }
LAB_00009624:
    iVar7 = *(int *)(iVar10 + 4);
    *(int *)(iVar7 * 4 + *(int *)(iVar10 + 8)) = iVar8;
    *(int *)(iVar10 + 4) = iVar7 + 1;
    goto switchD_00008894_caseD_0;
  }
  iVar7 = *(int *)(iVar10 + 4);
  *(int *)(iVar7 * 4 + *(int *)(iVar10 + 8)) = iVar8;
  *(int *)(iVar10 + 4) = iVar7 + 1;
switchD_00008894_caseD_0:
  return;
}

/* FUN_00009670 @ 0x9670 (28 bytes) */
int FUN_00009670()
{
  return "ATIRadeonX1000";
}

/* FUN_00009690 @ 0x9690 (4 bytes) */
int FUN_00009690()
{
  return;
}

/* FUN_000096a0 @ 0x96a0 (96 bytes) */
int FUN_000096a0(param_1)
  undefined4 *param_1;
{
  *param_1 = 0x5c8;
  param_1[1] = 0x10030000;
  param_1[2] = ((unsigned char *)0x00001002);
  param_1[3] = 0;
  param_1[4] = 0x1381;
  param_1[5] = 0;
  param_1[6] = ((unsigned char *)0x00001040);
  param_1[7] = 0;
  return param_1 + 8;
}

/* FUN_00009700 @ 0x9700 (528 bytes) */
int FUN_00009700(param_1, param_2)
  undefined4 *param_1;
  uint param_2;
{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  *param_1 = 0x850;
  param_1[1] = 0x102;
  param_1[2] = 0x854;
  if (param_2 == 1) {
    uVar7 = 0x26010001;
  }
  else {
    uVar7 = 0x6010001;
  }
  param_1[3] = uVar7;
  param_1[4] = 0x878;
  piVar2 = param_1 + 6;
  param_1[5] = 0xf688f688;
  if (1 < (int)param_2) {
    piVar3 = piVar2;
    uVar5 = 1;
    do {
      iVar6 = ((int)uVar5 >> 1) + (uint)((int)uVar5 < 0 && (uVar5 & 1) != 0);
      uVar4 = uVar5 + 2;
      *piVar3 = iVar6 + 0x855;
      piVar3[1] = (uint)(param_2 == uVar5 + 1) << 0xd | (uVar5 + 6) * 0x100 |
                  (uint)(param_2 == uVar4) << 0x1d | (uVar5 + 7) * 0x1000000 | 0x10001;
      piVar3[2] = iVar6 + 0x879;
      piVar2 = piVar3 + 4;
      piVar3[3] = -0x9770978;
      piVar3 = piVar2;
      uVar5 = uVar4;
    } while ((int)uVar4 < (int)param_2);
  }
  *piVar2 = 0x824;
  piVar2[1] = 1;
  if (0 < (int)param_2) {
    uVar4 = 0;
    uVar5 = param_2;
    do {
      uVar4 = uVar4 | uVar4 << 3 | 2;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  else {
    uVar4 = 0;
  }
  piVar2[2] = 0x825;
  piVar2[3] = uVar4;
  piVar2[4] = (int)0x000010c0;
  piVar2[5] = param_2 << 1 | 0x40000;
  piVar2[6] = 0x10c1;
  piVar3 = piVar2 + 8;
  piVar2[7] = param_2 - 1;
  if (0 < (int)param_2) {
    uVar5 = 0;
    iVar6 = 1;
    do {
      *piVar3 = (int)(((unsigned char *)0x0000101d) + uVar5);
      piVar3[1] = uVar5 << 1 | iVar6 << 6 | 0x28ffe000;
      piVar3[2] = uVar5 + 0x10c8;
      puVar1 = (uint *)(piVar3 + 3);
      piVar3 = piVar3 + 4;
      *puVar1 = uVar5 | uVar5 << 5 | 0x10;
      uVar5 = uVar5 + 1;
      iVar6 = iVar6 + 2;
      param_2 = param_2 - 1;
    } while (param_2 != 0);
    return piVar3;
  }
  return piVar3;
}

/* FUN_00009930 @ 0x9930 (80 bytes) */
int FUN_00009930(param_1, param_2, param_3, param_4)
  uint *param_1;
  uint param_2;
  uint *param_3;
  int param_4;
{
  uint uVar1;
  
  *param_1 = (param_4 + -1) * 0x10000 | param_2 | 0x8000;
  for (; param_1 = param_1 + 1, param_4 != 0; param_4 = param_4 + -1) {
    uVar1 = *param_3;
    param_3 = param_3 + 1;
    *param_1 = uVar1;
  }
  return param_1;
}

/* FUN_00009980 @ 0x9980 (48 bytes) */
int FUN_00009980(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
  *param_1 = 0x1094;
  param_1[1] = param_2;
  uVar1 = ((int (*)())FUN_00009930)(param_1 + 2,0x1095,param_4,param_3);
  return uVar1;
}

/* FUN_000099b0 @ 0x99b0 (264 bytes) */
int FUN_000099b0(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 *param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
  undefined4 param_6;
{
  int iVar1;
  
  if (param_4 != 0) {
    param_1 = (undefined4 *)((int (*)())FUN_00009980)(param_1,0x10000,(param_5 & 0xfffffff) << 2,param_4);
  }
  if (param_2 != 0) {
    param_1 = (undefined4 *)((int (*)())FUN_00009980)(param_1,0,(uint)(param_3 * 0x18) >> 2,param_2);
  }
  *param_1 = 0x1180;
  param_1[1] = 0;
  param_1[2] = 0x11ad;
  param_1[3] = 0;
  param_1[4] = 0x1181;
  param_1[5] = param_6;
  param_1[6] = 0x118c;
  iVar1 = (param_3 + -1) * 0x10000;
  param_1[7] = iVar1;
  param_1[8] = 0x118d;
  param_1[9] = iVar1;
  param_1[10] = 0x118e;
  param_1[0xb] = 0;
  param_1[0xc] = 0x1189;
  param_1[0xd] = 0;
  return param_1 + 0xe;
}

/* FUN_00009ac0 @ 0x9ac0 (424 bytes) */
int FUN_00009ac0(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  float *param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  
  *param_1 = 0x82d;
  param_1[1] = 4;
  param_1[2] = 0xc0103500;
  param_1[3] = 0x4083d;
  if (param_2 == (float *)0x0) {
    local_30 = 0.0;
    local_2c = 1.0;
    local_38 = 0.0;
    local_34 = 1.0;
  }
  else {
    local_30 = (float)((double)CONCAT44(0x43300000,param_5) - DOUBLE_0000d418);
    local_38 = (float)((double)CONCAT44(0x43300000,param_4) - DOUBLE_0000d418);
    local_2c = param_2[3] / local_30;
    local_34 = param_2[1] / local_38;
    local_38 = *param_2 / local_38;
    local_30 = param_2[2] / local_30;
  }
  uVar2 = *param_3;
  param_1[4] = uVar2;
  uVar1 = param_3[2];
  param_1[5] = uVar1;
  param_1[6] = local_38;
  param_1[7] = local_30;
  param_1[8] = uVar2;
  uVar2 = param_3[3];
  param_1[9] = uVar2;
  param_1[10] = local_38;
  param_1[0xb] = local_2c;
  uVar3 = param_3[1];
  param_1[0xc] = uVar3;
  param_1[0xd] = uVar2;
  param_1[0xe] = local_34;
  param_1[0xf] = local_2c;
  param_1[0x10] = uVar3;
  param_1[0x11] = uVar1;
  param_1[0x12] = local_34;
  param_1[0x13] = local_30;
  param_1[0x14] = 0x1393;
  param_1[0x15] = 10;
  return param_1 + 0x16;
}

/* FUN_00009c80 @ 0x9c80 (1160 bytes) */
int FUN_00009c80(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  double dVar13;
  double dVar14;
  undefined4 local_78;
  float local_74;
  undefined4 local_70;
  float local_6c;
  undefined4 local_68;
  uint uStack_64;
  undefined4 local_60;
  uint uStack_5c;
  
  puVar6 = PTR_0000f1a0;
  puVar9 = *(undefined4 **)(param_1 + 0x34);
  uVar12 = *(uint *)(param_1 + 0x588);
  uVar4 = *(uint *)(param_1 + 0x578) >> 2;
  uVar5 = *(uint *)(param_1 + 0x57c) >> 1;
  if (*(undefined4 **)(param_1 + 0x38) <= puVar9 + 0x90) {
    puVar7 = *(uint **)(param_1 + 0x30);
    *puVar7 = (int)puVar9 - (int)puVar7 >> 2 | *puVar7;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar6,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar10 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar10 + 0x20;
    *(int *)(param_1 + 0x30) = iVar10 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar10 + 0x20 + *(int *)(iVar10 + 0x10) * 4;
    *(undefined4 *)(iVar10 + 0x1c) = 0;
    puVar9 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar7 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar9 + 0x90;
  *puVar7 = (int)puVar9 - (int)puVar7 >> 2 | *puVar7;
  *(undefined4 **)(param_1 + 0x30) = puVar9;
  *puVar9 = 0x42000000;
  puVar9[1] = param_2;
  puVar9[2] = (uint)(param_3 != 0);
  puVar9 = puVar9 + 3;
  iVar10 = 7;
  do {
    *puVar9 = 0x80000000;
    puVar9 = puVar9 + 1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  uVar8 = ((int (*)())FUN_000096a0)(puVar9);
  puVar9 = (undefined4 *)((int (*)())FUN_00009700)(uVar8,1);
  *puVar9 = ((unsigned char *)0x00001041);
  puVar9[1] = 3;
  puVar9[2] = 0x1100;
  puVar9[3] = 0xa92;
  puVar9[4] = 0x1110;
  puVar9[5] = 0;
  puVar9[6] = 0x1120;
  uVar11 = uVar4 - 1 | (uVar5 - 1) * 0x800 | 0x80000000;
  puVar9[7] = uVar11;
  puVar9[8] = 0x1130;
  puVar9[9] = 0xa60c;
  puVar9[10] = 0x1140;
  iVar10 = (uVar12 >> 2) - 1;
  puVar9[0xb] = iVar10;
  puVar9[0xc] = 0x1101;
  puVar9[0xd] = 0x10000a92;
  puVar9[0xe] = 0x1111;
  puVar9[0xf] = 0;
  puVar9[0x10] = 0x1121;
  puVar9[0x11] = uVar11;
  puVar9[0x12] = 0x1131;
  puVar9[0x13] = 0x4340c;
  puVar9[0x14] = 0x1141;
  puVar9[0x15] = iVar10;
  fVar1 = *(float *)(param_1 + 300);
  fVar2 = *(float *)(param_1 + 0x138);
  fVar3 = *(float *)(param_1 + 0x130);
  dVar13 = _cos((double)fVar1);
  dVar14 = _sin((double)fVar1);
  DAT_0000f004 = (float)(dVar13 * (double)fVar2 * (double)fVar3);
  DAT_0000f024 = (float)((double)fVar3 * (double)fVar2 * -dVar14);
  DAT_0000f028 = -DAT_0000f024;
  DAT_0000f018 = ((DAT_0000f024 + (1.0 - DAT_0000f004)) * 128.0) / 255.0;
  DAT_0000f014 = (((1.0 - DAT_0000f004) - DAT_0000f024) * 128.0) / 255.0;
  DAT_0000f008 = DAT_0000f004;
  DAT_0000f00c = DAT_0000f004;
  DAT_0000f010 = DAT_0000f004;
  DAT_0000f01c = DAT_0000f014;
  DAT_0000f020 = DAT_0000f018;
  DAT_0000f02c = DAT_0000f024;
  DAT_0000f030 = DAT_0000f028;
  puVar9 = (undefined4 *)((int (*)())FUN_000099b0)(puVar9 + 0x16,&DAT_0000ea9c,4,&DAT_0000f004,3,3);
  *puVar9 = 0x11a9;
  puVar9[1] = 0x1b00;
  puVar9[2] = 0x11aa;
  puVar9[3] = 0xf;
  puVar9[4] = 0x11ab;
  puVar9[5] = 0xf;
  puVar9[6] = 0x11ac;
  puVar9[7] = 0xf;
  uStack_64 = uVar4 ^ 0x80000000;
  uStack_5c = uVar5 ^ 0x80000000;
  local_60 = 0x43300000;
  local_68 = 0x43300000;
  local_70 = 0;
  local_78 = 0;
  local_6c = (float)((double)CONCAT44(0x43300000,uStack_5c) - 4503601774854144.0);
  local_74 = (float)((double)CONCAT44(0x43300000,uStack_64) - 4503601774854144.0);
  ((int (*)())FUN_00009ac0)(puVar9 + 8,0,&local_78,uVar4,uVar5);
  puVar6 = PTR_0000f1a0;
  puVar7 = *(uint **)(param_1 + 0x30);
  *puVar7 = *(int *)(param_1 + 0x34) - (int)puVar7 >> 2 | *puVar7;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar6,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar10 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar10 + 0x20;
  *(int *)(param_1 + 0x30) = iVar10 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar10 + 0x20 + *(int *)(iVar10 + 0x10) * 4;
  *(undefined4 *)(iVar10 + 0x1c) = 0;
  return;
}

/* FUN_0000a110 @ 0xa110 (964 bytes) */
int FUN_0000a110(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  undefined *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  float local_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  
  puVar2 = PTR_0000f1a0;
  puVar5 = *(undefined4 **)(param_1 + 0x34);
  uVar7 = *(uint *)(param_1 + 0x588);
  uVar8 = *(uint *)(param_1 + 0x57c);
  uVar1 = *(uint *)(param_1 + 0x578) >> 2;
  if (*(undefined4 **)(param_1 + 0x38) <= puVar5 + 0x78) {
    puVar3 = *(uint **)(param_1 + 0x30);
    *puVar3 = (int)puVar5 - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar2,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar6 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar6 + 0x20;
    *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
    *(undefined4 *)(iVar6 + 0x1c) = 0;
    puVar5 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar3 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar5 + 0x78;
  *puVar3 = (int)puVar5 - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(param_1 + 0x30) = puVar5;
  *puVar5 = 0x3f000000;
  puVar5[1] = param_2;
  puVar5[2] = (uint)(param_3 != 0);
  puVar5 = puVar5 + 3;
  iVar6 = 9;
  do {
    *puVar5 = 0x80000000;
    puVar5 = puVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  uVar4 = ((int (*)())FUN_000096a0)(puVar5);
  puVar5 = (undefined4 *)((int (*)())FUN_00009700)(uVar4,1);
  *puVar5 = ((unsigned char *)0x00001041);
  puVar5[1] = 1;
  puVar5[2] = 0x1100;
  puVar5[3] = 0xa92;
  puVar5[4] = 0x1110;
  puVar5[5] = 0;
  puVar5[6] = 0x1120;
  puVar5[7] = uVar1 - 1 | (uVar8 - 1) * 0x800 | 0x80000000;
  puVar5[8] = 0x1130;
  puVar5[9] = 0xa60c;
  puVar5[10] = 0x1140;
  puVar5[0xb] = (uVar7 >> 2) - 1;
  DAT_0000f034 = *(undefined4 *)(param_1 + 0x138);
  DAT_0000f044 = ((1.0 - *(float *)(param_1 + 0x138)) * 128.0) / 255.0 + *(float *)(param_1 + 0x134)
  ;
  DAT_0000f038 = DAT_0000f034;
  DAT_0000f03c = DAT_0000f034;
  DAT_0000f040 = DAT_0000f034;
  DAT_0000f048 = DAT_0000f044;
  DAT_0000f04c = DAT_0000f044;
  DAT_0000f050 = DAT_0000f044;
  puVar5 = (undefined4 *)((int (*)())FUN_000099b0)(puVar5 + 0xc,&DAT_0000eafc,2,&DAT_0000f034,2,2);
  *puVar5 = 0x11a9;
  puVar5[1] = 0x1b00;
  puVar5[2] = 0x11aa;
  puVar5[3] = 0xf;
  puVar5[4] = 0x11ab;
  puVar5[5] = 0xf;
  puVar5[6] = 0x11ac;
  puVar5[7] = 0xf;
  uStack_44 = uVar1 ^ 0x80000000;
  uStack_3c = uVar8 ^ 0x80000000;
  local_40 = 0x43300000;
  local_48 = 0x43300000;
  local_50 = 0;
  local_58 = 0;
  local_4c = (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0);
  local_54 = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0);
  ((int (*)())FUN_00009ac0)(puVar5 + 8,0,&local_58,uVar1,uVar8);
  puVar2 = PTR_0000f1a0;
  puVar3 = *(uint **)(param_1 + 0x30);
  *puVar3 = *(int *)(param_1 + 0x34) - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar2,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar6 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar6 + 0x20;
  *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
  *(undefined4 *)(iVar6 + 0x1c) = 0;
  return;
}

/* FUN_0000a4e0 @ 0xa4e0 (1304 bytes) */
int FUN_0000a4e0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 local_48;
  float local_44;
  undefined4 local_40;
  float local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  puVar1 = PTR_0000f1a0;
  puVar8 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar8 + 0xb0) {
    puVar2 = *(uint **)(param_1 + 0x30);
    *puVar2 = (int)puVar8 - (int)puVar2 >> 2 | *puVar2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar6 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar6 + 0x20;
    *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
    *(undefined4 *)(iVar6 + 0x1c) = 0;
    puVar8 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar2 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar8 + 0xb0;
  *puVar2 = (int)puVar8 - (int)puVar2 >> 2 | *puVar2;
  *(undefined4 **)(param_1 + 0x30) = puVar8;
  *puVar8 = 0x44000000;
  puVar8[1] = param_2;
  puVar8[2] = 0x11;
  puVar8[3] = (uint)(*(int *)(param_2 * 4 + param_1 + 0x55c + 0x554) != 0);
  puVar8[4] = *(undefined4 *)(param_1 + 0x11c);
  puVar8 = puVar8 + 5;
  iVar6 = 5;
  do {
    *puVar8 = 0x80000000;
    puVar8 = puVar8 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  uVar3 = ((int (*)())FUN_000096a0)(puVar8);
  puVar8 = (undefined4 *)((int (*)())FUN_00009700)(uVar3,1);
  *puVar8 = 0x1100;
  puVar8[1] = 0xa92;
  puVar8[2] = 0x1110;
  puVar8[3] = 0;
  puVar8[4] = 0x1120;
  uVar7 = *(uint *)(param_1 + 0x57c);
  uVar4 = *(uint *)(param_1 + 0x578);
  puVar8[5] = (uVar7 - 1) * 0x800 | uVar4 - 1 | 0x80000000;
  puVar8[6] = 0x1130;
  puVar8[7] = 0x10120800;
  puVar8[8] = 0x1140;
  uVar5 = *(uint *)(param_1 + 0x588);
  puVar8[9] = uVar5 - 1;
  puVar8[10] = 0x1101;
  puVar8[0xb] = 0x10000a92;
  puVar8[0xc] = 0x1111;
  puVar8[0xd] = 0;
  puVar8[0xe] = 0x1121;
  puVar8[0xf] = ((uVar7 >> 1) - 1) * 0x800 | (uVar4 >> 1) - 1 | 0x80000000;
  puVar8[0x10] = 0x1131;
  puVar8[0x11] = 0x18044803;
  puVar8[0x12] = 0x1141;
  puVar8[0x13] = (uVar5 >> 1) - 1;
  puVar8[0x14] = ((unsigned char *)0x00001041);
  puVar8[0x15] = 3;
  puVar8 = (undefined4 *)((int (*)())FUN_000099b0)(puVar8 + 0x16,&DAT_0000eb7c,7,&DAT_0000eb2c,5,3);
  iVar6 = *(int *)(param_3 + 0xc);
  if (((iVar6 == 0x61726762) || (iVar6 == 0x61723135)) || (iVar6 != 0x72676261)) {
    *puVar8 = 0x11a9;
    puVar8[1] = 0x1b00;
  }
  else {
    *puVar8 = 0x11a9;
    puVar8[1] = 0x6c00;
  }
  puVar8[2] = 0x11aa;
  puVar8[3] = 0xf;
  puVar8[4] = 0x11ab;
  puVar8[5] = 0xf;
  puVar8[6] = 0x11ac;
  puVar8[7] = 0xf;
  puVar8[8] = 0x1393;
  puVar8[9] = 10;
  if (iVar6 == 0x61723135) {
    puVar8[10] = 0x138e;
    puVar8[0xb] = *(uint *)(param_3 + 8) >> 1 & 0x3ffe | 0x680000;
  }
  else {
    puVar8[10] = 0x138e;
    puVar8[0xb] = *(uint *)(param_3 + 8) >> 2 & 0x3ffe | 0xd00000;
  }
  uStack_34 = *(undefined4 *)(param_1 + 0x578);
  uStack_2c = *(undefined4 *)(param_1 + 0x57c);
  local_30 = 0x43300000;
  local_38 = 0x43300000;
  local_40 = 0;
  local_48 = 0;
  local_44 = (float)((double)CONCAT44(0x43300000,uStack_34) - 4503599627370496.0);
  local_3c = (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503599627370496.0);
  puVar8 = (undefined4 *)((int (*)())FUN_00009ac0)(puVar8 + 0xc,0,&local_48,uStack_34,uStack_2c);
  *puVar8 = 0x5c8;
  puVar8[1] = 0x10030000;
  puVar1 = PTR_0000f1a0;
  puVar2 = *(uint **)(param_1 + 0x30);
  *puVar2 = *(int *)(param_1 + 0x34) - (int)puVar2 >> 2 | *puVar2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar6 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar6 + 0x20;
  *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
  *(undefined4 *)(iVar6 + 0x1c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + param_1 + 0x55c + 0x570) =
       *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x18);
  return;
}

/* FUN_0000aa00 @ 0xaa00 (1152 bytes) */
int FUN_0000aa00(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  float local_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  
  puVar2 = PTR_0000f1a0;
  puVar6 = *(undefined4 **)(param_1 + 0x34);
  uVar3 = *(uint *)(param_1 + 0x588);
  uVar8 = *(uint *)(param_1 + 0x57c);
  uVar1 = *(uint *)(param_1 + 0x578) >> 1;
  if (*(undefined4 **)(param_1 + 0x38) <= puVar6 + 0x88) {
    puVar4 = *(uint **)(param_1 + 0x30);
    *puVar4 = (int)puVar6 - (int)puVar4 >> 2 | *puVar4;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar2,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar7 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar7 + 0x20;
    *(int *)(param_1 + 0x30) = iVar7 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar7 + 0x20 + *(int *)(iVar7 + 0x10) * 4;
    *(undefined4 *)(iVar7 + 0x1c) = 0;
    puVar6 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar4 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar6 + 0x88;
  *puVar4 = (int)puVar6 - (int)puVar4 >> 2 | *puVar4;
  *(undefined4 **)(param_1 + 0x30) = puVar6;
  *puVar6 = 0x43000000;
  puVar6[1] = param_2;
  puVar6[2] = 0x11;
  puVar6[3] = (uint)(*(int *)(param_2 * 4 + param_1 + 0x55c + 0x554) != 0);
  puVar6[4] = *(undefined4 *)(param_1 + 0x11c);
  puVar6 = puVar6 + 5;
  iVar7 = 6;
  do {
    *puVar6 = 0x80000000;
    puVar6 = puVar6 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar5 = ((int (*)())FUN_000096a0)(puVar6);
  puVar6 = (undefined4 *)((int (*)())FUN_00009700)(uVar5,1);
  *puVar6 = ((unsigned char *)0x00001041);
  puVar6[1] = 3;
  puVar6[2] = 0x1100;
  puVar6[3] = 0xa92;
  puVar6[4] = 0x1110;
  puVar6[5] = 0;
  puVar6[6] = 0x1120;
  puVar6[7] = uVar1 - 1 | (uVar8 - 1) * 0x800 | 0x80000000;
  puVar6[8] = 0x1130;
  puVar6[9] = 0x10060803;
  puVar6[10] = 0x1140;
  iVar7 = (uVar3 >> 1) - 1;
  puVar6[0xb] = iVar7;
  puVar6[0xc] = 0x1101;
  puVar6[0xd] = 0x10000a92;
  puVar6[0xe] = 0x1111;
  puVar6[0xf] = 0;
  puVar6[0x10] = 0x1121;
  puVar6[0x11] = uVar1 - 1 |
                 (((int)uVar8 >> 1) + (uint)((int)uVar8 < 0 && (uVar8 & 1) != 0) + -1) * 0x800 |
                 0x80000000;
  puVar6[0x12] = 0x1131;
  puVar6[0x13] = 0x1810c003;
  puVar6[0x14] = 0x1141;
  puVar6[0x15] = iVar7;
  puVar6 = (undefined4 *)((int (*)())FUN_000099b0)(puVar6 + 0x16,&DAT_0000ec24,4,0,0,3);
  *puVar6 = 0x11a9;
  puVar6[1] = 0x1b00;
  puVar6[2] = 0x11aa;
  puVar6[3] = 0xf;
  puVar6[4] = 0x11ab;
  puVar6[5] = 0xf;
  puVar6[6] = 0x11ac;
  puVar6[7] = 0xf;
  puVar6[8] = 0x1393;
  puVar6[9] = 10;
  puVar6[10] = 0x138e;
  puVar6[0xb] = *(uint *)(param_3 + 8) >> 2 & 0x3ffe | 0xd00000;
  uStack_44 = uVar1 ^ 0x80000000;
  uStack_3c = uVar8 ^ 0x80000000;
  local_40 = 0x43300000;
  local_48 = 0x43300000;
  local_50 = 0;
  local_58 = 0;
  local_4c = (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0);
  local_54 = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0);
  puVar6 = (undefined4 *)((int (*)())FUN_00009ac0)(puVar6 + 0xc,0,&local_58,uVar1,uVar8);
  *puVar6 = 0x5c8;
  puVar6[1] = 0x10030000;
  puVar2 = PTR_0000f1a0;
  puVar4 = *(uint **)(param_1 + 0x30);
  *puVar4 = *(int *)(param_1 + 0x34) - (int)puVar4 >> 2 | *puVar4;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar2,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar7 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar7 + 0x20;
  *(int *)(param_1 + 0x30) = iVar7 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar7 + 0x20 + *(int *)(iVar7 + 0x10) * 4;
  *(undefined4 *)(iVar7 + 0x1c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + param_1 + 0x55c + 0x570) =
       *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x18);
  return;
}

/* FUN_0000ae80 @ 0xae80 (2380 bytes) */
void FUN_0000ae80(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  undefined *puVar19;
  uint *puVar20;
  int iVar21;
  undefined4 uVar22;
  int iVar23;
  short sVar24;
  short sVar25;
  undefined4 *puVar26;
  float local_1e8;
  float local_1e4;
  float local_1e0;
  float local_1dc;
  float local_1d8;
  float local_1d4;
  float local_1d0;
  float local_1cc;
  undefined4 local_1c8;
  uint uStack_1c4;
  undefined4 local_1c0;
  int iStack_1bc;
  undefined4 local_1b8;
  undefined4 uStack_1b4;
  undefined4 local_1b0;
  uint uStack_1ac;
  undefined4 local_198;
  uint uStack_194;
  undefined4 local_190;
  int iStack_18c;
  undefined4 local_188;
  undefined4 uStack_184;
  undefined4 local_180;
  uint uStack_17c;
  undefined4 local_168;
  uint uStack_164;
  undefined4 local_160;
  uint uStack_15c;
  undefined4 local_158;
  int iStack_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined4 local_148;
  uint uStack_144;
  undefined4 local_140;
  uint uStack_13c;
  undefined4 local_138;
  int iStack_134;
  undefined4 local_130;
  undefined4 uStack_12c;
  undefined4 local_128;
  uint uStack_124;
  undefined4 local_120;
  uint uStack_11c;
  undefined4 local_118;
  uint uStack_114;
  undefined4 local_110;
  uint uStack_10c;
  undefined4 local_108;
  uint uStack_104;
  undefined4 local_100;
  uint uStack_fc;
  undefined4 local_f8;
  uint uStack_f4;
  undefined4 local_f0;
  uint uStack_ec;
  undefined4 local_e8;
  uint uStack_e4;
  undefined4 local_e0;
  uint uStack_dc;
  undefined4 local_d8;
  uint uStack_d4;
  undefined4 local_c8;
  int iStack_c4;
  undefined4 local_c0;
  uint uStack_bc;
  undefined4 local_b8;
  int iStack_b4;
  undefined4 local_b0;
  uint uStack_ac;
  undefined4 local_a8;
  uint uStack_a4;
  undefined4 local_a0;
  uint uStack_9c;
  longlong local_90;
  undefined4 local_88;
  uint uStack_84;
  longlong local_80;
  undefined4 local_78;
  uint uStack_74;
  
  sVar7 = *(short *)(param_1 + 0x126);
  if ((int)sVar7 == 0) {
    iVar21 = *(int *)(param_1 + 0x578);
    if ((*(short *)(param_1 + 0x12a) != iVar21) || (*(short *)(param_1 + 0x124) != 0)) {
      iVar23 = *(int *)(param_1 + 0x57c);
      goto LAB_0000b054;
    }
    iVar23 = *(int *)(param_1 + 0x57c);
    if (*(short *)(param_1 + 0x128) != iVar23) goto LAB_0000b054;
    local_1c8 = 0x43300000;
    local_1c0 = 0x43300000;
    local_1b0 = 0x43300000;
    local_198 = 0x43300000;
    local_190 = 0x43300000;
    local_180 = 0x43300000;
    uStack_1ac = (int)*(short *)(param_1 + 0x112) ^ 0x80000000;
    uStack_1c4 = (int)*(short *)(param_1 + 0x10e) ^ 0x80000000;
    uStack_17c = (int)*(short *)(param_1 + 0x110) ^ 0x80000000;
    uStack_194 = (int)*(short *)(param_1 + 0x10c) ^ 0x80000000;
    uStack_164 = (int)*(short *)(param_1 + 0x112) - (int)*(short *)(param_1 + 0x10e) ^ 0x80000000;
    uStack_15c = (int)*(short *)(param_1 + 0x110) - (int)*(short *)(param_1 + 0x10c) ^ 0x80000000;
    uStack_1b4 = *(undefined4 *)(param_1 + 0x60);
    uStack_184 = *(undefined4 *)(param_1 + 100);
    local_1b8 = 0x43300000;
    local_188 = 0x43300000;
    fVar1 = (float)((double)CONCAT44(0x43300000,iVar21) - 4503599627370496.0);
    fVar2 = (float)((double)CONCAT44(0x43300000,iVar23) - 4503599627370496.0);
    local_1e4 = (float)((double)CONCAT44(0x43300000,uStack_1b4) - 4503599627370496.0);
    fVar3 = (float)((double)CONCAT44(0x43300000,uStack_184) - 4503599627370496.0);
    local_1e8 = ((float)((double)CONCAT44(0x43300000,uStack_1c4) - 4503601774854144.0) * fVar1) /
                local_1e4;
    local_1e4 = ((float)((double)CONCAT44(0x43300000,uStack_1ac) - 4503601774854144.0) * fVar1) /
                local_1e4;
    local_1e0 = ((float)((double)CONCAT44(0x43300000,uStack_194) - 4503601774854144.0) * fVar2) /
                fVar3;
    local_160 = 0x43300000;
    local_168 = 0x43300000;
    local_1d0 = 0.0;
    local_1d8 = 0.0;
    local_1cc = (float)((double)CONCAT44(0x43300000,uStack_15c) - 4503601774854144.0);
    local_1d4 = (float)((double)CONCAT44(0x43300000,uStack_164) - 4503601774854144.0);
    local_1dc = ((float)((double)CONCAT44(0x43300000,uStack_17c) - 4503601774854144.0) * fVar2) /
                fVar3;
    iStack_1bc = iVar21;
    iStack_18c = iVar23;
  }
  else {
    iVar23 = *(int *)(param_1 + 0x57c);
    iVar21 = *(int *)(param_1 + 0x578);
LAB_0000b054:
    sVar8 = *(short *)(param_1 + 0x112);
    local_158 = 0x43300000;
    local_140 = 0x43300000;
    uStack_13c = (int)sVar8 ^ 0x80000000;
    uStack_14c = *(undefined4 *)(param_1 + 0x60);
    uStack_114 = (int)sVar7 ^ 0x80000000;
    local_150 = 0x43300000;
    sVar9 = *(short *)(param_1 + 0x10e);
    local_118 = 0x43300000;
    local_148 = 0x43300000;
    local_138 = 0x43300000;
    local_128 = 0x43300000;
    local_120 = 0x43300000;
    uStack_124 = (int)*(short *)(param_1 + 0x10c) ^ 0x80000000;
    uStack_144 = (int)sVar9 ^ 0x80000000;
    uStack_11c = (int)*(short *)(param_1 + 0x110) ^ 0x80000000;
    fVar1 = (float)((double)CONCAT44(0x43300000,iVar21) - 4503599627370496.0);
    uStack_12c = *(undefined4 *)(param_1 + 100);
    local_130 = 0x43300000;
    fVar2 = (float)((double)CONCAT44(0x43300000,uStack_14c) - 4503599627370496.0);
    fVar11 = (fVar1 * (float)((double)CONCAT44(0x43300000,uStack_13c) - 4503601774854144.0)) / fVar2
    ;
    fVar3 = (float)((double)CONCAT44(0x43300000,uStack_114) - 4503601774854144.0);
    fVar4 = (float)((double)CONCAT44(0x43300000,iVar23) - 4503599627370496.0);
    fVar2 = ((float)((double)CONCAT44(0x43300000,uStack_144) - 4503601774854144.0) * fVar1) / fVar2;
    fVar1 = (float)((double)CONCAT44(0x43300000,uStack_12c) - 4503599627370496.0);
    fVar14 = (fVar4 * (float)((double)CONCAT44(0x43300000,uStack_11c) - 4503601774854144.0)) / fVar1
    ;
    fVar1 = ((float)((double)CONCAT44(0x43300000,uStack_124) - 4503601774854144.0) * fVar4) / fVar1;
    iStack_154 = iVar21;
    iStack_134 = iVar23;
    if (fVar11 <= fVar3) goto LAB_0000b7d0;
    if (fVar11 <= fVar3) {
      sVar25 = *(short *)(param_1 + 0x12a);
LAB_0000b1e4:
      uStack_104 = (int)sVar25 ^ 0x80000000;
      local_108 = 0x43300000;
      fVar4 = (float)((double)CONCAT44(0x43300000,uStack_104) - 4503601774854144.0);
      if (fVar4 <= fVar2) goto LAB_0000b7d0;
      fVar12 = fVar2;
      if (fVar2 - fVar3 < 0.0) {
        fVar12 = fVar3;
      }
      if (-(fVar2 - fVar3) < 0.0) {
        fVar12 = fVar2;
      }
    }
    else {
      sVar25 = *(short *)(param_1 + 0x12a);
      local_110 = 0x43300000;
      uStack_10c = (int)sVar25 ^ 0x80000000;
      if ((float)((double)CONCAT44(0x43300000,uStack_10c) - 4503601774854144.0) <= fVar11)
      goto LAB_0000b1e4;
      fVar12 = fVar3;
      fVar4 = fVar11;
      if (fVar3 <= fVar2) {
        fVar12 = fVar2;
      }
    }
    sVar10 = *(short *)(param_1 + 0x124);
    local_100 = 0x43300000;
    uStack_fc = (int)sVar10 ^ 0x80000000;
    fVar3 = (float)((double)CONCAT44(0x43300000,uStack_fc) - 4503601774854144.0);
    if (fVar14 <= fVar3) goto LAB_0000b7d0;
    if (fVar14 <= fVar3) {
      sVar24 = *(short *)(param_1 + 0x128);
LAB_0000b2b8:
      uStack_ec = (int)sVar24 ^ 0x80000000;
      local_f0 = 0x43300000;
      fVar5 = (float)((double)CONCAT44(0x43300000,uStack_ec) - 4503601774854144.0);
      if (fVar5 <= fVar1) goto LAB_0000b7d0;
      fVar15 = fVar1;
      if (fVar1 - fVar3 < 0.0) {
        fVar15 = fVar3;
      }
      if (-(fVar1 - fVar3) < 0.0) {
        fVar15 = fVar1;
      }
    }
    else {
      sVar24 = *(short *)(param_1 + 0x128);
      local_f8 = 0x43300000;
      uStack_f4 = (int)sVar24 ^ 0x80000000;
      if ((float)((double)CONCAT44(0x43300000,uStack_f4) - 4503601774854144.0) <= fVar14)
      goto LAB_0000b2b8;
      fVar15 = fVar3;
      fVar5 = fVar14;
      if (fVar3 <= fVar1) {
        fVar15 = fVar1;
      }
    }
    uStack_bc = (int)sVar25 - (int)sVar7 ^ 0x80000000;
    local_c8 = 0x43300000;
    local_c0 = 0x43300000;
    local_b8 = 0x43300000;
    local_b0 = 0x43300000;
    local_a8 = 0x43300000;
    local_a0 = 0x43300000;
    local_e8 = 0x43300000;
    local_e0 = 0x43300000;
    local_d8 = 0x43300000;
    uStack_ac = (int)sVar24 - (int)sVar10 ^ 0x80000000;
    uStack_a4 = (int)sVar25 + (int)sVar7 ^ 0x80000000;
    uStack_9c = (int)sVar24 + (int)sVar10 ^ 0x80000000;
    uStack_e4 = (int)sVar8 - (int)sVar9 ^ 0x80000000;
    uStack_d4 = (int)*(short *)(param_1 + 0x110) - (int)*(short *)(param_1 + 0x10c) ^ 0x80000000;
    uStack_dc = (int)sVar8 - (int)sVar9 ^ 0x80000000;
    fVar3 = (float)((double)CONCAT44(0x43300000,iVar21) - 4503599627370496.0);
    fVar6 = (float)((double)CONCAT44(0x43300000,iVar23) - 4503599627370496.0);
    fVar17 = fVar3 / (float)((double)CONCAT44(0x43300000,uStack_bc) - 4503601774854144.0);
    local_1d0 = (float)((double)CONCAT44(0x43300000,uStack_d4) - 4503601774854144.0);
    fVar18 = fVar6 / (float)((double)CONCAT44(0x43300000,uStack_ac) - 4503601774854144.0);
    fVar13 = (float)((double)CONCAT44(0x43300000,uStack_a4) - 4503601774854144.0) * 0.5;
    fVar16 = (float)((double)CONCAT44(0x43300000,uStack_9c) - 4503601774854144.0) * 0.5;
    local_1d8 = ((fVar12 - fVar2) / (fVar11 - fVar2)) *
                (float)((double)CONCAT44(0x43300000,uStack_e4) - 4503601774854144.0);
    local_1d4 = (1.0 - (fVar11 - fVar4) / (fVar11 - fVar2)) *
                (float)((double)CONCAT44(0x43300000,uStack_dc) - 4503601774854144.0);
    local_1cc = (1.0 - (fVar14 - fVar5) / (fVar14 - fVar1)) * local_1d0;
    local_1d0 = ((fVar15 - fVar1) / (fVar14 - fVar1)) * local_1d0;
    local_78 = 0x43300000;
    local_88 = 0x43300000;
    local_1e4 = fVar17 * (fVar4 - fVar13) + fVar13;
    fVar13 = fVar17 * (fVar12 - fVar13) + fVar13;
    local_1e8 = fVar13;
    if (fVar13 < 0.0) {
      local_1e8 = 0.0;
    }
    uStack_84 = (uint)(fVar18 * (fVar15 - fVar16) + fVar16);
    local_90 = (longlong)(int)uStack_84;
    if (-fVar13 < 0.0) {
      local_1e8 = fVar13;
    }
    uStack_74 = (uint)(fVar18 * (fVar5 - fVar16) + fVar16);
    local_80 = (longlong)(int)uStack_74;
    fVar1 = fVar3;
    if (local_1e4 - fVar3 < 0.0) {
      fVar1 = local_1e4;
    }
    if (-(local_1e4 - fVar3) < 0.0) {
      local_1e4 = fVar1;
    }
    uStack_84 = uStack_84 ^ 0x80000000;
    uStack_74 = uStack_74 ^ 0x80000000;
    fVar1 = (float)((double)CONCAT44(0x43300000,uStack_84) - 4503601774854144.0);
    local_1dc = (float)((double)CONCAT44(0x43300000,uStack_74) - 4503601774854144.0);
    local_1e0 = fVar1;
    if (fVar1 < 0.0) {
      local_1e0 = 0.0;
    }
    if (-fVar1 < 0.0) {
      local_1e0 = fVar1;
    }
    fVar1 = fVar6;
    if (local_1dc - fVar6 < 0.0) {
      fVar1 = local_1dc;
    }
    iStack_c4 = iVar21;
    iStack_b4 = iVar23;
    if (-(local_1dc - fVar6) < 0.0) {
      local_1dc = fVar1;
    }
  }
  puVar26 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar26 + 0x70) {
    puVar20 = *(uint **)(param_1 + 0x30);
    *puVar20 = (int)puVar26 - (int)puVar20 >> 2 | *puVar20;
    puVar19 = PTR_0000f1a0;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar19,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar21 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar21 + 0x20;
    *(int *)(param_1 + 0x30) = iVar21 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar21 + 0x20 + *(int *)(iVar21 + 0x10) * 4;
    *(undefined4 *)(iVar21 + 0x1c) = 0;
    puVar26 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar20 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar26 + 0x70;
  *puVar20 = (int)puVar26 - (int)puVar20 >> 2 | *puVar20;
  *(undefined4 **)(param_1 + 0x30) = puVar26;
  *puVar26 = 0xb000000;
  puVar26[1] = 2;
  puVar26[2] = 1;
  puVar26 = puVar26 + 3;
  iVar21 = 10;
  do {
    *puVar26 = 0x80000000;
    puVar26 = puVar26 + 1;
    iVar21 = iVar21 + -1;
  } while (iVar21 != 0);
  uVar22 = ((int (*)())FUN_000096a0)(puVar26);
  puVar26 = (undefined4 *)((int (*)())FUN_00009700)(uVar22,1);
  *puVar26 = 0x1100;
  puVar26[1] = 0xa92;
  puVar26[2] = 0x1110;
  puVar26[3] = 0;
  puVar26[4] = 0x1120;
  puVar26[5] = ((int)*(short *)(param_1 + 0x112) - (int)*(short *)(param_1 + 0x10e)) - 1U |
               (((int)*(short *)(param_1 + 0x110) - (int)*(short *)(param_1 + 0x10c)) + -1) * 0x800
               | 0x80000000;
  puVar26[6] = 0x1130;
  puVar26[7] = 0xa60c;
  puVar26[8] = 0x1140;
  puVar26[9] = *(int *)(param_1 + 0x68) + -1;
  puVar26[10] = ((unsigned char *)0x00001041);
  puVar26[0xb] = 1;
  puVar26 = (undefined4 *)((int (*)())FUN_000099b0)(puVar26 + 0xc,&DAT_0000ec84,2,0,0,1);
  *puVar26 = 0x11a9;
  puVar26[1] = 0x1b00;
  puVar26[2] = 0x11aa;
  puVar26[3] = 0xf;
  puVar26[4] = 0x11ab;
  puVar26[5] = 0xf;
  puVar26[6] = 0x11ac;
  puVar26[7] = 0xf;
  puVar26[8] = 0x1381;
  puVar26[9] = 0x27260005;
  fparam_1 = (double)((int (*)())FUN_00009ac0)(puVar26 + 10,&local_1d8,&local_1e8,
                                  (int)*(short *)(param_1 + 0x112) -
                                  (int)*(short *)(param_1 + 0x10e),
                                  (int)*(short *)(param_1 + 0x110) -
                                  (int)*(short *)(param_1 + 0x10c));
LAB_0000b7d0:
  ((int (*)())FUN_0000cfe8)(fparam_1);
  return;
}

/* FUN_0000b7f0 @ 0xb7f0 (964 bytes) */
int FUN_0000b7f0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  undefined4 local_68;
  float local_64;
  undefined4 local_60;
  float local_5c;
  undefined4 local_58;
  uint uStack_54;
  undefined4 local_50;
  uint uStack_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  puVar6 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar6 + 0xb0) {
    puVar2 = *(uint **)(param_1 + 0x30);
    *puVar2 = (int)puVar6 - (int)puVar2 >> 2 | *puVar2;
    puVar1 = PTR_0000f1a0;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar5 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar5 + 0x20;
    *(int *)(param_1 + 0x30) = iVar5 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar5 + 0x20 + *(int *)(iVar5 + 0x10) * 4;
    *(undefined4 *)(iVar5 + 0x1c) = 0;
    puVar6 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar2 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar6 + 0xb0;
  *puVar2 = (int)puVar6 - (int)puVar2 >> 2 | *puVar2;
  *(undefined4 **)(param_1 + 0x30) = puVar6;
  *puVar6 = 0xa000000;
  puVar6[1] = param_2;
  puVar6[2] = (uint)(param_3 != 0);
  puVar6[3] = *(undefined4 *)(param_1 + 0x11c);
  puVar6 = puVar6 + 4;
  iVar5 = 0x10;
  do {
    *puVar6 = 0x80000000;
    puVar6 = puVar6 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  uVar3 = ((int (*)())FUN_000096a0)(puVar6);
  puVar6 = (undefined4 *)((int (*)())FUN_00009700)(uVar3,1);
  *puVar6 = 0x1100;
  puVar6[1] = 0x1492;
  puVar6[2] = 0x1110;
  puVar6[3] = 0;
  puVar6[4] = 0x1120;
  uVar7 = *(uint *)(param_1 + 0x57c);
  uVar4 = *(uint *)(param_1 + 0x578);
  puVar6[5] = (uVar7 - 1) * 0x800 | uVar4 - 1 | 0x80000000;
  puVar6[6] = 0x1130;
  puVar6[7] = 0x10120800;
  puVar6[8] = 0x1101;
  puVar6[9] = 0x10001492;
  puVar6[10] = 0x1111;
  puVar6[0xb] = 0;
  puVar6[0xc] = 0x1121;
  puVar6[0xd] = ((uVar7 >> 1) - 1) * 0x800 | (uVar4 >> 1) - 1 | 0x80000000;
  puVar6[0xe] = 0x1131;
  puVar6[0xf] = 0x18044803;
  puVar6[0x10] = ((unsigned char *)0x00001041);
  puVar6[0x11] = 3;
  puVar6 = (undefined4 *)((int (*)())FUN_000099b0)(puVar6 + 0x12,&DAT_0000eb7c,7,&DAT_0000eb2c,5,3);
  *puVar6 = 0x11a9;
  puVar6[1] = 0x1b00;
  puVar6[2] = 0x11aa;
  puVar6[3] = 0xf;
  puVar6[4] = 0x11ab;
  puVar6[5] = 0xf;
  puVar6[6] = 0x11ac;
  puVar6[7] = 0xf;
  uStack_2c = *(undefined4 *)(param_1 + 0x57c);
  uStack_34 = *(undefined4 *)(param_1 + 0x578);
  local_58 = 0x43300000;
  local_50 = 0x43300000;
  local_48 = 0x43300000;
  local_40 = 0x43300000;
  local_30 = 0x43300000;
  local_38 = 0x43300000;
  uStack_54 = (int)*(short *)(param_1 + 0x126) ^ 0x80000000;
  uStack_4c = (int)*(short *)(param_1 + 0x12a) ^ 0x80000000;
  uStack_44 = (int)*(short *)(param_1 + 0x124) ^ 0x80000000;
  uStack_3c = (int)*(short *)(param_1 + 0x128) ^ 0x80000000;
  local_60 = 0;
  local_68 = 0;
  local_5c = (float)((double)CONCAT44(0x43300000,uStack_2c) - 4503599627370496.0);
  local_78 = (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0);
  local_74 = (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0);
  local_6c = (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0);
  local_70 = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0);
  local_64 = (float)((double)CONCAT44(0x43300000,uStack_34) - 4503599627370496.0);
  ((int (*)())FUN_00009ac0)(puVar6 + 8,&local_78,&local_68,uStack_34,uStack_2c);
  return;
}

/* FUN_0000bbc0 @ 0xbbc0 (864 bytes) */
int FUN_0000bbc0(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  uint param_5;
  int param_6;
{
  undefined *puVar1;
  int iVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  float local_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  
  puVar1 = PTR_0000f1a0;
  if (param_6 < 5) {
    iVar2 = param_4 / (4 / param_6);
    uVar6 = iVar2 + (uint)(param_4 != iVar2 * (4 / param_6));
  }
  else {
    uVar6 = (param_6 >> 2) * param_4;
  }
  puVar5 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar5 + 0x70) {
    puVar3 = *(uint **)(param_1 + 0x30);
    *puVar3 = (int)puVar5 - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar2 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar2 + 0x20;
    *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    puVar5 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar3 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar5 + 0x70;
  *puVar3 = (int)puVar5 - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(param_1 + 0x30) = puVar5;
  *puVar5 = 0x47000000;
  puVar5[1] = param_2;
  puVar5[2] = param_3;
  puVar5 = puVar5 + 3;
  iVar2 = 0xe;
  do {
    *puVar5 = 0x80000000;
    puVar5 = puVar5 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  uVar4 = ((int (*)())FUN_000096a0)(puVar5);
  puVar5 = (undefined4 *)((int (*)())FUN_00009700)(uVar4,1);
  *puVar5 = 0x1100;
  puVar5[1] = 0xa92;
  puVar5[2] = 0x1110;
  puVar5[3] = 0;
  puVar5[4] = 0x1120;
  puVar5[5] = (param_5 - 1) * 0x800 | uVar6 - 1 | 0x80000000;
  puVar5[6] = 0x1130;
  puVar5[7] = 0xa60c;
  puVar5[8] = ((unsigned char *)0x00001041);
  puVar5[9] = 1;
  puVar5 = (undefined4 *)((int (*)())FUN_000099b0)(puVar5 + 10,&DAT_0000ecb4,2,0,0,1);
  *puVar5 = 0x11a9;
  puVar5[1] = 0x1b00;
  puVar5[2] = 0x11aa;
  puVar5[3] = 0xf;
  puVar5[4] = 0x11ab;
  puVar5[5] = 0xf;
  puVar5[6] = 0x11ac;
  puVar5[7] = 0xf;
  uStack_44 = uVar6 ^ 0x80000000;
  uStack_3c = param_5 ^ 0x80000000;
  local_40 = 0x43300000;
  local_48 = 0x43300000;
  local_50 = 0;
  local_58 = 0;
  local_4c = (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0);
  local_54 = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0);
  ((int (*)())FUN_00009ac0)(puVar5 + 8,0,&local_58,uVar6,param_5);
  puVar1 = PTR_0000f1a0;
  puVar3 = *(uint **)(param_1 + 0x30);
  *puVar3 = *(int *)(param_1 + 0x34) - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar2 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar2 + 0x20;
  *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  return;
}

/* FUN_0000bf20 @ 0xbf20 (72 bytes) */
int FUN_0000bf20(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x144);
  iVar1 = 0;
  iVar2 = (param_2 & iVar3 - 1U) + (param_3 - iVar3);
  if (0 < iVar2) {
    do {
      dataCacheBlockStore((-iVar3 & param_2) + iVar1);
      iVar1 = iVar3 + iVar1;
    } while (iVar1 < iVar2);
  }
  dataCacheBlockFlush((-iVar3 & param_2) + iVar1);
  return;
}

/* FUN_0000bf70 @ 0xbf70 (80 bytes) */
int FUN_0000bf70(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x144);
  iVar1 = 0;
  iVar2 = ((param_2 & iVar3 - 1U) + param_3) - iVar3;
  if (0 < iVar2) {
    do {
      dataCacheBlockFlush((-iVar3 & param_2) + iVar1);
      iVar1 = iVar1 + iVar3;
    } while (iVar1 < iVar2);
  }
  dataCacheBlockFlush((-iVar3 & param_2) + iVar1);
  sync(0);
  instructionSynchronize();
  return;
}

/* FUN_0000bfc0 @ 0xbfc0 (400 bytes) */
int FUN_0000bfc0(param_1)
  int param_1;
{
  undefined *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar1 = PTR_0000f1a0;
  puVar3 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar3 + 0x10) {
    puVar2 = *(uint **)(param_1 + 0x30);
    *puVar2 = (int)puVar3 - (int)puVar2 >> 2 | *puVar2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar4 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar4 + 0x20;
    *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
    *(undefined4 *)(iVar4 + 0x1c) = 0;
    puVar3 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar2 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar3 + 0x10;
  *puVar2 = (int)puVar3 - (int)puVar2 >> 2 | *puVar2;
  *(undefined4 **)(param_1 + 0x30) = puVar3;
  *puVar3 = 0x15000000;
  puVar3[1] = 0x20202020;
  puVar1 = PTR_0000f1a0;
  puVar2 = *(uint **)(param_1 + 0x30);
  *puVar2 = *(int *)(param_1 + 0x34) - (int)puVar2 >> 2 | *puVar2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar1,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar4 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar4 + 0x20;
  *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
  *(undefined4 *)(iVar4 + 0x1c) = 0;
  return;
}

/* FUN_0000c160 @ 0xc160 (848 bytes) */
int FUN_0000c160(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  float local_44;
  float local_3c;
  
  if (param_4 == 1) {
    uVar3 = *(uint *)(param_1 + 0x588);
    uVar4 = *(uint *)(param_1 + 0x578);
    uVar7 = *(uint *)(param_1 + 0x57c) >> 1;
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x588);
    uVar4 = *(uint *)(param_1 + 0x578);
    uVar7 = *(uint *)(param_1 + 0x57c) >> 2;
  }
  uVar4 = uVar4 >> 2;
  iVar8 = 0x18;
  puVar5 = param_2;
  do {
    *puVar5 = 0x80000000;
    puVar5 = puVar5 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  param_2[0x18] = 0x1120;
  uVar6 = uVar4 - 1 | (uVar7 - 1) * 0x800 | 0x80000000;
  param_2[0x19] = uVar6;
  param_2[0x1a] = 0x1140;
  iVar8 = (uVar3 >> 1 & 0x7ffffffe) - 1;
  param_2[0x1b] = iVar8;
  param_2[0x1c] = 0x1121;
  param_2[0x1d] = uVar6;
  param_2[0x1e] = 0x1141;
  param_2[0x1f] = iVar8;
  param_2[0x20] = 0x1122;
  param_2[0x21] = uVar6;
  param_2[0x22] = 0x1142;
  param_2[0x23] = iVar8;
  param_2[0x24] = 0x1123;
  param_2[0x25] = uVar6;
  param_2[0x26] = 0x1143;
  param_2[0x27] = iVar8;
  param_2[0x28] = 0x1124;
  param_2[0x29] = uVar6;
  param_2[0x2a] = 0x1144;
  param_2[0x2b] = iVar8;
  param_2[0x2c] = 0x82d;
  param_2[0x2d] = 4;
  param_2[0x2e] = 0xc0103500;
  param_2[0x2f] = 0x4003d;
  fVar2 = FLOAT_0000d43c;
  fVar1 = FLOAT_0000d430;
  if (param_5 == 1) {
    if (*(int *)(param_3 + 8) == 0) {
LAB_0000c3c0:
      local_44 = FLOAT_0000d43c / (float)((double)CONCAT44(0x43300000,uVar7) - DOUBLE_0000d418);
      goto LAB_0000c3e4;
    }
  }
  else if (*(int *)(param_3 + 8) != 0) goto LAB_0000c3c0;
  local_44 = FLOAT_0000d438 / (float)((double)CONCAT44(0x43300000,uVar7) - DOUBLE_0000d418);
LAB_0000c3e4:
  local_3c = local_44 + FLOAT_0000d43c;
  local_44 = local_44 + FLOAT_0000d430;
  param_2[0x30] = 0;
  param_2[0x31] = 0;
  param_2[0x32] = fVar1;
  param_2[0x33] = local_44;
  param_2[0x34] = uVar7 << 0x10;
  param_2[0x35] = 0x10000;
  param_2[0x36] = fVar1;
  param_2[0x37] = local_3c;
  param_2[0x38] = uVar4 | uVar7 << 0x10;
  param_2[0x39] = 0x00010001;
  param_2[0x3a] = fVar2;
  param_2[0x3b] = local_3c;
  param_2[0x3c] = uVar4;
  param_2[0x3d] = 1;
  param_2[0x3e] = fVar2;
  param_2[0x3f] = local_44;
  param_2[0x40] = 0x1393;
  param_2[0x41] = 10;
  return param_2 + 0x42;
}

/* FUN_0000c4b0 @ 0xc4b0 (1508 bytes) */
int FUN_0000c4b0(param_1, param_2, param_3, param_4)
  int param_1;
  char *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  bool bVar1;
  undefined *puVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  puVar2 = PTR_0000f1a0;
  puVar8 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar8 + 0x188) {
    puVar3 = *(uint **)(param_1 + 0x30);
    *puVar3 = (int)puVar8 - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar2,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar6 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar6 + 0x20;
    *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
    *(undefined4 *)(iVar6 + 0x1c) = 0;
    puVar8 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar3 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar8 + 0x188;
  *puVar3 = (int)puVar8 - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(param_1 + 0x30) = puVar8;
  *puVar8 = 0x3d000000;
  puVar8[1] = (int)*param_2;
  puVar8[2] = (int)param_2[1];
  puVar8[3] = *(undefined4 *)(param_2 + 8);
  puVar8[4] = param_4;
  puVar8[5] = -0x80000000;
  puVar8[6] = -0x80000000;
  puVar8[7] = 0x80000000;
  puVar8[8] = 0x80000000;
  puVar8[9] = 0x80000000;
  puVar4 = (undefined4 *)((int (*)())FUN_000096a0)(puVar8 + 10);
  *puVar4 = 0x850;
  puVar4[1] = 0x102;
  puVar4[2] = 0x854;
  puVar4[3] = 0x6060006;
  puVar4[4] = 0x855;
  puVar4[5] = 0x2701;
  puVar4[6] = 0x878;
  puVar4[7] = 0xf688f688;
  puVar4[8] = 0x879;
  puVar4[9] = 0xf688f688;
  puVar4[10] = 0x824;
  puVar4[0xb] = 1;
  puVar4[0xc] = 0x825;
  puVar4[0xd] = 0x12;
  puVar4[0xe] = 0x000010c0;
  puVar4[0xf] = 0x40004;
  puVar4[0x10] = 0x10c1;
  puVar4[0x11] = 1;
  uVar7 = 0;
  iVar6 = 1;
  puVar4 = puVar4 + 0x12;
  do {
    puVar5 = puVar4;
    *puVar5 = ((unsigned char *)0x0000101d) + uVar7;
    puVar5[1] = uVar7 << 1 | iVar6 << 6 | 0x28ffe000;
    puVar5[2] = uVar7 + 0x10c8;
    puVar5[3] = uVar7 | uVar7 << 5 | 0x10;
    bVar1 = uVar7 != 1;
    iVar6 = iVar6 + 2;
    uVar7 = uVar7 + 1;
    puVar4 = puVar5 + 4;
  } while (bVar1);
  puVar5[4] = 0x1100;
  puVar5[5] = 0xa92;
  puVar5[6] = 0x1110;
  puVar5[7] = 0;
  puVar5[8] = 0x1130;
  puVar5[9] = 0x4000a60c;
  puVar5[10] = 0x1101;
  puVar5[0xb] = 0x10000a92;
  puVar5[0xc] = 0x1111;
  puVar5[0xd] = 0;
  puVar5[0xe] = 0x1131;
  puVar5[0xf] = 0x4800a60c;
  puVar5[0x10] = 0x1102;
  puVar5[0x11] = 0x20000a92;
  puVar5[0x12] = 0x1112;
  puVar5[0x13] = 0;
  puVar5[0x14] = 0x1132;
  puVar5[0x15] = 0x2800a60c;
  puVar5[0x16] = 0x1103;
  puVar5[0x17] = 0x30000a92;
  puVar5[0x18] = 0x1113;
  puVar5[0x19] = 0;
  puVar5[0x1a] = 0x1133;
  puVar5[0x1b] = 0x3000a60c;
  puVar5[0x1c] = 0x1104;
  puVar5[0x1d] = 0x40000a92;
  puVar5[0x1e] = 0x1114;
  puVar5[0x1f] = 0;
  puVar5[0x20] = 0x1134;
  puVar5[0x21] = 0x3800a60c;
  puVar5[0x22] = ((unsigned char *)0x00001041);
  puVar5[0x23] = 0x1f;
  DAT_0000f054 = 0.5647059;
  DAT_0000f060 = 0.5647059;
  DAT_0000f070 = 0.047058824;
  DAT_0000f090 = 0.1254902;
  DAT_0000f058 = 0.5647059;
  DAT_0000f05c = 0.5647059;
  DAT_0000f064 = 0.047058824;
  DAT_0000f068 = 0.047058824;
  DAT_0000f06c = 0.047058824;
  DAT_0000f074 = 0.1254902;
  DAT_0000f078 = 0.1254902;
  DAT_0000f07c = 0.1254902;
  DAT_0000f080 = 0.1254902;
  DAT_0000f084 = 0.1254902;
  DAT_0000f088 = 0.1254902;
  DAT_0000f08c = 0.1254902;
  puVar4 = (undefined4 *)((int (*)())FUN_000099b0)(puVar5 + 0x24,&DAT_0000ece4,0x16,&DAT_0000f054,6,9);
  *puVar4 = 0x11a9;
  puVar4[1] = 0x1b00;
  puVar4[2] = 0x11aa;
  puVar4[3] = 0x1b00;
  puVar4[4] = 0x11ab;
  puVar4[5] = 0x1b00;
  puVar4[6] = 0x11ac;
  puVar4[7] = 0xf;
  puVar8[5] = (int)(puVar4 + 8) - (int)puVar8 >> 2;
  iVar6 = ((int (*)())FUN_0000c160)(param_1,puVar4 + 8,param_2,1,param_4);
  puVar8[6] = iVar6 - (int)puVar8 >> 2;
  ((int (*)())FUN_0000c160)(param_1,iVar6,param_2,2,param_4);
  puVar2 = PTR_0000f1a0;
  puVar3 = *(uint **)(param_1 + 0x30);
  *puVar3 = *(int *)(param_1 + 0x34) - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar2,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar6 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar6 + 0x20;
  *(int *)(param_1 + 0x30) = iVar6 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar6 + 0x20 + *(int *)(iVar6 + 0x10) * 4;
  *(undefined4 *)(iVar6 + 0x1c) = 0;
  return;
}

/* FUN_0000caa0 @ 0xcaa0 (92 bytes) */
int FUN_0000caa0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  if (*(int *)(param_1 + 0x120) == 4) {
    ((int (*)())FUN_0000c4b0)(param_1,param_2,param_3,param_4);
  }
  *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + param_1 + 0xacc) =
       *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x18);
  return;
}

/* FUN_0000cb00 @ 0xcb00 (1136 bytes) */
int FUN_0000cb00(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  undefined4 local_58;
  uint uStack_54;
  undefined4 local_50;
  uint uStack_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  undefined4 local_38;
  uint uStack_34;
  
  puVar2 = PTR_0000f1a0;
  local_40 = 0x43300000;
  local_50 = 0x43300000;
  local_58 = 0x43300000;
  local_48 = 0x43300000;
  (*(short *)((unsigned char *)ghidra_home + 10)) = (short)param_3;
  (*(short *)((unsigned char *)ghidra_home + 6)) = (short)param_2;
  (*(short *)((unsigned char *)ghidra_home + 8)) = (short)((uint)param_3 >> 0x10);
  (*(short *)((unsigned char *)ghidra_home + 4)) = (short)((uint)param_2 >> 0x10);
  puVar6 = *(undefined4 **)(param_1 + 0x34);
  uStack_4c = (int)(*(short *)((unsigned char *)ghidra_home + 6)) ^ 0x80000000;
  uStack_3c = (int)(*(short *)((unsigned char *)ghidra_home + 10)) ^ 0x80000000;
  uStack_54 = (int)(*(short *)((unsigned char *)ghidra_home + 4)) ^ 0x80000000;
  uStack_44 = (int)(*(short *)((unsigned char *)ghidra_home + 8)) ^ 0x80000000;
  uVar3 = *(uint *)(param_1 + 0x60);
  iVar8 = *(int *)(param_1 + 100);
  uVar1 = uVar3 >> 1;
  local_70 = (float)((double)CONCAT44(0x43300000,uStack_54) - 4503601774854144.0);
  local_6c = (float)((double)CONCAT44(0x43300000,uStack_44) - 4503601774854144.0);
  local_78 = (float)((double)CONCAT44(0x43300000,uStack_4c) - 4503601774854144.0) * 0.5;
  local_74 = (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0) * 0.5;
  (*(short *)((unsigned char *)ghidra_home + 4)) = param_2;
  (*(short *)((unsigned char *)ghidra_home + 8)) = param_3;
  local_68 = local_78;
  local_64 = local_74;
  local_60 = local_70;
  local_5c = local_6c;
  if (*(undefined4 **)(param_1 + 0x38) <= puVar6 + 0xa8) {
    puVar4 = *(uint **)(param_1 + 0x30);
    *puVar4 = (int)puVar6 - (int)puVar4 >> 2 | *puVar4;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar2,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar7 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar7 + 0x20;
    *(int *)(param_1 + 0x30) = iVar7 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar7 + 0x20 + *(int *)(iVar7 + 0x10) * 4;
    *(undefined4 *)(iVar7 + 0x1c) = 0;
    puVar6 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar4 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar6 + 0xa8;
  *puVar4 = (int)puVar6 - (int)puVar4 >> 2 | *puVar4;
  *(undefined4 **)(param_1 + 0x30) = puVar6;
  *puVar6 = 0x18000000;
  puVar6[1] = param_4;
  puVar6[2] = 3;
  puVar6[3] = param_5;
  puVar6 = puVar6 + 4;
  iVar7 = 8;
  do {
    *puVar6 = 0x80000000;
    puVar6 = puVar6 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar5 = ((int (*)())FUN_000096a0)(puVar6);
  puVar6 = (undefined4 *)((int (*)())FUN_00009700)(uVar5,1);
  *puVar6 = 0x1100;
  puVar6[1] = 0xa92;
  puVar6[2] = 0x1110;
  puVar6[3] = 0;
  puVar6[4] = 0x1120;
  puVar6[5] = (iVar8 + -1) * 0x800 | (uVar3 >> 2) - 1 | 0x80000000;
  puVar6[6] = 0x1130;
  puVar6[7] = 0x10108802;
  puVar6[8] = 0x1140;
  puVar6[9] = 0xbf;
  puVar6[10] = 0x1101;
  puVar6[0xb] = 0x10000a92;
  puVar6[0xc] = 0x1111;
  puVar6[0xd] = 0;
  puVar6[0xe] = 0x1121;
  puVar6[0xf] = 0x8000000f;
  puVar6[0x10] = 0x1131;
  puVar6[0x11] = 0x1800a60e;
  puVar6[0x12] = 0x1141;
  puVar6[0x13] = 0xf;
  puVar6[0x14] = ((unsigned char *)0x00001041);
  puVar6[0x15] = 3;
  local_38 = 0x43300000;
  DAT_0000f0b4 = (float)((double)CONCAT44(0x43300000,uVar1) - 4503599627370496.0);
  DAT_0000f0b8 = DAT_0000f0b4;
  DAT_0000f0bc = DAT_0000f0b4;
  DAT_0000f0c0 = DAT_0000f0b4;
  uStack_34 = uVar1;
  puVar6 = (undefined4 *)((int (*)())FUN_000099b0)(puVar6 + 0x16,&DAT_0000eef4,9,&DAT_0000f0b4,1,4);
  *puVar6 = 0x11a9;
  puVar6[1] = 0x1b05;
  puVar6[2] = 0x11aa;
  puVar6[3] = 0xf;
  puVar6[4] = 0x11ab;
  puVar6[5] = 0xf;
  puVar6[6] = 0x11ac;
  puVar6[7] = 0xf;
  ((int (*)())FUN_00009ac0)(puVar6 + 8,&local_78,&local_68,uVar1,iVar8);
  puVar2 = PTR_0000f1a0;
  puVar4 = *(uint **)(param_1 + 0x30);
  *puVar4 = *(int *)(param_1 + 0x34) - (int)puVar4 >> 2 | *puVar4;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar2,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar8 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar8 + 0x20;
  *(int *)(param_1 + 0x30) = iVar8 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar8 + 0x20 + *(int *)(iVar8 + 0x10) * 4;
  *(undefined4 *)(iVar8 + 0x1c) = 0;
  return;
}

/* FUN_0000cf98 @ 0xcf98 (12 bytes) */
int FUN_0000cf98()
{
  return;
}

/* FUN_0000cfa4 @ 0xcfa4 (4 bytes) */
int FUN_0000cfa4()
{
  return;
}

/* FUN_0000cfa8 @ 0xcfa8 (24 bytes) */
int FUN_0000cfa8()
{
  return;
}

/* FUN_0000cfe8 @ 0xcfe8 (44 bytes) */
int FUN_0000cfe8()
{
  return;
}

