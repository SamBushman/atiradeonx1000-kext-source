#include "decls.h"

/* FUN_0017f5a4 @ 0x17f5a4 (488 bytes) */
int FUN_0017f5a4(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  
  iVar1 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
  iVar1 = FUN_000f2e18(*(undefined4 *)(iVar1 + 0x10));
  if (iVar1 == 0) {
    piVar2 = (int *)FUN_0010445c(*(undefined4 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0x238),0)
    ;
    iVar1 = *(int *)(param_1 + 0x238);
    uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x6c4) + 0x3ac);
    iVar4 = *(int *)(iVar1 + 0x3ac) + -1;
    *(int *)(iVar1 + 0x3ac) = iVar4;
    uVar3 = FUN_00127608(uVar3,0,iVar4,0);
    FUN_0012306c(uVar3,*(undefined4 *)(param_1 + 0xb0));
    FUN_001046c8(*(undefined4 *)(param_1 + 0xb0),0,uVar3);
    iVar1 = DAT_001b01d4;
    iVar4 = piVar2[0x23];
    *(undefined1 *)(*(int *)(param_1 + 0xb0) + 0x9f) = 1;
    piVar2[0x27] = iVar1;
    FUN_0012306c(iVar4,piVar2);
    iVar1 = 1;
    piVar6 = piVar2;
    while( true ) {
      iVar4 = (**(code **)(*piVar2 + 0x14))(piVar2);
      if (iVar4 < iVar1) break;
      FUN_001236e4(piVar6[0x29],iVar1,piVar2);
      iVar1 = iVar1 + 1;
      piVar6 = piVar6 + 6;
    }
    if ((*(uint *)(*(int *)(param_1 + 0xb0) + 0x14) & 0x200) == 0) {
      FUN_001049e8(*(int *)(param_1 + 0xb0),uVar3,*(undefined4 *)(param_1 + 0x238));
      FUN_001236e4(uVar3,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x84));
      *(uint *)(*(int *)(param_1 + 0xb0) + 0x14) =
           *(uint *)(*(int *)(param_1 + 0xb0) + 0x14) | 0x200;
      iVar1 = FUN_00122fa4(uVar3,*(undefined4 *)
                                  (*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0x3a0));
      uVar5 = *(undefined4 *)(param_1 + 0x238);
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x84) * 4 + param_1 + 0x210) =
           *(undefined4 *)(iVar1 + 0xb0);
      FUN_001049e8(piVar2,uVar3,uVar5);
      FUN_001236e4(uVar3,piVar2[0x21],piVar2);
      piVar2[5] = piVar2[5] | 0x200;
    }
    else {
      FUN_001046c8(piVar2,piVar2[0x21],uVar3);
      FUN_001236e4(uVar3,piVar2[0x21],piVar2);
    }
    FUN_001745ac(param_1);
    FUN_000e7738(*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158),*(int *)(param_1 + 0xb0),piVar2);
    return;
  }
  return;
}

/* FUN_0017f78c @ 0x17f78c (96 bytes) */
int FUN_0017f78c(param_1)
  int param_1;
{
  int iVar1;
  
  if ((*(int *)(*(int *)(param_1 + 0xb0) + 0x98) != 0x2c) &&
     (iVar1 = FUN_0011379c(*(undefined4 *)(param_1 + 0x238)), iVar1 != 0)) {
    ((int (*)())FUN_0017f5a4)(param_1);
    return;
  }
  return;
}

/* FUN_0017f7ec @ 0x17f7ec (1848 bytes) */
int FUN_0017f7ec(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int local_38 [8];
  
  if ((*(int *)(*(int *)(param_1 + 0xb0) + 0x80) == 1) &&
     (iVar2 = FUN_001054ec(*(int *)(param_1 + 0xb0),0), *(int *)(iVar2 + 0x10) == DAT_001b01d0)) {
    return 0;
  }
  piVar4 = local_38;
  iVar2 = 4;
  piVar3 = piVar4;
  do {
    *piVar3 = 0x7ffffffe;
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar5 = 4;
  iVar2 = 0;
  do {
    *(undefined4 *)(iVar2 + (int)piVar4) = 0x7ffffffe;
    iVar2 = iVar2 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar2 = FUN_0017dbdc(param_1,piVar4);
  if (iVar2 != 0) {
    return 0;
  }
  piVar3 = (int *)FUN_00112f54(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8));
  iVar2 = (**(code **)(*piVar3 + 0x14))(piVar3,param_1,piVar4,*(undefined4 *)(param_1 + 0x238));
  if (iVar2 == 0) {
    return 0;
  }
  iVar5 = *(int *)(param_1 + 0xb0);
  iVar2 = *(int *)(*(int *)(iVar5 + 0x88) + 8);
  if (iVar2 == 0x1d) {
    FUN_00177ad0(param_1);
    iVar2 = FUN_0017c0f8(param_1);
    if (iVar2 != 0) {
      return 0;
    }
    iVar2 = FUN_0017ab4c(param_1);
    if (iVar2 != 0) {
      return 1;
    }
    iVar2 = FUN_001766bc(param_1);
joined_r0x0017f980:
    if (iVar2 != 0) {
      return 1;
    }
  }
  else if (iVar2 < 0x1e) {
    if (iVar2 == 0x17) {
      iVar2 = FUN_0017cb14(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = FUN_0017c888(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = FUN_0017f594(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar5 = 0;
      piVar3 = piVar4;
      do {
        iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar5 + iVar2 + 0x10) != '\x01') {
          iVar2 = *(int *)(param_1 + 0x238);
          if (*(int *)(iVar2 + 0x658) <= *(int *)(*(int *)(iVar2 + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*piVar3 == 0x7ffffffe) && (iVar2 = FUN_00179e74(param_1,iVar5), iVar2 == 0)) {
            FUN_0017994c(param_1,iVar5);
          }
        }
        bVar1 = iVar5 != 3;
        piVar3 = piVar3 + 1;
        iVar5 = iVar5 + 1;
      } while (bVar1);
    }
    else if (iVar2 < 0x18) {
      if (iVar2 == 0x13) {
        FUN_00177ad0(param_1);
        iVar2 = FUN_0017d57c(param_1);
        if (iVar2 != 0) {
          return 0;
        }
        iVar2 = FUN_0017c774(param_1);
        if (iVar2 != 0) {
          return 0;
        }
        iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),0xc);
        if ((iVar2 != 0) && (iVar2 = FUN_0017e1f4(param_1), iVar2 != 0)) {
          return 0;
        }
        iVar5 = 0;
        piVar3 = piVar4;
        do {
          iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
          if (*(char *)(iVar5 + iVar2 + 0x10) != '\x01') {
            iVar2 = *(int *)(param_1 + 0x238);
            if (*(int *)(iVar2 + 0x658) <= *(int *)(*(int *)(iVar2 + 0x6c4) + 0xa8))
            goto LAB_0017fe30;
            if ((*piVar3 == 0x7ffffffe) && (iVar2 = FUN_001768d4(param_1,iVar5), iVar2 == 0)) {
              FUN_00179f38(param_1,iVar5);
            }
          }
          bVar1 = iVar5 != 3;
          piVar3 = piVar3 + 1;
          iVar5 = iVar5 + 1;
        } while (bVar1);
      }
      else {
        if (iVar2 != 0x14) goto LAB_0017fe28;
        FUN_00177ad0(param_1);
        iVar2 = FUN_0017cd18(param_1);
        if (iVar2 != 0) {
          return 0;
        }
        iVar2 = FUN_0017e6c8(param_1);
        if (iVar2 != 0) {
          return 1;
        }
        iVar2 = FUN_0017e658(param_1);
        if (iVar2 != 0) {
          return 1;
        }
        iVar2 = FUN_0017f1f8(param_1);
        if (iVar2 != 0) {
          return 1;
        }
        iVar5 = 0;
        piVar3 = piVar4;
        do {
          iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
          if (*(char *)(iVar5 + iVar2 + 0x10) != '\x01') {
            iVar2 = *(int *)(param_1 + 0x238);
            if (*(int *)(iVar2 + 0x658) <= *(int *)(*(int *)(iVar2 + 0x6c4) + 0xa8))
            goto LAB_0017fe30;
            if (*piVar3 == 0x7ffffffe) {
              FUN_00179db0(param_1,iVar5);
            }
          }
          bVar1 = iVar5 != 3;
          piVar3 = piVar3 + 1;
          iVar5 = iVar5 + 1;
        } while (bVar1);
      }
    }
    else {
      if (iVar2 != 0x19) {
        if (iVar2 == 0x1c) {
          FUN_00177ad0(param_1);
          iVar2 = FUN_0017bf70(param_1);
          if (iVar2 != 0) {
            return 0;
          }
          iVar2 = FUN_0017ab4c(param_1);
          goto joined_r0x0017f980;
        }
LAB_0017fe28:
        iVar2 = *(int *)(param_1 + 0x238);
        goto LAB_0017fe34;
      }
      iVar2 = FUN_0017c910(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = FUN_0017c888(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = FUN_0017f59c(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar5 = 0;
      piVar3 = piVar4;
      do {
        iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar5 + iVar2 + 0x10) != '\x01') {
          iVar2 = *(int *)(param_1 + 0x238);
          if (*(int *)(iVar2 + 0x658) <= *(int *)(*(int *)(iVar2 + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*piVar3 == 0x7ffffffe) && (iVar2 = FUN_00179e74(param_1,iVar5), iVar2 == 0)) {
            FUN_00179a34(param_1,iVar5);
          }
        }
        bVar1 = iVar5 != 3;
        piVar3 = piVar3 + 1;
        iVar5 = iVar5 + 1;
      } while (bVar1);
    }
  }
  else if (iVar2 < 0x2b) {
    if (iVar2 < 0x27) {
      if (iVar2 < 0x24) goto LAB_0017fe28;
      iVar2 = FUN_0017c5e0(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = FUN_0017c41c(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = FUN_0017c4a4(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar5 = 0;
      piVar3 = piVar4;
      do {
        iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar5 + iVar2 + 0x10) != '\x01') {
          iVar2 = *(int *)(param_1 + 0x238);
          if (*(int *)(iVar2 + 0x658) <= *(int *)(*(int *)(iVar2 + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*piVar3 == 0x7ffffffe) && (iVar2 = FUN_0017a034(param_1,iVar5), iVar2 == 0)) {
            FUN_001797d0(param_1,iVar5);
          }
        }
        bVar1 = iVar5 != 3;
        piVar3 = piVar3 + 1;
        iVar5 = iVar5 + 1;
      } while (bVar1);
    }
    else {
      iVar2 = FUN_0017d9b8(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = FUN_0017d3f8(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar5 = 0;
      piVar3 = piVar4;
      do {
        iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar5 + iVar2 + 0x10) != '\x01') {
          iVar2 = *(int *)(param_1 + 0x238);
          if (*(int *)(iVar2 + 0x658) <= *(int *)(*(int *)(iVar2 + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*piVar3 == 0x7ffffffe) && (iVar2 = FUN_00176954(param_1,iVar5), iVar2 == 0)) {
            FUN_00179894(param_1,iVar5);
          }
        }
        bVar1 = iVar5 != 3;
        piVar3 = piVar3 + 1;
        iVar5 = iVar5 + 1;
      } while (bVar1);
    }
  }
  else {
    if (iVar2 == 0x8b) {
      iVar2 = FUN_0017a748(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = FUN_0017a3d4(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      FUN_00177748(param_1);
      iVar5 = *(int *)(param_1 + 0xb0);
      iVar2 = *(int *)(param_1 + 0x238);
      goto LAB_0017fe34;
    }
    if (iVar2 != 0x8c) goto LAB_0017fe28;
    iVar2 = FUN_0017a8a4(param_1);
    if (iVar2 != 0) {
      return 0;
    }
  }
  iVar5 = *(int *)(param_1 + 0xb0);
  iVar2 = *(int *)(param_1 + 0x238);
LAB_0017fe34:
  iVar2 = FUN_00113090(*(undefined4 *)(*(int *)(iVar5 + 0x88) + 8),iVar2);
  if ((iVar2 == 0) &&
     (iVar2 = FUN_001131c0(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(param_1 + 0x238)), iVar2 == 0)) {
    iVar2 = 0;
    do {
      if (*(int *)(*(int *)(param_1 + 0x238) + 0x658) <=
          *(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0xa8)) {
        return 0;
      }
      if (*piVar4 != 0x7ffffffe) {
        FUN_001765a4(param_1,*piVar4,iVar2);
      }
      bVar1 = iVar2 != 3;
      piVar4 = piVar4 + 1;
      iVar2 = iVar2 + 1;
    } while (bVar1);
  }
  else {
    iVar2 = 0;
    do {
      if (*(int *)(*(int *)(param_1 + 0x238) + 0x658) <=
          *(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0xa8)) {
        return 0;
      }
      if (*piVar4 != 0x7ffffffe) {
        FUN_001765a4(param_1,*piVar4,iVar2);
      }
      bVar1 = iVar2 != 3;
      piVar4 = piVar4 + 1;
      iVar2 = iVar2 + 1;
    } while (bVar1);
  }
  return 0;
LAB_0017fe30:
  iVar5 = *(int *)(param_1 + 0xb0);
  goto LAB_0017fe34;
}

/* FUN_00180154 @ 0x180154 (888 bytes) */
int FUN_00180154(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  switch(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8)) {
  case 0x16:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
    FUN_0017662c();
    iVar5 = 0;
    iVar6 = param_1;
    do {
      iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
      if (((*(char *)(iVar5 + iVar3 + 0x10) != '\x01') && (*(int *)(iVar6 + 0x30) == 0)) &&
         (*(int *)(*(int *)(param_1 + 0xb0) + 0x124) < 1)) {
        iVar3 = *(int *)(iVar6 + 0x40);
        if (iVar3 == 0) {
          iVar3 = FUN_00174ce0(*(undefined4 *)(param_1 + 0x238),iVar5,param_1);
          *(int *)(iVar6 + 0x40) = iVar3;
        }
        *(undefined4 *)(iVar3 + 0x10) = 4;
      }
      bVar1 = iVar5 != 3;
      iVar6 = iVar6 + 4;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    return;
  default:
    return;
  case 0x1c:
    break;
  case 0x1d:
    iVar5 = 0;
    iVar6 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(int *)(iVar6 + 0x10) != DAT_001b01d0) {
      iVar6 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
      iVar5 = FUN_000f30d4(*(undefined4 *)(iVar6 + 0x10));
    }
    if (*(int *)(iVar5 * 4 + param_1 + 0x30) == 0) {
      uVar4 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
      uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
      if (((uVar2 & 1) == (uVar4 & 1)) && ((uVar2 >> 1 & 1) == (uVar4 >> 1 & 1))) {
        iVar6 = 0;
        do {
          iVar3 = FUN_00179608(param_1,iVar6,1,2);
          if (iVar3 == 0) {
            return;
          }
          bVar1 = iVar6 != 3;
          iVar6 = iVar6 + 1;
        } while (bVar1);
        iVar6 = *(int *)(iVar5 * 4 + param_1 + 0x40);
        if (iVar6 == 0) {
          iVar6 = FUN_00174ce0(*(undefined4 *)(param_1 + 0x238),iVar5,param_1);
        }
        *(undefined4 *)(iVar6 + 0xc) = 4;
        iVar5 = 4;
        do {
          *(int *)(param_1 + 0x40) = iVar6;
          param_1 = param_1 + 4;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
    }
    return;
  }
  iVar5 = 0;
  iVar6 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
  if (*(int *)(iVar6 + 0x10) != DAT_001b01d0) {
    iVar6 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    iVar5 = FUN_000f30d4(*(undefined4 *)(iVar6 + 0x10));
  }
  if (*(int *)(iVar5 * 4 + param_1 + 0x30) == 0) {
    uVar4 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    if (((uVar2 & 1) == (uVar4 & 1)) && ((uVar2 >> 1 & 1) == (uVar4 >> 1 & 1))) {
      iVar6 = 0;
      do {
        iVar3 = FUN_00179608(param_1,iVar6,1,2);
        if (iVar3 == 0) {
          return;
        }
        bVar1 = iVar6 != 2;
        iVar6 = iVar6 + 1;
      } while (bVar1);
      iVar6 = *(int *)(iVar5 * 4 + param_1 + 0x40);
      if (iVar6 == 0) {
        iVar6 = FUN_00174ce0(*(undefined4 *)(param_1 + 0x238),iVar5,param_1);
      }
      iVar5 = 4;
      *(undefined4 *)(iVar6 + 0xc) = 4;
      do {
        *(int *)(param_1 + 0x40) = iVar6;
        param_1 = param_1 + 4;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  return;
}

/* FUN_00180250 @ 0x180250 (1504 bytes) */
int FUN_00180250(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  char *pcVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int *piVar17;
  uint *puVar18;
  int iVar19;
  int local_58;
  int local_54 [3];
  int local_48;
  int local_44 [7];
  
  piVar17 = *(int **)(param_1 + 0xb0);
  if (*(int *)(piVar17[0x22] + 8) == 0x77) {
    iVar4 = FUN_001054ec(piVar17,1);
    local_54[0] = *(int *)(iVar4 + 0x10);
    bVar2 = false;
    iVar14 = 0;
    iVar4 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    local_58 = *(int *)(iVar4 + 0x10);
    iVar4 = param_1;
    do {
      if (*(int *)(iVar4 + 0x178) < 0) {
        pfVar5 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
        local_44[1] = 0;
        if (0.0 <= *pfVar5) {
          if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x238) + 0x30c) + 8) & 0x1000) != 0) {
            *(undefined1 *)((int)local_54 + iVar14) = 4;
            *(undefined1 *)((int)local_54 + iVar14 + -4) = 1;
          }
        }
        else {
          bVar2 = true;
        }
      }
      bVar1 = iVar14 != 3;
      iVar4 = iVar4 + 4;
      iVar14 = iVar14 + 1;
    } while (bVar1);
    if (bVar2) {
      bVar2 = false;
      iVar14 = 0;
      iVar4 = param_1;
      do {
        if (((*(uint *)(*(int *)(*(int *)(param_1 + 0x238) + 0x30c) + 8) & 0x1000) != 0) &&
           (*(int *)(iVar4 + 0x178) < 0)) {
          pfVar5 = (float *)FUN_00173360();
          local_44[1] = 0;
          if (*pfVar5 < 0.0) {
            if (bVar2) {
              *(undefined1 *)((int)local_54 + iVar14) = 4;
              *(undefined1 *)((int)local_54 + iVar14 + -4) = 1;
            }
            bVar2 = true;
          }
        }
        bVar1 = iVar14 != 3;
        iVar4 = iVar4 + 4;
        iVar14 = iVar14 + 1;
      } while (bVar1);
    }
    iVar14 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),1);
    iVar4 = local_54[0];
    if (local_54[0] == *(int *)(iVar14 + 0x10)) {
      piVar17 = *(int **)(param_1 + 0xb0);
      goto LAB_001803f4;
    }
    uVar13 = 1;
    iVar14 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),1);
    *(int *)(iVar14 + 0x10) = iVar4;
    *(int *)(*(int *)(param_1 + 0xb0) + 0x9c) = local_58;
    piVar17 = *(int **)(param_1 + 0xb0);
  }
  else {
LAB_001803f4:
    uVar13 = 0;
  }
  if (piVar17[0x20] == 0) {
LAB_001807f4:
    iVar4 = (**(code **)(*piVar17 + 0x68))(piVar17);
    if (iVar4 != 0) goto LAB_00180440;
  }
  else {
    iVar4 = FUN_00126760(piVar17[0x26]);
    if (((iVar4 == 0) || ((piVar17[5] & 2U) != 0)) ||
       (iVar4 = (**(code **)(*piVar17 + 0x50))(piVar17), iVar4 != 0)) {
      piVar17 = *(int **)(param_1 + 0xb0);
      goto LAB_001807f4;
    }
LAB_00180440:
    iVar4 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x28))();
    if ((iVar4 == 0) || ((*(uint *)(*(int *)(*(int *)(param_1 + 0x238) + 0x30c) + 8) & 0x800) != 0))
    {
      piVar17 = *(int **)(param_1 + 0xb0);
      goto LAB_001804a4;
    }
  }
  piVar17 = *(int **)(param_1 + 0xb0);
  if (*(int *)(piVar17[0x22] + 8) != 0x77) {
    return uVar13;
  }
  if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x238) + 0x30c) + 8) & 0x800) == 0) {
    return uVar13;
  }
LAB_001804a4:
  iVar14 = 1;
  iVar4 = param_1;
  do {
    iVar6 = (**(code **)(*piVar17 + 0x14))(piVar17);
    if (iVar6 < iVar14) {
      return uVar13;
    }
    iVar6 = thunk_FUN_001268a4(*(undefined4 *)(iVar14 * 0x18 + *(int *)(param_1 + 0xb0) + 0x98));
    if (iVar6 != 0) {
      puVar18 = *(uint **)(*(int *)(iVar14 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
      uVar15 = puVar18[1];
      uVar16 = uVar15 - 1;
      if (uVar16 < *puVar18) {
        if (uVar15 <= uVar16) {
          _memset((void *)(uVar15 * 4 + puVar18[2]),0,(uVar16 - uVar15) * 4 + 4);
          puVar18[1] = uVar15;
        }
        piVar17 = (int *)(uVar16 * 4 + puVar18[2]);
      }
      else {
        piVar17 = (int *)FUN_0019423c(puVar18,uVar16);
      }
      if ((*(int *)(*(int *)(*(int *)(*piVar17 + 0xb0) + 0x88) + 8) != 0x8e) ||
         (*(int *)(*piVar17 + 0xb4) != 0)) {
        iVar6 = FUN_001793d8(param_1,iVar14,*(undefined4 *)(iVar4 + 0x228));
        if (iVar6 == 4) {
          iVar6 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),iVar14);
          local_58 = *(int *)(iVar6 + 0x10);
          iVar6 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),iVar14);
          local_54[0] = *(int *)(iVar6 + 0x10);
          iVar6 = FUN_00113090(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                               *(undefined4 *)(param_1 + 0x238));
          if (iVar6 == 0) {
            FUN_000f3340(local_44,local_54[0],*(undefined4 *)(iVar4 + 0x228));
            local_54[0] = local_44[0];
          }
          iVar6 = param_1 + iVar14 * 4 + 0x220;
          iVar10 = param_1 + iVar14 * 0x10 + 0x160;
          pcVar8 = (char *)(iVar6 + 4);
          piVar17 = (int *)(iVar10 + 8);
          iVar7 = 0;
          do {
            if (*pcVar8 != '\0') {
              iVar19 = 4;
              pcVar12 = (char *)(iVar6 + 4);
              piVar11 = (int *)(iVar10 + 8);
              iVar9 = 0;
              do {
                if (*pcVar12 != '\0') {
                  if (iVar9 == iVar7) break;
                  if ((*piVar17 == *piVar11) &&
                     (cVar3 = *(char *)((int)local_54 + iVar9 + -4),
                     *(char *)((int)local_54 + iVar7) != cVar3)) {
                    *(char *)((int)local_54 + iVar7) = cVar3;
                    break;
                  }
                }
                iVar9 = iVar9 + 1;
                pcVar12 = pcVar12 + 1;
                piVar11 = piVar11 + 1;
                iVar19 = iVar19 + -1;
              } while (iVar19 != 0);
            }
            bVar2 = iVar7 != 3;
            pcVar8 = pcVar8 + 1;
            piVar17 = piVar17 + 1;
            iVar7 = iVar7 + 1;
          } while (bVar2);
          if ((local_54[0] != local_58) &&
             (piVar17 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c),
             iVar7 = (**(code **)(*piVar17 + 0x104))
                               (piVar17,*(undefined4 *)(param_1 + 0xb0),iVar14,local_54,0),
             iVar6 = local_54[0], iVar7 != 0)) {
            iVar7 = *(int *)(param_1 + 0xb0);
            if (iVar14 == 0) {
LAB_00180784:
              uVar13 = 1;
              *(int *)(iVar7 + 0x9c) = iVar6;
            }
            else {
              uVar13 = 1;
              iVar7 = FUN_001054ec(iVar7,iVar14);
              *(int *)(iVar7 + 0x10) = iVar6;
            }
          }
        }
        else {
          local_58 = *(int *)(PTR_DAT_001e8b8c + iVar6 * 4);
          iVar6 = FUN_00113090(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                               *(undefined4 *)(param_1 + 0x238));
          if (iVar6 == 0) {
            FUN_000f3340(&local_48,local_58,*(undefined4 *)(iVar4 + 0x228));
            local_58 = local_48;
          }
          iVar6 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),iVar14);
          if ((local_58 != *(int *)(iVar6 + 0x10)) &&
             (piVar17 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c),
             iVar7 = (**(code **)(*piVar17 + 0x104))
                               (piVar17,*(undefined4 *)(param_1 + 0xb0),iVar14,&local_58,0),
             iVar6 = local_58, iVar7 != 0)) {
            iVar7 = *(int *)(param_1 + 0xb0);
            if (iVar14 == 0) goto LAB_00180784;
            uVar13 = 1;
            iVar7 = FUN_001054ec(iVar7,iVar14);
            *(int *)(iVar7 + 0x10) = iVar6;
          }
        }
      }
    }
    piVar17 = *(int **)(param_1 + 0xb0);
    iVar14 = iVar14 + 1;
    iVar4 = iVar4 + 4;
  } while( true );
}

/* FUN_00180830 @ 0x180830 (4312 bytes) */
int FUN_00180830(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  undefined4 uVar19;
  uint uVar20;
  undefined4 uVar21;
  uint uVar22;
  int *piVar23;
  float fVar24;
  char *pcVar25;
  uint *puVar26;
  int iVar27;
  double dVar28;
  uint local_9c;
  float local_98 [4];
  longlong local_88;
  longlong local_80;
  uint local_78;
  uint local_74;
  undefined4 local_70;
  undefined4 local_6c;
  uint local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c [3];
  
  if (*(int *)(*(int *)(param_1 + 0x238) + 0x658) <=
      *(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0xa8)) {
    return 0;
  }
  piVar23 = *(int **)(param_1 + 0xb0);
  uVar14 = 0;
  for (iVar16 = 1; iVar4 = (**(code **)(*piVar23 + 0x14))(piVar23), iVar16 <= iVar4;
      iVar16 = iVar16 + 1) {
    piVar23 = *(int **)(param_1 + 0xb0);
    if ((piVar23[iVar16 * 6 + 0x28] & 2U) != 0) {
      puVar26 = *(uint **)(piVar23[iVar16 * 6 + 0x23] + 0x2c);
      uVar20 = puVar26[1];
      uVar17 = uVar20 - 1;
      if (uVar17 < *puVar26) {
        if (uVar20 <= uVar17) {
          _memset((void *)(uVar20 * 4 + puVar26[2]),0,(uVar17 - uVar20) * 4 + 4);
          puVar26[1] = uVar20;
          piVar23 = *(int **)(param_1 + 0xb0);
        }
        puVar10 = (undefined4 *)(uVar17 * 4 + puVar26[2]);
      }
      else {
        puVar10 = (undefined4 *)FUN_0019423c(puVar26,uVar17);
        piVar23 = *(int **)(param_1 + 0xb0);
      }
      uVar21 = *puVar10;
      bVar2 = true;
      pcVar25 = (char *)(iVar16 * 4 + param_1 + 0x224);
      bVar3 = true;
      iVar4 = 0;
      do {
        if (*pcVar25 != '\0') {
          iVar18 = FUN_001054ec(piVar23,iVar16);
          iVar18 = FUN_00176518(uVar21,*(undefined1 *)(iVar4 + iVar18 + 0x10));
          if (iVar18 == 0) {
            iVar18 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),iVar16);
            iVar18 = FUN_001764fc(uVar21,*(undefined1 *)(iVar4 + iVar18 + 0x10));
            if ((iVar18 == 0) || (!bVar3)) {
LAB_00180a10:
              piVar23 = *(int **)(param_1 + 0xb0);
              goto LAB_00180a14;
            }
            piVar23 = *(int **)(param_1 + 0xb0);
            bVar2 = false;
          }
          else {
            if (!bVar2) goto LAB_00180a10;
            piVar23 = *(int **)(param_1 + 0xb0);
            bVar3 = false;
          }
        }
        bVar1 = iVar4 != 3;
        pcVar25 = pcVar25 + 1;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      if (bVar2) {
        FUN_00103d50(piVar23 + iVar16 * 6 + 0x23,2,0);
        piVar23 = *(int **)(param_1 + 0xb0);
        uVar14 = 1;
      }
      else if ((bVar3) && ((piVar23[iVar16 * 6 + 0x28] & 1U) != 0)) {
        uVar14 = 1;
        FUN_00103d50(piVar23 + iVar16 * 6 + 0x23,2,0);
        FUN_00103d50(iVar16 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c,1,0);
        piVar23 = *(int **)(param_1 + 0xb0);
      }
    }
LAB_00180a14: ;
  }
  iVar16 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),10);
  if (iVar16 != 0) {
    iVar4 = 0x18;
    iVar16 = param_1;
    for (iVar18 = 1; iVar6 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(), iVar18 <= iVar6;
        iVar18 = iVar18 + 1) {
      iVar6 = FUN_00105dbc(*(undefined4 *)(param_1 + 0xb0),iVar18);
      if (iVar6 == 2) {
        puVar26 = *(uint **)(*(int *)(iVar4 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
        uVar17 = puVar26[1];
        uVar20 = uVar17 - 1;
        if (uVar20 < *puVar26) {
          if (uVar17 <= uVar20) {
            _memset((void *)(uVar17 * 4 + puVar26[2]),0,(uVar20 - uVar17) * 4 + 4);
            puVar26[1] = uVar17;
          }
          piVar23 = (int *)(uVar20 * 4 + puVar26[2]);
        }
        else {
          piVar23 = (int *)FUN_0019423c(puVar26,uVar20);
        }
        iVar6 = *piVar23;
        if (*(int *)(iVar6 + 0x178) < 0) {
          pfVar5 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
          if (*(int *)(*(int *)(iVar6 + 0xb0) + 300) == 0) {
            dVar28 = (double)_floor((double)*pfVar5);
            iVar6 = (int)dVar28;
            local_80 = (longlong)iVar6;
          }
          else {
            dVar28 = (double)_floor((double)*pfVar5 + DOUBLE_001aa240);
            iVar6 = (int)dVar28;
            local_88 = (longlong)iVar6;
          }
          iVar15 = FUN_00105c5c(*(undefined4 *)(param_1 + 0xb0),iVar18);
          iVar6 = iVar6 + iVar15;
          if (*(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x30c) + 0x2c) <= iVar6) {
            iVar6 = 0;
          }
          iVar15 = *(int *)(param_1 + 0xb0);
          uVar21 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0x3ac);
          if ((iVar18 < 1) || (iVar13 = FUN_00105594(iVar15,iVar18), iVar13 == 0)) {
            uVar19 = *(undefined4 *)(iVar4 + iVar15 + 0x98);
          }
          else {
            iVar15 = FUN_00105594(iVar15,iVar18);
            uVar19 = *(undefined4 *)(iVar15 + 0x98);
          }
          iVar15 = FUN_00126708(uVar19);
          if (iVar15 == 0) {
            uVar21 = FUN_00127608(uVar21,0,iVar6,0);
          }
          else {
            uVar21 = FUN_00127608(uVar21,2,iVar6,0);
          }
          FUN_001046c8(*(undefined4 *)(param_1 + 0xb0),iVar18,uVar21);
          FUN_001236e4(uVar21,iVar18,*(undefined4 *)(param_1 + 0xb0));
          iVar6 = FUN_00122fa4(uVar21,*(undefined4 *)
                                       (*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0x3a0));
          *(undefined4 *)(iVar16 + 0x214) = *(undefined4 *)(iVar6 + 0xb0);
        }
      }
      iVar4 = iVar4 + 0x18;
      iVar16 = iVar16 + 4;
    }
  }
  piVar23 = *(int **)(param_1 + 0xb0);
  if (piVar23[0x20] == 0) {
LAB_001818e8:
    if (((piVar23[5] & 2U) != 0) || (iVar16 = FUN_001789d4(piVar23), iVar16 != 0))
    goto LAB_00180cb4;
  }
  else {
    iVar16 = FUN_00126760(piVar23[0x26]);
    if (((iVar16 == 0) || ((piVar23[5] & 2U) != 0)) ||
       (iVar16 = (**(code **)(*piVar23 + 0x50))(piVar23), iVar16 != 0)) {
      piVar23 = *(int **)(param_1 + 0xb0);
      goto LAB_001818e8;
    }
    piVar23 = *(int **)(param_1 + 0xb0);
LAB_00180cb4:
    iVar16 = param_1;
    for (iVar4 = 1; iVar18 = (**(code **)(*piVar23 + 0x14))(piVar23), iVar4 <= iVar18;
        iVar4 = iVar4 + 1) {
      puVar26 = *(uint **)(*(int *)(iVar4 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
      uVar20 = puVar26[1];
      uVar17 = uVar20 - 1;
      if (uVar17 < *puVar26) {
        if (uVar20 <= uVar17) {
          _memset((void *)(uVar20 * 4 + puVar26[2]),0,(uVar17 - uVar20) * 4 + 4);
          puVar26[1] = uVar20;
        }
        piVar23 = (int *)(uVar17 * 4 + puVar26[2]);
      }
      else {
        piVar23 = (int *)FUN_0019423c(puVar26,uVar17);
      }
      piVar23 = *(int **)(*piVar23 + 0xb0);
      iVar18 = (**(code **)(*piVar23 + 0x74))(piVar23);
      if (((iVar18 != 0) && (*(int *)(piVar23[0x22] + 8) == 0xfb)) &&
         (iVar18 = FUN_00105dbc(*(undefined4 *)(param_1 + 0xb0),iVar4), iVar18 == 0)) {
        iVar18 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),iVar4);
        FUN_000f3398(&local_78,*(undefined4 *)(iVar18 + 0x10));
        local_9c = local_78;
        piVar11 = (int *)FUN_0017bc58(piVar23,local_78,1,*(undefined4 *)(param_1 + 0x238));
        if (piVar11 != (int *)0x0) {
          iVar18 = (**(code **)(*piVar11 + 0x40))();
          if (iVar18 == 0) {
            iVar18 = FUN_001054ec(piVar11,0);
            FUN_000f3908(&local_74,*(undefined4 *)(iVar18 + 0x10));
            uVar20 = local_74;
            uVar17 = DAT_001b01e0;
            uVar22 = ~local_74;
            if (((uVar22 << 0x18 | (uVar22 & 0xff00) << 8 | uVar22 >> 8 & 0xff00 | uVar22 >> 0x18) &
                local_9c) == DAT_001b01e0) {
              iVar18 = FUN_00105594(piVar11,1);
              *(int *)(iVar16 + 0x214) = iVar18;
              uVar19 = *(undefined4 *)(iVar18 + 0x8c);
              uVar21 = *(undefined4 *)(param_1 + 0xb0);
            }
            else {
              fVar7 = (float)FUN_001043f0(0x31,*(undefined4 *)(param_1 + 0x238));
              FUN_001046c8(fVar7,0,piVar23[0x23]);
              *(undefined4 *)((int)fVar7 + 0x98) = 0;
              *(undefined4 *)((int)fVar7 + 0x94) = *(undefined4 *)((int)fVar7 + 0x14c);
              iVar18 = FUN_00105594(piVar11,1);
              FUN_001046c8(fVar7,1,*(undefined4 *)(iVar18 + 0x8c));
              FUN_00106004(fVar7,1,iVar18,0,*(undefined4 *)(param_1 + 0x238));
              uVar22 = ~(uVar20 & local_9c);
              FUN_000f3764(&local_70,uVar20 & local_9c);
              *(undefined4 *)((int)fVar7 + 0x9c) = local_70;
              FUN_000f370c(&local_6c,local_70);
              uVar21 = local_6c;
              iVar18 = FUN_001054ec(fVar7,1);
              *(undefined4 *)(iVar18 + 0x10) = uVar21;
              iVar18 = 0;
              local_98[0] = fVar7;
              local_9c = (uVar22 << 0x18 | (uVar22 & 0xff00) << 8 | uVar22 >> 8 & 0xff00 |
                         uVar22 >> 0x18) & local_9c;
              if (uVar17 == local_9c) {
LAB_00181100:
                pfVar5 = local_98 + iVar18;
                iVar6 = 0;
                do {
                  fVar24 = *pfVar5;
                  FUN_000e7700(*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158),
                               *(int *)(param_1 + 0xb0),fVar24);
                  FUN_0012306c(*(undefined4 *)((int)fVar24 + 0x8c),fVar24);
                  iVar15 = FUN_00105594(fVar24,1);
                  FUN_001236e4(*(undefined4 *)(iVar15 + 0x8c),1,fVar24);
                  uVar21 = *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x378);
                  puVar10 = (undefined4 *)FUN_00193e18(uVar21,0x240);
                  *puVar10 = uVar21;
                  puVar10 = puVar10 + 1;
                  FUN_00173938(puVar10,fVar24,*(undefined4 *)(param_1 + 0x238));
                  iVar6 = iVar6 + 1;
                  pfVar5 = pfVar5 + -1;
                  FUN_0011e988(puVar10,*(undefined4 *)
                                        (*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0x3a0));
                  FUN_00173f1c(puVar10);
                  FUN_00174e0c(puVar10);
                  FUN_00175b40(puVar10);
                  FUN_00173278(puVar10);
                  FUN_000e9c00(*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158),
                               *(undefined4 *)((int)fVar24 + 0x8c),puVar10);
                } while (iVar18 + 1 != iVar6);
              }
              else {
                pfVar5 = local_98;
                iVar6 = 1;
                fVar24 = fVar7;
                do {
                  iVar18 = iVar6;
                  pfVar5 = pfVar5 + 1;
                  piVar11 = (int *)FUN_0017bc58(piVar23,local_9c,0,*(undefined4 *)(param_1 + 0x238))
                  ;
                  if (piVar11 == (int *)0x0) goto LAB_00181220;
                  fVar8 = (float)FUN_001043f0(0x31,*(undefined4 *)(param_1 + 0x238));
                  FUN_001046c8(fVar8,0,piVar23[0x23]);
                  *(undefined4 *)((int)fVar8 + 0x98) = 0;
                  *(undefined4 *)((int)fVar8 + 0x94) = *(undefined4 *)((int)fVar8 + 0x14c);
                  FUN_001049e8(fVar24,*(undefined4 *)((int)fVar8 + 0x8c),
                               *(undefined4 *)(param_1 + 0x238));
                  FUN_00106804(fVar24,fVar8,0,*(undefined4 *)(param_1 + 0x238));
                  iVar6 = FUN_001054ec(piVar11,0);
                  FUN_000f3908(&local_68,*(undefined4 *)(iVar6 + 0x10));
                  uVar17 = local_68 & local_9c;
                  FUN_000f3764(&local_64,uVar17);
                  *(undefined4 *)((int)fVar8 + 0x9c) = local_64;
                  FUN_000f370c(&local_60,local_64);
                  uVar21 = local_60;
                  iVar6 = FUN_001054ec(fVar8,1);
                  *(undefined4 *)(iVar6 + 0x10) = uVar21;
                  iVar6 = (**(code **)(*piVar11 + 0x40))(piVar11);
                  if (iVar6 == 0) {
                    iVar6 = FUN_00105594(piVar11,1);
                    FUN_001046c8(fVar8,1,*(undefined4 *)(iVar6 + 0x8c));
                    FUN_00106004(fVar8,1,iVar6,0,*(undefined4 *)(param_1 + 0x238));
                  }
                  else {
                    iVar6 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
                    iVar6 = FUN_00123c08(iVar6,*(undefined4 *)(iVar6 + 0x3a0),0);
                    iVar6 = *(int *)(iVar6 + 0xb0);
                    FUN_001046c8(fVar8,1,*(undefined4 *)(iVar6 + 0x8c));
                    FUN_00106004(fVar8,1,iVar6,0,*(undefined4 *)(param_1 + 0x238));
                    local_9c = 0;
                  }
                  uVar17 = ~uVar17;
                  local_9c = (uVar17 << 0x18 | (uVar17 & 0xff00) << 8 | uVar17 >> 8 & 0xff00 |
                             uVar17 >> 0x18) & local_9c;
                  *pfVar5 = fVar8;
                  iVar6 = iVar18 + 1;
                  fVar24 = fVar8;
                } while (DAT_001b01e0 != local_9c);
                if (iVar18 + 1 == 0) goto LAB_00181220;
                if (-1 < iVar18) goto LAB_00181100;
              }
              *(float *)(iVar16 + 0x214) = fVar7;
              uVar19 = *(undefined4 *)((int)fVar7 + 0x8c);
              uVar21 = *(undefined4 *)(param_1 + 0xb0);
            }
          }
          else {
            iVar18 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
            iVar18 = FUN_00123c08(iVar18,*(undefined4 *)(iVar18 + 0x3a0),0);
            iVar18 = *(int *)(iVar18 + 0xb0);
            uVar21 = *(undefined4 *)(param_1 + 0xb0);
            *(int *)(iVar16 + 0x214) = iVar18;
            uVar19 = *(undefined4 *)(iVar18 + 0x8c);
          }
          FUN_001046c8(uVar21,iVar4,uVar19);
          FUN_001236e4(uVar19,iVar4,*(undefined4 *)(param_1 + 0xb0));
        }
      }
