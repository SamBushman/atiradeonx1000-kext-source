#include "decls.h"

/* _lFloatConst @ 0x97b88c98 (588 bytes) */
int _lFloatConst(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined *puVar1;
  float fVar2;
  int iVar3;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 uVar4;
  int a3;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  double dVar11;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  iVar6 = 0;
  iVar7 = 0;
  a3 = param_4;
  iVar9 = param_2;
  iVar3 = param_3;
  if (param_3 == 0x2e) {
    *(undefined1 *)((int)param_1 + param_2) = 0x2e;
    iVar9 = param_2 + 1;
    iVar3 = *(int *)(*(int *)puVar1 + 0x20);
    iVar3 = (**(code **)(iVar3 + 8))(iVar3,param_4);
    uVar8 = iVar3 - 0x30;
    uVar4 = extraout_r4;
    while (uVar8 < 10) {
      if (iVar9 < 0x80) {
        iVar6 = iVar6 + 1;
        if ((0 < iVar9) || (iVar3 != 0x30)) {
          *(char *)((int)param_1 + iVar9) = (char)iVar3;
          param_2 = param_2 + 1;
          iVar9 = iVar9 + 1;
        }
        iVar3 = *(int *)(*(int *)puVar1 + 0x20);
        iVar3 = (**(code **)(iVar3 + 8))(iVar3,param_4);
        uVar8 = iVar3 - 0x30;
        uVar4 = extraout_r4_00;
      }
      else {
        iVar9 = 1;
        param_2 = 1;
        _CPPErrorToInfoLog("ERROR___FP_CONST_TOO_LONG",uVar4,param_3,a3,in_r7,in_r8,in_r9);
        uVar4 = extraout_r4_01;
      }
    }
  }
  puVar1 = PTR__cpp_a7b7c0a4;
  if ((iVar3 != 0x65) && (iVar3 != 0x45)) goto LAB_97b88e60;
  *(char *)((int)param_1 + iVar9) = (char)iVar3;
  iVar10 = iVar9 + 1;
  iVar5 = 1;
  iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 8))
                    (*(int *)(*(int *)puVar1 + 0x20),param_4);
  if (iVar3 == 0x2b) {
    *(undefined1 *)((int)param_1 + iVar10) = 0x2b;
    iVar3 = *(int *)puVar1;
LAB_97b88de8:
    iVar3 = (**(code **)(*(int *)(iVar3 + 0x20) + 8))(*(int *)(iVar3 + 0x20),param_4);
    uVar4 = extraout_r4_03;
    iVar10 = iVar9 + 2;
  }
  else {
    uVar4 = extraout_r4_02;
    if (iVar3 == 0x2d) {
      *(undefined1 *)((int)param_1 + iVar10) = 0x2d;
      iVar3 = *(int *)puVar1;
      iVar5 = -1;
      goto LAB_97b88de8;
    }
  }
  iVar9 = iVar10;
  puVar1 = PTR__cpp_a7b7c0a4;
  if (iVar3 - 0x30U < 10) {
    do {
      *(char *)((int)param_1 + iVar9) = (char)iVar3;
      iVar9 = iVar9 + 1;
      iVar10 = *(int *)(*(int *)puVar1 + 0x20);
      iVar7 = iVar7 * 10 + iVar3 + -0x30;
      iVar3 = (**(code **)(iVar10 + 8))(iVar10,param_4,param_3,a3,in_r7,in_r8,*(int *)puVar1);
    } while (iVar3 - 0x30U < 10);
  }
  else {
    _CPPErrorToInfoLog("ERROR___ERROR_IN_EXPONENT",uVar4,param_3,a3,in_r7,in_r8,in_r9);
  }
  iVar7 = iVar7 * iVar5;
LAB_97b88e60:
  if (iVar9 == 0) {
    *param_1 = 0x302e3000;
    fVar2 = 0.0;
  }
  else {
    *(undefined1 *)((int)param_1 + iVar9) = 0;
    dVar11 = (double)((double (*)())_lBuildFloatValue)(param_1,param_2,iVar7 - iVar6);
    fVar2 = (float)dVar11;
  }
  *(float *)(param_4 + 4) = fVar2;
  _strcpy(param_4 + 0xc,param_1);
  iVar6 = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
  (**(code **)(iVar6 + 0xc))(iVar6,iVar3,param_4,a3,in_r7,in_r8,*(int *)PTR__cpp_a7b7c0a4);
  return 0x10b;
}

/* _byte_scan @ 0x97b88ee4 (3060 bytes) */
int _byte_scan(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  uint *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int a1;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 uVar4;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  undefined4 extraout_r4_08;
  undefined4 extraout_r4_09;
  undefined4 extraout_r4_10;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  undefined1 local_2d0 [144];
  undefined1 local_240 [536];
  
  uVar7 = 0;
  iVar9 = *(int *)PTR__cpp_a7b7c0a4;
LAB_97b88f18:
  *param_2 = 0;
  iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
  while (((iVar3 == 0x20 || (iVar3 == 9)) || (iVar3 == 0xd))) {
    *param_2 = 1;
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
  }
  if (iVar3 != -1) {
    *(undefined2 *)(iVar9 + 0x30) = *(undefined2 *)(*(int *)(iVar9 + 0x20) + 0x12);
    *(undefined2 *)(iVar9 + 0x32) = *(undefined2 *)(*(int *)(iVar9 + 0x20) + 0x16);
  }
  iVar10 = 0;
  if (0x7d < iVar3 + 1U) {
LAB_97b89cb4:
    return iVar3;
  }
  uVar6 = (iVar3 + 1U) * 4;
  switch(iVar3) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x23:
  case 0x24:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2c:
  case 0x3b:
  case 0x3f:
  case 0x40:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x60:
  case 0x7b:
    goto LAB_97b89cb4;
  case 0x21:
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
      return 0x21;
    }
    return 0x113;
  case 0x22:
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    bVar1 = iVar3 == 0x22;
    uVar4 = extraout_r4_08;
    if (((bVar1) || (iVar3 == 10)) || (iVar3 == -1)) goto LAB_97b89c74;
    puVar8 = local_240;
    goto LAB_97b89bf4;
  case 0x25:
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if (iVar3 == 0x3d) {
      return 0x104;
    }
    if (iVar3 != 0x3e) {
      (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
      return 0x25;
    }
    return 0x120;
  case 0x26:
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if (iVar3 == 0x26) {
      return 0x101;
    }
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
      return 0x26;
    }
    return 0x11a;
  case 0x2a:
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
      return 0x2a;
    }
    return 0x107;
  case 0x2b:
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if (iVar3 == 0x2b) {
      return 0x115;
    }
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
      return 0x2b;
    }
    return 0x105;
  case 0x2d:
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if (iVar3 == 0x2d) {
      return 0x112;
    }
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
      return 0x2d;
    }
    return 0x103;
  case 0x2e:
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if (9 < iVar3 - 0x30U) {
      if (iVar3 != 0x2e) {
        (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
        return 0x2e;
      }
      return -1;
    }
    (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
    iVar10 = 0;
    a1 = 0x2e;
    goto LAB_97b89a54;
  case 0x2f:
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if (iVar3 != 0x2f) break;
    do {
      iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
      if (iVar3 == 10) {
        return 10;
      }
    } while (iVar3 != -1);
switchD_97b88fcc_caseD_ffffffff:
    return -1;
  case 0x30:
    *(char *)(param_2 + 3) = (char)iVar3;
    iVar10 = 1;
    a1 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if ((a1 == 0x78) || (a1 == 0x58)) {
      *(char *)((int)param_2 + 0xd) = (char)a1;
      iVar10 = 2;
      a1 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
      uVar6 = a1 - 0x30;
      if ((uVar6 < 10) || ((a1 - 0x41U < 6 || (a1 - 0x61U < 6)))) {
        puVar8 = (undefined1 *)((int)param_2 + 0xe);
        bVar1 = false;
        uVar7 = 0;
        uVar4 = extraout_r4_00;
        do {
          *puVar8 = (char)a1;
          iVar10 = iVar10 + 1;
          puVar8 = puVar8 + 1;
          if ((int)uVar7 < 0x10000000) {
            if ((9 < uVar6) && (uVar6 = a1 - 0x37, 5 < a1 - 0x41U)) {
              uVar6 = a1 - 0x57;
            }
            uVar7 = uVar7 << 4 | uVar6;
          }
          else {
            if (!bVar1) {
              _CPPErrorToInfoLog("ERROR___HEX_CONST_OVERFLOW",uVar4,param_3,param_4,param_5,param_6,
                                 uVar6);
            }
            bVar1 = true;
          }
          a1 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
          uVar6 = a1 - 0x30;
          uVar4 = extraout_r4_01;
        } while (((uVar6 < 10) || (a1 - 0x41U < 6)) || (a1 - 0x61U < 6));
      }
      else {
        _CPPErrorToInfoLog("ERROR___ERROR_IN_HEX_CONSTANT",extraout_r4_00,param_3,param_4,param_5,
                           param_6,uVar6);
      }
      goto LAB_97b89458;
    }
    uVar6 = a1 - 0x30;
    if (uVar6 < 8) {
      bVar1 = false;
      uVar7 = 0;
      puVar8 = (undefined1 *)((int)param_2 + 0xd);
      uVar4 = extraout_r4;
      do {
        *puVar8 = (char)a1;
        iVar10 = iVar10 + 1;
        puVar8 = puVar8 + 1;
        if ((int)uVar7 < 0x20000000) {
          uVar7 = uVar7 << 3 | uVar6;
        }
        else {
          if (!bVar1) {
            _CPPErrorToInfoLog("ERROR___OCT_CONST_OVERFLOW",uVar4,param_3,param_4,param_5,param_6,
                               uVar6);
          }
          bVar1 = true;
        }
        a1 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
        uVar6 = a1 - 0x30;
        uVar4 = extraout_r4_02;
      } while (uVar6 < 8);
      if ((((a1 == 0x2e) || (a1 == 0x65)) || ((a1 == 0x66 || ((a1 == 0x68 || (a1 == 0x78)))))) ||
         (a1 == 0x45)) goto LAB_97b89a54;
LAB_97b89458:
      *(undefined1 *)((int)param_2 + iVar10 + 0xc) = 0;
      (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),a1,param_2);
      *param_2 = uVar7;
      return 0x10f;
    }
    iVar3 = 0x30;
    (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),a1,param_2);
switchD_97b88fcc_caseD_31:
    puVar8 = (undefined1 *)((int)param_2 + iVar10 + 0xc);
    a1 = iVar3;
    do {
      if (iVar10 < 0x80) {
        if ((0 < iVar10) || (a1 != 0x30)) {
          *puVar8 = (char)a1;
          iVar10 = iVar10 + 1;
          puVar8 = puVar8 + 1;
        }
        a1 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
      }
    } while (a1 - 0x30U < 10);
    if (((((a1 != 0x2e) && (a1 != 0x65)) && (a1 != 0x66)) && ((a1 != 0x68 && (a1 != 0x78)))) &&
       (a1 != 0x45)) {
      *(undefined1 *)((int)param_2 + iVar10 + 0xc) = 0;
      uVar7 = 0;
      bVar1 = false;
      puVar5 = param_2;
      (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),a1,param_2,param_4);
      if (0 < iVar10) {
        puVar11 = param_2 + 3;
        uVar4 = extraout_r4_03;
        do {
          cVar2 = *(char *)puVar11;
          puVar11 = (uint *)((int)puVar11 + 1);
          if ((0xccccccc < (int)uVar7) || ((uVar7 == 0xccccccc && (7 < cVar2 + -0x30)))) {
            if (!bVar1) {
              _CPPErrorToInfoLog("ERROR___INTEGER_CONST_OVERFLOW",uVar4,puVar5,param_4,param_5,
                                 param_6,uVar6);
              uVar4 = extraout_r4_04;
            }
            bVar1 = true;
          }
          iVar10 = iVar10 + -1;
          uVar7 = uVar7 * 10 + cVar2 + -0x30;
        } while (iVar10 != 0);
      }
      *param_2 = uVar7;
      if (uVar7 == 0) {
        *(undefined2 *)(param_2 + 3) = 0x3000;
      }
      return 0x10f;
    }
LAB_97b89a54:
    iVar9 = ((int (*)())_lFloatConst)(param_2 + 3,iVar10,a1,param_2);
    return iVar9;
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    goto switchD_97b88fcc_caseD_31;
  case 0x3a:
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if (iVar3 != 0x3e) {
      (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
      return 0x3a;
    }
    return 0x11e;
  case 0x3c:
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if (iVar3 == 0x3c) {
      iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
      if (iVar3 != 0x3d) {
        (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
        return 0x111;
      }
      return 0x119;
    }
    if (iVar3 == 0x3d) {
      return 0x110;
    }
    if (iVar3 == 0x25) {
      return 0x11f;
    }
    if (iVar3 != 0x3a) {
      (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
      return 0x3c;
    }
    return 0x11d;
  case 0x3d:
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
      return 0x3d;
    }
    return 0x108;
  case 0x3e:
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if (iVar3 != 0x3e) {
      if (iVar3 != 0x3d) {
        (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
        return 0x3e;
      }
      return 0x10c;
    }
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
      return 0x10d;
    }
    return 0x118;
  default:
    bVar1 = false;
    do {
      if (!bVar1) {
        local_2d0[iVar10] = (char)iVar3;
        iVar10 = iVar10 + 1;
        bVar1 = 0x7f < iVar10;
      }
      iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))
                        (*(int *)(iVar9 + 0x20),param_2,param_3,param_4,param_5,param_6,uVar6);
    } while (((iVar3 - 0x61U < 0x1a) || (iVar3 - 0x41U < 0x1a)) ||
            ((iVar3 - 0x30U < 10 || (iVar3 == 0x5f))));
    if (bVar1) {
      iVar10 = 0x7f;
    }
    local_2d0[iVar10] = 0;
    (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
    uVar7 = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,local_2d0);
    param_2[2] = uVar7;
    return 0x10e;
  case 0x5e:
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if (iVar3 == 0x5e) {
      return 0x109;
    }
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
      return 0x5e;
    }
    return 0x11c;
  case 0x7c:
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    if (iVar3 == 0x7c) {
      return 0x114;
    }
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
      return 0x7c;
    }
    return 0x11b;
  case -1:
    goto switchD_97b88fcc_caseD_ffffffff;
  }
  if (iVar3 != 0x2a) {
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar9 + 0x20) + 0xc))(*(int *)(iVar9 + 0x20),iVar3,param_2);
      return 0x2f;
    }
    return 0x106;
  }
  iVar3 = 0;
  iVar10 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
  uVar4 = extraout_r4_05;
  do {
    while (iVar10 != 0x2a) {
      if (iVar10 == 10) {
        iVar3 = iVar3 + 1;
      }
      if (iVar10 == -1) {
LAB_97b89b60:
        _CPPErrorToInfoLog("ERROR___EOF_IN_COMMENT",uVar4,param_3,param_4,param_5,param_6,uVar6);
        return -1;
      }
      iVar10 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
      uVar4 = extraout_r4_06;
    }
    iVar10 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    uVar4 = extraout_r4_07;
    if (iVar10 == -1) goto LAB_97b89b60;
  } while (iVar10 != 0x2f);
  if (iVar3 != 0) {
    return 10;
  }
  goto LAB_97b88f18;
LAB_97b89bf4:
  if (iVar3 == 0x5c) {
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    bVar1 = iVar3 == 0x22;
    uVar4 = extraout_r4_09;
    if ((iVar3 == 10) || (iVar3 == -1)) {
LAB_97b89c74:
      local_240[iVar10] = 0;
      if (!bVar1) {
        _CPPErrorToInfoLog("ERROR___CPP_EOL_IN_STRING",uVar4,param_3,param_4,param_5,param_6,uVar6);
        return 0x10a;
      }
      uVar7 = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,local_240);
      param_2[2] = uVar7;
      return 0x116;
    }
  }
  if (iVar10 < 0x200) {
    *puVar8 = (char)iVar3;
    iVar10 = iVar10 + 1;
    puVar8 = puVar8 + 1;
    iVar3 = (**(code **)(*(int *)(iVar9 + 0x20) + 8))(*(int *)(iVar9 + 0x20),param_2);
    uVar4 = extraout_r4_10;
  }
  bVar1 = iVar3 == 0x22;
  if (((bVar1) || (iVar3 == 10)) || (iVar3 == -1)) goto LAB_97b89c74;
  goto LAB_97b89bf4;
}

/* _yylex_CPP @ 0x97b89cd0 (452 bytes) */
int _yylex_CPP(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 extraout_r4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 a6;
  undefined1 auStack_b0 [8];
  int local_a8;
  char acStack_a4 [136];
  
  puVar2 = PTR__atable_a7b7c0ac;
  puVar1 = PTR__cpp_a7b7c0a4;
  a6 = 0xa7b79cdc;
  do {
    do {
      while( true ) {
        while( true ) {
          iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                            (*(int *)(*(int *)puVar1 + 0x20),auStack_b0,in_r5,in_r6,in_r7,in_r8,a6);
          iVar4 = ((int (*)())_check_EOF)(iVar3);
          if (iVar4 != 0) {
            return 0;
          }
          if (iVar3 != 0x23) break;
          if ((*(int *)(*(int *)puVar1 + 0x24) != 10) && (*(int *)(*(int *)puVar1 + 0x24) != 0)) {
            _CPPErrorToInfoLog("preprocessor command must not be preceded by any other statement in that line"
                               ,extraout_r4,in_r5,in_r6,in_r7,in_r8,a6);
            return 0;
          }
          uVar5 = _readCPPline(auStack_b0);
          iVar3 = ((int (*)())_check_EOF)(uVar5);
          if (iVar3 != 0) {
            return 0;
          }
        }
        *(int *)(*(int *)puVar1 + 0x24) = iVar3;
        if ((iVar3 != 0x10e) || (iVar4 = _MacroExpand(local_a8,auStack_b0), iVar4 == 0)) break;
        *(undefined4 *)(*(int *)puVar1 + 0x28) = 1;
      }
    } while (iVar3 == 10);
    if (iVar3 != 0x10e) {
      if ((iVar3 != 0x10b) && (iVar3 != 0x10f)) {
        *(undefined4 *)(*(int *)puVar1 + 0x28) = 1;
        uVar5 = *(undefined4 *)puVar2;
        goto LAB_97b89e08;
      }
      pcVar6 = acStack_a4;
      *(undefined4 *)(*(int *)puVar1 + 0x28) = 1;
    }
    else {
      *(undefined4 *)(*(int *)puVar1 + 0x28) = 1;
      uVar5 = *(undefined4 *)puVar2;
      iVar3 = local_a8;
LAB_97b89e08:
      pcVar6 = (char *)_GetStringOfAtom(uVar5,iVar3);
    }
    if (pcVar6 != (char *)0x0) {
      iVar3 = _strlen(pcVar6);
      if (iVar3 < param_2) {
        param_2 = 0;
        if (*pcVar6 != '\0') {
          _strcpy(param_1,pcVar6);
          *(uint *)(*(int *)puVar1 + 0x154) = *(uint *)(*(int *)puVar1 + 0x154) | 0x80000000;
          param_2 = _strlen(pcVar6);
        }
      }
      else {
        *(uint *)(*(int *)puVar1 + 0x154) = *(uint *)(*(int *)puVar1 + 0x154) | 0x80000000;
      }
      return param_2;
    }
  } while( true );
}

