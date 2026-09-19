#include "decls.h"

/* _lFloatConst @ 0x97b88c98 (588 bytes) */
int _lFloatConst(param_1, param_2, param_3, param_4)
  char *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined *puVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  double dVar9;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  iVar5 = 0;
  iVar6 = 0;
  iVar8 = param_2;
  if (param_3 == 0x2e) {
    param_1[param_2] = '.';
    iVar8 = param_2 + 1;
    iVar3 = *(int *)(*(int *)puVar1 + 0x20);
    param_3 = (**(code **)(iVar3 + 8))(iVar3,param_4);
    uVar7 = param_3 - 0x30;
    while (uVar7 < 10) {
      if (iVar8 < 0x80) {
        iVar5 = iVar5 + 1;
        if ((0 < iVar8) || (param_3 != 0x30)) {
          param_1[iVar8] = (char)param_3;
          param_2 = param_2 + 1;
          iVar8 = iVar8 + 1;
        }
        iVar3 = *(int *)(*(int *)puVar1 + 0x20);
        param_3 = (**(code **)(iVar3 + 8))(iVar3,param_4);
        uVar7 = param_3 - 0x30;
      }
      else {
        iVar8 = 1;
        param_2 = 1;
        _CPPErrorToInfoLog("ERROR___FP_CONST_TOO_LONG");
      }
    }
  }
  puVar1 = PTR__cpp_a7b7c0a4;
  if ((param_3 != 0x65) && (param_3 != 0x45)) goto LAB_97b88e60;
  param_1[iVar8] = (char)param_3;
  iVar3 = iVar8 + 1;
  iVar4 = 1;
  param_3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 8))
                      (*(int *)(*(int *)puVar1 + 0x20),param_4);
  if (param_3 == 0x2b) {
    param_1[iVar3] = '+';
    iVar3 = *(int *)puVar1;
LAB_97b88de8:
    param_3 = (**(code **)(*(int *)(iVar3 + 0x20) + 8))(*(int *)(iVar3 + 0x20),param_4);
    iVar3 = iVar8 + 2;
  }
  else if (param_3 == 0x2d) {
    param_1[iVar3] = '-';
    iVar3 = *(int *)puVar1;
    iVar4 = -1;
    goto LAB_97b88de8;
  }
  iVar8 = iVar3;
  puVar1 = PTR__cpp_a7b7c0a4;
  if (param_3 - 0x30U < 10) {
    do {
      param_1[iVar8] = (char)param_3;
      iVar8 = iVar8 + 1;
      iVar6 = iVar6 * 10 + param_3 + -0x30;
      param_3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 8))
                          (*(int *)(*(int *)puVar1 + 0x20),param_4);
    } while (param_3 - 0x30U < 10);
  }
  else {
    _CPPErrorToInfoLog("ERROR___ERROR_IN_EXPONENT");
  }
  iVar6 = iVar6 * iVar4;
LAB_97b88e60:
  if (iVar8 == 0) {
    builtin_strncpy(param_1,"0.0",4);
    fVar2 = 0.0;
  }
  else {
    param_1[iVar8] = '\0';
    dVar9 = (double)((double (*)())_lBuildFloatValue)(param_1,param_2,iVar6 - iVar5);
    fVar2 = (float)dVar9;
  }
  *(float *)(param_4 + 4) = fVar2;
  _strcpy((char *)(param_4 + 0xc),param_1);
  (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 0xc))
            (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_3,param_4);
  return 0x10b;
}

/* _byte_scan @ 0x97b88ee4 (3060 bytes) */
int _byte_scan(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  undefined1 local_2d0 [144];
  undefined1 local_240 [536];
  
  uVar6 = 0;
  iVar8 = *(int *)PTR__cpp_a7b7c0a4;
LAB_97b88f18:
  *param_2 = 0;
  iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
  while (((iVar3 == 0x20 || (iVar3 == 9)) || (iVar3 == 0xd))) {
    *param_2 = 1;
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
  }
  if (iVar3 != -1) {
    *(undefined2 *)(iVar8 + 0x30) = *(undefined2 *)(*(int *)(iVar8 + 0x20) + 0x12);
    *(undefined2 *)(iVar8 + 0x32) = *(undefined2 *)(*(int *)(iVar8 + 0x20) + 0x16);
  }
  iVar9 = 0;
  switch(iVar3) {
  default:
    return iVar3;
  case 0x21:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x21;
    }
    return 0x113;
  case 0x22:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    bVar1 = iVar3 == 0x22;
    if (((bVar1) || (iVar3 == 10)) || (iVar3 == -1)) goto LAB_97b89c74;
    puVar7 = local_240;
    goto LAB_97b89bf4;
  case 0x25:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 == 0x3d) {
      return 0x104;
    }
    if (iVar3 != 0x3e) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x25;
    }
    return 0x120;
  case 0x26:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 == 0x26) {
      return 0x101;
    }
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x26;
    }
    return 0x11a;
  case 0x2a:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x2a;
    }
    return 0x107;
  case 0x2b:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 == 0x2b) {
      return 0x115;
    }
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x2b;
    }
    return 0x105;
  case 0x2d:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 == 0x2d) {
      return 0x112;
    }
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x2d;
    }
    return 0x103;
  case 0x2e:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (9 < iVar3 - 0x30U) {
      if (iVar3 != 0x2e) {
        (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
        return 0x2e;
      }
      return -1;
    }
    (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
    iVar9 = 0;
    iVar4 = 0x2e;
    goto LAB_97b89a54;
  case 0x2f:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 != 0x2f) break;
    do {
      iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
      if (iVar3 == 10) {
        return 10;
      }
    } while (iVar3 != -1);
switchD_97b88fcc_caseD_ffffffff:
    return -1;
  case 0x30:
    *(char *)(param_2 + 3) = (char)iVar3;
    iVar9 = 1;
    iVar4 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if ((iVar4 == 0x78) || (iVar4 == 0x58)) {
      *(char *)((int)param_2 + 0xd) = (char)iVar4;
      iVar9 = 2;
      iVar4 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
      uVar5 = iVar4 - 0x30;
      if ((uVar5 < 10) || ((iVar4 - 0x41U < 6 || (iVar4 - 0x61U < 6)))) {
        puVar7 = (undefined1 *)((int)param_2 + 0xe);
        bVar1 = false;
        uVar6 = 0;
        do {
          *puVar7 = (char)iVar4;
          iVar9 = iVar9 + 1;
          puVar7 = puVar7 + 1;
          if ((int)uVar6 < 0x10000000) {
            if ((9 < uVar5) && (uVar5 = iVar4 - 0x37, 5 < iVar4 - 0x41U)) {
              uVar5 = iVar4 - 0x57;
            }
            uVar6 = uVar6 << 4 | uVar5;
          }
          else {
            if (!bVar1) {
              _CPPErrorToInfoLog("ERROR___HEX_CONST_OVERFLOW");
            }
            bVar1 = true;
          }
          iVar4 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
          uVar5 = iVar4 - 0x30;
        } while (((uVar5 < 10) || (iVar4 - 0x41U < 6)) || (iVar4 - 0x61U < 6));
      }
      else {
        _CPPErrorToInfoLog("ERROR___ERROR_IN_HEX_CONSTANT");
      }
      goto LAB_97b89458;
    }
    uVar5 = iVar4 - 0x30;
    if (uVar5 < 8) {
      bVar1 = false;
      uVar6 = 0;
      puVar7 = (undefined1 *)((int)param_2 + 0xd);
      do {
        *puVar7 = (char)iVar4;
        iVar9 = iVar9 + 1;
        puVar7 = puVar7 + 1;
        if ((int)uVar6 < 0x20000000) {
          uVar6 = uVar6 << 3 | uVar5;
        }
        else {
          if (!bVar1) {
            _CPPErrorToInfoLog("ERROR___OCT_CONST_OVERFLOW");
          }
          bVar1 = true;
        }
        iVar4 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
        uVar5 = iVar4 - 0x30;
      } while (uVar5 < 8);
      if ((((iVar4 == 0x2e) || (iVar4 == 0x65)) ||
          ((iVar4 == 0x66 || ((iVar4 == 0x68 || (iVar4 == 0x78)))))) || (iVar4 == 0x45))
      goto LAB_97b89a54;
LAB_97b89458:
      *(undefined1 *)((int)param_2 + iVar9 + 0xc) = 0;
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar4,param_2);
      *param_2 = uVar6;
      return 0x10f;
    }
    iVar3 = 0x30;
    (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar4,param_2);
switchD_97b88fcc_caseD_31:
    puVar7 = (undefined1 *)((int)param_2 + iVar9 + 0xc);
    iVar4 = iVar3;
    do {
      if (iVar9 < 0x80) {
        if ((0 < iVar9) || (iVar4 != 0x30)) {
          *puVar7 = (char)iVar4;
          iVar9 = iVar9 + 1;
          puVar7 = puVar7 + 1;
        }
        iVar4 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
      }
    } while (iVar4 - 0x30U < 10);
    if (((((iVar4 != 0x2e) && (iVar4 != 0x65)) && (iVar4 != 0x66)) &&
        ((iVar4 != 0x68 && (iVar4 != 0x78)))) && (iVar4 != 0x45)) {
      *(undefined1 *)((int)param_2 + iVar9 + 0xc) = 0;
      uVar6 = 0;
      bVar1 = false;
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar4,param_2);
      if (0 < iVar9) {
        puVar10 = param_2 + 3;
        do {
          cVar2 = *(char *)puVar10;
          puVar10 = (uint *)((int)puVar10 + 1);
          if ((0xccccccc < (int)uVar6) || ((uVar6 == 0xccccccc && (7 < cVar2 + -0x30)))) {
            if (!bVar1) {
              _CPPErrorToInfoLog("ERROR___INTEGER_CONST_OVERFLOW");
            }
            bVar1 = true;
          }
          iVar9 = iVar9 + -1;
          uVar6 = uVar6 * 10 + cVar2 + -0x30;
        } while (iVar9 != 0);
      }
      *param_2 = uVar6;
      if (uVar6 == 0) {
        *(undefined2 *)(param_2 + 3) = 0x3000;
      }
      return 0x10f;
    }
LAB_97b89a54:
    iVar8 = ((int (*)())_lFloatConst)(param_2 + 3,iVar9,iVar4,param_2);
    return iVar8;
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
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 != 0x3e) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x3a;
    }
    return 0x11e;
  case 0x3c:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 == 0x3c) {
      iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
      if (iVar3 != 0x3d) {
        (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
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
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x3c;
    }
    return 0x11d;
  case 0x3d:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x3d;
    }
    return 0x108;
  case 0x3e:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 != 0x3e) {
      if (iVar3 != 0x3d) {
        (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
        return 0x3e;
      }
      return 0x10c;
    }
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x10d;
    }
    return 0x118;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5f:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
    bVar1 = false;
    do {
      if (!bVar1) {
        local_2d0[iVar9] = (char)iVar3;
        iVar9 = iVar9 + 1;
        bVar1 = 0x7f < iVar9;
      }
      iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    } while (((iVar3 - 0x61U < 0x1a) || (iVar3 - 0x41U < 0x1a)) ||
            ((iVar3 - 0x30U < 10 || (iVar3 == 0x5f))));
    if (bVar1) {
      iVar9 = 0x7f;
    }
    local_2d0[iVar9] = 0;
    (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
    uVar6 = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,local_2d0);
    param_2[2] = uVar6;
    return 0x10e;
  case 0x5e:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 == 0x5e) {
      return 0x109;
    }
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x5e;
    }
    return 0x11c;
  case 0x7c:
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar3 == 0x7c) {
      return 0x114;
    }
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x7c;
    }
    return 0x11b;
  case -1:
    goto switchD_97b88fcc_caseD_ffffffff;
  }
  if (iVar3 != 0x2a) {
    if (iVar3 != 0x3d) {
      (**(code **)(*(int *)(iVar8 + 0x20) + 0xc))(*(int *)(iVar8 + 0x20),iVar3,param_2);
      return 0x2f;
    }
    return 0x106;
  }
  iVar3 = 0;
  iVar9 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
  do {
    while (iVar9 != 0x2a) {
      if (iVar9 == 10) {
        iVar3 = iVar3 + 1;
      }
      if (iVar9 == -1) {
LAB_97b89b60:
        _CPPErrorToInfoLog("ERROR___EOF_IN_COMMENT");
        return -1;
      }
      iVar9 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    }
    iVar9 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    if (iVar9 == -1) goto LAB_97b89b60;
  } while (iVar9 != 0x2f);
  if (iVar3 != 0) {
    return 10;
  }
  goto LAB_97b88f18;
LAB_97b89bf4:
  if (iVar3 == 0x5c) {
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
    bVar1 = iVar3 == 0x22;
    if ((iVar3 == 10) || (iVar3 == -1)) {
LAB_97b89c74:
      local_240[iVar9] = 0;
      if (!bVar1) {
        _CPPErrorToInfoLog("ERROR___CPP_EOL_IN_STRING");
        return 0x10a;
      }
      uVar6 = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,local_240);
      param_2[2] = uVar6;
      return 0x116;
    }
  }
  if (iVar9 < 0x200) {
    *puVar7 = (char)iVar3;
    iVar9 = iVar9 + 1;
    puVar7 = puVar7 + 1;
    iVar3 = (**(code **)(*(int *)(iVar8 + 0x20) + 8))(*(int *)(iVar8 + 0x20),param_2);
  }
  bVar1 = iVar3 == 0x22;
  if (((bVar1) || (iVar3 == 10)) || (iVar3 == -1)) goto LAB_97b89c74;
  goto LAB_97b89bf4;
}

