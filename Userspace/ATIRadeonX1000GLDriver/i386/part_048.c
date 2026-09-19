#include "decls.h"

/* FUN_00188a68 @ 0x188a68 (453 bytes) */
int FUN_00188a68(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int local_44;
  int local_40;
  int local_2c [7];
  
  if (*(int *)(param_1 + 0x30 + param_2 * 4) == 0) {
    iVar7 = param_1 + 0x168 + param_2 * 4;
    local_40 = 1;
    piVar5 = *(int **)(param_1 + 0xb0);
    local_44 = 0x98;
    piVar6 = local_2c;
    for (; piVar6 = (int *)((int)piVar6 + 4), iVar2 = (**(code **)(*piVar5 + 0x14))(piVar5),
        local_40 <= iVar2; local_40 = local_40 + 1) {
      iVar2 = *(int *)(iVar7 + 0x10);
      if (iVar2 < 0) {
        puVar3 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar2);
        iVar2 = ((undefined4 (*)())FUN_00186b4a)(*puVar3);
        piVar6[0xffffffff] = iVar2;
        piVar5 = *(int **)(param_1 + 0xb0);
      }
      else if (iVar2 < 1) {
        piVar6[0xffffffff] = 0;
        piVar5 = *(int **)(param_1 + 0xb0);
      }
      else {
        iVar2 = FUN_001836c0(*(undefined4 *)(param_1 + 0x238),iVar2);
        iVar2 = *(int *)(iVar2 + 0x10);
        piVar6[0xffffffff] = iVar2;
        piVar5 = *(int **)(param_1 + 0xb0);
        uVar1 = *(uint *)((int)piVar5 + local_44 + 0x20);
        if ((uVar1 & 2) != 0) {
          piVar6[0xffffffff] = *(int *)(&DAT_001f9074 + iVar2 * 4);
          uVar1 = *(uint *)((int)piVar5 + local_44 + 0x20);
        }
        if ((uVar1 & 1) != 0) {
          piVar6[0xffffffff] = *(int *)(&DAT_001f905c + piVar6[0xffffffff] * 4);
        }
      }
      local_44 = local_44 + 0x18;
      iVar7 = iVar7 + 0x10;
    }
    iVar7 = *(int *)(param_1 + 0xb0);
    switch(*(undefined4 *)(*(int *)(iVar7 + 0x88) + 8)) {
    case 0x12:
      local_2c[0] = *(int *)((local_2c[1] + local_2c[0] * 6) * 4 + 0x1f8a60);
      break;
    case 0x13:
      local_2c[0] = *(int *)((local_2c[1] + local_2c[0] * 6) * 4 + 0x1f8920);
      break;
    default:
      local_2c[0] = 0;
      break;
    case 0x17:
      local_2c[0] = *(int *)((local_2c[1] + local_2c[0] * 6) * 4 + 0x1f8880);
      break;
    case 0x19:
      local_2c[0] = *(int *)((local_2c[1] + local_2c[0] * 6) * 4 + 0x1f87e0);
      break;
    case 0x24:
    case 0x25:
    case 0x26:
      local_2c[0] = *(int *)((local_2c[2] + local_2c[1] * 6) * 4 + 0x1f89c0);
      break;
    case 0x31: ;
    }
    if ((0 < *(int *)(iVar7 + 0x124)) && (local_2c[0] != 2)) {
      local_2c[0] = 0;
    }
    if (*(char *)(iVar7 + 0x120) != '\0') {
      iVar7 = (DAT_001f9044)[local_2c[0]];
      if (local_2c[0] == iVar7) {
        *(undefined1 *)(param_3 + param_2) = 0;
      }
      else {
        *(undefined1 *)(param_2 + param_3) = 1;
        local_2c[0] = iVar7;
      }
    }
    if (*(int *)(param_1 + 0x40 + param_2 * 4) == 0) {
      uVar4 = FUN_001851d0(*(undefined4 *)(param_1 + 0x238),param_2,param_1);
      *(undefined4 *)(param_1 + 0x40 + param_2 * 4) = uVar4;
    }
    *(int *)(*(int *)(param_1 + 0x40 + param_2 * 4) + 0x10) = local_2c[0];
    return;
  }
  return;
}

/* FUN_00188d2e @ 0x188d2e (178 bytes) */
int FUN_00188d2e(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  byte bVar2;
  int iVar3;
  
  (**(code **)(**(int **)(param_1 + 0xb0) + 0x48))(*(int **)(param_1 + 0xb0));
  uVar1 = *(undefined4 *)(param_2 * 0x18 + *(int *)(param_1 + 0xb0) + 0x20);
  iVar3 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),uVar1);
  if ((((*(char *)(iVar3 + 8) == '\0') || (bVar2 = *(byte *)(iVar3 + 9), (bVar2 & 1) != 0)) ||
      ((bVar2 & 2) != 0)) || (((bVar2 & 4) != 0 || ((bVar2 & 8) != 0)))) {
    *(undefined1 *)(iVar3 + 8) = 2;
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
    *(int *)(iVar3 + 0x10) = param_2;
    *(undefined4 *)(iVar3 + 0x14) = uVar1;
    *(undefined1 *)(iVar3 + 9) = 0;
    *(undefined1 *)(iVar3 + 0x18) = 0;
    *(undefined4 *)(iVar3 + 0x1c) = 0;
    FUN_00186ab4(iVar3,*(undefined4 *)(param_1 + 0x238));
  }
  return iVar3;
}

/* FUN_00188de0 @ 0x188de0 (551 bytes) */
int FUN_00188de0(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar4 = FUN_0010f654(0xa2,*(undefined4 *)(param_1 + 0x238));
  iVar6 = *(int *)(*(int *)(param_1 + 0x238) + 0xf4) + -1;
  *(int *)(*(int *)(param_1 + 0x238) + 0xf4) = iVar6;
  iVar6 = FUN_0012eb84(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x3a0),0x36,
                       iVar6,0);
  FUN_0012a42e(iVar6,iVar4);
  piVar1 = *(int **)(*(int *)(param_1 + 0xb0) + 0x158);
  cVar3 = (**(code **)(*piVar1 + 0x24))(piVar1);
  if (cVar3 == '\0') {
    FUN_000e956e(piVar1,*(undefined4 *)(param_1 + 0xb0),iVar4);
  }
  else {
    FUN_000e9512(piVar1[1],iVar4);
  }
  if (*(int *)(*(int *)(iVar6 + 0x2c) + 4) == 0) {
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x238) + 0xbc);
    puVar5 = (undefined4 *)FUN_001a7bca(uVar2,0x240);
    *puVar5 = uVar2;
    FUN_00183c52(puVar5 + 1,iVar4,*(undefined4 *)(param_1 + 0x238));
    FUN_000eb51a(piVar1,iVar6,puVar5 + 1);
  }
  *(undefined4 *)(iVar4 + 0x84) = 1;
  *(undefined4 *)(iVar4 + 300) = 1;
  FUN_0010a3c2(iVar4,0,iVar6);
  uVar2 = *(undefined4 *)(param_2 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c);
  FUN_0010a3c2(iVar4,1,uVar2);
  FUN_0012a9e6(uVar2,1,iVar4);
  FUN_0010ba02(iVar4,1,*(undefined4 *)(param_1 + 0x210 + param_2 * 4),0,
               *(undefined4 *)(param_1 + 0x238));
  FUN_0010a3c2(*(undefined4 *)(param_1 + 0xb0),param_2,iVar6);
  FUN_0012a9e6(iVar6,param_2,*(undefined4 *)(param_1 + 0xb0));
  *(int *)(param_1 + 0x210 + param_2 * 4) = iVar4;
  return iVar4;
}

/* FUN_00189024 @ 0x189024 (125 bytes) */
int FUN_00189024(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xb0);
  if (((*(byte *)(iVar1 + 0xb8) & 1) != 0) && ((*(byte *)(iVar1 + 0xd0) & 1) != 0)) {
    FUN_00109c0e(iVar1 + 0xa4,1,0);
    FUN_00109c0e(*(int *)(param_1 + 0xb0) + 0xbc,1,0);
    FUN_00184a5a(param_1);
    return 1;
  }
  return 0;
}

/* FUN_001890a2 @ 0x1890a2 (518 bytes) */
int FUN_001890a2(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158);
  iVar3 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_0010a3c2(iVar3,0,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c));
  *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(iVar3 + 0x14c);
  *(undefined4 *)(iVar3 + 0x98) = 0;
  *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(PTR_DAT_0021345d + param_3 * 4);
  FUN_0010a3c2(iVar3,1,*(undefined4 *)(param_2 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c));
  iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),param_2);
  uVar2 = *(undefined4 *)(PTR_DAT_00213485 + (uint)*(byte *)(param_3 + 0x10 + iVar4) * 4);
  iVar4 = FUN_0010b0f4(iVar3,1);
  *(undefined4 *)(iVar4 + 0x10) = uVar2;
  iVar4 = param_2 * 0x18 + 0x80;
  FUN_00109c0e(iVar3 + 0xa4,2,*(uint *)(*(int *)(param_1 + 0xb0) + 0x20 + iVar4) >> 1 & 1);
  FUN_00109c0e(iVar3 + 0xa4,1,*(byte *)(*(int *)(param_1 + 0xb0) + 0x20 + iVar4) & 1);
  *(undefined1 *)(iVar3 + 0x120) = *(undefined1 *)(*(int *)(param_1 + 0xb0) + 0x120);
  *(undefined4 *)(iVar3 + 0x124) = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
  FUN_0010a6a6(iVar3,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c),
               *(undefined4 *)(param_1 + 0x238));
  *(undefined1 *)(param_3 + 0x9c + *(int *)(param_1 + 0xb0)) = 1;
  iVar4 = *(int *)(param_1 + 0xb0);
  if ((*(byte *)(iVar4 + 0x15) & 2) == 0) {
    FUN_0010a6a6(iVar4,*(undefined4 *)(iVar4 + 0x8c),*(undefined4 *)(param_1 + 0x238));
    iVar4 = *(int *)(param_1 + 0xb0);
  }
  FUN_000e9596(uVar1,iVar4,iVar3);
  return iVar3;
}

/* FUN_001892a8 @ 0x1892a8 (414 bytes) */
int FUN_001892a8(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158);
  iVar3 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_0010a3c2(iVar3,0,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c));
  *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(iVar3 + 0x14c);
  *(undefined4 *)(iVar3 + 0x98) = 0;
  *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(PTR_DAT_0021345d + param_3 * 4);
  FUN_0010a3c2(iVar3,1,*(undefined4 *)(param_2 + 0xc));
  uVar2 = *(undefined4 *)(PTR_DAT_00213485 + *(int *)(param_2 + 0x10) * 4);
  iVar4 = FUN_0010b0f4(iVar3,1);
  *(undefined4 *)(iVar4 + 0x10) = uVar2;
  if (*(char *)(param_2 + 0x18) != '\0') {
    FUN_00109c0e(iVar3 + 0xa4,1,1);
  }
  *(undefined1 *)(iVar3 + 0x120) = *(undefined1 *)(*(int *)(param_1 + 0xb0) + 0x120);
  *(undefined4 *)(iVar3 + 0x124) = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
  FUN_0010a6a6(iVar3,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c),
               *(undefined4 *)(param_1 + 0x238));
  *(undefined1 *)(param_3 + 0x9c + *(int *)(param_1 + 0xb0)) = 1;
  iVar4 = *(int *)(param_1 + 0xb0);
  if ((*(byte *)(iVar4 + 0x15) & 2) == 0) {
    FUN_0010a6a6(iVar4,*(undefined4 *)(iVar4 + 0x8c),*(undefined4 *)(param_1 + 0x238));
    iVar4 = *(int *)(param_1 + 0xb0);
  }
  FUN_000e9596(uVar1,iVar4,iVar3);
  return iVar3;
}

/* FUN_00189446 @ 0x189446 (718 bytes) */
int FUN_00189446(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  int param_5;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158);
  iVar3 = FUN_0010a17a(param_2,*(undefined4 *)(param_1 + 0x238));
  FUN_0010a3c2(iVar3,0,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c));
  *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(iVar3 + 0x14c);
  *(undefined4 *)(iVar3 + 0x98) = 0;
  *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(PTR_DAT_0021345d + param_5 * 4);
  FUN_0010a3c2(iVar3,1,*(undefined4 *)(param_3 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c));
  iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),param_3);
  uVar2 = *(undefined4 *)(PTR_DAT_00213485 + (uint)*(byte *)(param_5 + 0x10 + iVar4) * 4);
  iVar4 = FUN_0010b0f4(iVar3,1);
  *(undefined4 *)(iVar4 + 0x10) = uVar2;
  iVar4 = param_3 * 0x18 + 0x80;
  FUN_00109c0e(iVar3 + 0xa4,2,*(uint *)(*(int *)(param_1 + 0xb0) + 0x20 + iVar4) >> 1 & 1);
  FUN_00109c0e(iVar3 + 0xa4,1,*(byte *)(*(int *)(param_1 + 0xb0) + 0x20 + iVar4) & 1);
  FUN_0010a3c2(iVar3,2,*(undefined4 *)(param_4 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c));
  iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),param_4);
  uVar2 = *(undefined4 *)(PTR_DAT_00213485 + (uint)*(byte *)(param_5 + 0x10 + iVar4) * 4);
  iVar4 = FUN_0010b0f4(iVar3,2);
  *(undefined4 *)(iVar4 + 0x10) = uVar2;
  iVar4 = param_4 * 0x18 + 0x80;
  FUN_00109c0e(iVar3 + 0xbc,2,*(uint *)(*(int *)(param_1 + 0xb0) + 0x20 + iVar4) >> 1 & 1);
  FUN_00109c0e(iVar3 + 0xbc,1,*(byte *)(*(int *)(param_1 + 0xb0) + 0x20 + iVar4) & 1);
  *(undefined1 *)(iVar3 + 0x120) = *(undefined1 *)(*(int *)(param_1 + 0xb0) + 0x120);
  *(undefined4 *)(iVar3 + 0x124) = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
  FUN_0010a6a6(iVar3,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c),
               *(undefined4 *)(param_1 + 0x238));
  *(undefined1 *)(param_5 + 0x9c + *(int *)(param_1 + 0xb0)) = 1;
  iVar4 = *(int *)(param_1 + 0xb0);
  if ((*(byte *)(iVar4 + 0x15) & 2) == 0) {
    FUN_0010a6a6(iVar4,*(undefined4 *)(iVar4 + 0x8c),*(undefined4 *)(param_1 + 0x238));
    iVar4 = *(int *)(param_1 + 0xb0);
  }
  FUN_000e9596(uVar1,iVar4,iVar3);
  return iVar3;
}

/* FUN_00189714 @ 0x189714 (509 bytes) */
int FUN_00189714(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158);
  iVar3 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_0010a3c2(iVar3,0,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c));
  *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(iVar3 + 0x14c);
  *(undefined4 *)(iVar3 + 0x98) = 0;
  *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(PTR_DAT_0021345d + param_3 * 4);
  FUN_0010a3c2(iVar3,1,*(undefined4 *)(param_2 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c));
  iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),param_2);
  uVar2 = *(undefined4 *)(PTR_DAT_00213485 + (uint)*(byte *)(param_3 + 0x10 + iVar4) * 4);
  iVar4 = FUN_0010b0f4(iVar3,1);
  *(undefined4 *)(iVar4 + 0x10) = uVar2;
  iVar4 = param_2 * 0x18 + 0x80;
  FUN_00109c0e(iVar3 + 0xa4,2,*(uint *)(*(int *)(param_1 + 0xb0) + 0x20 + iVar4) >> 1 & 1);
  FUN_00109c0e(iVar3 + 0xa4,1,*(byte *)(*(int *)(param_1 + 0xb0) + 0x20 + iVar4) & 1);
  *(undefined1 *)(iVar3 + 0x120) = *(undefined1 *)(*(int *)(param_1 + 0xb0) + 0x120);
  *(undefined4 *)(iVar3 + 0x124) = param_4;
  FUN_0010a6a6(iVar3,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c),
               *(undefined4 *)(param_1 + 0x238));
  *(undefined1 *)(param_3 + 0x9c + *(int *)(param_1 + 0xb0)) = 1;
  iVar4 = *(int *)(param_1 + 0xb0);
  if ((*(byte *)(iVar4 + 0x15) & 2) == 0) {
    FUN_0010a6a6(iVar4,*(undefined4 *)(iVar4 + 0x8c),*(undefined4 *)(param_1 + 0x238));
    iVar4 = *(int *)(param_1 + 0xb0);
  }
  FUN_000e9596(uVar1,iVar4,iVar3);
  return iVar3;
}

/* FUN_00189912 @ 0x189912 (219 bytes) */
int FUN_00189912(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  int *piVar6;
  int *piVar7;
  
  piVar7 = *(int **)(param_1 + 0xb0);
  puVar2 = *(uint **)(piVar7[param_2 * 6 + 0x23] + 0x2c);
  uVar3 = puVar2[1];
  uVar1 = uVar3 - 1;
  if (uVar1 < *puVar2) {
    if (uVar3 <= uVar1) {
      _memset((void *)(puVar2[2] + uVar3 * 4),0,(uVar1 - uVar3) * 4 + 4);
      puVar2[1] = uVar3;
      piVar7 = *(int **)(param_1 + 0xb0);
    }
    piVar6 = (int *)(puVar2[2] + uVar1 * 4);
  }
  else {
    piVar6 = (int *)FUN_001a7f7c(puVar2,uVar1);
    piVar7 = *(int **)(param_1 + 0xb0);
  }
  iVar4 = *piVar6;
  cVar5 = (**(code **)(*piVar7 + 100))(piVar7);
  if (cVar5 != '\0') {
    cVar5 = FUN_00119104(*(undefined4 *)(*(int *)(*(int *)(iVar4 + 0xb0) + 0x88) + 8),
                         *(undefined4 *)(param_1 + 0x238));
    if (cVar5 != '\0') {
      return 1;
    }
  }
  return 0;
}