/* _check_EOF @ 0x97b89e94 (108 bytes) */
int _check_EOF(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 in_r4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  uVar2 = 0;
  if (param_1 == -1) {
    if (0 < *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x34)) {
      _CPPErrorToInfoLog("#endif missing!! Compilation stopped",in_r4,in_r5,in_r6,in_r7,in_r8,in_r9)
      ;
      *(undefined4 *)(*(int *)puVar1 + 0x140) = 1;
    }
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_97b89f04 @ 0x97b89f04 (72 bytes) */
int FUN_97b89f04(param_1)
  undefined4 *param_1;
{
  int unaff_r2 = (int)*param_1;   /* set by the entry _unlinkScope: lwz r2,0(r3) */
  
  if (unaff_r2 != 0) {
    *(undefined4 *)(unaff_r2 + 4) = param_1[1];
  }
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    *(undefined4 *)param_1[1] = *param_1;
    return;
  }
  _ScopeList = *param_1;
  return;
}

/* _NewScopeInPool @ 0x97b89f4c (152 bytes) */
int _NewScopeInPool(param_1)
  int param_1;
{
  bool bVar1;
  int *piVar2;
  
  piVar2 = (int *)_mem_Alloc(param_1,0x20);
  piVar2[4] = param_1;
  piVar2[2] = 0;
  piVar2[3] = 0;
  piVar2[5] = 0;
  piVar2[6] = 0;
  piVar2[7] = 0;
  bVar1 = _ScopeList != (int *)0x0;
  *piVar2 = (int)_ScopeList;
  if (bVar1) {
    *(int **)((int)_ScopeList + 4) = piVar2;
  }
  piVar2[1] = 0;
  _ScopeList = piVar2;
  _mem_AddCleanup(param_1,DAT_a7b7b048,piVar2);
  return piVar2;
}

/* _PushScope @ 0x97b89fe4 (148 bytes) */
int _PushScope(param_1)
  int *param_1;
{
  int *piVar1;
  int iVar2;
  
  if (_CurrentScope == (int *)0x0) {
    param_1[6] = 0;
  }
  else {
    iVar2 = *(int *)((int)_CurrentScope + 0x18) + 1;
    param_1[6] = iVar2;
    if ((iVar2 == 1) && (_GlobalScope == 0)) {
      param_1[6] = 2;
    }
    iVar2 = param_1[6];
    piVar1 = param_1;
    if (1 < iVar2) {
      while (2 < iVar2) {
        iVar2 = ((int *)*piVar1)[6];
        piVar1 = (int *)*piVar1;
      }
      param_1[3] = (int)piVar1;
    }
  }
  param_1[2] = (int)_CurrentScope;
  _CurrentScope = param_1;
  return;
}

/* _PopScope @ 0x97b8a078 (48 bytes) */
int _PopScope()
{
  if (_CurrentScope == 0) {
    return;
  }
  _CurrentScope = *(undefined4 *)(_CurrentScope + 8);
  return;
}

/* _NewSymbol @ 0x97b8a0a8 (116 bytes) */
int _NewSymbol(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = (undefined4 *)_mem_Alloc(*(undefined4 *)(param_2 + 0x10),0x28);
  puVar3[2] = 0;
  puVar3[3] = param_3;
  iVar4 = 0x10;
  *puVar3 = 0;
  puVar3[1] = 0;
  uVar1 = *param_1;
  puVar3[5] = param_4;
  puVar3[4] = uVar1;
  puVar2 = puVar3 + 6;
  do {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return puVar3;
}

/* _lAddToTree @ 0x97b8a11c (188 bytes) */
int _lAddToTree(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  int *piVar5;
  undefined8 uVar6;
  
  puVar1 = PTR__atable_a7b7c0ac;
  piVar5 = (int *)*param_1;
  if (piVar5 == (int *)0x0) {
    *param_1 = param_2;
  }
  else {
    iVar3 = _GetReversedAtom(*(undefined4 *)PTR__atable_a7b7c0ac,*(undefined4 *)(param_2 + 0xc));
    do {
      uVar6 = _GetReversedAtom(*(undefined4 *)puVar1,piVar5[3]);
      iVar4 = (int)((ulonglong)uVar6 >> 0x20);
      if (iVar4 == iVar3) {
        _CPPErrorToInfoLog("GetAtomString(atable, fSymb->name)",(int)uVar6,in_r5,in_r6,in_r7,in_r8,
                           in_r9);
        return;
      }
      if (iVar3 < iVar4) {
        piVar2 = (int *)*piVar5;
        if (piVar2 == (int *)0x0) {
          *piVar5 = param_2;
          return;
        }
      }
      else {
        piVar2 = (int *)piVar5[1];
        if (piVar2 == (int *)0x0) {
          piVar5[1] = param_2;
          return;
        }
      }
      piVar5 = piVar2;
    } while (piVar2 != (int *)0x0);
  }
  return;
}

/* _AddSymbol @ 0x97b8a1d8 (88 bytes) */
int _AddSymbol(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    param_2 = _CurrentScope;
  }
  uVar1 = ((int (*)())_NewSymbol)(param_1,param_2,param_3,param_4);
  ((int (*)())_lAddToTree)(param_2 + 0x14,uVar1);
  return uVar1;
}

/* _LookUpLocalSymbol @ 0x97b8a230 (148 bytes) */
int _LookUpLocalSymbol(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  puVar1 = PTR__atable_a7b7c0ac;
  iVar2 = _GetReversedAtom(*(undefined4 *)PTR__atable_a7b7c0ac,param_2);
  if (param_1 == 0) {
    param_1 = _CurrentScope;
  }
  piVar4 = *(int **)(param_1 + 0x14);
  while( true ) {
    if (piVar4 == (int *)0x0) {
      return 0;
    }
    iVar3 = _GetReversedAtom(*(undefined4 *)puVar1,piVar4[3]);
    if (iVar3 == iVar2) break;
    if (iVar2 < iVar3) {
      piVar4 = (int *)*piVar4;
    }
    else {
      piVar4 = (int *)piVar4[1];
    }
  }
  return (int)piVar4;
}

/* _LookUpSymbol @ 0x97b8a2c4 (108 bytes) */
int _LookUpSymbol(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = _CurrentScope;
  if (param_1 != 0) goto LAB_97b8a2f8;
  while( true ) {
    param_1 = iVar1;
    if (param_1 == 0) {
      return 0;
    }
LAB_97b8a2f8:
    iVar1 = ((int (*)())_LookUpLocalSymbol)(param_1,param_2);
    if (iVar1 != 0) break;
    iVar1 = *(int *)(param_1 + 8);
  }
  return iVar1;
}

/* _idstr @ 0x97b8a330 (248 bytes) */
int _idstr(param_1, param_2)
  byte *param_1;
  int param_2;
{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  
  iVar3 = _strlen(param_1);
  if (param_2 == 0) {
    pbVar4 = (byte *)_malloc(iVar3 + 1);
  }
  else {
    pbVar4 = (byte *)_mem_Alloc(param_2,iVar3 + 1);
  }
  puVar2 = PTR_DAT_a7b7c0a8;
  bVar1 = *param_1;
  pbVar6 = pbVar4;
  do {
    if (bVar1 == 0) {
      *pbVar6 = 0;
      return pbVar4;
    }
    uVar5 = (uint)(char)bVar1;
    if ((uVar5 & 0xffffff80) == 0) {
      uVar5 = -(uint)(*(uint *)(puVar2 + uVar5 * 4 + 0x34) & 0x500) >> 0x1f;
    }
    else {
      iVar3 = ___maskrune(uVar5,0x500);
      uVar5 = (uint)(iVar3 != 0);
    }
    if (uVar5 == 0) {
      if (*param_1 - 0x2e < 2) {
        *pbVar6 = 0x5f;
        goto LAB_97b8a3f8;
      }
    }
    else {
      *pbVar6 = *param_1;
LAB_97b8a3f8:
      pbVar6 = pbVar6 + 1;
    }
    param_1 = param_1 + 1;
    bVar1 = *param_1;
  } while( true );
}

/* _lNewBlock @ 0x97b8a428 (136 bytes) */
int _lNewBlock(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 *puVar1;
  
  if (param_2 == 0) {
    puVar1 = (undefined4 *)_malloc(0x114);
  }
  else {
    puVar1 = (undefined4 *)_mem_Alloc(param_2,0x114);
  }
  puVar1[4] = puVar1 + 5;
  puVar1[3] = 0x100;
  *puVar1 = 0;
  puVar1[2] = 0;
  puVar1[1] = 0;
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 **)(param_1 + 8) = puVar1;
  }
  else {
    **(undefined4 **)(param_1 + 0xc) = puVar1;
  }
  *(undefined4 **)(param_1 + 0xc) = puVar1;
  return puVar1;
}

/* _lAddByte @ 0x97b8a4b0 (92 bytes) */
int _lAddByte(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  iVar1 = *(int *)(iVar2 + 8);
  if (*(int *)(iVar2 + 0xc) <= iVar1) {
    iVar2 = ((int (*)())_lNewBlock)(param_1,0);
    iVar1 = *(int *)(iVar2 + 8);
  }
  *(undefined1 *)(*(int *)(iVar2 + 0x10) + iVar1) = (undefined1)param_2;
  *(int *)(iVar2 + 8) = iVar1 + 1;
  return;
}

/* _lReadByte @ 0x97b8a50c (88 bytes) */
int _lReadByte(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0xc);
  uVar2 = 0xffffffff;
  bVar1 = piVar3 == (int *)0x0;
  if (!bVar1) {
    if (piVar3[2] <= piVar3[1]) {
      piVar3 = (int *)*piVar3;
      bVar1 = piVar3 == (int *)0x0;
      if (!bVar1) {
        piVar3[1] = 0;
      }
      *(int **)(param_1 + 0xc) = piVar3;
    }
    if (!bVar1) {
      uVar2 = (uint)*(byte *)(piVar3[4] + piVar3[1]);
      piVar3[1] = piVar3[1] + 1;
    }
  }
  return uVar2;
}

/* _NewTokenStream @ 0x97b8a564 (124 bytes) */
int _NewTokenStream(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    puVar1 = (undefined4 *)_malloc(0x10);
  }
  else {
    puVar1 = (undefined4 *)_mem_Alloc(param_2,0x10);
  }
  *puVar1 = 0;
  uVar2 = ((int (*)())_idstr)(param_1,param_2);
  puVar1[3] = 0;
  puVar1[1] = uVar2;
  puVar1[2] = 0;
  ((int (*)())_lNewBlock)(puVar1,param_2);
  return puVar1;
}

/* _DeleteTokenStream @ 0x97b8a5e0 (116 bytes) */
int _DeleteTokenStream(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return;
  }
  piVar1 = (int *)*(int *)(param_1 + 8);
  while (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    _free(piVar1);
    piVar1 = (int *)iVar2;
  }
  if (*(int *)(param_1 + 4) != 0) {
    _free(*(int *)(param_1 + 4));
  }
  _free(param_1);
  return;
}

/* _RecordToken @ 0x97b8a654 (292 bytes) */
int _RecordToken(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int *param_3;
{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  
  if ((int)param_2 < 0x101) {
    uVar2 = param_2 & 0x7f;
  }
  else {
    uVar2 = (param_2 & 0x7f) - 0x80 & 0xff;
  }
  ((int (*)())_lAddByte)(param_1,uVar2);
  if (param_2 == 0x10e) {
LAB_97b8a6cc:
    pbVar3 = (byte *)_GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,param_3[2]);
    bVar1 = *pbVar3;
    while (bVar1 != 0) {
      ((int (*)())_lAddByte)(param_1,(uint)bVar1);
      pbVar3 = pbVar3 + 1;
      bVar1 = *pbVar3;
    }
  }
  else {
    if ((int)param_2 < 0x10f) {
      if (param_2 == 0x28) {
        ((int (*)())_lAddByte)(param_1,(uint)(*param_3 != 0));
        return;
      }
      if (param_2 != 0x10b) {
        return;
      }
    }
    else if (param_2 != 0x10f) {
      if (1 < param_2 - 0x116) {
        return;
      }
      goto LAB_97b8a6cc;
    }
    pbVar3 = (byte *)(param_3 + 3);
    bVar1 = *(byte *)(param_3 + 3);
    while (bVar1 != 0) {
      ((int (*)())_lAddByte)(param_1,(uint)bVar1);
      pbVar3 = pbVar3 + 1;
      bVar1 = *pbVar3;
    }
  }
  ((int (*)())_lAddByte)(param_1,0);
  return;
}

/* _RewindTokenStream @ 0x97b8a778 (28 bytes) */
int _RewindTokenStream(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    return;
  }
  *(int *)(param_1 + 0xc) = iVar1;
  *(undefined4 *)(iVar1 + 4) = 0;
  return;
}

/* _ReadToken @ 0x97b8a794 (888 bytes) */
int _ReadToken(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  double dVar7;
  undefined1 local_2c0 [144];
  char local_230 [532];
  
  iVar2 = ((int (*)())_lReadByte)(param_1);
  if (iVar2 < 0) {
    return -1;
  }
  if (0x7f < iVar2) {
    iVar2 = iVar2 + 0x80;
  }
  if (iVar2 == 0x10e) {
LAB_97b8a810:
    iVar6 = 0;
    uVar3 = ((int (*)())_lReadByte)(param_1);
    iVar4 = (int)(char)uVar3;
    uVar1 = iVar4 - 0x61;
    while (((((uVar1 & 0xff) < 0x1a || (iVar4 - 0x41U < 0x1a)) || (iVar4 - 0x30U < 10)) ||
           (iVar4 == 0x5f))) {
      if (iVar6 < 0x80) {
        local_2c0[iVar6] = (char)iVar4;
        uVar3 = ((int (*)())_lReadByte)(param_1);
        iVar6 = iVar6 + 1;
        iVar4 = (int)(char)uVar3;
        uVar1 = iVar4 - 0x61;
      }
    }
    local_2c0[iVar6] = 0;
    if (iVar4 == 0) {
      uVar3 = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,local_2c0);
      param_2[2] = uVar3;
      return 0x10e;
    }
    uVar3 = 0x140;
LAB_97b8aac8:
    ___eprintf("%s:%u: failed assertion `%s\'\n",
               "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/preprocessor/tokens.c"
               ,uVar3,"ch == \'\\0\'");
  }
  else {
    if (iVar2 < 0x10f) {
      if (iVar2 == 0x28) {
        uVar3 = ((int (*)())_lReadByte)(param_1);
        goto LAB_97b8aaf0;
      }
      if (iVar2 != 0x10b) {
        return iVar2;
      }
      iVar6 = 0;
      uVar3 = ((int (*)())_lReadByte)(param_1);
      iVar4 = (int)(char)uVar3;
      uVar1 = iVar4 - 0x30;
      while (((((uVar1 & 0xff) < 10 || (iVar4 == 0x65)) ||
              ((iVar4 == 0x45 || ((iVar4 == 0x2e || (iVar4 == 0x2b)))))) || (iVar4 == 0x2d))) {
        if (iVar6 < 0x80) {
          local_2c0[iVar6] = (char)iVar4;
          uVar3 = ((int (*)())_lReadByte)(param_1);
          iVar6 = iVar6 + 1;
          iVar4 = (int)(char)uVar3;
          uVar1 = iVar4 - 0x30;
        }
      }
      local_2c0[iVar6] = 0;
      if (iVar4 == 0) {
        _strcpy(param_2 + 3,local_2c0);
        dVar7 = (double)((double (*)())_glp_strtod)(param_2 + 3,0);
        param_2[1] = (float)dVar7;
        return 0x10b;
      }
      uVar3 = 0x158;
      goto LAB_97b8aac8;
    }
    if (iVar2 == 0x116) {
      iVar2 = 0;
      pcVar5 = local_230;
      while( true ) {
        uVar3 = ((int (*)())_lReadByte)(param_1);
        if ((char)uVar3 == '\0') break;
        if (iVar2 < 0x200) {
          *pcVar5 = (char)uVar3;
          iVar2 = iVar2 + 1;
          pcVar5 = pcVar5 + 1;
        }
      }
      local_230[iVar2] = '\0';
      uVar3 = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,local_230);
      param_2[2] = uVar3;
      return 0x116;
    }
    if (0x116 < iVar2) {
      if (iVar2 != 0x117) {
        return iVar2;
      }
      goto LAB_97b8a810;
    }
    if (iVar2 != 0x10f) {
      return iVar2;
    }
    iVar6 = 0;
    uVar3 = ((int (*)())_lReadByte)(param_1);
    iVar4 = (int)(char)uVar3;
    uVar1 = iVar4 - 0x30;
    while ((uVar1 & 0xff) < 10) {
      if (iVar6 < 0x80) {
        local_2c0[iVar6] = (char)iVar4;
        uVar3 = ((int (*)())_lReadByte)(param_1);
        iVar6 = iVar6 + 1;
        iVar4 = (int)(char)uVar3;
        uVar1 = iVar4 - 0x30;
      }
    }
    local_2c0[iVar6] = 0;
    if (iVar4 != 0) {
      uVar3 = 0x168;
      goto LAB_97b8aac8;
    }
  }
  _strcpy(param_2 + 3,local_2c0);
  uVar3 = _atoi(param_2 + 3);
LAB_97b8aaf0:
  *param_2 = uVar3;
  return iVar2;
}

/* _scan_token @ 0x97b8ab0c (248 bytes) */
int _scan_token(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined *puVar1;
  int iVar2;
  code *pcVar3;
  
  iVar2 = ((int (*)())_ReadToken)(param_1[6],param_2);
  puVar1 = PTR__cpp_a7b7c0a4;
  **(undefined2 **)(*(int *)PTR__cpp_a7b7c0a4 + 0x18) =
       *(undefined2 *)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 0x12);
  *(undefined2 *)(*(int *)(*(int *)puVar1 + 0x18) + 2) =
       *(undefined2 *)(*(int *)(*(int *)puVar1 + 0x20) + 0x16);
  if (iVar2 == 10) {
    iVar2 = 10;
    param_1[5] = param_1[5] + 1;
  }
  else if (iVar2 < 1) {
    *(undefined4 *)(*(int *)puVar1 + 0x20) = *param_1;
    pcVar3 = (code *)param_1[7];
    _free(param_1);
    if ((pcVar3 != (code *)0x0) && (iVar2 = (*pcVar3)(*(undefined4 *)puVar1), iVar2 == 0)) {
      return -1;
    }
    iVar2 = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
                    
                    
    iVar2 = (**(code **)(iVar2 + 4))
                      (iVar2,param_2,param_3,param_4,param_5,param_6,*(int *)PTR__cpp_a7b7c0a4);
    return iVar2;
  }
  return iVar2;
}

