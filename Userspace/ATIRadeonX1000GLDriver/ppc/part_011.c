#include "decls.h"

/* FUN_00076c60 @ 0x76c60 (480 bytes) */
int FUN_00076c60(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  iVar3 = *(int *)(((unsigned char *)0x0000148c) + param_1);
  piVar6 = *(int **)(((unsigned char *)0x00001168) + param_1);
  if ((*(uint *)(param_1 + 0x44) & 0x100000) == 0) {
                    
                    
    (**(code **)(((unsigned char *)0x000012a4) + param_1))(param_1,piVar6,1);
    return;
  }
  iVar7 = *(int *)(((unsigned char *)0x0000118c) + param_1);
  piVar4 = *(int **)(iVar7 * 4 + *piVar6);
  iVar5 = *piVar4;
  iVar2 = FUN_00076ac0(param_1,iVar5);
  if (((*(char *)(piVar6[1] + iVar7) == '\0') && (iVar2 == *(int *)(iVar5 + 0x38))) &&
     (*(int *)(iVar5 + 4) == piVar6[0x15])) {
    if ((*(byte *)(param_1 + 0x2d) & 4) == 0) {
      bVar1 = iVar5 == 0;
      if ((*(byte *)(param_1 + 0x2d) & 3) != 0) {
        FUN_00076770(param_1,iVar5 + 0x13c,piVar6);
      }
      goto LAB_00076dc0;
    }
    bVar1 = iVar5 == 0;
  }
  else {
    iVar5 = FUN_00076c10(piVar4,iVar2);
    bVar1 = iVar5 == 0;
    if ((bVar1) || (*(char *)(piVar6[1] + *(int *)(((unsigned char *)0x0000118c) + param_1)) != '\0')) {
      FUN_000546d0(param_1,piVar6);
    }
    else {
      *piVar4 = iVar5;
      piVar6[0x15] = *(int *)(iVar5 + 4);
      *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = *(undefined4 *)(iVar5 + 4);
    }
    *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 3;
  }
  FUN_000768e0(param_1,piVar6);
  (**(code **)(((unsigned char *)0x000012a4) + param_1))(param_1,piVar6,0);
LAB_00076dc0:
  (**(code **)(((unsigned char *)0x000012b4) + param_1))(param_1);
  if ((!bVar1) && (iVar3 != iVar5 + 0x13c)) {
                    
                    
    (**(code **)((int)((unsigned char *)0x00001294) + param_1))
              (param_1,iVar5 + 0x13c,*(undefined4 *)(iVar5 + 0x130));
    return;
  }
  return;
}

/* FUN_00076e60 @ 0x76e60 (4 bytes) */
int FUN_00076e60()
{
  return;
}

/* FUN_00076e70 @ 0x76e70 (356 bytes) */
int FUN_00076e70(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = param_2 + 0x13c;
  if ((iVar1 != 0) && (*(int *)(param_2 + 0x150) != 0)) {
    (**(code **)(((unsigned char *)0x000012ac) + param_1))(param_1,iVar1);
  }
  if (*(int *)(param_2 + 8) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 8));
  }
  if (*(int *)(param_2 + 0x10) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x10));
  }
  if (*(int *)(param_2 + 0x3c) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x3c));
  }
  if (*(int *)(param_2 + 0x44) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x44));
  }
  if (*(int *)(param_2 + 0x114) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x114));
  }
  if (*(int *)(param_2 + 0x11c) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x11c));
  }
  if (*(int *)(((unsigned char *)0x000013d8) + param_2) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(((unsigned char *)0x000013d8) + param_2));
  }
  if (*(int *)(param_2 + 0x124) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x124));
  }
  if (iVar1 == *(int *)(((unsigned char *)0x0000148c) + param_1)) {
    *(undefined4 *)(((unsigned char *)0x0000148c) + param_1) = 0;
  }
                    
                    
  (**(code **)(param_1 + 0x18))(param_2);
  return;
}

/* FUN_00076fe0 @ 0x76fe0 (76 bytes) */
int FUN_00076fe0(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(param_1 + 0xc))(0xc);
  *(undefined4 *)(((unsigned char *)0x000011b4) + param_1) = uVar1;
                    
                    
  (**(code **)(((unsigned char *)0x000011b0) + param_1))(param_1);
  return;
}

/* FUN_00077030 @ 0x77030 (84 bytes) */
int FUN_00077030(param_1)
  int param_1;
{
  if (*(int *)(((unsigned char *)0x000011b4) + param_1) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(((unsigned char *)0x000011b4) + param_1));
    *(undefined4 *)(((unsigned char *)0x000011b4) + param_1) = 0;
  }
  return;
}

