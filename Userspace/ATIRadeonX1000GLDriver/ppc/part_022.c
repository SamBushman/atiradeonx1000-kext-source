#include "decls.h"

/* FUN_000e4c40 @ 0xe4c40 (1764 bytes) */
int FUN_000e4c40(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int *piVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  void *pvVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  
  *(undefined4 *)(param_1 + 0x60) = 0;
  *param_2 = *param_2 + 1;
  iVar6 = FUN_000e4a38();
  if (iVar6 == 0) {
    *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
    if ((*(int *)(param_1 + 0x30) != 0) && (*(int *)(param_1 + 0x84) == 0)) {
      *(undefined4 *)(param_1 + 0x84) = 1;
      *(undefined4 *)(param_1 + 0x7c) = 3;
      *(undefined4 *)(param_1 + 0x80) = 0;
      return 1;
    }
    return 0;
  }
  uVar7 = FUN_000e4408(param_1);
  puVar15 = (uint *)(param_1 + 0x8c);
  iVar6 = FUN_000f89a4(uVar7,*(undefined4 *)(*(int *)(param_3 + 0x30c) + 0xc));
  if (iVar6 == 6) {
    *(ushort *)(param_1 + 0x8e) =
         ((ushort)((uint)*(undefined4 *)(param_1 + 0x8c) >> 0x10) & 0x3fff) + 0xcf;
    uVar7 = FUN_000e4408(param_1);
  }
  switch(uVar7) {
  case 0x76:
    if ((int)*puVar15 < 0) {
      iVar5 = *(int *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x58) = 2;
      iVar6 = *(int *)(param_1 + 0x74);
      *param_2 = *param_2 + 1;
      FUN_000e4a38(param_1);
      iVar8 = *param_2;
      iVar12 = 0;
      iVar10 = *(int *)(iVar8 * 4 + param_1 + 0x88);
      if (0 < iVar10) {
        while( true ) {
          iVar12 = iVar12 + 1;
          FUN_000e4a38(param_1,iVar8);
          if (iVar10 == iVar12) break;
          iVar8 = *param_2;
        }
        iVar8 = *param_2;
      }
      *(int *)(iVar8 * 4 + param_1 + 0x8c) = iVar6 - iVar5 >> 2;
      return 1;
    }
    break;
  case 0x77:
  case 0x78:
  case 0x79:
  case 0x7a:
  case 0x7b:
  case 0x7c:
  case 0x7e:
  case 0x7f:
  case 0x80:
  case 0x81:
  case 0x82:
  case 0x83:
  case 0x84:
  case 0x85:
  case 0x89:
    uVar3 = *puVar15;
    goto LAB_000e4e4c;
  case 0x7d:
    break;
  case 0x86:
  case 0x88:
  case 0x8a:
  case 0x8b:
  case 0x8c:
  case 0x8d:
    uVar3 = *puVar15;
    if ((uVar3 & 0x20000000) == 0) goto LAB_000e4e4c;
    iVar5 = 2;
    *(undefined4 *)(param_1 + 0x60) = 1;
    uVar3 = *puVar15;
    goto LAB_000e4e50;
  case 0x87:
    iVar6 = 1;
    goto LAB_000e4e74;
  default:
    uVar3 = *(uint *)(param_1 + 0x8c);
LAB_000e4e4c:
    iVar5 = 1;
LAB_000e4e50:
    if ((int)uVar3 < 0) {
      iVar5 = iVar5 + 1;
    }
    iVar6 = iVar5 + -1;
    if ((uVar3 & 0x40000000) != 0) {
      iVar6 = iVar5;
    }
    if (0 < iVar6) {
LAB_000e4e74:
      iVar5 = 0;
      do {
        iVar5 = iVar5 + 1;
        *param_2 = *param_2 + 1;
        FUN_000e4a38(param_1);
      } while (iVar6 != iVar5);
    }
  }
  iVar5 = FUN_000f8960(uVar7,*(undefined4 *)(*(int *)(param_3 + 0x30c) + 0xc));
  iVar8 = FUN_000f8970(uVar7,*(undefined4 *)(*(int *)(param_3 + 0x30c) + 0xc));
  uVar9 = FUN_000f8994(uVar7,*(undefined4 *)(*(int *)(param_3 + 0x30c) + 0xc));
  *(undefined4 *)(param_1 + 0x5c) = uVar9;
  iVar10 = FUN_000e4710(uVar7,0,*(undefined4 *)(*(int *)(param_3 + 0x30c) + 0xc));
  iVar12 = *param_2;
  iVar6 = iVar12;
  if (iVar5 < 1) goto LAB_000e50f4;
  **(int **)(param_1 + 100) = iVar12 * 4 + param_1 + 0x8c;
  *param_2 = *param_2 + 1;
  FUN_000e4a38(param_1);
  iVar6 = *param_2;
  iVar16 = param_1 + iVar6 * 4 + 0x7c;
  uVar3 = *(uint *)(iVar16 + 0xc);
  if ((uVar3 & 0x400000) != 0) {
    *param_2 = iVar6 + 1;
    FUN_000e4a38(param_1,iVar6);
    iVar6 = *param_2;
    uVar3 = *(uint *)(iVar16 + 0xc);
  }
  if ((uVar3 & 0x23f0000) == 0x21e0000) {
    *param_2 = iVar6 + 1;
    FUN_000e4a38(param_1,iVar6);
    uVar3 = *(uint *)(iVar16 + 0xc);
    iVar6 = *param_2;
  }
  if ((uVar3 & 0x1800000) == 0x800000) {
LAB_000e5044:
    *param_2 = iVar6 + 1;
    FUN_000e4a38(param_1,iVar6);
    iVar6 = *param_2;
  }
  else if ((uVar3 & 0x1800000) == 0x1000000) {
    *param_2 = iVar6 + 1;
    FUN_000e4a38(param_1,iVar6);
    iVar6 = *param_2;
    iVar13 = param_1 + iVar6 * 4 + 0x7c;
    uVar3 = *(uint *)(iVar13 + 0xc);
    if ((uVar3 & 0x400000) != 0) {
      *param_2 = iVar6 + 1;
      FUN_000e4a38(param_1,iVar6);
      iVar6 = *param_2;
      uVar3 = *(uint *)(iVar13 + 0xc);
    }
    if (((uVar3 & 0x1800000) == 0) && (uVar4 = 0, (uVar3 & 0x2000000) != 0)) {
      while( true ) {
        *param_2 = iVar6 + 1;
        FUN_000e4a38(param_1,iVar6);
        uVar3 = *(uint *)(iVar13 + 0xc);
        uVar4 = uVar4 + 1;
        if ((uVar3 >> 0x19 & 1) <= uVar4) break;
        iVar6 = *param_2;
      }
      iVar6 = *param_2;
    }
    else {
      uVar3 = *(uint *)(iVar13 + 0xc);
    }
    if ((uVar3 & 0x4000000) != 0) goto LAB_000e5044;
  }
  if ((*(uint *)(iVar16 + 0xc) & 0x4000000) != 0) {
    *param_2 = iVar6 + 1;
    FUN_000e4a38(param_1,iVar6);
    iVar6 = *param_2;
  }
  if (0 < iVar10) {
    iVar13 = 0;
    iVar14 = 0x14;
    iVar17 = 100;
    do {
      *(int *)(iVar14 + *(int *)(param_1 + 100)) = iVar17 + *(int *)(param_1 + 0x68);
      _memcpy((void *)(iVar17 + *(int *)(param_1 + 0x68)),(void *)**(undefined4 **)(param_1 + 100),
              (iVar6 - iVar12) * 4);
      iVar17 = iVar17 + 100;
      sVar2 = (short)iVar13;
      iVar13 = iVar13 + 1;
      piVar1 = (int *)(iVar14 + *(int *)(param_1 + 100));
      iVar14 = iVar14 + 0x14;
      *(short *)(*piVar1 + 2) = sVar2 + *(short *)(iVar16 + 0xe) + 1;
    } while (iVar10 != iVar13);
    iVar6 = *param_2;
  }
LAB_000e50f4:
  if (0 < iVar8) {
    iVar16 = 0;
    iVar12 = 0x14;
    iVar10 = iVar6;
    do {
      iVar13 = iVar16 * 4;
      iVar14 = FUN_000e4710(uVar7,iVar5 + iVar16,*(undefined4 *)(*(int *)(param_3 + 0x30c) + 0xc));
      *(int *)(*(int *)(param_1 + 0x6c) + iVar13) = iVar10 * 4 + param_1 + 0x8c;
      *param_2 = *param_2 + 1;
      FUN_000e4a38(param_1);
      uVar3 = **(uint **)(iVar13 + *(int *)(param_1 + 0x6c)) >> 0x19 & 1;
      if (uVar3 == 0xffffffff) {
        iVar6 = *param_2;
      }
      else {
        iVar6 = *param_2;
        iVar17 = 0;
LAB_000e5190:
        iVar18 = param_1 + iVar6 * 4 + 0x7c;
        uVar4 = *(uint *)(iVar18 + 0xc);
        if ((uVar4 & 0x400000) != 0) {
          *param_2 = iVar6 + 1;
          FUN_000e4a38(param_1,iVar6);
          uVar4 = *(uint *)(iVar18 + 0xc);
          iVar6 = *param_2;
        }
        uVar4 = uVar4 & 0x1800000;
        if (uVar4 != 0) {
          if (uVar4 == 0x800000) {
LAB_000e523c:
            *param_2 = iVar6 + 1;
            FUN_000e4a38(param_1,iVar6);
            iVar6 = *param_2;
          }
          else if (uVar4 == 0x1000000) {
            *param_2 = iVar6 + 1;
            FUN_000e4a38(param_1,iVar6);
            iVar6 = *param_2;
            iVar19 = param_1 + iVar6 * 4 + 0x7c;
            uVar4 = *(uint *)(iVar19 + 0xc);
            if ((uVar4 & 0x400000) != 0) {
              *param_2 = iVar6 + 1;
              FUN_000e4a38(param_1,iVar6);
              uVar4 = *(uint *)(iVar19 + 0xc);
              iVar6 = *param_2;
            }
            if ((uVar4 & 0x4000000) != 0) goto LAB_000e523c;
          }
        }
        if ((*(uint *)(iVar18 + 0xc) & 0x4000000) != 0) {
          *param_2 = iVar6 + 1;
          FUN_000e4a38(param_1,iVar6);
          iVar6 = *param_2;
        }
        iVar17 = iVar17 + 1;
        if (iVar17 != uVar3 + 1) {
          if (0 < iVar17) {
            *param_2 = iVar6 + 1;
            FUN_000e4a38(param_1,iVar6);
            iVar6 = *param_2;
          }
          goto LAB_000e5190;
        }
      }
      if (0 < iVar14) {
        iVar19 = iVar12 * 5;
        iVar18 = 0;
        iVar17 = iVar12;
        do {
          *(int *)(*(int *)(param_1 + 0x6c) + iVar17) = iVar19 + *(int *)(param_1 + 0x70);
          pvVar11 = (void *)(iVar19 + *(int *)(param_1 + 0x70));
          iVar19 = iVar19 + 100;
          _memcpy(pvVar11,*(void **)(iVar13 + *(int *)(param_1 + 0x6c)),(iVar6 - iVar10) * 4);
          piVar1 = (int *)(*(int *)(param_1 + 0x6c) + iVar17);
          iVar17 = iVar17 + 0x14;
          sVar2 = (short)iVar18;
          iVar18 = iVar18 + 1;
          *(short *)(*piVar1 + 2) =
               sVar2 + *(short *)(*(int *)(iVar13 + *(int *)(param_1 + 0x6c)) + 2) + 1;
        } while (iVar14 != iVar18);
        iVar6 = *param_2;
      }
      iVar16 = iVar16 + 1;
      iVar12 = iVar12 + 4;
      iVar10 = iVar6;
    } while (iVar8 != iVar16);
  }
  *(int *)(param_1 + 0x58) = iVar6;
  if (0 < *(int *)(param_1 + 0x5c)) {
    iVar6 = 0;
    do {
      *param_2 = *param_2 + 1;
      FUN_000e4a38(param_1);
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 0x5c));
  }
  return 1;
}

