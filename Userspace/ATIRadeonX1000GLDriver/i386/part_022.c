#include "decls.h"

/* FUN_000e9540 @ 0xe9540 (45 bytes) */
int FUN_000e9540(param_1, param_2)
  int param_1;
  int param_2;
{
  FUN_001a7cee(param_2,*(undefined4 *)(param_1 + 200));
  *(int *)(param_2 + 0x158) = param_1;
  return;
}

/* FUN_000e956e @ 0xe956e (40 bytes) */
int FUN_000e956e(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_001a7cb8(param_3,param_2);
  *(undefined4 *)(param_3 + 0x158) = param_1;
  return;
}

/* FUN_000e9596 @ 0xe9596 (40 bytes) */
int FUN_000e9596(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_001a7cee(param_3,param_2);
  *(undefined4 *)(param_3 + 0x158) = param_1;
  return;
}

/* FUN_000e95be @ 0xe95be (74 bytes) */
int FUN_000e95be(param_1)
  int *param_1;
{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 uVar6;
  
  uVar6 = &STACKARG(0x0) == segment_command_0000001c.segname + 8;
  pcVar1 = (char *)(**(code **)(*param_1 + 0x4c))();
  iVar2 = 7;
  pcVar4 = "SIMPLE";
  do {
    pcVar3 = pcVar1;
    pcVar5 = pcVar4;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar5 = pcVar4 + 1;
    pcVar3 = pcVar1 + 1;
    uVar6 = *pcVar1 == *pcVar4;
    pcVar1 = pcVar3;
    pcVar4 = pcVar5;
  } while ((bool)uVar6);
  iVar2 = 0;
  if (!(bool)uVar6) {
    iVar2 = (uint)(byte)pcVar3[-1] - (uint)(byte)pcVar5[-1];
  }
  return iVar2 == 0;
}

/* FUN_000e9608 @ 0xe9608 (36 bytes) */
int FUN_000e9608(param_1)
  int param_1;
{
  if (*(char *)(param_1 + 300) != '\0') {
    return "REP_HEADER";
  }
  return "LOOP_HEADER";
}

/* FUN_000e962c @ 0xe962c (24 bytes) */
int FUN_000e962c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x148) = param_2;
  *(undefined1 *)(param_1 + 0x144) = 1;
  return;
}

/* FUN_000e9644 @ 0xe9644 (97 bytes) */
int FUN_000e9644(param_1)
  int param_1;
{
  int iVar1;
  char cVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x98);
  iVar1 = piVar3[2];
  while (iVar1 != 0) {
    while ((((*(byte *)(piVar3 + 5) & 1) == 0 ||
            (cVar2 = (**(code **)(*piVar3 + 0x34))(piVar3), cVar2 != '\0')) ||
           (cVar2 = (**(code **)(*piVar3 + 0x38))(piVar3), cVar2 != '\0'))) {
      piVar3 = (int *)piVar3[2];
      if (piVar3[2] == 0) goto LAB_000e9698;
    }
    (**(code **)(*piVar3 + 0x18))(piVar3);
    piVar3 = (int *)piVar3[2];
    iVar1 = piVar3[2];
  }
LAB_000e9698:
  return *(undefined4 *)(param_1 + 0x128);
}

/* FUN_000e96a6 @ 0xe96a6 (65 bytes) */
int FUN_000e96a6(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0xb8) = param_2;
  if (*(int *)(param_1 + 300) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 300) + 0xb8) = param_2;
  }
  if (*(int *)(param_1 + 0x130) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x130) + 0xb8) = param_2;
  }
  if (*(int *)(param_1 + 0x134) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x134) + 0xb8) = param_2;
  }
  return;
}

/* FUN_000e96e8 @ 0xe96e8 (40 bytes) */
int FUN_000e96e8(param_1, param_2)
  int param_1;
  int param_2;
{
  do {
    if (param_2 == param_1) {
      return 1;
    }
    param_2 = *(int *)(param_2 + 0xec);
  } while (param_2 != 0);
  return 0;
}

/* FUN_000e9710 @ 0xe9710 (80 bytes) */
int FUN_000e9710(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  
  while( true ) {
    cVar1 = ((int (*)())FUN_000e96e8)(param_1,param_2);
    if (cVar1 != '\0') {
      return param_1;
    }
    cVar1 = ((int (*)())FUN_000e96e8)(param_2,param_1);
    if (cVar1 != '\0') break;
    param_1 = *(int *)(param_1 + 0xec);
    param_2 = *(int *)(param_2 + 0xec);
  }
  return param_2;
}

/* FUN_000e9760 @ 0xe9760 (25 bytes) */
int FUN_000e9760(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0xf4) + 4) != 0;
}

/* FUN_000e977a @ 0xe977a (24 bytes) */
int FUN_000e977a(param_1)
  int param_1;
{
  return 1 < *(uint *)(*(int *)(param_1 + 0xd0) + 4);
}

