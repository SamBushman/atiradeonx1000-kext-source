#include "decls.h"

/* FUN_000eacec @ 0xeacec (238 bytes) */
int FUN_000eacec(param_1)
  int param_1;
{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  
  uVar1 = *(undefined4 *)(param_1 + 300);
  iVar3 = FUN_000e97aa(uVar1);
  if ((iVar3 == 1) && (iVar3 = FUN_000e97aa(*(undefined4 *)(param_1 + 0x130)), iVar3 == 1)) {
    piVar4 = (int *)FUN_000eac7c(uVar1,0);
    cVar2 = (**(code **)(*piVar4 + 0x28))(piVar4);
    if (cVar2 != '\0') {
      piVar4 = (int *)FUN_000eac7c(*(undefined4 *)(param_1 + 0x130),0);
      cVar2 = (**(code **)(*piVar4 + 0x28))(piVar4);
      if (cVar2 != '\0') {
        uVar1 = *(undefined4 *)(param_1 + 300);
        iVar3 = FUN_000e97bc(uVar1);
        if ((iVar3 == 1) && (iVar3 = FUN_000e97bc(*(undefined4 *)(param_1 + 0x130)), iVar3 == 1)) {
          piVar4 = (int *)FUN_000eac0c(uVar1,0);
          cVar2 = (**(code **)(*piVar4 + 0x24))(piVar4);
          if (cVar2 != '\0') {
            piVar4 = (int *)FUN_000eac0c(*(undefined4 *)(param_1 + 0x130),0);
            cVar2 = (**(code **)(*piVar4 + 0x24))(piVar4);
            if (cVar2 != '\0') {
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_000eadda @ 0xeadda (737 bytes) */
int FUN_000eadda(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int *param_3;
{
  int *piVar1;
  uint *puVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  (**(code **)(*param_1 + 0x20))(param_1);
  (**(code **)(*param_1 + 0x1c))(param_1);
  uVar8 = 0;
  uVar6 = 1;
  iVar7 = 0;
  iVar5 = param_2[0x34];
  if (*(int *)(iVar5 + 4) != 0) {
    do {
      piVar1 = *(int **)(iVar7 + *(int *)(iVar5 + 8));
      if (piVar1 != (int *)0x0) {
        if (param_1 == piVar1) {
          cVar3 = (**(code **)(*param_3 + 0x20))(param_3);
          if ((cVar3 == '\0') || ((*(byte *)(param_1[0x2b] + 0x30) & 2) != 0)) {
            puVar2 = (uint *)param_2[0x34];
            if (uVar8 < *puVar2) {
              uVar6 = puVar2[1];
              if (uVar6 <= uVar8) {
                _memset((void *)(puVar2[2] + uVar6 * 4),0,(uVar8 - uVar6) * 4 + 4);
                puVar2[1] = uVar8 + 1;
              }
              *(int **)(puVar2[2] + uVar8 * 4) = param_3;
            }
            else {
              puVar4 = (undefined4 *)FUN_001a7f7c(puVar2,uVar8);
              *puVar4 = param_3;
            }
          }
          else {
            FUN_001a7f3c(param_2[0x34],uVar8);
          }
          break;
        }
        uVar8 = uVar8 + 1;
      }
      uVar6 = uVar6 + 1;
      iVar7 = iVar7 + 4;
    } while (uVar6 <= *(uint *)(iVar5 + 4));
  }
  iVar9 = 0;
  uVar6 = 1;
  iVar7 = 0;
  iVar5 = param_1[0x35];
  if (*(int *)(iVar5 + 4) != 0) {
    do {
      piVar1 = *(int **)(iVar7 + *(int *)(iVar5 + 8));
      if (piVar1 != (int *)0x0) {
        if (param_2 == piVar1) {
          FUN_001a7f3c(iVar5,iVar9);
          break;
        }
        iVar9 = iVar9 + 1;
      }
      uVar6 = uVar6 + 1;
      iVar7 = iVar7 + 4;
    } while (uVar6 <= *(uint *)(iVar5 + 4));
  }
  uVar8 = 0;
  uVar6 = 1;
  iVar5 = 0;
  puVar2 = (uint *)param_3[0x35];
  if (puVar2[1] != 0) {
    do {
      if (*(int **)(puVar2[2] + iVar5) != (int *)0x0) {
        if (param_1 == *(int **)(puVar2[2] + iVar5)) {
          if (uVar8 < *puVar2) {
            uVar6 = puVar2[1];
            if (uVar6 <= uVar8) {
              _memset((void *)(puVar2[2] + uVar6 * 4),0,(uVar8 - uVar6) * 4 + 4);
              puVar2[1] = uVar8 + 1;
            }
            *(int **)(puVar2[2] + uVar8 * 4) = param_2;
          }
          else {
            puVar4 = (undefined4 *)FUN_001a7f7c(puVar2,uVar8);
            *puVar4 = param_2;
          }
          break;
        }
        uVar8 = uVar8 + 1;
      }
      uVar6 = uVar6 + 1;
      iVar5 = iVar5 + 4;
    } while (uVar6 <= puVar2[1]);
  }
  iVar9 = 0;
  uVar6 = 1;
  iVar7 = 0;
  iVar5 = param_1[0x34];
  if (*(int *)(iVar5 + 4) != 0) {
    do {
      piVar1 = *(int **)(*(int *)(iVar5 + 8) + iVar7);
      if (piVar1 != (int *)0x0) {
        if (param_3 == piVar1) {
          FUN_001a7f3c(iVar5,iVar9);
          break;
        }
        iVar9 = iVar9 + 1;
      }
      uVar6 = uVar6 + 1;
      iVar7 = iVar7 + 4;
    } while (uVar6 <= *(uint *)(iVar5 + 4));
  }
  if ((*(byte *)(param_1[0x2b] + 0x30) & 2) == 0) {
    cVar3 = (**(code **)(*param_3 + 0x20))(param_3);
    if ((cVar3 == '\0') || (iVar5 = FUN_000e97aa(param_2), iVar5 != 0)) {
      (**(code **)(*param_2 + 0x48))(param_2);
    }
    cVar3 = (**(code **)(*param_3 + 0x20))(param_3);
    if ((cVar3 == '\0') || (iVar5 = FUN_000e97bc(param_3), iVar5 != 0)) {
      (**(code **)(*param_3 + 0x48))(param_3);
      return 1;
    }
  }
  else {
    (**(code **)(*param_2 + 0x48))(param_2);
    (**(code **)(*param_3 + 0x48))(param_3);
  }
  return 1;
}

/* FUN_000eb0bc @ 0xeb0bc (109 bytes) */
int FUN_000eb0bc(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  if (*(int *)(param_3 + 0xec) != param_1) {
    ((int (*)())FUN_000eadda)(param_1,param_2,param_3);
    FUN_000e94da(param_1);
    return 1;
  }
  *(undefined4 *)(param_3 + 0xec) = *(undefined4 *)(param_1 + 0xec);
  ((int (*)())FUN_000eadda)(param_1,param_2,param_3);
  FUN_000e94da(param_1);
  return 1;
}

/* FUN_000eb12a @ 0xeb12a (326 bytes) */
int FUN_000eb12a(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  uVar7 = 0;
  uVar5 = 1;
  iVar4 = 0;
  puVar1 = *(uint **)(param_1 + 0xd0);
  if (puVar1[1] != 0) {
    do {
      if (*(int *)(iVar4 + puVar1[2]) != 0) {
        if (param_2 == *(int *)(iVar4 + puVar1[2])) {
          if (uVar7 < *puVar1) {
            uVar5 = puVar1[1];
            if (uVar5 <= uVar7) {
              _memset((void *)(puVar1[2] + uVar5 * 4),0,(uVar7 - uVar5) * 4 + 4);
              puVar1[1] = uVar7 + 1;
            }
            *(int *)(puVar1[2] + uVar7 * 4) = param_3;
          }
          else {
            piVar3 = (int *)FUN_001a7f7c(puVar1,uVar7);
            *piVar3 = param_3;
          }
          break;
        }
        uVar7 = uVar7 + 1;
      }
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 4;
    } while (uVar5 <= puVar1[1]);
  }
  iVar8 = 0;
  uVar5 = 1;
  iVar6 = 0;
  iVar4 = *(int *)(param_2 + 0xd4);
  if (*(int *)(iVar4 + 4) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(iVar4 + 8) + iVar6);
      if (iVar2 != 0) {
        if (param_1 == iVar2) {
          FUN_001a7f3c(iVar4,iVar8);
          break;
        }
        iVar8 = iVar8 + 1;
      }
      uVar5 = uVar5 + 1;
      iVar6 = iVar6 + 4;
    } while (uVar5 <= *(uint *)(iVar4 + 4));
  }
  uVar5 = 1;
  iVar6 = 0;
  iVar4 = *(int *)(param_3 + 0xd4);
  if (*(int *)(iVar4 + 4) != 0) {
    do {
      iVar8 = *(int *)(*(int *)(iVar4 + 8) + iVar6);
      if ((iVar8 != 0) && (param_1 == iVar8)) {
        return;
      }
      uVar5 = uVar5 + 1;
      iVar6 = iVar6 + 4;
    } while (uVar5 <= *(uint *)(iVar4 + 4));
  }
  FUN_000ea83c(param_3,param_1);
  return;
}

/* FUN_000eb270 @ 0xeb270 (53 bytes) */
int FUN_000eb270(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())FUN_000eb12a)(param_1,param_2,param_3);
  FUN_000ea91c();
  return;
}

/* FUN_000eb2a6 @ 0xeb2a6 (326 bytes) */
int FUN_000eb2a6(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  uVar7 = 0;
  uVar5 = 1;
  iVar4 = 0;
  puVar1 = *(uint **)(param_1 + 0xd4);
  if (puVar1[1] != 0) {
    do {
      if (*(int *)(iVar4 + puVar1[2]) != 0) {
        if (param_2 == *(int *)(iVar4 + puVar1[2])) {
          if (uVar7 < *puVar1) {
            uVar5 = puVar1[1];
            if (uVar5 <= uVar7) {
              _memset((void *)(puVar1[2] + uVar5 * 4),0,(uVar7 - uVar5) * 4 + 4);
              puVar1[1] = uVar7 + 1;
            }
            *(int *)(puVar1[2] + uVar7 * 4) = param_3;
          }
          else {
            piVar3 = (int *)FUN_001a7f7c(puVar1,uVar7);
            *piVar3 = param_3;
          }
          break;
        }
        uVar7 = uVar7 + 1;
      }
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 4;
    } while (uVar5 <= puVar1[1]);
  }
  iVar8 = 0;
  uVar5 = 1;
  iVar6 = 0;
  iVar4 = *(int *)(param_2 + 0xd0);
  if (*(int *)(iVar4 + 4) != 0) {
    do {
      iVar2 = *(int *)(*(int *)(iVar4 + 8) + iVar6);
      if (iVar2 != 0) {
        if (param_1 == iVar2) {
          FUN_001a7f3c(iVar4,iVar8);
          break;
        }
        iVar8 = iVar8 + 1;
      }
      uVar5 = uVar5 + 1;
      iVar6 = iVar6 + 4;
    } while (uVar5 <= *(uint *)(iVar4 + 4));
  }
  uVar5 = 1;
  iVar6 = 0;
  iVar4 = *(int *)(param_3 + 0xd0);
  if (*(int *)(iVar4 + 4) != 0) {
    do {
      iVar8 = *(int *)(*(int *)(iVar4 + 8) + iVar6);
      if ((iVar8 != 0) && (param_1 == iVar8)) {
        return;
      }
      uVar5 = uVar5 + 1;
      iVar6 = iVar6 + 4;
    } while (uVar5 <= *(uint *)(iVar4 + 4));
  }
  FUN_000ea8ac(param_3,param_1);
  return;
}

/* FUN_000eb3ec @ 0xeb3ec (302 bytes) */
int FUN_000eb3ec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  uVar3 = FUN_000e9bea(param_1,param_2);
  puVar1 = *(uint **)(param_1 + 0xd0);
  if (uVar3 < *puVar1) {
    uVar2 = puVar1[1];
    if (uVar2 <= uVar3) {
      _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar3 - uVar2) * 4 + 4);
      puVar1[1] = uVar3 + 1;
    }
    puVar4 = (undefined4 *)(puVar1[2] + uVar3 * 4);
  }
  else {
    puVar4 = (undefined4 *)FUN_001a7f7c(puVar1,uVar3);
  }
  *puVar4 = param_3;
  uVar3 = FUN_000e9c3e(param_2,param_1);
  puVar1 = *(uint **)(param_2 + 0xd4);
  if (uVar3 < *puVar1) {
    uVar2 = puVar1[1];
    if (uVar2 <= uVar3) {
      _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar3 - uVar2) * 4 + 4);
      puVar1[1] = uVar3 + 1;
    }
    puVar4 = (undefined4 *)(puVar1[2] + uVar3 * 4);
  }
  else {
    puVar4 = (undefined4 *)FUN_001a7f7c(puVar1,uVar3);
  }
  *puVar4 = param_3;
  FUN_000ea83c(param_3,param_1);
  FUN_000ea8ac();
  return;
}

