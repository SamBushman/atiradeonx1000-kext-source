#include "decls.h"

/* FUN_000ed8be @ 0xed8be (46 bytes) */
int FUN_000ed8be(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_000ec6de(param_1,param_2);
  *param_1 = &PTR_FUN_001fc468;
  return;
}

/* FUN_000ed8ec @ 0xed8ec (46 bytes) */
int FUN_000ed8ec(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  FUN_000ec6de(param_1,param_2);
  *param_1 = &PTR_FUN_001fc468;
  return;
}

/* FUN_000ed91a @ 0xed91a (68 bytes) */
int FUN_000ed91a(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x130);
  *puVar2 = uVar1;
  ((int (*)())FUN_000ed8ec)(puVar2 + 1,param_1);
  return puVar2 + 1;
}

/* FUN_000ed97c @ 0xed97c (64 bytes) */
int FUN_000ed97c(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  FUN_000ebb06(param_1,param_4);
  param_1[0x49] = param_2;
  param_1[0x4a] = param_3;
  *param_1 = &PTR_FUN_001fc408;
  return;
}

/* FUN_000ed9bc @ 0xed9bc (64 bytes) */
int FUN_000ed9bc(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  FUN_000ebb06(param_1,param_4);
  param_1[0x49] = param_2;
  param_1[0x4a] = param_3;
  *param_1 = &PTR_FUN_001fc408;
  return;
}

/* FUN_000ed9fc @ 0xed9fc (64 bytes) */
int FUN_000ed9fc(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  FUN_000ebb06(param_1,param_4);
  param_1[0x49] = param_2;
  param_1[0x4a] = param_3;
  *param_1 = &PTR_FUN_001fc468;
  return;
}

/* FUN_000eda3c @ 0xeda3c (64 bytes) */
int FUN_000eda3c(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  FUN_000ebb06(param_1,param_4);
  param_1[0x49] = param_2;
  param_1[0x4a] = param_3;
  *param_1 = &PTR_FUN_001fc468;
  return;
}

/* FUN_000eda7c @ 0xeda7c (49 bytes) */
int FUN_000eda7c(param_1)
  int param_1;
{
  FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0x13,0,0);
  return;
}

/* FUN_000edaae @ 0xedaae (7 bytes) */
int FUN_000edaae()
{
  return 0;
}

/* FUN_000edab6 @ 0xedab6 (38 bytes) */
int FUN_000edab6(param_1)
  int param_1;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  (**(code **)(*piVar1 + 100))(piVar1,param_1,*(int *)(param_1 + 8));
  return;
}

/* FUN_000edadc @ 0xedadc (63 bytes) */
int FUN_000edadc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 4) + 4 + param_2 * 8);
  if (iVar1 != -1) {
    return iVar1;
  }
  FUN_000e27ca(*(int *)(param_1 + 8),0xf);
  return -1;
}

/* FUN_000edb1c @ 0xedb1c (22 bytes) */
int FUN_000edb1c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(undefined4 *)(PTR_DAT_00213459 + param_2 * 4);
}

/* FUN_000edb32 @ 0xedb32 (22 bytes) */
int FUN_000edb32(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(undefined4 *)(PTR_DAT_00213461 + param_2 * 4);
}

/* FUN_000edb48 @ 0xedb48 (22 bytes) */
int FUN_000edb48(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(undefined4 *)(PTR_DAT_00213455 + param_2 * 4);
}

/* FUN_000edb5e @ 0xedb5e (22 bytes) */
int FUN_000edb5e(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(undefined4 *)(PTR_DAT_00213465 + param_2 * 4);
}

/* FUN_000edb74 @ 0xedb74 (139 bytes) */
int FUN_000edb74(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x388) != 0) {
    FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(int *)(param_1 + 0x388));
    *(undefined4 *)(param_1 + 0x388) = 0;
  }
  if (*(int *)(param_1 + 0x38c) != 0) {
    FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(int *)(param_1 + 0x38c));
    *(undefined4 *)(param_1 + 0x38c) = 0;
  }
  if (*(int *)(param_1 + 0x390) != 0) {
    FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(int *)(param_1 + 0x390));
    *(undefined4 *)(param_1 + 0x390) = 0;
  }
  return;
}

/* FUN_000edc00 @ 0xedc00 (49 bytes) */
int FUN_000edc00(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_001a7cb8(param_3,param_2);
  *(undefined4 *)(param_3 + 0xac) = param_1;
  ((int (*)())FUN_000edb74)();
  return;
}

/* FUN_000edc32 @ 0xedc32 (49 bytes) */
int FUN_000edc32(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_001a7cee(param_3,param_2);
  *(undefined4 *)(param_3 + 0xac) = param_1;
  ((int (*)())FUN_000edb74)();
  return;
}

/* FUN_000edc64 @ 0xedc64 (60 bytes) */
int FUN_000edc64(param_1, param_2)
  int param_1;
  int param_2;
{
  FUN_001a7d0c(param_1 + 0x370,param_2);
  ((int (*)())FUN_000edb74)(param_1);
  *(int *)(param_2 + 0xac) = param_1;
  ((int (*)())FUN_000edb74)();
  return;
}

/* FUN_000edca0 @ 0xedca0 (52 bytes) */
int FUN_000edca0(param_1, param_2)
  int param_1;
  int param_2;
{
  FUN_001a7cd6(param_1 + 0x370,param_2);
  *(int *)(param_2 + 0xac) = param_1;
  ((int (*)())FUN_000edb74)();
  return;
}

/* FUN_000edcd4 @ 0xedcd4 (127 bytes) */
int FUN_000edcd4(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  undefined4 uVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x388) != 0) {
    FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(int *)(param_1 + 0x388));
  }
  uVar1 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),param_3 * 4 + 4);
  *(undefined4 *)(param_1 + 0x388) = uVar1;
  uVar2 = 0;
  do {
    *(undefined4 *)(uVar2 * 4 + *(int *)(param_1 + 0x388)) = *(undefined4 *)(uVar2 * 4 + param_2);
    uVar2 = uVar2 + 1;
  } while (uVar2 <= param_3);
  return;
}

/* FUN_000edd54 @ 0xedd54 (170 bytes) */
int FUN_000edd54(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0x388) == 0) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
    puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x2c);
    *puVar2 = uVar1;
    puVar3 = puVar2 + 1;
    FUN_000fa45c(puVar3,param_1);
    FUN_000fa96e(puVar3,*(undefined4 *)(param_1 + 0x394));
    ((int (*)())FUN_000edcd4)(param_1,puVar2[7],puVar2[8]);
    FUN_000fa822(puVar3);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_001a7aba(*puVar2,puVar2);
      return *(undefined4 *)(param_1 + 0x388);
    }
  }
  return *(undefined4 *)(param_1 + 0x388);
}

/* FUN_000ede1c @ 0xede1c (144 bytes) */
int FUN_000ede1c(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x38c) == 0) {
    iVar1 = FUN_001a7d8a(param_1 + 0x370);
    uVar2 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),iVar1 * 4 + 4);
    *(undefined4 *)(param_1 + 0x38c) = uVar2;
    puVar3 = (undefined4 *)((int (*)())FUN_000edd54)(param_1);
    **(undefined4 **)(param_1 + 0x38c) = *puVar3;
    if (0 < iVar1) {
      puVar3 = puVar3 + iVar1;
      iVar4 = 1;
      do {
        *(undefined4 *)(*(int *)(param_1 + 0x38c) + iVar4 * 4) = *puVar3;
        iVar4 = iVar4 + 1;
        puVar3 = puVar3 + -1;
      } while (iVar4 <= iVar1);
    }
  }
  return *(undefined4 *)(param_1 + 0x38c);
}

/* FUN_000edeac @ 0xedeac (72 bytes) */
int FUN_000edeac(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x378);
  if (*(int *)(iVar2 + 8) != 0) {
    iVar3 = 0;
    do {
      iVar1 = FUN_001a7d8a(iVar2 + 0x90);
      iVar3 = iVar3 + iVar1;
      iVar2 = *(int *)(iVar2 + 8);
    } while (*(int *)(iVar2 + 8) != 0);
    return iVar3;
  }
  return 0;
}

/* FUN_000edef4 @ 0xedef4 (78 bytes) */
int FUN_000edef4(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x378);
  iVar2 = *(int *)(iVar1 + 8);
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = FUN_000e97bc(iVar1);
    if ((1 < iVar2) || (iVar2 = FUN_000e97aa(iVar1), 1 < iVar2)) break;
    iVar1 = *(int *)(iVar1 + 8);
    iVar2 = *(int *)(iVar1 + 8);
  }
  return 1;
}

/* FUN_000edf42 @ 0xedf42 (524 bytes) */
int FUN_000edf42(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_20;
  int local_18;
  int local_10;
  
  iVar1 = *(int *)(param_1 + 0x378);
  iVar2 = *(int *)(iVar1 + 8);
  do {
    if (iVar2 == 0) {
      return;
    }
    iVar2 = *(int *)(iVar1 + 0x98);
    iVar3 = *(int *)(iVar2 + 8);
    while (iVar3 != 0) {
      if (((*(byte *)(iVar2 + 0x14) & 1) != 0) && (iVar3 = *(int *)(iVar2 + 0x84), 0 < iVar3)) {
        iVar8 = 0;
        iVar9 = 0;
        local_20 = 0;
        iVar7 = iVar2;
        do {
          while( true ) {
            iVar8 = iVar8 + 1;
            if (*(int *)(iVar7 + 0xb0) - 2U < 3) break;
            if (*(int *)(iVar7 + 0xb0) == 0xc) {
              iVar9 = iVar9 + 1;
            }
            iVar7 = iVar7 + 0x18;
            if (iVar3 == iVar8) goto LAB_000edfd3;
          }
          local_20 = local_20 + 1;
          iVar7 = iVar7 + 0x18;
        } while (iVar3 != iVar8);
LAB_000edfd3:
        if ((local_20 != 0) && (iVar9 != 0)) {
          local_18 = 0;
          local_10 = iVar2;
          do {
            while( true ) {
              local_18 = local_18 + 1;
              if (((2 < *(int *)(local_10 + 0xb0) - 2U) || (iVar9 < local_20)) &&
                 ((*(int *)(local_10 + 0xb0) != 0xc || (iVar9 >= local_20)))) break;
              uVar5 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
              uVar4 = *(undefined4 *)(local_10 + 0xa4);
              iVar7 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
              *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar7;
              uVar6 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar7,0);
              FUN_0010a3c2(uVar5,0,uVar6);
              FUN_0010a3c2(uVar5,1,uVar4);
              FUN_0012a8f4(uVar4,iVar2,uVar5);
              FUN_0010a3c2(iVar2,local_18,uVar6);
              FUN_000e956e(*(undefined4 *)(iVar2 + 0x158),iVar2,uVar5);
              local_10 = local_10 + 0x18;
              if (iVar3 == local_18) goto LAB_000ee110;
            }
            local_10 = local_10 + 0x18;
          } while (iVar3 != local_18);
        }
      }
LAB_000ee110:
      iVar2 = *(int *)(iVar2 + 8);
      iVar3 = *(int *)(iVar2 + 8);
    }
    iVar1 = *(int *)(iVar1 + 8);
    iVar2 = *(int *)(iVar1 + 8);
  } while( true );
}

/* FUN_000ee14e @ 0xee14e (34 bytes) */
int FUN_000ee14e(param_1)
  int param_1;
{
  FUN_0012ea1a(*(undefined4 *)(param_1 + 0x3a0));
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x10;
  return;
}

/* FUN_000ee170 @ 0xee170 (188 bytes) */
int FUN_000ee170(param_1)
  int param_1;
{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  
  iVar3 = ((int (*)())FUN_000ede1c)(param_1);
  do {
    bVar9 = false;
    iVar8 = 1;
    iVar4 = FUN_001a7d8a(param_1 + 0x370);
    if (0 < iVar4) {
      do {
        piVar1 = *(int **)(iVar3 + iVar8 * 4);
        cVar2 = (**(code **)(*piVar1 + 0x20))(piVar1);
        if (cVar2 == '\0') {
          iVar4 = piVar1[3];
          uVar7 = 1;
          iVar6 = 0;
          iVar5 = piVar1[0x34];
          if (*(int *)(iVar5 + 4) != 0) {
            do {
              iVar5 = *(int *)(*(int *)(iVar5 + 8) + iVar6);
              if (iVar5 != 0) {
                piVar1[3] = piVar1[3] | *(uint *)(iVar5 + 0xc) & 3;
              }
              uVar7 = uVar7 + 1;
              iVar6 = iVar6 + 4;
              iVar5 = piVar1[0x34];
            } while (uVar7 <= *(uint *)(iVar5 + 4));
          }
          bVar9 = iVar4 != piVar1[3];
        }
        iVar8 = iVar8 + 1;
        iVar4 = FUN_001a7d8a(param_1 + 0x370);
      } while (iVar8 <= iVar4);
    }
  } while (bVar9);
  return;
}

/* FUN_000ee22c @ 0xee22c (93 bytes) */
int FUN_000ee22c(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  char cVar1;
  byte bVar2;
  
  cVar1 = (**(code **)(*param_2 + 0x40))(param_2);
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*param_2 + 0x28))(param_2);
    if (cVar1 == '\0') {
      cVar1 = (**(code **)(*param_2 + 0x60))(param_2);
      if (cVar1 == '\0') {
        cVar1 = (**(code **)(*param_2 + 0x5c))(param_2);
        if ((cVar1 == '\0') && (*(int *)(param_2[0x22] + 8) != 0x84)) {
          bVar2 = 0;
          goto LAB_000ee247;
        }
      }
    }
  }
  bVar2 = 1;
LAB_000ee247:
  return bVar2 ^ 1;
}

/* FUN_000ee28a @ 0xee28a (93 bytes) */
int FUN_000ee28a(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  char cVar1;
  byte bVar2;
  
  cVar1 = (**(code **)(*param_2 + 0x40))(param_2);
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*param_2 + 0x28))(param_2);
    if (cVar1 == '\0') {
      cVar1 = (**(code **)(*param_2 + 0x60))(param_2);
      if (cVar1 == '\0') {
        cVar1 = (**(code **)(*param_2 + 0x5c))(param_2);
        if ((cVar1 == '\0') && (*(int *)(param_2[0x22] + 8) != 0x84)) {
          bVar2 = 0;
          goto LAB_000ee2a5;
        }
      }
    }
  }
  bVar2 = 1;
LAB_000ee2a5:
  return bVar2 ^ 1;
}

/* FUN_000ee2e8 @ 0xee2e8 (108 bytes) */
int FUN_000ee2e8(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  char cVar2;
  
  cVar2 = FUN_001195a6(param_2,param_1);
  if (cVar2 == '\0') {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x88) + 8);
    cVar2 = FUN_0011902c(uVar1,param_2);
    if ((cVar2 != '\0') && (cVar2 = FUN_0011913a(uVar1,param_2), cVar2 == '\0')) {
      return 1;
    }
    cVar2 = FUN_00119104(uVar1,param_2);
    if (cVar2 == '\0') {
      return 0;
    }
  }
  return 1;
}

/* FUN_000ee354 @ 0xee354 (213 bytes) */
int FUN_000ee354(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x60))(param_1);
  if (cVar1 != '\0') {
    cVar1 = FUN_0010a62e(param_1,*(undefined4 *)(param_3 + 0x3f4));
    if (cVar1 == '\0') {
      return 0;
    }
    cVar1 = FUN_0011169e(param_1,param_3);
    if (cVar1 == '\0') {
      return 0;
    }
    param_1 = (int *)FUN_0010b180(param_1,1);
  }
  cVar1 = FUN_0010a62e(param_1,*(undefined4 *)(param_3 + 0x3f4));
  if (((cVar1 != '\0') &&
      (cVar1 = (**(code **)(**(int **)(param_3 + 0x54) + 0x44))(*(int **)(param_3 + 0x54),param_1),
      cVar1 != '\0')) && ((*(byte *)(param_1[0x56] + 0xc) & 8) != 0)) {
    cVar1 = FUN_000f56f0(param_2,DAT_001c64f8);
    if (cVar1 != '\0') {
      return 1;
    }
    cVar1 = ((int (*)())FUN_000ee2e8)(param_1,param_3);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}

/* FUN_000ee42a @ 0xee42a (381 bytes) */
int FUN_000ee42a(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int *param_2;
  int *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)FUN_0010dbb8(0x31,*(undefined4 *)(param_1 + 8));
  FUN_0010ba02(piVar2,1,param_2,0,*(undefined4 *)(param_1 + 8));
  FUN_0010a38c(piVar2,param_1,param_4,param_5);
  (**(code **)(*piVar2 + 0x94))(piVar2,param_3,*(undefined4 *)(param_1 + 8));
  iVar3 = FUN_000f5aec(param_6);
  piVar2[0x27] = iVar3;
  iVar3 = FUN_0010b0f4(piVar2,1);
  *(undefined4 *)(iVar3 + 0x10) = param_6;
  iVar3 = param_2[0x56];
  if (iVar3 == param_3[0x56]) {
    piVar2 = *(int **)(iVar3 + 0x98);
    iVar3 = piVar2[2];
    while (iVar3 != 0) {
      if ((*(byte *)(piVar2 + 5) & 1) != 0) {
        if (piVar2 == param_3) break;
        if (piVar2 == param_2) goto LAB_000ee50f;
      }
      piVar2 = (int *)piVar2[2];
      iVar3 = piVar2[2];
    }
  }
  else if ((*(byte *)(iVar3 + 0xc) & 8) == 0) goto LAB_000ee50f;
  param_3 = param_2;
LAB_000ee50f:
  cVar1 = (**(code **)(*(int *)param_3[0x56] + 0x2c))((int *)param_3[0x56]);
  if (cVar1 != '\0') {
    FUN_000e9540();
    return;
  }
  iVar3 = (**(code **)(*param_3 + 0x7c))(param_3);
  if (iVar3 != 0) {
    FUN_000e9f7c();
    return;
  }
  FUN_000e9596();
  return;
}

