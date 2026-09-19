#include "decls.h"

/* FUN_00131888 @ 0x131888 (153 bytes) */
int FUN_00131888(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
{
  byte bVar1;
  int iVar2;
  
  if ((((((*(char *)(param_2 + 8) != '\0') && (bVar1 = *(byte *)(param_2 + 9), (bVar1 & 1) == 0)) &&
        ((bVar1 & 2) == 0)) && (((bVar1 & 4) == 0 && ((bVar1 & 8) == 0)))) &&
      ((((iVar2 = FUN_001840fe(param_3,*(uint *)(param_2 + 0x14) ^ 0x80000000),
         *(char *)(iVar2 + 8) == '\0' ||
         ((bVar1 = *(byte *)(iVar2 + 9), (bVar1 & 1) != 0 || ((bVar1 & 2) != 0)))) ||
        ((bVar1 & 4) != 0)) || ((bVar1 & 8) != 0)))) &&
     (((*(byte *)(iVar2 + 9) & 1) == 0 || ((*(byte *)(iVar2 + 9) & 2) != 0)))) {
    *(undefined4 *)(iVar2 + 0x20) = 0x31;
    FUN_00186a96(iVar2,param_2);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(param_2 + 0x14);
    *(undefined1 *)(iVar2 + 0x18) = 1;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    *(undefined1 *)(iVar2 + 9) = 1;
  }
  return;
}

/* FUN_00131922 @ 0x131922 (151 bytes) */
int FUN_00131922(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_000e27f6(param_2,0x3c);
  *puVar1 = PTR_DAT_002139f5 + 8;
  puVar1[2] = param_2;
  puVar1[1] = 0;
  *puVar1 = PTR_DAT_00213a09 + 8;
  FUN_001a3010(puVar1);
  FUN_001825e0(puVar1);
  puVar1[0xe] = 0;
  *(undefined4 **)(param_1 + 0x60) = puVar1;
  puVar1 = (undefined4 *)FUN_000e27f6(param_2,0xc);
  *puVar1 = PTR_DAT_00213a01 + 8;
  puVar1[1] = 1;
  puVar1[2] = 0;
  *(undefined4 **)(param_1 + 100) = puVar1;
  return;
}

/* FUN_001319cc @ 0x1319cc (303 bytes) */
int FUN_001319cc(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_001130c0(param_1,param_2);
  *param_1 = &PTR_FUN_001fd668;
  param_1[1] = PTR_DAT_00213a0d;
  param_1[4] = 5;
  param_1[5] = 2;
  param_1[7] = 4;
  param_1[8] = 0x7fffffff;
  param_1[0xb] = 0x100;
  param_1[6] = 0x48;
  param_1[9] = 0x100;
  param_1[10] = 0x100;
  param_1[0xe] = 0x10;
  param_1[0xf] = 0x10;
  param_1[0x10] = 0x100;
  param_1[0x11] = 4;
  param_1[0x12] = 0x3ff;
  param_1[0x13] = 4;
  param_1[0x14] = 0x20;
  param_1[0x15] = 1;
  param_1[2] = param_1[2] | 0x2000;
  FUN_0011325a(param_1);
  FUN_00113210(param_1,0x3a);
  FUN_00113210(param_1,0x3e);
  FUN_00113210(param_1,0x3f);
  FUN_00113210(param_1,0x4d);
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  ((int (*)())FUN_00131d74)(param_1);
  if (param_3 == '\0') {
    return;
  }
  ((int (*)())FUN_00131922)(param_1,param_2);
  return;
}

/* FUN_00131b0e @ 0x131b0e (303 bytes) */
int FUN_00131b0e(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_001130c0(param_1,param_2);
  *param_1 = &PTR_FUN_001fd668;
  param_1[1] = PTR_DAT_00213a0d;
  param_1[4] = 5;
  param_1[5] = 2;
  param_1[7] = 4;
  param_1[8] = 0x7fffffff;
  param_1[0xb] = 0x100;
  param_1[6] = 0x48;
  param_1[9] = 0x100;
  param_1[10] = 0x100;
  param_1[0xe] = 0x10;
  param_1[0xf] = 0x10;
  param_1[0x10] = 0x100;
  param_1[0x11] = 4;
  param_1[0x12] = 0x3ff;
  param_1[0x13] = 4;
  param_1[0x14] = 0x20;
  param_1[0x15] = 1;
  param_1[2] = param_1[2] | 0x2000;
  FUN_0011325a(param_1);
  FUN_00113210(param_1,0x3a);
  FUN_00113210(param_1,0x3e);
  FUN_00113210(param_1,0x3f);
  FUN_00113210(param_1,0x4d);
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  ((int (*)())FUN_00131d74)(param_1);
  if (param_3 == '\0') {
    return;
  }
  ((int (*)())FUN_00131922)(param_1,param_2);
  return;
}

/* FUN_00131c50 @ 0x131c50 (118 bytes) */
int FUN_00131c50(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  ((int (*)())FUN_00131b0e)(param_1,param_2,0);
  *param_1 = &PTR_FUN_001fd808;
  param_1[6] = 0x80;
  param_1[0x10] = 0x400;
  param_1[2] = param_1[2] | 0x10100;
  ((int (*)())FUN_00131dee)(param_1);
  if (param_3 == '\0') {
    return;
  }
  FUN_00130814(param_1,param_2);
  return;
}

/* FUN_00131ce2 @ 0x131ce2 (118 bytes) */
int FUN_00131ce2(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  int param_3;
{
  ((int (*)())FUN_00131b0e)(param_1,param_2,0);
  *param_1 = &PTR_FUN_001fd808;
  param_1[6] = 0x80;
  param_1[0x10] = 0x400;
  param_1[2] = param_1[2] | 0x10100;
  ((int (*)())FUN_00131dee)(param_1);
  if (param_3 == '\0') {
    return;
  }
  FUN_00130814(param_1,param_2);
  return;
}

/* FUN_00131d74 @ 0x131d74 (122 bytes) */
int FUN_00131d74(param_1)
  int param_1;
{
  *(undefined **)(param_1 + 0xc) = &DAT_001f47a0;
  DAT_001f5410 = 5;
  DAT_001f5414 = 0;
  PTR_DAT_001f5418 = PTR_DAT_00213a15;
  DAT_001f4a38 = 5;
  DAT_001f4a3c = 0;
  PTR_DAT_001f4a40 = PTR_DAT_00213a21;
  PTR_DAT_001f54a8 = PTR_DAT_00213a1d;
  PTR_DAT_001f543c = PTR_DAT_00213a11;
  PTR_DAT_001f55c8 = PTR_DAT_00213a19;
  return;
}

/* FUN_00131dee @ 0x131dee (130 bytes) */
int FUN_00131dee(param_1)
  int param_1;
{
  *(undefined **)(param_1 + 0xc) = &DAT_001f47a0;
  DAT_001f5410 = 4;
  DAT_001f5414 = PTR_FUN_00213575;
  PTR_DAT_001f5418 = (undefined *)0x0;
  DAT_001f5400 = 0x4c;
  DAT_001f4a38 = 4;
  DAT_001f4a3c = PTR_FUN_00213575;
  PTR_DAT_001f4a40 = (undefined *)0x0;
  DAT_001f4a28 = 0x4d;
  PTR_DAT_001f54a8 = PTR_DAT_00213571;
  PTR_DAT_001f543c = PTR_DAT_0021357d;
  PTR_DAT_001f55c8 = PTR_DAT_0021357d;
  return;
}

/* FUN_00131e70 @ 0x131e70 (22 bytes) */
int FUN_00131e70(param_1)
  int param_1;
{
  *(undefined **)(param_1 + 0xc) = &DAT_001f67c0;
  return;
}

/* FUN_00131e88 @ 0x131e88 (90 bytes) */
int FUN_00131e88(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  
  if (((*(char *)(param_5 + 0x135) == '\0') ||
      (param_2 * param_4 + param_3 <= *(int *)(*(int *)(param_1 + 0x54) + 0x2c))) &&
     ((*(char *)(param_1 + 0x60) == '\0' ||
      ((iVar1 = *(int *)(param_1 + 0x1bc), param_2 <= iVar1 &&
       (param_2 = param_2 * (*(int *)(param_1 + 0x68) - *(int *)(param_5 + 0x128)),
       param_2 + iVar1 * -2 == 0 || param_2 < iVar1 * 2)))))) {
    return 0;
  }
  return 1;
}

/* FUN_00131ee2 @ 0x131ee2 (36 bytes) */
int FUN_00131ee2(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((0 < param_2) && (*(undefined1 *)(param_1 + 0x1c0) = 1, *(int *)(param_1 + 0x1c4) < param_2))
  {
    *(int *)(param_1 + 0x1c4) = param_2;
  }
  return;
}

/* FUN_00131f06 @ 0x131f06 (56 bytes) */
int FUN_00131f06(param_1)
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
    iVar1 = FUN_0010b7c8(param_1,iVar2);
    if (iVar1 == 1) break;
    iVar2 = iVar2 + 1;
  }
  return 1;
}

/* FUN_00131f3e @ 0x131f3e (22 bytes) */
int FUN_00131f3e(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined1 uVar1;
  
  uVar1 = FUN_000eacec(param_2);
  return uVar1;
}

/* FUN_00131f54 @ 0x131f54 (22 bytes) */
int FUN_00131f54(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined1 uVar1;
  
  uVar1 = FUN_000eacec(param_2);
  return uVar1;
}

/* FUN_00131f6a @ 0x131f6a (59 bytes) */
int FUN_00131f6a(param_1)
  int param_1;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  (**(code **)(*piVar1 + 0x74))(piVar1,param_1);
  FUN_000f0346(param_1,"optimize_control_flow");
  return;
}

/* FUN_00131fa6 @ 0x131fa6 (116 bytes) */
int FUN_00131fa6(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 300);
  *(undefined4 *)(param_2 + 300) = *(undefined4 *)(param_2 + 0x130);
  *(undefined4 *)(param_2 + 0x130) = uVar1;
  FUN_001a7d72(uVar1);
  FUN_001a7cb8(uVar1,*(undefined4 *)(param_2 + 0x134));
  uVar1 = FUN_000e9644(param_2);
  iVar2 = FUN_0011074c(uVar1);
  FUN_00110a08(uVar1,*(undefined4 *)(PTR_DAT_00213a25 + iVar2 * 4));
  return param_2;
}

/* FUN_0013201a @ 0x13201a (350 bytes) */
int FUN_0013201a(param_1, param_2)
  int param_1;
  int *param_2;
{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *local_10;
  
  local_10 = (int *)param_2[0x49];
  do {
    piVar2 = (int *)FUN_000eac7c(param_2,0);
    iVar3 = (**(code **)(*piVar2 + 0x10))(piVar2);
    if (iVar3 != 0) {
      iVar3 = *(int *)(iVar3 + 0x124);
      goto joined_r0x0013205d;
    }
    while (cVar1 = (**(code **)(*piVar2 + 0x24))(piVar2), cVar1 != '\0') {
      param_2 = (int *)piVar2[0x4d];
      piVar2 = (int *)FUN_000eac7c(param_2,0);
      iVar3 = (**(code **)(*piVar2 + 0x10))(piVar2);
      if (iVar3 != 0) {
        iVar3 = *(int *)(iVar3 + 0x124);
joined_r0x0013205d:
        if (iVar3 == param_1) {
          cVar1 = (**(code **)(*local_10 + 0x2c))(local_10);
          if (cVar1 == '\0') {
            piVar2 = (int *)FUN_000eac0c();
            return piVar2;
          }
          piVar2 = (int *)FUN_000eac0c();
          return piVar2;
        }
      }
    }
    cVar1 = (**(code **)(*piVar2 + 0x2c))(piVar2);
    if (cVar1 == '\0') {
      cVar1 = (**(code **)(*param_2 + 0x38))(param_2);
      if ((cVar1 != '\0') || (cVar1 = (**(code **)(*param_2 + 0x3c))(param_2), cVar1 != '\0')) {
        return param_2;
      }
      cVar1 = (**(code **)(*piVar2 + 0x28))(piVar2);
      if (cVar1 == '\0') {
        cVar1 = (**(code **)(*piVar2 + 0x30))(piVar2);
        if (cVar1 == '\0') {
          cVar1 = (**(code **)(*piVar2 + 0x20))(piVar2);
          if (cVar1 == '\0') {
            param_2 = (int *)FUN_000eac7c(param_2,0);
          }
        }
        else {
          local_10 = (int *)piVar2[0x49];
          param_2 = piVar2;
        }
      }
      else {
        local_10 = (int *)piVar2[0x49];
        param_2 = piVar2;
      }
    }
    else {
      param_2 = (int *)piVar2[0x51];
    }
  } while( true );
}

/* FUN_00132178 @ 0x132178 (41 bytes) */
int FUN_00132178(param_1)
  int *param_1;
{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x30))(param_1);
  if (cVar1 != '\0') {
    param_1 = *(int **)(param_1[0x49] + 0x144);
  }
  return param_1;
}

/* FUN_001321a2 @ 0x1321a2 (68 bytes) */
int FUN_001321a2(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  char cVar3;
  
  piVar1 = *(int **)(param_1 + 0x98);
  iVar2 = piVar1[2];
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    if (((*(byte *)(piVar1 + 5) & 1) != 0) &&
       (cVar3 = (**(code **)(*piVar1 + 0x28))(piVar1), cVar3 != '\0')) break;
    piVar1 = (int *)piVar1[2];
    iVar2 = piVar1[2];
  }
  return 1;
}