/* FUN_000eb51a @ 0xeb51a (223 bytes) */
int FUN_000eb51a(param_1, param_2)
  int param_1;
  dword param_2;
{
  uint *puVar1;
  uint uVar2;
  dword dVar3;
  dword *pdVar4;
  uint uVar5;
  
  puVar1 = *(uint **)(param_1 + 0xc4);
  uVar2 = puVar1[1];
  if (0 < (int)uVar2) {
    uVar5 = 0;
    do {
      dVar3 = MACH_HEADER.magic;
      if (uVar5 < uVar2) {
        dVar3 = *(dword *)(puVar1[2] + uVar5 * 4);
      }
      if (param_2 == dVar3) {
        FUN_0012a7b2();
        return;
      }
      uVar5 = uVar5 + 1;
    } while (uVar2 != uVar5);
  }
  if (uVar2 < *puVar1) {
    _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
    puVar1[1] = uVar2 + 1;
    *(dword *)(uVar2 * 4 + puVar1[2]) = param_2;
  }
  else {
    pdVar4 = (dword *)FUN_001a7f7c(puVar1,uVar2);
    *pdVar4 = param_2;
  }
  FUN_0012a7b2();
  return;
}

/* FUN_000eb5fa @ 0xeb5fa (117 bytes) */
int FUN_000eb5fa(param_1)
  int param_1;
{
  byte bVar1;
  int *piVar2;
  
  if (*(char *)(param_1 + 0x136) == '\0') {
    piVar2 = *(int **)(*(int *)(*(int *)(param_1 + 0x138) + 0xa4) + 0x18);
    if (*piVar2 == 0) {
      piVar2 = (int *)FUN_001a7f7c(piVar2,0);
    }
    else {
      if (piVar2[1] == 0) {
        *(undefined4 *)piVar2[2] = 0;
        piVar2[1] = 1;
      }
      piVar2 = (int *)piVar2[2];
    }
    bVar1 = *(byte *)(*piVar2 + 0x15c);
    if ((((bVar1 & 1) != 0) && ((bVar1 & 2) != 0)) && ((bVar1 & 4) != 0)) {
      return 1;
    }
  }
  return 0;
}

