#include "decls.h"

/* FUN_0019d858 @ 0x19d858 (1008 bytes) */
int FUN_0019d858(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  double fparam_1;
  
  piVar11 = *(int **)(param_2 + 0xac);
  iVar5 = FUN_000e7804(param_2,param_2,param_3,param_4,param_5,param_6,param_7);
  if (*piVar11 != 0) goto LAB_0019dc0c;
  piVar8 = (int *)0x0;
  uVar4 = *(uint *)(param_1[0x25] + 4);
  uVar3 = uVar4 - 1;
  if (uVar3 < uVar4) {
    piVar8 = (int *)(uVar3 * 4 + *(int *)(param_1[0x25] + 8));
  }
  iVar10 = *piVar8;
  iVar6 = FUN_001054ec(iVar5,1);
  uVar3 = *(uint *)(iVar6 + 0x10);
  iVar6 = *(int *)(*(int *)(iVar5 + 0x88) + 8);
  if (iVar6 == 0x8b) {
    if (*(int *)(iVar5 + 300) != 0) goto LAB_0019dab0;
    piVar8 = (int *)FUN_001043f0(0x12,param_6);
    iVar6 = FUN_001054ec(piVar8,1);
    uVar4 = *(uint *)(iVar5 + 0xb8);
    *(uint *)(iVar6 + 0x10) = uVar3;
    FUN_00103d50(piVar8 + 0x29,1,uVar4 & 1);
    uVar7 = FUN_00105594(iVar5,1);
    FUN_00106004(piVar8,1,uVar7,0,param_6);
    uVar7 = FUN_00105594(iVar5,2);
    FUN_00106004(piVar8,2,uVar7,0,param_6);
    FUN_00103d50(piVar8 + 0x2f,1,1);
    iVar6 = FUN_0019d430(param_1,piVar11);
    piVar8[0x25] = iVar6;
    piVar8[0x26] = 0;
    (**(code **)(*piVar8 + 0x84))(piVar8,iVar10);
    FUN_000e7688(param_2,piVar8);
  }
  else if (iVar6 == 0x8c) {
    if (*(int *)(iVar5 + 300) == 0) {
      piVar8 = (int *)FUN_00105594(iVar5,1);
    }
    else {
      piVar8 = (int *)FUN_001043f0(0x12,param_6);
      iVar6 = FUN_001054ec(piVar8,1);
      uVar4 = *(uint *)(iVar5 + 0xb8);
      *(uint *)(iVar6 + 0x10) = uVar3;
      FUN_00103d50(piVar8 + 0x29,1,uVar4 & 1);
      uVar7 = FUN_00105594(iVar5,1);
      FUN_00106004(piVar8,1,uVar7,0,param_6);
      fparam_1 = (double)FLOAT_001aa0e8;
      ((void (*)())FUN_000f79c4)(piVar8,piVar11,2,fparam_1,fparam_1,fparam_1,fparam_1);
      FUN_00103d50(piVar8 + 0x2f,1,1);
      iVar6 = FUN_0019d430(param_1,piVar11);
      piVar8[0x25] = iVar6;
      piVar8[0x26] = 0;
      (**(code **)(*piVar8 + 0x84))(piVar8,iVar10);
      FUN_000e7688(param_2,piVar8);
    }
  }
  else {
LAB_0019dab0:
    piVar8 = (int *)0x0;
  }
  iVar6 = FUN_0019d4e8(param_1);
  iVar9 = *(int *)(iVar6 + 0x94);
  piVar11 = (int *)FUN_001043f0(0x54,param_6);
  iVar6 = DAT_001b2d54;
  piVar11[0x26] = 0;
  piVar11[0x27] = iVar6;
  piVar11[0x25] = 0;
  FUN_00106004(piVar11,1,piVar8,0,param_6);
  iVar6 = 0;
  do {
    (**(code **)(*piVar11 + 0x88))(piVar11,1,iVar6,uVar3 & 0xff);
    bVar1 = iVar6 != 3;
    iVar6 = iVar6 + 1;
  } while (bVar1);
  iVar6 = 0;
  (**(code **)(*piVar11 + 0x84))(piVar11,iVar10);
  FUN_000e7688(param_2,piVar11);
  piVar11 = (int *)FUN_001043f0(0x3e,param_6);
  FUN_00106004(piVar11,1,piVar8,0,param_6);
  do {
    (**(code **)(*piVar11 + 0x88))(piVar11,1,iVar6,uVar3 & 0xff);
    iVar2 = DAT_001b2d50;
    bVar1 = iVar6 != 3;
    iVar6 = iVar6 + 1;
  } while (bVar1);
  piVar11[0x25] = iVar9;
  piVar11[0x27] = iVar2;
  piVar11[0x26] = 0;
  (**(code **)(*piVar11 + 0x84))(piVar11,3 - (uint)(iVar10 == 3));
  FUN_000e7688(param_2,piVar11);
  FUN_00193f20(iVar5);
  *(undefined4 *)(param_2 + 0x130) = 0;
LAB_0019dc0c:
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  FUN_000e2860(*(undefined4 *)(param_2 + 0x13c),param_5);
  return;
}

/* FUN_0019dc48 @ 0x19dc48 (104 bytes) */
int FUN_0019dc48(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0xa0);
  uVar1 = FUN_000e7d5c(*(undefined4 *)(param_2 + 300));
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,uVar1);
  return;
}

/* FUN_0019dcb0 @ 0x19dcb0 (156 bytes) */
int FUN_0019dcb0(param_1)
  undefined4 *param_1;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = param_1[0x26];
  *param_1 = &PTR_FUN_001eb8d8;
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = param_1[0x25];
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  FUN_0019b91c(param_1);
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  iVar2 = param_1[-1];
  if ((*(int *)(iVar2 + 0x28) != 0) &&
     (puVar1 = *(undefined4 **)(iVar2 + 0x14), puVar1 == param_1 + -1)) {
    _memset(puVar1,0,*(int *)(iVar2 + 8) - (int)puVar1);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 0x14);
  }
  return;
}

/* FUN_0019dd7c @ 0x19dd7c (180 bytes) */
int FUN_0019dd7c(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  FUN_0019acb0(param_1,param_2,param_3,param_4);
  *(undefined4 *)(param_1 + 0x8c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x90) = 0;
  uVar2 = *(undefined4 *)(param_4 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[1] = 2;
  puVar1[4] = uVar2;
  puVar1[2] = 0;
  uVar2 = FUN_00193e18(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0x98) = puVar1 + 1;
  uVar2 = *(undefined4 *)(param_4 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[1] = 2;
  puVar1[2] = 0;
  puVar1[4] = uVar2;
  uVar2 = FUN_00193e18(uVar2,8);
  puVar1[3] = uVar2;
  *(undefined4 **)(param_1 + 0x94) = puVar1 + 1;
  return;
}

/* FUN_0019de50 @ 0x19de50 (96 bytes) */
int FUN_0019de50(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0xa0);
  *puVar1 = uVar2;
  puVar1[1] = &PTR_FUN_001eb8d8;
  puVar1[7] = 0;
  return puVar1 + 1;
}

/* FUN_0019deb0 @ 0x19deb0 (120 bytes) */
int FUN_0019deb0(param_1)
  undefined4 *param_1;
{
  int iVar1;
  
  iVar1 = param_1[0x26];
  *param_1 = &PTR_FUN_001eb8d8;
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x25];
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  *param_1 = &PTR_FUN_001eb808;
  FUN_00193cc0(*(undefined4 *)(param_1[3] + 0x374),param_1[2]);
  param_1[2] = 0;
  FUN_00193cc0(*(undefined4 *)(param_1[3] + 0x374),param_1[0x18]);
  param_1[0x11] = 0;
  *param_1 = PTR_DAT_001e914c + 8;
  return;
}

/* FUN_0019df54 @ 0x19df54 (120 bytes) */
int FUN_0019df54(param_1)
  undefined4 *param_1;
{
  int iVar1;
  
  iVar1 = param_1[0x26];
  *param_1 = &PTR_FUN_001eb8d8;
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x25];
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  *param_1 = &PTR_FUN_001eb808;
  FUN_00193cc0(*(undefined4 *)(param_1[3] + 0x374),param_1[2]);
  param_1[2] = 0;
  FUN_00193cc0(*(undefined4 *)(param_1[3] + 0x374),param_1[0x18]);
  param_1[0x11] = 0;
  *param_1 = PTR_DAT_001e914c + 8;
  return;
}