/* FUN_00077090 @ 0x77090 (600 bytes) */
int FUN_00077090(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint param_3;
{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  
  if (param_3 == 0xffffffff) {
    param_3 = 0;
    uVar6 = *(uint *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x10);
  }
  else {
    uVar6 = param_3 + 1;
  }
  iVar7 = param_3 << 2;
  do {
    puVar8 = *(undefined4 **)(*param_2 + iVar7);
    puVar3 = (undefined4 *)(**(code **)(param_1 + 0xc))(((unsigned char *)0x000013dc));
    *puVar3 = 0;
    puVar3[1] = 0;
    uVar4 = (**(code **)(param_1 + 0xc))(0x800);
    puVar3[2] = uVar4;
    puVar3[3] = 0x200;
    iVar5 = (**(code **)(param_1 + 0x10))(0x16,0x28);
    puVar3[4] = iVar5;
    puVar3[5] = 0x16;
    *(undefined1 *)(iVar5 + 0x10) = 1;
    *(undefined1 *)(puVar3 + 6) = 0;
    *(undefined1 *)((int)puVar3 + 0x19) = 0;
    iVar5 = 8;
    puVar1 = puVar3;
    do {
      *(undefined1 *)((int)puVar1 + 0x1a) = 0;
      puVar1 = (undefined4 *)((int)puVar1 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar5 = 8;
    puVar1 = puVar3;
    do {
      *(undefined1 *)((int)puVar1 + 0x22) = 0;
      puVar1 = (undefined4 *)((int)puVar1 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    *(undefined1 *)((int)puVar3 + 0x2e) = 0;
    *(undefined1 *)((int)puVar3 + 0x2a) = 0;
    *(undefined1 *)((int)puVar3 + 0x2b) = 0;
    *(undefined1 *)(puVar3 + 0xb) = 0;
    iVar5 = 4;
    *(undefined1 *)((int)puVar3 + 0x2d) = 0;
    puVar1 = puVar3;
    do {
      *(undefined1 *)((int)puVar1 + 0x2f) = 0;
      puVar1 = (undefined4 *)((int)puVar1 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar5 = 8;
    piVar2 = param_2;
    do {
      *(undefined1 *)((int)piVar2 + 0x71) = 0;
      piVar2 = (int *)((int)piVar2 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    *(undefined1 *)((int)puVar3 + 0x37) = 0;
    *(undefined1 *)((int)puVar3 + 0x33) = 0;
    *(undefined1 *)(puVar3 + 0xd) = 0;
    *(undefined1 *)((int)puVar3 + 0x35) = 0;
    *(undefined1 *)((int)puVar3 + 0x36) = 0;
    puVar3[0xe] = 0;
    uVar4 = (**(code **)(param_1 + 0x10))(0x20,0x28);
    puVar3[0xf] = uVar4;
    puVar3[0x10] = 0x20;
    uVar4 = (**(code **)(param_1 + 0x10))(0x100,0x28);
    puVar3[0x13] = 0;
    puVar3[0x45] = 0;
    puVar3[0x11] = uVar4;
    puVar3[0x46] = 0;
    puVar3[0x12] = 0x100;
    puVar3[0x47] = 0;
    puVar3[0x48] = 0;
    puVar3[0x49] = 0;
    puVar3[0x4a] = 0;
    puVar3[0x4c] = 0;
    *(undefined1 *)(puVar3 + 0x4d) = 0;
    puVar3[0x4e] = 0;
    if (puVar8 == (undefined4 *)0x0) {
      puVar8 = (undefined4 *)(**(code **)(param_1 + 0xc))(0x88);
      iVar5 = 0x20;
      puVar1 = puVar8;
      do {
        puVar1 = puVar1 + 1;
        *puVar1 = 0;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      puVar8[0x21] = 0;
      *(undefined4 **)(*param_2 + iVar7) = puVar8;
    }
    param_3 = param_3 + 1;
    *puVar8 = puVar3;
    iVar7 = iVar7 + 4;
  } while (param_3 < uVar6);
  return;
}

/* FUN_000772f4 @ 0x772f4 (300 bytes) */
int FUN_000772f4(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  
  iVar5 = *param_2;
  if (iVar5 != 0) {
    if (param_3 == 0) {
      uVar7 = *(uint *)(((unsigned char *)0x0000118c) + param_1);
      uVar3 = uVar7 + 1;
    }
    else {
      uVar7 = 0;
      uVar3 = *(uint *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x10);
    }
    if (uVar7 < uVar3) {
      iVar9 = uVar7 << 2;
      iVar8 = 0;
      while( true ) {
        piVar10 = *(int **)(iVar5 + iVar9);
        if (piVar10 != (int *)0x0) {
          if (*(char *)(*piVar10 + 0x134) == '\0') {
            ((int (*)())FUN_00076e70)(param_1,*piVar10);
            *piVar10 = 0;
          }
          if (param_3 != 0) {
            iVar5 = 0;
            piVar4 = piVar10;
            do {
              piVar1 = piVar4 + 1;
              piVar4 = piVar4 + 1;
              iVar6 = *piVar1;
              while (iVar6 != 0) {
                *piVar4 = *(int *)(iVar6 + 0x138);
                ((int (*)())FUN_00076e70)(param_1,iVar6);
                iVar6 = *piVar4;
              }
              bVar2 = iVar5 != 0x1f;
              iVar5 = iVar5 + 1;
            } while (bVar2);
            (**(code **)(param_1 + 0x18))(piVar10);
            *(undefined4 *)(*param_2 + iVar9) = 0;
          }
        }
        iVar8 = iVar8 + 1;
        iVar9 = iVar9 + 4;
        if (iVar8 == uVar3 - uVar7) break;
        iVar5 = *param_2;
      }
    }
  }
  return;
}

/* FUN_00077430 @ 0x77430 (132 bytes) */
int FUN_00077430(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  if (param_3 != 0) {
    puVar3 = *(undefined4 **)(param_3 + 0x38);
    iVar5 = *(int *)(param_3 + 4);
    iVar1 = *(int *)(((unsigned char *)0x0000137c) + iVar4);
    iVar2 = iVar5 * 0x10 + iVar4;
    *(undefined4 *)(iVar2 + 0x154) = *puVar3;
    *(undefined4 *)(iVar2 + 0x158) = puVar3[1];
    *(undefined4 *)(iVar2 + 0x15c) = puVar3[2];
    *(undefined4 *)(iVar2 + 0x160) = puVar3[3];
    if (iVar1 < iVar5) {
      *(int *)(((unsigned char *)0x0000137c) + iVar4) = iVar5;
    }
  }
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
  *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 1;
  *(undefined1 *)(param_1 + 0x29) = 1;
  return;
}

/* FUN_000774c0 @ 0x774c0 (156 bytes) */
int FUN_000774c0(param_1, param_2)
  code *param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = (*param_1)(0x359a4,param_2);
  if (iVar1 != 0) {
    _memset(iVar1,0,0x359a4);
    *(int *)(iVar1 + 0x34) = iVar1;
    *(undefined4 *)(iVar1 + 0x12458) = param_2;
    *(code **)(iVar1 + 0x12454) = param_1;
    *(undefined4 *)(iVar1 + 0x359a0) = 0xdeaddead;
    _memset(iVar1 + 0x38,0,0x1241c);
    *(undefined4 *)(iVar1 + 0x3c) = param_2;
    *(code **)(iVar1 + 0x38) = param_1;
  }
  return iVar1;
}

/* FUN_00077560 @ 0x77560 (228 bytes) */
int FUN_00077560(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  uint param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  
  iVar2 = param_2 * 4 + param_1;
  if (*(uint *)(iVar2 + 0x10454) < param_3) {
    *(uint *)(iVar2 + 0x10454) = param_3;
  }
  if ((*(uint *)(iVar2 + 0x3348c) & 0x10000) == 0) {
    iVar3 = *(int *)(param_1 + 0x26870);
    *(uint *)(iVar2 + 0x3348c) = *(uint *)(iVar2 + 0x3348c) | 0x10000;
    uVar5 = 0;
    piVar6 = (int *)(param_2 * 0xc + param_1 + 0x450);
    *(int *)(param_1 + 0x26870) = iVar3 + 1;
    *(int *)(0x00024870 + iVar3 * 4 + param_1) = param_2;
    iVar3 = iVar2;
    do {
      uVar4 = 1 << (uVar5 & 0x3f) & *(uint *)(iVar2 + 0x6450);
      if (uVar4 != 0) {
        for (puVar7 = (undefined4 *)*piVar6; puVar7 != (undefined4 *)0x0;
            puVar7 = (undefined4 *)puVar7[4]) {
          ((int (*)())FUN_00077560)(param_1,*puVar7,param_3 + 1,param_4,param_5,iVar3,uVar4);
        }
      }
      bVar1 = uVar5 != 2;
      piVar6 = piVar6 + 1;
      uVar5 = uVar5 + 1;
    } while (bVar1);
  }
  return;
}

/* FUN_00077650 @ 0x77650 (76 bytes) */
int FUN_00077650(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    return;
  }
  if (param_2 != 0) {
    if (iVar2 == param_2) {
      *param_1 = *(int *)(iVar2 + 0x10);
      return;
    }
    do {
      iVar1 = *(int *)(iVar2 + 0x10);
      if (param_2 == iVar1) {
        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(param_2 + 0x10);
        return;
      }
      iVar2 = iVar1;
    } while (iVar1 != 0);
    return;
  }
  return;
}

/* FUN_000776b0 @ 0x776b0 (176 bytes) */
int FUN_000776b0(param_1)
  int param_1;
{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x30c20) = 0;
  if ((**(uint **)(param_1 + 0x34) & 0x40) == 0) {
    *(undefined4 *)(param_1 + 0x30c24) = 0;
    puVar2 = (undefined4 *)(param_1 + 0x30c28);
    iVar3 = 0;
    do {
      bVar1 = iVar3 != 1;
      *puVar2 = 0;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (bVar1);
    puVar2 = (undefined4 *)(param_1 + 0x30c30);
    iVar3 = 6;
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined4 *)(((unsigned char *)0x00030c4c) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x00030c48) + param_1) = 0;
  }
  else {
    puVar2 = (undefined4 *)(param_1 + 0x31450);
    iVar3 = 0xf;
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  puVar2 = (undefined4 *)(param_1 + 0x30ba0);
  iVar3 = 0x20;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* FUN_00077760 @ 0x77760 (72 bytes) */
int FUN_00077760(param_1, param_2, param_3)
  uint param_1;
  uint *param_2;
  int param_3;
{
  uint uVar1;
  undefined4 *puVar2;
  
  uVar1 = *param_2 - 1;
  if (param_1 < uVar1) {
    puVar2 = (undefined4 *)(param_3 + param_1 * 4);
    do {
      param_1 = param_1 + 1;
      *puVar2 = puVar2[1];
      puVar2 = puVar2 + 1;
      uVar1 = *param_2 - 1;
    } while (param_1 < uVar1);
  }
  *param_2 = uVar1;
  return;
}

/* FUN_000777b0 @ 0x777b0 (56 bytes) */
int FUN_000777b0(param_1, param_2)
  uint *param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = *param_1 & 0xf00;
  if ((uVar1 != 0) && (((uVar1 != 0x400 && (uVar1 != 0x500)) || (param_2 == 0)))) {
    return 0;
  }
  return 1;
}

/* FUN_00077800 @ 0x77800 (64 bytes) */
int FUN_00077800(param_1, param_2)
  uint *param_1;
  int param_2;
{
  if ((*param_1 & 0xf00) == 0x300) {
    if (param_2 == 0) {
      return 1;
    }
  }
  else if (((*param_1 & 0xf00) == 0x100) && (param_2 != 0)) {
    return 1;
  }
  return 0;
}

/* FUN_00077850 @ 0x77850 (12 bytes) */
int FUN_00077850(param_1)
  uint *param_1;
{
  return *param_1 >> 0x14 & 0xf;
}

/* FUN_00077860 @ 0x77860 (792 bytes) */
int FUN_00077860(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  
  iVar3 = *(int *)(0x00024870 + param_3 * 4 + param_1) * 0x10;
  puVar8 = (uint *)(iVar3 + param_2);
  if (param_4 == 0) {
    switch(*(uint *)(param_2 + iVar3) >> 8 & 0xf) {
    case 0:
      puVar9 = (uint *)(param_1 + 0x30ba0 + (*puVar8 >> 0xb & 0x1fc));
      break;
    default:
      goto switchD_000778cc_caseD_1;
    case 3:
      puVar9 = (uint *)(param_1 + 0x30c20 + (*puVar8 >> 0xb & 0x1fc));
      break;
    case 4:
      puVar9 = (uint *)(param_1 + 0x30c24 + (*puVar8 >> 0xb & 0x1fc));
      break;
    case 5:
      puVar9 = (uint *)(param_1 + 0x30c28 + (*puVar8 >> 0xb & 0x1fc));
      break;
    case 6:
      puVar9 = (uint *)(param_1 + 0x30c30 + (*puVar8 >> 0xb & 0x1fc));
      break;
    case 7:
      puVar9 = (uint *)(((unsigned char *)0x00030c48) + (*puVar8 >> 0xb & 0x1fc) + param_1);
      break;
    case 8:
      puVar9 = (uint *)(((unsigned char *)0x00030c4c) + (*puVar8 >> 0xb & 0x1fc) + param_1);
    }
  }
  else {
    uVar4 = *(uint *)(param_2 + iVar3);
    uVar2 = uVar4 >> 8 & 0xf;
    if (uVar2 < 6) {
      uVar2 = 1 << uVar2;
      if ((uVar2 & 0x31) != 0) {
        puVar9 = (uint *)(param_1 + 0x30ba0 + (uVar4 >> 0xb & 0x1fc));
        goto LAB_000779d4;
      }
      if ((uVar2 & 2) != 0) {
        puVar9 = (uint *)(param_1 + 0x30c20 + (uVar4 >> 0xb & 0x1fc));
        goto LAB_000779d4;
      }
      if ((uVar2 & 0xc) != 0) {
        puVar9 = (uint *)(param_1 + 0x31450 + (uVar4 >> 0xb & 0x1fc));
        goto LAB_000779d4;
      }
    }
switchD_000778cc_caseD_1:
    puVar9 = (uint *)0x0;
  }
LAB_000779d4:
  iVar3 = ((int (*)())FUN_000777b0)(puVar8,param_4);
  if ((iVar3 == 0) && (iVar3 = ((int (*)())FUN_00077800)(puVar8,param_4), iVar3 == 0)) {
    uVar4 = ((int (*)())FUN_00077850)(puVar8);
    uVar2 = *puVar9;
    *puVar9 = uVar4 | uVar2;
    if ((uVar2 & uVar4 & 0xff) != 0) {
      return 0;
    }
  }
  uVar2 = 0;
  uVar4 = *(uint *)(0x00024870 + param_3 * 4 + param_1);
  piVar7 = (int *)(uVar4 * 0xc + param_1 + 0x450);
  do {
    if ((*(uint *)(uVar4 * 4 + param_1 + 0x6450) & 1 << (uVar2 & 0x3f)) != 0) {
      for (piVar6 = (int *)*piVar7; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[4]) {
        if ((*(uint *)(*piVar6 * 4 + param_1 + 0x3348c) & 0x40000) == 0) {
          return 0;
        }
      }
    }
    bVar1 = uVar2 != 2;
    piVar7 = piVar7 + 1;
    uVar2 = uVar2 + 1;
  } while (bVar1);
  iVar3 = ((int (*)())FUN_000777b0)(puVar8,param_4);
  if ((iVar3 != 0) && (puVar9 = *(uint **)(uVar4 * 4 + param_1 + 0xe450), puVar9 != (uint *)0x0)) {
    uVar2 = ((int (*)())FUN_00077850)(puVar8);
    do {
      uVar10 = *puVar9;
      uVar5 = ((int (*)())FUN_00077850)(param_2 + uVar10 * 0x10);
      if ((((uVar2 & uVar5) != 0) && (uVar10 < uVar4)) &&
         ((*(uint *)(uVar10 * 4 + param_1 + 0x3348c) & 0x40000) == 0)) {
        return 0;
      }
      puVar9 = (uint *)puVar9[4];
    } while (puVar9 != (uint *)0x0);
  }
  return 1;
}

/* FUN_00077ba0 @ 0x77ba0 (140 bytes) */
int FUN_00077ba0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 4;
  uVar4 = 0;
  piVar2 = (int *)(param_3 * 0x10 + param_1 + 0x2d87c);
  do {
    uVar3 = 1 << (uVar4 & 0x3f);
    if ((uVar3 & param_4) != 0) {
      bVar1 = *(byte *)(param_3 + param_1 + 0x3087c);
      if (((int)(char)bVar1 >> (uVar4 & 0x3f) & 1U) == 0) {
        *piVar2 = param_2;
        *(byte *)(param_3 + param_1 + 0x3087c) = (byte)uVar3 | bVar1;
      }
      else if ((param_2 != *piVar2) && (param_5 != 0)) {
        return 6;
      }
    }
    uVar4 = uVar4 + 1;
    piVar2 = piVar2 + 1;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return 0;
    }
  } while( true );
}

/* FUN_00077c40 @ 0x77c40 (124 bytes) */
int FUN_00077c40(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
  undefined4 param_5;
{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  iVar5 = 4;
  piVar3 = (int *)(param_1 + 0x30b8c);
  do {
    uVar2 = 1 << (uVar4 & 0x3f);
    if ((uVar2 & param_3) != 0) {
      bVar1 = *(byte *)(param_1 + 0x30b9c);
      if (((int)(char)bVar1 >> (uVar4 & 0x3f) & 1U) == 0) {
        *piVar3 = param_2;
        *(byte *)(param_1 + 0x30b9c) = (byte)uVar2 | bVar1;
      }
      else if ((param_2 != *piVar3) && (param_4 != 0)) {
        return 6;
      }
    }
    uVar4 = uVar4 + 1;
    piVar3 = piVar3 + 1;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return 0;
    }
  } while( true );
}

/* FUN_00077cd0 @ 0x77cd0 (24 bytes) */
int FUN_00077cd0(param_1)
  uint *param_1;
{
  return (*param_1 & 0xf) == 1;
}

/* FUN_00077cf0 @ 0x77cf0 (20 bytes) */
int FUN_00077cf0(param_1)
  uint *param_1;
{
  return (*param_1 & 0xf00) == 0;
}

/* FUN_00077d10 @ 0x77d10 (120 bytes) */
int FUN_00077d10(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = ((int (*)())FUN_00077850)(param_1 + 0x1286c + param_2 * 0x10);
  for (iVar1 = *(int *)(param_2 * 4 + param_1 + 0xc450); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10))
  {
    uVar2 = uVar2 | *(uint *)(iVar1 + 4);
  }
  return uVar2;
}

/* FUN_00077d90 @ 0x77d90 (1176 bytes) */
int FUN_00077d90(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  uint param_5;
  uint param_6;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  int *piVar16;
  int iVar17;
  int iVar18;
  int local_68 [4];
  uint local_58 [7];
  
  iVar3 = param_3 * 0x10;
  iVar17 = 4;
  puVar4 = (uint *)(iVar3 + param_1 + 0x2d87c);
  uVar12 = 0;
  do {
    if (((param_6 & 1 << (uVar12 & 0x3f)) == 0) ||
       ((((int)*(char *)(param_3 + param_1 + 0x3087c) >> (uVar12 & 0x3f) & 1U) != 0 &&
        (param_5 == *puVar4)))) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    uVar12 = uVar12 + 1;
    iVar17 = iVar17 + -1;
    if (iVar17 == 0) {
      if (!bVar2) {
        return 0;
      }
      break;
    }
    puVar4 = puVar4 + 1;
  } while (!bVar2);
  uVar12 = (uint)*(char *)(param_3 + param_1 + 0x3087c);
  if ((uVar12 & param_4) == 0) {
    return 0;
  }
  uVar10 = 0;
  bVar2 = false;
  iVar17 = 4;
  puVar5 = (undefined4 *)(iVar3 + param_1 + 0x2a87c);
  do {
    uVar13 = 1 << (uVar10 & 0x3f);
    if (((((uVar13 & uVar12) != 0) && (puVar4 = (uint *)*puVar5, puVar4 != (uint *)0x0)) &&
        (param_5 == *puVar4)) && (puVar4[1] == 0)) {
      uVar12 = uVar12 & ~uVar13;
      bVar2 = true;
    }
    uVar10 = uVar10 + 1;
    puVar5 = puVar5 + 1;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  if ((uVar12 != 0) && (bVar2)) {
    iVar17 = 0;
    uVar10 = 0;
    bVar2 = false;
    piVar11 = (int *)(iVar3 + param_1 + 0x2d87c);
    do {
      if ((1 << (uVar10 & 0x3f) & uVar12) != 0) {
        if (bVar2) {
          iVar14 = *piVar11;
          iVar6 = 0;
          iVar18 = iVar17;
          do {
            piVar16 = local_68 + iVar6;
            iVar18 = iVar18 + -1;
            if (iVar18 == 0) {
              if (*piVar16 != iVar14) goto LAB_00077f68;
              break;
            }
            iVar6 = iVar6 + 1;
          } while (*piVar16 != iVar14);
        }
        else {
          iVar14 = *piVar11;
LAB_00077f68:
          local_68[iVar17] = iVar14;
          bVar2 = 0 < iVar17 + 1;
          iVar17 = iVar17 + 1;
        }
      }
      bVar1 = uVar10 != 3;
      piVar11 = piVar11 + 1;
      uVar10 = uVar10 + 1;
    } while (bVar1);
    if (bVar2) {
      iVar14 = 0;
      uVar10 = 0;
      piVar11 = local_68;
      do {
        iVar6 = *piVar11;
        piVar11 = piVar11 + 1;
        if (iVar6 != -1) {
          for (puVar4 = *(uint **)(iVar6 * 4 + param_1 + 0xc450); puVar4 != (uint *)0x0;
              puVar4 = (uint *)puVar4[4]) {
            uVar13 = *puVar4;
            if ((*(uint *)(uVar13 * 4 + param_1 + 0x3348c) & 0x40000) == 0) {
              uVar8 = ((int (*)())FUN_00077850)(uVar13 * 0x10 + param_2);
              uVar9 = 0;
              puVar15 = local_58;
              iVar6 = 4;
              do {
                uVar7 = 1 << (uVar9 & 0x3f);
                if ((uVar8 & uVar7 & ~uVar12) != 0) {
                  if ((uVar7 & uVar10) == 0) {
                    *puVar15 = uVar13;
                    uVar10 = uVar10 | uVar7;
                  }
                  else if (uVar13 < *puVar15) {
                    *puVar15 = uVar13;
                  }
                }
                uVar9 = uVar9 + 1;
                puVar15 = puVar15 + 1;
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
          }
        }
        iVar14 = iVar14 + 1;
      } while (iVar14 != iVar17);
      if (uVar10 != 0) {
        uVar13 = 0;
        puVar4 = local_58;
        iVar17 = 4;
        do {
          uVar8 = 1 << (uVar13 & 0x3f);
          if (((uVar8 & uVar10) != 0) && (param_5 == *puVar4)) {
            uVar10 = uVar10 & ~uVar8;
          }
          uVar13 = uVar13 + 1;
          puVar4 = puVar4 + 1;
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
      }
      goto LAB_000780d4;
    }
  }
  uVar10 = 0;
LAB_000780d4:
  if (((param_4 & uVar12) == 0) && ((uVar10 & param_4) != 0)) {
    return 1;
  }
  uVar12 = param_4 & (uVar10 | uVar12);
  if (uVar12 != 0) {
    uVar10 = 0;
    puVar4 = (uint *)(iVar3 + param_1 + 0x2d87c);
    do {
      uVar13 = 1 << (uVar10 & 0x3f);
      if ((uVar13 & uVar12) != 0) {
        if ((param_6 & uVar13) == 0) {
          puVar15 = *(uint **)(param_5 * 4 + param_1 + 0xc450);
          if (puVar15 != (uint *)0x0) {
            do {
              if (*puVar15 == *puVar4) {
                uVar12 = uVar12 & ~uVar13;
              }
              puVar15 = (uint *)puVar15[4];
            } while (puVar15 != (uint *)0x0);
          }
        }
        else if (param_5 == *puVar4) {
          uVar12 = uVar12 & ~uVar13;
        }
      }
      bVar2 = uVar10 != 3;
      puVar4 = puVar4 + 1;
      uVar10 = uVar10 + 1;
    } while (bVar2);
    if (uVar12 != 0) {
      uVar10 = 0;
      piVar11 = (int *)(iVar3 + param_1 + 0x2d87c);
      do {
        uVar13 = 1 << (uVar10 & 0x3f);
        if ((((uVar13 & uVar12) != 0) && ((uVar13 & param_6) == 0)) &&
           (piVar16 = *(int **)(param_5 * 4 + param_1 + 0xe450), piVar16 != (int *)0x0)) {
          do {
            if (*piVar16 == *piVar11) {
              uVar12 = uVar12 & ~uVar13;
            }
            piVar16 = (int *)piVar16[4];
          } while (piVar16 != (int *)0x0);
        }
        bVar2 = uVar10 != 3;
        piVar11 = piVar11 + 1;
        uVar10 = uVar10 + 1;
      } while (bVar2);
      if (uVar12 != 0) {
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00078250 @ 0x78250 (132 bytes) */
int FUN_00078250(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = ((int (*)())FUN_00077d90)(param_1,param_2,iVar3 + 0x200,param_3,param_4,param_5);
    if (iVar2 == 0) {
      return iVar3 + 0x200;
    }
    bVar1 = iVar3 != 3;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return -1;
}

/* FUN_000782e0 @ 0x782e0 (20 bytes) */
int FUN_000782e0(param_1)
  uint *param_1;
{
  return (*param_1 & 0xf) == 0;
}

/* FUN_00078300 @ 0x78300 (200 bytes) */
int FUN_00078300(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 3);
  switch(cVar1) {
  case '\0':
  case '@':
    return 0;
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x05':
  case '\a':
  case '\b':
  case '\t':
  case '\n':
switchD_00078334_caseD_1:
    return 3;
  case '\x04':
  case '\v':
  case '\f':
  case -0x80:
switchD_00078334_caseD_4:
    return 7;
  case '\x06':
  case '\r':
  case '\x0e':
  case 'A':
  case 'B':
  case 'F':
  case 'G':
  case 'H':
  case 'I':
  case 'K':
  case 'L':
  case 'P':
  case 'Q':
    goto switchD_00078334_caseD_6;
  default:
    if (param_2 != 0) {
      switch(cVar1) {
      case 'C':
        return 4;
      case 'D':
      case 'M':
      case 'N':
      case -0x7f:
        goto switchD_00078334_caseD_4;
      case 'E':
      case 'O':
        return 5;
      default:
        goto switchD_000785b4_caseD_46;
      case 'J':
        goto switchD_00078334_caseD_1;
      }
    }
    if ((7 < (byte)(cVar1 + 0xbdU)) || ((1 << ((int)(char)(cVar1 + -0x43) & 0x3fU) & 0x87U) == 0)) {
switchD_000785b4_caseD_46:
      return 0xffffffff;
    }
switchD_00078334_caseD_6:
    return 1;
  }
}

/* FUN_00078700 @ 0x78700 (84 bytes) */
int FUN_00078700(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = param_2 * 4;
  iVar2 = param_1 + 0x3348c;
  piVar3 = *(int **)(iVar1 + param_1 + 0xc450);
  *(uint *)(iVar2 + iVar1) = *(uint *)(iVar2 + iVar1) | 0x2000;
  if (piVar3 != (int *)0x0) {
    do {
      *(uint *)(iVar2 + *piVar3 * 4) = *(uint *)(iVar2 + *piVar3 * 4) | 0x2000;
      piVar3 = (int *)piVar3[4];
    } while (piVar3 != (int *)0x0);
    return;
  }
  return;
}

/* FUN_00078760 @ 0x78760 (448 bytes) */
int FUN_00078760(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  char *param_4;
  int *param_5;
{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint *puVar7;
  
  puVar7 = (uint *)(param_3 * 0x10 + param_2);
  uVar2 = ((int (*)())FUN_00077d10)(param_1,param_3);
  uVar3 = ((int (*)())FUN_00077850)(puVar7);
  uVar5 = *(uint *)(param_3 * 0x10 + param_2);
  if ((uVar5 & 0xf00) == 0x400) {
    iVar4 = ((int (*)())FUN_00077d90)(param_1,param_2,
                         (char)(DAT_001aa758)[uVar5 >> 8 & 0xf] * 0x100 + (uVar5 >> 0xd & 0x7f),
                         uVar2,param_3,uVar3);
    if (iVar4 == 0) {
      *param_4 = '\0';
      return true;
    }
  }
  else {
    piVar6 = *(int **)(param_3 * 4 + param_1 + 0xa450);
    if (piVar6 != (int *)0x0) {
      cVar1 = *(char *)(*piVar6 * 4 + param_1 + 0x3148d);
      while( true ) {
        if ('\0' < cVar1) {
          ((int (*)())FUN_00078700)(param_1,param_3);
          return false;
        }
        piVar6 = (int *)piVar6[4];
        if (piVar6 == (int *)0x0) break;
        cVar1 = *(char *)(*piVar6 * 4 + param_1 + 0x3148d);
      }
    }
  }
  iVar4 = ((int (*)())FUN_00078250)(param_1,param_2,uVar2,param_3,uVar3);
  *param_5 = iVar4;
  if (iVar4 == -1) {
    ((int (*)())FUN_00078700)(param_1,param_3);
    *param_4 = '\0';
  }
  else {
    uVar5 = *puVar7;
    *param_4 = '\x01' - ((char)(DAT_001aa758)[uVar5 >> 8 & 0xf] * 0x100 + (uVar5 >> 0xd & 0x7f) ==
                        iVar4);
  }
  return iVar4 != -1;
}

/* FUN_00078950 @ 0x78950 (64 bytes) */
int FUN_00078950(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 + 0x3348c;
  iVar1 = *(int *)(param_1 + 0x35494) * 4;
  iVar2 = *(int *)(param_1 + 0x35498) * 4;
  *(uint *)(iVar3 + iVar1) = *(uint *)(iVar3 + iVar1) | 0x100;
  *(uint *)(iVar3 + iVar2) = *(uint *)(iVar3 + iVar2) | 0x100;
  *(int *)(param_1 + 0x3548c) = *(int *)(param_1 + 0x3548c) + 1;
  return;
}

/* FUN_00078990 @ 0x78990 (56 bytes) */
int FUN_00078990(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 * 4 + param_1 + 0x3348c);
  if ((((uVar1 & 0x100) == 0) && ((uVar1 & 0x1000) == 0)) && ((uVar1 & 0x20) != 0)) {
    return 1;
  }
  return 0;
}

/* FUN_000789d0 @ 0x789d0 (56 bytes) */
int FUN_000789d0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 * 4 + param_1 + 0x3348c);
  if ((((uVar1 & 0x100) == 0) && ((uVar1 & 2) != 0)) && ((uVar1 & 0x2000) == 0)) {
    return 1;
  }
  return 0;
}

/* FUN_00078a10 @ 0x78a10 (356 bytes) */
int FUN_00078a10(param_1, param_2, param_3)
  int param_1;
  char *param_2;
  uint *param_3;
{
  bool bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_28 [7];
  
  uVar4 = ((int (*)())FUN_00078300)(param_3,**(uint **)(param_1 + 0x34) >> 6 & 1);
  uVar7 = 0;
  param_2[0] = '\0';
  param_2[1] = '\0';
  param_2[2] = '\0';
  param_2[3] = '\0';
  puVar5 = local_28;
  do {
    param_3 = param_3 + 1;
    if ((uVar4 & 1 << (uVar7 & 0x3f)) == 0) {
      *puVar5 = 0x501;
    }
    else {
      uVar6 = (char)(DAT_001aa760)[*param_3 & 0xf] * 0x100 + (*param_3 >> 5 & 0xff);
      *puVar5 = uVar6;
      if (uVar7 != 0) {
        bVar1 = true;
        puVar3 = local_28;
        uVar8 = uVar7;
        do {
          uVar2 = *puVar3;
          puVar3 = puVar3 + 1;
          if (uVar6 == uVar2) {
            bVar1 = false;
          }
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
        if (!bVar1) goto LAB_00078b54;
      }
      uVar6 = uVar6 >> 8;
      if (uVar6 == 1) {
        param_2[3] = param_2[3] + '\x01';
      }
      else if (uVar6 == 0) {
        *param_2 = *param_2 + '\x01';
      }
      else if (uVar6 == 2) {
        param_2[1] = param_2[1] + '\x01';
      }
      else if (uVar6 == 4) {
        param_2[2] = param_2[2] + '\x01';
      }
    }
LAB_00078b54:
    bVar1 = uVar7 == 2;
    puVar5 = puVar5 + 1;
    uVar7 = uVar7 + 1;
    if (bVar1) {
      return;
    }
  } while( true );
}

/* FUN_00078b80 @ 0x78b80 (560 bytes) */
int FUN_00078b80(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  int local_68 [9];
  
  iVar7 = param_1 + 0x1286c;
  uVar5 = *(uint *)(iVar7 + param_2 * 0x10);
  uVar8 = (uint)(char)(DAT_001aa764)[param_3 >> 8];
  if ((char)(DAT_001aa758)[uVar5 >> 8 & 0xf] * 0x100 + (uVar5 >> 0xd & 0x7f) != param_3) {
    *(uint *)(iVar7 + param_2 * 0x10) =
         (param_3 & 0x7f) << 0xd | (uVar8 & 0xf) << 8 | uVar5 & 0xfff010ff;
    piVar9 = *(int **)(param_2 * 4 + param_1 + 0xa450);
    if (piVar9 != (int *)0x0) {
      do {
        iVar2 = *piVar9;
        uVar12 = 0;
        piVar10 = local_68;
        iVar11 = iVar2 * 0x10 + iVar7;
        uVar5 = *(uint *)(iVar2 * 4 + param_1 + 0x6450);
        local_68[0] = iVar11 + 4;
        local_68[1] = iVar11 + 8;
        local_68[2] = iVar11 + 0xc;
        puVar13 = (undefined4 *)(iVar2 * 0xc + param_1 + 0x450);
        do {
          if (((uVar5 & 1 << (uVar12 & 0x3f)) != 0) &&
             (piVar3 = (int *)*puVar13, piVar3 != (int *)0x0)) {
            bVar1 = false;
            do {
              if (param_2 == *piVar3) {
                bVar1 = true;
              }
              piVar3 = (int *)piVar3[4];
            } while (piVar3 != (int *)0x0);
            if (bVar1) {
              uVar6 = uVar8;
              if ((**(uint **)(param_1 + 0x34) & 0x40) != 0) {
                if (uVar8 == 4) {
                  uVar6 = 3;
                }
                else if (uVar8 == 5) {
                  uVar6 = 1;
                }
                else {
                  uVar6 = 0;
                }
              }
              uVar4 = *(uint *)*piVar10;
              if (((param_3 & 0xff) != (uVar4 >> 5 & 0xff)) || (uVar6 != (uVar4 & 0xf))) {
                *(uint *)*piVar10 = (param_3 & 0xff) << 5 | uVar6 & 0xf | uVar4 & 0xffffe010;
                ((int (*)())FUN_00078a10)(param_1,param_1 + 0x3148c + iVar2 * 4,iVar11);
              }
            }
          }
          bVar1 = uVar12 != 2;
          piVar10 = piVar10 + 1;
          puVar13 = puVar13 + 1;
          uVar12 = uVar12 + 1;
        } while (bVar1);
        piVar9 = (int *)piVar9[4];
      } while (piVar9 != (int *)0x0);
    }
    for (puVar13 = *(undefined4 **)(param_2 * 4 + param_1 + 0xc450); puVar13 != (undefined4 *)0x0;
        puVar13 = (undefined4 *)puVar13[4]) {
      ((int (*)())FUN_00078b80)(param_1,*puVar13,param_3);
    }
  }
  return;
}

/* FUN_00078db0 @ 0x78db0 (68 bytes) */
int FUN_00078db0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_2 + param_1 + 0x3087c);
  iVar2 = (param_2 * 4 + param_3) * 4 + param_1;
  *(undefined4 *)(iVar2 + 0x2d87c) = 0;
  *(undefined4 *)(iVar2 + 0x2a87c) = 0;
  *(byte *)(param_2 + param_1 + 0x3087c) =
       ((byte)(-2 << (param_3 & 0x1f)) | (byte)(0xfffffffe >> 0x20 - (param_3 & 0x1f))) & bVar1;
  return;
}

/* FUN_00078e00 @ 0x78e00 (228 bytes) */
int FUN_00078e00(param_1, param_2)
  undefined4 *param_1;
  uint param_2;
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_1[0x105];
  if (uVar3 < param_2) {
    uVar3 = param_1[0x102];
    uVar2 = param_1[0x104];
    if (uVar3 <= uVar2) {
      if (0xfe < uVar3) {
        return 0;
      }
      uVar1 = (*(code *)*param_1)(0x1000);
      iVar4 = param_1[0x102];
      param_1[uVar3 + 2] = uVar1;
      if (param_1[iVar4 + 2] == 0) {
        return 0;
      }
      uVar2 = param_1[0x104];
      param_1[0x102] = iVar4 + 1;
    }
    uVar3 = 0x1000;
    param_1[0x105] = 0x1000;
    param_1[0x104] = uVar2 + 1;
    param_1[0x103] = param_1[uVar2 + 2];
  }
  iVar4 = param_1[0x103];
  param_1[0x105] = uVar3 - param_2;
  param_1[0x103] = param_2 + iVar4;
  return (param_2 + iVar4) - param_2;
}

/* FUN_00078ef0 @ 0x78ef0 (24 bytes) */
int FUN_00078ef0(param_1)
  uint *param_1;
{
  return (*param_1 & 0xf) == 2;
}

/* FUN_00078f10 @ 0x78f10 (92 bytes) */
int FUN_00078f10(param_1, param_2)
  uint *param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *param_1 >> 0x15 & 1;
  }
  if (param_2 == 0) {
    return *param_1 >> 0x14 & 1;
  }
  if (param_2 == 2) {
    return *param_1 >> 0x16 & 1;
  }
  if (param_2 != 3) {
    return 0;
  }
  return *param_1 >> 0x17 & 1;
}

/* FUN_00078f80 @ 0x78f80 (2340 bytes) */
int FUN_00078f80(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  undefined4 *param_3;
  int param_4;
  undefined4 param_5;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int *piVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined4 *puVar17;
  int *piVar18;
  uint uVar19;
  uint uVar20;
  int *piVar21;
  int iVar22;
  int iVar23;
  int iStack00000024;
  undefined4 uStack00000028;
  int local_78 [4];
  uint local_68 [4];
  uint *local_58;
  
  piVar21 = (int *)(param_2 * 0xc + param_1 + 0x450);
  uVar20 = 0;
  uVar19 = *(uint *)(param_2 * 4 + param_1 + 0x6450);
  puVar17 = param_3;
  iStack00000024 = param_4;
  uStack00000028 = param_5;
  do {
    if ((uVar19 & 1 << (uVar20 & 0x3f)) != 0) {
      for (iVar22 = *piVar21; iVar22 != 0; iVar22 = *(int *)(iVar22 + 0x10)) {
        iVar11 = ((int (*)())FUN_00078ef0)(*puVar17);
        if (iVar11 == 0) {
          uVar16 = 0;
          do {
            if ((1 << (uVar16 & 0x3f) & *(uint *)(iVar22 + 4)) != 0) {
              puVar6 = *(uint **)((((char)(DAT_001aa760)[*(uint *)*puVar17 & 0xf] * 0x100 +
                                   (*(uint *)*puVar17 >> 5 & 0xff)) * 4 + uVar16) * 4 + param_1 +
                                 0x2a87c);
              while( true ) {
                if (puVar6 == (uint *)0x0) {
                  return 6;
                }
                if (param_2 == (*puVar6 & 0xfff)) break;
                puVar6 = (uint *)puVar6[1];
              }
              *puVar6 = *puVar6 | 0x4000;
            }
            bVar1 = uVar16 != 3;
            uVar16 = uVar16 + 1;
          } while (bVar1);
        }
        else {
          uVar16 = 0;
          piVar18 = (int *)(param_1 + 0x30b7c);
          do {
            if ((1 << (uVar16 & 0x3f) & *(uint *)(iVar22 + 4)) != 0) {
              puVar6 = (uint *)*piVar18;
              while( true ) {
                if (puVar6 == (uint *)0x0) {
                  return 6;
                }
                if (param_2 == (*puVar6 & 0xfff)) break;
                puVar6 = (uint *)puVar6[1];
              }
              *puVar6 = *puVar6 | 0x4000;
            }
            bVar1 = uVar16 != 3;
            piVar18 = piVar18 + 1;
            uVar16 = uVar16 + 1;
          } while (bVar1);
        }
      }
    }
    bVar1 = uVar20 != 2;
    piVar21 = piVar21 + 1;
    puVar17 = puVar17 + 1;
    uVar20 = uVar20 + 1;
  } while (bVar1);
  uVar20 = 0;
  piVar21 = (int *)(param_2 * 0xc + param_1 + 0x450);
  local_58 = local_68;
LAB_00079150:
  if ((uVar19 & 1 << (uVar20 & 0x3f)) != 0) {
    puVar6 = (uint *)*param_3;
    iVar22 = *piVar21;
    iVar11 = (char)(DAT_001aa760)[*puVar6 & 0xf] * 0x100 + (*puVar6 >> 5 & 0xff);
    if (iVar22 != 0) {
      bVar1 = false;
LAB_000791c0:
      iVar12 = ((int (*)())FUN_00078ef0)(puVar6);
      if (iVar12 == 0) {
        puVar6 = (uint *)(param_1 + iVar11 * 0x10 + 0x2a87c);
        uVar16 = 0;
LAB_000792a0:
        uVar14 = 1 << (uVar16 & 0x3f);
        if ((uVar14 & *(uint *)(iVar22 + 4)) != 0) {
          puVar7 = (uint *)*puVar6;
          uVar8 = 0;
          if (puVar7 != (uint *)0x0) {
            do {
              if ((*puVar7 & 0x4000) == 0) goto LAB_00079318;
              puVar7 = (uint *)puVar7[1];
              *puVar6 = (uint)puVar7;
            } while (puVar7 != (uint *)0x0);
            goto LAB_00079324;
          }
          goto LAB_00079328;
        }
        goto LAB_00079340;
      }
      puVar6 = (uint *)(param_1 + 0x30b7c);
      uVar16 = 0;
LAB_000791e0:
      uVar14 = 1 << (uVar16 & 0x3f);
      if ((uVar14 & *(uint *)(iVar22 + 4)) != 0) {
        puVar7 = (uint *)*puVar6;
        uVar8 = 0;
        if (puVar7 != (uint *)0x0) {
          do {
            if ((*puVar7 & 0x4000) == 0) goto LAB_00079258;
            puVar7 = (uint *)puVar7[1];
            *puVar6 = (uint)puVar7;
          } while (puVar7 != (uint *)0x0);
          goto LAB_00079264;
        }
        goto LAB_00079268;
      }
      goto LAB_00079280;
    }
    bVar1 = false;
    goto LAB_00079378;
  }
  goto LAB_000798a8;
LAB_00079318:
  while (puVar13 = puVar7, puVar7 = (uint *)puVar13[1], puVar7 != (uint *)0x0) {
    if ((*puVar7 & 0x4000) != 0) {
      puVar13[1] = puVar7[1];
      puVar7 = puVar13;
    }
  }
LAB_00079324:
  uVar8 = *puVar6;
LAB_00079328:
  if (uVar8 == 0) {
    bVar1 = true;
    *(byte *)(iVar11 + param_1 + 0x3087c) = *(byte *)(iVar11 + param_1 + 0x3087c) & ~(byte)uVar14;
  }
LAB_00079340:
  bVar2 = uVar16 == 3;
  puVar6 = puVar6 + 1;
  uVar16 = uVar16 + 1;
  if (bVar2) goto LAB_00079350;
  goto LAB_000792a0;
LAB_00079258:
  while (puVar13 = puVar7, puVar7 = (uint *)puVar13[1], puVar7 != (uint *)0x0) {
    if ((*puVar7 & 0x4000) != 0) {
      puVar13[1] = puVar7[1];
      puVar7 = puVar13;
    }
  }
LAB_00079264:
  uVar8 = *puVar6;
LAB_00079268:
  if (uVar8 == 0) {
    *(byte *)(param_1 + 0x30b9c) = *(byte *)(param_1 + 0x30b9c) & ~(byte)uVar14;
  }
LAB_00079280:
  bVar2 = uVar16 == 3;
  puVar6 = puVar6 + 1;
  uVar16 = uVar16 + 1;
  if (bVar2) goto LAB_00079350;
  goto LAB_000791e0;
LAB_00079350:
  iVar22 = *(int *)(iVar22 + 0x10);
  if (iVar22 == 0) goto LAB_0007936c;
  puVar6 = (uint *)*param_3;
  goto LAB_000791c0;
LAB_0007936c:
  if (*piVar21 == 0) {
LAB_00079378:
    uVar16 = *(uint *)*param_3;
    if ((uVar16 & 0xf) == 1) {
      puVar17 = (undefined4 *)(iVar11 * 0x10 + param_1 + 0x2a87c);
      uVar14 = 0;
      do {
        uVar8 = 1 << (uVar14 & 0x3f);
        if (((1 << (uVar16 >> 0xd & 7) | 1 << (uVar16 >> 0x10 & 7) | 1 << (uVar16 >> 0x13 & 7) |
             1 << (uVar16 >> 0x16 & 7)) & uVar8) != 0) {
          puVar6 = (uint *)*puVar17;
          bVar2 = puVar6 == (uint *)0x0;
          if (!bVar2) {
            uVar5 = *puVar6;
            while (puVar7 = puVar6, uVar5 == param_2) {
              puVar6 = (uint *)puVar6[1];
              bVar2 = puVar6 == (uint *)0x0;
              if (bVar2) goto LAB_00079448;
              uVar5 = *puVar6;
            }
            while (puVar13 = puVar7, puVar7 = (uint *)puVar13[1], puVar7 != (uint *)0x0) {
              if (param_2 == *puVar7) {
                puVar13[1] = puVar7[1];
                puVar7 = puVar13;
              }
            }
          }
LAB_00079448:
          *puVar17 = puVar6;
          if (bVar2) {
            *(byte *)(iVar11 + param_1 + 0x3087c) =
                 *(byte *)(iVar11 + param_1 + 0x3087c) & ~(byte)uVar8;
          }
        }
        bVar2 = uVar14 != 3;
        puVar17 = puVar17 + 1;
        uVar14 = uVar14 + 1;
      } while (bVar2);
    }
  }
  if (bVar1) {
    iVar22 = 0;
    uVar14 = 0;
    bVar1 = false;
    piVar18 = (int *)(iVar11 * 0x10 + param_1 + 0x2d87c);
    uVar16 = (uint)*(char *)(iVar11 + param_1 + 0x3087c);
    do {
      if ((uVar16 & 1 << (uVar14 & 0x3f)) != 0) {
        if (bVar1) {
          iVar12 = *piVar18;
          iVar9 = 0;
          iVar23 = iVar22;
          do {
            piVar4 = local_78 + iVar9;
            iVar23 = iVar23 + -1;
            if (iVar23 == 0) {
              if (*piVar4 != iVar12) goto LAB_00079508;
              break;
            }
            iVar9 = iVar9 + 1;
          } while (*piVar4 != iVar12);
        }
        else {
          iVar12 = *piVar18;
LAB_00079508:
          local_78[iVar22] = iVar12;
          bVar1 = 0 < iVar22 + 1;
          iVar22 = iVar22 + 1;
        }
      }
      bVar2 = uVar14 != 3;
      piVar18 = piVar18 + 1;
      uVar14 = uVar14 + 1;
    } while (bVar2);
    if (bVar1) {
      iVar12 = 0;
      uVar14 = 0;
      piVar18 = local_78;
      do {
        iVar9 = *piVar18;
        piVar18 = piVar18 + 1;
        if (iVar9 != -1) {
          for (puVar6 = *(uint **)(iVar9 * 4 + param_1 + 0xc450); puVar6 != (uint *)0x0;
              puVar6 = (uint *)puVar6[4]) {
            uVar8 = *puVar6;
            if ((*(uint *)(uVar8 * 4 + param_1 + 0x3348c) & 0x40000) == 0) {
              uVar5 = puVar6[1];
              uVar15 = 0;
              puVar7 = local_68;
              iVar9 = 4;
              do {
                uVar10 = 1 << (uVar15 & 0x3f);
                if ((uVar5 & uVar10 & ~uVar16) != 0) {
                  if ((uVar10 & uVar14) == 0) {
                    *puVar7 = uVar8;
                    uVar14 = uVar14 | uVar10;
                  }
                  else if (uVar8 < *puVar7) {
                    *puVar7 = uVar8;
                  }
                }
                uVar15 = uVar15 + 1;
                puVar7 = puVar7 + 1;
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
            }
          }
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 != iVar22);
      if (uVar14 != 0) {
        uVar16 = 0;
        do {
          if ((1 << (uVar16 & 0x3f) & uVar14) != 0) {
            uVar8 = 0;
            puVar6 = local_58;
            do {
              if ((((uVar16 != uVar8) && ((1 << (uVar8 & 0x3f) & uVar14) != 0)) &&
                  (uVar5 = local_58[uVar16], uVar5 < *puVar6)) &&
                 (iVar12 = ((int (*)())FUN_00078f10)(iStack00000024 + uVar5 * 0x10,uVar8), iVar12 != 0)) {
                *puVar6 = uVar5;
              }
              bVar2 = uVar8 != 3;
              puVar6 = puVar6 + 1;
              uVar8 = uVar8 + 1;
            } while (bVar2);
          }
          bVar2 = uVar16 != 3;
          uVar16 = uVar16 + 1;
        } while (bVar2);
        uVar16 = 0;
        puVar6 = local_68;
        do {
          uVar8 = 1 << (uVar16 & 0x3f);
          if (((uVar8 & uVar14) != 0) &&
             (iVar12 = ((int (*)())FUN_00077ba0)(param_1,*puVar6,iVar11,uVar8,1), iVar12 != 0)) {
            return iVar12;
          }
          bVar2 = uVar16 != 3;
          puVar6 = puVar6 + 1;
          uVar16 = uVar16 + 1;
        } while (bVar2);
      }
    }
    cVar3 = *(char *)(iVar11 + param_1 + 0x3087c);
    if (bVar1) {
      iVar12 = 0;
      uVar16 = 0;
      piVar18 = local_78;
      do {
        iVar9 = *piVar18;
        piVar18 = piVar18 + 1;
        if (iVar9 != -1) {
          for (puVar6 = *(uint **)(iVar9 * 4 + param_1 + 0xe450); puVar6 != (uint *)0x0;
              puVar6 = (uint *)puVar6[4]) {
            uVar14 = *puVar6;
            if ((*(uint *)(uVar14 * 4 + param_1 + 0x3348c) & 0x40000) == 0) {
              uVar8 = puVar6[1];
              uVar5 = 0;
              puVar7 = local_68;
              iVar9 = 4;
              do {
                uVar15 = 1 << (uVar5 & 0x3f);
                if ((uVar8 & uVar15 & ~(int)cVar3) != 0) {
                  if ((uVar15 & uVar16) == 0) {
                    *puVar7 = uVar14;
                    uVar16 = uVar16 | uVar15;
                  }
                  else if (uVar14 < *puVar7) {
                    *puVar7 = uVar14;
                  }
                }
                uVar5 = uVar5 + 1;
                puVar7 = puVar7 + 1;
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
            }
          }
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 != iVar22);
      if (uVar16 != 0) {
        uVar14 = 0;
        do {
          if ((1 << (uVar14 & 0x3f) & uVar16) != 0) {
            uVar8 = 0;
            puVar6 = local_68;
            do {
              if (((uVar14 != uVar8) && ((1 << (uVar8 & 0x3f) & uVar16) != 0)) &&
                 ((uVar5 = local_68[uVar14], uVar5 < *puVar6 &&
                  (iVar22 = ((int (*)())FUN_00078f10)(uVar5 * 0x10 + iStack00000024,uVar8), iVar22 != 0)))) {
                *puVar6 = uVar5;
              }
              bVar1 = uVar8 != 3;
              puVar6 = puVar6 + 1;
              uVar8 = uVar8 + 1;
            } while (bVar1);
          }
          bVar1 = uVar14 != 3;
          uVar14 = uVar14 + 1;
        } while (bVar1);
        uVar14 = 0;
        puVar6 = local_68;
        do {
          uVar8 = 1 << (uVar14 & 0x3f);
          if (((uVar8 & uVar16) != 0) &&
             (iVar22 = ((int (*)())FUN_00077ba0)(param_1,*puVar6,iVar11,uVar8,1), iVar22 != 0)) {
            return iVar22;
          }
          bVar1 = uVar14 != 3;
          puVar6 = puVar6 + 1;
          uVar14 = uVar14 + 1;
        } while (bVar1);
      }
    }
  }
LAB_000798a8:
  bVar1 = uVar20 == 2;
  param_3 = param_3 + 1;
  piVar21 = piVar21 + 1;
  uVar20 = uVar20 + 1;
  if (bVar1) {
    return 0;
  }
  goto LAB_00079150;
}

/* FUN_000798f0 @ 0x798f0 (28 bytes) */
int FUN_000798f0(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  *param_1 = (param_2 & 8) << 0x14 |
             (param_2 & 4) << 0x14 |
             (param_2 & 2) << 0x14 | (param_2 & 1) << 0x14 | *param_1 & 0xff0fffff;
  return;
}

/* FUN_00079910 @ 0x79910 (248 bytes) */
int FUN_00079910(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  int *param_2;
  int param_3;
  uint param_4;
  int param_5;
  int param_6;
  undefined4 param_7;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = (int *)*param_2;
  if ((int *)*param_2 == (int *)0x0) {
    piVar2 = (int *)((int (*)())FUN_00078e00)(param_7,0x14);
    *param_2 = (int)piVar2;
    if (piVar2 != (int *)0x0) {
      piVar2[3] = param_6;
      *piVar2 = param_3;
      piVar2[1] = param_4;
      piVar2[4] = 0;
      piVar2[2] = param_5;
      return 0;
    }
  }
  else {
    do {
      piVar3 = piVar2;
      if (param_3 == *piVar3) {
        piVar3[1] = param_4 | piVar3[1];
        return 0;
      }
      piVar2 = (int *)piVar3[4];
    } while ((int *)piVar3[4] != (int *)0x0);
    piVar2 = (int *)((int (*)())FUN_00078e00)(param_7,0x14);
    piVar3[4] = (int)piVar2;
    if (piVar2 != (int *)0x0) {
      *piVar2 = param_3;
      piVar2[1] = param_4;
      piVar2[4] = 0;
      iVar1 = piVar3[4];
      *(int *)(iVar1 + 0xc) = param_6;
      *(int *)(iVar1 + 8) = param_5;
      return 0;
    }
  }
  return 7;
}

/* FUN_00079a20 @ 0x79a20 (92 bytes) */
int FUN_00079a20(param_1, param_2)
  uint *param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(ushort *)param_1 & 7;
  }
  if (param_2 == 0) {
    return *param_1 >> 0xd & 7;
  }
  if (param_2 == 2) {
    return *param_1 >> 0x13 & 7;
  }
  if (param_2 != 3) {
    return 0;
  }
  return *param_1 >> 0x16 & 7;
}

/* FUN_00079a90 @ 0x79a90 (100 bytes) */
int FUN_00079a90(param_1, param_2, param_3)
  uint *param_1;
  int param_2;
  uint param_3;
{
  if (param_2 == 1) {
    *param_1 = (param_3 & 7) << 0x10 | *param_1 & 0xfff8ffff;
    return;
  }
  if (param_2 == 0) {
    *param_1 = (param_3 & 7) << 0xd | *param_1 & 0xffff1fff;
    return;
  }
  if (param_2 == 2) {
    *param_1 = (param_3 & 7) << 0x13 | *param_1 & 0xffc7ffff;
    return;
  }
  if (param_2 != 3) {
    return;
  }
  *param_1 = (param_3 & 7) << 0x16 | *param_1 & 0xfe3fffff;
  return;
}

/* FUN_00079b00 @ 0x79b00 (200 bytes) */
int FUN_00079b00(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_3 != param_2) && (((code **)0x00030c50)[param_3 + param_1] == (code *)0x0)) {
    ((code **)0x00030c50)[param_3 + param_1] = (code *)0x1;
    iVar1 = ((int (*)())FUN_00079910)(param_1,param_1 + 0xe450 + param_2 * 4,param_3,param_4,0,0,param_1 + 0x38);
    if (iVar1 != 0) {
      return iVar1;
    }
    for (puVar2 = *(undefined4 **)(param_3 * 4 + param_1 + 0xc450); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)puVar2[4]) {
      iVar1 = ((int (*)())FUN_00079b00)(param_1,param_2,*puVar2,puVar2[1]);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
  }
  return 0;
}

/* FUN_00079bd0 @ 0x79bd0 (532 bytes) */
int FUN_00079bd0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  undefined4 param_7;
{
  int iVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  
  iVar1 = (param_5 * 4 + param_6) * 4;
  puVar7 = (uint *)(iVar1 + param_2 + 4);
  uVar4 = ((int (*)())FUN_00079a20)(puVar7,param_7);
  if ((1 < uVar4 - 4) && (iVar8 = param_5 + -1, -1 < iVar8)) {
    puVar10 = (uint *)(param_2 + iVar8 * 0x10);
    iVar9 = 0;
    do {
      uVar3 = *puVar7 & 0xf;
      uVar6 = *puVar10 >> 8 & 0xf;
      if (uVar3 == 1) {
        bVar2 = uVar6 == 5;
LAB_00079cd0:
        if (((!bVar2) || ((*puVar10 >> 0xd & 0x7f) != (*puVar7 >> 5 & 0xff))) ||
           (iVar5 = ((int (*)())FUN_00078f10)(puVar10,uVar4), iVar5 == 0)) goto LAB_00079dc0;
        if ((char)*puVar10 == 'A') {
          if (((**(uint **)(param_1 + 0x34) & 0x280) == 0) || (uVar4 != 3)) {
LAB_00079d90:
            ((int (*)())FUN_00079910)(param_1,param_4 + 0x418 + (param_5 * 3 + param_6) * 4,iVar8 - iVar9,
                         1 << (uVar4 & 0x3f),0,0,param_4);
            bVar2 = true;
          }
          else {
            ((int (*)())FUN_00079a90)(puVar7,param_7,5);
            if (param_3 == 0) goto LAB_00079dc8;
LAB_00079d78:
            bVar2 = true;
            *(uint *)(iVar1 + param_3 + 4) = *puVar7;
          }
        }
        else {
          if (((char)*puVar10 != 'D') || ((uVar4 != 0 && (uVar4 != 3)))) goto LAB_00079d90;
          ((int (*)())FUN_00079a90)(puVar7,param_7,5);
          if ((param_3 != 0) && ((**(uint **)(param_1 + 0x34) & 0x200) != 0)) goto LAB_00079d78;
LAB_00079dc8:
          bVar2 = true;
        }
      }
      else {
        if (uVar3 == 0) {
          bVar2 = uVar6 == 0;
          goto LAB_00079cd0;
        }
        if (uVar3 == 3) {
          bVar2 = uVar6 == 4;
          goto LAB_00079cd0;
        }
LAB_00079dc0:
        bVar2 = false;
      }
      if (iVar8 == iVar9) {
        return;
      }
      iVar9 = iVar9 + 1;
      puVar10 = puVar10 + -4;
    } while (!bVar2);
  }
  return;
}

/* FUN_00079e10 @ 0x79e10 (88 bytes) */
int FUN_00079e10(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((((*(uint *)(param_1 + 4) & 0xf) == 0) && ((*(uint *)(param_1 + 8) & 0xf) == 0)) &&
     ((*(uint *)(param_1 + 0xc) & 0xf) == 0)) {
    uVar1 = *(uint *)(param_1 + 4) & 0x1fe0;
    uVar2 = *(uint *)(param_1 + 8) & 0x1fe0;
    if (((uVar1 != uVar2) && (uVar3 = *(uint *)(param_1 + 0xc) & 0x1fe0, uVar2 != uVar3)) &&
       (uVar1 != uVar3)) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00079e70 @ 0x79e70 (488 bytes) */
int FUN_00079e70(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  byte bVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  int *piVar14;
  int iVar15;
  uint uVar16;
  undefined8 uVar17;
  
  iVar10 = param_1 + 0x1286c;
  uVar8 = *(uint *)(param_1 + 0x2a878);
  if (uVar8 != 0) {
    bVar1 = param_2 != 0;
    uVar13 = 0;
    uVar7 = 6;
    bVar3 = false;
    do {
      iVar15 = *(int *)(uVar13 * 4 + param_1 + 0x28878);
      puVar9 = (uint *)(iVar10 + iVar15 * 0x10);
      if ((((bVar1) && ((**(uint **)(param_1 + 0x34) & 0x40) != 0)) &&
          (bVar5 = (char)*puVar9 + 0xbc, bVar5 < 0xb)) &&
         (uVar6 = 1 << ((int)(char)bVar5 & 0x3fU) & 0x601, uVar6 != 0)) {
        uVar17 = ((int (*)())FUN_00079e10)(puVar9,param_2,in_r5,in_r6,in_r7,in_r8,uVar6);
        param_2 = (int)uVar17;
        if ((int)((ulonglong)uVar17 >> 0x20) != 0) {
          bVar3 = true;
          uVar7 = 8;
        }
      }
      piVar11 = *(int **)(iVar15 * 4 + param_1 + 0xa450);
      if (piVar11 != (int *)0x0) {
        uVar6 = uVar13 + 1;
        do {
          if (uVar6 < uVar8) {
            uVar4 = *puVar9;
            iVar15 = *piVar11;
            piVar14 = (int *)(param_1 + uVar6 * 4 + 0x28878);
            uVar16 = uVar6;
            do {
              iVar12 = *piVar14;
              if ((*(uint *)(iVar10 + iVar12 * 0x10) & 0xfef00) == (uVar4 & 0xfef00)) {
                uVar17 = ((int (*)())FUN_00077850)(iVar10 + iVar12 * 0x10);
                param_2 = (int)uVar17;
                bVar2 = true;
                if (((uint)((ulonglong)uVar17 >> 0x20) & piVar11[1]) == 0) goto LAB_00079fc0;
              }
              else {
LAB_00079fc0:
                bVar2 = false;
              }
              uVar16 = uVar16 + 1;
              if (uVar8 == uVar16) {
                if (bVar2) {
LAB_00079ffc:
                  if (iVar12 != iVar15) {
                    bVar3 = true;
                    uVar7 = 9;
                  }
                }
                break;
              }
              if (bVar2) goto LAB_00079ffc;
              piVar14 = piVar14 + 1;
            } while (iVar12 != iVar15);
          }
          piVar11 = (int *)piVar11[4];
        } while (piVar11 != (int *)0x0);
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 < uVar8);
    if (bVar3) {
      return uVar7;
    }
  }
  return 0;
}

/* FUN_0007a060 @ 0x7a060 (16 bytes) */
int FUN_0007a060(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x410) = 0;
  *(undefined4 *)(param_1 + 0x414) = 0;
  return;
}

/* FUN_0007a070 @ 0x7a070 (156 bytes) */
int FUN_0007a070(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x408) != 0) {
    uVar2 = 0;
    iVar3 = param_1;
    do {
      uVar2 = uVar2 + 1;
      (**(code **)(param_1 + 4))(*(undefined4 *)(iVar3 + 8));
      uVar1 = *(uint *)(param_1 + 0x408);
      *(undefined4 *)(iVar3 + 8) = 0;
      iVar3 = iVar3 + 4;
    } while (uVar2 < uVar1);
  }
  *(undefined4 *)(param_1 + 0x40c) = 0;
  *(undefined4 *)(param_1 + 0x408) = 0;
  ((int (*)())FUN_0007a060)(param_1);
  return;
}

/* FUN_0007a110 @ 0x7a110 (100 bytes) */
int FUN_0007a110(param_1)
  int param_1;
{
  if (param_1 != 0) {
    ((int (*)())FUN_0007a070)(param_1 + 0x12454);
    ((int (*)())FUN_0007a070)(param_1 + 0x38);
                    
                    
    (**(code **)(param_1 + 0x12458))(param_1);
    return;
  }
  return;
}

/* FUN_0007a1a0 @ 0x7a1a0 (756 bytes) */
int FUN_0007a1a0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  int iVar16;
  int iVar17;
  
  iVar2 = param_2 * 4;
  puVar15 = (uint *)(param_1 + 0x1286c + param_2 * 0x10);
  uVar14 = 0;
  uVar13 = *(uint *)(iVar2 + param_1 + 0x6450);
  uVar6 = ((int (*)())FUN_00077850)(puVar15);
  uVar4 = 0;
  iVar16 = 4;
  do {
    if ((uVar6 & 1 << (uVar4 & 0x3f)) != 0) {
      uVar14 = uVar14 | 1 << (param_3 >> ((uVar4 & 0xf) << 2) & 0xf);
    }
    uVar4 = uVar4 + 1;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  if (uVar6 != uVar14) {
    uVar8 = 0;
    uVar4 = 0xd;
    do {
      if ((uVar6 & 1 << (uVar8 & 0x3f)) != 0) {
        uVar11 = 0;
        uVar9 = (param_3 >> ((uVar8 & 0xf) << 2) & 0xf) * 3 + 0xd;
        puVar12 = puVar15;
        do {
          if ((uVar13 & 1 << (uVar11 & 0x3f)) != 0) {
            uVar3 = puVar12[1];
            puVar12[1] = (uVar3 & ~(7 << (uVar4 & 0x3f)) |
                         (uVar3 >> (uVar9 & 0x3f) & 7) << (uVar4 & 0x3f)) & ~(7 << (uVar9 & 0x3f)) |
                         (uVar3 >> (uVar4 & 0x3f) & 7) << (uVar9 & 0x3f);
          }
          bVar1 = uVar11 != 2;
          puVar12 = puVar12 + 1;
          uVar11 = uVar11 + 1;
        } while (bVar1);
      }
      bVar1 = uVar8 != 3;
      uVar4 = uVar4 + 3;
      uVar8 = uVar8 + 1;
    } while (bVar1);
    *puVar15 = *puVar15 & 0xff0fffff | uVar14 << 0x14;
    for (piVar7 = *(int **)(iVar2 + param_1 + 0xa450); piVar7 != (int *)0x0;
        piVar7 = (int *)piVar7[4]) {
      iVar16 = *piVar7;
      uVar6 = 0;
      uVar13 = 0;
      iVar17 = 4;
      uVar4 = *(uint *)(iVar16 * 4 + param_1 + 0x6450);
      puVar15 = (uint *)(param_1 + iVar16 * 0x10 + 0x12870);
      do {
        if ((piVar7[1] & 1 << (uVar13 & 0x3f)) != 0) {
          uVar6 = uVar6 | 1 << (param_3 >> ((uVar13 & 0xf) << 2) & 0xf);
        }
        uVar13 = uVar13 + 1;
        iVar17 = iVar17 + -1;
      } while (iVar17 != 0);
      piVar7[1] = uVar6;
      uVar6 = 0;
      puVar10 = (undefined4 *)(iVar16 * 0xc + param_1 + 0x450);
      do {
        if (((uVar4 & 1 << (uVar6 & 0x3f)) != 0) && (piVar5 = (int *)*puVar10, piVar5 != (int *)0x0)
           ) {
          bVar1 = false;
          do {
            if (param_2 == *piVar5) {
              uVar13 = 0;
              uVar14 = 0;
              iVar16 = 4;
              do {
                if ((piVar5[1] & 1 << (uVar14 & 0x3f)) != 0) {
                  uVar13 = uVar13 | 1 << (param_3 >> ((uVar14 & 0xf) << 2) & 0xf);
                }
                uVar14 = uVar14 + 1;
                iVar16 = iVar16 + -1;
              } while (iVar16 != 0);
              piVar5[1] = uVar13;
              bVar1 = true;
            }
            piVar5 = (int *)piVar5[4];
          } while (piVar5 != (int *)0x0);
          if (bVar1) {
            *puVar15 = (param_3 >> (*puVar15 >> 0x1b & 0xc) & 3) << 0x1d | *puVar15 & 0x9fffffff;
          }
        }
        bVar1 = uVar6 != 2;
        puVar15 = puVar15 + 1;
        puVar10 = puVar10 + 1;
        uVar6 = uVar6 + 1;
      } while (bVar1);
    }
    for (puVar10 = *(undefined4 **)(iVar2 + param_1 + 0xc450); puVar10 != (undefined4 *)0x0;
        puVar10 = (undefined4 *)puVar10[4]) {
      ((int (*)())FUN_0007a1a0)(param_1,*puVar10,param_3);
    }
  }
  return;
}

/* FUN_0007a4a0 @ 0x7a4a0 (1544 bytes) */
int FUN_0007a4a0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
  undefined1 *param_6;
  uint *param_7;
{
  bool bVar1;
  char cVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  int *piVar17;
  undefined *puVar18;
  
  *param_6 = 0;
  *param_7 = 0xffffffff;
  puVar16 = (uint *)(param_5 * 0x10 + param_2);
  iVar5 = ((int (*)())FUN_000777b0)(puVar16,param_3);
  if (iVar5 == 0) {
    iVar5 = ((int (*)())FUN_00077800)(puVar16,param_3);
    if (iVar5 != 0) {
      puVar18 = ((unsigned char *)0x00003210);
      uVar6 = ((int (*)())FUN_00077d10)(param_1,param_5);
      uVar7 = ((int (*)())FUN_00077850)(puVar16);
      uVar15 = 0;
      uVar14 = 0;
      iVar5 = param_5 * 4 + param_1;
      uVar11 = (uint)*(char *)(param_1 + 0x30b9c);
LAB_0007a7b0:
      if (((uVar6 & uVar11 & 1 << (uVar14 & 0x3f)) == 0) || (4 < uVar15)) goto LAB_0007aa50;
      if (uVar15 != 4) {
        if ((1 << (uVar15 & 0x3f) & ~(uVar6 | uVar11)) == 0) {
          iVar4 = 5 - uVar15;
          do {
            uVar15 = uVar15 + 1;
            iVar4 = iVar4 + -1;
            if (iVar4 == 0) goto LAB_0007aa50;
            if (uVar15 == 4) goto LAB_0007a7e8;
          } while ((1 << (uVar15 & 0x3f) & ~(uVar6 | uVar11)) == 0);
        }
        uVar13 = uVar15 << (uVar14 << 2 & 0x3c);
        uVar15 = uVar15 + 1;
        puVar18 = (undefined *)((uint)puVar18 & ~(0xf << (uVar14 << 2 & 0x3c)) | uVar13);
        goto LAB_0007aa50;
      }
LAB_0007a7e8:
      uVar15 = 0;
      uVar14 = 0;
      iVar4 = 4;
      do {
        if ((uVar6 & 1 << (uVar14 & 0x3f)) != 0) {
          uVar15 = uVar15 | 1 << ((uint)puVar18 >> ((uVar14 & 0xf) << 2) & 0xf);
        }
        uVar14 = uVar14 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      uVar14 = 0;
      uVar6 = 0;
      iVar4 = 4;
      do {
        if ((uVar7 & 1 << (uVar6 & 0x3f)) != 0) {
          uVar14 = uVar14 | 1 << ((uint)puVar18 >> ((uVar6 & 0xf) << 2) & 0xf);
        }
        uVar6 = uVar6 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      uVar11 = uVar11 & uVar15;
      if (uVar11 == 0) {
LAB_0007aa5c:
        puVar3 = puVar18;
      }
      else {
        puVar12 = (undefined4 *)(param_1 + 0x30b7c);
        uVar6 = 0;
        iVar4 = 4;
        do {
          uVar7 = 1 << (uVar6 & 0x3f);
          if (((((uVar7 & uVar11) != 0) && (piVar17 = (int *)*puVar12, piVar17 != (int *)0x0)) &&
              (param_5 == *piVar17)) && (piVar17[1] == 0)) {
            uVar11 = uVar11 & ~uVar7;
          }
          uVar6 = uVar6 + 1;
          puVar12 = puVar12 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if (uVar11 == 0) goto LAB_0007aa5c;
        piVar17 = (int *)(param_1 + 0x30b8c);
        uVar6 = 0;
        do {
          uVar7 = 1 << (uVar6 & 0x3f);
          if ((uVar7 & uVar11) != 0) {
            if ((uVar7 & uVar14) == 0) {
              piVar8 = *(int **)(iVar5 + 0xc450);
              if (piVar8 != (int *)0x0) {
                do {
                  if (((uVar7 & piVar8[1]) == 0) || (bVar1 = true, *piVar8 != *piVar17)) {
                    bVar1 = false;
                  }
                  piVar8 = (int *)piVar8[4];
                  if (piVar8 == (int *)0x0) {
                    if (!bVar1) goto LAB_0007a948;
                    break;
                  }
                } while (!bVar1);
                goto LAB_0007a944;
              }
            }
            else if (param_5 == *piVar17) {
LAB_0007a944:
              uVar11 = uVar11 & ~uVar7;
            }
          }
LAB_0007a948:
          bVar1 = uVar6 != 3;
          piVar17 = piVar17 + 1;
          uVar6 = uVar6 + 1;
        } while (bVar1);
        if (uVar11 == 0) goto LAB_0007aa5c;
        piVar17 = (int *)(param_1 + 0x30b8c);
        uVar6 = 0;
        do {
          uVar7 = 1 << (uVar6 & 0x3f);
          if ((((uVar7 & uVar11) != 0) && ((uVar7 & uVar14) == 0)) &&
             (piVar8 = *(int **)(iVar5 + 0xe450), piVar8 != (int *)0x0)) {
            do {
              if (((uVar7 & piVar8[1]) == 0) || (bVar1 = true, *piVar8 != *piVar17)) {
                bVar1 = false;
              }
              piVar8 = (int *)piVar8[4];
              if (piVar8 == (int *)0x0) {
                if (!bVar1) goto LAB_0007a9d4;
                break;
              }
            } while (!bVar1);
            uVar11 = uVar11 & ~uVar7;
          }
LAB_0007a9d4:
          bVar1 = uVar6 != 3;
          piVar17 = piVar17 + 1;
          uVar6 = uVar6 + 1;
        } while (bVar1);
        puVar3 = (undefined *)0xffffffff;
        if (uVar11 == 0) goto LAB_0007aa5c;
      }
      *param_7 = (uint)puVar3;
      if (puVar3 != (undefined *)0xffffffff) {
        if (puVar3 == ((unsigned char *)0x00003210)) goto LAB_0007a680;
        goto LAB_0007aa80;
      }
      goto LAB_0007aa90;
    }
LAB_0007a680:
    uVar9 = 1;
  }
  else {
    if (((*(uint *)(param_5 * 4 + param_1 + 0x3348c) & 0x1000) != 0) &&
       (iVar5 = ((int (*)())FUN_00078760)(param_1,param_2,param_5,param_6,param_7), iVar5 != 0)) {
      return 1;
    }
    uVar6 = ((int (*)())FUN_00077850)(puVar16);
    for (piVar17 = *(int **)(param_5 * 4 + param_1 + 0xe450); piVar17 != (int *)0x0;
        piVar17 = (int *)piVar17[4]) {
      iVar5 = *piVar17;
      uVar7 = ((int (*)())FUN_00077850)(param_2 + iVar5 * 0x10);
      if (((uVar6 & uVar7) != 0) &&
         (iVar5 = iVar5 * 4 + param_1, (*(uint *)(iVar5 + 0x3348c) & 0x40000) != 0)) {
        for (piVar8 = *(int **)(iVar5 + 0xa450); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[4]) {
          if (((param_5 != *piVar8) && ((uVar6 & uVar7 & piVar8[1]) != 0)) &&
             ((*(uint *)(*piVar8 * 4 + param_1 + 0x3348c) & 0x40000) == 0)) goto LAB_0007aa90;
        }
      }
    }
    uVar9 = ((int (*)())FUN_00077d10)(param_1,param_5);
    iVar5 = ((int (*)())FUN_00077cf0)(puVar16);
    if (iVar5 == 0) {
      uVar6 = *puVar16;
LAB_0007a634:
      cVar2 = (DAT_001aa758)[uVar6 >> 8 & 0xf];
      uVar10 = ((int (*)())FUN_00077850)(puVar16);
      iVar5 = ((int (*)())FUN_00077d90)(param_1,param_2,cVar2 * 0x100 + (uVar6 >> 0xd & 0x7f),uVar9,param_5,
                           uVar10);
      if (iVar5 == 0) goto LAB_0007a680;
    }
    else {
      uVar6 = *puVar16;
      if ((uVar6 >> 0xd & 0x7f) < param_4) goto LAB_0007a634;
    }
    iVar5 = ((int (*)())FUN_00077cf0)(puVar16);
    if (iVar5 == 0) {
      if (((*puVar16 & 0xf00) != 0x400) || (bVar1 = true, param_3 == 0)) {
        bVar1 = false;
      }
      if (bVar1) {
        uVar10 = ((int (*)())FUN_00077850)(puVar16);
        uVar6 = ((int (*)())FUN_00078250)(param_1,param_2,uVar9,param_5,uVar10);
        *param_7 = uVar6;
      }
    }
    else {
      uVar10 = ((int (*)())FUN_00077850)(puVar16);
      if (param_4 != 0) {
        uVar6 = 0;
        do {
          iVar5 = ((int (*)())FUN_00077d90)(param_1,param_2,uVar6,uVar9,param_5,uVar10);
          if (iVar5 == 0) goto LAB_0007a6e4;
          uVar6 = uVar6 + 1;
        } while (param_4 != uVar6);
      }
      uVar6 = 0xffffffff;
LAB_0007a6e4:
      *param_7 = uVar6;
    }
    if ((int)*param_7 < 0) {
LAB_0007aa90:
      uVar9 = 0;
    }
    else {
LAB_0007aa80:
      uVar9 = 1;
      *param_6 = 1;
    }
  }
  return uVar9;
LAB_0007aa50:
  bVar1 = uVar14 == 3;
  uVar14 = uVar14 + 1;
  if (bVar1) goto LAB_0007aa5c;
  goto LAB_0007a7b0;
}

/* FUN_0007aae0 @ 0x7aae0 (1460 bytes) */
int FUN_0007aae0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  uint param_3;
  undefined1 *param_4;
  undefined4 *param_5;
  int param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 a2;
  int a4;
  byte *a5;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  char *pcVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint *puVar17;
  int *piVar18;
  uint uVar19;
  uint uStack00000020;
  undefined1 *puStack00000024;
  undefined4 *puStack00000028;
  byte local_78;
  undefined1 local_77 [3];
  undefined4 local_74;
  undefined4 local_70 [2];
  int local_68;
  int local_64;
  uint local_60;
  int local_5c;
  undefined4 *local_58;
  
  *param_4 = 0;
  local_78 = 0;
  local_74 = 0;
  if (param_2 == 0) {
    iVar12 = 0;
  }
  else {
    iVar12 = 0;
    pcVar13 = (char *)(param_1 + 0x3087c);
    iVar3 = param_2;
    do {
      if (*pcVar13 == '\0') {
        iVar12 = iVar12 + 1;
      }
      pcVar13 = pcVar13 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  iVar3 = *(int *)(param_1 + 0x35490);
  uStack00000020 = param_3;
  puStack00000024 = param_4;
  puStack00000028 = param_5;
  if (iVar3 == 2) {
    local_68 = *(int *)(param_1 + 0x35494);
    *(undefined4 *)(param_1 + 0x35490) = 3;
    iVar3 = ((int (*)())FUN_00078760)(param_1,param_6,local_68,param_4,param_5);
    if (iVar3 != 0) {
      ((int (*)())FUN_00078950)(param_1);
      return local_68;
    }
  }
  else if (iVar3 == 3) {
    *(undefined4 *)(param_1 + 0x35490) = 0;
  }
  else if (iVar3 == 1) {
    local_68 = *(int *)(param_1 + 0x35498);
    local_77[0] = 0;
    iVar3 = ((int (*)())FUN_0007a4a0)(param_1,param_6,param_8,param_2,local_68,local_77,local_70);
    *(undefined4 *)(param_1 + 0x35490) = 3;
    if (iVar3 != 0) {
      *puStack00000024 = local_77[0];
      *puStack00000028 = local_70[0];
      ((int (*)())FUN_00078950)(param_1);
      return local_68;
    }
  }
  local_68 = 0;
  if (*(int *)(param_1 + 0x28874) != 0) {
    local_5c = param_1 + 0x20000;
    local_58 = &local_74;
    iVar3 = -1;
    piVar18 = (int *)(param_1 + 0x26874);
    local_60 = 0;
    local_64 = 0;
    uVar15 = 0;
    uVar11 = 0;
    do {
      iVar4 = 0;
      local_78 = 0;
      a4 = *piVar18;
      do {
        bVar1 = iVar4 != 2;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      a5 = &local_78;
      a2 = param_8;
      iVar4 = param_2;
      iVar7 = ((int (*)())FUN_0007a4a0)(param_1,param_6,param_8,param_2,a4,a5,local_58);
      if (iVar7 != 0) {
        iVar7 = 100;
        if (uStack00000020 <= (uint)piVar18[-0x1001]) {
          iVar7 = 0;
        }
        iVar16 = *piVar18;
        iVar10 = iVar16 * 4 + param_1;
        iVar7 = *(int *)(iVar10 + 0x10454) * 2 + iVar7;
        if (*(int *)(iVar10 + 0x8450) != 0) {
          iVar7 = iVar7 + 0x20;
        }
        uVar14 = *(uint *)(iVar10 + 0x6450);
        iVar10 = 0;
        uVar19 = 0;
        puVar5 = (uint *)(param_6 + iVar16 * 0x10);
        do {
          puVar5 = puVar5 + 1;
          if (((uVar14 & 1 << (uVar19 & 0x3f)) != 0) && (iVar8 = ((int (*)())FUN_000782e0)(puVar5), iVar8 != 0))
          {
            bVar1 = true;
            iVar8 = 4;
            puVar6 = (undefined4 *)
                     (((char)(DAT_001aa760)[*puVar5 & 0xf] * 0x100 + (*puVar5 >> 5 & 0xff)) * 0x10
                      + param_1 + 0x2a87c);
            do {
              piVar9 = (int *)*puVar6;
              if ((piVar9 != (int *)0x0) && ((iVar16 != *piVar9 || (piVar9[1] != 0)))) {
                bVar1 = false;
              }
              iVar8 = iVar8 + -1;
              if (iVar8 == 0) {
                if (bVar1) {
                  iVar10 = iVar10 + 1;
                }
                break;
              }
              puVar6 = puVar6 + 1;
            } while (bVar1);
          }
          bVar1 = uVar19 != 2;
          uVar19 = uVar19 + 1;
        } while (bVar1);
        iVar7 = iVar10 * (param_2 - iVar12) * 2 + iVar7;
        if ((iVar3 < iVar7) || (uVar15 == 0)) {
          local_60 = (uint)local_78;
          local_64 = 1;
          uVar11 = local_74;
          iVar3 = iVar7;
          local_68 = iVar16;
        }
      }
      uVar15 = uVar15 + 1;
      piVar18 = piVar18 + 1;
    } while (uVar15 < *(uint *)(param_1 + 0x28874));
    if (local_64 != 0) {
      *puStack00000024 = (char)local_60;
      *puStack00000028 = uVar11;
      puVar5 = (uint *)(param_6 + local_68 * 0x10);
      bVar2 = (byte)*puVar5 >> 6;
      uVar15 = bVar2 & 1;
      iVar3 = (*(code *)(PTR_FUN_001e9150)[uVar15])
                        (param_1,local_68,a2,iVar4,a4,a5,&PTR_FUN_001e9150);
      if (iVar3 == 0) {
        return local_68;
      }
      if (*(int *)(param_1 + 0x28874) == 0) {
        return local_68;
      }
      iVar3 = param_1 + 0x3148c;
      uVar14 = 0;
      piVar18 = (int *)(local_5c + 0x6874);
      pcVar13 = (char *)(iVar3 + local_68 * 4);
      do {
        iVar7 = *piVar18;
        puVar17 = (uint *)(param_6 + iVar7 * 0x10);
        uVar19 = (byte)((byte)*puVar17 >> 6) & 1;
        iVar12 = (*(code *)(PTR_FUN_001e9150)[uVar19])
                           (param_1,iVar7,a2,iVar4,a4,a5,&PTR_FUN_001e9150);
        if ((iVar12 != 0) && (uVar15 != uVar19)) {
          iVar12 = iVar3 + iVar7 * 4;
          if ((*puVar5 & 0x40) == 0) {
            puVar17 = puVar5;
          }
          if (((((int)*pcVar13 + (int)*(char *)(iVar3 + iVar7 * 4) < 3) &&
               ((int)pcVar13[1] + (int)*(char *)(iVar12 + 1) < 2)) &&
              ((int)pcVar13[2] + (int)*(char *)(iVar12 + 2) < 2)) &&
             (((int)pcVar13[3] + (int)*(char *)(iVar12 + 3) < 2 && ((*puVar17 & 0xf00) != 0x400))))
          {
            if ((bVar2 & 1) == 0) {
              *(int *)(param_1 + 0x35494) = iVar7;
              *(int *)(param_1 + 0x35498) = local_68;
            }
            else {
              *(int *)(param_1 + 0x35498) = iVar7;
              *(int *)(param_1 + 0x35494) = local_68;
            }
            if (*(int *)(param_1 + 0x35494) == local_68) {
              iVar3 = ((int (*)())FUN_00078760)(param_1,param_6,local_68,local_77,local_70);
              if (iVar3 != 0) {
                *(undefined4 *)(param_1 + 0x35490) = 1;
                *puStack00000024 = local_77[0];
                *puStack00000028 = local_70[0];
                return local_68;
              }
              *(undefined4 *)(param_1 + 0x35490) = 0;
              return local_68;
            }
            *(undefined4 *)(param_1 + 0x35490) = 2;
            return local_68;
          }
        }
        uVar14 = uVar14 + 1;
        piVar18 = piVar18 + 1;
        if (*(uint *)(param_1 + 0x28874) <= uVar14) {
          return local_68;
        }
      } while( true );
    }
  }
  return -1;
}

/* FUN_0007b0d0 @ 0x7b0d0 (5660 bytes) */
int FUN_0007b0d0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  code *param_3;
  code *param_4;
  int *param_5;
  code *param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  bool bVar1;
  unsigned char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int *piVar9;
  byte bVar10;
  byte bVar11;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 uVar12;
  int iVar13;
  int *piVar14;
  code *pcVar15;
  uint *puVar16;
  uint uVar17;
  undefined4 uVar18;
  uint *puVar19;
  int iVar20;
  code *pcVar21;
  uint uVar22;
  uint *puVar23;
  int *piVar24;
  char cVar25;
  undefined4 uVar26;
  int iVar27;
  int iVar28;
  uint uVar29;
  bool bVar31;
  int iVar30;
  int *piVar32;
  uint uVar33;
  uint uVar34;
  uint *puVar35;
  int *piVar36;
  code *pcVar37;
  int iVar38;
  unsigned char *pcVar39;
  undefined4 *puVar40;
  unsigned char *pcVar41;
  undefined8 uVar42;
  char local_b8 [4];
  undefined4 local_b4;
  char local_b0;
  char local_af;
  char local_ae;
  char local_ad;
  char local_ac;
  char local_ab;
  char local_aa;
  char local_a9;
  undefined1 local_a8 [12];
  uint local_9c [5];
  uint local_88;
  int local_84;
  int local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  code *local_6c;
  uint local_68;
  uint local_64;
  unsigned char *local_60;
  
  iVar20 = param_1 + 0x38;
  local_64 = 0xe;
  puVar19 = *(uint **)(param_1 + 0x34);
  uVar33 = *puVar19;
  uVar4 = uVar33 >> 6 & 1;
  if (uVar4 == 0) {
    local_64 = 0xc;
  }
  iVar28 = *(int *)(param_1 + 0x2286c);
  pcVar21 = (code *)(param_1 + 0x1286c);
  if (((uVar4 != 0) && ((uVar33 & 0x400) != 0)) && (iVar28 != 0)) {
    piVar24 = (int *)(param_1 + 0xc450);
    iVar27 = 0;
    iVar30 = 0;
    do {
      pcVar39 = pcVar21 + iVar27 * 0x10;
      param_3 = pcVar39;
      ((int (*)())FUN_00078a10)(param_1,iVar30 + param_1 + 0x3148c,pcVar39);
      if (((byte)pcVar39[3] & 0x40) == 0) {
        iVar38 = param_1 + 0x3348c;
        uVar22 = *(uint *)(iVar30 + iVar38);
        *(uint *)(iVar30 + iVar38) = uVar22 | 0x10;
        uVar4 = ((int (*)())FUN_00078300)(pcVar39,1);
        if ((uVar4 & 4) == 0) {
          *(uint *)(iVar30 + iVar38) = uVar22 | 0x30;
        }
      }
      else {
        iVar38 = param_1 + 0x3348c;
        uVar22 = *(uint *)(iVar30 + iVar38);
        *(uint *)(iVar30 + iVar38) = uVar22 | 1;
        uVar4 = ((int (*)())FUN_00077850)(pcVar39);
        if ((((((uVar4 - 1 & uVar4) == 0) &&
              (iVar13 = ((byte)pcVar39[3] & 0xffffffbf) * 0x14,
              *(int *)(&DAT_001aa5f0 + iVar13) != 0)) &&
             (((DAT_001aa600)[iVar13] == '\0' || ((uVar33 >> 0xd & 1) != 0)))) &&
            (((*(uint *)(pcVar21 + iVar27 * 0x10) & 0xf00) != 0x200 &&
             ((*(uint *)(pcVar21 + iVar27 * 0x10) & 0xf00) != 0x300)))) &&
           ((*(int *)(&DAT_001aa5f4 + iVar13) == 1 ||
            ((*(int *)(&DAT_001aa5f4 + iVar13) == 2 &&
             (param_6 = pcVar39 + 4,
             (*(uint *)(param_6 + *(int *)(&DAT_001aa5f8 + iVar13) * 4) & 0x60001fff) ==
             (*(uint *)(param_6 + *(int *)(&DAT_001aa5fc + iVar13) * 4) & 0x60001fff))))))) {
          *(uint *)(iVar30 + iVar38) = uVar22 | 3;
          piVar14 = (int *)*piVar24;
          *(uint *)(iVar30 + iVar38) = uVar22 | 0x1003;
          for (; piVar14 != (int *)0x0; piVar14 = (int *)piVar14[4]) {
            *(uint *)(iVar38 + *piVar14 * 4) = *(uint *)(iVar38 + *piVar14 * 4) | 0x1000;
          }
        }
      }
      iVar27 = iVar27 + 1;
      iVar30 = iVar30 + 4;
      piVar24 = piVar24 + 1;
    } while (iVar28 != iVar27);
    uVar33 = *puVar19;
  }
  pcVar15 = (code *)(uVar33 >> 6 & 1);
  pcVar39 = pcVar21;
  if ((uVar33 & 2) != 0) {
    for (; iVar28 != 0; iVar28 = iVar28 + -1) {
      if (pcVar39[3] == (code *)0x4) {
        pcVar39[3] = (code *)0x80;
      }
      else if ((pcVar15 != (code *)0x0) && (pcVar39[3] == (code *)0xb)) {
        pcVar39[3] = (code *)0x81;
      }
      pcVar39 = pcVar39 + 0x10;
    }
  }
  pcVar39 = *(code **)(param_1 + 0x10450);
  if (*(code **)(param_1 + 0x10450) != (code *)0x0) {
    do {
      pcVar41 = pcVar39 + 0x10;
      pcVar37 = pcVar39;
      pcVar39 = *(code **)pcVar41;
    } while (*(code **)pcVar41 != (code *)0x0);
    while( true ) {
      pcVar39 = pcVar37;
      param_3 = (code *)0x0;
      ((int (*)())FUN_00077560)(param_1,*(undefined4 *)pcVar39,0,param_4,param_5,param_6,pcVar15);
      pcVar15 = *(code **)(param_1 + 0x10450);
      if ((pcVar15 == (code *)0x0) || (pcVar39 == pcVar15)) break;
      pcVar37 = pcVar15;
      for (pcVar41 = *(code **)(pcVar15 + 0x10); pcVar39 != pcVar41;
          pcVar41 = *(code **)(pcVar41 + 0x10)) {
        if (pcVar41 == (code *)0x0) goto LAB_0007b378;
        pcVar37 = pcVar41;
      }
    }
  }
LAB_0007b378:
  local_88 = *(uint *)(param_1 + 0x26870);
  bVar1 = local_88 != 0;
  if (bVar1) {
    pcVar39 = 0x00024870 + param_1;
    uVar4 = 0;
    do {
      iVar28 = *(int *)pcVar39;
      for (piVar24 = *(int **)(iVar28 * 4 + iVar20 + 0xa418); piVar24 != (int *)0x0;
          piVar24 = (int *)piVar24[4]) {
        if ((*(uint *)(*piVar24 * 4 + param_1 + 0x3348c) & 0x10000) == 0) {
          ((int (*)())FUN_00077650)(param_1 + 0xa450 + iVar28 * 4,piVar24);
          iVar28 = *(int *)pcVar39;
        }
      }
      for (piVar24 = *(int **)(iVar28 * 4 + iVar20 + 0xc418); piVar24 != (int *)0x0;
          piVar24 = (int *)piVar24[4]) {
        if ((*(uint *)(*piVar24 * 4 + param_1 + 0x3348c) & 0x10000) == 0) {
          ((int (*)())FUN_00077650)(param_1 + 0xc450 + iVar28 * 4,piVar24);
          iVar28 = *(int *)pcVar39;
        }
      }
      for (piVar24 = *(int **)(iVar28 * 4 + iVar20 + 0xe418); piVar24 != (int *)0x0;
          piVar24 = (int *)piVar24[4]) {
        if ((*(uint *)(*piVar24 * 4 + param_1 + 0x3348c) & 0x10000) == 0) {
          ((int (*)())FUN_00077650)(param_1 + 0xe450 + *(int *)pcVar39 * 4,piVar24);
        }
      }
      uVar4 = uVar4 + 1;
      pcVar39 = pcVar39 + 4;
    } while (uVar4 < *(uint *)(param_1 + 0x26870));
  }
  if ((((**(uint **)(param_1 + 0x34) & 0x40) != 0) && (bVar1)) &&
     (iVar28 = local_88 - 1, iVar28 != 0)) {
    iVar27 = 0;
    pcVar39 = pcVar21 + iVar28 * 0x10;
    puVar23 = (uint *)(iVar28 * 4 + param_1 + 0x6450);
    do {
      pcVar15 = (code *)(iVar28 - iVar27);
      local_6c = pcVar15;
      if ((puVar23[0xb40f] & 0x10000) != 0) {
        uVar4 = *(uint *)pcVar39;
        local_68 = *puVar23;
        if ((uVar4 & 0xf00) == 0x500) {
          pcVar15 = (code *)(uVar4 >> 0xd & 0x7f);
          pcVar41 = pcVar15 + (char)(DAT_001aa758)[uVar4 >> 8 & 0xf] * 0x100;
          if ((uVar4 & 0x100000) != 0) {
            param_3 = (code *)0x0;
            ((int (*)())FUN_00078db0)(param_1,pcVar41,0);
            uVar4 = *(uint *)pcVar39;
          }
          if ((uVar4 & 0x200000) != 0) {
            param_3 = (code *)((int)&MACH_HEADER.magic + 1);
            ((int (*)())FUN_00078db0)(param_1,pcVar41,1);
            uVar4 = *(uint *)pcVar39;
          }
          if ((uVar4 & 0x400000) != 0) {
            param_3 = (code *)((int)&MACH_HEADER.magic + 2);
            ((int (*)())FUN_00078db0)(param_1,pcVar41,2);
            uVar4 = *(uint *)pcVar39;
          }
          if ((uVar4 & 0x800000) != 0) {
            param_3 = (code *)((int)&MACH_HEADER.magic + 3);
            ((int (*)())FUN_00078db0)(param_1,pcVar41,3);
          }
        }
        uVar4 = 0;
        pcVar41 = pcVar39;
        do {
          pcVar41 = pcVar41 + 4;
          if ((local_68 & 1 << (uVar4 & 0x3f)) != 0) {
            param_6 = *(code **)pcVar41;
            param_5 = (int *)((uint)param_6 & 0xf);
            if (param_5 == (int *)((int)&MACH_HEADER.magic + 1U)) {
              uVar34 = 0;
              uVar33 = (uint)param_6 >> 0xd;
              pcVar15 = (code *)(1 << ((uint)param_6 >> 0x10 & 7));
              uVar22 = 1 << ((uint)param_6 >> 0x16 & 7) | 1 << ((uint)param_6 >> 0x13 & 7) |
                       (uint)pcVar15;
              iVar30 = DAT_001aa761 * 0x100 + ((uint)param_6 >> 5 & 0xff);
              local_60 = (code *)(iVar30 + param_1 + 0x30870);
              puVar40 = (undefined4 *)(iVar30 * 0x10 + param_1 + 0x2a87c);
              do {
                uVar29 = 1 << (uVar34 & 0x3f);
                if (((uVar22 | 1 << (uVar33 & 7)) & uVar29) != 0) {
                  uVar26 = *puVar40;
                  puVar8 = (undefined4 *)((int (*)())FUN_00078e00)(param_1 + 0x12454,8);
                  if (puVar8 != (undefined4 *)0x0) {
                    puVar8[1] = uVar26;
                    *puVar8 = local_6c;
                    *puVar40 = puVar8;
                    puVar40[0xc00] = 0xffffffff;
                    local_60[0xc] = (code *)((byte)uVar29 | (byte)local_60[0xc]);
                    pcVar15 = local_60;
                  }
                }
                bVar31 = uVar34 != 3;
                puVar40 = puVar40 + 1;
                uVar34 = uVar34 + 1;
              } while (bVar31);
            }
          }
          bVar31 = uVar4 != 2;
          uVar4 = uVar4 + 1;
        } while (bVar31);
      }
      iVar27 = iVar27 + 1;
      pcVar39 = pcVar39 + -0x10;
      puVar23 = puVar23 + -1;
    } while (iVar27 != iVar28);
  }
  pcVar39 = (code *)0x0;
  ((int (*)())FUN_000776b0)(param_1);
  pcVar41 = 0x00024870 + param_1;
  uVar26 = extraout_r4;
  while (pcVar39 < *(code **)(param_1 + 0x26870)) {
    param_4 = (code *)(**(uint **)(param_1 + 0x34) >> 6 & 1);
    param_3 = pcVar39;
    uVar42 = ((int (*)())FUN_00077860)(param_1,pcVar21,pcVar39,param_4);
    uVar26 = (undefined4)uVar42;
    if ((int)((ulonglong)uVar42 >> 0x20) == 0) {
      pcVar39 = pcVar39 + 1;
      pcVar41 = pcVar41 + 4;
    }
    else {
      iVar27 = *(int *)pcVar41;
      param_3 = 0x00024870 + param_1;
      pcVar15 = (code *)(*(int *)(param_1 + 0x28874) + 1);
      iVar28 = *(int *)(param_1 + 0x28874) * 4 + param_1;
      *(code **)(param_1 + 0x28874) = pcVar15;
      *(int *)(iVar28 + 0x26874) = iVar27;
      *(undefined4 *)(iVar28 + 0x22870) = 0;
      iVar28 = iVar27 * 4 + param_1;
      ((int (*)())FUN_00077760)(pcVar39,param_1 + 0x26870,param_3);
      *(uint *)(iVar28 + 0x3348c) = *(uint *)(iVar28 + 0x3348c) & 0xfffeffff | 0x20000;
      uVar26 = extraout_r4_00;
    }
  }
  while (*(uint *)(param_1 + 0x2a878) < local_88) {
    if (*(int *)(param_1 + 0x28874) == 0) {
      return 2;
    }
    param_6 = pcVar21;
    iVar28 = ((int (*)())FUN_0007aae0)(param_1,local_64,9,local_b8,&local_b4,pcVar21,*puVar19,*puVar19 >> 6 & 1);
    if (iVar28 < 0) {
      uVar4 = **(uint **)(param_1 + 0x34);
      bVar31 = true;
      while ((uVar4 = uVar4 >> 6 & 1, uVar4 != 0 && (local_64 < 0x20))) {
        if (local_64 == 0x12) {
          local_64 = 0x18;
        }
        else if (local_64 == 0x18) {
          local_64 = 0x20;
        }
        else if (local_64 == 0xe) {
          local_64 = 0x12;
        }
        param_6 = pcVar21;
        iVar28 = ((int (*)())FUN_0007aae0)(param_1,local_64,9,local_b8,&local_b4,pcVar21,*puVar19,uVar4);
        bVar31 = iVar28 < 0;
        if (!bVar31) goto LAB_0007b894;
        uVar4 = **(uint **)(param_1 + 0x34);
      }
      if (bVar31) {
        return 3;
      }
    }
LAB_0007b894:
    iVar27 = 0;
    param_3 = (code *)local_a8;
    pcVar39 = pcVar21 + iVar28 * 0x10;
    puVar23 = (uint *)(param_1 + 0x1286c + iVar28 * 0x10);
    do {
      pcVar39 = pcVar39 + 4;
      bVar31 = iVar27 != 8;
      *(code **)(param_3 + iVar27) = pcVar39;
      iVar27 = iVar27 + 4;
    } while (bVar31);
    if (local_b8[0] == '\0') {
      puVar35 = *(uint **)(param_1 + 0x34);
    }
    else {
      puVar35 = *(uint **)(param_1 + 0x34);
      uVar4 = *puVar35 >> 6 & 1;
      iVar27 = ((int (*)())FUN_000777b0)(puVar23,uVar4);
      if (iVar27 == 0) {
        iVar27 = ((int (*)())FUN_00077800)(puVar23,uVar4);
        if (iVar27 != 0) {
          ((int (*)())FUN_0007a1a0)(param_1,iVar28,local_b4);
          puVar35 = *(uint **)(param_1 + 0x34);
        }
      }
      else {
        ((int (*)())FUN_00078b80)(param_1,iVar28,local_b4);
        puVar35 = *(uint **)(param_1 + 0x34);
      }
    }
    param_5 = (int *)(*puVar35 >> 6 & 1);
    param_4 = pcVar21;
    iVar27 = ((int (*)())FUN_00078f80)(param_1,iVar28,param_3,pcVar21,param_5);
    if (iVar27 != 0) {
      return iVar27;
    }
    iVar27 = ((int (*)())FUN_000777b0)(puVar23,**(uint **)(param_1 + 0x34) >> 6 & 1);
    if (iVar27 == 0) {
      iVar27 = iVar28 * 4;
      iVar30 = ((int (*)())FUN_00077800)(puVar23,*puVar19 >> 6 & 1);
      if (iVar30 != 0) {
        param_3 = (code *)((int (*)())FUN_00077850)(puVar23);
        param_4 = (code *)((int)&MACH_HEADER.magic + 1);
        iVar30 = ((int (*)())FUN_00077c40)(param_1,iVar28,param_3,1,param_5);
        if (iVar30 != 0) {
          return iVar30;
        }
        for (puVar40 = *(undefined4 **)(iVar27 + iVar20 + 0xc418); puVar40 != (undefined4 *)0x0;
            puVar40 = (undefined4 *)puVar40[4]) {
          param_3 = (code *)puVar40[1];
          param_4 = (code *)((int)&MACH_HEADER.magic + 1);
          iVar30 = ((int (*)())FUN_00077c40)(param_1,*puVar40,param_3,1,param_5);
          if (iVar30 != 0) {
            return iVar30;
          }
        }
        for (puVar40 = *(undefined4 **)(iVar27 + iVar20 + 0xe418); puVar40 != (undefined4 *)0x0;
            puVar40 = (undefined4 *)puVar40[4]) {
          param_3 = (code *)puVar40[1];
          param_4 = (code *)((int)&MACH_HEADER.magic + 1);
          ((int (*)())FUN_00077c40)(param_1,*puVar40,param_3,1,param_5);
        }
        piVar14 = (int *)(param_1 + 0x30b7c);
        uVar4 = 0;
        piVar24 = *(int **)(iVar27 + iVar20 + 0xa418);
        do {
          if (piVar24 != (int *)0x0) {
            bVar31 = false;
            piVar36 = piVar24;
            do {
              if ((1 << (uVar4 & 0x3f) & piVar36[1]) != 0) {
                if (bVar31) {
                  piVar9 = (int *)*piVar14;
                  do {
                    piVar32 = piVar9;
                    if (*piVar32 == *piVar36) goto LAB_0007bdf0;
                    piVar9 = (int *)piVar32[1];
                  } while ((int *)piVar32[1] != (int *)0x0);
                  piVar9 = (int *)((int (*)())FUN_00078e00)(param_1 + 0x12454,8);
                  piVar32[1] = (int)piVar9;
                  if (piVar9 == (int *)0x0) {
                    return 7;
                  }
                  iVar27 = *piVar36;
                  piVar9[1] = 0;
                  *piVar9 = iVar27;
                }
                else {
                  if (*piVar14 != 0) {
                    return 6;
                  }
                  piVar9 = (int *)((int (*)())FUN_00078e00)(param_1 + 0x12454,8);
                  *piVar14 = (int)piVar9;
                  if (piVar9 == (int *)0x0) {
                    return 7;
                  }
                  *piVar9 = *piVar36;
                  *(undefined4 *)(*piVar14 + 4) = 0;
                  bVar31 = true;
                }
              }
LAB_0007bdf0:
              piVar36 = (int *)piVar36[4];
            } while (piVar36 != (int *)0x0);
          }
          bVar31 = uVar4 != 3;
          piVar14 = piVar14 + 1;
          uVar4 = uVar4 + 1;
        } while (bVar31);
      }
    }
    else {
      param_3 = (code *)((char)(DAT_001aa758)[*puVar23 >> 8 & 0xf] * 0x100 +
                        (*puVar23 >> 0xd & 0x7f));
      uVar26 = ((int (*)())FUN_00077850)(puVar23);
      param_5 = (int *)((int)&MACH_HEADER.magic + 1);
      iVar27 = ((int (*)())FUN_00077ba0)(param_1,iVar28,param_3,uVar26,1);
      if (iVar27 != 0) {
        return iVar27;
      }
      iVar27 = iVar28 * 4;
      uVar4 = 0;
      for (puVar35 = *(uint **)(iVar27 + iVar20 + 0xc418); puVar35 != (uint *)0x0;
          puVar35 = (uint *)puVar35[4]) {
        uVar33 = *puVar35;
        if ((*(uint *)(uVar33 * 4 + param_1 + 0x3348c) & 0x40000) == 0) {
          uVar34 = ((int (*)())FUN_00077850)(param_1 + 0x1286c + uVar33 * 0x10);
          uVar22 = 0;
          puVar16 = (uint *)(local_a8 + 0xc);
          iVar30 = 4;
          do {
            uVar29 = 1 << (uVar22 & 0x3f);
            if ((uVar34 & uVar29) != 0) {
              if ((uVar29 & uVar4) == 0) {
                *puVar16 = uVar33;
                uVar4 = uVar4 | uVar29;
              }
              else if (uVar33 < *puVar16) {
                *puVar16 = uVar33;
              }
            }
            uVar22 = uVar22 + 1;
            puVar16 = puVar16 + 1;
            iVar30 = iVar30 + -1;
          } while (iVar30 != 0);
        }
      }
      uVar33 = 0;
      puVar40 = (undefined4 *)(local_a8 + 0xc);
      do {
        param_4 = (code *)(1 << (uVar33 & 0x3f));
        if ((uVar4 & (uint)param_4) != 0) {
          param_5 = (int *)0x0;
          param_3 = (code *)((char)(DAT_001aa758)[*puVar23 >> 8 & 0xf] * 0x100 +
                            (*puVar23 >> 0xd & 0x7f));
          iVar30 = ((int (*)())FUN_00077ba0)(param_1,*puVar40,param_3,param_4,0);
          if (iVar30 != 0) {
            return iVar30;
          }
        }
        bVar31 = uVar33 != 3;
        puVar40 = puVar40 + 1;
        uVar33 = uVar33 + 1;
      } while (bVar31);
      for (puVar40 = *(undefined4 **)(iVar27 + iVar20 + 0xe418); puVar40 != (undefined4 *)0x0;
          puVar40 = (undefined4 *)puVar40[4]) {
        param_5 = (int *)0x0;
        param_4 = (code *)puVar40[1];
        param_3 = (code *)((char)(DAT_001aa758)[*puVar23 >> 8 & 0xf] * 0x100 +
                          (*puVar23 >> 0xd & 0x7f));
        ((int (*)())FUN_00077ba0)(param_1,*puVar40,param_3,param_4,0);
      }
      uVar4 = 0;
      piVar24 = *(int **)(iVar27 + iVar20 + 0xa418);
      piVar14 = (int *)(((char)(DAT_001aa758)[*puVar23 >> 8 & 0xf] * 0x100 +
                        (*puVar23 >> 0xd & 0x7f)) * 0x10 + param_1 + 0x2a87c);
      do {
        if (piVar24 != (int *)0x0) {
          bVar31 = false;
          piVar36 = piVar24;
          do {
            if ((1 << (uVar4 & 0x3f) & piVar36[1]) != 0) {
              if (bVar31) {
                piVar9 = (int *)*piVar14;
                do {
                  piVar32 = piVar9;
                  if (*piVar32 == *piVar36) goto LAB_0007bc50;
                  piVar9 = (int *)piVar32[1];
                } while ((int *)piVar32[1] != (int *)0x0);
                piVar9 = (int *)((int (*)())FUN_00078e00)(param_1 + 0x12454,8);
                piVar32[1] = (int)piVar9;
                if (piVar9 == (int *)0x0) {
                  return 7;
                }
                iVar27 = *piVar36;
                piVar9[1] = 0;
                *piVar9 = iVar27;
              }
              else {
                if (*piVar14 != 0) {
                  return 6;
                }
                piVar9 = (int *)((int (*)())FUN_00078e00)(param_1 + 0x12454,8);
                *piVar14 = (int)piVar9;
                if (piVar9 == (int *)0x0) {
                  return 7;
                }
                *piVar9 = *piVar36;
                *(undefined4 *)(*piVar14 + 4) = 0;
                bVar31 = true;
              }
            }
LAB_0007bc50:
            piVar36 = (int *)piVar36[4];
          } while (piVar36 != (int *)0x0);
        }
        bVar31 = uVar4 != 3;
        piVar14 = piVar14 + 1;
        uVar4 = uVar4 + 1;
      } while (bVar31);
    }
    iVar27 = iVar28 * 4 + param_1;
    iVar38 = *(int *)(param_1 + 0x2a878);
    iVar30 = *(int *)(param_1 + 0x28874);
    pcVar15 = (code *)(iVar27 + 0x30000);
    uVar4 = *(uint *)(iVar27 + 0x3348c);
    *(int *)(param_1 + 0x2a878) = iVar38 + 1;
    *(int *)(iVar38 * 4 + param_1 + 0x28878) = iVar28;
    *(uint *)(iVar27 + 0x3348c) = uVar4 & 0xfffdffff | 0x40000;
    pcVar39 = (code *)0x0;
    if (iVar30 != 0) {
      param_5 = (int *)(param_1 + 0x26874);
      param_3 = (code *)0x0;
      iVar27 = 1;
      iVar30 = 0x22874;
      do {
        if ((iVar28 == *param_5) && (param_3 < (code *)(*(int *)(param_1 + 0x28874) + -1))) {
          puVar40 = (undefined4 *)(param_1 + iVar30);
          param_4 = (code *)((int)param_3 * 4);
          param_6 = param_3;
          do {
            iVar38 = *(int *)(param_1 + 0x28874);
            param_6 = param_6 + 1;
            pcVar15 = param_4 + iVar27 * -4;
            uVar26 = puVar40[0x1001];
            *(undefined4 *)((int)puVar40 + (int)pcVar15) = *puVar40;
            puVar40[0x1000] = uVar26;
            puVar40 = puVar40 + 1;
          } while (param_6 < (code *)(iVar38 + -1));
        }
        pcVar39 = *(code **)(param_1 + 0x28874);
        param_3 = param_3 + 1;
        iVar27 = iVar27 + 1;
        iVar30 = iVar30 + 4;
        param_5 = param_5 + 1;
      } while (param_3 < pcVar39);
    }
    *(code **)(param_1 + 0x28874) = pcVar39 + -1;
    if ((*(int *)(param_1 + 0x35490) != 3) && (pcVar39 + -1 != (code *)0x0)) {
      pcVar15 = (code *)(param_1 + 0x22870);
      uVar4 = 0;
      do {
        if (*(int *)pcVar15 != 0) {
          *(int *)pcVar15 = *(int *)pcVar15 + -1;
        }
        uVar4 = uVar4 + 1;
        pcVar15 = pcVar15 + 4;
      } while (uVar4 < *(uint *)(param_1 + 0x28874));
    }
    pcVar39 = (code *)0x0;
    ((int (*)())FUN_000776b0)(param_1);
    pcVar41 = 0x00024870 + param_1;
    uVar26 = extraout_r4_01;
    while (pcVar39 < *(code **)(param_1 + 0x26870)) {
      param_4 = (code *)(**(uint **)(param_1 + 0x34) >> 6 & 1);
      param_3 = pcVar39;
      uVar42 = ((int (*)())FUN_00077860)(param_1,pcVar21,pcVar39,param_4);
      uVar26 = (undefined4)uVar42;
      if ((int)((ulonglong)uVar42 >> 0x20) == 0) {
        pcVar39 = pcVar39 + 1;
        pcVar41 = pcVar41 + 4;
      }
      else {
        iVar27 = *(int *)pcVar41;
        param_3 = 0x00024870 + param_1;
        pcVar15 = (code *)(*(int *)(param_1 + 0x28874) + 1);
        iVar28 = *(int *)(param_1 + 0x28874) * 4 + param_1;
        *(code **)(param_1 + 0x28874) = pcVar15;
        *(int *)(iVar28 + 0x26874) = iVar27;
        *(undefined4 *)(iVar28 + 0x22870) = 9;
        iVar28 = iVar27 * 4 + param_1;
        ((int (*)())FUN_00077760)(pcVar39,param_1 + 0x26870,param_3);
        *(uint *)(iVar28 + 0x3348c) = *(uint *)(iVar28 + 0x3348c) & 0xfffeffff | 0x20000;
        uVar26 = extraout_r4_02;
      }
    }
    if ((*puVar19 & 0x10) != 0) {
      uVar42 = ((int (*)())FUN_00079e70)(param_1,0);
      iVar28 = (int)((ulonglong)uVar42 >> 0x20);
      uVar26 = (undefined4)uVar42;
      if (iVar28 != 0) {
        return iVar28;
      }
    }
  }
  uVar4 = **(uint **)(param_1 + 0x34);
  if (bVar1) {
    uVar33 = 0;
    pcVar39 = pcVar21;
    do {
      uVar42 = ((int (*)())FUN_00079e10)(pcVar39,uVar26,param_3,param_4,param_5,param_6,pcVar15);
      uVar26 = (undefined4)uVar42;
      if ((int)((ulonglong)uVar42 >> 0x20) != 0) {
        if (pcVar39[3] == (code *)0x4) {
          pcVar39[3] = (code *)0x80;
        }
        else if (((uVar4 >> 6 & 1) != 0) && (pcVar39[3] == (code *)0xb)) {
          pcVar39[3] = (code *)0x81;
        }
      }
      uVar33 = uVar33 + 1;
      pcVar39 = pcVar39 + 0x10;
    } while (local_88 != uVar33);
  }
  if (((*puVar19 & 0x20) != 0) && (iVar28 = ((int (*)())FUN_00079e70)(param_1,1), iVar28 != 0)) {
    return iVar28;
  }
  iVar28 = *(int *)(param_1 + 0x34);
  if (*(int *)(param_1 + 0x2a878) == 0) {
    uVar22 = 0;
    uVar4 = 0;
    uVar33 = 0;
    local_70 = 0;
    local_74 = 0;
    local_78 = 0;
    local_80 = 0;
  }
  else {
    uVar4 = 0;
    local_7c = 0;
    local_70 = 0;
    uVar33 = 0;
    uVar22 = 0;
    local_74 = 0;
    local_78 = 0;
    local_80 = 0;
    iVar27 = param_1 + 0x30000;
    do {
      iVar30 = *(int *)(iVar27 + -0x7788) * 4;
      puVar19 = (uint *)(uVar22 * 0x10 + *(int *)(iVar28 + 0x18));
      pcVar39 = pcVar21 + *(int *)(iVar27 + -0x7788) * 0x10;
      if ((*(uint *)(iVar30 + param_1 + 0x3348c) & 0x100) == 0) {
LAB_0007c4b0:
        bVar11 = 0;
        uVar34 = *(uint *)(iVar30 + iVar20 + 0x6418);
        uVar29 = 0;
        cVar25 = *(char *)(iVar30 + iVar20 + 0x841b);
        pcVar15 = pcVar39;
        do {
          pcVar15 = pcVar15 + 4;
          if ((uVar34 & 1 << (uVar29 & 0x3f)) != 0) {
            bVar10 = ((int (*)())FUN_00077cd0)(pcVar15);
            bVar11 = bVar10 | bVar11;
          }
          bVar1 = uVar29 != 2;
          uVar29 = uVar29 + 1;
        } while (bVar1);
      }
      else {
        local_84 = *(int *)(iVar27 + -0x7784);
        pcVar15 = pcVar21 + local_84 * 0x10;
        pcVar41 = pcVar39;
        if (((byte)pcVar39[3] & 0x40) == 0) {
          pcVar15 = pcVar39;
          pcVar41 = pcVar21 + local_84 * 0x10;
        }
        cVar2 = pcVar41[3];
        uVar34 = *(uint *)pcVar41;
        *(undefined4 *)(pcVar15 + 0xc) = 0;
        pcVar37 = pcVar15 + 0xc;
        uVar34 = uVar34 >> 0x14 & 0xf;
        ((int (*)())FUN_00078a10)(param_1,&local_b0,pcVar15);
        ((int (*)())FUN_00078a10)(param_1,&local_ac,pcVar41);
        if ((((2 < (int)local_b0 + (int)local_ac) || (1 < (int)local_af + (int)local_ab)) ||
            (1 < (int)local_ae + (int)local_aa)) ||
           ((1 < (int)local_ad + (int)local_a9 || ((*(uint *)pcVar15 & 0xf00) == 0x400))))
        goto LAB_0007c4b0;
        uVar5 = *(uint *)(pcVar15 + 0xc);
        uVar29 = (*(uint *)pcVar41 & 0x6000) << 6;
        *(uint *)(pcVar15 + 0xc) = uVar29 | uVar5 & 0xffe7ffff;
        uVar17 = ((byte)pcVar41[3] & 0xf) << 0x15;
        *(uint *)(pcVar15 + 0xc) = uVar17 | uVar29 | uVar5 & 0xfe07ffff;
        uVar7 = (byte)pcVar41[3] >> 2 & 4;
        *(uint *)(pcVar15 + 0xc) = uVar7 | uVar17 | uVar29 | uVar5 & 0xfe07fffb;
        if (uVar34 == 2) {
          *(uint *)(pcVar15 + 0xc) = uVar7 | uVar17 | uVar29 | uVar5 & 0xe607fffb | 0x8000000;
        }
        else if (uVar34 < 3) {
          if (uVar34 == 1) {
            *(uint *)pcVar37 = uVar7 | uVar17 | uVar29 | uVar5 & 0xe607fffb;
          }
        }
        else if (uVar34 == 4) {
          *(uint *)(pcVar15 + 0xc) = uVar7 | uVar17 | uVar29 | uVar5 & 0xe607fffb | 0x10000000;
        }
        else if (uVar34 == 8) {
          *(uint *)pcVar37 = uVar7 | uVar17 | uVar29 | uVar5 & 0xe607fffb | 0x18000000;
        }
        iVar38 = ((byte)cVar2 & 0x1f) * 0x14;
        uVar34 = *(uint *)(&DAT_001aa5f8 + iVar38);
        if (uVar34 < 3) {
          uVar6 = *(uint *)pcVar37;
          uVar7 = *(uint *)(pcVar41 + (uVar34 + 1) * 4) & 3;
          *(uint *)pcVar37 = uVar7 | uVar6 & 0xfffffffc;
          uVar17 = *(uint *)(pcVar41 + (uVar34 + 1) * 4) & 0x10;
          *(uint *)pcVar37 = uVar17 | uVar7 | uVar6 & 0xffffffec;
          uVar5 = *(uint *)(pcVar41 + (uVar34 + 1) * 4) & 0x1fe0;
          *(uint *)pcVar37 = uVar5 | uVar17 | uVar7 | uVar6 & 0xffffe00c;
          uVar3 = *(uint *)(pcVar41 + (uVar34 + 1) * 4) & 0x60000000;
          *(uint *)pcVar37 = uVar3 | uVar5 | uVar17 | uVar7 | uVar6 & 0x9fffe00c;
          uVar29 = *(uint *)(pcVar41 + (uVar34 + 1) * 4) >> 3 & 0x2000000;
          *(uint *)pcVar37 = uVar29 | uVar3 | uVar5 | uVar17 | uVar7 | uVar6 & 0x9dffe00c;
          *(uint *)pcVar37 =
               *(uint *)(pcVar41 + (uVar34 + 1) * 4) >> 9 & 0xe000 |
               uVar29 | uVar3 | uVar5 | uVar17 | uVar7 | uVar6 & 0x9dff000c;
        }
        uVar34 = *(uint *)(&DAT_001aa5fc + iVar38);
        if (uVar34 < 3) {
          uVar6 = *(uint *)pcVar37;
          uVar7 = *(uint *)(pcVar41 + (uVar34 + 1) * 4) & 3;
          *(uint *)pcVar37 = uVar7 | uVar6 & 0xfffffffc;
          uVar17 = *(uint *)(pcVar41 + (uVar34 + 1) * 4) & 0x10;
          *(uint *)pcVar37 = uVar17 | uVar7 | uVar6 & 0xffffffec;
          uVar5 = *(uint *)(pcVar41 + (uVar34 + 1) * 4) & 0x1fe0;
          *(uint *)pcVar37 = uVar5 | uVar17 | uVar7 | uVar6 & 0xffffe00c;
          uVar3 = *(uint *)(pcVar41 + (uVar34 + 1) * 4) & 0x60000000;
          *(uint *)pcVar37 = uVar3 | uVar5 | uVar17 | uVar7 | uVar6 & 0x9fffe00c;
          uVar29 = *(uint *)(pcVar41 + (uVar34 + 1) * 4) >> 2 & 0x4000000;
          *(uint *)pcVar37 = uVar29 | uVar3 | uVar5 | uVar17 | uVar7 | uVar6 & 0x9bffe00c;
          *(uint *)pcVar37 =
               *(uint *)(pcVar41 + (uVar34 + 1) * 4) >> 6 & 0x70000 |
               uVar29 | uVar3 | uVar5 | uVar17 | uVar7 | uVar6 & 0x9bf8e00c;
        }
        *(uint *)pcVar15 = *(uint *)pcVar15 | 0x10000000;
        if ((*(int *)(iVar30 + iVar20 + 0x8418) != 0) ||
           (cVar25 = '\0', *(int *)(local_84 * 4 + iVar20 + 0x8418) != 0)) {
          cVar25 = '\x01';
        }
        bVar11 = 0;
        uVar29 = 0;
        uVar34 = *(uint *)(iVar30 + iVar20 + 0x6418);
        do {
          pcVar39 = pcVar39 + 4;
          if ((uVar34 & 1 << (uVar29 & 0x3f)) != 0) {
            bVar10 = ((int (*)())FUN_00077cd0)(pcVar39);
            bVar11 = bVar10 | bVar11;
          }
          bVar1 = uVar29 != 2;
          uVar29 = uVar29 + 1;
        } while (bVar1);
        if (bVar11 == 0) {
          uVar29 = 0;
          pcVar39 = pcVar21 + local_84 * 0x10;
          uVar34 = *(uint *)(local_84 * 4 + iVar20 + 0x6418);
          bVar10 = 0;
          do {
            pcVar39 = pcVar39 + 4;
            if ((uVar34 & 1 << (uVar29 & 0x3f)) != 0) {
              bVar11 = ((int (*)())FUN_00077cd0)(pcVar39);
              bVar10 = bVar11 | bVar10;
            }
            bVar1 = uVar29 != 2;
            uVar29 = uVar29 + 1;
          } while (bVar1);
          bVar11 = 0;
          if (bVar10 != 0) goto LAB_0007c484;
        }
        else {
LAB_0007c484:
          bVar11 = 1;
        }
        iVar27 = iVar27 + 4;
        local_80 = local_80 + 1;
        local_7c = local_7c + 1;
        pcVar39 = pcVar15;
      }
      if ((cVar25 != '\0') && (iVar30 = *(int *)(iVar28 + 0x20), local_74 = uVar22, iVar30 != 0)) {
        uVar18 = *(undefined4 *)(pcVar39 + 4);
        uVar12 = *(undefined4 *)(pcVar39 + 8);
        uVar26 = *(undefined4 *)(pcVar39 + 0xc);
        iVar38 = local_70 * 0x10;
        local_70 = local_70 + 1;
        iVar13 = iVar30 + iVar38;
        *(undefined4 *)(iVar30 + iVar38) = *(undefined4 *)pcVar39;
        *(undefined4 *)(iVar13 + 0xc) = uVar26;
        *(undefined4 *)(iVar13 + 4) = uVar18;
        *(undefined4 *)(iVar13 + 8) = uVar12;
      }
      uVar34 = *(uint *)pcVar39;
      if (((uVar34 & 0xf00) != 0x800) || (bVar1 = true, (**(uint **)(param_1 + 0x34) >> 6 & 1) != 0)
         ) {
        bVar1 = false;
      }
      if (bVar1) {
        uVar33 = uVar22;
      }
      if (bVar11 != 0) {
        uVar4 = uVar22;
      }
      iVar30 = ((int (*)())FUN_00077cf0)(pcVar39);
      if ((iVar30 != 0) && (uVar29 = (uVar34 >> 0xd & 0x7f) + 1, local_78 < uVar29)) {
        local_78 = uVar29;
      }
      if (uVar22 == 0x400) {
        return 10;
      }
      uVar29 = *(uint *)(pcVar39 + 0xc);
      uVar7 = *(uint *)(pcVar39 + 4);
      uVar22 = uVar22 + 1;
      iVar27 = iVar27 + 4;
      uVar17 = *(uint *)(pcVar39 + 8);
      *puVar19 = uVar34;
      puVar19[3] = uVar29;
      puVar19[1] = uVar7;
      puVar19[2] = uVar17;
      local_7c = local_7c + 1;
    } while (local_7c < *(uint *)(param_1 + 0x2a878));
  }
  **(uint **)(iVar28 + 0x1c) = uVar22;
  puVar19 = *(uint **)(iVar28 + 0x28);
  if (puVar19 != (uint *)0x0) {
    if ((**(uint **)(param_1 + 0x34) & 0x40) == 0) {
      if (local_74 < uVar33) {
        local_74 = uVar33;
      }
      *puVar19 = local_74;
    }
    else {
      *puVar19 = local_74;
    }
  }
  if (*(uint **)(iVar28 + 0x2c) != (uint *)0x0) {
    **(uint **)(iVar28 + 0x2c) = uVar4;
  }
  if (*(uint **)(iVar28 + 0x30) != (uint *)0x0) {
    **(uint **)(iVar28 + 0x30) = local_78;
  }
  if (*(int *)(iVar28 + 0x20) != 0) {
    **(int **)(iVar28 + 0x24) = local_70;
  }
  *(int *)(param_1 + 0x3548c) = local_80;
  return 0;
}

/* FUN_0007c760 @ 0x7c760 (4940 bytes) */
int FUN_0007c760(param_1)
  uint *param_1;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  lc_str lVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  dword *pdVar13;
  dword *pdVar14;
  uint *extraout_r4;
  uint *extraout_r4_00;
  uint *extraout_r4_01;
  uint *extraout_r4_02;
  uint *extraout_r4_03;
  uint *extraout_r4_04;
  uint *extraout_r4_05;
  uint *extraout_r4_06;
  uint *extraout_r4_07;
  uint *extraout_r4_08;
  uint *extraout_r4_09;
  uint *extraout_r4_10;
  uint *extraout_r4_11;
  uint *extraout_r4_12;
  uint *extraout_r4_13;
  uint *extraout_r4_14;
  uint *extraout_r4_15;
  dword *pdVar15;
  dword *in_r6;
  uint *puVar16;
  uint uVar17;
  dword *pdVar18;
  int iVar19;
  dword *pdVar20;
  uint *puVar21;
  char cVar22;
  int iVar23;
  dword *pdVar24;
  dword *pdVar25;
  uint uVar26;
  uint *puVar27;
  uint uVar28;
  dword dVar29;
  undefined1 *puVar30;
  int *piVar31;
  int *piVar32;
  int iVar33;
  uint *puVar34;
  byte in_xer_so;
  int iVar35;
  int iVar36;
  undefined8 uVar37;
  uint local_b8;
  uint *local_b4;
  dylib local_b0;
  int *local_a0;
  dword *local_9c;
  undefined1 *local_98;
  int local_94;
  int local_90;
  uint local_8c;
  int local_88;
  uint *local_84;
  uint *local_80;
  uint *local_7c;
  dword *local_78;
  dword *local_74;
  int *local_70;
  int *local_6c;
  int *local_68;
  uint *local_64;
  int local_60;
  uint **local_5c;
  
  if (0x800 < param_1[2]) {
    return 10;
  }
  if (param_1[2] == 0) {
    return 1;
  }
  param_1[0xd] = (uint)param_1;
  local_64 = param_1 + 0xc000;
  ((int (*)())FUN_0007a060)(param_1 + 0x4915);
  iVar19 = 0;
  local_64[-0x15e2] = 0;
  local_64[-0x1de3] = 0;
  puVar21 = local_64 + 0x21f;
  puVar27 = local_64 + -0x15e4;
  do {
    *(undefined1 *)puVar21 = 0;
    puVar9 = puVar27 + 3;
    iVar35 = 4;
    do {
      *puVar9 = 0;
      puVar9[0xc00] = 0;
      puVar9 = puVar9 + 1;
      iVar35 = iVar35 + -1;
    } while (iVar35 != 0);
    bVar1 = iVar19 != 0x2ff;
    puVar27 = puVar27 + 4;
    puVar21 = (uint *)((int)puVar21 + 1);
    iVar19 = iVar19 + 1;
  } while (bVar1);
  iVar19 = 4;
  *(undefined1 *)(local_64 + 0x2e7) = 0;
  puVar27 = local_64 + 0x2df;
  do {
    *puVar27 = 0;
    puVar27[4] = 0;
    puVar27 = puVar27 + 1;
    iVar19 = iVar19 + -1;
  } while (iVar19 != 0);
  pdVar15 = (dword *)0x2000;
  param_1[0x9a1c] = 0;
  _memset(local_64 + 0x523,0,0x2000);
  iVar19 = 0x800;
  puVar27 = local_64 + 0xd23;
  do {
    *puVar27 = 0;
    puVar27 = puVar27 + 1;
    iVar19 = iVar19 + -1;
  } while (iVar19 != 0);
  pdVar18 = param_1 + 0xe;
  local_64[0x1523] = 0;
  ((int (*)())FUN_0007a060)(pdVar18);
  puVar21 = param_1 + 0x3914;
  iVar19 = 0;
  pdVar20 = (dword *)0x0;
  puVar27 = param_1 + 0x112;
  do {
    puVar9 = puVar27 + 2;
    iVar35 = 0;
    do {
      bVar1 = iVar35 != 2;
      *puVar9 = 0;
      iVar35 = iVar35 + 1;
      puVar9 = puVar9 + 1;
    } while (bVar1);
    bVar1 = iVar19 != 0x7ff;
    puVar21[-0x1000] = 0;
    puVar21[-0x800] = 0;
    *puVar21 = 0;
    puVar21[-0x2000] = 0;
    puVar21[-0x1800] = 0;
    puVar21[0x801] = 0;
    param_1[0x4114] = 0;
    puVar27 = puVar27 + 3;
    puVar21 = puVar21 + 1;
    iVar19 = iVar19 + 1;
  } while (bVar1);
  if ((*param_1 & 0x40) == 0) {
    param_1[0x8a1b] = param_1[2];
    pdVar15 = (dword *)(param_1[2] << 4);
    _memcpy(param_1 + 0x4a1b,param_1[1],pdVar15);
    puVar27 = extraout_r4_00;
  }
  else {
    uVar10 = param_1[2];
    param_1[0x8a1b] = uVar10;
    param_1[0x8a1b] = 0;
    puVar27 = extraout_r4;
    if (uVar10 != 0) {
      pdVar15 = param_1 + 0x4a1b;
      puVar21 = (uint *)param_1[1];
      pdVar20 = pdVar15;
      while( true ) {
        puVar27 = puVar21 + 4;
        uVar17 = puVar21[1];
        uVar26 = puVar21[2];
        uVar11 = puVar21[3];
        *pdVar20 = *puVar21;
        pdVar20[1] = uVar17;
        pdVar20[2] = uVar26;
        pdVar20[3] = uVar11;
        uVar17 = param_1[0x8a1b] + 1;
        param_1[0x8a1b] = uVar17;
        if ((*puVar21 & 0x10000000) != 0) {
          puVar9 = puVar21 + 3;
          in_r6 = pdVar15 + uVar17 * 4;
          iVar19 = (puVar21[3] >> 0x15 & 0xf) * 0x14;
          if (0x7ff < uVar17) {
            return 10;
          }
          pdVar20[3] = 0x124800;
          *pdVar20 = *pdVar20 & 0xefffffff;
          pdVar15[uVar17 * 4] = 0;
          in_r6[3] = 0x124800;
          in_r6[1] = 0x124800;
          in_r6[2] = 0x124800;
          *(byte *)((int)in_r6 + 3) = (byte)(puVar21[3] >> 0x15) & 0xf | 0x40;
          uVar26 = pdVar15[uVar17 * 4];
          pdVar15[uVar17 * 4] = uVar26 & 0xfffff0ff | 0x400;
          uVar26 = (puVar21[3] >> 0x13 & 3) << 0xd | uVar26 & 0xff0010ff | 0x400;
          pdVar15[uVar17 * 4] = uVar26;
          uVar11 = puVar21[3] >> 0x1b & 3;
          if (uVar11 == 1) {
            pdVar15[uVar17 * 4] = uVar26 | 0x200000;
          }
          else if (uVar11 < 2) {
            if (uVar11 == 0) {
              pdVar15[uVar17 * 4] = uVar26 | 0x100000;
            }
          }
          else if (uVar11 == 2) {
            pdVar15[uVar17 * 4] = uVar26 | 0x400000;
          }
          else if (uVar11 == 3) {
            pdVar15[uVar17 * 4] = uVar26 | 0x800000;
          }
          *in_r6 = *in_r6 & 0xefffffff;
          uVar17 = *(uint *)(&DAT_001aa5f8 + iVar19);
          if (uVar17 < 3) {
            uVar8 = in_r6[uVar17 + 1];
            uVar11 = *puVar9 & 3;
            in_r6[uVar17 + 1] = uVar11 | uVar8 & 0xfffffff0;
            uVar28 = *puVar9 & 0x10;
            in_r6[uVar17 + 1] = uVar28 | uVar11 | uVar8 & 0xffffffe0;
            uVar5 = *puVar9 & 0x1fe0;
            in_r6[uVar17 + 1] = uVar5 | uVar28 | uVar11 | uVar8 & 0xffffe000;
            uVar6 = *puVar9 & 0x60000000;
            in_r6[uVar17 + 1] = uVar6 | uVar5 | uVar28 | uVar11 | uVar8 & 0x9fffe000;
            uVar26 = (*puVar9 & 0x2000000) << 3;
            in_r6[uVar17 + 1] = uVar26 | uVar6 | uVar5 | uVar28 | uVar11 | uVar8 & 0x8fffe000;
            in_r6[uVar17 + 1] =
                 (*puVar9 & 0xe000) << 9 |
                 uVar26 | uVar6 | uVar5 | uVar28 | uVar11 | uVar8 & 0x8e3fe000;
          }
          uVar17 = *(uint *)(&DAT_001aa5fc + iVar19);
          if (uVar17 < 3) {
            uVar8 = in_r6[uVar17 + 1];
            uVar11 = *puVar9 & 3;
            in_r6[uVar17 + 1] = uVar11 | uVar8 & 0xfffffff0;
            uVar28 = *puVar9 & 0x10;
            in_r6[uVar17 + 1] = uVar28 | uVar11 | uVar8 & 0xffffffe0;
            uVar5 = *puVar9 & 0x1fe0;
            in_r6[uVar17 + 1] = uVar5 | uVar28 | uVar11 | uVar8 & 0xffffe000;
            uVar6 = *puVar9 & 0x60000000;
            in_r6[uVar17 + 1] = uVar6 | uVar5 | uVar28 | uVar11 | uVar8 & 0x9fffe000;
            uVar26 = (*puVar9 & 0x4000000) << 2;
            in_r6[uVar17 + 1] = uVar26 | uVar6 | uVar5 | uVar28 | uVar11 | uVar8 & 0x8fffe000;
            in_r6[uVar17 + 1] =
                 (*(ushort *)puVar9 & 7) << 0x16 |
                 uVar26 | uVar6 | uVar5 | uVar28 | uVar11 | uVar8 & 0x8e3fe000;
          }
          param_1[0x8a1b] = param_1[0x8a1b] + 1;
        }
        uVar10 = uVar10 - 1;
        if (uVar10 == 0) break;
        pdVar20 = pdVar15 + param_1[0x8a1b] * 4;
        puVar21 = puVar27;
        if (0x7ff < param_1[0x8a1b]) {
          return 10;
        }
      }
    }
  }
  local_78 = (dword *)param_1[0x8a1b];
  puVar21 = param_1 + 0x4a1b;
  local_74 = (dword *)param_1[6];
  local_70 = (int *)param_1[10];
  local_6c = (int *)param_1[8];
  local_68 = (int *)param_1[9];
  if ((undefined4 *)param_1[7] != (undefined4 *)0x0) {
    *(undefined4 *)param_1[7] = local_78;
  }
  local_60 = (uint)(byte)(((int)local_70 < 0) << 3 | (0 < (int)local_70) << 2 |
                          (local_70 == (int *)0x0) << 1 | in_xer_so & 1) << 0x1c;
  piVar32 = local_6c;
  if (local_70 != (int *)0x0) {
    *local_70 = (int)((int)local_78 + -1);
    piVar32 = local_70;
  }
  pdVar14 = (dword *)((int)local_78 + -1);
  local_98 = (undefined1 *)pdVar14;
  if (-1 < (int)pdVar14) {
    iVar19 = (int)pdVar14 * 4;
    iVar23 = (int)pdVar14 * 0xc;
    puVar9 = puVar21 + (int)pdVar14 * 4;
    local_94 = 0;
    pdVar25 = local_74 + (int)pdVar14 * 4;
    local_5c = &local_b4;
    bVar1 = local_74 == (dword *)0x0;
    pdVar24 = pdVar18 + (int)(local_78 + 0x641) + 1;
    iVar35 = 0;
    pdVar13 = pdVar14;
    puVar4 = (undefined1 *)pdVar14;
    do {
      puVar4 = puVar4 + -1;
      if (bVar1) {
LAB_0007cc7c:
        puVar27 = (uint *)param_1[0xd];
      }
      else {
        puVar27 = (uint *)param_1[0xd];
        if ((*puVar27 & 0x200) == 0) {
          iVar36 = 4;
          pdVar14 = pdVar25;
          puVar27 = puVar9;
          do {
            uVar10 = *puVar27;
            puVar27 = puVar27 + 1;
            *pdVar14 = uVar10;
            pdVar14 = pdVar14 + 1;
            iVar36 = iVar36 + -1;
          } while (iVar36 != 0);
          goto LAB_0007cc7c;
        }
      }
      iVar36 = 0;
      puVar16 = puVar21 + iVar19;
      do {
        puVar16 = puVar16 + 1;
        bVar2 = iVar36 != 8;
        *(uint **)(iVar36 + (int)local_5c) = puVar16;
        iVar36 = iVar36 + 4;
      } while (bVar2);
      local_b0.current_version = (dword)(puVar21 + iVar19);
      pdVar14 = (dword *)((int (*)())FUN_00077850)(puVar9);
      if (pdVar14 == (dword *)0x0) {
LAB_0007ceb8:
        local_90 = 0;
      }
      else {
        if ((*puVar27 & 0x40) == 0) {
          pdVar20 = (dword *)*puVar9;
          if (((uint)pdVar20 >> 8 & 0xf) - 4 < 5) {
            for (piVar32 = (int *)param_1[0x4114]; piVar32 != (int *)0x0;
                piVar32 = (int *)piVar32[4]) {
              local_b8 = puVar21[*piVar32 * 4];
              if (((uint)pdVar20 & 0xfef00) == (local_b8 & 0xfef00)) {
                uVar10 = ((int (*)())FUN_00077850)(&local_b8);
                pdVar14 = (dword *)((uint)pdVar14 & ~uVar10);
                ((int (*)())FUN_000798f0)(puVar9,pdVar14);
                pdVar20 = (dword *)*puVar9;
              }
            }
            if ((((uint)pdVar20 & 0xf00) == 0x400) && (pdVar24[0x800] = 1, local_94 == 0)) {
              if ((bool)((byte)((uint)local_60 >> 0x1d) & 1)) {
                local_94 = 1;
              }
              else {
                *local_70 = (int)pdVar13;
                local_94 = 1;
              }
            }
            pdVar15 = pdVar13;
            in_r6 = pdVar14;
            iVar36 = ((int (*)())FUN_00079910)(param_1,param_1 + 0x4114,pdVar13,pdVar14,0,0,pdVar18);
            if (iVar36 != 0) {
              return iVar36;
            }
LAB_0007ceb4:
            puVar27 = (uint *)param_1[0xd];
          }
          goto LAB_0007ceb8;
        }
        pdVar20 = (dword *)*puVar9;
        if (1 < ((uint)pdVar20 >> 8 & 0xf) - 2) goto LAB_0007ceb8;
        for (piVar32 = (int *)param_1[0x4114]; piVar32 != (int *)0x0; piVar32 = (int *)piVar32[4]) {
          local_b8 = puVar21[*piVar32 * 4];
          if (((uint)pdVar20 & 0xfe000) == (local_b8 & 0xfe000)) {
            uVar10 = ((int (*)())FUN_00077850)(&local_b8);
            pdVar14 = (dword *)((uint)pdVar14 & ~uVar10);
            ((int (*)())FUN_000798f0)(puVar9,pdVar14);
            pdVar20 = (dword *)*puVar9;
          }
        }
        if (((uint)pdVar20 & 0xfe000) == 0) {
          pdVar24[0x800] = 1;
        }
        if ((local_94 == 0) && ((*puVar9 & 0xfe000) == 0)) {
          if ((bool)((byte)((uint)local_60 >> 0x1d) & 1)) {
            local_94 = 1;
          }
          else {
            *local_70 = (int)pdVar13;
            local_94 = 1;
          }
        }
        pdVar15 = pdVar13;
        in_r6 = pdVar14;
        iVar36 = ((int (*)())FUN_00079910)(param_1,param_1 + 0x4114,pdVar13,pdVar14,0,0,pdVar18);
        if (iVar36 != 0) {
          return iVar36;
        }
        if ((*puVar9 & 0xf00) != 0x300) goto LAB_0007ceb4;
        puVar27 = (uint *)param_1[0xd];
        local_90 = 1;
      }
      uVar10 = *puVar27 >> 6 & 1;
      iVar36 = ((int (*)())FUN_000777b0)(puVar9,uVar10);
      if (((iVar36 != 0) || (iVar36 = ((int (*)())FUN_00077800)(puVar9,uVar10), iVar36 != 0)) &&
         (piVar32 = (*(int * *)(pdVar24 + (0x1000))), piVar32 != (int *)0x0)) {
        pdVar20 = (dword *)((int)&MACH_HEADER.magic + 1);
        do {
          uVar10 = pdVar18[*piVar32 + 0x2106];
          if (uVar10 != 0) {
            pdVar24[0x800] = 1;
          }
          piVar32 = (int *)piVar32[4];
        } while ((piVar32 != (int *)0x0) && (uVar10 == 0));
        puVar27 = (uint *)param_1[0xd];
      }
      uVar10 = *puVar27 >> 6 & 1;
      iVar36 = ((int (*)())FUN_000777b0)(puVar9,uVar10);
      if ((iVar36 != 0) || (iVar36 = ((int (*)())FUN_00077800)(puVar9,uVar10), iVar36 != 0)) {
        puVar16 = (uint *)0x0;
        for (uVar10 = pdVar24[0x1000]; uVar10 != 0; uVar10 = *(uint *)(uVar10 + 0x10)) {
          puVar16 = (uint *)((uint)puVar16 | *(uint *)(uVar10 + 4));
        }
        if (pdVar14 != puVar16) {
          ((int (*)())FUN_000798f0)(puVar9,(uint)pdVar14 & (uint)puVar16);
          puVar27 = (uint *)param_1[0xd];
        }
      }
      puVar16 = local_b4;
      cVar22 = (char)*puVar9;
      if (((cVar22 == 'A') && ((*puVar27 & 0x80) != 0)) && (uVar10 = pdVar24[0x1000], uVar10 != 0))
      {
        uVar17 = 0;
        do {
          puVar34 = (uint *)(uVar10 + 4);
          uVar10 = *(uint *)(uVar10 + 0x10);
          uVar17 = uVar17 | *puVar34;
        } while (uVar10 != 0);
        if ((uVar17 & 7) == 2) {
          *(undefined1 *)((int)puVar9 + 3) = 6;
          pdVar15 = (dword *)((int (*)())FUN_00079a20)(local_b4,3);
          ((int (*)())FUN_00079a90)(puVar16,1,pdVar15);
          if (!bVar1) {
            iVar36 = 4;
            pdVar14 = local_74 + iVar19;
            puVar27 = (uint *)local_b0.current_version;
            do {
              uVar10 = *puVar27;
              puVar27 = puVar27 + 1;
              *pdVar14 = uVar10;
              pdVar14 = pdVar14 + 1;
              iVar36 = iVar36 + -1;
            } while (iVar36 != 0);
          }
          puVar27 = (uint *)param_1[0xd];
          cVar22 = (char)*puVar9;
        }
      }
      if ((cVar22 == 'D') &&
         (iVar36 = ((int (*)())FUN_000777b0)(puVar9,*puVar27 >> 6 & 1), puVar16 = local_b4, iVar36 != 0)) {
        pdVar20 = (dword *)(*puVar9 & 0xff7fffff);
        *puVar9 = *puVar9 & 0xff6fffff;
        puVar27 = (uint *)param_1[0xd];
        if ((((*puVar27 >> 6 & 1) != 0) &&
            ((iVar36 = ((int (*)())FUN_000782e0)(local_b4), lVar7.offset = local_b0.name.offset, iVar36 != 0 &&
             (iVar36 = ((int (*)())FUN_000782e0)(local_b0.name.offset), dVar29 = local_b0.timestamp, iVar36 != 0)
             ))) && (iVar36 = ((int (*)())FUN_000782e0)(local_b0.timestamp), iVar36 != 0)) {
          uVar10 = *puVar16;
          if (((uVar10 & 0x1fe0) == (*(uint *)lVar7.offset & 0x1fe0)) &&
             ((uVar10 & 0x1fe0) == (*(uint *)dVar29 & 0x1fe0))) {
            uVar17 = *(uint *)lVar7.offset >> 9 & 0xe000;
            *puVar16 = uVar17 | uVar10 & 0xffff1fff;
            *puVar16 = *(uint *)dVar29 >> 6 & 0x70000 | uVar17 | uVar10 & 0xfff81fff;
            uVar17 = *(uint *)lVar7.offset;
            uVar10 = (uVar10 & 0x1c00000) >> 9;
            *(uint *)lVar7.offset = uVar10 | uVar17 & 0xffff1fff;
            *(uint *)lVar7.offset = *(uint *)dVar29 >> 6 & 0x70000 | uVar10 | uVar17 & 0xfff81fff;
            uVar17 = *(uint *)dVar29;
            uVar10 = *puVar16 >> 9 & 0xe000;
            *(uint *)dVar29 = uVar10 | uVar17 & 0xffff1fff;
            *(uint *)dVar29 = *(uint *)lVar7.offset >> 6 & 0x70000 | uVar10 | uVar17 & 0xfff81fff;
            puVar27 = (uint *)param_1[0xd];
          }
        }
      }
      if ((!bVar1) && ((*puVar27 & 0x200) != 0)) {
        iVar36 = 4;
        pdVar14 = local_74 + iVar19;
        puVar27 = (uint *)local_b0.current_version;
        do {
          uVar10 = *puVar27;
          puVar27 = puVar27 + 1;
          *pdVar14 = uVar10;
          pdVar14 = pdVar14 + 1;
          iVar36 = iVar36 + -1;
        } while (iVar36 != 0);
        puVar27 = (uint *)param_1[0xd];
      }
      uVar17 = 0;
      local_a0 = (int *)0x0;
      uVar37 = ((int (*)())FUN_00078300)(puVar9,*puVar27 >> 6 & 1);
      uVar10 = (uint)((ulonglong)uVar37 >> 0x20);
      puVar27 = (uint *)uVar37;
      *pdVar24 = uVar10;
      local_9c = pdVar18 + (int)pdVar13 * 3 + 0x106;
      local_7c = local_b4;
      local_80 = (uint *)local_b0.name.offset;
      local_84 = (uint *)local_b0.timestamp;
      iVar36 = iVar23;
      local_b0.compatibility_version = (dword)&local_b0;
      do {
        if ((uVar10 & 1 << (uVar17 & 0x3f)) == 0) {
          uVar26 = 5;
          if ((*(uint *)param_1[0xd] & 0x40) == 0) {
            uVar26 = 9;
          }
          **(uint **)((int)local_a0 + (int)local_5c) =
               uVar26 | **(uint **)((int)local_a0 + (int)local_5c) & 0xfffffff0;
          goto LAB_0007da08;
        }
        puVar16 = (uint *)param_1[0xd];
        uVar28 = **(uint **)((int)local_a0 + (int)local_5c);
        uVar26 = *puVar16 >> 6;
        uVar11 = uVar28 & 0xf;
        if ((uVar11 == 0) || (((uVar11 == 3 || (uVar11 == 1)) && ((uVar26 & 1) != 0)))) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (!bVar2) {
          uVar37 = ((int (*)())FUN_00078ef0)(*(uint **)((int)local_a0 + (int)local_5c));
          puVar27 = (uint *)uVar37;
          if ((int)((ulonglong)uVar37 >> 0x20) != 0) {
            uVar11 = uVar28 >> 4 & 1;
            if ((uVar26 & 1) != 0) {
              uVar11 = uVar28 >> 0x1e & 2 | uVar28 >> 4 & 1;
            }
            if ((uVar11 == 1) && (local_8c = uVar28 >> 0x1d & 3, -1 < (int)puVar4)) {
              puVar30 = (undefined1 *)0x0;
              local_88 = (int)param_1 + iVar36 + 0x450;
              puVar34 = puVar9;
              do {
                puVar34 = puVar34 + -4;
                local_b8 = *puVar34;
                uVar37 = ((int (*)())FUN_00077800)(&local_b8,*puVar16 >> 6 & 1);
                puVar27 = (uint *)uVar37;
                if ((int)((ulonglong)uVar37 >> 0x20) == 0) {
LAB_0007d968:
                  bVar2 = false;
                }
                else {
                  uVar37 = ((int (*)())FUN_00078f10)(&local_b8,local_8c);
                  puVar27 = (uint *)uVar37;
                  if ((int)((ulonglong)uVar37 >> 0x20) == 0) goto LAB_0007d968;
                  pdVar15 = (dword *)(puVar4 + -(int)puVar30);
                  in_r6 = (dword *)(1 << (local_8c & 0x3f));
                  ((int (*)())FUN_00079910)(param_1,local_88,pdVar15,in_r6,0,0,pdVar18);
                  bVar2 = true;
                  puVar27 = extraout_r4_13;
                }
                if ((puVar30 == puVar4) || (puVar30 = puVar30 + 1, bVar2)) break;
                puVar16 = (uint *)param_1[0xd];
              } while( true );
            }
          }
          goto switchD_0007d27c_caseD_0;
        }
        switch((char)*puVar9) {
        case '\x01':
          iVar33 = 0;
          dVar29 = ((lc_str *)local_b0.compatibility_version)->offset;
          do {
            uVar37 = ((int (*)())FUN_00079a20)(dVar29,iVar33);
            puVar27 = (uint *)uVar37;
            if ((int)((ulonglong)uVar37 >> 0x20) != 4) {
              pdVar15 = local_74;
              in_r6 = pdVar18;
              ((int (*)())FUN_00079bd0)(param_1,puVar21,local_74,pdVar18,pdVar13,uVar17,iVar33);
              puVar27 = extraout_r4_08;
            }
            bVar2 = iVar33 != 3;
            iVar33 = iVar33 + 1;
          } while (bVar2);
          break;
        case '\x02':
          iVar33 = 0;
          bVar2 = local_90 == 0;
          do {
            if (bVar2) {
              uVar37 = ((int (*)())FUN_00078f10)(puVar9,iVar33);
              puVar27 = (uint *)uVar37;
              if ((int)((ulonglong)uVar37 >> 0x20) != 0) {
                uVar37 = ((int (*)())FUN_00079a20)(((lc_str *)local_b0.compatibility_version)->offset,iVar33);
                puVar27 = (uint *)uVar37;
                if ((int)((ulonglong)uVar37 >> 0x20) != 4) {
                  pdVar15 = local_74;
                  in_r6 = pdVar18;
                  ((int (*)())FUN_00079bd0)(param_1,puVar21,local_74,pdVar18,pdVar13,uVar17,iVar33);
                  puVar27 = extraout_r4_10;
                }
              }
            }
            else if (iVar33 == 0) {
              uVar37 = ((int (*)())FUN_00077850)(puVar9);
              puVar27 = (uint *)uVar37;
              if ((int)((ulonglong)uVar37 >> 0x20) != 0) {
                uVar37 = ((int (*)())FUN_00079a20)(((lc_str *)local_b0.compatibility_version)->offset,0);
                puVar27 = (uint *)uVar37;
                if ((int)((ulonglong)uVar37 >> 0x20) != 4) {
                  pdVar15 = local_74;
                  in_r6 = pdVar18;
                  ((int (*)())FUN_00079bd0)(param_1,puVar21,local_74,pdVar18,pdVar13,uVar17,0);
                  puVar27 = extraout_r4_09;
                }
              }
            }
            bVar3 = iVar33 != 3;
            iVar33 = iVar33 + 1;
          } while (bVar3);
          break;
        case '\x03':
        case '\x04':
        case '\x06':
        case '\a':
        case '\b':
        case '\t':
        case '\n':
        case '\v':
        case '\f':
        case '\r':
        case '\x0e':
        case -0x80:
        case -0x7f:
          iVar33 = 0;
          bVar2 = local_90 == 0;
          do {
            if (bVar2) {
              uVar37 = ((int (*)())FUN_00078f10)(puVar9,iVar33);
              puVar27 = (uint *)uVar37;
              if ((int)((ulonglong)uVar37 >> 0x20) != 0) {
                pdVar15 = local_74;
                in_r6 = pdVar18;
                ((int (*)())FUN_00079bd0)(param_1,puVar21,local_74,pdVar18,pdVar13,uVar17,iVar33);
                puVar27 = extraout_r4_12;
              }
            }
            else if (iVar33 == 0) {
              uVar37 = ((int (*)())FUN_00077850)(puVar9);
              puVar27 = (uint *)uVar37;
              if ((int)((ulonglong)uVar37 >> 0x20) != 0) {
                pdVar15 = local_74;
                in_r6 = pdVar18;
                ((int (*)())FUN_00079bd0)(param_1,puVar21,local_74,pdVar18,pdVar13,uVar17,0);
                puVar27 = extraout_r4_11;
              }
            }
            bVar3 = iVar33 != 3;
            iVar33 = iVar33 + 1;
          } while (bVar3);
          break;
        case '\x05':
          iVar33 = 1;
          do {
            if (uVar17 == 0) {
              if (iVar33 - 1U < 2) {
LAB_0007d6c4:
                uVar37 = ((int (*)())FUN_00078f10)(puVar9,iVar33);
                puVar27 = (uint *)uVar37;
                if ((int)((ulonglong)uVar37 >> 0x20) != 0) {
                  pdVar15 = local_74;
                  in_r6 = pdVar18;
                  ((int (*)())FUN_00079bd0)(param_1,puVar21,local_74,pdVar18,pdVar13,uVar17,iVar33);
                  puVar27 = extraout_r4_07;
                }
              }
            }
            else if ((uVar17 == 1) && ((iVar33 == 1 || (iVar33 == 3)))) goto LAB_0007d6c4;
            bVar2 = iVar33 != 3;
            iVar33 = iVar33 + 1;
          } while (bVar2);
          break;
        case 'A':
        case 'B':
        case 'F':
        case 'H':
        case 'K':
        case 'L':
        case 'P':
        case 'Q':
          goto switchD_0007d27c_caseD_41;
        case 'C':
        case 'G':
        case 'I':
          if ((uVar26 & 1) != 0) goto switchD_0007d27c_caseD_41;
          pdVar15 = local_74;
          in_r6 = pdVar18;
          ((int (*)())FUN_00079bd0)(param_1,puVar21,local_74,pdVar18,pdVar13,uVar17,0);
          puVar27 = extraout_r4_04;
          break;
        case 'D':
          iVar33 = 0;
          if ((uVar26 & 1) == 0) {
            do {
              pdVar15 = local_74;
              in_r6 = pdVar18;
              ((int (*)())FUN_00079bd0)(param_1,puVar21,local_74,pdVar18,pdVar13,uVar17,iVar33);
              iVar12 = 4 - iVar33;
              if (4 < iVar33 + 1) {
                iVar12 = 1;
              }
              do {
                iVar33 = iVar33 + 1;
                iVar12 = iVar12 + -1;
                puVar27 = extraout_r4_01;
                if (iVar12 == 0) goto switchD_0007d27c_caseD_0;
              } while (iVar33 == 2);
            } while( true );
          }
          if ((((*local_7c & 0xf) == 0) && ((*local_80 & 0xf) == 0)) &&
             (((*local_84 & 0xf) == 0 &&
              ((uVar26 = *local_7c & 0x1fe0, uVar26 == (*local_80 & 0x1fe0) &&
               (iVar33 = 0, uVar26 == (*local_84 & 0x1fe0))))))) {
            do {
              pdVar15 = local_74;
              in_r6 = pdVar18;
              ((int (*)())FUN_00079bd0)(param_1,puVar21,local_74,pdVar18,pdVar13,uVar17,iVar33);
              iVar12 = 4 - iVar33;
              if (4 < iVar33 + 1) {
                iVar12 = 1;
              }
              do {
                iVar33 = iVar33 + 1;
                iVar12 = iVar12 + -1;
                puVar27 = extraout_r4_02;
                if (iVar12 == 0) goto switchD_0007d27c_caseD_0;
              } while (iVar33 == 2);
            } while( true );
          }
          goto switchD_0007d27c_caseD_41;
        case 'E':
        case 'M':
        case 'N':
        case 'O':
          iVar33 = 0;
          if ((uVar26 & 1) == 0) {
            do {
              pdVar15 = local_74;
              in_r6 = pdVar18;
              ((int (*)())FUN_00079bd0)(param_1,puVar21,local_74,pdVar18,pdVar13,uVar17,iVar33);
              iVar12 = 3 - iVar33;
              if (3 < iVar33 + 1) {
                iVar12 = 1;
              }
              do {
                iVar33 = iVar33 + 1;
                iVar12 = iVar12 + -1;
                puVar27 = extraout_r4_03;
                if (iVar12 == 0) goto switchD_0007d27c_caseD_0;
              } while (((iVar33 == 1) && ((char)*puVar9 != '\r')) && ((char)*puVar9 != '\x0e'));
            } while( true );
          }
switchD_0007d27c_caseD_41:
          pdVar15 = local_74;
          in_r6 = pdVar18;
          ((int (*)())FUN_00079bd0)(param_1,puVar21,local_74,pdVar18,pdVar13,uVar17,3);
          puVar27 = extraout_r4_06;
          break;
        case 'J':
          if ((uVar26 & 1) != 0) goto switchD_0007d27c_caseD_41;
          iVar33 = 0;
          do {
            pdVar15 = local_74;
            in_r6 = pdVar18;
            ((int (*)())FUN_00079bd0)(param_1,puVar21,local_74,pdVar18,pdVar13,uVar17,iVar33);
            bVar2 = iVar33 != 1;
            iVar33 = iVar33 + 1;
            puVar27 = extraout_r4_05;
          } while (bVar2);
        }
switchD_0007d27c_caseD_0:
        for (piVar32 = (int *)*local_9c; piVar32 != (int *)0x0;
            piVar32 = *(int **)((int)piVar32 + 0x10)) {
          in_r6 = *(dword **)((int)piVar32 + 4);
          pdVar15 = pdVar13;
          uVar37 = ((int (*)())FUN_00079910)(param_1,param_1 + *piVar32 + 0x2914,pdVar13,in_r6,
                                *(int *)((int)piVar32 + 8),0,pdVar18);
          iVar33 = (int)((ulonglong)uVar37 >> 0x20);
          puVar27 = (uint *)uVar37;
          if (iVar33 != 0) {
            return iVar33;
          }
        }
LAB_0007da08:
        bVar2 = uVar17 != 2;
        iVar36 = iVar36 + 4;
        uVar17 = uVar17 + 1;
        local_9c = local_9c + 1;
        piVar32 = local_a0 + 1;
        pdVar14 = &((dylib *)(local_b0.compatibility_version + -0x10))->compatibility_version;
        local_b0.compatibility_version = (dword)pdVar14;
        local_a0 = piVar32;
      } while (bVar2);
      iVar35 = iVar35 + 1;
      pdVar13 = (dword *)((int)pdVar13 + -1);
      iVar23 = iVar23 + -0xc;
      puVar9 = puVar9 + -4;
      pdVar24 = pdVar24 + 0xffffffff;
      iVar19 = iVar19 + -4;
      pdVar25 = pdVar25 + -4;
    } while (iVar35 != (int)local_98 + 1);
  }
  bVar1 = 0 < (int)local_78;
  if (bVar1) {
    puVar21 = param_1 + 0x2914;
    uVar10 = 0;
    puVar27 = param_1 + 0x3114;
    do {
      for (piVar31 = (int *)*puVar21; piVar31 != (int *)0x0; piVar31 = (int *)piVar31[4]) {
        uVar26 = 0;
        pdVar14 = pdVar18 + *piVar31 * 3;
        uVar17 = pdVar18[*piVar31 + 0x1906];
        puVar9 = pdVar14 + 0x106;
        do {
          if (((uVar17 & 1 << (uVar26 & 0x3f)) != 0) &&
             (pdVar15 = (dword *)*puVar9, pdVar15 != (dword *)0x0)) {
            pdVar14 = (dword *)0x0;
            pdVar13 = pdVar15;
            do {
              if (uVar10 == *pdVar13) {
                pdVar14 = (dword *)((int)&MACH_HEADER.magic + 1);
              }
              pdVar13 = (*(dword * *)(pdVar13 + (4)));
              pdVar24 = pdVar14;
            } while (pdVar13 != (dword *)0x0);
            while (pdVar24 != (dword *)0x0) {
              if (uVar10 != *pdVar15) {
                in_r6 = (*(dword * *)(pdVar15 + (1)));
                piVar32 = (int *)0x0;
                pdVar14 = pdVar18;
                iVar19 = ((int (*)())FUN_00079910)(param_1,puVar27,*pdVar15,in_r6,0,0,pdVar18);
                if (iVar19 != 0) {
                  return iVar19;
                }
              }
              pdVar15 = (*(dword * *)(pdVar15 + (4)));
              pdVar24 = pdVar15;
            }
          }
          bVar2 = uVar26 != 2;
          puVar9 = puVar9 + 1;
          uVar26 = uVar26 + 1;
        } while (bVar2);
      }
      uVar10 = uVar10 + 1;
      puVar27 = puVar27 + 1;
      puVar21 = puVar21 + 1;
    } while ((dword *)uVar10 != local_78);
    puVar21 = param_1 + 0x3114;
    iVar19 = 0;
    do {
      pdVar15 = (unsigned int *)0x800;
      _memset(local_64 + 0x314,0,0x800);
      puVar27 = extraout_r4_14;
      for (piVar31 = (int *)*puVar21; piVar31 != (int *)0x0; piVar31 = (int *)piVar31[4]) {
        pdVar15 = (dword *)*piVar31;
        in_r6 = (dword *)piVar31[1];
        ((int (*)())FUN_00079b00)(param_1,iVar19,pdVar15,in_r6);
        puVar27 = extraout_r4_15;
      }
      iVar19 = iVar19 + 1;
      puVar21 = puVar21 + 1;
    } while ((dword *)iVar19 != local_78);
  }
  piVar31 = local_68;
  if (((local_68 != (int *)0x0) && (piVar32 = local_6c, local_6c != (int *)0x0)) &&
     (*local_68 = 0, bVar1)) {
    puVar27 = param_1 + 0x2114;
    pdVar20 = (dword *)0x0;
    pdVar15 = local_74;
    do {
      if (*puVar27 != 0) {
        iVar19 = 0;
        iVar35 = 4;
        pdVar18 = pdVar15;
        do {
          uVar10 = *pdVar18;
          pdVar18 = pdVar18 + 1;
          iVar23 = *local_68 * 4 + iVar19;
          iVar19 = iVar19 + 1;
          local_6c[iVar23] = uVar10;
          iVar35 = iVar35 + -1;
        } while (iVar35 != 0);
        *local_68 = *local_68 + 1;
        piVar31 = local_6c;
        piVar32 = local_68;
      }
      pdVar20 = (dword *)((int)pdVar20 + 1);
      puVar27 = puVar27 + 1;
      pdVar15 = pdVar15 + 4;
      pdVar14 = local_78;
    } while (pdVar20 != local_78);
  }
  if ((*param_1 & 0x100) == 0) {
    iVar19 = ((int (*)())FUN_0007b0d0)(param_1,puVar27,pdVar15,in_r6,piVar31,piVar32,pdVar14,pdVar20);
    return iVar19;
  }
  return 0;
}

/* FUN_0007dcd0 @ 0x7dcd0 (88 bytes) */
int FUN_0007dcd0(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(((unsigned char *)0x000011b4) + param_1);
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0xc))(8,param_2);
  *puVar1 = param_2;
  puVar1[1] = *(undefined4 *)(iVar2 + 8);
  *(undefined4 **)(iVar2 + 8) = puVar1;
  return;
}

/* FUN_0007dd30 @ 0x7dd30 (160 bytes) */
int FUN_0007dd30(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(((unsigned char *)0x000011b4) + param_1);
  if ((iVar4 == 0) || (piVar2 = *(int **)(iVar4 + 8), piVar2 == (int *)0x0)) {
LAB_0007ddc0:
    uVar1 = 0;
  }
  else {
    if (*piVar2 == param_2) {
      *(int *)(iVar4 + 8) = piVar2[1];
    }
    else {
      do {
        piVar3 = piVar2;
        piVar2 = (int *)piVar3[1];
        if (piVar2 == (int *)0x0) goto LAB_0007ddc0;
      } while (param_2 != *piVar2);
      piVar3[1] = piVar2[1];
    }
    (**(code **)(param_1 + 0x18))(piVar2);
    uVar1 = 1;
  }
  return uVar1;
}

/* FUN_0007dde0 @ 0x7dde0 (3504 bytes) */
int FUN_0007dde0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  byte bVar7;
  float *pfVar8;
  undefined4 uVar9;
  byte bVar10;
  int iVar11;
  byte bVar12;
  byte bVar14;
  int iVar13;
  uint uVar15;
  uint uVar16;
  undefined4 *puVar17;
  uint uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  int *piVar21;
  undefined4 uVar22;
  int iVar23;
  undefined4 uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  byte bVar29;
  uint uVar28;
  uint uVar30;
  int iVar31;
  int iVar32;
  byte in_xer_so;
  bool bVar33;
  bool bVar34;
  bool bVar35;
  bool bVar36;
  bool bVar37;
  bool bVar38;
  bool bVar39;
  char cStack_88;
  char cStack_87;
  char cStack_86;
  char acStack_85 [13];
  int iStack_78;
  undefined4 uStack_70;
  undefined4 uStack_60;
  
  uVar16 = *(uint *)(param_2 + 0x14);
  if (uVar16 != 0) {
    uVar15 = 0;
    uVar24 = 0x87df;
LAB_0007de3c:
    iVar11 = *(int *)(param_2 + 0x18);
    iVar31 = uVar15 * 0x74 + iVar11;
    if ((((((*(int *)(uVar15 * 0x74 + iVar11) == 0x8799) && (*(int *)(iVar31 + 0x20) == 2)) &&
          (*(int *)(iVar31 + 0x28) == 0x87d5)) &&
         ((*(int *)(iVar31 + 0x2c) == 0x87d6 && (*(int *)(iVar31 + 0x30) == 0x87d7)))) &&
        (*(int *)(iVar31 + 0x34) == 0x87d8)) &&
       ((iVar23 = *(int *)(iVar31 + 0x24) * 0x54 + *(int *)(param_2 + 0x20),
        *(int *)(iVar23 + 0x28) == 0x87c3 && (*(int *)(iVar23 + 0x24) == 0x87bf)))) {
      pfVar8 = *(float **)(iVar23 + 0x38);
      fVar2 = *pfVar8;
      fVar3 = pfVar8[3];
      fVar4 = pfVar8[1];
      fVar5 = pfVar8[2];
      uStack_60 = 0;
      bVar33 = fVar2 == 1.0;
      bVar34 = fVar4 == 1.0;
      bVar35 = fVar3 == 1.0;
      uVar30 = (uint)(byte)((fVar2 == 0.0) << 2 | (fVar2 != 0.0) << 1 | in_xer_so & 1);
      iStack_78 = uVar30 << 0x1c;
      bVar36 = fVar5 == 1.0;
      bVar37 = fVar5 == 0.0;
      bVar38 = fVar4 == 0.0;
      bVar39 = fVar3 == 0.0;
      if (((((!(bool)((byte)((uVar30 << 0xc) >> 8) >> 5 & 1)) ||
            (((bVar33 || (fVar2 == -1.0)) || (bVar38)))) ||
           (((bVar34 || (fVar4 == -1.0)) || (bVar37)))) ||
          (((bVar36 || (fVar5 == -1.0)) || ((bVar39 || ((bVar35 || (fVar3 == -1.0)))))))) &&
         (uVar30 = uVar15 + 1, uVar30 < uVar16)) {
        iVar32 = uVar30 * 0x74;
        bVar6 = false;
        uVar18 = uVar30;
        iVar23 = iVar32;
        do {
          iVar13 = iVar23 + iVar11;
          if (((*(int *)(iVar23 + iVar11) == 0x879b) && (*(int *)(iVar13 + 4) == 2)) &&
             (*(int *)(iVar13 + 8) == *(int *)(iVar31 + 8))) {
            bVar1 = *(int *)(iVar13 + 0xc) != 0;
            bVar10 = (byte)((uint)iStack_78 >> 0x18);
            if (((bVar1) || (!(bool)(bVar10 >> 5 & 1))) || ((bVar33 || (bVar12 = 0, fVar2 == -1.0)))
               ) {
              bVar12 = 1;
            }
            if (((*(int *)(iVar13 + 0x10) != 0) || (bVar38)) ||
               ((bVar34 || (bVar14 = 0, fVar4 == -1.0)))) {
              bVar14 = 1;
            }
            if ((((*(int *)(iVar13 + 0x14) != 0) || (bVar37)) || (bVar36)) ||
               (bVar29 = 0, fVar5 == -1.0)) {
              bVar29 = 1;
            }
            if (((*(int *)(iVar13 + 0x18) != 0) || (bVar39)) ||
               ((bVar35 || (bVar7 = 0, fVar3 == -1.0)))) {
              bVar7 = 1;
            }
            bVar6 = (bool)(bVar7 & bVar29 & bVar14 & bVar12);
            if (bVar6) {
              if (!bVar1) {
                *(undefined4 *)(iVar13 + 0xc) = 1;
                if ((bool)(bVar10 >> 5 & 1)) {
                  if (bVar33) {
                    *(undefined4 *)(iVar13 + 0x28) = 0x87de;
                  }
                  else {
                    *(undefined4 *)(iVar13 + 0x28) = uVar24;
                  }
                }
                else {
                  *(undefined4 *)(iVar13 + 0x28) = 0x87dd;
                }
              }
              if (*(int *)(iVar13 + 0x10) == 0) {
                *(undefined4 *)(iVar13 + 0x10) = 1;
                if (bVar38) {
                  *(undefined4 *)(iVar13 + 0x2c) = 0x87dd;
                }
                else if (bVar34) {
                  *(undefined4 *)(iVar13 + 0x2c) = 0x87de;
                }
                else {
                  *(undefined4 *)(iVar13 + 0x2c) = uVar24;
                }
              }
              if (*(int *)(iVar13 + 0x14) == 0) {
                *(undefined4 *)(iVar13 + 0x14) = 1;
                if (bVar37) {
                  *(undefined4 *)(iVar13 + 0x30) = 0x87dd;
                }
                else if (bVar36) {
                  *(undefined4 *)(iVar13 + 0x30) = 0x87de;
                }
                else {
                  *(undefined4 *)(iVar13 + 0x30) = uVar24;
                }
              }
              if (*(int *)(iVar13 + 0x18) == 0) {
                *(undefined4 *)(iVar13 + 0x18) = 1;
                if (bVar39) {
                  *(undefined4 *)(iVar13 + 0x34) = 0x87dd;
                  bVar1 = true;
                  uVar16 = *(uint *)(param_2 + 0x14);
                }
                else if (bVar35) {
                  *(undefined4 *)(iVar13 + 0x34) = 0x87de;
                  bVar1 = true;
                  uVar16 = *(uint *)(param_2 + 0x14);
                }
                else {
                  *(undefined4 *)(iVar13 + 0x34) = uVar24;
                  bVar1 = true;
                  uVar16 = *(uint *)(param_2 + 0x14);
                }
                goto LAB_0007e2bc;
              }
              uVar16 = *(uint *)(param_2 + 0x14);
            }
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
LAB_0007e2bc:
          uVar18 = uVar18 + 1;
          if ((uVar16 <= uVar18) || (iVar23 = iVar23 + 0x74, bVar1)) goto LAB_0007e2d4;
          iVar11 = *(int *)(param_2 + 0x18);
        } while( true );
      }
    }
    goto LAB_0007e2e0;
  }
LAB_0007e330:
  uVar15 = 0;
  do {
    bVar33 = false;
    for (uVar30 = uVar16; 1 < uVar30; uVar30 = uVar30 - 1) {
      iVar31 = uVar30 * 0x74;
      iVar11 = *(int *)(param_2 + 0x18) + iVar31;
      if (((((*(int *)(iVar11 + -0x74) == 0x879b) || (*(int *)(iVar11 + -0x74) == 0x8799)) &&
           (*(int *)(iVar11 + -0x54) == 2)) &&
          ((*(char *)(iVar11 + -0x3c) == '\0' &&
           ((*(char *)(param_2 + 0x7b) == '\0' ||
            (*(int *)(*(int *)(iVar11 + -0x6c) * 0x54 + *(int *)(param_2 + 0x20) + 0x28) != 0x87c4))
           )))) && ((*(int *)(iVar11 + -0x4c) == 0x87d5 &&
                    (((*(int *)(iVar11 + -0x48) == 0x87d6 && (*(int *)(iVar11 + -0x44) == 0x87d7))
                     && (*(int *)(iVar11 + -0x40) == 0x87d8)))))) {
        if (uVar30 < uVar16) {
          iVar23 = uVar16 - uVar30;
          piVar21 = (int *)(iVar11 + 0x20);
          bVar29 = 0;
          bVar10 = 0;
          bVar12 = 0;
          bVar14 = 0;
          bVar34 = true;
          do {
            if (((*piVar21 == 2) && (piVar21[1] == *(int *)(iVar11 + -0x50))) ||
               (((piVar21[7] == 2 && (piVar21[8] == *(int *)(iVar11 + -0x50))) ||
                ((piVar21[0xe] == 2 && (piVar21[0xf] == *(int *)(iVar11 + -0x50))))))) {
              bVar35 = true;
              bVar34 = false;
            }
            else {
              if ((piVar21[-7] == 2) && (piVar21[-6] == *(int *)(iVar11 + -0x50))) {
                bVar29 = bVar29 | *(byte *)((int)piVar21 + -0x11);
                bVar10 = bVar10 | *(byte *)((int)piVar21 + -0xd);
                bVar12 = bVar12 | *(byte *)((int)piVar21 + -9);
                bVar14 = bVar14 | *(byte *)((int)piVar21 + -5);
                if ((bVar29 != 0) && ((bVar10 != 0 && (bVar12 != 0)))) {
                  bVar35 = bVar14 != 0;
                  goto LAB_0007e530;
                }
              }
              bVar35 = false;
            }
LAB_0007e530:
            iVar23 = iVar23 + -1;
          } while ((iVar23 != 0) && (piVar21 = piVar21 + 0x1d, !bVar35));
          if (!bVar34) goto LAB_0007e760;
        }
        uVar18 = uVar30 - 1;
        if (uVar18 != 0) {
          uVar28 = 0;
          uVar27 = 0;
          uVar26 = 0;
          uVar25 = 0;
          bVar34 = false;
          do {
            iVar23 = *(int *)(param_2 + 0x18) + uVar18 * 0x74;
            bVar35 = *(int *)(iVar23 + -0x54) == 2;
            if ((((bVar35) && (*(int *)(iVar23 + -0x50) == *(int *)(iVar11 + -0x50))) ||
                ((bVar36 = *(int *)(iVar23 + -0x38) == 2, bVar36 &&
                 (*(int *)(iVar23 + -0x34) == *(int *)(iVar11 + -0x50))))) ||
               ((bVar37 = *(int *)(iVar23 + -0x1c) == 2, bVar37 &&
                (*(int *)(iVar23 + -0x18) == *(int *)(iVar11 + -0x50))))) {
              uVar15 = uVar18 - 1;
              bVar35 = true;
              bVar34 = true;
            }
            else if ((((bVar35) && (*(int *)(iVar23 + -0x50) == *(int *)(iVar11 + -0x6c))) ||
                     ((bVar36 && (*(int *)(iVar23 + -0x34) == *(int *)(iVar11 + -0x6c))))) ||
                    ((bVar37 && (*(int *)(iVar23 + -0x18) == *(int *)(iVar11 + -0x6c))))) {
              bVar35 = true;
              bVar34 = false;
            }
            else {
              bVar35 = false;
            }
            uVar18 = uVar18 - 1;
            if (((*(int *)(iVar23 + -0x74) != 0x879c) && (*(int *)(iVar23 + -0x70) == 2)) &&
               (*(int *)(iVar23 + -0x6c) == *(int *)(iVar11 + -0x50))) {
              uVar25 = uVar25 | *(byte *)(iVar23 + -0x65);
              uVar26 = uVar26 | *(byte *)(iVar23 + -0x61);
              uVar28 = uVar28 | *(byte *)(iVar23 + -0x59);
              uVar27 = uVar27 | *(byte *)(iVar23 + -0x5d);
              if (((*(uint *)(iVar11 + -0x68) <= uVar25) && (*(uint *)(iVar11 + -100) <= uVar26)) &&
                 ((*(uint *)(iVar11 + -0x60) <= uVar27 && (*(uint *)(iVar11 + -0x5c) <= uVar28)))) {
                bVar35 = true;
                bVar34 = true;
                uVar15 = uVar18;
              }
            }
          } while ((uVar18 != 0) && (!bVar35));
          if (bVar34) {
            FUN_000b72d0(param_2 + 0x1c,iVar11 + -0x74,*(undefined4 *)(iVar11 + -0x50),&cStack_88,
                         &cStack_87,&cStack_86,acStack_85);
            if (((((cStack_88 == '\0') || (uVar25 != 0)) && ((cStack_87 == '\0' || (uVar26 != 0))))
                && ((cStack_86 == '\0' || (uVar27 != 0)))) &&
               ((acStack_85[0] == '\0' || (uVar28 != 0)))) {
              if (uVar15 < uVar30) {
                iVar23 = uVar30 - uVar15;
                iVar32 = uVar15 * 0x74;
                do {
                  iVar13 = iVar32 + *(int *)(param_2 + 0x18);
                  if (((*(int *)(iVar32 + *(int *)(param_2 + 0x18)) != 0x879c) &&
                      (*(int *)(iVar13 + 4) == 2)) &&
                     (*(int *)(iVar13 + 8) == *(int *)(iVar11 + -0x50))) {
                    uVar24 = *(undefined4 *)(iVar11 + -0x6c);
                    *(undefined4 *)(iVar13 + 4) = *(undefined4 *)(iVar11 + -0x70);
                    *(undefined4 *)(iVar13 + 8) = uVar24;
                    uVar16 = *(uint *)(iVar11 + -0x5c);
                    uVar25 = *(uint *)(iVar11 + -100);
                    uVar18 = *(uint *)(iVar11 + -0x60);
                    *(uint *)(iVar13 + 0xc) = *(uint *)(iVar13 + 0xc) & *(uint *)(iVar11 + -0x68);
                    *(uint *)(iVar13 + 0x10) = *(uint *)(iVar13 + 0x10) & uVar25;
                    *(uint *)(iVar13 + 0x14) = *(uint *)(iVar13 + 0x14) & uVar18;
                    *(uint *)(iVar13 + 0x18) = *(uint *)(iVar13 + 0x18) & uVar16;
                  }
                  iVar32 = iVar32 + 0x74;
                  iVar23 = iVar23 + -1;
                } while (iVar23 != 0);
              }
              uVar16 = *(uint *)(param_2 + 0x14);
              uVar18 = uVar30;
              if (uVar30 < uVar16) {
                do {
                  uVar18 = uVar18 + 1;
                  iVar11 = iVar31 + *(int *)(param_2 + 0x18);
                  iVar31 = iVar31 + 0x74;
                  _memcpy(iVar11 + -0x74,iVar11,0x74);
                  uVar16 = *(uint *)(param_2 + 0x14);
                } while (uVar18 < uVar16);
              }
              uVar16 = uVar16 - 1;
              bVar33 = true;
              *(uint *)(param_2 + 0x14) = uVar16;
            }
            else {
              uVar16 = *(uint *)(param_2 + 0x14);
            }
          }
        }
      }
LAB_0007e760: ;
    }
    if (uVar16 != 0) {
      uVar30 = 0;
      do {
        iVar31 = *(int *)(param_2 + 0x18);
        iVar23 = uVar30 * 0x74;
        iVar11 = *(int *)(iVar31 + iVar23);
        iVar32 = iVar31 + iVar23;
        if ((((iVar11 == 0x879b) || (iVar11 == 0x8799)) || (iVar11 == 0x879a)) &&
           ((((*(char *)(iVar32 + 0x38) == '\0' && (*(int *)(iVar32 + 4) == 2)) &&
             ((*(char *)(param_2 + 0x7b) == '\0' ||
              (*(int *)(*(int *)(iVar32 + 8) * 0x54 + *(int *)(param_2 + 0x20) + 0x28) != 0x87c4))))
            && ((((*(int *)(iVar32 + 0xc) != 0 && (*(int *)(iVar32 + 0x10) != 0)) &&
                 (*(int *)(iVar32 + 0x14) != 0)) && (*(int *)(iVar32 + 0x18) != 0)))))) {
          uVar25 = uVar30 + 1;
          uVar18 = uVar25;
          uVar15 = uVar16;
          if (uVar25 < uVar16) {
            bVar34 = true;
            do {
              iVar11 = iVar31 + uVar18 * 0x74;
              if (*(int *)(iVar11 + 4) == 2) {
                iVar11 = *(int *)(iVar11 + 8);
                bVar35 = iVar11 == *(int *)(iVar32 + 8);
                if (bVar35) {
                  uVar15 = uVar18 + 1;
                }
                if (*(int *)(iVar32 + 0x24) == iVar11) {
                  bVar35 = true;
                  bVar34 = false;
                }
              }
              else {
                bVar35 = false;
              }
              uVar18 = uVar18 + 1;
            } while ((uVar18 < uVar16) && (!bVar35));
            if (!bVar34) goto LAB_00080860;
          }
          bVar34 = true;
          iVar11 = iVar31 + uVar18 * 0x74;
          bVar10 = *(byte *)(iVar11 + -0x59);
          bVar12 = *(byte *)(iVar11 + -0x65);
          bVar14 = *(byte *)(iVar11 + -0x61);
          bVar29 = *(byte *)(iVar11 + -0x5d);
          if (uVar15 < uVar16) {
            iVar11 = uVar15 * 0x74;
            uVar18 = uVar15;
            while( true ) {
              iVar31 = iVar11 + iVar31;
              if ((((*(int *)(iVar31 + 0x20) == 2) &&
                   (iVar13 = *(int *)(iVar32 + 8), *(int *)(iVar31 + 0x24) == iVar13)) ||
                  ((*(int *)(iVar31 + 0x3c) == 2 &&
                   (iVar13 = *(int *)(iVar32 + 8), *(int *)(iVar31 + 0x40) == iVar13)))) ||
                 ((*(int *)(iVar31 + 0x58) == 2 &&
                  (iVar13 = *(int *)(iVar32 + 8), *(int *)(iVar31 + 0x5c) == iVar13)))) {
                FUN_000b72d0(param_2 + 0x1c,iVar31,iVar13,&cStack_88,&cStack_87,&cStack_86,
                             acStack_85);
                if (((cStack_88 == '\0') || (bVar12 != 0)) &&
                   ((((cStack_87 == '\0' || (bVar14 != 0)) && ((cStack_86 == '\0' || (bVar29 != 0)))
                     ) && ((acStack_85[0] == '\0' || (bVar10 != 0)))))) {
                  uVar16 = *(uint *)(param_2 + 0x14);
                }
                else {
                  uVar16 = *(uint *)(param_2 + 0x14);
                  bVar34 = false;
                }
              }
              if ((*(int *)(iVar31 + 4) == 2) && (*(int *)(iVar31 + 8) == *(int *)(iVar32 + 8))) {
                bVar10 = bVar10 | *(byte *)(iVar31 + 0x1b);
                bVar12 = bVar12 | *(byte *)(iVar31 + 0xf);
                bVar14 = bVar14 | *(byte *)(iVar31 + 0x13);
                bVar29 = bVar29 | *(byte *)(iVar31 + 0x17);
              }
              uVar18 = uVar18 + 1;
              iVar11 = iVar11 + 0x74;
              if (uVar16 <= uVar18) break;
              iVar31 = *(int *)(param_2 + 0x18);
            }
            if (!bVar34) goto LAB_00080860;
          }
          if (uVar25 < uVar15) {
            iVar31 = uVar25 * 0x74;
            iVar11 = uVar15 - uVar25;
            do {
              iVar13 = iVar31 + *(int *)(param_2 + 0x18);
              if ((*(int *)(iVar13 + 0x20) == 2) &&
                 (*(int *)(iVar13 + 0x24) == *(int *)(iVar32 + 8))) {
                uVar24 = *(undefined4 *)(iVar13 + 0x28);
                puVar17 = (undefined4 *)(iVar32 + 0x28);
                *(undefined4 *)(iVar13 + 0x24) = *(undefined4 *)(iVar32 + 0x24);
                switch(uVar24) {
                case 0x87d5:
                  uVar24 = *puVar17;
                  break;
                case 0x87d6:
                  uVar24 = *(undefined4 *)(iVar32 + 0x2c);
                  break;
                case 0x87d7:
                  uVar24 = *(undefined4 *)(iVar32 + 0x30);
                  break;
                case 0x87d8:
                  uVar24 = *(undefined4 *)(iVar32 + 0x34);
                  break;
                case 0x87d9:
                  uVar24 = *puVar17;
                  switch(uVar24) {
                  case 0x87d5:
code_r0x0007ed7c:
                    uVar24 = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007ed70:
                    uVar24 = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007eddc:
                    uVar24 = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007edd0:
                    uVar24 = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007edc4:
                    uVar24 = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007edb8:
                    uVar24 = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007edac:
                    uVar24 = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007eda0:
                    uVar24 = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007ed94:
                    uVar24 = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007ed88:
                    uVar24 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar24 = *(undefined4 *)(iVar32 + 0x2c);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x0007ed7c;
                  case 0x87d6:
                    goto code_r0x0007ed70;
                  case 0x87d7:
                    goto code_r0x0007eddc;
                  case 0x87d8:
                    goto code_r0x0007edd0;
                  case 0x87d9:
                    goto code_r0x0007edc4;
                  case 0x87da:
                    goto code_r0x0007edb8;
                  case 0x87db:
                    goto code_r0x0007edac;
                  case 0x87dc:
                    goto code_r0x0007eda0;
                  case 0x87de:
                    goto code_r0x0007ed94;
                  case 0x87df:
                    goto code_r0x0007ed88;
                  }
                  break;
                case 0x87db:
                  uVar24 = *(undefined4 *)(iVar32 + 0x30);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x0007ed7c;
                  case 0x87d6:
                    goto code_r0x0007ed70;
                  case 0x87d7:
                    goto code_r0x0007eddc;
                  case 0x87d8:
                    goto code_r0x0007edd0;
                  case 0x87d9:
                    goto code_r0x0007edc4;
                  case 0x87da:
                    goto code_r0x0007edb8;
                  case 0x87db:
                    goto code_r0x0007edac;
                  case 0x87dc:
                    goto code_r0x0007eda0;
                  case 0x87de:
                    goto code_r0x0007ed94;
                  case 0x87df:
                    goto code_r0x0007ed88;
                  }
                  break;
                case 0x87dc:
                  uVar24 = *(undefined4 *)(iVar32 + 0x34);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x0007ed7c;
                  case 0x87d6:
                    goto code_r0x0007ed70;
                  case 0x87d7:
                    goto code_r0x0007eddc;
                  case 0x87d8:
                    goto code_r0x0007edd0;
                  case 0x87d9:
                    goto code_r0x0007edc4;
                  case 0x87da:
                    goto code_r0x0007edb8;
                  case 0x87db:
                    goto code_r0x0007edac;
                  case 0x87dc:
                    goto code_r0x0007eda0;
                  case 0x87de:
                    goto code_r0x0007ed94;
                  case 0x87df:
                    goto code_r0x0007ed88;
                  }
                }
                uVar9 = *(undefined4 *)(iVar13 + 0x2c);
                *(undefined4 *)(iVar13 + 0x28) = uVar24;
                switch(uVar9) {
                case 0x87d5:
                  uVar9 = *puVar17;
                  break;
                case 0x87d6:
                  uVar9 = *(undefined4 *)(iVar32 + 0x2c);
                  break;
                case 0x87d7:
                  uVar9 = *(undefined4 *)(iVar32 + 0x30);
                  break;
                case 0x87d8:
                  uVar9 = *(undefined4 *)(iVar32 + 0x34);
                  break;
                case 0x87d9:
                  uVar9 = *puVar17;
                  switch(uVar9) {
                  case 0x87d5:
code_r0x0007efd4:
                    uVar9 = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007efc8:
                    uVar9 = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007f034:
                    uVar9 = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007f028:
                    uVar9 = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007f01c:
                    uVar9 = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007f010:
                    uVar9 = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007f004:
                    uVar9 = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007eff8:
                    uVar9 = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007efec:
                    uVar9 = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007efe0:
                    uVar9 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar9 = *(undefined4 *)(iVar32 + 0x2c);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x0007efd4;
                  case 0x87d6:
                    goto code_r0x0007efc8;
                  case 0x87d7:
                    goto code_r0x0007f034;
                  case 0x87d8:
                    goto code_r0x0007f028;
                  case 0x87d9:
                    goto code_r0x0007f01c;
                  case 0x87da:
                    goto code_r0x0007f010;
                  case 0x87db:
                    goto code_r0x0007f004;
                  case 0x87dc:
                    goto code_r0x0007eff8;
                  case 0x87de:
                    goto code_r0x0007efec;
                  case 0x87df:
                    goto code_r0x0007efe0;
                  }
                  break;
                case 0x87db:
                  uVar9 = *(undefined4 *)(iVar32 + 0x30);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x0007efd4;
                  case 0x87d6:
                    goto code_r0x0007efc8;
                  case 0x87d7:
                    goto code_r0x0007f034;
                  case 0x87d8:
                    goto code_r0x0007f028;
                  case 0x87d9:
                    goto code_r0x0007f01c;
                  case 0x87da:
                    goto code_r0x0007f010;
                  case 0x87db:
                    goto code_r0x0007f004;
                  case 0x87dc:
                    goto code_r0x0007eff8;
                  case 0x87de:
                    goto code_r0x0007efec;
                  case 0x87df:
                    goto code_r0x0007efe0;
                  }
                  break;
                case 0x87dc:
                  uVar9 = *(undefined4 *)(iVar32 + 0x34);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x0007efd4;
                  case 0x87d6:
                    goto code_r0x0007efc8;
                  case 0x87d7:
                    goto code_r0x0007f034;
                  case 0x87d8:
                    goto code_r0x0007f028;
                  case 0x87d9:
                    goto code_r0x0007f01c;
                  case 0x87da:
                    goto code_r0x0007f010;
                  case 0x87db:
                    goto code_r0x0007f004;
                  case 0x87dc:
                    goto code_r0x0007eff8;
                  case 0x87de:
                    goto code_r0x0007efec;
                  case 0x87df:
                    goto code_r0x0007efe0;
                  }
                }
                uVar24 = *(undefined4 *)(iVar13 + 0x30);
                *(undefined4 *)(iVar13 + 0x2c) = uVar9;
                switch(uVar24) {
                case 0x87d5:
                  uVar24 = *puVar17;
                  break;
                case 0x87d6:
                  uVar24 = *(undefined4 *)(iVar32 + 0x2c);
                  break;
                case 0x87d7:
                  uVar24 = *(undefined4 *)(iVar32 + 0x30);
                  break;
                case 0x87d8:
                  uVar24 = *(undefined4 *)(iVar32 + 0x34);
                  break;
                case 0x87d9:
                  uVar24 = *puVar17;
                  switch(uVar24) {
                  case 0x87d5:
code_r0x0007f22c:
                    uVar24 = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007f220:
                    uVar24 = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007f28c:
                    uVar24 = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007f280:
                    uVar24 = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007f274:
                    uVar24 = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007f268:
                    uVar24 = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007f25c:
                    uVar24 = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007f250:
                    uVar24 = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007f244:
                    uVar24 = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007f238:
                    uVar24 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar24 = *(undefined4 *)(iVar32 + 0x2c);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x0007f22c;
                  case 0x87d6:
                    goto code_r0x0007f220;
                  case 0x87d7:
                    goto code_r0x0007f28c;
                  case 0x87d8:
                    goto code_r0x0007f280;
                  case 0x87d9:
                    goto code_r0x0007f274;
                  case 0x87da:
                    goto code_r0x0007f268;
                  case 0x87db:
                    goto code_r0x0007f25c;
                  case 0x87dc:
                    goto code_r0x0007f250;
                  case 0x87de:
                    goto code_r0x0007f244;
                  case 0x87df:
                    goto code_r0x0007f238;
                  }
                  break;
                case 0x87db:
                  uVar24 = *(undefined4 *)(iVar32 + 0x30);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x0007f22c;
                  case 0x87d6:
                    goto code_r0x0007f220;
                  case 0x87d7:
                    goto code_r0x0007f28c;
                  case 0x87d8:
                    goto code_r0x0007f280;
                  case 0x87d9:
                    goto code_r0x0007f274;
                  case 0x87da:
                    goto code_r0x0007f268;
                  case 0x87db:
                    goto code_r0x0007f25c;
                  case 0x87dc:
                    goto code_r0x0007f250;
                  case 0x87de:
                    goto code_r0x0007f244;
                  case 0x87df:
                    goto code_r0x0007f238;
                  }
                  break;
                case 0x87dc:
                  uVar24 = *(undefined4 *)(iVar32 + 0x34);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x0007f22c;
                  case 0x87d6:
                    goto code_r0x0007f220;
                  case 0x87d7:
                    goto code_r0x0007f28c;
                  case 0x87d8:
                    goto code_r0x0007f280;
                  case 0x87d9:
                    goto code_r0x0007f274;
                  case 0x87da:
                    goto code_r0x0007f268;
                  case 0x87db:
                    goto code_r0x0007f25c;
                  case 0x87dc:
                    goto code_r0x0007f250;
                  case 0x87de:
                    goto code_r0x0007f244;
                  case 0x87df:
                    goto code_r0x0007f238;
                  }
                }
                uVar9 = *(undefined4 *)(iVar13 + 0x34);
                *(undefined4 *)(iVar13 + 0x30) = uVar24;
                switch(uVar9) {
                case 0x87d5:
                  uVar9 = *puVar17;
                  break;
                case 0x87d6:
                  uVar9 = *(undefined4 *)(iVar32 + 0x2c);
                  break;
                case 0x87d7:
                  uVar9 = *(undefined4 *)(iVar32 + 0x30);
                  break;
                case 0x87d8:
                  uVar9 = *(undefined4 *)(iVar32 + 0x34);
                  break;
                case 0x87d9:
                  uVar9 = *puVar17;
                  switch(uVar9) {
                  case 0x87d5:
code_r0x0007f484:
                    uVar9 = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007f478:
                    uVar9 = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007f4e4:
                    uVar9 = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007f4d8:
                    uVar9 = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007f4cc:
                    uVar9 = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007f4c0:
                    uVar9 = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007f4b4:
                    uVar9 = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007f4a8:
                    uVar9 = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007f49c:
                    uVar9 = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007f490:
                    uVar9 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar9 = *(undefined4 *)(iVar32 + 0x2c);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x0007f484;
                  case 0x87d6:
                    goto code_r0x0007f478;
                  case 0x87d7:
                    goto code_r0x0007f4e4;
                  case 0x87d8:
                    goto code_r0x0007f4d8;
                  case 0x87d9:
                    goto code_r0x0007f4cc;
                  case 0x87da:
                    goto code_r0x0007f4c0;
                  case 0x87db:
                    goto code_r0x0007f4b4;
                  case 0x87dc:
                    goto code_r0x0007f4a8;
                  case 0x87de:
                    goto code_r0x0007f49c;
                  case 0x87df:
                    goto code_r0x0007f490;
                  }
                  break;
                case 0x87db:
                  uVar9 = *(undefined4 *)(iVar32 + 0x30);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x0007f484;
                  case 0x87d6:
                    goto code_r0x0007f478;
                  case 0x87d7:
                    goto code_r0x0007f4e4;
                  case 0x87d8:
                    goto code_r0x0007f4d8;
                  case 0x87d9:
                    goto code_r0x0007f4cc;
                  case 0x87da:
                    goto code_r0x0007f4c0;
                  case 0x87db:
                    goto code_r0x0007f4b4;
                  case 0x87dc:
                    goto code_r0x0007f4a8;
                  case 0x87de:
                    goto code_r0x0007f49c;
                  case 0x87df:
                    goto code_r0x0007f490;
                  }
                  break;
                case 0x87dc:
                  uVar9 = *(undefined4 *)(iVar32 + 0x34);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x0007f484;
                  case 0x87d6:
                    goto code_r0x0007f478;
                  case 0x87d7:
                    goto code_r0x0007f4e4;
                  case 0x87d8:
                    goto code_r0x0007f4d8;
                  case 0x87d9:
                    goto code_r0x0007f4cc;
                  case 0x87da:
                    goto code_r0x0007f4c0;
                  case 0x87db:
                    goto code_r0x0007f4b4;
                  case 0x87dc:
                    goto code_r0x0007f4a8;
                  case 0x87de:
                    goto code_r0x0007f49c;
                  case 0x87df:
                    goto code_r0x0007f490;
                  }
                }
                *(undefined4 *)(iVar13 + 0x34) = uVar9;
              }
              if ((*(int *)(iVar13 + 0x3c) == 2) &&
                 (*(int *)(iVar13 + 0x40) == *(int *)(iVar32 + 8))) {
                uVar24 = *(undefined4 *)(iVar13 + 0x44);
                puVar17 = (undefined4 *)(iVar32 + 0x28);
                *(undefined4 *)(iVar13 + 0x40) = *(undefined4 *)(iVar32 + 0x24);
                switch(uVar24) {
                case 0x87d5:
                  uVar24 = *puVar17;
                  break;
                case 0x87d6:
                  uVar24 = *(undefined4 *)(iVar32 + 0x2c);
                  break;
                case 0x87d7:
                  uVar24 = *(undefined4 *)(iVar32 + 0x30);
                  break;
                case 0x87d8:
                  uVar24 = *(undefined4 *)(iVar32 + 0x34);
                  break;
                case 0x87d9:
                  uVar24 = *puVar17;
                  switch(uVar24) {
                  case 0x87d5:
code_r0x0007f708:
                    uVar24 = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007f6fc:
                    uVar24 = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007f768:
                    uVar24 = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007f75c:
                    uVar24 = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007f750:
                    uVar24 = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007f744:
                    uVar24 = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007f738:
                    uVar24 = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007f72c:
                    uVar24 = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007f720:
                    uVar24 = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007f714:
                    uVar24 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar24 = *(undefined4 *)(iVar32 + 0x2c);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x0007f708;
                  case 0x87d6:
                    goto code_r0x0007f6fc;
                  case 0x87d7:
                    goto code_r0x0007f768;
                  case 0x87d8:
                    goto code_r0x0007f75c;
                  case 0x87d9:
                    goto code_r0x0007f750;
                  case 0x87da:
                    goto code_r0x0007f744;
                  case 0x87db:
                    goto code_r0x0007f738;
                  case 0x87dc:
                    goto code_r0x0007f72c;
                  case 0x87de:
                    goto code_r0x0007f720;
                  case 0x87df:
                    goto code_r0x0007f714;
                  }
                  break;
                case 0x87db:
                  uVar24 = *(undefined4 *)(iVar32 + 0x30);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x0007f708;
                  case 0x87d6:
                    goto code_r0x0007f6fc;
                  case 0x87d7:
                    goto code_r0x0007f768;
                  case 0x87d8:
                    goto code_r0x0007f75c;
                  case 0x87d9:
                    goto code_r0x0007f750;
                  case 0x87da:
                    goto code_r0x0007f744;
                  case 0x87db:
                    goto code_r0x0007f738;
                  case 0x87dc:
                    goto code_r0x0007f72c;
                  case 0x87de:
                    goto code_r0x0007f720;
                  case 0x87df:
                    goto code_r0x0007f714;
                  }
                  break;
                case 0x87dc:
                  uVar24 = *(undefined4 *)(iVar32 + 0x34);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x0007f708;
                  case 0x87d6:
                    goto code_r0x0007f6fc;
                  case 0x87d7:
                    goto code_r0x0007f768;
                  case 0x87d8:
                    goto code_r0x0007f75c;
                  case 0x87d9:
                    goto code_r0x0007f750;
                  case 0x87da:
                    goto code_r0x0007f744;
                  case 0x87db:
                    goto code_r0x0007f738;
                  case 0x87dc:
                    goto code_r0x0007f72c;
                  case 0x87de:
                    goto code_r0x0007f720;
                  case 0x87df:
                    goto code_r0x0007f714;
                  }
                }
                uVar9 = *(undefined4 *)(iVar13 + 0x48);
                *(undefined4 *)(iVar13 + 0x44) = uVar24;
                switch(uVar9) {
                case 0x87d5:
                  uVar9 = *puVar17;
                  break;
                case 0x87d6:
                  uVar9 = *(undefined4 *)(iVar32 + 0x2c);
                  break;
                case 0x87d7:
                  uVar9 = *(undefined4 *)(iVar32 + 0x30);
                  break;
                case 0x87d8:
                  uVar9 = *(undefined4 *)(iVar32 + 0x34);
                  break;
                case 0x87d9:
                  uVar9 = *puVar17;
                  switch(uVar9) {
                  case 0x87d5:
code_r0x0007f960:
                    uVar9 = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007f954:
                    uVar9 = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007f9c0:
                    uVar9 = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007f9b4:
                    uVar9 = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007f9a8:
                    uVar9 = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007f99c:
                    uVar9 = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007f990:
                    uVar9 = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007f984:
                    uVar9 = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007f978:
                    uVar9 = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007f96c:
                    uVar9 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar9 = *(undefined4 *)(iVar32 + 0x2c);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x0007f960;
                  case 0x87d6:
                    goto code_r0x0007f954;
                  case 0x87d7:
                    goto code_r0x0007f9c0;
                  case 0x87d8:
                    goto code_r0x0007f9b4;
                  case 0x87d9:
                    goto code_r0x0007f9a8;
                  case 0x87da:
                    goto code_r0x0007f99c;
                  case 0x87db:
                    goto code_r0x0007f990;
                  case 0x87dc:
                    goto code_r0x0007f984;
                  case 0x87de:
                    goto code_r0x0007f978;
                  case 0x87df:
                    goto code_r0x0007f96c;
                  }
                  break;
                case 0x87db:
                  uVar9 = *(undefined4 *)(iVar32 + 0x30);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x0007f960;
                  case 0x87d6:
                    goto code_r0x0007f954;
                  case 0x87d7:
                    goto code_r0x0007f9c0;
                  case 0x87d8:
                    goto code_r0x0007f9b4;
                  case 0x87d9:
                    goto code_r0x0007f9a8;
                  case 0x87da:
                    goto code_r0x0007f99c;
                  case 0x87db:
                    goto code_r0x0007f990;
                  case 0x87dc:
                    goto code_r0x0007f984;
                  case 0x87de:
                    goto code_r0x0007f978;
                  case 0x87df:
                    goto code_r0x0007f96c;
                  }
                  break;
                case 0x87dc:
                  uVar9 = *(undefined4 *)(iVar32 + 0x34);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x0007f960;
                  case 0x87d6:
                    goto code_r0x0007f954;
                  case 0x87d7:
                    goto code_r0x0007f9c0;
                  case 0x87d8:
                    goto code_r0x0007f9b4;
                  case 0x87d9:
                    goto code_r0x0007f9a8;
                  case 0x87da:
                    goto code_r0x0007f99c;
                  case 0x87db:
                    goto code_r0x0007f990;
                  case 0x87dc:
                    goto code_r0x0007f984;
                  case 0x87de:
                    goto code_r0x0007f978;
                  case 0x87df:
                    goto code_r0x0007f96c;
                  }
                }
                uVar24 = *(undefined4 *)(iVar13 + 0x4c);
                *(undefined4 *)(iVar13 + 0x48) = uVar9;
                switch(uVar24) {
                case 0x87d5:
                  uVar24 = *puVar17;
                  break;
                case 0x87d6:
                  uVar24 = *(undefined4 *)(iVar32 + 0x2c);
                  break;
                case 0x87d7:
                  uVar24 = *(undefined4 *)(iVar32 + 0x30);
                  break;
                case 0x87d8:
                  uVar24 = *(undefined4 *)(iVar32 + 0x34);
                  break;
                case 0x87d9:
                  uVar24 = *puVar17;
                  switch(uVar24) {
                  case 0x87d5:
code_r0x0007fbb8:
                    uVar24 = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007fbac:
                    uVar24 = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007fc18:
                    uVar24 = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007fc0c:
                    uVar24 = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007fc00:
                    uVar24 = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007fbf4:
                    uVar24 = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007fbe8:
                    uVar24 = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007fbdc:
                    uVar24 = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007fbd0:
                    uVar24 = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007fbc4:
                    uVar24 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar24 = *(undefined4 *)(iVar32 + 0x2c);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x0007fbb8;
                  case 0x87d6:
                    goto code_r0x0007fbac;
                  case 0x87d7:
                    goto code_r0x0007fc18;
                  case 0x87d8:
                    goto code_r0x0007fc0c;
                  case 0x87d9:
                    goto code_r0x0007fc00;
                  case 0x87da:
                    goto code_r0x0007fbf4;
                  case 0x87db:
                    goto code_r0x0007fbe8;
                  case 0x87dc:
                    goto code_r0x0007fbdc;
                  case 0x87de:
                    goto code_r0x0007fbd0;
                  case 0x87df:
                    goto code_r0x0007fbc4;
                  }
                  break;
                case 0x87db:
                  uVar24 = *(undefined4 *)(iVar32 + 0x30);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x0007fbb8;
                  case 0x87d6:
                    goto code_r0x0007fbac;
                  case 0x87d7:
                    goto code_r0x0007fc18;
                  case 0x87d8:
                    goto code_r0x0007fc0c;
                  case 0x87d9:
                    goto code_r0x0007fc00;
                  case 0x87da:
                    goto code_r0x0007fbf4;
                  case 0x87db:
                    goto code_r0x0007fbe8;
                  case 0x87dc:
                    goto code_r0x0007fbdc;
                  case 0x87de:
                    goto code_r0x0007fbd0;
                  case 0x87df:
                    goto code_r0x0007fbc4;
                  }
                  break;
                case 0x87dc:
                  uVar24 = *(undefined4 *)(iVar32 + 0x34);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x0007fbb8;
                  case 0x87d6:
                    goto code_r0x0007fbac;
                  case 0x87d7:
                    goto code_r0x0007fc18;
                  case 0x87d8:
                    goto code_r0x0007fc0c;
                  case 0x87d9:
                    goto code_r0x0007fc00;
                  case 0x87da:
                    goto code_r0x0007fbf4;
                  case 0x87db:
                    goto code_r0x0007fbe8;
                  case 0x87dc:
                    goto code_r0x0007fbdc;
                  case 0x87de:
                    goto code_r0x0007fbd0;
                  case 0x87df:
                    goto code_r0x0007fbc4;
                  }
                }
                uVar9 = *(undefined4 *)(iVar13 + 0x50);
                *(undefined4 *)(iVar13 + 0x4c) = uVar24;
                switch(uVar9) {
                case 0x87d5:
                  uVar9 = *puVar17;
                  break;
                case 0x87d6:
                  uVar9 = *(undefined4 *)(iVar32 + 0x2c);
                  break;
                case 0x87d7:
                  uVar9 = *(undefined4 *)(iVar32 + 0x30);
                  break;
                case 0x87d8:
                  uVar9 = *(undefined4 *)(iVar32 + 0x34);
                  break;
                case 0x87d9:
                  uVar9 = *puVar17;
                  switch(uVar9) {
                  case 0x87d5:
code_r0x0007fe10:
                    uVar9 = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x0007fe04:
                    uVar9 = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0007fe70:
                    uVar9 = 0x87db;
                    break;
                  case 0x87d8:
code_r0x0007fe64:
                    uVar9 = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0007fe58:
                    uVar9 = 0x87d5;
                    break;
                  case 0x87da:
code_r0x0007fe4c:
                    uVar9 = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0007fe40:
                    uVar9 = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x0007fe34:
                    uVar9 = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0007fe28:
                    uVar9 = 0x87df;
                    break;
                  case 0x87df:
code_r0x0007fe1c:
                    uVar9 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar9 = *(undefined4 *)(iVar32 + 0x2c);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x0007fe10;
                  case 0x87d6:
                    goto code_r0x0007fe04;
                  case 0x87d7:
                    goto code_r0x0007fe70;
                  case 0x87d8:
                    goto code_r0x0007fe64;
                  case 0x87d9:
                    goto code_r0x0007fe58;
                  case 0x87da:
                    goto code_r0x0007fe4c;
                  case 0x87db:
                    goto code_r0x0007fe40;
                  case 0x87dc:
                    goto code_r0x0007fe34;
                  case 0x87de:
                    goto code_r0x0007fe28;
                  case 0x87df:
                    goto code_r0x0007fe1c;
                  }
                  break;
                case 0x87db:
                  uVar9 = *(undefined4 *)(iVar32 + 0x30);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x0007fe10;
                  case 0x87d6:
                    goto code_r0x0007fe04;
                  case 0x87d7:
                    goto code_r0x0007fe70;
                  case 0x87d8:
                    goto code_r0x0007fe64;
                  case 0x87d9:
                    goto code_r0x0007fe58;
                  case 0x87da:
                    goto code_r0x0007fe4c;
                  case 0x87db:
                    goto code_r0x0007fe40;
                  case 0x87dc:
                    goto code_r0x0007fe34;
                  case 0x87de:
                    goto code_r0x0007fe28;
                  case 0x87df:
                    goto code_r0x0007fe1c;
                  }
                  break;
                case 0x87dc:
                  uVar9 = *(undefined4 *)(iVar32 + 0x34);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x0007fe10;
                  case 0x87d6:
                    goto code_r0x0007fe04;
                  case 0x87d7:
                    goto code_r0x0007fe70;
                  case 0x87d8:
                    goto code_r0x0007fe64;
                  case 0x87d9:
                    goto code_r0x0007fe58;
                  case 0x87da:
                    goto code_r0x0007fe4c;
                  case 0x87db:
                    goto code_r0x0007fe40;
                  case 0x87dc:
                    goto code_r0x0007fe34;
                  case 0x87de:
                    goto code_r0x0007fe28;
                  case 0x87df:
                    goto code_r0x0007fe1c;
                  }
                }
                *(undefined4 *)(iVar13 + 0x50) = uVar9;
              }
              if ((*(int *)(iVar13 + 0x58) == 2) &&
                 (*(int *)(iVar13 + 0x5c) == *(int *)(iVar32 + 8))) {
                uVar24 = *(undefined4 *)(iVar13 + 0x60);
                puVar17 = (undefined4 *)(iVar32 + 0x28);
                *(undefined4 *)(iVar13 + 0x5c) = *(undefined4 *)(iVar32 + 0x24);
                switch(uVar24) {
                case 0x87d5:
                  uVar24 = *puVar17;
                  break;
                case 0x87d6:
                  uVar24 = *(undefined4 *)(iVar32 + 0x2c);
                  break;
                case 0x87d7:
                  uVar24 = *(undefined4 *)(iVar32 + 0x30);
                  break;
                case 0x87d8:
                  uVar24 = *(undefined4 *)(iVar32 + 0x34);
                  break;
                case 0x87d9:
                  uVar24 = *puVar17;
                  switch(uVar24) {
                  case 0x87d5:
code_r0x00080094:
                    uVar24 = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x00080088:
                    uVar24 = 0x87da;
                    break;
                  case 0x87d7:
code_r0x000800f4:
                    uVar24 = 0x87db;
                    break;
                  case 0x87d8:
code_r0x000800e8:
                    uVar24 = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x000800dc:
                    uVar24 = 0x87d5;
                    break;
                  case 0x87da:
code_r0x000800d0:
                    uVar24 = 0x87d6;
                    break;
                  case 0x87db:
code_r0x000800c4:
                    uVar24 = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x000800b8:
                    uVar24 = 0x87d8;
                    break;
                  case 0x87de:
code_r0x000800ac:
                    uVar24 = 0x87df;
                    break;
                  case 0x87df:
code_r0x000800a0:
                    uVar24 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar24 = *(undefined4 *)(iVar32 + 0x2c);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x00080094;
                  case 0x87d6:
                    goto code_r0x00080088;
                  case 0x87d7:
                    goto code_r0x000800f4;
                  case 0x87d8:
                    goto code_r0x000800e8;
                  case 0x87d9:
                    goto code_r0x000800dc;
                  case 0x87da:
                    goto code_r0x000800d0;
                  case 0x87db:
                    goto code_r0x000800c4;
                  case 0x87dc:
                    goto code_r0x000800b8;
                  case 0x87de:
                    goto code_r0x000800ac;
                  case 0x87df:
                    goto code_r0x000800a0;
                  }
                  break;
                case 0x87db:
                  uVar24 = *(undefined4 *)(iVar32 + 0x30);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x00080094;
                  case 0x87d6:
                    goto code_r0x00080088;
                  case 0x87d7:
                    goto code_r0x000800f4;
                  case 0x87d8:
                    goto code_r0x000800e8;
                  case 0x87d9:
                    goto code_r0x000800dc;
                  case 0x87da:
                    goto code_r0x000800d0;
                  case 0x87db:
                    goto code_r0x000800c4;
                  case 0x87dc:
                    goto code_r0x000800b8;
                  case 0x87de:
                    goto code_r0x000800ac;
                  case 0x87df:
                    goto code_r0x000800a0;
                  }
                  break;
                case 0x87dc:
                  uVar24 = *(undefined4 *)(iVar32 + 0x34);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x00080094;
                  case 0x87d6:
                    goto code_r0x00080088;
                  case 0x87d7:
                    goto code_r0x000800f4;
                  case 0x87d8:
                    goto code_r0x000800e8;
                  case 0x87d9:
                    goto code_r0x000800dc;
                  case 0x87da:
                    goto code_r0x000800d0;
                  case 0x87db:
                    goto code_r0x000800c4;
                  case 0x87dc:
                    goto code_r0x000800b8;
                  case 0x87de:
                    goto code_r0x000800ac;
                  case 0x87df:
                    goto code_r0x000800a0;
                  }
                }
                uVar9 = *(undefined4 *)(iVar13 + 100);
                *(undefined4 *)(iVar13 + 0x60) = uVar24;
                switch(uVar9) {
                case 0x87d5:
                  uVar9 = *puVar17;
                  break;
                case 0x87d6:
                  uVar9 = *(undefined4 *)(iVar32 + 0x2c);
                  break;
                case 0x87d7:
                  uVar9 = *(undefined4 *)(iVar32 + 0x30);
                  break;
                case 0x87d8:
                  uVar9 = *(undefined4 *)(iVar32 + 0x34);
                  break;
                case 0x87d9:
                  uVar9 = *puVar17;
                  switch(uVar9) {
                  case 0x87d5:
code_r0x000802ec:
                    uVar9 = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x000802e0:
                    uVar9 = 0x87da;
                    break;
                  case 0x87d7:
code_r0x0008034c:
                    uVar9 = 0x87db;
                    break;
                  case 0x87d8:
code_r0x00080340:
                    uVar9 = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x00080334:
                    uVar9 = 0x87d5;
                    break;
                  case 0x87da:
code_r0x00080328:
                    uVar9 = 0x87d6;
                    break;
                  case 0x87db:
code_r0x0008031c:
                    uVar9 = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x00080310:
                    uVar9 = 0x87d8;
                    break;
                  case 0x87de:
code_r0x00080304:
                    uVar9 = 0x87df;
                    break;
                  case 0x87df:
code_r0x000802f8:
                    uVar9 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar9 = *(undefined4 *)(iVar32 + 0x2c);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x000802ec;
                  case 0x87d6:
                    goto code_r0x000802e0;
                  case 0x87d7:
                    goto code_r0x0008034c;
                  case 0x87d8:
                    goto code_r0x00080340;
                  case 0x87d9:
                    goto code_r0x00080334;
                  case 0x87da:
                    goto code_r0x00080328;
                  case 0x87db:
                    goto code_r0x0008031c;
                  case 0x87dc:
                    goto code_r0x00080310;
                  case 0x87de:
                    goto code_r0x00080304;
                  case 0x87df:
                    goto code_r0x000802f8;
                  }
                  break;
                case 0x87db:
                  uVar9 = *(undefined4 *)(iVar32 + 0x30);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x000802ec;
                  case 0x87d6:
                    goto code_r0x000802e0;
                  case 0x87d7:
                    goto code_r0x0008034c;
                  case 0x87d8:
                    goto code_r0x00080340;
                  case 0x87d9:
                    goto code_r0x00080334;
                  case 0x87da:
                    goto code_r0x00080328;
                  case 0x87db:
                    goto code_r0x0008031c;
                  case 0x87dc:
                    goto code_r0x00080310;
                  case 0x87de:
                    goto code_r0x00080304;
                  case 0x87df:
                    goto code_r0x000802f8;
                  }
                  break;
                case 0x87dc:
                  uVar9 = *(undefined4 *)(iVar32 + 0x34);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x000802ec;
                  case 0x87d6:
                    goto code_r0x000802e0;
                  case 0x87d7:
                    goto code_r0x0008034c;
                  case 0x87d8:
                    goto code_r0x00080340;
                  case 0x87d9:
                    goto code_r0x00080334;
                  case 0x87da:
                    goto code_r0x00080328;
                  case 0x87db:
                    goto code_r0x0008031c;
                  case 0x87dc:
                    goto code_r0x00080310;
                  case 0x87de:
                    goto code_r0x00080304;
                  case 0x87df:
                    goto code_r0x000802f8;
                  }
                }
                uVar24 = *(undefined4 *)(iVar13 + 0x68);
                *(undefined4 *)(iVar13 + 100) = uVar9;
                switch(uVar24) {
                case 0x87d5:
                  uVar24 = *puVar17;
                  break;
                case 0x87d6:
                  uVar24 = *(undefined4 *)(iVar32 + 0x2c);
                  break;
                case 0x87d7:
                  uVar24 = *(undefined4 *)(iVar32 + 0x30);
                  break;
                case 0x87d8:
                  uVar24 = *(undefined4 *)(iVar32 + 0x34);
                  break;
                case 0x87d9:
                  uVar24 = *puVar17;
                  switch(uVar24) {
                  case 0x87d5:
code_r0x00080544:
                    uVar24 = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x00080538:
                    uVar24 = 0x87da;
                    break;
                  case 0x87d7:
code_r0x000805a4:
                    uVar24 = 0x87db;
                    break;
                  case 0x87d8:
code_r0x00080598:
                    uVar24 = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x0008058c:
                    uVar24 = 0x87d5;
                    break;
                  case 0x87da:
code_r0x00080580:
                    uVar24 = 0x87d6;
                    break;
                  case 0x87db:
code_r0x00080574:
                    uVar24 = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x00080568:
                    uVar24 = 0x87d8;
                    break;
                  case 0x87de:
code_r0x0008055c:
                    uVar24 = 0x87df;
                    break;
                  case 0x87df:
code_r0x00080550:
                    uVar24 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar24 = *(undefined4 *)(iVar32 + 0x2c);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x00080544;
                  case 0x87d6:
                    goto code_r0x00080538;
                  case 0x87d7:
                    goto code_r0x000805a4;
                  case 0x87d8:
                    goto code_r0x00080598;
                  case 0x87d9:
                    goto code_r0x0008058c;
                  case 0x87da:
                    goto code_r0x00080580;
                  case 0x87db:
                    goto code_r0x00080574;
                  case 0x87dc:
                    goto code_r0x00080568;
                  case 0x87de:
                    goto code_r0x0008055c;
                  case 0x87df:
                    goto code_r0x00080550;
                  }
                  break;
                case 0x87db:
                  uVar24 = *(undefined4 *)(iVar32 + 0x30);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x00080544;
                  case 0x87d6:
                    goto code_r0x00080538;
                  case 0x87d7:
                    goto code_r0x000805a4;
                  case 0x87d8:
                    goto code_r0x00080598;
                  case 0x87d9:
                    goto code_r0x0008058c;
                  case 0x87da:
                    goto code_r0x00080580;
                  case 0x87db:
                    goto code_r0x00080574;
                  case 0x87dc:
                    goto code_r0x00080568;
                  case 0x87de:
                    goto code_r0x0008055c;
                  case 0x87df:
                    goto code_r0x00080550;
                  }
                  break;
                case 0x87dc:
                  uVar24 = *(undefined4 *)(iVar32 + 0x34);
                  switch(uVar24) {
                  case 0x87d5:
                    goto code_r0x00080544;
                  case 0x87d6:
                    goto code_r0x00080538;
                  case 0x87d7:
                    goto code_r0x000805a4;
                  case 0x87d8:
                    goto code_r0x00080598;
                  case 0x87d9:
                    goto code_r0x0008058c;
                  case 0x87da:
                    goto code_r0x00080580;
                  case 0x87db:
                    goto code_r0x00080574;
                  case 0x87dc:
                    goto code_r0x00080568;
                  case 0x87de:
                    goto code_r0x0008055c;
                  case 0x87df:
                    goto code_r0x00080550;
                  }
                }
                uVar9 = *(undefined4 *)(iVar13 + 0x6c);
                *(undefined4 *)(iVar13 + 0x68) = uVar24;
                switch(uVar9) {
                case 0x87d5:
                  uVar9 = *puVar17;
                  break;
                case 0x87d6:
                  uVar9 = *(undefined4 *)(iVar32 + 0x2c);
                  break;
                case 0x87d7:
                  uVar9 = *(undefined4 *)(iVar32 + 0x30);
                  break;
                case 0x87d8:
                  uVar9 = *(undefined4 *)(iVar32 + 0x34);
                  break;
                case 0x87d9:
                  uVar9 = *puVar17;
                  switch(uVar9) {
                  case 0x87d5:
code_r0x0008079c:
                    uVar9 = 0x87d9;
                    break;
                  case 0x87d6:
code_r0x00080790:
                    uVar9 = 0x87da;
                    break;
                  case 0x87d7:
code_r0x000807fc:
                    uVar9 = 0x87db;
                    break;
                  case 0x87d8:
code_r0x000807f0:
                    uVar9 = 0x87dc;
                    break;
                  case 0x87d9:
code_r0x000807e4:
                    uVar9 = 0x87d5;
                    break;
                  case 0x87da:
code_r0x000807d8:
                    uVar9 = 0x87d6;
                    break;
                  case 0x87db:
code_r0x000807cc:
                    uVar9 = 0x87d7;
                    break;
                  case 0x87dc:
code_r0x000807c0:
                    uVar9 = 0x87d8;
                    break;
                  case 0x87de:
code_r0x000807b4:
                    uVar9 = 0x87df;
                    break;
                  case 0x87df:
code_r0x000807a8:
                    uVar9 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar9 = *(undefined4 *)(iVar32 + 0x2c);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x0008079c;
                  case 0x87d6:
                    goto code_r0x00080790;
                  case 0x87d7:
                    goto code_r0x000807fc;
                  case 0x87d8:
                    goto code_r0x000807f0;
                  case 0x87d9:
                    goto code_r0x000807e4;
                  case 0x87da:
                    goto code_r0x000807d8;
                  case 0x87db:
                    goto code_r0x000807cc;
                  case 0x87dc:
                    goto code_r0x000807c0;
                  case 0x87de:
                    goto code_r0x000807b4;
                  case 0x87df:
                    goto code_r0x000807a8;
                  }
                  break;
                case 0x87db:
                  uVar9 = *(undefined4 *)(iVar32 + 0x30);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x0008079c;
                  case 0x87d6:
                    goto code_r0x00080790;
                  case 0x87d7:
                    goto code_r0x000807fc;
                  case 0x87d8:
                    goto code_r0x000807f0;
                  case 0x87d9:
                    goto code_r0x000807e4;
                  case 0x87da:
                    goto code_r0x000807d8;
                  case 0x87db:
                    goto code_r0x000807cc;
                  case 0x87dc:
                    goto code_r0x000807c0;
                  case 0x87de:
                    goto code_r0x000807b4;
                  case 0x87df:
                    goto code_r0x000807a8;
                  }
                  break;
                case 0x87dc:
                  uVar9 = *(undefined4 *)(iVar32 + 0x34);
                  switch(uVar9) {
                  case 0x87d5:
                    goto code_r0x0008079c;
                  case 0x87d6:
                    goto code_r0x00080790;
                  case 0x87d7:
                    goto code_r0x000807fc;
                  case 0x87d8:
                    goto code_r0x000807f0;
                  case 0x87d9:
                    goto code_r0x000807e4;
                  case 0x87da:
                    goto code_r0x000807d8;
                  case 0x87db:
                    goto code_r0x000807cc;
                  case 0x87dc:
                    goto code_r0x000807c0;
                  case 0x87de:
                    goto code_r0x000807b4;
                  case 0x87df:
                    goto code_r0x000807a8;
                  }
                }
                *(undefined4 *)(iVar13 + 0x6c) = uVar9;
              }
              iVar11 = iVar11 + -1;
              iVar31 = iVar31 + 0x74;
            } while (iVar11 != 0);
            uVar16 = *(uint *)(param_2 + 0x14);
          }
          uVar16 = uVar16 - 1;
          *(uint *)(param_2 + 0x14) = uVar16;
          uVar18 = uVar30;
          if (uVar30 < uVar16) {
            do {
              uVar18 = uVar18 + 1;
              iVar11 = iVar23 + *(int *)(param_2 + 0x18);
              iVar23 = iVar23 + 0x74;
              _memcpy(iVar11,iVar11 + 0x74,0x74);
              uVar16 = *(uint *)(param_2 + 0x14);
            } while (uVar18 < uVar16);
          }
          bVar33 = true;
        }