/* FUN_000eb670 @ 0xeb670 (301 bytes) */
int FUN_000eb670(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_001fc0a8;
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  FUN_001a7e06(param_1 + 0x24);
  iVar1 = *(int *)(param_2 + 0xa8);
  param_1[0x2a] = iVar1;
  param_1[0x2b] = *(undefined4 *)(param_2 + 0xac);
  iVar2 = *(int *)(iVar1 + 0x70);
  param_1[0x2c] = iVar2;
  *(int *)(iVar1 + 0x70) = iVar2 + 1;
  param_1[0x2e] = *(undefined4 *)(param_2 + 0xb8);
  param_1[0x30] = *(undefined4 *)(param_2 + 0xc0);
  *(undefined1 *)(param_1 + 0x37) = *(undefined1 *)(param_2 + 0xdc);
  param_1[0x38] = 0x7fffffff;
  param_1[0x39] = 0x7fffffff;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  *(undefined1 *)(param_1 + 0x42) = *(undefined1 *)(param_2 + 0x108);
  *(undefined1 *)((int)param_1 + 0x109) = *(undefined1 *)(param_2 + 0x109);
  param_1[0x44] = 0xffffffff;
  FUN_000ea4e6(param_1);
  FUN_000ea3e6(param_1);
  uVar3 = FUN_000e9d04(param_1[0x2b]);
  param_1[0x2d] = uVar3;
  return;
}

/* FUN_000eb7d0 @ 0xeb7d0 (68 bytes) */
int FUN_000eb7d0(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x128);
  *puVar2 = uVar1;
  ((int (*)())FUN_000eb670)(puVar2 + 1,param_1);
  return puVar2 + 1;
}

