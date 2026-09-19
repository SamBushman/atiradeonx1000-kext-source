#include "decls.h"

/* FUN_00137d0a @ 0x137d0a (97 bytes) */
int FUN_00137d0a(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 local_10;
  
  iVar3 = *(int *)(param_1 + 0x430 + param_2 * 4);
  iVar1 = *(int *)(param_1 + 0x43c + param_2 * 4);
  if (iVar1 <= iVar3) {
    return 0;
  }
  local_10 = 0;
  do {
    cVar2 = FUN_00137bae(param_1,iVar3);
    local_10 = local_10 + (uint)(cVar2 == '\0');
    iVar3 = iVar3 + 1;
  } while (iVar3 != iVar1);
  return local_10;
}

/* FUN_00137d6c @ 0x137d6c (140 bytes) */
int FUN_00137d6c(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  
  iVar2 = ((int (*)())FUN_00137d0a)(param_1,param_2);
  if (param_2 == 1) {
    iVar2 = iVar2 + 0x20;
  }
  cVar1 = FUN_00137bae(param_1,iVar2);
  if (cVar1 == '\0') {
    FUN_000e27ca(*(undefined4 *)(param_1 + 8),4);
  }
  FUN_00137b7e(param_1,iVar2);
  *(int *)(*(int *)(param_1 + 0x44c) + *(int *)(param_1 + 0x464) * 4) = iVar2;
  *(int *)(*(int *)(param_1 + 0x450) + *(int *)(param_1 + 0x464) * 4) = param_2;
  *(int *)(param_1 + 0x464) = *(int *)(param_1 + 0x464) + 1;
  return;
}

/* FUN_00137df8 @ 0x137df8 (87 bytes) */
int FUN_00137df8(param_1)
  int *param_1;
{
  byte bVar1;
  char cVar2;
  int *piVar3;
  
  cVar2 = (**(code **)(*param_1 + 0x34))(param_1);
  if (cVar2 == '\0') {
    cVar2 = (**(code **)(*param_1 + 0x28))(param_1);
    if (cVar2 == '\0') {
      do {
        piVar3 = param_1;
        param_1 = (int *)piVar3[1];
      } while ((*(byte *)(param_1 + 5) & 4) != 0);
      return piVar3;
    }
    bVar1 = *(byte *)((int)param_1 + 0x15);
    while (((bVar1 & 0x10) == 0 &&
           (param_1 = (int *)param_1[1], (*(byte *)((int)param_1 + 0x15) & 0x10) == 0))) {
      param_1 = (int *)param_1[1];
      bVar1 = *(byte *)((int)param_1 + 0x15);
    }
  }
  return param_1;
}

/* FUN_00137e50 @ 0x137e50 (29 bytes) */
int FUN_00137e50(param_1)
  undefined4 param_1;
{
  ((int (*)())FUN_00137df8)(param_1);
  ((int (*)())FUN_00137df8)();
  return;
}

/* FUN_00137e6e @ 0x137e6e (104 bytes) */
int FUN_00137e6e(param_1)
  int *param_1;
{
  int *piVar1;
  int *piVar2;
  char cVar3;
  byte bVar4;
  
  cVar3 = (**(code **)(*param_1 + 0x38))(param_1);
  if (cVar3 == '\0') {
    cVar3 = (**(code **)(*param_1 + 0x28))(param_1);
    if (cVar3 == '\0') {
      if ((*(byte *)(param_1 + 5) & 4) != 0) {
        do {
          param_1 = (int *)param_1[2];
        } while ((*(byte *)(param_1 + 5) & 4) != 0);
        return param_1;
      }
    }
    else {
      cVar3 = (**(code **)(*param_1 + 0x74))(param_1);
      if (cVar3 == '\0') {
        bVar4 = (**(code **)(*param_1 + 0x78))(param_1);
        piVar1 = param_1;
        while (piVar2 = piVar1, bVar4 == 0) {
          piVar1 = (int *)piVar2[2];
          bVar4 = *(byte *)((int)piVar1 + 0x15) & 0x10;
          param_1 = piVar2;
        }
      }
    }
  }
  return param_1;
}

/* FUN_00137ed6 @ 0x137ed6 (9 bytes) */
int FUN_00137ed6()
{
  ((int (*)())FUN_00137e6e)();
  return;
}

/* FUN_00137ee0 @ 0x137ee0 (22 bytes) */
int FUN_00137ee0(param_1)
  undefined4 param_1;
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_00137e6e)(param_1);
  return *(undefined4 *)(iVar1 + 8);
}

/* FUN_00137ef6 @ 0x137ef6 (45 bytes) */
int FUN_00137ef6(param_1)
  undefined4 param_1;
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_00137e50)(param_1);
  if ((*(byte *)(iVar1 + 0x17) & 4) != 0) {
    ((int (*)())FUN_00137e50)(param_1);
  }
  ((int (*)())FUN_00137e6e)();
  return;
}

/* FUN_00137f24 @ 0x137f24 (21 bytes) */
int FUN_00137f24(param_1)
  int param_1;
{
  return *(uint *)(param_1 + 0x98) < 2;
}

/* FUN_00137f3a @ 0x137f3a (34 bytes) */
int FUN_00137f3a(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = param_2 * 4 + param_3;
  return *(uint *)(param_1 + 8 + (uVar1 >> 5) * 4) >> ((byte)uVar1 & 0x1f) & 1;
}

/* FUN_00137f5c @ 0x137f5c (59 bytes) */
int FUN_00137f5c(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 * 4;
  uVar1 = uVar2 + 4;
  do {
    if ((*(uint *)(param_1 + 8 + (uVar2 >> 5) * 4) >> ((byte)uVar2 & 0x1f) & 1) != 0) {
      return 1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar1 != uVar2);
  return 0;
}

/* FUN_00137f98 @ 0x137f98 (31 bytes) */
int FUN_00137f98(param_1, param_2)
  int param_1;
  uint param_2;
{
  return *(uint *)(*(int *)(param_1 + 0x24) + 8 + (param_2 >> 5) * 4) >> ((byte)param_2 & 0x1f) & 1;
}

/* FUN_00137fb8 @ 0x137fb8 (34 bytes) */
int FUN_00137fb8(param_1, param_2)
  int param_1;
  uint param_2;
{
  return *(uint *)(*(int *)(param_1 + 0x424) + 8 + (param_2 >> 5) * 4) >> ((byte)param_2 & 0x1f) & 1
  ;
}

/* FUN_00137fda @ 0x137fda (67 bytes) */
int FUN_00137fda(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = ((int (*)())FUN_00137df8)(param_1);
  piVar3 = *(int **)(iVar2 + 4);
  while( true ) {
    cVar1 = (**(code **)(*piVar3 + 0x74))(piVar3);
    if (cVar1 == '\0') {
      return (int *)0x0;
    }
    if (*(int *)(piVar3[0x30] + 0x13c) == param_2) break;
    piVar3 = (int *)piVar3[1];
  }
  return piVar3;
}

/* FUN_0013801e @ 0x13801e (65 bytes) */
int FUN_0013801e(param_1, param_2)
  uint param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = param_1;
  while( true ) {
    if (uVar1 == 0) {
      return 0;
    }
    if (((*(uint *)(param_1 + 0x14) & 1) != 0) &&
       (*(int *)(param_1 + 0x14c) == *(int *)(param_2 + 0x14c))) break;
    uVar1 = *(uint *)(param_1 + 0x14) & 4;
    param_1 = *(uint *)(param_1 + 8);
    if (param_1 == 0) {
      return 0;
    }
  }
  return param_1;
}

/* FUN_00138060 @ 0x138060 (230 bytes) */
int FUN_00138060(param_1)
  undefined4 param_1;
{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar7;
  int iVar8;
  int local_10;
  uint uVar6;
  
  piVar3 = (int *)((int (*)())FUN_00137e50)(param_1);
  piVar4 = (int *)((int (*)())FUN_00137df8)(param_1);
  cVar2 = (**(code **)(*piVar3 + 0x24))(piVar3);
  if (((cVar2 != '\0') && ((*(byte *)((int)piVar3 + 0x17) & 4) == 0)) &&
     (piVar1 = piVar4, piVar5 = piVar4, (*(byte *)((int)piVar4 + 0x15) & 0x10) == 0)) {
    do {
      if (piVar5 == (int *)0x0) {
        return;
      }
      uVar6 = piVar1[5];
      if ((uVar6 & 1) != 0) {
        piVar5 = piVar1 + 0x29;
        for (local_10 = 1; iVar8 = (**(code **)(*piVar1 + 0x14))(piVar1), local_10 <= iVar8;
            local_10 = local_10 + 1) {
          uVar7 = FUN_0010b180(piVar1,local_10);
          iVar8 = ((int (*)())FUN_0013801e)(piVar3,uVar7);
          if (iVar8 != 0) {
            piVar4[5] = piVar4[5] | 0x10000000;
            FUN_00109c0e(piVar5,4,1);
          }
          piVar5 = piVar5 + 6;
        }
        uVar6 = piVar1[5];
      }
      piVar5 = (int *)(uVar6 & 4);
      piVar1 = (int *)piVar1[2];
    } while (piVar1 != (int *)0x0);
  }
  return;
}

/* FUN_00138146 @ 0x138146 (38 bytes) */
int FUN_00138146(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint *puVar1;
  byte bVar2;
  
  bVar2 = (byte)param_2 & 0x1f;
  puVar1 = (uint *)(*(int *)(param_1 + 0x424) + 8 + (param_2 >> 5) * 4);
  *puVar1 = *puVar1 & (-2 << bVar2 | 0xfffffffeU >> 0x20 - bVar2);
  return;
}

/* FUN_0013816c @ 0x13816c (108 bytes) */
int FUN_0013816c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 0x14);
  if (*(int *)(param_2 + 0x98) != 0) {
    return (uint)(*(int *)(param_2 + 0x98) == 1) * 2 + -1;
  }
  if ((*(byte *)(param_2 + 0x14) & 0x40) != 0) {
    if (0 < iVar1) {
      iVar2 = 0;
      do {
        if ((*(int *)(param_1 + 0x430) <= *(int *)(param_2 + 0x94)) &&
           (*(int *)(param_2 + 0x94) < *(int *)(param_1 + 0x43c))) {
          return iVar2;
        }
        iVar2 = iVar2 + 1;
        param_1 = param_1 + 4;
      } while (iVar1 != iVar2);
    }
    return -1;
  }
  return 0;
}

/* FUN_001381d8 @ 0x1381d8 (258 bytes) */
int FUN_001381d8(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int *param_4;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = ((int (*)())FUN_00137df8)(param_2);
  iVar1 = *(int *)(*(int *)(param_1 + 0x2c) + 0x3f4);
  iVar6 = FUN_0010a17a(0x31,*(int *)(param_1 + 0x2c));
  uVar2 = *(undefined4 *)(param_3 + 0x98);
  *(int *)(iVar6 + 0x94) = *param_4;
  *(undefined4 *)(iVar6 + 0x98) = uVar2;
  FUN_0010ba02(iVar6,1,param_3,0,*(undefined4 *)(param_1 + 0x2c));
  *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) & 0xffffffbf | 0x80000000;
  piVar3 = *(int **)(*(int *)(param_1 + 0x2c) + 0x54);
  cVar4 = (**(code **)(*piVar3 + 0x150))(piVar3,*(undefined4 *)(iVar5 + 4));
  if (cVar4 != '\0') {
    *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) | 0x1000;
  }
  FUN_000e956e(*(undefined4 *)(iVar5 + 0x158),iVar5,iVar6);
  *(undefined4 *)(*(int *)(iVar1 + 0x450) + *param_4 * 4) = 0;
  *(undefined4 *)(*(int *)(iVar1 + 0x44c) + *param_4 * 4) = 0xffffffff;
  **(int **)(param_1 + 0x18) = **(int **)(param_1 + 0x18) + 1;
  *param_4 = *param_4 + 1;
  return iVar6;
}

/* FUN_001382da @ 0x1382da (179 bytes) */
int FUN_001382da(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_0010b180(param_2,param_3);
  iVar2 = FUN_0010a1c2(uVar1,param_5,0);
  if ((*(byte *)(param_2 + 0x14) & 0x40) == 0) {
    uVar1 = FUN_00137b60(param_1);
    *(undefined4 *)(iVar2 + 0x94) = uVar1;
    *(undefined4 *)(iVar2 + 0x98) = 0;
  }
  FUN_000e9596(*(undefined4 *)(param_4 + 0x158),param_4,iVar2);
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x8000000;
  FUN_0010ba02(param_2,param_3,iVar2,0,param_5);
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) & 0xffffeffb | 0x8000000;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) | 1;
  return iVar2;
}

/* FUN_0013838e @ 0x13838e (56 bytes) */
int FUN_0013838e(param_1)
  int *param_1;
{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x28))(param_1);
  if ((cVar1 == '\0') && (*(int *)(param_1[0x22] + 8) != 0x93)) {
    return 0;
  }
  return 1;
}

/* FUN_001383c6 @ 0x1383c6 (131 bytes) */
int FUN_001383c6(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = *(undefined4 *)(param_3 + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar2,0x168);
  *puVar3 = uVar2;
  puVar1 = puVar3 + 1;
  FUN_0010ef86(puVar1,0xfa,param_3);
  puVar3[0x26] = param_1;
  puVar3[0x27] = 0x3b;
  puVar3[0x4d] = param_1;
  puVar3[0x4e] = param_2;
  FUN_000e9512(*(undefined4 *)(*(int *)(param_3 + 0x3f4) + 0x394),puVar1);
  return puVar1;
}

/* FUN_00138468 @ 0x138468 (131 bytes) */
int FUN_00138468(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = *(undefined4 *)(param_3 + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar2,0x168);
  *puVar3 = uVar2;
  puVar1 = puVar3 + 1;
  FUN_0010ef86(puVar1,0x79,param_3);
  puVar3[0x26] = param_2;
  puVar3[0x27] = 0x3c;
  puVar3[0x4d] = param_1;
  puVar3[0x50] = param_2;
  FUN_000e9540(*(undefined4 *)(*(int *)(param_3 + 0x3f4) + 0x394),puVar1);
  return puVar1;
}