/* FUN_000ee5a8 @ 0xee5a8 (180 bytes) */
int FUN_000ee5a8(param_1)
  int param_1;
{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar2,0x168);
  *puVar5 = uVar2;
  FUN_0010ac30(puVar5 + 1,0x93,*(undefined4 *)(param_1 + 8));
  *(undefined4 **)(param_1 + 0x33c) = puVar5 + 1;
  puVar5[0x26] = 0;
  puVar5[0x27] = 0x2d;
  *(undefined4 *)(*(int *)(param_1 + 0x33c) + 300) = 0;
  puVar1 = (uint *)(*(int *)(param_1 + 0x394) + 0xc);
  *puVar1 = *puVar1 | 8;
  FUN_000e9540(*(undefined4 *)(param_1 + 0x394),*(undefined4 *)(param_1 + 0x33c));
  iVar3 = *(int *)(param_1 + 0x378);
  iVar4 = *(int *)(iVar3 + 8);
  while (iVar4 != 0) {
    *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | 8;
    iVar3 = *(int *)(iVar3 + 8);
    iVar4 = *(int *)(iVar3 + 8);
  }
  return;
}

/* FUN_000ee67a @ 0xee67a (462 bytes) */
int FUN_000ee67a(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x424);
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x420);
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3bc);
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3b8);
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3a0);
  if (iVar1 != 0) {
    FUN_0012ea60(iVar1);
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(undefined4 *)(param_1 + 0x454));
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(undefined4 *)(param_1 + 0x450));
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(undefined4 *)(param_1 + 0x44c));
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(undefined4 *)(param_1 + 0x388));
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(undefined4 *)(param_1 + 0x38c));
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(undefined4 *)(param_1 + 0x390));
  FUN_001a7d34((undefined4 *)(param_1 + 0x370));
  *(undefined **)(param_1 + 0x37c) = PTR_DAT_00213441 + 8;
  *(undefined4 *)(param_1 + 0x370) = PTR_DAT_00213441 + 8;
  return;
}

/* FUN_000ee86e @ 0xee86e (462 bytes) */
int FUN_000ee86e(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x424);
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x420);
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3bc);
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3b8);
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3a0);
  if (iVar1 != 0) {
    FUN_0012ea60(iVar1);
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(undefined4 *)(param_1 + 0x454));
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(undefined4 *)(param_1 + 0x450));
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(undefined4 *)(param_1 + 0x44c));
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(undefined4 *)(param_1 + 0x388));
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(undefined4 *)(param_1 + 0x38c));
  FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),*(undefined4 *)(param_1 + 0x390));
  FUN_001a7d34((undefined4 *)(param_1 + 0x370));
  *(undefined **)(param_1 + 0x37c) = PTR_DAT_00213441 + 8;
  *(undefined4 *)(param_1 + 0x370) = PTR_DAT_00213441 + 8;
  return;
}

/* FUN_000eea62 @ 0xeea62 (2230 bytes) */
int FUN_000eea62(param_1, param_2)
  undefined1 *param_1;
  undefined4 param_2;
{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  *param_1 = 0;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x80) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x16c) = 0;
  *(undefined4 *)(param_1 + 0x170) = 0;
  *(undefined4 *)(param_1 + 0x174) = 0;
  *(undefined4 *)(param_1 + 0x178) = 0;
  *(undefined4 *)(param_1 + 0x17c) = 0;
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined4 *)(param_1 + 0x184) = 0;
  *(undefined4 *)(param_1 + 0x188) = 0;
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(undefined4 *)(param_1 + 400) = 0;
  *(undefined4 *)(param_1 + 0x194) = 0;
  *(undefined4 *)(param_1 + 0x198) = 0;
  *(undefined4 *)(param_1 + 0x19c) = 0;
  *(undefined4 *)(param_1 + 0x1a0) = 0;
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined4 *)(param_1 + 0x1ac) = 0;
  *(undefined4 *)(param_1 + 0x1b0) = 0;
  *(undefined4 *)(param_1 + 0x1b4) = 0;
  *(undefined4 *)(param_1 + 0x1b8) = 0;
  *(undefined4 *)(param_1 + 0x1bc) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined4 *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x1cc) = 0;
  *(undefined4 *)(param_1 + 0x1d0) = 0;
  *(undefined4 *)(param_1 + 0x1d4) = 0;
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  *(undefined4 *)(param_1 + 0x1dc) = 0;
  *(undefined4 *)(param_1 + 0x1e0) = 0;
  *(undefined4 *)(param_1 + 0x1e4) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 500) = 0;
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  *(undefined4 *)(param_1 + 0x1fc) = 0;
  *(undefined4 *)(param_1 + 0x200) = 0;
  *(undefined4 *)(param_1 + 0x204) = 0;
  *(undefined4 *)(param_1 + 0x208) = 0;
  *(undefined4 *)(param_1 + 0x20c) = 0;
  *(undefined4 *)(param_1 + 0x210) = 0;
  *(undefined4 *)(param_1 + 0x214) = 0;
  *(undefined4 *)(param_1 + 0x218) = 0;
  *(undefined4 *)(param_1 + 0x21c) = 0;
  *(undefined4 *)(param_1 + 0x220) = 0;
  *(undefined4 *)(param_1 + 0x224) = 0;
  *(undefined4 *)(param_1 + 0x228) = 0;
  *(undefined4 *)(param_1 + 0x22c) = 0;
  *(undefined4 *)(param_1 + 0x230) = 0;
  *(undefined4 *)(param_1 + 0x234) = 0;
  *(undefined4 *)(param_1 + 0x238) = 0;
  *(undefined4 *)(param_1 + 0x23c) = 0;
  *(undefined4 *)(param_1 + 0x240) = 0;
  *(undefined4 *)(param_1 + 0x244) = 0;
  *(undefined4 *)(param_1 + 0x248) = 0;
  *(undefined4 *)(param_1 + 0x24c) = 0;
  *(undefined4 *)(param_1 + 0x250) = 0;
  *(undefined4 *)(param_1 + 0x254) = 0;
  *(undefined4 *)(param_1 + 600) = 0;
  *(undefined4 *)(param_1 + 0x25c) = 0;
  *(undefined4 *)(param_1 + 0x260) = 0;
  *(undefined4 *)(param_1 + 0x264) = 0;
  *(undefined4 *)(param_1 + 0x268) = 0;
  *(undefined4 *)(param_1 + 0x26c) = 0;
  *(undefined4 *)(param_1 + 0x270) = 0;
  *(undefined4 *)(param_1 + 0x274) = 0;
  *(undefined4 *)(param_1 + 0x278) = 0;
  *(undefined4 *)(param_1 + 0x27c) = 0;
  *(undefined4 *)(param_1 + 0x280) = 0;
  *(undefined4 *)(param_1 + 0x284) = 0;
  *(undefined4 *)(param_1 + 0x288) = 0;
  *(undefined4 *)(param_1 + 0x28c) = 0;
  *(undefined4 *)(param_1 + 0x290) = 0;
  *(undefined4 *)(param_1 + 0x294) = 0;
  *(undefined4 *)(param_1 + 0x298) = 0;
  *(undefined4 *)(param_1 + 0x29c) = 0;
  *(undefined4 *)(param_1 + 0x2a0) = 0;
  *(undefined4 *)(param_1 + 0x2a4) = 0;
  *(undefined4 *)(param_1 + 0x2a8) = 0;
  *(undefined4 *)(param_1 + 0x2ac) = 0;
  *(undefined4 *)(param_1 + 0x330) = 0;
  *(undefined4 *)(param_1 + 0x338) = 0;
  *(undefined4 *)(param_1 + 0x33c) = 0;
  *(undefined4 *)(param_1 + 0x344) = 0;
  *(undefined4 *)(param_1 + 0x348) = 0;
  *(undefined4 *)(param_1 + 0x34c) = 0;
  *(undefined4 *)(param_1 + 0x350) = 0;
  *(undefined4 *)(param_1 + 0x358) = 0;
  *(undefined4 *)(param_1 + 0x35c) = 0;
  param_1[0x360] = 0;
  param_1[0x361] = 0;
  param_1[0x362] = 0;
  *(undefined4 *)(param_1 + 0x368) = 0;
  FUN_001a7e06(param_1 + 0x370);
  *(undefined4 *)(param_1 + 0x388) = 0;
  *(undefined4 *)(param_1 + 0x38c) = 0;
  *(undefined4 *)(param_1 + 0x390) = 0;
  *(undefined4 *)(param_1 + 0x398) = 0;
  param_1[0x3a8] = 0;
  *(undefined4 *)(param_1 + 0x3b4) = 0;
  *(undefined4 *)(param_1 + 0x3c0) = 0;
  param_1[0x3c8] = 0;
  *(undefined4 *)(param_1 + 0x3cc) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3d0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x3d4) = 0;
  param_1[0x3d8] = 0;
  *(undefined4 *)(param_1 + 0x3dc) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3e0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x3e4) = 0;
  *(undefined4 *)(param_1 + 0x3ec) = 1;
  *(undefined4 *)(param_1 + 0x41c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x468) = 0;
  *(undefined4 *)(param_1 + 0x46c) = 0;
  param_1[0x470] = 0;
  iVar5 = 0;
  puVar1 = param_1;
  do {
    *(undefined4 *)(puVar1 + 0x38) = 0;
    iVar5 = iVar5 + 1;
    puVar1 = puVar1 + 4;
  } while (iVar5 != 0x10);
  iVar5 = 0;
  puVar1 = param_1;
  do {
    *(undefined4 *)(puVar1 + 0x2b0) = 0;
    iVar5 = iVar5 + 1;
    puVar1 = puVar1 + 4;
  } while (iVar5 != 0x20);
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar4,0x6c);
  *puVar2 = uVar4;
  FUN_0012e8fc(puVar2 + 1,*(undefined4 *)(param_1 + 8));
  *(undefined4 **)(param_1 + 0x3a0) = puVar2 + 1;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x20c);
  *puVar3 = uVar4;
  puVar3[2] = 0x1000;
  puVar3[1] = 0x80;
  uVar6 = 0;
  puVar2 = puVar3 + 1;
  do {
    puVar2[2] = 0;
    uVar6 = uVar6 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar6 < 0x80);
  *(undefined4 **)(param_1 + 0x3a4) = puVar3 + 1;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x8c);
  *puVar3 = uVar4;
  puVar3[2] = 0x400;
  puVar3[1] = 0x20;
  uVar6 = 0;
  puVar2 = puVar3 + 1;
  do {
    puVar2[2] = 0;
    uVar6 = uVar6 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar6 < 0x20);
  *(undefined4 **)(param_1 + 0x3b0) = puVar3 + 1;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
  *puVar2 = uVar4;
  puVar2[4] = uVar4;
  puVar2[2] = 0;
  puVar2[1] = 2;
  uVar4 = FUN_001a7bca(uVar4,8);
  puVar2[3] = uVar4;
  *(undefined4 **)(param_1 + 0x3b8) = puVar2 + 1;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
  *puVar2 = uVar4;
  puVar2[4] = uVar4;
  puVar2[2] = 0;
  puVar2[1] = 2;
  uVar4 = FUN_001a7bca(uVar4,8);
  puVar2[3] = uVar4;
  *(undefined4 **)(param_1 + 0x3bc) = puVar2 + 1;
  iVar5 = 4;
  puVar1 = param_1;
  do {
    *(undefined4 *)(puVar1 + 0x10) = 0;
    *(undefined4 *)(puVar1 + 0x20) = 0;
    puVar1 = puVar1 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(undefined4 *)(param_1 + 0x36c) = 0;
  return;
}

/* FUN_000ef382 @ 0xef382 (2230 bytes) */
int FUN_000ef382(param_1, param_2)
  undefined1 *param_1;
  undefined4 param_2;
{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  *param_1 = 0;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x80) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x16c) = 0;
  *(undefined4 *)(param_1 + 0x170) = 0;
  *(undefined4 *)(param_1 + 0x174) = 0;
  *(undefined4 *)(param_1 + 0x178) = 0;
  *(undefined4 *)(param_1 + 0x17c) = 0;
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined4 *)(param_1 + 0x184) = 0;
  *(undefined4 *)(param_1 + 0x188) = 0;
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(undefined4 *)(param_1 + 400) = 0;
  *(undefined4 *)(param_1 + 0x194) = 0;
  *(undefined4 *)(param_1 + 0x198) = 0;
  *(undefined4 *)(param_1 + 0x19c) = 0;
  *(undefined4 *)(param_1 + 0x1a0) = 0;
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined4 *)(param_1 + 0x1ac) = 0;
  *(undefined4 *)(param_1 + 0x1b0) = 0;
  *(undefined4 *)(param_1 + 0x1b4) = 0;
  *(undefined4 *)(param_1 + 0x1b8) = 0;
  *(undefined4 *)(param_1 + 0x1bc) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined4 *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x1cc) = 0;
  *(undefined4 *)(param_1 + 0x1d0) = 0;
  *(undefined4 *)(param_1 + 0x1d4) = 0;
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  *(undefined4 *)(param_1 + 0x1dc) = 0;
  *(undefined4 *)(param_1 + 0x1e0) = 0;
  *(undefined4 *)(param_1 + 0x1e4) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 500) = 0;
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  *(undefined4 *)(param_1 + 0x1fc) = 0;
  *(undefined4 *)(param_1 + 0x200) = 0;
  *(undefined4 *)(param_1 + 0x204) = 0;
  *(undefined4 *)(param_1 + 0x208) = 0;
  *(undefined4 *)(param_1 + 0x20c) = 0;
  *(undefined4 *)(param_1 + 0x210) = 0;
  *(undefined4 *)(param_1 + 0x214) = 0;
  *(undefined4 *)(param_1 + 0x218) = 0;
  *(undefined4 *)(param_1 + 0x21c) = 0;
  *(undefined4 *)(param_1 + 0x220) = 0;
  *(undefined4 *)(param_1 + 0x224) = 0;
  *(undefined4 *)(param_1 + 0x228) = 0;
  *(undefined4 *)(param_1 + 0x22c) = 0;
  *(undefined4 *)(param_1 + 0x230) = 0;
  *(undefined4 *)(param_1 + 0x234) = 0;
  *(undefined4 *)(param_1 + 0x238) = 0;
  *(undefined4 *)(param_1 + 0x23c) = 0;
  *(undefined4 *)(param_1 + 0x240) = 0;
  *(undefined4 *)(param_1 + 0x244) = 0;
  *(undefined4 *)(param_1 + 0x248) = 0;
  *(undefined4 *)(param_1 + 0x24c) = 0;
  *(undefined4 *)(param_1 + 0x250) = 0;
  *(undefined4 *)(param_1 + 0x254) = 0;
  *(undefined4 *)(param_1 + 600) = 0;
  *(undefined4 *)(param_1 + 0x25c) = 0;
  *(undefined4 *)(param_1 + 0x260) = 0;
  *(undefined4 *)(param_1 + 0x264) = 0;
  *(undefined4 *)(param_1 + 0x268) = 0;
  *(undefined4 *)(param_1 + 0x26c) = 0;
  *(undefined4 *)(param_1 + 0x270) = 0;
  *(undefined4 *)(param_1 + 0x274) = 0;
  *(undefined4 *)(param_1 + 0x278) = 0;
  *(undefined4 *)(param_1 + 0x27c) = 0;
  *(undefined4 *)(param_1 + 0x280) = 0;
  *(undefined4 *)(param_1 + 0x284) = 0;
  *(undefined4 *)(param_1 + 0x288) = 0;
  *(undefined4 *)(param_1 + 0x28c) = 0;
  *(undefined4 *)(param_1 + 0x290) = 0;
  *(undefined4 *)(param_1 + 0x294) = 0;
  *(undefined4 *)(param_1 + 0x298) = 0;
  *(undefined4 *)(param_1 + 0x29c) = 0;
  *(undefined4 *)(param_1 + 0x2a0) = 0;
  *(undefined4 *)(param_1 + 0x2a4) = 0;
  *(undefined4 *)(param_1 + 0x2a8) = 0;
  *(undefined4 *)(param_1 + 0x2ac) = 0;
  *(undefined4 *)(param_1 + 0x330) = 0;
  *(undefined4 *)(param_1 + 0x338) = 0;
  *(undefined4 *)(param_1 + 0x33c) = 0;
  *(undefined4 *)(param_1 + 0x344) = 0;
  *(undefined4 *)(param_1 + 0x348) = 0;
  *(undefined4 *)(param_1 + 0x34c) = 0;
  *(undefined4 *)(param_1 + 0x350) = 0;
  *(undefined4 *)(param_1 + 0x358) = 0;
  *(undefined4 *)(param_1 + 0x35c) = 0;
  param_1[0x360] = 0;
  param_1[0x361] = 0;
  param_1[0x362] = 0;
  *(undefined4 *)(param_1 + 0x368) = 0;
  FUN_001a7e06(param_1 + 0x370);
  *(undefined4 *)(param_1 + 0x388) = 0;
  *(undefined4 *)(param_1 + 0x38c) = 0;
  *(undefined4 *)(param_1 + 0x390) = 0;
  *(undefined4 *)(param_1 + 0x398) = 0;
  param_1[0x3a8] = 0;
  *(undefined4 *)(param_1 + 0x3b4) = 0;
  *(undefined4 *)(param_1 + 0x3c0) = 0;
  param_1[0x3c8] = 0;
  *(undefined4 *)(param_1 + 0x3cc) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3d0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x3d4) = 0;
  param_1[0x3d8] = 0;
  *(undefined4 *)(param_1 + 0x3dc) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3e0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x3e4) = 0;
  *(undefined4 *)(param_1 + 0x3ec) = 1;
  *(undefined4 *)(param_1 + 0x41c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x468) = 0;
  *(undefined4 *)(param_1 + 0x46c) = 0;
  param_1[0x470] = 0;
  iVar5 = 0;
  puVar1 = param_1;
  do {
    *(undefined4 *)(puVar1 + 0x38) = 0;
    iVar5 = iVar5 + 1;
    puVar1 = puVar1 + 4;
  } while (iVar5 != 0x10);
  iVar5 = 0;
  puVar1 = param_1;
  do {
    *(undefined4 *)(puVar1 + 0x2b0) = 0;
    iVar5 = iVar5 + 1;
    puVar1 = puVar1 + 4;
  } while (iVar5 != 0x20);
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar4,0x6c);
  *puVar2 = uVar4;
  FUN_0012e8fc(puVar2 + 1,*(undefined4 *)(param_1 + 8));
  *(undefined4 **)(param_1 + 0x3a0) = puVar2 + 1;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x20c);
  *puVar3 = uVar4;
  puVar3[2] = 0x1000;
  puVar3[1] = 0x80;
  uVar6 = 0;
  puVar2 = puVar3 + 1;
  do {
    puVar2[2] = 0;
    uVar6 = uVar6 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar6 < 0x80);
  *(undefined4 **)(param_1 + 0x3a4) = puVar3 + 1;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x8c);
  *puVar3 = uVar4;
  puVar3[2] = 0x400;
  puVar3[1] = 0x20;
  uVar6 = 0;
  puVar2 = puVar3 + 1;
  do {
    puVar2[2] = 0;
    uVar6 = uVar6 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar6 < 0x20);
  *(undefined4 **)(param_1 + 0x3b0) = puVar3 + 1;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
  *puVar2 = uVar4;
  puVar2[4] = uVar4;
  puVar2[2] = 0;
  puVar2[1] = 2;
  uVar4 = FUN_001a7bca(uVar4,8);
  puVar2[3] = uVar4;
  *(undefined4 **)(param_1 + 0x3b8) = puVar2 + 1;
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
  *puVar2 = uVar4;
  puVar2[4] = uVar4;
  puVar2[2] = 0;
  puVar2[1] = 2;
  uVar4 = FUN_001a7bca(uVar4,8);
  puVar2[3] = uVar4;
  *(undefined4 **)(param_1 + 0x3bc) = puVar2 + 1;
  iVar5 = 4;
  puVar1 = param_1;
  do {
    *(undefined4 *)(puVar1 + 0x10) = 0;
    *(undefined4 *)(puVar1 + 0x20) = 0;
    puVar1 = puVar1 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(undefined4 *)(param_1 + 0x36c) = 0;
  return;
}