/* FUN_0019dff8 @ 0x19dff8 (292 bytes) */
int FUN_0019dff8(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = *(int **)(param_2 + 0xac);
  FUN_00194208(param_1[0x25],*(int *)(param_1[0x25] + 4) + -1);
  if (*piVar5 == 0) {
    piVar5 = (int *)0x0;
    uVar3 = *(uint *)(param_1[0x25] + 4);
    uVar2 = uVar3 - 1;
    if (uVar2 < uVar3) {
      piVar5 = (int *)(uVar2 * 4 + *(int *)(param_1[0x25] + 8));
    }
    iVar6 = *piVar5;
    FUN_000e2bf4(param_3,iVar6);
    if (iVar6 != 0) {
      iVar6 = FUN_001043f0(0x58,param_4);
      iVar4 = FUN_0019d4e8(param_1);
      uVar1 = DAT_001b2d50;
      *(undefined4 *)(iVar6 + 0x94) = *(undefined4 *)(iVar4 + 0x94);
      *(undefined4 *)(iVar6 + 0x98) = 0;
      *(undefined4 *)(iVar6 + 0x9c) = uVar1;
      FUN_00106004(iVar6,1,iVar4,0,param_4);
      uVar1 = DAT_001b2d4c;
      iVar4 = FUN_001054ec(iVar6,1);
      *(undefined4 *)(iVar4 + 0x10) = uVar1;
      FUN_000e76c4(param_2,iVar6);
    }
  }
                    
                    
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  return;
}

/* FUN_0019e11c @ 0x19e11c (508 bytes) */
int FUN_0019e11c(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  
  piVar7 = *(int **)(param_2 + 0xac);
  if (((0 < *(int *)(*(int *)(param_2 + 300) + 0x138)) ||
      (*(int *)(*(int *)(param_2 + 300) + 0x13c) != 0)) &&
     (FUN_00194208(param_1[0x25],*(int *)(param_1[0x25] + 4) + -1), *piVar7 == 0)) {
    puVar4 = (undefined4 *)0x0;
    uVar2 = *(uint *)(param_1[0x25] + 4);
    uVar1 = uVar2 - 1;
    if (uVar1 < uVar2) {
      puVar4 = (undefined4 *)(uVar1 * 4 + *(int *)(param_1[0x25] + 8));
    }
    FUN_000e2bf4(param_3,*puVar4);
    iVar3 = param_1[0x26];
    uVar1 = *(uint *)(iVar3 + 4);
    if (0 < (int)uVar1) {
      uVar2 = uVar1 - 1;
      puVar4 = (undefined4 *)0x0;
      if (uVar2 < uVar1) {
        puVar4 = (undefined4 *)(uVar2 * 4 + *(int *)(iVar3 + 8));
      }
      uVar5 = *puVar4;
      FUN_00194208(iVar3,uVar1 - 1);
      iVar3 = FUN_0019d4e8(param_1);
      iVar6 = *(int *)(iVar3 + 0x94);
      piVar7 = (int *)FUN_001043f0(0x5a,param_4);
      iVar3 = DAT_001b2d50;
      piVar7[0x25] = iVar6;
      piVar7[0x26] = 0;
      piVar7[0x27] = iVar3;
      FUN_00106004(piVar7,1,uVar5,0,param_4);
      if ((3 < (int)uVar1) && (uVar2 = 0, (int)uVar1 < 8)) {
        uVar2 = uVar1 - 4;
      }
      (**(code **)(*piVar7 + 0x88))(piVar7,1,0,uVar2);
      (**(code **)(*piVar7 + 0x88))(piVar7,1,1,uVar2);
      (**(code **)(*piVar7 + 0x88))(piVar7,1,2,uVar2);
      (**(code **)(*piVar7 + 0x88))(piVar7,1,3,uVar2);
      FUN_000e76c4(param_2,piVar7);
    }
  }
                    
                    
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  return;
}

/* FUN_0019e318 @ 0x19e318 (840 bytes) */
int FUN_0019e318(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  code *pcVar10;
  uint *puVar11;
  bool bVar12;
  
  piVar9 = *(int **)(param_2 + 0xac);
  piVar5 = (int *)FUN_000e7804(param_2,param_2,param_3,param_4,param_5,param_6,param_7);
  if (*piVar9 != 0) goto LAB_0019e5d0;
  (**(code **)(*piVar5 + 0x14))();
  piVar9 = (int *)0x0;
  uVar3 = *(uint *)(param_1[0x25] + 4);
  uVar2 = uVar3 - 1;
  if (uVar2 < uVar3) {
    piVar9 = (int *)(uVar2 * 4 + *(int *)(param_1[0x25] + 8));
  }
  iVar4 = piVar5[0x4b];
  bVar12 = *piVar9 == 0;
  if (iVar4 == 1) {
    if (bVar12) {
      uVar6 = 0x54;
    }
    else {
      uVar6 = 0x2d;
    }
  }
  else if (iVar4 < 2) {
    if (iVar4 == 0) {
      if (bVar12) {
        uVar6 = 0x53;
      }
      else {
        uVar6 = 0x2c;
      }
    }
    else {
LAB_0019e3d4:
      uVar6 = 0;
    }
  }
  else if (iVar4 == 2) {
    if (bVar12) {
      uVar6 = 0x55;
    }
    else {
      uVar6 = 0x2e;
    }
  }
  else {
    if (iVar4 != 3) goto LAB_0019e3d4;
    if (bVar12) {
      uVar6 = 0x56;
    }
    else {
      uVar6 = 0x2f;
    }
  }
  piVar9 = (int *)FUN_001043f0(uVar6,param_4);
  if (bVar12) {
    if (*(int *)(param_2 + 0x144) == 0) {
      iVar7 = FUN_0019d4e8(param_1);
      iVar4 = DAT_001b2d50;
      piVar9[0x25] = *(int *)(iVar7 + 0x94);
      piVar9[0x26] = 0;
      piVar9[0x27] = iVar4;
    }
    else {
      piVar9[0x26] = 0;
      iVar4 = DAT_001b2d54;
      piVar9[0x25] = 0;
      piVar9[0x27] = iVar4;
    }
    uVar6 = FUN_00105594(piVar5,1);
    FUN_00106004(piVar9,1,uVar6,0,param_4);
  }
  else {
    iVar7 = FUN_0019d4e8(param_1);
    iVar4 = DAT_001b2d50;
    piVar9[0x25] = *(int *)(iVar7 + 0x94);
    piVar9[0x26] = 0;
    piVar9[0x27] = iVar4;
    FUN_00106004(piVar9,1,iVar7,0,param_4);
    uVar6 = DAT_001b2d4c;
    iVar4 = FUN_001054ec(piVar9,1);
    *(undefined4 *)(iVar4 + 0x10) = uVar6;
    uVar6 = FUN_00105594(piVar5,1);
    FUN_00106004(piVar9,2,uVar6,0,param_4);
  }
  iVar4 = 0;
  do {
    pcVar10 = *(code **)(*piVar9 + 0x88);
    if (bVar12) {
      uVar6 = 1;
    }
    else {
      uVar6 = 2;
    }
    iVar7 = FUN_001054ec(piVar5,1);
    (*pcVar10)(piVar9,uVar6,iVar4,*(undefined1 *)(iVar7 + 0x13));
    bVar1 = iVar4 != 3;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  if ((piVar5[0x2e] & 1U) != 0) {
    if (bVar12) {
      iVar4 = 1;
    }
    else {
      iVar4 = 2;
    }
    FUN_00103d50(piVar9 + iVar4 * 6 + 0x23,1,1);
  }
  FUN_000e7688(param_2,piVar9);
  FUN_00193f20(piVar5);
  *(undefined4 *)(param_2 + 0x130) = 0;
LAB_0019e5d0:
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  puVar11 = (uint *)param_1[0x25];
  uVar2 = puVar11[1];
  if (uVar2 < *puVar11) {
    _memset(uVar2 * 4 + puVar11[2],0,4);
    puVar8 = (undefined4 *)(uVar2 * 4 + puVar11[2]);
    puVar11[1] = uVar2 + 1;
  }
  else {
    puVar8 = (undefined4 *)FUN_0019423c(puVar11,uVar2);
  }
  *puVar8 = 3;
  return;
}

/* FUN_0019e660 @ 0x19e660 (128 bytes) */
int FUN_0019e660(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  
  FUN_0019adf8(param_1,param_2);
  puVar3 = *(uint **)(param_1 + 0x94);
  uVar2 = puVar3[1];
  if (uVar2 < *puVar3) {
    _memset(uVar2 * 4 + puVar3[2],0,4);
    puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    puVar3[1] = uVar2 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar3,uVar2);
  }
  *puVar1 = 0;
  return;
}