/* FUN_001321e6 @ 0x1321e6 (205 bytes) */
int FUN_001321e6(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  cVar2 = FUN_000e95be(param_2);
  if ((((cVar2 == '\0') || (cVar2 = FUN_000e95be(param_3), cVar2 == '\0')) ||
      (iVar4 = FUN_000e97aa(param_2), iVar4 != 1)) ||
     ((iVar4 = FUN_000e97bc(param_3), iVar4 != 1 || (cVar2 = FUN_000e97ce(param_3), cVar2 == '\0')))
     ) {
    uVar3 = 0;
  }
  else {
    piVar1 = *(int **)(*(int *)(param_3 + 200) + 8);
    while (piVar5 = piVar1, cVar2 = (**(code **)(*piVar5 + 0x38))(piVar5), cVar2 == '\0') {
      piVar1 = (int *)piVar5[2];
      if ((*(byte *)(piVar5 + 5) & 1) != 0) {
        FUN_001a7d72(piVar5);
        FUN_000e9512(param_2,piVar5);
      }
    }
    uVar3 = FUN_000eac7c(param_3,0);
    FUN_000eb0bc(param_3,param_2,uVar3);
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_001322b4 @ 0x1322b4 (201 bytes) */
int FUN_001322b4(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
{
  char cVar1;
  int iVar2;
  
  do {
    if (param_3 == (int *)0x0) {
      return (int *)0x0;
    }
    while (cVar1 = (**(code **)(*param_3 + 0x24))(param_3), cVar1 == '\0') {
      cVar1 = (**(code **)(*param_3 + 0x2c))(param_3);
      if (cVar1 == '\0') {
        cVar1 = (**(code **)(*param_3 + 0x28))(param_3);
        if (cVar1 != '\0') {
          if ((param_1 != '\0') && (param_4 == param_3)) {
            param_3 = param_4;
          }
          return param_3;
        }
        cVar1 = (**(code **)(*param_3 + 0x30))(param_3);
        if (cVar1 != '\0') {
          return param_3;
        }
        iVar2 = (**(code **)(*param_3 + 0x10))(param_3);
        if (((iVar2 != 0) && (param_1 == '\0')) &&
           (iVar2 = (**(code **)(*param_3 + 0x10))(param_3), *(int *)(iVar2 + 0x124) == param_2)) {
          return param_3;
        }
      }
      else {
        param_3 = (int *)param_3[0x50];
      }
      param_3 = (int *)FUN_000eac7c(param_3,0);
      if (param_3 == (int *)0x0) {
        return (int *)0x0;
      }
    }
    param_3 = (int *)FUN_000eac7c(param_3[0x4d],0);
  } while( true );
}

/* FUN_0013237e @ 0x13237e (154 bytes) */
int FUN_0013237e(param_1)
  int *param_1;
{
  char cVar1;
  
  do {
    cVar1 = (**(code **)(*param_1 + 0x2c))(param_1);
    if (cVar1 == '\0') {
      param_1 = (int *)FUN_000eac0c(param_1,0);
    }
    else {
      param_1 = (int *)FUN_000e9b0e(param_1);
    }
    while( true ) {
      while( true ) {
        if (param_1 == (int *)0x0) {
          return (int *)0x0;
        }
        cVar1 = (**(code **)(*param_1 + 0x24))(param_1);
        if (cVar1 != '\0') {
          return param_1;
        }
        cVar1 = (**(code **)(*param_1 + 0x28))(param_1);
        if (cVar1 == '\0') break;
        param_1 = (int *)FUN_000eac0c(param_1[0x49],0);
      }
      cVar1 = (**(code **)(*param_1 + 0x34))(param_1);
      if (cVar1 == '\0') break;
      param_1 = (int *)FUN_000e9b0e(param_1[0x49]);
    }
  } while( true );
}

/* FUN_00132418 @ 0x132418 (144 bytes) */
int FUN_00132418(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_3 + 8) + 0xf0) + -1;
  *(int *)(*(int *)(param_3 + 8) + 0xf0) = iVar3;
  uVar1 = FUN_0010a17a(0x31,*(undefined4 *)(param_3 + 8));
  iVar2 = FUN_0010b0f4(uVar1,0);
  *(int *)(iVar2 + 8) = iVar3;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  FUN_0010a3c2(uVar1,1,*(undefined4 *)(param_1 + 0x8c));
  FUN_000f0144(param_3,uVar1);
  FUN_000e9512(param_2,uVar1);
  return iVar3;
}

/* FUN_001324a8 @ 0x1324a8 (126 bytes) */
int FUN_001324a8(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_0010a17a(0x31,*(undefined4 *)(param_4 + 8));
  iVar2 = FUN_0010b0f4(uVar1,0);
  *(undefined4 *)(iVar2 + 8) = param_3;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  FUN_0010a3c2(uVar1,1,*(undefined4 *)(param_1 + 0xa4));
  FUN_000f0144(param_4,uVar1);
  FUN_000e9512(param_2,uVar1);
  return uVar1;
}

/* FUN_00132526 @ 0x132526 (130 bytes) */
int FUN_00132526(param_1, param_2)
  undefined1 *param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = FUN_000f60f4(param_2);
  if (iVar1 == 1) {
    *(undefined4 *)(param_1 + 0x30) = param_2;
    *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
    iVar1 = 0;
    do {
      iVar3 = FUN_0010b0f4(param_2,0);
      if (*(char *)(iVar1 + 0x10 + iVar3) != '\x01') {
        *(int *)(param_1 + 0x34) = iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 != 4);
    iVar1 = FUN_00109e42(param_2,*(undefined4 *)(param_1 + 0x3c));
    if (iVar1 != 2) {
      *param_1 = 1;
      return 1;
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_001325a8 @ 0x1325a8 (257 bytes) */
int FUN_001325a8(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint local_34;
  int local_30;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
  iVar2 = *(int *)(param_1 + 0x394);
  do {
    iVar7 = *(int *)(*(int *)(param_1 + 0x378) + 8);
    if (iVar7 == 0) {
      return;
    }
    bVar4 = false;
    iVar6 = *(int *)(param_1 + 0x378);
    do {
      if ((iVar2 != iVar6) && (iVar5 = FUN_000e97bc(iVar6), iVar5 == 0)) {
        local_10 = 0;
        local_30 = 0;
        for (local_34 = 1; local_34 <= *(uint *)(*(int *)(iVar6 + 0xd0) + 4);
            local_34 = local_34 + 1) {
          local_10 = *(int *)(local_30 + *(int *)(*(int *)(iVar6 + 0xd0) + 8));
          if (local_10 != 0) {
            puVar3 = *(undefined4 **)(local_10 + 0xd4);
            local_20 = *puVar3;
            local_1c = puVar3[1];
            local_18 = puVar3[2];
            local_14 = puVar3[3];
            FUN_001a805e(&local_20,iVar6);
            iVar5 = FUN_000e97bc(local_10);
            if (iVar5 == 0) {
              bVar4 = true;
            }
            FUN_001a7aba(local_14,local_18);
          }
          local_30 = local_30 + 4;
        }
        FUN_000e94da(iVar6);
      }
      piVar1 = (int *)(iVar7 + 8);
      iVar6 = iVar7;
      iVar7 = *piVar1;
    } while (*piVar1 != 0);
  } while (bVar4);
  return;
}

/* FUN_001326c6 @ 0x1326c6 (90 bytes) */
int FUN_001326c6(param_1)
  undefined4 param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_000eac0c(param_1,0);
  iVar2 = FUN_000eac7c(param_1,0);
  *(undefined4 *)(*(int *)(iVar1 + 0xd0) + 4) = 0;
  *(undefined4 *)(*(int *)(iVar2 + 0xd4) + 4) = 0;
  FUN_000ea91c(iVar1,iVar2);
  return;
}

/* FUN_00132720 @ 0x132720 (1032 bytes) */
int FUN_00132720(param_1, param_2)
  char *param_1;
  int param_2;
{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 uVar8;
  uint uVar9;
  int local_30;
  
  iVar3 = FUN_000f6e40(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x3a0),3,1);
  if (iVar3 < 0) {
    return 0;
  }
  iVar4 = FUN_0010b180(*(undefined4 *)(param_1 + 0x38),1);
  piVar7 = (int *)(*(int *)(*(int *)(param_1 + 0x38) + 0x158) + 0x130);
  *piVar7 = *piVar7 + -1;
  iVar5 = FUN_00109e42(iVar4,*(undefined4 *)(param_1 + 0x3c));
  *(int *)(iVar4 + 0x160) = iVar5 + -1 + *(int *)(*(int *)(param_1 + 0x3c) + 0x46c);
  iVar4 = *(int *)(*(int *)(param_1 + 0x3c) + 8);
  uVar8 = *(undefined4 *)(iVar4 + 0xb8);
  puVar6 = (undefined4 *)FUN_001a7bca(uVar8,0x168);
  *puVar6 = uVar8;
  puVar1 = puVar6 + 1;
  FUN_0010ee6a(puVar1,iVar4);
  FUN_000e9512(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x394),puVar1);
  puVar6[0x26] = iVar3;
  puVar6[0x27] = 4;
  *(byte *)(puVar6 + 0x58) = *(byte *)(puVar6 + 0x58) | 1;
  if (*(int *)(param_1 + 0x18) == 0) {
    puVar6[8] = 5;
    puVar6[9] = *(undefined4 *)(param_1 + 0xc);
    puVar6[10] = *(undefined4 *)(param_1 + 0x10);
    puVar6[0xb] = *(undefined4 *)(param_1 + 0x1c);
    if (param_1[1] == '\0') {
      puVar6[0xc] = *(undefined4 *)(param_1 + 4);
    }
    else {
      puVar6[0xc] = 0xffffffff;
    }
    puVar6[0xd] = *(undefined4 *)(param_1 + 8);
  }
  else {
    if (param_1[1] == '\0') {
      return 0;
    }
    puVar6[8] = 3;
    puVar6[9] = *(undefined4 *)(param_1 + 0x14);
  }
  FUN_0010ba02(*(undefined4 *)(param_1 + 0x38),1,puVar1,0,iVar4);
  iVar3 = FUN_000eac0c(*(undefined4 *)(param_1 + 0x24),0);
  if (param_2 == '\0') {
    iVar4 = FUN_000eac7c(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x134),0);
  }
  else {
    iVar4 = *(int *)(*(int *)(param_1 + 0x24) + 300);
    ((int (*)())FUN_001326c6)(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x134));
  }
  *(undefined4 *)(*(int *)(iVar3 + 0xd0) + 4) = 0;
  *(undefined4 *)(*(int *)(iVar4 + 0xd4) + 4) = 0;
  FUN_000ea91c(iVar3,iVar4);
  iVar4 = FUN_000eac7c(*(undefined4 *)(param_1 + 0x20),0);
  local_30 = 0;
  uVar9 = 1;
  iVar5 = 0;
  iVar3 = *(int *)(iVar4 + 0xd4);
  if (*(int *)(iVar3 + 4) != 0) {
    do {
      iVar3 = *(int *)(*(int *)(iVar3 + 8) + iVar5);
      if (iVar3 != 0) {
        if (iVar3 == *(int *)(param_1 + 0x20)) {
          FUN_001a7f3c(*(undefined4 *)(iVar4 + 0xd4),local_30);
          break;
        }
        local_30 = local_30 + 1;
      }
      uVar9 = uVar9 + 1;
      iVar5 = iVar5 + 4;
      iVar3 = *(int *)(iVar4 + 0xd4);
    } while (uVar9 <= *(uint *)(iVar3 + 4));
  }
  if (param_2 == '\0') {
    iVar4 = FUN_000eac0c(*(undefined4 *)(param_1 + 0x20),0);
    FUN_000e94da(*(undefined4 *)(param_1 + 0x20));
    iVar3 = *(int *)(param_1 + 0x24);
    if (iVar4 != iVar3) {
      do {
        FUN_000e94da(iVar4);
        iVar4 = FUN_000eac0c(iVar4,0);
        iVar3 = *(int *)(param_1 + 0x24);
      } while (iVar3 != iVar4);
    }
    iVar3 = *(int *)(iVar3 + 0x134);
    if (*(int *)(param_1 + 0x24) != iVar3) {
      do {
        FUN_000e94da(iVar3);
        iVar3 = FUN_000eac0c(iVar3,0);
      } while (iVar3 != *(int *)(param_1 + 0x24));
    }
    cVar2 = *param_1;
  }
  else {
    FUN_000e94da(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x134));
    uVar8 = FUN_000eac0c(*(undefined4 *)(param_1 + 0x20),0);
    FUN_000e94da(uVar8);
    FUN_000e94da(*(undefined4 *)(param_1 + 0x20));
    cVar2 = *param_1;
  }
  if (cVar2 == '\0') {
    (**(code **)(**(int **)(param_1 + 0x30) + 0xc))
              (*(int **)(param_1 + 0x30),0,*(undefined4 *)(*(int *)(param_1 + 0x3c) + 8));
    (**(code **)(**(int **)(param_1 + 0x2c) + 0xc))
              (*(int **)(param_1 + 0x2c),0,*(undefined4 *)(*(int *)(param_1 + 0x3c) + 8));
  }
  piVar7 = (int *)FUN_000e9644(*(undefined4 *)(param_1 + 0x24));
  if (piVar7 != (int *)0x0) {
    (**(code **)(*piVar7 + 0xc))(piVar7,0,*(undefined4 *)(*(int *)(param_1 + 0x3c) + 8));
    *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128) = 0;
  }
  FUN_000e94da(*(undefined4 *)(param_1 + 0x24));
  return 1;
}

/* FUN_00132b46 @ 0x132b46 (172 bytes) */
int FUN_00132b46(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_000e97bc(param_2);
  if (((iVar1 == 2) && (*(char *)(param_2 + 0x134) == '\0')) && (0 < *(int *)(param_2 + 0x130))) {
    *(int *)(param_1 + 0x28) = param_2;
    iVar1 = *(int *)(param_2 + 0x98);
    iVar2 = *(int *)(iVar1 + 8);
    while (iVar2 != 0) {
      if (((*(byte *)(iVar1 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar1 + 0x88) + 8) == 0x81)) {
        iVar2 = FUN_0010b180(iVar1,1);
        if ((*(byte *)(iVar2 + 0x15c) & 1) == 0) {
          return 0;
        }
        if (*(int *)(iVar2 + 0x1c) != 3) {
          return 0;
        }
        iVar2 = *(int *)(iVar2 + 0x20);
        *(int *)(param_1 + 0x1c) = iVar2;
        if ((iVar2 == 0xff) || (iVar2 == 0xffff)) {
          *(int *)(param_1 + 0x38) = iVar1;
          return 1;
        }
      }
      iVar1 = *(int *)(iVar1 + 8);
      iVar2 = *(int *)(iVar1 + 8);
    }
  }
  return 0;
}

/* FUN_00132bf2 @ 0x132bf2 (1324 bytes) */
int FUN_00132bf2(param_1, param_2)
  int param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int *local_54;
  int *local_50;
  char local_4c;
  char local_4b;
  char local_4a;
  int *local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  
  (**(code **)(*param_2 + 0x24))(param_2);
  if ((*(byte *)((int)param_2 + 0xd) & 4) == 0) {
    iVar2 = param_2[0x4b];
    iVar3 = param_2[0x4c];
    iVar6 = FUN_000e9644(param_2);
    if ((((((iVar6 != 0) &&
           (iVar6 = FUN_000e9644(param_2), *(int *)(*(int *)(iVar6 + 0x88) + 8) == 0x8b)) &&
          (cVar5 = FUN_000eacec(param_2), cVar5 != '\0')) &&
         ((iVar6 = param_2[0x4d], (char)param_2[0x42] == '\0' &&
          (*(char *)((int)param_2 + 0x109) == '\0')))) &&
        ((((*(byte *)(param_2 + 3) & 0x10) == 0 &&
          ((*(char *)(iVar6 + 0x108) == '\0' && (*(char *)(iVar6 + 0x109) == '\0')))) &&
         ((*(byte *)(iVar6 + 0xc) & 0x10) == 0)))) &&
       ((((*(char *)(iVar2 + 0x108) == '\0' && (*(char *)(iVar2 + 0x109) == '\0')) &&
         ((*(byte *)(iVar2 + 0xc) & 0x10) == 0)) &&
        (((*(char *)(iVar3 + 0x108) == '\0' && (*(char *)(iVar3 + 0x109) == '\0')) &&
         ((*(byte *)(iVar3 + 0xc) & 0x10) == 0)))))) {
      iVar10 = param_2[0x37];
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
      puVar7 = (undefined4 *)FUN_001a7bca(uVar4,0x128);
      *puVar7 = uVar4;
      piVar1 = puVar7 + 1;
      FUN_000eb992(piVar1,*(undefined4 *)(param_1 + 8));
      FUN_000edc00(param_1,param_2,piVar1);
      FUN_000ea95e(param_2,iVar6,piVar1);
      iVar8 = FUN_000e9644(param_2);
      param_2[0x4a] = 0;
      *(undefined4 *)(iVar8 + 0x80) = 1;
      *(undefined4 *)(iVar8 + 0x94) = 0;
      *(undefined4 *)(iVar8 + 0x98) = 0x35;
      *(undefined4 *)(iVar8 + 0x9c) = DAT_001cc51c;
      uVar9 = *(uint *)(iVar8 + 0x14);
      *(uint *)(iVar8 + 0x14) = uVar9 | 0x80000;
      if ((char)iVar10 != '\0') {
        *(uint *)(iVar8 + 0x14) = uVar9 | 0x81000;
      }
      FUN_001a7d72(iVar8);
      FUN_000e9512(piVar1,iVar8);
      local_54 = (int *)param_2[0x26];
      local_50 = (int *)local_54[2];
      if ((int *)local_54[2] != (int *)0x0) {
        while( true ) {
          cVar5 = (**(code **)(*local_54 + 0x34))(local_54);
          if ((cVar5 == '\0') && (cVar5 = (**(code **)(*local_54 + 0x38))(local_54), cVar5 == '\0'))
          {
            FUN_001a7d72(local_54);
            FUN_000e956e(piVar1,iVar8,local_54);
          }
          if ((int *)local_50[2] == (int *)0x0) break;
          local_54 = local_50;
          local_50 = (int *)local_50[2];
        }
      }
      local_4c = *(char *)(iVar2 + 0xdc);
      local_38 = *(int **)(iVar2 + 0x98);
      local_44 = (int *)local_38[2];
      if ((int *)local_38[2] != (int *)0x0) {
        while( true ) {
          cVar5 = (**(code **)(*local_38 + 0x34))(local_38);
          if ((cVar5 == '\0') && (cVar5 = (**(code **)(*local_38 + 0x38))(local_38), cVar5 == '\0'))
          {
            FUN_001a7d72(local_38);
            (**(code **)(*local_38 + 0x94))(local_38,iVar8,*(undefined4 *)(param_1 + 8));
            (**(code **)(*local_38 + 0x84))(local_38,2);
            FUN_000e9512(piVar1,local_38);
            if (local_4c != '\0') {
              if ((local_38[5] & 0x10000U) == 0) {
                local_38[5] = local_38[5] | 0x1000;
                local_4c = '\0';
              }
              else {
                local_4c = '\x01';
              }
            }
          }
          if ((int *)local_44[2] == (int *)0x0) break;
          local_38 = local_44;
          local_44 = (int *)local_44[2];
        }
      }
      local_34 = *(int **)(iVar3 + 0x98);
      if ((int *)local_34[2] != (int *)0x0) {
        local_4b = local_4c;
        local_40 = (int *)local_34[2];
        while( true ) {
          cVar5 = (**(code **)(*local_34 + 0x34))(local_34);
          if ((cVar5 == '\0') && (cVar5 = (**(code **)(*local_34 + 0x38))(local_34), cVar5 == '\0'))
          {
            FUN_001a7d72(local_34);
            (**(code **)(*local_34 + 0x94))(local_34,iVar8,*(undefined4 *)(param_1 + 8));
            (**(code **)(*local_34 + 0x84))(local_34,3);
            FUN_000e9512(piVar1,local_34);
            if (local_4b != '\0') {
              if ((local_34[5] & 0x10000U) == 0) {
                local_34[5] = local_34[5] | 0x1000;
                local_4b = '\0';
              }
              else {
                local_4b = '\x01';
              }
            }
          }
          if ((int *)local_40[2] == (int *)0x0) break;
          local_34 = local_40;
          local_40 = (int *)local_40[2];
        }
      }
      local_4a = *(char *)(iVar6 + 0xdc);
      local_30 = *(int **)(iVar6 + 0x98);
      local_3c = (int *)local_30[2];
      if ((int *)local_30[2] != (int *)0x0) {
        while( true ) {
          cVar5 = (**(code **)(*local_30 + 0x34))(local_30);
          if ((cVar5 == '\0') && (cVar5 = (**(code **)(*local_30 + 0x38))(local_30), cVar5 == '\0'))
          {
            FUN_001a7d72(local_30);
            (**(code **)(*local_30 + 0x94))(local_30,iVar8,*(undefined4 *)(param_1 + 8));
            FUN_000e9512(piVar1,local_30);
            if (local_4a != '\0') {
              if ((local_30[5] & 0x10000U) == 0) {
                local_30[5] = local_30[5] | 0x1000;
                local_4a = '\0';
              }
              else {
                local_4a = '\x01';
              }
            }
          }
          if ((int *)local_3c[2] == (int *)0x0) break;
          local_30 = local_3c;
          local_3c = (int *)local_3c[2];
        }
      }
      if (local_4a != '\0') {
        iVar10 = 0;
        for (uVar9 = 1; uVar9 <= *(uint *)(puVar7[0x35] + 4); uVar9 = uVar9 + 1) {
          iVar8 = *(int *)(*(int *)(puVar7[0x35] + 8) + iVar10);
          if (iVar8 != 0) {
            *(undefined1 *)(iVar8 + 0xdc) = 1;
          }
          iVar10 = iVar10 + 4;
        }
      }
      FUN_000e94da(param_2);
      FUN_000e94da(iVar2);
      FUN_000e94da(iVar3);
      FUN_000e94da(iVar6);
      param_2 = piVar1;
    }
  }
  return param_2;
}