/* FUN_0013850a @ 0x13850a (329 bytes) */
int FUN_0013850a(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  undefined4 param_3;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int local_24;
  undefined1 local_14 [4];
  undefined4 local_10;
  
  iVar2 = FUN_0010b0f4(param_2,param_3);
  local_10 = FUN_000f5bdc(*(undefined4 *)(iVar2 + 0x10));
  uVar3 = FUN_0010b180(param_2,param_3);
  local_24 = 0;
  do {
    if ((*(char *)((int)&local_10 + local_24) != '\0') &&
       (uVar4 = FUN_0013fbf0(uVar3,local_24,local_14), -1 < param_1)) {
      iVar2 = 0;
      piVar5 = param_2;
      do {
        do {
          do {
            piVar5 = (int *)((int (*)())FUN_00137e50)(piVar5);
          } while ((*(byte *)((int)piVar5 + 0x17) & 4) != 0);
          cVar1 = (**(code **)(*piVar5 + 0x34))(piVar5);
        } while ((((cVar1 != '\0') || (cVar1 = (**(code **)(*piVar5 + 0x68))(piVar5), cVar1 != '\0')
                  ) || (*(int *)(piVar5[0x22] + 8) == 0x8e)) ||
                ((cVar1 = (**(code **)(*piVar5 + 0x74))(piVar5), cVar1 != '\0' ||
                 (cVar1 = (**(code **)(*piVar5 + 0x78))(piVar5), cVar1 != '\0'))));
        iVar2 = iVar2 + 1;
        cVar1 = (**(code **)(*(int *)param_2[0x56] + 0x24))((int *)param_2[0x56]);
        if ((cVar1 == '\0') &&
           ((cVar1 = (**(code **)(*(int *)param_2[0x56] + 0x2c))((int *)param_2[0x56]),
            cVar1 == '\0' && (piVar5[0x56] != param_2[0x56])))) {
          return 1;
        }
        iVar6 = ((int (*)())FUN_0013801e)(piVar5,uVar4);
        if (iVar6 != 0) {
          return 0;
        }
      } while (iVar2 <= param_1);
    }
    local_24 = local_24 + 1;
    if (local_24 == 4) {
      return 1;
    }
  } while( true );
}

/* FUN_00138654 @ 0x138654 (266 bytes) */
int FUN_00138654(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  uVar2 = *(undefined4 *)(param_6 + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar2,0x168);
  *puVar3 = uVar2;
  puVar1 = puVar3 + 1;
  FUN_0010d240(puVar1,0xfb,param_6);
  puVar3[0x26] = param_1;
  puVar3[0x27] = 0;
  puVar3[0x28] = DAT_001cc52c;
  FUN_0010ba02(puVar1,1,param_3,0,param_6);
  iVar4 = FUN_0010b0f4(puVar1,1);
  *(undefined4 *)(iVar4 + 0x10) = DAT_001cc528;
  FUN_0010ba02(puVar1,2,param_4,0,param_6);
  iVar4 = FUN_0010b0f4(puVar1,2);
  *(undefined4 *)(iVar4 + 0x10) = DAT_001cc524;
  FUN_000e9596(*(undefined4 *)(param_5 + 0x158),param_5,puVar1);
  puVar3[6] = puVar3[6] | 0x8001000;
  return puVar1;
}

/* FUN_0013877c @ 0x13877c (508 bytes) */
int FUN_0013877c(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 local_20 [4];
  
  iVar3 = FUN_0010b0f4(param_1,0);
  local_20[0] = *(undefined4 *)(iVar3 + 0x10);
  if (((*(byte *)(param_1 + 0x15) & 2) != 0) &&
     (iVar3 = FUN_0010b180(param_1,*(undefined4 *)(param_1 + 0x84)), iVar3 != 0)) {
    iVar7 = FUN_0010b0f4(param_1,0);
    cVar2 = *(char *)(iVar7 + 0x10);
    iVar7 = 0;
    while( true ) {
      if ((cVar2 == '\x01') && (cVar2 = FUN_0013fb98(iVar3,iVar7), cVar2 != '\0')) {
        *(undefined1 *)((int)local_20 + iVar7) = 0;
      }
      if (iVar7 + 1 == 4) break;
      iVar8 = FUN_0010b0f4(param_1,0);
      cVar2 = *(char *)(iVar7 + 0x11 + iVar8);
      iVar7 = iVar7 + 1;
    }
  }
  uVar4 = FUN_000f5e66(local_20[0]);
  uVar6 = *(undefined4 *)(param_5 + 0xb8);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar6,0x168);
  *puVar5 = uVar6;
  puVar1 = puVar5 + 1;
  FUN_0010cb26(puVar1,0xfc,param_5);
  puVar5[0x26] = *(undefined4 *)(param_2 + 0x94);
  puVar5[0x27] = 0x3b;
  uVar6 = FUN_000f5e2c(uVar4);
  puVar5[0x28] = uVar6;
  FUN_0010ba02(puVar1,1,param_1,0,param_5);
  iVar3 = FUN_0010b0f4(puVar1,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar4;
  FUN_0010ba02(puVar1,2,param_3,0,param_5);
  iVar3 = FUN_0010b0f4(puVar1,2);
  *(undefined4 *)(iVar3 + 0x10) = DAT_001cc524;
  FUN_0010ba02(puVar1,3,param_2,0,param_5);
  puVar5[6] = puVar5[6] | 0x1000;
  FUN_000e9596();
  return;
}

/* FUN_00138996 @ 0x138996 (286 bytes) */
int FUN_00138996(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  *(int *)(param_1 + 0x45c) = *(int *)(*(int *)(param_1 + 8) + 0x108) + 1;
  iVar2 = FUN_00137bd0(param_1);
  *(int *)(param_1 + 0x460) = iVar2;
  *(int *)(param_1 + 0x458) = iVar2 + *(int *)(param_1 + 0x45c);
  iVar2 = *(int *)(param_1 + 8);
  piVar1 = *(int **)(iVar2 + 0x54);
  iVar3 = (**(code **)(*piVar1 + 0x138))(piVar1,iVar2);
  iVar4 = (**(code **)(*piVar1 + 0x140))(piVar1,iVar2);
  iVar2 = (**(code **)(*piVar1 + 0x13c))(piVar1,iVar2);
  iVar2 = iVar3 + iVar4 + iVar2;
  if (iVar2 < *(int *)(param_1 + 0x458)) {
    iVar2 = *(int *)(param_1 + 0x458);
  }
  if (iVar2 < 0x1000) {
    iVar2 = 0x1000;
  }
  iVar3 = iVar2 * 4;
  uVar5 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),iVar3);
  *(undefined4 *)(param_1 + 0x44c) = uVar5;
  uVar5 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),iVar3);
  *(undefined4 *)(param_1 + 0x450) = uVar5;
  uVar5 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),iVar3);
  *(undefined4 *)(param_1 + 0x454) = uVar5;
  if (0 < iVar2) {
    iVar3 = 0;
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x454) + iVar3 * 4) = 0xffffffff;
      iVar3 = iVar3 + 1;
    } while (iVar2 != iVar3);
  }
  return;
}

/* FUN_00138ab4 @ 0x138ab4 (664 bytes) */
int FUN_00138ab4(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  int *param_4;
  undefined4 param_5;
  int param_6;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  int local_1c;
  int local_10;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x2c) + 0x3f4);
  iVar3 = FUN_0010a17a(0x31,*(int *)(param_1 + 0x2c));
  iVar2 = *param_4;
  uVar7 = *(undefined4 *)(param_2 + 0x98);
  *(int *)(iVar3 + 0x94) = iVar2;
  *(undefined4 *)(iVar3 + 0x98) = uVar7;
  FUN_0010ba02(iVar3,1,param_3,0,*(undefined4 *)(param_1 + 0x2c));
  *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xffffffbf | 0x80000000;
  FUN_000e956e(param_6,param_5,iVar3);
  FUN_0010c18e(param_2,iVar3,0,*(undefined4 *)(param_1 + 0x2c));
  FUN_0013eea6(param_1);
  *(undefined4 *)(*(int *)(iVar1 + 0x450) + *param_4 * 4) = 0;
  **(int **)(param_1 + 0x18) = **(int **)(param_1 + 0x18) + 1;
  *param_4 = *param_4 + 1;
  *(int *)(iVar1 + 600) = *(int *)(iVar1 + 600) + 1;
  iVar3 = *param_4;
  local_1c = *(int *)(iVar1 + 0x378);
  if (*(int *)(local_1c + 8) != 0) {
    uVar4 = iVar3 * 4 + 0x1fU >> 5;
    do {
      while( true ) {
        puVar8 = *(uint **)(local_1c + 0x100);
        uVar6 = puVar8[1];
        if (uVar6 + 0x20 >> 5 == *puVar8) break;
        uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc);
        puVar5 = (undefined4 *)FUN_001a7bca(uVar7,uVar4 * 4 + 0xc);
        puVar10 = puVar5 + 1;
        *puVar5 = uVar7;
        puVar5[2] = iVar3 * 4;
        puVar5[1] = uVar4;
        if (uVar4 != 0) {
          uVar6 = 0;
          puVar9 = puVar10;
          do {
            puVar9[2] = 0;
            uVar6 = uVar6 + 1;
            puVar9 = puVar9 + 1;
          } while (uVar6 < *puVar10);
        }
        *(uint **)(local_1c + 0x100) = puVar10;
        if (*puVar10 != 0) {
          uVar11 = 0;
          uVar6 = *puVar10;
          do {
            puVar10[2] = puVar10[2] | puVar8[2];
            uVar11 = uVar11 + 1;
            puVar10 = puVar10 + 1;
            puVar8 = puVar8 + 1;
          } while (uVar11 < uVar6);
        }
LAB_00138c56:
        local_1c = *(int *)(local_1c + 8);
        if (*(int *)(local_1c + 8) == 0) goto LAB_00138c6a;
      }
      puVar8[1] = uVar6 + 1;
      if (uVar6 + 1 <= uVar6) goto LAB_00138c56;
      do {
        puVar8[(uVar6 >> 5) + 2] = puVar8[(uVar6 >> 5) + 2] & ~(1 << ((byte)uVar6 & 0x1f));
        uVar6 = uVar6 + 1;
      } while (uVar6 < puVar8[1]);
      local_1c = *(int *)(local_1c + 8);
    } while (*(int *)(local_1c + 8) != 0);
  }
LAB_00138c6a:
  if (0 < *param_4) {
    local_10 = 0;
    uVar4 = 4;
LAB_00138c7f:
    do {
      uVar6 = local_10 << 2;
      do {
        if ((*(uint *)(*(int *)(param_6 + 0x100) + 8 + (uVar6 >> 5) * 4) >> ((byte)uVar6 & 0x1f) & 1
            ) != 0) {
          uVar7 = ((int (*)())FUN_0013c266)(param_1,local_10,1);
          FUN_0013c894(param_1,iVar2,uVar7);
          local_10 = local_10 + 1;
          uVar4 = uVar4 + 4;
          if (*param_4 <= local_10) {
            return;
          }
          goto LAB_00138c7f;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 != uVar4);
      local_10 = local_10 + 1;
      uVar4 = uVar4 + 4;
    } while (local_10 < *param_4);
  }
  return;
}

/* FUN_00138d4c @ 0x138d4c (321 bytes) */
int FUN_00138d4c(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar1 = *(uint **)(param_1 + 4);
  if (param_2 < *puVar1) {
    uVar2 = puVar1[1];
    if (uVar2 <= param_2) {
      _memset((void *)(puVar1[2] + uVar2 * 4),0,(param_2 - uVar2) * 4 + 4);
      puVar1[1] = param_2 + 1;
    }
    iVar3 = ((int (*)())FUN_0013c136)(*(undefined4 *)(puVar1[2] + param_2 * 4));
  }
  else {
    puVar5 = (undefined4 *)FUN_001a7f7c(puVar1,param_2);
    iVar3 = ((int (*)())FUN_0013c136)(*puVar5);
  }
  if (iVar3 != 0) {
    return iVar3;
  }
  iVar3 = *(int *)(param_3 + 0x138);
  iVar4 = ((int (*)())FUN_00138468)(*(undefined4 *)(param_3 + 0x130),iVar3,*(undefined4 *)(param_1 + 0x2c));
  puVar1 = *(uint **)(param_1 + 4);
  if (param_2 < *puVar1) {
    uVar2 = puVar1[1];
    if (uVar2 <= param_2) {
      _memset((void *)(puVar1[2] + uVar2 * 4),0,(param_2 - uVar2) * 4 + 4);
      puVar1[1] = param_2 + 1;
    }
    puVar5 = (undefined4 *)(puVar1[2] + param_2 * 4);
  }
  else {
    puVar5 = (undefined4 *)FUN_001a7f7c(puVar1,param_2);
  }
  ((int (*)())FUN_0013c128)(*puVar5,iVar4);
  *(int *)(param_3 + 0x138) = iVar3 + 1;
  return iVar4;
}

/* FUN_00138e8e @ 0x138e8e (163 bytes) */
int FUN_00138e8e(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  uint *puVar2;
  int *piVar3;
  int local_18;
  uint local_14;
  
  if ((int)param_2 < 1) {
    local_18 = 0;
  }
  else {
    local_14 = 0;
    local_18 = 0;
    do {
      puVar2 = *(uint **)(param_1 + 0x8c);
      if (param_2 < *puVar2) {
        uVar1 = puVar2[1];
        if (uVar1 <= param_2) {
          _memset((void *)(puVar2[2] + uVar1 * 4),0,(param_2 - uVar1) * 4 + 4);
          puVar2[1] = param_2 + 1;
        }
        piVar3 = (int *)(param_2 * 4 + puVar2[2]);
      }
      else {
        piVar3 = (int *)FUN_001a7f7c(puVar2,param_2);
      }
      local_18 = local_18 + *piVar3;
      local_14 = local_14 + 1;
    } while (param_2 != local_14);
  }
  return local_18;
}