LAB_00080860:
        uVar30 = uVar30 + 1;
      } while (uVar30 < uVar16);
    }
  } while (bVar33);
  uVar15 = 0;
  if (uVar16 != 0) {
    iVar11 = uVar16 * 0x74;
    uVar15 = 0;
    do {
      uVar30 = uVar16 - uVar15;
      iVar31 = iVar11 + *(int *)(param_2 + 0x18);
      if (((*(int *)(iVar31 + -0x74) == 0x879d) && (*(int *)(iVar31 + -0x70) == 2)) &&
         (iVar23 = FUN_000550e0(param_2 + 0x1c,iVar31 + -0x54), iVar23 == 0x87bf)) {
        uVar18 = *(uint *)(param_2 + 0x14);
        if (uVar30 < uVar18) {
          iVar23 = uVar18 - uVar30;
          bVar34 = true;
          bVar33 = false;
          piVar21 = (int *)(iVar11 + *(int *)(param_2 + 0x18) + 4);
          do {
            if ((*piVar21 != 2) || (piVar21[1] != *(int *)(iVar31 + -0x6c))) {
              if (bVar33) {
                if ((((piVar21[7] == 2) && (piVar21[8] == *(int *)(iVar31 + -0x6c))) ||
                    ((piVar21[0xe] == 2 && (piVar21[0xf] == *(int *)(iVar31 + -0x6c))))) ||
                   ((piVar21[0x15] == 2 && (piVar21[0x16] == *(int *)(iVar31 + -0x6c)))))
                goto code_r0x00080a40;
                bVar35 = false;
              }
              else {
                if (((*piVar21 == 2) && (*(int *)(iVar31 + -0x54) == 2)) &&
                   (piVar21[1] == *(int *)(iVar31 + -0x50))) {
                  iVar32 = *(int *)(iVar31 + -0x34);
                  if (iVar32 == 0) {
                    iVar32 = piVar21[2];
                  }
                  else if (iVar32 == 1) {
                    iVar32 = piVar21[3];
                  }
                  else if (iVar32 == 2) {
                    iVar32 = piVar21[4];
                  }
                  else {
                    if (iVar32 != 3) goto code_r0x000809ec;
                    iVar32 = piVar21[5];
                  }
                  if (iVar32 != 0) {
                    bVar35 = false;
                    bVar33 = true;
                    goto code_r0x00080a54;
                  }
                }
code_r0x000809ec:
                bVar35 = false;
                bVar33 = false;
              }
            }
            else if (((piVar21[2] == 0) || (piVar21[3] == 0)) ||
                    ((piVar21[4] == 0 || (bVar35 = true, piVar21[5] == 0)))) {
code_r0x00080a40:
              bVar35 = true;
              bVar34 = false;
            }
code_r0x00080a54:
            iVar23 = iVar23 + -1;
          } while ((iVar23 != 0) && (piVar21 = piVar21 + 0x1d, !bVar35));
          if (!bVar34) goto code_r0x00082600;
        }
        iVar23 = *(int *)(iVar31 + -0x34);
        if (iVar23 == 1) {
          uVar24 = *(undefined4 *)(iVar31 + -0x48);
        }
        else if (iVar23 == 0) {
          uVar24 = *(undefined4 *)(iVar31 + -0x4c);
        }
        else if (iVar23 == 2) {
          uVar24 = *(undefined4 *)(iVar31 + -0x44);
        }
        else {
          uVar24 = *(undefined4 *)(iVar31 + -0x40);
        }
        iVar23 = iVar11;
        uVar25 = uVar30;
        if (uVar30 < uVar18) {
          do {
            iVar32 = iVar23 + *(int *)(param_2 + 0x18);
            if ((*(int *)(iVar32 + 0x20) != 2) ||
               (*(int *)(iVar32 + 0x24) != *(int *)(iVar31 + -0x6c))) goto code_r0x000813a8;
            *(undefined4 *)(iVar32 + 0x24) = *(undefined4 *)(iVar31 + -0x50);
            uVar9 = *(undefined4 *)(iVar32 + 0x28);
            switch(*(undefined4 *)(iVar32 + 0x28)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar24) {
              case 0x87d5:
code_r0x00080cac:
                uVar9 = 0x87d9;
                break;
              case 0x87d6:
code_r0x00080ca0:
                uVar9 = 0x87da;
                break;
              case 0x87d7:
code_r0x00080d0c:
                uVar9 = 0x87db;
                break;
              case 0x87d8:
code_r0x00080d00:
                uVar9 = 0x87dc;
                break;
              case 0x87d9:
code_r0x00080cf4:
                uVar9 = 0x87d5;
                break;
              case 0x87da:
code_r0x00080ce8:
                uVar9 = 0x87d6;
                break;
              case 0x87db:
code_r0x00080cdc:
                uVar9 = 0x87d7;
                break;
              case 0x87dc:
code_r0x00080cd0:
                uVar9 = 0x87d8;
                break;
              default:
                goto code_r0x00080c98;
              case 0x87de:
code_r0x00080cc4:
                uVar9 = 0x87df;
                break;
              case 0x87df:
code_r0x00080cb8:
                uVar9 = 0x87de;
              }
              goto code_r0x00080d14;
            case 0x87da:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x00080cac;
              case 0x87d6:
                goto code_r0x00080ca0;
              case 0x87d7:
                goto code_r0x00080d0c;
              case 0x87d8:
                goto code_r0x00080d00;
              case 0x87d9:
                goto code_r0x00080cf4;
              case 0x87da:
                goto code_r0x00080ce8;
              case 0x87db:
                goto code_r0x00080cdc;
              case 0x87dc:
                goto code_r0x00080cd0;
              case 0x87de:
                goto code_r0x00080cc4;
              case 0x87df:
                goto code_r0x00080cb8;
              }
              break;
            case 0x87db:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x00080cac;
              case 0x87d6:
                goto code_r0x00080ca0;
              case 0x87d7:
                goto code_r0x00080d0c;
              case 0x87d8:
                goto code_r0x00080d00;
              case 0x87d9:
                goto code_r0x00080cf4;
              case 0x87da:
                goto code_r0x00080ce8;
              case 0x87db:
                goto code_r0x00080cdc;
              case 0x87dc:
                goto code_r0x00080cd0;
              case 0x87de:
                goto code_r0x00080cc4;
              case 0x87df:
                goto code_r0x00080cb8;
              }
              break;
            case 0x87dc:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x00080cac;
              case 0x87d6:
                goto code_r0x00080ca0;
              case 0x87d7:
                goto code_r0x00080d0c;
              case 0x87d8:
                goto code_r0x00080d00;
              case 0x87d9:
                goto code_r0x00080cf4;
              case 0x87da:
                goto code_r0x00080ce8;
              case 0x87db:
                goto code_r0x00080cdc;
              case 0x87dc:
                goto code_r0x00080cd0;
              case 0x87de:
                goto code_r0x00080cc4;
              case 0x87df:
                goto code_r0x00080cb8;
              }
              break;
            default:
              goto code_r0x00080d14;
            }
code_r0x00080c98:
            uVar9 = uVar24;
code_r0x00080d14:
            *(undefined4 *)(iVar32 + 0x28) = uVar9;
            uVar9 = *(undefined4 *)(iVar32 + 0x2c);
            switch(*(undefined4 *)(iVar32 + 0x2c)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar24) {
              case 0x87d5:
code_r0x00080edc:
                uVar9 = 0x87d9;
                break;
              case 0x87d6:
code_r0x00080ed0:
                uVar9 = 0x87da;
                break;
              case 0x87d7:
code_r0x00080f3c:
                uVar9 = 0x87db;
                break;
              case 0x87d8:
code_r0x00080f30:
                uVar9 = 0x87dc;
                break;
              case 0x87d9:
code_r0x00080f24:
                uVar9 = 0x87d5;
                break;
              case 0x87da:
code_r0x00080f18:
                uVar9 = 0x87d6;
                break;
              case 0x87db:
code_r0x00080f0c:
                uVar9 = 0x87d7;
                break;
              case 0x87dc:
code_r0x00080f00:
                uVar9 = 0x87d8;
                break;
              default:
                goto code_r0x00080ec8;
              case 0x87de:
code_r0x00080ef4:
                uVar9 = 0x87df;
                break;
              case 0x87df:
code_r0x00080ee8:
                uVar9 = 0x87de;
              }
              goto code_r0x00080f44;
            case 0x87da:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x00080edc;
              case 0x87d6:
                goto code_r0x00080ed0;
              case 0x87d7:
                goto code_r0x00080f3c;
              case 0x87d8:
                goto code_r0x00080f30;
              case 0x87d9:
                goto code_r0x00080f24;
              case 0x87da:
                goto code_r0x00080f18;
              case 0x87db:
                goto code_r0x00080f0c;
              case 0x87dc:
                goto code_r0x00080f00;
              case 0x87de:
                goto code_r0x00080ef4;
              case 0x87df:
                goto code_r0x00080ee8;
              }
              break;
            case 0x87db:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x00080edc;
              case 0x87d6:
                goto code_r0x00080ed0;
              case 0x87d7:
                goto code_r0x00080f3c;
              case 0x87d8:
                goto code_r0x00080f30;
              case 0x87d9:
                goto code_r0x00080f24;
              case 0x87da:
                goto code_r0x00080f18;
              case 0x87db:
                goto code_r0x00080f0c;
              case 0x87dc:
                goto code_r0x00080f00;
              case 0x87de:
                goto code_r0x00080ef4;
              case 0x87df:
                goto code_r0x00080ee8;
              }
              break;
            case 0x87dc:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x00080edc;
              case 0x87d6:
                goto code_r0x00080ed0;
              case 0x87d7:
                goto code_r0x00080f3c;
              case 0x87d8:
                goto code_r0x00080f30;
              case 0x87d9:
                goto code_r0x00080f24;
              case 0x87da:
                goto code_r0x00080f18;
              case 0x87db:
                goto code_r0x00080f0c;
              case 0x87dc:
                goto code_r0x00080f00;
              case 0x87de:
                goto code_r0x00080ef4;
              case 0x87df:
                goto code_r0x00080ee8;
              }
              break;
            default:
              goto code_r0x00080f44;
            }