/* FUN_000e5384 @ 0xe5384 (248 bytes) */
int FUN_000e5384(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint *puVar7;
  
  iVar1 = param_3 * 4 + param_1;
  uVar4 = *(undefined4 *)(param_1 + 0x80);
  uVar3 = *(undefined4 *)(param_1 + 0x7c);
  *(undefined2 *)(param_1 + 0x8e) = param_2;
  *(int *)(iVar1 + 0xa4) = *(int *)(param_1 + 0x74) - *(int *)(param_1 + 0x2c) >> 2;
  *(undefined4 *)(iVar1 + 0x8c) = param_4;
  *(undefined4 *)(iVar1 + 0x90) = param_5;
  *(undefined4 *)(iVar1 + 0x94) = 0x29;
  *(undefined4 *)(iVar1 + 0x98) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x9c) = uVar4;
  *(undefined4 *)(iVar1 + 0xa0) = uVar3;
  if (-1 < param_3 + 6) {
    iVar1 = 0;
    puVar5 = (undefined4 *)((param_3 + 6) * 4 + param_1 + 0x8c);
    do {
      puVar7 = *(uint **)(param_1 + 0x88);
      uVar3 = *puVar5;
      uVar6 = puVar7[1];
      if (uVar6 < *puVar7) {
        _memset((void *)(uVar6 * 4 + puVar7[2]),0,4);
        puVar2 = (undefined4 *)(uVar6 * 4 + puVar7[2]);
        puVar7[1] = uVar6 + 1;
      }
      else {
        puVar2 = (undefined4 *)FUN_0019423c(puVar7,uVar6);
      }
      iVar1 = iVar1 + 1;
      *puVar2 = uVar3;
      puVar5 = puVar5 + -1;
    } while (param_3 + 7 != iVar1);
  }
  *(undefined4 *)(param_1 + 0x7c) = 1;
  return;
}

/* FUN_000e547c @ 0xe547c (244 bytes) */
int FUN_000e547c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint *puVar7;
  
  iVar1 = param_3 * 4 + param_1;
  uVar4 = *(undefined4 *)(param_1 + 0x80);
  uVar3 = *(undefined4 *)(param_1 + 0x7c);
  *(undefined2 *)(param_1 + 0x8e) = param_2;
  *(int *)(iVar1 + 0xa0) = *(int *)(param_1 + 0x74) - *(int *)(param_1 + 0x2c) >> 2;
  *(undefined4 *)(iVar1 + 0x8c) = param_4;
  *(undefined4 *)(iVar1 + 0x90) = 0x29;
  *(undefined4 *)(iVar1 + 0x94) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x98) = uVar4;
  *(undefined4 *)(iVar1 + 0x9c) = uVar3;
  if (-1 < param_3 + 5) {
    iVar1 = 0;
    puVar5 = (undefined4 *)((param_3 + 5) * 4 + param_1 + 0x8c);
    do {
      puVar7 = *(uint **)(param_1 + 0x88);
      uVar3 = *puVar5;
      uVar6 = puVar7[1];
      if (uVar6 < *puVar7) {
        _memset((void *)(uVar6 * 4 + puVar7[2]),0,4);
        puVar2 = (undefined4 *)(uVar6 * 4 + puVar7[2]);
        puVar7[1] = uVar6 + 1;
      }
      else {
        puVar2 = (undefined4 *)FUN_0019423c(puVar7,uVar6);
      }
      iVar1 = iVar1 + 1;
      *puVar2 = uVar3;
      puVar5 = puVar5 + -1;
    } while (param_3 + 6 != iVar1);
  }
  *(undefined4 *)(param_1 + 0x7c) = 1;
  return;
}

/* FUN_000e5570 @ 0xe5570 (1060 bytes) */
int FUN_000e5570(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  
  param_1[0x1d] = param_2;
  param_1[9] = param_2;
  param_1[10] = param_2;
  *param_1 = param_3;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  uVar5 = *(undefined4 *)(param_3 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar5,0x14);
  *puVar1 = uVar5;
  puVar1[1] = 2;
  puVar1[2] = 0;
  puVar1[4] = uVar5;
  uVar5 = FUN_00193e18(uVar5,8);
  puVar1[3] = uVar5;
  param_1[0x22] = (int)(puVar1 + 1);
  uVar6 = puVar1[2];
  if (uVar6 < (uint)puVar1[1]) {
    _memset((void *)(uVar6 * 4 + puVar1[3]),0,4);
    puVar2 = (undefined4 *)(uVar6 * 4 + puVar1[3]);
    puVar1[2] = uVar6 + 1;
  }
  else {
    puVar2 = (undefined4 *)FUN_0019423c(puVar1 + 1,uVar6);
  }
  *puVar2 = 0;
  puVar7 = (uint *)param_1[0x22];
  uVar6 = puVar7[1];
  if (uVar6 < *puVar7) {
    _memset((void *)(uVar6 * 4 + puVar7[2]),0,4);
    puVar1 = (undefined4 *)(uVar6 * 4 + puVar7[2]);
    puVar7[1] = uVar6 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar7,uVar6);
  }
  *puVar1 = 2;
  puVar7 = (uint *)param_1[0x22];
  uVar6 = puVar7[1];
  if (uVar6 < *puVar7) {
    _memset((void *)(uVar6 * 4 + puVar7[2]),0,4);
    puVar1 = (undefined4 *)(uVar6 * 4 + puVar7[2]);
    puVar7[1] = uVar6 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar7,uVar6);
  }
  *puVar1 = 0;
  puVar7 = (uint *)param_1[0x22];
  uVar6 = puVar7[1];
  if (uVar6 < *puVar7) {
    _memset((void *)(uVar6 * 4 + puVar7[2]),0,4);
    puVar1 = (undefined4 *)(uVar6 * 4 + puVar7[2]);
    puVar7[1] = uVar6 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar7,uVar6);
  }
  *puVar1 = 0xffffffff;
  iVar3 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),0x50);
  param_1[0x19] = iVar3;
  iVar3 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),0x50);
  param_1[0x1b] = iVar3;
  iVar3 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),400);
  param_1[0x1a] = iVar3;
  iVar3 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),400);
  param_1[0x1c] = iVar3;
  uVar5 = *(undefined4 *)(*param_1 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar5,0x14);
  *puVar1 = uVar5;
  puVar1[1] = 2;
  puVar1[4] = uVar5;
  puVar1[2] = 0;
  uVar5 = FUN_00193e18(uVar5,8);
  puVar1[3] = uVar5;
  param_1[0xf] = (int)(puVar1 + 1);
  uVar5 = *(undefined4 *)(*param_1 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar5,0x14);
  *puVar1 = uVar5;
  puVar1[1] = 2;
  puVar1[4] = uVar5;
  puVar1[2] = 0;
  uVar5 = FUN_00193e18(uVar5,8);
  puVar1[3] = uVar5;
  param_1[0x11] = (int)(puVar1 + 1);
  uVar5 = *(undefined4 *)(*param_1 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar5,0x14);
  *puVar1 = uVar5;
  puVar1[1] = 2;
  puVar1[2] = 0;
  puVar1[4] = uVar5;
  uVar5 = FUN_00193e18(uVar5,8);
  puVar1[3] = uVar5;
  param_1[0x10] = (int)(puVar1 + 1);
  param_1[0x15] = 0;
  puVar1 = (undefined4 *)FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),0xc);
  param_1[3] = (int)puVar1;
  *puVar1 = 0xffffffff;
  *(undefined4 *)(param_1[3] + 4) = 0;
  *(undefined4 *)(param_1[3] + 8) = 0;
  iVar3 = param_1[3];
  param_1[4] = iVar3;
  *(int *)(iVar3 + 8) = iVar3;
  puVar1 = (undefined4 *)FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),0x18);
  param_1[7] = (int)puVar1;
  *puVar1 = 0xffffffff;
  *(undefined4 *)(param_1[7] + 4) = 0;
  *(undefined4 *)(param_1[7] + 8) = 0;
  *(undefined4 *)(param_1[7] + 0xc) = 0;
  *(undefined4 *)(param_1[7] + 0x10) = 0;
  *(undefined4 *)(param_1[7] + 0x14) = 0;
  iVar3 = param_1[7];
  param_1[8] = iVar3;
  *(int *)(iVar3 + 0x14) = iVar3;
  puVar1 = (undefined4 *)FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),0x18);
  param_1[5] = (int)puVar1;
  *puVar1 = 0xffffffff;
  *(undefined4 *)(param_1[5] + 4) = 0;
  *(undefined4 *)(param_1[5] + 8) = 0;
  *(undefined4 *)(param_1[5] + 0xc) = 0;
  *(undefined4 *)(param_1[5] + 0x10) = 0;
  *(undefined4 *)(param_1[5] + 0x14) = 0;
  iVar3 = param_1[5];
  param_1[6] = iVar3;
  *(int *)(iVar3 + 0x14) = iVar3;
  iVar3 = param_1[9];
  param_1[1] = iVar3;
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = iVar3 + 4;
    param_1[9] = iVar3;
  }
  param_1[2] = iVar3;
  iVar4 = 0;
  if (iVar3 != 0) {
    FUN_0019ee74(iVar3,*param_1);
    iVar4 = param_1[9] + 4;
    param_1[9] = iVar4;
  }
  param_1[0x1d] = iVar4;
  param_1[0xb] = iVar4;
  return;
}

/* FUN_000e59f0 @ 0xe59f0 (1060 bytes) */
int FUN_000e59f0(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  
  param_1[0x1d] = param_2;
  param_1[9] = param_2;
  param_1[10] = param_2;
  *param_1 = param_3;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  uVar5 = *(undefined4 *)(param_3 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar5,0x14);
  *puVar1 = uVar5;
  puVar1[1] = 2;
  puVar1[2] = 0;
  puVar1[4] = uVar5;
  uVar5 = FUN_00193e18(uVar5,8);
  puVar1[3] = uVar5;
  param_1[0x22] = (int)(puVar1 + 1);
  uVar6 = puVar1[2];
  if (uVar6 < (uint)puVar1[1]) {
    _memset((void *)(uVar6 * 4 + puVar1[3]),0,4);
    puVar2 = (undefined4 *)(uVar6 * 4 + puVar1[3]);
    puVar1[2] = uVar6 + 1;
  }
  else {
    puVar2 = (undefined4 *)FUN_0019423c(puVar1 + 1,uVar6);
  }
  *puVar2 = 0;
  puVar7 = (uint *)param_1[0x22];
  uVar6 = puVar7[1];
  if (uVar6 < *puVar7) {
    _memset((void *)(uVar6 * 4 + puVar7[2]),0,4);
    puVar1 = (undefined4 *)(uVar6 * 4 + puVar7[2]);
    puVar7[1] = uVar6 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar7,uVar6);
  }
  *puVar1 = 2;
  puVar7 = (uint *)param_1[0x22];
  uVar6 = puVar7[1];
  if (uVar6 < *puVar7) {
    _memset((void *)(uVar6 * 4 + puVar7[2]),0,4);
    puVar1 = (undefined4 *)(uVar6 * 4 + puVar7[2]);
    puVar7[1] = uVar6 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar7,uVar6);
  }
  *puVar1 = 0;
  puVar7 = (uint *)param_1[0x22];
  uVar6 = puVar7[1];
  if (uVar6 < *puVar7) {
    _memset((void *)(uVar6 * 4 + puVar7[2]),0,4);
    puVar1 = (undefined4 *)(uVar6 * 4 + puVar7[2]);
    puVar7[1] = uVar6 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar7,uVar6);
  }
  *puVar1 = 0xffffffff;
  iVar3 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),0x50);
  param_1[0x19] = iVar3;
  iVar3 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),0x50);
  param_1[0x1b] = iVar3;
  iVar3 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),400);
  param_1[0x1a] = iVar3;
  iVar3 = FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),400);
  param_1[0x1c] = iVar3;
  uVar5 = *(undefined4 *)(*param_1 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar5,0x14);
  *puVar1 = uVar5;
  puVar1[1] = 2;
  puVar1[4] = uVar5;
  puVar1[2] = 0;
  uVar5 = FUN_00193e18(uVar5,8);
  puVar1[3] = uVar5;
  param_1[0xf] = (int)(puVar1 + 1);
  uVar5 = *(undefined4 *)(*param_1 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar5,0x14);
  *puVar1 = uVar5;
  puVar1[1] = 2;
  puVar1[4] = uVar5;
  puVar1[2] = 0;
  uVar5 = FUN_00193e18(uVar5,8);
  puVar1[3] = uVar5;
  param_1[0x11] = (int)(puVar1 + 1);
  uVar5 = *(undefined4 *)(*param_1 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar5,0x14);
  *puVar1 = uVar5;
  puVar1[1] = 2;
  puVar1[2] = 0;
  puVar1[4] = uVar5;
  uVar5 = FUN_00193e18(uVar5,8);
  puVar1[3] = uVar5;
  param_1[0x10] = (int)(puVar1 + 1);
  param_1[0x15] = 0;
  puVar1 = (undefined4 *)FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),0xc);
  param_1[3] = (int)puVar1;
  *puVar1 = 0xffffffff;
  *(undefined4 *)(param_1[3] + 4) = 0;
  *(undefined4 *)(param_1[3] + 8) = 0;
  iVar3 = param_1[3];
  param_1[4] = iVar3;
  *(int *)(iVar3 + 8) = iVar3;
  puVar1 = (undefined4 *)FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),0x18);
  param_1[7] = (int)puVar1;
  *puVar1 = 0xffffffff;
  *(undefined4 *)(param_1[7] + 4) = 0;
  *(undefined4 *)(param_1[7] + 8) = 0;
  *(undefined4 *)(param_1[7] + 0xc) = 0;
  *(undefined4 *)(param_1[7] + 0x10) = 0;
  *(undefined4 *)(param_1[7] + 0x14) = 0;
  iVar3 = param_1[7];
  param_1[8] = iVar3;
  *(int *)(iVar3 + 0x14) = iVar3;
  puVar1 = (undefined4 *)FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),0x18);
  param_1[5] = (int)puVar1;
  *puVar1 = 0xffffffff;
  *(undefined4 *)(param_1[5] + 4) = 0;
  *(undefined4 *)(param_1[5] + 8) = 0;
  *(undefined4 *)(param_1[5] + 0xc) = 0;
  *(undefined4 *)(param_1[5] + 0x10) = 0;
  *(undefined4 *)(param_1[5] + 0x14) = 0;
  iVar3 = param_1[5];
  param_1[6] = iVar3;
  *(int *)(iVar3 + 0x14) = iVar3;
  iVar3 = param_1[9];
  param_1[1] = iVar3;
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = iVar3 + 4;
    param_1[9] = iVar3;
  }
  param_1[2] = iVar3;
  iVar4 = 0;
  if (iVar3 != 0) {
    FUN_0019ee74(iVar3,*param_1);
    iVar4 = param_1[9] + 4;
    param_1[9] = iVar4;
  }
  param_1[0x1d] = iVar4;
  param_1[0xb] = iVar4;
  return;
}