/* FUN_000e9792 @ 0xe9792 (24 bytes) */
int FUN_000e9792(param_1)
  int param_1;
{
  return 1 < *(uint *)(*(int *)(param_1 + 0xd4) + 4);
}

/* FUN_000e97aa @ 0xe97aa (17 bytes) */
int FUN_000e97aa(param_1)
  int param_1;
{
  return *(undefined4 *)(*(int *)(param_1 + 0xd0) + 4);
}

/* FUN_000e97bc @ 0xe97bc (17 bytes) */
int FUN_000e97bc(param_1)
  int param_1;
{
  return *(undefined4 *)(*(int *)(param_1 + 0xd4) + 4);
}

/* FUN_000e97ce @ 0xe97ce (25 bytes) */
int FUN_000e97ce(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0xd0) + 4) != 0;
}

/* FUN_000e97e8 @ 0xe97e8 (25 bytes) */
int FUN_000e97e8(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0xd4) + 4) != 0;
}

/* FUN_000e9802 @ 0xe9802 (25 bytes) */
int FUN_000e9802(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0xf0) + 4) != 0;
}

/* FUN_000e981c @ 0xe981c (78 bytes) */
int FUN_000e981c(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  while (iVar2 = *(int *)(param_1 + 0xc4), *(int *)(iVar2 + 4) != 0) {
    uVar3 = *(uint *)(iVar2 + 4);
    if (uVar3 - 1 < uVar3) {
      puVar4 = (undefined4 *)(*(int *)(iVar2 + 8) + (uVar3 - 1) * 4);
    }
    else {
      puVar4 = (undefined4 *)0x0;
    }
    uVar1 = *puVar4;
    FUN_001a7f3c(iVar2,uVar3 - 1);
    FUN_0012a2c4(uVar1);
  }
  return;
}

/* FUN_000e986a @ 0xe986a (146 bytes) */
int FUN_000e986a(param_1)
  int *param_1;
{
  int *piVar1;
  char cVar2;
  int *piVar3;
  
  piVar3 = (int *)param_1[0x4c];
  if (piVar3 == (int *)0x0) {
    return param_1;
  }
  do {
    cVar2 = ((int (*)())FUN_000e97ce)(piVar3);
    if (cVar2 == '\0') {
      return piVar3;
    }
    cVar2 = (**(code **)(*piVar3 + 0x38))(piVar3);
    if (cVar2 != '\0') {
      return piVar3;
    }
    cVar2 = (**(code **)(*piVar3 + 0x3c))(piVar3);
    if (cVar2 != '\0') {
      return piVar3;
    }
    cVar2 = (**(code **)(*piVar3 + 0x2c))(piVar3);
    if (cVar2 == '\0') {
      cVar2 = (**(code **)(*piVar3 + 0x24))(piVar3);
      if (cVar2 == '\0') {
        piVar1 = piVar3 + 0x34;
        piVar3 = (int *)MACH_HEADER.magic;
        if (*(int *)(*piVar1 + 4) != 0) {
          piVar3 = (int *)**(undefined4 **)(*piVar1 + 8);
        }
      }
      else {
        piVar3 = (int *)piVar3[0x4d];
      }
    }
    else {
      piVar3 = (int *)piVar3[0x51];
    }
  } while (piVar3 != (int *)0x0);
  return (int *)0x0;
}

/* FUN_000e98fc @ 0xe98fc (136 bytes) */
int FUN_000e98fc(param_1)
  int param_1;
{
  int *piVar1;
  int *piVar2;
  char cVar3;
  
  piVar2 = *(int **)(param_1 + 300);
  while ((((piVar2 != (int *)0x0 && (cVar3 = ((int (*)())FUN_000e97ce)(piVar2), cVar3 != '\0')) &&
          (cVar3 = (**(code **)(*piVar2 + 0x38))(piVar2), cVar3 == '\0')) &&
         (cVar3 = (**(code **)(*piVar2 + 0x3c))(piVar2), cVar3 == '\0'))) {
    cVar3 = (**(code **)(*piVar2 + 0x2c))(piVar2);
    if (cVar3 == '\0') {
      cVar3 = (**(code **)(*piVar2 + 0x24))(piVar2);
      if (cVar3 == '\0') {
        piVar1 = piVar2 + 0x34;
        piVar2 = (int *)MACH_HEADER.magic;
        if (*(int *)(*piVar1 + 4) != 0) {
          piVar2 = (int *)**(undefined4 **)(*piVar1 + 8);
        }
      }
      else {
        piVar2 = (int *)piVar2[0x4d];
      }
    }
    else {
      piVar2 = (int *)piVar2[0x51];
    }
  }
  return piVar2;
}

/* FUN_000e9984 @ 0xe9984 (44 bytes) */
int FUN_000e9984(param_1)
  int param_1;
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xa0);
  (**(code **)(*piVar1 + 0x38))(piVar1);
  if ((*(byte *)(piVar1[1] + 0x14) & 8) != 0) {
    piVar1 = *(int **)(piVar1[1] + 4);
  }
  return piVar1;
}