/* FUN_000efca2 @ 0xefca2 (276 bytes) */
int FUN_000efca2(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  char cStack_25;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  if (param_2 == 0) {
    FUN_000e27ca(param_4,0xf);
  }
  iVar1 = FUN_0010b0f4(param_2,0);
  if (*(int *)(iVar1 + 0x10) != DAT_001c64f4) {
    iVar1 = FUN_0010a17a(0x31,param_4);
    FUN_000fa0d2(iVar1,*(undefined4 *)(param_4 + 0x3f4),1,0,0,0,0x3f800000);
    FUN_0010a3c2(iVar1,0,*(undefined4 *)(param_2 + 0xa4));
    iVar2 = FUN_0010b0f4(param_2,0);
    local_24 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = 1;
    do {
      *(bool *)((int)local_20 + iVar2 + -1) = (&cStack_25)[iVar2] != '\x01';
      iVar2 = iVar2 + 1;
    } while (iVar2 != 5);
    *(undefined4 *)(iVar1 + 0x9c) = local_20[0];
    FUN_000e9540(*(undefined4 *)(param_2 + 0x158),iVar1);
    *(int *)(param_2 + 0x9c) = DAT_001c64f4;
  }
  return;
}

/* FUN_000efdb6 @ 0xefdb6 (909 bytes) */
int FUN_000efdb6(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar1 = FUN_0010a17a(0x17,*(undefined4 *)(param_1 + 8));
  FUN_0010a3c2(iVar1,1,*(undefined4 *)(param_2 + 0xa4));
  iVar2 = FUN_0010b0f4(param_2,1);
  uVar7 = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = FUN_0010b0f4(iVar1,1);
  *(undefined4 *)(iVar2 + 0x10) = uVar7;
  FUN_000fa0d2(iVar1,param_1,2,0x3f000001,0,0,0);
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar2;
  uVar3 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar2,0);
  FUN_0010a3c2(iVar1,0,uVar3);
  *(undefined4 *)(iVar1 + 0x9c) = DAT_001c64f4;
  *(undefined1 *)(iVar1 + 0x120) = 1;
  iVar2 = FUN_0010a17a(0x13,*(undefined4 *)(param_1 + 8));
  FUN_0010a3c2(iVar2,1,*(undefined4 *)(param_2 + 0xa4));
  iVar4 = FUN_0010b0f4(param_2,1);
  uVar7 = *(undefined4 *)(iVar4 + 0x10);
  iVar4 = FUN_0010b0f4(iVar2,1);
  *(undefined4 *)(iVar4 + 0x10) = uVar7;
  FUN_000fa0d2(iVar2,param_1,2,0x3f7fffff,0,0,0);
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar4;
  uVar5 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar4,0);
  FUN_0010a3c2(iVar2,0,uVar5);
  *(undefined4 *)(iVar2 + 0x9c) = DAT_001c64f4;
  *(undefined1 *)(iVar2 + 0x120) = 1;
  iVar4 = FUN_0010a17a(0x14,*(undefined4 *)(param_1 + 8));
  FUN_0010a3c2(iVar4,1,uVar3);
  uVar7 = DAT_001c6504;
  iVar6 = FUN_0010b0f4(iVar4,1);
  *(undefined4 *)(iVar6 + 0x10) = uVar7;
  FUN_000fa0d2(iVar4,param_1,2,0x3f7fffff,0,0,0);
  FUN_0010a3c2(iVar4,3,uVar5);
  iVar6 = FUN_0010b0f4(iVar4,3);
  *(undefined4 *)(iVar6 + 0x10) = uVar7;
  iVar6 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar6;
  uVar7 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar6,0);
  FUN_0010a3c2(iVar4,0,uVar7);
  *(undefined4 *)(iVar4 + 0x9c) = DAT_001c64f4;
  *(undefined1 *)(iVar4 + 0x120) = 0;
  FUN_0010a3c2(param_2,1,uVar7);
  uVar7 = *(undefined4 *)(param_2 + 0x158);
  FUN_000e956e(uVar7,param_2,iVar4);
  FUN_000e956e(uVar7,iVar4,iVar2);
  FUN_000e956e(uVar7,iVar2,iVar1);
  return;
}

/* FUN_000f0144 @ 0xf0144 (513 bytes) */
int FUN_000f0144(param_1, param_2)
  int param_1;
  int param_2;
{
  code *pcVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_20;
  
  if (*(int *)(param_2 + 0x80) != 0) {
    piVar2 = (int *)FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),*(undefined4 *)(param_2 + 0x98),
                                 *(undefined4 *)(param_2 + 0x94),0);
    pcVar1 = *(code **)(*piVar2 + 0x28);
    iVar5 = FUN_0010b0f4(param_2,0);
    piVar3 = (int *)(*pcVar1)(piVar2,*(undefined4 *)(iVar5 + 0x10),param_1);
    if ((piVar3 == (int *)0x0) || (piVar2 == piVar3)) {
      FUN_0012a42e(piVar2,param_2);
      FUN_0010a3c2(param_2,0,piVar2);
    }
    else {
      FUN_0012a42e(piVar3,param_2);
      FUN_0010a3c2(param_2,0,piVar3);
      if ((*(byte *)(param_1 + 0x31) & 0x40) != 0) {
        FUN_000e9596(*(undefined4 *)(param_2 + 0x158),param_2,piVar2[0xc]);
      }
    }
  }
  if (0 < *(int *)(param_2 + 0x84)) {
    local_20 = 1;
    iVar5 = param_2;
    do {
      if (*(int *)(iVar5 + 0xb0) == 0x1c) {
        iVar6 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar6;
        iVar4 = FUN_0010b0f4(param_2,local_20);
        *(int *)(iVar4 + 8) = iVar6;
        *(undefined4 *)(iVar4 + 0xc) = 0x1c;
      }
      piVar2 = (int *)FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),*(undefined4 *)(iVar5 + 0xb0),
                                   *(undefined4 *)(iVar5 + 0xac),0);
      piVar3 = (int *)(**(code **)(*piVar2 + 0x28))(piVar2,DAT_001c6500,param_1);
      if (piVar3 != (int *)0x0) {
        piVar2 = piVar3;
      }
      FUN_0012a9e6(piVar2,local_20,param_2);
      FUN_0010a3c2(param_2,local_20,piVar2);
      local_20 = local_20 + 1;
      iVar5 = iVar5 + 0x18;
    } while (local_20 <= *(int *)(param_2 + 0x84));
  }
  return;
}

/* FUN_000f0346 @ 0xf0346 (133 bytes) */
int FUN_000f0346(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  piVar1 = *(int **)(param_1 + 0x378);
  iVar3 = piVar1[2];
  while (iVar3 != 0) {
    (**(code **)(*piVar1 + 0x48))(piVar1);
    piVar1 = (int *)piVar1[2];
    iVar3 = piVar1[2];
  }
  uVar4 = 1;
  iVar5 = 0;
  iVar3 = *(int *)(param_1 + 0x3b8);
  if (*(int *)(iVar3 + 4) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(iVar3 + 8) + iVar5);
      if ((*(byte *)(iVar2 + 0x14) & 1) != 0) {
        FUN_0010b0f4(iVar2,0);
        iVar3 = *(int *)(param_1 + 0x3b8);
      }
      uVar4 = uVar4 + 1;
      iVar5 = iVar5 + 4;
    } while (uVar4 <= *(uint *)(iVar3 + 4));
  }
  return 1;
}

/* FUN_000f03cc @ 0xf03cc (1297 bytes) */
int FUN_000f03cc(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  int local_70;
  int *local_5c;
  int *local_58;
  int *local_48;
  int *local_40;
  int local_28;
  int local_24;
  int local_20 [4];
  
  iVar1 = *(int *)(param_1 + 0x378);
  iVar9 = *(int *)(iVar1 + 8);
  do {
    if (iVar9 == 0) {
      return;
    }
    piVar13 = *(int **)(iVar1 + 0x98);
    if (piVar13[2] != 0) {
      local_5c = (int *)0x0;
      local_58 = (int *)0x0;
      do {
        if ((*(byte *)(piVar13 + 5) & 1) != 0) {
          iVar9 = piVar13[0x2c];
          cVar5 = (**(code **)(*piVar13 + 0x28))(piVar13);
          if (((cVar5 != '\0') && (cVar5 = (**(code **)(*piVar13 + 0x2c))(piVar13), cVar5 != '\0'))
             && ((iVar9 == 0x1f || (((iVar9 == 0xd || (iVar9 == 0xe)) || (iVar9 == 0xf)))))) {
            uVar8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
            puVar6 = (undefined4 *)FUN_001a7bca(uVar8,0x18);
            *puVar6 = uVar8;
            puVar6[2] = piVar13;
            puVar6[5] = local_58;
            *(undefined1 *)(piVar13 + 0x4d) = 1;
            iVar7 = FUN_0010b0f4(piVar13,1);
            iVar7 = *(int *)(iVar7 + 0x10);
            FUN_0010a10a(piVar13,local_20,&local_24,&local_28,*(undefined4 *)(param_1 + 8));
            puVar6[3] = local_24;
            puVar6[4] = local_28;
            for (piVar11 = local_5c; piVar11 != (int *)0x0; piVar11 = (int *)piVar11[0xb]) {
              if (((*piVar11 == local_20[0]) && (iVar9 == piVar11[1])) && (piVar11[2] == iVar7)) {
                if (local_24 < piVar11[5]) {
                  piVar11[3] = (int)piVar13;
                  piVar11[5] = local_24;
                }
                if (piVar11[6] < local_24 + local_28) {
                  piVar11[6] = local_24 + local_28;
                }
                piVar11[4] = piVar11[4] + 1;
                goto LAB_000f08d0;
              }
            }
            uVar8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
            puVar10 = (undefined4 *)FUN_001a7bca(uVar8,0x34);
            *puVar10 = uVar8;
            piVar11 = puVar10 + 1;
            puVar10[1] = local_20[0];
            puVar10[2] = iVar9;
            puVar10[3] = iVar7;
            puVar10[6] = local_24;
            puVar10[7] = local_24 + local_28;
            puVar10[4] = piVar13;
            puVar10[5] = 1;
            puVar10[0xc] = local_5c;
            local_5c = piVar11;
LAB_000f08d0:
            puVar6[1] = piVar11;
            local_58 = puVar6 + 1;
          }
        }
        piVar13 = (int *)piVar13[2];
      } while (piVar13[2] != 0);
      if (local_5c != (int *)0x0) {
        while( true ) {
          uVar8 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0x22,0,0);
          local_48 = (int *)0x0;
          do {
            piVar13 = (int *)local_5c[0xb];
            local_5c[0xb] = 0;
            iVar9 = local_5c[3];
            local_5c[7] = iVar9;
            uVar2 = *(undefined4 *)(iVar9 + 0x8c);
            iVar9 = FUN_0010b0f4(iVar9,0);
            uVar3 = *(undefined4 *)(iVar9 + 0x10);
            FUN_0010a3c2(local_5c[7],0,uVar8);
            *(undefined4 *)(local_5c[7] + 0x9c) = DAT_001c64f4;
            FUN_0012a42e(uVar8,local_5c[7]);
            uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
            puVar10 = (undefined4 *)FUN_001a7bca(uVar4,0x168);
            *puVar10 = uVar4;
            puVar6 = puVar10 + 1;
            FUN_0010f2b4(puVar6,0x84,*(undefined4 *)(param_1 + 8));
            FUN_0010a3c2(puVar6,0,uVar2);
            puVar10[0x28] = uVar3;
            FUN_0010a3c2(puVar6,1,uVar8);
            FUN_0012a42e(uVar2,puVar6);
            FUN_0012a9e6(uVar8,1,puVar6);
            FUN_000e9596(iVar1,local_5c[7],puVar6);
            *(undefined4 **)(local_5c[7] + 0x138) = puVar6;
            local_5c[8] = (int)puVar6;
            local_5c[9] = local_5c[5];
            local_5c[10] = 0;
            *(undefined4 *)(local_5c[7] + 0x13c) = 0;
            if (8 < local_5c[6] - local_5c[5]) {
              local_5c[0xb] = (int)local_48;
              local_5c[3] = 0;
              local_5c[4] = 0;
              local_5c[5] = local_5c[6] + 1;
              local_5c[6] = 0;
              local_48 = local_5c;
            }
            local_5c = piVar13;
          } while (piVar13 != (int *)0x0);
          if (local_58 == (int *)0x0) {
            local_40 = (int *)0x0;
          }
          else {
            local_40 = (int *)0x0;
            do {
              iVar9 = *local_58;
              piVar13 = (int *)local_58[4];
              local_58[4] = 0;
              iVar7 = local_58[2];
              local_70 = local_58[3];
              iVar12 = (iVar7 + local_70) - *(int *)(iVar9 + 0x24);
              iVar14 = local_58[1];
              if (iVar14 == *(int *)(iVar9 + 0x1c)) {
                if (*(int *)(iVar9 + 0x28) < iVar12) {
                  *(int *)(iVar9 + 0x28) = iVar12;
                  *(int *)(iVar14 + 0x13c) = iVar12;
                }
              }
              else if (iVar12 < 9) {
                if (*(int *)(iVar9 + 0x28) < iVar12) {
                  *(int *)(iVar9 + 0x28) = iVar12;
                  *(int *)(*(int *)(iVar9 + 0x1c) + 0x13c) = iVar12;
                  iVar14 = local_58[1];
                }
                FUN_001a7d72(iVar14);
                FUN_001a7cee(local_58[1],*(undefined4 *)(iVar9 + 0x20));
                FUN_0010a6a6(local_58[1],uVar8,*(undefined4 *)(param_1 + 8));
                FUN_0012a9e6(uVar8,*(undefined4 *)(local_58[1] + 0x84),local_58[1]);
              }
              else {
                if (iVar7 < *(int *)(iVar9 + 0x14)) {
                  *(int *)(iVar9 + 0xc) = iVar14;
                  *(int *)(iVar9 + 0x14) = local_58[2];
                  iVar7 = local_58[2];
                  local_70 = local_58[3];
                }
                if (*(int *)(iVar9 + 0x18) < iVar7 + local_70) {
                  *(int *)(iVar9 + 0x18) = iVar7 + local_70;
                }
                *(int *)(iVar9 + 0x10) = *(int *)(iVar9 + 0x10) + 1;
                local_58[4] = (int)local_40;
                local_40 = local_58;
              }
              local_58 = piVar13;
            } while (piVar13 != (int *)0x0);
          }
          if (local_48 == (int *)0x0) break;
          local_58 = local_40;
          local_5c = local_48;
        }
      }
    }
    iVar1 = *(int *)(iVar1 + 8);
    iVar9 = *(int *)(iVar1 + 8);
  } while( true );
}

/* FUN_000f08fc @ 0xf08fc (595 bytes) */
int FUN_000f08fc(param_1)
  int param_1;
{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_124;
  int local_120;
  int local_11c;
  int local_114;
  int local_110;
  int aiStack_10c [64];
  
  iVar7 = *(int *)(param_1 + 8);
  if (-1 < *(int *)(*(int *)(iVar7 + 0x54) + 0x4c)) {
    local_124 = 0;
    do {
      uVar5 = *(undefined4 *)(iVar7 + 0xbc);
      puVar6 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
      *puVar6 = uVar5;
      puVar6[4] = uVar5;
      puVar6[2] = 0;
      puVar6[1] = 2;
      uVar5 = FUN_001a7bca(uVar5,8);
      puVar6[3] = uVar5;
      aiStack_10c[local_124] = (int)(puVar6 + 1);
      local_124 = local_124 + 1;
      iVar7 = *(int *)(param_1 + 8);
    } while (local_124 <= *(int *)(*(int *)(iVar7 + 0x54) + 0x4c));
  }
  local_120 = *(int *)(param_1 + 0x378);
  iVar7 = *(int *)(local_120 + 8);
  while (iVar7 != 0) {
    while( true ) {
      puVar1 = (uint *)aiStack_10c[*(int *)(local_120 + 0xb8)];
      uVar3 = puVar1[1];
      if (uVar3 < *puVar1) break;
      piVar4 = (int *)FUN_001a7f7c(puVar1,uVar3);
      *piVar4 = local_120;
      local_120 = *(int *)(local_120 + 8);
      if (*(int *)(local_120 + 8) == 0) goto LAB_000f09cb;
    }
    _memset((void *)(uVar3 * 4 + puVar1[2]),0,4);
    puVar1[1] = uVar3 + 1;
    *(int *)(uVar3 * 4 + puVar1[2]) = local_120;
    local_120 = *(int *)(local_120 + 8);
    iVar7 = *(int *)(local_120 + 8);
  }
LAB_000f09cb:
  local_11c = FUN_001a7d8a(param_1 + 0x370);
  uVar5 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),local_11c * 4 + 4);
  *(undefined4 *)(param_1 + 0x390) = uVar5;
  local_11c = local_11c + -1;
  iVar7 = *(int *)(param_1 + 8);
  if (-1 < *(int *)(*(int *)(iVar7 + 0x54) + 0x4c)) {
    local_110 = 0;
    do {
      iVar2 = aiStack_10c[local_110];
      if (*(int *)(iVar2 + 4) != 0) {
        local_114 = local_11c << 2;
        do {
          iVar7 = *(int *)(param_1 + 0x390);
          uVar3 = *(uint *)(iVar2 + 4);
          if (uVar3 - 1 < uVar3) {
            puVar6 = (undefined4 *)(*(int *)(iVar2 + 8) + (uVar3 - 1) * 4);
          }
          else {
            puVar6 = (undefined4 *)0x0;
          }
          uVar5 = *puVar6;
          FUN_001a7f3c(iVar2,uVar3 - 1);
          *(undefined4 *)(local_114 + iVar7) = uVar5;
          local_11c = local_11c + -1;
          local_114 = local_114 + -4;
        } while (*(int *)(iVar2 + 4) != 0);
        iVar7 = *(int *)(param_1 + 8);
      }
      local_110 = local_110 + 1;
    } while (local_110 <= *(int *)(*(int *)(iVar7 + 0x54) + 0x4c));
  }
  return *(undefined4 *)(param_1 + 0x390);
}