/* FUN_000e5e70 @ 0xe5e70 (5640 bytes) */
int FUN_000e5e70(param_1)
  int *param_1;
{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  int *piVar16;
  int iVar17;
  bool bVar18;
  int local_68;
  float local_64 [4];
  float local_54 [10];
  
  iVar13 = 0;
  uVar12 = 0;
  iVar14 = 0;
LAB_000e5e9c:
  while( true ) {
    local_68 = 0;
    if (param_1[0x1f] == 3) {
      iVar4 = param_1[0xc];
      param_1[9] = iVar4;
      param_1[1] = iVar4;
      if (iVar4 != 0) {
        param_1[9] = iVar4 + 4;
      }
      iVar4 = param_1[9];
      param_1[2] = iVar4;
      if (iVar4 != 0) {
        iVar4 = iVar4 + 4;
        param_1[9] = iVar4;
      }
      param_1[0x1d] = iVar4;
      param_1[0x1f] = 0;
      param_1[0xb] = iVar4;
    }
    iVar4 = ((int (*)())FUN_000e4c40)(param_1,&local_68,*param_1);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = param_1[0x20];
    if (iVar4 != 3) break;
    if (iVar14 == 0) {
      uVar2 = *(ushort *)((int)param_1 + 0x8e);
      uVar3 = (uint)uVar2;
      if ((uVar2 < 0xbf) && (uVar2 == 0x29)) {
        param_1[0x20] = 0;
        FUN_00194208(param_1[0xf],*(int *)(param_1[0xf] + 4) + -1);
        goto LAB_000e5f48;
      }
    }
    else {
LAB_000e5f48:
      uVar3 = (uint)*(ushort *)((int)param_1 + 0x8e);
    }
    if (uVar3 < 0xbf) {
      if (((uVar3 - 0x34 < 2) || (uVar3 == 0x70)) || (uVar3 == 0x6f)) {
LAB_000e6000:
        iVar14 = iVar14 + 1;
      }
      else {
joined_r0x000e600c:
        if (uVar3 == 0x29) {
          iVar14 = iVar14 + -1;
        }
      }
    }
  }
  if (iVar4 == 2) {
    if (iVar14 == 0) {
      uVar2 = *(ushort *)((int)param_1 + 0x8e);
      uVar3 = (uint)uVar2;
      if ((uVar2 < 0xbf) && ((uVar2 == 0x27 || (uVar2 == 0x29)))) {
        param_1[0x20] = 0;
        if ((*(ushort *)((int)param_1 + 0x8e) < 0xbf) && (*(ushort *)((int)param_1 + 0x8e) == 0x29))
        {
          FUN_00194208(param_1[0xf],*(int *)(param_1[0xf] + 4) + -1);
        }
        goto LAB_000e5e9c;
      }
    }
    else {
      uVar3 = (uint)*(ushort *)((int)param_1 + 0x8e);
    }
    if ((uVar3 < 0xbf) && (((uVar3 - 0x34 < 2 || (uVar3 == 0x70)) || (uVar3 == 0x6f))))
    goto LAB_000e6000;
    if (uVar3 < 0xbf) goto joined_r0x000e600c;
    goto LAB_000e5e9c;
  }
  if (iVar4 == 1) {
    if (((*(ushort *)((int)param_1 + 0x8e) < 0xbf) && (*(ushort *)((int)param_1 + 0x8e) == 0x32)) &&
       (uVar12 == *(ushort *)((int)param_1 + 0x92))) {
LAB_000e6ac4:
      param_1[0x20] = 0;
    }
    goto LAB_000e5e9c;
  }
  param_1[9] = (int)(param_1 + 0x23);
  if (iVar4 == 4) {
    iVar4 = FUN_000e4408(param_1);
    if ((iVar4 != 0x6d) && (iVar4 != 0x69)) goto LAB_000e5e9c;
    iVar7 = param_1[0x22];
    piVar16 = (int *)0x0;
    uVar3 = *(uint *)(iVar7 + 4);
    if (uVar3 - 1 < uVar3) {
      piVar16 = (int *)((uVar3 - 1) * 4 + *(int *)(iVar7 + 8));
    }
    iVar4 = *piVar16;
    FUN_00194208(iVar7,uVar3 - 1);
    param_1[0x20] = iVar4;
  }
  if (iVar4 == 5) {
    iVar4 = FUN_000e4408(param_1);
    if (iVar4 != 0x6d) goto LAB_000e5e9c;
    iVar4 = param_1[0x22];
    piVar16 = (int *)0x0;
    uVar3 = *(uint *)(iVar4 + 4);
    if (uVar3 - 1 < uVar3) {
      piVar16 = (int *)((uVar3 - 1) * 4 + *(int *)(iVar4 + 8));
    }
    iVar7 = *piVar16;
    FUN_00194208(iVar4,uVar3 - 1);
    param_1[0x20] = iVar7;
  }
  if (param_1[0xe] != 0) {
    uVar3 = (uint)*(ushort *)((int)param_1 + 0x8e);
    if (0xbe < uVar3) goto LAB_000e5e9c;
    if (((uVar3 != 0x28) && (uVar3 != 0x2b)) &&
       ((uVar3 != 0x29 && (((uVar3 != 0x2a && (uVar3 != 0x27)) && (uVar3 != 0x53)))))) {
      if (((uVar3 - 0x34 < 2) || (uVar3 == 0x3e)) ||
         ((uVar3 == 0x32 || ((uVar3 == 0x70 || (uVar3 == 0x6f)))))) {
        iVar13 = iVar13 + 1;
      }
      goto LAB_000e5e9c;
    }
    iVar13 = iVar13 + -1;
    if (0 < iVar13) goto LAB_000e5e9c;
    param_1[0xe] = 0;
  }
  uVar8 = FUN_000e4408(param_1);
  switch(uVar8) {
  case 6:
    puVar9 = (undefined4 *)0x0;
    uVar6 = *(uint *)(param_1[0x10] + 4);
    uVar3 = uVar6 - 1;
    if (uVar3 < uVar6) {
      puVar9 = (undefined4 *)(uVar3 * 4 + *(int *)(param_1[0x10] + 8));
    }
    piVar16 = (int *)*puVar9;
    if ((*piVar16 != 0x3e) && (*piVar16 != 0x71)) {
      if (piVar16[5] == 0) {
        if (piVar16[3] == 0) {
          piVar16[1] = 0;
        }
        else {
          param_1[0x23] = 0xe3;
        }
        goto switchD_000e61ac_caseD_a;
      }
      puVar15 = (uint *)param_1[0x22];
      iVar4 = param_1[0x20];
      uVar3 = puVar15[1];
      if (uVar3 < *puVar15) {
        _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
        piVar16 = (int *)(uVar3 * 4 + puVar15[2]);
        puVar15[1] = uVar3 + 1;
      }
      else {
        piVar16 = (int *)FUN_0019423c(puVar15,uVar3);
      }
      *piVar16 = iVar4;
      param_1[0x20] = 5;
      break;
    }
  case 0x10:
    param_1[0xe] = 1;
    goto switchD_000e61ac_caseD_a;
  case 7:
    local_64[0] = 8.40779e-45;
    ((int (*)())FUN_000e547c)(param_1,0x34,local_68,6);
    break;
  case 8:
    puVar15 = (uint *)param_1[0x22];
    iVar4 = param_1[0x1d];
    uVar3 = puVar15[1];
    iVar7 = param_1[0xb];
    uVar12 = param_1[0x24];
    if (uVar3 < *puVar15) {
      _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
      piVar16 = (int *)(uVar3 * 4 + puVar15[2]);
      puVar15[1] = uVar3 + 1;
    }
    else {
      piVar16 = (int *)FUN_0019423c(puVar15,uVar3);
    }
    *piVar16 = iVar4 - iVar7 >> 2;
    puVar15 = (uint *)param_1[0x22];
    iVar4 = param_1[0x1f];
    uVar3 = puVar15[1];
    if (uVar3 < *puVar15) {
      _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
      piVar16 = (int *)(uVar3 * 4 + puVar15[2]);
      puVar15[1] = uVar3 + 1;
    }
    else {
      piVar16 = (int *)FUN_0019423c(puVar15,uVar3);
    }
    *piVar16 = iVar4;
    puVar15 = (uint *)param_1[0x22];
    iVar4 = param_1[0x20];
    uVar3 = puVar15[1];
    if (uVar3 < *puVar15) {
      _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
      piVar16 = (int *)(uVar3 * 4 + puVar15[2]);
      puVar15[1] = uVar3 + 1;
    }
    else {
      piVar16 = (int *)FUN_0019423c(puVar15,uVar3);
    }
    *piVar16 = iVar4;
    puVar15 = (uint *)param_1[0x22];
    uVar3 = puVar15[1];
    if (uVar3 < *puVar15) {
      _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
      puVar9 = (undefined4 *)(uVar3 * 4 + puVar15[2]);
      puVar15[1] = uVar3 + 1;
    }
    else {
      puVar9 = (undefined4 *)FUN_0019423c(puVar15,uVar3);
    }
    *puVar9 = 0xffffffff;
    puVar15 = (uint *)param_1[0x11];
    iVar4 = param_1[0x14];
    param_1[0x15] = param_1[0x15] + 1;
    uVar3 = puVar15[1];
    if (uVar3 < *puVar15) {
      _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
      piVar16 = (int *)(uVar3 * 4 + puVar15[2]);
      puVar15[1] = uVar3 + 1;
    }
    else {
      piVar16 = (int *)FUN_0019423c(puVar15,uVar3);
    }
    *piVar16 = iVar4;
    puVar15 = (uint *)param_1[0x11];
    iVar4 = param_1[0x13];
    uVar3 = puVar15[1];
    if (uVar3 < *puVar15) {
      _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
      piVar16 = (int *)(uVar3 * 4 + puVar15[2]);
      puVar15[1] = uVar3 + 1;
    }
    else {
      piVar16 = (int *)FUN_0019423c(puVar15,uVar3);
    }
    *piVar16 = iVar4;
    puVar15 = (uint *)param_1[0x11];
    iVar4 = param_1[0x12];
    uVar3 = puVar15[1];
    if (uVar3 < *puVar15) {
      _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
      piVar16 = (int *)(uVar3 * 4 + puVar15[2]);
      puVar15[1] = uVar3 + 1;
    }
    else {
      piVar16 = (int *)FUN_0019423c(puVar15,uVar3);
    }
    *piVar16 = iVar4;
    param_1[0x1f] = 0;
    param_1[0x20] = 1;
    param_1[0x1d] = param_1[0xb];
    param_1[0x13] = 0;
    param_1[0x12] = 0;
    param_1[0x14] = 0;
    break;
  case 9:
    local_64[0] = 1.12104e-44;
    iVar7 = local_68 + -1;
    iVar4 = local_68 + 0x22;
    local_68 = iVar7;
    ((int (*)())FUN_000e5384)(param_1,0x35,iVar7,8,param_1[iVar4]);
    break;
  default:
    goto switchD_000e61ac_caseD_a;
  case 0xf:
    uVar2 = *(ushort *)((int)param_1 + 0x92);
    if (uVar2 != 0) {
      uVar3 = 0;
      do {
        uVar3 = uVar3 + 1;
        FUN_000e4a38(param_1,0);
      } while (uVar2 != uVar3);
    }
    break;
  case 0x1c:
    iVar4 = FUN_000e07dc(*param_1,0);
    if (iVar4 == 0) {
      iVar13 = FUN_000e07dc(*param_1,1);
      if (iVar13 != 0) {
        uVar12 = **(uint **)param_1[0x19] >> 0x10 & 0x3f;
        if (uVar12 == 1) {
          ((void (*)())FUN_000e4780)((double)(float)param_1[0x25],(double)(float)param_1[0x26],
                       (double)(float)param_1[0x27],(double)(float)param_1[0x28],param_1);
        }
        else if (uVar12 == 2) {
          FUN_000e4450(param_1,(int)(short)**(uint **)param_1[0x19],param_1[0x25],param_1[0x26],
                       param_1[0x27],param_1[0x28]);
        }
      }
      goto switchD_000e61ac_caseD_a;
    }
    break;
  case 0x1d:
    iVar4 = FUN_000e07dc(*param_1,0);
    if (iVar4 == 0) {
      iVar13 = param_1[0x25];
      iVar4 = *(int *)param_1[0x19];
      iVar14 = FUN_000e07dc(*param_1,1);
      if (iVar14 != 0) {
        FUN_000e4724(param_1,*(undefined2 *)(iVar4 + 2),iVar13 != 0);
      }
      goto switchD_000e61ac_caseD_a;
    }
    break;
  case 0x27:
    piVar16 = (int *)0x0;
    uVar6 = *(uint *)(param_1[0xf] + 4);
    uVar3 = uVar6 - 1;
    if (uVar3 < uVar6) {
      piVar16 = (int *)(uVar3 * 4 + *(int *)(param_1[0xf] + 8));
    }
    if ((*piVar16 == 0) || (*piVar16 != 1)) goto switchD_000e61ac_caseD_a;
    iVar14 = 0;
    param_1[0x20] = 3;
    break;
  case 0x29:
    iVar4 = param_1[0xf];
    piVar16 = (int *)0x0;
    uVar3 = *(uint *)(iVar4 + 4);
    if (uVar3 - 1 < uVar3) {
      piVar16 = (int *)((uVar3 - 1) * 4 + *(int *)(iVar4 + 8));
    }
    iVar7 = *piVar16;
    FUN_00194208(iVar4,uVar3 - 1);
    if (iVar7 != 0) goto LAB_000e6ac4;
    param_1[0x12] = param_1[0x12] + -1;
    uVar12 = *(uint *)(param_1[0x10] + 4);
    if (0 < (int)uVar12) {
      piVar16 = (int *)0x0;
      if (uVar12 - 1 < uVar12) {
        piVar16 = (int *)((uVar12 - 1) * 4 + *(int *)(param_1[0x10] + 8));
      }
      *(int *)(*piVar16 + 0xc) = *(int *)(*piVar16 + 0xc) + -1;
    }
    goto switchD_000e61ac_caseD_a;
  case 0x2a:
    iVar13 = param_1[0x10];
    puVar9 = (undefined4 *)0x0;
    uVar12 = *(uint *)(iVar13 + 4);
    if (uVar12 - 1 < uVar12) {
      puVar9 = (undefined4 *)((uVar12 - 1) * 4 + *(int *)(iVar13 + 8));
    }
    uVar8 = *puVar9;
    FUN_00194208(iVar13,uVar12 - 1);
    FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),uVar8);
    param_1[0x13] = param_1[0x13] + -1;
    goto switchD_000e61ac_caseD_a;
  case 0x34:
    uVar3 = param_1[0x24];
    iVar17 = 0;
    uVar6 = param_1[0x23];
    iVar7 = 0;
    uVar11 = uVar3 >> 0x10 & 0x3f;
    iVar4 = 1;
    if ((uVar3 & 0x400000) != 0) {
      iVar17 = param_1[0x25];
      iVar4 = 3;
    }
    uVar5 = param_1[iVar4 + 0x23];
    if ((uVar5 & 0x400000) != 0) {
      iVar7 = param_1[iVar4 + 0x24];
    }
    if ((((uVar11 != (uVar5 >> 0x10 & 0x3f)) || (uVar11 != 1)) ||
        (iVar4 = FUN_000e07dc(*param_1,1), iVar4 == 0)) ||
       ((iVar4 = FUN_000e44c4(param_1,(int)(short)uVar3,local_64,iVar17), iVar4 == 0 ||
        (iVar4 = FUN_000e44c4(param_1,(int)(short)uVar5,local_54,iVar7), iVar4 == 0)))) {
      puVar15 = (uint *)param_1[0xf];
      uVar12 = puVar15[1];
      if (uVar12 < *puVar15) {
        _memset((void *)(uVar12 * 4 + puVar15[2]),0,4);
        puVar9 = (undefined4 *)(uVar12 * 4 + puVar15[2]);
        puVar15[1] = uVar12 + 1;
      }
      else {
        puVar9 = (undefined4 *)FUN_0019423c(puVar15,uVar12);
      }
      *puVar9 = 0;
      iVar13 = param_1[0x10];
      param_1[0x12] = param_1[0x12] + 1;
      uVar12 = *(uint *)(iVar13 + 4);
      goto joined_r0x000e6a0c;
    }
    switch(uVar6 >> 0x10 & 7) {
    case 0:
      bVar18 = local_64[0] != local_54[0];
      break;
    case 1:
      bVar18 = local_64[0] == local_54[0];
      break;
    case 2:
      bVar18 = local_54[0] <= local_64[0];
      break;
    case 3:
      bVar18 = local_54[0] < local_64[0];
      break;
    case 4:
      bVar18 = local_64[0] <= local_54[0];
      break;
    case 5:
      bVar18 = local_64[0] < local_54[0];
      break;
    default:
      goto switchD_000e67b4_default;
    }
    if (bVar18) goto LAB_000e6870;