/* FUN_000e99b0 @ 0xe99b0 (108 bytes) */
int FUN_000e99b0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(param_2 + 0x84) != 0) {
    FUN_0010b180(param_2,1);
    FUN_001a7cee(param_2,*(undefined4 *)(param_1 + 0x124));
    *(int *)(param_2 + 0x158) = param_1;
    return;
  }
  FUN_001a7cee(param_2,*(undefined4 *)(param_1 + 0x124));
  *(int *)(param_1 + 0x124) = param_2;
  *(int *)(param_2 + 0x158) = param_1;
  return;
}

/* FUN_000e9a1c @ 0xe9a1c (102 bytes) */
int FUN_000e9a1c(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x98);
  iVar2 = *(int *)(iVar1 + 8);
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    if (((*(byte *)(iVar1 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar1 + 0x88) + 8) == 0x81))
    break;
    iVar1 = *(int *)(iVar1 + 8);
    iVar2 = *(int *)(iVar1 + 8);
  }
  iVar2 = FUN_0010b180(iVar1,1);
  if (iVar2 == 0) {
    return *(undefined4 *)(iVar1 + 0xac);
  }
  return *(undefined4 *)(iVar2 + 0x94);
}

/* FUN_000e9a82 @ 0xe9a82 (139 bytes) */
int FUN_000e9a82(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined1 local_1d;
  
  uVar2 = 1;
  iVar3 = 0;
  do {
    if (*(uint *)(*(int *)(param_2 + 0xd4) + 4) < uVar2) {
      local_1d = 0;
LAB_000e9aad:
      uVar2 = 1;
      iVar4 = 0;
      iVar3 = *(int *)(param_1 + 0xd0);
      if (*(int *)(iVar3 + 4) != 0) {
        do {
          iVar1 = *(int *)(*(int *)(iVar3 + 8) + iVar4);
          if ((iVar1 != 0) && (param_2 == iVar1)) {
            return local_1d;
          }
          uVar2 = uVar2 + 1;
          iVar4 = iVar4 + 4;
        } while (uVar2 <= *(uint *)(iVar3 + 4));
      }
      return local_1d;
    }
    iVar4 = *(int *)(iVar3 + *(int *)(*(int *)(param_2 + 0xd4) + 8));
    if ((iVar4 != 0) && (param_1 == iVar4)) {
      local_1d = 1;
      goto LAB_000e9aad;
    }
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + 4;
  } while( true );
}

/* FUN_000e9b0e @ 0xe9b0e (110 bytes) */
int FUN_000e9b0e(param_1)
  int param_1;
{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 1;
  iVar5 = 0;
  iVar3 = *(int *)(param_1 + 0xd4);
  if (*(int *)(iVar3 + 4) != 0) {
    do {
      piVar1 = *(int **)(*(int *)(iVar3 + 8) + iVar5);
      if (piVar1 != (int *)0x0) {
        cVar2 = ((int (*)())FUN_000e95be)(piVar1);
        if (cVar2 != '\0') {
          return piVar1;
        }
        cVar2 = (**(code **)(*piVar1 + 0x1c))(piVar1);
        if (cVar2 != '\0') {
          return piVar1;
        }
        iVar3 = *(int *)(param_1 + 0xd4);
      }
      uVar4 = uVar4 + 1;
      iVar5 = iVar5 + 4;
    } while (uVar4 <= *(uint *)(iVar3 + 4));
  }
  return (int *)0x0;
}

/* FUN_000e9b7c @ 0xe9b7c (110 bytes) */
int FUN_000e9b7c(param_1)
  int param_1;
{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 1;
  iVar5 = 0;
  iVar3 = *(int *)(param_1 + 0xd0);
  if (*(int *)(iVar3 + 4) != 0) {
    do {
      piVar1 = *(int **)(*(int *)(iVar3 + 8) + iVar5);
      if (piVar1 != (int *)0x0) {
        cVar2 = ((int (*)())FUN_000e95be)(piVar1);
        if (cVar2 != '\0') {
          return piVar1;
        }
        cVar2 = (**(code **)(*piVar1 + 0x20))(piVar1);
        if (cVar2 != '\0') {
          return piVar1;
        }
        iVar3 = *(int *)(param_1 + 0xd0);
      }
      uVar4 = uVar4 + 1;
      iVar5 = iVar5 + 4;
    } while (uVar4 <= *(uint *)(iVar3 + 4));
  }
  return (int *)0x0;
}

/* FUN_000e9bea @ 0xe9bea (84 bytes) */
int FUN_000e9bea(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  uVar3 = 1;
  iVar4 = 0;
  iVar1 = *(int *)(param_1 + 0xd0);
  if (*(int *)(iVar1 + 4) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(iVar1 + 8) + iVar4);
      if (iVar2 != 0) {
        if (iVar2 == param_2) {
          return iVar5;
        }
        iVar5 = iVar5 + 1;
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 4;
    } while (uVar3 <= *(uint *)(iVar1 + 4));
  }
  return -1;
}