/* FUN_001899ee @ 0x1899ee (621 bytes) */
int FUN_001899ee(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  int iVar11;
  int local_18;
  
  piVar5 = (int *)(param_2 * 0x10 + 0x168 + param_1);
  local_18 = 0;
  pcVar9 = &STACKARG(0xc);
  do {
    if (*pcVar9 != '\0') {
      if (local_18 == 0) {
        local_18 = *piVar5;
      }
      else {
        cVar3 = FUN_00186a7c(local_18,*piVar5);
        if (cVar3 == '\0') {
          return 4;
        }
      }
    }
    pcVar9 = pcVar9 + 1;
    piVar5 = piVar5 + 1;
  } while (pcVar9 != &STACKARG(0x10));
  puVar1 = *(uint **)(*(int *)(param_2 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
  uVar8 = puVar1[1];
  uVar10 = uVar8 - 1;
  if (uVar10 < *puVar1) {
    if (uVar8 <= uVar10) {
      _memset((void *)(puVar1[2] + uVar8 * 4),0,(uVar10 - uVar8) * 4 + 4);
      puVar1[1] = uVar8;
    }
    piVar5 = (int *)(puVar1[2] + uVar10 * 4);
  }
  else {
    piVar5 = (int *)FUN_001a7f7c(puVar1,uVar10);
  }
  iVar2 = *piVar5;
  uVar8 = 0;
  iVar11 = iVar2;
  do {
    iVar4 = FUN_0010b0f4(*(undefined4 *)(iVar2 + 0xb0),0);
    if (*(char *)(uVar8 + 0x10 + iVar4) != '\x01') {
      iVar4 = *(int *)(iVar11 + 0x20);
      if (iVar4 < 0) {
        puVar6 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar4);
        uVar7 = ((float (*)())FUN_0011048e)(*(undefined4 *)(param_1 + 0xb0),param_2,*puVar6);
        uVar7 = ((float (*)())FUN_0011042e)(*(undefined4 *)(param_1 + 0xb0),param_2,uVar7);
        iVar4 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),uVar7);
        iVar4 = *(int *)(iVar4 + 4);
      }
      if (iVar4 == local_18) {
        return uVar8;
      }
    }
    uVar8 = uVar8 + 1;
    iVar11 = iVar11 + 4;
  } while (uVar8 != 4);
  iVar11 = 0;
  do {
    iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(iVar11 + 0x10 + iVar4) != '\x01') {
      iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),param_2);
      uVar8 = (uint)*(byte *)(iVar11 + 0x10 + iVar4);
      iVar4 = *(int *)(iVar2 + 0x20 + uVar8 * 4);
      if (iVar4 < 0) {
        puVar6 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar4);
        uVar7 = ((float (*)())FUN_0011048e)(*(undefined4 *)(param_1 + 0xb0),param_2,*puVar6);
        uVar7 = ((float (*)())FUN_0011042e)(*(undefined4 *)(param_1 + 0xb0),param_2,uVar7);
        iVar4 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),uVar7);
        iVar4 = *(int *)(iVar4 + 4);
      }
      if (iVar4 == local_18) {
        return uVar8;
      }
    }
    iVar11 = iVar11 + 1;
    if (iVar11 == 4) {
      return 4;
    }
  } while( true );
}

/* FUN_00189c5c @ 0x189c5c (473 bytes) */
int FUN_00189c5c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  undefined1 uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int local_20;
  
  iVar5 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),param_3);
  bVar1 = *(byte *)(param_2 + 0x10 + iVar5);
  local_20 = *(int *)(param_1 + 0x168 + (param_2 + param_3 * 4) * 4);
  if (local_20 < 0) {
    iVar5 = *(int *)(param_1 + 0xb0);
    if (*(int *)(*(int *)(iVar5 + 0x88) + 8) != 0x8e) {
      puVar2 = *(uint **)(*(int *)(iVar5 + 0x8c + param_3 * 0x18) + 0x2c);
      uVar7 = puVar2[1];
      uVar3 = uVar7 - 1;
      if (uVar3 < *puVar2) {
        if (uVar7 <= uVar3) {
          _memset((void *)(puVar2[2] + uVar7 * 4),0,(uVar3 - uVar7) * 4 + 4);
          puVar2[1] = uVar7;
          iVar5 = *(int *)(param_1 + 0xb0);
        }
        piVar6 = (int *)(puVar2[2] + uVar3 * 4);
      }
      else {
        piVar6 = (int *)FUN_001a7f7c(puVar2,uVar3);
        iVar5 = *(int *)(param_1 + 0xb0);
      }
      local_20 = *(int *)(*piVar6 + 0x20 + (uint)bVar1 * 4);
    }
  }
  else {
    iVar5 = *(int *)(param_1 + 0xb0);
  }
  iVar5 = FUN_0010b0f4(iVar5,param_4);
  bVar1 = *(byte *)(param_2 + 0x10 + iVar5);
  iVar5 = *(int *)(param_1 + 0x168 + (param_2 + param_4 * 4) * 4);
  if ((iVar5 < 0) && (*(int *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8) != 0x8e)) {
    puVar2 = *(uint **)(*(int *)(*(int *)(param_1 + 0xb0) + 0x8c + param_4 * 0x18) + 0x2c);
    uVar3 = puVar2[1];
    uVar7 = uVar3 - 1;
    if (uVar7 < *puVar2) {
      if (uVar3 <= uVar7) {
        _memset((void *)(puVar2[2] + uVar3 * 4),0,(uVar7 - uVar3) * 4 + 4);
        puVar2[1] = uVar3;
      }
      piVar6 = (int *)(puVar2[2] + uVar7 * 4);
    }
    else {
      piVar6 = (int *)FUN_001a7f7c(puVar2,uVar7);
    }
    uVar4 = FUN_00186a7c(local_20,*(undefined4 *)(*piVar6 + 0x20 + (uint)bVar1 * 4));
    return uVar4;
  }
  uVar4 = FUN_00186a7c(local_20,iVar5);
  return uVar4;
}

/* FUN_00189e36 @ 0x189e36 (198 bytes) */
int FUN_00189e36(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  
  cVar3 = ((int (*)())FUN_00189c5c)(param_1,param_2,2,3);
  if (cVar3 != '\0') {
    iVar1 = *(int *)(param_1 + 0xb0);
    uVar2 = *(uint *)(iVar1 + 0xe8);
    if ((((byte)*(uint *)(iVar1 + 0xd0) & 1) == ((byte)uVar2 & 1)) &&
       (((byte)(*(uint *)(iVar1 + 0xd0) >> 1) & 1) == ((byte)(uVar2 >> 1) & 1))) {
      if ((*(char *)(iVar1 + 0x120) == '\0') &&
         (((*(int *)(iVar1 + 0x124) == 0 && ((uVar2 & 1) == 0)) && ((uVar2 & 2) == 0)))) {
        uVar4 = FUN_001836ee(*(undefined4 *)(param_1 + 0x238),
                             *(undefined4 *)(param_1 + 0x198 + param_2 * 4));
        *(undefined4 *)(param_1 + 0x30 + param_2 * 4) = uVar4;
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_00189efc @ 0x189efc (177 bytes) */
int FUN_00189efc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  cVar2 = ((int (*)())FUN_00189c5c)(param_1,param_2,1,2);
  if (cVar2 != '\0') {
    iVar1 = *(int *)(param_1 + 0xb0);
    if ((((byte)*(uint *)(iVar1 + 0xb8) & 1) == ((byte)*(uint *)(iVar1 + 0xd0) & 1)) &&
       (((byte)(*(uint *)(iVar1 + 0xb8) >> 1) & 1) == ((byte)(*(uint *)(iVar1 + 0xd0) >> 1) & 1))) {
      uVar3 = 0;
      cVar2 = ((bool (*)())FUN_00110958)(iVar1,0,0);
      if (cVar2 != '\0') {
        uVar3 = 0x3f800000;
      }
      uVar3 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),uVar3);
      *(undefined4 *)(param_1 + 0x30 + param_2 * 4) = uVar3;
      return 1;
    }
  }
  return 0;
}

/* FUN_00189fae @ 0x189fae (222 bytes) */
int FUN_00189fae(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  undefined4 uVar6;
  
  cVar4 = ((int (*)())FUN_00189c5c)(param_1,param_2,1,2);
  if (cVar4 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    if (((((byte)uVar1 & 1) != ((byte)uVar2 & 1)) &&
        (((byte)(uVar1 >> 1) & 1) == ((byte)(uVar2 >> 1) & 1))) &&
       (iVar3 = *(int *)(param_1 + 0x178 + param_2 * 4), iVar3 < 0)) {
      piVar5 = (int *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar3);
      if ((*(char *)(*(int *)(param_1 + 0xb0) + 0x120) == '\0') &&
         (*(int *)(*(int *)(param_1 + 0xb0) + 0x124) == 0)) {
        uVar6 = FUN_001836ee(*(undefined4 *)(param_1 + 0x238),
                             *(undefined4 *)
                              (param_1 + 0x168 + (param_2 + (~(*piVar5 >> 0x1f) + 2U) * 4) * 4));
        *(undefined4 *)(param_1 + 0x30 + param_2 * 4) = uVar6;
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_0018a08c @ 0x18a08c (228 bytes) */
int FUN_0018a08c(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  undefined4 uVar6;
  
  cVar4 = ((int (*)())FUN_00189c5c)(param_1,param_2,1,2);
  if (cVar4 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    if (((((byte)uVar1 & 1) != ((byte)uVar2 & 1)) &&
        (((byte)(uVar1 >> 1) & 1) == ((byte)(uVar2 >> 1) & 1))) &&
       (iVar3 = *(int *)(param_1 + 0x178 + param_2 * 4), iVar3 < 0)) {
      piVar5 = (int *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar3);
      if ((*(char *)(*(int *)(param_1 + 0xb0) + 0x120) == '\0') &&
         (*(int *)(*(int *)(param_1 + 0xb0) + 0x124) == 0)) {
        uVar6 = FUN_001836ee(*(undefined4 *)(param_1 + 0x238),
                             *(undefined4 *)
                              (param_1 + 0x168 + (param_2 + ((0 < *piVar5) + 1) * 4) * 4));
        *(undefined4 *)(param_1 + 0x30 + param_2 * 4) = uVar6;
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_0018a170 @ 0x18a170 (147 bytes) */
int FUN_0018a170(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  
  cVar3 = ((int (*)())FUN_00189c5c)(param_1,param_2,1,2);
  if (cVar3 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    if ((((byte)uVar1 & 1) != ((byte)uVar2 & 1)) &&
       (((byte)(uVar1 >> 1) & 1) == ((byte)(uVar2 >> 1) & 1))) {
      uVar4 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),0);
      *(undefined4 *)(param_1 + 0x30 + param_2 * 4) = uVar4;
      return 1;
    }
  }
  return 0;
}

/* FUN_0018a204 @ 0x18a204 (98 bytes) */
int FUN_0018a204(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0xb0) + 0x84);
  if ((iVar2 != 1) && (1 < iVar2)) {
    iVar2 = 2;
    do {
      cVar1 = ((int (*)())FUN_00189c5c)(param_1,param_2,iVar2 + -1,iVar2);
      if (cVar1 == '\0') {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= *(int *)(*(int *)(param_1 + 0xb0) + 0x84));
  }
  return 1;
}

/* FUN_0018a266 @ 0x18a266 (96 bytes) */
int FUN_0018a266(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while ((iVar2 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0),
         *(char *)(iVar3 + 0x10 + iVar2) == '\x01' ||
         (cVar1 = ((int (*)())FUN_00189c5c)(param_1,iVar3,param_2,param_3), cVar1 != '\0'))) {
    iVar3 = iVar3 + 1;
    if (iVar3 == 4) {
      return 1;
    }
  }
  return 0;
}

/* FUN_0018a2c6 @ 0x18a2c6 (201 bytes) */
int FUN_0018a2c6(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1 + 0x168 + param_2 * 4;
  iVar5 = 1;
  while ((-1 < *(int *)(iVar4 + 0x10) ||
         (piVar2 = (int *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),*(int *)(iVar4 + 0x10)),
         *piVar2 != 0))) {
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0x10;
    if (iVar5 == 3) {
      return 0;
    }
  }
  iVar5 = (iVar5 == 1) + 1;
  iVar4 = *(int *)(param_1 + 0xb0);
  if ((*(char *)(iVar4 + 0x120) == '\0') &&
     (((*(int *)(iVar4 + 0x124) == 0 &&
       (uVar1 = *(uint *)(iVar4 + 0xa0 + iVar5 * 0x18), (uVar1 & 1) == 0)) && ((uVar1 & 2) == 0))))
  {
    uVar3 = FUN_001836ee(*(undefined4 *)(param_1 + 0x238),
                         *(undefined4 *)(param_1 + 0x168 + (param_2 + iVar5 * 4) * 4));
    *(undefined4 *)(param_1 + 0x30 + param_2 * 4) = uVar3;
    return 1;
  }
  return 1;
}

/* FUN_0018a390 @ 0x18a390 (171 bytes) */
int FUN_0018a390(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1 + 0x168 + param_2 * 4;
  iVar4 = 2;
  while ((-1 < *(int *)(iVar3 + 0x10) ||
         (piVar1 = (int *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),*(int *)(iVar3 + 0x10)),
         *piVar1 != 0))) {
    iVar3 = iVar3 + 0x10;
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      return 0;
    }
  }
  iVar3 = *(int *)(param_1 + 0xb0);
  if ((*(char *)(iVar3 + 0x120) == '\0') &&
     (((*(int *)(iVar3 + 0x124) == 0 && ((*(uint *)(iVar3 + 0xe8) & 1) == 0)) &&
      ((*(uint *)(iVar3 + 0xe8) & 2) == 0)))) {
    uVar2 = FUN_001836ee(*(undefined4 *)(param_1 + 0x238),
                         *(undefined4 *)(param_1 + 0x198 + param_2 * 4));
    *(undefined4 *)(param_1 + 0x30 + param_2 * 4) = uVar2;
    return 1;
  }
  return 1;
}

/* FUN_0018a43c @ 0x18a43c (198 bytes) */
int FUN_0018a43c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  
  cVar3 = ((int (*)())FUN_00189c5c)(param_1,param_2,1,2);
  if (cVar3 != '\0') {
    iVar1 = *(int *)(param_1 + 0xb0);
    uVar2 = *(uint *)(iVar1 + 0xb8);
    if ((((byte)uVar2 & 1) == ((byte)*(uint *)(iVar1 + 0xd0) & 1)) &&
       (((byte)(uVar2 >> 1) & 1) == ((byte)(*(uint *)(iVar1 + 0xd0) >> 1) & 1))) {
      if ((*(char *)(iVar1 + 0x120) == '\0') &&
         (((*(int *)(iVar1 + 0x124) == 0 && ((uVar2 & 1) == 0)) && ((uVar2 & 2) == 0)))) {
        uVar4 = FUN_001836ee(*(undefined4 *)(param_1 + 0x238),
                             *(undefined4 *)(param_1 + 0x178 + param_2 * 4));
        *(undefined4 *)(param_1 + 0x30 + param_2 * 4) = uVar4;
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_0018a502 @ 0x18a502 (217 bytes) */
int FUN_0018a502(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  float *pfVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1 + 0x168 + param_2 * 4;
  iVar5 = 1;
  do {
    if (*(int *)(iVar4 + 0x10) < 0) {
      pfVar2 = (float *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),*(int *)(iVar4 + 0x10));
      if ((FLOAT_001c5ba4 == *pfVar2) && (!NAN(FLOAT_001c5ba4) && !NAN(*pfVar2))) {
        iVar5 = (iVar5 == 1) + 1;
        iVar4 = *(int *)(param_1 + 0xb0);
        if ((*(char *)(iVar4 + 0x120) == '\0') &&
           (((*(int *)(iVar4 + 0x124) == 0 &&
             (uVar1 = *(uint *)(iVar4 + 0xa0 + iVar5 * 0x18), (uVar1 & 1) == 0)) &&
            ((uVar1 & 2) == 0)))) {
          uVar3 = FUN_001836ee(*(undefined4 *)(param_1 + 0x238),
                               *(undefined4 *)(param_1 + 0x168 + (param_2 + iVar5 * 4) * 4));
          *(undefined4 *)(param_1 + 0x30 + param_2 * 4) = uVar3;
          return 1;
        }
        return 1;
      }
    }
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0x10;
    if (iVar5 == 3) {
      return 0;
    }
  } while( true );
}

/* FUN_0018a5dc @ 0x18a5dc (256 bytes) */
int FUN_0018a5dc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  
  iVar1 = *(int *)(param_1 + 0x178 + param_2 * 4);
  if (iVar1 < 0) {
    puVar5 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar1);
    puVar6 = (undefined4 *)FUN_001840fe(*(undefined4 *)(param_1 + 0x238),0);
    cVar3 = ((bool (*)())FUN_00110958)(*(undefined4 *)(param_1 + 0xb0),*puVar5,*puVar6);
    iVar7 = ~-(uint)(cVar3 == '\0') + 3;
    iVar1 = *(int *)(param_1 + 0xb0);
    if ((((*(char *)(iVar1 + 0x120) != '\0') || (*(int *)(iVar1 + 0x124) != 0)) ||
        (uVar2 = *(uint *)(iVar1 + 0xa0 + iVar7 * 0x18), (uVar2 & 1) != 0)) || ((uVar2 & 2) != 0)) {
      return 1;
    }
    iVar1 = *(int *)(param_1 + 0x168 + (param_2 + iVar7 * 4) * 4);
    if (iVar1 < 0) {
      uVar4 = FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar1);
      *(undefined4 *)(param_1 + 0x30 + param_2 * 4) = uVar4;
      uVar4 = 1;
    }
    else {
      uVar4 = FUN_001836c0(*(undefined4 *)(param_1 + 0x238),iVar1);
      *(undefined4 *)(param_1 + 0x40 + param_2 * 4) = uVar4;
      uVar4 = 1;
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

/* FUN_0018a6dc @ 0x18a6dc (371 bytes) */
int FUN_0018a6dc(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  
  uVar2 = DAT_001cc728;
  if (param_1 == 0) {
    *(undefined4 *)(param_3 + 0x9c) = DAT_001cc728;
  }
  else {
    iVar5 = FUN_0010b0f4(param_3,param_1);
    *(undefined4 *)(iVar5 + 0x10) = uVar2;
  }
  FUN_000fa0d2(param_3,*(undefined4 *)(param_4 + 0x3f4),param_1,*param_2,param_2[1],param_2[2],
               param_2[3]);
  piVar4 = *(int **)(*(int *)(param_3 + 0x8c + param_1 * 0x18) + 0x18);
  if (*piVar4 == 0) {
    piVar4 = (int *)FUN_001a7f7c(piVar4,0);
  }
  else {
    if (piVar4[1] == 0) {
      *(undefined4 *)piVar4[2] = 0;
      piVar4[1] = 1;
    }
    piVar4 = (int *)piVar4[2];
  }
  iVar5 = *piVar4;
  iVar1 = *(int *)(iVar5 + 0x8c);
  if (*(int *)(*(int *)(iVar1 + 0x2c) + 4) == 0) {
    uVar2 = *(undefined4 *)(param_4 + 0xbc);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar2,0x240);
    *puVar3 = uVar2;
    puVar3 = puVar3 + 1;
    FUN_00183c52(puVar3,iVar5,param_4);
    FUN_00185344(puVar3);
    FUN_00183630(puVar3);
    FUN_0012a7b2(iVar1,*(undefined4 *)(*(int *)(iVar5 + 0x158) + 0xb0),puVar3);
  }
  FUN_0010a3c2(param_3,param_1,iVar1);
  return iVar5;
}

/* FUN_0018a86c @ 0x18a86c (416 bytes) */
int FUN_0018a86c(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar1 = *(int *)(param_1 + 0xb0);
  iVar2 = *(int *)(*(int *)(iVar1 + 0x88) + 8);
  if (iVar2 == 0x8b) {
    FUN_0010a83e(iVar1,1);
    uVar3 = ((int (*)())FUN_0018a6dc)(1,param_2,*(undefined4 *)(param_1 + 0xb0),param_3);
    *(undefined4 *)(param_1 + 0x214) = uVar3;
    FUN_000fa0d2(*(undefined4 *)(param_1 + 0xb0),*(undefined4 *)(param_3 + 0x3f4),1,*param_2,
                 param_2[1],param_2[2],param_2[3]);
    FUN_0010a83e(*(undefined4 *)(param_1 + 0xb0),2);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    uVar3 = ((int (*)())FUN_0018a6dc)(2,&local_2c,*(undefined4 *)(param_1 + 0xb0),param_3);
    *(undefined4 *)(param_1 + 0x218) = uVar3;
    *(undefined4 *)(*(int *)(param_1 + 0xb0) + 300) = 0;
    return;
  }
  if (iVar2 != 0x8c) {
    return;
  }
  FUN_0010a83e(iVar1,1);
  uVar3 = ((int (*)())FUN_0018a6dc)(1,param_2,*(undefined4 *)(param_1 + 0xb0),param_3);
  *(undefined4 *)(param_1 + 0x214) = uVar3;
  FUN_000fa0d2(*(undefined4 *)(param_1 + 0xb0),*(undefined4 *)(param_3 + 0x3f4),1,*param_2,
               param_2[1],param_2[2],param_2[3]);
  *(undefined4 *)(*(int *)(param_1 + 0xb0) + 300) = 0;
  return;
}

/* FUN_0018aa0c @ 0x18aa0c (1042 bytes) */
int FUN_0018aa0c(param_1)
  int param_1;
{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  uint uVar9;
  float fVar10;
  undefined4 *puVar11;
  int local_8c;
  float *local_88;
  undefined4 *local_7c;
  int local_78;
  float local_60;
  int local_58;
  int local_50;
  float afStack_48 [5];
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  int local_24;
  int local_20;
  
  pfVar7 = afStack_48 + 1;
  do {
    *pfVar7 = NAN;
    pfVar7 = pfVar7 + 1;
  } while (&local_34 != pfVar7);
  iVar6 = 1;
  do {
    afStack_48[iVar6] = 0.0;
    iVar6 = iVar6 + 1;
  } while (iVar6 != 5);
  bVar2 = false;
  local_60 = FLOAT_001c5bdc;
  bVar4 = true;
  local_58 = 0;
  local_88 = afStack_48;
  local_8c = param_1 + 0x160;
  do {
    local_88 = local_88 + 1;
    iVar6 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    pfVar7 = &local_34;
    if (*(char *)(local_58 + 0x10 + iVar6) != '\x01') {
      do {
        *pfVar7 = NAN;
        pfVar7 = pfVar7 + 1;
      } while (&local_28 != pfVar7);
      iVar6 = local_8c + 8;
      bVar3 = true;
      local_50 = 1;
      local_78 = 0x98;
      local_7c = &local_30;
      pfVar7 = &local_28;
      do {
        pfVar7[1] = 0.0;
        iVar8 = *(int *)(iVar6 + 0x10);
        if (iVar8 < 0) {
          puVar11 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar8);
          *local_7c = *puVar11;
          fVar10 = (float)FUN_00186b2c(*puVar11);
          pfVar7[1] = fVar10;
        }
        else {
          if (iVar8 < 1) {
            return 0;
          }
          iVar8 = FUN_001836c0(*(undefined4 *)(param_1 + 0x238),iVar8);
          fVar10 = *(float *)(iVar8 + 0xc);
          pfVar7[1] = fVar10;
          iVar8 = *(int *)(param_1 + 0xb0);
          uVar9 = *(uint *)(iVar8 + 0x20 + local_78);
          if ((uVar9 & 2) != 0) {
            pfVar7[1] = (float)(DAT_001f90bc)[(int)fVar10];
            uVar9 = *(uint *)(iVar8 + 0x20 + local_78);
          }
          if ((uVar9 & 1) != 0) {
            pfVar7[1] = *(float *)(&DAT_001f90a4 + (int)pfVar7[1] * 4);
          }
          bVar2 = true;
          bVar3 = false;
        }
        iVar8 = local_24;
        if (pfVar7[1] == 0.0) {
          return 0;
        }
        local_50 = local_50 + 1;
        local_7c = local_7c + 1;
        local_78 = local_78 + 0x18;
        iVar6 = iVar6 + 0x10;
        pfVar7 = pfVar7 + 1;
      } while (local_50 != 3);
      if (bVar3) {
        cVar5 = ((bool (*)())FUN_00110958)(*(undefined4 *)(param_1 + 0xb0),local_30,local_2c);
        if (cVar5 == '\0') {
          fVar10 = 1.0;
        }
        else {
          fVar10 = 0.0;
        }
        *local_88 = fVar10;
      }
      else {
        iVar6 = FUN_0011074c(*(undefined4 *)(param_1 + 0xb0));
        iVar6 = *(int *)(&DAT_001f90e0 + (iVar8 * 0x30 + iVar6 * 6 + local_20) * 4);
        if (iVar6 == 1) {
          *local_88 = 0.0;
        }
        else if (iVar6 == 2) {
          *local_88 = 1.0;
        }
        else if (iVar6 == 0) {
          return 0;
        }
      }
      if ((local_60 != FLOAT_001c5bdc) || (NAN(local_60) || NAN(FLOAT_001c5bdc))) {
        if (local_60 != afStack_48[local_58 + 1]) {
          bVar4 = false;
        }
        if (NAN(local_60) || NAN(afStack_48[local_58 + 1])) {
          bVar4 = false;
        }
      }
      else {
        local_60 = *local_88;
      }
    }
    local_8c = local_8c + 4;
    local_58 = local_58 + 1;
    if (local_58 == 4) {
      if (bVar2) {
        piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x134);
        *piVar1 = *piVar1 + 1;
      }
      ((int (*)())FUN_0018a86c)(param_1,afStack_48 + 1,*(undefined4 *)(param_1 + 0x238));
      cVar5 = FUN_000e1402(*(undefined4 *)(param_1 + 0x238),0xd);
      if ((cVar5 != '\0') && (bVar4)) {
        bVar2 = local_60 == FLOAT_001c5b9c;
        piVar1 = *(int **)(*(int *)(param_1 + 0xb0) + 0x158);
        cVar5 = (**(code **)(*piVar1 + 0x24))(piVar1);
        if (cVar5 != '\0') {
          if (bVar2) {
            iVar6 = piVar1[0x4c];
          }
          else {
            iVar6 = piVar1[0x4b];
          }
          FUN_00133514(*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x3f4),piVar1,iVar6,piVar1[0x4d])
          ;
          piVar1[0x50] = ((int)((uint)bVar2 << 0x1f) >> 0x1f) + 2;
          return 1;
        }
      }
      return 1;
    }
  } while( true );
}