switchD_000e67b4_default:
    puVar15 = (uint *)param_1[0xf];
    uVar3 = puVar15[1];
    if (uVar3 < *puVar15) {
      _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
      puVar9 = (undefined4 *)(uVar3 * 4 + puVar15[2]);
      puVar15[1] = uVar3 + 1;
    }
    else {
      puVar9 = (undefined4 *)FUN_0019423c(puVar15,uVar3);
    }
    iVar14 = 0;
    *puVar9 = 2;
    param_1[0x20] = 2;
    break;
  case 0x35:
    sVar1 = *(short *)((int)param_1 + 0x92);
    iVar4 = FUN_000e4410(param_1,(int)sVar1);
    if (iVar4 == -1) {
      puVar15 = (uint *)param_1[0xf];
      uVar12 = puVar15[1];
      if (uVar12 < *puVar15) {
        _memset((void *)(uVar12 * 4 + puVar15[2]),0,4);
        puVar9 = (undefined4 *)(uVar12 * 4 + puVar15[2]);
        puVar15[1] = uVar12 + 1;
      }
      else {
        puVar9 = (undefined4 *)FUN_0019423c(puVar15,uVar12);
      }
      *puVar9 = 0;
      param_1[0x12] = param_1[0x12] + 1;
      goto switchD_000e61ac_caseD_a;
    }
    iVar4 = FUN_000e4410(param_1,(int)sVar1);
    if (iVar4 == 0) {
      puVar15 = (uint *)param_1[0xf];
      param_1[0x20] = 2;
      uVar3 = puVar15[1];
      if (uVar3 < *puVar15) {
        _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
        puVar9 = (undefined4 *)(uVar3 * 4 + puVar15[2]);
        puVar15[1] = uVar3 + 1;
      }
      else {
        puVar9 = (undefined4 *)FUN_0019423c(puVar15,uVar3);
      }
      iVar14 = 0;
      *puVar9 = 2;
    }
    else {
LAB_000e6870:
      puVar15 = (uint *)param_1[0xf];
      uVar3 = puVar15[1];
      if (uVar3 < *puVar15) {
        _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
        puVar9 = (undefined4 *)(uVar3 * 4 + puVar15[2]);
        puVar15[1] = uVar3 + 1;
      }
      else {
        puVar9 = (undefined4 *)FUN_0019423c(puVar15,uVar3);
      }
      *puVar9 = 1;
    }
    break;
  case 0x3e:
  case 0x71:
    param_1[0x13] = param_1[0x13] + 1;
  case 0x72:
    puVar9 = (undefined4 *)FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),0x18);
    *puVar9 = uVar8;
    puVar9[3] = 0;
    puVar9[1] = 0;
    puVar9[2] = 0;
    puVar15 = (uint *)param_1[0x10];
    uVar12 = puVar15[1];
    if (uVar12 < *puVar15) {
      _memset((void *)(uVar12 * 4 + puVar15[2]),0,4);
      puVar10 = (undefined4 *)(uVar12 * 4 + puVar15[2]);
      puVar15[1] = uVar12 + 1;
    }
    else {
      puVar10 = (undefined4 *)FUN_0019423c(puVar15,uVar12);
    }
    *puVar10 = puVar9;
    goto switchD_000e61ac_caseD_a;
  case 0x53:
    goto switchD_000e61ac_caseD_53;
  case 0x65:
    local_64[0] = 8.40779e-45;
    ((int (*)())FUN_000e547c)(param_1,0x6f,local_68,6);
    break;
  case 0x66:
    local_64[0] = 8.40779e-45;
    ((int (*)())FUN_000e547c)(param_1,0x70,local_68,6);
    break;
  case 0x67:
    local_64[0] = 1.12104e-44;
    iVar7 = local_68 + -1;
    iVar4 = local_68 + 0x22;
    local_68 = iVar7;
    ((int (*)())FUN_000e5384)(param_1,0x6f,iVar7,8,param_1[iVar4]);
    break;
  case 0x68:
    local_64[0] = 1.12104e-44;
    iVar7 = local_68 + -1;
    iVar4 = local_68 + 0x22;
    local_68 = iVar7;
    ((int (*)())FUN_000e5384)(param_1,0x70,iVar7,8,param_1[iVar4]);
    break;
  case 0x69:
    piVar16 = (int *)0x0;
    uVar6 = *(uint *)(param_1[0x10] + 4);
    uVar3 = uVar6 - 1;
    if (uVar3 < uVar6) {
      piVar16 = (int *)(uVar3 * 4 + *(int *)(param_1[0x10] + 8));
    }
    iVar4 = *piVar16;
    if (*(int *)(iVar4 + 0x14) == 0) {
      if (*(int *)(iVar4 + 4) == 0) {
        if (*(int *)(iVar4 + 8) == 0) {
          *(undefined4 *)(iVar4 + 4) = 1;
          goto switchD_000e61ac_caseD_a;
        }
        param_1[0x1d] = *(int *)(iVar4 + 8);
        param_1[0x20] = 0;
        *(undefined4 *)(iVar4 + 8) = 0;
      }
      else if (*(int *)(iVar4 + 8) == 0) {
        *(int *)(iVar4 + 8) = param_1[0x1d] + local_68 * -4;
      }
    }
    break;
  case 0x6c:
    piVar16 = (int *)0x0;
    uVar6 = *(uint *)(param_1[0x10] + 4);
    uVar3 = uVar6 - 1;
    if (uVar3 < uVar6) {
      piVar16 = (int *)(uVar3 * 4 + *(int *)(param_1[0x10] + 8));
    }
    iVar4 = *piVar16;
    *(int *)(iVar4 + 0x10) = param_1[0x1d] + local_68 * -4;
    if (*(int *)(iVar4 + 4) != 0) goto LAB_000e7400;
    if (*(int *)(iVar4 + 0x14) != 0) goto switchD_000e61ac_caseD_a;
    puVar15 = (uint *)param_1[0x22];
    iVar4 = param_1[0x20];
    uVar3 = puVar15[1];
    if (uVar3 < *puVar15) {
      _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
      piVar16 = (int *)(uVar3 * 4 + puVar15[2]);
      puVar15[1] = uVar3 + 1;
    }
    else {
      piVar16 = (int *)FUN_0019423c(puVar15,uVar3);
    }
    *piVar16 = iVar4;
    param_1[0x20] = 4;
    break;
  case 0x6d:
    iVar4 = param_1[0x10];
    piVar16 = (int *)0x0;
    uVar3 = *(uint *)(iVar4 + 4);
    if (uVar3 - 1 < uVar3) {
      piVar16 = (int *)((uVar3 - 1) * 4 + *(int *)(iVar4 + 8));
    }
    iVar7 = *piVar16;
    if (*(int *)(iVar7 + 4) == 0) {
      if (*(int *)(iVar7 + 8) == 0) {
        if ((*(int *)(iVar7 + 0x14) != 0) || (*(int *)(iVar7 + 0x10) == 0)) {
          FUN_00194208(iVar4,uVar3 - 1);
          goto switchD_000e61ac_caseD_a;
        }
        param_1[0x1d] = *(int *)(iVar7 + 0x10);
        *(undefined4 *)(iVar7 + 0x14) = 1;
      }
      else {
        param_1[0x1d] = *(int *)(iVar7 + 8);
        piVar16 = (int *)0x0;
        uVar3 = *(uint *)(iVar4 + 4) - 1;
        if (uVar3 < *(uint *)(iVar4 + 4)) {
          piVar16 = (int *)(uVar3 * 4 + *(int *)(iVar4 + 8));
        }
        *(undefined4 *)(*piVar16 + 8) = 0;
        param_1[0x1f] = 0;
      }
    }
    else {
      iVar4 = *(int *)(iVar7 + 8);
      if (iVar4 == 0) {
        puVar15 = (uint *)param_1[0x22];
        iVar4 = param_1[0x1d];
        uVar3 = puVar15[1];
        iVar17 = param_1[0xb];
        if (uVar3 < *puVar15) {
          _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
          piVar16 = (int *)(uVar3 * 4 + puVar15[2]);
          puVar15[1] = uVar3 + 1;
        }
        else {
          piVar16 = (int *)FUN_0019423c(puVar15,uVar3);
        }
        *piVar16 = (iVar4 - iVar17) + -4 >> 2;
        puVar15 = (uint *)param_1[0x22];
        uVar3 = puVar15[1];
        if (uVar3 < *puVar15) {
          _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
          puVar9 = (undefined4 *)(uVar3 * 4 + puVar15[2]);
          puVar15[1] = uVar3 + 1;
        }
        else {
          puVar9 = (undefined4 *)FUN_0019423c(puVar15,uVar3);
        }
        *puVar9 = 0;
        puVar15 = (uint *)param_1[0x22];
        uVar3 = puVar15[1];
        if (uVar3 < *puVar15) {
          _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
          puVar9 = (undefined4 *)(uVar3 * 4 + puVar15[2]);
          puVar15[1] = uVar3 + 1;
        }
        else {
          puVar9 = (undefined4 *)FUN_0019423c(puVar15,uVar3);
        }
        *puVar9 = 0;
        puVar15 = (uint *)param_1[0x22];
        uVar3 = puVar15[1];
        if (uVar3 < *puVar15) {
          _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
          puVar9 = (undefined4 *)(uVar3 * 4 + puVar15[2]);
          puVar15[1] = uVar3 + 1;
        }
        else {
          puVar9 = (undefined4 *)FUN_0019423c(puVar15,uVar3);
        }
        *puVar9 = 0xffffffff;
        puVar15 = (uint *)param_1[0x22];
        uVar3 = puVar15[1];
        if (uVar3 < *puVar15) {
          _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
          puVar9 = (undefined4 *)(uVar3 * 4 + puVar15[2]);
          puVar15[1] = uVar3 + 1;
        }
        else {
          puVar9 = (undefined4 *)FUN_0019423c(puVar15,uVar3);
        }
        *puVar9 = 6;
        param_1[0x1f] = 1;
        *(undefined4 *)(iVar7 + 4) = 0;
      }
      else {
        puVar15 = (uint *)param_1[0x22];
        iVar17 = param_1[0xb];
        uVar3 = puVar15[1];
        if (uVar3 < *puVar15) {
          _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
          piVar16 = (int *)(uVar3 * 4 + puVar15[2]);
          puVar15[1] = uVar3 + 1;
        }
        else {
          piVar16 = (int *)FUN_0019423c(puVar15,uVar3);
        }
        *piVar16 = iVar4 - iVar17 >> 2;
        *(undefined4 *)(iVar7 + 8) = 0;
        puVar15 = (uint *)param_1[0x22];
        uVar3 = puVar15[1];
        if (uVar3 < *puVar15) {
          _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
          puVar9 = (undefined4 *)(uVar3 * 4 + puVar15[2]);
          puVar15[1] = uVar3 + 1;
        }
        else {
          puVar9 = (undefined4 *)FUN_0019423c(puVar15,uVar3);
        }
        *puVar9 = 0;
        puVar15 = (uint *)param_1[0x22];
        uVar3 = puVar15[1];
        if (uVar3 < *puVar15) {
          _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
          puVar9 = (undefined4 *)(uVar3 * 4 + puVar15[2]);
          puVar15[1] = uVar3 + 1;
        }
        else {
          puVar9 = (undefined4 *)FUN_0019423c(puVar15,uVar3);
        }
        *puVar9 = 0;
        puVar15 = (uint *)param_1[0x22];
        uVar3 = puVar15[1];
        if (uVar3 < *puVar15) {
          _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
          puVar9 = (undefined4 *)(uVar3 * 4 + puVar15[2]);
          puVar15[1] = uVar3 + 1;
        }
        else {
          puVar9 = (undefined4 *)FUN_0019423c(puVar15,uVar3);
        }
        *puVar9 = 0xffffffff;
        puVar15 = (uint *)param_1[0x22];
        uVar3 = puVar15[1];
        if (uVar3 < *puVar15) {
          _memset((void *)(uVar3 * 4 + puVar15[2]),0,4);
          puVar9 = (undefined4 *)(uVar3 * 4 + puVar15[2]);
          puVar15[1] = uVar3 + 1;
        }
        else {
          puVar9 = (undefined4 *)FUN_0019423c(puVar15,uVar3);
        }
        *puVar9 = 6;
        param_1[0x1f] = 1;
      }
    }
    break;
  case 0x6f:
  case 0x70:
    puVar15 = (uint *)param_1[0xf];
    param_1[0x12] = param_1[0x12] + 1;
    uVar12 = puVar15[1];
    if (uVar12 < *puVar15) {
      _memset((void *)(uVar12 * 4 + puVar15[2]),0,4);
      puVar9 = (undefined4 *)(uVar12 * 4 + puVar15[2]);
      puVar15[1] = uVar12 + 1;
    }
    else {
      puVar9 = (undefined4 *)FUN_0019423c(puVar15,uVar12);
    }
    *puVar9 = 0;
    iVar13 = param_1[0x10];
    uVar12 = *(uint *)(iVar13 + 4);