/* FUN_000f0b74 @ 0xf0b74 (111 bytes) */
int FUN_000f0b74(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = *(uint **)(param_1 + 0x3b8);
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

/* FUN_000f0be4 @ 0xf0be4 (583 bytes) */
int FUN_000f0be4(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint local_28;
  int local_24;
  int local_20;
  
  if (((*(byte *)(param_1 + 0x30) & 1) != 0) &&
     (piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x54),
     iVar2 = (**(code **)(*piVar1 + 0xe4))(piVar1), *(char *)(param_1 + 0x3c8) != '\0')) {
    if ((*(byte *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 9) & 0x20) == 0) {
      iVar4 = iVar2;
      if ((*(char *)(param_1 + 0x3d8) != '\0') &&
         (iVar4 = *(int *)(param_1 + 0x3e0), iVar4 <= iVar2)) {
        iVar4 = iVar2 + 1;
      }
      iVar2 = *(int *)(param_1 + 0x3cc);
      *(int *)(param_1 + 0x3d4) = iVar4 - iVar2;
      if (iVar2 < *(int *)(param_1 + 0x3d0)) {
        do {
          uVar3 = ((int (*)())FUN_000edadc)(param_1,5);
          iVar4 = FUN_0012ead6(*(undefined4 *)(param_1 + 0x3a0),uVar3,iVar2,0);
          if (iVar4 != 0) {
            local_28 = 1;
            local_24 = 0;
            iVar5 = *(int *)(iVar4 + 0x18);
            if (*(int *)(iVar5 + 4) != 0) {
              do {
                iVar5 = *(int *)(local_24 + *(int *)(iVar5 + 8));
                if ((*(uint *)(iVar5 + 0x14) & 1) != 0) {
                  *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x10;
                  ((int (*)())FUN_000f0b74)(param_1,iVar5);
                }
                local_28 = local_28 + 1;
                local_24 = local_24 + 4;
                iVar5 = *(int *)(iVar4 + 0x18);
              } while (local_28 <= *(uint *)(iVar5 + 4));
            }
            *(int *)(iVar4 + 0x10) = iVar2 + *(int *)(param_1 + 0x3d4);
            *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) | 2;
            FUN_00137b7e(param_1,iVar2 + *(int *)(param_1 + 0x3d4));
            FUN_00138146(param_1,iVar2 + *(int *)(param_1 + 0x3d4));
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(param_1 + 0x3d0));
      }
    }
    else {
      iVar2 = *(int *)(param_1 + 0x3cc);
      if (iVar2 < *(int *)(param_1 + 0x3d0)) {
        do {
          uVar3 = ((int (*)())FUN_000edadc)(param_1,5);
          iVar4 = FUN_0012ead6(*(undefined4 *)(param_1 + 0x3a0),uVar3,iVar2,0);
          if (iVar4 != 0) {
            uVar6 = 1;
            local_20 = 0;
            iVar5 = *(int *)(iVar4 + 0x18);
            if (*(int *)(iVar5 + 4) != 0) {
              do {
                iVar5 = *(int *)(local_20 + *(int *)(iVar5 + 8));
                if ((*(uint *)(iVar5 + 0x14) & 1) != 0) {
                  *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x10;
                  ((int (*)())FUN_000f0b74)(param_1,iVar5);
                }
                uVar6 = uVar6 + 1;
                local_20 = local_20 + 4;
                iVar5 = *(int *)(iVar4 + 0x18);
              } while (uVar6 <= *(uint *)(iVar5 + 4));
            }
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(param_1 + 0x3d0));
      }
    }
  }
  return;
}

/* FUN_000f0e2c @ 0xf0e2c (414 bytes) */
int FUN_000f0e2c(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  char cVar4;
  undefined4 *puVar5;
  int iVar6;
  
  if (*(char *)(param_1 + 0x3d8) != '\0') {
    piVar2 = *(int **)(*(int *)(param_1 + 0x394) + 0x98);
    iVar6 = piVar2[2];
    while (iVar6 != 0) {
      if (((*(byte *)(piVar2 + 5) & 1) != 0) &&
         (cVar4 = (**(code **)(*piVar2 + 0x4c))(piVar2), cVar4 != '\0')) {
        if ((*(char *)(param_1 + 0x3d8) != '\0') &&
           (((piVar2[0x51] == *(int *)(param_1 + 1000) &&
             (*(int *)(param_1 + 0x3dc) <= piVar2[0x52])) &&
            (piVar2[0x52] < *(int *)(param_1 + 0x3e0))))) {
          piVar2[5] = piVar2[5] | 0x10;
          ((int (*)())FUN_000f0b74)(param_1,piVar2);
        }
      }
      piVar2 = (int *)piVar2[2];
      iVar6 = piVar2[2];
    }
    *(int *)(param_1 + 0x3e4) = -*(int *)(param_1 + 0x3dc);
  }
  if ((*(int *)(param_1 + 0x348) == 0) && (*(int *)(param_1 + 0x350) == 0)) {
    iVar6 = *(int *)(param_1 + 0x34c);
    if (iVar6 != 0) goto LAB_000f0e83;
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
    puVar5 = (undefined4 *)FUN_001a7bca(uVar3,0x168);
    *puVar5 = uVar3;
    puVar1 = puVar5 + 1;
    FUN_0010dfac(puVar1,*(undefined4 *)(param_1 + 8));
    *(undefined4 **)(param_1 + 0x348) = puVar1;
    iVar6 = FUN_0010b0f4(puVar1,0);
    *(undefined4 *)(iVar6 + 8) = 0;
    *(undefined4 *)(iVar6 + 0xc) = 9;
    puVar5[0x28] = DAT_001c64f4;
    FUN_000fa0d2(puVar1,param_1,1,0,0,0,0);
    FUN_000fbaca(param_1,puVar1,*(undefined4 *)(param_1 + 0x39c));
  }
  iVar6 = *(int *)(param_1 + 0x34c);
  if (iVar6 == 0) {
    return;
  }
LAB_000f0e83:
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 9) & 0x40) == 0) {
    return;
  }
  ((int (*)())FUN_000efdb6)(param_1,iVar6);
  return;
}

/* FUN_000f0fe8 @ 0xf0fe8 (1082 bytes) */
int FUN_000f0fe8(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  code *pcVar4;
  int iVar5;
  char cVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  int iVar11;
  int *piVar12;
  int *local_20;
  int local_1c;
  
  iVar1 = *(int *)(param_1 + 0x378);
  iVar11 = *(int *)(iVar1 + 8);
  do {
    if (iVar11 == 0) {
      return;
    }
    piVar2 = *(int **)(iVar1 + 0x98);
    iVar11 = piVar2[2];
    while (iVar11 != 0) {
      piVar12 = piVar2;
      if ((*(byte *)(piVar2 + 5) & 1) != 0) {
        piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x54);
        cVar6 = (**(code **)(*piVar3 + 0xcc))(piVar3);
        if (cVar6 == '\0') {
          if (*(int *)(piVar2[0x22] + 8) != 0x77) goto LAB_000f1056;
          uVar7 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0x30,0,0);
          FUN_0010a3c2(piVar2,0,uVar7);
          piVar2[5] = piVar2[5] | 0x10;
          FUN_0012a42e(uVar7,piVar2);
          ((int (*)())FUN_000f0b74)(param_1,piVar2);
          iVar11 = piVar2[0x26];
        }
        else {
          if ((((*(byte *)(piVar2 + 5) & 2) != 0) &&
              (iVar11 = FUN_00109e62(piVar2[0x26]), iVar11 == 9)) &&
             (iVar11 = FUN_0012ead6(*(undefined4 *)(param_1 + 0x3a0),0x21,0,0), iVar11 != 0)) {
            FUN_0010a6a6(piVar2,iVar11,*(undefined4 *)(param_1 + 8));
          }
LAB_000f1056:
          iVar11 = piVar2[0x26];
        }
        if (iVar11 == 0x2a) {
          local_1c = *(int *)(param_1 + 0x3dc);
          local_20 = piVar2;
          if (local_1c < *(int *)(param_1 + 0x3e0)) {
            do {
              piVar9 = (int *)FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),
                                           *(undefined4 *)(param_1 + 1000),local_1c,0);
              uVar7 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
              puVar10 = (undefined4 *)FUN_001a7bca(uVar7,0x168);
              *puVar10 = uVar7;
              piVar12 = puVar10 + 1;
              FUN_0010f2b4(piVar12,0x84,*(undefined4 *)(param_1 + 8));
              puVar10[0x4b] = local_1c;
              pcVar4 = *(code **)(*piVar9 + 0x28);
              iVar11 = FUN_0010b0f4(piVar2,0);
              iVar11 = (*pcVar4)(piVar9,*(undefined4 *)(iVar11 + 0x10),param_1);
              piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x54);
              cVar6 = (**(code **)(*piVar3 + 0xd8))(piVar3);
              if (cVar6 != '\0') {
                *(int *)(iVar11 + 0x10) = local_1c;
                *(uint *)(iVar11 + 0x24) = *(uint *)(iVar11 + 0x24) | 2;
                FUN_00137b7e(param_1,local_1c);
                FUN_00138146(param_1,local_1c);
              }
              iVar5 = piVar2[0x23];
              FUN_0010a3c2(piVar12,0,iVar11);
              iVar8 = FUN_0010b0f4(piVar2,0);
              puVar10[0x28] = *(undefined4 *)(iVar8 + 0x10);
              FUN_0012a42e(iVar11,piVar12);
              FUN_0010a3c2(piVar12,1,iVar5);
              FUN_0012a9e6(iVar5,1,piVar12);
              FUN_0010a6a6(piVar12,iVar11,*(undefined4 *)(param_1 + 8));
              FUN_0012a9e6(iVar11,2,piVar12);
              FUN_000e9596(iVar1,local_20,piVar12);
              iVar11 = (**(code **)(*piVar9 + 0x2c))(piVar9);
              *(undefined1 *)(iVar11 + 0x144) = 1;
              local_1c = local_1c + 1;
              local_20 = piVar12;
            } while (local_1c < *(int *)(param_1 + 0x3e0));
          }
        }
        else {
          if ((piVar2[0x21] == 0) || ((piVar2[0x26] != 0x3b && (piVar2[0x26] != 0x2c)))) {
            if ((piVar2[0x20] == 0) ||
               ((cVar6 = FUN_000f59aa(piVar2), cVar6 == '\0' ||
                (cVar6 = (**(code **)(*piVar2 + 0x4c))(piVar2), cVar6 != '\0')))) goto LAB_000f101c;
            iVar11 = piVar2[0x23];
            FUN_0010a6a6(piVar2,iVar11,*(undefined4 *)(param_1 + 8));
          }
          else {
            iVar11 = piVar2[0x23];
            iVar5 = piVar2[0x21];
            piVar2[0x21] = iVar5 + 1;
            FUN_0010a3c2(piVar2,iVar5 + 1,iVar11);
          }
          FUN_0012a9e6(iVar11,piVar2[0x21],piVar2);
        }
      }
LAB_000f101c:
      piVar2 = (int *)piVar12[2];
      iVar11 = piVar2[2];
    }
    iVar1 = *(int *)(iVar1 + 8);
    iVar11 = *(int *)(iVar1 + 8);
  } while( true );
}

/* FUN_000f1442 @ 0xf1442 (633 bytes) */
int FUN_000f1442(param_1)
  int param_1;
{
  int *piVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int local_28;
  int local_24;
  int *local_20;
  
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  iVar4 = (**(code **)(*piVar1 + 0x16c))(piVar1);
  cVar3 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x31);
  if (cVar3 == '\0') {
    cVar3 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x33);
    if (cVar3 != '\0') {
      piVar1 = *(int **)(*(int *)(param_1 + 0x39c) + 0x98);
      iVar5 = piVar1[2];
      while (iVar5 != 0) {
        if (((((*(byte *)(piVar1 + 5) & 1) != 0) &&
             (cVar3 = (**(code **)(*piVar1 + 0x68))(piVar1), cVar3 != '\0')) && (piVar1[0x26] != 7))
           && ((*(int *)(*(int *)(piVar1[0x22] + 8) * 0x38 + 0x34 + iVar4) == 0 &&
               (local_28 = FUN_000f60f4(piVar1), 1 < local_28)))) {
          local_24 = 0;
          local_20 = (int *)PTR_DAT_0021345d;
          do {
            iVar5 = FUN_0010b0f4(piVar1,0);
            if (*(char *)(local_24 + 0x10 + iVar5) != '\x01') {
              if (local_28 < 2) {
                piVar1[0x27] = *local_20;
              }
              else {
                iVar5 = FUN_0010a1c2(piVar1,*(undefined4 *)(param_1 + 8),0);
                *(int *)(iVar5 + 0x9c) = *local_20;
                FUN_000e956e(*(undefined4 *)(param_1 + 0x39c),piVar1,iVar5);
                ((int (*)())FUN_000f0b74)(param_1,iVar5);
              }
              local_28 = local_28 + -1;
            }
            local_24 = local_24 + 1;
            local_20 = local_20 + 1;
          } while (local_24 != 4);
        }
        piVar1 = (int *)piVar1[2];
        iVar5 = piVar1[2];
      }
    }
  }
  else {
    piVar1 = *(int **)(*(int *)(param_1 + 0x39c) + 0x98);
    iVar5 = piVar1[2];
    while (iVar5 != 0) {
      if ((((*(byte *)(piVar1 + 5) & 1) != 0) &&
          (cVar3 = (**(code **)(*piVar1 + 0x68))(piVar1), cVar3 != '\0')) &&
         ((piVar1[0x26] != 6 &&
          (((piVar1[0x26] != 7 && (piVar1[0x26] != 0x2c)) &&
           (*(int *)(*(int *)(piVar1[0x22] + 8) * 0x38 + 0x34 + iVar4) == 0)))))) {
        iVar5 = FUN_0010b0f4(piVar1,0);
        uVar2 = *(uint *)(iVar5 + 0x10);
        cVar3 = FUN_000f57b4(uVar2);
        if (cVar3 == '\0') {
          iVar5 = FUN_0010a1c2(piVar1,*(undefined4 *)(param_1 + 8),0);
          *(uint *)(iVar5 + 0x9c) = uVar2 & 0xffffff | 0x1000000;
          piVar1[0x27] = DAT_001c6508;
          FUN_000e956e(*(undefined4 *)(param_1 + 0x39c),piVar1,iVar5);
          ((int (*)())FUN_000f0b74)(param_1,iVar5);
        }
      }
      piVar1 = (int *)piVar1[2];
      iVar5 = piVar1[2];
    }
  }
  return;
}