/* FUN_0013313c @ 0x13313c (58 bytes) */
int FUN_0013313c(param_1)
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
    if (((*(byte *)(iVar1 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar1 + 0x88) + 8) == 0x77))
    break;
    iVar1 = *(int *)(iVar1 + 8);
    iVar2 = *(int *)(iVar1 + 8);
  }
  return 1;
}

/* FUN_00133176 @ 0x133176 (340 bytes) */
int FUN_00133176(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  char cVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  float fVar6;
  float fVar7;
  
  cVar2 = FUN_000eacec(param_2);
  if (cVar2 != '\0') {
    iVar3 = *(int *)(param_2 + 300);
    iVar1 = *(int *)(param_2 + 0x130);
    cVar2 = ((int (*)())FUN_0013313c)(iVar3);
    if ((cVar2 == '\0') && (cVar2 = ((int (*)())FUN_0013313c)(iVar1), cVar2 == '\0')) {
      cVar2 = FUN_000e144e(param_3,0,3);
      if (cVar2 == '\0') {
        if ((*(byte *)(param_2 + 0xd) & 8) == 0) {
          cVar2 = ((int (*)())FUN_001321a2)(iVar3);
          if (cVar2 != '\0') {
            return 0;
          }
          cVar2 = ((int (*)())FUN_001321a2)(iVar1);
          if (cVar2 != '\0') {
            return 0;
          }
          iVar3 = FUN_001a7d8a(iVar3 + 0x90);
          fVar6 = (float)iVar3 - FLOAT_001c5bd0;
          iVar3 = FUN_001a7d8a(iVar1 + 0x90);
          fVar7 = (float)iVar3 - FLOAT_001c5bd0;
          if ((float)iVar3 - FLOAT_001c5bd0 < fVar6) {
            fVar7 = fVar6;
          }
          bVar5 = fVar7 == FLOAT_001c5c64;
          bVar4 = fVar7 < FLOAT_001c5c64;
          if (NAN(fVar7) || NAN(FLOAT_001c5c64)) {
            return 0;
          }
        }
        else {
          iVar3 = FUN_001a7d8a(iVar3 + 0x90);
          fVar7 = (float)iVar3 - FLOAT_001c5bd0;
          iVar3 = FUN_001a7d8a(iVar1 + 0x90);
          if (fVar7 <= (float)iVar3 - FLOAT_001c5bd0) {
            fVar7 = (float)iVar3 - FLOAT_001c5bd0;
          }
          bVar5 = fVar7 == FLOAT_001c5c64;
          bVar4 = fVar7 < FLOAT_001c5c64;
          if (NAN(fVar7) || NAN(FLOAT_001c5c64)) {
            return 0;
          }
        }
        if (!bVar4 && !bVar5) {
          return 0;
        }
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_001332ca @ 0x1332ca (335 bytes) */
int FUN_001332ca(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  byte bVar1;
  
  switch(*(undefined4 *)(param_1 + 300)) {
  case 0:
    FUN_00109c0e(param_2 + 0xa4,2,1);
    goto LAB_001333a0;
  case 1:
    FUN_00109c0e(param_2 + 0xa4,2,1);
    bVar1 = *(byte *)(param_2 + 0xb8);
    break;
  case 2:
    bVar1 = *(byte *)(param_2 + 0xb8);
    break;
  default:
    goto switchD_001332fc_caseD_3;
  case 4:
    FUN_0010fe82(param_2,2,3,param_3);
    return;
  case 5:
LAB_001333a0:
    FUN_00109c0e();
    return;
  }
  FUN_00109c0e(param_2 + 0xa4,1,bVar1 & 1 ^ 1);
  FUN_0010fe82(param_2,2,3,param_3);
switchD_001332fc_caseD_3:
  return;
}

/* FUN_00133434 @ 0x133434 (223 bytes) */
int FUN_00133434(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if ((0 < *(int *)(param_2 + 0x130)) || (*(char *)(param_2 + 0x134) != '\0')) {
    iVar2 = FUN_000eac7c(param_2,0);
    iVar3 = FUN_001a7d8a(iVar2 + 0x90);
    if (iVar3 < 3) {
      piVar4 = (int *)FUN_000eac7c(iVar2,0);
      cVar1 = (**(code **)(*piVar4 + 0x24))(piVar4);
      if (cVar1 != '\0') {
        iVar2 = FUN_000eac7c(iVar2,0);
        iVar3 = FUN_000e9644(iVar2);
        if ((((*(byte *)(param_1 + 0x30) & 8) == 0) && (*(int *)(iVar3 + 0x84) == 2)) &&
           (*(int *)(iVar3 + 0xa4) == *(int *)(iVar3 + 0xbc))) {
          piVar4 = (int *)FUN_000eac7c(*(undefined4 *)(iVar2 + 300),0);
          cVar1 = (**(code **)(*piVar4 + 0x38))(piVar4);
          if (cVar1 != '\0') {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_00133514 @ 0x133514 (752 bytes) */
int FUN_00133514(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  undefined4 param_3;
  int *param_4;
{
  int iVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int local_3c;
  int local_30;
  uint local_20;
  uint local_1c;
  int local_18;
  undefined4 local_14;
  int *local_10;
  
  local_14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_1c = 0;
  local_20 = 2;
  local_18 = FUN_001a7bca(local_14,8);
  uVar8 = local_1c;
  if (local_1c < local_20) {
    iVar1 = local_1c * 4;
    _memset((void *)(local_18 + iVar1),0,4);
    local_1c = uVar8 + 1;
    puVar7 = (undefined4 *)(iVar1 + local_18);
  }
  else {
    puVar7 = (undefined4 *)FUN_001a7f7c(&local_20,local_1c);
  }
  *puVar7 = param_3;
LAB_0013358f:
  if (local_1c != 0) {
    do {
      uVar8 = local_1c - 1;
      if (uVar8 < local_1c) {
        piVar4 = (int *)(local_18 + uVar8 * 4);
      }
      else {
        piVar4 = (int *)0x0;
      }
      iVar1 = *piVar4;
      FUN_001a7f3c(&local_20,uVar8);
      piVar4 = *(int **)(iVar1 + 0x98);
      iVar6 = piVar4[2];
      while (iVar6 != 0) {
        while ((((*(byte *)(piVar4 + 5) & 1) == 0 ||
                (cVar3 = (**(code **)(*piVar4 + 0x34))(piVar4), cVar3 != '\0')) ||
               (cVar3 = (**(code **)(*piVar4 + 0x38))(piVar4), cVar3 != '\0'))) {
          piVar4 = (int *)piVar4[2];
          if (piVar4[2] == 0) goto LAB_00133664;
        }
        if (*(int *)(piVar4[0x22] + 8) != 0x8e) {
          piVar5 = piVar4;
          for (local_3c = 1; iVar6 = (**(code **)(*piVar4 + 0x14))(piVar4), local_3c <= iVar6;
              local_3c = local_3c + 1) {
            FUN_0012a842(piVar5[0x29],piVar4);
            piVar5 = piVar5 + 6;
          }
        }
        (**(code **)(*piVar4 + 0xc))(piVar4,0,*(undefined4 *)(param_1 + 8));
        piVar4 = (int *)piVar4[2];
        iVar6 = piVar4[2];
      }
LAB_00133664:
      local_10 = (int *)0x0;
      uVar8 = 1;
      local_30 = 0;
      iVar6 = *(int *)(iVar1 + 0xd0);
      if (*(int *)(iVar6 + 4) == 0) goto LAB_0013358f;
      do {
        local_10 = *(int **)(*(int *)(iVar6 + 8) + local_30);
        if ((((local_10 != (int *)0x0) && (local_10 != param_4)) &&
            ((local_10 != param_2 &&
             ((cVar3 = (**(code **)(*local_10 + 0x38))(local_10), cVar3 == '\0' &&
              (cVar3 = (**(code **)(*local_10 + 0x3c))(local_10), cVar3 == '\0')))))) &&
           (iVar6 = FUN_001a7d8a(local_10 + 0x24), piVar4 = local_10, uVar2 = local_1c, 2 < iVar6))
        {
          if (local_1c < local_20) {
            iVar6 = local_1c * 4;
            _memset((void *)(iVar6 + local_18),0,4);
            local_1c = uVar2 + 1;
            *(int **)(iVar6 + local_18) = piVar4;
          }
          else {
            piVar5 = (int *)FUN_001a7f7c(&local_20,local_1c);
            *piVar5 = (int)piVar4;
          }
        }
        uVar8 = uVar8 + 1;
        local_30 = local_30 + 4;
        iVar6 = *(int *)(iVar1 + 0xd0);
      } while (uVar8 <= *(uint *)(iVar6 + 4));
      if (local_1c == 0) break;
    } while( true );
  }
  piVar4 = (int *)param_4[0x26];
  iVar1 = piVar4[2];
  while (iVar1 != 0) {
    while (((*(byte *)(piVar4 + 5) & 1) == 0 ||
           (piVar5 = (int *)(**(code **)(*piVar4 + 0x7c))(piVar4), piVar5 == (int *)0x0))) {
      piVar4 = (int *)piVar4[2];
      if (piVar4[2] == 0) goto LAB_00133727;
    }
    (**(code **)(*piVar5 + 0xc))(piVar5,0,*(undefined4 *)(param_1 + 8));
    piVar4 = (int *)piVar4[2];
    iVar1 = piVar4[2];
  }
LAB_00133727:
  FUN_001a7d8a(param_4 + 0x24);
  FUN_001a7aba(local_14,local_18);
  return;
}

/* FUN_00133820 @ 0x133820 (524 bytes) */
int FUN_00133820(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint uVar6;
  int local_30;
  uint local_20;
  uint local_1c;
  undefined4 *local_18;
  undefined4 local_14;
  int local_10;
  
  *(int *)(param_1 + 0x468) = *(int *)(param_1 + 0x468) + 1;
  local_14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_1c = 0;
  local_20 = 2;
  local_18 = (undefined4 *)FUN_001a7bca(local_14,8);
  iVar2 = FUN_000eac0c(param_2,0);
  FUN_001a805e(*(undefined4 *)(iVar2 + 0xd0),param_2);
  iVar3 = FUN_000eac7c(param_3,0);
  FUN_001a805e(*(undefined4 *)(iVar3 + 0xd4),param_3);
  FUN_000ea91c(iVar2,iVar3);
  while( true ) {
    local_10 = 0;
    uVar6 = 1;
    local_30 = 0;
    iVar2 = param_2[0x34];
    if (*(int *)(iVar2 + 4) != 0) {
      do {
        local_10 = *(int *)(*(int *)(iVar2 + 8) + local_30);
        if (((local_10 != 0) && (*(int *)(param_1 + 0x468) != *(int *)(local_10 + 0x110))) &&
           (param_3 != local_10)) {
          *(int *)(local_10 + 0x110) = *(int *)(param_1 + 0x468);
          if (local_1c < local_20) {
            local_18[local_1c] = 0;
            piVar4 = local_18 + local_1c;
            local_1c = local_1c + 1;
          }
          else {
            piVar4 = (int *)FUN_001a7f7c(&local_20,local_1c);
          }
          *piVar4 = local_10;
        }
        uVar6 = uVar6 + 1;
        local_30 = local_30 + 4;
        iVar2 = param_2[0x34];
      } while (uVar6 <= *(uint *)(iVar2 + 4));
    }
    cVar1 = (**(code **)(*param_2 + 0x24))(param_2);
    if ((cVar1 != '\0') && (piVar4 = (int *)FUN_000e9644(param_2), piVar4 != (int *)0x0)) {
      FUN_000f1b60(param_1,piVar4);
      (**(code **)(*piVar4 + 0xc))
                (piVar4,*(uint *)(param_1 + 0x30) >> 7 & 1,*(undefined4 *)(param_1 + 8));
      param_2[0x4a] = 0;
    }
    FUN_000e94da(param_2);
    if (local_1c == 0) break;
    puVar5 = local_18;
    if (local_20 == 0) {
      puVar5 = (undefined4 *)FUN_001a7f7c(&local_20,0);
    }
    param_2 = (int *)*puVar5;
    if ((param_2 == (int *)0x0) || (cVar1 = FUN_001a805e(&local_20,param_2), cVar1 == '\0')) break;
  }
  FUN_000e94da(param_3);
  FUN_001a7aba(local_14,local_18);
  return;
}

/* FUN_00133a48 @ 0x133a48 (1578 bytes) */
int FUN_00133a48(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int *param_3;
  int *param_4;
  int *param_5;
{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int local_48;
  uint local_34;
  int local_30;
  uint local_20;
  uint local_1c;
  int local_18;
  undefined4 local_14;
  int *local_10;
  
  if (param_2[0x50] == 1) {
    local_48 = param_2[0x4c];
  }
  else {
    local_48 = param_2[0x4b];
  }
  *(int *)(param_1 + 0x468) = *(int *)(param_1 + 0x468) + 1;
  local_14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_1c = 0;
  local_20 = 2;
  local_18 = FUN_001a7bca(local_14,8);
  uVar5 = local_1c;
  if (local_1c < local_20) {
    iVar10 = local_1c * 4;
    _memset((void *)(local_18 + iVar10),0,4);
    local_1c = uVar5 + 1;
    piVar4 = (int *)(iVar10 + local_18);
  }
  else {
    piVar4 = (int *)FUN_001a7f7c(&local_20,local_1c);
  }
  *piVar4 = local_48;
  *(undefined4 *)(local_48 + 0x110) = *(undefined4 *)(param_1 + 0x468);
  do {
    if (local_1c == 0) {
      piVar4 = (int *)FUN_000e9644(param_2);
      param_2[0x4a] = 0;
      FUN_000f1b60(param_1,piVar4);
      (**(code **)(*piVar4 + 0xc))(piVar4,0,*(undefined4 *)(param_1 + 8));
      FUN_001a7d8a(param_2 + 0x24);
      iVar7 = FUN_000e9b0e(param_2);
      iVar8 = FUN_000e9b7c(param_3);
      iVar10 = param_2[0x50];
      iVar9 = FUN_000eac7c(param_2,iVar10 != 1);
      *param_4 = iVar9;
      piVar4 = *(int **)(iVar9 + 0xd4);
      if (*piVar4 == 0) {
        piVar4 = (int *)FUN_001a7f7c(piVar4,0);
        *piVar4 = iVar7;
        piVar4 = *(int **)(iVar7 + 0xd0);
        iVar7 = *piVar4;
      }
      else {
        if (piVar4[1] == 0) {
          *(undefined4 *)piVar4[2] = 0;
          piVar4[1] = 1;
        }
        *(int *)piVar4[2] = iVar7;
        piVar4 = *(int **)(iVar7 + 0xd0);
        iVar7 = *piVar4;
      }
      if (iVar7 == 0) {
        piVar4 = (int *)FUN_001a7f7c(piVar4,0);
      }
      else {
        if (piVar4[1] == 0) {
          *(undefined4 *)piVar4[2] = 0;
          piVar4[1] = 1;
        }
        piVar4 = (int *)piVar4[2];
      }
      *piVar4 = *param_4;
      iVar10 = FUN_000eac0c(param_3,iVar10 != 1);
      *param_5 = iVar10;
      piVar4 = *(int **)(iVar10 + 0xd0);
      if (*piVar4 == 0) {
        piVar4 = (int *)FUN_001a7f7c(piVar4,0);
        *piVar4 = iVar8;
        piVar4 = *(int **)(iVar8 + 0xd4);
        iVar10 = *piVar4;
      }
      else {
        if (piVar4[1] == 0) {
          *(undefined4 *)piVar4[2] = 0;
          piVar4[1] = 1;
        }
        *(int *)piVar4[2] = iVar8;
        piVar4 = *(int **)(iVar8 + 0xd4);
        iVar10 = *piVar4;
      }
      if (iVar10 == 0) {
        piVar4 = (int *)FUN_001a7f7c(piVar4,0);
      }
      else {
        if (piVar4[1] == 0) {
          *(undefined4 *)piVar4[2] = 0;
          piVar4[1] = 1;
        }
        piVar4 = (int *)piVar4[2];
      }
      *piVar4 = *param_5;
      FUN_000e94da(param_2);
      FUN_000e94da(param_3);
      FUN_000edb74(param_1);
      FUN_001a7aba(local_14,local_18);
      return;
    }
    uVar5 = local_1c - 1;
    if (uVar5 < local_1c) {
      piVar4 = (int *)(local_18 + uVar5 * 4);
    }
    else {
      piVar4 = (int *)0x0;
    }
    piVar4 = (int *)*piVar4;
    FUN_001a7f3c(&local_20,uVar5);
    cVar3 = (**(code **)(*piVar4 + 0x38))(piVar4);
    if ((cVar3 == '\0') && (cVar3 = (**(code **)(*piVar4 + 0x3c))(piVar4), cVar3 == '\0')) {
      local_10 = (int *)0x0;
      local_34 = 1;
      local_30 = 0;
      iVar10 = piVar4[0x34];
      if (*(int *)(iVar10 + 4) != 0) {
        do {
          local_10 = *(int **)(local_30 + *(int *)(iVar10 + 8));
          if ((((local_10 != (int *)0x0) && (*(int *)(param_1 + 0x468) != local_10[0x44])) &&
              (local_10 != param_3)) && (local_10 != param_2)) {
            cVar3 = (**(code **)(*local_10 + 0x38))(local_10);
            if (cVar3 == '\0') {
              cVar3 = (**(code **)(*local_10 + 0x3c))(local_10);
              if (cVar3 != '\0') {
                piVar11 = (int *)local_10[0x34];
                if (*piVar11 == 0) {
                  piVar11 = (int *)FUN_001a7f7c(piVar11,0);
                }
                else {
                  if (piVar11[1] == 0) {
                    *(undefined4 *)piVar11[2] = 0;
                    piVar11[1] = 1;
                  }
                  piVar11 = (int *)piVar11[2];
                }
                iVar10 = *piVar11;
                uVar5 = FUN_000e9c3e(iVar10,local_10);
                puVar1 = *(uint **)(iVar10 + 0xd4);
                if (uVar5 < *puVar1) {
                  uVar2 = puVar1[1];
                  if (uVar2 <= uVar5) {
                    _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar5 - uVar2) * 4 + 4);
                    puVar1[1] = uVar5 + 1;
                  }
                  puVar6 = (undefined4 *)(puVar1[2] + uVar5 * 4);
                }
                else {
                  puVar6 = (undefined4 *)FUN_001a7f7c(puVar1,uVar5);
                }
                goto LAB_00133c0b;
              }
            }
            else {
              piVar11 = (int *)local_10[0x34];
              if (*piVar11 == 0) {
                piVar11 = (int *)FUN_001a7f7c(piVar11,0);
              }
              else {
                if (piVar11[1] == 0) {
                  *(undefined4 *)piVar11[2] = 0;
                  piVar11[1] = 1;
                }
                piVar11 = (int *)piVar11[2];
              }
              iVar10 = *piVar11;
              uVar5 = FUN_000e9c3e(iVar10,local_10);
              puVar1 = *(uint **)(iVar10 + 0xd4);
              if (uVar5 < *puVar1) {
                uVar2 = puVar1[1];
                if (uVar2 <= uVar5) {
                  _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar5 - uVar2) * 4 + 4);
                  puVar1[1] = uVar5 + 1;
                }
                puVar6 = (undefined4 *)(puVar1[2] + uVar5 * 4);
              }
              else {
                puVar6 = (undefined4 *)FUN_001a7f7c(puVar1,uVar5);
              }
LAB_00133c0b:
              *puVar6 = 0;
            }
            piVar11 = local_10;
            uVar5 = local_1c;
            local_10[0x44] = *(int *)(param_1 + 0x468);
            if (local_1c < local_20) {
              iVar10 = local_1c * 4;
              _memset((void *)(iVar10 + local_18),0,4);
              local_1c = uVar5 + 1;
              puVar6 = (undefined4 *)(iVar10 + local_18);
            }
            else {
              puVar6 = (undefined4 *)FUN_001a7f7c(&local_20,local_1c);
            }
            *puVar6 = piVar11;
          }
          local_34 = local_34 + 1;
          local_30 = local_30 + 4;
          iVar10 = piVar4[0x34];
        } while (local_34 <= *(uint *)(iVar10 + 4));
      }
    }
    FUN_001a7d8a(piVar4 + 0x24);
    FUN_000e94da(piVar4);
  } while( true );
}

/* FUN_0013408e @ 0x13408e (193 bytes) */
int FUN_0013408e(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  puVar4 = (undefined4 *)FUN_000eac7c(param_2,0);
  iVar5 = FUN_001a7d8a(puVar4 + 0x24);
  if ((iVar5 < 3) && (cVar3 = FUN_000e95be(puVar4), cVar3 != '\0')) {
    return puVar4;
  }
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar6 = (undefined4 *)FUN_001a7bca(uVar2,0x128);
  *puVar6 = uVar2;
  puVar1 = puVar6 + 1;
  FUN_000eb992(puVar1,*(undefined4 *)(param_1 + 8));
  puVar6[0x2f] = *(undefined4 *)(param_2 + 0xb8);
  FUN_000edc32(param_1,param_2,puVar1);
  FUN_000eb12a(param_2,puVar4,puVar1);
  FUN_000ea91c(puVar1,puVar4);
  return puVar1;
}

/* FUN_0013416c @ 0x13416c (830 bytes) */
int FUN_0013416c(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  
  cVar5 = (**(code **)(*param_2 + 0x30))(param_2);
  if (cVar5 == '\0') {
    return;
  }
  uVar2 = *(undefined4 *)(param_3 + 0x3f4);
  iVar3 = param_2[0x49];
  uVar4 = *(undefined4 *)(param_3 + 0xb8);
  puVar6 = (undefined4 *)FUN_001a7bca(uVar4,0x168);
  *puVar6 = uVar4;
  puVar7 = puVar6 + 1;
  FUN_0010ac30(puVar7,0x8c,param_3);
  puVar6[0x4c] = 6;
  iVar8 = FUN_0010b0f4(puVar7,1);
  *(undefined4 *)(iVar8 + 8) = param_1;
  *(undefined4 *)(iVar8 + 0xc) = 0;
  uVar4 = *(undefined4 *)PTR_DAT_00213485;
  iVar8 = FUN_0010b0f4(puVar7,1);
  *(undefined4 *)(iVar8 + 0x10) = uVar4;
  uVar4 = *(undefined4 *)(iVar3 + 0xb8);
  uVar9 = FUN_000eac7c(iVar3,0);
  uVar11 = *(undefined4 *)(param_3 + 0xb8);
  puVar6 = (undefined4 *)FUN_001a7bca(uVar11,0x128);
  *puVar6 = uVar11;
  puVar10 = puVar6 + 1;
  FUN_000eb992(puVar10,param_3);
  puVar6[0x2f] = uVar4;
  FUN_000edc32(uVar2,iVar3,puVar10);
  FUN_000eb12a(iVar3,uVar9,puVar10);
  uVar11 = ((int (*)())FUN_0013237e)(iVar3);
  uVar4 = *(undefined4 *)(param_3 + 0xb8);
  puVar12 = (undefined4 *)FUN_001a7bca(uVar4,0x128);
  *puVar12 = uVar4;
  puVar12 = puVar12 + 1;
  FUN_000eb992(puVar12,param_3);
  uVar4 = *(undefined4 *)(param_3 + 0xb8);
  puVar13 = (undefined4 *)FUN_001a7bca(uVar4,0x130);
  *puVar13 = uVar4;
  puVar13 = puVar13 + 1;
  FUN_000ed9bc(puVar13,iVar3,1,param_3);
  uVar4 = *(undefined4 *)(param_3 + 0xb8);
  puVar14 = (undefined4 *)FUN_001a7bca(uVar4,0x150);
  *puVar14 = uVar4;
  puVar6 = puVar14 + 1;
  FUN_000ec126(puVar6,puVar7,uVar11,puVar12,param_3);
  uVar4 = *(undefined4 *)(param_3 + 0xb8);
  puVar15 = (undefined4 *)FUN_001a7bca(uVar4,300);
  *puVar15 = uVar4;
  puVar1 = puVar15 + 1;
  FUN_000ebb06(puVar1,param_3);
  *puVar1 = PTR_DAT_00213a29 + 8;
  puVar15[0x4a] = puVar6;
  puVar14[0x4c] = puVar12;
  puVar14[0x4d] = puVar13;
  puVar14[0x4e] = puVar1;
  FUN_000edc32(uVar2,puVar10,puVar6);
  FUN_000edc32(uVar2,puVar6,puVar12);
  FUN_000edc32(uVar2,puVar12,puVar13);
  FUN_000edc32(uVar2,puVar13,puVar1);
  FUN_000ea91c(puVar10,puVar6);
  FUN_000ea91c(puVar6,puVar12);
  FUN_000ea91c(puVar6,puVar13);
  FUN_000ea91c(puVar12,puVar1);
  FUN_000ea91c(puVar13,*(undefined4 *)(iVar3 + 0x144));
  FUN_000ea91c(puVar1,uVar9);
  FUN_000f0144(uVar2,puVar7);
  return;
}

/* FUN_0013455c @ 0x13455c (438 bytes) */
int FUN_0013455c(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  
  piVar4 = param_2;
  do {
    if (piVar4 == param_3) {
      return;
    }
    piVar4 = (int *)FUN_000eac7c(param_2,0);
    cVar3 = ((int (*)())FUN_001321e6)(param_1,param_2,piVar4);
    if (cVar3 == '\0') {
      param_2 = (int *)param_2[2];
    }
    cVar3 = (**(code **)(*param_2 + 0x28))(param_2);
    if (((cVar3 != '\0') || (cVar3 = (**(code **)(*param_2 + 0x34))(param_2), cVar3 != '\0')) &&
       (iVar5 = FUN_000e9b7c(param_2), iVar5 == 0)) {
      uVar6 = FUN_000eac7c(param_2,0);
      uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
      puVar7 = (undefined4 *)FUN_001a7bca(uVar2,0x128);
      *puVar7 = uVar2;
      puVar1 = puVar7 + 1;
      FUN_000eb992(puVar1,*(undefined4 *)(param_1 + 8));
      puVar7[0x2f] = param_2[0x2e];
      FUN_000edc32(param_1,param_2,puVar1);
      FUN_000eb3ec(param_2,uVar6,puVar1);
    }
    cVar3 = (**(code **)(*param_2 + 0x24))(param_2);
    if (((cVar3 != '\0') || (cVar3 = (**(code **)(*param_2 + 0x2c))(param_2), cVar3 != '\0')) &&
       (iVar5 = FUN_000e9b0e(param_2), iVar5 == 0)) {
      uVar6 = FUN_000eac0c(param_2,0);
      uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
      puVar7 = (undefined4 *)FUN_001a7bca(uVar2,0x128);
      *puVar7 = uVar2;
      puVar1 = puVar7 + 1;
      FUN_000eb992(puVar1,*(undefined4 *)(param_1 + 8));
      puVar7[0x2f] = param_2[0x2e];
      FUN_000edc00(param_1,param_2,puVar1);
      FUN_000eb3ec(uVar6,param_2,puVar1);
    }
  } while (param_2 != param_3);
  return;
}

/* FUN_00134746 @ 0x134746 (451 bytes) */
int FUN_00134746(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *local_10;
  
  local_10 = param_1;
  iVar4 = 1;
  do {
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar2 < iVar4) {
      iVar4 = (**(code **)(*param_1 + 0x18))(param_1);
      if (iVar4 == 1) {
        iVar4 = FUN_0010b7c8(param_1,0);
        if (iVar4 == 1) {
          iVar4 = FUN_0010b6e4(param_1,0);
          piVar3 = (int *)FUN_0012eb84(*(undefined4 *)(param_3 + 0x3a0),0x24,iVar4 + param_2,0);
          pcVar1 = *(code **)(*piVar3 + 0x28);
          iVar4 = FUN_0010b0f4(param_1,0);
          uVar5 = (*pcVar1)(piVar3,*(undefined4 *)(iVar4 + 0x10),param_3);
          FUN_0010a3c2(param_1,0,uVar5);
          if ((param_1[5] & 2U) == 0) {
            param_1[5] = param_1[5] & 0xffffffef;
            FUN_000f1b60();
            return;
          }
        }
      }
      return;
    }
    iVar2 = FUN_0010b7c8(param_1,iVar4);
    if (iVar2 == 1) {
      iVar2 = FUN_0010b6e4(param_1,iVar4);
      if (local_10[0x2c] == 0x28) {
        uVar5 = 2;
      }
      else {
        if (local_10[0x2c] != 0x29) goto LAB_00134767;
        if ((*(uint *)(param_3 + 0x30) & 1) == 0) {
          if ((*(uint *)(param_3 + 0x30) & 0x2000) == 0) goto LAB_00134767;
          uVar5 = 0x24;
        }
        else {
          uVar5 = FUN_000edadc(param_3,5);
        }
      }
      uVar5 = FUN_0012eb84(*(undefined4 *)(param_3 + 0x3a0),uVar5,iVar2 + param_2,0);
      FUN_0010a3c2(param_1,iVar4,uVar5);
    }
LAB_00134767:
    iVar4 = iVar4 + 1;
    local_10 = local_10 + 6;
  } while( true );
}

/* FUN_0013490a @ 0x13490a (3209 bytes) */
int FUN_0013490a(param_1)
  int param_1;
{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  bool bVar9;
  int *piVar10;
  undefined4 uVar11;
  int *piVar12;
  char cVar13;
  int *piVar14;
  int iVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int iVar18;
  int *piVar19;
  uint *puVar20;
  undefined4 local_a0;
  int *local_98;
  int local_84;
  int *local_80;
  byte local_7c;
  byte local_6c;
  int *local_50;
  int local_44;
  char cStack_29;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_1d [13];
  
  piVar14 = (int *)(*(int **)(param_1 + 0x378))[2];
  if (piVar14 != (int *)0x0) {
    bVar9 = false;
    local_98 = *(int **)(param_1 + 0x378);
    do {
      piVar19 = piVar14;
      cVar13 = (**(code **)(*local_98 + 0x28))(local_98);
      if ((cVar13 != '\0') && (cVar13 = (**(code **)(*local_98 + 0x40))(local_98), cVar13 == '\0'))
      {
        iVar15 = *(int *)(param_1 + 8);
        if (*(int *)(iVar15 + 0x3dc) <= *(int *)(*(int *)(iVar15 + 0x3f4) + 0x15c)) break;
        iVar18 = local_98[0x49];
        cVar13 = (**(code **)(**(int **)(iVar15 + 0x54) + 0x114))
                           (*(int **)(iVar15 + 0x54),iVar18,iVar15);
        if ((cVar13 == '\0') || (cVar13 = FUN_000ea2e0(iVar18,local_1d), cVar13 != '\0')) break;
        iVar15 = *(int *)(iVar18 + 300);
        iVar1 = *(int *)(iVar18 + 0x130);
        puVar2 = (uint *)local_98[0x35];
        if (*puVar2 == 0) {
          piVar14 = (int *)FUN_001a7f7c(puVar2,0);
          puVar20 = (uint *)local_98[0x35];
        }
        else {
          puVar20 = puVar2;
          if (puVar2[1] == 0) {
            *(undefined4 *)puVar2[2] = 0;
            puVar2[1] = 1;
            puVar20 = (uint *)local_98[0x35];
          }
          piVar14 = (int *)puVar2[2];
        }
        iVar3 = *piVar14;
        if (*puVar20 < 2) {
          piVar14 = (int *)FUN_001a7f7c(puVar20,1);
        }
        else {
          uVar4 = puVar20[1];
          if (uVar4 < 2) {
            _memset((void *)(puVar20[2] + uVar4 * 4),0,(1 - uVar4) * 4 + 4);
            puVar20[1] = 2;
          }
          piVar14 = (int *)(puVar20[2] + 4);
        }
        iVar5 = *piVar14;
        piVar14 = *(int **)(iVar18 + 0xd4);
        if (*piVar14 == 0) {
          piVar14 = (int *)FUN_001a7f7c(piVar14,0);
        }
        else {
          if (piVar14[1] == 0) {
            *(undefined4 *)piVar14[2] = 0;
            piVar14[1] = 1;
          }
          piVar14 = (int *)piVar14[2];
        }
        iVar6 = *piVar14;
        piVar14 = (int *)local_98[0x34];
        if (*piVar14 == 0) {
          piVar14 = (int *)FUN_001a7f7c(piVar14,0);
          local_84 = *piVar14;
          piVar14 = *(int **)(iVar6 + 0xd0);
          if (*piVar14 == 0) goto LAB_00135115;
LAB_00134ab5:
          if (piVar14[1] == 0) {
            *(undefined4 *)piVar14[2] = 0;
            piVar14[1] = 1;
          }
          *(int *)piVar14[2] = iVar15;
          piVar14 = *(int **)(iVar15 + 0xd4);
          if (*piVar14 != 0) goto LAB_00134ae1;
LAB_00135143:
          piVar14 = (int *)FUN_001a7f7c(piVar14,0);
          *piVar14 = iVar6;
          piVar14 = *(int **)(local_84 + 0xd4);
          if (*piVar14 == 0) goto LAB_0013516e;
LAB_00134b0a:
          if (piVar14[1] == 0) {
            *(undefined4 *)piVar14[2] = 0;
            piVar14[1] = 1;
          }
          *(int *)piVar14[2] = iVar5;
          piVar14 = *(int **)(iVar5 + 0xd0);
          if (*piVar14 != 0) goto LAB_00134b2a;
LAB_00135190:
          piVar14 = (int *)FUN_001a7f7c(piVar14,0);
          *piVar14 = local_84;
          piVar14 = *(int **)(iVar3 + 0xd0);
          if (*piVar14 == 0) goto LAB_001351b5;
LAB_00134b4d:
          if (piVar14[1] == 0) {
            *(undefined4 *)piVar14[2] = 0;
            piVar14[1] = 1;
          }
          *(int *)piVar14[2] = iVar1;
          piVar14 = *(int **)(iVar1 + 0xd4);
          if (*piVar14 != 0) goto LAB_00134b73;
LAB_001351dd:
          piVar14 = (int *)FUN_001a7f7c(piVar14,0);
        }
        else {
          if (piVar14[1] == 0) {
            *(undefined4 *)piVar14[2] = 0;
            piVar14[1] = 1;
          }
          local_84 = *(int *)piVar14[2];
          piVar14 = *(int **)(iVar6 + 0xd0);
          if (*piVar14 != 0) goto LAB_00134ab5;
LAB_00135115:
          piVar14 = (int *)FUN_001a7f7c(piVar14,0);
          *piVar14 = iVar15;
          piVar14 = *(int **)(iVar15 + 0xd4);
          if (*piVar14 == 0) goto LAB_00135143;
LAB_00134ae1:
          if (piVar14[1] == 0) {
            *(undefined4 *)piVar14[2] = 0;
            piVar14[1] = 1;
          }
          *(int *)piVar14[2] = iVar6;
          piVar14 = *(int **)(local_84 + 0xd4);
          if (*piVar14 != 0) goto LAB_00134b0a;
LAB_0013516e:
          piVar14 = (int *)FUN_001a7f7c(piVar14,0);
          *piVar14 = iVar5;
          piVar14 = *(int **)(iVar5 + 0xd0);
          if (*piVar14 == 0) goto LAB_00135190;
LAB_00134b2a:
          if (piVar14[1] == 0) {
            *(undefined4 *)piVar14[2] = 0;
            piVar14[1] = 1;
          }
          *(int *)piVar14[2] = local_84;
          piVar14 = *(int **)(iVar3 + 0xd0);
          if (*piVar14 != 0) goto LAB_00134b4d;
LAB_001351b5:
          piVar14 = (int *)FUN_001a7f7c(piVar14,0);
          *piVar14 = iVar1;
          piVar14 = *(int **)(iVar1 + 0xd4);
          if (*piVar14 == 0) goto LAB_001351dd;
LAB_00134b73:
          if (piVar14[1] == 0) {
            *(undefined4 *)piVar14[2] = 0;
            piVar14[1] = 1;
          }
          piVar14 = (int *)piVar14[2];
        }
        *piVar14 = iVar3;
        *(int *)(iVar15 + 0xec) = iVar6;
        *(int *)(iVar1 + 0xec) = iVar3;
        *(int *)(local_84 + 0xec) = iVar5;
        piVar14 = (int *)FUN_000e9644(iVar18);
        if (*(int *)(piVar14[0x22] + 8) == 0x8b) {
          cVar13 = FUN_0011062e(piVar14,2);
          if (cVar13 == '\0') {
            cVar13 = FUN_0011062e(piVar14,1);
            if (cVar13 == '\0') {
              local_80 = (int *)FUN_0010a17a(0x12,*(undefined4 *)(param_1 + 8));
              local_80[0x25] = local_80[0x53];
              local_80[0x26] = 0;
              uVar16 = *(undefined4 *)(param_1 + 8);
              uVar17 = FUN_0010b0f4(piVar14,1);
              FUN_0010bc9c(local_80,1,uVar17,uVar16);
              uVar16 = *(undefined4 *)(param_1 + 8);
              uVar17 = FUN_0010b0f4(piVar14,2);
              FUN_0010bc9c(local_80,2,uVar17,uVar16);
              FUN_00109c0e(local_80 + 0x2f,1,*(byte *)(piVar14 + 0x34) & 1 ^ 1);
              FUN_000e9540(local_84,local_80);
              FUN_0010b908(local_80,param_1);
              local_a0 = DAT_001cc520;
              local_44 = 1;
              while (iVar15 = (**(code **)(*local_80 + 0x14))(local_80), local_44 <= iVar15) {
                piVar19 = (int *)FUN_0010b180(local_80,local_44);
                cVar13 = (**(code **)(*piVar19 + 0x5c))(piVar19);
                if (cVar13 == '\0') {
                  local_44 = local_44 + 1;
                }
                else {
                  FUN_001a7d72(piVar19);
                  FUN_000e956e(local_84,local_80,piVar19);
                  local_44 = local_44 + 1;
                }
              }
              local_7c = 0;
              local_6c = 0;
              local_50 = local_80;
            }
            else {
              local_50 = *(int **)(local_84 + 200);
              local_80 = (int *)FUN_0010b180(piVar14,2);
              iVar15 = FUN_0010b0f4(piVar14,2);
              local_a0 = *(undefined4 *)(iVar15 + 0x10);
              local_7c = (byte)piVar14[0x34] & 1;
              local_6c = (byte)((uint)piVar14[0x34] >> 1) & 1;
              iVar15 = FUN_0011074c(piVar14);
              FUN_00110a08(piVar14,*(undefined4 *)(PTR_DAT_002139fd + iVar15 * 4));
            }
          }
          else {
            local_50 = *(int **)(local_84 + 200);
            local_80 = (int *)FUN_0010b180(piVar14,1);
            iVar15 = FUN_0010b0f4(piVar14,1);
            local_a0 = *(undefined4 *)(iVar15 + 0x10);
            local_7c = (byte)piVar14[0x2e] & 1;
            local_6c = (byte)((uint)piVar14[0x2e] >> 1) & 1;
          }
        }
        else {
          local_50 = *(int **)(local_84 + 200);
          local_80 = (int *)FUN_0010b180(piVar14,1);
          iVar15 = FUN_0010b0f4(piVar14,1);
          local_a0 = *(undefined4 *)(iVar15 + 0x10);
          local_7c = *(byte *)(piVar14 + 0x2e) & 1 ^ 1;
          iVar15 = *(int *)(local_80[0x22] + 8);
          if ((((iVar15 == 0x27) || (iVar15 == 0x29)) || (iVar15 == 0x2a)) || (iVar15 == 0x28)) {
            local_6c = 0;
          }
          else {
            local_6c = 1;
          }
        }
        piVar12 = (int *)local_98[0x26];
        piVar19 = (int *)((int *)local_98[0x26])[2];
        while (piVar10 = piVar12, piVar19 != (int *)0x0) {
          piVar12 = piVar19;
          if (*(int *)(piVar10[0x22] + 8) == 0x8e) {
            iVar15 = FUN_0010b0f4(piVar10,0);
            local_28 = *(int *)(iVar15 + 0x10);
            uVar16 = FUN_0010b180(piVar10,1);
            uVar17 = FUN_0010b180(piVar10,2);
            local_24 = local_a0;
            iVar15 = 1;
            do {
              if ((&cStack_29)[iVar15] == '\x01') {
                *(undefined1 *)((int)&local_28 + iVar15 + 3) = 4;
              }
              iVar15 = iVar15 + 1;
            } while (iVar15 != 5);
            iVar15 = FUN_0010b0f4(piVar10,1);
            uVar7 = *(undefined4 *)(iVar15 + 0x10);
            iVar15 = FUN_0010b0f4(piVar10,2);
            uVar8 = *(undefined4 *)(iVar15 + 0x10);
            iVar15 = piVar10[0x58] - *(int *)(param_1 + 0x46c);
            if (iVar15 < 0) {
              iVar15 = 0;
            }
            iVar1 = piVar10[4];
            FUN_0010b612(piVar10,param_1);
            FUN_001a7d72(piVar10);
            FUN_0010da48(piVar10,0x25,*(undefined4 *)(param_1 + 8));
            FUN_000e9596(local_84,local_50,piVar10);
            piVar10[0x58] = iVar15 + *(int *)(param_1 + 0x46c);
            piVar10[4] = iVar1;
            piVar10[0x25] = piVar10[0x53];
            piVar10[0x26] = 0;
            piVar10[0x27] = local_28;
            FUN_0010ba02(piVar10,1,local_80,*(uint *)(param_1 + 0x30) >> 7 & 1,
                         *(undefined4 *)(param_1 + 8));
            uVar11 = local_24;
            iVar15 = FUN_0010b0f4(piVar10,1);
            *(undefined4 *)(iVar15 + 0x10) = uVar11;
            FUN_00109c0e(piVar10 + 0x29,1,local_7c);
            FUN_00109c0e(piVar10 + 0x29,2,local_6c);
            FUN_0010ba02(piVar10,2,uVar16,*(uint *)(param_1 + 0x30) >> 7 & 1,
                         *(undefined4 *)(param_1 + 8));
            iVar15 = FUN_0010b0f4(piVar10,2);
            *(undefined4 *)(iVar15 + 0x10) = uVar7;
            FUN_0010ba02(piVar10,3,uVar17,*(uint *)(param_1 + 0x30) >> 7 & 1,
                         *(undefined4 *)(param_1 + 8));
            iVar15 = FUN_0010b0f4(piVar10,3);
            *(undefined4 *)(iVar15 + 0x10) = uVar8;
            if (*(int *)(piVar14[0x22] + 8) == 0x8b) {
              ((int (*)())FUN_001332ca)(piVar14,piVar10,*(undefined4 *)(param_1 + 8));
            }
            piVar19 = (int *)piVar19[2];
            local_50 = piVar10;
          }
          else {
            cVar13 = (**(code **)(*piVar10 + 0x34))(piVar10);
            if (cVar13 == '\0') break;
            piVar19 = (int *)piVar19[2];
          }
        }
        FUN_000f1b60(param_1,piVar14);
        piVar14[5] = piVar14[5] & 0xffffffef;
        (**(code **)(*piVar14 + 0xc))
                  (piVar14,*(uint *)(param_1 + 0x30) >> 7 & 1,*(undefined4 *)(param_1 + 8));
        cVar13 = FUN_0010a67e(local_80,param_1);
        if (cVar13 != '\0') {
          (**(code **)(*local_80 + 0xc))
                    (local_80,*(uint *)(param_1 + 0x30) >> 7 & 1,*(undefined4 *)(param_1 + 8));
        }
        *(undefined4 *)(iVar18 + 0x128) = 0;
        if ((*(char *)(iVar18 + 0x13c) != '\0') && (*(int *)(iVar18 + 0x138) != 0)) {
          *(undefined1 *)(*(int *)(iVar18 + 0x138) + 0x13c) = 1;
        }
        FUN_000e94da(iVar18);
        piVar19 = (int *)local_98[0x26];
        piVar14 = (int *)((int *)local_98[0x26])[2];
        while (piVar12 = piVar19, piVar14 != (int *)0x0) {
          cVar13 = (**(code **)(*piVar12 + 0x34))(piVar12);
          piVar19 = piVar14;
          if (cVar13 == '\0') {
            cVar13 = (**(code **)(*piVar12 + 0x38))(piVar12);
            if (cVar13 != '\0') break;
            FUN_001a7d72(piVar12);
            FUN_000e9596(local_84,local_50,piVar12);
            piVar14 = (int *)piVar14[2];
            local_50 = piVar12;
          }
          else {
            piVar14 = (int *)piVar14[2];
          }
        }
        FUN_000e94da(local_98);
        iVar15 = iVar6;
        do {
          iVar18 = FUN_000e9b7c(iVar15);
          if (local_84 == iVar18) {
            bVar9 = true;
LAB_00135052:
            cVar13 = ((int (*)())FUN_001321e6)(param_1,iVar15,iVar18);
            if (cVar13 == '\0') goto LAB_001350b4;
          }
          else {
            if (iVar18 != 0) {
              bVar9 = false;
              goto LAB_00135052;
            }
            bVar9 = false;
LAB_001350b4:
            iVar15 = *(int *)(iVar15 + 8);
          }
        } while ((!bVar9) && (iVar15 != local_84));
        piVar19 = *(int **)(iVar6 + 8);
        bVar9 = true;
      }
      piVar14 = (int *)piVar19[2];
      local_98 = piVar19;
    } while ((int *)piVar19[2] != (int *)0x0);
    if (bVar9) {
      FUN_000edb74(param_1);
      FUN_000f0346(param_1,"flatten_ifs");
      FUN_00143642(param_1,0);
    }
  }
  return;
}

/* FUN_0013559c @ 0x13559c (60 bytes) */
int FUN_0013559c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  char cVar1;
  
  cVar1 = FUN_000e144e(*(undefined4 *)(param_2 + 8),0,0);
  if (cVar1 != '\0') {
    return;
  }
  ((int (*)())FUN_0013490a)();
  return;
}

/* FUN_001355d8 @ 0x1355d8 (15 bytes) */
int FUN_001355d8(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  param_1 = param_2;
  ((int (*)())FUN_0013490a)();
  return;
}

/* FUN_001355e8 @ 0x1355e8 (15 bytes) */
int FUN_001355e8(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  param_1 = param_2;
  ((int (*)())FUN_0013490a)();
  return;
}

/* FUN_001355f8 @ 0x1355f8 (437 bytes) */
int FUN_001355f8(param_1, param_2)
  int param_1;
  int *param_2;
{
  byte bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_20 [4];
  
  cVar2 = (**(code **)(*param_2 + 100))(param_2);
  if (cVar2 != '\0') {
    for (iVar6 = 1; iVar3 = (**(code **)(*param_2 + 0x14))(param_2), iVar6 <= iVar3;
        iVar6 = iVar6 + 1) {
      if ((param_2[iVar6 * 6 + 0x28] & 1U) != 0) {
        return 0;
      }
      if ((param_2[iVar6 * 6 + 0x28] & 2U) != 0) {
        return 0;
      }
      cVar2 = FUN_000f5a1e(param_2,iVar6);
      if (cVar2 == '\0') {
        return 0;
      }
    }
    if (((char)param_2[0x48] == '\0') && (param_2[0x49] == 0)) {
      if ((param_2[0x20] != 0) &&
         (((cVar2 = FUN_0012dfd8(param_2[0x26]), cVar2 != '\0' &&
           ((*(byte *)(param_2 + 5) & 2) == 0)) &&
          (cVar2 = (**(code **)(*param_2 + 0x50))(param_2), cVar2 == '\0')))) {
        iVar6 = 4;
        piVar4 = param_2;
        do {
          if ((byte)((char)piVar4[0x27] - 2U) < 2) {
            return 0;
          }
          piVar4 = (int *)((int)piVar4 + 1);
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      FUN_0010b0f4(param_2,0);
      iVar6 = FUN_0010b7c8(param_2,0);
      if (((iVar6 == 0) && ((param_2[5] & 2U) == 0)) && ((param_2[5] & 0x200U) == 0)) {
        piVar4 = (int *)FUN_0010b180(param_2,1);
        cVar2 = (**(code **)(*piVar4 + 0x48))(piVar4);
        if (cVar2 != '\0') {
          iVar6 = FUN_0010b0f4(param_2,1);
          local_20[0] = *(undefined4 *)(iVar6 + 0x10);
          bVar1 = *(byte *)((int)local_20 + *(int *)(param_1 + 0x34));
          uVar5 = (uint)bVar1;
          if (((int)(char)piVar4[0x57] >> (bVar1 & 0x1f) & 1U) == 0) {
            *(undefined1 *)(param_1 + 1) = 0;
            *(uint *)(param_1 + 8) = uVar5;
            *(int *)(param_1 + 4) = piVar4[0x25];
            return 1;
          }
          if (((piVar4[uVar5 * 6 + 7] == 2) && ((float)piVar4[uVar5 * 6 + 8] == 0.0)) &&
             (!NAN((float)piVar4[uVar5 * 6 + 8]))) {
            *(undefined1 *)(param_1 + 1) = 1;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_001357ae @ 0x1357ae (305 bytes) */
int FUN_001357ae(param_1, param_2)
  undefined1 *param_1;
  int param_2;
{
  byte bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_30;
  undefined4 local_20 [4];
  
  if (*(int *)(*(int *)(param_2 + 0x88) + 8) == 0x12) {
    iVar6 = 0;
    local_30 = -1;
    iVar5 = 0;
    do {
      iVar3 = FUN_0010b0f4(param_2,0);
      if (*(char *)(iVar5 + 0x10 + iVar3) != '\x01') {
        iVar6 = iVar6 + 1;
        local_30 = *(int *)(param_1 + 0x34);
        if (local_30 != iVar5) {
          return 0;
        }
        if (1 < iVar6) {
          return 0;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != 4);
    iVar5 = FUN_00109e42(param_2,*(undefined4 *)(param_1 + 0x3c));
    if (1 < iVar5) {
      *param_1 = 1;
    }
    iVar5 = FUN_0010b180(*(undefined4 *)(param_1 + 0x30),1);
    if (param_2 == iVar5) {
      piVar4 = (int *)FUN_0010b180(param_2,2);
      cVar2 = (**(code **)(*piVar4 + 0x48))(piVar4);
      if (cVar2 != '\0') {
        iVar5 = FUN_0010b0f4(param_2,2);
        local_20[0] = *(undefined4 *)(iVar5 + 0x10);
        bVar1 = *(byte *)((int)local_20 + local_30);
        if ((((int)(char)piVar4[0x57] >> (bVar1 & 0x1f) & 1U) != 0) &&
           (piVar4[(uint)bVar1 * 6 + 7] == 2)) {
          if ((FLOAT_001c5ba4 == (float)piVar4[(uint)bVar1 * 6 + 8]) &&
             (!NAN(FLOAT_001c5ba4) && !NAN((float)piVar4[(uint)bVar1 * 6 + 8]))) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_001358e0 @ 0x1358e0 (959 bytes) */
int FUN_001358e0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  char *param_4;
{
  byte bVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *local_34;
  undefined4 local_28;
  int local_24;
  undefined4 local_20 [4];
  
  *param_4 = '\0';
  if (param_2 == 0) {
    return 0;
  }
  iVar6 = *(int *)(*(int *)(param_2 + 0x88) + 8);
  if (iVar6 == 0x8b) {
    iVar6 = FUN_0010b180(param_2,1);
    if (iVar6 != *(int *)(param_1 + 0x30)) {
      return 0;
    }
    piVar3 = (int *)FUN_0010b180(param_2,2);
    cVar2 = (**(code **)(*piVar3 + 0x48))(piVar3);
    if (cVar2 == '\0') {
      return 0;
    }
    iVar6 = FUN_0011074c(param_2);
    if (iVar6 != 3) {
      return 0;
    }
    iVar6 = FUN_0010b0f4(param_2,2);
    local_20[0] = *(undefined4 *)(iVar6 + 0x10);
    bVar1 = *(byte *)((int)local_20 + *(int *)(param_1 + 0x34));
    uVar9 = (uint)bVar1;
    *(uint *)(param_1 + 0x10) = uVar9;
    if (piVar3[0x26] == 0x33) {
      local_24 = piVar3[uVar9 * 6 + 8];
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x3a0);
      local_28 = DAT_001cc518;
      *(byte *)((int)&local_28 + uVar9) = bVar1;
      piVar3 = (int *)FUN_000f7a2e(uVar4,&local_24,&local_28);
      *(uint *)(param_1 + 0x10) = (uint)*(byte *)((int)&local_28 + *(int *)(param_1 + 0x10));
      if (piVar3 == (int *)0x0) {
        return 0;
      }
    }
    *(int *)(param_1 + 0xc) = piVar3[0x25];
  }
  else {
    if (iVar6 != 0x8c) {
      return 0;
    }
    uVar4 = FUN_0010b180(param_2,1);
    local_34 = (int *)FUN_0010b180(uVar4,1);
    piVar5 = (int *)FUN_0010b180(uVar4,2);
    cVar2 = (**(code **)(*local_34 + 0x48))(local_34);
    piVar3 = piVar5;
    if (cVar2 == '\0') {
      cVar2 = (**(code **)(*piVar5 + 0x48))(piVar5);
      if (cVar2 == '\0') {
        return 0;
      }
      *param_4 = '\x01';
      piVar3 = local_34;
      local_34 = piVar5;
    }
    if (piVar3 != *(int **)(param_1 + 0x30)) {
      return 0;
    }
    iVar6 = FUN_00109e42(uVar4,*(undefined4 *)(param_1 + 0x3c));
    if (iVar6 != 1) {
      return 0;
    }
    iVar6 = FUN_0011074c(uVar4);
    if (*param_4 == '\0') {
      if (iVar6 != 2) {
        return 0;
      }
    }
    else if (iVar6 != 3) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
    if ((*(byte *)(local_34 + 0x57) & 1) == 0) {
      *(int *)(param_1 + 0xc) = local_34[0x25];
      iVar6 = FUN_0010b0f4(param_2,1);
      local_20[0] = *(undefined4 *)(iVar6 + 0x10);
      *(uint *)(param_1 + 0x10) = (uint)*(byte *)((int)local_20 + *(int *)(param_1 + 0x34));
      if (*param_4 == '\0') {
        iVar6 = FUN_0010b0f4(uVar4,1);
        local_20[0] = *(undefined4 *)(iVar6 + 0x10);
      }
      else {
        iVar6 = FUN_0010b0f4(uVar4,2);
        local_20[0] = *(undefined4 *)(iVar6 + 0x10);
      }
      *(uint *)(param_1 + 0x10) = (uint)*(byte *)((int)local_20 + *(int *)(param_1 + 0x10));
    }
    else {
      *(int *)(param_1 + 0x14) = (int)(float)local_34[8];
      *(undefined4 *)(param_1 + 0x18) = 1;
    }
  }
  iVar6 = *(int *)(param_3 + 300);
  iVar8 = *(int *)(param_3 + 0x130);
  if (*param_4 == '\0') {
    iVar7 = FUN_001a7d8a(iVar6 + 0x90);
    if ((iVar7 < 3) && (iVar8 = FUN_001a7d8a(iVar8 + 0x90), iVar8 < 3)) {
      piVar3 = (int *)FUN_000eac7c(iVar6,0);
      cVar2 = (**(code **)(*piVar3 + 0x38))(piVar3);
      if (cVar2 != '\0') {
        uVar4 = FUN_000eac7c(iVar6,0);
        *(undefined4 *)(param_1 + 0x20) = uVar4;
LAB_00135a55:
        *(int *)(param_1 + 0x24) = param_3;
        return 1;
      }
    }
  }
  else {
    cVar2 = FUN_000e95be(iVar8);
    if ((cVar2 != '\0') && (iVar6 = FUN_001a7d8a(iVar8 + 0x90), iVar6 < 3)) {
      piVar3 = (int *)FUN_000eac7c(iVar8,0);
      *(int **)(param_1 + 0x20) = piVar3;
      cVar2 = (**(code **)(*piVar3 + 0x38))(piVar3);
      if (cVar2 != '\0') {
        uVar4 = FUN_000eac7c(*(undefined4 *)(param_3 + 0x134),0);
        cVar2 = FUN_000e95be(uVar4);
        if ((cVar2 != '\0') &&
           (iVar6 = FUN_000eac7c(uVar4,0), iVar6 == *(int *)(*(int *)(param_1 + 0x28) + 0x140)))
        goto LAB_00135a55;
      }
    }
  }
  return 0;
}

/* FUN_00135ca0 @ 0x135ca0 (692 bytes) */
int FUN_00135ca0(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *local_7c;
  int *local_70;
  undefined1 local_60 [44];
  undefined4 local_34;
  int local_24;
  char local_1d [13];
  
  local_24 = param_1;
  local_7c = (int *)(*(int **)(param_1 + 0x378))[2];
  if (local_7c != (int *)0x0) {
    bVar1 = false;
    piVar7 = *(int **)(param_1 + 0x378);
    do {
      cVar3 = (**(code **)(*piVar7 + 0x2c))(piVar7);
      if ((cVar3 != '\0') && (cVar3 = ((int (*)())FUN_00132b46)(local_60,piVar7), cVar3 != '\0')) {
        local_60[0] = 0;
        iVar6 = piVar7[0x26];
        for (iVar2 = *(int *)(piVar7[0x26] + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
          if ((*(int *)(*(int *)(iVar6 + 0x88) + 8) == 0x8e) &&
             (cVar3 = ((int (*)())FUN_00132526)(local_60,iVar6), cVar3 != '\0')) {
            uVar4 = FUN_0010b180(iVar6,2);
            cVar3 = ((int (*)())FUN_001355f8)(local_60,uVar4);
            if (cVar3 != '\0') {
              uVar4 = FUN_0010b180(iVar6,1);
              cVar3 = ((int (*)())FUN_001357ae)(local_60,uVar4);
              if (cVar3 != '\0') {
                local_34 = uVar4;
                piVar5 = (int *)FUN_000eac7c(piVar7,0);
                cVar3 = (**(code **)(*piVar5 + 0x24))(piVar5);
                if (cVar3 == '\0') {
                  cVar3 = FUN_000e95be(piVar5);
                  if (cVar3 != '\0') {
                    iVar6 = FUN_001a7d8a(piVar5 + 0x24);
                    if ((iVar6 < 3) || (iVar6 = FUN_001a7d8a(piVar5 + 0x24), iVar6 == 3)) {
                      piVar5 = (int *)FUN_000eac7c(piVar5,0);
                      cVar3 = (**(code **)(*piVar5 + 0x24))(piVar5);
                      if (cVar3 != '\0') goto LAB_00135e28;
                    }
                  }
                }
                else {
LAB_00135e28:
                  uVar4 = FUN_000e9644(piVar5);
                  local_70 = (int *)piVar5[0x4d];
                  local_1d[0] = '\0';
                  cVar3 = ((int (*)())FUN_001358e0)(local_60,uVar4,piVar5,local_1d);
                  if (cVar3 != '\0') {
                    if ((local_1d[0] == '\0') && (piVar5 = (int *)piVar7[0x50], local_70 != piVar5))
                    {
                      iVar6 = 0;
                      do {
                        cVar3 = (**(code **)(*local_70 + 0x2c))(local_70);
                        if (cVar3 == '\0') {
                          cVar3 = (**(code **)(*local_70 + 0x30))(local_70);
                          if (cVar3 == '\0') {
                            if (iVar6 == 0) {
                              (**(code **)(*local_70 + 0x38))(local_70);
                            }
                          }
                          else {
                            iVar6 = iVar6 + -1;
                          }
                        }
                        else {
                          iVar6 = iVar6 + 1;
                        }
                        local_70 = (int *)local_70[2];
                      } while (piVar5 != local_70);
                    }
                    cVar3 = ((int (*)())FUN_00132720)(local_60,local_1d[0]);
                    bVar1 = bVar1 || cVar3 != '\0';
                    if (cVar3 != '\0') {
                      FUN_000f0346(param_1,"loop_trans");
                    }
                  }
                }
              }
            }
          }
          iVar6 = iVar2;
        }
      }
      piVar5 = local_7c + 2;
      piVar7 = local_7c;
      local_7c = (int *)*piVar5;
    } while ((int *)*piVar5 != (int *)0x0);
    if (bVar1) {
      FUN_000edb74(param_1);
      FUN_00143642(param_1,0);
      return 1;
    }
  }
  return 0;
}

/* FUN_00135f54 @ 0x135f54 (1877 bytes) */
int FUN_00135f54(param_1)
  int param_1;
{
  uint uVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  bool bVar19;
  undefined4 local_50;
  undefined4 local_48;
  undefined4 local_40;
  undefined4 *local_2c;
  
  if (*(int *)(*(int *)(param_1 + 0x408) + 4) != 0) {
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
    puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x14);
    *puVar3 = uVar4;
    puVar3[4] = uVar4;
    puVar3[2] = 0;
    puVar3[1] = 2;
    uVar4 = FUN_001a7bca(uVar4,8);
    puVar3[3] = uVar4;
    iVar16 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar16;
    uVar4 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
    iVar5 = FUN_0010b0f4(uVar4,0);
    *(int *)(iVar5 + 8) = iVar16;
    *(undefined4 *)(iVar5 + 0xc) = 0;
    FUN_000fa0d2(uVar4,param_1,1,0,0,0,0);
    FUN_000fbaca(param_1,uVar4,*(undefined4 *)(param_1 + 0x394));
    iVar17 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar17;
    iVar5 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
    iVar16 = FUN_0010b0f4(iVar5,0);
    *(int *)(iVar16 + 8) = iVar17;
    *(undefined4 *)(iVar16 + 0xc) = 0;
    FUN_000f9ef4(iVar5,param_1,1,0xffffffff,0xffffffff,0xffffffff,0xffffffff);
    FUN_000fbaca(param_1,iVar5,*(undefined4 *)(param_1 + 0x394));
    while (iVar16 = *(int *)(param_1 + 0x408), *(int *)(iVar16 + 4) != 0) {
      uVar18 = *(uint *)(iVar16 + 4);
      if (uVar18 - 1 < uVar18) {
        piVar6 = (int *)(*(int *)(iVar16 + 8) + (uVar18 - 1) * 4);
      }
      else {
        piVar6 = (int *)0x0;
      }
      iVar17 = *piVar6;
      FUN_001a7f3c(iVar16,uVar18 - 1);
      uVar9 = *(undefined4 *)(iVar17 + 0x158);
      iVar16 = ((int (*)())FUN_0013237e)(uVar9);
      uVar8 = *(undefined4 *)(iVar16 + 0x134);
      bVar19 = *(int *)(*(int *)(iVar17 + 0x88) + 8) != 0xf8;
      if (bVar19) {
        do {
          iVar16 = ((int (*)())FUN_0013237e)(iVar16);
        } while (*(char *)(iVar16 + 0x144) == '\0');
        if (puVar3[2] != 0) {
          uVar18 = 0;
          do {
            if (uVar18 < (uint)puVar3[1]) {
              uVar1 = puVar3[2];
              if (uVar1 <= uVar18) {
                _memset((void *)(puVar3[3] + uVar1 * 4),0,(uVar18 - uVar1) * 4 + 4);
                puVar3[2] = uVar18 + 1;
              }
              iVar12 = *(int *)(puVar3[3] + uVar18 * 4);
            }
            else {
              piVar6 = (int *)FUN_001a7f7c(puVar3 + 1,uVar18);
              iVar12 = *piVar6;
            }
            if (iVar12 == iVar16) {
              local_48 = *(undefined4 *)(iVar16 + 0x134);
              iVar16 = FUN_000e9f24(uVar9);
              local_40 = *(undefined4 *)(iVar16 + 0x94);
              local_50 = 0xffffffff;
              goto LAB_00136237;
            }
            uVar18 = uVar18 + 1;
          } while (uVar18 < (uint)puVar3[2]);
        }
        local_48 = *(undefined4 *)(iVar16 + 0x134);
        iVar16 = *(int *)(iVar16 + 300);
        local_50 = 0xffffffff;
        if (iVar16 == 0) goto LAB_00136679;
LAB_0013621e:
        local_40 = ((int (*)())FUN_00132418)(uVar4,iVar16,param_1);
      }
      else {
        local_50 = *(undefined4 *)(iVar17 + 300);
        iVar16 = ((int (*)())FUN_0013201a)(local_50,uVar8);
        local_48 = 0;
        if (iVar16 != 0) goto LAB_0013621e;
LAB_00136679:
        local_40 = 0;
      }
LAB_00136237:
      uVar7 = FUN_0010a17a(0x31,*(undefined4 *)(param_1 + 8));
      iVar16 = FUN_0010b0f4(uVar7,0);
      *(undefined4 *)(iVar16 + 8) = local_40;
      *(undefined4 *)(iVar16 + 0xc) = 0;
      FUN_0010a3c2(uVar7,1,*(undefined4 *)(iVar5 + 0x8c));
      FUN_000f0144(param_1,uVar7);
      FUN_000e9596(uVar9,iVar17,uVar7);
      FUN_001a7d72(iVar17);
      while( true ) {
        while( true ) {
          uVar9 = ((int (*)())FUN_0013408e)(param_1,uVar8);
          iVar16 = FUN_000eac7c(uVar9,0);
          iVar17 = ((int (*)())FUN_001322b4)(bVar19,local_50,iVar16,local_48);
          uVar9 = ((int (*)())FUN_0013237e)(iVar16);
          if (iVar16 != iVar17) break;
          ((int (*)())FUN_0013416c)();
          uVar8 = ((int (*)())FUN_00132178)();
        }
        if (iVar17 == 0) break;
        uVar8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
        puVar10 = (undefined4 *)FUN_001a7bca(uVar8,0x168);
        *puVar10 = uVar8;
        puVar11 = puVar10 + 1;
        FUN_0010ac30(puVar11,0x8c,*(undefined4 *)(param_1 + 8));
        puVar10[0x4c] = 6;
        iVar12 = FUN_0010b0f4(puVar11,1);
        *(undefined4 *)(iVar12 + 8) = local_40;
        *(undefined4 *)(iVar12 + 0xc) = 0;
        uVar8 = *(undefined4 *)PTR_DAT_00213485;
        iVar12 = FUN_0010b0f4(puVar11,1);
        *(undefined4 *)(iVar12 + 0x10) = uVar8;
        uVar13 = FUN_000eac0c(iVar17,0);
        puVar10 = (undefined4 *)FUN_000eac0c(iVar16,0);
        uVar8 = *(undefined4 *)(iVar16 + 0xb8);
        uVar7 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
        puVar14 = (undefined4 *)FUN_001a7bca(uVar7,0x150);
        *puVar14 = uVar7;
        puVar15 = puVar14 + 1;
        FUN_000ec126(puVar15,puVar11,uVar9,iVar16,*(undefined4 *)(param_1 + 8));
        cVar2 = FUN_000e95be(puVar10);
        local_2c = puVar10;
        if (cVar2 == '\0') {
          uVar9 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          local_2c = (undefined4 *)FUN_001a7bca(uVar9,0x128);
          *local_2c = uVar9;
          local_2c = local_2c + 1;
          FUN_000eb992(local_2c,*(undefined4 *)(param_1 + 8));
          FUN_000eb12a(puVar10,iVar16,local_2c);
          FUN_000eb2a6(puVar15,iVar16,local_2c);
          FUN_000edc32(param_1,puVar10,local_2c);
        }
        FUN_000edc32(param_1,local_2c,puVar15);
        uVar9 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
        puVar10 = (undefined4 *)FUN_001a7bca(uVar9,0x128);
        *puVar10 = uVar9;
        puVar10 = puVar10 + 1;
        FUN_000eb992(puVar10,*(undefined4 *)(param_1 + 8));
        puVar14[0x4d] = puVar10;
        FUN_000edc32(param_1,uVar13,puVar10);
        uVar9 = puVar14[0x4e];
        FUN_000edc32(param_1,puVar10,uVar9);
        FUN_000e96a6(puVar15,uVar8);
        FUN_000ea91c(puVar15,puVar10);
        FUN_000eb12a(local_2c,iVar16,puVar15);
        FUN_000ea91c(puVar10,uVar9);
        FUN_000eb12a(uVar13,iVar17,uVar9);
        FUN_000ea91c(uVar9,iVar17);
        FUN_000f0144(param_1,puVar11);
        ((int (*)())FUN_0013416c)();
        uVar8 = ((int (*)())FUN_00132178)();
      }
    }
    ((int (*)())FUN_0013455c)(param_1,*(undefined4 *)(param_1 + 0x394),*(undefined4 *)(param_1 + 0x39c));
  }
  return;
}

/* FUN_00136740 @ 0x136740 (3630 bytes) */
int FUN_00136740(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
  int *param_5;
  int *param_6;
{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 *puVar13;
  int *piVar14;
  int *piVar15;
  int *piVar16;
  int iVar17;
  uint local_94;
  undefined4 local_7c;
  int local_6c;
  int local_64;
  int local_60;
  int local_5c;
  int local_54;
  int local_50;
  uint local_44;
  int local_38;
  int *local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  int local_20;
  
  cVar5 = FUN_000e1402(*(undefined4 *)(param_1 + 8),2);
  if ((((cVar5 != '\0') && (cVar5 = FUN_000eb5fa(param_3), cVar5 != '\0')) &&
      (*(int *)(param_3 + 0x130) < 1)) && (*(char *)(param_3 + 0x134) == '\0')) {
    iVar6 = FUN_000ea774(param_3);
    iVar7 = FUN_000ea71c(param_3);
    iVar8 = FUN_000ea6c4(param_3);
    uVar11 = *(undefined4 *)(param_1 + 8);
    cVar5 = ((int (*)())FUN_00131e88)(uVar11,iVar6,iVar7,iVar8,param_3);
    if (cVar5 == '\0') {
      ((int (*)())FUN_00131ee2)(uVar11,iVar6);
      *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
      iVar9 = FUN_000e9b0e(param_3);
      local_7c = *(undefined4 *)(param_3 + 8);
      iVar2 = *param_4;
      if (iVar6 == 0) {
        while (param_3 != iVar2) {
          iVar7 = *(int *)(iVar2 + 4);
          piVar16 = *(int **)(iVar2 + 0x98);
          iVar8 = piVar16[2];
          while (iVar8 != 0) {
            if ((((*(byte *)(piVar16 + 5) & 1) != 0) &&
                (cVar5 = (**(code **)(*piVar16 + 0x34))(piVar16), cVar5 == '\0')) &&
               (cVar5 = (**(code **)(*piVar16 + 0x38))(piVar16), cVar5 == '\0')) {
              local_6c = 1;
              piVar14 = piVar16;
              while( true ) {
                iVar8 = (**(code **)(*piVar16 + 0x14))(piVar16);
                if (iVar8 < local_6c) break;
                FUN_0012a842(piVar14[0x29],piVar16);
                local_6c = local_6c + 1;
                piVar14 = piVar14 + 6;
              }
              (**(code **)(*piVar16 + 0xc))(piVar16,0,*(undefined4 *)(param_1 + 8));
            }
            piVar16 = (int *)piVar16[2];
            iVar8 = piVar16[2];
          }
          FUN_000e94da(iVar2);
          iVar2 = iVar7;
        }
        *param_4 = iVar9;
        local_7c = *(undefined4 *)(param_3 + 8);
      }
      else {
        if ((1 < iVar6) && (param_3 != iVar2)) {
          iVar17 = 0;
          iVar12 = param_3;
          do {
            iVar12 = *(int *)(iVar12 + 8);
            *(int *)(iVar12 + 0xc0) = iVar17;
            iVar17 = iVar17 + 1;
          } while (iVar2 != iVar12);
        }
        iVar12 = *(int *)(param_3 + 0x13c);
        for (iVar17 = param_3; iVar17 != iVar2; iVar17 = *(int *)(iVar17 + 8)) {
          piVar16 = *(int **)(iVar17 + 8);
          piVar16[0x2e] = piVar16[0x2e] + -1;
          cVar5 = (**(code **)(*piVar16 + 0x2c))(piVar16);
          if ((cVar5 != '\0') && (param_3 == piVar16[0x4f])) {
            piVar16[0x4f] = iVar12;
          }
        }
        uVar11 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
        puVar10 = (undefined4 *)FUN_001a7bca(uVar11,0x14);
        *puVar10 = uVar11;
        puVar1 = puVar10 + 1;
        puVar10[4] = uVar11;
        puVar10[2] = 0;
        puVar10[1] = 2;
        uVar11 = FUN_001a7bca(uVar11,8);
        puVar10[3] = uVar11;
        if (1 < iVar6) {
          local_5c = 1;
          local_64 = iVar7;
          local_60 = iVar2;
          do {
            local_64 = local_64 + iVar8;
            if (param_3 == iVar2) {
              local_2c = 0xffffffff;
            }
            else {
              local_50 = param_3;
              local_94 = 0;
              do {
                local_2c = local_94;
                piVar16 = *(int **)(local_50 + 8);
                iVar12 = (**(code **)(*piVar16 + 8))(piVar16);
                if (local_2c < *puVar1) {
                  uVar3 = puVar10[2];
                  if (uVar3 <= local_2c) {
                    _memset((void *)(puVar10[3] + uVar3 * 4),0,(local_2c - uVar3) * 4 + 4);
                    puVar10[2] = local_2c + 1;
                  }
                  piVar14 = (int *)(puVar10[3] + local_2c * 4);
                }
                else {
                  piVar14 = (int *)FUN_001a7f7c(puVar1,local_2c);
                }
                local_94 = local_2c + 1;
                *piVar14 = iVar12;
                piVar14 = (int *)piVar16[0x26];
                iVar17 = piVar14[2];
                while (iVar17 != 0) {
                  while (((*(byte *)(piVar14 + 5) & 1) == 0 ||
                         (cVar5 = (**(code **)(*piVar14 + 0x34))(piVar14), cVar5 != '\0'))) {
                    piVar14 = (int *)piVar14[2];
                    if (piVar14[2] == 0) goto LAB_00136a43;
                  }
                  cVar5 = (**(code **)(*piVar14 + 0x38))(piVar14);
                  if (cVar5 != '\0') break;
                  iVar17 = FUN_0010a1c2(piVar14,*(undefined4 *)(param_1 + 8),0);
                  if ((*(char *)(param_3 + 300) == '\0') &&
                     (cVar5 = ((int (*)())FUN_00131f06)(iVar17), cVar5 != '\0')) {
                    ((int (*)())FUN_00134746)(iVar17,local_64,param_1);
                  }
                  if ((*(byte *)(iVar17 + 0x14) & 0x10) != 0) {
                    FUN_000f0b74(param_1,iVar17);
                  }
                  cVar5 = (**(code **)(*piVar16 + 0x24))(piVar16);
                  if ((cVar5 != '\0') &&
                     (piVar15 = (int *)FUN_000e9644(piVar16), piVar14 == piVar15)) {
                    *(int *)(iVar12 + 0x128) = iVar17;
                  }
                  cVar5 = (**(code **)(*piVar16 + 0x2c))(piVar16);
                  if ((cVar5 != '\0') && (piVar14 == (int *)piVar16[0x4e])) {
                    *(int *)(iVar12 + 0x138) = iVar17;
                  }
                  FUN_000fbaca(param_1,iVar17,iVar12);
                  piVar14 = (int *)piVar14[2];
                  iVar17 = piVar14[2];
                }
LAB_00136a43:
                FUN_000edc32(param_1,*param_4,iVar12);
                *param_4 = iVar12;
                local_50 = *(int *)(local_50 + 8);
              } while (iVar2 != local_50);
            }
            local_54 = *(int *)(param_3 + 8);
            if (0 < (int)local_2c) {
              local_44 = 0;
              local_20 = 1;
              do {
                if (local_44 < *puVar1) {
                  uVar3 = puVar10[2];
                  if (uVar3 <= local_44) {
                    _memset((void *)(puVar10[3] + uVar3 * 4),0,(local_44 - uVar3) * 4 + 4);
                    puVar10[2] = local_20;
                  }
                }
                else {
                  FUN_001a7f7c(puVar1,local_44);
                }
                local_28 = 1;
                local_24 = 0;
                iVar12 = *(int *)(local_54 + 0xd0);
                if (*(int *)(iVar12 + 4) != 0) {
                  do {
                    iVar12 = *(int *)(local_24 + *(int *)(iVar12 + 8));
                    if (iVar12 != 0) {
                      if (local_44 < *puVar1) {
                        uVar3 = puVar10[2];
                        if (uVar3 <= local_44) {
                          _memset((void *)(puVar10[3] + uVar3 * 4),0,(local_44 - uVar3) * 4 + 4);
                          puVar10[2] = local_20;
                        }
                        puVar13 = (undefined4 *)(local_44 * 4 + puVar10[3]);
                      }
                      else {
                        puVar13 = (undefined4 *)FUN_001a7f7c(puVar1,local_44);
                      }
                      uVar11 = *puVar13;
                      uVar3 = *(uint *)(iVar12 + 0xc0);
                      if (uVar3 < *puVar1) {
                        uVar4 = puVar10[2];
                        if (uVar4 <= uVar3) {
                          _memset((void *)(puVar10[3] + uVar4 * 4),0,(uVar3 - uVar4) * 4 + 4);
                          puVar10[2] = uVar3 + 1;
                        }
                        puVar13 = (undefined4 *)(puVar10[3] + uVar3 * 4);
                      }
                      else {
                        puVar13 = (undefined4 *)FUN_001a7f7c(puVar1,uVar3);
                      }
                      FUN_000ea91c(uVar11,*puVar13);
                    }
                    local_28 = local_28 + 1;
                    local_24 = local_24 + 4;
                    iVar12 = *(int *)(local_54 + 0xd0);
                  } while (local_28 <= *(uint *)(iVar12 + 4));
                }
                local_54 = *(int *)(local_54 + 8);
                local_44 = local_44 + 1;
                local_20 = local_20 + 1;
              } while (local_2c != local_44);
            }
            if (*puVar1 == 0) {
              puVar13 = (undefined4 *)FUN_001a7f7c(puVar1,0);
            }
            else {
              if (puVar10[2] == 0) {
                *(undefined4 *)puVar10[3] = 0;
                puVar10[2] = 1;
              }
              puVar13 = (undefined4 *)puVar10[3];
            }
            FUN_000ea91c(local_60,*puVar13);
            if (param_3 != iVar2) {
              local_38 = param_3;
              do {
                iVar12 = *(int *)(local_38 + 8);
                uVar3 = *(uint *)(iVar12 + 0xc0);
                if (uVar3 < *puVar1) {
                  uVar4 = puVar10[2];
                  if (uVar4 <= uVar3) {
                    _memset((void *)(puVar10[3] + uVar4 * 4),0,(uVar3 - uVar4) * 4 + 4);
                    puVar10[2] = uVar3 + 1;
                  }
                  local_30 = *(int **)(puVar10[3] + uVar3 * 4);
                  cVar5 = (**(code **)(*local_30 + 0x24))(local_30);
                  if (cVar5 != '\0') goto LAB_00136bf0;
LAB_00136cd5:
                  cVar5 = (**(code **)(*local_30 + 0x28))(local_30);
                  if (cVar5 == '\0') {
                    cVar5 = (**(code **)(*local_30 + 0x2c))(local_30);
                    if (cVar5 == '\0') {
                      cVar5 = (**(code **)(*local_30 + 0x30))(local_30);
                      if (cVar5 != '\0') goto LAB_00136ce8;
                      cVar5 = (**(code **)(*local_30 + 0x34))(local_30);
                      if (cVar5 == '\0') {
                        cVar5 = (**(code **)(*local_30 + 0x38))(local_30);
                        if (cVar5 != '\0') goto LAB_00136ce8;
                        (**(code **)(*local_30 + 0x3c))(local_30);
                      }
                      else {
                        uVar3 = *(uint *)(*(int *)(iVar12 + 0x124) + 0xc0);
                        if (uVar3 < *puVar1) {
                          uVar4 = puVar10[2];
                          if (uVar4 <= uVar3) {
                            _memset((void *)(puVar10[3] + uVar4 * 4),0,(uVar3 - uVar4) * 4 + 4);
                            puVar10[2] = uVar3 + 1;
                          }
                          piVar16 = (int *)(puVar10[3] + uVar3 * 4);
                        }
                        else {
                          piVar16 = (int *)FUN_001a7f7c(puVar1,uVar3);
                        }
                        local_30[0x49] = *piVar16;
                      }
                    }
                    else {
                      uVar3 = *(uint *)(*(int *)(iVar12 + 0x140) + 0xc0);
                      if (uVar3 < *puVar1) {
                        uVar4 = puVar10[2];
                        if (uVar4 <= uVar3) {
                          _memset((void *)(puVar10[3] + uVar4 * 4),0,(uVar3 - uVar4) * 4 + 4);
                          puVar10[2] = uVar3 + 1;
                        }
                        piVar16 = (int *)(puVar10[3] + uVar3 * 4);
                      }
                      else {
                        piVar16 = (int *)FUN_001a7f7c(puVar1,uVar3);
                      }
                      local_30[0x50] = *piVar16;
                      uVar3 = *(uint *)(*(int *)(iVar12 + 0x144) + 0xc0);
                      if (uVar3 < *puVar1) {
                        uVar4 = puVar10[2];
                        if (uVar4 <= uVar3) {
                          _memset((void *)(puVar10[3] + uVar4 * 4),0,(uVar3 - uVar4) * 4 + 4);
                          puVar10[2] = uVar3 + 1;
                        }
                        piVar16 = (int *)(puVar10[3] + uVar3 * 4);
                      }
                      else {
                        piVar16 = (int *)FUN_001a7f7c(puVar1,uVar3);
                      }
                      local_30[0x51] = *piVar16;
                    }
                  }
                  else {
LAB_00136ce8:
                    uVar3 = *(uint *)(*(int *)(iVar12 + 0x124) + 0xc0);
                    if (uVar3 < *puVar1) {
                      uVar4 = puVar10[2];
                      if (uVar4 <= uVar3) {
                        _memset((void *)(puVar10[3] + uVar4 * 4),0,(uVar3 - uVar4) * 4 + 4);
                        puVar10[2] = uVar3 + 1;
                      }
                      piVar16 = (int *)(puVar10[3] + uVar3 * 4);
                    }
                    else {
                      piVar16 = (int *)FUN_001a7f7c(puVar1,uVar3);
                    }
                    local_30[0x49] = *piVar16;
                  }
                }
                else {
                  puVar13 = (undefined4 *)FUN_001a7f7c(puVar1,uVar3);
                  local_30 = (int *)*puVar13;
                  cVar5 = (**(code **)(*local_30 + 0x24))(local_30);
                  if (cVar5 == '\0') goto LAB_00136cd5;
LAB_00136bf0:
                  uVar3 = *(uint *)(*(int *)(iVar12 + 0x134) + 0xc0);
                  if (uVar3 < *puVar1) {
                    uVar4 = puVar10[2];
                    if (uVar4 <= uVar3) {
                      _memset((void *)(puVar10[3] + uVar4 * 4),0,(uVar3 - uVar4) * 4 + 4);
                      puVar10[2] = uVar3 + 1;
                    }
                    piVar16 = (int *)(puVar10[3] + uVar3 * 4);
                  }
                  else {
                    piVar16 = (int *)FUN_001a7f7c(puVar1,uVar3);
                  }
                  local_30[0x4d] = *piVar16;
                  uVar3 = *(uint *)(*(int *)(iVar12 + 300) + 0xc0);
                  if (uVar3 < *puVar1) {
                    uVar4 = puVar10[2];
                    if (uVar4 <= uVar3) {
                      _memset((void *)(puVar10[3] + uVar4 * 4),0,(uVar3 - uVar4) * 4 + 4);
                      puVar10[2] = uVar3 + 1;
                    }
                    piVar16 = (int *)(puVar10[3] + uVar3 * 4);
                  }
                  else {
                    piVar16 = (int *)FUN_001a7f7c(puVar1,uVar3);
                  }
                  local_30[0x4b] = *piVar16;
                  uVar3 = *(uint *)(*(int *)(iVar12 + 0x130) + 0xc0);
                  if (uVar3 < *puVar1) {
                    uVar4 = puVar10[2];
                    if (uVar4 <= uVar3) {
                      _memset((void *)(puVar10[3] + uVar4 * 4),0,(uVar3 - uVar4) * 4 + 4);
                      puVar10[2] = uVar3 + 1;
                    }
                    piVar16 = (int *)(puVar10[3] + uVar3 * 4);
                  }
                  else {
                    piVar16 = (int *)FUN_001a7f7c(puVar1,uVar3);
                  }
                  local_30[0x4c] = *piVar16;
                }
                local_38 = *(int *)(local_38 + 8);
              } while (iVar2 != local_38);
            }
            local_60 = *param_4;
            local_5c = local_5c + 1;
          } while (iVar6 != local_5c);
        }
        iVar8 = param_3;
        if (*(char *)(param_3 + 300) == '\0') {
          while (iVar12 = iVar8, iVar12 != iVar2) {
            iVar17 = *(int *)(*(int *)(iVar12 + 8) + 0x98);
            iVar8 = *(int *)(iVar12 + 8);
            if (*(int *)(iVar17 + 8) != 0) {
              do {
                if (((*(byte *)(iVar17 + 0x14) & 1) != 0) &&
                   (cVar5 = ((int (*)())FUN_00131f06)(iVar17), cVar5 != '\0')) {
                  ((int (*)())FUN_00134746)(iVar17,iVar7,param_1);
                }
                iVar17 = *(int *)(iVar17 + 8);
              } while (*(int *)(iVar17 + 8) != 0);
              iVar8 = *(int *)(iVar12 + 8);
            }
          }
        }
      }
      FUN_001a7f3c(param_2,*(int *)(param_2 + 4) + -1);
      *param_6 = *param_6 + -1;
      piVar16 = *(int **)(param_3 + 0x98);
      iVar7 = piVar16[2];
      do {
        if (iVar7 == 0) {
          FUN_000eadda(param_3,iVar9,local_7c);
          if (iVar6 == 0) {
            FUN_000e97aa(iVar9);
          }
          else {
            FUN_000e97aa(iVar9);
            FUN_000e97bc(local_7c);
          }
          piVar16 = *(int **)(param_3 + 0x140);
          if (piVar16 != (int *)0x0) {
            (**(code **)(*piVar16 + 4))(piVar16);
          }
          piVar16 = *(int **)(param_3 + 0x144);
          if (piVar16 != (int *)0x0) {
            (**(code **)(*piVar16 + 4))(piVar16);
          }
          FUN_000e94da(param_3);
          uVar11 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          puVar10 = (undefined4 *)FUN_001a7bca(uVar11,0x128);
          *puVar10 = uVar11;
          FUN_000eb992(puVar10 + 1,*(undefined4 *)(param_1 + 8));
          *param_5 = (int)(puVar10 + 1);
          puVar10[0x2f] = *param_6;
          FUN_000edc32(param_1,*param_4,*param_5);
          FUN_000ea91c(*param_4,*param_5);
          ((int (*)())FUN_0013455c)(param_1,iVar9,*param_4);
          *param_4 = *param_5;
          return 1;
        }
        if ((*(byte *)(piVar16 + 5) & 1) != 0) {
          cVar5 = (**(code **)(*piVar16 + 0x3c))(piVar16);
          if (cVar5 == '\0') {
            if (*(int *)(piVar16[0x22] + 4) == 3) {
              if (*(char *)(param_3 + 300) == '\0') goto LAB_00137045;
              FUN_0012a842(piVar16[0x29],piVar16);
              FUN_001a7d72(piVar16);
              iVar7 = *(int *)(param_3 + 0x13c);
              FUN_0010a3c2(piVar16,1,*(undefined4 *)(*(int *)(iVar7 + 0x138) + 0x8c));
              FUN_000f0144(param_1,piVar16);
              FUN_000e9512(iVar7,piVar16);
            }
          }
          else {
LAB_00137045:
            FUN_0012a842(piVar16[0x29],piVar16);
            (**(code **)(*piVar16 + 0xc))(piVar16,0,*(undefined4 *)(param_1 + 8));
          }
        }
        piVar16 = (int *)piVar16[2];
        iVar7 = piVar16[2];
      } while( true );
    }
  }
  return 0;
}

/* FUN_001375b6 @ 0x1375b6 (459 bytes) */
int FUN_001375b6(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  int local_30;
  uint local_20;
  uint local_1c;
  undefined4 *local_18;
  undefined4 local_14;
  int local_10;
  
  iVar2 = FUN_001a7d8a(param_3 + 0x90);
  if (2 < iVar2) {
    return 0;
  }
  *(int *)(param_1 + 0x468) = *(int *)(param_1 + 0x468) + 1;
  local_14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  local_1c = 0;
  local_20 = 2;
  local_18 = (undefined4 *)FUN_001a7bca(local_14,8);
  do {
    cVar1 = (**(code **)(*param_2 + 0x24))(param_2);
    if (cVar1 == '\0') {
      iVar2 = FUN_001a7d8a(param_2 + 0x24);
      if (((2 < iVar2) || (cVar1 = (**(code **)(*param_2 + 0x38))(param_2), cVar1 != '\0')) ||
         (cVar1 = (**(code **)(*param_2 + 0x3c))(param_2), cVar1 != '\0')) goto LAB_0013774f;
    }
    else {
      iVar2 = FUN_001a7d8a(param_2 + 0x24);
      if (3 < iVar2) {
LAB_0013774f:
        uVar5 = 0;
        goto LAB_00137705;
      }
    }
    local_10 = 0;
    uVar6 = 1;
    local_30 = 0;
    iVar2 = param_2[0x34];
    if (*(int *)(iVar2 + 4) != 0) {
      do {
        local_10 = *(int *)(*(int *)(iVar2 + 8) + local_30);
        if (((local_10 != 0) && (*(int *)(param_1 + 0x468) != *(int *)(local_10 + 0x110))) &&
           (param_3 != local_10)) {
          *(int *)(local_10 + 0x110) = *(int *)(param_1 + 0x468);
          if (local_1c < local_20) {
            local_18[local_1c] = 0;
            piVar4 = local_18 + local_1c;
            local_1c = local_1c + 1;
          }
          else {
            piVar4 = (int *)FUN_001a7f7c(&local_20,local_1c);
          }
          *piVar4 = local_10;
        }
        uVar6 = uVar6 + 1;
        local_30 = local_30 + 4;
        iVar2 = param_2[0x34];
      } while (uVar6 <= *(uint *)(iVar2 + 4));
    }
    if (local_1c == 0) {
LAB_00137700:
      uVar5 = 1;
LAB_00137705:
      FUN_001a7aba(local_14,local_18);
      return uVar5;
    }
    puVar3 = local_18;
    if (local_20 == 0) {
      puVar3 = (undefined4 *)FUN_001a7f7c(&local_20,0);
    }
    param_2 = (int *)*puVar3;
    if ((param_2 == (int *)0x0) || (cVar1 = FUN_001a805e(&local_20,param_2), cVar1 == '\0'))
    goto LAB_00137700;
  } while( true );
}

/* FUN_0013779e @ 0x13779e (922 bytes) */
int FUN_0013779e(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  
LAB_001377ac:
  piVar9 = *(int **)(param_1 + 0x378);
  piVar5 = (int *)piVar9[2];
joined_r0x001377ba:
  if (piVar5 != (int *)0x0) {
    bVar3 = false;
    cVar4 = (**(code **)(*piVar9 + 0x24))(piVar9);
    do {
      if (cVar4 == '\0') {
        cVar4 = FUN_000e95be(piVar9);
        if ((((cVar4 != '\0') && (iVar7 = FUN_001a7d8a(piVar9 + 0x24), iVar7 < 3)) &&
            (iVar7 = FUN_000e97bc(piVar9), iVar7 == 1)) &&
           (iVar7 = FUN_000e97aa(piVar9), iVar7 == 1)) {
          piVar6 = (int *)FUN_000eac0c(piVar9,0);
          piVar8 = (int *)FUN_000eac7c(piVar9,0);
          cVar4 = FUN_000e95be(piVar6);
          if (((cVar4 != '\0') || (cVar4 = (**(code **)(*piVar6 + 0x1c))(piVar6), cVar4 != '\0')) &&
             ((cVar4 = FUN_000e95be(piVar8), cVar4 != '\0' ||
              (cVar4 = (**(code **)(*piVar8 + 0x20))(piVar8), cVar4 != '\0')))) {
            FUN_000eb0bc(piVar9,piVar6,piVar8);
            piVar5 = piVar8;
            goto LAB_0013790d;
          }
        }
LAB_00137911:
        piVar6 = (int *)piVar5[2];
        piVar9 = piVar5;
      }
      else {
        iVar7 = piVar9[0x4d];
        iVar1 = piVar9[0x4b];
        iVar2 = piVar9[0x4c];
        cVar4 = ((int (*)())FUN_001375b6)(param_1,piVar9,iVar7);
        if (cVar4 == '\0') {
          cVar4 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x21);
          if (((cVar4 != '\0') && (cVar4 = FUN_000e977a(iVar1), cVar4 == '\0')) &&
             ((iVar10 = FUN_000eac7c(iVar1,0), iVar10 == iVar7 &&
              ((iVar7 = FUN_001a7d8a(iVar1 + 0x90), iVar7 < 3 &&
               (iVar7 = FUN_001a7d8a(iVar2 + 0x90), 2 < iVar7)))))) {
            ((int (*)())FUN_00131fa6)(param_1,piVar9);
            piVar5 = (int *)piVar9[0x4b];
            bVar3 = true;
          }
          goto LAB_00137911;
        }
        piVar5 = (int *)FUN_000e9644(piVar9);
        if (piVar5 != (int *)0x0) {
          FUN_000f1b60(param_1,piVar5);
          piVar5[5] = piVar5[5] & 0xffffffef;
          (**(code **)(*piVar5 + 0xc))
                    (piVar5,*(uint *)(param_1 + 0x30) >> 7 & 1,*(undefined4 *)(param_1 + 8));
          piVar9[0x4a] = 0;
        }
        piVar9[3] = piVar9[3] | 0x100;
        piVar6 = (int *)FUN_000eac0c(piVar9,0);
        iVar1 = piVar9[0x3b];
        FUN_001a805e(piVar6[0x34],piVar9);
        piVar5 = (int *)FUN_000e9b7c(iVar7);
        FUN_001a805e(piVar5[0x35],iVar7);
        FUN_000ea91c(piVar6,piVar5);
        piVar5[0x3b] = iVar1;
        ((int (*)())FUN_00133820)(param_1,piVar9,iVar7);
        (**(code **)(*piVar6 + 0x48))(piVar6);
        (**(code **)(*piVar5 + 0x48))(piVar5);
        cVar4 = ((int (*)())FUN_001321e6)(param_1,piVar6,piVar5);
        if (cVar4 == '\0') {
LAB_0013790d:
          bVar3 = true;
          goto LAB_00137911;
        }
        piVar9 = (int *)FUN_000eac7c(piVar6,0);
        bVar3 = true;
        piVar6 = (int *)piVar9[2];
      }
      piVar5 = piVar6;
      if (piVar5 == (int *)0x0) goto LAB_00137a15;
      cVar4 = (**(code **)(*piVar9 + 0x24))(piVar9);
    } while( true );
  }
  goto LAB_00137a7e;
LAB_00137a15:
  if (!bVar3) {
LAB_00137a7e:
    FUN_000f0346(param_1,"remove_empty_graphs");
    return;
  }
  *(undefined4 *)(param_1 + 0x388) = 0;
  *(undefined4 *)(param_1 + 0x38c) = 0;
  *(undefined4 *)(param_1 + 0x390) = 0;
  cVar4 = FUN_000e1402(*(undefined4 *)(param_1 + 8),0x11);
  if (cVar4 == '\0') goto LAB_001377ac;
  FUN_00143642(param_1,0);
  piVar9 = *(int **)(param_1 + 0x378);
  piVar5 = (int *)piVar9[2];
  goto joined_r0x001377ba;
}

/* FUN_00137b38 @ 0x137b38 (39 bytes) */
int FUN_00137b38(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = 1;
  do {
    if (*(int *)(param_2 + -4 + iVar1 * 4) == param_1) {
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 5);
  return 0;
}

/* FUN_00137b60 @ 0x137b60 (29 bytes) */
int FUN_00137b60(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x2c) + 0x108) + 1;
  *(int *)(*(int *)(param_1 + 0x2c) + 0x108) = iVar1;
  return iVar1 + *(int *)(param_1 + 8);
}

/* FUN_00137b7e @ 0x137b7e (47 bytes) */
int FUN_00137b7e(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint *puVar1;
  byte bVar2;
  
  bVar2 = (byte)param_2 & 0x1f;
  puVar1 = (uint *)(*(int *)(param_1 + 0x420) + 8 + (param_2 >> 5) * 4);
  *puVar1 = *puVar1 & (-2 << bVar2 | 0xfffffffeU >> 0x20 - bVar2);
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x8000;
  return;
}

/* FUN_00137bae @ 0x137bae (34 bytes) */
int FUN_00137bae(param_1, param_2)
  int param_1;
  uint param_2;
{
  return *(uint *)(*(int *)(param_1 + 0x420) + 8 + (param_2 >> 5) * 4) >> ((byte)param_2 & 0x1f) & 1
  ;
}

/* FUN_00137bd0 @ 0x137bd0 (145 bytes) */
int FUN_00137bd0(param_1)
  int param_1;
{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_18;
  
  iVar5 = *(int *)(param_1 + 8);
  piVar1 = *(int **)(iVar5 + 0x54);
  iVar3 = (**(code **)(*piVar1 + 0x138))(piVar1,iVar5);
  iVar4 = (**(code **)(*piVar1 + 0x140))(piVar1,iVar5);
  iVar5 = (**(code **)(*piVar1 + 0x13c))(piVar1,iVar5);
  iVar5 = iVar3 + iVar4 + iVar5;
  if (iVar5 < 1) {
    return 0;
  }
  iVar3 = 0;
  local_18 = 0;
  do {
    cVar2 = ((int (*)())FUN_00137bae)(param_1,iVar3);
    local_18 = local_18 + (uint)(cVar2 == '\0');
    iVar3 = iVar3 + 1;
  } while (iVar5 != iVar3);
  return local_18;
}

/* FUN_00137c62 @ 0x137c62 (38 bytes) */
int FUN_00137c62(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint *puVar1;
  
  puVar1 = (uint *)(*(int *)(param_1 + 0x420) + 8 + (param_2 >> 5) * 4);
  *puVar1 = *puVar1 | 1 << ((byte)param_2 & 0x1f);
  return;
}

/* FUN_00137c88 @ 0x137c88 (129 bytes) */
int FUN_00137c88(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int local_14;
  
  iVar3 = *(int *)(param_1 + 0x430 + param_2 * 4);
  iVar1 = *(int *)(param_1 + 0x43c + param_2 * 4);
  if (iVar3 < iVar1) {
    local_14 = -1;
    iVar4 = iVar3;
    do {
      cVar2 = ((int (*)())FUN_00137bae)(param_1,iVar4);
      if ((cVar2 == '\0') && (local_14 < iVar4)) {
        local_14 = iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar1 != iVar4);
    iVar3 = local_14 - iVar3;
    if (local_14 < 0) {
      iVar3 = local_14;
    }
    return iVar3;
  }
  return -1;
}