/* _ReadFromTokenStream @ 0x97b8ac04 (172 bytes) */
int _ReadFromTokenStream(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  puVar4 = (undefined4 *)_malloc(0x20);
  puVar2 = PTR__cpp_a7b7c0a4;
  iVar3 = *(int *)PTR__cpp_a7b7c0a4;
  puVar4[7] = 0;
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[5] = 0;
  puVar4[6] = 0;
  puVar4[2] = 0;
  puVar4[3] = 0;
  puVar4[4] = param_2;
  uVar1 = DAT_a7b7b050;
  uVar5 = *(undefined4 *)(iVar3 + 0x20);
  puVar4[5] = 1;
  puVar4[1] = uVar1;
  *puVar4 = uVar5;
  puVar4[7] = param_3;
  puVar4[6] = param_1;
  ((int (*)())_RewindTokenStream)(param_1);
  *(undefined4 **)(*(int *)puVar2 + 0x20) = puVar4;
  return 1;
}

/* FUN_97b8acb4 @ 0x97b8acb4 (96 bytes) */
int FUN_97b8acb4(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  uVar1 = param_1[6];
  _memcpy(param_2,param_1 + 7,0x90);
  *(undefined4 *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) = *param_1;
  _free(param_1);
  return uVar1;
}

/* _UngetToken @ 0x97b8ad14 (156 bytes) */
int _UngetToken(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)_malloc(0xac);
  _memset(puVar1,0,0xac);
  puVar1[6] = param_1;
  _memcpy(puVar1 + 7,param_2,0x90);
  iVar2 = *(int *)PTR__cpp_a7b7c0a4;
  puVar1[1] = DAT_a7b7b04c;
  *puVar1 = *(undefined4 *)(iVar2 + 0x20);
  puVar1[4] = *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x10);
  puVar1[5] = *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x14);
  *(undefined4 **)(iVar2 + 0x20) = puVar1;
  return;
}

/* _DumpTokenStream @ 0x97b8adb0 (240 bytes) */
int _DumpTokenStream(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  char *pcVar2;
  char acStack_80 [116];
  
  ((int (*)())_RewindTokenStream)(param_2);
  do {
    iVar1 = ((int (*)())_ReadToken)(param_2,param_3);
    if (iVar1 < 1) {
      return;
    }
    switch(iVar1) {
    case 0x10b:
    case 0x10f:
      goto switchD_97b8ae00_caseD_10b;
    default:
      if (0x7e < iVar1) goto LAB_97b8ae70;
      pcVar2 = "%c";
      break;
    case 0x10e:
    case 0x117:
      iVar1 = *(int *)(param_3 + 8);
LAB_97b8ae70:
      iVar1 = _GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,iVar1);
      pcVar2 = "%s ";
      break;
    case 0x116:
      iVar1 = _GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,*(undefined4 *)(param_3 + 8));
      pcVar2 = "\"%s\"";
    }
    _sprintf(acStack_80,pcVar2,iVar1);
switchD_97b8ae00_caseD_10b:
    _CPPDebugLogMsg(acStack_80);
  } while( true );
}

/* TBuiltIns__getNumStringArrays @ 0x97b8aed4 (20 bytes) */
int TBuiltIns__getNumStringArrays(this, param_2)
  unsigned char * this;
  int param_2;
{
  return 6 - (uint)(param_2 == 1);
}

/* TBuiltIns__getStringArray @ 0x97b8aee8 (204 bytes) */
int TBuiltIns__getStringArray(this, param_2, param_3)
  unsigned char * this;
  int param_2;
  uint param_3;
{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_2 == 1) {
    if (param_3 == 0) {
      puVar1 = &_strBuiltInFunctions;
    }
    if (param_3 == 1) {
      puVar1 = &_strBuiltInFunctionsFragment;
    }
    if (param_3 == 2) {
      puVar1 = &_strStandardFragmentVaryings;
    }
    if (param_3 == 3) {
      puVar1 = &_strStandardUniformConstants;
    }
    if (param_3 != 4) {
      return puVar1;
    }
  }
  else {
    if (param_3 == 0) {
      puVar1 = &_strBuiltInFunctions;
    }
    if (param_3 == 1) {
      puVar1 = &_strBuiltInFunctionsVertex;
    }
    if (param_3 == 2) {
      puVar1 = &_strStandardVertexVaryings;
    }
    if (param_3 == 3) {
      puVar1 = &_strStandardVertexAttributes;
    }
    if (param_3 == 4) {
      puVar1 = &_strStandardUniformConstants;
    }
    if (param_3 != 5) {
      return puVar1;
    }
  }
  return &_strStandardUniforms;
}

/* TBuiltIns__getStringSizeArray @ 0x97b8afb4 (204 bytes) */
int TBuiltIns__getStringSizeArray(this, param_2, param_3)
  unsigned char * this;
  int param_2;
  uint param_3;
{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_2 == 1) {
    if (param_3 == 0) {
      puVar1 = &_sizeBuiltInFunctions;
    }
    if (param_3 == 1) {
      puVar1 = &_sizeBuiltInFunctionsFragment;
    }
    if (param_3 == 2) {
      puVar1 = &_sizeStandardFragmentVaryings;
    }
    if (param_3 == 3) {
      puVar1 = &_sizeStandardUniformConstants;
    }
    if (param_3 != 4) {
      return puVar1;
    }
  }
  else {
    if (param_3 == 0) {
      puVar1 = &_sizeBuiltInFunctions;
    }
    if (param_3 == 1) {
      puVar1 = &_sizeBuiltInFunctionsVertex;
    }
    if (param_3 == 2) {
      puVar1 = &_sizeStandardVertexVaryings;
    }
    if (param_3 == 3) {
      puVar1 = &_sizeStandardVertexAttributes;
    }
    if (param_3 == 4) {
      puVar1 = &_sizeStandardUniformConstants;
    }
    if (param_3 != 5) {
      return puVar1;
    }
  }
  return &_sizeStandardUniforms;
}

/* TBuiltIns__getNumStrings @ 0x97b8b080 (148 bytes) */
int TBuiltIns__getNumStrings(this, param_2, param_3)
  unsigned char * this;
  int param_2;
  uint param_3;
{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 == 1) {
    if (param_3 == 0) {
      uVar2 = 0x454;
    }
    if (param_3 == 1) {
      uVar2 = 0x34;
    }
    if (param_3 == 2) {
      uVar2 = 0x14;
    }
    if (param_3 == 3) {
      uVar2 = 0x34;
    }
    bVar1 = param_3 == 4;
  }
  else {
    if (param_3 == 0) {
      uVar2 = 0x454;
    }
    if (param_3 == 1) {
      uVar2 = 8;
    }
    if (param_3 == 2) {
      uVar2 = 0x1c;
    }
    if (param_3 == 3) {
      uVar2 = 0x38;
    }
    if (param_3 == 4) {
      uVar2 = 0x34;
    }
    bVar1 = param_3 == 5;
  }
  if (bVar1) {
    uVar2 = 0x174;
  }
  return uVar2 >> 2;
}

/* __ZN9TBuiltIns10initializeEv @ 0x97b8b114 (4 bytes) */
int __ZN9TBuiltIns10initializeEv()
{
  return;
}

/* __ZN9TBuiltIns10initializeERK16TBuiltInResource @ 0x97b8b118 (4 bytes) */
int __ZN9TBuiltIns10initializeERK16TBuiltInResource(param_1)
  unsigned char * param_1;
{
  return;
}