/* FUN_000f16bc @ 0xf16bc (1016 bytes) */
int FUN_000f16bc(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint *puVar6;
  uint *puVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  iVar9 = *(int *)(param_1 + 8);
  piVar1 = *(int **)(iVar9 + 0x54);
  iVar2 = (**(code **)(*piVar1 + 0x138))(piVar1,iVar9);
  iVar3 = (**(code **)(*piVar1 + 0x140))(piVar1,iVar9);
  iVar4 = (**(code **)(*piVar1 + 0x13c))(piVar1,iVar9);
  uVar10 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  iVar4 = iVar2 + iVar3 + iVar4;
  uVar13 = iVar4 + 0x1fU >> 5;
  iVar9 = uVar13 * 4 + 0xc;
  puVar5 = (undefined4 *)FUN_001a7bca(uVar10,iVar9);
  puVar7 = puVar5 + 1;
  *puVar5 = uVar10;
  puVar5[2] = iVar4;
  puVar5[1] = uVar13;
  if (uVar13 != 0) {
    uVar11 = 0;
    puVar6 = puVar7;
    do {
      puVar6[2] = 0;
      uVar11 = uVar11 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar11 < uVar13);
  }
  *(uint **)(param_1 + 0x420) = puVar7;
  if (*puVar7 != 0) {
    uVar12 = 0;
    uVar11 = *puVar7;
    do {
      puVar7[2] = 0xffffffff;
      uVar12 = uVar12 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar12 < uVar11);
  }
  uVar10 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar10,iVar9);
  puVar7 = puVar5 + 1;
  *puVar5 = uVar10;
  puVar5[2] = iVar4;
  puVar5[1] = uVar13;
  if (uVar13 != 0) {
    uVar11 = 0;
    puVar6 = puVar7;
    do {
      puVar6[2] = 0;
      uVar11 = uVar11 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar11 < uVar13);
  }
  *(uint **)(param_1 + 0x424) = puVar7;
  if (*puVar7 != 0) {
    uVar11 = 0;
    uVar13 = *puVar7;
    do {
      puVar7[2] = 0xffffffff;
      uVar11 = uVar11 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar11 < uVar13);
  }
  uVar10 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar8 = (undefined4 *)FUN_001a7bca(uVar10,0x8c);
  *puVar8 = uVar10;
  puVar8[2] = 0x400;
  puVar8[1] = 0x20;
  uVar13 = 0;
  puVar5 = puVar8 + 1;
  do {
    puVar5[2] = 0;
    uVar13 = uVar13 + 1;
    puVar5 = puVar5 + 1;
  } while (uVar13 < 0x20);
  *(undefined4 **)(param_1 + 0x428) = puVar8 + 1;
  *(undefined4 *)(param_1 + 0x430) = 0;
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  iVar9 = (**(code **)(*piVar1 + 0x138))(piVar1,*(int *)(param_1 + 8));
  *(int *)(param_1 + 0x43c) = iVar9;
  *(int *)(param_1 + 0x434) = iVar9;
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  iVar2 = (**(code **)(*piVar1 + 0x140))(piVar1,*(int *)(param_1 + 8));
  iVar9 = iVar9 + iVar2;
  *(int *)(param_1 + 0x440) = iVar9;
  *(int *)(param_1 + 0x438) = iVar9;
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  iVar2 = (**(code **)(*piVar1 + 0x13c))(piVar1,*(int *)(param_1 + 8));
  *(int *)(param_1 + 0x444) = iVar9 + iVar2;
  uVar10 = FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),
                        *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 0x50) * 0xc);
  *(undefined4 *)(param_1 + 0x78) = uVar10;
  uVar10 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar10,300);
  *puVar5 = uVar10;
  puVar5 = puVar5 + 1;
  FUN_000ec61e(puVar5,*(undefined4 *)(param_1 + 8));
  *(undefined4 **)(param_1 + 0x394) = puVar5;
  ((int (*)())FUN_000edc64)(param_1,puVar5);
  uVar10 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar10,0x128);
  *puVar5 = uVar10;
  puVar5 = puVar5 + 1;
  FUN_000ec5c2(puVar5,*(undefined4 *)(param_1 + 8));
  *(undefined4 **)(param_1 + 0x39c) = puVar5;
  ((int (*)())FUN_000edca0)(param_1,puVar5);
  FUN_0012ee7e(*(undefined4 *)(param_1 + 0x3a0),*(byte *)(param_1 + 0x30) & 1);
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  (**(code **)(*piVar1 + 0x10))(piVar1,*(int *)(param_1 + 8));
  FUN_00101244(param_1,param_2);
  if ((*(uint *)(param_1 + 0x30) & 1) == 0) {
    if ((*(uint *)(param_1 + 0x30) & 0x2000) != 0) {
      uVar10 = 1;
      iVar9 = 1;
      goto LAB_000f1a4b;
    }
    iVar9 = 2;
    piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    (**(code **)(*piVar1 + 0x14))(piVar1,2,*(int *)(param_1 + 8));
  }
  else {
    uVar10 = 0;
    iVar9 = 0;
LAB_000f1a4b:
    piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    (**(code **)(*piVar1 + 0x14))(piVar1,uVar10,*(int *)(param_1 + 8));
    if (iVar9 == 1) {
      ((int (*)())FUN_000f0e2c)(param_1);
      goto LAB_000f19f9;
    }
  }
  if (iVar9 == 2) {
    iVar9 = *(int *)(param_1 + 8);
  }
  else {
    if (iVar9 != 0) goto LAB_000f19f9;
    iVar9 = *(int *)(param_1 + 8);
  }
  (**(code **)(**(int **)(iVar9 + 0x54) + 0xac))
            (*(int **)(iVar9 + 0x54),*(undefined4 *)(param_1 + 0x358),param_1,iVar9);
LAB_000f19f9:
  ((int (*)())FUN_000f1442)(param_1);
  FUN_00135f54(param_1);
  ((int (*)())FUN_000f0fe8)(param_1);
  ((int (*)())FUN_000f0be4)(param_1);
  FUN_0013fac4(param_1);
  ((int (*)())FUN_000f0346)(param_1,"non_local_set");
  return;
}

/* FUN_000f1af0 @ 0xf1af0 (111 bytes) */
int FUN_000f1af0(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = *(uint **)(param_1 + 0x3bc);
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

/* FUN_000f1b60 @ 0xf1b60 (222 bytes) */
int FUN_000f1b60(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  uint *puVar3;
  uint *local_14;
  uint local_10;
  
  if ((*(uint **)(param_1 + 0x3b8))[1] == 0) {
    return;
  }
  local_10 = 0;
  local_14 = *(uint **)(param_1 + 0x3b8);
  do {
    if (local_10 < *local_14) {
      uVar1 = local_14[1];
      puVar3 = local_14;
      if (uVar1 <= local_10) {
        _memset((void *)(local_14[2] + uVar1 * 4),0,(local_10 - uVar1) * 4 + 4);
        local_14[1] = local_10 + 1;
        puVar3 = *(uint **)(param_1 + 0x3b8);
      }
      if (*(int *)(local_14[2] + local_10 * 4) != param_2) goto LAB_000f1ba3;
LAB_000f1bda:
      FUN_001a7f3c(puVar3,local_10);
      puVar3 = *(uint **)(param_1 + 0x3b8);
      if (puVar3[1] <= local_10 + 1) {
        return;
      }
    }
    else {
      piVar2 = (int *)FUN_001a7f7c(local_14,local_10);
      puVar3 = *(uint **)(param_1 + 0x3b8);
      if (*piVar2 == param_2) goto LAB_000f1bda;
LAB_000f1ba3:
      if (puVar3[1] <= local_10 + 1) {
        return;
      }
    }
    local_10 = local_10 + 1;
    local_14 = puVar3;
  } while( true );
}

/* FUN_000f1c3e @ 0xf1c3e (1065 bytes) */
int FUN_000f1c3e(param_1)
  int param_1;
{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  dword *pdVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  dword local_2c;
  uint local_28;
  int local_24;
  dword local_20;
  
  uVar8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar7 = (undefined4 *)FUN_001a7bca(uVar8,0x14);
  *puVar7 = uVar8;
  puVar1 = puVar7 + 1;
  puVar7[4] = uVar8;
  puVar7[2] = 0;
  puVar7[1] = 2;
  uVar8 = FUN_001a7bca(uVar8,8);
  puVar7[3] = uVar8;
  uVar8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar9 = (undefined4 *)FUN_001a7bca(uVar8,0x14);
  *puVar9 = uVar8;
  puVar2 = puVar9 + 1;
  puVar9[4] = uVar8;
  puVar9[2] = 0;
  puVar9[1] = 2;
  uVar8 = FUN_001a7bca(uVar8,8);
  puVar9[3] = uVar8;
  iVar12 = *(int *)(param_1 + 0x378);
  iVar3 = *(int *)(iVar12 + 8);
  while (iVar3 != 0) {
    *(undefined4 *)(iVar12 + 0x110) = 0;
    iVar12 = *(int *)(iVar12 + 8);
    iVar3 = *(int *)(iVar12 + 8);
  }
  uVar8 = *(undefined4 *)(param_1 + 0x394);
  uVar14 = puVar7[2];
  if (uVar14 < *puVar1) {
    _memset((void *)(uVar14 * 4 + puVar7[3]),0,4);
    puVar7[2] = uVar14 + 1;
    puVar10 = (undefined4 *)(uVar14 * 4 + puVar7[3]);
  }
  else {
    puVar10 = (undefined4 *)FUN_001a7f7c(puVar1,uVar14);
  }
  *puVar10 = uVar8;
  *(undefined4 *)(*(int *)(param_1 + 0x394) + 0x110) = 1;
LAB_000f1d69:
  iVar12 = puVar7[2];
  local_2c = MACH_HEADER.magic;
  do {
    MACH_HEADER.magic = local_2c;
    if (iVar12 == 0) {
      FUN_001a7d22(param_1 + 0x370);
      iVar12 = puVar9[2];
      while (iVar12 != 0) {
        uVar14 = puVar9[2];
        if (uVar14 - 1 < uVar14) {
          puVar7 = (undefined4 *)(puVar9[3] + (uVar14 - 1) * 4);
        }
        else {
          puVar7 = (undefined4 *)0x0;
        }
        uVar8 = *puVar7;
        FUN_001a7f3c(puVar2,uVar14 - 1);
        FUN_001a7cd6(param_1 + 0x370,uVar8);
        ((int (*)())FUN_000edb74)(param_1);
        iVar12 = puVar9[2];
      }
      return;
    }
    uVar14 = puVar7[2];
    if (uVar14 - 1 < uVar14) {
      local_2c = *(dword *)(puVar7[3] + (uVar14 - 1) * 4);
      FUN_001a7f3c(puVar1,uVar14 - 1);
      uVar14 = puVar7[2];
      if (uVar14 < *puVar1) goto LAB_000f1daf;
LAB_000f1fdd:
      pdVar11 = (dword *)FUN_001a7f7c(puVar1,uVar14);
    }
    else {
      FUN_001a7f3c(puVar1,uVar14 - 1);
      uVar14 = puVar7[2];
      if (*puVar1 <= uVar14) goto LAB_000f1fdd;
LAB_000f1daf:
      _memset((void *)(uVar14 * 4 + puVar7[3]),0,4);
      puVar7[2] = uVar14 + 1;
      pdVar11 = (dword *)(uVar14 * 4 + puVar7[3]);
    }
    *pdVar11 = local_2c;
    cVar6 = FUN_000e97ce(local_2c);
    if (cVar6 != '\0') {
      bVar4 = true;
      local_28 = 1;
      local_24 = 0;
      iVar12 = *(int *)(local_2c + 0xd0);
      bVar5 = true;
      if (*(int *)(iVar12 + 4) != 0) {
        do {
          bVar4 = bVar5;
          iVar12 = *(int *)(local_24 + *(int *)(iVar12 + 8));
          if ((iVar12 != 0) && (*(int *)(iVar12 + 0x110) == 0)) {
            uVar14 = puVar7[2];
            if (uVar14 < *puVar1) {
              _memset((void *)(uVar14 * 4 + puVar7[3]),0,4);
              puVar7[2] = uVar14 + 1;
              piVar13 = (int *)(uVar14 * 4 + puVar7[3]);
            }
            else {
              piVar13 = (int *)FUN_001a7f7c(puVar1,uVar14);
            }
            *piVar13 = iVar12;
            *(undefined4 *)(iVar12 + 0x110) = 1;
            bVar4 = false;
          }
          local_28 = local_28 + 1;
          local_24 = local_24 + 4;
          iVar12 = *(int *)(local_2c + 0xd0);
          bVar5 = bVar4;
        } while (local_28 <= *(uint *)(iVar12 + 4));
      }
      if (!bVar4) goto LAB_000f1d69;
    }
    uVar14 = puVar7[2];
    if (uVar14 - 1 < uVar14) {
      local_20 = *(dword *)(puVar7[3] + (uVar14 - 1) * 4);
      FUN_001a7f3c(puVar1,uVar14 - 1);
      uVar14 = puVar9[2];
      if (uVar14 < *puVar2) goto LAB_000f1ef9;
LAB_000f201f:
      pdVar11 = (dword *)FUN_001a7f7c(puVar2,uVar14);
      *pdVar11 = local_20;
    }
    else {
      local_20 = MACH_HEADER.magic;
      FUN_001a7f3c(puVar1,uVar14 - 1);
      uVar14 = puVar9[2];
      if (*puVar2 <= uVar14) goto LAB_000f201f;
LAB_000f1ef9:
      _memset((void *)(uVar14 * 4 + puVar9[3]),0,4);
      puVar9[2] = uVar14 + 1;
      *(dword *)(uVar14 * 4 + puVar9[3]) = local_20;
    }
    iVar12 = puVar7[2];
    local_2c = MACH_HEADER.magic;
  } while( true );
}

/* FUN_000f20a2 @ 0xf20a2 (970 bytes) */
int FUN_000f20a2(param_1)
  int param_1;
{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  uint local_2c;
  int local_28;
  uint local_24;
  int local_20;
  
  if (((*(uint *)(param_1 + 0x30) & 1) == 0) && ((*(uint *)(param_1 + 0x30) & 0x2000) != 0)) {
    uVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
    puVar4 = (undefined4 *)FUN_001a7bca(uVar6,0x168);
    *puVar4 = uVar6;
    puVar4 = puVar4 + 1;
    FUN_0010ac30(puVar4,0x95,*(undefined4 *)(param_1 + 8));
  }
  else {
    uVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
    puVar4 = (undefined4 *)FUN_001a7bca(uVar6,0x168);
    *puVar4 = uVar6;
    puVar4 = puVar4 + 1;
    FUN_0010ac30(puVar4,0x96,*(undefined4 *)(param_1 + 8));
  }
  *(undefined4 **)(param_1 + 0x33c) = puVar4;
  iVar5 = *(int *)(param_1 + 0x33c);
  *(undefined4 *)(iVar5 + 0x94) = 0;
  *(undefined4 *)(iVar5 + 0x98) = 0x2d;
  *(undefined4 *)(*(int *)(param_1 + 0x33c) + 300) = 0;
  iVar5 = *(int *)(param_1 + 0x39c);
  puVar1 = (uint *)(iVar5 + 0xc);
  *puVar1 = *puVar1 | 8;
  do {
    iVar7 = iVar5;
    iVar5 = *(int *)(iVar7 + 0xec);
    if (iVar5 == 0) goto LAB_000f216c;
    *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) | 8;
    uVar2 = *(uint *)(iVar5 + 0xc);
  } while ((((uVar2 & 2) == 0) && ((uVar2 & 1) == 0)) && ((uVar2 & 4) == 0));
  if (*(int *)(*(int *)(iVar7 + 0xd4) + 4) == 1) {
    *(uint *)(iVar5 + 0xc) = uVar2 | 8;
    iVar7 = iVar5;
  }
LAB_000f216c:
  piVar8 = *(int **)(iVar7 + 0x98);
  iVar5 = piVar8[2];
  do {
    if (iVar5 == 0) {
LAB_000f21bc:
      *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) | 8;
      if (*(int *)(param_1 + 0x344) != 0) {
        (**(code **)(**(int **)(param_1 + 0x33c) + 0x94))
                  (*(int **)(param_1 + 0x33c),*(int *)(param_1 + 0x344),*(undefined4 *)(param_1 + 8)
                  );
      }
      uVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
      puVar4 = (undefined4 *)FUN_001a7bca(uVar6,0x14);
      *puVar4 = uVar6;
      puVar1 = puVar4 + 1;
      puVar4[4] = uVar6;
      puVar4[2] = 0;
      puVar4[1] = 2;
      uVar6 = FUN_001a7bca(uVar6,8);
      puVar4[3] = uVar6;
      local_24 = 1;
      local_20 = 0;
      iVar5 = *(int *)(iVar7 + 0xf0);
      if (*(int *)(iVar5 + 4) != 0) {
        do {
          uVar6 = *(undefined4 *)(*(int *)(iVar5 + 8) + local_20);
          uVar2 = puVar4[2];
          if (uVar2 < *puVar1) {
            _memset((void *)(uVar2 * 4 + puVar4[3]),0,4);
            puVar4[2] = uVar2 + 1;
            puVar9 = (undefined4 *)(uVar2 * 4 + puVar4[3]);
          }
          else {
            puVar9 = (undefined4 *)FUN_001a7f7c(puVar1,uVar2);
          }
          *puVar9 = uVar6;
          local_24 = local_24 + 1;
          local_20 = local_20 + 4;
          iVar5 = *(int *)(iVar7 + 0xf0);
        } while (local_24 <= *(uint *)(iVar5 + 4));
      }
      do {
        if (puVar4[2] == 0) {
          return;
        }
        while( true ) {
          if (*puVar1 == 0) {
            piVar8 = (int *)FUN_001a7f7c(puVar1,0);
          }
          else {
            if (puVar4[2] == 0) {
              *(undefined4 *)puVar4[3] = 0;
              puVar4[2] = 1;
            }
            piVar8 = (int *)puVar4[3];
          }
          iVar5 = *piVar8;
          FUN_001a7f3c(puVar1,0);
          *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 8;
          local_2c = 1;
          local_28 = 0;
          iVar7 = *(int *)(iVar5 + 0xf0);
          if (*(int *)(iVar7 + 4) == 0) break;
          do {
            uVar6 = *(undefined4 *)(*(int *)(iVar7 + 8) + local_28);
            uVar2 = puVar4[2];
            if (uVar2 < *puVar1) {
              _memset((void *)(uVar2 * 4 + puVar4[3]),0,4);
              puVar4[2] = uVar2 + 1;
              puVar9 = (undefined4 *)(uVar2 * 4 + puVar4[3]);
            }
            else {
              puVar9 = (undefined4 *)FUN_001a7f7c(puVar1,uVar2);
            }
            *puVar9 = uVar6;
            local_2c = local_2c + 1;
            local_28 = local_28 + 4;
            iVar7 = *(int *)(iVar5 + 0xf0);
          } while (local_2c <= *(uint *)(iVar7 + 4));
          if (puVar4[2] == 0) {
            return;
          }
        }
      } while( true );
    }
    if ((((*(byte *)(piVar8 + 5) & 1) != 0) &&
        (iVar5 = (**(code **)(*piVar8 + 0x7c))(piVar8), iVar5 == 0)) &&
       (cVar3 = (**(code **)(*piVar8 + 0x34))(piVar8), cVar3 == '\0')) {
      FUN_000e956e(iVar7,piVar8,*(undefined4 *)(param_1 + 0x33c));
      goto LAB_000f21bc;
    }
    piVar8 = (int *)piVar8[2];
    iVar5 = piVar8[2];
  } while( true );
}

