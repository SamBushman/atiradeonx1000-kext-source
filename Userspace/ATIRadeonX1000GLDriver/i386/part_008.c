#include "decls.h"

/* FUN_000565aa @ 0x565aa (847 bytes) */
int FUN_000565aa(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  FUN_00053994(param_2 + 7,param_3 + 4);
  cVar1 = FUN_00055c4a();
  if (cVar1 != '\0') {
    iVar4 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar3 = *(int *)(iVar4 + 0x18);
    if (0x100 < iVar3 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar3 = *(int *)(iVar4 + 0x18);
      if (*(uint *)(iVar4 + 0x20) < iVar3 + 2U) {
        uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar2,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
        *(undefined4 *)(iVar4 + 0x1c) = uVar2;
        *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
        iVar3 = *(int *)(iVar4 + 0x18);
      }
    }
    iVar4 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
    FUN_00055cba();
    FUN_00055167(iVar4,3,0,0);
    FUN_000555c4(iVar4 + 4,0);
    *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 4);
    *(byte *)(iVar4 + 9) = *(byte *)(iVar4 + 9) & 0x1f | 0x80;
    *(byte *)(iVar4 + 10) = *(byte *)(iVar4 + 10) & 0xc0 | 0x24;
    *(ushort *)(iVar4 + 10) = *(ushort *)(iVar4 + 10) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 8);
    FUN_00055167(iVar4 + 0x10,1,0,0);
    FUN_000555c4(iVar4 + 0x14,0);
    FUN_000555c4(iVar4 + 0x18,0);
    *(ushort *)(iVar4 + 0x1a) = *(ushort *)(iVar4 + 0x1a) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar4 + 0x18);
    return 2;
  }
  iVar4 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar3 = *(int *)(iVar4 + 0x18);
  if (0x100 < iVar3 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar3 = *(int *)(iVar4 + 0x18);
    if (*(uint *)(iVar4 + 0x20) < iVar3 + 1U) {
      uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar2,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
      *(undefined4 *)(iVar4 + 0x1c) = uVar2;
      *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
      iVar3 = *(int *)(iVar4 + 0x18);
    }
  }
  iVar4 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
  FUN_00055167(iVar4,1,0,0);
  FUN_000555c4(iVar4 + 4,0);
  *(ushort *)(iVar4 + 6) = *(ushort *)(iVar4 + 6) & 0xfe3f | 0x100;
  FUN_000555c4(iVar4 + 8,0);
  *(ushort *)(iVar4 + 10) = *(ushort *)(iVar4 + 10) & 0xfe3f | 0x100;
  *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 8);
  return 1;
}

/* FUN_000568f9 @ 0x568f9 (789 bytes) */
int FUN_000568f9(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = param_3 + 0x3c;
  param_3 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  cVar1 = FUN_00055c4a();
  if (cVar1 != '\0') {
    iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar4 = *(int *)(iVar5 + 0x18);
    if (0x100 < iVar4 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar4 = *(int *)(iVar5 + 0x18);
      if (*(uint *)(iVar5 + 0x20) < iVar4 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
        *(undefined4 *)(iVar5 + 0x1c) = uVar3;
        *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
        iVar4 = *(int *)(iVar5 + 0x18);
      }
    }
    iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
    uVar3 = FUN_00055cba();
    FUN_00055167(iVar5,3,0,0,iVar2,param_3,piVar6,uVar3);
    FUN_000555c4(iVar5 + 4,0);
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 4);
    *(byte *)(iVar5 + 9) = *(byte *)(iVar5 + 9) & 0x1f | 0x80;
    *(byte *)(iVar5 + 10) = *(byte *)(iVar5 + 10) & 0xc0 | 0x24;
    *(ushort *)(iVar5 + 10) = *(ushort *)(iVar5 + 10) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
    FUN_00055167(iVar5 + 0x10,1,0,0);
    FUN_000555c4(iVar5 + 0x14,0);
    FUN_000555c4(iVar5 + 0x18,0);
    *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x18);
    return 2;
  }
  iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar4 = *(int *)(iVar5 + 0x18);
  if (0x100 < iVar4 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar4 = *(int *)(iVar5 + 0x18);
    if (*(uint *)(iVar5 + 0x20) < iVar4 + 1U) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
      *(undefined4 *)(iVar5 + 0x1c) = uVar3;
      *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
      iVar4 = *(int *)(iVar5 + 0x18);
    }
  }
  iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
  FUN_00055167(iVar5,1,0,0,iVar2,param_3,piVar6);
  FUN_000555c4(iVar5 + 4,0);
  FUN_000555c4(iVar5 + 8,0);
  *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
  return 1;
}

/* FUN_00056c0e @ 0x56c0e (789 bytes) */
int FUN_00056c0e(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = param_3 + 0x3c;
  param_3 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  cVar1 = FUN_00055c4a();
  if (cVar1 != '\0') {
    iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar4 = *(int *)(iVar5 + 0x18);
    if (0x100 < iVar4 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar4 = *(int *)(iVar5 + 0x18);
      if (*(uint *)(iVar5 + 0x20) < iVar4 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
        *(undefined4 *)(iVar5 + 0x1c) = uVar3;
        *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
        iVar4 = *(int *)(iVar5 + 0x18);
      }
    }
    iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
    uVar3 = FUN_00055cba();
    FUN_00055167(iVar5,3,0,0,iVar2,param_3,piVar6,uVar3);
    FUN_000555c4(iVar5 + 4,0);
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 4);
    *(byte *)(iVar5 + 9) = *(byte *)(iVar5 + 9) & 0x1f | 0x80;
    *(byte *)(iVar5 + 10) = *(byte *)(iVar5 + 10) & 0xc0 | 0x24;
    *(ushort *)(iVar5 + 10) = *(ushort *)(iVar5 + 10) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
    FUN_00055167(iVar5 + 0x10,2,0,0);
    FUN_000555c4(iVar5 + 0x14,0);
    FUN_000555c4(iVar5 + 0x18,0);
    *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x18);
    return 2;
  }
  iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar4 = *(int *)(iVar5 + 0x18);
  if (0x100 < iVar4 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar4 = *(int *)(iVar5 + 0x18);
    if (*(uint *)(iVar5 + 0x20) < iVar4 + 1U) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
      *(undefined4 *)(iVar5 + 0x1c) = uVar3;
      *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
      iVar4 = *(int *)(iVar5 + 0x18);
    }
  }
  iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
  FUN_00055167(iVar5,2,0,0,iVar2,param_3,piVar6);
  FUN_000555c4(iVar5 + 4,0);
  FUN_000555c4(iVar5 + 8,0);
  *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
  return 1;
}

/* FUN_00056f23 @ 0x56f23 (789 bytes) */
int FUN_00056f23(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = param_3 + 0x3c;
  param_3 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  cVar1 = FUN_00055c4a();
  if (cVar1 != '\0') {
    iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar4 = *(int *)(iVar5 + 0x18);
    if (0x100 < iVar4 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar4 = *(int *)(iVar5 + 0x18);
      if (*(uint *)(iVar5 + 0x20) < iVar4 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
        *(undefined4 *)(iVar5 + 0x1c) = uVar3;
        *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
        iVar4 = *(int *)(iVar5 + 0x18);
      }
    }
    iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
    uVar3 = FUN_00055cba();
    FUN_00055167(iVar5,3,0,0,iVar2,param_3,piVar6,uVar3);
    FUN_000555c4(iVar5 + 4,0);
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 4);
    *(byte *)(iVar5 + 9) = *(byte *)(iVar5 + 9) & 0x1f | 0x80;
    *(byte *)(iVar5 + 10) = *(byte *)(iVar5 + 10) & 0xc0 | 0x24;
    *(ushort *)(iVar5 + 10) = *(ushort *)(iVar5 + 10) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
    FUN_00055167(iVar5 + 0x10,3,0,0);
    FUN_000555c4(iVar5 + 0x14,0);
    FUN_000555c4(iVar5 + 0x18,0);
    *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x18);
    return 2;
  }
  iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar4 = *(int *)(iVar5 + 0x18);
  if (0x100 < iVar4 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar4 = *(int *)(iVar5 + 0x18);
    if (*(uint *)(iVar5 + 0x20) < iVar4 + 1U) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
      *(undefined4 *)(iVar5 + 0x1c) = uVar3;
      *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
      iVar4 = *(int *)(iVar5 + 0x18);
    }
  }
  iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
  FUN_00055167(iVar5,3,0,0,iVar2,param_3,piVar6);
  FUN_000555c4(iVar5 + 4,0);
  FUN_000555c4(iVar5 + 8,0);
  *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
  return 1;
}

/* FUN_00057238 @ 0x57238 (2616 bytes) */
int FUN_00057238(param_1, param_2)
  int param_1;
  int *param_2;
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  cVar1 = FUN_00055c4a();
  if (cVar1 != '\0') {
    cVar1 = FUN_00055c4a();
    if ((cVar1 != '\0') && (cVar1 = FUN_00055c4a(), cVar1 != '\0')) {
      iVar4 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
      iVar3 = *(int *)(iVar4 + 0x18);
      if (0x100 < iVar3 + 3U) {
        *(undefined1 *)(param_2 + 4) = 0;
        iVar3 = *(int *)(iVar4 + 0x18);
        if (*(uint *)(iVar4 + 0x20) < iVar3 + 3U) {
          uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
          (**(code **)(param_1 + 0x1344))
                    (uVar2,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
          *(undefined4 *)(iVar4 + 0x1c) = uVar2;
          *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
          iVar3 = *(int *)(iVar4 + 0x18);
        }
      }
      iVar4 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
      FUN_00055cba();
      FUN_00055167(iVar4,3,0,0);
      FUN_000555c4(iVar4 + 4,0);
      *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 4);
      *(byte *)(iVar4 + 9) = *(byte *)(iVar4 + 9) & 0x1f | 0x80;
      *(byte *)(iVar4 + 10) = *(byte *)(iVar4 + 10) & 0xc0 | 0x24;
      *(ushort *)(iVar4 + 10) = *(ushort *)(iVar4 + 10) & 0xfe3f | 0x100;
      *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 8);
      FUN_00055167(iVar4 + 0x10,2,0,0);
      FUN_000555c4(iVar4 + 0x14,0);
      FUN_000555c4(iVar4 + 0x18,0);
      *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar4 + 0x18);
      FUN_00055167(iVar4 + 0x20,3,0,0);
      FUN_000555c4(iVar4 + 0x24,0);
      FUN_000555c4(iVar4 + 0x28,0);
      *(undefined4 *)(iVar4 + 0x2c) = *(undefined4 *)(iVar4 + 0x28);
      return 3;
    }
    cVar1 = FUN_00055c4a();
    if (cVar1 == '\0') {
      iVar4 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
      iVar3 = *(int *)(iVar4 + 0x18);
      if (0x100 < iVar3 + 2U) {
        *(undefined1 *)(param_2 + 4) = 0;
        iVar3 = *(int *)(iVar4 + 0x18);
        if (*(uint *)(iVar4 + 0x20) < iVar3 + 2U) {
          uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
          (**(code **)(param_1 + 0x1344))
                    (uVar2,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
          *(undefined4 *)(iVar4 + 0x1c) = uVar2;
          *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
          iVar3 = *(int *)(iVar4 + 0x18);
        }
      }
      iVar4 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
      FUN_00055cba();
      FUN_00055167(iVar4,3,0,0);
      FUN_000555c4(iVar4 + 4,0);
      *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 4);
      *(byte *)(iVar4 + 9) = *(byte *)(iVar4 + 9) & 0x1f | 0x80;
      *(byte *)(iVar4 + 10) = *(byte *)(iVar4 + 10) & 0xc0 | 0x24;
      *(ushort *)(iVar4 + 10) = *(ushort *)(iVar4 + 10) & 0xfe3f | 0x100;
      *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 8);
      FUN_00055167(iVar4 + 0x10,4,0,0);
      FUN_000555c4(iVar4 + 0x14,0);
    }
    else {
      iVar4 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
      iVar3 = *(int *)(iVar4 + 0x18);
      if (0x100 < iVar3 + 2U) {
        *(undefined1 *)(param_2 + 4) = 0;
        iVar3 = *(int *)(iVar4 + 0x18);
        if (*(uint *)(iVar4 + 0x20) < iVar3 + 2U) {
          uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
          (**(code **)(param_1 + 0x1344))
                    (uVar2,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
          *(undefined4 *)(iVar4 + 0x1c) = uVar2;
          *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
          iVar3 = *(int *)(iVar4 + 0x18);
        }
      }
      iVar4 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
      FUN_00055cba();
      FUN_00055167(iVar4,3,0,0);
      FUN_000555c4(iVar4 + 4,0);
      *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 4);
      *(byte *)(iVar4 + 9) = *(byte *)(iVar4 + 9) & 0x1f | 0x80;
      *(byte *)(iVar4 + 10) = *(byte *)(iVar4 + 10) & 0xc0 | 0x24;
      *(ushort *)(iVar4 + 10) = *(ushort *)(iVar4 + 10) & 0xfe3f | 0x100;
      *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 8);
      FUN_00055167(iVar4 + 0x10,4,0,0);
      FUN_000555c4(iVar4 + 0x14,0);
    }
    FUN_000555c4(iVar4 + 0x18,0);
    FUN_000555c4(iVar4 + 0x1c,0);
    return 2;
  }
  cVar1 = FUN_00055c4a();
  if ((cVar1 == '\0') && (cVar1 = FUN_00055c4a(), cVar1 == '\0')) {
    iVar4 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar3 = *(int *)(iVar4 + 0x18);
    if (0x100 < iVar3 + 1U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar3 = *(int *)(iVar4 + 0x18);
      if (*(uint *)(iVar4 + 0x20) < iVar3 + 1U) {
        uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar2,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
        *(undefined4 *)(iVar4 + 0x1c) = uVar2;
        *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
        iVar3 = *(int *)(iVar4 + 0x18);
      }
    }
    iVar4 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
    FUN_00055167(iVar4,4,0,0);
    FUN_000555c4(iVar4 + 4,0);
    FUN_000555c4(iVar4 + 8,0);
    FUN_000555c4(iVar4 + 0xc,0);
    return 1;
  }
  iVar4 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar3 = *(int *)(iVar4 + 0x18);
  if (0x100 < iVar3 + 2U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar3 = *(int *)(iVar4 + 0x18);
    if (*(uint *)(iVar4 + 0x20) < iVar3 + 2U) {
      uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar2,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
      *(undefined4 *)(iVar4 + 0x1c) = uVar2;
      *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
      iVar3 = *(int *)(iVar4 + 0x18);
    }
  }
  iVar4 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
  FUN_00055cba();
  FUN_00055167(iVar4,2,0,0);
  FUN_000555c4(iVar4 + 4,0);
  FUN_000555c4(iVar4 + 8,0);
  *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 8);
  FUN_00055167(iVar4 + 0x10,3,0,0);
  FUN_000555c4(iVar4 + 0x14,0);
  FUN_000555c4(iVar4 + 0x18,0);
  *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar4 + 0x18);
  return 2;
}

/* FUN_00057c70 @ 0x57c70 (240 bytes) */
int FUN_00057c70(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      iVar2 = *(int *)(iVar3 + 0x18);
    }
  }
  iVar3 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  FUN_00055167(iVar3,6,0,0);
  FUN_000555c4(iVar3 + 4,0);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 4);
  return 1;
}

/* FUN_00057d60 @ 0x57d60 (789 bytes) */
int FUN_00057d60(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = param_3 + 0x3c;
  param_3 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  cVar1 = FUN_00055c4a();
  if (cVar1 != '\0') {
    iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar4 = *(int *)(iVar5 + 0x18);
    if (0x100 < iVar4 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar4 = *(int *)(iVar5 + 0x18);
      if (*(uint *)(iVar5 + 0x20) < iVar4 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
        *(undefined4 *)(iVar5 + 0x1c) = uVar3;
        *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
        iVar4 = *(int *)(iVar5 + 0x18);
      }
    }
    iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
    uVar3 = FUN_00055cba();
    FUN_00055167(iVar5,3,0,0,iVar2,param_3,piVar6,uVar3);
    FUN_000555c4(iVar5 + 4,0);
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 4);
    *(byte *)(iVar5 + 9) = *(byte *)(iVar5 + 9) & 0x1f | 0x80;
    *(byte *)(iVar5 + 10) = *(byte *)(iVar5 + 10) & 0xc0 | 0x24;
    *(ushort *)(iVar5 + 10) = *(ushort *)(iVar5 + 10) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
    FUN_00055167(iVar5 + 0x10,7,0,0);
    FUN_000555c4(iVar5 + 0x14,0);
    FUN_000555c4(iVar5 + 0x18,0);
    *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x18);
    return 2;
  }
  iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar4 = *(int *)(iVar5 + 0x18);
  if (0x100 < iVar4 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar4 = *(int *)(iVar5 + 0x18);
    if (*(uint *)(iVar5 + 0x20) < iVar4 + 1U) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
      *(undefined4 *)(iVar5 + 0x1c) = uVar3;
      *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
      iVar4 = *(int *)(iVar5 + 0x18);
    }
  }
  iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
  FUN_00055167(iVar5,7,0,0,iVar2,param_3,piVar6);
  FUN_000555c4(iVar5 + 4,0);
  FUN_000555c4(iVar5 + 8,0);
  *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
  return 1;
}

/* FUN_00058075 @ 0x58075 (789 bytes) */
int FUN_00058075(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = param_3 + 0x3c;
  param_3 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  cVar1 = FUN_00055c4a();
  if (cVar1 != '\0') {
    iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar4 = *(int *)(iVar5 + 0x18);
    if (0x100 < iVar4 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar4 = *(int *)(iVar5 + 0x18);
      if (*(uint *)(iVar5 + 0x20) < iVar4 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
        *(undefined4 *)(iVar5 + 0x1c) = uVar3;
        *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
        iVar4 = *(int *)(iVar5 + 0x18);
      }
    }
    iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
    uVar3 = FUN_00055cba();
    FUN_00055167(iVar5,3,0,0,iVar2,param_3,piVar6,uVar3);
    FUN_000555c4(iVar5 + 4,0);
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 4);
    *(byte *)(iVar5 + 9) = *(byte *)(iVar5 + 9) & 0x1f | 0x80;
    *(byte *)(iVar5 + 10) = *(byte *)(iVar5 + 10) & 0xc0 | 0x24;
    *(ushort *)(iVar5 + 10) = *(ushort *)(iVar5 + 10) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
    FUN_00055167(iVar5 + 0x10,8,0,0);
    FUN_000555c4(iVar5 + 0x14,0);
    FUN_000555c4(iVar5 + 0x18,0);
    *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x18);
    return 2;
  }
  iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar4 = *(int *)(iVar5 + 0x18);
  if (0x100 < iVar4 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar4 = *(int *)(iVar5 + 0x18);
    if (*(uint *)(iVar5 + 0x20) < iVar4 + 1U) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
      *(undefined4 *)(iVar5 + 0x1c) = uVar3;
      *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
      iVar4 = *(int *)(iVar5 + 0x18);
    }
  }
  iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
  FUN_00055167(iVar5,8,0,0,iVar2,param_3,piVar6);
  FUN_000555c4(iVar5 + 4,0);
  FUN_000555c4(iVar5 + 8,0);
  *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
  return 1;
}

/* FUN_0005838a @ 0x5838a (789 bytes) */
int FUN_0005838a(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = param_3 + 0x3c;
  param_3 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  cVar1 = FUN_00055c4a();
  if (cVar1 != '\0') {
    iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar4 = *(int *)(iVar5 + 0x18);
    if (0x100 < iVar4 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar4 = *(int *)(iVar5 + 0x18);
      if (*(uint *)(iVar5 + 0x20) < iVar4 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
        *(undefined4 *)(iVar5 + 0x1c) = uVar3;
        *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
        iVar4 = *(int *)(iVar5 + 0x18);
      }
    }
    iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
    uVar3 = FUN_00055cba();
    FUN_00055167(iVar5,3,0,0,iVar2,param_3,piVar6,uVar3);
    FUN_000555c4(iVar5 + 4,0);
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 4);
    *(byte *)(iVar5 + 9) = *(byte *)(iVar5 + 9) & 0x1f | 0x80;
    *(byte *)(iVar5 + 10) = *(byte *)(iVar5 + 10) & 0xc0 | 0x24;
    *(ushort *)(iVar5 + 10) = *(ushort *)(iVar5 + 10) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
    FUN_00055167(iVar5 + 0x10,9,0,0);
    FUN_000555c4(iVar5 + 0x14,0);
    FUN_000555c4(iVar5 + 0x18,0);
    *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x18);
    return 2;
  }
  iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar4 = *(int *)(iVar5 + 0x18);
  if (0x100 < iVar4 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar4 = *(int *)(iVar5 + 0x18);
    if (*(uint *)(iVar5 + 0x20) < iVar4 + 1U) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
      *(undefined4 *)(iVar5 + 0x1c) = uVar3;
      *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
      iVar4 = *(int *)(iVar5 + 0x18);
    }
  }
  iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
  FUN_00055167(iVar5,9,0,0,iVar2,param_3,piVar6);
  FUN_000555c4(iVar5 + 4,0);
  FUN_000555c4(iVar5 + 8,0);
  *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
  return 1;
}

/* FUN_0005869f @ 0x5869f (789 bytes) */
int FUN_0005869f(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = param_3 + 0x3c;
  param_3 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  cVar1 = FUN_00055c4a();
  if (cVar1 != '\0') {
    iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar4 = *(int *)(iVar5 + 0x18);
    if (0x100 < iVar4 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar4 = *(int *)(iVar5 + 0x18);
      if (*(uint *)(iVar5 + 0x20) < iVar4 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
        *(undefined4 *)(iVar5 + 0x1c) = uVar3;
        *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
        iVar4 = *(int *)(iVar5 + 0x18);
      }
    }
    iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
    uVar3 = FUN_00055cba();
    FUN_00055167(iVar5,3,0,0,iVar2,param_3,piVar6,uVar3);
    FUN_000555c4(iVar5 + 4,0);
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 4);
    *(byte *)(iVar5 + 9) = *(byte *)(iVar5 + 9) & 0x1f | 0x80;
    *(byte *)(iVar5 + 10) = *(byte *)(iVar5 + 10) & 0xc0 | 0x24;
    *(ushort *)(iVar5 + 10) = *(ushort *)(iVar5 + 10) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
    FUN_00055167(iVar5 + 0x10,10,0,0);
    FUN_000555c4(iVar5 + 0x14,0);
    FUN_000555c4(iVar5 + 0x18,0);
    *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x18);
    return 2;
  }
  iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar4 = *(int *)(iVar5 + 0x18);
  if (0x100 < iVar4 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar4 = *(int *)(iVar5 + 0x18);
    if (*(uint *)(iVar5 + 0x20) < iVar4 + 1U) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
      *(undefined4 *)(iVar5 + 0x1c) = uVar3;
      *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
      iVar4 = *(int *)(iVar5 + 0x18);
    }
  }
  iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
  FUN_00055167(iVar5,10,0,0,iVar2,param_3,piVar6);
  FUN_000555c4(iVar5 + 4,0);
  FUN_000555c4(iVar5 + 8,0);
  *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
  return 1;
}

/* FUN_000589b4 @ 0x589b4 (1112 bytes) */
int FUN_000589b4(param_1, param_2)
  int param_1;
  int *param_2;
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  FUN_00055cba();
  cVar1 = FUN_00055c4a();
  if (cVar1 != '\0') {
    iVar4 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar3 = *(int *)(iVar4 + 0x18);
    if (0x100 < iVar3 + 3U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar3 = *(int *)(iVar4 + 0x18);
      if (*(uint *)(iVar4 + 0x20) < iVar3 + 3U) {
        uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar2,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
        *(undefined4 *)(iVar4 + 0x1c) = uVar2;
        *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
        iVar3 = *(int *)(iVar4 + 0x18);
      }
    }
    iVar4 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
    FUN_00055167(iVar4,3,0,0);
    FUN_000555c4(iVar4 + 4,0);
    *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 4);
    *(byte *)(iVar4 + 9) = *(byte *)(iVar4 + 9) & 0x1f | 0x80;
    *(byte *)(iVar4 + 10) = *(byte *)(iVar4 + 10) & 0xc0 | 0x24;
    *(ushort *)(iVar4 + 10) = *(ushort *)(iVar4 + 10) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 8);
    FUN_00055167(iVar4 + 0x10,7,0,0);
    FUN_000555c4(iVar4 + 0x14,0);
    FUN_000555c4(iVar4 + 0x18,0);
    *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar4 + 0x18);
    FUN_00055167(iVar4 + 0x20,8,0,0);
    FUN_000555c4(iVar4 + 0x24,0);
    FUN_000555c4(iVar4 + 0x28,0);
    *(undefined4 *)(iVar4 + 0x2c) = *(undefined4 *)(iVar4 + 0x28);
    return 3;
  }
  iVar4 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar3 = *(int *)(iVar4 + 0x18);
  if (0x100 < iVar3 + 2U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar3 = *(int *)(iVar4 + 0x18);
    if (*(uint *)(iVar4 + 0x20) < iVar3 + 2U) {
      uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar2,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
      *(undefined4 *)(iVar4 + 0x1c) = uVar2;
      *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
      iVar3 = *(int *)(iVar4 + 0x18);
    }
  }
  iVar4 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
  FUN_00055167(iVar4,7,0,0);
  FUN_000555c4(iVar4 + 4,0);
  FUN_000555c4(iVar4 + 8,0);
  *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 8);
  FUN_00055167(iVar4 + 0x10,8,0,0);
  FUN_000555c4(iVar4 + 0x14,0);
  FUN_000555c4(iVar4 + 0x18,0);
  *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar4 + 0x18);
  return 2;
}

/* FUN_00058e0c @ 0x58e0c (462 bytes) */
int FUN_00058e0c(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 2U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 2U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      iVar2 = *(int *)(iVar3 + 0x18);
    }
  }
  iVar3 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  FUN_00055cba();
  FUN_00055167(iVar3,6,0,0);
  FUN_000555c4(iVar3 + 4,0);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 4);
  FUN_00055167(iVar3 + 0x10,3,0,0);
  FUN_000555c4(iVar3 + 0x14,0);
  FUN_000555c4(iVar3 + 0x18,0);
  *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(iVar3 + 0x18);
  return 2;
}