/* __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTable @ 0x97b8b11c (5284 bytes) */
int __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTable(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  unsigned char * pTVar6;
  int *piVar7;
  unsigned char * psVar8;
  void *pvVar9;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  char *pcVar10;
  unsigned char * in_r5;
  unsigned char * paVar11;
  unsigned char * paVar12;
  undefined4 uVar13;
  undefined4 in_r6;
  undefined4 in_r7;
  void *pvVar14;
  undefined *puVar15;
  undefined4 uVar16;
  char in_RESERVE;
  byte bVar17;
  undefined8 uVar18;
  undefined4 local_3b0 [4];
  undefined **local_3a0;
  undefined4 local_39c;
  undefined4 local_398;
  undefined4 local_394;
  undefined4 local_390;
  undefined4 local_38c;
  undefined4 local_388;
  undefined4 local_384;
  undefined4 local_380;
  uint local_37c;
  undefined4 local_370;
  undefined4 local_36c;
  undefined4 local_360;
  undefined4 local_35c;
  undefined4 local_350;
  int local_34c;
  int *local_348;
  undefined4 local_340 [4];
  undefined4 local_330 [4];
  undefined **local_320;
  undefined4 local_31c;
  undefined4 local_318;
  undefined4 local_314;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300;
  uint local_2fc;
  undefined4 local_2f0;
  undefined4 local_2ec;
  undefined4 local_2e0;
  undefined4 local_2dc;
  undefined4 local_2d0;
  int local_2cc;
  int *local_2c8;
  undefined4 local_2c0 [4];
  undefined4 local_2b0 [4];
  undefined **local_2a0;
  undefined4 local_29c;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  undefined4 local_28c;
  undefined4 local_288;
  undefined4 local_284;
  undefined4 local_280;
  uint local_27c;
  undefined4 local_270;
  undefined4 local_26c;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_250;
  int local_24c;
  int *local_248;
  undefined4 local_240 [4];
  undefined4 local_230 [4];
  undefined **local_220;
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  uint local_1fc;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d0;
  int local_1cc;
  int *local_1c8;
  undefined4 local_1c0 [4];
  undefined4 local_1b0 [4];
  undefined **local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  uint local_17c;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_150;
  int local_14c;
  int *local_148;
  undefined4 local_140 [4];
  undefined4 local_130 [4];
  undefined **local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  uint local_fc;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d0;
  int local_cc;
  int *local_c8;
  undefined4 local_c0 [4];
  undefined4 local_b0 [4];
  undefined **local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  uint local_7c;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_50;
  int local_4c;
  int *local_48;
  undefined4 local_40 [6];
  
  if (param_1 == 0) {
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(pTVar6,0x40);
    pcVar10 = DAT_a7b7b708;
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    uVar18 = TPoolAllocator__allocate(pTVar6,8);
    pvVar9 = (void *)((ulonglong)uVar18 >> 0x20);
    uVar13 = (undefined4)uVar18;
    bVar17 = (pvVar9 == (void *)0x0) << 1;
    pvVar14 = (void *)0x0;
    if (pvVar9 != (void *)0x0) {
      local_1b0[0] = GetGlobalPoolAllocator();
      in_r5 = (unsigned char *)local_1b0;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(pvVar9,pcVar10,in_r5);
      uVar13 = extraout_r4_03;
      pvVar14 = pvVar9;
    }
    puVar15 = PTR_vtable_a7b7c0b4 + 8;
    local_17c = local_17c & 0x801ff | 0x1a082000;
    local_19c = 0;
    local_198 = 0;
    local_194 = 0;
    paVar11 = (unsigned char *)&local_150;
    local_190 = 0;
    local_18c = 0;
    local_188 = 0;
    local_184 = 0;
    local_180 = 0;
    local_1a0 = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar7[1] = (int)pvVar14;
    *piVar7 = (int)puVar15;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar7[0xb] = 0;
    uVar2 = piVar7[0xc];
    piVar7[0xc] = uVar2 & 0x1ffffff | 0x1a000000;
    uVar3 = (local_17c >> 0x13 & 0x3f) << 0x13;
    piVar7[0xc] = uVar3 | uVar2 & 0x7ffff | 0x1a000000;
    piVar7[0xc] = uVar3 | uVar2 & 0x7ff | 0x1a000000 | 0x2000;
    piVar7[0xc] = uVar3 | uVar2 & 0x3ff | 0x1a000000 | 0x2000;
    piVar7[0xc] = uVar3 | uVar2 & 0x1ff | 0x1a000000 | 0x2000;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar4 = param_2[3];
    param_2[3] = iVar4 + 1;
    piVar7[2] = iVar4 + 1;
    iVar4 = *param_2;
    uVar16 = *(undefined4 *)(iVar4 + ((param_2[1] - iVar4 & 0xfffffffcU) - 4));
    local_16c = 0;
    psVar8 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7,uVar13,in_r5,in_r6,in_r7,pvVar14,iVar4);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(paVar11,psVar8);
    local_148 = piVar7;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_160,uVar16,paVar11);
    local_170 = local_160;
    piVar7 = (int *)(local_14c + -4);
    local_16c = local_15c;
    local_140[0] = local_150;
    do {
      iVar4 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar17 = 2;
      }
    } while (!(bool)(bVar17 >> 1 & 1));
    if (iVar4 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_14c + -0xc),local_140);
    }
    local_1a0 = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(pTVar6,0x40);
    pcVar10 = DAT_a7b7b70c;
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    uVar18 = TPoolAllocator__allocate(pTVar6,8);
    pvVar9 = (void *)((ulonglong)uVar18 >> 0x20);
    uVar13 = (undefined4)uVar18;
    bVar17 = (pvVar9 == (void *)0x0) << 1;
    pvVar14 = (void *)0x0;
    if (pvVar9 != (void *)0x0) {
      local_130[0] = GetGlobalPoolAllocator();
      paVar11 = (unsigned char *)local_130;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(pvVar9,pcVar10,paVar11);
      uVar13 = extraout_r4_04;
      pvVar14 = pvVar9;
    }
    puVar15 = PTR_vtable_a7b7c0b4 + 8;
    local_fc = local_fc & 0x1ff | 0x1c080800;
    local_11c = 0;
    local_118 = 0;
    paVar12 = (unsigned char *)&local_d0;
    local_114 = 0;
    local_110 = 0;
    local_10c = 0;
    local_108 = 0;
    local_104 = 0;
    local_100 = 0;
    local_120 = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar7[1] = (int)pvVar14;
    *piVar7 = (int)puVar15;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar7[0xb] = 0;
    uVar3 = piVar7[0xc];
    piVar7[0xc] = uVar3 & 0x1ffffff | 0x1c000000;
    piVar7[0xc] = uVar3 & 0x7ffff | 0x1c080000;
    piVar7[0xc] = uVar3 & 0x7ff | 0x1c080800;
    piVar7[0xc] = uVar3 & 0x3ff | 0x1c080800;
    piVar7[0xc] = uVar3 & 0x1ff | 0x1c080800;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar4 = param_2[3];
    param_2[3] = iVar4 + 1;
    piVar7[2] = iVar4 + 1;
    iVar4 = *param_2;
    uVar16 = *(undefined4 *)(iVar4 + ((param_2[1] - iVar4 & 0xfffffffcU) - 4));
    local_ec = 0;
    psVar8 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7,uVar13,paVar11,in_r6,in_r7,pvVar14,iVar4);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(paVar12,psVar8);
    local_c8 = piVar7;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_e0,uVar16,paVar12);
    local_f0 = local_e0;
    piVar7 = (int *)(local_cc + -4);
    local_ec = local_dc;
    local_c0[0] = local_d0;
    do {
      iVar4 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar17 = 2;
      }
    } while (!(bool)(bVar17 >> 1 & 1));
    if (iVar4 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_cc + -0xc),local_c0);
    }
    local_120 = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(pTVar6,0x40);
    pcVar10 = DAT_a7b7b710;
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    uVar18 = TPoolAllocator__allocate(pTVar6,8);
    pvVar9 = (void *)((ulonglong)uVar18 >> 0x20);
    uVar13 = (undefined4)uVar18;
    bVar17 = (pvVar9 == (void *)0x0) << 1;
    pvVar14 = (void *)0x0;
    if (pvVar9 != (void *)0x0) {
      local_b0[0] = GetGlobalPoolAllocator();
      paVar12 = (unsigned char *)local_b0;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(pvVar9,pcVar10,paVar12);
      uVar13 = extraout_r4_05;
      pvVar14 = pvVar9;
    }
    puVar15 = PTR_vtable_a7b7c0b4 + 8;
    local_7c = local_7c & 0x801ff | 0x1e082000;
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    local_90 = 0;
    local_8c = 0;
    local_88 = 0;
    local_84 = 0;
    local_80 = 0;
    local_a0 = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar7[1] = (int)pvVar14;
    *piVar7 = (int)puVar15;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar7[0xb] = 0;
    uVar2 = piVar7[0xc];
    piVar7[0xc] = uVar2 & 0x1ffffff | 0x1e000000;
    uVar3 = (local_7c >> 0x13 & 0x3f) << 0x13;
    piVar7[0xc] = uVar3 | uVar2 & 0x7ffff | 0x1e000000;
    piVar7[0xc] = uVar3 | uVar2 & 0x7ff | 0x1e000000 | 0x2000;
    piVar7[0xc] = uVar3 | uVar2 & 0x3ff | 0x1e000000 | 0x2000;
    piVar7[0xc] = uVar3 | uVar2 & 0x1ff | 0x1e000000 | 0x2000;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar4 = param_2[3];
    param_2[3] = iVar4 + 1;
    piVar7[2] = iVar4 + 1;
    iVar4 = *param_2;
    uVar16 = *(undefined4 *)(iVar4 + ((param_2[1] - iVar4 & 0xfffffffcU) - 4));
    local_6c = 0;
    psVar8 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7,uVar13,paVar12,in_r6,in_r7,pvVar14,iVar4);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_50,psVar8);
    local_48 = piVar7;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_60,uVar16,&local_50);
    local_70 = local_60;
    piVar7 = (int *)(local_4c + -4);
    local_6c = local_5c;
    local_40[0] = local_50;
    do {
      iVar4 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar17 = 2;
      }
    } while (!(bool)(bVar17 >> 1 & 1));
    if (iVar4 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_4c + -0xc),local_40);
    }
    local_a0 = &PTR___ZN5TTypeD1Ev_a7b7cf48;
  }
  else if (param_1 == 1) {
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(pTVar6,0x40);
    pcVar10 = _strSpecialBuiltIn;
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    uVar18 = TPoolAllocator__allocate(pTVar6,8);
    pvVar9 = (void *)((ulonglong)uVar18 >> 0x20);
    uVar13 = (undefined4)uVar18;
    bVar17 = (pvVar9 == (void *)0x0) << 1;
    pvVar14 = (void *)0x0;
    if (pvVar9 != (void *)0x0) {
      local_3b0[0] = GetGlobalPoolAllocator();
      in_r5 = (unsigned char *)local_3b0;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(pvVar9,pcVar10,in_r5);
      uVar13 = extraout_r4;
      pvVar14 = pvVar9;
    }
    puVar15 = PTR_vtable_a7b7c0b4 + 8;
    local_37c = local_37c & 0x1801ff | 0x20180800;
    local_39c = 0;
    local_398 = 0;
    local_394 = 0;
    paVar11 = (unsigned char *)&local_350;
    local_390 = 0;
    local_38c = 0;
    local_388 = 0;
    local_384 = 0;
    local_380 = 0;
    local_3a0 = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar7[1] = (int)pvVar14;
    *piVar7 = (int)puVar15;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar7[0xb] = 0;
    uVar2 = piVar7[0xc];
    piVar7[0xc] = uVar2 & 0x1ffffff | 0x20000000;
    uVar3 = (local_37c >> 0x13 & 0x3f) << 0x13;
    piVar7[0xc] = uVar3 | uVar2 & 0x7ffff | 0x20000000;
    piVar7[0xc] = uVar3 | uVar2 & 0x7ff | 0x20000000 | 0x800;
    piVar7[0xc] = uVar3 | uVar2 & 0x3ff | 0x20000000 | 0x800;
    piVar7[0xc] = uVar3 | uVar2 & 0x1ff | 0x20000000 | 0x800;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar4 = param_2[3];
    param_2[3] = iVar4 + 1;
    piVar7[2] = iVar4 + 1;
    iVar4 = *param_2;
    uVar16 = *(undefined4 *)(iVar4 + ((param_2[1] - iVar4 & 0xfffffffcU) - 4));
    local_36c = 0;
    psVar8 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7,uVar13,in_r5,in_r6,in_r7,pvVar14,iVar4);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(paVar11,psVar8);
    local_348 = piVar7;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_360,uVar16,paVar11);
    local_370 = local_360;
    piVar7 = (int *)(local_34c + -4);
    local_36c = local_35c;
    local_340[0] = local_350;
    do {
      iVar4 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar17 = 2;
      }
    } while (!(bool)(bVar17 >> 1 & 1));
    if (iVar4 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_34c + -0xc),local_340);
    }
    local_3a0 = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(pTVar6,0x40);
    pcVar10 = DAT_a7b7b6f8;
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    uVar18 = TPoolAllocator__allocate(pTVar6,8);
    pvVar9 = (void *)((ulonglong)uVar18 >> 0x20);
    uVar13 = (undefined4)uVar18;
    bVar17 = (pvVar9 == (void *)0x0) << 1;
    pvVar14 = (void *)0x0;
    if (pvVar9 != (void *)0x0) {
      local_330[0] = GetGlobalPoolAllocator();
      paVar11 = (unsigned char *)local_330;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(pvVar9,pcVar10,paVar11);
      uVar13 = extraout_r4_00;
      pvVar14 = pvVar9;
    }
    puVar15 = PTR_vtable_a7b7c0b4 + 8;
    local_2fc = local_2fc & 0x801ff | 0x22082000;
    local_31c = 0;
    local_318 = 0;
    local_314 = 0;
    paVar12 = (unsigned char *)&local_2d0;
    local_310 = 0;
    local_30c = 0;
    local_308 = 0;
    local_304 = 0;
    local_300 = 0;
    local_320 = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar7[1] = (int)pvVar14;
    *piVar7 = (int)puVar15;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar7[0xb] = 0;
    uVar2 = piVar7[0xc];
    piVar7[0xc] = uVar2 & 0x1ffffff | 0x22000000;
    uVar3 = (local_2fc >> 0x13 & 0x3f) << 0x13;
    piVar7[0xc] = uVar3 | uVar2 & 0x7ffff | 0x22000000;
    piVar7[0xc] = uVar3 | uVar2 & 0x7ff | 0x22000000 | 0x2000;
    piVar7[0xc] = uVar3 | uVar2 & 0x3ff | 0x22000000 | 0x2000;
    piVar7[0xc] = uVar3 | uVar2 & 0x1ff | 0x22000000 | 0x2000;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar4 = param_2[3];
    param_2[3] = iVar4 + 1;
    piVar7[2] = iVar4 + 1;
    iVar4 = *param_2;
    uVar16 = *(undefined4 *)(iVar4 + ((param_2[1] - iVar4 & 0xfffffffcU) - 4));
    local_2ec = 0;
    psVar8 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7,uVar13,paVar11,in_r6,in_r7,pvVar14,iVar4);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(paVar12,psVar8);
    local_2c8 = piVar7;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_2e0,uVar16,paVar12);
    local_2f0 = local_2e0;
    piVar7 = (int *)(local_2cc + -4);
    local_2ec = local_2dc;
    local_2c0[0] = local_2d0;
    do {
      iVar4 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar17 = 2;
      }
    } while (!(bool)(bVar17 >> 1 & 1));
    if (iVar4 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_2cc + -0xc),local_2c0);
    }
    local_320 = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(pTVar6,0x40);
    pcVar10 = DAT_a7b7b6fc;
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    uVar18 = TPoolAllocator__allocate(pTVar6,8);
    pvVar9 = (void *)((ulonglong)uVar18 >> 0x20);
    uVar13 = (undefined4)uVar18;
    bVar17 = (pvVar9 == (void *)0x0) << 1;
    pvVar14 = (void *)0x0;
    if (pvVar9 != (void *)0x0) {
      local_2b0[0] = GetGlobalPoolAllocator();
      paVar12 = (unsigned char *)local_2b0;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(pvVar9,pcVar10,paVar12);
      uVar13 = extraout_r4_01;
      pvVar14 = pvVar9;
    }
    puVar15 = PTR_vtable_a7b7c0b4 + 8;
    local_27c = local_27c & 0x801ff | 0x24082000;
    local_29c = 0;
    local_298 = 0;
    local_294 = 0;
    paVar11 = (unsigned char *)&local_250;
    local_290 = 0;
    local_28c = 0;
    local_288 = 0;
    local_284 = 0;
    local_280 = 0;
    local_2a0 = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar7[1] = (int)pvVar14;
    *piVar7 = (int)puVar15;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar7[0xb] = 0;
    uVar2 = piVar7[0xc];
    piVar7[0xc] = uVar2 & 0x1ffffff | 0x24000000;
    uVar3 = (local_27c >> 0x13 & 0x3f) << 0x13;
    piVar7[0xc] = uVar3 | uVar2 & 0x7ffff | 0x24000000;
    piVar7[0xc] = uVar3 | uVar2 & 0x7ff | 0x24000000 | 0x2000;
    piVar7[0xc] = uVar3 | uVar2 & 0x3ff | 0x24000000 | 0x2000;
    piVar7[0xc] = uVar3 | uVar2 & 0x1ff | 0x24000000 | 0x2000;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar4 = param_2[3];
    param_2[3] = iVar4 + 1;
    piVar7[2] = iVar4 + 1;
    iVar4 = *param_2;
    uVar16 = *(undefined4 *)(iVar4 + ((param_2[1] - iVar4 & 0xfffffffcU) - 4));
    local_26c = 0;
    psVar8 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7,uVar13,paVar12,in_r6,in_r7,pvVar14,iVar4);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(paVar11,psVar8);
    local_248 = piVar7;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_260,uVar16,paVar11);
    local_270 = local_260;
    piVar7 = (int *)(local_24c + -4);
    local_26c = local_25c;
    local_240[0] = local_250;
    do {
      iVar4 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar17 = 2;
      }
    } while (!(bool)(bVar17 >> 1 & 1));
    if (iVar4 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_24c + -0xc),local_240);
    }
    local_2a0 = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(pTVar6,0x40);
    pcVar10 = DAT_a7b7b700;
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    uVar18 = TPoolAllocator__allocate(pTVar6,8);
    pvVar9 = (void *)((ulonglong)uVar18 >> 0x20);
    uVar13 = (undefined4)uVar18;
    bVar17 = (pvVar9 == (void *)0x0) << 1;
    pvVar14 = (void *)0x0;
    if (pvVar9 != (void *)0x0) {
      local_230[0] = GetGlobalPoolAllocator();
      paVar11 = (unsigned char *)local_230;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(pvVar9,pcVar10,paVar11);
      uVar13 = extraout_r4_02;
      pvVar14 = pvVar9;
    }
    puVar15 = PTR_vtable_a7b7c0b4 + 8;
    local_1fc = local_1fc & 0x1ff | 0x26080800;
    local_21c = 0;
    local_218 = 0;
    local_214 = 0;
    local_210 = 0;
    local_20c = 0;
    local_208 = 0;
    local_204 = 0;
    local_200 = 0;
    local_220 = &PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar7[1] = (int)pvVar14;
    *piVar7 = (int)puVar15;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar7[0xb] = 0;
    uVar3 = piVar7[0xc];
    piVar7[0xc] = uVar3 & 0x1ffffff | 0x26000000;
    piVar7[0xc] = uVar3 & 0x7ffff | 0x26080000;
    piVar7[0xc] = uVar3 & 0x7ff | 0x26080800;
    piVar7[0xc] = uVar3 & 0x3ff | 0x26080800;
    piVar7[0xc] = uVar3 & 0x1ff | 0x26080800;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar4 = param_2[3];
    param_2[3] = iVar4 + 1;
    piVar7[2] = iVar4 + 1;
    iVar4 = *param_2;
    uVar16 = *(undefined4 *)(iVar4 + ((param_2[1] - iVar4 & 0xfffffffcU) - 4));
    local_1ec = 0;
    psVar8 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7,uVar13,paVar11,in_r6,in_r7,pvVar14,iVar4);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_1d0,psVar8);
    local_1c8 = piVar7;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_1e0,uVar16,&local_1d0);
    local_1f0 = local_1e0;
    piVar7 = (int *)(local_1cc + -4);
    local_1ec = local_1dc;
    local_1c0[0] = local_1d0;
    do {
      iVar4 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar17 = 2;
      }
    } while (!(bool)(bVar17 >> 1 & 1));
    if (iVar4 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_1cc + -0xc),local_1c0);
    }
    local_220 = &PTR___ZN5TTypeD1Ev_a7b7cf48;
  }
  puVar15 = PTR__operatorStrings_a7b7c0b0;
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(PTR__operatorStrings_a7b7c0b0 + 0x1c),7);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x54),0x15);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x5c),0x17);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x7c),0x1f);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x80),0x20);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x84),0x21);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x88),0x22);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x8c),0x23);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x90),0x24);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0xc4),0x31);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 200),0x32);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0xcc),0x33);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0xd0),0x34);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0xd4),0x35);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0xd8),0x36);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0xdc),0x37);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0xe0),0x38);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0xe4),0x39);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0xf0),0x3c);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0xec),0x3b);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0xe8),0x3a);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0xf4),0x3d);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0xf8),0x3e);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0xfc),0x3f);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x100),0x40);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x104),0x41);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x108),0x42);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x10c),0x43);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x110),0x44);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x114),0x45);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x118),0x46);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x11c),0x47);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x120),0x48);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x124),0x49);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x128),0x4a);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 300),0x4b);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x130),0x4c);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x134),0x4d);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x138),0x4e);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x13c),0x4f);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x140),0x50);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x144),0x51);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x148),0x52);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x15c),0x57);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x160),0x58);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x218),0x86);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x21c),0x87);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x220),0x88);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x224),0x89);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x228),0x8a);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x22c),0x8b);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x230),0x8c);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x234),0x8d);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x238),0x8e);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x23c),0x8f);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x240),0x90);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x244),0x91);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x248),0x92);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x24c),0x93);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x250),0x94);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x254),0x95);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 600),0x96);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x25c),0x97);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x260),0x98);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x264),0x99);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x268),0x9a);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x26c),0x9b);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x270),0x9c);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x274),0x9d);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x278),0x9e);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x27c),0x9f);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x280),0xa0);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x284),0xa1);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x288),0xa2);
  TSymbolTableLevel__relateToOperator
            (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x28c),0xa3);
  if (param_1 == 0) {
    puVar5 = (undefined4 *)*param_2;
    uVar13 = 0x85;
    pcVar10 = *(char **)(puVar15 + 0x214);
  }
  else {
    if (param_1 != 1) {
      return;
    }
    TSymbolTableLevel__relateToOperator
              (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x14c),0x53);
    TSymbolTableLevel__relateToOperator
              (*(unsigned char **)*param_2,*(char **)(puVar15 + 0x150),0x54);
    puVar5 = (undefined4 *)*param_2;
    pcVar10 = *(char **)(puVar15 + 0x154);
    uVar13 = 0x55;
  }
  TSymbolTableLevel__relateToOperator((unsigned char *)*puVar5,pcVar10,uVar13);
  return;
}

/* __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTableRK16TBuiltInResource @ 0x97b8c5c0 (600 bytes) */
int __Z16IdentifyBuiltIns11EShLanguageR12TSymbolTableRK16TBuiltInResource(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  unsigned char * param_3;
{
  int iVar1;
  char *pcVar2;
  void *pvVar3;
  uint uVar4;
  unsigned char * pTVar5;
  int *piVar6;
  void *this;
  unsigned char * psVar7;
  undefined4 extraout_r4;
  undefined4 a1;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar8;
  undefined4 uVar9;
  char in_RESERVE;
  byte bVar10;
  undefined8 uVar11;
  undefined4 local_70 [4];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_40;
  int local_3c;
  int *local_38;
  undefined4 local_30 [6];
  
  if (param_1 == 1) {
    iVar8 = *(int *)(param_3 + 0x2c);
    pTVar5 = (unsigned char *)GetGlobalPoolAllocator();
    piVar6 = (int *)TPoolAllocator__allocate(pTVar5,0x40);
    pcVar2 = DAT_a7b7b704;
    pTVar5 = (unsigned char *)GetGlobalPoolAllocator();
    uVar11 = TPoolAllocator__allocate(pTVar5,8);
    this = (void *)((ulonglong)uVar11 >> 0x20);
    a1 = (undefined4)uVar11;
    bVar10 = (this == (void *)0x0) << 1;
    pvVar3 = (void *)0x0;
    if (this != (void *)0x0) {
      local_70[0] = GetGlobalPoolAllocator();
      param_3 = (unsigned char *)local_70;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(this,pcVar2,param_3);
      pvVar3 = this;
      a1 = extraout_r4;
    }
    piVar6[1] = (int)pvVar3;
    *piVar6 = (int)(PTR_vtable_a7b7c0b4 + 8);
    piVar6[4] = iVar8;
    piVar6[5] = 0;
    piVar6[6] = 0;
    piVar6[7] = 0;
    piVar6[8] = 0;
    piVar6[9] = 0;
    piVar6[3] = (int)&PTR___ZN5TTypeD1Ev_a7b7cf48;
    piVar6[10] = 0;
    piVar6[0xb] = 0;
    uVar4 = piVar6[0xc];
    piVar6[0xc] = uVar4 & 0x1ffffff | 0x24000000;
    piVar6[0xc] = uVar4 & 0x7ffff | 0x24080000;
    piVar6[0xc] = uVar4 & 0x7ff | 0x24082000;
    piVar6[0xc] = uVar4 & 0x3ff | 0x24082000;
    piVar6[0xc] = uVar4 & 0x1ff | 0x24082200;
    piVar6[0xd] = 0;
    piVar6[0xe] = 0;
    piVar6[0xf] = 0;
    iVar8 = param_2[3];
    param_2[3] = iVar8 + 1;
    piVar6[2] = iVar8 + 1;
    uVar9 = *(undefined4 *)(*param_2 + ((param_2[1] - *param_2 & 0xfffffffcU) - 4));
    local_5c = 0;
    psVar7 = (unsigned char *)(**(code **)(*piVar6 + 8))(piVar6,a1,param_3,in_r6,in_r7,in_r8,0);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_40,psVar7);
    local_38 = piVar6;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_50,uVar9,&local_40);
    local_60 = local_50;
    piVar6 = (int *)(local_3c + -4);
    local_5c = local_4c;
    local_30[0] = local_40;
    do {
      iVar8 = *piVar6;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar8 + -1,0,piVar6);
        *piVar6 = iVar1;
        bVar10 = 2;
      }
    } while (!(bool)(bVar10 >> 1 & 1));
    if (iVar8 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_3c + -0xc),local_30);
    }
  }
  return;
}

/* GetPreprocessorBuiltinString @ 0x97b8c818 (28 bytes) */
int GetPreprocessorBuiltinString()
{
  return GetPreprocessorBuiltinString__PreprocessorBuiltinString;
}

/* __ZN13TInfoSinkBase6appendEPKc @ 0x97b8c834 (196 bytes) */
int __ZN13TInfoSinkBase6appendEPKc(this, param_2)
  void *this;
  char *param_2;
{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  
  uVar1 = *(uint *)((int)this + 4);
  if ((uVar1 & 4) != 0) {
    iVar2 = _strlen(param_2);
    uVar1 = *(uint *)(*(int *)this + -8);
    if (uVar1 < *(int *)(*(int *)this + -0xc) + iVar2 + 2U) {
      __ZNSs7reserveEm(this,uVar1 + (uVar1 >> 1));
    }
    uVar3 = _strlen(param_2);
    __ZNSs6appendEPKcm(this,param_2,uVar3);
    uVar1 = *(uint *)((int)this + 4);
  }
  if ((uVar1 & 2) != 0) {
    _fprintf((FILE *)(PTR_DAT_a7b7c0bc + 0x58),"%s",param_2);
    return;
  }
  return;
}

/* __ZN13TInfoSinkBase6appendEic @ 0x97b8c8f8 (180 bytes) */
int __ZN13TInfoSinkBase6appendEic(this, param_2, param_3)
  void *this;
  int param_2;
  undefined4 param_3;
{
  uint uVar1;
  
  uVar1 = *(uint *)((int)this + 4);
  if ((uVar1 & 4) != 0) {
    uVar1 = *(uint *)(*(int *)this + -8);
    if (uVar1 < *(int *)(*(int *)this + -0xc) + param_2 + 2U) {
      __ZNSs7reserveEm(this,uVar1 + (uVar1 >> 1));
    }
    __ZNSs6appendEmc(this,param_2,param_3);
    uVar1 = *(uint *)((int)this + 4);
  }
  if ((uVar1 & 2) != 0) {
    _fprintf((FILE *)(PTR_DAT_a7b7c0bc + 0x58),"%c",param_3);
    return;
  }
  return;
}

/* __ZN13TInfoSinkBase6appendERKSs @ 0x97b8c9ac (204 bytes) */
int __ZN13TInfoSinkBase6appendERKSs(this, param_2)
  void *this;
  unsigned char * param_2;
{
  undefined *puVar1;
  uint uVar2;
  
  uVar2 = *(uint *)((int)this + 4);
  if ((uVar2 & 4) != 0) {
    uVar2 = *(uint *)(*(int *)this + -8);
    if (uVar2 < *(int *)(*(int *)this + -0xc) + *(int *)(*(int *)param_2 + -0xc) + 2U) {
      __ZNSs7reserveEm(this,uVar2 + (uVar2 >> 1));
    }
    __ZNSs6appendERKSs(this,param_2);
    uVar2 = *(uint *)((int)this + 4);
  }
  puVar1 = PTR_DAT_a7b7c0bc;
  if ((uVar2 & 2) != 0) {
    *(undefined *)(*(int *)param_2 + *(int *)(*(int *)param_2 + -0xc)) = *PTR__S_terminal_a7b7c0b8;
    _fprintf((FILE *)(puVar1 + 0x58),"%s",*(undefined4 *)param_2);
    return;
  }
  return;
}