/* FUN_0019e6e0 @ 0x19e6e0 (688 bytes) */
int FUN_0019e6e0(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar9;
  int iVar10;
  double fparam_1;
  
  piVar8 = *(int **)(param_2 + 0xac);
  if ((0 < *(int *)(param_2 + 0x138)) || (*(int *)(param_2 + 0x13c) != 0)) {
    iVar3 = FUN_0019d4e8(param_1);
    puVar9 = (uint *)param_1[0x25];
    uVar7 = *(undefined4 *)(iVar3 + 0x94);
    piVar6 = (int *)0x0;
    uVar2 = puVar9[1] - 1;
    if (uVar2 < puVar9[1]) {
      piVar6 = (int *)(uVar2 * 4 + puVar9[2]);
    }
    if (*piVar6 == 0) {
      if (*piVar8 == 0) {
        iVar3 = FUN_001043f0(0x53,param_4);
        uVar1 = DAT_001b2d50;
        fparam_1 = (double)FLOAT_001aa0d4;
        *(undefined4 *)(iVar3 + 0x94) = uVar7;
        *(undefined4 *)(iVar3 + 0x9c) = uVar1;
        *(undefined4 *)(iVar3 + 0x98) = 0;
        ((void (*)())FUN_000f79c4)(iVar3,piVar8,1,fparam_1,fparam_1,fparam_1,fparam_1);
        *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffffb;
        FUN_000e7688(param_2,iVar3);
        puVar9 = (uint *)param_1[0x25];
      }
    }
    else if (*piVar8 == 0) {
      iVar10 = *(int *)(param_1[0x26] + 4);
      if (2 < iVar10) {
        if (iVar10 < 7) {
          uVar7 = FUN_00130690(piVar8,0);
          iVar10 = iVar10 + -3;
        }
        else {
          uVar7 = 0;
          iVar10 = 0;
        }
      }
      iVar4 = FUN_001084b8(0x66,param_4);
      *(undefined4 *)(iVar4 + 0x9c) = DAT_001b2d54;
      *(undefined1 *)(iVar10 + iVar4 + 0x9c) = 0;
      *(undefined4 *)(iVar4 + 0x98) = 0;
      *(undefined4 *)(iVar4 + 0x94) = uVar7;
      FUN_00106004(iVar4,1,iVar3,0,param_4);
      uVar7 = DAT_001b2d4c;
      iVar3 = FUN_001054ec(iVar4,1);
      *(undefined4 *)(iVar3 + 0x10) = uVar7;
      *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) & 0xfffffffb;
      FUN_000e7688(param_2,iVar4);
      puVar9 = (uint *)param_1[0x26];
      uVar2 = puVar9[1];
      if (uVar2 < *puVar9) {
        _memset(uVar2 * 4 + puVar9[2],0,4);
        piVar8 = (int *)(uVar2 * 4 + puVar9[2]);
        puVar9[1] = uVar2 + 1;
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar9,uVar2);
      }
      *piVar8 = iVar4;
      puVar9 = (uint *)param_1[0x25];
    }
    uVar2 = puVar9[1];
    if (uVar2 < *puVar9) {
      _memset(uVar2 * 4 + puVar9[2],0,4);
      puVar5 = (undefined4 *)(uVar2 * 4 + puVar9[2]);
      puVar9[1] = uVar2 + 1;
    }
    else {
      puVar5 = (undefined4 *)FUN_0019423c(puVar9,uVar2);
    }
    *puVar5 = 3;
  }
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x9c);
  uVar7 = FUN_000e7d5c(param_2);
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,uVar7,*(undefined4 *)(param_2 + 0x134));
  return;
}

/* FUN_0019e990 @ 0x19e990 (108 bytes) */
int FUN_0019e990(param_1, param_2)
  uint *param_1;
  int param_2;
{
  if ((*param_1 & 0x400000) != 0) {
    if (param_2 == 1) {
      return param_1[1] >> 2 & 3;
    }
    if (param_2 < 2) {
      if (param_2 == 0) {
        return param_1[1] & 3;
      }
    }
    else {
      if (param_2 == 2) {
        return param_1[1] >> 4 & 3;
      }
      if (param_2 == 3) {
        return param_1[1] >> 6 & 3;
      }
    }
  }
  return 1;
}

/* FUN_0019e9fc @ 0x19e9fc (168 bytes) */
int FUN_0019e9fc(param_1, param_2)
  uint *param_1;
  int param_2;
{
  if ((*param_1 & 0x400000) == 0) {
    if (param_2 == 1) {
      return 1;
    }
    if (param_2 < 2) {
      if (param_2 == 0) {
        return 0;
      }
    }
    else {
      if (param_2 == 2) {
        return 2;
      }
      if (param_2 == 3) {
        return 3;
      }
    }
  }
  else {
    if (param_2 == 1) {
      return param_1[1] >> 4 & 7;
    }
    if (param_2 < 2) {
      if (param_2 == 0) {
        return param_1[1] & 7;
      }
    }
    else {
      if (param_2 == 2) {
        return param_1[1] >> 8 & 7;
      }
      if (param_2 == 3) {
        return param_1[1] >> 0xc & 7;
      }
    }
  }
  return 0xffffffff;
}

/* FUN_0019eaa4 @ 0x19eaa4 (32 bytes) */
int FUN_0019eaa4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  uint *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if ((*param_1 & 0x400000) == 0) {
    return 0;
  }
  return param_1[1] & 0x8888;
}

/* FUN_0019eac4 @ 0x19eac4 (108 bytes) */
int FUN_0019eac4(param_1, param_2)
  uint *param_1;
  int param_2;
{
  if ((*param_1 & 0x400000) != 0) {
    if (param_2 == 1) {
      return param_1[1] >> 7 & 1;
    }
    if (param_2 < 2) {
      if (param_2 == 0) {
        return param_1[1] >> 3 & 1;
      }
    }
    else {
      if (param_2 == 2) {
        return param_1[1] >> 0xb & 1;
      }
      if (param_2 == 3) {
        return param_1[1] >> 0xf & 1;
      }
    }
  }
  return 0;
}

/* FUN_0019eb30 @ 0x19eb30 (172 bytes) */
int FUN_0019eb30(param_1)
  uint *param_1;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if ((*param_1 & 0x400000) == 0) {
    return 0;
  }
  uVar1 = param_1[1];
  if (1 < (uVar1 & 3) - 2) {
    iVar3 = 4;
    iVar2 = 0;
    do {
      while( true ) {
        do {
          while( true ) {
            iVar2 = iVar2 + 1;
            iVar3 = iVar3 + -1;
            if (iVar3 == 0) {
              return 0;
            }
            if (iVar2 != 1) break;
            if ((uVar1 & 0xc) == 8) {
              return 1;
            }
            if ((uVar1 & 0xc) == 0xc) {
              return 1;
            }
          }
        } while (iVar2 < 2);
        if (iVar2 != 2) break;
        if ((uVar1 & 0x30) == 0x20) {
          return 1;
        }
        if ((uVar1 & 0x30) == 0x30) {
          return 1;
        }
      }
    } while ((iVar2 != 3) || (((uVar1 & 0xc0) != 0x80 && ((uVar1 & 0xc0) != 0xc0))));
  }
  return 1;
}

/* FUN_0019ebdc @ 0x19ebdc (172 bytes) */
int FUN_0019ebdc(param_1)
  uint *param_1;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if ((*param_1 & 0x400000) == 0) {
    return 0;
  }
  uVar1 = param_1[1];
  if (1 < (uVar1 & 7) - 4) {
    iVar3 = 4;
    iVar2 = 0;
    do {
      while( true ) {
        do {
          while( true ) {
            iVar2 = iVar2 + 1;
            iVar3 = iVar3 + -1;
            if (iVar3 == 0) {
              return 0;
            }
            if (iVar2 != 1) break;
            if ((uVar1 & 0x70) == 0x40) {
              return 1;
            }
            if ((uVar1 & 0x70) == 0x50) {
              return 1;
            }
          }
        } while (iVar2 < 2);
        if (iVar2 != 2) break;
        if ((uVar1 & 0x700) == 0x400) {
          return 1;
        }
        if ((uVar1 & 0x700) == 0x500) {
          return 1;
        }
      }
    } while ((iVar2 != 3) ||
            (((undefined *)(uVar1 & 0x7000) != (undefined *)0x4000 &&
             ((undefined *)(uVar1 & 0x7000) != ((unsigned char *)0x00005000)))));
  }
  return 1;
}

/* FUN_0019ec88 @ 0x19ec88 (108 bytes) */
int FUN_0019ec88(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  
  if (param_1 == 1) {
    param_3 = param_3 + 4;
  }
  else {
    iVar2 = 0;
    if (-1 < param_2) {
      do {
        iVar2 = iVar2 + 1;
        iVar1 = ((int (*)())FUN_0019ecf4)(param_3);
        param_3 = param_3 + iVar1 * 4;
      } while (iVar2 <= param_2);
    }
  }
  return param_3;
}

/* FUN_0019ecf4 @ 0x19ecf4 (192 bytes) */
int FUN_0019ecf4(param_1)
  uint *param_1;
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = param_1 + 1;
  uVar1 = *param_1;
  if ((uVar1 & 0x400000) != 0) {
    puVar3 = param_1 + 2;
  }
  if ((uVar1 & 0x1800000) == 0) {
    uVar4 = 0;
    if ((uVar1 & 0x2000000) == 0) {
      uVar1 = *param_1;
    }
    else {
      do {
        uVar4 = uVar4 + 1;
        iVar2 = ((int (*)())FUN_0019ecf4)(puVar3);
        uVar1 = *param_1;
        puVar3 = puVar3 + iVar2;
      } while (uVar4 < (uVar1 >> 0x19 & 1));
    }
    if ((uVar1 & 0x1800000) == 0) goto LAB_0019ed78;
  }
  puVar3 = (uint *)((int (*)())FUN_0019ec88)(uVar1 >> 0x17 & 3,uVar1 >> 0x19 & 1,puVar3);
  uVar1 = *param_1;
LAB_0019ed78:
  if ((uVar1 & 0x4000000) != 0) {
    puVar3 = puVar3 + 1;
  }
  return (int)puVar3 - (int)param_1 >> 2;
}

