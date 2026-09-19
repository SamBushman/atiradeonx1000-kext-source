#include "decls.h"

/* FUN_00127ee4 @ 0x127ee4 (64 bytes) */
int FUN_00127ee4(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x138))(param_1,0);
  *param_2 = uVar1;
  return;
}

/* FUN_00127f24 @ 0x127f24 (180 bytes) */
int FUN_00127f24(param_1, param_2)
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
  *(undefined4 **)(param_1 + 0x60) = puVar2;
  puVar2 = (undefined4 *)FUN_000e1564(param_2,0xc);
  puVar1 = PTR_DAT_001e9100;
  puVar2[1] = 1;
  puVar2[2] = 0;
  *puVar2 = puVar1 + 8;
  *(undefined4 **)(param_1 + 100) = puVar2;
  return;
}

/* FUN_00127fd8 @ 0x127fd8 (32 bytes) */
int FUN_00127fd8(param_1)
  _Unwind_Exception *param_1;
{
  int extraout_r3;
  int unaff_r27;
  int *unaff_r30;
  
  *unaff_r30 = *(int *)((*(unsigned char *)0x000011d0) + unaff_r27) + 8;
  __Unwind_Resume(param_1);
  *(undefined4 *)(*(int *)(extraout_r3 + 8) + 0x2c) = 0x100;
  return;
}

/* FUN_00127ff8 @ 0x127ff8 (36 bytes) */
int FUN_00127ff8(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(undefined4 *)(PTR_PTR_001e910c + param_2 * 4);
}

/* FUN_0012801c @ 0x12801c (20 bytes) */
int FUN_0012801c(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  return *(int *)(param_3 + 0x138) == 1;
}

/* FUN_00128030 @ 0x128030 (28 bytes) */
int FUN_00128030()
{
  return &DAT_001dca64;
}