code_r0x00080ec8:
            uVar9 = uVar24;
code_r0x00080f44:
            *(undefined4 *)(iVar32 + 0x2c) = uVar9;
            uVar9 = *(undefined4 *)(iVar32 + 0x30);
            switch(*(undefined4 *)(iVar32 + 0x30)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar24) {
              case 0x87d5:
code_r0x0008110c:
                uVar9 = 0x87d9;
                break;
              case 0x87d6:
code_r0x00081100:
                uVar9 = 0x87da;
                break;
              case 0x87d7:
code_r0x0008116c:
                uVar9 = 0x87db;
                break;
              case 0x87d8:
code_r0x00081160:
                uVar9 = 0x87dc;
                break;
              case 0x87d9:
code_r0x00081154:
                uVar9 = 0x87d5;
                break;
              case 0x87da:
code_r0x00081148:
                uVar9 = 0x87d6;
                break;
              case 0x87db:
code_r0x0008113c:
                uVar9 = 0x87d7;
                break;
              case 0x87dc:
code_r0x00081130:
                uVar9 = 0x87d8;
                break;
              default:
                goto code_r0x000810f8;
              case 0x87de:
code_r0x00081124:
                uVar9 = 0x87df;
                break;
              case 0x87df:
code_r0x00081118:
                uVar9 = 0x87de;
              }
              goto code_r0x00081174;
            case 0x87da:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x0008110c;
              case 0x87d6:
                goto code_r0x00081100;
              case 0x87d7:
                goto code_r0x0008116c;
              case 0x87d8:
                goto code_r0x00081160;
              case 0x87d9:
                goto code_r0x00081154;
              case 0x87da:
                goto code_r0x00081148;
              case 0x87db:
                goto code_r0x0008113c;
              case 0x87dc:
                goto code_r0x00081130;
              case 0x87de:
                goto code_r0x00081124;
              case 0x87df:
                goto code_r0x00081118;
              }
              break;
            case 0x87db:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x0008110c;
              case 0x87d6:
                goto code_r0x00081100;
              case 0x87d7:
                goto code_r0x0008116c;
              case 0x87d8:
                goto code_r0x00081160;
              case 0x87d9:
                goto code_r0x00081154;
              case 0x87da:
                goto code_r0x00081148;
              case 0x87db:
                goto code_r0x0008113c;
              case 0x87dc:
                goto code_r0x00081130;
              case 0x87de:
                goto code_r0x00081124;
              case 0x87df:
                goto code_r0x00081118;
              }
              break;
            case 0x87dc:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x0008110c;
              case 0x87d6:
                goto code_r0x00081100;
              case 0x87d7:
                goto code_r0x0008116c;
              case 0x87d8:
                goto code_r0x00081160;
              case 0x87d9:
                goto code_r0x00081154;
              case 0x87da:
                goto code_r0x00081148;
              case 0x87db:
                goto code_r0x0008113c;
              case 0x87dc:
                goto code_r0x00081130;
              case 0x87de:
                goto code_r0x00081124;
              case 0x87df:
                goto code_r0x00081118;
              }
              break;
            default:
              goto code_r0x00081174;
            }