/* FUN_0018ae1e @ 0x18ae1e (365 bytes) */
int FUN_0018ae1e(param_1)
  int param_1;
{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_30 [5];
  undefined4 local_1c [3];
  
  cVar1 = ((int (*)())FUN_0018a266)(param_1,1,2);
  if (cVar1 != '\0') {
    iVar4 = *(int *)(param_1 + 0xb0);
    if ((((byte)*(uint *)(iVar4 + 0xb8) & 1) == ((byte)*(uint *)(iVar4 + 0xd0) & 1)) &&
       (((byte)(*(uint *)(iVar4 + 0xb8) >> 1) & 1) == ((byte)(*(uint *)(iVar4 + 0xd0) >> 1) & 1))) {
      puVar2 = local_30 + 1;
      do {
        *puVar2 = 0x7ffffffe;
        puVar2 = puVar2 + 1;
      } while (local_1c != puVar2);
      iVar3 = 1;
      do {
        local_30[iVar3] = 0;
        iVar3 = iVar3 + 1;
      } while (iVar3 != 5);
      iVar3 = FUN_00186b2c(0);
      iVar4 = FUN_0010b0f4(iVar4,0);
      cVar1 = *(char *)(iVar4 + 0x10);
      iVar4 = 0;
      while( true ) {
        if (cVar1 != '\x01') {
          iVar5 = FUN_0011074c(*(undefined4 *)(param_1 + 0xb0));
          if (*(int *)(&DAT_001f90e0 + (iVar3 * 0x31 + iVar5 * 6) * 4) == 1) {
            local_30[iVar4 + 1] = 0;
          }
          else if (*(int *)(&DAT_001f90e0 + (iVar3 * 0x31 + iVar5 * 6) * 4) == 2) {
            local_30[iVar4 + 1] = 0x3f800000;
          }
        }
        if (iVar4 + 1 == 4) break;
        iVar5 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
        cVar1 = *(char *)(iVar4 + 0x11 + iVar5);
        iVar4 = iVar4 + 1;
      }
      ((int (*)())FUN_0018a86c)(param_1,local_30 + 1,*(undefined4 *)(param_1 + 0x238));
      FUN_00184a5a(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_0018af8c @ 0x18af8c (725 bytes) */
int FUN_0018af8c(param_1)
  int param_1;
{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  float *local_4c;
  float local_38;
  int local_30;
  float local_2c [4];
  float local_1c [3];
  
  pfVar5 = local_2c;
  do {
    *pfVar5 = NAN;
    pfVar5 = pfVar5 + 1;
  } while (local_1c != pfVar5);
  iVar6 = 1;
  do {
    local_2c[iVar6 + -1] = 0.0;
    iVar6 = iVar6 + 1;
  } while (iVar6 != 5);
  iVar7 = FUN_00186b2c(0);
  bVar2 = false;
  local_38 = FLOAT_001c5bdc;
  bVar3 = true;
  local_30 = 0;
  local_4c = local_2c;
  iVar6 = param_1;
  do {
    iVar8 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(local_30 + 0x10 + iVar8) != '\x01') {
      iVar8 = *(int *)(iVar6 + 0x178);
      if (iVar8 < 0) {
        puVar9 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar8);
        iVar10 = FUN_00186b2c(*puVar9);
        iVar8 = *(int *)(param_1 + 0xb0);
      }
      else {
        if (iVar8 < 1) {
          return 0;
        }
        iVar8 = FUN_001836c0(*(undefined4 *)(param_1 + 0x238),iVar8);
        iVar10 = *(int *)(iVar8 + 0xc);
        iVar8 = *(int *)(param_1 + 0xb0);
        if ((*(uint *)(iVar8 + 0xb8) & 2) != 0) {
          iVar10 = (DAT_001f90bc)[iVar10];
        }
        if ((*(uint *)(iVar8 + 0xb8) & 1) != 0) {
          iVar10 = *(int *)(&DAT_001f90a4 + iVar10 * 4);
        }
        bVar2 = true;
      }
      iVar8 = FUN_0011074c(iVar8);
      iVar8 = *(int *)(&DAT_001f90e0 + (iVar10 * 0x30 + iVar8 * 6 + iVar7) * 4);
      if (iVar8 == 1) {
        *local_4c = 0.0;
      }
      else if (iVar8 == 2) {
        *local_4c = 1.0;
      }
      else if (iVar8 == 0) {
        return 0;
      }
      if ((local_38 != FLOAT_001c5bdc) || (NAN(local_38) || NAN(FLOAT_001c5bdc))) {
        if (local_38 != local_2c[local_30]) {
          bVar3 = false;
        }
        if (NAN(local_38) || NAN(local_2c[local_30])) {
          bVar3 = false;
        }
      }
      else {
        local_38 = *local_4c;
      }
    }
    local_30 = local_30 + 1;
    local_4c = local_4c + 1;
    iVar6 = iVar6 + 4;
  } while (local_30 != 4);
  if (bVar2) {
    piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x134);
    *piVar1 = *piVar1 + 1;
  }
  ((int (*)())FUN_0018a86c)(param_1,local_2c,*(undefined4 *)(param_1 + 0x238));
  cVar4 = FUN_000e1402(*(undefined4 *)(param_1 + 0x238),0xd);
  if ((cVar4 != '\0') && (bVar3)) {
    bVar2 = local_38 == FLOAT_001c5b9c;
    piVar1 = *(int **)(*(int *)(param_1 + 0xb0) + 0x158);
    cVar4 = (**(code **)(*piVar1 + 0x24))(piVar1);
    if (cVar4 != '\0') {
      if (bVar2) {
        iVar6 = piVar1[0x4c];
      }
      else {
        iVar6 = piVar1[0x4b];
      }
      FUN_00133514(*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x3f4),piVar1,iVar6,piVar1[0x4d]);
      piVar1[0x50] = ((int)((uint)bVar2 << 0x1f) >> 0x1f) + 2;
      return 1;
    }
  }
  return 1;
}

/* FUN_0018b262 @ 0x18b262 (478 bytes) */
int FUN_0018b262(param_1)
  int param_1;
{
  int *piVar1;
  char cVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  float fVar7;
  int local_38;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar6 = 1;
  local_38 = 0x98;
  do {
    fVar3 = (float)FUN_001883e0(param_1,iVar6);
    if (fVar3 != NAN) {
      fVar7 = fVar3;
      if ((int)fVar3 < 0) {
        fVar7 = (float)((uint)fVar3 ^ _DAT_001cc740);
      }
      if ((fVar7 != FLOAT_001c5ba4) && (cVar2 = ((undefined4 (*)())FUN_0010fd8c)(fVar7), cVar2 != '\0')) {
        iVar4 = ((int (*)())FUN_0010fdbc)(fVar7);
        iVar4 = iVar4 + *(int *)(*(int *)(param_1 + 0xb0) + 0x124);
        piVar1 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
        cVar2 = (**(code **)(*piVar1 + 0xfc))(piVar1,iVar4,*(int *)(param_1 + 0xb0));
        if (cVar2 != '\0') {
          local_2c = 0x3f800000;
          local_28 = 0x3f800000;
          local_24 = 0x3f800000;
          local_20 = 0x3f800000;
          uVar5 = ((int (*)())FUN_0018a6dc)(iVar6,&local_2c,*(undefined4 *)(param_1 + 0xb0),
                               *(undefined4 *)(param_1 + 0x238));
          *(undefined4 *)(param_1 + 0x210 + iVar6 * 4) = uVar5;
          *(int *)(*(int *)(param_1 + 0xb0) + 0x124) = iVar4;
          FUN_00109c0e(local_38 + *(int *)(param_1 + 0xb0) + 0xc,1,0);
          FUN_00109c0e(local_38 + *(int *)(param_1 + 0xb0) + 0xc,2,0);
          if ((int)fVar3 < 0) {
            iVar6 = ((iVar6 == 1) + 1) * 0x18 + 0x80;
            FUN_00109c0e(*(int *)(param_1 + 0xb0) + 0xc + iVar6,1,
                         (*(uint *)(*(int *)(param_1 + 0xb0) + 0x20 + iVar6) ^ 1) & 1);
          }
          FUN_00184a5a(param_1);
          return 1;
        }
      }
    }
    iVar6 = iVar6 + 1;
    local_38 = local_38 + 0x18;
  } while (iVar6 != 3);
  return 0;
}

/* FUN_0018b440 @ 0x18b440 (307 bytes) */
int FUN_0018b440(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  undefined4 local_30 [8];
  
  local_30[0] = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158);
  iVar1 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_0010a3c2(iVar1,0,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c));
  *(undefined4 *)(iVar1 + 0x94) = *(undefined4 *)(iVar1 + 0x14c);
  *(undefined4 *)(iVar1 + 0x98) = 0;
  *(undefined4 *)(iVar1 + 0x9c) = *(undefined4 *)(PTR_DAT_0021345d + param_3 * 4);
  iVar2 = 1;
  do {
    local_30[iVar2] = param_2;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 5);
  ((int (*)())FUN_0018a6dc)(1,local_30 + 1,iVar1,*(undefined4 *)(param_1 + 0x238));
  FUN_0010a6a6(iVar1,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c),
               *(undefined4 *)(param_1 + 0x238));
  *(undefined1 *)(param_3 + 0x9c + *(int *)(param_1 + 0xb0)) = 1;
  iVar2 = *(int *)(param_1 + 0xb0);
  if ((*(byte *)(iVar2 + 0x15) & 2) == 0) {
    FUN_0010a6a6(iVar2,*(undefined4 *)(iVar2 + 0x8c),*(undefined4 *)(param_1 + 0x238));
    iVar2 = *(int *)(param_1 + 0xb0);
  }
  FUN_000e9596(local_30[0],iVar2,iVar1);
  return iVar1;
}

/* FUN_0018b574 @ 0x18b574 (319 bytes) */
int FUN_0018b574(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
  int param_7;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_3 + 0x8c);
  if (*(int *)(*(int *)(iVar3 + 0x2c) + 4) == 0) {
    uVar1 = *(undefined4 *)(param_7 + 0xbc);
    puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x240);
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
    FUN_00183c52(puVar2,param_3,param_7);
    FUN_00185344(puVar2);
    FUN_00183630(puVar2);
    FUN_0012a7b2(iVar3,*(undefined4 *)(*(int *)(param_3 + 0x158) + 0xb0),puVar2);
  }
  FUN_0010a3c2(*(undefined4 *)(param_1 + 0xb0),param_2,iVar3);
  if (param_2 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x9c) = param_4;
  }
  else {
    iVar3 = FUN_0010b0f4(*(int *)(param_1 + 0xb0),param_2);
    *(undefined4 *)(iVar3 + 0x10) = param_4;
  }
  iVar3 = param_2 * 0x18 + 0x80;
  FUN_00109c0e(iVar3 + *(int *)(param_1 + 0xb0) + 0xc,1,param_5);
  FUN_00109c0e(iVar3 + *(int *)(param_1 + 0xb0) + 0xc,2,param_6);
  return param_3;
}

/* FUN_0018b6d0 @ 0x18b6d0 (130 bytes) */
int FUN_0018b6d0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  char cStack_11;
  undefined4 local_10;
  
  iVar1 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
  local_10 = *(undefined4 *)(iVar1 + 0x10);
  piVar2 = (int *)(param_2 * 0x10 + 0x168 + param_1);
  iVar1 = 0;
  iVar5 = 1;
  do {
    if ((&cStack_11)[iVar5] != '\x01') {
      if (iVar1 == 0) {
        iVar1 = *piVar2;
      }
      else if (*piVar2 != iVar1) goto LAB_0018b72a;
    }
    iVar5 = iVar5 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar5 != 5);
  if (iVar1 < 0) {
    puVar4 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar1);
    uVar3 = *puVar4;
  }
  else {
LAB_0018b72a:
    uVar3 = 0x7ffffffe;
  }
  return uVar3;
}

/* FUN_0018b752 @ 0x18b752 (241 bytes) */
int FUN_0018b752(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  
  puVar1 = *(uint **)(*(int *)(param_2 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
  uVar2 = puVar1[1];
  uVar6 = uVar2 - 1;
  if (uVar6 < *puVar1) {
    if (uVar2 <= uVar6) {
      _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar6 - uVar2) * 4 + 4);
      puVar1[1] = uVar2;
    }
    piVar5 = (int *)(puVar1[2] + uVar6 * 4);
  }
  else {
    piVar5 = (int *)FUN_001a7f7c(puVar1,uVar6);
  }
  iVar4 = *piVar5;
  piVar5 = *(int **)(iVar4 + 0xb0);
  cVar3 = (**(code **)(*piVar5 + 100))(piVar5);
  if (((cVar3 != '\0') &&
      (iVar4 = FUN_0010b0f4(*(undefined4 *)(iVar4 + 0xb0),0), *(int *)(iVar4 + 0x10) == DAT_001cc734
      )) && (iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),1),
            *(int *)(iVar4 + 0x10) == DAT_001cc728)) {
    return 1;
  }
  return 0;
}