LAB_00181220:
      piVar23 = *(int **)(param_1 + 0xb0);
      iVar16 = iVar16 + 4;
    }
    piVar23 = *(int **)(param_1 + 0xb0);
  }
  if (piVar23[0x20] != 0) {
    iVar16 = FUN_00126760(piVar23[0x26]);
    if (((iVar16 != 0) && ((piVar23[5] & 2U) == 0)) &&
       (iVar16 = (**(code **)(*piVar23 + 0x50))(piVar23), iVar16 == 0)) {
      piVar23 = *(int **)(param_1 + 0xb0);
      goto LAB_001812b0;
    }
    piVar23 = *(int **)(param_1 + 0xb0);
  }
  if (((piVar23[5] & 2U) == 0) && (iVar16 = FUN_001789d4(piVar23), iVar16 == 0)) {
    return uVar14;
  }
LAB_001812b0:
  iVar15 = 1;
  iVar18 = param_1 + 0x170;
  iVar6 = param_1 + 0x224;
  iVar4 = 4;
  iVar16 = param_1;
  do {
    iVar13 = (**(code **)(*piVar23 + 0x14))(piVar23);
    if (iVar13 < iVar15) {
      return uVar14;
    }
    piVar23 = *(int **)(param_1 + 0xb0);
    uVar21 = *(undefined4 *)(piVar23[0x22] + 8);
    iVar9 = FUN_00176564(uVar21);
    iVar13 = 0x7ffffffe;
    if (iVar9 == 0) {
      iVar13 = FUN_00176574(uVar21);
      if (iVar13 == 0) {
        iVar13 = FUN_00113174(uVar21,*(undefined4 *)(param_1 + 0x238));
        if (iVar13 == 0) {
          iVar13 = FUN_00113090(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                                *(undefined4 *)(param_1 + 0x238));
          if (iVar13 == 0) {
            FUN_001770e4(&local_50,param_1,iVar15);
            piVar23 = *(int **)(param_1 + 0xb0);
            iVar13 = local_50;
          }
          else {
            FUN_001769f4(&local_54,param_1,iVar15);
            piVar23 = *(int **)(param_1 + 0xb0);
            iVar13 = local_54;
          }
        }
        else {
          FUN_00178d78(&local_58,param_1,iVar15);
          piVar23 = *(int **)(param_1 + 0xb0);
          iVar13 = local_58;
        }
      }
      else {
        FUN_00178c84(&local_5c,param_1,iVar15);
        piVar23 = *(int **)(param_1 + 0xb0);
        iVar13 = local_5c;
      }
    }
    if ((piVar23[5] & 2U) == 0) {
LAB_001813e0:
      if (((piVar23[iVar15 * 6 + 0x26] == 0x33) || (piVar23[iVar15 * 6 + 0x26] == 0xc)) ||
         (*(uint *)(iVar6 + 4) == DAT_001b01e0)) goto LAB_001816c0;
      pcVar25 = (char *)(iVar6 + 4);
      local_98[3] = 0.0;
      piVar23 = (int *)(iVar18 + 8);
      local_98[0] = 0.0;
      bVar3 = true;
      local_98[1] = 0.0;
      iVar9 = 0;
      local_98[2] = 0.0;
      do {
        if (*pcVar25 != '\0') {
          if (*piVar23 < 0) {
            puVar10 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238));
            *(undefined4 *)((int)local_98 + iVar9) = *puVar10;
          }
          else {
            bVar3 = false;
          }
        }
        bVar2 = iVar9 != 0xc;
        pcVar25 = pcVar25 + 1;
        piVar23 = piVar23 + 1;
        iVar9 = iVar9 + 4;
      } while (bVar2);
      uVar21 = *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x6c4);
      FUN_000f3340(local_4c,DAT_001b01d8,*(undefined4 *)(iVar16 + 0x228));
      local_9c = local_4c[0];
      if (iVar13 != 0x7ffffffe) {
        piVar23 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
        iVar9 = (**(code **)(*piVar23 + 0x154))(piVar23,uVar21,local_98,&local_9c);
        if (iVar9 == 0) {
          iVar27 = 4;
          pcVar25 = (char *)(iVar4 + param_1 + 0x224);
          iVar9 = 0;
          do {
            if (*pcVar25 != '\0') {
              *(float *)(iVar9 + (int)local_98) = -*(float *)(iVar9 + (int)local_98);
            }
            pcVar25 = pcVar25 + 1;
            iVar9 = iVar9 + 4;
            iVar27 = iVar27 + -1;
          } while (iVar27 != 0);
          goto LAB_00181590;
        }
LAB_001815cc:
        uVar19 = 0;
LAB_001815d0:
        piVar23 = *(int **)(param_1 + 0xb0);
        if (piVar23[iVar15 * 6 + 0x26] != *(int *)(iVar9 + 0x98)) {
          piVar11 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
          iVar27 = (**(code **)(*piVar11 + 0x11c))(piVar11,piVar23,iVar15,iVar9,0,uVar19);
          if (iVar27 == 0) goto LAB_001816bc;
          uVar14 = FUN_0017ae28(param_1,iVar15,iVar9,local_9c,uVar19,0,
                                *(undefined4 *)(param_1 + 0x238));
          iVar27 = 0;
          *(undefined4 *)(iVar16 + 0x214) = uVar14;
          iVar9 = param_1;
          do {
            iVar12 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
            if (*(char *)(iVar27 + iVar12 + 0x10) == '\x01') {
              *(undefined4 *)(iVar9 + 0x30) = 0;
            }
            bVar3 = iVar27 != 3;
            iVar9 = iVar9 + 4;
            iVar27 = iVar27 + 1;
          } while (bVar3);
          piVar23 = *(int **)(param_1 + 0xb0);
          uVar14 = 1;
        }
        goto LAB_001816c0;
      }
      if (bVar3) {
        piVar23 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
        iVar9 = (**(code **)(*piVar23 + 0x154))(piVar23,uVar21,local_98,&local_9c);
        if (iVar9 != 0) goto LAB_001815cc;
        iVar27 = 4;
        pcVar25 = (char *)(iVar4 + param_1 + 0x224);
        iVar9 = 0;
        do {
          if (*pcVar25 != '\0') {
            *(float *)(iVar9 + (int)local_98) = -*(float *)(iVar9 + (int)local_98);
          }
          pcVar25 = pcVar25 + 1;
          iVar9 = iVar9 + 4;
          iVar27 = iVar27 + -1;
        } while (iVar27 != 0);
LAB_00181590:
        piVar23 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
        uVar19 = 1;
        iVar9 = (**(code **)(*piVar23 + 0x154))(piVar23,uVar21,local_98,&local_9c);
        if (iVar9 != 0) goto LAB_001815d0;
LAB_001816bc:
        piVar23 = *(int **)(param_1 + 0xb0);
        goto LAB_001816c0;
      }
      piVar23 = *(int **)(param_1 + 0xb0);
    }
    else {
      iVar9 = (**(code **)(**(int **)(*(int *)(param_1 + 0x238) + 0x30c) + 0xbc))();
      if (iVar9 != 0) {
        piVar23 = *(int **)(param_1 + 0xb0);
        goto LAB_001813e0;
      }
      piVar23 = *(int **)(param_1 + 0xb0);
LAB_001816c0:
      if (iVar13 != 0x7ffffffe) {
        if (*(int *)(piVar23[0x22] + 8) != 0x8e) {
          pcVar25 = (char *)(iVar6 + 4);
          iVar9 = 4;
          iVar13 = 0;
          do {
            if (*pcVar25 != '\0') {
              iVar9 = FUN_001054ec(piVar23,iVar15);
              piVar23 = *(int **)(param_1 + 0xb0);
              uVar17 = (uint)*(byte *)(iVar13 + iVar9 + 0x10);
              goto LAB_00181700;
            }
            iVar13 = iVar13 + 1;
            pcVar25 = pcVar25 + 1;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
          uVar17 = 0;
LAB_00181700:
          puVar26 = *(uint **)(piVar23[iVar15 * 6 + 0x23] + 0x2c);
          uVar20 = puVar26[1];
          uVar22 = uVar20 - 1;
          if (uVar22 < *puVar26) {
            if (uVar20 <= uVar22) {
              _memset((void *)(uVar20 * 4 + puVar26[2]),0,(uVar22 - uVar20) * 4 + 4);
              puVar26[1] = uVar20;
            }
            piVar23 = (int *)(uVar22 * 4 + puVar26[2]);
          }
          else {
            piVar23 = (int *)FUN_0019423c(puVar26,uVar22);
          }
          piVar23 = (int *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),
                                        *(undefined4 *)(uVar17 * 4 + *piVar23 + 0x20));
          iVar13 = *piVar23;
        }
        piVar23 = (int *)FUN_00173e10(*(undefined4 *)(param_1 + 0x238),iVar13);
        if (*piVar23 == 0) {
          piVar23 = *(int **)(param_1 + 0xb0);
          if ((piVar23[iVar15 * 6 + 0x28] & 2U) != 0) {
            uVar14 = 1;
            FUN_00103d50(piVar23 + iVar15 * 6 + 0x23,2,0);
            piVar23 = *(int **)(param_1 + 0xb0);
          }
          if ((piVar23[iVar15 * 6 + 0x28] & 1U) != 0) {
            uVar14 = 1;
            FUN_00103d50(piVar23 + iVar15 * 6 + 0x23,1,0);
            piVar23 = *(int **)(param_1 + 0xb0);
          }
        }
        else if (*piVar23 < 1) {
          piVar23 = *(int **)(param_1 + 0xb0);
          if ((piVar23[iVar15 * 6 + 0x28] & 2U) != 0) {
            uVar14 = 1;
            FUN_00103d50(piVar23 + iVar15 * 6 + 0x23,2,0);
            iVar13 = *(int *)(param_1 + 0xb0) + iVar15 * 0x18 + 0x80;
            FUN_00103d50(iVar13 + 0xc,1,(*(uint *)(iVar13 + 0x20) ^ 1) & 1);
            piVar23 = *(int **)(param_1 + 0xb0);
          }
        }
        else {
          piVar23 = *(int **)(param_1 + 0xb0);
          if ((piVar23[iVar15 * 6 + 0x28] & 2U) != 0) {
            uVar14 = 1;
            FUN_00103d50(piVar23 + iVar15 * 6 + 0x23,2,0);
            piVar23 = *(int **)(param_1 + 0xb0);
          }
        }
      }
    }
    iVar15 = iVar15 + 1;
    iVar4 = iVar4 + 4;
    iVar6 = iVar6 + 4;
    iVar18 = iVar18 + 0x10;
    iVar16 = iVar16 + 4;
  } while( true );
}

/* FUN_00181928 @ 0x181928 (140 bytes) */
int FUN_00181928(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0010497c(param_1,param_3);
  if ((((iVar1 == 0) || (iVar1 = (**(code **)(*param_1 + 0x68))(param_1), iVar1 != 0)) ||
      ((param_1[5] & 0x200U) != 0)) ||
     ((*(int *)(param_1[0x22] + 8) == 0x8e || (uVar2 = 1, param_1[0x56] != param_2)))) {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_001819b4 @ 0x1819b4 (252 bytes) */
int FUN_001819b4(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  if ((((param_1[0x20] == 0) || (iVar1 = FUN_00126760(param_1[0x26]), iVar1 == 0)) ||
      ((param_1[5] & 2U) != 0)) || (iVar1 = (**(code **)(*param_1 + 0x50))(param_1), iVar1 != 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_000f3a30(param_1);
  }
  if (((param_2[0x20] == 0) || (iVar2 = FUN_00126760(param_2[0x26]), iVar2 == 0)) ||
     (((param_2[5] & 2U) != 0 || (iVar2 = (**(code **)(*param_2 + 0x50))(param_2), iVar2 != 0)))) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_000f3a30(param_2);
  }
  return param_2[0x54] - iVar2 < param_1[0x54] - iVar1;
}

/* FUN_00181ab0 @ 0x181ab0 (208 bytes) */
int FUN_00181ab0(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint *puVar9;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0x98) + 8);
  if (iVar1 != 0) {
    iVar5 = 0;
    iVar6 = *(int *)(param_2 + 0x98);
    do {
      iVar2 = iVar1;
      if ((*(uint *)(iVar6 + 0x14) & 1) != 0) {
        *(int *)(iVar6 + 0x150) = iVar5;
        uVar8 = *(undefined4 *)(*param_1 + 0x378);
        puVar3 = (undefined4 *)FUN_00193e18(uVar8,0x1c);
        *puVar3 = uVar8;
        puVar9 = (uint *)param_1[7];
        uVar7 = puVar9[1];
        if (uVar7 < *puVar9) {
          _memset((void *)(uVar7 * 4 + puVar9[2]),0,4);
          piVar4 = (int *)(uVar7 * 4 + puVar9[2]);
          puVar9[1] = uVar7 + 1;
        }
        else {
          piVar4 = (int *)FUN_0019423c(puVar9,uVar7);
        }
        *piVar4 = (int)(puVar3 + 1);
        iVar5 = iVar5 + 1;
        iVar2 = *(int *)(iVar6 + 8);
      }
      iVar1 = *(int *)(iVar2 + 8);
      iVar6 = iVar2;
    } while (*(int *)(iVar2 + 8) != 0);
  }
  return;
}

/* FUN_00181b80 @ 0x181b80 (896 bytes) */
int FUN_00181b80(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  undefined4 *param_4;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  
  iVar1 = *(int *)(param_2 + 0x98);
  for (iVar10 = *(int *)(*(int *)(param_2 + 0x98) + 8); iVar10 != 0; iVar10 = *(int *)(iVar10 + 8))
  {
    if ((*(uint *)(iVar1 + 0x14) & 1) != 0) {
      puVar11 = *(uint **)(param_1 + 0x1c);
      uVar9 = *(uint *)(iVar1 + 0x150);
      if (uVar9 < *puVar11) {
        uVar3 = puVar11[1];
        if (uVar3 <= uVar9) {
          _memset((void *)(uVar3 * 4 + puVar11[2]),0,(uVar9 - uVar3) * 4 + 4);
          puVar11[1] = uVar9 + 1;
        }
        puVar4 = (undefined4 *)(uVar9 * 4 + puVar11[2]);
      }
      else {
        puVar4 = (undefined4 *)FUN_0019423c(puVar11,uVar9);
      }
      puVar4 = (undefined4 *)*puVar4;
      *puVar4 = 1;
      puVar4[1] = 1;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      puVar4[5] = 1;
      if ((*(int *)(*(int *)(iVar1 + 0x88) + 8) != 0x8e) && (0 < *(int *)(iVar1 + 0x84))) {
        iVar10 = 1;
        do {
          iVar5 = FUN_00105594(iVar1,iVar10);
          if (param_2 == *(int *)(iVar5 + 0x158)) {
            puVar11 = *(uint **)(param_1 + 0x1c);
            uVar9 = *(uint *)(iVar5 + 0x150);
            if (uVar9 < *puVar11) {
              uVar3 = puVar11[1];
              if (uVar3 <= uVar9) {
                _memset((void *)(uVar3 * 4 + puVar11[2]),0,(uVar9 - uVar3) * 4 + 4);
                puVar11[1] = uVar9 + 1;
              }
              piVar6 = (int *)(uVar9 * 4 + puVar11[2]);
            }
            else {
              piVar6 = (int *)FUN_0019423c(puVar11,uVar9);
            }
            iVar2 = *(int *)(*piVar6 + 4) + 1;
            iVar5 = puVar4[1];
            if ((int)puVar4[1] < iVar2) {
              iVar5 = iVar2;
            }
            puVar4[1] = iVar5;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 <= *(int *)(iVar1 + 0x84));
      }
      iVar10 = *(int *)(iVar1 + 8);
    }
    iVar1 = iVar10;
  }
  *param_3 = 0;
  FUN_00172000(*(undefined4 *)(param_1 + 8));
  iVar1 = *(int *)(param_2 + 0xa0);
  for (iVar10 = *(int *)(*(int *)(param_2 + 0xa0) + 4); iVar10 != 0; iVar10 = *(int *)(iVar10 + 4))
  {
    if (((*(uint *)(iVar1 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar1 + 0x88) + 8) != 0x8e)) {
      puVar11 = *(uint **)(param_1 + 0x1c);
      uVar9 = *(uint *)(iVar1 + 0x150);
      if (uVar9 < *puVar11) {
        uVar3 = puVar11[1];
        if (uVar3 <= uVar9) {
          _memset((void *)(uVar3 * 4 + puVar11[2]),0,(uVar9 - uVar3) * 4 + 4);
          puVar11[1] = uVar9 + 1;
        }
        puVar4 = (undefined4 *)(uVar9 * 4 + puVar11[2]);
      }
      else {
        puVar4 = (undefined4 *)FUN_0019423c(puVar11,uVar9);
      }
      piVar6 = (int *)*puVar4;
      FUN_00172204(*(undefined4 *)(param_1 + 8),iVar1);
      if (0 < *(int *)(iVar1 + 0x84)) {
        iVar10 = 1;
        do {
          iVar5 = FUN_00105594(iVar1,iVar10);
          if (param_2 == *(int *)(iVar5 + 0x158)) {
            puVar11 = *(uint **)(param_1 + 0x1c);
            uVar9 = *(uint *)(iVar5 + 0x150);
            if (uVar9 < *puVar11) {
              uVar3 = puVar11[1];
              if (uVar3 <= uVar9) {
                _memset((void *)(uVar3 * 4 + puVar11[2]),0,(uVar9 - uVar3) * 4 + 4);
                puVar11[1] = uVar9 + 1;
              }
              puVar4 = (undefined4 *)(uVar9 * 4 + puVar11[2]);
            }
            else {
              puVar4 = (undefined4 *)FUN_0019423c(puVar11,uVar9);
            }
            piVar7 = (int *)*puVar4;
            iVar5 = *piVar7;
            if (*piVar7 < *piVar6 + 1) {
              iVar5 = *piVar6 + 1;
            }
            piVar7[4] = iVar10;
            *piVar7 = iVar5;
            piVar7[3] = iVar1;
            if (iVar5 < *param_3) {
              iVar5 = *param_3;
            }
            *param_3 = iVar5;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 <= *(int *)(iVar1 + 0x84));
      }
      iVar10 = *(int *)(iVar1 + 4);
    }
    iVar1 = iVar10;
  }
  uVar8 = (**(code **)(**(int **)(param_1 + 8) + 0x5c))();
  *param_4 = uVar8;
  return;
}

/* FUN_00181f00 @ 0x181f00 (7020 bytes) */
int FUN_00181f00(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint *puVar16;
  uint *puVar17;
  uint *puVar18;
  int iVar19;
  int iVar20;
  undefined4 uVar21;
  uint uVar22;
  uint *puVar23;
  uint *puVar24;
  int iVar25;
  uint uVar26;
  undefined1 auStack_88 [8];
  int local_80;
  uint local_68;
  uint local_64;
  uint local_60;
  undefined4 local_5c;
  
  uVar21 = *(undefined4 *)(*param_1 + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar21,0x14);
  puVar16 = puVar5 + 1;
  *puVar5 = uVar21;
  puVar5[1] = 2;
  puVar5[4] = uVar21;
  puVar5[2] = 0;
  uVar21 = FUN_00193e18(uVar21,8);
  puVar5[3] = uVar21;
  uVar21 = *(undefined4 *)(*param_1 + 0x378);
  puVar6 = (undefined4 *)FUN_00193e18(uVar21,0x14);
  puVar18 = puVar6 + 1;
  *puVar6 = uVar21;
  puVar6[1] = 2;
  puVar6[4] = uVar21;
  puVar6[2] = 0;
  uVar21 = FUN_00193e18(uVar21,8);
  puVar6[3] = uVar21;
  uVar21 = *(undefined4 *)(*param_1 + 0x378);
  puVar7 = (undefined4 *)FUN_00193e18(uVar21,0x14);
  puVar17 = puVar7 + 1;
  *puVar7 = uVar21;
  puVar7[1] = 2;
  puVar7[2] = 0;
  puVar7[4] = uVar21;
  uVar21 = FUN_00193e18(uVar21,8);
  uVar22 = puVar5[2];
  uVar2 = *puVar16;
  puVar7[3] = uVar21;
  if (uVar22 < uVar2) {
    _memset((void *)(uVar22 * 4 + puVar5[3]),0,4);
    piVar8 = (int *)(uVar22 * 4 + puVar5[3]);
    puVar5[2] = uVar22 + 1;
  }
  else {
    piVar8 = (int *)FUN_0019423c(puVar16,uVar22);
  }
  *piVar8 = param_3;
  while (uVar2 = puVar5[2], uVar2 != 0) {
    piVar8 = (int *)0x0;
    if (uVar2 - 1 < uVar2) {
      piVar8 = (int *)((uVar2 - 1) * 4 + puVar5[3]);
    }
    iVar15 = *piVar8;
    iVar19 = 1;
    FUN_00194208(puVar16,uVar2 - 1);
    puVar24 = (uint *)(iVar15 + 0xb8);
    iVar3 = 0x18;
    do {
      iVar10 = FUN_00105594(iVar15,iVar19);
      if (param_2 == *(int *)(iVar10 + 0x158)) {
        puVar23 = (uint *)param_1[7];
        uVar2 = *(uint *)(iVar10 + 0x150);
        if (uVar2 < *puVar23) {
          uVar22 = puVar23[1];
          if (uVar22 <= uVar2) {
            _memset((void *)(uVar22 * 4 + puVar23[2]),0,(uVar2 - uVar22) * 4 + 4);
            puVar23[1] = uVar2 + 1;
          }
          piVar8 = (int *)(uVar2 * 4 + puVar23[2]);
        }
        else {
          piVar8 = (int *)FUN_0019423c(puVar23,uVar2);
        }
        if (*(int *)(*piVar8 + 0x14) == 0) {
          if (((*puVar24 & 2) != 0) && (*(int *)(*(int *)(iVar10 + 0x88) + 8) == 0x13)) {
            iVar4 = 1;
            iVar13 = iVar10 + 0x98;
            do {
              FUN_00103d50(iVar13 + 0xc,2,1);
              if ((*(uint *)(iVar13 + 0x20) & 1) != 0) {
                FUN_00103d50(iVar13 + 0xc,1,0);
              }
              bVar1 = iVar4 != 2;
              iVar13 = iVar13 + 0x18;
              iVar4 = iVar4 + 1;
            } while (bVar1);
            FUN_00103d50(iVar3 + iVar15 + 0x8c,2,0);
          }
          uVar2 = *(uint *)(iVar3 + iVar15 + 0xa0);
          if ((((uVar2 & 1) != 0) && ((uVar2 & 2) == 0)) &&
             (*(int *)(*(int *)(iVar10 + 0x88) + 8) == 0x12)) {
            iVar4 = 1;
            iVar13 = iVar10 + 0x98;
            do {
              FUN_00103d50(iVar13 + 0xc,1,*(uint *)(iVar13 + 0x20) & 1 ^ 1);
              bVar1 = iVar4 != 2;
              iVar13 = iVar13 + 0x18;
              iVar4 = iVar4 + 1;
            } while (bVar1);
            FUN_00103d50(iVar3 + iVar15 + 0x8c,1,0);
          }
          uVar2 = puVar5[2];
          if (uVar2 < *puVar16) {
            _memset((void *)(uVar2 * 4 + puVar5[3]),0,4);
            piVar8 = (int *)(uVar2 * 4 + puVar5[3]);
            puVar5[2] = uVar2 + 1;
          }
          else {
            piVar8 = (int *)FUN_0019423c(puVar16,uVar2);
          }
          *piVar8 = iVar10;
        }
      }
      bVar1 = iVar19 != 2;
      iVar3 = iVar3 + 0x18;
      puVar24 = puVar24 + 6;
      iVar19 = iVar19 + 1;
    } while (bVar1);
    iVar3 = FUN_001054ec(iVar15,1);
    iVar3 = FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
    if (iVar3 != 0) {
      iVar3 = FUN_001054ec(iVar15,2);
      FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
    }
    iVar3 = FUN_001054ec(iVar15,1);
    iVar3 = FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
    if (iVar3 == 0) {
      iVar3 = FUN_001054ec(iVar15,2);
      iVar3 = FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
      if (iVar3 != 0) {
        uVar2 = puVar6[2];
        if (uVar2 < *puVar18) {
          _memset((void *)(uVar2 * 4 + puVar6[3]),0,4);
          piVar8 = (int *)(uVar2 * 4 + puVar6[3]);
          puVar6[2] = uVar2 + 1;
        }
        else {
          piVar8 = (int *)FUN_0019423c(puVar18,uVar2);
        }
        *piVar8 = iVar15;
        uVar2 = puVar7[2];
        if (uVar2 < *puVar17) {
          _memset((void *)(uVar2 * 4 + puVar7[3]),0,4);
          puVar11 = (undefined4 *)(uVar2 * 4 + puVar7[3]);
          puVar7[2] = uVar2 + 1;
        }
        else {
          puVar11 = (undefined4 *)FUN_0019423c(puVar17,uVar2);
        }
        *puVar11 = 2;
      }
    }
    else {
      uVar2 = puVar6[2];
      if (uVar2 < *puVar18) {
        _memset((void *)(uVar2 * 4 + puVar6[3]),0,4);
        piVar8 = (int *)(uVar2 * 4 + puVar6[3]);
        puVar6[2] = uVar2 + 1;
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar2);
      }
      *piVar8 = iVar15;
      uVar2 = puVar7[2];
      if (uVar2 < *puVar17) {
        _memset((void *)(uVar2 * 4 + puVar7[3]),0,4);
        puVar11 = (undefined4 *)(uVar2 * 4 + puVar7[3]);
        puVar7[2] = uVar2 + 1;
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar17,uVar2);
      }
      *puVar11 = 1;
    }
  }
  iVar3 = *(int *)(*(int *)(param_3 + 0x88) + 8);
  if ((iVar3 == 0x13) || (iVar3 == 0x14)) {
    local_5c = 0x13;
  }
  else {
    local_5c = 0x12;
    if (iVar3 != 0x12) {
      local_5c = 0;
    }
  }
  FUN_001940a8(auStack_88);
  iVar3 = puVar6[2];
  uVar22 = iVar3 - 1;
  uVar2 = uVar22;
  if ((int)uVar22 < 1) {
    iVar15 = 0;
  }
  else {
    iVar19 = uVar22 * 4;
    iVar4 = iVar19 + -4;
    iVar15 = 0;
    iVar10 = iVar3;
    do {
      iVar13 = FUN_001043f0(local_5c,*param_1);
      uVar21 = DAT_001b0210;
      *(undefined4 *)(iVar13 + 0x94) = *(undefined4 *)(iVar13 + 0x14c);
      uVar14 = uVar2 - 1;
      *(undefined4 *)(iVar13 + 0x98) = 0;
      *(undefined4 *)(iVar13 + 0x9c) = uVar21;
      uVar26 = *puVar18;
      if (uVar14 < uVar26) {
        uVar9 = puVar6[2];
        if (uVar9 <= uVar14) {
          _memset((void *)(uVar9 * 4 + puVar6[3]),0,(uVar14 - uVar9) * 4 + 4);
          uVar26 = *puVar18;
          puVar6[2] = uVar2;
        }
        piVar8 = (int *)(iVar4 + puVar6[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar14);
        uVar26 = *puVar18;
      }
      if (param_3 != *piVar8) {
        if (uVar14 < uVar26) {
          uVar9 = puVar6[2];
          if (uVar9 <= uVar14) {
            _memset((void *)(uVar9 * 4 + puVar6[3]),0,(uVar14 - uVar9) * 4 + 4);
            uVar26 = *puVar18;
            puVar6[2] = uVar2;
          }
          piVar8 = (int *)(iVar4 + puVar6[3]);
        }
        else {
          piVar8 = (int *)FUN_0019423c(puVar18,uVar14);
          uVar26 = *puVar18;
        }
        iVar15 = iVar15 + *(int *)(*piVar8 + 0x124);
      }
      if (uVar2 < uVar26) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar2 - uVar26) * 4 + 4);
          puVar6[2] = iVar10;
        }
        piVar8 = (int *)(iVar19 + puVar6[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar2);
      }
      if (param_3 != *piVar8) {
        if (uVar2 < *puVar18) {
          uVar26 = puVar6[2];
          if (uVar26 <= uVar2) {
            _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar2 - uVar26) * 4 + 4);
            puVar6[2] = iVar10;
          }
          piVar8 = (int *)(iVar19 + puVar6[3]);
        }
        else {
          piVar8 = (int *)FUN_0019423c(puVar18,uVar2);
        }
        iVar15 = iVar15 + *(int *)(*piVar8 + 0x124);
      }
      if (iVar15 != 0) {
        iVar20 = *(int *)(*(int *)(*param_1 + 0x30c) + 0x58);
        if (iVar15 < iVar20) {
          *(int *)(iVar13 + 0x124) = iVar20;
          iVar15 = iVar15 - *(int *)(*(int *)(*param_1 + 0x30c) + 0x58);
        }
        else {
          iVar20 = *(int *)(*(int *)(*param_1 + 0x30c) + 0x5c);
          if (iVar20 < iVar15) {
            *(int *)(iVar13 + 0x124) = iVar20;
            iVar15 = iVar15 - *(int *)(*(int *)(*param_1 + 0x30c) + 0x5c);
          }
          else {
            *(int *)(iVar13 + 0x124) = iVar15;
            iVar15 = 0;
          }
        }
      }
      if (uVar14 < *puVar18) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar6[2] = uVar2;
        }
        puVar11 = (undefined4 *)(iVar4 + puVar6[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar18,uVar14);
      }
      uVar21 = *puVar11;
      if (uVar14 < *puVar17) {
        uVar26 = puVar7[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar7[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar7[2] = uVar2;
        }
        puVar11 = (undefined4 *)(iVar4 + puVar7[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar17,uVar14);
      }
      uVar21 = FUN_00105594(uVar21,*puVar11);
      FUN_00106004(iVar13,1,uVar21,0,*param_1);
      if (uVar2 < *puVar18) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar2 - uVar26) * 4 + 4);
          puVar6[2] = iVar10;
        }
        puVar11 = (undefined4 *)(iVar19 + puVar6[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar18,uVar2);
      }
      uVar21 = *puVar11;
      if (uVar2 < *puVar17) {
        uVar26 = puVar7[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar7[3]),0,(uVar2 - uVar26) * 4 + 4);
          puVar7[2] = iVar10;
        }
        puVar11 = (undefined4 *)(iVar19 + puVar7[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar17,uVar2);
      }
      uVar21 = FUN_00105594(uVar21,*puVar11);
      FUN_00106004(iVar13,2,uVar21,0,*param_1);
      if (uVar14 < *puVar18) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar6[2] = uVar2;
        }
        puVar11 = (undefined4 *)(iVar4 + puVar6[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar18,uVar14);
      }
      uVar21 = *puVar11;
      if (uVar14 < *puVar17) {
        uVar26 = puVar7[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar7[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar7[2] = uVar2;
        }
        puVar11 = (undefined4 *)(iVar4 + puVar7[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar17,uVar14);
      }
      iVar20 = FUN_001054ec(uVar21,*puVar11);
      FUN_000f33f8(&local_68,*(undefined4 *)(iVar20 + 0x10));
      uVar26 = local_68 & 0xff;
      if (uVar2 < *puVar18) {
        uVar9 = puVar6[2];
        if (uVar9 <= uVar2) {
          _memset((void *)(uVar9 * 4 + puVar6[3]),0,(uVar2 - uVar9) * 4 + 4);
          puVar6[2] = iVar10;
        }
        puVar11 = (undefined4 *)(iVar19 + puVar6[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar18,uVar2);
      }
      uVar21 = *puVar11;
      if (uVar2 < *puVar17) {
        uVar9 = puVar7[2];
        if (uVar9 <= uVar2) {
          _memset((void *)(uVar9 * 4 + puVar7[3]),0,(uVar2 - uVar9) * 4 + 4);
          puVar7[2] = iVar10;
        }
        puVar11 = (undefined4 *)(iVar19 + puVar7[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar17,uVar2);
      }
      iVar20 = FUN_001054ec(uVar21,*puVar11);
      FUN_000f33f8(&local_64,*(undefined4 *)(iVar20 + 0x10));
      uVar9 = local_64 & 0xff;
      iVar20 = FUN_001054ec(iVar13,1);
      *(uint *)(iVar20 + 0x10) = uVar26 | 0x4040400;
      iVar20 = FUN_001054ec(iVar13,2);
      *(uint *)(iVar20 + 0x10) = uVar9 | 0x4040400;
      if (uVar14 < *puVar18) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar6[2] = uVar2;
        }
        piVar8 = (int *)(iVar4 + puVar6[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar14);
      }
      iVar20 = *piVar8;
      if (uVar14 < *puVar17) {
        uVar26 = puVar7[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar7[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar7[2] = uVar2;
        }
        piVar8 = (int *)(iVar4 + puVar7[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar17,uVar14);
      }
      FUN_00103d50(iVar13 + 0xa4,1,*(uint *)(*piVar8 * 0x18 + iVar20 + 0xa0) & 1);
      if (uVar2 < *puVar18) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar2 - uVar26) * 4 + 4);
          puVar6[2] = iVar10;
        }
        piVar8 = (int *)(iVar19 + puVar6[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar2);
      }
      iVar20 = *piVar8;
      if (uVar2 < *puVar17) {
        uVar26 = puVar7[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar7[3]),0,(uVar2 - uVar26) * 4 + 4);
          puVar7[2] = iVar10;
        }
        piVar8 = (int *)(iVar19 + puVar7[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar17,uVar2);
      }
      FUN_00103d50(iVar13 + 0xbc,1,*(uint *)(*piVar8 * 0x18 + iVar20 + 0xa0) & 1);
      if (uVar14 < *puVar18) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar6[2] = uVar2;
        }
        piVar8 = (int *)(iVar4 + puVar6[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar14);
      }
      iVar20 = *piVar8;
      if (uVar14 < *puVar17) {
        uVar26 = puVar7[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar7[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar7[2] = uVar2;
        }
        piVar8 = (int *)(iVar4 + puVar7[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar17,uVar14);
      }
      FUN_00103d50(iVar13 + 0xa4,2,*(uint *)(*piVar8 * 0x18 + iVar20 + 0xa0) >> 1 & 1);
      if (uVar2 < *puVar18) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar2 - uVar26) * 4 + 4);
          puVar6[2] = iVar10;
        }
        piVar8 = (int *)(iVar19 + puVar6[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar2);
      }
      iVar20 = *piVar8;
      if (uVar2 < *puVar17) {
        uVar26 = puVar7[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar7[3]),0,(uVar2 - uVar26) * 4 + 4);
          puVar7[2] = iVar10;
        }
        piVar8 = (int *)(iVar19 + puVar7[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar17,uVar2);
      }
      FUN_00103d50(iVar13 + 0xbc,2,*(uint *)(*piVar8 * 0x18 + iVar20 + 0xa0) >> 1 & 1);
      *(undefined4 *)(iVar13 + 0x150) = *(undefined4 *)(param_1[7] + 4);
      uVar21 = *(undefined4 *)(*param_1 + 0x378);
      puVar11 = (undefined4 *)FUN_00193e18(uVar21,0x1c);
      *puVar11 = uVar21;
      puVar24 = (uint *)param_1[7];
      uVar26 = puVar24[1];
      if (uVar26 < *puVar24) {
        _memset((void *)(uVar26 * 4 + puVar24[2]),0,4);
        piVar8 = (int *)(uVar26 * 4 + puVar24[2]);
        puVar24[1] = uVar26 + 1;
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar24,uVar26);
      }
      *piVar8 = (int)(puVar11 + 1);
      FUN_00193f64(auStack_88,iVar13);
      uVar2 = uVar2 - 2;
      iVar19 = iVar19 + -8;
      iVar4 = iVar4 + -8;
      iVar10 = iVar10 + -2;
    } while (0 < (int)uVar2);
  }
  iVar19 = local_80;
  if (uVar2 == 0) {
    iVar10 = FUN_001043f0(local_5c,*param_1);
    uVar21 = DAT_001b0210;
    *(undefined4 *)(iVar10 + 0x98) = 0;
    *(undefined4 *)(iVar10 + 0x94) = *(undefined4 *)(iVar10 + 0x14c);
    *(undefined4 *)(iVar10 + 0x9c) = uVar21;
    if (*puVar18 == 0) {
      piVar8 = (int *)FUN_0019423c(puVar18,0);
    }
    else {
      if (puVar6[2] == 0) {
        *(undefined4 *)puVar6[3] = 0;
        puVar6[2] = 1;
      }
      piVar8 = (int *)puVar6[3];
    }
    if (param_3 != *piVar8) {
      if (*puVar18 == 0) {
        piVar8 = (int *)FUN_0019423c(puVar18,0);
      }
      else {
        if (puVar6[2] == 0) {
          *(undefined4 *)puVar6[3] = 0;
          puVar6[2] = 1;
        }
        piVar8 = (int *)puVar6[3];
      }
      iVar15 = iVar15 + *(int *)(*piVar8 + 0x124);
    }
    if (iVar15 == 0) {
      iVar4 = *param_1;
      iVar15 = 0;
    }
    else {
      iVar4 = *(int *)(*(int *)(*param_1 + 0x30c) + 0x58);
      if (iVar15 < iVar4) {
        *(int *)(iVar10 + 0x124) = iVar4;
        iVar4 = *param_1;
        iVar15 = iVar15 - *(int *)(*(int *)(iVar4 + 0x30c) + 0x58);
      }
      else {
        iVar4 = *(int *)(*(int *)(*param_1 + 0x30c) + 0x5c);
        if (iVar4 < iVar15) {
          *(int *)(iVar10 + 0x124) = iVar4;
          iVar4 = *param_1;
          iVar15 = iVar15 - *(int *)(*(int *)(iVar4 + 0x30c) + 0x5c);
        }
        else {
          *(int *)(iVar10 + 0x124) = iVar15;
          iVar15 = 0;
          iVar4 = *param_1;
        }
      }
    }
    FUN_00106004(iVar10,1,iVar19,0,iVar4);
    uVar21 = DAT_001b020c;
    iVar4 = FUN_001054ec(iVar10,1);
    *(undefined4 *)(iVar4 + 0x10) = uVar21;
    if (*puVar18 == 0) {
      puVar11 = (undefined4 *)FUN_0019423c(puVar18,0);
    }
    else {
      if (puVar6[2] == 0) {
        *(undefined4 *)puVar6[3] = 0;
        puVar6[2] = 1;
      }
      puVar11 = (undefined4 *)puVar6[3];
    }
    uVar21 = *puVar11;
    if (*puVar17 == 0) {
      puVar11 = (undefined4 *)FUN_0019423c(puVar17,0);
    }
    else {
      if (puVar7[2] == 0) {
        *(undefined4 *)puVar7[3] = 0;
        puVar7[2] = 1;
      }
      puVar11 = (undefined4 *)puVar7[3];
    }
    uVar21 = FUN_00105594(uVar21,*puVar11);
    FUN_00106004(iVar10,2,uVar21,0,*param_1);
    if (*puVar18 == 0) {
      puVar11 = (undefined4 *)FUN_0019423c(puVar18,0);
    }
    else {
      if (puVar6[2] == 0) {
        *(undefined4 *)puVar6[3] = 0;
        puVar6[2] = 1;
      }
      puVar11 = (undefined4 *)puVar6[3];
    }
    uVar21 = *puVar11;
    if (*puVar17 == 0) {
      puVar11 = (undefined4 *)FUN_0019423c(puVar17,0);
    }
    else {
      if (puVar7[2] == 0) {
        *(undefined4 *)puVar7[3] = 0;
        puVar7[2] = 1;
      }
      puVar11 = (undefined4 *)puVar7[3];
    }
    iVar4 = FUN_001054ec(uVar21,*puVar11);
    FUN_000f33f8(&local_60,*(undefined4 *)(iVar4 + 0x10));
    iVar4 = FUN_001054ec(iVar10,2);
    *(uint *)(iVar4 + 0x10) = local_60 & 0xff | 0x4040400;
    if (*puVar18 == 0) {
      piVar8 = (int *)FUN_0019423c(puVar18,0);
    }
    else {
      if (puVar6[2] == 0) {
        *(undefined4 *)puVar6[3] = 0;
        puVar6[2] = 1;
      }
      piVar8 = (int *)puVar6[3];
    }
    iVar4 = *piVar8;
    if (*puVar17 == 0) {
      piVar8 = (int *)FUN_0019423c(puVar17,0);
    }
    else {
      if (puVar7[2] == 0) {
        *(undefined4 *)puVar7[3] = 0;
        puVar7[2] = 1;
      }
      piVar8 = (int *)puVar7[3];
    }
    FUN_00103d50(iVar10 + 0xbc,1,*(uint *)(*piVar8 * 0x18 + iVar4 + 0xa0) & 1);
    if (*puVar18 == 0) {
      piVar8 = (int *)FUN_0019423c(puVar18,0);
    }
    else {
      if (puVar6[2] == 0) {
        *(undefined4 *)puVar6[3] = 0;
        puVar6[2] = 1;
      }
      piVar8 = (int *)puVar6[3];
    }
    iVar4 = *piVar8;
    if (*puVar17 == 0) {
      piVar8 = (int *)FUN_0019423c(puVar17,0);
    }
    else {
      if (puVar7[2] == 0) {
        *(undefined4 *)puVar7[3] = 0;
        puVar7[2] = 1;
      }
      piVar8 = (int *)puVar7[3];
    }
    FUN_00103d50(iVar10 + 0xbc,2,*(uint *)(*piVar8 * 0x18 + iVar4 + 0xa0) >> 1 & 1);
    FUN_00193f64(auStack_88,iVar10);
    *(undefined4 *)(iVar10 + 0x150) = *(undefined4 *)(param_1[7] + 4);
    uVar21 = *(undefined4 *)(*param_1 + 0x378);
    puVar11 = (undefined4 *)FUN_00193e18(uVar21,0x1c);
    *puVar11 = uVar21;
    puVar24 = (uint *)param_1[7];
    uVar2 = puVar24[1];
    if (uVar2 < *puVar24) {
      _memset((void *)(uVar2 * 4 + puVar24[2]),0,4);
      piVar8 = (int *)(uVar2 * 4 + puVar24[2]);
      puVar24[1] = uVar2 + 1;
    }
    else {
      piVar8 = (int *)FUN_0019423c(puVar24,uVar2);
    }
    *piVar8 = (int)(puVar11 + 1);
    iVar19 = *(int *)(iVar19 + 8);
  }
  while (iVar10 = *(int *)(iVar19 + 8), *(int *)(iVar10 + 8) != 0) {
    iVar4 = FUN_001043f0(local_5c,*param_1);
    uVar21 = DAT_001b0210;
    *(undefined4 *)(iVar4 + 0x98) = 0;
    *(undefined4 *)(iVar4 + 0x94) = *(undefined4 *)(iVar4 + 0x14c);
    *(undefined4 *)(iVar4 + 0x9c) = uVar21;
    if (iVar15 == 0) {
      iVar13 = *param_1;
    }
    else {
      iVar13 = *(int *)(*(int *)(*param_1 + 0x30c) + 0x58);
      if (iVar15 < iVar13) {
        *(int *)(iVar4 + 0x124) = iVar13;
        iVar13 = *param_1;
        iVar15 = iVar15 - *(int *)(*(int *)(iVar13 + 0x30c) + 0x58);
      }
      else {
        iVar13 = *(int *)(*(int *)(*param_1 + 0x30c) + 0x5c);
        if (iVar13 < iVar15) {
          *(int *)(iVar4 + 0x124) = iVar13;
          iVar13 = *param_1;
          iVar15 = iVar15 - *(int *)(*(int *)(iVar13 + 0x30c) + 0x5c);
        }
        else {
          *(int *)(iVar4 + 0x124) = iVar15;
          iVar15 = 0;
          iVar13 = *param_1;
        }
      }
    }
    FUN_00106004(iVar4,1,iVar19,0,iVar13);
    FUN_00106004(iVar4,2,iVar10,0,*param_1);
    uVar21 = DAT_001b020c;
    iVar19 = FUN_001054ec(iVar4,1);
    *(undefined4 *)(iVar19 + 0x10) = uVar21;
    iVar19 = FUN_001054ec(iVar4,2);
    *(undefined4 *)(iVar19 + 0x10) = uVar21;
    FUN_00193f64(auStack_88,iVar4);
    *(undefined4 *)(iVar4 + 0x150) = *(undefined4 *)(param_1[7] + 4);
    uVar21 = *(undefined4 *)(*param_1 + 0x378);
    puVar11 = (undefined4 *)FUN_00193e18(uVar21,0x1c);
    *puVar11 = uVar21;
    puVar24 = (uint *)param_1[7];
    uVar2 = puVar24[1];
    if (uVar2 < *puVar24) {
      _memset((void *)(uVar2 * 4 + puVar24[2]),0,4);
      piVar8 = (int *)(uVar2 * 4 + puVar24[2]);
      puVar24[1] = uVar2 + 1;
    }
    else {
      piVar8 = (int *)FUN_0019423c(puVar24,uVar2);
    }
    *piVar8 = (int)(puVar11 + 1);
    iVar19 = *(int *)(iVar10 + 8);
  }
  if (-1 < (int)uVar22) {
    iVar19 = uVar22 * 4;
    iVar10 = 0;
    iVar15 = iVar3;
    do {
      uVar2 = *puVar18;
      uVar26 = uVar22 - iVar10;
      if (uVar26 < uVar2) {
        uVar14 = puVar6[2];
        if (uVar14 <= uVar26) {
          _memset((void *)(uVar14 * 4 + puVar6[3]),0,(uVar26 - uVar14) * 4 + 4);
          uVar2 = *puVar18;
          puVar6[2] = iVar15;
        }
        piVar8 = (int *)(iVar19 + puVar6[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar26);
        uVar2 = *puVar18;
      }
      if (param_3 == *piVar8) goto LAB_001836f0;
      if (uVar26 < uVar2) {
        uVar2 = puVar6[2];
        if (uVar2 <= uVar26) {
          _memset((void *)(uVar2 * 4 + puVar6[3]),0,(uVar26 - uVar2) * 4 + 4);
          puVar6[2] = iVar15;
        }
        puVar11 = (undefined4 *)(iVar19 + puVar6[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar18,uVar26);
      }
      piVar8 = (int *)*puVar11;
      if (uVar26 < *puVar17) {
        uVar2 = puVar7[2];
        if (uVar2 <= uVar26) {
          _memset((void *)(uVar2 * 4 + puVar7[3]),0,(uVar26 - uVar2) * 4 + 4);
          puVar7[2] = iVar15;
        }
        piVar12 = (int *)(iVar19 + puVar7[3]);
      }
      else {
        piVar12 = (int *)FUN_0019423c(puVar17,uVar26);
      }
      iVar4 = (*piVar12 == 1) + 1;
      FUN_0010497c(piVar8,param_1[1]);
      puVar24 = (uint *)param_1[7];
      uVar2 = piVar8[0x54];
      if (uVar2 < *puVar24) {
        uVar26 = puVar24[1];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar24[2]),0,(uVar2 - uVar26) * 4 + 4);
          puVar24[1] = uVar2 + 1;
        }
        piVar12 = (int *)(uVar2 * 4 + puVar24[2]);
      }
      else {
        piVar12 = (int *)FUN_0019423c(puVar24,uVar2);
      }
      iVar25 = *(int *)(*piVar12 + 0x10);
      iVar20 = *(int *)(*piVar12 + 0xc);
      uVar21 = FUN_00105594(piVar8,iVar4);
      FUN_00106004(iVar20,iVar25,uVar21,0,*param_1);
      iVar13 = FUN_001054ec(piVar8,iVar4);
      uVar21 = *(undefined4 *)(iVar13 + 0x10);
      iVar13 = FUN_001054ec(iVar20,iVar25);
      *(undefined4 *)(iVar13 + 0x10) = uVar21;
      if ((*(uint *)(iVar25 * 0x18 + iVar20 + 0xa0) & 1) == 0) {
        uVar2 = piVar8[iVar4 * 6 + 0x28] & 1;
      }
      else {
        uVar2 = piVar8[iVar4 * 6 + 0x28] & 1U ^ 1;
      }
      iVar13 = iVar25 * 0x18 + iVar20 + 0x8c;
      FUN_00103d50(iVar13,1,uVar2);
      FUN_00103d50(iVar13,2,(uint)piVar8[iVar4 * 6 + 0x28] >> 1 & 1);
      (**(code **)(*piVar8 + 0xc))(piVar8,0,*param_1);
      iVar10 = iVar10 + 1;
      iVar19 = iVar19 + -4;
      iVar15 = iVar15 + -1;
    } while (iVar10 != iVar3);
  }
  uVar2 = *puVar18;