/* __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE @ 0x97b8ca78 (244 bytes) */
int __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE(this, param_2)
  void *this;
  unsigned char * param_2;
{
  undefined *puVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  char *pcVar5;
  
  uVar2 = *(uint *)((int)this + 4);
  if ((uVar2 & 4) != 0) {
    iVar4 = *(int *)(param_2 + 4);
    uVar2 = *(uint *)(*(int *)this + -8);
    if (uVar2 < *(int *)(*(int *)this + -0xc) + *(int *)(iVar4 + -0xc) + 2U) {
      __ZNSs7reserveEm(this,uVar2 + (uVar2 >> 1));
      iVar4 = *(int *)(param_2 + 4);
    }
    *(undefined1 *)(iVar4 + *(int *)(iVar4 + -0xc)) = *DAT_a7b7b720;
    pcVar5 = *(char **)(param_2 + 4);
    uVar3 = _strlen(pcVar5);
    __ZNSs6appendEPKcm(this,pcVar5,uVar3);
    uVar2 = *(uint *)((int)this + 4);
  }
  puVar1 = PTR_DAT_a7b7c0bc;
  if ((uVar2 & 2) != 0) {
    *(undefined1 *)(*(int *)(param_2 + 4) + *(int *)(*(int *)(param_2 + 4) + -0xc)) = *DAT_a7b7b720;
    _fprintf((FILE *)(puVar1 + 0x58),"%s",*(undefined4 *)(param_2 + 4));
    return;
  }
  return;
}