/* FUN_0018b844 @ 0x18b844 (2855 bytes) */
int FUN_0018b844(param_1)
  int param_1;
{
  byte bVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  uint uVar14;
  undefined1 *puVar15;
  int *local_158;
  int *local_154;
  int local_150;
  int local_144;
  char local_10d;
  int local_10c;
  int local_108;
  int local_f8;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  byte *local_d8;
  int local_d0;
  undefined4 local_c0 [19];
  undefined4 uStack_74;
  byte local_70 [16];
  undefined4 uStack_60;
  undefined1 local_5c [16];
  int aiStack_4c [5];
  int aiStack_38 [6];
  undefined4 local_20 [4];
  
  cVar5 = FUN_000e1402(*(undefined4 *)(param_1 + 0x238),0xb);
  if (((cVar5 != '\0') &&
      (cVar5 = FUN_000e1402(*(undefined4 *)(param_1 + 0x238),0x3a), cVar5 != '\0')) &&
     (*(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x228) <
      *(int *)(*(int *)(param_1 + 0x238) + 0x398))) {
    iVar11 = 0;
    do {
      puVar9 = local_c0 + iVar11 * 4;
      iVar12 = 0;
      do {
        *puVar9 = 0xbf800000;
        iVar12 = iVar12 + 1;
        puVar9 = puVar9 + 1;
      } while (iVar12 != 4);
      iVar11 = iVar11 + 1;
    } while (iVar11 != 5);
    iVar11 = 1;
    do {
      aiStack_38[iVar11] = 0;
      aiStack_4c[iVar11] = 0;
      (&uStack_60)[iVar11] = DAT_001cc720;
      (&uStack_74)[iVar11] = DAT_001cc72c;
      iVar11 = iVar11 + 1;
    } while (iVar11 != 6);
    local_10d = '\0';
    local_10c = 1;
    iVar11 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0));
    if (0 < iVar11) {
      do {
        iVar11 = *(int *)(param_1 + 0xb0);
        if ((local_10c < 1) || (iVar12 = FUN_0010b180(iVar11,local_10c), iVar12 == 0)) {
          cVar5 = FUN_0012dff6(*(undefined4 *)(iVar11 + 0x98 + local_10c * 0x18));
        }
        else {
          iVar11 = FUN_0010b180(iVar11,local_10c);
          cVar5 = FUN_0012dff6(*(undefined4 *)(iVar11 + 0x98));
        }
        if (cVar5 == '\0') {
          pcVar13 = (char *)(local_10c * 4 + 0x224 + param_1);
          piVar7 = (int *)(local_10c * 0x10 + 0x168 + param_1);
          local_108 = 0;
          iVar11 = local_10c + 1;
          do {
            if (*pcVar13 != '\0') {
              iVar12 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),local_10c);
              bVar1 = *(byte *)(local_108 + 0x10 + iVar12);
              iVar12 = (uint)bVar1 + local_10c * 4 + -0x1c;
              local_5c[iVar12 + 0x1c] = 0;
              local_70[iVar12 + 0x1c] = bVar1;
              if (*piVar7 < 0) {
                puVar9 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),*piVar7);
                piVar2 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
                cVar5 = (**(code **)(*piVar2 + 0xf0))(piVar2,*puVar9);
                if (cVar5 != '\0') {
                  if (aiStack_38[iVar11] == 0) {
                    iVar6 = ((int (*)())FUN_00188de0)(param_1,local_10c);
                    aiStack_38[iVar11] = iVar6;
                    aiStack_4c[iVar11] = 1;
                    local_10d = '\x01';
                  }
                  iVar6 = ((int (*)())FUN_00186c2c)(*puVar9,local_c0,local_10c);
                  if (aiStack_4c[iVar11] < iVar6) {
                    FUN_00110d96(aiStack_38[iVar11],*puVar9,iVar6,*(undefined4 *)(param_1 + 0x238));
                    aiStack_4c[iVar11] = iVar6;
                  }
                  (**(code **)(*(int *)aiStack_38[iVar11] + 0x88))
                            ((int *)aiStack_38[iVar11],iVar6,(uint)bVar1,local_108);
                  local_70[iVar12 + 0x1c] = 4;
                }
              }
            }
            local_108 = local_108 + 1;
            pcVar13 = pcVar13 + 1;
            piVar7 = piVar7 + 1;
          } while (local_108 != 4);
        }
        local_144 = local_10c + 1;
        iVar11 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0));
        local_10c = local_144;
      } while (local_144 <= iVar11);
    }
    iVar11 = 1;
    do {
      if (aiStack_38[iVar11] == 0) {
        aiStack_4c[iVar11] = 0;
        (&uStack_60)[iVar11] = DAT_001cc720;
        (&uStack_74)[iVar11] = DAT_001cc72c;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 != 6);
    piVar7 = *(int **)(param_1 + 0xb0);
    if ((((*(byte *)((int)piVar7 + 0x15) & 2) != 0) && ((char)piVar7[0x48] == '\0')) &&
       (piVar7[0x49] == 0)) {
      cVar5 = FUN_001886be(param_1);
      if (cVar5 == '\0') {
        piVar7 = *(int **)(param_1 + 0xb0);
      }
      else {
        local_d0 = param_1;
        local_f8 = 0;
        do {
          iVar11 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
          if (*(char *)(local_f8 + 0x10 + iVar11) == '\x01') {
            iVar11 = *(int *)(param_1 + 0xb0);
            puVar3 = *(uint **)(*(int *)(iVar11 + 0x8c + *(int *)(iVar11 + 0x84) * 0x18) + 0x2c);
            uVar14 = puVar3[1];
            uVar4 = uVar14 - 1;
            if (uVar4 < *puVar3) {
              if (uVar14 <= uVar4) {
                _memset((void *)(puVar3[2] + uVar14 * 4),0,(uVar4 - uVar14) * 4 + 4);
                puVar3[1] = uVar14;
                iVar11 = *(int *)(param_1 + 0xb0);
              }
              piVar7 = (int *)(puVar3[2] + uVar4 * 4);
            }
            else {
              piVar7 = (int *)FUN_001a7f7c(puVar3,uVar4);
              iVar11 = *(int *)(param_1 + 0xb0);
            }
            iVar12 = *piVar7;
            iVar11 = FUN_0010b0f4(iVar11,0);
            local_20[0] = *(undefined4 *)(iVar11 + 0x10);
            iVar11 = *(int *)(iVar12 + 0x20 + local_f8 * 4);
            if (iVar11 < 0) {
              puVar9 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar11);
              piVar7 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
              cVar5 = (**(code **)(*piVar7 + 0xf0))(piVar7,*puVar9);
              if (cVar5 != '\0') {
                local_ec = 1;
                while (iVar11 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))
                                          (*(int **)(param_1 + 0xb0)), local_ec <= iVar11) {
                  iVar11 = local_ec + 1;
                  if (aiStack_38[iVar11] == 0) {
                    iVar12 = ((int (*)())FUN_00188de0)(param_1,local_ec);
                    aiStack_38[iVar11] = iVar12;
                    aiStack_4c[iVar11] = 1;
                    local_d8 = local_70 + local_ec * 4;
                    puVar15 = local_5c + local_ec * 4;
                    iVar12 = 0;
                    do {
                      if (*(char *)((int)local_20 + iVar12) == '\0') {
                        iVar6 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),local_ec);
                        *local_d8 = *(byte *)(iVar12 + 0x10 + iVar6);
                        *puVar15 = 0;
                        (**(code **)(**(int **)(param_1 + 0xb0) + 0x88))
                                  (*(int **)(param_1 + 0xb0),local_ec,iVar12,iVar12);
                      }
                      iVar12 = iVar12 + 1;
                      local_d8 = local_d8 + 1;
                      puVar15 = puVar15 + 1;
                    } while (iVar12 != 4);
                    local_10d = '\x01';
                  }
                  uVar10 = FUN_00110a3a(*(undefined4 *)(param_1 + 0xb0),local_ec,*puVar9,
                                        *(undefined4 *)(param_1 + 0x238));
                  iVar12 = ((int (*)())FUN_00186c2c)(uVar10,local_c0,local_ec);
                  if (aiStack_4c[iVar11] < iVar12) {
                    FUN_00110d96(aiStack_38[iVar11],uVar10,iVar12,*(undefined4 *)(param_1 + 0x238));
                    aiStack_4c[iVar11] = iVar12;
                  }
                  iVar6 = FUN_000f5970((&uStack_60)[iVar11]);
                  piVar7 = (int *)aiStack_38[iVar11];
                  (**(code **)(*piVar7 + 0x88))(piVar7,iVar12,iVar6,iVar6);
                  local_5c[iVar6 + local_ec * 4] = 0;
                  (**(code **)(**(int **)(param_1 + 0xb0) + 0x88))
                            (*(int **)(param_1 + 0xb0),local_ec,local_f8,iVar6);
                  local_ec = iVar11;
                }
                *(undefined1 *)(local_f8 + 0x9c + *(int *)(param_1 + 0xb0)) = 0;
                *(undefined4 **)(local_d0 + 0x30) = puVar9;
              }
            }
          }
          local_f8 = local_f8 + 1;
          local_d0 = local_d0 + 4;
        } while (local_f8 != 4);
        piVar7 = *(int **)(param_1 + 0xb0);
      }
    }
    iVar11 = 1;
    while (iVar12 = (**(code **)(*piVar7 + 0x14))(piVar7), iVar11 <= iVar12) {
      iVar11 = iVar11 + 1;
      iVar12 = aiStack_38[iVar11];
      if (iVar12 != 0) {
        *(undefined4 *)(iVar12 + 0x9c) = (&uStack_60)[iVar11];
        uVar10 = (&uStack_74)[iVar11];
        iVar6 = FUN_0010b0f4(iVar12,1);
        *(undefined4 *)(iVar6 + 0x10) = uVar10;
        FUN_00111598(iVar12,*(undefined4 *)(param_1 + 0x238));
      }
      piVar7 = *(int **)(param_1 + 0xb0);
    }
    local_158 = aiStack_38 + 2;
    for (local_e8 = 1;
        iVar11 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0)),
        local_e8 <= iVar11; local_e8 = local_e8 + 1) {
      iVar11 = *local_158;
      if (iVar11 != 0) {
        piVar7 = (int *)FUN_0010b180(iVar11,1);
        cVar5 = (**(code **)(*piVar7 + 0x60))(piVar7);
        if (cVar5 != '\0') {
          uVar10 = *(undefined4 *)(param_1 + 0x238);
          uVar8 = FUN_0010b180(iVar11,1);
          FUN_00111842(uVar8,iVar11,uVar10);
        }
      }
      local_158 = local_158 + 1;
    }
    local_e0 = param_1;
    local_150 = 0x18;
    local_154 = aiStack_38 + 2;
    for (local_e4 = 1;
        iVar11 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0)),
        local_e4 <= iVar11; local_e4 = local_e4 + 1) {
      iVar11 = *local_154;
      if (iVar11 != 0) {
        puVar3 = *(uint **)(*(int *)(local_150 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
        uVar4 = puVar3[1];
        uVar14 = uVar4 - 1;
        if (uVar14 < *puVar3) {
          if (uVar4 <= uVar14) {
            _memset((void *)(puVar3[2] + uVar4 * 4),0,(uVar14 - uVar4) * 4 + 4);
            puVar3[1] = uVar4;
          }
          puVar9 = (undefined4 *)(puVar3[2] + uVar14 * 4);
        }
        else {
          puVar9 = (undefined4 *)FUN_001a7f7c(puVar3,uVar14);
        }
        uVar10 = *puVar9;
        FUN_00183b9e(uVar10);
        FUN_00184224(uVar10);
        FUN_00185344(uVar10);
        FUN_0018627e(uVar10);
        FUN_00183630(uVar10);
        *(int *)(local_e0 + 0x214) = iVar11;
      }
      local_154 = local_154 + 1;
      local_150 = local_150 + 0x18;
      local_e0 = local_e0 + 4;
    }
    if (local_10d != '\0') {
      iVar11 = 4;
      do {
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
    return local_10d;
  }
  return '\0';
}

/* FUN_0018c36c @ 0x18c36c (1678 bytes) */
int FUN_0018c36c(param_1)
  int param_1;
{
  uint *puVar1;
  uint uVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  float *pfVar7;
  char *pcVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined1 local_43;
  int local_40;
  int local_3c;
  char *local_38;
  int *local_34;
  int local_30;
  char cStack_25;
  undefined4 local_24;
  int local_20 [4];
  
  piVar6 = *(int **)(param_1 + 0xb0);
  if (*(int *)(piVar6[0x22] + 8) == 0x77) {
    iVar5 = FUN_0010b0f4(piVar6,1);
    local_24 = *(int *)(iVar5 + 0x10);
    iVar5 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    local_20[0] = *(int *)(iVar5 + 0x10);
    bVar3 = false;
    iVar11 = 1;
    iVar5 = param_1;
    do {
      if (*(int *)(iVar5 + 0x178) < 0) {
        pfVar7 = (float *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),*(int *)(iVar5 + 0x178));
        if (*pfVar7 < FLOAT_001c5b9c) {
          bVar3 = true;
        }
        else if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x238) + 0x54) + 9) & 0x10) != 0) {
          (&cStack_25)[iVar11] = '\x04';
          *(undefined1 *)((int)local_20 + iVar11 + -1) = 1;
        }
      }
      iVar11 = iVar11 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar11 != 5);
    if (bVar3) {
      bVar3 = false;
      iVar11 = 1;
      iVar5 = param_1;
      do {
        if ((((*(byte *)(*(int *)(*(int *)(param_1 + 0x238) + 0x54) + 9) & 0x10) != 0) &&
            (*(int *)(iVar5 + 0x178) < 0)) &&
           (pfVar7 = (float *)FUN_001836ee(*(int *)(param_1 + 0x238),*(int *)(iVar5 + 0x178)),
           *pfVar7 <= 0.0 && *pfVar7 != 0.0)) {
          if (bVar3) {
            (&cStack_25)[iVar11] = '\x04';
            *(undefined1 *)((int)local_20 + iVar11 + -1) = 1;
          }
          bVar3 = true;
        }
        iVar11 = iVar11 + 1;
        iVar5 = iVar5 + 4;
      } while (iVar11 != 5);
    }
    iVar11 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),1);
    iVar5 = local_24;
    if (local_24 == *(int *)(iVar11 + 0x10)) {
      piVar6 = *(int **)(param_1 + 0xb0);
      goto LAB_0018c396;
    }
    iVar11 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),1);
    *(int *)(iVar11 + 0x10) = iVar5;
    *(int *)(*(int *)(param_1 + 0xb0) + 0x9c) = local_20[0];
    local_43 = 1;
    piVar6 = *(int **)(param_1 + 0xb0);
  }
  else {
LAB_0018c396:
    local_43 = 0;
  }
  if (piVar6[0x20] == 0) {
LAB_0018c3a8:
    cVar4 = (**(code **)(*piVar6 + 0x68))(piVar6);
    if (cVar4 != '\0') goto LAB_0018c3b8;
  }
  else {
    cVar4 = FUN_0012dfd8(piVar6[0x26]);
    if (cVar4 == '\0') {
      piVar6 = *(int **)(param_1 + 0xb0);
      goto LAB_0018c3a8;
    }
    if ((*(byte *)(piVar6 + 5) & 2) != 0) {
      piVar6 = *(int **)(param_1 + 0xb0);
      goto LAB_0018c3a8;
    }
    cVar4 = (**(code **)(*piVar6 + 0x50))(piVar6);
    if (cVar4 != '\0') {
      piVar6 = *(int **)(param_1 + 0xb0);
      goto LAB_0018c3a8;
    }
LAB_0018c3b8:
    cVar4 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x28))(*(int **)(param_1 + 0xb0));
    if (cVar4 == '\0') {
      piVar6 = *(int **)(param_1 + 0xb0);
      goto LAB_0018c3da;
    }
    if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x238) + 0x54) + 9) & 8) != 0) {
      piVar6 = *(int **)(param_1 + 0xb0);
      goto LAB_0018c3da;
    }
  }
  piVar6 = *(int **)(param_1 + 0xb0);
  if (*(int *)(piVar6[0x22] + 8) != 0x77) {
    return local_43;
  }
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x238) + 0x54) + 9) & 8) == 0) {
    return local_43;
  }
LAB_0018c3da:
  local_30 = param_1;
  local_40 = 1;
  do {
    iVar5 = (**(code **)(*piVar6 + 0x14))(piVar6);
    if (iVar5 < local_40) {
      return local_43;
    }
    cVar4 = FUN_00186c82(*(undefined4 *)(local_40 * 0x18 + *(int *)(param_1 + 0xb0) + 0x98));
    if (cVar4 != '\0') {
      puVar1 = *(uint **)(*(int *)(local_40 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
      uVar2 = puVar1[1];
      uVar9 = uVar2 - 1;
      if (uVar9 < *puVar1) {
        if (uVar2 <= uVar9) {
          _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar9 - uVar2) * 4 + 4);
          puVar1[1] = uVar2;
        }
        piVar6 = (int *)(puVar1[2] + uVar9 * 4);
      }
      else {
        piVar6 = (int *)FUN_001a7f7c(puVar1,uVar9);
      }
      if ((*(int *)(*(int *)(*(int *)(*piVar6 + 0xb0) + 0x88) + 8) != 0x8e) ||
         (*(int *)(*piVar6 + 0xb4) != 0)) {
        iVar5 = ((int (*)())FUN_001899ee)(param_1,local_40,*(undefined4 *)(local_30 + 0x228));
        if (iVar5 == 4) {
          iVar5 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),local_40);
          local_20[0] = *(int *)(iVar5 + 0x10);
          iVar5 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),local_40);
          local_24 = *(int *)(iVar5 + 0x10);
          cVar4 = FUN_0011902c(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                               *(undefined4 *)(param_1 + 0x238));
          if (cVar4 == '\0') {
            local_24 = FUN_000f5b96(local_24,*(undefined4 *)(local_30 + 0x228));
          }
          iVar5 = param_1 + 0x220 + local_40 * 4;
          local_38 = (char *)(iVar5 + 4);
          iVar11 = local_40 * 0x10 + 0x160 + param_1;
          local_34 = (int *)(iVar11 + 8);
          local_3c = 0;
          do {
            if (*local_38 != '\0') {
              pcVar8 = (char *)(iVar5 + 4);
              piVar6 = (int *)(iVar11 + 8);
              iVar10 = 0;
              do {
                if (*pcVar8 != '\0') {
                  if (iVar10 == local_3c) break;
                  if ((*local_34 == *piVar6) &&
                     (*(char *)((int)local_20 + local_3c + -4) != *(char *)((int)local_20 + iVar10))
                     ) {
                    *(undefined1 *)((int)local_20 + local_3c + -4) =
                         *(undefined1 *)((int)local_20 + iVar10);
                    break;
                  }
                }
                iVar10 = iVar10 + 1;
                pcVar8 = pcVar8 + 1;
                piVar6 = piVar6 + 1;
              } while (iVar10 != 4);
            }
            local_3c = local_3c + 1;
            local_38 = local_38 + 1;
            local_34 = local_34 + 1;
          } while (local_3c != 4);
          if ((local_24 != local_20[0]) &&
             (piVar6 = *(int **)(*(int *)(param_1 + 0x238) + 0x54),
             cVar4 = (**(code **)(*piVar6 + 0x104))
                               (piVar6,*(undefined4 *)(param_1 + 0xb0),local_40,&local_24,0),
             cVar4 != '\0')) {
            iVar5 = *(int *)(param_1 + 0xb0);
            iVar11 = local_24;
            if (local_40 != 0) goto LAB_0018c73a;
LAB_0018c4fc:
            *(int *)(iVar5 + 0x9c) = iVar11;
            local_43 = 1;
          }
        }
        else {
          local_20[0] = *(int *)(PTR_DAT_00213485 + iVar5 * 4);
          cVar4 = FUN_0011902c(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                               *(undefined4 *)(param_1 + 0x238));
          if (cVar4 == '\0') {
            local_20[0] = FUN_000f5b96(local_20[0],*(undefined4 *)(local_30 + 0x228));
          }
          iVar5 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),local_40);
          if ((local_20[0] != *(int *)(iVar5 + 0x10)) &&
             (piVar6 = *(int **)(*(int *)(param_1 + 0x238) + 0x54),
             cVar4 = (**(code **)(*piVar6 + 0x104))
                               (piVar6,*(undefined4 *)(param_1 + 0xb0),local_40,local_20,0),
             cVar4 != '\0')) {
            iVar5 = *(int *)(param_1 + 0xb0);
            iVar11 = local_20[0];
            if (local_40 == 0) goto LAB_0018c4fc;
LAB_0018c73a:
            iVar5 = FUN_0010b0f4(iVar5,local_40);
            *(int *)(iVar5 + 0x10) = iVar11;
            local_43 = 1;
          }
        }
      }
    }
    local_40 = local_40 + 1;
    local_30 = local_30 + 4;
    piVar6 = *(int **)(param_1 + 0xb0);
  } while( true );
}