/* FUN_00058fda @ 0x58fda (982 bytes) */
int FUN_00058fda(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar2 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar3 = *(int *)(iVar2 + 0x18);
  if (0x100 < iVar3 + 4U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar3 = *(int *)(iVar2 + 0x18);
    if (*(uint *)(iVar2 + 0x20) < iVar3 + 4U) {
      uVar5 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar5,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
      *(undefined4 *)(iVar2 + 0x1c) = uVar5;
      *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      iVar3 = *(int *)(iVar2 + 0x18);
    }
  }
  iVar6 = iVar3 * 0x10 + *(int *)(iVar2 + 0x1c);
  iVar3 = FUN_00055cba();
  iVar2 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar4 = iVar3 * 0x28 + *(int *)(iVar2 + 0x4c);
  uVar1 = *(undefined1 *)(iVar4 + 0x10);
  *(undefined1 *)(iVar4 + 0x10) = 1;
  FUN_00055cba();
  *(undefined1 *)(iVar3 * 0x28 + 0x10 + *(int *)(iVar2 + 0x4c)) = uVar1;
  FUN_00055167(iVar6,0xb,1,0);
  FUN_000555c4(iVar6 + 4,0);
  *(byte *)(iVar6 + 5) = *(byte *)(iVar6 + 5) & 0x1f | 0xa0;
  *(byte *)(iVar6 + 6) = *(byte *)(iVar6 + 6) & 0xc0 | 0x2d;
  *(ushort *)(iVar6 + 6) = *(ushort *)(iVar6 + 6) & 0xfe3f | 0x140;
  *(byte *)(iVar6 + 7) = *(byte *)(iVar6 + 7) | 0x1e;
  *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar6 + 4);
  *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar6 + 4);
  FUN_00055167(iVar6 + 0x10,3,0,0);
  FUN_000555c4(iVar6 + 0x14,0);
  FUN_000555c4(iVar6 + 0x18,0);
  *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)(iVar6 + 0x18);
  FUN_00055167(iVar6 + 0x20,6,0,0);
  FUN_000555c4(iVar6 + 0x24,0);
  *(undefined4 *)(iVar6 + 0x28) = *(undefined4 *)(iVar6 + 0x24);
  *(undefined4 *)(iVar6 + 0x2c) = *(undefined4 *)(iVar6 + 0x24);
  FUN_00055167(iVar6 + 0x30,3,0,0);
  FUN_000555c4(iVar6 + 0x34,0);
  FUN_000555c4(iVar6 + 0x38,0);
  *(undefined4 *)(iVar6 + 0x3c) = *(undefined4 *)(iVar6 + 0x38);
  return 4;
}

/* FUN_000593b0 @ 0x593b0 (240 bytes) */
int FUN_000593b0(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      iVar2 = *(int *)(iVar3 + 0x18);
    }
  }
  iVar3 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  FUN_00055167(iVar3,0xb,1,0);
  FUN_000555c4(iVar3 + 4,0);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 4);
  return 1;
}

/* FUN_000594a0 @ 0x594a0 (240 bytes) */
int FUN_000594a0(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      iVar2 = *(int *)(iVar3 + 0x18);
    }
  }
  iVar3 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  FUN_00055167(iVar3,0xc,1,0);
  FUN_000555c4(iVar3 + 4,0);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 4);
  return 1;
}

/* FUN_00059590 @ 0x59590 (789 bytes) */
int FUN_00059590(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = param_3 + 0x3c;
  param_3 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  cVar1 = FUN_00055c4a();
  if (cVar1 != '\0') {
    iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar4 = *(int *)(iVar5 + 0x18);
    if (0x100 < iVar4 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar4 = *(int *)(iVar5 + 0x18);
      if (*(uint *)(iVar5 + 0x20) < iVar4 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
        *(undefined4 *)(iVar5 + 0x1c) = uVar3;
        *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
        iVar4 = *(int *)(iVar5 + 0x18);
      }
    }
    iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
    uVar3 = FUN_00055cba();
    FUN_00055167(iVar5,3,0,0,iVar2,param_3,piVar6,uVar3);
    FUN_000555c4(iVar5 + 4,0);
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 4);
    *(byte *)(iVar5 + 9) = *(byte *)(iVar5 + 9) & 0x1f | 0x80;
    *(byte *)(iVar5 + 10) = *(byte *)(iVar5 + 10) & 0xc0 | 0x24;
    *(ushort *)(iVar5 + 10) = *(ushort *)(iVar5 + 10) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
    FUN_00055167(iVar5 + 0x10,5,1,0);
    FUN_000555c4(iVar5 + 0x14,0);
    FUN_000555c4(iVar5 + 0x18,0);
    *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x18);
    return 2;
  }
  iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar4 = *(int *)(iVar5 + 0x18);
  if (0x100 < iVar4 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar4 = *(int *)(iVar5 + 0x18);
    if (*(uint *)(iVar5 + 0x20) < iVar4 + 1U) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
      *(undefined4 *)(iVar5 + 0x1c) = uVar3;
      *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
      iVar4 = *(int *)(iVar5 + 0x18);
    }
  }
  iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
  FUN_00055167(iVar5,5,1,0,iVar2,param_3,piVar6);
  FUN_000555c4(iVar5 + 4,0);
  FUN_000555c4(iVar5 + 8,0);
  *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
  return 1;
}

/* FUN_000598a5 @ 0x598a5 (240 bytes) */
int FUN_000598a5(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      iVar2 = *(int *)(iVar3 + 0x18);
    }
  }
  iVar3 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  FUN_00055167(iVar3,6,1,0);
  FUN_000555c4(iVar3 + 4,0);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 4);
  return 1;
}

/* FUN_00059995 @ 0x59995 (240 bytes) */
int FUN_00059995(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      iVar2 = *(int *)(iVar3 + 0x18);
    }
  }
  iVar3 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  FUN_00055167(iVar3,8,1,0);
  FUN_000555c4(iVar3 + 4,0);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 4);
  return 1;
}

/* FUN_00059a85 @ 0x59a85 (981 bytes) */
int FUN_00059a85(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  iVar3 = param_3 + 0x3c;
  param_3 = param_3 + 0x20;
  piVar7 = param_2 + 7;
  cVar2 = FUN_00055c4a();
  if (cVar2 != '\0') {
    iVar6 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar5 = *(int *)(iVar6 + 0x18);
    if (0x100 < iVar5 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar5 = *(int *)(iVar6 + 0x18);
      if (*(uint *)(iVar6 + 0x20) < iVar5 + 2U) {
        uVar4 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar6 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar4,*(undefined4 *)(iVar6 + 0x1c),*(int *)(iVar6 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar6 + 0x1c));
        *(undefined4 *)(iVar6 + 0x1c) = uVar4;
        *(int *)(iVar6 + 0x20) = *(int *)(iVar6 + 0x20) + 0x10;
        iVar5 = *(int *)(iVar6 + 0x18);
      }
    }
    iVar6 = iVar5 * 0x10 + *(int *)(iVar6 + 0x1c);
    uVar4 = FUN_00055cba();
    FUN_00055167(iVar6,3,0,0,iVar3,param_3,piVar7,uVar4);
    FUN_000555c4(iVar6 + 4,0);
    *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar6 + 4);
    *(byte *)(iVar6 + 9) = *(byte *)(iVar6 + 9) & 0x1f | 0x80;
    *(byte *)(iVar6 + 10) = *(byte *)(iVar6 + 10) & 0xc0 | 0x24;
    *(ushort *)(iVar6 + 10) = *(ushort *)(iVar6 + 10) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar6 + 8);
    FUN_00055167(iVar6 + 0x10,3,0,0);
    FUN_000555c4(iVar6 + 0x14,0);
    FUN_000555c4(iVar6 + 0x18,0);
    bVar1 = *(byte *)(iVar6 + 0x1b);
    *(byte *)(iVar6 + 0x1b) =
         bVar1 & 0xe1 | (1 - (bVar1 >> 1) & 1) * '\x02' | (1 - (bVar1 >> 2) & 1) << 2 |
         (1 - (bVar1 >> 3) & 1) << 3 | (1 - (bVar1 >> 4) & 1) << 4;
    *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)(iVar6 + 0x18);
    return 2;
  }
  iVar6 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar5 = *(int *)(iVar6 + 0x18);
  if (0x100 < iVar5 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar5 = *(int *)(iVar6 + 0x18);
    if (*(uint *)(iVar6 + 0x20) < iVar5 + 1U) {
      uVar4 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar6 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar4,*(undefined4 *)(iVar6 + 0x1c),*(int *)(iVar6 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar6 + 0x1c));
      *(undefined4 *)(iVar6 + 0x1c) = uVar4;
      *(int *)(iVar6 + 0x20) = *(int *)(iVar6 + 0x20) + 0x10;
      iVar5 = *(int *)(iVar6 + 0x18);
    }
  }
  iVar6 = iVar5 * 0x10 + *(int *)(iVar6 + 0x1c);
  FUN_00055167(iVar6,3,0,0,iVar3,param_3,piVar7);
  FUN_000555c4(iVar6 + 4,0);
  FUN_000555c4(iVar6 + 8,0);
  bVar1 = *(byte *)(iVar6 + 0xb);
  *(byte *)(iVar6 + 0xb) =
       bVar1 & 0xe1 | (1 - (bVar1 >> 1) & 1) * '\x02' | (1 - (bVar1 >> 2) & 1) << 2 |
       (1 - (bVar1 >> 3) & 1) << 3 | (1 - (bVar1 >> 4) & 1) << 4;
  *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar6 + 8);
  return 1;
}

/* FUN_00059e5a @ 0x59e5a (2195 bytes) */
int FUN_00059e5a(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined1 uVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  byte local_78;
  
  cVar4 = FUN_00055c4a();
  if (cVar4 != '\0') {
    iVar10 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar5 = *(int *)(iVar10 + 0x18);
    if (0x100 < iVar5 + 3U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar5 = *(int *)(iVar10 + 0x18);
      if (*(uint *)(iVar10 + 0x20) < iVar5 + 3U) {
        uVar7 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar10 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar7,*(undefined4 *)(iVar10 + 0x1c),*(int *)(iVar10 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar10 + 0x1c));
        *(undefined4 *)(iVar10 + 0x1c) = uVar7;
        *(int *)(iVar10 + 0x20) = *(int *)(iVar10 + 0x20) + 0x10;
        iVar5 = *(int *)(iVar10 + 0x18);
      }
    }
    iVar9 = iVar5 * 0x10 + *(int *)(iVar10 + 0x1c);
    iVar5 = FUN_00055cba();
    iVar10 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar6 = iVar5 * 0x28 + *(int *)(iVar10 + 0x4c);
    uVar1 = *(undefined1 *)(iVar6 + 0x10);
    *(undefined1 *)(iVar6 + 0x10) = 1;
    FUN_00055cba();
    *(undefined1 *)(iVar5 * 0x28 + 0x10 + *(int *)(iVar10 + 0x4c)) = uVar1;
    FUN_00055167(iVar9,3,0,0);
    FUN_000555c4(iVar9 + 4,0);
    *(undefined4 *)(iVar9 + 8) = *(undefined4 *)(iVar9 + 4);
    *(byte *)(iVar9 + 9) = *(byte *)(iVar9 + 9) & 0x1f | 0x80;
    *(byte *)(iVar9 + 10) = *(byte *)(iVar9 + 10) & 0xc0 | 0x24;
    *(ushort *)(iVar9 + 10) = *(ushort *)(iVar9 + 10) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar9 + 0xc) = *(undefined4 *)(iVar9 + 8);
    FUN_00055167(iVar9 + 0x10,2,0,0);
    FUN_000555c4(iVar9 + 0x14,0);
    FUN_000555c4(iVar9 + 0x18,0);
    uVar2 = *(uint *)(iVar9 + 0x18);
    *(byte *)(iVar9 + 0x19) = *(byte *)(iVar9 + 0x19) & 0x1f | (char)(uVar2 >> 0x10) << 5;
    *(byte *)(iVar9 + 0x1a) =
         *(byte *)(iVar9 + 0x1a) & 0xc0 | (byte)(uVar2 >> 0x13) & 7 |
         ((byte)(uVar2 >> 0xd) & 7) << 3;
    bVar3 = (byte)(uVar2 >> 0x18);
    local_78 = bVar3 >> 1;
    *(byte *)(iVar9 + 0x1b) =
         *(byte *)(iVar9 + 0x1b) & 0xe1 | (bVar3 >> 2 & 1) * '\x02' | (bVar3 >> 3 & 1) << 2 |
         (local_78 & 1) << 3;
    *(ushort *)(iVar9 + 0x1a) = *(ushort *)(iVar9 + 0x1a) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar9 + 0x1c) = *(undefined4 *)(iVar9 + 0x18);
    FUN_00055167(iVar9 + 0x20,4,0,0);
    FUN_000555c4(iVar9 + 0x24,0);
    FUN_000555c4(iVar9 + 0x28,0);
    uVar2 = *(uint *)(iVar9 + 0x28);
    *(byte *)(iVar9 + 0x29) = *(byte *)(iVar9 + 0x29) & 0x1f | (char)(uVar2 >> 0x13) << 5;
    *(byte *)(iVar9 + 0x2a) =
         *(byte *)(iVar9 + 0x2a) & 0xc0 | (byte)(uVar2 >> 0xd) & 7 |
         ((byte)(uVar2 >> 0x10) & 7) << 3;
    bVar3 = (byte)(uVar2 >> 0x18);
    local_78 = bVar3 >> 1;
    bVar8 = local_78 & 1;
    local_78 = bVar3 >> 2;
    *(byte *)(iVar9 + 0x2b) =
         *(byte *)(iVar9 + 0x2b) & 0xe1 | (bVar3 >> 3 & 1) * '\x02' | bVar8 << 2 |
         (local_78 & 1) << 3;
    *(ushort *)(iVar9 + 0x2a) = *(ushort *)(iVar9 + 0x2a) & 0xfe3f | 0x140;
    FUN_000555c4(iVar9 + 0x2c,0);
    return 3;
  }
  iVar10 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar5 = *(int *)(iVar10 + 0x18);
  if (0x100 < iVar5 + 2U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar5 = *(int *)(iVar10 + 0x18);
    if (*(uint *)(iVar10 + 0x20) < iVar5 + 2U) {
      uVar7 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar10 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar7,*(undefined4 *)(iVar10 + 0x1c),*(int *)(iVar10 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar10 + 0x1c));
      *(undefined4 *)(iVar10 + 0x1c) = uVar7;
      *(int *)(iVar10 + 0x20) = *(int *)(iVar10 + 0x20) + 0x10;
      iVar5 = *(int *)(iVar10 + 0x18);
    }
  }
  iVar10 = iVar5 * 0x10 + *(int *)(iVar10 + 0x1c);
  FUN_00055cba();
  FUN_00055167(iVar10,2,0,0);
  FUN_000555c4(iVar10 + 4,0);
  uVar2 = *(uint *)(iVar10 + 4);
  *(byte *)(iVar10 + 5) = *(byte *)(iVar10 + 5) & 0x1f | (char)(uVar2 >> 0x13) << 5;
  *(byte *)(iVar10 + 6) =
       *(byte *)(iVar10 + 6) & 0xc0 | (byte)(uVar2 >> 0xd) & 7 | ((byte)(uVar2 >> 0x10) & 7) << 3;
  bVar3 = (byte)(uVar2 >> 0x18);
  local_78 = bVar3 >> 1;
  bVar8 = local_78 & 1;
  local_78 = bVar3 >> 2;
  *(byte *)(iVar10 + 7) =
       *(byte *)(iVar10 + 7) & 0xe1 | (bVar3 >> 3 & 1) * '\x02' | bVar8 << 2 | (local_78 & 1) << 3;
  *(ushort *)(iVar10 + 6) = *(ushort *)(iVar10 + 6) & 0xfe3f | 0x100;
  FUN_000555c4(iVar10 + 8,0);
  uVar2 = *(uint *)(iVar10 + 8);
  *(byte *)(iVar10 + 9) = *(byte *)(iVar10 + 9) & 0x1f | (char)(uVar2 >> 0x10) << 5;
  *(byte *)(iVar10 + 10) =
       *(byte *)(iVar10 + 10) & 0xc0 | (byte)(uVar2 >> 0x13) & 7 | ((byte)(uVar2 >> 0xd) & 7) << 3;
  bVar3 = (byte)(uVar2 >> 0x18);
  local_78 = bVar3 >> 1;
  *(byte *)(iVar10 + 0xb) =
       *(byte *)(iVar10 + 0xb) & 0xe1 | (bVar3 >> 2 & 1) * '\x02' | (bVar3 >> 3 & 1) << 2 |
       (local_78 & 1) << 3;
  *(ushort *)(iVar10 + 10) = *(ushort *)(iVar10 + 10) & 0xfe3f | 0x100;
  *(undefined4 *)(iVar10 + 0xc) = *(undefined4 *)(iVar10 + 8);
  FUN_00055167(iVar10 + 0x10,4,0,0);
  FUN_000555c4(iVar10 + 0x14,0);
  uVar2 = *(uint *)(iVar10 + 0x14);
  *(byte *)(iVar10 + 0x15) = *(byte *)(iVar10 + 0x15) & 0x1f | (char)(uVar2 >> 0x10) << 5;
  *(byte *)(iVar10 + 0x16) =
       *(byte *)(iVar10 + 0x16) & 0xc0 | (byte)(uVar2 >> 0x13) & 7 | ((byte)(uVar2 >> 0xd) & 7) << 3
  ;
  bVar3 = (byte)(uVar2 >> 0x18);
  local_78 = bVar3 >> 1;
  *(byte *)(iVar10 + 0x17) =
       *(byte *)(iVar10 + 0x17) & 0xe1 | (bVar3 >> 2 & 1) * '\x02' | (bVar3 >> 3 & 1) << 2 |
       (local_78 & 1) << 3;
  *(ushort *)(iVar10 + 0x16) = *(ushort *)(iVar10 + 0x16) & 0xfe3f | 0x140;
  FUN_000555c4(iVar10 + 0x18,0);
  uVar2 = *(uint *)(iVar10 + 0x18);
  *(byte *)(iVar10 + 0x19) = *(byte *)(iVar10 + 0x19) & 0x1f | (char)(uVar2 >> 0x13) << 5;
  *(byte *)(iVar10 + 0x1a) =
       *(byte *)(iVar10 + 0x1a) & 0xc0 | (byte)(uVar2 >> 0xd) & 7 | ((byte)(uVar2 >> 0x10) & 7) << 3
  ;
  bVar3 = (byte)(uVar2 >> 0x18);
  local_78 = bVar3 >> 1;
  bVar8 = local_78 & 1;
  local_78 = bVar3 >> 2;
  *(byte *)(iVar10 + 0x1b) =
       *(byte *)(iVar10 + 0x1b) & 0xe1 | (bVar3 >> 3 & 1) * '\x02' | bVar8 << 2 |
       (local_78 & 1) << 3;
  *(ushort *)(iVar10 + 0x1a) = *(ushort *)(iVar10 + 0x1a) & 0xfe3f | 0x140;
  FUN_000555c4(iVar10 + 0x1c,0);
  return 2;
}

/* FUN_0005a6ed @ 0x5a6ed (1527 bytes) */
int FUN_0005a6ed(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (((*(int *)(param_3 + 4) != *(int *)(param_3 + 0x3c)) ||
      (*(int *)(param_3 + 8) != *(int *)(param_3 + 0x40))) &&
     (cVar1 = FUN_00055c4a(), cVar1 == '\0')) {
    iVar4 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar3 = *(int *)(iVar4 + 0x18);
    if (0x100 < iVar3 + 4U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar3 = *(int *)(iVar4 + 0x18);
      if (*(uint *)(iVar4 + 0x20) < iVar3 + 4U) {
        uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar2,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
        *(undefined4 *)(iVar4 + 0x1c) = uVar2;
        *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
        iVar3 = *(int *)(iVar4 + 0x18);
      }
    }
    iVar4 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
    FUN_00055167(iVar4,1,0,0);
    *(byte *)(iVar4 + 2) = *(byte *)(iVar4 + 2) & 0x1f;
    FUN_000555c4(iVar4 + 4,0);
    FUN_000555c4(iVar4 + 8,0);
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 8);
    FUN_00055167(iVar4 + 0x10,1,0,0);
    *(byte *)(iVar4 + 0x12) = *(byte *)(iVar4 + 0x12) & 0x2f;
    FUN_000555c4(iVar4 + 0x14,1);
    FUN_000555c4(iVar4 + 0x18,0);
    *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar4 + 0x18);
    FUN_00055167(iVar4 + 0x20,1,0,0);
    *(byte *)(iVar4 + 0x22) = *(byte *)(iVar4 + 0x22) & 0x4f;
    FUN_000555c4(iVar4 + 0x24,2);
    FUN_000555c4(iVar4 + 0x28,0);
    *(undefined4 *)(iVar4 + 0x2c) = *(undefined4 *)(iVar4 + 0x28);
    FUN_00055167(iVar4 + 0x30,1,0,0);
    *(byte *)(iVar4 + 0x32) = *(byte *)(iVar4 + 0x32) & 0x8f;
    FUN_000555c4(iVar4 + 0x34,3);
    FUN_000555c4(iVar4 + 0x38,0);
    *(undefined4 *)(iVar4 + 0x3c) = *(undefined4 *)(iVar4 + 0x38);
    return 4;
  }
  iVar4 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar3 = *(int *)(iVar4 + 0x18);
  if (0x100 < iVar3 + 5U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar3 = *(int *)(iVar4 + 0x18);
    if (*(uint *)(iVar4 + 0x20) < iVar3 + 5U) {
      uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar2,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
      *(undefined4 *)(iVar4 + 0x1c) = uVar2;
      *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
      iVar3 = *(int *)(iVar4 + 0x18);
    }
  }
  iVar4 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
  FUN_00055cba();
  FUN_00055167(iVar4,3,0,0);
  FUN_000555c4(iVar4 + 4,0);
  *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 4);
  *(byte *)(iVar4 + 9) = *(byte *)(iVar4 + 9) & 0x1f | 0x80;
  *(byte *)(iVar4 + 10) = *(byte *)(iVar4 + 10) & 0xc0 | 0x24;
  *(ushort *)(iVar4 + 10) = *(ushort *)(iVar4 + 10) & 0xfe3f | 0x100;
  *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 8);
  FUN_00055167(iVar4 + 0x10,1,0,0);
  *(byte *)(iVar4 + 0x12) = *(byte *)(iVar4 + 0x12) & 0x1f;
  FUN_000555c4(iVar4 + 0x14,0);
  FUN_000555c4(iVar4 + 0x18,0);
  *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar4 + 0x18);
  FUN_00055167(iVar4 + 0x20,1,0,0);
  *(byte *)(iVar4 + 0x22) = *(byte *)(iVar4 + 0x22) & 0x2f;
  FUN_000555c4(iVar4 + 0x24,1);
  FUN_000555c4(iVar4 + 0x28,0);
  *(undefined4 *)(iVar4 + 0x2c) = *(undefined4 *)(iVar4 + 0x28);
  FUN_00055167(iVar4 + 0x30,1,0,0);
  *(byte *)(iVar4 + 0x32) = *(byte *)(iVar4 + 0x32) & 0x4f;
  FUN_000555c4(iVar4 + 0x34,2);
  FUN_000555c4(iVar4 + 0x38,0);
  *(undefined4 *)(iVar4 + 0x3c) = *(undefined4 *)(iVar4 + 0x38);
  FUN_00055167(iVar4 + 0x40,1,0,0);
  *(byte *)(iVar4 + 0x42) = *(byte *)(iVar4 + 0x42) & 0x8f;
  FUN_000555c4(iVar4 + 0x44,3);
  FUN_000555c4(iVar4 + 0x48,0);
  *(undefined4 *)(iVar4 + 0x4c) = *(undefined4 *)(iVar4 + 0x48);
  return 5;
}

/* FUN_0005ace4 @ 0x5ace4 (284 bytes) */
int FUN_0005ace4(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      iVar2 = *(int *)(iVar3 + 0x18);
    }
  }
  iVar3 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  FUN_00055167(iVar3,3,0,0);
  FUN_000555c4(iVar3 + 4,0);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
  *(byte *)(iVar3 + 9) = *(byte *)(iVar3 + 9) & 0x1f | 0x80;
  *(byte *)(iVar3 + 10) = *(byte *)(iVar3 + 10) & 0xc0 | 0x24;
  *(ushort *)(iVar3 + 10) = *(ushort *)(iVar3 + 10) & 0xfe3f | 0x100;
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 8);
  return 1;
}