/* FUN_000e9c3e @ 0xe9c3e (84 bytes) */
int FUN_000e9c3e(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  uVar3 = 1;
  iVar4 = 0;
  iVar1 = *(int *)(param_1 + 0xd4);
  if (*(int *)(iVar1 + 4) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(iVar1 + 8) + iVar4);
      if (iVar2 != 0) {
        if (iVar2 == param_2) {
          return iVar5;
        }
        iVar5 = iVar5 + 1;
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 4;
    } while (uVar3 <= *(uint *)(iVar1 + 4));
  }
  return -1;
}

/* FUN_000e9c92 @ 0xe9c92 (34 bytes) */
int FUN_000e9c92(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_000e9c3e)(param_1,param_2);
  if (iVar1 != -1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

/* FUN_000e9cb4 @ 0xe9cb4 (80 bytes) */
int FUN_000e9cb4(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 1;
  iVar4 = 0;
  iVar1 = *(int *)(param_1 + 0xd0);
  if (*(int *)(iVar1 + 4) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(iVar1 + 8) + iVar4);
      if ((iVar2 != 0) && (param_2 != *(int *)(iVar2 + 0x110))) {
        return iVar2;
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 4;
    } while (uVar3 <= *(uint *)(iVar1 + 4));
  }
  return 0;
}

/* FUN_000e9d04 @ 0xe9d04 (543 bytes) */
int FUN_000e9d04(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint local_14;
  uint local_10;
  
  puVar4 = *(uint **)(param_1 + 0x3b0);
  uVar3 = puVar4[1];
  if (uVar3 == 0) {
LAB_000e9d55:
    uVar8 = uVar3 + 1;
    if (uVar3 + 0x20 >> 5 == *puVar4) {
      puVar4[1] = uVar8;
      for (; uVar3 < uVar8; uVar3 = uVar3 + 2) {
        puVar4[(uVar3 >> 5) + 2] = puVar4[(uVar3 >> 5) + 2] & ~(1 << ((byte)uVar3 & 0x1f));
        uVar7 = uVar3 + 1;
        if (uVar8 <= uVar7) break;
        puVar4[(uVar7 >> 5) + 2] = puVar4[(uVar7 >> 5) + 2] & ~(1 << ((byte)uVar7 & 0x1f));
      }
      puVar4 = *(uint **)(param_1 + 0x3b0);
      if (puVar4[1] == 0) goto LAB_000e9e4b;
      if ((puVar4[2] & 1) != 0) {
        local_14 = 0;
        do {
          local_14 = local_14 + 1;
          if (puVar4[1] == local_14) goto LAB_000e9e4b;
        } while ((puVar4[(local_14 >> 5) + 2] >> ((byte)local_14 & 0x1f) & 1) != 0);
        goto LAB_000e9e15;
      }
    }
    else {
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
      uVar8 = uVar3 + 0x41f >> 5;
      puVar2 = (undefined4 *)FUN_001a7bca(uVar1,uVar8 * 4 + 0xc);
      puVar6 = puVar2 + 1;
      *puVar2 = uVar1;
      puVar2[2] = uVar3 + 0x400;
      puVar2[1] = uVar8;
      if (uVar8 != 0) {
        uVar3 = 0;
        puVar5 = puVar6;
        do {
          puVar5[2] = 0;
          uVar3 = uVar3 + 1;
          puVar5 = puVar5 + 1;
        } while (uVar3 < *puVar6);
      }
      *(uint **)(param_1 + 0x3b0) = puVar6;
      if (*puVar6 != 0) {
        uVar8 = 0;
        uVar3 = *puVar6;
        do {
          puVar6[2] = puVar6[2] | puVar4[2];
          uVar8 = uVar8 + 1;
          puVar6 = puVar6 + 1;
          puVar4 = puVar4 + 1;
        } while (uVar8 < uVar3);
      }
      puVar4 = *(uint **)(param_1 + 0x3b0);
      if (puVar4[1] == 0) {
LAB_000e9e4b:
        puVar4[0x8000001] = puVar4[0x8000001] | 0x80000000;
        return 0xffffffff;
      }
      if ((puVar4[2] & 1) != 0) {
        local_10 = 0;
        do {
          local_14 = local_10 + 1;
          if (local_14 == puVar4[1]) goto LAB_000e9e4b;
          local_10 = local_14;
        } while ((puVar4[(local_14 >> 5) + 2] >> ((byte)local_14 & 0x1f) & 1) != 0);
        goto LAB_000e9e15;
      }
    }
  }
  else if ((puVar4[2] & 1) != 0) {
    local_14 = 0;
    do {
      local_14 = local_14 + 1;
      if (uVar3 == local_14) goto LAB_000e9d55;
    } while ((puVar4[(local_14 >> 5) + 2] >> ((byte)local_14 & 0x1f) & 1) != 0);
    if (local_14 != 0xffffffff) goto LAB_000e9e15;
    goto LAB_000e9d55;
  }
  local_14 = 0;
LAB_000e9e15:
  puVar4[(local_14 >> 5) + 2] = puVar4[(local_14 >> 5) + 2] | 1 << ((byte)local_14 & 0x1f);
  return local_14;
}