/* FUN_0019edb4 @ 0x19edb4 (84 bytes) */
int FUN_0019edb4(param_1)
  uint *param_1;
{
  uint *puVar1;
  
  if ((short)*param_1 == 0x7d) {
    return 1;
  }
  puVar1 = param_1 + 1;
  if ((int)*param_1 < 0) {
    puVar1 = param_1 + 2;
  }
  if ((short)*param_1 == 0x17) {
    return (int)puVar1 - (int)param_1 >> 2;
  }
  if ((*param_1 & 0x40000000) != 0) {
    puVar1 = puVar1 + 1;
  }
  return (int)puVar1 - (int)param_1 >> 2;
}

/* FUN_0019ee08 @ 0x19ee08 (108 bytes) */
int FUN_0019ee08(param_1)
  uint *param_1;
{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = param_1 + 1;
  uVar1 = *param_1;
  if ((uVar1 & 0x400000) != 0) {
    puVar2 = param_1 + 2;
  }
  if ((uVar1 & 0x1800000) != 0) {
    puVar2 = (uint *)((int (*)())FUN_0019ec88)(uVar1 >> 0x17 & 3,uVar1 >> 0x19 & 1,puVar2);
    uVar1 = *param_1;
  }
  if ((uVar1 & 0x4000000) != 0) {
    puVar2 = puVar2 + 1;
  }
  return (int)puVar2 - (int)param_1 >> 2;
}

/* FUN_0019ee74 @ 0x19ee74 (184 bytes) */
int FUN_0019ee74(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)(param_1 + 1);
  if (cVar1 == '\x01') {
    *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) =
         *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) | 0x2000;
    piVar2 = *(int **)(param_2 + 0x310);
    *(int *)(param_2 + 0x30c) = piVar2[2];
                    
                    
    (**(code **)(*piVar2 + 8))(piVar2);
    return;
  }
  if (cVar1 != '\x02') {
    if (cVar1 != '\0') {
      return;
    }
    *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) = *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) | 1;
    piVar2 = *(int **)(param_2 + 0x310);
    *(int *)(param_2 + 0x30c) = piVar2[1];
                    
                    
    (**(code **)(*piVar2 + 0xc))(piVar2);
    return;
  }
  *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) = *(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) | 0x4000
  ;
  piVar2 = *(int **)(param_2 + 0x310);
  *(int *)(param_2 + 0x30c) = piVar2[3];
                    
                    
  (**(code **)(*piVar2 + 0x10))(piVar2);
  return;
}

/* FUN_0019ef2c @ 0x19ef2c (32 bytes) */
int FUN_0019ef2c(param_1)
  int param_1;
{
  *(undefined **)(param_1 + 0xc) = &DAT_001e6730;
  return;
}

/* FUN_0019ef50 @ 0x19ef50 (324 bytes) */
int FUN_0019ef50(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_4 + 0x30c);
  uVar2 = FUN_000e14e4(param_4,0x963c,param_3);
  *(undefined4 *)(param_1 + 0xac) = uVar2;
  _memset(uVar2,0,0x963c);
  iVar3 = *(int *)(*(int *)(param_4 + 0x30c) + 0x40);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(int *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x60) = 1;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x80) = 1;
  *(undefined4 *)(param_1 + 0x84) = 1;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x98) = 1;
  *(undefined4 *)(param_1 + 0x94) = 1;
  **(undefined4 **)(param_1 + 0xa8) = 0;
  puVar1 = PTR_DAT_001e913c;
  *(int *)(*(int *)(param_1 + 0xa8) + 4) = iVar3 + 1;
  *(undefined4 *)(puVar1 + 0x2654) = 7;
  *(undefined4 *)(puVar1 + 0x10e4) = 0xd;
  *(undefined4 *)(puVar1 + 0x22d4) = 0xe;
  *(undefined4 *)(puVar1 + 0x229c) = 0xb;
  *(undefined4 *)(puVar1 + 0x2344) = 0xf;
  *(undefined4 *)(puVar1 + 0x230c) = 0xc;
  *(undefined4 *)(puVar1 + 0x261c) = 5;
  *(undefined4 *)(puVar1 + 0x1a4c) = 6;
  *(undefined4 *)(puVar1 + 0x10ac) = 0xc;
  return;
}

/* FUN_0019f094 @ 0x19f094 (56 bytes) */
int FUN_0019f094(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  
  iVar1 = param_2 * 0x48;
  *(undefined4 *)(*(int *)(param_1 + 0xa8) + iVar1) = 1;
  *(undefined1 *)(iVar1 + *(int *)(param_1 + 0xa8) + 10) = (undefined1)param_3;
  *(undefined1 *)(iVar1 + *(int *)(param_1 + 0xa8) + 0xb) = (undefined1)param_4;
  *(undefined2 *)(iVar1 + *(int *)(param_1 + 0xa8) + 6) = (*(unsigned short *)((unsigned char *)&(param_5) + 2));
  return;
}

/* FUN_0019f0cc @ 0x19f0cc (68 bytes) */
int FUN_0019f0cc(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  
  iVar1 = param_2 * 0x48;
  *(undefined4 *)(*(int *)(param_1 + 0xa8) + iVar1) = 1;
  *(undefined1 *)(iVar1 + *(int *)(param_1 + 0xa8) + 8) = (undefined1)param_3;
  *(undefined1 *)(iVar1 + *(int *)(param_1 + 0xa8) + 9) = (undefined1)param_4;
  *(undefined2 *)(iVar1 + *(int *)(param_1 + 0xa8) + 4) = (*(unsigned short *)((unsigned char *)&(param_5) + 2));
  *(undefined1 *)(iVar1 + *(int *)(param_1 + 0xa8) + 0xc) = (undefined1)param_6;
  return;
}

/* FUN_0019f110 @ 0x19f110 (40 bytes) */
int FUN_0019f110(param_1)
  int param_1;
{
  _memset(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8),0,0x48);
  return;
}

/* FUN_0019f138 @ 0x19f138 (168 bytes) */
int FUN_0019f138(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xa8);
  iVar1 = *(int *)(param_1 + 0x60) * 0x48;
  *(undefined4 *)(iVar1 + iVar2) = 3;
  iVar1 = iVar1 + iVar2;
  *(undefined1 *)(iVar1 + 0x2a) = 0;
  *(undefined1 *)(iVar1 + 0x2b) = 0;
  *(undefined1 *)(iVar1 + 0x40) = 0;
  *(undefined2 *)(iVar1 + 0x1e) = 0x8000;
  *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) & 0x7f007f | 0x92009200;
  *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) & 0x7fffff | 0x92000000;
  *(undefined1 *)(iVar1 + 0x38) = 4;
  *(undefined2 *)(iVar1 + 0xe) = 0x8000;
  *(undefined2 *)(iVar1 + 0x10) = 0x8000;
  *(undefined2 *)(iVar1 + 0x12) = 0x8000;
  *(undefined2 *)(iVar1 + 0x1a) = 0x8000;
  *(undefined2 *)(iVar1 + 0x1c) = 0x8000;
  *(undefined1 *)(iVar1 + 0x2c) = 0;
  *(undefined1 *)(iVar1 + 0x31) = 0;
  *(undefined1 *)(iVar1 + 0x39) = 0;
  *(undefined1 *)(iVar1 + 0x3a) = 0;
  *(undefined1 *)(iVar1 + 0x3b) = 0;
  *(undefined1 *)(iVar1 + 0x36) = 4;
  *(undefined1 *)(iVar1 + 0x37) = 4;
  return;
}

/* FUN_0019f1e0 @ 0x19f1e0 (28 bytes) */
int FUN_0019f1e0(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_000e2c78(param_2,param_1,param_3);
  return;
}

/* FUN_0019f1fc @ 0x19f1fc (48 bytes) */
int FUN_0019f1fc(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  int iVar1;
  
  iVar1 = param_2 * 4;
  *(undefined4 *)(iVar1 + param_3) = 3;
  *(uint *)(iVar1 + param_4) =
       param_5 >> 0x18 | *(uint *)(iVar1 + param_4) | param_5 >> 0xd & 0x7f8 | param_5 >> 2 & 0x3fc0
  ;
  return;
}

/* FUN_0019f22c @ 0x19f22c (24 bytes) */
int FUN_0019f22c(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  *(undefined4 *)(param_2 * 4 + param_3) = 3;
  *(uint *)(param_2 * 4 + param_4) = (param_5 & 0xff) << 9;
  return;
}