/* _yylex_CPP @ 0x97b89cd0 (452 bytes) */
int _yylex_CPP(param_1, param_2)
  char *param_1;
  size_t param_2;
{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  size_t sVar7;
  undefined1 auStack_b0 [8];
  int local_a8;
  char acStack_a4 [136];
  
  puVar2 = PTR__atable_a7b7c0ac;
  puVar1 = PTR__cpp_a7b7c0a4;
  do {
    do {
      while( true ) {
        while( true ) {
          iVar3 = (**(code **)(*(int *)(*(int *)puVar1 + 0x20) + 4))
                            (*(int *)(*(int *)puVar1 + 0x20),auStack_b0);
          iVar4 = ((int (*)())_check_EOF)();
          if (iVar4 != 0) {
            return 0;
          }
          if (iVar3 != 0x23) break;
          if ((*(int *)(*(int *)puVar1 + 0x24) != 10) && (*(int *)(*(int *)puVar1 + 0x24) != 0)) {
            _CPPErrorToInfoLog(
                              "preprocessor command must not be preceded by any other statement in that line"
                              );
            return 0;
          }
          _readCPPline(auStack_b0);
          iVar3 = ((int (*)())_check_EOF)();
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
      sVar7 = _strlen(pcVar6);
      if ((int)sVar7 < (int)param_2) {
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
  
  puVar1 = PTR__cpp_a7b7c0a4;
  uVar2 = 0;
  if (param_1 == -1) {
    if (0 < *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x34)) {
      _CPPErrorToInfoLog("#endif missing!! Compilation stopped");
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
  int unaff_r2;
  
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
  int iVar3;
  
  puVar2 = (undefined4 *)_mem_Alloc(*(undefined4 *)(param_2 + 0x10),0x28);
  puVar2[2] = 0;
  puVar2[3] = param_3;
  iVar3 = 0x10;
  *puVar2 = 0;
  puVar2[1] = 0;
  uVar1 = *param_1;
  puVar2[5] = param_4;
  puVar2[4] = uVar1;
  puVar2 = puVar2 + 6;
  do {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
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
  int *piVar5;
  
  puVar1 = PTR__atable_a7b7c0ac;
  piVar5 = (int *)*param_1;
  if (piVar5 == (int *)0x0) {
    *param_1 = param_2;
  }
  else {
    iVar3 = _GetReversedAtom(*(undefined4 *)PTR__atable_a7b7c0ac,*(undefined4 *)(param_2 + 0xc));
    do {
      iVar4 = _GetReversedAtom(*(undefined4 *)puVar1,piVar5[3]);
      if (iVar4 == iVar3) {
        _CPPErrorToInfoLog("GetAtomString(atable, fSymb->name)");
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
int _AddSymbol(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    param_2 = _CurrentScope;
  }
  uVar1 = ((int (*)())_NewSymbol)(param_1,param_2);
  ((int (*)())_lAddToTree)(param_2 + 0x14,uVar1);
  return uVar1;
}

/* _LookUpLocalSymbol @ 0x97b8a230 (148 bytes) */
int _LookUpLocalSymbol(param_1)
  int param_1;
{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  puVar1 = PTR__atable_a7b7c0ac;
  iVar2 = _GetReversedAtom(*(undefined4 *)PTR__atable_a7b7c0ac);
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
  size_t sVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  
  sVar3 = _strlen((char *)param_1);
  if (param_2 == 0) {
    pbVar4 = _malloc(sVar3 + 1);
  }
  else {
    pbVar4 = (byte *)_mem_Alloc(param_2,sVar3 + 1);
  }
  puVar2 = PTR_DAT_a7b7c0a8;
  bVar1 = *param_1;
  pbVar7 = pbVar4;
  do {
    if (bVar1 == 0) {
      *pbVar7 = 0;
      return pbVar4;
    }
    uVar5 = (uint)(char)bVar1;
    if ((uVar5 & 0xffffff80) == 0) {
      uVar5 = -(*(uint *)(puVar2 + uVar5 * 4 + 0x34) & 0x500) >> 0x1f;
    }
    else {
      iVar6 = ___maskrune(uVar5,0x500);
      uVar5 = (uint)(iVar6 != 0);
    }
    if (uVar5 == 0) {
      if (*param_1 - 0x2e < 2) {
        *pbVar7 = 0x5f;
        goto LAB_97b8a3f8;
      }
    }
    else {
      *pbVar7 = *param_1;
LAB_97b8a3f8:
      pbVar7 = pbVar7 + 1;
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
    puVar1 = _malloc(0x114);
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
  return;
}

/* _lAddByte @ 0x97b8a4b0 (92 bytes) */
int _lAddByte(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  iVar1 = *(int *)(iVar2 + 8);
  if (*(int *)(iVar2 + 0xc) <= iVar1) {
    iVar2 = ((int (*)())_lNewBlock)(param_1,0);
    iVar1 = *(int *)(iVar2 + 8);
  }
  *(undefined1 *)(*(int *)(iVar2 + 0x10) + iVar1) = param_2;
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
    puVar1 = _malloc(0x10);
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
  void *param_1;
{
  undefined4 *puVar1;
  void *pvVar2;
  
  if (param_1 == (void *)0x0) {
    return;
  }
  puVar1 = *(void **)((int)param_1 + 8);
  while (puVar1 != (void *)0x0) {
    pvVar2 = (void *)*puVar1;
    _free(puVar1);
    puVar1 = pvVar2;
  }
  if (*(void **)((int)param_1 + 4) != (void *)0x0) {
    _free(*(void **)((int)param_1 + 4));
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
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  
  if ((int)param_2 < 0x101) {
    uVar2 = param_2 & 0x7f;
  }
  else {
    uVar2 = (param_2 & 0x7f) - 0x80 & 0xff;
  }
  ((int (*)())_lAddByte)(param_1,uVar2);
  if (param_2 == 0x10e) {
LAB_97b8a6cc:
    pcVar3 = (char *)_GetAtomString(*(undefined4 *)PTR__atable_a7b7c0ac,param_3[2]);
    cVar1 = *pcVar3;
    while (cVar1 != '\0') {
      ((int (*)())_lAddByte)(param_1);
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    }
  }
  else {
    if ((int)param_2 < 0x10f) {
      if (param_2 == 0x28) {
        ((int (*)())_lAddByte)(param_1,*param_3 != 0);
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
    piVar4 = param_3 + 3;
    cVar1 = *(char *)(param_3 + 3);
    while (cVar1 != '\0') {
      ((int (*)())_lAddByte)(param_1,cVar1);
      piVar4 = (int *)((int)piVar4 + 1);
      cVar1 = *(char *)piVar4;
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
  int *param_2;
{
  uint uVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  double dVar8;
  char local_2c0 [144];
  char local_230 [532];
  
  iVar2 = ((int (*)())_lReadByte)();
  if (iVar2 < 0) {
    return -1;
  }
  if (0x7f < iVar2) {
    iVar2 = iVar2 + 0x80;
  }
  if (iVar2 == 0x10e) {
LAB_97b8a810:
    iVar7 = 0;
    cVar3 = ((int (*)())_lReadByte)(param_1);
    iVar5 = (int)cVar3;
    uVar1 = iVar5 - 0x61;
    while (((((uVar1 & 0xff) < 0x1a || (iVar5 - 0x41U < 0x1a)) || (iVar5 - 0x30U < 10)) ||
           (iVar5 == 0x5f))) {
      if (iVar7 < 0x80) {
        local_2c0[iVar7] = (char)iVar5;
        cVar3 = ((int (*)())_lReadByte)(param_1);
        iVar7 = iVar7 + 1;
        iVar5 = (int)cVar3;
        uVar1 = iVar5 - 0x61;
      }
    }
    local_2c0[iVar7] = '\0';
    if (iVar5 == 0) {
      iVar2 = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,local_2c0);
      param_2[2] = iVar2;
      return 0x10e;
    }
    uVar4 = 0x140;
LAB_97b8aac8:
    ___eprintf("%s:%u: failed assertion `%s\'\n",
               "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/preprocessor/tokens.c"
               ,uVar4,"ch == \'\\0\'");
  }
  else {
    if (iVar2 < 0x10f) {
      if (iVar2 == 0x28) {
        iVar7 = ((int (*)())_lReadByte)(param_1);
        goto LAB_97b8aaf0;
      }
      if (iVar2 != 0x10b) {
        return iVar2;
      }
      iVar7 = 0;
      cVar3 = ((int (*)())_lReadByte)(param_1);
      iVar5 = (int)cVar3;
      uVar1 = iVar5 - 0x30;
      while (((((uVar1 & 0xff) < 10 || (iVar5 == 0x65)) ||
              ((iVar5 == 0x45 || ((iVar5 == 0x2e || (iVar5 == 0x2b)))))) || (iVar5 == 0x2d))) {
        if (iVar7 < 0x80) {
          local_2c0[iVar7] = (char)iVar5;
          cVar3 = ((int (*)())_lReadByte)(param_1);
          iVar7 = iVar7 + 1;
          iVar5 = (int)cVar3;
          uVar1 = iVar5 - 0x30;
        }
      }
      local_2c0[iVar7] = '\0';
      if (iVar5 == 0) {
        _strcpy((char *)(param_2 + 3),local_2c0);
        dVar8 = (double)((double (*)())_glp_strtod)(param_2 + 3,0);
        param_2[1] = (int)(float)dVar8;
        return 0x10b;
      }
      uVar4 = 0x158;
      goto LAB_97b8aac8;
    }
    if (iVar2 == 0x116) {
      iVar2 = 0;
      pcVar6 = local_230;
      while (cVar3 = ((int (*)())_lReadByte)(param_1), cVar3 != '\0') {
        if (iVar2 < 0x200) {
          *pcVar6 = cVar3;
          iVar2 = iVar2 + 1;
          pcVar6 = pcVar6 + 1;
        }
      }
      local_230[iVar2] = '\0';
      iVar2 = _LookUpAddString(*(undefined4 *)PTR__atable_a7b7c0ac,local_230);
      param_2[2] = iVar2;
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
    iVar7 = 0;
    cVar3 = ((int (*)())_lReadByte)(param_1);
    iVar5 = (int)cVar3;
    uVar1 = iVar5 - 0x30;
    while ((uVar1 & 0xff) < 10) {
      if (iVar7 < 0x80) {
        local_2c0[iVar7] = (char)iVar5;
        cVar3 = ((int (*)())_lReadByte)(param_1);
        iVar7 = iVar7 + 1;
        iVar5 = (int)cVar3;
        uVar1 = iVar5 - 0x30;
      }
    }
    local_2c0[iVar7] = '\0';
    if (iVar5 != 0) {
      uVar4 = 0x168;
      goto LAB_97b8aac8;
    }
  }
  _strcpy((char *)(param_2 + 3),local_2c0);
  iVar7 = _atoi((char *)(param_2 + 3));
LAB_97b8aaf0:
  *param_2 = iVar7;
  return iVar2;
}

/* _scan_token @ 0x97b8ab0c (248 bytes) */
int _scan_token(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  int iVar2;
  code *pcVar3;
  
  iVar2 = ((int (*)())_ReadToken)(param_1[6]);
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
                    
                    
    iVar2 = (**(code **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20) + 4))
                      (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20),param_2);
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
  
  puVar4 = _malloc(0x20);
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
  void *param_2;
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
  void *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = _malloc(0xac);
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
int TBuiltIns__getNumStringArrays(this, param_1)
  unsigned char * this;
  int param_1;
{
  return 6 - (uint)(param_1 == 1);
}

/* TBuiltIns__getStringArray @ 0x97b8aee8 (204 bytes) */
int TBuiltIns__getStringArray(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  uint param_2;
{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_1 == 1) {
    if (param_2 == 0) {
      puVar1 = &_strBuiltInFunctions;
    }
    if (param_2 == 1) {
      puVar1 = &_strBuiltInFunctionsFragment;
    }
    if (param_2 == 2) {
      puVar1 = &_strStandardFragmentVaryings;
    }
    if (param_2 == 3) {
      puVar1 = &_strStandardUniformConstants;
    }
    if (param_2 != 4) {
      return puVar1;
    }
  }
  else {
    if (param_2 == 0) {
      puVar1 = &_strBuiltInFunctions;
    }
    if (param_2 == 1) {
      puVar1 = &_strBuiltInFunctionsVertex;
    }
    if (param_2 == 2) {
      puVar1 = &_strStandardVertexVaryings;
    }
    if (param_2 == 3) {
      puVar1 = &_strStandardVertexAttributes;
    }
    if (param_2 == 4) {
      puVar1 = &_strStandardUniformConstants;
    }
    if (param_2 != 5) {
      return puVar1;
    }
  }
  return &_strStandardUniforms;
}

/* TBuiltIns__getStringSizeArray @ 0x97b8afb4 (204 bytes) */
int TBuiltIns__getStringSizeArray(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  uint param_2;
{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_1 == 1) {
    if (param_2 == 0) {
      puVar1 = &_sizeBuiltInFunctions;
    }
    if (param_2 == 1) {
      puVar1 = &_sizeBuiltInFunctionsFragment;
    }
    if (param_2 == 2) {
      puVar1 = &_sizeStandardFragmentVaryings;
    }
    if (param_2 == 3) {
      puVar1 = &_sizeStandardUniformConstants;
    }
    if (param_2 != 4) {
      return puVar1;
    }
  }
  else {
    if (param_2 == 0) {
      puVar1 = &_sizeBuiltInFunctions;
    }
    if (param_2 == 1) {
      puVar1 = &_sizeBuiltInFunctionsVertex;
    }
    if (param_2 == 2) {
      puVar1 = &_sizeStandardVertexVaryings;
    }
    if (param_2 == 3) {
      puVar1 = &_sizeStandardVertexAttributes;
    }
    if (param_2 == 4) {
      puVar1 = &_sizeStandardUniformConstants;
    }
    if (param_2 != 5) {
      return puVar1;
    }
  }
  return &_sizeStandardUniforms;
}

/* TBuiltIns__getNumStrings @ 0x97b8b080 (148 bytes) */
int TBuiltIns__getNumStrings(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  uint param_2;
{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_1 == 1) {
    if (param_2 == 0) {
      uVar2 = 0x454;
    }
    if (param_2 == 1) {
      uVar2 = 0x34;
    }
    if (param_2 == 2) {
      uVar2 = 0x14;
    }
    if (param_2 == 3) {
      uVar2 = 0x34;
    }
    bVar1 = param_2 == 4;
  }
  else {
    if (param_2 == 0) {
      uVar2 = 0x454;
    }
    if (param_2 == 1) {
      uVar2 = 8;
    }
    if (param_2 == 2) {
      uVar2 = 0x1c;
    }
    if (param_2 == 3) {
      uVar2 = 0x38;
    }
    if (param_2 == 4) {
      uVar2 = 0x34;
    }
    bVar1 = param_2 == 5;
  }
  if (bVar1) {
    uVar2 = 0x174;
  }
  return uVar2 >> 2;
}

/* TBuiltIns__initialize @ 0x97b8b114 (4 bytes) */
int TBuiltIns__initialize()
{
  return;
}

/* TBuiltIns__initialize_97b8b118 @ 0x97b8b118 (4 bytes) */
int TBuiltIns__initialize_97b8b118(param_1)
  unsigned char * param_1;
{
  return;
}

/* IdentifyBuiltIns @ 0x97b8b11c (5284 bytes) */
int IdentifyBuiltIns(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  int *piVar7;
  unsigned char * psVar8;
  unsigned char * psVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined *puVar12;
  char in_RESERVE;
  byte bVar13;
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
  undefined4 local_340;
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
  undefined4 local_2c0;
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
  undefined4 local_240;
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
  undefined4 local_1c0;
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
  undefined4 local_140;
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
  undefined4 local_c0;
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
  undefined4 local_40;
  
  if (param_1 == 0) {
    uVar6 = GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(uVar6);
    pcVar2 = DAT_a7b7b708;
    uVar6 = GetGlobalPoolAllocator();
    psVar8 = (unsigned char *)TPoolAllocator__allocate(uVar6);
    bVar13 = (psVar8 == (unsigned char *)0x0) << 1;
    psVar9 = (unsigned char *)0x0;
    if (psVar8 != (unsigned char *)0x0) {
      local_1b0[0] = GetGlobalPoolAllocator();
      std__string__string(psVar8,pcVar2,(unsigned char *)local_1b0);
      psVar9 = psVar8;
    }
    puVar12 = PTR_vtable_a7b7c0b4 + 8;
    local_17c = local_17c & 0x801ff | 0x1a082000;
    local_19c = 0;
    local_198 = 0;
    local_194 = 0;
    local_190 = 0;
    local_18c = 0;
    local_188 = 0;
    local_184 = 0;
    local_180 = 0;
    local_1a0 = &PTR__TType_a7b7cf48;
    piVar7[1] = (int)psVar9;
    *piVar7 = (int)puVar12;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR__TType_a7b7cf48;
    piVar7[0xb] = 0;
    uVar3 = piVar7[0xc];
    piVar7[0xc] = uVar3 & 0x1ffffff | 0x1a000000;
    uVar4 = (local_17c >> 0x13 & 0x3f) << 0x13;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ffff | 0x1a000000;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ff | 0x1a000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x3ff | 0x1a000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x1ff | 0x1a000000 | 0x2000;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar5 = param_2[3];
    param_2[3] = iVar5 + 1;
    piVar7[2] = iVar5 + 1;
    local_16c = 0;
    psVar9 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7);
    std__string__string((unsigned char *)&local_150,psVar9);
    local_148 = piVar7;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_160);
    local_170 = local_160;
    piVar7 = (int *)(local_14c + -4);
    local_16c = local_15c;
    local_140 = local_150;
    do {
      iVar5 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar13 = 2;
      }
    } while (!(bool)(bVar13 >> 1 & 1));
    if (iVar5 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_14c + -0xc));
    }
    local_1a0 = &PTR__TType_a7b7cf48;
    uVar6 = GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(uVar6);
    pcVar2 = DAT_a7b7b70c;
    uVar6 = GetGlobalPoolAllocator();
    psVar8 = (unsigned char *)TPoolAllocator__allocate(uVar6);
    bVar13 = (psVar8 == (unsigned char *)0x0) << 1;
    psVar9 = (unsigned char *)0x0;
    if (psVar8 != (unsigned char *)0x0) {
      local_130[0] = GetGlobalPoolAllocator();
      std__string__string(psVar8,pcVar2,(unsigned char *)local_130);
      psVar9 = psVar8;
    }
    puVar12 = PTR_vtable_a7b7c0b4 + 8;
    local_fc = local_fc & 0x1ff | 0x1c080800;
    local_11c = 0;
    local_118 = 0;
    local_114 = 0;
    local_110 = 0;
    local_10c = 0;
    local_108 = 0;
    local_104 = 0;
    local_100 = 0;
    local_120 = &PTR__TType_a7b7cf48;
    piVar7[1] = (int)psVar9;
    *piVar7 = (int)puVar12;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR__TType_a7b7cf48;
    piVar7[0xb] = 0;
    uVar4 = piVar7[0xc];
    piVar7[0xc] = uVar4 & 0x1ffffff | 0x1c000000;
    piVar7[0xc] = uVar4 & 0x7ffff | 0x1c080000;
    piVar7[0xc] = uVar4 & 0x7ff | 0x1c080800;
    piVar7[0xc] = uVar4 & 0x3ff | 0x1c080800;
    piVar7[0xc] = uVar4 & 0x1ff | 0x1c080800;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar5 = param_2[3];
    param_2[3] = iVar5 + 1;
    piVar7[2] = iVar5 + 1;
    local_ec = 0;
    psVar9 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7);
    std__string__string((unsigned char *)&local_d0,psVar9);
    local_c8 = piVar7;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_e0);
    local_f0 = local_e0;
    piVar7 = (int *)(local_cc + -4);
    local_ec = local_dc;
    local_c0 = local_d0;
    do {
      iVar5 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar13 = 2;
      }
    } while (!(bool)(bVar13 >> 1 & 1));
    if (iVar5 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_cc + -0xc));
    }
    local_120 = &PTR__TType_a7b7cf48;
    uVar6 = GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(uVar6);
    pcVar2 = DAT_a7b7b710;
    uVar6 = GetGlobalPoolAllocator();
    psVar8 = (unsigned char *)TPoolAllocator__allocate(uVar6);
    bVar13 = (psVar8 == (unsigned char *)0x0) << 1;
    psVar9 = (unsigned char *)0x0;
    if (psVar8 != (unsigned char *)0x0) {
      local_b0[0] = GetGlobalPoolAllocator();
      std__string__string(psVar8,pcVar2,(unsigned char *)local_b0);
      psVar9 = psVar8;
    }
    puVar12 = PTR_vtable_a7b7c0b4 + 8;
    local_7c = local_7c & 0x801ff | 0x1e082000;
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    local_90 = 0;
    local_8c = 0;
    local_88 = 0;
    local_84 = 0;
    local_80 = 0;
    local_a0 = &PTR__TType_a7b7cf48;
    piVar7[1] = (int)psVar9;
    *piVar7 = (int)puVar12;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR__TType_a7b7cf48;
    piVar7[0xb] = 0;
    uVar3 = piVar7[0xc];
    piVar7[0xc] = uVar3 & 0x1ffffff | 0x1e000000;
    uVar4 = (local_7c >> 0x13 & 0x3f) << 0x13;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ffff | 0x1e000000;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ff | 0x1e000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x3ff | 0x1e000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x1ff | 0x1e000000 | 0x2000;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar5 = param_2[3];
    param_2[3] = iVar5 + 1;
    piVar7[2] = iVar5 + 1;
    local_6c = 0;
    psVar9 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7);
    std__string__string((unsigned char *)&local_50,psVar9);
    local_48 = piVar7;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_60);
    local_70 = local_60;
    piVar7 = (int *)(local_4c + -4);
    local_6c = local_5c;
    local_40 = local_50;
    do {
      iVar5 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar13 = 2;
      }
    } while (!(bool)(bVar13 >> 1 & 1));
    if (iVar5 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_4c + -0xc));
    }
    local_a0 = &PTR__TType_a7b7cf48;
  }
  else if (param_1 == 1) {
    uVar6 = GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(uVar6);
    pcVar2 = _strSpecialBuiltIn;
    uVar6 = GetGlobalPoolAllocator();
    psVar8 = (unsigned char *)TPoolAllocator__allocate(uVar6);
    bVar13 = (psVar8 == (unsigned char *)0x0) << 1;
    psVar9 = (unsigned char *)0x0;
    if (psVar8 != (unsigned char *)0x0) {
      local_3b0[0] = GetGlobalPoolAllocator();
      std__string__string(psVar8,pcVar2,(unsigned char *)local_3b0);
      psVar9 = psVar8;
    }
    puVar12 = PTR_vtable_a7b7c0b4 + 8;
    local_37c = local_37c & 0x1801ff | 0x20180800;
    local_39c = 0;
    local_398 = 0;
    local_394 = 0;
    local_390 = 0;
    local_38c = 0;
    local_388 = 0;
    local_384 = 0;
    local_380 = 0;
    local_3a0 = &PTR__TType_a7b7cf48;
    piVar7[1] = (int)psVar9;
    *piVar7 = (int)puVar12;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR__TType_a7b7cf48;
    piVar7[0xb] = 0;
    uVar3 = piVar7[0xc];
    piVar7[0xc] = uVar3 & 0x1ffffff | 0x20000000;
    uVar4 = (local_37c >> 0x13 & 0x3f) << 0x13;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ffff | 0x20000000;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ff | 0x20000000 | 0x800;
    piVar7[0xc] = uVar4 | uVar3 & 0x3ff | 0x20000000 | 0x800;
    piVar7[0xc] = uVar4 | uVar3 & 0x1ff | 0x20000000 | 0x800;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar5 = param_2[3];
    param_2[3] = iVar5 + 1;
    piVar7[2] = iVar5 + 1;
    local_36c = 0;
    psVar9 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7);
    std__string__string((unsigned char *)&local_350,psVar9);
    local_348 = piVar7;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_360);
    local_370 = local_360;
    piVar7 = (int *)(local_34c + -4);
    local_36c = local_35c;
    local_340 = local_350;
    do {
      iVar5 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar13 = 2;
      }
    } while (!(bool)(bVar13 >> 1 & 1));
    if (iVar5 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_34c + -0xc));
    }
    local_3a0 = &PTR__TType_a7b7cf48;
    uVar6 = GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(uVar6);
    pcVar2 = DAT_a7b7b6f8;
    uVar6 = GetGlobalPoolAllocator();
    psVar8 = (unsigned char *)TPoolAllocator__allocate(uVar6);
    bVar13 = (psVar8 == (unsigned char *)0x0) << 1;
    psVar9 = (unsigned char *)0x0;
    if (psVar8 != (unsigned char *)0x0) {
      local_330[0] = GetGlobalPoolAllocator();
      std__string__string(psVar8,pcVar2,(unsigned char *)local_330);
      psVar9 = psVar8;
    }
    puVar12 = PTR_vtable_a7b7c0b4 + 8;
    local_2fc = local_2fc & 0x801ff | 0x22082000;
    local_31c = 0;
    local_318 = 0;
    local_314 = 0;
    local_310 = 0;
    local_30c = 0;
    local_308 = 0;
    local_304 = 0;
    local_300 = 0;
    local_320 = &PTR__TType_a7b7cf48;
    piVar7[1] = (int)psVar9;
    *piVar7 = (int)puVar12;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR__TType_a7b7cf48;
    piVar7[0xb] = 0;
    uVar3 = piVar7[0xc];
    piVar7[0xc] = uVar3 & 0x1ffffff | 0x22000000;
    uVar4 = (local_2fc >> 0x13 & 0x3f) << 0x13;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ffff | 0x22000000;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ff | 0x22000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x3ff | 0x22000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x1ff | 0x22000000 | 0x2000;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar5 = param_2[3];
    param_2[3] = iVar5 + 1;
    piVar7[2] = iVar5 + 1;
    local_2ec = 0;
    psVar9 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7);
    std__string__string((unsigned char *)&local_2d0,psVar9);
    local_2c8 = piVar7;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_2e0);
    local_2f0 = local_2e0;
    piVar7 = (int *)(local_2cc + -4);
    local_2ec = local_2dc;
    local_2c0 = local_2d0;
    do {
      iVar5 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar13 = 2;
      }
    } while (!(bool)(bVar13 >> 1 & 1));
    if (iVar5 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_2cc + -0xc));
    }
    local_320 = &PTR__TType_a7b7cf48;
    uVar6 = GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(uVar6);
    pcVar2 = DAT_a7b7b6fc;
    uVar6 = GetGlobalPoolAllocator();
    psVar8 = (unsigned char *)TPoolAllocator__allocate(uVar6);
    bVar13 = (psVar8 == (unsigned char *)0x0) << 1;
    psVar9 = (unsigned char *)0x0;
    if (psVar8 != (unsigned char *)0x0) {
      local_2b0[0] = GetGlobalPoolAllocator();
      std__string__string(psVar8,pcVar2,(unsigned char *)local_2b0);
      psVar9 = psVar8;
    }
    puVar12 = PTR_vtable_a7b7c0b4 + 8;
    local_27c = local_27c & 0x801ff | 0x24082000;
    local_29c = 0;
    local_298 = 0;
    local_294 = 0;
    local_290 = 0;
    local_28c = 0;
    local_288 = 0;
    local_284 = 0;
    local_280 = 0;
    local_2a0 = &PTR__TType_a7b7cf48;
    piVar7[1] = (int)psVar9;
    *piVar7 = (int)puVar12;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR__TType_a7b7cf48;
    piVar7[0xb] = 0;
    uVar3 = piVar7[0xc];
    piVar7[0xc] = uVar3 & 0x1ffffff | 0x24000000;
    uVar4 = (local_27c >> 0x13 & 0x3f) << 0x13;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ffff | 0x24000000;
    piVar7[0xc] = uVar4 | uVar3 & 0x7ff | 0x24000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x3ff | 0x24000000 | 0x2000;
    piVar7[0xc] = uVar4 | uVar3 & 0x1ff | 0x24000000 | 0x2000;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar5 = param_2[3];
    param_2[3] = iVar5 + 1;
    piVar7[2] = iVar5 + 1;
    local_26c = 0;
    psVar9 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7);
    std__string__string((unsigned char *)&local_250,psVar9);
    local_248 = piVar7;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_260);
    local_270 = local_260;
    piVar7 = (int *)(local_24c + -4);
    local_26c = local_25c;
    local_240 = local_250;
    do {
      iVar5 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar13 = 2;
      }
    } while (!(bool)(bVar13 >> 1 & 1));
    if (iVar5 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_24c + -0xc));
    }
    local_2a0 = &PTR__TType_a7b7cf48;
    uVar6 = GetGlobalPoolAllocator();
    piVar7 = (int *)TPoolAllocator__allocate(uVar6);
    pcVar2 = DAT_a7b7b700;
    uVar6 = GetGlobalPoolAllocator();
    psVar8 = (unsigned char *)TPoolAllocator__allocate(uVar6);
    bVar13 = (psVar8 == (unsigned char *)0x0) << 1;
    psVar9 = (unsigned char *)0x0;
    if (psVar8 != (unsigned char *)0x0) {
      local_230[0] = GetGlobalPoolAllocator();
      std__string__string(psVar8,pcVar2,(unsigned char *)local_230);
      psVar9 = psVar8;
    }
    puVar12 = PTR_vtable_a7b7c0b4 + 8;
    local_1fc = local_1fc & 0x1ff | 0x26080800;
    local_21c = 0;
    local_218 = 0;
    local_214 = 0;
    local_210 = 0;
    local_20c = 0;
    local_208 = 0;
    local_204 = 0;
    local_200 = 0;
    local_220 = &PTR__TType_a7b7cf48;
    piVar7[1] = (int)psVar9;
    *piVar7 = (int)puVar12;
    piVar7[4] = 0;
    piVar7[5] = 0;
    piVar7[6] = 0;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[3] = (int)&PTR__TType_a7b7cf48;
    piVar7[0xb] = 0;
    uVar4 = piVar7[0xc];
    piVar7[0xc] = uVar4 & 0x1ffffff | 0x26000000;
    piVar7[0xc] = uVar4 & 0x7ffff | 0x26080000;
    piVar7[0xc] = uVar4 & 0x7ff | 0x26080800;
    piVar7[0xc] = uVar4 & 0x3ff | 0x26080800;
    piVar7[0xc] = uVar4 & 0x1ff | 0x26080800;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    iVar5 = param_2[3];
    param_2[3] = iVar5 + 1;
    piVar7[2] = iVar5 + 1;
    local_1ec = 0;
    psVar9 = (unsigned char *)(**(code **)(*piVar7 + 8))(piVar7);
    std__string__string((unsigned char *)&local_1d0,psVar9);
    local_1c8 = piVar7;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_1e0);
    local_1f0 = local_1e0;
    piVar7 = (int *)(local_1cc + -4);
    local_1ec = local_1dc;
    local_1c0 = local_1d0;
    do {
      iVar5 = *piVar7;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar7);
        *piVar7 = iVar1;
        bVar13 = 2;
      }
    } while (!(bool)(bVar13 >> 1 & 1));
    if (iVar5 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_1cc + -0xc));
    }
    local_220 = &PTR__TType_a7b7cf48;
  }
  puVar12 = PTR__operatorStrings_a7b7c0b0;
  TSymbolTableLevel__relateToOperator
            (*(undefined4 *)*param_2,*(undefined4 *)(PTR__operatorStrings_a7b7c0b0 + 0x1c),7);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x54),0x15);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x5c),0x17);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x7c),0x1f);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x80),0x20);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x84),0x21);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x88),0x22);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x8c),0x23);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x90),0x24);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xc4),0x31);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 200),0x32);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xcc),0x33);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xd0),0x34);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xd4),0x35);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xd8),0x36);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xdc),0x37);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xe0),0x38);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xe4),0x39);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xf0),0x3c);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xec),0x3b);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xe8),0x3a);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xf4),0x3d);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xf8),0x3e);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0xfc),0x3f);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x100),0x40)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x104),0x41)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x108),0x42)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x10c),0x43)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x110),0x44)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x114),0x45)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x118),0x46)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x11c),0x47)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x120),0x48)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x124),0x49)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x128),0x4a)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 300),0x4b);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x130),0x4c)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x134),0x4d)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x138),0x4e)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x13c),0x4f)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x140),0x50)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x144),0x51)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x148),0x52)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x15c),0x57)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x160),0x58)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x218),0x86)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x21c),0x87)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x220),0x88)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x224),0x89)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x228),0x8a)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x22c),0x8b)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x230),0x8c)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x234),0x8d)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x238),0x8e)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x23c),0x8f)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x240),0x90)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x244),0x91)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x248),0x92)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x24c),0x93)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x250),0x94)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x254),0x95)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 600),0x96);
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x25c),0x97)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x260),0x98)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x264),0x99)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x268),0x9a)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x26c),0x9b)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x270),0x9c)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x274),0x9d)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x278),0x9e)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x27c),0x9f)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x280),0xa0)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x284),0xa1)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x288),0xa2)
  ;
  TSymbolTableLevel__relateToOperator(*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x28c),0xa3)
  ;
  if (param_1 == 0) {
    param_2 = (undefined4 *)*param_2;
    uVar11 = 0x85;
    uVar10 = *(undefined4 *)(puVar12 + 0x214);
  }
  else {
    if (param_1 != 1) {
      return;
    }
    TSymbolTableLevel__relateToOperator
              (*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x14c),0x53);
    TSymbolTableLevel__relateToOperator
              (*(undefined4 *)*param_2,*(undefined4 *)(puVar12 + 0x150),0x54);
    param_2 = (undefined4 *)*param_2;
    uVar10 = *(undefined4 *)(puVar12 + 0x154);
    uVar11 = 0x55;
  }
  TSymbolTableLevel__relateToOperator(*param_2,uVar10,uVar11);
  return;
}

