#include "decls.h"

/* FUN_00014b91 @ 0x14b91 (215 bytes) */
int FUN_00014b91(param_1, param_2)
  uint param_1;
  uint param_2;
{
  if (param_1 != 0x405) {
    if (param_1 < 0x406) {
      if (param_1 == 0x401) {
LAB_00014c12:
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
        if (param_1 == 0x407) goto LAB_00014c12;
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

/* FUN_00014c68 @ 0x14c68 (90 bytes) */
int FUN_00014c68(param_1, param_2, param_3)
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

/* FUN_00014cc2 @ 0x14cc2 (224 bytes) */
int FUN_00014cc2(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *param_2 & 0x80ffffff;
  *param_2 = uVar3;
  if (param_3 == 0) {
    *(undefined1 *)(param_1 + 0x143) = 1;
  }
  else {
    iVar1 = *(int *)(param_3 + 0xc);
    if (iVar1 - 0xde0U < 2) {
      uVar3 = uVar3 | 0x10000000;
      *param_2 = uVar3;
    }
    else if (iVar1 == 0x84f5) {
      uVar3 = uVar3 | 0x20000000;
      *param_2 = uVar3;
    }
    else if (iVar1 == 0x8513) {
      uVar3 = uVar3 | 0x30000000;
      *param_2 = uVar3;
    }
    if (*(int *)(param_3 + 0x14) < 0xd) {
      uVar2 = *(int *)(param_3 + 0x14) << 0x18;
    }
    else {
      uVar2 = 0xc000000;
    }
    *param_2 = uVar2 & 0xf000000 | uVar3;
    *(undefined1 *)(param_1 + 0x143) = 0;
  }
  if (*(int *)(param_1 + 0x150) == 0) {
    if (param_3 != 0) {
      **(uint **)(param_1 + 0x14) = **(uint **)(param_1 + 0x14) & 0xfffffffd;
      *(undefined1 *)(param_1 + 0x2b7c) = 0;
      FUN_000a5df1();
      return;
    }
    **(uint **)(param_1 + 0x14) = **(uint **)(param_1 + 0x14) | 2;
    *(undefined1 *)(param_1 + 0x2b7c) = 1;
  }
  FUN_000a5df1();
  return;
}

/* FUN_00014da2 @ 0x14da2 (143 bytes) */
int FUN_00014da2(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x150) == 0) {
    uVar3 = FUN_0002d168(*(undefined4 *)(param_1 + 0x154));
    *(undefined1 *)(param_1 + 0x2b7f) = uVar3;
  }
  else {
    *(undefined1 *)(param_1 + 0x2b7f) = 0x2f;
    iVar5 = **(int **)(param_1 + 0x150);
    iVar4 = 4;
    do {
      if (*(ushort *)(iVar5 + 0x90) != 0) {
        iVar1 = *(ushort *)(iVar5 + 0x90) - 0x8ce0;
        iVar2 = (*(int **)(param_1 + 0x150))[1];
        if (*(int *)(iVar2 + iVar1 * 4) != 0) {
          *(undefined1 *)(param_1 + 0x2b7f) = *(undefined1 *)(*(int *)(iVar2 + iVar1 * 4) + 0x38);
          break;
        }
      }
      iVar5 = iVar5 + 2;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  FUN_000a5df1();
  return;
}

/* FUN_00014e31 @ 0x14e31 (1092 bytes) */
int FUN_00014e31(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 *param_3;
{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *local_20;
  int local_18;
  uint local_14;
  undefined4 local_10;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x271e;
  }
  if (param_2 != 0x132) {
    if (param_2 < 0x133) {
      if (param_2 == 300) {
        puVar4 = *(undefined4 **)(param_1 + 0x1dc);
        if (*(undefined4 **)(param_1 + 0x1e0) <= puVar4 + 6) {
          ((int (*)())FUN_00017c77)(param_1,0x1000000);
          puVar4 = *(undefined4 **)(param_1 + 0x1dc);
        }
        *(undefined4 **)(param_1 + 0x1dc) = puVar4 + 6;
        *puVar4 = 0x1040;
        puVar4[1] = 0;
        puVar4[2] = 0x1393;
        puVar4[3] = 10;
        puVar4[4] = 0x5c8;
        puVar4[5] = 0x20000;
        return 0;
      }
    }
    else {
      if (param_2 == 0x1fe) {
        if ((*(int *)(param_1 + 0xf8) != 0) && (*(int *)(param_1 + 0x2a84) == 0)) {
          uVar3 = ((int (*)())FUN_000179c6)(param_1,*param_3,1);
          return uVar3;
        }
        return 0;
      }
      if (param_2 == 0x29b) {
        if (*(uint *)(param_1 + 0x1e0) <= *(int *)(param_1 + 0x1dc) + 0x60U) {
          ((int (*)())FUN_00017c77)(param_1,0x1000000);
        }
        iVar5 = *(int *)(param_1 + 500);
        uVar2 = *(uint *)(param_1 + 0x1f8);
        if (uVar2 <= iVar5 + 0x800U) {
          local_10 = 2;
          uVar2 = *(int *)(param_1 + 0x204) + 1;
          *(uint *)(param_1 + 0x204) = uVar2;
          if (2 < uVar2) {
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              ((int (*)())FUN_00017c77)(param_1,0x1000000);
              iVar5 = *(int *)(param_1 + 500);
            }
            *(undefined4 *)(param_1 + 0x204) = 1;
          }
          *(int *)(*(int *)(param_1 + 0x208) + 0xc) = iVar5 - *(int *)(param_1 + 0x1fc) >> 2;
          _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(param_1 + 4),0x12,0,0,&local_18,&local_10);
          *(int *)(param_1 + 0x1fc) = local_18;
          *(int *)(param_1 + 500) = local_18;
          uVar2 = local_18 + (local_14 & 0xfffffffc);
          *(uint *)(param_1 + 0x1f8) = uVar2;
          *(undefined4 *)(param_1 + 0x200) = *(undefined4 *)(*(int *)(param_1 + 0x208) + 8);
          *(uint *)(param_1 + 0x26c8) = *(uint *)(param_1 + 0x26c8) | 1;
          iVar5 = local_18;
        }
        local_20 = &local_18;
        if (uVar2 <= iVar5 + 800U) {
          local_10 = 2;
          uVar2 = *(int *)(param_1 + 0x204) + 1;
          *(uint *)(param_1 + 0x204) = uVar2;
          if (2 < uVar2) {
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              ((int (*)())FUN_00017c77)(param_1,0x1000000);
              iVar5 = *(int *)(param_1 + 500);
            }
            *(undefined4 *)(param_1 + 0x204) = 1;
          }
          *(int *)(*(int *)(param_1 + 0x208) + 0xc) = iVar5 - *(int *)(param_1 + 0x1fc) >> 2;
          _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(param_1 + 4),0x12,0,0,local_20,&local_10);
          *(int *)(param_1 + 0x1fc) = local_18;
          *(int *)(param_1 + 500) = local_18;
          *(uint *)(param_1 + 0x1f8) = local_18 + (local_14 & 0xfffffffc);
          *(undefined4 *)(param_1 + 0x200) = *(undefined4 *)(*(int *)(param_1 + 0x208) + 8);
          *(uint *)(param_1 + 0x26c8) = *(uint *)(param_1 + 0x26c8) | 1;
          iVar5 = local_18;
        }
        iVar5 = iVar5 + 800;
        *(int *)(param_1 + 500) = iVar5;
        local_10 = 2;
        uVar2 = *(int *)(param_1 + 0x204) + 1;
        *(uint *)(param_1 + 0x204) = uVar2;
        if (2 < uVar2) {
          if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
            ((int (*)())FUN_00017c77)(param_1,0x1000000);
            iVar5 = *(int *)(param_1 + 500);
          }
          *(undefined4 *)(param_1 + 0x204) = 1;
        }
        *(int *)(*(int *)(param_1 + 0x208) + 0xc) = iVar5 - *(int *)(param_1 + 0x1fc) >> 2;
        _io_connect_method_scalarI_scalarO(*(undefined4 *)(param_1 + 4),0x12,0,0,local_20,&local_10)
        ;
        *(int *)(param_1 + 0x1fc) = local_18;
        *(int *)(param_1 + 500) = local_18;
        *(uint *)(param_1 + 0x1f8) = local_18 + (local_14 & 0xfffffffc);
        *(undefined4 *)(param_1 + 0x200) = *(undefined4 *)(*(int *)(param_1 + 0x208) + 8);
        *(uint *)(param_1 + 0x26c8) = *(uint *)(param_1 + 0x26c8) | 1;
        return 0;
      }
    }
    return 0x271a;
  }
  puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  if (*(undefined4 **)(param_1 + 0x1e0) <= puVar4 + 4) {
    ((int (*)())FUN_00017c77)(param_1,0x1000000);
    puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  }
  *(undefined4 **)(param_1 + 0x1dc) = puVar4 + 4;
  puVar1 = *(uint **)(param_1 + 0x1d8);
  *puVar1 = *puVar1 | (int)puVar4 - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x1d8) = puVar4;
  *puVar4 = 0x3d000000;
  puVar4[1] = 0x132;
  puVar4[2] = *param_3;
  puVar4[3] = 0;
  return 0;
}

/* FUN_00015275 @ 0x15275 (22 bytes) */
int FUN_00015275(param_1)
  undefined4 param_1;
{
  FUN_000384a8(param_1);
  return;
}

/* FUN_0001528b @ 0x1528b (869 bytes) */
int FUN_0001528b(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  undefined4 uVar1;
  short local_28;
  short local_26;
  short local_24;
  short local_22;
  short local_20;
  
  *param_2 = 10;
  param_2[3] = 0x1000;
  param_2[4] = 0x1000;
  param_2[5] = 4;
  param_2[6] = 4;
  param_2[7] = 0x20;
  param_2[8] = 0x20;
  param_2[1] = 0x3f800000;
  param_2[2] = 3;
  param_2[0x18] = 0x3f800000;
  param_2[0x19] = 0x42800000;
  param_2[0x1a] = 0x3e000000;
  param_2[0x1b] = 0x3f800000;
  param_2[0x1c] = 0x42800000;
  param_2[0x1d] = 0x3e000000;
  param_2[0x28] = 0x80;
  param_2[0x29] = 0x80;
  param_2[0x2a] = 0x20;
  *(undefined1 *)(param_2 + 0x1e) = 1;
  *(undefined1 *)((int)param_2 + 0x79) = 1;
  *(undefined1 *)((int)param_2 + 0x7a) = 1;
  *(undefined1 *)((int)param_2 + 0x7b) = 1;
  *(bool *)(param_2 + 9) = (*(uint *)(param_3 + 0x10) & 0x3ffffffc) != 0;
  *(byte *)((int)param_2 + 0x25) = (byte)(*(uint *)(param_3 + 0xc) >> 3) & 1;
  *(byte *)((int)param_2 + 0x26) = (byte)(*(uint *)(param_3 + 0xc) >> 1) & 1;
  *(bool *)((int)param_2 + 0x27) = (*(uint *)(param_3 + 0x10) & 0x3f000000) != 0;
  FUN_00009165(*(undefined4 *)(param_3 + 0x10),&local_28);
  param_2[0xb] = (int)local_28;
  param_2[0xc] = (int)local_26;
  param_2[0xd] = (int)local_24;
  param_2[0xe] = (int)local_22;
  param_2[10] = (int)local_20;
  FUN_00009165(*(undefined4 *)(param_3 + 0x14),&local_28);
  param_2[0x11] = (int)local_28;
  param_2[0x12] = (int)local_26;
  param_2[0x13] = (int)local_24;
  param_2[0x14] = (int)local_22;
  uVar1 = FUN_000090c8(*(undefined4 *)(param_3 + 0x18));
  param_2[0xf] = uVar1;
  uVar1 = FUN_000090c8(*(undefined4 *)(param_3 + 0x1c));
  param_2[0x10] = uVar1;
  param_2[0x15] = (int)*(short *)(param_3 + 0x22);
  param_2[0x16] = (int)*(short *)(param_3 + 0x24);
  param_2[0x17] = (int)*(short *)(param_3 + 0x26);
  *(undefined2 *)(param_2 + 0x1f) = 3;
  *(undefined2 *)((int)param_2 + 0x7e) = 2;
  *(undefined2 *)(param_2 + 0x20) = 1;
  *(undefined2 *)((int)param_2 + 0x82) = 6;
  *(undefined2 *)(param_2 + 0x21) = 5;
  *(undefined2 *)((int)param_2 + 0x86) = 4;
  param_2[0x25] = param_2[0x25] | 4;
  param_2[0x47] = 0;
  param_2[0x48] = 0;
  param_2[0x26] = 0;
  param_2[0x22] = 0x800;
  param_2[0x23] = 0xffff;
  param_2[0x24] = 4;
  *(undefined2 *)(param_2 + 0x2d) = 8;
  *(undefined2 *)((int)param_2 + 0xb6) = 0x10;
  *(undefined2 *)(param_2 + 0x2e) = 0;
  *(undefined2 *)((int)param_2 + 0xba) = 8;
  param_2[0x2b] = 0x41800000;
  param_2[0x2c] = 0x41800000;
  *(undefined2 *)(param_2 + 0x2f) = 0x1000;
  *(undefined2 *)((int)param_2 + 0xbe) = 0x200;
  param_2[0x3a] = 0x1000;
  *(undefined2 *)(param_2 + 0x30) = 0x1000;
  *(undefined2 *)((int)param_2 + 0xc2) = 0x1000;
  *(undefined1 *)((int)param_2 + 199) = 1;
  param_2[0x32] = 0x83f0;
  param_2[0x33] = 0x83f1;
  param_2[0x34] = 0x83f2;
  param_2[0x35] = 0x83f3;
  param_2[0x36] = 0x8837;
  *(undefined1 *)((int)param_2 + 0xc6) = 5;
  *(undefined2 *)(param_2 + 0x3b) = 0x100;
  *(undefined2 *)((int)param_2 + 0xee) = 0x12;
  *(undefined2 *)(param_2 + 0x3c) = 0x100;
  *(undefined2 *)((int)param_2 + 0xf2) = 0x20;
  *(undefined2 *)(param_2 + 0x3d) = 0;
  *(undefined2 *)((int)param_2 + 0xf6) = 0;
  param_2[0x3e] = 0;
  *(undefined2 *)(param_2 + 0x46) = 1;
  *(undefined2 *)(param_2 + 0x3f) = 0x400;
  *(undefined2 *)(param_2 + 0x40) = 0x40;
  *(undefined2 *)((int)param_2 + 0x102) = 0x40;
  *(undefined2 *)(param_2 + 0x43) = 0x200;
  *(undefined2 *)((int)param_2 + 0x10e) = 0x200;
  *(undefined2 *)((int)param_2 + 0xfe) = 10;
  *(undefined2 *)(param_2 + 0x41) = 0;
  *(undefined2 *)((int)param_2 + 0x106) = 0;
  param_2[0x42] = 0;
  *(undefined2 *)(param_2 + 0x44) = 4;
  *(undefined2 *)((int)param_2 + 0x112) = 0;
  *(undefined2 *)(param_2 + 0x45) = 0;
  *(undefined2 *)((int)param_2 + 0x116) = 0;
  param_2[0x4a] = param_2[0x4a] | 0x447f9e7;
  param_2[0x4b] = param_2[0x4b] | 0x74fc;
  param_2[0x49] = param_2[0x49] | 0xffb7ffff;
  return;
}

/* FUN_000155f0 @ 0x155f0 (180 bytes) */
int FUN_000155f0(param_1, param_2)
  uint *param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  iVar1 = *(int *)(param_2 + 0x18);
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
  if ((*(byte *)(param_2 + 8) & 8) != 0) {
    uVar2 = uVar2 | 0x80000000;
  }
  if (*(short *)(param_2 + 0x24) != 0) {
    if (((uVar2 & 0xf) == 4) && (*(int *)(param_2 + 0x28) != 1)) {
      if (*(short *)(param_2 + 0x26) == 6) {
        *param_1 = uVar2 | 0x400000;
        return;
      }
      if (*(short *)(param_2 + 0x26) != 4) {
        *param_1 = uVar2 | 0x100000;
        return;
      }
      *param_1 = uVar2 | 0x200000;
      return;
    }
    if ((*(short *)(param_2 + 0x26) == 4) || (*(short *)(param_2 + 0x26) == 6)) {
      *param_1 = uVar2 | 0x80000;
      return;
    }
    uVar2 = uVar2 | 0x40000;
  }
  *param_1 = uVar2;
  return;
}

/* FUN_000156a4 @ 0x156a4 (696 bytes) */
int FUN_000156a4(param_1)
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
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
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
  if (iVar3 == 0) goto LAB_00015900;
  if ((((iVar4 != 0) && (iVar5 != 0)) && (iVar6 != 0)) && ((iVar7 != 0 && (iVar8 != 0)))) {
    _CFNotificationCenterAddObserver(iVar1,param_1,PTR_FUN_002131c5,iVar3,iVar4,2);
    local_24 = iVar5;
    local_2c = _CFNumberCreate(0,3,param_1 + 0x2a60);
    local_20 = iVar6;
    local_28 = _CFNumberCreate(0,3,param_1 + 0x2a64);
    if (local_2c != 0) {
      if (local_28 != 0) {
        iVar9 = _CFDictionaryCreate(*(undefined4 *)PTR_002131c1,&local_24,&local_2c,2,PTR_002131b9,
                                    PTR_002131bd);
        if (iVar9 != 0) {
          _CFNotificationCenterPostNotification(iVar1,iVar7,iVar8,iVar9,1);
          _CFRelease(iVar9);
        }
        if (local_2c == 0) goto LAB_000158e6;
      }
      _CFRelease(local_2c);
    }
LAB_000158e6:
    if (local_28 != 0) {
      _CFRelease(local_28);
    }
  }
  _CFRelease(iVar3);
LAB_00015900:
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

/* FUN_0001595c @ 0x1595c (165 bytes) */
int FUN_0001595c(param_1)
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
      _CFRelease();
      return;
    }
  }
  return;
}

/* FUN_00015a01 @ 0x15a01 (387 bytes) */
int FUN_00015a01()
{
  pid_t pVar1;
  FILE *pFVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  size_t sVar7;
  size_t sVar8;
  char local_3c [44];
  
  pVar1 = _getpid();
  _sprintf(local_3c,"ps -wwp %d\n",pVar1);
  pFVar2 = _popen(local_3c,"r");
  if (pFVar2 == (FILE *)0x0) {
    _puts("  failed to compute application path");
    return;
  }
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
      sVar8 = 0;
      pcVar6 = pcVar5;
      do {
        if ((*pcVar6 == ' ') && (pcVar6[1] == '/')) {
          *pcVar6 = '\0';
          break;
        }
        sVar8 = sVar8 + 1;
        pcVar6 = pcVar6 + 1;
      } while (sVar7 != sVar8);
    }
    _strlcpy(pcVar4,pcVar5,sVar7);
    _printf("  application path | %s\n",pcVar5);
  }
  _pclose(pFVar2);
  if (pcVar3 != (char *)0x0) {
    _free(pcVar3);
  }
  if (pcVar4 != (char *)0x0) {
    _free(pcVar4);
  }
  return;
}

/* FUN_00015b84 @ 0x15b84 (81 bytes) */
int FUN_00015b84(param_1, param_2)
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
      goto LAB_00015bb9;
    }
    if (param_1 == 10) goto LAB_00015bb9;
    if (param_1 != 0xb) {
      return 0;
    }
  }
  if (0x1ff < (param_2 & 0x300)) {
    return 2;
  }
LAB_00015bb9:
  if ((param_2 & 0x300) < 0x100) {
    return 0;
  }
  return 1;
}

/* FUN_00015bd5 @ 0x15bd5 (2328 bytes) */
int FUN_00015bd5(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  float *param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  float fVar13;
  int local_60;
  int local_4c;
  int local_40;
  undefined4 local_24;
  undefined4 local_20;
  
  local_4c = param_4;
  iVar5 = *(int *)(param_1 + 0x10);
  uVar3 = FUN_000092a0(*(undefined2 *)(iVar5 + 0x2db8),*(undefined4 *)(param_1 + 0x154));
  if ((*(char *)(iVar5 + 0x2d84) == '\0') ||
     (((((*(int *)(iVar5 + 0x2d68) == 1 && (*(int *)(iVar5 + 0x2d6c) == 1)) &&
        (*(short *)(iVar5 + 0x2d80) != -0x7ff5)) &&
       (((*(short *)(iVar5 + 0x2d80) != -0x7ff9 && (*(short *)(iVar5 + 0x2d82) != -0x7ff5)) &&
        (*(short *)(iVar5 + 0x2d82) != -0x7ff9)))) || (*(char *)(iVar5 + 0x2e33) != '\0')))) {
    uVar10 = *(uint *)(param_1 + 0x26b0) & 0xfffffffd;
    *(uint *)(param_1 + 0x26b0) = uVar10;
    if (*(char *)(iVar5 + 0x2d66) != '\0') goto LAB_00015e75;
LAB_00015c6f:
    uVar10 = uVar10 & 0xfffffffe;
    *(uint *)(param_1 + 0x26b0) = uVar10;
    if ((*(ushort *)(iVar5 + 0x30b4) & 0xcff1) == 0) goto LAB_00015c87;
LAB_00015e8d:
    uVar10 = uVar10 | 0x800;
    *(uint *)(param_1 + 0x26b0) = uVar10;
    if (*(char *)(iVar5 + 0x2ddc) != '\0') goto LAB_00015ea3;
LAB_00015c9d:
    uVar10 = uVar10 & 0xffffffdf;
    *(uint *)(param_1 + 0x26b0) = uVar10;
  }
  else {
    uVar10 = *(uint *)(param_1 + 0x26b0) | 2;
    *(uint *)(param_1 + 0x26b0) = uVar10;
    if (*(char *)(iVar5 + 0x2d66) == '\0') goto LAB_00015c6f;
LAB_00015e75:
    uVar10 = uVar10 | 1;
    *(uint *)(param_1 + 0x26b0) = uVar10;
    if ((*(ushort *)(iVar5 + 0x30b4) & 0xcff1) != 0) goto LAB_00015e8d;
LAB_00015c87:
    uVar10 = uVar10 & 0xfffff7ff;
    *(uint *)(param_1 + 0x26b0) = uVar10;
    if (*(char *)(iVar5 + 0x2ddc) == '\0') goto LAB_00015c9d;
LAB_00015ea3:
    if ((*(uint *)(param_1 + 0x154) & 0xf) != 3) goto LAB_00015c9d;
    uVar10 = uVar10 | 0x20;
    *(uint *)(param_1 + 0x26b0) = uVar10;
  }
  if ((((*(byte *)(iVar5 + 0x31c0) & 1) == 0) || (-1 < *(char *)(param_1 + 0x154))) ||
     ((*(short *)(iVar5 + 0x31a0) == 0x207 && (*(int *)(iVar5 + 0x31a4) == 0x1e001e00)))) {
    uVar10 = uVar10 & 0xfffeffff;
    *(uint *)(param_1 + 0x26b0) = uVar10;
  }
  else {
    uVar10 = uVar10 | 0x10000;
    *(uint *)(param_1 + 0x26b0) = uVar10;
  }
  if ((*(char *)(iVar5 + 0x2dc8) == '\0') || ((*(byte *)(param_1 + 0x154) & 0x40) == 0)) {
    uVar10 = uVar10 & 0xffffffef;
    *(uint *)(param_1 + 0x26b0) = uVar10;
  }
  else {
    uVar10 = uVar10 | 0x10;
    *(uint *)(param_1 + 0x26b0) = uVar10;
  }
  if (*(char *)(iVar5 + 0x2e0a) == '\0') {
    *(uint *)(param_1 + 0x26b0) = uVar10 & 0xffffffbf;
  }
  else {
    *(uint *)(param_1 + 0x26b0) = uVar10 | 0x40;
  }
  if (((((((*(int *)(param_1 + 0x18c) == 0) || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 0)) &&
         ((*(int *)(param_1 + 400) == 0 || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 1)))) &&
        ((*(int *)(param_1 + 0x194) == 0 || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 2)))) &&
       ((*(int *)(param_1 + 0x198) == 0 || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 3)))) &&
      (((*(int *)(param_1 + 0x19c) == 0 || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 4)) &&
       ((*(int *)(param_1 + 0x1a0) == 0 || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 5)))))) &&
     (((*(int *)(param_1 + 0x1a4) == 0 || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 6)) &&
      ((*(int *)(param_1 + 0x1a8) == 0 || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 7)))))) {
    uVar10 = *(uint *)(param_1 + 0x26b0) & 0xfffdffff;
    *(uint *)(param_1 + 0x26b0) = uVar10;
  }
  else {
    uVar10 = *(uint *)(param_1 + 0x26b0) | 0x20000;
    *(uint *)(param_1 + 0x26b0) = uVar10;
  }
  if (*(char *)(iVar5 + 0x2e33) == '\0') {
    uVar10 = uVar10 & 0xfffffdff;
    *(uint *)(param_1 + 0x26b0) = uVar10;
  }
  else {
    uVar10 = uVar10 | 0x200;
    *(uint *)(param_1 + 0x26b0) = uVar10;
  }
  if ((((*(char *)(iVar5 + 0x2e43) == '\0') || (*(char *)(iVar5 + 0x2e40) == '\0')) ||
      (*(char *)(iVar5 + 0x2e41) == '\0')) || (*(char *)(iVar5 + 0x2e42) == '\0')) {
    uVar10 = uVar10 | 0x400;
    *(uint *)(param_1 + 0x26b0) = uVar10;
  }
  else {
    uVar10 = uVar10 & 0xfffffbff;
    *(uint *)(param_1 + 0x26b0) = uVar10;
  }
  if (*(short *)(iVar5 + 0x2dba) == *(short *)(iVar5 + 0x2db8)) {
    iVar4 = param_3 + param_5;
    iVar7 = param_4 + param_6;
    iVar11 = (int)*param_2;
    if (*(char *)(param_1 + 0x2b7c) == '\0') {
      fVar13 = param_2[1];
    }
    else {
      fVar13 = (float)*(int *)(param_1 + 0x160) - (FLOAT_001c5ba4 + param_2[1]);
    }
    local_60 = (int)fVar13;
    iVar8 = param_5 + iVar11;
    iVar9 = param_6 + local_60;
    if ((((iVar11 < param_3) || (iVar4 < iVar11)) && ((iVar8 < param_3 || (iVar4 < iVar8)))) ||
       ((local_60 < param_4 || (iVar7 < local_60)))) {
      if ((param_3 <= iVar11) && (((iVar11 <= iVar4 && (param_4 <= iVar9)) && (iVar9 <= iVar7)))) {
        bVar1 = true;
        goto LAB_00015d7a;
      }
      if (((iVar8 < param_3) || (iVar4 < iVar8)) || ((iVar9 < param_4 || (iVar7 < iVar9))))
      goto LAB_00015d76;
    }
    bVar1 = true;
  }
  else {
LAB_00015d76:
    bVar1 = false;
  }