/* FUN_0018c9fa @ 0x18c9fa (844 bytes) */
int FUN_0018c9fa(param_1)
  int param_1;
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined1 uVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  int *piVar14;
  int iVar15;
  undefined1 local_41;
  undefined4 local_20 [4];
  
  if ((*(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0xa8) <
       *(int *)(*(int *)(param_1 + 0x238) + 0x38c)) &&
     (cVar7 = (**(code **)(**(int **)(param_1 + 0xb0) + 100))(*(int **)(param_1 + 0xb0)),
     cVar7 != '\0')) {
    iVar8 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),1);
    cVar7 = FUN_000f59e0(*(undefined4 *)(iVar8 + 0x10));
    if (cVar7 == '\0') {
      iVar8 = *(int *)(param_1 + 0xb0);
      puVar2 = *(uint **)(*(int *)(iVar8 + 0xa4) + 0x2c);
      uVar3 = puVar2[1];
      uVar1 = uVar3 - 1;
      if (uVar1 < *puVar2) {
        if (uVar3 <= uVar1) {
          _memset((void *)(puVar2[2] + uVar3 * 4),0,(uVar1 - uVar3) * 4 + 4);
          puVar2[1] = uVar3;
          iVar8 = *(int *)(param_1 + 0xb0);
        }
        piVar14 = (int *)(puVar2[2] + uVar1 * 4);
      }
      else {
        piVar14 = (int *)FUN_001a7f7c(puVar2,uVar1);
        iVar8 = *(int *)(param_1 + 0xb0);
      }
      iVar12 = *piVar14;
      bVar5 = true;
      iVar15 = 0;
      iVar9 = FUN_0010b0f4(iVar8,0);
      iVar8 = iVar12;
      iVar10 = iVar15;
      if (*(char *)(iVar9 + 0x10) == '\x01') goto joined_r0x0018cb14;
LAB_0018cac6:
      iVar10 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),1);
      cVar7 = FUN_00186a7c(*(undefined4 *)
                            (iVar12 + 0x20 + (uint)*(byte *)(iVar15 + 0x10 + iVar10) * 4),
                           *(undefined4 *)(iVar8 + 0x20));
      iVar10 = iVar15;
      if (cVar7 == '\0') {
        bVar5 = false;
      }
joined_r0x0018cb14:
      iVar15 = iVar10 + 1;
      if (iVar15 != 4) goto LAB_0018cb16;
      if (bVar5) {
        local_20[0] = DAT_001cc72c;
        iVar8 = 0;
        do {
          iVar12 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
          if (*(char *)(iVar8 + 0x10 + iVar12) != '\x01') {
            *(char *)((int)local_20 + iVar8) = (char)iVar8;
          }
          uVar4 = local_20[0];
          iVar8 = iVar8 + 1;
        } while (iVar8 != 4);
        iVar8 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),1);
        *(undefined4 *)(iVar8 + 0x10) = uVar4;
        local_41 = 1;
        goto LAB_0018cba9;
      }
    }
    local_41 = 0;
LAB_0018cba9:
    iVar8 = *(int *)(param_1 + 0xb0);
    if ((*(char *)(iVar8 + 0x120) == '\0') || (*(int *)(iVar8 + 0x124) != 0)) {
      return local_41;
    }
    puVar2 = *(uint **)(*(int *)(iVar8 + 0xa4) + 0x2c);
    uVar3 = puVar2[1];
    uVar1 = uVar3 - 1;
    if (uVar1 < *puVar2) {
      if (uVar3 <= uVar1) {
        _memset((void *)(puVar2[2] + uVar3 * 4),0,(uVar1 - uVar3) * 4 + 4);
        puVar2[1] = uVar3;
        iVar8 = *(int *)(param_1 + 0xb0);
      }
      puVar13 = (undefined4 *)(puVar2[2] + uVar1 * 4);
    }
    else {
      puVar13 = (undefined4 *)FUN_001a7f7c(puVar2,uVar1);
      iVar8 = *(int *)(param_1 + 0xb0);
    }
    uVar4 = *puVar13;
    uVar1 = *(uint *)(iVar8 + 0xb8);
    iVar8 = FUN_0010b0f4(iVar8,0);
    cVar7 = *(char *)(iVar8 + 0x10);
    iVar8 = 0;
    while( true ) {
      if (cVar7 != '\x01') {
        iVar12 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),1);
        cVar7 = FUN_00186c98(uVar4,*(undefined1 *)(iVar8 + 0x10 + iVar12));
        if (cVar7 == '\0') {
          return local_41;
        }
        if ((uVar1 & 1) != 0) {
          return local_41;
        }
      }
      if (iVar8 + 1 == 4) break;
      iVar12 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
      cVar7 = *(char *)(iVar8 + 0x11 + iVar12);
      iVar8 = iVar8 + 1;
    }
    *(undefined1 *)(*(int *)(param_1 + 0xb0) + 0x120) = 0;
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
LAB_0018cb16:
  iVar8 = iVar8 + 4;
  iVar11 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
  iVar9 = iVar10 + 0x11;
  iVar10 = iVar15;
  if (*(char *)(iVar9 + iVar11) != '\x01') goto LAB_0018cac6;
  goto joined_r0x0018cb14;
}

/* FUN_0018cd46 @ 0x18cd46 (229 bytes) */
int FUN_0018cd46(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  int param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  
  piVar3 = (int *)FUN_0010b180(param_1,1);
  while( true ) {
    cVar2 = (**(code **)(*piVar3 + 0x40))(piVar3);
    if (cVar2 != '\0') {
      return piVar3;
    }
    iVar4 = FUN_0010b0f4(piVar3,0);
    uVar1 = *(undefined4 *)(iVar4 + 0x10);
    iVar4 = FUN_00186ce2(param_1,piVar3);
    if (iVar4 == 2) break;
    if ((iVar4 == 0) && (uVar5 = FUN_000f5fea(uVar1), (uVar5 & param_2) != DAT_001cc730)) {
      return piVar3;
    }
    piVar3 = (int *)FUN_0010b180(piVar3,3);
  }
  if ((param_3 != '\0') && (piVar6 = (int *)FUN_0010b180(param_1,1), piVar3 != piVar6)) {
    FUN_0010ba02(param_1,1,piVar3,0,param_4);
    return (int *)0x0;
  }
  return (int *)0x0;
}

/* FUN_0018ce2c @ 0x18ce2c (5776 bytes) */
int FUN_0018ce2c(param_1)
  int param_1;
{
  uint *puVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  float *pfVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 *puVar14;
  char *pcVar15;
  uint uVar16;
  longdouble lVar17;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_b0;
  uint local_ac;
  undefined1 local_a1;
  int local_a0;
  int local_8c;
  int local_88;
  int local_80;
  int local_78;
  int local_64;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int *local_48;
  int local_44;
  int local_40 [12];
  
  if (*(int *)(*(int *)(param_1 + 0x238) + 0x38c) <=
      *(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0xa8)) {
    return 0;
  }
  local_a1 = 0;
  local_a0 = 1;
  iVar5 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0));
  if (0 < iVar5) {
    do {
      piVar6 = *(int **)(param_1 + 0xb0);
      if ((*(byte *)(piVar6 + local_a0 * 6 + 0x28) & 2) != 0) {
        puVar1 = *(uint **)(piVar6[local_a0 * 6 + 0x23] + 0x2c);
        uVar16 = puVar1[1];
        uVar10 = uVar16 - 1;
        if (uVar10 < *puVar1) {
          if (uVar16 <= uVar10) {
            _memset((void *)(puVar1[2] + uVar16 * 4),0,(uVar10 - uVar16) * 4 + 4);
            puVar1[1] = uVar16;
            piVar6 = *(int **)(param_1 + 0xb0);
          }
          puVar14 = (undefined4 *)(puVar1[2] + uVar10 * 4);
        }
        else {
          puVar14 = (undefined4 *)FUN_001a7f7c(puVar1);
          piVar6 = *(int **)(param_1 + 0xb0);
        }
        uVar12 = *puVar14;
        pcVar15 = (char *)(param_1 + 0x224 + local_a0 * 4);
        bVar2 = true;
        bVar3 = true;
        local_8c = 0;
        do {
          if (*pcVar15 != '\0') {
            FUN_0010b0f4(piVar6);
            cVar4 = FUN_00186cc8(uVar12);
            if (cVar4 == '\0') {
              FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0));
              cVar4 = FUN_00186cae(uVar12);
              if (cVar4 == '\0') {
                piVar6 = *(int **)(param_1 + 0xb0);
                goto LAB_0018cf73;
              }
              if (!bVar3) {
                piVar6 = *(int **)(param_1 + 0xb0);
                goto LAB_0018cf73;
              }
              bVar2 = false;
              piVar6 = *(int **)(param_1 + 0xb0);
            }
            else {
              if (!bVar2) {
                piVar6 = *(int **)(param_1 + 0xb0);
                goto LAB_0018cf73;
              }
              bVar3 = false;
              piVar6 = *(int **)(param_1 + 0xb0);
            }
          }
          local_8c = local_8c + 1;
          pcVar15 = pcVar15 + 1;
        } while (local_8c != 4);
        if (bVar2) {
          FUN_00109c0e(piVar6 + local_a0 * 6 + 0x23,2,0);
          local_a1 = 1;
          piVar6 = *(int **)(param_1 + 0xb0);
        }
        else if ((bVar3) && ((*(byte *)(piVar6 + local_a0 * 6 + 0x28) & 1) != 0)) {
          FUN_00109c0e(piVar6 + local_a0 * 6 + 0x23,2,0);
          FUN_00109c0e(local_a0 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c,1,0);
          local_a1 = 1;
          piVar6 = *(int **)(param_1 + 0xb0);
        }
      }
LAB_0018cf73:
      local_a0 = local_a0 + 1;
      iVar5 = (**(code **)(*piVar6 + 0x14))();
    } while (local_a0 <= iVar5);
  }
  cVar4 = FUN_000e1402(*(undefined4 *)(param_1 + 0x238));
  if (cVar4 != '\0') {
    local_40[0] = param_1;
    local_f0 = 0x18;
    local_f4 = 0x18;
    for (local_88 = 1;
        iVar5 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0)),
        local_88 <= iVar5; local_88 = local_88 + 1) {
      iVar5 = FUN_0010b7c8(*(undefined4 *)(param_1 + 0xb0));
      if (iVar5 == 2) {
        puVar1 = *(uint **)(*(int *)(local_f4 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
        uVar10 = puVar1[1];
        uVar16 = uVar10 - 1;
        if (uVar16 < *puVar1) {
          if (uVar10 <= uVar16) {
            _memset((void *)(puVar1[2] + uVar10 * 4),0,(uVar16 - uVar10) * 4 + 4);
            puVar1[1] = uVar10;
          }
          piVar6 = (int *)(puVar1[2] + uVar16 * 4);
        }
        else {
          piVar6 = (int *)FUN_001a7f7c(puVar1);
        }
        iVar5 = *piVar6;
        if (*(int *)(iVar5 + 0x178) < 0) {
          pfVar8 = (float *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238));
          if (*(char *)(*(int *)(iVar5 + 0xb0) + 300) == '\0') {
            lVar17 = (longdouble)_floorf(*pfVar8);
          }
          else {
            lVar17 = (longdouble)_floor((double)*pfVar8 + DOUBLE_001cf368);
          }
          iVar5 = FUN_0010b6e4(*(undefined4 *)(param_1 + 0xb0));
          iVar5 = (int)lVar17 + iVar5;
          if (*(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x54) + 0x2c) <= iVar5) {
            iVar5 = 0;
          }
          uVar12 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x3a0);
          iVar11 = *(int *)(param_1 + 0xb0);
          if ((local_88 < 1) || (iVar13 = FUN_0010b180(iVar11), iVar13 == 0)) {
            uVar9 = *(undefined4 *)(local_f0 + 0x98 + iVar11);
          }
          else {
            iVar11 = FUN_0010b180(iVar11);
            uVar9 = *(undefined4 *)(iVar11 + 0x98);
          }
          cVar4 = FUN_0012df9c(uVar9);
          if (cVar4 == '\0') {
            uVar12 = FUN_0012eb84(uVar12,0,iVar5,0);
          }
          else {
            uVar12 = FUN_0012eb84(uVar12,2,iVar5,0);
          }
          FUN_0010a3c2(*(undefined4 *)(param_1 + 0xb0),local_88,uVar12);
          FUN_0012a9e6(uVar12,local_88,*(undefined4 *)(param_1 + 0xb0));
          iVar5 = FUN_0012a37e(uVar12,*(undefined4 *)
                                       (*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x394),
                               *(int *)(param_1 + 0x238));
          *(undefined4 *)(local_40[0] + 0x214) = *(undefined4 *)(iVar5 + 0xb0);
        }
      }
      local_f4 = local_f4 + 0x18;
      local_f0 = local_f0 + 0x18;
      local_40[0] = local_40[0] + 4;
    }
  }
  piVar6 = *(int **)(param_1 + 0xb0);
  if (piVar6[0x20] == 0) {
LAB_0018cfc6:
    if (((*(byte *)(piVar6 + 5) & 2) != 0) || (cVar4 = FUN_0018872c(piVar6), cVar4 != '\0'))
    goto LAB_0018cfd0;
  }
  else {
    cVar4 = FUN_0012dfd8(piVar6[0x26]);
    if (cVar4 == '\0') {
      piVar6 = *(int **)(param_1 + 0xb0);
      goto LAB_0018cfc6;
    }
    if ((*(byte *)(piVar6 + 5) & 2) != 0) {
      piVar6 = *(int **)(param_1 + 0xb0);
      goto LAB_0018cfc6;
    }
    cVar4 = (**(code **)(*piVar6 + 0x50))(piVar6);
    if (cVar4 != '\0') {
      piVar6 = *(int **)(param_1 + 0xb0);
      goto LAB_0018cfc6;
    }
    piVar6 = *(int **)(param_1 + 0xb0);
LAB_0018cfd0:
    local_44 = param_1;
    for (local_80 = 1; iVar5 = (**(code **)(*piVar6 + 0x14))(piVar6), local_80 <= iVar5;
        local_80 = local_80 + 1) {
      puVar1 = *(uint **)(*(int *)(local_80 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
      uVar10 = puVar1[1];
      uVar16 = uVar10 - 1;
      if (uVar16 < *puVar1) {
        if (uVar10 <= uVar16) {
          _memset((void *)(puVar1[2] + uVar10 * 4),0,(uVar16 - uVar10) * 4 + 4);
          puVar1[1] = uVar10;
        }
        piVar6 = (int *)(puVar1[2] + uVar16 * 4);
      }
      else {
        piVar6 = (int *)FUN_001a7f7c(puVar1);
      }
      piVar6 = *(int **)(*piVar6 + 0xb0);
      cVar4 = (**(code **)(*piVar6 + 0x74))(piVar6);
      if (((cVar4 != '\0') && (*(int *)(piVar6[0x22] + 8) == 0xfb)) &&
         (iVar5 = FUN_0010b7c8(*(undefined4 *)(param_1 + 0xb0)), iVar5 == 0)) {
        iVar5 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0));
        local_ac = FUN_000f5bdc(*(undefined4 *)(iVar5 + 0x10));
        piVar7 = (int *)((int (*)())FUN_0018cd46)(piVar6,local_ac,1,*(undefined4 *)(param_1 + 0x238));
        if (piVar7 != (int *)0x0) {
          cVar4 = (**(code **)(*piVar7 + 0x40))(piVar7);
          if (cVar4 == '\0') {
            iVar5 = FUN_0010b0f4(piVar7);
            uVar10 = FUN_000f5fea(*(undefined4 *)(iVar5 + 0x10));
            if ((~uVar10 & local_ac) == DAT_001cc730) {
              iVar5 = FUN_0010b180(piVar7);
              goto LAB_0018d289;
            }
            iVar5 = FUN_0010a17a(0x31);
            FUN_0010a3c2(iVar5,0,piVar6[0x23]);
            *(undefined4 *)(iVar5 + 0x94) = *(undefined4 *)(iVar5 + 0x14c);
            *(undefined4 *)(iVar5 + 0x98) = 0;
            iVar11 = FUN_0010b180(piVar7);
            FUN_0010a3c2(iVar5,1,*(undefined4 *)(iVar11 + 0x8c));
            FUN_0010ba02(iVar5,1,iVar11,0,*(undefined4 *)(param_1 + 0x238));
            uVar12 = FUN_000f5ea0(local_ac & uVar10);
            *(undefined4 *)(iVar5 + 0x9c) = uVar12;
            uVar12 = FUN_000f5e66(uVar12);
            iVar11 = FUN_0010b0f4(iVar5);
            *(undefined4 *)(iVar11 + 0x10) = uVar12;
            local_ac = local_ac & ~(local_ac & uVar10);
            local_40[5] = iVar5;
            if (DAT_001cc730 == local_ac) {
              local_58 = 0;
LAB_0018e009:
              local_48 = local_40 + local_58 + 5;
              local_4c = 0;
              do {
                iVar11 = *local_48;
                FUN_000e956e(*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158),
                             *(int *)(param_1 + 0xb0),iVar11);
                FUN_0012a42e(*(undefined4 *)(iVar11 + 0x8c));
                iVar13 = FUN_0010b180(iVar11);
                FUN_0012a9e6(*(undefined4 *)(iVar13 + 0x8c),1,iVar11);
                uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x238) + 0xbc);
                puVar14 = (undefined4 *)FUN_001a7bca(uVar12);
                *puVar14 = uVar12;
                puVar14 = puVar14 + 1;
                FUN_00183c52(puVar14,iVar11,*(undefined4 *)(param_1 + 0x238));
                FUN_0012540a(puVar14);
                FUN_00184224(puVar14);
                FUN_00185344(puVar14);
                FUN_0018627e(puVar14);
                FUN_00183630(puVar14);
                FUN_000eb51a(*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158),
                             *(undefined4 *)(iVar11 + 0x8c),puVar14);
                local_4c = local_4c + 1;
                local_48 = local_48 + -1;
              } while (local_58 + 1 != local_4c);
            }
            else {
              local_78 = 1;
              local_ec = 8;
              iVar11 = iVar5;
              iVar13 = local_78;
              do {
                local_78 = iVar13;
                piVar7 = (int *)((int (*)())FUN_0018cd46)(piVar6,local_ac,0,*(undefined4 *)(param_1 + 0x238));
                if (piVar7 == (int *)0x0) goto LAB_0018d01c;
                iVar13 = FUN_0010a17a(0x31);
                FUN_0010a3c2(iVar13,0,piVar6[0x23]);
                *(undefined4 *)(iVar13 + 0x94) = *(undefined4 *)(iVar13 + 0x14c);
                *(undefined4 *)(iVar13 + 0x98) = 0;
                FUN_0010a6a6(iVar11,*(undefined4 *)(iVar13 + 0x8c),*(undefined4 *)(param_1 + 0x238))
                ;
                FUN_0010c18e(iVar11,iVar13,0,*(undefined4 *)(param_1 + 0x238));
                iVar11 = FUN_0010b0f4(piVar7);
                uVar10 = FUN_000f5fea(*(undefined4 *)(iVar11 + 0x10));
                uVar10 = uVar10 & local_ac;
                uVar12 = FUN_000f5ea0(uVar10);
                *(undefined4 *)(iVar13 + 0x9c) = uVar12;
                uVar12 = FUN_000f5e66(uVar12);
                iVar11 = FUN_0010b0f4(iVar13);
                *(undefined4 *)(iVar11 + 0x10) = uVar12;
                cVar4 = (**(code **)(*piVar7 + 0x40))(piVar7);
                if (cVar4 == '\0') {
                  iVar11 = FUN_0010b180(piVar7);
                  FUN_0010a3c2(iVar13,1,*(undefined4 *)(iVar11 + 0x8c));
                  FUN_0010ba02(iVar13,1,iVar11,0,*(undefined4 *)(param_1 + 0x238));
                }
                else {
                  iVar11 = *(int *)(*(int *)(param_1 + 0x238) + 0x3f4);
                  iVar11 = FUN_0012af7a(iVar11,*(undefined4 *)(iVar11 + 0x394),0);
                  iVar11 = *(int *)(iVar11 + 0xb0);
                  FUN_0010a3c2(iVar13,1,*(undefined4 *)(iVar11 + 0x8c));
                  FUN_0010ba02(iVar13,1,iVar11,0,*(undefined4 *)(param_1 + 0x238));
                  local_ac = 0;
                }
                local_ac = ~uVar10 & local_ac;
                *(int *)((int)local_40 + local_ec + 0x10U) = iVar13;
                local_ec = local_ec + 4;
                iVar11 = iVar13;
                iVar13 = local_78 + 1;
              } while (DAT_001cc730 != local_ac);
              if (local_78 + 1 == 0) goto LAB_0018d01c;
              local_58 = local_78;
              if (-1 < local_78) goto LAB_0018e009;
            }
            *(int *)(local_44 + 0x214) = iVar5;
            uVar12 = *(undefined4 *)(iVar5 + 0x8c);
          }
          else {
            iVar5 = *(int *)(*(int *)(param_1 + 0x238) + 0x3f4);
            iVar5 = FUN_0012af7a(iVar5,*(undefined4 *)(iVar5 + 0x394),0);
            iVar5 = *(int *)(iVar5 + 0xb0);
LAB_0018d289:
            *(int *)(local_44 + 0x214) = iVar5;
            uVar12 = *(undefined4 *)(iVar5 + 0x8c);
          }
          FUN_0010a3c2(*(undefined4 *)(param_1 + 0xb0),local_80,uVar12);
          FUN_0012a9e6(uVar12,local_80,*(undefined4 *)(param_1 + 0xb0));
        }
      }