/* FUN_00138f32 @ 0x138f32 (331 bytes) */
int FUN_00138f32(param_1)
  int param_1;
{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint local_14;
  
  iVar2 = *(int *)(param_1 + 0x428);
  if (*(uint *)(iVar2 + 4) == 0) {
LAB_00138f5a:
    local_14 = 0xffffffff;
  }
  else if ((*(byte *)(iVar2 + 8) & 1) == 0) {
    local_14 = 0;
  }
  else {
    local_14 = 0;
    do {
      local_14 = local_14 + 1;
      if (*(uint *)(iVar2 + 4) == local_14) goto LAB_00138f5a;
    } while ((*(uint *)(iVar2 + 8 + (local_14 >> 5) * 4) >> ((byte)local_14 & 0x1f) & 1) != 0);
  }
  puVar1 = (uint *)(iVar2 + 8 + (local_14 >> 5) * 4);
  *puVar1 = *puVar1 | 1 << ((byte)local_14 & 0x1f);
  if (*(int *)(param_1 + 0x8c) == 0) {
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
    puVar4 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
    *puVar4 = uVar5;
    puVar4[4] = uVar5;
    puVar4[2] = 0;
    puVar4[1] = 2;
    uVar5 = FUN_001a7bca(uVar5,8);
    puVar4[3] = uVar5;
    *(undefined4 **)(param_1 + 0x8c) = puVar4 + 1;
  }
  puVar1 = *(uint **)(param_1 + 0x8c);
  if (*puVar1 <= local_14) {
    puVar4 = (undefined4 *)FUN_001a7f7c(puVar1,local_14);
    *puVar4 = 0;
    return local_14;
  }
  uVar3 = puVar1[1];
  if (uVar3 <= local_14) {
    _memset((void *)(puVar1[2] + uVar3 * 4),0,(local_14 - uVar3) * 4 + 4);
    puVar1[1] = local_14 + 1;
  }
  *(undefined4 *)(puVar1[2] + local_14 * 4) = 0;
  return local_14;
}

/* FUN_0013909a @ 0x13909a (94 bytes) */
int FUN_0013909a(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x42c) != 0) {
    return *(undefined4 *)(param_1 + 0x42c);
  }
  uVar1 = ((int (*)())FUN_00138f32)(param_1);
  uVar2 = ((int (*)())FUN_00138e8e)(param_1,uVar1);
  uVar1 = ((int (*)())FUN_001383c6)(uVar1,uVar2,*(undefined4 *)(param_1 + 8));
  *(undefined4 *)(param_1 + 0x42c) = uVar1;
  return *(undefined4 *)(param_1 + 0x42c);
}

/* FUN_001390f8 @ 0x1390f8 (133 bytes) */
int FUN_001390f8(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)(param_2 + 300) = param_3;
  uVar1 = *(uint *)(param_2 + 0x130);
  puVar2 = *(uint **)(param_1 + 0x8c);
  if (uVar1 < *puVar2) {
    uVar3 = puVar2[1];
    if (uVar3 <= uVar1) {
      _memset((void *)(puVar2[2] + uVar3 * 4),0,(uVar1 - uVar3) * 4 + 4);
      puVar2[1] = uVar1 + 1;
    }
    *(undefined4 *)(puVar2[2] + uVar1 * 4) = param_3;
    return;
  }
  puVar4 = (undefined4 *)FUN_001a7f7c(puVar2,uVar1);
  *puVar4 = param_3;
  return;
}

/* FUN_0013917e @ 0x13917e (1624 bytes) */
int FUN_0013917e(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  uint *puVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int *piVar16;
  int *piVar17;
  byte local_90;
  int local_38;
  int local_30;
  int local_2c;
  int local_28;
  
  iVar15 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 0x14) << 2;
  iVar4 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xbc),iVar15);
  iVar5 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xbc),iVar15);
  uVar6 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xbc),
                       *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 0x14) << 2);
  piVar16 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  (**(code **)(*piVar16 + 0x134))(piVar16,uVar6,*(int *)(param_1 + 8));
  iVar15 = *(int *)(param_1 + 8);
  if (0 < *(int *)(*(int *)(iVar15 + 0x54) + 0x14)) {
    local_28 = 1;
    do {
      uVar6 = *(undefined4 *)(iVar15 + 0xbc);
      puVar10 = (undefined4 *)FUN_001a7bca(uVar6,0x20c);
      *puVar10 = uVar6;
      puVar10[2] = 0x1000;
      puVar10[1] = 0x80;
      uVar14 = 0;
      puVar8 = puVar10 + 1;
      do {
        puVar8[2] = 0;
        uVar14 = uVar14 + 1;
        puVar8 = puVar8 + 1;
      } while (uVar14 < 0x80);
      *(undefined4 **)(iVar4 + -4 + local_28 * 4) = puVar10 + 1;
      uVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
      puVar10 = (undefined4 *)FUN_001a7bca(uVar6,0x20c);
      *puVar10 = uVar6;
      puVar10[2] = 0x1000;
      puVar10[1] = 0x80;
      uVar14 = 0;
      puVar8 = puVar10 + 1;
      do {
        puVar8[2] = 0;
        uVar14 = uVar14 + 1;
        puVar8 = puVar8 + 1;
      } while (uVar14 < 0x80);
      *(undefined4 **)(iVar5 + -4 + local_28 * 4) = puVar10 + 1;
      iVar15 = *(int *)(param_1 + 8);
      bVar2 = local_28 < *(int *)(*(int *)(iVar15 + 0x54) + 0x14);
      local_28 = local_28 + 1;
    } while (bVar2);
  }
  iVar9 = *(int *)(param_1 + 0x378);
  if (*(int *)(iVar9 + 8) == 0) {
LAB_0013935a:
    iVar9 = *(int *)(*(int *)(iVar15 + 0x54) + 0x14);
    iVar7 = iVar9 + -1;
    if (-1 < iVar7) {
      iVar7 = iVar7 * 4;
      piVar17 = (int *)(iVar5 + iVar7);
      piVar16 = (int *)(iVar4 + iVar7);
      local_2c = 0;
      do {
        iVar15 = *piVar17;
        if (iVar15 != 0) {
          FUN_001a7aba(*(undefined4 *)(iVar15 + -4),iVar15 + -4);
        }
        iVar15 = *piVar16;
        if (iVar15 != 0) {
          FUN_001a7aba(*(undefined4 *)(iVar15 + -4),iVar15 + -4);
        }
        local_2c = local_2c + 1;
        piVar17 = piVar17 + -1;
        piVar16 = piVar16 + -1;
      } while (iVar9 != local_2c);
      iVar15 = *(int *)(param_1 + 8);
    }
    FUN_001a7aba(*(undefined4 *)(iVar15 + 0xbc),iVar5);
    FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xbc),iVar4);
    iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 0x14) << 2;
    puVar8 = (undefined4 *)FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xbc),iVar4);
    *puVar8 = 0;
    iVar15 = *(int *)(param_1 + 8);
    if (1 < *(int *)(*(int *)(iVar15 + 0x54) + 0x14)) {
      iVar5 = 1;
      do {
        puVar8[iVar5] =
             (puVar8 + iVar5)[-1] +
             *(int *)(*(int *)(*(int *)(param_1 + 0x3b4) + 0x14) + -4 + iVar5 * 4);
        iVar5 = iVar5 + 1;
        iVar15 = *(int *)(param_1 + 8);
      } while (iVar5 < *(int *)(*(int *)(iVar15 + 0x54) + 0x14));
    }
    iVar4 = FUN_001a7bca(*(undefined4 *)(iVar15 + 0xbc),iVar4);
    iVar15 = *(int *)(param_1 + 8);
    if (0 < *(int *)(*(int *)(iVar15 + 0x54) + 0x14)) {
      iVar5 = 0;
      do {
        *(undefined4 *)(iVar4 + iVar5 * 4) = 0;
        iVar5 = iVar5 + 1;
        iVar15 = *(int *)(param_1 + 8);
      } while (iVar5 < *(int *)(*(int *)(iVar15 + 0x54) + 0x14));
    }
    iVar5 = *(int *)(param_1 + 0x378);
    if (*(int *)(iVar5 + 8) != 0) {
      do {
        piVar16 = *(int **)(iVar5 + 0x98);
        iVar15 = piVar16[2];
        while (iVar15 != 0) {
          while ((((*(byte *)(piVar16 + 5) & 1) == 0 || (piVar16[0x20] == 0)) ||
                 ((cVar3 = FUN_0012dfd8(piVar16[0x26]), cVar3 == '\0' ||
                  (((*(byte *)(piVar16 + 5) & 2) != 0 ||
                   (cVar3 = (**(code **)(*piVar16 + 0x50))(piVar16), cVar3 != '\0'))))))) {
            piVar16 = (int *)piVar16[2];
            if (piVar16[2] == 0) goto LAB_001395bb;
          }
          iVar15 = ((int (*)())FUN_0013816c)(param_1,piVar16);
          if ((*(byte *)(piVar16 + 5) & 0x40) == 0) {
            if (param_5 == '\0') {
              local_38 = param_3 + piVar16[0x25];
            }
            else {
              local_38 = piVar16[0x25];
            }
            local_30 = local_38 * 4;
            *(undefined4 *)(*(int *)(param_1 + 0x44c) + local_30) = 0xffffffff;
          }
          else {
            iVar9 = piVar16[0x25];
            iVar12 = iVar9 * 4;
            iVar7 = *(int *)(param_1 + 0x454);
            piVar17 = (int *)(iVar12 + iVar7);
            if (*piVar17 == -1) {
              iVar13 = iVar15 * 4;
              piVar11 = (int *)(iVar4 + iVar13);
              *piVar17 = *piVar11;
              *piVar11 = *piVar11 + 1;
              iVar7 = *(int *)(param_1 + 0x454);
            }
            else {
              iVar13 = iVar15 << 2;
            }
            local_38 = *(int *)(iVar12 + iVar7) + *(int *)((int)puVar8 + iVar13);
            local_30 = local_38 * 4;
            *(int *)(*(int *)(param_1 + 0x44c) + local_30) = iVar9;
          }
          iVar9 = FUN_0010b0f4(piVar16,0);
          *(int *)(iVar9 + 8) = local_38;
          *(int *)(*(int *)(param_1 + 0x450) + local_30) = iVar15;
          piVar16 = (int *)piVar16[2];
          iVar15 = piVar16[2];
        }
LAB_001395bb:
        iVar5 = *(int *)(iVar5 + 8);
      } while (*(int *)(iVar5 + 8) != 0);
      iVar15 = *(int *)(param_1 + 8);
    }
    *(undefined4 *)(param_1 + 0x34) = 4;
    FUN_001a7aba(*(undefined4 *)(iVar15 + 0xbc),puVar8);
    FUN_000e1c3e();
    return;
  }
  do {
    piVar16 = *(int **)(iVar9 + 0x98);
    iVar15 = piVar16[2];
joined_r0x0013925c:
    if (iVar15 != 0) {
      do {
        if (((((*(byte *)(piVar16 + 5) & 1) != 0) && (piVar16[0x20] != 0)) &&
            (cVar3 = FUN_0012dfd8(piVar16[0x26]), cVar3 != '\0')) &&
           (((*(byte *)(piVar16 + 5) & 2) == 0 &&
            (cVar3 = (**(code **)(*piVar16 + 0x50))(piVar16), cVar3 == '\0')))) {
          iVar15 = ((int (*)())FUN_0013816c)(param_1,piVar16);
          uVar14 = piVar16[0x25];
          if ((*(byte *)(piVar16 + 5) & 0x40) == 0) {
            piVar17 = (int *)(iVar5 + iVar15 * 4);
            local_90 = (byte)uVar14 & 0x1f;
            if ((*(uint *)(*piVar17 + 8 + (uVar14 >> 5) * 4) >> local_90 & 1) == 0)
            goto code_r0x00139303;
          }
          else {
            piVar17 = (int *)(iVar4 + iVar15 * 4);
            local_90 = (byte)uVar14 & 0x1f;
            if ((*(uint *)(*piVar17 + 8 + (uVar14 >> 5) * 4) >> local_90 & 1) == 0) {
              piVar11 = (int *)(iVar15 * 4 + *(int *)(*(int *)(param_1 + 0x3b4) + 0x14));
              *piVar11 = *piVar11 + 1;
              puVar1 = (uint *)(*piVar17 + 8 + (uVar14 >> 5) * 4);
              *puVar1 = *puVar1 | 1 << local_90;
            }
          }
        }
        piVar16 = (int *)piVar16[2];
        if (piVar16[2] == 0) break;
      } while( true );
    }
    iVar9 = *(int *)(iVar9 + 8);
    if (*(int *)(iVar9 + 8) == 0) {
      iVar15 = *(int *)(param_1 + 8);
      goto LAB_0013935a;
    }
  } while( true );
code_r0x00139303:
  piVar11 = (int *)(iVar15 * 4 + *(int *)(*(int *)(param_1 + 0x3b4) + 0x18));
  *piVar11 = *piVar11 + 1;
  puVar1 = (uint *)(*piVar17 + 8 + (uVar14 >> 5) * 4);
  *puVar1 = *puVar1 | 1 << local_90;
  piVar16 = (int *)piVar16[2];
  iVar15 = piVar16[2];
  goto joined_r0x0013925c;
}