LAB_00015d7a:
  if (((param_7 == 0x1801) && ((*(uint *)(param_1 + 0x154) & 0x30000) != 0)) &&
     ((iVar4 = *(int *)(param_1 + 0x10), *(int *)(iVar4 + 0x2e40) == 0 &&
      ((((*(char *)(iVar4 + 0x2e44) != '\0' && ((uVar10 & 0x10001) == 0)) && ((uVar10 & 0x10) != 0))
       && (*(short *)(iVar4 + 0x2dc4) == 0x207)))))) {
    cVar2 = ((int (*)())FUN_00017bd8)(param_1,4);
    if (cVar2 == '\0') {
      local_40 = 3;
      goto LAB_00015d9a;
    }
    uVar10 = *(uint *)(param_1 + 0x26b0);
  }
  if (((((uVar10 & 0x20800) != 0) || (param_7 - 0x1801U < 2)) ||
      (((*(ushort *)(*(int *)(param_1 + 0x10) + 0x30b0) & 0x1ff) != 0 ||
       ((*(uint *)(*(int *)(param_1 + 0x10) + 0x30b4) & 0xff0000) != 0)))) ||
     ((((uVar10 & 0x10073) == 0 &&
       ((byte)PTR_DAT_002131c9[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24 + 0x17] >> 5 < 3)) &&
      ((bVar1 && ((*(byte *)(param_1 + 0x154) & 0x20) != 0)))))) {
    local_40 = 0;
  }
  else {
    local_40 = 2;
  }
LAB_00015d9a:
  if ((*(int *)(*(int *)(param_1 + 0x18) + 0x1a0) != 0) ||
     (1 < (ushort)(*(uint *)(param_1 + 0x1ae4) >> 6))) {
    local_40 = 0;
  }
  iVar4 = local_40;
  if ((bVar1) && (iVar4 = 0, 1 < local_40 - 2U)) {
    iVar4 = local_40;
  }
  local_40 = iVar4;
  cVar2 = ((int (*)())FUN_00017bd8)(param_1,uVar3);
  if (((cVar2 == '\0') &&
      (cVar2 = ((int (*)())FUN_00017bd8)(param_1,*(undefined4 *)(param_1 + 0x26a0)), cVar2 == '\0')) &&
     (local_40 != 0)) {
    fVar13 = *param_2 + FLOAT_001c5bd4;
    if (fVar13 < 0.0) {
      fVar13 = fVar13 - FLOAT_001c5be0;
    }
    iVar4 = (int)fVar13;
    fVar13 = FLOAT_001c5bd4 + param_2[1];
    if (fVar13 < 0.0) {
      fVar13 = fVar13 - FLOAT_001c5be0;
    }
    iVar11 = (int)fVar13;
    if (*(char *)(param_1 + 0x2b7c) != '\0') {
      local_4c = (*(int *)(param_1 + 0x160) - param_4) - param_6;
      iVar11 = iVar11 - param_6;
    }
    if (local_40 == 1) {
      if (*(char *)(iVar5 + 0x2e33) == '\0') {
        uVar10 = 0xc;
        uVar12 = 0xc0;
      }
      else {
        uVar10 = (uint)(*(byte *)(param_1 + 0x1d39) & 0xf);
        uVar12 = uVar10 << 4;
      }
      FUN_0001e5bd(param_1,param_3,local_4c,param_5,param_6,iVar4,iVar11,uVar3,uVar10 | uVar12);
    }
    else if (local_40 == 3) {
      FUN_0001e7d3(param_1,param_3,local_4c,param_5,param_6,iVar4,iVar11,uVar3);
    }
    else {
      FUN_0001f823(param_1,param_3,local_4c,param_5,param_6,iVar4,iVar11,param_2[2],uVar3);
    }
  }
  else {
    if (param_7 == 0x1801) {
      if ((*(uint *)(param_1 + 0x154) & 0x30000) == 0) {
        return;
      }
      if ((*(uint *)(param_1 + 0x154) & 0x20000) == 0) {
        iVar5 = param_5 * 2;
        local_24 = 0x1403;
        local_20 = 0x1902;
      }
      else {
        iVar5 = param_5 << 2;
        local_24 = 0x1405;
        local_20 = 0x1902;
      }
    }
    else if (param_7 == 0x1802) {
      if ((*(uint *)(param_1 + 0x154) & 0x30000) != 0x30000) {
        return;
      }
      local_24 = 0x1401;
      local_20 = 0x1901;
      iVar5 = param_5;
    }
    else {
      if (param_7 != 0x1800) {
        return;
      }
      local_24 = 0x1401;
      local_20 = 0x1908;
      iVar5 = param_5 << 2;
    }
    pvVar6 = _malloc(iVar5 * param_6);
    if (pvVar6 != (void *)0x0) {
      FUN_00026ee1(param_1,param_3,param_4,param_5,param_6,local_20,local_24,pvVar6,2,0);
      ((int (*)())FUN_000175fe)(param_1,param_2,param_5,param_6,local_20,local_24,pvVar6,1,0);
      _free(pvVar6);
      return;
    }
  }
  return;
}

/* FUN_000164ed @ 0x164ed (4217 bytes) */
int FUN_000164ed(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  float *param_2;
  uint param_3;
  uint param_4;
  int param_5;
  undefined4 param_6;
  int param_7;
  int param_8;
  int param_9;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  void *pvVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  uint local_354;
  uint local_34c;
  uint local_348;
  uint local_344;
  uint local_340;
  uint local_33c;
  int local_338;
  int local_334;
  int local_330;
  int local_32c;
  uint local_328;
  float local_308;
  float local_304;
  uint local_9c;
  int local_94;
  int local_90;
  undefined1 local_8c [8];
  void *local_84;
  int local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  uint local_70;
  undefined4 local_6c;
  uint local_68;
  uint local_64;
  float local_60;
  float local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  undefined4 local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  undefined4 local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  undefined4 local_2c;
  undefined1 local_28;
  int local_24;
  undefined1 local_20 [16];
  
  iVar2 = *(int *)(param_1 + 0x10);
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  if (((*(char *)(iVar2 + 0x2d84) == '\0') ||
      (((((*(int *)(iVar2 + 0x2d68) == 1 && (*(int *)(iVar2 + 0x2d6c) == 1)) &&
         (*(short *)(iVar2 + 0x2d80) != -0x7ff5)) &&
        ((*(short *)(iVar2 + 0x2d80) != -0x7ff9 && (*(short *)(iVar2 + 0x2d82) != -0x7ff5)))) &&
       (*(short *)(iVar2 + 0x2d82) != -0x7ff9)))) || (*(char *)(iVar2 + 0x2e33) != '\0')) {
    uVar8 = *(uint *)(param_1 + 0x26b0) & 0xfffffffd;
    *(uint *)(param_1 + 0x26b0) = uVar8;
    if (*(char *)(iVar2 + 0x2d66) == '\0') goto LAB_00016589;
LAB_00016aa4:
    uVar8 = uVar8 | 1;
    *(uint *)(param_1 + 0x26b0) = uVar8;
    if ((*(ushort *)(iVar2 + 0x30b4) & 0xcff1) == 0) goto LAB_000165a7;
LAB_00016ac2:
    uVar8 = uVar8 | 0x800;
    *(uint *)(param_1 + 0x26b0) = uVar8;
    if (*(char *)(iVar2 + 0x2ddc) != '\0') goto LAB_00016ade;
LAB_000165c3:
    uVar8 = uVar8 & 0xffffffdf;
    *(uint *)(param_1 + 0x26b0) = uVar8;
  }
  else {
    uVar8 = *(uint *)(param_1 + 0x26b0) | 2;
    *(uint *)(param_1 + 0x26b0) = uVar8;
    if (*(char *)(iVar2 + 0x2d66) != '\0') goto LAB_00016aa4;
LAB_00016589:
    uVar8 = uVar8 & 0xfffffffe;
    *(uint *)(param_1 + 0x26b0) = uVar8;
    if ((*(ushort *)(iVar2 + 0x30b4) & 0xcff1) != 0) goto LAB_00016ac2;
LAB_000165a7:
    uVar8 = uVar8 & 0xfffff7ff;
    *(uint *)(param_1 + 0x26b0) = uVar8;
    if (*(char *)(iVar2 + 0x2ddc) == '\0') goto LAB_000165c3;
LAB_00016ade:
    if ((*(uint *)(param_1 + 0x154) & 0xf) != 3) goto LAB_000165c3;
    uVar8 = uVar8 | 0x20;
    *(uint *)(param_1 + 0x26b0) = uVar8;
  }
  if ((((*(byte *)(iVar2 + 0x31c0) & 1) == 0) || (-1 < *(char *)(param_1 + 0x154))) ||
     ((*(short *)(iVar2 + 0x31a0) == 0x207 && (*(int *)(iVar2 + 0x31a4) == 0x1e001e00)))) {
    uVar8 = uVar8 & 0xfffeffff;
    *(uint *)(param_1 + 0x26b0) = uVar8;
  }
  else {
    uVar8 = uVar8 | 0x10000;
    *(uint *)(param_1 + 0x26b0) = uVar8;
  }
  if ((*(char *)(iVar2 + 0x2dc8) == '\0') || ((*(byte *)(param_1 + 0x154) & 0x40) == 0)) {
    uVar8 = uVar8 & 0xffffffef;
    *(uint *)(param_1 + 0x26b0) = uVar8;
  }
  else {
    uVar8 = uVar8 | 0x10;
    *(uint *)(param_1 + 0x26b0) = uVar8;
  }
  if (*(char *)(iVar2 + 0x2e0a) == '\0') {
    *(uint *)(param_1 + 0x26b0) = uVar8 & 0xffffffbf;
  }
  else {
    *(uint *)(param_1 + 0x26b0) = uVar8 | 0x40;
  }
  if (((((((*(int *)(param_1 + 0x18c) == 0) || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 0)) &&
         ((*(int *)(param_1 + 400) == 0 || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 1)))) &&
        ((*(int *)(param_1 + 0x194) == 0 || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 2)))) &&
       ((*(int *)(param_1 + 0x198) == 0 || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 3)))) &&
      ((((*(int *)(param_1 + 0x19c) == 0 || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 4)) &&
        ((*(int *)(param_1 + 0x1a0) == 0 || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 5)))) &&
       ((*(int *)(param_1 + 0x1a4) == 0 || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 6)))))) &&
     ((*(int *)(param_1 + 0x1a8) == 0 || (iVar4 = FUN_000a2bfa(param_1), iVar4 == 7)))) {
    uVar8 = *(uint *)(param_1 + 0x26b0) & 0xfffdffff;
    *(uint *)(param_1 + 0x26b0) = uVar8;
  }
  else {
    uVar8 = *(uint *)(param_1 + 0x26b0) | 0x20000;
    *(uint *)(param_1 + 0x26b0) = uVar8;
  }
  if (*(char *)(iVar2 + 0x2e33) == '\0') {
    uVar8 = uVar8 & 0xfffffdff;
    *(uint *)(param_1 + 0x26b0) = uVar8;
  }
  else {
    uVar8 = uVar8 | 0x200;
    *(uint *)(param_1 + 0x26b0) = uVar8;
  }
  if ((((*(char *)(iVar2 + 0x2e43) == '\0') || (*(char *)(iVar2 + 0x2e40) == '\0')) ||
      (*(char *)(iVar2 + 0x2e41) == '\0')) || (*(char *)(iVar2 + 0x2e42) == '\0')) {
    *(uint *)(param_1 + 0x26b0) = uVar8 | 0x400;
  }
  else {
    *(uint *)(param_1 + 0x26b0) = uVar8 & 0xfffffbff;
  }
  if (param_3 == 0) {
    return;
  }
  if (param_4 == 0) {
    return;
  }
  iVar2 = *(int *)(param_1 + 0x10);
  if (*(char *)(iVar2 + 0x3190) != '\0') {
    if (*(int *)(iVar2 + 0x3188) == 0) {
      return;
    }
    if (*(int *)(iVar2 + 0x318c) == 0) {
      return;
    }
    if (*(int *)(param_1 + 0x15c) <= *(int *)(iVar2 + 0x3180)) {
      return;
    }
    if (*(int *)(iVar2 + 0x3180) + *(int *)(iVar2 + 0x3188) < 1) {
      return;
    }
    if (*(int *)(param_1 + 0x160) <= *(int *)(iVar2 + 0x3184)) {
      return;
    }
    if (*(int *)(iVar2 + 0x3184) + *(int *)(iVar2 + 0x318c) < 1) {
      return;
    }
  }
  if (((param_9 == '\0') && ((*(uint *)(param_1 + 0x26b0) & 0x30e73) == 0)) &&
     ((1 < param_5 - 0x1901U &&
      (((*(ushort *)(iVar2 + 0x30b0) & 0x1ff) == 0 && ((*(uint *)(iVar2 + 0x30b4) & 0xff0000) == 0))
      )))) {
    ((int (*)())FUN_00017bd8)(param_1);
  }
  local_60 = 0.0;
  local_5c = 0.0;
  local_70 = 0;
  local_6c = 0x7ffff;
  if (param_8 == '\0') {
    iVar2 = *(int *)(param_1 + 0x10);
    iVar4 = iVar2 + 0x2e6c;
    local_70 = (uint)(*(char *)(iVar2 + 0x2e84) != '\0');
    if (*(char *)(iVar2 + 0x2e85) != '\0') {
      local_70 = local_70 | 4;
    }
  }
  else {
    iVar4 = 0;
  }
  FUN_000095f0(param_1,param_5,param_6,param_3,param_4,&local_90,local_20,&local_24,iVar4);
  FUN_00009369(param_5);
  _glgConvertType(param_5,param_6,local_8c);
  if (param_5 == 0x1901) {
    local_7c = 0xe;
    local_78 = 0;
  }
  else if (param_5 == 0x1902) {
    local_7c = 0xd;
    local_78 = 7;
  }
  else {
    local_7c = 6;
    local_78 = 0x11;
  }
  local_74 = 2;
  local_60 = *param_2;
  fVar13 = *(float *)(param_1 + 0x2a54);
  fVar11 = local_60 * fVar13 + FLOAT_001c5bd4;
  if (fVar11 < 0.0) {
    fVar11 = fVar11 - FLOAT_001c5be0;
  }
  local_338 = (int)fVar11;
  if (*(char *)(param_1 + 0x2b7c) == '\0') {
    local_5c = param_2[1];
    fVar11 = *(float *)(param_1 + 0x2a58);
    fVar12 = local_5c * fVar11 + FLOAT_001c5bd4;
    if (fVar12 < 0.0) {
      fVar12 = fVar12 - FLOAT_001c5be0;
      goto LAB_00016d42;
    }
    local_334 = (int)fVar12;
  }
  else {
    local_5c = param_2[1];
    fVar11 = *(float *)(param_1 + 0x2a58);
    fVar12 = local_5c * fVar11 - FLOAT_001c5bd4;
    if (0.0 <= fVar12) {
LAB_00016d42:
      local_334 = (int)fVar12;
    }
    else {
      local_334 = (int)(fVar12 + FLOAT_001c5be0);
    }
  }
  fVar12 = *(float *)(*(int *)(param_1 + 0x10) + 0x2e48) * fVar13;
  fVar14 = *(float *)(*(int *)(param_1 + 0x10) + 0x2e4c) * fVar11;
  iVar2 = (uint)(param_5 != 0x1901) * 3 + 1;
  if ((fVar12 == FLOAT_001c5ba4) && (fVar14 == FLOAT_001c5ba4)) {
    local_60 = 0.0;
    local_5c = 0.0;
    iVar4 = iVar2 * param_3;
    sVar5 = param_4 * iVar4;
    local_330 = 1;
    local_32c = 1;
    uVar8 = param_4;
    local_328 = param_3;
    goto LAB_00016ebf;
  }
  fVar11 = fVar11 * local_5c;
  if (fVar12 < 0.0) {
    fVar12 = (float)((uint)fVar12 ^ _DAT_001c5ed0);
    fVar13 = local_60 * fVar13 - FLOAT_001c5bd4;
    if (0.0 <= fVar13) {
      local_338 = (int)fVar13;
      local_330 = -1;
    }
    else {
      local_338 = (int)(fVar13 + FLOAT_001c5be0);
      local_330 = -1;
    }
  }
  else {
    fVar13 = local_60 * fVar13 + FLOAT_001c5bd4;
    if (0.0 <= fVar13) {
      local_338 = (int)fVar13;
      local_330 = 1;
    }
    else {
      local_338 = (int)(fVar13 + FLOAT_001c5be0);
      local_330 = 1;
    }
  }
  if (*(char *)(param_1 + 0x2b7c) == '\0') {
    if (fVar14 < 0.0) {
      fVar14 = (float)((uint)fVar14 ^ _DAT_001c5ed0);
      fVar11 = fVar11 - FLOAT_001c5bd4;
      if (0.0 <= fVar11) {
        local_334 = (int)fVar11;
        local_330 = -1;
        goto LAB_0001743c;
      }
      local_334 = (int)(fVar11 + FLOAT_001c5be0);
      local_330 = -1;
      local_32c = 1;
    }
    else {
      fVar11 = FLOAT_001c5bd4 + fVar11;
      if (0.0 <= fVar11) {
        local_334 = (int)fVar11;
        local_32c = 1;
      }
      else {
        local_334 = (int)(fVar11 + FLOAT_001c5be0);
        local_32c = 1;
      }
    }
  }
  else if (fVar14 < 0.0) {
    fVar14 = (float)((uint)fVar14 ^ _DAT_001c5ed0);
    fVar11 = FLOAT_001c5bd4 + fVar11;
    fVar13 = fVar11;
    if (fVar11 < 0.0) {
      fVar13 = fVar11 + FLOAT_001c5be0;
    }
    local_334 = (int)fVar13;
    if (fVar11 - (float)local_334 == 0.0) {
      local_334 = local_334 + -1;
    }
    local_32c = -1;
  }
  else {
    fVar11 = fVar11 - FLOAT_001c5bd4;
    fVar13 = fVar11;
    if (fVar11 < 0.0) {
      fVar13 = fVar11 + FLOAT_001c5be0;
    }
    local_334 = (int)fVar13;
    if (((float)local_334 - fVar11) + FLOAT_001c5ba4 == FLOAT_001c5ba4) {
      local_334 = local_334 + -1;
      local_32c = 1;
    }
    else {
LAB_0001743c:
      local_32c = 1;
    }
  }
  local_60 = local_60 - (float)(int)local_60;
  local_5c = local_5c - (float)(int)local_5c;
  local_328 = _glgPixelCenters((double)local_60,(double)(fVar12 * (float)(int)param_3 + local_60),
                               fVar12);
  uVar8 = _glgPixelCenters((double)local_5c,(double)(fVar14 * (float)(int)param_4 + local_5c),fVar14
                          );
  iVar4 = iVar2 * local_328;
  sVar5 = uVar8 * iVar4;
LAB_00016ebf:
  pvVar6 = _malloc(sVar5);
  if (pvVar6 != (void *)0x0) {
    local_64 = param_4;
    local_28 = 1;
    local_68 = param_3;
    local_94 = param_7 + local_24;
    local_84 = pvVar6;
    local_80 = iVar4;
    if (param_9 == '\0') {
      iVar10 = *(int *)(param_1 + 0x10);
      if (((((*(ushort *)(iVar10 + 0x30b0) & 0x1ff) != 0) ||
           ((*(uint *)(iVar10 + 0x30b4) & 0xff0000) != 0)) && (param_5 != 0x1901)) &&
         (param_5 != 0x1902)) {
        if ((*(uint *)(iVar10 + 0x30b0) & 2) == 0) {
          if (((*(uint *)(iVar10 + 0x30b0) & 4) != 0) && (*(short *)(iVar10 + 0x2fe8) == -0x7fea)) {
            local_328 = (local_328 - *(int *)(iVar10 + 0x2ff0)) + 1;
            uVar8 = (uVar8 - *(int *)(iVar10 + 0x2ff4)) + 1;
          }
        }
        else if (*(short *)(iVar10 + 0x2fa8) == -0x7fea) {
          local_328 = (local_328 - *(int *)(iVar10 + 0x2fb0)) + 1;
          uVar8 = (uVar8 - *(int *)(iVar10 + 0x2fb4)) + 1;
        }
        iVar1 = *(int *)(param_1 + 0x18);
        iVar3 = *(int *)(*(int *)(iVar1 + 0x140) + 0x30);
        local_58 = (uint)*(ushort *)(iVar3 + 0x98);
        local_54 = (uint)*(ushort *)(iVar3 + 0x9a);
        local_50 = (uint)*(ushort *)(iVar3 + 0x8c);
        local_4c = *(undefined4 *)(iVar3 + 0x9c);
        iVar3 = *(int *)(*(int *)(iVar1 + 0x148) + 0x30);
        local_48 = (uint)*(ushort *)(iVar3 + 0x98);
        local_44 = (uint)*(ushort *)(iVar3 + 0x9a);
        local_40 = (uint)*(ushort *)(iVar3 + 0x8c);
        local_3c = *(undefined4 *)(iVar3 + 0x9c);
        iVar1 = *(int *)(*(int *)(iVar1 + 0x144) + 0x30);
        local_38 = (uint)*(ushort *)(iVar1 + 0x98);
        local_34 = (uint)*(ushort *)(iVar1 + 0x9a);
        local_30 = (uint)*(ushort *)(iVar1 + 0x8c);
        local_2c = *(undefined4 *)(iVar1 + 0x9c);
      }
      fVar11 = *(float *)(param_1 + 0x2a58) * *(float *)(iVar10 + 0x2e4c);
      fVar13 = *(float *)(param_1 + 0x2a54) * *(float *)(iVar10 + 0x2e48);
      _memcpy(&local_308,(void *)(iVar10 + 0x2e48),0x274);
      if ((fVar13 != FLOAT_001c5ba4) || (NAN(fVar13) || NAN(FLOAT_001c5ba4))) {
        uVar7 = 0x4000;
      }
      else {
        uVar7 = 0;
      }
      uVar9 = 0;
      if (fVar11 != FLOAT_001c5ba4) {
        uVar9 = 0x8000;
      }
      if (NAN(fVar11) || NAN(FLOAT_001c5ba4)) {
        uVar9 = 0x8000;
      }
      local_9c = uVar9 | uVar7 | local_9c & 0xffff3fff;
      local_308 = fVar13;
      local_304 = fVar11;
      _glgProcessPixels(&local_308);
    }
    else {
      _glgProcessPixels(0);
    }
    local_90 = iVar4;
    if (*(char *)(param_1 + 0x2b7c) != '\0') {
      local_90 = -iVar4;
    }
    uVar7 = local_328;
    if (0x7fe < local_328) {
      uVar7 = 0x7fe;
    }
    uVar9 = (uint)(0x7fe / (ulonglong)uVar7);
    if (uVar8 < uVar9) {
      uVar9 = uVar8;
    }
    local_34c = local_328 % uVar7;
    local_33c = local_328 / uVar7 + 1;
    if (local_328 % uVar7 == 0) {
      local_34c = uVar7;
      local_33c = local_328 / uVar7;
    }
    local_354 = uVar8 % uVar9;
    local_340 = uVar8 / uVar9 + 1;
    if (uVar8 % uVar9 == 0) {
      local_354 = uVar9;
      local_340 = uVar8 / uVar9;
    }
    if (local_340 != 0) {
      local_348 = 0;
      do {
        if (local_33c != 0) {
          iVar4 = uVar9 * local_348;
          local_344 = 0;
          do {
            local_64 = local_354;
            if (local_348 != local_340 - 1) {
              local_64 = uVar9;
            }
            local_68 = local_34c;
            if (local_344 != local_33c - 1) {
              local_68 = uVar7;
            }
            iVar10 = local_344 * uVar7;
            if (*(char *)(param_1 + 0x2b7c) == '\0') {
              local_94 = iVar4 * local_90 + iVar2 * iVar10;
              iVar1 = local_32c * iVar4;
            }
            else {
              iVar1 = iVar4 + -1 + local_64;
              local_94 = iVar2 * iVar10 - local_90 * iVar1;
              iVar1 = -(iVar1 * local_32c);
            }
            local_94 = local_94 + (int)pvVar6;
            FUN_00027abe(param_1,local_94,local_68,local_64,local_90,iVar2,
                         local_330 * iVar10 + local_338,iVar1 + local_334,param_2,param_5,param_9);
            local_344 = local_344 + 1;
          } while (local_33c != local_344);
        }
        local_348 = local_348 + 1;
      } while (local_340 != local_348);
    }
    _free(pvVar6);
  }
  return;
}

/* FUN_00017566 @ 0x17566 (152 bytes) */
int FUN_00017566()
{
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  
  ((int (*)())FUN_000164ed)(in_stack_00000014,0x80e1,in_stack_00000018,in_stack_0000001c,1,1);
  return;
}