LAB_001836f0:
  if (uVar2 == 0) {
    piVar8 = (int *)FUN_0019423c(puVar18,0);
  }
  else {
    if (puVar6[2] == 0) {
      *(undefined4 *)puVar6[3] = 0;
      puVar6[2] = 1;
    }
    piVar8 = (int *)puVar6[3];
  }
  if (param_3 == *piVar8) {
    iVar19 = *(int *)(local_80 + 8);
    iVar3 = local_80;
    while (iVar15 = iVar19, iVar15 != 0) {
      FUN_0019401c(iVar3);
      FUN_000e7700(param_2,param_3,iVar3);
      iVar3 = iVar15;
      iVar19 = *(int *)(iVar15 + 8);
    }
    if (*puVar17 == 0) {
      piVar8 = (int *)FUN_0019423c(puVar17,0);
    }
    else {
      if (puVar7[2] == 0) {
        *(undefined4 *)puVar7[3] = 0;
        puVar7[2] = 1;
      }
      piVar8 = (int *)puVar7[3];
    }
    iVar19 = *piVar8;
    FUN_00106004(param_3,iVar19,*(undefined4 *)(param_3 + 4),0,*param_1);
    uVar21 = DAT_001b020c;
    iVar3 = FUN_001054ec(param_3,iVar19);
    *(undefined4 *)(iVar3 + 0x10) = uVar21;
    iVar3 = iVar19 * 0x18 + param_3 + 0x8c;
    FUN_00103d50(iVar3,1,0);
    FUN_00103d50(iVar3,2,0);
  }
  else {
    iVar3 = FUN_001043f0(local_5c,*param_1);
    *(undefined4 *)(iVar3 + 0x98) = 0;
    *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(iVar3 + 0x14c);
    iVar19 = FUN_001054ec(param_3,0);
    *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(iVar19 + 0x10);
    uVar21 = FUN_00105594(param_3,1);
    FUN_00106004(iVar3,1,uVar21,0,*param_1);
    uVar21 = FUN_00105594(param_3,2);
    FUN_00106004(iVar3,2,uVar21,0,*param_1);
    iVar19 = FUN_001054ec(param_3,1);
    uVar21 = *(undefined4 *)(iVar19 + 0x10);
    iVar19 = FUN_001054ec(iVar3,1);
    *(undefined4 *)(iVar19 + 0x10) = uVar21;
    iVar19 = FUN_001054ec(param_3,2);
    uVar21 = *(undefined4 *)(iVar19 + 0x10);
    iVar19 = FUN_001054ec(iVar3,2);
    uVar2 = *(uint *)(param_3 + 0xb8);
    *(undefined4 *)(iVar19 + 0x10) = uVar21;
    FUN_00103d50(iVar3 + 0xa4,1,uVar2 & 1);
    FUN_00103d50(iVar3 + 0xbc,1,*(uint *)(param_3 + 0xd0) & 1);
    FUN_00103d50(iVar3 + 0xa4,2,*(uint *)(param_3 + 0xb8) >> 1 & 1);
    FUN_00103d50(iVar3 + 0xbc,2,*(uint *)(param_3 + 0xd0) >> 1 & 1);
    FUN_000e7700(param_2,param_3,iVar3);
    FUN_00106004(param_3,1,iVar3,0,*param_1);
    uVar21 = DAT_001b0208;
    iVar3 = FUN_001054ec(param_3,1);
    *(undefined4 *)(iVar3 + 0x10) = uVar21;
    FUN_00103d50(param_3 + 0xa4,1,0);
    FUN_00103d50(param_3 + 0xa4,2,0);
    iVar3 = *(int *)(local_80 + 8);
    while (iVar19 = iVar3, iVar19 != 0) {
      FUN_0019401c(local_80);
      FUN_000e7700(param_2,param_3,local_80);
      local_80 = iVar19;
      iVar3 = *(int *)(iVar19 + 8);
    }
    FUN_00106004(param_3,2,*(undefined4 *)(param_3 + 4),0,*param_1);
    uVar21 = DAT_001b020c;
    iVar3 = FUN_001054ec(param_3,2);
    *(undefined4 *)(iVar3 + 0x10) = uVar21;
    FUN_00103d50(param_3 + 0xbc,1,0);
    FUN_00103d50(param_3 + 0xbc,2,0);
    FUN_000f35c4(param_3);
  }
  if (puVar17 != (uint *)0x0) {
    FUN_00193cc0(puVar7[4],puVar7[3]);
    FUN_00193cc0(*puVar7,puVar7);
  }
  if (puVar18 != (uint *)0x0) {
    FUN_00193cc0(puVar6[4],puVar6[3]);
    FUN_00193cc0(*puVar6,puVar6);
  }
  if (puVar16 != (uint *)0x0) {
    FUN_00193cc0(puVar5[4],puVar5[3]);
    FUN_00193cc0(*puVar5,puVar5);
  }
  return 1;
}

/* FUN_00183ac8 @ 0x183ac8 (212 bytes) */
int FUN_00183ac8(param_1)
  int param_1;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  
  uVar5 = 0;
  puVar6 = *(uint **)(param_1 + 0x1c);
  uVar4 = puVar6[1];
  if (0 < (int)uVar4) {
    while( true ) {
      if (uVar5 < *puVar6) {
        uVar1 = puVar6[1];
        if (uVar1 <= uVar5) {
          _memset((void *)(uVar1 * 4 + puVar6[2]),0,(uVar5 - uVar1) * 4 + 4);
          puVar6[1] = uVar5 + 1;
        }
        piVar2 = (int *)(uVar5 * 4 + puVar6[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar6,uVar5);
      }
      uVar5 = uVar5 + 1;
      iVar3 = *piVar2;
      if (iVar3 != 0) {
        FUN_00193cc0(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
      }
      if (uVar4 == uVar5) break;
      puVar6 = *(uint **)(param_1 + 0x1c);
    }
    puVar6 = *(uint **)(param_1 + 0x1c);
  }
  puVar6[1] = 0;
  return;
}

/* FUN_00183b9c @ 0x183b9c (1152 bytes) */
int FUN_00183b9c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  int local_48;
  int local_44 [8];
  
  ((int (*)())FUN_00181ab0)();
LAB_00183bcc:
  ((int (*)())FUN_00181b80)(param_1,param_2,&local_48,local_44);
  if ((local_48 < local_44[0]) &&
     (iVar1 = *(int *)(param_1 + 8),
     *(int *)(iVar1 + 0x14) < *(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 0x10))) {
    iVar1 = *(int *)(*(int *)(param_2 + 0x98) + 8);
    iVar7 = *(int *)(param_2 + 0x98);
    if (iVar1 != 0) {
      do {
        iVar4 = iVar1;
        if ((*(uint *)(iVar7 + 0x14) & 1) != 0) {
          iVar5 = *(int *)(iVar7 + 0x88);
          iVar1 = *(int *)(iVar5 + 8);
          if ((iVar1 == 0x13) || (iVar1 == 0x14)) {
            iVar6 = 0x13;
          }
          else {
            iVar6 = 0x12;
            if (iVar1 != 0x12) goto LAB_00183fe8;
          }
          puVar9 = *(uint **)(param_1 + 0x1c);
          uVar8 = *(uint *)(iVar7 + 0x150);
          if (uVar8 < *puVar9) {
            uVar2 = puVar9[1];
            if (uVar2 <= uVar8) {
              _memset((void *)(uVar2 * 4 + puVar9[2]),0,(uVar8 - uVar2) * 4 + 4);
              puVar9[1] = uVar8 + 1;
              iVar5 = *(int *)(iVar7 + 0x88);
            }
            piVar3 = (int *)(uVar8 * 4 + puVar9[2]);
          }
          else {
            piVar3 = (int *)FUN_0019423c(puVar9,uVar8);
            iVar5 = *(int *)(iVar7 + 0x88);
          }
          iVar1 = *piVar3;
          if ((((((iVar6 == *(int *)(iVar5 + 8)) && (*(int *)(iVar7 + 0x120) == 0)) &&
                ((*(uint *)(iVar7 + 0x14) & 0x200) == 0)) &&
               (((iVar6 != 0x12 || (*(int *)(iVar7 + 0x124) == 0)) &&
                ((iVar4 = FUN_001054ec(iVar7,0), *(int *)(iVar4 + 0x10) != DAT_001b021c &&
                 ((iVar4 = FUN_001054ec(iVar7,0), *(int *)(iVar4 + 0x10) != DAT_001b0218 &&
                  (iVar4 = FUN_001054ec(iVar7,0), *(int *)(iVar4 + 0x10) != DAT_001b0214)))))))) &&
              (iVar4 = FUN_001054ec(iVar7,0), *(int *)(iVar4 + 0x10) != DAT_001b0210)) &&
             ((((iVar4 = FUN_0010497c(iVar7,*(undefined4 *)(param_1 + 4)), iVar4 != 0 &&
                (iVar4 = *(int *)(iVar1 + 0xc), iVar4 != 0)) &&
               (iVar6 == *(int *)(*(int *)(iVar4 + 0x88) + 8))) &&
              ((iVar4 = FUN_000f31e8(iVar4,*(undefined4 *)(iVar1 + 0x10)), iVar4 != 0 &&
               ((iVar6 != 0x12 ||
                ((*(uint *)(*(int *)(iVar1 + 0x10) * 0x18 + *(int *)(iVar1 + 0xc) + 0xa0) & 2) == 0)
                ))))))) {
            *(undefined4 *)(iVar1 + 0x14) = 0;
          }
          iVar4 = FUN_00105594(iVar7,1);
          iVar5 = FUN_00105594(iVar7,2);
          iVar6 = FUN_001054ec(iVar7,1);
          iVar6 = FUN_000f2c5c(*(undefined4 *)(iVar6 + 0x10));
          if (iVar6 == 0) {
LAB_00183e40:
            iVar6 = FUN_001054ec(iVar7,1);
            iVar6 = FUN_000f2c5c(*(undefined4 *)(iVar6 + 0x10));
            if (iVar6 == 0) {
              iVar6 = FUN_001054ec(iVar7,2);
              iVar6 = FUN_000f2c5c(*(undefined4 *)(iVar6 + 0x10));
              if (iVar6 != 0) goto LAB_00183e78;
            }
          }
          else {
            iVar6 = FUN_001054ec(iVar7,2);
            iVar6 = FUN_000f2c5c(*(undefined4 *)(iVar6 + 0x10));
            if (iVar6 != 0) goto LAB_00183e40;
LAB_00183e78:
            *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
          }
          if (param_2 == *(int *)(iVar4 + 0x158)) {
            puVar9 = *(uint **)(param_1 + 0x1c);
            uVar8 = *(uint *)(iVar4 + 0x150);
            if (uVar8 < *puVar9) {
              uVar2 = puVar9[1];
              if (uVar2 <= uVar8) {
                _memset((void *)(uVar2 * 4 + puVar9[2]),0,(uVar8 - uVar2) * 4 + 4);
                puVar9[1] = uVar8 + 1;
              }
              piVar3 = (int *)(uVar8 * 4 + puVar9[2]);
            }
            else {
              piVar3 = (int *)FUN_0019423c(puVar9,uVar8);
            }
            iVar4 = *piVar3;
            if ((iVar4 != 0) && (*(int *)(iVar4 + 0x14) == 0)) {
              *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + *(int *)(iVar4 + 8);
            }
          }
          if (param_2 == *(int *)(iVar5 + 0x158)) {
            puVar9 = *(uint **)(param_1 + 0x1c);
            uVar8 = *(uint *)(iVar5 + 0x150);
            if (uVar8 < *puVar9) {
              uVar2 = puVar9[1];
              if (uVar2 <= uVar8) {
                _memset((void *)(uVar2 * 4 + puVar9[2]),0,(uVar8 - uVar2) * 4 + 4);
                puVar9[1] = uVar8 + 1;
              }
              piVar3 = (int *)(uVar8 * 4 + puVar9[2]);
            }
            else {
              piVar3 = (int *)FUN_0019423c(puVar9,uVar8);
            }
            iVar4 = *piVar3;
            if ((iVar4 != 0) && (*(int *)(iVar4 + 0x14) == 0)) {
              *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + *(int *)(iVar4 + 8);
            }
          }
          if (((*(int *)(iVar1 + 0x14) != 0) && (1 < *(int *)(iVar1 + 8))) &&
             (iVar1 = ((int (*)())FUN_00181f00)(param_1,param_2,iVar7), iVar1 != 0)) goto LAB_00183bcc;
          iVar4 = *(int *)(iVar7 + 8);
        }
LAB_00183fe8:
        iVar1 = *(int *)(iVar4 + 8);
        iVar7 = iVar4;
        if (*(int *)(iVar4 + 8) == 0) break;
      } while( true );
    }
  }
  ((int (*)())FUN_00183ac8)(param_1);
  return;
}

/* FUN_0018401c @ 0x18401c (256 bytes) */
int FUN_0018401c(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  param_1[1] = param_2;
  *param_1 = *(int *)(param_2 + 8);
  iVar2 = FUN_0010ddcc();
  param_1[2] = iVar2;
  uVar4 = *(undefined4 *)(*param_1 + 0x378);
  puVar3 = (undefined4 *)FUN_00193e18(uVar4,0x14);
  puVar3[1] = 2;
  *puVar3 = uVar4;
  puVar3[2] = 0;
  puVar3[4] = uVar4;
  uVar4 = FUN_00193e18(uVar4,8);
  puVar3[3] = uVar4;
  param_1[7] = (int)(puVar3 + 1);
  iVar2 = *(int *)(param_1[1] + 900);
  iVar1 = *(int *)(iVar2 + 8);
  while (iVar1 != 0) {
    iVar1 = FUN_00194034(iVar2 + 0x90);
    if (2 < iVar1) {
      ((int (*)())FUN_00183b9c)(param_1,iVar2);
    }
    iVar2 = *(int *)(iVar2 + 8);
    iVar1 = *(int *)(iVar2 + 8);
  }
  iVar2 = param_1[7];
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  FUN_000ed7e4(param_2,"height_reduction");
  return;
}