/* FUN_001397d6 @ 0x1397d6 (3666 bytes) */
int FUN_001397d6(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  uint *puVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint *puVar11;
  undefined4 uVar12;
  int *piVar13;
  int iVar14;
  int *piVar15;
  byte bVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  uint local_b0;
  int *local_64;
  int *local_60;
  int local_5c;
  int local_54;
  int local_50;
  int local_44;
  int local_40;
  uint local_3c;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar2 = *(int *)(param_6 + 0x3f4);
  *(undefined4 *)(iVar2 + 0x240) = 0;
  *(undefined4 *)(iVar2 + 0x244) = 0;
  if (0 < param_3) {
    iVar19 = 0;
    while (iVar19 = iVar19 + 1, param_3 != iVar19) {
      while (0 < iVar19) {
        iVar18 = 0;
        do {
          FUN_0013c894(param_2,iVar19,iVar18);
          iVar18 = iVar18 + 1;
        } while (iVar19 != iVar18);
        iVar19 = iVar19 + 1;
        if (param_3 == iVar19) goto LAB_00139847;
      }
    }
  }
LAB_00139847:
  uVar4 = param_4 * 4;
  uVar12 = *(undefined4 *)(param_6 + 0xbc);
  uVar20 = uVar4 + 0x1f >> 5;
  puVar5 = (undefined4 *)FUN_001a7bca(uVar12,uVar20 * 4 + 0xc);
  puVar1 = puVar5 + 1;
  *puVar5 = uVar12;
  puVar5[2] = uVar4;
  puVar5[1] = uVar20;
  if (uVar20 != 0) {
    uVar17 = 0;
    puVar6 = puVar1;
    do {
      puVar6[2] = 0;
      uVar17 = uVar17 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar17 < uVar20);
  }
  uVar12 = *(undefined4 *)(param_6 + 0xbc);
  puVar7 = (undefined4 *)FUN_001a7bca(uVar12,0x18);
  *puVar7 = uVar12;
  puVar6 = puVar7 + 1;
  puVar7[4] = uVar12;
  puVar7[2] = 0;
  puVar7[1] = 2;
  uVar8 = FUN_001a7bca(uVar12,8);
  puVar7[3] = uVar8;
  uVar20 = param_4 + 0x1fU >> 5;
  puVar9 = (undefined4 *)FUN_001a7bca(uVar12,uVar20 * 4 + 0xc);
  *puVar9 = uVar12;
  puVar9[2] = param_4;
  puVar9[1] = uVar20;
  if (uVar20 != 0) {
    uVar17 = 0;
    puVar10 = puVar9 + 1;
    do {
      puVar10[2] = 0;
      uVar17 = uVar17 + 1;
      puVar10 = puVar10 + 1;
    } while (uVar17 < uVar20);
  }
  puVar7[5] = puVar9 + 1;
  iVar2 = *(int *)(iVar2 + 0x378);
  iVar19 = *(int *)(iVar2 + 8);
  do {
    if (iVar19 == 0) {
      if (puVar1 != (uint *)0x0) {
        FUN_001a7aba(*puVar5,puVar5);
      }
      return;
    }
    if (*puVar1 != 0) {
      uVar20 = 0;
      puVar11 = puVar1;
      do {
        puVar11[2] = 0;
        uVar20 = uVar20 + 1;
        puVar11 = puVar11 + 1;
      } while (uVar20 < *puVar1);
    }
    if (param_5 == '\0') {
      iVar19 = *(int *)(iVar2 + 0x100);
      if (*puVar1 != 0) {
        uVar17 = 0;
        uVar20 = *puVar1;
        puVar11 = puVar1;
        do {
          puVar11[2] = *(uint *)(iVar19 + 8);
          uVar17 = uVar17 + 1;
          iVar19 = iVar19 + 4;
          puVar11 = puVar11 + 1;
        } while (uVar17 < uVar20);
      }
    }
    else if (0 < (int)uVar4) {
      uVar20 = 0;
      do {
        if ((*(uint *)(*(int *)(iVar2 + 0x100) + 8 + (uVar20 >> 5) * 4) >> ((byte)uVar20 & 0x1f) & 1
            ) != 0) {
          uVar17 = uVar20;
          if ((int)uVar20 < 0) {
            uVar17 = uVar20 + 3;
          }
          iVar19 = ((int (*)())FUN_0013c266)(param_2,(int)uVar17 >> 2,1);
          uVar17 = uVar20 & 0x80000003;
          if ((int)uVar17 < 0) {
            uVar17 = (uVar17 - 1 | 0xfffffffc) + 1;
          }
          uVar17 = uVar17 + iVar19 * 4;
          puVar5[(uVar17 >> 5) + 3] = puVar5[(uVar17 >> 5) + 3] | 1 << ((byte)uVar17 & 0x1f);
        }
        uVar20 = uVar20 + 1;
      } while (uVar4 != uVar20);
    }
    iVar19 = (*(int **)(iVar2 + 0xa0))[1];
    local_64 = *(int **)(iVar2 + 0xa0);
joined_r0x0013999c:
    if (iVar19 != 0) {
      do {
        if ((local_64 != *(int **)(iVar2 + 0x98)) &&
           (piVar15 = (int *)local_64[1], (*(byte *)(piVar15 + 5) & 4) != 0)) goto LAB_00139b12;
        if (local_64 != (int *)0x0) {
          local_60 = local_64;
          do {
            uVar20 = local_60[5];
            if ((uVar20 & 1) == 0) goto LAB_001399cd;
            iVar19 = (**(code **)(*local_60 + 0x7c))(local_60);
            if (iVar19 == 0) {
              if (local_60[0x20] == 0) goto LAB_00139e43;
              cVar3 = FUN_0012dfd8(local_60[0x26]);
              if (cVar3 == '\0') goto LAB_001399fd;
              uVar20 = local_60[5];
              if ((uVar20 & 2) == 0) {
                cVar3 = (**(code **)(*local_60 + 0x50))(local_60);
                if (cVar3 == '\0') {
                  local_2c = -1;
                  local_28 = 0xffffffff;
                  local_24 = 0xffffffff;
                  local_20 = 0xffffffff;
                  uVar20 = ((int (*)())FUN_0013c266)(param_2,local_60[0x25],param_5);
                  cVar3 = (**(code **)(*local_60 + 100))(local_60);
                  if (cVar3 != '\0') {
                    for (iVar19 = 1; iVar18 = (**(code **)(*local_60 + 0x14))(local_60),
                        iVar19 <= iVar18; iVar19 = iVar19 + 1) {
                      if ((((local_60[iVar19 * 6 + 0x28] & 1U) != 0) ||
                          ((local_60[iVar19 * 6 + 0x28] & 2U) != 0)) ||
                         (cVar3 = FUN_000f5a1e(local_60,iVar19), cVar3 == '\0')) goto LAB_00139f76;
                    }
                    if (((char)local_60[0x48] == '\0') && (local_60[0x49] == 0)) {
                      if (((local_60[0x20] != 0) &&
                          ((cVar3 = FUN_0012dfd8(local_60[0x26]), cVar3 != '\0' &&
                           ((*(byte *)(local_60 + 5) & 2) == 0)))) &&
                         (cVar3 = (**(code **)(*local_60 + 0x50))(local_60), cVar3 == '\0')) {
                        iVar19 = 0;
                        piVar15 = local_60;
                        do {
                          if ((byte)((char)piVar15[0x27] - 2U) < 2) goto LAB_00139f76;
                          iVar19 = iVar19 + 1;
                          piVar15 = (int *)((int)piVar15 + 1);
                        } while (iVar19 != 4);
                      }
                      FUN_0010b0f4(local_60,0);
                      iVar19 = FUN_0010b7c8(local_60,0);
                      if (((((iVar19 == 0) && ((local_60[5] & 2U) == 0)) &&
                           ((local_60[5] & 0x200U) == 0)) &&
                          ((piVar15 = (int *)FUN_0010b180(local_60,1), piVar15[0x20] != 0 &&
                           (cVar3 = FUN_0012dfd8(piVar15[0x26]), cVar3 != '\0')))) &&
                         (((*(byte *)(piVar15 + 5) & 2) == 0 &&
                          (cVar3 = (**(code **)(*piVar15 + 0x50))(piVar15), cVar3 == '\0')))) {
                        local_2c = ((int (*)())FUN_0013c266)(param_2,piVar15[0x25],param_5);
                      }
                    }
                  }
LAB_00139f76:
                  cVar3 = ((int (*)())FUN_00137f5c)(puVar1,uVar20);
                  if (cVar3 == '\0') {
                    if ((*(uint *)(puVar7[5] + 8 + (uVar20 >> 5) * 4) >> ((byte)uVar20 & 0x1f) & 1)
                        != 0) goto LAB_001399fd;
                    uVar17 = puVar7[2];
                    if (uVar17 < *puVar6) {
                      _memset((void *)(uVar17 * 4 + puVar7[3]),0,4);
                      puVar7[2] = uVar17 + 1;
                      puVar11 = (uint *)(uVar17 * 4 + puVar7[3]);
                    }
                    else {
                      puVar11 = (uint *)FUN_001a7f7c(puVar6,uVar17);
                    }
                    *puVar11 = uVar20;
                    uVar20 = local_60[5];
                  }
                  else {
                    if (0 < param_4) {
                      local_5c = 0;
                      do {
                        if ((((*(byte *)((int)local_60 + 0x15) & 2) == 0) ||
                            (piVar15 = (int *)FUN_0010b180(local_60,local_60[0x21]),
                            piVar15 == (int *)0x0)) ||
                           ((piVar15[0x20] == 0 ||
                            (((cVar3 = FUN_0012dfd8(piVar15[0x26]), cVar3 == '\0' ||
                              ((*(byte *)(piVar15 + 5) & 2) != 0)) ||
                             (cVar3 = (**(code **)(*piVar15 + 0x50))(piVar15), cVar3 != '\0')))))) {
                          iVar19 = 0;
                          do {
                            iVar18 = FUN_0010b0f4(local_60,0);
                            if ((*(char *)(iVar19 + 0x10 + iVar18) != '\x01') &&
                               (cVar3 = ((int (*)())FUN_00137f3a)(puVar1,local_5c,iVar19), cVar3 != '\0')) {
                              uVar12 = ((int (*)())FUN_0013c266)(param_2,local_5c,param_5);
                              cVar3 = FUN_00137b38(uVar12,&local_2c);
                              if (cVar3 == '\0') {
                                FUN_0013c894(param_2,uVar20,uVar12);
                                break;
                              }
                            }
                            iVar19 = iVar19 + 1;
                          } while (iVar19 != 4);
                        }
                        else {
                          iVar19 = ((int (*)())FUN_0013c266)(param_2,piVar15[0x25],param_5);
                          iVar18 = 0;
                          do {
                            cVar3 = ((int (*)())FUN_00137f3a)(puVar1,local_5c,iVar18);
                            if (((cVar3 != '\0') &&
                                (iVar14 = ((int (*)())FUN_0013c266)(param_2,local_5c,param_5), iVar14 != local_2c
                                )) && ((iVar14 != iVar19 ||
                                       (cVar3 = FUN_000f5990(local_60,iVar18), cVar3 != '\0')))) {
                              FUN_0013c894(param_2,uVar20,iVar14);
                              break;
                            }
                            iVar18 = iVar18 + 1;
                          } while (iVar18 != 4);
                        }
                        local_5c = local_5c + 1;
                      } while (param_4 != local_5c);
                    }
                    if ((((*(int *)(local_60[0x22] + 8) == 0x32) &&
                         (piVar15 = (int *)FUN_0010b180(local_60,1), piVar15[0x20] != 0)) &&
                        (cVar3 = FUN_0012dfd8(piVar15[0x26]), cVar3 != '\0')) &&
                       (((*(byte *)(piVar15 + 5) & 2) == 0 &&
                        (cVar3 = (**(code **)(*piVar15 + 0x50))(piVar15), cVar3 == '\0')))) {
                      iVar19 = FUN_0010b180(local_60,1);
                      uVar12 = ((int (*)())FUN_0013c266)(param_2,*(undefined4 *)(iVar19 + 0x94),param_5);
                      FUN_0013c894(param_2,uVar20,uVar12);
                    }
                    cVar3 = (**(code **)(*local_60 + 0x2c))(local_60);
                    if (cVar3 == '\0') goto LAB_00139e43;
                    iVar19 = FUN_0010b180(local_60,1);
                    uVar12 = ((int (*)())FUN_0013c266)(param_2,*(undefined4 *)(iVar19 + 0x94),param_5);
                    FUN_0013c894(param_2,uVar20,uVar12);
                    uVar20 = local_60[5];
                  }
                }
                else {
LAB_00139e43:
                  uVar20 = local_60[5];
                }
              }
LAB_001399cd:
              local_60 = (int *)local_60[2];
            }
            else {
LAB_001399fd:
              uVar20 = local_60[5];
              local_60 = (int *)local_60[2];
            }
            piVar15 = local_64;
          } while ((local_60 != (int *)0x0) && ((uVar20 & 4) != 0));
          do {
            uVar20 = piVar15[5];
            if ((uVar20 & 1) == 0) {
LAB_00139a1a:
              piVar15 = (int *)piVar15[2];
            }
            else {
              iVar19 = (**(code **)(*piVar15 + 0x7c))(piVar15);
              if (((iVar19 == 0) && (piVar15[0x20] != 0)) &&
                 (cVar3 = FUN_0012dfd8(piVar15[0x26]), cVar3 != '\0')) {
                uVar20 = piVar15[5];
                if ((uVar20 & 2) != 0) goto LAB_00139a1a;
                cVar3 = (**(code **)(*piVar15 + 0x50))(piVar15);
                if (cVar3 != '\0') goto LAB_00139a43;
                iVar19 = ((int (*)())FUN_0013c266)(param_2,piVar15[0x25],param_5);
                local_3c = iVar19 << 2;
                local_54 = 0;
                uVar20 = local_3c;
                do {
                  iVar19 = FUN_0010b0f4(piVar15,0);
                  if (*(char *)(local_54 + 0x10 + iVar19) != '\x01') {
                    puVar5[(uVar20 >> 5) + 3] =
                         puVar5[(uVar20 >> 5) + 3] & ~(1 << ((byte)uVar20 & 0x1f));
                  }
                  local_54 = local_54 + 1;
                  uVar20 = uVar20 + 1;
                } while (local_54 != 4);
                uVar20 = piVar15[5];
                if ((uVar20 & 0x200) == 0) goto LAB_00139a1a;
                piVar13 = (int *)FUN_0010b180(piVar15,piVar15[0x21]);
                if (((piVar13 == (int *)0x0) || (piVar13[0x20] == 0)) ||
                   ((cVar3 = FUN_0012dfd8(piVar13[0x26]), cVar3 == '\0' ||
                    (((*(byte *)(piVar13 + 5) & 2) != 0 ||
                     (cVar3 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar3 != '\0'))))))
                goto LAB_00139a43;
                local_50 = 0;
                do {
                  iVar19 = FUN_0010b0f4(piVar15,0);
                  if ((*(char *)(local_50 + 0x10 + iVar19) == '\x01') &&
                     (cVar3 = FUN_0013fb98(piVar13,local_50), cVar3 != '\0')) {
                    puVar5[(local_3c >> 5) + 3] =
                         puVar5[(local_3c >> 5) + 3] & ~(1 << ((byte)local_3c & 0x1f));
                  }
                  local_50 = local_50 + 1;
                  local_3c = local_3c + 1;
                } while (local_50 != 4);
                uVar20 = piVar15[5];
              }
              else {
LAB_00139a43:
                uVar20 = piVar15[5];
              }
              piVar15 = (int *)piVar15[2];
            }
          } while ((piVar15 != (int *)0x0) && ((uVar20 & 4) != 0));
        }
        while (puVar7[2] != 0) {
          uVar20 = puVar7[2];
          if (uVar20 - 1 < uVar20) {
            puVar11 = (uint *)(puVar7[3] + (uVar20 - 1) * 4);
          }
          else {
            puVar11 = (uint *)0x0;
          }
          uVar17 = *puVar11;
          FUN_001a7f3c(puVar6,uVar20 - 1);
          bVar16 = (byte)uVar17 & 0x1f;
          puVar11 = (uint *)(puVar7[5] + 8 + (uVar17 >> 5) * 4);
          *puVar11 = *puVar11 & (-2 << bVar16 | 0xfffffffeU >> 0x20 - bVar16);
          if (0 < param_4) {
            iVar19 = 0;
            do {
              cVar3 = ((int (*)())FUN_00137f5c)(puVar1,iVar19);
              if (cVar3 != '\0') {
                uVar12 = ((int (*)())FUN_0013c266)(param_2,iVar19,param_5);
                FUN_0013c894(param_2,uVar17,uVar12);
              }
              iVar19 = iVar19 + 1;
            } while (param_4 != iVar19);
          }
        }
        piVar15 = local_64;
        if (local_64 != (int *)0x0) goto LAB_00139b80;
        local_64 = (int *)MACH_HEADER.cputype;
        if (*(int *)(MACH_HEADER.cputype + 4) == 0) break;
      } while( true );
    }
    iVar2 = *(int *)(iVar2 + 8);
    iVar19 = *(int *)(iVar2 + 8);
  } while( true );
LAB_00139b80:
  do {
    uVar20 = piVar15[5];
    if ((uVar20 & 1) != 0) {
      iVar19 = FUN_0010b0f4(piVar15,0);
      if (((((*(int *)(iVar19 + 0x10) == DAT_001cc530) || (*(int *)(piVar15[0x22] + 8) == 0x8e)) ||
           (cVar3 = (**(code **)(*piVar15 + 0x34))(piVar15), cVar3 != '\0')) ||
          ((cVar3 = (**(code **)(*piVar15 + 0x38))(piVar15), cVar3 != '\0' ||
           (cVar3 = (**(code **)(*piVar15 + 0x60))(piVar15), cVar3 != '\0')))) ||
         (cVar3 = (**(code **)(*piVar15 + 0x5c))(piVar15), cVar3 != '\0')) {
LAB_00139bbd:
        uVar20 = piVar15[5];
      }
      else {
        iVar19 = piVar15[0x21];
        uVar20 = piVar15[5];
        if ((uVar20 & 0x200) != 0) {
          iVar19 = iVar19 + -1;
        }
        if (0 < iVar19) {
          local_44 = 1;
          do {
            piVar13 = (int *)FUN_0010b180(piVar15,local_44);
            if (((piVar13[0x20] != 0) && (cVar3 = FUN_0012dfd8(piVar13[0x26]), cVar3 != '\0')) &&
               (((*(byte *)(piVar13 + 5) & 2) == 0 &&
                ((cVar3 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar3 == '\0' &&
                 (cVar3 = FUN_0013f888(piVar15,local_44,piVar15), cVar3 == '\0')))))) {
              iVar18 = FUN_0010b0f4(piVar15,local_44);
              local_2c = FUN_000f5bdc(*(undefined4 *)(iVar18 + 0x10));
              iVar18 = ((int (*)())FUN_0013c266)(param_2,piVar13[0x25],param_5);
              local_b0 = iVar18 << 2;
              iVar18 = 0;
              do {
                if (*(char *)((int)&local_2c + iVar18) != '\0') {
                  puVar5[(local_b0 >> 5) + 3] =
                       puVar5[(local_b0 >> 5) + 3] | 1 << ((byte)local_b0 & 0x1f);
                }
                iVar18 = iVar18 + 1;
                local_b0 = local_b0 + 1;
              } while (iVar18 != 4);
            }
            local_44 = local_44 + 1;
          } while (local_44 <= iVar19);
          uVar20 = piVar15[5];
        }
        if ((uVar20 & 0x200) != 0) {
          piVar13 = (int *)FUN_0010b180(piVar15,piVar15[0x21]);
          if ((((piVar13 == (int *)0x0) || (piVar13[0x20] == 0)) ||
              (cVar3 = FUN_0012dfd8(piVar13[0x26]), cVar3 == '\0')) ||
             ((((*(byte *)(piVar13 + 5) & 2) != 0 ||
               (cVar3 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar3 != '\0')) ||
              (cVar3 = FUN_0013f888(piVar15,piVar15[0x21],piVar15), cVar3 != '\0'))))
          goto LAB_00139bbd;
          iVar19 = ((int (*)())FUN_0013c266)(param_2,piVar13[0x25],param_5);
          uVar20 = iVar19 * 4;
          local_40 = 0;
          do {
            iVar19 = FUN_0010b0f4(piVar15,0);
            if ((*(char *)(local_40 + 0x10 + iVar19) == '\x01') &&
               (cVar3 = FUN_0013fb98(piVar13,local_40), cVar3 != '\0')) {
              puVar5[(uVar20 >> 5) + 3] = puVar5[(uVar20 >> 5) + 3] | 1 << ((byte)uVar20 & 0x1f);
            }
            local_40 = local_40 + 1;
            uVar20 = uVar20 + 1;
          } while (local_40 != 4);
          uVar20 = piVar15[5];
        }
      }
    }
  } while (((int *)piVar15[2] != (int *)0x0) && (piVar15 = (int *)piVar15[2], (uVar20 & 4) != 0));
  piVar15 = (int *)local_64[1];
LAB_00139b12:
  iVar19 = piVar15[1];
  local_64 = piVar15;
  goto joined_r0x0013999c;
}