/* FUN_000175fe @ 0x175fe (149 bytes) */
int FUN_000175fe(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
  int param_9;
{
  undefined1 uVar1;
  
  if (param_9 != 0) {
    uVar1 = FUN_00028413(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    return uVar1;
  }
  ((int (*)())FUN_000164ed)(param_4,param_5,param_6,param_7,param_8,0);
  return 1;
}

/* FUN_00017693 @ 0x17693 (176 bytes) */
int FUN_00017693(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    return;
  }
  iVar2 = ((int (*)())FUN_00014b91)(*(undefined2 *)(*(int *)(param_1 + 0x10) + 0x2dba),
                       *(undefined4 *)(param_1 + 0x154));
  uVar1 = *(uint *)(param_1 + 0x154);
  if (((((uVar1 & 0x20) != 0) || (((uVar1 & 0x10) == 0 && ((uVar1 & 0x400) != 0)))) &&
      ((iVar2 == 0 || ((iVar2 == 1 && ((uVar1 & 0x400) == 0)))))) && ((uVar1 & 0x70000000) == 0)) {
    if (5 < param_2) {
      uVar3 = 6;
      goto LAB_000176d9;
    }
    if (3 < param_2) {
      uVar3 = 4;
      goto LAB_000176d9;
    }
    if (1 < param_2) {
      uVar3 = 2;
      goto LAB_000176d9;
    }
  }
  uVar3 = 1;
LAB_000176d9:
  *(undefined4 *)(param_1 + 0x2a50) = uVar3;
  *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
  *(undefined1 *)(param_1 + 0x2a5c) = 1;
  *(undefined1 *)(param_1 + 0x2a5d) = 1;
  return;
}

/* FUN_00017743 @ 0x17743 (304 bytes) */
int FUN_00017743(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return;
  }
  iVar2 = ((int (*)())FUN_00014b91)(*(undefined2 *)(*(int *)(param_1 + 0x10) + 0x2dba),
                       *(undefined4 *)(param_1 + 0x154));
  uVar1 = *(uint *)(param_1 + 0x154);
  if (((((uVar1 & 0x20) == 0) && (((uVar1 & 0x10) != 0 || ((uVar1 & 0x400) == 0)))) ||
      ((iVar2 != 0 && ((iVar2 != 1 || ((uVar1 & 0x400) != 0)))))) || ((uVar1 & 0x70000000) != 0)) {
LAB_00017784:
    *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
    *(undefined1 *)(param_1 + 0x2a5c) = 1;
    *(undefined1 *)(param_1 + 0x2a5d) = 1;
  }
  else {
    if (param_2 < 4) {
      if (param_2 < 2) goto LAB_00017784;
      *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
      *(undefined1 *)(param_1 + 0x2a5c) = 1;
      if (0x1000 < *(int *)(param_1 + 0x160) * 2) {
        *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
        *(undefined1 *)(param_1 + 0x2a5d) = 1;
        goto LAB_000177a3;
      }
    }
    else {
      if (*(int *)(param_1 + 0x15c) * 2 < 0x1001) {
        *(undefined4 *)(param_1 + 0x2a54) = 0x40000000;
        *(undefined1 *)(param_1 + 0x2a5c) = 2;
      }
      else {
        *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
        *(undefined1 *)(param_1 + 0x2a5c) = 1;
      }
      if (0x1000 < *(int *)(param_1 + 0x160) * 2) {
        *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
        *(undefined1 *)(param_1 + 0x2a5d) = 1;
        goto LAB_000177a3;
      }
    }
    *(undefined4 *)(param_1 + 0x2a58) = 0x40000000;
    *(undefined1 *)(param_1 + 0x2a5d) = 2;
  }
LAB_000177a3:
  *(undefined4 *)(param_1 + 0x2a50) = 1;
  return;
}

/* FUN_00017873 @ 0x17873 (339 bytes) */
int FUN_00017873(param_1)
  int param_1;
{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (param_1 == 0) {
    return;
  }
  iVar4 = *(int *)(param_1 + 0x2a50);
  fVar1 = *(float *)(param_1 + 0x2a54);
  fVar2 = *(float *)(param_1 + 0x2a58);
  uVar5 = *(uint *)(param_1 + 0x154) & 0x700000;
  if (uVar5 == 0) {
    uVar5 = *(uint *)(param_1 + 0x154) & 0xc0000;
    if (uVar5 == 0x40000) {
      ((int (*)())FUN_00017743)();
    }
    else if (uVar5 == 0x80000) {
      ((int (*)())FUN_00017743)();
    }
    else {
      ((int (*)())FUN_00017743)();
    }
  }
  else if (uVar5 == 0x200000) {
    ((int (*)())FUN_00017693)();
  }
  else if (uVar5 == 0x400000) {
    ((int (*)())FUN_00017693)();
  }
  else {
    if (uVar5 != 0x100000) {
      ((int (*)())FUN_00017693)();
      *(undefined4 *)(param_1 + 0x2a48) = *(undefined4 *)(param_1 + 0x15c);
      *(undefined4 *)(param_1 + 0x2a4c) = *(undefined4 *)(param_1 + 0x160);
      iVar3 = *(int *)(param_1 + 0x2a50);
      goto joined_r0x0001794d;
    }
    ((int (*)())FUN_00017693)();
  }
  *(undefined4 *)(param_1 + 0x2a48) = *(undefined4 *)(param_1 + 0x15c);
  *(undefined4 *)(param_1 + 0x2a4c) = *(undefined4 *)(param_1 + 0x160);
  iVar3 = *(int *)(param_1 + 0x2a50);
joined_r0x0001794d:
  if (iVar4 == iVar3) {
    if (((fVar1 == *(float *)(param_1 + 0x2a54)) &&
        (!NAN(fVar1) && !NAN(*(float *)(param_1 + 0x2a54)))) &&
       (fVar2 == *(float *)(param_1 + 0x2a58))) {
      return;
    }
  }
  *(undefined1 *)(param_1 + 0x2a43) = 1;
  return;
}

/* FUN_000179c6 @ 0x179c6 (530 bytes) */
int FUN_000179c6(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  uint local_2c;
  uint local_28;
  int local_24;
  int local_20;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (param_1[0x3e] == 0) {
    return 0;
  }
  if (param_1[0x79] + 0x28U < (uint)param_1[0x77]) {
    ((int (*)())FUN_00017c77)(param_1,0x1000000);
  }
  if (((param_1[0x55] & 0xfU) == 3) || (param_3 == '\0')) {
    ((int (*)())FUN_00017743)();
    param_3 = '\0';
  }
  else {
    ((int (*)())FUN_00017693)();
  }
  local_28 = param_1[0xf] & 0xff83efff;
  param_1[0xf] = local_28;
  if (param_3 == '\0') {
    if ((float)param_1[0xa95] <= FLOAT_001c5bf0) {
      if ((float)param_1[0xa96] <= FLOAT_001c5bf0) goto LAB_00017b1c;
      local_28 = local_28 | 0x41000;
      param_1[0xf] = local_28;
    }
    else {
      if ((float)param_1[0xa96] <= FLOAT_001c5bf0) {
LAB_00017b1c:
        param_1[0xf] = local_28;
        iVar1 = param_1[0x54];
        goto joined_r0x00017b29;
      }
      local_28 = local_28 | 0x81000;
      param_1[0xf] = local_28;
    }
  }
  else {
    iVar1 = param_1[0xa94];
    if (iVar1 == 6) {
      local_28 = local_28 | 0x401000;
      param_1[0xf] = local_28;
    }
    else if (iVar1 == 4) {
      local_28 = local_28 | 0x201000;
      param_1[0xf] = local_28;
    }
    else if (iVar1 == 2) {
      local_28 = local_28 | 0x101000;
      param_1[0xf] = local_28;
    }
  }
  iVar1 = param_1[0x54];
joined_r0x00017b29:
  if (iVar1 == 0) {
    param_1[0x55] = local_28;
  }
  if ((local_28 & 0x20) == 0) {
    local_2c = ~(uint)*(byte *)(*(int *)(PTR_DAT_002131ad + 0xc) + *param_1);
  }
  else {
    local_2c = *(uint *)(param_1[0x3e] + 8);
  }
  local_28 = local_28 & 0xffff3fc0;
  local_24 = param_1[0x3f];
  local_20 = param_1[0x40];
  _io_connect_method_scalarI_structureI(param_1[1],0,&local_2c,4,0,0);
  ((int (*)())FUN_00017873)(param_1);
  FUN_00020b2d(param_1,0);
  *(undefined1 *)(param_1 + 0xa91) = 1;
  return 0;
}

/* FUN_00017bd8 @ 0x17bd8 (131 bytes) */
int FUN_00017bd8(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  bool bVar2;
  
  uVar1 = *(uint *)(param_1 + 0x154);
  if ((((uVar1 & 0x700000) == 0) &&
      (((uVar1 & 0xc0000) == 0 ||
       ((*(float *)(param_1 + 0x2a54) <= FLOAT_001c5bf0 &&
         FLOAT_001c5bf0 != *(float *)(param_1 + 0x2a54) &&
        (*(float *)(param_1 + 0x2a58) <= FLOAT_001c5bf0 &&
         FLOAT_001c5bf0 != *(float *)(param_1 + 0x2a58))))))) || ((uVar1 & 0x70000000) != 0)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (param_2 == 1) {
    if ((uVar1 & 0x400) != 0) {
      return 0;
    }
  }
  else if (param_2 == 0) {
    if ((uVar1 & 0x400) == 0) {
      return 0;
    }
  }
  else if (1 < param_2 - 4U) {
    return 0;
  }
  if (bVar2) {
    return 1;
  }
  return 0;
}

/* FUN_00017c5b @ 0x17c5b (28 bytes) */
int FUN_00017c5b(param_1, param_2)
  int param_1;
  int param_2;
{
  return param_2 == **(int **)(param_1 + 0x238) || param_2 - **(int **)(param_1 + 0x238) < 0;
}

/* FUN_00017c77 @ 0x17c77 (368 bytes) */
int FUN_00017c77(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  char cVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  cVar1 = *(char *)(param_1 + 0x2b7e);
  *puVar4 = 0x1393;
  puVar4[1] = 0;
  puVar4[2] = 0x5c8;
  puVar4[3] = 0x20000;
  puVar4 = puVar4 + 4;
  if (cVar1 != '\0') {
    puVar4 = (undefined4 *)FUN_00029a08(param_1,puVar4);
  }
  puVar2 = *(uint **)(param_1 + 0x1d8);
  *(int *)(*(int *)(param_1 + 0x1e4) + 0x10) =
       (*(int *)(param_1 + 0x1e0) - (int)puVar4 >> 2) + 0x25 +
       (*(int *)(param_1 + 0x1f0) - *(int *)(param_1 + 0x1ec) >> 2);
  *puVar2 = *puVar2 | (int)puVar4 - (int)puVar2 >> 2;
  *puVar4 = param_2;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 4),1,*(undefined4 *)PTR_002131b5,param_1 + 0x1e4,
                      param_1 + 0x1e8,1);
  iVar3 = *(int *)(param_1 + 0x1e4);
  iVar5 = iVar3 + 0x20;
  *(int *)(param_1 + 0x1e0) = iVar3 + -0x74 + *(int *)(iVar3 + 0x10) * 4;
  *(undefined4 *)(iVar3 + 0x1c) = 0;
  *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 0x2834) = 0;
  *(undefined4 *)(param_1 + 0x2838) = 0;
  *(undefined4 *)(param_1 + 0x204) = 1;
  if (cVar1 != '\0') {
    *(undefined4 *)(iVar3 + 0x20) = 0x13d6;
    *(undefined4 *)(iVar3 + 0x24) = 0;
    iVar5 = iVar3 + 0x28;
  }
  *(int *)(param_1 + 0x1dc) = iVar5;
  *(int *)(param_1 + 0x1d8) = iVar3 + 0x1c;
  *(int *)(param_1 + 0x2994) = iVar5 + 0x18000;
  FUN_0002a71b();
  return;
}

/* FUN_00017de7 @ 0x17de7 (635 bytes) */
int FUN_00017de7(param_1)
  int param_1;
{
  uint *puVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint local_2c;
  uint local_28;
  
  cVar2 = ((int (*)())FUN_00017bd8)(param_1,0);
  if (cVar2 != '\0') {
    FUN_00020d0f(param_1,0,0,1,0,0,*(undefined4 *)(param_1 + 0x15c),*(undefined4 *)(param_1 + 0x160)
                );
  }
  ((int (*)())FUN_00017c77)(param_1,0x2000000);
  if ((*(byte *)(*(int *)(param_1 + 0x1e4) + 0x14) & 2) != 0) {
    puVar3 = *(undefined4 **)(param_1 + 0xf8);
    if (*(char *)(param_1 + 0x144) == '\0') {
      cVar2 = *(char *)(param_1 + 0x142);
      uVar5 = 0;
      iVar4 = 0;
    }
    else {
      cVar2 = *(char *)(param_1 + 0x142);
      uVar5 = *(undefined4 *)(param_1 + 0x108);
      iVar4 = param_1 + 0x124;
    }
    (**(code **)(PTR_DAT_002131ad + 0x10))(*puVar3,puVar3[1],puVar3[2],iVar4,uVar5,cVar2 != '\0');
  }
  puVar3 = *(undefined4 **)(param_1 + 0x1dc);
  if (*(undefined4 **)(param_1 + 0x1e0) <= puVar3 + 5) {
    ((int (*)())FUN_00017c77)(param_1,0x1000000);
    puVar3 = *(undefined4 **)(param_1 + 0x1dc);
  }
  *(undefined4 **)(param_1 + 0x1dc) = puVar3 + 5;
  puVar1 = *(uint **)(param_1 + 0x1d8);
  *puVar1 = *puVar1 | (int)puVar3 - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x1d8) = puVar3;
  *puVar3 = 0x28000000;
  if (*(char *)(param_1 + 0x2a68) != '\0') {
    *(undefined1 *)(param_1 + 0x2a68) = 0;
    *(undefined1 *)(param_1 + 0x2a69) = 1;
    *(undefined4 *)(param_1 + 0x2a8c) = *(undefined4 *)(param_1 + 0x2a78);
    *(undefined4 *)(param_1 + 0x2a90) = *(undefined4 *)(param_1 + 0x2a7c);
    cVar2 = *(char *)(param_1 + 0x2a6c);
    if (*(char *)(param_1 + 0x2a80) != cVar2) {
      *(char *)(param_1 + 0x2a80) = cVar2;
      if (cVar2 == '\x01') {
        local_2c = 0;
        local_28 = 0;
      }
      else if (cVar2 == '\x02') {
        local_2c = 1;
        local_28 = 1;
      }
      else {
        local_2c = (uint)*(byte *)(param_1 + 0x142);
        local_28 = (uint)*(byte *)(param_1 + 0x146);
      }
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),2,&local_2c,2,0,0);
    }
    iVar4 = *(int *)(param_1 + 0x2a70);
    if ((*(int *)(param_1 + 0x2a84) != iVar4) ||
       (*(int *)(param_1 + 0x2a88) != *(int *)(param_1 + 0x2a74))) {
      *(int *)(param_1 + 0x2a84) = iVar4;
      *(undefined4 *)(param_1 + 0x2a88) = *(undefined4 *)(param_1 + 0x2a74);
      ((int (*)())FUN_000179c6)(param_1,iVar4,*(uint *)(param_1 + 0x2a74) < 2);
    }
  }
  return;
}

/* FUN_00018062 @ 0x18062 (229 bytes) */
int FUN_00018062(param_1)
  int param_1;
{
  int iVar1;
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (((*(byte *)(param_1 + 0x155) & 8) != 0) && (*(int *)(param_1 + 0x26a0) != 1)) {
    if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
      ((int (*)())FUN_00017c77)(param_1,0x1000000);
      local_18 = *(uint *)(param_1 + 0x3c) & 0xfffff7ff;
      *(uint *)(param_1 + 0x3c) = local_18;
      iVar1 = *(int *)(param_1 + 0x150);
    }
    else {
      local_18 = *(uint *)(param_1 + 0x3c) & 0xfffff7ff;
      *(uint *)(param_1 + 0x3c) = local_18;
      iVar1 = *(int *)(param_1 + 0x150);
    }
    if (iVar1 == 0) {
      *(uint *)(param_1 + 0x154) = local_18;
    }
    local_1c = *(undefined4 *)(*(int *)(param_1 + 0xf8) + 8);
    local_18 = local_18 & 0xffff3fc0;
    local_14 = *(undefined4 *)(param_1 + 0xfc);
    local_10 = *(undefined4 *)(param_1 + 0x100);
    _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0,&local_1c,4,0,0);
  }
  ((int (*)())FUN_00017de7)(param_1);
  return;
}

/* _gldFlush @ 0x18147 (46 bytes) */
int _gldFlush(param_1)
  int param_1;
{
  if (*(uint *)(param_1 + 0x1dc) <= *(int *)(param_1 + 0x1e4) + 0x28U) {
    return;
  }
  ((int (*)())FUN_00017c77)(param_1,0x1000000);
  return;
}

/* _gldFinish @ 0x18175 (109 bytes) */
int _gldFinish(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
    ((int (*)())FUN_00017c77)(param_1,0x1000000);
  }
  do {
    iVar1 = _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),8,0,0,0,0);
  } while (iVar1 == -0x1ffffd2a);
  return;
}

/* FUN_000181e2 @ 0x181e2 (156 bytes) */
int FUN_000181e2(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x1dc);
  if (*(undefined4 **)(param_1 + 0x1e0) <= puVar2 + 6) {
    ((int (*)())FUN_00017c77)(param_1,0x1000000);
    puVar2 = *(undefined4 **)(param_1 + 0x1dc);
  }
  *(undefined4 **)(param_1 + 0x1dc) = puVar2 + 6;
  *puVar2 = 0x1393;
  puVar2[1] = 0;
  puVar2[2] = 0x5c8;
  puVar2[3] = 0x20000;
  puVar1 = *(uint **)(param_1 + 0x1d8);
  *puVar1 = *puVar1 | (int)(puVar2 + 4) - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x1d8) = puVar2 + 4;
  puVar2[4] = 0x34000000;
  puVar2[5] = *param_2;
  *(undefined1 *)(param_2 + 1) = 0;
  *(undefined4 *)(*param_2 * 8 + *(int *)(param_1 + 0x218) + 4) = 1;
  return;
}

/* FUN_0001827e @ 0x1827e (693 bytes) */
int FUN_0001827e(param_1)
  int param_1;
{
  uint *puVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint local_2c;
  uint local_28;
  
  cVar2 = ((int (*)())FUN_00017bd8)(param_1,1);
  if (cVar2 != '\0') {
    FUN_00020d0f(param_1,0,1,0,0,0,*(undefined4 *)(param_1 + 0x15c),*(undefined4 *)(param_1 + 0x160)
                );
  }
  ((int (*)())FUN_00017c77)(param_1,0x3000000);
  if ((*(byte *)(*(int *)(param_1 + 0x1e4) + 0x14) & 2) != 0) {
    puVar4 = *(undefined4 **)(param_1 + 0xf8);
    if (*(char *)(param_1 + 0x144) == '\0') {
      cVar2 = *(char *)(param_1 + 0x142);
      uVar5 = 0;
      iVar3 = 0;
    }
    else {
      cVar2 = *(char *)(param_1 + 0x142);
      uVar5 = *(undefined4 *)(param_1 + 0x108);
      iVar3 = param_1 + 0x124;
    }
    (**(code **)(PTR_DAT_002131ad + 0x10))(*puVar4,puVar4[1],puVar4[2],iVar3,uVar5,cVar2 != '\0');
  }
  puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  if (*(undefined4 **)(param_1 + 0x1e0) <= puVar4 + 5) {
    ((int (*)())FUN_00017c77)(param_1,0x1000000);
    puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  }
  *(undefined4 **)(param_1 + 0x1dc) = puVar4 + 5;
  puVar1 = *(uint **)(param_1 + 0x1d8);
  *puVar1 = *puVar1 | (int)puVar4 - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x1d8) = puVar4;
  *puVar4 = 0x28000000;
  do {
    iVar3 = _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),8,0,0,0,0);
  } while (iVar3 == -0x1ffffd2a);
  if (*(char *)(param_1 + 0x2a68) != '\0') {
    *(undefined1 *)(param_1 + 0x2a68) = 0;
    *(undefined1 *)(param_1 + 0x2a69) = 1;
    *(undefined4 *)(param_1 + 0x2a8c) = *(undefined4 *)(param_1 + 0x2a78);
    *(undefined4 *)(param_1 + 0x2a90) = *(undefined4 *)(param_1 + 0x2a7c);
    cVar2 = *(char *)(param_1 + 0x2a6c);
    if (*(char *)(param_1 + 0x2a80) != cVar2) {
      *(char *)(param_1 + 0x2a80) = cVar2;
      if (cVar2 == '\x01') {
        local_2c = 0;
        local_28 = 0;
      }
      else if (cVar2 == '\x02') {
        local_2c = 1;
        local_28 = 1;
      }
      else {
        local_2c = (uint)*(byte *)(param_1 + 0x142);
        local_28 = (uint)*(byte *)(param_1 + 0x146);
      }
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),2,&local_2c,2,0,0);
    }
    iVar3 = *(int *)(param_1 + 0x2a70);
    if ((*(int *)(param_1 + 0x2a84) != iVar3) ||
       (*(int *)(param_1 + 0x2a88) != *(int *)(param_1 + 0x2a74))) {
      *(int *)(param_1 + 0x2a84) = iVar3;
      *(undefined4 *)(param_1 + 0x2a88) = *(undefined4 *)(param_1 + 0x2a74);
      ((int (*)())FUN_000179c6)(param_1,iVar3,*(uint *)(param_1 + 0x2a74) < 2);
    }
  }
  return;
}

/* FUN_00018533 @ 0x18533 (635 bytes) */
int FUN_00018533(param_1)
  int param_1;
{
  uint *puVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint local_2c;
  uint local_28;
  
  cVar2 = ((int (*)())FUN_00017bd8)(param_1,1);
  if (cVar2 != '\0') {
    FUN_00020d0f(param_1,0,1,0,0,0,*(undefined4 *)(param_1 + 0x15c),*(undefined4 *)(param_1 + 0x160)
                );
  }
  ((int (*)())FUN_00017c77)(param_1,0x3000000);
  if ((*(byte *)(*(int *)(param_1 + 0x1e4) + 0x14) & 2) != 0) {
    puVar3 = *(undefined4 **)(param_1 + 0xf8);
    if (*(char *)(param_1 + 0x144) == '\0') {
      cVar2 = *(char *)(param_1 + 0x142);
      uVar5 = 0;
      iVar4 = 0;
    }
    else {
      cVar2 = *(char *)(param_1 + 0x142);
      uVar5 = *(undefined4 *)(param_1 + 0x108);
      iVar4 = param_1 + 0x124;
    }
    (**(code **)(PTR_DAT_002131ad + 0x10))(*puVar3,puVar3[1],puVar3[2],iVar4,uVar5,cVar2 != '\0');
  }
  puVar3 = *(undefined4 **)(param_1 + 0x1dc);
  if (*(undefined4 **)(param_1 + 0x1e0) <= puVar3 + 5) {
    ((int (*)())FUN_00017c77)(param_1,0x1000000);
    puVar3 = *(undefined4 **)(param_1 + 0x1dc);
  }
  *(undefined4 **)(param_1 + 0x1dc) = puVar3 + 5;
  puVar1 = *(uint **)(param_1 + 0x1d8);
  *puVar1 = *puVar1 | (int)puVar3 - (int)puVar1 >> 2;
  *(undefined4 **)(param_1 + 0x1d8) = puVar3;
  *puVar3 = 0x28000000;
  if (*(char *)(param_1 + 0x2a68) != '\0') {
    *(undefined1 *)(param_1 + 0x2a68) = 0;
    *(undefined1 *)(param_1 + 0x2a69) = 1;
    *(undefined4 *)(param_1 + 0x2a8c) = *(undefined4 *)(param_1 + 0x2a78);
    *(undefined4 *)(param_1 + 0x2a90) = *(undefined4 *)(param_1 + 0x2a7c);
    cVar2 = *(char *)(param_1 + 0x2a6c);
    if (*(char *)(param_1 + 0x2a80) != cVar2) {
      *(char *)(param_1 + 0x2a80) = cVar2;
      if (cVar2 == '\x01') {
        local_2c = 0;
        local_28 = 0;
      }
      else if (cVar2 == '\x02') {
        local_2c = 1;
        local_28 = 1;
      }
      else {
        local_2c = (uint)*(byte *)(param_1 + 0x142);
        local_28 = (uint)*(byte *)(param_1 + 0x146);
      }
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),2,&local_2c,2,0,0);
    }
    iVar4 = *(int *)(param_1 + 0x2a70);
    if ((*(int *)(param_1 + 0x2a84) != iVar4) ||
       (*(int *)(param_1 + 0x2a88) != *(int *)(param_1 + 0x2a74))) {
      *(int *)(param_1 + 0x2a84) = iVar4;
      *(undefined4 *)(param_1 + 0x2a88) = *(undefined4 *)(param_1 + 0x2a74);
      ((int (*)())FUN_000179c6)(param_1,iVar4,*(uint *)(param_1 + 0x2a74) < 2);
    }
  }
  return;
}