/* FUN_000e9f24 @ 0xe9f24 (88 bytes) */
int FUN_000e9f24(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0x98);
  (**(code **)(*piVar1 + 0x34))(piVar1);
  iVar3 = piVar1[2];
  iVar2 = *(int *)(*(int *)(iVar3 + 0x88) + 8);
  while ((iVar2 == 0x8e &&
         (iVar3 = *(int *)(iVar3 + 8), *(int *)(*(int *)(iVar3 + 0x88) + 8) == 0x8e))) {
    iVar3 = *(int *)(iVar3 + 8);
    iVar2 = *(int *)(*(int *)(iVar3 + 0x88) + 8);
  }
  return iVar3;
}

/* FUN_000e9f7c @ 0xe9f7c (145 bytes) */
int FUN_000e9f7c(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  char cVar3;
  
  if (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 200) + 8) + 0x88) + 8) == 0x8e) {
    piVar1 = *(int **)(param_1 + 0x98);
    iVar2 = piVar1[2];
    while (iVar2 != 0) {
      if ((((*(byte *)(piVar1 + 5) & 1) != 0) && (*(int *)(piVar1[0x22] + 8) != 0x8e)) &&
         (cVar3 = (**(code **)(*piVar1 + 0x34))(piVar1), cVar3 == '\0')) {
        ((int (*)())FUN_000e956e)(param_1,piVar1,param_2);
        return;
      }
      piVar1 = (int *)piVar1[2];
      iVar2 = piVar1[2];
    }
  }
  else {
    FUN_001a7cee(param_2,*(int *)(param_1 + 200));
    *(int *)(param_2 + 0x158) = param_1;
  }
  return;
}

/* FUN_000ea00e @ 0xea00e (380 bytes) */
int FUN_000ea00e(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int local_24;
  int local_20;
  
  uVar4 = 1;
  local_20 = 0;
  iVar5 = *(int *)(param_1 + 0xd4);
  if (*(int *)(iVar5 + 4) != 0) {
    do {
      iVar2 = *(int *)(local_20 + *(int *)(iVar5 + 8));
      if (iVar2 != 0) {
        for (uVar1 = 1; uVar1 <= *(uint *)(*(int *)(iVar2 + 0xd0) + 4); uVar1 = uVar1 + 1) {
        }
      }
      uVar4 = uVar4 + 1;
      local_20 = local_20 + 4;
    } while (uVar4 <= *(uint *)(iVar5 + 4));
  }
  uVar4 = 1;
  local_24 = 0;
  iVar5 = *(int *)(param_1 + 0xd0);
  if (*(int *)(iVar5 + 4) != 0) {
    do {
      iVar2 = *(int *)(local_24 + *(int *)(iVar5 + 8));
      if (iVar2 != 0) {
        for (uVar1 = 1; uVar1 <= *(uint *)(*(int *)(iVar2 + 0xd4) + 4); uVar1 = uVar1 + 1) {
        }
      }
      uVar4 = uVar4 + 1;
      local_24 = local_24 + 4;
    } while (uVar4 <= *(uint *)(iVar5 + 4));
  }
  piVar3 = *(int **)(param_1 + 0x98);
  if (piVar3[2] != 0) {
    iVar5 = 0;
    do {
      if ((*(byte *)(piVar3 + 5) & 1) != 0) {
        iVar5 = iVar5 + 1;
        if (iVar5 == 1) {
          (**(code **)(*piVar3 + 0x34))(piVar3);
        }
        iVar2 = *(int *)(param_1 + 0xa8);
        if (((*(byte *)(*(int *)(iVar2 + 0x3f4) + 0x30) & 4) != 0) &&
           (*(int *)(piVar3[0x22] + 8) == 0x8e)) {
          (**(code **)(*(int *)piVar3[1] + 0x34))((int *)piVar3[1]);
          iVar2 = *(int *)(param_1 + 0xa8);
        }
        (**(code **)(*piVar3 + 8))(piVar3,iVar2);
      }
      piVar3 = (int *)piVar3[2];
    } while (piVar3[2] != 0);
  }
  return 1;
}

/* FUN_000ea18a @ 0xea18a (22 bytes) */
int FUN_000ea18a(param_1)
  undefined4 param_1;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_000ea00e)(param_1);
  return uVar1;
}

/* FUN_000ea1a0 @ 0xea1a0 (22 bytes) */
int FUN_000ea1a0(param_1)
  undefined4 param_1;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_000ea00e)(param_1);
  return uVar1;
}

/* FUN_000ea1b6 @ 0xea1b6 (22 bytes) */
int FUN_000ea1b6(param_1)
  undefined4 param_1;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_000ea00e)(param_1);
  return uVar1;
}