/* IdentifyBuiltIns_97b8c5c0 @ 0x97b8c5c0 (600 bytes) */
int IdentifyBuiltIns_97b8c5c0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  ulong uVar4;
  int *piVar5;
  unsigned char * this;
  unsigned char * psVar6;
  int iVar7;
  char in_RESERVE;
  byte bVar8;
  undefined4 local_70 [4];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_40;
  int local_3c;
  int *local_38;
  undefined4 local_30;
  
  if (param_1 == 1) {
    iVar7 = *(int *)(param_3 + 0x2c);
    uVar4 = GetGlobalPoolAllocator();
    piVar5 = (int *)TPoolAllocator__allocate(uVar4);
    pcVar2 = DAT_a7b7b704;
    uVar4 = GetGlobalPoolAllocator();
    this = (unsigned char *)TPoolAllocator__allocate(uVar4);
    bVar8 = (this == (unsigned char *)0x0) << 1;
    psVar6 = (unsigned char *)0x0;
    if (this != (unsigned char *)0x0) {
      local_70[0] = GetGlobalPoolAllocator();
      std__string__string(this,pcVar2,(unsigned char *)local_70);
      psVar6 = this;
    }
    piVar5[1] = (int)psVar6;
    *piVar5 = (int)(PTR_vtable_a7b7c0b4 + 8);
    piVar5[4] = iVar7;
    piVar5[5] = 0;
    piVar5[6] = 0;
    piVar5[7] = 0;
    piVar5[8] = 0;
    piVar5[9] = 0;
    piVar5[3] = (int)&PTR__TType_a7b7cf48;
    piVar5[10] = 0;
    piVar5[0xb] = 0;
    uVar3 = piVar5[0xc];
    piVar5[0xc] = uVar3 & 0x1ffffff | 0x24000000;
    piVar5[0xc] = uVar3 & 0x7ffff | 0x24080000;
    piVar5[0xc] = uVar3 & 0x7ff | 0x24082000;
    piVar5[0xc] = uVar3 & 0x3ff | 0x24082000;
    piVar5[0xc] = uVar3 & 0x1ff | 0x24082200;
    piVar5[0xd] = 0;
    piVar5[0xe] = 0;
    piVar5[0xf] = 0;
    iVar7 = *(int *)(param_2 + 0xc) + 1;
    *(int *)(param_2 + 0xc) = iVar7;
    piVar5[2] = iVar7;
    local_5c = 0;
    psVar6 = (unsigned char *)(**(code **)(*piVar5 + 8))(piVar5);
    std__string__string((unsigned char *)&local_40,psVar6);
    local_38 = piVar5;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_50);
    local_60 = local_50;
    piVar5 = (int *)(local_3c + -4);
    local_5c = local_4c;
    local_30 = local_40;
    do {
      iVar7 = *piVar5;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar7 + -1,0,piVar5);
        *piVar5 = iVar1;
        bVar8 = 2;
      }
    } while (!(bool)(bVar8 >> 1 & 1));
    if (iVar7 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_3c + -0xc));
    }
  }
  return;
}