/* FUN_000f24c4 @ 0xf24c4 (877 bytes) */
int FUN_000f24c4(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  uint *puVar8;
  uint *local_1c;
  int local_18;
  int local_10;
  
  if (((*(uint *)(param_1 + 0x30) & 0x4000) != 0) && ((*(uint *)(param_1 + 0x30) & 0x80000) == 0)) {
    if ((*(uint **)(param_1 + 0x3b8))[1] != 0) {
      uVar7 = 0;
      local_18 = 0;
      local_1c = *(uint **)(param_1 + 0x3b8);
      do {
        if (uVar7 < *local_1c) {
          uVar1 = local_1c[1];
          puVar8 = local_1c;
          if (uVar1 <= uVar7) {
            _memset((void *)(local_1c[2] + uVar1 * 4),0,(uVar7 - uVar1) * 4 + 4);
            local_1c[1] = uVar7 + 1;
            puVar8 = *(uint **)(param_1 + 0x3b8);
          }
          iVar2 = *(int *)(local_1c[2] + uVar7 * 4);
          if (*(int *)(iVar2 + 0x98) != 0x2c) {
            iVar2 = local_18;
          }
          local_18 = iVar2;
          if (puVar8[1] <= uVar7 + 1) goto LAB_000f256a;
        }
        else {
          piVar3 = (int *)FUN_001a7f7c(local_1c,uVar7);
          puVar8 = *(uint **)(param_1 + 0x3b8);
          iVar2 = *piVar3;
          if (*(int *)(*piVar3 + 0x98) != 0x2c) {
            iVar2 = local_18;
          }
          local_18 = iVar2;
          if (puVar8[1] <= uVar7 + 1) goto LAB_000f256a;
        }
        uVar7 = uVar7 + 1;
        local_1c = puVar8;
      } while( true );
    }
    local_18 = 0;
LAB_000f256a:
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
    puVar4 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
    *puVar4 = uVar5;
    puVar4[4] = uVar5;
    puVar4[2] = 0;
    puVar4[1] = 2;
    uVar5 = FUN_001a7bca(uVar5,8);
    puVar4[3] = uVar5;
    local_10 = FUN_0010b180(local_18,1);
LAB_000f25cb:
    if (*(int *)(local_10 + 0x84) != 0) {
      while ((iVar2 = *(int *)(local_10 + 0x88), *(int *)(iVar2 + 8) != 0xf7 &&
             (*(int *)(iVar2 + 8) != 0x107))) {
        if (*(int *)(iVar2 + 8) == 0xf9) {
          local_10 = FUN_0010b180(local_10,2);
          goto LAB_000f25cb;
        }
        if (*(int *)(iVar2 + 8) == 0x8e) {
          return;
        }
        local_10 = FUN_0010b180(local_10,1);
        if (*(int *)(local_10 + 0x84) == 0) goto LAB_000f2638;
      }
      uVar7 = puVar4[2];
      if (uVar7 < (uint)puVar4[1]) {
        _memset((void *)(uVar7 * 4 + puVar4[3]),0,4);
        puVar4[2] = uVar7 + 1;
        piVar3 = (int *)(uVar7 * 4 + puVar4[3]);
      }
      else {
        piVar3 = (int *)FUN_001a7f7c(puVar4 + 1,uVar7);
      }
      *piVar3 = local_10;
      local_10 = FUN_0010b180(local_10,1);
      goto LAB_000f25cb;
    }
LAB_000f2638:
    if (*(int *)(param_1 + 0x3ec) < (int)puVar4[2]) {
      uVar7 = puVar4[2] - *(int *)(param_1 + 0x3ec);
      if (uVar7 < (uint)puVar4[2]) {
        piVar3 = (int *)(puVar4[3] + uVar7 * 4);
      }
      else {
        piVar3 = (int *)0x0;
      }
      piVar3 = (int *)*piVar3;
      for (piVar6 = (int *)FUN_0010b180(local_18,1); piVar3 != piVar6;
          piVar6 = (int *)FUN_0010b180(piVar6,2)) {
        while (((iVar2 = piVar6[0x22], *(int *)(iVar2 + 8) == 0xf7 || (*(int *)(iVar2 + 8) == 0x107)
                ) || (*(int *)(iVar2 + 8) != 0xf9))) {
          (**(code **)(*piVar6 + 0xc))(piVar6,0,*(undefined4 *)(param_1 + 8));
          piVar6 = (int *)FUN_0010b180(piVar6,1);
          if (piVar3 == piVar6) goto LAB_000f26cf;
        }
        (**(code **)(*piVar6 + 0xc))(piVar6,0,*(undefined4 *)(param_1 + 8));
      }
LAB_000f26cf:
      FUN_0010ba02(local_18,1,piVar3,0,*(undefined4 *)(param_1 + 8));
      FUN_0010ba02(local_18,2,piVar3,0,*(undefined4 *)(param_1 + 8));
    }
  }
  return;
}

