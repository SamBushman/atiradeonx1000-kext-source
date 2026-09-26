#include "decls.h"

/* FUN_0019156c @ 0x19156c (412 bytes) */
int FUN_0019156c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (((*(uint *)(param_2 + 0x14) & 2) == 0) &&
     ((*(int *)(param_2 + 0x98) == 0 || (*(int *)(param_2 + 0x98) == 1)))) {
    iVar2 = *(int *)(param_2 + 0x88);
    iVar1 = *(int *)(iVar2 + 8);
    if ((iVar1 == 0x66) || (iVar1 == 0x36)) {
      return 1;
    }
    if (iVar1 == 0x31) {
      iVar1 = FUN_000f3a30(param_2);
      if (iVar1 == 1) {
        return 1;
      }
      iVar2 = *(int *)(param_2 + 0x88);
    }
    if (((*(int *)(iVar2 + 8) == 0x13) && (iVar1 = FUN_000f3a30(param_2), iVar1 == 1)) &&
       ((*(uint *)(param_2 + 0xb8) & 1) == (*(uint *)(param_2 + 0xd0) & 1))) {
      iVar1 = FUN_00105594(param_2,1);
      iVar2 = FUN_00105594(param_2,2);
      if (iVar1 == iVar2) {
        return 1;
      }
      piVar3 = (int *)FUN_00105594(param_2,1);
      if (((((piVar3[0x20] != 0) && (iVar1 = FUN_00126760(piVar3[0x26]), iVar1 != 0)) &&
           (((piVar3[5] & 2U) == 0 &&
            ((iVar1 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar1 == 0 &&
             (piVar3 = (int *)FUN_00105594(param_2,2), piVar3[0x20] != 0)))))) &&
          (iVar1 = FUN_00126760(piVar3[0x26]), iVar1 != 0)) &&
         (((piVar3[5] & 2U) == 0 && (iVar1 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar1 == 0)))) {
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00191710 @ 0x191710 (76 bytes) */
undefined4 FUN_00191710(double fparam_1)
{
  if (((fparam_1 != (double)FLOAT_001aa0d4) && (fparam_1 != (double)FLOAT_001aa10c)) &&
     (fparam_1 != (double)FLOAT_001aa0e8)) {
    return 0;
  }
  return 1;
}

/* FUN_00191888 @ 0x191888 (184 bytes) */
undefined4 FUN_00191888(int param_1,undefined4 param_2,uint *param_3,uint *param_4,double fparam_1)
{
  float fVar1;
  uint uVar2;
  int iVar3;
  
  if ((double)FLOAT_001aa0d4 < fparam_1) {
    fVar1 = (float)fparam_1;
    if (((uint)GH_F2U(fVar1) & 1) == 0) {
      uVar2 = (uint)GH_F2U(fVar1) >> 1 & 0xff;
      *param_3 = uVar2;
      if ((uVar2 == 0) || (*param_3 = uVar2 - 0x78, uVar2 - 0x78 < 0x10)) {
        if (*param_3 == 0) {
          uVar2 = 0;
          iVar3 = 8;
          do {
            if (fparam_1 == (double)*(float *)(FUN_00001740 + param_1 + 4)) {
              *param_4 = uVar2;
              return 1;
            }
            uVar2 = uVar2 + 1;
            param_1 = param_1 + 4;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        else {
          *param_4 = (uint)GH_F2U(fVar1) >> 9;
          if (((uint)GH_F2U(fVar1) >> 9 & 0xfffff) == 0) {
            *param_4 = (uint)GH_F2U(fVar1) >> 0x1d;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_00191940 @ 0x191940 (152 bytes) */
int FUN_00191940(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  undefined4 param_3;
{
  bool bVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  double fparam_1;
  undefined4 uStack00000020;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [32];
  
  bVar1 = false;
  iVar4 = 4;
  uStack00000020 = param_3;
  fparam_1 = (double)FLOAT_001aa0d4;
  pcVar2 = (char *)&STACKARG(0x20);
  do {
    if (*pcVar2 != '\x04') {
      if (bVar1) {
        if ((double)*param_2 != fparam_1) {
          return 0;
        }
        bVar1 = true;
      }
      else {
        fparam_1 = (double)*param_2;
        bVar1 = true;
      }
    }
    pcVar2 = pcVar2 + 1;
    param_2 = param_2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar3 = ((undefined4 (*)())FUN_00191888)(param_1,param_2,auStack_28,auStack_24,fparam_1);
  return uVar3;
}

/* FUN_001919d8 @ 0x1919d8 (344 bytes) */
int FUN_001919d8(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  dword *param_3;
  int *param_4;
{
  float fVar1;
  bool bVar2;
  int *piVar3;
  uint *puVar4;
  undefined *puVar5;
  int iVar6;
  dword *pdVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint local_38;
  float local_20;
  
  if (*param_4 != 0x4040404) {
    puVar5 = &DAT_001b19e0;
    fVar1 = 0.0;
    iVar9 = 4;
    bVar2 = true;
    iVar6 = 1;
    piVar3 = param_4;
    pdVar7 = param_3;
    do {
      if (*(char *)piVar3 != '\x04') {
        if (bVar2) {
          fVar1 = (float)*pdVar7;
          bVar2 = false;
        }
        else if ((float)*pdVar7 != fVar1) {
          iVar6 = 0;
        }
      }
      piVar3 = (int *)((int)piVar3 + 1);
      pdVar7 = pdVar7 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    piVar3 = param_4;
    if (iVar6 == 0) {
      iVar9 = FUN_000f6a04(param_2,param_3,*param_4);
    }
    else {
      puVar5 = (undefined *)0x4;
      iVar9 = 4;
      puVar4 = &local_38;
      do {
        *puVar4 = 0x7ffffffe;
        puVar4 = puVar4 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      pdVar7 = &MACH_HEADER.cputype;
      iVar9 = 0;
      iVar10 = 4;
      do {
        local_20 = fVar1;
        *(float *)(iVar9 + (int)&local_38) = fVar1;
        iVar9 = iVar9 + 4;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      iVar9 = FUN_000f6a04(param_2,&local_38,0x10203);
    }
    if (iVar9 != 0) {
      return iVar9;
    }
    uVar8 = *(undefined4 *)(param_2 + 0x3ac);
    iVar6 = FUN_000f5f94(uVar8,param_3,param_4,piVar3,puVar5,iVar6,pdVar7);
    if (iVar6 != 0) {
      return iVar6;
    }
    iVar6 = FUN_000f57f0(uVar8,param_3,param_4,piVar3);
    if (iVar6 != 0) {
      return iVar6;
    }
  }
  return 0;
}

/* FUN_00191b30 @ 0x191b30 (316 bytes) */
int FUN_00191b30(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
  int param_5;
{
  char cVar1;
  float fVar2;
  int *a0;
  int iVar3;
  undefined4 uVar4;
  float *pfVar5;
  int iVar6;
  uint local_58;
  undefined4 local_54;
  uint local_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  undefined4 local_30;
  
  local_58 = param_4 << 0x18 | (param_4 & 0xff00) << 8 | param_4 >> 8 & 0xff00 | param_4 >> 0x18;
  a0 = (int *)FUN_00105594(param_2,param_3);
  iVar3 = (**(code **)(*a0 + 0x48))(a0);
  if (iVar3 == 0) {
LAB_00191c54:
    uVar4 = 0;
  }
  else {
    iVar3 = FUN_001054ec(param_2,param_3);
    iVar6 = 0;
    local_54 = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = 4;
    pfVar5 = (float *)&local_50;
    do {
      cVar1 = *(char *)((int)&local_58 + iVar6);
      *pfVar5 = 0.0;
      if (cVar1 == '\0') {
        if ((((int)*(char *)(a0 + 0x57) >> (*(byte *)((int)&local_54 + iVar6) & 0x3f) & 1U) == 0) ||
           (((fVar2 = GH_U2F((unsigned int)(a0[(uint)*(byte *)((int)&local_54 + iVar6) * 6 + 8])), fVar2 != 0.0 &&
             (fVar2 != 1.0)) && (local_30 = 0x3f000000, fVar2 != 0.5)))) goto LAB_00191c54;
        *pfVar5 = fVar2;
      }
      iVar6 = iVar6 + 1;
      pfVar5 = pfVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    ((void (*)())FUN_000f79c4)(param_2,*(undefined4 *)(param_5 + 0x6c4),param_3,(double)GH_U2F((unsigned int)(local_50)),
                 (double)fStack_4c,(double)fStack_48,(double)fStack_44);
    uVar4 = 1;
  }
  return uVar4;
}

/* FUN_00191c6c @ 0x191c6c (16 bytes) */
int FUN_00191c6c(param_1)
  int param_1;
{
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x2c) = 0x100;
  return;
}

/* FUN_00191c7c @ 0x191c7c (428 bytes) */
int FUN_00191c7c(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  float *param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  float fVar1;
  bool bVar2;
  char *pcVar3;
  float *pfVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined4 uStack00000024;
  
  uStack00000024 = param_4;
  *param_3 = 0xffffffff;
  pcVar3 = (char *)&STACKARG(0x24);
  iVar6 = 4;
  pfVar4 = param_2;
  pcVar5 = pcVar3;
  while ((((*pcVar5 == '\x04' || (fVar1 = *pfVar4, fVar1 == FLOAT_001aa0d4)) ||
          (fVar1 == FLOAT_001aa10c)) || (fVar1 == 1.0))) {
    pcVar5 = pcVar5 + 1;
    pfVar4 = pfVar4 + 1;
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) {
      iVar6 = (int)pcVar5 - (int)pcVar3;
      do {
        if (*pcVar3 == '\x04') {
          *param_2 = 0.0;
        }
        pcVar3 = pcVar3 + 1;
        param_2 = param_2 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      return 1;
    }
  }
  iVar6 = FUN_000e07dc(param_5,0x2f);
  if (iVar6 == 0) {
    return 0;
  }
  iVar6 = 4;
  bVar2 = true;
  pfVar4 = param_2;
  fVar1 = FLOAT_001aa0d4;
  do {
    if (*pcVar3 != '\x04') {
      if (bVar2) {
        fVar1 = *pfVar4;
        bVar2 = false;
      }
      else if (*pfVar4 != fVar1) {
        return 0;
      }
    }
    pcVar3 = pcVar3 + 1;
    pfVar4 = pfVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = (**(code **)(*param_1 + 0x98))(param_1,param_2,uStack00000024);
  if (iVar6 != 0) {
    iVar6 = 0;
    iVar7 = 4;
    do {
      *(float *)((int)param_2 + iVar6) = fVar1;
      iVar6 = iVar6 + 4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    *param_3 = 3;
    return 1;
  }
  return 0;
}

/* FUN_00191e28 @ 0x191e28 (196 bytes) */
int FUN_00191e28(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  puVar2 = (undefined4 *)FUN_000e1564(param_2,0x6c);
  puVar1 = PTR_DAT_001e90f4;
  puVar3 = PTR_DAT_001e90fc + 8;
  puVar2[2] = param_2;
  *puVar2 = puVar3;
  puVar2[1] = 0;
  *puVar2 = puVar1 + 8;
  FUN_00189560(puVar2 + 10);
  FUN_00189604(puVar2);
  puVar2[0x1a] = 0;
  *puVar2 = PTR_DAT_001e9148 + 8;
  *(undefined4 **)(param_1 + 0x60) = puVar2;
  puVar2 = (undefined4 *)FUN_000e1564(param_2,0xc);
  puVar1 = PTR_DAT_001e9100;
  puVar2[1] = 1;
  puVar2[2] = 0;
  *puVar2 = puVar1 + 8;
  *(undefined4 **)(param_1 + 100) = puVar2;
  return;
}

/* FUN_00191efc @ 0x191efc (448 bytes) */
int FUN_00191efc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  double dVar7;
  uint uVar8;
  float *pfVar9;
  uint uVar10;
  float *pfVar11;
  double dVar12;
  
  FUN_00128fd0(param_1,param_2,0);
  param_1[7] = 0;
  param_1[0x10] = 0x200;
  *param_1 = &PTR_FUN_001eb450;
  param_1[0xb] = 0x100;
  param_1[8] = 0x7fffffff;
  param_1[0x13] = 4;
  param_1[9] = 0x20;
  param_1[10] = 0x10;
  param_1[0xe] = 0x89;
  param_1[0x15] = 0x400;
  param_1[0xf] = 0x10;
  param_1[0x11] = 4;
  param_1[0x12] = 4;
  param_1[0x14] = 0x20;
  FUN_0010dc20(param_1);
  FUN_0010dbd8(param_1,0x2f);
  FUN_0010dbd8(param_1,0x30);
  FUN_0010dbd8(param_1,0x31);
  FUN_0010dbd8(param_1,0x34);
  FUN_0010dbd8(param_1,0x35);
  FUN_0010dbd8(param_1,0x36);
  FUN_0010dbd8(param_1,0x37);
  FUN_0010dbd8(param_1,0x38);
  FUN_0010dbd8(param_1,0x39);
  FUN_0010dbd8(param_1,0x3a);
  FUN_0010dbd8(param_1,0x3b);
  FUN_0010dbd8(param_1,0x3c);
  FUN_0010dbd8(param_1,0x3d);
  FUN_0010dbd8(param_1,0x40);
  FUN_0010dbd8(param_1,0x42);
  FUN_0010dbd8(param_1,0x47);
  FUN_0010dbd8(param_1,0x4a);
  FUN_0010dbd8(param_1,0x4b);
  param_1[2] = param_1[2] & 0xfffdffff | 0x1d80;
  FUN_0019ef2c(param_1);
  if (param_3 != 0) {
    ((int (*)())FUN_00191e28)(param_1,param_2);
  }
  dVar7 = DOUBLE_001aa2a8[0];
  dVar6 = DOUBLE_001aa1e0;
  fVar5 = FLOAT_001aa1c4;
  fVar4 = FLOAT_001aa170;
  fVar3 = FLOAT_001aa0e8;
  pfVar9 = (float *)(param_1 + 0x5d0);
  uVar8 = 0;
  do {
    uVar10 = 0;
    pfVar11 = pfVar9;
    do {
      pfVar11 = pfVar11 + 1;
      if (uVar8 == 0) {
        fVar2 = FLOAT_001aa1c0;
        if (uVar10 != 0) {
          fVar2 = (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - dVar6) * fVar4 * fVar5;
        }
      }
      else {
        dVar12 = _pow(DOUBLE_001aa2a0,
                      (double)(float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - dVar6) -
                      dVar7);
        fVar2 = (float)dVar12 *
                ((float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - dVar6) * fVar4 + fVar3);
      }
      bVar1 = uVar10 != 7;
      *pfVar11 = fVar2;
      uVar10 = uVar10 + 1;
    } while (bVar1);
    bVar1 = uVar8 != 0xf;
    pfVar9 = pfVar9 + 8;
    uVar8 = uVar8 + 1;
  } while (bVar1);
  return;
}

/* FUN_001920e0 @ 0x1920e0 (748 bytes) */
int FUN_001920e0(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  double dVar7;
  uint uVar8;
  float *pfVar9;
  uint uVar10;
  float *pfVar11;
  double dVar12;
  
  FUN_00128fd0(param_1,param_2,0);
  param_1[7] = 0;
  param_1[0x10] = 0x200;
  *param_1 = &PTR_FUN_001eb450;
  param_1[0xb] = 0x100;
  param_1[8] = 0x7fffffff;
  param_1[0x13] = 4;
  param_1[9] = 0x20;
  param_1[10] = 0x10;
  param_1[0xe] = 0x89;
  param_1[0x15] = 0x400;
  param_1[0xf] = 0x10;
  param_1[0x11] = 4;
  param_1[0x12] = 4;
  param_1[0x14] = 0x20;
  FUN_0010dc20(param_1);
  FUN_0010dbd8(param_1,0x2f);
  FUN_0010dbd8(param_1,0x30);
  FUN_0010dbd8(param_1,0x31);
  FUN_0010dbd8(param_1,0x34);
  FUN_0010dbd8(param_1,0x35);
  FUN_0010dbd8(param_1,0x36);
  FUN_0010dbd8(param_1,0x37);
  FUN_0010dbd8(param_1,0x38);
  FUN_0010dbd8(param_1,0x39);
  FUN_0010dbd8(param_1,0x3a);
  FUN_0010dbd8(param_1,0x3b);
  FUN_0010dbd8(param_1,0x3c);
  FUN_0010dbd8(param_1,0x3d);
  FUN_0010dbd8(param_1,0x40);
  FUN_0010dbd8(param_1,0x42);
  FUN_0010dbd8(param_1,0x47);
  FUN_0010dbd8(param_1,0x4a);
  FUN_0010dbd8(param_1,0x4b);
  param_1[2] = param_1[2] & 0xfffdffff | 0x1d80;
  FUN_0019ef2c(param_1);
  if (param_3 != 0) {
    ((int (*)())FUN_00191e28)(param_1,param_2);
  }
  dVar7 = DOUBLE_001aa2a8[0];
  dVar6 = DOUBLE_001aa1e0;
  fVar5 = FLOAT_001aa1c4;
  fVar4 = FLOAT_001aa170;
  fVar3 = FLOAT_001aa0e8;
  pfVar9 = (float *)(param_1 + 0x5d0);
  uVar8 = 0;
  do {
    uVar10 = 0;
    pfVar11 = pfVar9;
    do {
      pfVar11 = pfVar11 + 1;
      if (uVar8 == 0) {
        fVar2 = FLOAT_001aa1c0;
        if (uVar10 != 0) {
          fVar2 = (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - dVar6) * fVar4 * fVar5;
        }
      }
      else {
        dVar12 = _pow(DOUBLE_001aa2a0,
                      (double)(float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - dVar6) -
                      dVar7);
        fVar2 = (float)dVar12 *
                ((float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - dVar6) * fVar4 + fVar3);
      }
      bVar1 = uVar10 != 7;
      *pfVar11 = fVar2;
      uVar10 = uVar10 + 1;
    } while (bVar1);
    bVar1 = uVar8 != 0xf;
    pfVar9 = pfVar9 + 8;
    uVar8 = uVar8 + 1;
  } while (bVar1);
  return;
}

/* FUN_001922c4 @ 0x1922c4 (1016 bytes) */
int FUN_001922c4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  double dVar13;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  
  uVar11 = *(undefined4 *)(param_4 + 8);
  iVar2 = *(int *)(param_3[0x22] + 8);
  if (((((iVar2 == 0x5d) || (iVar2 == 0x29)) || (iVar2 == 0x5b)) ||
      ((iVar2 == 0x27 || (iVar2 == 0x5e)))) ||
     ((iVar2 == 0x2a || ((iVar2 == 0x5c || (iVar2 == 0x28)))))) {
    switch(iVar2) {
    case 0x27:
    case 0x5b:
      iVar12 = 1;
      iVar2 = 2;
      uVar9 = 3;
      uVar10 = 2;
      uVar8 = 1;
      uVar7 = 1;
      break;
    case 0x28:
    case 0x5c:
      iVar12 = 2;
      iVar2 = 1;
      uVar9 = 2;
      uVar10 = 3;
      uVar8 = 0;
      uVar7 = 0;
      break;
    case 0x29:
    case 0x5d:
      iVar12 = 1;
      iVar2 = 2;
      uVar9 = 3;
      uVar10 = 2;
      uVar8 = 0;
      uVar7 = 0;
      break;
    case 0x2a:
    case 0x5e:
      iVar12 = 1;
      iVar2 = 2;
      uVar9 = 2;
      uVar10 = 3;
      uVar8 = 1;
      uVar7 = 1;
      break;
    default:
      iVar12 = 0;
      iVar2 = 0;
      uVar9 = 0;
      uVar10 = 0;
      uVar8 = 0;
      uVar7 = 0;
    }
    iVar3 = FUN_001043f0(0x12,uVar11);
    uVar4 = FUN_00105594(param_3,iVar12);
    FUN_00106004(iVar3,iVar12,uVar4,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    iVar5 = FUN_001054ec(param_3,iVar12);
    uVar4 = *(undefined4 *)(iVar5 + 0x10);
    iVar5 = FUN_001054ec(iVar3,iVar12);
    *(undefined4 *)(iVar5 + 0x10) = uVar4;
    iVar5 = iVar3 + iVar12 * 0x18 + 0x8c;
    FUN_00103d50(iVar5,2,(uint)param_3[iVar12 * 6 + 0x28] >> 1 & 1);
    FUN_00103d50(iVar5,1,param_3[iVar12 * 6 + 0x28] & 1);
    uVar4 = FUN_00105594(param_3,iVar2);
    FUN_00106004(iVar3,iVar2,uVar4,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    iVar12 = FUN_001054ec(param_3,iVar2);
    uVar4 = *(undefined4 *)(iVar12 + 0x10);
    iVar12 = FUN_001054ec(iVar3,iVar2);
    *(undefined4 *)(iVar12 + 0x10) = uVar4;
    iVar12 = iVar3 + iVar2 * 0x18 + 0x8c;
    FUN_00103d50(iVar12,2,(uint)param_3[iVar2 * 6 + 0x28] >> 1 & 1);
    FUN_00103d50(iVar12,1,param_3[iVar2 * 6 + 0x28] & 1U ^ 1);
    iVar2 = FUN_001054ec(param_3,0);
    uVar4 = *(undefined4 *)(iVar2 + 0x10);
    *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(iVar3 + 0x14c);
    *(undefined4 *)(iVar3 + 0x9c) = uVar4;
    *(undefined4 *)(iVar3 + 0x98) = 0;
    ((int (*)())FUN_00193f44)(iVar3,param_3);
    if ((*(uint *)(param_4 + 0x30) & 0x80) == 0) {
      *(int *)(iVar3 + 0x160) = *(int *)(param_4 + 0x478) + 1;
    }
    *(int *)(iVar3 + 0x158) = param_3[0x56];
    iVar2 = 0;
    local_40 = 0;
    local_48 = 0;
    local_44 = 0;
    FUN_00103f18(param_3,&local_48,0xffffffff);
    if ((param_3[5] & 0x200U) != 0) {
      iVar2 = FUN_00105594(param_3,param_3[0x21]);
    }
    iVar12 = param_3[4];
    ((int (*)())FUN_0019401c)(param_3);
    FUN_00106004(param_3,1,0,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    FUN_00106004(param_3,2,0,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    FUN_00108304(param_3,0x25,*(undefined4 *)(param_4 + 8));
    FUN_00103f44(param_3,&local_48);
    param_3[4] = iVar12;
    FUN_00106004(param_3,1,iVar3,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    iVar5 = 0;
    FUN_00103d50(param_3 + 0x29,1,uVar8);
    FUN_00103d50(param_3 + 0x29,2,uVar7);
    dVar13 = (double)FLOAT_001aa0e8;
    ((void (*)())FUN_000f79c4)(param_3,param_4,uVar10,dVar13,dVar13,dVar13,dVar13);
    dVar13 = (double)FLOAT_001aa0d4;
    ((void (*)())FUN_000f79c4)(param_3,param_4,uVar9,dVar13,dVar13,dVar13,dVar13);
    param_3[0x25] = param_3[0x53];
    param_3[0x26] = 0;
    iVar12 = FUN_001054ec(iVar3,0);
    param_3[0x27] = *(int *)(iVar12 + 0x10);
    do {
      iVar12 = FUN_001054ec(iVar3,0);
      if (*(char *)(iVar5 + iVar12 + 0x10) == '\x01') {
        for (iVar12 = 1; iVar6 = (**(code **)(*param_3 + 0x14))(param_3), iVar12 <= iVar6;
            iVar12 = iVar12 + 1) {
          (**(code **)(*param_3 + 0x88))(param_3,iVar12,iVar5,4);
        }
      }
      bVar1 = iVar5 != 3;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    if (iVar2 != 0) {
      FUN_00106804(param_3,iVar2,*(uint *)(param_4 + 0x30) >> 7 & 1,uVar11);
    }
    param_3[0x56] = *(int *)(iVar3 + 0x158);
    ((int (*)())FUN_00193f74)(param_3,iVar3);
    if ((*(uint *)(param_4 + 0x30) & 0x80) == 0) {
      FUN_001875a8(param_3,1,iVar3,param_4);
    }
  }
  return param_3;
}

/* FUN_0019286c @ 0x19286c (2512 bytes) */
int FUN_0019286c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  int *param_2;
  int param_3;
  int *param_4;
  undefined4 *param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  undefined4 uVar21;
  undefined4 local_58;
  int local_54 [7];
  
  local_58 = 0;
  puVar16 = param_5;
  iVar3 = (**(code **)(*param_4 + 0x60))(param_4,param_2,param_3,param_4,param_5,param_6,param_7);
  if (iVar3 != 0) {
    piVar4 = (int *)FUN_00105594(param_4,1);
    iVar3 = (**(code **)(*piVar4 + 0x60))(piVar4);
    if (iVar3 != 0) {
      uVar5 = FUN_00105594(param_4,1);
      FUN_0010c670(uVar5,param_4,param_5[2]);
    }
  }
  iVar3 = FUN_000e07dc(param_5[2],0x38);
  if (((iVar3 != 0) && (param_2 != (int *)0x0)) &&
     (iVar3 = (**(code **)(*param_2 + 100))(param_2), iVar3 == 0)) {
    FUN_0014a918(param_2,param_3,param_5);
  }
  uVar5 = 0;
  iVar3 = FUN_000e07dc(param_5[2],0x1b);
  if (iVar3 != 0) {
    uVar5 = (**(code **)(*param_4 + 100))(param_4);
    iVar3 = FUN_0014abdc(param_4,param_5,&local_58);
    if ((iVar3 != 0) &&
       (param_4 = (int *)FUN_00146610(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
    if (param_2 != (int *)0x0) {
      puVar16 = &local_58;
      iVar3 = FUN_00160320(param_2,param_3,param_4,param_5,puVar16);
      if ((iVar3 != 0) &&
         (param_4 = (int *)FUN_00146610(param_2,param_3,param_4), param_4 == (int *)0x0)) {
        return 1;
      }
    }
  }
  iVar3 = FUN_000e07dc(param_5[2],0x1c);
  if (iVar3 != 0) {
    iVar3 = FUN_00162cc0(param_4,param_5);
    if (iVar3 != 0) {
      iVar3 = (**(code **)(*param_4 + 100))(param_4);
      if (((iVar3 != 0) && ((param_4[5] & 0x200U) == 0)) && (param_2 != (int *)0x0)) {
        puVar16 = &local_58;
        FUN_00160320(param_2,param_3,param_4,param_5,puVar16);
      }
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      if (param_4 == (int *)0x0) {
        return 1;
      }
    }
    iVar3 = (**(code **)(*param_4 + 0x14))(param_4);
    if ((param_3 <= iVar3) && (iVar3 = FUN_00158264(param_2,param_3,param_4,param_5), iVar3 != 0)) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      if (param_4 == (int *)0x0) {
        return 1;
      }
      uVar5 = 1;
    }
    iVar3 = FUN_00155a60(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0014bdbc(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0014b82c(param_4,param_5,0,1);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0014b150(param_4,param_5);
    if (iVar3 != 0) {
      iVar3 = (**(code **)(*param_4 + 100))(param_4);
      if (((iVar3 != 0) && ((param_4[5] & 0x200U) == 0)) && (param_2 != (int *)0x0)) {
        puVar16 = &local_58;
        FUN_00160320(param_2,param_3,param_4,param_5,puVar16);
      }
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
      if (param_4 == (int *)0x0) {
        return 1;
      }
      uVar5 = 1;
    }
    iVar3 = FUN_0014caec(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0014d8f8(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0015ceb0(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0015bd40(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_00163994(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0015c6d4(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0014cec8(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_00150d38(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0014acb8(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_001595f0(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0015df44(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0015e494(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_000e07dc(param_5[2],0x3c);
    if ((iVar3 != 0) && (iVar3 = FUN_00163478(param_2,param_3,param_4,param_5), iVar3 != 0)) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_0014d274(param_4,param_5);
    if (iVar3 != 0) {
      param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
    }
    iVar3 = FUN_00158c3c(param_4,param_5);
    if (iVar3 != 0) {
      uVar5 = 1;
    }
  }
  iVar3 = FUN_0015546c(param_2,param_3,param_4,(uint)param_5);
  if (iVar3 != 0) {
    uVar5 = 1;
    param_4 = (int *)FUN_00146610(param_2,param_3,param_4);
  }
  piVar4 = param_4;
  puVar15 = param_5;
  iVar3 = FUN_00155654(param_2,param_3,param_4,param_5);
  piVar6 = param_4;
  if (iVar3 != 0) {
    uVar5 = 1;
    piVar6 = (int *)FUN_00146610(param_2,param_3,param_4);
    piVar4 = param_4;
  }
  iVar3 = FUN_000e07dc(param_5[2],0x1d);
  if (((((iVar3 != 0) &&
        (iVar3 = FUN_001633f8(piVar6,param_5,piVar4,puVar15,puVar16,param_6,param_7), iVar3 != 0))
       && (iVar3 = (**(code **)(*piVar6 + 100))(piVar6), iVar3 != 0)) &&
      ((param_2 != (int *)0x0 &&
       (iVar3 = FUN_00160320(param_2,param_3,piVar6,param_5,&local_58), iVar3 != 0)))) &&
     (piVar6 = (int *)FUN_00146610(param_2,param_3,piVar6), piVar6 == (int *)0x0)) {
    return 1;
  }
  iVar3 = FUN_00160eb0(param_2,param_3,piVar6,param_5);
  if (iVar3 != 0) {
    piVar6 = (int *)FUN_00146610(param_2,param_3,piVar6);
  }
  uVar21 = param_5[2];
  if (*(int *)(piVar6[0x22] + 8) != 0x77) goto LAB_00193490;
  iVar3 = FUN_000e07dc(uVar21,0x3d);
  if (iVar3 != 0) {
    iVar3 = FUN_001054ec(piVar6,1);
    iVar3 = FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
    if (((iVar3 != 0) &&
        (piVar4 = (int *)FUN_00105594(piVar6,1), *(int *)(piVar4[0x22] + 8) == 0x12)) &&
       ((piVar4[0x48] == 0 &&
        (((piVar4[0x49] == 0 && ((piVar4[5] & 0x200U) == 0)) &&
         (iVar3 = FUN_0010497c(piVar4,param_5), iVar3 != 0)))))) {
      iVar3 = FUN_001054ec(piVar4,0);
      iVar3 = FUN_000f37b8(*(undefined4 *)(iVar3 + 0x10));
      if (-1 < iVar3) {
        piVar7 = (int *)FUN_00105594(piVar4,1);
        piVar8 = (int *)FUN_00105594(piVar4,2);
        iVar9 = (**(code **)(*piVar7 + 0x48))(piVar7);
        if (iVar9 == 0) {
          iVar9 = (**(code **)(*piVar8 + 0x48))(piVar8);
          if (iVar9 == 0) goto LAB_0019348c;
          uVar14 = 2;
          iVar9 = 1;
        }
        else {
          uVar14 = 1;
          iVar9 = 2;
          piVar7 = piVar8;
        }
        iVar10 = ((undefined4 (*)())FUN_00139838)(piVar4,uVar14,-0.5);
        if (((iVar10 != 0) && ((piVar4[iVar9 * 6 + 0x28] & 1U) == 0)) &&
           ((piVar4[iVar9 * 6 + 0x28] & 2U) == 0)) {
          iVar9 = FUN_001054ec(piVar4,iVar9);
          uVar17 = (uint)*(byte *)(iVar3 + iVar9 + 0x10);
          if (((*(int *)(piVar7[0x22] + 8) == 0x12) && (piVar7[0x48] == 0)) && (piVar7[0x49] == 0))
          {
            iVar3 = FUN_001054ec(piVar7,0);
            uVar11 = FUN_000f37b8(*(undefined4 *)(iVar3 + 0x10));
            if ((uVar17 == uVar11) && (iVar3 = FUN_0010497c(piVar7,param_5), iVar3 != 0)) {
              iVar3 = FUN_00105594(piVar7,1);
              iVar9 = FUN_00105594(piVar7,2);
              uVar11 = piVar7[0x2e] & 1;
              if (((iVar3 == iVar9) &&
                  (((uVar11 != (piVar7[0x34] & 1U) && ((piVar7[0x2e] & 2U) == 0)) &&
                   ((piVar7[0x34] & 2U) == 0)))) &&
                 (iVar9 = FUN_001049a0(iVar9,param_5), iVar9 != 0)) {
                iVar9 = FUN_001054ec(piVar7,1);
                uVar20 = (uint)*(byte *)(uVar17 + iVar9 + 0x10);
                iVar9 = FUN_001054ec(piVar7,2);
                uVar18 = (uint)*(byte *)(uVar17 + iVar9 + 0x10);
                uVar17 = uVar18;
                if (uVar11 == 0) {
                  uVar17 = uVar20;
                  uVar20 = uVar18;
                }
                if ((((*(int *)(*(int *)(iVar3 + 0x88) + 8) == 0x25) &&
                     (iVar9 = ((undefined4 (*)())FUN_00139838)(iVar3,2,1.0), iVar9 != 0)) &&
                    ((iVar9 = ((undefined4 (*)())FUN_00139838)(iVar3,3,0.0), iVar9 != 0 &&
                     (((*(uint *)(iVar3 + 0x14) & 0x200) == 0 &&
                      ((*(uint *)(iVar3 + 0xb8) & 1) == 0)))))) &&
                   ((*(uint *)(iVar3 + 0xb8) & 2) == 0)) {
                  ((int (*)())FUN_0019401c)(piVar4);
                  ((int (*)())FUN_0019401c)(piVar7);
                  ((int (*)())FUN_0019401c)(iVar3);
                  FUN_00108174(piVar4,0x17,uVar21);
                  iVar3 = FUN_00105594(iVar3,1);
                  if ((int)param_5[0x11e] < *(int *)(iVar3 + 0x160)) {
                    *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar3 + 0x160) = param_5[0x11e] + 1;
                  }
                  if ((int)param_5[0x11e] < *(int *)(iVar3 + 0x160)) {
                    *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar3 + 0x160) = param_5[0x11e] + 1;
                  }
                  FUN_00106004(piVar4,1,iVar3,0,uVar21);
                  FUN_00106004(piVar4,2,iVar3,0,uVar21);
                  piVar4[0x27] = *(int *)(PTR_DAT_001e8b64 + uVar20 * 4);
                  FUN_00106804(piVar4,iVar3,0,uVar21);
                  iVar3 = FUN_001054ec(piVar4,1);
                  *(undefined4 *)(iVar3 + 0x10) = 0x4040404;
                  iVar3 = FUN_001054ec(piVar4,2);
                  *(undefined4 *)(iVar3 + 0x10) = 0x4040404;
                  iVar3 = FUN_001054ec(piVar6,1);
                  *(undefined4 *)(iVar3 + 0x10) = 0x4040404;
                  (**(code **)(*piVar6 + 0x88))(piVar6,1,uVar17,uVar17);
                  (**(code **)(*piVar6 + 0x88))(piVar6,1,uVar20,uVar20);
                  (**(code **)(*piVar4 + 0x88))(piVar4,1,uVar20,uVar20);
                  (**(code **)(*piVar4 + 0x88))(piVar4,2,uVar20,uVar20);
                  FUN_00103d50(piVar4 + 0x29,1,1);
                  FUN_00103d50(piVar4 + 0x2f,1,1);
                  piVar4[0x26] = 0;
                  piVar4[0x25] = piVar4[0x53];
                  if ((int)param_5[0x11e] < piVar4[0x58]) {
                    piVar4[0x58] = piVar4[0x58] + 1;
                  }
                  else {
                    piVar4[0x58] = param_5[0x11e] + 1;
                  }
                  FUN_000e7700(piVar6[0x56],piVar6,piVar4);
                  local_54[0] = *(int *)(PTR_DAT_001e8b64 + uVar17 * 4);
                  pcVar2 = PTR_DAT_001e8b64 + uVar20 * 4;
                  iVar9 = 4;
                  iVar3 = 0;
                  do {
                    if (*pcVar2 != '\x01') {
                      *(char *)((int)local_54 + iVar3) = *pcVar2;
                    }
                    iVar3 = iVar3 + 1;
                    pcVar2 = pcVar2 + 1;
                    iVar9 = iVar9 + -1;
                  } while (iVar9 != 0);
                  piVar6[0x27] = local_54[0];
                  piVar6[5] = piVar6[5] | 0x2000000;
                  piVar6 = (int *)FUN_00146610(param_2,param_3,piVar6);
                  uVar21 = param_5[2];
                  goto LAB_00193490;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0019348c:
  uVar21 = param_5[2];
LAB_00193490:
  iVar3 = FUN_000e07dc(uVar21,0x39);
  if (iVar3 != 0) {
    FUN_001882a4(piVar6,param_5[2]);
    for (iVar3 = 1; iVar9 = (**(code **)(*piVar6 + 0x14))(piVar6), iVar3 <= iVar9; iVar3 = iVar3 + 1
        ) {
      uVar21 = FUN_00105594(piVar6,iVar3);
      FUN_001875a8(piVar6,iVar3,uVar21,param_5);
    }
    iVar3 = FUN_001875a8(param_2,param_3,piVar6,param_5);
    if (iVar3 != 0) {
      uVar5 = 1;
      piVar6 = (int *)FUN_00146610(param_2,param_3,piVar6);
    }
  }
  piVar4 = (int *)((int (*)())FUN_001922c4)(param_2,param_3,piVar6,param_5);
  iVar3 = FUN_00159b58(piVar4,1,param_5);
  if (iVar3 != 0) {
    uVar5 = 1;
    piVar4 = (int *)FUN_00146610(param_2,param_3,piVar4);
  }
  iVar3 = FUN_0011379c(param_5[2],piVar4);
  if ((iVar3 != 0) && ((piVar4[5] & 0x200U) == 0)) {
    for (iVar3 = 1; iVar9 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar3 <= iVar9; iVar3 = iVar3 + 1
        ) {
      iVar9 = FUN_00105594(piVar4,iVar3);
      if ((((*(int *)(*(int *)(iVar9 + 0x88) + 8) == 0x4c) &&
           (iVar10 = FUN_0010497c(iVar9,param_5), iVar10 != 0)) &&
          ((*(uint *)(iVar9 + 0x14) & 0x200) != 0)) &&
         (iVar10 = FUN_00105594(iVar9,*(undefined4 *)(iVar9 + 0x84)),
         *(int *)(*(int *)(iVar10 + 0x88) + 8) == 0x4d)) {
        uVar21 = FUN_00105594(iVar9,*(undefined4 *)(iVar9 + 0x84));
        iVar10 = FUN_0010497c(uVar21,param_5);
        if ((iVar10 != 0) &&
           (iVar10 = FUN_00105594(iVar9,*(undefined4 *)(iVar9 + 0x84)),
           (*(uint *)(iVar10 + 0x14) & 0x200) == 0)) {
          iVar19 = 0;
          uVar21 = FUN_00105594(iVar9,*(undefined4 *)(iVar9 + 0x84));
          iVar12 = FUN_0010445c(piVar4,param_5[2],0);
          piVar6 = piVar4;
          iVar10 = iVar12;
          do {
            iVar13 = FUN_001054ec(piVar4,iVar3);
            uVar17 = (uint)*(byte *)(iVar19 + iVar13 + 0x10);
            if (uVar17 < 4) {
              iVar13 = FUN_000f313c(uVar21,uVar17);
              if (iVar13 == 0) {
                *(undefined1 *)(iVar10 + 0x9c) = 1;
              }
              else {
                *(undefined1 *)(piVar6 + 0x27) = 1;
              }
            }
            bVar1 = iVar19 != 3;
            piVar6 = (int *)((int)piVar6 + 1);
            iVar10 = iVar10 + 1;
            iVar19 = iVar19 + 1;
          } while (bVar1);
          FUN_00106004(iVar12,iVar3,uVar21,0,param_5[2]);
          FUN_00106804(piVar4,iVar12,0,param_5[2]);
          FUN_000e7700(piVar4[0x56],piVar4,iVar12);
          FUN_00106004(iVar9,*(undefined4 *)(iVar9 + 0x84),0,0,param_5[2]);
          *(int *)(iVar9 + 0x84) = *(int *)(iVar9 + 0x84) + -1;
          *(uint *)(iVar9 + 0x14) = *(uint *)(iVar9 + 0x14) & 0xfffffdff;
          FUN_000f35c4(piVar4);
          FUN_000f35c4(iVar12);
          iVar9 = *(int *)(iVar12 + 0x84);
          *(int *)(iVar12 + 0x160) = param_5[0x11e] + 1;
          if (0 < iVar9) {
            iVar10 = 1;
            do {
              if (iVar10 != iVar3) {
                piVar6 = (int *)FUN_00105594(iVar12,iVar10);
                iVar9 = (**(code **)(*piVar6 + 0x5c))();
                if (iVar9 == 0) {
                  iVar19 = FUN_00105594(iVar12,iVar10);
                  if ((int)param_5[0x11e] < *(int *)(iVar19 + 0x160)) {
                    iVar9 = *(int *)(iVar12 + 0x84);
                    *(int *)(iVar19 + 0x160) = *(int *)(iVar19 + 0x160) + 1;
                  }
                  else {
                    iVar9 = *(int *)(iVar12 + 0x84);
                    *(int *)(iVar19 + 0x160) = param_5[0x11e] + 1;
                  }
                }
                else {
                  uVar21 = FUN_00105594(iVar12,iVar10);
                  iVar9 = FUN_0010445c(uVar21,param_5[2],0);
                  FUN_00106004(iVar12,iVar10,iVar9,0,param_5[2]);
                  FUN_000e7700(*(undefined4 *)(iVar12 + 0x158),iVar12,iVar9);
                  if (0 < *(int *)(iVar9 + 0x84)) {
                    iVar19 = 1;
                    do {
                      iVar13 = FUN_00105594(iVar9,iVar19);
                      if ((int)param_5[0x11e] < *(int *)(iVar13 + 0x160)) {
                        *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
                      }
                      else {
                        *(int *)(iVar13 + 0x160) = param_5[0x11e] + 1;
                      }
                      iVar19 = iVar19 + 1;
                    } while (iVar19 <= *(int *)(iVar9 + 0x84));
                  }
                  iVar9 = *(int *)(iVar12 + 0x84);
                }
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 <= iVar9);
          }
          break;
        }
      }
    }
  }
  iVar3 = FUN_000e07dc(param_5[2],0x3a);
  if (iVar3 == 0) {
    return uVar5;
  }
  if (((int)param_5[0x8a] < *(int *)(param_5[2] + 0x664)) &&
     (iVar3 = FUN_0015ea3c(param_2,param_3,piVar4,param_5), iVar3 != 0)) {
    uVar5 = 1;
    piVar4 = (int *)FUN_00146610(param_2,param_3,piVar4);
  }
  iVar3 = FUN_0015f44c(param_2,param_3,piVar4,param_5);
  if (iVar3 != 0) {
    FUN_00146610(param_2,param_3,piVar4);
    return 1;
  }
  return uVar5;
}

/* FUN_00193944 @ 0x193944 (112 bytes) */
int FUN_00193944(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  int param_3;
  undefined4 *param_4;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_3 + 0x88) + 8);
  iVar1 = (**(code **)(*param_2 + 0x24))
                    (param_2,param_2,param_3,param_4,in_r7,in_r8,*(int *)(param_3 + 0x88));
  if ((iVar1 == 0) || (3 < iVar3 - 0x9eU)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    *param_4 = 2;
  }
  return uVar2;
}

/* FUN_001939b4 @ 0x1939b4 (76 bytes) */
int FUN_001939b4(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (*(int *)(*(int *)(param_1 + 8) + 0x6b8) != 0) {
    return 1;
  }
  if ((param_2 < 0x18) && ((param_3 < 0x10 || (param_4 <= param_3 << 2)))) {
    uVar1 = 0;
    uVar2 = 0;
  }
  else {
    uVar1 = 1;
    uVar2 = 1;
  }
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x6b8) = uVar1;
  return uVar2;
}

/* FUN_00193a00 @ 0x193a00 (140 bytes) */
int FUN_00193a00(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_000e07dc(*(undefined4 *)(param_2 + 8),0x4a);
  if (iVar1 != 0) {
    piVar2 = *(int **)(param_2 + 900);
    iVar1 = piVar2[2];
    while (iVar1 != 0) {
      iVar1 = (**(code **)(*piVar2 + 0x24))(piVar2);
      if (iVar1 != 0) {
        piVar2 = (int *)FUN_0012bb48(param_2,piVar2);
      }
      piVar2 = (int *)piVar2[2];
      iVar1 = piVar2[2];
    }
  }
  return;
}

/* FUN_00193a8c @ 0x193a8c (88 bytes) */
int FUN_00193a8c(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  param_1[1] = param_3;
  *param_1 = param_4;
  param_1[2] = param_2;
  if (param_2 < 3) {
    param_1[5] = 0;
  }
  else {
    iVar1 = ((int (*)())FUN_00193e18)(*(undefined4 *)(param_4 + 0x370),param_2 << 2);
    param_1[5] = iVar1;
  }
  return;
}

/* FUN_00193ae4 @ 0x193ae4 (88 bytes) */
int FUN_00193ae4(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  param_1[1] = param_3;
  *param_1 = param_4;
  param_1[2] = param_2;
  if (param_2 < 3) {
    param_1[5] = 0;
  }
  else {
    iVar1 = ((int (*)())FUN_00193e18)(*(undefined4 *)(param_4 + 0x370),param_2 << 2);
    param_1[5] = iVar1;
  }
  return;
}

/* FUN_00193b3c @ 0x193b3c (76 bytes) */
int FUN_00193b3c(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_3 + 0x370);
  puVar1 = (undefined4 *)((int (*)())FUN_00193e18)(uVar2,0x1c);
  *puVar1 = uVar2;
  ((int (*)())FUN_00193ae4)(puVar1 + 1,1,0x22,param_3);
  puVar1[4] = param_1;
  puVar1[3] = 1;
  puVar1[5] = param_2;
  return puVar1 + 1;
}

/* FUN_00193be8 @ 0x193be8 (24 bytes) */
int FUN_00193be8(param_1)
  int *param_1;
{
  if (param_1[5] == 0) {
    return;
  }
  ((int (*)())FUN_00193cc0)(*(undefined4 *)(*param_1 + 0x370),param_1[5]);
  return;
}

/* FUN_00193c00 @ 0x193c00 (116 bytes) */
int FUN_00193c00(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 4;
  cVar1 = *(char *)(param_1 + 5);
  if ((cVar1 != '\x01') && (iVar3 = 0x10, cVar1 != '\x02')) {
    iVar3 = (uint)(cVar1 == '\0') << 1;
  }
  uVar4 = *(undefined4 *)(param_2 + 0x370);
  puVar2 = (undefined4 *)((int (*)())FUN_00193e18)(uVar4,0x1c);
  *puVar2 = uVar4;
  ((int (*)())FUN_00193ae4)(puVar2 + 1,1,iVar3,param_2);
  puVar2[4] = param_1;
  puVar2[3] = 1;
  puVar2[5] = 0;
  return puVar2 + 1;
}

/* FUN_00193cc0 @ 0x193cc0 (88 bytes) */
int FUN_00193cc0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x28) != 0) && (iVar1 = *(int *)(param_1 + 0x14), iVar1 == param_2)) {
    _memset(iVar1,0,*(int *)(param_1 + 8) - iVar1);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x14);
  }
  return;
}

/* FUN_00193d18 @ 0x193d18 (124 bytes) */
int FUN_00193d18(param_1)
  int *param_1;
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)param_1[1];
  while (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    (**(code **)(*param_1 + 0x34c))(*(undefined4 *)(*param_1 + 0x354),piVar1);
    piVar1 = (int *)iVar2;
  }
  param_1[3] = 0;
  param_1[1] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[2] = 0;
  return;
}

/* FUN_00193d98 @ 0x193d98 (128 bytes) */
int FUN_00193d98(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 uVar5;
  
  puVar1 = (undefined *)(param_2 + 3U & 0xfffffffc);
  puVar4 = ((unsigned char *)0x00002fd8);
  if (0x2fd7 < (int)puVar1) {
    puVar4 = puVar1;
  }
  uVar5 = param_1[1];
  puVar2 = (undefined4 *)FUN_000e1564(*param_1,(uint)(puVar4 + 8));
  param_1[1] = puVar2;
  *puVar2 = uVar5;
  *(undefined **)(param_1[1] + 4) = puVar4 + 8;
  iVar3 = param_1[1] + 8;
  param_1[5] = iVar3;
  param_1[4] = puVar4 + param_1[1] + 8;
  param_1[2] = iVar3;
  return;
}

/* FUN_00193e18 @ 0x193e18 (92 bytes) */
int FUN_00193e18(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_2 + 3U & 0xfffffffc;
  if (*(uint *)(param_1 + 0x10) < uVar1 + *(int *)(param_1 + 8)) {
    ((int (*)())FUN_00193d98)(param_1,uVar1);
  }
  iVar2 = *(int *)(param_1 + 8);
  *(int *)(param_1 + 0x14) = iVar2;
  *(uint *)(param_1 + 8) = uVar1 + iVar2;
  return iVar2;
}

/* FUN_00193e74 @ 0x193e74 (68 bytes) */
int FUN_00193e74(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())FUN_00193e18)(param_1,param_2 * param_3);
  _memset(uVar1,0,param_2 * param_3);
  return uVar1;
}

/* FUN_00193eb8 @ 0x193eb8 (76 bytes) */
int FUN_00193eb8(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  piVar3 = (int *)*piVar1;
  iVar2 = piVar1[1] - (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 8));
  if (piVar3 == (int *)0x0) {
    return iVar2;
  }
  do {
    piVar1 = piVar3 + 1;
    piVar3 = (int *)*piVar3;
    iVar2 = iVar2 + *piVar1;
  } while (piVar3 != (int *)0x0);
  return iVar2;
}

/* FUN_00193f08 @ 0x193f08 (24 bytes) */
int FUN_00193f08(param_1)
  int param_1;
{
  return *(int *)(param_1 + 8) == param_1 + 0xc;
}

/* FUN_00193f20 @ 0x193f20 (36 bytes) */
int FUN_00193f20(param_1)
  int *param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[2];
  iVar1 = *param_1;
  *(int *)(iVar2 + 4) = param_1[1];
  *(int *)(param_1[1] + 8) = iVar2;
                    
                    
  (**(code **)(iVar1 + 4))();
  return;
}

/* FUN_00193f44 @ 0x193f44 (32 bytes) */
int FUN_00193f44(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 4);
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 != 0) {
    *(int *)(iVar1 + 8) = param_1;
  }
  *(int *)(param_2 + 4) = param_1;
  *(int *)(param_1 + 8) = param_2;
  return;
}

/* FUN_00193f64 @ 0x193f64 (16 bytes) */
int FUN_00193f64(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_00193f44)(param_2,param_1 + 0xc);
  return;
}

/* FUN_00193f74 @ 0x193f74 (32 bytes) */
int FUN_00193f74(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 8);
  *(int *)(param_1 + 8) = iVar1;
  if (iVar1 != 0) {
    *(int *)(iVar1 + 4) = param_1;
  }
  *(int *)(param_2 + 8) = param_1;
  *(int *)(param_1 + 4) = param_2;
  return;
}

/* FUN_00193f94 @ 0x193f94 (16 bytes) */
int FUN_00193f94(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_00193f74)(param_2,param_1);
  return;
}

/* FUN_00193fa4 @ 0x193fa4 (16 bytes) */
int FUN_00193fa4(param_1)
  int param_1;
{
  *(int *)(param_1 + 0x10) = param_1;
  *(int *)(param_1 + 8) = param_1 + 0xc;
  return;
}

/* FUN_00193fb4 @ 0x193fb4 (104 bytes) */
int FUN_00193fb4(param_1)
  int param_1;
{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  while (piVar1 != (int *)(param_1 + 0xc)) {
    piVar2 = (int *)piVar1[2];
    (**(code **)(*piVar1 + 4))(piVar1);
    piVar1 = piVar2;
  }
  ((int (*)())FUN_00193fa4)(param_1);
  return;
}

/* FUN_0019401c @ 0x19401c (24 bytes) */
int FUN_0019401c(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 8);
  *(int *)(*(int *)(param_1 + 8) + 4) = iVar1;
  return;
}

/* FUN_00194034 @ 0x194034 (44 bytes) */
int FUN_00194034(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = *(int *)(param_1 + 8); iVar1 != param_1 + 0xc; iVar1 = *(int *)(iVar1 + 8)) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

/* FUN_00194060 @ 0x194060 (72 bytes) */
int FUN_00194060(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  param_1[4] = 0;
  puVar1 = PTR_DAT_001e8b48;
  param_1[5] = 0;
  param_1[5] = 0;
  param_1[3] = puVar1 + 8;
  param_1[2] = param_1 + 3;
  *param_1 = puVar1 + 8;
  param_1[1] = 0;
  param_1[4] = param_1;
  return;
}

/* FUN_001940a8 @ 0x1940a8 (72 bytes) */
int FUN_001940a8(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  param_1[4] = 0;
  puVar1 = PTR_DAT_001e8b48;
  param_1[5] = 0;
  param_1[5] = 0;
  param_1[3] = puVar1 + 8;
  param_1[2] = param_1 + 3;
  *param_1 = puVar1 + 8;
  param_1[1] = 0;
  param_1[4] = param_1;
  return;
}

/* FUN_001940f0 @ 0x1940f0 (280 bytes) */
int FUN_001940f0(param_1, param_2)
  int param_1;
  code *param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  uVar1 = 1;
  iVar8 = *(int *)(param_1 + 8);
  uVar3 = *(uint *)(param_1 + 4);
  do {
    uVar1 = uVar1 * 3 + 1;
  } while (uVar1 < uVar3);
  do {
    do {
      uVar1 = uVar1 / 3;
      if (uVar1 == 0) {
        return;
      }
    } while (uVar3 <= uVar1);
    puVar4 = (undefined4 *)(iVar8 + uVar1 * 4);
    iVar7 = 0;
    uVar5 = uVar1;
    do {
      uVar6 = *puVar4;
      for (iVar9 = iVar7; -1 < iVar9; iVar9 = iVar9 - uVar1) {
        iVar2 = (*param_2)(*(undefined4 *)(iVar8 + iVar9 * 4),uVar6);
        if (iVar2 < 1) break;
        *(undefined4 *)((uVar1 + iVar9) * 4 + iVar8) = *(undefined4 *)(iVar8 + iVar9 * 4);
      }
      uVar5 = uVar5 + 1;
      iVar7 = iVar7 + 1;
      *(undefined4 *)(iVar8 + (uVar1 + iVar9) * 4) = uVar6;
      puVar4 = puVar4 + 1;
      uVar3 = *(uint *)(param_1 + 4);
    } while (uVar5 < uVar3);
  } while( true );
}

/* FUN_00194208 @ 0x194208 (52 bytes) */
int FUN_00194208(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  int iVar2;
  
  if (*(uint *)(param_1 + 4) <= param_2) {
    return;
  }
  iVar1 = *(uint *)(param_1 + 4) - 1;
  iVar2 = param_2 * 4 + *(int *)(param_1 + 8);
  *(int *)(param_1 + 4) = iVar1;
  _memcpy(iVar2,iVar2 + 4,(iVar1 - param_2) * 4);
  return;
}

/* FUN_0019423c @ 0x19423c (152 bytes) */
int FUN_0019423c(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  if (uVar1 <= param_2) {
    do {
      uVar1 = uVar1 << 1;
    } while (uVar1 <= param_2);
    *param_1 = uVar1;
  }
  uVar2 = param_1[2];
  uVar1 = ((int (*)())FUN_00193e18)(param_1[3],uVar1 << 2);
  param_1[2] = uVar1;
  _memcpy(uVar1,uVar2,param_1[1] << 2);
  ((int (*)())FUN_00193cc0)(param_1[3],uVar2);
  if (param_1[1] < param_2 + 1) {
    param_1[1] = param_2 + 1;
  }
  return param_2 * 4 + param_1[2];
}

/* FUN_001942d4 @ 0x1942d4 (160 bytes) */
int FUN_001942d4(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar2 = param_1[1];
  if (param_1[1] < param_2) {
    uVar2 = param_2;
  }
  if (*param_1 < uVar2 + 1) {
    ((int (*)())FUN_0019423c)(param_1,uVar2);
  }
  else {
    param_1[1] = uVar2 + 1;
  }
  iVar1 = (param_1[1] - param_2) + -1;
  iVar3 = param_2 * 4 + param_1[2];
  puVar4 = (undefined4 *)(iVar3 + iVar1 * 4);
  if (iVar1 != 0) {
    iVar1 = (param_1[1] - param_2) + -1;
    puVar5 = puVar4;
    do {
      puVar4 = puVar5 + -1;
      *puVar5 = *puVar4;
      iVar1 = iVar1 + -1;
      puVar5 = puVar4;
    } while (iVar1 != 0);
  }
  *puVar4 = 0;
  return iVar3;
}

/* FUN_00194374 @ 0x194374 (124 bytes) */
int FUN_00194374(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 0) {
LAB_001943c4:
    uVar2 = 0;
  }
  else {
    iVar3 = 0;
    if (param_2 != **(int **)(param_1 + 8)) {
      iVar3 = 0;
      do {
        iVar3 = iVar3 + 1;
        iVar1 = iVar1 + -1;
        if (iVar1 == 0) goto LAB_001943c4;
      } while (param_2 != (*(int **)(param_1 + 8))[iVar3]);
    }
    ((int (*)())FUN_00194208)(param_1,iVar3);
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_001943f0 @ 0x1943f0 (276 bytes) */
int FUN_001943f0(param_1)
  uint *param_1;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  uVar1 = *param_1;
  if (uVar1 == 0) {
    uVar3 = param_1[2];
  }
  else {
    uVar3 = param_1[2];
    uVar5 = 0;
    do {
      puVar6 = *(uint **)(uVar3 + uVar5 * 4);
      if (puVar6 != (uint *)0x0) {
        uVar1 = puVar6[1];
        if (uVar1 != 0) {
          uVar3 = 0;
          do {
            if (uVar3 < *puVar6) {
              if (uVar1 <= uVar3) {
                _memset(uVar1 * 4 + puVar6[2],0,(uVar3 - uVar1) * 4 + 4);
                puVar6[1] = uVar3 + 1;
              }
              piVar2 = (int *)(uVar3 * 4 + puVar6[2]);
            }
            else {
              piVar2 = (int *)((int (*)())FUN_0019423c)(puVar6,uVar3);
            }
            uVar3 = uVar3 + 1;
            iVar4 = *piVar2;
            if (iVar4 != 0) {
              ((int (*)())FUN_00193cc0)(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
            }
            uVar1 = puVar6[1];
          } while (uVar3 < uVar1);
          uVar3 = param_1[2];
        }
        ((int (*)())FUN_00193cc0)(param_1[5],*(undefined4 *)(uVar3 + uVar5 * 4));
        uVar1 = *param_1;
        uVar3 = param_1[2];
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  ((int (*)())FUN_00193cc0)(param_1[5],uVar3);
  return;
}

/* FUN_00194504 @ 0x194504 (276 bytes) */
int FUN_00194504(param_1)
  uint *param_1;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  uVar1 = *param_1;
  if (uVar1 == 0) {
    uVar3 = param_1[2];
  }
  else {
    uVar3 = param_1[2];
    uVar5 = 0;
    do {
      puVar6 = *(uint **)(uVar3 + uVar5 * 4);
      if (puVar6 != (uint *)0x0) {
        uVar1 = puVar6[1];
        if (uVar1 != 0) {
          uVar3 = 0;
          do {
            if (uVar3 < *puVar6) {
              if (uVar1 <= uVar3) {
                _memset(uVar1 * 4 + puVar6[2],0,(uVar3 - uVar1) * 4 + 4);
                puVar6[1] = uVar3 + 1;
              }
              piVar2 = (int *)(uVar3 * 4 + puVar6[2]);
            }
            else {
              piVar2 = (int *)((int (*)())FUN_0019423c)(puVar6,uVar3);
            }
            uVar3 = uVar3 + 1;
            iVar4 = *piVar2;
            if (iVar4 != 0) {
              ((int (*)())FUN_00193cc0)(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
            }
            uVar1 = puVar6[1];
          } while (uVar3 < uVar1);
          uVar3 = param_1[2];
        }
        ((int (*)())FUN_00193cc0)(param_1[5],*(undefined4 *)(uVar3 + uVar5 * 4));
        uVar1 = *param_1;
        uVar3 = param_1[2];
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  ((int (*)())FUN_00193cc0)(param_1[5],uVar3);
  return;
}

/* FUN_00194618 @ 0x194618 (264 bytes) */
int FUN_00194618(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar1 = (*(code *)param_1[4])(param_2,param_2);
  puVar5 = *(uint **)((uVar1 & *param_1 - 1U) * 4 + param_1[2]);
  if ((puVar5 != (uint *)0x0) && (uVar1 = puVar5[1], uVar1 != 0)) {
    uVar4 = 0;
    do {
      if (uVar4 < *puVar5) {
        if (uVar1 <= uVar4) {
          _memset(uVar1 * 4 + puVar5[2],0,(uVar4 - uVar1) * 4 + 4);
          puVar5[1] = uVar4 + 1;
        }
        puVar2 = (undefined4 *)(uVar4 * 4 + puVar5[2]);
      }
      else {
        puVar2 = (undefined4 *)((int (*)())FUN_0019423c)(puVar5,uVar4);
      }
      puVar2 = (undefined4 *)*puVar2;
      iVar3 = (*(code *)param_1[3])(*puVar2,param_2);
      if (iVar3 == 0) {
  return puVar2;
      }
      uVar1 = puVar5[1];
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return 0;
}

/* FUN_00194720 @ 0x194720 (276 bytes) */
int FUN_00194720(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar1 = (*(code *)param_1[4])(param_2,param_2);
  puVar5 = *(uint **)((*param_1 - 1U & uVar1) * 4 + param_1[2]);
  if ((puVar5 != (uint *)0x0) && (uVar1 = puVar5[1], uVar1 != 0)) {
    uVar4 = 0;
    do {
      if (uVar4 < *puVar5) {
        if (uVar1 <= uVar4) {
          _memset(uVar1 * 4 + puVar5[2],0,(uVar4 - uVar1) * 4 + 4);
          puVar5[1] = uVar4 + 1;
        }
        puVar2 = (undefined4 *)(uVar4 * 4 + puVar5[2]);
      }
      else {
        puVar2 = (undefined4 *)((int (*)())FUN_0019423c)(puVar5,uVar4);
      }
      iVar3 = (*(code *)param_1[3])(*puVar2,param_2);
      if (iVar3 == 0) {
        ((int (*)())FUN_00194208)(puVar5,uVar4);
        return;
      }
      uVar1 = puVar5[1];
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return;
}

/* FUN_00194834 @ 0x194834 (260 bytes) */
int FUN_00194834(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 uVar6;
  
  uVar1 = (*(code *)param_1[4])(param_2,param_2);
  puVar5 = *(uint **)((*param_1 - 1U & uVar1) * 4 + param_1[2]);
  if ((puVar5 != (uint *)0x0) && (uVar1 = puVar5[1], uVar1 != 0)) {
    uVar4 = 0;
    do {
      if (uVar4 < *puVar5) {
        if (uVar1 <= uVar4) {
          _memset(uVar1 * 4 + puVar5[2],0,(uVar4 - uVar1) * 4 + 4);
          puVar5[1] = uVar4 + 1;
        }
        puVar2 = (undefined4 *)(uVar4 * 4 + puVar5[2]);
      }
      else {
        puVar2 = (undefined4 *)((int (*)())FUN_0019423c)(puVar5,uVar4);
      }
      uVar6 = *puVar2;
      iVar3 = (*(code *)param_1[3])(uVar6,param_2);
      if (iVar3 == 0) {
        return uVar6;
      }
      uVar1 = puVar5[1];
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return 0;
}

/* FUN_00194938 @ 0x194938 (348 bytes) */
int FUN_00194938(param_1)
  undefined4 *param_1;
{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  uVar5 = param_1[3];
  if ((int)uVar5 < 0) {
    uVar5 = param_1[1];
    do {
      uVar5 = uVar5 + 1;
      param_1[1] = uVar5;
      if (*(uint *)*param_1 <= uVar5) {
        param_1[4] = 0;
        return;
      }
      puVar4 = *(uint **)(uVar5 * 4 + ((uint *)*param_1)[2]);
      param_1[2] = puVar4;
    } while ((puVar4 == (uint *)0x0) || (uVar1 = puVar4[1], uVar1 == 0));
    uVar5 = uVar1 - 1;
    param_1[3] = uVar1 - 2;
    if (uVar5 < *puVar4) {
      uVar3 = puVar4[1];
      if (uVar3 <= uVar5) {
        _memset(uVar3 * 4 + puVar4[2],0,(uVar5 - uVar3) * 4 + 4);
        puVar4[1] = uVar1;
      }
      puVar2 = (undefined4 *)(uVar5 * 4 + puVar4[2]);
    }
    else {
      puVar2 = (undefined4 *)((int (*)())FUN_0019423c)(puVar4,uVar5);
    }
  }
  else {
    puVar4 = (uint *)param_1[2];
    param_1[3] = uVar5 - 1;
    if (uVar5 < *puVar4) {
      uVar1 = puVar4[1];
      if (uVar1 <= uVar5) {
        _memset(uVar1 * 4 + puVar4[2],0,(uVar5 - uVar1) * 4 + 4);
        puVar4[1] = uVar5 + 1;
      }
      puVar2 = (undefined4 *)(uVar5 * 4 + puVar4[2]);
    }
    else {
      puVar2 = (undefined4 *)((int (*)())FUN_0019423c)(puVar4,uVar5);
    }
  }
  param_1[4] = *puVar2;
  return;
}

/* FUN_00194a94 @ 0x194a94 (20 bytes) */
int FUN_00194a94(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  param_1[3] = 0xffffffff;
  param_1[1] = 0xffffffff;
  ((int (*)())FUN_00194938)(param_1);
  return;
}

/* FUN_00194aa8 @ 0x194aa8 (260 bytes) */
int FUN_00194aa8(param_1)
  uint *param_1;
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  undefined4 uVar15;
  uint uVar16;
  uint uVar17;
  
  uVar5 = *param_1;
  *param_1 = uVar5 << 1;
  uVar1 = ((int (*)())FUN_00193e18)(param_1[5],uVar5 << 3);
  _memset(uVar1,0,*param_1 << 2);
  if (0 < (int)uVar5) {
    uVar8 = 0;
    puVar7 = (undefined4 *)(uVar1 + uVar5 * 4);
    iVar6 = 0;
    do {
      puVar13 = *(uint **)(param_1[2] + iVar6);
      if (puVar13 != (uint *)0x0) {
        uVar17 = param_1[5];
        puVar2 = (uint *)((int (*)())FUN_00193e18)(uVar17,0x14);
        *puVar2 = uVar17;
        uVar17 = param_1[5];
        puVar2[1] = 2;
        puVar2[4] = uVar17;
        puVar2[2] = 0;
        uVar17 = ((int (*)())FUN_00193e18)(uVar17,8);
        puVar2[3] = uVar17;
        *(uint **)(uVar1 + iVar6) = puVar2 + 1;
        uVar17 = param_1[5];
        puVar2 = (uint *)((int (*)())FUN_00193e18)(uVar17,0x14);
        *puVar2 = uVar17;
        puVar14 = puVar2 + 1;
        uVar17 = param_1[5];
        puVar2[1] = 2;
        puVar2[2] = 0;
        puVar2[4] = uVar17;
        uVar17 = ((int (*)())FUN_00193e18)(uVar17,8);
        puVar2[3] = uVar17;
        uVar11 = 0;
        *puVar7 = puVar14;
        uVar10 = puVar13[1];
        puVar9 = *(uint **)(uVar1 + iVar6);
        iVar12 = uVar10 << 2;
        uVar17 = uVar10;
        while( true ) {
          iVar12 = iVar12 + -4;
          uVar16 = uVar17 - 1;
          if (uVar10 == uVar11) break;
          if (uVar16 < *puVar13) {
            uVar3 = puVar13[1];
            if (uVar3 <= uVar16) {
              _memset(uVar3 * 4 + puVar13[2],0,(uVar16 - uVar3) * 4 + 4);
              puVar13[1] = uVar17;
            }
            puVar4 = (undefined4 *)(iVar12 + puVar13[2]);
          }
          else {
            puVar4 = (undefined4 *)((int (*)())FUN_0019423c)(puVar13,uVar16);
          }
          uVar15 = *puVar4;
          uVar17 = (*(code *)param_1[4])(uVar15);
          if (uVar8 == (uVar17 & *param_1 - 1)) {
            uVar17 = puVar9[1];
            if (uVar17 < *puVar9) {
              _memset(uVar17 * 4 + puVar9[2],0,4);
              puVar4 = (undefined4 *)(uVar17 * 4 + puVar9[2]);
              puVar9[1] = uVar17 + 1;
            }
            else {
              puVar4 = (undefined4 *)((int (*)())FUN_0019423c)(puVar9,uVar17);
            }
          }
          else {
            uVar17 = puVar2[2];
            if (uVar17 < *puVar14) {
              _memset(uVar17 * 4 + puVar2[3],0,4);
              puVar4 = (undefined4 *)(uVar17 * 4 + puVar2[3]);
              puVar2[2] = uVar17 + 1;
            }
            else {
              puVar4 = (undefined4 *)((int (*)())FUN_0019423c)(puVar14,uVar17);
            }
          }
          *puVar4 = uVar15;
          uVar11 = uVar11 + 1;
          uVar17 = uVar16;
        }
      }
      uVar8 = uVar8 + 1;
      iVar6 = iVar6 + 4;
      puVar7 = puVar7 + 1;
    } while (uVar5 != uVar8);
  }
  param_1[2] = uVar1;
  return;
}

/* FUN_00194d44 @ 0x194d44 (184 bytes) */
int FUN_00194d44(param_1, param_2)
  uint *param_1;
  undefined4 param_2;
{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = (*(code *)param_1[4])(param_2,param_2);
  uVar4 = param_1[2];
  iVar5 = (*param_1 - 1 & uVar1) * 4;
  if (*(int *)(iVar5 + uVar4) == 0) {
    uVar1 = param_1[5];
    puVar2 = (uint *)((int (*)())FUN_00193e18)(uVar1,0x14);
    *puVar2 = uVar1;
    uVar1 = param_1[5];
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2[4] = uVar1;
    uVar1 = ((int (*)())FUN_00193e18)(uVar1,8);
    puVar2[3] = uVar1;
    *(uint **)(iVar5 + uVar4) = puVar2 + 1;
    uVar4 = param_1[2];
  }
  iVar5 = *(int *)(iVar5 + uVar4);
  puVar3 = (undefined4 *)((int (*)())FUN_001942d4)(iVar5,0);
  *puVar3 = param_2;
  if (*param_1 < *(uint *)(iVar5 + 4)) {
    ((int (*)())FUN_00194aa8)(param_1);
  }
  param_1[1] = param_1[1] + 1;
  return;
}

/* FUN_00194e44 @ 0x194e44 (260 bytes) */
int FUN_00194e44(param_1)
  uint *param_1;
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  uint *puVar15;
  uint uVar16;
  uint uVar17;
  
  uVar6 = *param_1;
  *param_1 = uVar6 << 1;
  uVar1 = ((int (*)())FUN_00193e18)(param_1[5],uVar6 << 3);
  _memset(uVar1,0,*param_1 << 2);
  if (uVar6 != 0) {
    uVar9 = 0;
    puVar8 = (undefined4 *)(uVar1 + uVar6 * 4);
    iVar7 = 0;
    do {
      puVar14 = *(uint **)(param_1[2] + iVar7);
      if (puVar14 != (uint *)0x0) {
        uVar17 = param_1[5];
        puVar2 = (uint *)((int (*)())FUN_00193e18)(uVar17,0x14);
        *puVar2 = uVar17;
        uVar17 = param_1[5];
        puVar2[1] = 2;
        puVar2[4] = uVar17;
        puVar2[2] = 0;
        uVar17 = ((int (*)())FUN_00193e18)(uVar17,8);
        puVar2[3] = uVar17;
        *(uint **)(uVar1 + iVar7) = puVar2 + 1;
        uVar17 = param_1[5];
        puVar2 = (uint *)((int (*)())FUN_00193e18)(uVar17,0x14);
        *puVar2 = uVar17;
        puVar15 = puVar2 + 1;
        uVar17 = param_1[5];
        puVar2[1] = 2;
        puVar2[2] = 0;
        puVar2[4] = uVar17;
        uVar17 = ((int (*)())FUN_00193e18)(uVar17,8);
        puVar2[3] = uVar17;
        uVar12 = 0;
        *puVar8 = puVar15;
        uVar11 = puVar14[1];
        puVar10 = *(uint **)(uVar1 + iVar7);
        iVar13 = uVar11 << 2;
        uVar17 = uVar11;
        while( true ) {
          iVar13 = iVar13 + -4;
          uVar16 = uVar17 - 1;
          if (uVar11 == uVar12) break;
          if (uVar16 < *puVar14) {
            uVar3 = puVar14[1];
            if (uVar3 <= uVar16) {
              _memset(uVar3 * 4 + puVar14[2],0,(uVar16 - uVar3) * 4 + 4);
              puVar14[1] = uVar17;
            }
            puVar4 = (undefined4 *)(iVar13 + puVar14[2]);
          }
          else {
            puVar4 = (undefined4 *)((int (*)())FUN_0019423c)(puVar14,uVar16);
          }
          puVar4 = (undefined4 *)*puVar4;
          uVar17 = (*(code *)param_1[4])(*puVar4);
          if (uVar9 == (uVar17 & *param_1 - 1)) {
            uVar17 = puVar10[1];
            if (uVar17 < *puVar10) {
              _memset(uVar17 * 4 + puVar10[2],0,4);
              puVar5 = (undefined4 *)(uVar17 * 4 + puVar10[2]);
              puVar10[1] = uVar17 + 1;
            }
            else {
              puVar5 = (undefined4 *)((int (*)())FUN_0019423c)(puVar10,uVar17);
            }
          }
          else {
            uVar17 = puVar2[2];
            if (uVar17 < *puVar15) {
              _memset(uVar17 * 4 + puVar2[3],0,4);
              puVar5 = (undefined4 *)(uVar17 * 4 + puVar2[3]);
              puVar2[2] = uVar17 + 1;
            }
            else {
              puVar5 = (undefined4 *)((int (*)())FUN_0019423c)(puVar15,uVar17);
            }
          }
          *puVar5 = puVar4;
          uVar12 = uVar12 + 1;
          uVar17 = uVar16;
        }
      }
      uVar9 = uVar9 + 1;
      iVar7 = iVar7 + 4;
      puVar8 = puVar8 + 1;
    } while (uVar6 != uVar9);
  }
  param_1[2] = uVar1;
  return;
}

/* FUN_001950e0 @ 0x1950e0 (208 bytes) */
int FUN_001950e0(param_1, param_2, param_3)
  uint *param_1;
  uint param_2;
  uint param_3;
{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  uVar1 = (*(code *)param_1[4])(param_2,param_2,param_3);
  uVar5 = param_1[2];
  iVar4 = (uVar1 & *param_1 - 1) * 4;
  if (*(int *)(iVar4 + uVar5) == 0) {
    uVar1 = param_1[5];
    puVar2 = (uint *)((int (*)())FUN_00193e18)(uVar1,0x14);
    *puVar2 = uVar1;
    uVar1 = param_1[5];
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2[4] = uVar1;
    uVar1 = ((int (*)())FUN_00193e18)(uVar1,8);
    puVar2[3] = uVar1;
    *(uint **)(iVar4 + uVar5) = puVar2 + 1;
    uVar5 = param_1[2];
  }
  uVar1 = param_1[5];
  puVar6 = *(uint **)(iVar4 + uVar5);
  puVar2 = (uint *)((int (*)())FUN_00193e18)(uVar1,0xc);
  *puVar2 = uVar1;
  puVar2[1] = param_2;
  puVar2[2] = param_3;
  uVar1 = puVar6[1];
  if (uVar1 != 0) {
    uVar5 = 0;
    do {
      if (uVar5 < *puVar6) {
        if (uVar1 <= uVar5) {
          _memset(uVar1 * 4 + puVar6[2],0,(uVar5 - uVar1) * 4 + 4);
          puVar6[1] = uVar5 + 1;
        }
        puVar3 = (undefined4 *)(uVar5 * 4 + puVar6[2]);
      }
      else {
        puVar3 = (undefined4 *)((int (*)())FUN_0019423c)(puVar6,uVar5);
      }
      uVar5 = uVar5 + 1;
      puVar3 = (undefined4 *)*puVar3;
      iVar4 = (*(code *)param_1[3])(*puVar3,param_2);
      if (((iVar4 == 0) && (param_3 == puVar3[1])) && (puVar2 + 1 != (uint *)0x0)) {
        ((int (*)())FUN_00193cc0)(*puVar2,puVar2);
      }
      uVar1 = puVar6[1];
    } while (uVar5 < uVar1);
  }
  puVar3 = (undefined4 *)((int (*)())FUN_001942d4)(puVar6,0);
  *puVar3 = puVar2 + 1;
  if (*param_1 < puVar6[1]) {
    ((int (*)())FUN_00194e44)(param_1);
  }
  param_1[1] = param_1[1] + 1;
  return;
}

/* FUN_001952d8 @ 0x1952d8 (88 bytes) */
int FUN_001952d8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_2 + param_1 * 4);
  iVar3 = param_1;
  if (param_1 != iVar2) {
    do {
      iVar3 = *(int *)(param_2 + iVar2 * 4);
      iVar2 = *(int *)(iVar3 * 4 + param_2);
    } while (iVar3 != iVar2);
    if (param_1 != iVar3) {
      iVar2 = param_1 << 2;
      do {
        iVar1 = *(int *)(param_2 + iVar2);
        iVar2 = iVar1 * 4;
        *(int *)(param_2 + iVar2) = iVar3;
      } while (iVar3 != iVar1);
    }
  }
  *(int *)(param_1 * 4 + param_2) = iVar3;
  return iVar3;
}

/* FUN_00195330 @ 0x195330 (12 bytes) */
int FUN_00195330(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  *(undefined4 *)(param_2 * 4 + param_3) = param_1;
  return;
}

/* FUN_0019533c @ 0x19533c (16 bytes) */
int FUN_0019533c(param_1)
  int param_1;
{
  if (-1 < param_1) {
    return param_1;
  }
  return 3 - param_1;
}

/* FUN_0019534c @ 0x19534c (108 bytes) */
int FUN_0019534c(param_1, param_2)
  uint param_1;
  uint param_2;
{
  if (((((param_1 >> 0x18 != 3) || (param_2 >> 0x18 == 0)) &&
       (((param_1 >> 0x10 & 0xff) != 3 || ((param_2 >> 0x10 & 0xff) == 0)))) &&
      (((param_1 >> 8 & 0xff) != 3 || ((param_2 >> 8 & 0xff) == 0)))) &&
     (((param_1 & 0xff) != 3 || ((param_2 & 0xff) == 0)))) {
    return 0;
  }
  return 1;
}

/* FUN_001953b8 @ 0x1953b8 (108 bytes) */
int FUN_001953b8(param_1, param_2)
  uint param_1;
  uint param_2;
{
  if (((((2 < param_1 >> 0x18) || (param_2 >> 0x18 == 0)) &&
       ((2 < (param_1 >> 0x10 & 0xff) || ((param_2 >> 0x10 & 0xff) == 0)))) &&
      ((2 < (param_1 >> 8 & 0xff) || ((param_2 >> 8 & 0xff) == 0)))) &&
     ((2 < (param_1 & 0xff) || ((param_2 & 0xff) == 0)))) {
    return 0;
  }
  return 1;
}