/* FUN_0013a664 @ 0x13a664 (300 bytes) */
int FUN_0013a664(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  do {
    piVar2 = (int *)FUN_0010b180(param_2,param_2[0x21]);
    if (((piVar2[0x20] != 0) && (cVar1 = FUN_0012dfd8(piVar2[0x26]), cVar1 != '\0')) &&
       ((*(byte *)(piVar2 + 5) & 2) == 0)) {
      (**(code **)(*piVar2 + 0x50))(piVar2);
    }
    uVar3 = ((int (*)())FUN_0013c266)(param_1,param_2[0x25],0);
    iVar4 = ((int (*)())FUN_0013c266)(param_1,piVar2[0x25],0);
    cVar1 = FUN_0013cb02(param_1,iVar4,uVar3);
  } while (((((cVar1 != '\0') && ((*(byte *)((int)piVar2 + 0x15) & 2) != 0)) &&
            ((piVar5 = (int *)FUN_0010b180(piVar2,piVar2[0x21]), piVar5[0x20] != 0 &&
             ((cVar1 = FUN_0012dfd8(piVar5[0x26]), cVar1 != '\0' &&
              ((*(byte *)(piVar5 + 5) & 2) == 0)))))) &&
           (cVar1 = (**(code **)(*piVar5 + 0x50))(piVar5), cVar1 == '\0')) &&
          ((iVar6 = ((int (*)())FUN_0013c266)(param_1,piVar5[0x25],0), iVar4 != iVar6 &&
           (param_2 = piVar2, piVar2 != (int *)0x0))));
  return;
}