/* GetPreprocessorBuiltinString @ 0x97b8c818 (28 bytes) */
int GetPreprocessorBuiltinString()
{
  return GetPreprocessorBuiltinString__PreprocessorBuiltinString;
}

/* TInfoSinkBase__append @ 0x97b8c834 (196 bytes) */
int TInfoSinkBase__append(this, param_1)
  unsigned char * this;
  char *param_1;
{
  uint uVar1;
  size_t sVar2;
  
  uVar1 = *(uint *)(this + 4);
  if ((uVar1 & 4) != 0) {
    sVar2 = _strlen(param_1);
    if (*(uint *)(*(int *)this + -8) < *(int *)(*(int *)this + -0xc) + sVar2 + 2) {
      std__string__reserve((ulong)this);
    }
    _strlen(param_1);
    std__string__append((char *)this,(ulong)param_1);
    uVar1 = *(uint *)(this + 4);
  }
  if ((uVar1 & 2) != 0) {
    _fprintf((FILE *)(PTR_DAT_a7b7c0bc + 0x58),"%s",param_1);
    return;
  }
  return;
}

/* TInfoSinkBase__append_97b8c8f8 @ 0x97b8c8f8 (180 bytes) */
int TInfoSinkBase__append_97b8c8f8(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  int param_2;
{
  uint uVar1;
  undefined3 in_register_00000014;
  
  uVar1 = *(uint *)(this + 4);
  if ((uVar1 & 4) != 0) {
    if (*(uint *)(*(int *)this + -8) < *(int *)(*(int *)this + -0xc) + param_1 + 2U) {
      std__string__reserve((ulong)this);
    }
    std__string__append((ulong)this,(char)param_1);
    uVar1 = *(uint *)(this + 4);
  }
  if ((uVar1 & 2) != 0) {
    _fprintf((FILE *)(PTR_DAT_a7b7c0bc + 0x58),"%c",CONCAT31(in_register_00000014,param_2));
    return;
  }
  return;
}

/* TInfoSinkBase__append_97b8c9ac @ 0x97b8c9ac (204 bytes) */
int TInfoSinkBase__append_97b8c9ac(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined *puVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(this + 4);
  if ((uVar2 & 4) != 0) {
    if (*(uint *)(*(int *)this + -8) <
        *(int *)(*(int *)this + -0xc) + *(int *)(*(int *)param_1 + -0xc) + 2U) {
      std__string__reserve((ulong)this);
    }
    std__string__append((unsigned char *)this);
    uVar2 = *(uint *)(this + 4);
  }
  puVar1 = PTR_DAT_a7b7c0bc;
  if ((uVar2 & 2) != 0) {
    *(undefined *)(*(int *)param_1 + *(int *)(*(int *)param_1 + -0xc)) = *PTR__S_terminal_a7b7c0b8;
    _fprintf((FILE *)(puVar1 + 0x58),"%s",*(undefined4 *)param_1);
    return;
  }
  return;
}

/* TInfoSinkBase__append_97b8ca78 @ 0x97b8ca78 (244 bytes) */
int TInfoSinkBase__append_97b8ca78(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  
  uVar2 = *(uint *)(this + 4);
  if ((uVar2 & 4) != 0) {
    iVar3 = *(int *)(param_1 + 4);
    if (*(uint *)(*(int *)this + -8) < *(int *)(*(int *)this + -0xc) + *(int *)(iVar3 + -0xc) + 2U)
    {
      std__string__reserve((ulong)this);
      iVar3 = *(int *)(param_1 + 4);
    }
    *(undefined1 *)(iVar3 + *(int *)(iVar3 + -0xc)) = *DAT_a7b7b720;
    pcVar4 = *(char **)(param_1 + 4);
    _strlen(pcVar4);
    std__string__append((char *)this,(ulong)pcVar4);
    uVar2 = *(uint *)(this + 4);
  }
  puVar1 = PTR_DAT_a7b7c0bc;
  if ((uVar2 & 2) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 4) + *(int *)(*(int *)(param_1 + 4) + -0xc)) = *DAT_a7b7b720;
    _fprintf((FILE *)(puVar1 + 0x58),"%s",*(undefined4 *)(param_1 + 4));
    return;
  }
  return;
}

/* TIntermediate__addSymbol @ 0x97b8cb6c (376 bytes) */
int TIntermediate__addSymbol(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  int param_1;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  ulong uVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  char in_RESERVE;
  byte in_cr0;
  
  uVar9 = GetGlobalPoolAllocator();
  piVar10 = (int *)TPoolAllocator__allocate(uVar9);
  piVar10[1] = 0;
  *piVar10 = (int)&PTR_getLine_a7b7cf90;
  iVar6 = *(int *)(param_3 + 4);
  iVar17 = *(int *)(param_3 + 8);
  iVar16 = *(int *)(param_3 + 0xc);
  iVar15 = *(int *)(param_3 + 0x10);
  iVar14 = *(int *)(param_3 + 0x14);
  iVar13 = *(int *)(param_3 + 0x18);
  iVar12 = *(int *)(param_3 + 0x1c);
  iVar11 = *(int *)(param_3 + 0x20);
  piVar10[2] = (int)&PTR__TType_a7b7cff8;
  piVar10[3] = iVar6;
  piVar10[4] = iVar17;
  piVar10[5] = iVar16;
  piVar10[6] = iVar15;
  piVar10[7] = iVar14;
  piVar10[8] = iVar13;
  piVar10[9] = iVar12;
  piVar10[10] = iVar11;
  uVar7 = piVar10[0xb];
  uVar2 = *(uint *)(param_3 + 0x24) & 0xfe000000;
  piVar10[0xb] = uVar2 | uVar7 & 0x1ffffff;
  uVar3 = (*(uint *)(param_3 + 0x24) >> 0x13 & 0x3f) << 0x13;
  piVar10[0xb] = uVar3 | uVar2 | uVar7 & 0x7ffff;
  uVar1 = *(uint *)(param_3 + 0x24) & 0x7f800;
  piVar10[0xb] = uVar1 | uVar3 | uVar2 | uVar7 & 0x7ff;
  uVar4 = (*(uint *)(param_3 + 0x24) >> 10 & 1) << 10;
  piVar10[0xb] = uVar4 | uVar1 | uVar3 | uVar2 | uVar7 & 0x3ff;
  puVar5 = PTR_vtable_a7b7c0dc;
  iVar6 = DAT_a7b7b9b8;
  piVar10[0xb] = (*(uint *)(param_3 + 0x24) >> 9 & 1) << 9 |
                 uVar4 | uVar1 | uVar3 | uVar2 | uVar7 & 0x1ff;
  piVar8 = (int *)(iVar6 + 8);
  *piVar10 = (int)(puVar5 + 8);
  piVar10[0xc] = param_1;
  do {
    if (in_RESERVE != '\0') {
      iVar11 = storeWordConditionalIndexed(*piVar8 + 1,0,piVar8);
      *piVar8 = iVar11;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  iVar11 = GetGlobalPoolAllocator();
  piVar10[0xd] = iVar11;
  piVar10[0xe] = iVar6 + 0xc;
  std__string__assign((unsigned char *)(piVar10 + 0xd));
  (**(code **)(*piVar10 + 4))(piVar10,param_4);
  return piVar10;
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
  ulong uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  unsigned char * pTVar12;
  int *piVar13;
  unsigned char * pTVar14;
  unsigned char * pTVar15;
  unsigned char * pTVar16;
  unsigned char * pTVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  code *pcVar20;
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
      local_f0[0] = &PTR__TType_a7b7cff8;
    }
    goto LAB_97b8d01c;
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
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
    break;
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    (**(code **)(*param_3 + 0x38))(&local_120,param_3);
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
      if (!bVar1) goto LAB_97b8cf6c;
    }
    local_90[0] = &PTR__TType_a7b7cff8;
    goto LAB_97b8cf6c;
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
      local_60[0] = &PTR__TType_a7b7cff8;
    }
    else {
LAB_97b8cf4c:
      bVar4 = true;
      if (bVar1) goto LAB_97b8cf5c;
    }
LAB_97b8cf6c:
    if (bVar2) {
      local_c0[0] = &PTR__TType_a7b7cff8;
    }
    if (bVar3) {
      local_f0[0] = &PTR__TType_a7b7cff8;
    }