/* FUN_000eb832 @ 0xeb832 (301 bytes) */
int FUN_000eb832(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_001fc0a8;
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  FUN_001a7e06(param_1 + 0x24);
  iVar1 = *(int *)(param_2 + 0xa8);
  param_1[0x2a] = iVar1;
  param_1[0x2b] = *(undefined4 *)(param_2 + 0xac);
  iVar2 = *(int *)(iVar1 + 0x70);
  param_1[0x2c] = iVar2;
  *(int *)(iVar1 + 0x70) = iVar2 + 1;
  param_1[0x2e] = *(undefined4 *)(param_2 + 0xb8);
  param_1[0x30] = *(undefined4 *)(param_2 + 0xc0);
  *(undefined1 *)(param_1 + 0x37) = *(undefined1 *)(param_2 + 0xdc);
  param_1[0x38] = 0x7fffffff;
  param_1[0x39] = 0x7fffffff;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  *(undefined1 *)(param_1 + 0x42) = *(undefined1 *)(param_2 + 0x108);
  *(undefined1 *)((int)param_1 + 0x109) = *(undefined1 *)(param_2 + 0x109);
  param_1[0x44] = 0xffffffff;
  FUN_000ea4e6(param_1);
  FUN_000ea3e6(param_1);
  uVar3 = FUN_000e9d04(param_1[0x2b]);
  param_1[0x2d] = uVar3;
  return;
}

/* FUN_000eb992 @ 0xeb992 (320 bytes) */
int FUN_000eb992(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_001fc0a8;
  param_1[3] = 0;
  FUN_001a7e06(param_1 + 0x24);
  param_1[0x2a] = param_2;
  param_1[0x2b] = 0;
  iVar3 = *(int *)(param_2 + 0x70);
  param_1[0x2c] = iVar3;
  *(int *)(param_2 + 0x70) = iVar3 + 1;
  param_1[0x2e] = 0;
  param_1[0x30] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x37) = 0;
  param_1[0x38] = 0x7fffffff;
  param_1[0x39] = 0x7fffffff;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  *(undefined1 *)(param_1 + 0x42) = 0;
  *(undefined1 *)((int)param_1 + 0x109) = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0xffffffff;
  param_1[0x48] = 0;
  FUN_000ea4e6(param_1);
  FUN_000ea3e6(param_1);
  iVar3 = 0x20;
  puVar1 = param_1;
  do {
    puVar1[4] = 0;
    puVar1 = puVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar2 = FUN_000e9d04(*(undefined4 *)(param_1[0x2a] + 0x3f4));
  param_1[0x2d] = uVar2;
  return;
}

/* FUN_000ebb06 @ 0xebb06 (320 bytes) */
int FUN_000ebb06(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_001fc0a8;
  param_1[3] = 0;
  FUN_001a7e06(param_1 + 0x24);
  param_1[0x2a] = param_2;
  param_1[0x2b] = 0;
  iVar3 = *(int *)(param_2 + 0x70);
  param_1[0x2c] = iVar3;
  *(int *)(param_2 + 0x70) = iVar3 + 1;
  param_1[0x2e] = 0;
  param_1[0x30] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x37) = 0;
  param_1[0x38] = 0x7fffffff;
  param_1[0x39] = 0x7fffffff;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  *(undefined1 *)(param_1 + 0x42) = 0;
  *(undefined1 *)((int)param_1 + 0x109) = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0xffffffff;
  param_1[0x48] = 0;
  FUN_000ea4e6(param_1);
  FUN_000ea3e6(param_1);
  iVar3 = 0x20;
  puVar1 = param_1;
  do {
    puVar1[4] = 0;
    puVar1 = puVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar2 = FUN_000e9d04(*(undefined4 *)(param_1[0x2a] + 0x3f4));
  param_1[0x2d] = uVar2;
  return;
}

/* FUN_000ebc7a @ 0xebc7a (365 bytes) */
int FUN_000ebc7a(param_1)
  undefined4 *param_1;
{
  int iVar1;
  
  *param_1 = &PTR_FUN_001fc0a8;
  iVar1 = param_1[0x35];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x34];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x3c];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x3d];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x31];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  FUN_001a7d34(param_1 + 0x24);
  param_1[0x27] = PTR_DAT_00213441 + 8;
  param_1[0x24] = PTR_DAT_00213441 + 8;
  *param_1 = PTR_DAT_00213441 + 8;
  return;
}

/* FUN_000ebe1a @ 0xebe1a (126 bytes) */
int FUN_000ebe1a(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_000ebb06)(param_1,param_2);
  *param_1 = PTR_DAT_00213451 + 8;
  uVar2 = *(undefined4 *)(param_2 + 0xb8);
  puVar1 = (undefined4 *)FUN_001a7bca(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[4] = uVar2;
  puVar1[2] = 0;
  puVar1[1] = 2;
  uVar2 = FUN_001a7bca(uVar2,8);
  puVar1[3] = uVar2;
  param_1[0x49] = puVar1 + 1;
  return;
}

/* FUN_000ebec6 @ 0xebec6 (126 bytes) */
int FUN_000ebec6(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_000ebb06)(param_1,param_2);
  *param_1 = PTR_DAT_00213451 + 8;
  uVar2 = *(undefined4 *)(param_2 + 0xb8);
  puVar1 = (undefined4 *)FUN_001a7bca(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[4] = uVar2;
  puVar1[2] = 0;
  puVar1[1] = 2;
  uVar2 = FUN_001a7bca(uVar2,8);
  puVar1[3] = uVar2;
  param_1[0x49] = puVar1 + 1;
  return;
}

