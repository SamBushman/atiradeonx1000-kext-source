#include "decls.h"

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
  
  iVar1 = (**(code **)(*param_2 + 100))(param_2,param_2,param_3,param_4,param_5,param_6);
  if ((((iVar1 != 0) && (param_2[0x48] == 0)) && ((param_2[5] & 0x200U) == 0)) &&
     ((iVar1 = param_2[0x49], iVar1 != 0 &&
      (iVar2 = FUN_0015800c(param_1,param_3,iVar1,param_5,param_6,param_4), iVar2 != 0)))) {
    ((int (*)())FUN_00158988)(param_2,param_3,iVar1,param_5,param_6,param_4);
    param_2[0x49] = 0;
  }
  return;
}

/* FUN_00158c3c @ 0x158c3c (2424 bytes) */
int FUN_00158c3c(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
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
  uVar9 = local_64;
  if (local_64 < local_68) {
    iVar13 = local_64 * 4;
    _memset(local_60 + iVar13,0,4);
    local_64 = uVar9 + 1;
    piVar3 = (int *)(iVar13 + local_60);
  }
  else {
    piVar3 = (int *)FUN_0019423c(&local_68,local_64);
  }
  *piVar3 = param_1;
  uVar11 = 0;
  do {
    uVar9 = local_64 - 1;
    piVar3 = (int *)0x0;
    if (uVar9 < local_64) {
      piVar3 = (int *)(uVar9 * 4 + local_60);
    }
    iVar16 = *piVar3;
    FUN_00194208(&local_68,uVar9);
    iVar13 = *(int *)(iVar16 + 0x124);
    iVar14 = *(int *)(*(int *)(iVar16 + 0x88) + 8);
    if (iVar14 - 0x12U < 3) {
      iVar4 = FUN_001054ec(iVar16,0);
      uVar12 = *(undefined4 *)(iVar4 + 0x10);
      iVar4 = FUN_001054ec(iVar16,1);
      FUN_000f3398(&local_58,*(undefined4 *)(iVar4 + 0x10));
      uVar1 = local_58;
      iVar4 = FUN_001054ec(iVar16,2);
      FUN_000f3398(&local_54,*(undefined4 *)(iVar4 + 0x10));
      uVar2 = local_54;
      piVar3 = (int *)FUN_00105594(iVar16,1);
      piVar5 = (int *)FUN_00105594(iVar16,2);
      if (iVar14 == 0x13) {
        iVar14 = FUN_0010497c(piVar3,param_2);
        if ((iVar14 != 0) && (iVar14 = FUN_0010497c(piVar5,param_2), iVar14 != 0)) {
          ((int (*)())FUN_00158b78)(iVar16,piVar3,piVar5,param_2,uVar12,uVar2);
          ((int (*)())FUN_00158b78)(iVar16,piVar5,piVar3,param_2,uVar12,uVar1);
        }
        if (iVar13 != 0) {
          iVar14 = FUN_0015800c(iVar16,piVar3,iVar13,uVar12,uVar1,param_2);
          if (iVar14 == 0) {
            iVar14 = FUN_0015800c(iVar16,piVar5,iVar13,uVar12,uVar2,param_2);
            if (iVar14 != 0) {
              ((int (*)())FUN_00158988)(iVar16,piVar5,iVar13,uVar12,uVar2,param_2);
              *(undefined4 *)(iVar16 + 0x124) = 0;
              goto LAB_00158fc8;
            }
          }
          else {
            ((int (*)())FUN_00158988)(iVar16,piVar3,iVar13,uVar12,uVar1,param_2);
            uVar9 = local_64;
            *(undefined4 *)(iVar16 + 0x124) = 0;
            if (local_64 < local_68) {
              iVar13 = local_64 * 4;
              _memset(iVar13 + local_60,0,4);
              local_64 = uVar9 + 1;
              puVar6 = (undefined4 *)(iVar13 + local_60);
            }
            else {
              puVar6 = (undefined4 *)FUN_0019423c(&local_68,local_64);
            }
            *puVar6 = piVar3;
          }
        }
      }
      else if (iVar14 == 0x14) {
        iVar14 = FUN_0010497c(piVar3,param_2);
        if ((iVar14 != 0) && (iVar14 = FUN_0010497c(piVar5,param_2), iVar14 != 0)) {
          ((int (*)())FUN_00158b78)(iVar16,piVar3,piVar5,param_2,uVar12,uVar2);
          ((int (*)())FUN_00158b78)(iVar16,piVar5,piVar3,param_2,uVar12,uVar1);
          iVar14 = (**(code **)(*piVar3 + 100))(piVar3);
          if (iVar14 != 0) {
            puVar15 = (uint *)(piVar3 + 0x2e);
            for (iVar14 = 1; iVar4 = (**(code **)(*piVar3 + 0x14))(piVar3), iVar14 <= iVar4;
                iVar14 = iVar14 + 1) {
              uVar9 = *puVar15;
              puVar15 = puVar15 + 6;
              if ((((uVar9 & 1) != 0) || ((uVar9 & 2) != 0)) ||
                 (iVar4 = FUN_000f31e8(piVar3,iVar14), iVar4 == 0)) goto LAB_00159218;
            }
            if ((piVar3[0x48] == 0) && (piVar3[0x49] == 0)) {
              if (((piVar3[0x20] != 0) &&
                  ((iVar14 = FUN_00126760(piVar3[0x26]), iVar14 != 0 && ((piVar3[5] & 2U) == 0))))
                 && (iVar14 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar14 == 0)) {
                iVar14 = 4;
                piVar10 = piVar3;
                do {
                  if (*(byte *)(piVar10 + 0x27) - 2 < 2) goto LAB_00159218;
                  piVar10 = (int *)((int)piVar10 + 1);
                  iVar14 = iVar14 + -1;
                } while (iVar14 != 0);
              }
              FUN_001054ec(piVar3,0);
              iVar14 = FUN_00105dbc(piVar3,0);
              if (((iVar14 == 0) && ((piVar3[5] & 2U) == 0)) && ((piVar3[5] & 0x200U) == 0)) {
                *(int *)(param_2 + 0x17c) = *(int *)(param_2 + 0x17c) + 1;
                uVar7 = FUN_00105594(piVar3,1);
                FUN_00106004(iVar16,1,uVar7,0,*(undefined4 *)(param_2 + 8));
                iVar14 = FUN_00105594(piVar3,1);
                if (*(int *)(param_2 + 0x478) < *(int *)(iVar14 + 0x160)) {
                  *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar14 + 0x160) = *(int *)(param_2 + 0x478) + 1;
                }
                FUN_00105894(piVar3,*(undefined4 *)(param_2 + 8));
              }
            }
          }
LAB_00159218:
          iVar14 = (**(code **)(*piVar5 + 100))(piVar5);
          if (iVar14 != 0) {
            puVar15 = (uint *)(piVar5 + 0x2e);
            for (iVar14 = 1; iVar4 = (**(code **)(*piVar5 + 0x14))(piVar5), iVar14 <= iVar4;
                iVar14 = iVar14 + 1) {
              uVar9 = *puVar15;
              puVar15 = puVar15 + 6;
              if ((((uVar9 & 1) != 0) || ((uVar9 & 2) != 0)) ||
                 (iVar4 = FUN_000f31e8(piVar5,iVar14), iVar4 == 0)) goto LAB_001593b8;
            }
            if ((piVar5[0x48] == 0) && (piVar5[0x49] == 0)) {
              if ((piVar5[0x20] != 0) &&
                 (((iVar14 = FUN_00126760(piVar5[0x26]), iVar14 != 0 && ((piVar5[5] & 2U) == 0)) &&
                  (iVar14 = (**(code **)(*piVar5 + 0x50))(piVar5), iVar14 == 0)))) {
                iVar14 = 4;
                piVar10 = piVar5;
                do {
                  if (*(byte *)(piVar10 + 0x27) - 2 < 2) goto LAB_001593b8;
                  piVar10 = (int *)((int)piVar10 + 1);
                  iVar14 = iVar14 + -1;
                } while (iVar14 != 0);
              }
              FUN_001054ec(piVar5,0);
              iVar14 = FUN_00105dbc(piVar5,0);
              if (((iVar14 == 0) && ((piVar5[5] & 2U) == 0)) && ((piVar5[5] & 0x200U) == 0)) {
                *(int *)(param_2 + 0x17c) = *(int *)(param_2 + 0x17c) + 1;
                uVar7 = FUN_00105594(piVar5,1);
                FUN_00106004(iVar16,2,uVar7,0,*(undefined4 *)(param_2 + 8));
                iVar14 = FUN_00105594(piVar5,1);
                if (*(int *)(param_2 + 0x478) < *(int *)(iVar14 + 0x160)) {
                  *(int *)(iVar14 + 0x160) = *(int *)(iVar14 + 0x160) + 1;
                }
                else {
                  *(int *)(iVar14 + 0x160) = *(int *)(param_2 + 0x478) + 1;
                }
                FUN_00105894(piVar5,*(undefined4 *)(param_2 + 8));
              }
            }
          }
        }
LAB_001593b8:
        if (iVar13 != 0) {
          uVar8 = FUN_00105594(iVar16,3);
          iVar14 = FUN_001054ec(iVar16,3);
          FUN_000f3398(local_50,*(undefined4 *)(iVar14 + 0x10));
          uVar7 = local_50[0];
          iVar14 = FUN_0015800c(iVar16,uVar8,iVar13,uVar12,local_50[0],param_2);
          if (iVar14 != 0) {
            iVar14 = FUN_0015800c(iVar16,piVar3,iVar13,uVar12,uVar1,param_2);
            if (iVar14 == 0) {
              iVar14 = FUN_0015800c(iVar16,piVar5,iVar13,uVar12,uVar2,param_2);
              if (iVar14 == 0) break;
              ((int (*)())FUN_00158988)(iVar16,piVar5,iVar13,uVar12,uVar2,param_2);
              uVar9 = local_64;
              *(undefined4 *)(iVar16 + 0x124) = 0;
              if (local_64 < local_68) {
                iVar14 = local_64 * 4;
                _memset(iVar14 + local_60,0,4);
                local_64 = uVar9 + 1;
                puVar6 = (undefined4 *)(iVar14 + local_60);
              }
              else {
                puVar6 = (undefined4 *)FUN_0019423c(&local_68,local_64);
              }
              *puVar6 = piVar5;
            }
            else {
              ((int (*)())FUN_00158988)(iVar16,piVar3,iVar13,uVar12,uVar1,param_2);
              uVar9 = local_64;
              *(undefined4 *)(iVar16 + 0x124) = 0;
              if (local_64 < local_68) {
                iVar14 = local_64 * 4;
                _memset(iVar14 + local_60,0,4);
                local_64 = uVar9 + 1;
                puVar6 = (undefined4 *)(iVar14 + local_60);
              }
              else {
                puVar6 = (undefined4 *)FUN_0019423c(&local_68,local_64);
              }
              *puVar6 = piVar3;
            }
            ((int (*)())FUN_00158988)(iVar16,uVar8,iVar13,uVar12,uVar7,param_2);
            uVar9 = local_64;
            if (local_64 < local_68) {
              iVar13 = local_64 * 4;
              _memset(iVar13 + local_60,0,4);
              local_64 = uVar9 + 1;
              puVar6 = (undefined4 *)(iVar13 + local_60);
            }
            else {
              puVar6 = (undefined4 *)FUN_0019423c(&local_68,local_64);
            }
            *puVar6 = uVar8;
          }
        }
      }
      else if (((iVar14 == 0x12) && (iVar13 != 0)) &&
              ((iVar14 = FUN_0015800c(iVar16,piVar3,iVar13,uVar12,uVar1,param_2), iVar14 != 0 &&
               (iVar14 = FUN_0015800c(iVar16,piVar5,iVar13,uVar12,uVar2,param_2), iVar14 != 0)))) {
        *(undefined4 *)(iVar16 + 0x124) = 0;
        if (param_1 == iVar16) {
          uVar11 = 1;
        }
        ((int (*)())FUN_00158988)(iVar16,piVar3,iVar13,uVar12,uVar1,param_2);
        uVar9 = local_64;
        if (local_64 < local_68) {
          iVar14 = local_64 * 4;
          _memset(iVar14 + local_60,0,4);
          local_64 = uVar9 + 1;
          puVar6 = (undefined4 *)(iVar14 + local_60);
        }
        else {
          puVar6 = (undefined4 *)FUN_0019423c(&local_68,local_64);
        }
        *puVar6 = piVar3;
        if (piVar3 != piVar5) {
          ((int (*)())FUN_00158988)(iVar16,piVar5,iVar13,uVar12,uVar2,param_2);
LAB_00158fc8:
          uVar9 = local_64;
          if (local_64 < local_68) {
            iVar13 = local_64 * 4;
            _memset(iVar13 + local_60,0,4);
            local_64 = uVar9 + 1;
            puVar6 = (undefined4 *)(iVar13 + local_60);
          }
          else {
            puVar6 = (undefined4 *)FUN_0019423c(&local_68,local_64);
          }
          *puVar6 = piVar5;
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
  int *a0;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_38 [4];
  undefined4 local_28;
  float local_24;
  
  iVar2 = FUN_0017361c(param_1);
  if (iVar2 == 0) {
LAB_0015977c:
    uVar5 = 0;
  }
  else {
    iVar2 = FUN_001054ec(param_1,1);
    local_38[0] = *(undefined4 *)(iVar2 + 0x10);
    iVar6 = 0;
    iVar2 = -1;
    do {
      iVar3 = FUN_001054ec(param_1,0);
      iVar4 = iVar2;
      if (*(char *)(iVar6 + iVar3 + 0x10) != '\x01') {
        uVar7 = (uint)*(byte *)((int)local_38 + iVar6);
        a0 = (int *)FUN_00105594(param_1,1);
        iVar4 = (**(code **)(*a0 + 0x60))(a0);
        if (iVar4 != 0) {
          uVar5 = FUN_001042bc(a0,uVar7);
          iVar4 = FUN_001054ec(a0,uVar5);
          uVar7 = (uint)*(byte *)(uVar7 + iVar4 + 0x10);
          a0 = (int *)FUN_00105594(a0,uVar5);
        }
        iVar4 = FUN_00126708(a0[0x26]);
        if ((iVar4 == 0) || (((int)*(char *)(a0 + 0x57) >> (uVar7 & 0x3f) & 1U) == 0))
        goto LAB_0015977c;
        ((void (*)())FUN_0010b2dc)(&local_28,param_1,1,a0[uVar7 * 6 + 8]);
        ((void (*)())FUN_0010b284)(&local_24,param_1,1,local_28);
        iVar4 = ((bool (*)())FUN_0010b820)(param_1,(double)local_24,0.0);
        iVar4 = (iVar4 == 0) + 2;
        if ((iVar2 != -1) && (bVar1 = iVar4 != iVar2, iVar4 = iVar2, bVar1)) goto LAB_0015977c;
      }
      bVar1 = iVar6 != 3;
      iVar6 = iVar6 + 1;
      iVar2 = iVar4;
    } while (bVar1);
    *(int *)(param_2 + 0x1ec) = *(int *)(param_2 + 0x1ec) + 1;
    FUN_0010d15c(param_1,iVar4,0,*(undefined4 *)(param_2 + 8));
    uVar5 = 1;
  }
  return uVar5;
}

/* FUN_00159794 @ 0x159794 (964 bytes) */
int FUN_00159794(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
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
        iVar4 = (**(code **)(*piVar5 + 0x5c))(piVar5);
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
        iVar4 = (**(code **)(*piVar5 + 0x5c))(piVar5);
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
  undefined4 a1;
  uint uVar7;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  double fparam_1;
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
  
  uVar12 = *(uint *)(param_3 + 8);
  if ((((*(int *)(*(int *)(uVar12 + 0x6c4) + 0x214) + *(int *)(*(int *)(uVar12 + 0x6c4) + 0x218) <
         *(int *)(uVar12 + 0x6a0)) && (param_1 != 0)) && (0 < *(int *)(param_1 + 0x84))) &&
     (iVar2 = FUN_00105594(param_1,1), iVar2 != 0)) {
    ((int (*)())FUN_00159794)(param_1,param_2,uVar12);
    ((int (*)())FUN_00159794)(iVar2,param_2,uVar12);
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
            iVar8 = (**(code **)(*piVar3 + 0x5c))(piVar3);
            piVar4 = piVar3;
            if ((iVar8 != 0) && (iVar8 = FUN_0010497c(piVar3,param_3), iVar8 == 0)) {
              piVar4 = (int *)FUN_0010445c(piVar3,uVar12,0);
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
            uVar5 = 1;
            ((void (*)())FUN_0010b284)(&local_6c,param_1,1,local_74);
            local_50 = local_70;
            if ((0.0 <= local_70) || (local_50 = local_6c, 0.0 <= local_6c)) {
              if ((0.0 > local_70) || (local_50 = local_6c, local_6c < 0.0)) {
                uVar11 = *(uint *)(iVar2 + 0xb8);
                iVar8 = (**(code **)(*piVar4 + 0x5c))
                                  (piVar4,a1,uVar5,local_74,in_r7,in_r8,*(code **)(*piVar4 + 0x5c));
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
                FUN_00106004(param_1,1,piVar3,0,uVar12);
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
                *(undefined4 *)(iVar8 + 0x10) = local_68;
                if ((local_70 < 0.0) || (local_50 = local_6c, 0.0 <= local_6c)) {
                  FUN_0010ac38(param_1,2,3,uVar12);
                }
                uVar5 = FUN_00105894(iVar2,uVar12);
                return uVar5;
              }
              uVar5 = 2;
            }
            else {
              uVar5 = 3;
            }
            FUN_0010d15c(param_1,uVar5,0,uVar12);
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
        FUN_0010ac38(param_1,1,2,uVar12);
        iVar8 = *(int *)(PTR_DAT_001e90f8 + iVar8 * 4);
        *(int *)(param_1 + 300) = iVar8;
      }
      iVar2 = FUN_00105594(param_1,1);
      if (((*(uint *)(param_1 + 0xb8) & 2) == 0) && ((*(uint *)(param_1 + 0xd0) & 2) == 0)) {
        if ((*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x12) &&
           (((local_e4 == 0.0 && (*(int *)(iVar2 + 0x120) == 0)) &&
            ((*(uint *)(iVar2 + 0x14) & 0x200) == 0)))) {
          iVar8 = FUN_001054ec(param_1,1);
          uVar9 = *(undefined4 *)(iVar8 + 0x10);
          *(int *)(param_3 + 0x218) = *(int *)(param_3 + 0x218) + 1;
          uVar5 = FUN_00105594(param_1,2);
          FUN_00105894(uVar5,uVar12);
          uVar5 = FUN_00105594(iVar2,1);
          FUN_00106004(param_1,1,uVar5,0,uVar12);
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
          FUN_00106004(param_1,2,uVar5,0,uVar12);
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
          uVar5 = FUN_00105894(iVar2,uVar12);
          return uVar5;
        }
        iVar6 = FUN_001054ec(param_1,0);
        iVar6 = FUN_000f5cf0(param_1,2,*(undefined4 *)(iVar6 + 0x10),auStack_d0);
        if (((*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x25) && (iVar6 != 0)) &&
           ((local_cc == 0.0 &&
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
                if (uVar7 == 0) {
                  fVar1 = 1.0;
                }
                else {
                  fVar1 = 0.0;
                }
                fparam_1 = (double)fVar1;
                piVar4 = (int *)0x0;
                ((void (*)())FUN_000f79c4)(param_1,param_3,1,fparam_1,fparam_1,fparam_1,fparam_1);
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
              uVar5 = FUN_00105894(iVar2,uVar12);
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
                FUN_00106004(param_1,1,piVar4,0,uVar12);
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
  void *pvVar16;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  code *a7;
  int iVar17;
  uint uVar18;
  int iVar19;
  int *piVar20;
  int *piVar21;
  int *piVar22;
  undefined4 uVar23;
  uint uVar24;
  uint *puVar25;
  int *piVar26;
  int iVar27;
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
  
  uVar18 = *(uint *)(*(int *)(param_1 + 0x10) + 4);
  iVar5 = uVar18 << 2;
  iStack00000018 = param_1;
  iVar3 = FUN_00193e18(*(undefined4 *)(*(int *)(param_2 + 8) + 0x378),iVar5);
  iVar4 = FUN_00193e18(*(undefined4 *)(*(int *)(param_2 + 8) + 0x378),iVar5);
  iVar5 = FUN_00193e18(*(undefined4 *)(*(int *)(param_2 + 8) + 0x378),iVar5);
  if (0 < (int)uVar18) {
    uVar24 = 0;
    iVar17 = 0;
    iVar19 = 0;
    do {
      puVar25 = *(uint **)(iStack00000018 + 0x10);
      if (uVar24 < *puVar25) {
        uVar6 = puVar25[1];
        if (uVar6 <= uVar24) {
          _memset(uVar6 * 4 + puVar25[2],0,(uVar24 - uVar6) * 4 + 4);
          puVar25[1] = uVar24 + 1;
        }
        puVar7 = (undefined4 *)(iVar19 + puVar25[2]);
      }
      else {
        puVar7 = (undefined4 *)FUN_0019423c(puVar25,uVar24);
      }
      uVar24 = uVar24 + 1;
      piVar21 = (int *)*puVar7;
      bVar2 = false;
      *(int **)(iVar19 + iVar3) = piVar21;
      *(undefined4 *)(iVar19 + iVar4) = 0;
      *(undefined4 *)(iVar19 + iVar5) = 0;
      while ((((*(int *)(piVar21[0x22] + 8) == 0x13 && ((piVar21[5] & 0x200U) == 0)) &&
              (iVar9 = FUN_0010497c(piVar21,param_2), iVar9 != 0)) && (piVar21[0x48] == 0))) {
        piVar10 = (int *)piVar21[4];
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
        puVar25 = (uint *)(piVar10 + 0x2e);
        for (iVar9 = 1; iVar8 = (**(code **)(*piVar10 + 0x14))(piVar10), iVar9 <= iVar8;
            iVar9 = iVar9 + 1) {
          piVar20 = (int *)FUN_00105594(piVar10,iVar9);
          if (piVar21 == piVar20) {
            iVar8 = FUN_001054ec(piVar10,iVar9);
            iVar8 = FUN_000f3190(*(undefined4 *)(iVar8 + 0x10));
            if ((iVar8 == 0) || ((*puVar25 & 2) != 0)) {
              bVar1 = true;
            }
            *(int *)(iVar19 + iVar5) = iVar9;
          }
          puVar25 = puVar25 + 6;
        }
        if (bVar1) break;
        bVar2 = true;
        piVar21 = piVar10;
      }
      if (bVar2) {
        if (((piVar21[5] & 0x200U) != 0) ||
           ((*(int *)(piVar21[0x22] + 8) != 0x12 && (*(int *)(piVar21[0x22] + 8) != 0x14))))
        goto LAB_0015a760;
        *(undefined4 *)(iVar19 + iVar4) = piVar21;
        iVar17 = iVar17 + 1;
      }
      else if (((*(int *)(piVar21[0x22] + 8) == 0x14) && ((piVar21[5] & 0x200U) == 0)) &&
              ((iVar9 = FUN_00105594(piVar21,1), iStack00000018 == iVar9 ||
               (iVar9 = FUN_00105594(piVar21,2), iStack00000018 == iVar9)))) {
        *(undefined4 *)(iVar19 + iVar4) = piVar21;
        iVar8 = FUN_00105594(piVar21,1);
        iVar9 = 2;
        if (iStack00000018 == iVar8) {
          iVar9 = 1;
        }
        iVar17 = iVar17 + 1;
        *(int *)(iVar19 + iVar5) = iVar9;
      }
      else {
LAB_0015a760:
        *(undefined4 *)(iVar19 + iVar3) = 0;
      }
      iVar19 = iVar19 + 4;
    } while (uVar18 != uVar24);
    if (1 < iVar17) {
      iVar17 = 0;
      uVar23 = 0;
      do {
        iVar19 = iVar17 * 4;
        piVar21 = (int *)(iVar3 + iVar19);
        if ((*(int *)(iVar3 + iVar19) == 0) ||
           ((*(uint *)(*(int *)(iVar3 + iVar19) + 0x14) & 1) == 0)) {
LAB_0015a9bc:
          iVar17 = iVar17 + 1;
        }
        else {
          local_60 = (int *)(iVar4 + iVar19);
          iVar9 = 1;
          if ((*(uint *)(*(int *)(iVar4 + iVar19) + 0x14) & 1) == 0) goto LAB_0015a9bc;
          for (; iVar8 = (**(code **)(*(int *)*piVar21 + 0x14))((int *)*piVar21), iVar9 <= iVar8;
              iVar9 = iVar9 + 1) {
            iVar8 = FUN_00105594(*piVar21,iVar9);
            if (iStack00000018 == iVar8) {
              iVar8 = FUN_001054ec(*piVar21,iVar9);
              local_5c = *(int *)(iVar8 + 0x10);
              local_6c = *(uint *)(iVar9 * 0x18 + *piVar21 + 0xa0) >> 1 & 1;
              local_68 = iVar9;
              goto LAB_0015aa4c;
            }
          }
          local_68 = 0;
          local_6c = 0;
LAB_0015aa4c:
          local_70 = iVar17 + 1;
          iVar17 = local_70;
          if (local_70 < (int)uVar18) {
            iVar17 = local_70 * 4;
            piVar22 = (int *)(iVar4 + iVar17);
            piVar20 = (int *)(iVar3 + iVar17);
            local_64 = 3 - local_68;
            piVar10 = (int *)(iVar5 + iVar17);
            iVar9 = 0;
            local_54 = local_64 * 0x18 + 0x80;
            do {
              piVar11 = (int *)*piVar20;
              if ((((piVar11 != (int *)0x0) && ((piVar11[5] & 1U) != 0)) &&
                  ((*(uint *)(*piVar22 + 0x14) & 1) != 0)) &&
                 ((piVar11 != (int *)*piVar21 && (*local_60 == *piVar22)))) {
                if ((*(int *)(iVar5 + iVar19) != *piVar10) &&
                   (((*(int *)(*(int *)(*local_60 + 0x88) + 8) != 0x14 ||
                     (*(int *)(iVar5 + iVar19) == 3)) || (*piVar10 == 3)))) {
                  uVar24 = 0;
                  for (iVar17 = 1; iVar8 = (**(code **)(*piVar11 + 0x14))(piVar11), iVar17 <= iVar8;
                      iVar17 = iVar17 + 1) {
                    iVar8 = FUN_00105594(*piVar20,iVar17);
                    if (iStack00000018 == iVar8) {
                      iVar8 = FUN_001054ec(*piVar20,iVar17);
                      local_58 = *(int *)(iVar8 + 0x10);
                      piVar11 = (int *)*piVar20;
                      uVar24 = (uint)piVar11[iVar17 * 6 + 0x28] >> 1 & 1;
                      if ((local_58 == local_5c) && (uVar6 = local_6c, local_6c == uVar24))
                      goto LAB_0015abb0;
                    }
                    else {
                      piVar11 = (int *)*piVar20;
                    }
                  }
                  local_74 = 0;
                  uVar6 = uVar24;
                  iVar17 = local_74;
LAB_0015abb0:
                  local_74 = iVar17;
                  if ((local_58 == local_5c) && (local_6c == uVar6)) {
                    *(int *)(param_2 + 0x1cc) = *(int *)(param_2 + 0x1cc) + 1;
                    iVar17 = *piVar21;
                    if (iVar17 != *local_60) {
                      piVar11 = *(int **)(iVar17 + 0x10);
                      if (*piVar11 == 0) {
                        puVar7 = (undefined4 *)FUN_0019423c(piVar11,0);
                        iVar17 = *piVar21;
                      }
                      else {
                        if (piVar11[1] == 0) {
                          *(undefined4 *)piVar11[2] = 0;
                          piVar11[1] = 1;
                          iVar17 = *piVar21;
                        }
                        puVar7 = (undefined4 *)piVar11[2];
                      }
                      piVar26 = (int *)*puVar7;
                      piVar13 = piVar26 + 0x26;
                      local_78 = FUN_00105594(iVar17,local_64);
                      iVar17 = FUN_001054ec(*piVar21,local_64);
                      piVar11 = (int *)*piVar21;
                      iVar17 = *(int *)(iVar17 + 0x10);
                      uVar6 = *(uint *)((int)piVar11 + local_54 + 0x20);
                      uVar24 = piVar11[local_68 * 6 + 0x28];
                      (**(code **)(*piVar11 + 0xc))
                                (piVar11,1,*(undefined4 *)(param_2 + 8),in_r6,in_r7,in_r8,uVar6,
                                 *(code **)(*piVar11 + 0xc));
                      for (iVar8 = 1; iVar12 = (**(code **)(*piVar26 + 0x14))(piVar26),
                          iVar8 <= iVar12; iVar8 = iVar8 + 1) {
                        iVar12 = FUN_00105594(piVar26,iVar8);
                        if (iVar12 == *piVar21) {
                          in_r7 = *(undefined4 *)(param_2 + 8);
                          in_r6 = 1;
                          FUN_00106004(piVar26,iVar8,local_78,1,in_r7);
                          if (iVar8 == 0) {
                            piVar26[0x27] = iVar17;
                          }
                          else {
                            iVar12 = FUN_001054ec(piVar26,iVar8);
                            *(int *)(iVar12 + 0x10) = iVar17;
                          }
                          FUN_00103d50(piVar13 + 3,2,uVar6 >> 1 & 1);
                          FUN_00103d50(piVar13 + 3,1,(uVar24 ^ uVar6) & 1 ^ piVar13[8] & 1U);
                        }
                        piVar13 = piVar13 + 6;
                      }
                    }
                    iVar17 = *piVar20;
                    if (iVar17 != *piVar22) {
                      piVar11 = *(int **)(iVar17 + 0x10);
                      if (*piVar11 == 0) {
                        puVar7 = (undefined4 *)FUN_0019423c(piVar11,0);
                        iVar17 = *piVar20;
                      }
                      else {
                        if (piVar11[1] == 0) {
                          *(undefined4 *)piVar11[2] = 0;
                          piVar11[1] = 1;
                          iVar17 = *piVar20;
                        }
                        puVar7 = (undefined4 *)piVar11[2];
                      }
                      piVar26 = (int *)*puVar7;
                      iVar8 = 3 - local_74;
                      piVar13 = piVar26 + 0x26;
                      local_7c = FUN_00105594(iVar17,iVar8);
                      iVar17 = FUN_001054ec(*piVar20,iVar8);
                      piVar11 = (int *)*piVar20;
                      iVar17 = *(int *)(iVar17 + 0x10);
                      a7 = *(code **)(*piVar11 + 0xc);
                      uVar6 = piVar11[iVar8 * 6 + 0x28];
                      uVar24 = piVar11[local_74 * 6 + 0x28];
                      (*a7)(piVar11,1,*(undefined4 *)(param_2 + 8),in_r6,in_r7,in_r8,*piVar11,a7);
                      for (iVar8 = 1; iVar12 = (**(code **)(*piVar26 + 0x14))(piVar26),
                          iVar8 <= iVar12; iVar8 = iVar8 + 1) {
                        iVar12 = FUN_00105594(piVar26,iVar8);
                        if (iVar12 == *piVar20) {
                          FUN_00106004(piVar26,iVar8,local_7c,1,*(undefined4 *)(param_2 + 8));
                          if (iVar8 == 0) {
                            piVar26[0x27] = iVar17;
                          }
                          else {
                            iVar12 = FUN_001054ec(piVar26,iVar8);
                            *(int *)(iVar12 + 0x10) = iVar17;
                          }
                          FUN_00103d50(piVar13 + 3,2,uVar6 >> 1 & 1);
                          FUN_00103d50(piVar13 + 3,1,(uVar24 ^ uVar6) & 1 ^ piVar13[8] & 1U);
                        }
                        piVar13 = piVar13 + 6;
                      }
                    }
                    piVar11 = FUN_001043f0(0x13,*(undefined4 *)(param_2 + 8));
                    FUN_00106004(piVar11,1,iStack00000018,1,*(undefined4 *)(param_2 + 8));
                    iVar17 = FUN_001054ec(piVar11,1);
                    *(int *)(iVar17 + 0x10) = local_5c;
                    FUN_00103d50(piVar11 + 0x29,2,local_6c);
                    piVar11[0x26] = 0;
                    piVar11[0x25] = piVar11[0x53];
                    iVar17 = FUN_001054ec(*piVar22,0);
                    piVar11[0x27] = *(int *)(iVar17 + 0x10);
                    piVar11[0x48] = *(int *)(*piVar22 + 0x120);
                    piVar11[0x49] = *(int *)(*piVar22 + 0x124);
                    iVar17 = *piVar22;
                    iVar8 = *(int *)(*(int *)(iVar17 + 0x10) + 4);
                    uVar24 = iVar8 - 1;
                    if (-1 < (int)uVar24) {
                      iVar12 = uVar24 * 4;
                      local_80 = 0;
                      do {
                        puVar25 = *(uint **)(iVar17 + 0x10);
                        if (uVar24 < *puVar25) {
                          uVar6 = puVar25[1];
                          if (uVar6 <= uVar24) {
                            _memset(uVar6 * 4 + puVar25[2],0,(uVar24 - uVar6) * 4 + 4);
                            puVar25[1] = uVar24 + 1;
                          }
                          piVar13 = (int *)(iVar12 + puVar25[2]);
                        }
                        else {
                          piVar13 = (int *)FUN_0019423c(puVar25,uVar24);
                        }
                        iVar17 = *piVar13;
                        iVar27 = *(int *)(iVar17 + 0x84);
                        if ((*(uint *)(iVar17 + 0x14) & 0x200) == 0) {
LAB_0015b040:
                          if (0 < iVar27) {
                            iVar14 = 1;
                            do {
                              iVar15 = FUN_00105594(iVar17,iVar14);
                              if (iVar15 == *piVar22) {
                                FUN_00106004(iVar17,iVar14,piVar11,1,*(undefined4 *)(param_2 + 8));
                                break;
                              }
                              iVar14 = iVar14 + 1;
                            } while (iVar14 <= iVar27);
                          }
                        }
                        else {
                          iVar14 = FUN_00105594(iVar17,iVar27);
                          iVar27 = iVar27 + -1;
                          if (iVar14 != *piVar22) goto LAB_0015b040;
                          FUN_00106804(iVar17,piVar11,1,*(undefined4 *)(param_2 + 8));
                        }
                        uVar24 = uVar24 - 1;
                        iVar12 = iVar12 + -4;
                        local_80 = local_80 + 1;
                        if (iVar8 == local_80) break;
                        iVar17 = *piVar22;
                      } while( true );
                    }
                    iVar17 = FUN_001054ec(piVar11,0);
                    FUN_000f3908(&local_88,*(undefined4 *)(iVar17 + 0x10));
                    FUN_000f3340(&local_84,0x10203,local_88);
                    uVar23 = local_84;
                    iVar17 = FUN_001054ec(piVar11,2);
                    *(undefined4 *)(iVar17 + 0x10) = uVar23;
                    FUN_000e7738(*(undefined4 *)(*piVar22 + 0x158),*piVar22,piVar11);
                    if (*piVar21 == *local_60) {
                      piVar13 = (int *)*piVar22;
LAB_0015b134:
                      (**(code **)(*piVar13 + 0xc))(piVar13,1,*(undefined4 *)(param_2 + 8));
                      pvVar16 = FUN_001043f0(0x12,*(undefined4 *)(param_2 + 8));
                      uVar23 = FUN_00105594(*piVar22,3);
                      FUN_00106004(pvVar16,2,uVar23,1,*(undefined4 *)(param_2 + 8));
                      uVar23 = FUN_001054ec(*piVar22,3);
                      FUN_001062c0(pvVar16,2,uVar23,*(undefined4 *)(param_2 + 8));
                      if ((*piVar21 == *local_60) && (local_68 == 1)) {
                        iVar17 = *piVar22;
LAB_0015b1ec:
                        uVar23 = FUN_00105594(iVar17,2);
                        FUN_00106004(pvVar16,1,uVar23,1,*(undefined4 *)(param_2 + 8));
                        iVar17 = *piVar22;
                        uVar23 = 2;
                      }
                      else {
                        iVar17 = *piVar22;
                        if ((*piVar20 == iVar17) && (local_74 == 1)) goto LAB_0015b1ec;
                        uVar23 = FUN_00105594(iVar17,1);
                        FUN_00106004(pvVar16,1,uVar23,1,*(undefined4 *)(param_2 + 8));
                        iVar17 = *piVar22;
                        uVar23 = 1;
                      }
                      uVar23 = FUN_001054ec(iVar17,uVar23);
                      FUN_001062c0(pvVar16,1,uVar23,*(undefined4 *)(param_2 + 8));
                      FUN_00103d50((int)pvVar16 + 0xa4,1,
                                   (*(uint *)(*piVar22 + 0xd0) ^ *(uint *)(*piVar22 + 0xb8)) & 1);
                      *(undefined4 *)((int)pvVar16 + 0x98) = 0;
                      *(undefined4 *)((int)pvVar16 + 0x94) = *(undefined4 *)((int)pvVar16 + 0x14c);
                      iVar17 = FUN_001054ec(*piVar22,0);
                      in_r6 = 1;
                      *(undefined4 *)((int)pvVar16 + 0x9c) = *(undefined4 *)(iVar17 + 0x10);
                      in_r7 = *(undefined4 *)(param_2 + 8);
                      FUN_00106004(piVar11,2,pvVar16,1,in_r7);
                      FUN_000e7700(piVar11[0x56],piVar11,pvVar16);
                    }
                    else {
                      piVar13 = (int *)*piVar22;
                      if ((int *)*piVar20 == piVar13) goto LAB_0015b134;
                      in_r7 = *(undefined4 *)(param_2 + 8);
                      in_r6 = 1;
                      FUN_00106004(piVar11,2,piVar13,1,in_r7);
                      *(undefined4 *)(*piVar22 + 0x120) = 0;
                      *(undefined4 *)(*piVar22 + 0x124) = 0;
                    }
                    *piVar20 = (int)piVar11;
                    *piVar22 = 0;
                    *piVar10 = 0;
                    while (piVar13 = piVar11, *(int *)(piVar13[0x22] + 8) == 0x13) {
                      uVar24 = piVar13[5];
                      if ((uVar24 & 0x200) != 0) goto LAB_0015b3f0;
                      iVar17 = FUN_0010497c(piVar13,param_2);
                      if ((iVar17 == 0) || (piVar13[0x48] != 0)) break;
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
                      puVar25 = (uint *)(piVar11 + 0x2e);
                      for (iVar17 = 1; iVar8 = (**(code **)(*piVar11 + 0x14))(piVar11),
                          iVar17 <= iVar8; iVar17 = iVar17 + 1) {
                        piVar26 = (int *)FUN_00105594(piVar11,iVar17);
                        if (piVar26 == piVar13) {
                          iVar8 = FUN_001054ec(piVar11,iVar17);
                          iVar8 = FUN_000f3190(*(undefined4 *)(iVar8 + 0x10));
                          if ((iVar8 == 0) || ((*puVar25 & 2) != 0)) {
                            bVar2 = true;
                          }
                          *piVar10 = iVar17;
                        }
                        puVar25 = puVar25 + 6;
                      }
                      if (bVar2) break;
                    }
                    uVar24 = piVar13[5];
LAB_0015b3f0:
                    if (((uVar24 & 0x200) == 0) &&
                       ((*(int *)(piVar13[0x22] + 8) == 0x12 ||
                        (*(int *)(piVar13[0x22] + 8) == 0x14)))) {
                      *piVar22 = (int)piVar13;
                    }
                    else {
                      *piVar20 = 0;
                    }
                    if ((*(uint *)(*piVar21 + 0x14) & 1) == 0) {
                      uVar23 = 1;
                      iVar17 = local_70;
                      break;
                    }
                    uVar23 = 1;
                  }
                }
              }
              iVar9 = iVar9 + 1;
              piVar20 = piVar20 + 1;
              piVar10 = piVar10 + 1;
              piVar22 = piVar22 + 1;
              iVar17 = local_70;
            } while (uVar18 - local_70 != iVar9);
          }
        }
        if ((int)uVar18 <= iVar17) {
          FUN_00193cc0(*(undefined4 *)(*(int *)(param_2 + 8) + 0x378),iVar5);
          FUN_00193cc0(*(undefined4 *)(*(int *)(param_2 + 8) + 0x378),iVar4);
          FUN_00193cc0(*(undefined4 *)(*(int *)(param_2 + 8) + 0x378),iVar3);
          return uVar23;
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
  int *a0;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  undefined4 local_48;
  byte local_44 [24];
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x31) {
    iVar3 = FUN_001054ec(param_1,1);
    iVar3 = FUN_000f3190(*(undefined4 *)(iVar3 + 0x10));
    if (iVar3 == 0) {
      a0 = (int *)FUN_00105594(param_1,1);
      iVar3 = (**(code **)(*a0 + 0x5c))(a0);
      if (((iVar3 == 0) && ((a0[5] & 0x200U) == 0)) &&
         ((iVar3 = FUN_0011379c(*(undefined4 *)(param_2 + 8),a0), iVar3 != 0 ||
          (iVar3 = FUN_001131c0(*(undefined4 *)(a0[0x22] + 8),*(undefined4 *)(param_2 + 8)),
          iVar3 != 0)))) {
        iVar3 = FUN_001054ec(param_1,1);
        uVar8 = 0;
        local_48 = *(undefined4 *)(iVar3 + 0x10);
        do {
          iVar3 = FUN_001054ec(param_1,0);
          if ((((*(char *)(uVar8 + iVar3 + 0x10) != '\x01') &&
               (uVar10 = (uint)local_44[uVar8 - 4], uVar10 != 4)) && (uVar8 != uVar10)) &&
             (iVar3 = FUN_001054ec(a0,0), *(char *)(uVar10 + iVar3 + 0x10) != '\x01')) {
            return;
          }
          bVar1 = uVar8 != 3;
          uVar8 = uVar8 + 1;
        } while (bVar1);
        puVar11 = (uint *)a0[4];
        uVar10 = 0;
        uVar8 = puVar11[1];
        if (uVar8 != 0) {
          do {
            if (uVar10 < *puVar11) {
              if (uVar8 <= uVar10) {
                _memset(uVar8 * 4 + puVar11[2],0,(uVar10 - uVar8) * 4 + 4);
                puVar11[1] = uVar10 + 1;
              }
              piVar4 = (int *)(uVar10 * 4 + puVar11[2]);
            }
            else {
              piVar4 = (int *)FUN_0019423c(puVar11,uVar10);
            }
            iVar3 = *piVar4;
            if (((*(uint *)(iVar3 + 0x14) & 0x200) != 0) &&
               (piVar4 = (int *)FUN_00105594(iVar3,*(undefined4 *)(iVar3 + 0x84)), a0 == piVar4)) {
              return;
            }
            puVar11 = (uint *)a0[4];
            uVar10 = uVar10 + 1;
            uVar8 = puVar11[1];
          } while (uVar10 < uVar8);
        }
        *(int *)(param_2 + 0x164) = *(int *)(param_2 + 0x164) + 1;
        local_44[0] = 4;
        local_44[1] = 4;
        local_44[2] = 4;
        local_44[3] = 4;
        uVar8 = 0;
        FUN_001054ec(a0,0);
        piVar4 = a0;
        do {
          iVar3 = FUN_001054ec(param_1,0);
          if (*(char *)(uVar8 + iVar3 + 0x10) != '\x01') {
            bVar2 = local_44[uVar8 - 4];
            uVar10 = (uint)bVar2;
            if ((uVar10 != 4) && (uVar10 != uVar8)) {
              iVar9 = 1;
              iVar3 = FUN_0011379c(*(undefined4 *)(param_2 + 8),a0);
              if (iVar3 != 0) {
                for (; iVar3 = (**(code **)(*a0 + 0x14))(a0), iVar9 <= iVar3; iVar9 = iVar9 + 1) {
                  iVar3 = FUN_001054ec(a0,iVar9);
                  (**(code **)(*a0 + 0x88))(a0,iVar9,uVar8,*(undefined1 *)(uVar10 + iVar3 + 0x10));
                }
              }
              iVar3 = FUN_001054ec(a0,0);
              if (*(char *)(uVar8 + iVar3 + 0x10) != '\0') {
                *(undefined1 *)(piVar4 + 0x27) = 0;
              }
              local_44[uVar8] = bVar2;
            }
          }
          bVar1 = uVar8 != 3;
          piVar4 = (int *)((int)piVar4 + 1);
          uVar8 = uVar8 + 1;
        } while (bVar1);
        puVar11 = (uint *)a0[4];
        uVar10 = 0;
        uVar8 = puVar11[1];
        if (uVar8 != 0) {
          do {
            if (uVar10 < *puVar11) {
              if (uVar8 <= uVar10) {
                _memset(uVar8 * 4 + puVar11[2],0,(uVar10 - uVar8) * 4 + 4);
                puVar11[1] = uVar10 + 1;
              }
              puVar5 = (undefined4 *)(uVar10 * 4 + puVar11[2]);
            }
            else {
              puVar5 = (undefined4 *)FUN_0019423c(puVar11,uVar10);
            }
            uVar10 = uVar10 + 1;
            piVar4 = (int *)*puVar5;
            for (iVar3 = 1; iVar9 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar3 <= iVar9;
                iVar3 = iVar3 + 1) {
              piVar6 = (int *)FUN_00105594(piVar4,iVar3);
              if (a0 == piVar6) {
                iVar9 = 0;
                do {
                  iVar7 = FUN_001054ec(piVar4,iVar3);
                  iVar12 = 3;
                  if (*(byte *)(iVar9 + iVar7 + 0x10) == local_44[iVar9]) {
                    (**(code **)(*piVar4 + 0x88))(piVar4,iVar3,iVar9,iVar9);
                  }
                  else {
                    do {
                      iVar12 = iVar12 + -1;
                    } while (iVar12 != 0);
                  }
                  bVar1 = iVar9 != 3;
                  iVar9 = iVar9 + 1;
                } while (bVar1);
              }
            }
            puVar11 = (uint *)a0[4];
            uVar8 = puVar11[1];
          } while (uVar10 < uVar8);
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
        iVar1 = (**(code **)(*local_68 + 100))(local_68);
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
            iVar1 = (**(code **)(*piVar3 + 0x48))(piVar3);
            if (iVar1 == 0) {
              iVar1 = (**(code **)(*local_64 + 0x48))(local_64);
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
            iVar1 = ((int (*)())FUN_0015b8b8)(&local_64,(uint)*(byte *)(uVar5 + iVar1 + 0x10));
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
              if (local_5c != (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0))
              {
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
          iVar1 = ((int (*)())FUN_0015b8b8)(&local_64,(uint)*(byte *)(uVar5 + iVar1 + 0x10));
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
  iVar9 = (**(code **)(*piVar13 + 0x60))(piVar13);
  if (iVar9 != 0) {
    return 0;
  }
  piVar13 = (int *)FUN_00105594(iVar17,2);
  iVar9 = (**(code **)(*piVar13 + 0x60))(piVar13);
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
    iVar7 = (**(code **)(*piVar20 + 0x60))(piVar20);
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
      piVar20[0x21] = 2;
      iVar7 = 0;
      ((void (*)())FUN_000f79c4)(piVar20,param_2,2,1.0,1.0,1.0,1.0);
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
          piVar20[0x21] = iVar17;
          ((void (*)())FUN_000f79c4)(piVar20,param_2,iVar17,1.0,1.0,1.0,1.0);
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
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint *puVar18;
  double fparam_1;
  undefined8 uVar19;
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
        uVar19 = FUN_001054ec(param_1,uVar17);
        local_84 = *(undefined4 *)((int)((ulonglong)uVar19 >> 0x20) + 0x10);
        iVar5 = (**(code **)(*param_1 + 0x14))
                          (param_1,(int)uVar19,in_r5,in_r6,in_r7,in_r8,*(code **)(*param_1 + 0x14));
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
                  _memset(uVar7 * 4 + puVar18[2],0,(uVar16 - uVar7) * 4 + 4);
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
          if (uVar7 == uVar13) {
            fVar3 = 1.0;
LAB_0015ca9c:
            fparam_1 = (double)fVar3;
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
              ((void (*)())FUN_000f79c4)(piVar9,param_2,2,fparam_1,fparam_1,fparam_1,fparam_1);
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
                  if ((iVar5 != 0) && (fparam_1 == (double)local_74)) {
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
              ((void (*)())FUN_000f79c4)(piVar8,param_2,iVar5,fparam_1,fparam_1,fparam_1,fparam_1);
              iVar15 = FUN_001054ec(piVar8,iVar5);
              *(undefined4 *)(iVar15 + 0x10) = 0x4040404;
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
          else if ((uVar7 == uVar11) || (uVar7 == uVar12)) {
            fVar3 = 0.0;
            goto LAB_0015ca9c;
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

/* FUN_0015ceb0 @ 0x15ceb0 (3720 bytes) */
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
  int *a0;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int *piVar23;
  int iVar24;
  int iVar25;
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
  a0 = (int *)FUN_00105594(param_1,param_1[0x21]);
  if (a0 == (int *)0x0) {
    return 0;
  }
  if ((*(uint *)(*(int *)(*(int *)(param_2 + 8) + 0x30c) + 8) & 0x100) == 0) {
    return 0;
  }
  iVar24 = *(int *)(a0[0x22] + 8);
  if (*(int *)(param_1[0x22] + 8) == 0x12) {
    if (iVar24 == 0x12) {
      piVar8 = (int *)FUN_00105594(param_1,1);
      piVar9 = (int *)FUN_00105594(param_1,2);
      piVar10 = (int *)FUN_00105594(a0,1);
      piVar15 = (int *)FUN_00105594(a0,2);
      bVar1 = piVar8 == piVar15;
      if (bVar1) {
        bVar1 = piVar9 == piVar10;
        FUN_0010ac38(a0,1,2,*(uint *)(param_2 + 8));
        bVar4 = true;
        bVar3 = false;
        piVar23 = piVar8;
        piVar15 = piVar10;
      }
      else {
        piVar23 = piVar9;
        if (piVar9 == piVar10) {
          FUN_0010ac38(param_1,1,2,*(uint *)(param_2 + 8));
          bVar4 = false;
          bVar3 = true;
          piVar9 = piVar8;
        }
        else {
          bVar1 = piVar9 == piVar15;
          if (bVar1) {
            bVar1 = piVar8 == piVar10;
            FUN_0010ac38(a0,1,2,*(uint *)(param_2 + 8));
            FUN_0010ac38(param_1,1,2,*(uint *)(param_2 + 8));
            bVar4 = true;
            bVar3 = true;
            piVar15 = piVar10;
            piVar9 = piVar8;
          }
          else {
            if (piVar8 != piVar10) {
              return 0;
            }
            bVar4 = false;
            bVar3 = false;
            piVar23 = piVar10;
          }
        }
      }
      iVar24 = FUN_001054ec(param_1,0);
      local_fc = *(int *)(iVar24 + 0x10);
      iVar24 = FUN_001054ec(a0,0);
      local_100 = *(int *)(iVar24 + 0x10);
      if ((((!bVar1) && (a0[0x49] == param_1[0x49])) && (a0[0x48] == param_1[0x48])) &&
         ((local_fc != 0x1010100 && (*(int *)(iVar24 + 0x10) != 0x1010100)))) {
        iVar7 = 4;
        local_64 = &local_100;
        iVar24 = 0;
        do {
          if ((*(char *)(iVar24 + (int)&local_100) != '\x01') &&
             (*(char *)((int)&local_fc + iVar24) != '\x01')) goto LAB_0015d1a4;
          iVar24 = iVar24 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        if (((((a0[0x2e] & 1U) == (param_1[0x2e] & 1U)) && ((a0[0x34] & 1U) == (param_1[0x34] & 1U))
             ) && (((uint)a0[0x2e] >> 1 & 1) == ((uint)param_1[0x2e] >> 1 & 1))) &&
           (iVar24 = FUN_00146de0(piVar15,piVar9), iVar24 == 0)) {
          *(int *)(param_2 + 0x280) = *(int *)(param_2 + 0x280) + 1;
          FUN_000f2f84(&local_68,local_100,local_fc);
          local_104 = local_68;
          piVar9 = (int *)((int (*)())FUN_0010bed0)(2,local_68,piVar9,param_2,*(undefined4 *)(param_2 + 8),1.0);
          if (*(int *)(param_2 + 0x478) < piVar15[0x58]) {
            piVar15[0x58] = piVar15[0x58] + 1;
          }
          else {
            piVar15[0x58] = *(int *)(param_2 + 0x478) + 1;
          }
          piVar15 = (int *)((int (*)())FUN_0010bed0)(2,local_104,piVar15,param_2,*(undefined4 *)(param_2 + 8),1.0
                                       );
          iVar24 = FUN_001054ec(param_1,2);
          uVar12 = *(undefined4 *)(iVar24 + 0x10);
          iVar24 = FUN_001054ec(piVar9,1);
          *(undefined4 *)(iVar24 + 0x10) = uVar12;
          iVar24 = FUN_001054ec(a0,2);
          uVar12 = *(undefined4 *)(iVar24 + 0x10);
          iVar24 = FUN_001054ec(piVar15,1);
          *(undefined4 *)(iVar24 + 0x10) = uVar12;
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
          uVar12 = FUN_001054ec(a0,1);
          FUN_00104730(&local_a0,uVar12);
          uVar12 = FUN_001054ec(a0,2);
          FUN_00104730(local_e8,uVar12);
          uVar12 = FUN_001054ec(param_1,1);
          FUN_00104730(&local_b8,uVar12);
          uVar12 = FUN_001054ec(param_1,2);
          FUN_00104730(&local_d0,uVar12);
          iVar24 = FUN_001054ec(param_1,1);
          local_f8 = *(int *)(iVar24 + 0x10);
          iVar24 = FUN_001054ec(a0,1);
          local_108 = *(int *)(iVar24 + 0x10);
          local_f4[0] = 0;
          local_f4[1] = 0;
          local_f4[2] = 0;
          FUN_00103f18(param_1,local_f4,0xffffffff);
          local_88 = 0;
          local_84 = 0;
          local_74 = 0;
          if ((a0[5] & 0x200U) != 0) {
            FUN_00104d3c(a0,&local_88);
          }
          iVar24 = param_1[1];
          FUN_0019401c(param_1);
          FUN_00108304(param_1,0x14,*(undefined4 *)(param_2 + 8));
          FUN_000e7738(*(undefined4 *)(iVar24 + 0x158),iVar24,param_1);
          FUN_00103f44(param_1,local_f4);
          iVar24 = a0[0x49];
          param_1[0x48] = a0[0x48];
          param_1[0x49] = iVar24;
          uVar12 = FUN_001054ec(param_1,3);
          FUN_00104730(uVar12,&local_b8);
          uVar12 = FUN_001054ec(param_1,1);
          FUN_00104730(uVar12,&local_d0);
          uVar12 = FUN_001054ec(param_1,2);
          FUN_00104730(uVar12,local_e8);
          FUN_00106004(param_1,1,piVar9,0,*(undefined4 *)(param_2 + 8));
          FUN_00106004(param_1,2,piVar15,0,*(undefined4 *)(param_2 + 8));
          FUN_00103d50(param_1 + 0x29,1,0);
          param_1[0x26] = 0;
          iVar24 = 0;
          param_1[0x25] = param_1[0x53];
          param_1[0x27] = local_104;
          do {
            if (*(char *)((int)&local_104 + iVar24) == '\0') {
              (**(code **)(*param_1 + 0x88))(param_1,1,iVar24,iVar24);
              (**(code **)(*param_1 + 0x88))(param_1,2,iVar24,iVar24);
              iVar7 = FUN_001054ec(piVar15,1);
              cVar2 = *(char *)(iVar24 + iVar7 + 0x10);
              iVar7 = FUN_001054ec(piVar9,1);
              if (cVar2 == '\x04') {
                if (*(char *)(iVar24 + iVar7 + 0x10) == '\x04') goto LAB_0015d5cc;
                (**(code **)(*piVar15 + 0x88))(piVar15,2,iVar24,iVar24);
                piVar8 = &local_f8;
                pcVar5 = *(code **)(*param_1 + 0x88);
              }
              else {
                (**(code **)(*piVar9 + 0x88))(piVar9,2,iVar24,iVar24);
                piVar8 = &local_108;
                pcVar5 = *(code **)(*param_1 + 0x88);
              }
              (*pcVar5)(param_1,3,iVar24,*(undefined1 *)(iVar24 + (int)piVar8));
            }
            else {
              (**(code **)(*param_1 + 0x88))(param_1,1,iVar24,4);
              (**(code **)(*param_1 + 0x88))(param_1,2,iVar24,4);
              (**(code **)(*param_1 + 0x88))(param_1,3,iVar24,4);
            }
LAB_0015d5cc:
            bVar1 = iVar24 == 3;
            iVar24 = iVar24 + 1;
            if (bVar1) {
              FUN_000e7700(param_1[0x56],param_1,piVar15);
              FUN_000e7700(param_1[0x56],param_1,piVar9);
              if (local_84 != 0) {
                FUN_00106b48(param_1,&local_88,0,*(undefined4 *)(param_2 + 8));
                if (*(int *)(param_2 + 0x478) < *(int *)(local_84 + 0x160)) {
                  *(int *)(local_84 + 0x160) = *(int *)(local_84 + 0x160) + 1;
                }
                else {
                  *(int *)(local_84 + 0x160) = *(int *)(param_2 + 0x478) + 1;
                }
              }
              for (iVar24 = 1; iVar7 = (**(code **)(*a0 + 0x14))(a0), iVar24 <= iVar7;
                  iVar24 = iVar24 + 1) {
                piVar8 = (int *)FUN_00105594(a0,iVar24);
                if ((((a0[5] & 1U) == 0) ||
                    (iVar7 = (**(code **)(*piVar8 + 0x5c))(piVar8), iVar7 == 0)) ||
                   (iVar7 = FUN_0010497c(piVar8,param_2), iVar7 != 0)) {
                  iVar7 = (**(code **)(*piVar8 + 0x60))(piVar8);
                  if (((iVar7 != 0) && ((a0[5] & 1U) == 0)) && (piVar23 != piVar8)) {
                    FUN_00105894(piVar8,*(undefined4 *)(param_2 + 8));
                  }
                }
                else {
                  FUN_001049a0(piVar8,param_2);
                  uVar17 = *(uint *)(param_2 + 0x30) >> 7 & 1;
                  iVar7 = FUN_0010af38(piVar8,param_2,uVar17);
                  FUN_00106004(a0,iVar24,iVar7,0,*(undefined4 *)(param_2 + 8));
                  if (uVar17 == 0) {
                    if (*(int *)(param_2 + 0x478) < *(int *)(iVar7 + 0x160)) {
                      *(int *)(iVar7 + 0x160) = *(int *)(iVar7 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar7 + 0x160) = *(int *)(param_2 + 0x478) + 1;
                    }
                  }
                  piVar8[0x58] = piVar8[0x58] + -1;
                }
              }
              piVar8 = (int *)FUN_00105594(piVar9,1);
              iVar24 = (**(code **)(*piVar8 + 0x60))(piVar8);
              if (iVar24 != 0) {
                uVar12 = FUN_00105594(piVar9,1);
                FUN_0010c670(uVar12,piVar9,*(undefined4 *)(param_2 + 8));
              }
              piVar9 = (int *)FUN_00105594(piVar15,1);
              iVar24 = (**(code **)(*piVar9 + 0x60))(piVar9);
              if (iVar24 != 0) {
                uVar12 = FUN_00105594(piVar15,1);
                FUN_0010c670(uVar12,piVar15,*(undefined4 *)(param_2 + 8));
              }
              FUN_00105894(a0,*(undefined4 *)(param_2 + 8));
              if (bVar4) {
                FUN_0010ac38(a0,1,2,*(uint *)(param_2 + 8));
                return 1;
              }
              return 1;
            }
          } while( true );
        }
      }
LAB_0015d1a4:
      if (bVar4) {
        FUN_0010ac38(a0,1,2,*(uint *)(param_2 + 8));
      }
      if (!bVar3) {
        return 0;
      }
      FUN_0010ac38(param_1,1,2,*(uint *)(param_2 + 8));
      return 0;
    }
    iVar7 = (**(code **)(*a0 + 100))(a0);
    piVar15 = a0;
    piVar9 = param_1;
    if (iVar7 != 0) goto LAB_0015cf80;
  }
  iVar7 = (**(code **)(*param_1 + 100))(param_1);
  if (iVar7 == 0) {
    return 0;
  }
  piVar15 = param_1;
  piVar9 = a0;
  if (iVar24 != 0x12) {
    return 0;
  }
LAB_0015cf80:
  iVar24 = FUN_00105594(piVar15,1);
  iVar7 = FUN_00105594(piVar9,1);
  if (iVar24 == iVar7) {
    iVar24 = 1;
    iVar7 = 2;
  }
  else {
    iVar24 = FUN_00105594(piVar15,1);
    iVar7 = FUN_00105594(piVar9,2);
    if (iVar24 != iVar7) {
      return 0;
    }
    iVar24 = 2;
    iVar7 = 1;
  }
  iVar11 = FUN_001054ec(param_1,0);
  local_108 = *(int *)(iVar11 + 0x10);
  iVar11 = FUN_001054ec(a0,0);
  local_104 = *(int *)(iVar11 + 0x10);
  if ((a0[0x49] == param_1[0x49]) && (a0[0x48] == param_1[0x48])) {
    if (((piVar15[0x2e] & 1U) == (piVar9[iVar24 * 6 + 0x28] & 1U)) &&
       (((uint)piVar15[0x2e] >> 1 & 1) == ((uint)piVar9[iVar24 * 6 + 0x28] >> 1 & 1))) {
      iVar6 = 0;
      iVar25 = 4;
      do {
        if ((*(char *)((int)&local_104 + iVar6) != '\x01') &&
           (*(char *)((int)&local_108 + iVar6) != '\x01')) {
          return 0;
        }
        iVar6 = iVar6 + 1;
        iVar25 = iVar25 + -1;
      } while (iVar25 != 0);
      if ((local_108 != 0x1010100) && (*(int *)(iVar11 + 0x10) != 0x1010100)) {
        *(int *)(param_2 + 0x280) = *(int *)(param_2 + 0x280) + 1;
        iVar11 = param_1[0x58] - *(int *)(param_2 + 0x478);
        uVar17 = *(uint *)(param_2 + 0x30) >> 7 & 1;
        if (iVar11 < 0) {
          iVar11 = 0;
        }
        iVar25 = 4;
        iVar18 = param_1[4];
        iVar19 = param_1[0x53];
        iVar20 = param_1[0x26];
        iVar21 = param_1[0x48];
        iVar6 = 0;
        iVar22 = param_1[0x49];
        local_64 = &local_100;
        local_100 = local_108;
        do {
          if (*(char *)((int)&local_104 + iVar6) != '\x01') {
            *(char *)(iVar6 + (int)&local_100) = *(char *)((int)&local_104 + iVar6);
          }
          iVar6 = iVar6 + 1;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        iVar25 = FUN_001054ec(piVar9,iVar7);
        iVar6 = 0;
        local_fc = *(int *)(iVar25 + 0x10);
        iVar25 = 4;
        do {
          if (*(char *)(iVar6 + (int)local_64) == '\0') {
            *(char *)((int)&local_fc + iVar6) = (char)iVar6;
          }
          iVar6 = iVar6 + 1;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        iVar6 = FUN_001054ec(piVar9,iVar24);
        local_e8[0] = *(int *)(iVar6 + 0x10);
        iVar25 = FUN_001054ec(piVar15,1);
        iVar6 = 0;
        local_f8 = *(int *)(iVar25 + 0x10);
        iVar25 = 4;
        do {
          if (*(char *)((int)local_e8 + iVar6) == '\x04') {
            *(undefined1 *)((int)local_e8 + iVar6) = *(undefined1 *)((int)&local_f8 + iVar6);
          }
          iVar6 = iVar6 + 1;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        uVar12 = FUN_00105594(piVar9,iVar7);
        iVar6 = FUN_0010af38(uVar12,param_2,uVar17);
        iVar25 = FUN_00105594(piVar9,iVar24);
        iVar13 = FUN_0010a240(0xa2,*(undefined4 *)(param_2 + 8));
        FUN_000e7700(param_1[0x56],param_1,iVar13);
        *(undefined4 *)(iVar13 + 0x84) = 1;
        *(undefined4 *)(iVar13 + 0x94) = *(undefined4 *)(iVar13 + 0x14c);
        *(undefined4 *)(iVar13 + 0x98) = 0x36;
        *(int *)(iVar13 + 0x9c) = local_100;
        FUN_00106004(iVar13,1,iVar6,0,*(undefined4 *)(param_2 + 8));
        iVar14 = FUN_001054ec(piVar9,iVar7);
        uVar12 = *(undefined4 *)(iVar14 + 0x10);
        iVar14 = FUN_001054ec(iVar13,1);
        *(undefined4 *)(iVar14 + 0x10) = uVar12;
        if (*(int *)(param_2 + 0x478) < *(int *)(iVar6 + 0x160)) {
          *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
        }
        else {
          *(int *)(iVar6 + 0x160) = *(int *)(param_2 + 0x478) + 1;
        }
        *(undefined4 *)(iVar13 + 0x84) = 2;
        ((void (*)())FUN_000f79c4)(iVar13,param_2,2,0.0,0.0,0.0,0.0);
        iVar6 = FUN_001054ec(piVar15,1);
        uVar12 = *(undefined4 *)(iVar6 + 0x10);
        iVar6 = FUN_001054ec(iVar13,2);
        *(undefined4 *)(iVar6 + 0x10) = uVar12;
        iVar6 = FUN_00105594(iVar13,2);
        if (*(int *)(param_2 + 0x478) < *(int *)(iVar6 + 0x160)) {
          *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
        }
        else {
          *(int *)(iVar6 + 0x160) = *(int *)(param_2 + 0x478) + 1;
        }
        *(undefined4 *)(iVar13 + 0x160) = *(undefined4 *)(param_2 + 0x478);
        piVar15 = (int *)FUN_00105594(iVar13,1);
        iVar6 = (**(code **)(*piVar15 + 0x60))(piVar15);
        if (iVar6 != 0) {
          uVar12 = FUN_00105594(iVar13,1);
          FUN_0010c670(uVar12,iVar13,*(undefined4 *)(param_2 + 8));
        }
        iVar6 = 0;
        local_60 = &DAT_001acec0;
        local_f4[0] = 0x4040404;
        if (((a0[5] & 0x200U) != 0) && (iVar6 = FUN_00105594(a0,a0[0x21]), iVar6 != 0)) {
          iVar16 = FUN_001054ec(param_1,param_1[0x21]);
          iVar14 = 0;
          local_f4[0] = *(int *)(iVar16 + 0x10);
          iVar16 = 4;
          do {
            if (*(char *)(iVar14 + (int)local_64) == '\0') {
              *(undefined1 *)((int)local_f4 + iVar14) = 4;
            }
            iVar14 = iVar14 + 1;
            iVar16 = iVar16 + -1;
          } while (iVar16 != 0);
        }
        if (0 < param_1[0x21]) {
          iVar14 = 1;
          do {
            iVar16 = FUN_00105594(param_1,iVar14);
            *(int *)(iVar16 + 0x160) = *(int *)(iVar16 + 0x160) + -1;
            if (uVar17 != 0) {
              iVar16 = FUN_00105594(param_1,iVar14);
              FUN_00194374(*(undefined4 *)(iVar16 + 0x10),param_1);
            }
            iVar14 = iVar14 + 1;
          } while (iVar14 <= param_1[0x21]);
        }
        local_a4 = 0;
        local_d0 = 0;
        local_cc = 0;
        local_bc = 0;
        local_b8 = 0;
        local_b4 = 0;
        uVar12 = FUN_001054ec(piVar9,iVar7);
        FUN_00104730(&local_d0,uVar12);
        uVar12 = FUN_001054ec(piVar9,iVar24);
        FUN_00104730(&local_b8,uVar12);
        iVar14 = param_1[1];
        FUN_0019401c(param_1);
        FUN_00108174(param_1,0x12,*(undefined4 *)(param_2 + 8));
        bVar1 = uVar17 == 0;
        FUN_000e7738(*(undefined4 *)(iVar14 + 0x158),iVar14,param_1);
        iVar14 = *(int *)(param_2 + 0x478);
        param_1[4] = iVar18;
        param_1[0x58] = iVar11 + iVar14;
        param_1[0x27] = local_100;
        param_1[0x48] = iVar21;
        param_1[0x49] = iVar22;
        param_1[0x25] = iVar19;
        param_1[0x26] = iVar20;
        uVar12 = FUN_001054ec(param_1,iVar7);
        FUN_001047a8(uVar12,&local_d0);
        FUN_00106004(param_1,iVar7,iVar13,0,*(undefined4 *)(param_2 + 8));
        iVar11 = local_fc;
        if (bVar1) {
          if (*(int *)(param_2 + 0x478) < *(int *)(iVar13 + 0x160)) {
            *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
          }
          else {
            *(int *)(iVar13 + 0x160) = *(int *)(param_2 + 0x478) + 1;
          }
        }
        if (iVar7 == 0) {
          param_1[0x27] = local_fc;
        }
        else {
          iVar7 = FUN_001054ec(param_1,iVar7);
          *(int *)(iVar7 + 0x10) = iVar11;
        }
        uVar12 = FUN_001054ec(param_1,iVar24);
        FUN_001047a8(uVar12,&local_b8);
        FUN_00106004(param_1,iVar24,iVar25,0,*(undefined4 *)(param_2 + 8));
        iVar7 = local_e8[0];
        if (bVar1) {
          if (*(int *)(param_2 + 0x478) < *(int *)(iVar25 + 0x160)) {
            *(int *)(iVar25 + 0x160) = *(int *)(iVar25 + 0x160) + 1;
          }
          else {
            *(int *)(iVar25 + 0x160) = *(int *)(param_2 + 0x478) + 1;
          }
        }
        if (iVar24 == 0) {
          param_1[0x27] = local_e8[0];
        }
        else {
          iVar24 = FUN_001054ec(param_1,iVar24);
          *(int *)(iVar24 + 0x10) = iVar7;
        }
        if ((iVar6 != 0) && (local_f4[0] != *(int *)((*(unsigned char *)0x00003190) + (int)local_60))) {
          FUN_00106804(param_1,iVar6,uVar17,*(undefined4 *)(param_2 + 8));
          iVar24 = local_f4[0];
          iVar7 = FUN_001054ec(param_1,3);
          *(int *)(iVar7 + 0x10) = iVar24;
          if (bVar1) {
            if (*(int *)(param_2 + 0x478) < *(int *)(iVar6 + 0x160)) {
              *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
            }
            else {
              *(int *)(iVar6 + 0x160) = *(int *)(param_2 + 0x478) + 1;
            }
          }
        }
        FUN_0010564c(a0,*(undefined4 *)(param_2 + 8),0);
        return 0;
      }
    }
  }
  return 0;
}

/* FUN_0015df44 @ 0x15df44 (600 bytes) */
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
undefined4 FUN_0015e2f4(int param_1,int param_2,undefined4 param_3,undefined4 param_4,double fparam_1)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_48 [4];
  float local_44;
  
  if (((((*(int *)(param_1 + 0x120) == 0) && (*(int *)(param_1 + 0x124) == 0)) &&
       ((*(uint *)(param_1 + 0xb8) & 1) == 0)) &&
      (((*(uint *)(param_1 + 0xb8) & 2) == 0 && ((*(uint *)(param_1 + 0xd0) & 1) == 0)))) &&
     (((*(uint *)(param_1 + 0xd0) & 2) == 0 && (*(int *)(*(int *)(param_1 + 0x88) + 8) == param_2)))
     ) {
    iVar1 = FUN_001054ec(param_1,0);
    iVar1 = FUN_000f5cf0(param_1,1,*(undefined4 *)(iVar1 + 0x10),auStack_48);
    if ((iVar1 != 0) && (fparam_1 == (double)local_44)) {
      uVar2 = FUN_00105594(param_1,2);
      iVar1 = FUN_001054ec(param_1,2);
      uVar4 = *(undefined4 *)(iVar1 + 0x10);
      uVar3 = FUN_00105594(param_1,1);
      FUN_00106004(param_1,2,uVar3,0,param_4);
      iVar1 = FUN_001054ec(param_1,1);
      uVar3 = *(undefined4 *)(iVar1 + 0x10);
      iVar1 = FUN_001054ec(param_1,2);
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      FUN_00106004(param_1,1,uVar2,0,param_4);
      iVar1 = FUN_001054ec(param_1,1);
      *(undefined4 *)(iVar1 + 0x10) = uVar4;
      return uVar2;
    }
    iVar1 = FUN_001054ec(param_1,0);
    iVar1 = FUN_000f5cf0(param_1,2,*(undefined4 *)(iVar1 + 0x10),auStack_48);
    if ((iVar1 != 0) && ((double)local_44 == fparam_1)) {
      uVar2 = FUN_00105594(param_1,1);
      return uVar2;
    }
  }
  return 0;
}

/* FUN_0015e494 @ 0x15e494 (772 bytes) */
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
  undefined4 in_r5;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 local_88;
  byte local_84 [4];
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_64;
  
  iVar16 = *(int *)(param_2 + 8);
  iVar3 = (**(code **)(**(int **)(iVar16 + 0x30c) + 0x80))(*(int **)(iVar16 + 0x30c),param_2);
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = ((undefined4 (*)())FUN_0015e2f4)(param_1,0x17,in_r5,iVar16,0.0);
  if (iVar3 == 0) {
    iVar3 = ((undefined4 (*)())FUN_0015e2f4)(param_1,0x19,in_r5,iVar16,1.0);
    if (iVar3 == 0) {
      return 0;
    }
    piVar4 = (int *)((undefined4 (*)())FUN_0015e2f4)(iVar3,0x17,in_r5,iVar16,0.0);
  }
  else {
    piVar4 = (int *)((undefined4 (*)())FUN_0015e2f4)(iVar3,0x19,in_r5,iVar16,1.0);
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
  local_84[0] = 4;
  local_84[1] = 4;
  local_84[2] = 4;
  local_84[3] = 4;
  local_88 = *(undefined4 *)(iVar5 + 0x10);
  do {
    if (*(char *)((int)&local_88 + iVar17) != '\x01') {
      iVar5 = FUN_001054ec(param_1,1);
      bVar2 = *(byte *)(iVar17 + iVar5 + 0x10);
      iVar5 = FUN_001054ec(iVar3,1);
      local_84[iVar17] = *(byte *)((uint)bVar2 + iVar5 + 0x10);
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
  uVar6 = 0x10203;
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
    iVar3 = FUN_001054ec(param_1,1);
    *(undefined4 *)(iVar3 + 0x10) = 0x10203;
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
      local_7c = 0x4040404;
      local_80 = *(undefined4 *)(iVar16 + 0x10);
      iVar16 = 4;
      do {
        if (*(char *)((int)&local_88 + iVar5) == '\0') {
          *(undefined1 *)((int)&local_7c + iVar5) =
               *(undefined1 *)((int)&local_80 + (uint)local_84[iVar5]);
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

/* FUN_0015ea3c @ 0x15ea3c (696 bytes) */
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
  int iVar7;
  int iVar8;
  undefined4 a1;
  undefined4 uVar9;
  undefined4 in_r7;
  undefined4 in_r8;
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
          iVar7 = 0;
          FUN_000e7738(*(undefined4 *)(iVar3 + 0x158),iVar3,param_3);
          iVar5 = FUN_001054ec(iVar3,0);
          uVar6 = *(undefined4 *)(iVar5 + 0x10);
          iVar5 = FUN_001054ec(iVar3,0);
          local_68 = *(int *)(iVar5 + 0x10);
          iVar5 = FUN_001054ec(piVar4,0);
          local_64 = *(undefined4 *)(iVar5 + 0x10);
          do {
            iVar5 = FUN_001054ec(iVar3,0);
            if (*(char *)(iVar7 + iVar5 + 0x10) != '\x01') {
              *(undefined1 *)((int)&local_64 + iVar7) = 1;
            }
            bVar2 = iVar7 != 3;
            iVar7 = iVar7 + 1;
          } while (bVar2);
          iVar7 = FUN_001054ec(piVar4,0);
          iVar5 = 0;
          local_6c = *(undefined4 *)(iVar7 + 0x10);
          iVar7 = 4;
          do {
            if (*(char *)((int)&local_6c + iVar5) != '\x01') {
              *(char *)((int)&local_68 + iVar5) = *(char *)((int)&local_6c + iVar5);
            }
            iVar5 = iVar5 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          param_3[0x27] = local_68;
          param_3[0x25] = param_3[0x53];
          param_3[0x26] = 0x36;
          FUN_00103f44(param_3,&local_5c);
          param_3[0x21] = 2;
          FUN_00106004(param_3,1,iVar3,0,*(undefined4 *)(param_4 + 8));
          FUN_000f3908(&local_48,uVar6);
          FUN_000f3340(&local_44,0x10203,local_48);
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
          ((int (*)())FUN_00160320)(param_1,param_2,param_3,param_4,&local_70);
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
        iVar3 = param_4;
        iVar5 = FUN_000f5a0c(param_3,1,param_3,param_4);
        if (iVar5 == 0) {
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
          uVar9 = *(undefined4 *)(iVar3 + 0x10);
          FUN_0019401c(param_3);
          FUN_0010a1c0(param_3,0xa2,*(undefined4 *)(param_4 + 8));
          FUN_00103f44(param_3,&local_5c);
          param_3[0x26] = 0x36;
          param_3[0x25] = param_3[0x53];
          param_3[0x27] = local_60;
          param_3[0x21] = 2;
          FUN_00106004(param_3,1,uVar6,0,*(undefined4 *)(param_4 + 8));
          iVar3 = FUN_001054ec(param_3,1);
          *(undefined4 *)(iVar3 + 0x10) = uVar9;
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
          iVar5 = FUN_001054ec(param_3,0);
          local_68 = *(int *)(iVar5 + 0x10);
          iVar7 = FUN_001054ec(piVar4,0);
          iVar5 = 0;
          local_74 = *(undefined4 *)(iVar7 + 0x10);
          iVar7 = 4;
          do {
            if (*(char *)((int)&local_74 + iVar5) != '\x01') {
              *(char *)((int)&local_68 + iVar5) = *(char *)((int)&local_74 + iVar5);
            }
            iVar5 = iVar5 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          iVar5 = 0;
          local_64 = 0x10203;
          do {
            iVar7 = FUN_001054ec(param_3,0);
            if (*(char *)(iVar5 + iVar7 + 0x10) != '\x01') {
              *(undefined1 *)((int)&local_64 + iVar5) = 4;
            }
            bVar2 = iVar5 != 3;
            iVar5 = iVar5 + 1;
          } while (bVar2);
          iVar5 = 0;
          iVar7 = 4;
          do {
            if (*(char *)((int)&local_68 + iVar5) == '\x01') {
              *(undefined1 *)((int)&local_64 + iVar5) = 4;
            }
            iVar5 = iVar5 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          iVar5 = FUN_001054ec(param_3,1);
          local_60 = *(int *)(iVar5 + 0x10);
          iVar5 = param_3[1];
          FUN_0019401c(param_3);
          uVar9 = *(undefined4 *)(param_4 + 8);
          FUN_0010a1c0(param_3,0xa2,uVar9);
          FUN_00103f44(param_3,&local_5c);
          param_3[0x26] = 0x36;
          param_3[0x25] = param_3[0x53];
          param_3[0x27] = local_68;
          iVar3 = (**(code **)(*piVar4 + 0x60))(piVar4,a1,uVar9,iVar3,in_r7,in_r8,local_68);
          if (iVar3 == 0) {
            param_3[0x21] = 2;
            FUN_00106004(param_3,1,piVar4,0,*(undefined4 *)(param_4 + 8));
            uVar9 = local_64;
            iVar3 = FUN_001054ec(param_3,1);
            *(undefined4 *)(iVar3 + 0x10) = uVar9;
            FUN_00106004(param_3,2,uVar6,0,*(undefined4 *)(param_4 + 8));
            iVar3 = local_60;
            iVar7 = FUN_001054ec(param_3,2);
            *(int *)(iVar7 + 0x10) = iVar3;
          }
          else {
            param_3[0x21] = piVar4[0x21] + 1;
            if (0 < piVar4[0x21]) {
              iVar3 = 1;
              do {
                uVar9 = FUN_00105594(piVar4,iVar3);
                FUN_00106004(param_3,iVar3,uVar9,0,*(undefined4 *)(param_4 + 8));
                iVar7 = FUN_001054ec(piVar4,iVar3);
                iVar7 = *(int *)(iVar7 + 0x10);
                if (iVar3 == 0) {
                  param_3[0x27] = iVar7;
                }
                else {
                  iVar8 = FUN_001054ec(param_3,iVar3);
                  *(int *)(iVar8 + 0x10) = iVar7;
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
            iVar7 = 0;
            do {
              if ((*(char *)((int)&local_60 + iVar7) != '\x04') && (0 < iVar3)) {
                iVar8 = 1;
                do {
                  iVar10 = iVar8 + 1;
                  (**(code **)(*param_3 + 0x88))(param_3,iVar8,iVar7,4);
                  iVar3 = param_3[0x21];
                  iVar8 = iVar10;
                } while (iVar10 <= iVar3);
              }
              bVar2 = iVar7 != 3;
              iVar7 = iVar7 + 1;
            } while (bVar2);
            FUN_00106004(param_3,iVar3,uVar6,0,*(undefined4 *)(param_4 + 8));
            iVar3 = local_60;
            if (param_3[0x21] == 0) {
              param_3[0x27] = local_60;
            }
            else {
              iVar7 = FUN_001054ec(param_3,param_3[0x21]);
              *(int *)(iVar7 + 0x10) = iVar3;
            }
          }
          FUN_000e7738(*(undefined4 *)(iVar5 + 0x158),iVar5,param_3);
          FUN_0010564c(piVar4,*(undefined4 *)(param_4 + 8),0);
          iVar3 = (**(code **)(*piVar4 + 100))(piVar4);
          if (iVar3 == 0) {
            return 1;
          }
        }
        ((int (*)())FUN_00160320)(param_1,param_2,param_3,param_4,&local_70);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0015f44c @ 0x15f44c (2576 bytes) */
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
  undefined4 in_r8;
  undefined4 uVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  int *piVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  double fparam_1;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  int local_ac;
  undefined4 local_a8;
  int local_a0 [5];
  undefined4 *local_8c;
  undefined4 *local_88;
  undefined4 *local_84;
  undefined4 *local_80;
  undefined4 *local_7c;
  undefined4 local_70;
  
  piVar17 = (int *)0x0;
  if ((param_3[5] & 0x200U) != 0) {
    piVar17 = (int *)FUN_00105594(param_3,param_3[0x21]);
  }
  uVar15 = *(undefined4 *)(param_4 + 8);
  if ((piVar17 == (int *)0x0) || (iVar6 = (**(code **)(*piVar17 + 0x60))(piVar17), iVar6 == 0)) {
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
  uVar13 = *(undefined4 *)(iVar6 + 0x10);
  iVar6 = FUN_001054ec(piVar17,0);
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
  piVar7 = (int *)FUN_00105594(piVar17,1);
  if (((piVar7[0x20] == 0) || (iVar11 = FUN_00126760(piVar7[0x26]), iVar11 == 0)) ||
     (((piVar7[5] & 2U) != 0 || (iVar11 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar11 != 0)))) {
    iVar11 = FUN_001054ec(piVar17,1);
    uVar12 = *(undefined4 *)(iVar11 + 0x10);
    iVar11 = FUN_001054ec(param_3,0);
    iVar11 = FUN_00146624(uVar12,*(undefined4 *)(iVar11 + 0x10));
    if (iVar11 != 0) goto LAB_0015f5cc;
  }
  else {
LAB_0015f5cc:
    if (iVar6 - 0x12U < 3) {
      iVar11 = (**(code **)(*piVar17 + 0x14))(piVar17);
      local_a0[1] = 0;
      local_b0 = 0;
      local_ac = 0;
      if (iVar11 < 1) {
        local_a0[2] = 0;
        local_a0[4] = 0;
        local_a0[3] = 0;
        goto LAB_0015f7bc;
      }
      iVar16 = 1;
      local_a0[4] = 0;
      uVar14 = 0;
      local_a0[3] = 0;
      do {
        iVar9 = FUN_00105594(piVar17,iVar16);
        if (*(int *)(iVar9 + 0x98) == 0x33) {
          iVar18 = FUN_001054ec(piVar17,iVar16);
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
                  uVar14 = uVar14 | 1 << (uVar21 & 0x3f);
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
        iVar16 = iVar16 + 1;
      } while (iVar16 <= iVar11);
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
      if ((uVar14 == 0) && (-1 < local_a0[2])) {
LAB_0015f7bc:
        uVar14 = 2;
        bVar1 = local_a0[4] == 0;
        iVar11 = FUN_001054ec(param_3,0);
        local_8c = &local_bc;
        local_88 = &local_c8;
        local_bc = *(undefined4 *)(iVar11 + 0x10);
        local_84 = local_8c;
        local_80 = local_88;
        local_7c = local_8c;
        do {
          iVar16 = 3 - uVar14;
          iVar11 = (**(code **)(*param_3 + 0x14))(param_3);
          if (iVar11 < iVar16) {
            FUN_00106004(param_3,param_3[0x21],0,0,uVar15);
            param_3[0x21] = param_3[0x21] + -1;
            param_3[5] = param_3[5] & 0xfffffdff;
            if (local_ac != 0) {
              iVar6 = FUN_001054ec(param_3,0);
              iVar11 = 0;
              piVar7 = local_a0;
              local_b8 = *(int *)(iVar6 + 0x10);
              iVar6 = 4;
              do {
                if (*(char *)((int)&local_b8 + iVar11) != '\x01') {
                  *(undefined1 *)piVar7 = 4;
                }
                iVar11 = iVar11 + 1;
                piVar7 = (int *)((int)piVar7 + 1);
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
              if (local_a0[0] != 0x4040404) {
                FUN_00106b48(param_3,&local_b0,0,uVar15);
                if (*(int *)(param_4 + 0x478) < *(int *)(local_ac + 0x160)) {
                  *(int *)(local_ac + 0x160) = *(int *)(local_ac + 0x160) + 1;
                }
                else {
                  *(int *)(local_ac + 0x160) = *(int *)(param_4 + 0x478) + 1;
                }
              }
            }
            (**(code **)(*param_3 + 0x14))(param_3);
            FUN_00105894(piVar17,uVar15);
            return 1;
          }
          uVar13 = FUN_00105594(param_3,iVar16);
          if ((bVar1) || ((local_a0[3] == 0 && (iVar6 == 0x13)))) {
            uVar21 = local_a0[2] >> (uVar14 & 0x3f);
            if ((uVar21 & 1) == 0) goto LAB_0015f88c;
            iVar11 = 2;
            fparam_1 = 1.0;
          }
          else {
            uVar21 = local_a0[2] >> (uVar14 & 0x3f);
            if ((uVar21 & 1) == 0) {
LAB_0015f88c:
              iVar11 = 2;
              fparam_1 = 0.0;
            }
            else {
              iVar11 = 3;
              fparam_1 = 1.0;
            }
          }
          bVar3 = local_a0[3] != 0;
          iVar18 = 0;
          piVar8 = (int *)((int (*)())FUN_0010bed0)(iVar11,0x1010101,uVar13,param_4,uVar15,fparam_1);
          iVar9 = FUN_001054ec(param_3,iVar16);
          local_b8 = *(int *)(iVar9 + 0x10);
          piVar7 = piVar8;
          do {
            if (*(char *)((int)&local_b8 + iVar18) != '\x04') {
              (**(code **)(*piVar8 + 0x88))(piVar8,1,iVar18);
              *(undefined1 *)(piVar7 + 0x27) = 0;
              (**(code **)(*param_3 + 0x88))(param_3,iVar16,iVar18,iVar18);
            }
            bVar2 = iVar18 != 3;
            piVar7 = (int *)((int)piVar7 + 1);
            iVar18 = iVar18 + 1;
          } while (bVar2);
          iVar9 = -1;
          iVar18 = -1;
          iVar19 = 0;
          piVar7 = piVar8;
          do {
            iVar10 = FUN_001054ec(piVar8,1);
            if ((*(char *)(iVar19 + iVar10 + 0x10) == '\x04') &&
               (*(char *)(iVar19 + (int)local_8c) == '\x01')) {
              if ((iVar11 == 3) || (fparam_1 == 1.0)) {
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
                if (fparam_1 != 0.0) break;
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
                  (*(char *)(uVar20 + (int)local_88) != '\x01')) &&
                 (*(char *)(uVar20 + (int)local_84) == '\x01')) {
                if ((uVar21 & 1) == 0) {
                  (**(code **)(*param_3 + 0x88))(param_3,iVar16,uVar20,iVar18);
                }
                else {
                  (**(code **)(*param_3 + 0x88))(param_3,iVar16,uVar20,iVar9);
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
                (**(code **)(*param_3 + 0x88))(param_3,iVar16,uVar21,iVar18);
                *(undefined1 *)(piVar7 + 0x27) = 0;
              }
              bVar3 = uVar21 != 3;
              piVar7 = (int *)((int)piVar7 + 1);
              uVar21 = uVar21 + 1;
            } while (bVar3);
          }
          piVar7 = (int *)FUN_00105594(piVar8,1);
          iVar11 = (**(code **)(*piVar7 + 0x60))(piVar7);
          if (iVar11 != 0) {
            uVar13 = FUN_00105594(piVar8,1);
            FUN_0010c670(uVar13,piVar8,uVar15);
          }
          uVar14 = uVar14 - 1;
          FUN_000e7700(param_3[0x56],param_3,piVar8);
          FUN_00106004(param_3,iVar16,piVar8,0,uVar15);
        } while( true );
      }
    }
  }
  if ((piVar17[0x26] != 0x33) ||
     (iVar6 = FUN_00105594(param_3,param_3[0x21]), *(int *)(iVar6 + 300) == 3)) {
    iVar11 = FUN_001084b8(0x31,*(undefined4 *)(param_4 + 8));
    iVar6 = *(int *)(param_4 + 0x478);
    *(undefined4 *)(iVar11 + 0x98) = 0;
    *(int *)(iVar11 + 0x160) = iVar6 + 1;
    *(undefined4 *)(iVar11 + 0x94) = *(undefined4 *)(iVar11 + 0x14c);
    FUN_00106004(iVar11,1,piVar17,0,*(undefined4 *)(param_4 + 8));
    uVar15 = FUN_00105594(param_3,param_3[0x21]);
    iVar6 = FUN_001054ec(uVar15,0);
    *(undefined4 *)(iVar11 + 0x9c) = *(undefined4 *)(iVar6 + 0x10);
    FUN_000f4698(iVar11,1,param_4);
    iVar6 = param_3[0x21];
    *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) | 0x80000000;
    iVar6 = FUN_00105594(param_3,iVar6);
    uVar12 = *(undefined4 *)(iVar6 + 0x158);
    uVar15 = FUN_00105594(param_3,param_3[0x21]);
    FUN_000e7738(uVar12,uVar15,iVar11);
    FUN_00106804(param_3,iVar11,0,*(undefined4 *)(param_4 + 8));
    iVar6 = FUN_001054ec(param_3,param_3[0x21]);
    *(undefined4 *)(iVar6 + 0x10) = uVar13;
    return 1;
  }
LAB_0015fd14:
  uVar12 = *(undefined4 *)(param_4 + 8);
  uVar15 = 0;
  uVar13 = 0;
  FUN_00106004(param_3,param_3[0x21],0,0,uVar12);
  iVar6 = piVar17[0x58];
  param_3[0x21] = param_3[0x21] + -1;
  param_3[5] = param_3[5] & 0xfffffdff;
  piVar17[0x58] = iVar6 + -1;
  iVar6 = FUN_001049c4(piVar17,param_4,uVar15,uVar13,uVar12,in_r8,iVar6 + -1);
  bVar1 = iVar6 != 0;
  if (bVar1) {
    (**(code **)(*piVar17 + 0xc))(piVar17,0,*(undefined4 *)(param_4 + 8));
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
  uVar15 = *(undefined4 *)(iVar6 + 0x158);
  param_3[0x21] = piVar17[0x21] + 1;
  FUN_000e7738(uVar15,iVar6,param_3);
  iVar11 = FUN_001054ec(iVar6,0);
  local_b8 = *(int *)(iVar11 + 0x10);
  iVar11 = FUN_001054ec(piVar17,0);
  iVar16 = 0;
  local_c0 = *(undefined4 *)(iVar11 + 0x10);
  iVar11 = 4;
  do {
    if (*(char *)((int)&local_c0 + iVar16) != '\x01') {
      *(char *)((int)&local_b8 + iVar16) = *(char *)((int)&local_c0 + iVar16);
    }
    iVar16 = iVar16 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  iVar11 = FUN_00105594(piVar17,1);
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
    iVar11 = FUN_001054ec(param_3,1);
    iVar16 = 2;
    *(undefined4 *)(iVar11 + 0x10) = 0x10203;
  }
  else {
    FUN_00106004(param_3,2,iVar6,0,*(undefined4 *)(param_4 + 8));
    iVar16 = FUN_001054ec(param_3,2);
    *(undefined4 *)(iVar16 + 0x10) = 0x10203;
    FUN_00106004(param_3,1,iVar11,0,*(undefined4 *)(param_4 + 8));
    iVar11 = FUN_001054ec(piVar17,1);
    uVar15 = *(undefined4 *)(iVar11 + 0x10);
    iVar11 = FUN_001054ec(param_3,1);
    iVar16 = 3;
    *(undefined4 *)(iVar11 + 0x10) = uVar15;
  }
  iVar11 = FUN_001054ec(iVar6,0);
  local_b4 = *(undefined4 *)(iVar11 + 0x10);
  if (1 < piVar17[0x21]) {
    iVar11 = 2;
    do {
      uVar15 = FUN_00105594(piVar17,iVar11);
      FUN_00106004(param_3,iVar16,uVar15,0,*(undefined4 *)(param_4 + 8));
      if (!bVar1) {
        iVar9 = FUN_00105594(piVar17,iVar11);
        if (*(int *)(param_4 + 0x478) < *(int *)(iVar9 + 0x160)) {
          *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
        }
        else {
          *(int *)(iVar9 + 0x160) = *(int *)(param_4 + 0x478) + 1;
        }
      }
      iVar9 = FUN_001054ec(piVar17,iVar11);
      iVar9 = *(int *)(iVar9 + 0x10);
      if (iVar16 == 0) {
        param_3[0x27] = iVar9;
      }
      else {
        iVar18 = FUN_001054ec(param_3,iVar16);
        *(int *)(iVar18 + 0x10) = iVar9;
      }
      iVar18 = FUN_001054ec(piVar17,iVar11);
      iVar9 = 0;
      local_bc = *(undefined4 *)(iVar18 + 0x10);
      iVar18 = 4;
      do {
        if (*(char *)((int)&local_b4 + iVar9) != '\x04') {
          *(undefined1 *)((int)&local_bc + iVar9) = 4;
        }
        uVar15 = local_bc;
        iVar9 = iVar9 + 1;
        iVar18 = iVar18 + -1;
      } while (iVar18 != 0);
      iVar11 = iVar11 + 1;
      iVar9 = FUN_001054ec(param_3,iVar16);
      iVar16 = iVar16 + 1;
      *(undefined4 *)(iVar9 + 0x10) = uVar15;
    } while (iVar11 <= piVar17[0x21]);
  }
  param_3[0x27] = local_b8;
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
  
  iVar2 = (**(code **)(*param_3 + 0x60))(param_3,param_2,param_3,param_4,param_5);
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
          iVar2 = (**(code **)(*piVar8 + 0x5c))(piVar8);
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
            iVar2 = (**(code **)(*piVar8 + 0x60))(piVar8);
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
  iVar2 = (**(code **)(*piVar8 + 0x5c))(piVar8);
  if (iVar2 != 0) {
    return 0;
  }
  if (*(int *)(*(int *)(param_4 + 8) + 0x660) <= *(int *)(param_4 + 0x17c)) {
    return 0;
  }
  iVar2 = FUN_001054ec(param_3,0);
  FUN_000f3908(auStack_38,*(undefined4 *)(iVar2 + 0x10));
  iVar2 = FUN_001054ec(param_1,0);
  FUN_000f3968(auStack_34,*(undefined4 *)(iVar2 + 0x10),0x1010101);
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

/* FUN_00160eb0 @ 0x160eb0 (2064 bytes) */
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
  undefined4 local_98;
  int *local_94;
  int local_90;
  int local_8c;
  int local_88;
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
    local_88 = 0;
    local_84 = 0;
    local_80 = 0;
    local_7c = 0;
    local_70 = 4;
    iVar4 = ((int (*)())FUN_0015b974)(param_3,&local_64,&local_8c,&local_80,local_74);
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
              (iVar6 = ((int (*)())FUN_0015b974)(piVar14,&local_94,&local_88,&local_7c,&local_70), iVar6 == 0))
             || (local_8c != local_88)) ||
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
                 (iVar8 = ((int (*)())FUN_0015b974)(piVar7,&local_90,&local_84,&local_78,&local_6c), iVar8 == 0))
                || (local_88 != local_84)) ||
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
        iVar9 = (**(code **)(*local_64 + 0x5c))(local_64);
        if (iVar9 != 0) {
          local_64[0x27] = iVar4;
          iVar9 = 1;
          while( true ) {
            iVar10 = (**(code **)(*local_64 + 0x14))(local_64);
            if (iVar10 < iVar9) break;
            iVar10 = FUN_001054ec(local_64,iVar9);
            *(undefined4 *)(iVar10 + 0x10) = 0x10203;
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
        iVar10 = (**(code **)(*local_64 + 0x5c))(local_64);
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
        local_68 = 0x4040404;
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
          ((void (*)())FUN_000f79c4)(param_3,param_4,1,1.0,1.0,1.0,1.0);
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
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78 [6];
  undefined4 local_60;
  int local_58 [5];
  
  iVar7 = (**(code **)(*param_1 + 100))(param_1,param_2,param_3);
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
        iVar7 = FUN_0010453c(uVar8,uVar9,*(undefined4 *)(iVar7 + 0x10),in_r6,in_r7,in_r8,in_r9);
        uVar8 = FUN_00105594(param_2,1);
        uVar9 = *(undefined4 *)(param_3 + 8);
        bVar1 = iVar7 == 0;
        iVar7 = FUN_001054ec(param_2,1);
        iVar7 = FUN_0010453c(uVar8,uVar9,*(undefined4 *)(iVar7 + 0x10),in_r6,in_r7,in_r8,in_r9);
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
            local_88 = *(undefined4 *)(iVar10 + 0x10);
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
            if ((iVar10 == 0) || (((char)local_88 != '\0' && ((char)local_84 != '\0')))) {
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
              FUN_000f2f84(local_58,local_84,local_88);
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
              piVar12[0x58] = *(int *)(param_3 + 0x478) + 1;
              piVar12[0x27] = 0x1010101;
              iVar11 = FUN_001054ec(piVar12,1);
              *(undefined4 *)(iVar11 + 0x10) = 0x4040404;
              iVar11 = FUN_001054ec(piVar12,2);
              *(undefined4 *)(iVar11 + 0x10) = 0x10203;
              iVar11 = FUN_001054ec(param_1,1);
              *(undefined4 *)(iVar11 + 0x10) = 0x4040404;
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
                  iVar7 = (**(code **)(*piVar14 + 0x60))(piVar14);
                  if (iVar7 != 0) {
                    uVar8 = FUN_00105594(piVar12,1);
                    FUN_0010c670(uVar8,piVar12,*(undefined4 *)(param_3 + 8));
                  }
                  FUN_00105894(param_2,*(undefined4 *)(param_3 + 8));
                  if ((param_2[5] & 1U) != 0) {
                    piVar14 = (int *)FUN_00105594(piVar12,1);
                    iVar7 = (**(code **)(*piVar14 + 0x5c))(piVar14);
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

/* FUN_001621c8 @ 0x1621c8 (2404 bytes) */
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
  
  iVar6 = (**(code **)(*param_1 + 100))(param_1,param_2,param_3);
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
        local_c8 = 0x4040404;
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
    *pfVar4 = GH_U2F(0x7fff0000U);
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
    *pfVar4 = GH_U2F(0x7fff0000U);
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
    bVar2 = iVar6 != 3;
    pfVar4 = pfVar4 + 1;
    iVar6 = iVar6 + 1;
  } while (bVar2);
  FUN_000f3908(&local_78,local_c4);
  FUN_000f3340(&local_74,0x10203,local_78);
  local_c0 = local_74;
  piVar9 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
  iVar6 = (**(code **)(*piVar9 + 0x154))(piVar9,param_3,pfVar12,&local_c0);
  FUN_000f3908(&local_70,local_c4);
  FUN_000f3340(&local_6c,0x10203,local_70);
  local_bc = local_6c;
  piVar9 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
  iVar7 = (**(code **)(*piVar9 + 0x154))(piVar9,param_3,local_b8,&local_bc);
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
    *(undefined4 *)(iVar7 + 0x9c) = 0;
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
        if (*pfVar12 == 0.0) {
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
  
  iVar1 = (**(code **)(*param_1 + 100))(param_1,param_2);
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
  undefined4 local_88;
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
      local_88 = *(undefined4 *)(iVar4 + 0x10);
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
        for (iVar2 = 1; iVar4 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1),
            iVar2 <= iVar4; iVar2 = iVar2 + 1) {
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
          iVar4 = (**(code **)(*piVar5 + 0x48))(piVar5);
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
        for (iVar2 = 1; iVar4 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1),
            iVar2 <= iVar4; iVar2 = iVar2 + 1) {
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
          iVar4 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1);
          if (iVar4 < iVar2) {
            puVar10 = local_54;
            *(undefined4 *)(*param_1 + 0x9c) = local_78;
            for (iVar2 = 1; iVar4 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1),
                iVar2 <= iVar4; iVar2 = iVar2 + 1) {
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
            iVar4 = *param_1;
            if (*(int *)(iVar4 + 0x84) == 0) {
              *(undefined4 *)(iVar4 + 0x9c) = local_74;
            }
            else {
              iVar4 = FUN_001054ec(iVar4,*(int *)(iVar4 + 0x84));
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
int FUN_001633f8(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  (*(int *)((unsigned char *)ghidra_home + 0)) = param_1;
  if ((*(uint *)(param_1 + 0x14) & 0x200) != 0) {
    uVar2 = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84));
  }
  iVar1 = ((int (*)())FUN_00162dfc)(&(*(unsigned int *)((unsigned char *)ghidra_home + 0)),0,param_2);
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
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  undefined4 local_68;
  
  uVar10 = *(undefined4 *)(param_4 + 8);
  iVar11 = *(int *)(param_3[0x22] + 8);
  iVar3 = FUN_001054ec(param_3,0);
  local_98 = *(int *)(iVar3 + 0x10);
  if ((iVar11 - 0x1cU < 2) && (iVar3 = FUN_000f3824(local_98), iVar3 != 0)) {
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
          local_88 = 0;
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
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint *puVar20;
  int iVar21;
  int iVar22;
  double fparam_1;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  int local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  int local_98;
  undefined4 local_88;
  undefined4 local_84;
  float local_80;
  
  if ((*(uint *)(param_1 + 0x14) & 0x200) == 0) {
    return 0;
  }
  iVar3 = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84));
  if (iVar3 == 0) {
    return 0;
  }
  if ((*(uint *)(*(int *)(*(int *)(param_2 + 8) + 0x30c) + 8) & 0x100) == 0) {
    return 0;
  }
  iVar19 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  iVar21 = *(int *)(*(int *)(iVar3 + 0x88) + 8);
  iVar4 = FUN_001054ec(param_1,*(undefined4 *)(param_1 + 0x84));
  local_b8 = *(undefined4 *)(iVar4 + 0x10);
  if (iVar19 == 0x31) {
    if (iVar21 != 0x14) {
      return 0;
    }
    iVar4 = FUN_001054ec(param_1,0);
    iVar21 = 0;
    local_84 = *(undefined4 *)(iVar4 + 0x10);
    iVar22 = 4;
    do {
      if (*(char *)((int)&local_b8 + iVar21) == '\x04') {
        if (*(char *)((int)&local_84 + iVar21) == '\0') {
          *(char *)((int)&local_b8 + iVar21) = (char)iVar21;
        }
      }
      else {
        *(undefined1 *)((int)&local_b8 + iVar21) = 4;
      }
      iVar21 = iVar21 + 1;
      iVar22 = iVar22 + -1;
      iVar4 = iVar3;
      iVar19 = param_1;
    } while (iVar22 != 0);
  }
  else {
    if (iVar19 != 0x14) {
      return 0;
    }
    iVar4 = param_1;
    iVar19 = iVar3;
    if (iVar21 != 0x31) {
      return 0;
    }
  }
  if (*(int *)(iVar19 + 0x120) != *(int *)(iVar4 + 0x120)) {
    return 0;
  }
  if (*(int *)(iVar19 + 0x124) != *(int *)(iVar4 + 0x124)) {
    return 0;
  }
  iVar21 = FUN_001054ec(iVar19,0);
  local_b4 = *(int *)(iVar21 + 0x10);
  iVar21 = FUN_001054ec(iVar4,0);
  local_b0 = *(undefined4 *)(iVar21 + 0x10);
  iVar21 = FUN_000e07dc(*(undefined4 *)(param_2 + 8),0x30);
  if (iVar21 != 0) {
    if ((char)local_b4 == '\0') {
      return 0;
    }
    if ((char)local_b0 == '\0') {
      return 0;
    }
  }
  iVar21 = 0;
  iVar22 = 4;
  do {
    if ((*(char *)((int)&local_b4 + iVar21) != '\x01') &&
       (*(char *)((int)&local_b0 + iVar21) != '\x01')) {
      return 0;
    }
    iVar21 = iVar21 + 1;
    iVar22 = iVar22 + -1;
  } while (iVar22 != 0);
  piVar5 = (int *)FUN_00105594(iVar19,1);
  iVar21 = (**(code **)(*piVar5 + 0x60))(piVar5);
  if (iVar21 != 0) {
    return 0;
  }
  iVar21 = FUN_001466f4(iVar19,1);
  iVar22 = FUN_001466f4(iVar4,1);
  iVar6 = FUN_001466f4(iVar4,2);
  iVar7 = FUN_001466f4(iVar4,3);
  uVar17 = *(uint *)(iVar4 + 0xb8) & 1;
  uVar10 = *(uint *)(iVar4 + 0xd0) & 1;
  uVar18 = *(uint *)(iVar19 + 0xb8) & 1;
  uVar12 = *(uint *)(iVar19 + 0xb8) >> 1 & 1;
  if ((iVar21 == iVar22) && ((*(uint *)(iVar4 + 0xb8) >> 1 & 1) == uVar12)) {
    if (uVar18 == 0) {
      if (uVar17 != uVar10) goto LAB_00163c00;
    }
    else if (uVar17 == uVar10) goto LAB_00163c00;
    uVar13 = 1;
    fparam_1 = 1.0;
    uVar14 = 2;
    uVar15 = 3;
  }
  else {
LAB_00163c00:
    if ((iVar21 == iVar6) && ((*(uint *)(iVar4 + 0xd0) >> 1 & 1) == uVar12)) {
      if (uVar18 == 0) {
        if (uVar17 != uVar10) goto LAB_00163c2c;
      }
      else if (uVar17 == uVar10) goto LAB_00163c2c;
      uVar13 = 2;
      fparam_1 = 1.0;
      uVar14 = 1;
      uVar15 = 3;
    }
    else {
LAB_00163c2c:
      if (iVar21 != iVar7) {
        return 0;
      }
      if ((*(uint *)(iVar4 + 0xe8) >> 1 & 1) != uVar12) {
        return 0;
      }
      if ((*(uint *)(iVar4 + 0xe8) & 1) != uVar18) {
        return 0;
      }
      uVar13 = 3;
      fparam_1 = 0.0;
      uVar14 = 1;
      uVar15 = 2;
    }
  }
  local_88 = 0;
  local_9c = 0;
  local_98 = 0;
  if ((*(uint *)(iVar3 + 0x14) & 0x200) != 0) {
    FUN_00104d3c(iVar3,&local_9c);
  }
  iVar3 = *(int *)(iVar19 + 0x160) - *(int *)(param_2 + 0x478);
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  iVar21 = FUN_001054ec(iVar19,1);
  local_a4 = *(undefined4 *)(iVar21 + 0x10);
  iVar21 = FUN_001054ec(iVar4,uVar14);
  local_a0 = *(undefined4 *)(iVar21 + 0x10);
  iVar21 = FUN_001054ec(iVar4,uVar15);
  local_ac = *(undefined4 *)(iVar21 + 0x10);
  iVar22 = 4;
  local_a8 = local_b4;
  iVar21 = 0;
  do {
    if (*(char *)((int)&local_b0 + iVar21) != '\x01') {
      *(char *)((int)&local_a8 + iVar21) = *(char *)((int)&local_b0 + iVar21);
    }
    iVar21 = iVar21 + 1;
    iVar22 = iVar22 + -1;
  } while (iVar22 != 0);
  FUN_00105894(iVar19,*(undefined4 *)(param_2 + 8));
  piVar5 = (int *)FUN_00105594(iVar4,uVar13);
  piVar8 = (int *)FUN_00105594(iVar4,uVar14);
  piVar9 = (int *)FUN_00105594(iVar4,uVar15);
  iVar19 = *(int *)(param_1 + 4);
  FUN_0019401c(param_1);
  if ((*(uint *)(iVar4 + 0x14) & 0x200) != 0) {
    uVar16 = *(undefined4 *)(param_2 + 8);
    uVar17 = *(uint *)(param_2 + 0x30) >> 7 & 1;
    if (uVar17 != 0) {
      iVar21 = FUN_00105594(iVar4,*(undefined4 *)(iVar4 + 0x84));
      puVar20 = *(uint **)(iVar21 + 0x10);
      uVar10 = puVar20[1];
      if (0 < (int)uVar10) {
        uVar18 = 0;
        do {
          if (uVar18 < *puVar20) {
            if (uVar10 <= uVar18) {
              _memset(uVar10 * 4 + puVar20[2],0,(uVar18 - uVar10) * 4 + 4);
              puVar20[1] = uVar18 + 1;
            }
            piVar11 = (int *)(uVar18 * 4 + puVar20[2]);
          }
          else {
            piVar11 = (int *)FUN_0019423c(puVar20,uVar18);
          }
          if (iVar4 == *piVar11) {
            FUN_00194208(puVar20,uVar18);
            iVar21 = FUN_00105594(iVar4,*(undefined4 *)(iVar4 + 0x84));
            *(int *)(iVar21 + 0x160) = *(int *)(iVar21 + 0x160) + -1;
            break;
          }
          uVar10 = puVar20[1];
          uVar18 = uVar18 + 1;
        } while ((int)uVar18 < (int)uVar10);
      }
    }
    FUN_00106004(iVar4,*(undefined4 *)(iVar4 + 0x84),0,uVar17,uVar16);
    *(int *)(iVar4 + 0x84) = *(int *)(iVar4 + 0x84) + -1;
    *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) & 0xfffffdff;
  }
  piVar11 = (int *)FUN_00103ebc(iVar4,param_1,*(undefined4 *)(param_2 + 8),0);
  FUN_000e7738(*(undefined4 *)(iVar19 + 0x158),iVar19,piVar11);
  iVar19 = piVar11[0x53];
  piVar11[0x27] = local_a8;
  iVar4 = FUN_001054ec(piVar11,0);
  *(int *)(iVar4 + 8) = iVar19;
  iVar4 = (**(code **)(*piVar8 + 0x60))(piVar8);
  if (iVar4 == 0) {
    piVar8 = (int *)FUN_0010a240(0xa2,*(undefined4 *)(param_2 + 8));
    FUN_000e7700(piVar11[0x56],piVar11,piVar8);
    piVar8[0x21] = 1;
    piVar8[0x25] = piVar8[0x53];
    piVar8[0x26] = 0x36;
    piVar8[0x27] = local_a8;
    iVar4 = FUN_00105594(piVar11,uVar14);
    FUN_00106004(piVar8,1,iVar4,0,*(undefined4 *)(param_2 + 8));
    if (*(int *)(param_2 + 0x478) < *(int *)(iVar4 + 0x160)) {
      *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
    }
    else {
      *(int *)(iVar4 + 0x160) = *(int *)(param_2 + 0x478) + 1;
    }
    piVar8[0x21] = 2;
    iVar4 = 0;
    ((void (*)())FUN_000f79c4)(piVar8,param_2,2,fparam_1,fparam_1,fparam_1,fparam_1);
    do {
      if (*(char *)((int)&local_b0 + iVar4) != '\x01') {
        (**(code **)(*piVar8 + 0x88))(piVar8,1,iVar4,*(undefined1 *)((int)&local_a0 + iVar4));
        (**(code **)(*piVar8 + 0x88))(piVar8,2,iVar4,4);
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar14,iVar4,iVar4);
      }
      bVar1 = iVar4 != 3;
      iVar4 = iVar4 + 1;
    } while (bVar1);
    iVar4 = 0;
    do {
      if (*(char *)((int)&local_b4 + iVar4) != '\x01') {
        (**(code **)(*piVar8 + 0x88))(piVar8,1,iVar4,4);
        (**(code **)(*piVar8 + 0x88))(piVar8,2,iVar4,iVar4);
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar14,iVar4,iVar4);
      }
      bVar1 = iVar4 != 3;
      iVar4 = iVar4 + 1;
    } while (bVar1);
    FUN_00106004(piVar11,uVar14,piVar8,0,*(undefined4 *)(param_2 + 8));
    piVar8[0x58] = *(int *)(param_2 + 0x478) + 1;
  }
  else {
    iVar4 = FUN_0010497c(piVar8,param_2);
    if (iVar4 == 0) {
      piVar8[0x58] = piVar8[0x58] + -1;
      piVar8 = (int *)FUN_0010445c(piVar8,*(undefined4 *)(param_2 + 8),0);
      FUN_000e7700(*(undefined4 *)(param_1 + 0x158),param_1,piVar8);
      piVar8[0x58] = *(int *)(param_2 + 0x478) + 1;
    }
    iVar4 = piVar8[0x21];
    if (1 < iVar4) {
      bVar1 = false;
      iVar19 = 2;
      do {
        iVar4 = FUN_001054ec(piVar8,0);
        iVar4 = FUN_000f5cf0(piVar8,iVar19,*(undefined4 *)(iVar4 + 0x10),&local_84);
        if ((iVar4 != 0) && (fparam_1 == (double)local_80)) {
          iVar4 = -1;
          iVar21 = 0;
          do {
            iVar22 = FUN_001054ec(piVar8,iVar19);
            if (*(char *)(iVar21 + iVar22 + 0x10) != '\x04') {
              iVar4 = iVar21;
            }
            bVar2 = iVar21 != 3;
            iVar21 = iVar21 + 1;
          } while (bVar2);
          iVar21 = 0;
          do {
            if (*(char *)((int)&local_b8 + iVar21) != '\x04') {
              bVar1 = true;
              (**(code **)(*piVar11 + 0x88))(piVar11,uVar14,iVar21,iVar4);
            }
            bVar2 = iVar21 != 3;
            iVar21 = iVar21 + 1;
          } while (bVar2);
          if (bVar1) goto LAB_00164300;
        }
        iVar4 = piVar8[0x21];
        iVar19 = iVar19 + 1;
      } while (iVar19 <= iVar4);
      if (bVar1) goto LAB_00164300;
    }
    iVar4 = iVar4 + 1;
    piVar8[0x21] = iVar4;
    ((void (*)())FUN_000f79c4)(piVar8,param_2,iVar4,fparam_1,fparam_1,fparam_1,fparam_1);
    iVar19 = FUN_001054ec(piVar8,iVar4);
    *(undefined4 *)(iVar19 + 0x10) = 0x4040404;
    iVar19 = 0;
    do {
      iVar21 = FUN_001054ec(piVar8,0);
      if (*(char *)(iVar19 + iVar21 + 0x10) != '\0') {
        (**(code **)(*piVar8 + 0x88))(piVar8,iVar4,iVar19,iVar19);
        *(undefined1 *)((int)piVar8 + iVar19 + 0x9c) = 0;
        goto LAB_001642bc;
      }
      bVar1 = iVar19 != 3;
      iVar19 = iVar19 + 1;
    } while (bVar1);
    iVar19 = -1;
LAB_001642bc:
    iVar4 = 0;
    do {
      if (*(char *)((int)&local_b8 + iVar4) != '\x04') {
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar14,iVar4,iVar19);
      }
      bVar1 = iVar4 != 3;
      iVar4 = iVar4 + 1;
    } while (bVar1);
  }
LAB_00164300:
  iVar4 = (**(code **)(*piVar9 + 0x60))(piVar9);
  if (iVar4 == 0) {
    piVar8 = (int *)FUN_0010a240(0xa2,*(undefined4 *)(param_2 + 8));
    FUN_000e7700(piVar11[0x56],piVar11,piVar8);
    piVar8[0x21] = 1;
    piVar8[0x25] = piVar8[0x53];
    piVar8[0x26] = 0x36;
    piVar8[0x27] = local_a8;
    iVar4 = FUN_00105594(piVar11,uVar15);
    FUN_00106004(piVar8,1,iVar4,0,*(undefined4 *)(param_2 + 8));
    if (*(int *)(param_2 + 0x478) < *(int *)(iVar4 + 0x160)) {
      *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
    }
    else {
      *(int *)(iVar4 + 0x160) = *(int *)(param_2 + 0x478) + 1;
    }
    piVar8[0x21] = 2;
    iVar4 = 0;
    ((void (*)())FUN_000f79c4)(piVar8,param_2,2,0.0,0.0,0.0,0.0);
    do {
      if (*(char *)((int)&local_b0 + iVar4) != '\x01') {
        (**(code **)(*piVar8 + 0x88))(piVar8,1,iVar4,*(undefined1 *)((int)&local_ac + iVar4));
        (**(code **)(*piVar8 + 0x88))(piVar8,2,iVar4,4);
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar15,iVar4,iVar4);
      }
      bVar1 = iVar4 != 3;
      iVar4 = iVar4 + 1;
    } while (bVar1);
    iVar4 = 0;
    do {
      if (*(char *)((int)&local_b4 + iVar4) != '\x01') {
        (**(code **)(*piVar8 + 0x88))(piVar8,1,iVar4,4);
        (**(code **)(*piVar8 + 0x88))(piVar8,2,iVar4,iVar4);
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar15,iVar4,iVar4);
      }
      bVar1 = iVar4 != 3;
      iVar4 = iVar4 + 1;
    } while (bVar1);
    FUN_00106004(piVar11,uVar15,piVar8,0,*(undefined4 *)(param_2 + 8));
    piVar8[0x58] = *(int *)(param_2 + 0x478) + 1;
  }
  else {
    iVar4 = FUN_0010497c(piVar9,param_2);
    if (iVar4 == 0) {
      piVar9[0x58] = piVar9[0x58] + -1;
      piVar9 = (int *)FUN_0010445c(piVar9,*(undefined4 *)(param_2 + 8),0);
      FUN_000e7700(*(undefined4 *)(param_1 + 0x158),param_1,piVar9);
      piVar9[0x58] = *(int *)(param_2 + 0x478) + 1;
    }
    iVar4 = piVar9[0x21];
    if (1 < iVar4) {
      bVar1 = false;
      iVar19 = 2;
      do {
        iVar4 = FUN_001054ec(piVar9,0);
        iVar4 = FUN_000f5cf0(piVar9,iVar19,*(undefined4 *)(iVar4 + 0x10),&local_84);
        if ((iVar4 != 0) && (local_80 == 0.0)) {
          iVar4 = -1;
          iVar21 = 0;
          do {
            iVar22 = FUN_001054ec(piVar9,iVar19);
            if (*(char *)(iVar21 + iVar22 + 0x10) != '\x04') {
              iVar4 = iVar21;
            }
            bVar2 = iVar21 != 3;
            iVar21 = iVar21 + 1;
          } while (bVar2);
          iVar21 = 0;
          do {
            if (*(char *)((int)&local_b8 + iVar21) != '\x04') {
              bVar1 = true;
              (**(code **)(*piVar11 + 0x88))(piVar11,uVar15,iVar21,iVar4);
            }
            bVar2 = iVar21 != 3;
            iVar21 = iVar21 + 1;
          } while (bVar2);
          if (bVar1) goto LAB_00164744;
        }
        iVar4 = piVar9[0x21];
        iVar19 = iVar19 + 1;
      } while (iVar19 <= iVar4);
      if (bVar1) goto LAB_00164744;
    }
    iVar4 = iVar4 + 1;
    piVar9[0x21] = iVar4;
    ((void (*)())FUN_000f79c4)(piVar9,param_2,iVar4,0.0,0.0,0.0,0.0);
    iVar19 = FUN_001054ec(piVar9,iVar4);
    *(undefined4 *)(iVar19 + 0x10) = 0x4040404;
    iVar19 = 0;
    do {
      iVar21 = FUN_001054ec(piVar9,0);
      if (*(char *)(iVar19 + iVar21 + 0x10) != '\0') {
        (**(code **)(*piVar9 + 0x88))(piVar9,iVar4,iVar19,iVar19);
        *(undefined1 *)((int)piVar9 + iVar19 + 0x9c) = 0;
        goto LAB_00164700;
      }
      bVar1 = iVar19 != 3;
      iVar19 = iVar19 + 1;
    } while (bVar1);
    iVar19 = -1;
LAB_00164700:
    iVar4 = 0;
    do {
      if (*(char *)((int)&local_b8 + iVar4) != '\x04') {
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar15,iVar4,iVar19);
      }
      bVar1 = iVar4 != 3;
      iVar4 = iVar4 + 1;
    } while (bVar1);
  }
LAB_00164744:
  iVar4 = 0;
  do {
    if (*(char *)((int)&local_b4 + iVar4) != '\x01') {
      iVar19 = (**(code **)(*piVar5 + 0x60))(piVar5);
      if (iVar19 == 0) {
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar13,iVar4,*(undefined1 *)((int)&local_a4 + iVar4))
        ;
      }
      else {
        iVar19 = FUN_001054ec(piVar5,0);
        iVar19 = FUN_000f3108(*(undefined4 *)(iVar19 + 0x10));
        (**(code **)(*piVar5 + 0x88))(piVar5,1,iVar19,*(undefined1 *)((int)&local_a4 + iVar4));
        (**(code **)(*piVar11 + 0x88))(piVar11,uVar13,iVar4,iVar19);
        *(undefined1 *)((int)piVar5 + iVar19 + 0x9c) = 0;
      }
    }
    bVar1 = iVar4 != 3;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  if (*(int *)(param_2 + 0x478) < piVar5[0x58]) {
    piVar5[0x58] = piVar5[0x58] + 1;
  }
  else {
    piVar5[0x58] = *(int *)(param_2 + 0x478) + 1;
  }
  if (local_98 != 0) {
    FUN_00106b48(piVar11,&local_9c,0,*(undefined4 *)(param_2 + 8));
    if (*(int *)(param_2 + 0x478) < *(int *)(local_98 + 0x160)) {
      *(int *)(local_98 + 0x160) = *(int *)(local_98 + 0x160) + 1;
    }
    else {
      *(int *)(local_98 + 0x160) = *(int *)(param_2 + 0x478) + 1;
    }
  }
  piVar11[0x58] = iVar3 + *(int *)(param_2 + 0x478);
  return 0;
}

/* FUN_001648ac @ 0x1648ac (456 bytes) */
int FUN_001648ac(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
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
          iVar1 = param_3;
          iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x60))
                            (*(int **)(param_1 + 8),param_2,param_3,param_4);
          iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x60))
                            (*(int **)(param_1 + 8),param_3,iVar1,param_4);
          if (iVar2 - iVar1 != 0) {
            return iVar2 - iVar1;
          }
          iVar1 = *(int *)(param_2 + 0xc) - *(int *)(param_3 + 0xc);
          goto joined_r0x00164a48;
        }
      }
    }
    else {
      iVar1 = *(int *)(param_2 + 0x1c);
      if (iVar1 == *(int *)(param_3 + 0x1c)) {
        iVar1 = param_3;
        iVar2 = (**(code **)(**(int **)(param_1 + 8) + 100))
                          (*(int **)(param_1 + 8),param_2,param_3,param_4);
        iVar1 = (**(code **)(**(int **)(param_1 + 8) + 100))
                          (*(int **)(param_1 + 8),param_3,iVar1,param_4);
        if (iVar2 - iVar1 != 0) {
          return iVar2 - iVar1;
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

/* FUN_00164bac @ 0x164bac (44 bytes) */
int FUN_00164bac(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((*(int *)(param_1 + 0x94) == *(int *)(param_2 + 0x94)) &&
     (*(int *)(param_1 + 0x98) == *(int *)(param_2 + 0x98))) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_00164bd8 @ 0x164bd8 (20 bytes) */
int FUN_00164bd8(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x98) * 0x10000 + *(int *)(param_1 + 0x94);
}

/* FUN_00164bec @ 0x164bec (520 bytes) */
int FUN_00164bec(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
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
  int local_28 [6];
  
  bVar2 = param_4 == 0;
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = param_2;
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
    piVar4 = *(int **)(*param_1 + 0x30c);
    uVar5 = (**(code **)(*piVar4 + 0x13c))(piVar4,*param_1);
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
        pcVar10 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
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
      pcVar10 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
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
  
  iVar1 = (**(code **)(*param_1 + 0x7c))(param_1);
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
  undefined4 local_28 [6];
  
  if (param_6 == 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x54))
                      (*(int **)(param_1 + 8),param_2,param_3,local_28);
    if (iVar1 != 0) {
      return local_28[0];
    }
    if ((((*(int *)(param_2[0x22] + 4) != 1) &&
         ((iVar1 = (**(code **)(*param_3 + 0x54))(param_3), iVar1 == 0 ||
          (iVar1 = FUN_001045e4(param_3), iVar1 != 0)))) &&
        ((iVar1 = (**(code **)(*param_3 + 0x5c))(param_3), iVar1 == 0 ||
         (iVar1 = (**(code **)(*param_2 + 0x28))(param_2), iVar1 == 0)))) &&
       ((iVar1 = (**(code **)(*param_3 + 0x60))(param_3), iVar1 == 0 &&
        (iVar1 = FUN_00104644(param_2), iVar1 == 0)))) {
      uVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x78))(*(int **)(param_1 + 8));
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
                    iVar11 = (**(code **)(*piVar10 + 0x5c))(piVar10);
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
        iVar5 = (**(code **)(*piVar2 + 0x5c))(piVar2);
        if (iVar5 == 0) goto LAB_00165840;
      }
      iVar5 = (**(code **)(*piVar1 + 0x60))(piVar1);
      if (iVar5 != 0) {
        piVar2 = (int *)FUN_00105594(piVar1,1);
        iVar5 = (**(code **)(*piVar2 + 0x5c))(piVar2);
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
int FUN_00165b7c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  uint param_7;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 a2;
  undefined4 a3;
  undefined4 a5;
  undefined4 a6;
  char *pcVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 uVar7;
  int iVar8;
  
  uVar7 = *(undefined4 *)(*param_1 + 0x378);
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = param_6;
  puVar1 = (undefined4 *)FUN_00193e18(uVar7,0x24);
  a6 = 0x1010101;
  *puVar1 = uVar7;
  puVar1[4] = 1;
  a3 = 0;
  puVar1[7] = 0x1010101;
  a5 = 0;
  puVar1[1] = param_2;
  puVar1[3] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[8] = 0;
  puVar1[2] = param_3;
  a2 = *(undefined4 *)(param_3 + 0x38);
  uVar7 = param_4;
  uVar2 = ((int (*)())FUN_00164e7c)(param_1,*(undefined4 *)(param_2 + 0x38),a2,0,param_4,0);
  puVar1[5] = param_4;
  puVar1[4] = uVar2;
  puVar1[6] = param_5;
  uVar7 = (**(code **)(*(int *)param_1[3] + 0x20))
                    ((int *)param_1[3],*(undefined4 *)(param_2 + 0x38),a2,a3,uVar7,a5,a6);
  puVar1[8] = uVar7;
  puVar1[7] = (*(unsigned int *)((unsigned char *)ghidra_home + 20));
  puVar6 = *(uint **)(param_2 + 0x40);
  uVar5 = puVar6[1];
  if (uVar5 < *puVar6) {
    _memset(uVar5 * 4 + puVar6[2],0,4);
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
    _memset(uVar5 * 4 + puVar6[2],0,4);
    puVar3 = (undefined4 *)(uVar5 * 4 + puVar6[2]);
    puVar6[1] = uVar5 + 1;
  }
  else {
    puVar3 = (undefined4 *)FUN_0019423c(puVar6,uVar5);
  }
  *puVar3 = puVar1 + 1;
  iVar8 = 4;
  pcVar4 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 20));
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

/* FUN_00165d3c @ 0x165d3c (504 bytes) */
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
  FUN_00172078(param_1[2],puVar12);
  return puVar12;
}

/* FUN_00165fa8 @ 0x165fa8 (632 bytes) */
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
          _memset(uVar4 * 4 + puVar12[2],0,(uVar7 - uVar4) * 4 + 4);
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
            _memset(uVar4 * 4 + puVar9[2],0,(uVar7 - uVar4) * 4 + 4);
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
    _memset(uVar4 * 4 + puVar12[2],0,4);
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
      iVar2 = (**(code **)(**(int **)(iVar13 + 0x38) + 0x14))(*(int **)(iVar13 + 0x38));
      if (1 < iVar2) break;
LAB_00166334:
      iVar2 = *(int *)(iVar13 + 8);
      FUN_0019401c(iVar13);
      iVar13 = iVar2;
    }
    iVar7 = 0;
    local_58[0] = 0x1010101;
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
    if (local_58[0] == 0x1010101) goto LAB_00166334;
    iVar2 = *(int *)(iVar13 + 0x38);
    if (piVar14 == (int *)0x0) {
      piVar14 = FUN_001043f0(0x12,*param_1);
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
    FUN_00103d50(piVar14 + 0x2f,1,(uint)(*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x9a));
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
      FUN_00172078(param_1[2],iVar13);
      puVar17 = *(uint **)(iVar13 + 0x44);
      uVar12 = puVar17[1];
      if (0 < (int)uVar12) {
        while( true ) {
          if (uVar15 < *puVar17) {
            uVar10 = puVar17[1];
            if (uVar10 <= uVar15) {
              _memset(uVar10 * 4 + puVar17[2],0,(uVar15 - uVar10) * 4 + 4);
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
              _memset(uVar5 * 4 + puVar17[2],0,(uVar15 - uVar5) * 4 + 4);
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
                      _memset(uVar6 * 4 + puVar17[2],0,(uVar16 - uVar6) * 4 + 4);
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
            (**(code **)(**(int **)(iVar18 + 0x38) + 0x60))(*(int **)(iVar18 + 0x38));
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
          _memset(uVar3 * 4 + puVar12[2],0,(uVar14 - uVar3) * 4 + 4);
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
          _memset(uVar10 * 4 + puVar12[2],0,4);
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
          _memset(uVar1 * 4 + puVar9[2],0,(uVar6 - uVar1) * 4 + 4);
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
                _memset(uVar3 * 4 + puVar9[2],0,(uVar8 - uVar3) * 4 + 4);
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
              _memset(uVar2 * 4 + puVar8[2],0,(uVar7 - uVar2) * 4 + 4);
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
              (iVar4 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))(*(int **)(param_1 + 0xc)),
              iVar4 != 0)) &&
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
          _memset(uVar1 * 4 + puVar10[2],0,(uVar8 - uVar1) * 4 + 4);
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
              _memset(uVar3 * 4 + puVar10[2],0,(uVar9 - uVar3) * 4 + 4);
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
          _memset(uVar1 * 4 + puVar10[2],0,(uVar8 - uVar1) * 4 + 4);
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
              _memset(uVar3 * 4 + puVar10[2],0,(uVar9 - uVar3) * 4 + 4);
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
  FUN_00172000(param_1[2]);
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
          _memset(uVar7 * 4 + puVar20[2],0,(uVar15 - uVar7) * 4 + 4);
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
      FUN_00172078(param_1[2],iVar12);
      *puVar16 = 0;
      puVar20 = *(uint **)(iVar12 + 0x40);
      uVar17 = puVar20[1];
      if (0 < (int)uVar17) {
        while( true ) {
          if (uVar7 < *puVar20) {
            uVar9 = puVar20[1];
            if (uVar9 <= uVar7) {
              _memset(uVar9 * 4 + puVar20[2],0,(uVar7 - uVar9) * 4 + 4);
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
        iVar3 = (**(code **)(**(int **)(iVar12 + 0x38) + 0x30))(*(int **)(iVar12 + 0x38));
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
              _memset(uVar9 * 4 + puVar20[2],0,(uVar17 - uVar9) * 4 + 4);
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
              _memset(uVar9 * 4 + puVar20[2],0,(uVar7 - uVar9) * 4 + 4);
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
  iVar10 = (**(code **)(*(int *)param_1[2] + 0x5c))((int *)param_1[2]);
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
          _memset(uVar1 * 4 + puVar7[2],0,(uVar6 - uVar1) * 4 + 4);
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
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool bVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint local_58 [7];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  if (param_2 != 1) {
    uVar4 = 0;
    piVar3 = *(int **)(*param_1 + 0x30c);
    uVar5 = (**(code **)(*piVar3 + 0x138))(piVar3,*param_1);
    iVar9 = param_1[0x66];
  }
  else {
    piVar3 = *(int **)(*param_1 + 0x30c);
    uVar4 = (**(code **)(*piVar3 + 0x138))(piVar3,*param_1);
    uVar5 = param_1[0x51];
    iVar9 = uVar4 + param_1[0x67];
  }
  uVar10 = 0xffffffff;
  if ((int)uVar4 < (int)uVar5) {
    iVar12 = uVar4 << 2;
    iVar8 = 4;
    uVar13 = uVar4;
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
      iVar7 = 0;
      iVar14 = 4;
      piVar3 = param_1;
      do {
        iVar6 = *(int *)(piVar3[0x4d] + iVar12);
        if (((iVar6 != 0) && (0 < *(int *)(iVar7 * 4 + iVar6 + 0x48))) &&
           (*(uint **)(iVar6 + 0x60) != (uint *)0x0)) {
          local_58[0] = local_58[0] | **(uint **)(iVar6 + 0x60);
        }
        iVar7 = iVar7 + 1;
        piVar3 = piVar3 + 1;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      if (bVar1) {
        iVar14 = 0;
        iVar7 = 0;
        pcVar11 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
        piVar3 = param_1;
        do {
          if ((*(char *)((int)local_58 + iVar14) == '\0') &&
             ((*(int *)(piVar3[0x4d] + iVar12) == 0 ||
              (*(int *)(iVar14 * 4 + *(int *)(piVar3[0x4d] + iVar12) + 0x48) < 1)))) {
            cVar2 = *pcVar11;
            if (cVar2 == '\0') {
              iVar7 = iVar7 + 1;
            }
LAB_00167d14:
            if (((cVar2 != '\0') && (iVar6 = *(int *)(param_1[1] + 0x38), iVar6 != 0)) &&
               ((*(uint *)(iVar6 + 0x94) == uVar13 &&
                ((((iVar6 = FUN_000f313c(iVar6,iVar14), iVar6 != 0 &&
                   (iVar6 = *(int *)(piVar3[0x4d] + iVar12), iVar6 != 0)) &&
                  (*(int *)(iVar6 + 0x38) == *(int *)(param_1[1] + 0x38))) &&
                 (iVar6 = ((int (*)())FUN_00167a74)(iVar6,iVar14), iVar6 == param_1[0xb])))))) goto LAB_00167cf0;
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
          piVar3 = piVar3 + 1;
        } while (iVar14 != 4);
        if (((int)uVar10 < 0) || (iVar7 < iVar8)) {
          iVar8 = iVar7;
          uVar10 = uVar13;
        }
      }
LAB_00167db4:
      uVar13 = uVar13 + 1;
      iVar12 = iVar12 + 4;
    } while (uVar13 != uVar5);
  }
  if (param_2 != 1) {
    iVar9 = param_1[0x66];
    if (param_1[0x66] < (int)(uVar10 - uVar4)) {
      iVar9 = uVar10 - uVar4;
    }
    param_1[0x66] = iVar9;
  }
  else {
    iVar9 = param_1[0x67];
    if (param_1[0x67] < (int)(uVar10 - uVar4)) {
      iVar9 = uVar10 - uVar4;
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
  undefined4 uVar3;
  int iVar4;
  undefined4 local_28 [2];
  
  iVar4 = *(int *)(*param_1 + 0x6c4);
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
  *(int *)(iVar4 + 0x23c) = *(int *)(iVar4 + 0x23c) + 1;
  uVar3 = ((int (*)())FUN_00165d3c)(param_1,iVar2,param_5,param_4);
  return uVar3;
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
  uint in_r9;
  uint uVar8;
  int *a0;
  int iVar9;
  int *piVar10;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  a0 = *(int **)(param_2 + 0x38);
  iVar1 = (**(code **)(*a0 + 0x14))(a0,param_2);
  if ((iVar1 < 3) || (*(int *)(a0[0x22] + 8) == 0x14)) goto LAB_00168120;
  iVar1 = FUN_00105594(a0,1);
  if (*(int *)(iVar1 + 0x98) != 0) {
    piVar2 = (int *)FUN_00105594(a0,1);
    iVar1 = (**(code **)(*piVar2 + 0x60))(piVar2);
    if (iVar1 == 0) goto LAB_00168120;
    uVar3 = FUN_00105594(a0,1);
    iVar1 = FUN_00105594(uVar3,1);
    if (*(int *)(iVar1 + 0x98) != 0) goto LAB_00168120;
  }
  iVar1 = FUN_00105594(a0,2);
  if (*(int *)(iVar1 + 0x98) != 0) {
    piVar2 = (int *)FUN_00105594(a0,2);
    iVar1 = (**(code **)(*piVar2 + 0x60))(piVar2);
    if (iVar1 == 0) goto LAB_00168120;
    uVar3 = FUN_00105594(a0,2);
    iVar1 = FUN_00105594(uVar3,1);
    if (*(int *)(iVar1 + 0x98) != 0) goto LAB_00168120;
  }
  iVar1 = FUN_00105594(a0,3);
  if (*(int *)(iVar1 + 0x98) != 0) {
    piVar2 = (int *)FUN_00105594(a0,3);
    iVar1 = (**(code **)(*piVar2 + 0x60))(piVar2);
    if (iVar1 != 0) {
      uVar3 = FUN_00105594(a0,3);
      iVar1 = FUN_00105594(uVar3,1);
      if (*(int *)(iVar1 + 0x98) == 0) goto LAB_00168060;
    }
LAB_00168120:
    iVar1 = -1;
    for (iVar4 = 1; iVar5 = (**(code **)(*a0 + 0x14))(a0), iVar4 <= iVar5; iVar4 = iVar4 + 1) {
      piVar2 = (int *)FUN_00105594(a0,iVar4);
      iVar5 = (**(code **)(*piVar2 + 0x60))(piVar2);
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
      iVar5 = (**(code **)(*a0 + 0x14))(a0);
      if (iVar5 < iVar4) {
        return 0;
      }
      piVar2 = (int *)FUN_00105594(a0,iVar4);
      iVar5 = (**(code **)(*piVar2 + 0x60))(piVar2);
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
             ((uVar8 = piVar2[0x56], uVar8 == param_1[4] ||
              (uVar8 = *(uint *)(uVar8 + 0x118), *(uint *)(param_1[1] + 0x474) == uVar8)))) {
            iVar1 = FUN_001054ec(a0,iVar4);
            FUN_000f32cc(&local_40,*(undefined4 *)(iVar1 + 0x10));
            uVar3 = FUN_00105594(a0,iVar4);
            iVar1 = ((int (*)())FUN_00167e1c)(param_1,uVar3,local_40,param_1[0xb],param_2 + 0xc);
            FUN_00106004(a0,iVar4,*(undefined4 *)(iVar1 + 0x38),0,*param_1);
            iVar5 = FUN_001054ec(a0,iVar4);
            FUN_000f3398(local_3c,*(undefined4 *)(iVar5 + 0x10));
            ((int (*)())FUN_00165b7c)(param_1,iVar1,param_2,iVar4,0,local_3c[0],uVar8);
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
  uVar3 = FUN_00105594(a0,1);
  iVar1 = FUN_001054ec(a0,1);
  FUN_000f32cc(&local_48,*(undefined4 *)(iVar1 + 0x10));
  iVar1 = ((int (*)())FUN_00167e1c)(param_1,uVar3,local_48,param_1[0xb],param_2 + 0xc);
  FUN_00106004(a0,1,*(undefined4 *)(iVar1 + 0x38),0,*param_1);
  iVar4 = FUN_001054ec(a0,1);
  FUN_000f3398(&local_44,*(undefined4 *)(iVar4 + 0x10));
  ((int (*)())FUN_00165b7c)(param_1,iVar1,param_2,1,0,local_44,in_r9);
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
  int *piVar7;
  undefined4 uVar8;
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
  undefined4 local_88;
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
        _memset(uVar12 * 4 + puVar19[2],0,(uVar17 - uVar12) * 4 + 4);
        puVar19[1] = uVar17 + 1;
      }
      piVar7 = (int *)(uVar17 * 4 + puVar19[2]);
    }
    else {
      piVar7 = (int *)FUN_0019423c(puVar19,uVar17);
    }
    iVar4 = *piVar7;
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
      uVar18 = *(undefined4 *)(iVar15 + 0x10);
      if (bVar1) {
        iVar15 = FUN_001054ec(*(undefined4 *)(param_2 + 0x38),param_4);
        FUN_000f3398(&local_68,*(undefined4 *)(iVar15 + 0x10));
        piVar7 = (int *)FUN_00105594(*(undefined4 *)(param_2 + 0x38),param_4);
        if (param_3 != piVar7) {
          piVar7 = (int *)FUN_00105594(*(undefined4 *)(param_2 + 0x38),param_4);
          iVar15 = (**(code **)(*piVar7 + 0x60))(piVar7);
          if (iVar15 != 0) {
            uVar8 = FUN_00105594(*(undefined4 *)(param_2 + 0x38),param_4);
            FUN_00105594(uVar8,1);
          }
          uVar8 = FUN_00105594(*(undefined4 *)(param_2 + 0x38),param_4);
          iVar15 = FUN_001054ec(uVar8,1);
          FUN_000f3340(&local_64,*(undefined4 *)(iVar15 + 0x10),local_68);
          FUN_000f3398(&local_60,local_64);
          local_68 = local_60;
        }
        FUN_000f3340(&local_5c,uVar18,local_68);
        uVar18 = local_5c;
      }
      FUN_000f3398(local_58,uVar18);
      bVar2 = iVar16 == 0;
      local_88 = local_58[0];
      iVar15 = 0;
      puVar6 = &local_88;
LAB_00168844:
      piVar7 = puVar6 + 2;
      do {
        local_84 = piVar3[3] & local_88;
        if ((piVar3[3] & local_88) != 0) {
          uVar18 = *(undefined4 *)(*param_1 + 0x378);
          puVar9 = (undefined4 *)FUN_00193e18(uVar18,0x24);
          puVar13 = puVar9 + 1;
          *puVar9 = uVar18;
          puVar9[1] = iVar4;
          puVar9[4] = 1;
          puVar9[7] = 0x1010101;
          puVar9[3] = 0;
          puVar9[5] = 0;
          puVar9[6] = 0;
          puVar9[8] = 0;
          puVar9[2] = param_2;
          uVar18 = ((int (*)())FUN_00164e7c)(param_1,piVar3,param_3,0,param_4,0);
          puVar9[4] = uVar18;
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
            uVar18 = (**(code **)(*(int *)param_1[3] + 0x20))((int *)param_1[3],piVar10);
            puVar9[8] = uVar18;
          }
          puVar19 = *(uint **)(iVar4 + 0x40);
          uVar17 = puVar19[1];
          if (uVar17 < *puVar19) {
            _memset(uVar17 * 4 + puVar19[2],0,4);
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
            _memset(uVar17 * 4 + puVar19[2],0,4);
            piVar10 = (int *)(uVar17 * 4 + puVar19[2]);
            puVar19[1] = uVar17 + 1;
          }
          else {
            piVar10 = (int *)FUN_0019423c(puVar19,uVar17);
          }
          *piVar10 = (int)puVar13;
          iVar15 = iVar15 + 1;
          *piVar7 = (int)puVar13;
          puVar6 = puVar6 + 1;
          piVar7 = piVar7 + 1;
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
          local_88 = uVar17 * 0x1000000 | (uVar17 & 0xff00) << 8 | uVar17 >> 8 & 0xff00 |
                     uVar17 >> 0x18;
        }
        else {
          local_88 = 0;
        }
        if ((local_88 == 0) || ((piVar3[5] & 0x200U) == 0)) {
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
                piVar7 = (int *)*puVar9;
                if ((*(uint *)(*(int *)(*piVar3 + 0x38) + 0xc) &
                    *(uint *)(*(int *)(*piVar7 + 0x38) + 0xc)) != 0) {
                  uVar18 = *(undefined4 *)(*param_1 + 0x378);
                  puVar13 = (undefined4 *)FUN_00193e18(uVar18,0x24);
                  *puVar13 = uVar18;
                  puVar13[1] = 0;
                  iVar11 = *piVar7;
                  puVar13[1] = iVar11;
                  iVar16 = *piVar3;
                  puVar13[4] = 1;
                  puVar13[7] = 0x1010101;
                  puVar13[3] = 3;
                  puVar13[2] = iVar16;
                  puVar13[5] = 0;
                  puVar13[6] = 0;
                  puVar13[8] = 0;
                  uVar18 = ((int (*)())FUN_00164e7c)(param_1,*(undefined4 *)(iVar11 + 0x38),
                                        *(undefined4 *)(iVar16 + 0x38),0,0,3);
                  iVar11 = *piVar7;
                  iVar16 = *piVar3;
                  puVar13[4] = uVar18;
                  puVar13[7] = *(uint *)(*(int *)(iVar16 + 0x38) + 0xc) &
                               *(uint *)(*(int *)(iVar11 + 0x38) + 0xc);
                  puVar19 = *(uint **)(puVar13[1] + 0x40);
                  uVar17 = puVar19[1];
                  if (uVar17 < *puVar19) {
                    _memset(uVar17 * 4 + puVar19[2],0,4);
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
                    _memset(uVar17 * 4 + puVar19[2],0,4);
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
        iVar4 = (**(code **)(*piVar10 + 0x50))(piVar10);
        if (iVar4 != 0) goto LAB_00168ab0;
        piVar3 = (int *)FUN_00105594(piVar3,piVar3[0x21]);
        if ((piVar3[0x56] == param_1[4]) && (iVar4 = ((int (*)())FUN_00164df4)(piVar3), iVar4 == 0))
        goto LAB_00168b48;
        iVar16 = 1;
        bVar2 = false;
        iVar4 = ((int (*)())FUN_00165fa8)(param_1,piVar3);
      } while( true );
    }
    uVar18 = *(undefined4 *)(*param_1 + 0x378);
    puVar6 = (undefined4 *)FUN_00193e18(uVar18,0x24);
    *puVar6 = uVar18;
    puVar6[4] = 1;
    puVar6[1] = iVar4;
    puVar6[7] = 0x1010101;
    puVar6[3] = 0;
    puVar6[5] = 0;
    puVar6[6] = 0;
    puVar6[8] = 0;
    puVar6[2] = param_2;
    uVar18 = ((int (*)())FUN_00164e7c)(param_1,piVar3,param_3,0,param_4,0);
    puVar6[5] = param_4;
    puVar6[4] = uVar18;
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
    *puVar6 = uVar18;
    puVar6[4] = 1;
    puVar6[1] = iVar4;
    puVar6[3] = 3;
    puVar6[7] = 0x1010101;
    puVar6[8] = 0;
    puVar6[5] = 0;
    puVar6[6] = 0;
    puVar6[2] = param_2;
    uVar18 = ((int (*)())FUN_00164e7c)(param_1,piVar3,param_3,0,0,3);
    puVar6[4] = uVar18;
    puVar6[7] = param_3[3];
  }
  puVar19 = *(uint **)(iVar4 + 0x40);
  uVar17 = puVar19[1];
  if (uVar17 < *puVar19) {
    _memset(uVar17 * 4 + puVar19[2],0,4);
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
    _memset(uVar17 * 4 + puVar19[2],0,4);
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
      _memset(uVar12 * 4 + puVar19[2],0,(uVar17 - uVar12) * 4 + 4);
      puVar19[1] = uVar17 + 1;
    }
    piVar7 = (int *)(uVar17 * 4 + puVar19[2]);
  }
  else {
    piVar7 = (int *)FUN_0019423c(puVar19,uVar17);
  }
  iVar4 = *piVar7;
  goto LAB_00168844;
}

/* FUN_00168d80 @ 0x168d80 (2668 bytes) */
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
  int local_88;
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
    FUN_0017212c(param_1[2],param_2);
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
      if (local_88 < 2) {
        puVar20 = (undefined1 *)((int)&local_80 + local_88 + 1);
        puVar21 = (undefined1 *)((int)&local_7c + local_88 + 1);
        iVar5 = local_88;
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
        if (local_88 < 3) {
          puVar20 = (undefined1 *)((int)&local_80 + local_88 + 1);
          puVar21 = (undefined1 *)((int)&local_7c + local_88 + 1);
          iVar5 = local_88;
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
      FUN_0017212c(param_1[2],param_2);
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
      uVar9 = UNK_001b019c;
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
        if (iVar8 != 0) goto code_r0x001699c4;
      }
      uVar9 = 0;
code_r0x001699c4:
      *(undefined4 *)(param_2 + 0x5c) = uVar9;
      (**(code **)(*(int *)param_1[2] + 0x48))((int *)param_1[2],param_2);
      FUN_00172078(param_1[2],param_2);
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
        _memset(uVar4 * 4 + puVar24[2],0,4);
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
        _memset(uVar4 * 4 + puVar24[2],0,4);
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
    FUN_0017212c(param_1[2],param_2);
    if (*(int *)(piVar25[0x22] + 8) == 0x1e) {
      FUN_00108304(piVar25,0x14,*param_1);
      piVar25[0x27] = iVar18;
      puVar2 = PTR_DAT_001e8b8c;
      uVar9 = *(undefined4 *)
               (PTR_DAT_001e8b8c + (uint)*(byte *)((int)&local_80 + (1 - local_88)) * 4);
      iVar18 = FUN_001054ec(piVar25,1);
      *(undefined4 *)(iVar18 + 0x10) = uVar9;
      uVar9 = *(undefined4 *)(puVar2 + (uint)*(byte *)((int)&local_7c + (1 - local_88)) * 4);
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
        if (local_88 < 2) {
          puVar20 = (undefined1 *)((int)&local_80 + local_88 + 1);
          puVar21 = (undefined1 *)((int)&local_7c + local_88 + 1);
          iVar18 = local_88;
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
  FUN_00172078(param_1[2],param_2);
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
    _memset(uVar4 * 4 + puVar24[2],0,4);
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
    _memset(uVar4 * 4 + puVar24[2],0,4);
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

/* FUN_00169b70 @ 0x169b70 (680 bytes) */
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
          _memset(uVar2 * 4 + puVar10[2],0,(uVar8 - uVar2) * 4 + 4);
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
              _memset(uVar4 * 4 + puVar10[2],0,(uVar2 - uVar4) * 4 + 4);
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
    (**(code **)(**(int **)(param_1 + 8) + 8))(*(int **)(param_1 + 8));
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
  int in_r7;
  undefined4 in_r8;
  int *piVar11;
  undefined4 in_r10;
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
            in_r7 = *param_1;
            FUN_00106004(piVar5,0,0,0,in_r7);
            iVar2 = (**(code **)(*piVar12 + 0x14))(piVar12);
            if (iVar2 != 0) {
              piVar5[5] = piVar5[5] | 0x20;
            }
            iVar2 = (**(code **)(*piVar5 + 0x7c))(piVar5);
            if (iVar2 == 0) {
              if ((*(int *)(piVar5[0x22] + 8) == 0x32) &&
                 (iVar2 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0xd0))
                                    (*(int **)(*param_1 + 0x30c)), iVar2 == 0)) {
                piVar4 = (int *)piVar5[2];
                piVar5[5] = piVar5[5] | 0x20;
                goto LAB_0016a118;
              }
              if (0 < piVar5[0x21]) {
                iVar2 = 1;
                do {
                  piVar11 = (int *)FUN_00105594(piVar5,iVar2);
                  iVar3 = (**(code **)(*piVar11 + 0x5c))(piVar11);
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
                      iVar9 = (**(code **)(*piVar4 + 0x5c))(piVar4);
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
  FUN_000e0e0c(*param_1,"Scheduler : %d out of %d instructions are marked global\n",iVar9,iVar10,
               in_r7,in_r8,0,in_r10);
  FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),iVar8);
  FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),iVar7);
  return;
}

/* FUN_0016a568 @ 0x16a568 (6052 bytes) */
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
  int iVar12;
  uint uVar13;
  int *piVar14;
  undefined4 *puVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  undefined4 *puVar24;
  uint *puVar25;
  undefined4 uVar26;
  uint *puVar27;
  undefined1 auStack_78 [8];
  int local_70;
  uint local_58;
  int local_54;
  
  iVar7 = FUN_000e07dc(*param_1,0x24);
  uVar19 = 0x7fffffff;
  if (iVar7 == 0) {
    uVar19 = 0;
  }
  param_1[4] = param_2;
  FUN_00172000(param_1[2]);
  FUN_001940a8(auStack_78);
  piVar4 = (int *)(*(int **)(param_1[4] + 0x98))[2];
  if (piVar4 != (int *)0x0) {
    uVar20 = 0;
    bVar2 = false;
    piVar14 = *(int **)(param_1[4] + 0x98);
    do {
      piVar5 = piVar4;
      if ((piVar14[5] & 1U) != 0) {
        piVar14[5] = piVar14[5] & 0xffffefff;
        piVar14[0x54] = 0;
        iVar7 = (**(code **)(*piVar14 + 0x34))(piVar14);
        if ((iVar7 == 0) && (iVar7 = (**(code **)(*piVar14 + 0x38))(piVar14), iVar7 == 0)) {
          iVar7 = ((int (*)())FUN_00164df4)(piVar14);
          if (iVar7 == 0) {
            iVar7 = ((int (*)())FUN_00164fc0)(piVar14);
            if (((iVar7 != 0) ||
                (iVar7 = (**(code **)(*(int *)param_1[3] + 0x2c))((int *)param_1[3],piVar14),
                iVar7 != 0)) ||
               (iVar7 = (**(code **)(*(int *)param_1[3] + 0x28))((int *)param_1[3],piVar14),
               iVar7 != 0)) {
              bVar2 = true;
            }
            piVar14[0x54] = uVar20;
            uVar26 = *(undefined4 *)(*param_1 + 0x378);
            puVar15 = (undefined4 *)FUN_00193e18(uVar26,0x74);
            puVar3 = PTR_DAT_001e9138;
            puVar24 = puVar15 + 1;
            puVar6 = PTR_DAT_001e8b48 + 8;
            *puVar15 = uVar26;
            puVar15[1] = puVar6;
            puVar15[0xc] = 0xffffffff;
            puVar15[1] = puVar3 + 8;
            puVar15[0x11] = 0;
            puVar15[0x1c] = 0;
            iVar7 = 4;
            puVar15[2] = 0;
            puVar15[3] = 0;
            puVar15[0xd] = 0;
            puVar15[0xe] = 0;
            puVar15[0xf] = piVar14;
            puVar15[0x10] = uVar20;
            puVar15[0x12] = 0;
            puVar15[0x17] = 0;
            puVar15[0x18] = 0;
            puVar15[0x19] = 0;
            puVar15[0x1a] = 0;
            puVar15[0x1b] = 0;
            puVar11 = puVar24;
            do {
              puVar11[0x12] = 0;
              puVar11 = puVar11 + 1;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
            puVar15[4] = 0;
            puVar15[7] = 1;
            puVar15[5] = 0;
            puVar15[6] = 1;
            puVar15[8] = 0;
            puVar15[9] = 0;
            puVar15[10] = 0;
            puVar15[0xb] = 0;
            uVar26 = *(undefined4 *)(*param_1 + 0x378);
            puVar11 = (undefined4 *)FUN_00193e18(uVar26,0x14);
            *puVar11 = uVar26;
            puVar11[1] = 2;
            puVar11[4] = uVar26;
            puVar11[2] = 0;
            uVar26 = FUN_00193e18(uVar26,8);
            puVar11[3] = uVar26;
            puVar15[0x12] = puVar11 + 1;
            uVar26 = *(undefined4 *)(*param_1 + 0x378);
            puVar11 = (undefined4 *)FUN_00193e18(uVar26,0x14);
            *puVar11 = uVar26;
            puVar11[1] = 2;
            puVar11[2] = 0;
            puVar11[4] = uVar26;
            uVar26 = FUN_00193e18(uVar26,8);
            puVar11[3] = uVar26;
            puVar15[0x11] = puVar11 + 1;
            if (0 < piVar14[0x21]) {
              iVar7 = 1;
              bVar1 = false;
              do {
                ((int (*)())FUN_00168468)(param_1,puVar24,piVar14,iVar7,0);
                piVar4 = (int *)FUN_00105594(piVar14,iVar7);
                iVar17 = (**(code **)(*piVar4 + 0x5c))(piVar4);
                if (iVar17 == 0) {
                  piVar4 = (int *)FUN_00105594(piVar14,iVar7);
                  iVar17 = (**(code **)(*piVar4 + 0x60))(piVar4);
                  if (iVar17 != 0) goto LAB_0016a958;
                  uVar26 = FUN_00105594(piVar14,iVar7);
                  iVar17 = FUN_001045e4(uVar26);
                  if ((iVar17 != 0) &&
                     (iVar17 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0xd4))
                                         (*(int **)(*param_1 + 0x30c)), iVar17 != 0))
                  goto LAB_0016a958;
                }
                else {
LAB_0016a958:
                  piVar4 = (int *)FUN_00105594(piVar14,iVar7);
                  iVar17 = (**(code **)(*piVar4 + 0x60))(piVar4);
                  if (iVar17 != 0) {
                    piVar5 = (int *)FUN_00105594(piVar4,1);
                    iVar17 = (**(code **)(*piVar5 + 0x5c))(piVar5);
                    if (iVar17 != 0) {
                      piVar4 = (int *)FUN_00105594(piVar4,1);
                    }
                  }
                  for (iVar17 = 1; iVar16 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar17 <= iVar16;
                      iVar17 = iVar17 + 1) {
                    ((int (*)())FUN_00168468)(param_1,puVar24,piVar4,iVar7,iVar17);
                  }
                }
                uVar26 = FUN_00105594(piVar14,iVar7);
                iVar17 = FUN_00104644(uVar26);
                if (iVar17 != 0) {
                  bVar1 = true;
                }
                iVar7 = iVar7 + 1;
              } while (iVar7 <= piVar14[0x21]);
              if (bVar1) {
                puVar25 = (uint *)puVar15[0x12];
                uVar13 = 0;
                uVar21 = puVar25[1];
                if (0 < (int)uVar21) {
                  while( true ) {
                    if (uVar13 < *puVar25) {
                      uVar9 = puVar25[1];
                      if (uVar9 <= uVar13) {
                        _memset(uVar9 * 4 + puVar25[2],0,(uVar13 - uVar9) * 4 + 4);
                        puVar25[1] = uVar13 + 1;
                      }
                      puVar11 = (undefined4 *)(uVar13 * 4 + puVar25[2]);
                    }
                    else {
                      puVar11 = (undefined4 *)FUN_0019423c(puVar25,uVar13);
                    }
                    iVar17 = *(int *)*puVar11;
                    iVar7 = FUN_00104644(*(undefined4 *)(iVar17 + 0x38));
                    if (iVar7 == 0) {
                      uVar9 = 0;
                      do {
                        puVar25 = (uint *)puVar15[0x12];
                        if (uVar9 < *puVar25) {
                          uVar8 = puVar25[1];
                          if (uVar8 <= uVar9) {
                            _memset(uVar8 * 4 + puVar25[2],0,(uVar9 - uVar8) * 4 + 4);
                            puVar25[1] = uVar9 + 1;
                          }
                          puVar11 = (undefined4 *)(uVar9 * 4 + puVar25[2]);
                        }
                        else {
                          puVar11 = (undefined4 *)FUN_0019423c(puVar25,uVar9);
                        }
                        iVar16 = *(int *)*puVar11;
                        iVar7 = FUN_00104644(*(undefined4 *)(iVar16 + 0x38));
                        if ((iVar7 != 0) && (*(int *)(iVar17 + 0x3c) < *(int *)(iVar16 + 0x3c))) {
                          uVar26 = *(undefined4 *)(*param_1 + 0x378);
                          puVar11 = (undefined4 *)FUN_00193e18(uVar26,0x24);
                          *puVar11 = uVar26;
                          puVar11[4] = 1;
                          puVar11[1] = iVar17;
                          puVar11[7] = 0x1010101;
                          puVar11[3] = 5;
                          puVar11[5] = 0;
                          puVar11[6] = 0;
                          puVar11[8] = 0;
                          puVar11[2] = iVar16;
                          uVar26 = ((int (*)())FUN_00164e7c)(param_1,*(undefined4 *)(iVar17 + 0x38),
                                                *(undefined4 *)(iVar16 + 0x38),0,0,5);
                          puVar11[4] = uVar26;
                          puVar25 = *(uint **)(iVar17 + 0x40);
                          uVar8 = puVar25[1];
                          if (uVar8 < *puVar25) {
                            _memset(uVar8 * 4 + puVar25[2],0,4);
                            piVar4 = (int *)(uVar8 * 4 + puVar25[2]);
                            puVar25[1] = uVar8 + 1;
                          }
                          else {
                            piVar4 = (int *)FUN_0019423c(puVar25,uVar8);
                          }
                          *piVar4 = (int)(puVar11 + 1);
                          puVar25 = *(uint **)(iVar16 + 0x44);
                          uVar8 = puVar25[1];
                          if (uVar8 < *puVar25) {
                            _memset(uVar8 * 4 + puVar25[2],0,4);
                            piVar4 = (int *)(uVar8 * 4 + puVar25[2]);
                            puVar25[1] = uVar8 + 1;
                          }
                          else {
                            piVar4 = (int *)FUN_0019423c(puVar25,uVar8);
                          }
                          *piVar4 = (int)(puVar11 + 1);
                        }
                        uVar9 = uVar9 + 1;
                      } while (uVar21 != uVar9);
                    }
                    uVar13 = uVar13 + 1;
                    if (uVar21 == uVar13) break;
                    puVar25 = (uint *)puVar15[0x12];
                  }
                }
              }
            }
            if (*(int *)(piVar14[0x22] + 4) == 1) {
              FUN_00193f64(auStack_78,puVar24);
            }
            if (uVar19 == uVar20) {
              uVar13 = uVar20 - 1;
              if (-1 < (int)uVar13) {
                iVar7 = uVar13 * 4;
                uVar21 = 0;
                do {
                  puVar25 = (uint *)param_1[6];
                  if (uVar13 < *puVar25) {
                    uVar9 = puVar25[1];
                    if (uVar9 <= uVar13) {
                      _memset(uVar9 * 4 + puVar25[2],0,(uVar13 - uVar9) * 4 + 4);
                      puVar25[1] = uVar13 + 1;
                    }
                    piVar4 = (int *)(iVar7 + puVar25[2]);
                  }
                  else {
                    piVar4 = (int *)FUN_0019423c(puVar25,uVar13);
                  }
                  iVar17 = *piVar4;
                  iVar16 = *(int *)(iVar17 + 0x38);
                  if (((*(uint *)(iVar16 + 0x14) & 2) == 0) &&
                     (*(int *)(*(int *)(iVar16 + 0x88) + 4) != 1)) {
                    uVar26 = *(undefined4 *)(*param_1 + 0x378);
                    puVar11 = (undefined4 *)FUN_00193e18(uVar26,0x24);
                    *puVar11 = uVar26;
                    puVar11[1] = iVar17;
                    puVar11[7] = 0x1010101;
                    puVar11[8] = 0;
                    puVar11[4] = 1;
                    puVar11[5] = 0;
                    puVar11[6] = 0;
                    puVar11[2] = puVar24;
                    puVar11[3] = 1;
                    uVar26 = ((int (*)())FUN_00164e7c)(param_1,iVar16,piVar14,0,0,1);
                    puVar11[4] = uVar26;
                    puVar25 = *(uint **)(iVar17 + 0x40);
                    uVar9 = puVar25[1];
                    if (uVar9 < *puVar25) {
                      _memset(uVar9 * 4 + puVar25[2],0,4);
                      puVar10 = (undefined4 *)(uVar9 * 4 + puVar25[2]);
                      puVar25[1] = uVar9 + 1;
                    }
                    else {
                      puVar10 = (undefined4 *)FUN_0019423c(puVar25,uVar9);
                    }
                    *puVar10 = puVar11 + 1;
                    puVar25 = (uint *)puVar15[0x12];
                    uVar9 = puVar25[1];
                    if (uVar9 < *puVar25) {
                      _memset(uVar9 * 4 + puVar25[2],0,4);
                      puVar10 = (undefined4 *)(uVar9 * 4 + puVar25[2]);
                      puVar25[1] = uVar9 + 1;
                    }
                    else {
                      puVar10 = (undefined4 *)FUN_0019423c(puVar25,uVar9);
                    }
                    *puVar10 = puVar11 + 1;
                  }
                  uVar21 = uVar21 + 1;
                  uVar13 = uVar13 - 1;
                  iVar7 = iVar7 + -4;
                } while (uVar21 != uVar20);
              }
            }
            else if ((int)uVar19 < (int)uVar20) {
              puVar25 = (uint *)param_1[6];
              uVar13 = uVar20 - 1;
              if (uVar13 < *puVar25) {
                uVar21 = puVar25[1];
                if (uVar21 <= uVar13) {
                  _memset(uVar21 * 4 + puVar25[2],0,(uVar13 - uVar21) * 4 + 4);
                  puVar25[1] = uVar20;
                }
                piVar4 = (int *)(uVar13 * 4 + puVar25[2]);
              }
              else {
                piVar4 = (int *)FUN_0019423c(puVar25,uVar13);
              }
              iVar17 = *piVar4;
              iVar7 = *(int *)(iVar17 + 0x38);
              if (*(int *)(*(int *)(iVar7 + 0x88) + 4) != 1) {
                uVar26 = *(undefined4 *)(*param_1 + 0x378);
                puVar11 = (undefined4 *)FUN_00193e18(uVar26,0x24);
                *puVar11 = uVar26;
                puVar11[1] = iVar17;
                puVar11[7] = 0x1010101;
                puVar11[8] = 0;
                puVar11[3] = 1;
                puVar11[4] = 1;
                puVar11[5] = 0;
                puVar11[6] = 0;
                puVar11[2] = puVar24;
                uVar26 = ((int (*)())FUN_00164e7c)(param_1,iVar7,piVar14,0,0,1);
                puVar11[4] = uVar26;
                puVar25 = *(uint **)(iVar17 + 0x40);
                uVar13 = puVar25[1];
                if (uVar13 < *puVar25) {
                  _memset(uVar13 * 4 + puVar25[2],0,4);
                  piVar4 = (int *)(uVar13 * 4 + puVar25[2]);
                  puVar25[1] = uVar13 + 1;
                }
                else {
                  piVar4 = (int *)FUN_0019423c(puVar25,uVar13);
                }
                *piVar4 = (int)(puVar11 + 1);
                puVar25 = (uint *)puVar15[0x12];
                uVar13 = puVar25[1];
                if (uVar13 < *puVar25) {
                  _memset(uVar13 * 4 + puVar25[2],0,4);
                  piVar4 = (int *)(uVar13 * 4 + puVar25[2]);
                  puVar25[1] = uVar13 + 1;
                }
                else {
                  piVar4 = (int *)FUN_0019423c(puVar25,uVar13);
                }
                *piVar4 = (int)(puVar11 + 1);
              }
            }
            puVar25 = (uint *)param_1[6];
            uVar13 = puVar25[1];
            if (uVar13 < *puVar25) {
              _memset(uVar13 * 4 + puVar25[2],0,4);
              piVar4 = (int *)(uVar13 * 4 + puVar25[2]);
              puVar25[1] = uVar13 + 1;
            }
            else {
              piVar4 = (int *)FUN_0019423c(puVar25,uVar13);
            }
            *piVar4 = (int)puVar24;
            uVar20 = uVar20 + 1;
            piVar5 = (int *)piVar14[2];
          }
          else {
            if (((((piVar14[0x20] == 0) || (iVar7 = FUN_00126760(piVar14[0x26]), iVar7 == 0)) ||
                 ((piVar14[5] & 2U) != 0)) ||
                ((iVar7 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar7 != 0 ||
                 ((piVar14[5] & 0x40U) != 0)))) ||
               (((piVar14[5] & 0x20U) == 0 && (iVar7 = FUN_000e07dc(*param_1,0x25), iVar7 != 0))))
            goto LAB_0016b038;
            iVar7 = *(int *)(*param_1 + 0x3c4) + 1;
            *(int *)(*param_1 + 0x3c4) = iVar7;
            piVar5 = (int *)piVar14[2];
            piVar14[0x25] = iVar7;
          }
        }
        else {
LAB_0016b038:
          piVar5 = (int *)piVar14[2];
        }
      }
      piVar4 = (int *)piVar5[2];
      piVar14 = piVar5;
    } while ((int *)piVar5[2] != (int *)0x0);
    if (bVar2) {
      uVar26 = *(undefined4 *)(*param_1 + 0x378);
      puVar11 = (undefined4 *)FUN_00193e18(uVar26,0x1c);
      puVar25 = puVar11 + 1;
      *puVar11 = uVar26;
      uVar19 = 1;
      puVar11[4] = FUN_00164bac;
      puVar11[1] = 1;
      puVar11[5] = FUN_00164bd8;
      iVar7 = 0x20;
      puVar11[6] = uVar26;
      do {
        uVar19 = uVar19 << 1;
        if (0xf < uVar19) break;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      *puVar25 = uVar19;
      puVar11[2] = 0;
      uVar26 = FUN_00193e18(uVar26,*puVar25 << 2);
      puVar11[3] = uVar26;
      _memset(uVar26,0,*puVar25 << 2);
      uVar20 = uVar20 - 1;
      if (-1 < (int)uVar20) {
        iVar7 = uVar20 * 4;
        local_54 = 0;
        iVar17 = 0;
        iVar16 = 0;
        local_58 = uVar20;
        do {
          puVar27 = (uint *)param_1[6];
          if (uVar20 < *puVar27) {
            uVar19 = puVar27[1];
            if (uVar19 <= uVar20) {
              _memset(uVar19 * 4 + puVar27[2],0,(uVar20 - uVar19) * 4 + 4);
              puVar27[1] = uVar20 + 1;
            }
            piVar4 = (int *)(iVar7 + puVar27[2]);
          }
          else {
            piVar4 = (int *)FUN_0019423c(puVar27,uVar20);
          }
          iVar22 = *piVar4;
          piVar4 = *(int **)(iVar22 + 0x38);
          iVar12 = ((int (*)())FUN_00164fc0)(piVar4);
          if (iVar12 != 0) {
            iVar12 = FUN_00194834(puVar25,piVar4);
            if (iVar12 != 0) {
              puVar27 = (uint *)param_1[6];
              uVar19 = *(uint *)(iVar12 + 0x150);
              if (uVar19 < *puVar27) {
                uVar13 = puVar27[1];
                if (uVar13 <= uVar19) {
                  _memset(uVar13 * 4 + puVar27[2],0,(uVar19 - uVar13) * 4 + 4);
                  puVar27[1] = uVar19 + 1;
                }
                piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              }
              else {
                piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
              }
              iVar23 = *piVar14;
              uVar26 = *(undefined4 *)(*param_1 + 0x378);
              puVar15 = (undefined4 *)FUN_00193e18(uVar26,0x24);
              *puVar15 = uVar26;
              puVar15[1] = iVar22;
              puVar15[7] = 0x1010101;
              puVar15[4] = 1;
              puVar15[5] = 0;
              puVar15[6] = 0;
              puVar15[8] = 0;
              puVar15[2] = iVar23;
              puVar15[3] = 1;
              uVar26 = ((int (*)())FUN_00164e7c)(param_1,piVar4,iVar12,0,0,1);
              puVar15[4] = uVar26;
              puVar27 = *(uint **)(iVar22 + 0x40);
              uVar19 = puVar27[1];
              if (uVar19 < *puVar27) {
                _memset(uVar19 * 4 + puVar27[2],0,4);
                piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                puVar27[1] = uVar19 + 1;
              }
              else {
                piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
              }
              *piVar14 = (int)(puVar15 + 1);
              puVar27 = *(uint **)(iVar23 + 0x44);
              uVar19 = puVar27[1];
              if (uVar19 < *puVar27) {
                _memset(uVar19 * 4 + puVar27[2],0,4);
                piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                puVar27[1] = uVar19 + 1;
              }
              else {
                piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
              }
              *piVar14 = (int)(puVar15 + 1);
              FUN_00194720(puVar25,iVar12);
            }
            FUN_00194d44(puVar25,piVar4);
          }
          iVar23 = (**(code **)(*(int *)param_1[3] + 0x28))((int *)param_1[3],piVar4);
          iVar12 = iVar17;
          if ((iVar23 != 0) && (iVar12 = iVar22, iVar17 != 0)) {
            uVar26 = *(undefined4 *)(*param_1 + 0x378);
            puVar15 = (undefined4 *)FUN_00193e18(uVar26,0x24);
            *puVar15 = uVar26;
            puVar15[7] = 0x1010101;
            puVar15[1] = iVar22;
            puVar15[4] = 1;
            puVar15[5] = 0;
            puVar15[6] = 0;
            puVar15[8] = 0;
            puVar15[2] = iVar17;
            puVar15[3] = 4;
            uVar26 = ((int (*)())FUN_00164e7c)(param_1,piVar4,*(undefined4 *)(iVar17 + 0x38),0,0,4);
            puVar15[4] = uVar26;
            puVar27 = *(uint **)(iVar22 + 0x40);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
            }
            *piVar14 = (int)(puVar15 + 1);
            puVar27 = *(uint **)(iVar17 + 0x44);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
            }
            *piVar14 = (int)(puVar15 + 1);
          }
          iVar17 = (**(code **)(*(int *)param_1[3] + 0x2c))((int *)param_1[3],piVar4);
          iVar23 = iVar16;
          if ((iVar17 != 0) && (iVar23 = iVar22, iVar16 != 0)) {
            uVar26 = *(undefined4 *)(*param_1 + 0x378);
            puVar15 = (undefined4 *)FUN_00193e18(uVar26,0x24);
            *puVar15 = uVar26;
            puVar15[7] = 0x1010101;
            puVar15[1] = iVar22;
            puVar15[4] = 1;
            puVar15[5] = 0;
            puVar15[6] = 0;
            puVar15[8] = 0;
            puVar15[2] = iVar16;
            puVar15[3] = 4;
            uVar26 = ((int (*)())FUN_00164e7c)(param_1,piVar4,*(undefined4 *)(iVar16 + 0x38),0,0,4);
            puVar15[4] = uVar26;
            puVar27 = *(uint **)(iVar22 + 0x40);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
            }
            *piVar14 = (int)(puVar15 + 1);
            puVar27 = *(uint **)(iVar16 + 0x44);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
            }
            *piVar14 = (int)(puVar15 + 1);
          }
          if (0 < piVar4[0x21]) {
            iVar17 = 1;
            do {
              uVar26 = FUN_00105594(piVar4,iVar17);
              iVar16 = ((int (*)())FUN_00164fc0)(uVar26);
              if (iVar16 != 0) {
                uVar26 = FUN_00105594(piVar4,iVar17);
                piVar14 = (int *)FUN_00194834(puVar25,uVar26);
                if ((piVar14 != (int *)0x0) && (piVar4 != piVar14)) {
                  puVar27 = (uint *)param_1[6];
                  uVar19 = piVar14[0x54];
                  if (uVar19 < *puVar27) {
                    uVar13 = puVar27[1];
                    if (uVar13 <= uVar19) {
                      _memset(uVar13 * 4 + puVar27[2],0,(uVar19 - uVar13) * 4 + 4);
                      puVar27[1] = uVar19 + 1;
                    }
                    piVar5 = (int *)(uVar19 * 4 + puVar27[2]);
                  }
                  else {
                    piVar5 = (int *)FUN_0019423c(puVar27,uVar19);
                  }
                  iVar16 = *piVar5;
                  uVar26 = *(undefined4 *)(*param_1 + 0x378);
                  puVar15 = (undefined4 *)FUN_00193e18(uVar26,0x24);
                  *puVar15 = uVar26;
                  puVar15[7] = 0x1010101;
                  puVar15[1] = iVar22;
                  puVar15[3] = 2;
                  puVar15[4] = 1;
                  puVar15[5] = 0;
                  puVar15[6] = 0;
                  puVar15[8] = 0;
                  puVar15[2] = iVar16;
                  uVar26 = ((int (*)())FUN_00164e7c)(param_1,piVar4,piVar14,iVar17,0,2);
                  puVar15[4] = uVar26;
                  puVar27 = *(uint **)(iVar22 + 0x40);
                  uVar19 = puVar27[1];
                  if (uVar19 < *puVar27) {
                    _memset(uVar19 * 4 + puVar27[2],0,4);
                    piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                    puVar27[1] = uVar19 + 1;
                  }
                  else {
                    piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
                  }
                  *piVar14 = (int)(puVar15 + 1);
                  puVar27 = *(uint **)(iVar16 + 0x44);
                  uVar19 = puVar27[1];
                  if (uVar19 < *puVar27) {
                    _memset(uVar19 * 4 + puVar27[2],0,4);
                    piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                    puVar27[1] = uVar19 + 1;
                  }
                  else {
                    piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
                  }
                  *piVar14 = (int)(puVar15 + 1);
                }
              }
              iVar17 = iVar17 + 1;
            } while (iVar17 <= piVar4[0x21]);
          }
          iVar17 = (**(code **)(*piVar4 + 0x28))(piVar4);
          if ((iVar17 != 0) && (iVar23 != 0)) {
            uVar26 = *(undefined4 *)(*param_1 + 0x378);
            puVar15 = (undefined4 *)FUN_00193e18(uVar26,0x24);
            *puVar15 = uVar26;
            puVar15[7] = 0x1010101;
            puVar15[1] = iVar22;
            puVar15[4] = 1;
            puVar15[5] = 0;
            puVar15[6] = 0;
            puVar15[8] = 0;
            puVar15[2] = iVar23;
            puVar15[3] = 4;
            uVar26 = ((int (*)())FUN_00164e7c)(param_1,piVar4,*(undefined4 *)(iVar23 + 0x38),0,0,4);
            puVar15[4] = uVar26;
            puVar27 = *(uint **)(iVar22 + 0x40);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
            }
            *piVar14 = (int)(puVar15 + 1);
            puVar27 = *(uint **)(iVar23 + 0x44);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
            }
            *piVar14 = (int)(puVar15 + 1);
          }
          iVar17 = (**(code **)(*piVar4 + 0x24))(piVar4);
          if (((iVar17 != 0) && ((piVar4[5] & 2U) == 0)) && (iVar12 != 0)) {
            uVar26 = *(undefined4 *)(*param_1 + 0x378);
            puVar15 = (undefined4 *)FUN_00193e18(uVar26,0x24);
            *puVar15 = uVar26;
            puVar15[7] = 0x1010101;
            puVar15[1] = iVar22;
            puVar15[8] = 0;
            puVar15[4] = 1;
            puVar15[5] = 0;
            puVar15[6] = 0;
            puVar15[2] = iVar12;
            puVar15[3] = 4;
            uVar26 = ((int (*)())FUN_00164e7c)(param_1,piVar4,*(undefined4 *)(iVar12 + 0x38),0,0,4);
            puVar15[4] = uVar26;
            puVar27 = *(uint **)(iVar22 + 0x40);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
            }
            *piVar14 = (int)(puVar15 + 1);
            puVar27 = *(uint **)(iVar12 + 0x44);
            uVar19 = puVar27[1];
            if (uVar19 < *puVar27) {
              _memset(uVar19 * 4 + puVar27[2],0,4);
              piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
              puVar27[1] = uVar19 + 1;
            }
            else {
              piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
            }
            *piVar14 = (int)(puVar15 + 1);
          }
          iVar17 = (**(code **)(*(int *)param_1[3] + 0x20))((int *)param_1[3],piVar4);
          if ((iVar17 != 0) && (iVar17 = FUN_00193f08(auStack_78), iVar17 == 0)) {
            iVar16 = *(int *)(local_70 + 8);
            iVar17 = local_70;
            while (iVar16 != 0) {
              uVar26 = *(undefined4 *)(*param_1 + 0x378);
              puVar15 = (undefined4 *)FUN_00193e18(uVar26,0x24);
              *puVar15 = uVar26;
              puVar15[7] = 0x1010101;
              puVar15[1] = iVar22;
              puVar15[4] = 1;
              puVar15[5] = 0;
              puVar15[6] = 0;
              puVar15[8] = 0;
              puVar15[2] = iVar17;
              puVar15[3] = 4;
              uVar26 = ((int (*)())FUN_00164e7c)(param_1,piVar4,*(undefined4 *)(iVar17 + 0x38),0,0,4);
              puVar15[4] = uVar26;
              puVar27 = *(uint **)(iVar22 + 0x40);
              uVar19 = puVar27[1];
              if (uVar19 < *puVar27) {
                _memset(uVar19 * 4 + puVar27[2],0,4);
                piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                puVar27[1] = uVar19 + 1;
              }
              else {
                piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
              }
              *piVar14 = (int)(puVar15 + 1);
              puVar27 = *(uint **)(iVar17 + 0x44);
              uVar19 = puVar27[1];
              if (uVar19 < *puVar27) {
                _memset(uVar19 * 4 + puVar27[2],0,4);
                piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                puVar27[1] = uVar19 + 1;
              }
              else {
                piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
              }
              *piVar14 = (int)(puVar15 + 1);
              iVar17 = *(int *)(iVar17 + 8);
              iVar16 = *(int *)(iVar17 + 8);
            }
          }
          if (((*(int *)(param_1[1] + 0x33c) != 0) &&
              (*(int *)(*(int *)(*param_1 + 0x30c) + 0x20) <
               *(int *)(*(int *)(param_1[1] + 0x33c) + 300))) &&
             (iVar17 = (**(code **)(*(int *)param_1[2] + 0x28))((int *)param_1[2],piVar4),
             iVar17 != 0)) {
            iVar16 = *(int *)(local_70 + 8);
            iVar17 = local_70;
            while (iVar18 = iVar16, iVar18 != 0) {
              if (*(int *)(iVar17 + 0x38) == *(int *)(param_1[1] + 0x33c)) {
                uVar26 = *(undefined4 *)(*param_1 + 0x378);
                puVar15 = (undefined4 *)FUN_00193e18(uVar26,0x24);
                *puVar15 = uVar26;
                puVar15[7] = 0x1010101;
                puVar15[1] = iVar22;
                puVar15[3] = 2;
                puVar15[4] = 1;
                puVar15[5] = 0;
                puVar15[6] = 0;
                puVar15[8] = 0;
                puVar15[2] = iVar17;
                uVar26 = ((int (*)())FUN_00164e7c)(param_1,piVar4,*(undefined4 *)(iVar17 + 0x38),0,0,2);
                puVar15[4] = uVar26;
                puVar27 = *(uint **)(iVar22 + 0x40);
                uVar19 = puVar27[1];
                if (uVar19 < *puVar27) {
                  _memset(uVar19 * 4 + puVar27[2],0,4);
                  piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                  puVar27[1] = uVar19 + 1;
                }
                else {
                  piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
                }
                *piVar14 = (int)(puVar15 + 1);
                puVar27 = *(uint **)(iVar17 + 0x44);
                uVar19 = puVar27[1];
                if (uVar19 < *puVar27) {
                  _memset(uVar19 * 4 + puVar27[2],0,4);
                  piVar14 = (int *)(uVar19 * 4 + puVar27[2]);
                  puVar27[1] = uVar19 + 1;
                }
                else {
                  piVar14 = (int *)FUN_0019423c(puVar27,uVar19);
                }
                *piVar14 = (int)(puVar15 + 1);
                iVar18 = *(int *)(iVar17 + 8);
              }
              iVar17 = iVar18;
              iVar16 = *(int *)(iVar18 + 8);
            }
          }
          uVar20 = uVar20 - 1;
          iVar7 = iVar7 + -4;
          local_54 = local_54 + 1;
          iVar17 = iVar12;
          iVar16 = iVar23;
        } while (local_54 != local_58 + 1);
      }
      if (puVar25 != (uint *)0x0) {
        uVar19 = *puVar25;
        if (uVar19 == 0) {
          iVar7 = puVar11[3];
        }
        else {
          iVar7 = puVar11[3];
          uVar20 = 0;
          do {
            iVar17 = *(int *)(uVar20 * 4 + iVar7);
            if (iVar17 != 0) {
              FUN_00193cc0(puVar11[6],iVar17);
              uVar19 = *puVar25;
              iVar7 = puVar11[3];
            }
            uVar20 = uVar20 + 1;
          } while (uVar20 < uVar19);
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
          _memset(uVar3 * 4 + puVar17[2],0,(uVar14 - uVar3) * 4 + 4);
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
          _memset(iVar5 + local_60,0,4);
          local_64 = uVar3 + 1;
          piVar4 = (int *)(iVar5 + local_60);
        }
        else {
          piVar4 = (int *)FUN_0019423c(&local_68,local_64);
        }
        *piVar4 = iVar13;
        while (uVar3 = DAT_001b01a8, local_64 != 0) {
          uVar3 = local_64 - 1;
          piVar4 = (int *)0x0;
          if (uVar3 < local_64) {
            piVar4 = (int *)(uVar3 * 4 + local_60);
          }
          iVar5 = *piVar4;
          FUN_00194208(&local_68,uVar3);
          puVar17 = *(uint **)(iVar5 + 0x40);
          uVar15 = 0;
          uVar3 = puVar17[1];
          if (0 < (int)uVar3) {
            while( true ) {
              if (uVar15 < *puVar17) {
                uVar7 = puVar17[1];
                if (uVar7 <= uVar15) {
                  _memset(uVar7 * 4 + puVar17[2],0,(uVar15 - uVar7) * 4 + 4);
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
                        _memset(uVar8 * 4 + puVar17[2],0,(uVar19 - uVar8) * 4 + 4);
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
                        _memset(iVar1 + local_60,0,4);
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
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  piVar8 = (int *)param_1[0xc];
  iVar4 = *piVar8;
  if (iVar4 == 0) {
    iVar4 = piVar8[1];
    if (iVar4 == 0) goto LAB_0016c27c;
  }
  else if (piVar8[1] != 0) goto LAB_0016c27c;
  if (((*(int *)(iVar4 + 100) == 0) && (*(int *)(iVar4 + 0x60) == 0)) &&
     (*(int *)(*(int *)(iVar4 + 0x38) + 0x98) == 1)) {
    *(undefined4 *)(*(int *)(iVar4 + 0x38) + 0x98) = 0;
    piVar8 = (int *)param_1[0xc];
  }
LAB_0016c27c:
  iVar4 = 0;
  while( true ) {
    iVar12 = piVar8[iVar4];
    if ((((iVar12 != 0) && (piVar8 = *(int **)(iVar12 + 0x38), piVar8[0x20] != 0)) &&
        ((iVar5 = FUN_00126760(piVar8[0x26]), iVar5 != 0 &&
         (((piVar8[5] & 2U) == 0 && (iVar5 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar5 == 0))))))
       && ((piVar8[5] & 0x40U) != 0)) {
      iVar5 = piVar8[0x25];
      iVar10 = 0;
      piVar9 = param_1;
      do {
        iVar6 = FUN_001054ec(piVar8,0);
        if (*(char *)(iVar10 + iVar6 + 0x10) != '\x01') {
          *(int *)(piVar9[0x4d] + iVar5 * 4) = iVar12;
        }
        bVar2 = iVar10 != 3;
        piVar9 = piVar9 + 1;
        iVar10 = iVar10 + 1;
      } while (bVar2);
    }
    if (4 < iVar4 + 1) break;
    piVar8 = (int *)param_1[0xc];
    iVar4 = iVar4 + 1;
  }
  iVar4 = param_1[0xc];
  iVar12 = 0;
  do {
    iVar5 = iVar12 * 4;
    iVar12 = iVar12 + 1;
    iVar4 = *(int *)(iVar5 + iVar4);
    if (iVar4 != 0) {
      piVar8 = *(int **)(iVar4 + 0x38);
      iVar5 = FUN_000e07dc(*param_1,0x25);
      if (iVar5 == 0) {
LAB_0016c3e0:
        iVar5 = piVar8[0x20];
      }
      else {
        iVar5 = 0;
        if (piVar8[0x20] != 0) {
          iVar5 = FUN_00126760(piVar8[0x26]);
          if ((((iVar5 != 0) && ((piVar8[5] & 2U) == 0)) &&
              (iVar5 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar5 == 0)) &&
             (((piVar8[5] & 0x40U) == 0 && ((piVar8[5] & 0x20U) == 0)))) {
            if ((*(int *)(iVar4 + 0x60) == 0) ||
               (iVar5 = *(int *)(*(int *)(iVar4 + 0x60) + 4), iVar5 < 0)) {
              iVar10 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x7c))
                                 (*(int **)(*param_1 + 0x30c),piVar8);
              iVar5 = DAT_001b0194;
              if (iVar10 != 0) {
                if (*(int **)(iVar4 + 0x60) == (int *)0x0) {
                  iVar5 = piVar8[3];
                }
                else {
                  iVar5 = **(int **)(iVar4 + 0x60);
                }
              }
              iVar5 = ((int (*)())FUN_00167b68)(param_1,piVar8[0x26],iVar5);
              if (iVar5 < 0) {
                iVar5 = param_1[0x52];
                iVar10 = param_1[0x53];
                param_1[0x52] = iVar5 + 1;
                if (iVar10 < iVar5 + 1) {
                  piVar9 = param_1;
                  do {
                    iVar11 = piVar9[0x4d];
                    iVar6 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),iVar10 << 3);
                    iVar7 = param_1[0x53];
                    piVar9[0x4d] = iVar6;
                    piVar9 = piVar9 + 1;
                    _memcpy(iVar6,iVar11,iVar7 << 2);
                    FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),iVar11);
                  } while (piVar9 != param_1 + 4);
                  param_1[0x53] = iVar10 << 1;
                }
                iVar10 = iVar5 * 4;
                iVar6 = 4;
                piVar9 = param_1;
                do {
                  piVar1 = piVar9 + 0x4d;
                  piVar9 = piVar9 + 1;
                  *(undefined4 *)(iVar10 + *piVar1) = 0;
                  iVar6 = iVar6 + -1;
                } while (iVar6 != 0);
              }
              else {
                iVar10 = iVar5 << 2;
              }
              iVar6 = 0;
              piVar9 = param_1;
              do {
                iVar7 = FUN_001054ec(piVar8,0);
                if (*(char *)(iVar6 + iVar7 + 0x10) != '\x01') {
                  *(int *)(piVar9[0x4d] + iVar10) = iVar4;
                }
                bVar2 = iVar6 != 3;
                piVar9 = piVar9 + 1;
                iVar6 = iVar6 + 1;
              } while (bVar2);
              if (*(int *)(iVar4 + 0x60) != 0) {
                *(int *)(*(int *)(iVar4 + 0x60) + 4) = iVar5;
              }
            }
            else {
              iVar10 = 0;
              piVar9 = param_1;
              do {
                iVar6 = FUN_001054ec(piVar8,0);
                if (*(char *)(iVar10 + iVar6 + 0x10) != '\x01') {
                  *(int *)(piVar9[0x4d] + iVar5 * 4) = iVar4;
                }
                bVar2 = iVar10 != 3;
                piVar9 = piVar9 + 1;
                iVar10 = iVar10 + 1;
              } while (bVar2);
            }
            piVar8[0x25] = iVar5;
            piVar8[5] = piVar8[5] | 0x40;
            goto LAB_0016c620;
          }
          goto LAB_0016c3e0;
        }
      }
      if (((iVar5 != 0) && (iVar4 = FUN_00126760(piVar8[0x26]), iVar4 != 0)) &&
         (((piVar8[5] & 2U) == 0 && (iVar4 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar4 == 0)))) {
        uVar3 = piVar8[5];
        if ((uVar3 & 0x20) == 0) {
          iVar4 = FUN_000e07dc(*param_1,0x25);
          if (iVar4 != 0) goto LAB_0016c620;
          uVar3 = piVar8[5];
        }
        if ((uVar3 & 0x40) == 0) {
          iVar4 = *(int *)(*param_1 + 0x3c4) + 1;
          *(int *)(*param_1 + 0x3c4) = iVar4;
          piVar8[0x25] = iVar4;
        }
      }
    }
LAB_0016c620:
    if (4 < iVar12) {
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
  ((int (*)())FUN_0016c1fc)(param_1);
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
              _memset(uVar2 * 4 + puVar11[2],0,(uVar9 - uVar2) * 4 + 4);
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
              (iVar4 = (**(code **)(**(int **)(*piVar12 + 0x38) + 0x5c))(*(int **)(*piVar12 + 0x38))
              , iVar4 != 0)) && (*(int *)(*(int *)(*piVar12 + 0x38) + 0x158) == 0)) {
            FUN_000e7738(param_1[4],iVar5,*(int *)(*piVar12 + 0x38));
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
              _memset(uVar2 * 4 + puVar11[2],0,(uVar9 - uVar2) * 4 + 4);
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
              (iVar10 = (**(code **)(**(int **)(*piVar12 + 0x38) + 0x5c))
                                  (*(int **)(*piVar12 + 0x38)), iVar10 != 0)) &&
             (*(int *)(*(int *)(*piVar12 + 0x38) + 0x158) == 0)) {
            FUN_000e7738(param_1[4],iVar5,*(int *)(*piVar12 + 0x38));
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