/* FUN_0005ae00 @ 0x5ae00 (1176 bytes) */
int FUN_0005ae00(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar5 = *(int *)(iVar6 + 0x18);
  if (0x100 < iVar5 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar5 = *(int *)(iVar6 + 0x18);
    if (*(uint *)(iVar6 + 0x20) < iVar5 + 1U) {
      uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar6 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar2,*(undefined4 *)(iVar6 + 0x1c),*(int *)(iVar6 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar6 + 0x1c));
      *(undefined4 *)(iVar6 + 0x1c) = uVar2;
      *(int *)(iVar6 + 0x20) = *(int *)(iVar6 + 0x20) + 0x10;
      iVar5 = *(int *)(iVar6 + 0x18);
    }
  }
  iVar6 = iVar5 * 0x10 + *(int *)(iVar6 + 0x1c);
  FUN_00055167(iVar6,3,0,0);
  FUN_000555c4(iVar6 + 4,0);
  switch(*(undefined4 *)(param_3 + 0x28)) {
  case 0x87d5:
  case 0x87d9:
    *(byte *)(iVar6 + 5) = *(byte *)(iVar6 + 5) & 0x1f;
    break;
  case 0x87d6:
  case 0x87da:
    *(byte *)(iVar6 + 5) = *(byte *)(iVar6 + 5) & 0x1f | 0x20;
    break;
  case 0x87d7:
  case 0x87db:
    *(byte *)(iVar6 + 5) = *(byte *)(iVar6 + 5) & 0x1f | 0x40;
    break;
  case 0x87d8:
  case 0x87dc:
    *(byte *)(iVar6 + 5) = *(byte *)(iVar6 + 5) & 0x1f | 0x60;
    break;
  case 0x87dd:
    *(byte *)(iVar6 + 5) = *(byte *)(iVar6 + 5) & 0x1f | 0x80;
    break;
  case 0x87de:
  case 0x87df:
    *(byte *)(iVar6 + 5) = *(byte *)(iVar6 + 5) & 0x1f | 0xa0;
    break;
  default:
    goto LAB_0005aee6;
  }
  uVar3 = *(int *)(param_3 + 0x28) - 0x87d5;
  if (uVar3 < 0xb) {
    uVar3 = 1 << ((byte)uVar3 & 0x1f);
    if ((uVar3 & 0x30f) == 0) {
      if ((uVar3 & 0x4f0) == 0) {
        return 0;
      }
      bVar1 = *(byte *)(iVar6 + 7) | 2;
      *(byte *)(iVar6 + 7) = bVar1;
    }
    else {
      bVar1 = *(byte *)(iVar6 + 7) & 0xfd;
      *(byte *)(iVar6 + 7) = bVar1;
    }
    switch(*(undefined4 *)(param_3 + 0x2c)) {
    case 0x87d5:
    case 0x87d9:
      bVar4 = *(byte *)(iVar6 + 6) & 0xf8;
      *(byte *)(iVar6 + 6) = bVar4;
      break;
    case 0x87d6:
    case 0x87da:
      bVar4 = *(byte *)(iVar6 + 6) & 0xf8 | 1;
      *(byte *)(iVar6 + 6) = bVar4;
      break;
    case 0x87d7:
    case 0x87db:
      bVar4 = *(byte *)(iVar6 + 6) & 0xf8 | 2;
      *(byte *)(iVar6 + 6) = bVar4;
      break;
    case 0x87d8:
    case 0x87dc:
      bVar4 = *(byte *)(iVar6 + 6) & 0xf8 | 3;
      *(byte *)(iVar6 + 6) = bVar4;
      break;
    case 0x87dd:
      bVar4 = *(byte *)(iVar6 + 6) & 0xf8 | 4;
      *(byte *)(iVar6 + 6) = bVar4;
      break;
    case 0x87de:
    case 0x87df:
      bVar4 = *(byte *)(iVar6 + 6) & 0xf8 | 5;
      *(byte *)(iVar6 + 6) = bVar4;
      break;
    default:
      goto LAB_0005aee6;
    }
    uVar3 = *(int *)(param_3 + 0x2c) - 0x87d5;
    if (uVar3 < 0xb) {
      uVar3 = 1 << ((byte)uVar3 & 0x1f);
      if ((uVar3 & 0x30f) == 0) {
        if ((uVar3 & 0x4f0) == 0) {
          return 0;
        }
        bVar1 = bVar1 | 4;
        *(byte *)(iVar6 + 7) = bVar1;
      }
      else {
        bVar1 = bVar1 & 0xfb;
        *(byte *)(iVar6 + 7) = bVar1;
      }
      switch(*(undefined4 *)(param_3 + 0x30)) {
      case 0x87d5:
      case 0x87d9:
        *(byte *)(iVar6 + 6) = bVar4 & 199;
        break;
      case 0x87d6:
      case 0x87da:
        *(byte *)(iVar6 + 6) = bVar4 & 199 | 8;
        break;
      case 0x87d7:
      case 0x87db:
        *(byte *)(iVar6 + 6) = bVar4 & 199 | 0x10;
        break;
      case 0x87d8:
      case 0x87dc:
        *(byte *)(iVar6 + 6) = bVar4 & 199 | 0x18;
        break;
      case 0x87dd:
        *(byte *)(iVar6 + 6) = bVar4 & 199 | 0x20;
        break;
      case 0x87de:
      case 0x87df:
        *(byte *)(iVar6 + 6) = bVar4 & 199 | 0x28;
        break;
      default:
        goto LAB_0005aee6;
      }
      uVar3 = *(int *)(param_3 + 0x30) - 0x87d5;
      if (uVar3 < 0xb) {
        uVar3 = 1 << ((byte)uVar3 & 0x1f);
        if ((uVar3 & 0x30f) == 0) {
          if ((uVar3 & 0x4f0) == 0) {
            return 0;
          }
          *(byte *)(iVar6 + 7) = bVar1 | 8;
        }
        else {
          *(byte *)(iVar6 + 7) = bVar1 & 0xf7;
        }
        switch(*(undefined4 *)(param_3 + 0x34)) {
        case 0x87d5:
        case 0x87d9:
          *(ushort *)(iVar6 + 6) = *(ushort *)(iVar6 + 6) & 0xfe3f;
          break;
        case 0x87d6:
        case 0x87da:
          *(ushort *)(iVar6 + 6) = *(ushort *)(iVar6 + 6) & 0xfe3f | 0x40;
          break;
        case 0x87d7:
        case 0x87db:
          *(ushort *)(iVar6 + 6) = *(ushort *)(iVar6 + 6) & 0xfe3f | 0x80;
          break;
        case 0x87d8:
        case 0x87dc:
          *(ushort *)(iVar6 + 6) = *(ushort *)(iVar6 + 6) & 0xfe3f | 0xc0;
          break;
        case 0x87dd:
          *(ushort *)(iVar6 + 6) = *(ushort *)(iVar6 + 6) & 0xfe3f | 0x100;
          break;
        case 0x87de:
        case 0x87df:
          *(ushort *)(iVar6 + 6) = *(ushort *)(iVar6 + 6) & 0xfe3f | 0x140;
          break;
        default:
          goto LAB_0005aee6;
        }
        uVar3 = *(int *)(param_3 + 0x34) - 0x87d5;
        if (uVar3 < 0xb) {
          uVar3 = 1 << ((byte)uVar3 & 0x1f);
          if ((uVar3 & 0x30f) == 0) {
            if ((uVar3 & 0x4f0) == 0) {
              return 0;
            }
            *(byte *)(iVar6 + 7) = *(byte *)(iVar6 + 7) | 0x10;
          }
          else {
            *(byte *)(iVar6 + 7) = *(byte *)(iVar6 + 7) & 0xef;
          }
          *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar6 + 4);
          *(byte *)(iVar6 + 9) = *(byte *)(iVar6 + 9) & 0x1f | 0x80;
          *(byte *)(iVar6 + 10) = *(byte *)(iVar6 + 10) & 0xc0 | 0x24;
          *(ushort *)(iVar6 + 10) = *(ushort *)(iVar6 + 10) & 0xfe3f | 0x100;
          *(byte *)(iVar6 + 0xb) = *(byte *)(iVar6 + 0xb) & 0xe1;
          *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar6 + 8);
          return 1;
        }
      }
    }
  }
LAB_0005aee6:
  return 0;
}

/* FUN_0005b34f @ 0x5b34f (355 bytes) */
int FUN_0005b34f(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  byte bVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar6 = *(int *)(iVar7 + 0x18);
  if (0x100 < iVar6 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar6 = *(int *)(iVar7 + 0x18);
    if (*(uint *)(iVar7 + 0x20) < iVar6 + 1U) {
      uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar7 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar2,*(undefined4 *)(iVar7 + 0x1c),*(int *)(iVar7 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar7 + 0x1c));
      *(undefined4 *)(iVar7 + 0x1c) = uVar2;
      *(int *)(iVar7 + 0x20) = *(int *)(iVar7 + 0x20) + 0x10;
      iVar6 = *(int *)(iVar7 + 0x18);
    }
  }
  iVar7 = iVar6 * 0x10 + *(int *)(iVar7 + 0x1c);
  FUN_00055167(iVar7,3,0,0);
  bVar3 = (*(byte *)(param_3 + 0xc) & 1) << 4;
  bVar1 = *(byte *)(iVar7 + 2);
  *(byte *)(iVar7 + 2) = bVar1 & 0xef | bVar3;
  bVar4 = (*(byte *)(param_3 + 0x10) & 1) << 5;
  *(byte *)(iVar7 + 2) = bVar1 & 0xcf | bVar3 | bVar4;
  bVar5 = (*(byte *)(param_3 + 0x14) & 1) << 6;
  *(byte *)(iVar7 + 2) = bVar1 & 0x8f | bVar3 | bVar4 | bVar5;
  *(byte *)(iVar7 + 2) =
       bVar1 & 0xf | bVar3 | bVar4 | bVar5 | (char)*(undefined4 *)(param_3 + 0x18) << 7;
  FUN_000555c4(iVar7 + 4,0);
  *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar7 + 4);
  *(byte *)(iVar7 + 9) = *(byte *)(iVar7 + 9) & 0x1f | 0x80;
  *(byte *)(iVar7 + 10) = *(byte *)(iVar7 + 10) & 0xc0 | 0x24;
  *(ushort *)(iVar7 + 10) = *(ushort *)(iVar7 + 10) & 0xfe3f | 0x100;
  *(undefined4 *)(iVar7 + 0xc) = *(undefined4 *)(iVar7 + 8);
  return 1;
}

/* FUN_0005b4b2 @ 0x5b4b2 (358 bytes) */
int FUN_0005b4b2(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar3 = *(int *)(iVar1 + 0x18);
  if (0x100 < iVar3 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar3 = *(int *)(iVar1 + 0x18);
    if (*(uint *)(iVar1 + 0x20) < iVar3 + 1U) {
      uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar1 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar2,*(undefined4 *)(iVar1 + 0x1c),*(int *)(iVar1 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar1 + 0x1c));
      *(undefined4 *)(iVar1 + 0x1c) = uVar2;
      *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + 0x10;
      iVar3 = *(int *)(iVar1 + 0x18);
    }
  }
  iVar3 = iVar3 * 0x10 + *(int *)(iVar1 + 0x1c);
  iVar1 = FUN_00053994(param_2 + 7,param_3 + 4);
  uVar4 = *(uint *)(param_3 + 0x40);
  if (uVar4 < 4) {
    if (iVar1 == 0x87bf) {
      uVar4 = 0;
    }
    else if (iVar1 != 0x87c0) {
      return 0xffffffff;
    }
    FUN_00055167(iVar3,3,0,uVar4);
    FUN_000555c4(iVar3 + 4,0);
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
    *(byte *)(iVar3 + 9) = *(byte *)(iVar3 + 9) & 0x1f | 0x80;
    *(byte *)(iVar3 + 10) = *(byte *)(iVar3 + 10) & 0xc0 | 0x24;
    *(ushort *)(iVar3 + 10) = *(ushort *)(iVar3 + 10) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 8);
    return 1;
  }
  return 0xffffffff;
}

/* FUN_0005b618 @ 0x5b618 (659 bytes) */
int FUN_0005b618(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  byte bVar5;
  ushort uVar6;
  int iVar7;
  
  iVar2 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar7 = *(int *)(iVar2 + 0x18);
  if (0x100 < iVar7 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar7 = *(int *)(iVar2 + 0x18);
    if (*(uint *)(iVar2 + 0x20) < iVar7 + 1U) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
      *(undefined4 *)(iVar2 + 0x1c) = uVar3;
      *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      iVar7 = *(int *)(iVar2 + 0x18);
    }
  }
  iVar7 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
  iVar2 = FUN_00053994(param_2 + 7,param_3 + 0x20);
  uVar1 = *(uint *)(param_3 + 0x40);
  if (3 < uVar1) {
    return 0xffffffff;
  }
  FUN_00055167(iVar7,3,0,0);
  if (iVar2 == 0x87bf) {
    FUN_000555c4(iVar7 + 4,0);
    if (uVar1 == 1) {
      bVar5 = *(byte *)(iVar7 + 6);
      uVar6 = (ushort)(bVar5 & 7);
      *(byte *)(iVar7 + 5) = *(byte *)(iVar7 + 5) & 0x1f | bVar5 << 5;
      *(byte *)(iVar7 + 6) = bVar5 & 199 | (bVar5 & 7) * '\b';
    }
    else if (uVar1 == 0) {
      bVar5 = *(byte *)(iVar7 + 5) >> 5;
      uVar6 = (ushort)bVar5;
      *(byte *)(iVar7 + 6) = *(byte *)(iVar7 + 6) & 0xc0 | bVar5 | bVar5 * '\b';
    }
    else {
      if (uVar1 != 2) {
        if (uVar1 == 3) {
          bVar4 = (byte)(*(ushort *)(iVar7 + 6) >> 6);
          bVar5 = bVar4 & 7;
          *(byte *)(iVar7 + 5) = *(byte *)(iVar7 + 5) & 0x1f | bVar4 << 5;
          *(byte *)(iVar7 + 6) = *(byte *)(iVar7 + 6) & 0xc0 | bVar5 | bVar5 * '\b';
        }
        goto LAB_0005b712;
      }
      bVar5 = *(byte *)(iVar7 + 6) >> 3;
      bVar4 = bVar5 & 7;
      uVar6 = (ushort)bVar4;
      *(byte *)(iVar7 + 5) = *(byte *)(iVar7 + 5) & 0x1f | bVar5 << 5;
      *(byte *)(iVar7 + 6) = *(byte *)(iVar7 + 6) & 0xf8 | bVar4;
    }
    *(ushort *)(iVar7 + 6) = *(ushort *)(iVar7 + 6) & 0xfe3f | uVar6 << 6;
  }
  else {
    if (iVar2 != 0x87c0) {
      return 0xffffffff;
    }
    FUN_000555c4(iVar7 + 4,uVar1);
  }
LAB_0005b712:
  *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar7 + 4);
  *(byte *)(iVar7 + 9) = *(byte *)(iVar7 + 9) & 0x1f | 0x80;
  *(byte *)(iVar7 + 10) = *(byte *)(iVar7 + 10) & 0xc0 | 0x24;
  *(ushort *)(iVar7 + 10) = *(ushort *)(iVar7 + 10) & 0xfe3f | 0x100;
  *(undefined4 *)(iVar7 + 0xc) = *(undefined4 *)(iVar7 + 8);
  return 1;
}

/* FUN_0005b8ab @ 0x5b8ab (341 bytes) */
int FUN_0005b8ab(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      iVar2 = *(int *)(iVar3 + 0x18);
    }
  }
  iVar3 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  FUN_00055167(iVar3,4,1,0);
  FUN_000555c4(iVar3 + 4,0);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 4);
  *(ushort *)(iVar3 + 6) = *(ushort *)(iVar3 + 6) & 0xfe3f | (ushort)(*(byte *)(iVar3 + 6) & 7) << 6
  ;
  *(byte *)(iVar3 + 7) = *(byte *)(iVar3 + 7) & 0xef | *(byte *)(iVar3 + 7) * '\x04' & 0x10;
  *(ushort *)(iVar3 + 10) =
       *(ushort *)(iVar3 + 10) & 0xfe3f | (ushort)(*(byte *)(iVar3 + 9) >> 5) << 6;
  *(byte *)(iVar3 + 0xb) = *(byte *)(iVar3 + 0xb) & 0xef | *(byte *)(iVar3 + 0xb) * '\b' & 0x10;
  return 1;
}

/* FUN_0005ba00 @ 0x5ba00 (789 bytes) */
int FUN_0005ba00(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = param_3 + 0x3c;
  param_3 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  cVar1 = FUN_00055c4a();
  if (cVar1 != '\0') {
    iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar4 = *(int *)(iVar5 + 0x18);
    if (0x100 < iVar4 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar4 = *(int *)(iVar5 + 0x18);
      if (*(uint *)(iVar5 + 0x20) < iVar4 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
        *(undefined4 *)(iVar5 + 0x1c) = uVar3;
        *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
        iVar4 = *(int *)(iVar5 + 0x18);
      }
    }
    iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
    uVar3 = FUN_00055cba();
    FUN_00055167(iVar5,3,0,0,iVar2,param_3,piVar6,uVar3);
    FUN_000555c4(iVar5 + 4,0);
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 4);
    *(byte *)(iVar5 + 9) = *(byte *)(iVar5 + 9) & 0x1f | 0x80;
    *(byte *)(iVar5 + 10) = *(byte *)(iVar5 + 10) & 0xc0 | 0x24;
    *(ushort *)(iVar5 + 10) = *(ushort *)(iVar5 + 10) & 0xfe3f | 0x100;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
    FUN_00055167(iVar5 + 0x10,5,0,0);
    FUN_000555c4(iVar5 + 0x14,0);
    FUN_000555c4(iVar5 + 0x18,0);
    *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x18);
    return 2;
  }
  iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar4 = *(int *)(iVar5 + 0x18);
  if (0x100 < iVar4 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar4 = *(int *)(iVar5 + 0x18);
    if (*(uint *)(iVar5 + 0x20) < iVar4 + 1U) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
      *(undefined4 *)(iVar5 + 0x1c) = uVar3;
      *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
      iVar4 = *(int *)(iVar5 + 0x18);
    }
  }
  iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
  FUN_00055167(iVar5,5,0,0,iVar2,param_3,piVar6);
  FUN_000555c4(iVar5 + 4,0);
  FUN_000555c4(iVar5 + 8,0);
  *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
  return 1;
}

/* FUN_0005bd15 @ 0x5bd15 (293 bytes) */
int FUN_0005bd15(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      iVar2 = *(int *)(iVar3 + 0x18);
    }
  }
  iVar3 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  FUN_00055167(iVar3,1,1,0);
  FUN_000555c4(iVar3 + 4,0);
  *(ushort *)(iVar3 + 6) =
       *(ushort *)(iVar3 + 6) & 0xfe3f | (ushort)(*(byte *)(iVar3 + 5) >> 5) << 6;
  *(byte *)(iVar3 + 7) = *(byte *)(iVar3 + 7) & 0xef | *(byte *)(iVar3 + 7) * '\b' & 0x10;
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 4);
  return 1;
}

/* FUN_0005be3a @ 0x5be3a (293 bytes) */
int FUN_0005be3a(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      iVar2 = *(int *)(iVar3 + 0x18);
    }
  }
  iVar3 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  FUN_00055167(iVar3,2,1,0);
  FUN_000555c4(iVar3 + 4,0);
  *(ushort *)(iVar3 + 6) =
       *(ushort *)(iVar3 + 6) & 0xfe3f | (ushort)(*(byte *)(iVar3 + 5) >> 5) << 6;
  *(byte *)(iVar3 + 7) = *(byte *)(iVar3 + 7) & 0xef | *(byte *)(iVar3 + 7) * '\b' & 0x10;
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 4);
  return 1;
}

/* FUN_0005bf5f @ 0x5bf5f (240 bytes) */
int FUN_0005bf5f(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      iVar2 = *(int *)(iVar3 + 0x18);
    }
  }
  iVar3 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  FUN_00055167(iVar3,0xd,0,0);
  FUN_000555c4(iVar3 + 4,0);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 4);
  return 1;
}

/* FUN_0005c04f @ 0x5c04f (1818 bytes) */
int FUN_0005c04f(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint *param_3;
{
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  uVar2 = FUN_00055cba();
  *(byte *)((int)param_3 + 1) = *(byte *)((int)param_3 + 1) & 0xf0;
  *param_3 = *param_3 & 0xfff01fff | (uVar2 & 0x7f) << 0xd;
  *(byte *)((int)param_3 + 2) = *(byte *)((int)param_3 + 2) | 0x10;
  sVar1 = *(short *)(iVar5 + 0x2e04);
  if (sVar1 == 0x801) {
    iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar4 = *(int *)(iVar5 + 0x18);
    if (0x100 < iVar4 + 3U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar4 = *(int *)(iVar5 + 0x18);
      if (*(uint *)(iVar5 + 0x20) < iVar4 + 3U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
        *(undefined4 *)(iVar5 + 0x1c) = uVar3;
        *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
        iVar4 = *(int *)(iVar5 + 0x18);
      }
    }
    iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
    FUN_00055167(iVar5,2,0,0);
    FUN_000555c4(iVar5 + 4,0);
    FUN_000555c4(iVar5 + 8,0);
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
    FUN_00055167(iVar5 + 0x10,2,0,0);
    FUN_000555c4(iVar5 + 0x14,0);
    FUN_000555c4(iVar5 + 0x18,0);
    *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x18);
    FUN_00055167(iVar5 + 0x20,3,1,0);
    FUN_000555c4(iVar5 + 0x24,0);
    *(undefined4 *)(iVar5 + 0x28) = *(undefined4 *)(iVar5 + 0x24);
    *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)(iVar5 + 0x24);
    return 3;
  }
  if (sVar1 != 0x2601) {
    if (sVar1 != 0x800) {
      return 0;
    }
    iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    iVar4 = *(int *)(iVar5 + 0x18);
    if (0x100 < iVar4 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar4 = *(int *)(iVar5 + 0x18);
      if (*(uint *)(iVar5 + 0x20) < iVar4 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
        (**(code **)(param_1 + 0x1344))
                  (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
        *(undefined4 *)(iVar5 + 0x1c) = uVar3;
        *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
        iVar4 = *(int *)(iVar5 + 0x18);
      }
    }
    iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
    FUN_00055167(iVar5,2,0,0);
    FUN_000555c4(iVar5 + 4,0);
    FUN_000555c4(iVar5 + 8,0);
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
    FUN_00055167(iVar5 + 0x10,3,1,0);
    FUN_000555c4(iVar5 + 0x14,0);
    *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(iVar5 + 0x14);
    *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x14);
    return 2;
  }
  iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar4 = *(int *)(iVar5 + 0x18);
  if (0x100 < iVar4 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar4 = *(int *)(iVar5 + 0x18);
    if (*(uint *)(iVar5 + 0x20) < iVar4 + 1U) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar3,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
      *(undefined4 *)(iVar5 + 0x1c) = uVar3;
      *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
      iVar4 = *(int *)(iVar5 + 0x18);
    }
  }
  iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
  FUN_00055167(iVar5,1,0,0);
  FUN_000555c4(iVar5 + 4,0);
  FUN_000555c4(iVar5 + 8,0);
  *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 8);
  return 1;
}