/* FUN_000ebf72 @ 0xebf72 (171 bytes) */
int FUN_000ebf72(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  ((int (*)())FUN_000ebb06)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc288;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4e] = 0;
  *(undefined1 *)(param_1 + 0x4f) = 1;
  *(undefined1 *)((int)param_1 + 0x13d) = 1;
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x128);
  *puVar2 = uVar1;
  puVar2 = puVar2 + 1;
  ((int (*)())FUN_000eb992)(puVar2,param_2);
  param_1[0x4b] = puVar2;
  FUN_000ea91c(param_1,puVar2);
  return;
}

/* FUN_000ec04c @ 0xec04c (171 bytes) */
int FUN_000ec04c(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  ((int (*)())FUN_000ebb06)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc288;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4e] = 0;
  *(undefined1 *)(param_1 + 0x4f) = 1;
  *(undefined1 *)((int)param_1 + 0x13d) = 1;
  uVar1 = *(undefined4 *)(param_2 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x128);
  *puVar2 = uVar1;
  puVar2 = puVar2 + 1;
  ((int (*)())FUN_000eb992)(puVar2,param_2);
  param_1[0x4b] = puVar2;
  FUN_000ea91c(param_1,puVar2);
  return;
}

/* FUN_000ec126 @ 0xec126 (307 bytes) */
int FUN_000ec126(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  ((int (*)())FUN_000ebb06)(param_1,param_5);
  *param_1 = &PTR_FUN_001fc288;
  param_1[0x4a] = param_2;
  param_1[0x4b] = param_4;
  param_1[0x4c] = 0;
  param_1[0x4e] = param_3;
  *(undefined1 *)(param_1 + 0x4f) = 1;
  *(undefined1 *)((int)param_1 + 0x13d) = 1;
  *(undefined1 *)(param_1 + 0x51) = 0;
  param_1[0x52] = 0;
  if (param_1[0x4b] == 0) {
    uVar1 = *(undefined4 *)(param_5 + 0xb8);
    puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x128);
    *puVar2 = uVar1;
    ((int (*)())FUN_000eb992)(puVar2 + 1,param_5);
    param_1[0x4b] = puVar2 + 1;
  }
  FUN_000ea91c(param_1,param_1[0x4b]);
  FUN_000e9512(param_1,param_1[0x4a]);
  uVar1 = *(undefined4 *)(param_5 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,300);
  *puVar2 = uVar1;
  ((int (*)())FUN_000ebb06)(puVar2 + 1,param_5);
  puVar2[1] = &PTR_FUN_001fc348;
  puVar2[0x4a] = param_1;
  param_1[0x4d] = puVar2 + 1;
  return;
}

/* FUN_000ec2a0 @ 0xec2a0 (732 bytes) */
int FUN_000ec2a0(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  
  ((int (*)())FUN_000ebb06)(param_1,param_5);
  *param_1 = &PTR_FUN_001fc168;
  param_1[0x49] = 0;
  *(undefined1 *)(param_1 + 0x4b) = 0;
  param_1[0x4c] = 0;
  *(undefined1 *)(param_1 + 0x4d) = 0;
  *(undefined1 *)((int)param_1 + 0x135) = 0;
  *(char *)((int)param_1 + 0x136) = param_4;
  param_1[0x4f] = param_3;
  uVar4 = *(undefined4 *)(param_5 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar4,300);
  *puVar2 = uVar4;
  ((int (*)())FUN_000ebb06)(puVar2 + 1,param_5);
  puVar2[1] = &PTR_FUN_001fc1c8;
  puVar2[0x4a] = param_1;
  param_1[0x50] = puVar2 + 1;
  uVar4 = *(undefined4 *)(param_5 + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar4,300);
  *puVar3 = uVar4;
  puVar2 = puVar3 + 1;
  ((int (*)())FUN_000ebb06)(puVar2,param_5);
  *puVar2 = &PTR_FUN_001fc228;
  puVar3[0x4a] = param_1;
  param_1[0x51] = puVar2;
  FUN_000ea91c(param_1[0x50],param_1);
  if (param_4 == '\0') {
    uVar4 = FUN_0010a17a(0x81,param_5);
    param_1[0x4e] = uVar4;
    iVar5 = FUN_0010b0f4(uVar4,0);
    *(undefined4 *)(iVar5 + 8) = param_2;
    *(undefined4 *)(iVar5 + 0xc) = 0x27;
    uVar4 = FUN_0012eb84(*(undefined4 *)(*(int *)(param_5 + 0x3f4) + 0x3a0),4,param_2,0);
    FUN_0010a3c2(param_1[0x4e],1,uVar4);
  }
  else {
    uVar4 = *(undefined4 *)(param_5 + 0xb8);
    puVar2 = (undefined4 *)FUN_001a7bca(uVar4,0x168);
    *puVar2 = uVar4;
    puVar2 = puVar2 + 1;
    FUN_0010ac30(puVar2,0xfd,param_5);
    param_1[0x4e] = puVar2;
    iVar5 = FUN_0010b0f4(puVar2,0);
    *(undefined4 *)(iVar5 + 8) = param_2;
    *(undefined4 *)(iVar5 + 0xc) = 0x27;
    iVar5 = FUN_0012eb84(*(undefined4 *)(*(int *)(param_5 + 0x3f4) + 0x3a0),4,0,0);
    piVar6 = *(int **)(iVar5 + 0x18);
    if (*piVar6 == 0) {
      piVar6 = (int *)FUN_001a7f7c(piVar6,0);
    }
    else {
      if (piVar6[1] == 0) {
        *(undefined4 *)piVar6[2] = 0;
        piVar6[1] = 1;
      }
      piVar6 = (int *)piVar6[2];
    }
    iVar1 = *piVar6;
    *(undefined4 *)(iVar1 + 0x20) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x1c) = 3;
    *(byte *)(iVar1 + 0x15c) = *(byte *)(iVar1 + 0x15c) | 1;
    FUN_0010a3c2(param_1[0x4e],1,iVar5);
    iVar5 = FUN_0010b0f4(param_1[0x4e],1);
    *(undefined4 *)(iVar5 + 0x10) = DAT_001c64f0;
  }
  FUN_000e9512(param_1,param_1[0x4e]);
  return;
}