joined_r0x000e6a0c:
    if (0 < (int)uVar12) {
      piVar16 = (int *)0x0;
      if (uVar12 - 1 < uVar12) {
        piVar16 = (int *)((uVar12 - 1) * 4 + *(int *)(iVar13 + 8));
      }
      *(int *)(*piVar16 + 0xc) = *(int *)(*piVar16 + 0xc) + 1;
    }
    goto switchD_000e61ac_caseD_a;
  case 0x73:
    if ((param_1[0x12] != 0) || (param_1[0x13] != 0)) {
      param_1[0x14] = 1;
      param_1[0x24] = param_1[0x15];
      param_1[0x17] = 1;
      param_1[0x16] = 1;
      goto switchD_000e61ac_caseD_a;
    }
switchD_000e61ac_caseD_53:
    iVar4 = param_1[0x15];
    iVar7 = param_1[0x14];
    param_1[0x15] = iVar4 + -1;
    if (iVar4 + -1 < 0) {
      param_1[0x14] = 0;
      param_1[0x12] = 0;
      param_1[0x13] = 0;
    }
    else {
      iVar4 = param_1[0x11];
      piVar16 = (int *)0x0;
      uVar3 = *(uint *)(iVar4 + 4);
      if (uVar3 - 1 < uVar3) {
        piVar16 = (int *)((uVar3 - 1) * 4 + *(int *)(iVar4 + 8));
      }
      iVar17 = *piVar16;
      FUN_00194208(iVar4,uVar3 - 1);
      iVar4 = param_1[0x11];
      param_1[0x12] = iVar17;
      piVar16 = (int *)0x0;
      uVar3 = *(uint *)(iVar4 + 4);
      if (uVar3 - 1 < uVar3) {
        piVar16 = (int *)((uVar3 - 1) * 4 + *(int *)(iVar4 + 8));
      }
      iVar17 = *piVar16;
      FUN_00194208(iVar4,uVar3 - 1);
      iVar4 = param_1[0x11];
      param_1[0x13] = iVar17;
      piVar16 = (int *)0x0;
      uVar3 = *(uint *)(iVar4 + 4);
      if (uVar3 - 1 < uVar3) {
        piVar16 = (int *)((uVar3 - 1) * 4 + *(int *)(iVar4 + 8));
      }
      iVar17 = *piVar16;
      FUN_00194208(iVar4,uVar3 - 1);
      param_1[0x14] = (uint)(iVar17 == 1);
    }
    param_1[0x1f] = 1;
    if (iVar7 != 0) {
      param_1[0x23] = 0x6e;
      param_1[0x16] = 1;
      param_1[0x17] = 1;
      param_1[0x24] = param_1[0x15] + 1;
      goto switchD_000e61ac_caseD_a;
    }
    break;
  case 0x74:
    local_64[0] = 1.61149e-43;
    ((int (*)())FUN_000e547c)(param_1,0x6f,local_68,0x73);
    break;
  case 0x75:
    local_64[0] = 1.61149e-43;
    ((int (*)())FUN_000e547c)(param_1,0x70,local_68,0x73);
  }
  goto LAB_000e5e9c;
LAB_000e7400:
  if (*(int *)(iVar4 + 0x14) != 0) {
switchD_000e61ac_caseD_a:
    DAT_001fa620 = local_68;
    param_1[0xd] = param_1[0xd] + 1;
    return 1;
  }
  goto LAB_000e5e9c;
}

/* FUN_000e7658 @ 0xe7658 (48 bytes) */
int FUN_000e7658(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0xb4) & 0x1f;
  iVar2 = (*(uint *)(param_1 + 0xb4) >> 3 & 0x1ffffffc) + *(int *)(*(int *)(param_1 + 0xac) + 0x3bc)
  ;
  *(uint *)(iVar2 + 8) = (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & *(uint *)(iVar2 + 8);
  FUN_00193f20();
  return;
}

/* FUN_000e7688 @ 0xe7688 (60 bytes) */
int FUN_000e7688(param_1, param_2)
  int param_1;
  int param_2;
{
  FUN_00193f44(param_2,*(undefined4 *)(param_1 + 0xcc));
  *(int *)(param_2 + 0x158) = param_1;
  return;
}

/* FUN_000e76c4 @ 0xe76c4 (60 bytes) */
int FUN_000e76c4(param_1, param_2)
  int param_1;
  int param_2;
{
  FUN_00193f74(param_2,*(undefined4 *)(param_1 + 200));
  *(int *)(param_2 + 0x158) = param_1;
  return;
}

/* FUN_000e7700 @ 0xe7700 (56 bytes) */
int FUN_000e7700(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_00193f44(param_3);
  *(undefined4 *)(param_3 + 0x158) = param_1;
  return;
}

/* FUN_000e7738 @ 0xe7738 (56 bytes) */
int FUN_000e7738(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_00193f74(param_3);
  *(undefined4 *)(param_3 + 0x158) = param_1;
  return;
}

/* FUN_000e7770 @ 0xe7770 (80 bytes) */
int FUN_000e7770(param_1)
  int *param_1;
{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)(**(code **)(*param_1 + 0x4c))();
  iVar2 = _strcmp(pcVar1,"SIMPLE");
  return iVar2 == 0;
}

/* FUN_000e77c0 @ 0xe77c0 (52 bytes) */
int FUN_000e77c0(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x134) != 0) {
    return "REP_HEADER";
  }
  return "LOOP_HEADER";
}

/* FUN_000e77f4 @ 0xe77f4 (16 bytes) */
int FUN_000e77f4(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x154) = param_2;
  *(undefined4 *)(param_1 + 0x150) = 1;
  return;
}

/* FUN_000e7804 @ 0xe7804 (188 bytes) */
int FUN_000e7804(param_1)
  int param_1;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0x98);
  for (piVar2 = (int *)(*(int **)(param_1 + 0x98))[2]; piVar2 != (int *)0x0;
      piVar2 = (int *)piVar2[2]) {
    if ((piVar1[5] & 1U) != 0) {
      iVar3 = (**(code **)(*piVar1 + 0x34))(piVar1);
      if ((iVar3 == 0) && (iVar3 = (**(code **)(*piVar1 + 0x38))(piVar1), iVar3 == 0)) {
        (**(code **)(*piVar1 + 0x18))(piVar1);
        piVar2 = (int *)piVar1[2];
      }
      else {
        piVar2 = (int *)piVar1[2];
      }
    }
    piVar1 = piVar2;
  }
  return *(undefined4 *)(param_1 + 0x130);
}

/* FUN_000e78c0 @ 0xe78c0 (56 bytes) */
int FUN_000e78c0(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0xb8) = param_2;
  if (*(int *)(param_1 + 0x134) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x134) + 0xb8) = param_2;
  }
  if (*(int *)(param_1 + 0x138) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x138) + 0xb8) = param_2;
  }
  if (*(int *)(param_1 + 0x13c) == 0) {
    return;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x13c) + 0xb8) = param_2;
  return;
}

/* FUN_000e78f8 @ 0xe78f8 (44 bytes) */
int FUN_000e78f8(param_1, param_2)
  int param_1;
  int param_2;
{
  do {
    if (param_2 == param_1) {
      return 1;
    }
    param_2 = *(int *)(param_2 + 0xf0);
  } while (param_2 != 0);
  return 0;
}