/* FUN_0019f244 @ 0x19f244 (84 bytes) */
int FUN_0019f244(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  uint param_6;
{
  int iVar1;
  
  iVar1 = param_2 * 4;
  *(undefined4 *)(iVar1 + param_3) = param_5;
  if (param_6 >> 0x18 == 3) {
    *(uint *)(iVar1 + param_4) = *(uint *)(iVar1 + param_4) | 3;
  }
  if ((param_6 >> 0x10 & 0xff) == 3) {
    *(uint *)(iVar1 + param_4) = *(uint *)(iVar1 + param_4) | 0x18;
  }
  if ((param_6 >> 8 & 0xff) != 3) {
    return;
  }
  *(uint *)(iVar1 + param_4) = *(uint *)(iVar1 + param_4) | 0xc0;
  return;
}

/* FUN_0019f298 @ 0x19f298 (44 bytes) */
int FUN_0019f298(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  uint param_6;
{
  int iVar1;
  
  iVar1 = param_2 * 4;
  *(undefined4 *)(iVar1 + param_3) = param_5;
  *(uint *)(iVar1 + param_4) =
       param_6 >> 0x18 | *(uint *)(iVar1 + param_4) | param_6 >> 0xd & 0x7f8 | param_6 >> 2 & 0x3fc0
  ;
  return;
}

/* FUN_0019f2c4 @ 0x19f2c4 (40 bytes) */
int FUN_0019f2c4(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  uint param_6;
{
  int iVar1;
  
  iVar1 = param_2 * 4;
  *(undefined4 *)(iVar1 + param_3) = param_5;
  if ((param_6 & 0xff) == 3) {
    return;
  }
  *(uint *)(iVar1 + param_4) = (param_6 & 0xff) << 9 | *(uint *)(iVar1 + param_4);
  return;
}

/* FUN_0019f2ec @ 0x19f2ec (36 bytes) */
int FUN_0019f2ec(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  
  iVar1 = param_2 * 4;
  *(undefined4 *)(iVar1 + param_3) = param_5;
  if ((char)param_6 != '\x03') {
    return;
  }
  *(uint *)(iVar1 + param_4) = *(uint *)(iVar1 + param_4) | 0x600;
  return;
}

/* FUN_0019f310 @ 0x19f310 (300 bytes) */
int FUN_0019f310(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int *param_3;
  int param_4;
  int *param_5;
{
  bool bVar1;
  uint uVar2;
  undefined2 uVar3;
  
  uVar2 = 1;
  do {
    if ((param_2 >> (uVar2 & 0x3f) & 1U) != 0) {
      uVar3 = (undefined2)param_3[1];
      if ((-1 < param_3[1]) && (uVar2 == 1)) {
        *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0xe) = uVar3;
      }
      if (-1 < param_3[1]) {
        if (uVar2 == 2) {
          *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x10) = uVar3
          ;
        }
        else if (uVar2 == 3) {
          *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x12) = uVar3
          ;
        }
      }
    }
    bVar1 = uVar2 != 3;
    uVar2 = uVar2 + 1;
    param_3 = param_3 + 1;
  } while (bVar1);
  uVar2 = 1;
  do {
    if ((param_4 >> (uVar2 & 0x3f) & 1U) != 0) {
      uVar3 = (undefined2)param_5[1];
      if ((-1 < param_5[1]) && (uVar2 == 1)) {
        *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x1a) = uVar3;
      }
      if (-1 < param_5[1]) {
        if (uVar2 == 2) {
          *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x1c) = uVar3
          ;
        }
        else if (uVar2 == 3) {
          *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x1e) = uVar3
          ;
        }
      }
    }
    bVar1 = uVar2 != 3;
    uVar2 = uVar2 + 1;
    param_5 = param_5 + 1;
  } while (bVar1);
  return;
}

/* FUN_0019f43c @ 0x19f43c (828 bytes) */
int FUN_0019f43c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  
  uVar4 = (undefined1)param_2;
  if (param_2 != -1) goto LAB_0019f708;
  if (param_3 == 0x34) {
LAB_0019f51c:
    uVar4 = 0;
    iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(undefined1 *)(iVar3 + 0x3b) = *(undefined1 *)(iVar3 + 0x3a);
    iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(undefined1 *)(iVar3 + 0x3e) = *(undefined1 *)(iVar3 + 0x3d);
    iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(undefined1 *)(iVar3 + 0x38) = *(undefined1 *)(iVar3 + 0x37);
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x37) = 6;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3d) = 0;
  }
  else {
    if (param_3 < 0x35) {
      if (param_3 == 0x13) {
LAB_0019f4fc:
        uVar4 = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x38) = 4;
        goto LAB_0019f708;
      }
      if (param_3 < 0x14) {
        if (param_3 == 0x12) goto LAB_0019f51c;
      }
      else {
        if (param_3 == 0x25) {
LAB_0019f5f0:
          iVar5 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          uVar4 = *(undefined1 *)(iVar5 + 0x39);
          *(undefined1 *)(iVar5 + 0x39) = *(undefined1 *)(iVar5 + 0x3a);
          uVar1 = *(undefined1 *)(iVar5 + 0x3c);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          uVar2 = *(undefined1 *)(iVar5 + 0x36);
          *(undefined1 *)(iVar3 + 0x3c) = *(undefined1 *)(iVar3 + 0x3d);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(undefined1 *)(iVar3 + 0x36) = *(undefined1 *)(iVar3 + 0x37);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(undefined1 *)(iVar3 + 0x3a) = *(undefined1 *)(iVar3 + 0x3b);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(undefined1 *)(iVar3 + 0x3d) = *(undefined1 *)(iVar3 + 0x3e);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(undefined1 *)(iVar3 + 0x37) = *(undefined1 *)(iVar3 + 0x38);
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3b) = uVar4
          ;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3e) = uVar1
          ;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x38) = uVar2
          ;
          if (param_3 == 0x9d) {
            uVar4 = 5;
          }
          else {
            uVar4 = 6;
          }
          goto LAB_0019f708;
        }
        if (param_3 == 0x31) {
LAB_0019f5b4:
          uVar4 = 0;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x37) = 6;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x38) = 4;
          goto LAB_0019f708;
        }
      }
    }
    else {
      if (param_3 == 0x8b) goto LAB_0019f51c;
      if (param_3 < 0x8c) {
        if (param_3 == 0x36) goto LAB_0019f4fc;
        if (param_3 == 0x66) goto LAB_0019f5b4;
      }
      else {
        if (param_3 == 0x9d) goto LAB_0019f5f0;
        if (param_3 == 0xb4) {
          uVar4 = 0;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x36) = 4;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x37) = 4;
          goto LAB_0019f708;
        }
      }
    }
    uVar4 = 0xff;
  }
LAB_0019f708:
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x40) = uVar4;
  if (*(int *)(param_4 + 0x120) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x42) = 1;
  }
  iVar5 = *(int *)(param_1 + 0x60);
  iVar3 = *(int *)(param_1 + 0xa8);
  uVar4 = FUN_0019533c(*(undefined4 *)(param_4 + 0x124));
  *(undefined1 *)(iVar5 * 0x48 + iVar3 + 0x41) = uVar4;
  return;
}

/* FUN_0019f778 @ 0x19f778 (44 bytes) */
int FUN_0019f778(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x60) <= *(int *)(param_1 + 0x74) + 1) {
    return;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0xb) = 1;
  return;
}

/* FUN_0019f7a4 @ 0x19f7a4 (188 bytes) */
int FUN_0019f7a4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  *(undefined2 *)(*(int *)(param_1 + 0xa8) + 0x24) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
  iVar5 = *(int *)(param_1 + 0xa8);
  *(int *)(iVar5 + 8) = *(int *)(param_1 + 0x60) + -1;
  uVar1 = *(undefined4 *)(param_1 + 0x9c);
  *(undefined1 *)(iVar5 + 0xd) = 6;
  *(char *)(iVar5 + 0xe) = (char)uVar1;
  *(undefined1 *)(iVar5 + 0xf) = 0;
  *(undefined2 *)(iVar5 + 0x10) = 0;
  *(undefined1 *)(iVar5 + 0xc) = 0;
  uVar1 = *(undefined4 *)(param_1 + 0x74);
  uVar2 = *(undefined4 *)(param_1 + 0x60);
  *(undefined2 *)(iVar5 + 0x14) = 1;
  *(undefined2 *)(iVar5 + 0x16) = 1;
  *(short *)(iVar5 + 0x12) = ((short)uVar2 - (short)uVar1) + -2;
  *(short *)(iVar5 + 0x18) = (short)*(undefined4 *)(param_1 + 0x74);
  *(short *)(iVar5 + 0x1a) = (short)*(undefined4 *)(param_1 + 0x68);
  *(short *)(iVar5 + 0x1c) = (short)*(undefined4 *)(param_1 + 100);
  *(short *)(iVar5 + 0x1e) = (short)*(undefined4 *)(param_1 + 100);
  uVar1 = *(undefined4 *)(param_1 + 100);
  uVar2 = *(undefined4 *)(param_1 + 0x60);
  uVar4 = *(undefined4 *)(param_1 + 0x68);
  uVar3 = *(undefined4 *)(param_1 + 0x74);
  *(undefined2 *)(iVar5 + 0x22) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
  *(short *)(iVar5 + 0x20) = ((((short)uVar2 - (short)uVar1) - (short)uVar4) - (short)uVar3) + -1;
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + -0x3e) = 1;
  return;
}

/* FUN_0019f860 @ 0x19f860 (32 bytes) */
int FUN_0019f860(param_1, param_2)
  int param_1;
  int *param_2;
{
  *param_2 = *(int *)(param_1 + 0x60) * 0x48 >> 2;
  return;
}