/* FUN_000ea1cc @ 0xea1cc (22 bytes) */
int FUN_000ea1cc(param_1)
  undefined4 param_1;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_000ea00e)(param_1);
  return uVar1;
}

/* FUN_000ea1e2 @ 0xea1e2 (22 bytes) */
int FUN_000ea1e2(param_1)
  undefined4 param_1;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_000ea00e)(param_1);
  return uVar1;
}

/* FUN_000ea1f8 @ 0xea1f8 (22 bytes) */
int FUN_000ea1f8(param_1)
  undefined4 param_1;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_000ea00e)(param_1);
  return uVar1;
}

/* FUN_000ea20e @ 0xea20e (22 bytes) */
int FUN_000ea20e(param_1)
  undefined4 param_1;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_000ea00e)(param_1);
  return uVar1;
}

/* FUN_000ea224 @ 0xea224 (22 bytes) */
int FUN_000ea224(param_1)
  undefined4 param_1;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_000ea00e)(param_1);
  return uVar1;
}

/* FUN_000ea23a @ 0xea23a (121 bytes) */
int FUN_000ea23a(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  
  piVar1 = *(int **)(param_1 + 0x98);
  iVar2 = piVar1[2];
  while (iVar2 != 0) {
    if (((((*(byte *)(piVar1 + 5) & 1) != 0) &&
         (cVar3 = (**(code **)(*piVar1 + 0x34))(piVar1), cVar3 == '\0')) &&
        (cVar3 = (**(code **)(*piVar1 + 0x38))(piVar1), cVar3 == '\0')) &&
       ((*(int *)(piVar1[0x22] + 8) != 0x8e &&
        (cVar3 = (**(code **)(*piVar1 + 0x78))(piVar1), cVar3 == '\0')))) {
      (**(code **)(*piVar1 + 0x3c))(piVar1);
    }
    piVar1 = (int *)piVar1[2];
    iVar2 = piVar1[2];
  }
  uVar4 = ((int (*)())FUN_000ea00e)(param_1);
  return uVar4;
}

/* FUN_000ea2b4 @ 0xea2b4 (22 bytes) */
int FUN_000ea2b4(param_1)
  undefined4 param_1;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_000ea00e)(param_1);
  return uVar1;
}

/* FUN_000ea2ca @ 0xea2ca (22 bytes) */
int FUN_000ea2ca(param_1)
  undefined4 param_1;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_000ea00e)(param_1);
  return uVar1;
}