LAB_0018d01c:
      local_44 = local_44 + 4;
      piVar6 = *(int **)(param_1 + 0xb0);
    }
    piVar6 = *(int **)(param_1 + 0xb0);
  }
  if (piVar6[0x20] != 0) {
    cVar4 = FUN_0012dfd8(piVar6[0x26]);
    if (cVar4 == '\0') {
      piVar6 = *(int **)(param_1 + 0xb0);
    }
    else if ((*(byte *)(piVar6 + 5) & 2) == 0) {
      cVar4 = (**(code **)(*piVar6 + 0x50))(piVar6);
      if (cVar4 == '\0') {
        piVar6 = *(int **)(param_1 + 0xb0);
        goto LAB_0018d338;
      }
      piVar6 = *(int **)(param_1 + 0xb0);
    }
    else {
      piVar6 = *(int **)(param_1 + 0xb0);
    }
  }
  if (((*(byte *)(piVar6 + 5) & 2) == 0) && (cVar4 = FUN_0018872c(piVar6), cVar4 == '\0')) {
    return local_a1;
  }
LAB_0018d338:
  local_50 = param_1;
  local_64 = 1;
  local_d8 = 0x98;
  local_dc = 0x18;
  local_e0 = 0x18;
  local_e4 = 0x224;
  local_e8 = 0x18;
  iVar5 = (**(code **)(*piVar6 + 0x14))(piVar6);
  if (0 < iVar5) {
    do {
      local_b0 = 0x7ffffffe;
      piVar6 = *(int **)(param_1 + 0xb0);
      cVar4 = FUN_00186d16(*(undefined4 *)(piVar6[0x22] + 8));
      if (cVar4 == '\0') {
        cVar4 = FUN_00186d28(*(undefined4 *)(piVar6[0x22] + 8));
        if (cVar4 == '\0') {
          cVar4 = FUN_001190ce(*(undefined4 *)(piVar6[0x22] + 8));
          if (cVar4 == '\0') {
            cVar4 = FUN_0011902c(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8));
            if (cVar4 == '\0') {
              local_b0 = FUN_00187782(param_1);
              piVar6 = *(int **)(param_1 + 0xb0);
            }
            else {
              local_b0 = FUN_0018711e(param_1);
              piVar6 = *(int **)(param_1 + 0xb0);
            }
          }
          else {
            local_b0 = FUN_001883e0(param_1);
            piVar6 = *(int **)(param_1 + 0xb0);
          }
        }
        else {
          local_b0 = FUN_001884b0(param_1);
          piVar6 = *(int **)(param_1 + 0xb0);
        }
      }
      if ((*(byte *)(piVar6 + 5) & 2) == 0) {
LAB_0018d3d5:
        if (((*(int *)((int)piVar6 + local_e8 + 0x98) == 0x33) ||
            (*(int *)((int)piVar6 + local_e8 + 0x98) == 0xc)) ||
           (*(uint *)(local_e4 + 4 + param_1) == DAT_001cc730)) goto LAB_0018d5b4;
        local_40[1] = 0;
        local_40[2] = 0;
        local_40[3] = 0;
        local_40[4] = 0;
        pcVar15 = (char *)(param_1 + 4 + local_e4);
        piVar6 = (int *)(local_64 * 0x10 + 0x168 + param_1);
        bVar2 = true;
        local_54 = 1;
        do {
          if (*pcVar15 != '\0') {
            if (*piVar6 < 0) {
              piVar7 = (int *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238));
              local_40[local_54] = *piVar7;
            }
            else {
              bVar2 = false;
            }
          }
          local_54 = local_54 + 1;
          pcVar15 = pcVar15 + 1;
          piVar6 = piVar6 + 1;
        } while (local_54 != 5);
        uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x3f4);
        local_40[5] = FUN_000f5b96(DAT_001cc728);
        if (local_b0 != 0x7ffffffe) {
          piVar6 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
          iVar5 = (**(code **)(*piVar6 + 0x154))(piVar6,uVar12,local_40 + 1,local_40 + 5);
          if (iVar5 == 0) {
            pcVar15 = (char *)(param_1 + 4 + local_e4);
            iVar5 = 1;
            piVar6 = local_40 + 2;
            do {
              if (*pcVar15 != '\0') {
                piVar6[0xffffffff] = piVar6[0xffffffff] ^ _DAT_001cc750;
              }
              iVar5 = iVar5 + 1;
              piVar6 = piVar6 + 1;
              pcVar15 = pcVar15 + 1;
            } while (iVar5 != 5);
            goto LAB_0018d945;
          }
LAB_0018d53e:
          uVar12 = 0;
LAB_0018d540:
          piVar6 = *(int **)(param_1 + 0xb0);
          if (*(int *)(local_e0 + 0x98 + (int)piVar6) != *(int *)(iVar5 + 0x98)) {
            piVar7 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
            cVar4 = (**(code **)(*piVar7 + 0x11c))
                              (piVar7,piVar6,local_64,iVar5,0,uVar12,*(int *)(param_1 + 0x238));
            if (cVar4 == '\0') goto LAB_0018d5ab;
            uVar12 = ((int (*)())FUN_0018b574)(param_1,local_64,iVar5,local_40[5],uVar12,0,
                                  *(undefined4 *)(param_1 + 0x238));
            *(undefined4 *)(local_50 + 0x214) = uVar12;
            iVar11 = 0;
            iVar5 = param_1;
            do {
              iVar13 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0));
              if (*(char *)(iVar11 + 0x10 + iVar13) == '\x01') {
                *(undefined4 *)(iVar5 + 0x30) = 0;
              }
              iVar11 = iVar11 + 1;
              iVar5 = iVar5 + 4;
            } while (iVar11 != 4);
            local_a1 = 1;
            piVar6 = *(int **)(param_1 + 0xb0);
          }
          goto LAB_0018d5b4;
        }
        if (bVar2) {
          piVar6 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
          iVar5 = (**(code **)(*piVar6 + 0x154))(piVar6,uVar12,local_40 + 1,local_40 + 5);
          if (iVar5 != 0) goto LAB_0018d53e;
          pcVar15 = (char *)(param_1 + 4 + local_e4);
          iVar5 = 1;
          piVar6 = local_40 + 2;
          do {
            if (*pcVar15 != '\0') {
              piVar6[0xffffffff] = piVar6[0xffffffff] ^ _DAT_001cc750;
            }
            iVar5 = iVar5 + 1;
            piVar6 = piVar6 + 1;
            pcVar15 = pcVar15 + 1;
          } while (iVar5 != 5);
LAB_0018d945:
          piVar6 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
          iVar5 = (**(code **)(*piVar6 + 0x154))(piVar6,uVar12,local_40 + 1,local_40 + 5);
          if (iVar5 != 0) {
            uVar12 = 1;
            goto LAB_0018d540;
          }
LAB_0018d5ab:
          piVar6 = *(int **)(param_1 + 0xb0);
          goto LAB_0018d5b4;
        }
        piVar6 = *(int **)(param_1 + 0xb0);
      }
      else {
        piVar6 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
        cVar4 = (**(code **)(*piVar6 + 0xbc))(piVar6);
        if (cVar4 != '\0') {
          piVar6 = *(int **)(param_1 + 0xb0);
          goto LAB_0018d3d5;
        }
        piVar6 = *(int **)(param_1 + 0xb0);
LAB_0018d5b4:
        if (local_b0 != 0x7ffffffe) {
          if (*(int *)(piVar6[0x22] + 8) != 0x8e) {
            pcVar15 = (char *)(param_1 + 4 + local_e4);
            iVar5 = 0;
            do {
              if (*pcVar15 != '\0') {
                FUN_0010b0f4(piVar6);
                piVar6 = *(int **)(param_1 + 0xb0);
                break;
              }
              iVar5 = iVar5 + 1;
              pcVar15 = pcVar15 + 1;
            } while (iVar5 != 4);
            puVar1 = *(uint **)(*(int *)(local_dc + 0x8c + (int)piVar6) + 0x2c);
            uVar10 = puVar1[1];
            uVar16 = uVar10 - 1;
            if (uVar16 < *puVar1) {
              if (uVar10 <= uVar16) {
                _memset((void *)(puVar1[2] + uVar10 * 4),0,(uVar16 - uVar10) * 4 + 4);
                puVar1[1] = uVar10;
              }
            }
            else {
              FUN_001a7f7c(puVar1);
            }
            FUN_001836ee(*(undefined4 *)(param_1 + 0x238));
          }
          piVar6 = (int *)FUN_001840fe(*(undefined4 *)(param_1 + 0x238));
          if (*piVar6 == 0) {
            piVar6 = *(int **)(param_1 + 0xb0);
            if ((*(byte *)((int)piVar6 + local_d8 + 0x20) & 2) != 0) {
              FUN_00109c0e((int)piVar6 + local_d8 + 0xc,2,0);
              local_a1 = 1;
              piVar6 = *(int **)(param_1 + 0xb0);
            }
            if ((*(byte *)((int)piVar6 + local_d8 + 0x20) & 1) != 0) {
              uVar12 = 1;
LAB_0018d6b6:
              FUN_00109c0e((int)piVar6 + local_d8 + 0xc,uVar12,0);
              local_a1 = 1;
              piVar6 = *(int **)(param_1 + 0xb0);
            }
          }
          else if (*piVar6 < 1) {
            piVar6 = *(int **)(param_1 + 0xb0);
            if ((*(byte *)((int)piVar6 + local_d8 + 0x20) & 2) != 0) {
              FUN_00109c0e((int)piVar6 + local_d8 + 0xc,2,0);
              FUN_00109c0e(*(int *)(param_1 + 0xb0) + 0xc + local_d8,1,
                           (*(uint *)(*(int *)(param_1 + 0xb0) + 0x20 + local_d8) ^ 1) & 1);
              local_a1 = 1;
              piVar6 = *(int **)(param_1 + 0xb0);
            }
          }
          else {
            piVar6 = *(int **)(param_1 + 0xb0);
            if ((*(byte *)((int)piVar6 + local_d8 + 0x20) & 2) != 0) {
              uVar12 = 2;
              goto LAB_0018d6b6;
            }
          }
        }
      }
      local_64 = local_64 + 1;
      local_e8 = local_e8 + 0x18;
      local_e4 = local_e4 + 4;
      local_e0 = local_e0 + 0x18;
      local_dc = local_dc + 0x18;
      local_d8 = local_d8 + 0x18;
      local_50 = local_50 + 4;
      iVar5 = (**(code **)(*piVar6 + 0x14))(piVar6);
    } while (local_64 <= iVar5);
  }
  return local_a1;
}

/* FUN_0018e4da @ 0x18e4da (626 bytes) */
int FUN_0018e4da(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  undefined1 uVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar13 = *(int *)(param_1 + 0xb0);
  uVar3 = *(undefined4 *)(iVar13 + 4);
  uVar4 = *(undefined4 *)(iVar13 + 0x158);
  FUN_001a7d72(iVar13);
  uVar5 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar13 = FUN_0010b0f4(*(int *)(param_1 + 0xb0),0);
  uVar6 = *(undefined4 *)(iVar13 + 0x10);
  iVar13 = *(int *)(param_1 + 0xb0);
  uVar1 = *(undefined1 *)(iVar13 + 0x120);
  uVar7 = *(undefined4 *)(param_2 * 0x18 + 0x8c + iVar13);
  iVar13 = FUN_0010b0f4(iVar13,param_2);
  bVar2 = *(byte *)(param_3 + 0x10 + iVar13);
  iVar13 = *(int *)(param_1 + 0xb0);
  uVar8 = *(uint *)(param_2 * 0x18 + 0xa0 + iVar13);
  uVar9 = *(undefined4 *)(param_1 + 0x210 + param_2 * 4);
  uVar10 = *(uint *)(iVar13 + 0x14);
  uVar14 = uVar10 >> 9;
  if ((uVar14 & 1) == 0) {
    local_30 = 0;
    local_2c = 0;
  }
  else {
    local_30 = *(undefined4 *)(param_1 + 0x210 + *(int *)(iVar13 + 0x84) * 4);
    local_2c = *(undefined4 *)(iVar13 + 0x8c + *(int *)(iVar13 + 0x84) * 0x18);
  }
  uVar11 = *(undefined4 *)(iVar13 + 0x94);
  uVar12 = *(undefined4 *)(iVar13 + 0x98);
  FUN_0010db52(iVar13,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_0010a3c2(iVar13,0,uVar5);
  *(undefined4 *)(iVar13 + 0x94) = uVar11;
  *(undefined4 *)(iVar13 + 0x98) = uVar12;
  *(undefined4 *)(iVar13 + 0x9c) = uVar6;
  *(undefined1 *)(iVar13 + 0x120) = uVar1;
  *(undefined4 *)(iVar13 + 0x124) = param_4;
  FUN_0010a3c2(iVar13,1,uVar7);
  uVar5 = *(undefined4 *)(PTR_DAT_00213485 + (uint)bVar2 * 4);
  iVar15 = FUN_0010b0f4(iVar13,1);
  *(undefined4 *)(iVar15 + 0x10) = uVar5;
  FUN_00109c0e(iVar13 + 0xa4,1,(byte)uVar8 & 1);
  FUN_00109c0e(iVar13 + 0xa4,2,(byte)(uVar8 >> 1) & 1);
  *(undefined4 *)(param_1 + 0x214) = uVar9;
  if ((uVar14 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_0010a6a6(iVar13,local_2c,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar13 + 0x14) = *(uint *)(iVar13 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = local_30;
  }
  if ((uVar10 & 0x200000) != 0) {
    *(uint *)(iVar13 + 0x14) = *(uint *)(iVar13 + 0x14) | 0x200000;
  }
  FUN_000e9596(uVar4,uVar3,iVar13);
  return iVar13;
}

/* FUN_0018e754 @ 0x18e754 (433 bytes) */
int FUN_0018e754(param_1)
  int param_1;
{
  float fVar1;
  int *piVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int local_28;
  int local_24;
  
  iVar5 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),0);
  iVar5 = *(int *)(iVar5 + 4);
  local_24 = 2;
  do {
    cVar3 = FUN_00186f88(param_1,local_24,1,1,1,0);
    if (cVar3 != '\0') {
      cVar3 = (local_24 == 1) + '\x01';
      local_28 = 0;
      piVar8 = &DAT_001f9020;
      iVar9 = local_24 * 4;
      do {
        if ((iVar5 == *(int *)(param_1 + 0x168 + (iVar9 + *piVar8) * 4)) &&
           (iVar5 == *(int *)(param_1 + 0x168 + (iVar9 + piVar8[1]) * 4))) {
          pfVar6 = (float *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),
                                         *(undefined4 *)(param_1 + 0x168 + (iVar9 + piVar8[2]) * 4))
          ;
          fVar1 = *pfVar6;
          if ((fVar1 == FLOAT_001c5ba4) && (!NAN(fVar1) && !NAN(FLOAT_001c5ba4))) {
            ((int (*)())FUN_0018e4da)(param_1,cVar3,local_28,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124));
            FUN_00184a5a(param_1);
            return 1;
          }
          iVar7 = ((int (*)())FUN_0010fdbc)(fVar1);
          if (iVar7 != 0) {
            iVar7 = iVar7 + *(int *)(*(int *)(param_1 + 0xb0) + 0x124);
            piVar2 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
            cVar4 = (**(code **)(*piVar2 + 0xfc))(piVar2,iVar7,*(int *)(param_1 + 0xb0));
            if (cVar4 != '\0') {
              ((int (*)())FUN_0018e4da)(param_1,cVar3,local_28,iVar7);
              FUN_00184a5a(param_1);
              return 1;
            }
          }
        }
        local_28 = local_28 + 1;
        piVar8 = piVar8 + 3;
      } while (local_28 != 3);
    }
    local_24 = local_24 + -1;
    if (local_24 == 0) {
      return 0;
    }
  } while( true );
}