/* FUN_0013a790 @ 0x13a790 (3680 bytes) */
int FUN_0013a790(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  bool bVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  uint *puVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  uint *puVar16;
  undefined4 uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int local_a8;
  int *local_a0;
  int *local_98;
  int local_90;
  int local_8c;
  int local_80;
  int local_64;
  char local_3d;
  uint local_34;
  uint local_30;
  int local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  undefined4 local_18;
  int *local_14;
  undefined4 local_10;
  
  local_28 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_30 = 0;
  local_34 = 2;
  local_2c = FUN_001a7bca(local_28,8);
  local_18 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_20 = 0;
  local_24 = 2;
  local_1c = FUN_001a7bca(local_18,8);
  iVar4 = FUN_000f08fc(param_1);
  uVar17 = 0;
  do {
    *(undefined4 *)(param_1 + 0x250) = 0;
    if (0 < *(int *)(param_1 + 0x248)) {
      ((int (*)())FUN_0013c7fa)(param_2);
      ((int (*)())FUN_0013c3fc)(param_2);
      local_20 = 0;
    }
    piVar9 = (int *)(*(int *)(param_1 + 8) + 0xe0);
    *piVar9 = *piVar9 + 1;
    piVar9 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    (**(code **)(*piVar9 + 0x148))
              (piVar9,param_2,*(undefined4 *)(param_1 + 0x460),*(undefined4 *)(param_1 + 0x458),
               uVar17,*(int *)(param_1 + 8));
    local_3d = '\0';
    for (local_a8 = 0; iVar5 = FUN_001a7d8a(param_1 + 0x370), local_a8 < iVar5;
        local_a8 = local_a8 + 1) {
      iVar5 = *(int *)(iVar4 + local_a8 * 4);
      local_a0 = *(int **)(iVar5 + 0x98);
      if (local_a0[2] != 0) {
        bVar1 = false;
        do {
          if (local_a0 != (int *)0x0) {
            local_98 = (int *)0x0;
            piVar9 = local_a0;
            do {
              uVar18 = piVar9[5];
              if ((uVar18 & 1) == 0) goto LAB_0013a90f;
              iVar6 = (**(code **)(*piVar9 + 0x7c))(piVar9);
              if (iVar6 == 0) {
                if ((piVar9[5] & 0x10000U) == 0) {
                  if (local_98 == (int *)0x0) {
                    local_98 = piVar9;
                  }
                  if (bVar1) {
                    piVar9[5] = piVar9[5] | 0x1000;
                    bVar1 = false;
                  }
                }
                if (((*(byte *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 9) & 2) != 0) &&
                   (((((cVar3 = (**(code **)(*piVar9 + 0x28))(piVar9), cVar3 != '\0' ||
                       (cVar3 = (**(code **)(*piVar9 + 0x68))(piVar9), cVar3 != '\0')) &&
                      (piVar7 = (int *)FUN_0010b180(piVar9,1), piVar7[0x20] != 0)) &&
                     ((cVar3 = FUN_0012dfd8(piVar7[0x26]), cVar3 != '\0' &&
                      ((*(byte *)(piVar7 + 5) & 2) == 0)))) &&
                    (cVar3 = (**(code **)(*piVar7 + 0x50))(piVar7), cVar3 == '\0')))) {
                  iVar6 = FUN_0010b0f4(piVar9,1);
                  local_10 = FUN_000f5bdc(*(undefined4 *)(iVar6 + 0x10));
                  local_90 = -1;
                  local_8c = 0;
                  iVar6 = local_90;
                  if ((char)local_10 != '\0') goto LAB_0013ad21;
                  do {
                    do {
                      local_90 = iVar6;
                      iVar20 = local_8c + 1;
                      if (iVar20 == 4) goto LAB_0013aa3f;
                      iVar2 = local_8c + 1;
                      iVar6 = local_90;
                      local_8c = iVar20;
                    } while (*(char *)((int)&local_10 + iVar2) == '\0');
LAB_0013ad21:
                    piVar8 = (int *)FUN_0013fbf0(piVar7,local_8c,&local_14);
                    iVar6 = local_90;
                  } while ((((piVar8 == (int *)0x0) || (piVar8[0x20] == 0)) ||
                           ((cVar3 = FUN_0012dfd8(piVar8[0x26]), cVar3 == '\0' ||
                            ((((*(byte *)(piVar8 + 5) & 2) != 0 ||
                              (cVar3 = (**(code **)(*piVar8 + 0x50))(piVar8), cVar3 != '\0')) ||
                             (iVar20 = ((int (*)())FUN_0013c266)(param_2,piVar8[0x25],local_3d),
                             uVar18 = local_20, iVar6 = iVar20, local_90 == -1)))))) ||
                          (iVar6 = local_90, local_90 == iVar20));
                  if (local_20 < local_24) {
                    iVar6 = local_20 * 4;
                    _memset((void *)(iVar6 + local_1c),0,4);
                    local_20 = uVar18 + 1;
                    puVar12 = (undefined4 *)(iVar6 + local_1c);
                  }
                  else {
                    puVar12 = (undefined4 *)FUN_001a7f7c(&local_24,local_20);
                  }
                  *puVar12 = piVar9;
                }
LAB_0013aa3f:
                if ((((*(byte *)((int)piVar9 + 0x15) & 2) != 0) &&
                    (piVar7 = (int *)FUN_0010b180(piVar9,piVar9[0x21]),
                    (*(byte *)(piVar7 + 5) & 1) != 0)) &&
                   (((piVar7[0x20] != 0 &&
                     ((cVar3 = FUN_0012dfd8(piVar7[0x26]), cVar3 != '\0' &&
                      ((*(byte *)(piVar7 + 5) & 2) == 0)))) &&
                    (cVar3 = (**(code **)(*piVar7 + 0x50))(piVar7), cVar3 == '\0')))) {
                  iVar6 = ((int (*)())FUN_0013c266)(param_2,piVar9[0x25],local_3d);
                  iVar20 = ((int (*)())FUN_0013c266)(param_2,piVar7[0x25],local_3d);
                  if (iVar6 != iVar20) {
                    if (((*(byte *)(piVar9 + 5) & 0x40) == 0) ||
                       ((*(byte *)(piVar7 + 5) & 0x40) == 0)) {
                      if ((*(int *)(*(int *)(param_1 + 0x450) + iVar6 * 4) ==
                           *(int *)(*(int *)(param_1 + 0x450) + iVar20 * 4)) &&
                         (cVar3 = FUN_0013d252(param_2,iVar6,iVar20), cVar3 != '\0')) {
                        *(int *)(param_1 + 0x24c) = *(int *)(param_1 + 0x24c) + 1;
                        local_3d = '\x01';
                      }
                      else {
                        *(int *)(param_1 + 0x250) = *(int *)(param_1 + 0x250) + 1;
                      }
                    }
                    else if ((*(byte *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 9) & 2) == 0) {
                      ((int (*)())FUN_00138ab4)(param_2,piVar9,piVar7,param_1 + 0x458,local_a0,iVar5);
                    }
                  }
                }
                cVar3 = (**(code **)(*piVar9 + 100))(piVar9);
                if (cVar3 == '\0') goto LAB_0013a934;
                local_80 = 1;
                puVar14 = (uint *)(piVar9 + 0x2e);
                iVar6 = (**(code **)(*piVar9 + 0x14))(piVar9);
                if (0 < iVar6) {
                  do {
                    if ((((*puVar14 & 1) != 0) || ((*puVar14 & 2) != 0)) ||
                       (cVar3 = FUN_000f5a1e(piVar9,local_80), cVar3 == '\0')) goto LAB_0013a934;
                    local_80 = local_80 + 1;
                    puVar14 = puVar14 + 6;
                    iVar6 = (**(code **)(*piVar9 + 0x14))(piVar9);
                  } while (local_80 <= iVar6);
                }
                if (((char)piVar9[0x48] != '\0') || (piVar9[0x49] != 0)) goto LAB_0013a934;
                if (((piVar9[0x20] != 0) &&
                    ((cVar3 = FUN_0012dfd8(piVar9[0x26]), cVar3 != '\0' &&
                     ((*(byte *)(piVar9 + 5) & 2) == 0)))) &&
                   (cVar3 = (**(code **)(*piVar9 + 0x50))(piVar9), cVar3 == '\0')) {
                  iVar6 = 0;
                  piVar7 = piVar9;
                  do {
                    if ((byte)((char)piVar7[0x27] - 2U) < 2) goto LAB_0013a934;
                    iVar6 = iVar6 + 1;
                    piVar7 = (int *)((int)piVar7 + 1);
                  } while (iVar6 != 4);
                }
                FUN_0010b0f4(piVar9,0);
                iVar6 = FUN_0010b7c8(piVar9,0);
                if (iVar6 != 0) goto LAB_0013a934;
                uVar18 = piVar9[5];
                if ((((uVar18 & 2) == 0) && ((uVar18 & 0x200) == 0)) && (-1 < (int)uVar18)) {
                  piVar7 = (int *)FUN_0010b180(piVar9,1);
                  if (((piVar7[0x20] == 0) || (cVar3 = FUN_0012dfd8(piVar7[0x26]), cVar3 == '\0'))
                     || (((*(byte *)(piVar7 + 5) & 2) != 0 ||
                         (cVar3 = (**(code **)(*piVar7 + 0x50))(piVar7), cVar3 != '\0'))))
                  goto LAB_0013a934;
                  iVar6 = ((int (*)())FUN_0013c266)(param_2,piVar9[0x25],local_3d);
                  iVar20 = ((int (*)())FUN_0013c266)(param_2,piVar7[0x25],local_3d);
                  if (((0 < *(int *)(*(int *)(param_1 + 8) + 0x3ac)) &&
                      (*(int *)(*(int *)(param_1 + 0x450) + iVar6 * 4) ==
                       *(int *)(*(int *)(param_1 + 0x450) + iVar20 * 4))) &&
                     (cVar3 = FUN_0013d252(param_2,iVar6,iVar20), uVar18 = local_30, cVar3 != '\0'))
                  {
                    *(int *)(param_1 + 0x254) = *(int *)(param_1 + 0x254) + 1;
                    if ((*(byte *)((int)piVar9 + 0x15) & 0x10) != 0) {
                      if ((local_98 == (int *)0x0) || (local_98 == piVar9)) {
                        bVar1 = true;
                      }
                      else {
                        local_98[5] = local_98[5] | 0x1000;
                      }
                    }
                    if (((*(byte *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 9) & 2) == 0) ||
                       ((*(byte *)((int)piVar9 + 0x17) & 0x40) == 0)) {
                      (**(code **)(*piVar9 + 0xc))(piVar9,0,*(int *)(param_1 + 8));
                      local_3d = '\x01';
                      uVar18 = piVar9[5];
                    }
                    else {
                      if (local_30 < local_34) {
                        iVar6 = local_30 * 4;
                        _memset((void *)(iVar6 + local_2c),0,4);
                        local_30 = uVar18 + 1;
                        puVar12 = (undefined4 *)(iVar6 + local_2c);
                      }
                      else {
                        puVar12 = (undefined4 *)FUN_001a7f7c(&local_34,local_30);
                      }
                      *puVar12 = piVar9;
                      uVar18 = piVar9[5] | 0x80000000;
                      piVar9[5] = uVar18;
                      local_3d = '\x01';
                    }
                    goto LAB_0013a90f;
                  }
                  if ((iVar6 < *(int *)(param_1 + 0x460)) ||
                     (*(int *)(*(int *)(param_1 + 0x450) + iVar6 * 4) !=
                      *(int *)(*(int *)(param_1 + 0x450) + iVar20 * 4))) goto LAB_0013a934;
                  FUN_0013cc32(param_2,iVar6,iVar20);
                  uVar18 = piVar9[5];
                  goto LAB_0013a937;
                }
LAB_0013a90f:
                piVar9 = (int *)piVar9[2];
              }
              else {
LAB_0013a934:
                uVar18 = piVar9[5];
LAB_0013a937:
                piVar9 = (int *)piVar9[2];
              }
            } while ((piVar9 != (int *)0x0) && ((uVar18 & 4) != 0));
          }
          uVar18 = local_a0[5];
          local_a0 = (int *)local_a0[2];
          iVar6 = local_a0[2];
          while( true ) {
            if (iVar6 == 0) {
              if (bVar1) {
                local_14 = (int *)0x0;
                uVar18 = 1;
                iVar20 = 0;
                iVar6 = *(int *)(iVar5 + 0xd0);
                if (*(int *)(iVar6 + 4) != 0) {
                  do {
                    local_14 = *(int **)(iVar20 + *(int *)(iVar6 + 8));
                    if (local_14 != (int *)0x0) {
                      cVar3 = (**(code **)(*local_14 + 0x30))(local_14);
                      if (cVar3 == '\0') {
                        *(undefined1 *)(local_14 + 0x37) = 1;
                      }
                      else {
                        *(undefined1 *)(local_14[0x49] + 0xdc) = 1;
                      }
                    }
                    uVar18 = uVar18 + 1;
                    iVar20 = iVar20 + 4;
                    iVar6 = *(int *)(iVar5 + 0xd0);
                  } while (uVar18 <= *(uint *)(iVar6 + 4));
                }
              }
              goto LAB_0013a9e9;
            }
            if ((uVar18 & 4) == 0) break;
            uVar18 = local_a0[5];
            local_a0 = (int *)local_a0[2];
            iVar6 = local_a0[2];
          }
        } while( true );
      }
LAB_0013a9e9: ;
    }
    *(int *)(param_1 + 0x248) = *(int *)(param_1 + 0x248) + 1;
    if (local_3d == '\0') {
      iVar5 = *(int *)(param_1 + 8);
      goto LAB_0013af0d;
    }
    if (0 < *(int *)(param_1 + 0x458)) {
      iVar5 = 0;
      do {
        ((int (*)())FUN_0013c266)(param_2,iVar5,1);
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(param_1 + 0x458));
    }
    iVar5 = *(int *)(param_1 + 8);
    if (*(int *)(iVar5 + 0x3ac) <= *(int *)(param_1 + 0x248)) break;
    uVar17 = 1;
  } while( true );
  local_3d = '\x01';
LAB_0013af0d:
  *(undefined4 *)(param_1 + 0x34) = 5;
  if ((*(byte *)(*(int *)(iVar5 + 0x54) + 9) & 2) != 0) {
joined_r0x0013af29:
    if (local_30 != 0) {
      uVar18 = local_30 - 1;
      if (uVar18 < local_30) {
        piVar9 = (int *)(local_2c + uVar18 * 4);
      }
      else {
        piVar9 = (int *)0x0;
      }
      piVar9 = (int *)*piVar9;
      FUN_001a7f3c(&local_34,uVar18);
      iVar4 = ((int (*)())FUN_0013c266)(param_2,piVar9[0x25],0);
      piVar7 = (int *)FUN_0010b180(piVar9,1);
      do {
        cVar3 = (**(code **)(*piVar7 + 0x50))(piVar7);
        if (cVar3 != '\0') {
LAB_0013afe3:
          (**(code **)(*piVar9 + 0xc))(piVar9,0,*(undefined4 *)(param_1 + 8));
          break;
        }
        iVar5 = ((int (*)())FUN_0013c266)(param_2,piVar7[0x25],0);
        if ((*(byte *)((int)piVar7 + 0x15) & 2) == 0) {
          if (iVar4 == iVar5) goto LAB_0013afe3;
          break;
        }
        piVar7 = (int *)FUN_0010b180(piVar7,piVar7[0x21]);
      } while (iVar4 == iVar5);
      goto joined_r0x0013af29;
    }
    if (local_20 != 0) {
      FUN_0013f0d8(param_2,local_20);
      uVar18 = local_20;
      while (local_20 != 0) {
        uVar13 = local_20 - 1;
        if (uVar13 < local_20) {
          puVar12 = (undefined4 *)(local_1c + uVar13 * 4);
        }
        else {
          puVar12 = (undefined4 *)0x0;
        }
        uVar17 = *puVar12;
        FUN_001a7f3c(&local_24,uVar13);
        *(int *)(param_1 + 600) = *(int *)(param_1 + 600) + 1;
        uVar10 = FUN_0010b180(uVar17,1);
        piVar7 = (int *)((int (*)())FUN_001381d8)(param_2,uVar17,uVar10,param_1 + 0x458);
        iVar4 = FUN_0010b0f4(uVar17,1);
        iVar4 = FUN_000f5df2(*(undefined4 *)(iVar4 + 0x10));
        piVar7[0x27] = iVar4;
        uVar10 = FUN_000f5e66(iVar4);
        iVar4 = FUN_0010b0f4(piVar7,1);
        *(undefined4 *)(iVar4 + 0x10) = uVar10;
        local_10 = FUN_000f5bdc(uVar10);
        uVar10 = FUN_0010b180(piVar7,1);
        iVar4 = 0;
        piVar9 = piVar7;
        do {
          if ((*(char *)((int)&local_10 + iVar4) != '\0') &&
             (iVar5 = FUN_0013fbf0(uVar10,iVar4,&local_14), iVar5 == 0)) {
            *(undefined1 *)(piVar9 + 0x27) = 1;
            (**(code **)(*piVar7 + 0x88))(piVar7,1,iVar4,4);
          }
          iVar4 = iVar4 + 1;
          piVar9 = (int *)((int)piVar9 + 1);
        } while (iVar4 != 4);
        FUN_0010ba02(uVar17,1,piVar7,0,*(undefined4 *)(param_1 + 8));
      }
      piVar9 = *(int **)(*(int *)(param_1 + 8) + 0x54);
      (**(code **)(*piVar9 + 0x14c))(piVar9,param_1);
      iVar4 = *(int *)(param_1 + 0x458) * 4;
      local_64 = *(int *)(param_1 + 0x378);
      if (*(int *)(local_64 + 8) != 0) {
        uVar13 = iVar4 + 0x1fU >> 5;
        do {
          puVar14 = *(uint **)(local_64 + 0x100);
          uVar15 = uVar18 * 4 + puVar14[1];
          if (uVar15 + 0x1f >> 5 == *puVar14) {
            puVar14[1] = uVar15;
            uVar19 = uVar15 + uVar18 * -4;
            if (uVar19 < uVar15) {
              do {
                puVar14[(uVar19 >> 5) + 2] =
                     puVar14[(uVar19 >> 5) + 2] & ~(1 << ((byte)uVar19 & 0x1f));
                uVar19 = uVar19 + 1;
              } while (uVar19 < puVar14[1]);
            }
          }
          else {
            uVar17 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
            puVar12 = (undefined4 *)FUN_001a7bca(uVar17,uVar13 * 4 + 0xc);
            puVar16 = puVar12 + 1;
            *puVar12 = uVar17;
            puVar12[2] = iVar4;
            puVar12[1] = uVar13;
            if (uVar13 != 0) {
              uVar15 = 0;
              puVar11 = puVar16;
              do {
                puVar11[2] = 0;
                uVar15 = uVar15 + 1;
                puVar11 = puVar11 + 1;
              } while (uVar15 < uVar13);
            }
            *(uint **)(local_64 + 0x100) = puVar16;
            if (*puVar16 != 0) {
              uVar19 = 0;
              uVar15 = *puVar16;
              do {
                puVar16[2] = puVar16[2] | puVar14[2];
                uVar19 = uVar19 + 1;
                puVar16 = puVar16 + 1;
                puVar14 = puVar14 + 1;
              } while (uVar19 < uVar15);
            }
          }
          local_64 = *(int *)(local_64 + 8);
        } while (*(int *)(local_64 + 8) != 0);
      }
      ((int (*)())FUN_0013c7fa)(param_2);
      ((int (*)())FUN_0013c3fc)(param_2);
      piVar9 = *(int **)(*(int *)(param_1 + 8) + 0x54);
      (**(code **)(*piVar9 + 0x148))
                (piVar9,param_2,*(undefined4 *)(param_1 + 0x460),*(undefined4 *)(param_1 + 0x458),1,
                 *(int *)(param_1 + 8));
    }
  }
  if (local_3d != '\0') {
    ((int (*)())FUN_0013c7fa)(param_2);
    ((int (*)())FUN_0013c3fc)(param_2);
    piVar9 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    (**(code **)(*piVar9 + 0x148))
              (piVar9,param_2,*(undefined4 *)(param_1 + 0x460),*(undefined4 *)(param_1 + 0x458),0,
               *(int *)(param_1 + 8));
  }
  FUN_001a7aba(local_18,local_1c);
  FUN_001a7aba(local_28,local_2c);
  return;
}