/* FUN_000187ae @ 0x187ae (390 bytes) */
int FUN_000187ae(param_1)
  int param_1;
{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_1 == 0) {
    return 0x271e;
  }
  uVar6 = *(uint *)(param_1 + 0x30);
  if ((uVar6 == 0) || ((uVar6 & ~*(uint *)PTR_DAT_002131ad) != 0)) {
    return 0x2716;
  }
  uVar3 = *(uint *)(param_1 + 8);
  uVar5 = uVar3 >> 1 & 1;
  if (uVar5 != 0) {
    for (; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1) {
    }
    if (uVar6 != 1) {
      return 0x2716;
    }
  }
  if ((((((*(uint *)(param_1 + 4) & 0xff00) == 0x1900) && (*(short *)(param_1 + 0x20) == 0)) &&
       (((*(uint *)(param_1 + 0xc) & 2) == 0 || (uVar5 != 0)))) && (*(ushort *)(param_1 + 0x22) < 3)
      ) && ((((uVar3 & 0x2000) == 0 || (*(int *)(param_1 + 0x24) == 0)) &&
            (uVar1 = *(ushort *)(param_1 + 0x24), uVar1 < 2)))) {
    if (uVar1 == 0) {
      if (*(short *)(param_1 + 0x26) != 0) {
        return 0x2712;
      }
    }
    else if (((uVar1 == 1) && (sVar2 = *(short *)(param_1 + 0x26), sVar2 != 6)) &&
            ((sVar2 != 4 && (sVar2 != 2)))) {
      return 0x2712;
    }
    if (((((uVar3 & 0xffffd064) == 0) &&
         (((uVar3 & 8) == 0 || ((*(uint *)(param_1 + 0xc) & 8) != 0)))) &&
        ((*(uint *)(param_1 + 0x10) & 0xf57f7bff) == 0)) &&
       (((*(uint *)(param_1 + 0x10) & 0xa800000) == 0 || ((uVar1 == 0 && ((uVar3 & 0x400) == 0))))))
    {
      iVar4 = *(int *)(param_1 + 0x1c);
      if (iVar4 == 1) {
        uVar6 = 0xffffe3fe;
      }
      else {
        if (iVar4 != 0x80) {
          return 0x2712;
        }
        uVar6 = 0xfffff7ff;
      }
      if (((*(uint *)(param_1 + 0x18) & uVar6) == 0) &&
         ((((*(uint *)(param_1 + 0x18) != 1 || (iVar4 != 1)) || ((uVar3 & 0x800) == 0)) &&
          ((uVar6 = *(uint *)(param_1 + 0x14), (uVar6 & 0xff7f7fff) == 0 &&
           ((uVar6 & uVar6 - 1) == 0)))))) {
        return 0;
      }
    }
  }
  return 0x2712;
}

/* FUN_00018934 @ 0x18934 (919 bytes) */
int FUN_00018934(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  undefined4 *puVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((param_1[7] & 1) == 0) {
    param_1[7] = param_1[7] & 0x80;
    if (param_2 == '\0') {
      param_1[6] = 0x800;
    }
    else {
      param_1[6] = param_1[6] & 0x800;
    }
  }
  else {
    param_1[7] = 1;
    uVar4 = param_1[6];
    param_1[6] = uVar4 & 0x1c01;
    if (param_2 == '\0') {
      if (param_3 == '\0') goto LAB_00018975;
LAB_00018c83:
      if ((uVar4 & 1) == 0) {
        param_1[6] = 0x1000;
        goto LAB_000189b4;
      }
LAB_0001897d:
      param_1[6] = 1;
      uVar4 = param_1[5];
      goto joined_r0x000189b9;
    }
    if ((uVar4 & 0x1c01) != 0) {
      if (param_3 != '\0') goto LAB_00018c83;
LAB_00018975:
      if ((uVar4 & 1) != 0) goto LAB_0001897d;
      if ((uVar4 & 0x400) == 0) {
        param_1[6] = (-(uint)((uVar4 & 0x800) == 0) & 0x800) + 0x800;
      }
      else {
        param_1[6] = 0x400;
      }
    }
  }
LAB_000189b4:
  uVar4 = param_1[5];
joined_r0x000189b9:
  if ((int)uVar4 < 0) {
    param_1[5] = 0;
    bVar2 = *(byte *)(param_1 + 3);
  }
  else {
    if ((short)uVar4 < 0) {
      param_1[5] = 0x8000;
    }
    else {
      param_1[5] = -(uint)((uVar4 & 0x800000) == 0) | 0x800000;
    }
    bVar2 = *(byte *)(param_1 + 3);
  }
  if ((bVar2 & 8) == 0) {
    uVar4 = param_1[2] & 0xfffffff7;
    param_1[2] = uVar4;
  }
  else {
    uVar4 = param_1[2];
  }
  if ((uVar4 & 0x2000) != 0) {
    *(undefined2 *)((int)param_1 + 0x26) = 0;
    *(undefined2 *)(param_1 + 9) = 0;
  }
  if (*(short *)(param_1 + 9) == 0) {
    *(undefined2 *)((int)param_1 + 0x26) = 0;
  }
  else {
    if (*(short *)(param_1 + 9) != 1) {
      *(undefined2 *)(param_1 + 9) = 1;
    }
    if (*(short *)((int)param_1 + 0x26) < 5) {
      *(ushort *)((int)param_1 + 0x26) = (ushort)(2 < *(short *)((int)param_1 + 0x26)) * 2 + 2;
    }
    else {
      *(undefined2 *)((int)param_1 + 0x26) = 6;
    }
  }
  uVar4 = param_1[4];
  param_1[0xd] = *param_1;
  param_1[0xe] = param_1[1];
  param_1[0xf] = param_1[2];
  param_1[0x10] = param_1[3];
  param_1[0x11] = param_1[4];
  param_1[0x12] = param_1[5];
  param_1[0x13] = param_1[6];
  param_1[0x14] = param_1[7];
  param_1[0x15] = param_1[8];
  param_1[0x16] = param_1[9];
  param_1[0x17] = param_1[10];
  param_1[0x18] = param_1[0xb];
  param_1[0x19] = param_1[0xc];
  param_1[4] = 0x400;
  param_1[0x11] = 0x8000;
  if ((uVar4 & 0x800000) == 0) {
    iVar7 = 2;
  }
  else {
    param_1[0x1a] = *param_1;
    param_1[0x1b] = param_1[1];
    param_1[0x1c] = param_1[2];
    param_1[0x1d] = param_1[3];
    param_1[0x1e] = param_1[4];
    param_1[0x1f] = param_1[5];
    param_1[0x20] = param_1[6];
    param_1[0x21] = param_1[7];
    param_1[0x22] = param_1[8];
    param_1[0x23] = param_1[9];
    param_1[0x24] = param_1[10];
    param_1[0x25] = param_1[0xb];
    param_1[0x26] = param_1[0xc];
    *(undefined2 *)(param_1 + 0x23) = 0;
    *(undefined2 *)((int)param_1 + 0x8e) = 0;
    param_1[0x1e] = 0x800000;
    param_1[0x1c] = param_1[2] & 0xfffffbff;
    iVar7 = 3;
  }
  if ((uVar4 & 0x2000000) != 0) {
    puVar1 = param_1 + iVar7 * 0xd;
    *puVar1 = *param_1;
    puVar1[1] = param_1[1];
    uVar3 = param_1[2];
    puVar1[2] = uVar3;
    puVar1[3] = param_1[3];
    puVar1[4] = param_1[4];
    puVar1[5] = param_1[5];
    puVar1[6] = param_1[6];
    puVar1[7] = param_1[7];
    puVar1[8] = param_1[8];
    puVar1[9] = param_1[9];
    puVar1[10] = param_1[10];
    puVar1[0xb] = param_1[0xb];
    puVar1[0xc] = param_1[0xc];
    *(undefined2 *)(puVar1 + 9) = 0;
    *(undefined2 *)((int)puVar1 + 0x26) = 0;
    puVar1[4] = 0x2000000;
    puVar1[2] = uVar3 & 0xfffffbff;
    iVar7 = iVar7 + 1;
  }
  if ((uVar4 & 0x8000000) != 0) {
    puVar1 = param_1 + iVar7 * 0xd;
    *puVar1 = *param_1;
    puVar1[1] = param_1[1];
    uVar4 = param_1[2];
    puVar1[2] = uVar4;
    puVar1[3] = param_1[3];
    puVar1[4] = param_1[4];
    puVar1[5] = param_1[5];
    puVar1[6] = param_1[6];
    puVar1[7] = param_1[7];
    puVar1[8] = param_1[8];
    puVar1[9] = param_1[9];
    puVar1[10] = param_1[10];
    puVar1[0xb] = param_1[0xb];
    puVar1[0xc] = param_1[0xc];
    *(undefined2 *)(puVar1 + 9) = 0;
    *(undefined2 *)((int)puVar1 + 0x26) = 0;
    puVar1[4] = 0x8000000;
    puVar1[2] = uVar4 & 0xfffffbff;
    iVar7 = iVar7 + 1;
  }
  if (iVar7 != 0) {
    iVar6 = 0;
    do {
      iVar5 = ((int (*)())FUN_000187ae)(param_1);
      if (iVar5 != 0) {
        return 0;
      }
      iVar6 = iVar6 + 1;
      param_1 = param_1 + 0xd;
    } while (iVar7 != iVar6);
  }
  return iVar7;
}

/* FUN_00018ccb @ 0x18ccb (59 bytes) */
int FUN_00018ccb(param_1)
  int param_1;
{
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 1;
  *(undefined2 *)(param_1 + 0x24) = 2;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x5000;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 2;
  *(undefined2 *)(param_1 + 0x26) = 1;
  *(undefined2 *)(param_1 + 0x28) = 6;
  *(undefined4 *)(param_1 + 0x2c) = 3;
  *(undefined1 *)(param_1 + 0x2a) = 1;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0xa800000;
  return;
}

/* _gldFreeVertexBuffer @ 0x18d08 (19 bytes) */
int _gldFreeVertexBuffer(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if (param_2 != 0) {
    *(undefined4 *)(param_2 + -0x6c) = 1;
  }
  return;
}

/* _gldCompleteVertexBuffer @ 0x18d1b (5 bytes) */
int _gldCompleteVertexBuffer()
{
  return;
}

/* _gldAllocVertexBuffer @ 0x18d20 (82 bytes) */
int _gldAllocVertexBuffer(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int *param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_28;
  int iStack_24;
  undefined4 local_20 [4];
  
  local_20[0] = 8;
  iVar2 = *param_3;
  *param_3 = 0;
  if (0x800 < iVar2) {
    return 0;
  }
  if (*(char *)(param_1 + 0x20) == '\0') {
    return 0;
  }
  switch(param_2 & 0x7fff) {
  default:
    goto code_r0x00018d49;
  case 1:
    uStack_44 = 9;
    break;
  case 2:
    uStack_44 = 10;
    break;
  case 3:
    uStack_44 = 0xb;
    break;
  case 4:
    uStack_44 = 0xc;
    break;
  case 5:
    uStack_44 = 0xd;
    break;
  case 6:
    uStack_44 = 0xe;
  }
  if (*(int *)(param_1 + 0x210) == 0) {
    uStack_3c = 2;
    uStack_38 = 0x16000;
    iVar2 = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(param_1 + 4),10,&uStack_3c,0x14,&iStack_28,local_20);
    if (iVar2 != 0) {
      return 0;
    }
    iStack_40 = iStack_28;
    *(int *)(iStack_28 + 0x1c) = iStack_24;
    *(int *)(iStack_24 + 0x10) = *(int *)(iStack_24 + 0x10) + 0x10000;
    *(undefined1 *)(iStack_24 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x214) = 1;
    *(int *)(iStack_28 + 0x10) = iStack_28;
    goto code_r0x00018e20;
  }
  iStack_40 = *(int *)(*(int *)(param_1 + 0x210) + 0x10);
  iVar2 = *(int *)(iStack_40 + 0x1c);
  if (*(int *)(iStack_40 + 0x14) == 0) {
    if (0x7f < *(uint *)(param_1 + 0x214)) {
      return 0;
    }
  }
  else if (*(int *)(iStack_40 + 0x18) == *(int *)(param_1 + 0x23c)) {
    if (0x7f < *(uint *)(param_1 + 0x214)) {
      ((int (*)())FUN_00017c77)(param_1,0x1000000);
      iVar3 = 0;
      iVar2 = *(int *)(iVar2 + 8);
      do {
        if (iVar2 == **(int **)(param_1 + 0x238) || iVar2 - **(int **)(param_1 + 0x238) < 0) break;
        iVar3 = iVar3 + 1;
      } while (iVar3 != 0xf4241);
code_r0x00018e16:
      *(undefined4 *)(iStack_40 + 0x14) = 0;
      goto code_r0x00018e20;
    }
  }
  else {
    iVar2 = *(int *)(iVar2 + 8);
    iVar3 = **(int **)(param_1 + 0x238);
    if (iVar2 == iVar3 || iVar2 - iVar3 < 0) {
      *(undefined4 *)(iStack_40 + 0x14) = 0;
      goto code_r0x00018e20;
    }
    if (0x7f < *(uint *)(param_1 + 0x214)) {
      iVar3 = 0;
      do {
        iVar1 = **(int **)(param_1 + 0x238);
        if (iVar2 == iVar1 || iVar2 - iVar1 < 0) break;
        iVar3 = iVar3 + 1;
      } while (iVar3 != 0xf4241);
      goto code_r0x00018e16;
    }
  }
  uStack_38 = 0x16000;
  uStack_3c = 2;
  iVar2 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,&uStack_3c,0x14,&iStack_28,local_20);
  if (iVar2 != 0) {
code_r0x00018d49:
    return 0;
  }
  iStack_40 = iStack_28;
  *(int *)(iStack_28 + 0x1c) = iStack_24;
  *(int *)(iStack_24 + 0x10) = *(int *)(iStack_24 + 0x10) + 0x10000;
  *(undefined1 *)(iStack_24 + 0x14) = 1;
  *(int *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + 1;
  *(undefined4 *)(iStack_28 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x210) + 0x10);
  *(int *)(*(int *)(param_1 + 0x210) + 0x10) = iStack_28;
code_r0x00018e20:
  *(int *)(param_1 + 0x210) = iStack_40;
  *(int *)(iStack_40 + 0x18) = *(int *)(param_1 + 0x23c) + -1;
  *(undefined4 *)(iStack_40 + 0xc) = uStack_44;
  *param_3 = 0x800;
  return iStack_40 + 0x80;
}

/* FUN_00019040 @ 0x19040 (32 bytes) */
int FUN_00019040(param_1)
  int param_1;
{
  *(bool *)(param_1 + 0x2b7c) = (*(uint *)(param_1 + 0x154) & 0x70000000) == 0;
  *(undefined1 *)(param_1 + 0x2b7d) = 1;
  return;
}

/* FUN_00019060 @ 0x19060 (5 bytes) */
int FUN_00019060()
{
  return;
}

/* FUN_00019065 @ 0x19065 (10 bytes) */
int FUN_00019065()
{
  return 1;
}

/* FUN_0001906f @ 0x1906f (1199 bytes) */
int FUN_0001906f(param_1, param_2)
  int param_1;
  int *param_2;
{
  byte bVar1;
  undefined *puVar2;
  char cVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_48;
  int *local_40;
  uint local_38;
  int local_34;
  int local_30;
  int *local_28;
  
  *(undefined4 *)(param_2[1] + 0x18) = 0;
  iVar10 = 0;
  piVar4 = param_2;
  do {
    piVar4[0x13] = 0;
    iVar10 = iVar10 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar10 != 6);
  *(undefined1 *)(param_2 + 4) = 1;
  *(undefined1 *)((int)param_2 + 0x11) = 0;
  *(undefined1 *)((int)param_2 + 0x12) = 0;
  param_2[5] = 0;
  param_2[0xc] = 0;
  param_2[0xd] = 0;
  param_2[0xe] = 0;
  param_2[0xf] = 0;
  param_2[0x10] = 0;
  param_2[0x11] = 0;
  param_2[0x12] = 0;
  local_40 = (int *)param_2[1];
  if ((local_40[4] != 0) && (local_40[5] != 0)) goto LAB_000190f8;
  if ((*(int *)(*(int *)(param_1 + 0x14) + 0xc) < (int)(uint)*(ushort *)(*param_2 + 0x9a)) ||
     (*(int *)(*(int *)(param_1 + 0x14) + 0x10) < (int)(uint)*(ushort *)(*param_2 + 0x9c)))
  goto LAB_000190f8;
  local_30 = 0;
  iVar10 = 0;
  do {
    iVar9 = local_40[iVar10];
    if (iVar9 != 0) {
      if (iVar10 < 4) {
        local_30 = iVar9;
      }
      cVar3 = FUN_0002fdb4(param_1,iVar9);
      if (cVar3 == '\0') {
        local_40 = (int *)param_2[1];
        goto LAB_000190f8;
      }
      local_40 = (int *)param_2[1];
    }
    puVar2 = PTR_DAT_002131c9;
    iVar10 = iVar10 + 1;
  } while (iVar10 != 6);
  if (local_30 == 0) {
    *(undefined1 *)((int)param_2 + 0x13) = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    param_2[8] = 0;
    param_2[9] = 0;
  }
  else {
    bVar1 = *(byte *)(local_30 + 0x38);
    param_2[6] = (uint)((byte)PTR_DAT_002131c9[(uint)bVar1 * 0x24 + 0x11] >> 2);
    param_2[7] = (uint)(puVar2[(uint)bVar1 * 0x24 + 0x12] & 0x3f);
    param_2[8] = *(ushort *)(puVar2 + (uint)bVar1 * 0x24 + 0x12) >> 6 & 0x3f;
    if ((((puVar2[(uint)bVar1 * 0x24 + 0x11] & 0xfc) == 0) ||
        ((puVar2[(uint)bVar1 * 0x24 + 0x12] & 0x3f) == 0)) ||
       ((*(ushort *)(puVar2 + (uint)bVar1 * 0x24 + 0x12) & 0xfc0) == 0)) {
      uVar7 = (uint)(byte)puVar2[(uint)bVar1 * 0x24 + 0x14];
LAB_000191f0:
      param_2[9] = uVar7 & 0x3f;
    }
    else {
      uVar7 = (uint)(byte)puVar2[(uint)bVar1 * 0x24 + 0x14];
      if (((puVar2[(uint)bVar1 * 0x24 + 0x14] & 0x3f) == 0) ||
         (*(short *)(*(int *)(local_30 + 0x30) + 2) != 0x1907)) goto LAB_000191f0;
      param_2[9] = 0;
    }
    *(byte *)((int)param_2 + 0x13) = puVar2[(uint)bVar1 * 0x24 + 0x21] & 1;
    if (-1 < (char)puVar2[(uint)bVar1 * 0x24 + 0x19]) goto LAB_000190f8;
  }
  iVar10 = local_40[4];
  if (iVar10 == 0) {
    param_2[10] = 0;
  }
  else {
    param_2[10] = (uint)((byte)PTR_DAT_002131c9[(uint)*(byte *)(iVar10 + 0x38) * 0x24 + 0x16] >> 2);
    if ((*(char *)(iVar10 + 0x38) != '\x10') && (*(char *)(iVar10 + 0x38) != ')'))
    goto LAB_000190f8;
  }
  iVar9 = local_40[5];
  if (iVar9 == 0) {
    param_2[0xb] = 0;
  }
  else {
    param_2[0xb] = (uint)(PTR_DAT_002131c9[(uint)*(byte *)(iVar9 + 0x38) * 0x24 + 0x17] & 0xf);
    if ((*(char *)(iVar9 + 0x38) != ')') || ((iVar10 != 0 && (iVar10 != iVar9)))) {
LAB_000190f8:
      local_40[7] = 1;
      return 0;
    }
  }
  iVar10 = 0;
  piVar4 = param_2;
  do {
    if (local_40[iVar10] != 0) {
      piVar4[0x13] = *(int *)(local_40[iVar10] + 0x34);
    }
    iVar10 = iVar10 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar10 != 6);
  piVar4 = local_40;
  do {
    if (*piVar4 != 0) {
      switch(*(undefined1 *)(*piVar4 + 0x38)) {
      case 5:
        local_38 = 0x4000;
        uVar7 = 5;
        break;
      case 6:
      case 7:
        local_38 = 0x4000;
        uVar7 = 3;
        break;
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0x23:
      case 0x24:
        local_38 = 0x4000;
        uVar7 = 4;
        break;
      default:
        local_38 = 0x4000;
        uVar7 = 0;
        break;
      case 0x11:
      case 0x12:
        local_38 = 0x4000;
        uVar7 = 0xd;
        break;
      case 0x17:
      case 0x18:
        local_38 = 0x4000;
        uVar7 = 0xb;
        break;
      case 0x1d:
      case 0x1e:
        local_38 = 0x4000;
        uVar7 = 0xc;
      }
      goto LAB_000192c3;
    }
    piVar4 = piVar4 + 1;
  } while (piVar4 != local_40 + 4);
  local_38 = 0;
  uVar7 = 0;
LAB_000192c3:
  uVar5 = uVar7;
  if (local_40[4] != 0) {
    local_38 = local_38 | 0x100;
    cVar3 = *(char *)(local_40[4] + 0x38);
    if (cVar3 == '\x10') {
      uVar5 = uVar7 | 0x10040;
    }
    else {
      uVar5 = uVar7 | 0x40;
      if (cVar3 == ')') {
        uVar5 = uVar7 | 0x20040;
      }
    }
  }
  uVar7 = uVar5;
  if (local_40[5] != 0) {
    local_38 = local_38 | 0x400;
    uVar7 = uVar5 | 0x30080;
    if (*(char *)(local_40[5] + 0x38) != ')') {
      uVar7 = uVar5 | 0x80;
    }
  }
  local_28 = param_2;
  local_34 = 0;
  local_48 = 0;
  do {
    piVar4 = (int *)local_40[local_34];
    if (piVar4 == (int *)0x0) {
      local_28[0x2b] = -1;
      local_28[0x19] = 0;
      local_28[0x1f] = 0;
      local_28[0x25] = 0;
    }
    else {
      iVar10 = *param_2;
      iVar6 = local_48 + iVar10;
      iVar9 = *(int *)(iVar6 + 8);
      if (*(char *)(piVar4[0xd] + 0x16) == '\x06') {
        iVar11 = (uint)*(ushort *)((int)piVar4 + 0x3e) <<
                 ((byte)PTR_DAT_002131c9[(uint)*(byte *)(piVar4 + 0xe) * 0x24 + 0x17] >> 5);
        if (iVar9 != 0) {
          iVar6 = 0;
          do {
            iVar11 = iVar11 / 2;
            iVar6 = iVar6 + 1;
          } while (iVar6 != iVar9);
        }
        iVar9 = 0;
      }
      else {
        iVar11 = *(int *)(*piVar4 + 0xc);
        if (iVar9 != 0) {
          iVar8 = 0;
          do {
            iVar11 = iVar11 / 2;
            iVar8 = iVar8 + 1;
          } while (iVar8 != iVar9);
        }
        iVar9 = *(int *)(iVar6 + 0xc) * iVar11 * (uint)*(ushort *)(iVar10 + 0x9c) +
                *(int *)(*piVar4 + (*(int *)(iVar6 + 4) * 0xd + iVar9) * 0x20 + 0x48);
      }
      local_28[0x2b] = *(int *)piVar4[0xd];
      local_28[0x19] = iVar9;
      local_28[0x1f] = iVar11;
      local_28[0x25] = (uint)*(ushort *)(iVar10 + 0x9a);
    }
    local_34 = local_34 + 1;
    local_48 = local_48 + 0x18;
    local_28 = local_28 + 1;
  } while (local_34 != 6);
  param_2[3] = uVar7;
  param_2[2] = local_38;
  local_40[7] = 0;
  *(undefined1 *)((int)param_2 + 0xc5) = 1;
  *(undefined1 *)(param_2 + 0x31) = 0;
  *(undefined1 *)((int)param_2 + 0xc6) = 0;
  return 1;
}

/* FUN_00019607 @ 0x19607 (786 bytes) */
int FUN_00019607(param_1, param_2)
  int param_1;
  int *param_2;
{
  ushort uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int local_10;
  
  *(undefined1 *)(param_1 + 0x2b7c) = 0;
  puVar2 = (uint *)(**(code **)(param_1 + 0x2998))(param_1 + 0x240,0x83);
  *(uint **)(param_1 + 0x298c) = puVar2;
  puVar3 = (undefined4 *)((uint)(puVar2 + 0xb) & 0xffffffe0);
  *puVar2 = (((int)puVar3 - (int)puVar2) + -8) * 0x4000 | 0xc0001000;
  puVar3[-1] = (int)puVar3 - (int)puVar2;
  puVar2 = *(uint **)(param_1 + 0x1d8);
  *puVar2 = *puVar2 | (int)puVar3 - (int)puVar2 >> 2;
  *(undefined4 **)(param_1 + 0x1d8) = puVar3;
  *puVar3 = 0x41000000;
  puVar3[1] = 4;
  puVar3[2] = (uint)*(ushort *)(*param_2 + 0x9a);
  puVar3[3] = (uint)*(ushort *)(*param_2 + 0x9c);
  puVar3[4] = *(undefined4 *)(param_1 + 0x1d20);
  puVar3[5] = *(undefined4 *)(param_1 + 0x1cf0);
  local_10 = 0;
  piVar8 = puVar3 + 6;
  do {
    piVar7 = piVar8;
    uVar1 = *(ushort *)(*param_2 + 0x90 + local_10 * 2);
    if (uVar1 == 0) {
      *piVar7 = -1;
      piVar7[1] = 0;
      piVar7[2] = 0;
      piVar7[3] = 0;
      piVar7[4] = 0;
      piVar7[5] = 0;
    }
    else {
      uVar4 = (uint)uVar1;
      iVar5 = uVar4 - 0x8ce0;
      *piVar7 = param_2[uVar4 - 0x8cb5];
      piVar7[1] = param_2[uVar4 - 0x8cc7];
      piVar7[2] = param_2[uVar4 - 0x8cc1];
      piVar7[3] = param_2[uVar4 - 0x8cbb];
      iVar6 = iVar5 * 0x18 + *param_2;
      piVar7[4] = *(int *)(iVar6 + 4) << 0x10 | *(uint *)(iVar6 + 8);
      piVar7[5] = (uint)*(byte *)(*(int *)(param_2[1] + iVar5 * 4) + 0x38);
      *(undefined1 *)(*(int *)(param_2[1] + iVar5 * 4) + 200) = 0;
      iVar5 = *(int *)(*(int *)(param_2[1] + iVar5 * 4) + 0x34);
      *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + 0x10000;
    }
    piVar8 = piVar7 + 6;
    local_10 = local_10 + 1;
  } while (local_10 != 4);
  if (*(int *)(param_2[1] + 0x10) == 0) {
    *piVar8 = -1;
    piVar7[7] = 0;
    piVar7[8] = 0;
    piVar7[9] = 0;
    piVar7[10] = 0;
    piVar7[0xb] = 0;
  }
  else {
    *piVar8 = param_2[0x2f];
    piVar7[7] = param_2[0x1d];
    piVar7[8] = param_2[0x23];
    piVar7[9] = param_2[0x29];
    piVar7[10] = *(int *)(*param_2 + 100) << 0x10 | *(uint *)(*param_2 + 0x68);
    piVar7[0xb] = (uint)*(byte *)(*(int *)(param_2[1] + 0x10) + 0x38);
    *(undefined1 *)(*(int *)(param_2[1] + 0x10) + 200) = 0;
    iVar5 = *(int *)(*(int *)(param_2[1] + 0x10) + 0x34);
    *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + 0x10000;
  }
  if (*(int *)(param_2[1] + 0x14) == 0) {
    piVar7[0xc] = -1;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    piVar7[0x10] = 0;
    piVar7[0x11] = 0;
  }
  else {
    piVar7[0xc] = param_2[0x30];
    piVar7[0xd] = param_2[0x1e];
    piVar7[0xe] = param_2[0x24];
    piVar7[0xf] = param_2[0x2a];
    piVar7[0x10] = *(int *)(*param_2 + 0x7c) << 0x10 | *(uint *)(*param_2 + 0x80);
    piVar7[0x11] = (uint)*(byte *)(*(int *)(param_2[1] + 0x14) + 0x38);
    *(undefined1 *)(*(int *)(param_2[1] + 0x14) + 200) = 0;
    iVar5 = *(int *)(*(int *)(param_2[1] + 0x14) + 0x34);
    *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + 0x10000;
  }
  *(int **)(param_1 + 0x298c) = piVar7 + 0x4b;
  (**(code **)(param_1 + 0x299c))(param_1 + 0x240,piVar7 + 0x4b);
  if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
    ((int (*)())FUN_00017c77)(param_1,0x1000000);
  }
  *(undefined1 *)(param_1 + 0x2b7d) = 1;
  return;
}