/* FUN_0019f880 @ 0x19f880 (240 bytes) */
int FUN_0019f880(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x2a]) = 5;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0xe) = 0;
  if (param_2 == 0) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0x55;
  }
  else {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x12) = 0xaa;
  }
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x14) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x15) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + 0x17) = (undefined1)param_3;
  (**(code **)(*param_1 + 0x15c))(param_1);
  return param_1[0x18] + -1;
}

/* FUN_0019f970 @ 0x19f970 (28 bytes) */
int FUN_0019f970(param_1)
  int param_1;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 9) = 1;
  return;
}

/* FUN_0019f98c @ 0x19f98c (204 bytes) */
int FUN_0019f98c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  uint *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_28;
  uint local_24 [7];
  
  if (*(int *)(param_2 + 300) == 3) {
    uVar2 = 0;
    iVar4 = 4;
    iVar3 = param_2;
    do {
      if ((((int)*(char *)(param_2 + 0x15c) >> (uVar2 & 0x3f) & 1U) != 0) &&
         (*(int *)(iVar3 + 0x1c) == 2)) {
        fVar1 = *(float *)(uVar2 * 0x18 + param_2 + 0x20);
        break;
      }
      uVar2 = uVar2 + 1;
      iVar3 = iVar3 + 0x18;
      iVar4 = iVar4 + -1;
      fVar1 = FLOAT_001aa0d4;
    } while (iVar4 != 0);
    iVar3 = ((undefined4 (*)())FUN_00191888)(*(undefined4 *)(param_1 + 0xa4),param_2,&local_28,local_24,(double)fVar1);
    if (iVar3 != 0) {
      *param_3 = local_24[0] | local_28 << 3 | 0x2000;
      return 1;
    }
  }
  return 0;
}

/* FUN_0019fa58 @ 0x19fa58 (300 bytes) */
int FUN_0019fa58(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  float fVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  
  if (1 < *(int *)(param_4 + 0x84)) {
    puVar6 = (uint *)(param_3 + param_2 * 4);
    iVar7 = 2;
    do {
      piVar4 = (int *)FUN_00105594(param_4,iVar7);
      if (((piVar4 != (int *)0x0) && (iVar5 = (**(code **)(*piVar4 + 0x48))(), iVar5 != 0)) &&
         ((param_5 & 0xff) < 4)) {
        iVar5 = FUN_001054ec(param_4,iVar7);
        uVar3 = (uint)*(byte *)((param_5 & 0xff) + iVar5 + 0x10);
        if (uVar3 < 4) {
          uVar2 = *puVar6 & 0xfffff1ff;
          fVar1 = (float)piVar4[uVar3 * 6 + 8];
          *puVar6 = uVar2;
          if (fVar1 == 0.0) {
            *puVar6 = uVar2 | 0x800;
          }
          else if (fVar1 == 0.5) {
            *puVar6 = uVar2 | 0xa00;
          }
          else if (fVar1 == 1.0) {
            *puVar6 = uVar2 | 0xc00;
          }
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 <= *(int *)(param_4 + 0x84));
  }
  return;
}

/* FUN_0019fb84 @ 0x19fb84 (320 bytes) */
int FUN_0019fb84(param_1)
  int *param_1;
{
  int iVar1;
  
  if (param_1[0x1d] == 0) {
    iVar1 = param_1[0x2a] + param_1[0x18] * 0x48;
    _memcpy(iVar1 + 0x48,iVar1,0x48);
    _memset(param_1[0x18] * 0x48 + param_1[0x2a],0,0x48);
    param_1[0x18] = 2;
    param_1[0x1d] = 1;
    (**(code **)(*param_1 + 0xc4))(param_1,1,0,0,0,0);
    (**(code **)(*param_1 + 200))(param_1,1,0,0,0,0);
    (**(code **)(*param_1 + 0xcc))(param_1,1,0xf);
    (**(code **)(*param_1 + 0xd0))(param_1,1,0xf);
  }
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  param_1[0x18] = param_1[0x18] + 1;
  return;
}

/* FUN_0019fccc @ 0x19fccc (292 bytes) */
int FUN_0019fccc(param_1)
  int *param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  *(int *)(param_1[0x2b] + 0x93b8) = param_1[0x24];
  *(int *)(param_1[0x2b] + 0x9364) = *(int *)(*(int *)(param_1[3] + 0x6c4) + 0x7c) + 1;
  *(undefined4 *)(param_1[0x2b] + 0x9368) = *(undefined4 *)(*(int *)(param_1[3] + 0x6c4) + 0x84);
  iVar1 = FUN_0013061c(*(undefined4 *)(param_1[3] + 0x6c4),0);
  if (iVar1 != 0) {
    iVar2 = iVar1 + -1;
  }
  if ((*(int *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x48) != 3) ||
     (param_1[0x2d] == (param_1[0x18] - param_1[0x1d]) + -1)) {
    (**(code **)(*param_1 + 0xbc))(param_1);
    (**(code **)(*param_1 + 0xc0))(param_1);
    (**(code **)(*param_1 + 0x15c))(param_1);
  }
                    
                    
  (**(code **)(*param_1 + 0x144))(param_1,param_1[0x1e],iVar2);
  return;
}

/* FUN_0019fdf0 @ 0x19fdf0 (316 bytes) */
int FUN_0019fdf0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  
  if (param_2 != 2) {
    if (param_2 != 3) {
      return;
    }
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 6) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 8) = 1;
  }
  if (param_3 == DAT_001b2d68) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 5) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 7) = 5;
    return;
  }
  if (param_3 == DAT_001b2d64) {
    uVar3 = 2;
    iVar1 = *(int *)(param_1 + 0xa8);
    iVar2 = *(int *)(param_1 + 0x60) * 0x48;
  }
  else if (param_3 == DAT_001b2d60) {
    uVar3 = 3;
    iVar1 = *(int *)(param_1 + 0xa8);
    iVar2 = *(int *)(param_1 + 0x60) * 0x48;
  }
  else if (param_3 == DAT_001b2d5c) {
    uVar3 = 4;
    iVar1 = *(int *)(param_1 + 0xa8);
    iVar2 = *(int *)(param_1 + 0x60) * 0x48;
  }
  else {
    if (param_3 != DAT_001b2d58) {
      return;
    }
    uVar3 = 5;
    iVar1 = *(int *)(param_1 + 0xa8);
    iVar2 = *(int *)(param_1 + 0x60) * 0x48;
  }
  *(undefined1 *)(iVar2 + iVar1 + 5) = uVar3;
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 7) = uVar3;
  return;
}

/* FUN_0019ff2c @ 0x19ff2c (176 bytes) */
int FUN_0019ff2c(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  if ((*(int *)(param_2 + 0xdc) != 0) && (iVar4 == param_1[0x18])) {
    iVar4 = *(int *)(param_2 + 0xd0);
    iVar3 = 0;
    for (uVar2 = 1; uVar2 <= *(uint *)(iVar4 + 4); uVar2 = uVar2 + 1) {
      iVar1 = *(int *)(iVar3 + *(int *)(iVar4 + 8));
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0xdc) = 1;
      }
      iVar3 = iVar3 + 4;
    }
  }
  return;
}

/* FUN_0019ffdc @ 0x19ffdc (216 bytes) */
int FUN_0019ffdc(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  
  iVar3 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  if ((*(int *)(param_2 + 0xdc) == 0) || (bVar1 = true, iVar3 != param_1[0x18])) {
    bVar1 = false;
  }
  pcVar4 = *(code **)(*param_1 + 0x9c);
  uVar2 = FUN_000e7d5c(param_2);
  (*pcVar4)(param_1,uVar2,*(undefined4 *)(param_2 + 0x134));
  if (bVar1) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x44) = 1;
  }
  if (*(int *)(param_2 + 0x134) != 0) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x3a) = 3;
  }
  return;
}