/* FUN_0005c769 @ 0x5c769 (80 bytes) */
int FUN_0005c769(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  uVar2 = 0;
  do {
    iVar1 = *(int *)(param_1 + uVar2 * 4);
    if ((iVar1 != 0) && (uVar3 = uVar2 + 1, uVar3 < 0x20)) {
      puVar4 = (undefined4 *)(param_1 + uVar3 * 4);
      do {
        puVar4[-1] = *puVar4;
        uVar3 = uVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (uVar3 != 0x20);
    }
    uVar2 = uVar2 + 1;
  } while ((uVar2 < 0x20) && (iVar1 == 0));
  return iVar1;
}

/* FUN_0005c7b9 @ 0x5c7b9 (3581 bytes) */
int FUN_0005c7b9(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  int local_270;
  int local_248;
  int local_244;
  int local_240;
  int local_23c;
  uint local_238;
  int local_234;
  int local_230;
  int local_22c;
  int local_220 [33];
  int local_19c [32];
  int local_11c [32];
  int local_9c [35];
  
  iVar1 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  *(undefined4 *)(iVar1 + 0x234) = 1;
  iVar5 = 1;
  do {
    local_220[iVar5 + 0x60] = 0;
    local_220[iVar5 + 0x40] = 0;
    local_220[iVar5 + 0x20] = 0;
    local_220[iVar5] = 0;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x21);
  if (param_2[5] == 0) {
    local_244 = 0;
    local_240 = 0;
    local_23c = 0;
  }
  else {
    local_248 = 0;
    uVar7 = 0;
    local_244 = 0;
    local_240 = 0;
    local_23c = 0;
    iVar5 = 0;
LAB_0005c8e3:
    do {
      iVar8 = param_2[6];
      if (((*(int *)(iVar5 + iVar8 + 0x20) == 2) &&
          (iVar6 = param_2[8] + *(int *)(iVar5 + iVar8 + 0x24) * 0x54,
          *(int *)(iVar6 + 0x28) == 0x87c1)) && (*(char *)(iVar6 + 0x3d) == '\0')) {
        if ((*(char *)(iVar6 + 0x44) == '\0') || (*(int *)(iVar6 + 0x48) == 0x12)) {
          iVar8 = *(int *)(iVar6 + 0x24);
          if (iVar8 == 0x87bf) {
            local_220[local_240 + 0x21] = iVar6;
            local_240 = local_240 + 1;
          }
          else if (iVar8 == 0x87c0) {
            local_220[local_23c + 1] = iVar6;
            local_23c = local_23c + 1;
          }
          else if (iVar8 == 0x87be) {
            local_220[local_244 + 0x41] = iVar6;
            local_244 = local_244 + 1;
          }
        }
        else {
          local_220[local_248 + 0x61] = iVar6;
          local_248 = local_248 + 1;
          switch(*(undefined4 *)(iVar6 + 0x48)) {
          case 0:
            *(undefined1 *)(iVar1 + 0x2c) = 1;
            break;
          case 1:
            *(undefined1 *)(iVar1 + 0x2d) = 1;
            param_2[0xc] = param_2[0xc] | 8;
            break;
          case 2:
            iVar8 = *(int *)(iVar6 + 0x4c);
            *(undefined1 *)(iVar8 + 0x2e + iVar1) = 1;
            param_2[0xc] = param_2[0xc] | 4;
            *(undefined1 *)(iVar8 + 0x34 + (int)param_2) = 1;
            break;
          case 3:
            *(undefined1 *)(iVar1 + 0x36) = 1;
            param_2[0xc] = param_2[0xc] | 1;
            break;
          case 4:
            *(undefined1 *)(iVar1 + 0x37) = 1;
            break;
          case 5:
            *(undefined1 *)(iVar1 + 0x38) = 1;
            break;
          case 6:
            *(undefined1 *)(iVar1 + 0x39) = 1;
            break;
          case 7:
            *(undefined1 *)(iVar1 + 0x36) = 1;
            break;
          case 8:
            *(undefined1 *)(iVar1 + 0x3b) = 1;
            break;
          case 9:
            *(undefined1 *)(iVar1 + 0x3c) = 1;
            break;
          case 10:
            *(undefined1 *)(iVar1 + 0x3d) = 1;
            break;
          case 0xb:
            *(undefined1 *)(iVar1 + 0x3a) = 1;
            break;
          case 0xc:
            *(undefined1 *)(iVar1 + 0x40) = 1;
            break;
          case 0xd:
            *(undefined1 *)(iVar1 + 0x41) = 1;
            break;
          case 0xe:
            *(undefined1 *)(iVar1 + 0x37) = 1;
            param_2[0xc] = param_2[0xc] | 2;
            break;
          case 0xf:
            *(undefined1 *)(iVar1 + 0x3e) = 1;
            param_2[0xc] = param_2[0xc] | 0x40;
            break;
          case 0x10:
            *(undefined1 *)(iVar1 + 0x3f) = 1;
            param_2[0xc] = param_2[0xc] | 0x80;
          }
        }
        *(undefined1 *)(iVar6 + 0x3d) = 1;
        param_2[0x16] = param_2[0x16] + 1;
        iVar8 = param_2[6];
        iVar6 = iVar5 + iVar8;
        if (*(int *)(iVar6 + 0x3c) != 2) goto LAB_0005c8c1;
LAB_0005c96b:
        iVar6 = param_2[8] + *(int *)(iVar6 + 0x40) * 0x54;
        if ((*(int *)(iVar6 + 0x28) != 0x87c1) || (*(char *)(iVar6 + 0x3d) != '\0'))
        goto LAB_0005c8c1;
        if ((*(char *)(iVar6 + 0x44) == '\0') || (*(int *)(iVar6 + 0x48) == 0x12)) {
          iVar8 = *(int *)(iVar6 + 0x24);
          if (iVar8 == 0x87bf) {
            local_220[local_240 + 0x21] = iVar6;
            local_240 = local_240 + 1;
          }
          else if (iVar8 == 0x87c0) {
            local_220[local_23c + 1] = iVar6;
            local_23c = local_23c + 1;
          }
          else if (iVar8 == 0x87be) {
            local_220[local_244 + 0x41] = iVar6;
            local_244 = local_244 + 1;
          }
        }
        else {
          local_220[local_248 + 0x61] = iVar6;
          local_248 = local_248 + 1;
          switch(*(undefined4 *)(iVar6 + 0x48)) {
          case 0:
            *(undefined1 *)(iVar1 + 0x2c) = 1;
            break;
          case 1:
            *(undefined1 *)(iVar1 + 0x2d) = 1;
            param_2[0xc] = param_2[0xc] | 8;
            break;
          case 2:
            iVar8 = *(int *)(iVar6 + 0x4c);
            *(undefined1 *)(iVar8 + 0x2e + iVar1) = 1;
            param_2[0xc] = param_2[0xc] | 4;
            *(undefined1 *)(iVar8 + 0x34 + (int)param_2) = 1;
            break;
          case 3:
            *(undefined1 *)(iVar1 + 0x36) = 1;
            param_2[0xc] = param_2[0xc] | 1;
            break;
          case 4:
            *(undefined1 *)(iVar1 + 0x37) = 1;
            break;
          case 5:
            *(undefined1 *)(iVar1 + 0x38) = 1;
            break;
          case 6:
            *(undefined1 *)(iVar1 + 0x39) = 1;
            break;
          case 7:
            *(undefined1 *)(iVar1 + 0x36) = 1;
            break;
          case 8:
            *(undefined1 *)(iVar1 + 0x3b) = 1;
            break;
          case 9:
            *(undefined1 *)(iVar1 + 0x3c) = 1;
            break;
          case 10:
            *(undefined1 *)(iVar1 + 0x3d) = 1;
            break;
          case 0xb:
            *(undefined1 *)(iVar1 + 0x3a) = 1;
            break;
          case 0xc:
            *(undefined1 *)(iVar1 + 0x40) = 1;
            break;
          case 0xd:
            *(undefined1 *)(iVar1 + 0x41) = 1;
            break;
          case 0xe:
            *(undefined1 *)(iVar1 + 0x37) = 1;
            param_2[0xc] = param_2[0xc] | 2;
            break;
          case 0xf:
            *(undefined1 *)(iVar1 + 0x3e) = 1;
            param_2[0xc] = param_2[0xc] | 0x40;
            break;
          case 0x10:
            *(undefined1 *)(iVar1 + 0x3f) = 1;
            param_2[0xc] = param_2[0xc] | 0x80;
          }
        }
        *(undefined1 *)(iVar6 + 0x3d) = 1;
        param_2[0x16] = param_2[0x16] + 1;
        iVar8 = iVar5 + param_2[6];
        iVar6 = *(int *)(iVar8 + 0x58);
      }
      else {
        iVar6 = iVar5 + iVar8;
        if (*(int *)(iVar6 + 0x3c) == 2) goto LAB_0005c96b;
LAB_0005c8c1:
        iVar8 = iVar5 + iVar8;
        iVar6 = *(int *)(iVar8 + 0x58);
      }
      if (((iVar6 == 2) &&
          (iVar8 = param_2[8] + *(int *)(iVar8 + 0x5c) * 0x54, *(int *)(iVar8 + 0x28) == 0x87c1)) &&
         (*(char *)(iVar8 + 0x3d) == '\0')) {
        if ((*(char *)(iVar8 + 0x44) == '\0') || (*(int *)(iVar8 + 0x48) == 0x12)) {
          iVar6 = *(int *)(iVar8 + 0x24);
          if (iVar6 == 0x87bf) {
            local_220[local_240 + 0x21] = iVar8;
            local_240 = local_240 + 1;
          }
          else if (iVar6 == 0x87c0) {
            local_220[local_23c + 1] = iVar8;
            local_23c = local_23c + 1;
          }
          else if (iVar6 == 0x87be) {
            local_220[local_244 + 0x41] = iVar8;
            local_244 = local_244 + 1;
          }
        }
        else {
          local_220[local_248 + 0x61] = iVar8;
          local_248 = local_248 + 1;
          switch(*(undefined4 *)(iVar8 + 0x48)) {
          case 0:
            *(undefined1 *)(iVar1 + 0x2c) = 1;
            break;
          case 1:
            *(undefined1 *)(iVar1 + 0x2d) = 1;
            param_2[0xc] = param_2[0xc] | 8;
            break;
          case 2:
            iVar6 = *(int *)(iVar8 + 0x4c);
            *(undefined1 *)(iVar6 + 0x2e + iVar1) = 1;
            param_2[0xc] = param_2[0xc] | 4;
            *(undefined1 *)(iVar6 + 0x34 + (int)param_2) = 1;
            break;
          case 3:
            *(undefined1 *)(iVar1 + 0x36) = 1;
            param_2[0xc] = param_2[0xc] | 1;
            break;
          case 4:
            *(undefined1 *)(iVar1 + 0x37) = 1;
            break;
          case 5:
            *(undefined1 *)(iVar1 + 0x38) = 1;
            break;
          case 6:
            *(undefined1 *)(iVar1 + 0x39) = 1;
            break;
          case 7:
            *(undefined1 *)(iVar1 + 0x36) = 1;
            break;
          case 8:
            *(undefined1 *)(iVar1 + 0x3b) = 1;
            break;
          case 9:
            *(undefined1 *)(iVar1 + 0x3c) = 1;
            break;
          case 10:
            *(undefined1 *)(iVar1 + 0x3d) = 1;
            break;
          case 0xb:
            *(undefined1 *)(iVar1 + 0x3a) = 1;
            break;
          case 0xc:
            *(undefined1 *)(iVar1 + 0x40) = 1;
            break;
          case 0xd:
            *(undefined1 *)(iVar1 + 0x41) = 1;
            break;
          case 0xe:
            *(undefined1 *)(iVar1 + 0x37) = 1;
            param_2[0xc] = param_2[0xc] | 2;
            break;
          case 0xf:
            *(undefined1 *)(iVar1 + 0x3e) = 1;
            param_2[0xc] = param_2[0xc] | 0x40;
            break;
          case 0x10:
            *(undefined1 *)(iVar1 + 0x3f) = 1;
            param_2[0xc] = param_2[0xc] | 0x80;
          }
        }
        *(undefined1 *)(iVar8 + 0x3d) = 1;
        param_2[0x16] = param_2[0x16] + 1;
        uVar7 = uVar7 + 1;
        iVar5 = iVar5 + 0x74;
        if ((uint)param_2[5] <= uVar7) break;
        goto LAB_0005c8e3;
      }
      uVar7 = uVar7 + 1;
      iVar5 = iVar5 + 0x74;
    } while (uVar7 < (uint)param_2[5]);
  }
  if (*(char *)(iVar1 + 0x2c) != '\0') {
    iVar5 = 1;
    do {
      iVar8 = local_220[iVar5 + 0x60];
      if (((iVar8 == 0) || (*(int *)(iVar8 + 0x48) != 0)) || (*(int *)(iVar8 + 0x4c) != 0)) {
        iVar8 = 0;
      }
    } while ((iVar5 != 0x20) && (iVar5 = iVar5 + 1, iVar8 == 0));
    *(undefined4 *)(iVar8 + 4) = 0;
    *(undefined4 *)(iVar1 + 0x198) = 0;
    *(undefined1 *)(*(int *)(iVar1 + 0x24) + 0x10) = 1;
  }
  DAT_001ee6c4 = 0xe;
  local_238 = 2;
  iVar8 = 0x50;
  iVar5 = 0;
  do {
    while (iVar6 = iVar5, local_240 != 0) {
      puVar3 = (undefined4 *)((int (*)())FUN_0005c769)();
      *puVar3 = *(undefined4 *)(&DAT_001ee660 + local_238 * 4);
      puVar3[1] = local_238;
      *(undefined1 *)(iVar8 + 0x10 + *(int *)(iVar1 + 0x24)) = 1;
      *(uint *)(iVar1 + 0x234) = *(uint *)(iVar1 + 0x234) | 4 << ((byte)iVar6 & 0x1f);
      local_240 = local_240 + -1;
      local_238 = local_238 + 1;
      iVar8 = iVar8 + 0x28;
      iVar5 = iVar6 + 1;
      if (iVar6 + 1 == 8) goto LAB_0005cb65;
    }
    iVar5 = iVar6 + 1;
  } while (iVar6 + 1 != 8);
LAB_0005cb65:
  uVar7 = iVar6 + 1U & 0xffff0000;
  iVar5 = local_238 * 0x28;
  do {
    while (local_240 != 0) {
      puVar3 = (undefined4 *)((int (*)())FUN_0005c769)();
      *puVar3 = *(undefined4 *)(&DAT_001ee660 + local_238 * 4);
      puVar3[1] = local_238;
      *(undefined1 *)(iVar5 + 0x10 + *(int *)(iVar1 + 0x24)) = 1;
      *(uint *)(iVar1 + 0x234) = *(uint *)(iVar1 + 0x234) | 0x400 << ((byte)uVar7 & 0x1f);
      local_240 = local_240 + -1;
      local_238 = local_238 + 1;
      iVar5 = iVar5 + 0x28;
      uVar7 = uVar7 + 1;
      if (uVar7 == 8) goto LAB_0005cbf9;
    }
    uVar7 = uVar7 + 1;
  } while (uVar7 != 8);
LAB_0005cbf9:
  uVar7 = local_238;
  if (*(char *)(*(int *)(iVar1 + 0x24) + 0x10 + local_238 * 0x28) != '\0') {
    uVar2 = *(uint *)(iVar1 + 0x234);
    *(uint *)(iVar1 + 0x234) = uVar2 | 0x40000;
    uVar7 = local_238 + 1;
    if (*(char *)(*(int *)(iVar1 + 0x24) + 0x10 + (local_238 + 1) * 0x28) != '\0') {
      *(uint *)(iVar1 + 0x234) = uVar2 | 0xc0000;
      uVar7 = local_238 + 2;
    }
  }
  local_238 = uVar7;
  if (local_240 != 0) {
    puVar3 = (undefined4 *)((int (*)())FUN_0005c769)();
    *puVar3 = *(undefined4 *)(&DAT_001ee660 + local_238 * 4);
    puVar3[1] = local_238;
    *(undefined1 *)(*(int *)(iVar1 + 0x24) + 0x10 + local_238 * 0x28) = 1;
    *(uint *)(iVar1 + 0x234) = *(uint *)(iVar1 + 0x234) | 0x100000;
    local_240 = local_240 + -1;
    local_238 = local_238 + 1;
  }
  if ((local_244 == 0) && (local_240 == 0)) {
    if (local_23c == 0) goto LAB_0005ccad;
    *(undefined1 *)(param_2 + 4) = 0;
    bVar9 = false;
  }
  else {
    *(undefined1 *)(param_2 + 4) = 0;
    bVar9 = local_244 != 0;
  }
  if (bVar9) {
    iVar5 = local_238 * 0x28;
    local_22c = 0;
    do {
      local_220[0] = ((int (*)())FUN_0005c769)();
      if (*(uint *)(iVar1 + 0x28) <= local_238) {
        uVar4 = (**(code **)(param_1 + 0x10))(*(uint *)(iVar1 + 0x28) + 0x10,0x28);
        (**(code **)(param_1 + 0x1344))
                  (uVar4,*(undefined4 *)(iVar1 + 0x24),*(int *)(iVar1 + 0x28) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar1 + 0x24));
        *(undefined4 *)(iVar1 + 0x24) = uVar4;
        *(int *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + 0x10;
      }
      *(uint *)(local_220[0] + 4) = local_238;
      *(undefined4 *)(local_220[0] + 8) = 0;
      *(undefined1 *)(iVar5 + 0x10 + *(int *)(iVar1 + 0x24)) = 1;
      local_238 = local_238 + 1;
      local_22c = local_22c + 1;
      iVar5 = iVar5 + 0x28;
    } while (local_244 != local_22c);
  }
  if (local_240 != 0) {
    iVar5 = local_238 * 0x28;
    local_230 = 0;
    do {
      iVar8 = ((int (*)())FUN_0005c769)();
      if (*(uint *)(iVar1 + 0x28) <= local_238) {
        uVar4 = (**(code **)(param_1 + 0x10))(*(uint *)(iVar1 + 0x28) + 0x10,0x28);
        (**(code **)(param_1 + 0x1344))
                  (uVar4,*(undefined4 *)(iVar1 + 0x24),*(int *)(iVar1 + 0x28) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar1 + 0x24));
        *(undefined4 *)(iVar1 + 0x24) = uVar4;
        *(int *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + 0x10;
      }
      *(uint *)(iVar8 + 4) = local_238;
      *(undefined1 *)(*(int *)(iVar1 + 0x24) + 0x10 + iVar5) = 1;
      local_238 = local_238 + 1;
      local_230 = local_230 + 1;
      iVar5 = iVar5 + 0x28;
    } while (local_240 != local_230);
  }
  if (local_23c != 0) {
    local_270 = local_238 * 0x28;
    local_234 = 0;
    do {
      iVar5 = ((int (*)())FUN_0005c769)();
      if (*(uint *)(iVar1 + 0x28) <= local_238 + 3) {
        uVar4 = (**(code **)(param_1 + 0x10))(*(uint *)(iVar1 + 0x28) + 0x10,0x28);
        (**(code **)(param_1 + 0x1344))
                  (uVar4,*(undefined4 *)(iVar1 + 0x24),*(int *)(iVar1 + 0x28) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar1 + 0x24));
        *(undefined4 *)(iVar1 + 0x24) = uVar4;
        *(int *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + 0x10;
      }
      iVar6 = 0;
      iVar8 = local_270;
      do {
        *(uint *)(iVar5 + 0x10) = local_238 + iVar6;
        *(undefined1 *)(iVar8 + 0x10 + *(int *)(iVar1 + 0x24)) = 1;
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 4;
        iVar8 = iVar8 + 0x28;
      } while (iVar6 != 4);
      local_238 = local_238 + 4;
      local_234 = local_234 + 1;
      local_270 = local_270 + 0xa0;
    } while (local_234 != local_23c);
  }
LAB_0005ccad:
  *(uint *)(iVar1 + 0x2a4) = local_238;
  return;
}

/* FUN_0005d687 @ 0x5d687 (587 bytes) */
int FUN_0005d687(param_1, param_2)
  int param_1;
  int *param_2;
{
  byte bVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  
  iVar2 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  if ((char)param_2[4] != '\0') {
    iVar6 = (**(code **)(param_1 + 0xc))(*(int *)(iVar2 + 0x18) << 4);
    puVar7 = (undefined4 *)
             FUN_00072f84(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x18));
    *puVar7 = 0x460;
    puVar7[3] = 0x20;
    puVar7[8] = 0;
    puVar7[9] = 0;
    puVar7[1] = *(undefined4 *)(iVar2 + 0x1c);
    puVar7[2] = *(undefined4 *)(iVar2 + 0x18);
    puVar7[6] = iVar6;
    puVar7[7] = &local_10;
    puVar7[10] = &local_14;
    puVar7[0xb] = &local_18;
    puVar7[0xc] = &local_1c;
    iVar8 = FUN_00077d43(puVar7);
    FUN_00075412(puVar7);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
    *(int *)(iVar2 + 0x1c) = iVar6;
    if (iVar8 == 0) {
      *(uint *)(iVar2 + 0x18) = local_10;
      param_2[0x15] = local_10;
      *(undefined4 *)(iVar2 + 8) = local_14;
      *(undefined4 *)(iVar2 + 0xc) = local_18;
      *(undefined4 *)(iVar2 + 0x2ac) = local_1c;
    }
    else {
      *(undefined4 *)(iVar2 + 0xc) = 0;
      if (local_10 != 0) {
        iVar6 = local_10 * 0x10 + -0x10 + iVar6;
        uVar10 = local_10;
        do {
          if ((((*(byte *)(iVar6 + 4) & 7) == 1) || ((*(byte *)(iVar6 + 8) & 7) == 1)) ||
             ((*(byte *)(iVar6 + 0xc) & 7) == 1)) {
            *(uint *)(iVar2 + 0xc) = uVar10 - 1;
          }
          iVar6 = iVar6 + -0x10;
          uVar10 = uVar10 - 1;
        } while ((uVar10 != 0) && (*(int *)(iVar2 + 0xc) == 0));
      }
    }
    pbVar9 = *(byte **)(iVar2 + 0x1c);
    if (local_10 != 0) {
      uVar10 = 0;
      do {
        bVar1 = *pbVar9;
        if ((bVar1 & 0x3f) == 4) {
          if ((((pbVar9[4] & 7) == 0) && ((pbVar9[8] & 7) == 0)) && ((pbVar9[0xc] & 7) == 0)) {
            cVar3 = (char)(*(ushort *)(pbVar9 + 8) >> 5);
            cVar4 = (char)(*(ushort *)(pbVar9 + 4) >> 5);
            if (((cVar4 != cVar3) &&
                (cVar5 = (char)(*(ushort *)(pbVar9 + 0xc) >> 5), cVar4 != cVar5)) &&
               (cVar3 != cVar5)) {
              *pbVar9 = bVar1 & 0xc0 | 0x80;
            }
          }
        }
        else if ((((bVar1 & 0x3f) == 0xb) && ((pbVar9[4] & 7) == 0)) &&
                (((pbVar9[8] & 7) == 0 && ((pbVar9[0xc] & 7) == 0)))) {
          cVar3 = (char)(*(ushort *)(pbVar9 + 8) >> 5);
          cVar4 = (char)(*(ushort *)(pbVar9 + 4) >> 5);
          if (((cVar4 != cVar3) && (cVar5 = (char)(*(ushort *)(pbVar9 + 0xc) >> 5), cVar4 != cVar5))
             && (cVar3 != cVar5)) {
            *pbVar9 = bVar1 & 0xc0 | 0x81;
          }
        }
        uVar10 = uVar10 + 1;
        pbVar9 = pbVar9 + 0x10;
      } while (uVar10 < local_10);
    }
  }
  return;
}