/* FUN_0001991c @ 0x1991c (806 bytes) */
int FUN_0001991c(param_1, param_2)
  byte *param_1;
  byte *param_2;
{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  byte *local_88;
  int local_6c;
  int local_68;
  int local_64;
  byte *local_60;
  byte local_54 [8];
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  undefined4 local_3c;
  undefined4 local_38;
  byte local_34;
  undefined4 local_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  byte local_14 [8];
  
  local_14[1] = 0xff;
  iVar3 = 0x10;
  pbVar4 = param_1;
  bVar1 = 0;
  do {
    bVar2 = *pbVar4;
    pbVar4 = pbVar4 + 4;
    if (bVar2 < local_14[1]) {
      local_14[1] = bVar2;
    }
    if (bVar2 <= bVar1) {
      bVar2 = bVar1;
    }
    iVar3 = iVar3 + -1;
    bVar1 = bVar2;
  } while (iVar3 != 0);
  local_14[0] = bVar2;
  if (local_14[1] == 0) {
    if (bVar2 == 0xff) goto LAB_000199fb;
  }
  else if (bVar2 != 0xff) goto LAB_000199fb;
  local_14[0] = local_14[1];
  local_14[1] = bVar2;
LAB_000199fb:
  local_6c = 0;
  do {
    local_60 = param_1 + local_6c * 0x10;
    local_88 = local_54 + local_6c * 0x10;
    local_68 = 0;
    do {
      uVar5 = 0xff;
      local_64 = 0;
      iVar3 = 0;
      do {
        if ((uint)local_14[iVar3] - (uint)local_60[3] < uVar5) {
          uVar5 = (uint)local_14[iVar3] - (uint)local_60[3];
          local_64 = iVar3;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != 8);
      *(int *)local_88 = local_64;
      local_68 = local_68 + 1;
      local_60 = local_60 + 4;
      local_88 = local_88 + 4;
    } while (local_68 != 4);
    local_6c = local_6c + 1;
  } while (local_6c != 4);
  *param_2 = local_14[0];
  param_2[1] = local_14[1];
  param_2[2] = (char)local_4c << 6 | (char)(*(unsigned int *)((unsigned char *)&(local_54) + 4)) << 3 | local_54[0];
  param_2[3] = (char)local_40 << 7 | (char)local_44 << 4 | (char)local_48 * '\x02' |
               (byte)((local_4c & 4) >> 2);
  param_2[4] = (char)local_38 << 5 | (char)local_3c << 2 | (byte)((local_40 & 6) >> 1);
  param_2[5] = (char)local_2c << 6 | (char)local_30 << 3 | local_34;
  param_2[6] = (char)local_20 << 7 | (char)local_24 << 4 | (char)local_28 * '\x02' |
               (byte)((local_2c & 4) >> 2);
  param_2[7] = (char)local_18 << 5 | (char)local_1c << 2 | (byte)((local_20 & 6) >> 1);
  return param_2 + 8;
}

/* FUN_00019c42 @ 0x19c42 (494 bytes) */
int FUN_00019c42(param_1, param_2, param_3, param_4)
  uint param_1;
  int param_2;
  int param_3;
  byte *param_4;
{
  byte bVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  byte local_12 [6];
  
  local_12[0] = (byte)(param_1 >> 8);
  local_12[3] = (byte)(param_2 >> 8);
  if (param_2 < (ushort)param_1) {
    local_12[0] = local_12[0] & 0xf8;
    local_12[1] = (char)(param_1 >> 5) << 2;
    local_12[2] = (char)param_1 * '\b';
    local_12[3] = local_12[3] & 0xf8;
    local_12[4] = (char)(param_2 >> 5) << 2;
    local_12[5] = (char)param_2 << 3;
    if (param_3 == 2) {
      *param_4 = (byte)((ulonglong)
                        ((longlong)(int)((uint)local_12[3] + (uint)local_12[0] * 2) * 0x55555556) >>
                       0x20);
      param_4[1] = (byte)((ulonglong)
                          ((longlong)(int)((uint)local_12[4] + (uint)local_12[1] * 2) * 0x55555556)
                         >> 0x20);
      bVar1 = local_12[5];
    }
    else {
      if (param_3 < 2) goto LAB_00019d77;
      if (param_3 != 3) {
        return (uint)param_3;
      }
      *param_4 = (byte)((ulonglong)
                        ((longlong)(int)((uint)local_12[0] + (uint)local_12[3] * 2) * 0x55555556) >>
                       0x20);
      param_4[1] = (byte)((ulonglong)
                          ((longlong)(int)((uint)local_12[1] + (uint)local_12[4] * 2) * 0x55555556)
                         >> 0x20);
      bVar1 = local_12[2];
      local_12[2] = local_12[5];
    }
    lVar2 = (longlong)(int)((uint)bVar1 + (uint)local_12[2] * 2) * 0x55555556;
    param_4[2] = (byte)((ulonglong)lVar2 >> 0x20);
    param_4[3] = 0xff;
    return (uint)lVar2;
  }
  if (param_3 == 3) {
    *param_4 = 0;
    param_4[1] = 0;
    param_4[2] = 0;
    param_4[3] = 0;
    return param_1;
  }
  local_12[0] = local_12[0] & 0xf8;
  local_12[1] = (char)(param_1 >> 5) << 2;
  local_12[2] = (char)param_1 * '\b';
  local_12[3] = local_12[3] & 0xf8;
  local_12[4] = (char)(param_2 >> 5) * '\x04';
  local_12[5] = (char)param_2 << 3;
  if (1 < param_3) {
    if (param_3 != 2) {
      return (uint)param_3;
    }
    *param_4 = (byte)((int)((uint)local_12[0] + (uint)local_12[3]) >> 1);
    param_4[1] = (byte)((int)((uint)local_12[1] + (uint)local_12[4]) >> 1);
    uVar4 = (int)((uint)local_12[2] + (uint)local_12[5]) >> 1;
    param_4[2] = (byte)uVar4;
    param_4[3] = 0xff;
    return uVar4;
  }
LAB_00019d77:
  iVar3 = (uint)param_3 * 3;
  *param_4 = local_12[iVar3];
  param_4[1] = local_12[iVar3 + 1];
  bVar1 = local_12[iVar3 + 2];
  param_4[2] = bVar1;
  param_4[3] = 0xff;
  return (uint)bVar1;
}

/* FUN_00019e30 @ 0x19e30 (4722 bytes) */
int FUN_00019e30(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined *param_5;
  byte *param_6;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  bool bVar6;
  short sVar7;
  short sVar8;
  int iVar9;
  uint uVar10;
  ushort *puVar11;
  byte bVar12;
  int iVar15;
  byte *pbVar16;
  uint *puVar17;
  uint uVar18;
  undefined *puVar19;
  byte bVar20;
  short sVar21;
  int iVar23;
  uint uVar24;
  uint uVar25;
  int iVar26;
  undefined *puVar27;
  byte bVar28;
  uint uVar29;
  byte *pbVar30;
  byte *local_600;
  undefined *local_5e0;
  int local_5c4;
  byte *local_5b0;
  int local_5ac;
  int local_5a8;
  byte *local_5a4;
  byte *local_5a0;
  byte *local_59c;
  uint local_594;
  byte local_552;
  int local_544;
  uint local_540;
  int local_53c;
  uint local_538;
  int local_534;
  int local_530;
  int local_52c;
  undefined *local_528;
  int local_524;
  int local_520;
  byte local_50e;
  byte local_50d;
  byte local_50c;
  byte local_4f9;
  int local_4f4;
  int local_4f0;
  byte *local_4ec;
  ushort *local_4e4;
  uint *local_4e0;
  int local_4dc;
  int local_4d8;
  int local_4d4;
  int local_4d0;
  int local_4cc;
  int local_4c8;
  int local_4c4;
  int local_4c0;
  uint local_4b8;
  int local_4b4;
  int local_4b0;
  uint local_4ac [256];
  byte local_ac [7];
  byte local_a5;
  byte local_a1;
  byte local_9d;
  byte local_99;
  byte local_95;
  byte local_91;
  byte local_8d;
  byte local_89;
  byte local_85;
  byte local_81;
  byte local_7d;
  byte local_79;
  byte local_75;
  byte local_71;
  byte local_6d;
  ushort local_6c [12];
  byte local_54 [16];
  int local_44 [4];
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  byte local_30;
  byte local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  byte local_28;
  byte local_27;
  byte local_26;
  byte local_25;
  byte local_24 [20];
  byte bVar13;
  ushort uVar14;
  ushort uVar22;
  
  if (param_3 == 0x80e0) {
    local_524 = 2;
    local_520 = 3;
  }
  else if (param_3 == 0x80e1) {
    local_524 = 2;
    local_520 = 4;
  }
  else if (param_3 == 0x1907) {
    local_524 = 0;
    local_520 = 3;
  }
  else {
    local_524 = 0;
    local_520 = 4;
  }
  if ((param_1 + 3U < 7) || (param_2 + 3U < 7)) {
    local_4d8 = 4;
    if (3 < param_1) {
      local_4d8 = param_1;
    }
    local_4dc = param_2;
    if (param_2 < 4) {
      local_4dc = 4;
    }
    else if (param_2 < 1) {
      return;
    }
    local_53c = 0;
    local_528 = DAT_0020c680;
    local_5c4 = 0;
    do {
      if (0 < local_4d8) {
        iVar26 = 0;
        local_5e0 = &DAT_0020c683 + local_5c4 * 4;
        do {
          while( true ) {
            iVar15 = (iVar26 + local_5c4) * local_520;
            iVar23 = iVar26 % param_1 + (local_53c % param_2) * param_1;
            iVar9 = local_520 * iVar23;
            (DAT_0020c680)[iVar15] = param_5[iVar9];
            (DAT_0020c681)[iVar15] = param_5[iVar9 + 1];
            (DAT_0020c682)[iVar15] = param_5[iVar9 + 2];
            if (local_520 != 4) break;
            *local_5e0 = param_5[iVar23 * 4 + 3];
            iVar26 = iVar26 + 1;
            local_5e0 = local_5e0 + 4;
            if (local_4d8 == iVar26) goto LAB_00019fc6;
          }
          iVar26 = iVar26 + 1;
          local_5e0 = local_5e0 + 4;
        } while (local_4d8 != iVar26);
      }
LAB_00019fc6:
      local_53c = local_53c + 1;
      local_5c4 = local_5c4 + local_4d8;
    } while (local_4dc != local_53c);
    param_2 = local_4dc;
  }
  else {
    if (param_2 < 1) {
      return;
    }
    local_4d8 = param_1;
    local_528 = param_5;
  }
  local_4b0 = 0;
  do {
    param_6 = (byte *)((uint)(param_6 + 0x1f) & 0xffffffe0);
    if (0 < local_4d8) {
      local_4b4 = 0;
      do {
        if (param_4 == 0xc) {
          if (local_520 != 4) goto LAB_0001a086;
          bVar5 = false;
          local_4c0 = 0;
          do {
            local_600 = local_ac + local_4c0 * 0x10;
            iVar15 = 1;
            iVar26 = ((local_4c0 + local_4b0) * local_4d8 + local_4b4) * 4;
            iVar9 = 4;
            bVar6 = bVar5;
            do {
              *local_600 = local_528[iVar9 + -4 + iVar26 + local_524];
              local_600[1] = local_528[iVar9 + -3 + iVar26];
              local_600[2] = local_528[iVar9 + -2 + (iVar26 - local_524)];
              bVar28 = local_528[iVar9 + -1 + iVar26];
              local_600[3] = bVar28;
              bVar5 = true;
              if (0x7e < bVar28) {
                bVar5 = bVar6;
              }
              iVar15 = iVar15 + 1;
              iVar9 = iVar9 + 4;
              local_600 = local_600 + 4;
              bVar6 = bVar5;
            } while (iVar15 != 5);
            local_4c0 = local_4c0 + 1;
          } while (local_4c0 != 4);
        }
        else if (local_520 == 4) {
          local_4c4 = 0;
          do {
            iVar26 = ((local_4c4 + local_4b0) * local_4d8 + local_4b4) * 4;
            pbVar30 = local_528 + local_524 + iVar26;
            pbVar16 = local_ac + local_4c4 * 0x10;
            puVar19 = local_528 + iVar26;
            puVar27 = local_528 + (iVar26 - local_524);
            local_4f4 = 4;
            do {
              *pbVar16 = *pbVar30;
              pbVar16[1] = puVar19[1];
              pbVar16[2] = puVar27[2];
              pbVar16[3] = puVar19[3];
              pbVar30 = pbVar30 + 4;
              pbVar16 = pbVar16 + 4;
              puVar19 = puVar19 + 4;
              puVar27 = puVar27 + 4;
              local_4f4 = local_4f4 + -1;
            } while (local_4f4 != 0);
            local_4c4 = local_4c4 + 1;
          } while (local_4c4 != 4);
          bVar5 = false;
        }
        else {
LAB_0001a086:
          local_4c8 = 0;
          do {
            pbVar16 = local_ac + local_4c8 * 0x10;
            iVar26 = 0;
            do {
              iVar9 = (iVar26 + (local_4b0 + local_4c8) * local_4d8 + local_4b4) * local_520;
              *pbVar16 = local_528[iVar9 + local_524];
              pbVar16[1] = local_528[iVar9 + 1];
              pbVar16[2] = local_528[(iVar9 - local_524) + 2];
              pbVar16[3] = 0xff;
              iVar26 = iVar26 + 1;
              pbVar16 = pbVar16 + 4;
            } while (iVar26 != 4);
            local_4c8 = local_4c8 + 1;
          } while (local_4c8 != 4);
          bVar5 = false;
        }
        local_4b8 = 1;
        uVar29 = 0;
        do {
          uVar18 = uVar29;
          if ((int)uVar29 < 0) {
            uVar18 = uVar29 + 3;
          }
          uVar10 = uVar29 & 0x80000003;
          if ((int)uVar10 < 0) {
            uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
          }
          iVar26 = uVar10 + ((int)uVar18 >> 2) * 4;
          bVar28 = local_ac[iVar26 * 4];
          bVar12 = local_ac[iVar26 * 4 + 1];
          bVar13 = local_ac[iVar26 * 4 + 2];
          local_4e0 = local_4ac + uVar29 * 0x10 + local_4b8;
          uVar29 = local_4b8;
          do {
            uVar18 = uVar29;
            if ((int)uVar29 < 0) {
              uVar18 = uVar29 + 3;
            }
            uVar10 = uVar29 & 0x80000003;
            if ((int)uVar10 < 0) {
              uVar10 = ((uVar29 & 0x80000003) - 1 | 0xfffffffc) + 1;
            }
            iVar26 = uVar10 + ((int)uVar18 >> 2) * 4;
            sVar21 = (ushort)local_ac[iVar26 * 4] - (ushort)bVar28;
            if (0x7fffffff < (uint)(int)sVar21) {
              sVar21 = -sVar21;
            }
            sVar7 = (ushort)local_ac[iVar26 * 4 + 1] - (ushort)bVar12;
            if (0x7fffffff < (uint)(int)sVar7) {
              sVar7 = -sVar7;
            }
            sVar8 = (ushort)local_ac[iVar26 * 4 + 2] - (ushort)bVar13;
            if (0x7fffffff < (uint)(int)sVar8) {
              sVar8 = -sVar8;
            }
            *local_4e0 = (int)sVar21 + (int)sVar7 + (int)sVar8;
            uVar29 = uVar29 + 1;
            local_4e0 = local_4e0 + 1;
          } while ((int)uVar29 < 0x10);
          uVar18 = local_4b8 + 1;
          uVar29 = local_4b8;
          local_4b8 = uVar18;
        } while (uVar18 != 0x10);
        local_540 = 0;
        do {
          iVar26 = 0;
          do {
            local_54[iVar26] = (byte)iVar26;
            iVar26 = iVar26 + 1;
          } while (iVar26 != 0x10);
          local_594 = 0;
          local_544 = 0x10;
          do {
            bVar28 = local_54[local_594];
            if ((bVar28 == local_594) && (uVar29 = local_594 + 1, (int)uVar29 < 0x10)) {
              puVar17 = local_4ac + local_594 * 0x10 + uVar29;
              pbVar16 = local_54 + local_594 + 1;
              do {
                if (*puVar17 < local_540) {
                  if (uVar29 == *pbVar16) {
                    *pbVar16 = bVar28;
                    local_544 = local_544 + -1;
                  }
                  else if (*puVar17 < local_4ac[(uint)*pbVar16 * 0x10 + uVar29]) {
                    *pbVar16 = bVar28;
                  }
                }
                uVar29 = uVar29 + 1;
                puVar17 = puVar17 + 1;
                pbVar16 = pbVar16 + 1;
              } while (uVar29 != 0x10);
            }
            local_594 = local_594 + 1;
          } while (local_594 != 0x10);
          local_540 = local_540 + 4;
        } while ((int)(~-(uint)!bVar5 + 4) < local_544);
        if (local_544 < 1) {
          local_534 = 0;
          local_530 = 0;
        }
        else {
          iVar26 = 0;
          puVar11 = local_6c;
          do {
            (local_24 + 4)[iVar26] = 0;
            *puVar11 = 0;
            puVar11[1] = 0;
            puVar11[2] = 0;
            iVar26 = iVar26 + 1;
            puVar11 = puVar11 + 3;
          } while (local_544 != iVar26);
          local_4d4 = 0;
          local_538 = 0xffffffff;
          puVar11 = local_6c;
          local_5b0 = local_24 + 4;
          do {
            iVar26 = 0;
            do {
              if ((int)local_538 < (int)(uint)local_54[iVar26]) {
                local_538 = (uint)local_54[iVar26];
                break;
              }
              iVar26 = iVar26 + 1;
            } while (iVar26 != 0x10);
            if ((int)local_538 < 0x10) {
              pbVar16 = local_54 + local_538;
              uVar29 = local_538;
              do {
                if (local_538 == *pbVar16) {
                  *pbVar16 = (byte)local_4d4;
                  uVar18 = uVar29;
                  if ((int)uVar29 < 0) {
                    uVar18 = uVar29 + 3;
                  }
                  uVar10 = uVar29 & 0x80000003;
                  if ((int)uVar10 < 0) {
                    uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
                  }
                  iVar26 = uVar10 + ((int)uVar18 >> 2) * 4;
                  *puVar11 = *puVar11 + (ushort)local_ac[iVar26 * 4];
                  puVar11[1] = puVar11[1] + (ushort)local_ac[iVar26 * 4 + 1];
                  puVar11[2] = puVar11[2] + (ushort)local_ac[iVar26 * 4 + 2];
                  *local_5b0 = *local_5b0 + 1;
                }
                uVar29 = uVar29 + 1;
                pbVar16 = pbVar16 + 1;
              } while (uVar29 != 0x10);
            }
            uVar29 = (uint)*local_5b0;
            *puVar11 = (ushort)((ulonglong)*puVar11 / (ulonglong)(longlong)(int)uVar29);
            puVar11[1] = (ushort)((ulonglong)puVar11[1] / (ulonglong)(longlong)(int)uVar29);
            puVar11[2] = (ushort)((ulonglong)puVar11[2] / (ulonglong)(longlong)(int)uVar29);
            local_4d4 = local_4d4 + 1;
            local_5b0 = local_5b0 + 1;
            puVar11 = puVar11 + 3;
          } while (local_544 != local_4d4);
          local_4d0 = 0;
          local_52c = 0;
          local_530 = 0;
          local_534 = 0;
          local_4e4 = local_6c;
          do {
            iVar26 = local_4d0 + 1;
            if (iVar26 < local_544) {
              puVar11 = local_6c + iVar26 * 3;
              iVar9 = iVar26;
              do {
                sVar21 = *local_4e4 - *puVar11;
                if (0x7fffffff < (uint)(int)sVar21) {
                  sVar21 = -sVar21;
                }
                sVar7 = local_4e4[1] - puVar11[1];
                if (0x7fffffff < (uint)(int)sVar7) {
                  sVar7 = -sVar7;
                }
                sVar8 = local_4e4[2] - puVar11[2];
                if (0x7fffffff < (uint)(int)sVar8) {
                  sVar8 = -sVar8;
                }
                iVar15 = (int)sVar21 + (int)sVar7 + (int)sVar8;
                if (local_52c < iVar15) {
                  local_530 = local_4d0;
                  local_534 = iVar9;
                  local_52c = iVar15;
                }
                iVar9 = iVar9 + 1;
                puVar11 = puVar11 + 3;
              } while (iVar9 != local_544);
            }
            local_4e4 = local_4e4 + 3;
            local_4d0 = iVar26;
          } while (local_544 != iVar26);
        }
        uVar14 = local_6c[local_530 * 3];
        local_50c = (byte)uVar14 & 0xf8;
        uVar22 = local_6c[local_530 * 3 + 1];
        local_50d = (byte)uVar22 & 0xfc;
        uVar1 = local_6c[local_530 * 3 + 2];
        local_50e = (byte)uVar1 & 0xf8;
        uVar2 = local_6c[local_534 * 3];
        uVar29 = uVar2 & 0xfffffff8;
        uVar3 = local_6c[local_534 * 3 + 1];
        local_552 = (byte)uVar3;
        uVar4 = local_6c[local_534 * 3 + 2];
        local_4f9 = (byte)uVar4 & 0xf8;
        if (local_50c != (byte)uVar29) goto LAB_0001a438;
        if (uVar14 == uVar2) {
LAB_0001ac58:
          uVar29 = (uint)local_50c;
        }
        else if (uVar2 < uVar14) {
          if (0xf7 < local_50c) goto LAB_0001ac58;
          uVar29 = (uint)local_50c;
          local_50c = local_50c + 8;
        }
        else {
          if (0xf7 < local_50c) goto LAB_0001ac58;
          uVar29 = local_50c + 8;
        }
LAB_0001a438:
        bVar28 = local_552 & 0xfc;
        if ((local_50d == (local_552 & 0xfc)) && (bVar28 = local_50d, uVar22 != uVar3)) {
          if (uVar3 < uVar22) {
            if (local_50d < 0xfc) {
              local_50d = local_50d + 4;
            }
          }
          else if (local_50d < 0xfc) {
            bVar28 = local_50d + 4;
          }
        }
        if ((local_50e == local_4f9) && (local_4f9 = local_50e, uVar1 != uVar4)) {
          if (uVar4 < uVar1) {
            if (local_50e < 0xf8) {
              local_50e = local_50e + 8;
            }
          }
          else if (local_50e < 0xf8) {
            local_4f9 = local_50e + 8;
          }
        }
        uVar18 = (uint)local_50c << 8 | (uint)local_50d << 3;
        uVar10 = uVar18 | local_50e >> 3;
        uVar24 = uVar29 << 8 | (uint)bVar28 << 3;
        uVar25 = uVar24 | local_4f9 >> 3;
        uVar14 = (ushort)uVar10;
        bVar12 = (byte)uVar10;
        local_26 = (byte)uVar25;
        uVar22 = (ushort)uVar25;
        bVar13 = (byte)(uVar18 >> 8);
        local_25 = (byte)(uVar24 >> 8);
        bVar20 = (byte)uVar29;
        if (bVar5) {
          if (uVar22 < uVar14) {
            local_28 = local_26;
            local_27 = local_25;
            local_26 = bVar12;
            local_25 = bVar13;
            local_34 = bVar20;
            local_33 = bVar28;
            local_32 = local_4f9;
            local_31 = local_50c;
            local_30 = local_50d;
            local_2f = local_50e;
          }
          else {
            local_28 = bVar12;
            local_27 = bVar13;
            local_31 = bVar20;
            local_30 = bVar28;
            local_2f = local_4f9;
            local_34 = local_50c;
            local_33 = local_50d;
            local_32 = local_50e;
          }
          local_2e = (char)((int)((uint)local_34 + (uint)local_31) >> 1);
          local_2d = (char)((int)((uint)local_33 + (uint)local_30) >> 1);
          local_2c = (char)((int)((uint)local_32 + (uint)local_2f) >> 1);
        }
        else {
          if (uVar22 < uVar14) {
            local_28 = bVar12;
            local_27 = bVar13;
            local_34 = local_50c;
            local_33 = local_50d;
            local_32 = local_50e;
            local_31 = bVar20;
            local_30 = bVar28;
            local_2f = local_4f9;
          }
          else {
            local_28 = local_26;
            local_27 = local_25;
            local_26 = bVar12;
            local_25 = bVar13;
            local_31 = local_50c;
            local_30 = local_50d;
            local_2f = local_50e;
            local_34 = bVar20;
            local_33 = bVar28;
            local_32 = local_4f9;
          }
          local_2e = (char)((ulonglong)
                            ((longlong)(int)((uint)local_31 + (uint)local_34 * 2) * 0x55555556) >>
                           0x20);
          local_2d = (char)((ulonglong)
                            ((longlong)(int)((uint)local_30 + (uint)local_33 * 2) * 0x55555556) >>
                           0x20);
          local_2c = (char)((ulonglong)
                            ((longlong)(int)((uint)local_2f + (uint)local_32 * 2) * 0x55555556) >>
                           0x20);
          local_2b = (char)((ulonglong)
                            ((longlong)(int)((uint)local_34 + (uint)local_31 * 2) * 0x55555556) >>
                           0x20);
          local_2a = (char)((ulonglong)
                            ((longlong)(int)((uint)local_33 + (uint)local_30 * 2) * 0x55555556) >>
                           0x20);
          local_29 = (char)((ulonglong)
                            ((longlong)(int)((uint)local_32 + (uint)local_2f * 2) * 0x55555556) >>
                           0x20);
        }
        local_24[0] = 0;
        local_24[1] = 0;
        local_24[2] = 0;
        local_24[3] = 0;
        uVar29 = ~-(uint)!bVar5 + 4;
        local_4cc = 0;
        local_59c = local_ac + 2;
        local_5a0 = local_ac + 1;
        local_5a4 = local_ac + 3;
        local_5a8 = 0;
        local_5ac = 3;
        do {
          local_4ec = local_ac + local_5ac;
          local_4f0 = 0;
          do {
            if ((bVar5) && (*local_4ec < 0x7f)) {
              uVar18 = 3;
            }
            else {
              if (0 < (int)uVar29) {
                bVar28 = local_4ec[(int)(local_ac + (local_5a8 - (int)local_5a4))];
                bVar12 = local_4ec[(int)local_5a0 - (int)local_5a4];
                bVar13 = local_4ec[(int)local_59c - (int)local_5a4];
                local_5e0 = (undefined *)0x0;
                pbVar16 = &local_34;
                do {
                  local_44[(int)local_5e0] =
                       ((uint)bVar28 - (uint)*pbVar16) * ((uint)bVar28 - (uint)*pbVar16) +
                       ((uint)bVar12 - (uint)pbVar16[1]) * ((uint)bVar12 - (uint)pbVar16[1]) * 4 +
                       ((uint)bVar13 - (uint)pbVar16[2]) * ((uint)bVar13 - (uint)pbVar16[2]);
                  local_5e0 = (undefined *)((int)local_5e0 + 1);
                  pbVar16 = pbVar16 + 3;
                } while (local_5e0 != (undefined *)uVar29);
              }
              if ((int)uVar29 < 2) {
                uVar18 = 0;
              }
              else {
                local_5e0 = (undefined *)0x0;
                uVar18 = 1;
                iVar9 = 8;
                iVar26 = local_44[0];
                do {
                  if (*(int *)(local_54 + iVar9 + 0xc) < iVar26) {
                    iVar26 = *(int *)(local_54 + iVar9 + 0xc);
                    local_5e0 = (undefined *)uVar18;
                  }
                  uVar18 = uVar18 + 1;
                  iVar9 = iVar9 + 4;
                } while (uVar29 != uVar18);
                uVar18 = (uint)local_5e0 & 3;
              }
            }
            local_24[local_4cc] = local_24[local_4cc] | (byte)(uVar18 << ((byte)local_4f0 & 0x1f));
            local_4f0 = local_4f0 + 2;
            local_4ec = local_4ec + 4;
          } while (local_4f0 != 8);
          local_4cc = local_4cc + 1;
          local_5ac = local_5ac + 0x10;
          local_5a8 = local_5a8 + 0x10;
          local_5a4 = local_5a4 + 0x10;
          local_5a0 = local_5a0 + 0x10;
          local_59c = local_59c + 0x10;
        } while (local_4cc != 4);
        if (param_4 == 0xd) {
          if (local_520 == 4) {
            *param_6 = local_a5 & 0xf0 | local_ac[3] >> 4;
            param_6[1] = local_9d & 0xf0 | local_a1 >> 4;
            param_6[2] = local_95 & 0xf0 | local_99 >> 4;
            param_6[3] = local_8d & 0xf0 | local_91 >> 4;
            param_6[4] = local_85 & 0xf0 | local_89 >> 4;
            param_6[5] = local_7d & 0xf0 | local_81 >> 4;
            param_6[6] = local_75 & 0xf0 | local_79 >> 4;
            param_6[7] = local_6d & 0xf0 | local_71 >> 4;
            param_6 = param_6 + 8;
          }
          else {
            *param_6 = 0xff;
            param_6[1] = 0xff;
            param_6[2] = 0xff;
            param_6[3] = 0xff;
            param_6[4] = 0xff;
            param_6[5] = 0xff;
            param_6[6] = 0xff;
            param_6[7] = 0xff;
            param_6 = param_6 + 8;
          }
        }
        else if (param_4 == 0xe) {
          param_6 = (byte *)((int (*)())FUN_0001991c)(local_ac,param_6);
        }
        *param_6 = local_28;
        param_6[1] = local_27;
        param_6[2] = local_26;
        param_6[3] = local_25;
        param_6[4] = local_24[0];
        param_6[5] = local_24[1];
        param_6[6] = local_24[2];
        param_6[7] = local_24[3];
        param_6 = param_6 + 8;
        local_4b4 = local_4b4 + 4;
      } while (local_4b4 < local_4d8);
    }
    local_4b0 = local_4b0 + 4;
    if (param_2 <= local_4b0) {
      return;
    }
  } while( true );
}

/* FUN_0001b0a2 @ 0x1b0a2 (1601 bytes) */
int FUN_0001b0a2(param_1, param_2, param_3, param_4, param_5, param_6)
  uint param_1;
  uint param_2;
  uint param_3;
  int param_4;
  int param_5;
  int param_6;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  uint local_70;
  uint local_68;
  uint local_64;
  uint local_5c;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  
  if (param_4 == 0xd) {
    if (param_3 != 0) {
      uVar4 = param_1;
      if ((int)param_1 < 0) {
        uVar4 = param_1 + 3;
      }
      local_24 = 0;
      do {
        if (param_2 != 0) {
          local_2c = 0;
          do {
            if (param_1 != 0) {
              uVar6 = local_2c;
              if ((int)local_2c < 0) {
                uVar6 = local_2c + 3;
              }
              local_64 = local_2c & 0x80000003;
              if ((int)local_64 < 0) {
                local_64 = (local_64 - 1 | 0xfffffffc) + 1;
              }
              local_34 = 0;
              do {
                while( true ) {
                  iVar5 = 1;
                  if ((int)uVar4 >> 2 != 0) {
                    iVar5 = (int)uVar4 >> 2;
                  }
                  local_5c = local_34 & 0x80000003;
                  if ((int)local_5c < 0) {
                    local_5c = (local_5c - 1 | 0xfffffffc) + 1;
                  }
                  uVar7 = local_34;
                  if ((int)local_34 < 0) {
                    uVar7 = local_34 + 3;
                  }
                  ((int (*)())FUN_00019c42)(param_6);
                  bVar3 = *(byte *)(param_5 + (local_64 +
                                              (((int)uVar7 >> 2) + iVar5 * ((int)uVar6 >> 2)) * 8) *
                                              2 + ((int)local_5c >> 1));
                  if ((local_5c & 1) != 0) break;
                  *(byte *)(param_6 + 3) = bVar3 << 4;
                  param_6 = param_6 + 4;
                  local_34 = local_34 + 1;
                  if (param_1 <= local_34) goto LAB_0001b228;
                }
                *(byte *)(param_6 + 3) = bVar3 & 0xf0;
                param_6 = param_6 + 4;
                local_34 = local_34 + 1;
              } while (local_34 < param_1);
            }
LAB_0001b228:
            local_2c = local_2c + 1;
          } while (local_2c < param_2);
        }
        local_24 = local_24 + 1;
        if (param_3 <= local_24) {
          return;
        }
      } while( true );
    }
  }
  else if (param_4 == 0xe) {
    if (param_3 != 0) {
      local_20 = 0;
      do {
        if (param_2 != 0) {
          local_28 = 0;
          do {
            if (param_1 != 0) {
              uVar4 = local_28;
              if ((int)local_28 < 0) {
                uVar4 = local_28 + 3;
              }
              local_70 = local_28 & 0x80000003;
              if ((int)local_70 < 0) {
                local_70 = (local_70 - 1 | 0xfffffffc) + 1;
              }
              local_30 = 0;
              do {
                iVar5 = 1;
                if ((int)param_1 / 2 != 0) {
                  iVar5 = (int)param_1 / 2;
                }
                local_68 = local_30 & 0x80000003;
                if ((int)local_68 < 0) {
                  local_68 = (local_68 - 1 | 0xfffffffc) + 1;
                }
                uVar6 = local_30;
                if ((int)local_30 < 0) {
                  uVar6 = local_30 + 3;
                }
                pbVar8 = (byte *)(param_5 + (((int)uVar6 >> 2) + iVar5 * ((int)uVar4 >> 2)) * 0x10);
                ((int (*)())FUN_00019c42)(param_6);
                bVar3 = *pbVar8;
                bVar1 = pbVar8[1];
                uVar6 = local_68 + local_70 * 4 & 0x80000007;
                if ((int)uVar6 < 0) {
                  uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
                }
                if ((int)local_70 < 2) {
                  uVar7 = (uint)pbVar8[4] << 0x10 | (uint)pbVar8[3] << 8 | (uint)pbVar8[2];
                }
                else {
                  uVar7 = (uint)pbVar8[7] << 0x10 | (uint)pbVar8[6] << 8 | (uint)pbVar8[5];
                }
                bVar2 = (byte)(uVar7 >> ((char)uVar6 * '\x03' & 0x1fU)) & 7;
                if (bVar3 <= bVar1) {
                  switch(bVar2) {
                  case 0:
                    goto LAB_0001b4dc;
                  case 1:
                    goto switchD_0001b3b6_caseD_1;
                  case 2:
                    uVar6 = (uint)bVar1 + (uint)bVar3 * 4;
                    break;
                  case 3:
                    uVar6 = (uint)bVar3 * 3 + (uint)bVar1 * 2;
                    break;
                  case 4:
                    uVar6 = (uint)bVar1 * 3 + (uint)bVar3 * 2;
                    break;
                  case 5:
                    uVar6 = (uint)bVar3 + (uint)bVar1 * 4;
                    break;
                  default:
                    goto switchD_0001b3b6_default;
                  case 7:
                    bVar3 = 0xff;
                    goto LAB_0001b4dc;
                  }
                  goto LAB_0001b532;
                }
                switch(bVar2) {
                case 0:
                  goto LAB_0001b4dc;
                case 1:
switchD_0001b3b6_caseD_1:
                  bVar3 = bVar1;
                  goto LAB_0001b4dc;
                case 2:
                  uVar6 = (uint)bVar1 + (uint)bVar3 * 6;
                  break;
                case 3:
                  uVar6 = (uint)bVar3 * 5 + (uint)bVar1 * 2;
                  break;
                case 4:
                  uVar6 = (uint)bVar1 * 3 + (uint)bVar3 * 4;
                  break;
                case 5:
                  uVar6 = (uint)bVar3 * 3 + (uint)bVar1 * 4;
                  break;
                case 6:
                  uVar6 = (uint)bVar1 * 5 + (uint)bVar3 * 2;
                  break;
                case 7:
                  uVar6 = (uint)bVar3 + (uint)bVar1 * 6;
                  break;
                default:
switchD_0001b3b6_default:
                  bVar3 = 0;
                  goto LAB_0001b4dc;
                }
LAB_0001b532:
                bVar3 = (byte)(uVar6 / 7);
LAB_0001b4dc:
                *(byte *)(param_6 + 3) = bVar3;
                param_6 = param_6 + 4;
                local_30 = local_30 + 1;
              } while (local_30 < param_1);
            }
            local_28 = local_28 + 1;
          } while (local_28 < param_2);
        }
        local_20 = local_20 + 1;
        if (param_3 <= local_20) {
          return;
        }
      } while( true );
    }
  }
  else if ((param_4 == 0xc) && (param_3 != 0)) {
    local_48 = 0;
    do {
      if (param_2 != 0) {
        local_4c = 0;
        do {
          if (param_1 != 0) {
            local_50 = 0;
            do {
              ((int (*)())FUN_00019c42)(param_6);
              param_6 = param_6 + 4;
              local_50 = local_50 + 1;
            } while (local_50 < param_1);
          }
          local_4c = local_4c + 1;
        } while (local_4c < param_2);
      }
      local_48 = local_48 + 1;
    } while (local_48 < param_3);
    return;
  }
  return;
}