/* FUN_000e7924 @ 0xe7924 (104 bytes) */
int FUN_000e7924(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  while ((iVar1 = ((int (*)())FUN_000e78f8)(param_1,param_2), iVar2 = param_1, iVar1 == 0 &&
         (iVar1 = ((int (*)())FUN_000e78f8)(param_2,param_1), iVar2 = param_2, iVar1 == 0))) {
    param_1 = *(int *)(param_1 + 0xf0);
    param_2 = *(int *)(param_2 + 0xf0);
  }
  return iVar2;
}

/* FUN_000e798c @ 0xe798c (20 bytes) */
int FUN_000e798c(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0xf8) + 4) != 0;
}

/* FUN_000e79a0 @ 0xe79a0 (24 bytes) */
int FUN_000e79a0(param_1)
  int param_1;
{
  return 1 < *(uint *)(*(int *)(param_1 + 0xd0) + 4);
}

/* FUN_000e79b8 @ 0xe79b8 (24 bytes) */
int FUN_000e79b8(param_1)
  int param_1;
{
  return 1 < *(uint *)(*(int *)(param_1 + 0xd4) + 4);
}

/* FUN_000e79d0 @ 0xe79d0 (12 bytes) */
int FUN_000e79d0(param_1)
  int param_1;
{
  return *(undefined4 *)(*(int *)(param_1 + 0xd0) + 4);
}

/* FUN_000e79dc @ 0xe79dc (12 bytes) */
int FUN_000e79dc(param_1)
  int param_1;
{
  return *(undefined4 *)(*(int *)(param_1 + 0xd4) + 4);
}

/* FUN_000e79e8 @ 0xe79e8 (20 bytes) */
int FUN_000e79e8(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0xd0) + 4) != 0;
}

/* FUN_000e79fc @ 0xe79fc (20 bytes) */
int FUN_000e79fc(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0xd4) + 4) != 0;
}

/* FUN_000e7a10 @ 0xe7a10 (20 bytes) */
int FUN_000e7a10(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0xf4) + 4) != 0;
}

/* FUN_000e7a24 @ 0xe7a24 (120 bytes) */
int FUN_000e7a24(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_1 + 0xc4);
  uVar2 = *(uint *)(iVar1 + 4);
  while (uVar2 != 0) {
    puVar3 = (undefined4 *)0x0;
    if (uVar2 - 1 < uVar2) {
      puVar3 = (undefined4 *)((uVar2 - 1) * 4 + *(int *)(iVar1 + 8));
    }
    uVar4 = *puVar3;
    FUN_00194208(iVar1,uVar2 - 1);
    FUN_00122ebc(uVar4);
    iVar1 = *(int *)(param_1 + 0xc4);
    uVar2 = *(uint *)(iVar1 + 4);
  }
  return;
}

/* FUN_000e7a9c @ 0xe7a9c (256 bytes) */
int FUN_000e7a9c(param_1)
  int *param_1;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)param_1[0x4e];
  while ((((piVar3 != (int *)0x0 && (iVar2 = ((int (*)())FUN_000e79e8)(piVar3), param_1 = piVar3, iVar2 != 0)) &&
          (iVar2 = (**(code **)(*piVar3 + 0x38))(piVar3), iVar2 == 0)) &&
         (iVar2 = (**(code **)(*piVar3 + 0x3c))(piVar3), iVar2 == 0))) {
    iVar2 = (**(code **)(*piVar3 + 0x2c))(piVar3);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3);
      if (iVar2 == 0) {
        piVar1 = (int *)0x0;
        if (*(int *)(piVar3[0x34] + 4) != 0) {
          piVar1 = *(int **)(piVar3[0x34] + 8);
        }
        piVar3 = (int *)*piVar1;
        param_1 = piVar3;
      }
      else {
        piVar3 = (int *)piVar3[0x4f];
        param_1 = piVar3;
      }
    }
    else {
      piVar3 = (int *)piVar3[0x55];
      param_1 = piVar3;
    }
  }
  return param_1;
}

/* FUN_000e7b9c @ 0xe7b9c (252 bytes) */
int FUN_000e7b9c(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x134);
  while ((((piVar3 != (int *)0x0 && (iVar2 = ((int (*)())FUN_000e79e8)(piVar3), iVar2 != 0)) &&
          (iVar2 = (**(code **)(*piVar3 + 0x38))(piVar3), iVar2 == 0)) &&
         (iVar2 = (**(code **)(*piVar3 + 0x3c))(piVar3), iVar2 == 0))) {
    iVar2 = (**(code **)(*piVar3 + 0x2c))(piVar3);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3);
      if (iVar2 == 0) {
        piVar1 = (int *)0x0;
        if (*(int *)(piVar3[0x34] + 4) != 0) {
          piVar1 = *(int **)(piVar3[0x34] + 8);
        }
        piVar3 = (int *)*piVar1;
      }
      else {
        piVar3 = (int *)piVar3[0x4f];
      }
    }
    else {
      piVar3 = (int *)piVar3[0x55];
    }
  }
  return piVar3;
}

/* FUN_000e7c98 @ 0xe7c98 (88 bytes) */
int FUN_000e7c98(param_1)
  int param_1;
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xa0);
  (**(code **)(*piVar1 + 0x38))(piVar1);
  if ((*(uint *)(piVar1[1] + 0x14) & 8) != 0) {
    piVar1 = *(int **)(piVar1[1] + 4);
  }
  return piVar1;
}

/* FUN_000e7cf0 @ 0xe7cf0 (108 bytes) */
int FUN_000e7cf0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(param_2 + 0x84) == 0) {
    FUN_00193f74(param_2,*(undefined4 *)(param_1 + 300));
    *(int *)(param_1 + 300) = param_2;
    *(int *)(param_2 + 0x158) = param_1;
  }
  else {
    FUN_00105594(param_2,1);
    FUN_00193f74(param_2,*(undefined4 *)(param_1 + 300));
    *(int *)(param_2 + 0x158) = param_1;
  }
  return;
}

/* FUN_000e7d5c @ 0xe7d5c (136 bytes) */
int FUN_000e7d5c(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x98);
  iVar2 = *(int *)(*(int *)(param_1 + 0x98) + 8);
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    if (((*(uint *)(iVar1 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar1 + 0x88) + 8) == 0x81))
    break;
    iVar1 = iVar2;
    iVar2 = *(int *)(iVar2 + 8);
  }
  iVar2 = FUN_00105594(iVar1,1);
  if (iVar2 == 0) {
    return *(undefined4 *)(iVar1 + 0xac);
  }
  return *(undefined4 *)(iVar2 + 0x94);
}

/* FUN_000e7de4 @ 0xe7de4 (172 bytes) */
int FUN_000e7de4(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar2 = 1;
  iVar4 = 0;
  do {
    if (*(uint *)(*(int *)(param_2 + 0xd4) + 4) < uVar2) {
      uVar3 = 0;
LAB_000e7e3c:
      uVar2 = 1;
      for (iVar4 = 0;
          (uVar2 <= *(uint *)(*(int *)(param_1 + 0xd0) + 4) &&
          ((iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0xd0) + 8) + iVar4), iVar1 == 0 ||
           (param_2 != iVar1)))); iVar4 = iVar4 + 4) {
        uVar2 = uVar2 + 1;
      }
      return uVar3;
    }
    iVar1 = *(int *)(iVar4 + *(int *)(*(int *)(param_2 + 0xd4) + 8));
    if ((iVar1 != 0) && (param_1 == iVar1)) {
      uVar3 = 1;
      goto LAB_000e7e3c;
    }
    uVar2 = uVar2 + 1;
    iVar4 = iVar4 + 4;
  } while( true );
}

/* FUN_000e7e90 @ 0xe7e90 (168 bytes) */
int FUN_000e7e90(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 1;
  iVar3 = 0;
  iVar2 = *(int *)(param_1 + 0xd4);
  do {
    if (*(uint *)(iVar2 + 4) < uVar4) {
      return (int *)0x0;
    }
    piVar1 = *(int **)(*(int *)(iVar2 + 8) + iVar3);
    if (piVar1 != (int *)0x0) {
      iVar2 = ((int (*)())FUN_000e7770)();
      if (iVar2 != 0) {
        return piVar1;
      }
      iVar2 = (**(code **)(*piVar1 + 0x1c))();
      if (iVar2 != 0) {
        return piVar1;
      }
      iVar2 = *(int *)(param_1 + 0xd4);
    }
    uVar4 = uVar4 + 1;
    iVar3 = iVar3 + 4;
  } while( true );
}

/* FUN_000e7f38 @ 0xe7f38 (168 bytes) */
int FUN_000e7f38(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 1;
  iVar3 = 0;
  iVar2 = *(int *)(param_1 + 0xd0);
  do {
    if (*(uint *)(iVar2 + 4) < uVar4) {
      return (int *)0x0;
    }
    piVar1 = *(int **)(*(int *)(iVar2 + 8) + iVar3);
    if (piVar1 != (int *)0x0) {
      iVar2 = ((int (*)())FUN_000e7770)();
      if (iVar2 != 0) {
        return piVar1;
      }
      iVar2 = (**(code **)(*piVar1 + 0x20))();
      if (iVar2 != 0) {
        return piVar1;
      }
      iVar2 = *(int *)(param_1 + 0xd0);
    }
    uVar4 = uVar4 + 1;
    iVar3 = iVar3 + 4;
  } while( true );
}

/* FUN_000e7fe0 @ 0xe7fe0 (92 bytes) */
int FUN_000e7fe0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 1;
  iVar4 = 0;
  iVar2 = 0;
  do {
    if (*(uint *)(*(int *)(param_1 + 0xd0) + 4) < uVar3) {
      return -1;
    }
    iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0xd0) + 8) + iVar4);
    if (iVar1 != 0) {
      if (iVar1 == param_2) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
    uVar3 = uVar3 + 1;
    iVar4 = iVar4 + 4;
  } while( true );
}

/* FUN_000e803c @ 0xe803c (92 bytes) */
int FUN_000e803c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 1;
  iVar4 = 0;
  iVar2 = 0;
  do {
    if (*(uint *)(*(int *)(param_1 + 0xd4) + 4) < uVar3) {
      return -1;
    }
    iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0xd4) + 8) + iVar4);
    if (iVar1 != 0) {
      if (iVar1 == param_2) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
    uVar3 = uVar3 + 1;
    iVar4 = iVar4 + 4;
  } while( true );
}

/* FUN_000e8098 @ 0xe8098 (52 bytes) */
int FUN_000e8098()
{
  int iVar1;
  int iVar2;
  
  iVar2 = ((int (*)())FUN_000e803c)();
  iVar1 = -1;
  if (iVar2 != -1) {
    iVar1 = iVar2 + 1;
  }
  return iVar1;
}

/* FUN_000e80cc @ 0xe80cc (88 bytes) */
int FUN_000e80cc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 1;
  iVar3 = 0;
  while( true ) {
    if (*(uint *)(*(int *)(param_1 + 0xd0) + 4) < uVar2) {
      return 0;
    }
    iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0xd0) + 8) + iVar3);
    if ((iVar1 != 0) && (param_2 != *(int *)(iVar1 + 0x118))) break;
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + 4;
  }
  return iVar1;
}