/* FUN_000ec5c2 @ 0xec5c2 (46 bytes) */
int FUN_000ec5c2(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000ebb06)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc4c8;
  return;
}

/* FUN_000ec5f0 @ 0xec5f0 (46 bytes) */
int FUN_000ec5f0(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000ebb06)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc4c8;
  return;
}

/* FUN_000ec61e @ 0xec61e (58 bytes) */
int FUN_000ec61e(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000ebb06)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc528;
  param_1[0x49] = param_1[0x32];
  return;
}

/* FUN_000ec658 @ 0xec658 (58 bytes) */
int FUN_000ec658(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000ebb06)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc528;
  param_1[0x49] = param_1[0x32];
  return;
}

/* FUN_000ec692 @ 0xec692 (75 bytes) */
int FUN_000ec692(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  ((int (*)())FUN_000eb832)(param_1,param_2);
  *param_1 = PTR_DAT_0021344d + 8;
  param_1[0x49] = *(undefined4 *)(param_2 + 0x124);
  param_1[0x4a] = *(undefined4 *)(param_2 + 0x128);
  return;
}

/* FUN_000ec6de @ 0xec6de (75 bytes) */
int FUN_000ec6de(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  ((int (*)())FUN_000eb832)(param_1,param_2);
  *param_1 = PTR_DAT_0021344d + 8;
  param_1[0x49] = *(undefined4 *)(param_2 + 0x124);
  param_1[0x4a] = *(undefined4 *)(param_2 + 0x128);
  return;
}

/* FUN_000ec72a @ 0xec72a (50 bytes) */
int FUN_000ec72a(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000eb832)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc228;
  param_1[3] = param_1[3] | 0x20;
  return;
}

/* FUN_000ec75c @ 0xec75c (68 bytes) */
int FUN_000ec75c(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,300);
  *puVar2 = uVar1;
  ((int (*)())FUN_000ec72a)(puVar2 + 1,param_1);
  return puVar2 + 1;
}

/* FUN_000ec7be @ 0xec7be (50 bytes) */
int FUN_000ec7be(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000eb832)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc228;
  param_1[3] = param_1[3] | 0x20;
  return;
}

/* FUN_000ec7f0 @ 0xec7f0 (50 bytes) */
int FUN_000ec7f0(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000eb832)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc1c8;
  param_1[3] = param_1[3] | 0x20;
  return;
}

/* FUN_000ec822 @ 0xec822 (68 bytes) */
int FUN_000ec822(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,300);
  *puVar2 = uVar1;
  ((int (*)())FUN_000ec7f0)(puVar2 + 1,param_1);
  return puVar2 + 1;
}

/* FUN_000ec884 @ 0xec884 (50 bytes) */
int FUN_000ec884(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000eb832)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc1c8;
  param_1[3] = param_1[3] | 0x20;
  return;
}

/* FUN_000ec8b6 @ 0xec8b6 (128 bytes) */
int FUN_000ec8b6(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  ((int (*)())FUN_000eb832)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc168;
  param_1[0x49] = *(undefined4 *)(param_2 + 0x124);
  *(undefined1 *)(param_1 + 0x4b) = *(undefined1 *)(param_2 + 300);
  param_1[0x4c] = *(undefined4 *)(param_2 + 0x130);
  *(undefined1 *)(param_1 + 0x4d) = *(undefined1 *)(param_2 + 0x134);
  *(undefined1 *)((int)param_1 + 0x135) = *(undefined1 *)(param_2 + 0x135);
  *(undefined1 *)((int)param_1 + 0x136) = *(undefined1 *)(param_2 + 0x136);
  param_1[3] = param_1[3] | 0x20;
  return;
}

/* FUN_000ec936 @ 0xec936 (68 bytes) */
int FUN_000ec936(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x14c);
  *puVar2 = uVar1;
  ((int (*)())FUN_000ec8b6)(puVar2 + 1,param_1);
  return puVar2 + 1;
}

/* FUN_000ec998 @ 0xec998 (128 bytes) */
int FUN_000ec998(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  ((int (*)())FUN_000eb832)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc168;
  param_1[0x49] = *(undefined4 *)(param_2 + 0x124);
  *(undefined1 *)(param_1 + 0x4b) = *(undefined1 *)(param_2 + 300);
  param_1[0x4c] = *(undefined4 *)(param_2 + 0x130);
  *(undefined1 *)(param_1 + 0x4d) = *(undefined1 *)(param_2 + 0x134);
  *(undefined1 *)((int)param_1 + 0x135) = *(undefined1 *)(param_2 + 0x135);
  *(undefined1 *)((int)param_1 + 0x136) = *(undefined1 *)(param_2 + 0x136);
  param_1[3] = param_1[3] | 0x20;
  return;
}

/* FUN_000eca18 @ 0xeca18 (46 bytes) */
int FUN_000eca18(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000eb832)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc348;
  return;
}

/* FUN_000eca46 @ 0xeca46 (68 bytes) */
int FUN_000eca46(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,300);
  *puVar2 = uVar1;
  ((int (*)())FUN_000eca18)(puVar2 + 1,param_1);
  return puVar2 + 1;
}

/* FUN_000ecaa8 @ 0xecaa8 (46 bytes) */
int FUN_000ecaa8(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000eb832)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc348;
  return;
}