/* FUN_0005d8d2 @ 0x5d8d2 (10051 bytes) */
int FUN_0005d8d2(param_1, param_2)
  int param_1;
  int *param_2;
{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  bool bVar5;
  bool bVar6;
  undefined1 uVar7;
  byte bVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  void *pvVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint local_f8;
  uint local_f4;
  uint local_f0;
  uint local_e8;
  uint local_dc;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  undefined4 local_90 [2];
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  
  piVar2 = *(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar3 = *piVar2;
  if ((param_2[6] == 0) || (param_2[5] == 0)) {
    param_2[0xc] = 0;
    param_2[0x15] = 0;
    param_2[0x16] = 0;
    param_2[0x17] = 0;
    param_2[0x18] = 0;
    param_2[0x19] = 0;
    return 1;
  }
  *(undefined1 *)(param_2 + 4) = 1;
  ((int (*)())FUN_0005c7b9)();
  puVar9 = (undefined4 *)(**(code **)(param_1 + 0xc))(param_2[5] << 4);
  if (param_2[5] != 0) {
    local_f8 = 0;
    iVar19 = 0;
    puVar13 = puVar9;
    do {
      iVar12 = param_2[6];
      iVar15 = iVar19 + iVar12;
      if (*(int *)(iVar15 + 4) == 1) {
        puVar4 = *(uint **)(iVar15 + 8);
        if (&UINT_0000879c < puVar4) {
          if (puVar4 < (uint *)0x87a5) {
            if (*(int *)(iVar15 + 0xc) != 0) {
              *(byte *)((int)(puVar4 + -0x21cb) + (int)param_2) =
                   *(byte *)((int)(puVar4 + -0x21cb) + (int)param_2) | 1;
            }
            if (*(int *)(iVar15 + 0x10) != 0) {
              pbVar1 = (byte *)(*(int *)(iVar15 + 8) + -0x872c + (int)param_2);
              *pbVar1 = *pbVar1 | 2;
            }
            if (*(int *)(iVar15 + 0x14) != 0) {
              pbVar1 = (byte *)(*(int *)(iVar15 + 8) + -0x872c + (int)param_2);
              *pbVar1 = *pbVar1 | 4;
            }
            if (*(int *)(iVar15 + 0x18) != 0) {
              pbVar1 = (byte *)(*(int *)(iVar15 + 8) + -0x872c + (int)param_2);
              *pbVar1 = *pbVar1 | 8;
            }
          }
          else if (puVar4 == (uint *)0x87bd) {
            *(undefined1 *)((int)param_2 + 0x7a) = 1;
          }
        }
        else if (puVar4 < (uint *)0x879b) {
          if (puVar4 < (uint *)0x6111) {
            if (puVar4 < (uint *)0x610f) {
              if (puVar4 == (uint *)0x610e) {
                *(undefined1 *)((int)param_2 + 0x79) = 1;
              }
            }
            else {
              *(undefined1 *)((int)(puVar4 + -0x1828) + (int)param_2) = 1;
            }
          }
          else if (puVar4 == (uint *)0x879a) {
            *(undefined1 *)(param_2 + 0x1b) = 1;
          }
        }
        else {
          *(undefined1 *)(((int)puVar4 - 0x872eU) + (int)param_2) = 1;
        }
      }
      *puVar13 = *(undefined4 *)(iVar12 + 0xc + iVar19);
      puVar13[1] = *(undefined4 *)(iVar12 + 0x10 + iVar19);
      puVar13[2] = *(undefined4 *)(iVar12 + 0x14 + iVar19);
      puVar13[3] = *(undefined4 *)(iVar12 + 0x18 + iVar19);
      local_f8 = local_f8 + 1;
      iVar19 = iVar19 + 0x74;
      puVar13 = puVar13 + 4;
    } while (local_f8 < (uint)param_2[5]);
  }
  if ((*(char *)((int)param_2 + 0x7a) == '\0') || ((*(byte *)(param_1 + 0x46) & 8) != 0)) {
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
  }
  *(undefined1 *)(iVar3 + 0x42) = uVar7;
  *(undefined1 *)(iVar3 + 0x43) = *(undefined1 *)((int)param_2 + 0x79);
  if ((*(char *)((int)param_2 + 0x6f) == '\0') && ((char)param_2[0x1c] == '\0')) {
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
  }
  *(undefined1 *)(iVar3 + 0x44) = uVar7;
  bVar8 = *(byte *)(param_1 + 0x47);
  if ((bVar8 & 1) == 0) {
    *(undefined1 *)((int)param_2 + 0x79) = 0;
    bVar8 = *(byte *)(param_1 + 0x47);
  }
  if ((bVar8 & 2) == 0) {
    *(undefined1 *)((int)param_2 + 0x6f) = 0;
    *(undefined1 *)(param_2 + 0x1c) = 0;
  }
  if ((*(char *)((int)param_2 + 0x7a) != '\0') && ((*(byte *)(param_1 + 0x46) & 0x10) != 0)) {
    uVar20 = (uint)*(byte *)(param_1 + 0x11d1);
    if ((*(char *)(uVar20 + 0x71 + (int)param_2) != '\0') && (param_2[5] != 0)) {
      uVar18 = 0;
      iVar19 = 0;
      do {
        iVar15 = iVar19 + param_2[6];
        if ((*(int *)(iVar15 + 4) == 1) && (*(int *)(iVar15 + 8) == uVar20 + 0x879d)) {
          *(undefined4 *)(iVar15 + 0xc) = 0;
          *(undefined4 *)(iVar15 + 0x10) = 0;
          *(undefined4 *)(iVar15 + 0x14) = 0;
          *(undefined4 *)(iVar15 + 0x18) = 0;
        }
        uVar18 = uVar18 + 1;
        iVar19 = iVar19 + 0x74;
      } while (uVar18 < (uint)param_2[5]);
    }
    *(undefined1 *)(uVar20 + 0x71 + (int)param_2) = 0xf;
  }
  if (((char)param_2[0x1b] != '\0') && ((*(byte *)(param_1 + 0x46) & 0x20) != 0)) {
    bVar8 = *(byte *)(param_1 + 0x11d2);
    if ((*(char *)(bVar8 + 0x71 + (int)param_2) != '\0') && (param_2[5] != 0)) {
      uVar20 = 0;
      iVar19 = 0;
      do {
        iVar15 = iVar19 + param_2[6];
        if ((*(int *)(iVar15 + 4) == 1) && (*(int *)(iVar15 + 8) == bVar8 + 0x879d)) {
          *(undefined4 *)(iVar15 + 0xc) = 0;
          *(undefined4 *)(iVar15 + 0x10) = 0;
          *(undefined4 *)(iVar15 + 0x14) = 0;
          *(undefined4 *)(iVar15 + 0x18) = 0;
        }
        uVar20 = uVar20 + 1;
        iVar19 = iVar19 + 0x74;
      } while (uVar20 < (uint)param_2[5]);
    }
    *(undefined1 *)(*(byte *)(param_1 + 0x11d2) + 0x71 + (int)param_2) = 0xf;
  }
  *(undefined4 *)(iVar3 + 0x1e8) = 0;
  if (*(char *)((int)param_2 + 0x79) == '\0') {
    iVar19 = 1;
  }
  else {
    *(undefined4 *)(iVar3 + 0x1fc) = 1;
    iVar19 = 2;
  }
  if ((((param_2[0x1b] & 0xffffff00U) != 0) || ((char)param_2[0x1c] != '\0')) ||
     (*(char *)((int)param_2 + 0x7a) != '\0')) {
    *(int *)(iVar3 + 0x1ec) = iVar19;
    iVar19 = iVar19 + 1;
  }
  if (((*(short *)((int)param_2 + 0x6e) != 0) || ((char)param_2[0x1c] != '\0')) ||
     (*(char *)((int)param_2 + 0x7a) != '\0')) {
    *(int *)(iVar3 + 0x1f0) = iVar19;
    iVar19 = iVar19 + 1;
  }
  if ((*(char *)((int)param_2 + 0x6f) != '\0') || ((char)param_2[0x1c] != '\0')) {
    *(int *)(iVar3 + 500) = iVar19;
    *(int *)(iVar3 + 0x1f8) = iVar19 + 1;
    iVar19 = iVar19 + 2;
  }
  iVar12 = 0;
  piVar10 = param_2;
  iVar15 = iVar3;
  do {
    if (*(char *)((int)piVar10 + 0x71) != '\0') {
      *(int *)(iVar15 + 0x200) = iVar19;
      iVar19 = iVar19 + 1;
    }
    iVar12 = iVar12 + 1;
    piVar10 = (int *)((int)piVar10 + 1);
    iVar15 = iVar15 + 4;
  } while (iVar12 != 8);
  *(undefined4 *)(iVar3 + 0x224) = 0;
  *(undefined4 *)(iVar3 + 0x22c) = 0;
  if (param_2[5] != 0) {
    local_ac = 0;
    local_b4 = 0;
    do {
      iVar19 = param_2[6];
      if (*(int *)(local_b4 + iVar19 + 0x20) == 2) {
        iVar14 = *(int *)(local_b4 + iVar19 + 0x24);
        iVar12 = iVar14 * 0x54;
        iVar17 = param_2[8];
        iVar15 = iVar12 + iVar17;
        if ((*(int *)(iVar15 + 0x28) == 0x87c2) && (*(char *)(iVar15 + 0x3d) == '\0')) {
          if (*(int *)(iVar15 + 0x30) == 0) {
            if (*(uint *)(iVar15 + 0x34) < 2) {
              FUN_000543b0(iVar15);
              iVar19 = param_2[6];
              goto LAB_0005dc58;
            }
          }
          else {
            iVar14 = FUN_0005369a(param_2 + 7,*(int *)(iVar15 + 0x30));
            iVar12 = iVar14 * 0x54;
            iVar17 = param_2[8];
          }
          if (*(int *)(iVar17 + 0x34 + iVar12) == 0) {
            iVar19 = param_2[6];
          }
          else {
            iVar14 = iVar14 * 0x54;
            local_f0 = 0;
            do {
              FUN_000543b0(iVar14 + iVar17);
              local_f0 = local_f0 + 1;
              iVar17 = param_2[8];
              iVar14 = iVar14 + 0x54;
            } while (local_f0 < *(uint *)(iVar17 + 0x34 + iVar12));
            iVar19 = param_2[6];
          }
        }
      }
LAB_0005dc58:
      if (*(int *)(local_b4 + iVar19 + 0x3c) == 2) {
        local_b8 = *(int *)(local_b4 + iVar19 + 0x40);
        local_c4 = local_b8 * 0x54;
        iVar15 = param_2[8];
        iVar12 = local_c4 + iVar15;
        if ((*(int *)(iVar12 + 0x28) == 0x87c2) && (*(char *)(iVar12 + 0x3d) == '\0')) {
          if (*(int *)(iVar12 + 0x30) == 0) {
            if (1 < *(uint *)(iVar12 + 0x34)) goto LAB_0005deb0;
            param_2[0x17] = param_2[0x17] + 1;
            if (*(char *)(iVar12 + 0x44) == '\0') {
              *(int *)(iVar3 + 0x224) = *(int *)(iVar3 + 0x224) + 1;
            }
            else {
              *(int *)(iVar3 + 0x22c) = *(int *)(iVar3 + 0x22c) + 1;
            }
            *(undefined1 *)(iVar12 + 0x3d) = 1;
            iVar19 = *(int *)(iVar12 + 0x24);
            if (iVar19 == 0x87bf) {
              *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 1;
              bVar5 = false;
              iVar19 = 0;
              for (uVar20 = 0; uVar20 < *(uint *)(iVar3 + 0x58); uVar20 = uVar20 + 1) {
                while( true ) {
                  if (bVar5) goto LAB_0005fb5e;
                  if (*(char *)(iVar19 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                  bVar5 = true;
                  if (*(uint *)(iVar3 + 0x58) <= uVar20) goto LAB_0005fb56;
                }
                iVar19 = iVar19 + 0x28;
              }
LAB_0005fb56:
              if (bVar5) {
LAB_0005fb5e:
                *(uint *)(iVar12 + 4) = uVar20;
LAB_0005fb67:
                *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + uVar20 * 0x28) = 1;
              }
              else {
                *(undefined1 *)(param_2 + 4) = 0;
                iVar19 = *(int *)(iVar3 + 0x58);
                uVar11 = (**(code **)(param_1 + 0x10))(iVar19 + 0x10,0x28);
                (**(code **)(param_1 + 0x1344))
                          (uVar11,*(undefined4 *)(iVar3 + 0x54),*(int *)(iVar3 + 0x58) * 0x28);
                (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x54));
                *(undefined4 *)(iVar3 + 0x54) = uVar11;
                *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 0x10;
                *(int *)(iVar12 + 4) = iVar19;
LAB_0005fefa:
                *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + iVar19 * 0x28) = 1;
              }
LAB_0005f62d:
              iVar19 = param_2[6];
              goto LAB_0005dc6d;
            }
            if (iVar19 != 0x87c0) {
              if (iVar19 == 0x87be) {
                *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 1;
                bVar5 = false;
                iVar19 = 0;
                for (uVar20 = 0; uVar20 < *(uint *)(iVar3 + 0x58); uVar20 = uVar20 + 1) {
                  while( true ) {
                    if (bVar5) goto LAB_0005fddf;
                    if (*(char *)(iVar19 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                    bVar5 = true;
                    if (*(uint *)(iVar3 + 0x58) <= uVar20) goto LAB_0005fdd7;
                  }
                  iVar19 = iVar19 + 0x28;
                }
LAB_0005fdd7:
                if (!bVar5) {
                  *(undefined1 *)(param_2 + 4) = 0;
                  iVar19 = *(int *)(iVar3 + 0x58);
                  uVar11 = (**(code **)(param_1 + 0x10))(iVar19 + 0x10,0x28);
                  (**(code **)(param_1 + 0x1344))
                            (uVar11,*(undefined4 *)(iVar3 + 0x54),*(int *)(iVar3 + 0x58) * 0x28);
                  (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x54));
                  *(undefined4 *)(iVar3 + 0x54) = uVar11;
                  *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 0x10;
                  *(int *)(iVar12 + 4) = iVar19;
                  *(undefined4 *)(iVar12 + 8) = 0;
                  goto LAB_0005fefa;
                }
LAB_0005fddf:
                *(uint *)(iVar12 + 4) = uVar20;
                *(undefined4 *)(iVar12 + 8) = 0;
                goto LAB_0005fb67;
              }
              goto LAB_0005f62d;
            }
            *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 4;
            uVar20 = *(int *)(iVar3 + 0x58) - 3;
            bVar5 = false;
            iVar19 = 0;
            for (uVar18 = 0; uVar18 < uVar20; uVar18 = uVar18 + 1) {
              while( true ) {
                if (bVar5) goto LAB_0005eb21;
                if (*(char *)(iVar19 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                bVar5 = true;
                if (uVar20 <= uVar18) goto LAB_0005eb19;
              }
              iVar19 = iVar19 + 0x28;
            }
LAB_0005eb19:
            if (bVar5) {
LAB_0005eb21:
              iVar19 = uVar18 * 0x28;
              iVar15 = iVar19 + *(int *)(iVar3 + 0x54);
              if (((*(char *)(iVar15 + 0x38) != '\0') || (*(char *)(iVar15 + 0x60) != '\0')) ||
                 (*(char *)(iVar15 + 0x88) != '\0')) goto LAB_0005fceb;
              iVar15 = 0;
              do {
                *(uint *)(iVar12 + 0x10) = uVar18 + iVar15;
                *(undefined1 *)(iVar19 + 0x10 + *(int *)(iVar3 + 0x54)) = 1;
                iVar15 = iVar15 + 1;
                iVar12 = iVar12 + 4;
                iVar19 = iVar19 + 0x28;
              } while (iVar15 != 4);
            }
            else {
LAB_0005fceb:
              *(undefined1 *)(param_2 + 4) = 0;
              iVar15 = *(int *)(iVar3 + 0x58);
              uVar11 = (**(code **)(param_1 + 0x10))(iVar15 + 0x10,0x28);
              (**(code **)(param_1 + 0x1344))
                        (uVar11,*(undefined4 *)(iVar3 + 0x54),*(int *)(iVar3 + 0x58) * 0x28);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x54));
              *(undefined4 *)(iVar3 + 0x54) = uVar11;
              *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 0x10;
              iVar19 = iVar15 * 0x28;
              iVar14 = 0;
              do {
                *(int *)(iVar12 + 0x10) = iVar14 + iVar15;
                *(undefined1 *)(iVar19 + 0x10 + *(int *)(iVar3 + 0x54)) = 1;
                iVar14 = iVar14 + 1;
                iVar12 = iVar12 + 4;
                iVar19 = iVar19 + 0x28;
              } while (iVar14 != 4);
            }
          }
          else {
            local_b8 = FUN_0005369a(param_2 + 7,*(int *)(iVar12 + 0x30));
            local_c4 = local_b8 * 0x54;
            iVar15 = param_2[8];
LAB_0005deb0:
            if (*(int *)(local_c4 + 0x34 + iVar15) == 0) {
              iVar19 = param_2[6];
              goto LAB_0005dc6d;
            }
            local_b8 = local_b8 * 0x54;
            local_e8 = 0;
            do {
              iVar19 = local_b8 + iVar15;
              if (*(int *)(iVar19 + 0x28) == 0x87c2) {
                param_2[0x17] = param_2[0x17] + 1;
                if (*(char *)(iVar19 + 0x44) == '\0') {
                  *(int *)(iVar3 + 0x224) = *(int *)(iVar3 + 0x224) + 1;
                }
                else {
                  *(int *)(iVar3 + 0x22c) = *(int *)(iVar3 + 0x22c) + 1;
                }
                *(undefined1 *)(iVar19 + 0x3d) = 1;
                iVar15 = *(int *)(iVar19 + 0x24);
                if (iVar15 == 0x87bf) {
                  *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 1;
                  bVar6 = false;
                  iVar15 = 0;
                  for (uVar20 = 0; bVar5 = bVar6, uVar20 < *(uint *)(iVar3 + 0x58);
                      uVar20 = uVar20 + 1) {
                    while( true ) {
                      if (bVar6) goto LAB_0005ebfb;
                      if (*(char *)(iVar15 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                      bVar6 = true;
                      bVar5 = true;
                      if (*(uint *)(iVar3 + 0x58) <= uVar20) goto LAB_0005ebf3;
                    }
                    iVar15 = iVar15 + 0x28;
                  }
LAB_0005ebf3:
                  if (bVar5) {
LAB_0005ebfb:
                    *(uint *)(iVar19 + 4) = uVar20;
LAB_0005ec04:
                    *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + uVar20 * 0x28) = 1;
                    iVar15 = param_2[8];
                  }
                  else {
                    *(undefined1 *)(param_2 + 4) = 0;
                    iVar15 = *(int *)(iVar3 + 0x58);
                    uVar11 = (**(code **)(param_1 + 0x10))(iVar15 + 0x10,0x28);
                    (**(code **)(param_1 + 0x1344))
                              (uVar11,*(undefined4 *)(iVar3 + 0x54),*(int *)(iVar3 + 0x58) * 0x28);
                    (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x54));
                    *(undefined4 *)(iVar3 + 0x54) = uVar11;
                    *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 0x10;
                    *(int *)(iVar19 + 4) = iVar15;
LAB_0005f825:
                    *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + iVar15 * 0x28) = 1;
                    iVar15 = param_2[8];
                  }
                }
                else {
                  if (iVar15 == 0x87c0) {
                    *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 4;
                    uVar20 = *(int *)(iVar3 + 0x58) - 3;
                    bVar5 = false;
                    iVar15 = 0;
                    for (uVar18 = 0; uVar18 < uVar20; uVar18 = uVar18 + 1) {
                      while( true ) {
                        if (bVar5) goto LAB_0005f006;
                        if (*(char *)(iVar15 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                        bVar5 = true;
                        if (uVar20 <= uVar18) goto LAB_0005effe;
                      }
                      iVar15 = iVar15 + 0x28;
                    }
LAB_0005effe:
                    if (bVar5) {
LAB_0005f006:
                      iVar15 = uVar18 * 0x28;
                      iVar12 = iVar15 + *(int *)(iVar3 + 0x54);
                      if (((*(char *)(iVar12 + 0x38) == '\0') && (*(char *)(iVar12 + 0x60) == '\0'))
                         && (*(char *)(iVar12 + 0x88) == '\0')) {
                        iVar12 = 0;
                        do {
                          *(uint *)(iVar19 + 0x10) = uVar18 + iVar12;
                          *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + iVar15) = 1;
                          iVar12 = iVar12 + 1;
                          iVar19 = iVar19 + 4;
                          iVar15 = iVar15 + 0x28;
                        } while (iVar12 != 4);
                        goto LAB_0005df76;
                      }
                    }
                    *(undefined1 *)(param_2 + 4) = 0;
                    iVar12 = *(int *)(iVar3 + 0x58);
                    uVar11 = (**(code **)(param_1 + 0x10))(iVar12 + 0x10,0x28);
                    (**(code **)(param_1 + 0x1344))
                              (uVar11,*(undefined4 *)(iVar3 + 0x54),*(int *)(iVar3 + 0x58) * 0x28);
                    (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x54));
                    *(undefined4 *)(iVar3 + 0x54) = uVar11;
                    *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 0x10;
                    iVar15 = iVar12 * 0x28;
                    iVar14 = 0;
                    do {
                      *(int *)(iVar19 + 0x10) = iVar14 + iVar12;
                      *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + iVar15) = 1;
                      iVar14 = iVar14 + 1;
                      iVar19 = iVar19 + 4;
                      iVar15 = iVar15 + 0x28;
                    } while (iVar14 != 4);
                  }
                  else if (iVar15 == 0x87be) {
                    *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 1;
                    bVar6 = false;
                    iVar15 = 0;
                    for (uVar20 = 0; bVar5 = bVar6, uVar20 < *(uint *)(iVar3 + 0x58);
                        uVar20 = uVar20 + 1) {
                      while( true ) {
                        if (bVar6) goto LAB_0005f3f1;
                        if (*(char *)(iVar15 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                        bVar6 = true;
                        bVar5 = true;
                        if (*(uint *)(iVar3 + 0x58) <= uVar20) goto LAB_0005f3e9;
                      }
                      iVar15 = iVar15 + 0x28;
                    }
LAB_0005f3e9:
                    if (!bVar5) {
                      *(undefined1 *)(param_2 + 4) = 0;
                      iVar15 = *(int *)(iVar3 + 0x58);
                      uVar11 = (**(code **)(param_1 + 0x10))(iVar15 + 0x10,0x28);
                      (**(code **)(param_1 + 0x1344))
                                (uVar11,*(undefined4 *)(iVar3 + 0x54),*(int *)(iVar3 + 0x58) * 0x28)
                      ;
                      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x54));
                      *(undefined4 *)(iVar3 + 0x54) = uVar11;
                      *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 0x10;
                      *(int *)(iVar19 + 4) = iVar15;
                      *(undefined4 *)(iVar19 + 8) = 0;
                      goto LAB_0005f825;
                    }
LAB_0005f3f1:
                    *(uint *)(iVar19 + 4) = uVar20;
                    *(undefined4 *)(iVar19 + 8) = 0;
                    goto LAB_0005ec04;
                  }
LAB_0005df76:
                  iVar15 = param_2[8];
                }
              }
              else if (*(int *)(iVar19 + 0x28) == 0x87c3) {
                param_2[0x18] = param_2[0x18] + 1;
                *(undefined1 *)(iVar19 + 0x3d) = 1;
                iVar15 = *(int *)(iVar19 + 0x24);
                if (iVar15 == 0x87bf) {
                  *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 1;
                  bVar5 = false;
                  iVar15 = 0;
                  for (uVar20 = 0; bVar6 = bVar5, uVar20 < *(uint *)(iVar3 + 0x58);
                      uVar20 = uVar20 + 1) {
                    while( true ) {
                      bVar5 = bVar6;
                      if (bVar5) goto LAB_0005ebfb;
                      if (*(char *)(iVar15 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                      bVar5 = true;
                      bVar6 = true;
                      if (*(uint *)(iVar3 + 0x58) <= uVar20) goto LAB_0005ebf3;
                    }
                    iVar15 = iVar15 + 0x28;
                  }
                  goto LAB_0005ebf3;
                }
                if (iVar15 == 0x87c0) {
                  *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 4;
                  uVar20 = *(int *)(iVar3 + 0x58) - 3;
                  bVar5 = false;
                  iVar15 = 0;
                  for (uVar18 = 0; uVar18 < uVar20; uVar18 = uVar18 + 1) {
                    while( true ) {
                      if (bVar5) goto LAB_0005f333;
                      if (*(char *)(iVar15 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                      bVar5 = true;
                      if (uVar20 <= uVar18) goto LAB_0005f32b;
                    }
                    iVar15 = iVar15 + 0x28;
                  }
LAB_0005f32b:
                  if (bVar5) {
LAB_0005f333:
                    iVar15 = uVar18 * 0x28;
                    iVar12 = iVar15 + *(int *)(iVar3 + 0x54);
                    if (((*(char *)(iVar12 + 0x38) == '\0') && (*(char *)(iVar12 + 0x60) == '\0'))
                       && (*(char *)(iVar12 + 0x88) == '\0')) {
                      iVar12 = 0;
                      do {
                        *(uint *)(iVar19 + 0x10) = iVar12 + uVar18;
                        *(undefined1 *)(iVar15 + 0x10 + *(int *)(iVar3 + 0x54)) = 1;
                        iVar12 = iVar12 + 1;
                        iVar19 = iVar19 + 4;
                        iVar15 = iVar15 + 0x28;
                      } while (iVar12 != 4);
                      goto LAB_0005df76;
                    }
                  }
                  *(undefined1 *)(param_2 + 4) = 0;
                  iVar12 = *(int *)(iVar3 + 0x58);
                  uVar11 = (**(code **)(param_1 + 0x10))(iVar12 + 0x10,0x28);
                  (**(code **)(param_1 + 0x1344))
                            (uVar11,*(undefined4 *)(iVar3 + 0x54),*(int *)(iVar3 + 0x58) * 0x28);
                  (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x54));
                  *(undefined4 *)(iVar3 + 0x54) = uVar11;
                  *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 0x10;
                  iVar15 = iVar12 * 0x28;
                  iVar14 = 0;
                  do {
                    *(int *)(iVar19 + 0x10) = iVar14 + iVar12;
                    *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + iVar15) = 1;
                    iVar14 = iVar14 + 1;
                    iVar19 = iVar19 + 4;
                    iVar15 = iVar15 + 0x28;
                  } while (iVar14 != 4);
                  iVar15 = param_2[8];
                }
                else {
                  if (iVar15 == 0x87be) {
                    *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 1;
                    bVar5 = false;
                    iVar15 = 0;
                    for (uVar20 = 0; bVar6 = bVar5, uVar20 < *(uint *)(iVar3 + 0x58);
                        uVar20 = uVar20 + 1) {
                      while( true ) {
                        bVar5 = bVar6;
                        if (bVar5) goto LAB_0005f3f1;
                        if (*(char *)(iVar15 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                        bVar5 = true;
                        bVar6 = true;
                        if (*(uint *)(iVar3 + 0x58) <= uVar20) goto LAB_0005f3e9;
                      }
                      iVar15 = iVar15 + 0x28;
                    }
                    goto LAB_0005f3e9;
                  }
                  iVar15 = param_2[8];
                }
              }
              local_e8 = local_e8 + 1;
              local_b8 = local_b8 + 0x54;
            } while (local_e8 < *(uint *)(local_c4 + 0x34 + iVar15));
          }
          iVar19 = param_2[6];
        }
      }
LAB_0005dc6d:
      if (*(int *)(local_b4 + iVar19 + 0x58) == 2) {
        local_bc = *(int *)(local_b4 + iVar19 + 0x5c);
        local_c8 = local_bc * 0x54;
        iVar19 = param_2[8];
        iVar15 = local_c8 + iVar19;
        if ((*(int *)(iVar15 + 0x28) == 0x87c2) && (*(char *)(iVar15 + 0x3d) == '\0')) {
          if (*(int *)(iVar15 + 0x30) == 0) {
            if (*(uint *)(iVar15 + 0x34) < 2) {
              param_2[0x17] = param_2[0x17] + 1;
              if (*(char *)(iVar15 + 0x44) == '\0') {
                *(int *)(iVar3 + 0x224) = *(int *)(iVar3 + 0x224) + 1;
              }
              else {
                *(int *)(iVar3 + 0x22c) = *(int *)(iVar3 + 0x22c) + 1;
              }
              *(undefined1 *)(iVar15 + 0x3d) = 1;
              iVar19 = *(int *)(iVar15 + 0x24);
              if (iVar19 == 0x87bf) {
                *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 1;
                bVar5 = false;
                iVar19 = 0;
                for (uVar20 = 0; uVar20 < *(uint *)(iVar3 + 0x58); uVar20 = uVar20 + 1) {
                  while( true ) {
                    if (bVar5) goto LAB_0005f9ed;
                    if (*(char *)(iVar19 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                    bVar5 = true;
                    if (*(uint *)(iVar3 + 0x58) <= uVar20) goto LAB_0005f9e3;
                  }
                  iVar19 = iVar19 + 0x28;
                }
LAB_0005f9e3:
                if (bVar5) {
LAB_0005f9ed:
                  *(uint *)(iVar15 + 4) = uVar20;
                  *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + uVar20 * 0x28) = 1;
                }
                else {
                  *(undefined1 *)(param_2 + 4) = 0;
                  iVar19 = *(int *)(iVar3 + 0x58);
                  uVar11 = (**(code **)(param_1 + 0x10))(iVar19 + 0x10,0x28);
                  (**(code **)(param_1 + 0x1344))
                            (uVar11,*(undefined4 *)(iVar3 + 0x54),*(int *)(iVar3 + 0x58) * 0x28);
                  (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x54));
                  *(undefined4 *)(iVar3 + 0x54) = uVar11;
                  *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 0x10;
                  *(int *)(iVar15 + 4) = iVar19;
                  *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + iVar19 * 0x28) = 1;
                }
              }
              else if (iVar19 == 0x87c0) {
                *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 4;
                uVar20 = *(int *)(iVar3 + 0x58) - 3;
                bVar5 = false;
                iVar19 = 0;
                for (uVar18 = 0; uVar18 < uVar20; uVar18 = uVar18 + 1) {
                  while( true ) {
                    if (bVar5) goto LAB_0005fbce;
                    if (*(char *)(iVar19 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                    bVar5 = true;
                    if (uVar20 <= uVar18) goto LAB_0005fbca;
                  }
                  iVar19 = iVar19 + 0x28;
                }
LAB_0005fbca:
                if (bVar5) {
LAB_0005fbce:
                  iVar19 = uVar18 * 0x28;
                  iVar12 = iVar19 + *(int *)(iVar3 + 0x54);
                  if (((*(char *)(iVar12 + 0x38) == '\0') && (*(char *)(iVar12 + 0x60) == '\0')) &&
                     (*(char *)(iVar12 + 0x88) == '\0')) {
                    iVar12 = 0;
                    do {
                      *(uint *)(iVar15 + 0x10) = iVar12 + uVar18;
                      *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + iVar19) = 1;
                      iVar12 = iVar12 + 1;
                      iVar15 = iVar15 + 4;
                      iVar19 = iVar19 + 0x28;
                    } while (iVar12 != 4);
                    goto LAB_0005dc82;
                  }
                }
                *(undefined1 *)(param_2 + 4) = 0;
                iVar12 = *(int *)(iVar3 + 0x58);
                uVar11 = (**(code **)(param_1 + 0x10))(iVar12 + 0x10,0x28);
                (**(code **)(param_1 + 0x1344))
                          (uVar11,*(undefined4 *)(iVar3 + 0x54),*(int *)(iVar3 + 0x58) * 0x28);
                (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x54));
                *(undefined4 *)(iVar3 + 0x54) = uVar11;
                *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 0x10;
                iVar19 = iVar12 * 0x28;
                iVar14 = 0;
                do {
                  *(int *)(iVar15 + 0x10) = iVar14 + iVar12;
                  *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + iVar19) = 1;
                  iVar14 = iVar14 + 1;
                  iVar15 = iVar15 + 4;
                  iVar19 = iVar19 + 0x28;
                } while (iVar14 != 4);
              }
              else if (iVar19 == 0x87be) {
                *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 1;
                bVar5 = false;
                iVar19 = 0;
                for (uVar20 = 0; uVar20 < *(uint *)(iVar3 + 0x58); uVar20 = uVar20 + 1) {
                  while( true ) {
                    if (bVar5) goto LAB_0005f6d2;
                    if (*(char *)(iVar19 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                    bVar5 = true;
                    if (*(uint *)(iVar3 + 0x58) <= uVar20) goto LAB_0005f6ca;
                  }
                  iVar19 = iVar19 + 0x28;
                }
LAB_0005f6ca:
                if (bVar5) {
LAB_0005f6d2:
                  *(uint *)(iVar15 + 4) = uVar20;
                  *(undefined4 *)(iVar15 + 8) = 0;
                  *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + uVar20 * 0x28) = 1;
                }
                else {
                  *(undefined1 *)(param_2 + 4) = 0;
                  iVar19 = *(int *)(iVar3 + 0x58);
                  uVar11 = (**(code **)(param_1 + 0x10))(iVar19 + 0x10,0x28);
                  (**(code **)(param_1 + 0x1344))
                            (uVar11,*(undefined4 *)(iVar3 + 0x54),*(int *)(iVar3 + 0x58) * 0x28);
                  (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x54));
                  *(undefined4 *)(iVar3 + 0x54) = uVar11;
                  *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 0x10;
                  *(int *)(iVar15 + 4) = iVar19;
                  *(undefined4 *)(iVar15 + 8) = 0;
                  *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + iVar19 * 0x28) = 1;
                }
              }
              goto LAB_0005dc82;
            }
          }
          else {
            local_bc = FUN_0005369a(param_2 + 7,*(int *)(iVar15 + 0x30));
            local_c8 = local_bc * 0x54;
            iVar19 = param_2[8];
          }
          if (*(int *)(iVar19 + 0x34 + local_c8) != 0) {
            local_bc = local_bc * 0x54;
            local_dc = 0;
            do {
              iVar15 = local_bc + iVar19;
              if (*(int *)(iVar15 + 0x28) == 0x87c2) {
                param_2[0x17] = param_2[0x17] + 1;
                if (*(char *)(iVar15 + 0x44) == '\0') {
                  *(int *)(iVar3 + 0x224) = *(int *)(iVar3 + 0x224) + 1;
                }
                else {
                  *(int *)(iVar3 + 0x22c) = *(int *)(iVar3 + 0x22c) + 1;
                }
                *(undefined1 *)(iVar15 + 0x3d) = 1;
                iVar19 = *(int *)(iVar15 + 0x24);
                if (iVar19 == 0x87bf) {
                  *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 1;
                  bVar6 = false;
                  iVar19 = 0;
                  for (uVar20 = 0; bVar5 = bVar6, uVar20 < *(uint *)(iVar3 + 0x58);
                      uVar20 = uVar20 + 1) {
                    while( true ) {
                      if (bVar6) goto LAB_0005ec72;
                      if (*(char *)(iVar19 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                      bVar6 = true;
                      bVar5 = true;
                      if (*(uint *)(iVar3 + 0x58) <= uVar20) goto LAB_0005ec6a;
                    }
                    iVar19 = iVar19 + 0x28;
                  }
LAB_0005ec6a:
                  if (bVar5) {
LAB_0005ec72:
                    *(uint *)(iVar15 + 4) = uVar20;
LAB_0005ec7b:
                    *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + uVar20 * 0x28) = 1;
                    iVar19 = param_2[8];
                  }
                  else {
                    *(undefined1 *)(param_2 + 4) = 0;
                    iVar19 = *(int *)(iVar3 + 0x58);
                    uVar11 = (**(code **)(param_1 + 0x10))(iVar19 + 0x10,0x28);
                    (**(code **)(param_1 + 0x1344))
                              (uVar11,*(undefined4 *)(iVar3 + 0x54),*(int *)(iVar3 + 0x58) * 0x28);
                    (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x54));
                    *(undefined4 *)(iVar3 + 0x54) = uVar11;
                    *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 0x10;
                    *(int *)(iVar15 + 4) = iVar19;
LAB_0005f8b5:
                    *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + iVar19 * 0x28) = 1;
                    iVar19 = param_2[8];
                  }
                }
                else {
                  if (iVar19 == 0x87c0) {
                    *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 4;
                    uVar20 = *(int *)(iVar3 + 0x58) - 3;
                    bVar5 = false;
                    iVar19 = 0;
                    for (uVar18 = 0; uVar18 < uVar20; uVar18 = uVar18 + 1) {
                      while( true ) {
                        if (bVar5) goto LAB_0005eeee;
                        if (*(char *)(iVar19 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                        bVar5 = true;
                        if (uVar20 <= uVar18) goto LAB_0005eee6;
                      }
                      iVar19 = iVar19 + 0x28;
                    }
LAB_0005eee6:
                    if (bVar5) {
LAB_0005eeee:
                      iVar19 = uVar18 * 0x28;
                      iVar12 = iVar19 + *(int *)(iVar3 + 0x54);
                      if (((*(char *)(iVar12 + 0x38) == '\0') && (*(char *)(iVar12 + 0x60) == '\0'))
                         && (*(char *)(iVar12 + 0x88) == '\0')) {
                        iVar12 = 0;
                        do {
                          *(uint *)(iVar15 + 0x10) = iVar12 + uVar18;
                          *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + iVar19) = 1;
                          iVar12 = iVar12 + 1;
                          iVar15 = iVar15 + 4;
                          iVar19 = iVar19 + 0x28;
                        } while (iVar12 != 4);
                        goto LAB_0005de57;
                      }
                    }
                    *(undefined1 *)(param_2 + 4) = 0;
                    iVar12 = *(int *)(iVar3 + 0x58);
                    uVar11 = (**(code **)(param_1 + 0x10))(iVar12 + 0x10,0x28);
                    (**(code **)(param_1 + 0x1344))
                              (uVar11,*(undefined4 *)(iVar3 + 0x54),*(int *)(iVar3 + 0x58) * 0x28);
                    (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x54));
                    *(undefined4 *)(iVar3 + 0x54) = uVar11;
                    *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 0x10;
                    iVar19 = iVar12 * 0x28;
                    iVar14 = 0;
                    do {
                      *(int *)(iVar15 + 0x10) = iVar12 + iVar14;
                      *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + iVar19) = 1;
                      iVar14 = iVar14 + 1;
                      iVar15 = iVar15 + 4;
                      iVar19 = iVar19 + 0x28;
                    } while (iVar14 != 4);
                  }
                  else if (iVar19 == 0x87be) {
                    *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 1;
                    bVar6 = false;
                    iVar19 = 0;
                    for (uVar20 = 0; bVar5 = bVar6, uVar20 < *(uint *)(iVar3 + 0x58);
                        uVar20 = uVar20 + 1) {
                      while( true ) {
                        if (bVar6) goto LAB_0005f458;
                        if (*(char *)(iVar19 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                        bVar6 = true;
                        bVar5 = true;
                        if (*(uint *)(iVar3 + 0x58) <= uVar20) goto LAB_0005f450;
                      }
                      iVar19 = iVar19 + 0x28;
                    }
LAB_0005f450:
                    if (!bVar5) {
                      *(undefined1 *)(param_2 + 4) = 0;
                      iVar19 = *(int *)(iVar3 + 0x58);
                      uVar11 = (**(code **)(param_1 + 0x10))(iVar19 + 0x10,0x28);
                      (**(code **)(param_1 + 0x1344))
                                (uVar11,*(undefined4 *)(iVar3 + 0x54),*(int *)(iVar3 + 0x58) * 0x28)
                      ;
                      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x54));
                      *(undefined4 *)(iVar3 + 0x54) = uVar11;
                      *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 0x10;
                      *(int *)(iVar15 + 4) = iVar19;
                      *(undefined4 *)(iVar15 + 8) = 0;
                      goto LAB_0005f8b5;
                    }
LAB_0005f458:
                    *(uint *)(iVar15 + 4) = uVar20;
                    *(undefined4 *)(iVar15 + 8) = 0;
                    goto LAB_0005ec7b;
                  }
LAB_0005de57:
                  iVar19 = param_2[8];
                }
              }
              else if (*(int *)(iVar15 + 0x28) == 0x87c3) {
                param_2[0x18] = param_2[0x18] + 1;
                *(undefined1 *)(iVar15 + 0x3d) = 1;
                iVar19 = *(int *)(iVar15 + 0x24);
                if (iVar19 == 0x87bf) {
                  *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 1;
                  bVar5 = false;
                  iVar19 = 0;
                  for (uVar20 = 0; bVar6 = bVar5, uVar20 < *(uint *)(iVar3 + 0x58);
                      uVar20 = uVar20 + 1) {
                    while( true ) {
                      bVar5 = bVar6;
                      if (bVar5) goto LAB_0005ec72;
                      if (*(char *)(iVar19 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                      bVar5 = true;
                      bVar6 = true;
                      if (*(uint *)(iVar3 + 0x58) <= uVar20) goto LAB_0005ec6a;
                    }
                    iVar19 = iVar19 + 0x28;
                  }
                  goto LAB_0005ec6a;
                }
                if (iVar19 == 0x87c0) {
                  *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 4;
                  uVar20 = *(int *)(iVar3 + 0x58) - 3;
                  bVar5 = false;
                  iVar19 = 0;
                  for (uVar18 = 0; uVar18 < uVar20; uVar18 = uVar18 + 1) {
                    while( true ) {
                      if (bVar5) goto LAB_0005f272;
                      if (*(char *)(iVar19 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                      bVar5 = true;
                      if (uVar20 <= uVar18) goto LAB_0005f26a;
                    }
                    iVar19 = iVar19 + 0x28;
                  }
LAB_0005f26a:
                  if (bVar5) {
LAB_0005f272:
                    iVar19 = uVar18 * 0x28;
                    iVar12 = iVar19 + *(int *)(iVar3 + 0x54);
                    if (((*(char *)(iVar12 + 0x38) == '\0') && (*(char *)(iVar12 + 0x60) == '\0'))
                       && (*(char *)(iVar12 + 0x88) == '\0')) {
                      iVar12 = 0;
                      do {
                        *(uint *)(iVar15 + 0x10) = iVar12 + uVar18;
                        *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + iVar19) = 1;
                        iVar12 = iVar12 + 1;
                        iVar15 = iVar15 + 4;
                        iVar19 = iVar19 + 0x28;
                      } while (iVar12 != 4);
                      goto LAB_0005de57;
                    }
                  }
                  *(undefined1 *)(param_2 + 4) = 0;
                  iVar12 = *(int *)(iVar3 + 0x58);
                  uVar11 = (**(code **)(param_1 + 0x10))(iVar12 + 0x10,0x28);
                  (**(code **)(param_1 + 0x1344))
                            (uVar11,*(undefined4 *)(iVar3 + 0x54),*(int *)(iVar3 + 0x58) * 0x28);
                  (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x54));
                  *(undefined4 *)(iVar3 + 0x54) = uVar11;
                  *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 0x10;
                  iVar19 = iVar12 * 0x28;
                  iVar14 = 0;
                  do {
                    *(int *)(iVar15 + 0x10) = iVar12 + iVar14;
                    *(undefined1 *)(*(int *)(iVar3 + 0x54) + 0x10 + iVar19) = 1;
                    iVar14 = iVar14 + 1;
                    iVar15 = iVar15 + 4;
                    iVar19 = iVar19 + 0x28;
                  } while (iVar14 != 4);
                  iVar19 = param_2[8];
                }
                else {
                  if (iVar19 == 0x87be) {
                    *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 1;
                    bVar5 = false;
                    iVar19 = 0;
                    for (uVar20 = 0; bVar6 = bVar5, uVar20 < *(uint *)(iVar3 + 0x58);
                        uVar20 = uVar20 + 1) {
                      while( true ) {
                        bVar5 = bVar6;
                        if (bVar5) goto LAB_0005f458;
                        if (*(char *)(iVar19 + 0x10 + *(int *)(iVar3 + 0x54)) != '\0') break;
                        bVar5 = true;
                        bVar6 = true;
                        if (*(uint *)(iVar3 + 0x58) <= uVar20) goto LAB_0005f450;
                      }
                      iVar19 = iVar19 + 0x28;
                    }
                    goto LAB_0005f450;
                  }
                  iVar19 = param_2[8];
                }
              }
              local_dc = local_dc + 1;
              local_bc = local_bc + 0x54;
            } while (local_dc < *(uint *)(iVar19 + 0x34 + local_c8));
          }
        }
      }
LAB_0005dc82:
      local_ac = local_ac + 1;
      local_b4 = local_b4 + 0x74;
    } while (local_ac < (uint)param_2[5]);
    if (param_2[5] != 0) {
      local_a8 = 0;
      local_c0 = 0;
      piVar10 = param_2 + 7;
      do {
        iVar19 = param_2[6];
        if (*(int *)(local_c0 + iVar19 + 0x20) == 2) {
          iVar14 = *(int *)(local_c0 + iVar19 + 0x24);
          iVar12 = iVar14 * 0x54;
          iVar17 = param_2[8];
          iVar15 = iVar12 + iVar17;
          if ((*(int *)(iVar15 + 0x28) == 0x87c3) && (*(char *)(iVar15 + 0x3d) == '\0')) {
            if (*(int *)(iVar15 + 0x30) == 0) {
              if (*(uint *)(iVar15 + 0x34) < 2) {
                FUN_000543b0(iVar15);
                iVar19 = param_2[6];
                goto LAB_0005e403;
              }
            }
            else {
              iVar14 = FUN_0005369a(piVar10,*(int *)(iVar15 + 0x30));
              iVar12 = iVar14 * 0x54;
              iVar17 = param_2[8];
            }
            if (*(int *)(iVar17 + 0x34 + iVar12) == 0) {
              iVar19 = param_2[6];
            }
            else {
              iVar14 = iVar14 * 0x54;
              local_d4 = 0;
              do {
                FUN_000543b0(iVar14 + iVar17);
                local_d4 = local_d4 + 1;
                iVar17 = param_2[8];
                iVar14 = iVar14 + 0x54;
              } while (local_d4 < *(uint *)(iVar17 + 0x34 + iVar12));
              iVar19 = param_2[6];
            }
          }
        }
LAB_0005e403:
        if (*(int *)(local_c0 + iVar19 + 0x3c) == 2) {
          iVar14 = *(int *)(local_c0 + iVar19 + 0x40);
          iVar12 = iVar14 * 0x54;
          iVar17 = param_2[8];
          iVar15 = iVar12 + iVar17;
          if ((*(int *)(iVar15 + 0x28) == 0x87c3) && (*(char *)(iVar15 + 0x3d) == '\0')) {
            if (*(int *)(iVar15 + 0x30) == 0) {
              if (*(uint *)(iVar15 + 0x34) < 2) {
                FUN_000543b0(iVar15);
                iVar19 = param_2[6];
                goto LAB_0005e418;
              }
            }
            else {
              iVar14 = FUN_0005369a(piVar10,*(int *)(iVar15 + 0x30));
              iVar12 = iVar14 * 0x54;
              iVar17 = param_2[8];
            }
            if (*(int *)(iVar17 + 0x34 + iVar12) == 0) {
              iVar19 = param_2[6];
            }
            else {
              iVar14 = iVar14 * 0x54;
              local_d0 = 0;
              do {
                FUN_000543b0(iVar14 + iVar17);
                local_d0 = local_d0 + 1;
                iVar17 = param_2[8];
                iVar14 = iVar14 + 0x54;
              } while (local_d0 < *(uint *)(iVar17 + 0x34 + iVar12));
              iVar19 = param_2[6];
            }
          }
        }
LAB_0005e418:
        if (*(int *)(local_c0 + iVar19 + 0x58) == 2) {
          iVar12 = *(int *)(local_c0 + iVar19 + 0x5c);
          iVar15 = iVar12 * 0x54;
          iVar14 = param_2[8];
          iVar19 = iVar15 + iVar14;
          if ((*(int *)(iVar19 + 0x28) == 0x87c3) && (*(char *)(iVar19 + 0x3d) == '\0')) {
            if (*(int *)(iVar19 + 0x30) == 0) {
              if (*(uint *)(iVar19 + 0x34) < 2) {
                FUN_000543b0(iVar19);
                goto LAB_0005e42d;
              }
            }
            else {
              iVar12 = FUN_0005369a(piVar10,*(int *)(iVar19 + 0x30));
              iVar15 = iVar12 * 0x54;
              iVar14 = param_2[8];
            }
            if (*(int *)(iVar14 + 0x34 + iVar15) != 0) {
              iVar12 = iVar12 * 0x54;
              local_cc = 0;
              do {
                FUN_000543b0(iVar12 + iVar14);
                local_cc = local_cc + 1;
                iVar14 = param_2[8];
                iVar12 = iVar12 + 0x54;
              } while (local_cc < *(uint *)(iVar14 + 0x34 + iVar15));
            }
          }
        }
LAB_0005e42d:
        local_a8 = local_a8 + 1;
        local_c0 = local_c0 + 0x74;
      } while (local_a8 < (uint)param_2[5]);
    }
  }
  if ((*(char *)((int)param_2 + 0x7a) != '\0') && (*(char *)(param_1 + 0x44) < '\0')) {
    *(int *)(iVar3 + 0x60) = *(int *)(iVar3 + 0x5c);
    uVar20 = *(int *)(iVar3 + 0x5c) + 1;
    *(uint *)(iVar3 + 0x5c) = uVar20;
    if (*(uint *)(iVar3 + 0x58) < uVar20) {
      *(undefined1 *)(param_2 + 4) = 0;
      uVar11 = (**(code **)(param_1 + 0x10))(*(int *)(iVar3 + 0x58) + 0x10,0x28);
      (**(code **)(param_1 + 0x1344))
                (uVar11,*(undefined4 *)(iVar3 + 0x54),*(int *)(iVar3 + 0x58) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x54));
      *(undefined4 *)(iVar3 + 0x54) = uVar11;
      *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 0x10;
    }
  }
  *(undefined4 *)(iVar3 + 0x18) = 0;
  if (param_2[5] == 0) {
    local_f4 = 0;
  }
  else {
    local_a4 = 0;
    local_f4 = 0;
    iVar19 = 0;
    do {
      if (0x20 < *(int *)(iVar19 + param_2[6]) - 0x8782U) {
        param_2[0xc] = 0;
        param_2[0x15] = 0;
        param_2[0x16] = 0;
        param_2[0x17] = 0;
        param_2[0x18] = 0;
        param_2[0x19] = 0;
        return 0;
      }
      FUN_00054960((int *)(iVar19 + param_2[6]) + 1);
      FUN_00054960(iVar19 + param_2[6] + 0x20);
      FUN_00054960(iVar19 + param_2[6] + 0x3c);
      FUN_00054960(iVar19 + param_2[6] + 0x58);
      uVar20 = param_2[0x19];
      if ((uint)param_2[0x19] <= local_f4) {
        uVar20 = local_f4;
      }
      iVar12 = *(int *)(iVar19 + param_2[6]) + -0x8782;
      iVar15 = (*(code *)(PTR_FUN_001ee5c0)[iVar12])(param_1,param_2,(int *)(iVar19 + param_2[6]));
      if (iVar15 < 0) {
        param_2[0xc] = 0;
        param_2[0x15] = 0;
        param_2[0x16] = 0;
        param_2[0x17] = 0;
        param_2[0x18] = 0;
        param_2[0x19] = 0;
        return 0;
      }
      *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + iVar15;
      bVar8 = *(byte *)(param_1 + 0x46);
      if ((((bVar8 & 0x10) != 0) &&
          (pvVar16 = (void *)(iVar19 + param_2[6]), *(int *)((int)pvVar16 + 4) == 1)) &&
         (*(int *)((int)pvVar16 + 8) == 0x87bd)) {
        bVar8 = *(byte *)(param_1 + 0x11d1);
        _memcpy(local_90,pvVar16,0x74);
        local_88 = bVar8 + 0x879d;
        local_84 = 1;
        local_80 = 0;
        local_7c = 0;
        local_78 = 0;
        iVar15 = (*(code *)(PTR_FUN_001ee5c0)[iVar12])(param_1,param_2,local_90);
        *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + iVar15;
        local_90[0] = 0x8799;
        local_84 = 0;
        local_80 = 1;
        local_7c = 1;
        local_78 = 1;
        local_68 = 0x87dd;
        local_64 = 0x87dd;
        local_60 = 0x87dd;
        local_5c = 0x87de;
        iVar15 = (*(code *)PTR_FUN_001ee61c)(param_1,param_2,local_90);
        *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + iVar15;
        bVar8 = *(byte *)(param_1 + 0x46);
      }
      if ((((bVar8 & 0x20) != 0) &&
          (pvVar16 = (void *)(iVar19 + param_2[6]), *(int *)((int)pvVar16 + 4) == 1)) &&
         (*(int *)((int)pvVar16 + 8) == 0x879a)) {
        _memcpy(local_90,pvVar16,0x74);
        local_88 = *(byte *)(param_1 + 0x11d2) + 0x879d;
        iVar15 = (*(code *)(PTR_FUN_001ee5c0)[iVar12])(param_1,param_2,local_90);
        *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + iVar15;
      }
      if (*(char *)((int)param_2 + 0x7b) == '\0') {
        FUN_00054ec0();
      }
      if (((*(char *)((int)param_2 + 0x7a) != '\0') && (*(char *)(param_1 + 0x44) < '\0')) &&
         ((*(int *)(iVar19 + param_2[6] + 4) == 1 && (*(int *)(iVar19 + param_2[6] + 8) == 0x87bd)))
         ) {
        iVar15 = *(int *)(iVar3 + 0x18);
        iVar12 = ((int (*)())FUN_0005c04f)();
        *(int *)(iVar3 + 0x18) = iVar15 + iVar12;
      }
      local_a4 = local_a4 + 1;
      iVar19 = iVar19 + 0x74;
      local_f4 = uVar20;
    } while (local_a4 < (uint)param_2[5]);
  }
  param_2[0x15] = *(int *)(iVar3 + 0x18);
  param_2[0x19] = local_f4;
  if (param_2[5] != 0) {
    uVar20 = 0;
    iVar19 = 0;
    puVar13 = puVar9;
    do {
      iVar15 = param_2[6];
      *(undefined4 *)(iVar15 + 0xc + iVar19) = *puVar13;
      *(undefined4 *)(iVar15 + 0x10 + iVar19) = puVar13[1];
      *(undefined4 *)(iVar15 + 0x14 + iVar19) = puVar13[2];
      *(undefined4 *)(iVar15 + 0x18 + iVar19) = puVar13[3];
      uVar20 = uVar20 + 1;
      iVar19 = iVar19 + 0x74;
      puVar13 = puVar13 + 4;
    } while (uVar20 < (uint)param_2[5]);
  }
  (**(code **)(param_1 + 0x18))(puVar9);
  iVar19 = *(int *)(iVar3 + 0x18);
  *(undefined4 *)(iVar3 + 8) = 0;
  if (iVar19 != 0) {
    do {
      iVar15 = *(int *)(iVar3 + 0x1c) + iVar19 * 0x10;
      if (((byte)((*(byte *)(iVar15 + -0xf) & 0xf) - 2) < 2) &&
         ((*(uint *)(iVar15 + -0x10) & 0xfe000) == 0)) {
        *(int *)(iVar3 + 8) = iVar19 + -1;
      }
      iVar19 = iVar19 + -1;
    } while ((iVar19 != 0) && (*(int *)(iVar3 + 8) == 0));
  }
  if (*(int *)(iVar3 + 0x224) != 0) {
    uVar11 = (**(code **)(param_1 + 0xc))(*(int *)(iVar3 + 0x224) << 2);
    *(undefined4 *)(iVar3 + 0x220) = uVar11;
    if (param_2[7] != 0) {
      uVar20 = 0;
      iVar15 = 0;
      iVar19 = 0;
      do {
        iVar12 = iVar19 + param_2[8];
        if (((*(char *)(iVar12 + 0x3d) != '\0') && (*(int *)(iVar12 + 0x28) == 0x87c2)) &&
           (*(char *)(iVar12 + 0x44) == '\0')) {
          *(uint *)(*(int *)(iVar3 + 0x220) + iVar15 * 4) = uVar20;
          iVar15 = iVar15 + 1;
        }
        uVar20 = uVar20 + 1;
        iVar19 = iVar19 + 0x54;
      } while (uVar20 < (uint)param_2[7]);
    }
  }
  if (*(int *)(iVar3 + 0x22c) != 0) {
    uVar11 = (**(code **)(param_1 + 0xc))(*(int *)(iVar3 + 0x22c) << 2);
    *(undefined4 *)(iVar3 + 0x228) = uVar11;
    if (param_2[7] != 0) {
      uVar20 = 0;
      iVar15 = 0;
      iVar19 = 0;
      do {
        iVar12 = iVar19 + param_2[8];
        if (((*(char *)(iVar12 + 0x3d) != '\0') && (*(int *)(iVar12 + 0x28) == 0x87c2)) &&
           (*(char *)(iVar12 + 0x44) != '\0')) {
          *(uint *)(*(int *)(iVar3 + 0x228) + iVar15 * 4) = uVar20;
          iVar15 = iVar15 + 1;
          *(uint *)(iVar3 + 0x230) = *(uint *)(iVar3 + 0x230) | *(uint *)(iVar12 + 0x50);
        }
        uVar20 = uVar20 + 1;
        iVar19 = iVar19 + 0x54;
      } while (uVar20 < (uint)param_2[7]);
    }
  }
  uVar20 = *(uint *)(iVar3 + 0x5c);
  if (uVar20 != 0) {
    if ((uint)piVar2[0x23] < uVar20) {
      iVar19 = (**(code **)(param_1 + 0x14))(piVar2[0x22],uVar20 << 4);
      piVar2[0x22] = iVar19;
      piVar2[0x23] = *(int *)(iVar3 + 0x5c);
    }
    if ((param_2[0x18] != 0) && (param_2[7] != 0)) {
      local_a0 = 0;
      iVar19 = 0;
      do {
        iVar15 = iVar19 + param_2[8];
        if ((*(char *)(iVar15 + 0x3d) != '\0') && (*(int *)(iVar15 + 0x28) == 0x87c3)) {
          iVar12 = piVar2[0x22];
          iVar14 = *(int *)(iVar15 + 4) * 0x10;
          puVar9 = *(undefined4 **)(iVar15 + 0x38);
          *(undefined4 *)(iVar14 + iVar12) = *puVar9;
          *(undefined4 *)(iVar14 + 4 + iVar12) = puVar9[1];
          *(undefined4 *)(iVar14 + 8 + iVar12) = puVar9[2];
          *(undefined4 *)(iVar14 + 0xc + iVar12) = puVar9[3];
        }
        local_a0 = local_a0 + 1;
        iVar19 = iVar19 + 0x54;
      } while (local_a0 < (uint)param_2[7]);
    }
  }
  ((int (*)())FUN_00060ae5)(param_1,param_2);
  ((int (*)())FUN_00060aa0)(param_1,param_2);
  *(undefined1 *)(param_2[1] + *(int *)(param_1 + 0x118c)) = 0;
  if (*(int *)(iVar3 + 0x2b8) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(iVar3 + 0x2b8));
    *(undefined4 *)(iVar3 + 0x2b8) = 0;
  }
  return (char)param_2[4];
}