/* FUN_001a00b4 @ 0x1a00b4 (1552 bytes) */
int FUN_001a00b4(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = (undefined1)param_2;
  if (param_2 != -1) goto LAB_001a0654;
  if (param_3 == 0x34) {
LAB_001a0260:
    uVar3 = 0;
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(undefined1 *)(iVar4 + 0x2c) = *(undefined1 *)(iVar4 + 0x2b);
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(undefined1 *)(iVar4 + 0x2f) = *(undefined1 *)(iVar4 + 0x2e);
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(uint *)(iVar4 + 0x28) =
         (*(uint *)(iVar4 + 0x24) & 0xe000) << 0x10 | *(uint *)(iVar4 + 0x28) & 0x1fffffff;
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(uint *)(iVar4 + 0x28) =
         (*(uint *)(iVar4 + 0x24) & 0x1c00) << 0x10 | *(uint *)(iVar4 + 0x28) & 0xe3ffffff;
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(uint *)(iVar4 + 0x28) =
         (*(uint *)(iVar4 + 0x24) & 0x380) << 0x10 | *(uint *)(iVar4 + 0x28) & 0xfc7fffff;
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffff1fff | 0xc000;
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffffe3ff | 0x1800;
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xfffffc7f | 0x300;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2e) = 0;
  }
  else {
    if (param_3 < 0x35) {
      if (param_3 == 0x13) {
LAB_001a0200:
        uVar3 = 0;
        iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
        *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0x1fffffff | 0x80000000;
        iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
        *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xe3ffffff | 0x10000000;
        iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
        *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xfc7fffff | 0x2000000;
        goto LAB_001a0654;
      }
      if (param_3 < 0x14) {
        if (param_3 == 0x12) goto LAB_001a0260;
      }
      else {
        if (param_3 == 0x25) {
LAB_001a044c:
          iVar6 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          uVar3 = *(undefined1 *)(iVar6 + 0x2a);
          *(undefined1 *)(iVar6 + 0x2a) = *(undefined1 *)(iVar6 + 0x2b);
          uVar5 = *(uint *)(iVar6 + 0x24);
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          uVar1 = *(undefined1 *)(iVar6 + 0x2d);
          *(undefined1 *)(iVar4 + 0x2d) = *(undefined1 *)(iVar4 + 0x2e);
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          uVar2 = *(uint *)(iVar4 + 0x24);
          *(uint *)(iVar4 + 0x24) = (uVar2 & 0x1c00) << 0x10 | uVar2 & 0xe3ffffff;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          uVar2 = *(uint *)(iVar4 + 0x24);
          *(uint *)(iVar4 + 0x24) = (uVar2 & 0x380) << 0x10 | uVar2 & 0xfc7fffff;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          uVar2 = *(uint *)(iVar4 + 0x24);
          *(uint *)(iVar4 + 0x24) = (uVar2 & 0xe000) << 0x10 | uVar2 & 0x1fffffff;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(undefined1 *)(iVar4 + 0x2b) = *(undefined1 *)(iVar4 + 0x2c);
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(undefined1 *)(iVar4 + 0x2e) = *(undefined1 *)(iVar4 + 0x2f);
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) =
               *(uint *)(iVar4 + 0x28) >> 0x10 & 0xe000 | *(uint *)(iVar4 + 0x24) & 0xffff1fff;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) =
               *(uint *)(iVar4 + 0x28) >> 0x10 & 0x1c00 | *(uint *)(iVar4 + 0x24) & 0xffffe3ff;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) =
               *(uint *)(iVar4 + 0x28) >> 0x10 & 0x380 | *(uint *)(iVar4 + 0x24) & 0xfffffc7f;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2c) = uVar3
          ;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2f) = uVar1
          ;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = uVar5 & 0xe0000000 | *(uint *)(iVar4 + 0x28) & 0x1fffffff;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = uVar5 & 0x1c000000 | *(uint *)(iVar4 + 0x28) & 0xe3ffffff;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = uVar5 & 0x3800000 | *(uint *)(iVar4 + 0x28) & 0xfc7fffff;
          if (param_3 == 0x9d) {
            uVar3 = 7;
          }
          else {
            uVar3 = 8;
          }
          goto LAB_001a0654;
        }
        if (param_3 == 0x31) {
LAB_001a0390:
          uVar3 = 0;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffff1fff | 0xc000;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffffe3ff | 0x1800;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xfffffc7f | 0x300;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0x1fffffff | 0x80000000;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xe3ffffff | 0x10000000;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xfc7fffff | 0x2000000;
          goto LAB_001a0654;
        }
      }
    }
    else {
      if (param_3 == 0x8b) goto LAB_001a0260;
      if (param_3 < 0x8c) {
        if (param_3 == 0x36) goto LAB_001a0200;
        if (param_3 == 0x66) goto LAB_001a0390;
      }
      else {
        if (param_3 == 0x9d) goto LAB_001a044c;
        if (param_3 == 0xb4) {
          *(undefined4 *)(param_1 + 0x9c) = 1;
          uVar3 = 0;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xfc7fffff | 0x3000000;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffff1fff | 0xc000;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffffe3ff | 0x1800;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0x1fffffff | 0x80000000;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xfc7fffff | 0x2000000;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xe3ffffff | 0x10000000;
          goto LAB_001a0654;
        }
      }
    }
    uVar3 = 0xff;
  }
LAB_001a0654:
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x31) = uVar3;
  if (*(int *)(param_4 + 0x120) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x33) = 1;
  }
  iVar6 = *(int *)(param_1 + 0x60);
  iVar4 = *(int *)(param_1 + 0xa8);
  uVar3 = FUN_0019533c(*(undefined4 *)(param_4 + 0x124));
  *(undefined1 *)(iVar6 * 0x48 + iVar4 + 0x32) = uVar3;
  return;
}

/* FUN_001a06c4 @ 0x1a06c4 (252 bytes) */
int FUN_001a06c4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  piVar1 = (int *)FUN_00105594(param_2,param_3);
  if (((((piVar1[0x20] == 0) || (iVar2 = FUN_00126760(piVar1[0x26]), iVar2 == 0)) ||
       ((piVar1[5] & 2U) != 0)) || (iVar2 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar2 != 0)) &&
     (iVar2 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar2 == 0)) {
    uVar3 = 0;
    if (piVar1[0x26] == 0x29) {
      iVar2 = FUN_00105c5c(param_2,param_3);
      uVar3 = iVar2 + *(int *)(*(int *)(param_4 + 0x6c4) + 0x3f0) | 0x4000;
    }
    return uVar3;
  }
  uVar3 = thunk_FUN_00134de8(*(undefined4 *)(param_4 + 0x6c4),piVar1);
  return uVar3;
}

/* FUN_001a07c0 @ 0x1a07c0 (304 bytes) */
int FUN_001a07c0(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  
  iVar6 = FUN_00105594(param_5,param_2);
  fVar4 = FLOAT_001aa10c;
  fVar3 = FLOAT_001aa0d4;
  puVar9 = (uint *)(param_4 + param_2 * 4);
  iVar8 = 0;
  uVar10 = 0;
  do {
    iVar7 = FUN_001054ec(param_5,param_2);
    uVar5 = (uint)*(byte *)(iVar8 + iVar7 + 0x10);
    if (uVar5 < 4) {
      fVar2 = *(float *)(uVar5 * 0x18 + iVar6 + 0x20);
      if (fVar2 == fVar3) {
LAB_001a08b4:
        *puVar9 = 4 << (uVar10 & 0x3f) | *puVar9;
      }
      else if (fVar2 == fVar4) {
        *puVar9 = 5 << (uVar10 & 0x3f) | *puVar9;
      }
      else if (fVar2 == 1.0) {
        *puVar9 = 6 << (uVar10 & 0x3f) | *puVar9;
      }
    }
    else {
      if (uVar5 != 6) goto LAB_001a08b4;
      *puVar9 = 6 << (uVar10 & 0x3f) | *puVar9;
    }
    bVar1 = iVar8 == 2;
    uVar10 = uVar10 + 3;
    iVar8 = iVar8 + 1;
    if (bVar1) {
      return;
    }
  } while( true );
}