/* FUN_000ecad6 @ 0xecad6 (101 bytes) */
int FUN_000ecad6(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  ((int (*)())FUN_000eb832)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc288;
  *(undefined1 *)(param_1 + 0x4f) = *(undefined1 *)(param_2 + 0x13c);
  *(undefined1 *)((int)param_1 + 0x13d) = *(undefined1 *)(param_2 + 0x13d);
  param_1[0x50] = 0;
  *(undefined1 *)(param_1 + 0x51) = 0;
  param_1[0x52] = 0;
  return;
}

/* FUN_000ecb3c @ 0xecb3c (68 bytes) */
int FUN_000ecb3c(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x150);
  *puVar2 = uVar1;
  ((int (*)())FUN_000ecad6)(puVar2 + 1,param_1);
  return puVar2 + 1;
}

/* FUN_000ecb9e @ 0xecb9e (101 bytes) */
int FUN_000ecb9e(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  ((int (*)())FUN_000eb832)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc288;
  *(undefined1 *)(param_1 + 0x4f) = *(undefined1 *)(param_2 + 0x13c);
  *(undefined1 *)((int)param_1 + 0x13d) = *(undefined1 *)(param_2 + 0x13d);
  param_1[0x50] = 0;
  *(undefined1 *)(param_1 + 0x51) = 0;
  param_1[0x52] = 0;
  return;
}

/* FUN_000ecc04 @ 0xecc04 (60 bytes) */
int FUN_000ecc04(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  ((int (*)())FUN_000eb832)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc108;
  param_1[0x49] = *(undefined4 *)(param_2 + 0x124);
  return;
}

/* FUN_000ecc40 @ 0xecc40 (68 bytes) */
int FUN_000ecc40(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,300);
  *puVar2 = uVar1;
  ((int (*)())FUN_000ecc04)(puVar2 + 1,param_1);
  return puVar2 + 1;
}

/* FUN_000ecca2 @ 0xecca2 (60 bytes) */
int FUN_000ecca2(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  ((int (*)())FUN_000eb832)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc108;
  param_1[0x49] = *(undefined4 *)(param_2 + 0x124);
  return;
}

/* FUN_000eccde @ 0xeccde (732 bytes) */
int FUN_000eccde(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  
  ((int (*)())FUN_000ebb06)(param_1,param_5);
  *param_1 = &PTR_FUN_001fc168;
  param_1[0x49] = 0;
  *(undefined1 *)(param_1 + 0x4b) = 0;
  param_1[0x4c] = 0;
  *(undefined1 *)(param_1 + 0x4d) = 0;
  *(undefined1 *)((int)param_1 + 0x135) = 0;
  *(char *)((int)param_1 + 0x136) = param_4;
  param_1[0x4f] = param_3;
  uVar4 = *(undefined4 *)(param_5 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar4,300);
  *puVar2 = uVar4;
  ((int (*)())FUN_000ebb06)(puVar2 + 1,param_5);
  puVar2[1] = &PTR_FUN_001fc1c8;
  puVar2[0x4a] = param_1;
  param_1[0x50] = puVar2 + 1;
  uVar4 = *(undefined4 *)(param_5 + 0xb8);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar4,300);
  *puVar3 = uVar4;
  puVar2 = puVar3 + 1;
  ((int (*)())FUN_000ebb06)(puVar2,param_5);
  *puVar2 = &PTR_FUN_001fc228;
  puVar3[0x4a] = param_1;
  param_1[0x51] = puVar2;
  FUN_000ea91c(param_1[0x50],param_1);
  if (param_4 == '\0') {
    uVar4 = FUN_0010a17a(0x81,param_5);
    param_1[0x4e] = uVar4;
    iVar5 = FUN_0010b0f4(uVar4,0);
    *(undefined4 *)(iVar5 + 8) = param_2;
    *(undefined4 *)(iVar5 + 0xc) = 0x27;
    uVar4 = FUN_0012eb84(*(undefined4 *)(*(int *)(param_5 + 0x3f4) + 0x3a0),4,param_2,0);
    FUN_0010a3c2(param_1[0x4e],1,uVar4);
  }
  else {
    uVar4 = *(undefined4 *)(param_5 + 0xb8);
    puVar2 = (undefined4 *)FUN_001a7bca(uVar4,0x168);
    *puVar2 = uVar4;
    puVar2 = puVar2 + 1;
    FUN_0010ac30(puVar2,0xfd,param_5);
    param_1[0x4e] = puVar2;
    iVar5 = FUN_0010b0f4(puVar2,0);
    *(undefined4 *)(iVar5 + 8) = param_2;
    *(undefined4 *)(iVar5 + 0xc) = 0x27;
    iVar5 = FUN_0012eb84(*(undefined4 *)(*(int *)(param_5 + 0x3f4) + 0x3a0),4,0,0);
    piVar6 = *(int **)(iVar5 + 0x18);
    if (*piVar6 == 0) {
      piVar6 = (int *)FUN_001a7f7c(piVar6,0);
    }
    else {
      if (piVar6[1] == 0) {
        *(undefined4 *)piVar6[2] = 0;
        piVar6[1] = 1;
      }
      piVar6 = (int *)piVar6[2];
    }
    iVar1 = *piVar6;
    *(undefined4 *)(iVar1 + 0x20) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x1c) = 3;
    *(byte *)(iVar1 + 0x15c) = *(byte *)(iVar1 + 0x15c) | 1;
    FUN_0010a3c2(param_1[0x4e],1,iVar5);
    iVar5 = FUN_0010b0f4(param_1[0x4e],1);
    *(undefined4 *)(iVar5 + 0x10) = DAT_001c64f0;
  }
  FUN_000e9512(param_1,param_1[0x4e]);
  return;
}