/* FUN_0018e906 @ 0x18e906 (394 bytes) */
int FUN_0018e906(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  iVar2 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),0);
  iVar2 = *(int *)(iVar2 + 4);
  iVar3 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),0x3f800000);
  iVar3 = *(int *)(iVar3 + 4);
  cVar1 = '\x01';
  iVar5 = 2;
  iVar4 = *(int *)(param_1 + 0x18c);
  iVar6 = param_1 + 0x20;
  if (iVar2 == iVar4) goto LAB_0018e99d;
  do {
    do {
      if (iVar2 == *(int *)(iVar6 + 0x168)) {
        iVar7 = *(int *)(iVar6 + 0x170);
        if (((iVar2 == iVar7) && (iVar2 == *(int *)(iVar6 + 0x174))) && (iVar3 == iVar4)) {
          uVar9 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
          uVar8 = 1;
          goto LAB_0018e9d3;
        }
        if (iVar2 == iVar4) {
          if ((iVar2 == *(int *)(iVar6 + 0x174)) && (iVar3 == iVar7)) {
            uVar9 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
            uVar8 = 2;
            goto LAB_0018e9d3;
          }
          if ((iVar2 == iVar7) && (iVar3 == *(int *)(iVar6 + 0x174))) {
            uVar9 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
            uVar8 = 3;
            goto LAB_0018e9d3;
          }
        }
      }
      iVar5 = iVar5 + -1;
      iVar7 = iVar6 + -0x10;
      if (iVar5 < 1) {
        return 0;
      }
      cVar1 = (iVar5 == 1) + '\x01';
      iVar4 = *(int *)(iVar6 + 0x15c);
      iVar6 = iVar7;
    } while (iVar2 != iVar4);
LAB_0018e99d: ;
  } while (((iVar2 != *(int *)(iVar6 + 0x170)) || (iVar2 != *(int *)(iVar6 + 0x174))) ||
          (iVar3 != *(int *)(iVar6 + 0x168)));
  uVar9 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
  uVar8 = 0;
LAB_0018e9d3:
  ((int (*)())FUN_0018e4da)(param_1,cVar1,uVar8,uVar9);
  FUN_00184a5a(param_1);
  return 1;
}

/* FUN_0018ea90 @ 0x18ea90 (617 bytes) */
int FUN_0018ea90(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar14 = *(int *)(param_1 + 0xb0);
  uVar2 = *(undefined4 *)(iVar14 + 4);
  uVar3 = *(undefined4 *)(iVar14 + 0x158);
  FUN_001a7d72(iVar14);
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar14 = FUN_0010b0f4(*(int *)(param_1 + 0xb0),0);
  uVar5 = *(undefined4 *)(iVar14 + 0x10);
  iVar14 = *(int *)(param_1 + 0xb0);
  uVar1 = *(undefined1 *)(iVar14 + 0x120);
  uVar6 = *(undefined4 *)(iVar14 + 0x124);
  uVar7 = *(undefined4 *)(param_2 * 0x18 + 0x8c + iVar14);
  iVar14 = FUN_0010b0f4(iVar14,param_2);
  uVar8 = *(undefined4 *)(iVar14 + 0x10);
  iVar14 = *(int *)(param_1 + 0xb0);
  uVar9 = *(uint *)(param_2 * 0x18 + 0xa0 + iVar14);
  uVar10 = *(undefined4 *)(param_1 + 0x210 + param_2 * 4);
  uVar11 = *(uint *)(iVar14 + 0x14);
  uVar15 = uVar11 >> 9;
  if ((uVar15 & 1) == 0) {
    local_24 = 0;
    local_20 = 0;
  }
  else {
    local_24 = *(undefined4 *)(param_1 + 0x210 + *(int *)(iVar14 + 0x84) * 4);
    local_20 = *(undefined4 *)(iVar14 + 0x8c + *(int *)(iVar14 + 0x84) * 0x18);
  }
  uVar12 = *(undefined4 *)(iVar14 + 0x94);
  uVar13 = *(undefined4 *)(iVar14 + 0x98);
  FUN_0010db52(iVar14,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_0010a3c2(iVar14,0,uVar4);
  *(undefined4 *)(iVar14 + 0x94) = uVar12;
  *(undefined4 *)(iVar14 + 0x98) = uVar13;
  *(undefined4 *)(iVar14 + 0x9c) = uVar5;
  *(undefined1 *)(iVar14 + 0x120) = uVar1;
  *(undefined4 *)(iVar14 + 0x124) = uVar6;
  FUN_0010a3c2(iVar14,1,uVar7);
  iVar16 = FUN_0010b0f4(iVar14,1);
  *(undefined4 *)(iVar16 + 0x10) = uVar8;
  FUN_00109c0e(iVar14 + 0xa4,1,(byte)uVar9 & 1);
  FUN_00109c0e(iVar14 + 0xa4,2,(byte)(uVar9 >> 1) & 1);
  *(undefined4 *)(param_1 + 0x214) = uVar10;
  if ((uVar15 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_0010a6a6(iVar14,local_20,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar14 + 0x14) = *(uint *)(iVar14 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = local_24;
  }
  if ((uVar11 & 0x200000) != 0) {
    *(uint *)(iVar14 + 0x14) = *(uint *)(iVar14 + 0x14) | 0x200000;
  }
  FUN_000e9596(uVar3,uVar2,iVar14);
  return iVar14;
}

/* FUN_0018ed02 @ 0x18ed02 (127 bytes) */
int FUN_0018ed02(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  
  cVar3 = ((int (*)())FUN_0018a266)(param_1,2,3);
  if (cVar3 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xe8);
    if ((((byte)uVar1 & 1) == ((byte)uVar2 & 1)) &&
       (((byte)(uVar1 >> 1) & 1) == ((byte)(uVar2 >> 1) & 1))) {
      ((int (*)())FUN_0018ea90)(param_1,2);
      FUN_00184a5a(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_0018ed82 @ 0x18ed82 (314 bytes) */
int FUN_0018ed82(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  undefined4 uVar6;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
  cVar5 = (**(code **)(*piVar1 + 0x88))(piVar1);
  if (((cVar5 == '\0') || (cVar5 = ((int (*)())FUN_0018a266)(param_1,2,3), cVar5 == '\0')) ||
     (cVar5 = ((int (*)())FUN_0018a266)(param_1,1,3), cVar5 == '\0')) {
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0xb0);
  if ((*(uint *)(iVar2 + 0xb8) & 2) != 0) {
    return 0;
  }
  uVar3 = *(uint *)(iVar2 + 0xd0);
  if ((uVar3 & 2) != 0) {
    return 0;
  }
  uVar4 = *(uint *)(iVar2 + 0xe8);
  if ((uVar4 & 2) != 0) {
    return 0;
  }
  if ((*(uint *)(iVar2 + 0xb8) & 1) == 0) {
    if ((uVar3 & 1) != 0) {
      return 0;
    }
    if ((uVar4 & 1) == 0) {
      return 0;
    }
  }
  else {
    if ((uVar3 & 1) == 0) {
      if ((uVar4 & 1) == 0) {
        return 0;
      }
      ((int (*)())FUN_0018ea90)(param_1,2);
      FUN_00109c0e(*(int *)(param_1 + 0xb0) + 0xa4,2,1);
      uVar6 = 1;
      goto LAB_0018ee3c;
    }
    if ((uVar4 & 1) != 0) {
      return 0;
    }
  }
  ((int (*)())FUN_0018ea90)(param_1,2);
  uVar6 = 2;
LAB_0018ee3c:
  FUN_00109c0e(*(int *)(param_1 + 0xb0) + 0xa4,uVar6,1);
  FUN_00184a5a(param_1);
  return 1;
}

/* FUN_0018eebc @ 0x18eebc (456 bytes) */
int FUN_0018eebc(param_1)
  int param_1;
{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_28;
  int local_20;
  
  iVar3 = FUN_00186b2c(0);
  bVar2 = false;
  local_28 = -1;
  local_20 = 0;
  iVar7 = param_1;
  do {
    iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    iVar5 = local_28;
    if (*(char *)(local_20 + 0x10 + iVar4) != '\x01') {
      iVar5 = *(int *)(iVar7 + 0x178);
      if (iVar5 < 0) {
        puVar6 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar5);
        iVar4 = FUN_00186b2c(*puVar6);
        iVar5 = *(int *)(param_1 + 0xb0);
      }
      else {
        if (iVar5 < 1) {
          return 0;
        }
        iVar5 = FUN_001836c0(*(undefined4 *)(param_1 + 0x238),iVar5);
        iVar4 = *(int *)(iVar5 + 0xc);
        iVar5 = *(int *)(param_1 + 0xb0);
        if ((*(uint *)(iVar5 + 0xb8) & 2) != 0) {
          iVar4 = (DAT_001f90bc)[iVar4];
        }
        if ((*(uint *)(iVar5 + 0xb8) & 1) != 0) {
          iVar4 = *(int *)(&DAT_001f90a4 + iVar4 * 4);
        }
        bVar2 = true;
      }
      iVar5 = FUN_0011074c(iVar5);
      iVar5 = *(int *)(&DAT_001f90e0 + (iVar4 * 0x30 + iVar5 * 6 + iVar3) * 4);
      if (iVar5 == 1) {
        iVar4 = 2;
      }
      else if (iVar5 == 2) {
        iVar4 = 3;
      }
      else {
        if (iVar5 == 0) {
          return 0;
        }
        iVar4 = 0;
      }
      iVar5 = iVar4;
      if ((local_28 != -1) && (iVar5 = local_28, iVar4 != local_28)) {
        return 0;
      }
    }
    local_28 = iVar5;
    iVar7 = iVar7 + 4;
    local_20 = local_20 + 1;
    if (local_20 == 4) {
      if (bVar2) {
        piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x134);
        *piVar1 = *piVar1 + 1;
        ((int (*)())FUN_0018ea90)(param_1,local_28);
        FUN_00184a5a(param_1);
      }
      else {
        ((int (*)())FUN_0018ea90)(param_1,local_28);
        FUN_00184a5a(param_1);
      }
      return 1;
    }
  } while( true );
}

/* FUN_0018f084 @ 0x18f084 (296 bytes) */
int FUN_0018f084(param_1)
  int param_1;
{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),0x3f800000);
  uVar1 = *(undefined4 *)(iVar3 + 4);
  iVar3 = 1;
  do {
    cVar2 = FUN_00187720(param_1,uVar1,iVar3);
    if (cVar2 != '\0') {
      ((int (*)())FUN_0018ea90)(param_1,(iVar3 == 1) + '\x01');
      FUN_00184a5a(param_1);
      return 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 3);
  iVar3 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),0xbf800000);
  uVar1 = *(undefined4 *)(iVar3 + 4);
  iVar3 = 1;
  do {
    cVar2 = FUN_00187720(param_1,uVar1,iVar3);
    if (cVar2 != '\0') {
      iVar3 = (iVar3 == 1) + 1;
      ((int (*)())FUN_0018ea90)(param_1,iVar3);
      FUN_00109c0e(*(int *)(param_1 + 0xb0) + 0xa4,1,
                   *(byte *)(*(int *)(param_1 + 0xb0) + 0xa0 + iVar3 * 0x18) & 1 ^ 1);
      FUN_00184a5a(param_1);
      return 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 3);
  return 0;
}

/* FUN_0018f1ac @ 0x18f1ac (127 bytes) */
int FUN_0018f1ac(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  
  cVar3 = ((int (*)())FUN_0018a266)(param_1,1,2);
  if (cVar3 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    if ((((byte)uVar1 & 1) == ((byte)uVar2 & 1)) &&
       (((byte)(uVar1 >> 1) & 1) == ((byte)(uVar2 >> 1) & 1))) {
      ((int (*)())FUN_0018ea90)(param_1,1);
      FUN_00184a5a(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_0018f22c @ 0x18f22c (635 bytes) */
int FUN_0018f22c(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int local_58;
  int local_54;
  int local_48;
  int local_44;
  int local_40;
  int local_2c [7];
  
  bVar1 = false;
  local_48 = -1;
  local_44 = 0;
  local_58 = param_1 + 0x160;
  do {
    iVar2 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    iVar4 = local_48;
    if (*(char *)(local_44 + 0x10 + iVar2) != '\x01') {
      iVar8 = local_58 + 8;
      local_40 = 1;
      local_54 = 0x98;
      piVar7 = local_2c;
      iVar2 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0));
      if (0 < iVar2) {
        do {
          piVar7 = (int *)((int)piVar7 + 4);
          iVar2 = *(int *)(iVar8 + 0x10);
          if (iVar2 < 0) {
            puVar5 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar2);
            iVar2 = FUN_00186b2c(*puVar5);
            piVar7[0xffffffff] = iVar2;
            piVar6 = *(int **)(param_1 + 0xb0);
          }
          else {
            if (iVar2 < 1) {
              return 0;
            }
            iVar2 = FUN_001836c0(*(undefined4 *)(param_1 + 0x238),iVar2);
            iVar2 = *(int *)(iVar2 + 0xc);
            piVar7[0xffffffff] = iVar2;
            piVar6 = *(int **)(param_1 + 0xb0);
            uVar3 = *(uint *)((int)piVar6 + local_54 + 0x20);
            if ((uVar3 & 2) != 0) {
              piVar7[0xffffffff] = (DAT_001f90bc)[iVar2];
              uVar3 = *(uint *)((int)piVar6 + local_54 + 0x20);
            }
            if ((uVar3 & 1) != 0) {
              piVar7[0xffffffff] = *(int *)(&DAT_001f90a4 + piVar7[0xffffffff] * 4);
            }
            bVar1 = true;
          }
          local_40 = local_40 + 1;
          local_54 = local_54 + 0x18;
          iVar8 = iVar8 + 0x10;
          iVar2 = (**(code **)(*piVar6 + 0x14))(piVar6);
        } while (local_40 <= iVar2);
      }
      if (local_2c[0] == 3) {
        if (local_2c[1] == 3) goto joined_r0x0018f39b;
        iVar4 = *(int *)(&DAT_001f8ee0 + (local_2c[1] + 0x12) * 4);
      }
      else {
        iVar4 = *(int *)(&DAT_001f8ee0 + (local_2c[1] + local_2c[0] * 6) * 4);
      }
      if (iVar4 == 1) {
        iVar2 = 1;
      }
      else if (iVar4 == 2) {
        iVar2 = 2;
      }
      else {
        if (iVar4 == 0) {
          return 0;
        }
        iVar2 = 0;
      }
      iVar4 = iVar2;
      if ((local_48 != -1) && (iVar4 = local_48, iVar2 != local_48)) {
        return 0;
      }
    }
joined_r0x0018f39b:
    local_48 = iVar4;
    local_58 = local_58 + 4;
    local_44 = local_44 + 1;
    if (local_44 == 4) {
      iVar4 = 1;
      if (local_48 != -1) {
        iVar4 = local_48;
      }
      if (bVar1) {
        piVar7 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x134);
        *piVar7 = *piVar7 + 1;
        ((int (*)())FUN_0018ea90)(param_1,iVar4);
        FUN_00184a5a(param_1);
      }
      else {
        ((int (*)())FUN_0018ea90)(param_1,iVar4);
        FUN_00184a5a(param_1);
      }
      return 1;
    }
  } while( true );
}

/* FUN_0018f4a8 @ 0x18f4a8 (635 bytes) */
int FUN_0018f4a8(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int local_58;
  int local_54;
  int local_48;
  int local_44;
  int local_40;
  int local_2c [7];
  
  bVar1 = false;
  local_48 = -1;
  local_44 = 0;
  local_58 = param_1 + 0x160;
  do {
    iVar2 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    iVar4 = local_48;
    if (*(char *)(local_44 + 0x10 + iVar2) != '\x01') {
      iVar8 = local_58 + 8;
      local_40 = 1;
      local_54 = 0x98;
      piVar7 = local_2c;
      iVar2 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0));
      if (0 < iVar2) {
        do {
          piVar7 = (int *)((int)piVar7 + 4);
          iVar2 = *(int *)(iVar8 + 0x10);
          if (iVar2 < 0) {
            puVar5 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar2);
            iVar2 = FUN_00186b2c(*puVar5);
            piVar7[0xffffffff] = iVar2;
            piVar6 = *(int **)(param_1 + 0xb0);
          }
          else {
            if (iVar2 < 1) {
              return 0;
            }
            iVar2 = FUN_001836c0(*(undefined4 *)(param_1 + 0x238),iVar2);
            iVar2 = *(int *)(iVar2 + 0xc);
            piVar7[0xffffffff] = iVar2;
            piVar6 = *(int **)(param_1 + 0xb0);
            uVar3 = *(uint *)((int)piVar6 + local_54 + 0x20);
            if ((uVar3 & 2) != 0) {
              piVar7[0xffffffff] = (DAT_001f90bc)[iVar2];
              uVar3 = *(uint *)((int)piVar6 + local_54 + 0x20);
            }
            if ((uVar3 & 1) != 0) {
              piVar7[0xffffffff] = *(int *)(&DAT_001f90a4 + piVar7[0xffffffff] * 4);
            }
            bVar1 = true;
          }
          local_40 = local_40 + 1;
          local_54 = local_54 + 0x18;
          iVar8 = iVar8 + 0x10;
          iVar2 = (**(code **)(*piVar6 + 0x14))(piVar6);
        } while (local_40 <= iVar2);
      }
      if (local_2c[0] == 3) {
        if (local_2c[1] == 3) goto joined_r0x0018f617;
        iVar4 = *(int *)(&DAT_001f8f80 + (local_2c[1] + 0x12) * 4);
      }
      else {
        iVar4 = *(int *)(&DAT_001f8f80 + (local_2c[1] + local_2c[0] * 6) * 4);
      }
      if (iVar4 == 1) {
        iVar2 = 1;
      }
      else if (iVar4 == 2) {
        iVar2 = 2;
      }
      else {
        if (iVar4 == 0) {
          return 0;
        }
        iVar2 = 0;
      }
      iVar4 = iVar2;
      if ((local_48 != -1) && (iVar4 = local_48, iVar2 != local_48)) {
        return 0;
      }
    }
joined_r0x0018f617:
    local_48 = iVar4;
    local_58 = local_58 + 4;
    local_44 = local_44 + 1;
    if (local_44 == 4) {
      iVar4 = 1;
      if (local_48 != -1) {
        iVar4 = local_48;
      }
      if (bVar1) {
        piVar7 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x134);
        *piVar7 = *piVar7 + 1;
        ((int (*)())FUN_0018ea90)(param_1,iVar4);
        FUN_00184a5a(param_1);
      }
      else {
        ((int (*)())FUN_0018ea90)(param_1,iVar4);
        FUN_00184a5a(param_1);
      }
      return 1;
    }
  } while( true );
}

/* FUN_0018f724 @ 0x18f724 (164 bytes) */
int FUN_0018f724(param_1)
  int param_1;
{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),0);
  uVar1 = *(undefined4 *)(iVar3 + 4);
  iVar3 = 1;
  do {
    cVar2 = FUN_00187720(param_1,uVar1,iVar3);
    if (cVar2 != '\0') {
      cVar2 = FUN_001879bc(param_1,0,3);
      if (cVar2 == '\0') {
        ((int (*)())FUN_0018ea90)(param_1,3);
      }
      else {
        FUN_00187b3e(param_1);
      }
      FUN_00184a5a(param_1);
      return 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 3);
  return 0;
}