code_r0x000810f8:
            uVar9 = uVar24;
code_r0x00081174:
            *(undefined4 *)(iVar32 + 0x30) = uVar9;
            uVar9 = *(undefined4 *)(iVar32 + 0x34);
            switch(*(undefined4 *)(iVar32 + 0x34)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar24) {
              case 0x87d5:
code_r0x0008133c:
                uVar9 = 0x87d9;
                break;
              case 0x87d6:
code_r0x00081330:
                uVar9 = 0x87da;
                break;
              case 0x87d7:
code_r0x0008139c:
                uVar9 = 0x87db;
                break;
              case 0x87d8:
code_r0x00081390:
                uVar9 = 0x87dc;
                break;
              case 0x87d9:
code_r0x00081384:
                uVar9 = 0x87d5;
                break;
              case 0x87da:
code_r0x00081378:
                uVar9 = 0x87d6;
                break;
              case 0x87db:
code_r0x0008136c:
                uVar9 = 0x87d7;
                break;
              case 0x87dc:
code_r0x00081360:
                uVar9 = 0x87d8;
                break;
              default:
                goto code_r0x00081328;
              case 0x87de:
code_r0x00081354:
                uVar9 = 0x87df;
                break;
              case 0x87df:
code_r0x00081348:
                uVar9 = 0x87de;
              }
              goto code_r0x000813a4;
            case 0x87da:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x0008133c;
              case 0x87d6:
                goto code_r0x00081330;
              case 0x87d7:
                goto code_r0x0008139c;
              case 0x87d8:
                goto code_r0x00081390;
              case 0x87d9:
                goto code_r0x00081384;
              case 0x87da:
                goto code_r0x00081378;
              case 0x87db:
                goto code_r0x0008136c;
              case 0x87dc:
                goto code_r0x00081360;
              case 0x87de:
                goto code_r0x00081354;
              case 0x87df:
                goto code_r0x00081348;
              }
              break;
            case 0x87db:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x0008133c;
              case 0x87d6:
                goto code_r0x00081330;
              case 0x87d7:
                goto code_r0x0008139c;
              case 0x87d8:
                goto code_r0x00081390;
              case 0x87d9:
                goto code_r0x00081384;
              case 0x87da:
                goto code_r0x00081378;
              case 0x87db:
                goto code_r0x0008136c;
              case 0x87dc:
                goto code_r0x00081360;
              case 0x87de:
                goto code_r0x00081354;
              case 0x87df:
                goto code_r0x00081348;
              }
              break;
            case 0x87dc:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x0008133c;
              case 0x87d6:
                goto code_r0x00081330;
              case 0x87d7:
                goto code_r0x0008139c;
              case 0x87d8:
                goto code_r0x00081390;
              case 0x87d9:
                goto code_r0x00081384;
              case 0x87da:
                goto code_r0x00081378;
              case 0x87db:
                goto code_r0x0008136c;
              case 0x87dc:
                goto code_r0x00081360;
              case 0x87de:
                goto code_r0x00081354;
              case 0x87df:
                goto code_r0x00081348;
              }
              break;
            default:
              goto code_r0x000813a4;
            }