/* FUN_001a08f0 @ 0x1a08f0 (224 bytes) */
int FUN_001a08f0(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
{
  float fVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = FUN_00105594(param_5,param_2);
  iVar2 = param_2 * 4;
  *(undefined4 *)(iVar2 + param_3) = 0;
  iVar5 = FUN_001054ec(param_5,param_2);
  uVar3 = (uint)*(byte *)(iVar5 + 0x13);
  if (uVar3 < 4) {
    fVar1 = *(float *)(uVar3 * 0x18 + iVar4 + 0x20);
    if (fVar1 == FLOAT_001aa0d4) {
LAB_001a09b0:
      *(uint *)(iVar2 + param_4) = *(uint *)(iVar2 + param_4) | 0x800;
      return;
    }
    if (fVar1 == FLOAT_001aa10c) {
      *(uint *)(iVar2 + param_4) = *(uint *)(iVar2 + param_4) | 0xa00;
      return;
    }
    if (fVar1 != FLOAT_001aa0e8) {
      return;
    }
  }
  else if (uVar3 != 6) goto LAB_001a09b0;
  *(uint *)(iVar2 + param_4) = *(uint *)(iVar2 + param_4) | 0xc00;
  return;
}

/* FUN_001a09d0 @ 0x1a09d0 (364 bytes) */
int FUN_001a09d0(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
{
  bool bVar1;
  byte bVar2;
  float fVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint *puVar7;
  byte *pbVar8;
  int iVar9;
  uint uVar10;
  undefined4 uStack00000028;
  
  if (1 < *(int *)(param_4 + 0x84)) {
    iVar9 = 2;
    puVar7 = (uint *)(param_3 + param_2 * 4);
    uStack00000028 = param_5;
    do {
      piVar5 = (int *)FUN_00105594(param_4,iVar9);
      if ((piVar5 != (int *)0x0) && (iVar6 = (**(code **)(*piVar5 + 0x48))(), iVar6 != 0)) {
        pbVar8 = (byte *)&STACKARG(0x28);
        uVar10 = 0;
        do {
          bVar2 = *pbVar8;
          if (bVar2 < 4) {
            iVar6 = FUN_001054ec(param_4,iVar9);
            uVar4 = (uint)*(byte *)((uint)bVar2 + iVar6 + 0x10);
            if (uVar4 < 4) {
              fVar3 = (float)piVar5[uVar4 * 6 + 8];
              if (fVar3 == 0.0) {
                *puVar7 = *puVar7 & ~(7 << (uVar10 & 0x3f)) | 4 << (uVar10 & 0x3f);
              }
              else if (fVar3 == 0.5) {
                *puVar7 = *puVar7 & ~(7 << (uVar10 & 0x3f)) | 5 << (uVar10 & 0x3f);
              }
              else if (fVar3 == 1.0) {
                *puVar7 = *puVar7 & ~(7 << (uVar10 & 0x3f)) | 6 << (uVar10 & 0x3f);
              }
            }
          }
          bVar1 = uVar10 != 6;
          pbVar8 = pbVar8 + 1;
          uVar10 = uVar10 + 3;
        } while (bVar1);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 <= *(int *)(param_4 + 0x84));
  }
  return;
}

/* FUN_001a0b3c @ 0x1a0b3c (1192 bytes) */
int FUN_001a0b3c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int *param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  
  iVar4 = (**(code **)(*param_2 + 0x14))(param_2);
  if (*(int *)(param_2[0x22] + 8) == 0xb4) {
    iVar4 = 3;
  }
  else if (iVar4 < 1) {
    return;
  }
  bVar1 = param_3 != 0;
  bVar2 = param_6 != 0;
  do {
    if (bVar1) {
      *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2a) =
           (char)*(undefined4 *)(param_4 + 4);
      iVar6 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(uint *)(iVar6 + 0x24) = *(int *)(param_5 + 4) << 0x1d | *(uint *)(iVar6 + 0x24) & 0x1fffffff
      ;
      iVar6 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(uint *)(iVar6 + 0x24) =
           (*(uint *)(param_5 + 4) & 0x38) << 0x17 | *(uint *)(iVar6 + 0x24) & 0xe3ffffff;
      iVar6 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(uint *)(iVar6 + 0x24) =
           (*(uint *)(param_5 + 4) & 0x1c0) << 0x11 | *(uint *)(iVar6 + 0x24) & 0xfc7fffff;
    }
    if (bVar2) {
      *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x39) =
           (char)*(undefined4 *)(param_7 + 4);
      *(byte *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x36) =
           (byte)(*(uint *)(param_8 + 4) >> 9) & 7;
    }
    iVar6 = 1;
    while( true ) {
      iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar3 + 0x2a) = *(byte *)(iVar3 + 0x2a) | 0x80;
      iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar3 + 0x39) = *(byte *)(iVar3 + 0x39) | 0x80;
      iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar3 + 0x2b) = *(byte *)(iVar3 + 0x2b) | 0x80;
      iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar3 + 0x3a) = *(byte *)(iVar3 + 0x3a) | 0x80;
      iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar3 + 0x2c) = *(byte *)(iVar3 + 0x2c) | 0x80;
      iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
      *(byte *)(iVar3 + 0x3b) = *(byte *)(iVar3 + 0x3b) | 0x80;
      uVar5 = FUN_0019545c(param_2[iVar6 * 6 + 0x28] & 1,(uint)param_2[iVar6 * 6 + 0x28] >> 1 & 1);
      if (bVar2) {
        if (iVar6 == 1) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3c) = uVar5
          ;
        }
        else if (iVar6 == 2) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3d) = uVar5
          ;
        }
        else if (iVar6 == 3) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3e) = uVar5
          ;
        }
      }
      if (bVar1) {
        if (iVar6 == 1) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2d) = uVar5
          ;
        }
        else if (iVar6 == 2) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2e) = uVar5
          ;
        }
        else if (iVar6 == 3) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2f) = uVar5
          ;
        }
      }
      iVar6 = iVar6 + 1;
      if (iVar4 < iVar6) {
        return;
      }
      if (iVar6 == 1) break;
      if (iVar6 == 2) {
        if (bVar1) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2b) =
               (char)*(undefined4 *)(param_4 + 8);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar3 + 0x24) =
               (*(uint *)(param_5 + 8) & 7) << 0xd | *(uint *)(iVar3 + 0x24) & 0xffff1fff;
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar3 + 0x24) =
               (*(uint *)(param_5 + 8) & 0x38) << 7 | *(uint *)(iVar3 + 0x24) & 0xffffe3ff;
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar3 + 0x24) =
               (*(uint *)(param_5 + 8) & 0x1c0) << 1 | *(uint *)(iVar3 + 0x24) & 0xfffffc7f;
        }
        if (bVar2) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3a) =
               (char)*(undefined4 *)(param_7 + 8);
          *(byte *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x37) =
               (byte)(*(uint *)(param_8 + 8) >> 9) & 7;
        }
      }
      else if (iVar6 == 3) {
        if (bVar1) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2c) =
               (char)*(undefined4 *)(param_4 + 0xc);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar3 + 0x28) =
               *(int *)(param_5 + 0xc) << 0x1d | *(uint *)(iVar3 + 0x28) & 0x1fffffff;
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar3 + 0x28) =
               (*(uint *)(param_5 + 0xc) & 0x38) << 0x17 | *(uint *)(iVar3 + 0x28) & 0xe3ffffff;
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar3 + 0x28) =
               (*(uint *)(param_5 + 0xc) & 0x1c0) << 0x11 | *(uint *)(iVar3 + 0x28) & 0xfc7fffff;
        }
        if (bVar2) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3b) =
               (char)*(undefined4 *)(param_7 + 0xc);
          *(byte *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x38) =
               (byte)(*(uint *)(param_8 + 0xc) >> 9) & 7;
        }
      }
    }
  } while( true );
}

/* FUN_001a0fe4 @ 0x1a0fe4 (356 bytes) */
int FUN_001a0fe4(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  int local_48;
  float local_44;
  int local_30;
  float local_2c;
  
  uVar1 = DAT_001b2d70;
  iVar2 = FUN_000f5cf0(param_1,1,DAT_001b2d70,&local_48);
  if ((((iVar2 == 0) || (local_48 != 2)) ||
      (iVar2 = FUN_000f5cf0(param_1,2,uVar1,&local_30), iVar2 == 0)) || (local_30 != 2)) {
    bVar3 = false;
    *param_2 = 0;
  }
  else {
    bVar3 = false;
    switch(*(undefined4 *)(param_1 + 300)) {
    case 0:
      bVar3 = local_44 == local_2c;
      break;
    case 1:
      bVar3 = local_44 != local_2c;
      break;
    case 2:
      bVar3 = local_2c < local_44;
      break;
    case 3:
      bVar3 = local_2c <= local_44;
      break;
    case 4:
      bVar3 = local_44 < local_2c;
      break;
    case 5:
      bVar3 = local_44 <= local_2c;
    }
    *param_2 = 1;
  }
  return bVar3;
}

/* FUN_001a1160 @ 0x1a1160 (144 bytes) */
int FUN_001a1160(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)0x0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x24);
  uVar2 = *(uint *)(iVar1 + 4);
  if (uVar2 - 1 < uVar2) {
    piVar3 = (int *)((uVar2 - 1) * 4 + *(int *)(iVar1 + 8));
  }
  iVar4 = *piVar3;
  FUN_00194208(iVar1,uVar2 - 1);
  *(short *)(iVar4 * 0x48 + *(int *)(param_1 + 0xa8) + 0xc) =
       ((short)*(undefined4 *)(param_1 + 0x60) - (short)*(undefined4 *)(param_1 + 0x74)) + -1;
  *(int *)(param_1 + 0xb4) = (*(int *)(param_1 + 0x60) - *(int *)(param_1 + 0x74)) + -1;
  return;
}

/* FUN_001a11f0 @ 0x1a11f0 (328 bytes) */
int FUN_001a11f0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  uint *puVar8;
  
  iVar3 = FUN_000e7804(param_2,param_2,param_3,param_4,param_5,param_6,param_7);
  uVar7 = *(undefined4 *)(param_4 + 0x6c4);
  iVar2 = *(int *)(iVar3 + 300);
  uVar4 = FUN_00105594(iVar3,1);
  uVar4 = thunk_FUN_00134de8(uVar7,uVar4);
  iVar3 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  if ((*(int *)(param_2 + 0xdc) == 0) || (bVar1 = true, iVar3 != param_1[0x18])) {
    bVar1 = false;
  }
  uVar4 = (**(code **)(*param_1 + 0x98))(param_1,iVar2 != 1,uVar4,0);
  if (bVar1) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x44) = 1;
  }
  puVar8 = *(uint **)(param_1[4] + 0x24);
  uVar6 = puVar8[1];
  if (uVar6 < *puVar8) {
    _memset(uVar6 * 4 + puVar8[2],0,4);
    puVar5 = (undefined4 *)(uVar6 * 4 + puVar8[2]);
    puVar8[1] = uVar6 + 1;
  }
  else {
    puVar5 = (undefined4 *)FUN_0019423c(puVar8,uVar6);
  }
  *puVar5 = uVar4;
  return;
}

/* FUN_001a1338 @ 0x1a1338 (96 bytes) */
int FUN_001a1338(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,((unsigned char *)0x000010c4));
  *puVar1 = uVar2;
  puVar1[1] = &PTR_FUN_001eb9a8;
  puVar1[7] = 0;
  return puVar1 + 1;
}