/* FUN_00060018 @ 0x60018 (176 bytes) */
int FUN_00060018(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x18);
  if ((iVar2 != 0) && (*(int *)(param_2 + 0x1c) != 0)) {
    puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar2 * 4 + 3);
    *(undefined4 **)(param_1 + 0x274c) = puVar1;
    *puVar1 = 0x880;
    *(undefined4 *)(*(int *)(param_1 + 0x274c) + 4) = *(undefined4 *)(param_2 + 4);
    *(uint *)(*(int *)(param_1 + 0x274c) + 8) = (iVar2 * 4 + -1) * 0x10000 | 0x8882;
    _memcpy((void *)(*(int *)(param_1 + 0x274c) + 0xc),*(void **)(param_2 + 0x1c),iVar2 * 0x10);
    iVar2 = iVar2 * 0x10 + *(int *)(param_1 + 0x274c) + 0xc;
    *(int *)(param_1 + 0x274c) = iVar2;
    (**(code **)(param_1 + 0x275c))(param_1,iVar2);
  }
  return;
}

/* FUN_000600c8 @ 0x600c8 (604 bytes) */
int FUN_000600c8(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  void *param_4;
  int param_5;
{
  int iVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  code *UNRECOVERED_JUMPTABLE;
  size_t sVar5;
  
  if (*(int *)(param_3 + 0x5c) == 0) {
    return;
  }
  if ((*(char *)(param_2 + 0x7a) == '\0') || (-1 < *(char *)(param_1 + 0x44))) {
    if (param_5 == '\0') {
      return;
    }
  }
  else {
    iVar1 = *(int *)(param_3 + 0x60);
    iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    sVar2 = *(short *)(iVar3 + 0x2e04);
    if (sVar2 == 0x801) {
      *(undefined4 *)((int)param_4 + iVar1 * 0x10 + 4) = 0;
      *(uint *)((int)param_4 + iVar1 * 0x10 + 8) =
           (uint)(*(float *)(iVar3 + 0x2df0) * *(float *)(iVar3 + 0x2df0)) ^ _DAT_001c6210;
    }
    else if (sVar2 == 0x2601) {
      *(float *)((int)param_4 + iVar1 * 0x10 + 4) =
           *(float *)(iVar3 + 0x2df8) * *(float *)(iVar3 + 0x2dfc);
      *(uint *)((int)param_4 + iVar1 * 0x10 + 8) = *(uint *)(iVar3 + 0x2dfc) ^ 0x80000000;
    }
    else if (sVar2 == 0x800) {
      *(undefined4 *)((int)param_4 + iVar1 * 0x10 + 4) = 0;
      *(uint *)((int)param_4 + iVar1 * 0x10 + 8) = *(uint *)(iVar3 + 0x2df0) ^ 0x80000000;
    }
    if (param_5 == '\0') {
      puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,7);
      *(undefined4 **)(param_1 + 0x274c) = puVar4;
      *puVar4 = 0x880;
      *(int *)(*(int *)(param_1 + 0x274c) + 4) =
           iVar1 + *(int *)(param_1 + 0x2448) + *(int *)(param_3 + 0x14);
      *(undefined4 *)(*(int *)(param_1 + 0x274c) + 8) = 0x38882;
      puVar4 = (undefined4 *)((int)param_4 + iVar1 * 0x10);
      *(undefined4 *)(*(int *)(param_1 + 0x274c) + 0xc) = *puVar4;
      *(undefined4 *)(*(int *)(param_1 + 0x274c) + 0x10) = puVar4[1];
      *(undefined4 *)(*(int *)(param_1 + 0x274c) + 0x14) = puVar4[2];
      *(undefined4 *)(*(int *)(param_1 + 0x274c) + 0x18) = puVar4[3];
      *(int *)(param_1 + 0x274c) = *(int *)(param_1 + 0x274c) + 0x1c;
      UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
      goto LAB_0006019e;
    }
  }
  iVar3 = *(int *)(param_3 + 0x5c);
  iVar1 = iVar3 * 4;
  puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar1 + 3);
  *(undefined4 **)(param_1 + 0x274c) = puVar4;
  *puVar4 = 0x880;
  *(int *)(*(int *)(param_1 + 0x274c) + 4) = *(int *)(param_1 + 0x2448) + *(int *)(param_3 + 0x14);
  *(uint *)(*(int *)(param_1 + 0x274c) + 8) = (iVar1 + -1) * 0x10000 | 0x8882;
  sVar5 = iVar3 * 0x10;
  _memcpy((void *)(*(int *)(param_1 + 0x274c) + 0xc),param_4,sVar5);
  *(size_t *)(param_1 + 0x274c) = sVar5 + *(int *)(param_1 + 0x274c) + 0xc;
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
LAB_0006019e:
                    
                    
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

/* FUN_00060324 @ 0x60324 (236 bytes) */
int FUN_00060324(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  short sVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = (uint)*(byte *)(param_3 + 0x43) & *(byte *)(param_1 + 0x47) & 1 |
          ((uint)*(byte *)(param_3 + 0x44) & *(byte *)(param_1 + 0x47) >> 1 & 1) * 2 |
          (uint)(*(int *)(param_1 + 0x148) == 1) << 2;
  if (*(char *)(param_2 + 0x7a) != '\0') {
    if (*(char *)(param_2 + 0x6e) == '\0') {
      bVar2 = *(byte *)(param_1 + 0x46);
    }
    else {
      bVar2 = *(byte *)(param_1 + 0x46);
      uVar3 = uVar3 | (bVar2 >> 3 & 1) << 3;
    }
    if (*(char *)(param_1 + 0x44) < '\0') {
      sVar1 = *(short *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x2e04);
      if (sVar1 == 0x801) {
        uVar3 = uVar3 | 0x30;
      }
      else if (sVar1 == 0x2601) {
        uVar3 = uVar3 | 0x10;
      }
      else if (sVar1 == 0x800) {
        uVar3 = uVar3 | 0x20;
      }
    }
    if ((bVar2 & 0x10) != 0) {
      uVar3 = uVar3 | (uint)*(byte *)(param_1 + 0x11d1) << 0xf | 0x4000;
    }
  }
  if ((*(char *)(param_2 + 0x6c) != '\0') && ((*(byte *)(param_1 + 0x46) & 0x20) != 0)) {
    uVar3 = uVar3 | (uint)*(byte *)(param_1 + 0x11d2) << 0x18 | 0x800000;
  }
  return uVar3;
}

/* FUN_00060410 @ 0x60410 (137 bytes) */
int FUN_00060410(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(param_2 + 0x1c) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x1c));
  }
  if (*(int *)(param_2 + 0x24) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x24));
  }
  if (*(int *)(param_2 + 0x4c) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x4c));
  }
  if (*(int *)(param_2 + 0x54) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x54));
  }
  if (*(int *)(param_2 + 0x220) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x220));
  }
  if (*(int *)(param_2 + 0x228) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x228));
  }
  if (*(int *)(param_2 + 0x2b8) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x2b8));
  }
  (**(code **)(param_1 + 0x18))(param_2);
  FUN_0007959e(param_1,param_2);
  return;
}