LAB_97b8d01c:
    local_120 = &PTR__TType_a7b7cff8;
    if (bVar4) {
      return (int *)0x0;
    }
  }
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
    local_f0[0] = &PTR__TType_a7b7cff8;
  }
  local_120 = &PTR__TType_a7b7cff8;
  if (bVar2) {
    (**(code **)(*param_3 + 0x38))(local_c0,param_3);
    piVar7 = (int *)((int (*)())TIntermediate__addConversion)(this,param_2,local_c0,param_4);
    local_c0[0] = &PTR__TType_a7b7cff8;
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
    local_90[0] = &PTR__TType_a7b7cff8;
    piVar7 = param_4;
    if (!bVar1) {
      return (int *)0x0;
    }
  }
  local_c0[0] = &PTR__TType_a7b7cff8;
  uVar8 = GetGlobalPoolAllocator();
  piVar9 = (int *)TPoolAllocator__allocate(uVar8);
  local_fc = local_fc & 0x1ff | 0x80800;
  local_11c = 0;
  local_114 = 0;
  local_110 = 0;
  local_10c = 0;
  local_108 = 0;
  local_104 = 0;
  local_100 = 0;
  local_118 = 0;
  piVar9[1] = 0;
  *piVar9 = (int)&PTR_getLine_a7b7cf90;
  piVar9[3] = 0;
  piVar9[4] = 0;
  piVar9[5] = 0;
  piVar9[6] = 0;
  piVar9[7] = 0;
  piVar9[8] = 0;
  piVar9[2] = (int)&PTR__TType_a7b7cff8;
  piVar9[9] = 0;
  piVar9[10] = 0;
  uVar6 = piVar9[0xb];
  piVar9[0xb] = uVar6 & 0x1ffffff;
  piVar9[0xb] = uVar6 & 0x7ffff | 0x80000;
  piVar9[0xb] = uVar6 & 0x7ff | 0x80800;
  piVar9[0xb] = uVar6 & 0x3ff | 0x80800;
  puVar5 = PTR_vtable_a7b7c0d8;
  piVar9[0xb] = uVar6 & 0x1ff | 0x80800;
  local_120 = &PTR__TType_a7b7cff8;
  piVar9[0xc] = param_2;
  *piVar9 = (int)(puVar5 + 8);
  if (param_5 == 0) {
    param_5 = (**(code **)*piVar7)(piVar7);
  }
  (**(code **)(*piVar9 + 4))(piVar9,param_5);
  (**(code **)(*piVar9 + 0x60))(piVar9,param_3);
  (**(code **)(*piVar9 + 100))(piVar9,piVar7);
  iVar10 = (**(code **)(*piVar9 + 0x5c))(piVar9,*(undefined4 *)this);
  if (iVar10 == 0) {
    return (int *)0x0;
  }
  iVar10 = (**(code **)(*param_3 + 0x18))(param_3);
  iVar11 = (**(code **)(*piVar7 + 0x18))(piVar7);
  pTVar12 = (unsigned char *)0x0;
  if (iVar10 != 0) {
    pTVar12 = (unsigned char *)(**(code **)(*param_3 + 0x18))(param_3);
    piVar13 = (int *)TIntermediate__copyConstUnion(this,pTVar12);
    pTVar12 = (unsigned char *)(**(code **)(*piVar13 + 0x18))();
  }
  pTVar14 = (unsigned char *)0x0;
  if (iVar11 != 0) {
    pTVar14 = (unsigned char *)(**(code **)(*piVar7 + 0x18))(piVar7);
    piVar13 = (int *)TIntermediate__copyConstUnion(this,pTVar14);
    pTVar14 = (unsigned char *)(**(code **)(*piVar13 + 0x18))();
  }
  bVar1 = false;
  (**(code **)(*piVar7 + 0x38))(&local_120,piVar7);
  if (local_fc >> 0x19 == 2) {
    (**(code **)(*param_3 + 0x38))(local_f0,param_3);
    bVar1 = local_cc >> 0x19 == 2;
    local_f0[0] = &PTR__TType_a7b7cff8;
  }
  local_120 = &PTR__TType_a7b7cff8;
  if (bVar1) {
    iVar10 = (**(code **)(*piVar7 + 0x1c))(piVar7);
    if (iVar10 != 0) {
      pTVar15 = (unsigned char *)(**(code **)(*piVar7 + 0x1c))(piVar7);
      pTVar14 = (unsigned char *)TIntermediate__changeAggrToTempConst(this,pTVar15,param_6,param_5);
      if (*(int *)(pTVar14 + 0x30) == 0) {
        return (int *)0x0;
      }
    }
    iVar10 = (**(code **)(*param_3 + 0x1c))(param_3);
    if (iVar10 != 0) {
      pTVar15 = (unsigned char *)(**(code **)(*param_3 + 0x1c))(param_3);
      pTVar12 = (unsigned char *)TIntermediate__changeAggrToTempConst(this,pTVar15,param_6,param_5);
      if (*(int *)(pTVar12 + 0x30) == 0) {
        return (int *)0x0;
      }
    }
  }
  if (pTVar12 == (unsigned char *)0x0) {
    if (pTVar14 == (unsigned char *)0x0) {
      return piVar9;
    }
  }
  else {
    if (pTVar14 == (unsigned char *)0x0) {
      iVar10 = *piVar9;
      pTVar14 = (unsigned char *)TIntermediate__copyConstUnion(this,pTVar12);
      pcVar20 = *(code **)(iVar10 + 0x60);
      goto LAB_97b8d618;
    }
    iVar10 = (**(code **)(*(int *)pTVar12 + 0x4c))(pTVar12);
    if ((iVar10 == 1) && (iVar10 = (**(code **)(*(int *)pTVar14 + 0x4c))(pTVar14), 1 < iVar10)) {
      uVar18 = *(undefined4 *)this;
      pcVar20 = *(code **)(*(int *)pTVar14 + 0x5c);
      uVar19 = 0;
      pTVar16 = pTVar14;
      pTVar17 = pTVar12;
    }
    else {
      uVar18 = *(undefined4 *)this;
      pcVar20 = *(code **)(*(int *)pTVar12 + 0x5c);
      uVar19 = 1;
      pTVar16 = pTVar12;
      pTVar17 = pTVar14;
    }
    piVar7 = (int *)(*pcVar20)(pTVar16,piVar9[0xc],pTVar17,uVar18,uVar19);
    if (piVar7 != (int *)0x0) {
      return piVar7;
    }
    (**(code **)(*piVar9 + 0x60))(piVar9,pTVar12);
  }
  pcVar20 = *(code **)(*piVar9 + 100);
LAB_97b8d618:
  (*pcVar20)(piVar9,pTVar14);
  return piVar9;
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
  ulong uVar3;
  int *piVar4;
  int iVar5;
  unsigned char * pTVar6;
  int *piVar7;
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
  
  uVar3 = GetGlobalPoolAllocator();
  piVar4 = (int *)TPoolAllocator__allocate(uVar3);
  local_2c = local_2c & 0x1ff | 0x80800;
  local_4c = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_48 = 0;
  piVar4[1] = 0;
  *piVar4 = (int)&PTR_getLine_a7b7cf90;
  piVar4[3] = 0;
  piVar4[4] = 0;
  piVar4[5] = 0;
  piVar4[6] = 0;
  piVar4[7] = 0;
  piVar4[8] = 0;
  piVar4[2] = (int)&PTR__TType_a7b7cff8;
  piVar4[9] = 0;
  piVar4[10] = 0;
  uVar2 = piVar4[0xb];
  piVar4[0xb] = uVar2 & 0x1ffffff;
  piVar4[0xb] = uVar2 & 0x7ffff | 0x80000;
  piVar4[0xb] = uVar2 & 0x7ff | 0x80800;
  piVar4[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d8;
  piVar4[0xb] = uVar2 & 0x1ff | 0x80800;
  local_50 = &PTR__TType_a7b7cff8;
  *piVar4 = (int)(puVar1 + 8);
  piVar4[0xc] = param_2;
  if (param_5 == 0) {
    param_5 = (**(code **)*param_3)(param_3);
  }
  (**(code **)(*piVar4 + 4))(piVar4,param_5);
  iVar5 = (**(code **)(*param_4 + 0x18))(param_4);
  if (iVar5 != 0) {
    pTVar6 = (unsigned char *)(**(code **)(*param_4 + 0x18))(param_4);
    param_4 = (int *)TIntermediate__copyConstUnion(this,pTVar6);
    if (param_4 == (int *)0x0) {
      return (int *)0x0;
    }
  }
  (**(code **)(*param_3 + 0x38))(&local_50,param_3);
  iVar5 = ((int (*)())TIntermediate__addConversion)(this,param_2,&local_50,param_4);
  local_50 = &PTR__TType_a7b7cff8;
  piVar7 = (int *)0x0;
  if (iVar5 != 0) {
    (**(code **)(*piVar4 + 0x60))(piVar4,param_3);
    (**(code **)(*piVar4 + 100))(piVar4,iVar5);
    iVar5 = (**(code **)(*piVar4 + 0x5c))(piVar4,*(undefined4 *)this);
    piVar7 = (int *)0x0;
    if (iVar5 != 0) {
      piVar7 = piVar4;
    }
  }
  return piVar7;
}