/* FUN_0013b622 @ 0x13b622 (1158 bytes) */
int FUN_0013b622(param_1)
  int param_1;
{
  uint *puVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  undefined4 *puVar14;
  undefined4 uVar15;
  uint uVar16;
  uint uVar17;
  undefined1 local_39;
  int local_2c;
  int local_28;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x2c) + 0x3f4);
  uVar4 = ((int (*)())FUN_0013909a)(iVar2);
  uVar6 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xbc);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar6,0x14);
  *puVar5 = uVar6;
  puVar1 = puVar5 + 1;
  puVar5[4] = uVar6;
  puVar5[2] = 0;
  puVar5[1] = 2;
  uVar6 = FUN_001a7bca(uVar6,8);
  puVar5[3] = uVar6;
  local_2c = *(int *)(iVar2 + 0x378);
  if (*(int *)(local_2c + 8) == 0) {
    local_39 = 0;
  }
  else {
    local_39 = 0;
    do {
      piVar7 = *(int **)(local_2c + 0x98);
      iVar10 = piVar7[2];
      while (iVar10 != 0) {
        if (((((*(byte *)(piVar7 + 5) & 1) != 0) && (*(int *)(piVar7[0x22] + 8) != 0x8e)) &&
            (cVar3 = (**(code **)(*piVar7 + 0x78))(piVar7), cVar3 == '\0')) && (0 < piVar7[0x21])) {
          local_28 = 1;
          do {
            piVar11 = (int *)FUN_0010b180(piVar7,local_28);
            if (((piVar11[0x20] != 0) && (cVar3 = FUN_0012dfd8(piVar11[0x26]), cVar3 != '\0')) &&
               (((*(byte *)(piVar11 + 5) & 2) == 0 &&
                (cVar3 = (**(code **)(*piVar11 + 0x50))(piVar11), cVar3 == '\0')))) {
              iVar10 = piVar11[0x25];
              cVar3 = ((int (*)())FUN_00137f98)(param_1,iVar10);
              if (cVar3 != '\0') {
                piVar11[5] = piVar11[5] | 0x8000000;
                iVar12 = (**(code **)(*piVar7 + 0x14))(piVar7);
                if ((local_28 <= iVar12) && (cVar3 = ((int (*)())FUN_0013850a)(1,piVar7,local_28), cVar3 != '\0')
                   ) {
                  ((int (*)())FUN_00138060)(piVar7,param_1,*(undefined4 *)(param_1 + 0x2c));
                  if (((*(byte *)((int)piVar11 + 0x17) & 0x20) == 0) ||
                     ((*(byte *)(piVar11 + 6) & 1) != 0)) {
                    iVar10 = ((int (*)())FUN_00138d4c)(param_1,iVar10,uVar4);
                    iVar12 = ((int (*)())FUN_00137fda)(piVar7,*(undefined4 *)(iVar10 + 0x13c));
                    if (iVar12 == 0) {
                      uVar6 = *(undefined4 *)(param_1 + 0x2c);
                      uVar9 = ((int (*)())FUN_00137ef6)(piVar7);
                      iVar12 = FUN_0010b0f4(piVar7,local_28);
                      uVar8 = *(undefined4 *)(iVar12 + 0x10);
                      uVar15 = FUN_00137b60(param_1);
                      iVar12 = ((int (*)())FUN_00138654)(uVar15,uVar8,uVar4,iVar10,uVar9,uVar6);
                    }
                    FUN_0010ba02(piVar7,local_28,iVar12,0,*(undefined4 *)(param_1 + 0x2c));
                    uVar16 = puVar5[2];
                    if (0 < (int)uVar16) {
                      uVar17 = 0;
                      do {
                        if (uVar17 < uVar16) {
                          piVar13 = (int *)(puVar5[3] + uVar17 * 4);
                        }
                        else {
                          piVar13 = (int *)0x0;
                        }
                        if (piVar11 == (int *)*piVar13) goto LAB_0013b80b;
                        uVar17 = uVar17 + 1;
                      } while (uVar17 != uVar16);
                    }
                    if (uVar16 < *puVar1) {
                      _memset((void *)(uVar16 * 4 + puVar5[3]),0,4);
                      puVar5[2] = uVar16 + 1;
                      *(int **)(uVar16 * 4 + puVar5[3]) = piVar11;
                    }
                    else {
                      puVar14 = (undefined4 *)FUN_001a7f7c(puVar1,uVar16);
                      *puVar14 = piVar11;
                    }
                  }
                  else {
                    uVar6 = ((int (*)())FUN_00137ef6)(piVar7);
                    ((int (*)())FUN_001382da)(param_1,piVar7,local_28,uVar6,*(undefined4 *)(param_1 + 0x2c));
                    local_39 = 1;
                  }
                }
              }
            }
LAB_0013b80b:
            local_28 = local_28 + 1;
          } while (local_28 <= piVar7[0x21]);
        }
        piVar7 = (int *)piVar7[2];
        iVar10 = piVar7[2];
      }
      local_2c = *(int *)(local_2c + 8);
    } while (*(int *)(local_2c + 8) != 0);
  }
  if (0 < (int)puVar5[2]) {
    local_39 = 1;
  }
  if (puVar5[2] == 0) {
    iVar10 = *(int *)(iVar2 + 0x448);
  }
  else {
    do {
      uVar16 = puVar5[2] - 1;
      if (uVar16 < (uint)puVar5[2]) {
        piVar7 = (int *)(puVar5[3] + uVar16 * 4);
      }
      else {
        piVar7 = (int *)0x0;
      }
      iVar10 = *piVar7;
      FUN_001a7f3c(puVar1,puVar5[2] + -1);
      uVar6 = *(undefined4 *)(param_1 + 0x2c);
      uVar8 = ((int (*)())FUN_00137ee0)(iVar10);
      ((int (*)())FUN_00138060)(uVar8,param_1,uVar6);
      uVar6 = *(undefined4 *)(param_1 + 0x2c);
      uVar8 = ((int (*)())FUN_00137ed6)(iVar10);
      uVar9 = ((int (*)())FUN_00138d4c)(param_1,*(undefined4 *)(iVar10 + 0x94),uVar4);
      ((int (*)())FUN_0013877c)(iVar10,uVar4,uVar9,uVar8,uVar6);
      iVar10 = *(int *)(iVar2 + 0x448) + 1;
      *(int *)(iVar2 + 0x448) = iVar10;
    } while (puVar5[2] != 0);
  }
  ((int (*)())FUN_001390f8)(iVar2,uVar4,iVar10 << 2);
  return local_39;
}

/* FUN_0013bac8 @ 0x13bac8 (562 bytes) */
int FUN_0013bac8(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  int *piVar6;
  char cVar7;
  uint uVar8;
  int *piVar9;
  undefined4 *puVar10;
  int *piVar11;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x2c) + 0x3f4) + 0x378);
  iVar2 = *(int *)(iVar1 + 8);
  do {
    if (iVar2 == 0) {
      return;
    }
    iVar2 = (*(int **)(iVar1 + 0xa0))[1];
    piVar6 = *(int **)(iVar1 + 0xa0);
    while (iVar2 != 0) {
      piVar3 = piVar6;
      piVar11 = piVar6;
      if ((piVar6 == *(int **)(iVar1 + 0x98)) ||
         (piVar9 = (int *)piVar6[1], (*(byte *)(piVar9 + 5) & 4) == 0)) {
        do {
          if (piVar11 == (int *)0x0) break;
          uVar8 = piVar3[5];
          if ((uVar8 & 1) != 0) {
            if ((((piVar3[0x20] != 0) && (cVar7 = FUN_0012dfd8(piVar3[0x26]), cVar7 != '\0')) &&
                ((*(byte *)(piVar3 + 5) & 2) == 0)) &&
               ((cVar7 = (**(code **)(*piVar3 + 0x50))(piVar3), cVar7 == '\0' &&
                ((*(byte *)((int)piVar3 + 0x17) & 8) != 0)))) {
              uVar8 = piVar3[0x25];
              puVar4 = *(uint **)(param_1 + 4);
              if (uVar8 < *puVar4) {
                uVar5 = puVar4[1];
                if (uVar5 <= uVar8) {
                  _memset((void *)(puVar4[2] + uVar5 * 4),0,(uVar8 - uVar5) * 4 + 4);
                  puVar4[1] = uVar8 + 1;
                }
                piVar11 = (int *)(puVar4[2] + uVar8 * 4);
              }
              else {
                piVar11 = (int *)FUN_001a7f7c(puVar4,uVar8);
              }
              *(undefined1 *)(*piVar11 + 0x18) = 1;
            }
            if ((piVar3[0x20] == 0) || (cVar7 = FUN_0012dfd8(piVar3[0x26]), cVar7 == '\0')) {
LAB_0013bb37:
              uVar8 = piVar3[5];
            }
            else {
              uVar8 = piVar3[5];
              if ((uVar8 & 2) == 0) {
                cVar7 = (**(code **)(*piVar3 + 0x50))(piVar3);
                if (cVar7 != '\0') goto LAB_0013bb37;
                iVar2 = piVar3[0x1f];
                uVar8 = piVar3[0x25];
                puVar4 = *(uint **)(param_1 + 4);
                if (uVar8 < *puVar4) {
                  uVar5 = puVar4[1];
                  if (uVar5 <= uVar8) {
                    _memset((void *)(puVar4[2] + uVar5 * 4),0,(uVar8 - uVar5) * 4 + 4);
                    puVar4[1] = uVar8 + 1;
                  }
                  puVar10 = (undefined4 *)(puVar4[2] + uVar8 * 4);
                }
                else {
                  puVar10 = (undefined4 *)FUN_001a7f7c(puVar4,uVar8);
                }
                ((int (*)())FUN_0013c128)(*puVar10,iVar2);
                uVar8 = piVar3[5];
              }
            }
          }
          piVar11 = (int *)(uVar8 & 4);
          piVar3 = (int *)piVar3[2];
        } while (piVar3 != (int *)0x0);
        piVar9 = (int *)piVar6[1];
      }
      piVar6 = piVar9;
      iVar2 = piVar9[1];
    }
    iVar1 = *(int *)(iVar1 + 8);
    iVar2 = *(int *)(iVar1 + 8);
  } while( true );
}

/* FUN_0013bcfa @ 0x13bcfa (1039 bytes) */
int FUN_0013bcfa(param_1)
  int param_1;
{
  uint *puVar1;
  int *piVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  char local_29;
  
  ((int (*)())FUN_00138996)(param_1);
  iVar11 = *(int *)(param_1 + 8);
  if (*(int *)(iVar11 + 0x108) == -1) {
    return;
  }
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x400;
  *(undefined4 *)(param_1 + 0x42c) = 0;
  *(undefined4 *)(param_1 + 0x448) = 0;
  piVar2 = *(int **)(iVar11 + 0x54);
  iVar5 = (**(code **)(*piVar2 + 0x138))(piVar2,iVar11);
  iVar6 = (**(code **)(*piVar2 + 0x140))(piVar2,iVar11);
  iVar7 = (**(code **)(*piVar2 + 0x13c))(piVar2,iVar11);
  uVar3 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  iVar7 = iVar5 + iVar6 + iVar7;
  uVar15 = iVar7 + 0x1fU >> 5;
  iVar11 = uVar15 * 4 + 0xc;
  puVar8 = (undefined4 *)FUN_001a7bca(uVar3,iVar11);
  puVar1 = puVar8 + 1;
  *puVar8 = uVar3;
  puVar8[2] = iVar7;
  puVar8[1] = uVar15;
  if (uVar15 != 0) {
    uVar13 = 0;
    puVar9 = puVar1;
    do {
      puVar9[2] = 0;
      uVar13 = uVar13 + 1;
      puVar9 = puVar9 + 1;
    } while (uVar13 < uVar15);
  }
  iVar5 = *(int *)(param_1 + 0x420);
  if (*puVar1 != 0) {
    uVar14 = 0;
    uVar13 = *puVar1;
    puVar9 = puVar1;
    do {
      puVar9[2] = *(uint *)(iVar5 + 8);
      uVar14 = uVar14 + 1;
      iVar5 = iVar5 + 4;
      puVar9 = puVar9 + 1;
    } while (uVar14 < uVar13);
  }
  uVar3 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar8 = (undefined4 *)FUN_001a7bca(uVar3,iVar11);
  puVar9 = puVar8 + 1;
  *puVar8 = uVar3;
  puVar8[2] = iVar7;
  puVar8[1] = uVar15;
  if (uVar15 != 0) {
    uVar13 = 0;
    puVar10 = puVar9;
    do {
      puVar10[2] = 0;
      uVar13 = uVar13 + 1;
      puVar10 = puVar10 + 1;
    } while (uVar13 < uVar15);
  }
  iVar11 = *(int *)(param_1 + 0x424);
  if (*puVar9 != 0) {
    uVar13 = 0;
    uVar15 = *puVar9;
    puVar10 = puVar9;
    do {
      puVar10[2] = *(uint *)(iVar11 + 8);
      uVar13 = uVar13 + 1;
      iVar11 = iVar11 + 4;
      puVar10 = puVar10 + 1;
    } while (uVar13 < uVar15);
  }
  local_29 = '\0';
  do {
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
    puVar8 = (undefined4 *)FUN_001a7bca(uVar3,0x34);
    *puVar8 = uVar3;
    FUN_0013eb88(puVar8 + 1,*(undefined4 *)(param_1 + 0x460),*(undefined4 *)(param_1 + 0x458),
                 param_1,*(undefined4 *)(param_1 + 8));
    *(undefined4 **)(param_1 + 0x3b4) = puVar8 + 1;
    ((int (*)())FUN_0013917e)(param_1,*(undefined4 *)(param_1 + 0x45c),*(undefined4 *)(param_1 + 0x460),
                 *(undefined4 *)(param_1 + 0x458),local_29);
    if (local_29 != '\0') {
      ((int (*)())FUN_0013bac8)(*(undefined4 *)(param_1 + 0x3b4));
    }
    piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    (**(code **)(*piVar2 + 0x144))
              (piVar2,*(undefined4 *)(param_1 + 0x458),param_1,*(int *)(param_1 + 8));
    ((int (*)())FUN_0013a790)(param_1,*(undefined4 *)(param_1 + 0x3b4));
    FUN_0013fa08(param_1);
    if (local_29 != '\0') {
      FUN_0013f318(*(undefined4 *)(param_1 + 0x3b4),*(undefined4 *)(param_1 + 8));
    }
    cVar4 = FUN_0013d5b8(*(undefined4 *)(param_1 + 0x3b4));
    if (cVar4 != '\0') {
      iVar11 = *(int *)(*(int *)(param_1 + 0x3b4) + 0x24);
      uVar15 = *(uint *)(iVar11 + 4);
      if (uVar15 == 0) {
        iVar11 = *(int *)(param_1 + 8);
      }
      else {
        uVar13 = 0;
        iVar5 = 0;
        do {
          iVar5 = (iVar5 + 1) -
                  (uint)((*(uint *)(iVar11 + 8 + (uVar13 >> 5) * 4) >> ((byte)uVar13 & 0x1f) & 1) ==
                        0);
          uVar13 = uVar13 + 1;
        } while (uVar15 != uVar13);
        if (iVar5 == 0) {
          iVar11 = *(int *)(param_1 + 8);
        }
        else {
          iVar11 = *(int *)(param_1 + 8);
          if (*(int *)(param_1 + 0x264) < *(int *)(iVar11 + 0x3b0)) {
            *(int *)(param_1 + 0x264) = *(int *)(param_1 + 0x264) + 1;
            ((int (*)())FUN_0013b622)(*(int *)(param_1 + 0x3b4));
            piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x54);
            (**(code **)(*piVar2 + 0x14c))(piVar2,param_1);
            puVar10 = *(uint **)(param_1 + 0x420);
            if (*puVar10 != 0) {
              uVar13 = 0;
              uVar15 = *puVar10;
              puVar12 = puVar1;
              do {
                puVar10[2] = puVar12[2];
                uVar13 = uVar13 + 1;
                puVar12 = puVar12 + 1;
                puVar10 = puVar10 + 1;
              } while (uVar13 < uVar15);
            }
            puVar10 = *(uint **)(param_1 + 0x424);
            if (*puVar10 != 0) {
              uVar13 = 0;
              uVar15 = *puVar10;
              puVar12 = puVar9;
              do {
                puVar10[2] = puVar12[2];
                uVar13 = uVar13 + 1;
                puVar12 = puVar12 + 1;
                puVar10 = puVar10 + 1;
              } while (uVar13 < uVar15);
            }
            ((int (*)())FUN_00138996)(param_1);
            goto LAB_0013bfd0;
          }
        }
      }
      FUN_000e27ca(iVar11,4);
    }
LAB_0013bfd0:
    iVar11 = *(int *)(param_1 + 0x3b4);
    if (iVar11 != 0) {
      FUN_0013cd90(iVar11);
      FUN_001a7aba(*(undefined4 *)(iVar11 + -4),iVar11 + -4);
    }
    if (cVar4 == '\0') {
      *(undefined4 *)(param_1 + 0x34) = 6;
      return;
    }
    local_29 = '\x01';
  } while( true );
}