/* FUN_00060499 @ 0x60499 (52 bytes) */
int FUN_00060499(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = 0;
  do {
    *(byte *)(param_1 + 0x18ac + iVar1 * 8) =
         *(byte *)(param_1 + 0x18ac + iVar1 * 8) & 0xfe | *(char *)(param_2 + 0x71) != '\0';
    iVar1 = iVar1 + 1;
    param_2 = param_2 + 1;
  } while (iVar1 != 0x10);
  return;
}

/* FUN_000604cd @ 0x604cd (82 bytes) */
int FUN_000604cd(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  byte *pbVar1;
  int iVar2;
  
  if (param_3 == '\0') {
    iVar2 = 0;
    do {
      *(byte *)(param_1 + 0x18ac + iVar2 * 8) =
           *(byte *)(param_1 + 0x18ac + iVar2 * 8) & 0xfe | *(char *)(param_2 + 0x71) != '\0';
      iVar2 = iVar2 + 1;
      param_2 = param_2 + 1;
    } while (iVar2 != 0x10);
    return;
  }
  iVar2 = 0;
  do {
    pbVar1 = (byte *)(param_1 + 0x18ac + iVar2 * 8);
    *pbVar1 = *pbVar1 & 0xfe;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x10);
  return;
}

/* FUN_0006051f @ 0x6051f (48 bytes) */
int FUN_0006051f(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x11b8) = 0x100;
  *(undefined4 *)(param_1 + 0x11bc) = 0x10;
  *(undefined4 *)(param_1 + 0x11c0) = 0x100;
  *(undefined4 *)(param_1 + 0x11c4) = 0x100;
  *(undefined4 *)(param_1 + 0x11c8) = 0x20;
  return;
}

/* FUN_0006054f @ 0x6054f (94 bytes) */
int FUN_0006054f(param_1)
  int param_1;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0xc))(0xc);
  *puVar1 = 0;
  puVar1[1] = *(undefined4 *)(param_1 + 0x2448);
  puVar1[2] = 0;
  *(undefined4 **)(param_1 + 0x11b4) = puVar1;
  *(undefined4 *)(param_1 + 0x11b8) = 0x100;
  *(undefined4 *)(param_1 + 0x11bc) = 0x10;
  *(undefined4 *)(param_1 + 0x11c0) = 0x100;
  *(undefined4 *)(param_1 + 0x11c4) = 0x100;
  *(undefined4 *)(param_1 + 0x11c8) = 0x20;
  return;
}

/* FUN_000605ad @ 0x605ad (66 bytes) */
int FUN_000605ad(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_1 + 0x11b4);
  puVar3 = *(undefined4 **)(iVar1 + 8);
  while (puVar3 != (undefined4 *)0x0) {
    *(undefined1 *)*puVar3 = 0;
    puVar2 = (undefined4 *)puVar3[1];
    (**(code **)(param_1 + 0x18))(puVar3);
    puVar3 = puVar2;
  }
  *(undefined4 *)(iVar1 + 8) = 0;
  return;
}

/* FUN_000605ef @ 0x605ef (55 bytes) */
int FUN_000605ef(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x11b4) != 0) {
    ((int (*)())FUN_000605ad)(param_1);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_1 + 0x11b4));
    *(undefined4 *)(param_1 + 0x11b4) = 0;
  }
  return;
}

/* FUN_00060626 @ 0x60626 (606 bytes) */
int FUN_00060626(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint param_3;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint local_18;
  uint local_14;
  int local_10;
  
  if (param_3 == 0xffffffff) {
    local_14 = *(uint *)(*(int *)(param_1 + 0x116c) + 0x10);
    local_18 = 0;
  }
  else {
    local_14 = param_3 + 1;
    local_18 = param_3;
  }
  local_10 = local_18 << 2;
  do {
    puVar1 = (undefined1 *)(**(code **)(param_1 + 0xc))(700);
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 4) = 0;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
    *(undefined4 *)(puVar1 + 0x10) = 0;
    *(undefined4 *)(puVar1 + 0x14) = 0;
    *(undefined4 *)(puVar1 + 0x18) = 0;
    uVar2 = (**(code **)(param_1 + 0xc))(0x1000);
    *(undefined4 *)(puVar1 + 0x1c) = uVar2;
    *(undefined4 *)(puVar1 + 0x20) = 0x100;
    iVar3 = (**(code **)(param_1 + 0x10))(0x16,0x28);
    *(int *)(puVar1 + 0x24) = iVar3;
    *(undefined4 *)(puVar1 + 0x28) = 0x16;
    *(undefined1 *)(iVar3 + 0x10) = 1;
    puVar1[0x2c] = 0;
    puVar1[0x2d] = 0;
    iVar3 = 8;
    puVar4 = puVar1;
    do {
      puVar4[0x2e] = 0;
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = 8;
    puVar4 = puVar1;
    do {
      puVar4[0x36] = 0;
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    puVar1[0x3e] = 0;
    puVar1[0x3f] = 0;
    puVar1[0x40] = 0;
    puVar1[0x41] = 0;
    *(undefined1 *)(param_2 + 0x1b) = 0;
    iVar3 = 4;
    piVar5 = param_2;
    do {
      *(undefined1 *)((int)piVar5 + 0x6d) = 0;
      piVar5 = (int *)((int)piVar5 + 1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = 0;
    piVar5 = param_2;
    do {
      *(undefined1 *)((int)piVar5 + 0x71) = 0;
      iVar3 = iVar3 + 1;
      piVar5 = (int *)((int)piVar5 + 1);
    } while (iVar3 != 8);
    *(undefined1 *)((int)param_2 + 0x7a) = 0;
    *(undefined1 *)((int)param_2 + 0x79) = 0;
    puVar1[0x42] = 0;
    puVar1[0x43] = 0;
    puVar1[0x44] = 0;
    *(undefined4 *)(puVar1 + 0x48) = 0;
    uVar2 = (**(code **)(param_1 + 0x10))(0x20,0x28);
    *(undefined4 *)(puVar1 + 0x4c) = uVar2;
    *(undefined4 *)(puVar1 + 0x50) = 0x20;
    uVar2 = (**(code **)(param_1 + 0x10))(0x100,0x28);
    *(undefined4 *)(puVar1 + 0x54) = uVar2;
    *(undefined4 *)(puVar1 + 0x58) = 0x100;
    *(undefined4 *)(puVar1 + 0x5c) = 0;
    *(undefined4 *)(puVar1 + 0x74) = 0;
    *(undefined4 *)(puVar1 + 0x220) = 0;
    *(undefined4 *)(puVar1 + 0x224) = 0;
    *(undefined4 *)(puVar1 + 0x228) = 0;
    *(undefined4 *)(puVar1 + 0x22c) = 0;
    *(undefined4 *)(puVar1 + 0x230) = 0;
    *(undefined4 *)(puVar1 + 0x2a4) = 0;
    *(undefined4 *)(puVar1 + 0x2a8) = 0;
    *(undefined4 *)(puVar1 + 0x2ac) = 0;
    puVar1[0x2b0] = 0;
    *(undefined4 *)(puVar1 + 0x2b4) = 0;
    puVar6 = *(undefined4 **)(*param_2 + local_10);
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)(**(code **)(param_1 + 0xc))(0x90);
      iVar3 = 0x20;
      puVar7 = puVar6;
      do {
        puVar7[1] = 0;
        puVar7 = puVar7 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      puVar6[0x21] = 0;
      puVar6[0x22] = 0;
      puVar6[0x23] = 0;
      *(undefined4 **)(*param_2 + local_10) = puVar6;
    }
    *puVar6 = puVar1;
    local_18 = local_18 + 1;
    local_10 = local_10 + 4;
  } while (local_18 < local_14);
  return;
}

/* FUN_00060884 @ 0x60884 (296 bytes) */
int FUN_00060884(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  
  if (*param_2 != 0) {
    if (param_3 == '\0') {
      local_1c = *(uint *)(param_1 + 0x118c);
      local_18 = local_1c + 1;
    }
    else {
      local_18 = *(uint *)(*(int *)(param_1 + 0x116c) + 0x10);
      local_1c = 0;
    }
    if (local_1c < local_18) {
      local_10 = local_1c << 2;
      local_14 = 0;
      do {
        piVar2 = *(int **)(*param_2 + local_10);
        if (piVar2 != (int *)0x0) {
          if (*(char *)(*piVar2 + 0x2b0) == '\0') {
            ((int (*)())FUN_00060410)();
            *piVar2 = 0;
          }
          if (param_3 != '\0') {
            iVar5 = 0x20;
            piVar4 = piVar2;
            do {
              piVar1 = piVar4 + 1;
              iVar3 = piVar4[1];
              while (iVar3 != 0) {
                *piVar1 = *(int *)(iVar3 + 0x2b4);
                ((int (*)())FUN_00060410)();
                iVar3 = *piVar1;
              }
              iVar5 = iVar5 + -1;
              piVar4 = piVar1;
            } while (iVar5 != 0);
            if (piVar2[0x22] != 0) {
              (**(code **)(param_1 + 0x18))(piVar2[0x22]);
            }
            (**(code **)(param_1 + 0x18))(piVar2);
            *(undefined4 *)(*param_2 + local_10) = 0;
          }
        }
        local_14 = local_14 + 1;
        local_10 = local_10 + 4;
      } while (local_14 != local_18 - local_1c);
    }
  }
  return;
}

/* FUN_000609ac @ 0x609ac (239 bytes) */
int FUN_000609ac(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  piVar1 = *(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar2 = *piVar1;
  puVar3 = *(undefined4 **)(param_3 + 0x38);
  iVar4 = piVar1[0x22];
  iVar6 = *(int *)(param_3 + 4) * 0x10;
  *(undefined4 *)(iVar6 + iVar4) = *puVar3;
  *(undefined4 *)(iVar6 + 4 + iVar4) = puVar3[1];
  *(undefined4 *)(iVar6 + 8 + iVar4) = puVar3[2];
  *(undefined4 *)(iVar6 + 0xc + iVar4) = puVar3[3];
  puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,9);
  *(undefined4 **)(param_1 + 0x274c) = puVar5;
  *puVar5 = 0x8a1;
  *(undefined4 *)(*(int *)(param_1 + 0x274c) + 4) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x274c) + 8) = 0x880;
  *(int *)(*(int *)(param_1 + 0x274c) + 0xc) =
       *(int *)(param_1 + 0x2448) + *(int *)(iVar2 + 0x14) + *(int *)(param_3 + 4);
  *(undefined4 *)(*(int *)(param_1 + 0x274c) + 0x10) = 0x38882;
  iVar2 = *(int *)(param_1 + 0x274c);
  *(undefined4 *)(iVar2 + 0x14) = *puVar3;
  *(undefined4 *)(iVar2 + 0x18) = puVar3[1];
  *(undefined4 *)(iVar2 + 0x1c) = puVar3[2];
  *(undefined4 *)(iVar2 + 0x20) = puVar3[3];
  *(int *)(param_1 + 0x274c) = *(int *)(param_1 + 0x274c) + 0x24;
                    
                    
  (**(code **)(param_1 + 0x275c))();
  return;
}

/* FUN_00060aa0 @ 0x60aa0 (69 bytes) */
int FUN_00060aa0(param_1, param_2)
  int param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  piVar1 = *(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar2 = *piVar1;
  uVar3 = ((int (*)())FUN_00060324)();
  *(uint *)(iVar2 + 0x48) = uVar3;
  *(int *)(iVar2 + 0x2b4) = piVar1[(uVar3 & 0x1f) + 1];
  piVar1[(uVar3 & 0x1f) + 1] = iVar2;
  *(undefined1 *)(iVar2 + 0x2b0) = 1;
  piVar1[0x21] = piVar1[0x21] + 1;
  return;
}

/* FUN_00060ae5 @ 0x60ae5 (5398 bytes) */
int FUN_00060ae5(param_1, param_2)
  int param_1;
  int *param_2;
{
  byte *pbVar1;
  short sVar2;
  int iVar3;
  bool bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  bool bVar10;
  
  iVar3 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  *(undefined4 *)(iVar3 + 0x238) = 0;
  bVar5 = *(byte *)(iVar3 + 0x238) & 0x80;
  bVar8 = bVar5 | 4;
  *(byte *)(iVar3 + 0x238) = bVar8;
  *(undefined4 *)(iVar3 + 0x23c) = 1;
  *(undefined4 *)(iVar3 + 0x240) = 0;
  *(undefined4 *)(iVar3 + 0x29c) = 0;
  *(undefined1 *)(iVar3 + 0x244) = 3;
  *(undefined1 *)(iVar3 + 0x245) = 0;
  *(byte *)(iVar3 + 0x270) = *(byte *)(iVar3 + 0x270) & 0xc0 | 8;
  *(ushort *)(iVar3 + 0x270) = *(ushort *)(iVar3 + 0x270) & 0xfe3f | 0x80;
  *(byte *)(iVar3 + 0x271) = *(byte *)(iVar3 + 0x271) & 0xf1 | 0xf6;
  *(undefined4 *)(iVar3 + 0x2a0) = 1;
  *(undefined4 *)(iVar3 + 0x2a8) = 1;
  iVar7 = *(int *)(iVar3 + 0x24);
  bVar10 = *(char *)(iVar7 + 0x38) != '\0';
  if (bVar10) {
    *(byte *)(iVar3 + 0x238) = bVar5 | bVar8 + 4 & 0x7f;
    *(undefined1 *)(iVar3 + 0x246) = 3;
    *(undefined1 *)(iVar3 + 0x247) = 1;
    *(byte *)(iVar3 + 0x272) = *(byte *)(iVar3 + 0x272) & 0xc0 | 8;
    *(ushort *)(iVar3 + 0x272) = *(ushort *)(iVar3 + 0x272) & 0xfe3f | 0x80;
    *(byte *)(iVar3 + 0x273) = *(byte *)(iVar3 + 0x273) & 0xf1 | 0xf6;
    *(undefined4 *)(iVar3 + 0x2a0) = 2;
  }
  bVar4 = !bVar10;
  uVar9 = (uint)bVar10;
  if (*(char *)(iVar7 + 0x60) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 2;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 2;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x88) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 3;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 3;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0xb0) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 4;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 4;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0xd8) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 5;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 5;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x100) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 6;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 6;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x128) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 7;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 7;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x150) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 8;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 8;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x178) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 9;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 9;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x1a0) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 10;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 10;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x1c8) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 0xb;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 0xb;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x1f0) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 0xc;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 0xc;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x218) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 0xd;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 0xd;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x240) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 0xe;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 0xe;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x268) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 0xf;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 0xf;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x290) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 0x10;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 0x10;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x2b8) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 0x11;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 0x11;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x2e0) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 0x12;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 0x12;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x308) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 0x13;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 0x13;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x330) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 0x14;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 0x14;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
    iVar7 = *(int *)(iVar3 + 0x24);
  }
  if (*(char *)(iVar7 + 0x358) != '\0') {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    bVar4 = !bVar4;
    if (bVar4) {
      *(undefined1 *)(iVar3 + 0x244 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x245 + uVar9 * 4) = 0x15;
      *(byte *)(iVar3 + 0x270 + uVar9 * 4) = *(byte *)(iVar3 + 0x270 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x270 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x270 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x271 + uVar9 * 4) = *(byte *)(iVar3 + 0x271 + uVar9 * 4) & 0xf1 | 0xf6;
    }
    else {
      *(undefined1 *)(iVar3 + 0x246 + uVar9 * 4) = 3;
      *(undefined1 *)(iVar3 + 0x247 + uVar9 * 4) = 0x15;
      *(byte *)(iVar3 + 0x272 + uVar9 * 4) = *(byte *)(iVar3 + 0x272 + uVar9 * 4) & 0xc0 | 8;
      *(ushort *)(iVar3 + 0x272 + uVar9 * 4) =
           *(ushort *)(iVar3 + 0x272 + uVar9 * 4) & 0xfe3f | 0x80;
      *(byte *)(iVar3 + 0x273 + uVar9 * 4) = *(byte *)(iVar3 + 0x273 + uVar9 * 4) & 0xf1 | 0xf6;
      uVar9 = uVar9 + 1;
    }
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
  }
  if (*(uint *)(iVar3 + 0x2a0) < 2) {
    *(byte *)(iVar3 + 0x238) = *(byte *)(iVar3 + 0x238) & 0x80 | *(byte *)(iVar3 + 0x238) + 4 & 0x7f
    ;
    *(uint *)(iVar3 + 0x234) = *(uint *)(iVar3 + 0x234) | 2;
    *(undefined1 *)(iVar3 + 0x246) = 3;
    *(undefined1 *)(iVar3 + 0x247) = 0x21;
    *(byte *)(iVar3 + 0x272) = *(byte *)(iVar3 + 0x272) & 0xc0 | 8;
    *(ushort *)(iVar3 + 0x272) = *(ushort *)(iVar3 + 0x272) & 0xfe3f | 0x80;
    *(byte *)(iVar3 + 0x273) = *(byte *)(iVar3 + 0x273) & 0xf1 | 0xf6;
    *(int *)(iVar3 + 0x2a0) = *(int *)(iVar3 + 0x2a0) + 1;
  }
  else {
    if (bVar4) {
      pbVar1 = (byte *)(iVar3 + 0x245 + uVar9 * 4);
      *pbVar1 = *pbVar1 | 0x20;
    }
    else {
      pbVar1 = (byte *)(iVar3 + 0x243 + uVar9 * 4);
      *pbVar1 = *pbVar1 | 0x20;
    }
    if (0x10 < *(uint *)(iVar3 + 0x2a0)) {
      *(undefined1 *)(param_2 + 4) = 0;
    }
  }
  if ((((param_2[0x1b] & 0xffffff00U) == 0) && ((char)param_2[0x1c] == '\0')) &&
     (*(char *)((int)param_2 + 0x7a) == '\0')) {
    sVar2 = *(short *)((int)param_2 + 0x6e);
  }
  else {
    *(byte *)(iVar3 + 0x23c) = *(byte *)(iVar3 + 0x23c) | 2;
    *(int *)(iVar3 + 0x2a8) = *(int *)(iVar3 + 0x2a8) + 1;
    sVar2 = *(short *)((int)param_2 + 0x6e);
  }
  if (((sVar2 != 0) || ((char)param_2[0x1c] != '\0')) || (*(char *)((int)param_2 + 0x7a) != '\0')) {
    *(byte *)(iVar3 + 0x23c) = *(byte *)(iVar3 + 0x23c) | 4;
    *(int *)(iVar3 + 0x2a8) = *(int *)(iVar3 + 0x2a8) + 1;
  }
  if ((*(char *)((int)param_2 + 0x6f) != '\0') || ((char)param_2[0x1c] != '\0')) {
    *(byte *)(iVar3 + 0x23c) = *(byte *)(iVar3 + 0x23c) | 0x18;
    *(int *)(iVar3 + 0x2a8) = *(int *)(iVar3 + 0x2a8) + 2;
  }
  if (*(char *)((int)param_2 + 0x79) != '\0') {
    *(byte *)(iVar3 + 0x23e) = *(byte *)(iVar3 + 0x23e) | 1;
    *(int *)(iVar3 + 0x2a8) = *(int *)(iVar3 + 0x2a8) + 1;
  }
  iVar7 = 0;
  do {
    bVar5 = *(byte *)((int)param_2 + 0x71);
    if (bVar5 != 0) {
      if ((bVar5 & 8) == 0) {
        iVar6 = 3 - (uint)((bVar5 & 4) == 0);
      }
      else {
        iVar6 = 4;
      }
      uVar9 = iVar6 << ((byte)iVar7 & 0x1f);
      *(uint *)(iVar3 + 0x240) = *(uint *)(iVar3 + 0x240) | uVar9;
      *(uint *)(iVar3 + 0x29c) = *(uint *)(iVar3 + 0x29c) | uVar9;
      *(int *)(iVar3 + 0x2a8) = *(int *)(iVar3 + 0x2a8) + 1;
    }
    param_2 = (int *)((int)param_2 + 1);
    iVar7 = iVar7 + 3;
  } while (iVar7 != 0x18);
  if (*(int *)(iVar3 + 0x2a8) == 1) {
    *(byte *)(iVar3 + 0x242) = *(byte *)(iVar3 + 0x242) & 0x1f | 0x80;
    *(byte *)(iVar3 + 0x29e) = *(byte *)(iVar3 + 0x29e) & 0x1f | 0x80;
    *(undefined4 *)(iVar3 + 0x2a8) = 2;
  }
  return;
}

/* FUN_00061ffb @ 0x61ffb (209 bytes) */
int FUN_00061ffb(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = (param_3 + -1) * 0x10000;
  switch(param_2) {
  default:
    return 0;
  case 2:
    return uVar1 | 0x8c8;
  case 3:
    return uVar1 | 0x8cc;
  case 4:
    return uVar1 | 0x8d0;
  case 5:
    return uVar1 | 0x8d4;
  case 6:
    return uVar1 | 0x8d8;
  case 7:
    return uVar1 | 0x8dc;
  case 8:
    return uVar1 | 0x8e0;
  case 9:
    return uVar1 | 0x8e4;
  case 10:
    return uVar1 | 0x8e8;
  case 0xb:
    return uVar1 | 0x8ec;
  case 0xc:
    return uVar1 | 0x8f0;
  case 0xd:
    return uVar1 | 0x8f4;
  case 0xe:
    return uVar1 | 0x8f8;
  case 0xf:
    return uVar1 | 0x8fc;
  case 0x10:
    return (param_3 + -1) * 0x10000 | 0x900;
  case 0x11:
    return uVar1 | 0x904;
  case 0x13:
    return uVar1 | 0x90c;
  case 0x14:
    return uVar1 | 0x910;
  case 0x15:
    return uVar1 | 0x914;
  }
}

/* FUN_00062125 @ 0x62125 (1044 bytes) */
int FUN_00062125(param_1, param_2)
  int param_1;
  int *param_2;
{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  char cVar9;
  byte *pbVar10;
  int local_34;
  int local_2c;
  int local_28;
  undefined *local_24;
  
  iVar8 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar2 = *(int *)(iVar8 + 0x150);
  if (*(int *)(iVar8 + 0x1384) == 0) {
    uVar7 = (**(code **)(param_1 + 0xc))(0x7c);
    *(undefined4 *)(iVar8 + 0x1384) = uVar7;
  }
  puVar3 = *(uint **)(iVar8 + 0x1384);
  puVar3[1] = 0;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0x80 | 4;
  puVar3[2] = 1;
  puVar3[3] = 0;
  puVar3[4] = 0;
  *(undefined1 *)(puVar3 + 5) = 3;
  *(byte *)((int)puVar3 + 0x15) = *(byte *)(iVar2 + 0x55e8) & 0x1f;
  *(byte *)(puVar3 + 0x10) = (byte)puVar3[0x10] & 0xc0 | 8;
  *(ushort *)(puVar3 + 0x10) = (ushort)puVar3[0x10] & 0xfe3f | 0x80;
  bVar1 = *(byte *)((int)puVar3 + 0x41);
  *(byte *)((int)puVar3 + 0x41) = bVar1 & 0xf1 | 6;
  cVar9 = '\0';
  if (*(int *)(iVar2 + 0x55e8) != 0x16) {
    cVar9 = '\x0f';
  }
  *(byte *)((int)puVar3 + 0x41) = bVar1 & 1 | 6 | cVar9 << 4;
  puVar3[0x1b] = 1;
  puVar3[0x1d] = 1;
  *puVar3 = 1;
  local_34 = 0;
  bVar4 = true;
  local_2c = 1;
  local_24 = &DAT_001ee6e0;
  pbVar10 = (byte *)((int)puVar3 + 0x41);
  local_28 = iVar8;
  do {
    if (0 < *(int *)(local_28 + 100)) {
      iVar6 = *(int *)(local_28 + 0xbc);
      *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0x80 | (byte)puVar3[1] + 4 & 0x7f;
      if (bVar4) {
        pbVar10[-0x2b] = 3;
        pbVar10[-0x2a] = *(byte *)(iVar2 + 0x55e8 + iVar6 * 4) & 0x1f;
        pbVar10[1] = pbVar10[1] & 0xc0 | 8;
        *(ushort *)(pbVar10 + 1) = *(ushort *)(pbVar10 + 1) & 0xfe3f | 0x80;
        bVar1 = pbVar10[2];
        pbVar10[2] = bVar1 & 0xf1 | 6;
        cVar9 = '\0';
        if (*(int *)(iVar2 + 0x55e8 + iVar6 * 4) != 0x16) {
          cVar9 = '\x0f';
        }
        pbVar10[2] = bVar1 & 1 | 6 | cVar9 << 4;
        local_34 = local_34 + 1;
        pbVar10 = pbVar10 + 4;
        bVar4 = false;
        puVar3[0x1b] = puVar3[0x1b] + 1;
        *puVar3 = *puVar3 | *(uint *)(local_24 + 4);
        local_2c = local_2c + 1;
        if (local_2c == *(int *)(iVar8 + 0x110)) break;
      }
      else {
        pbVar10[-0x2d] = 3;
        pbVar10[-0x2c] = *(byte *)(iVar2 + 0x55e8 + iVar6 * 4) & 0x1f;
        pbVar10[-1] = pbVar10[-1] & 0xc0 | 8;
        *(ushort *)(pbVar10 + -1) = *(ushort *)(pbVar10 + -1) & 0xfe3f | 0x80;
        bVar1 = *pbVar10;
        *pbVar10 = bVar1 & 0xf1 | 6;
        cVar9 = '\0';
        if (*(int *)(iVar2 + 0x55e8 + iVar6 * 4) != 0x16) {
          cVar9 = '\x0f';
        }
        *pbVar10 = bVar1 & 1 | 6 | cVar9 << 4;
        bVar4 = true;
        puVar3[0x1b] = puVar3[0x1b] + 1;
        *puVar3 = *puVar3 | *(uint *)(local_24 + 4);
        local_2c = local_2c + 1;
        if (local_2c == *(int *)(iVar8 + 0x110)) break;
      }
    }
    local_28 = local_28 + 4;
    local_24 = local_24 + 4;
  } while (local_24 != &DAT_001ee734);
  if (puVar3[0x1b] < 2) {
    *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0x80 | (byte)puVar3[1] + 4 & 0x7f;
    *puVar3 = *puVar3 | 2;
    *(undefined1 *)((int)puVar3 + 0x16) = 3;
    *(undefined1 *)((int)puVar3 + 0x17) = 0x21;
    *(byte *)((int)puVar3 + 0x42) = *(byte *)((int)puVar3 + 0x42) & 0xc0 | 8;
    *(ushort *)((int)puVar3 + 0x42) = *(ushort *)((int)puVar3 + 0x42) & 0xfe3f | 0x80;
    *(byte *)((int)puVar3 + 0x43) = *(byte *)((int)puVar3 + 0x43) & 0xf1 | 0xf6;
    puVar3[0x1b] = puVar3[0x1b] + 1;
  }
  else {
    if (bVar4) {
      pbVar10 = (byte *)((int)puVar3 + local_34 * 4 + 0x15);
      *pbVar10 = *pbVar10 | 0x20;
    }
    else {
      pbVar10 = (byte *)((int)puVar3 + local_34 * 4 + 0x13);
      *pbVar10 = *pbVar10 | 0x20;
    }
    if (0x10 < puVar3[0x1b]) {
      *(undefined1 *)(param_2 + 4) = 0;
    }
  }
  if ((((param_2[0x1b] & 0xffffff00U) != 0) || ((char)param_2[0x1c] != '\0')) ||
     (*(char *)((int)&UINT_000013c8 + iVar8) != '\0')) {
    *(byte *)(puVar3 + 2) = (byte)puVar3[2] | 2;
    puVar3[0x1d] = puVar3[0x1d] + 1;
  }
  if (((*(short *)((int)param_2 + 0x6e) != 0) || ((char)param_2[0x1c] != '\0')) ||
     (*(char *)((int)&UINT_000013c8 + iVar8) != '\0')) {
    *(byte *)(puVar3 + 2) = (byte)puVar3[2] | 4;
    puVar3[0x1d] = puVar3[0x1d] + 1;
  }
  if ((*(char *)((int)param_2 + 0x6f) != '\0') || ((char)param_2[0x1c] != '\0')) {
    *(byte *)(puVar3 + 2) = (byte)puVar3[2] | 0x18;
    puVar3[0x1d] = puVar3[0x1d] + 2;
  }
  if (*(char *)((int)param_2 + 0x79) != '\0') {
    *(byte *)((int)puVar3 + 10) = *(byte *)((int)puVar3 + 10) | 1;
    puVar3[0x1d] = puVar3[0x1d] + 1;
  }
  iVar8 = 0;
  do {
    bVar1 = *(byte *)((int)param_2 + 0x71);
    if (bVar1 != 0) {
      if ((bVar1 & 8) == 0) {
        iVar6 = 3 - (uint)((bVar1 & 4) == 0);
      }
      else {
        iVar6 = 4;
      }
      uVar5 = iVar6 << ((byte)iVar8 & 0x1f);
      puVar3[3] = puVar3[3] | uVar5;
      puVar3[4] = puVar3[4] | uVar5;
      puVar3[0x1d] = puVar3[0x1d] + 1;
    }
    param_2 = (int *)((int)param_2 + 1);
    iVar8 = iVar8 + 3;
  } while (iVar8 != 0x18);
  puVar3[2] = *(uint *)(iVar2 + 0x5498);
  puVar3[3] = *(uint *)(iVar2 + 0x549c);
  uVar5 = *(uint *)(iVar2 + 0x5434);
  puVar3[0x1d] = uVar5;
  if (uVar5 == 1) {
    *(byte *)((int)puVar3 + 0xe) = *(byte *)((int)puVar3 + 0xe) & 0x1f | 0x80;
    *(byte *)((int)puVar3 + 0x12) = *(byte *)((int)puVar3 + 0x12) & 0x1f | 0x80;
    puVar3[0x1d] = 2;
  }
  return;
}