/* FUN_000ea2e0 @ 0xea2e0 (261 bytes) */
int FUN_000ea2e0(param_1, param_2)
  int *param_1;
  undefined1 *param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  *param_2 = 0;
  iVar2 = FUN_001a7d8a(param_1[0x4c] + 0x90);
  if ((iVar2 < 3) && (iVar2 = FUN_001a7d8a(param_1[0x4b] + 0x90), iVar2 < 3)) {
    iVar2 = param_1[0x4c];
    iVar3 = ((int (*)())FUN_000e97aa)(iVar2);
    if (iVar3 == 1) {
      iVar2 = *(int *)(iVar2 + 0xd0);
      if (*(int *)(iVar2 + 4) == 0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = *(int **)(iVar2 + 8);
      }
      if (((*piVar4 == param_1[0x4d]) && (iVar2 = ((int (*)())FUN_000e97aa)(param_1[0x4b]), iVar2 == 1)) &&
         (cVar1 = (**(code **)(*param_1 + 0x40))(param_1), cVar1 == '\0')) {
        if (*(int *)(*(int *)(param_1[0x4b] + 0xd0) + 4) == 0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          puVar5 = *(undefined4 **)(*(int *)(param_1[0x4b] + 0xd0) + 8);
        }
        cVar1 = (**(code **)(*(int *)*puVar5 + 0x38))((int *)*puVar5);
        if (cVar1 == '\0') {
          if (*(int *)(*(int *)(param_1[0x4b] + 0xd0) + 4) == 0) {
            puVar5 = (undefined4 *)0x0;
          }
          else {
            puVar5 = *(undefined4 **)(*(int *)(param_1[0x4b] + 0xd0) + 8);
          }
          cVar1 = (**(code **)(*(int *)*puVar5 + 0x3c))((int *)*puVar5);
          if (cVar1 == '\0') {
            return 0;
          }
          *param_2 = 1;
        }
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_000ea3e6 @ 0xea3e6 (204 bytes) */
int FUN_000ea3e6(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  puVar2 = puVar2 + 1;
  FUN_0010e372(puVar2,*(undefined4 *)(param_1 + 0xa8));
  *(undefined4 **)(param_1 + 200) = puVar2;
  FUN_001a7d0c(param_1 + 0x90,puVar2);
  *(int *)(*(int *)(param_1 + 200) + 0x158) = param_1;
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x168);
  *puVar2 = uVar1;
  puVar2 = puVar2 + 1;
  FUN_0010e3e6(puVar2,*(undefined4 *)(param_1 + 0xa8));
  *(undefined4 **)(param_1 + 0xcc) = puVar2;
  FUN_001a7cd6(param_1 + 0x90,puVar2);
  *(int *)(*(int *)(param_1 + 0xcc) + 0x158) = param_1;
  return;
}

/* FUN_000ea4e6 @ 0xea4e6 (414 bytes) */
int FUN_000ea4e6(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar1 = (undefined4 *)FUN_001a7bca(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[4] = uVar2;
  puVar1[2] = 0;
  puVar1[1] = 2;
  uVar2 = FUN_001a7bca(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0xc4) = puVar1 + 1;
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar1 = (undefined4 *)FUN_001a7bca(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[4] = uVar2;
  puVar1[2] = 0;
  puVar1[1] = 2;
  uVar2 = FUN_001a7bca(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0xf4) = puVar1 + 1;
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar1 = (undefined4 *)FUN_001a7bca(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[4] = uVar2;
  puVar1[2] = 0;
  puVar1[1] = 2;
  uVar2 = FUN_001a7bca(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0xf0) = puVar1 + 1;
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar1 = (undefined4 *)FUN_001a7bca(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[4] = uVar2;
  puVar1[2] = 0;
  puVar1[1] = 2;
  uVar2 = FUN_001a7bca(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0xd0) = puVar1 + 1;
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar1 = (undefined4 *)FUN_001a7bca(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[4] = uVar2;
  puVar1[2] = 0;
  puVar1[1] = 2;
  uVar2 = FUN_001a7bca(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0xd4) = puVar1 + 1;
  return;
}

/* FUN_000ea6c4 @ 0xea6c4 (88 bytes) */
int FUN_000ea6c4(param_1)
  int param_1;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x138) + 0xa4) + 0x18);
  if (*piVar1 != 0) {
    if (piVar1[1] == 0) {
      *(undefined4 *)piVar1[2] = 0;
      piVar1[1] = 1;
    }
    return *(undefined4 *)(*(int *)piVar1[2] + 0x50);
  }
  piVar1 = (int *)FUN_001a7f7c(piVar1,0);
  return *(undefined4 *)(*piVar1 + 0x50);
}

/* FUN_000ea71c @ 0xea71c (88 bytes) */
int FUN_000ea71c(param_1)
  int param_1;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x138) + 0xa4) + 0x18);
  if (*piVar1 != 0) {
    if (piVar1[1] == 0) {
      *(undefined4 *)piVar1[2] = 0;
      piVar1[1] = 1;
    }
    return *(undefined4 *)(*(int *)piVar1[2] + 0x38);
  }
  piVar1 = (int *)FUN_001a7f7c(piVar1,0);
  return *(undefined4 *)(*piVar1 + 0x38);
}

/* FUN_000ea774 @ 0xea774 (88 bytes) */
int FUN_000ea774(param_1)
  int param_1;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x138) + 0xa4) + 0x18);
  if (*piVar1 != 0) {
    if (piVar1[1] == 0) {
      *(undefined4 *)piVar1[2] = 0;
      piVar1[1] = 1;
    }
    return *(undefined4 *)(*(int *)piVar1[2] + 0x20);
  }
  piVar1 = (int *)FUN_001a7f7c(piVar1,0);
  return *(undefined4 *)(*piVar1 + 0x20);
}