/* FUN_0013c128 @ 0x13c128 (14 bytes) */
int FUN_0013c128(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}

/* FUN_0013c136 @ 0x13c136 (11 bytes) */
int FUN_0013c136(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x14);
}

/* FUN_0013c142 @ 0x13c142 (133 bytes) */
int FUN_0013c142(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 8) == 0) {
    *param_3 = 0;
    *param_2 = 6;
    return;
  }
  *param_2 = 0;
  *param_3 = *(int *)(param_1 + 8);
  iVar2 = *param_2;
  iVar3 = iVar2 + 7;
  iVar1 = *(int *)(param_1 + 4);
  if (iVar3 < iVar1) {
    do {
      *param_2 = iVar3;
      *param_3 = *(int *)(*param_3 + 0x1c);
      iVar2 = *param_2;
      iVar1 = *(int *)(param_1 + 4);
      if (iVar1 <= iVar2 + 7) break;
      *param_2 = iVar2 + 7;
      *param_3 = *(int *)(*param_3 + 0x1c);
      iVar2 = *param_2;
      iVar3 = iVar2 + 7;
      iVar1 = *(int *)(param_1 + 4);
    } while (iVar3 < iVar1);
  }
  *param_2 = (iVar1 - iVar2) + -1;
  return;
}

/* FUN_0013c1c8 @ 0x13c1c8 (38 bytes) */
int FUN_0013c1c8(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = param_2;
  if (param_3 <= param_2) {
    iVar1 = param_3;
  }
  if (param_3 < param_2) {
    param_3 = param_2;
  }
  return iVar1 + (param_3 * (param_3 + -1)) / 2;
}

/* FUN_0013c1ee @ 0x13c1ee (61 bytes) */
int FUN_0013c1ee(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = ((int (*)())FUN_0013c1c8)(param_1,param_2,param_3);
  puVar1 = (uint *)(*param_1 + 8 + (uVar2 >> 5) * 4);
  *puVar1 = *puVar1 | 1 << ((byte)uVar2 & 0x1f);
  return;
}

/* FUN_0013c22c @ 0x13c22c (57 bytes) */
int FUN_0013c22c(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint uVar1;
  
  uVar1 = ((int (*)())FUN_0013c1c8)(param_1,param_2,param_3);
  return *(uint *)(*param_1 + 8 + (uVar1 >> 5) * 4) >> ((byte)uVar1 & 0x1f) & 1;
}

/* FUN_0013c266 @ 0x13c266 (38 bytes) */
int FUN_0013c266(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (param_3 == '\0') {
    return *(undefined4 *)(*(int *)(param_1 + 0x20) + param_2 * 4);
  }
  uVar1 = FUN_001a8f90();
  return uVar1;
}

/* FUN_0013c28c @ 0x13c28c (136 bytes) */
int FUN_0013c28c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar3 = 0;
  do {
    while (iVar1 = ((int (*)())FUN_0013c266)(param_3,*(undefined4 *)(iVar2 + iVar3 * 4),1), iVar1 == param_2) {
      *(undefined4 *)(iVar2 + iVar3 * 4) = *(undefined4 *)(iVar2 + *(int *)(param_1 + 4) * 4);
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
      iVar3 = iVar3 + 1;
      if (iVar3 == 7) {
        return;
      }
    }
    if ((*(int *)(param_1 + 4) % 7 == 0) && (*(int *)(iVar2 + 0x1c) != 0)) {
      iVar2 = *(int *)(iVar2 + 0x1c);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 7);
  return;
}

/* FUN_0013c314 @ 0x13c314 (30 bytes) */
int FUN_0013c314()
{
  FUN_001a8fcc();
  return;
}

/* FUN_0013c332 @ 0x13c332 (201 bytes) */
int FUN_0013c332(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_24;
  
  if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 4) < 1)) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    iVar2 = 0;
    iVar1 = *(int *)(param_1 + 8);
    while( true ) {
      local_24 = iVar1;
      if (*(int *)(param_3 + param_2 * 4) ==
          *(int *)(param_3 +
                  *(int *)(*(int *)(param_4 + 0x20) +
                          *(int *)(local_24 + iVar2 * 4 + (iVar2 / 7) * -0x1c) * 4) * 4)) {
        iVar3 = iVar3 + 1;
      }
      iVar2 = iVar2 + 1;
      if (*(int *)(param_1 + 4) == iVar2) break;
      iVar1 = local_24;
      if (((0 < iVar2) && (iVar2 % 7 == 0)) &&
         (iVar1 = *(int *)(local_24 + 0x1c), *(int *)(local_24 + 0x1c) == 0)) {
        iVar1 = local_24;
      }
    }
  }
  return iVar3;
}

/* FUN_0013c3fc @ 0x13c3fc (37 bytes) */
int FUN_0013c3fc(param_1)
  undefined4 *param_1;
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = (uint *)*param_1;
  if (*puVar2 != 0) {
    uVar3 = 0;
    uVar1 = *puVar2;
    do {
      puVar2[2] = 0;
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

/* FUN_0013c422 @ 0x13c422 (189 bytes) */
int FUN_0013c422(param_1, param_2)
  int param_1;
  int *param_2;
{
  char cVar1;
  int iVar2;
  
  if (param_2[0x26] != 0xc) {
    cVar1 = (**(code **)(*param_2 + 0x50))(param_2);
    if (cVar1 != '\0') {
      return 0;
    }
    iVar2 = FUN_0010b0f4(param_2,0);
    if (*(int *)(iVar2 + 0x10) == DAT_001cc534) {
      return 0;
    }
    if ((((param_2[0x26] != 0x37) && (param_2[0x20] != 0)) &&
        (cVar1 = FUN_0012dfd8(param_2[0x26]), cVar1 != '\0')) &&
       (((*(byte *)(param_2 + 5) & 2) == 0 &&
        (cVar1 = (**(code **)(*param_2 + 0x50))(param_2), cVar1 == '\0')))) {
      if ((*(byte *)(param_1 + 0x31) & 4) != 0) {
        return *(int *)(*(int *)(param_1 + 0x44c) + param_2[0x25] * 4);
      }
      if ((*(byte *)(param_2 + 5) & 0x40) == 0) {
        return *(int *)(*(int *)(param_1 + 0x44c) + param_2[0x25] * 4);
      }
    }
  }
  return param_2[0x25];
}

/* FUN_0013c4e0 @ 0x13c4e0 (9 bytes) */
int FUN_0013c4e0()
{
  ((int (*)())FUN_0013c422)();
  return;
}

/* FUN_0013c4ea @ 0x13c4ea (182 bytes) */
int FUN_0013c4ea(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int *param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  iVar3 = *param_2;
  *param_2 = iVar3 + 1;
  if (iVar3 + 1 == 7) {
    *param_2 = 0;
    iVar3 = *param_3;
    if (iVar3 != 0) {
      if (*(int *)(iVar3 + 0x1c) == 0) {
        uVar1 = *(undefined4 *)(param_4 + 0xbc);
        puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x24);
        *puVar2 = uVar1;
        *(undefined4 **)(iVar3 + 0x1c) = puVar2 + 1;
        *(undefined4 *)(*(int *)(*param_3 + 0x1c) + 0x1c) = 0;
        iVar3 = *param_3;
      }
      *param_3 = *(int *)(iVar3 + 0x1c);
      return;
    }
    uVar1 = *(undefined4 *)(param_4 + 0xbc);
    puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x24);
    *puVar2 = uVar1;
    *(undefined4 **)(param_1 + 8) = puVar2 + 1;
    puVar2[8] = 0;
    *param_3 = *(int *)(param_1 + 8);
  }
  return;
}

/* FUN_0013c5a0 @ 0x13c5a0 (57 bytes) */
int FUN_0013c5a0(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
  int *param_4;
  undefined4 param_5;
{
  ((int (*)())FUN_0013c4ea)(param_1,param_3,param_4,param_5);
  *(undefined4 *)(*param_4 + *param_3 * 4) = param_2;
  return;
}

/* FUN_0013c5da @ 0x13c5da (92 bytes) */
int FUN_0013c5da(param_1)
  int param_1;
{
  int iVar1;
  
  while (iVar1 = *(int *)(param_1 + 8), iVar1 != 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar1 + 0x1c);
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  return;
}

/* FUN_0013c636 @ 0x13c636 (92 bytes) */
int FUN_0013c636(param_1)
  int param_1;
{
  int iVar1;
  
  while (iVar1 = *(int *)(param_1 + 8), iVar1 != 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar1 + 0x1c);
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  return;
}

/* FUN_0013c692 @ 0x13c692 (149 bytes) */
int FUN_0013c692(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  *(int *)(*(int *)(param_4 + 0x20) + param_2 * 4) = param_2;
  uVar2 = *(undefined4 *)(param_5 + 0xbc);
  puVar1 = (undefined4 *)FUN_001a7bca(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[4] = uVar2;
  puVar1[2] = 0;
  puVar1[1] = 2;
  uVar2 = FUN_001a7bca(uVar2,8);
  puVar1[3] = uVar2;
  param_1[4] = (int)(puVar1 + 1);
  return;
}

/* FUN_0013c746 @ 0x13c746 (149 bytes) */
int FUN_0013c746(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  *(int *)(*(int *)(param_4 + 0x20) + param_2 * 4) = param_2;
  uVar2 = *(undefined4 *)(param_5 + 0xbc);
  puVar1 = (undefined4 *)FUN_001a7bca(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[4] = uVar2;
  puVar1[2] = 0;
  puVar1[1] = 2;
  uVar2 = FUN_001a7bca(uVar2,8);
  puVar1[3] = uVar2;
  param_1[4] = (int)(puVar1 + 1);
  return;
}

/* FUN_0013c7fa @ 0x13c7fa (153 bytes) */
int FUN_0013c7fa(param_1)
  int param_1;
{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  if (0 < *(int *)(param_1 + 0xc)) {
    uVar4 = 0;
    do {
      while (puVar1 = *(uint **)(param_1 + 4), uVar4 < *puVar1) {
        uVar3 = puVar1[1];
        if (uVar3 <= uVar4) {
          _memset((void *)(puVar1[2] + uVar3 * 4),0,(uVar4 - uVar3) * 4 + 4);
          puVar1[1] = uVar4 + 1;
        }
        uVar3 = uVar4 + 1;
        *(undefined4 *)(*(int *)(puVar1[2] + uVar4 * 4) + 4) = 0;
        uVar4 = uVar3;
        if (*(int *)(param_1 + 0xc) <= (int)uVar3) {
          return;
        }
      }
      piVar2 = (int *)FUN_001a7f7c(puVar1,uVar4);
      uVar4 = uVar4 + 1;
      *(undefined4 *)(*piVar2 + 4) = 0;
    } while ((int)uVar4 < *(int *)(param_1 + 0xc));
  }
  return;
}