/* FUN_000f2852 @ 0xf2852 (670 bytes) */
int FUN_000f2852(param_1, param_2)
  int param_1;
  int *param_2;
{
  byte bVar1;
  bool bVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint local_28;
  float local_20;
  
  cVar3 = (**(code **)(*param_2 + 0x68))(param_2);
  if ((cVar3 == '\0') && (cVar3 = (**(code **)(*param_2 + 100))(param_2), cVar3 != '\0')) {
    for (iVar7 = 1; iVar5 = (**(code **)(*param_2 + 0x14))(param_2), iVar7 <= iVar5;
        iVar7 = iVar7 + 1) {
      if ((((param_2[iVar7 * 6 + 0x28] & 1U) != 0) || ((param_2[iVar7 * 6 + 0x28] & 2U) != 0)) ||
         (cVar3 = FUN_000f5a1e(param_2,iVar7), cVar3 == '\0')) goto LAB_000f2873;
    }
    if (((char)param_2[0x48] == '\0') && (param_2[0x49] == 0)) {
      if (((param_2[0x20] != 0) &&
          ((cVar3 = FUN_0012dfd8(param_2[0x26]), cVar3 != '\0' &&
           ((*(byte *)(param_2 + 5) & 2) == 0)))) &&
         (cVar3 = (**(code **)(*param_2 + 0x50))(param_2), cVar3 == '\0')) {
        iVar7 = 4;
        piVar4 = param_2;
        do {
          if ((byte)((char)piVar4[0x27] - 2U) < 2) goto LAB_000f2873;
          piVar4 = (int *)((int)piVar4 + 1);
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      FUN_0010b0f4(param_2,0);
      FUN_0010b7c8(param_2,0);
    }
  }
LAB_000f2873:
  piVar4 = (int *)FUN_0010b180(param_2,1);
  (**(code **)(*piVar4 + 0x48))(piVar4);
  local_28 = 0xffffffff;
  bVar2 = true;
  local_20 = 0.0;
  iVar7 = 0;
  do {
    iVar5 = FUN_0010b0f4(param_2,0);
    if (*(char *)(iVar7 + 0x10 + iVar5) != '\x01') {
      iVar5 = FUN_0010b0f4(param_2,1);
      bVar1 = *(byte *)(iVar7 + 0x10 + iVar5);
      uVar6 = (uint)bVar1;
      if ((((int)(char)piVar4[0x57] >> (bVar1 & 0x1f) & 1U) == 0) ||
         (cVar3 = ((undefined4 (*)())FUN_0010fd8c)(piVar4[uVar6 * 6 + 8]), cVar3 == '\0')) {
        bVar2 = false;
      }
      else if (local_28 == 0xffffffff) {
        local_20 = (float)piVar4[uVar6 * 6 + 8];
        local_28 = uVar6;
      }
      else if (local_20 != (float)piVar4[uVar6 * 6 + 8]) {
        return 0;
      }
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 != 4);
  if (bVar2) {
    iVar7 = ((int (*)())FUN_0010fdbc)(piVar4[local_28 * 6 + 8]);
    piVar4 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    cVar3 = (**(code **)(*piVar4 + 0xfc))(piVar4,iVar7,param_2);
    if (cVar3 != '\0') {
      FUN_000fa0d2(param_2,*(undefined4 *)(*(int *)(param_1 + 8) + 0x3f4),1,0x3f800000,0x3f800000,
                   0x3f800000,0x3f800000);
      param_2[0x49] = iVar7;
      iVar7 = FUN_0010b0f4(param_2,1);
      *(undefined4 *)(iVar7 + 0x10) = DAT_001c64f8;
      return 1;
    }
  }
  return 0;
}

/* FUN_000f2af0 @ 0xf2af0 (4111 bytes) */
int FUN_000f2af0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int *param_3;
{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  uint *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  uint uVar16;
  int *local_84;
  int local_6c;
  int local_64;
  int local_54;
  int *local_50;
  undefined4 local_40 [5];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20 [4];
  
  piVar12 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  cVar5 = (**(code **)(*piVar12 + 0xb8))(piVar12);
  if ((((cVar5 == '\0') && ((*(byte *)(param_3 + 5) & 8) == 0)) &&
      (iVar6 = (**(code **)(*param_3 + 0x18))(param_3), iVar6 < 2)) &&
     (iVar6 = (**(code **)(*param_3 + 0x14))(param_3), iVar6 != 0)) {
    local_84 = (int *)FUN_0010b180(param_3,1);
    cVar5 = (**(code **)(*param_3 + 0x68))(param_3);
    if (((cVar5 != '\0') || (cVar5 = (**(code **)(*param_3 + 100))(param_3), cVar5 != '\0')) &&
       (((param_3[0x2e] & 1U) == 0 && ((param_3[0x2e] & 2U) == 0)))) {
      iVar6 = FUN_0010b0f4(param_3,0);
      uVar7 = FUN_000f5fea(*(undefined4 *)(iVar6 + 0x10));
      iVar6 = FUN_0010b0f4(param_3,1);
      local_20[0] = FUN_000f5b96(*(undefined4 *)(iVar6 + 0x10),uVar7);
      cVar5 = ((int (*)())FUN_000ee354)(local_84,local_20[0],*(undefined4 *)(param_1 + 8));
      if (cVar5 != '\0') {
        cVar5 = (**(code **)(*local_84 + 0x60))(local_84);
        if (cVar5 != '\0') {
          local_84 = (int *)FUN_00111dca(local_84,*(undefined4 *)(param_1 + 8));
          FUN_0010ba02(param_3,1,local_84,0,*(undefined4 *)(param_1 + 8));
        }
        iVar6 = param_3[0x26];
        iVar3 = param_3[0x25];
        uVar7 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
        puVar8 = (undefined4 *)FUN_001a7bca(uVar7,0x14);
        *puVar8 = uVar7;
        puVar9 = puVar8 + 1;
        puVar8[4] = uVar7;
        puVar8[2] = 0;
        puVar8[1] = 2;
        uVar7 = FUN_001a7bca(uVar7,8);
        puVar8[3] = uVar7;
        uVar7 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
        puVar10 = (undefined4 *)FUN_001a7bca(uVar7,0x14);
        *puVar10 = uVar7;
        puVar1 = puVar10 + 1;
        puVar10[4] = uVar7;
        puVar10[2] = 0;
        puVar10[1] = 2;
        uVar7 = FUN_001a7bca(uVar7,8);
        puVar10[3] = uVar7;
        uVar16 = puVar8[2];
        if (uVar16 < (uint)puVar8[1]) {
          _memset((void *)(uVar16 * 4 + puVar8[3]),0,4);
          puVar8[2] = uVar16 + 1;
          puVar11 = (undefined4 *)(uVar16 * 4 + puVar8[3]);
        }
        else {
          puVar11 = (undefined4 *)FUN_001a7f7c(puVar9,uVar16);
        }
        iVar13 = local_20[0];
        *puVar11 = local_84;
        uVar16 = puVar10[2];
        if (uVar16 < *puVar1) {
          _memset((void *)(uVar16 * 4 + puVar10[3]),0,4);
          puVar10[2] = uVar16 + 1;
          piVar12 = (int *)(uVar16 * 4 + puVar10[3]);
        }
        else {
          piVar12 = (int *)FUN_001a7f7c(puVar1,uVar16);
        }
        *piVar12 = iVar13;
        *(int *)(param_1 + 0x468) = *(int *)(param_1 + 0x468) + 1;
LAB_000f2d95:
        do {
          while( true ) {
            while( true ) {
              do {
                do {
                  if (puVar8[2] == 0) {
                    (**(code **)(*param_3 + 0xc))(param_3,0,*(undefined4 *)(param_1 + 8));
                    if (puVar9 != (uint *)0x0) {
                      FUN_001a7aba(puVar8[4],puVar8[3]);
                      FUN_001a7aba(*puVar8,puVar8);
                    }
                    if (puVar1 == (uint *)0x0) {
                      return;
                    }
                    FUN_001a7aba(puVar10[4],puVar10[3]);
                    FUN_001a7aba(*puVar10,puVar10);
                    return;
                  }
                  uVar16 = puVar8[2] - 1;
                  if (uVar16 < (uint)puVar8[2]) {
                    puVar11 = (undefined4 *)(puVar8[3] + uVar16 * 4);
                  }
                  else {
                    puVar11 = (undefined4 *)0x0;
                  }
                  local_50 = (int *)*puVar11;
                  FUN_001a7f3c(puVar9,puVar8[2] + -1);
                  uVar16 = puVar10[2] - 1;
                  if (uVar16 < (uint)puVar10[2]) {
                    piVar12 = (int *)(puVar10[3] + uVar16 * 4);
                  }
                  else {
                    piVar12 = (int *)0x0;
                  }
                  iVar13 = *piVar12;
                  FUN_001a7f3c(puVar1,puVar10[2] + -1);
                  local_20[0] = iVar13;
                  cVar5 = ((int (*)())FUN_000ee354)(local_50,iVar13,*(undefined4 *)(param_1 + 8));
                  if ((cVar5 != '\0') &&
                     (cVar5 = (**(code **)(*local_50 + 0x60))(local_50), cVar5 != '\0')) {
                    local_50 = (int *)FUN_00111dca(local_50,*(undefined4 *)(param_1 + 8));
                  }
                } while ((*(int *)(param_1 + 0x468) == local_50[0x54]) &&
                        (*(int *)(local_50[0x22] + 8) == 0x8e));
                local_50[0x54] = *(int *)(param_1 + 0x468);
                cVar5 = (**(code **)(*local_50 + 0x50))(local_50);
              } while (cVar5 != '\0');
              local_24 = local_20[0];
              local_28 = local_20[0];
              iVar13 = FUN_0010b0f4(local_50,0);
              local_2c = *(undefined4 *)(iVar13 + 0x10);
              iVar13 = 1;
              do {
                bVar2 = *(byte *)((int)local_20 + iVar13 + -1);
                if (bVar2 != 4) {
                  if (*(char *)((int)&local_2c + (uint)bVar2) == '\x01') {
                    *(undefined1 *)((int)&local_28 + iVar13 + 3) = 4;
                  }
                  else {
                    *(undefined1 *)((int)&local_2c + iVar13 + 3) = 4;
                  }
                }
                iVar14 = local_28;
                iVar13 = iVar13 + 1;
              } while (iVar13 != 5);
              if (local_24 != DAT_001c64fc) break;
              if (((*(byte *)((int)local_50 + 0x15) & 2) != 0) && (local_24 != local_28)) {
                uVar16 = puVar10[2];
                if (uVar16 < *puVar1) {
                  _memset((void *)(uVar16 * 4 + puVar10[3]),0,4);
                  puVar10[2] = uVar16 + 1;
                  piVar12 = (int *)(uVar16 * 4 + puVar10[3]);
                }
                else {
                  piVar12 = (int *)FUN_001a7f7c(puVar1,uVar16);
                }
                *piVar12 = iVar14;
                uVar7 = FUN_0010b180(local_50,local_50[0x21]);
                uVar16 = puVar8[2];
                if (uVar16 < *puVar9) {
                  _memset((void *)(uVar16 * 4 + puVar8[3]),0,4);
                  puVar8[2] = uVar16 + 1;
                  *(undefined4 *)(uVar16 * 4 + puVar8[3]) = uVar7;
                }
                else {
                  puVar11 = (undefined4 *)FUN_001a7f7c(puVar9,uVar16);
                  *puVar11 = uVar7;
                }
              }
            }
            cVar5 = ((int (*)())FUN_000ee354)(local_50,local_24,*(undefined4 *)(param_1 + 8));
            if (cVar5 != '\0') break;
            ((int (*)())FUN_000ee42a)(param_1,local_50,param_2,iVar6,iVar3,local_20[0]);
          }
          iVar14 = (**(code **)(*local_50 + 0x7c))(local_50);
          iVar13 = local_28;
          if (iVar14 != 0) {
            if (0 < local_50[0x21]) {
              local_6c = 1;
              bVar4 = true;
              do {
                piVar12 = (int *)FUN_0010b180(local_50,local_6c);
                iVar13 = (**(code **)(*piVar12 + 0x7c))(piVar12);
                if ((iVar13 != 0) ||
                   (cVar5 = ((int (*)())FUN_000ee354)(piVar12,local_24,*(undefined4 *)(param_1 + 8)),
                   cVar5 == '\0')) {
                  bVar4 = false;
                }
                local_6c = local_6c + 1;
              } while (local_6c <= local_50[0x21]);
              if (!bVar4) {
                ((int (*)())FUN_000ee42a)(param_1,local_50,param_2,iVar6,iVar3,local_20[0]);
                goto LAB_000f2d95;
              }
            }
            if (0 < local_50[0x21]) {
              local_64 = 1;
              do {
                iVar13 = local_20[0];
                uVar16 = puVar10[2];
                if (uVar16 < *puVar1) {
                  _memset((void *)(uVar16 * 4 + puVar10[3]),0,4);
                  puVar10[2] = uVar16 + 1;
                  piVar12 = (int *)(uVar16 * 4 + puVar10[3]);
                }
                else {
                  piVar12 = (int *)FUN_001a7f7c(puVar1,uVar16);
                }
                *piVar12 = iVar13;
                uVar7 = FUN_0010b180(local_50,local_64);
                uVar16 = puVar8[2];
                if (uVar16 < *puVar9) {
                  _memset((void *)(uVar16 * 4 + puVar8[3]),0,4);
                  puVar8[2] = uVar16 + 1;
                  puVar11 = (undefined4 *)(uVar16 * 4 + puVar8[3]);
                }
                else {
                  puVar11 = (undefined4 *)FUN_001a7f7c(puVar9,uVar16);
                }
                *puVar11 = uVar7;
                local_64 = local_64 + 1;
              } while (local_64 <= local_50[0x21]);
            }
LAB_000f3449:
            (**(code **)(*local_50 + 0xc))(local_50,0,*(undefined4 *)(param_1 + 8));
            goto LAB_000f2d95;
          }
          if (((*(byte *)((int)local_50 + 0x15) & 2) != 0) && (local_28 != DAT_001c64fc)) {
            uVar16 = puVar10[2];
            if (uVar16 < *puVar1) {
              _memset((void *)(uVar16 * 4 + puVar10[3]),0,4);
              puVar10[2] = uVar16 + 1;
              piVar12 = (int *)(uVar16 * 4 + puVar10[3]);
            }
            else {
              piVar12 = (int *)FUN_001a7f7c(puVar1,uVar16);
            }
            *piVar12 = iVar13;
            uVar7 = FUN_0010b180(local_50,local_50[0x21]);
            uVar16 = puVar8[2];
            if (uVar16 < *puVar9) {
              _memset((void *)(uVar16 * 4 + puVar8[3]),0,4);
              puVar8[2] = uVar16 + 1;
              puVar11 = (undefined4 *)(uVar16 * 4 + puVar8[3]);
            }
            else {
              puVar11 = (undefined4 *)FUN_001a7f7c(puVar9,uVar16);
            }
            *puVar11 = uVar7;
            FUN_0010ba02(local_50,local_50[0x21],0,0,*(undefined4 *)(param_1 + 8));
            local_50[0x21] = local_50[0x21] + -1;
            local_50[5] = local_50[5] & 0xfffffdff;
          }
          cVar5 = (**(code **)(*local_50 + 100))(local_50);
          if (cVar5 != '\0') {
            for (iVar13 = 1; iVar14 = (**(code **)(*local_50 + 0x14))(local_50), iVar13 <= iVar14;
                iVar13 = iVar13 + 1) {
              if ((((local_50[iVar13 * 6 + 0x28] & 1U) != 0) ||
                  ((local_50[iVar13 * 6 + 0x28] & 2U) != 0)) ||
                 (cVar5 = FUN_000f5a1e(local_50,iVar13), cVar5 == '\0')) goto LAB_000f35a8;
            }
            if (((char)local_50[0x48] == '\0') && (local_50[0x49] == 0)) {
              if (((local_50[0x20] != 0) &&
                  ((cVar5 = FUN_0012dfd8(local_50[0x26]), cVar5 != '\0' &&
                   ((*(byte *)(local_50 + 5) & 2) == 0)))) &&
                 (cVar5 = (**(code **)(*local_50 + 0x50))(local_50), cVar5 == '\0')) {
                iVar13 = 0;
                piVar12 = local_50;
                do {
                  if ((byte)((char)piVar12[0x27] - 2U) < 2) goto LAB_000f35a8;
                  iVar13 = iVar13 + 1;
                  piVar12 = (int *)((int)piVar12 + 1);
                } while (iVar13 != 4);
              }
              FUN_0010b0f4(local_50,0);
              iVar14 = FUN_0010b7c8(local_50,0);
              iVar13 = local_24;
              if ((iVar14 == 0) && ((*(byte *)(local_50 + 5) & 2) == 0)) {
                uVar7 = *(undefined4 *)(param_1 + 8);
                uVar15 = FUN_0010b180(local_50,1);
                cVar5 = ((int (*)())FUN_000ee354)(uVar15,iVar13,uVar7);
                iVar13 = local_24;
                if (cVar5 != '\0') {
                  uVar16 = puVar10[2];
                  if (uVar16 < *puVar1) {
                    _memset((void *)(uVar16 * 4 + puVar10[3]),0,4);
                    puVar10[2] = uVar16 + 1;
                    piVar12 = (int *)(uVar16 * 4 + puVar10[3]);
                  }
                  else {
                    piVar12 = (int *)FUN_001a7f7c(puVar1,uVar16);
                  }
                  *piVar12 = iVar13;
                  uVar7 = FUN_0010b180(local_50,1);
                  uVar16 = puVar8[2];
                  if (uVar16 < *puVar9) {
                    _memset((void *)(uVar16 * 4 + puVar8[3]),0,4);
                    puVar8[2] = uVar16 + 1;
                    puVar11 = (undefined4 *)(uVar16 * 4 + puVar8[3]);
                  }
                  else {
                    puVar11 = (undefined4 *)FUN_001a7f7c(puVar9,uVar16);
                  }
                  *puVar11 = uVar7;
                  goto LAB_000f3449;
                }
              }
            }
          }
LAB_000f35a8:
          FUN_0010a38c(local_50,param_1,iVar6,iVar3);
          (**(code **)(*local_50 + 0x94))(local_50,param_2,*(undefined4 *)(param_1 + 8));
          iVar13 = FUN_000f5aec(local_24);
          local_50[0x27] = iVar13;
          cVar5 = FUN_000f56f0(local_24,DAT_001c64f8);
          if ((cVar5 == '\0') &&
             (cVar5 = FUN_001195a6(*(undefined4 *)(param_1 + 8),local_50), cVar5 != '\0')) {
            local_54 = 1;
            while (iVar14 = (**(code **)(*local_50 + 0x14))(local_50), iVar13 = local_24,
                  local_54 <= iVar14) {
              iVar14 = FUN_0010b0f4(local_50,local_54);
              iVar13 = FUN_000f5610(*(undefined4 *)(iVar14 + 0x10),iVar13);
              if (local_54 == 0) {
                local_50[0x27] = iVar13;
                local_54 = 1;
              }
              else {
                iVar14 = FUN_0010b0f4(local_50,local_54);
                *(int *)(iVar14 + 0x10) = iVar13;
                local_54 = local_54 + 1;
              }
            }
          }
          cVar5 = (**(code **)(*local_50 + 100))(local_50);
          if (cVar5 != '\0') {
            for (iVar13 = 1; iVar14 = (**(code **)(*local_50 + 0x14))(local_50), iVar13 <= iVar14;
                iVar13 = iVar13 + 1) {
              if ((((local_50[iVar13 * 6 + 0x28] & 1U) != 0) ||
                  ((local_50[iVar13 * 6 + 0x28] & 2U) != 0)) ||
                 (cVar5 = FUN_000f5a1e(local_50,iVar13), cVar5 == '\0')) goto LAB_000f2d95;
            }
            if (((char)local_50[0x48] == '\0') && (local_50[0x49] == 0)) {
              if (((local_50[0x20] != 0) &&
                  ((cVar5 = FUN_0012dfd8(local_50[0x26]), cVar5 != '\0' &&
                   ((*(byte *)(local_50 + 5) & 2) == 0)))) &&
                 (cVar5 = (**(code **)(*local_50 + 0x50))(local_50), cVar5 == '\0')) {
                iVar13 = 0;
                piVar12 = local_50;
                do {
                  if ((byte)((char)piVar12[0x27] - 2U) < 2) goto LAB_000f2d95;
                  iVar13 = iVar13 + 1;
                  piVar12 = (int *)((int)piVar12 + 1);
                } while (iVar13 != 4);
              }
              FUN_0010b0f4(local_50,0);
              iVar13 = FUN_0010b7c8(local_50,0);
              if (iVar13 == 0) {
                piVar12 = (int *)FUN_0010b180(local_50,1);
                cVar5 = (**(code **)(*piVar12 + 0x48))(piVar12);
                if (cVar5 != '\0') {
                  puVar11 = local_40;
                  do {
                    *puVar11 = 0x7ffffffe;
                    puVar11 = puVar11 + 1;
                  } while (local_40 + 4 != puVar11);
                  local_40[3] = 0x3f800000;
                  local_40[2] = 0x3f800000;
                  local_40[1] = 0x3f800000;
                  local_40[0] = 0x3f800000;
                  piVar12 = *(int **)(*(int *)(param_1 + 8) + 0x54);
                  cVar5 = (**(code **)(*piVar12 + 0xe8))
                                    (piVar12,local_40,local_40 + 4,DAT_001c64f8,
                                     *(int *)(param_1 + 8));
                  if (cVar5 != '\0') {
                    ((int (*)())FUN_000f2852)(param_1,local_50);
                  }
                }
              }
            }
          }
        } while( true );
      }
    }
  }
  (**(code **)(*param_3 + 0x94))(param_3,param_2,*(undefined4 *)(param_1 + 8));
  return;
}

/* FUN_000f3b4c @ 0xf3b4c (2406 bytes) */
int FUN_000f3b4c(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  int local_48;
  int *local_30;
  undefined4 local_2c;
  int local_24;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar2,0x168);
  *puVar5 = uVar2;
  FUN_0010ac30(puVar5 + 1,0x93,*(undefined4 *)(param_1 + 8));
  *(undefined4 **)(param_1 + 0x340) = puVar5 + 1;
  puVar5[0x26] = 0;
  puVar5[0x27] = 0x2e;
  *(undefined4 *)(*(int *)(param_1 + 0x340) + 300) = 0;
  cVar4 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x23);
  if (cVar4 == '\0') {
    if ((*(byte *)(param_1 + 0x30) & 1) == 0) {
      return;
    }
    if (param_2 == (int *)0x0) {
      return;
    }
    FUN_000e9540(param_2[0x56],*(undefined4 *)(param_1 + 0x340));
    (**(code **)(*param_2 + 0x94))
              (param_2,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
    if (param_3 == (int *)0x0) {
      return;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x340) + 300) = 1;
  }
  else {
    if ((*(byte *)(param_1 + 0x30) & 1) == 0) {
      return;
    }
    if (param_2 == (int *)0x0) {
      return;
    }
    iVar8 = param_2[0x56];
    if (param_3 == (int *)0x0) {
      piVar10 = (int *)FUN_0010b180(param_2,1);
      iVar9 = FUN_0010b0f4(param_2,1);
      iVar9 = *(int *)(iVar9 + 0x10);
      piVar6 = *(int **)(*(int *)(param_1 + 8) + 0x54);
      cVar4 = (**(code **)(*piVar6 + 0xb8))(piVar6);
      if ((((((cVar4 != '\0') || (iVar7 = (**(code **)(*piVar10 + 0x7c))(piVar10), iVar7 != 0)) ||
            (cVar4 = FUN_001195a6(*(undefined4 *)(param_1 + 8),piVar10), cVar4 == '\0')) ||
           ((iVar7 = piVar10[0x58] - *(int *)(param_1 + 0x46c), -1 < iVar7 && (1 < iVar7)))) ||
          (cVar4 = (**(code **)(*piVar10 + 0x28))(piVar10), cVar4 != '\0')) ||
         ((piVar10[0x21] == 0 || (iVar9 != DAT_001c64f8)))) {
        FUN_000e9f7c(iVar8,*(undefined4 *)(param_1 + 0x340));
        (**(code **)(*param_2 + 0x94))
                  (param_2,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
        return;
      }
      iVar8 = FUN_0010b0f4(param_2,0);
      uVar2 = *(undefined4 *)(iVar8 + 0x10);
      ((int (*)())FUN_000f1b60)(param_1,param_2);
      (**(code **)(*param_2 + 0xc))(param_2,0,*(undefined4 *)(param_1 + 8));
      iVar8 = piVar10[0x56];
      FUN_0010a38c(piVar10,param_1,6,0);
      (**(code **)(*piVar10 + 0x94))
                (piVar10,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
      iVar9 = FUN_0010b0f4(piVar10,0);
      iVar9 = FUN_000f58e8(uVar2,*(undefined4 *)(iVar9 + 0x10));
      bVar1 = *(byte *)((int)piVar10 + 0x15);
      do {
        if ((bVar1 & 2) == 0) {
LAB_000f3eb9:
          FUN_000e9540();
          return;
        }
        piVar6 = (int *)FUN_0010b180(piVar10,piVar10[0x21]);
        FUN_0010ba02(piVar10,piVar10[0x21],0,0,*(undefined4 *)(param_1 + 8));
        piVar10[0x21] = piVar10[0x21] + -1;
        piVar10[5] = piVar10[5] & 0xfffffdff;
        iVar7 = (**(code **)(*piVar6 + 0x7c))(piVar6);
        if ((((iVar7 != 0) ||
             (cVar4 = FUN_001195a6(*(undefined4 *)(param_1 + 8),piVar6), cVar4 == '\0')) ||
            ((iVar7 = piVar6[0x58] - *(int *)(param_1 + 0x46c), -1 < iVar7 && (1 < iVar7)))) ||
           (((iVar8 != piVar6[0x56] ||
             (cVar4 = (**(code **)(*piVar6 + 0x28))(piVar6), cVar4 != '\0')) || (piVar6[0x21] == 0))
           )) {
          piVar11 = (int *)FUN_0010dbb8(0x31,*(undefined4 *)(param_1 + 8));
          FUN_0010ba02(piVar11,1,piVar6,0,*(undefined4 *)(param_1 + 8));
          (**(code **)(*piVar11 + 0x94))
                    (piVar11,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
          FUN_0010a38c(piVar11,param_1,6,0);
          piVar11[0x27] = iVar9;
          FUN_000e956e(iVar8,piVar10,piVar11);
          goto LAB_000f3eb9;
        }
        (**(code **)(*piVar6 + 0x94))
                  (piVar6,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
        FUN_0010a38c(piVar6,param_1,6,0);
        iVar7 = FUN_0010b0f4(piVar6,0);
        iVar9 = FUN_000f58e8(iVar9,*(undefined4 *)(iVar7 + 0x10));
        bVar1 = *(byte *)((int)piVar6 + 0x15);
        piVar10 = piVar6;
      } while( true );
    }
    *(undefined4 *)(*(int *)(param_1 + 0x340) + 300) = 1;
    local_30 = (int *)FUN_0010b180(param_2,1);
    piVar6 = (int *)FUN_0010b180(param_3,1);
    if (((local_30[0x56] == piVar6[0x56]) &&
        (iVar9 = (**(code **)(*local_30 + 0x7c))(local_30), iVar9 == 0)) &&
       ((iVar9 = (**(code **)(*piVar6 + 0x7c))(piVar6), iVar9 == 0 &&
        ((local_30[0x21] != 0 && (piVar6[0x21] != 0)))))) {
      uVar12 = (uint)(1 < *(int *)(param_1 + 0x46c));
      if ((((int)(local_30[0x58] - uVar12) < 0) || (local_30[0x58] == uVar12)) &&
         ((((iVar9 = piVar6[0x58] - *(int *)(param_1 + 0x46c), iVar9 < 0 || (iVar9 < 2)) &&
           (cVar4 = (**(code **)(*local_30 + 0x28))(local_30), cVar4 == '\0')) &&
          (cVar4 = (**(code **)(*piVar6 + 0x28))(piVar6), cVar4 == '\0')))) {
        iVar8 = local_30[0x56];
        iVar9 = FUN_0010b0f4(param_2,0);
        uVar2 = *(undefined4 *)(iVar9 + 0x10);
        iVar9 = FUN_0010b0f4(param_3,0);
        uVar3 = *(undefined4 *)(iVar9 + 0x10);
        ((int (*)())FUN_000f1b60)(param_1,param_3);
        ((int (*)())FUN_000f1b60)(param_1,param_2);
        (**(code **)(*param_2 + 0xc))(param_2,0,*(undefined4 *)(param_1 + 8));
        (**(code **)(*param_3 + 0xc))(param_3,0,*(undefined4 *)(param_1 + 8));
        FUN_000e9540(iVar8,*(undefined4 *)(param_1 + 0x340));
        iVar9 = FUN_0010b0f4(local_30,0);
        local_48 = FUN_000f58e8(uVar2,*(undefined4 *)(iVar9 + 0x10));
        local_2c = 6;
        local_24 = 0;
        do {
          (**(code **)(*local_30 + 0x94))
                    (local_30,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
          FUN_0010a38c(local_30,param_1,local_2c,0);
          bVar1 = *(byte *)((int)local_30 + 0x15);
          while ((bVar1 & 2) != 0) {
            piVar10 = (int *)FUN_0010b180(local_30,local_30[0x21]);
            iVar9 = (**(code **)(*piVar10 + 0x7c))(piVar10);
            if ((((iVar9 != 0) ||
                 (cVar4 = FUN_001195a6(*(undefined4 *)(param_1 + 8),piVar10), cVar4 == '\0')) ||
                ((iVar9 = piVar10[0x58] - *(int *)(param_1 + 0x46c), -1 < iVar9 && (1 < iVar9)))) ||
               (((iVar8 != piVar10[0x56] ||
                 (cVar4 = (**(code **)(*piVar10 + 0x28))(piVar10), cVar4 != '\0')) ||
                (piVar10[0x21] == 0)))) {
              piVar11 = (int *)FUN_0010dbb8(0x31,*(undefined4 *)(param_1 + 8));
              FUN_0010ba02(piVar11,1,piVar10,0,*(undefined4 *)(param_1 + 8));
              FUN_0010a38c(piVar11,param_1,local_2c,0);
              (**(code **)(*piVar11 + 0x94))
                        (piVar11,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
              piVar11[0x27] = local_48;
              FUN_000e956e(iVar8,local_30,piVar11);
              break;
            }
            (**(code **)(*piVar10 + 0x94))
                      (piVar10,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
            FUN_0010a38c(piVar10,param_1,local_2c,0);
            iVar9 = FUN_0010b0f4(piVar10,0);
            local_48 = FUN_000f58e8(local_48,*(undefined4 *)(iVar9 + 0x10));
            local_30 = piVar10;
            bVar1 = *(byte *)((int)piVar10 + 0x15);
          }
          iVar9 = FUN_0010b0f4(piVar6,0);
          local_48 = FUN_000f58e8(uVar3,*(undefined4 *)(iVar9 + 0x10));
          local_24 = local_24 + 1;
          local_2c = 7;
          local_30 = piVar6;
          if (local_24 == 2) {
            return;
          }
        } while( true );
      }
    }
    FUN_000e9f7c(iVar8,*(undefined4 *)(param_1 + 0x340));
    (**(code **)(*param_2 + 0x94))
              (param_2,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
  }
  (**(code **)(*param_3 + 0x94))
            (param_3,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
  return;
}

/* FUN_000f44d0 @ 0xf44d0 (3841 bytes) */
int FUN_000f44d0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int *param_3;
{
  uint uVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int *local_94;
  int local_88;
  int *local_60;
  uint local_5c;
  uint local_58;
  int local_54;
  undefined4 local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  undefined4 local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  undefined4 local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  undefined4 local_20;
  
  *(int *)(param_1 + 0x468) = *(int *)(param_1 + 0x468) + 1;
  iVar12 = param_3[0x26];
  iVar2 = param_3[0x25];
  local_20 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_28 = 0;
  local_2c = 2;
  local_24 = FUN_001a7bca(local_20,8);
  local_30 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_38 = 0;
  local_3c = 2;
  local_34 = FUN_001a7bca(local_30,8);
  local_40 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_48 = 0;
  local_4c = 2;
  local_44 = FUN_001a7bca(local_40,8);
  local_50 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_58 = 0;
  local_5c = 2;
  local_54 = FUN_001a7bca(local_50,8);
  uVar8 = local_28;
  if (local_28 < local_2c) {
    iVar7 = local_28 * 4;
    _memset((void *)(iVar7 + local_24),0,4);
    local_28 = uVar8 + 1;
    puVar5 = (undefined4 *)(iVar7 + local_24);
  }
  else {
    puVar5 = (undefined4 *)FUN_001a7f7c(&local_2c,local_28);
  }
  uVar8 = local_38;
  *puVar5 = param_3;
  if (local_38 < local_3c) {
    iVar7 = local_38 * 4;
    _memset((void *)(iVar7 + local_34),0,4);
    local_38 = uVar8 + 1;
    puVar5 = (undefined4 *)(iVar7 + local_34);
  }
  else {
    puVar5 = (undefined4 *)FUN_001a7f7c(&local_3c,local_38);
  }
  *puVar5 = 1;
  local_94 = (int *)FUN_0010b180(param_3,1);
  bVar3 = true;
  uVar8 = local_28;
LAB_000f4778:
  if (uVar8 == 0) {
    iVar7 = FUN_0010b0f4(param_3,0);
    uVar8 = FUN_000f5fea(*(undefined4 *)(iVar7 + 0x10));
    while (local_48 != 0) {
      uVar1 = local_48 - 1;
      if (uVar1 < local_48) {
        piVar6 = (int *)(local_44 + uVar1 * 4);
      }
      else {
        piVar6 = (int *)0x0;
      }
      piVar6 = (int *)*piVar6;
      FUN_001a7f3c(&local_4c,uVar1);
      uVar1 = local_58 - 1;
      if (uVar1 < local_58) {
        piVar10 = (int *)(local_54 + uVar1 * 4);
      }
      else {
        piVar10 = (int *)0x0;
      }
      iVar7 = *piVar10;
      FUN_001a7f3c(&local_5c,uVar1);
      piVar10 = (int *)FUN_0010b180(piVar6,iVar7);
      if ((piVar10[0x26] != iVar12) &&
         (cVar4 = (**(code **)(*piVar10 + 0x50))(piVar10), cVar4 == '\0')) {
        uVar1 = piVar10[3];
        iVar9 = FUN_0010dbb8(0x31,*(undefined4 *)(param_1 + 8));
        FUN_0010ba02(iVar9,1,piVar10,0,*(undefined4 *)(param_1 + 8));
        FUN_0010a38c(iVar9,param_1,iVar12,iVar2);
        uVar11 = FUN_000f5a44(DAT_001c64f4,uVar8 & uVar1);
        *(undefined4 *)(iVar9 + 0x9c) = uVar11;
        FUN_000f6af0(iVar9,1,param_1);
        cVar4 = FUN_0010b1aa(piVar6);
        if (cVar4 == '\0') {
          iVar13 = (**(code **)(*piVar6 + 0x7c))(piVar6);
          if (iVar13 == 0) {
            FUN_0010ba02(piVar6,iVar7,iVar9,0,*(undefined4 *)(param_1 + 8));
            FUN_000e956e(piVar6[0x56],piVar6,iVar9);
          }
          else {
            FUN_0010ba02(piVar6,iVar7,iVar9,0,*(undefined4 *)(param_1 + 8));
            uVar11 = FUN_000eac0c(piVar6[0x56],iVar7 + -1);
            FUN_000e9512(uVar11,iVar9);
          }
        }
        else {
          FUN_0010c18e(piVar6,iVar9,0,*(undefined4 *)(param_1 + 8));
          FUN_000e9596(piVar10[0x56],piVar10,iVar9);
        }
      }
    }
    iVar12 = FUN_0010b180(param_3,1);
    uVar8 = uVar8 & *(uint *)(iVar12 + 0xc);
    iVar12 = FUN_000f5a44(DAT_001c64f4,uVar8);
    param_3[0x27] = iVar12;
    FUN_000f6af0(param_3,1,param_1);
    if (uVar8 == 0) {
      (**(code **)(*param_3 + 0xc))(param_3,0,*(undefined4 *)(param_1 + 8));
    }
    else {
      ((int (*)())FUN_000f2af0)(param_1,param_2,param_3);
    }
    FUN_001a7aba(local_50,local_54);
    FUN_001a7aba(local_40,local_44);
    FUN_001a7aba(local_30,local_34);
    FUN_001a7aba(local_20,local_24);
    return;
  }
  if (!bVar3) {
    uVar1 = uVar8 - 1;
    local_60 = (int *)MACH_HEADER.magic;
    if (uVar1 < uVar8) {
      local_60 = *(int **)(local_24 + uVar1 * 4);
    }
    if (local_94 != (int *)0x0) {
      uVar8 = local_38 - 1;
      if (uVar8 < local_38) {
        piVar6 = (int *)(local_34 + uVar8 * 4);
      }
      else {
        piVar6 = (int *)0x0;
      }
      if (*piVar6 != local_60[0x21]) {
        if (uVar8 < local_38) {
          piVar6 = (int *)(local_34 + uVar8 * 4);
        }
        else {
          piVar6 = (int *)0x0;
        }
        iVar7 = *piVar6;
        FUN_001a7f3c(&local_3c,uVar8);
        uVar8 = local_38;
        if (local_38 < local_3c) {
          iVar9 = local_38 * 4;
          _memset((void *)(iVar9 + local_34),0,4);
          local_38 = uVar8 + 1;
          piVar6 = (int *)(iVar9 + local_34);
        }
        else {
          piVar6 = (int *)FUN_001a7f7c(&local_3c,local_38);
        }
        *piVar6 = iVar7 + 1;
        local_60 = (int *)FUN_0010b180(local_60,iVar7 + 1);
        goto LAB_000f4764;
      }
    }
    FUN_001a7f3c(&local_2c,uVar1);
    FUN_001a7f3c(&local_3c,local_38 - 1);
    iVar7 = FUN_0010b0f4(local_60,0);
    uVar8 = FUN_000f5fea(*(undefined4 *)(iVar7 + 0x10));
    cVar4 = FUN_0010b1aa(local_60);
    if (cVar4 == '\0') {
      iVar7 = (**(code **)(*local_60 + 0x7c))(local_60);
      if (iVar7 == 0) {
        cVar4 = FUN_0010abd6(local_60);
        if (cVar4 != '\0') {
          iVar7 = FUN_0010b180(local_60,2);
          iVar9 = FUN_0010b180(local_60,3);
          if ((uVar8 & ~*(uint *)(iVar7 + 0xc)) == 0) {
            if ((uVar8 & ~*(uint *)(iVar9 + 0xc)) == 0) goto LAB_000f49d7;
            FUN_001110c0(local_60,3,*(undefined4 *)(param_1 + 8));
            FUN_0010a38c(local_60,param_1,iVar12,iVar2);
            uVar1 = local_48;
            if (local_48 < local_4c) {
              iVar7 = local_48 * 4;
              _memset((void *)(iVar7 + local_44),0,4);
              local_48 = uVar1 + 1;
              puVar5 = (undefined4 *)(iVar7 + local_44);
            }
            else {
              puVar5 = (undefined4 *)FUN_001a7f7c(&local_4c,local_48);
            }
            uVar1 = local_58;
            *puVar5 = local_60;
            if (local_58 < local_5c) {
              iVar7 = local_58 * 4;
              _memset((void *)(iVar7 + local_54),0,4);
              local_58 = uVar1 + 1;
              puVar5 = (undefined4 *)(iVar7 + local_54);
            }
            else {
              puVar5 = (undefined4 *)FUN_001a7f7c(&local_5c,local_58);
            }
          }
          else {
            FUN_001110c0(local_60,2,*(undefined4 *)(param_1 + 8));
            FUN_0010a38c(local_60,param_1,iVar12,iVar2);
            uVar1 = local_48;
            if (local_48 < local_4c) {
              iVar7 = local_48 * 4;
              _memset((void *)(iVar7 + local_44),0,4);
              local_48 = uVar1 + 1;
              puVar5 = (undefined4 *)(iVar7 + local_44);
            }
            else {
              puVar5 = (undefined4 *)FUN_001a7f7c(&local_4c,local_48);
            }
            uVar1 = local_58;
            *puVar5 = local_60;
            if (local_58 < local_5c) {
              iVar7 = local_58 * 4;
              _memset((void *)(iVar7 + local_54),0,4);
              local_58 = uVar1 + 1;
              puVar5 = (undefined4 *)(iVar7 + local_54);
            }
            else {
              puVar5 = (undefined4 *)FUN_001a7f7c(&local_5c,local_58);
            }
          }
          *puVar5 = 3;
          local_60[3] = 0;
        }
LAB_000f49d7:
        if ((*(byte *)((int)local_60 + 0x15) & 2) != 0) {
          iVar7 = FUN_0010b180(local_60,local_60[0x21]);
          local_60[3] = uVar8 | *(uint *)(iVar7 + 0xc);
          if (*(int *)(iVar7 + 0x98) == iVar12) {
            FUN_0010ba02(local_60,local_60[0x21],0,0,*(undefined4 *)(param_1 + 8));
            local_60[0x21] = local_60[0x21] + -1;
            local_60[5] = local_60[5] & 0xfffffdff;
          }
        }
        goto LAB_000f4a46;
      }
      if (local_60[0x21] < 1) goto LAB_000f4a46;
      iVar7 = 1;
      do {
        iVar9 = FUN_0010b180(local_60,iVar7);
        if ((uVar8 & ~*(uint *)(iVar9 + 0xc)) != 0) {
          FUN_0010a38c(local_60,param_1,iVar12,iVar2);
          local_60[3] = 0;
          if (local_60[0x21] < 1) goto LAB_000f4a46;
          local_88 = 1;
          goto LAB_000f4d77;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 <= local_60[0x21]);
      bVar3 = false;
      uVar8 = local_28;
      goto LAB_000f476f;
    }
    FUN_0010a38c(local_60,param_1,iVar12,iVar2);
    iVar7 = FUN_0010b180(local_60,local_60[0x21]);
    uVar1 = local_48;
    local_60[3] = 0;
    if ((*(uint *)(iVar7 + 0xc) & uVar8) != 0) {
      if (local_48 < local_4c) {
        iVar7 = local_48 * 4;
        _memset((void *)(iVar7 + local_44),0,4);
        local_48 = uVar1 + 1;
        puVar5 = (undefined4 *)(iVar7 + local_44);
      }
      else {
        puVar5 = (undefined4 *)FUN_001a7f7c(&local_4c,local_48);
      }
      uVar8 = local_58;
      *puVar5 = local_60;
      iVar7 = local_60[0x21];
      if (local_58 < local_5c) {
        iVar9 = local_58 * 4;
        _memset((void *)(iVar9 + local_54),0,4);
        local_58 = uVar8 + 1;
        piVar6 = (int *)(iVar9 + local_54);
      }
      else {
        piVar6 = (int *)FUN_001a7f7c(&local_5c,local_58);
      }
      *piVar6 = iVar7;
      bVar3 = false;
      uVar8 = local_28;
      goto LAB_000f476f;
    }
    goto LAB_000f4a46;
  }
  if (local_94 == (int *)0x0) {
    local_60 = (int *)0x0;
    bVar3 = false;
  }
  else if (*(int *)(param_1 + 0x468) == local_94[0x54]) {
LAB_000f49a9:
    local_60 = local_94;
    bVar3 = false;
  }
  else {
    local_94[0x54] = *(int *)(param_1 + 0x468);
    iVar7 = FUN_0010b0f4(local_94,0);
    iVar7 = FUN_000f5fea(*(undefined4 *)(iVar7 + 0x10));
    local_94[3] = iVar7;
    iVar7 = (**(code **)(*local_94 + 0x7c))(local_94);
    uVar8 = local_28;
    if (iVar7 == 0) {
      cVar4 = FUN_0010abd6(local_94);
      uVar8 = local_28;
      if (cVar4 == '\0') {
        if ((*(byte *)((int)local_94 + 0x15) & 2) == 0) goto LAB_000f49a9;
        if (local_28 < local_2c) {
          iVar7 = local_28 * 4;
          _memset((void *)(iVar7 + local_24),0,4);
          local_28 = uVar8 + 1;
          puVar5 = (undefined4 *)(iVar7 + local_24);
        }
        else {
          puVar5 = (undefined4 *)FUN_001a7f7c(&local_2c,local_28);
        }
        uVar8 = local_38;
        *puVar5 = local_94;
        iVar7 = local_94[0x21];
        if (local_38 < local_3c) {
          iVar9 = local_38 * 4;
          _memset((void *)(iVar9 + local_34),0,4);
          local_38 = uVar8 + 1;
          piVar6 = (int *)(iVar9 + local_34);
        }
        else {
          piVar6 = (int *)FUN_001a7f7c(&local_3c,local_38);
        }
        *piVar6 = iVar7;
        local_60 = (int *)FUN_0010b180(local_94,local_94[0x21]);
      }
      else {
        if (local_28 < local_2c) {
          iVar7 = local_28 * 4;
          _memset((void *)(iVar7 + local_24),0,4);
          local_28 = uVar8 + 1;
          puVar5 = (undefined4 *)(iVar7 + local_24);
        }
        else {
          puVar5 = (undefined4 *)FUN_001a7f7c(&local_2c,local_28);
        }
        uVar8 = local_38;
        *puVar5 = local_94;
        if (local_38 < local_3c) {
          iVar7 = local_38 * 4;
          _memset((void *)(iVar7 + local_34),0,4);
          local_38 = uVar8 + 1;
          puVar5 = (undefined4 *)(iVar7 + local_34);
        }
        else {
          puVar5 = (undefined4 *)FUN_001a7f7c(&local_3c,local_38);
        }
        *puVar5 = 2;
        local_60 = (int *)FUN_0010b180(local_94,2);
      }
    }
    else {
      if (local_28 < local_2c) {
        iVar7 = local_28 * 4;
        _memset((void *)(iVar7 + local_24),0,4);
        local_28 = uVar8 + 1;
        puVar5 = (undefined4 *)(iVar7 + local_24);
      }
      else {
        puVar5 = (undefined4 *)FUN_001a7f7c(&local_2c,local_28);
      }
      uVar8 = local_38;
      *puVar5 = local_94;
      if (local_38 < local_3c) {
        iVar7 = local_38 * 4;
        _memset((void *)(iVar7 + local_34),0,4);
        local_38 = uVar8 + 1;
        puVar5 = (undefined4 *)(iVar7 + local_34);
      }
      else {
        puVar5 = (undefined4 *)FUN_001a7f7c(&local_3c,local_38);
      }
      *puVar5 = 1;
      local_60 = (int *)FUN_0010b180(local_94,1);
    }
LAB_000f4764:
    bVar3 = true;
    uVar8 = local_28;
  }
  goto LAB_000f476f;
LAB_000f4d77:
  do {
    iVar7 = FUN_0010b180(local_60,local_88);
    uVar1 = local_48;
    if ((*(uint *)(iVar7 + 0xc) & uVar8) != 0) {
      if (local_48 < local_4c) {
        iVar7 = local_48 * 4;
        _memset((void *)(iVar7 + local_44),0,4);
        local_48 = uVar1 + 1;
        *(int **)(iVar7 + local_44) = local_60;
        if (local_58 < local_5c) goto LAB_000f4d23;
LAB_000f4dc6:
        piVar6 = (int *)FUN_001a7f7c(&local_5c,local_58);
      }
      else {
        puVar5 = (undefined4 *)FUN_001a7f7c(&local_4c,local_48);
        *puVar5 = local_60;
        if (local_5c <= local_58) goto LAB_000f4dc6;
LAB_000f4d23:
        uVar1 = local_58;
        iVar7 = local_58 * 4;
        _memset((void *)(iVar7 + local_54),0,4);
        local_58 = uVar1 + 1;
        piVar6 = (int *)(iVar7 + local_54);
      }
      *piVar6 = local_88;
    }
    local_88 = local_88 + 1;
  } while (local_88 <= local_60[0x21]);
LAB_000f4a46:
  bVar3 = false;
  uVar8 = local_28;
LAB_000f476f:
  local_94 = local_60;
  goto LAB_000f4778;
}

/* FUN_000f5430 @ 0xf5430 (478 bytes) */
int FUN_000f5430(param_1)
  int param_1;
{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  int *local_28;
  int *local_24;
  int local_20;
  
  FUN_00113e28(param_1);
  ((int (*)())FUN_000f0346)(param_1,"assign_slots");
  piVar4 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  cVar3 = (**(code **)(*piVar4 + 0xd8))(piVar4);
  if (cVar3 == '\0') {
    ((int (*)())FUN_000ee5a8)(param_1);
    piVar4 = *(int **)(*(int *)(param_1 + 0x39c) + 0x98);
    for (piVar5 = (int *)piVar4[2]; piVar5 != (int *)0x0; piVar5 = (int *)piVar5[2]) {
      cVar3 = (**(code **)(*piVar4 + 0x68))(piVar4);
      if (cVar3 != '\0') {
        if ((char)piVar4[0x51] == '\0') {
          ((int (*)())FUN_000f2af0)(param_1,*(undefined4 *)(param_1 + 0x33c),piVar4);
        }
        else {
          ((int (*)())FUN_000f44d0)(param_1,*(undefined4 *)(param_1 + 0x33c),piVar4);
        }
      }
      piVar4 = piVar5;
    }
  }
  else {
    ((int (*)())FUN_000ee170)(param_1);
    ((int (*)())FUN_000f20a2)(param_1);
    piVar4 = *(int **)(*(int *)(param_1 + 0x39c) + 0x98);
    piVar5 = (int *)piVar4[2];
    if (piVar5 == (int *)0x0) {
      local_20 = 0;
      local_28 = (int *)0x0;
      local_24 = (int *)0x0;
    }
    else {
      local_20 = 0;
      local_28 = (int *)0x0;
      local_24 = (int *)0x0;
      do {
        cVar3 = (**(code **)(*piVar4 + 0x68))(piVar4);
        piVar1 = local_28;
        piVar2 = local_24;
        if (((cVar3 == '\0') || (piVar1 = piVar4, piVar4[0x4f] == 6)) ||
           (piVar1 = local_28, piVar2 = piVar4, piVar4[0x4f] == 7)) {
          local_24 = piVar2;
          local_28 = piVar1;
          piVar1 = (int *)piVar5[2];
        }
        else {
          local_20 = local_20 + 1;
          ((int (*)())FUN_000f2af0)(param_1,*(undefined4 *)(param_1 + 0x33c),piVar4);
          piVar1 = (int *)piVar5[2];
        }
        piVar4 = piVar5;
        piVar5 = piVar1;
      } while (piVar1 != (int *)0x0);
      if (local_20 == 0) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + -1;
      }
    }
    *(int *)(*(int *)(param_1 + 0x33c) + 300) = local_20;
    if (local_28 != (int *)0x0) {
      ((int (*)())FUN_000f3b4c)(param_1,local_28,local_24);
    }
  }
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x800;
  ((int (*)())FUN_000edab6)(param_1);
  ((int (*)())FUN_000f0346)(param_1,"mark_io");
  return;
}