/* FUN_000ea7cc @ 0xea7cc (111 bytes) */
int FUN_000ea7cc(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = *(uint **)(param_1 + 0xf0);
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

/* FUN_000ea83c @ 0xea83c (111 bytes) */
int FUN_000ea83c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = *(uint **)(param_1 + 0xd4);
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

/* FUN_000ea8ac @ 0xea8ac (111 bytes) */
int FUN_000ea8ac(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = *(uint **)(param_1 + 0xd0);
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

/* FUN_000ea91c @ 0xea91c (66 bytes) */
int FUN_000ea91c(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  char cVar1;
  
  cVar1 = ((int (*)())FUN_000e9a82)(param_1,param_2);
  if (cVar1 != '\0') {
    return;
  }
  ((int (*)())FUN_000ea8ac)(param_1,param_2);
  ((int (*)())FUN_000ea83c)();
  return;
}

/* FUN_000ea95e @ 0xea95e (574 bytes) */
int FUN_000ea95e(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint local_2c;
  uint local_28;
  int local_24;
  int local_20;
  
  local_20 = 0;
  iVar4 = *(int *)(param_1 + 0xd4);
  for (uVar8 = 1; uVar8 <= *(uint *)(iVar4 + 4); uVar8 = uVar8 + 1) {
    iVar2 = *(int *)(local_20 + *(int *)(iVar4 + 8));
    if (iVar2 != 0) {
      ((int (*)())FUN_000ea83c)(param_3,iVar2);
      local_2c = 0xffffffff;
      uVar7 = 1;
      iVar6 = 0;
      iVar4 = *(int *)(iVar2 + 0xd0);
      if (*(int *)(iVar4 + 4) != 0) {
        do {
          iVar4 = *(int *)(iVar6 + *(int *)(iVar4 + 8));
          uVar1 = local_2c;
          if ((iVar4 != 0) && (uVar1 = local_2c + 1, param_1 == iVar4)) {
            puVar3 = *(uint **)(iVar2 + 0xd0);
            if (uVar1 < *puVar3) {
              uVar7 = puVar3[1];
              if (uVar7 <= uVar1) {
                _memset((void *)(puVar3[2] + uVar7 * 4),0,(uVar1 - uVar7) * 4 + 4);
                puVar3[1] = local_2c + 2;
              }
              puVar5 = (undefined4 *)(puVar3[2] + uVar1 * 4);
            }
            else {
              puVar5 = (undefined4 *)FUN_001a7f7c(puVar3,uVar1);
            }
            *puVar5 = param_3;
            iVar4 = *(int *)(param_1 + 0xd4);
            goto LAB_000eaa29;
          }
          local_2c = uVar1;
          uVar7 = uVar7 + 1;
          iVar6 = iVar6 + 4;
          iVar4 = *(int *)(iVar2 + 0xd0);
        } while (uVar7 <= *(uint *)(iVar4 + 4));
      }
      iVar4 = *(int *)(param_1 + 0xd4);
    }
LAB_000eaa29:
    local_20 = local_20 + 4;
  }
  uVar8 = 1;
  local_24 = 0;
  iVar4 = *(int *)(param_2 + 0xd0);
  do {
    if (*(uint *)(iVar4 + 4) < uVar8) {
      return;
    }
    iVar2 = *(int *)(local_24 + *(int *)(iVar4 + 8));
    if (iVar2 != 0) {
      ((int (*)())FUN_000ea8ac)(param_3,iVar2);
      local_28 = 0xffffffff;
      uVar7 = 1;
      iVar6 = 0;
      iVar4 = *(int *)(iVar2 + 0xd4);
      if (*(int *)(iVar4 + 4) != 0) {
        do {
          iVar4 = *(int *)(*(int *)(iVar4 + 8) + iVar6);
          uVar1 = local_28;
          if ((iVar4 != 0) && (uVar1 = local_28 + 1, param_2 == iVar4)) {
            puVar3 = *(uint **)(iVar2 + 0xd4);
            if (uVar1 < *puVar3) {
              uVar7 = puVar3[1];
              if (uVar7 <= uVar1) {
                _memset((void *)(puVar3[2] + uVar7 * 4),0,(uVar1 - uVar7) * 4 + 4);
                puVar3[1] = local_28 + 2;
              }
              puVar5 = (undefined4 *)(puVar3[2] + uVar1 * 4);
            }
            else {
              puVar5 = (undefined4 *)FUN_001a7f7c(puVar3,uVar1);
            }
            *puVar5 = param_3;
            iVar4 = *(int *)(param_2 + 0xd0);
            goto LAB_000eaaa7;
          }
          local_28 = uVar1;
          uVar7 = uVar7 + 1;
          iVar6 = iVar6 + 4;
          iVar4 = *(int *)(iVar2 + 0xd4);
        } while (uVar7 <= *(uint *)(iVar4 + 4));
      }
      iVar4 = *(int *)(param_2 + 0xd0);
    }
LAB_000eaaa7:
    uVar8 = uVar8 + 1;
    local_24 = local_24 + 4;
  } while( true );
}

/* FUN_000eab9c @ 0xeab9c (111 bytes) */
int FUN_000eab9c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = *(uint **)(param_1 + 0xf4);
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

/* FUN_000eac0c @ 0xeac0c (112 bytes) */
int FUN_000eac0c(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = *(uint **)(param_1 + 0xd4);
  if (param_2 < *puVar1) {
    uVar2 = puVar1[1];
    if (uVar2 <= param_2) {
      _memset((void *)(puVar1[2] + uVar2 * 4),0,(param_2 - uVar2) * 4 + 4);
      puVar1[1] = param_2 + 1;
    }
    return *(undefined4 *)(puVar1[2] + param_2 * 4);
  }
  puVar3 = (undefined4 *)FUN_001a7f7c(puVar1,param_2);
  return *puVar3;
}

/* FUN_000eac7c @ 0xeac7c (112 bytes) */
int FUN_000eac7c(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = *(uint **)(param_1 + 0xd0);
  if (param_2 < *puVar1) {
    uVar2 = puVar1[1];
    if (uVar2 <= param_2) {
      _memset((void *)(puVar1[2] + uVar2 * 4),0,(param_2 - uVar2) * 4 + 4);
      puVar1[1] = param_2 + 1;
    }
    return *(undefined4 *)(puVar1[2] + param_2 * 4);
  }
  puVar3 = (undefined4 *)FUN_001a7f7c(puVar1,param_2);
  return *puVar3;
}