/* FUN_0018413c @ 0x18413c (2336 bytes) */
int FUN_0018413c(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int *param_4;
{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  int *piVar11;
  undefined4 uVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  
  uVar12 = *(undefined4 *)(*param_1 + 0x378);
  puVar2 = (undefined4 *)FUN_00193e18(uVar12,0x14);
  puVar8 = puVar2 + 1;
  *puVar2 = uVar12;
  puVar2[1] = 2;
  puVar2[4] = uVar12;
  puVar2[2] = 0;
  uVar12 = FUN_00193e18(uVar12,8);
  puVar2[3] = uVar12;
  uVar12 = *(undefined4 *)(*param_1 + 0x378);
  puVar3 = (undefined4 *)FUN_00193e18(uVar12,0x14);
  puVar10 = puVar3 + 1;
  *puVar3 = uVar12;
  puVar3[1] = 2;
  puVar3[4] = uVar12;
  puVar3[2] = 0;
  uVar12 = FUN_00193e18(uVar12,8);
  puVar3[3] = uVar12;
  uVar12 = *(undefined4 *)(*param_1 + 0x378);
  puVar4 = (undefined4 *)FUN_00193e18(uVar12,0x14);
  puVar9 = puVar4 + 1;
  *puVar4 = uVar12;
  puVar4[1] = 2;
  puVar4[2] = 0;
  puVar4[4] = uVar12;
  uVar12 = FUN_00193e18(uVar12,8);
  uVar15 = puVar2[2];
  uVar1 = *puVar8;
  puVar4[3] = uVar12;
  if (uVar15 < uVar1) {
    _memset((void *)(uVar15 * 4 + puVar2[3]),0,4);
    puVar5 = (undefined4 *)(uVar15 * 4 + puVar2[3]);
    puVar2[2] = uVar15 + 1;
  }
  else {
    puVar5 = (undefined4 *)FUN_0019423c(puVar8,uVar15);
  }
  *puVar5 = param_4;
  uVar1 = puVar3[2];
  if (uVar1 < *puVar10) {
    _memset((void *)(uVar1 * 4 + puVar3[3]),0,4);
    puVar5 = (undefined4 *)(uVar1 * 4 + puVar3[3]);
    puVar3[2] = uVar1 + 1;
    goto LAB_00184480;
  }
LAB_00184474:
  puVar5 = (undefined4 *)FUN_0019423c(puVar10,uVar1);
LAB_00184480:
  *puVar5 = 1;
  do {
    uVar1 = puVar2[2];
    if (uVar1 == 0) {
      if (*puVar8 == 0) {
        puVar5 = (undefined4 *)FUN_0019423c(puVar8,0);
      }
      else {
        _memset((void *)puVar2[3],0,4);
        puVar5 = (undefined4 *)puVar2[3];
        puVar2[2] = 1;
      }
      *puVar5 = param_4;
      uVar1 = puVar3[2];
      if (uVar1 < *puVar10) {
        _memset((void *)(uVar1 * 4 + puVar3[3]),0,4);
        puVar5 = (undefined4 *)(uVar1 * 4 + puVar3[3]);
        puVar3[2] = uVar1 + 1;
      }
      else {
        puVar5 = (undefined4 *)FUN_0019423c(puVar10,uVar1);
      }
      *puVar5 = 1;
      while (uVar1 = puVar2[2], uVar1 != 0) {
        puVar5 = (undefined4 *)0x0;
        if (uVar1 - 1 < uVar1) {
          puVar5 = (undefined4 *)((uVar1 - 1) * 4 + puVar2[3]);
        }
        piVar11 = (int *)*puVar5;
        iVar6 = ((int (*)())FUN_00181928)(piVar11,param_3,param_2);
        if ((iVar6 == 0) && (param_4 != piVar11)) {
          FUN_00194208(puVar8,puVar2[2] + -1);
          FUN_00194208(puVar10,puVar3[2] + -1);
        }
        else {
          piVar14 = (int *)0x0;
          uVar1 = puVar3[2] - 1;
          if (uVar1 < (uint)puVar3[2]) {
            piVar14 = (int *)(uVar1 * 4 + puVar3[3]);
          }
          iVar13 = *piVar14;
          iVar6 = (**(code **)(*piVar11 + 0x14))(piVar11);
          if (iVar6 < iVar13) {
            FUN_00194208(puVar8,puVar2[2] + -1);
            FUN_00194208(puVar10,puVar3[2] + -1);
            if (param_4 != piVar11) {
              FUN_0019401c(piVar11);
              FUN_000e7700(param_3,param_4,piVar11);
            }
          }
          else {
            uVar1 = (**(code **)(*piVar11 + 0x14))(piVar11);
            if (0 < (int)uVar1) {
              iVar6 = 1;
              do {
                uVar12 = FUN_00105594(piVar11,iVar6);
                uVar15 = puVar4[2];
                if (uVar15 < *puVar9) {
                  _memset((void *)(uVar15 * 4 + puVar4[3]),0,4);
                  puVar5 = (undefined4 *)(uVar15 * 4 + puVar4[3]);
                  puVar4[2] = uVar15 + 1;
                }
                else {
                  puVar5 = (undefined4 *)FUN_0019423c(puVar9,uVar15);
                }
                iVar6 = iVar6 + 1;
                *puVar5 = uVar12;
              } while (iVar6 <= (int)uVar1);
            }
            FUN_001940f0(puVar9,FUN_001819b4);
            FUN_00194208(puVar10,puVar3[2] + -1);
            uVar15 = puVar3[2];
            if (uVar15 < *puVar10) {
              _memset((void *)(uVar15 * 4 + puVar3[3]),0,4);
              piVar11 = (int *)(uVar15 * 4 + puVar3[3]);
              puVar3[2] = uVar15 + 1;
            }
            else {
              piVar11 = (int *)FUN_0019423c(puVar10,uVar15);
            }
            *piVar11 = uVar1 + 1;
            if (0 < (int)uVar1) {
              uVar15 = 0;
              do {
                if (uVar15 < *puVar9) {
                  uVar7 = puVar4[2];
                  if (uVar7 <= uVar15) {
                    _memset((void *)(uVar7 * 4 + puVar4[3]),0,(uVar15 - uVar7) * 4 + 4);
                    puVar4[2] = uVar15 + 1;
                  }
                  puVar5 = (undefined4 *)(uVar15 * 4 + puVar4[3]);
                }
                else {
                  puVar5 = (undefined4 *)FUN_0019423c(puVar9,uVar15);
                }
                uVar15 = uVar15 + 1;
                uVar7 = puVar2[2];
                uVar12 = *puVar5;
                if (uVar7 < *puVar8) {
                  _memset((void *)(uVar7 * 4 + puVar2[3]),0,4);
                  puVar5 = (undefined4 *)(uVar7 * 4 + puVar2[3]);
                  puVar2[2] = uVar7 + 1;
                }
                else {
                  puVar5 = (undefined4 *)FUN_0019423c(puVar8,uVar7);
                }
                *puVar5 = uVar12;
                uVar7 = puVar3[2];
                if (uVar7 < *puVar10) {
                  _memset((void *)(uVar7 * 4 + puVar3[3]),0,4);
                  puVar5 = (undefined4 *)(uVar7 * 4 + puVar3[3]);
                  puVar3[2] = uVar7 + 1;
                }
                else {
                  puVar5 = (undefined4 *)FUN_0019423c(puVar10,uVar7);
                }
                *puVar5 = 1;
              } while (uVar1 != uVar15);
            }
            puVar4[2] = 0;
          }
        }
      }
      if (puVar9 != (uint *)0x0) {
        FUN_00193cc0(puVar4[4],puVar4[3]);
        FUN_00193cc0(*puVar4,puVar4);
      }
      if (puVar10 != (uint *)0x0) {
        FUN_00193cc0(puVar3[4],puVar3[3]);
        FUN_00193cc0(*puVar3,puVar3);
      }
      if (puVar8 == (uint *)0x0) {
        return;
      }
      FUN_00193cc0(puVar2[4],puVar2[3]);
      FUN_00193cc0(*puVar2,puVar2);
      return;
    }
    puVar5 = (undefined4 *)0x0;
    if (uVar1 - 1 < uVar1) {
      puVar5 = (undefined4 *)((uVar1 - 1) * 4 + puVar2[3]);
    }
    piVar14 = (int *)*puVar5;
    uVar1 = puVar3[2] - 1;
    piVar11 = (int *)0x0;
    if (uVar1 < (uint)puVar3[2]) {
      piVar11 = (int *)(uVar1 * 4 + puVar3[3]);
    }
    iVar13 = *piVar11;
    iVar6 = ((int (*)())FUN_00181928)(piVar14,param_3,param_2);
    if ((iVar6 == 0) && (param_4 != piVar14)) {
      piVar14[0x54] = 0;
    }
    else {
      iVar6 = (**(code **)(*piVar14 + 0x14))(piVar14);
      if (iVar13 <= iVar6) break;
      uVar1 = (**(code **)(*piVar14 + 0x14))(piVar14);
      if (0 < (int)uVar1) {
        iVar6 = 1;
        do {
          uVar12 = FUN_00105594(piVar14,iVar6);
          uVar15 = puVar4[2];
          if (uVar15 < *puVar9) {
            _memset((void *)(uVar15 * 4 + puVar4[3]),0,4);
            puVar5 = (undefined4 *)(uVar15 * 4 + puVar4[3]);
            puVar4[2] = uVar15 + 1;
          }
          else {
            puVar5 = (undefined4 *)FUN_0019423c(puVar9,uVar15);
          }
          iVar6 = iVar6 + 1;
          *puVar5 = uVar12;
        } while (iVar6 <= (int)uVar1);
      }
      FUN_001940f0(puVar9,FUN_001819b4);
      if (0 < (int)uVar1) {
        uVar15 = 0;
        iVar6 = 0;
        do {
          if (uVar15 < *puVar9) {
            uVar7 = puVar4[2];
            if (uVar7 <= uVar15) {
              _memset((void *)(uVar7 * 4 + puVar4[3]),0,(uVar15 - uVar7) * 4 + 4);
              puVar4[2] = uVar15 + 1;
            }
            puVar5 = (undefined4 *)(uVar15 * 4 + puVar4[3]);
          }
          else {
            puVar5 = (undefined4 *)FUN_0019423c(puVar9,uVar15);
          }
          uVar15 = uVar15 + 1;
          piVar11 = (int *)*puVar5;
          if ((((piVar11[0x20] == 0) || (iVar13 = FUN_00126760(piVar11[0x26]), iVar13 == 0)) ||
              ((piVar11[5] & 2U) != 0)) ||
             (iVar13 = (**(code **)(*piVar11 + 0x50))(piVar11), iVar13 != 0)) {
            iVar13 = 0;
          }
          else {
            iVar13 = FUN_000f3a30(piVar11);
          }
          iVar6 = iVar6 + iVar13;
          if (iVar6 <= piVar11[0x54]) {
            iVar6 = piVar11[0x54];
          }
        } while (uVar1 != uVar15);
      }
      else {
        iVar6 = 0;
      }
      puVar4[2] = 0;
      piVar14[0x54] = iVar6;
    }
    FUN_00194208(puVar8,puVar2[2] + -1);
    FUN_00194208(puVar10,puVar3[2] + -1);
  } while( true );
  uVar12 = FUN_00105594(piVar14,iVar13);
  uVar1 = puVar2[2];
  if (uVar1 < *puVar8) {
    _memset((void *)(uVar1 * 4 + puVar2[3]),0,4);
    puVar5 = (undefined4 *)(uVar1 * 4 + puVar2[3]);
    puVar2[2] = uVar1 + 1;
  }
  else {
    puVar5 = (undefined4 *)FUN_0019423c(puVar8,uVar1);
  }
  *puVar5 = uVar12;
  FUN_00194208(puVar10,puVar3[2] + -1);
  uVar1 = puVar3[2];
  if (uVar1 < *puVar10) {
    _memset((void *)(uVar1 * 4 + puVar3[3]),0,4);
    piVar11 = (int *)(uVar1 * 4 + puVar3[3]);
    puVar3[2] = uVar1 + 1;
  }
  else {
    piVar11 = (int *)FUN_0019423c(puVar10,uVar1);
  }
  *piVar11 = iVar13 + 1;
  uVar1 = puVar3[2];
  if (*puVar10 <= uVar1) goto LAB_00184474;
  _memset((void *)(uVar1 * 4 + puVar3[3]),0,4);
  puVar5 = (undefined4 *)(uVar1 * 4 + puVar3[3]);
  puVar3[2] = uVar1 + 1;
  goto LAB_00184480;
}

/* FUN_00184ab4 @ 0x184ab4 (280 bytes) */
int FUN_00184ab4(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  iVar1 = *(int *)(param_2 + 900);
  for (iVar2 = *(int *)(*(int *)(param_2 + 900) + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    piVar3 = (int *)(*(int **)(iVar1 + 0xa0))[1];
    piVar5 = *(int **)(iVar1 + 0xa0);
    if (piVar3 != (int *)0x0) {
      do {
        piVar4 = piVar3;
        iVar2 = (**(code **)(*piVar5 + 0x34))(piVar5);
        if ((((iVar2 == 0) && (iVar2 = (**(code **)(*piVar5 + 0x38))(piVar5), iVar2 == 0)) &&
            (iVar2 = (**(code **)(*piVar5 + 0x14))(piVar5), 0 < iVar2)) &&
           (iVar2 = ((int (*)())FUN_00181928)(piVar5,iVar1,param_2), iVar2 == 0)) {
          ((int (*)())FUN_0018413c)(param_1,param_2,iVar1,piVar5);
        }
        piVar3 = (int *)piVar4[1];
        piVar5 = piVar4;
      } while (piVar3 != (int *)0x0);
      iVar2 = *(int *)(iVar1 + 8);
    }
    iVar1 = iVar2;
  }
  FUN_000ed7e4(param_2,"minreg_order");
  return;
}

/* FUN_00184bf0 @ 0x184bf0 (232 bytes) */
int FUN_00184bf0(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  
  puVar8 = *(uint **)(param_1 + 0x10);
  uVar1 = puVar8[1];
  uVar7 = uVar1 - 1;
  if (-1 < (int)uVar7) {
    iVar6 = uVar7 * 4;
    uVar5 = 0;
    while( true ) {
      if (uVar7 < *puVar8) {
        uVar2 = puVar8[1];
        if (uVar2 <= uVar7) {
          _memset((void *)(uVar2 * 4 + puVar8[2]),0,(uVar7 - uVar2) * 4 + 4);
          puVar8[1] = uVar7 + 1;
        }
        puVar3 = (undefined4 *)(iVar6 + puVar8[2]);
      }
      else {
        puVar3 = (undefined4 *)FUN_0019423c(puVar8,uVar7);
      }
      iVar4 = (**(code **)(*(int *)*puVar3 + 0x24))();
      if (iVar4 == 0) {
        return 0;
      }
      uVar5 = uVar5 + 1;
      uVar7 = uVar7 - 1;
      iVar6 = iVar6 + -4;
      if (uVar1 == uVar5) break;
      puVar8 = *(uint **)(param_1 + 0x10);
    }
  }
  return 1;
}

/* FUN_00184cd8 @ 0x184cd8 (164 bytes) */
int FUN_00184cd8(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*param_1 + 0x24))();
  if (((iVar1 == 0) ||
      (piVar2 = *(int **)(*(int *)(param_3 + 8) + 0x30c),
      iVar1 = (**(code **)(*piVar2 + 0xfc))(piVar2,param_1[0x49] + -1,param_1), iVar1 == 0)) ||
     ((iVar1 = *(int *)(param_1[0x22] + 8), iVar1 != 0x13 && ((iVar1 != 0x1c && (iVar1 != 0x1d))))))
  {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_00184d7c @ 0x184d7c (372 bytes) */
int FUN_00184d7c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x13) {
    puVar5 = *(uint **)(param_1 + 0x10);
    uVar1 = puVar5[1];
    if (0 < (int)uVar1) {
      uVar4 = 0;
      do {
        if (uVar4 < *puVar5) {
          if (uVar1 <= uVar4) {
            _memset((void *)(uVar1 * 4 + puVar5[2]),0,(uVar4 - uVar1) * 4 + 4);
            puVar5[1] = uVar4 + 1;
          }
          puVar2 = (undefined4 *)(uVar4 * 4 + puVar5[2]);
        }
        else {
          puVar2 = (undefined4 *)FUN_0019423c(puVar5,uVar4);
        }
        iVar3 = FUN_001470dc(*puVar2,param_2,0);
        if (iVar3 == 0) {
          return;
        }
        puVar5 = *(uint **)(param_1 + 0x10);
        uVar4 = uVar4 + 1;
        uVar1 = puVar5[1];
      } while ((int)uVar4 < (int)uVar1);
    }
    uVar1 = puVar5[1];
    if (0 < (int)uVar1) {
      uVar4 = 0;
      do {
        if (uVar4 < *puVar5) {
          if (uVar1 <= uVar4) {
            _memset((void *)(uVar1 * 4 + puVar5[2]),0,(uVar4 - uVar1) * 4 + 4);
            puVar5[1] = uVar4 + 1;
          }
          puVar2 = (undefined4 *)(uVar4 * 4 + puVar5[2]);
        }
        else {
          puVar2 = (undefined4 *)FUN_0019423c(puVar5,uVar4);
        }
        uVar4 = uVar4 + 1;
        FUN_0014b82c(*puVar2,param_2,1,0);
        puVar5 = *(uint **)(param_1 + 0x10);
        uVar1 = puVar5[1];
      } while ((int)uVar4 < (int)uVar1);
    }
  }
  return;
}

/* FUN_00184ef0 @ 0x184ef0 (2760 bytes) */
int FUN_00184ef0(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  int param_3;
{
  float fVar1;
  float fVar2;
  uint uVar3;
  float *pfVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int *piVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  uint *puVar20;
  uint *puVar21;
  int iVar22;
  double dVar23;
  undefined1 auStack_f8 [4];
  float local_f4 [4];
  float local_e4;
  float local_e0;
  undefined4 local_c8;
  uint uStack_c4;
  undefined4 local_c0;
  uint uStack_bc;
  undefined4 local_b8;
  uint uStack_b4;
  undefined4 local_b0;
  uint uStack_ac;
  undefined4 local_a8;
  uint uStack_a4;
  undefined4 local_a0;
  uint uStack_9c;
  undefined4 local_98;
  uint uStack_94;
  undefined4 local_90;
  uint uStack_8c;
  undefined4 local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  
  iVar5 = (**(code **)(*param_1 + 0x24))();
  if ((((iVar5 == 0) ||
       (piVar6 = *(int **)(*(int *)(param_3 + 8) + 0x30c),
       iVar5 = (**(code **)(*piVar6 + 0xfc))(piVar6,param_2 + param_1[0x49],0), iVar5 == 0)) ||
      ((param_1[5] & 0x200U) != 0)) ||
     ((param_1[0x48] != 0 || (iVar5 = (**(code **)(*param_1 + 0x5c))(param_1), iVar5 != 0)))) {
LAB_00185098:
    uVar9 = 0;
  }
  else {
    FUN_001940f0(param_1[4],((unsigned char *)0x00184bcc));
    puVar20 = (uint *)param_1[4];
    uVar7 = puVar20[1];
    if (0 < (int)uVar7) {
      uVar19 = 0;
      do {
        if (uVar19 < *puVar20) {
          if (uVar7 <= uVar19) {
            _memset((void *)(uVar7 * 4 + puVar20[2]),0,(uVar19 - uVar7) * 4 + 4);
            puVar20[1] = uVar19 + 1;
          }
          puVar8 = (undefined4 *)(uVar19 * 4 + puVar20[2]);
        }
        else {
          puVar8 = (undefined4 *)FUN_0019423c(puVar20,uVar19);
        }
        piVar6 = (int *)*puVar8;
        if ((((piVar6[5] & 0x200U) != 0) ||
            (iVar5 = (**(code **)(*piVar6 + 0x28))(piVar6), iVar5 != 0)) ||
           (iVar5 = (**(code **)(*piVar6 + 0x5c))(piVar6), iVar5 != 0)) goto LAB_00185098;
        iVar5 = *(int *)(piVar6[0x22] + 8);
        if (iVar5 == 0x31) {
LAB_001850bc:
          if ((((piVar6[0x21] != 2) || (piVar10 = (int *)FUN_00105594(piVar6,1), param_1 != piVar10)
               ) || (piVar10 = (int *)FUN_00105594(piVar6,2), param_1 != piVar10)) ||
             (piVar10 = *(int **)(*(int *)(param_3 + 8) + 0x30c),
             iVar5 = (**(code **)(*piVar10 + 0xfc))(piVar10,piVar6[0x49] + param_2 * -2,0),
             iVar5 == 0)) {
LAB_001851b4:
            piVar10 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
            iVar5 = (**(code **)(*piVar10 + 0xfc))(piVar10,piVar6[0x49] - param_2,0);
            goto joined_r0x001851e0;
          }
        }
        else {
          if (0x31 < iVar5) {
            if ((iVar5 == 0x36) || (iVar5 == 0x66)) goto LAB_001850bc;
            if (iVar5 == 0x34) {
LAB_00185124:
              piVar10 = (int *)FUN_00105594(piVar6,1);
              if ((param_1 != piVar10) ||
                 (piVar10 = (int *)FUN_00105594(piVar6,2), param_1 != piVar10)) {
                if ((int)param_2 < 0) {
                  uStack_c4 = 1 << (-param_2 & 0x3f) ^ 0x80000000;
                  local_c8 = 0x43300000;
                  fVar2 = (float)((double)CONCAT44(0x43300000,uStack_c4) - DOUBLE_001aa1e0);
                }
                else {
                  local_c0 = 0x43300000;
                  uStack_bc = 1 << (param_2 & 0x3f) ^ 0x80000000;
                  fVar2 = FLOAT_001aa0e8 /
                          (float)((double)CONCAT44(0x43300000,uStack_bc) - DOUBLE_001aa1e0);
                }
                iVar5 = 4;
                pfVar4 = local_f4;
                do {
                  *pfVar4 = NAN;
                  pfVar4 = pfVar4 + 1;
                  iVar5 = iVar5 + -1;
                } while (iVar5 != 0);
                iVar5 = 0;
                iVar22 = 4;
                do {
                  *(float *)(iVar5 + (int)local_f4) = fVar2;
                  iVar5 = iVar5 + 4;
                  iVar22 = iVar22 + -1;
                } while (iVar22 != 0);
                goto LAB_0018533c;
              }
              goto LAB_001851b4;
            }
            goto LAB_00185098;
          }
          if (iVar5 == 0x13) goto LAB_001850bc;
          if (iVar5 != 0x14) {
            if (iVar5 == 0x12) goto LAB_00185124;
            goto LAB_00185098;
          }
          iVar5 = FUN_001054ec(piVar6,0);
          iVar5 = FUN_000f5cf0(piVar6,2,*(undefined4 *)(iVar5 + 0x10),&local_e4);
          fVar2 = local_e0;
          if (((iVar5 == 0) || (local_e4 != 2.8026e-45)) ||
             (piVar6 = (int *)FUN_00105594(piVar6,1), param_1 != piVar6)) goto LAB_00185098;
          if ((int)param_2 < 0) {
            uStack_b4 = 1 << (-param_2 & 0x3f) ^ 0x80000000;
            local_b8 = 0x43300000;
            fVar1 = (float)((double)CONCAT44(0x43300000,uStack_b4) - DOUBLE_001aa1e0);
          }
          else {
            local_b0 = 0x43300000;
            uStack_ac = 1 << (param_2 & 0x3f) ^ 0x80000000;
            fVar1 = FLOAT_001aa0e8 /
                    (float)((double)CONCAT44(0x43300000,uStack_ac) - DOUBLE_001aa1e0);
          }
          pfVar4 = local_f4;
          do {
            *pfVar4 = NAN;
            pfVar4 = pfVar4 + 1;
          } while (&local_e4 != pfVar4);
          iVar5 = 0;
          iVar22 = 4;
          do {
            *(float *)(iVar5 + (int)local_f4) = fVar2 * fVar1;
            iVar5 = iVar5 + 4;
            iVar22 = iVar22 + -1;
          } while (iVar22 != 0);
LAB_0018533c:
          piVar6 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
          iVar5 = (**(code **)(*piVar6 + 0xe8))(piVar6,local_f4,auStack_f8,DAT_001b0220);
joined_r0x001851e0:
          if (iVar5 == 0) goto LAB_00185098;
        }
        puVar20 = (uint *)param_1[4];
        uVar19 = uVar19 + 1;
        uVar7 = puVar20[1];
      } while ((int)uVar19 < (int)uVar7);
    }
    uVar7 = uVar7 - 1;
    if (-1 < (int)uVar7) {
      local_70 = param_2 << 1;
      do {
        if (0 < (int)uVar7) {
          uVar19 = uVar7 - 1;
          if (uVar19 < *puVar20) {
            uVar3 = puVar20[1];
            puVar21 = puVar20;
            if (uVar3 <= uVar19) {
              _memset((void *)(uVar3 * 4 + puVar20[2]),0,(uVar19 - uVar3) * 4 + 4);
              puVar20[1] = uVar7;
              puVar21 = (uint *)param_1[4];
            }
            piVar6 = (int *)(uVar19 * 4 + puVar20[2]);
          }
          else {
            piVar6 = (int *)FUN_0019423c(puVar20,uVar19);
            puVar21 = (uint *)param_1[4];
          }
          iVar5 = *piVar6;
          if (uVar7 < *puVar21) {
            uVar19 = puVar21[1];
            if (uVar19 <= uVar7) {
              _memset((void *)(uVar19 * 4 + puVar21[2]),0,(uVar7 - uVar19) * 4 + 4);
              puVar21[1] = uVar7 + 1;
            }
            piVar6 = (int *)(uVar7 * 4 + puVar21[2]);
          }
          else {
            piVar6 = (int *)FUN_0019423c(puVar21,uVar7);
          }
          if (iVar5 != *piVar6) {
            puVar20 = (uint *)param_1[4];
            goto LAB_0018545c;
          }
          goto LAB_00185964;
        }
LAB_0018545c:
        if (uVar7 < *puVar20) {
          uVar19 = puVar20[1];
          if (uVar19 <= uVar7) {
            _memset((void *)(uVar19 * 4 + puVar20[2]),0,(uVar7 - uVar19) * 4 + 4);
            puVar20[1] = uVar7 + 1;
          }
          puVar8 = (undefined4 *)(uVar7 * 4 + puVar20[2]);
        }
        else {
          puVar8 = (undefined4 *)FUN_0019423c(puVar20,uVar7);
        }
        piVar6 = (int *)*puVar8;
        iVar5 = *(int *)(piVar6[0x22] + 8);
        if (iVar5 == 0x31) {
LAB_0018550c:
          if ((piVar6[0x21] == 2) &&
             ((piVar10 = (int *)FUN_00105594(piVar6,1), param_1 == piVar10 &&
              (piVar10 = (int *)FUN_00105594(piVar6,2), param_1 == piVar10)))) {
            piVar6[0x49] = piVar6[0x49] - local_70;
          }
          else {
LAB_00185628:
            piVar6[0x49] = piVar6[0x49] - param_2;
          }
        }
        else {
          if (iVar5 < 0x32) {
            if (iVar5 != 0x13) {
              if (iVar5 == 0x14) {
                iVar5 = FUN_001054ec(piVar6,0);
                FUN_000f5cf0(piVar6,2,*(undefined4 *)(iVar5 + 0x10),&local_e4);
                if ((int)param_2 < 0) {
                  uStack_94 = 1 << (-param_2 & 0x3f) ^ 0x80000000;
                  local_98 = 0x43300000;
                  fVar2 = (float)((double)CONCAT44(0x43300000,uStack_94) - DOUBLE_001aa1e0);
                }
                else {
                  local_90 = 0x43300000;
                  uStack_8c = 1 << (param_2 & 0x3f) ^ 0x80000000;
                  fVar2 = FLOAT_001aa0e8 /
                          (float)((double)CONCAT44(0x43300000,uStack_8c) - DOUBLE_001aa1e0);
                }
                dVar23 = (double)(local_e0 * fVar2);
                FUN_00103d50(piVar6 + 0x2f,1,0);
                FUN_00103d50(piVar6 + 0x2f,2,0);
                FUN_000f79c4(dVar23,dVar23,dVar23,dVar23,piVar6,param_3,2);
              }
              else if (iVar5 == 0x12) goto LAB_00185558;
              goto LAB_00185964;
            }
            goto LAB_0018550c;
          }
          if ((iVar5 == 0x36) || (iVar5 == 0x66)) goto LAB_0018550c;
          if (iVar5 == 0x34) {
LAB_00185558:
            piVar10 = (int *)FUN_00105594(piVar6,1);
            if ((param_1 != piVar10) ||
               (piVar10 = (int *)FUN_00105594(piVar6,2), param_1 != piVar10)) {
              if ((int)param_2 < 0) {
                uStack_a4 = 1 << (-param_2 & 0x3f) ^ 0x80000000;
                local_a8 = 0x43300000;
                fVar2 = (float)((double)CONCAT44(0x43300000,uStack_a4) - DOUBLE_001aa1e0);
              }
              else {
                local_a0 = 0x43300000;
                uStack_9c = 1 << (param_2 & 0x3f) ^ 0x80000000;
                fVar2 = FLOAT_001aa0e8 /
                        (float)((double)CONCAT44(0x43300000,uStack_9c) - DOUBLE_001aa1e0);
              }
              dVar23 = (double)fVar2;
              local_74 = piVar6[1];
              local_78 = piVar6[0x56];
              FUN_0019401c(piVar6);
              iVar5 = FUN_001054ec(piVar6,0);
              local_84 = *(int *)(iVar5 + 0x10);
              local_7c = piVar6[0x49];
              local_80 = piVar6[0x48];
              iVar5 = FUN_00104054(piVar6,param_3);
              iVar22 = piVar6[4];
              piVar10 = (int *)FUN_00105594(piVar6,1);
              if (param_1 == piVar10) {
                iVar18 = 1;
                iVar17 = 2;
              }
              else {
                FUN_00105594(piVar6,2);
                iVar18 = 2;
                iVar17 = 1;
              }
              iVar14 = piVar6[iVar18 * 6 + 0x26];
              iVar13 = piVar6[iVar18 * 6 + 0x25];
              iVar11 = FUN_001054ec(piVar6,iVar18);
              uVar19 = piVar6[iVar18 * 6 + 0x28];
              uVar16 = *(undefined4 *)(iVar11 + 0x10);
              uVar9 = FUN_00105594(piVar6,iVar18);
              iVar15 = piVar6[iVar17 * 6 + 0x26];
              iVar11 = piVar6[iVar17 * 6 + 0x25];
              iVar18 = FUN_001054ec(piVar6,iVar17);
              local_88 = *(undefined4 *)(iVar18 + 0x10);
              uVar3 = piVar6[iVar17 * 6 + 0x28];
              uVar12 = FUN_00105594(piVar6,iVar17);
              (**(code **)(*piVar6 + 0xc))(piVar6,1,*(undefined4 *)(param_3 + 8));
              FUN_00108304(piVar6,0x14,*(undefined4 *)(param_3 + 8));
              piVar6[4] = iVar22;
              piVar6[0x25] = piVar6[0x53];
              piVar6[0x26] = 0;
              piVar6[0x27] = local_84;
              piVar6[0x48] = local_80;
              piVar6[0x49] = local_7c;
              piVar6[0x58] = iVar5 + *(int *)(param_3 + 0x478);
              FUN_00106004(piVar6,1,uVar9,1,*(undefined4 *)(param_3 + 8));
              iVar5 = FUN_001054ec(piVar6,1);
              *(int *)(iVar5 + 0xc) = iVar14;
              *(int *)(iVar5 + 8) = iVar13;
              iVar5 = FUN_001054ec(piVar6,1);
              *(undefined4 *)(iVar5 + 0x10) = uVar16;
              FUN_00103d50(piVar6 + 0x29,2,uVar19 >> 1 & 1);
              FUN_00103d50(piVar6 + 0x29,1,uVar19 & 1);
              FUN_00106004(piVar6,3,uVar12,1,*(undefined4 *)(param_3 + 8));
              iVar5 = FUN_001054ec(piVar6,3);
              *(int *)(iVar5 + 0xc) = iVar15;
              *(int *)(iVar5 + 8) = iVar11;
              iVar5 = FUN_001054ec(piVar6,3);
              *(undefined4 *)(iVar5 + 0x10) = local_88;
              FUN_00103d50(piVar6 + 0x35,2,uVar3 >> 1 & 1);
              FUN_00103d50(piVar6 + 0x35,1,uVar3 & 1);
              FUN_000f79c4(dVar23,dVar23,dVar23,dVar23,piVar6,param_3,2);
              FUN_000e7738(local_78,local_74,piVar6);
              goto LAB_00185964;
            }
            goto LAB_00185628;
          }
        }
LAB_00185964:
        uVar7 = uVar7 - 1;
        if ((int)uVar7 < 0) break;
        puVar20 = (uint *)param_1[4];
      } while( true );
    }
    uVar9 = 1;
    param_1[0x49] = param_2 + param_1[0x49];
  }
  return uVar9;
}

/* FUN_001859bc @ 0x1859bc (996 bytes) */
int FUN_001859bc(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  undefined4 local_78;
  undefined4 local_74;
  uint local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  
  iVar3 = FUN_001054ec(param_1,1);
  uVar14 = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = FUN_001054ec(param_1,2);
  uVar13 = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = FUN_001054ec(param_1,0);
  uVar12 = *(undefined4 *)(iVar3 + 0x10);
  if (((*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x12) &&
      (iVar3 = FUN_000f2c5c(uVar14), iVar3 != 0)) && (iVar3 = FUN_000f2c5c(uVar13), iVar3 != 0)) {
    piVar4 = (int *)FUN_00105594(param_1,1);
    piVar5 = (int *)FUN_00105594(param_1,2);
    if (((*(int *)(piVar4[0x22] + 8) == 0x1c) && (iVar3 = FUN_0010497c(piVar4,param_2), iVar3 != 0))
       && (((*(uint *)(param_1 + 0xb8) & 1) == 0 && ((*(uint *)(param_1 + 0xb8) & 2) == 0)))) {
      iVar3 = FUN_00146788(piVar4,param_2);
      iVar9 = 2;
      if (iVar3 != 0) goto LAB_00185afc;
    }
    if (((*(int *)(piVar5[0x22] + 8) == 0x1c) && (iVar3 = FUN_0010497c(piVar5,param_2), iVar3 != 0))
       && (((*(uint *)(param_1 + 0xd0) & 1) == 0 &&
           (((*(uint *)(param_1 + 0xd0) & 2) == 0 &&
            (iVar3 = FUN_00146788(piVar5,param_2), iVar3 != 0)))))) {
      iVar9 = 1;
      piVar4 = piVar5;
      uVar13 = uVar14;
LAB_00185afc:
      local_74 = FUN_00105594(param_1,iVar9);
      uVar1 = *(uint *)(iVar9 * 0x18 + param_1 + 0xa0);
      iVar15 = 0;
      local_70 = uVar1 & 1;
      local_6c = uVar1 >> 1 & 1;
      iVar3 = FUN_001054ec(param_1,iVar9);
      local_60 = *(undefined4 *)(iVar3 + 0x10);
      uVar14 = FUN_00105594(piVar4,1);
      uVar1 = piVar4[0x2e];
      iVar3 = FUN_001054ec(piVar4,1);
      local_64 = *(undefined4 *)(iVar3 + 0x10);
      uVar6 = FUN_00105594(piVar4,2);
      uVar2 = piVar4[0x34];
      iVar3 = FUN_001054ec(piVar4,2);
      local_68 = *(undefined4 *)(iVar3 + 0x10);
      uVar7 = *(undefined4 *)(param_1 + 4);
      uVar8 = *(undefined4 *)(param_1 + 0x158);
      iVar3 = FUN_00104054(param_1,param_2);
      uVar10 = *(undefined4 *)(param_1 + 0x120);
      uVar11 = *(undefined4 *)(param_1 + 0x124);
      if ((*(uint *)(param_1 + 0x14) & 0x200) != 0) {
        iVar15 = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84));
      }
      FUN_0019401c(param_1);
      FUN_00108304(param_1,0xa3,param_3);
      *(undefined4 *)(param_1 + 0x98) = 0;
      *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x14c);
      *(undefined4 *)(param_1 + 0x9c) = uVar12;
      *(undefined4 *)(param_1 + 0x120) = uVar10;
      *(undefined4 *)(param_1 + 0x124) = uVar11;
      *(int *)(param_1 + 0x160) = iVar3 + *(int *)(param_2 + 0x478);
      if (iVar15 != 0) {
        FUN_00106804(param_1,iVar15,0,param_3);
      }
      FUN_000e7738(uVar8,uVar7,param_1);
      FUN_00106004(param_1,1,uVar14,0,*(undefined4 *)(param_2 + 8));
      FUN_00103d50(param_1 + 0xa4,1,uVar1 & 1);
      FUN_00103d50(param_1 + 0xa4,2,uVar1 >> 1 & 1);
      iVar3 = FUN_001054ec(param_1,1);
      *(undefined4 *)(iVar3 + 0x10) = local_64;
      FUN_00106004(param_1,2,uVar6,0,*(undefined4 *)(param_2 + 8));
      FUN_00103d50(param_1 + 0xbc,1,uVar2 & 1);
      FUN_00103d50(param_1 + 0xbc,2,uVar2 >> 1 & 1);
      iVar3 = FUN_001054ec(param_1,2);
      *(undefined4 *)(iVar3 + 0x10) = local_68;
      FUN_00106004(param_1,3,local_74,0,*(undefined4 *)(param_2 + 8));
      FUN_00103d50(param_1 + 0xd4,1,local_70);
      FUN_00103d50(param_1 + 0xd4,2,local_6c);
      iVar3 = FUN_001054ec(param_1,3);
      *(undefined4 *)(iVar3 + 0x10) = local_60;
      FUN_000f33f8(&local_78,uVar13);
      iVar3 = FUN_001054ec(param_1,3);
      *(undefined4 *)(iVar3 + 0x10) = local_78;
                    
                    
      (**(code **)(*piVar4 + 0xc))(piVar4,0,*(undefined4 *)(param_2 + 8));
      return;
    }
  }
  return;
}

/* FUN_00185da4 @ 0x185da4 (1900 bytes) */
int FUN_00185da4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
  int *param_5;
  int param_6;
  int param_7;
  int param_8;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  code *pcVar10;
  undefined4 *in_stack_00000038;
  int in_stack_0000003c;
  undefined4 local_68;
  int local_64 [3];
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  int local_4c [4];
  
  iVar3 = FUN_001054ec(param_5,1);
  uVar8 = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = FUN_001054ec(param_3,param_1);
  uVar7 = *(undefined4 *)(iVar3 + 0x10);
  FUN_000f2bdc(&local_58,uVar8,uVar7);
  local_68 = local_58;
  piVar4 = *(int **)(*(int *)(param_6 + 8) + 0x30c);
  iVar3 = (**(code **)(*piVar4 + 0x108))(piVar4,&local_68);
  if (iVar3 == 0) {
    *(int *)(param_6 + 0x20c) = *(int *)(param_6 + 0x20c) + 1;
    return 0;
  }
  if ((param_2 == 0) || ((param_3[param_1 * 6 + 0x28] & 2U) != 0)) {
LAB_00185ea8:
    if (param_7 == 0) goto LAB_00185f24;
  }
  else {
    if ((*(int *)(param_4[0x22] + 8) == 0x9a) && (param_4[0x2c] == param_4[0x32])) {
      FUN_0010ac38(param_4,1,2,*(undefined4 *)(param_6 + 8));
      param_2 = 0;
      goto LAB_00185ea8;
    }
    if (param_7 == 0) goto LAB_00185f24;
    iVar3 = (**(code **)(*param_3 + 0x60))(param_3);
    if (iVar3 != 0) {
      return 0;
    }
    FUN_00103d50(param_3 + param_1 * 6 + 0x23,1,param_3[param_1 * 6 + 0x28] & 1U ^ 1);
  }
  uVar8 = local_68;
  iVar3 = FUN_001054ec(param_3,param_1);
  *(undefined4 *)(iVar3 + 0x10) = uVar8;
  FUN_00106004(param_3,param_1,param_4,0,*(undefined4 *)(param_6 + 8));