/* FUN_000ed000 @ 0xed000 (307 bytes) */
int FUN_000ed000(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  ((int (*)())FUN_000ebb06)(param_1,param_5);
  *param_1 = &PTR_FUN_001fc288;
  param_1[0x4a] = param_2;
  param_1[0x4b] = param_4;
  param_1[0x4c] = 0;
  param_1[0x4e] = param_3;
  *(undefined1 *)(param_1 + 0x4f) = 1;
  *(undefined1 *)((int)param_1 + 0x13d) = 1;
  *(undefined1 *)(param_1 + 0x51) = 0;
  param_1[0x52] = 0;
  if (param_1[0x4b] == 0) {
    uVar1 = *(undefined4 *)(param_5 + 0xb8);
    puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x128);
    *puVar2 = uVar1;
    ((int (*)())FUN_000eb992)(puVar2 + 1,param_5);
    param_1[0x4b] = puVar2 + 1;
  }
  FUN_000ea91c(param_1,param_1[0x4b]);
  FUN_000e9512(param_1,param_1[0x4a]);
  uVar1 = *(undefined4 *)(param_5 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,300);
  *puVar2 = uVar1;
  ((int (*)())FUN_000ebb06)(puVar2 + 1,param_5);
  puVar2[1] = &PTR_FUN_001fc348;
  puVar2[0x4a] = param_1;
  param_1[0x4d] = puVar2 + 1;
  return;
}

/* FUN_000ed17a @ 0xed17a (46 bytes) */
int FUN_000ed17a(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000ecaa8)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc3a8;
  return;
}

/* FUN_000ed1a8 @ 0xed1a8 (46 bytes) */
int FUN_000ed1a8(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000ecaa8)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc3a8;
  return;
}

/* FUN_000ed1d6 @ 0xed1d6 (68 bytes) */
int FUN_000ed1d6(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,300);
  *puVar2 = uVar1;
  ((int (*)())FUN_000ed1a8)(puVar2 + 1,param_1);
  return puVar2 + 1;
}

/* FUN_000ed238 @ 0xed238 (46 bytes) */
int FUN_000ed238(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000ecb9e)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc2e8;
  return;
}

/* FUN_000ed266 @ 0xed266 (46 bytes) */
int FUN_000ed266(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000ecb9e)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc2e8;
  return;
}

/* FUN_000ed294 @ 0xed294 (68 bytes) */
int FUN_000ed294(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x150);
  *puVar2 = uVar1;
  ((int (*)())FUN_000ed266)(puVar2 + 1,param_1);
  return puVar2 + 1;
}

/* FUN_000ed2f6 @ 0xed2f6 (161 bytes) */
int FUN_000ed2f6(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  ((int (*)())FUN_000ec04c)(param_1,param_4);
  *param_1 = &PTR_FUN_001fc2e8;
  param_1[0x4a] = param_2;
  FUN_000e9512(param_1,param_2);
  param_1[0x4e] = param_3;
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,300);
  *puVar2 = uVar1;
  ((int (*)())FUN_000ebb06)(puVar2 + 1,param_4);
  puVar2[0x4a] = param_1;
  puVar2[1] = &PTR_FUN_001fc3a8;
  param_1[0x4d] = puVar2 + 1;
  return;
}

/* FUN_000ed3cc @ 0xed3cc (161 bytes) */
int FUN_000ed3cc(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  ((int (*)())FUN_000ec04c)(param_1,param_4);
  *param_1 = &PTR_FUN_001fc2e8;
  param_1[0x4a] = param_2;
  FUN_000e9512(param_1,param_2);
  param_1[0x4e] = param_3;
  uVar1 = *(undefined4 *)(param_4 + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,300);
  *puVar2 = uVar1;
  ((int (*)())FUN_000ebb06)(puVar2 + 1,param_4);
  puVar2[0x4a] = param_1;
  puVar2[1] = &PTR_FUN_001fc3a8;
  param_1[0x4d] = puVar2 + 1;
  return;
}

/* FUN_000ed4a2 @ 0xed4a2 (365 bytes) */
int FUN_000ed4a2(param_1)
  undefined4 *param_1;
{
  int iVar1;
  
  *param_1 = &PTR_FUN_001fc0a8;
  iVar1 = param_1[0x35];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x34];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x3c];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x3d];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x31];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  FUN_001a7d34(param_1 + 0x24);
  param_1[0x27] = PTR_DAT_00213441 + 8;
  param_1[0x24] = PTR_DAT_00213441 + 8;
  *param_1 = PTR_DAT_00213441 + 8;
  return;
}

/* FUN_000ed642 @ 0xed642 (397 bytes) */
int FUN_000ed642(param_1)
  undefined4 *param_1;
{
  int iVar1;
  
  *param_1 = &PTR_FUN_001fc0a8;
  iVar1 = param_1[0x35];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x34];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x3c];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x3d];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x31];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  FUN_001a7d34(param_1 + 0x24);
  param_1[0x27] = PTR_DAT_00213441 + 8;
  param_1[0x24] = PTR_DAT_00213441 + 8;
  *param_1 = PTR_DAT_00213441 + 8;
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_000ed800 @ 0xed800 (46 bytes) */
int FUN_000ed800(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000ec6de)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc408;
  return;
}

/* FUN_000ed82e @ 0xed82e (46 bytes) */
int FUN_000ed82e(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000ec6de)(param_1,param_2);
  *param_1 = &PTR_FUN_001fc408;
  return;
}

/* FUN_000ed85c @ 0xed85c (68 bytes) */
int FUN_000ed85c(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0xb8);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0x130);
  *puVar2 = uVar1;
  ((int (*)())FUN_000ed82e)(puVar2 + 1,param_1);
  return puVar2 + 1;
}