code_r0x00081328:
            uVar9 = uVar24;
code_r0x000813a4:
            *(undefined4 *)(iVar32 + 0x34) = uVar9;
code_r0x000813a8:
            if ((*(int *)(iVar32 + 0x3c) != 2) ||
               (*(int *)(iVar32 + 0x40) != *(int *)(iVar31 + -0x6c))) goto code_r0x00081c90;
            *(undefined4 *)(iVar32 + 0x40) = *(undefined4 *)(iVar31 + -0x50);
            uVar9 = *(undefined4 *)(iVar32 + 0x44);
            switch(*(undefined4 *)(iVar32 + 0x44)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar24) {
              case 0x87d5:
code_r0x00081594:
                uVar9 = 0x87d9;
                break;
              case 0x87d6:
code_r0x00081588:
                uVar9 = 0x87da;
                break;
              case 0x87d7:
code_r0x000815f4:
                uVar9 = 0x87db;
                break;
              case 0x87d8:
code_r0x000815e8:
                uVar9 = 0x87dc;
                break;
              case 0x87d9:
code_r0x000815dc:
                uVar9 = 0x87d5;
                break;
              case 0x87da:
code_r0x000815d0:
                uVar9 = 0x87d6;
                break;
              case 0x87db:
code_r0x000815c4:
                uVar9 = 0x87d7;
                break;
              case 0x87dc:
code_r0x000815b8:
                uVar9 = 0x87d8;
                break;
              default:
                goto code_r0x00081580;
              case 0x87de:
code_r0x000815ac:
                uVar9 = 0x87df;
                break;
              case 0x87df:
code_r0x000815a0:
                uVar9 = 0x87de;
              }
              goto code_r0x000815fc;
            case 0x87da:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x00081594;
              case 0x87d6:
                goto code_r0x00081588;
              case 0x87d7:
                goto code_r0x000815f4;
              case 0x87d8:
                goto code_r0x000815e8;
              case 0x87d9:
                goto code_r0x000815dc;
              case 0x87da:
                goto code_r0x000815d0;
              case 0x87db:
                goto code_r0x000815c4;
              case 0x87dc:
                goto code_r0x000815b8;
              case 0x87de:
                goto code_r0x000815ac;
              case 0x87df:
                goto code_r0x000815a0;
              }
              break;
            case 0x87db:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x00081594;
              case 0x87d6:
                goto code_r0x00081588;
              case 0x87d7:
                goto code_r0x000815f4;
              case 0x87d8:
                goto code_r0x000815e8;
              case 0x87d9:
                goto code_r0x000815dc;
              case 0x87da:
                goto code_r0x000815d0;
              case 0x87db:
                goto code_r0x000815c4;
              case 0x87dc:
                goto code_r0x000815b8;
              case 0x87de:
                goto code_r0x000815ac;
              case 0x87df:
                goto code_r0x000815a0;
              }
              break;
            case 0x87dc:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x00081594;
              case 0x87d6:
                goto code_r0x00081588;
              case 0x87d7:
                goto code_r0x000815f4;
              case 0x87d8:
                goto code_r0x000815e8;
              case 0x87d9:
                goto code_r0x000815dc;
              case 0x87da:
                goto code_r0x000815d0;
              case 0x87db:
                goto code_r0x000815c4;
              case 0x87dc:
                goto code_r0x000815b8;
              case 0x87de:
                goto code_r0x000815ac;
              case 0x87df:
                goto code_r0x000815a0;
              }
              break;
            default:
              goto code_r0x000815fc;
            }