LAB_00185f24:
  bVar2 = param_7 != 0;
  FUN_000f32cc(&local_54,local_68);
  param_4[0x27] = local_54;
  if ((param_8 != 0) && (iVar3 = FUN_0018da48(param_3,*(undefined4 *)(param_6 + 8)), iVar3 == 0)) {
    iVar3 = 0;
    for (iVar9 = 1; iVar5 = (**(code **)(*param_3 + 0x14))(param_3), iVar9 <= iVar5;
        iVar9 = iVar9 + 1) {
      iVar5 = FUN_000f3b10(param_3,iVar9);
      if (iVar5 != 0) {
        iVar5 = iVar3 + 1;
        iVar3 = iVar3 + 2;
        if (iVar9 != param_1) {
          iVar3 = iVar5;
        }
      }
      FUN_000f3b68(param_3,iVar9);
    }
    if (3 < iVar3) {
      for (iVar3 = 1; iVar9 = (**(code **)(*param_3 + 0x14))(param_3), iVar3 <= iVar9;
          iVar3 = iVar3 + 1) {
        if (param_1 == iVar3) {
          iVar9 = (**(code **)(*param_5 + 100))(param_5);
          if (iVar9 != 0) {
            piVar4 = (int *)FUN_00105594(param_5,1);
            goto LAB_0018601c;
          }
        }
        else {
          piVar4 = (int *)FUN_00105594(param_3,iVar3);
LAB_0018601c:
          iVar9 = FUN_001054ec(param_3,iVar3);
          local_64[0] = *(int *)(iVar9 + 0x10);
          iVar9 = FUN_000f2c5c(local_64[0]);
          if (iVar9 != 0) {
            iVar9 = FUN_0011379c(*(undefined4 *)(param_6 + 8),piVar4);
            if ((iVar9 == 0) || (iVar9 = FUN_0010497c(piVar4,param_6), iVar9 == 0)) {
              bVar1 = false;
            }
            else {
              iVar9 = FUN_000f2cac(local_64[0]);
              piVar4[0x27] = DAT_001b023c;
              for (iVar5 = 1; iVar6 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar5 <= iVar6;
                  iVar5 = iVar5 + 1) {
                pcVar10 = *(code **)(*piVar4 + 0x88);
                iVar6 = FUN_001054ec(piVar4,iVar5);
                (*pcVar10)(piVar4,iVar5,3,*(undefined1 *)(iVar9 + iVar6 + 0x10));
                (**(code **)(*piVar4 + 0x88))(piVar4,iVar5,iVar9,4);
              }
              iVar9 = 0;
              iVar5 = 4;
              do {
                if (*(char *)((int)local_64 + iVar9) != '\x04') {
                  *(undefined1 *)((int)local_64 + iVar9) = 3;
                }
                iVar6 = local_64[0];
                iVar9 = iVar9 + 1;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
              if (iVar3 == 0) {
                bVar1 = true;
                param_3[0x27] = local_64[0];
              }
              else {
                iVar9 = FUN_001054ec(param_3,iVar3);
                bVar1 = true;
                *(int *)(iVar9 + 0x10) = iVar6;
              }
            }
            iVar9 = FUN_001131c0(*(undefined4 *)(piVar4[0x22] + 8),*(undefined4 *)(param_6 + 8));
            if (iVar9 != 0) {
              iVar9 = FUN_0010497c(piVar4,param_6);
              if (iVar9 == 0) {
                *(undefined1 *)((int)piVar4 + 0x9f) = 0;
              }
              else {
                piVar4[0x27] = DAT_001b023c;
              }
              iVar9 = 0;
              iVar5 = 4;
              do {
                if (*(char *)((int)local_64 + iVar9) != '\x04') {
                  *(undefined1 *)((int)local_64 + iVar9) = 3;
                }
                iVar6 = local_64[0];
                iVar9 = iVar9 + 1;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
              if (iVar3 == 0) {
                param_3[0x27] = local_64[0];
              }
              else {
                iVar9 = FUN_001054ec(param_3,iVar3);
                *(int *)(iVar9 + 0x10) = iVar6;
              }
LAB_001861f8:
              if (iVar3 == param_1) {
                param_4[0x27] = DAT_001b023c;
                for (iVar3 = 1; iVar5 = (**(code **)(*param_4 + 0x14))(param_4),
                    iVar9 = DAT_001b0224, iVar3 <= iVar5; iVar3 = iVar3 + 1) {
                  if (iVar3 == 0) {
                    param_4[0x27] = DAT_001b0224;
                  }
                  else {
                    iVar5 = FUN_001054ec(param_4,iVar3);
                    *(int *)(iVar5 + 0x10) = iVar9;
                  }
                  (**(code **)(*param_4 + 0x88))(param_4,iVar3,3,3);
                }
              }
              break;
            }
            if (bVar1) goto LAB_001861f8;
          }
        }
      }
    }
  }
  iVar3 = FUN_0018da48(param_3,*(undefined4 *)(param_6 + 8));
  if ((iVar3 == 0) && (param_8 != 0)) {
    if (bVar2) {
      if (in_stack_0000003c == 0) {
        FUN_00106004(param_3,param_1,param_5,0,*(undefined4 *)(param_6 + 8));
      }
      else {
        FUN_00106004(param_3,param_1,in_stack_0000003c,0,*(undefined4 *)(param_6 + 8));
      }
      iVar3 = FUN_001054ec(param_3,param_1);
      *(undefined4 *)(iVar3 + 0x10) = uVar7;
      if ((param_2 != 0) && ((param_3[param_1 * 6 + 0x28] & 2U) == 0)) {
        FUN_00103d50(param_3 + param_1 * 6 + 0x23,1,param_3[param_1 * 6 + 0x28] & 1U ^ 1);
      }
    }
    if (in_stack_0000003c == 0) {
      param_5[0x54] = *(int *)(param_6 + 0x474) + -1;
    }
    else {
      *(int *)(in_stack_0000003c + 0x150) = *(int *)(param_6 + 0x474) + -1;
    }
    uVar7 = 0;
    *(int *)(param_6 + 0x208) = *(int *)(param_6 + 0x208) + 1;
  }
  else {
    if (bVar2) {
      *(int *)(param_6 + 0x200) = *(int *)(param_6 + 0x200) + 1;
      FUN_000e7700(param_3[0x56],param_3,param_4);
      param_4[0x58] = *(int *)(param_6 + 0x478) + 1;
    }
    uVar7 = DAT_001b0220;
    iVar3 = FUN_001054ec(param_4,0);
    FUN_000f3908(&local_50,*(undefined4 *)(iVar3 + 0x10));
    FUN_000f3340(local_4c,uVar7,local_50);
    if (0 < param_4[0x21]) {
      iVar3 = 1;
      do {
        if (bVar2) {
          iVar9 = FUN_00105594(param_4,iVar3);
          if (*(int *)(param_6 + 0x478) < *(int *)(iVar9 + 0x160)) {
            *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
          }
          else {
            *(int *)(iVar9 + 0x160) = *(int *)(param_6 + 0x478) + 1;
          }
        }
        iVar9 = (**(code **)(*param_4 + 0x14))(param_4);
        if (iVar3 <= iVar9) {
          if (iVar3 == 0) {
            param_4[0x27] = local_4c[0];
          }
          else {
            iVar9 = FUN_001054ec(param_4,iVar3);
            *(int *)(iVar9 + 0x10) = local_4c[0];
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= param_4[0x21]);
    }
    if (bVar2) {
      if (in_stack_0000003c == 0) {
        param_5[5] = param_5[5] | 0x40000;
        FUN_00105894(param_5,*(undefined4 *)(param_6 + 8));
      }
      else {
        *(uint *)(in_stack_0000003c + 0x14) = *(uint *)(in_stack_0000003c + 0x14) | 0x40000;
        FUN_00105894(in_stack_0000003c,*(undefined4 *)(param_6 + 8));
        FUN_0019401c(param_5);
      }
    }
    uVar7 = 1;
    if (in_stack_00000038 != (undefined4 *)0x0) {
      *in_stack_00000038 = param_4;
    }
  }
  return uVar7;
}

/* FUN_00186510 @ 0x186510 (1400 bytes) */
int FUN_00186510(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  int param_4;
{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  undefined1 *puVar11;
  int iVar12;
  int local_78;
  uint local_74;
  uint local_70;
  int local_6c;
  uint local_68;
  undefined4 local_64;
  int local_60;
  undefined4 uStack_5c;
  int local_58 [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  iVar5 = FUN_001054ec(param_1,1);
  local_60 = *(int *)(iVar5 + 0x10);
  iVar5 = FUN_001054ec(param_1,2);
  local_78 = *(int *)(iVar5 + 0x10);
  if (local_60 == local_78) {
    return 1;
  }
  iVar5 = FUN_001054ec(param_1,0);
  iVar8 = 0;
  local_64 = *(undefined4 *)(iVar5 + 0x10);
  do {
    iVar5 = 0;
    pcVar4 = &DAT_001b0228 + iVar8 * 4;
    iVar12 = 4;
    while ((*(char *)((int)&local_64 + iVar5) != '\0' ||
           ((*(char *)((int)&local_78 + iVar5) == *(char *)((int)&local_60 + iVar5) &&
            (*(char *)((int)&local_78 + iVar5) == *pcVar4))))) {
      iVar5 = iVar5 + 1;
      pcVar4 = pcVar4 + 1;
      iVar12 = iVar12 + -1;
      if (iVar12 == 0) {
        return 1;
      }
    }
    bVar1 = iVar8 != 4;
    iVar8 = iVar8 + 1;
  } while (bVar1);
  iVar5 = FUN_000f31e8(param_1,1);
  if ((iVar5 == 0) && (iVar5 = FUN_000f31e8(param_1,2), iVar5 == 0)) {
    *(int *)(*(int *)(param_4 + 0x6c4) + 0x204) = *(int *)(*(int *)(param_4 + 0x6c4) + 0x204) + 1;
    return 0;
  }
  piVar9 = (int *)*param_2;
  iVar8 = 1;
  piVar10 = (int *)*param_3;
  iVar5 = FUN_000f31e8(param_1,1);
  if (iVar5 != 0) {
    iVar8 = 2;
    local_60 = local_78;
    piVar9 = piVar10;
  }
  iVar12 = *(int *)(param_4 + 0x6c4);
  iVar5 = FUN_001054ec(param_1,0);
  local_74 = *(uint *)(iVar5 + 0x10);
  iVar5 = FUN_001054ec(piVar9,0);
  local_70 = *(uint *)(iVar5 + 0x10);
  local_6c = DAT_001b0224;
  if ((piVar9[5] & 0x200U) != 0) {
    *(int *)(*(int *)(param_4 + 0x6c4) + 0x204) = *(int *)(*(int *)(param_4 + 0x6c4) + 0x204) + 1;
    iVar5 = FUN_001054ec(piVar9,piVar9[0x21]);
    iVar6 = 0;
    local_6c = *(int *)(iVar5 + 0x10);
    iVar5 = 4;
    do {
      if ((*(byte *)((int)&local_60 + iVar6) != 4) &&
         (*(char *)((int)&local_6c + (uint)*(byte *)((int)&local_60 + iVar6)) != '\x04')) {
        bVar1 = false;
        goto LAB_00186708;
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  bVar1 = true;
LAB_00186708:
  local_68 = DAT_001b0220;
  if (bVar1) {
    iVar5 = FUN_0011379c(param_4,piVar9);
    if (iVar5 == 0) {
      iVar5 = FUN_001131c0(*(undefined4 *)(piVar9[0x22] + 8),param_4);
      if (iVar5 == 0) goto LAB_00186a60;
      iVar5 = FUN_0010497c(piVar9,iVar12);
      uVar3 = DAT_001b0220;
      if (iVar5 == 0) {
        iVar5 = 0;
        iVar6 = 4;
        do {
          if (((*(char *)((int)&local_74 + iVar5) == '\0') &&
              (*(char *)((int)&local_70 + iVar5) != '\0')) &&
             ((*(char *)((int)&local_70 + iVar5) != '\x01' ||
              (*(char *)((int)&local_6c + iVar5) != '\x04')))) goto LAB_00186a60;
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        uVar7 = (local_74 << 0x18 | (local_74 >> 8 & 0xff) << 0x10 | (local_74 >> 0x10 & 0xff) << 8
                | local_74 >> 0x18) &
                (local_70 << 0x18 | (local_70 >> 8 & 0xff) << 0x10 | (local_70 >> 0x10 & 0xff) << 8
                | local_70 >> 0x18);
        local_68 = uVar7 << 0x18 | (uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 | uVar7 >> 0x18;
      }
      else {
        local_68 = local_74;
      }
      piVar9[0x27] = local_68;
      FUN_000f3908(&local_40,local_68);
      FUN_000f3340(local_3c,uVar3,local_40);
    }
    else {
      iVar5 = FUN_0010497c(piVar9,iVar12);
      if (iVar5 == 0) {
        iVar5 = 0;
        iVar6 = 4;
        do {
          if ((*(char *)((int)&local_74 + iVar5) == '\0') &&
             ((*(char *)((int)&local_70 + iVar5) != '\x01' ||
              (*(char *)((int)&local_6c + iVar5) != '\x04')))) goto LAB_00186a60;
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        uVar7 = (local_74 << 0x18 | (local_74 >> 8 & 0xff) << 0x10 | (local_74 >> 0x10 & 0xff) << 8
                | local_74 >> 0x18) &
                (local_70 << 0x18 | (local_70 >> 8 & 0xff) << 0x10 | (local_70 >> 0x10 & 0xff) << 8
                | local_70 >> 0x18);
        local_68 = uVar7 << 0x18 | (uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 | uVar7 >> 0x18;
      }
      else {
        local_68 = local_74;
      }
      iVar5 = FUN_000f2e18(local_68);
      if (iVar5 == 0) goto LAB_00186a60;
      iVar6 = 1;
      piVar9[0x27] = local_68;
      iVar5 = FUN_0010497c(piVar9,iVar12);
      if (iVar5 == 0) {
        for (; iVar5 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar6 <= iVar5; iVar6 = iVar6 + 1) {
          iVar5 = FUN_001054ec(piVar9,iVar6);
          (&uStack_5c)[iVar6] = *(undefined4 *)(iVar5 + 0x10);
        }
      }
      else {
        piVar10 = local_58;
        for (; iVar5 = (**(code **)(*piVar9 + 0x14))(piVar9), iVar6 <= iVar5; iVar6 = iVar6 + 1) {
          *piVar10 = DAT_001b0224;
          piVar10 = piVar10 + 1;
        }
      }
      iVar5 = FUN_001054ec(param_1,iVar8);
      iVar12 = 0;
      local_64 = *(undefined4 *)(iVar5 + 0x10);
      do {
        if (*(char *)((int)&local_74 + iVar12) == '\0') {
          iVar5 = 1;
          puVar11 = (undefined1 *)((int)local_58 + iVar12);
          while( true ) {
            iVar6 = (**(code **)(*piVar9 + 0x14))(piVar9);
            if (iVar6 < iVar5) break;
            bVar2 = *(byte *)((int)&local_64 + iVar12);
            iVar6 = FUN_001054ec(piVar9,iVar5);
            *puVar11 = *(undefined1 *)((uint)bVar2 + iVar6 + 0x10);
            iVar5 = iVar5 + 1;
            puVar11 = puVar11 + 4;
          }
        }
        bVar1 = iVar12 != 3;
        iVar12 = iVar12 + 1;
      } while (bVar1);
      piVar10 = local_58;
      for (iVar5 = 1; iVar12 = (**(code **)(*piVar9 + 0x14))(piVar9), uVar3 = DAT_001b0220,
          iVar5 <= iVar12; iVar5 = iVar5 + 1) {
        iVar12 = *piVar10;
        if (iVar5 == 0) {
          piVar9[0x27] = iVar12;
        }
        else {
          iVar6 = FUN_001054ec(piVar9,iVar5);
          *(int *)(iVar6 + 0x10) = iVar12;
        }
        piVar10 = piVar10 + 1;
      }
      FUN_000f3908(&local_48,local_74);
      FUN_000f3340(&local_44,uVar3,local_48);
      local_3c[0] = local_44;
    }
    if (iVar8 == 0) {
      uVar3 = 1;
      *(undefined4 *)(param_1 + 0x9c) = local_3c[0];
    }
    else {
      iVar5 = FUN_001054ec(param_1,iVar8);
      uVar3 = 1;
      *(undefined4 *)(iVar5 + 0x10) = local_3c[0];
    }
  }
  else {
LAB_00186a60:
    uVar3 = 0;
    *(int *)(iVar12 + 0x204) = *(int *)(iVar12 + 0x204) + 1;
  }
  return uVar3;
}

/* FUN_00186a88 @ 0x186a88 (2816 bytes) */
int FUN_00186a88(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  int param_2;
  int *param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *local_a8;
  int *local_a4 [10];
  int local_7c [4];
  int local_6c;
  float local_68;
  
  local_a4[9] = (int *)0x3f800000;
  local_a4[5] = (int *)0x3f000000;
  local_a4[6] = (int *)0x3f800000;
  local_a4[7] = (int *)0x3f800000;
  local_a4[8] = (int *)0x3f800000;
  local_a4[2] = (int *)0x3f000000;
  local_a4[3] = (int *)0x3f000000;
  local_a4[4] = (int *)0x3f000000;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  FUN_00105594();
  iVar4 = (**(code **)(*param_1 + 0x14))(param_1);
  if (iVar4 < param_2) {
    return 0;
  }
  iVar4 = (**(code **)(*param_1 + 0x5c))(param_1);
  if (iVar4 != 0) {
    return 0;
  }
  iVar4 = (**(code **)(*param_1 + 0x28))(param_1);
  if (iVar4 != 0) {
    return 0;
  }
  if ((param_1[5] & 2U) != 0) {
    return 0;
  }
  iVar4 = (**(code **)(*param_1 + 100))(param_1);
  if (iVar4 != 0) {
    for (iVar4 = 1; iVar5 = (**(code **)(*param_1 + 0x14))(param_1), iVar4 <= iVar5;
        iVar4 = iVar4 + 1) {
      if ((((param_1[iVar4 * 6 + 0x28] & 1U) != 0) || ((param_1[iVar4 * 6 + 0x28] & 2U) != 0)) ||
         (iVar5 = FUN_000f31e8(param_1,iVar4), iVar5 == 0)) goto LAB_001874d4;
    }
    if ((param_1[0x48] == 0) && (param_1[0x49] == 0)) {
      if (((param_1[0x20] != 0) &&
          ((iVar4 = FUN_00126760(param_1[0x26]), iVar4 != 0 && ((param_1[5] & 2U) == 0)))) &&
         (iVar4 = (**(code **)(*param_1 + 0x50))(param_1), iVar4 == 0)) {
        iVar4 = 4;
        piVar6 = param_1;
        do {
          if (*(byte *)(piVar6 + 0x27) - 2 < 2) goto LAB_001874d4;
          piVar6 = (int *)((int)piVar6 + 1);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      FUN_001054ec(param_1,0);
      iVar4 = FUN_00105dbc(param_1,0);
      if (((iVar4 == 0) && ((param_1[5] & 2U) == 0)) && ((param_1[5] & 0x200U) == 0)) {
        return 0;
      }
    }
  }
LAB_001874d4:
  if (*(int *)(param_1[0x22] + 8) == 0x8e) {
    return 0;
  }
  iVar4 = (**(code **)(*param_3 + 0x5c))(param_3);
  if (iVar4 != 0) {
    return 0;
  }
  if (param_3[0x48] != 0) {
    return 0;
  }
  iVar4 = ((int (*)())FUN_001897fc)(param_1,param_2);
  if (iVar4 != 0) {
    return 0;
  }
  uVar2 = param_3[5];
  if ((uVar2 & 0x200) != 0) {
    iVar5 = param_3[1];
    FUN_0019401c(param_3);
    local_a8 = (int *)FUN_0010445c(param_3,*(undefined4 *)(param_4 + 8),1);
    iVar4 = FUN_00162dfc(&local_a8,1,param_4);
    if (iVar4 == 0) {
      FUN_000e7738(*(undefined4 *)(iVar5 + 0x158),iVar5,param_3);
      return 0;
    }
    FUN_000e7738(*(undefined4 *)(iVar5 + 0x158),iVar5,local_a8);
    FUN_000e7738(*(undefined4 *)(iVar5 + 0x158),local_a8,param_3);
    uVar2 = local_a8[5];
    param_3 = local_a8;
  }
  if ((uVar2 & 0x200) != 0) {
    return 0;
  }
  if (0 < param_3[0x21]) {
    iVar4 = 1;
    do {
      piVar6 = (int *)FUN_00105594(param_3,iVar4);
      iVar5 = (**(code **)(*piVar6 + 0x60))();
      if (iVar5 != 0) {
        return 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= param_3[0x21]);
  }
  iVar5 = FUN_001054ec(param_3,0);
  iVar4 = param_3[0x22];
  uVar7 = *(undefined4 *)(iVar5 + 0x10);
  if (*(int *)(iVar4 + 8) == 0x12) {
    local_a8 = (int *)FUN_00105594(param_3,1);
    iVar4 = FUN_001267b8(local_a8[0x26]);
    if (iVar4 == 0) {
      if (local_a8[0x26] == 0x33) {
        iVar4 = FUN_001054ec(param_3,1);
        iVar5 = 0;
        local_a4[0] = *(int **)(iVar4 + 0x10);
        iVar4 = 4;
        piVar6 = local_7c;
        do {
          uVar2 = (uint)*(byte *)(iVar5 + (int)local_a4);
          if (uVar2 != 4) {
            *piVar6 = local_a8[uVar2 * 6 + 8];
          }
          iVar5 = iVar5 + 1;
          piVar6 = piVar6 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        uVar8 = *(undefined4 *)(param_4 + 0x3ac);
        local_a8 = (int *)FUN_000f5f94(uVar8,local_7c,local_a4);
        if (local_a8 == (int *)0x0) {
          local_a8 = (int *)FUN_000f57f0(uVar8,local_7c,local_a4);
        }
        piVar6 = local_a4;
        if (local_a8 == (int *)0x0) {
          return 0;
        }
        iVar4 = FUN_001054ec(param_3,1);
        *(int **)(iVar4 + 0x10) = piVar6;
        FUN_00106004(param_3,1,local_a8,0,*(undefined4 *)(param_4 + 8));
      }
      else {
        local_a8 = (int *)0x0;
      }
    }
    if (local_a8 == (int *)0x0) {
      return 0;
    }
    iVar4 = (**(code **)(*local_a8 + 0x5c))();
    if (iVar4 != 0) {
      return 0;
    }
    if ((param_3[0x2e] & 2U) != 0) {
      return 0;
    }
    if (param_3[0x49] != 0) {
      return 0;
    }
    iVar4 = FUN_000f5cf0(param_3,2,uVar7,&local_6c);
    if ((iVar4 == 0) || (bVar1 = true, local_6c != 2)) {
      bVar1 = false;
    }
    if (bVar1) {
      if ((local_68 == FLOAT_001aa0e8) || (local_68 == FLOAT_001aa114)) {
        uVar2 = (uint)(local_68 == FLOAT_001aa114);
        if (uVar2 == (param_3[0x2e] & 1U)) {
          return 0;
        }
        iVar5 = FUN_001043f0(0x9c,*(undefined4 *)(param_4 + 8));
        uVar7 = *(undefined4 *)(iVar5 + 0x14c);
        iVar4 = FUN_001054ec(iVar5,0);
        *(undefined4 *)(iVar4 + 0xc) = 0x31;
        *(undefined4 *)(iVar4 + 8) = uVar7;
        uVar7 = *(undefined4 *)(param_4 + 8);
        piVar6 = local_a8;
        goto LAB_00187498;
      }
      if ((((local_68 == FLOAT_001aa10c) || (local_68 == FLOAT_001aa174)) &&
          (iVar4 = ((int (*)())FUN_00184cd8)(param_1,param_2,param_4), iVar4 != 0)) &&
         ((param_3[0x2e] & 1U) == (uint)(local_68 == FLOAT_001aa10c))) {
        iVar4 = FUN_001043f0(0x99,*(undefined4 *)(param_4 + 8));
        uVar7 = *(undefined4 *)(iVar4 + 0x14c);
        iVar5 = FUN_001054ec(iVar4,0);
        *(undefined4 *)(iVar5 + 0xc) = 0x31;
        *(undefined4 *)(iVar5 + 8) = uVar7;
        uVar7 = FUN_00105594(param_3,1);
        FUN_00106004(iVar4,1,uVar7,0,*(undefined4 *)(param_4 + 8));
        iVar4 = ((int (*)())FUN_00185da4)(param_2,local_68 == FLOAT_001aa174,param_1,iVar4,param_3,param_4,
                             param_5,param_6);
        if (iVar4 != 0) {
          param_1[0x49] = param_1[0x49] + -1;
          return iVar4;
        }
        return 0;
      }
    }
    local_a4[1] = (int *)FUN_00105594(param_3,2);
    iVar4 = FUN_001267b8(local_a4[1][0x26]);
    if (iVar4 == 0) {
      if (local_a4[1][0x26] == 0x33) {
        iVar4 = FUN_001054ec(param_3,2);
        iVar5 = 0;
        local_a4[0] = *(int **)(iVar4 + 0x10);
        iVar4 = 4;
        piVar6 = local_7c;
        do {
          uVar2 = (uint)*(byte *)(iVar5 + (int)local_a4);
          if (uVar2 != 4) {
            *piVar6 = local_a4[1][uVar2 * 6 + 8];
          }
          iVar5 = iVar5 + 1;
          piVar6 = piVar6 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        uVar7 = *(undefined4 *)(param_4 + 0x3ac);
        local_a4[1] = (int *)FUN_000f5f94(uVar7,local_7c,local_a4);
        if (local_a4[1] == (int *)0x0) {
          local_a4[1] = (int *)FUN_000f57f0(uVar7,local_7c,local_a4);
        }
        piVar6 = local_a4;
        if (local_a4[1] == (int *)0x0) {
          return 0;
        }
        iVar4 = FUN_001054ec(param_3,2);
        *(int **)(iVar4 + 0x10) = piVar6;
        FUN_00106004(param_3,2,local_a4[1],0,*(undefined4 *)(param_4 + 8));
      }
      else {
        local_a4[1] = (int *)0x0;
      }
    }
    if (((local_a4[1] == (int *)0x0) || ((param_3[0x34] & 2U) != 0)) ||
       ((iVar4 = (**(code **)(*local_a4[1] + 0x5c))(), iVar4 != 0 ||
        (iVar4 = ((int (*)())FUN_00186510)(param_3,&local_a8,local_a4 + 1,*(undefined4 *)(param_4 + 8)),
        iVar4 == 0)))) {
      return 0;
    }
    if ((param_3[0x2e] & 1U) == (param_3[0x34] & 1U)) {
      uVar8 = *(undefined4 *)(param_4 + 8);
      uVar7 = 0x9b;
    }
    else {
      uVar8 = *(undefined4 *)(param_4 + 8);
      uVar7 = 0x9a;
    }
    iVar5 = FUN_001043f0(uVar7,uVar8);
    uVar7 = *(undefined4 *)(iVar5 + 0x14c);
    iVar4 = FUN_001054ec(iVar5,0);
    *(undefined4 *)(iVar4 + 0xc) = 0x31;
    *(undefined4 *)(iVar4 + 8) = uVar7;
    FUN_00106004(iVar5,1,local_a8,0,*(undefined4 *)(param_4 + 8));
    FUN_00106004(iVar5,2,local_a4[1],0,*(undefined4 *)(param_4 + 8));
    uVar2 = param_3[0x2e] & 1;
  }
  else {
    if (*(int *)(iVar4 + 8) == 0x31) {
      iVar4 = FUN_00105594(param_3,1);
      uVar8 = 0;
      if (iVar4 != 0) {
        iVar4 = FUN_00105594(param_3,1);
        uVar8 = *(undefined4 *)(iVar4 + 0x98);
      }
      iVar4 = FUN_001267b8(uVar8);
      if ((iVar4 != 0) && ((param_3[0x2e] & 2U) == 0)) {
        piVar6 = (int *)FUN_00105594(param_3,1);
        iVar4 = (**(code **)(*piVar6 + 0x5c))();
        if ((iVar4 == 0) && (param_3[0x49] == 1)) {
          if ((param_3[0x2e] & 1U) == 0) {
            if ((param_3[0x34] & 1U) == 0) goto LAB_001872f8;
LAB_001872f0:
            uVar2 = 1;
          }
          else {
            if ((param_3[0x34] & 1U) == 0) goto LAB_001872f0;
LAB_001872f8:
            uVar2 = 0;
          }
          iVar5 = FUN_001043f0(0x9b,*(undefined4 *)(param_4 + 8));
          uVar7 = *(undefined4 *)(iVar5 + 0x14c);
          iVar4 = FUN_001054ec(iVar5,0);
          *(undefined4 *)(iVar4 + 0xc) = 0x31;
          *(undefined4 *)(iVar4 + 8) = uVar7;
          uVar7 = FUN_00105594(param_3,1);
          FUN_00106004(iVar5,1,uVar7,0,*(undefined4 *)(param_4 + 8));
          uVar7 = FUN_00105594(param_3,1);
          FUN_00106004(iVar5,2,uVar7,0,*(undefined4 *)(param_4 + 8));
          goto LAB_0018754c;
        }
      }
      iVar4 = param_3[0x22];
    }
    if (*(int *)(iVar4 + 8) != 0x14) {
      return 0;
    }
    iVar4 = FUN_00105594(param_3,1);
    if (iVar4 == 0) {
      uVar8 = 0;
    }
    else {
      iVar4 = FUN_00105594(param_3,1);
      uVar8 = *(undefined4 *)(iVar4 + 0x98);
    }
    iVar4 = FUN_001267b8(uVar8);
    if (iVar4 == 0) {
      return 0;
    }
    if ((param_3[0x2e] & 2U) != 0) {
      return 0;
    }
    piVar6 = (int *)FUN_00105594(param_3,1);
    iVar4 = (**(code **)(*piVar6 + 0x5c))();
    if (iVar4 != 0) {
      return 0;
    }
    iVar4 = FUN_000f5c0c(param_3,2,uVar7,local_a4 + 6);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = FUN_000f5c0c(param_3,3,uVar7,local_a4 + 2);
    if (iVar4 == 0) {
      return 0;
    }
    if (param_3[0x49] != 1) {
      return 0;
    }
    uVar2 = param_3[0x3a] & 1;
    if ((param_3[0x2e] & 1U) == 0) {
      if ((param_3[0x34] & 1U) == 0) goto LAB_0018744c;
LAB_00187444:
      uVar3 = 1;
    }
    else {
      if ((param_3[0x34] & 1U) == 0) goto LAB_00187444;
LAB_0018744c:
      uVar3 = 0;
    }
    if (uVar3 == uVar2) {
      return 0;
    }
    iVar5 = FUN_001043f0(0x99,*(undefined4 *)(param_4 + 8));
    uVar7 = *(undefined4 *)(iVar5 + 0x14c);
    iVar4 = FUN_001054ec(iVar5,0);
    *(undefined4 *)(iVar4 + 0xc) = 0x31;
    *(undefined4 *)(iVar4 + 8) = uVar7;
    piVar6 = (int *)FUN_00105594(param_3,1);
    uVar7 = *(undefined4 *)(param_4 + 8);
LAB_00187498:
    FUN_00106004(iVar5,1,piVar6,0,uVar7);
  }
LAB_0018754c:
  iVar4 = ((int (*)())FUN_00185da4)(param_2,uVar2,param_1,iVar5,param_3,param_4,param_5,param_6);
  return iVar4;
}

/* FUN_001875a8 @ 0x1875a8 (1328 bytes) */
int FUN_001875a8(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c [5];
  
  if ((((((param_1 != (int *)0x0) && (*(int *)(*(int *)(param_3 + 0x88) + 8) == 0x12)) &&
        (*(int *)(param_1[0x22] + 8) == 0x12)) &&
       (((iVar4 = FUN_0010497c(param_3,param_4), iVar4 != 0 && (*(int *)(param_3 + 0x120) == 0)) &&
        ((*(int *)(param_3 + 0x124) == 0 && ((param_1[0x48] == 0 && (param_1[0x49] == 0)))))))) &&
      ((param_1[5] & 0x200U) == 0)) &&
     (((*(uint *)(param_3 + 0x14) & 0x200) == 0 && ((*(uint *)(param_3 + 0x14) & 0x40000) == 0)))) {
    iVar4 = FUN_001054ec(param_1,0);
    iVar13 = *(int *)(iVar4 + 0x10);
    iVar4 = FUN_001054ec(param_3,0);
    if (iVar13 != *(int *)(iVar4 + 0x10)) {
      iVar4 = FUN_001054ec(param_3,0);
      iVar4 = FUN_000f3824(*(undefined4 *)(iVar4 + 0x10));
      if (iVar4 == 0) goto LAB_00187a90;
    }
    iVar4 = FUN_000f31e8(param_1,param_2);
    if (iVar4 == 0) {
      iVar4 = (**(code **)(*param_1 + 0x60))(param_1);
      if (iVar4 != 0) {
        return 0;
      }
      iVar4 = FUN_001054ec(param_1,param_2);
      uVar12 = *(undefined4 *)(iVar4 + 0x10);
      iVar4 = FUN_001054ec(param_1,0);
      uVar10 = *(undefined4 *)(iVar4 + 0x10);
      *(undefined4 *)(param_3 + 0x9c) = uVar10;
      iVar4 = FUN_001054ec(param_3,1);
      FUN_000f2bdc(&local_68,*(undefined4 *)(iVar4 + 0x10),uVar12);
      iVar4 = FUN_001054ec(param_3,1);
      *(undefined4 *)(iVar4 + 0x10) = local_68;
      iVar4 = FUN_001054ec(param_3,2);
      FUN_000f2bdc(&local_64,*(undefined4 *)(iVar4 + 0x10),uVar12);
      iVar4 = FUN_001054ec(param_3,2);
      uVar12 = DAT_001b0220;
      *(undefined4 *)(iVar4 + 0x10) = local_64;
      FUN_000f3908(&local_60,uVar10);
      FUN_000f3340(local_5c,uVar12,local_60);
      if (param_2 == 0) {
        param_1[0x27] = local_5c[0];
      }
      else {
        iVar4 = FUN_001054ec(param_1,param_2);
        *(int *)(iVar4 + 0x10) = local_5c[0];
      }
    }
    piVar5 = (int *)FUN_00105594(param_3,1);
    FUN_001054ec(param_3,1);
    piVar6 = (int *)FUN_00105594(param_3,2);
    uVar1 = *(uint *)(param_3 + 0xd0) & 1;
    uVar8 = *(uint *)(param_3 + 0xd0) >> 1 & 1;
    iVar4 = FUN_001054ec(param_3,2);
    uVar12 = *(undefined4 *)(iVar4 + 0x10);
    iVar13 = (param_2 == 1) + 1;
    piVar7 = (int *)FUN_00105594(param_1,iVar13);
    uVar2 = param_1[iVar13 * 6 + 0x28] & 1;
    uVar9 = (uint)param_1[iVar13 * 6 + 0x28] >> 1 & 1;
    iVar4 = FUN_001054ec(param_1,iVar13);
    uVar10 = *(undefined4 *)(iVar4 + 0x10);
    iVar4 = (**(code **)(*piVar5 + 0x5c))(piVar5);
    if (iVar4 != 0) {
      return 0;
    }
    iVar4 = (**(code **)(*piVar6 + 0x5c))(piVar6);
    if (iVar4 != 0) {
      return 0;
    }
    iVar4 = (**(code **)(*piVar7 + 0x5c))(piVar7);
    if (iVar4 != 0) {
      return 0;
    }
    iVar4 = (**(code **)(*piVar7 + 0x48))(piVar7);
    if ((((iVar4 != 0) && (iVar4 = (**(code **)(*piVar5 + 0x48))(piVar5), iVar4 == 0)) &&
        (iVar4 = (**(code **)(*piVar6 + 0x48))(piVar6), iVar4 == 0)) &&
       ((param_1[param_2 * 6 + 0x28] & 2U) == 0)) {
      iVar11 = param_3 + 0xbc;
      FUN_00106004(param_3,2,piVar7,0,*(undefined4 *)(param_4 + 8));
      FUN_00103d50(iVar11,1,uVar2);
      FUN_00103d50(iVar11,2,uVar9);
      piVar5 = param_1 + iVar13 * 6 + 0x23;
      iVar4 = FUN_001054ec(param_3,2);
      *(undefined4 *)(iVar4 + 0x10) = uVar10;
      FUN_00106004(param_1,iVar13,piVar6,0,*(undefined4 *)(param_4 + 8));
      FUN_00103d50(piVar5,1,uVar1);
      FUN_00103d50(piVar5,2,uVar8);
      iVar4 = FUN_001054ec(param_1,iVar13);
      uVar3 = param_1[param_2 * 6 + 0x28];
      *(undefined4 *)(iVar4 + 0x10) = uVar12;
      if ((uVar3 & 1) != 0) {
        FUN_00103d50(iVar11,1,*(uint *)(param_3 + 0xd0) & 1 ^ 1);
        FUN_00103d50(piVar5,1,param_1[iVar13 * 6 + 0x28] & 1U ^ 1);
      }
      iVar4 = ((int (*)())FUN_00186a88)(param_1,param_2,param_3,param_4,1,1,0);
      if (iVar4 != 0) {
        return 1;
      }
      FUN_00106004(param_3,2,piVar6,0,*(undefined4 *)(param_4 + 8));
      FUN_00103d50(iVar11,1,uVar1);
      FUN_00103d50(iVar11,2,uVar8);
      iVar4 = FUN_001054ec(param_3,2);
      *(undefined4 *)(iVar4 + 0x10) = uVar12;
      FUN_00106004(param_1,iVar13,piVar7,0,*(undefined4 *)(param_4 + 8));
      FUN_00103d50(piVar5,1,uVar2);
      FUN_00103d50(piVar5,2,uVar9);
      iVar4 = FUN_001054ec(param_1,iVar13);
      *(undefined4 *)(iVar4 + 0x10) = uVar10;
    }
  }
LAB_00187a90:
  iVar4 = ((int (*)())FUN_00186a88)(param_1,param_2,param_3,param_4,1,1,0);
  if (iVar4 == 0) {
    return 0;
  }
  return 1;
}

/* FUN_00187ad8 @ 0x187ad8 (1996 bytes) */
int FUN_00187ad8(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  undefined4 *puVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  undefined4 uVar21;
  uint uVar22;
  int iVar23;
  uint *puVar24;
  code *pcVar25;
  int iVar26;
  int iVar27;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_80;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  undefined4 *local_5c;
  
  piVar5 = (int *)FUN_001922c4(0,0,param_1,param_2);
  iVar2 = *(int *)(piVar5[0x22] + 8);
  if (((iVar2 != 0x24) && (iVar2 != 0x25)) && (iVar2 != 0x26)) {
    return;
  }
  iVar2 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0e8,piVar5,2);
  iVar6 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,piVar5,2);
  if ((iVar6 == 0) || (iVar6 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0e8,piVar5,3), iVar6 == 0)) {
    iVar6 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,piVar5,3);
    if (iVar6 == 0) {
      return;
    }
    if (iVar2 == 0) {
      return;
    }
  }
  if ((piVar5[5] & 0x200U) != 0) {
    return;
  }
  puVar24 = (uint *)piVar5[4];
  uVar3 = puVar24[1];
  uVar18 = uVar3 - 1;
  if (-1 < (int)uVar18) {
    iVar6 = uVar18 * 4;
    uVar19 = 0;
    piVar11 = (int *)0x0;
    uVar22 = uVar18;
    do {
      if (uVar22 < *puVar24) {
        uVar7 = puVar24[1];
        if (uVar7 <= uVar22) {
          _memset((void *)(uVar7 * 4 + puVar24[2]),0,(uVar22 - uVar7) * 4 + 4);
          puVar24[1] = uVar22 + 1;
        }
        piVar8 = (int *)(iVar6 + puVar24[2]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar24,uVar22);
      }
      iVar26 = *piVar8;
      iVar4 = *(int *)(iVar26 + 0x88);
      piVar8 = piVar11;
      if (*(int *)(iVar4 + 8) != 0x13) {
        if (*(int *)(iVar4 + 8) == 0x14) {
          piVar9 = (int *)FUN_00105594(iVar26,1);
          if ((piVar5 == piVar9) || (piVar9 = (int *)FUN_00105594(iVar26,2), piVar5 == piVar9))
          goto LAB_00187ce4;
          iVar4 = *(int *)(iVar26 + 0x88);
        }
        if (*(int *)(iVar4 + 8) == 0x12) {
          piVar9 = (int *)FUN_00105594(iVar26,1);
          piVar10 = (int *)FUN_00105594(iVar26,2);
          piVar8 = piVar10;
          if (((piVar5 != piVar9) && (piVar8 = piVar9, piVar5 != piVar10)) ||
             ((piVar11 != (int *)0x0 && (piVar11 != piVar8)))) goto LAB_00187cfc;
        }
      }
LAB_00187ce4:
      uVar19 = uVar19 + 1;
      uVar22 = uVar22 - 1;
      iVar6 = iVar6 + -4;
      if (uVar19 == uVar3) goto LAB_00187cfc;
      puVar24 = (uint *)piVar5[4];
      piVar11 = piVar8;
    } while( true );
  }
LAB_00187d00:
  iVar6 = *(int *)(param_2 + 0x478);
  if (-1 < (int)uVar18) {
    iVar4 = uVar18 * 4;
    uVar22 = 0;
    do {
      if (uVar18 < *puVar24) {
        uVar19 = puVar24[1];
        if (uVar19 <= uVar18) {
          _memset((void *)(uVar19 * 4 + puVar24[2]),0,(uVar18 - uVar19) * 4 + 4);
          puVar24[1] = uVar18 + 1;
        }
        piVar11 = (int *)(iVar4 + puVar24[2]);
      }
      else {
        piVar11 = (int *)FUN_0019423c(puVar24,uVar18);
      }
      iVar26 = *piVar11;
      if (*(int *)(*(int *)(iVar26 + 0x88) + 8) == 0x13) {
        piVar11 = (int *)FUN_00105594(iVar26,1);
        if (piVar5 == piVar11) {
          uVar21 = 1;
          iVar23 = 2;
        }
        else {
          piVar11 = (int *)FUN_00105594(iVar26,2);
          if (piVar5 != piVar11) {
            if ((*(uint *)(iVar26 + 0x14) & 0x200) != 0) {
              FUN_00105594(iVar26,*(undefined4 *)(iVar26 + 0x84));
            }
            goto LAB_00188244;
          }
          uVar21 = 2;
          iVar23 = 1;
        }
        local_5c = &local_94;
        iVar20 = 0;
        *(int *)(param_2 + 500) = *(int *)(param_2 + 500) + 1;
        FUN_00194208(piVar5[4],uVar18);
        piVar5[0x58] = piVar5[0x58] + -1;
        local_80 = 0;
        local_94 = 0;
        local_90 = 0;
        uVar12 = FUN_001054ec(iVar26,0);
        FUN_00104730(local_5c,uVar12);
        local_60 = FUN_00105594(iVar26,iVar23);
        FUN_00106004(iVar26,iVar23,0,1,*(undefined4 *)(param_2 + 8));
        iVar13 = FUN_001054ec(iVar26,iVar23);
        local_78 = *(int *)(iVar13 + 0x10);
        iVar13 = FUN_001054ec(iVar26,uVar21);
        local_98 = *(undefined4 *)(iVar13 + 0x10);
        uVar19 = *(uint *)(iVar23 * 0x18 + iVar26 + 0xa0);
        local_68 = uVar19 & 1;
        local_64 = uVar19 >> 1 & 1;
        local_6c = piVar5[1];
        local_70 = *(undefined4 *)(iVar26 + 8);
        local_74 = *(undefined4 *)(iVar26 + 0x158);
        iVar13 = piVar5[0x56];
        iVar23 = *(int *)(iVar26 + 0x10);
        FUN_0019401c(piVar5);
        FUN_0019401c(iVar26);
        iVar16 = *(int *)(iVar26 + 0x14c);
        iVar27 = *(int *)(iVar26 + 0x120);
        iVar17 = *(int *)(iVar26 + 0x124);
        if ((*(uint *)(iVar26 + 0x14) & 0x200) != 0) {
          iVar20 = FUN_00105594(iVar26,*(undefined4 *)(iVar26 + 0x84));
          uVar21 = *(undefined4 *)(param_2 + 8);
          iVar14 = FUN_00105594(iVar26,*(undefined4 *)(iVar26 + 0x84));
          puVar24 = *(uint **)(iVar14 + 0x10);
          uVar19 = puVar24[1];
          if (0 < (int)uVar19) {
            uVar7 = 0;
            do {
              if (uVar7 < *puVar24) {
                if (uVar19 <= uVar7) {
                  _memset((void *)(uVar19 * 4 + puVar24[2]),0,(uVar7 - uVar19) * 4 + 4);
                  puVar24[1] = uVar7 + 1;
                }
                piVar11 = (int *)(uVar7 * 4 + puVar24[2]);
              }
              else {
                piVar11 = (int *)FUN_0019423c(puVar24,uVar7);
              }
              if (iVar26 == *piVar11) {
                FUN_00194208(puVar24,uVar7);
                iVar14 = FUN_00105594(iVar26,*(undefined4 *)(iVar26 + 0x84));
                *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + -1;
                break;
              }
              uVar19 = puVar24[1];
              uVar7 = uVar7 + 1;
            } while ((int)uVar7 < (int)uVar19);
          }
          FUN_00106004(iVar26,*(undefined4 *)(iVar26 + 0x84),0,1,uVar21);
          *(int *)(iVar26 + 0x84) = *(int *)(iVar26 + 0x84) + -1;
          *(uint *)(iVar26 + 0x14) = *(uint *)(iVar26 + 0x14) & 0xfffffdff;
        }
        iVar14 = *(int *)(iVar26 + 0x160) - iVar6;
        if (iVar14 < 0) {
          iVar14 = 0;
        }
        piVar11 = (int *)FUN_00103ebc(piVar5,iVar26,*(undefined4 *)(param_2 + 8),1);
        iVar26 = (iVar2 == 0) + 2;
        FUN_001062c0(piVar11,0,local_5c,*(undefined4 *)(param_2 + 8));
        piVar11[0x53] = iVar16;
        FUN_000e7738(iVar13,local_6c,piVar5);
        FUN_000e7700(local_74,local_70,piVar11);
        piVar11[0x48] = iVar27;
        piVar11[0x49] = iVar17;
        if (iVar20 != 0) {
          FUN_00106804(piVar11,iVar20,1,*(undefined4 *)(param_2 + 8));
        }
        piVar11[4] = iVar23;
        FUN_00106004(piVar11,iVar26,local_60,1,*(undefined4 *)(param_2 + 8));
        piVar11[0x58] = iVar6 + iVar14;
        if (iVar26 == 0) {
          piVar11[0x27] = local_78;
        }
        else {
          iVar23 = FUN_001054ec(piVar11,iVar26);
          *(int *)(iVar23 + 0x10) = local_78;
        }
        FUN_00103d50(piVar11 + iVar26 * 6 + 0x23,2,local_64);
        FUN_00103d50(piVar11 + iVar26 * 6 + 0x23,1,local_68);
        iVar23 = FUN_00105594(piVar11,1);
        if (iVar6 < *(int *)(iVar23 + 0x160)) {
          *(int *)(iVar23 + 0x160) = *(int *)(iVar23 + 0x160) + 1;
        }
        else {
          *(int *)(iVar23 + 0x160) = iVar6 + 1;
        }
        puVar24 = *(uint **)(iVar23 + 0x10);
        uVar19 = puVar24[1];
        if (uVar19 < *puVar24) {
          _memset((void *)(uVar19 * 4 + puVar24[2]),0,4);
          puVar15 = (undefined4 *)(uVar19 * 4 + puVar24[2]);
          puVar24[1] = uVar19 + 1;
        }
        else {
          puVar15 = (undefined4 *)FUN_0019423c(puVar24,uVar19);
        }
        *puVar15 = piVar11;
        iVar23 = 0;
        do {
          uVar19 = (uint)*(byte *)((int)&local_98 + iVar23);
          iVar13 = FUN_001054ec(piVar11,0);
          if (*(char *)(iVar23 + iVar13 + 0x10) == '\x01') {
            uVar19 = 4;
          }
          for (iVar13 = 1; iVar20 = (**(code **)(*piVar11 + 0x14))(piVar11), iVar13 <= iVar20;
              iVar13 = iVar13 + 1) {
            if (iVar26 != iVar13) {
              if (uVar19 == 4) {
                (**(code **)(*piVar11 + 0x88))(piVar11,iVar13,iVar23,4);
              }
              else {
                pcVar25 = *(code **)(*piVar11 + 0x88);
                iVar20 = FUN_001054ec(piVar5,iVar13);
                (*pcVar25)(piVar11,iVar13,iVar23,*(undefined1 *)(uVar19 + iVar20 + 0x10));
              }
            }
          }
          bVar1 = iVar23 != 3;
          iVar23 = iVar23 + 1;
        } while (bVar1);
      }
LAB_00188244:
      uVar22 = uVar22 + 1;
      uVar18 = uVar18 - 1;
      iVar4 = iVar4 + -4;
      if (uVar22 == uVar3) goto code_r0x00188258;
      puVar24 = (uint *)piVar5[4];
    } while( true );
  }
LAB_0018825c:
  if (puVar24[1] == 0) {
    (**(code **)(*piVar5 + 0xc))(piVar5,1,*(undefined4 *)(param_2 + 8));
  }
  return;
LAB_00187cfc:
  puVar24 = (uint *)piVar5[4];
  goto LAB_00187d00;
code_r0x00188258:
  puVar24 = (uint *)piVar5[4];
  goto LAB_0018825c;
}

/* FUN_001882a4 @ 0x1882a4 (408 bytes) */
int FUN_001882a4(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  double dVar9;
  
  iVar4 = (**(code **)(*param_1 + 0x68))();
  if (iVar4 != 0) {
    piVar5 = (int *)FUN_00105594(param_1,1);
    iVar4 = (**(code **)(*piVar5 + 0x40))();
    if (iVar4 != 0) {
      uVar7 = 0xffffffff;
      iVar4 = 0;
      fVar2 = FLOAT_001aa0d4;
      do {
        iVar6 = FUN_001054ec(param_1,0);
        if (*(char *)(iVar4 + iVar6 + 0x10) != '\x01') {
          iVar6 = FUN_001054ec(param_1,1);
          uVar8 = (uint)*(byte *)(iVar4 + iVar6 + 0x10);
          if (((int)*(char *)(piVar5 + 0x57) >> (uVar8 & 0x3f) & 1U) == 0) {
            return;
          }
          iVar6 = ((undefined4 (*)())FUN_0010aafc)((double)(float)piVar5[uVar8 * 6 + 8]);
          if (iVar6 == 0) {
            return;
          }
          if (uVar7 == 0xffffffff) {
            fVar2 = (float)piVar5[uVar8 * 6 + 8];
            uVar7 = uVar8;
          }
          else if ((float)piVar5[uVar8 * 6 + 8] != fVar2) {
            return;
          }
        }
        bVar1 = iVar4 != 3;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      iVar4 = ((int (*)())FUN_0010ab40)((double)(float)piVar5[uVar7 * 6 + 8]);
      iVar6 = (**(code **)(**(int **)(param_2 + 0x30c) + 0xfc))(*(int **)(param_2 + 0x30c),iVar4,0);
      if (iVar6 != 0) {
        dVar9 = (double)FLOAT_001aa0e8;
        FUN_000f79c4(dVar9,dVar9,dVar9,dVar9,param_1,*(undefined4 *)(param_2 + 0x6c4),1);
        uVar3 = DAT_001b0220;
        param_1[0x49] = iVar4;
        iVar4 = FUN_001054ec(param_1,1);
        *(undefined4 *)(iVar4 + 0x10) = uVar3;
      }
    }
  }
  return;
}

/* FUN_0018843c @ 0x18843c (1328 bytes) */
int FUN_0018843c(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int *param_4;
  int param_5;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_38 [7];
  
  uVar2 = 0;
  local_38[0] = 0;
  iVar1 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x1b);
  if (iVar1 == 0) {
LAB_00188508:
    iVar1 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x1c);
    if (iVar1 != 0) {
      iVar1 = FUN_00154dc0(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
        if (param_4 == (int *)0x0) goto LAB_00188950;
      }
      iVar1 = FUN_00162cc0(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
        if (param_4 == (int *)0x0) goto LAB_00188950;
      }
      iVar1 = (**(code **)(*param_4 + 0x14))(param_4);
      if ((param_3 <= iVar1) && (iVar1 = FUN_00158264(param_2,param_3,param_4,param_5), iVar1 != 0))
      {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
        if (param_4 == (int *)0x0) goto LAB_00188950;
        uVar2 = 1;
      }
      iVar1 = FUN_00155a60(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_0014bdbc(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_0014caec(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_0014d8f8(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_00150d38(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_0014cec8(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_0015df44(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_0015e494(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x3c);
      if ((iVar1 != 0) && (iVar1 = FUN_00163478(param_2,param_3,param_4,param_5), iVar1 != 0)) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_0014d274(param_4,param_5);
      if (iVar1 != 0) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      }
      iVar1 = FUN_00158c3c(param_4,param_5);
      if (iVar1 != 0) {
        uVar2 = 1;
      }
    }
    iVar1 = FUN_0015546c(param_2,param_3,param_4,param_5);
    if (iVar1 != 0) {
      uVar2 = 1;
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar1 = FUN_00155654(param_2,param_3,param_4,param_5);
    if (iVar1 != 0) {
      uVar2 = 1;
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar1 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x1d);
    if ((((iVar1 != 0) && (iVar1 = FUN_001633f8(param_4,param_5), iVar1 != 0)) &&
        (iVar1 = (**(code **)(*param_4 + 100))(param_4), iVar1 != 0)) &&
       ((param_2 != 0 &&
        (iVar1 = FUN_00160320(param_2,param_3,param_4,param_5,local_38), iVar1 != 0)))) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      if (param_4 == (int *)0x0) goto LAB_00188950;
    }
    iVar1 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x39);
    if (iVar1 != 0) {
      ((int (*)())FUN_001882a4)(param_4,*(undefined4 *)(param_5 + 8));
    }
    iVar1 = FUN_00159b58(param_4,1,param_5);
    if (iVar1 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar1 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x39);
    if ((iVar1 != 0) &&
       (iVar1 = ((int (*)())FUN_001875a8)(param_2,param_3,param_4,param_5,*(undefined4 *)(param_5 + 8)),
       iVar1 != 0)) {
      uVar2 = 1;
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar1 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x3b);
    if ((iVar1 != 0) && ((param_4[5] & 1U) != 0)) {
      ((int (*)())FUN_001859bc)(param_4,param_5,*(undefined4 *)(param_5 + 8));
    }
  }
  else {
    uVar2 = (**(code **)(*param_4 + 100))(param_4);
    iVar1 = FUN_0014abdc(param_4,param_5,local_38);
    if (iVar1 == 0) {
LAB_001884c8:
      if ((param_2 != 0) &&
         (iVar1 = FUN_00160320(param_2,param_3,param_4,param_5,local_38), iVar1 != 0)) {
        param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
        if (param_4 == (int *)0x0) goto LAB_00188950;
      }
      goto LAB_00188508;
    }
    param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    if (param_4 != (int *)0x0) goto LAB_001884c8;
LAB_00188950:
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_0018896c @ 0x18896c (1208 bytes) */
int FUN_0018896c(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint *puVar12;
  int *piVar13;
  undefined4 local_58;
  undefined4 local_54;
  int local_48;
  undefined4 local_44;
  int local_38 [5];
  
  if (*(int *)(param_1[0x22] + 8) != 0x31) {
    return;
  }
  iVar1 = FUN_00105594(param_1,1);
  uVar2 = 0;
  if (iVar1 != 0) {
    iVar1 = FUN_00105594(param_1,1);
    uVar2 = *(undefined4 *)(iVar1 + 0x98);
  }
  iVar1 = FUN_001267b8(uVar2);
  if (iVar1 == 0) {
    return;
  }
  piVar3 = (int *)FUN_00105594(param_1,1);
  iVar1 = (**(code **)(*piVar3 + 0x5c))();
  if (iVar1 != 0) {
    return;
  }
  if ((param_1[5] & 0x200U) != 0) {
    return;
  }
  if (param_1[0x48] != 0) {
    return;
  }
  piVar3 = (int *)FUN_00105594(param_1,1);
  iVar1 = (**(code **)(*piVar3 + 0x48))();
  if (iVar1 != 0) {
    return;
  }
  if (param_1[0x49] == 0) {
    return;
  }
  if (((param_1[0x2e] & 1U) == 0) && ((param_1[0x2e] & 2U) == 0)) {
    iVar1 = FUN_001054ec(param_1,1);
    iVar1 = FUN_000f3190(*(undefined4 *)(iVar1 + 0x10));
    if (iVar1 != 0) goto LAB_00188a5c;
  }
  iVar1 = ((int (*)())FUN_00184bf0)(param_1);
  if (iVar1 == 0) {
    return;
  }
LAB_00188a5c:
  uVar2 = FUN_00105594(param_1,1);
  iVar1 = ((int (*)())FUN_00184ef0)(uVar2,param_1[0x49],param_2);
  if (iVar1 != 0) {
    *(int *)(param_2 + 0x160) = *(int *)(param_2 + 0x160) + 1;
    uVar2 = FUN_00105594(param_1,1);
    puVar12 = (uint *)param_1[4];
    uVar9 = puVar12[1] - 1;
    if (-1 < (int)uVar9) {
      do {
        if (uVar9 < *puVar12) {
          uVar4 = puVar12[1];
          if (uVar4 <= uVar9) {
            _memset((void *)(uVar4 * 4 + puVar12[2]),0,(uVar9 - uVar4) * 4 + 4);
            puVar12[1] = uVar9 + 1;
          }
          puVar5 = (undefined4 *)(uVar9 * 4 + puVar12[2]);
        }
        else {
          puVar5 = (undefined4 *)FUN_0019423c(puVar12,uVar9);
        }
        piVar13 = (int *)*puVar5;
        piVar3 = piVar13 + 0x20;
        for (iVar1 = 0; iVar8 = (**(code **)(*piVar13 + 0x14))(piVar13), iVar1 <= iVar8;
            iVar1 = iVar1 + 1) {
          piVar6 = (int *)FUN_00105594(piVar13,iVar1);
          if (param_1 == piVar6) {
            uVar9 = uVar9 - 1;
            iVar8 = FUN_001054ec(piVar6,1);
            uVar10 = *(undefined4 *)(iVar8 + 0x10);
            iVar8 = FUN_001054ec(piVar13,iVar1);
            FUN_000f2bdc(local_38,uVar10,*(undefined4 *)(iVar8 + 0x10));
            iVar8 = local_38[0];
            if ((*(int *)(piVar13[0x22] + 8) != 0x8e) ||
               (((iVar7 = FUN_000f3190(local_38[0]), iVar7 != 0 && ((param_1[0x2e] & 1U) == 0)) &&
                ((param_1[0x2e] & 2U) == 0)))) {
              FUN_00106004(piVar13,iVar1,uVar2,1,*(undefined4 *)(param_2 + 8));
              if (iVar1 == 0) {
                piVar13[0x27] = iVar8;
              }
              else {
                iVar7 = FUN_001054ec(piVar13,iVar1);
                *(int *)(iVar7 + 0x10) = iVar8;
              }
              FUN_00103d50(piVar3 + 3,2,(uint)param_1[0x2e] >> 1 & 1);
              if ((param_1[0x2e] & 1U) != 0) {
                FUN_00103d50(piVar3 + 3,1,piVar3[8] & 1U ^ 1);
              }
            }
          }
          piVar3 = piVar3 + 6;
        }
        if (((piVar13[5] & 0x200U) != 0) &&
           (piVar3 = (int *)FUN_00105594(piVar13,piVar13[0x21]), param_1 == piVar3)) {
          iVar1 = FUN_000f31e8(piVar3,1);
          if (iVar1 != 0) {
            local_44 = 0;
            local_58 = 0;
            local_54 = 0;
            FUN_00104d3c(piVar13,&local_58);
            uVar10 = *(undefined4 *)(param_2 + 8);
            iVar1 = FUN_00105594(piVar13,piVar13[0x21]);
            puVar12 = *(uint **)(iVar1 + 0x10);
            uVar4 = puVar12[1];
            if (0 < (int)uVar4) {
              uVar11 = 0;
              do {
                if (uVar11 < *puVar12) {
                  if (uVar4 <= uVar11) {
                    _memset((void *)(uVar4 * 4 + puVar12[2]),0,(uVar11 - uVar4) * 4 + 4);
                    puVar12[1] = uVar11 + 1;
                  }
                  piVar3 = (int *)(uVar11 * 4 + puVar12[2]);
                }
                else {
                  piVar3 = (int *)FUN_0019423c(puVar12,uVar11);
                }
                if (piVar13 == (int *)*piVar3) {
                  FUN_00194208(puVar12,uVar11);
                  iVar1 = FUN_00105594(piVar13,piVar13[0x21]);
                  *(int *)(iVar1 + 0x160) = *(int *)(iVar1 + 0x160) + -1;
                  break;
                }
                uVar4 = puVar12[1];
                uVar11 = uVar11 + 1;
              } while ((int)uVar11 < (int)uVar4);
            }
            FUN_00106004(piVar13,piVar13[0x21],0,1,uVar10);
            piVar13[0x21] = piVar13[0x21] + -1;
            piVar13[5] = piVar13[5] & 0xfffffdff;
            FUN_00106804(piVar13,uVar2,1,*(undefined4 *)(param_2 + 8));
            iVar1 = local_48;
            if (piVar13[0x21] == 0) {
              piVar13[0x27] = local_48;
            }
            else {
              iVar8 = FUN_001054ec(piVar13);
              *(int *)(iVar8 + 0x10) = iVar1;
            }
          }
          uVar9 = uVar9 - 1;
        }
        if ((int)uVar9 < 0) break;
        puVar12 = (uint *)param_1[4];
      } while( true );
    }
    iVar1 = FUN_00104054(param_1,param_2);
    if (iVar1 == 0) {
      FUN_0019401c(param_1);
      (**(code **)(*param_1 + 0xc))(param_1,1,*(undefined4 *)(param_2 + 8));
    }
  }
  return;
}

/* FUN_00188e24 @ 0x188e24 (256 bytes) */
int FUN_00188e24(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  if ((*(uint *)(param_2 + 0x14) & 1) != 0) {
    ((int (*)())FUN_00187ad8)(param_2,param_3);
    iVar1 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x36);
    if ((iVar1 == 0) || (((int (*)())FUN_00184d7c)(param_2,param_3), (*(uint *)(param_2 + 0x14) & 1) != 0)) {
      iVar1 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x15);
      if (iVar1 != 0) {
        FUN_00150b94(param_2,param_3);
        FUN_0014e6e4(param_2,param_3);
      }
      iVar1 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x16);
      if ((iVar1 != 0) && (iVar1 = FUN_0010497c(param_2,param_3), iVar1 == 0)) {
        FUN_0015a68c(param_2,param_3);
      }
      iVar1 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x14);
      if (iVar1 != 0) {
        ((int (*)())FUN_0018896c)(param_2,param_3);
        return;
      }
    }
  }
  return;
}

/* FUN_00188f24 @ 0x188f24 (200 bytes) */
int FUN_00188f24(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 auStack_28 [24];
  
  piVar3 = *(int **)(param_2 + 900);
  iVar1 = piVar3[2];
  while (iVar1 != 0) {
    iVar1 = (**(code **)(*piVar3 + 0x24))(piVar3);
    if (iVar1 != 0) {
      iVar2 = piVar3[0x4d];
      iVar1 = FUN_00194034(iVar2 + 0x90);
      if ((((iVar1 < 3) && (iVar1 = FUN_000e79d0(iVar2), iVar1 == 1)) &&
          (iVar1 = FUN_000e920c(iVar2,0), iVar1 == piVar3[0x4f])) &&
         (iVar1 = FUN_000e87e4(piVar3,auStack_28), iVar1 == 0)) {
        piVar3 = (int *)FUN_0012abd8(param_2,piVar3);
      }
    }
    piVar3 = (int *)piVar3[2];
    iVar1 = piVar3[2];
  }
  return;
}

/* FUN_00188fec @ 0x188fec (1280 bytes) */
int FUN_00188fec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int *param_4;
  int param_5;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_38 [8];
  
  uVar2 = 0;
  local_38[0] = 0;
  iVar1 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x1b);
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*param_4 + 100))(param_4);
    iVar1 = FUN_0014abdc(param_4,param_5,local_38);
    if ((iVar1 != 0) &&
       (param_4 = (int *)FUN_00146610(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
    if (((param_2 != 0) &&
        (iVar1 = FUN_00160320(param_2,param_3,param_4,param_5,local_38), iVar1 != 0)) &&
       (param_4 = (int *)FUN_00146610(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
  }
  iVar1 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x1c);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(**(int **)(*(int *)(param_5 + 8) + 0x30c) + 0x84))();
    if (((iVar1 != 0) && (iVar1 = FUN_00154dc0(param_4,param_5), iVar1 != 0)) &&
       (param_4 = (int *)FUN_00146610(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
    iVar1 = FUN_00162cc0(param_4,param_5);
    if ((iVar1 != 0) &&
       (param_4 = (int *)FUN_00146610(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
    iVar1 = (**(code **)(*param_4 + 0x14))(param_4);
    if ((param_3 <= iVar1) && (iVar1 = FUN_00158264(param_2,param_3,param_4,param_5), iVar1 != 0)) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      if (param_4 == (int *)0x0) {
        return 1;
      }
      uVar2 = 1;
    }
    iVar1 = FUN_00155a60(param_4,param_5);
    if (iVar1 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar1 = FUN_0014bdbc(param_4,param_5);
    if (iVar1 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar1 = FUN_0014b82c(param_4,param_5,0,1);
    if (iVar1 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar1 = FUN_0014b150(param_4,param_5);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*param_4 + 100))(param_4);
      if (((iVar1 != 0) && ((param_4[5] & 0x200U) == 0)) && (param_2 != 0)) {
        FUN_00160320(param_2,param_3,param_4,param_5,local_38);
      }
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      if (param_4 == (int *)0x0) {
        return 1;
      }
      uVar2 = 1;
    }
    iVar1 = FUN_00150d38(param_4,param_5);
    if (iVar1 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar1 = FUN_0015ceb0(param_4,param_5);
    if (iVar1 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar1 = FUN_0015bd40(param_4,param_5);
    if (iVar1 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar1 = FUN_00163994(param_4,param_5);
    if (iVar1 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar1 = FUN_0015c6d4(param_4,param_5);
    if (iVar1 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar1 = FUN_0014acb8(param_4,param_5);
    if (iVar1 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar1 = FUN_0015e494(param_4,param_5);
    if (iVar1 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
  }
  iVar1 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x1d);
  if ((((iVar1 != 0) && (iVar1 = FUN_001633f8(param_4,param_5), iVar1 != 0)) &&
      ((iVar1 = (**(code **)(*param_4 + 100))(param_4), iVar1 != 0 &&
       ((param_2 != 0 &&
        (iVar1 = FUN_00160320(param_2,param_3,param_4,param_5,local_38), iVar1 != 0)))))) &&
     (param_4 = (int *)FUN_00146610(param_2,param_3,param_4), param_4 == (int *)0x0)) {
    return 1;
  }
  iVar1 = FUN_000e07dc(*(undefined4 *)(param_5 + 8),0x3a);
  if (iVar1 == 0) {
    return uVar2;
  }
  if ((*(int *)(param_5 + 0x228) < *(int *)(*(int *)(param_5 + 8) + 0x664)) &&
     (iVar1 = FUN_0015ea3c(param_2,param_3,param_4,param_5), iVar1 != 0)) {
    uVar2 = 1;
    param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
  }
  iVar1 = FUN_0015f44c(param_2,param_3,param_4,param_5);
  if (iVar1 != 0) {
    FUN_00146610(param_2,param_3,param_4);
    return 1;
  }
  return uVar2;
}

/* FUN_001894ec @ 0x1894ec (116 bytes) */
int FUN_001894ec(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  if (((*(uint *)(param_2 + 0x14) & 1) != 0) &&
     (iVar1 = FUN_000e07dc(*(undefined4 *)(param_3 + 8),0x15), iVar1 != 0)) {
    FUN_00150b94(param_2,param_3);
    FUN_0014e6e4(param_2,param_3);
    return;
  }
  return;
}

/* FUN_00189560 @ 0x189560 (64 bytes) */
int FUN_00189560(param_1)
  undefined4 *param_1;
{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0;
  param_1[5] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  do {
    bVar1 = iVar2 != 2;
    param_1[6] = 0;
    param_1[9] = 0;
    iVar2 = iVar2 + 1;
    param_1[0xc] = 0;
    param_1 = param_1 + 1;
  } while (bVar1);
  return;
}

/* FUN_001895a0 @ 0x1895a0 (100 bytes) */
int FUN_001895a0(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = *param_2;
  param_1[2] = param_2[2];
  uVar3 = param_2[3];
  *param_1 = uVar4;
  iVar5 = 0;
  param_1[3] = uVar3;
  uVar4 = param_2[1];
  param_1[4] = param_2[4];
  uVar3 = param_2[5];
  param_1[1] = uVar4;
  param_1[5] = uVar3;
  do {
    bVar2 = iVar5 != 2;
    iVar5 = iVar5 + 1;
    param_1[6] = param_2[6];
    puVar1 = param_2 + 9;
    uVar3 = param_2[0xc];
    param_2 = param_2 + 1;
    param_1[9] = *puVar1;
    param_1[0xc] = uVar3;
    param_1 = param_1 + 1;
  } while (bVar2);
  return;
}

/* FUN_00189604 @ 0x189604 (40 bytes) */
int FUN_00189604(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  ((int (*)())FUN_00189560)(param_1 + 0x28);
  return;
}

/* FUN_0018962c @ 0x18962c (52 bytes) */
int FUN_0018962c(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_2 + 0x30))(param_2);
  return uVar1 ^ 1;
}

/* FUN_001896f8 @ 0x1896f8 (108 bytes) */
int FUN_001896f8(param_1)
  uint param_1;
{
  return *(uint *)(&DAT_001b0244 +
                  ((param_1 >> 0x18) * 0x7d + (param_1 >> 0x10 & 0xff) * 0x19 +
                   (param_1 >> 8 & 0xff) * 5 + (param_1 & 0xff)) * 0x10) ==
         ((uint)(byte)DAT_001b2a68 << 0x18 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 2)) << 0x10 |
          (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 1)) << 8 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 0)));
}

/* FUN_0018976c @ 0x18976c (28 bytes) */
int FUN_0018976c(param_1)
  undefined4 param_1;
{
  FUN_000f2d18(param_1,DAT_001b2a64);
  return;
}

/* FUN_00189788 @ 0x189788 (104 bytes) */
int FUN_00189788(param_1)
  undefined4 param_1;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_001b2994;
  do {
    iVar1 = FUN_000f2d18(*puVar2,param_1);
    if (iVar1 != 0) {
      return 1;
    }
    puVar2 = puVar2 + 1;
  } while (puVar2 != (undefined4 *)&UNK_001b29e4);
  return 0;
}

/* FUN_001897fc @ 0x1897fc (68 bytes) */
int FUN_001897fc()
{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_00105594();
  bVar2 = false;
  if (*(int *)(iVar1 + 0x98) == 0x33) {
    bVar2 = *(int *)(iVar1 + 300) != 3;
  }
  return bVar2;
}

/* FUN_00189840 @ 0x189840 (364 bytes) */
int FUN_00189840(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int *param_3;
  int param_4;
  int param_5;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *local_58 [12];
  
  iVar5 = 0;
  do {
    iVar4 = 2;
    piVar7 = param_2;
    do {
      for (iVar6 = 1; iVar2 = (**(code **)(*piVar7 + 0x14))(piVar7), iVar6 <= iVar2;
          iVar6 = iVar6 + 1) {
        piVar1 = (int *)FUN_00105594(piVar7,iVar6);
        iVar2 = (**(code **)(*piVar1 + 0x60))();
        if (iVar2 == 0) {
LAB_001898e0:
          iVar2 = (**(code **)(*piVar1 + 0x48))(piVar1);
          if ((iVar2 != 0) && (piVar1[0x4b] == 3)) {
            if (iVar5 < 1) {
LAB_00189934:
              iVar2 = iVar5 + 1;
              local_58[iVar5] = piVar1;
              iVar5 = iVar2;
              if (param_4 + param_5 < iVar2) {
                return 0;
              }
            }
            else if (local_58[0] != piVar1) {
              iVar3 = 0;
              iVar2 = iVar5;
              do {
                iVar3 = iVar3 + 1;
                iVar2 = iVar2 + -1;
                if (iVar2 == 0) goto LAB_00189934;
              } while (piVar1 != local_58[iVar3]);
            }
          }
        }
        else {
          iVar2 = FUN_0010497c(piVar1,*(undefined4 *)(*(int *)(param_1 + 8) + 0x6c4));
          if (iVar2 != 0) {
            piVar1 = (int *)FUN_00105594(piVar1,1);
            goto LAB_001898e0;
          }
        }
      }
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) {
        return 1;
      }
      piVar7 = param_3;
    } while (iVar4 != 2);
  } while( true );
}

/* FUN_001899ac @ 0x1899ac (568 bytes) */
int FUN_001899ac(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int *param_3;
  undefined4 param_4;
  int param_5;
{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int *local_68 [13];
  
  iVar6 = 0;
  do {
    iVar7 = 0;
    piVar11 = param_2;
    do {
      iVar8 = 1;
      if (piVar11 != (int *)0x0) {
        for (; iVar5 = (**(code **)(*piVar11 + 0x14))(piVar11), iVar8 <= iVar5; iVar8 = iVar8 + 1) {
          piVar3 = (int *)FUN_00105594(piVar11,iVar8);
          iVar4 = (**(code **)(*piVar3 + 0x60))();
          iVar5 = iVar8;
          piVar10 = piVar11;
          if (iVar4 == 0) {
LAB_00189a60:
            iVar4 = (**(code **)(*piVar3 + 0x48))(piVar3);
            if ((iVar4 != 0) && (piVar3[0x4b] == 3)) {
              if (iVar6 < 1) {
                iVar4 = 0;
LAB_00189ab0:
                local_68[iVar6] = piVar3;
                iVar6 = iVar6 + 1;
              }
              else {
                iVar4 = 0;
                iVar9 = iVar6;
                piVar2 = local_68;
                while (piVar3 != piVar2) {
                  iVar4 = iVar4 + 1;
                  iVar9 = iVar9 + -1;
                  if (iVar9 == 0) goto LAB_00189ab0;
                  piVar2 = local_68[iVar4];
                }
              }
              iVar9 = 0;
              if (iVar4 < param_5) {
                do {
                  iVar4 = FUN_001054ec(piVar10,iVar5);
                  if (*(char *)(iVar9 + iVar4 + 0x10) != '\x04') {
                    (**(code **)(*piVar10 + 0x88))(piVar10,iVar5,iVar9,3);
                  }
                  bVar1 = iVar9 != 3;
                  iVar9 = iVar9 + 1;
                } while (bVar1);
                *(undefined1 *)((int)piVar3 + 0x9f) = 0;
              }
              else {
                do {
                  iVar4 = FUN_001054ec(piVar10,iVar5);
                  if (*(char *)(iVar9 + iVar4 + 0x10) != '\x04') {
                    (**(code **)(*piVar10 + 0x88))(piVar10,iVar5,iVar9,0);
                  }
                  bVar1 = iVar9 != 3;
                  iVar9 = iVar9 + 1;
                } while (bVar1);
                *(undefined1 *)(piVar3 + 0x27) = 0;
              }
            }
          }
          else {
            iVar5 = FUN_0010497c(piVar3,*(undefined4 *)(*(int *)(param_1 + 8) + 0x6c4));
            if (iVar5 != 0) {
              piVar2 = (int *)FUN_00105594(piVar3,1);
              iVar5 = 1;
              piVar10 = piVar3;
              piVar3 = piVar2;
              goto LAB_00189a60;
            }
          }
        }
      }
      bVar1 = iVar7 == 1;
      iVar7 = iVar7 + 1;
      if (bVar1) {
        return;
      }
      piVar11 = param_3;
    } while (iVar7 != 0);
  } while( true );
}

/* FUN_00189c24 @ 0x189c24 (188 bytes) */
int FUN_00189c24(param_1)
  int *param_1;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = 0;
  (**(code **)(*param_1 + 0x5c))();
  iVar4 = *(int *)(param_1[0x22] + 8);
  iVar1 = FUN_00105594(param_1,1);
  uVar3 = *(uint *)(iVar1 + 0x94);
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
  if (1 < iVar1) {
    iVar1 = FUN_00105594(param_1,2);
    uVar2 = *(uint *)(iVar1 + 0x94) & 0xfff;
  }
  iVar1 = FUN_001054ec(param_1,0);
  return uVar2 | iVar4 << 0x19 | -(*(byte *)(iVar1 + 0x13) ^ 1) >> 7 & 0x1000000 |
                 (uVar3 & 0xfff) << 0xc;
}

/* FUN_00189ce0 @ 0x189ce0 (276 bytes) */
int FUN_00189ce0(param_1, param_2)
  int *param_1;
  int *param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (**(code **)(*param_1 + 0x5c))();
  if (iVar2 != 0) {
    (**(code **)(*param_2 + 0x5c))(param_2);
  }
  if (*(int *)(param_1[0x22] + 8) == *(int *)(param_2[0x22] + 8)) {
    iVar2 = FUN_001054ec(param_1,0);
    cVar1 = *(char *)(iVar2 + 0x13);
    iVar2 = FUN_001054ec(param_2,0);
    if (cVar1 == *(char *)(iVar2 + 0x13)) {
      iVar2 = FUN_00105594(param_1,1);
      iVar3 = FUN_00105594(param_2,1);
      if (iVar2 == iVar3) {
        iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
        if (1 < iVar2) {
          iVar2 = FUN_00105594(param_1,2);
          iVar3 = FUN_00105594(param_2,2);
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

/* FUN_00189df4 @ 0x189df4 (480 bytes) */
int FUN_00189df4(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int *param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = (**(code **)(*param_1 + 0x28))();
  if ((iVar2 == 0) && (*(int *)(param_1[0x22] + 4) != 1)) {
    iVar4 = *(int *)(param_1[0x22] + 8);
    iVar2 = iVar4;
    if ((iVar4 - 0x1cU < 3) || (iVar4 == 0xa3)) {
      if (((iVar4 == 0x1d) || (iVar4 == 0xa3)) ||
         (iVar4 = FUN_001054ec(param_1,0), *(char *)(iVar4 + 0x13) == '\0')) {
        iVar4 = 0x97;
      }
      else {
        iVar4 = -1;
      }
LAB_00189f70:
      if (iVar2 < 0) goto LAB_00189f94;
LAB_00189f84:
      if (*param_2 < 0) {
        *param_2 = iVar2;
        goto LAB_00189f94;
      }
    }
    else {
      if (((((iVar4 != 0x37) && (iVar4 != 0x3a)) &&
           ((iVar4 != 0x3b && ((iVar4 != 0x3e && (iVar4 != 0x3f)))))) && (iVar4 != 0x40)) &&
         ((((iVar4 != 0x41 && (iVar4 != 0x42)) && (iVar4 != 0x43)) &&
          ((iVar4 != 0x4c && (iVar4 != 0x4d)))))) {
        iVar2 = FUN_001054ec(param_1,0);
        uVar1 = *(uint *)(iVar2 + 0x10);
        if ((uVar1 >> 0x18 == 0) ||
           (((uVar1 >> 0x10 & 0xff) == 0 || (iVar2 = -1, (uVar1 >> 8 & 0xff) == 0)))) {
          iVar2 = iVar4;
        }
        if ((uVar1 & 0xff) != 0) {
          iVar4 = -1;
        }
        goto LAB_00189f70;
      }
      iVar2 = FUN_001054ec(param_1,0);
      uVar1 = *(uint *)(iVar2 + 0x10);
      if (((uVar1 >> 0x18 == 0) || ((uVar1 >> 0x10 & 0xff) == 0)) || ((uVar1 >> 8 & 0xff) == 0)) {
        iVar2 = 0x98;
        goto LAB_00189f84;
      }
LAB_00189f94:
      if (iVar4 < 0) goto LAB_00189fb4;
      if (*param_3 < 0) {
        *param_3 = iVar4;
        return 1;
      }
    }
    uVar3 = 0;
  }
  else {
LAB_00189fb4:
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_00189fd4 @ 0x189fd4 (172 bytes) */
int FUN_00189fd4(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  undefined4 uVar2;
  int local_28;
  int local_24 [7];
  
  local_24[0] = -1;
  local_28 = -1;
  if ((param_2[5] & 0x8000U) == 0) {
    iVar1 = (**(code **)(*param_2 + 0x28))(param_2);
    if (iVar1 == 0) {
      ((int (*)())FUN_00189df4)(param_2,&local_28,local_24);
      if (local_28 < 0) {
        if (-1 < local_24[0]) {
          return 2;
        }
        goto LAB_0018a060;
      }
      if (local_24[0] < 0) {
        return 1;
      }
    }
    uVar2 = 3;
  }
  else {
LAB_0018a060:
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_0018a080 @ 0x18a080 (364 bytes) */
int FUN_0018a080(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = (**(code **)(*param_2 + 0x30))(param_2);
  if (iVar1 != 0) {
    iVar1 = FUN_001054ec(param_2,1);
    uVar2 = ((int (*)())FUN_0018976c)(*(undefined4 *)(iVar1 + 0x10));
    return uVar2;
  }
  iVar4 = 1;
  iVar1 = (**(code **)(*param_2 + 0x5c))(param_2);
  if (iVar1 == 0) {
    for (; iVar1 = (**(code **)(*param_2 + 0x14))(param_2), iVar4 <= iVar1; iVar4 = iVar4 + 1) {
      iVar1 = FUN_001054ec(param_2,iVar4);
      uVar2 = *(undefined4 *)(iVar1 + 0x10);
      piVar3 = (int *)FUN_00105594(param_2,iVar4);
      iVar1 = (**(code **)(*piVar3 + 0x5c))();
      if (iVar1 == 0) {
        iVar1 = ((int (*)())FUN_001896f8)(uVar2);
      }
      else {
        iVar1 = ((int (*)())FUN_00189788)(uVar2);
      }
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  else {
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar1 != 1) {
      iVar1 = FUN_001054ec(param_2,1);
      iVar4 = *(int *)(iVar1 + 0x10);
      iVar1 = FUN_001054ec(param_2,2);
      if (iVar4 != *(int *)(iVar1 + 0x10)) {
        return 0;
      }
    }
  }
  return 1;
}

/* FUN_0018a1ec @ 0x18a1ec (596 bytes) */
int FUN_0018a1ec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int *param_2;
  int param_3;
  int param_4;
  int *param_5;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  *param_5 = 0;
  iVar2 = FUN_001054ec(param_2,param_3);
  uVar5 = *(uint *)(iVar2 + 0x10);
  iVar2 = (**(code **)(*param_2 + 0x28))(param_2);
  if (iVar2 == 0) {
    iVar2 = (**(code **)(*param_2 + 0x5c))(param_2);
    if (iVar2 != 0) {
      iVar2 = FUN_000f31e8(param_2,1);
      if (iVar2 == 0) {
        return;
      }
      iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
      if (iVar2 == 1) {
        return;
      }
      FUN_000f31e8(param_2,2);
      return;
    }
    piVar3 = (int *)FUN_00105594(param_2,param_3);
    iVar2 = (**(code **)(*piVar3 + 0x5c))();
    if (iVar2 == 0) {
      iVar2 = ((int (*)())FUN_001896f8)(uVar5);
    }
    else {
      iVar2 = ((int (*)())FUN_00189788)(uVar5);
    }
  }
  else {
    if (param_3 != 1) {
      return;
    }
    iVar2 = ((int (*)())FUN_0018976c)(uVar5);
  }
  if (iVar2 == 0) {
    iVar2 = ((uVar5 >> 0x18) * 0x7d + (uVar5 >> 0x10 & 0xff) * 0x19 + (uVar5 >> 8 & 0xff) * 5 +
            (uVar5 & 0xff)) * 4;
    if (((uint)(byte)DAT_001b2a68 << 0x18 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 2)) << 0x10 |
         (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 1)) << 8 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 0))) !=
        *(uint *)(&DAT_001b0240 + (iVar2 + *param_5) * 4)) {
      do {
        uVar4 = *(uint *)(&DAT_001b0240 + (iVar2 + *param_5) * 4);
        *(uint *)(*param_5 * 4 + param_4) =
             uVar4 << 0x18 | (uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 | uVar4 >> 0x18;
        iVar1 = *param_5;
        *param_5 = iVar1 + 1;
      } while (*(uint *)(&DAT_001b0240 + (iVar2 + iVar1 + 1) * 4) !=
               ((uint)(byte)DAT_001b2a68 << 0x18 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 2)) << 0x10 |
                (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 1)) << 8 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 0))));
    }
    if (uVar5 >> 0x18 != 4) {
      uVar5 = uVar5 & 0xffffff;
    }
    if ((uVar5 >> 0x10 & 0xff) != 4) {
      uVar5 = uVar5 & 0xff00ffff | 0x10000;
    }
    if ((uVar5 >> 8 & 0xff) != 4) {
      uVar5 = uVar5 & 0xffff00ff | 0x200;
    }
    if ((uVar5 & 0xff) != 4) {
      uVar5 = uVar5 & 0xffffff00 | 3;
    }
    iVar2 = FUN_001054ec(param_2,param_3);
    *(uint *)(iVar2 + 0x10) = uVar5;
  }
  return;
}

/* FUN_0018a440 @ 0x18a440 (2212 bytes) */
int FUN_0018a440(param_1, param_2)
  int *param_1;
  int param_2;
{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  void *pvVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  int iVar16;
  undefined4 uVar17;
  uint uVar18;
  int iVar19;
  double dVar20;
  undefined4 local_78;
  int local_74 [3];
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  int local_5c;
  int local_58;
  
  iVar14 = *(int *)(param_2 + 900);
  if (*(int *)(iVar14 + 8) != 0) {
    local_5c = 0x18a450;
    local_58 = 0x18a450;
    do {
      uVar17 = *(undefined4 *)(param_1[2] + 0x378);
      puVar5 = (undefined4 *)FUN_00193e18(uVar17,0x1c);
      puVar15 = puVar5 + 1;
      *puVar5 = uVar17;
      puVar5[4] = local_5c + -0x770;
      uVar3 = 1;
      iVar19 = 0x20;
      puVar5[1] = 1;
      puVar5[5] = local_58 + -0x82c;
      puVar5[6] = uVar17;
      do {
        uVar3 = uVar3 << 1;
        if (0xf < uVar3) break;
        iVar19 = iVar19 + -1;
      } while (iVar19 != 0);
      *puVar15 = uVar3;
      puVar5[2] = 0;
      pvVar6 = (void *)FUN_00193e18(uVar17,*puVar15 << 2);
      puVar5[3] = pvVar6;
      _memset(pvVar6,0,*puVar15 << 2);
      piVar2 = *(int **)(iVar14 + 0x98);
      for (piVar4 = (int *)(*(int **)(iVar14 + 0x98))[2]; piVar4 != (int *)0x0;
          piVar4 = (int *)piVar4[2]) {
        if ((piVar2[5] & 1U) != 0) {
          if ((*(int *)(piVar2[0x22] + 8) == 0x31) || (*(int *)(piVar2[0x22] + 8) == 0x30)) {
            piVar4 = (int *)FUN_00105594(piVar2,1);
            iVar19 = (**(code **)(*piVar4 + 0x5c))();
            if ((iVar19 != 0) && ((piVar2[0x2e] & 2U) == 0)) {
              piVar4 = (int *)FUN_00105594(piVar2,1);
              iVar19 = piVar2[0x49];
              if (*(int *)(piVar4[0x22] + 8) == 0x99) {
                iVar19 = iVar19 + 1;
              }
              iVar16 = (**(code **)(**(int **)(param_1[2] + 0x30c) + 0xfc))
                                 (*(int **)(param_1[2] + 0x30c),iVar19,0);
              if (iVar16 != 0) {
                iVar10 = piVar2[1];
                iVar9 = 0;
                iVar11 = piVar2[0x25];
                iVar12 = piVar2[0x26];
                iVar16 = FUN_001054ec(piVar2,0);
                iVar13 = *(int *)(iVar16 + 0x10);
                iVar16 = FUN_001054ec(piVar2,1);
                uVar18 = piVar2[5];
                uVar3 = piVar2[0x2e] & 1;
                uVar17 = *(undefined4 *)(iVar16 + 0x10);
                iVar16 = piVar2[0x48];
                if ((uVar18 & 0x200) != 0) {
                  iVar9 = FUN_00105594(piVar2,piVar2[0x21]);
                }
                FUN_0019401c(piVar2);
                FUN_00108174(piVar2,0x12,*(undefined4 *)(param_2 + 8));
                piVar2[0x27] = iVar13;
                piVar2[0x48] = iVar16;
                piVar2[0x49] = iVar19;
                piVar2[0x25] = iVar11;
                piVar2[0x26] = iVar12;
                if ((uVar18 & 0x40) == 0) {
                  piVar2[5] = piVar2[5] & 0xffffffbf;
                }
                else {
                  piVar2[5] = piVar2[5] | 0x40;
                }
                if ((uVar18 & 2) != 0) {
                  FUN_0010469c(piVar2,*(undefined4 *)(param_1[2] + 0x6c4),iVar12,iVar11);
                }
                if (iVar9 != 0) {
                  FUN_00106804(piVar2,iVar9,0,param_1[2]);
                }
                FUN_000e7738(iVar14,iVar10,piVar2);
                iVar19 = *(int *)(piVar4[0x22] + 8);
                if (iVar19 == 0x9a) {
                  uVar7 = FUN_00105594(piVar4,1);
                  FUN_00106004(piVar2,1,uVar7,0,param_1[2]);
                  uVar7 = FUN_00105594(piVar4,2);
                  FUN_00106004(piVar2,2,uVar7,0,param_1[2]);
                  iVar19 = FUN_001054ec(piVar2,1);
                  *(undefined4 *)(iVar19 + 0x10) = uVar17;
                  iVar19 = FUN_001054ec(piVar2,2);
                  *(undefined4 *)(iVar19 + 0x10) = uVar17;
                  FUN_00103d50(piVar2 + 0x29,1,uVar3);
                  FUN_00103d50(piVar2 + 0x2f,1,uVar3 ^ 1);
                }
                else {
                  if (iVar19 < 0x9b) {
                    if (iVar19 != 0x99) goto LAB_0018a910;
                    uVar7 = FUN_00105594(piVar4,1);
                    FUN_00106004(piVar2,1,uVar7,0,param_1[2]);
                    dVar20 = (double)FLOAT_001aa10c;
                    FUN_000f79c4(dVar20,dVar20,dVar20,dVar20,piVar2,param_2,2);
                    iVar19 = FUN_001054ec(piVar2,1);
                    *(undefined4 *)(iVar19 + 0x10) = uVar17;
                    uVar18 = uVar3 ^ 1;
                  }
                  else if (iVar19 == 0x9b) {
                    uVar7 = FUN_00105594(piVar4,1);
                    FUN_00106004(piVar2,1,uVar7,0,param_1[2]);
                    uVar7 = FUN_00105594(piVar4,2);
                    FUN_00106004(piVar2,2,uVar7,0,param_1[2]);
                    iVar19 = FUN_001054ec(piVar2,1);
                    *(undefined4 *)(iVar19 + 0x10) = uVar17;
                    iVar19 = FUN_001054ec(piVar2,2);
                    *(undefined4 *)(iVar19 + 0x10) = uVar17;
                    uVar18 = uVar3;
                  }
                  else {
                    if (iVar19 != 0x9c) goto LAB_0018a910;
                    uVar7 = FUN_00105594(piVar4,1);
                    FUN_00106004(piVar2,1,uVar7,0,param_1[2]);
                    dVar20 = (double)FLOAT_001aa0e8;
                    FUN_000f79c4(dVar20,dVar20,dVar20,dVar20,piVar2,param_2,2);
                    iVar19 = FUN_001054ec(piVar2,1);
                    *(undefined4 *)(iVar19 + 0x10) = uVar17;
                    uVar18 = uVar3 ^ 1;
                  }
                  FUN_00103d50(piVar2 + 0x29,1,uVar18);
                  FUN_00103d50(piVar2 + 0x2f,1,uVar3);
                }
LAB_0018a910:
                (**(code **)(*piVar4 + 0xc))(piVar4,0,param_1[2]);
                piVar4 = (int *)piVar2[2];
                goto LAB_0018aab8;
              }
            }
          }
          for (iVar19 = 1; iVar16 = (**(code **)(*piVar2 + 0x14))(piVar2), iVar19 <= iVar16;
              iVar19 = iVar19 + 1) {
            piVar4 = (int *)FUN_00105594(piVar2,iVar19);
            iVar16 = (**(code **)(*piVar4 + 0x5c))();
            if (iVar16 != 0) {
              piVar8 = (int *)FUN_00194834(puVar15,piVar4);
              if (piVar8 == (int *)0x0) {
                FUN_00194d44(puVar15,piVar4);
              }
              else if (piVar4 != piVar8) {
                iVar16 = FUN_001054ec(piVar8,0);
                local_74[0] = *(int *)(iVar16 + 0x10);
                iVar10 = FUN_001054ec(piVar4,0);
                iVar16 = DAT_001b2a64;
                iVar9 = 0;
                local_78 = *(undefined4 *)(iVar10 + 0x10);
                iVar10 = 4;
                do {
                  cVar1 = *(char *)((int)local_74 + iVar9 + -4);
                  if (cVar1 != '\x01') {
                    *(char *)((int)local_74 + iVar9) = cVar1;
                  }
                  iVar9 = iVar9 + 1;
                  iVar10 = iVar10 + -1;
                } while (iVar10 != 0);
                piVar8[0x27] = local_74[0];
                FUN_000f3908(&local_68,local_74[0]);
                FUN_000f3340(&local_64,iVar16,local_68);
                uVar17 = local_64;
                iVar16 = FUN_001054ec(piVar8,1);
                *(undefined4 *)(iVar16 + 0x10) = uVar17;
                iVar16 = (**(code **)(*piVar8 + 0x14))(piVar8);
                if (1 < iVar16) {
                  iVar16 = FUN_001054ec(piVar8,2);
                  *(undefined4 *)(iVar16 + 0x10) = uVar17;
                }
                FUN_00106004(piVar2,iVar19,piVar8,0,param_1[2]);
                (**(code **)(*piVar4 + 0xc))(piVar4,0,param_1[2]);
              }
            }
          }
          piVar4 = (int *)piVar2[2];
        }
LAB_0018aab8:
        piVar2 = piVar4;
      }
      if (puVar15 != (uint *)0x0) {
        uVar3 = *puVar15;
        if (uVar3 == 0) {
          iVar19 = puVar5[3];
        }
        else {
          iVar19 = puVar5[3];
          uVar18 = 0;
          do {
            if (*(int *)(uVar18 * 4 + iVar19) != 0) {
              FUN_00193cc0(puVar5[6]);
              uVar3 = *puVar15;
              iVar19 = puVar5[3];
            }
            uVar18 = uVar18 + 1;
          } while (uVar18 < uVar3);
        }
        FUN_00193cc0(puVar5[6],iVar19);
        FUN_00193cc0(*puVar5,puVar5);
      }
      piVar2 = *(int **)(iVar14 + 0x98);
      for (piVar4 = (int *)(*(int **)(iVar14 + 0x98))[2]; piVar4 != (int *)0x0;
          piVar4 = (int *)piVar4[2]) {
        if ((piVar2[5] & 1U) != 0) {
          iVar16 = 1;
          iVar19 = FUN_000e07dc(param_1[2],0x41);
          if (iVar19 != 0) {
            for (; iVar19 = (**(code **)(*piVar2 + 0x14))(piVar2), iVar16 <= iVar19;
                iVar16 = iVar16 + 1) {
              piVar4 = (int *)FUN_00105594(piVar2,iVar16);
              iVar19 = (**(code **)(*piVar4 + 0x80))();
              iVar9 = FUN_001054ec(piVar2,iVar16);
              FUN_000f39d0(&local_60,*(undefined4 *)(iVar9 + 0x10));
              uVar3 = local_60;
              iVar9 = FUN_001054ec(piVar2,iVar16);
              uVar18 = *(uint *)(iVar9 + 0x10);
              if ((((iVar19 != 0) &&
                   (((iVar10 = FUN_001054ec(iVar19,0), iVar9 = _UNK_001b2a7c,
                     *(char *)(iVar10 + 0x12) == '\x01' ||
                     (*(int *)(iVar19 + 0xb4) == _UNK_001b2a7c)) && ((uVar3 >> 8 & 0xff) != 0)))) &&
                  ((uVar18 >> 8 & 0xff) == 3)) &&
                 (((uVar3 >> 0x18 != 0 && (uVar18 >> 0x18 == 0)) ||
                  (((uVar3 >> 0x10 & 0xff) != 0 && ((uVar18 >> 0x10 & 0xff) == 1)))))) {
                *(undefined1 *)(iVar19 + 0xe) = 1;
                *(int *)(iVar19 + 0xb4) = iVar9;
                *(undefined1 *)(iVar19 + 0x9e) = 0;
                iVar19 = DAT_001b2a64;
                if (iVar16 == 0) {
                  piVar2[0x27] = DAT_001b2a64;
                }
                else {
                  iVar9 = FUN_001054ec(piVar2,iVar16);
                  *(int *)(iVar9 + 0x10) = iVar19;
                }
              }
            }
          }
          if (*(int *)(piVar2[0x22] + 8) == 0x8e) {
            piVar4 = (int *)piVar2[2];
          }
          else {
            (**(code **)(*param_1 + 0x6c))(param_1,piVar2);
            piVar4 = (int *)piVar2[2];
          }
        }
        piVar2 = piVar4;
      }
      iVar14 = *(int *)(iVar14 + 8);
    } while (*(int *)(iVar14 + 8) != 0);
  }
  return;
}

/* FUN_0018ad08 @ 0x18ad08 (1204 bytes) */
int FUN_0018ad08(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int *param_3;
  undefined4 *param_4;
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0x88) + 8);
  if (iVar1 == 0x1c) {
    piVar2 = (int *)FUN_001043f0(0x13,param_1[2]);
    iVar1 = DAT_001b2a70;
    piVar2[0x25] = piVar2[0x53];
    piVar2[0x27] = iVar1;
    piVar2[0x26] = 0;
    *param_4 = 3;
    uVar3 = FUN_001054ec(param_2,1);
    FUN_001062c0(piVar2,1,uVar3,param_1[2]);
    uVar3 = FUN_001054ec(param_2,2);
    FUN_001062c0(piVar2,2,uVar3,param_1[2]);
    piVar2[3] = 0;
    uVar3 = DAT_001b2a68;
    *(undefined1 *)((int)piVar2 + 0xf) = 1;
    *param_3 = 2;
    do {
      iVar1 = FUN_001054ec(piVar2,1);
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      iVar5 = *param_3;
      pcVar4 = *(code **)(*piVar2 + 0x88);
      iVar1 = FUN_001054ec(param_2,1);
      (*pcVar4)(piVar2,1,3,*(undefined1 *)(iVar5 + iVar1 + 0x10));
      iVar1 = FUN_001054ec(piVar2,2);
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      iVar5 = *param_3;
      pcVar4 = *(code **)(*piVar2 + 0x88);
      iVar1 = FUN_001054ec(param_2,2);
      (*pcVar4)(piVar2,2,3,*(undefined1 *)(iVar5 + iVar1 + 0x10));
      iVar1 = (**(code **)(*param_1 + 0xc))(param_1,piVar2);
      if (iVar1 != 0) {
        return piVar2;
      }
    } while (((*(uint *)(*(int *)(param_1[2] + 0x30c) + 8) & 0x400) != 0) &&
            (iVar1 = *param_3, *param_3 = iVar1 + -1, -1 < iVar1 + -1));
  }
  else {
    if (iVar1 != 0x1e) {
      if (iVar1 != 0x1d) {
        return (int *)0x0;
      }
      piVar2 = (int *)FUN_001043f0(0x1c,param_1[2]);
      iVar1 = DAT_001b2a6c;
      piVar2[0x25] = piVar2[0x53];
      piVar2[0x27] = iVar1;
      piVar2[0x26] = 0;
      *param_4 = 1;
      *param_3 = 3;
      uVar3 = FUN_001054ec(param_2,1);
      FUN_001062c0(piVar2,1,uVar3,param_1[2]);
      uVar3 = FUN_001054ec(param_2,2);
      FUN_001062c0(piVar2,2,uVar3,param_1[2]);
      (**(code **)(*piVar2 + 0x88))(piVar2,1,3,4);
      (**(code **)(*piVar2 + 0x88))(piVar2,2,3,4);
      piVar2[3] = 0;
      *(undefined1 *)(piVar2 + 3) = 1;
      iVar1 = (**(code **)(*param_1 + 0xc))(param_1,piVar2);
      if (iVar1 != 0) {
        return piVar2;
      }
      iVar1 = *piVar2;
      goto LAB_0018b190;
    }
    piVar2 = (int *)FUN_001043f0(0x14,param_1[2]);
    iVar1 = DAT_001b2a70;
    piVar2[0x25] = piVar2[0x53];
    piVar2[0x27] = iVar1;
    piVar2[0x26] = 0;
    *param_4 = 3;
    uVar3 = FUN_001054ec(param_2,1);
    FUN_001062c0(piVar2,1,uVar3,param_1[2]);
    uVar3 = FUN_001054ec(param_2,2);
    FUN_001062c0(piVar2,2,uVar3,param_1[2]);
    uVar3 = FUN_001054ec(param_2,3);
    FUN_001062c0(piVar2,3,uVar3,param_1[2]);
    piVar2[3] = 0;
    uVar3 = DAT_001b2a68;
    *(undefined1 *)((int)piVar2 + 0xf) = 1;
    *param_3 = 1;
    do {
      iVar1 = FUN_001054ec(piVar2,1);
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      iVar5 = *param_3;
      pcVar4 = *(code **)(*piVar2 + 0x88);
      iVar1 = FUN_001054ec(param_2,1);
      (*pcVar4)(piVar2,1,3,*(undefined1 *)(iVar5 + iVar1 + 0x10));
      iVar1 = FUN_001054ec(piVar2,2);
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      iVar5 = *param_3;
      pcVar4 = *(code **)(*piVar2 + 0x88);
      iVar1 = FUN_001054ec(param_2,2);
      (*pcVar4)(piVar2,2,3,*(undefined1 *)(iVar5 + iVar1 + 0x10));
      iVar1 = FUN_001054ec(piVar2,3);
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      pcVar4 = *(code **)(*piVar2 + 0x88);
      iVar1 = FUN_001054ec(param_2,3);
      (*pcVar4)(piVar2,3,3,*(undefined1 *)(iVar1 + 0x12));
      iVar1 = (**(code **)(*param_1 + 0xc))(param_1,piVar2);
      if (iVar1 != 0) {
        return piVar2;
      }
      iVar1 = *param_3;
      *param_3 = iVar1 + -1;
    } while (-1 < iVar1 + -1);
  }
  iVar1 = *piVar2;
LAB_0018b190:
  (**(code **)(iVar1 + 4))(piVar2);
  return (int *)0x0;
}

/* FUN_0018b1bc @ 0x18b1bc (1176 bytes) */
int FUN_0018b1bc(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  
  bVar1 = param_3 <= param_4;
  if (bVar1) {
    puVar3 = (undefined4 *)(param_3 * 4 + param_2 + 0x48);
    iVar10 = param_3;
    do {
      iVar10 = iVar10 + 1;
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    } while (iVar10 <= param_4);
  }
  puVar15 = *(uint **)(param_2 + 0x40);
  uVar14 = 0;
  uVar12 = puVar15[1];
  if (0 < (int)uVar12) {
    while( true ) {
      if (uVar14 < *puVar15) {
        uVar5 = puVar15[1];
        if (uVar5 <= uVar14) {
          _memset((void *)(uVar5 * 4 + puVar15[2]),0,(uVar14 - uVar5) * 4 + 4);
          puVar15[1] = uVar14 + 1;
        }
        piVar6 = (int *)(uVar14 * 4 + puVar15[2]);
      }
      else {
        piVar6 = (int *)FUN_0019423c(puVar15,uVar14);
      }
      uVar14 = uVar14 + 1;
      iVar10 = *piVar6;
      if (*(int *)(iVar10 + 8) == 0) {
        if (bVar1) {
          puVar4 = (undefined1 *)(param_3 + iVar10 + 0x18);
          iVar11 = param_3;
          do {
            iVar11 = iVar11 + 1;
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
          } while (iVar11 <= param_4);
        }
        *(undefined1 *)(param_5 + iVar10 + 0x18) = 1;
        iVar11 = param_5 * 4 + param_2;
        *(int *)(iVar11 + 0x48) = *(int *)(iVar11 + 0x48) + 1;
        iVar11 = *(int *)(iVar10 + 4);
        piVar6 = *(int **)(iVar11 + 0x38);
        if ((piVar6[5] & 0x200U) != 0) {
          FUN_00105594(piVar6,piVar6[0x21]);
        }
        (**(code **)(*piVar6 + 0x28))(piVar6);
        iVar7 = (**(code **)(*piVar6 + 0x5c))(piVar6);
        if (iVar7 == 0) {
          piVar9 = (int *)FUN_00105594(piVar6,*(undefined4 *)(iVar10 + 0x10));
          iVar11 = (**(code **)(*piVar9 + 0x60))();
          if (iVar11 == 0) {
            iVar11 = 0;
            do {
              iVar7 = FUN_001054ec(piVar6,*(undefined4 *)(iVar10 + 0x10));
              uVar5 = (uint)*(byte *)(iVar11 + iVar7 + 0x10);
              if ((param_3 <= (int)uVar5) && ((int)uVar5 <= param_4)) {
                (**(code **)(*piVar6 + 0x88))(piVar6,*(undefined4 *)(iVar10 + 0x10),iVar11,param_5);
              }
              bVar2 = iVar11 != 3;
              iVar11 = iVar11 + 1;
            } while (bVar2);
          }
        }
        else {
          iVar10 = (**(code **)(*piVar6 + 0x14))(piVar6);
          if (1 < iVar10) {
            FUN_00105594(piVar6,1);
            FUN_00105594(piVar6,2);
          }
          if (bVar1) {
            puVar4 = (undefined1 *)((int)piVar6 + param_3 + 0xc);
            iVar10 = param_3;
            do {
              puVar4[0x90] = 1;
              iVar7 = *piVar6;
              *puVar4 = 0;
              (**(code **)(iVar7 + 0x88))(piVar6,1,iVar10,4);
              iVar7 = (**(code **)(*piVar6 + 0x14))(piVar6);
              if (iVar7 == 2) {
                (**(code **)(*piVar6 + 0x88))(piVar6,2,iVar10,4);
              }
              iVar10 = iVar10 + 1;
              puVar4 = puVar4 + 1;
            } while (iVar10 <= param_4);
          }
          *(undefined1 *)((int)piVar6 + param_5 + 0x9c) = 0;
          iVar10 = *piVar6;
          *(undefined1 *)((int)piVar6 + param_5 + 0xc) = 1;
          (**(code **)(iVar10 + 0x88))(piVar6,1,param_5,param_5);
          iVar10 = (**(code **)(*piVar6 + 0x14))(piVar6);
          if (iVar10 == 2) {
            (**(code **)(*piVar6 + 0x88))(piVar6,2,param_5,param_5);
          }
          if (bVar1) {
            puVar3 = (undefined4 *)(param_3 * 4 + iVar11 + 0x48);
            iVar10 = param_3;
            do {
              iVar10 = iVar10 + 1;
              *puVar3 = 0;
              puVar3 = puVar3 + 1;
            } while (iVar10 <= param_4);
          }
          puVar15 = *(uint **)(iVar11 + 0x40);
          uVar5 = 0;
          uVar13 = puVar15[1];
          if (0 < (int)uVar13) {
            while( true ) {
              if (uVar5 < *puVar15) {
                uVar8 = puVar15[1];
                if (uVar8 <= uVar5) {
                  _memset((void *)(uVar8 * 4 + puVar15[2]),0,(uVar5 - uVar8) * 4 + 4);
                  puVar15[1] = uVar5 + 1;
                }
                piVar6 = (int *)(uVar5 * 4 + puVar15[2]);
              }
              else {
                piVar6 = (int *)FUN_0019423c(puVar15,uVar5);
              }
              uVar5 = uVar5 + 1;
              iVar10 = *piVar6;
              if (*(int *)(iVar10 + 8) == 0) {
                if (bVar1) {
                  puVar4 = (undefined1 *)(param_3 + iVar10 + 0x18);
                  iVar7 = param_3;
                  do {
                    iVar7 = iVar7 + 1;
                    *puVar4 = 0;
                    puVar4 = puVar4 + 1;
                  } while (iVar7 <= param_4);
                }
                *(undefined1 *)(param_5 + iVar10 + 0x18) = 1;
                iVar10 = param_5 * 4 + iVar11;
                *(int *)(iVar10 + 0x48) = *(int *)(iVar10 + 0x48) + 1;
              }
              if (uVar13 == uVar5) break;
              puVar15 = *(uint **)(iVar11 + 0x40);
            }
          }
        }
      }
      if (uVar12 == uVar14) break;
      puVar15 = *(uint **)(param_2 + 0x40);
    }
  }
  return;
}

/* FUN_0018b654 @ 0x18b654 (888 bytes) */
int FUN_0018b654(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined4 local_48;
  
  pbVar6 = *(byte **)(param_2 + 0x60);
  local_48 = DAT_001b2a78;
  if (pbVar6 != (byte *)0x0) {
    uVar3 = (DAT_001b2a78 << 0x18 | (DAT_001b2a78 >> 8 & 0xff) << 0x10 |
             (DAT_001b2a78 >> 0x10 & 0xff) << 8 | DAT_001b2a78 >> 0x18) -
            ((uint)pbVar6[3] << 0x18 | (uint)pbVar6[2] << 0x10 | (uint)pbVar6[1] << 8 |
            (uint)*pbVar6);
    local_48 = uVar3 * 0x1000000 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
    iVar4 = *(int *)(*(int *)(param_2 + 0x60) + 4);
    if (-1 < iVar4) {
      iVar9 = 4;
      iVar7 = 0;
      do {
        iVar5 = *(int *)(iVar4 * 4 + *(int *)(param_3 + iVar7 * 4));
        if ((iVar5 != 0) && (*(int *)(iVar7 * 4 + iVar5 + 0x48) != 0)) {
          *(undefined1 *)((int)&local_48 + iVar7) = 0;
        }
        iVar7 = iVar7 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  if (local_48 == DAT_001b2a74) {
    return 0;
  }
  piVar8 = *(int **)(param_2 + 0x38);
  FUN_000f3a30(piVar8);
  iVar4 = FUN_001054ec(piVar8,0);
  if (*(char *)(iVar4 + 0x13) == '\0') {
    if (local_48 == DAT_001b2a78) {
      iVar7 = param_1[0x1a];
      param_1[0x1a] = iVar7 + 1;
      if (2 < iVar7 + 1) {
        param_1[0x1a] = 0;
      }
    }
    else {
      iVar7 = 0;
      while (*(char *)((int)&local_48 + iVar7) == '\0') {
        bVar1 = iVar7 == 2;
        iVar7 = iVar7 + 1;
        if (bVar1) {
          return 0;
        }
      }
    }
    if (iVar7 == -1) {
      return 0;
    }
    iVar4 = 3;
  }
  else {
    if ((char)local_48 == '\0') {
      return 0;
    }
    iVar4 = FUN_001054ec(piVar8,0);
    iVar7 = 3;
    iVar4 = FUN_000f30d4(*(undefined4 *)(iVar4 + 0x10));
  }
  *(undefined1 *)((int)piVar8 + iVar4 + 0x9c) = 1;
  *(undefined1 *)((int)piVar8 + iVar4 + 0xc) = 0;
  iVar5 = 1;
  *(undefined1 *)((int)piVar8 + iVar7 + 0x9c) = 0;
  iVar9 = piVar8[0x22];
  *(undefined1 *)((int)piVar8 + iVar7 + 0xc) = 1;
  if (*(int *)(PTR_DAT_001e913c + *(int *)(iVar9 + 8) * 0x38 + 0x34) == 0) {
    for (; iVar9 = (**(code **)(*piVar8 + 0x14))(piVar8), iVar5 <= iVar9; iVar5 = iVar5 + 1) {
      iVar9 = FUN_001054ec(piVar8,iVar5);
      uVar2 = *(undefined1 *)(iVar4 + iVar9 + 0x10);
      (**(code **)(*piVar8 + 0x88))(piVar8,iVar5,iVar4,4);
      (**(code **)(*piVar8 + 0x88))(piVar8,iVar5,iVar7,uVar2);
    }
  }
  iVar9 = (**(code **)(*param_1 + 0xc))(param_1,*(undefined4 *)(param_2 + 0x38));
  if (iVar9 == 0) {
    *(undefined1 *)((int)piVar8 + iVar4 + 0x9c) = 0;
    *(undefined1 *)((int)piVar8 + iVar4 + 0xc) = 1;
    iVar5 = 1;
    *(undefined1 *)((int)piVar8 + iVar7 + 0x9c) = 1;
    iVar9 = piVar8[0x22];
    *(undefined1 *)((int)piVar8 + iVar7 + 0xc) = 0;
    if (*(int *)(PTR_DAT_001e913c + *(int *)(iVar9 + 8) * 0x38 + 0x34) == 0) {
      for (; iVar9 = (**(code **)(*piVar8 + 0x14))(piVar8), iVar5 <= iVar9; iVar5 = iVar5 + 1) {
        iVar9 = FUN_001054ec(piVar8,iVar5);
        uVar2 = *(undefined1 *)(iVar7 + iVar9 + 0x10);
        (**(code **)(*piVar8 + 0x88))(piVar8,iVar5,iVar7,4);
        (**(code **)(*piVar8 + 0x88))(piVar8,iVar5,iVar4,uVar2);
      }
    }
    return 0;
  }
  *(uint *)(param_2 + 0x58) = (iVar7 == 3) + 1;
  if (*(int *)(param_2 + 0x60) != 0) {
    *(undefined1 *)(*(int *)(param_2 + 0x60) + iVar7) = 1;
  }
  ((int (*)())FUN_0018b1bc)(param_1,param_2,iVar4,iVar4,iVar7);
  return 1;
}

/* FUN_0018b9cc @ 0x18b9cc (712 bytes) */
int FUN_0018b9cc(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined1 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  
  piVar10 = *(int **)(param_2 + 0x38);
  if ((piVar10[0x20] == 0) || (iVar4 = FUN_00126760(piVar10[0x26]), iVar4 == 0)) {
    uVar2 = piVar10[5];
  }
  else {
    uVar2 = piVar10[5];
    if ((uVar2 & 2) == 0) {
      (**(code **)(*piVar10 + 0x50))(piVar10);
      uVar2 = piVar10[5];
    }
  }
  if (((uVar2 & 2) == 0) && (iVar4 = (**(code **)(*piVar10 + 0x5c))(piVar10), iVar4 == 0)) {
    (**(code **)(*piVar10 + 0x28))(piVar10);
  }
  iVar8 = *(int *)(PTR_DAT_001e913c + *(int *)(piVar10[0x22] + 8) * 0x38 + 0x34);
  iVar4 = FUN_001054ec(piVar10,0);
  if (*(char *)(iVar4 + 0x13) == '\0') {
    if ((iVar8 == 0) && (iVar4 = FUN_000f3a30(piVar10), 1 < iVar4)) {
      iVar4 = FUN_001054ec(piVar10,0);
      iVar7 = 3;
      iVar9 = FUN_000f3108(*(undefined4 *)(iVar4 + 0x10));
      iVar4 = 3;
    }
    else {
      iVar9 = *(int *)(param_1 + 0x68);
      *(int *)(param_1 + 0x68) = iVar9 + 1;
      if (iVar9 + 1 < 3) {
        iVar7 = 3;
        iVar4 = 3;
      }
      else {
        iVar7 = 3;
        *(undefined4 *)(param_1 + 0x68) = 0;
        iVar4 = 3;
      }
    }
  }
  else if (iVar8 == 5) {
    iVar7 = 0;
    iVar9 = 3;
    iVar4 = 2;
  }
  else {
    iVar4 = FUN_001054ec(piVar10,0);
    iVar9 = 3;
    iVar7 = FUN_000f30d4(*(undefined4 *)(iVar4 + 0x10));
    iVar4 = iVar7;
  }
  puVar3 = (undefined1 *)((int)piVar10 + iVar7 + 0xc);
  iVar6 = iVar7;
  do {
    iVar6 = iVar6 + 1;
    puVar3[0x90] = 1;
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  } while (iVar6 <= iVar4);
  *(undefined1 *)((int)piVar10 + iVar9 + 0xc) = 1;
  *(undefined1 *)((int)piVar10 + iVar9 + 0x9c) = 0;
  *(uint *)(param_2 + 0x58) = (iVar9 == 3) + 1;
  if (((iVar8 - 1U < 2) || (iVar8 == 5)) || (iVar6 = 1, iVar7 != iVar4)) {
    *(undefined4 *)(param_2 + 0x5c) = 0;
  }
  else {
    for (; iVar5 = (**(code **)(*piVar10 + 0x14))(piVar10), iVar6 <= iVar5; iVar6 = iVar6 + 1) {
      iVar5 = FUN_001054ec(piVar10,iVar6);
      uVar1 = *(undefined1 *)(iVar7 + iVar5 + 0x10);
      (**(code **)(*piVar10 + 0x88))(piVar10,iVar6,iVar7,4);
      (**(code **)(*piVar10 + 0x88))(piVar10,iVar6,iVar9,uVar1);
    }
    if ((iVar8 == 0) && (iVar8 = FUN_000f3a30(piVar10), 1 < iVar8)) {
      *(undefined4 *)(param_2 + 0x5c) = 0;
    }
  }
  ((int (*)())FUN_0018b1bc)(param_1,param_2,iVar7,iVar4,iVar9);
  return;
}

/* FUN_0018bc94 @ 0x18bc94 (1332 bytes) */
int FUN_0018bc94(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  int local_68 [10];
  
  if (param_2 < 3) {
    iVar7 = param_2 * 4 + param_1;
    if (*(int *)(iVar7 + 0x30) == 0) {
      iVar7 = ((int (*)())FUN_0018bc94)(param_1,param_2 + 1);
      if (iVar7 != 0) goto LAB_0018c1b0;
    }
    else {
      piVar11 = param_3 + 3;
      piVar8 = param_4 + 3;
      piVar6 = param_4;
      piVar9 = param_3;
      do {
        piVar14 = (int *)*piVar9;
        if ((((piVar14 == (int *)0x0) || (piVar14 == *(int **)(iVar7 + 0x18))) ||
            ((((*(int **)(iVar7 + 0x18) != (int *)0x0 &&
               ((piVar14[0x20] != 0 && (iVar3 = FUN_00126760(piVar14[0x26]), iVar3 != 0)))) &&
              ((piVar14[5] & 2U) == 0)) &&
             ((((((iVar3 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar3 == 0 &&
                  (piVar14 = *(int **)(iVar7 + 0x18), piVar14[0x20] != 0)) &&
                 (iVar3 = FUN_00126760(piVar14[0x26]), iVar3 != 0)) &&
                (((piVar14[5] & 2U) == 0 &&
                 (iVar3 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar3 == 0)))) &&
               ((*(uint *)(*piVar9 + 0x14) & 0x40) != 0)) &&
              (((*(uint *)(*(int *)(iVar7 + 0x18) + 0x14) & 0x40) != 0 &&
               (*(int *)(*piVar9 + 0x94) == *(int *)(*(int *)(iVar7 + 0x18) + 0x94))))))))) &&
           (((piVar14 = (int *)*piVar11, piVar14 == (int *)0x0 ||
             (piVar14 == *(int **)(iVar7 + 0x24))) ||
            (((((*(int **)(iVar7 + 0x24) != (int *)0x0 && (piVar14[0x20] != 0)) &&
               (iVar3 = FUN_00126760(piVar14[0x26]), iVar3 != 0)) &&
              ((((piVar14[5] & 2U) == 0 &&
                (iVar3 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar3 == 0)) &&
               (piVar14 = *(int **)(iVar7 + 0x24), piVar14[0x20] != 0)))) &&
             (((iVar3 = FUN_00126760(piVar14[0x26]), iVar3 != 0 && ((piVar14[5] & 2U) == 0)) &&
              ((iVar3 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar3 == 0 &&
               ((((*(uint *)(*piVar11 + 0x14) & 0x40) != 0 &&
                 ((*(uint *)(*(int *)(iVar7 + 0x24) + 0x14) & 0x40) != 0)) &&
                (*(int *)(*piVar11 + 0x94) == *(int *)(*(int *)(iVar7 + 0x24) + 0x94))))))))))))) {
          *piVar9 = *(int *)(iVar7 + 0x18);
          *piVar11 = *(int *)(iVar7 + 0x24);
          *piVar6 = *piVar6 + 1;
          *piVar8 = *piVar8 + 1;
          iVar3 = ((int (*)())FUN_0018bc94)(param_1,param_2 + 1,param_3,param_4);
          if (iVar3 != 0) goto LAB_0018c1b0;
          *piVar6 = *piVar6 + -1;
          iVar3 = *piVar8 + -1;
          *piVar8 = iVar3;
          if (*piVar6 == 0) {
            *piVar9 = 0;
            iVar3 = *piVar8;
          }
          if (iVar3 == 0) {
            *piVar11 = 0;
          }
        }
        piVar9 = piVar9 + 1;
        piVar11 = piVar11 + 1;
        piVar8 = piVar8 + 1;
        piVar6 = piVar6 + 1;
      } while (param_3 + 3 != piVar9);
    }
LAB_0018bf4c:
    uVar4 = 0;
  }
  else {
    piVar8 = param_4 + 3;
    piVar14 = local_68;
    piVar6 = piVar8;
    piVar9 = param_4;
    piVar11 = piVar14;
    do {
      iVar7 = *piVar9;
      piVar9 = piVar9 + 1;
      *piVar11 = iVar7;
      iVar7 = *piVar6;
      piVar6 = piVar6 + 1;
      piVar11[3] = iVar7;
      piVar11 = piVar11 + 1;
    } while (piVar11 != local_68 + 3);
    iVar7 = 0;
    iVar3 = param_1 + 0x10;
    do {
      piVar13 = (int *)(iVar3 + 8);
      iVar10 = 0;
      piVar6 = param_4;
      piVar9 = param_3;
      do {
        if ((*(int *)(param_1 + 0x30) == 0) && (*piVar13 != 0)) {
          iVar12 = 0;
          piVar2 = piVar9;
          do {
            if (((int *)*piVar2 != (int *)0x0) &&
               ((piVar15 = (int *)*piVar13, (int *)*piVar2 == piVar15 ||
                ((((piVar15 != (int *)0x0 && (piVar15[0x20] != 0)) &&
                  (iVar5 = FUN_00126760(piVar15[0x26]), iVar5 != 0)) &&
                 ((((((piVar15[5] & 2U) == 0 &&
                     (iVar5 = (**(code **)(*piVar15 + 0x50))(piVar15), iVar5 == 0)) &&
                    ((piVar15 = (int *)*piVar2, piVar15[0x20] != 0 &&
                     ((iVar5 = FUN_00126760(piVar15[0x26]), iVar5 != 0 && ((piVar15[5] & 2U) == 0)))
                     ))) && (iVar5 = (**(code **)(*piVar15 + 0x50))(piVar15), iVar5 == 0)) &&
                  ((((*(uint *)(*piVar13 + 0x14) & 0x40) != 0 &&
                    ((*(uint *)(*piVar2 + 0x14) & 0x40) != 0)) &&
                   (*(int *)(*piVar13 + 0x94) == *(int *)(*piVar2 + 0x94))))))))))) {
              piVar6[iVar12] = piVar6[iVar12] + 1;
              goto LAB_0018c0d4;
            }
            bVar1 = iVar12 != 2;
            piVar2 = piVar2 + 1;
            iVar12 = iVar12 + 1;
          } while (bVar1);
          iVar12 = 0;
          piVar2 = piVar9;
          while (*piVar2 != 0) {
            bVar1 = iVar12 == 2;
            piVar2 = piVar2 + 1;
            iVar12 = iVar12 + 1;
            if (bVar1) {
              piVar6 = param_3 + 3;
              do {
                iVar3 = *piVar14;
                *param_4 = iVar3;
                iVar7 = piVar14[3];
                *piVar8 = iVar7;
                if (iVar3 == 0) {
                  *param_3 = 0;
                }
                if (iVar7 == 0) {
                  *piVar6 = 0;
                }
                piVar14 = piVar14 + 1;
                param_4 = param_4 + 1;
                piVar8 = piVar8 + 1;
                piVar6 = piVar6 + 1;
                param_3 = param_3 + 1;
              } while (piVar11 != piVar14);
              goto LAB_0018bf4c;
            }
          }
          piVar9[iVar12] = *piVar13;
          piVar6[iVar12] = piVar6[iVar12] + 1;
        }
LAB_0018c0d4:
        bVar1 = iVar10 != 0xc;
        piVar13 = piVar13 + 3;
        piVar6 = piVar6 + 3;
        piVar9 = piVar9 + 3;
        iVar10 = iVar10 + 0xc;
      } while (bVar1);
      bVar1 = iVar7 != 2;
      iVar3 = iVar3 + 4;
      param_1 = param_1 + 4;
      iVar7 = iVar7 + 1;
    } while (bVar1);
LAB_0018c1b0:
    uVar4 = 1;
  }
  return uVar4;
}

/* FUN_0018c1c8 @ 0x18c1c8 (1440 bytes) */
int FUN_0018c1c8(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int local_58 [3];
  int local_4c [9];
  
  piVar5 = param_2 + 3;
  piVar4 = local_58;
  piVar1 = piVar5;
  piVar3 = param_2;
  do {
    *piVar4 = 0;
    piVar4[3] = 0;
    piVar4 = piVar4 + 1;
    *piVar3 = 0;
    *piVar1 = 0;
    piVar3 = piVar3 + 1;
    piVar1 = piVar1 + 1;
  } while (piVar4 != local_4c);
  if (*param_1 != 0) {
    *param_2 = *param_1;
    local_58[0] = local_58[0] + 1;
  }
  if (param_1[1] != 0) {
    *piVar5 = param_1[1];
    local_4c[0] = local_4c[0] + 1;
  }
  piVar1 = param_1;
  piVar3 = param_1;
  do {
    piVar4 = param_1;
    piVar6 = param_1;
    if ((param_1[2] == 0) || (param_1[3] == 0)) {
LAB_0018c498:
      do {
        if ((param_1[4] == 0) || (param_1[5] == 0)) {
LAB_0018c6a0:
          iVar2 = ((int (*)())FUN_0018bc94)(param_1,0,param_2,local_58);
          if (iVar2 != 0) {
            return 1;
          }
          local_4c[0] = local_4c[0] + -1;
          if (local_4c[0] == 0) {
            *piVar5 = 0;
          }
          local_4c[1] = local_4c[1] + -1;
          if (local_4c[1] == 0) {
            param_2[4] = 0;
          }
        }
        else {
          piVar7 = (int *)*piVar5;
          if ((((piVar7 == (int *)0x0) || (piVar7 == (int *)piVar6[5])) ||
              ((((((int *)piVar6[5] != (int *)0x0 && (piVar7[0x20] != 0)) &&
                 (iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0)) &&
                (((piVar7[5] & 2U) == 0 &&
                 (iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0)))) &&
               ((piVar7 = (int *)piVar6[5], piVar7[0x20] != 0 &&
                (((iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0 && ((piVar7[5] & 2U) == 0)) &&
                 ((iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0 &&
                  ((((*(uint *)(*piVar5 + 0x14) & 0x40) != 0 &&
                    ((*(uint *)(piVar6[5] + 0x14) & 0x40) != 0)) &&
                   (*(int *)(*piVar5 + 0x94) == *(int *)(piVar6[5] + 0x94))))))))))))) &&
             (((piVar7 = (int *)param_2[4], piVar7 == (int *)0x0 || (piVar7 == (int *)piVar4[4])) ||
              (((int *)piVar4[4] != (int *)0x0 &&
               ((((piVar7[0x20] != 0 && (iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0)) &&
                 (((piVar7[5] & 2U) == 0 &&
                  (((iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0 &&
                    (piVar7 = (int *)piVar4[4], piVar7[0x20] != 0)) &&
                   (iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0)))))) &&
                ((((piVar7[5] & 2U) == 0 &&
                  (iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0)) &&
                 (((*(uint *)(param_2[4] + 0x14) & 0x40) != 0 &&
                  (((*(uint *)(piVar4[4] + 0x14) & 0x40) != 0 &&
                   (*(int *)(param_2[4] + 0x94) == *(int *)(piVar4[4] + 0x94))))))))))))))) {
            *piVar5 = piVar6[5];
            local_4c[1] = local_4c[1] + 1;
            local_4c[0] = local_4c[0] + 1;
            param_2[4] = piVar4[4];
            goto LAB_0018c6a0;
          }
        }
        piVar6 = piVar6 + -1;
        piVar4 = piVar4 + 1;
      } while (param_1 + -2 != piVar6);
      local_58[0] = local_58[0] + -1;
      if (local_58[0] == 0) {
        *param_2 = 0;
      }
      local_58[1] = local_58[1] + -1;
      if (local_58[1] == 0) {
        param_2[1] = 0;
      }
    }
    else {
      piVar7 = (int *)*param_2;
      if ((((piVar7 == (int *)0x0) || (piVar7 == (int *)piVar3[3])) ||
          (((((((int *)piVar3[3] != (int *)0x0 && (piVar7[0x20] != 0)) &&
              (iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0)) &&
             (((piVar7[5] & 2U) == 0 && (iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0))
             )) && (piVar7 = (int *)piVar3[3], piVar7[0x20] != 0)) &&
           ((((iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0 && ((piVar7[5] & 2U) == 0)) &&
             (iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0)) &&
            ((((*(uint *)(*param_2 + 0x14) & 0x40) != 0 &&
              ((*(uint *)(piVar3[3] + 0x14) & 0x40) != 0)) &&
             (*(int *)(*param_2 + 0x94) == *(int *)(piVar3[3] + 0x94))))))))) &&
         (((piVar7 = (int *)param_2[1], piVar7 == (int *)0x0 || (piVar7 == (int *)piVar1[2])) ||
          (((((int *)piVar1[2] != (int *)0x0 &&
             ((piVar7[0x20] != 0 && (iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0)))) &&
            ((piVar7[5] & 2U) == 0)) &&
           (((((iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0 &&
               (piVar7 = (int *)piVar1[2], piVar7[0x20] != 0)) &&
              (iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0)) &&
             (((piVar7[5] & 2U) == 0 && (iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0))
             )) && (((*(uint *)(param_2[1] + 0x14) & 0x40) != 0 &&
                    (((*(uint *)(piVar1[2] + 0x14) & 0x40) != 0 &&
                     (*(int *)(param_2[1] + 0x94) == *(int *)(piVar1[2] + 0x94))))))))))))) {
        *param_2 = piVar3[3];
        local_58[0] = local_58[0] + 1;
        local_58[1] = local_58[1] + 1;
        param_2[1] = piVar1[2];
        goto LAB_0018c498;
      }
    }
    piVar3 = piVar3 + -1;
    piVar1 = piVar1 + 1;
    if (param_1 + -2 == piVar3) {
      return 0;
    }
  } while( true );
}

/* FUN_0018c768 @ 0x18c768 (140 bytes) */
int FUN_0018c768(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int *piVar2;
  int local_38 [3];
  int local_2c [9];
  
  iVar1 = ((int (*)())FUN_0018c1c8)(param_1,local_38);
  param_2[1] = 0;
  *param_2 = 0;
  if (iVar1 != 0) {
    piVar2 = local_38;
    do {
      if (*piVar2 == 0) {
        *param_2 = *param_2 + 1;
      }
      if (piVar2[3] == 0) {
        param_2[1] = param_2[1] + 1;
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != local_2c);
  }
  return;
}

/* FUN_0018c7f4 @ 0x18c7f4 (396 bytes) */
int FUN_0018c7f4(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = (int *)(param_3 * 0xc + param_1 + 0x18);
  iVar4 = 0;
  while (((int *)*piVar5 == (int *)0x0 ||
         ((param_2 != (int *)*piVar5 &&
          (((((param_2 == (int *)0x0 || (param_2[0x20] == 0)) ||
             (iVar2 = FUN_00126760(param_2[0x26]), iVar2 == 0)) ||
            (((((param_2[5] & 2U) != 0 ||
               (iVar2 = (**(code **)(*param_2 + 0x50))(param_2), iVar2 != 0)) ||
              ((piVar3 = (int *)*piVar5, piVar3[0x20] == 0 ||
               ((iVar2 = FUN_00126760(piVar3[0x26]), iVar2 == 0 || ((piVar3[5] & 2U) != 0)))))) ||
             (iVar2 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar2 != 0)))) ||
           ((((param_2[5] & 0x40U) == 0 || ((*(uint *)(*piVar5 + 0x14) & 0x40) == 0)) ||
            (param_2[0x25] != *(int *)(*piVar5 + 0x94)))))))))) {
    bVar1 = iVar4 == 2;
    piVar5 = piVar5 + 1;
    iVar4 = iVar4 + 1;
    if (bVar1) {
      iVar4 = 0;
      piVar5 = (int *)(param_3 * 0xc + param_1 + 0x18);
      do {
        if (*piVar5 == 0) {
          *(int **)((param_3 * 3 + iVar4) * 4 + param_1 + 0x18) = param_2;
          return 1;
        }
        bVar1 = iVar4 != 2;
        piVar5 = piVar5 + 1;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      return 0;
    }
  }
  return 1;
}

/* FUN_0018c980 @ 0x18c980 (1112 bytes) */
int FUN_0018c980(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  
  iVar4 = 0;
  iVar6 = param_1;
  while (*(int *)(iVar6 + 0x30) != 0) {
    piVar7 = *(int **)(iVar6 + 0x18);
    if (((param_2 == piVar7) ||
        ((((((piVar7 != (int *)0x0 && (param_2 != (int *)0x0)) && (piVar7[0x20] != 0)) &&
           ((iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0 && ((piVar7[5] & 2U) == 0)))) &&
          ((((iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0 &&
             ((param_2[0x20] != 0 && (iVar2 = FUN_00126760(param_2[0x26]), iVar2 != 0)))) &&
            ((param_2[5] & 2U) == 0)) &&
           (((iVar2 = (**(code **)(*param_2 + 0x50))(param_2), iVar2 == 0 &&
             ((*(uint *)(*(int *)(iVar6 + 0x18) + 0x14) & 0x40) != 0)) &&
            ((param_2[5] & 0x40U) != 0)))))) &&
         (*(int *)(*(int *)(iVar6 + 0x18) + 0x94) == param_2[0x25])))) &&
       ((piVar7 = *(int **)(iVar6 + 0x24), param_3 == piVar7 ||
        (((((piVar7 != (int *)0x0 && (param_3 != (int *)0x0)) &&
           ((piVar7[0x20] != 0 &&
            ((iVar2 = FUN_00126760(piVar7[0x26]), iVar2 != 0 && ((piVar7[5] & 2U) == 0)))))) &&
          (iVar2 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar2 == 0)) &&
         (((((param_3[0x20] != 0 && (iVar2 = FUN_00126760(param_3[0x26]), iVar2 != 0)) &&
            ((param_3[5] & 2U) == 0)) &&
           ((iVar2 = (**(code **)(*param_3 + 0x50))(param_3), iVar2 == 0 &&
            ((*(uint *)(*(int *)(iVar6 + 0x24) + 0x14) & 0x40) != 0)))) &&
          (((param_3[5] & 0x40U) != 0 && (*(int *)(*(int *)(iVar6 + 0x24) + 0x94) == param_3[0x25]))
          )))))))) goto LAB_0018cdb8;
    bVar1 = iVar4 == 2;
    iVar6 = iVar6 + 4;
    iVar4 = iVar4 + 1;
    if (bVar1) goto LAB_0018cdb8;
  }
  iVar2 = iVar4 + 1;
  iVar6 = iVar4 * 4 + param_1;
  iVar5 = *(int *)(iVar6 + 0x18);
  iVar4 = *(int *)(iVar6 + 0x24);
  *(undefined4 *)(iVar6 + 0x30) = 1;
  *(int **)(iVar6 + 0x18) = param_2;
  *(int **)(iVar6 + 0x24) = param_3;
  if (iVar2 < 3) {
    piVar7 = (int *)(iVar2 * 4 + param_1 + 0x18);
    do {
      piVar8 = (int *)*piVar7;
      if ((piVar8 != (int *)0x0) &&
         ((param_2 == piVar8 ||
          ((((param_2 != (int *)0x0 && (piVar8[0x20] != 0)) &&
            (iVar6 = FUN_00126760(piVar8[0x26]), iVar6 != 0)) &&
           (((((piVar8[5] & 2U) == 0 && (iVar6 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar6 == 0))
             && ((param_2[0x20] != 0 &&
                 ((iVar6 = FUN_00126760(param_2[0x26]), iVar6 != 0 && ((param_2[5] & 2U) == 0))))))
            && ((iVar6 = (**(code **)(*param_2 + 0x50))(param_2), iVar6 == 0 &&
                ((((*(uint *)(*piVar7 + 0x14) & 0x40) != 0 && ((param_2[5] & 0x40U) != 0)) &&
                 (*(int *)(*piVar7 + 0x94) == param_2[0x25])))))))))))) {
        *piVar7 = 0;
      }
      piVar8 = (int *)piVar7[3];
      if ((piVar8 != (int *)0x0) &&
         ((param_3 == piVar8 ||
          ((((param_3 != (int *)0x0 && (piVar8[0x20] != 0)) &&
            ((iVar6 = FUN_00126760(piVar8[0x26]), iVar6 != 0 &&
             (((piVar8[5] & 2U) == 0 && (iVar6 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar6 == 0))
             )))) && (((param_3[0x20] != 0 &&
                       ((((iVar6 = FUN_00126760(param_3[0x26]), iVar6 != 0 &&
                          ((param_3[5] & 2U) == 0)) &&
                         (iVar6 = (**(code **)(*param_3 + 0x50))(param_3), iVar6 == 0)) &&
                        (((*(uint *)(piVar7[3] + 0x14) & 0x40) != 0 && ((param_3[5] & 0x40U) != 0)))
                        ))) && (*(int *)(piVar7[3] + 0x94) == param_3[0x25])))))))) {
        piVar7[3] = 0;
      }
      bVar1 = iVar2 != 2;
      piVar7 = piVar7 + 1;
      iVar2 = iVar2 + 1;
    } while (bVar1);
  }
  if (((iVar5 == 0) || (iVar6 = ((int (*)())FUN_0018c7f4)(param_1,iVar5,0), iVar6 != 0)) &&
     ((iVar4 == 0 || (iVar6 = ((int (*)())FUN_0018c7f4)(param_1,iVar4,1), iVar6 != 0)))) {
LAB_0018cdb8:
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

/* FUN_0018cdd8 @ 0x18cdd8 (1456 bytes) */
int FUN_0018cdd8(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int *param_3;
  int param_4;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = param_4 * 8;
  iVar3 = iVar5 + param_1;
  piVar6 = *(int **)(iVar3 + 8);
  if ((piVar6 == (int *)0x0) || (piVar4 = *(int **)(iVar3 + 0xc), piVar4 == (int *)0x0)) {
    iVar3 = param_4 * 4;
    piVar6 = *(int **)(iVar3 + param_1);
    if ((((piVar6 == (int *)0x0) || (piVar6 == param_2)) ||
        (((((((param_2 != (int *)0x0 && (piVar6[0x20] != 0)) &&
             (iVar1 = FUN_00126760(piVar6[0x26]), iVar1 != 0)) &&
            ((((piVar6[5] & 2U) == 0 && (iVar1 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar1 == 0))
             && (param_2[0x20] != 0)))) &&
           ((iVar1 = FUN_00126760(param_2[0x26]), iVar1 != 0 && ((param_2[5] & 2U) == 0)))) &&
          ((iVar1 = (**(code **)(*param_2 + 0x50))(param_2), iVar1 == 0 &&
           ((((*(uint *)(*(int *)(iVar3 + param_1) + 0x14) & 0x40) != 0 &&
             ((param_2[5] & 0x40U) != 0)) &&
            (*(int *)(*(int *)(iVar3 + param_1) + 0x94) == param_2[0x25])))))) ||
         ((piVar6 = *(int **)(iVar3 + param_1), param_3 == piVar6 ||
          ((((piVar6 != (int *)0x0 && (param_3 != (int *)0x0)) &&
            (((piVar6[0x20] != 0 &&
              ((iVar1 = FUN_00126760(piVar6[0x26]), iVar1 != 0 && ((piVar6[5] & 2U) == 0)))) &&
             (iVar1 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar1 == 0)))) &&
           (((((param_3[0x20] != 0 && (iVar1 = FUN_00126760(param_3[0x26]), iVar1 != 0)) &&
              ((param_3[5] & 2U) == 0)) &&
             ((iVar1 = (**(code **)(*param_3 + 0x50))(param_3), iVar1 == 0 &&
              ((*(uint *)(*(int *)(iVar3 + param_1) + 0x14) & 0x40) != 0)))) &&
            (((param_3[5] & 0x40U) != 0 &&
             (*(int *)(*(int *)(iVar3 + param_1) + 0x94) == param_3[0x25])))))))))))) &&
       ((iVar3 = ((int (*)())FUN_0018c7f4)(param_1,param_2,param_4), iVar3 != 0 &&
        (iVar3 = ((int (*)())FUN_0018c7f4)(param_1,param_3,param_4), iVar3 != 0)))) {
      *(int **)(iVar5 + param_1 + 0xc) = param_3;
      *(int **)(iVar5 + param_1 + 8) = param_2;
      return 1;
    }
LAB_0018d170:
    uVar2 = 0;
  }
  else {
    if (piVar6 == param_2) {
LAB_0018cee8:
      if ((param_3 != piVar4) &&
         ((((piVar4 == (int *)0x0 || (param_3 == (int *)0x0)) ||
           ((piVar4[0x20] == 0 ||
            ((iVar1 = FUN_00126760(piVar4[0x26]), iVar1 == 0 || ((piVar4[5] & 2U) != 0)))))) ||
          (((iVar1 = (**(code **)(*piVar4 + 0x50))(piVar4), iVar1 != 0 ||
            ((((param_3[0x20] == 0 || (iVar1 = FUN_00126760(param_3[0x26]), iVar1 == 0)) ||
              ((param_3[5] & 2U) != 0)) ||
             ((iVar1 = (**(code **)(*param_3 + 0x50))(param_3), iVar1 != 0 ||
              ((*(uint *)(*(int *)(iVar3 + 0xc) + 0x14) & 0x40) == 0)))))) ||
           (((param_3[5] & 0x40U) == 0 || (*(int *)(*(int *)(iVar3 + 0xc) + 0x94) != param_3[0x25]))
           )))))) goto LAB_0018cfbc;
    }
    else {
      if (((((param_2 != (int *)0x0) && (piVar6[0x20] != 0)) &&
           (iVar1 = FUN_00126760(piVar6[0x26]), iVar1 != 0)) &&
          ((((piVar6[5] & 2U) == 0 && (iVar1 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar1 == 0))
           && ((param_2[0x20] != 0 &&
               ((iVar1 = FUN_00126760(param_2[0x26]), iVar1 != 0 && ((param_2[5] & 2U) == 0))))))))
         && ((iVar1 = (**(code **)(*param_2 + 0x50))(param_2), iVar1 == 0 &&
             ((((*(uint *)(*(int *)(iVar3 + 8) + 0x14) & 0x40) != 0 && ((param_2[5] & 0x40U) != 0))
              && (*(int *)(*(int *)(iVar3 + 8) + 0x94) == param_2[0x25])))))) {
        piVar4 = *(int **)(iVar3 + 0xc);
        goto LAB_0018cee8;
      }
LAB_0018cfbc:
      iVar5 = iVar5 + param_1;
      piVar6 = *(int **)(iVar5 + 8);
      if (((param_3 != piVar6) &&
          (((((piVar6 == (int *)0x0 || (param_3 == (int *)0x0)) ||
             ((piVar6[0x20] == 0 ||
              (((iVar3 = FUN_00126760(piVar6[0x26]), iVar3 == 0 || ((piVar6[5] & 2U) != 0)) ||
               (iVar3 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar3 != 0)))))) ||
            ((param_3[0x20] == 0 || (iVar3 = FUN_00126760(param_3[0x26]), iVar3 == 0)))) ||
           (((param_3[5] & 2U) != 0 ||
            (((iVar3 = (**(code **)(*param_3 + 0x50))(param_3), iVar3 != 0 ||
              ((*(uint *)(*(int *)(iVar5 + 8) + 0x14) & 0x40) == 0)) ||
             (((param_3[5] & 0x40U) == 0 || (*(int *)(*(int *)(iVar5 + 8) + 0x94) != param_3[0x25]))
             )))))))) ||
         ((piVar6 = *(int **)(iVar5 + 0xc), param_2 != piVar6 &&
          (((((piVar6 == (int *)0x0 || (param_2 == (int *)0x0)) || (piVar6[0x20] == 0)) ||
            ((iVar3 = FUN_00126760(piVar6[0x26]), iVar3 == 0 || ((piVar6[5] & 2U) != 0)))) ||
           ((((iVar3 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar3 != 0 ||
              ((param_2[0x20] == 0 || (iVar3 = FUN_00126760(param_2[0x26]), iVar3 == 0)))) ||
             ((param_2[5] & 2U) != 0)) ||
            ((((iVar3 = (**(code **)(*param_2 + 0x50))(param_2), iVar3 != 0 ||
               ((*(uint *)(*(int *)(iVar5 + 0xc) + 0x14) & 0x40) == 0)) ||
              ((param_2[5] & 0x40U) == 0)) ||
             (*(int *)(*(int *)(iVar5 + 0xc) + 0x94) != param_2[0x25])))))))))) goto LAB_0018d170;
    }
    uVar2 = 1;
  }
  return uVar2;
}