/* FUN_000e8124 @ 0xe8124 (664 bytes) */
int FUN_000e8124(param_1)
  int param_1;
{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  
  puVar7 = *(uint **)(param_1 + 0x3bc);
  uVar9 = puVar7[1];
  if (uVar9 == 0) {
LAB_000e8190:
    uVar2 = uVar9 + 1;
    if (uVar9 + 0x20 >> 5 == *puVar7) {
      puVar7[1] = uVar2;
      if (uVar9 < uVar2) {
        iVar10 = uVar2 - uVar9;
        do {
          uVar3 = uVar9 >> 3 & 0x1ffffffc;
          uVar2 = uVar9 & 0x1f;
          uVar9 = uVar9 + 1;
          *(uint *)((int)puVar7 + uVar3 + 8) = *(uint *)((int)puVar7 + uVar3 + 8) & ~(1 << uVar2);
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
      puVar7 = *(uint **)(param_1 + 0x3bc);
      uVar9 = puVar7[1];
      if (uVar9 != 0) {
        if ((puVar7[2] & 1) != 0) {
          uVar3 = 0;
          do {
            uVar3 = uVar3 + 1;
            uVar9 = uVar9 - 1;
            if (uVar9 == 0) goto LAB_000e82ec;
          } while ((*(uint *)((int)puVar7 + (uVar3 >> 3 & 0x1ffffffc) + 8) >> (uVar3 & 0x1f) & 1) !=
                   0);
          goto LAB_000e8388;
        }
        goto LAB_000e8324;
      }
    }
    else {
      uVar2 = uVar9 + 0x41f >> 5;
      uVar8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar5 = (undefined4 *)FUN_00193e18(uVar8,uVar2 * 4 + 0xc);
      piVar4 = puVar5 + 1;
      *puVar5 = uVar8;
      puVar5[1] = uVar2;
      puVar5[2] = uVar9 + 0x400;
      if (uVar2 != 0) {
        piVar6 = piVar4;
        if (uVar2 == 0) {
          uVar2 = 1;
        }
        do {
          piVar6[2] = 0;
          piVar6 = piVar6 + 1;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      *(int **)(param_1 + 0x3bc) = piVar4;
      iVar10 = *piVar4;
      if (iVar10 != 0) {
        if (iVar10 == 0) {
          iVar10 = 1;
        }
        do {
          puVar1 = puVar7 + 2;
          puVar7 = puVar7 + 1;
          piVar4[2] = piVar4[2] | *puVar1;
          piVar4 = piVar4 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
      puVar7 = *(uint **)(param_1 + 0x3bc);
      uVar9 = puVar7[1];
      if (uVar9 != 0) {
        if ((puVar7[2] & 1) != 0) {
          uVar3 = 0;
          do {
            uVar3 = uVar3 + 1;
            uVar9 = uVar9 - 1;
            if (uVar9 == 0) goto LAB_000e82ec;
          } while ((*(uint *)((int)puVar7 + (uVar3 >> 3 & 0x1ffffffc) + 8) >> (uVar3 & 0x1f) & 1) !=
                   0);
          goto LAB_000e8388;
        }
        goto LAB_000e8324;
      }
    }
LAB_000e82ec:
    uVar3 = 0xffffffff;
  }
  else {
    if ((puVar7[2] & 1) != 0) {
      uVar3 = 0;
      uVar2 = uVar9;
      do {
        uVar3 = uVar3 + 1;
        uVar2 = uVar2 - 1;
        if (uVar2 == 0) goto LAB_000e8190;
      } while ((*(uint *)((int)puVar7 + (uVar3 >> 3 & 0x1ffffffc) + 8) >> (uVar3 & 0x1f) & 1) != 0);
      if (uVar3 != 0xffffffff) goto LAB_000e8388;
      goto LAB_000e8190;
    }
LAB_000e8324:
    uVar3 = 0;
  }
LAB_000e8388:
  uVar9 = uVar3 >> 3 & 0x1ffffffc;
  *(uint *)((int)puVar7 + uVar9 + 8) = 1 << (uVar3 & 0x1f) | *(uint *)((int)puVar7 + uVar9 + 8);
  return uVar3;
}

/* FUN_000e83bc @ 0xe83bc (104 bytes) */
int FUN_000e83bc(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x98);
  (**(code **)(*piVar3 + 0x34))(piVar3);
  iVar2 = piVar3[2];
  iVar1 = *(int *)(*(int *)(iVar2 + 0x88) + 8);
  while (iVar1 == 0x8e) {
    iVar2 = *(int *)(iVar2 + 8);
    iVar1 = *(int *)(*(int *)(iVar2 + 0x88) + 8);
  }
  return;
}

/* FUN_000e8424 @ 0xe8424 (216 bytes) */
int FUN_000e8424(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 200) + 8) + 0x88) + 8) == 0x8e) {
    piVar1 = *(int **)(param_1 + 0x98);
    for (piVar3 = (int *)(*(int **)(param_1 + 0x98))[2]; piVar3 != (int *)0x0;
        piVar3 = (int *)piVar3[2]) {
      if (((piVar1[5] & 1U) != 0) && (*(int *)(piVar1[0x22] + 8) != 0x8e)) {
        iVar2 = (**(code **)(*piVar1 + 0x34))(piVar1);
        if (iVar2 == 0) {
          ((int (*)())FUN_000e7700)(param_1,piVar1,param_2);
          return;
        }
        piVar3 = (int *)piVar1[2];
      }
      piVar1 = piVar3;
    }
  }
  else {
    FUN_00193f74(param_2,*(int *)(param_1 + 200));
    *(int *)(param_2 + 0x158) = param_1;
  }
  return;
}

/* FUN_000e84fc @ 0xe84fc (468 bytes) */
int FUN_000e84fc(param_1)
  int param_1;
{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  
  iVar4 = 0;
  for (uVar5 = 1; uVar5 <= *(uint *)(*(int *)(param_1 + 0xd4) + 4); uVar5 = uVar5 + 1) {
    iVar6 = *(int *)(iVar4 + *(int *)(*(int *)(param_1 + 0xd4) + 8));
    if (iVar6 != 0) {
      for (uVar7 = 1; uVar7 <= *(uint *)(*(int *)(iVar6 + 0xd0) + 4); uVar7 = uVar7 + 1) {
      }
    }
    iVar4 = iVar4 + 4;
  }
  iVar4 = 0;
  for (uVar5 = 1; uVar5 <= *(uint *)(*(int *)(param_1 + 0xd0) + 4); uVar5 = uVar5 + 1) {
    iVar6 = *(int *)(iVar4 + *(int *)(*(int *)(param_1 + 0xd0) + 8));
    if (iVar6 != 0) {
      for (uVar7 = 1; uVar7 <= *(uint *)(*(int *)(iVar6 + 0xd4) + 4); uVar7 = uVar7 + 1) {
      }
    }
    iVar4 = iVar4 + 4;
  }
  piVar2 = (int *)(*(int **)(param_1 + 0x98))[2];
  if (piVar2 != (int *)0x0) {
    iVar4 = 0;
    piVar8 = *(int **)(param_1 + 0x98);
    do {
      piVar3 = piVar2;
      if ((piVar8[5] & 1U) != 0) {
        bVar1 = iVar4 == 0;
        iVar4 = iVar4 + 1;
        if (bVar1) {
          (**(code **)(*piVar8 + 0x34))(piVar8);
        }
        iVar6 = *(int *)(param_1 + 0xa8);
        if (((*(uint *)(*(int *)(iVar6 + 0x6c4) + 0x30) & 4) != 0) &&
           (*(int *)(piVar8[0x22] + 8) == 0x8e)) {
          (**(code **)(*(int *)piVar8[1] + 0x34))();
          iVar6 = *(int *)(param_1 + 0xa8);
        }
        (**(code **)(*piVar8 + 8))(piVar8,iVar6);
        piVar3 = (int *)piVar8[2];
      }
      piVar2 = (int *)piVar3[2];
      piVar8 = piVar3;
    } while ((int *)piVar3[2] != (int *)0x0);
  }
  return 1;
}

/* FUN_000e86f0 @ 0xe86f0 (236 bytes) */
int FUN_000e86f0(param_1)
  int param_1;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0x98);
  for (piVar2 = (int *)(*(int **)(param_1 + 0x98))[2]; piVar2 != (int *)0x0;
      piVar2 = (int *)piVar2[2]) {
    if ((piVar1[5] & 1U) != 0) {
      iVar3 = (**(code **)(*piVar1 + 0x34))(piVar1);
      if ((((iVar3 == 0) && (iVar3 = (**(code **)(*piVar1 + 0x38))(piVar1), iVar3 == 0)) &&
          (*(int *)(piVar1[0x22] + 8) != 0x8e)) &&
         (iVar3 = (**(code **)(*piVar1 + 0x78))(piVar1), iVar3 == 0)) {
        (**(code **)(*piVar1 + 0x3c))(piVar1);
        piVar2 = (int *)piVar1[2];
      }
      else {
        piVar2 = (int *)piVar1[2];
      }
    }
    piVar1 = piVar2;
  }
  ((int (*)())FUN_000e84fc)(param_1);
  return;
}

/* FUN_000e87e4 @ 0xe87e4 (340 bytes) */
int FUN_000e87e4(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  *param_2 = 0;
  iVar2 = FUN_00194034(param_1[0x4e] + 0x90);
  if ((iVar2 < 3) && (iVar2 = FUN_00194034(param_1[0x4d] + 0x90), iVar2 < 3)) {
    iVar4 = param_1[0x4e];
    iVar2 = ((int (*)())FUN_000e79d0)(iVar4);
    if (iVar2 == 1) {
      iVar2 = *(int *)(iVar4 + 0xd0);
      piVar1 = (int *)0x0;
      if (*(int *)(iVar2 + 4) != 0) {
        piVar1 = *(int **)(iVar2 + 8);
      }
      if (((*piVar1 == param_1[0x4f]) && (iVar2 = ((int (*)())FUN_000e79d0)(param_1[0x4d]), iVar2 == 1)) &&
         (iVar2 = (**(code **)(*param_1 + 0x40))(param_1), iVar2 == 0)) {
        puVar3 = (undefined4 *)0x0;
        if (*(int *)(*(int *)(param_1[0x4d] + 0xd0) + 4) != 0) {
          puVar3 = *(undefined4 **)(*(int *)(param_1[0x4d] + 0xd0) + 8);
        }
        iVar2 = (**(code **)(*(int *)*puVar3 + 0x38))();
        if (iVar2 != 0) {
          return 1;
        }
        puVar3 = (undefined4 *)0x0;
        if (*(int *)(*(int *)(param_1[0x4d] + 0xd0) + 4) != 0) {
          puVar3 = *(undefined4 **)(*(int *)(param_1[0x4d] + 0xd0) + 8);
        }
        iVar2 = (**(code **)(*(int *)*puVar3 + 0x3c))();
        if (iVar2 != 0) {
          *param_2 = 1;
          return 1;
        }
      }
    }
  }
  return 0;
}

/* FUN_000e8938 @ 0xe8938 (176 bytes) */
int FUN_000e8938(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  puVar1 = puVar1 + 1;
  FUN_00108d5c(puVar1,*(undefined4 *)(param_1 + 0xa8));
  *(undefined4 **)(param_1 + 200) = puVar1;
  FUN_00193f94(param_1 + 0x90,puVar1);
  *(int *)(*(int *)(param_1 + 200) + 0x158) = param_1;
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar1 = uVar2;
  puVar1 = puVar1 + 1;
  FUN_00108df4(puVar1,*(undefined4 *)(param_1 + 0xa8));
  *(undefined4 **)(param_1 + 0xcc) = puVar1;
  FUN_00193f64(param_1 + 0x90,puVar1);
  *(int *)(*(int *)(param_1 + 0xcc) + 0x158) = param_1;
  return;
}

/* FUN_000e8a08 @ 0xe8a08 (376 bytes) */
int FUN_000e8a08(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[1] = 2;
  puVar1[4] = uVar2;
  puVar1[2] = 0;
  uVar2 = FUN_00193e18(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0xc4) = puVar1 + 1;
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[1] = 2;
  puVar1[4] = uVar2;
  puVar1[2] = 0;
  uVar2 = FUN_00193e18(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0xf8) = puVar1 + 1;
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[1] = 2;
  puVar1[2] = 0;
  puVar1[4] = uVar2;
  uVar2 = FUN_00193e18(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0xf4) = puVar1 + 1;
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x14);
  puVar1[1] = 2;
  *puVar1 = uVar2;
  puVar1[2] = 0;
  puVar1[4] = uVar2;
  uVar2 = FUN_00193e18(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0xd0) = puVar1 + 1;
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x14);
  puVar1[1] = 2;
  *puVar1 = uVar2;
  puVar1[2] = 0;
  puVar1[4] = uVar2;
  uVar2 = FUN_00193e18(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0xd4) = puVar1 + 1;
  return;
}

/* FUN_000e8bac @ 0xe8bac (104 bytes) */
int FUN_000e8bac(param_1)
  int param_1;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x148) + 0xa4) + 0x18);
  if (*piVar1 == 0) {
    piVar1 = (int *)FUN_0019423c(piVar1,0);
  }
  else {
    if (piVar1[1] == 0) {
      *(undefined4 *)piVar1[2] = 0;
      piVar1[1] = 1;
    }
    piVar1 = (int *)piVar1[2];
  }
  return *(undefined4 *)(*piVar1 + 0x50);
}

/* FUN_000e8c14 @ 0xe8c14 (104 bytes) */
int FUN_000e8c14(param_1)
  int param_1;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x148) + 0xa4) + 0x18);
  if (*piVar1 == 0) {
    piVar1 = (int *)FUN_0019423c(piVar1,0);
  }
  else {
    if (piVar1[1] == 0) {
      *(undefined4 *)piVar1[2] = 0;
      piVar1[1] = 1;
    }
    piVar1 = (int *)piVar1[2];
  }
  return *(undefined4 *)(*piVar1 + 0x38);
}

/* FUN_000e8c7c @ 0xe8c7c (104 bytes) */
int FUN_000e8c7c(param_1)
  int param_1;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x148) + 0xa4) + 0x18);
  if (*piVar1 == 0) {
    piVar1 = (int *)FUN_0019423c(piVar1,0);
  }
  else {
    if (piVar1[1] == 0) {
      *(undefined4 *)piVar1[2] = 0;
      piVar1[1] = 1;
    }
    piVar1 = (int *)piVar1[2];
  }
  return *(undefined4 *)(*piVar1 + 0x20);
}