/* FUN_00062539 @ 0x62539 (280 bytes) */
int FUN_00062539(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_10;
  
  iVar1 = **(int **)(**(int **)(param_1 + 0x1168) + *(int *)(param_1 + 0x118c) * 4);
  if (((char)(*(int **)(param_1 + 0x1168))[4] != '\0') && ((*(byte *)(param_1 + 0x8c) & 2) == 0)) {
    *(undefined4 *)(param_1 + 0x1ca0) = *(undefined4 *)(iVar1 + 0x234);
    *(undefined4 *)(param_1 + 0x1ca4) = *(undefined4 *)(iVar1 + 0x238);
    *(undefined4 *)(param_1 + 0x1b9c) = *(undefined4 *)(iVar1 + 0x23c);
    *(undefined4 *)(param_1 + 0x1ba0) = *(undefined4 *)(iVar1 + 0x240);
    iVar4 = *(int *)(iVar1 + 0x2a0);
    if (iVar4 + 1U >> 1 != 0) {
      local_10 = 0;
      iVar2 = iVar1;
      iVar3 = param_1;
      do {
        *(undefined4 *)(iVar3 + 0x1be4) = *(undefined4 *)(iVar2 + 0x244);
        *(undefined4 *)(iVar3 + 0x1c04) = *(undefined4 *)(iVar2 + 0x270);
        local_10 = local_10 + 1;
        iVar4 = *(int *)(iVar1 + 0x2a0);
        iVar2 = iVar2 + 4;
        iVar3 = iVar3 + 4;
      } while (local_10 < iVar4 + 1U >> 1);
    }
    *(int *)(param_1 + 0x2438) = iVar4;
    *(undefined4 *)(param_1 + 0x243c) = *(undefined4 *)(iVar1 + 0x2a0);
    *(undefined4 *)(param_1 + 0x1b78) = 0;
    *(byte *)(param_1 + 0x1b78) = *(byte *)(param_1 + 0x1b78) & 0xfc | *(byte *)(iVar1 + 0x36) & 3;
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000;
    (**(code **)(param_1 + 0x1334))(param_1,1);
    *(undefined1 *)(param_1 + 0x2435) = 1;
  }
  return;
}

/* FUN_00062651 @ 0x62651 (433 bytes) */
int FUN_00062651(param_1)
  int param_1;
{
  int *piVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  piVar1 = *(int **)(param_1 + 0x1168);
  puVar2 = *(undefined4 **)(**(int **)(*piVar1 + *(int *)(param_1 + 0x118c) * 4) + 0x1384);
  if (((char)piVar1[4] != '\0') && ((*(byte *)(param_1 + 0x8c) & 2) == 0)) {
    if ((*(int *)(param_1 + 0x1b9c) == puVar2[2]) && (*(int *)(param_1 + 0x1ba0) == puVar2[3])) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    *(undefined4 *)(param_1 + 0x1ca0) = *puVar2;
    *(undefined4 *)(param_1 + 0x1ca4) = puVar2[1];
    *(undefined4 *)(param_1 + 0x1b9c) = puVar2[2];
    *(undefined4 *)(param_1 + 0x1ba0) = puVar2[3];
    iVar6 = puVar2[0x1b];
    if (iVar6 + 1U >> 1 != 0) {
      uVar7 = 0;
      puVar4 = puVar2;
      iVar5 = param_1;
      do {
        *(undefined4 *)(iVar5 + 0x1be4) = puVar4[5];
        *(undefined4 *)(iVar5 + 0x1c04) = puVar4[0x10];
        uVar7 = uVar7 + 1;
        iVar6 = puVar2[0x1b];
        puVar4 = puVar4 + 1;
        iVar5 = iVar5 + 4;
      } while (uVar7 < iVar6 + 1U >> 1);
    }
    *(int *)(param_1 + 0x2438) = iVar6;
    *(undefined4 *)(param_1 + 0x243c) = puVar2[0x1b];
    *(undefined4 *)(param_1 + 0x1b78) = 0;
    if ((*(byte *)(piVar1 + 0xc) & 1) != 0) {
      *(byte *)(param_1 + 0x1b78) = *(byte *)(param_1 + 0x1b78) & 0xfc | 1;
    }
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000;
    if (*(int *)(param_1 + 0x148c) != 0) {
      iVar6 = *(int *)(*(int *)(param_1 + 0x148c) + 0x14);
      if (((*(int *)(param_1 + 0x1b50) != *(int *)(iVar6 + 0x5658)) ||
          (iVar5 = *(int *)(param_1 + 0x1ba4), iVar5 != *(int *)(iVar6 + 0x5650))) || (bVar3)) {
        (**(code **)(param_1 + 0x1334))(param_1,1);
        *(undefined4 *)(iVar6 + 0x5650) = *(undefined4 *)(param_1 + 0x1ba4);
        *(undefined4 *)(iVar6 + 0x5658) = *(undefined4 *)(param_1 + 0x1b50);
        iVar5 = *(int *)(param_1 + 0x1ba4);
      }
      *(int *)(iVar6 + 0x5650) = iVar5;
      *(undefined4 *)(iVar6 + 0x5658) = *(undefined4 *)(param_1 + 0x1b50);
    }
    *(undefined1 *)(param_1 + 0x2435) = 1;
  }
  return;
}

/* FUN_00062802 @ 0x62802 (1400 bytes) */
int FUN_00062802(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  int *piVar12;
  char *pcVar13;
  uint uVar14;
  uint uVar15;
  undefined8 *puVar16;
  char cVar17;
  undefined4 *puVar18;
  int iVar19;
  undefined4 *puVar20;
  undefined8 *puVar21;
  int iVar22;
  undefined8 *puVar23;
  undefined8 *puVar24;
  undefined8 *puVar25;
  int *piVar26;
  int local_2c;
  uint local_28;
  uint local_24;
  
  if (*param_2 != 0) {
    piVar12 = *(int **)(param_1 + 0x11b4);
    puVar20 = *(undefined4 **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
    pcVar13 = (char *)*puVar20;
    uVar14 = *(uint *)(pcVar13 + 0x18);
    uVar15 = *(uint *)(pcVar13 + 0x5c);
    if (((char)param_2[4] != '\0') && ((*(byte *)(param_1 + 0x8c) & 2) == 0)) {
      if (*pcVar13 != '\0') {
LAB_0006298a:
        if (*(int *)(pcVar13 + 0x5c) != 0) {
          if (*(int *)(pcVar13 + 0x2b8) == 0) {
            iVar19 = puVar20[0x22];
            iVar22 = param_2[8];
            piVar12 = *(int **)(pcVar13 + 0x220) + *(int *)(pcVar13 + 0x224);
            piVar26 = *(int **)(pcVar13 + 0x220);
            while (piVar26 + 4 <= piVar12) {
              iVar1 = iVar22 + *piVar26 * 0x54;
              iVar2 = iVar22 + piVar26[1] * 0x54;
              iVar3 = iVar22 + piVar26[2] * 0x54;
              iVar4 = iVar22 + piVar26[3] * 0x54;
              puVar16 = *(undefined8 **)(iVar1 + 0x38);
              uVar5 = puVar16[1];
              puVar21 = *(undefined8 **)(iVar2 + 0x38);
              uVar6 = *puVar21;
              uVar7 = puVar21[1];
              puVar21 = *(undefined8 **)(iVar3 + 0x38);
              uVar8 = *puVar21;
              uVar9 = puVar21[1];
              puVar21 = *(undefined8 **)(iVar4 + 0x38);
              uVar10 = *puVar21;
              uVar11 = puVar21[1];
              puVar25 = (undefined8 *)(*(int *)(iVar1 + 4) * 0x10 + iVar19);
              puVar23 = (undefined8 *)(*(int *)(iVar2 + 4) * 0x10 + iVar19);
              puVar24 = (undefined8 *)(*(int *)(iVar3 + 4) * 0x10 + iVar19);
              puVar21 = (undefined8 *)(*(int *)(iVar4 + 4) * 0x10 + iVar19);
              *puVar25 = *puVar16;
              puVar25[1] = uVar5;
              *puVar23 = uVar6;
              puVar23[1] = uVar7;
              *puVar24 = uVar8;
              puVar24[1] = uVar9;
              *puVar21 = uVar10;
              puVar21[1] = uVar11;
              piVar26 = piVar26 + 4;
            }
            for (; piVar26 < piVar12; piVar26 = piVar26 + 1) {
              iVar1 = iVar22 + *piVar26 * 0x54;
              puVar16 = *(undefined8 **)(iVar1 + 0x38);
              uVar5 = puVar16[1];
              puVar21 = (undefined8 *)(*(int *)(iVar1 + 4) * 0x10 + iVar19);
              *puVar21 = *puVar16;
              puVar21[1] = uVar5;
            }
          }
          puVar18 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
          *(undefined4 **)(param_1 + 0x274c) = puVar18;
          *puVar18 = 0x8a1;
          *(undefined4 *)(*(int *)(param_1 + 0x274c) + 4) = 0;
          iVar19 = *(int *)(param_1 + 0x274c) + 8;
          *(int *)(param_1 + 0x274c) = iVar19;
          (**(code **)(param_1 + 0x275c))(param_1,iVar19);
          ((int (*)())FUN_000600c8)(puVar20[0x22],1);
        }
        *(ushort *)(param_1 + 0x1b90) =
             *(ushort *)(param_1 + 0x1b90) & 0xfc00 | *(ushort *)(pcVar13 + 4) & 0x3ff;
        *(uint *)(param_1 + 0x1b90) =
             *(uint *)(param_1 + 0x1b90) & 0xfff003ff |
             ((ushort)((short)*(undefined4 *)(pcVar13 + 8) + *(short *)(pcVar13 + 4)) & 0x3ff) << 10
        ;
        *(ushort *)(param_1 + 0x1b92) =
             *(ushort *)(param_1 + 0x1b92) & 0xc00f | (*(ushort *)(pcVar13 + 0x10) & 0x3ff) << 4;
        *(ushort *)(param_1 + 0x1b94) =
             *(ushort *)(param_1 + 0x1b94) & 0xfc00 |
             (short)*(undefined4 *)(pcVar13 + 0xc) + *(short *)(pcVar13 + 4) & 0x3ffU;
        *(char *)(param_1 + 0x1b8c) = (char)*(undefined4 *)(pcVar13 + 0x14);
        cVar17 = '\0';
        if (*(int *)(pcVar13 + 0x5c) != 0) {
          cVar17 = (char)*(int *)(pcVar13 + 0x5c) + -1;
        }
        *(char *)(param_1 + 0x1b8e) = cVar17;
        puVar20 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
        *(undefined4 **)(param_1 + 0x274c) = puVar20;
        *puVar20 = 0x208b4;
        *(undefined4 *)(*(int *)(param_1 + 0x274c) + 4) = *(undefined4 *)(param_1 + 0x1b90);
        *(undefined4 *)(*(int *)(param_1 + 0x274c) + 8) = *(undefined4 *)(param_1 + 0x1b8c);
        *(undefined4 *)(*(int *)(param_1 + 0x274c) + 0xc) = *(undefined4 *)(param_1 + 0x1b94);
        iVar19 = *(int *)(param_1 + 0x274c) + 0x10;
        *(int *)(param_1 + 0x274c) = iVar19;
        (**(code **)(param_1 + 0x275c))(param_1,iVar19);
        puVar20 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
        *(undefined4 **)(param_1 + 0x274c) = puVar20;
        *puVar20 = 0x8b7;
        *(undefined4 *)(*(int *)(param_1 + 0x274c) + 4) = *(undefined4 *)(param_1 + 0x1b98);
        iVar19 = *(int *)(param_1 + 0x274c) + 8;
        *(int *)(param_1 + 0x274c) = iVar19;
        (**(code **)(param_1 + 0x275c))(param_1,iVar19);
        FUN_0004fd18(param_1,*(undefined4 *)(pcVar13 + 0x2a4),*(undefined4 *)(pcVar13 + 0x2a8),
                     *(undefined4 *)(pcVar13 + 0x2ac));
        ((int (*)())FUN_00062539)();
        return;
      }
      local_2c = *piVar12;
      iVar22 = piVar12[1] - *(int *)(param_1 + 0x2448);
      local_28 = 0;
      local_24 = 0;
      iVar19 = *(int *)(param_1 + 0xd8);
      do {
        if (iVar19 == 1) goto LAB_00062bb1;
        if (iVar19 == 0) {
          local_28 = 0x80 - local_2c;
          local_24 = 0x80 - iVar22;
        }
        else if (iVar19 == 2) goto LAB_00062c03;
        while( true ) {
          while( true ) {
            if ((uVar14 <= local_28) && (uVar15 <= local_24)) {
              *(int *)(pcVar13 + 4) = local_2c;
              *(uint *)(pcVar13 + 0x10) = (uVar14 - 1) + local_2c;
              *(int *)(pcVar13 + 0x14) = iVar22;
              *piVar12 = *piVar12 + uVar14;
              piVar12[1] = piVar12[1] + uVar15;
              ((int (*)())FUN_00060018)();
              *pcVar13 = '\x01';
              FUN_00079570(param_1,pcVar13);
              goto LAB_0006298a;
            }
            if (iVar19 != 1) break;
            iVar19 = 2;
            *(undefined4 *)(param_1 + 0xd8) = 2;
LAB_00062c03:
            local_28 = 0x100 - local_2c;
            local_24 = 0x100 - iVar22;
            *(byte *)(param_1 + 0x8d) = *(byte *)(param_1 + 0x8d) | 0x20;
            *(byte *)(param_1 + 0x8e) = *(byte *)(param_1 + 0x8e) | 1;
          }
          if (iVar19 != 0) break;
          iVar19 = 1;
          *(undefined4 *)(param_1 + 0xd8) = 1;
LAB_00062bb1:
          local_28 = 0xfe - local_2c;
          local_24 = 0x100 - iVar22;
          *(byte *)(param_1 + 0x8d) = *(byte *)(param_1 + 0x8d) | 0x20;
        }
        if (iVar19 == 2) {
          puVar18 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
          *(undefined4 **)(param_1 + 0x274c) = puVar18;
          *puVar18 = 0x8a1;
          *(undefined4 *)(*(int *)(param_1 + 0x274c) + 4) = 0;
          iVar19 = *(int *)(param_1 + 0x274c) + 8;
          *(int *)(param_1 + 0x274c) = iVar19;
          (**(code **)(param_1 + 0x275c))(param_1,iVar19);
          *piVar12 = 0;
          piVar12[1] = *(int *)(param_1 + 0x2448);
          ((int (*)())FUN_000605ad)(param_1);
          local_2c = 0;
          iVar22 = 0;
          iVar19 = *(int *)(param_1 + 0xd8);
        }
      } while( true );
    }
  }
  return;
}

/* FUN_00062d7a @ 0x62d7a (529 bytes) */
int FUN_00062d7a(param_1)
  int param_1;
{
  byte *pbVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  bool bVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  
  if ((*(byte *)(param_1 + 0x45) & 8) == 0) {
    iVar9 = 0;
    do {
      pbVar1 = (byte *)(param_1 + 0x18ac + iVar9 * 8);
      *pbVar1 = *pbVar1 & 0xfe;
      iVar9 = iVar9 + 1;
    } while (iVar9 != 0x10);
    return;
  }
  piVar2 = *(int **)(param_1 + 0x1168);
  if (((*(byte *)(param_1 + 0x2d) & 8) != 0) && (*(char *)(param_1 + 0x8d) < '\0')) {
    puVar8 = *(undefined4 **)(param_1 + 0x11b4);
    puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
    *(undefined4 **)(param_1 + 0x274c) = puVar6;
    *puVar6 = 0x8a1;
    *(undefined4 *)(*(int *)(param_1 + 0x274c) + 4) = 0;
    iVar9 = *(int *)(param_1 + 0x274c) + 8;
    *(int *)(param_1 + 0x274c) = iVar9;
    (**(code **)(param_1 + 0x275c))(param_1,iVar9);
    *puVar8 = 0;
    puVar8[1] = *(undefined4 *)(param_1 + 0x2448);
    ((int (*)())FUN_000605ad)(param_1);
    *(byte *)(param_1 + 0x8d) = *(byte *)(param_1 + 0x8d) & 0x7f;
  }
  if ((char)piVar2[4] == '\0') {
    return;
  }
  iVar9 = *(int *)(param_1 + 0x118c);
  piVar3 = *(int **)(*piVar2 + iVar9 * 4);
  iVar4 = *piVar3;
  uVar7 = ((int (*)())FUN_00060324)();
  if ((*(char *)(param_1 + 0x31) == '\0') || (*(char *)(piVar2[1] + iVar9) == '\0')) {
    bVar5 = false;
  }
  else {
    bVar5 = true;
  }
  if (((uVar7 != *(uint *)(iVar4 + 0x48)) || (*(int *)(iVar4 + 0x18) != piVar2[0x15])) || (bVar5)) {
    for (iVar9 = piVar3[(uVar7 & 0x1f) + 1]; iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x2b4)) {
      if (*(uint *)(iVar9 + 0x48) == uVar7) {
        if (!bVar5) {
          *piVar3 = iVar9;
          piVar2[0x15] = *(int *)(iVar9 + 0x18);
          *(undefined4 *)(param_1 + 0x1174) = *(undefined4 *)(iVar9 + 0x18);
          goto LAB_00062ebb;
        }
        break;
      }
    }
    FUN_00053161(param_1,piVar2);
LAB_00062ebb:
    *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 3;
  }
  else if ((*(byte *)(param_1 + 0x2d) & 4) == 0) {
    if ((*(byte *)(param_1 + 0x2d) & 3) == 0) {
      return;
    }
    puVar8 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
    *(undefined4 **)(param_1 + 0x274c) = puVar8;
    *puVar8 = 0x8a1;
    *(undefined4 *)(*(int *)(param_1 + 0x274c) + 4) = 0;
    iVar9 = *(int *)(param_1 + 0x274c) + 8;
    *(int *)(param_1 + 0x274c) = iVar9;
    (**(code **)(param_1 + 0x275c))(param_1,iVar9);
    ((int (*)())FUN_000600c8)(piVar3[0x22],0);
    return;
  }
  ((int (*)())FUN_00062802)(param_1,piVar2);
  ((int (*)())FUN_00060499)();
  return;
}

/* FUN_00062f8b @ 0x62f8b (363 bytes) */
int FUN_00062f8b(param_1)
  int param_1;
{
  undefined4 *puVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  
  for (iVar4 = *(int *)(*(int *)(param_1 + 0x11b4) + 8); iVar4 != 0; iVar4 = *(int *)(iVar4 + 4)) {
    ((int (*)())FUN_00060018)();
  }
  puVar1 = *(undefined4 **)(**(int **)(param_1 + 0x1168) + *(int *)(param_1 + 0x118c) * 4);
  pcVar2 = (char *)*puVar1;
  if (((char)(*(int **)(param_1 + 0x1168))[4] != '\0') && (*pcVar2 != '\0')) {
    puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
    *(undefined4 **)(param_1 + 0x274c) = puVar3;
    *puVar3 = 0x208b4;
    *(undefined4 *)(*(int *)(param_1 + 0x274c) + 4) = *(undefined4 *)(param_1 + 0x1b90);
    *(undefined4 *)(*(int *)(param_1 + 0x274c) + 8) = *(undefined4 *)(param_1 + 0x1b8c);
    *(undefined4 *)(*(int *)(param_1 + 0x274c) + 0xc) = *(undefined4 *)(param_1 + 0x1b94);
    iVar4 = *(int *)(param_1 + 0x274c) + 0x10;
    *(int *)(param_1 + 0x274c) = iVar4;
    (**(code **)(param_1 + 0x275c))(param_1,iVar4);
    puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
    *(undefined4 **)(param_1 + 0x274c) = puVar3;
    *puVar3 = 0x8b7;
    *(undefined4 *)(*(int *)(param_1 + 0x274c) + 4) = *(undefined4 *)(param_1 + 0x1b98);
    iVar4 = *(int *)(param_1 + 0x274c) + 8;
    *(int *)(param_1 + 0x274c) = iVar4;
    (**(code **)(param_1 + 0x275c))(param_1,iVar4);
    FUN_0004fd18(param_1,*(undefined4 *)(pcVar2 + 0x2a4),*(undefined4 *)(pcVar2 + 0x2a8),
                 *(undefined4 *)(pcVar2 + 0x2ac));
    ((int (*)())FUN_000600c8)(puVar1[0x22],1);
    *(byte *)(param_1 + 0x8d) = *(byte *)(param_1 + 0x8d) & 0x7f;
    return;
  }
  *(byte *)(param_1 + 0x8d) = *(byte *)(param_1 + 0x8d) & 0x7f;
  return;
}

/* FUN_000630f6 @ 0x630f6 (548 bytes) */
int FUN_000630f6(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_14;
  undefined4 local_10;
  
  cVar1 = *(char *)(param_1 + 0x29);
  if (*(char *)(param_1 + 0x1868) == '\0') {
    (**(code **)(param_1 + 0x12e0))(param_1);
    return;
  }
  *(undefined1 *)(param_1 + 0x126) = 0;
  (**(code **)(param_1 + 0x133c))(param_1);
  if (cVar1 == '\0') {
    iVar2 = *(int *)(param_1 + 0x13c);
    if (iVar2 == *(int *)(param_1 + 0x140)) {
      iVar5 = *(int *)(param_1 + 0x148);
      if (iVar5 == *(int *)(param_1 + 0x144)) {
        return;
      }
    }
    else {
      iVar5 = *(int *)(param_1 + 0x148);
    }
  }
  else {
    iVar2 = *(int *)(param_1 + 0x13c);
    iVar5 = *(int *)(param_1 + 0x148);
  }
  *(int *)(param_1 + 0x140) = iVar2;
  *(int *)(param_1 + 0x144) = iVar5;
  if (*(char *)(param_1 + 0x124) == '\0') {
    if ((*(byte *)(param_1 + 0x45) & 8) != 0) {
      return;
    }
    iVar2 = FUN_0009cdff(param_1,param_1 + 0x1874);
    if (iVar2 == 0) {
      FUN_0009afcf(param_1);
      uVar3 = FUN_00099e1d(param_1);
      (**(code **)(param_1 + 0x12b4))(param_1);
      uVar4 = ((void * (*)())FUN_0009b319)(param_1,1,&local_10,&local_14,uVar3);
      iVar2 = FUN_0009a799(param_1,param_1 + 0x1874,uVar4,*(undefined1 *)(param_1 + 0x131),local_10,
                           local_14,uVar3,*(undefined1 *)(param_1 + 0x126));
      if (*(char *)(param_1 + 0x126) != '\0') {
        *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 2;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1020;
        goto LAB_00063247;
      }
    }
    else if (*(char *)(iVar2 + 0x59) != '\0') {
      *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 2;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1020;
      *(undefined1 *)(param_1 + 0x126) = 1;
LAB_00063247:
      *(undefined1 *)(param_1 + 0x29) = 1;
      (**(code **)(param_1 + 0x133c))(param_1);
      (**(code **)(param_1 + 0x12dc))(param_1);
      return;
    }
    *(int *)(param_1 + 0x14c) = iVar2;
    (**(code **)(param_1 + 0x12c4))(param_1,iVar2);
    iVar5 = *(int *)(iVar2 + 0x54) + 0x750;
    if (iVar5 == *(int *)(param_1 + 0x148c)) {
      (**(code **)(param_1 + 0x12a0))(param_1,iVar5);
    }
    else {
      (**(code **)(param_1 + 0x1294))(param_1,iVar5,*(undefined4 *)(iVar2 + 0x3c));
    }
    if (*(char *)(*(int *)(iVar2 + 0x54) + 0x752) == '\0') {
      return;
    }
    *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 2;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1020;
    *(undefined1 *)(param_1 + 0x126) = 1;
    *(undefined1 *)(param_1 + 0x29) = 1;
    (**(code **)(param_1 + 0x133c))(param_1);
  }
  (**(code **)(param_1 + 0x12dc))(param_1);
  return;
}

/* FUN_0006331a @ 0x6331a (150 bytes) */
int FUN_0006331a(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  _memset((void *)(param_2 + 0x68),-1,0x3c);
  *(undefined4 *)(param_2 + 0x68) = 0;
  *(undefined4 *)(param_2 + 0x6c) = 0;
  *(undefined4 *)(param_2 + 0x74) = 0;
  *(undefined4 *)(param_2 + 0x7c) = 0;
  *(undefined4 *)(param_2 + 0x70) = 0;
  *(undefined4 *)(param_2 + 0x78) = 1;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x88) = 1;
  *(undefined4 *)(param_2 + 0x8c) = 2;
  *(undefined4 *)(param_2 + 0x90) = 3;
  *(undefined4 *)(param_2 + 0x94) = 4;
  *(undefined4 *)(param_2 + 0x98) = 5;
  *(undefined4 *)(param_2 + 0x9c) = 6;
  *(undefined4 *)(param_2 + 0xa0) = 7;
  return;
}