/* FUN_0001b725 @ 0x1b725 (153 bytes) */
int FUN_0001b725(param_1)
  uint param_1;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 >> 0x1f;
  uVar2 = param_1 >> 0x17 & 0xff;
  iVar1 = uVar2 - 0x7f;
  if (0x10 < iVar1) {
    return uVar3 << 0xf | 0x7fff;
  }
  if (iVar1 < -0xe) {
    if (-0x26 < iVar1) {
      return uVar3 << 0xf | ((param_1 & 0x7fffff | 0x800000) >> (0xf2U - (char)iVar1 & 0x1f)) >> 0xd
      ;
    }
    return uVar3 << 0xf;
  }
  return uVar3 << 0xf | (uVar2 - 0x70) * 0x400 | (param_1 & 0x7fffff) >> 0xd;
}

/* FUN_0001b7c0 @ 0x1b7c0 (782 bytes) */
int FUN_0001b7c0(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined1 *puVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint local_2c;
  undefined1 local_1d;
  int local_18;
  
  iVar2 = *param_1;
  if (param_2 == '\0') {
    local_2c = *(uint *)(iVar2 + 0x314);
  }
  else {
    local_2c = 0;
  }
  iVar3 = *(int *)(iVar2 + 0x318);
  if (((*(uint *)(param_1[1] + 0x84) & 1) == 0) || (param_2 != '\0')) {
    bVar6 = false;
    if (param_2 != '\0') {
      local_1d = 1;
      goto LAB_0001b825;
    }
  }
  else {
    bVar6 = true;
  }
  if ((local_2c == 0) || (iVar3 == 0)) {
    local_1d = 0;
  }
  else {
    local_1d = 1;
  }
  if ((local_2c & 3) != 0) {
    local_1d = 0;
  }
LAB_0001b825:
  uVar7 = *(uint *)(iVar2 + 0x300) & 0xffff0000;
  if (bVar6) {
    uVar13 = 0xff7f0000;
  }
  else {
    uVar13 = *(uint *)(param_1[1] + 0x84) & 0xff7f0000;
  }
  iVar12 = 0;
  local_18 = 0;
  do {
    while( true ) {
      while (uVar13 == 0) {
        uVar7 = *(uint *)(iVar2 + 0x304);
        if (bVar6) {
          uVar13 = 0xffff;
        }
        else {
          uVar13 = (uint)*(ushort *)(param_1[1] + 0x88);
        }
        if (1 < local_18 + 1) {
          iVar2 = param_1[1];
          *(uint *)(iVar2 + 0x84) = *(uint *)(iVar2 + 0x84) & 0xfffb;
          *(undefined4 *)(iVar2 + 0x88) = 0;
          return local_1d;
        }
        local_18 = local_18 + 1;
        iVar12 = 0x10;
      }
      uVar4 = (DAT_001ec240)[iVar12];
      if ((uVar13 & uVar4) != 0) break;
LAB_0001ba67:
      iVar12 = iVar12 + 1;
    }
    puVar10 = (undefined1 *)((int)param_1 + iVar12 + 8);
    *puVar10 = 1;
    uVar13 = uVar13 & ~uVar4;
    if ((uVar7 & uVar4) == 0) goto LAB_0001ba67;
    iVar8 = iVar12 * 0x18;
    uVar4 = *(uint *)(iVar8 + iVar2);
    uVar11 = (uint)*(short *)(iVar8 + 10 + iVar2);
    uVar5 = *(uint *)(iVar8 + 4 + iVar2);
    uVar9 = (*(ushort *)(iVar8 + 8 + iVar2) & 0x7fff) - 0x1400;
    iVar8 = uVar11 - 1;
    if (((param_2 != '\0') ||
        (((local_2c <= uVar4 && (uVar4 < iVar3 + local_2c)) && ((uVar4 & 3) == 0)))) &&
       ((((uVar11 < 5 && (uVar5 < 0x200)) && ((uVar5 & 3) == 0)) &&
        ((uVar9 < 0xb && (*(int *)(&DAT_001ec400 + uVar9 * 4) == 1)))))) {
      if (uVar5 != 0) {
        uVar11 = uVar5 >> 2;
      }
      iVar1 = iVar8 + uVar9 * 4;
      param_1[iVar12 + 10] =
           param_1[iVar12 + 10] & 0xffff8080U | (uVar11 & 0x7f) << 8 |
           *(uint *)(&DAT_001ec340 + iVar1 * 4) & 0x7f;
      param_1[iVar12 + 0x2a] = uVar4 - local_2c;
      param_1[iVar12 + 0x4a] =
           (int)*(short *)(iVar2 + 8 + iVar12 * 0x18) & 0x8000U |
           param_1[iVar12 + 0x4a] & 0xffff3ff0U | *(uint *)(&DAT_001c5f00 + iVar1 * 4) |
           *(uint *)(&DAT_001ec300 + uVar9 * 4);
      param_1[iVar12 + 0x6a] =
           param_1[iVar12 + 0x6a] & 0xfffff000U | *(uint *)(&DAT_001c5ee0 + iVar8 * 4);
      goto LAB_0001ba67;
    }
    *puVar10 = 0;
  } while( true );
}

/* FUN_0001bace @ 0x1bace (241 bytes) */
int FUN_0001bace(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  uint *param_3;
  uint *param_4;
  uint *param_5;
  int *param_6;
{
  uint uVar1;
  uint uVar2;
  undefined4 local_10;
  
  if (*(uint *)(param_1 + 0x29d8) < 0x7ffd) {
    local_10 = *(uint *)(param_1 + 0x29d8) & 0xffffffe0;
    *param_3 = 0;
    *param_5 = 0;
    *param_4 = 0;
    *param_6 = 0;
    if (param_2 < local_10) goto LAB_0001bb80;
  }
  else {
    local_10 = 0x7fe0;
    *param_3 = 0;
    *param_5 = 0;
    *param_4 = 0;
    *param_6 = 0;
    if (param_2 < 0x7fe0) {
LAB_0001bb80:
      *param_3 = param_2;
      if ((param_2 & 0x1f) == 0) {
        *param_5 = 1;
      }
      else {
        *param_3 = param_2 + 0x1f & 0xffffffe0;
        *param_5 = 1;
      }
      uVar2 = 0;
      *param_4 = *param_3 >> 2;
      uVar1 = *param_5;
      goto joined_r0x0001bba2;
    }
  }
  *param_3 = local_10;
  *param_5 = param_2 / local_10;
  uVar2 = param_2 % *param_3 + 3 & 0xfffffffc;
  *param_4 = *param_3 >> 2;
  uVar1 = *param_5;
joined_r0x0001bba2:
  if (uVar1 < 0x2000) {
    *param_6 = 2 - (uint)(uVar2 == 0);
    return 1;
  }
  return 0;
}

/* FUN_0001bbbf @ 0x1bbbf (1059 bytes) */
int FUN_0001bbbf(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int *piVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_18;
  int local_14;
  uint local_10;
  
  iVar1 = *param_2;
  iVar5 = param_2[1];
  if (*(int *)(iVar5 + 0x88) != 0 || (*(uint *)(iVar5 + 0x84) & 0xfffffff5) != 0) {
    cVar3 = ((int (*)())FUN_0001b7c0)();
    if (cVar3 == '\0') {
      return 0;
    }
    iVar5 = param_2[1];
  }
  uVar6 = *(uint *)(iVar5 + 0x84);
  if (*(int *)(iVar5 + 0x88) == 0 && uVar6 == 0) {
    return 1;
  }
  if ((param_2[0x8a] != 0) && (((uVar6 ^ 1) & 1) != 0)) {
    if (*(short *)(iVar1 + 0x312) == -0x7a42) {
      if (param_2[0x8c] == 7) {
        if ((uVar6 & 2) != 0) {
          *(undefined1 *)(param_2[0x8a] + 0x14) = 1;
          *(ushort *)(param_2[0x8a] + 0x1c) = *(ushort *)(param_2[0x8a] + 0x1c) | 1;
          *(ushort *)(param_2[0x8a] + 0x28) = *(ushort *)(param_2[0x8a] + 0x28) & 0xfffe;
          iVar5 = param_2[1];
        }
        goto LAB_0001bd2f;
      }
    }
    else if (param_2[0x8c] == 6) {
LAB_0001bd2f:
      *(undefined4 *)(iVar5 + 0x84) = 0;
      *(undefined4 *)(iVar5 + 0x88) = 0;
      return 1;
    }
  }
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  cVar3 = ((int (*)())FUN_0001bace)(&local_18,&local_14,&local_10);
  if (cVar3 != '\0') {
    if (local_10 < 2) {
      uVar7 = 0;
      uVar6 = *(uint *)(iVar1 + 0x318);
    }
    else {
      uVar6 = *(uint *)(iVar1 + 0x318);
      uVar7 = uVar6 % 0 + 3 & 0xfffffffc;
    }
    if ((*(short *)(iVar1 + 0x312) == -0x7a42) && (local_10 < 0x4f)) {
      cVar3 = FUN_0000a870(param_1,param_2,local_10 * 0x48 + 0x30,uVar7,
                           *(undefined4 *)(iVar1 + 0x314),uVar6);
      if (cVar3 != '\0') goto LAB_0001bccd;
      uVar6 = *(uint *)(iVar1 + 0x318);
    }
    cVar3 = FUN_0000a75f(param_1,param_2,*(undefined4 *)(iVar1 + 0x314),
                         *(undefined4 *)(iVar1 + 0x314),uVar6);
    if (cVar3 != '\0') {
LAB_0001bccd:
      if (param_2[0x8c] == 7) {
        uVar6 = (*(uint *)(iVar1 + 0x314) & 0xfff) - (*(uint *)(iVar1 + 0x314) & 0xfe0) >> 2;
        *(undefined1 *)(param_2[0x8a] + 0x15) = 0;
        *(undefined1 *)(param_2[0x8a] + 0x17) = 0;
        *(undefined1 *)(param_2[0x8a] + 0x34) = 1;
        *(undefined1 *)(param_2[0x8a] + 0x35) = 1;
        piVar2 = (int *)param_2[0x8b];
        *(byte *)(piVar2 + 8) = *(byte *)(piVar2 + 8) & 0xf5 | 5;
        piVar2[0x280] = 0x1393;
        piVar2[0x281] = 10;
        piVar2[0x282] = 0x5c8;
        piVar2[0x283] = 0x20000;
        piVar2[0x284] = 0x575;
        piVar2[0x285] = 0;
        piVar2[0x286] = 0x574;
        piVar2[0x287] = 0;
        *(short *)(piVar2 + 0x10) = (short)((int)(piVar2 + 0x288) - (int)(piVar2 + 0x280) >> 2);
        piVar2[0x11] = *(uint *)(iVar1 + 0x314) & 0xfe0;
        piVar2[0x12] = 0;
        piVar2[0x13] = 0;
        piVar2[0x14] = 0;
        *(short *)((int)piVar2 + 0x42) = (short)local_10;
        piVar2[0x15] = 0;
        piVar2[0x17] = 0;
        puVar4 = (undefined4 *)
                 FUN_0002e556(piVar2 + 0x288,6,0,0,0,uVar6,local_14 << 0x10 | local_18);
        if (uVar7 != 0) {
          puVar4 = (undefined4 *)FUN_0002e556(puVar4,6,0,0,0,uVar6,uVar7 >> 2 | 0x10000);
        }
        *(ushort *)(param_2[0x8a] + 0x1c) = *(ushort *)(param_2[0x8a] + 0x1c) | 1;
        *(ushort *)(param_2[0x8a] + 0x28) = *(ushort *)(param_2[0x8a] + 0x28) & 0xfffe;
        *puVar4 = 0xd0b;
        puVar4[1] = 5;
        puVar4[2] = 0x5c8;
        puVar4[3] = 0x10000;
        *piVar2 = (int)puVar4 + (0x10 - (int)(piVar2 + 0x280)) >> 2;
      }
      *(undefined1 *)(param_2[0x8a] + 0x14) = 1;
      iVar1 = param_2[1];
      *(undefined4 *)(iVar1 + 0x84) = 0;
      *(undefined4 *)(iVar1 + 0x88) = 0;
      return 1;
    }
  }
  return 0;
}

/* FUN_0001bfe2 @ 0x1bfe2 (100 bytes) */
int FUN_0001bfe2(param_1)
  int param_1;
{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = (**(code **)(param_1 + 0x2998))(param_1 + 0x240,1);
  *(int *)(param_1 + 0x298c) = iVar3;
  puVar1 = *(uint **)(param_1 + 0x1d8);
  *puVar1 = *puVar1 | iVar3 - (int)puVar1 >> 2;
  puVar2 = *(undefined4 **)(param_1 + 0x298c);
  *(undefined4 **)(param_1 + 0x1d8) = puVar2;
  *puVar2 = 0x3a000000;
  *(undefined4 **)(param_1 + 0x298c) = puVar2 + 1;
  (**(code **)(param_1 + 0x299c))(param_1 + 0x240,puVar2 + 1);
  return;
}

/* _gldPageoffBuffer @ 0x1c046 (501 bytes) */
int _gldPageoffBuffer(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  undefined4 local_14;
  undefined4 local_10;
  
  if (*(int *)(param_2 + 8) != 0) {
    _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
    puVar1 = (undefined4 *)**(int **)(param_2 + 8);
    if ((puVar1 == (undefined4 *)0x0) || (*(char *)((int)puVar1 + 0x16) != '\a')) {
      if (*(char *)((int)puVar1 + 0x16) == '\x06') {
        if ((0x1ffff < (int)puVar1[4]) &&
           (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc))) {
          ((int (*)())FUN_00017c77)(param_1,0x1000000);
        }
        if (((byte)*(undefined2 *)(puVar1 + 10) & ~(byte)*(undefined2 *)(puVar1 + 7) & 1) != 0) {
          cVar3 = ((int (*)())FUN_00017c5b)(param_1,puVar1[3]);
          if (cVar3 == '\0') {
            _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,puVar1 + 3,1,0,0);
          }
          *(ushort *)(puVar1 + 7) = *(ushort *)(puVar1 + 7) | *(ushort *)(puVar1 + 10);
        }
      }
    }
    else {
      if ((0x1ffff < (int)puVar1[4]) &&
         (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc))) {
        ((int (*)())FUN_00017c77)(param_1,0x1000000);
      }
      if (((byte)*(undefined2 *)(puVar1 + 10) & ~(byte)*(undefined2 *)(puVar1 + 7) & 1) != 0) {
        local_14 = *puVar1;
        local_10 = 0;
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xd,&local_14,2,0,0);
      }
      iVar2 = *(int *)(*(int *)(param_2 + 8) + 4);
      if ((*(byte *)(iVar2 + 0x20) & 8) != 0) {
        cVar3 = ((int (*)())FUN_00017c5b)(param_1,*(undefined4 *)(iVar2 + 0x1c));
        if (cVar3 == '\0') {
          _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar2 + 0x1c,1,0,0);
          *(byte *)(iVar2 + 0x20) = *(byte *)(iVar2 + 0x20) & 0xf7;
        }
        else {
          *(byte *)(iVar2 + 0x20) = *(byte *)(iVar2 + 0x20) & 0xf7;
        }
      }
    }
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
  }
  return;
}

