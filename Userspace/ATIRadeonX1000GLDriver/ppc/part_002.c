#include "decls.h"

/* FUN_0000a2f0 @ 0xa2f0 (184 bytes) */
int FUN_0000a2f0(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  switch(param_1) {
  case 0x400:
  case 0x404:
  case 0x406:
    goto switchD_0000a324_caseD_400;
  case 0x401:
  case 0x407:
    if ((param_2 & 0x10) == 0) {
      return 1;
    }
    return 3;
  case 0x403:
    if ((param_2 & 0x400) == 0) {
      return 1;
    }
    if ((param_2 & 0x10) == 0) {
      return 0;
    }
    return 2;
  case 0x409:
    if (0xff < (param_2 & 0x300)) {
      return 7;
    }
    break;
  case 0x40a:
    if (0x1ff < (param_2 & 0x300)) {
      return 8;
    }
    break;
  case 0x40b:
    if (0x2ff < (param_2 & 0x300)) {
      return 9;
    }
  }
  if ((param_2 & 0x400) != 0) {
    return 0;
  }
switchD_0000a324_caseD_400:
  return 1;
}

/* FUN_0000a3f0 @ 0xa3f0 (592 bytes) */
int FUN_0000a3f0(param_1, param_2)
  uint param_1;
  undefined *param_2;
{
  if (param_2 == (undefined *)0x1a00) {
    return 1;
  }
  if (param_2 < (undefined *)0x1a01) {
    if (((unsigned char *)0x00001403) < param_2) {
      if (param_2 < ((unsigned char *)0x00001407)) {
        if (param_1 == 0x1909) {
          return 4;
        }
        if (param_1 < 0x190a) {
          if (0x18ff < param_1) {
            if (param_1 < 0x1907) {
              return 4;
            }
            if (param_1 == 0x1907) {
              return 0xc;
            }
          }
          return 0x10;
        }
        if (param_1 == 0x8049) {
          return 4;
        }
        if (param_1 < 0x804a) {
          if (param_1 == 0x190a) {
            return 8;
          }
          return 0x10;
        }
        if (param_1 == 0x80e0) {
          return 0xc;
        }
        if (param_1 == 0x85b9) {
          return 8;
        }
        return 0x10;
      }
      if (param_2 != ((unsigned char *)0x0000140b)) {
        return 4;
      }
    }
    else if (param_2 < ((unsigned char *)0x00001402)) {
      if (param_2 == (undefined *)0x0) {
        if (1 < param_1 - 0x83f0) {
          return 0x10;
        }
        return 8;
      }
      if (param_2 <= ((unsigned char *)0x000013ff)) {
        return 4;
      }
      if (param_1 == 0x1909) {
        return 1;
      }
      if (param_1 < 0x190a) {
        if (param_1 < 0x1900) {
          return 4;
        }
        if (0x1906 < param_1) {
          if (param_1 != 0x1907) {
            return 4;
          }
          return 3;
        }
        return 1;
      }
      if (param_1 == 0x8049) {
        return 1;
      }
      if (param_1 < 0x804a) {
        if (param_1 == 0x190a) {
          return 2;
        }
        return 4;
      }
      if (param_1 == 0x80e0) {
        return 3;
      }
      if (param_1 == 0x85b9) {
        return 2;
      }
      return 4;
    }
    if (param_1 != 0x1909) {
      if (param_1 < 0x190a) {
        if (0x18ff < param_1) {
          if (param_1 < 0x1907) {
            return 2;
          }
          if (param_1 == 0x1907) {
            return 6;
          }
        }
        return 8;
      }
      if (param_1 != 0x8049) {
        if (param_1 < 0x804a) {
          if (param_1 != 0x190a) {
            return 8;
          }
        }
        else {
          if (param_1 == 0x80e0) {
            return 6;
          }
          if (param_1 != 0x85b9) {
            return 8;
          }
        }
        return 4;
      }
    }
  }
  else {
    if (param_2 == (undefined *)0x8362) {
      return 1;
    }
    if (param_2 < (undefined *)0x8363) {
      if (param_2 == (undefined *)0x8032) {
        return 1;
      }
      if (param_2 < (undefined *)0x8032) {
        return 4;
      }
      if ((undefined *)0x8034 < param_2) {
        return 4;
      }
    }
    else if (((undefined *)0x8366 < param_2) && ((undefined *)0x1 < param_2 + -0x85ba)) {
      return 4;
    }
  }
  return 2;
}

/* FUN_0000a670 @ 0xa670 (100 bytes) */
int FUN_0000a670(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = ((int (*)())FUN_0000a3f0)(param_1,0);
    iVar1 = iVar1 * (param_3 + 3 >> 2) >> 2;
  }
  else if (param_2 == 0x1a00) {
    iVar1 = param_3 + 7 >> 3;
  }
  else {
    iVar1 = ((int (*)())FUN_0000a3f0)(param_1,param_2);
    iVar1 = iVar1 * param_3;
  }
  return iVar1;
}

/* FUN_0000a6e0 @ 0xa6e0 (292 bytes) */
int FUN_0000a6e0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  uint *param_6;
  int *param_7;
  int *param_8;
  int *param_9;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = ((int (*)())FUN_0000a3f0)(param_2,param_3);
  *param_7 = iVar2;
  if (param_9 == (int *)0x0) {
    *param_8 = 0;
    uVar3 = ((int (*)())FUN_0000a670)(param_2,param_3,param_4);
    *param_6 = uVar3;
  }
  else {
    iVar4 = *param_9;
    if (iVar4 < 1) {
      uVar3 = ((int (*)())FUN_0000a670)(param_2,param_3,param_4);
    }
    else if (param_3 == 0x1a00) {
      uVar3 = iVar4 + 7 >> 3;
    }
    else {
      uVar3 = iVar2 * iVar4;
    }
    uVar1 = param_9[5];
    iVar4 = uVar3 - (uVar3 / uVar1) * uVar1;
    if (iVar4 != 0) {
      uVar3 = uVar3 + (uVar1 - iVar4);
    }
    *param_6 = uVar3;
    iVar4 = param_9[1];
    if (param_9[1] < 1) {
      iVar4 = param_5;
    }
    if (param_3 == 0x1a00) {
      iVar2 = param_9[3] >> 3;
    }
    else {
      iVar2 = iVar2 * param_9[3];
    }
    *param_8 = iVar2 + uVar3 * param_9[2] + uVar3 * iVar4 * param_9[4];
  }
  return;
}

/* FUN_0000a820 @ 0xa820 (452 bytes) */
int FUN_0000a820(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar6 = *(int *)(param_1 + 0x18);
  piVar5 = *(int **)(iVar6 + 0x19c);
  if ((piVar5 == (int *)0x0) &&
     (((((unsigned char *)0x0000430c)[*(int *)(param_1 + 0x10)] == '\0' ||
       (*(undefined4 **)(iVar6 + 400) == (undefined4 *)0x0)) ||
      (*(short *)**(undefined4 **)(iVar6 + 400) != -0x77fc)))) {
    uVar7 = 0;
    uVar8 = 0;
    bVar2 = true;
  }
  else {
    bVar2 = false;
    if (piVar5 == (int *)0x0) {
      param_2 = 0xffffffff;
      uVar7 = *(uint *)(**(int **)(iVar6 + 400) + 8);
      uVar8 = *(uint *)(**(int **)(iVar6 + 400) + 0xc);
    }
    else {
      param_2 = 0xffffffff;
      uVar7 = *(uint *)(*piVar5 + 8);
      uVar8 = *(uint *)(*piVar5 + 0xc);
    }
  }
  iVar11 = 0;
  iVar9 = 0;
  iVar10 = 0;
  iVar6 = param_1;
  do {
    if ((param_2 & 1) != 0) {
      if (bVar2) {
        uVar3 = 0;
        iVar12 = 5;
        do {
          if ((*(uint *)(((unsigned char *)0x000031d4) + iVar10 + *(int *)(param_1 + 0x10)) & 1 << (uVar3 & 0x3f))
              != 0) goto LAB_0000a96c;
          uVar3 = uVar3 + 1;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
LAB_0000a924:
        iVar12 = 0;
      }
      else {
        uVar3 = iVar11 * 4 - 0x20;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar7 << 1) << (iVar11 * -4 + 0x1fU & 0x3f) | uVar8 >> (iVar11 * 4 & 0x3cU);
        }
        else {
          uVar3 = uVar7 >> (uVar3 & 0x3f);
        }
        uVar3 = uVar3 & 0xf;
        if (4 < uVar3) goto LAB_0000a924;
LAB_0000a96c:
        iVar12 = *(int *)(iVar9 + *(int *)(param_1 + 0x18) + uVar3 * 4);
        if ((*(short *)(*(int *)(iVar12 + 0x30) + 0x5c) == 0) ||
           (((*(byte *)(iVar12 + 0x39) & 0x87) != 0 &&
            (iVar4 = FUN_00032100(param_1,iVar12,param_3,param_4,param_5,param_6), iVar4 == 0))))
        goto LAB_0000a924;
      }
      *(int *)(iVar6 + 0x18c) = iVar12;
    }
    bVar1 = iVar11 == 0xf;
    iVar10 = iVar10 + 0x7c;
    iVar9 = iVar9 + 0x14;
    param_2 = param_2 >> 1;
    iVar6 = iVar6 + 4;
    iVar11 = iVar11 + 1;
    if (bVar1) {
      return;
    }
  } while( true );
}

/* FUN_0000a9f0 @ 0xa9f0 (244 bytes) */
int FUN_0000a9f0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = *(int *)(param_2 + 0x30);
  iVar6 = 0xc;
  uVar1 = (uint)*(byte *)(iVar3 + 0xaa);
  uVar5 = (uint)*(ushort *)(iVar3 + 0xa4) + uVar1 * -2;
  uVar4 = (uint)*(ushort *)(iVar3 + 0xa6) - uVar1 * *(byte *)(iVar3 + 0x6e);
  uVar1 = (uint)*(ushort *)(iVar3 + 0xa8) - uVar1 * *(byte *)(iVar3 + 0x6f);
  iVar2 = uVar1 * uVar5 * uVar4;
  do {
    if ((((uVar5 == 1) && (uVar4 == 1)) && (uVar1 == 1)) || (*(ushort *)(iVar3 + 0x5c) < 0x2602))
    break;
    uVar5 = uVar5 >> 1;
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    uVar4 = uVar4 >> 1;
    if (uVar4 == 0) {
      uVar4 = 1;
    }
    uVar1 = uVar1 >> 1;
    if (uVar1 == 0) {
      uVar1 = 1;
    }
    iVar2 = iVar2 + uVar1 * uVar5 * uVar4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  uVar5 = (uint)*(byte *)(iVar3 + 0x6c) * iVar2;
  iVar2 = FUN_00030f00(param_1,param_2);
  if (iVar2 < 0) {
    uVar5 = uVar5 / (uint)-iVar2;
  }
  else {
    uVar5 = uVar5 * iVar2;
  }
  return uVar5;
}

/* FUN_0000aaf0 @ 0xaaf0 (244 bytes) */
int FUN_0000aaf0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x34);
  if (iVar3 != 0) {
    if (*(char *)(iVar3 + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(iVar3 + 0x10)) {
        _gldFlush(param_1);
      }
      iVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 + 8));
      if (iVar1 == 0) {
        uVar2 = *(undefined4 *)(param_1 + 4);
        iVar3 = iVar3 + 8;
LAB_0000abac:
        _io_connect_method_scalarI_structureI(uVar2,9,iVar3,1,0,0);
        return;
      }
    }
    else if (*(char *)(iVar3 + 0x16) == '\a') {
      if (0x1ffff < *(int *)(iVar3 + 0x10)) {
        _gldFlush(param_1);
      }
      iVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 + 0xc));
      if (iVar1 == 0) {
        uVar2 = *(undefined4 *)(param_1 + 4);
        iVar3 = iVar3 + 0xc;
        goto LAB_0000abac;
      }
    }
  }
  return;
}

/* FUN_0000abf0 @ 0xabf0 (184 bytes) */
int FUN_0000abf0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x34);
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush(param_1);
      }
      uVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 8));
      return uVar1;
    }
    if (*(char *)(iVar2 + 0x16) == '\a') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush(param_1);
      }
      uVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 0xc));
      return uVar1;
    }
  }
  return 1;
}

/* FUN_0000acb0 @ 0xacb0 (568 bytes) */
int FUN_0000acb0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  
  iVar10 = param_2[0xd];
  if ((((iVar10 == 0) || (*(char *)(iVar10 + 0x16) != '\x03')) || (param_3 != param_2[2])) ||
     (param_4 != param_2[3])) {
LAB_0000adc0:
    *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    if (iVar10 != 0) {
      piVar5 = (int *)(iVar10 + 0x10);
      do {
        iVar9 = *piVar5;
        if (in_RESERVE != '\0') {
          iVar7 = storeWordConditionalIndexed(iVar9 + -0x10000,0,piVar5);
          *piVar5 = iVar7;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar9 == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar10,1,0,0);
      }
      param_2[0xd] = 0;
    }
    param_2[2] = param_3;
    param_2[3] = param_4;
    param_2[1] = 3;
    local_38 = 8;
    iVar10 = _io_connect_method_structureI_structureO
                       (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,&local_34,&local_38);
    uVar8 = 0;
    if (iVar10 == 0) {
      param_2[0xd] = local_30;
      piVar5 = (int *)(local_30 + 0x10);
      do {
        if (in_RESERVE != '\0') {
          iVar10 = storeWordConditionalIndexed(*piVar5 + 0x10000,0,piVar5);
          *piVar5 = iVar10;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      uVar8 = 1;
      *param_2 = local_34;
      *(undefined1 *)(local_30 + 0x14) = 1;
    }
  }
  else {
    iVar9 = param_2[0xc];
    if (0x1ffff < *(int *)(iVar10 + 0x10)) {
      _gldFlush(param_1);
    }
    uVar6 = (uint)*(byte *)(iVar9 + 0x6c);
    if (uVar6 == 0) {
LAB_0000ad38:
      iVar9 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar10 + 0xc));
      if (iVar9 == 0) goto LAB_0000adc0;
    }
    else {
      if ((ushort)((*(ushort *)(iVar10 + 0x1c) | *(ushort *)(iVar10 + 0x28)) &
                  ~*(ushort *)(iVar9 + 0x7c)) == 0) {
        in_cr0 = 2;
        iVar7 = iVar10;
        if (uVar6 == 0) {
          uVar6 = 1;
        }
        do {
          uVar6 = uVar6 - 1;
          if (uVar6 == 0) goto LAB_0000ad38;
          puVar2 = (ushort *)(iVar7 + 0x2a);
          puVar3 = (ushort *)(iVar7 + 0x1e);
          iVar7 = iVar7 + 2;
          puVar4 = (ushort *)(iVar9 + 0x7e);
          iVar9 = iVar9 + 2;
          bVar1 = (ushort)((*puVar3 | *puVar2) & ~*puVar4) == 0;
          in_cr0 = bVar1 << 1;
        } while (bVar1);
      }
      iVar9 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar10 + 0xc));
      if (iVar9 == 0) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar10 + 0xc,1,0,0);
      }
    }
    uVar8 = 1;
    *(undefined1 *)(iVar10 + 0x14) = 1;
  }
  return uVar8;
}

/* FUN_0000aef4 @ 0xaef4 (580 bytes) */
int FUN_0000aef4(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  bool bVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  char in_RESERVE;
  byte in_cr0;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  
  iVar10 = param_2[0xd];
  if ((((iVar10 == 0) || (*(char *)(iVar10 + 0x16) != '\x06')) || (param_2[2] != 0)) ||
     ((param_2[3] != 0 || (param_3 != param_2[4])))) {
LAB_0000b010:
    *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    if (iVar10 != 0) {
      piVar5 = (int *)(iVar10 + 0x10);
      do {
        iVar9 = *piVar5;
        if (in_RESERVE != '\0') {
          iVar7 = storeWordConditionalIndexed(iVar9 + -0x10000,0,piVar5);
          *piVar5 = iVar7;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar9 == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar10,1,0,0);
      }
      param_2[0xd] = 0;
    }
    param_2[4] = param_3;
    param_2[1] = 6;
    param_2[3] = 0;
    param_2[2] = 0;
    uStack_38 = 8;
    iVar10 = _io_connect_method_structureI_structureO
                       (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,&uStack_34,&uStack_38);
    uVar8 = 0;
    if (iVar10 == 0) {
      param_2[0xd] = iStack_30;
      piVar5 = (int *)(iStack_30 + 0x10);
      do {
        if (in_RESERVE != '\0') {
          iVar10 = storeWordConditionalIndexed(*piVar5 + 0x10000,0,piVar5);
          *piVar5 = iVar10;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      uVar8 = 1;
      *param_2 = uStack_34;
      *(undefined1 *)(iStack_30 + 0x14) = 1;
    }
  }
  else {
    iVar9 = param_2[0xc];
    if (0x1ffff < *(int *)(iVar10 + 0x10)) {
      _gldFlush(param_1);
    }
    uVar6 = (uint)*(byte *)(iVar9 + 0x6c);
    if (uVar6 == 0) {
LAB_0000af80:
      iVar9 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar10 + 8));
      if (iVar9 == 0) goto LAB_0000b010;
    }
    else {
      if ((ushort)((*(ushort *)(iVar10 + 0x1c) | *(ushort *)(iVar10 + 0x28)) &
                  ~*(ushort *)(iVar9 + 0x7c)) == 0) {
        in_cr0 = 2;
        iVar7 = iVar10;
        if (uVar6 == 0) {
          uVar6 = 1;
        }
        do {
          uVar6 = uVar6 - 1;
          if (uVar6 == 0) goto LAB_0000af80;
          puVar2 = (ushort *)(iVar7 + 0x2a);
          puVar3 = (ushort *)(iVar7 + 0x1e);
          iVar7 = iVar7 + 2;
          puVar4 = (ushort *)(iVar9 + 0x7e);
          iVar9 = iVar9 + 2;
          bVar1 = (ushort)((*puVar3 | *puVar2) & ~*puVar4) == 0;
          in_cr0 = bVar1 << 1;
        } while (bVar1);
      }
      iVar9 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar10 + 8));
      if (iVar9 == 0) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar10 + 8,1,0,0);
      }
    }
    uVar8 = 1;
    *(undefined1 *)(iVar10 + 0x14) = 1;
  }
  return uVar8;
}

/* FUN_0000b150 @ 0xb150 (280 bytes) */
int FUN_0000b150(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_38;
  undefined1 auStack_34 [4];
  int local_30;
  
  uVar4 = 0;
  param_2[2] = param_3;
  param_2[3] = param_4;
  param_2[1] = 6;
  param_2[4] = param_5;
  *param_2 = 0;
  iVar5 = param_2[0xd];
  param_2[0xd] = 0;
  local_38 = 8;
  iVar3 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,auStack_34,&local_38);
  if (iVar3 == 0) {
    param_2[0xd] = local_30;
    piVar2 = (int *)(local_30 + 0x10);
    do {
      if (in_RESERVE != '\0') {
        iVar3 = storeWordConditionalIndexed(*piVar2 + 0x10000,0,piVar2);
        *piVar2 = iVar3;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    uVar4 = 1;
    *(undefined1 *)(local_30 + 0x14) = 1;
    if (iVar5 != local_30) {
      *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    }
  }
  if (iVar5 != 0) {
    piVar2 = (int *)(iVar5 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar5,1,0,0);
    }
  }
  return uVar4;
}

/* FUN_0000b270 @ 0xb270 (296 bytes) */
int FUN_0000b270(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  
  uVar4 = 0;
  param_2[2] = param_3;
  param_2[3] = param_4;
  param_2[1] = 7;
  param_2[4] = param_5;
  param_2[5] = param_6;
  *param_2 = 0;
  iVar5 = param_2[0xd];
  param_2[0xd] = 0;
  local_38 = 8;
  iVar3 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,&local_34,&local_38);
  if (iVar3 == 0) {
    param_2[0xd] = local_30;
    piVar2 = (int *)(local_30 + 0x10);
    do {
      if (in_RESERVE != '\0') {
        iVar3 = storeWordConditionalIndexed(*piVar2 + 0x10000,0,piVar2);
        *piVar2 = iVar3;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    uVar4 = 1;
    *(byte *)(local_30 + 0x14) = *(byte *)(local_30 + 0x14) | 1;
    *param_2 = local_34;
    if (iVar5 != local_30) {
      *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    }
  }
  if (iVar5 != 0) {
    piVar2 = (int *)(iVar5 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar5,1,0,0);
    }
  }
  return uVar4;
}

/* FUN_0000b3a0 @ 0xb3a0 (332 bytes) */
int FUN_0000b3a0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_38;
  undefined1 auStack_34 [4];
  int local_30;
  
  iVar4 = param_2[0xd];
  if ((((iVar4 == 0) || (*(char *)(iVar4 + 0x16) != '\0')) || (param_3 != param_2[2])) ||
     ((param_4 != param_2[3] || (uVar2 = 1, param_5 != param_2[4])))) {
    *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    if (iVar4 != 0) {
      piVar3 = (int *)(iVar4 + 0x10);
      do {
        iVar5 = *piVar3;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar5 + -0x10000,0,piVar3);
          *piVar3 = iVar1;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar5 == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar4,1,0,0);
      }
      param_2[0xd] = 0;
    }
    param_2[2] = param_3;
    param_2[3] = param_4;
    param_2[4] = param_5;
    param_2[1] = 0;
    local_38 = 8;
    iVar4 = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,auStack_34,&local_38);
    uVar2 = 0;
    if (iVar4 == 0) {
      param_2[0xd] = local_30;
      piVar3 = (int *)(local_30 + 0x10);
      if (in_RESERVE != '\0') {
        iVar4 = storeWordConditionalIndexed(*piVar3 + 0x10000,0,piVar3);
        *piVar3 = iVar4;
      }
      *param_2 = 0;
      uVar2 = 1;
    }
  }
  return uVar2;
}

/* FUN_0000b4f0 @ 0xb4f0 (292 bytes) */
int FUN_0000b4f0(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_28;
  undefined1 auStack_24 [4];
  int local_20;
  
  iVar4 = param_2[0xd];
  if (((iVar4 == 0) || (*(char *)(iVar4 + 0x16) != '\x01')) || (uVar2 = 1, param_3 != param_2[2])) {
    *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    if (iVar4 != 0) {
      piVar3 = (int *)(iVar4 + 0x10);
      do {
        iVar5 = *piVar3;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar5 + -0x10000,0,piVar3);
          *piVar3 = iVar1;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar5 == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar4,1,0,0);
      }
      param_2[0xd] = 0;
    }
    param_2[2] = param_3;
    param_2[1] = 1;
    local_28 = 8;
    iVar4 = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,auStack_24,&local_28);
    uVar2 = 0;
    if (iVar4 == 0) {
      param_2[0xd] = local_20;
      piVar3 = (int *)(local_20 + 0x10);
      if (in_RESERVE != '\0') {
        iVar4 = storeWordConditionalIndexed(*piVar3 + 0x10000,0,piVar3);
        *piVar3 = iVar4;
      }
      *param_2 = 0;
      uVar2 = 1;
    }
  }
  return uVar2;
}

/* FUN_0000b620 @ 0xb620 (72 bytes) */
int FUN_0000b620(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
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
  uint uVar3;
  
  uVar3 = (uint)*(byte *)(param_1 + 8);
  iVar1 = 0;
  iVar2 = (param_2 & uVar3 - 1) + (param_3 - uVar3);
  if (0 < iVar2) {
    do {
      dataCacheBlockStore((-uVar3 & param_2) + iVar1);
      iVar1 = iVar1 + uVar3;
    } while (iVar1 < iVar2);
  }
  dataCacheBlockFlush((-uVar3 & param_2) + iVar1);
  return;
}

/* FUN_0000b670 @ 0xb670 (80 bytes) */
int FUN_0000b670(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
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
  uint uVar3;
  
  uVar3 = (uint)*(byte *)(param_1 + 8);
  iVar1 = 0;
  iVar2 = ((param_2 & uVar3 - 1) + param_3) - uVar3;
  if (0 < iVar2) {
    do {
      dataCacheBlockFlush((-uVar3 & param_2) + iVar1);
      iVar1 = iVar1 + uVar3;
    } while (iVar1 < iVar2);
  }
  dataCacheBlockFlush((-uVar3 & param_2) + iVar1);
  sync(0);
  instructionSynchronize();
  return;
}

/* _gldCreateVertexArray @ 0xb6c0 (80 bytes) */
int _gldCreateVertexArray(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  
  puVar1 = _calloc(1,0x244);
  *param_2 = puVar1;
  *puVar1 = param_3;
  puVar1[1] = param_4;
  return 0;
}

/* _gldFlushVertexArray @ 0xb710 (56 bytes) */
int _gldFlushVertexArray(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (param_5 != 0) {
    ((int (*)())FUN_0000b620)(param_1,param_4,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  return param_5 != 0;
}

/* FUN_0000b750 @ 0xb750 (276 bytes) */
int FUN_0000b750(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(param_1 + 0x1d4);
  piVar3 = *(int **)(*(int *)(param_1 + 0x18) + 0x194);
  iVar1 = *piVar3;
  if ((*(uint *)(iVar1 + 0x308) & *(uint *)(iVar1 + 0x300)) == 0 &&
      (*(uint *)(iVar1 + 0x30c) & *(uint *)(iVar1 + 0x304)) == 0) {
    if ((((unsigned char *)0x000042fc)[*(int *)(param_1 + 0x10)] != '\0') ||
       (*(short *)(iVar1 + 0x312) != -0x7a4c)) {
      if (*(int *)(piVar3[1] + 0x84) == 0 && *(int *)(piVar3[1] + 0x88) == 0) goto LAB_0000b830;
      iVar1 = FUN_0001dc10(param_1,piVar3);
      goto joined_r0x0000b814;
    }
  }
  else {
    if (*(int *)(piVar3[1] + 0x84) == 0 && *(int *)(piVar3[1] + 0x88) == 0) goto LAB_0000b830;
    iVar1 = FUN_0001e730(param_1,piVar3);
joined_r0x0000b814:
    if (iVar1 != 0) goto LAB_0000b830;
  }
  piVar3 = (int *)0x0;
LAB_0000b830:
  *(int **)(param_1 + 0x1d4) = piVar3;
  if ((iVar2 != 0) && (piVar3 == (int *)0x0)) {
    FUN_0001dff0(param_1);
    return;
  }
  return;
}

/* FUN_0000b880 @ 0xb880 (244 bytes) */
int FUN_0000b880(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x228);
  if (iVar3 != 0) {
    if (*(char *)(iVar3 + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(iVar3 + 0x10)) {
        _gldFlush(param_1);
      }
      iVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 + 8));
      if (iVar1 == 0) {
        uVar2 = *(undefined4 *)(param_1 + 4);
        iVar3 = iVar3 + 8;
LAB_0000b93c:
        _io_connect_method_scalarI_structureI(uVar2,9,iVar3,1,0,0);
        return;
      }
    }
    else if (*(char *)(iVar3 + 0x16) == '\a') {
      if (0x1ffff < *(int *)(iVar3 + 0x10)) {
        _gldFlush(param_1);
      }
      iVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 + 0xc));
      if (iVar1 == 0) {
        uVar2 = *(undefined4 *)(param_1 + 4);
        iVar3 = iVar3 + 0xc;
        goto LAB_0000b93c;
      }
    }
  }
  return;
}

/* FUN_0000b980 @ 0xb980 (184 bytes) */
int FUN_0000b980(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x228);
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush(param_1);
      }
      uVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 8));
      return uVar1;
    }
    if (*(char *)(iVar2 + 0x16) == '\a') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush(param_1);
      }
      uVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 0xc));
      return uVar1;
    }
  }
  return 1;
}

/* _gldModifyVertexArray @ 0xba40 (248 bytes) */
int _gldModifyVertexArray(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  char in_RESERVE;
  
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  iVar5 = param_2[0x8a];
  if (iVar5 != 0) {
    bVar1 = ((*(uint *)(param_2[1] + 0x88) ^ 1) & 1) == 0;
    if (!bVar1) {
      if (*(short *)(*param_2 + 0x312) == -0x7a42) {
        uVar3 = param_2[0x8c] ^ 7;
      }
      else {
        uVar3 = param_2[0x8c] ^ 6;
      }
      if (uVar3 == 0) goto LAB_0000bb18;
    }
    piVar4 = (int *)(iVar5 + 0x10);
    do {
      iVar6 = *piVar4;
      if (in_RESERVE != '\0') {
        iVar2 = storeWordConditionalIndexed(iVar6 + -0x10000,0,piVar4);
        *piVar4 = iVar2;
        bVar1 = true;
      }
    } while (!bVar1);
    if (iVar6 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar5,1,0,0);
    }
    param_2[0x8a] = 0;
  }
LAB_0000bb18:
  _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
  return 0;
}

/* _gldReclaimVertexArray @ 0xbb40 (220 bytes) */
int _gldReclaimVertexArray(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  if (*(int *)(param_1 + 0x1d4) == param_2) {
    *(undefined4 *)(param_1 + 0x1d4) = 0;
    FUN_0001dff0(param_1);
  }
  iVar4 = *(int *)(param_2 + 0x228);
  if (iVar4 != 0) {
    if ((0x1ffff < (int)*(uint *)(iVar4 + 0x10)) || ((*(uint *)(iVar4 + 0x10) & 0xffff) != 0)) {
      _gldFlush(param_1);
    }
    ((int (*)())FUN_0000b880)(param_1,param_2);
    piVar2 = (int *)(iVar4 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar4,1,0,0);
    }
    *(undefined4 *)(param_2 + 0x228) = 0;
  }
  return;
}

/* _gldDestroyVertexArray @ 0xbc20 (56 bytes) */
int _gldDestroyVertexArray(param_1, param_2)
  undefined4 param_1;
  void *param_2;
{
  ((int (*)())_gldReclaimVertexArray)(param_1,param_2);
  _free(param_2);
  return 0;
}

/* FUN_0000bc60 @ 0xbc60 (248 bytes) */
int FUN_0000bc60(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_38;
  undefined1 auStack_34 [4];
  int local_30;
  
  uVar4 = 0;
  *(undefined4 *)(param_2 + 0x234) = param_3;
  *(undefined4 *)(param_2 + 0x238) = param_4;
  *(undefined4 *)(param_2 + 0x230) = 6;
  *(undefined4 *)(param_2 + 0x23c) = param_5;
  *(undefined4 *)(param_2 + 0x22c) = 0;
  iVar5 = *(int *)(param_2 + 0x228);
  *(undefined4 *)(param_2 + 0x228) = 0;
  local_38 = 8;
  iVar3 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 0x230,0x14,auStack_34,&local_38);
  if (iVar3 == 0) {
    *(int *)(param_2 + 0x228) = local_30;
    piVar2 = (int *)(local_30 + 0x10);
    do {
      if (in_RESERVE != '\0') {
        iVar3 = storeWordConditionalIndexed(*piVar2 + 0x10000,0,piVar2);
        *piVar2 = iVar3;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    uVar4 = 1;
    *(undefined1 *)(local_30 + 0x14) = 1;
  }
  if (iVar5 != 0) {
    piVar2 = (int *)(iVar5 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar5,1,0,0);
    }
  }
  return uVar4;
}

/* FUN_0000bd60 @ 0xbd60 (264 bytes) */
int FUN_0000bd60(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  
  uVar4 = 0;
  *(undefined4 *)(param_2 + 0x234) = param_3;
  *(undefined4 *)(param_2 + 0x238) = param_4;
  *(undefined4 *)(param_2 + 0x230) = 7;
  *(undefined4 *)(param_2 + 0x23c) = param_5;
  *(undefined4 *)(param_2 + 0x240) = param_6;
  *(undefined4 *)(param_2 + 0x22c) = 0;
  iVar5 = *(int *)(param_2 + 0x228);
  *(undefined4 *)(param_2 + 0x228) = 0;
  local_38 = 8;
  iVar3 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 0x230,0x14,&local_34,&local_38);
  if (iVar3 == 0) {
    *(int *)(param_2 + 0x228) = local_30;
    piVar2 = (int *)(local_30 + 0x10);
    do {
      if (in_RESERVE != '\0') {
        iVar3 = storeWordConditionalIndexed(*piVar2 + 0x10000,0,piVar2);
        *piVar2 = iVar3;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    uVar4 = 1;
    *(undefined1 *)(local_30 + 0x14) = 1;
    *(undefined4 *)(param_2 + 0x22c) = local_34;
  }
  if (iVar5 != 0) {
    piVar2 = (int *)(iVar5 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar5,1,0,0);
    }
  }
  return uVar4;
}

/* FUN_0000be70 @ 0xbe70 (272 bytes) */
double FUN_0000be70(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7)
{
  int iVar1;
  double dVar2;
  
  if (0 < param_1) {
    dVar2 = DOUBLE_001aa200;
    if (0x20 < param_1) {
      iVar1 = (param_1 - 0x21U >> 5) + 1;
      if (param_1 + -0x20 < 1) {
        iVar1 = 1;
      }
      do {
        dVar2 = dVar2 * DOUBLE_001aa1f8;
        param_1 = param_1 + -0x20;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    return dVar2 * *(double *)(&DAT_001aa3a8 + param_1 * 8);
  }
  if (-1 < param_1) {
    return DOUBLE_001aa200;
  }
  dVar2 = DOUBLE_001aa200;
  if (param_1 < -0x20) {
    iVar1 = (~(param_1 + 0x20U) >> 5) + 1;
    if (-1 < (int)(param_1 + 0x20U)) {
      iVar1 = 1;
    }
    do {
      dVar2 = dVar2 * DOUBLE_001aa1f0;
      param_1 = param_1 + 0x20;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return dVar2 * (DOUBLE_001aa2a8)[-param_1];
}

/* FUN_0000bfa0 @ 0xbfa0 (1332 bytes) */
char * FUN_0000bfa0(undefined4 param_1,undefined4 param_2,char *param_3,uint param_4,double fparam_1,double fparam_2)
{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  uint *puVar4;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined *puVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  uint local_78 [4];
  undefined4 local_68;
  uint uStack_64;
  longlong local_60;
  longlong local_58;
  longlong local_50;
  
  pcVar7 = param_3 + param_4;
  if (fparam_2 <= DOUBLE_001aa228) {
    fparam_2 = DOUBLE_001aa208;
  }
  if (param_4 < 2) {
    return (char *)0x0;
  }
  pcVar8 = param_3;
  if (fparam_1 < DOUBLE_001aa228) {
    fparam_1 = -fparam_1;
    pcVar8 = param_3 + 1;
    *param_3 = '-';
  }
  puVar5 = &DAT_001abfb4;
  dVar11 = fparam_1;
  if (fparam_1 <= DOUBLE_001aa228) {
    local_78[0] = 0;
    dVar12 = fparam_2 * DOUBLE_001aa240;
  }
  else {
    if ((fparam_1 < DOUBLE_001aa210) || (DOUBLE_001aa230 < fparam_1)) {
      puVar4 = local_78;
      _frexp(fparam_1,puVar4);
      local_68 = 0x43300000;
      uStack_64 = local_78[0] ^ 0x80000000;
      dVar11 = _round(((double)CONCAT44(0x43300000,uStack_64) - DOUBLE_001aa1e0) * DOUBLE_001aa218);
      local_78[0] = (uint)dVar11;
      local_60 = (longlong)(int)local_78[0];
      dVar12 = (double)((double (*)())FUN_0000be70)(local_78[0],extraout_r4,puVar4,param_4,in_r7,in_r8,puVar5);
      dVar11 = (double)((double (*)())FUN_0000be70)(-local_78[0],extraout_r4_00,puVar4,param_4,in_r7,in_r8,puVar5);
      dVar11 = fparam_1 * dVar11;
      dVar13 = fparam_2 * dVar12;
    }
    else {
      local_78[0] = 0;
      dVar13 = fparam_2;
    }
    dVar12 = fparam_2 * DOUBLE_001aa240;
    for (; dVar10 = dVar12 + dVar11, DOUBLE_001aa238 <= dVar10; dVar11 = dVar11 * DOUBLE_001aa220) {
      local_78[0] = local_78[0] + 1;
      dVar13 = dVar13 * DOUBLE_001aa238;
    }
    while (dVar10 < DOUBLE_001aa200) {
      dVar11 = dVar11 * DOUBLE_001aa238;
      local_78[0] = local_78[0] - 1;
      dVar13 = dVar13 * DOUBLE_001aa220;
      dVar10 = dVar12 + dVar11;
    }
    if ((int)(((int)local_78[0] >> 0x1f ^ local_78[0]) - ((int)local_78[0] >> 0x1f)) < 4) {
      local_78[0] = 0;
      dVar12 = dVar13 * DOUBLE_001aa240;
      fparam_2 = dVar13;
      dVar11 = fparam_1;
    }
  }
  dVar10 = _floor(dVar11 + dVar12);
  pcVar9 = pcVar8;
  dVar13 = dVar10;
  if (dVar10 <= fparam_2) {
LAB_0000c240:
    *pcVar9 = '0';
    pcVar9 = pcVar9 + 1;
  }
  else {
    do {
      if (pcVar9 == pcVar7) {
        return (char *)0x0;
      }
      dVar14 = dVar13 * DOUBLE_001aa220;
      dVar13 = _floor(dVar14);
      iVar3 = (int)((dVar14 - dVar13) * DOUBLE_001aa238);
      local_58 = (longlong)iVar3;
      *pcVar9 = (char)iVar3 + '0';
      pcVar9 = pcVar9 + 1;
    } while (fparam_2 < dVar13);
    if (pcVar9 <= pcVar8) goto LAB_0000c240;
    iVar3 = (int)pcVar9 - (int)pcVar8;
    if (1 < iVar3) {
      iVar2 = ((uint)(pcVar8 + (iVar3 * 2 - (int)pcVar9) + -2) >> 1) + 1;
      pcVar6 = pcVar9;
      if ((int)(pcVar8 + (iVar3 * 2 - (int)pcVar9) + -2) < 0) {
        iVar2 = 1;
      }
      do {
        pcVar6 = pcVar6 + -1;
        cVar1 = *pcVar6;
        *pcVar6 = *pcVar8;
        *pcVar8 = cVar1;
        pcVar8 = pcVar8 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  dVar10 = (dVar11 + dVar12) - dVar10;
  if (dVar10 <= fparam_2) {
    if (local_78[0] == 0) {
      if ((int)pcVar7 - (int)pcVar9 < 2) {
        return (char *)0x0;
      }
      *pcVar9 = '.';
      pcVar9[1] = '0';
      pcVar9 = pcVar9 + 2;
      goto LAB_0000c31c;
    }
  }
  else {
    if (pcVar9 == pcVar7) {
      return (char *)0x0;
    }
    *pcVar9 = '.';
    dVar11 = DOUBLE_001aa238;
    pcVar9 = pcVar9 + 1;
    do {
      if (pcVar7 == pcVar9) {
        return (char *)0x0;
      }
      dVar10 = dVar10 * dVar11;
      fparam_2 = fparam_2 * dVar11;
      dVar12 = _floor(dVar10);
      local_50 = (longlong)(int)dVar12;
      dVar10 = dVar10 - dVar12;
      *pcVar9 = (char)(int)dVar12 + '0';
      pcVar9 = pcVar9 + 1;
    } while (fparam_2 < dVar10);
LAB_0000c31c:
    if (local_78[0] == 0) goto LAB_0000c440;
  }
  if ((int)pcVar7 - (int)pcVar9 < 3) {
    return (char *)0x0;
  }
  pcVar8 = pcVar9 + 1;
  *pcVar9 = 'e';
  if ((int)local_78[0] < 0) {
    pcVar8 = pcVar9 + 2;
    pcVar9[1] = '-';
    local_78[0] = -local_78[0];
  }
  pcVar9 = pcVar8;
  if (0 < (int)local_78[0]) {
    if (pcVar8 == pcVar7) {
      return (char *)0x0;
    }
    iVar3 = (int)pcVar7 - (int)pcVar8;
    while( true ) {
      *pcVar9 = (char)local_78[0] + (char)((int)local_78[0] / 10) * -10 + '0';
      pcVar9 = pcVar9 + 1;
      local_78[0] = (int)local_78[0] / 10;
      if ((int)local_78[0] < 1) break;
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) {
        return (char *)0x0;
      }
    }
    if (1 < (int)pcVar9 - (int)pcVar8) {
      iVar3 = ((uint)(pcVar8 + (((int)pcVar9 - (int)pcVar8) * 2 - (int)pcVar9) + -2) >> 1) + 1;
      pcVar6 = pcVar9;
      if ((int)(pcVar8 + (((int)pcVar9 - (int)pcVar8) * 2 - (int)pcVar9) + -2) < 0) {
        iVar3 = 1;
      }
      do {
        pcVar6 = pcVar6 + -1;
        cVar1 = *pcVar6;
        *pcVar6 = *pcVar8;
        *pcVar8 = cVar1;
        pcVar8 = pcVar8 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
LAB_0000c440:
  if (pcVar9 == pcVar7) {
    return (char *)0x0;
  }
  *pcVar9 = '\0';
  return pcVar9;
}

/* FUN_0000c500 @ 0xc500 (892 bytes) */
double FUN_0000c500(char *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6)
{
  bool bVar1;
  bool bVar2;
  double dVar3;
  char cVar5;
  char *pcVar4;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  double dVar9;
  double dVar10;
  
  cVar5 = *param_1;
  if (cVar5 == '+') {
    param_1 = param_1 + 1;
    cVar5 = *param_1;
    bVar1 = false;
  }
  else {
    bVar1 = false;
    if (cVar5 == '-') {
      param_1 = param_1 + 1;
      cVar5 = *param_1;
      bVar1 = true;
    }
  }
  iVar6 = (int)cVar5;
  dVar10 = DOUBLE_001aa228;
  if (iVar6 == 0) goto LAB_0000c5a8;
  if (iVar6 == 0x2e) {
LAB_0000c670:
    pcVar4 = param_1 + 1;
    cVar5 = param_1[1];
    pcVar8 = pcVar4;
    while ((byte)(cVar5 - 0x30U) < 10) {
      pcVar8 = pcVar8 + 1;
      cVar5 = *pcVar8;
    }
    pcVar7 = pcVar8 + -1;
    dVar9 = DOUBLE_001aa228;
    if (pcVar4 <= pcVar7) {
      do {
        cVar5 = *pcVar7;
        pcVar7 = pcVar7 + -1;
        dVar9 = dVar9 * DOUBLE_001aa220 +
                ((double)CONCAT44(0x43300000,(int)cVar5 - 0x30U ^ 0x80000000) - DOUBLE_001aa1e0);
      } while (pcVar4 <= pcVar7);
      dVar9 = dVar9 * DOUBLE_001aa220;
    }
    cVar5 = *pcVar8;
    dVar10 = dVar10 + dVar9;
  }
  else {
    if ((iVar6 == 0x65) || (iVar6 == 0x45)) goto LAB_0000c5a8;
    pcVar4 = param_1;
    dVar9 = DOUBLE_001aa200;
    pcVar8 = param_1;
    if ((iVar6 - 0x30U & 0xff) < 10) {
      do {
        pcVar4 = pcVar4 + 1;
        pcVar8 = pcVar4;
      } while ((byte)(*pcVar4 - 0x30U) < 10);
    }
    while (pcVar4 = pcVar4 + -1, param_1 <= pcVar4) {
      dVar10 = dVar9 * ((double)CONCAT44(0x43300000,(int)*pcVar4 - 0x30U ^ 0x80000000) -
                       DOUBLE_001aa1e0) + dVar10;
      dVar9 = dVar9 * DOUBLE_001aa238;
    }
    cVar5 = *pcVar8;
    param_1 = pcVar8;
    if (cVar5 == '.') goto LAB_0000c670;
  }
  if ((cVar5 == 'e') || (param_1 = pcVar8, cVar5 == 'E')) {
    pcVar4 = pcVar8 + 1;
    if (pcVar8[1] == '+') {
      pcVar4 = pcVar8 + 2;
      bVar2 = false;
    }
    else {
      bVar2 = false;
      if (pcVar8[1] == '-') {
        pcVar4 = pcVar8 + 2;
        bVar2 = true;
      }
    }
    cVar5 = *pcVar4;
    param_1 = pcVar4;
    while (dVar9 = DOUBLE_001aa228, dVar3 = DOUBLE_001aa200, pcVar8 = param_1,
          (byte)(cVar5 - 0x30U) < 10) {
      param_1 = param_1 + 1;
      cVar5 = *param_1;
    }
    while (pcVar8 = pcVar8 + -1, pcVar4 <= pcVar8) {
      dVar9 = dVar3 * ((double)CONCAT44(0x43300000,(int)*pcVar8 - 0x30U ^ 0x80000000) -
                      DOUBLE_001aa1e0) + dVar9;
      dVar3 = dVar3 * DOUBLE_001aa238;
    }
    if (bVar2) {
      dVar9 = -dVar9;
    }
    dVar9 = (double)((double (*)())FUN_0000be70)((int)dVar9,param_2,param_3,param_4,param_5,param_6,pcVar8);
    dVar10 = dVar10 * dVar9;
  }
LAB_0000c5a8:
  if (bVar1) {
    dVar10 = -dVar10;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_1;
  }
  return dVar10;
}

/* FUN_0000c8a0 @ 0xc8a0 (136 bytes) */
int FUN_0000c8a0(param_1, param_2, param_3)
  size_t *param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  void *pvVar2;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = *param_3;
  uVar5 = 1;
  iVar1 = *param_2;
  if ((int)(*param_1 - (iVar4 - iVar1)) < 0x100) {
    sVar3 = *param_1 + 0x800;
    *param_1 = sVar3;
    pvVar2 = _realloc((void *)*param_2,sVar3);
    uVar5 = 0;
    *param_3 = (int)pvVar2;
    if (pvVar2 != (void *)0x0) {
      *param_2 = (int)pvVar2;
      uVar5 = 1;
      *param_3 = (int)pvVar2 + (iVar4 - iVar1);
    }
  }
  return uVar5;
}

/* FUN_0000c930 @ 0xc930 (284 bytes) */
int FUN_0000c930(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  if (param_2 != 0) {
    iVar3 = 0;
    if (s_C_001a4428[0] != '\0') {
      pcVar2 = "C";
      iVar3 = 0;
      cVar1 = s_C_001a4428[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(param_1 + iVar3) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    param_1 = param_1 + iVar3;
    if (0 < param_3) {
      iVar3 = 0;
      if (s_1_001a442c[0] != '\0') {
        pcVar2 = "1";
        cVar1 = s_1_001a442c[0];
        do {
          pcVar2 = pcVar2 + 1;
          *(char *)(param_1 + iVar3) = cVar1;
          iVar3 = iVar3 + 1;
          cVar1 = *pcVar2;
        } while (cVar1 != '\0');
      }
      param_1 = param_1 + iVar3;
    }
  }
  if (param_4 != 0) {
    iVar3 = 0;
    if (s__SAT_001a4430[0] != '\0') {
      pcVar2 = "_SAT";
      cVar1 = s__SAT_001a4430[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(param_1 + iVar3) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    return param_1 + iVar3;
  }
  return param_1;
}

/* FUN_0000ca50 @ 0xca50 (312 bytes) */
int FUN_0000ca50(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  if (param_2 == 2) {
    iVar3 = 0;
    if (s_H_001a443c[0] != '\0') {
      pcVar2 = "H";
      iVar3 = 0;
      cVar1 = s_H_001a443c[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(param_1 + iVar3) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
  }
  else {
    if (param_2 == 3) {
      iVar3 = 0;
      if (s_X_001a4440[0] != '\0') {
        pcVar2 = "X";
        iVar3 = 0;
        cVar1 = s_X_001a4440[0];
        do {
          pcVar2 = pcVar2 + 1;
          *(char *)(param_1 + iVar3) = cVar1;
          iVar3 = iVar3 + 1;
          cVar1 = *pcVar2;
        } while (cVar1 != '\0');
      }
      return param_1 + iVar3;
    }
    if (param_2 != 1) {
      return param_1;
    }
    iVar3 = 0;
    if (s_R_001a4438[0] != '\0') {
      pcVar2 = "R";
      iVar3 = 0;
      cVar1 = s_R_001a4438[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(param_1 + iVar3) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
  }
  return param_1 + iVar3;
}

/* FUN_0000cb90 @ 0xcb90 (572 bytes) */
int FUN_0000cb90(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  
  iVar1 = param_2 / 10;
  if (iVar1 == 0) {
    pcVar10 = (char *)*param_1;
  }
  else {
    iVar2 = iVar1 / 10;
    if (iVar2 == 0) {
      pcVar10 = (char *)*param_1;
    }
    else {
      iVar3 = iVar2 / 10;
      if (iVar3 == 0) {
        pcVar10 = (char *)*param_1;
      }
      else {
        iVar4 = iVar3 / 10;
        if (iVar4 == 0) {
          pcVar10 = (char *)*param_1;
        }
        else {
          iVar5 = iVar4 / 10;
          if (iVar5 == 0) {
            pcVar10 = (char *)*param_1;
          }
          else {
            iVar6 = iVar5 / 10;
            if (iVar6 == 0) {
              pcVar10 = (char *)*param_1;
            }
            else {
              iVar7 = iVar6 / 10;
              if (iVar7 == 0) {
                pcVar10 = (char *)*param_1;
              }
              else {
                iVar8 = iVar7 / 10;
                if (iVar8 == 0) {
                  pcVar10 = (char *)*param_1;
                }
                else {
                  iVar9 = iVar8 / 10;
                  if (iVar9 != 0) {
                    ((int (*)())FUN_0000cb90)(param_1,iVar9);
                  }
                  *(char *)*param_1 = (char)iVar8 + (char)iVar9 * -10 + '0';
                  pcVar10 = (char *)(*param_1 + 1);
                  *param_1 = (int)pcVar10;
                }
                *pcVar10 = (char)iVar7 + (char)iVar8 * -10 + '0';
                pcVar10 = (char *)(*param_1 + 1);
                *param_1 = (int)pcVar10;
              }
              *pcVar10 = (char)iVar6 + (char)iVar7 * -10 + '0';
              pcVar10 = (char *)(*param_1 + 1);
              *param_1 = (int)pcVar10;
            }
            *pcVar10 = (char)iVar5 + (char)iVar6 * -10 + '0';
            pcVar10 = (char *)(*param_1 + 1);
            *param_1 = (int)pcVar10;
          }
          *pcVar10 = (char)iVar4 + (char)iVar5 * -10 + '0';
          pcVar10 = (char *)(*param_1 + 1);
          *param_1 = (int)pcVar10;
        }
        *pcVar10 = (char)iVar3 + (char)iVar4 * -10 + '0';
        pcVar10 = (char *)(*param_1 + 1);
        *param_1 = (int)pcVar10;
      }
      *pcVar10 = (char)iVar2 + (char)iVar3 * -10 + '0';
      pcVar10 = (char *)(*param_1 + 1);
      *param_1 = (int)pcVar10;
    }
    *pcVar10 = (char)iVar1 + (char)iVar2 * -10 + '0';
    pcVar10 = (char *)(*param_1 + 1);
    *param_1 = (int)pcVar10;
  }
  *pcVar10 = (char)param_2 + (char)iVar1 * -10 + '0';
  *param_1 = *param_1 + 1;
  return;
}

/* FUN_0000cdf0 @ 0xcdf0 (156 bytes) */
int FUN_0000cdf0(param_1, param_2)
  char *param_1;
  int param_2;
{
  int iVar1;
  char *local_28 [6];
  
  local_28[0] = param_1;
  if (param_2 < 0) {
    local_28[0] = param_1 + 1;
    param_2 = -param_2;
    *param_1 = '-';
  }
  iVar1 = param_2 / 10;
  if (iVar1 != 0) {
    ((int (*)())FUN_0000cb90)(local_28,iVar1);
  }
  *local_28[0] = (char)param_2 + (char)iVar1 * -10 + '0';
  return local_28[0] + (1 - (int)param_1);
}

/* FUN_0000ce90 @ 0xce90 (924 bytes) */
int FUN_0000ce90(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  
  cVar7 = s___001a4444[0];
  bVar1 = s___001a4444[0] != '\0';
  if (bVar1) {
    pcVar3 = ":";
    iVar4 = 0;
    cVar2 = s___001a4444[0];
    do {
      pcVar3 = pcVar3 + 1;
      *(char *)(param_1 + iVar4) = cVar2;
      iVar4 = iVar4 + 1;
      cVar2 = *pcVar3;
    } while (cVar2 != '\0');
  }
  else {
    iVar4 = 0;
  }
  iVar5 = ((int (*)())FUN_0000cdf0)(param_1 + iVar4,param_2 + 1);
  iVar5 = param_1 + iVar4 + iVar5;
  if (param_3 == 1) {
    if (bVar1) {
      pcVar3 = ":";
      iVar4 = 0;
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
    else {
      iVar4 = 0;
    }
    iVar6 = ((int (*)())FUN_0000cdf0)(iVar5 + iVar4,param_2 + 1);
    iVar5 = iVar5 + iVar4 + iVar6;
  }
  if (param_4 == 2) {
    iVar4 = 0;
    if (s_X_001a4440[0] != '\0') {
      pcVar3 = "X";
      cVar7 = s_X_001a4440[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else if (param_4 < 3) {
    if (param_4 != 1) goto LAB_0000d0e4;
    iVar4 = 0;
    if (s_F_001a4448[0] != '\0') {
      pcVar3 = "F";
      cVar7 = s_F_001a4448[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else if (param_4 == 3) {
    iVar4 = 0;
    if (s_I_001a444c[0] != '\0') {
      pcVar3 = "I";
      cVar7 = s_I_001a444c[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else {
    if (param_4 != 4) goto LAB_0000d0e4;
    iVar4 = 0;
    if (s_B_001a4450[0] != '\0') {
      pcVar3 = "B";
      cVar7 = s_B_001a4450[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  iVar5 = iVar5 + iVar4;
LAB_0000d0e4:
  if (param_5 == 2) {
    iVar4 = 0;
    if (s_16_001a4458[0] != '\0') {
      pcVar3 = "16";
      cVar7 = s_16_001a4458[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else if (param_5 == 3) {
    iVar4 = 0;
    if (s_12_001a445c[0] != '\0') {
      pcVar3 = "12";
      cVar7 = s_12_001a445c[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else {
    if (param_5 != 1) {
      return iVar5;
    }
    iVar4 = 0;
    if (s_32_001a4454[0] != '\0') {
      pcVar3 = "32";
      cVar7 = s_32_001a4454[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  return iVar5 + iVar4;
}

/* FUN_0000d240 @ 0xd240 (308 bytes) */
int FUN_0000d240(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  
  cVar6 = s___001a4444[0];
  if ((param_2 != 3) || (param_3 == 1)) {
    bVar1 = s___001a4444[0] != '\0';
    if (bVar1) {
      pcVar3 = ":";
      iVar4 = 0;
      cVar2 = s___001a4444[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(param_1 + iVar4) = cVar2;
        iVar4 = iVar4 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    else {
      iVar4 = 0;
    }
    iVar5 = ((int (*)())FUN_0000cdf0)(param_1 + iVar4,param_2 + 1);
    param_1 = param_1 + iVar4 + iVar5;
    if (param_3 == 1) {
      if (bVar1) {
        pcVar3 = ":";
        iVar4 = 0;
        do {
          pcVar3 = pcVar3 + 1;
          *(char *)(param_1 + iVar4) = cVar6;
          iVar4 = iVar4 + 1;
          cVar6 = *pcVar3;
        } while (cVar6 != '\0');
      }
      else {
        iVar4 = 0;
      }
      iVar5 = ((int (*)())FUN_0000cdf0)(param_1 + iVar4,param_2 + 1);
      param_1 = param_1 + iVar4 + iVar5;
    }
  }
  return param_1;
}

/* FUN_0000d380 @ 0xd380 (2976 bytes) */
int FUN_0000d380(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined1 *param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  uint uVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined1 *puVar7;
  uint *puVar8;
  
  puVar8 = (uint *)(param_5 * 8 + param_1);
  uVar1 = *(uint *)(param_5 * 8 + param_1) >> 0x11 & 7;
  if (uVar1 == 1) {
    iVar6 = 0;
    if (s_tmp_001a4460[0] != '\0') {
      pcVar3 = "tmp";
      iVar6 = 0;
      cVar2 = s_tmp_001a4460[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    puVar7 = param_2 + iVar6;
    if ((param_6 == 0) || (param_3 == 0)) {
      iVar6 = ((int (*)())FUN_0000cdf0)(puVar7,(uint)*(ushort *)((int)puVar8 + 6));
      param_2 = puVar7 + iVar6;
      goto LAB_0000d5c0;
    }
    iVar6 = ((int (*)())FUN_0000cdf0)(puVar7,*(undefined4 *)(param_3 + (uint)*(ushort *)((int)puVar8 + 6) * 4));
    param_2 = puVar7 + iVar6;
    if (param_4 == 0) goto LAB_0000d5c4;
    uVar1 = puVar8[1];
    if (-1 < (int)uVar1) {
      uVar5 = (uint)*(ushort *)((int)puVar8 + 6);
      if (*(int *)(param_4 + uVar5 * 4) != -1) {
        iVar6 = 0;
        if (s___001a4464[0] != '\0') {
          pcVar3 = "[";
          iVar6 = 0;
          cVar2 = s___001a4464[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar5 = (uint)*(ushort *)((int)puVar8 + 6);
        }
        puVar7 = param_2 + iVar6;
        iVar6 = ((int (*)())FUN_0000cdf0)(puVar7,*(undefined4 *)(param_4 + uVar5 * 4));
        iVar4 = 0;
        if (s___001a4468[0] != '\0') {
          pcVar3 = "]";
          iVar4 = 0;
          cVar2 = s___001a4468[0];
          do {
            pcVar3 = pcVar3 + 1;
            puVar7[iVar4 + iVar6] = cVar2;
            iVar4 = iVar4 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        uVar1 = puVar8[1];
        param_2 = puVar7 + iVar4 + iVar6;
      }
      goto LAB_0000d5c8;
    }
LAB_0000d5d0:
    iVar6 = 0;
    if (s__adr_001a4470[0] != '\0') {
      pcVar3 = "[adr";
      iVar6 = 0;
      cVar2 = s__adr_001a4470[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      uVar1 = puVar8[1];
    }
    iVar4 = ((int (*)())FUN_0000cdf0)(param_2 + iVar6,uVar1 >> 0x1e & 1);
    uVar5 = puVar8[1];
    puVar7 = param_2 + iVar6 + iVar4;
    uVar1 = uVar5 >> 0x1c & 3;
    if (uVar1 == 1) {
      iVar6 = 0;
      if (s__y_001a447c[0] != '\0') {
        pcVar3 = ".y";
        cVar2 = s__y_001a447c[0];
        do {
          pcVar3 = pcVar3 + 1;
          puVar7[iVar6] = cVar2;
          iVar6 = iVar6 + 1;
          cVar2 = *pcVar3;
        } while (cVar2 != '\0');
        goto LAB_0000d794;
      }
LAB_0000d798:
      puVar7 = puVar7 + iVar6;
    }
    else {
      if (1 < uVar1) {
        if (uVar1 == 2) {
          iVar6 = 0;
          if (s__z_001a4480[0] != '\0') {
            pcVar3 = ".z";
            cVar2 = s__z_001a4480[0];
            do {
              pcVar3 = pcVar3 + 1;
              puVar7[iVar6] = cVar2;
              iVar6 = iVar6 + 1;
              cVar2 = *pcVar3;
            } while (cVar2 != '\0');
LAB_0000d794:
            uVar5 = puVar8[1];
          }
        }
        else {
          if (uVar1 != 3) goto LAB_0000d79c;
          iVar6 = 0;
          if (s__w_001a4484[0] != '\0') {
            pcVar3 = ".w";
            cVar2 = s__w_001a4484[0];
            do {
              pcVar3 = pcVar3 + 1;
              puVar7[iVar6] = cVar2;
              iVar6 = iVar6 + 1;
              cVar2 = *pcVar3;
            } while (cVar2 != '\0');
            goto LAB_0000d794;
          }
        }
        goto LAB_0000d798;
      }
      if (uVar1 == 0) {
        iVar6 = 0;
        if (s__x_001a4478[0] != '\0') {
          pcVar3 = ".x";
          cVar2 = s__x_001a4478[0];
          do {
            pcVar3 = pcVar3 + 1;
            puVar7[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          goto LAB_0000d794;
        }
        goto LAB_0000d798;
      }
    }
LAB_0000d79c:
    if ((((*puVar8 & 0xe0000) != 0x20000) || (param_4 == 0)) ||
       (iVar6 = *(int *)(param_4 + (uint)*(ushort *)((int)puVar8 + 6) * 4), iVar6 == -1)) {
      iVar6 = 0;
    }
    iVar6 = iVar6 + ((int)(uVar5 << 4 | uVar5 >> 0x1c) >> 0x18);
    if (iVar6 != 0) {
      if (0 < iVar6) {
        iVar4 = 0;
        if (s___001a4488[0] != '\0') {
          pcVar3 = "+";
          cVar2 = s___001a4488[0];
          do {
            pcVar3 = pcVar3 + 1;
            puVar7[iVar4] = cVar2;
            iVar4 = iVar4 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        puVar7 = puVar7 + iVar4;
      }
      iVar6 = ((int (*)())FUN_0000cdf0)(puVar7,iVar6);
      puVar7 = puVar7 + iVar6;
    }
    iVar6 = 0;
    if (s___001a4468[0] != '\0') {
      pcVar3 = "]";
      iVar6 = 0;
      cVar2 = s___001a4468[0];
      do {
        pcVar3 = pcVar3 + 1;
        puVar7[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    param_2 = puVar7 + iVar6;
LAB_0000d89c:
    iVar6 = 0;
    if (s___001a448c[0] != '\0') {
      pcVar3 = ".";
      iVar6 = 0;
      cVar2 = s___001a448c[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    if ((*puVar8 & 0x2000) == 0) {
      param_2[iVar6] = 0x5f;
    }
    else {
      param_2[iVar6] = (((byte)(*puVar8 >> 8) & 3) + 1 & 3) + 0x77;
    }
    pcVar3 = param_2 + iVar6 + 1;
    uVar1 = *puVar8;
    if ((uVar1 & 0xc00) != 0) {
      if ((uVar1 & 0x4000) == 0) {
        *pcVar3 = '_';
        pcVar3 = param_2 + iVar6 + 2;
        uVar1 = *puVar8;
      }
      else {
        *pcVar3 = (((byte)(uVar1 >> 6) & 3) + 1 & 3) + 0x77;
        pcVar3 = param_2 + iVar6 + 2;
        uVar1 = *puVar8;
      }
    }
    if (1 < (uVar1 >> 10 & 3)) {
      if ((uVar1 & 0x8000) == 0) {
        *pcVar3 = '_';
        pcVar3 = pcVar3 + 1;
        uVar1 = *puVar8;
      }
      else {
        *pcVar3 = (((byte)(uVar1 >> 4) & 3) + 1 & 3) + 0x77;
        pcVar3 = pcVar3 + 1;
        uVar1 = *puVar8;
      }
    }
    if (2 < (uVar1 >> 10 & 3)) {
      if ((uVar1 & 0x10000) == 0) {
        *pcVar3 = '_';
        pcVar3 = pcVar3 + 1;
        uVar1 = *puVar8;
      }
      else {
        *pcVar3 = (((byte)(uVar1 >> 2) & 3) + 1 & 3) + 0x77;
        pcVar3 = pcVar3 + 1;
        uVar1 = *puVar8;
      }
    }
    param_2 = (undefined1 *)((int (*)())FUN_0000d240)(pcVar3,uVar1 >> 10 & 3,uVar1 >> 0xc & 1);
    uVar1 = *puVar8;
  }
  else {
    if (uVar1 == 3) {
      iVar6 = 0;
      if (s_res_001a446c[0] != '\0') {
        pcVar3 = "res";
        iVar6 = 0;
        cVar2 = s_res_001a446c[0];
        do {
          pcVar3 = pcVar3 + 1;
          param_2[iVar6] = cVar2;
          iVar6 = iVar6 + 1;
          cVar2 = *pcVar3;
        } while (cVar2 != '\0');
      }
      iVar4 = ((int (*)())FUN_0000cdf0)(param_2 + iVar6,(uint)*(ushort *)((int)puVar8 + 6));
      param_2 = param_2 + iVar6 + iVar4;
    }
LAB_0000d5c0:
    if (param_6 != 0) {
LAB_0000d5c4:
      uVar1 = puVar8[1];
LAB_0000d5c8:
      if ((int)uVar1 < 0) goto LAB_0000d5d0;
      goto LAB_0000d89c;
    }
    uVar1 = *puVar8;
    if ((uVar1 & 0x1e000) != 0x1e000) {
      iVar6 = 0;
      if (s___001a448c[0] != '\0') {
        pcVar3 = ".";
        cVar2 = s___001a448c[0];
        do {
          pcVar3 = pcVar3 + 1;
          param_2[iVar6] = cVar2;
          iVar6 = iVar6 + 1;
          cVar2 = *pcVar3;
        } while (cVar2 != '\0');
        uVar1 = *puVar8;
      }
      param_2 = param_2 + iVar6;
      if ((uVar1 & 0x2000) != 0) {
        iVar6 = 0;
        if (s_x_001a4490[0] != '\0') {
          pcVar3 = "x";
          cVar2 = s_x_001a4490[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar1 = *puVar8;
        }
        param_2 = param_2 + iVar6;
      }
      if ((uVar1 & 0x4000) != 0) {
        iVar6 = 0;
        if (s_y_001a4494[0] != '\0') {
          pcVar3 = "y";
          cVar2 = s_y_001a4494[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar1 = *puVar8;
        }
        param_2 = param_2 + iVar6;
      }
      if ((uVar1 & 0x8000) != 0) {
        iVar6 = 0;
        if (s_z_001a4498[0] != '\0') {
          pcVar3 = "z";
          cVar2 = s_z_001a4498[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar1 = *puVar8;
        }
        param_2 = param_2 + iVar6;
      }
      if ((uVar1 & 0x10000) != 0) {
        iVar6 = 0;
        if (s_w_001a449c[0] != '\0') {
          pcVar3 = "w";
          cVar2 = s_w_001a449c[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar1 = *puVar8;
        }
        param_2 = param_2 + iVar6;
      }
    }
  }
  if ((uVar1 & 0x70000000) == 0) {
    return param_2;
  }
  switch(uVar1 >> 0x1c & 7) {
  case 0:
    iVar6 = 0;
    if (s__TR_001a44a0[0] != '\0') {
      pcVar3 = " (TR";
      cVar2 = s__TR_001a44a0[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
LAB_0000de9c:
      uVar1 = *puVar8;
    }
    break;
  case 1:
    iVar6 = 0;
    if (s__EQ_001a44a8[0] != '\0') {
      pcVar3 = " (EQ";
      cVar2 = s__EQ_001a44a8[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 2:
    iVar6 = 0;
    if (s__GE_001a44b0[0] != '\0') {
      pcVar3 = " (GE";
      cVar2 = s__GE_001a44b0[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 3:
    iVar6 = 0;
    if (s__GT_001a44b8[0] != '\0') {
      pcVar3 = " (GT";
      cVar2 = s__GT_001a44b8[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 4:
    iVar6 = 0;
    if (s__LE_001a44c0[0] != '\0') {
      pcVar3 = " (LE";
      cVar2 = s__LE_001a44c0[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 5:
    iVar6 = 0;
    if (s__LT_001a44c8[0] != '\0') {
      pcVar3 = " (LT";
      cVar2 = s__LT_001a44c8[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 6:
    iVar6 = 0;
    if (s__NE_001a44d0[0] != '\0') {
      pcVar3 = " (NE";
      cVar2 = s__NE_001a44d0[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 7:
    iVar6 = 0;
    if (s__FL_001a44d8[0] != '\0') {
      pcVar3 = " (FL";
      cVar2 = s__FL_001a44d8[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      goto LAB_0000de9c;
    }
    break;
  default:
    goto switchD_0000dc3c_default;
  }
  param_2 = param_2 + iVar6;
switchD_0000dc3c_default:
  if ((int)uVar1 < 0) {
    *param_2 = 0x31;
    param_2 = param_2 + 1;
  }
  *param_2 = 0x2e;
  param_2[1] = (((byte)(*puVar8 >> 0x1a) & 3) + 1 & 3) + 0x77;
  param_2[2] = (*(char *)puVar8 + 1U & 3) + 0x77;
  param_2[3] = (((byte)(*puVar8 >> 0x16) & 3) + 1 & 3) + 0x77;
  uVar1 = *puVar8;
  param_2[5] = 0x29;
  param_2[4] = (((byte)(uVar1 >> 0x14) & 3) + 1 & 3) + 0x77;
  return param_2 + 6;
}

/* FUN_0000df50 @ 0xdf50 (648 bytes) */
int FUN_0000df50(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  
  cVar7 = s___001a4444[0];
  bVar1 = s___001a4444[0] != '\0';
  if (bVar1) {
    pcVar3 = ":";
    iVar4 = 0;
    cVar2 = s___001a4444[0];
    do {
      pcVar3 = pcVar3 + 1;
      *(char *)(param_1 + iVar4) = cVar2;
      iVar4 = iVar4 + 1;
      cVar2 = *pcVar3;
    } while (cVar2 != '\0');
  }
  else {
    iVar4 = 0;
  }
  iVar5 = ((int (*)())FUN_0000cdf0)(param_1 + iVar4,param_2 + 1);
  iVar5 = param_1 + iVar4 + iVar5;
  if (param_3 != 0) {
    if (bVar1) {
      pcVar3 = ":";
      iVar4 = 0;
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
    else {
      iVar4 = 0;
    }
    iVar6 = ((int (*)())FUN_0000cdf0)(iVar5 + iVar4,param_2 + 1);
    iVar5 = iVar5 + iVar4 + iVar6;
  }
  if (param_4 == 2) {
    iVar4 = 0;
    if (s_X_001a4440[0] != '\0') {
      pcVar3 = "X";
      cVar7 = s_X_001a4440[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else if (param_4 < 3) {
    if (param_4 != 1) {
      return iVar5;
    }
    iVar4 = 0;
    if (s_F_001a4448[0] != '\0') {
      pcVar3 = "F";
      cVar7 = s_F_001a4448[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else if (param_4 == 3) {
    iVar4 = 0;
    if (s_I_001a444c[0] != '\0') {
      pcVar3 = "I";
      cVar7 = s_I_001a444c[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else {
    if (param_4 != 4) {
      return iVar5;
    }
    iVar4 = 0;
    if (s_B_001a4450[0] != '\0') {
      pcVar3 = "B";
      cVar7 = s_B_001a4450[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  return iVar5 + iVar4;
}

/* FUN_0000e1f0 @ 0xe1f0 (4068 bytes) */
int FUN_0000e1f0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  char *param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
  int param_9;
{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  
  puVar10 = (uint *)(param_7 * 8 + param_1);
  if ((*(uint *)(param_1 + param_7 * 8) & 0x8000000) != 0) {
    iVar5 = 0;
    if (s___001a44e0[0] != '\0') {
      pcVar3 = "-";
      iVar5 = 0;
      cVar2 = s___001a44e0[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar5] = cVar2;
        iVar5 = iVar5 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    param_2 = param_2 + iVar5;
  }
  uVar7 = *puVar10;
  if ((uVar7 & 0x4000000) != 0) {
    iVar5 = 0;
    if (s___001a44e4[0] != '\0') {
      pcVar3 = "|";
      cVar2 = s___001a44e4[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar5] = cVar2;
        iVar5 = iVar5 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      uVar7 = *puVar10;
    }
    param_2 = param_2 + iVar5;
  }
  switch(uVar7 >> 0x17 & 7) {
  case 0:
    iVar5 = 0;
    if (s_att_001a44e8[0] != '\0') {
      pcVar3 = "att";
      iVar5 = 0;
      cVar2 = s_att_001a44e8[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar5] = cVar2;
        iVar5 = iVar5 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    break;
  case 1:
    iVar5 = 0;
    if (s_tmp_001a4460[0] != '\0') {
      pcVar3 = "tmp";
      iVar5 = 0;
      cVar2 = s_tmp_001a4460[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar5] = cVar2;
        iVar5 = iVar5 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    pcVar3 = param_2 + iVar5;
    if (param_5 == 0) {
      iVar5 = ((int (*)())FUN_0000cdf0)(pcVar3,(uint)*(ushort *)((int)puVar10 + 6));
    }
    else {
      iVar5 = ((int (*)())FUN_0000cdf0)(pcVar3,*(undefined4 *)(param_5 + (uint)*(ushort *)((int)puVar10 + 6) * 4)
                          );
    }
    param_2 = pcVar3 + iVar5;
    if (param_6 == 0) {
      uVar7 = *puVar10;
    }
    else {
      uVar7 = *puVar10;
      if ((int)uVar7 < 0) goto LAB_0000e6e8;
      uVar8 = (uint)*(ushort *)((int)puVar10 + 6);
      if (*(int *)(param_6 + uVar8 * 4) != -1) {
        iVar5 = 0;
        if (s___001a4464[0] != '\0') {
          pcVar3 = "[";
          iVar5 = 0;
          cVar2 = s___001a4464[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar8 = (uint)*(ushort *)((int)puVar10 + 6);
        }
        iVar6 = ((int (*)())FUN_0000cdf0)(param_2 + iVar5,*(undefined4 *)(param_6 + uVar8 * 4));
        pcVar3 = param_2 + iVar5 + iVar6;
        iVar5 = 0;
        if (s___001a4468[0] != '\0') {
          pcVar4 = "]";
          iVar5 = 0;
          cVar2 = s___001a4468[0];
          do {
            pcVar4 = pcVar4 + 1;
            pcVar3[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar4;
          } while (cVar2 != '\0');
        }
        goto LAB_0000e610;
      }
    }
    goto switchD_0000e310_default;
  case 2:
    iVar5 = 0;
    if (s_prm_001a44ec[0] != '\0') {
      pcVar3 = "prm";
      iVar5 = 0;
      cVar2 = s_prm_001a44ec[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar5] = cVar2;
        iVar5 = iVar5 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    iVar6 = ((int (*)())FUN_0000cdf0)(param_2 + iVar5,
                         *(undefined4 *)(param_3 + (uint)*(ushort *)((int)puVar10 + 6) * 4));
    uVar7 = *puVar10;
    param_2 = param_2 + iVar5 + iVar6;
    if (-1 < (int)uVar7) {
      uVar8 = (uint)*(ushort *)((int)puVar10 + 6);
      if (*(int *)(param_4 + uVar8 * 4) != -1) {
        iVar5 = 0;
        if (s___001a4464[0] != '\0') {
          pcVar3 = "[";
          iVar5 = 0;
          cVar2 = s___001a4464[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar8 = (uint)*(ushort *)((int)puVar10 + 6);
        }
        iVar6 = ((int (*)())FUN_0000cdf0)(param_2 + iVar5,*(undefined4 *)(param_4 + uVar8 * 4));
        pcVar3 = param_2 + iVar5 + iVar6;
        iVar5 = 0;
        if (s___001a4468[0] != '\0') {
          pcVar4 = "]";
          iVar5 = 0;
          cVar2 = s___001a4468[0];
          do {
            pcVar4 = pcVar4 + 1;
            pcVar3[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar4;
          } while (cVar2 != '\0');
        }
LAB_0000e610:
        uVar7 = *puVar10;
        param_2 = pcVar3 + iVar5;
      }
      goto switchD_0000e310_default;
    }
    goto LAB_0000e6e8;
  case 3:
    iVar5 = 0;
    if (s_res_001a446c[0] != '\0') {
      pcVar3 = "res";
      iVar5 = 0;
      cVar2 = s_res_001a446c[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar5] = cVar2;
        iVar5 = iVar5 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    break;
  case 4:
    iVar5 = 0;
    if (s_adr_001a44f0[0] != '\0') {
      pcVar3 = "adr";
      iVar5 = 0;
      cVar2 = s_adr_001a44f0[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar5] = cVar2;
        iVar5 = iVar5 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    break;
  default:
    goto switchD_0000e310_default;
  }
  iVar6 = ((int (*)())FUN_0000cdf0)(param_2 + iVar5,(uint)*(ushort *)((int)puVar10 + 6));
  uVar7 = *puVar10;
  param_2 = param_2 + iVar5 + iVar6;
switchD_0000e310_default:
  if ((int)uVar7 < 0) {
LAB_0000e6e8:
    iVar5 = 0;
    if (s__adr_001a4470[0] != '\0') {
      pcVar3 = "[adr";
      cVar2 = s__adr_001a4470[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar5] = cVar2;
        iVar5 = iVar5 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      uVar7 = *puVar10;
    }
    iVar6 = ((int (*)())FUN_0000cdf0)(param_2 + iVar5,uVar7 >> 0x1e & 1);
    uVar8 = *puVar10;
    pcVar3 = param_2 + iVar5 + iVar6;
    uVar7 = uVar8 >> 0x1c & 3;
    if (uVar7 == 1) {
      iVar5 = 0;
      if (s__y_001a447c[0] != '\0') {
        pcVar4 = ".y";
        cVar2 = s__y_001a447c[0];
        do {
          pcVar4 = pcVar4 + 1;
          pcVar3[iVar5] = cVar2;
          iVar5 = iVar5 + 1;
          cVar2 = *pcVar4;
        } while (cVar2 != '\0');
        goto LAB_0000e89c;
      }
LAB_0000e8a0:
      pcVar3 = pcVar3 + iVar5;
    }
    else {
      if (1 < uVar7) {
        if (uVar7 == 2) {
          iVar5 = 0;
          if (s__z_001a4480[0] != '\0') {
            pcVar4 = ".z";
            cVar2 = s__z_001a4480[0];
            do {
              pcVar4 = pcVar4 + 1;
              pcVar3[iVar5] = cVar2;
              iVar5 = iVar5 + 1;
              cVar2 = *pcVar4;
            } while (cVar2 != '\0');
LAB_0000e89c:
            uVar8 = *puVar10;
          }
        }
        else {
          if (uVar7 != 3) goto LAB_0000e8a4;
          iVar5 = 0;
          if (s__w_001a4484[0] != '\0') {
            pcVar4 = ".w";
            cVar2 = s__w_001a4484[0];
            do {
              pcVar4 = pcVar4 + 1;
              pcVar3[iVar5] = cVar2;
              iVar5 = iVar5 + 1;
              cVar2 = *pcVar4;
            } while (cVar2 != '\0');
            goto LAB_0000e89c;
          }
        }
        goto LAB_0000e8a0;
      }
      if (uVar7 == 0) {
        iVar5 = 0;
        if (s__x_001a4478[0] != '\0') {
          pcVar4 = ".x";
          cVar2 = s__x_001a4478[0];
          do {
            pcVar4 = pcVar4 + 1;
            pcVar3[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar4;
          } while (cVar2 != '\0');
          goto LAB_0000e89c;
        }
        goto LAB_0000e8a0;
      }
    }
LAB_0000e8a4:
    if ((uVar8 & 0x3800000) == 0x800000) {
      if (param_6 == 0) goto LAB_0000e908;
      iVar5 = *(int *)(param_6 + (uint)*(ushort *)((int)puVar10 + 6) * 4);
joined_r0x0000e904:
      if (iVar5 == -1) goto LAB_0000e908;
    }
    else {
      if (((uVar8 & 0x3800000) == 0x1000000) && (param_4 != 0)) {
        iVar5 = *(int *)(param_4 + (uint)*(ushort *)((int)puVar10 + 6) * 4);
        goto joined_r0x0000e904;
      }
LAB_0000e908:
      iVar5 = 0;
    }
    iVar5 = iVar5 + (char)*puVar10;
    if (iVar5 != 0) {
      if (0 < iVar5) {
        iVar6 = 0;
        if (s___001a4488[0] != '\0') {
          pcVar4 = "+";
          cVar2 = s___001a4488[0];
          do {
            pcVar4 = pcVar4 + 1;
            pcVar3[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar4;
          } while (cVar2 != '\0');
        }
        pcVar3 = pcVar3 + iVar6;
      }
      iVar5 = ((int (*)())FUN_0000cdf0)(pcVar3,iVar5);
      pcVar3 = pcVar3 + iVar5;
    }
    iVar5 = 0;
    if (s___001a4468[0] != '\0') {
      pcVar4 = "]";
      iVar5 = 0;
      cVar2 = s___001a4468[0];
      do {
        pcVar4 = pcVar4 + 1;
        pcVar3[iVar5] = cVar2;
        iVar5 = iVar5 + 1;
        cVar2 = *pcVar4;
      } while (cVar2 != '\0');
    }
    uVar7 = *puVar10;
    param_2 = pcVar3 + iVar5;
  }
  if ((uVar7 & 0x3800000) == 0x2000000) {
LAB_0000efb4:
    if (param_8 == 0) goto LAB_0000f0bc;
  }
  else {
    if (param_9 != 0) {
      puVar9 = (uint *)(param_1 + (param_7 + 1) * 8);
LAB_0000e9fc:
      uVar7 = *puVar9 >> 0xc & 0xf;
      if (s___001a44f4[0] == '\0') {
        iVar5 = 0;
      }
      else {
        pcVar3 = ", ";
        iVar5 = 0;
        cVar2 = s___001a44f4[0];
        do {
          pcVar3 = pcVar3 + 1;
          param_2[iVar5] = cVar2;
          iVar5 = iVar5 + 1;
          cVar2 = *pcVar3;
        } while (cVar2 != '\0');
      }
      param_2 = param_2 + iVar5;
      iVar5 = 0;
LAB_0000ebd8:
      switch(uVar7) {
      case 0:
        iVar6 = 0;
        if (s_x_001a4490[0] != '\0') {
          pcVar3 = "x";
          cVar2 = s_x_001a4490[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 1:
        iVar6 = 0;
        if (s_y_001a4494[0] != '\0') {
          pcVar3 = "y";
          cVar2 = s_y_001a4494[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 2:
        iVar6 = 0;
        if (s_z_001a4498[0] != '\0') {
          pcVar3 = "z";
          cVar2 = s_z_001a4498[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 3:
        iVar6 = 0;
        if (s_w_001a449c[0] != '\0') {
          pcVar3 = "w";
          cVar2 = s_w_001a449c[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 4:
        iVar6 = 0;
        if (s__x_001a44fc[0] != '\0') {
          pcVar3 = "-x";
          cVar2 = s__x_001a44fc[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 5:
        iVar6 = 0;
        if (s__y_001a4500[0] != '\0') {
          pcVar3 = "-y";
          cVar2 = s__y_001a4500[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 6:
        iVar6 = 0;
        if (s__z_001a4504[0] != '\0') {
          pcVar3 = "-z";
          cVar2 = s__z_001a4504[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 7:
        iVar6 = 0;
        if (s__w_001a4508[0] != '\0') {
          pcVar3 = "-w";
          cVar2 = s__w_001a4508[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 8:
        iVar6 = 0;
        if (s_1_001a442c[0] != '\0') {
          pcVar3 = "1";
          cVar2 = s_1_001a442c[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 9:
        iVar6 = 0;
        if (s_0_001a450c[0] != '\0') {
          pcVar3 = "0";
          cVar2 = s_0_001a450c[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 10:
        iVar6 = 0;
        if (s__1_001a4510[0] != '\0') {
          pcVar3 = "-1";
          cVar2 = s__1_001a4510[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      default:
        goto switchD_0000ebf8_default;
      }
      param_2 = param_2 + iVar6;
switchD_0000ebf8_default:
      bVar1 = iVar5 == 3;
      iVar5 = iVar5 + 1;
      if (bVar1) {
        uVar7 = *puVar10;
        goto LAB_0000efb4;
      }
      if (iVar5 == 1) {
        iVar6 = 0;
        uVar7 = *puVar9 >> 8 & 0xf;
        if (s___001a44f8[0] != '\0') {
          pcVar3 = ",";
          iVar6 = 0;
          cVar2 = s___001a44f8[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
      }
      else {
        if (iVar5 < 2) {
          if (iVar5 == 0) goto LAB_0000e9fc;
          goto LAB_0000ebd8;
        }
        if (iVar5 == 2) {
          iVar6 = 0;
          uVar7 = *puVar9 >> 4 & 0xf;
          if (s___001a44f8[0] != '\0') {
            pcVar3 = ",";
            iVar6 = 0;
            cVar2 = s___001a44f8[0];
            do {
              pcVar3 = pcVar3 + 1;
              param_2[iVar6] = cVar2;
              iVar6 = iVar6 + 1;
              cVar2 = *pcVar3;
            } while (cVar2 != '\0');
          }
          goto LAB_0000ebd4;
        }
        if (iVar5 != 3) goto LAB_0000ebd8;
        iVar6 = 0;
        uVar7 = *puVar9 & 0xf;
        if (s___001a44f8[0] != '\0') {
          pcVar3 = ",";
          iVar6 = 0;
          cVar2 = s___001a44f8[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
      }
LAB_0000ebd4:
      param_2 = param_2 + iVar6;
      goto LAB_0000ebd8;
    }
    if (param_8 == 0) {
      if ((uVar7 & 0x7f8000) != 0xd8000) {
        iVar5 = 0;
        if (s___001a448c[0] != '\0') {
          pcVar3 = ".";
          iVar5 = 0;
          cVar2 = s___001a448c[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar7 = *puVar10;
        }
        uVar8 = uVar7 >> 0x15 & 3;
        pcVar3 = param_2 + iVar5;
        if (((uVar8 == (uVar7 >> 0x13 & 3)) && (uVar8 == (uVar7 >> 0x11 & 3))) &&
           (uVar8 == (uVar7 >> 0xf & 3))) {
          param_2[iVar5] = ((char)uVar8 + 1U & 3) + 0x77;
          param_2 = pcVar3 + 1;
          uVar7 = *puVar10;
        }
        else {
          param_2 = pcVar3 + 4;
          *pcVar3 = ((char)uVar8 + 1U & 3) + 0x77;
          pcVar3[1] = (((byte)(*puVar10 >> 0x13) & 3) + 1 & 3) + 0x77;
          pcVar3[2] = (((byte)(*puVar10 >> 0x11) & 3) + 1 & 3) + 0x77;
          pcVar3[3] = (((byte)(*puVar10 >> 0xf) & 3) + 1 & 3) + 0x77;
          uVar7 = *puVar10;
        }
      }
      goto LAB_0000f0bc;
    }
    iVar5 = 0;
    if (s___001a448c[0] != '\0') {
      pcVar3 = ".";
      iVar5 = 0;
      cVar2 = s___001a448c[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar5] = cVar2;
        iVar5 = iVar5 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      uVar7 = *puVar10;
    }
    param_2[iVar5] = (((byte)(uVar7 >> 0x15) & 3) + 1 & 3) + 0x77;
    iVar6 = iVar5 + 1;
    uVar7 = *puVar10;
    if ((uVar7 & 0x3000) != 0) {
      iVar6 = iVar5 + 2;
      param_2[iVar5 + 1] = (((byte)(uVar7 >> 0x13) & 3) + 1 & 3) + 0x77;
      uVar7 = *puVar10;
    }
    param_2 = param_2 + iVar6;
    if (1 < (uVar7 >> 0xc & 3)) {
      *param_2 = (((byte)(uVar7 >> 0x11) & 3) + 1 & 3) + 0x77;
      param_2 = param_2 + 1;
      uVar7 = *puVar10;
    }
    if (2 < (uVar7 >> 0xc & 3)) {
      *param_2 = (((byte)(uVar7 >> 0xf) & 3) + 1 & 3) + 0x77;
      param_2 = param_2 + 1;
      uVar7 = *puVar10;
    }
  }
  param_2 = (char *)((int (*)())FUN_0000d240)(param_2,uVar7 >> 0xc & 3,uVar7 >> 0xe & 1);
  uVar7 = *puVar10;
LAB_0000f0bc:
  if ((uVar7 & 0x4000000) != 0) {
    iVar5 = 0;
    if (s___001a44e4[0] != '\0') {
      pcVar3 = "|";
      cVar2 = s___001a44e4[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar5] = cVar2;
        iVar5 = iVar5 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    param_2 = param_2 + iVar5;
  }
  return param_2;
}

/* FUN_0000f250 @ 0xf250 (932 bytes) */
int FUN_0000f250(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
  int param_8;
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  if (s_texture__001a4514[0] != '\0') {
    pcVar2 = "texture[";
    iVar3 = 0;
    cVar1 = s_texture__001a4514[0];
    do {
      pcVar2 = pcVar2 + 1;
      *(char *)(param_2 + iVar3) = cVar1;
      iVar3 = iVar3 + 1;
      cVar1 = *pcVar2;
    } while (cVar1 != '\0');
  }
  iVar3 = param_2 + iVar3;
  if (param_8 == 0) {
    iVar5 = param_7 * 8;
    iVar4 = ((int (*)())FUN_0000cdf0)(iVar3,*(uint *)(iVar5 + param_1) & 0x1f);
    iVar3 = iVar3 + iVar4;
  }
  else {
    iVar5 = (param_7 + 1) * 8;
    iVar3 = ((int (*)())FUN_0000e1f0)(param_1,iVar3,param_3,param_4,param_5,param_6,param_7,1,0);
  }
  iVar4 = 0;
  if (s____001a4520[0] != '\0') {
    pcVar2 = "], ";
    iVar4 = 0;
    cVar1 = s____001a4520[0];
    do {
      pcVar2 = pcVar2 + 1;
      *(char *)(iVar3 + iVar4) = cVar1;
      iVar4 = iVar4 + 1;
      cVar1 = *pcVar2;
    } while (cVar1 != '\0');
  }
  iVar3 = iVar3 + iVar4;
  switch(*(uint *)(iVar5 + param_1) >> 5 & 7) {
  case 0:
    iVar5 = 0;
    if (s_CUBE_001a4530[0] != '\0') {
      pcVar2 = "CUBE";
      cVar1 = s_CUBE_001a4530[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(iVar3 + iVar5) = cVar1;
        iVar5 = iVar5 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  case 1:
    iVar5 = 0;
    if (s_3D_001a452c[0] != '\0') {
      pcVar2 = "3D";
      cVar1 = s_3D_001a452c[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(iVar3 + iVar5) = cVar1;
        iVar5 = iVar5 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  case 2:
    iVar5 = 0;
    if (s_RECT_001a4538[0] != '\0') {
      pcVar2 = "RECT";
      cVar1 = s_RECT_001a4538[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(iVar5 + iVar3) = cVar1;
        iVar5 = iVar5 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  case 3:
    iVar5 = 0;
    if (s_2D_001a4528[0] != '\0') {
      pcVar2 = "2D";
      cVar1 = s_2D_001a4528[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(iVar5 + iVar3) = cVar1;
        iVar5 = iVar5 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  case 4:
    iVar5 = 0;
    if (s_1D_001a4524[0] != '\0') {
      pcVar2 = "1D";
      cVar1 = s_1D_001a4524[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(iVar3 + iVar5) = cVar1;
        iVar5 = iVar5 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  case 5:
    iVar5 = 0;
    if (s_SHADOWRECT_001a4540[0] != '\0') {
      pcVar2 = "SHADOWRECT";
      cVar1 = s_SHADOWRECT_001a4540[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(iVar3 + iVar5) = cVar1;
        iVar5 = iVar5 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  case 6:
    iVar5 = 0;
    if (s_SHADOW2D_001a454c[0] != '\0') {
      pcVar2 = "SHADOW2D";
      cVar1 = s_SHADOW2D_001a454c[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(iVar3 + iVar5) = cVar1;
        iVar5 = iVar5 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  case 7:
    iVar5 = 0;
    if (s_SHADOW1D_001a4558[0] != '\0') {
      pcVar2 = "SHADOW1D";
      cVar1 = s_SHADOW1D_001a4558[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(iVar3 + iVar5) = cVar1;
        iVar5 = iVar5 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  default:
    goto switchD_0000f394_default;
  }
  iVar3 = iVar3 + iVar5;
switchD_0000f394_default:
  return iVar3;
}

/* FUN_0000f620 @ 0xf620 (27520 bytes) */
int FUN_0000f620(param_1)
  uint *param_1;
{
  uint *puVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  ushort uVar5;
  undefined1 *puVar6;
  int iVar7;
  char acVar8;
  char cVar9;
  char *pcVar10;
  int iVar11;
  char *pcVar12;
  undefined1 *puVar13;
  char *pcVar14;
  undefined4 uVar15;
  uint uVar16;
  uint *in_r6;
  uint uVar17;
  void *in_r7;
  uint *in_r8;
  uint *puVar18;
  char cVar22;
  int iVar19;
  int *piVar20;
  uint *puVar21;
  char *in_r10;
  undefined1 *puVar23;
  void *pvVar24;
  uint *puVar25;
  int iVar26;
  size_t sVar27;
  uint *puVar28;
  uint uVar29;
  uint uVar30;
  void *pvVar31;
  uint *puVar32;
  uint *puVar33;
  uint uVar34;
  float *pfVar35;
  uint uVar36;
  dword *pdVar37;
  uint uVar38;
  ushort uVar39;
  uint *puVar40;
  ulonglong uVar41;
  undefined8 uVar42;
  void *local_88;
  undefined1 *local_84;
  int local_80 [2];
  uint *local_78;
  int *local_74;
  uint *local_70;
  void *local_6c;
  int local_68;
  char *local_64;
  int local_60;
  undefined1 **local_5c;
  int *local_58;
  int local_54;
  
  local_80[0] = 0x800;
  local_88 = _malloc(0x800);
  if (local_88 == (void *)0x0) {
    return (void *)0x0;
  }
  uVar30 = *param_1;
  puVar1 = (uint *)(uint)(uVar30 - 0x8b30 < 2);
  if (uVar30 == 0x8804) {
    iVar7 = 0;
    if (s___ARBfp1_0_001a4584[0] != '\0') {
      pcVar10 = "!!ARBfp1.0\n";
      cVar22 = s___ARBfp1_0_001a4584[0];
      do {
        pcVar10 = pcVar10 + 1;
        cVar9 = *pcVar10;
        *(char *)((int)local_88 + iVar7) = cVar22;
        iVar7 = iVar7 + 1;
        cVar22 = cVar9;
      } while (cVar9 != '\0');
    }
  }
  else if (uVar30 < 0x8805) {
    if (uVar30 == 0x8620) {
      iVar7 = 0;
      if (s___ARBvp1_0_001a4564[0] != '\0') {
        pcVar10 = "!!ARBvp1.0\n";
        cVar22 = s___ARBvp1_0_001a4564[0];
        do {
          pcVar10 = pcVar10 + 1;
          cVar9 = *pcVar10;
          *(char *)((int)local_88 + iVar7) = cVar22;
          iVar7 = iVar7 + 1;
          cVar22 = cVar9;
        } while (cVar9 != '\0');
      }
    }
    else {
LAB_0000f6a4:
      if (s_Unkown_Target__error__001a45a8[0] == '\0') {
        iVar7 = 0;
      }
      else {
        pcVar10 = "Unkown Target (error)\n";
        iVar7 = 0;
        cVar22 = s_Unkown_Target__error__001a45a8[0];
        do {
          pcVar10 = pcVar10 + 1;
          cVar9 = *pcVar10;
          *(char *)((int)local_88 + iVar7) = cVar22;
          iVar7 = iVar7 + 1;
          cVar22 = cVar9;
        } while (cVar9 != '\0');
      }
    }
  }
  else if (uVar30 == 0x8b30) {
    iVar7 = 0;
    if (s___ARBfragmentshader_001a4590[0] != '\0') {
      pcVar10 = "!!ARBfragmentshader\n";
      cVar22 = s___ARBfragmentshader_001a4590[0];
      do {
        pcVar10 = pcVar10 + 1;
        cVar9 = *pcVar10;
        *(char *)((int)local_88 + iVar7) = cVar22;
        iVar7 = iVar7 + 1;
        cVar22 = cVar9;
      } while (cVar9 != '\0');
    }
  }
  else {
    if (uVar30 != 0x8b31) goto LAB_0000f6a4;
    iVar7 = 0;
    if (s___ARBvertexshader_001a4570[0] != '\0') {
      pcVar10 = "!!ARBvertexshader\n";
      cVar22 = s___ARBvertexshader_001a4570[0];
      do {
        pcVar10 = pcVar10 + 1;
        cVar9 = *pcVar10;
        *(char *)((int)local_88 + iVar7) = cVar22;
        iVar7 = iVar7 + 1;
        cVar22 = cVar9;
      } while (cVar9 != '\0');
    }
  }
  local_84 = (undefined1 *)(iVar7 + (int)local_88);
  bVar3 = puVar1 == (uint *)0x0;
  if (!bVar3) {
    local_54 = 0x19f634;
    iVar7 = 0;
    if (s__001a45c0[0] != '\0') {
      pcVar10 = "\n";
      iVar7 = 0;
      cVar22 = s__001a45c0[0];
      do {
        pcVar10 = pcVar10 + 1;
        local_84[iVar7] = cVar22;
        iVar7 = iVar7 + 1;
        cVar22 = *pcVar10;
      } while (cVar22 != '\0');
    }
    local_84 = local_84 + iVar7;
  }
  uVar34 = param_1[0x12];
  puVar32 = param_1 + param_1[0x13] * 2;
  if (0 < (int)uVar34) {
    local_5c = &local_84;
    local_58 = local_80;
    uVar36 = 0;
    do {
      iVar7 = 0;
      if (s_OPTION_001a45c4[0] != '\0') {
        pcVar10 = "OPTION ";
        iVar7 = 0;
        cVar22 = s_OPTION_001a45c4[0];
        do {
          pcVar10 = pcVar10 + 1;
          local_84[iVar7] = cVar22;
          iVar7 = iVar7 + 1;
          cVar22 = *pcVar10;
        } while (cVar22 != '\0');
      }
      local_84 = local_84 + iVar7;
      switch((char)*puVar32) {
      case '\0':
        iVar7 = 0;
        if (s_ARB_position_invariant_001a45cc[0] != '\0') {
          pcVar10 = "ARB_position_invariant";
          cVar22 = s_ARB_position_invariant_001a45cc[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case '\x01':
        iVar7 = 0;
        if (s_ARB_fog_exp_001a45e4[0] != '\0') {
          pcVar10 = "ARB_fog_exp";
          cVar22 = s_ARB_fog_exp_001a45e4[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case '\x02':
        iVar7 = 0;
        if (s_ARB_fog_exp2_001a45f0[0] != '\0') {
          pcVar10 = "ARB_fog_exp2";
          cVar22 = s_ARB_fog_exp2_001a45f0[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case '\x03':
        iVar7 = 0;
        if (s_ARB_fog_linear_001a4600[0] != '\0') {
          pcVar10 = "ARB_fog_linear";
          cVar22 = s_ARB_fog_linear_001a4600[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case '\x04':
        iVar7 = 0;
        if (s_ARB_precision_hint_fastest_001a4610[0] != '\0') {
          pcVar10 = "ARB_precision_hint_fastest";
          cVar22 = s_ARB_precision_hint_fastest_001a4610[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case '\x05':
        iVar7 = 0;
        if (s_ARB_precision_hint_nicest_001a462c[0] != '\0') {
          pcVar10 = "ARB_precision_hint_nicest";
          cVar22 = s_ARB_precision_hint_nicest_001a462c[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case '\x06':
        iVar7 = 0;
        if (s_APPLE_no_runtime_compile_001a4648[0] != '\0') {
          pcVar10 = "APPLE_no_runtime_compile";
          cVar22 = s_APPLE_no_runtime_compile_001a4648[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case '\a':
        iVar7 = 0;
        if (s_APPLE_no_altivec_001a4664[0] != '\0') {
          pcVar10 = "APPLE_no_altivec";
          cVar22 = s_APPLE_no_altivec_001a4664[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case '\b':
        iVar7 = 0;
        if (s_NV_fragment_program_001a4678[0] != '\0') {
          pcVar10 = "NV_fragment_program";
          cVar22 = s_NV_fragment_program_001a4678[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case '\t':
        iVar7 = 0;
        if (s_NV_fragment_program2_001a468c[0] != '\0') {
          pcVar10 = "NV_fragment_program2";
          cVar22 = s_NV_fragment_program2_001a468c[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case '\n':
        iVar7 = 0;
        if (s_NV_vertex_program2_001a46c0[0] != '\0') {
          pcVar10 = "NV_vertex_program2";
          cVar22 = s_NV_vertex_program2_001a46c0[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case '\v':
        iVar7 = 0;
        if (s_NV_vertex_program3_001a46d4[0] != '\0') {
          pcVar10 = "NV_vertex_program3";
          cVar22 = s_NV_vertex_program3_001a46d4[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case '\f':
        iVar7 = 0;
        if (s_ARB_draw_buffers_001a46e8[0] != '\0') {
          pcVar10 = "ARB_draw_buffers";
          cVar22 = s_ARB_draw_buffers_001a46e8[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case '\r':
        iVar7 = 0;
        if (s_ARB_fragment_program_shadow_001a46a4[0] != '\0') {
          pcVar10 = "ARB_fragment_program_shadow";
          cVar22 = s_ARB_fragment_program_shadow_001a46a4[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      default:
        goto switchD_0000f958_default;
      }
      local_84 = local_84 + iVar7;
switchD_0000f958_default:
      iVar7 = 0;
      if (s___001a46fc[0] != '\0') {
        pcVar10 = ";\n";
        iVar7 = 0;
        cVar22 = s___001a46fc[0];
        do {
          pcVar10 = pcVar10 + 1;
          local_84[iVar7] = cVar22;
          iVar7 = iVar7 + 1;
          cVar22 = *pcVar10;
        } while (cVar22 != '\0');
      }
      local_84 = local_84 + iVar7;
      iVar7 = ((int (*)())FUN_0000c8a0)(local_58,&local_88,local_5c);
      if (iVar7 == 0) goto LAB_00016630;
      uVar36 = uVar36 + 1;
      puVar32 = puVar32 + 2;
    } while (uVar34 != uVar36);
  }
  if ((uVar34 != 0) && (!bVar3)) {
    iVar7 = 0;
    if (s__001a45c0[0] != '\0') {
      pcVar10 = "\n";
      iVar7 = 0;
      cVar22 = s__001a45c0[0];
      do {
        pcVar10 = pcVar10 + 1;
        local_84[iVar7] = cVar22;
        iVar7 = iVar7 + 1;
        cVar22 = *pcVar10;
      } while (cVar22 != '\0');
    }
    local_84 = local_84 + iVar7;
  }
  uVar34 = param_1[6];
  if (uVar34 != 0) {
    iVar7 = 0;
    if (s_ADDRESS_adr0_001a4700[0] != '\0') {
      pcVar10 = "ADDRESS adr0";
      cVar22 = s_ADDRESS_adr0_001a4700[0];
      do {
        pcVar10 = pcVar10 + 1;
        local_84[iVar7] = cVar22;
        iVar7 = iVar7 + 1;
        cVar22 = *pcVar10;
      } while (cVar22 != '\0');
    }
    local_84 = local_84 + iVar7;
    if (1 < (int)uVar34) {
      uVar36 = 1;
      do {
        iVar7 = 0;
        if (s___adr_001a4710[0] != '\0') {
          pcVar10 = ", adr";
          iVar7 = 0;
          cVar22 = s___adr_001a4710[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar7;
        uVar38 = uVar36 + 1;
        iVar7 = ((int (*)())FUN_0000cdf0)(local_84,uVar36);
        local_84 = local_84 + iVar7;
        uVar36 = uVar38;
      } while (uVar34 != uVar38);
    }
    iVar7 = 0;
    if (s___001a46fc[0] != '\0') {
      pcVar10 = ";\n";
      cVar22 = s___001a46fc[0];
      do {
        pcVar10 = pcVar10 + 1;
        local_84[iVar7] = cVar22;
        iVar7 = iVar7 + 1;
        cVar22 = *pcVar10;
      } while (cVar22 != '\0');
    }
    local_84 = local_84 + iVar7;
    iVar7 = ((int (*)())FUN_0000c8a0)(local_80,&local_88,&local_84);
    if (iVar7 == 0) goto LAB_00016630;
    if (!bVar3) {
      iVar7 = 0;
      if (s__001a45c0[0] != '\0') {
        pcVar10 = "\n";
        iVar7 = 0;
        cVar22 = s__001a45c0[0];
        do {
          pcVar10 = pcVar10 + 1;
          local_84[iVar7] = cVar22;
          iVar7 = iVar7 + 1;
          cVar22 = *pcVar10;
        } while (cVar22 != '\0');
      }
      local_84 = local_84 + iVar7;
    }
  }
  uVar34 = param_1[4];
  puVar32 = param_1 + param_1[5] * 2;
  if (bVar3) {
    if (0 < (int)uVar34) {
      pvVar24 = (void *)0x0;
      puVar25 = (uint *)0x0;
      pvVar31 = (void *)0x0;
LAB_0001025c:
      local_58 = local_80;
      local_5c = &local_84;
      iVar26 = 0;
      uVar36 = 0;
      iVar7 = -1;
      do {
        in_r6 = puVar32 + uVar36 * 2;
        uVar38 = puVar32[uVar36 * 2] >> 0x1d;
        if (uVar38 == 1) {
          iVar19 = 0;
          if (s_LONG_TEMP_001a4720[0] != '\0') {
            pcVar10 = "LONG TEMP ";
            cVar22 = s_LONG_TEMP_001a4720[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
LAB_00010394:
          local_84 = local_84 + iVar19;
        }
        else {
          if (uVar38 == 2) {
            iVar19 = 0;
            if (s_SHORT_TEMP_001a472c[0] != '\0') {
              pcVar10 = "SHORT TEMP ";
              cVar22 = s_SHORT_TEMP_001a472c[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar19] = cVar22;
                iVar19 = iVar19 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
            goto LAB_00010394;
          }
          if (uVar38 == 0) {
            iVar19 = 0;
            if (s_TEMP_001a4718[0] != '\0') {
              pcVar10 = "TEMP ";
              cVar22 = s_TEMP_001a4718[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar19] = cVar22;
                iVar19 = iVar19 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
            goto LAB_00010394;
          }
        }
        uVar38 = *in_r6;
        puVar28 = in_r6;
        do {
          if (bVar3) {
            iVar19 = 0;
            if (s_tmp_001a4460[0] != '\0') {
              pcVar10 = "tmp";
              cVar22 = s_tmp_001a4460[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar19] = cVar22;
                iVar19 = iVar19 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
            local_84 = local_84 + iVar19;
            iVar19 = ((int (*)())FUN_0000cdf0)(local_84,(uint)*(ushort *)((int)puVar28 + 6));
            local_84 = local_84 + iVar19;
          }
          else if (puVar25[*(ushort *)((int)puVar28 + 6)] == 0xffffffff) {
            iVar19 = 0;
            if (s_tmp_001a4460[0] != '\0') {
              pcVar10 = "tmp";
              cVar22 = s_tmp_001a4460[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar19] = cVar22;
                iVar19 = iVar19 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
            local_84 = local_84 + iVar19;
            iVar19 = ((int (*)())FUN_0000cdf0)(local_84,*(undefined4 *)
                                            ((int)pvVar24 + (uint)*(ushort *)((int)puVar28 + 6) * 4)
                                 );
            local_84 = local_84 + iVar19;
            uVar17 = *puVar28;
            in_r7 = (void *)(uVar17 >> 0x1d);
            in_r6 = (uint *)(uVar17 >> 0x1a & 7);
            local_84 = (undefined1 *)((int (*)())FUN_0000ce90)(local_84,uVar17 >> 0x18 & 3,0,in_r6,in_r7);
          }
          else {
            if (puVar25[*(ushort *)((int)puVar28 + 6)] == 0) {
              iVar7 = 0;
              if (s_tmp_001a4460[0] != '\0') {
                pcVar10 = "tmp";
                cVar22 = s_tmp_001a4460[0];
                do {
                  pcVar10 = pcVar10 + 1;
                  local_84[iVar7] = cVar22;
                  iVar7 = iVar7 + 1;
                  cVar22 = *pcVar10;
                } while (cVar22 != '\0');
              }
              local_84 = local_84 + iVar7;
              iVar7 = ((int (*)())FUN_0000cdf0)(local_84,*(undefined4 *)
                                             ((int)pvVar24 + (uint)*(ushort *)((int)puVar28 + 6) * 4
                                             ));
              iVar19 = 0;
              if (s___001a4464[0] != '\0') {
                pcVar10 = "[";
                cVar22 = s___001a4464[0];
                do {
                  pcVar10 = pcVar10 + 1;
                  local_84[iVar19 + iVar7] = cVar22;
                  iVar19 = iVar19 + 1;
                  cVar22 = *pcVar10;
                } while (cVar22 != '\0');
              }
              local_84 = local_84 + iVar19 + iVar7;
              iVar19 = iVar26 * 4;
              iVar7 = ((int (*)())FUN_0000cdf0)(local_84,*(undefined4 *)((int)pvVar31 + iVar19));
              iVar11 = 0;
              if (s___001a4468[0] != '\0') {
                pcVar10 = "]";
                cVar22 = s___001a4468[0];
                do {
                  pcVar10 = pcVar10 + 1;
                  local_84[iVar11 + iVar7] = cVar22;
                  iVar11 = iVar11 + 1;
                  cVar22 = *pcVar10;
                } while (cVar22 != '\0');
              }
              local_84 = local_84 + iVar11 + iVar7;
              uVar17 = *puVar28;
              in_r7 = (void *)(uVar17 >> 0x1d);
              in_r6 = (uint *)(uVar17 >> 0x1a & 7);
              local_84 = (undefined1 *)((int (*)())FUN_0000ce90)(local_84,uVar17 >> 0x18 & 3,0,in_r6,in_r7);
              iVar7 = 0;
              iVar11 = 1;
            }
            else {
              iVar19 = iVar26 << 2;
              iVar11 = iVar7 + 2;
              iVar7 = iVar7 + 1;
            }
            if (iVar11 == *(int *)((int)pvVar31 + iVar19)) {
              iVar26 = iVar26 + 1;
              iVar7 = -1;
            }
          }
          uVar36 = uVar36 + 1;
          if (uVar34 == uVar36) {
            iVar19 = 0;
            if (s___001a46fc[0] != '\0') {
              pcVar10 = ";\n";
              cVar22 = s___001a46fc[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar19] = cVar22;
                iVar19 = iVar19 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
LAB_00010780:
            local_84 = local_84 + iVar19;
            bVar2 = false;
          }
          else if (puVar28[2] >> 0x1d == uVar38 >> 0x1d) {
            bVar2 = false;
            if (iVar7 == -1) {
              iVar19 = 0;
              if (s___001a44f4[0] != '\0') {
                pcVar10 = ", ";
                cVar22 = s___001a44f4[0];
                do {
                  pcVar10 = pcVar10 + 1;
                  local_84[iVar19] = cVar22;
                  iVar19 = iVar19 + 1;
                  cVar22 = *pcVar10;
                } while (cVar22 != '\0');
              }
              goto LAB_00010780;
            }
          }
          else {
            iVar19 = 0;
            if (s___001a46fc[0] != '\0') {
              pcVar10 = ";\n";
              cVar22 = s___001a46fc[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar19] = cVar22;
                iVar19 = iVar19 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
            local_84 = local_84 + iVar19;
            bVar2 = true;
          }
          iVar19 = ((int (*)())FUN_0000c8a0)(local_58,&local_88,local_5c);
          if (iVar19 == 0) goto LAB_00014070;
          if ((int)uVar34 <= (int)uVar36) goto LAB_000107a8;
          puVar28 = puVar28 + 2;
        } while (!bVar2);
      } while( true );
    }
    iVar7 = -1;
    puVar25 = (uint *)0x0;
    pvVar24 = (void *)0x0;
  }
  else {
    if (0 < (int)uVar34) {
      uVar36 = 0xffffffff;
      puVar25 = puVar32;
      uVar38 = uVar34;
      do {
        if ((int)uVar36 < (int)(uint)*(ushort *)((int)puVar25 + 6)) {
          uVar36 = (uint)*(ushort *)((int)puVar25 + 6);
        }
        puVar25 = puVar25 + 2;
        uVar38 = uVar38 - 1;
      } while (uVar38 != 0);
      if (uVar36 == 0xffffffff) goto LAB_000100c0;
      sVar27 = uVar36 * 4 + 4;
      pvVar24 = _malloc(sVar27);
      puVar25 = _malloc(sVar27);
      if (pvVar24 == (void *)0x0) {
        if (puVar25 != (uint *)0x0) {
LAB_000163f0:
          _free(puVar25);
        }
        goto LAB_00016630;
      }
      if (puVar25 == (uint *)0x0) {
        _free(pvVar24);
        goto LAB_00016630;
      }
    }
    else {
LAB_000100c0:
      pvVar24 = (void *)0x0;
      puVar25 = (uint *)0x0;
    }
    pvVar31 = (void *)0x0;
    if (param_1[0x10] != 0) {
      pvVar31 = _malloc(param_1[0x10] << 2);
    }
    if (0 < (int)uVar34) {
      iVar7 = 0;
      in_r8 = (uint *)0x0;
      in_r7 = (void *)0xffffffff;
      uVar36 = 0xffffffff;
      do {
        in_r10 = (char *)(puVar32 + (int)in_r8 * 2);
        *(uint *)((uint)*(ushort *)((int)in_r10 + 6) * 4 + (int)pvVar24) =
             (uint)*(ushort *)((int)in_r10 + 6);
        uVar17 = param_1[0x10];
        uVar38 = (uint)*(ushort *)((int)in_r10 + 6);
        puVar28 = param_1 + param_1[0x11] * 2;
        if ((uVar17 == 0) || ((int)uVar17 < 1)) {
LAB_00010194:
          puVar25[uVar38] = (uint)in_r7;
          uVar38 = 0xffffffff;
        }
        else {
          puVar33 = puVar28;
          if (uVar38 != (ushort)*puVar28) {
            iVar26 = 8;
            do {
              uVar17 = uVar17 - 1;
              if (uVar17 == 0) goto LAB_00010194;
              puVar33 = (uint *)((int)puVar28 + iVar26);
              iVar26 = iVar26 + 8;
            } while (uVar38 != (ushort)*puVar33);
          }
          uVar36 = (uint)*(ushort *)((int)puVar33 + 6);
          in_r7 = (void *)((int)&MACH_HEADER.magic + 1);
          puVar25[uVar38] = 0;
        }
        if (*(ushort *)((int)in_r10 + 6) == uVar36) {
          iVar26 = iVar7 * 4;
          uVar38 = 0xffffffff;
          iVar7 = iVar7 + 1;
          uVar36 = 0xffffffff;
          *(void **)((int)pvVar31 + iVar26) = in_r7;
          in_r7 = (void *)0xffffffff;
        }
        iVar26 = uVar34 - (int)in_r8;
        puVar28 = puVar32 + (int)in_r8 * 2 + 2;
        if (((int)uVar34 < (int)in_r8 + 1) || (uVar34 == 0x80000000)) {
          iVar26 = 1;
        }
        while( true ) {
          in_r8 = (uint *)((int)in_r8 + 1);
          iVar26 = iVar26 + -1;
          if (iVar26 == 0) goto LAB_0001025c;
          if (uVar38 == 0xffffffff) break;
          if ((int)(uint)*(ushort *)((int)puVar28 + 6) <= (int)uVar36) {
            *(uint *)((uint)*(ushort *)((int)puVar28 + 6) * 4 + (int)pvVar24) = uVar38;
            puVar25[*(ushort *)((int)puVar28 + 6)] = (uint)in_r7;
            in_r7 = (void *)((int)in_r7 + 1);
            if (*(ushort *)((int)puVar28 + 6) == uVar36) {
              iVar19 = iVar7 * 4;
              uVar38 = 0xffffffff;
              iVar7 = iVar7 + 1;
              uVar36 = 0xffffffff;
              *(void **)((int)pvVar31 + iVar19) = in_r7;
              in_r7 = (void *)0xffffffff;
            }
          }
          puVar28 = puVar28 + 2;
        }
      } while( true );
    }
    iVar7 = -1;
LAB_000107a8:
    if (pvVar31 != (void *)0x0) {
      _free(pvVar31);
    }
  }
  if ((uVar34 != 0) && (!bVar3)) {
    iVar26 = 0;
    if (s__001a45c0[0] != '\0') {
      pcVar10 = "\n";
      iVar26 = 0;
      cVar22 = s__001a45c0[0];
      do {
        pcVar10 = pcVar10 + 1;
        local_84[iVar26] = cVar22;
        iVar26 = iVar26 + 1;
        cVar22 = *pcVar10;
      } while (cVar22 != '\0');
    }
    local_84 = local_84 + iVar26;
  }
  uVar34 = param_1[8];
  puVar32 = param_1 + param_1[9] * 2;
  if (0 < (int)uVar34) {
    uVar36 = 0;
    do {
      uVar5 = *(ushort *)puVar32;
      if ((uVar5 & 0xf) != 0) {
        iVar26 = 0;
        if (s_ATTRIB_att_001a4738[0] != '\0') {
          pcVar10 = "ATTRIB att";
          cVar22 = s_ATTRIB_att_001a4738[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar26] = cVar22;
            iVar26 = iVar26 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar26;
        iVar26 = ((int (*)())FUN_0000cdf0)(local_84,(uint)*(ushort *)((int)puVar32 + 6));
        local_84 = local_84 + iVar26;
        if (!bVar3) {
          uVar38 = *puVar32;
          in_r7 = (void *)(uVar38 >> 0x1d);
          in_r6 = (uint *)(uVar38 >> 0x1a & 7);
          local_84 = (undefined1 *)((int (*)())FUN_0000ce90)(local_84,uVar38 >> 0x18 & 3,0,in_r6,in_r7);
        }
        if (uVar30 == 0x8804) {
LAB_00010974:
          iVar26 = 0;
          if (s___fragment__001a4750[0] != '\0') {
            pcVar10 = " = fragment.";
            cVar22 = s___fragment__001a4750[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
LAB_000109bc:
          local_84 = local_84 + iVar26;
        }
        else if (uVar30 < 0x8805) {
          if (uVar30 == 0x8620) {
LAB_0001092c:
            iVar26 = 0;
            if (s___vertex__001a4744[0] != '\0') {
              pcVar10 = " = vertex.";
              cVar22 = s___vertex__001a4744[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar26] = cVar22;
                iVar26 = iVar26 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
            goto LAB_000109bc;
          }
        }
        else {
          if (uVar30 == 0x8b30) goto LAB_00010974;
          if (uVar30 == 0x8b31) goto LAB_0001092c;
        }
        switch(uVar5 & 0xf) {
        default:
          goto switchD_000109e4_caseD_0;
        case 1:
          iVar26 = 0;
          if (s_position_001a4760[0] != '\0') {
            pcVar10 = "position";
            cVar22 = s_position_001a4760[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 2:
          iVar26 = 0;
          if (s_color_primary_001a476c[0] != '\0') {
            pcVar10 = "color.primary";
            cVar22 = s_color_primary_001a476c[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 3:
          iVar26 = 0;
          if (s_color_secondary_001a477c[0] != '\0') {
            pcVar10 = "color.secondary";
            cVar22 = s_color_secondary_001a477c[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 4:
          iVar26 = 0;
          if (s_normal_001a478c[0] != '\0') {
            pcVar10 = "normal";
            cVar22 = s_normal_001a478c[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 5:
          iVar26 = 0;
          if (s_fogcoord_001a4794[0] != '\0') {
            pcVar10 = "fogcoord";
            cVar22 = s_fogcoord_001a4794[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 6:
          iVar26 = 0;
          if (s_weight__001a47b8[0] != '\0') {
            pcVar10 = "weight[";
            cVar22 = s_weight__001a47b8[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          local_84 = local_84 + iVar26;
          iVar19 = ((int (*)())FUN_0000cdf0)(local_84,*puVar32 & 0x1f);
          iVar26 = 0;
          local_84 = local_84 + iVar19;
          if (s___001a4468[0] != '\0') {
            pcVar10 = "]";
            cVar22 = s___001a4468[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 7:
          iVar26 = 0;
          if (s_texcoord__001a47ac[0] != '\0') {
            pcVar10 = "texcoord[";
            cVar22 = s_texcoord__001a47ac[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          local_84 = local_84 + iVar26;
          iVar19 = ((int (*)())FUN_0000cdf0)(local_84,*puVar32 & 0x1f);
          iVar26 = 0;
          local_84 = local_84 + iVar19;
          if (s___001a4468[0] != '\0') {
            pcVar10 = "]";
            cVar22 = s___001a4468[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 8:
          iVar26 = 0;
          if (s_matrixindex__001a47c0[0] != '\0') {
            pcVar10 = "matrixindex[";
            cVar22 = s_matrixindex__001a47c0[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          local_84 = local_84 + iVar26;
          iVar19 = ((int (*)())FUN_0000cdf0)(local_84,*puVar32 & 0x1f);
          iVar26 = 0;
          local_84 = local_84 + iVar19;
          if (s___001a4468[0] != '\0') {
            pcVar10 = "]";
            cVar22 = s___001a4468[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 9:
          iVar26 = 0;
          if (s_attrib__001a47d0[0] != '\0') {
            pcVar10 = "attrib[";
            cVar22 = s_attrib__001a47d0[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          local_84 = local_84 + iVar26;
          iVar19 = ((int (*)())FUN_0000cdf0)(local_84,*puVar32 & 0x1f);
          iVar26 = 0;
          local_84 = local_84 + iVar19;
          if (s___001a4468[0] != '\0') {
            pcVar10 = "]";
            cVar22 = s___001a4468[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 10:
          iVar26 = 0;
          if (s_material__001a47d8[0] != '\0') {
            pcVar10 = "material.";
            iVar26 = 0;
            cVar22 = s_material__001a47d8[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          uVar38 = *puVar32;
          local_84 = local_84 + iVar26;
          if ((uVar38 & 1) == 0) {
            iVar26 = 0;
            if (s_front__001a47e4[0] != '\0') {
              pcVar10 = "front.";
              cVar22 = s_front__001a47e4[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar26] = cVar22;
                iVar26 = iVar26 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
LAB_00010f94:
              uVar38 = *puVar32;
            }
LAB_00010f9c:
            local_84 = local_84 + iVar26;
          }
          else if ((uVar38 & 1) == 1) {
            iVar26 = 0;
            if (s_back__001a47ec[0] != '\0') {
              pcVar10 = "back.";
              cVar22 = s_back__001a47ec[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar26] = cVar22;
                iVar26 = iVar26 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
              goto LAB_00010f94;
            }
            goto LAB_00010f9c;
          }
          switch(uVar38 >> 0xc & 0xf) {
          case 0:
            iVar26 = 0;
            if (s_ambient_001a47f4[0] != '\0') {
              pcVar10 = "ambient";
              cVar22 = s_ambient_001a47f4[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar26] = cVar22;
                iVar26 = iVar26 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
            break;
          case 1:
            iVar26 = 0;
            if (s_diffuse_001a47fc[0] != '\0') {
              pcVar10 = "diffuse";
              cVar22 = s_diffuse_001a47fc[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar26] = cVar22;
                iVar26 = iVar26 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
            break;
          case 2:
            iVar26 = 0;
            if (s_specular_001a4804[0] != '\0') {
              pcVar10 = "specular";
              cVar22 = s_specular_001a4804[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar26] = cVar22;
                iVar26 = iVar26 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
            break;
          case 3:
            iVar26 = 0;
            if (s_emission_001a4810[0] != '\0') {
              pcVar10 = "emission";
              cVar22 = s_emission_001a4810[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar26] = cVar22;
                iVar26 = iVar26 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
            break;
          case 4:
            iVar26 = 0;
            if (s_shininess_001a481c[0] != '\0') {
              pcVar10 = "shininess";
              cVar22 = s_shininess_001a481c[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar26] = cVar22;
                iVar26 = iVar26 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
            break;
          default:
            goto switchD_000109e4_caseD_0;
          }
          break;
        case 0xb:
          iVar26 = 0;
          if (s_frontfacing_001a47a0[0] != '\0') {
            pcVar10 = "frontfacing";
            cVar22 = s_frontfacing_001a47a0[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
        }
        local_84 = local_84 + iVar26;
switchD_000109e4_caseD_0:
        iVar26 = 0;
        if (s___001a46fc[0] != '\0') {
          pcVar10 = ";\n";
          cVar22 = s___001a46fc[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar26] = cVar22;
            iVar26 = iVar26 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar26;
        iVar26 = ((int (*)())FUN_0000c8a0)(local_80,&local_88,&local_84);
        if (iVar26 == 0) goto LAB_00014070;
      }
      uVar36 = uVar36 + 1;
      puVar32 = puVar32 + 2;
    } while (uVar34 != uVar36);
  }
  if ((uVar34 != 0) && (!bVar3)) {
    iVar26 = 0;
    if (s__001a45c0[0] != '\0') {
      pcVar10 = "\n";
      iVar26 = 0;
      cVar22 = s__001a45c0[0];
      do {
        pcVar10 = pcVar10 + 1;
        local_84[iVar26] = cVar22;
        iVar26 = iVar26 + 1;
        cVar22 = *pcVar10;
      } while (cVar22 != '\0');
    }
    local_84 = local_84 + iVar26;
  }
  puVar32 = (uint *)param_1[10];
  puVar28 = param_1 + param_1[0xb] * 2;
  if (puVar32 == (uint *)0x0) {
    local_6c = (void *)0x0;
    local_70 = (uint *)0x0;
    goto LAB_0001376c;
  }
  if ((int)puVar32 < 1) {
LAB_000112d0:
    local_6c = (void *)0x0;
    local_70 = (uint *)0x0;
  }
  else {
    uVar34 = 0xffffffff;
    puVar33 = puVar28;
    puVar40 = puVar32;
    do {
      if ((int)uVar34 < (int)(uint)*(ushort *)((int)puVar33 + 6)) {
        uVar34 = (uint)*(ushort *)((int)puVar33 + 6);
      }
      puVar33 = puVar33 + 2;
      puVar40 = (uint *)((int)puVar40 - 1);
    } while (puVar40 != (uint *)0x0);
    if (uVar34 == 0xffffffff) goto LAB_000112d0;
    sVar27 = uVar34 * 4 + 4;
    local_6c = _malloc(sVar27);
    local_70 = _malloc(sVar27);
    if (local_6c == (void *)0x0) goto joined_r0x000112bc;
    if (local_70 == (uint *)0x0) {
      _free(local_6c);
      goto LAB_00014070;
    }
  }
  puVar33 = (uint *)0x0;
  if (param_1[0xe] != 0) {
    puVar33 = _malloc(param_1[0xe] << 2);
  }
  if ((int)puVar32 >= 1) {
    in_r10 = (char *)0x0;
    in_r7 = (void *)0xffffffff;
    in_r6 = (uint *)0xffffffff;
    uVar34 = 0xffffffff;
    puVar40 = puVar33;
    puVar21 = puVar28;
    do {
      if ((*puVar21 & 0x1f0000) != 0) {
        if (in_r6 == (uint *)0xffffffff) {
          *(uint *)((uint)*(ushort *)((int)puVar21 + 6) * 4 + (int)local_6c) =
               (uint)*(ushort *)((int)puVar21 + 6);
          uVar36 = param_1[0xe];
          in_r6 = (uint *)(uint)*(ushort *)((int)puVar21 + 6);
          puVar18 = param_1 + param_1[0xf] * 2;
          if ((uVar36 == 0) || ((int)uVar36 < 1)) {
LAB_000113ac:
            local_70[(int)in_r6] = (uint)in_r7;
            in_r6 = (uint *)0xffffffff;
            in_r8 = puVar18;
          }
          else {
            in_r8 = puVar18;
            if (in_r6 != (uint *)(uint)(ushort)*puVar18) {
              iVar26 = 8;
              do {
                uVar36 = uVar36 - 1;
                if (uVar36 == 0) goto LAB_000113ac;
                in_r8 = (uint *)((int)puVar18 + iVar26);
                iVar26 = iVar26 + 8;
              } while (in_r6 != (uint *)(uint)(ushort)*in_r8);
            }
            uVar34 = (uint)*(ushort *)((int)in_r8 + 6);
            in_r7 = (void *)((int)&MACH_HEADER.magic + 1);
            local_70[(int)in_r6] = 0;
          }
          if (*(ushort *)((int)puVar21 + 6) == uVar34) {
LAB_00011410:
            *puVar40 = (uint)in_r7;
            in_r6 = (uint *)0xffffffff;
            puVar40 = puVar40 + 1;
            in_r7 = (void *)0xffffffff;
            uVar34 = 0xffffffff;
          }
        }
        else if ((int)(uint)*(ushort *)((int)puVar21 + 6) <= (int)uVar34) {
          *(uint **)((uint)*(ushort *)((int)puVar21 + 6) * 4 + (int)local_6c) = in_r6;
          local_70[*(ushort *)((int)puVar21 + 6)] = (uint)in_r7;
          in_r7 = (void *)((int)in_r7 + 1);
          if (*(ushort *)((int)puVar21 + 6) == uVar34) goto LAB_00011410;
        }
      }
      uVar41 = (ulonglong)uVar34;
      in_r10 = (char *)((int)in_r10 + 1);
      puVar21 = puVar21 + 2;
    } while (puVar32 != (uint *)in_r10);
    iVar26 = 0;
    puVar40 = (uint *)0x0;
    do {
      uVar5 = *(ushort *)puVar28;
      uVar39 = uVar5 & 0x1f;
      if ((uVar5 & 0x1f) == 0) goto LAB_000136f0;
      uVar34 = (uint)*(ushort *)((int)puVar28 + 6);
      if (local_70[uVar34] == 0xffffffff) {
        iVar19 = 0;
        if (s_PARAM_prm_001a4828[0] != '\0') {
          pcVar10 = "PARAM prm";
          cVar22 = s_PARAM_prm_001a4828[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
          uVar34 = (uint)*(ushort *)((int)puVar28 + 6);
        }
        local_84 = local_84 + iVar19;
        uVar41 = ((int (*)())FUN_0000cdf0)(local_84,*(undefined4 *)((int)local_6c + uVar34 * 4));
        local_84 = local_84 + (int)(uVar41 >> 0x20);
        if (!bVar3) {
          uVar34 = *puVar28;
          in_r7 = (void *)(uVar34 >> 0x1d);
          in_r6 = (uint *)(uVar34 >> 0x1a & 7);
          uVar41 = ((int (*)())FUN_0000ce90)(local_84,uVar34 >> 0x18 & 3,0,in_r6,in_r7);
          local_84 = (undefined1 *)(uVar41 >> 0x20);
        }
        iVar19 = 0;
        if (s___001a4834[0] != '\0') {
          pcVar10 = " = ";
          cVar22 = s___001a4834[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
LAB_00011758:
        local_84 = local_84 + iVar19;
      }
      else {
        if (local_70[uVar34] != 0) {
          iVar7 = iVar7 + 1;
          iVar19 = 0;
          if (s__001a4844[0] != '\0') {
            pcVar10 = "    ";
            cVar22 = s__001a4844[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          goto LAB_00011758;
        }
        iVar7 = 0;
        if (s_PARAM_prm_001a4828[0] != '\0') {
          pcVar10 = "PARAM prm";
          cVar22 = s_PARAM_prm_001a4828[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
          uVar34 = (uint)*(ushort *)((int)puVar28 + 6);
        }
        local_84 = local_84 + iVar7;
        iVar7 = ((int (*)())FUN_0000cdf0)(local_84,*(undefined4 *)((int)local_6c + uVar34 * 4));
        iVar19 = 0;
        if (s___001a4464[0] != '\0') {
          pcVar10 = "[";
          cVar22 = s___001a4464[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19 + iVar7] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar19 + iVar7;
        uVar41 = ((int (*)())FUN_0000cdf0)(local_84,puVar33[iVar26]);
        iVar7 = (int)(uVar41 >> 0x20);
        iVar19 = 0;
        if (s___001a4468[0] != '\0') {
          pcVar10 = "]";
          cVar22 = s___001a4468[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19 + iVar7] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar19 + iVar7;
        if (!bVar3) {
          uVar34 = *puVar28;
          in_r7 = (void *)(uVar34 >> 0x1d);
          in_r6 = (uint *)(uVar34 >> 0x1a & 7);
          uVar41 = ((int (*)())FUN_0000ce90)(local_84,uVar34 >> 0x18 & 3,0,in_r6,in_r7);
          local_84 = (undefined1 *)(uVar41 >> 0x20);
        }
        iVar7 = 0;
        if (s_____001a4838[0] != '\0') {
          pcVar10 = " = {\n    ";
          cVar22 = s_____001a4838[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar7;
        iVar7 = 0;
      }
      if ((uVar5 & 0x1f) != 0) {
        if (uVar39 < 3) {
          iVar19 = 0;
          if (s_program__001a484c[0] != '\0') {
            pcVar10 = "program.";
            cVar22 = s_program__001a484c[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          goto LAB_000118a8;
        }
        if (uVar39 != 0x11) goto LAB_00011778;
        iVar19 = 0;
        if (s__001a4134[0] != '\0') {
          pcVar10 = "";
          acVar8 = s__001a4134[0];
          do {
            local_84[iVar19] = acVar8;
            iVar19 = iVar19 + 1;
            acVar8 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (acVar8 != '\0');
        }
        local_84 = local_84 + iVar19;
switchD_000118c8_caseD_11:
        pfVar35 = (float *)(param_1 + param_1[0x1b] * 2 + (uint)(ushort)*puVar28 * 4);
        switch(*puVar28 >> 0x1a & 7) {
        case 0:
        case 1:
          iVar19 = 0;
          if (s___001a49dc[0] != '\0') {
            pcVar10 = "{";
            cVar22 = s___001a49dc[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          local_84 = local_84 + iVar19;
          local_60 = 0x19f634;
          uVar42 = ((char * (*)())FUN_0000bfa0)((int)(uVar41 >> 0x20),(int)uVar41,local_84,
                                (int)local_88 + (local_80[0] - (int)local_84),(double)*pfVar35,
                                DOUBLE_001aa248);
          iVar19 = (int)((ulonglong)uVar42 >> 0x20);
          cVar22 = ((unsigned char *)0x00004ec0)[local_60];
          bVar2 = cVar22 != '\0';
          if (bVar2) {
            pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
            iVar11 = 0;
            cVar9 = cVar22;
            do {
              *(char *)(iVar19 + iVar11) = cVar9;
              iVar11 = iVar11 + 1;
              cVar9 = *pcVar10;
              pcVar10 = pcVar10 + 1;
            } while (cVar9 != '\0');
          }
          else {
            iVar11 = 0;
          }
          local_84 = (undefined1 *)(iVar11 + iVar19);
          uVar42 = ((char * (*)())FUN_0000bfa0)(iVar19,(int)uVar42,local_84,
                                (int)local_88 + (local_80[0] - (int)local_84),(double)pfVar35[1],
                                DOUBLE_001aa248);
          iVar19 = (int)((ulonglong)uVar42 >> 0x20);
          if (bVar2) {
            iVar11 = 0;
            pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
            cVar9 = cVar22;
            do {
              *(char *)(iVar19 + iVar11) = cVar9;
              iVar11 = iVar11 + 1;
              cVar9 = *pcVar10;
              pcVar10 = pcVar10 + 1;
            } while (cVar9 != '\0');
          }
          else {
            iVar11 = 0;
          }
          local_84 = (undefined1 *)(iVar11 + iVar19);
          uVar42 = ((char * (*)())FUN_0000bfa0)(iVar19,(int)uVar42,local_84,
                                (int)local_88 + (local_80[0] - (int)local_84),(double)pfVar35[2],
                                DOUBLE_001aa248);
          iVar19 = (int)((ulonglong)uVar42 >> 0x20);
          if (bVar2) {
            iVar11 = 0;
            pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
            do {
              *(char *)(iVar19 + iVar11) = cVar22;
              iVar11 = iVar11 + 1;
              cVar22 = *pcVar10;
              pcVar10 = pcVar10 + 1;
            } while (cVar22 != '\0');
          }
          else {
            iVar11 = 0;
          }
          local_84 = (undefined1 *)(iVar11 + iVar19);
          in_r6 = (uint *)((int)local_88 + (local_80[0] - (int)local_84));
          iVar19 = ((char * (*)())FUN_0000bfa0)(iVar19,(int)uVar42,local_84,in_r6,(double)pfVar35[3],DOUBLE_001aa248
                               );
          iVar11 = 0;
          if (s___001a49e0[0] != '\0') {
            pcVar10 = "}";
            cVar22 = s___001a49e0[0];
            do {
              pcVar10 = pcVar10 + 1;
              *(char *)(iVar19 + iVar11) = cVar22;
              iVar11 = iVar11 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          local_84 = (undefined1 *)(iVar11 + iVar19);
          break;
        case 2:
          iVar19 = 0;
          if (s_____Fixed_constant_data_not_curr_001a49e4[0] != '\0') {
            pcVar10 = "{-- Fixed constant data not currently supported --}";
            cVar22 = s_____Fixed_constant_data_not_curr_001a49e4[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          goto LAB_000135c0;
        case 3:
        case 4:
          iVar19 = 0;
          if (s___001a49dc[0] != '\0') {
            pcVar10 = "{";
            cVar22 = s___001a49dc[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          local_84 = local_84 + iVar19;
          local_60 = 0x19f634;
          iVar19 = ((int (*)())FUN_0000cdf0)(local_84,*pfVar35);
          cVar22 = ((unsigned char *)0x00004ec0)[local_60];
          bVar2 = cVar22 != '\0';
          if (bVar2) {
            pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
            iVar11 = 0;
            cVar9 = cVar22;
            do {
              local_84[iVar11 + iVar19] = cVar9;
              iVar11 = iVar11 + 1;
              cVar9 = *pcVar10;
              pcVar10 = pcVar10 + 1;
            } while (cVar9 != '\0');
          }
          else {
            iVar11 = 0;
          }
          local_84 = local_84 + iVar11 + iVar19;
          iVar19 = ((int (*)())FUN_0000cdf0)(local_84,pfVar35[1]);
          if (bVar2) {
            iVar11 = 0;
            pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
            cVar9 = cVar22;
            do {
              local_84[iVar11 + iVar19] = cVar9;
              iVar11 = iVar11 + 1;
              cVar9 = *pcVar10;
              pcVar10 = pcVar10 + 1;
            } while (cVar9 != '\0');
          }
          else {
            iVar11 = 0;
          }
          local_84 = local_84 + iVar11 + iVar19;
          iVar19 = ((int (*)())FUN_0000cdf0)(local_84,pfVar35[2]);
          if (bVar2) {
            iVar11 = 0;
            pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
            do {
              local_84[iVar11 + iVar19] = cVar22;
              iVar11 = iVar11 + 1;
              cVar22 = *pcVar10;
              pcVar10 = pcVar10 + 1;
            } while (cVar22 != '\0');
          }
          else {
            iVar11 = 0;
          }
          local_84 = local_84 + iVar11 + iVar19;
          iVar11 = ((int (*)())FUN_0000cdf0)(local_84,pfVar35[3]);
          iVar19 = 0;
          local_84 = local_84 + iVar11;
          if (s___001a49e0[0] != '\0') {
            pcVar10 = "}";
            cVar22 = s___001a49e0[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          goto LAB_000135c0;
        }
        goto switchD_000118c8_caseD_0;
      }
LAB_00011778:
      if (s_state__001a4858[0] == '\0') {
        iVar19 = 0;
      }
      else {
        pcVar10 = "state.";
        iVar19 = 0;
        cVar22 = s_state__001a4858[0];
        do {
          pcVar10 = pcVar10 + 1;
          local_84[iVar19] = cVar22;
          iVar19 = iVar19 + 1;
          cVar22 = *pcVar10;
        } while (cVar22 != '\0');
      }
LAB_000118a8:
      local_84 = local_84 + iVar19;
      switch(uVar39) {
      default:
        goto switchD_000118c8_caseD_0;
      case 1:
        iVar19 = 0;
        if (s_local__001a4860[0] != '\0') {
          pcVar10 = "local[";
          cVar22 = s_local__001a4860[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar19;
        iVar11 = ((int (*)())FUN_0000cdf0)(local_84,(uint)(ushort)*puVar28);
        iVar19 = 0;
        local_84 = local_84 + iVar11;
        if (s___001a4468[0] != '\0') {
          pcVar10 = "]";
          cVar22 = s___001a4468[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 2:
        iVar19 = 0;
        if (s_env__001a4868[0] != '\0') {
          pcVar10 = "env[";
          cVar22 = s_env__001a4868[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar19;
        iVar11 = ((int (*)())FUN_0000cdf0)(local_84,(uint)(ushort)*puVar28);
        iVar19 = 0;
        local_84 = local_84 + iVar11;
        if (s___001a4468[0] != '\0') {
          pcVar10 = "]";
          cVar22 = s___001a4468[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 3:
        iVar19 = 0;
        if (s_light__001a4870[0] != '\0') {
          pcVar10 = "light[";
          cVar22 = s_light__001a4870[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar19;
        iVar19 = ((int (*)())FUN_0000cdf0)(local_84,(uint)(byte)*puVar28);
        iVar11 = 0;
        if (s____001a4878[0] != '\0') {
          pcVar10 = "].";
          cVar22 = s____001a4878[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar11 + iVar19] = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar11 + iVar19;
        switch(*puVar28 >> 8 & 0xf) {
        case 0:
          iVar19 = 0;
          if (s_ambient_001a47f4[0] != '\0') {
            pcVar10 = "ambient";
            cVar22 = s_ambient_001a47f4[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 1:
          iVar19 = 0;
          if (s_diffuse_001a47fc[0] != '\0') {
            pcVar10 = "diffuse";
            cVar22 = s_diffuse_001a47fc[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 2:
          iVar19 = 0;
          if (s_specular_001a4804[0] != '\0') {
            pcVar10 = "specular";
            cVar22 = s_specular_001a4804[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 3:
          iVar19 = 0;
          if (s_position_001a4760[0] != '\0') {
            pcVar10 = "position";
            cVar22 = s_position_001a4760[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 4:
          iVar19 = 0;
          if (s_spot_direction_001a487c[0] != '\0') {
            pcVar10 = "spot.direction";
            cVar22 = s_spot_direction_001a487c[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 5:
          iVar19 = 0;
          if (s_attenuation_001a488c[0] != '\0') {
            pcVar10 = "attenuation";
            cVar22 = s_attenuation_001a488c[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 6:
          iVar19 = 0;
          if (s_half_001a4898[0] != '\0') {
            pcVar10 = "half";
            cVar22 = s_half_001a4898[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 7:
          iVar19 = 0;
          if (s_spotcutoff_001a48a0[0] != '\0') {
            pcVar10 = "spotcutoff";
            cVar22 = s_spotcutoff_001a48a0[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        default:
          goto switchD_000118c8_caseD_0;
        }
        break;
      case 4:
        iVar19 = 0;
        if (s_lightprod__001a48ac[0] != '\0') {
          pcVar10 = "lightprod[";
          cVar22 = s_lightprod__001a48ac[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar19;
        iVar19 = ((int (*)())FUN_0000cdf0)(local_84,(uint)(byte)*puVar28);
        iVar11 = 0;
        if (s____001a4878[0] != '\0') {
          pcVar10 = "].";
          cVar22 = s____001a4878[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar11 + iVar19] = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        uVar36 = *puVar28;
        local_84 = local_84 + iVar11 + iVar19;
        uVar34 = uVar36 >> 8 & 1;
        if (uVar34 == 0) {
          iVar19 = 0;
          if (s_front__001a47e4[0] != '\0') {
            pcVar10 = "front.";
            cVar22 = s_front__001a47e4[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
LAB_00011f20:
            uVar36 = *puVar28;
          }
LAB_00011f28:
          local_84 = local_84 + iVar19;
        }
        else if (uVar34 == 1) {
          iVar19 = 0;
          if (s_back__001a47ec[0] != '\0') {
            pcVar10 = "back.";
            cVar22 = s_back__001a47ec[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
            goto LAB_00011f20;
          }
          goto LAB_00011f28;
        }
        uVar34 = uVar36 >> 9 & 3;
        if (uVar34 == 1) {
          iVar19 = 0;
          if (s_diffuse_001a47fc[0] != '\0') {
            pcVar10 = "diffuse";
            cVar22 = s_diffuse_001a47fc[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
        }
        else if (uVar34 == 2) {
          iVar19 = 0;
          if (s_specular_001a4804[0] != '\0') {
            pcVar10 = "specular";
            cVar22 = s_specular_001a4804[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
        }
        else {
          if (uVar34 != 0) goto switchD_000118c8_caseD_0;
          iVar19 = 0;
          if (s_ambient_001a47f4[0] != '\0') {
            pcVar10 = "ambient";
            cVar22 = s_ambient_001a47f4[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
        }
        break;
      case 5:
        uVar34 = *puVar28;
        if ((uVar34 >> 1 & 7) == 5) {
          iVar19 = 0;
          if (s_lightmodel__001a48cc[0] != '\0') {
            pcVar10 = "lightmodel.";
            cVar22 = s_lightmodel__001a48cc[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
LAB_00012114:
            uVar34 = *puVar28;
          }
        }
        else {
          iVar19 = 0;
          if (s_material__001a47d8[0] != '\0') {
            pcVar10 = "material.";
            cVar22 = s_material__001a47d8[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
            goto LAB_00012114;
          }
        }
        local_84 = local_84 + iVar19;
        if ((uVar34 & 1) == 0) {
          iVar19 = 0;
          if (s_front__001a47e4[0] != '\0') {
            pcVar10 = "front.";
            cVar22 = s_front__001a47e4[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
LAB_000121c4:
            uVar34 = *puVar28;
          }
LAB_000121cc:
          local_84 = local_84 + iVar19;
        }
        else if ((uVar34 & 1) == 1) {
          iVar19 = 0;
          if (s_back__001a47ec[0] != '\0') {
            pcVar10 = "back.";
            cVar22 = s_back__001a47ec[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
            goto LAB_000121c4;
          }
          goto LAB_000121cc;
        }
        switch(uVar34 >> 1 & 7) {
        case 0:
          iVar19 = 0;
          if (s_ambient_001a47f4[0] != '\0') {
            pcVar10 = "ambient";
            cVar22 = s_ambient_001a47f4[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 1:
          iVar19 = 0;
          if (s_diffuse_001a47fc[0] != '\0') {
            pcVar10 = "diffuse";
            cVar22 = s_diffuse_001a47fc[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 2:
          iVar19 = 0;
          if (s_specular_001a4804[0] != '\0') {
            pcVar10 = "specular";
            cVar22 = s_specular_001a4804[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 3:
          iVar19 = 0;
          if (s_emission_001a4810[0] != '\0') {
            pcVar10 = "emission";
            cVar22 = s_emission_001a4810[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 4:
          iVar19 = 0;
          if (s_shininess_001a481c[0] != '\0') {
            pcVar10 = "shininess";
            cVar22 = s_shininess_001a481c[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 5:
          iVar19 = 0;
          if (s_scenecolor_001a48d8[0] != '\0') {
            pcVar10 = "scenecolor";
            cVar22 = s_scenecolor_001a48d8[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        default:
          goto switchD_000118c8_caseD_0;
        }
        break;
      case 6:
        iVar19 = 0;
        if (s_lightmodel_ambient_001a48b8[0] != '\0') {
          pcVar10 = "lightmodel.ambient";
          cVar22 = s_lightmodel_ambient_001a48b8[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 7:
        iVar19 = 0;
        if (s_texgen__001a48e4[0] != '\0') {
          pcVar10 = "texgen[";
          cVar22 = s_texgen__001a48e4[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar19;
        iVar19 = ((int (*)())FUN_0000cdf0)(local_84,*puVar28 & 0x1f);
        iVar11 = 0;
        if (s___eye__001a48ec[0] != '\0') {
          pcVar10 = "].eye.";
          cVar22 = s___eye__001a48ec[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar11 + iVar19] = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar11 + iVar19;
        uVar34 = *puVar28 >> 5 & 7;
        if (uVar34 == 1) {
          iVar19 = 0;
          if (s_t_001a48f8[0] != '\0') {
            pcVar10 = "t";
            cVar22 = s_t_001a48f8[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
        }
        else if (uVar34 < 2) {
          if (uVar34 != 0) goto switchD_000118c8_caseD_0;
          iVar19 = 0;
          if (s_s_001a48f4[0] != '\0') {
            pcVar10 = "s";
            cVar22 = s_s_001a48f4[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
        }
        else if (uVar34 == 2) {
          iVar19 = 0;
          if (s_r_001a48fc[0] != '\0') {
            pcVar10 = "r";
            cVar22 = s_r_001a48fc[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
        }
        else {
          if (uVar34 != 3) goto switchD_000118c8_caseD_0;
          iVar19 = 0;
          if (s_q_001a4900[0] != '\0') {
            pcVar10 = "q";
            cVar22 = s_q_001a4900[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
        }
        break;
      case 8:
        iVar19 = 0;
        if (s_texgen__001a48e4[0] != '\0') {
          pcVar10 = "texgen[";
          cVar22 = s_texgen__001a48e4[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar19;
        iVar19 = ((int (*)())FUN_0000cdf0)(local_84,*puVar28 & 0x1f);
        iVar11 = 0;
        if (s___object__001a4904[0] != '\0') {
          pcVar10 = "].object.";
          cVar22 = s___object__001a4904[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar11 + iVar19] = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar11 + iVar19;
        uVar34 = *puVar28 >> 5 & 7;
        if (uVar34 == 1) {
          iVar19 = 0;
          if (s_t_001a48f8[0] != '\0') {
            pcVar10 = "t";
            cVar22 = s_t_001a48f8[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
        }
        else if (uVar34 < 2) {
          if (uVar34 != 0) goto switchD_000118c8_caseD_0;
          iVar19 = 0;
          if (s_s_001a48f4[0] != '\0') {
            pcVar10 = "s";
            cVar22 = s_s_001a48f4[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
        }
        else if (uVar34 == 2) {
          iVar19 = 0;
          if (s_r_001a48fc[0] != '\0') {
            pcVar10 = "r";
            cVar22 = s_r_001a48fc[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
        }
        else {
          if (uVar34 != 3) goto switchD_000118c8_caseD_0;
          iVar19 = 0;
          if (s_q_001a4900[0] != '\0') {
            pcVar10 = "q";
            cVar22 = s_q_001a4900[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
        }
        break;
      case 9:
        iVar19 = 0;
        if (s_texenv__001a4910[0] != '\0') {
          pcVar10 = "texenv[";
          cVar22 = s_texenv__001a4910[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar19;
        iVar11 = ((int (*)())FUN_0000cdf0)(local_84,*puVar28 & 0x1f);
        iVar19 = 0;
        local_84 = local_84 + iVar11;
        if (s___color_001a4918[0] != '\0') {
          pcVar10 = "].color";
          cVar22 = s___color_001a4918[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 10:
        iVar19 = 0;
        if (s_clip__001a4920[0] != '\0') {
          pcVar10 = "clip[";
          cVar22 = s_clip__001a4920[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar19;
        iVar11 = ((int (*)())FUN_0000cdf0)(local_84,(uint)(byte)*puVar28);
        iVar19 = 0;
        local_84 = local_84 + iVar11;
        if (s___plane_001a4928[0] != '\0') {
          pcVar10 = "].plane";
          cVar22 = s___plane_001a4928[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 0xb:
        iVar19 = 0;
        if (s_fog_color_001a4930[0] != '\0') {
          pcVar10 = "fog.color";
          cVar22 = s_fog_color_001a4930[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 0xc:
        iVar19 = 0;
        if (s_fog_params_001a493c[0] != '\0') {
          pcVar10 = "fog.params";
          cVar22 = s_fog_params_001a493c[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 0xd:
        iVar19 = 0;
        if (s_point_size_001a4954[0] != '\0') {
          pcVar10 = "point.size";
          cVar22 = s_point_size_001a4954[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 0xe:
        iVar19 = 0;
        if (s_point_attenuation_001a4960[0] != '\0') {
          pcVar10 = "point.attenuation";
          cVar22 = s_point_attenuation_001a4960[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 0xf:
        iVar19 = 0;
        if (s_depth_range_001a4948[0] != '\0') {
          pcVar10 = "depth.range";
          cVar22 = s_depth_range_001a4948[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 0x10:
        iVar19 = 0;
        if (s_matrix__001a4974[0] != '\0') {
          pcVar10 = "matrix.";
          cVar22 = s_matrix__001a4974[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        uVar34 = *puVar28;
        local_84 = local_84 + iVar19;
        switch(uVar34 >> 8 & 7) {
        case 0:
          iVar11 = 0;
          if (s_mvp__001a4988[0] != '\0') {
            pcVar10 = "mvp.";
            cVar22 = s_mvp__001a4988[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar11] = cVar22;
              iVar11 = iVar11 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
LAB_00012bfc:
            uVar34 = *puVar28;
          }
          goto LAB_00012e2c;
        case 1:
          iVar11 = 0;
          if (s_projection__001a497c[0] != '\0') {
            pcVar10 = "projection.";
            cVar22 = s_projection__001a497c[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar11] = cVar22;
              iVar11 = iVar11 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
            goto LAB_00012bfc;
          }
          goto LAB_00012e2c;
        case 2:
          iVar19 = 0;
          if (s_color__001a4990[0] != '\0') {
            pcVar10 = "color[";
            cVar22 = s_color__001a4990[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          local_84 = local_84 + iVar19;
          iVar19 = ((int (*)())FUN_0000cdf0)(local_84,(uint)(byte)*puVar28);
          iVar11 = 0;
          local_84 = local_84 + iVar19;
          if (s____001a4878[0] != '\0') {
            pcVar10 = "].";
            cVar22 = s____001a4878[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar11] = cVar22;
              iVar11 = iVar11 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          goto LAB_00012d68;
        case 3:
          iVar19 = 0;
          if (s_modelview__001a4998[0] != '\0') {
            pcVar10 = "modelview[";
            cVar22 = s_modelview__001a4998[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          local_84 = local_84 + iVar19;
          iVar19 = ((int (*)())FUN_0000cdf0)(local_84,(uint)(byte)*puVar28);
          iVar11 = 0;
          local_84 = local_84 + iVar19;
          if (s____001a4878[0] != '\0') {
            pcVar10 = "].";
            cVar22 = s____001a4878[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar11] = cVar22;
              iVar11 = iVar11 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
LAB_00012d68:
          uVar34 = *puVar28;
          local_84 = local_84 + iVar11;
          break;
        case 4:
          iVar19 = 0;
          if (s_texture__001a4514[0] != '\0') {
            pcVar10 = "texture[";
            cVar22 = s_texture__001a4514[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          local_84 = local_84 + iVar19;
          iVar19 = ((int (*)())FUN_0000cdf0)(local_84,(uint)(byte)*puVar28);
          iVar11 = 0;
          local_84 = local_84 + iVar19;
          if (s____001a4878[0] != '\0') {
            pcVar10 = "].";
            cVar22 = s____001a4878[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar11] = cVar22;
              iVar11 = iVar11 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          uVar34 = *puVar28;
LAB_00012e2c:
          local_84 = local_84 + iVar11;
          break;
        case 5:
          iVar19 = 0;
          if (s_program__001a49a4[0] != '\0') {
            pcVar10 = "program[";
            cVar22 = s_program__001a49a4[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          local_84 = local_84 + iVar19;
          iVar19 = ((int (*)())FUN_0000cdf0)(local_84,(uint)(byte)*puVar28);
          iVar11 = 0;
          if (s____001a4878[0] != '\0') {
            pcVar10 = "].";
            cVar22 = s____001a4878[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar11 + iVar19] = cVar22;
              iVar11 = iVar11 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          local_84 = local_84 + iVar11 + iVar19;
          uVar34 = *puVar28;
        }
        uVar34 = uVar34 >> 0xe & 3;
        if (uVar34 == 2) {
          iVar19 = 0;
          if (s_inverse__001a49bc[0] != '\0') {
            pcVar10 = "inverse.";
            cVar22 = s_inverse__001a49bc[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
LAB_00012ff0:
          local_84 = local_84 + iVar19;
        }
        else {
          if (uVar34 == 3) {
            iVar19 = 0;
            if (s_invtrans__001a49c8[0] != '\0') {
              pcVar10 = "invtrans.";
              cVar22 = s_invtrans__001a49c8[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar19] = cVar22;
                iVar19 = iVar19 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
            goto LAB_00012ff0;
          }
          if (uVar34 == 1) {
            iVar19 = 0;
            if (s_transpose__001a49b0[0] != '\0') {
              pcVar10 = "transpose.";
              cVar22 = s_transpose__001a49b0[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar19] = cVar22;
                iVar19 = iVar19 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
            goto LAB_00012ff0;
          }
        }
        iVar19 = 0;
        if (s_row__001a49d4[0] != '\0') {
          pcVar10 = "row[";
          cVar22 = s_row__001a49d4[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar19;
        iVar11 = ((int (*)())FUN_0000cdf0)(local_84,*puVar28 >> 0xc & 3);
        iVar19 = 0;
        local_84 = local_84 + iVar11;
        if (s___001a4468[0] != '\0') {
          pcVar10 = "]";
          cVar22 = s___001a4468[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 0x11:
        goto switchD_000118c8_caseD_11;
      case 0x12:
        iVar19 = 0;
        if (s_normalscale_001a4a18[0] != '\0') {
          pcVar10 = "normalscale";
          cVar22 = s_normalscale_001a4a18[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
      }
LAB_000135c0:
      local_84 = local_84 + iVar19;
switchD_000118c8_caseD_0:
      if (local_70[*(ushort *)((int)puVar28 + 6)] == 0xffffffff) {
        iVar19 = 0;
        if (s___001a46fc[0] != '\0') {
          pcVar10 = ";\n";
          cVar22 = s___001a46fc[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
      }
      else if (iVar7 + 1U == puVar33[iVar26]) {
        iVar26 = iVar26 + 1;
        iVar19 = 0;
        if (s____001a4a24[0] != '\0') {
          pcVar10 = "\n};\n";
          cVar22 = s____001a4a24[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
      }
      else {
        iVar19 = 0;
        if (s___001a4a2c[0] != '\0') {
          pcVar10 = ",\n";
          cVar22 = s___001a4a2c[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
      }
      local_84 = local_84 + iVar19;
      uVar41 = ((int (*)())FUN_0000c8a0)(local_80,&local_88,&local_84);
      if ((int)(uVar41 >> 0x20) == 0) goto LAB_00014048;
LAB_000136f0:
      puVar40 = (uint *)((int)puVar40 + 1);
      puVar28 = puVar28 + 2;
    } while (puVar32 != puVar40);
  }
  if (puVar33 != (uint *)0x0) {
    _free(puVar33);
  }
  iVar7 = 0;
  if (s__001a45c0[0] != '\0') {
    pcVar10 = "\n";
    iVar7 = 0;
    cVar22 = s__001a45c0[0];
    do {
      pcVar10 = pcVar10 + 1;
      local_84[iVar7] = cVar22;
      iVar7 = iVar7 + 1;
      cVar22 = *pcVar10;
    } while (cVar22 != '\0');
  }
  local_84 = local_84 + iVar7;
LAB_0001376c:
  uVar34 = param_1[0xc];
  puVar32 = param_1 + param_1[0xd] * 2;
  if (0 < (int)uVar34) {
    uVar36 = 0;
    do {
      uVar38 = *puVar32 >> 0x10 & 0xf;
      if (uVar38 == 0) goto LAB_000140a0;
      uVar17 = *puVar32 >> 0x1d;
      if (uVar17 == 1) {
        iVar7 = 0;
        if (s_LONG_OUTPUT_res_001a4a3c[0] != '\0') {
          pcVar10 = "LONG OUTPUT res";
          cVar22 = s_LONG_OUTPUT_res_001a4a3c[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
LAB_0001389c:
        local_84 = local_84 + iVar7;
      }
      else {
        if (uVar17 == 2) {
          iVar7 = 0;
          if (s_SHORT_OUTPUT_res_001a4a4c[0] != '\0') {
            pcVar10 = "SHORT OUTPUT res";
            cVar22 = s_SHORT_OUTPUT_res_001a4a4c[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar7] = cVar22;
              iVar7 = iVar7 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          goto LAB_0001389c;
        }
        if (uVar17 == 0) {
          iVar7 = 0;
          if (s_OUTPUT_res_001a4a30[0] != '\0') {
            pcVar10 = "OUTPUT res";
            cVar22 = s_OUTPUT_res_001a4a30[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar7] = cVar22;
              iVar7 = iVar7 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          goto LAB_0001389c;
        }
      }
      iVar7 = ((int (*)())FUN_0000cdf0)(local_84,(uint)*(ushort *)((int)puVar32 + 6));
      local_84 = local_84 + iVar7;
      if (!bVar3) {
        uVar17 = *puVar32;
        in_r7 = (void *)(uVar17 >> 0x1d);
        in_r6 = (uint *)(uVar17 >> 0x1a & 7);
        local_84 = (undefined1 *)((int (*)())FUN_0000ce90)(local_84,uVar17 >> 0x18 & 3,0,in_r6,in_r7);
      }
      iVar7 = 0;
      if (s___001a4834[0] != '\0') {
        pcVar10 = " = ";
        cVar22 = s___001a4834[0];
        do {
          pcVar10 = pcVar10 + 1;
          local_84[iVar7] = cVar22;
          iVar7 = iVar7 + 1;
          cVar22 = *pcVar10;
        } while (cVar22 != '\0');
      }
      local_84 = local_84 + iVar7;
      switch(uVar38) {
      default:
        goto switchD_00013960_caseD_0;
      case 1:
        iVar26 = 0;
        if (s_result_position_001a4a60[0] != '\0') {
          pcVar10 = "result.position";
          cVar22 = s_result_position_001a4a60[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar26] = cVar22;
            iVar26 = iVar26 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 2:
        iVar26 = 0;
        if (s_result_fogcoord_001a4a70[0] != '\0') {
          pcVar10 = "result.fogcoord";
          cVar22 = s_result_fogcoord_001a4a70[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar26] = cVar22;
            iVar26 = iVar26 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 3:
        iVar26 = 0;
        if (s_result_pointsize_001a4a80[0] != '\0') {
          pcVar10 = "result.pointsize";
          cVar22 = s_result_pointsize_001a4a80[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar26] = cVar22;
            iVar26 = iVar26 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 4:
        iVar7 = 0;
        if (s_result_color_001a4a94[0] != '\0') {
          pcVar10 = "result.color";
          cVar22 = s_result_color_001a4a94[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar7;
        if ((uVar30 == 0x8620) || (uVar30 == 0x8b31)) {
          if ((*puVar32 & 1) == 0) {
            iVar26 = 0;
            if (s__front_primary_001a4aa4[0] != '\0') {
              pcVar10 = ".front.primary";
              cVar22 = s__front_primary_001a4aa4[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar26] = cVar22;
                iVar26 = iVar26 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
          }
          else {
            if ((*puVar32 & 1) != 1) goto switchD_00013960_caseD_0;
            iVar26 = 0;
            if (s__back_primary_001a4ab4[0] != '\0') {
              pcVar10 = ".back.primary";
              cVar22 = s__back_primary_001a4ab4[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar26] = cVar22;
                iVar26 = iVar26 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
          }
        }
        else {
          if (((uVar30 != 0x8804) && (uVar30 != 0x8b30)) ||
             (uVar38 = *puVar32, (uVar38 >> 1 & 7) < 2)) goto switchD_00013960_caseD_0;
          iVar7 = 0;
          if (s___001a4464[0] != '\0') {
            pcVar10 = "[";
            cVar22 = s___001a4464[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar7] = cVar22;
              iVar7 = iVar7 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
            uVar38 = *puVar32;
          }
          local_84 = local_84 + iVar7;
          iVar7 = ((int (*)())FUN_0000cdf0)(local_84,uVar38 >> 1 & 7);
          iVar26 = 0;
          local_84 = local_84 + iVar7;
          if (s___001a4468[0] != '\0') {
            pcVar10 = "]";
            cVar22 = s___001a4468[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar26] = cVar22;
              iVar26 = iVar26 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
        }
        break;
      case 5:
        iVar7 = 0;
        if (s_result_color_001a4a94[0] != '\0') {
          pcVar10 = "result.color";
          cVar22 = s_result_color_001a4a94[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar7;
        if ((uVar30 == 0x8620) || (uVar30 == 0x8b31)) {
          if ((*puVar32 & 1) == 0) {
            iVar26 = 0;
            if (s__front_secondary_001a4ac4[0] != '\0') {
              pcVar10 = ".front.secondary";
              cVar22 = s__front_secondary_001a4ac4[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar26] = cVar22;
                iVar26 = iVar26 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
          }
          else {
            if ((*puVar32 & 1) != 1) goto switchD_00013960_caseD_0;
            iVar26 = 0;
            if (s__back_secondary_001a4ad8[0] != '\0') {
              pcVar10 = ".back.secondary";
              cVar22 = s__back_secondary_001a4ad8[0];
              do {
                pcVar10 = pcVar10 + 1;
                local_84[iVar26] = cVar22;
                iVar26 = iVar26 + 1;
                cVar22 = *pcVar10;
              } while (cVar22 != '\0');
            }
          }
          break;
        }
        goto switchD_00013960_caseD_0;
      case 6:
        iVar7 = 0;
        if (s_result_texcoord__001a4ae8[0] != '\0') {
          pcVar10 = "result.texcoord[";
          cVar22 = s_result_texcoord__001a4ae8[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar7;
        iVar7 = ((int (*)())FUN_0000cdf0)(local_84,*puVar32 & 0x1f);
        iVar26 = 0;
        local_84 = local_84 + iVar7;
        if (s___001a4468[0] != '\0') {
          pcVar10 = "]";
          cVar22 = s___001a4468[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar26] = cVar22;
            iVar26 = iVar26 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 7:
        iVar26 = 0;
        if (s_result_depth_001a4afc[0] != '\0') {
          pcVar10 = "result.depth";
          cVar22 = s_result_depth_001a4afc[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar26] = cVar22;
            iVar26 = iVar26 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 8:
        iVar26 = 0;
        if (s_result_eyePosition_001a4b1c[0] != '\0') {
          pcVar10 = "result.eyePosition";
          cVar22 = s_result_eyePosition_001a4b1c[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar26] = cVar22;
            iVar26 = iVar26 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 9:
        iVar26 = 0;
        if (s_result_clipVertex_001a4b30[0] != '\0') {
          pcVar10 = "result.clipVertex";
          cVar22 = s_result_clipVertex_001a4b30[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar26] = cVar22;
            iVar26 = iVar26 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        break;
      case 10:
        iVar7 = 0;
        if (s_result_attrib__001a4b0c[0] != '\0') {
          pcVar10 = "result.attrib[";
          cVar22 = s_result_attrib__001a4b0c[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar7] = cVar22;
            iVar7 = iVar7 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar7;
        iVar7 = ((int (*)())FUN_0000cdf0)(local_84,*puVar32 & 0x1f);
        iVar26 = 0;
        local_84 = local_84 + iVar7;
        if (s___001a4468[0] != '\0') {
          pcVar10 = "]";
          cVar22 = s___001a4468[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar26] = cVar22;
            iVar26 = iVar26 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
      }
      local_84 = local_84 + iVar26;
switchD_00013960_caseD_0:
      iVar7 = 0;
      if (s___001a46fc[0] != '\0') {
        pcVar10 = ";\n";
        cVar22 = s___001a46fc[0];
        do {
          pcVar10 = pcVar10 + 1;
          local_84[iVar7] = cVar22;
          iVar7 = iVar7 + 1;
          cVar22 = *pcVar10;
        } while (cVar22 != '\0');
      }
      local_84 = local_84 + iVar7;
      iVar7 = ((int (*)())FUN_0000c8a0)(local_80,&local_88,&local_84);
      if (iVar7 == 0) goto LAB_00014048;
LAB_000140a0:
      uVar36 = uVar36 + 1;
      puVar32 = puVar32 + 2;
    } while (uVar34 != uVar36);
  }
  if ((uVar34 != 0) || (bVar3)) {
    iVar7 = 0;
    if (s__001a45c0[0] != '\0') {
      pcVar10 = "\n";
      iVar7 = 0;
      cVar22 = s__001a45c0[0];
      do {
        pcVar10 = pcVar10 + 1;
        local_84[iVar7] = cVar22;
        iVar7 = iVar7 + 1;
        cVar22 = *pcVar10;
      } while (cVar22 != '\0');
    }
    local_84 = local_84 + iVar7;
  }
  uVar34 = param_1[0x14];
  uVar30 = param_1[0x15];
  if (0 < (int)uVar34) {
    iVar7 = 0;
    sVar27 = 0;
    uVar36 = uVar34;
    do {
      if ((param_1[uVar30 * 2 + iVar7 * 2] >> 0x12 & 0xff) - 0x4b < 2) {
        sVar27 = sVar27 + 1;
      }
      iVar7 = iVar7 + (param_1[uVar30 * 2 + iVar7 * 2] >> 0x1d) + 2;
      uVar36 = uVar36 - 1;
    } while (uVar36 != 0);
    if (sVar27 == 0) {
      local_74 = (int *)0x0;
      local_78 = (uint *)0x0;
      puVar28 = (uint *)0x0;
      bVar4 = true;
    }
    else {
      local_74 = _malloc(sVar27 << 2);
      _memset(local_74,0,sVar27);
      local_78 = _malloc(sVar27 << 2);
      bVar2 = false;
      bVar4 = true;
      _memset(local_78,0,sVar27);
      uVar36 = 0;
      iVar7 = 0;
      puVar32 = (uint *)0x0;
      do {
        puVar28 = puVar32;
        if ((param_1[uVar30 * 2 + iVar7 * 2] >> 0x12 & 0xff) - 0x4b < 2) {
          uVar38 = param_1[uVar30 * 2 + iVar7 * 2] & 0x3ffff;
          puVar33 = (uint *)((param_1 + uVar30 * 2 + iVar7 * 2)[1] & 0x3ffff);
          if (bVar2) {
            if (*local_74 < (int)puVar33) {
              in_r8 = (uint *)0x0;
              piVar20 = local_74;
              puVar40 = puVar32;
              do {
                in_r8 = (uint *)((int)in_r8 + 1);
                puVar40 = (uint *)((int)puVar40 + -1);
                if (puVar40 == (uint *)0x0) goto LAB_00014230;
                piVar20 = piVar20 + 1;
              } while (*piVar20 < (int)puVar33);
            }
            else {
              in_r8 = (uint *)0x0;
            }
          }
          else {
            if (bVar4) {
LAB_00014230:
              puVar28 = (uint *)((int)puVar32 + 1);
              bVar2 = 0 < (int)puVar28;
              bVar4 = puVar28 == (uint *)0x0;
              local_74[(int)puVar32] = (int)puVar33;
              local_78[(int)puVar32] = uVar38;
              goto LAB_00014300;
            }
            in_r8 = (uint *)0x0;
          }
          in_r10 = (char *)local_74[(int)in_r8];
          if (puVar33 != (uint *)in_r10) {
            local_74[(int)in_r8] = (int)puVar33;
            puVar28 = (uint *)((int)puVar32 + 1);
            in_r6 = (uint *)((int)in_r8 + 1);
            pvVar31 = (void *)local_78[(int)in_r8];
            local_78[(int)in_r8] = uVar38;
            if ((int)in_r6 < (int)puVar32) {
              iVar26 = (int)puVar32 - (int)in_r6;
              puVar32 = (uint *)0x0;
              puVar21 = local_78 + (int)in_r6;
              puVar40 = (uint *)(local_74 + (int)in_r6);
              puVar33 = (uint *)in_r10;
              do {
                in_r7 = pvVar31;
                in_r10 = (char *)*puVar40;
                *puVar40 = (uint)puVar33;
                puVar32 = (uint *)((int)puVar32 + 1);
                puVar40 = puVar40 + 1;
                pvVar31 = (void *)*puVar21;
                *puVar21 = (uint)in_r7;
                puVar21 = puVar21 + 1;
                iVar26 = iVar26 + -1;
                puVar33 = (uint *)in_r10;
              } while (iVar26 != 0);
              in_r6 = (uint *)((int)in_r6 + (int)puVar32);
            }
            bVar2 = 0 < (int)puVar28;
            bVar4 = puVar28 == (uint *)0x0;
            local_74[(int)in_r6] = (int)in_r10;
            local_78[(int)in_r6] = (uint)pvVar31;
            in_r8 = puVar32;
          }
        }
LAB_00014300:
        uVar36 = uVar36 + 1;
        iVar7 = iVar7 + (param_1[uVar30 * 2 + iVar7 * 2] >> 0x1d) + 2;
        puVar32 = puVar28;
      } while (uVar34 != uVar36);
    }
    local_58 = local_80;
    local_5c = &local_84;
    local_54 = 0x19f634;
    puVar23 = (undefined1 *)0x0;
    local_64 = s_MUL_V_001df634;
    local_68 = 0x19f634;
    iVar7 = 0;
    uVar36 = 0;
    iVar26 = 1;
    do {
      puVar32 = param_1 + uVar30 * 2 + (int)puVar23 * 2;
      if (((param_1[uVar30 * 2 + (int)puVar23 * 2] & 0x3ffff) == 0) && (!bVar3)) {
        iVar19 = 0;
        if (s_main__001a4b44[0] != '\0') {
          pcVar10 = "main:\n";
          iVar19 = 0;
          cVar22 = s_main__001a4b44[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar19;
      }
      if ((bVar4) || ((int)puVar28 <= iVar7)) {
        uVar38 = *puVar32;
      }
      else {
        uVar38 = *puVar32;
        if ((uVar38 & 0x3ffff) == local_74[iVar7]) {
          if (0 < iVar26 + -1) {
            in_r8 = (uint *)0x19f634;
            iVar19 = 0;
            in_r10 = "  ";
            do {
              iVar11 = 0;
              if (s__001a4b4c[0] != '\0') {
                pcVar10 = "  ";
                iVar11 = 0;
                cVar22 = s__001a4b4c[0];
                do {
                  pcVar10 = pcVar10 + 1;
                  local_84[iVar11] = cVar22;
                  iVar11 = iVar11 + 1;
                  cVar22 = *pcVar10;
                } while (cVar22 != '\0');
              }
              iVar19 = iVar19 + 1;
              local_84 = local_84 + iVar11;
            } while (iVar26 + -1 != iVar19);
          }
          iVar19 = 0;
          if (s_label__001a4b50[0] != '\0') {
            pcVar10 = "label_";
            cVar22 = s_label__001a4b50[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          local_84 = local_84 + iVar19;
          iVar19 = ((int (*)())FUN_0000cdf0)(local_84,iVar7);
          iVar7 = iVar7 + 1;
          iVar11 = 0;
          if (s___001a4b58[0] != '\0') {
            pcVar10 = ":\n";
            cVar22 = s___001a4b58[0];
            do {
              pcVar10 = pcVar10 + 1;
              local_84[iVar11 + iVar19] = cVar22;
              iVar11 = iVar11 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          uVar38 = *puVar32;
          local_84 = local_84 + iVar11 + iVar19;
        }
      }
      puVar6 = local_84;
      uVar17 = uVar38 & 0x3fc0000;
      if ((((uVar17 == 0x1ac0000) || (uVar17 == 0x1600000)) || (uVar17 == 0x1640000)) ||
         ((uVar17 == 0x1680000 || (uVar17 == 0x16c0000)))) {
        iVar26 = iVar26 + -1;
      }
      uVar17 = puVar32[1];
      uVar29 = uVar38 >> 0x12 & 0xff;
      puVar13 = local_84;
      if (0 < iVar26) {
        in_r8 = (uint *)0x19f634;
        iVar19 = 0;
        in_r10 = "  ";
        do {
          iVar11 = 0;
          if (s__001a4b4c[0] != '\0') {
            pcVar10 = "  ";
            cVar22 = s__001a4b4c[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar11] = cVar22;
              iVar11 = iVar11 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          iVar19 = iVar19 + 1;
          puVar13 = puVar13 + iVar11;
        } while (iVar19 != iVar26);
      }
      iVar19 = 0;
      pcVar10 = *(char **)(local_64 + uVar29 * 4 + -0x6630);
      cVar22 = *pcVar10;
      if (cVar22 != '\0') {
        iVar19 = 0;
        do {
          puVar13[iVar19] = cVar22;
          iVar19 = iVar19 + 1;
          cVar22 = pcVar10[iVar19];
        } while (cVar22 != '\0');
      }
      puVar13 = puVar13 + iVar19;
      pdVar37 = (dword *)0x0;
      switch(uVar29) {
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
      case 0x50:
      case 0x51:
      case 0x5c:
      case 0x5d:
      case 0x5e:
      case 0x5f:
      case 99:
      case 100:
      case 0x65:
      case 0x66:
      case 0x6c:
      case 0x6f:
      case 0x70:
        uVar15 = ((int (*)())FUN_0000ca50)(puVar13,puVar32[1] >> 0x12 & 3);
        uVar16 = puVar32[1];
        iVar19 = ((int (*)())FUN_0000c930)(uVar15,uVar16 >> 0x16 & 1,uVar16 >> 0x15 & 1,uVar16 >> 0x14 & 1);
        if (!bVar3) {
          uVar16 = puVar32[1];
          iVar19 = ((int (*)())FUN_0000df50)(iVar19,uVar16 >> 0x1a & 3,uVar16 >> 0x1c & 1,uVar16 >> 0x17 & 7);
        }
        iVar11 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar10 = " ";
          cVar22 = s__001a4b5c[0];
          do {
            pcVar10 = pcVar10 + 1;
            *(char *)(iVar19 + iVar11) = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_60 = 0x19f634;
        iVar19 = ((int (*)())FUN_0000d380)(puVar32,iVar19 + iVar11,pvVar24,puVar25,1,puVar1);
        cVar22 = ((unsigned char *)0x00004ec0)[local_60];
        if (cVar22 != '\0') {
          pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
          iVar11 = 0;
          cVar9 = cVar22;
          do {
            *(char *)(iVar19 + iVar11) = cVar9;
            iVar11 = iVar11 + 1;
            cVar9 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar9 != '\0');
        }
        else {
          iVar11 = 0;
        }
        pdVar37 = (dword *)((int)&MACH_HEADER.magic + 2);
        in_r6 = local_70;
        in_r7 = pvVar24;
        in_r8 = puVar25;
        in_r10 = (char *)puVar1;
        puVar13 = (undefined1 *)
                  ((int (*)())FUN_0000e1f0)(puVar32,iVar19 + iVar11,local_6c,local_70,pvVar24,puVar25,2,puVar1,0)
        ;
        if (uVar38 >> 0x1d == 2) {
          if (cVar22 != '\0') {
            iVar19 = 0;
            pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
            do {
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
              pcVar10 = pcVar10 + 1;
            } while (cVar22 != '\0');
          }
          else {
            iVar19 = 0;
          }
          puVar13 = puVar13 + iVar19;
          goto LAB_000154ec;
        }
        break;
      case 0x1f:
      case 0x20:
      case 0x21:
      case 0x22:
      case 0x23:
      case 0x24:
      case 0x25:
      case 0x26:
      case 0x27:
      case 0x28:
      case 0x29:
      case 0x2a:
      case 0x2b:
      case 0x2c:
      case 0x2d:
      case 0x2e:
      case 0x2f:
      case 0x30:
      case 0x31:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
      case 0x36:
      case 0x37:
      case 0x38:
      case 0x39:
      case 0x3a:
      case 0x4e:
      case 0x52:
      case 0x6d:
        uVar15 = ((int (*)())FUN_0000ca50)(puVar13,puVar32[1] >> 0x12 & 3);
        uVar38 = puVar32[1];
        iVar19 = ((int (*)())FUN_0000c930)(uVar15,uVar38 >> 0x16 & 1,uVar38 >> 0x15 & 1,uVar38 >> 0x14 & 1);
        if (!bVar3) {
          uVar38 = puVar32[1];
          iVar19 = ((int (*)())FUN_0000df50)(iVar19,uVar38 >> 0x1a & 3,uVar38 >> 0x1c & 1,uVar38 >> 0x17 & 7);
        }
        iVar11 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar10 = " ";
          cVar22 = s__001a4b5c[0];
          do {
            pcVar10 = pcVar10 + 1;
            *(char *)(iVar19 + iVar11) = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_60 = 0x19f634;
        iVar19 = ((int (*)())FUN_0000d380)(puVar32,iVar19 + iVar11,pvVar24,puVar25,1,puVar1);
        cVar22 = ((unsigned char *)0x00004ec0)[local_60];
        if (cVar22 != '\0') {
          pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
          iVar11 = 0;
          cVar9 = cVar22;
          do {
            *(char *)(iVar19 + iVar11) = cVar9;
            iVar11 = iVar11 + 1;
            cVar9 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar9 != '\0');
        }
        else {
          iVar11 = 0;
        }
        iVar19 = ((int (*)())FUN_0000e1f0)(puVar32,iVar19 + iVar11,local_6c,local_70,pvVar24,puVar25,2,puVar1,0);
        if (cVar22 != '\0') {
          iVar11 = 0;
          pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
          do {
            *(char *)(iVar19 + iVar11) = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar22 != '\0');
        }
        else {
          iVar11 = 0;
        }
        puVar13 = (undefined1 *)(iVar19 + iVar11);
LAB_000154ec:
        pdVar37 = (dword *)((int)&MACH_HEADER.magic + 3);
        in_r6 = local_70;
        in_r7 = pvVar24;
        in_r8 = puVar25;
        in_r10 = (char *)puVar1;
        puVar13 = (undefined1 *)
                  ((int (*)())FUN_0000e1f0)(puVar32,puVar13,local_6c,local_70,pvVar24,puVar25,3,puVar1,0);
        break;
      case 0x3b:
      case 0x3c:
      case 0x3d:
      case 0x3e:
      case 0x3f:
      case 0x40:
      case 0x53:
      case 0x67:
      case 0x68:
        uVar15 = ((int (*)())FUN_0000ca50)(puVar13,puVar32[1] >> 0x12 & 3);
        uVar38 = puVar32[1];
        iVar19 = ((int (*)())FUN_0000c930)(uVar15,uVar38 >> 0x16 & 1,uVar38 >> 0x15 & 1,uVar38 >> 0x14 & 1);
        if (!bVar3) {
          uVar38 = puVar32[1];
          iVar19 = ((int (*)())FUN_0000df50)(iVar19,uVar38 >> 0x1a & 3,uVar38 >> 0x1c & 1,uVar38 >> 0x17 & 7);
        }
        iVar11 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar10 = " ";
          cVar22 = s__001a4b5c[0];
          do {
            pcVar10 = pcVar10 + 1;
            *(char *)(iVar19 + iVar11) = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_60 = 0x19f634;
        iVar19 = ((int (*)())FUN_0000d380)(puVar32,iVar19 + iVar11,pvVar24,puVar25,1,puVar1);
        cVar22 = ((unsigned char *)0x00004ec0)[local_60];
        bVar2 = cVar22 != '\0';
        if (bVar2) {
          pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
          iVar11 = 0;
          cVar9 = cVar22;
          do {
            *(char *)(iVar19 + iVar11) = cVar9;
            iVar11 = iVar11 + 1;
            cVar9 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar9 != '\0');
        }
        else {
          iVar11 = 0;
        }
        iVar19 = ((int (*)())FUN_0000e1f0)(puVar32,iVar19 + iVar11,local_6c,local_70,pvVar24,puVar25,2,puVar1,0);
        if (bVar2) {
          iVar11 = 0;
          pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
          cVar9 = cVar22;
          do {
            *(char *)(iVar19 + iVar11) = cVar9;
            iVar11 = iVar11 + 1;
            cVar9 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar9 != '\0');
        }
        else {
          iVar11 = 0;
        }
        iVar19 = ((int (*)())FUN_0000e1f0)(puVar32,iVar19 + iVar11,local_6c,local_70,pvVar24,puVar25,3,puVar1,0);
        if (bVar2) {
          iVar11 = 0;
          pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
          do {
            *(char *)(iVar19 + iVar11) = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar22 != '\0');
        }
        else {
          iVar11 = 0;
        }
        pdVar37 = &MACH_HEADER.cputype;
        in_r6 = local_70;
        in_r7 = pvVar24;
        in_r8 = puVar25;
        in_r10 = (char *)puVar1;
        puVar13 = (undefined1 *)
                  ((int (*)())FUN_0000e1f0)(puVar32,iVar19 + iVar11,local_6c,local_70,pvVar24,puVar25,4,puVar1,0)
        ;
        break;
      case 0x41:
        uVar38 = puVar32[1];
        iVar19 = ((int (*)())FUN_0000c930)(puVar13,uVar38 >> 0x16 & 1,uVar38 >> 0x15 & 1,uVar38 >> 0x14 & 1);
        if (!bVar3) {
          uVar38 = puVar32[1];
          iVar19 = ((int (*)())FUN_0000df50)(iVar19,uVar38 >> 0x1a & 3,uVar38 >> 0x1c & 1,uVar38 >> 0x17 & 7);
        }
        iVar11 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar10 = " ";
          cVar22 = s__001a4b5c[0];
          do {
            pcVar10 = pcVar10 + 1;
            *(char *)(iVar19 + iVar11) = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        iVar19 = ((int (*)())FUN_0000d380)(puVar32,iVar19 + iVar11,pvVar24,puVar25,1,puVar1);
        iVar11 = 0;
        if (s___001a44f4[0] != '\0') {
          pcVar10 = ", ";
          cVar22 = s___001a44f4[0];
          do {
            pcVar10 = pcVar10 + 1;
            *(char *)(iVar19 + iVar11) = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        pdVar37 = (dword *)((int)&MACH_HEADER.magic + 3);
        in_r6 = local_70;
        in_r7 = pvVar24;
        in_r8 = puVar25;
        in_r10 = (char *)puVar1;
        puVar13 = (undefined1 *)
                  ((int (*)())FUN_0000e1f0)(puVar32,iVar19 + iVar11,local_6c,local_70,pvVar24,puVar25,2,puVar1,1)
        ;
        break;
      case 0x42:
      case 0x43:
        uVar38 = puVar32[1];
        iVar19 = ((int (*)())FUN_0000c930)(puVar13,uVar38 >> 0x16 & 1,uVar38 >> 0x15 & 1,uVar38 >> 0x14 & 1);
        if (!bVar3) {
          uVar38 = puVar32[1];
          iVar19 = ((int (*)())FUN_0000df50)(iVar19,uVar38 >> 0x1a & 3,uVar38 >> 0x1c & 1,uVar38 >> 0x17 & 7);
        }
        iVar11 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar10 = " ";
          cVar22 = s__001a4b5c[0];
          do {
            pcVar10 = pcVar10 + 1;
            *(char *)(iVar19 + iVar11) = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_60 = 0x19f634;
        iVar19 = ((int (*)())FUN_0000d380)(puVar32,iVar19 + iVar11,pvVar24,puVar25,1,puVar1);
        cVar22 = ((unsigned char *)0x00004ec0)[local_60];
        if (cVar22 != '\0') {
          pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
          iVar11 = 0;
          cVar9 = cVar22;
          do {
            *(char *)(iVar19 + iVar11) = cVar9;
            iVar11 = iVar11 + 1;
            cVar9 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar9 != '\0');
        }
        else {
          iVar11 = 0;
        }
        iVar19 = ((int (*)())FUN_0000e1f0)(puVar32,iVar19 + iVar11,local_6c,local_70,pvVar24,puVar25,2,puVar1,0);
        if (cVar22 != '\0') {
          iVar11 = 0;
          pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
          do {
            *(char *)(iVar19 + iVar11) = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar22 != '\0');
        }
        else {
          iVar11 = 0;
        }
        pdVar37 = (dword *)((int)puVar1 + 3);
        in_r6 = local_70;
        in_r7 = pvVar24;
        in_r8 = puVar25;
        in_r10 = (char *)puVar1;
        puVar13 = (undefined1 *)
                  ((int (*)())FUN_0000f250)(puVar32,iVar19 + iVar11,local_6c,local_70,pvVar24,puVar25,3,puVar1);
        break;
      case 0x44:
      case 0x45:
      case 0x46:
      case 0x47:
        uVar38 = puVar32[1];
        iVar19 = ((int (*)())FUN_0000c930)(puVar13,uVar38 >> 0x16 & 1,uVar38 >> 0x15 & 1,uVar38 >> 0x14 & 1);
        if (!bVar3) {
          uVar38 = puVar32[1];
          iVar19 = ((int (*)())FUN_0000df50)(iVar19,uVar38 >> 0x1a & 3,uVar38 >> 0x1c & 1,uVar38 >> 0x17 & 7);
        }
        iVar11 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar10 = " ";
          cVar22 = s__001a4b5c[0];
          do {
            pcVar10 = pcVar10 + 1;
            *(char *)(iVar19 + iVar11) = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_60 = 0x19f634;
        iVar19 = ((int (*)())FUN_0000d380)(puVar32,iVar19 + iVar11,pvVar24,puVar25,1,puVar1);
        cVar22 = ((unsigned char *)0x00004ec0)[local_60];
        bVar2 = cVar22 != '\0';
        if (bVar2) {
          pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
          iVar11 = 0;
          cVar9 = cVar22;
          do {
            *(char *)(iVar19 + iVar11) = cVar9;
            iVar11 = iVar11 + 1;
            cVar9 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar9 != '\0');
        }
        else {
          iVar11 = 0;
        }
        iVar19 = ((int (*)())FUN_0000e1f0)(puVar32,iVar19 + iVar11,local_6c,local_70,pvVar24,puVar25,2,puVar1,0);
        if (bVar2) {
          iVar11 = 0;
          pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
          cVar9 = cVar22;
          do {
            *(char *)(iVar19 + iVar11) = cVar9;
            iVar11 = iVar11 + 1;
            cVar9 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar9 != '\0');
        }
        else {
          iVar11 = 0;
        }
        in_r6 = local_70;
        in_r7 = pvVar24;
        in_r8 = puVar25;
        in_r10 = (char *)puVar1;
        puVar13 = (undefined1 *)
                  ((int (*)())FUN_0000f250)(puVar32,iVar19 + iVar11,local_6c,local_70,pvVar24,puVar25,3,puVar1);
        if (bVar3) {
          pdVar37 = (dword *)((int)&MACH_HEADER.magic + 3);
        }
        else {
          if (bVar2) {
            iVar19 = 0;
            pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
            do {
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
              pcVar10 = pcVar10 + 1;
            } while (cVar22 != '\0');
          }
          else {
            iVar19 = 0;
          }
          pdVar37 = puVar1 + 1;
          in_r6 = local_70;
          in_r7 = pvVar24;
          in_r8 = puVar25;
          in_r10 = (char *)puVar1;
          puVar13 = (undefined1 *)
                    ((int (*)())FUN_0000e1f0)(puVar32,puVar13 + iVar19,local_6c,local_70,pvVar24,puVar25,pdVar37,
                                 puVar1,0);
        }
        break;
      case 0x48:
      case 0x49:
      case 0x4a:
        if (!bVar3) {
          uVar38 = puVar32[1];
          puVar13 = (undefined1 *)
                    ((int (*)())FUN_0000df50)(puVar13,uVar38 >> 0x1a & 3,uVar38 >> 0x1c & 1,uVar38 >> 0x17 & 7);
        }
        iVar19 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar10 = " ";
          iVar19 = 0;
          cVar22 = s__001a4b5c[0];
          do {
            pcVar10 = pcVar10 + 1;
            puVar13[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        puVar13 = puVar13 + iVar19;
        puVar33 = puVar32 + 2;
        if ((puVar32[2] & 0xe0000) == 0x80000) {
          iVar19 = 0;
          if (s_adr_001a44f0[0] != '\0') {
            pcVar10 = "adr";
            iVar19 = 0;
            cVar22 = s_adr_001a44f0[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          iVar11 = ((int (*)())FUN_0000cdf0)(puVar13 + iVar19,(uint)*(ushort *)((int)puVar32 + 0xe));
          puVar13 = puVar13 + iVar19 + iVar11;
        }
        uVar38 = *puVar33;
        if ((uVar38 & 0x1e000) != 0x1e000) {
          iVar19 = 0;
          if (s___001a448c[0] != '\0') {
            pcVar10 = ".";
            cVar22 = s___001a448c[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
            uVar38 = *puVar33;
          }
          puVar13 = puVar13 + iVar19;
          if (bVar3) {
            if ((uVar38 & 0x2000) != 0) {
              iVar19 = 0;
              if (s_x_001a4490[0] != '\0') {
                pcVar10 = "x";
                cVar22 = s_x_001a4490[0];
                do {
                  pcVar10 = pcVar10 + 1;
                  puVar13[iVar19] = cVar22;
                  iVar19 = iVar19 + 1;
                  cVar22 = *pcVar10;
                } while (cVar22 != '\0');
                uVar38 = *puVar33;
              }
              puVar13 = puVar13 + iVar19;
            }
            if ((uVar38 & 0x4000) != 0) {
              iVar19 = 0;
              if (s_y_001a4494[0] != '\0') {
                pcVar10 = "y";
                cVar22 = s_y_001a4494[0];
                do {
                  pcVar10 = pcVar10 + 1;
                  puVar13[iVar19] = cVar22;
                  iVar19 = iVar19 + 1;
                  cVar22 = *pcVar10;
                } while (cVar22 != '\0');
                uVar38 = *puVar33;
              }
              puVar13 = puVar13 + iVar19;
            }
            if ((uVar38 & 0x8000) != 0) {
              iVar19 = 0;
              if (s_z_001a4498[0] != '\0') {
                pcVar10 = "z";
                cVar22 = s_z_001a4498[0];
                do {
                  pcVar10 = pcVar10 + 1;
                  puVar13[iVar19] = cVar22;
                  iVar19 = iVar19 + 1;
                  cVar22 = *pcVar10;
                } while (cVar22 != '\0');
                uVar38 = *puVar33;
              }
              puVar13 = puVar13 + iVar19;
            }
            if ((uVar38 & 0x10000) != 0) {
              iVar19 = 0;
              if (s_w_001a449c[0] != '\0') {
                pcVar10 = "w";
                cVar22 = s_w_001a449c[0];
                do {
                  pcVar10 = pcVar10 + 1;
                  puVar13[iVar19] = cVar22;
                  iVar19 = iVar19 + 1;
                  cVar22 = *pcVar10;
                } while (cVar22 != '\0');
              }
              goto LAB_00016158;
            }
          }
          else {
            if ((uVar38 & 0x2000) != 0) {
              iVar19 = 0;
              if (s_x_001a4490[0] != '\0') {
                pcVar10 = "x";
                cVar22 = s_x_001a4490[0];
                do {
                  pcVar10 = pcVar10 + 1;
                  puVar13[iVar19] = cVar22;
                  iVar19 = iVar19 + 1;
                  cVar22 = *pcVar10;
                } while (cVar22 != '\0');
                uVar38 = *puVar33;
              }
              puVar13 = puVar13 + iVar19;
            }
            if (((uVar38 & 0xc00) != 0) && ((uVar38 & 0x4000) != 0)) {
              iVar19 = 0;
              if (s_y_001a4494[0] != '\0') {
                pcVar10 = "y";
                cVar22 = s_y_001a4494[0];
                do {
                  pcVar10 = pcVar10 + 1;
                  puVar13[iVar19] = cVar22;
                  iVar19 = iVar19 + 1;
                  cVar22 = *pcVar10;
                } while (cVar22 != '\0');
                uVar38 = *puVar33;
              }
              puVar13 = puVar13 + iVar19;
            }
            if ((1 < (uVar38 >> 10 & 3)) && ((uVar38 & 0x8000) != 0)) {
              iVar19 = 0;
              if (s_z_001a4498[0] != '\0') {
                pcVar10 = "z";
                cVar22 = s_z_001a4498[0];
                do {
                  pcVar10 = pcVar10 + 1;
                  puVar13[iVar19] = cVar22;
                  iVar19 = iVar19 + 1;
                  cVar22 = *pcVar10;
                } while (cVar22 != '\0');
                uVar38 = *puVar33;
              }
              puVar13 = puVar13 + iVar19;
            }
            if ((2 < (uVar38 >> 10 & 3)) && ((uVar38 & 0x10000) != 0)) {
              iVar19 = 0;
              if (s_w_001a449c[0] != '\0') {
                pcVar10 = "w";
                cVar22 = s_w_001a449c[0];
                do {
                  pcVar10 = pcVar10 + 1;
                  puVar13[iVar19] = cVar22;
                  iVar19 = iVar19 + 1;
                  cVar22 = *pcVar10;
                } while (cVar22 != '\0');
              }
LAB_00016158:
              puVar13 = puVar13 + iVar19;
            }
          }
        }
        iVar19 = 0;
        if (s___001a44f4[0] != '\0') {
          pcVar10 = ", ";
          cVar22 = s___001a44f4[0];
          do {
            pcVar10 = pcVar10 + 1;
            puVar13[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
LAB_000161a0:
        puVar13 = puVar13 + iVar19;
        goto LAB_00014cb8;
      case 0x4b:
      case 0x4c:
        pcVar14 = (char *)0x0;
        if (s__001a4b5c[0] != '\0') {
          pcVar12 = " ";
          pcVar14 = (char *)0x0;
          cVar22 = s__001a4b5c[0];
          do {
            pcVar12 = pcVar12 + 1;
            puVar13[(int)pcVar14] = cVar22;
            pcVar14 = pcVar14 + 1;
            cVar22 = *pcVar12;
            pcVar10 = pcVar14;
          } while (cVar22 != '\0');
        }
        iVar19 = -1;
        if (local_74 != (int *)0x0) {
          iVar19 = 0;
          pcVar10 = (char *)(puVar32[1] & 0x3ffff);
          pcVar12 = (char *)*local_74;
          while (pcVar10 != pcVar12) {
            iVar19 = iVar19 + 1;
            pcVar12 = (char *)local_74[iVar19];
          }
        }
        iVar19 = FUN_001a32d0(puVar13 + (int)pcVar14,"label_%i",iVar19,in_r6,in_r7,in_r8,pcVar10,
                              in_r10);
        puVar13 = puVar13 + (int)pcVar14 + iVar19;
        if (uVar29 != 0x4b) goto switchD_000146d8_caseD_4d;
        puVar33 = puVar32 + 2;
        switch(puVar32[2] >> 0x1c & 7) {
        case 0:
          iVar19 = 0;
          if (s__TR_001a44a0[0] != '\0') {
            pcVar10 = " (TR";
            cVar22 = s__TR_001a44a0[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 1:
          iVar19 = 0;
          if (s__EQ_001a44a8[0] != '\0') {
            pcVar10 = " (EQ";
            cVar22 = s__EQ_001a44a8[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 2:
          iVar19 = 0;
          if (s__GE_001a44b0[0] != '\0') {
            pcVar10 = " (GE";
            cVar22 = s__GE_001a44b0[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 3:
          iVar19 = 0;
          if (s__GT_001a44b8[0] != '\0') {
            pcVar10 = " (GT";
            cVar22 = s__GT_001a44b8[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 4:
          iVar19 = 0;
          if (s__LE_001a44c0[0] != '\0') {
            pcVar10 = " (LE";
            cVar22 = s__LE_001a44c0[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 5:
          iVar19 = 0;
          if (s__LT_001a44c8[0] != '\0') {
            pcVar10 = " (LT";
            cVar22 = s__LT_001a44c8[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 6:
          iVar19 = 0;
          if (s__NE_001a44d0[0] != '\0') {
            pcVar10 = " (NE";
            cVar22 = s__NE_001a44d0[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 7:
          iVar19 = 0;
          if (s__FL_001a44d8[0] != '\0') {
            pcVar10 = " (FL";
            cVar22 = s__FL_001a44d8[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        default:
          goto switchD_00014df8_default;
        }
        puVar13 = puVar13 + iVar19;
switchD_00014df8_default:
        if ((int)*puVar33 < 0) {
          *puVar13 = 0x31;
          puVar13 = puVar13 + 1;
        }
        pdVar37 = (dword *)((int)&MACH_HEADER.magic + 1);
        *puVar13 = 0x2e;
        puVar13[1] = (((byte)(*puVar33 >> 0x1a) & 3) + 1 & 3) + 0x77;
        puVar13[2] = (*(char *)puVar33 + 1U & 3) + 0x77;
        puVar13[3] = (((byte)(*puVar33 >> 0x16) & 3) + 1 & 3) + 0x77;
        uVar38 = *puVar33;
        puVar13[5] = 0x29;
        puVar13[4] = (((byte)(uVar38 >> 0x14) & 3) + 1 & 3) + 0x77;
        puVar13 = puVar13 + 6;
        break;
      case 0x4d:
      case 0x54:
      case 0x59:
      case 0x5a:
      case 0x5b:
      case 0x69:
      case 0x6b:
      case 0x6e:
switchD_000146d8_caseD_4d:
        pdVar37 = (dword *)((int)&MACH_HEADER.magic + 1);
        break;
      case 0x4f:
        iVar19 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar10 = " ";
          cVar22 = s__001a4b5c[0];
          do {
            pcVar10 = pcVar10 + 1;
            puVar13[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        goto LAB_00014cb4;
      case 0x55:
        iVar26 = iVar26 + 1;
        if (!bVar3) {
          uVar38 = puVar32[1];
          puVar13 = (undefined1 *)
                    ((int (*)())FUN_0000df50)(puVar13,uVar38 >> 0x1a & 3,uVar38 >> 0x1c & 1,uVar38 >> 0x17 & 7);
          iVar19 = 0;
          if (s__001a4b5c[0] != '\0') {
            pcVar10 = " ";
            cVar22 = s__001a4b5c[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          goto LAB_000161a0;
        }
        puVar33 = puVar32 + 2;
        switch(puVar32[2] >> 0x1c & 7) {
        case 0:
          iVar19 = 0;
          if (s_TR_001a4b60[0] != '\0') {
            pcVar10 = " TR";
            cVar22 = s_TR_001a4b60[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 1:
          iVar19 = 0;
          if (s_EQ_001a4b64[0] != '\0') {
            pcVar10 = " EQ";
            cVar22 = s_EQ_001a4b64[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 2:
          iVar19 = 0;
          if (s_GE_001a4b68[0] != '\0') {
            pcVar10 = " GE";
            cVar22 = s_GE_001a4b68[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 3:
          iVar19 = 0;
          if (s_GT_001a4b6c[0] != '\0') {
            pcVar10 = " GT";
            cVar22 = s_GT_001a4b6c[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 4:
          iVar19 = 0;
          if (s_LE_001a4b70[0] != '\0') {
            pcVar10 = " LE";
            cVar22 = s_LE_001a4b70[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 5:
          iVar19 = 0;
          if (s_LT_001a4b74[0] != '\0') {
            pcVar10 = " LT";
            cVar22 = s_LT_001a4b74[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 6:
          iVar19 = 0;
          if (s_NE_001a4b78[0] != '\0') {
            pcVar10 = " NE";
            cVar22 = s_NE_001a4b78[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        case 7:
          iVar19 = 0;
          if (s_FL_001a4b7c[0] != '\0') {
            pcVar10 = " FL";
            cVar22 = s_FL_001a4b7c[0];
            do {
              pcVar10 = pcVar10 + 1;
              puVar13[iVar19] = cVar22;
              iVar19 = iVar19 + 1;
              cVar22 = *pcVar10;
            } while (cVar22 != '\0');
          }
          break;
        default:
          goto switchD_00014940_default;
        }
        puVar13 = puVar13 + iVar19;
switchD_00014940_default:
        if ((int)*puVar33 < 0) {
          *puVar13 = 0x31;
          puVar13 = puVar13 + 1;
        }
        pdVar37 = (dword *)((int)&MACH_HEADER.magic + 1);
        *puVar13 = 0x2e;
        puVar13[1] = (((byte)(*puVar33 >> 0x1a) & 3) + 1 & 3) + 0x77;
        puVar13[2] = (*(char *)puVar33 + 1U & 3) + 0x77;
        puVar13[3] = (((byte)(*puVar33 >> 0x16) & 3) + 1 & 3) + 0x77;
        puVar13[4] = (((byte)(*puVar33 >> 0x14) & 3) + 1 & 3) + 0x77;
        puVar13 = puVar13 + 5;
        break;
      case 0x56:
      case 0x57:
        iVar26 = iVar26 + 1;
        iVar19 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar10 = " ";
          cVar22 = s__001a4b5c[0];
          do {
            pcVar10 = pcVar10 + 1;
            puVar13[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        goto LAB_00014cb4;
      case 0x58:
      case 0x6a:
        iVar26 = iVar26 + 1;
        pdVar37 = (dword *)((int)&MACH_HEADER.magic + 1);
        break;
      case 0x60:
      case 0x61:
        iVar19 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar10 = " ";
          cVar22 = s__001a4b5c[0];
          do {
            pcVar10 = pcVar10 + 1;
            puVar13[iVar19] = cVar22;
            iVar19 = iVar19 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
LAB_00014cb4:
        puVar13 = puVar13 + iVar19;
LAB_00014cb8:
        pdVar37 = (dword *)((int)&MACH_HEADER.magic + 2);
        in_r6 = local_70;
        in_r7 = pvVar24;
        in_r8 = puVar25;
        in_r10 = (char *)puVar1;
        puVar13 = (undefined1 *)
                  ((int (*)())FUN_0000e1f0)(puVar32,puVar13,local_6c,local_70,pvVar24,puVar25,2,puVar1,0);
        break;
      case 0x62:
        uVar38 = puVar32[1];
        iVar19 = ((int (*)())FUN_0000c930)(puVar13,uVar38 >> 0x16 & 1,uVar38 >> 0x15 & 1,uVar38 >> 0x14 & 1);
        if (!bVar3) {
          uVar38 = puVar32[1];
          iVar19 = ((int (*)())FUN_0000df50)(iVar19,uVar38 >> 0x1a & 3,uVar38 >> 0x1c & 1,uVar38 >> 0x17 & 7);
        }
        iVar11 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar10 = " ";
          cVar22 = s__001a4b5c[0];
          do {
            pcVar10 = pcVar10 + 1;
            *(char *)(iVar19 + iVar11) = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_60 = 0x19f634;
        iVar19 = ((int (*)())FUN_0000d380)(puVar32,iVar19 + iVar11,pvVar24,puVar25,1,puVar1);
        cVar22 = ((unsigned char *)0x00004ec0)[local_60];
        bVar2 = cVar22 != '\0';
        if (bVar2) {
          pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
          iVar11 = 0;
          cVar9 = cVar22;
          do {
            *(char *)(iVar19 + iVar11) = cVar9;
            iVar11 = iVar11 + 1;
            cVar9 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar9 != '\0');
        }
        else {
          iVar11 = 0;
        }
        iVar19 = ((int (*)())FUN_0000e1f0)(puVar32,iVar19 + iVar11,local_6c,local_70,pvVar24,puVar25,2,puVar1,0);
        if (bVar2) {
          iVar11 = 0;
          pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
          cVar9 = cVar22;
          do {
            *(char *)(iVar19 + iVar11) = cVar9;
            iVar11 = iVar11 + 1;
            cVar9 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar9 != '\0');
        }
        else {
          iVar11 = 0;
        }
        iVar19 = ((int (*)())FUN_0000e1f0)(puVar32,iVar19 + iVar11,local_6c,local_70,pvVar24,puVar25,3,puVar1,0);
        if (bVar2) {
          iVar11 = 0;
          pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
          cVar9 = cVar22;
          do {
            *(char *)(iVar19 + iVar11) = cVar9;
            iVar11 = iVar11 + 1;
            cVar9 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar9 != '\0');
        }
        else {
          iVar11 = 0;
        }
        iVar19 = ((int (*)())FUN_0000e1f0)(puVar32,iVar19 + iVar11,local_6c,local_70,pvVar24,puVar25,4,puVar1,0);
        if (bVar2) {
          iVar11 = 0;
          pcVar10 = ((unsigned char *)0x00004ec1) + local_60;
          do {
            *(char *)(iVar19 + iVar11) = cVar22;
            iVar11 = iVar11 + 1;
            cVar22 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar22 != '\0');
        }
        else {
          iVar11 = 0;
        }
        pdVar37 = (dword *)((int)puVar1 + 5);
        in_r6 = local_70;
        in_r7 = pvVar24;
        in_r8 = puVar25;
        in_r10 = (char *)puVar1;
        puVar13 = (undefined1 *)
                  ((int (*)())FUN_0000f250)(puVar32,iVar19 + iVar11,local_6c,local_70,pvVar24,puVar25,5,puVar1);
      }
      iVar19 = 0;
      cVar22 = ((unsigned char *)0x00005558)[local_68];
      if (cVar22 != '\0') {
        pcVar10 = ((unsigned char *)0x00005559) + local_68;
        iVar19 = 0;
        do {
          puVar13[iVar19] = cVar22;
          iVar19 = iVar19 + 1;
          cVar22 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar22 != '\0');
      }
      puVar13 = puVar13 + iVar19;
      if ((!bVar3) && (uVar29 - 0x4b < 0x21)) {
        switch(uVar29) {
        case 0x4b:
        case 0x4c:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
        case 0x5a:
        case 0x5b:
        case 0x69:
        case 0x6a:
        case 0x6b:
          iVar19 = FUN_001a32d0(puVar13,"    # Target: %d",uVar17 & 0x3ffff,in_r6,in_r7,in_r8,
                                (uVar29 - 0x4b) * 4,in_r10);
          puVar13 = puVar13 + iVar19;
        }
      }
      iVar19 = 0;
      cVar22 = ((unsigned char *)0x00004f8c)[local_54];
      if (cVar22 != '\0') {
        pcVar10 = ((unsigned char *)0x00004f8d) + local_54;
        iVar19 = 0;
        do {
          puVar13[iVar19] = cVar22;
          iVar19 = iVar19 + 1;
          cVar22 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar22 != '\0');
      }
      local_84 = puVar13 + (int)(local_84 + (iVar19 - (int)puVar6));
      iVar19 = ((int (*)())FUN_0000c8a0)(local_58,&local_88,local_5c);
      if (iVar19 == 0) {
        if (local_6c != (void *)0x0) {
          _free(local_6c);
        }
        if (local_70 != (uint *)0x0) {
          _free(local_70);
        }
        if (pvVar24 != (void *)0x0) {
          _free(pvVar24);
        }
        if (puVar25 != (uint *)0x0) {
          _free(puVar25);
        }
        if (bVar4) goto LAB_00016630;
        _free(local_74);
        puVar25 = local_78;
        goto LAB_000163f0;
      }
      uVar36 = uVar36 + 1;
      puVar23 = (undefined1 *)((int)pdVar37 + (int)(puVar23 + 1));
    } while (uVar34 != uVar36);
    if (!bVar4) {
      if ((iVar7 < (int)puVar28) && (uVar34 + 1 == local_74[iVar7])) {
        iVar26 = 0;
        if (s_label__001a4ba4[0] != '\0') {
          pcVar10 = "  label_";
          cVar22 = s_label__001a4ba4[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar26] = cVar22;
            iVar26 = iVar26 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar26;
        iVar7 = ((int (*)())FUN_0000cdf0)(local_84,iVar7);
        iVar26 = 0;
        if (s___001a4b58[0] != '\0') {
          pcVar10 = ":\n";
          cVar22 = s___001a4b58[0];
          do {
            pcVar10 = pcVar10 + 1;
            local_84[iVar26 + iVar7] = cVar22;
            iVar26 = iVar26 + 1;
            cVar22 = *pcVar10;
          } while (cVar22 != '\0');
        }
        local_84 = local_84 + iVar26 + iVar7;
      }
      _free(local_74);
      _free(local_78);
    }
  }
  iVar7 = 0;
  if (s_END_001a4bb0[0] != '\0') {
    pcVar10 = "END\n";
    iVar7 = 0;
    cVar22 = s_END_001a4bb0[0];
    do {
      pcVar10 = pcVar10 + 1;
      local_84[iVar7] = cVar22;
      iVar7 = iVar7 + 1;
      cVar22 = *pcVar10;
    } while (cVar22 != '\0');
  }
  local_84[iVar7] = 0;
  local_84 = local_84 + iVar7 + 1;
  if (local_6c != (void *)0x0) {
    _free(local_6c);
  }
  if (local_70 != (uint *)0x0) {
    _free(local_70);
  }
  if (pvVar24 != (void *)0x0) {
    _free(pvVar24);
  }
  if (puVar25 != (uint *)0x0) {
    _free(puVar25);
  }
  if ((int)local_84 - (int)local_88 < 1) {
    _free(local_88);
    local_88 = (void *)0x0;
  }
  else {
    local_88 = _realloc(local_88,(int)local_84 - (int)local_88);
  }
  return local_88;
LAB_00014048:
  if (local_6c != (void *)0x0) {
    _free(local_6c);
  }
joined_r0x000112bc:
  if (local_70 != (uint *)0x0) {
    _free(local_70);
  }
LAB_00014070:
  if (pvVar24 != (void *)0x0) {
    _free(pvVar24);
  }
  if (puVar25 != (uint *)0x0) {
    _free(puVar25);
  }
LAB_00016630:
  _free(local_88);
  return (void *)0x0;
}

/* FUN_00016670 @ 0x16670 (2312 bytes) */
void FUN_00016670(int param_1,float *param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6,int param_7,int param_8,double fparam_1,double fparam_2)
{
  bool bVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 uVar11;
  undefined4 extraout_r4_05;
  float *pfVar12;
  int iVar13;
  float *pfVar14;
  undefined4 uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  float fVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  float *pfVar25;
  double dVar26;
  double dVar27;
  int iStack00000020;
  int iStack00000024;
  int iStack00000030;
  float fStack_188;
  float fStack_184;
  float fStack_180;
  float fStack_17c;
  undefined1 auStack_178 [144];
  longlong lStack_e8;
  longlong lStack_e0;
  uint uStack_d8;
  uint uStack_d4;
  uint uStack_d0;
  int iStack_cc;
  uint uStack_c8;
  uint uStack_c4;
  uint uStack_c0;
  int iStack_bc;
  int iStack_b8;
  uint uStack_b4;
  int iStack_b0;
  undefined1 *puStack_ac;
  uint uStack_a8;
  uint uStack_a4;
  int iStack_a0;
  
  fStack_180 = param_2[0xd];
  fStack_17c = param_2[0xe];
  fStack_188 = param_2[0xf];
  fStack_184 = param_2[0xc];
  iVar10 = *(int *)(param_1 + 0x10);
  iStack_b0 = param_1 + 0x240;
  fVar20 = param_2[2];
  if (((unsigned char *)0x00002e0a)[iVar10] != '\0') {
    dVar26 = (double)param_2[0x13];
    dVar27 = DOUBLE_001aa200 - dVar26;
    fStack_184 = (float)(dVar27 * (double)*(float *)(((unsigned char *)0x00002de0) + iVar10) +
                        (double)(float)((double)fStack_184 * dVar26));
    fStack_180 = (float)(dVar27 * (double)*(float *)(((unsigned char *)0x00002de4) + iVar10) +
                        (double)(float)((double)fStack_180 * dVar26));
    fStack_17c = (float)(dVar27 * (double)*(float *)(((unsigned char *)0x00002de8) + iVar10) +
                        (double)(float)((double)fStack_17c * dVar26));
    fStack_188 = (float)(dVar27 * (double)*(float *)(((unsigned char *)0x00002dec) + iVar10) +
                        (double)(float)((double)fStack_188 * dVar26));
  }
  iVar10 = (int)(*(float *)(param_1 + 0x2a54) + FLOAT_001aa10c);
  lStack_e8 = (longlong)iVar10;
  iVar21 = (int)(*(float *)(param_1 + 0x2a58) + FLOAT_001aa10c);
  lStack_e0 = (longlong)iVar21;
  iVar16 = iVar10 * iVar21;
  fVar3 = FLOAT_001aa10c;
  if (iVar10 == 2) {
    fVar3 = FLOAT_001aa110;
  }
  fVar6 = FLOAT_001aa10c;
  if (iVar21 == 2) {
    fVar6 = FLOAT_001aa110;
  }
  if ((0 < param_3) && (0 < param_4)) {
    puStack_ac = auStack_178;
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    iStack00000020 = param_3;
    iStack00000024 = param_4;
    iStack00000030 = param_7;
    FUN_0002a260(iStack_b0,puStack_ac);
    dVar26 = _floor((double)(float)((double)*param_2 - fparam_1));
    fVar8 = FLOAT_001aa114;
    fVar7 = FLOAT_001aa0e8;
    if (((unsigned char *)0x00002b7c)[param_1] == '\0') {
      dVar27 = _floor((double)(float)((double)param_2[1] - fparam_2));
      uVar11 = extraout_r4_00;
    }
    else {
      dVar27 = _ceil((double)((float)(fparam_2 + (double)param_2[1]) - FLOAT_001aa0e8));
      uVar11 = extraout_r4;
      fVar7 = fVar8;
    }
    fVar8 = (float)dVar27;
    if (param_8 == 0) {
      iVar21 = *(int *)(param_1 + 0x10);
      iVar10 = *(int *)(((unsigned char *)0x00002e6c) + iVar21);
      if (*(int *)(((unsigned char *)0x00002e6c) + iVar21) == 0) {
        iVar10 = iStack00000020;
      }
      uStack_c8 = *(uint *)(((unsigned char *)0x00002e78) + iVar21) & 7;
      uStack_c0 = (*(int *)(((unsigned char *)0x00002e80) + iVar21) - 1U) + (iVar10 + 7 >> 3) &
                  ~(*(int *)(((unsigned char *)0x00002e80) + iVar21) - 1U);
      iStack00000030 =
           iStack00000030 +
           uStack_c0 * *(int *)(((unsigned char *)0x00002e74) + iVar21) +
           ((int)*(uint *)(((unsigned char *)0x00002e78) + iVar21) >> 3);
      uStack_c4 = (int)(iStack00000020 + uStack_c8 + 7) >> 3;
      if (((unsigned char *)0x00002e85)[iVar21] == '\0') {
        uStack_b4 = 0xffffffff;
        uVar24 = 1 << uStack_c8;
        uStack_d4 = 0x80 >> uStack_c8;
        uStack_d0 = 0;
      }
      else {
        uStack_b4 = 0;
        uStack_d0 = 0xffffffff;
        uStack_d4 = 0;
        uVar24 = 1 << uStack_c8;
      }
    }
    else {
      uVar24 = 1;
      uStack_c8 = 0;
      uStack_b4 = 0xff;
      uStack_d0 = 0xffffff00;
      uStack_c4 = iStack00000020 + 7 >> 3;
      uStack_d4 = 0x80;
      uStack_c0 = uStack_c4;
    }
    iVar19 = iStack00000020 * iStack00000024;
    iVar21 = iVar16 * iVar19;
    iVar10 = iVar21 * 0x20;
    if (0x7ff < iVar21) {
      iVar21 = 0x7ff;
      iVar10 = 0xffe0;
    }
    pfVar12 = *(float **)(param_1 + 0x1dc);
    if (*(float **)(param_1 + 0x1e0) <= pfVar12 + 2) {
      FUN_0001a0f0(param_1,0x1000000);
      pfVar12 = *(float **)(param_1 + 0x1dc);
      uVar11 = extraout_r4_01;
    }
    if (*(char *)(iStack_b0 + 0x2802) == '\0') {
      pfVar12[1] = 2.524355e-29;
      *pfVar12 = 2.07392e-42;
      *(undefined1 *)(iStack_b0 + 0x2802) = 1;
      pfVar12 = *(float **)(param_1 + 0x1dc);
    }
    if (*(uint *)(param_1 + 0x1e0) <= (uint)((int)pfVar12 + iVar10 + 0x10)) {
      FUN_0001a0f0(param_1,0x1000000);
      pfVar12 = *(float **)(param_1 + 0x1dc);
      uVar11 = extraout_r4_02;
    }
    pfVar25 = pfVar12 + 4;
    iVar10 = 0;
    iStack_b8 = 0;
    uStack_d8 = uVar24 & uStack_d0;
    bVar1 = 0 < (int)uStack_c4;
    iVar13 = iVar21;
    do {
      if (bVar1) {
        fVar5 = (float)dVar26;
        if (7 < (int)uStack_c8) {
          iStack_bc = 0;
          uStack_a8 = uStack_d0 & 1;
          uStack_a4 = uStack_b4 & 0x80;
          iVar22 = iStack00000020;
          goto LAB_00016e40;
        }
        iStack_bc = 0;
        uStack_a8 = uStack_d0 & 1;
        uStack_a4 = uStack_b4 & 0x80;
        uVar17 = uStack_c8;
        uVar23 = uStack_d4;
        uVar24 = uStack_d8;
        iStack_cc = iStack00000020;
        do {
          fVar9 = FLOAT_001aa10c;
          iVar18 = 0;
          iVar22 = iStack_cc;
          do {
            if (((uint)*(byte *)(iStack00000030 + iStack_bc) & (uVar24 | uVar23)) != 0) {
              if (iVar21 < iVar16) {
                *pfVar12 = 2.93152e-42;
                pfVar12[1] = *(float *)(iStack_b0 + 0x1b84);
                pfVar12[2] = (float)((iVar13 - iVar21) * 0x80000 | 0xc0003500);
                pfVar12[3] = (float)((iVar13 - iVar21) * 0x10000 | 0x31);
                iVar21 = iVar16 * iVar19;
                *(float **)(param_1 + 0x1dc) = pfVar25;
                iVar13 = iVar21 * 0x20;
                if (0x7ff < iVar21) {
                  iVar21 = 0x7ff;
                  iVar13 = 0xffe0;
                }
                if (*(uint *)(param_1 + 0x1e0) <= (uint)((int)pfVar25 + iVar13 + 0x10)) {
                  iStack_a0 = iVar10;
                  FUN_0001a0f0(param_1,0x1000000);
                  uVar11 = extraout_r4_03;
                  iVar10 = iStack_a0;
                }
                pfVar12 = *(float **)(param_1 + 0x1dc);
                if ((pfVar25 != pfVar12) &&
                   (*(uint *)(param_1 + 0x1e0) <= (uint)((int)pfVar12 + iVar13 + 0x10))) {
                  iStack_a0 = iVar10;
                  FUN_0001a0f0(param_1,0x1000000);
                  pfVar12 = *(float **)(param_1 + 0x1dc);
                  uVar11 = extraout_r4_04;
                  iVar10 = iStack_a0;
                }
                pfVar25 = pfVar12 + 4;
                iVar13 = iVar21;
              }
              if (iVar16 == 1) {
                *pfVar25 = fVar3 + fVar5;
                pfVar25[1] = fVar6 + fVar8;
                pfVar25[2] = fVar20;
                pfVar25[3] = 1.0;
                pfVar25[4] = fStack_184;
                pfVar25[5] = fStack_180;
                pfVar14 = pfVar25 + 7;
                pfVar25[6] = fStack_17c;
                pfVar25 = pfVar25 + 8;
                *pfVar14 = fStack_188;
              }
              else if (iVar16 == 2) {
                *pfVar25 = fVar3 + fVar5;
                pfVar25[1] = fVar6 + fVar8;
                pfVar25[2] = fVar20;
                pfVar25[3] = 1.0;
                pfVar25[4] = fStack_184;
                pfVar25[5] = fStack_180;
                pfVar25[6] = fStack_17c;
                pfVar25[7] = fStack_188;
                pfVar25[8] = fVar3 + fVar5;
                pfVar25[9] = fVar6 + fVar8 + fVar9;
                pfVar25[10] = fVar20;
                pfVar25[0xb] = 1.0;
                pfVar25[0xc] = fStack_184;
                pfVar25[0xd] = fStack_180;
                pfVar14 = pfVar25 + 0xf;
                pfVar25[0xe] = fStack_17c;
                pfVar25 = pfVar25 + 0x10;
                *pfVar14 = fStack_188;
                fVar8 = (fVar8 + fVar9) - fVar9;
              }
              else {
                *pfVar25 = fVar3 + fVar5;
                pfVar25[1] = fVar6 + fVar8;
                pfVar25[2] = fVar20;
                pfVar25[3] = 1.0;
                pfVar25[4] = fStack_184;
                pfVar25[5] = fStack_180;
                pfVar25[6] = fStack_17c;
                pfVar25[7] = fStack_188;
                pfVar25[8] = fVar3 + fVar5;
                fVar4 = fVar6 + fVar8 + fVar9;
                pfVar25[9] = fVar4;
                pfVar25[10] = fVar20;
                pfVar25[0xb] = 1.0;
                pfVar25[0xc] = fStack_184;
                pfVar25[0xd] = fStack_180;
                pfVar25[0xe] = fStack_17c;
                pfVar25[0xf] = fStack_188;
                pfVar25[0x11] = fVar4;
                fVar4 = fVar3 + fVar5 + fVar9;
                pfVar25[0x10] = fVar4;
                pfVar25[0x12] = fVar20;
                pfVar25[0x13] = 1.0;
                pfVar25[0x14] = fStack_184;
                pfVar25[0x15] = fStack_180;
                pfVar25[0x16] = fStack_17c;
                pfVar25[0x17] = fStack_188;
                fVar8 = (fVar8 + fVar9) - fVar9;
                pfVar25[0x18] = fVar4;
                pfVar25[0x19] = fVar6 + fVar8;
                pfVar25[0x1a] = fVar20;
                pfVar25[0x1b] = 1.0;
                pfVar25[0x1c] = fStack_184;
                pfVar25[0x1d] = fStack_180;
                pfVar14 = pfVar25 + 0x1f;
                pfVar25[0x1e] = fStack_17c;
                pfVar25 = pfVar25 + 0x20;
                *pfVar14 = fStack_188;
                fVar5 = (fVar5 + fVar9) - fVar9;
              }
              iVar21 = iVar21 - iVar16;
            }
            bVar2 = uVar17 != 7;
            iVar19 = iVar19 + -1;
            uVar24 = uVar24 << 1;
            uVar23 = uVar23 >> 1;
            iVar22 = iVar22 + -1;
            uVar17 = uVar17 + 1;
            fVar5 = fVar5 + FLOAT_001aa0e8;
          } while ((bVar2) && (iVar18 = iVar18 + 1, iStack_cc != iVar18));
LAB_00016e40:
          iVar18 = uStack_c4 - iStack_bc;
          do {
            iStack_bc = iStack_bc + 1;
            iVar18 = iVar18 + -1;
            if (iVar18 == 0) goto LAB_00016a6c;
          } while (iVar22 == 0);
          uVar17 = 0;
          uVar23 = uStack_a4;
          uVar24 = uStack_a8;
          iStack_cc = iVar22;
        } while( true );
      }
LAB_00016a6c:
      fVar8 = fVar8 + fVar7;
      iStack_b8 = iStack_b8 + 1;
      iStack00000030 = iStack00000030 + uStack_c0;
    } while (iStack00000024 != iStack_b8);
    iVar13 = iVar13 - iVar21;
    if (iVar13 == 0) {
      pfVar25 = pfVar25 + -4;
    }
    else {
      *(undefined4 *)((int)pfVar12 + iVar10) = 0x82c;
      *(undefined4 *)((int)pfVar12 + iVar10 + 4) = *(undefined4 *)(iStack_b0 + 0x1b84);
      *(uint *)((int)pfVar12 + iVar10 + 8) = iVar13 * 0x80000 | 0xc0003500;
      *(uint *)((int)pfVar12 + iVar10 + 0xc) = iVar13 * 0x10000 | 0x31;
    }
    *(float **)(param_1 + 0x1dc) = pfVar25;
    if (*(float **)(param_1 + 0x1e0) <= pfVar25 + 2) {
      iStack_a0 = iVar10;
      FUN_0001a0f0(param_1,0x1000000);
      uVar11 = extraout_r4_05;
      iVar10 = iStack_a0;
    }
    iVar21 = *(int *)(param_1 + 0x1dc);
    *(int *)(param_1 + 0x1dc) = iVar21 + 8;
    *(undefined **)(iVar21 + iVar10) = ((unsigned char *)0x00001087);
    uVar15 = *(undefined4 *)(iStack_b0 + 0x1ccc);
    *(undefined4 *)(iVar21 + 4 + iVar10) = uVar15;
    FUN_0009d3b0(iStack_b0,uVar11,param_3,iVar10,pfVar12,iVar13,uVar15);
    FUN_000872e0(iStack_b0,puStack_ac);
  }
  return;
}

/* FUN_00016fc0 @ 0x16fc0 (272 bytes) */
int FUN_00016fc0(param_1, param_2)
  uint param_1;
  uint param_2;
{
  if (param_1 != 0x405) {
    if (param_1 < 0x406) {
      if (param_1 == 0x401) {
LAB_00017070:
        if ((param_2 & 0x10) == 0) {
          return 1;
        }
        return 3;
      }
      if (param_1 < 0x402) {
        if (param_1 == 0) {
          return 0x11;
        }
        if (param_1 == 0x400) {
          return 1;
        }
      }
      else {
        if (param_1 == 0x403) {
          if ((param_2 & 0x400) == 0) {
            return 1;
          }
          if ((param_2 & 0x10) == 0) {
            return 0;
          }
          return 2;
        }
        if (0x403 < param_1) {
          return 1;
        }
      }
    }
    else {
      if (param_1 == 0x408) {
        return 1;
      }
      if (param_1 < 0x409) {
        if (param_1 == 0x406) {
          return 1;
        }
        if (param_1 == 0x407) goto LAB_00017070;
      }
      else if (param_1 == 0x40a) {
        if (0x1ff < (param_2 & 0x300)) {
          return 8;
        }
      }
      else if (param_1 < 0x40a) {
        if (0xff < (param_2 & 0x300)) {
          return 7;
        }
      }
      else if ((param_1 == 0x40b) && (0x2ff < (param_2 & 0x300))) {
        return 9;
      }
    }
  }
  if ((param_2 & 0x400) == 0) {
    return 1;
  }
  return 0;
}

/* FUN_00017100 @ 0x17100 (84 bytes) */
int FUN_00017100(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  if (param_2 == 0xcb) {
    if (*(char *)(param_1 + 0x2a80) != '\0') {
      *(char *)(param_1 + 0x146) = (char)*param_3;
      return 1;
    }
  }
  else if ((param_2 == 0xde) && (*(char *)(param_1 + 0x2a80) != '\0')) {
    *(char *)(param_1 + 0x142) = (char)*param_3;
    return 1;
  }
  return 0;
}

/* FUN_00017160 @ 0x17160 (236 bytes) */
int FUN_00017160(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  int param_3;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *param_2 & 0x80ffffff;
  *param_2 = uVar2;
  if (param_3 == 0) {
    *(undefined1 *)(param_1 + 0x143) = 1;
  }
  else {
    iVar3 = *(int *)(param_3 + 0xc);
    if (iVar3 - 0xde0U < 2) {
      uVar2 = uVar2 | 0x10000000;
      *param_2 = uVar2;
    }
    else if (iVar3 == 0x84f5) {
      uVar2 = uVar2 | 0x20000000;
      *param_2 = uVar2;
    }
    else if (iVar3 == 0x8513) {
      uVar2 = uVar2 | 0x30000000;
      *param_2 = uVar2;
    }
    uVar1 = 0xc000000;
    if (*(int *)(param_3 + 0x14) < 0xd) {
      uVar1 = *(int *)(param_3 + 0x14) << 0x18;
    }
    *param_2 = uVar1 & 0xf000000 | uVar2;
    *(undefined1 *)(param_1 + 0x143) = 0;
  }
  if (*(int *)(param_1 + 0x150) == 0) {
    if (param_3 == 0) {
      **(uint **)(param_1 + 0x14) = **(uint **)(param_1 + 0x14) | 2;
      ((unsigned char *)0x00002b7c)[param_1] = 1;
    }
    else {
      **(uint **)(param_1 + 0x14) = **(uint **)(param_1 + 0x14) & 0xfffffffd;
      ((unsigned char *)0x00002b7c)[param_1] = 0;
    }
  }
  FUN_000a7a60(param_1);
  return;
}

/* FUN_00017260 @ 0x17260 (168 bytes) */
int FUN_00017260(param_1)
  int param_1;
{
  int iVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  piVar3 = *(int **)(param_1 + 0x150);
  if (piVar3 == (int *)0x0) {
    uVar2 = FUN_0002f410(*(undefined4 *)(param_1 + 0x154));
    ((unsigned char *)0x00002b7f)[param_1] = uVar2;
  }
  else {
    iVar5 = 4;
    ((unsigned char *)0x00002b7f)[param_1] = 0x2f;
    iVar4 = *piVar3;
    do {
      if ((*(ushort *)(iVar4 + 0x90) != 0) &&
         (iVar1 = *(int *)((*(ushort *)(iVar4 + 0x90) - 0x8ce0) * 4 + piVar3[1]), iVar1 != 0)) {
        ((unsigned char *)0x00002b7f)[param_1] = *(undefined1 *)(iVar1 + 0x38);
        break;
      }
      iVar4 = iVar4 + 2;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  FUN_000a7a60(param_1);
  return;
}

/* FUN_00017310 @ 0x17310 (1008 bytes) */
int FUN_00017310(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint *puVar6;
  undefined4 local_28;
  int local_24;
  uint local_20;
  
  uVar1 = 0x271e;
  if (param_3 != (undefined4 *)0x0) {
    if (param_2 == 0x132) {
      puVar4 = *(undefined4 **)(param_1 + 0x1dc);
      if (*(undefined4 **)(param_1 + 0x1e0) <= puVar4 + 4) {
        FUN_0001a0f0(param_1,0x1000000);
        puVar4 = *(undefined4 **)(param_1 + 0x1dc);
      }
      puVar6 = *(uint **)(param_1 + 0x1d8);
      *(undefined4 **)(param_1 + 0x1dc) = puVar4 + 4;
      *puVar6 = (int)puVar4 - (int)puVar6 >> 2 | *puVar6;
      *(undefined4 **)(param_1 + 0x1d8) = puVar4;
      *puVar4 = 0x3d000000;
      puVar4[1] = 0x132;
      puVar4[2] = *param_3;
      puVar4[3] = 0;
      uVar1 = 0;
    }
    else {
      if (param_2 < 0x133) {
        if (param_2 == 300) {
          puVar4 = *(undefined4 **)(param_1 + 0x1dc);
          if (*(undefined4 **)(param_1 + 0x1e0) <= puVar4 + 6) {
            FUN_0001a0f0(param_1,0x1000000);
            puVar4 = *(undefined4 **)(param_1 + 0x1dc);
          }
          *(undefined4 **)(param_1 + 0x1dc) = puVar4 + 6;
          *puVar4 = ((unsigned char *)0x00001040);
          puVar4[1] = 0;
          puVar4[2] = ((unsigned char *)0x00001393);
          puVar4[3] = 10;
          puVar4[4] = 0x5c8;
          puVar4[5] = 0x20000;
          return 0;
        }
      }
      else {
        if (param_2 == 0x1fe) {
          if ((*(int *)(param_1 + 0xf8) != 0) && (*(int *)(param_1 + 0x2a84) == 0)) {
            uVar1 = FUN_00019db0(param_1,*param_3,1);
            return uVar1;
          }
          return 0;
        }
        if (param_2 == 0x29b) {
          if (*(uint *)(param_1 + 0x1e0) <= *(int *)(param_1 + 0x1dc) + 0x60U) {
            FUN_0001a0f0(param_1,0x1000000);
          }
          iVar5 = *(int *)(param_1 + 500);
          uVar3 = *(uint *)(param_1 + 0x1f8);
          if (uVar3 <= iVar5 + 0x800U) {
            local_28 = 2;
            uVar3 = *(int *)(param_1 + 0x204) + 1;
            *(uint *)(param_1 + 0x204) = uVar3;
            if (2 < uVar3) {
              if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
                FUN_0001a0f0(param_1,0x1000000);
                iVar5 = *(int *)(param_1 + 500);
              }
              *(undefined4 *)(param_1 + 0x204) = 1;
            }
            *(int *)(*(int *)(param_1 + 0x208) + 0xc) = iVar5 - *(int *)(param_1 + 0x1fc) >> 2;
            _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(param_1 + 4),0x12,0,0,&local_24,&local_28);
            uVar2 = *(uint *)(FUN_000026c8 + param_1);
            *(int *)(param_1 + 0x1fc) = local_24;
            uVar3 = local_24 + (local_20 & 0xfffffffc);
            *(int *)(param_1 + 500) = local_24;
            *(uint *)(param_1 + 0x1f8) = uVar3;
            uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x208) + 8);
            *(uint *)(FUN_000026c8 + param_1) = uVar2 | 1;
            *(undefined4 *)(param_1 + 0x200) = uVar1;
            iVar5 = local_24;
          }
          if (uVar3 <= iVar5 + 800U) {
            local_28 = 2;
            uVar3 = *(int *)(param_1 + 0x204) + 1;
            *(uint *)(param_1 + 0x204) = uVar3;
            if (2 < uVar3) {
              if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
                FUN_0001a0f0(param_1,0x1000000);
                iVar5 = *(int *)(param_1 + 500);
              }
              *(undefined4 *)(param_1 + 0x204) = 1;
            }
            *(int *)(*(int *)(param_1 + 0x208) + 0xc) = iVar5 - *(int *)(param_1 + 0x1fc) >> 2;
            _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(param_1 + 4),0x12,0,0,&local_24,&local_28);
            uVar3 = *(uint *)(FUN_000026c8 + param_1);
            *(int *)(param_1 + 0x1fc) = local_24;
            *(int *)(param_1 + 500) = local_24;
            *(uint *)(param_1 + 0x1f8) = local_24 + (local_20 & 0xfffffffc);
            uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x208) + 8);
            *(uint *)(FUN_000026c8 + param_1) = uVar3 | 1;
            *(undefined4 *)(param_1 + 0x200) = uVar1;
            iVar5 = local_24;
          }
          iVar5 = iVar5 + 800;
          *(int *)(param_1 + 500) = iVar5;
          local_28 = 2;
          uVar3 = *(int *)(param_1 + 0x204) + 1;
          *(uint *)(param_1 + 0x204) = uVar3;
          if (2 < uVar3) {
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              FUN_0001a0f0(param_1,0x1000000);
              iVar5 = *(int *)(param_1 + 500);
            }
            *(undefined4 *)(param_1 + 0x204) = 1;
          }
          *(int *)(*(int *)(param_1 + 0x208) + 0xc) = iVar5 - *(int *)(param_1 + 0x1fc) >> 2;
          _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(param_1 + 4),0x12,0,0,&local_24,&local_28);
          uVar3 = *(uint *)(FUN_000026c8 + param_1);
          *(int *)(param_1 + 0x1fc) = local_24;
          *(int *)(param_1 + 500) = local_24;
          *(uint *)(param_1 + 0x1f8) = local_24 + (local_20 & 0xfffffffc);
          uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x208) + 8);
          *(uint *)(FUN_000026c8 + param_1) = uVar3 | 1;
          *(undefined4 *)(param_1 + 0x200) = uVar1;
          return 0;
        }
      }
      uVar1 = 0x271a;
    }
  }
  return uVar1;
}

/* FUN_00017720 @ 0x17720 (36 bytes) */
int FUN_00017720(param_1)
  undefined4 param_1;
{
  uint uVar1;
  
  uVar1 = FUN_00039100(param_1);
  return uVar1 | 0x1900;
}

/* FUN_00017750 @ 0x17750 (748 bytes) */
int FUN_00017750(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar4;
  short local_58;
  short local_56;
  short local_54;
  short local_52;
  short local_50;
  
  param_2[0x29] = 0x80;
  *param_2 = 10;
  *(undefined1 *)((int)param_2 + 0x7b) = 1;
  *(undefined1 *)(param_2 + 0x1e) = 1;
  *(undefined1 *)((int)param_2 + 0x79) = 1;
  *(undefined1 *)((int)param_2 + 0x7a) = 1;
  param_2[3] = 0x1000;
  param_2[4] = 0x1000;
  param_2[5] = 4;
  param_2[6] = 4;
  param_2[7] = 0x20;
  param_2[8] = 0x20;
  param_2[0x1b] = 0x3f800000;
  param_2[0x1c] = 0x42800000;
  param_2[0x1d] = 0x3e000000;
  param_2[1] = 0x3f800000;
  param_2[2] = 3;
  param_2[0x28] = 0x80;
  param_2[0x2a] = 0x20;
  param_2[0x18] = 0x3f800000;
  param_2[0x19] = 0x42800000;
  param_2[0x1a] = 0x3e000000;
  *(byte *)(param_2 + 9) = (byte)(-(*(uint *)(param_3 + 0x10) & 0x3ffffffc) >> 0x1f);
  *(byte *)((int)param_2 + 0x25) = (byte)(*(uint *)(param_3 + 0xc) >> 3) & 1;
  uVar4 = *(uint *)(param_3 + 0xc) >> 1 & 1;
  *(char *)((int)param_2 + 0x26) = (char)uVar4;
  *(byte *)((int)param_2 + 0x27) = (byte)(-(*(uint *)(param_3 + 0x10) & 0x3f000000) >> 0x1f);
  iVar3 = param_3;
  FUN_0000a180(*(undefined4 *)(param_3 + 0x10),&local_58,param_3,in_r6,in_r7,in_r8,uVar4);
  param_2[10] = (int)local_50;
  param_2[0xb] = (int)local_58;
  param_2[0xc] = (int)local_56;
  param_2[0xd] = (int)local_54;
  param_2[0xe] = (int)local_52;
  FUN_0000a180(*(undefined4 *)(param_3 + 0x14),&local_58,iVar3,in_r6,in_r7,in_r8,(int)local_54);
  param_2[0x11] = (int)local_58;
  param_2[0x12] = (int)local_56;
  param_2[0x13] = (int)local_54;
  param_2[0x14] = (int)local_52;
  uVar2 = FUN_0000a0f0(*(undefined4 *)(param_3 + 0x18));
  param_2[0xf] = uVar2;
  uVar2 = FUN_0000a0f0(*(undefined4 *)(param_3 + 0x1c));
  param_2[0x10] = uVar2;
  param_2[0x15] = (int)*(short *)(param_3 + 0x22);
  param_2[0x16] = (int)*(short *)(param_3 + 0x24);
  sVar1 = *(short *)(param_3 + 0x26);
  *(undefined2 *)((int)param_2 + 0x7e) = 2;
  *(undefined2 *)((int)param_2 + 0x82) = 6;
  *(undefined2 *)(param_2 + 0x1f) = 3;
  param_2[0x22] = 0x800;
  param_2[0x25] = param_2[0x25] | 4;
  param_2[0x23] = 0xffff;
  *(undefined2 *)((int)param_2 + 0xba) = 8;
  param_2[0x2c] = 0x41800000;
  param_2[0x17] = (int)sVar1;
  *(undefined2 *)((int)param_2 + 0xc2) = 0x1000;
  *(undefined2 *)(param_2 + 0x20) = 1;
  *(undefined2 *)(param_2 + 0x21) = 5;
  *(undefined2 *)((int)param_2 + 0x86) = 4;
  param_2[0x47] = 0;
  param_2[0x48] = 0;
  param_2[0x26] = 0;
  param_2[0x24] = 4;
  *(undefined2 *)(param_2 + 0x2d) = 8;
  *(undefined2 *)(param_2 + 0x2e) = 0;
  param_2[0x2b] = 0x41800000;
  *(undefined2 *)(param_2 + 0x2f) = 0x1000;
  *(undefined2 *)((int)param_2 + 0xbe) = 0x200;
  param_2[0x3a] = 0x1000;
  *(undefined2 *)(param_2 + 0x30) = 0x1000;
  *(undefined1 *)((int)param_2 + 199) = 1;
  *(undefined2 *)((int)param_2 + 0xb6) = 0x10;
  param_2[0x32] = 0x83f0;
  *(undefined1 *)((int)param_2 + 0xc6) = 5;
  *(undefined2 *)(param_2 + 0x3c) = 0x100;
  *(undefined2 *)((int)param_2 + 0xf2) = 0x20;
  *(undefined2 *)(param_2 + 0x46) = 1;
  *(undefined2 *)((int)param_2 + 0x102) = 0x40;
  *(undefined2 *)((int)param_2 + 0x10e) = 0x200;
  *(undefined2 *)((int)param_2 + 0xfe) = 10;
  *(undefined2 *)(param_2 + 0x44) = 4;
  *(undefined2 *)((int)param_2 + 0x116) = 0;
  *(undefined2 *)(param_2 + 0x3b) = 0x100;
  *(undefined2 *)(param_2 + 0x3d) = 0;
  *(undefined2 *)((int)param_2 + 0xf6) = 0;
  *(undefined2 *)(param_2 + 0x40) = 0x40;
  *(undefined2 *)(param_2 + 0x43) = 0x200;
  *(undefined2 *)(param_2 + 0x41) = 0;
  *(undefined2 *)((int)param_2 + 0x106) = 0;
  *(undefined2 *)((int)param_2 + 0x112) = 0;
  *(undefined2 *)(param_2 + 0x45) = 0;
  param_2[0x33] = 0x83f1;
  param_2[0x34] = 0x83f2;
  param_2[0x35] = 0x83f3;
  param_2[0x36] = 0x8837;
  param_2[0x3e] = 0;
  param_2[0x42] = 0;
  param_2[0x49] = param_2[0x49] | 0xffb7ffff;
  param_2[0x4b] = param_2[0x4b] | 0x74fc;
  *(undefined2 *)((int)param_2 + 0xee) = 0x12;
  param_2[0x4a] = param_2[0x4a] | 0x447f9e7;
  *(undefined2 *)(param_2 + 0x3f) = 0x400;
  return;
}

/* FUN_00017a40 @ 0x17a40 (200 bytes) */
int FUN_00017a40(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  uint *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_2 + 0x18);
  uVar2 = *param_1;
  if (iVar1 != 1) {
    if (iVar1 == 0x400) {
      uVar2 = uVar2 | 0x10000;
    }
    else if (iVar1 == 0x800) {
      uVar2 = uVar2 | 0x30000;
    }
    else {
      uVar2 = uVar2 | 0x20000;
    }
  }
  if ((*(uint *)(param_2 + 8) & 8) != 0) {
    uVar2 = uVar2 | 0x80000000;
  }
  if (*(short *)(param_2 + 0x24) != 0) {
    if (((uVar2 & 0xf) == 4) && (*(int *)(param_2 + 0x28) != 1)) {
      if (*(short *)(param_2 + 0x26) == 6) {
        uVar2 = uVar2 | 0x400000;
      }
      else if (*(short *)(param_2 + 0x26) == 4) {
        uVar2 = uVar2 | 0x200000;
      }
      else {
        uVar2 = uVar2 | 0x100000;
      }
    }
    else if ((*(short *)(param_2 + 0x26) == 4) || (*(short *)(param_2 + 0x26) == 6)) {
      uVar2 = uVar2 | 0x80000;
    }
    else {
      uVar2 = uVar2 | 0x40000;
    }
  }
  *param_1 = uVar2;
  return;
}

/* FUN_00017b20 @ 0x17b20 (740 bytes) */
int FUN_00017b20(param_1)
  int param_1;
{
  int iVar1;
  pid_t pVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  
  iVar1 = _CFNotificationCenterGetDistributedCenter();
  pVar2 = _getpid();
  *(pid_t *)(param_1 + 0x2a60) = pVar2;
  if (iVar1 == 0) {
    return;
  }
  iVar3 = _CFStringCreateWithCString(0,"ATI Displays",0x600);
  iVar4 = _CFStringCreateWithCString(0,"com.ati.ati_displays",0x600);
  iVar5 = _CFStringCreateWithCString(0,"pid",0x600);
  iVar6 = _CFStringCreateWithCString(0,"gldisplaymask",0x600);
  iVar7 = _CFStringCreateWithCString(0,"ATI GL Driver",0x600);
  iVar8 = _CFStringCreateWithCString(0,"com.ati.ati_gl_driver",0x600);
  if (iVar3 == 0) goto LAB_00017d90;
  if ((((iVar4 != 0) && (iVar5 != 0)) && (iVar6 != 0)) && ((iVar7 != 0 && (iVar8 != 0)))) {
    _CFNotificationCenterAddObserver(iVar1,param_1,PTR_FUN_001e88c4,iVar3,iVar4,2);
    local_48 = iVar5;
    local_40 = _CFNumberCreate(0,3,param_1 + 0x2a60);
    local_44 = iVar6;
    local_3c = _CFNumberCreate(0,3,param_1 + 0x2a64);
    if (local_40 != 0) {
      if (local_3c != 0) {
        iVar9 = _CFDictionaryCreate(*(undefined4 *)PTR_001e88c0,&local_48,&local_40,2,PTR_001e88b8,
                                    PTR_001e88bc);
        if (iVar9 != 0) {
          _CFNotificationCenterPostNotification(iVar1,iVar7,iVar8,iVar9,1);
          _CFRelease(iVar9);
        }
        if (local_40 == 0) goto LAB_00017cfc;
      }
      _CFRelease();
    }
LAB_00017cfc:
    if (local_3c != 0) {
      _CFRelease();
    }
  }
  _CFRelease(iVar3);
LAB_00017d90:
  if (iVar4 != 0) {
    _CFRelease(iVar4);
  }
  if (iVar5 != 0) {
    _CFRelease(iVar5);
  }
  if (iVar6 != 0) {
    _CFRelease(iVar6);
  }
  if (iVar7 != 0) {
    _CFRelease(iVar7);
  }
  if (iVar8 != 0) {
    _CFRelease(iVar8);
  }
  return;
}

/* FUN_00017e10 @ 0x17e10 (204 bytes) */
int FUN_00017e10(param_1)
  undefined4 param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = _CFNotificationCenterGetDistributedCenter();
  if (iVar1 != 0) {
    iVar2 = _CFStringCreateWithCString(0,"ATI Displays",0x600);
    iVar3 = _CFStringCreateWithCString(0,"com.ati.ati_displays",0x600);
    if (iVar2 != 0) {
      if (iVar3 != 0) {
        _CFNotificationCenterRemoveObserver(iVar1,param_1,iVar2,iVar3);
      }
      _CFRelease(iVar2);
    }
    if (iVar3 != 0) {
      _CFRelease(iVar3);
      return;
    }
  }
  return;
}

/* FUN_00017ee0 @ 0x17ee0 (432 bytes) */
int FUN_00017ee0()
{
  pid_t pVar1;
  FILE *pFVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  size_t sVar7;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int in_r9;
  undefined4 in_r10;
  size_t sVar8;
  char acStack_48 [52];
  
  pVar1 = _getpid();
  FUN_001a32d0(acStack_48,"ps -wwp %d\n",pVar1,in_r6,in_r7,in_r8,in_r9,in_r10);
  pFVar2 = _popen(acStack_48,"r");
  if (pFVar2 == (FILE *)0x0) {
    _puts("  failed to compute application path");
  }
  else {
    pcVar3 = _malloc(0x200);
    pcVar4 = _malloc(0x100);
    if ((pcVar3 == (char *)0x0) || (pcVar4 == (char *)0x0)) {
      _puts("  failed to compute application path");
    }
    else {
      _fgets(pcVar3,0x32,pFVar2);
      _fgets(pcVar3,0x200,pFVar2);
      pcVar5 = _index(pcVar3,0x2f);
      pcVar6 = _rindex(pcVar3,0x2d);
      if (pcVar6 == (char *)0x0) {
        pcVar6 = _strchr(pcVar3,0);
      }
      sVar7 = (int)pcVar6 - (int)pcVar5;
      if (0 < (int)sVar7) {
        in_r9 = 0;
        pcVar6 = pcVar5;
        sVar8 = sVar7;
        do {
          if ((pcVar5[in_r9] == ' ') && (pcVar6[1] == '/')) {
            *pcVar6 = '\0';
            break;
          }
          in_r9 = in_r9 + 1;
          pcVar6 = pcVar6 + 1;
          sVar8 = sVar8 - 1;
        } while (sVar8 != 0);
      }
      _strlcpy(pcVar4,pcVar5,sVar7);
      FUN_001a337c("  application path | %s\n",pcVar5,sVar7,in_r6,in_r7,in_r8,in_r9,in_r10);
    }
    _pclose(pFVar2);
    if (pcVar3 != (char *)0x0) {
      _free(pcVar3);
    }
    if (pcVar4 != (char *)0x0) {
      _free(pcVar4);
    }
  }
  return;
}

/* FUN_00018090 @ 0x18090 (100 bytes) */
int FUN_00018090(param_1, param_2)
  uint param_1;
  uint param_2;
{
  if ((param_2 & 0x2000) == 0) {
    return 0;
  }
  if (param_1 != 8) {
    if (param_1 < 9) {
      if (param_1 != 7) {
        return 0;
      }
      goto LAB_000180e4;
    }
    if (param_1 == 10) goto LAB_000180e4;
    if (param_1 != 0xb) {
      return 0;
    }
  }
  if (0x1ff < (param_2 & 0x300)) {
    return 2;
  }
LAB_000180e4:
  if ((param_2 & 0x300) < 0x100) {
    return 0;
  }
  return 1;
}

/* FUN_00018120 @ 0x18120 (6016 bytes) */
int FUN_00018120(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  float *param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  ushort uVar8;
  ushort uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  bool bVar22;
  double dVar23;
  int iVar24;
  uint uVar25;
  uint uVar26;
  int iVar27;
  uint uVar28;
  int iVar29;
  uint *puVar30;
  uint *puVar31;
  undefined4 uVar32;
  int iVar33;
  int iVar34;
  void *pvVar35;
  undefined4 *puVar36;
  uint uVar37;
  uint uVar38;
  int iVar39;
  uint uVar40;
  int iVar41;
  uint uVar42;
  undefined *puVar43;
  uint uVar44;
  int in_r10;
  uint uVar45;
  uint uVar46;
  uint uVar47;
  uint uVar48;
  uint uVar49;
  uint uVar50;
  int iVar51;
  undefined4 *puVar52;
  uint uVar53;
  
  iVar51 = *(int *)(param_1 + 0x10);
  iVar34 = param_3;
  iVar29 = param_4;
  iVar39 = param_5;
  iVar41 = param_6;
  uVar32 = ((int (*)())FUN_0000a2f0)((uint)*(ushort *)(((unsigned char *)0x00002db8) + iVar51),*(undefined4 *)(param_1 + 0x154));
  if ((((unsigned char *)0x00002d84)[iVar51] == '\0') ||
     ((((((*(int *)(((unsigned char *)0x00002d68) + iVar51) == 0x10000 &&
          (*(int *)(((unsigned char *)0x00002d6c) + iVar51) == 0x10000)) &&
         (*(short *)(((unsigned char *)0x00002d80) + iVar51) != -0x7ff5)) &&
        ((*(short *)(((unsigned char *)0x00002d80) + iVar51) != -0x7ff9 &&
         (*(short *)(((unsigned char *)0x00002d82) + iVar51) != -0x7ff5)))) &&
       (*(short *)(((unsigned char *)0x00002d82) + iVar51) != -0x7ff9)) || (((unsigned char *)0x00002e33)[iVar51] != '\0')))) {
    uVar42 = *(uint *)(param_1 + 0x26b0) & 0xfffffffd;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  else {
    uVar42 = *(uint *)(param_1 + 0x26b0) | 2;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  if (((unsigned char *)0x00002d66)[iVar51] == '\0') {
    uVar42 = uVar42 & 0xfffffffe;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  else {
    uVar42 = uVar42 | 1;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  if ((*(uint *)(((unsigned char *)0x000030b4) + iVar51) & 0xcff1) == 0) {
    uVar42 = uVar42 & 0xfffff7ff;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  else {
    uVar42 = uVar42 | 0x800;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  if ((((unsigned char *)0x00002ddc)[iVar51] == '\0') || ((*(uint *)(param_1 + 0x154) & 0xf) != 3)) {
    uVar42 = uVar42 & 0xffffffdf;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  else {
    uVar42 = uVar42 | 0x20;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  if ((((*(uint *)(((unsigned char *)0x000031c0) + iVar51) & 1) == 0) || ((*(uint *)(param_1 + 0x154) & 0x80) == 0))
     || ((*(short *)(((unsigned char *)0x000031a0) + iVar51) == 0x207 &&
         (*(int *)(((unsigned char *)0x000031a4) + iVar51) == 0x1e001e00)))) {
    uVar42 = uVar42 & 0xfffeffff;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  else {
    uVar42 = uVar42 | 0x10000;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  if ((((unsigned char *)0x00002dc8)[iVar51] == '\0') || ((*(uint *)(param_1 + 0x154) & 0x40) == 0)) {
    uVar42 = uVar42 & 0xffffffef;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  else {
    uVar42 = uVar42 | 0x10;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  if (((unsigned char *)0x00002e0a)[iVar51] == '\0') {
    *(uint *)(param_1 + 0x26b0) = uVar42 & 0xffffffbf;
  }
  else {
    *(uint *)(param_1 + 0x26b0) = uVar42 | 0x40;
  }
  if (((((((*(int *)(param_1 + 0x18c) == 0) || (iVar33 = FUN_000a4760(param_1), iVar33 == 0)) &&
         ((*(int *)(param_1 + 400) == 0 || (iVar33 = FUN_000a4760(param_1), iVar33 == 1)))) &&
        ((*(int *)(param_1 + 0x194) == 0 || (iVar33 = FUN_000a4760(param_1), iVar33 == 2)))) &&
       ((*(int *)(param_1 + 0x198) == 0 || (iVar33 = FUN_000a4760(param_1), iVar33 == 3)))) &&
      ((((*(int *)(param_1 + 0x19c) == 0 || (iVar33 = FUN_000a4760(param_1), iVar33 == 4)) &&
        ((*(int *)(param_1 + 0x1a0) == 0 || (iVar33 = FUN_000a4760(param_1), iVar33 == 5)))) &&
       ((*(int *)(param_1 + 0x1a4) == 0 || (iVar33 = FUN_000a4760(param_1), iVar33 == 6)))))) &&
     ((*(int *)(param_1 + 0x1a8) == 0 || (iVar33 = FUN_000a4760(param_1), iVar33 == 7)))) {
    uVar42 = *(uint *)(param_1 + 0x26b0) & 0xfffdffff;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  else {
    uVar42 = *(uint *)(param_1 + 0x26b0) | 0x20000;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  if (((unsigned char *)0x00002e33)[iVar51] == '\0') {
    uVar42 = uVar42 & 0xfffffdff;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  else {
    uVar42 = uVar42 | 0x200;
    *(uint *)(param_1 + 0x26b0) = uVar42;
  }
  if ((((((unsigned char *)0x00002e43)[iVar51] == '\0') || (((unsigned char *)0x00002e40)[iVar51] == '\0')) ||
      (((unsigned char *)0x00002e41)[iVar51] == '\0')) || (((unsigned char *)0x00002e42)[iVar51] == '\0')) {
    puVar43 = (undefined *)(uVar42 | 0x400);
    *(undefined **)(param_1 + 0x26b0) = puVar43;
  }
  else {
    puVar43 = (undefined *)(uVar42 & 0xfffffbff);
    *(undefined **)(param_1 + 0x26b0) = puVar43;
  }
  if (*(short *)(((unsigned char *)0x00002dba) + iVar51) == *(short *)(((unsigned char *)0x00002db8) + iVar51)) {
    iVar41 = param_3 + param_5;
    iVar39 = param_4 + param_6;
    iVar33 = (int)*param_2;
    if (((unsigned char *)0x00002b7c)[param_1] == '\0') {
      fVar1 = param_2[1];
    }
    else {
      fVar1 = (float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 0x160) ^ 0x80000000) -
                     DOUBLE_001aa1e0) - (param_2[1] + FLOAT_001aa0e8);
    }
    iVar24 = (int)fVar1;
    iVar27 = param_5 + iVar33;
    in_r10 = iVar24 + param_6;
    if (((((iVar33 < param_3) || (iVar41 < iVar33)) && ((iVar27 < param_3 || (iVar41 < iVar27)))) ||
        ((iVar24 < param_4 || (iVar39 < iVar24)))) &&
       (((iVar33 < param_3 || (((iVar41 < iVar33 || (in_r10 < param_4)) || (iVar39 < in_r10)))) &&
        (((iVar27 < param_3 || (iVar41 < iVar27)) || ((in_r10 < param_4 || (iVar39 < in_r10))))))))
    goto LAB_000185c0;
    bVar22 = true;
  }
  else {
LAB_000185c0:
    bVar22 = false;
  }
  if (((param_7 == 0x1801) && ((*(uint *)(param_1 + 0x154) & 0x30000) != 0)) &&
     ((iVar33 = *(int *)(param_1 + 0x10), *(int *)((*(unsigned char *)0x00002e40) + iVar33) == 0 &&
      ((((((unsigned char *)0x00002e44)[iVar33] != '\0' && (((uint)puVar43 & 0x10001) == 0)) &&
        (((uint)puVar43 & 0x10) != 0)) && (*(short *)(((unsigned char *)0x00002dc4) + iVar33) == 0x207)))))) {
    iVar33 = FUN_0001a010(param_1,4,iVar34,iVar29,iVar39,iVar41,puVar43);
    if (iVar33 == 0) {
      iVar33 = 3;
      goto LAB_00018700;
    }
    puVar43 = *(undefined **)(param_1 + 0x26b0);
  }
  if ((((((uint)puVar43 & 0x20800) != 0) || (param_7 - 0x1801U < 2)) ||
      (((*(uint *)(((unsigned char *)0x000030b0) + *(int *)(param_1 + 0x10)) & 0x1ff) != 0 ||
       ((*(uint *)(((unsigned char *)0x000030b4) + *(int *)(param_1 + 0x10)) & 0xff0000) != 0)))) ||
     (((((uint)puVar43 & 0x10073) == 0 &&
       (puVar43 = PTR_DAT_001e88c8 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24,
       (*(uint *)(puVar43 + 0x14) & 7) < 3)) &&
      ((bVar22 && ((*(uint *)(param_1 + 0x154) & 0x20) != 0)))))) {
    iVar33 = 0;
  }
  else {
    iVar33 = 2;
  }
LAB_00018700:
  if ((*(int *)(*(int *)(param_1 + 0x18) + 0x1a0) != 0) ||
     (1 < (*(uint *)(param_1 + 0x1ae4) >> 6 & 0xffff))) {
    iVar33 = 0;
  }
  if ((bVar22) && (iVar33 - 2U < 2)) {
    iVar33 = 0;
  }
  iVar24 = FUN_0001a010(param_1,uVar32,iVar34,iVar29,iVar39,iVar41,puVar43);
  if (((iVar24 == 0) &&
      (iVar34 = FUN_0001a010(param_1,*(undefined4 *)(param_1 + 0x26a0),iVar34,iVar29,iVar39,iVar41,
                             puVar43), iVar34 == 0)) && (iVar33 != 0)) {
    fVar1 = *param_2 + FLOAT_001aa10c;
    if (fVar1 < FLOAT_001aa0d4) {
      fVar1 = fVar1 - FLOAT_001aa118;
    }
    uVar42 = (uint)fVar1;
    fVar1 = param_2[1] + FLOAT_001aa10c;
    if (fVar1 < FLOAT_001aa0d4) {
      fVar1 = fVar1 - FLOAT_001aa118;
    }
    uVar44 = (uint)fVar1;
    if (((unsigned char *)0x00002b7c)[param_1] != '\0') {
      uVar44 = uVar44 - param_6;
      param_4 = (*(int *)(param_1 + 0x160) - param_4) - param_6;
    }
    if (iVar33 == 1) {
      if (((unsigned char *)0x00002e33)[iVar51] == '\0') {
        uVar25 = 0xc;
        uVar28 = 0xc0;
      }
      else {
        uVar25 = *(uint *)(param_1 + 0x1d38) >> 8 & 0xf;
        uVar28 = uVar25 << 4;
      }
      FUN_00020b30(param_1,param_3,param_4,param_5,param_6,uVar42,uVar44,uVar32,uVar25 | uVar28);
    }
    else {
      if (iVar33 == 3) {
        iVar34 = param_1 + 0x240;
        uVar8 = *(ushort *)(param_1 + 0x11e);
        uVar25 = (uint)uVar8;
        uVar9 = *(ushort *)(param_1 + 0x122);
        uVar28 = (uint)uVar9;
        fVar1 = (float)((double)CONCAT44(0x43300000,param_4 - uVar44 ^ 0x80000000) - DOUBLE_001aa1e0
                       );
        fVar2 = (float)((double)CONCAT44(0x43300000,uVar42 ^ 0x80000000) - DOUBLE_001aa1e0);
        fVar3 = (float)((double)CONCAT44(0x43300000,uVar44 ^ 0x80000000) - DOUBLE_001aa1e0);
        fVar4 = (float)((double)CONCAT44(0x43300000,uVar42 + param_5 ^ 0x80000000) - DOUBLE_001aa1e0
                       );
        fVar5 = (float)((double)CONCAT44(0x43300000,uVar44 + param_6 ^ 0x80000000) - DOUBLE_001aa1e0
                       );
        fVar6 = (float)((double)CONCAT44(0x43300000,param_3 - uVar42 ^ 0x80000000) - DOUBLE_001aa1e0
                       );
        if ((uVar25 < 0x1001) && (uVar28 < 0x1001)) {
          uVar42 = 0;
          uVar48 = 0;
          uVar49 = 0;
          uVar44 = 0;
          uVar47 = 0;
          iVar29 = 0xc;
          fVar15 = FLOAT_001aa0d4;
          fVar10 = FLOAT_001aa0d4;
          fVar16 = FLOAT_001aa0d4;
          fVar11 = FLOAT_001aa0d4;
        }
        else {
          fVar10 = fVar3 + fVar1;
          fVar11 = fVar5 + fVar1;
          fVar7 = fVar2 + fVar6;
          fVar16 = fVar4 + fVar6;
          fVar15 = fVar11;
          if (fVar11 < fVar10) {
            fVar15 = fVar10;
            fVar10 = fVar11;
          }
          fVar11 = fVar7;
          if (fVar16 < fVar7) {
            fVar11 = fVar16;
            fVar16 = fVar7;
          }
          uVar42 = (int)fVar11 - 1;
          uVar42 = (((int)uVar42 >> 9) + (uint)((int)uVar42 < 0 && (uVar42 & 0x1ff) != 0)) * 0x200;
          uVar44 = 0;
          if ((-1 < (int)uVar42) && (uVar44 = uVar8 & 0xfe00, (int)uVar42 <= (int)(uVar8 & 0xfe00)))
          {
            uVar44 = uVar42 & 0xfe00;
          }
          uVar42 = 0x40;
          if ((0x40 < uVar28) && (uVar42 = uVar9 & 0xffc0, (int)(uVar28 - uVar42) < 0x40)) {
            uVar42 = uVar42 - 0x40;
          }
          uVar47 = 0;
          uVar48 = (int)fVar10 - 1;
          uVar48 = (((int)uVar48 >> 6) + (uint)((int)uVar48 < 0 && (uVar48 & 0x3f) != 0)) * 0x40;
          if ((-1 < (int)uVar48) && (uVar47 = uVar42 & 0xffff, (int)uVar48 <= (int)uVar42)) {
            uVar47 = uVar48 & 0xffc0;
          }
          uVar42 = 0x200;
          if (0x1ff < uVar44) {
            uVar42 = uVar44;
          }
          uVar48 = uVar25 - 1;
          uVar49 = (((int)uVar48 >> 9) + (uint)((int)uVar48 < 0 && (uVar48 & 0x1ff) != 0)) * 0x200;
          uVar48 = (uint)fVar16;
          if ((FLOAT_001aa0d4 < fVar16) &&
             ((float)((double)CONCAT44(0x43300000,uVar48 ^ 0x80000000) - DOUBLE_001aa1e0) < fVar16))
          {
            uVar48 = uVar48 + 1;
          }
          if ((int)uVar48 <= (int)uVar49) {
            uVar49 = uVar48;
          }
          uVar48 = 1;
          if ((int)uVar42 < (int)uVar49) {
            uVar48 = (int)((uVar49 - uVar42) + 0xbff) / 0xc00 & 0xff;
          }
          uVar42 = 0x40;
          if (0x3f < uVar47) {
            uVar42 = uVar47;
          }
          uVar49 = uVar28 - 1;
          uVar37 = (((int)uVar49 >> 6) + (uint)((int)uVar49 < 0 && (uVar49 & 0x3f) != 0)) * 0x40;
          uVar49 = (uint)fVar15;
          if ((FLOAT_001aa0d4 < fVar15) &&
             ((float)((double)CONCAT44(0x43300000,uVar49 ^ 0x80000000) - DOUBLE_001aa1e0) < fVar15))
          {
            uVar49 = uVar49 + 1;
          }
          if ((int)uVar49 <= (int)uVar37) {
            uVar37 = uVar49;
          }
          uVar49 = 1;
          if ((int)uVar42 < (int)uVar37) {
            uVar49 = (int)((uVar37 - uVar42) + 0xf7f) / 0xf80 & 0xff;
          }
          uVar42 = uVar48 * uVar49 & 0xff;
          iVar29 = uVar42 << 4;
        }
        iVar39 = iVar29 + 0x56f;
        *(undefined1 *)(param_1 + 0x2a5e) = 1;
        if (*(char *)(param_1 + 0x2a42) == '\0') {
          iVar39 = iVar29 + 0x571;
        }
        puVar36 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar34,iVar39);
        *(undefined4 **)(param_1 + 0x298c) = puVar36;
        puVar52 = puVar36;
        if (*(char *)(param_1 + 0x2a42) == '\0') {
          puVar52 = puVar36 + 2;
          *puVar36 = 0x5c8;
          puVar36[1] = 0x10000000;
          *(undefined1 *)(param_1 + 0x2a42) = 1;
        }
        puVar43 = PTR_DAT_001e88d0;
        puVar30 = *(uint **)(param_1 + 0x1d8);
        *puVar30 = (int)puVar52 - (int)puVar30 >> 2 | *puVar30;
        *(undefined4 **)(param_1 + 0x1d8) = puVar52;
        puVar52[2] = uVar32;
        puVar52[1] = 1000;
        *puVar52 = 0x31000000;
        puVar52[3] = uVar42;
        puVar52[4] = CONCAT22(uVar9,uVar8);
        _memcpy(puVar52 + 1000,puVar43,0x2f4);
        puVar30 = puVar52 + 0x4a5;
        puVar52[0x496] = 0xe - ((int)-(*(uint *)(param_1 + 0x154) & 0x30000 ^ 0x30000) >> 0x1f);
        fVar7 = FLOAT_001aa12c;
        if (uVar42 == 0) {
          fVar10 = FLOAT_001aa0d4;
          if (uVar25 != 0) {
            fVar10 = FLOAT_001aa0e8 /
                     (float)((double)CONCAT44(0x43300000,uVar25 ^ 0x80000000) - DOUBLE_001aa1e0);
          }
          fVar11 = FLOAT_001aa0d4;
          if (uVar28 != 0) {
            fVar11 = FLOAT_001aa0e8 /
                     (float)((double)CONCAT44(0x43300000,uVar28 ^ 0x80000000) - DOUBLE_001aa1e0);
          }
          *puVar30 = 0x31080;
          puVar52[0x4aa] = ((unsigned char *)0x00001087);
          puVar52[0x4a6] = fVar10 * (fVar2 + fVar6);
          puVar52[0x4a8] = fVar10 * (fVar4 + fVar6);
          puVar52[0x4a7] = fVar11 * (fVar5 + fVar1);
          puVar52[0x4a9] = fVar11 * (fVar3 + fVar1);
          fVar1 = (fVar2 + fVar4) * FLOAT_001aa10c;
          fVar6 = (fVar3 + fVar5) * FLOAT_001aa10c;
          puVar52[0x4ac] = 0xc0033500;
          puVar52[0x4ad] = 0x10031;
          puVar52[0x4ae] = fVar1;
          puVar52[0x4af] = fVar6;
          puVar52[0x4ab] = (int)((fVar4 - fVar2) * fVar7) << 0x10 | (int)((fVar5 - fVar3) * fVar7);
          puVar52[0x4b0] = 0;
          puVar30 = puVar52 + 0x4b1;
        }
        else if (uVar49 != 0) {
          uVar37 = uVar28 - uVar47;
          uVar50 = 0;
          iVar29 = 0;
          uVar42 = uVar47;
          do {
            if (uVar48 != 0) {
              uVar38 = iVar29 + uVar47;
              uVar40 = uVar25 - uVar44;
              iVar39 = 0;
              fVar2 = (float)((double)CONCAT44(0x43300000,uVar38 ^ 0x80000000) - DOUBLE_001aa1e0);
              uVar45 = uVar44;
              uVar53 = uVar48;
              do {
                *puVar30 = uVar45;
                puVar30[1] = uVar42;
                uVar26 = uVar40;
                if ((int)(uVar45 + 0x1000) <= (int)uVar25) {
                  uVar26 = 0x1000;
                }
                uVar46 = uVar37;
                if ((int)(uVar38 + 0x1000) <= (int)uVar28) {
                  uVar46 = 0x1000;
                }
                puVar30[2] = uVar26;
                puVar30[3] = uVar46;
                dVar23 = DOUBLE_001aa1e0;
                fVar3 = fVar11;
                if (iVar39 != 0) {
                  fVar3 = (float)((double)CONCAT44(0x43300000,uVar45 + 0x200 ^ 0x80000000) -
                                 DOUBLE_001aa1e0);
                }
                fVar4 = fVar10;
                if (uVar50 != 0) {
                  fVar4 = (float)((double)CONCAT44(0x43300000,uVar38 + 0x40 ^ 0x80000000) -
                                 DOUBLE_001aa1e0);
                }
                fVar5 = fVar16;
                if (iVar39 != uVar48 - 1) {
                  fVar5 = (float)((double)CONCAT44(0x43300000,uVar45 + 0xe00 ^ 0x80000000) -
                                 DOUBLE_001aa1e0);
                }
                fVar7 = fVar15;
                if (uVar50 != uVar49 - 1) {
                  fVar7 = (float)((double)CONCAT44(0x43300000,uVar38 + 0xfc0 ^ 0x80000000) -
                                 DOUBLE_001aa1e0);
                }
                fVar12 = fVar10;
                if (fVar10 - fVar4 < 0.0) {
                  fVar12 = fVar4;
                }
                fVar13 = fVar15;
                if (fVar7 - fVar15 < 0.0) {
                  fVar13 = fVar7;
                }
                fVar14 = fVar16;
                if (fVar5 - fVar16 < 0.0) {
                  fVar14 = fVar5;
                }
                fVar17 = fVar11;
                if (fVar11 - fVar3 < 0.0) {
                  fVar17 = fVar3;
                }
                if (-(fVar10 - fVar4) < 0.0) {
                  fVar4 = fVar12;
                }
                if (-(fVar7 - fVar15) < 0.0) {
                  fVar7 = fVar13;
                }
                if (-(fVar11 - fVar3) < 0.0) {
                  fVar3 = fVar17;
                }
                if (-(fVar5 - fVar16) < 0.0) {
                  fVar5 = fVar14;
                }
                fVar12 = fVar7 + -fVar1;
                fVar13 = fVar4 + -fVar1;
                fVar18 = fVar3 + -fVar6;
                fVar17 = fVar5 + -fVar6;
                fVar14 = fVar4;
                fVar19 = fVar12;
                if (fVar12 < fVar13) {
                  fVar14 = fVar7;
                  fVar7 = fVar4;
                  fVar19 = fVar13;
                  fVar13 = fVar12;
                }
                fVar4 = fVar5;
                fVar12 = fVar18;
                if (fVar17 < fVar18) {
                  fVar4 = fVar3;
                  fVar3 = fVar5;
                  fVar12 = fVar17;
                  fVar17 = fVar18;
                }
                fVar5 = FLOAT_001aa0d4;
                if (uVar26 != 0) {
                  fVar5 = FLOAT_001aa0e8 /
                          (float)((double)CONCAT44(0x43300000,uVar26 ^ 0x80000000) - DOUBLE_001aa1e0
                                 );
                }
                fVar18 = FLOAT_001aa0d4;
                if (uVar46 != 0) {
                  fVar18 = FLOAT_001aa0e8 /
                           (float)((double)CONCAT44(0x43300000,uVar46 ^ 0x80000000) -
                                  DOUBLE_001aa1e0);
                }
                uVar26 = uVar45 ^ 0x80000000;
                iVar39 = iVar39 + 1;
                uVar45 = uVar45 + 0xc00;
                uVar40 = uVar40 - 0xc00;
                fVar20 = (fVar17 - fVar12) * FLOAT_001aa12c;
                fVar21 = (fVar19 - fVar13) * FLOAT_001aa12c;
                fVar12 = (fVar17 + fVar12) * FLOAT_001aa10c;
                fVar13 = (fVar19 + fVar13) * FLOAT_001aa10c;
                puVar30[4] = 0x31080;
                puVar30[6] = (uint)(fVar18 * (fVar7 - fVar2));
                puVar30[8] = (uint)(fVar18 * (fVar14 - fVar2));
                puVar30[9] = (uint)((unsigned char *)0x00001087);
                fVar7 = (float)((double)CONCAT44(0x43300000,uVar26) - dVar23);
                puVar30[7] = (uint)(fVar5 * (fVar4 - fVar7));
                puVar30[5] = (uint)(fVar5 * (fVar3 - fVar7));
                puVar30[0xb] = 0xc0033500;
                puVar30[0xc] = 0x10031;
                puVar30[0xd] = (uint)fVar12;
                puVar30[0xe] = (uint)fVar13;
                puVar30[10] = (int)fVar20 << 0x10 | (int)fVar21;
                puVar30[0xf] = 0;
                puVar30 = puVar30 + 0x10;
                uVar53 = uVar53 - 1;
              } while (uVar53 != 0);
            }
            uVar50 = uVar50 + 1;
            iVar29 = iVar29 + 0xf80;
            uVar37 = uVar37 - 0xf80;
            uVar42 = uVar42 + 0xf80;
          } while (uVar50 != uVar49);
        }
        puVar31 = *(uint **)(param_1 + 0x1d8);
        *puVar31 = (int)puVar30 - (int)puVar31 >> 2 | *puVar31;
        *(uint **)(param_1 + 0x1d8) = puVar30;
        puVar30[2] = (uint)((unsigned char *)0x00001393);
        *puVar30 = 0x33000000;
        puVar30[1] = 2;
        puVar30[3] = 10;
        puVar30[4] = (uint)((unsigned char *)0x000013c6);
        puVar30[5] = 3;
        puVar30[6] = 0x5c8;
        puVar30[7] = 0x20000;
        puVar30[8] = (uint)(*(unsigned char *)0x000010ea);
        uVar42 = *(uint *)(param_1 + 0x1cfc);
        puVar30[10] = (uint)((unsigned char *)0x000010fa);
        puVar30[9] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1da0);
        puVar30[0xc] = 0xc0001000;
        puVar30[0xe] = 0x11004;
        puVar30[0xb] = uVar42;
        puVar30[0xf] = *(uint *)(param_1 + 0x1ca8);
        uVar42 = *(uint *)(param_1 + 0x1cac);
        puVar30[0x11] = (uint)((unsigned char *)0x00001008);
        puVar30[0x10] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1ca0);
        puVar30[0x13] = (uint)(*(unsigned char *)0x000010e9);
        puVar30[0x12] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1d20);
        puVar30[0x15] = (uint)((unsigned char *)0x000013c7);
        puVar30[0x14] = uVar42;
        puVar30[0x16] = *(uint *)(param_1 + 0x1cf0);
        puVar30[0x17] = (uint)((unsigned char *)0x000013c1);
        uVar42 = *(uint *)(param_1 + 0x1ce4);
        puVar30[0x19] = 0x850;
        puVar30[0x18] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1dc0);
        puVar30[0x1b] = 0x887;
        puVar30[0x1a] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1db4);
        puVar30[0xbd] = 0x82c;
        puVar30[0x1c] = uVar42;
        uVar42 = *(uint *)(FUN_00001dc4 + param_1);
        puVar30[0x1d] = (uint)((unsigned char *)0x000010ae);
        puVar30[0xbe] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1d70);
        puVar30[0x1f] = (uint)((unsigned char *)0x00001394);
        puVar30[0x1e] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1d30);
        puVar30[0x21] = (uint)((unsigned char *)0x00001380);
        puVar30[0x22] = 0;
        puVar30[0x23] = (uint)((unsigned char *)0x00001002);
        puVar30[0x20] = uVar42;
        puVar30[0x24] = *(uint *)(param_1 + 0x1d90);
        uVar42 = *(uint *)(param_1 + 0x1d90);
        puVar30[0x25] = 0x824;
        puVar30[0x24] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1ddc);
        puVar30[0x27] = 0x825;
        puVar30[0x26] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1de0);
        puVar30[0x29] = 0x82d;
        puVar30[0x28] = uVar42;
        puVar30[0x2a] = *(uint *)(FUN_000026c8 + param_1 + 4);
        puVar30[0x2b] = 0x854;
        puVar43 = PTR_DAT_001e88c8;
        uVar42 = **(uint **)(param_1 + 0x2680);
        puVar30[0x2d] = 0x878;
        puVar30[0x2c] = uVar42;
        uVar42 = **(uint **)(param_1 + 0x2684);
        puVar30[0x2f] = (uint)((unsigned char *)0x000013c0);
        puVar30[0x2e] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1ce0);
        puVar30[0x31] = (uint)((unsigned char *)0x000012f0);
        puVar30[0x30] = uVar42;
        puVar30[0x32] = *(uint *)(param_1 + 0x1d2c);
        if ((*(uint *)(puVar43 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0)
        {
          puVar30[0x32] = puVar30[0x32] & 0xfffffffe;
        }
        puVar43 = PTR_DAT_001e88c8;
        puVar30[0x33] = (uint)((unsigned char *)0x000012f5);
        uVar42 = *(uint *)(param_1 + 0x1c8c);
        puVar30[0x34] = uVar42;
        if ((*(uint *)(puVar43 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0)
        {
          puVar30[0x34] = uVar42 & 0xfffff7ff;
        }
        puVar30[0x35] = (uint)((unsigned char *)0x000010a2);
        uVar42 = *(uint *)(param_1 + 0x1d7c);
        puVar30[0x37] = (uint)((unsigned char *)0x00001381);
        puVar30[0x36] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1cc0);
        puVar30[0x38] = uVar42;
        if ((*(uint *)(puVar43 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x4000) == 0)
        {
          puVar30[0x38] = uVar42 & 0xfffffffc;
        }
        puVar30[0x39] = (uint)((unsigned char *)0x0000109e);
        uVar42 = *(uint *)(param_1 + 0x1d6c);
        puVar30[0x3b] = (uint)((unsigned char *)0x00001096);
        puVar30[0x3a] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1df8);
        puVar30[0x3d] = (uint)((unsigned char *)0x00001041);
        puVar30[0x3a] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x29f0);
        puVar30[0x3f] = (uint)((unsigned char *)0x00001046);
        puVar30[0x3e] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1dfc);
        puVar30[0x41] = (uint)((unsigned char *)0x00001094);
        puVar30[0x59] = (uint)((unsigned char *)0x00001095);
        puVar30[0x5b] = 0xc0221000;
        puVar30[0x7f] = (uint)((unsigned char *)0x00001180);
        puVar30[0x42] = 0;
        puVar30[0x43] = (uint)((unsigned char *)0x00001095);
        puVar30[0x45] = (uint)((unsigned char *)0x00001095);
        puVar30[0x40] = uVar42;
        puVar30[0x47] = (uint)((unsigned char *)0x00001095);
        puVar30[0x49] = (uint)((unsigned char *)0x00001095);
        puVar30[0x4b] = (uint)((unsigned char *)0x00001095);
        puVar30[0x4d] = (uint)((unsigned char *)0x00001095);
        puVar30[0x4f] = (uint)((unsigned char *)0x00001095);
        puVar30[0x51] = (uint)((unsigned char *)0x00001095);
        puVar30[0x53] = (uint)((unsigned char *)0x00001095);
        puVar30[0x55] = (uint)((unsigned char *)0x00001095);
        puVar30[0x57] = (uint)((unsigned char *)0x00001095);
        puVar30[0x80] = 2;
        puVar30[0x81] = (uint)((unsigned char *)0x00001189);
        puVar30[0x83] = (uint)((unsigned char *)0x00001181);
        puVar30[0x85] = (uint)((unsigned char *)0x0000118d);
        puVar30[0x87] = (uint)((unsigned char *)0x0000118e);
        puVar30[0x89] = (uint)((unsigned char *)0x0000118c);
        puVar30[0x8b] = (uint)((unsigned char *)0x000011a9);
        uVar42 = *(uint *)(param_1 + 0x257c);
        puVar30[0x8d] = (uint)((unsigned char *)0x000011aa);
        puVar30[0x8c] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x2580);
        puVar30[0x8f] = (uint)((unsigned char *)0x000011ab);
        puVar30[0x8e] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x2584);
        puVar30[0x91] = (uint)((unsigned char *)0x000011ac);
        puVar30[0x90] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x2588);
        puVar30[0x93] = (uint)((unsigned char *)0x000010c0);
        puVar30[0x92] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x216c);
        puVar30[0x95] = (uint)((unsigned char *)0x000010c1);
        puVar30[0x97] = (uint)((unsigned char *)0x000010c8);
        puVar30[0x99] = (uint)((unsigned char *)0x0000101d);
        puVar30[0x94] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x2128);
        puVar30[0x9b] = (uint)((unsigned char *)0x0000138a);
        puVar30[0xa2] = 0;
        puVar30[0x9c] = 0;
        puVar30[0x9f] = (uint)((unsigned char *)0x00001040);
        puVar30[0x9e] = 0;
        puVar30[0xa0] = 0;
        puVar30[0x9d] = (uint)((unsigned char *)0x0000138e);
        puVar30[0x9a] = uVar42;
        puVar30[0xa1] = (uint)(*(unsigned char *)0x00001150);
        puVar30[0xa3] = (uint)((unsigned char *)0x00001100);
        uVar42 = *(uint *)(param_1 + 0x1f1c);
        puVar30[0xa5] = (uint)((unsigned char *)0x00001110);
        puVar30[0xa4] = uVar42;
        puVar30[0xa6] = *(uint *)(param_1 + 0x1f5c);
        puVar30[0xa7] = (uint)(*(unsigned char *)0x00001120);
        uVar42 = *(uint *)(param_1 + 0x1f9c);
        puVar30[0xa9] = (uint)((unsigned char *)0x00001130);
        puVar30[0xa8] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1fdc);
        puVar30[0xab] = (uint)((unsigned char *)0x00001140);
        puVar30[0xaa] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x201c);
        puVar30[0xad] = (uint)((unsigned char *)0x000010f4);
        puVar30[0xae] = 0xaaaa;
        puVar30[0xaf] = (uint)((unsigned char *)0x00001383);
        puVar30[0xac] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1d34);
        puVar30[0xb1] = (uint)((unsigned char *)0x00001386);
        puVar30[0xb0] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1d38);
        puVar30[0xb3] = 0x110f8;
        puVar30[0xb2] = uVar42;
        puVar30[0xb4] = *(uint *)(param_1 + 0x1d98);
        uVar42 = *(uint *)(param_1 + 0x1d50);
        puVar30[0xb6] = (uint)((unsigned char *)0x00001087);
        puVar30[0xb5] = uVar42;
        uVar42 = *(uint *)(param_1 + 0x1f0c);
        puVar30[0xb8] = 0x31080;
        puVar30[0xb7] = uVar42;
        puVar30[0xb9] = *(uint *)(param_1 + 0x1efc);
        puVar30[0xba] = *(uint *)(param_1 + 0x1f04);
        puVar30[0xbb] = *(uint *)(param_1 + 0x1f00);
        puVar30[0xbc] = *(uint *)(param_1 + 0x1f08);
        FUN_0004c100(puVar30 + 2,iVar34);
        puVar30[0xbf] = (uint)((unsigned char *)0x000013c4);
        puVar30[200] = (uint)((unsigned char *)0x000013ca);
        puVar30[0xc4] = (uint)((unsigned char *)0x000013cd);
        puVar30[0xc6] = (uint)((unsigned char *)0x000013cc);
        puVar30[0xc1] = 0x113c8;
        *(uint **)(param_1 + 0x298c) = puVar30 + 0xca;
                    
                    
        (**(code **)(param_1 + 0x299c))(iVar34);
        return;
      }
      FUN_00021c70(param_1,param_3,param_4,param_5,param_6,uVar42,uVar44,in_r10,uVar32);
    }
  }
  else {
    if (param_7 == 0x1801) {
      if ((*(uint *)(param_1 + 0x154) & 0x30000) == 0) {
        return;
      }
      if ((*(uint *)(param_1 + 0x154) & 0x20000) == 0) {
        iVar34 = param_5 << 1;
        puVar43 = ((unsigned char *)0x00001403);
        uVar32 = 0x1902;
      }
      else {
        iVar34 = param_5 << 2;
        puVar43 = ((unsigned char *)0x00001405);
        uVar32 = 0x1902;
      }
    }
    else if (param_7 == 0x1802) {
      if ((*(uint *)(param_1 + 0x154) & 0x30000) != 0x30000) {
        return;
      }
      puVar43 = ((unsigned char *)0x00001401);
      uVar32 = 0x1901;
      iVar34 = param_5;
    }
    else {
      if (param_7 != 0x1800) {
        return;
      }
      puVar43 = ((unsigned char *)0x00001401);
      uVar32 = 0x1908;
      iVar34 = param_5 << 2;
    }
    pvVar35 = _malloc(iVar34 * param_6);
    if (pvVar35 != (void *)0x0) {
      FUN_00029290(param_1,param_3,param_4,param_5,param_6,uVar32,puVar43,pvVar35,2,0);
      ((int (*)())FUN_000199a0)(param_1,param_2,param_5,param_6,uVar32,puVar43,pvVar35,1,0);
                    
                    
      (*(code *)PTR_FUN_001e8754)(pvVar35);
      return;
    }
  }
  return;
}

/* FUN_00018a40 @ 0x18a40 (3636 bytes) */
int FUN_00018a40(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  float *param_2;
  uint param_3;
  uint param_4;
  int param_5;
  undefined4 param_6;
  int param_7;
  int param_8;
  uint param_9;
{
  bool bVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  undefined *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  size_t sVar12;
  void *pvVar13;
  int iVar14;
  undefined4 uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  uint uVar26;
  int iVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  float *pfStack0000001c;
  undefined1 auStack_428 [4];
  int local_424;
  int local_420;
  int local_41c;
  undefined1 auStack_418 [4];
  undefined1 auStack_414 [4];
  void *local_410;
  int local_40c;
  undefined4 local_408;
  undefined4 local_404;
  undefined4 local_400;
  uint local_3fc;
  undefined4 local_3f8;
  uint local_3f4;
  uint local_3f0;
  float local_3ec;
  float local_3e8;
  uint local_3e4;
  uint local_3e0;
  uint local_3dc;
  undefined4 local_3d8;
  uint local_3d4;
  uint local_3d0;
  uint local_3cc;
  undefined4 local_3c8;
  uint local_3c4;
  uint local_3c0;
  uint local_3bc;
  undefined4 local_3b8;
  undefined1 local_3b4;
  float local_3b0;
  float local_3ac;
  uint local_144;
  longlong local_138;
  longlong local_130;
  longlong local_128;
  longlong local_120;
  longlong local_118;
  longlong local_110;
  longlong local_108;
  longlong local_100;
  longlong local_f8;
  longlong local_f0;
  longlong local_e8;
  longlong local_e0;
  undefined4 local_d8;
  uint uStack_d4;
  longlong local_d0;
  longlong local_c8;
  undefined4 local_c0;
  uint uStack_bc;
  longlong local_b8;
  longlong local_b0;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  undefined4 local_90;
  uint uStack_8c;
  longlong local_88;
  undefined4 local_80;
  uint uStack_7c;
  undefined4 local_78;
  uint uStack_74;
  undefined4 local_70;
  uint uStack_6c;
  int local_68;
  uint local_64;
  
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  iVar27 = *(int *)(param_1 + 0x10);
  local_64 = param_9 & 0xff;
  if ((((unsigned char *)0x00002d84)[iVar27] == '\0') ||
     (((((*(int *)(((unsigned char *)0x00002d68) + iVar27) == 0x10000 &&
         (*(int *)(((unsigned char *)0x00002d6c) + iVar27) == 0x10000)) &&
        (*(short *)(((unsigned char *)0x00002d80) + iVar27) != -0x7ff5)) &&
       (((*(short *)(((unsigned char *)0x00002d80) + iVar27) != -0x7ff9 &&
         (*(short *)(((unsigned char *)0x00002d82) + iVar27) != -0x7ff5)) &&
        (*(short *)(((unsigned char *)0x00002d82) + iVar27) != -0x7ff9)))) || (((unsigned char *)0x00002e33)[iVar27] != '\0')))) {
    uVar16 = *(uint *)(param_1 + 0x26b0) & 0xfffffffd;
    *(uint *)(param_1 + 0x26b0) = uVar16;
  }
  else {
    uVar16 = *(uint *)(param_1 + 0x26b0) | 2;
    *(uint *)(param_1 + 0x26b0) = uVar16;
  }
  if (((unsigned char *)0x00002d66)[iVar27] == '\0') {
    uVar16 = uVar16 & 0xfffffffe;
    *(uint *)(param_1 + 0x26b0) = uVar16;
  }
  else {
    uVar16 = uVar16 | 1;
    *(uint *)(param_1 + 0x26b0) = uVar16;
  }
  if ((*(uint *)(((unsigned char *)0x000030b4) + iVar27) & 0xcff1) == 0) {
    uVar16 = uVar16 & 0xfffff7ff;
    *(uint *)(param_1 + 0x26b0) = uVar16;
  }
  else {
    uVar16 = uVar16 | 0x800;
    *(uint *)(param_1 + 0x26b0) = uVar16;
  }
  if ((((unsigned char *)0x00002ddc)[iVar27] == '\0') || ((*(uint *)(param_1 + 0x154) & 0xf) != 3)) {
    uVar16 = uVar16 & 0xffffffdf;
    *(uint *)(param_1 + 0x26b0) = uVar16;
  }
  else {
    uVar16 = uVar16 | 0x20;
    *(uint *)(param_1 + 0x26b0) = uVar16;
  }
  if ((((*(uint *)(((unsigned char *)0x000031c0) + iVar27) & 1) == 0) || ((*(uint *)(param_1 + 0x154) & 0x80) == 0))
     || ((*(short *)(((unsigned char *)0x000031a0) + iVar27) == 0x207 &&
         (*(int *)(((unsigned char *)0x000031a4) + iVar27) == 0x1e001e00)))) {
    uVar16 = uVar16 & 0xfffeffff;
    *(uint *)(param_1 + 0x26b0) = uVar16;
  }
  else {
    uVar16 = uVar16 | 0x10000;
    *(uint *)(param_1 + 0x26b0) = uVar16;
  }
  if ((((unsigned char *)0x00002dc8)[iVar27] == '\0') || ((*(uint *)(param_1 + 0x154) & 0x40) == 0)) {
    uVar16 = uVar16 & 0xffffffef;
    *(uint *)(param_1 + 0x26b0) = uVar16;
  }
  else {
    uVar16 = uVar16 | 0x10;
    *(uint *)(param_1 + 0x26b0) = uVar16;
  }
  if (((unsigned char *)0x00002e0a)[iVar27] == '\0') {
    *(uint *)(param_1 + 0x26b0) = uVar16 & 0xffffffbf;
  }
  else {
    *(uint *)(param_1 + 0x26b0) = uVar16 | 0x40;
  }
  uVar16 = param_3;
  uVar11 = param_4;
  iVar22 = param_5;
  uVar15 = param_6;
  pfStack0000001c = param_2;
  if (((((((*(int *)(param_1 + 0x18c) == 0) || (iVar10 = FUN_000a4760(param_1), iVar10 == 0)) &&
         ((*(int *)(param_1 + 400) == 0 || (iVar10 = FUN_000a4760(param_1), iVar10 == 1)))) &&
        ((*(int *)(param_1 + 0x194) == 0 || (iVar10 = FUN_000a4760(param_1), iVar10 == 2)))) &&
       ((*(int *)(param_1 + 0x198) == 0 || (iVar10 = FUN_000a4760(param_1), iVar10 == 3)))) &&
      (((*(int *)(param_1 + 0x19c) == 0 || (iVar10 = FUN_000a4760(param_1), iVar10 == 4)) &&
       ((*(int *)(param_1 + 0x1a0) == 0 || (iVar10 = FUN_000a4760(param_1), iVar10 == 5)))))) &&
     (((*(int *)(param_1 + 0x1a4) == 0 || (iVar10 = FUN_000a4760(param_1), iVar10 == 6)) &&
      ((*(int *)(param_1 + 0x1a8) == 0 || (iVar10 = FUN_000a4760(param_1), iVar10 == 7)))))) {
    uVar17 = *(uint *)(param_1 + 0x26b0) & 0xfffdffff;
    *(uint *)(param_1 + 0x26b0) = uVar17;
  }
  else {
    uVar17 = *(uint *)(param_1 + 0x26b0) | 0x20000;
    *(uint *)(param_1 + 0x26b0) = uVar17;
  }
  if (((unsigned char *)0x00002e33)[iVar27] == '\0') {
    uVar17 = uVar17 & 0xfffffdff;
    *(uint *)(param_1 + 0x26b0) = uVar17;
  }
  else {
    uVar17 = uVar17 | 0x200;
    *(uint *)(param_1 + 0x26b0) = uVar17;
  }
  if ((((((unsigned char *)0x00002e43)[iVar27] == '\0') || (((unsigned char *)0x00002e40)[iVar27] == '\0')) ||
      (((unsigned char *)0x00002e41)[iVar27] == '\0')) || (((unsigned char *)0x00002e42)[iVar27] == '\0')) {
    *(uint *)(param_1 + 0x26b0) = uVar17 | 0x400;
  }
  else {
    *(uint *)(param_1 + 0x26b0) = uVar17 & 0xfffffbff;
  }
  if (param_3 == 0) {
    return;
  }
  if (param_4 == 0) {
    return;
  }
  iVar27 = *(int *)(param_1 + 0x10);
  if (((unsigned char *)0x00003190)[iVar27] != '\0') {
    if (*(int *)(((unsigned char *)0x00003188) + iVar27) == 0) {
      return;
    }
    if (*(int *)(((unsigned char *)0x0000318c) + iVar27) == 0) {
      return;
    }
    if (*(int *)(param_1 + 0x15c) <= *(int *)(((unsigned char *)0x00003180) + iVar27)) {
      return;
    }
    if (*(int *)(((unsigned char *)0x00003188) + iVar27) + *(int *)(((unsigned char *)0x00003180) + iVar27) < 1) {
      return;
    }
    if (*(int *)(param_1 + 0x160) <= *(int *)(((unsigned char *)0x00003184) + iVar27)) {
      return;
    }
    if (*(int *)(((unsigned char *)0x0000318c) + iVar27) + *(int *)(((unsigned char *)0x00003184) + iVar27) < 1) {
      return;
    }
  }
  bVar1 = local_64 != 0;
  if (((!bVar1) && ((*(uint *)(param_1 + 0x26b0) & 0x30e73) == 0)) &&
     ((1 < param_5 - 0x1901U &&
      (((*(uint *)(((unsigned char *)0x000030b0) + iVar27) & 0x1ff) == 0 &&
       ((*(uint *)(((unsigned char *)0x000030b4) + iVar27) & 0xff0000) == 0)))))) {
    FUN_0001a010(param_1,*(undefined4 *)(param_1 + 0x26a0),uVar16,uVar11,iVar22,uVar15,iVar27);
  }
  local_3e8 = 0.0;
  local_3fc = 0;
  local_3f8 = 0x7ffff;
  local_3ec = 0.0;
  puVar8 = (undefined *)0x0;
  if (param_8 == 0) {
    iVar27 = *(int *)(param_1 + 0x10);
    puVar8 = ((unsigned char *)0x00002e6c) + iVar27;
    local_3fc = (uint)(((unsigned char *)0x00002e84)[iVar27] != '\0');
    if (((unsigned char *)0x00002e85)[iVar27] != '\0') {
      local_3fc = local_3fc | 4;
    }
  }
  bVar2 = param_5 != 0x1901;
  ((int (*)())FUN_0000a6e0)(param_1,param_5,param_6,param_3,param_4,&local_41c,auStack_428,&local_424,puVar8);
  ((int (*)())FUN_0000a3f0)(param_5,param_6);
  _glgConvertType(param_5,param_6,auStack_418,auStack_414);
  dVar7 = DOUBLE_001aa1e0;
  if (bVar2) {
    if (param_5 == 0x1902) {
      local_408 = 0xd;
      local_404 = 7;
    }
    else {
      local_408 = 6;
      local_404 = 0x11;
    }
  }
  else {
    local_408 = 0xe;
    local_404 = 0;
  }
  local_3ec = *pfStack0000001c;
  local_400 = 2;
  fVar4 = local_3ec * *(float *)(param_1 + 0x2a54);
  fVar5 = fVar4 + FLOAT_001aa10c;
  dVar29 = (double)fVar5;
  if ((double)FLOAT_001aa0d4 <= dVar29) {
    iVar27 = (int)fVar5;
    local_130 = (longlong)iVar27;
  }
  else {
    iVar27 = (int)(dVar29 - (double)FLOAT_001aa118);
    local_138 = (longlong)iVar27;
  }
  if (((unsigned char *)0x00002b7c)[param_1] == '\0') {
    fVar3 = *(float *)(param_1 + 0x2a58);
    local_3e8 = pfStack0000001c[1];
    fVar6 = local_3e8 * fVar3 + FLOAT_001aa10c;
    if (FLOAT_001aa0d4 <= fVar6) {
      uVar16 = (uint)fVar6;
      local_110 = (longlong)(int)uVar16;
    }
    else {
      uVar16 = (uint)(fVar6 - FLOAT_001aa118);
      local_118 = (longlong)(int)uVar16;
    }
  }
  else {
    fVar3 = *(float *)(param_1 + 0x2a58);
    local_3e8 = pfStack0000001c[1];
    fVar6 = local_3e8 * fVar3 - FLOAT_001aa10c;
    if (FLOAT_001aa0d4 <= fVar6) {
      uVar16 = (uint)fVar6;
      local_120 = (longlong)(int)uVar16;
    }
    else {
      uVar16 = (uint)(fVar6 + FLOAT_001aa118);
      local_128 = (longlong)(int)uVar16;
    }
  }
  dVar31 = (double)(fVar3 * *(float *)(((unsigned char *)0x00002e4c) + *(int *)(param_1 + 0x10)));
  dVar28 = (double)(*(float *)(param_1 + 0x2a54) *
                   *(float *)(((unsigned char *)0x00002e48) + *(int *)(param_1 + 0x10)));
  if (bVar2) {
    iVar22 = 4;
  }
  else {
    iVar22 = 1;
  }
  if ((dVar28 == (double)FLOAT_001aa0e8) && (dVar31 == (double)FLOAT_001aa0e8)) {
    iVar24 = iVar22 * param_3;
    local_3e8 = 0.0;
    local_3ec = 0.0;
    sVar12 = param_4 * iVar24;
    iVar10 = 1;
    local_68 = 1;
    uVar17 = param_3;
    uVar11 = param_4;
    goto LAB_000194f4;
  }
  fVar3 = fVar3 * local_3e8;
  dVar30 = (double)FLOAT_001aa0d4;
  if (dVar28 < dVar30) {
    dVar28 = -dVar28;
    fVar4 = fVar4 - FLOAT_001aa10c;
    dVar29 = (double)fVar4;
    if (dVar30 <= dVar29) {
      iVar27 = (int)fVar4;
      local_f0 = (longlong)iVar27;
      iVar10 = -1;
    }
    else {
      iVar10 = -1;
      iVar27 = (int)(dVar29 + (double)FLOAT_001aa118);
      local_f8 = (longlong)iVar27;
    }
  }
  else if (dVar30 <= dVar29) {
    iVar27 = (int)fVar5;
    local_100 = (longlong)iVar27;
    iVar10 = 1;
  }
  else {
    iVar10 = 1;
    iVar27 = (int)(dVar29 + (double)FLOAT_001aa118);
    local_108 = (longlong)iVar27;
  }
  if (((unsigned char *)0x00002b7c)[param_1] == '\0') {
    dVar29 = (double)FLOAT_001aa0d4;
    if (dVar31 < dVar29) {
      dVar31 = -dVar31;
      dVar30 = (double)(fVar3 - FLOAT_001aa10c);
      if (dVar29 <= dVar30) {
        uVar16 = (uint)(fVar3 - FLOAT_001aa10c);
        local_a0 = (longlong)(int)uVar16;
        iVar10 = -1;
        local_68 = 1;
      }
      else {
        iVar10 = -1;
        local_68 = 1;
        uVar16 = (uint)(dVar30 + (double)FLOAT_001aa118);
        local_a8 = (longlong)(int)uVar16;
      }
    }
    else {
      dVar30 = (double)(fVar3 + FLOAT_001aa10c);
      if (dVar29 <= dVar30) {
        uVar16 = (uint)(fVar3 + FLOAT_001aa10c);
        local_b0 = (longlong)(int)uVar16;
        local_68 = 1;
      }
      else {
        local_68 = 1;
        uVar16 = (uint)(dVar30 + (double)FLOAT_001aa118);
        local_b8 = (longlong)(int)uVar16;
      }
    }
  }
  else {
    dVar29 = (double)FLOAT_001aa0d4;
    if (dVar31 < dVar29) {
      dVar31 = -dVar31;
      dVar30 = (double)(fVar3 + FLOAT_001aa10c);
      if (dVar29 <= dVar30) {
        uVar16 = (uint)(fVar3 + FLOAT_001aa10c);
        local_c8 = (longlong)(int)uVar16;
      }
      else {
        uVar16 = (uint)(dVar30 + (double)FLOAT_001aa118);
        local_d0 = (longlong)(int)uVar16;
      }
      uStack_bc = uVar16 ^ 0x80000000;
      local_c0 = 0x43300000;
      local_68 = -1;
      if ((float)(dVar30 - (double)(float)((double)CONCAT44(0x43300000,uStack_bc) - DOUBLE_001aa1e0)
                 ) == FLOAT_001aa0d4) goto LAB_0001931c;
    }
    else {
      dVar30 = (double)(fVar3 - FLOAT_001aa10c);
      if (dVar29 <= dVar30) {
        uVar16 = (uint)(fVar3 - FLOAT_001aa10c);
        local_e0 = (longlong)(int)uVar16;
      }
      else {
        uVar16 = (uint)(dVar30 + (double)FLOAT_001aa118);
        local_e8 = (longlong)(int)uVar16;
      }
      uStack_d4 = uVar16 ^ 0x80000000;
      local_d8 = 0x43300000;
      local_68 = 1;
      if ((float)((double)(float)((double)CONCAT44(0x43300000,uStack_d4) - DOUBLE_001aa1e0) - dVar30
                 ) + FLOAT_001aa0e8 == FLOAT_001aa0e8) {
LAB_0001931c:
        uVar16 = uVar16 - 1;
      }
    }
  }
  local_98 = (longlong)(int)local_3ec;
  local_88 = (longlong)(int)local_3e8;
  uStack_74 = param_3 ^ 0x80000000;
  local_90 = 0x43300000;
  local_78 = 0x43300000;
  local_80 = 0x43300000;
  uStack_8c = (int)local_3ec ^ 0x80000000;
  uStack_7c = (int)local_3e8 ^ 0x80000000;
  local_3ec = local_3ec - (float)((double)CONCAT44(0x43300000,uStack_8c) - DOUBLE_001aa1e0);
  local_3e8 = local_3e8 - (float)((double)CONCAT44(0x43300000,uStack_7c) - DOUBLE_001aa1e0);
  uVar17 = _glgPixelCenters((double)local_3ec,
                            (double)(float)(dVar28 * (double)(float)((double)CONCAT44(0x43300000,
                                                                                      uStack_74) -
                                                                    DOUBLE_001aa1e0) +
                                           (double)local_3ec),dVar28);
  uStack_6c = param_4 ^ 0x80000000;
  local_70 = 0x43300000;
  iVar24 = iVar22 * uVar17;
  uVar11 = _glgPixelCenters((double)local_3e8,
                            (double)(float)(dVar31 * (double)(float)((double)CONCAT44(0x43300000,
                                                                                      uStack_6c) -
                                                                    dVar7) + (double)local_3e8),
                            dVar31);
  sVar12 = uVar11 * iVar24;
LAB_000194f4:
  pvVar13 = _malloc(sVar12);
  if (pvVar13 != (void *)0x0) {
    local_3b4 = 1;
    local_3f0 = param_4;
    local_3f4 = param_3;
    local_420 = param_7 + local_424;
    local_410 = pvVar13;
    local_40c = iVar24;
    if (bVar1) {
      _glgProcessPixels(0,&local_420);
    }
    else {
      iVar14 = *(int *)(param_1 + 0x10);
      if (((((*(uint *)(((unsigned char *)0x000030b0) + iVar14) & 0x1ff) != 0) ||
           ((*(uint *)(((unsigned char *)0x000030b4) + iVar14) & 0xff0000) != 0)) && (bVar2)) && (param_5 != 0x1902)
         ) {
        if ((*(uint *)(((unsigned char *)0x000030b0) + iVar14) & 2) == 0) {
          if (((*(uint *)(((unsigned char *)0x000030b0) + iVar14) & 4) != 0) &&
             (*(short *)(((unsigned char *)0x00002fe8) + iVar14) == -0x7fea)) {
            uVar11 = (uVar11 - *(int *)(((unsigned char *)0x00002ff4) + iVar14)) + 1;
            uVar17 = (uVar17 - *(int *)(((unsigned char *)0x00002ff0) + iVar14)) + 1;
          }
        }
        else if (*(short *)(((unsigned char *)0x00002fa8) + iVar14) == -0x7fea) {
          uVar11 = (uVar11 - *(int *)(((unsigned char *)0x00002fb4) + iVar14)) + 1;
          uVar17 = (uVar17 - *(int *)(((unsigned char *)0x00002fb0) + iVar14)) + 1;
        }
        iVar20 = *(int *)(param_1 + 0x18);
        iVar18 = *(int *)(*(int *)(iVar20 + 0x140) + 0x30);
        local_3e4 = (uint)*(ushort *)(iVar18 + 0x98);
        local_3e0 = (uint)*(ushort *)(iVar18 + 0x9a);
        local_3dc = (uint)*(ushort *)(iVar18 + 0x8c);
        local_3d8 = *(undefined4 *)(iVar18 + 0x9c);
        iVar18 = *(int *)(*(int *)(iVar20 + 0x148) + 0x30);
        local_3d4 = (uint)*(ushort *)(iVar18 + 0x98);
        local_3d0 = (uint)*(ushort *)(iVar18 + 0x9a);
        local_3cc = (uint)*(ushort *)(iVar18 + 0x8c);
        local_3c8 = *(undefined4 *)(iVar18 + 0x9c);
        iVar18 = *(int *)(*(int *)(iVar20 + 0x144) + 0x30);
        local_3c4 = (uint)*(ushort *)(iVar18 + 0x98);
        local_3c0 = (uint)*(ushort *)(iVar18 + 0x9a);
        local_3bc = (uint)*(ushort *)(iVar18 + 0x8c);
        local_3b8 = *(undefined4 *)(iVar18 + 0x9c);
      }
      fVar4 = *(float *)(((unsigned char *)0x00002e48) + iVar14) * *(float *)(param_1 + 0x2a54);
      fVar5 = *(float *)(((unsigned char *)0x00002e4c) + iVar14) * *(float *)(param_1 + 0x2a58);
      _memcpy(&local_3b0,((unsigned char *)0x00002e48) + iVar14,0x274);
      uVar9 = 0x4000;
      if (fVar4 == FLOAT_001aa0e8) {
        uVar9 = 0;
      }
      local_144 = (uint)(fVar5 != FLOAT_001aa0e8) << 0xf | uVar9 | local_144 & 0xffff3fff;
      local_3b0 = fVar4;
      local_3ac = fVar5;
      _glgProcessPixels(&local_3b0,&local_420);
    }
    local_41c = iVar24;
    if (((unsigned char *)0x00002b7c)[param_1] != '\0') {
      local_41c = -iVar24;
    }
    uVar9 = uVar17;
    if (0x7fe < uVar17) {
      uVar9 = 0x7fe;
    }
    uVar25 = 0x7fe / uVar9;
    if (uVar11 < 0x7fe / uVar9) {
      uVar25 = uVar11;
    }
    uVar19 = uVar17 / uVar9;
    uVar21 = uVar11 / uVar25;
    uVar17 = uVar17 - uVar19 * uVar9;
    uVar11 = uVar11 - uVar21 * uVar25;
    uVar23 = uVar19 + 1;
    if (uVar17 == 0) {
      uVar17 = uVar9;
      uVar23 = uVar19;
    }
    uVar19 = uVar21 + 1;
    if (uVar11 == 0) {
      uVar11 = uVar25;
      uVar19 = uVar21;
    }
    if (uVar19 != 0) {
      uVar21 = 0;
      do {
        if (uVar23 != 0) {
          iVar14 = uVar25 * uVar21;
          uVar26 = 0;
          iVar24 = local_68 * iVar14;
          do {
            local_3f0 = uVar25;
            if (uVar21 == uVar19 - 1) {
              local_3f0 = uVar11;
            }
            local_3f4 = uVar17;
            if (uVar26 != uVar23 - 1) {
              local_3f4 = uVar9;
            }
            iVar18 = uVar26 * uVar9;
            if (((unsigned char *)0x00002b7c)[param_1] == '\0') {
              local_420 = iVar14 * local_41c + iVar22 * iVar18;
              iVar20 = iVar24;
            }
            else {
              iVar20 = iVar14 + local_3f0 + -1;
              local_420 = iVar22 * iVar18 - local_41c * iVar20;
              iVar20 = -(local_68 * iVar20);
            }
            local_420 = local_420 + (int)pvVar13;
            uVar26 = uVar26 + 1;
            FUN_00029c00(param_1,local_420,local_3f4,local_3f0,local_41c,iVar22,
                         iVar27 + iVar10 * iVar18,uVar16 + iVar20,pfStack0000001c,param_5,local_64);
          } while (uVar23 != uVar26);
        }
        uVar21 = uVar21 + 1;
      } while (uVar19 != uVar21);
    }
    _free(pvVar13);
  }
  return;
}

/* FUN_000198b0 @ 0x198b0 (228 bytes) */
int FUN_000198b0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint param_2;
  uint param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint uVar1;
  float fStack_128;
  float fStack_124;
  undefined4 uStack_120;
  undefined4 uStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  uStack_24 = param_2 ^ 0x80000000;
  uStack_28 = 0x43300000;
  fStack_128 = (float)((double)CONCAT44(0x43300000,uStack_24) - DOUBLE_001aa1e0);
  if (((unsigned char *)0x00002b7c)[param_1] == '\0') {
    uStack_14 = param_3 ^ 0x80000000;
    uStack_18 = 0x43300000;
    uVar1 = uStack_14;
  }
  else {
    uStack_20 = 0x43300000;
    uStack_1c = *(int *)(param_1 + 0x160) - param_3 ^ 0x80000000;
    uVar1 = uStack_1c;
  }
  fStack_124 = (float)((double)CONCAT44(0x43300000,uVar1) - DOUBLE_001aa1e0);
  uStack_120 = 0;
  ((int (*)())FUN_00018a40)(param_1,&fStack_128,param_4,param_5,0x80e1,param_6,param_7,1,1);
  return;
}

/* FUN_000199a0 @ 0x199a0 (68 bytes) */
int FUN_000199a0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  int param_9;
{
  undefined4 uVar1;
  
  if (param_9 == 0) {
    ((int (*)())FUN_00018a40)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,0);
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_0002a3d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  return uVar1;
}

/* FUN_000199f0 @ 0x199f0 (212 bytes) */
int FUN_000199f0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 != 0) {
    iVar2 = ((int (*)())FUN_00016fc0)((uint)*(ushort *)(((unsigned char *)0x00002dba) + *(int *)(param_1 + 0x10)),
                         *(undefined4 *)(param_1 + 0x154));
    uVar1 = *(uint *)(param_1 + 0x154);
    if (((((uVar1 & 0x20) == 0) && (((uVar1 & 0x10) != 0 || ((uVar1 & 0x400) == 0)))) ||
        ((iVar2 != 0 && ((iVar2 != 1 || ((uVar1 & 0x400) != 0)))))) ||
       (((uVar1 & 0x70000000) != 0 ||
        (((uVar3 = 6, param_2 < 6 && (uVar3 = 4, param_2 < 4)) && (uVar3 = 2, param_2 < 2)))))) {
      uVar3 = 1;
    }
    *(undefined4 *)(param_1 + 0x2a50) = uVar3;
    *(undefined1 *)(param_1 + 0x2a5d) = 1;
    *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
    *(undefined1 *)(param_1 + 0x2a5c) = 1;
  }
  return;
}

/* FUN_00019ad0 @ 0x19ad0 (360 bytes) */
int FUN_00019ad0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return;
  }
  iVar2 = ((int (*)())FUN_00016fc0)((uint)*(ushort *)(((unsigned char *)0x00002dba) + *(int *)(param_1 + 0x10)),
                       *(undefined4 *)(param_1 + 0x154));
  uVar1 = *(uint *)(param_1 + 0x154);
  if (((((uVar1 & 0x20) == 0) && (((uVar1 & 0x10) != 0 || ((uVar1 & 0x400) == 0)))) ||
      ((iVar2 != 0 && ((iVar2 != 1 || ((uVar1 & 0x400) != 0)))))) || ((uVar1 & 0x70000000) != 0)) {
LAB_00019b60:
    *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
    *(undefined1 *)(param_1 + 0x2a5d) = 1;
    *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
    *(undefined1 *)(param_1 + 0x2a5c) = 1;
  }
  else {
    if (param_2 < 4) {
      if (param_2 < 2) goto LAB_00019b60;
      *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
      *(undefined1 *)(param_1 + 0x2a5c) = 1;
      if (0x1000 < *(int *)(param_1 + 0x160) << 1) {
        *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
        *(undefined1 *)(param_1 + 0x2a5d) = 1;
        goto LAB_00019be0;
      }
    }
    else {
      if (*(int *)(param_1 + 0x15c) << 1 < 0x1001) {
        *(undefined4 *)(param_1 + 0x2a54) = 0x40000000;
        *(undefined1 *)(param_1 + 0x2a5c) = 2;
      }
      else {
        *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
        *(undefined1 *)(param_1 + 0x2a5c) = 1;
      }
      if (0x1000 < *(int *)(param_1 + 0x160) << 1) {
        *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
        *(undefined1 *)(param_1 + 0x2a5d) = 1;
        goto LAB_00019be0;
      }
    }
    *(undefined4 *)(param_1 + 0x2a58) = 0x40000000;
    *(undefined1 *)(param_1 + 0x2a5d) = 2;
  }
LAB_00019be0:
  *(undefined4 *)(param_1 + 0x2a50) = 1;
  return;
}