/* FUN_0012804c @ 0x12804c (356 bytes) */
int FUN_0012804c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  void *param_3;
{
  undefined1 *puVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  
  _memcpy((void *)(param_2 + 0x64c),param_3,0x963c);
  iVar5 = 0;
  *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(((unsigned char *)0x0000172c) + param_1);
  iVar6 = param_1 + 0x80;
  iVar8 = param_2 + 0x100;
  iVar7 = param_1;
  do {
    puVar9 = (undefined1 *)(iVar6 + 0x14);
    puVar10 = (undefined1 *)(iVar8 + 0xc);
    *(char *)(iVar8 + 8) = (char)*(undefined4 *)(iVar7 + 0x68);
    iVar11 = 4;
    *(char *)(iVar8 + 9) = (char)*(undefined4 *)(iVar7 + 0x6c);
    *(char *)(iVar8 + 10) = (char)*(undefined4 *)(iVar7 + 0x70);
    uVar4 = *(uint *)(iVar8 + 8);
    uVar3 = (*(uint *)(iVar7 + 0x78) & 0xf) << 4;
    *(uint *)(iVar8 + 8) = uVar3 | uVar4 & 0xffffff0f;
    *(uint *)(iVar8 + 8) = *(uint *)(iVar7 + 0x7c) & 1 | uVar3 | uVar4 & 0xffffff0e;
    do {
      *puVar10 = *puVar9;
      puVar1 = puVar9 + 4;
      puVar9 = puVar9 + 1;
      puVar10[4] = *puVar1;
      puVar10 = puVar10 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    bVar2 = iVar5 != 0x3f;
    iVar8 = iVar8 + 0xc;
    iVar6 = iVar6 + 0x34;
    iVar7 = iVar7 + 0x34;
    iVar5 = iVar5 + 1;
  } while (bVar2);
  iVar7 = param_2 + 0x400;
  iVar5 = 0;
  *(undefined4 *)(param_2 + 0x408) = *(undefined4 *)(((unsigned char *)0x00001728) + param_1);
  iVar6 = param_1 + 0xd80;
  do {
    puVar9 = (undefined1 *)(iVar6 + 0x14);
    puVar10 = (undefined1 *)(iVar7 + 0x10);
    *(char *)(iVar7 + 0xc) = (char)*(undefined4 *)(param_1 + 0xd68);
    iVar8 = 4;
    *(char *)(iVar7 + 0xd) = (char)*(undefined4 *)(param_1 + 0xd6c);
    *(char *)(iVar7 + 0xe) = (char)*(undefined4 *)(param_1 + 0xd70);
    uVar4 = *(uint *)(iVar7 + 0xc);
    uVar3 = (*(uint *)(param_1 + 0xd78) & 0xf) << 4;
    *(uint *)(iVar7 + 0xc) = uVar3 | uVar4 & 0xffffff0f;
    *(uint *)(iVar7 + 0xc) = *(uint *)(param_1 + 0xd7c) & 1 | uVar3 | uVar4 & 0xffffff0e;
    do {
      *puVar10 = *puVar9;
      puVar1 = puVar9 + 4;
      puVar9 = puVar9 + 1;
      puVar10[4] = *puVar1;
      puVar10 = puVar10 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    bVar2 = iVar5 != 0x2f;
    iVar7 = iVar7 + 0xc;
    iVar6 = iVar6 + 0x34;
    param_1 = param_1 + 0x34;
    iVar5 = iVar5 + 1;
  } while (bVar2);
  return 0;
}

/* FUN_001281b0 @ 0x1281b0 (56 bytes) */
int FUN_001281b0()
{
  int in_r9;
  
  if (*(int *)(in_r9 + 0x6c4) != 0) {
    FUN_000e1534(in_r9,0xf);
  }
  return 0;
}

/* FUN_001281f0 @ 0x1281f0 (344 bytes) */
int FUN_001281f0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  float *param_2;
  undefined4 *param_3;
  undefined4 param_4;
{
  float fVar1;
  float fVar2;
  bool bVar3;
  float *pfVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  char cStack00000024;
  char cStack00000025;
  char cStack00000026;
  char cStack00000027;
  
  (*(char *)(*(unsigned int *)__builtin_frame_address(0) + 0x24)) = param_4;
  bVar3 = true;
  *param_3 = 0xffffffff;
  iVar8 = 4;
  pcVar6 = &STACKARG(0x24);
  pfVar4 = param_2;
  fVar1 = FLOAT_001aa0d4;
  do {
    if (*pcVar6 != '\x04') {
      if (bVar3) {
        fVar1 = *pfVar4;
        bVar3 = false;
      }
      else if (*pfVar4 != fVar1) {
        return 0;
      }
    }
    pcVar6 = pcVar6 + 1;
    pfVar4 = pfVar4 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 4;
  fVar2 = FLOAT_001aa0d4;
  do {
    fVar2 = fVar2 + fVar1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  cStack00000024 = (char)((uint)param_4 >> 0x18);
  cStack00000025 = (char)((uint)param_4 >> 0x10);
  cStack00000026 = (char)((uint)param_4 >> 8);
  cStack00000027 = (char)param_4;
  puVar5 = &DAT_001aff0c;
  while( true ) {
    uVar7 = *puVar5;
    if (((((float)puVar5[1] == fVar2) &&
         ((cStack00000024 == '\x04' || (fVar1 == (float)puVar5[-4])))) &&
        ((cStack00000025 == '\x04' || (fVar1 == (float)puVar5[-3])))) &&
       (((cStack00000026 == '\x04' || (fVar1 == (float)puVar5[-2])) &&
        ((cStack00000027 == '\x04' || ((float)puVar5[-1] == fVar1)))))) break;
    puVar5 = puVar5 + 6;
    if (puVar5 == (undefined4 *)&UNK_001aff54) {
      return 0;
    }
  }
  iVar8 = 0;
  iVar9 = 4;
  do {
    *(float *)((int)param_2 + iVar8) = fVar1;
    iVar8 = iVar8 + 4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  *param_3 = uVar7;
  return 1;
}

/* FUN_00128348 @ 0x128348 (84 bytes) */
int FUN_00128348(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_001aff74;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
    FUN_00173e10(param_2,uVar1);
  } while (puVar2 != &DAT_001aff9c);
  return;
}

/* FUN_0012839c @ 0x12839c (128 bytes) */
int FUN_0012839c(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_001aff68;
  do {
    iVar2 = FUN_00173e10(param_2,*puVar3);
    uVar1 = *puVar3;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    puVar3 = puVar3 + 1;
    *(undefined4 *)(iVar2 + 0x14) = uVar1;
    *(undefined1 *)(iVar2 + 8) = 1;
    *(undefined1 *)(iVar2 + 9) = 0;
    *(undefined4 *)(iVar2 + 0x18) = 0;
    FUN_0017629c(iVar2,param_2);
  } while (puVar3 != &DAT_001aff74);
  return;
}

/* FUN_00128430 @ 0x128430 (780 bytes) */
int FUN_00128430(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  float *param_3;
  int *param_4;
{
  float fVar1;
  bool bVar2;
  int *piVar3;
  float *pfVar4;
  bool bVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  float local_b8 [26];
  float local_50;
  
  if (*param_4 != DAT_001affa0) {
    iVar7 = 4;
    bVar2 = true;
    bVar5 = true;
    piVar3 = param_4;
    pfVar4 = param_3;
    fVar1 = FLOAT_001aa0d4;
    do {
      if (*(char *)piVar3 != '\x04') {
        if (bVar2) {
          fVar1 = *pfVar4;
          bVar2 = false;
        }
        else if (*pfVar4 != fVar1) {
          bVar5 = false;
        }
      }
      piVar3 = (int *)((int)piVar3 + 1);
      pfVar4 = pfVar4 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    if (bVar5) {
      iVar7 = 4;
      pfVar4 = local_b8;
      do {
        *pfVar4 = NAN;
        pfVar4 = pfVar4 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar7 = 0;
      iVar8 = 4;
      do {
        local_50 = fVar1;
        *(float *)(iVar7 + (int)local_b8) = fVar1;
        iVar7 = iVar7 + 4;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      iVar7 = FUN_000f6a04(param_2,local_b8,DAT_001aff9c);
    }
    else {
      iVar7 = FUN_000f6a04(param_2,param_3,*param_4);
    }
    if (iVar7 != 0) {
      return iVar7;
    }
    uVar6 = *(undefined4 *)(param_2 + 0x3ac);
    iVar7 = FUN_000f5f94(uVar6,param_3,param_4);
    if (iVar7 != 0) {
      return iVar7;
    }
    if ((((((*(uint *)(param_2 + 0x30) & 0x100) != 0) && (*param_3 == FLOAT_001aa0d4)) &&
         (param_3[1] == FLOAT_001aa0e8)) &&
        ((param_3[2] == FLOAT_001aa0d4 && (param_3[3] == FLOAT_001aa0d4)))) &&
       (*param_4 == DAT_001aff9c)) {
      FUN_000f4a24(param_3,local_b8);
      iVar7 = FUN_000f5248(uVar6);
      return iVar7;
    }
    iVar7 = FUN_000f57f0(uVar6,param_3,param_4);
    if ((iVar7 != 0) && (iVar8 = (**(code **)(*param_1 + 0x100))(param_1,param_4), iVar8 != 0)) {
      return iVar7;
    }
  }
  return 0;
}

/* FUN_0012873c @ 0x12873c (500 bytes) */
int FUN_0012873c(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int *param_2;
  int param_3;
  uint param_4;
  int param_5;
{
  uint uVar1;
  float *pfVar2;
  int iVar3;
  float local_64 [4];
  float local_54 [9];
  float local_30;
  
  iVar3 = 4;
  pfVar2 = local_64;
  do {
    *pfVar2 = NAN;
    pfVar2 = pfVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 4;
  pfVar2 = local_54;
  do {
    *pfVar2 = NAN;
    pfVar2 = pfVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar1 = param_4 << 0x18 | (param_4 & 0xff00) << 8 | param_4 >> 8 & 0xff00 | param_4 >> 0x18;
  pfVar2 = (float *)&DAT_001aff08;
  while( true ) {
    local_64[1] = pfVar2[-2];
    local_64[0] = pfVar2[-3];
    local_64[2] = pfVar2[-1];
    local_54[0] = -local_64[0];
    local_64[3] = *pfVar2;
    local_54[1] = -local_64[1];
    local_54[2] = -local_64[2];
    local_54[3] = -local_64[3];
    local_30 = local_54[3];
    iVar3 = FUN_000f5c0c(param_2,param_3,uVar1,local_64);
    if (iVar3 != 0) {
      FUN_000f79c4((double)local_64[0],(double)local_64[1],(double)local_64[2],(double)local_64[3],
                   param_2,*(undefined4 *)(param_5 + 0x6c4),param_3);
      return 1;
    }
    iVar3 = (**(code **)(*param_2 + 0x8c))(param_2);
    if ((iVar3 != 0) && (iVar3 = FUN_000f5c0c(param_2,param_3,uVar1,local_54), iVar3 != 0)) break;
    pfVar2 = pfVar2 + 6;
    if (pfVar2 == (float *)&DAT_001aff50) {
      return 0;
    }
  }
  FUN_000f79c4((double)local_64[0],(double)local_64[1],(double)local_64[2],(double)local_64[3],
               param_2,*(undefined4 *)(param_5 + 0x6c4),param_3);
  if ((param_2[param_3 * 6 + 0x28] & 2U) != 0) {
    return 1;
  }
  FUN_00103d50(param_2 + param_3 * 6 + 0x23,1,param_2[param_3 * 6 + 0x28] & 1U ^ 1);
  return 1;
}

/* FUN_00128930 @ 0x128930 (420 bytes) */
int FUN_00128930(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uStack00000030;
  int in_stack_0000003c;
  
  uVar5 = *(undefined4 *)(in_stack_0000003c + 0x6c4);
  iVar4 = *(int *)(PTR_DAT_001e8b84 + param_2 * 4);
  uStack00000030 = param_7;
  iVar1 = FUN_001043f0(0x8b,in_stack_0000003c);
  uVar2 = FUN_000ec208(uVar5,param_4);
  iVar3 = FUN_001054ec(iVar1,1);
  *(undefined4 *)(iVar3 + 0xc) = uVar2;
  *(int *)(iVar3 + 8) = param_3;
  uVar2 = FUN_000ec208(uVar5,param_6);
  iVar3 = FUN_001054ec(iVar1,2);
  *(undefined4 *)(iVar3 + 0xc) = uVar2;
  *(int *)(iVar3 + 8) = param_5;
  FUN_000f8aa0(uVar5,&STACKARG(0x30),**(undefined4 **)(param_8 + 0x6c),1,iVar1);
  FUN_000f8aa0(uVar5,&STACKARG(0x30),*(undefined4 *)(*(int *)(param_8 + 0x6c) + 4),2,iVar1);
  if ((param_3 == param_5) && (param_4 == param_6)) {
    if ((*(uint *)(iVar1 + 0xb8) & 1) != (*(uint *)(iVar1 + 0xd0) & 1)) {
      if (((*(uint *)(iVar1 + 0xb8) & 2) == 0) && ((*(uint *)(iVar1 + 0xd0) & 2) == 0)) {
        iVar3 = FUN_001054ec(iVar1,1);
        iVar6 = *(int *)(iVar3 + 0x10);
        iVar3 = FUN_001054ec(iVar1,2);
        if (iVar6 == *(int *)(iVar3 + 0x10)) {
          if ((*(uint *)(iVar1 + 0xb8) & 1) != 0) {
            FUN_00103d50(iVar1 + 0xa4,1,0);
            iVar4 = *(int *)(PTR_DAT_001e90f8 + iVar4 * 4);
          }
          FUN_000f7870(iVar1,uVar5,2,0,0,0,0);
        }
      }
    }
  }
  *(int *)(iVar1 + 300) = iVar4;
  return iVar1;
}

/* FUN_00128ad8 @ 0x128ad8 (676 bytes) */
int FUN_00128ad8(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  byte in_cr7;
  double dVar10;
  
  if ((bool)(in_cr7 >> 1 & 1)) {
    iVar6 = *(int *)(param_3 + 0x6c4);
    iVar2 = FUN_00127534(*(undefined4 *)(iVar6 + 0x3ac),0x1b,0,0);
    if (iVar2 != 0) {
      FUN_001041d0(*(undefined4 *)(iVar2 + 0x38),3,3,8,0);
      uVar3 = *(undefined4 *)(iVar6 + 0x3ac);
      iVar5 = *(int *)(param_3 + 0x3ac) + -1;
      *(int *)(param_3 + 0x3ac) = iVar5;
      iVar7 = 0;
      uVar3 = FUN_001275a0(uVar3,0,iVar5,0);
      for (uVar8 = 1; uVar8 <= *(uint *)(*(int *)(iVar2 + 0x14) + 4); uVar8 = uVar8 + 1) {
        iVar5 = *(int *)(iVar7 + *(int *)(*(int *)(iVar2 + 0x14) + 8));
        if (((*(uint *)(iVar5 + 0x14) & 1) != 0) && (iVar9 = 1, 0 < *(int *)(iVar5 + 0x84))) {
          do {
            if (*(int *)(iVar9 * 0x18 + iVar5 + 0x98) == 0x1b) {
              FUN_001046c8(iVar5,iVar9,uVar3);
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 <= *(int *)(iVar5 + 0x84));
        }
        iVar7 = iVar7 + 4;
      }
      iVar5 = FUN_000d9f3c(*(undefined4 *)(param_3 + 0x398),0);
      if (iVar5 == 0) {
        piVar4 = (int *)FUN_001043f0(0x14,param_3);
        FUN_001046c8(piVar4,0,uVar3);
        FUN_001046c8(piVar4,1,iVar2);
        uVar1 = DAT_001aff48;
        iVar5 = FUN_001054ec(piVar4,1);
        dVar10 = (double)FLOAT_001aa108;
        *(undefined4 *)(iVar5 + 0x10) = uVar1;
        FUN_000f79c4(dVar10,dVar10,dVar10,dVar10,piVar4,*(undefined4 *)(param_3 + 0x6c4),2);
        FUN_00103d50(piVar4 + 0x2f,1,1);
        dVar10 = (double)FLOAT_001aa0e8;
        FUN_000f79c4(dVar10,dVar10,dVar10,dVar10,piVar4,*(undefined4 *)(param_3 + 0x6c4),3);
        FUN_001236e4(iVar2,1,piVar4);
        FUN_0012306c(uVar3,piVar4);
        FUN_000e7688(*(undefined4 *)(iVar6 + 0x3a0),piVar4);
        (**(code **)(*piVar4 + 8))(piVar4,param_3);
      }
      else {
        piVar4 = (int *)FUN_001043f0(0x31,param_3);
        FUN_001046c8(piVar4,0,uVar3);
        FUN_001046c8(piVar4,1,iVar2);
        uVar1 = DAT_001affa4;
        iVar5 = FUN_001054ec(piVar4,1);
        *(undefined4 *)(iVar5 + 0x10) = uVar1;
        FUN_001236e4(iVar2,1,piVar4);
        FUN_0012306c(uVar3,piVar4);
        FUN_000e7688(*(undefined4 *)(iVar6 + 0x3a0),piVar4);
        (**(code **)(*piVar4 + 8))(piVar4,param_3);
      }
    }
  }
  return;
}

/* FUN_00128d7c @ 0x128d7c (596 bytes) */
int FUN_00128d7c(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  undefined4 param_3;
{
  bool bVar1;
  float fVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  
  if (*(char *)(param_2 + 2) == '\0') {
    return;
  }
  bVar3 = *(byte *)((int)param_2 + 9);
  if ((bVar3 & 1) != 0) {
    return;
  }
  if ((bVar3 & 2) != 0) {
    return;
  }
  if ((bVar3 & 4) != 0) {
    return;
  }
  if ((bVar3 & 8) != 0) {
    return;
  }
  iVar4 = FUN_00173e10(param_3,-param_2[5]);
  if (*(char *)(iVar4 + 8) == '\0') {
    bVar3 = *(byte *)(iVar4 + 9);
  }
  else {
    bVar3 = *(byte *)(iVar4 + 9);
    if (((((bVar3 & 1) == 0) && ((bVar3 & 2) == 0)) && ((bVar3 & 4) == 0)) && ((bVar3 & 8) == 0))
    goto LAB_00128e28;
  }
  if (((bVar3 & 1) == 0) || ((bVar3 & 2) != 0)) {
    *(undefined4 *)(iVar4 + 0x20) = 0x31;
    FUN_00176280(iVar4,param_2);
    fVar2 = param_2[5];
    *(undefined1 *)(iVar4 + 9) = 1;
    *(float *)(iVar4 + 0x14) = fVar2;
    *(undefined4 *)(iVar4 + 0x1c) = 0;
    *(undefined4 *)(iVar4 + 0x18) = 1;
  }
LAB_00128e28:
  iVar4 = -3;
  pfVar6 = (float *)&DAT_001aff4c;
  do {
    iVar5 = FUN_00173e10(param_3,*param_2 * *pfVar6);
    if (*(char *)(iVar5 + 8) == '\0') {
      bVar3 = *(byte *)(iVar5 + 9);
LAB_00128e98:
      if ((((bVar3 & 1) == 0) || ((bVar3 & 2) != 0)) && (((bVar3 & 2) == 0 || ((bVar3 & 1) != 0))))
      {
        *(undefined4 *)(iVar5 + 0x20) = 0x31;
        FUN_00176280(iVar5,param_2);
        fVar2 = param_2[5];
        *(int *)(iVar5 + 0x1c) = iVar4;
        *(undefined1 *)(iVar5 + 9) = 2;
        *(float *)(iVar5 + 0x14) = fVar2;
        *(undefined4 *)(iVar5 + 0x18) = 0;
      }
    }
    else {
      bVar3 = *(byte *)(iVar5 + 9);
      if ((((bVar3 & 1) != 0) || ((bVar3 & 2) != 0)) || (((bVar3 & 4) != 0 || ((bVar3 & 8) != 0))))
      goto LAB_00128e98;
    }
    bVar1 = iVar4 == 3;
    pfVar6 = pfVar6 + 1;
    iVar4 = iVar4 + 1;
    if (bVar1) {
      pfVar6 = (float *)&DAT_001aff4c;
      iVar4 = -3;
      do {
        iVar5 = FUN_00173e10(param_3,-*param_2 * *pfVar6);
        if (*(char *)(iVar5 + 8) == '\0') {
          *(undefined4 *)(iVar5 + 0x20) = 0x31;
          FUN_00176280(iVar5,param_2);
          fVar2 = param_2[5];
          *(undefined1 *)(iVar5 + 9) = 3;
          *(float *)(iVar5 + 0x14) = fVar2;
          *(undefined4 *)(iVar5 + 0x18) = 1;
          *(int *)(iVar5 + 0x1c) = iVar4;
        }
        bVar1 = iVar4 != 3;
        pfVar6 = pfVar6 + 1;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      return;
    }
  } while( true );
}

/* FUN_00128fd0 @ 0x128fd0 (332 bytes) */
int FUN_00128fd0(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  FUN_0010dad8();
  param_1[7] = 0;
  puVar1 = PTR_DAT_001e9104;
  param_1[0xe] = 9;
  param_1[0x10] = 0x60;
  param_1[1] = puVar1;
  param_1[0x15] = 4;
  *param_1 = &PTR_FUN_001ead88;
  param_1[8] = 0x7fffffff;
  param_1[0xf] = 0x10;
  param_1[0x14] = 0x20;
  param_1[0x16] = 0xfffffffd;
  param_1[0x17] = 3;
  param_1[0xb] = 0x20;
  param_1[10] = 0x10;
  FUN_0010dc20(param_1);
  FUN_0010dbd8(param_1,0x30);
  FUN_0010dbd8(param_1,0x31);
  FUN_0010dbd8(param_1,0x36);
  FUN_0010dbd8(param_1,0x39);
  FUN_0010dbd8(param_1,0x3b);
  FUN_0010dbd8(param_1,0x3c);
  FUN_0010dbd8(param_1,0x40);
  FUN_0010dbd8(param_1,0x41);
  FUN_0010dbd8(param_1,0x42);
  param_1[2] = param_1[2] | 0x20000;
  ((int (*)())FUN_0012aa58)(param_1);
  if (param_3 != 0) {
    ((int (*)())FUN_00127f24)(param_1,param_2);
  }
  return;
}

/* FUN_00129130 @ 0x129130 (332 bytes) */
int FUN_00129130(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  FUN_0010dad8();
  param_1[7] = 0;
  puVar1 = PTR_DAT_001e9104;
  param_1[0xe] = 9;
  param_1[0x10] = 0x60;
  param_1[1] = puVar1;
  param_1[0x15] = 4;
  *param_1 = &PTR_FUN_001ead88;
  param_1[8] = 0x7fffffff;
  param_1[0xf] = 0x10;
  param_1[0x14] = 0x20;
  param_1[0x16] = 0xfffffffd;
  param_1[0x17] = 3;
  param_1[0xb] = 0x20;
  param_1[10] = 0x10;
  FUN_0010dc20(param_1);
  FUN_0010dbd8(param_1,0x30);
  FUN_0010dbd8(param_1,0x31);
  FUN_0010dbd8(param_1,0x36);
  FUN_0010dbd8(param_1,0x39);
  FUN_0010dbd8(param_1,0x3b);
  FUN_0010dbd8(param_1,0x3c);
  FUN_0010dbd8(param_1,0x40);
  FUN_0010dbd8(param_1,0x41);
  FUN_0010dbd8(param_1,0x42);
  param_1[2] = param_1[2] | 0x20000;
  ((int (*)())FUN_0012aa58)(param_1);
  if (param_3 != 0) {
    ((int (*)())FUN_00127f24)(param_1,param_2);
  }
  return;
}

/* FUN_00129290 @ 0x129290 (176 bytes) */
int FUN_00129290(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  puVar2 = (undefined4 *)FUN_000e1564(param_2,0x3c);
  puVar1 = PTR_DAT_001e9110;
  puVar3 = PTR_DAT_001e90fc + 8;
  puVar2[2] = param_2;
  *puVar2 = puVar3;
  puVar2[1] = 0;
  *puVar2 = puVar1 + 8;
  FUN_0018f824();
  FUN_00172000(puVar2);
  puVar2[0xe] = 0;
  *(undefined4 **)(param_1 + 0x60) = puVar2;
  puVar2 = (undefined4 *)FUN_000e1564(param_2,0xc);
  puVar1 = PTR_DAT_001e9100;
  puVar2[1] = 1;
  puVar2[2] = 0;
  *puVar2 = puVar1 + 8;
  *(undefined4 **)(param_1 + 100) = puVar2;
  return;
}

/* FUN_00129350 @ 0x129350 (96 bytes) */
int FUN_00129350(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x138))(param_1,0);
  *param_2 = uVar1;
  uVar1 = (**(code **)(*param_1 + 0x140))(param_1,0);
  param_2[1] = uVar1;
  return;
}

/* FUN_001293b0 @ 0x1293b0 (72 bytes) */
int FUN_001293b0(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  
  *param_2 = 0;
  uVar1 = (**(code **)(*param_1 + 0x138))(param_1,0);
  param_2[1] = uVar1;
  return;
}

/* FUN_001293f8 @ 0x1293f8 (8 bytes) */
int FUN_001293f8()
{
  return 0x14;
}

/* FUN_00129408 @ 0x129408 (60 bytes) */
undefined4 FUN_00129408(double param_1)

{
  if ((param_1 != (double)FLOAT_001aa0d4) && (param_1 != (double)FLOAT_001aa0e8)) {
    return 0;
  }
  return 1;
}

/* FUN_00129444 @ 0x129444 (4 bytes) */
int FUN_00129444()
{
  return;
}

/* FUN_00129448 @ 0x129448 (48 bytes) */
int FUN_00129448(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  return *(byte *)(param_2 * 0xc +
                   *(int *)(*(int *)(*(int *)(param_3 + 8) + 0x52c) * 4 + *(int *)(param_3 + 8) +
                           0x524) + 0x10a) == param_2;
}

/* FUN_00129478 @ 0x129478 (504 bytes) */
int FUN_00129478(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined1 *puVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined1 *puVar12;
  
  _memcpy(*(void **)(param_2 + 0x650),(void *)param_3[1],*param_3 << 4);
  _memcpy(*(void **)(param_2 + 0x654),(void *)param_3[2],900);
  iVar4 = param_3[3];
  iVar7 = param_3[4];
  iVar11 = param_3[5];
  iVar8 = param_3[6];
  iVar6 = param_3[7];
  iVar5 = param_3[8];
  *(int *)(param_2 + 0x670) = param_3[9];
  *(int *)(param_2 + 0x658) = iVar4;
  *(int *)(param_2 + 0x65c) = iVar7;
  *(int *)(param_2 + 0x660) = iVar11;
  *(int *)(param_2 + 0x664) = iVar8;
  *(int *)(param_2 + 0x668) = iVar6;
  *(int *)(param_2 + 0x66c) = iVar5;
  iVar4 = *(int *)(((unsigned char *)0x0000172c) + param_1);
  *(int *)(param_2 + 0x104) = iVar4;
  if (iVar4 != 0) {
    uVar9 = 0;
    iVar4 = param_1;
    do {
      uVar9 = uVar9 + 1;
      iVar5 = *(int *)(iVar4 + 0x70) * 0xc + param_2;
      *(uint *)(iVar4 + 0x68) = (uint)*(byte *)(iVar5 + 0x108);
      *(uint *)(iVar4 + 0x6c) = (uint)*(byte *)(iVar5 + 0x109);
      iVar4 = iVar4 + 0x34;
    } while (uVar9 < *(uint *)(param_2 + 0x104));
  }
  iVar5 = 0;
  iVar6 = param_1 + 0x80;
  iVar7 = param_2 + 0x100;
  iVar4 = param_1;
  do {
    puVar10 = (undefined1 *)(iVar6 + 0x14);
    puVar12 = (undefined1 *)(iVar7 + 0xc);
    *(char *)(iVar7 + 8) = (char)*(undefined4 *)(iVar4 + 0x68);
    iVar8 = 4;
    *(char *)(iVar7 + 9) = (char)*(undefined4 *)(iVar4 + 0x6c);
    *(char *)(iVar7 + 10) = (char)*(undefined4 *)(iVar4 + 0x70);
    uVar3 = *(uint *)(iVar7 + 8);
    uVar9 = (*(uint *)(iVar4 + 0x78) & 0xf) << 4;
    *(uint *)(iVar7 + 8) = uVar9 | uVar3 & 0xffffff0f;
    *(uint *)(iVar7 + 8) = *(uint *)(iVar4 + 0x7c) & 1 | uVar9 | uVar3 & 0xffffff0e;
    do {
      *puVar12 = *puVar10;
      puVar1 = puVar10 + 4;
      puVar10 = puVar10 + 1;
      puVar12[4] = *puVar1;
      puVar12 = puVar12 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    bVar2 = iVar5 != 0x3f;
    iVar7 = iVar7 + 0xc;
    iVar6 = iVar6 + 0x34;
    iVar4 = iVar4 + 0x34;
    iVar5 = iVar5 + 1;
  } while (bVar2);
  iVar4 = param_2 + 0x400;
  iVar5 = 0;
  *(undefined4 *)(param_2 + 0x408) = *(undefined4 *)(((unsigned char *)0x00001728) + param_1);
  iVar6 = param_1 + 0xd80;
  do {
    puVar10 = (undefined1 *)(iVar6 + 0x14);
    puVar12 = (undefined1 *)(iVar4 + 0x10);
    *(char *)(iVar4 + 0xc) = (char)*(undefined4 *)(param_1 + 0xd68);
    iVar7 = 4;
    *(char *)(iVar4 + 0xd) = (char)*(undefined4 *)(param_1 + 0xd6c);
    *(char *)(iVar4 + 0xe) = (char)*(undefined4 *)(param_1 + 0xd70);
    uVar3 = *(uint *)(iVar4 + 0xc);
    uVar9 = (*(uint *)(param_1 + 0xd78) & 0xf) << 4;
    *(uint *)(iVar4 + 0xc) = uVar9 | uVar3 & 0xffffff0f;
    *(uint *)(iVar4 + 0xc) = *(uint *)(param_1 + 0xd7c) & 1 | uVar9 | uVar3 & 0xffffff0e;
    do {
      *puVar12 = *puVar10;
      puVar1 = puVar10 + 4;
      puVar10 = puVar10 + 1;
      puVar12[4] = *puVar1;
      puVar12 = puVar12 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    bVar2 = iVar5 != 0x2f;
    iVar4 = iVar4 + 0xc;
    iVar6 = iVar6 + 0x34;
    param_1 = param_1 + 0x34;
    iVar5 = iVar5 + 1;
  } while (bVar2);
  return 0;
}

/* FUN_00129678 @ 0x129678 (28 bytes) */
int FUN_00129678()
{
  return &DAT_001df1fc;
}

/* FUN_00129694 @ 0x129694 (56 bytes) */
int FUN_00129694()
{
  int in_r9;
  
  if (*(int *)(in_r9 + 0x6c4) != 0) {
    FUN_000e1534(in_r9,0xf);
  }
  return 0;
}

/* FUN_001296cc @ 0x1296cc (124 bytes) */
int FUN_001296cc(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 *param_2;
  undefined1 *param_3;
  undefined4 param_4;
  undefined4 param_5;
  uint param_6;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = *(int *)(((unsigned char *)0x00001728) + param_1);
  *(int *)(((unsigned char *)0x00001728) + param_1) = iVar1 + 1;
  uVar2 = 0;
  param_1 = param_1 + iVar1 * 0x34 + 0xd60;
  iVar1 = param_1 + 8;
  *(undefined4 *)(param_1 + 8) = param_4;
  *(undefined4 *)(param_1 + 0x24) = 1;
  *(undefined4 *)(param_1 + 0x1c) = 1;
  iVar3 = 4;
  *(undefined4 *)(param_1 + 0x10) = param_5;
  *(undefined4 *)(param_1 + 0xc) = param_5;
  *(uint *)(param_1 + 0x18) = param_6;
  do {
    if ((param_6 & 1 << (uVar2 & 0x3f)) != 0) {
      *(char *)(iVar1 + 0x2c) = (char)*param_2;
      *(undefined1 *)(iVar1 + 0x30) = *param_3;
    }
    uVar2 = uVar2 + 1;
    param_2 = param_2 + 1;
    iVar1 = iVar1 + 1;
    param_3 = param_3 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* FUN_00129748 @ 0x129748 (156 bytes) */
int FUN_00129748(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  int iVar1;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  
  iVar1 = *(int *)(((unsigned char *)0x00001728) + param_1);
  *(int *)(((unsigned char *)0x00001728) + param_1) = iVar1 + 1;
  param_1 = param_1 + iVar1 * 0x34 + 0xd60;
  *(int *)(param_1 + 8) = param_3;
  *(undefined4 *)(param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  *(undefined1 *)(param_1 + 0x37) = param_2;
  *(undefined1 *)(param_1 + 0x34) = param_2;
  *(undefined1 *)(param_1 + 0x35) = param_2;
  *(undefined1 *)(param_1 + 0x36) = param_2;
  if (param_3 == 4) {
    *(undefined1 *)(param_1 + 0x3b) = 3;
    *(undefined1 *)(param_1 + 0x38) = 3;
    *(undefined1 *)(param_1 + 0x39) = 3;
    *(undefined1 *)(param_1 + 0x3a) = 3;
  }
  else {
    *(char *)(param_1 + 0x38) = (char)((uint)param_5 >> 0x18);
    *(char *)(param_1 + 0x39) = (char)((uint)param_5 >> 0x10);
    *(char *)(param_1 + 0x3a) = (char)((uint)param_5 >> 8);
    *(char *)(param_1 + 0x3b) = (char)param_5;
  }
  *(undefined4 *)(param_1 + 0x10) = in_stack_0000003c;
  *(uint *)(param_1 + 0x24) = (uint)(param_6 == 0);
  *(undefined4 *)(param_1 + 0x18) = in_stack_00000038;
  return;
}

/* FUN_001297e4 @ 0x1297e4 (112 bytes) */
int FUN_001297e4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = *(int *)(((unsigned char *)0x0000172c) + param_1);
  *(int *)(((unsigned char *)0x0000172c) + param_1) = iVar1 + 1;
  param_1 = param_1 + iVar1 * 0x34 + 0x60;
  *(undefined4 *)(param_1 + 8) = 5;
  *(undefined1 *)(param_1 + 0x38) = 0;
  *(undefined1 *)(param_1 + 0x3a) = 2;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined1 *)(param_1 + 0x37) = param_3;
  *(undefined1 *)(param_1 + 0x39) = 1;
  *(undefined1 *)(param_1 + 0x3b) = 3;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined1 *)(param_1 + 0x34) = param_3;
  *(undefined1 *)(param_1 + 0x35) = param_3;
  *(undefined1 *)(param_1 + 0x36) = param_3;
  return;
}

/* FUN_00129854 @ 0x129854 (312 bytes) */
int FUN_00129854(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  float *param_2;
  int *param_3;
  undefined4 param_4;
{
  float fVar1;
  int *piVar2;
  float *pfVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  undefined4 uStack00000024;
  int local_38 [4];
  longlong local_28;
  undefined4 local_20;
  
  pcVar5 = (char *)&STACKARG(0x24);
  uStack00000024 = param_4;
  *param_3 = -1;
  iVar7 = 4;
  pfVar3 = param_2;
  pcVar6 = pcVar5;
  while ((((*pcVar6 == '\x04' || (fVar1 = *pfVar3, fVar1 == FLOAT_001aa0d4)) ||
          (fVar1 == FLOAT_001aa0e8)) || (local_20 = 0xbf800000, fVar1 == -1.0))) {
    pcVar6 = pcVar6 + 1;
    pfVar3 = pfVar3 + 1;
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) {
      iVar7 = (int)pcVar6 - (int)pcVar5;
      pfVar3 = param_2;
      do {
        if (*pcVar5 == '\x04') {
          *pfVar3 = 0.0;
        }
        local_38[3] = DAT_001affcc;
        local_38[2] = DAT_001affc8;
        pcVar5 = pcVar5 + 1;
        pfVar3 = pfVar3 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar7 = 0;
      iVar4 = 0;
      local_38[1] = DAT_001affc4;
      local_38[0] = DAT_001affc0;
      iVar8 = 4;
      *param_3 = 0;
      do {
        fVar1 = *param_2;
        param_2 = param_2 + 1;
        local_28 = (longlong)(int)fVar1;
        piVar2 = (int *)((int)local_38 + iVar4);
        iVar4 = iVar4 + 4;
        iVar7 = (int)fVar1 * *piVar2 + iVar7;
        *param_3 = iVar7;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      return 1;
    }
  }
  return 0;
}

/* FUN_0012998c @ 0x12998c (128 bytes) */
int FUN_0012998c(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_001affb0;
  do {
    iVar2 = FUN_00173e10(param_2,*puVar3);
    uVar1 = *puVar3;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    puVar3 = puVar3 + 1;
    *(undefined4 *)(iVar2 + 0x14) = uVar1;
    *(undefined1 *)(iVar2 + 8) = 1;
    *(undefined1 *)(iVar2 + 9) = 0;
    *(undefined4 *)(iVar2 + 0x18) = 0;
    FUN_0017629c(iVar2,param_2);
  } while (puVar3 != &DAT_001affb8);
  return;
}

/* FUN_00129a0c @ 0x129a0c (316 bytes) */
int FUN_00129a0c(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
  int param_5;
{
  char cVar1;
  float fVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  float *pfVar7;
  int iVar8;
  uint local_58;
  undefined4 local_54;
  float local_50 [8];
  undefined4 local_30;
  
  local_58 = param_4 << 0x18 | (param_4 & 0xff00) << 8 | param_4 >> 8 & 0xff00 | param_4 >> 0x18;
  piVar4 = (int *)FUN_00105594(param_2,param_3);
  iVar5 = (**(code **)(*piVar4 + 0x48))();
  if (iVar5 == 0) {
LAB_00129b30:
    uVar6 = 0;
  }
  else {
    iVar5 = FUN_001054ec(param_2,param_3);
    iVar8 = 0;
    local_54 = *(undefined4 *)(iVar5 + 0x10);
    iVar5 = 4;
    pfVar7 = local_50;
    do {
      cVar1 = *(char *)((int)&local_58 + iVar8);
      *pfVar7 = FLOAT_001aa0d4;
      if (cVar1 == '\0') {
        uVar3 = (uint)*(byte *)((int)local_50 + iVar8 + -4);
        if ((((int)*(char *)(piVar4 + 0x57) >> (uVar3 & 0x3f) & 1U) == 0) ||
           (((fVar2 = (float)piVar4[uVar3 * 6 + 8], fVar2 != FLOAT_001aa0d4 &&
             (fVar2 != FLOAT_001aa0e8)) && (local_30 = 0xbf800000, fVar2 != -1.0))))
        goto LAB_00129b30;
        *pfVar7 = fVar2;
      }
      iVar8 = iVar8 + 1;
      pfVar7 = pfVar7 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_000f79c4((double)local_50[0],(double)local_50[1],(double)local_50[2],(double)local_50[3],
                 param_2,*(undefined4 *)(param_5 + 0x6c4),param_3);
    uVar6 = 1;
  }
  return uVar6;
}

/* FUN_00129b48 @ 0x129b48 (632 bytes) */
int FUN_00129b48(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  int *param_2;
  int param_3;
  int *param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int local_58 [10];
  
  iVar3 = 0;
  do {
    bVar1 = iVar3 != 8;
    *(undefined4 *)(iVar3 + (int)local_58) = 0xffffffff;
    *(undefined4 *)(iVar3 + (int)(local_58 + 3)) = 0xffffffff;
    iVar3 = iVar3 + 4;
  } while (bVar1);
  iVar7 = 0;
  iVar3 = 0;
  iVar10 = 1;
  piVar8 = param_2;
  do {
    iVar6 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar6 < iVar10) {
      return 1;
    }
    if ((*(uint *)(*(int *)(param_7 + 0x6c4) + 0x30) & 8) == 0) {
      if (iVar10 == param_3) {
        iVar9 = param_4[0x26];
        iVar6 = *(int *)(param_4[0x23] + 8);
      }
      else {
        iVar6 = piVar8[0x2b];
        iVar9 = piVar8[0x2c];
      }
LAB_00129cc4:
      switch(iVar9) {
      case 2:
      case 0xc:
      case 0x26:
      case 0x28:
        iVar9 = 0;
        piVar4 = local_58;
        while( true ) {
          iVar2 = *piVar4;
          piVar4 = piVar4 + 1;
          if (iVar2 == -1) break;
          if ((iVar6 == iVar2) || (bVar1 = iVar9 == 2, iVar9 = iVar9 + 1, bVar1))
          goto switchD_00129ce4_caseD_0;
        }
        iVar7 = iVar7 + 1;
        local_58[iVar9] = iVar6;
        break;
      case 0x29:
      case 0x37:
        iVar9 = 0;
        piVar4 = local_58 + 3;
        while( true ) {
          iVar2 = *piVar4;
          piVar4 = piVar4 + 1;
          if (iVar2 == -1) break;
          if ((iVar6 == iVar2) || (bVar1 = iVar9 == 2, iVar9 = iVar9 + 1, bVar1))
          goto switchD_00129ce4_caseD_0;
        }
        iVar3 = iVar3 + 1;
        local_58[iVar9 + 3] = iVar6;
      }
    }
    else {
      if (iVar10 == param_3) {
        iVar6 = (**(code **)(*param_4 + 0x60))(param_4);
        if (iVar6 == 0) {
          iVar6 = param_4[0x25];
          iVar9 = param_4[0x26];
        }
        else {
          iVar6 = FUN_00105594(param_4,1);
          iVar9 = *(int *)(iVar6 + 0x98);
          iVar6 = FUN_00105594(param_4,1);
          iVar6 = *(int *)(iVar6 + 0x94);
        }
        goto LAB_00129cc4;
      }
      iVar6 = FUN_00105594(param_2,iVar10);
      if (iVar6 != 0) {
        piVar4 = (int *)FUN_00105594(param_2,iVar10);
        iVar6 = (**(code **)(*piVar4 + 0x60))();
        if (iVar6 == 0) {
          iVar6 = FUN_00105594(param_2,iVar10);
          iVar9 = *(int *)(iVar6 + 0x98);
          iVar6 = FUN_00105594(param_2,iVar10);
          iVar6 = *(int *)(iVar6 + 0x94);
        }
        else {
          uVar5 = FUN_00105594(param_2,iVar10);
          iVar6 = FUN_00105594(uVar5,1);
          iVar9 = *(int *)(iVar6 + 0x98);
          uVar5 = FUN_00105594(param_2,iVar10);
          iVar6 = FUN_00105594(uVar5,1);
          iVar6 = *(int *)(iVar6 + 0x94);
        }
        goto LAB_00129cc4;
      }
    }
switchD_00129ce4_caseD_0:
    if ((1 < iVar7) || (piVar8 = piVar8 + 6, 1 < iVar3)) {
      return 0;
    }
    iVar10 = iVar10 + 1;
  } while( true );
}

/* FUN_00129eb4 @ 0x129eb4 (344 bytes) */
int FUN_00129eb4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  float *param_3;
  int *param_4;
{
  float fVar1;
  bool bVar2;
  int *piVar3;
  float *pfVar4;
  bool bVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  float local_38 [6];
  float local_20;
  
  if (*param_4 != DAT_001affbc) {
    iVar7 = 4;
    bVar2 = true;
    bVar5 = true;
    piVar3 = param_4;
    pfVar4 = param_3;
    fVar1 = FLOAT_001aa0d4;
    do {
      if (*(char *)piVar3 != '\x04') {
        if (bVar2) {
          fVar1 = *pfVar4;
          bVar2 = false;
        }
        else if (*pfVar4 != fVar1) {
          bVar5 = false;
        }
      }
      piVar3 = (int *)((int)piVar3 + 1);
      pfVar4 = pfVar4 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    if (bVar5) {
      iVar7 = 4;
      pfVar4 = local_38;
      do {
        *pfVar4 = NAN;
        pfVar4 = pfVar4 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar7 = 0;
      iVar8 = 4;
      do {
        local_20 = fVar1;
        *(float *)(iVar7 + (int)local_38) = fVar1;
        iVar7 = iVar7 + 4;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      iVar7 = FUN_000f6a04(param_2,local_38,DAT_001affb8);
    }
    else {
      iVar7 = FUN_000f6a04(param_2,param_3,*param_4);
    }
    if (iVar7 != 0) {
      return iVar7;
    }
    uVar6 = *(undefined4 *)(param_2 + 0x3ac);
    iVar7 = FUN_000f5f94(uVar6,param_3,param_4);
    if (iVar7 != 0) {
      return iVar7;
    }
    iVar7 = FUN_000f57f0(uVar6,param_3,param_4);
    if (iVar7 != 0) {
      return iVar7;
    }
  }
  return 0;
}

/* FUN_0012a00c @ 0x12a00c (540 bytes) */
int FUN_0012a00c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 uStack00000030;
  undefined4 in_stack_00000038;
  int in_stack_0000003c;
  
  iVar7 = in_stack_0000003c;
  uVar8 = *(undefined4 *)(in_stack_0000003c + 0x6c4);
  switch(param_2) {
  case 0:
    uVar2 = 0x27;
    bVar1 = false;
    break;
  case 1:
    uVar2 = 0x2a;
    bVar1 = false;
    break;
  case 2:
    uVar2 = 0x28;
    bVar1 = true;
    break;
  case 3:
    uVar2 = 0x29;
    bVar1 = true;
    break;
  case 4:
    uVar2 = 0x28;
    bVar1 = false;
    break;
  case 5:
    uVar2 = 0x29;
    bVar1 = false;
    break;
  default:
    uVar2 = 0xb5;
    bVar1 = false;
  }
  bVar1 = !bVar1;
  uStack00000030 = param_7;
  uVar2 = FUN_001043f0(uVar2,in_stack_0000003c);
  uVar3 = FUN_000ec208(uVar8,param_4);
  iVar4 = FUN_001054ec(uVar2,2 - (uint)bVar1);
  *(undefined4 *)(iVar4 + 0xc) = uVar3;
  *(undefined4 *)(iVar4 + 8) = param_3;
  if (bVar1) {
    uVar3 = 2;
  }
  else {
    uVar3 = 1;
  }
  uVar5 = FUN_000ec208(uVar8,param_6);
  iVar4 = FUN_001054ec(uVar2,uVar3);
  *(undefined4 *)(iVar4 + 0xc) = uVar5;
  *(undefined4 *)(iVar4 + 8) = param_5;
  if (bVar1) {
    uVar3 = 1;
  }
  else {
    uVar3 = 2;
  }
  FUN_000f8aa0(uVar8,&STACKARG(0x30),**(undefined4 **)(param_8 + 0x6c),uVar3,uVar2);
  if (bVar1) {
    uVar3 = 2;
  }
  else {
    uVar3 = 1;
  }
  FUN_000f8aa0(uVar8,&STACKARG(0x30),*(undefined4 *)(*(int *)(param_8 + 0x6c) + 4),uVar3,uVar2);
  iVar10 = *(int *)(iVar7 + 0x3ac) + -1;
  *(int *)(iVar7 + 0x3ac) = iVar10;
  iVar4 = FUN_001054ec(uVar2,0);
  *(undefined4 *)(iVar4 + 0xc) = 0;
  *(int *)(iVar4 + 8) = iVar10;
  FUN_000f92fc(uVar8,uVar2,in_stack_00000038);
  uVar8 = *(undefined4 *)(iVar7 + 0x374);
  puVar6 = (undefined4 *)FUN_00193e18(uVar8,0x168);
  puVar9 = puVar6 + 1;
  *puVar6 = uVar8;
  FUN_0010502c(puVar9,0x8c,iVar7);
  iVar7 = FUN_001054ec(puVar9,1);
  *(int *)(iVar7 + 8) = iVar10;
  *(undefined4 *)(iVar7 + 0xc) = 0;
  puVar6[0x4c] = 0;
  return puVar9;
}

/* FUN_0012a260 @ 0x12a260 (352 bytes) */
int FUN_0012a260(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_2 + 0x3d4) == 0) {
    iVar1 = *(int *)(*(int *)(param_2 + 0x3a0) + 0x98);
    iVar4 = *(int *)(iVar1 + 8);
    if (iVar4 != 0) {
      iVar3 = 0;
      do {
        iVar2 = iVar4;
        if (((*(uint *)(iVar1 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar1 + 0x88) + 8) == 0xa4))
        {
          iVar4 = FUN_000e07dc(*(undefined4 *)(param_2 + 8),0x3e);
          if ((iVar4 == 0) ||
             (iVar4 = (**(code **)(*param_1 + 0x18c))(param_1,*(undefined4 *)(iVar1 + 0x94),param_2)
             , iVar4 != 0)) {
            (**(code **)(*param_1 + 400))(param_1,*(undefined4 *)(iVar1 + 0x94),iVar3);
            iVar4 = FUN_001054ec(iVar1,0);
            *(int *)(iVar4 + 8) = iVar3;
            iVar2 = *(int *)(iVar1 + 8);
            iVar3 = iVar3 + 1;
          }
          else {
            iVar2 = *(int *)(iVar1 + 8);
          }
        }
        iVar4 = *(int *)(iVar2 + 8);
        iVar1 = iVar2;
      } while (*(int *)(iVar2 + 8) != 0);
    }
  }
  else {
    iVar4 = *(int *)(*(int *)(param_2 + 0x3a0) + 0x98);
    for (iVar1 = *(int *)(iVar4 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if (((*(uint *)(iVar4 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar4 + 0x88) + 8) == 0xa4)) {
        (**(code **)(*param_1 + 400))
                  (param_1,*(undefined4 *)(iVar4 + 0x94),*(undefined4 *)(iVar4 + 0x94));
        iVar1 = *(int *)(iVar4 + 8);
      }
      iVar4 = iVar1;
    }
  }
  return;
}

/* FUN_0012a3c0 @ 0x12a3c0 (248 bytes) */
int FUN_0012a3c0(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  byte bVar2;
  int iVar3;
  
  if ((((*(char *)(param_2 + 8) != '\0') && (bVar2 = *(byte *)(param_2 + 9), (bVar2 & 1) == 0)) &&
      ((bVar2 & 2) == 0)) && (((bVar2 & 4) == 0 && ((bVar2 & 8) == 0)))) {
    iVar3 = FUN_00173e10(param_3,-*(float *)(param_2 + 0x14));
    if (*(char *)(iVar3 + 8) == '\0') {
      bVar2 = *(byte *)(iVar3 + 9);
    }
    else {
      bVar2 = *(byte *)(iVar3 + 9);
      if ((((bVar2 & 1) == 0) && ((bVar2 & 2) == 0)) && (((bVar2 & 4) == 0 && ((bVar2 & 8) == 0))))
      {
        return;
      }
    }
    if (((bVar2 & 1) == 0) || ((bVar2 & 2) != 0)) {
      *(undefined4 *)(iVar3 + 0x20) = 0x31;
      FUN_00176280(iVar3,param_2);
      uVar1 = *(undefined4 *)(param_2 + 0x14);
      *(undefined1 *)(iVar3 + 9) = 1;
      *(undefined4 *)(iVar3 + 0x14) = uVar1;
      *(undefined4 *)(iVar3 + 0x1c) = 0;
      *(undefined4 *)(iVar3 + 0x18) = 1;
    }
  }
  return;
}

/* FUN_0012a4b8 @ 0x12a4b8 (176 bytes) */
int FUN_0012a4b8(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  puVar2 = (undefined4 *)FUN_000e1564(param_2,0x3c);
  puVar1 = PTR_DAT_001e9110;
  puVar3 = PTR_DAT_001e90fc + 8;
  puVar2[2] = param_2;
  *puVar2 = puVar3;
  puVar2[1] = 0;
  *puVar2 = puVar1 + 8;
  FUN_0018f824();
  FUN_00172000(puVar2);
  puVar2[0xe] = 0;
  *(undefined4 **)(param_1 + 0x60) = puVar2;
  puVar2 = (undefined4 *)FUN_000e1564(param_2,0xc);
  puVar1 = PTR_DAT_001e9100;
  puVar2[1] = 1;
  puVar2[2] = 0;
  *puVar2 = puVar1 + 8;
  *(undefined4 **)(param_1 + 100) = puVar2;
  return;
}

/* FUN_0012a578 @ 0x12a578 (308 bytes) */
int FUN_0012a578(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  FUN_0010dad8();
  puVar1 = PTR_DAT_001e9114;
  param_1[4] = 5;
  param_1[1] = puVar1;
  param_1[6] = 0x48;
  param_1[5] = 2;
  param_1[0x12] = 0x3ff;
  *param_1 = &PTR_FUN_001eaf20;
  param_1[8] = 0x7fffffff;
  param_1[0xf] = 0x10;
  param_1[0x10] = 0x100;
  param_1[0x13] = 4;
  param_1[0x14] = 0x20;
  param_1[0x15] = 1;
  param_1[2] = param_1[2] | 0x2000;
  param_1[7] = 4;
  param_1[0xb] = 0x100;
  param_1[9] = 0x100;
  param_1[10] = 0x100;
  param_1[0xe] = 0x10;
  param_1[0x11] = 4;
  FUN_0010dc20(param_1);
  FUN_0010dbd8(param_1,0x3a);
  FUN_0010dbd8(param_1,0x3e);
  FUN_0010dbd8(param_1,0x3f);
  FUN_0010dbd8(param_1,0x4d);
  param_1[0x19] = 0;
  param_1[0x18] = 0;
  ((int (*)())FUN_0012a970)(param_1);
  if (param_3 != 0) {
    ((int (*)())FUN_0012a4b8)(param_1,param_2);
  }
  return;
}

/* FUN_0012a6c0 @ 0x12a6c0 (308 bytes) */
int FUN_0012a6c0(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined *puVar1;
  
  FUN_0010dad8();
  puVar1 = PTR_DAT_001e9114;
  param_1[4] = 5;
  param_1[1] = puVar1;
  param_1[6] = 0x48;
  param_1[5] = 2;
  param_1[0x12] = 0x3ff;
  *param_1 = &PTR_FUN_001eaf20;
  param_1[8] = 0x7fffffff;
  param_1[0xf] = 0x10;
  param_1[0x10] = 0x100;
  param_1[0x13] = 4;
  param_1[0x14] = 0x20;
  param_1[0x15] = 1;
  param_1[2] = param_1[2] | 0x2000;
  param_1[7] = 4;
  param_1[0xb] = 0x100;
  param_1[9] = 0x100;
  param_1[10] = 0x100;
  param_1[0xe] = 0x10;
  param_1[0x11] = 4;
  FUN_0010dc20(param_1);
  FUN_0010dbd8(param_1,0x3a);
  FUN_0010dbd8(param_1,0x3e);
  FUN_0010dbd8(param_1,0x3f);
  FUN_0010dbd8(param_1,0x4d);
  param_1[0x19] = 0;
  param_1[0x18] = 0;
  ((int (*)())FUN_0012a970)(param_1);
  if (param_3 != 0) {
    ((int (*)())FUN_0012a4b8)(param_1,param_2);
  }
  return;
}

/* FUN_0012a808 @ 0x12a808 (144 bytes) */
int FUN_0012a808(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  ((int (*)())FUN_0012a6c0)(param_1,param_2,0);
  *param_1 = &PTR_FUN_001eb0c0;
  param_1[6] = 0x80;
  param_1[0x10] = 0x400;
  param_1[2] = param_1[2] | 0x10100;
  ((int (*)())FUN_0012a9e4)(param_1);
  if (param_3 != 0) {
    ((int (*)())FUN_00129290)(param_1,param_2);
  }
  return;
}

/* FUN_0012a8bc @ 0x12a8bc (144 bytes) */
int FUN_0012a8bc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  ((int (*)())FUN_0012a6c0)(param_1,param_2,0);
  *param_1 = &PTR_FUN_001eb0c0;
  param_1[6] = 0x80;
  param_1[0x10] = 0x400;
  param_1[2] = param_1[2] | 0x10100;
  ((int (*)())FUN_0012a9e4)(param_1);
  if (param_3 != 0) {
    ((int (*)())FUN_00129290)(param_1,param_2);
  }
  return;
}

/* FUN_0012a970 @ 0x12a970 (116 bytes) */
int FUN_0012a970(param_1)
  int param_1;
{
  PTR_DAT_001e27bc = PTR_DAT_001e9120;
  *(undefined **)(param_1 + 0xc) = &DAT_001e1994;
  PTR_DAT_001e260c = PTR_DAT_001e911c;
  PTR_DAT_001e1c34 = PTR_DAT_001e9128;
  DAT_001e1c2c = 5;
  DAT_001e1c30 = 0;
  PTR_DAT_001e269c = PTR_DAT_001e9124;
  PTR_DAT_001e2630 = PTR_DAT_001e9118;
  DAT_001e2604 = 5;
  DAT_001e2608 = 0;
  return;
}

/* FUN_0012a9e4 @ 0x12a9e4 (116 bytes) */
int FUN_0012a9e4(param_1)
  int param_1;
{
  *(undefined **)(param_1 + 0xc) = &DAT_001e1994;
  DAT_001e25f4 = 0x4c;
  PTR_DAT_001e27bc = PTR_DAT_001e8c84;
  DAT_001e1c2c = 4;
  DAT_001e1c30 = PTR_FUN_001e8c7c;
  PTR_DAT_001e1c34 = (undefined *)0x0;
  DAT_001e1c1c = 0x4d;
  PTR_DAT_001e269c = PTR_DAT_001e8c78;
  DAT_001e2604 = 4;
  DAT_001e2608 = PTR_FUN_001e8c7c;
  PTR_DAT_001e260c = (undefined *)0x0;
  PTR_DAT_001e2630 = PTR_DAT_001e8c84;
  return;
}

/* FUN_0012aa58 @ 0x12aa58 (32 bytes) */
int FUN_0012aa58(param_1)
  int param_1;
{
  *(undefined **)(param_1 + 0xc) = &DAT_001e39a4;
  return;
}

/* FUN_0012aa78 @ 0x12aa78 (104 bytes) */
int FUN_0012aa78(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  if (((*(int *)(param_5 + 0x140) == 0) ||
      (param_2 * param_4 + param_3 <= *(int *)(*(int *)(param_1 + 0x30c) + 0x2c))) &&
     ((*(int *)(param_1 + 0x318) == 0 ||
      ((param_2 <= *(int *)(param_1 + 0x478) &&
       (param_2 * (*(int *)(param_1 + 0x324) - *(int *)(param_5 + 0x130)) <=
        *(int *)(param_1 + 0x478) << 1)))))) {
    return 0;
  }
  return 1;
}

/* FUN_0012aae0 @ 0x12aae0 (36 bytes) */
int FUN_0012aae0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 < 1) {
    return;
  }
  *(undefined4 *)(param_1 + 0x47c) = 1;
  if (param_2 <= *(int *)(param_1 + 0x480)) {
    return;
  }
  *(int *)(param_1 + 0x480) = param_2;
  return;
}

/* FUN_0012ab04 @ 0x12ab04 (108 bytes) */
int FUN_0012ab04(param_1)
  int *param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar1 < iVar2) {
      return 0;
    }
    iVar1 = FUN_00105dbc(param_1,iVar2);
    if (iVar1 == 1) break;
    iVar2 = iVar2 + 1;
  }
  return 1;
}

/* FUN_0012ab80 @ 0x12ab80 (88 bytes) */
int FUN_0012ab80(param_1)
  int param_1;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
  (**(code **)(*piVar1 + 0x74))(piVar1,param_1);
  FUN_000ed7e4(param_1,"optimize_control_flow");
  return;
}

/* FUN_0012abd8 @ 0x12abd8 (128 bytes) */
int FUN_0012abd8(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x134);
  *(undefined4 *)(param_2 + 0x134) = *(undefined4 *)(param_2 + 0x138);
  *(undefined4 *)(param_2 + 0x138) = uVar2;
  FUN_0019401c(uVar2);
  FUN_00193f44(uVar2,*(undefined4 *)(param_2 + 0x13c));
  uVar2 = FUN_000e7804(param_2);
  iVar1 = FUN_0010b5f8();
  FUN_0010b914(uVar2,*(undefined4 *)(PTR_DAT_001e912c + iVar1 * 4));
  return param_2;
}

/* FUN_0012ac58 @ 0x12ac58 (452 bytes) */
int FUN_0012ac58(param_1, param_2)
  int param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)param_2[0x4b];
  while( true ) {
    while( true ) {
      while( true ) {
        piVar1 = (int *)FUN_000e920c(param_2,0);
        iVar2 = (**(code **)(*piVar1 + 0x10))();
        if ((iVar2 != 0) && (*(int *)(iVar2 + 300) == param_1)) {
          iVar2 = (**(code **)(*piVar3 + 0x2c))(piVar3);
          piVar3 = (int *)FUN_000e9184(piVar3,iVar2 != 0);
          return piVar3;
        }
        iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1);
        if (iVar2 == 0) break;
        param_2 = (int *)piVar1[0x4f];
      }
      iVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1);
      if (iVar2 == 0) break;
      param_2 = (int *)piVar1[0x55];
    }
    iVar2 = (**(code **)(*param_2 + 0x38))(param_2);
    if ((iVar2 != 0) || (iVar2 = (**(code **)(*param_2 + 0x3c))(param_2), iVar2 != 0)) break;
    iVar2 = (**(code **)(*piVar1 + 0x28))(piVar1);
    if ((iVar2 == 0) && (iVar2 = (**(code **)(*piVar1 + 0x30))(piVar1), iVar2 == 0)) {
      iVar2 = (**(code **)(*piVar1 + 0x20))(piVar1);
      if (iVar2 == 0) {
        param_2 = (int *)FUN_000e920c(param_2,0);
      }
    }
    else {
      piVar3 = (int *)piVar1[0x4b];
      param_2 = piVar1;
    }
  }
  return param_2;
}

/* FUN_0012ae1c @ 0x12ae1c (80 bytes) */
int FUN_0012ae1c(param_1)
  int *param_1;
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x30))();
  if (iVar1 != 0) {
    param_1 = *(int **)(param_1[0x4b] + 0x154);
  }
  return param_1;
}

/* FUN_0012ae6c @ 0x12ae6c (132 bytes) */
int FUN_0012ae6c(param_1)
  int param_1;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0x98);
  piVar2 = (int *)(*(int **)(param_1 + 0x98))[2];
  do {
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    if ((piVar1[5] & 1U) != 0) {
      iVar3 = (**(code **)(*piVar1 + 0x28))(piVar1);
      if (iVar3 != 0) {
        return 1;
      }
      piVar2 = (int *)piVar1[2];
    }
    piVar1 = piVar2;
    piVar2 = (int *)piVar2[2];
  } while( true );
}

/* FUN_0012aef0 @ 0x12aef0 (248 bytes) */
int FUN_0012aef0(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  
  iVar1 = FUN_000e7770(param_2);
  if ((((iVar1 == 0) || (iVar1 = FUN_000e7770(param_3), iVar1 == 0)) ||
      (iVar1 = FUN_000e79d0(param_2), iVar1 != 1)) ||
     ((iVar1 = FUN_000e79dc(param_3), iVar1 != 1 || (iVar1 = FUN_000e79e8(param_3), iVar1 == 0)))) {
    uVar2 = 0;
  }
  else {
    piVar3 = *(int **)(*(int *)(param_3 + 200) + 8);
    while (piVar4 = piVar3, iVar1 = (**(code **)(*piVar4 + 0x38))(piVar4), iVar1 == 0) {
      piVar3 = (int *)piVar4[2];
      if ((piVar4[5] & 1U) != 0) {
        FUN_0019401c(piVar4);
        FUN_000e7688(param_2,piVar4);
      }
    }
    uVar2 = FUN_000e920c(param_3,0);
    FUN_000e9730(param_3,param_2,uVar2);
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_0012afe8 @ 0x12afe8 (344 bytes) */
int FUN_0012afe8(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
{
  int iVar1;
  
  if (param_3 != (int *)0x0) {
    do {
      iVar1 = (**(code **)(*param_3 + 0x24))(param_3);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*param_3 + 0x2c))(param_3);
        if (iVar1 == 0) {
          iVar1 = (**(code **)(*param_3 + 0x28))(param_3);
          if (iVar1 != 0) {
            if (param_1 == 0) {
              return param_3;
            }
            if (param_4 != param_3) {
              return param_3;
            }
            return param_4;
          }
          iVar1 = (**(code **)(*param_3 + 0x30))(param_3);
          if (iVar1 != 0) {
            return param_3;
          }
          iVar1 = (**(code **)(*param_3 + 0x10))(param_3);
          if (((iVar1 != 0) && (param_1 == 0)) &&
             (iVar1 = (**(code **)(*param_3 + 0x10))(param_3), *(int *)(iVar1 + 300) == param_2)) {
            return param_3;
          }
        }
        else {
          param_3 = (int *)param_3[0x54];
        }
      }
      else {
        param_3 = (int *)param_3[0x4f];
      }
      param_3 = (int *)FUN_000e920c(param_3,0);
    } while (param_3 != (int *)0x0);
  }
  return (int *)0x0;
}

/* FUN_0012b140 @ 0x12b140 (264 bytes) */
int FUN_0012b140(param_1)
  int *param_1;
{
  int iVar1;
  
  iVar1 = *param_1;
  do {
    iVar1 = (**(code **)(iVar1 + 0x2c))(param_1);
    if (iVar1 == 0) {
      param_1 = (int *)FUN_000e9184(param_1,0);
    }
    else {
      param_1 = (int *)FUN_000e7e90(param_1);
    }
    while( true ) {
      while( true ) {
        if (param_1 == (int *)0x0) {
          return (int *)0x0;
        }
        iVar1 = (**(code **)(*param_1 + 0x24))(param_1);
        if (iVar1 != 0) {
          return param_1;
        }
        iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
        if (iVar1 == 0) break;
        param_1 = (int *)FUN_000e9184(param_1[0x4b],0);
      }
      iVar1 = (**(code **)(*param_1 + 0x34))(param_1);
      if (iVar1 == 0) break;
      param_1 = (int *)FUN_000e7e90(param_1[0x4b]);
    }
    iVar1 = *param_1;
  } while( true );
}

/* FUN_0012b248 @ 0x12b248 (144 bytes) */
int FUN_0012b248(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)(param_3 + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(param_3 + 8) + 0x3ac) = iVar4;
  uVar1 = FUN_001043f0(0x31,*(undefined4 *)(param_3 + 8));
  iVar2 = FUN_001054ec(uVar1,0);
  uVar3 = *(undefined4 *)(param_1 + 0x8c);
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(int *)(iVar2 + 8) = iVar4;
  FUN_001046c8(uVar1,1,uVar3);
  FUN_000ed63c(param_3,uVar1);
  FUN_000e7688(param_2,uVar1);
  return iVar4;
}

/* FUN_0012b2d8 @ 0x12b2d8 (132 bytes) */
int FUN_0012b2d8(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_001043f0(0x31,*(undefined4 *)(param_4 + 8));
  iVar2 = FUN_001054ec(uVar1,0);
  uVar3 = *(undefined4 *)(param_1 + 0xa4);
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 8) = param_3;
  FUN_001046c8(uVar1,1,uVar3);
  FUN_000ed63c(param_4,uVar1);
  FUN_000e7688(param_2,uVar1);
  return uVar1;
}