/* TIntermediate__addSymbol @ 0x97b8cb6c (376 bytes) */
int TIntermediate__addSymbol(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
  unsigned char * param_4;
  int param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  unsigned char * this_00;
  int *a0;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  char in_RESERVE;
  byte in_cr0;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (int *)TPoolAllocator__allocate(this_00,0x3c);
  a0[1] = 0;
  *a0 = (int)&PTR_getLine_a7b7cf90;
  iVar6 = *(int *)(param_4 + 4);
  iVar15 = *(int *)(param_4 + 8);
  iVar14 = *(int *)(param_4 + 0xc);
  iVar13 = *(int *)(param_4 + 0x10);
  iVar12 = *(int *)(param_4 + 0x14);
  iVar11 = *(int *)(param_4 + 0x18);
  iVar10 = *(int *)(param_4 + 0x1c);
  iVar9 = *(int *)(param_4 + 0x20);
  a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[3] = iVar6;
  a0[4] = iVar15;
  a0[5] = iVar14;
  a0[6] = iVar13;
  a0[7] = iVar12;
  a0[8] = iVar11;
  a0[9] = iVar10;
  a0[10] = iVar9;
  uVar7 = a0[0xb];
  uVar2 = *(uint *)(param_4 + 0x24) & 0xfe000000;
  a0[0xb] = uVar2 | uVar7 & 0x1ffffff;
  uVar3 = (*(uint *)(param_4 + 0x24) >> 0x13 & 0x3f) << 0x13;
  a0[0xb] = uVar3 | uVar2 | uVar7 & 0x7ffff;
  uVar1 = *(uint *)(param_4 + 0x24) & 0x7f800;
  a0[0xb] = uVar1 | uVar3 | uVar2 | uVar7 & 0x7ff;
  uVar4 = (*(uint *)(param_4 + 0x24) >> 10 & 1) << 10;
  a0[0xb] = uVar4 | uVar1 | uVar3 | uVar2 | uVar7 & 0x3ff;
  puVar5 = PTR_vtable_a7b7c0dc;
  iVar6 = DAT_a7b7b9b8;
  a0[0xb] = (*(uint *)(param_4 + 0x24) >> 9 & 1) << 9 |
            uVar4 | uVar1 | uVar3 | uVar2 | uVar7 & 0x1ff;
  piVar8 = (int *)(iVar6 + 8);
  *a0 = (int)(puVar5 + 8);
  a0[0xc] = param_2;
  do {
    if (in_RESERVE != '\0') {
      iVar9 = storeWordConditionalIndexed(*piVar8 + 1,0,piVar8);
      *piVar8 = iVar9;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  iVar9 = GetGlobalPoolAllocator();
  a0[0xd] = iVar9;
  a0[0xe] = iVar6 + 0xc;
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_(a0 + 0xd,param_3);
  (**(code **)(*a0 + 4))(a0,param_5);
  return a0;
}

/* TIntermediate__addBinaryMath @ 0x97b8cce4 (2288 bytes) */
int TIntermediate__addBinaryMath(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  int param_2;
  int *param_3;
  int *param_4;
  int param_5;
  unsigned char * param_6;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined *puVar5;
  uint uVar6;
  int *piVar7;
  unsigned char * this_00;
  int *a0;
  int iVar8;
  int iVar9;
  unsigned char * pTVar10;
  int *piVar11;
  unsigned char * pTVar12;
  unsigned char * pTVar13;
  unsigned char * a0_00;
  unsigned char * a2;
  undefined4 a3;
  undefined4 a4;
  code *pcVar14;
  undefined **local_120;
  undefined4 local_11c;
  int local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  uint local_fc;
  undefined **local_f0 [2];
  int local_e8;
  uint local_cc;
  undefined **local_c0 [2];
  int local_b8;
  uint local_9c;
  undefined **local_90 [2];
  int local_88;
  uint local_6c;
  undefined **local_60 [9];
  uint local_3c;
  
  if (param_2 - 0x13U < 0x1a) {
    switch(param_2) {
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
      bVar4 = false;
      (**(code **)(*param_3 + 0x38))(&local_120,param_3);
      bVar1 = false;
      if ((local_fc >> 0x13 & 0x3f) == 0xe) {
LAB_97b8cff8:
        bVar4 = true;
        if (bVar1) goto LAB_97b8d008;
      }
      else {
        (**(code **)(*param_3 + 0x38))(local_f0,param_3);
        bVar1 = true;
        if ((local_cc >> 0x13 & 0x3f) == 3) goto LAB_97b8cff8;
LAB_97b8d008:
        local_f0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      }
      goto LAB_97b8d01c;
    default:
      goto switchD_97b8cd3c_default;
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
      bVar4 = false;
      bVar3 = false;
      bVar2 = false;
      (**(code **)(*param_3 + 0x38))
                (&local_120,param_3,param_3,param_4,param_5,param_6,(param_2 - 0x13U) * 4);
      bVar1 = false;
      if ((local_fc & 0x400) == 0) {
        bVar3 = true;
        (**(code **)(*param_3 + 0x38))(local_f0,param_3);
        if ((local_cc & 0x200) != 0) goto LAB_97b8ce68;
        bVar2 = true;
        (**(code **)(*param_3 + 0x38))(local_c0,param_3);
        if ((1 < (int)(local_9c << 0xd | local_9c >> 0x13) >> 0x18) && ((local_9c & 0x400) == 0))
        goto LAB_97b8ce68;
        bVar1 = true;
        (**(code **)(*param_3 + 0x38))(local_90,param_3);
        if ((local_6c >> 0x13 & 0x3f) == 0xe) goto LAB_97b8ce68;
      }
      else {
LAB_97b8ce68:
        bVar4 = true;
        if (!bVar1) break;
      }
      local_90[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      break;
    case 0x2a:
    case 0x2b:
    case 0x2c:
      bVar4 = false;
      bVar3 = false;
      bVar2 = false;
      (**(code **)(*param_3 + 0x38))(&local_120,param_3);
      bVar1 = false;
      if ((local_fc >> 0x13 & 0x3f) == 3) {
        bVar3 = true;
        (**(code **)(*param_3 + 0x38))(local_f0,param_3);
        if ((local_cc & 0x400) != 0) goto LAB_97b8cf4c;
        bVar2 = true;
        (**(code **)(*param_3 + 0x38))(local_c0,param_3);
        if ((local_9c & 0x200) != 0) goto LAB_97b8cf4c;
        bVar1 = true;
        (**(code **)(*param_3 + 0x38))(local_60,param_3);
        if ((1 < (int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18) && ((local_3c & 0x400) == 0))
        goto LAB_97b8cf4c;
LAB_97b8cf5c:
        local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      }
      else {
LAB_97b8cf4c:
        bVar4 = true;
        if (bVar1) goto LAB_97b8cf5c;
      }
    }
    if (bVar2) {
      local_c0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
    if (bVar3) {
      local_f0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
LAB_97b8d01c:
    local_120 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    if (bVar4) {
      return (int *)0x0;
    }
  }
switchD_97b8cd3c_default:
  bVar2 = false;
  (**(code **)(*param_3 + 0x38))(&local_120,param_3);
  bVar1 = false;
  if (local_118 == 0) {
LAB_97b8d08c:
    bVar2 = true;
    if (bVar1) goto LAB_97b8d098;
  }
  else {
    (**(code **)(*param_4 + 0x38))(local_f0,param_4);
    bVar1 = true;
    if (local_e8 == 0) goto LAB_97b8d08c;
LAB_97b8d098:
    local_f0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  }
  local_120 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (bVar2) {
    (**(code **)(*param_3 + 0x38))(local_c0,param_3);
    piVar7 = (int *)((int (*)())TIntermediate__addConversion)(this,param_2,local_c0,param_4);
    local_c0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    if (piVar7 == (int *)0x0) {
      (**(code **)(*param_4 + 0x38))(local_c0,param_4);
      param_3 = (int *)((int (*)())TIntermediate__addConversion)(this,param_2,local_c0,param_3);
      piVar7 = param_4;
      if (param_3 == (int *)0x0) {
        return (int *)0x0;
      }
    }
  }
  else {
    (**(code **)(*param_3 + 0x38))(local_c0,param_3);
    (**(code **)(*param_4 + 0x38))(local_90,param_4);
    bVar1 = false;
    if (((local_9c & 0x1fffe00) == (local_6c & 0x1fffe00)) && (local_b8 == local_88)) {
      bVar1 = true;
    }
    local_90[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    piVar7 = param_4;
    if (!bVar1) {
      return (int *)0x0;
    }
  }
  local_c0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (int *)TPoolAllocator__allocate(this_00,0x3c);
  local_fc = local_fc & 0x1ff | 0x80800;
  local_11c = 0;
  local_114 = 0;
  local_110 = 0;
  local_10c = 0;
  local_108 = 0;
  local_104 = 0;
  local_100 = 0;
  local_118 = 0;
  a0[1] = 0;
  *a0 = (int)&PTR_getLine_a7b7cf90;
  a0[3] = 0;
  a0[4] = 0;
  a0[5] = 0;
  a0[6] = 0;
  a0[7] = 0;
  a0[8] = 0;
  a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[9] = 0;
  a0[10] = 0;
  uVar6 = a0[0xb];
  a0[0xb] = uVar6 & 0x1ffffff;
  a0[0xb] = uVar6 & 0x7ffff | 0x80000;
  a0[0xb] = uVar6 & 0x7ff | 0x80800;
  a0[0xb] = uVar6 & 0x3ff | 0x80800;
  puVar5 = PTR_vtable_a7b7c0d8;
  a0[0xb] = uVar6 & 0x1ff | 0x80800;
  local_120 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[0xc] = param_2;
  *a0 = (int)(puVar5 + 8);
  if (param_5 == 0) {
    param_5 = (**(code **)*piVar7)(piVar7);
  }
  (**(code **)(*a0 + 4))(a0,param_5);
  (**(code **)(*a0 + 0x60))(a0,param_3);
  (**(code **)(*a0 + 100))(a0,piVar7);
  iVar8 = (**(code **)(*a0 + 0x5c))(a0,*(undefined4 *)this);
  if (iVar8 == 0) {
    return (int *)0x0;
  }
  iVar8 = (**(code **)(*param_3 + 0x18))(param_3);
  iVar9 = (**(code **)(*piVar7 + 0x18))(piVar7);
  pTVar10 = (unsigned char *)0x0;
  if (iVar8 != 0) {
    pTVar10 = (unsigned char *)(**(code **)(*param_3 + 0x18))(param_3);
    piVar11 = (int *)TIntermediate__copyConstUnion(this,pTVar10);
    pTVar10 = (unsigned char *)(**(code **)(*piVar11 + 0x18))(piVar11);
  }
  pTVar12 = (unsigned char *)0x0;
  if (iVar9 != 0) {
    pTVar12 = (unsigned char *)(**(code **)(*piVar7 + 0x18))(piVar7);
    piVar11 = (int *)TIntermediate__copyConstUnion(this,pTVar12);
    pTVar12 = (unsigned char *)(**(code **)(*piVar11 + 0x18))(piVar11);
  }
  bVar1 = false;
  (**(code **)(*piVar7 + 0x38))(&local_120,piVar7);
  if (local_fc >> 0x19 == 2) {
    (**(code **)(*param_3 + 0x38))(local_f0,param_3);
    bVar1 = local_cc >> 0x19 == 2;
    local_f0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  }
  local_120 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (bVar1) {
    iVar8 = (**(code **)(*piVar7 + 0x1c))(piVar7);
    if (iVar8 != 0) {
      pTVar13 = (unsigned char *)(**(code **)(*piVar7 + 0x1c))(piVar7);
      pTVar12 = (unsigned char *)TIntermediate__changeAggrToTempConst(this,pTVar13,param_6,param_5);
      if (*(int *)(pTVar12 + 0x30) == 0) {
        return (int *)0x0;
      }
    }
    iVar8 = (**(code **)(*param_3 + 0x1c))(param_3);
    if (iVar8 != 0) {
      pTVar13 = (unsigned char *)(**(code **)(*param_3 + 0x1c))(param_3);
      pTVar10 = (unsigned char *)TIntermediate__changeAggrToTempConst(this,pTVar13,param_6,param_5);
      if (*(int *)(pTVar10 + 0x30) == 0) {
        return (int *)0x0;
      }
    }
  }
  if (pTVar10 == (unsigned char *)0x0) {
    if (pTVar12 == (unsigned char *)0x0) {
      return a0;
    }
  }
  else {
    if (pTVar12 == (unsigned char *)0x0) {
      iVar8 = *a0;
      pTVar12 = (unsigned char *)TIntermediate__copyConstUnion(this,pTVar10);
      pcVar14 = *(code **)(iVar8 + 0x60);
      goto LAB_97b8d618;
    }
    iVar8 = (**(code **)(*(int *)pTVar10 + 0x4c))(pTVar10);
    if ((iVar8 == 1) && (iVar8 = (**(code **)(*(int *)pTVar12 + 0x4c))(pTVar12), 1 < iVar8)) {
      a3 = *(undefined4 *)this;
      pcVar14 = *(code **)(*(int *)pTVar12 + 0x5c);
      a4 = 0;
      a0_00 = pTVar12;
      a2 = pTVar10;
    }
    else {
      a3 = *(undefined4 *)this;
      pcVar14 = *(code **)(*(int *)pTVar10 + 0x5c);
      a4 = 1;
      a0_00 = pTVar10;
      a2 = pTVar12;
    }
    piVar7 = (int *)(*pcVar14)(a0_00,a0[0xc],a2,a3,a4);
    if (piVar7 != (int *)0x0) {
      return piVar7;
    }
    (**(code **)(*a0 + 0x60))(a0,pTVar10);
  }
  pcVar14 = *(code **)(*a0 + 100);
LAB_97b8d618:
  (*pcVar14)(a0,pTVar12);
  return a0;
}

/* TIntermediate__addAssign @ 0x97b8d63c (640 bytes) */
int TIntermediate__addAssign(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  int *param_3;
  int *param_4;
  int param_5;
{
  undefined *puVar1;
  uint uVar2;
  unsigned char * this_00;
  int *a0;
  int iVar3;
  unsigned char * pTVar4;
  int *piVar5;
  undefined **local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (int *)TPoolAllocator__allocate(this_00,0x3c);
  local_2c = local_2c & 0x1ff | 0x80800;
  local_4c = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_48 = 0;
  a0[1] = 0;
  *a0 = (int)&PTR_getLine_a7b7cf90;
  a0[3] = 0;
  a0[4] = 0;
  a0[5] = 0;
  a0[6] = 0;
  a0[7] = 0;
  a0[8] = 0;
  a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[9] = 0;
  a0[10] = 0;
  uVar2 = a0[0xb];
  a0[0xb] = uVar2 & 0x1ffffff;
  a0[0xb] = uVar2 & 0x7ffff | 0x80000;
  a0[0xb] = uVar2 & 0x7ff | 0x80800;
  a0[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d8;
  a0[0xb] = uVar2 & 0x1ff | 0x80800;
  local_50 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  *a0 = (int)(puVar1 + 8);
  a0[0xc] = param_2;
  if (param_5 == 0) {
    param_5 = (**(code **)*param_3)(param_3);
  }
  (**(code **)(*a0 + 4))(a0,param_5);
  iVar3 = (**(code **)(*param_4 + 0x18))(param_4);
  if (iVar3 != 0) {
    pTVar4 = (unsigned char *)(**(code **)(*param_4 + 0x18))(param_4);
    param_4 = (int *)TIntermediate__copyConstUnion(this,pTVar4);
    if (param_4 == (int *)0x0) {
      return (int *)0x0;
    }
  }
  (**(code **)(*param_3 + 0x38))(&local_50,param_3);
  iVar3 = ((int (*)())TIntermediate__addConversion)(this,param_2,&local_50,param_4);
  local_50 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  piVar5 = (int *)0x0;
  if (iVar3 != 0) {
    (**(code **)(*a0 + 0x60))(a0,param_3);
    (**(code **)(*a0 + 100))(a0,iVar3);
    iVar3 = (**(code **)(*a0 + 0x5c))(a0,*(undefined4 *)this);
    piVar5 = (int *)0x0;
    if (iVar3 != 0) {
      piVar5 = a0;
    }
  }
  return piVar5;
}

/* TIntermediate__addIndex @ 0x97b8d8bc (460 bytes) */
int TIntermediate__addIndex(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  undefined4 param_3;
  undefined4 *param_4;
  int param_5;
{
  undefined *puVar1;
  uint uVar2;
  unsigned char * this_00;
  int *a0;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (int *)TPoolAllocator__allocate(this_00,0x3c);
  a0[1] = 0;
  *a0 = (int)&PTR_getLine_a7b7cf90;
  a0[3] = 0;
  a0[4] = 0;
  a0[5] = 0;
  a0[6] = 0;
  a0[7] = 0;
  a0[8] = 0;
  a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[9] = 0;
  a0[10] = 0;
  uVar2 = a0[0xb];
  a0[0xb] = uVar2 & 0x1ffffff;
  a0[0xb] = uVar2 & 0x7ffff | 0x80000;
  a0[0xb] = uVar2 & 0x7ff | 0x80800;
  a0[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d8;
  a0[0xb] = uVar2 & 0x1ff | 0x80800;
  a0[0xc] = param_2;
  *a0 = (int)(puVar1 + 8);
  if (param_5 == 0) {
    param_5 = (**(code **)*param_4)(param_4);
  }
  (**(code **)(*a0 + 4))(a0,param_5);
  (**(code **)(*a0 + 0x60))(a0,param_3);
  (**(code **)(*a0 + 100))(a0,param_4);
  return a0;
}

/* TIntermediate__addUnaryMath @ 0x97b8da88 (104 bytes) */
int TIntermediate__addUnaryMath(this, param_2, param_3, param_4, param_5, param_6, param_7)
  unsigned char * this;
  int param_2;
  int *param_3;
  uint param_4;
  unsigned char * param_5;
  undefined4 param_6;
  uint param_7;
{
  undefined *puVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined **ppuVar6;
  uint uVar7;
  undefined *puVar8;
  int *a1;
  uint uVar9;
  uint uVar10;
  int iVar11;
  unsigned char * pTVar12;
  unsigned char * pTVar13;
  int *a0;
  unsigned char * this_00;
  int *a0_00;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 uVar14;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  unsigned char * a4;
  void *this_01;
  char in_RESERVE;
  byte bVar15;
  undefined **local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  char local_110 [20];
  uint local_fc;
  undefined **local_f0 [8];
  unsigned char aaStack_d0 [4];
  uint local_cc;
  undefined **local_c0 [9];
  uint local_9c;
  undefined **local_90 [9];
  uint local_6c;
  undefined **local_60 [9];
  uint local_3c;
  
  uVar7 = param_4;
  a4 = param_5;
  a1 = (int *)(**(code **)(*param_3 + 0x14))
                        (param_3,param_2,param_3,param_4,param_5,param_6,param_7);
  if (a1 == (int *)0x0) {
    this_01 = *(void **)this;
                    
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_01,"INTERNAL ERROR: ");
    uVar7 = param_4 & 0xffff;
    bVar15 = (uVar7 == 0) << 1;
    if (uVar7 == 0) {
      _sprintf(local_110,"%d:? ",(int)param_4 >> 0x10);
    }
    else {
      _sprintf(local_110,"%d:%d",(int)param_4 >> 0x10,uVar7);
    }
    __ZNSsC1EPKcRKSaIcE(&local_120,local_110,aaStack_d0);
    *(undefined *)((int)local_120 + (int)local_120[-3]) = *PTR__S_terminal_a7b7c0b8;
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_01,(char *)local_120);
    ppuVar6 = local_120 + -1;
    do {
      puVar8 = *ppuVar6;
      if (in_RESERVE != '\0') {
        puVar1 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar6);
        *ppuVar6 = puVar1;
        bVar15 = 2;
      }
    } while (!(bool)(bVar15 >> 1 & 1));
    if ((int)puVar8 < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_120 + -3),local_110);
    }
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_01,": ");
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_01,"Bad type in AddUnaryMath");
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_01,"\n");
    return (int *)0x0;
  }
  if (param_2 == 6) {
    bVar5 = false;
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    (**(code **)(*a1 + 0x38))(&local_120,a1);
    uVar14 = extraout_r4_00;
    if ((local_fc >> 0x13 & 0x3f) == 3) {
      bVar4 = true;
      (**(code **)(*a1 + 0x38))(local_c0,a1);
      uVar14 = extraout_r4_01;
      if ((local_9c & 0x400) != 0) goto LAB_97b8dcfc;
      bVar3 = true;
      (**(code **)(*a1 + 0x38))(local_90,a1);
      uVar14 = extraout_r4_02;
      if ((local_6c & 0x200) != 0) goto LAB_97b8dcfc;
      bVar2 = true;
      (**(code **)(*a1 + 0x38))(local_60,a1);
      uVar14 = extraout_r4_03;
      if ((1 < (int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18) && ((local_3c & 0x400) == 0))
      goto LAB_97b8dcfc;
LAB_97b8dd0c:
      local_60[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
    else {
LAB_97b8dcfc:
      bVar5 = true;
      if (bVar2) goto LAB_97b8dd0c;
    }
    if (bVar3) {
      local_90[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
    if (bVar4) {
      local_c0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    }
LAB_97b8ddc8:
    local_120 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    if (bVar5) {
      return (int *)0x0;
    }
  }
  else {
    uVar14 = extraout_r4;
    if (param_2 < 7) {
      if (param_2 == 5) {
LAB_97b8dd4c:
        bVar5 = false;
        (**(code **)(*a1 + 0x38))(&local_120,a1);
        bVar2 = false;
        uVar14 = extraout_r4_04;
        if ((local_fc >> 0x13 & 0x3f) == 0xe) {
LAB_97b8dda4:
          bVar5 = true;
          if (bVar2) goto LAB_97b8ddb4;
        }
        else {
          (**(code **)(*a1 + 0x38))(local_f0,a1);
          bVar2 = true;
          param_7 = local_cc & 0x200;
          uVar14 = extraout_r4_05;
          if (param_7 != 0) goto LAB_97b8dda4;
LAB_97b8ddb4:
          local_f0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        }
        goto LAB_97b8ddc8;
      }
    }
    else if (param_2 - 9U < 4) goto LAB_97b8dd4c;
  }
  if (param_2 == 0x67) {
    iVar11 = 3;
  }
  else if (param_2 < 0x68) {
    if (param_2 != 0x66) goto LAB_97b8decc;
    iVar11 = 2;
  }
  else {
    if (param_2 != 0x68) goto LAB_97b8decc;
    iVar11 = 1;
  }
  uVar7 = (**(code **)(*a1 + 0x48))(a1,uVar14,param_3,uVar7,a4,param_6,param_7);
  uVar9 = (**(code **)(*a1 + 0x50))(a1);
  uVar10 = (**(code **)(*a1 + 0x54))(a1);
  local_fc = (uVar10 & 1) << 9 |
             (uVar9 & 1) << 10 | (uVar7 & 0xff) << 0xb | iVar11 << 0x13 | local_fc & 0x1ff;
  local_110[0x10] = '\0';
  local_110[0x11] = '\0';
  local_110[0x12] = '\0';
  local_110[0x13] = '\0';
  local_120 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  local_11c = 0;
  local_118 = 0;
  local_114 = 0;
  local_110[0] = '\0';
  local_110[1] = '\0';
  local_110[2] = '\0';
  local_110[3] = '\0';
  local_110[4] = '\0';
  local_110[5] = '\0';
  local_110[6] = '\0';
  local_110[7] = '\0';
  local_110[8] = '\0';
  local_110[9] = '\0';
  local_110[10] = '\0';
  local_110[0xb] = '\0';
  local_110[0xc] = '\0';
  local_110[0xd] = '\0';
  local_110[0xe] = '\0';
  local_110[0xf] = '\0';
  a1 = (int *)((int (*)())TIntermediate__addConversion)(this,param_2,&local_120,a1);
  local_120 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (a1 == (int *)0x0) {
    return (int *)0x0;
  }
LAB_97b8decc:
  if (2 < param_2 - 0x66U) {
    iVar11 = (**(code **)(*a1 + 0x18))(a1);
    if (iVar11 != 0) {
      pTVar12 = (unsigned char *)(**(code **)(*a1 + 0x18))(a1);
      a1 = (int *)TIntermediate__copyConstUnion(this,pTVar12);
    }
    iVar11 = (**(code **)(*a1 + 0x1c))(a1);
    if (iVar11 != 0) {
      (**(code **)(*a1 + 0x38))(&local_120,a1);
      local_120 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      if (local_fc >> 0x19 == 2) {
        pTVar13 = (unsigned char *)(**(code **)(*a1 + 0x1c))(a1);
        a1 = (int *)TIntermediate__changeAggrToTempConst(this,pTVar13,param_5,param_4);
        iVar11 = (**(code **)(*a1 + 0x18))(a1);
        if (*(int *)(iVar11 + 0x30) == 0) {
          return (int *)0x0;
        }
      }
    }
    a0 = (int *)(**(code **)(*a1 + 0x18))(a1);
    this_00 = (unsigned char *)GetGlobalPoolAllocator();
    a0_00 = (int *)TPoolAllocator__allocate(this_00,0x38);
    local_fc = local_fc & 0x1ff | 0x80800;
    local_11c = 0;
    local_118 = 0;
    local_114 = 0;
    local_110[0] = '\0';
    local_110[1] = '\0';
    local_110[2] = '\0';
    local_110[3] = '\0';
    local_110[4] = '\0';
    local_110[5] = '\0';
    local_110[6] = '\0';
    local_110[7] = '\0';
    local_110[8] = '\0';
    local_110[9] = '\0';
    local_110[10] = '\0';
    local_110[0xb] = '\0';
    local_110[0xc] = '\0';
    local_110[0xd] = '\0';
    local_110[0xe] = '\0';
    local_110[0xf] = '\0';
    local_110[0x10] = '\0';
    local_110[0x11] = '\0';
    local_110[0x12] = '\0';
    local_110[0x13] = '\0';
    *a0_00 = (int)&PTR_getLine_a7b7cf90;
    a0_00[1] = 0;
    a0_00[3] = 0;
    a0_00[4] = 0;
    a0_00[5] = 0;
    a0_00[6] = 0;
    a0_00[7] = 0;
    a0_00[8] = 0;
    a0_00[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
    a0_00[9] = 0;
    a0_00[10] = 0;
    uVar7 = a0_00[0xb];
    a0_00[0xb] = uVar7 & 0x1ffffff;
    a0_00[0xb] = uVar7 & 0x7ffff | 0x80000;
    a0_00[0xb] = uVar7 & 0x7ff | 0x80800;
    a0_00[0xb] = uVar7 & 0x3ff | 0x80800;
    puVar8 = PTR_vtable_a7b7c0d4;
    a0_00[0xb] = uVar7 & 0x1ff | 0x80800;
    local_120 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    *a0_00 = (int)(puVar8 + 8);
    a0_00[0xd] = 0;
    a0_00[0xc] = param_2;
    if (param_4 == 0) {
      param_4 = (**(code **)*a1)(a1);
    }
    (**(code **)(*a0_00 + 4))(a0_00,param_4);
    (**(code **)(*a0_00 + 0x60))(a0_00,a1);
    iVar11 = (**(code **)(*a0_00 + 0x5c))(a0_00,*(undefined4 *)this);
    a1 = (int *)0x0;
    if ((iVar11 != 0) &&
       ((a0 == (int *)0x0 ||
        (a1 = (int *)(**(code **)(*a0 + 0x5c))(a0,param_2,0,*(undefined4 *)this,1), a1 == (int *)0x0
        )))) {
      a1 = a0_00;
    }
  }
  return a1;
}

/* TIntermediate__setAggregateOperator @ 0x97b8e1b8 (1132 bytes) */
int TIntermediate__setAggregateOperator(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_2;
  undefined4 param_3;
  int param_4;
{
  unsigned int ghidra_home[8] = { this, param_2, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool bVar1;
  undefined *puVar2;
  uint uVar3;
  int *piVar4;
  int *a0;
  unsigned char * pTVar5;
  int iVar6;
  int iVar7;
  unsigned char * this_00;
  undefined4 *puVar8;
  code *pcVar9;
  char in_RESERVE;
  byte bVar10;
  unsigned char * pTStack0000001c;
  
  bVar10 = (param_2 == (unsigned char *)0x0) << 1;
  pTStack0000001c = param_2;
  if (param_2 == (unsigned char *)0x0) {
    pTVar5 = (unsigned char *)GetGlobalPoolAllocator();
    a0 = (int *)TPoolAllocator__allocate(pTVar5,0x6c);
    a0[1] = 0;
    *a0 = (int)&PTR_getLine_a7b7cf90;
    a0[3] = 0;
    a0[4] = 0;
    a0[5] = 0;
    a0[6] = 0;
    a0[7] = 0;
    a0[8] = 0;
    a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
    a0[9] = 0;
    a0[10] = 0;
    uVar3 = a0[0xb];
    a0[0xb] = uVar3 & 0x1ffffff;
    a0[0xb] = uVar3 & 0x7ffff | 0x80000;
    a0[0xb] = uVar3 & 0x7ff | 0x80800;
    a0[0xb] = uVar3 & 0x3ff | 0x80800;
    puVar2 = PTR_vtable_a7b7c0d0;
    a0[0xb] = uVar3 & 0x1ff | 0x80800;
    *a0 = (int)(puVar2 + 8);
    a0[0xc] = 0;
    iVar6 = GetGlobalPoolAllocator();
    a0[0x10] = 0;
    a0[0xe] = 0;
    a0[0xf] = 0;
    a0[0xd] = iVar6;
    iVar6 = GetGlobalPoolAllocator();
    a0[0x11] = iVar6;
    iVar6 = DAT_a7b7b9b8;
    a0[0x14] = 0;
    a0[0x12] = 0;
    piVar4 = (int *)(iVar6 + 8);
    a0[0x13] = 0;
    do {
      if (in_RESERVE != '\0') {
        iVar7 = storeWordConditionalIndexed(*piVar4 + 1,0,piVar4);
        *piVar4 = iVar7;
        bVar10 = 2;
      }
    } while (!(bool)(bVar10 >> 1 & 1));
    iVar7 = GetGlobalPoolAllocator();
    a0[0x16] = iVar6 + 0xc;
    bVar1 = param_4 == 0;
    a0[0x1a] = 0;
    a0[0x15] = iVar7;
    a0[0x17] = 0;
  }
  else {
    a0 = (int *)(**(code **)(*(int *)param_2 + 0x1c))(param_2);
    bVar10 = (a0 == (int *)0x0) << 1;
    if ((a0 == (int *)0x0) || (bVar1 = param_4 == 0, a0[0xc] != 0)) {
      pTVar5 = (unsigned char *)GetGlobalPoolAllocator();
      a0 = (int *)TPoolAllocator__allocate(pTVar5,0x6c);
      a0[1] = 0;
      *a0 = (int)&PTR_getLine_a7b7cf90;
      a0[3] = 0;
      a0[4] = 0;
      a0[5] = 0;
      a0[6] = 0;
      a0[7] = 0;
      a0[8] = 0;
      a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
      a0[9] = 0;
      a0[10] = 0;
      uVar3 = a0[0xb];
      a0[0xb] = uVar3 & 0x1ffffff;
      a0[0xb] = uVar3 & 0x7ffff | 0x80000;
      a0[0xb] = uVar3 & 0x7ff | 0x80800;
      a0[0xb] = uVar3 & 0x3ff | 0x80800;
      puVar2 = PTR_vtable_a7b7c0d0;
      a0[0xb] = uVar3 & 0x1ff | 0x80800;
      *a0 = (int)(puVar2 + 8);
      a0[0xc] = 0;
      iVar6 = GetGlobalPoolAllocator();
      a0[0x10] = 0;
      a0[0xe] = 0;
      a0[0xf] = 0;
      a0[0xd] = iVar6;
      iVar6 = GetGlobalPoolAllocator();
      a0[0x11] = iVar6;
      iVar6 = DAT_a7b7b9b8;
      a0[0x14] = 0;
      a0[0x12] = 0;
      piVar4 = (int *)(iVar6 + 8);
      a0[0x13] = 0;
      do {
        if (in_RESERVE != '\0') {
          iVar7 = storeWordConditionalIndexed(*piVar4 + 1,0,piVar4);
          *piVar4 = iVar7;
          bVar10 = 2;
        }
      } while (!(bool)(bVar10 >> 1 & 1));
      iVar7 = GetGlobalPoolAllocator();
      a0[0x16] = iVar6 + 0xc;
      a0[0x15] = iVar7;
      pcVar9 = *(code **)(*a0 + 100);
      a0[0x1a] = 0;
      a0[0x17] = 0;
      this_00 = (unsigned char *)(*pcVar9)(a0);
      puVar8 = *(undefined4 **)(this_00 + 8);
      if (puVar8 == *(undefined4 **)(this_00 + 0xc)) {
        std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                  (this_00,puVar8,&(*(unsigned int *)((unsigned char *)ghidra_home + 4)));
      }
      else {
        iVar6 = 0;
        if (puVar8 != (undefined4 *)0x0) {
          *puVar8 = pTStack0000001c;
          iVar6 = *(int *)(this_00 + 8);
        }
        *(int *)(this_00 + 8) = iVar6 + 4;
      }
      bVar1 = false;
      if (param_4 == 0) {
        param_4 = (*(code *)**(undefined4 **)pTStack0000001c)(pTStack0000001c);
        bVar1 = param_4 == 0;
      }
    }
  }
  (**(code **)(*a0 + 0x60))(a0,param_3);
  if (!bVar1) {
    (**(code **)(*a0 + 4))(a0,param_4);
  }
  return a0;
}

/* TIntermediate__addConversion @ 0x97b8e624 (2488 bytes) */
int TIntermediate__addConversion(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  unsigned char * param_3;
  int *param_4;
{
  undefined *puVar1;
  bool bVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  unsigned char * pTVar9;
  unsigned char * pcVar10;
  int iVar11;
  int *piVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  undefined4 a1;
  undefined4 a1_00;
  undefined4 a1_01;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  unsigned char * a2;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 *a6;
  unsigned char * pTVar16;
  char *pcVar17;
  undefined4 *puVar18;
  uint uVar19;
  void *this_00;
  char in_RESERVE;
  byte bVar20;
  undefined **local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  uint local_9c;
  undefined4 local_90;
  undefined4 *puStack_8c;
  char acStack_80 [64];
  longlong local_40;
  undefined1 auStack_38 [4];
  int local_34;
  
  a2 = param_3;
  piVar12 = param_4;
  iVar6 = (**(code **)(*param_4 + 0x40))(param_4,param_2,param_3,param_4);
  if (iVar6 == 0) {
    return (int *)0x0;
  }
  if ((-1 < iVar6) && (iVar6 - 5U < 8)) {
    return (int *)0x0;
  }
  (**(code **)(*param_4 + 0x38))(&local_c0,param_4);
  a6 = (undefined4 *)0x0;
  if (((*(uint *)(param_3 + 0x24) & 0x1fffe00) == (local_9c & 0x1fffe00)) &&
     (*(int *)(param_3 + 8) == local_b8)) {
    a6 = (undefined4 *)0x1;
  }
  local_c0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (a6 != (undefined4 *)0x0) {
    return param_4;
  }
  if (*(int *)(param_3 + 8) != 0) {
    return (int *)0x0;
  }
  (**(code **)(*param_4 + 0x38))((unsigned char *)&local_c0,param_4,a2,piVar12,in_r7,in_r8,0);
  local_c0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (local_b8 != 0) {
    return (int *)0x0;
  }
  iVar6 = (**(code **)(*(int *)param_3 + 0x38))(param_3);
  if (iVar6 != 0) {
    return (int *)0x0;
  }
  (**(code **)(*param_4 + 0x38))((unsigned char *)&local_c0,param_4);
  local_c0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if ((local_9c & 0x200) != 0) {
    return (int *)0x0;
  }
  if (param_2 == 0x67) {
    uVar7 = 3;
  }
  else if (param_2 < 0x68) {
    if (param_2 != 0x66) {
LAB_97b8e794:
      uVar7 = (**(code **)(*(int *)param_3 + 0x20))(param_3);
      (**(code **)(*param_4 + 0x38))(&local_c0,param_4);
      if (uVar7 == (local_9c >> 0x13 & 0x3f)) {
        return param_4;
      }
      return (int *)0x0;
    }
    uVar7 = 2;
  }
  else {
    if (param_2 != 0x68) goto LAB_97b8e794;
    uVar7 = 1;
  }
  bVar2 = true;
  iVar6 = (**(code **)(*param_4 + 0x1c))(param_4);
  if (iVar6 == 0) {
LAB_97b8e8ac:
    iVar6 = (**(code **)(*param_4 + 0x1c))(param_4);
    if (iVar6 != 0) {
      piVar8 = (int *)(**(code **)(*param_4 + 0x1c))(param_4);
      iVar6 = (**(code **)(*piVar8 + 100))(piVar8);
      pTVar16 = *(unsigned char **)(iVar6 + 4);
      while( true ) {
        if (pTVar16 == *(unsigned char **)(iVar6 + 8)) {
          piVar12 = (int *)(**(code **)(*param_4 + 0x1c))(param_4);
          return piVar12;
        }
        pTVar9 = (unsigned char *)GetGlobalPoolAllocator();
        pcVar10 = (unsigned char *)TPoolAllocator__allocate(pTVar9,4);
        if (uVar7 != 2) break;
        piVar8 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
        (**(code **)(*piVar8 + 0x38))(&local_c0,piVar8);
        uVar19 = local_9c >> 0x13 & 0x3f;
        local_c0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (uVar19 == 1) {
          piVar12 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
          iVar11 = (**(code **)(*piVar12 + 0x18))(piVar12);
          local_40 = (longlong)(int)**(float **)(iVar11 + 0x30);
          *(int *)pcVar10 = (int)**(float **)(iVar11 + 0x30);
LAB_97b8ec88:
          local_9c = uVar7 << 0x13 | local_9c & 0x7ff | 0x4000000 | 0x800;
        }
        else {
          if (uVar19 != 3) {
            this_00 = *(void **)this;
            pcVar17 = "Bad promotion node";
            uVar7 = (**(code **)*param_4)(param_4,a1_00,a2,piVar12,in_r7,in_r8,a6);
                    
            goto override_jmp_97b8ea8c_case_0;
          }
          piVar12 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
          iVar11 = (**(code **)(*piVar12 + 0x18))(piVar12);
          a6 = *(undefined4 **)(iVar11 + 0x30);
          *(undefined4 *)pcVar10 = *a6;
LAB_97b8ecd8:
          local_9c = uVar7 << 0x13 | local_9c & 0xfff | 0x4000000 | 0x800;
        }
LAB_97b8ed90:
        local_9c = local_9c & 0xfffff9ff;
        local_bc = 0;
        local_b8 = 0;
        local_b4 = 0;
        local_b0 = 0;
        local_ac = 0;
        local_a8 = 0;
        local_a4 = 0;
        local_a0 = 0;
        local_c0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        piVar12 = (int *)(**(code **)*param_4)(param_4);
        a2 = (unsigned char *)&local_c0;
        iVar11 = ((int (*)())TIntermediate__addConstantUnion)(this,pcVar10,(unsigned char *)&local_c0,(int)piVar12);
        local_c0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (iVar11 != 0) {
          std__vector_TIntermNode__pool_allocator_TIntermNode_____erase(auStack_38,iVar6,pTVar16);
          piVar12 = &local_34;
          a2 = pTVar16;
          local_34 = iVar11;
          std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                    (auStack_38,iVar6,pTVar16,piVar12);
        }
        pTVar16 = pTVar16 + 4;
      }
      if (uVar7 < 3) {
        if (uVar7 == 1) {
          piVar8 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
          (**(code **)(*piVar8 + 0x38))(&local_c0,piVar8);
          uVar19 = local_9c >> 0x13 & 0x3f;
          local_c0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
          if (uVar19 == 2) {
            piVar12 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
            iVar11 = (**(code **)(*piVar12 + 0x18))(piVar12);
            a6 = (undefined4 *)(**(uint **)(iVar11 + 0x30) ^ 0x80000000);
            *(float *)pcVar10 = (float)((double)CONCAT44(0x43300000,a6) - 4503601774854144.0);
          }
          else {
            if (uVar19 != 3) {
              this_00 = *(void **)this;
              pcVar17 = "Bad promotion node";
              uVar7 = (**(code **)*param_4)(param_4,a1,a2,piVar12,in_r7,in_r8,a6);
                    
              goto override_jmp_97b8ea8c_case_0;
            }
            piVar12 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))
                                       (*(int **)pTVar16,a1,a2,piVar12,in_r7,in_r8,a6);
            iVar11 = (**(code **)(*piVar12 + 0x18))(piVar12);
            a6 = (undefined4 *)**(undefined4 **)(iVar11 + 0x30);
            *(float *)pcVar10 = (float)((double)CONCAT44(0x43300000,a6) - 4503599627370496.0);
          }
          local_90 = 0x43300000;
          local_9c = local_9c & 0x7ff | 0x4080800;
          puStack_8c = a6;
          goto LAB_97b8ed90;
        }
      }
      else if (uVar7 == 3) {
        piVar8 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
        (**(code **)(*piVar8 + 0x38))(&local_c0,piVar8);
        uVar19 = local_9c >> 0x13 & 0x3f;
        local_c0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
        if (uVar19 == 1) {
          piVar12 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
          iVar11 = (**(code **)(*piVar12 + 0x18))(piVar12);
          *(uint *)pcVar10 = (uint)(**(float **)(iVar11 + 0x30) != 0.0);
          goto LAB_97b8ec88;
        }
        if (uVar19 == 2) {
          piVar12 = (int *)(**(code **)(**(int **)pTVar16 + 0x14))(*(int **)pTVar16);
          iVar11 = (**(code **)(*piVar12 + 0x18))(piVar12);
          iVar11 = **(int **)(iVar11 + 0x30);
          a6 = (undefined4 *)(iVar11 + -1);
          *(uint *)pcVar10 = iVar11 - ((int)a6 + (uint)(iVar11 == 0));
          goto LAB_97b8ecd8;
        }
        this_00 = *(void **)this;
        pcVar17 = "Bad promotion node";
        uVar7 = (**(code **)*param_4)(param_4,a1_01,a2,piVar12,in_r7,in_r8,a6);
                    
        goto override_jmp_97b8ea8c_case_0;
      }
      this_00 = *(void **)this;
      pcVar17 = "Bad promotion node";
      uVar7 = (**(code **)*param_4)(param_4);
                    
      goto override_jmp_97b8ea8c_case_0;
    }
  }
  else {
    iVar6 = (**(code **)(*param_4 + 0x1c))(param_4);
    if (*(int *)(iVar6 + 0x30) == 2) {
      bVar2 = false;
    }
    else {
      piVar8 = (int *)(**(code **)(*param_4 + 0x1c))(param_4);
      iVar6 = (**(code **)(*piVar8 + 100))(piVar8);
      for (puVar18 = *(undefined4 **)(iVar6 + 4); puVar18 != *(undefined4 **)(iVar6 + 8);
          puVar18 = puVar18 + 1) {
        piVar8 = (int *)(**(code **)(*(int *)*puVar18 + 0x14))((int *)*puVar18);
        iVar11 = (**(code **)(*piVar8 + 0x18))(piVar8);
        if (iVar11 == 0) {
          bVar2 = false;
        }
      }
    }
    if (bVar2) goto LAB_97b8e8ac;
  }
  iVar6 = (**(code **)(*param_4 + 0x18))(param_4);
  if (iVar6 != 0) {
    uVar13 = (**(code **)(*param_4 + 0x18))(param_4);
    piVar12 = (int *)TIntermediate__promoteConstantUnion(this,uVar7,uVar13);
    return piVar12;
  }
  if (uVar7 != 2) {
    if (uVar7 < 3) {
      if (uVar7 == 1) {
        iVar6 = (**(code **)(*param_4 + 0x40))(param_4);
        uVar13 = extraout_r4;
        if (iVar6 == 2) {
          iVar11 = 0x10;
        }
        else {
          iVar11 = 0xf;
          if (iVar6 != 3) {
            this_00 = *(void **)this;
            pcVar17 = "Bad promotion node";
            uVar7 = (**(code **)*param_4)(param_4);
                    
            goto override_jmp_97b8ea8c_case_0;
          }
        }
        goto LAB_97b8f1ac;
      }
    }
    else if (uVar7 == 3) {
      iVar6 = (**(code **)(*param_4 + 0x40))(param_4);
      uVar13 = extraout_r4_00;
      if (iVar6 == 1) {
        iVar11 = 0xe;
      }
      else {
        iVar11 = 0xd;
        if (iVar6 != 2) {
          this_00 = *(void **)this;
          pcVar17 = "Bad promotion node";
          uVar7 = (**(code **)*param_4)(param_4);
                    
          goto override_jmp_97b8ea8c_case_0;
        }
      }
      goto LAB_97b8f1ac;
    }
    this_00 = *(void **)this;
    pcVar17 = "Bad promotion type";
    uVar7 = (**(code **)*param_4)(param_4);
                    
override_jmp_97b8ea8c_case_0:
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_00,"INTERNAL ERROR: ");
    uVar19 = uVar7 & 0xffff;
    bVar20 = (uVar19 == 0) << 1;
    if (uVar19 == 0) {
      _sprintf(acStack_80,"%d:? ",(int)uVar7 >> 0x10);
    }
    else {
      _sprintf(acStack_80,"%d:%d",(int)uVar7 >> 0x10,uVar19);
    }
    __ZNSsC1EPKcRKSaIcE(&local_c0,acStack_80,(unsigned char *)&local_b0);
    *(undefined *)((int)local_c0 + (int)local_c0[-3]) = *PTR__S_terminal_a7b7c0b8;
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_00,(char *)local_c0);
    ppuVar3 = local_c0 + -1;
    do {
      puVar4 = *ppuVar3;
      if (in_RESERVE != '\0') {
        puVar1 = (undefined *)storeWordConditionalIndexed(puVar4 + -1,0,ppuVar3);
        *ppuVar3 = puVar1;
        bVar20 = 2;
      }
    } while (!(bool)(bVar20 >> 1 & 1));
    if ((int)puVar4 < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_c0 + -3),(unsigned char *)&local_b0);
    }
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_00,": ");
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_00,pcVar17);
    ((int (*)())__ZN13TInfoSinkBase6appendEPKc)(this_00,"\n");
    return (int *)0x0;
  }
  iVar6 = (**(code **)(*param_4 + 0x40))(param_4);
  uVar13 = extraout_r4_01;
  if (iVar6 == 1) {
    iVar11 = 0x11;
  }
  else {
    iVar11 = 0x12;
    if (iVar6 != 3) {
      this_00 = *(void **)this;
      pcVar17 = "Bad promotion node";
      uVar7 = (**(code **)*param_4)(param_4);
                    
      goto override_jmp_97b8ea8c_case_0;
    }
  }
LAB_97b8f1ac:
  uVar19 = (**(code **)(*param_4 + 0x48))(param_4,uVar13);
  uVar14 = (**(code **)(*param_4 + 0x50))(param_4);
  uVar15 = (**(code **)(*param_4 + 0x54))(param_4);
  local_c0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  local_9c = (uVar15 & 1) << 9 |
             (uVar14 & 1) << 10 | (uVar19 & 0xff) << 0xb | uVar7 << 0x13 | local_9c & 0x1ff;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  pTVar9 = (unsigned char *)GetGlobalPoolAllocator();
  piVar12 = (int *)TPoolAllocator__allocate(pTVar9,0x38);
  piVar12[1] = 0;
  *piVar12 = (int)&PTR_getLine_a7b7cf90;
  piVar12[3] = local_bc;
  piVar12[4] = local_b8;
  piVar12[5] = local_b4;
  piVar12[6] = local_b0;
  piVar12[7] = local_ac;
  piVar12[8] = local_a8;
  piVar12[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  piVar12[10] = local_a0;
  piVar12[9] = local_a4;
  puVar4 = PTR_vtable_a7b7c0d4;
  uVar5 = piVar12[0xb];
  uVar19 = local_9c & 0xfe000000;
  piVar12[0xb] = uVar19 | uVar5 & 0x1ffffff;
  uVar14 = (local_9c >> 0x13 & 0x3f) << 0x13;
  piVar12[0xb] = uVar14 | uVar19 | uVar5 & 0x7ffff;
  uVar7 = local_9c & 0x7f800;
  piVar12[0xb] = uVar7 | uVar14 | uVar19 | uVar5 & 0x7ff;
  uVar15 = (local_9c >> 10 & 1) << 10;
  piVar12[0xb] = uVar15 | uVar7 | uVar14 | uVar19 | uVar5 & 0x3ff;
  piVar12[0xb] = (local_9c >> 9 & 1) << 9 | uVar15 | uVar7 | uVar14 | uVar19 | uVar5 & 0x1ff;
  piVar12[0xc] = iVar11;
  *piVar12 = (int)(puVar4 + 8);
  piVar12[0xd] = 0;
  uVar13 = (**(code **)*param_4)(param_4);
  (**(code **)(puVar4 + 0xc))(piVar12,uVar13);
  (**(code **)(*piVar12 + 0x60))(piVar12,param_4);
  return piVar12;
}

/* TIntermediate__growAggregate @ 0x97b8f36c (760 bytes) */
int TIntermediate__growAggregate(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
{
  unsigned int ghidra_home[8] = { this, param_2, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  int *a0;
  unsigned char * this_00;
  int iVar4;
  int iVar5;
  unsigned char * pvVar6;
  undefined4 *puVar7;
  char in_RESERVE;
  byte in_cr0;
  unsigned char * pTStack0000001c;
  unsigned char * pTStack00000020;
  
  if ((param_2 == (unsigned char *)0x0) && (param_3 == (unsigned char *)0x0)) {
    return (int *)0x0;
  }
  pTStack0000001c = param_2;
  pTStack00000020 = param_3;
  if (param_2 != (unsigned char *)0x0) {
    a0 = (int *)(**(code **)(*(int *)param_2 + 0x1c))(param_2);
    in_cr0 = (a0 == (int *)0x0) << 1;
    if ((a0 != (int *)0x0) && (a0[0xc] == 0)) goto LAB_97b8f5cc;
  }
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (int *)TPoolAllocator__allocate(this_00,0x6c);
  a0[1] = 0;
  *a0 = (int)&PTR_getLine_a7b7cf90;
  a0[3] = 0;
  a0[4] = 0;
  a0[5] = 0;
  a0[6] = 0;
  a0[7] = 0;
  a0[8] = 0;
  a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[9] = 0;
  a0[10] = 0;
  uVar2 = a0[0xb];
  a0[0xb] = uVar2 & 0x1ffffff;
  a0[0xb] = uVar2 & 0x7ffff | 0x80000;
  a0[0xb] = uVar2 & 0x7ff | 0x80800;
  a0[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d0;
  a0[0xb] = uVar2 & 0x1ff | 0x80800;
  *a0 = (int)(puVar1 + 8);
  a0[0xc] = 0;
  iVar4 = GetGlobalPoolAllocator();
  a0[0x10] = 0;
  a0[0xe] = 0;
  a0[0xf] = 0;
  a0[0xd] = iVar4;
  iVar4 = GetGlobalPoolAllocator();
  a0[0x11] = iVar4;
  iVar4 = DAT_a7b7b9b8;
  a0[0x14] = 0;
  a0[0x12] = 0;
  piVar3 = (int *)(iVar4 + 8);
  a0[0x13] = 0;
  do {
    if (in_RESERVE != '\0') {
      iVar5 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar5;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  iVar5 = GetGlobalPoolAllocator();
  a0[0x16] = iVar4 + 0xc;
  a0[0x15] = iVar5;
  a0[0x1a] = 0;
  a0[0x17] = 0;
  if (pTStack0000001c != (unsigned char *)0x0) {
    pvVar6 = (unsigned char *)(**(code **)(*a0 + 100))(a0);
    puVar7 = *(undefined4 **)(pvVar6 + 8);
    if (puVar7 == *(undefined4 **)(pvVar6 + 0xc)) {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                (pvVar6,puVar7,&(*(unsigned int *)((unsigned char *)ghidra_home + 4)));
    }
    else {
      iVar4 = 0;
      if (puVar7 != (undefined4 *)0x0) {
        *puVar7 = pTStack0000001c;
        iVar4 = *(int *)(pvVar6 + 8);
      }
      *(int *)(pvVar6 + 8) = iVar4 + 4;
    }
  }
LAB_97b8f5cc:
  if (pTStack00000020 != (unsigned char *)0x0) {
    pvVar6 = (unsigned char *)(**(code **)(*a0 + 100))(a0);
    puVar7 = *(undefined4 **)(pvVar6 + 8);
    if (puVar7 == *(undefined4 **)(pvVar6 + 0xc)) {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                (pvVar6,puVar7,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
    }
    else {
      iVar4 = 0;
      if (puVar7 != (undefined4 *)0x0) {
        *puVar7 = pTStack00000020;
        iVar4 = *(int *)(pvVar6 + 8);
      }
      *(int *)(pvVar6 + 8) = iVar4 + 4;
    }
  }
  if (param_4 != 0) {
    (**(code **)(*a0 + 4))(a0,param_4);
  }
  return a0;
}

/* TIntermediate__makeAggregate @ 0x97b8f664 (632 bytes) */
int TIntermediate__makeAggregate(this, param_2, param_3)
  unsigned char * this;
  unsigned char * param_2;
  int param_3;
{
  unsigned int ghidra_home[8] = { this, param_2, param_3, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  int *a0;
  unsigned char * this_00;
  int iVar4;
  int iVar5;
  unsigned char * this_01;
  undefined4 *a1;
  undefined4 *extraout_r4;
  code *pcVar6;
  char in_RESERVE;
  byte in_cr0;
  unsigned char * pTStack0000001c;
  
  a0 = (int *)0x0;
  if (param_2 != (unsigned char *)0x0) {
    pTStack0000001c = param_2;
    this_00 = (unsigned char *)GetGlobalPoolAllocator();
    a0 = (int *)TPoolAllocator__allocate(this_00,0x6c);
    a0[1] = 0;
    *a0 = (int)&PTR_getLine_a7b7cf90;
    a0[3] = 0;
    a0[4] = 0;
    a0[5] = 0;
    a0[6] = 0;
    a0[7] = 0;
    a0[8] = 0;
    a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
    a0[9] = 0;
    a0[10] = 0;
    uVar2 = a0[0xb];
    a0[0xb] = uVar2 & 0x1ffffff;
    a0[0xb] = uVar2 & 0x7ffff | 0x80000;
    a0[0xb] = uVar2 & 0x7ff | 0x80800;
    a0[0xb] = uVar2 & 0x3ff | 0x80800;
    puVar1 = PTR_vtable_a7b7c0d0;
    a0[0xb] = uVar2 & 0x1ff | 0x80800;
    *a0 = (int)(puVar1 + 8);
    a0[0xc] = 0;
    iVar4 = GetGlobalPoolAllocator();
    a0[0x10] = 0;
    a0[0xe] = 0;
    a0[0xf] = 0;
    a0[0xd] = iVar4;
    iVar4 = GetGlobalPoolAllocator();
    a0[0x11] = iVar4;
    iVar4 = DAT_a7b7b9b8;
    a0[0x14] = 0;
    a0[0x12] = 0;
    piVar3 = (int *)(iVar4 + 8);
    a0[0x13] = 0;
    do {
      if (in_RESERVE != '\0') {
        iVar5 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
        *piVar3 = iVar5;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    iVar5 = GetGlobalPoolAllocator();
    a0[0x16] = iVar4 + 0xc;
    a0[0x15] = iVar5;
    pcVar6 = *(code **)(*a0 + 100);
    a0[0x1a] = 0;
    a0[0x17] = 0;
    this_01 = (unsigned char *)(*pcVar6)(a0);
    a1 = *(undefined4 **)(this_01 + 8);
    if (a1 == *(undefined4 **)(this_01 + 0xc)) {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                (this_01,a1,&(*(unsigned int *)((unsigned char *)ghidra_home + 4)));
      a1 = extraout_r4;
    }
    else {
      iVar4 = 0;
      if (a1 != (undefined4 *)0x0) {
        *a1 = pTStack0000001c;
        iVar4 = *(int *)(this_01 + 8);
      }
      *(int *)(this_01 + 8) = iVar4 + 4;
    }
    if (param_3 == 0) {
      iVar4 = *a0;
      param_3 = (*(code *)**(undefined4 **)pTStack0000001c)(pTStack0000001c,a1);
      pcVar6 = *(code **)(iVar4 + 4);
    }
    else {
      pcVar6 = *(code **)(*a0 + 4);
    }
    (*pcVar6)(a0,param_3);
  }
  return a0;
}

/* __ZN13TIntermediate12addSelectionEP12TIntermTyped15TIntermNodePairi @ 0x97b8f8dc (516 bytes) */
int __ZN13TIntermediate12addSelectionEP12TIntermTyped15TIntermNodePairi(param_1, param_2, param_3, param_4, param_5)
  unsigned char * param_1;
  int *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
  undefined4 param_5;
{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  unsigned char * this;
  undefined4 *a0;
  undefined *a6;
  code *pcVar5;
  undefined4 *puStack00000020;
  undefined4 *puStack00000024;
  
  puStack00000020 = param_3;
  puStack00000024 = param_4;
  iVar3 = (**(code **)(*param_2 + 0x14))(param_2,param_2,param_3,param_4,param_5);
  if (iVar3 != 0) {
    piVar4 = (int *)(**(code **)(*param_2 + 0x14))(param_2);
    iVar3 = (**(code **)(*piVar4 + 0x18))(piVar4);
    if (iVar3 != 0) {
      piVar4 = (int *)(**(code **)(*param_2 + 0x14))(param_2);
      iVar3 = (**(code **)(*piVar4 + 0x18))(piVar4);
      if (**(int **)(iVar3 + 0x30) == 0) {
        return puStack00000024;
      }
      return puStack00000020;
    }
  }
  this = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (undefined4 *)TPoolAllocator__allocate(this,0x3c);
  *a0 = &PTR_getLine_a7b7cf90;
  a0[1] = 0;
  a0[3] = 0;
  a0[4] = 0;
  a0[5] = 0;
  a0[6] = 0;
  a0[7] = 0;
  a0[8] = 0;
  a0[2] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[10] = 0;
  a0[9] = 0;
  uVar2 = a0[0xb];
  a0[0xb] = uVar2 & 0x1ffffff;
  puVar1 = PTR_vtable_a7b7c0cc;
  a6 = PTR_vtable_a7b7c0cc + 8;
  a0[0xb] = uVar2 & 0x7ffff;
  pcVar5 = *(code **)(puVar1 + 0xc);
  a0[0xb] = uVar2 & 0x7ff | 0x800;
  a0[0xb] = uVar2 & 0x3ff | 0x800;
  a0[0xb] = uVar2 & 0x1ff | 0x800;
  a0[0xc] = param_2;
  a0[0xd] = puStack00000020;
  a0[0xe] = puStack00000024;
  *a0 = a6;
  (*pcVar5)(a0,param_5,param_3,param_4,puStack00000024,puStack00000020,a6,
            &PTR___ZN5TTypeD1Ev_a7b7cff8);
  return a0;
}

/* TIntermediate__addComma @ 0x97b8fae0 (348 bytes) */
int TIntermediate__addComma(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
{
  bool bVar1;
  unsigned char * pTVar2;
  int *piVar3;
  int a3;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined **local_b0 [9];
  uint local_8c;
  undefined **local_80 [9];
  uint local_5c;
  undefined **local_50 [13];
  
  bVar1 = false;
  pTVar2 = param_3;
  a3 = param_4;
  (**(code **)(*(int *)param_2 + 0x38))(local_b0,param_2,param_3,param_4);
  if (local_8c >> 0x19 == 2) {
    (**(code **)(*(int *)param_3 + 0x38))(local_80,param_3,pTVar2,a3,in_r7,in_r8,0xa7b7faf0);
    bVar1 = local_5c >> 0x19 == 2;
    local_80[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  }
  local_b0[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  pTVar2 = param_3;
  if (!bVar1) {
    pTVar2 = (unsigned char *)
             ((int (*)())TIntermediate__growAggregate)(this,(unsigned char *)param_2,(unsigned char *)param_3,param_4);
    piVar3 = (int *)(**(code **)(*(int *)pTVar2 + 0x1c))(pTVar2);
    (**(code **)(*piVar3 + 0x60))(piVar3,0x25);
    (**(code **)(*(int *)param_3 + 0x38))(local_50,param_3);
    (**(code **)(*(int *)pTVar2 + 0x34))(pTVar2,local_50);
    local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    piVar3 = (int *)(**(code **)(*(int *)pTVar2 + 0x3c))(pTVar2);
    (**(code **)(*piVar3 + 0x28))(piVar3,0);
  }
  return pTVar2;
}

/* __ZN13TIntermediate12addSelectionEP12TIntermTypedS1_S1_i @ 0x97b8fc3c (628 bytes) */
int __ZN13TIntermediate12addSelectionEP12TIntermTypedS1_S1_i(this, param_2, param_3, param_4, param_5)
  void *this;
  unsigned char * param_2;
  unsigned char * param_3;
  unsigned char * param_4;
  int param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  unsigned char * this_00;
  unsigned char * pTVar9;
  undefined4 a1;
  undefined ***a2;
  undefined ***a0;
  unsigned char * a3;
  undefined4 in_r8;
  unsigned char * a0_00;
  undefined8 uVar10;
  undefined **local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
  
  a0 = &local_60;
  iVar8 = param_5;
  (**(code **)(*(int *)param_3 + 0x38))(&local_60,param_3,param_3,param_4,param_5);
  a2 = &local_60;
  a3 = param_4;
  uVar10 = ((int (*)())TIntermediate__addConversion)(this,1,a2,param_4);
  a0_00 = (unsigned char *)((ulonglong)uVar10 >> 0x20);
  a1 = (undefined4)uVar10;
  local_60 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  if (a0_00 == (unsigned char *)0x0) {
    (**(code **)(*(int *)param_4 + 0x38))(a0,param_4);
    pTVar9 = (unsigned char *)((int (*)())TIntermediate__addConversion)(this,1,a0,param_3);
    a1 = 0;
    a2 = a0;
    a3 = param_3;
    a0_00 = param_4;
    param_3 = pTVar9;
    if (pTVar9 == (unsigned char *)0x0) {
      return (unsigned char *)0x0;
    }
  }
  local_60 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  iVar7 = (**(code **)(*(int *)param_2 + 0x18))(param_2,a1);
  if (((iVar7 == 0) || (iVar7 = (**(code **)(*(int *)param_3 + 0x18))(param_3), iVar7 == 0)) ||
     (iVar7 = (**(code **)(*(int *)a0_00 + 0x18))(a0_00), iVar7 == 0)) {
    this_00 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar9 = (unsigned char *)TPoolAllocator__allocate(this_00,0x3c);
    (**(code **)(*(int *)param_3 + 0x38))(&local_60,param_3);
    *(int *)(pTVar9 + 4) = 0;
    *(undefined ***)pTVar9 = &PTR_getLine_a7b7cf90;
    *(int *)(pTVar9 + 0xc) = local_5c;
    *(int *)(pTVar9 + 0x10) = local_58;
    *(int *)(pTVar9 + 0x14) = local_54;
    *(int *)(pTVar9 + 0x18) = local_50;
    *(int *)(pTVar9 + 0x1c) = local_4c;
    *(int *)(pTVar9 + 0x20) = local_48;
    *(undefined ***)(pTVar9 + 8) = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    *(int *)(pTVar9 + 0x24) = local_44;
    *(int *)(pTVar9 + 0x28) = local_40;
    uVar6 = *(uint *)(pTVar9 + 0x2c);
    uVar2 = local_3c & 0xfe000000;
    *(uint *)(pTVar9 + 0x2c) = uVar2 | uVar6 & 0x1ffffff;
    uVar3 = (local_3c >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar9 + 0x2c) = uVar3 | uVar2 | uVar6 & 0x7ffff;
    uVar1 = local_3c & 0x7f800;
    *(uint *)(pTVar9 + 0x2c) = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
    uVar4 = (local_3c >> 10 & 1) << 10;
    *(uint *)(pTVar9 + 0x2c) = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
    puVar5 = PTR_vtable_a7b7c0cc;
    *(uint *)(pTVar9 + 0x2c) =
         (local_3c >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff;
    *(unsigned char **)(pTVar9 + 0x30) = param_2;
    *(undefined **)pTVar9 = puVar5 + 8;
    *(unsigned char **)(pTVar9 + 0x34) = param_3;
    *(unsigned char **)(pTVar9 + 0x38) = a0_00;
    local_60 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
    (**(code **)(*(int *)pTVar9 + 4))(pTVar9,param_5,a2,a3,iVar8,in_r8,pTVar9 + 8);
  }
  else {
    iVar8 = (**(code **)(*(int *)param_2 + 0x18))(param_2);
    pTVar9 = param_3;
    if (**(int **)(iVar8 + 0x30) == 0) {
      pTVar9 = a0_00;
    }
  }
  return pTVar9;
}

/* TIntermediate__addConstantUnion @ 0x97b8feb0 (300 bytes) */
int TIntermediate__addConstantUnion(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined *puVar7;
  unsigned char * this_00;
  undefined4 *a0;
  undefined4 uVar8;
  undefined4 a2;
  undefined4 a3;
  undefined4 a4;
  undefined4 a5;
  undefined4 uVar9;
  uint a6;
  undefined4 a7;
  code *pcVar10;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (undefined4 *)TPoolAllocator__allocate(this_00,0x34);
  a0[1] = 0;
  *a0 = &PTR_getLine_a7b7cf90;
  uVar5 = *(undefined4 *)(param_3 + 4);
  uVar9 = *(undefined4 *)(param_3 + 8);
  uVar8 = *(undefined4 *)(param_3 + 0x20);
  a7 = *(undefined4 *)(param_3 + 0xc);
  a5 = *(undefined4 *)(param_3 + 0x10);
  a4 = *(undefined4 *)(param_3 + 0x14);
  a3 = *(undefined4 *)(param_3 + 0x18);
  a2 = *(undefined4 *)(param_3 + 0x1c);
  a0[2] = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[3] = uVar5;
  a0[10] = uVar8;
  a0[4] = uVar9;
  a0[5] = a7;
  a0[6] = a5;
  a0[7] = a4;
  a0[8] = a3;
  a0[9] = a2;
  uVar6 = a0[0xb];
  uVar2 = *(uint *)(param_3 + 0x24) & 0xfe000000;
  a0[0xb] = uVar2 | uVar6 & 0x1ffffff;
  uVar3 = (*(uint *)(param_3 + 0x24) >> 0x13 & 0x3f) << 0x13;
  a0[0xb] = uVar3 | uVar2 | uVar6 & 0x7ffff;
  uVar1 = *(uint *)(param_3 + 0x24) & 0x7f800;
  a0[0xb] = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
  uVar4 = (*(uint *)(param_3 + 0x24) >> 10 & 1) << 10;
  a0[0xb] = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
  puVar7 = PTR_vtable_a7b7c0c8 + 8;
  a6 = *(uint *)(param_3 + 0x24) >> 9 & 1;
  pcVar10 = *(code **)(PTR_vtable_a7b7c0c8 + 0xc);
  a0[0xb] = a6 << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff;
  a0[0xc] = param_2;
  *a0 = puVar7;
  (*pcVar10)(a0,param_4,a2,a3,a4,a5,a6,a7);
  return a0;
}

/* TIntermediate__addSwizzle @ 0x97b8ffdc (744 bytes) */
int TIntermediate__addSwizzle(this, param_2, param_3)
  unsigned char * this;
  unsigned char * param_2;
  int param_3;
{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  unsigned char * pTVar5;
  int *a0;
  unsigned char * this_00;
  unsigned char * pcVar6;
  undefined4 *puVar7;
  code *pcVar8;
  int iVar9;
  unsigned char * pTVar10;
  char in_RESERVE;
  byte in_cr0;
  undefined **local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  uint local_8c;
  int local_80;
  int local_70;
  int local_60;
  undefined4 local_50 [6];
  
  pTVar5 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (int *)TPoolAllocator__allocate(pTVar5,0x6c);
  local_8c = local_8c & 0x1ff | 0x80800;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  *a0 = (int)&PTR_getLine_a7b7cf90;
  a0[1] = 0;
  a0[3] = 0;
  a0[4] = 0;
  a0[5] = 0;
  a0[6] = 0;
  a0[7] = 0;
  a0[8] = 0;
  a0[9] = 0;
  a0[2] = (int)&PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[10] = 0;
  uVar2 = a0[0xb];
  a0[0xb] = uVar2 & 0x1ffffff;
  a0[0xb] = uVar2 & 0x7ffff | 0x80000;
  a0[0xb] = uVar2 & 0x7ff | 0x80800;
  a0[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d0;
  a0[0xb] = uVar2 & 0x1ff | 0x80800;
  local_b0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
  a0[0xc] = 1;
  *a0 = (int)(puVar1 + 8);
  local_80 = GetGlobalPoolAllocator();
  a0[0x10] = 0;
  a0[0xe] = 0;
  a0[0xf] = 0;
  a0[0xd] = local_80;
  local_70 = GetGlobalPoolAllocator();
  a0[0x11] = local_70;
  iVar9 = DAT_a7b7b9b8;
  a0[0x14] = 0;
  a0[0x12] = 0;
  piVar3 = (int *)(iVar9 + 8);
  a0[0x13] = 0;
  do {
    if (in_RESERVE != '\0') {
      iVar4 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar4;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  local_60 = GetGlobalPoolAllocator();
  a0[0x16] = iVar9 + 0xc;
  iVar9 = 0;
  a0[0x15] = local_60;
  pcVar8 = *(code **)(*a0 + 4);
  a0[0x1a] = 0;
  (*pcVar8)(a0,param_3);
  this_00 = (unsigned char *)(**(code **)(*a0 + 100))(a0);
  if (0 < *(int *)(param_2 + 0x10)) {
    pTVar10 = param_2;
    do {
      pTVar5 = (unsigned char *)GetGlobalPoolAllocator();
      pcVar6 = (unsigned char *)TPoolAllocator__allocate(pTVar5,4);
      *(undefined4 *)pcVar6 = *(undefined4 *)pTVar10;
      local_8c = local_8c & 0x1ff | 0x4100800;
      pTVar10 = pTVar10 + 4;
      local_b0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      local_ac = 0;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_50[0] = ((int (*)())TIntermediate__addConstantUnion)(this,pcVar6,(unsigned char *)&local_b0,param_3);
      local_b0 = &PTR___ZN5TTypeD1Ev_a7b7cff8;
      puVar7 = *(undefined4 **)(this_00 + 8);
      if (puVar7 == *(undefined4 **)(this_00 + 0xc)) {
        std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                  (this_00,puVar7,local_50);
      }
      else {
        iVar4 = 0;
        if (puVar7 != (undefined4 *)0x0) {
          *puVar7 = local_50[0];
          iVar4 = *(int *)(this_00 + 8);
        }
        *(int *)(this_00 + 8) = iVar4 + 4;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < *(int *)(param_2 + 0x10));
  }
  return a0;
}

/* TIntermediate__addLoop @ 0x97b902c4 (140 bytes) */
int TIntermediate__addLoop(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
  unsigned char * param_4;
  undefined4 param_5;
  int param_6;
{
  undefined *puVar1;
  unsigned char * this_00;
  undefined4 *a0;
  code *pcVar2;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (undefined4 *)TPoolAllocator__allocate(this_00,0x18);
  puVar1 = PTR_vtable_a7b7c0c4;
  a0[1] = 0;
  a0[2] = param_2;
  pcVar2 = *(code **)(puVar1 + 0xc);
  a0[3] = param_3;
  a0[4] = param_4;
  a0[5] = param_5;
  *a0 = puVar1 + 8;
  (*pcVar2)(a0,param_6);
  return a0;
}

/* __ZN13TIntermediate9addBranchE9TOperatori @ 0x97b90350 (12 bytes) */
int __ZN13TIntermediate9addBranchE9TOperatori(this, param_2, param_3)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())__ZN13TIntermediate9addBranchE9TOperatorP12TIntermTypedi)(this,param_2,0,param_3);
  return;
}

/* __ZN13TIntermediate9addBranchE9TOperatorP12TIntermTypedi @ 0x97b9035c (124 bytes) */
int __ZN13TIntermediate9addBranchE9TOperatorP12TIntermTypedi(this, param_2, param_3, param_4)
  void *this;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined *puVar1;
  unsigned char * this_00;
  undefined4 *a0;
  code *pcVar2;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  a0 = (undefined4 *)TPoolAllocator__allocate(this_00,0x10);
  puVar1 = PTR_vtable_a7b7c0c0;
  a0[1] = 0;
  a0[2] = param_2;
  pcVar2 = *(code **)(puVar1 + 0xc);
  a0[3] = param_3;
  *a0 = puVar1 + 8;
  (*pcVar2)(a0,param_4);
  return a0;
}

/* TIntermediate__postProcess @ 0x97b903d8 (96 bytes) */
int TIntermediate__postProcess(param_1, param_2)
  unsigned char * param_1;
  int *param_2;
{
  int *a0;
  
  if (((param_2 != (int *)0x0) &&
      (a0 = (int *)(**(code **)(*param_2 + 0x1c))(param_2), a0 != (int *)0x0)) && (a0[0xc] == 0)) {
    (**(code **)(*a0 + 0x60))(a0,1);
  }
  return 1;
}

/* TIntermediate__remove @ 0x97b90438 (12 bytes) */
int TIntermediate__remove(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  if (param_2 == (unsigned char *)0x0) {
    return;
  }
  RemoveAllTreeNodes(param_2);
  return;
}

/* TIntermOperator__modifiesState @ 0x97b90444 (48 bytes) */
int TIntermOperator__modifiesState(this)
  unsigned char * this;
{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x30);
  if ((8 < iVar1) && ((iVar1 < 0xd || (iVar1 - 0x76U < 0xf)))) {
    return 1;
  }
  return 0;
}