/* FUN_000e8ce4 @ 0xe8ce4 (120 bytes) */
int FUN_000e8ce4(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0xf4);
  uVar2 = puVar3[1];
  if (uVar2 < *puVar3) {
    _memset((void *)(uVar2 * 4 + puVar3[2]),0,4);
    puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    puVar3[1] = uVar2 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar3,uVar2);
  }
  *puVar1 = param_2;
  return;
}

/* FUN_000e8d5c @ 0xe8d5c (120 bytes) */
int FUN_000e8d5c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0xd4);
  uVar2 = puVar3[1];
  if (uVar2 < *puVar3) {
    _memset((void *)(uVar2 * 4 + puVar3[2]),0,4);
    puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    puVar3[1] = uVar2 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar3,uVar2);
  }
  *puVar1 = param_2;
  return;
}

/* FUN_000e8dd4 @ 0xe8dd4 (120 bytes) */
int FUN_000e8dd4(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0xd0);
  uVar2 = puVar3[1];
  if (uVar2 < *puVar3) {
    _memset((void *)(uVar2 * 4 + puVar3[2]),0,4);
    puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    puVar3[1] = uVar2 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar3,uVar2);
  }
  *puVar1 = param_2;
  return;
}

/* FUN_000e8e4c @ 0xe8e4c (96 bytes) */
int FUN_000e8e4c(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_000e7de4)();
  if (iVar1 == 0) {
    ((int (*)())FUN_000e8dd4)(param_1,param_2);
    ((int (*)())FUN_000e8d5c)(param_2,param_1);
    return;
  }
  return;
}

/* FUN_000e8eac @ 0xe8eac (608 bytes) */
int FUN_000e8eac(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar10 = 1;
  iVar7 = 0;
  iVar4 = *(int *)(param_1 + 0xd4);
  do {
    if (*(uint *)(iVar4 + 4) < uVar10) {
      iVar4 = *(int *)(param_2 + 0xd0);
      uVar10 = 1;
      iVar7 = 0;
      do {
        if (*(uint *)(iVar4 + 4) < uVar10) {
          return;
        }
        iVar3 = *(int *)(iVar7 + *(int *)(iVar4 + 8));
        if (iVar3 != 0) {
          ((int (*)())FUN_000e8dd4)(param_3);
          iVar4 = 0;
          uVar9 = 0xffffffff;
          for (uVar5 = 1; uVar5 <= *(uint *)(*(int *)(iVar3 + 0xd4) + 4); uVar5 = uVar5 + 1) {
            iVar1 = *(int *)(*(int *)(*(int *)(iVar3 + 0xd4) + 8) + iVar4);
            uVar8 = uVar9;
            if ((iVar1 != 0) && (uVar8 = uVar9 + 1, param_2 == iVar1)) {
              puVar6 = *(uint **)(iVar3 + 0xd4);
              if (uVar8 < *puVar6) {
                uVar5 = puVar6[1];
                if (uVar5 <= uVar8) {
                  _memset((void *)(uVar5 * 4 + puVar6[2]),0,(uVar8 - uVar5) * 4 + 4);
                  puVar6[1] = uVar9 + 2;
                }
                puVar2 = (undefined4 *)(uVar8 * 4 + puVar6[2]);
              }
              else {
                puVar2 = (undefined4 *)FUN_0019423c(puVar6,uVar8);
              }
              *puVar2 = param_3;
              iVar4 = *(int *)(param_2 + 0xd0);
              goto LAB_000e9098;
            }
            iVar4 = iVar4 + 4;
            uVar9 = uVar8;
          }
          iVar4 = *(int *)(param_2 + 0xd0);
        }
LAB_000e9098:
        uVar10 = uVar10 + 1;
        iVar7 = iVar7 + 4;
      } while( true );
    }
    iVar3 = *(int *)(iVar7 + *(int *)(iVar4 + 8));
    if (iVar3 != 0) {
      ((int (*)())FUN_000e8d5c)(param_3);
      iVar4 = 0;
      uVar9 = 0xffffffff;
      for (uVar5 = 1; uVar5 <= *(uint *)(*(int *)(iVar3 + 0xd0) + 4); uVar5 = uVar5 + 1) {
        iVar1 = *(int *)(iVar4 + *(int *)(*(int *)(iVar3 + 0xd0) + 8));
        uVar8 = uVar9;
        if ((iVar1 != 0) && (uVar8 = uVar9 + 1, param_1 == iVar1)) {
          puVar6 = *(uint **)(iVar3 + 0xd0);
          if (uVar8 < *puVar6) {
            uVar5 = puVar6[1];
            if (uVar5 <= uVar8) {
              _memset((void *)(uVar5 * 4 + puVar6[2]),0,(uVar8 - uVar5) * 4 + 4);
              puVar6[1] = uVar9 + 2;
            }
            puVar2 = (undefined4 *)(uVar8 * 4 + puVar6[2]);
          }
          else {
            puVar2 = (undefined4 *)FUN_0019423c(puVar6,uVar8);
          }
          *puVar2 = param_3;
          iVar4 = *(int *)(param_1 + 0xd4);
          goto LAB_000e8f80;
        }
        iVar4 = iVar4 + 4;
        uVar9 = uVar8;
      }
      iVar4 = *(int *)(param_1 + 0xd4);
    }
LAB_000e8f80:
    uVar10 = uVar10 + 1;
    iVar7 = iVar7 + 4;
  } while( true );
}

/* FUN_000e910c @ 0xe910c (120 bytes) */
int FUN_000e910c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0xf8);
  uVar2 = puVar3[1];
  if (uVar2 < *puVar3) {
    _memset((void *)(uVar2 * 4 + puVar3[2]),0,4);
    puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    puVar3[1] = uVar2 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar3,uVar2);
  }
  *puVar1 = param_2;
  return;
}

/* FUN_000e9184 @ 0xe9184 (136 bytes) */
int FUN_000e9184(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0xd4);
  if (param_2 < *puVar3) {
    uVar1 = puVar3[1];
    if (uVar1 <= param_2) {
      _memset((void *)(uVar1 * 4 + puVar3[2]),0,(param_2 - uVar1) * 4 + 4);
      puVar3[1] = param_2 + 1;
    }
    puVar2 = (undefined4 *)(param_2 * 4 + puVar3[2]);
  }
  else {
    puVar2 = (undefined4 *)FUN_0019423c(puVar3);
  }
  return *puVar2;
}

/* FUN_000e920c @ 0xe920c (136 bytes) */
int FUN_000e920c(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0xd0);
  if (param_2 < *puVar3) {
    uVar1 = puVar3[1];
    if (uVar1 <= param_2) {
      _memset((void *)(uVar1 * 4 + puVar3[2]),0,(param_2 - uVar1) * 4 + 4);
      puVar3[1] = param_2 + 1;
    }
    puVar2 = (undefined4 *)(param_2 * 4 + puVar3[2]);
  }
  else {
    puVar2 = (undefined4 *)FUN_0019423c(puVar3);
  }
  return *puVar2;
}

/* FUN_000e9294 @ 0xe9294 (280 bytes) */
int FUN_000e9294(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(param_1 + 0x134);
  iVar1 = ((int (*)())FUN_000e79d0)(uVar3);
  if ((iVar1 == 1) && (iVar1 = ((int (*)())FUN_000e79d0)(*(undefined4 *)(param_1 + 0x138)), iVar1 == 1)) {
    piVar2 = (int *)((int (*)())FUN_000e920c)(uVar3,0);
    iVar1 = (**(code **)(*piVar2 + 0x28))();
    if (iVar1 != 0) {
      piVar2 = (int *)((int (*)())FUN_000e920c)(*(undefined4 *)(param_1 + 0x138),0);
      iVar1 = (**(code **)(*piVar2 + 0x28))();
      if (iVar1 != 0) {
        uVar3 = *(undefined4 *)(param_1 + 0x134);
        iVar1 = ((int (*)())FUN_000e79dc)(uVar3);
        if ((iVar1 == 1) && (iVar1 = ((int (*)())FUN_000e79dc)(*(undefined4 *)(param_1 + 0x138)), iVar1 == 1)) {
          piVar2 = (int *)((int (*)())FUN_000e9184)(uVar3,0);
          iVar1 = (**(code **)(*piVar2 + 0x24))();
          if (iVar1 != 0) {
            piVar2 = (int *)((int (*)())FUN_000e9184)(*(undefined4 *)(param_1 + 0x138),0);
            iVar1 = (**(code **)(*piVar2 + 0x24))();
            if (iVar1 != 0) {
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_000e93ac @ 0xe93ac (900 bytes) */
int FUN_000e93ac(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int *param_3;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  
  uVar7 = 0;
  (**(code **)(*param_1 + 0x20))();
  (**(code **)(*param_1 + 0x1c))(param_1);
  iVar5 = 0;
  for (uVar4 = 1; uVar4 <= *(uint *)(param_2[0x34] + 4); uVar4 = uVar4 + 1) {
    piVar1 = *(int **)(iVar5 + *(int *)(param_2[0x34] + 8));
    if (piVar1 != (int *)0x0) {
      if (param_1 == piVar1) {
        iVar5 = (**(code **)(*param_3 + 0x20))(param_3);
        if ((iVar5 == 0) || ((*(uint *)(param_1[0x2b] + 0x30) & 2) != 0)) {
          puVar8 = (uint *)param_2[0x34];
          if (uVar7 < *puVar8) {
            uVar4 = puVar8[1];
            if (uVar4 <= uVar7) {
              _memset((void *)(uVar4 * 4 + puVar8[2]),0,(uVar7 - uVar4) * 4 + 4);
              puVar8[1] = uVar7 + 1;
            }
            puVar2 = (undefined4 *)(uVar7 * 4 + puVar8[2]);
          }
          else {
            puVar2 = (undefined4 *)FUN_0019423c(puVar8,uVar7);
          }
          *puVar2 = param_3;
        }
        else {
          FUN_00194208(param_2[0x34],uVar7);
        }
        break;
      }
      uVar7 = uVar7 + 1;
    }
    iVar5 = iVar5 + 4;
  }
  iVar5 = param_1[0x35];
  iVar3 = 0;
  iVar6 = 0;
  for (uVar4 = 1; uVar4 <= *(uint *)(iVar5 + 4); uVar4 = uVar4 + 1) {
    piVar1 = *(int **)(iVar6 + *(int *)(iVar5 + 8));
    if (piVar1 != (int *)0x0) {
      if (param_2 == piVar1) {
        FUN_00194208(iVar5,iVar3);
        break;
      }
      iVar3 = iVar3 + 1;
    }
    iVar6 = iVar6 + 4;
  }
  puVar8 = (uint *)param_3[0x35];
  uVar7 = 0;
  iVar5 = 0;
  for (uVar4 = 1; uVar4 <= puVar8[1]; uVar4 = uVar4 + 1) {
    if (*(int **)(puVar8[2] + iVar5) != (int *)0x0) {
      if (param_1 == *(int **)(puVar8[2] + iVar5)) {
        if (uVar7 < *puVar8) {
          uVar4 = puVar8[1];
          if (uVar4 <= uVar7) {
            _memset((void *)(uVar4 * 4 + puVar8[2]),0,(uVar7 - uVar4) * 4 + 4);
            puVar8[1] = uVar7 + 1;
          }
          puVar2 = (undefined4 *)(uVar7 * 4 + puVar8[2]);
        }
        else {
          puVar2 = (undefined4 *)FUN_0019423c(puVar8,uVar7);
        }
        *puVar2 = param_2;
        break;
      }
      uVar7 = uVar7 + 1;
    }
    iVar5 = iVar5 + 4;
  }
  iVar5 = param_1[0x34];
  iVar3 = 0;
  uVar4 = 1;
  iVar6 = 0;
  do {
    if (*(uint *)(iVar5 + 4) < uVar4) {
LAB_000e9610:
      if ((*(uint *)(param_1[0x2b] + 0x30) & 2) == 0) {
        iVar5 = (**(code **)(*param_3 + 0x20))(param_3);
        if ((iVar5 == 0) || (iVar5 = ((int (*)())FUN_000e79d0)(param_2), iVar5 != 0)) {
          (**(code **)(*param_2 + 0x48))(param_2);
        }
        iVar5 = (**(code **)(*param_3 + 0x20))(param_3);
        if ((iVar5 != 0) && (iVar5 = ((int (*)())FUN_000e79dc)(param_3), iVar5 == 0)) {
          return 1;
        }
      }
      else {
        (**(code **)(*param_2 + 0x48))(param_2);
      }
      (**(code **)(*param_3 + 0x48))(param_3);
      return 1;
    }
    piVar1 = *(int **)(*(int *)(iVar5 + 8) + iVar6);
    if (piVar1 != (int *)0x0) {
      if (param_3 == piVar1) {
        FUN_00194208(iVar5,iVar3);
        goto LAB_000e9610;
      }
      iVar3 = iVar3 + 1;
    }
    uVar4 = uVar4 + 1;
    iVar6 = iVar6 + 4;
  } while( true );
}