/* FUN_0018f7c8 @ 0x18f7c8 (191 bytes) */
int FUN_0018f7c8(param_1)
  int param_1;
{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int local_24;
  undefined4 local_20;
  
  iVar3 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),0);
  uVar1 = *(undefined4 *)(iVar3 + 4);
  local_24 = 1;
  do {
    local_20 = 2;
    do {
      cVar2 = FUN_00187720(param_1,uVar1,local_24);
      if (cVar2 != '\0') {
        cVar2 = FUN_001879bc(param_1,0,local_20);
        if (cVar2 == '\0') {
          ((int (*)())FUN_0018ea90)(param_1,local_20);
        }
        else {
          FUN_00187b3e(param_1);
        }
        FUN_00184a5a(param_1);
        return 1;
      }
      local_24 = local_24 + 1;
      if (2 < local_24) {
        return 0;
      }
      local_20 = 1;
    } while (local_24 != 1);
  } while( true );
}

/* FUN_0018f888 @ 0x18f888 (652 bytes) */
int FUN_0018f888(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined4 local_34;
  undefined4 local_30;
  
  iVar11 = *(int *)(param_1 + 0xb0);
  uVar2 = *(undefined4 *)(iVar11 + 4);
  uVar3 = *(undefined4 *)(iVar11 + 0x158);
  FUN_001a7d72(iVar11);
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar11 = FUN_0010b0f4(*(int *)(param_1 + 0xb0),0);
  uVar5 = *(undefined4 *)(iVar11 + 0x10);
  iVar11 = *(int *)(param_1 + 0xb0);
  uVar1 = *(undefined1 *)(iVar11 + 0x120);
  uVar6 = *(undefined4 *)(iVar11 + 0x124);
  uVar7 = *(uint *)(iVar11 + 0x14);
  uVar12 = uVar7 >> 9;
  if ((uVar12 & 1) == 0) {
    local_34 = 0;
    local_30 = 0;
  }
  else {
    local_34 = *(undefined4 *)(param_1 + 0x210 + *(int *)(iVar11 + 0x84) * 4);
    local_30 = *(undefined4 *)(iVar11 + 0x8c + *(int *)(iVar11 + 0x84) * 0x18);
  }
  uVar8 = *(undefined4 *)(iVar11 + 0x94);
  uVar9 = *(undefined4 *)(iVar11 + 0x98);
  FUN_0010db52(iVar11,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_0010a3c2(iVar11,0,uVar4);
  *(undefined4 *)(iVar11 + 0x94) = uVar8;
  *(undefined4 *)(iVar11 + 0x98) = uVar9;
  *(undefined4 *)(iVar11 + 0x9c) = uVar5;
  *(undefined1 *)(iVar11 + 0x120) = uVar1;
  *(undefined4 *)(iVar11 + 0x124) = uVar6;
  FUN_0010a3c2(iVar11,1,*(undefined4 *)(param_2 + 0xc));
  uVar4 = *(undefined4 *)(PTR_DAT_00213485 + *(int *)(param_2 + 0x10) * 4);
  iVar13 = FUN_0010b0f4(iVar11,1);
  *(undefined4 *)(iVar13 + 0x10) = uVar4;
  if (*(char *)(param_2 + 0x18) != '\0') {
    FUN_00109c0e(iVar11 + 0xa4,1,1);
  }
  *(undefined1 *)(iVar11 + 0x120) = uVar1;
  *(undefined4 *)(iVar11 + 0x124) = uVar6;
  piVar10 = *(int **)(*(int *)(iVar11 + 0xa4) + 0x18);
  if (*piVar10 == 0) {
    puVar14 = (undefined4 *)FUN_001a7f7c(piVar10,0);
    *(undefined4 *)(param_1 + 0x214) = *puVar14;
  }
  else {
    if (piVar10[1] == 0) {
      *(undefined4 *)piVar10[2] = 0;
      piVar10[1] = 1;
    }
    *(undefined4 *)(param_1 + 0x214) = *(undefined4 *)piVar10[2];
  }
  if ((uVar12 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_0010a6a6(iVar11,local_30,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = local_34;
  }
  if ((uVar7 & 0x200000) != 0) {
    *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) | 0x200000;
  }
  FUN_000e9596(uVar3,uVar2,iVar11);
  return iVar11;
}

/* FUN_0018fb1c @ 0x18fb1c (629 bytes) */
int FUN_0018fb1c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 *param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 local_28;
  undefined4 local_24;
  
  iVar8 = *(int *)(param_1 + 0xb0);
  uVar1 = *(undefined4 *)(iVar8 + 4);
  uVar2 = *(undefined4 *)(iVar8 + 0x158);
  FUN_001a7d72(iVar8);
  uVar3 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar8 = FUN_0010b0f4(*(int *)(param_1 + 0xb0),0);
  uVar4 = *(undefined4 *)(iVar8 + 0x10);
  iVar8 = *(int *)(param_1 + 0xb0);
  uVar5 = *(uint *)(iVar8 + 0x14);
  uVar9 = uVar5 >> 9;
  if ((uVar9 & 1) == 0) {
    local_28 = 0;
    local_24 = 0;
  }
  else {
    local_28 = *(undefined4 *)(param_1 + 0x210 + *(int *)(iVar8 + 0x84) * 4);
    local_24 = *(undefined4 *)(iVar8 + 0x8c + *(int *)(iVar8 + 0x84) * 0x18);
  }
  uVar6 = *(undefined4 *)(iVar8 + 0x94);
  uVar7 = *(undefined4 *)(iVar8 + 0x98);
  FUN_0010db52(iVar8,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_0010a3c2(iVar8,0,uVar3);
  *(undefined4 *)(iVar8 + 0x94) = uVar6;
  *(undefined4 *)(iVar8 + 0x98) = uVar7;
  *(undefined4 *)(iVar8 + 0x9c) = uVar4;
  iVar10 = *(int *)(param_2 + 0x8c);
  if (*(int *)(*(int *)(iVar10 + 0x2c) + 4) == 0) {
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x238) + 0xbc);
    puVar11 = (undefined4 *)FUN_001a7bca(uVar3,0x240);
    *puVar11 = uVar3;
    puVar11 = puVar11 + 1;
    FUN_00183c52(puVar11,param_2,*(undefined4 *)(param_1 + 0x238));
    FUN_00185344(puVar11);
    FUN_00183630(puVar11);
    FUN_0012a7b2(iVar10,*(undefined4 *)(*(int *)(param_2 + 0x158) + 0xb0),puVar11);
  }
  FUN_0010a3c2(iVar8,1,iVar10);
  uVar3 = *param_3;
  iVar10 = FUN_0010b0f4(iVar8,1);
  *(undefined4 *)(iVar10 + 0x10) = uVar3;
  FUN_00109c0e(iVar8 + 0xa4,1,param_4);
  *(int *)(param_1 + 0x214) = param_2;
  if ((uVar9 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_0010a6a6(iVar8,local_24,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar8 + 0x14) = *(uint *)(iVar8 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = local_28;
  }
  if ((uVar5 & 0x200000) != 0) {
    *(uint *)(iVar8 + 0x14) = *(uint *)(iVar8 + 0x14) | 0x200000;
  }
  FUN_000e9596(uVar2,uVar1,iVar8);
  return iVar8;
}

/* FUN_0018fdb6 @ 0x18fdb6 (514 bytes) */
int FUN_0018fdb6(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar7 = *(int *)(param_1 + 0xb0);
  uVar1 = *(undefined4 *)(iVar7 + 4);
  uVar2 = *(undefined4 *)(iVar7 + 0x158);
  FUN_001a7d72(iVar7);
  uVar9 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar7 = FUN_0010b0f4(*(int *)(param_1 + 0xb0),0);
  uVar3 = *(undefined4 *)(iVar7 + 0x10);
  iVar7 = *(int *)(param_1 + 0xb0);
  uVar4 = *(uint *)(iVar7 + 0x14);
  uVar8 = uVar4 >> 9;
  if ((uVar8 & 1) == 0) {
    local_20 = 0;
    local_1c = 0;
  }
  else {
    local_20 = *(undefined4 *)(param_1 + 0x210 + *(int *)(iVar7 + 0x84) * 4);
    local_1c = *(undefined4 *)(iVar7 + 0x8c + *(int *)(iVar7 + 0x84) * 0x18);
  }
  uVar5 = *(undefined4 *)(iVar7 + 0x94);
  uVar6 = *(undefined4 *)(iVar7 + 0x98);
  FUN_0010db52(iVar7,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_0010a3c2(iVar7,0,uVar9);
  *(undefined4 *)(iVar7 + 0x94) = uVar5;
  *(undefined4 *)(iVar7 + 0x98) = uVar6;
  if ((uVar8 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_0010a6a6(iVar7,local_1c,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar7 + 0x14) = *(uint *)(iVar7 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = local_20;
  }
  *(undefined4 *)(iVar7 + 0x9c) = uVar3;
  uVar9 = ((int (*)())FUN_0018a6dc)(1,param_2,iVar7,*(undefined4 *)(param_1 + 0x238));
  *(undefined4 *)(param_1 + 0x214) = uVar9;
  iVar12 = 0;
  iVar11 = param_1;
  do {
    iVar10 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(iVar12 + 0x10 + iVar10) == '\x01') {
      *(undefined4 *)(iVar11 + 0x30) = 0;
    }
    iVar12 = iVar12 + 1;
    iVar11 = iVar11 + 4;
  } while (iVar12 != 4);
  if ((uVar4 & 0x200000) != 0) {
    *(uint *)(iVar7 + 0x14) = *(uint *)(iVar7 + 0x14) | 0x200000;
  }
  FUN_000e9596(uVar2,uVar1,iVar7);
  return iVar7;
}

/* FUN_0018ffc0 @ 0x18ffc0 (201 bytes) */
int FUN_0018ffc0(param_1)
  int param_1;
{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 auStack_30 [5];
  undefined4 local_1c [3];
  
  cVar1 = ((int (*)())FUN_0018a266)(param_1,1,2);
  if (cVar1 != '\0') {
    iVar3 = *(int *)(param_1 + 0xb0);
    if ((((byte)*(uint *)(iVar3 + 0xb8) & 1) == ((byte)*(uint *)(iVar3 + 0xd0) & 1)) &&
       (((byte)(*(uint *)(iVar3 + 0xb8) >> 1) & 1) == ((byte)(*(uint *)(iVar3 + 0xd0) >> 1) & 1))) {
      uVar4 = 0;
      cVar1 = ((bool (*)())FUN_00110958)(iVar3,0,0);
      if (cVar1 != '\0') {
        uVar4 = 0x3f800000;
      }
      puVar2 = auStack_30 + 1;
      do {
        *puVar2 = 0x7ffffffe;
        puVar2 = puVar2 + 1;
      } while (puVar2 != local_1c);
      iVar3 = 1;
      do {
        auStack_30[iVar3] = uVar4;
        iVar3 = iVar3 + 1;
      } while (iVar3 != 5);
      ((int (*)())FUN_0018fdb6)(param_1,auStack_30 + 1);
      FUN_00184a5a(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_0019008a @ 0x19008a (142 bytes) */
int FUN_0019008a(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  cVar3 = FUN_00187690(param_1,1,2);
  if (cVar3 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    if ((((byte)uVar1 & 1) == ((byte)uVar2 & 1)) &&
       (((byte)(uVar1 >> 1) & 1) == ((byte)(uVar2 >> 1) & 1))) {
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      ((int (*)())FUN_0018fdb6)(param_1,&local_2c);
      FUN_00184a5a(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_00190118 @ 0x190118 (153 bytes) */
int FUN_00190118(param_1)
  int param_1;
{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar3 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),0);
  uVar1 = *(undefined4 *)(iVar3 + 4);
  iVar3 = 1;
  do {
    cVar2 = FUN_00187720(param_1,uVar1,iVar3);
    if (cVar2 != '\0') {
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      ((int (*)())FUN_0018fdb6)(param_1,&local_2c);
      FUN_00184a5a(param_1);
      return 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 3);
  return 0;
}

/* FUN_001901b2 @ 0x1901b2 (148 bytes) */
int FUN_001901b2(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  cVar3 = ((int (*)())FUN_0018a266)(param_1,1,2);
  if (cVar3 != '\0') {
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    if ((((byte)uVar1 & 1) != ((byte)uVar2 & 1)) &&
       (((byte)(uVar1 >> 1) & 1) == ((byte)(uVar2 >> 1) & 1))) {
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      ((int (*)())FUN_0018fdb6)(param_1,&local_2c);
      FUN_00184a5a(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_00190246 @ 0x190246 (710 bytes) */
int FUN_00190246(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint *puVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  uint local_40;
  uint auStack_34 [5];
  uint local_20 [4];
  
  iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
  uVar5 = FUN_000f5fea(*(undefined4 *)(iVar4 + 0x10));
  local_20[0] = FUN_000f5b96(DAT_001cc728,uVar5);
  piVar3 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
  iVar4 = (**(code **)(*piVar3 + 0x154))
                    (piVar3,*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x3f4),param_2,local_20);
  if (iVar4 == 0) {
    puVar1 = auStack_34 + 1;
    puVar7 = puVar1;
    do {
      *puVar7 = 0x7ffffffe;
      puVar7 = puVar7 + 1;
    } while (local_20 != puVar7);
    iVar4 = 0;
    puVar7 = param_2;
    do {
      iVar6 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
      if (*(char *)(iVar4 + 0x10 + iVar6) != '\x01') {
        auStack_34[iVar4 + 1] = *puVar7 ^ 0x80000000;
      }
      iVar4 = iVar4 + 1;
      puVar7 = puVar7 + 1;
    } while (iVar4 != 4);
    piVar3 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
    iVar4 = (**(code **)(*piVar3 + 0x154))
                      (piVar3,*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x3f4),puVar1,local_20);
    if (iVar4 == 0) {
      local_40 = 0x7ffffffe;
      iVar4 = 0;
      puVar7 = param_2;
      do {
        iVar6 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar4 + 0x10 + iVar6) != '\x01') {
          FUN_001840fe(*(undefined4 *)(param_1 + 0x238),*puVar7);
          if (local_40 == 0x7ffffffe) {
            local_40 = *puVar7;
          }
          else if (local_40 != *puVar7) {
            return 0;
          }
        }
        iVar4 = iVar4 + 1;
        puVar7 = puVar7 + 1;
      } while (iVar4 != 4);
      iVar4 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),local_40);
      if (*(char *)(iVar4 + 8) == '\0') {
        return 0;
      }
      bVar2 = *(byte *)(iVar4 + 9);
      if (((((bVar2 & 1) == 0) && ((bVar2 & 2) == 0)) && ((bVar2 & 4) == 0)) && ((bVar2 & 8) == 0))
      {
        if ((*(byte *)(iVar4 + 8) & 1) == 0) {
          iVar4 = ((int (*)())FUN_0018f888)(param_1,iVar4);
          return iVar4;
        }
        iVar4 = 1;
        do {
          param_2[iVar4 + -1] = local_40;
          iVar4 = iVar4 + 1;
        } while (iVar4 != 5);
        iVar4 = ((int (*)())FUN_0018fdb6)(param_1,param_2);
        return iVar4;
      }
      iVar6 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(iVar4 + 0x14));
      puVar7 = puVar1;
      if ((*(byte *)(iVar6 + 8) & 1) == 0) {
        iVar6 = ((int (*)())FUN_0018f888)(param_1,iVar6);
      }
      else {
        do {
          *puVar7 = 0x7ffffffe;
          puVar7 = puVar7 + 1;
        } while (puVar7 != local_20);
        iVar8 = 1;
        do {
          auStack_34[iVar8] = *(uint *)(iVar6 + 0x14);
          iVar8 = iVar8 + 1;
        } while (iVar8 != 5);
        iVar6 = ((int (*)())FUN_0018fdb6)(param_1,puVar1);
      }
      if ((*(byte *)(iVar4 + 9) & 1) != 0) {
        FUN_00109c0e(iVar6 + 0xa4,1,1);
      }
      if ((*(byte *)(iVar4 + 9) & 2) != 0) {
        *(undefined4 *)(iVar6 + 0x124) = *(undefined4 *)(iVar4 + 0x1c);
        return iVar6;
      }
      return iVar6;
    }
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  iVar4 = ((int (*)())FUN_0018fb1c)(param_1,iVar4,local_20,uVar5);
  return iVar4;
}

/* FUN_0019050c @ 0x19050c (597 bytes) */
int FUN_0019050c(param_1)
  int param_1;
{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int local_68;
  int *local_64;
  int local_5c;
  int local_44;
  int local_40;
  int aiStack_3c [5];
  int local_28;
  int local_24;
  int local_20;
  
  piVar3 = aiStack_3c + 1;
  do {
    *piVar3 = 0x7ffffffe;
    piVar3 = piVar3 + 1;
  } while (&local_28 != piVar3);
  iVar4 = 1;
  do {
    aiStack_3c[iVar4] = 0x7ffffffe;
    iVar4 = iVar4 + 1;
  } while (iVar4 != 5);
  bVar2 = false;
  local_44 = 0;
  local_64 = aiStack_3c;
  local_68 = param_1 + 0x160;
  do {
    local_64 = local_64 + 1;
    iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(local_44 + 0x10 + iVar4) != '\x01') {
      iVar4 = local_68 + 8;
      local_40 = 1;
      local_5c = 0x98;
      piVar3 = &local_28;
      do {
        piVar3[1] = 0;
        iVar5 = *(int *)(iVar4 + 0x10);
        if (iVar5 < 0) {
          puVar7 = (undefined4 *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),iVar5);
          iVar5 = FUN_00186b2c(*puVar7);
          piVar3[1] = iVar5;
        }
        else {
          if (iVar5 < 1) {
            return 0;
          }
          iVar5 = FUN_001836c0(*(undefined4 *)(param_1 + 0x238),iVar5);
          iVar5 = *(int *)(iVar5 + 0xc);
          piVar3[1] = iVar5;
          iVar1 = *(int *)(param_1 + 0xb0);
          uVar6 = *(uint *)(iVar1 + 0x20 + local_5c);
          if ((uVar6 & 2) != 0) {
            piVar3[1] = (DAT_001f90bc)[iVar5];
            uVar6 = *(uint *)(iVar1 + 0x20 + local_5c);
          }
          if ((uVar6 & 1) != 0) {
            piVar3[1] = *(int *)(&DAT_001f90a4 + piVar3[1] * 4);
          }
          bVar2 = true;
        }
        iVar5 = local_24;
        if (piVar3[1] == 0) {
          return 0;
        }
        local_40 = local_40 + 1;
        local_5c = local_5c + 0x18;
        iVar4 = iVar4 + 0x10;
        piVar3 = piVar3 + 1;
      } while (local_40 != 3);
      iVar4 = FUN_0011074c(*(undefined4 *)(param_1 + 0xb0));
      iVar4 = *(int *)(&DAT_001f90e0 + (iVar5 * 0x30 + iVar4 * 6 + local_20) * 4);
      if (iVar4 == 1) {
        *local_64 = 0x3f800000;
      }
      else if (iVar4 == 2) {
        *local_64 = 0;
      }
      else if (iVar4 == 0) {
        return 0;
      }
    }
    local_68 = local_68 + 4;
    local_44 = local_44 + 1;
    if (local_44 == 4) {
      iVar4 = ((int (*)())FUN_00190246)(param_1,aiStack_3c + 1);
      if (iVar4 == 0) {
        return 0;
      }
      if (bVar2) {
        piVar3 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x134);
        *piVar3 = *piVar3 + 1;
        FUN_00184a5a(param_1);
      }
      else {
        FUN_00184a5a(param_1);
      }
      return 1;
    }
  } while( true );
}