code_r0x00081580:
            uVar9 = uVar24;
code_r0x000815fc:
            *(undefined4 *)(iVar32 + 0x44) = uVar9;
            uVar9 = *(undefined4 *)(iVar32 + 0x48);
            switch(*(undefined4 *)(iVar32 + 0x48)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar24) {
              case 0x87d5:
code_r0x000817c4:
                uVar9 = 0x87d9;
                break;
              case 0x87d6:
code_r0x000817b8:
                uVar9 = 0x87da;
                break;
              case 0x87d7:
code_r0x00081824:
                uVar9 = 0x87db;
                break;
              case 0x87d8:
code_r0x00081818:
                uVar9 = 0x87dc;
                break;
              case 0x87d9:
code_r0x0008180c:
                uVar9 = 0x87d5;
                break;
              case 0x87da:
code_r0x00081800:
                uVar9 = 0x87d6;
                break;
              case 0x87db:
code_r0x000817f4:
                uVar9 = 0x87d7;
                break;
              case 0x87dc:
code_r0x000817e8:
                uVar9 = 0x87d8;
                break;
              default:
                goto code_r0x000817b0;
              case 0x87de:
code_r0x000817dc:
                uVar9 = 0x87df;
                break;
              case 0x87df:
code_r0x000817d0:
                uVar9 = 0x87de;
              }
              goto code_r0x0008182c;
            case 0x87da:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x000817c4;
              case 0x87d6:
                goto code_r0x000817b8;
              case 0x87d7:
                goto code_r0x00081824;
              case 0x87d8:
                goto code_r0x00081818;
              case 0x87d9:
                goto code_r0x0008180c;
              case 0x87da:
                goto code_r0x00081800;
              case 0x87db:
                goto code_r0x000817f4;
              case 0x87dc:
                goto code_r0x000817e8;
              case 0x87de:
                goto code_r0x000817dc;
              case 0x87df:
                goto code_r0x000817d0;
              }
              break;
            case 0x87db:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x000817c4;
              case 0x87d6:
                goto code_r0x000817b8;
              case 0x87d7:
                goto code_r0x00081824;
              case 0x87d8:
                goto code_r0x00081818;
              case 0x87d9:
                goto code_r0x0008180c;
              case 0x87da:
                goto code_r0x00081800;
              case 0x87db:
                goto code_r0x000817f4;
              case 0x87dc:
                goto code_r0x000817e8;
              case 0x87de:
                goto code_r0x000817dc;
              case 0x87df:
                goto code_r0x000817d0;
              }
              break;
            case 0x87dc:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x000817c4;
              case 0x87d6:
                goto code_r0x000817b8;
              case 0x87d7:
                goto code_r0x00081824;
              case 0x87d8:
                goto code_r0x00081818;
              case 0x87d9:
                goto code_r0x0008180c;
              case 0x87da:
                goto code_r0x00081800;
              case 0x87db:
                goto code_r0x000817f4;
              case 0x87dc:
                goto code_r0x000817e8;
              case 0x87de:
                goto code_r0x000817dc;
              case 0x87df:
                goto code_r0x000817d0;
              }
              break;
            default:
              goto code_r0x0008182c;
            }
code_r0x000817b0:
            uVar9 = uVar24;
code_r0x0008182c:
            *(undefined4 *)(iVar32 + 0x48) = uVar9;
            uVar9 = *(undefined4 *)(iVar32 + 0x4c);
            switch(*(undefined4 *)(iVar32 + 0x4c)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar24) {
              case 0x87d5:
code_r0x000819f4:
                uVar9 = 0x87d9;
                break;
              case 0x87d6:
code_r0x000819e8:
                uVar9 = 0x87da;
                break;
              case 0x87d7:
code_r0x00081a54:
                uVar9 = 0x87db;
                break;
              case 0x87d8:
code_r0x00081a48:
                uVar9 = 0x87dc;
                break;
              case 0x87d9:
code_r0x00081a3c:
                uVar9 = 0x87d5;
                break;
              case 0x87da:
code_r0x00081a30:
                uVar9 = 0x87d6;
                break;
              case 0x87db:
code_r0x00081a24:
                uVar9 = 0x87d7;
                break;
              case 0x87dc:
code_r0x00081a18:
                uVar9 = 0x87d8;
                break;
              default:
                goto code_r0x000819e0;
              case 0x87de:
code_r0x00081a0c:
                uVar9 = 0x87df;
                break;
              case 0x87df:
code_r0x00081a00:
                uVar9 = 0x87de;
              }
              goto code_r0x00081a5c;
            case 0x87da:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x000819f4;
              case 0x87d6:
                goto code_r0x000819e8;
              case 0x87d7:
                goto code_r0x00081a54;
              case 0x87d8:
                goto code_r0x00081a48;
              case 0x87d9:
                goto code_r0x00081a3c;
              case 0x87da:
                goto code_r0x00081a30;
              case 0x87db:
                goto code_r0x00081a24;
              case 0x87dc:
                goto code_r0x00081a18;
              case 0x87de:
                goto code_r0x00081a0c;
              case 0x87df:
                goto code_r0x00081a00;
              }
              break;
            case 0x87db:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x000819f4;
              case 0x87d6:
                goto code_r0x000819e8;
              case 0x87d7:
                goto code_r0x00081a54;
              case 0x87d8:
                goto code_r0x00081a48;
              case 0x87d9:
                goto code_r0x00081a3c;
              case 0x87da:
                goto code_r0x00081a30;
              case 0x87db:
                goto code_r0x00081a24;
              case 0x87dc:
                goto code_r0x00081a18;
              case 0x87de:
                goto code_r0x00081a0c;
              case 0x87df:
                goto code_r0x00081a00;
              }
              break;
            case 0x87dc:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x000819f4;
              case 0x87d6:
                goto code_r0x000819e8;
              case 0x87d7:
                goto code_r0x00081a54;
              case 0x87d8:
                goto code_r0x00081a48;
              case 0x87d9:
                goto code_r0x00081a3c;
              case 0x87da:
                goto code_r0x00081a30;
              case 0x87db:
                goto code_r0x00081a24;
              case 0x87dc:
                goto code_r0x00081a18;
              case 0x87de:
                goto code_r0x00081a0c;
              case 0x87df:
                goto code_r0x00081a00;
              }
              break;
            default:
              goto code_r0x00081a5c;
            }
code_r0x000819e0:
            uVar9 = uVar24;