/* FUN_0001c23b @ 0x1c23b (7 bytes) */
int FUN_0001c23b()
{
  return 0;
}

/* FUN_0001c242 @ 0x1c242 (1155 bytes) */
int FUN_0001c242(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint *puVar1;
  int *piVar2;
  undefined4 uVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint local_18;
  int local_14;
  uint local_10;
  
  if (param_3 == '\0') {
    *(undefined1 *)(param_2 + 3) = 1;
  }
  puVar1 = (uint *)*param_2;
  if (*puVar1 == 0) {
    return 0;
  }
  if (((int *)param_2[2] != (int *)0x0) && (iVar7 = *(int *)param_2[2], iVar7 != 0)) {
    puVar8 = (uint *)param_2[1];
    uVar9 = *puVar8;
    if (((uVar9 ^ 1) & 1) != 0) {
      if ((short)puVar1[3] == -0x771c) {
        if (param_2[4] == 7) {
          if ((uVar9 & 2) != 0) {
            *(undefined1 *)(iVar7 + 0x14) = 1;
            *(ushort *)(*(int *)param_2[2] + 0x1c) = *(ushort *)(*(int *)param_2[2] + 0x1c) | 1;
            *(ushort *)(*(int *)param_2[2] + 0x28) = *(ushort *)(*(int *)param_2[2] + 0x28) & 0xfffe
            ;
            if ((*(byte *)(param_1 + 0x24) & 2) == 0) {
              puVar8 = (uint *)param_2[1];
            }
            else {
              FUN_00009943(param_1,*puVar1,puVar1[2]);
              puVar8 = (uint *)param_2[1];
            }
          }
          goto LAB_0001c3bc;
        }
      }
      else if (param_2[4] == 6) {
        if (((uVar9 & 2) != 0) && ((*(byte *)(param_1 + 0x24) & 2) != 0)) {
          FUN_00009943(param_1,*puVar1,puVar1[2]);
          puVar8 = (uint *)param_2[1];
        }
        goto LAB_0001c3bc;
      }
    }
  }
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  cVar4 = ((int (*)())FUN_0001bace)(&local_18,&local_14,&local_10);
  if (cVar4 == '\0') {
    return 0;
  }
  if (local_10 < 2) {
    uVar10 = 0;
    uVar9 = puVar1[1];
  }
  else {
    uVar9 = puVar1[1];
    uVar10 = uVar9 % 0 + 3 & 0xfffffffc;
  }
  if (((short)puVar1[3] == -0x771c) && (local_10 < 0x4f)) {
    if (param_3 == '\0') {
      iVar7 = 0;
    }
    else {
      iVar7 = 0x49;
    }
    cVar4 = FUN_00005628(param_1,param_2,iVar7 + local_10 * 0x48 + 0x30,uVar10,*puVar1,uVar9);
    if (cVar4 == '\0') {
      uVar9 = puVar1[1];
      goto LAB_0001c369;
    }
  }
  else {
LAB_0001c369:
    cVar4 = FUN_00005509(param_1,param_2,*puVar1,*puVar1,uVar9);
    if (cVar4 == '\0') {
      return 0;
    }
  }
  if (param_2[4] == 7) {
    uVar9 = (*puVar1 & 0xfff) - (*puVar1 & 0xfe0) >> 2;
    *(undefined1 *)(*(int *)param_2[2] + 0x15) = 0;
    *(undefined1 *)(*(int *)param_2[2] + 0x17) = 0;
    *(undefined1 *)(*(int *)param_2[2] + 0x34) = 1;
    *(undefined1 *)(*(int *)param_2[2] + 0x35) = 1;
    piVar2 = *(int **)(param_2[2] + 4);
    *(byte *)(piVar2 + 8) = *(byte *)(piVar2 + 8) & 0xfd | 5;
    piVar2[0x280] = 0x1393;
    piVar2[0x281] = 10;
    piVar2[0x282] = 0x5c8;
    piVar2[0x283] = 0x20000;
    piVar2[0x284] = 0x575;
    piVar2[0x285] = 0;
    piVar2[0x286] = 0x574;
    piVar2[0x287] = 0;
    *(short *)(piVar2 + 0x10) = (short)((int)(piVar2 + 0x288) - (int)(piVar2 + 0x280) >> 2);
    piVar2[0x11] = *puVar1 & 0xfe0;
    piVar2[0x12] = 0;
    piVar2[0x13] = 0;
    piVar2[0x14] = 0;
    *(short *)((int)piVar2 + 0x42) = (short)local_10;
    piVar2[0x15] = 0;
    piVar2[0x17] = 0;
    puVar5 = (undefined4 *)FUN_0002e556(piVar2 + 0x288,6,0,0,0,uVar9,local_14 << 0x10 | local_18);
    if (uVar10 != 0) {
      puVar5 = (undefined4 *)FUN_0002e556(puVar5,6,0,0,0,uVar9,uVar10 >> 2 | 0x10000);
    }
    *(ushort *)(*(int *)param_2[2] + 0x1c) = *(ushort *)(*(int *)param_2[2] + 0x1c) | 1;
    *(ushort *)(*(int *)param_2[2] + 0x28) = *(ushort *)(*(int *)param_2[2] + 0x28) & 0xfffe;
    *puVar5 = 0xd0b;
    puVar5[1] = 5;
    puVar5[2] = 0x5c8;
    puVar5[3] = 0x10000;
    puVar6 = puVar5 + 4;
    if (param_3 != '\0') {
      uVar3 = *(undefined4 *)(param_1 + 0x1d74);
      puVar5[4] = 0x4790b1;
      puVar6 = puVar5 + 5;
      iVar7 = 0x48;
      do {
        *puVar6 = uVar3;
        puVar6 = puVar6 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    *piVar2 = (int)puVar6 - (int)(piVar2 + 0x280) >> 2;
  }
  *(undefined1 *)(*(int *)param_2[2] + 0x14) = 1;
  puVar8 = (uint *)param_2[1];
  if (((*puVar8 & 2) != 0) && ((*(byte *)(param_1 + 0x24) & 2) != 0)) {
    FUN_00009943(param_1,*puVar1,puVar1[2]);
    puVar8 = (uint *)param_2[1];
  }
LAB_0001c3bc:
  *puVar8 = 0;
  return 1;
}

/* FUN_0001c6c5 @ 0x1c6c5 (335 bytes) */
int FUN_0001c6c5(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  int local_24;
  int local_20;
  
  iVar1 = *param_2;
  iVar2 = param_2[1];
  uVar6 = *(uint *)(iVar1 + 0x300);
  if ((~*(uint *)(iVar1 + 0x30c) & *(uint *)(iVar1 + 0x304)) != 0 ||
      (~*(uint *)(iVar1 + 0x308) & uVar6) != 0) {
    return 0;
  }
  if (*(int *)(iVar2 + 0x88) != 0 || (*(uint *)(iVar2 + 0x84) & 0xfffffff5) != 0) {
    cVar5 = ((int (*)())FUN_0001b7c0)();
    if (cVar5 == '\0') {
      return 0;
    }
    uVar6 = *(uint *)(iVar1 + 0x300);
  }
  uVar6 = uVar6 & 0xffff0000;
  local_24 = 0;
  local_20 = 0;
  do {
    while (uVar6 == 0) {
      uVar6 = (uint)*(ushort *)(iVar1 + 0x304);
      local_20 = local_20 + 1;
      if (1 < local_20) {
        if (*(int *)(iVar2 + 0x80) != 0) {
          ((int (*)())FUN_0001c242)(param_1,*(int *)(iVar2 + 0x80),1);
        }
        iVar1 = param_2[1];
        *(undefined4 *)(iVar1 + 0x84) = 0;
        *(undefined4 *)(iVar1 + 0x88) = 0;
        return 1;
      }
      local_24 = 0x10;
    }
    uVar3 = (DAT_001ec240)[local_24];
    if ((uVar6 & uVar3) != 0) {
      iVar4 = *(int *)(iVar2 + local_24 * 4);
      if (iVar4 == 0) {
        return 0;
      }
      cVar5 = ((int (*)())FUN_0001c242)(param_1,iVar4,0);
      if (cVar5 == '\0') {
        return 0;
      }
      uVar6 = uVar6 & ~uVar3;
    }
    local_24 = local_24 + 1;
  } while( true );
}

/* FUN_0001c814 @ 0x1c814 (3759 bytes) */
int FUN_0001c814(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  uint param_6;
  uint param_7;
  int param_8;
{
  void *pvVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint *puVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  bool bVar8;
  int iVar9;
  uint *puVar10;
  byte bVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  byte *pbVar16;
  uint uVar17;
  int *piVar18;
  uint *puVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  bool bVar23;
  int local_a4;
  int *local_74;
  undefined4 *local_70;
  int local_68;
  int local_60;
  byte local_56;
  uint local_44;
  int local_40;
  uint local_30;
  uint local_20;
  
  piVar18 = *(int **)(param_1 + 0x1d4);
  if (piVar18 == (int *)0x0) {
    return 0;
  }
  if (*(char *)(param_1 + 0x2724) == '\0') {
    return 0;
  }
  bVar11 = *(byte *)(param_1 + 0x27c8) & 0x1f;
  uVar20 = (uint)bVar11;
  iVar9 = *piVar18;
  bVar5 = *(int *)(iVar9 + 0x308) != 0;
  bVar6 = *(int *)(iVar9 + 0x30c) != 0;
  if ((*(uint *)(iVar9 + 0x300) & 0x400000) == 0) {
    if (((*(int *)(*(int *)(param_1 + 0x10) + 0x3170) == 0x1b011b01) &&
        (*(char *)(param_8 + 0x7c) == '\0')) && (param_3 - 4U < 6)) {
      return 1;
    }
  }
  else if (((*(short *)(*(int *)(param_1 + 0x10) + 0x3170) == 0x1b02) ||
           (*(short *)(*(int *)(param_1 + 0x10) + 0x3172) == 0x1b02)) && (param_3 - 4U < 6)) {
    return 0;
  }
  iVar14 = *piVar18;
  iVar13 = *(int *)(piVar18[1] + 0x80);
  if (param_5 < 0x20) {
LAB_0001c8c2:
    local_56 = 0;
LAB_0001c8c6:
    if (param_6 == 0x14ff) {
LAB_0001c9ed:
      uVar15 = 0xffff;
    }
    else {
      if (param_6 == 0x1405) goto LAB_0001d371;
      uVar15 = 0x7ffa;
    }
  }
  else {
    if (((*(int *)(iVar14 + 0x30c) != 0 || *(int *)(iVar14 + 0x308) != 0) && (iVar13 != 0)) &&
       ((*(int **)(iVar13 + 8) != (int *)0x0 && (**(int **)(iVar13 + 8) != 0)))) {
      if (param_6 == 0x1403) {
        if ((*(int *)(iVar13 + 0x10) != 7) || (*(char *)(iVar13 + 0xc) != '\0')) goto LAB_0001c9d5;
        local_56 = 1;
      }
      else if (param_6 == 0x1405) {
        *(undefined1 *)(iVar13 + 0xc) = 1;
        local_56 = 1;
      }
      else {
LAB_0001c9d5:
        local_56 = 0;
      }
      if ((param_7 & 1) != 0) goto LAB_0001c8c2;
      if (local_56 == 0) goto LAB_0001c8c6;
      goto LAB_0001c9ed;
    }
    if ((((*(int *)(iVar14 + 0x30c) != 0 || *(int *)(iVar14 + 0x308) != 0) ||
         ((*(uint *)(iVar14 + 0x300) & 0x800000) == 0)) || (param_2 != 2)) || (param_6 != 0x1405))
    goto LAB_0001c8c2;
    if ((param_7 & 1) == 0) {
      if ((*(uint *)(iVar14 + 0x314) <= *(uint *)(iVar14 + 0xa8)) &&
         (*(uint *)(iVar14 + 0xa8) < *(uint *)(iVar14 + 0x314) + *(int *)(iVar14 + 0x318))) {
        uVar15 = 0xffff;
        local_56 = 1;
        goto LAB_0001c8e5;
      }
    }
    local_56 = 0;
LAB_0001d371:
    uVar15 = 0x3ffd;
  }
LAB_0001c8e5:
  local_20 = FUN_0002ab76(param_1,1,param_3,param_5);
  bVar23 = local_20 != 0;
  switch(param_3) {
  case 0:
    break;
  case 1:
  case 8:
    uVar15 = uVar15 & 0xfffffffe;
    break;
  default:
    if (uVar15 < local_20) {
      bVar23 = false;
      goto LAB_0001ca03;
    }
    break;
  case 4:
    uVar15 = (uVar15 / 3) * 3;
    goto LAB_0001ca03;
  case 7:
    uVar15 = uVar15 & 0xfffffffc;
    goto LAB_0001ca03;
  }
LAB_0001ca03:
  local_30 = local_20;
  if (uVar15 <= local_20) {
    local_30 = uVar15;
  }
  if (!bVar23) {
    return 0;
  }
  if (((param_6 == 0x14ff) || (*(int *)(param_1 + 0x2720) != 0)) || (local_56 != 0)) {
    bVar23 = true;
    bVar8 = true;
  }
  else if (*(int *)(param_1 + 0x26d4) == param_1 + 0x2768) {
    bVar23 = false;
    bVar8 = false;
  }
  else {
    bVar23 = true;
    bVar8 = false;
  }
  uVar15 = ~-(uint)(*(char *)(param_1 + 0x2a42) == '\0') & 2;
  if (*(int *)(param_1 + 0x2680) != param_1 + 0x2630) {
    uVar15 = uVar15 + 4 + (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe);
  }
  if (bVar23) {
    iVar14 = **(int **)(param_1 + 0x1d4);
    if (*(int *)(iVar14 + 0x30c) == 0 && *(int *)(iVar14 + 0x308) == 0) {
      iVar14 = uVar15 + 0x14;
    }
    else {
      iVar14 = uVar20 + uVar15 + 0x13;
    }
    uVar15 = (iVar14 - (uint)(local_56 == 0)) + 4 + (uVar20 + 1 >> 1) * 3;
    if (*(int *)(param_1 + 0x2720) != 0) {
      uVar15 = uVar15 + 1 + *(int *)(param_1 + 0x2720);
    }
    puVar3 = *(undefined4 **)((*(int **)(param_1 + 0x1d4))[1] + 0x80);
  }
  else {
    puVar3 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x1d4) + 4) + 0x80);
  }
  if (bVar5 || bVar6) {
    local_60 = 0;
  }
  else {
    local_60 = *(int *)(iVar9 + 0x314);
  }
  uVar21 = uVar20 + 1 >> 1;
  local_74 = (int *)0x0;
  local_70 = (undefined4 *)0x0;
  local_68 = 0;
  do {
    if ((int)local_20 < 1) {
      *(undefined1 *)(param_1 + 0x27d5) = 1;
      *(undefined1 *)(param_1 + 0x2a5e) = 1;
      return 1;
    }
    iVar9 = local_68 * local_30 + param_4;
    uVar22 = local_20;
    if (local_30 <= local_20) {
      uVar22 = local_30;
    }
    if (param_6 == 0x1403) {
LAB_0001cfba:
      if (local_56 == 0) {
        iVar14 = (uVar22 + 1 >> 1) + 4;
      }
      else {
LAB_0001d26d:
        iVar14 = 8;
      }
    }
    else if (param_6 < 0x1404) {
      if (param_6 == 0x1401) goto LAB_0001cfba;
LAB_0001cb82:
      iVar14 = 0;
    }
    else if (param_6 == 0x1405) {
      if (local_56 != 0) goto LAB_0001d26d;
      iVar14 = uVar22 + 4;
    }
    else {
      if (param_6 != 0x14ff) goto LAB_0001cb82;
      iVar14 = 4;
    }
    puVar10 = (uint *)(**(code **)(param_1 + 0x2998))(param_1 + 0x240,iVar14 + uVar15 + 2);
    *(uint **)(param_1 + 0x298c) = puVar10;
    if (*(char *)(param_1 + 0x2a42) != '\0') {
      *puVar10 = 0x5c8;
      puVar10[1] = 0x10000000;
      puVar10 = puVar10 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 0;
    }
    if (*(int *)(param_1 + 0x2680) != param_1 + 0x2630) {
      *(int *)(param_1 + 0x2680) = param_1 + 0x2630;
      *(int *)(param_1 + 0x2684) = param_1 + 0x2650;
      puVar10 = (uint *)FUN_0002a122(param_1,puVar10);
    }
    if (bVar23) {
      *(int *)(param_1 + 0x26d4) = param_1 + 0x2768;
      *(int *)(param_1 + 0x26d8) = param_1 + 0x2788;
      *(undefined4 *)(param_1 + 0x26d0) = *(undefined4 *)(param_1 + 0x27c8);
      local_70 = (undefined4 *)((uint)(puVar10 + 0xb) & 0xffffffe0);
      *puVar10 = (((int)local_70 - (int)puVar10) + -8) * 0x4000 | 0xc0001000;
      local_70[-1] = (int)local_70 - (int)puVar10;
      puVar10 = *(uint **)(param_1 + 0x1d8);
      *puVar10 = *puVar10 | (int)local_70 - (int)puVar10 >> 2;
      *(undefined4 **)(param_1 + 0x1d8) = local_70;
      *local_70 = 0x39000000;
      local_70[1] = uVar20;
      local_70[2] = (uint)(bVar5 || bVar6);
      local_70[3] = (uint)local_56;
      local_70[4] = (uint)(param_6 != 0x1403) * 2 + 2;
      puVar10 = local_70 + 8;
      iVar14 = **(int **)(param_1 + 0x1d4);
      if (*(int *)(iVar14 + 0x30c) == 0 && *(int *)(iVar14 + 0x308) == 0) {
        local_70[8] = *(undefined4 *)(*(int **)(param_1 + 0x1d4))[0x8a];
        puVar10 = local_70 + 9;
        iVar14 = *(int *)(*(int *)(param_1 + 0x1d4) + 0x228);
        *(int *)(iVar14 + 0x10) = *(int *)(iVar14 + 0x10) + 0x10000;
        if (local_56 != 0) {
          local_70[9] = **(undefined4 **)(*(int *)(param_1 + 0x1d4) + 0x228);
          puVar10 = local_70 + 10;
          iVar14 = *(int *)(*(int *)(param_1 + 0x1d4) + 0x228);
          *(int *)(iVar14 + 0x10) = *(int *)(iVar14 + 0x10) + 0x10000;
        }
      }
      else {
        if (bVar11 != 0) {
          uVar12 = 0;
          do {
            puVar4 = *(uint **)(param_1 + 0x2728 + uVar12 * 4);
            *puVar10 = *puVar4;
            puVar10 = puVar10 + 1;
            puVar4[4] = puVar4[4] + 0x10000;
            uVar12 = uVar12 + 1;
          } while (uVar12 < uVar20);
        }
        if (local_56 != 0) {
          *puVar10 = *(uint *)**(undefined4 **)
                                (*(int *)(*(int *)(*(int *)(param_1 + 0x1d4) + 4) + 0x80) + 8);
          puVar10 = puVar10 + 1;
          iVar14 = **(int **)(*(int *)(*(int *)(*(int *)(param_1 + 0x1d4) + 4) + 0x80) + 8);
          *(int *)(iVar14 + 0x10) = *(int *)(iVar14 + 0x10) + 0x10000;
        }
      }
      local_70[5] = ((int)puVar10 - (int)local_70 >> 2) + 2;
      if (param_6 == 0x14ff) {
        *puVar10 = (uVar21 * 3 + -1) * 0x10000 | 0x831;
        puVar10 = puVar10 + 1;
        if (uVar21 != 0) {
          uVar12 = 0;
          piVar18 = (int *)(param_1 + 0x278c);
          do {
            *puVar10 = *(uint *)(param_1 + 0x2768 + uVar12 * 4);
            if (piVar18[-1] == -1) {
              puVar10[1] = 0xffffffff;
              local_a4 = *piVar18;
              if (local_a4 != -1) goto LAB_0001d2d0;
LAB_0001d33b:
              puVar10[2] = 0xffffffff;
            }
            else {
              puVar10[1] = piVar18[-1] +
                           (uint)(*(byte *)(param_1 + 0x2769 + uVar12 * 4) & 0x7f) * param_4 * 4;
              local_a4 = *piVar18;
              if (local_a4 == -1) goto LAB_0001d33b;
LAB_0001d2d0:
              puVar10[2] = local_a4 +
                           (uint)(*(byte *)(param_1 + 0x276b + uVar12 * 4) & 0x7f) * param_4 * 4;
            }
            puVar10 = puVar10 + 3;
            uVar12 = uVar12 + 1;
            piVar18 = piVar18 + 2;
          } while (uVar21 != uVar12);
        }
        *puVar10 = 0x830;
        puVar10[1] = *(uint *)(param_1 + 0x27c8);
        puVar10 = puVar10 + 2;
        *(undefined4 *)(param_1 + 0x26d4) = 0;
      }
      else {
        puVar10 = (uint *)FUN_0002a1bf(param_1,puVar10);
      }
      local_70[6] = (int)puVar10 + (4 - (int)local_70) >> 2;
      local_74 = local_70 + 7;
      local_44 = *(uint *)(param_1 + 0x271c);
      bVar23 = bVar8;
      if (local_44 != 0) {
        *puVar10 = (*(int *)(param_1 + 0x2720) + -1) * 0x10000 | 0xc0001000;
        puVar4 = puVar10 + 1;
        if (*(int *)(*(int *)(param_1 + 0x14) + 0x11c) == 0) {
          iVar14 = *(int *)(param_1 + 0x1cc);
          if (iVar14 == 0) {
            if ((local_44 & 2) != 0) {
              puVar10[1] = *(uint *)(param_8 + 0x40);
              puVar10[2] = *(uint *)(param_8 + 0x44);
              puVar10[3] = *(uint *)(param_8 + 0x48);
              puVar10[4] = 0x3f800000;
              puVar4 = puVar10 + 5;
            }
            puVar10 = puVar4;
            if ((local_44 & 4) != 0) {
              *puVar10 = *(uint *)(param_8 + 0x30);
              puVar10[1] = *(uint *)(param_8 + 0x34);
              puVar10[2] = *(uint *)(param_8 + 0x38);
              puVar10[3] = *(uint *)(param_8 + 0x3c);
              puVar10 = puVar10 + 4;
            }
            if ((local_44 & 8) != 0) {
              *puVar10 = *(uint *)(param_8 + 0x50);
              puVar10[1] = *(uint *)(param_8 + 0x54);
              puVar10[2] = *(uint *)(param_8 + 0x58);
              puVar10[3] = 0x3f800000;
              puVar10 = puVar10 + 4;
            }
            iVar13 = 0;
            iVar14 = param_8;
            do {
              if ((local_44 & 0x400 << ((byte)iVar13 & 0x1f)) != 0) {
                *puVar10 = *(uint *)(iVar14 + 0x80);
                puVar10[1] = *(uint *)(iVar14 + 0x84);
                puVar10[2] = *(uint *)(iVar14 + 0x88);
                puVar10[3] = *(uint *)(iVar14 + 0x8c);
                puVar10 = puVar10 + 4;
              }
              iVar13 = iVar13 + 1;
              iVar14 = iVar14 + 0x10;
            } while (iVar13 != 8);
            if ((local_44 & 0x40000) != 0) {
              *puVar10 = *(uint *)(param_8 + 0x5c);
              puVar10[1] = 0x3f800000;
              puVar10[2] = 0x3f800000;
              puVar10[3] = 0x3f800000;
              puVar10 = puVar10 + 4;
            }
            if ((local_44 & 0x80000) != 0) {
              *puVar10 = *(uint *)(param_8 + 0x60);
              puVar10[1] = *(uint *)(param_8 + 100);
              puVar10[2] = *(uint *)(param_8 + 0x68);
              puVar10[3] = *(uint *)(param_8 + 0x6c);
              puVar10 = puVar10 + 4;
            }
            goto LAB_0001cdbc;
          }
        }
        else {
          iVar14 = *(int *)(param_1 + 0x1cc);
        }
        iVar13 = *(int *)(*(int *)(param_1 + 0x14) + 0x11c);
        puVar10 = puVar4;
        if (iVar14 == 0) {
          local_40 = 0x16;
        }
        else {
          local_40 = *(int *)(*(int *)(param_1 + 0x29e8) + 0x28);
          if (local_40 == 0) goto LAB_0001cdbc;
        }
        iVar14 = 0;
        do {
          uVar12 = 1 << ((byte)iVar14 & 0x1f);
          if ((local_44 & uVar12) != 0) {
            iVar7 = iVar14;
            if (iVar13 != 0) {
              iVar7 = *(int *)(param_1 + 0x27dc + iVar14 * 4);
            }
            puVar4 = (uint *)(param_8 + iVar7 * 0x10);
            *puVar10 = *puVar4;
            puVar10[1] = puVar4[1];
            puVar10[2] = puVar4[2];
            puVar10[3] = puVar4[3];
            puVar10 = puVar10 + 4;
            local_44 = local_44 & ~uVar12;
          }
        } while ((local_44 != 0) && (iVar14 = iVar14 + 1, local_40 != iVar14));
      }
    }
LAB_0001cdbc:
    if (param_6 == 0x1403) {
      puVar4 = (uint *)(param_7 + iVar9 * 2);
      uVar12 = (byte)(DAT_001ec200)[param_3 * 4] & 0xf | 0x10 | uVar22 << 0x10;
      if (local_56 == 0) {
        *puVar10 = 0x82c;
        puVar10[1] = *(uint *)(param_1 + 0x1dc4);
        puVar10[2] = (uVar22 + 1 >> 1) << 0x10 | 0xc0003600;
        puVar10[3] = uVar12;
        puVar10 = puVar10 + 4;
        if ((uVar22 & 0xfffffffe) != 0) {
          uVar12 = 0;
          puVar19 = puVar4;
          do {
            *puVar10 = *puVar19;
            puVar10 = puVar10 + 1;
            uVar12 = uVar12 + 2;
            puVar19 = puVar19 + 1;
          } while (uVar12 < (uVar22 & 0xfffffffe));
        }
        if ((uVar22 & 1) != 0) {
          *puVar10 = (uint)*(ushort *)((int)puVar4 + uVar22 * 2 + -2);
          puVar10 = puVar10 + 1;
        }
      }
      else {
        uVar17 = uVar22 + 1 >> 1;
        *puVar10 = 0x82c;
        puVar10[1] = *(uint *)(param_1 + 0x1dc4);
        puVar10[2] = 0xc0003600;
        puVar10[3] = uVar12;
        *local_74 = (int)puVar10 + (0x10 - (int)local_70) >> 2;
        local_74 = local_74 + 1;
        puVar10[4] = 0xc0023300;
        puVar10[5] = 0x80000810;
        if (puVar3 == (undefined4 *)0x0) {
          puVar10[6] = (int)puVar4 - local_60;
          puVar10[7] = uVar17;
          puVar10 = puVar10 + 8;
        }
        else {
          puVar10[6] = (int)puVar4 - *(int *)*puVar3;
          puVar10[7] = uVar17;
          puVar10 = puVar10 + 8;
        }
      }
    }
    else if (param_6 < 0x1404) {
      if (param_6 != 0x1401) {
        return 0;
      }
      bVar2 = (DAT_001ec200)[param_3 * 4];
      *puVar10 = 0x82c;
      puVar10[1] = *(uint *)(param_1 + 0x1dc4);
      puVar10[2] = (uVar22 + 1 >> 1) << 0x10 | 0xc0003600;
      puVar10[3] = bVar2 & 0xf | 0x10 | uVar22 << 0x10;
      puVar10 = puVar10 + 4;
      if ((uVar22 & 0xfffffffe) != 0) {
        uVar12 = 0;
        pbVar16 = (byte *)(param_7 + iVar9);
        do {
          *puVar10 = (uint)pbVar16[1] << 0x10 | (uint)*pbVar16;
          puVar10 = puVar10 + 1;
          uVar12 = uVar12 + 2;
          pbVar16 = pbVar16 + 2;
        } while (uVar12 < (uVar22 & 0xfffffffe));
      }
      if ((uVar22 & 1) != 0) {
        *puVar10 = (uint)((byte *)(param_7 + iVar9))[uVar22 - 1];
        puVar10 = puVar10 + 1;
      }
    }
    else if (param_6 == 0x1405) {
      pvVar1 = (void *)(param_7 + iVar9 * 4);
      uVar12 = (byte)(DAT_001ec200)[param_3 * 4] & 0xf | 0x810 | uVar22 << 0x10;
      if (local_56 == 0) {
        *puVar10 = 0x82c;
        puVar10[1] = *(uint *)(param_1 + 0x1dc4);
        puVar10[2] = uVar22 << 0x10 | 0xc0003600;
        puVar10[3] = uVar12;
        _memcpy(puVar10 + 4,pvVar1,uVar22 * 4);
        puVar10 = puVar10 + 4 + uVar22;
      }
      else {
        *puVar10 = 0x82c;
        puVar10[1] = *(uint *)(param_1 + 0x1dc4);
        puVar10[2] = 0xc0003600;
        puVar10[3] = uVar12;
        *local_74 = (int)puVar10 + (0x10 - (int)local_70) >> 2;
        local_74 = local_74 + 1;
        puVar10[4] = 0xc0023300;
        puVar10[5] = 0x80000810;
        if (puVar3 == (undefined4 *)0x0) {
          puVar10[6] = (int)pvVar1 - local_60;
        }
        else {
          puVar10[6] = (int)pvVar1 - *(int *)*puVar3;
        }
        puVar10[7] = uVar22;
        puVar10 = puVar10 + 8;
      }
    }
    else {
      if (param_6 != 0x14ff) {
        return 0;
      }
      bVar2 = (DAT_001ec200)[param_3 * 4];
      *puVar10 = 0x82c;
      puVar10[1] = *(uint *)(param_1 + 0x1dc4);
      puVar10[2] = 0xc0003400;
      puVar10[3] = bVar2 & 0xf | 0x820 | uVar22 << 0x10;
      puVar10 = puVar10 + 4;
      param_4 = param_4 + uVar22;
    }
    *puVar10 = 0x1393;
    puVar10[1] = 0;
    puVar10 = puVar10 + 2;
    *(uint **)(param_1 + 0x298c) = puVar10;
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240,puVar10);
    local_20 = local_20 - uVar22;
    local_68 = local_68 + 1;
    local_30 = uVar22;
    if (*(uint **)(param_1 + 0x2994) <= puVar10) {
      if (**(int **)(param_1 + 0x238) == (*(int **)(param_1 + 0x238))[8]) {
        ((int (*)())FUN_00017c77)(param_1,0x1000000);
      }
      else {
        *(uint **)(param_1 + 0x2994) = *(uint **)(param_1 + 0x2994) + 0x1000;
      }
    }
  } while( true );
}