/* TIntermediate__addIndex @ 0x97b8d8bc (460 bytes) */
int TIntermediate__addIndex(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 *param_4;
  int param_5;
{
  undefined *puVar1;
  uint uVar2;
  ulong uVar3;
  int *piVar4;
  
  uVar3 = GetGlobalPoolAllocator();
  piVar4 = (int *)TPoolAllocator__allocate(uVar3);
  piVar4[1] = 0;
  *piVar4 = (int)&PTR_getLine_a7b7cf90;
  piVar4[3] = 0;
  piVar4[4] = 0;
  piVar4[5] = 0;
  piVar4[6] = 0;
  piVar4[7] = 0;
  piVar4[8] = 0;
  piVar4[2] = (int)&PTR__TType_a7b7cff8;
  piVar4[9] = 0;
  piVar4[10] = 0;
  uVar2 = piVar4[0xb];
  piVar4[0xb] = uVar2 & 0x1ffffff;
  piVar4[0xb] = uVar2 & 0x7ffff | 0x80000;
  piVar4[0xb] = uVar2 & 0x7ff | 0x80800;
  piVar4[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d8;
  piVar4[0xb] = uVar2 & 0x1ff | 0x80800;
  piVar4[0xc] = param_2;
  *piVar4 = (int)(puVar1 + 8);
  if (param_5 == 0) {
    param_5 = (**(code **)*param_4)(param_4);
  }
  (**(code **)(*piVar4 + 4))(piVar4,param_5);
  (**(code **)(*piVar4 + 0x60))(piVar4,param_3);
  (**(code **)(*piVar4 + 100))(piVar4,param_4);
  return piVar4;
}

/* TIntermediate__addUnaryMath @ 0x97b8da88 (1548 bytes) */
int TIntermediate__addUnaryMath(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  int param_2;
  int *param_3;
  uint param_4;
  unsigned char * param_5;
{
  bool bVar1;
  undefined *puVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined **ppuVar6;
  uint uVar7;
  undefined *puVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  unsigned char * pTVar13;
  unsigned char * pTVar14;
  int *piVar15;
  ulong uVar16;
  int *piVar17;
  char *pcVar18;
  char in_RESERVE;
  byte bVar19;
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
  
  piVar9 = (int *)(**(code **)(*param_3 + 0x14))(param_3);
  if (piVar9 == (int *)0x0) {
    pcVar18 = *(char **)this;
                    
    ((int (*)())TInfoSinkBase__append)(pcVar18);
    bVar1 = (param_4 & 0xffff) == 0;
    bVar19 = bVar1 << 1;
    if (bVar1) {
      _sprintf(local_110,"%d:? ",(int)param_4 >> 0x10);
    }
    else {
      _sprintf(local_110,"%d:%d",(int)param_4 >> 0x10);
    }
    std__string__string((unsigned char *)&local_120,local_110,aaStack_d0);
    *(undefined *)((int)local_120 + (int)local_120[-3]) = *PTR__S_terminal_a7b7c0b8;
    ((int (*)())TInfoSinkBase__append)(pcVar18);
    ppuVar6 = local_120 + -1;
    do {
      puVar8 = *ppuVar6;
      if (in_RESERVE != '\0') {
        puVar2 = (undefined *)storeWordConditionalIndexed(puVar8 + -1,0,ppuVar6);
        *ppuVar6 = puVar2;
        bVar19 = 2;
      }
    } while (!(bool)(bVar19 >> 1 & 1));
    if ((int)puVar8 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_120 + -3));
    }
    ((int (*)())TInfoSinkBase__append)(pcVar18);
    ((int (*)())TInfoSinkBase__append)(pcVar18);
    ((int (*)())TInfoSinkBase__append)(pcVar18);
    return (int *)0x0;
  }
  if (param_2 == 6) {
    bVar5 = false;
    bVar4 = false;
    bVar3 = false;
    bVar1 = false;
    (**(code **)(*piVar9 + 0x38))(&local_120,piVar9);
    if ((local_fc >> 0x13 & 0x3f) == 3) {
      bVar4 = true;
      (**(code **)(*piVar9 + 0x38))(local_c0,piVar9);
      if ((local_9c & 0x400) != 0) goto LAB_97b8dcfc;
      bVar3 = true;
      (**(code **)(*piVar9 + 0x38))(local_90,piVar9);
      if ((local_6c & 0x200) != 0) goto LAB_97b8dcfc;
      bVar1 = true;
      (**(code **)(*piVar9 + 0x38))(local_60,piVar9);
      if ((1 < (int)(local_3c << 0xd | local_3c >> 0x13) >> 0x18) && ((local_3c & 0x400) == 0))
      goto LAB_97b8dcfc;
LAB_97b8dd0c:
      local_60[0] = &PTR__TType_a7b7cff8;
    }
    else {
LAB_97b8dcfc:
      bVar5 = true;
      if (bVar1) goto LAB_97b8dd0c;
    }
    if (bVar3) {
      local_90[0] = &PTR__TType_a7b7cff8;
    }
    if (bVar4) {
      local_c0[0] = &PTR__TType_a7b7cff8;
    }
LAB_97b8ddc8:
    local_120 = &PTR__TType_a7b7cff8;
    if (bVar5) {
      return (int *)0x0;
    }
  }
  else if (param_2 < 7) {
    if (param_2 == 5) {
LAB_97b8dd4c:
      bVar5 = false;
      (**(code **)(*piVar9 + 0x38))(&local_120,piVar9);
      bVar1 = false;
      if ((local_fc >> 0x13 & 0x3f) == 0xe) {
LAB_97b8dda4:
        bVar5 = true;
        if (bVar1) goto LAB_97b8ddb4;
      }
      else {
        (**(code **)(*piVar9 + 0x38))(local_f0,piVar9);
        bVar1 = true;
        if ((local_cc & 0x200) != 0) goto LAB_97b8dda4;
LAB_97b8ddb4:
        local_f0[0] = &PTR__TType_a7b7cff8;
      }
      goto LAB_97b8ddc8;
    }
  }
  else if (param_2 - 9U < 4) goto LAB_97b8dd4c;
  if (param_2 == 0x67) {
    iVar12 = 3;
  }
  else if (param_2 < 0x68) {
    if (param_2 != 0x66) goto LAB_97b8decc;
    iVar12 = 2;
  }
  else {
    if (param_2 != 0x68) goto LAB_97b8decc;
    iVar12 = 1;
  }
  uVar7 = (**(code **)(*piVar9 + 0x48))(piVar9);
  uVar10 = (**(code **)(*piVar9 + 0x50))(piVar9);
  uVar11 = (**(code **)(*piVar9 + 0x54))(piVar9);
  local_fc = (uVar11 & 1) << 9 |
             (uVar10 & 1) << 10 | (uVar7 & 0xff) << 0xb | iVar12 << 0x13 | local_fc & 0x1ff;
  local_110[0x10] = '\0';
  local_110[0x11] = '\0';
  local_110[0x12] = '\0';
  local_110[0x13] = '\0';
  local_120 = &PTR__TType_a7b7cff8;
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
  piVar9 = (int *)((int (*)())TIntermediate__addConversion)(this,param_2,&local_120,piVar9);
  local_120 = &PTR__TType_a7b7cff8;
  if (piVar9 == (int *)0x0) {
    return (int *)0x0;
  }
LAB_97b8decc:
  if (2 < param_2 - 0x66U) {
    iVar12 = (**(code **)(*piVar9 + 0x18))(piVar9);
    if (iVar12 != 0) {
      pTVar13 = (unsigned char *)(**(code **)(*piVar9 + 0x18))(piVar9);
      piVar9 = (int *)TIntermediate__copyConstUnion(this,pTVar13);
    }
    iVar12 = (**(code **)(*piVar9 + 0x1c))(piVar9);
    if (iVar12 != 0) {
      (**(code **)(*piVar9 + 0x38))(&local_120,piVar9);
      local_120 = &PTR__TType_a7b7cff8;
      if (local_fc >> 0x19 == 2) {
        pTVar14 = (unsigned char *)(**(code **)(*piVar9 + 0x1c))(piVar9);
        piVar9 = (int *)TIntermediate__changeAggrToTempConst(this,pTVar14,param_5,param_4);
        iVar12 = (**(code **)(*piVar9 + 0x18))();
        if (*(int *)(iVar12 + 0x30) == 0) {
          return (int *)0x0;
        }
      }
    }
    piVar15 = (int *)(**(code **)(*piVar9 + 0x18))(piVar9);
    uVar16 = GetGlobalPoolAllocator();
    piVar17 = (int *)TPoolAllocator__allocate(uVar16);
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
    *piVar17 = (int)&PTR_getLine_a7b7cf90;
    piVar17[1] = 0;
    piVar17[3] = 0;
    piVar17[4] = 0;
    piVar17[5] = 0;
    piVar17[6] = 0;
    piVar17[7] = 0;
    piVar17[8] = 0;
    piVar17[2] = (int)&PTR__TType_a7b7cff8;
    piVar17[9] = 0;
    piVar17[10] = 0;
    uVar7 = piVar17[0xb];
    piVar17[0xb] = uVar7 & 0x1ffffff;
    piVar17[0xb] = uVar7 & 0x7ffff | 0x80000;
    piVar17[0xb] = uVar7 & 0x7ff | 0x80800;
    piVar17[0xb] = uVar7 & 0x3ff | 0x80800;
    puVar8 = PTR_vtable_a7b7c0d4;
    piVar17[0xb] = uVar7 & 0x1ff | 0x80800;
    local_120 = &PTR__TType_a7b7cff8;
    *piVar17 = (int)(puVar8 + 8);
    piVar17[0xd] = 0;
    piVar17[0xc] = param_2;
    if (param_4 == 0) {
      param_4 = (**(code **)*piVar9)(piVar9);
    }
    (**(code **)(*piVar17 + 4))(piVar17,param_4);
    (**(code **)(*piVar17 + 0x60))(piVar17,piVar9);
    iVar12 = (**(code **)(*piVar17 + 0x5c))(piVar17,*(undefined4 *)this);
    piVar9 = (int *)0x0;
    if ((iVar12 != 0) &&
       ((piVar15 == (int *)0x0 ||
        (piVar9 = (int *)(**(code **)(*piVar15 + 0x5c))(piVar15,param_2,0,*(undefined4 *)this,1),
        piVar9 == (int *)0x0)))) {
      piVar9 = piVar17;
    }
  }
  return piVar9;
}

/* TIntermediate__setAggregateOperator @ 0x97b8e1b8 (1132 bytes) */
int TIntermediate__setAggregateOperator(param_1_00, param_1, param_3, param_4)
  undefined4 param_1_00;
  int *param_1;
  undefined4 param_3;
  int param_4;
{
  bool bVar1;
  undefined *puVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  ulong uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  code *pcVar10;
  char in_RESERVE;
  byte bVar11;
  int *piStack0000001c;
  
  bVar11 = (param_1 == (int *)0x0) << 1;
  piStack0000001c = param_1;
  if (param_1 == (int *)0x0) {
    uVar6 = GetGlobalPoolAllocator();
    piVar5 = (int *)TPoolAllocator__allocate(uVar6);
    piVar5[1] = 0;
    *piVar5 = (int)&PTR_getLine_a7b7cf90;
    piVar5[3] = 0;
    piVar5[4] = 0;
    piVar5[5] = 0;
    piVar5[6] = 0;
    piVar5[7] = 0;
    piVar5[8] = 0;
    piVar5[2] = (int)&PTR__TType_a7b7cff8;
    piVar5[9] = 0;
    piVar5[10] = 0;
    uVar3 = piVar5[0xb];
    piVar5[0xb] = uVar3 & 0x1ffffff;
    piVar5[0xb] = uVar3 & 0x7ffff | 0x80000;
    piVar5[0xb] = uVar3 & 0x7ff | 0x80800;
    piVar5[0xb] = uVar3 & 0x3ff | 0x80800;
    puVar2 = PTR_vtable_a7b7c0d0;
    piVar5[0xb] = uVar3 & 0x1ff | 0x80800;
    *piVar5 = (int)(puVar2 + 8);
    piVar5[0xc] = 0;
    iVar7 = GetGlobalPoolAllocator();
    piVar5[0x10] = 0;
    piVar5[0xe] = 0;
    piVar5[0xf] = 0;
    piVar5[0xd] = iVar7;
    iVar7 = GetGlobalPoolAllocator();
    piVar5[0x11] = iVar7;
    iVar7 = DAT_a7b7b9b8;
    piVar5[0x14] = 0;
    piVar5[0x12] = 0;
    piVar4 = (int *)(iVar7 + 8);
    piVar5[0x13] = 0;
    do {
      if (in_RESERVE != '\0') {
        iVar8 = storeWordConditionalIndexed(*piVar4 + 1,0,piVar4);
        *piVar4 = iVar8;
        bVar11 = 2;
      }
    } while (!(bool)(bVar11 >> 1 & 1));
    iVar8 = GetGlobalPoolAllocator();
    piVar5[0x16] = iVar7 + 0xc;
    bVar1 = param_4 == 0;
    piVar5[0x1a] = 0;
    piVar5[0x15] = iVar8;
    piVar5[0x17] = 0;
  }
  else {
    piVar5 = (int *)(**(code **)(*param_1 + 0x1c))(param_1);
    bVar11 = (piVar5 == (int *)0x0) << 1;
    if ((piVar5 == (int *)0x0) || (bVar1 = param_4 == 0, piVar5[0xc] != 0)) {
      uVar6 = GetGlobalPoolAllocator();
      piVar5 = (int *)TPoolAllocator__allocate(uVar6);
      piVar5[1] = 0;
      *piVar5 = (int)&PTR_getLine_a7b7cf90;
      piVar5[3] = 0;
      piVar5[4] = 0;
      piVar5[5] = 0;
      piVar5[6] = 0;
      piVar5[7] = 0;
      piVar5[8] = 0;
      piVar5[2] = (int)&PTR__TType_a7b7cff8;
      piVar5[9] = 0;
      piVar5[10] = 0;
      uVar3 = piVar5[0xb];
      piVar5[0xb] = uVar3 & 0x1ffffff;
      piVar5[0xb] = uVar3 & 0x7ffff | 0x80000;
      piVar5[0xb] = uVar3 & 0x7ff | 0x80800;
      piVar5[0xb] = uVar3 & 0x3ff | 0x80800;
      puVar2 = PTR_vtable_a7b7c0d0;
      piVar5[0xb] = uVar3 & 0x1ff | 0x80800;
      *piVar5 = (int)(puVar2 + 8);
      piVar5[0xc] = 0;
      iVar7 = GetGlobalPoolAllocator();
      piVar5[0x10] = 0;
      piVar5[0xe] = 0;
      piVar5[0xf] = 0;
      piVar5[0xd] = iVar7;
      iVar7 = GetGlobalPoolAllocator();
      piVar5[0x11] = iVar7;
      iVar7 = DAT_a7b7b9b8;
      piVar5[0x14] = 0;
      piVar5[0x12] = 0;
      piVar4 = (int *)(iVar7 + 8);
      piVar5[0x13] = 0;
      do {
        if (in_RESERVE != '\0') {
          iVar8 = storeWordConditionalIndexed(*piVar4 + 1,0,piVar4);
          *piVar4 = iVar8;
          bVar11 = 2;
        }
      } while (!(bool)(bVar11 >> 1 & 1));
      iVar8 = GetGlobalPoolAllocator();
      piVar5[0x16] = iVar7 + 0xc;
      piVar5[0x15] = iVar8;
      pcVar10 = *(code **)(*piVar5 + 100);
      piVar5[0x1a] = 0;
      piVar5[0x17] = 0;
      iVar7 = (*pcVar10)(piVar5);
      puVar9 = *(undefined4 **)(iVar7 + 8);
      if (puVar9 == *(undefined4 **)(iVar7 + 0xc)) {
        std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                  (iVar7,puVar9,&STACKARG(0x1c));
      }
      else {
        iVar8 = 0;
        if (puVar9 != (undefined4 *)0x0) {
          *puVar9 = piStack0000001c;
          iVar8 = *(int *)(iVar7 + 8);
        }
        *(int *)(iVar7 + 8) = iVar8 + 4;
      }
      bVar1 = false;
      if (param_4 == 0) {
        param_4 = (**(code **)*piStack0000001c)();
        bVar1 = param_4 == 0;
      }
    }
  }
  (**(code **)(*piVar5 + 0x60))(piVar5,param_3);
  if (!bVar1) {
    (**(code **)(*piVar5 + 4))(piVar5,param_4);
  }
  return piVar5;
}

/* TIntermediate__addConversion @ 0x97b8e624 (2944 bytes) */
int TIntermediate__addConversion(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  int *param_3;
  int *param_4;
{
  undefined *puVar1;
  undefined **ppuVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  ulong uVar8;
  unsigned char * pcVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  undefined4 *puVar15;
  uint uVar16;
  char *pcVar17;
  char in_RESERVE;
  byte bVar18;
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
  uint uStack_8c;
  char acStack_80 [64];
  longlong local_40;
  undefined1 auStack_38 [4];
  int local_34;
  
  iVar5 = (**(code **)(*param_4 + 0x40))(param_4);
  if (iVar5 == 0) {
    return (int *)0x0;
  }
  if ((-1 < iVar5) && (iVar5 - 5U < 8)) {
    return (int *)0x0;
  }
  (**(code **)(*param_4 + 0x38))(&local_c0,param_4);
  bVar14 = false;
  if (((param_3[9] & 0x1fffe00U) == (local_9c & 0x1fffe00)) && (param_3[2] == local_b8)) {
    bVar14 = true;
  }
  local_c0 = &PTR__TType_a7b7cff8;
  if (bVar14) {
    return param_4;
  }
  if (param_3[2] != 0) {
    return (int *)0x0;
  }
  (**(code **)(*param_4 + 0x38))((unsigned char *)&local_c0,param_4);
  local_c0 = &PTR__TType_a7b7cff8;
  if (local_b8 != 0) {
    return (int *)0x0;
  }
  iVar5 = (**(code **)(*param_3 + 0x38))(param_3);
  if (iVar5 != 0) {
    return (int *)0x0;
  }
  (**(code **)(*param_4 + 0x38))((unsigned char *)&local_c0,param_4);
  local_c0 = &PTR__TType_a7b7cff8;
  if ((local_9c & 0x200) != 0) {
    return (int *)0x0;
  }
  if (param_2 == 0x67) {
    uVar6 = 3;
  }
  else if (param_2 < 0x68) {
    if (param_2 != 0x66) {
LAB_97b8e794:
      uVar6 = (**(code **)(*param_3 + 0x20))(param_3);
      (**(code **)(*param_4 + 0x38))(&local_c0,param_4);
      if (uVar6 == (local_9c >> 0x13 & 0x3f)) {
        return param_4;
      }
      return (int *)0x0;
    }
    uVar6 = 2;
  }
  else {
    if (param_2 != 0x68) goto LAB_97b8e794;
    uVar6 = 1;
  }
  bVar14 = true;
  iVar5 = (**(code **)(*param_4 + 0x1c))(param_4);
  if (iVar5 == 0) {
LAB_97b8e8ac:
    iVar5 = (**(code **)(*param_4 + 0x1c))(param_4);
    if (iVar5 != 0) {
      piVar7 = (int *)(**(code **)(*param_4 + 0x1c))(param_4);
      iVar5 = (**(code **)(*piVar7 + 100))();
      puVar15 = *(undefined4 **)(iVar5 + 4);
      while( true ) {
        if (puVar15 == *(undefined4 **)(iVar5 + 8)) {
          piVar7 = (int *)(**(code **)(*param_4 + 0x1c))(param_4);
          return piVar7;
        }
        uVar8 = GetGlobalPoolAllocator();
        pcVar9 = (unsigned char *)TPoolAllocator__allocate(uVar8);
        if (uVar6 != 2) break;
        piVar7 = (int *)(**(code **)(*(int *)*puVar15 + 0x14))();
        (**(code **)(*piVar7 + 0x38))(&local_c0,piVar7);
        uVar16 = local_9c >> 0x13 & 0x3f;
        local_c0 = &PTR__TType_a7b7cff8;
        if (uVar16 == 1) {
          piVar7 = (int *)(**(code **)(*(int *)*puVar15 + 0x14))();
          iVar10 = (**(code **)(*piVar7 + 0x18))();
          local_40 = (longlong)(int)**(float **)(iVar10 + 0x30);
          *(int *)pcVar9 = (int)**(float **)(iVar10 + 0x30);
LAB_97b8ec88:
          local_9c = uVar6 << 0x13 | local_9c & 0x7ff | 0x4000000 | 0x800;
        }
        else {
          if (uVar16 != 3) {
            pcVar17 = *(char **)this;
            uVar6 = (**(code **)*param_4)(param_4);
                    
            goto override_jmp_97b8ea8c_case_0;
          }
          piVar7 = (int *)(**(code **)(*(int *)*puVar15 + 0x14))();
          iVar10 = (**(code **)(*piVar7 + 0x18))();
          *(undefined4 *)pcVar9 = **(undefined4 **)(iVar10 + 0x30);
LAB_97b8ecd8:
          local_9c = uVar6 << 0x13 | local_9c & 0xfff | 0x4000000 | 0x800;
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
        local_c0 = &PTR__TType_a7b7cff8;
        iVar10 = (**(code **)*param_4)(param_4);
        iVar10 = ((int (*)())TIntermediate__addConstantUnion)(this,pcVar9,(unsigned char *)&local_c0,iVar10);
        local_c0 = &PTR__TType_a7b7cff8;
        if (iVar10 != 0) {
          std__vector_TIntermNode__pool_allocator_TIntermNode_____erase(auStack_38,iVar5,puVar15);
          local_34 = iVar10;
          std__vector_TIntermNode__pool_allocator_TIntermNode_____insert
                    (auStack_38,iVar5,puVar15,&local_34);
        }
        puVar15 = puVar15 + 1;
      }
      if (uVar6 < 3) {
        if (uVar6 == 1) {
          piVar7 = (int *)(**(code **)(*(int *)*puVar15 + 0x14))();
          (**(code **)(*piVar7 + 0x38))(&local_c0,piVar7);
          uVar16 = local_9c >> 0x13 & 0x3f;
          local_c0 = &PTR__TType_a7b7cff8;
          if (uVar16 == 2) {
            piVar7 = (int *)(**(code **)(*(int *)*puVar15 + 0x14))();
            iVar10 = (**(code **)(*piVar7 + 0x18))();
            uStack_8c = **(uint **)(iVar10 + 0x30) ^ 0x80000000;
            *(float *)pcVar9 = (float)((double)CONCAT44(0x43300000,uStack_8c) - DOUBLE_97c30a58);
          }
          else {
            if (uVar16 != 3) {
              pcVar17 = *(char **)this;
              uVar6 = (**(code **)*param_4)(param_4);
                    
              goto override_jmp_97b8ea8c_case_0;
            }
            piVar7 = (int *)(**(code **)(*(int *)*puVar15 + 0x14))();
            iVar10 = (**(code **)(*piVar7 + 0x18))();
            uStack_8c = **(uint **)(iVar10 + 0x30);
            *(float *)pcVar9 = (float)((double)CONCAT44(0x43300000,uStack_8c) - DOUBLE_97c30a68);
          }
          local_90 = 0x43300000;
          local_9c = local_9c & 0x7ff | 0x4080800;
          goto LAB_97b8ed90;
        }
      }
      else if (uVar6 == 3) {
        piVar7 = (int *)(**(code **)(*(int *)*puVar15 + 0x14))();
        (**(code **)(*piVar7 + 0x38))(&local_c0,piVar7);
        uVar16 = local_9c >> 0x13 & 0x3f;
        local_c0 = &PTR__TType_a7b7cff8;
        if (uVar16 == 1) {
          piVar7 = (int *)(**(code **)(*(int *)*puVar15 + 0x14))();
          iVar10 = (**(code **)(*piVar7 + 0x18))();
          *(uint *)pcVar9 = (uint)((double)**(float **)(iVar10 + 0x30) != DOUBLE_97c30a48);
          goto LAB_97b8ec88;
        }
        if (uVar16 == 2) {
          piVar7 = (int *)(**(code **)(*(int *)*puVar15 + 0x14))();
          iVar10 = (**(code **)(*piVar7 + 0x18))();
          *(uint *)pcVar9 = (uint)(**(int **)(iVar10 + 0x30) != 0);
          goto LAB_97b8ecd8;
        }
        pcVar17 = *(char **)this;
        uVar6 = (**(code **)*param_4)(param_4);
                    
        goto override_jmp_97b8ea8c_case_0;
      }
      pcVar17 = *(char **)this;
      uVar6 = (**(code **)*param_4)(param_4);
                    
      goto override_jmp_97b8ea8c_case_0;
    }
  }
  else {
    iVar5 = (**(code **)(*param_4 + 0x1c))(param_4);
    if (*(int *)(iVar5 + 0x30) == 2) {
      bVar14 = false;
    }
    else {
      piVar7 = (int *)(**(code **)(*param_4 + 0x1c))(param_4);
      iVar5 = (**(code **)(*piVar7 + 100))();
      for (puVar15 = *(undefined4 **)(iVar5 + 4); puVar15 != *(undefined4 **)(iVar5 + 8);
          puVar15 = puVar15 + 1) {
        piVar7 = (int *)(**(code **)(*(int *)*puVar15 + 0x14))();
        iVar10 = (**(code **)(*piVar7 + 0x18))();
        if (iVar10 == 0) {
          bVar14 = false;
        }
      }
    }
    if (bVar14) goto LAB_97b8e8ac;
  }
  iVar5 = (**(code **)(*param_4 + 0x18))(param_4);
  if (iVar5 != 0) {
    uVar11 = (**(code **)(*param_4 + 0x18))(param_4);
    piVar7 = (int *)TIntermediate__promoteConstantUnion(this,uVar6,uVar11);
    return piVar7;
  }
  if (uVar6 != 2) {
    if (uVar6 < 3) {
      if (uVar6 == 1) {
        iVar5 = (**(code **)(*param_4 + 0x40))(param_4);
        if (iVar5 == 2) {
          iVar10 = 0x10;
        }
        else {
          iVar10 = 0xf;
          if (iVar5 != 3) {
            pcVar17 = *(char **)this;
            uVar6 = (**(code **)*param_4)(param_4);
                    
            goto override_jmp_97b8ea8c_case_0;
          }
        }
        goto LAB_97b8f1ac;
      }
    }
    else if (uVar6 == 3) {
      iVar5 = (**(code **)(*param_4 + 0x40))(param_4);
      if (iVar5 == 1) {
        iVar10 = 0xe;
      }
      else {
        iVar10 = 0xd;
        if (iVar5 != 2) {
          pcVar17 = *(char **)this;
          uVar6 = (**(code **)*param_4)(param_4);
                    
          goto override_jmp_97b8ea8c_case_0;
        }
      }
      goto LAB_97b8f1ac;
    }
    pcVar17 = *(char **)this;
    uVar6 = (**(code **)*param_4)(param_4);
                    
override_jmp_97b8ea8c_case_0:
    ((int (*)())TInfoSinkBase__append)(pcVar17);
    bVar14 = (uVar6 & 0xffff) == 0;
    bVar18 = bVar14 << 1;
    if (bVar14) {
      _sprintf(acStack_80,"%d:? ",(int)uVar6 >> 0x10);
    }
    else {
      _sprintf(acStack_80,"%d:%d",(int)uVar6 >> 0x10);
    }
    std__string__string((unsigned char *)&local_c0,acStack_80,(unsigned char *)&local_b0);
    *(undefined *)((int)local_c0 + (int)local_c0[-3]) = *PTR__S_terminal_a7b7c0b8;
    ((int (*)())TInfoSinkBase__append)(pcVar17);
    ppuVar2 = local_c0 + -1;
    do {
      puVar3 = *ppuVar2;
      if (in_RESERVE != '\0') {
        puVar1 = (undefined *)storeWordConditionalIndexed(puVar3 + -1,0,ppuVar2);
        *ppuVar2 = puVar1;
        bVar18 = 2;
      }
    } while (!(bool)(bVar18 >> 1 & 1));
    if ((int)puVar3 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_c0 + -3));
    }
    ((int (*)())TInfoSinkBase__append)(pcVar17);
    ((int (*)())TInfoSinkBase__append)(pcVar17);
    ((int (*)())TInfoSinkBase__append)(pcVar17);
    return (int *)0x0;
  }
  iVar5 = (**(code **)(*param_4 + 0x40))(param_4);
  if (iVar5 == 1) {
    iVar10 = 0x11;
  }
  else {
    iVar10 = 0x12;
    if (iVar5 != 3) {
      pcVar17 = *(char **)this;
      uVar6 = (**(code **)*param_4)(param_4);
                    
      goto override_jmp_97b8ea8c_case_0;
    }
  }
LAB_97b8f1ac:
  uVar16 = (**(code **)(*param_4 + 0x48))(param_4);
  uVar12 = (**(code **)(*param_4 + 0x50))(param_4);
  uVar13 = (**(code **)(*param_4 + 0x54))(param_4);
  local_c0 = &PTR__TType_a7b7cff8;
  local_9c = (uVar13 & 1) << 9 |
             (uVar12 & 1) << 10 | (uVar16 & 0xff) << 0xb | uVar6 << 0x13 | local_9c & 0x1ff;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  uVar8 = GetGlobalPoolAllocator();
  piVar7 = (int *)TPoolAllocator__allocate(uVar8);
  piVar7[1] = 0;
  *piVar7 = (int)&PTR_getLine_a7b7cf90;
  piVar7[3] = local_bc;
  piVar7[4] = local_b8;
  piVar7[5] = local_b4;
  piVar7[6] = local_b0;
  piVar7[7] = local_ac;
  piVar7[8] = local_a8;
  piVar7[2] = (int)&PTR__TType_a7b7cff8;
  piVar7[10] = local_a0;
  piVar7[9] = local_a4;
  puVar3 = PTR_vtable_a7b7c0d4;
  uVar4 = piVar7[0xb];
  uVar16 = local_9c & 0xfe000000;
  piVar7[0xb] = uVar16 | uVar4 & 0x1ffffff;
  uVar12 = (local_9c >> 0x13 & 0x3f) << 0x13;
  piVar7[0xb] = uVar12 | uVar16 | uVar4 & 0x7ffff;
  uVar6 = local_9c & 0x7f800;
  piVar7[0xb] = uVar6 | uVar12 | uVar16 | uVar4 & 0x7ff;
  uVar13 = (local_9c >> 10 & 1) << 10;
  piVar7[0xb] = uVar13 | uVar6 | uVar12 | uVar16 | uVar4 & 0x3ff;
  piVar7[0xb] = (local_9c >> 9 & 1) << 9 | uVar13 | uVar6 | uVar12 | uVar16 | uVar4 & 0x1ff;
  piVar7[0xc] = iVar10;
  *piVar7 = (int)(puVar3 + 8);
  piVar7[0xd] = 0;
  uVar11 = (**(code **)*param_4)(param_4);
  (**(code **)(puVar3 + 0xc))(piVar7,uVar11);
  (**(code **)(*piVar7 + 0x60))(piVar7,param_4);
  return piVar7;
}

/* TIntermediate__growAggregate @ 0x97b8f36c (760 bytes) */
int TIntermediate__growAggregate(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
  int param_3;
{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  ulong uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  char in_RESERVE;
  byte in_cr0;
  unsigned char * pTStack0000001c;
  unsigned char * pTStack00000020;
  
  if ((param_1 == (unsigned char *)0x0) && (param_2 == (unsigned char *)0x0)) {
    return (int *)0x0;
  }
  pTStack0000001c = param_1;
  pTStack00000020 = param_2;
  if (param_1 != (unsigned char *)0x0) {
    piVar4 = (int *)(**(code **)(*(int *)param_1 + 0x1c))();
    in_cr0 = (piVar4 == (int *)0x0) << 1;
    if ((piVar4 != (int *)0x0) && (piVar4[0xc] == 0)) goto LAB_97b8f5cc;
  }
  uVar5 = GetGlobalPoolAllocator();
  piVar4 = (int *)TPoolAllocator__allocate(uVar5);
  piVar4[1] = 0;
  *piVar4 = (int)&PTR_getLine_a7b7cf90;
  piVar4[3] = 0;
  piVar4[4] = 0;
  piVar4[5] = 0;
  piVar4[6] = 0;
  piVar4[7] = 0;
  piVar4[8] = 0;
  piVar4[2] = (int)&PTR__TType_a7b7cff8;
  piVar4[9] = 0;
  piVar4[10] = 0;
  uVar2 = piVar4[0xb];
  piVar4[0xb] = uVar2 & 0x1ffffff;
  piVar4[0xb] = uVar2 & 0x7ffff | 0x80000;
  piVar4[0xb] = uVar2 & 0x7ff | 0x80800;
  piVar4[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d0;
  piVar4[0xb] = uVar2 & 0x1ff | 0x80800;
  *piVar4 = (int)(puVar1 + 8);
  piVar4[0xc] = 0;
  iVar6 = GetGlobalPoolAllocator();
  piVar4[0x10] = 0;
  piVar4[0xe] = 0;
  piVar4[0xf] = 0;
  piVar4[0xd] = iVar6;
  iVar6 = GetGlobalPoolAllocator();
  piVar4[0x11] = iVar6;
  iVar6 = DAT_a7b7b9b8;
  piVar4[0x14] = 0;
  piVar4[0x12] = 0;
  piVar3 = (int *)(iVar6 + 8);
  piVar4[0x13] = 0;
  do {
    if (in_RESERVE != '\0') {
      iVar7 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar7;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  iVar7 = GetGlobalPoolAllocator();
  piVar4[0x16] = iVar6 + 0xc;
  piVar4[0x15] = iVar7;
  piVar4[0x1a] = 0;
  piVar4[0x17] = 0;
  if (pTStack0000001c != (unsigned char *)0x0) {
    iVar6 = (**(code **)(*piVar4 + 100))(piVar4);
    puVar8 = *(undefined4 **)(iVar6 + 8);
    if (puVar8 == *(undefined4 **)(iVar6 + 0xc)) {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                (iVar6,puVar8,&STACKARG(0x1c));
    }
    else {
      iVar7 = 0;
      if (puVar8 != (undefined4 *)0x0) {
        *puVar8 = pTStack0000001c;
        iVar7 = *(int *)(iVar6 + 8);
      }
      *(int *)(iVar6 + 8) = iVar7 + 4;
    }
  }
LAB_97b8f5cc:
  if (pTStack00000020 != (unsigned char *)0x0) {
    iVar6 = (**(code **)(*piVar4 + 100))(piVar4);
    puVar8 = *(undefined4 **)(iVar6 + 8);
    if (puVar8 == *(undefined4 **)(iVar6 + 0xc)) {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                (iVar6,puVar8,&STACKARG(0x20));
    }
    else {
      iVar7 = 0;
      if (puVar8 != (undefined4 *)0x0) {
        *puVar8 = pTStack00000020;
        iVar7 = *(int *)(iVar6 + 8);
      }
      *(int *)(iVar6 + 8) = iVar7 + 4;
    }
  }
  if (param_3 != 0) {
    (**(code **)(*piVar4 + 4))(piVar4,param_3);
  }
  return piVar4;
}

/* TIntermediate__makeAggregate @ 0x97b8f664 (632 bytes) */
int TIntermediate__makeAggregate(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  int param_2;
{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  ulong uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  code *pcVar9;
  char in_RESERVE;
  byte in_cr0;
  unsigned char * pTStack0000001c;
  
  piVar4 = (int *)0x0;
  if (param_1 != (unsigned char *)0x0) {
    pTStack0000001c = param_1;
    uVar5 = GetGlobalPoolAllocator();
    piVar4 = (int *)TPoolAllocator__allocate(uVar5);
    piVar4[1] = 0;
    *piVar4 = (int)&PTR_getLine_a7b7cf90;
    piVar4[3] = 0;
    piVar4[4] = 0;
    piVar4[5] = 0;
    piVar4[6] = 0;
    piVar4[7] = 0;
    piVar4[8] = 0;
    piVar4[2] = (int)&PTR__TType_a7b7cff8;
    piVar4[9] = 0;
    piVar4[10] = 0;
    uVar2 = piVar4[0xb];
    piVar4[0xb] = uVar2 & 0x1ffffff;
    piVar4[0xb] = uVar2 & 0x7ffff | 0x80000;
    piVar4[0xb] = uVar2 & 0x7ff | 0x80800;
    piVar4[0xb] = uVar2 & 0x3ff | 0x80800;
    puVar1 = PTR_vtable_a7b7c0d0;
    piVar4[0xb] = uVar2 & 0x1ff | 0x80800;
    *piVar4 = (int)(puVar1 + 8);
    piVar4[0xc] = 0;
    iVar6 = GetGlobalPoolAllocator();
    piVar4[0x10] = 0;
    piVar4[0xe] = 0;
    piVar4[0xf] = 0;
    piVar4[0xd] = iVar6;
    iVar6 = GetGlobalPoolAllocator();
    piVar4[0x11] = iVar6;
    iVar6 = DAT_a7b7b9b8;
    piVar4[0x14] = 0;
    piVar4[0x12] = 0;
    piVar3 = (int *)(iVar6 + 8);
    piVar4[0x13] = 0;
    do {
      if (in_RESERVE != '\0') {
        iVar7 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
        *piVar3 = iVar7;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    iVar7 = GetGlobalPoolAllocator();
    piVar4[0x16] = iVar6 + 0xc;
    piVar4[0x15] = iVar7;
    pcVar9 = *(code **)(*piVar4 + 100);
    piVar4[0x1a] = 0;
    piVar4[0x17] = 0;
    iVar6 = (*pcVar9)(piVar4);
    puVar8 = *(undefined4 **)(iVar6 + 8);
    if (puVar8 == *(undefined4 **)(iVar6 + 0xc)) {
      std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux
                (iVar6,puVar8,&STACKARG(0x1c));
    }
    else {
      iVar7 = 0;
      if (puVar8 != (undefined4 *)0x0) {
        *puVar8 = pTStack0000001c;
        iVar7 = *(int *)(iVar6 + 8);
      }
      *(int *)(iVar6 + 8) = iVar7 + 4;
    }
    if (param_2 == 0) {
      iVar6 = *piVar4;
      param_2 = (*(code *)**(undefined4 **)pTStack0000001c)();
      pcVar9 = *(code **)(iVar6 + 4);
    }
    else {
      pcVar9 = *(code **)(*piVar4 + 4);
    }
    (*pcVar9)(piVar4,param_2);
  }
  return piVar4;
}

/* TIntermediate__addSelection @ 0x97b8f8dc (516 bytes) */
int TIntermediate__addSelection(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
  undefined4 param_5;
{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  ulong uVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  code *pcVar8;
  undefined4 *puStack00000020;
  undefined4 *puStack00000024;
  
  puStack00000020 = param_3;
  puStack00000024 = param_4;
  iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
  if (iVar3 != 0) {
    piVar4 = (int *)(**(code **)(*param_2 + 0x14))(param_2);
    iVar3 = (**(code **)(*piVar4 + 0x18))();
    if (iVar3 != 0) {
      piVar4 = (int *)(**(code **)(*param_2 + 0x14))(param_2);
      iVar3 = (**(code **)(*piVar4 + 0x18))();
      if (**(int **)(iVar3 + 0x30) == 0) {
        return puStack00000024;
      }
      return puStack00000020;
    }
  }
  uVar5 = GetGlobalPoolAllocator();
  puVar6 = (undefined4 *)TPoolAllocator__allocate(uVar5);
  *puVar6 = &PTR_getLine_a7b7cf90;
  puVar6[1] = 0;
  puVar6[3] = 0;
  puVar6[4] = 0;
  puVar6[5] = 0;
  puVar6[6] = 0;
  puVar6[7] = 0;
  puVar6[8] = 0;
  puVar6[2] = &PTR__TType_a7b7cff8;
  puVar6[10] = 0;
  puVar6[9] = 0;
  uVar2 = puVar6[0xb];
  puVar6[0xb] = uVar2 & 0x1ffffff;
  puVar1 = PTR_vtable_a7b7c0cc;
  puVar7 = PTR_vtable_a7b7c0cc + 8;
  puVar6[0xb] = uVar2 & 0x7ffff;
  pcVar8 = *(code **)(puVar1 + 0xc);
  puVar6[0xb] = uVar2 & 0x7ff | 0x800;
  puVar6[0xb] = uVar2 & 0x3ff | 0x800;
  puVar6[0xb] = uVar2 & 0x1ff | 0x800;
  puVar6[0xc] = param_2;
  puVar6[0xd] = puStack00000020;
  puVar6[0xe] = puStack00000024;
  *puVar6 = puVar7;
  (*pcVar8)(puVar6,param_5);
  return puVar6;
}

/* TIntermediate__addComma @ 0x97b8fae0 (348 bytes) */
int TIntermediate__addComma(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
  int param_3;
{
  bool bVar1;
  unsigned char * pTVar2;
  int *piVar3;
  undefined **local_b0 [9];
  uint local_8c;
  undefined **local_80 [9];
  uint local_5c;
  undefined **local_50 [13];
  
  bVar1 = false;
  (**(code **)(*(int *)param_1 + 0x38))(local_b0);
  if (local_8c >> 0x19 == 2) {
    (**(code **)(*(int *)param_2 + 0x38))(local_80,param_2);
    bVar1 = local_5c >> 0x19 == 2;
    local_80[0] = &PTR__TType_a7b7cff8;
  }
  local_b0[0] = &PTR__TType_a7b7cff8;
  pTVar2 = param_2;
  if (!bVar1) {
    pTVar2 = (unsigned char *)
             ((int (*)())TIntermediate__growAggregate)(this,(unsigned char *)param_1,(unsigned char *)param_2,param_3);
    piVar3 = (int *)(**(code **)(*(int *)pTVar2 + 0x1c))();
    (**(code **)(*piVar3 + 0x60))(piVar3,0x25);
    (**(code **)(*(int *)param_2 + 0x38))(local_50,param_2);
    (**(code **)(*(int *)pTVar2 + 0x34))(pTVar2,local_50);
    local_50[0] = &PTR__TType_a7b7cff8;
    piVar3 = (int *)(**(code **)(*(int *)pTVar2 + 0x3c))(pTVar2);
    (**(code **)(*piVar3 + 0x28))(piVar3,0);
  }
  return pTVar2;
}

/* TIntermediate__addSelection_97b8fc3c @ 0x97b8fc3c (628 bytes) */
int TIntermediate__addSelection_97b8fc3c(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  unsigned char * pTVar7;
  int iVar8;
  ulong uVar9;
  unsigned char * pTVar10;
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
  
  (**(code **)(*(int *)param_2 + 0x38))(&local_60,param_2);
  pTVar7 = (unsigned char *)((int (*)())TIntermediate__addConversion)(this,1,&local_60,param_3);
  local_60 = &PTR__TType_a7b7cff8;
  if (pTVar7 == (unsigned char *)0x0) {
    (**(code **)(*(int *)param_3 + 0x38))(&local_60,param_3);
    param_2 = (unsigned char *)((int (*)())TIntermediate__addConversion)(this,1,&local_60,param_2);
    pTVar7 = param_3;
    if (param_2 == (unsigned char *)0x0) {
      return (unsigned char *)0x0;
    }
  }
  local_60 = &PTR__TType_a7b7cff8;
  iVar8 = (**(code **)(*(int *)param_1 + 0x18))(param_1);
  if (((iVar8 == 0) || (iVar8 = (**(code **)(*(int *)param_2 + 0x18))(param_2), iVar8 == 0)) ||
     (iVar8 = (**(code **)(*(int *)pTVar7 + 0x18))(pTVar7), iVar8 == 0)) {
    uVar9 = GetGlobalPoolAllocator();
    pTVar10 = (unsigned char *)TPoolAllocator__allocate(uVar9);
    (**(code **)(*(int *)param_2 + 0x38))(&local_60,param_2);
    *(int *)(pTVar10 + 4) = 0;
    *(undefined ***)pTVar10 = &PTR_getLine_a7b7cf90;
    *(int *)(pTVar10 + 0xc) = local_5c;
    *(int *)(pTVar10 + 0x10) = local_58;
    *(int *)(pTVar10 + 0x14) = local_54;
    *(int *)(pTVar10 + 0x18) = local_50;
    *(int *)(pTVar10 + 0x1c) = local_4c;
    *(int *)(pTVar10 + 0x20) = local_48;
    *(undefined ***)(pTVar10 + 8) = &PTR__TType_a7b7cff8;
    *(int *)(pTVar10 + 0x24) = local_44;
    *(int *)(pTVar10 + 0x28) = local_40;
    uVar6 = *(uint *)(pTVar10 + 0x2c);
    uVar2 = local_3c & 0xfe000000;
    *(uint *)(pTVar10 + 0x2c) = uVar2 | uVar6 & 0x1ffffff;
    uVar3 = (local_3c >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar10 + 0x2c) = uVar3 | uVar2 | uVar6 & 0x7ffff;
    uVar1 = local_3c & 0x7f800;
    *(uint *)(pTVar10 + 0x2c) = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
    uVar4 = (local_3c >> 10 & 1) << 10;
    *(uint *)(pTVar10 + 0x2c) = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
    puVar5 = PTR_vtable_a7b7c0cc;
    *(uint *)(pTVar10 + 0x2c) =
         (local_3c >> 9 & 1) << 9 | uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff;
    *(unsigned char **)(pTVar10 + 0x30) = param_1;
    *(undefined **)pTVar10 = puVar5 + 8;
    *(unsigned char **)(pTVar10 + 0x34) = param_2;
    *(unsigned char **)(pTVar10 + 0x38) = pTVar7;
    local_60 = &PTR__TType_a7b7cff8;
    (**(code **)(*(int *)pTVar10 + 4))(pTVar10,param_4);
  }
  else {
    iVar8 = (**(code **)(*(int *)param_1 + 0x18))(param_1);
    pTVar10 = param_2;
    if (**(int **)(iVar8 + 0x30) == 0) {
      pTVar10 = pTVar7;
    }
  }
  return pTVar10;
}

/* TIntermediate__addConstantUnion @ 0x97b8feb0 (300 bytes) */
int TIntermediate__addConstantUnion(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
  int param_3;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined *puVar7;
  ulong uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  code *pcVar17;
  
  uVar8 = GetGlobalPoolAllocator();
  puVar9 = (undefined4 *)TPoolAllocator__allocate(uVar8);
  puVar9[1] = 0;
  *puVar9 = &PTR_getLine_a7b7cf90;
  uVar5 = *(undefined4 *)(param_2 + 4);
  uVar15 = *(undefined4 *)(param_2 + 8);
  uVar10 = *(undefined4 *)(param_2 + 0x20);
  uVar16 = *(undefined4 *)(param_2 + 0xc);
  uVar14 = *(undefined4 *)(param_2 + 0x10);
  uVar13 = *(undefined4 *)(param_2 + 0x14);
  uVar12 = *(undefined4 *)(param_2 + 0x18);
  uVar11 = *(undefined4 *)(param_2 + 0x1c);
  puVar9[2] = &PTR__TType_a7b7cff8;
  puVar9[3] = uVar5;
  puVar9[10] = uVar10;
  puVar9[4] = uVar15;
  puVar9[5] = uVar16;
  puVar9[6] = uVar14;
  puVar9[7] = uVar13;
  puVar9[8] = uVar12;
  puVar9[9] = uVar11;
  uVar6 = puVar9[0xb];
  uVar2 = *(uint *)(param_2 + 0x24) & 0xfe000000;
  puVar9[0xb] = uVar2 | uVar6 & 0x1ffffff;
  uVar3 = (*(uint *)(param_2 + 0x24) >> 0x13 & 0x3f) << 0x13;
  puVar9[0xb] = uVar3 | uVar2 | uVar6 & 0x7ffff;
  uVar1 = *(uint *)(param_2 + 0x24) & 0x7f800;
  puVar9[0xb] = uVar1 | uVar3 | uVar2 | uVar6 & 0x7ff;
  uVar4 = (*(uint *)(param_2 + 0x24) >> 10 & 1) << 10;
  puVar9[0xb] = uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x3ff;
  puVar7 = PTR_vtable_a7b7c0c8 + 8;
  pcVar17 = *(code **)(PTR_vtable_a7b7c0c8 + 0xc);
  puVar9[0xb] = (*(uint *)(param_2 + 0x24) >> 9 & 1) << 9 |
                uVar4 | uVar1 | uVar3 | uVar2 | uVar6 & 0x1ff;
  puVar9[0xc] = param_1;
  *puVar9 = puVar7;
  (*pcVar17)(puVar9,param_3);
  return puVar9;
}

/* TIntermediate__addSwizzle @ 0x97b8ffdc (744 bytes) */
int TIntermediate__addSwizzle(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  int param_2;
{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  ulong uVar5;
  int *piVar6;
  int iVar7;
  unsigned char * pcVar8;
  undefined4 *puVar9;
  code *pcVar10;
  int iVar11;
  unsigned char * pTVar12;
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
  
  uVar5 = GetGlobalPoolAllocator();
  piVar6 = (int *)TPoolAllocator__allocate(uVar5);
  local_8c = local_8c & 0x1ff | 0x80800;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  *piVar6 = (int)&PTR_getLine_a7b7cf90;
  piVar6[1] = 0;
  piVar6[3] = 0;
  piVar6[4] = 0;
  piVar6[5] = 0;
  piVar6[6] = 0;
  piVar6[7] = 0;
  piVar6[8] = 0;
  piVar6[9] = 0;
  piVar6[2] = (int)&PTR__TType_a7b7cff8;
  piVar6[10] = 0;
  uVar2 = piVar6[0xb];
  piVar6[0xb] = uVar2 & 0x1ffffff;
  piVar6[0xb] = uVar2 & 0x7ffff | 0x80000;
  piVar6[0xb] = uVar2 & 0x7ff | 0x80800;
  piVar6[0xb] = uVar2 & 0x3ff | 0x80800;
  puVar1 = PTR_vtable_a7b7c0d0;
  piVar6[0xb] = uVar2 & 0x1ff | 0x80800;
  local_b0 = &PTR__TType_a7b7cff8;
  piVar6[0xc] = 1;
  *piVar6 = (int)(puVar1 + 8);
  local_80 = GetGlobalPoolAllocator();
  piVar6[0x10] = 0;
  piVar6[0xe] = 0;
  piVar6[0xf] = 0;
  piVar6[0xd] = local_80;
  local_70 = GetGlobalPoolAllocator();
  piVar6[0x11] = local_70;
  iVar7 = DAT_a7b7b9b8;
  piVar6[0x14] = 0;
  piVar6[0x12] = 0;
  piVar3 = (int *)(iVar7 + 8);
  piVar6[0x13] = 0;
  do {
    if (in_RESERVE != '\0') {
      iVar11 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar11;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  local_60 = GetGlobalPoolAllocator();
  piVar6[0x16] = iVar7 + 0xc;
  iVar11 = 0;
  piVar6[0x15] = local_60;
  pcVar10 = *(code **)(*piVar6 + 4);
  piVar6[0x1a] = 0;
  (*pcVar10)(piVar6,param_2);
  iVar7 = (**(code **)(*piVar6 + 100))(piVar6);
  if (0 < *(int *)(param_1 + 0x10)) {
    pTVar12 = param_1;
    do {
      uVar5 = GetGlobalPoolAllocator();
      pcVar8 = (unsigned char *)TPoolAllocator__allocate(uVar5);
      *(undefined4 *)pcVar8 = *(undefined4 *)pTVar12;
      local_8c = local_8c & 0x1ff | 0x4100800;
      pTVar12 = pTVar12 + 4;
      local_b0 = &PTR__TType_a7b7cff8;
      local_ac = 0;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_50[0] = ((int (*)())TIntermediate__addConstantUnion)(this,pcVar8,(unsigned char *)&local_b0,param_2);
      local_b0 = &PTR__TType_a7b7cff8;
      puVar9 = *(undefined4 **)(iVar7 + 8);
      if (puVar9 == *(undefined4 **)(iVar7 + 0xc)) {
        std__vector_TIntermNode__pool_allocator_TIntermNode______M_insert_aux(iVar7,puVar9,local_50)
        ;
      }
      else {
        iVar4 = 0;
        if (puVar9 != (undefined4 *)0x0) {
          *puVar9 = local_50[0];
          iVar4 = *(int *)(iVar7 + 8);
        }
        *(int *)(iVar7 + 8) = iVar4 + 4;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < *(int *)(param_1 + 0x10));
  }
  return piVar6;
}

/* TIntermediate__addLoop @ 0x97b902c4 (140 bytes) */
int TIntermediate__addLoop(this, param_1, param_2, param_3, param_4, param_5)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
  unsigned char * param_3;
  int param_4;
  int param_5;
{
  undefined *puVar1;
  ulong uVar2;
  undefined4 *puVar3;
  undefined3 in_register_0000001c;
  code *pcVar4;
  
  uVar2 = GetGlobalPoolAllocator();
  puVar3 = (undefined4 *)TPoolAllocator__allocate(uVar2);
  puVar1 = PTR_vtable_a7b7c0c4;
  puVar3[1] = 0;
  puVar3[2] = param_1;
  pcVar4 = *(code **)(puVar1 + 0xc);
  puVar3[3] = param_2;
  puVar3[4] = param_3;
  puVar3[5] = CONCAT31(in_register_0000001c,param_4);
  *puVar3 = puVar1 + 8;
  (*pcVar4)(puVar3,param_5);
  return puVar3;
}

/* TIntermediate__addBranch @ 0x97b90350 (12 bytes) */
int TIntermediate__addBranch(this, param_2, param_3)
  unsigned char * this;
  undefined4 param_2;
  undefined4 param_3;
{
  addBranch(this,param_2,0,param_3);
  return;
}

/* TIntermediate__addBranch_97b9035c @ 0x97b9035c (124 bytes) */
int TIntermediate__addBranch_97b9035c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined *puVar1;
  ulong uVar2;
  undefined4 *puVar3;
  code *pcVar4;
  
  uVar2 = GetGlobalPoolAllocator();
  puVar3 = (undefined4 *)TPoolAllocator__allocate(uVar2);
  puVar1 = PTR_vtable_a7b7c0c0;
  puVar3[1] = 0;
  puVar3[2] = param_2;
  pcVar4 = *(code **)(puVar1 + 0xc);
  puVar3[3] = param_3;
  *puVar3 = puVar1 + 8;
  (*pcVar4)(puVar3,param_4);
  return puVar3;
}

/* TIntermediate__postProcess @ 0x97b903d8 (96 bytes) */
int TIntermediate__postProcess(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int *piVar1;
  
  if (((param_2 != (int *)0x0) &&
      (piVar1 = (int *)(**(code **)(*param_2 + 0x1c))(), piVar1 != (int *)0x0)) &&
     (piVar1[0xc] == 0)) {
    (**(code **)(*piVar1 + 0x60))(piVar1,1);
  }
  return 1;
}

/* TIntermediate__remove @ 0x97b90438 (12 bytes) */
int TIntermediate__remove(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  if (param_1 == (unsigned char *)0x0) {
    return;
  }
  RemoveAllTreeNodes(param_1);
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