code_r0x00081a5c:
            *(undefined4 *)(iVar32 + 0x4c) = uVar9;
            uVar9 = *(undefined4 *)(iVar32 + 0x50);
            switch(*(undefined4 *)(iVar32 + 0x50)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar24) {
              case 0x87d5:
code_r0x00081c24:
                uVar9 = 0x87d9;
                break;
              case 0x87d6:
code_r0x00081c18:
                uVar9 = 0x87da;
                break;
              case 0x87d7:
code_r0x00081c84:
                uVar9 = 0x87db;
                break;
              case 0x87d8:
code_r0x00081c78:
                uVar9 = 0x87dc;
                break;
              case 0x87d9:
code_r0x00081c6c:
                uVar9 = 0x87d5;
                break;
              case 0x87da:
code_r0x00081c60:
                uVar9 = 0x87d6;
                break;
              case 0x87db:
code_r0x00081c54:
                uVar9 = 0x87d7;
                break;
              case 0x87dc:
code_r0x00081c48:
                uVar9 = 0x87d8;
                break;
              default:
                goto code_r0x00081c10;
              case 0x87de:
code_r0x00081c3c:
                uVar9 = 0x87df;
                break;
              case 0x87df:
code_r0x00081c30:
                uVar9 = 0x87de;
              }
              goto code_r0x00081c8c;
            case 0x87da:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x00081c24;
              case 0x87d6:
                goto code_r0x00081c18;
              case 0x87d7:
                goto code_r0x00081c84;
              case 0x87d8:
                goto code_r0x00081c78;
              case 0x87d9:
                goto code_r0x00081c6c;
              case 0x87da:
                goto code_r0x00081c60;
              case 0x87db:
                goto code_r0x00081c54;
              case 0x87dc:
                goto code_r0x00081c48;
              case 0x87de:
                goto code_r0x00081c3c;
              case 0x87df:
                goto code_r0x00081c30;
              }
              break;
            case 0x87db:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x00081c24;
              case 0x87d6:
                goto code_r0x00081c18;
              case 0x87d7:
                goto code_r0x00081c84;
              case 0x87d8:
                goto code_r0x00081c78;
              case 0x87d9:
                goto code_r0x00081c6c;
              case 0x87da:
                goto code_r0x00081c60;
              case 0x87db:
                goto code_r0x00081c54;
              case 0x87dc:
                goto code_r0x00081c48;
              case 0x87de:
                goto code_r0x00081c3c;
              case 0x87df:
                goto code_r0x00081c30;
              }
              break;
            case 0x87dc:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x00081c24;
              case 0x87d6:
                goto code_r0x00081c18;
              case 0x87d7:
                goto code_r0x00081c84;
              case 0x87d8:
                goto code_r0x00081c78;
              case 0x87d9:
                goto code_r0x00081c6c;
              case 0x87da:
                goto code_r0x00081c60;
              case 0x87db:
                goto code_r0x00081c54;
              case 0x87dc:
                goto code_r0x00081c48;
              case 0x87de:
                goto code_r0x00081c3c;
              case 0x87df:
                goto code_r0x00081c30;
              }
              break;
            default:
              goto code_r0x00081c8c;
            }
code_r0x00081c10:
            uVar9 = uVar24;
code_r0x00081c8c:
            *(undefined4 *)(iVar32 + 0x50) = uVar9;
code_r0x00081c90:
            if ((*(int *)(iVar32 + 0x58) != 2) ||
               (*(int *)(iVar32 + 0x5c) != *(int *)(iVar31 + -0x6c))) goto code_r0x00082578;
            *(undefined4 *)(iVar32 + 0x5c) = *(undefined4 *)(iVar31 + -0x50);
            uVar9 = *(undefined4 *)(iVar32 + 0x60);
            switch(*(undefined4 *)(iVar32 + 0x60)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar24) {
              case 0x87d5:
code_r0x00081e7c:
                uVar9 = 0x87d9;
                break;
              case 0x87d6:
code_r0x00081e70:
                uVar9 = 0x87da;
                break;
              case 0x87d7:
code_r0x00081edc:
                uVar9 = 0x87db;
                break;
              case 0x87d8:
code_r0x00081ed0:
                uVar9 = 0x87dc;
                break;
              case 0x87d9:
code_r0x00081ec4:
                uVar9 = 0x87d5;
                break;
              case 0x87da:
code_r0x00081eb8:
                uVar9 = 0x87d6;
                break;
              case 0x87db:
code_r0x00081eac:
                uVar9 = 0x87d7;
                break;
              case 0x87dc:
code_r0x00081ea0:
                uVar9 = 0x87d8;
                break;
              default:
                goto code_r0x00081e68;
              case 0x87de:
code_r0x00081e94:
                uVar9 = 0x87df;
                break;
              case 0x87df:
code_r0x00081e88:
                uVar9 = 0x87de;
              }
              goto code_r0x00081ee4;
            case 0x87da:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x00081e7c;
              case 0x87d6:
                goto code_r0x00081e70;
              case 0x87d7:
                goto code_r0x00081edc;
              case 0x87d8:
                goto code_r0x00081ed0;
              case 0x87d9:
                goto code_r0x00081ec4;
              case 0x87da:
                goto code_r0x00081eb8;
              case 0x87db:
                goto code_r0x00081eac;
              case 0x87dc:
                goto code_r0x00081ea0;
              case 0x87de:
                goto code_r0x00081e94;
              case 0x87df:
                goto code_r0x00081e88;
              }
              break;
            case 0x87db:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x00081e7c;
              case 0x87d6:
                goto code_r0x00081e70;
              case 0x87d7:
                goto code_r0x00081edc;
              case 0x87d8:
                goto code_r0x00081ed0;
              case 0x87d9:
                goto code_r0x00081ec4;
              case 0x87da:
                goto code_r0x00081eb8;
              case 0x87db:
                goto code_r0x00081eac;
              case 0x87dc:
                goto code_r0x00081ea0;
              case 0x87de:
                goto code_r0x00081e94;
              case 0x87df:
                goto code_r0x00081e88;
              }
              break;
            case 0x87dc:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x00081e7c;
              case 0x87d6:
                goto code_r0x00081e70;
              case 0x87d7:
                goto code_r0x00081edc;
              case 0x87d8:
                goto code_r0x00081ed0;
              case 0x87d9:
                goto code_r0x00081ec4;
              case 0x87da:
                goto code_r0x00081eb8;
              case 0x87db:
                goto code_r0x00081eac;
              case 0x87dc:
                goto code_r0x00081ea0;
              case 0x87de:
                goto code_r0x00081e94;
              case 0x87df:
                goto code_r0x00081e88;
              }
              break;
            default:
              goto code_r0x00081ee4;
            }
code_r0x00081e68:
            uVar9 = uVar24;
code_r0x00081ee4:
            *(undefined4 *)(iVar32 + 0x60) = uVar9;
            uVar9 = *(undefined4 *)(iVar32 + 100);
            switch(*(undefined4 *)(iVar32 + 100)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar24) {
              case 0x87d5:
code_r0x000820ac:
                uVar9 = 0x87d9;
                break;
              case 0x87d6:
code_r0x000820a0:
                uVar9 = 0x87da;
                break;
              case 0x87d7:
code_r0x0008210c:
                uVar9 = 0x87db;
                break;
              case 0x87d8:
code_r0x00082100:
                uVar9 = 0x87dc;
                break;
              case 0x87d9:
code_r0x000820f4:
                uVar9 = 0x87d5;
                break;
              case 0x87da:
code_r0x000820e8:
                uVar9 = 0x87d6;
                break;
              case 0x87db:
code_r0x000820dc:
                uVar9 = 0x87d7;
                break;
              case 0x87dc:
code_r0x000820d0:
                uVar9 = 0x87d8;
                break;
              default:
                goto code_r0x00082098;
              case 0x87de:
code_r0x000820c4:
                uVar9 = 0x87df;
                break;
              case 0x87df:
code_r0x000820b8:
                uVar9 = 0x87de;
              }
              goto code_r0x00082114;
            case 0x87da:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x000820ac;
              case 0x87d6:
                goto code_r0x000820a0;
              case 0x87d7:
                goto code_r0x0008210c;
              case 0x87d8:
                goto code_r0x00082100;
              case 0x87d9:
                goto code_r0x000820f4;
              case 0x87da:
                goto code_r0x000820e8;
              case 0x87db:
                goto code_r0x000820dc;
              case 0x87dc:
                goto code_r0x000820d0;
              case 0x87de:
                goto code_r0x000820c4;
              case 0x87df:
                goto code_r0x000820b8;
              }
              break;
            case 0x87db:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x000820ac;
              case 0x87d6:
                goto code_r0x000820a0;
              case 0x87d7:
                goto code_r0x0008210c;
              case 0x87d8:
                goto code_r0x00082100;
              case 0x87d9:
                goto code_r0x000820f4;
              case 0x87da:
                goto code_r0x000820e8;
              case 0x87db:
                goto code_r0x000820dc;
              case 0x87dc:
                goto code_r0x000820d0;
              case 0x87de:
                goto code_r0x000820c4;
              case 0x87df:
                goto code_r0x000820b8;
              }
              break;
            case 0x87dc:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x000820ac;
              case 0x87d6:
                goto code_r0x000820a0;
              case 0x87d7:
                goto code_r0x0008210c;
              case 0x87d8:
                goto code_r0x00082100;
              case 0x87d9:
                goto code_r0x000820f4;
              case 0x87da:
                goto code_r0x000820e8;
              case 0x87db:
                goto code_r0x000820dc;
              case 0x87dc:
                goto code_r0x000820d0;
              case 0x87de:
                goto code_r0x000820c4;
              case 0x87df:
                goto code_r0x000820b8;
              }
              break;
            default:
              goto code_r0x00082114;
            }
code_r0x00082098:
            uVar9 = uVar24;
code_r0x00082114:
            *(undefined4 *)(iVar32 + 100) = uVar9;
            uVar9 = *(undefined4 *)(iVar32 + 0x68);
            switch(*(undefined4 *)(iVar32 + 0x68)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar24) {
              case 0x87d5:
code_r0x000822dc:
                uVar9 = 0x87d9;
                break;
              case 0x87d6:
code_r0x000822d0:
                uVar9 = 0x87da;
                break;
              case 0x87d7:
code_r0x0008233c:
                uVar9 = 0x87db;
                break;
              case 0x87d8:
code_r0x00082330:
                uVar9 = 0x87dc;
                break;
              case 0x87d9:
code_r0x00082324:
                uVar9 = 0x87d5;
                break;
              case 0x87da:
code_r0x00082318:
                uVar9 = 0x87d6;
                break;
              case 0x87db:
code_r0x0008230c:
                uVar9 = 0x87d7;
                break;
              case 0x87dc:
code_r0x00082300:
                uVar9 = 0x87d8;
                break;
              default:
                goto code_r0x000822c8;
              case 0x87de:
code_r0x000822f4:
                uVar9 = 0x87df;
                break;
              case 0x87df:
code_r0x000822e8:
                uVar9 = 0x87de;
              }
              goto code_r0x00082344;
            case 0x87da:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x000822dc;
              case 0x87d6:
                goto code_r0x000822d0;
              case 0x87d7:
                goto code_r0x0008233c;
              case 0x87d8:
                goto code_r0x00082330;
              case 0x87d9:
                goto code_r0x00082324;
              case 0x87da:
                goto code_r0x00082318;
              case 0x87db:
                goto code_r0x0008230c;
              case 0x87dc:
                goto code_r0x00082300;
              case 0x87de:
                goto code_r0x000822f4;
              case 0x87df:
                goto code_r0x000822e8;
              }
              break;
            case 0x87db:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x000822dc;
              case 0x87d6:
                goto code_r0x000822d0;
              case 0x87d7:
                goto code_r0x0008233c;
              case 0x87d8:
                goto code_r0x00082330;
              case 0x87d9:
                goto code_r0x00082324;
              case 0x87da:
                goto code_r0x00082318;
              case 0x87db:
                goto code_r0x0008230c;
              case 0x87dc:
                goto code_r0x00082300;
              case 0x87de:
                goto code_r0x000822f4;
              case 0x87df:
                goto code_r0x000822e8;
              }
              break;
            case 0x87dc:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x000822dc;
              case 0x87d6:
                goto code_r0x000822d0;
              case 0x87d7:
                goto code_r0x0008233c;
              case 0x87d8:
                goto code_r0x00082330;
              case 0x87d9:
                goto code_r0x00082324;
              case 0x87da:
                goto code_r0x00082318;
              case 0x87db:
                goto code_r0x0008230c;
              case 0x87dc:
                goto code_r0x00082300;
              case 0x87de:
                goto code_r0x000822f4;
              case 0x87df:
                goto code_r0x000822e8;
              }
              break;
            default:
              goto code_r0x00082344;
            }
code_r0x000822c8:
            uVar9 = uVar24;
code_r0x00082344:
            *(undefined4 *)(iVar32 + 0x68) = uVar9;
            uVar9 = *(undefined4 *)(iVar32 + 0x6c);
            switch(*(undefined4 *)(iVar32 + 0x6c)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar24) {
              case 0x87d5:
code_r0x0008250c:
                uVar9 = 0x87d9;
                break;
              case 0x87d6:
code_r0x00082500:
                uVar9 = 0x87da;
                break;
              case 0x87d7:
code_r0x0008256c:
                uVar9 = 0x87db;
                break;
              case 0x87d8:
code_r0x00082560:
                uVar9 = 0x87dc;
                break;
              case 0x87d9:
code_r0x00082554:
                uVar9 = 0x87d5;
                break;
              case 0x87da:
code_r0x00082548:
                uVar9 = 0x87d6;
                break;
              case 0x87db:
code_r0x0008253c:
                uVar9 = 0x87d7;
                break;
              case 0x87dc:
code_r0x00082530:
                uVar9 = 0x87d8;
                break;
              default:
                goto code_r0x000824f8;
              case 0x87de:
code_r0x00082524:
                uVar9 = 0x87df;
                break;
              case 0x87df:
code_r0x00082518:
                uVar9 = 0x87de;
              }
              goto code_r0x00082574;
            case 0x87da:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x0008250c;
              case 0x87d6:
                goto code_r0x00082500;
              case 0x87d7:
                goto code_r0x0008256c;
              case 0x87d8:
                goto code_r0x00082560;
              case 0x87d9:
                goto code_r0x00082554;
              case 0x87da:
                goto code_r0x00082548;
              case 0x87db:
                goto code_r0x0008253c;
              case 0x87dc:
                goto code_r0x00082530;
              case 0x87de:
                goto code_r0x00082524;
              case 0x87df:
                goto code_r0x00082518;
              }
              break;
            case 0x87db:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x0008250c;
              case 0x87d6:
                goto code_r0x00082500;
              case 0x87d7:
                goto code_r0x0008256c;
              case 0x87d8:
                goto code_r0x00082560;
              case 0x87d9:
                goto code_r0x00082554;
              case 0x87da:
                goto code_r0x00082548;
              case 0x87db:
                goto code_r0x0008253c;
              case 0x87dc:
                goto code_r0x00082530;
              case 0x87de:
                goto code_r0x00082524;
              case 0x87df:
                goto code_r0x00082518;
              }
              break;
            case 0x87dc:
              switch(uVar24) {
              case 0x87d5:
                goto code_r0x0008250c;
              case 0x87d6:
                goto code_r0x00082500;
              case 0x87d7:
                goto code_r0x0008256c;
              case 0x87d8:
                goto code_r0x00082560;
              case 0x87d9:
                goto code_r0x00082554;
              case 0x87da:
                goto code_r0x00082548;
              case 0x87db:
                goto code_r0x0008253c;
              case 0x87dc:
                goto code_r0x00082530;
              case 0x87de:
                goto code_r0x00082524;
              case 0x87df:
                goto code_r0x00082518;
              }
              break;
            default:
              goto code_r0x00082574;
            }
code_r0x000824f8:
            uVar9 = uVar24;
code_r0x00082574:
            *(undefined4 *)(iVar32 + 0x6c) = uVar9;
code_r0x00082578:
            if ((*(int *)(iVar32 + 4) != 2) ||
               (bVar33 = true, *(int *)(iVar32 + 8) != *(int *)(iVar31 + -0x6c))) {
              bVar33 = false;
            }
            uVar18 = *(uint *)(param_2 + 0x14);
          } while ((uVar25 + 1 < uVar18) && (iVar23 = iVar23 + 0x74, uVar25 = uVar25 + 1, !bVar33));
          iVar31 = iVar11;
          if (uVar30 < uVar18) {
            do {
              uVar30 = uVar30 + 1;
              iVar23 = iVar31 + *(int *)(param_2 + 0x18);
              _memcpy(iVar23 + -0x74,iVar23,0x74);
              uVar18 = *(uint *)(param_2 + 0x14);
              iVar31 = iVar31 + 0x74;
            } while (uVar30 < uVar18);
          }
        }
        *(uint *)(param_2 + 0x14) = uVar18 - 1;
      }
code_r0x00082600:
      uVar15 = uVar15 + 1;
      iVar11 = iVar11 + -0x74;
    } while (uVar16 != uVar15);
    uVar15 = *(uint *)(param_2 + 0x14);
  }
  do {
    while( true ) {
      uVar16 = uVar15;
      if (uVar16 < 2) {
        return;
      }
      iVar31 = uVar16 * 0x74;
      iVar11 = iVar31 + *(int *)(param_2 + 0x18);
      if (((*(int *)(iVar11 + -0x74) == 0x879c) && (*(int *)(iVar11 + -0x54) == 2)) &&
         (iVar23 = FUN_000550e0(param_2 + 0x1c,iVar11 + -0x54), iVar23 == 0x87be)) break;
code_r0x00082770:
      uVar15 = uVar16 - 1;
    }
    if (uVar16 < *(uint *)(param_2 + 0x14)) {
      iVar23 = *(uint *)(param_2 + 0x14) - uVar16;
      bVar33 = true;
      piVar21 = (int *)(iVar31 + *(int *)(param_2 + 0x18) + 0x20);
      do {
        if ((((*piVar21 == 2) && (piVar21[1] == *(int *)(iVar11 + -0x50))) ||
            ((piVar21[7] == 2 && (piVar21[8] == *(int *)(iVar11 + -0x50))))) ||
           ((piVar21[0xe] == 2 && (piVar21[0xf] == *(int *)(iVar11 + -0x50))))) {
          bVar34 = true;
          bVar33 = false;
        }
        else if ((piVar21[-7] != 2) || (bVar34 = true, piVar21[-6] != *(int *)(iVar11 + -0x50))) {
          bVar34 = false;
        }
        iVar23 = iVar23 + -1;
      } while ((iVar23 != 0) && (piVar21 = piVar21 + 0x1d, !bVar34));
      if (!bVar33) goto code_r0x00082770;
    }
    uVar15 = uVar16 - 1;
    if (uVar15 != 0) {
      iVar23 = uVar15 * 0x74;
      bVar33 = false;
      uVar30 = uVar15;
      do {
        iVar32 = iVar23 + *(int *)(param_2 + 0x18);
        if ((*(int *)(iVar32 + -0x70) == 2) &&
           (*(int *)(iVar32 + -0x6c) == *(int *)(iVar11 + -0x50))) {
          if (*(int *)(iVar32 + -0x74) - 0x879bU < 2) {
code_r0x0008286c:
            bVar34 = true;
          }
          else {
            uVar22 = *(undefined4 *)(iVar11 + -100);
            bVar34 = true;
            bVar33 = true;
            uVar19 = *(undefined4 *)(iVar11 + -0x60);
            uVar24 = *(undefined4 *)(iVar11 + -0x5c);
            uVar9 = *(undefined4 *)(iVar11 + -0x70);
            uVar20 = *(undefined4 *)(iVar11 + -0x6c);
            *(undefined4 *)(iVar32 + -0x68) = *(undefined4 *)(iVar11 + -0x68);
            *(undefined4 *)(iVar32 + -100) = uVar22;
            *(undefined4 *)(iVar32 + -0x5c) = uVar24;
            *(undefined4 *)(iVar32 + -0x60) = uVar19;
            *(undefined4 *)(iVar32 + -0x70) = uVar9;
            *(undefined4 *)(iVar32 + -0x6c) = uVar20;
          }
        }
        else {
          if ((((*(int *)(iVar32 + -0x54) == 2) &&
               (*(int *)(iVar32 + -0x50) == *(int *)(iVar11 + -0x50))) ||
              ((*(int *)(iVar32 + -0x38) == 2 &&
               (*(int *)(iVar32 + -0x34) == *(int *)(iVar11 + -0x50))))) ||
             ((*(int *)(iVar32 + -0x1c) == 2 &&
              (*(int *)(iVar32 + -0x18) == *(int *)(iVar11 + -0x50))))) goto code_r0x0008286c;
          bVar34 = false;
        }
        uVar30 = uVar30 - 1;
      } while ((uVar30 != 0) && (iVar23 = iVar23 + -0x74, !bVar34));
      if (bVar33) {
        uVar30 = *(uint *)(param_2 + 0x14);
        if (uVar16 < uVar30) {
          do {
            uVar16 = uVar16 + 1;
            iVar11 = iVar31 + *(int *)(param_2 + 0x18);
            iVar31 = iVar31 + 0x74;
            _memcpy(iVar11 + -0x74,iVar11,0x74);
            uVar30 = *(uint *)(param_2 + 0x14);
          } while (uVar16 < uVar30);
        }
        *(uint *)(param_2 + 0x14) = uVar30 - 1;
      }
    }
  } while( true );
LAB_0007e2d4:
  if (bVar6) {
    if (uVar30 < uVar16) {
      do {
        uVar30 = uVar30 + 1;
        iVar11 = iVar32 + *(int *)(param_2 + 0x18);
        iVar32 = iVar32 + 0x74;
        uStack_70 = uVar24;
        _memcpy(iVar11 + -0x74,iVar11,0x74);
        uVar16 = *(uint *)(param_2 + 0x14);
        uVar24 = uStack_70;
      } while (uVar30 < uVar16);
    }
    uVar16 = uVar16 - 1;
    *(uint *)(param_2 + 0x14) = uVar16;
  }
LAB_0007e2e0:
  uVar15 = uVar15 + 1;
  if (uVar16 <= uVar15) goto LAB_0007e330;
  goto LAB_0007de3c;
}

/* FUN_00082900 @ 0x82900 (812 bytes) */
int FUN_00082900(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  undefined4 *puVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  uint uVar6;
  undefined4 a4;
  uint uVar7;
  code *a5;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint uVar13;
  
  iVar8 = *(int *)(param_2 + 0x54);
  uVar13 = *(uint *)(iVar8 + 0x3cc);
  puVar12 = *(undefined4 **)(iVar8 + 0x3c8);
  if ((uVar13 == 0) || (puVar12 == (undefined4 *)0x0)) {
    return;
  }
  uVar9 = *(uint *)(param_1 + 0x8c);
  if ((uVar9 & 0x40000) == 0) {
LAB_00082b00:
    uVar6 = *(uint *)(param_1 + 0x3cc);
    uVar9 = *(uint *)(param_1 + 0x1b90);
    a4 = *(undefined4 *)(param_1 + 0x3d0);
    a5 = *(code **)(param_1 + 0x2758);
    *(uint *)(param_1 + 0x1b90) = uVar6 & 0x3ff | uVar9 & 0xfffffc00;
    *(uint *)(param_1 + 0x1b90) =
         (uVar6 + uVar13 + -1) * 0x100000 & 0x3ff00000 |
         (uVar6 + *(int *)(param_2 + 0x34)) * 0x400 & 0xffc00 | uVar6 & 0x3ff | uVar9 & 0xc0000000;
    iVar8 = *(int *)(param_2 + 0x38);
    *(char *)(param_1 + 0x1b8f) = (char)a4;
    uVar6 = uVar6 + iVar8;
    uVar13 = uVar6 & 0x3ff | *(uint *)(param_1 + 0x1b94) & 0xfffffc00;
    *(uint *)(param_1 + 0x1b94) = uVar13;
    *(char *)(param_1 + 0x1b8d) = (char)*(undefined4 *)(param_2 + 0x48);
    puVar12 = (undefined4 *)(*a5)(param_1,4,in_r5,in_r6,a4,a5,uVar6,uVar13);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar12;
    *puVar12 = 0x208b4;
    puVar12[1] = *(undefined4 *)(param_1 + 0x1b90);
    puVar12[2] = *(undefined4 *)(param_1 + 0x1b8c);
    puVar12[3] = *(undefined4 *)(param_1 + 0x1b94);
    pcVar4 = *(code **)(param_1 + 0x275c);
    iVar8 = *(int *)(0x00002748 + param_1 + 4) + 0x10;
    *(int *)(0x00002748 + param_1 + 4) = iVar8;
    (*pcVar4)(param_1,iVar8,in_r5,in_r6,a4,a5,iVar8);
    puVar12 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar12;
    *puVar12 = 0x8b7;
    puVar12[1] = *(undefined4 *)(param_1 + 0x1b98);
    iVar8 = *(int *)(0x00002748 + param_1 + 4);
    pcVar4 = *(code **)(param_1 + 0x275c);
    *(int *)(0x00002748 + param_1 + 4) = iVar8 + 8;
    (*pcVar4)(param_1,iVar8 + 8,in_r5,in_r6,a4,a5,puVar12);
    FUN_00050ef0(param_1,*(undefined4 *)(param_2 + 0x3c),*(undefined4 *)(param_2 + 0x40),
                 *(undefined4 *)(param_2 + 0x44));
    return;
  }
  iVar10 = *(int *)(param_1 + 0xd8);
  uVar11 = 0;
  uVar7 = 0;
  uVar2 = 0;
  uVar6 = 0;
  do {
    if (iVar10 == 1) goto LAB_000829a0;
    if (iVar10 == 0) {
      uVar6 = (uint)(*(ushort *)(((unsigned char *)0x000013be) + param_1) >> 1);
      uVar11 = *(uint *)(iVar8 + 0x3e4) >> 1;
      uVar2 = uVar11 - 2;
      uVar7 = uVar6;
      goto LAB_000829e0;
    }
    if (iVar10 != 2) goto LAB_000829e0;
    while( true ) {
      uVar2 = *(uint *)(iVar8 + 0x3e4);
      uVar6 = (uint)*(ushort *)(((unsigned char *)0x000013be) + param_1);
      uVar11 = 0;
      uVar9 = uVar9 | 0x18000;
      *(uint *)(param_1 + 0x8c) = uVar9;
      uVar7 = 0;
LAB_000829e0:
      while( true ) {
        if ((uVar13 <= uVar2) && (*(uint *)(param_2 + 0x48) <= uVar6)) {
          *(uint *)(param_1 + 0x3d0) = uVar7;
          *(uint *)(param_1 + 0x3cc) = uVar11;
          iVar8 = uVar13 * 4 + 5;
          puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar8);
          *(undefined4 **)(0x00002748 + param_1 + 4) = puVar5;
          puVar5[3] = uVar11;
          *puVar5 = 0x8a1;
          puVar5[1] = 0;
          puVar5[4] = (uVar13 * 4 + -1) * 0x10000 | 0x8882;
          puVar5[2] = 0x880;
          puVar5 = puVar5 + 5;
          uVar9 = uVar13;
          do {
            *puVar5 = *puVar12;
            puVar5[1] = puVar12[1];
            puVar5[2] = puVar12[2];
            puVar1 = puVar12 + 3;
            puVar12 = puVar12 + 4;
            puVar5[3] = *puVar1;
            puVar5 = puVar5 + 4;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
          pcVar4 = *(code **)(param_1 + 0x275c);
          iVar8 = iVar8 * 4 + *(int *)(0x00002748 + param_1 + 4);
          *(int *)(0x00002748 + param_1 + 4) = iVar8;
          (*pcVar4)(param_1,iVar8);
          if (*(int *)(param_1 + 0xd8) == 0) {
            *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xfffbffff;
          }
          goto LAB_00082b00;
        }
        if (iVar10 != 0) break;
        iVar10 = 1;
        *(undefined4 *)(param_1 + 0xd8) = 1;
LAB_000829a0:
        iVar3 = *(int *)(iVar8 + 0x3e4);
        uVar6 = (uint)*(ushort *)(((unsigned char *)0x000013be) + param_1);
        uVar9 = uVar9 | 0x10000;
        uVar11 = 0;
        *(uint *)(param_1 + 0x8c) = uVar9;
        uVar2 = iVar3 - 2;
        uVar7 = 0;
      }
      if (iVar10 != 1) break;
      iVar10 = 2;
      *(undefined4 *)(param_1 + 0xd8) = 2;
    }
  } while( true );
}

/* FUN_00082c50 @ 0x82c50 (760 bytes) */
int FUN_00082c50(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  puVar1 = (undefined4 *)
           (**(code **)(param_1 + 0x2758))
                     (param_1,2,param_3,param_4,param_5,param_6,param_7,param_8);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar1;
  puVar1[1] = 0;
  *puVar1 = 0x8a1;
  iVar2 = *(int *)(0x00002748 + param_1 + 4);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(0x00002748 + param_1 + 4) = iVar2 + 8;
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar2 + 8);
  if (*(char *)(param_2 + 0x58) == '\0') {
    if (*(int *)(param_2 + 0x48) == 0) {
      return;
    }
    puVar7 = *(undefined4 **)(param_2 + 0x4c);
    ((void (*)())FUN_0009f0b0)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,fparam_1,in_f2,
                 in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffffa8,in_stack_ffffffb0,
                 in_stack_ffffffb8,in_stack_ffffffc0,in_stack_ffffffc8);
    iVar2 = *(int *)(param_2 + 0x48) * 4 + 3;
    puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar2);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar1;
    puVar4 = puVar1 + 3;
    *puVar1 = 0x880;
    puVar1[1] = *(int *)(param_1 + 0x2448) + *(int *)(param_1 + 0x3d0);
    puVar1[2] = *(int *)(param_2 + 0x48) * 0x40000 - 0x10000U | 0x8882;
    if (*(int *)(param_2 + 0x48) != 0) {
      uVar5 = 0;
      do {
        uVar5 = uVar5 + 1;
        *puVar4 = *puVar7;
        puVar4[1] = puVar7[1];
        puVar4[2] = puVar7[2];
        puVar1 = puVar7 + 3;
        puVar7 = puVar7 + 4;
        puVar4[3] = *puVar1;
        puVar4 = puVar4 + 4;
      } while (uVar5 < *(uint *)(param_2 + 0x48));
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
    *(int *)(0x00002748 + param_1 + 4) = iVar2 * 4 + *(int *)(0x00002748 + param_1 + 4);
  }
  else {
    puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x13);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar1;
    *puVar1 = 0x880;
    iVar2 = *(int *)(param_1 + 0x2448);
    iVar3 = *(int *)(param_1 + 0x3d0);
    puVar1[2] = 0xf8882;
    puVar1[1] = iVar2 + iVar3;
    if ((*(uint *)(((unsigned char *)0x000013c0) + param_1) & 4) == 0) {
      puVar1[3] = *(undefined4 *)(iVar6 + 0x2460);
      puVar1[4] = *(undefined4 *)(iVar6 + 0x2470);
      puVar1[5] = *(undefined4 *)(iVar6 + 0x2480);
      puVar1[6] = *(undefined4 *)(iVar6 + 0x2490);
      puVar1[7] = *(undefined4 *)(iVar6 + 0x2464);
      puVar1[8] = *(undefined4 *)(iVar6 + 0x2474);
      puVar1[9] = *(undefined4 *)(iVar6 + 0x2484);
      puVar1[10] = *(undefined4 *)(iVar6 + 0x2494);
      puVar1[0xb] = *(undefined4 *)(iVar6 + 0x2468);
      puVar1[0xc] = *(undefined4 *)(iVar6 + 0x2478);
      puVar1[0xd] = *(undefined4 *)(iVar6 + 0x2488);
      puVar1[0xe] = *(undefined4 *)(iVar6 + 0x2498);
      puVar1[0xf] = *(undefined4 *)(iVar6 + 0x246c);
      puVar1[0x10] = *(undefined4 *)(iVar6 + 0x247c);
      puVar1[0x11] = *(undefined4 *)(iVar6 + 0x248c);
      puVar1[0x12] = *(undefined4 *)(iVar6 + 0x249c);
    }
    else {
      puVar1[3] = *(undefined4 *)(iVar6 + 0x2460);
      puVar1[4] = *(undefined4 *)(iVar6 + 0x2464);
      puVar1[5] = *(undefined4 *)(iVar6 + 0x2468);
      puVar1[6] = *(undefined4 *)(iVar6 + 0x246c);
      puVar1[7] = *(undefined4 *)(iVar6 + 0x2470);
      puVar1[8] = *(undefined4 *)(iVar6 + 0x2474);
      puVar1[9] = *(undefined4 *)(iVar6 + 0x2478);
      puVar1[10] = *(undefined4 *)(iVar6 + 0x247c);
      puVar1[0xb] = *(undefined4 *)(iVar6 + 0x2480);
      puVar1[0xc] = *(undefined4 *)(iVar6 + 0x2484);
      puVar1[0xd] = *(undefined4 *)(iVar6 + 0x2488);
      puVar1[0xe] = *(undefined4 *)(iVar6 + 0x248c);
      puVar1[0xf] = *(undefined4 *)(iVar6 + 0x2490);
      puVar1[0x10] = *(undefined4 *)(iVar6 + 0x2494);
      puVar1[0x11] = *(undefined4 *)(iVar6 + 0x2498);
      puVar1[0x12] = *(undefined4 *)(iVar6 + 0x249c);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
    *(int *)(0x00002748 + param_1 + 4) = *(int *)(0x00002748 + param_1 + 4) + 0x4c;
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}

/* FUN_00082f60 @ 0x82f60 (416 bytes) */
int FUN_00082f60(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  uint *param_4;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  _memset(param_2 + 0x68,0xffffffff,0x3c);
  bVar1 = (*(uint *)(param_1 + 0x1b9c) & 1) != 0;
  if (bVar1) {
    *(undefined4 *)(param_2 + 0x68) = 0;
  }
  uVar3 = (uint)bVar1;
  uVar2 = *(uint *)(param_1 + 0x1b9c);
  if ((uVar2 & 0x10000) != 0) {
    *(uint *)(param_2 + 0x6c) = uVar3;
    uVar3 = uVar3 + 1;
    uVar2 = *(uint *)(param_1 + 0x1b9c);
  }
  if ((uVar2 & 2) != 0) {
    *(uint *)(param_2 + 0x74) = uVar3;
    uVar3 = uVar3 + 1;
    uVar2 = *(uint *)(param_1 + 0x1b9c);
  }
  if ((uVar2 & 4) != 0) {
    *(uint *)(param_2 + 0x7c) = uVar3;
    if (((*(uint *)(param_1 + 0x44) & 0x1000000) != 0) && (*(char *)(param_1 + 0x121) == '\0')) {
      *(uint *)(param_2 + 0x70) = uVar3;
    }
    uVar2 = *(uint *)(param_1 + 0x1b9c);
    uVar3 = uVar3 + 1;
  }
  if ((uVar2 & 8) != 0) {
    *(uint *)(param_2 + 0x78) = uVar3;
    uVar3 = uVar3 + 1;
    uVar2 = *(uint *)(param_1 + 0x1b9c);
  }
  if ((uVar2 & 0x10) != 0) {
    *(uint *)(param_2 + 0x80) = uVar3;
    uVar3 = uVar3 + 1;
  }
  uVar2 = *(uint *)(param_1 + 0x1ba0);
  if ((uVar2 & 7) != 0) {
    *(uint *)(param_2 + 0x84) = uVar3;
    uVar3 = uVar3 + 1;
    uVar2 = *(uint *)(param_1 + 0x1ba0);
  }
  if ((uVar2 & 0x38) != 0) {
    *(uint *)(param_2 + 0x88) = uVar3;
    uVar3 = uVar3 + 1;
    uVar2 = *(uint *)(param_1 + 0x1ba0);
  }
  if ((uVar2 & 0x1c0) != 0) {
    *(uint *)(param_2 + 0x8c) = uVar3;
    uVar3 = uVar3 + 1;
    uVar2 = *(uint *)(param_1 + 0x1ba0);
  }
  if ((uVar2 & 0xe00) != 0) {
    *(uint *)(param_2 + 0x90) = uVar3;
    uVar3 = uVar3 + 1;
    uVar2 = *(uint *)(param_1 + 0x1ba0);
  }
  if ((uVar2 & 0x7000) != 0) {
    *(uint *)(param_2 + 0x94) = uVar3;
    uVar3 = uVar3 + 1;
    uVar2 = *(uint *)(param_1 + 0x1ba0);
  }
  if ((uVar2 & 0x38000) != 0) {
    *(uint *)(param_2 + 0x98) = uVar3;
    uVar3 = uVar3 + 1;
    uVar2 = *(uint *)(param_1 + 0x1ba0);
  }
  if ((uVar2 & 0x1c0000) != 0) {
    *(uint *)(param_2 + 0x9c) = uVar3;
    uVar3 = uVar3 + 1;
    uVar2 = *(uint *)(param_1 + 0x1ba0);
  }
  if ((uVar2 & 0xe00000) != 0) {
    *(uint *)(param_2 + 0xa0) = uVar3;
    uVar3 = uVar3 + 1;
  }
  (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,0);
  *param_4 = uVar3;
  return;
}