/* FUN_0001d6e9 @ 0x1d6e9 (1315 bytes) */
int FUN_0001d6e9(param_1)
  int param_1;
{
  uint *puVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int local_78;
  int local_68;
  uint local_64;
  int local_54;
  int *local_50;
  int local_4c;
  int local_48;
  int local_44;
  byte local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint *local_14;
  
  iVar3 = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x2494) = 0;
  *(int *)(param_1 + 0x2440) = param_1 + 0x249c;
  *(int *)(param_1 + 0x2444) = param_1 + 0x24bc;
  piVar4 = *(int **)(iVar3 + 0x1d4);
  if (piVar4 == (int *)0x0) {
    return;
  }
  iVar5 = *piVar4;
  iVar6 = piVar4[1];
  uVar7 = *(uint *)(param_1 + 0x243c);
  bVar9 = *(uint *)(iVar5 + 0x308) != 0;
  bVar10 = *(uint *)(iVar5 + 0x30c) != 0;
  if (*(int *)(iVar3 + 0x1cc) == 0) {
    local_64 = *(uint *)(iVar5 + 0x300);
    if ((local_64 & 0x10000) != 0) goto LAB_0001d78e;
  }
  else {
    local_64 = *(uint *)(iVar5 + 0x300);
    if ((*(uint *)(iVar5 + 0x304) & 1) != 0 || (local_64 & 0x10000) != 0) {
LAB_0001d78e:
      bVar11 = false;
      cVar2 = *(char *)(iVar3 + 0x20);
      goto joined_r0x0001d7d3;
    }
  }
  bVar11 = true;
  cVar2 = *(char *)(iVar3 + 0x20);
joined_r0x0001d7d3:
  if (((((cVar2 == '\0') || (0x10 < uVar7)) || (uVar7 < 2)) ||
      ((bVar9 || bVar10 &&
       ((~*(uint *)(iVar5 + 0x30c) & *(uint *)(iVar5 + 0x304)) != 0 ||
        (~*(uint *)(iVar5 + 0x308) & local_64) != 0)))) || (bVar11)) {
LAB_0001d79b:
    *(undefined1 *)(param_1 + 0x24e4) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x24dc) = 0;
    *(undefined4 *)(param_1 + 0x24e0) = 0;
    *(undefined1 *)(param_1 + 0x24e4) = 1;
    if (*(int **)(iVar3 + 0x1cc) == (int *)0x0) {
      local_54 = 0;
      local_50 = (int *)0x0;
      local_4c = 0;
      local_44 = 0;
    }
    else {
      local_54 = *(int *)(iVar3 + 0x29e8) + 0x14;
      local_50 = *(int **)(*(int *)(iVar3 + 0x29e8) + 0x34);
      local_4c = *(int *)(**(int **)(iVar3 + 0x1cc) + 4);
      local_44 = *(int *)(local_4c + 0x24);
    }
    *(undefined4 *)(param_1 + 0x2588) = 0;
    local_28 = (byte)uVar7;
    *(byte *)(param_1 + 0x2588) = *(byte *)(param_1 + 0x2588) & 0xe0 | 0x20 | local_28 & 0x1f;
    local_48 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_14 = (uint *)&DAT_001ec440;
    do {
      iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x1cc);
      if (iVar3 == 0) {
        if ((*(uint *)(param_1 + 0x1ca0) & 1 << ((byte)local_20 & 0x1f)) != 0) goto LAB_0001da0c;
      }
      else if ((*(int *)(*(int *)(local_54 + 0x20) + local_20 * 4) != 0x80) ||
              (*(uint *)(local_54 + 0x1c) <= local_20)) {
LAB_0001da0c:
        if (local_4c != 0) {
          if (local_20 < *(uint *)(local_54 + 0x1c)) {
            local_48 = local_4c + (local_44 + local_50[local_20]) * 8;
          }
          else {
            local_48 = local_4c + (local_44 + *local_50) * 8;
          }
        }
        if (iVar3 == 0) {
          uVar12 = *local_14;
        }
        else {
          uVar12 = *(uint *)(&DAT_001ec4a0 + (uint)(*(byte *)(local_48 + 1) >> 4) * 4);
          if (uVar12 == 8) {
            uVar12 = (*(byte *)(local_48 + 3) >> 3) + 8;
          }
          else if (uVar12 == 0x10) {
            uVar12 = (*(byte *)(local_48 + 3) >> 3) + 0x10;
          }
          else if (uVar12 == 0x2f) {
            switch(*(byte *)(local_48 + 2) & 0xf) {
            case 0:
              uVar12 = (*(byte *)(local_48 + 3) >> 7) + 0x20;
              break;
            case 1:
              uVar12 = (*(byte *)(local_48 + 3) >> 7) + 0x22;
              break;
            case 2:
              uVar12 = (*(byte *)(local_48 + 3) >> 7) + 0x24;
              break;
            case 3:
              uVar12 = (*(byte *)(local_48 + 3) >> 7) + 0x26;
              break;
            case 4:
              uVar12 = (*(byte *)(local_48 + 3) >> 7) + 0x28;
              break;
            default:
              goto LAB_0001dc59;
            }
          }
        }
        if (uVar12 == 0x30) {
LAB_0001dc59:
          *(undefined1 *)(param_1 + 0x24e4) = 0;
          return;
        }
        if (uVar12 < 0x10) {
          if (((DAT_001ec240)[uVar12] & *(uint *)(iVar5 + 0x300)) == 0) goto LAB_0001da92;
LAB_0001d8f7:
          if (*(char *)((int)piVar4 + uVar12 + 8) == '\0') goto LAB_0001d79b;
          local_78 = piVar4[uVar12 + 10];
          local_68 = piVar4[uVar12 + 0x2a];
          uVar13 = piVar4[uVar12 + 0x4a];
          uVar14 = piVar4[uVar12 + 0x6a];
          if ((bVar9 || bVar10) &&
             (puVar8 = *(undefined4 **)(*(int *)(iVar6 + uVar12 * 4) + 8),
             puVar8 != (undefined4 *)0x0)) {
            *(undefined4 *)(param_1 + 0x24e8 + local_24 * 4) = *puVar8;
          }
          if ((local_24 & 1) == 0) goto LAB_0001dae2;
LAB_0001d951:
          puVar1 = (uint *)(param_1 + 0x2528 + local_1c * 4);
          *puVar1 = *puVar1 | local_78 << 0x10;
          *(int *)(param_1 + 0x2548 + local_24 * 4) = local_68;
          uVar12 = *(uint *)(param_1 + 0x1be4 + local_1c * 4);
          puVar1 = (uint *)(param_1 + 0x23f0 + local_1c * 4);
          *puVar1 = *puVar1 | uVar13 << 0x10 | uVar12 & 0x1f000000 | uVar12 & 0x20000000;
          puVar1 = (uint *)(param_1 + 0x2410 + local_1c * 4);
          *puVar1 = *puVar1 | uVar14 << 0x10 |
                              *(uint *)(param_1 + 0x1c04 + local_1c * 4) & 0xf0000000;
        }
        else {
          if (((DAT_001ec240)[uVar12] & *(uint *)(iVar5 + 0x304)) != 0) goto LAB_0001d8f7;
LAB_0001da92:
          *(uint *)(param_1 + 0x24dc) = *(uint *)(param_1 + 0x24dc) | 1 << ((byte)local_20 & 0x1f);
          *(int *)(param_1 + 0x24e0) = *(int *)(param_1 + 0x24e0) + 4;
          if (bVar9 || bVar10) {
            *(undefined4 *)(param_1 + 0x24e8 + local_24 * 4) =
                 *(undefined4 *)(param_1 + 0x24e4 + local_24 * 4);
          }
          local_78 = 4;
          local_68 = -1;
          uVar13 = 3;
          uVar14 = 0x688;
          if ((local_24 & 1) != 0) goto LAB_0001d951;
LAB_0001dae2:
          *(int *)(param_1 + 0x2528 + local_1c * 4) = local_78;
          *(int *)(param_1 + 0x2548 + local_24 * 4) = local_68;
          uVar12 = *(uint *)(param_1 + 0x1be4 + local_1c * 4);
          *(uint *)(param_1 + 0x23f0 + local_1c * 4) = uVar13 | uVar12 & 0x1f00 | uVar12 & 0x2000;
          *(uint *)(param_1 + 0x2410 + local_1c * 4) =
               uVar14 | *(uint *)(param_1 + 0x1c04 + local_1c * 4) & 0xf000;
        }
        local_24 = local_24 + 1;
        local_1c = local_24 >> 1;
      }
      if (local_24 == uVar7) {
        return;
      }
      local_20 = local_20 + 1;
      local_14 = local_14 + 1;
    } while (local_20 != 0x16);
  }
  return;
}

/* FUN_0001dc89 @ 0x1dc89 (296 bytes) */
int FUN_0001dc89(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  iVar2 = *(int *)(param_1 + 0x10);
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  if (*(char *)(iVar2 + 0x3190) == '\0') {
    local_14 = *(int *)(param_1 + 0x15c);
    local_10 = *(int *)(param_1 + 0x160);
    local_1c = 0;
    local_18 = 0;
  }
  else {
    local_1c = *(int *)(iVar2 + 0x3180);
    if (*(char *)(param_1 + 0x2b7c) == '\0') {
      local_18 = *(int *)(iVar2 + 0x3184);
      iVar3 = *(int *)(iVar2 + 0x318c);
      iVar1 = *(int *)(param_1 + 0x160);
      iVar2 = *(int *)(iVar2 + 0x3188);
    }
    else {
      iVar3 = *(int *)(iVar2 + 0x318c);
      iVar1 = *(int *)(param_1 + 0x160);
      local_18 = iVar1 - (*(int *)(iVar2 + 0x3184) + iVar3);
      iVar2 = *(int *)(iVar2 + 0x3188);
    }
    if (local_1c < 0) {
      iVar2 = iVar2 + local_1c;
      local_1c = 0;
    }
    if (local_18 < 0) {
      iVar3 = iVar3 + local_18;
      local_18 = 0;
    }
    local_14 = *(int *)(param_1 + 0x15c) - local_1c;
    if (iVar2 <= local_14) {
      local_14 = iVar2;
    }
    local_10 = iVar1 - local_18;
    if (iVar3 <= iVar1 - local_18) {
      local_10 = iVar3;
    }
    if (local_14 < 1) {
      return;
    }
    if (local_10 < 1) {
      return;
    }
  }
  local_14 = local_1c + local_14;
  local_10 = local_18 + local_10;
  FUN_0008a701(param_1 + 0x240,0,0,&local_1c,0);
  return;
}

/* FUN_0001ddb1 @ 0x1ddb1 (155 bytes) */
int FUN_0001ddb1(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  param_2 = *(uint *)(param_1 + 0x158) & param_2;
  iVar1 = *(int *)(param_1 + 0x10);
  if (((*(char *)(iVar1 + 0x2e43) == '\0' && *(char *)(iVar1 + 0x2e40) == '\0') &&
      *(char *)(iVar1 + 0x2e41) == '\0') && *(char *)(iVar1 + 0x2e42) == '\0') {
    param_2 = param_2 & 0xffffbfff;
  }
  if (*(char *)(iVar1 + 0x2e44) == '\0') {
    param_2 = param_2 & 0xfffffeff;
  }
  if ((param_2 & 0x200) != 0) {
    FUN_000010c4(param_1,iVar1);
  }
  if ((param_2 & 0x4000) != 0) {
    ((int (*)())FUN_0001dc89)(param_1);
    param_2 = param_2 & 0xffffbfff;
  }
  if ((param_2 & 0x500) == 0) {
    return;
  }
  FUN_000a5097();
  return;
}

/* FUN_0001de4c @ 0x1de4c (1838 bytes) */
int FUN_0001de4c(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  int local_20 [4];
  
  local_3c = 0;
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  local_34 = 0;
  local_38 = 0;
  local_20[0] = 0;
  if (param_5 != 0) {
    iVar2 = _CFStringCreateWithCString(0,"pid",0x600);
    iVar3 = _CFStringCreateWithCString(0,"gldisplaymask",0x600);
    iVar4 = _CFStringCreateWithCString(0,"log_notifications",0x600);
    iVar5 = _CFStringCreateWithCString(0,"fsaa_samples",0x600);
    iVar6 = _CFStringCreateWithCString(0,"fsaa_mode",0x600);
    iVar7 = _CFStringCreateWithCString(0,"aniso_level",0x600);
    iVar8 = _CFStringCreateWithCString(0,"vsync_mode",0x600);
    iVar9 = _CFStringCreateWithCString(0,"performance_level",0x600);
    if (iVar2 != 0) {
      if (((((iVar3 != 0) && (iVar4 != 0)) && (iVar5 != 0)) && ((iVar7 != 0 && (iVar8 != 0)))) &&
         (iVar9 != 0)) {
        iVar10 = _CFDictionaryGetValue(param_5,iVar4);
        if (iVar10 != 0) {
          cVar1 = _CFNumberGetValue(iVar10,3,&local_28);
          if ((cVar1 != '\0') && (local_28 != 0)) {
            _puts("\nATI R300 GL Driver Notification Callback");
            ((int (*)())FUN_00015a01)(param_2);
          }
        }
        iVar10 = _CFDictionaryGetValue(param_5,iVar2);
        iVar11 = _CFDictionaryGetValue(param_5,iVar3);
        if ((iVar10 == 0) || (iVar11 == 0)) {
          if (local_28 != 0) {
            if (iVar10 == 0) {
              _puts("  failed to extract process id from CFDictionary | expected \"pid\"");
            }
            if (iVar11 == 0) {
              _puts(
                   "  failed to extract gl display mask from CFDictionary | expected \"gldisplaymask\""
                   );
            }
          }
        }
        else {
          cVar1 = _CFNumberGetValue(iVar10,3,&local_3c);
          if (cVar1 != '\0') {
            cVar1 = _CFNumberGetValue(iVar11,3,&local_24);
            if (cVar1 != '\0') {
              iVar10 = *(int *)(param_2 + 0x2a60);
              if ((iVar10 == local_3c) && ((*(uint *)(param_2 + 0x2a64) & local_24) != 0)) {
                *(undefined1 *)(param_2 + 0x2a68) = 1;
                if (local_28 != 0) {
                  _printf("  process id [%i] and gl display mask [0x%x] match\n",iVar10,local_24);
                }
                iVar10 = _CFDictionaryGetValue(param_5,iVar6);
                if (iVar10 == 0) {
                  if (local_28 != 0) {
                    _puts("  failed to extract fsaa mode from CFDictionary | expected \"fsaa_mode\""
                         );
                  }
                }
                else {
                  cVar1 = _CFNumberGetValue(iVar10,3,&local_30);
                  if (cVar1 != '\0') {
                    *(int *)(param_2 + 0x2a74) = local_30;
                    if (local_28 != 0) {
                      if (local_30 == 1) {
                        _puts("  fsaa mode | multisampling");
                      }
                      else if (local_30 == 0) {
                        _puts("  fsaa mode | app value");
                      }
                      else if (local_30 == 2) {
                        _puts("  fsaa mode | supersampling");
                      }
                    }
                  }
                }
                iVar10 = _CFDictionaryGetValue(param_5,iVar5);
                if (iVar10 == 0) {
                  if (local_28 != 0) {
                    _puts(
                         "  failed to extract fsaa samples from CFDictionary | expected \"fsaa_samples\""
                         );
                  }
                }
                else {
                  cVar1 = _CFNumberGetValue(iVar10,3,&local_2c);
                  if (cVar1 != '\0') {
                    *(int *)(param_2 + 0x2a70) = local_2c;
                    if (local_28 != 0) {
                      if (local_2c == 0) {
                        _puts("  fsaa samples | app value");
                      }
                      else {
                        _printf("  fsaa samples | %i\n",local_2c);
                      }
                    }
                  }
                }
                iVar10 = _CFDictionaryGetValue(param_5,iVar7);
                if (iVar10 == 0) {
                  if (local_28 != 0) {
                    _puts(
                         "  failed to extract anisotropic filtering samples from CFDictionary | expected \"aniso_level\""
                         );
                  }
                }
                else {
                  cVar1 = _CFNumberGetValue(iVar10,3,&local_34);
                  if (cVar1 != '\0') {
                    *(int *)(param_2 + 0x2a7c) = local_34;
                    if (local_28 != 0) {
                      if (local_34 == 0) {
                        _puts("  anisotropic filtering samples | app value");
                      }
                      else {
                        _printf("  anisotropic filtering samples | %i\n",local_34);
                      }
                    }
                  }
                }
                iVar10 = _CFDictionaryGetValue(param_5,iVar8);
                if (iVar10 == 0) {
                  if (local_28 != 0) {
                    _puts(
                         "  failed to extract vertical sync mode from CFDictionary | expected \"vsync_mode\""
                         );
                  }
                }
                else {
                  cVar1 = _CFNumberGetValue(iVar10,3,&local_38);
                  if (cVar1 != '\0') {
                    *(char *)(param_2 + 0x2a6c) = (char)local_38;
                    if (local_28 != 0) {
                      if (local_38 == 1) {
                        _puts("  vsync mode | forced off");
                      }
                      else if (local_38 == 0) {
                        _puts("  vsync mode | app value");
                      }
                      else if (local_38 == 2) {
                        _puts("  vsync mode | forced on");
                      }
                    }
                  }
                }
                iVar10 = _CFDictionaryGetValue(param_5,iVar9);
                if (iVar10 == 0) {
                  if (local_28 != 0) {
                    _puts(
                         "  failed to extract performance level from CFDictionary | expected \"performance_level\""
                         );
                  }
                }
                else {
                  cVar1 = _CFNumberGetValue(iVar10,3,local_20);
                  if (cVar1 != '\0') {
                    *(int *)(param_2 + 0x2a78) = local_20[0];
                    if (local_28 != 0) {
                      if (local_20[0] == 0) {
                        _puts("  performance cheats | off");
                      }
                      else {
                        _printf("  performance cheats level | %d\n",local_20[0]);
                      }
                    }
                  }
                }
              }
              else if (local_28 != 0) {
                if (iVar10 != local_3c) {
                  _printf("  process id does not match | expected %i | received %i\n",iVar10,
                          local_3c);
                }
                if ((*(uint *)(param_2 + 0x2a64) & local_24) == 0) {
                  _printf("  gl display mask does not match | expected 0x%x | received 0x%x\n",
                          *(uint *)(param_2 + 0x2a64),local_24);
                }
              }
            }
          }
        }
      }
      _CFRelease(iVar2);
    }
    if (iVar3 != 0) {
      _CFRelease(iVar3);
    }
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
    if (iVar9 != 0) {
      _CFRelease(iVar9);
    }
  }
  return;
}

/* FUN_0001e57a @ 0x1e57a (67 bytes) */
int FUN_0001e57a(param_1)
  int param_1;
{
  *(undefined1 *)(param_1 + 0x2a6a) = 0;
  *(undefined1 *)(param_1 + 0x2a6c) = 0;
  *(undefined4 *)(param_1 + 0x2a70) = 0;
  *(undefined4 *)(param_1 + 0x2a74) = 0;
  *(undefined4 *)(param_1 + 0x2a78) = 0;
  *(undefined4 *)(param_1 + 0x2a7c) = 0;
  return;
}

