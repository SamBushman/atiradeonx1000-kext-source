#include "decls.h"

/* FUN_0002a122 @ 0x2a122 (157 bytes) */
int FUN_0002a122(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(int *)(param_1 + 0x267c) + 1U >> 1;
  uVar1 = (uVar3 - 1) * 0x10000;
  *param_2 = uVar1 | 0x854;
  param_2 = param_2 + 1;
  if (uVar3 != 0) {
    uVar2 = 0;
    do {
      *param_2 = *(uint *)(*(int *)(param_1 + 0x2680) + uVar2 * 4);
      param_2 = param_2 + 1;
      uVar2 = uVar2 + 1;
    } while (uVar3 != uVar2);
  }
  *param_2 = uVar1 | 0x878;
  param_2 = param_2 + 1;
  if (uVar3 != 0) {
    uVar1 = 0;
    do {
      *param_2 = *(uint *)(*(int *)(param_1 + 0x2684) + uVar1 * 4);
      param_2 = param_2 + 1;
      uVar1 = uVar1 + 1;
    } while (uVar3 != uVar1);
  }
  *param_2 = 0x82d;
  param_2[1] = *(uint *)(param_1 + 0x26cc);
  return param_2 + 2;
}

/* FUN_0002a1bf @ 0x2a1bf (146 bytes) */
int FUN_0002a1bf(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = (int)((*(byte *)(param_1 + 0x26d0) & 0x1f) + 1) >> 1;
  *param_2 = (uVar1 * 3 + -1) * 0x10000 | 0x831;
  param_2 = param_2 + 1;
  if (uVar1 != 0) {
    uVar3 = 0;
    iVar2 = 0;
    do {
      *param_2 = *(uint *)(*(int *)(param_1 + 0x26d4) + uVar3 * 4);
      param_2[1] = *(uint *)(*(int *)(param_1 + 0x26d8) + iVar2);
      param_2[2] = *(uint *)(*(int *)(param_1 + 0x26d8) + 4 + iVar2);
      param_2 = param_2 + 3;
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 8;
    } while (uVar3 < uVar1);
  }
  *param_2 = 0x830;
  param_2[1] = *(uint *)(param_1 + 0x26d0);
  return param_2 + 2;
}

/* FUN_0002a251 @ 0x2a251 (1226 bytes) */
int FUN_0002a251(param_1, param_2)
  int param_1;
  uint *param_2;
{
  short sVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  char cVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  int local_20;
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar2 = *(int *)(param_1 + 4);
  uVar8 = param_2[3];
  bVar11 = (uVar8 & 0x10000000) != *(uint *)(param_1 + 0x2780);
  if (((((*param_2 != 0) || (param_2[1] != 0)) || (param_2[2] != 0)) ||
      (((uVar8 & 0xffefffff) != 0 || (param_2[4] != 0)))) || (bVar11)) {
    if ((((param_2[2] & 0x3f000008) != 0) || ((uVar8 & 0x4c00003) != 0)) ||
       ((*(char *)(iVar2 + 0x2a43) != '\0' || (bVar11)))) {
      FUN_0008b899(param_1,param_2);
      FUN_0008b774(param_1);
    }
    if (*(char *)(iVar2 + 0x20) == '\0') {
      FUN_000a60e5(param_1);
    }
    FUN_000630f6(param_1);
    FUN_0008b868(param_1);
    if (((*param_2 & 0x20000000) == 0) && (*(char *)(iVar2 + 0x2a43) == '\0')) {
      if ((*param_2 & 0x180) != 0) goto LAB_0002a34c;
LAB_0002a456:
      if (*(char *)(iVar2 + 0x2a43) != '\0') goto LAB_0002a34c;
      sVar1 = (short)param_2[1];
    }
    else {
      FUN_00020b2d(iVar2,0);
      if ((*param_2 & 0x180) == 0) goto LAB_0002a456;
LAB_0002a34c:
      if (*(int *)(iVar2 + 0x150) == 0) {
        iVar3 = *(int *)(param_1 + 4);
        iVar10 = *(int *)(iVar3 + 0x10);
        local_20 = 4;
        iVar9 = param_1;
        do {
          uVar6 = FUN_00014b91(*(undefined2 *)(iVar10 + 0x2dba),*(undefined4 *)(iVar3 + 0x154));
          *(undefined4 *)(iVar9 + 0x2460) = uVar6;
          iVar10 = iVar10 + 2;
          iVar9 = iVar9 + 4;
          local_20 = local_20 + -1;
        } while (local_20 != 0);
        puVar7 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x22d);
        *(undefined4 **)(param_1 + 0x274c) = puVar7;
        if ((((*(int *)(param_1 + 0x2460) == 1) &&
             (uVar8 = *(uint *)(iVar3 + 0x154), (uVar8 & 0x800) == 0)) && ((uVar8 & 0x20) != 0)) &&
           ((uVar8 & 0x400) != 0)) {
          (**(code **)(param_1 + 0x275c))(param_1,puVar7);
          if (*(int *)(iVar3 + 0x1e4) + 0x28U < *(uint *)(iVar3 + 0x1dc)) {
            FUN_00017c77(iVar3,0x1000000);
          }
          uVar8 = *(uint *)(iVar3 + 0x3c) | 0x800;
          *(uint *)(iVar3 + 0x3c) = uVar8;
          *(uint *)(iVar3 + 0x154) = uVar8;
          local_1c = *(undefined4 *)(*(int *)(iVar3 + 0xf8) + 8);
          local_18 = *(uint *)(iVar3 + 0x3c) & 0xffff3fc0;
          local_14 = *(undefined4 *)(iVar3 + 0xfc);
          local_10 = *(undefined4 *)(iVar3 + 0x100);
          _io_connect_method_scalarI_structureI(*(undefined4 *)(iVar3 + 4),0,&local_1c,4,0,0);
          puVar7 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x22d);
          *(undefined4 **)(param_1 + 0x274c) = puVar7;
        }
        cVar5 = FUN_00017bd8(iVar3,*(undefined4 *)(param_1 + 0x2460));
        if (cVar5 == '\0') {
          puVar4 = *(uint **)(iVar3 + 0x1d8);
          *puVar4 = *puVar4 | (int)puVar7 - (int)puVar4 >> 2;
          *(undefined4 **)(iVar3 + 0x1d8) = puVar7;
          *puVar7 = 0x29000000;
          puVar7[1] = *(undefined4 *)(param_1 + 0x2460);
          puVar7[2] = *(undefined4 *)(param_1 + 0x2464);
          puVar7[3] = *(undefined4 *)(param_1 + 0x2468);
          puVar7[4] = *(undefined4 *)(param_1 + 0x246c);
          puVar7[5] = 0x11;
        }
        else {
          puVar4 = *(uint **)(iVar3 + 0x1d8);
          *puVar4 = *puVar4 | (int)puVar7 - (int)puVar4 >> 2;
          *(undefined4 **)(iVar3 + 0x1d8) = puVar7;
          *puVar7 = 0x29000000;
          puVar7[1] = *(undefined4 *)(param_1 + 0x2460);
          puVar7[2] = 0x11;
          puVar7[3] = 0x11;
          puVar7[4] = 0x11;
          puVar7[5] = 0x10;
        }
        puVar7[6] = *(undefined4 *)(param_1 + 0x1ae0);
        puVar7[7] = *(undefined4 *)(param_1 + 0x1ab0);
        *(undefined4 **)(param_1 + 0x274c) = puVar7 + 0x39;
        (**(code **)(param_1 + 0x275c))(param_1,puVar7 + 0x39);
      }
      sVar1 = (short)param_2[1];
    }
    if (sVar1 != 0) {
      ((int (*)())FUN_0002ad3a)(param_1,param_2);
    }
    if (*(char *)(param_1 + 0x2435) == '\0') {
      uVar8 = *(uint *)(param_1 + 0x2488);
    }
    else {
      uVar8 = *(uint *)(param_1 + 0x2488) | 4;
      *(uint *)(param_1 + 0x2488) = uVar8;
      *(undefined4 *)(param_1 + 0x2494) = 0;
      *(int *)(param_1 + 0x2440) = param_1 + 0x249c;
      *(int *)(param_1 + 0x2444) = param_1 + 0x24bc;
    }
  }
  else {
    uVar8 = *(uint *)(param_1 + 0x2488);
  }
  if (((uVar8 & 4) == 0) && (*(char *)(param_1 + 0x247d) == '\0')) {
    if (*(char *)(param_1 + 0x2595) == '\0') {
      if ((*(byte *)((int)param_2 + 0xe) & 0x10) == 0) {
LAB_0002a3d1:
        if ((*param_2 & 0x800000) == 0) goto LAB_0002a3ec;
      }
    }
    else if (*(int *)(*(int *)(iVar2 + 0x14) + 0x120) == 0) goto LAB_0002a3d1;
  }
  FUN_00025278(param_1,param_2);
LAB_0002a3ec:
  if ((((*(byte *)((int)param_2 + 0xe) & 0x10) != 0) || ((*(byte *)(param_1 + 0x2488) & 4) != 0)) ||
     (*(char *)(param_1 + 0x247d) != '\0')) {
    FUN_0001d6e9(param_1,param_2);
  }
  return;
}

/* FUN_0002a71b @ 0x2a71b (161 bytes) */
int FUN_0002a71b(param_1)
  int param_1;
{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x208);
  puVar1[7] = puVar1[7] | 1;
  *(undefined4 **)(param_1 + 0x298c) = puVar1 + 8;
  *(code **)(param_1 + 0x2998) = FUN_00029f77;
  *(code **)(param_1 + 0x299c) = FUN_00029f85;
  FUN_0004f0f0(param_1 + 0x240);
  *puVar1 = *(undefined4 *)(param_1 + 0x1d20);
  puVar1[1] = *(undefined4 *)(param_1 + 0x1cf0);
  puVar1[5] = *(int *)(param_1 + 0x298c) - (int)(puVar1 + 8) >> 2;
  *(code **)(param_1 + 0x2998) = FUN_00029f24;
  *(code **)(param_1 + 0x299c) = FUN_00029f63;
  if ((uint)puVar1[5] <= (uint)puVar1[4]) {
    return;
  }
                    
  _exit(1);
}

/* FUN_0002a7bc @ 0x2a7bc (701 bytes) */
int FUN_0002a7bc(param_1, param_2)
  int param_1;
  int param_2;
{
  void *pvVar1;
  undefined1 uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  pvVar1 = (void *)(param_1 + 0x240);
  _memset(pvVar1,0,0x2950);
  *(undefined1 *)(param_1 + 0x2b7c) = 1;
  *(undefined1 *)(param_1 + 0x2b7d) = 0;
  *(byte *)(param_1 + 0x258c) = *(byte *)(param_1 + 0x258c) & 0xfc | 1;
  uVar2 = ((int (*)())FUN_0002d168)(*(undefined4 *)(param_1 + 0x154));
  *(undefined1 *)(param_1 + 0x2b7f) = uVar2;
  *(int *)(param_1 + 0x2680) = param_1 + 0x26dc;
  *(int *)(param_1 + 0x2684) = param_1 + 0x26fc;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  pvVar3 = _malloc(0x44);
  *(void **)(param_1 + 0x27cc) = pvVar3;
  _memset(pvVar3,0,0x44);
  pvVar3 = _malloc(0x44);
  *(void **)(param_1 + 0x27d0) = pvVar3;
  _memset(pvVar3,0,0x44);
  FUN_0001e57a(param_1);
  *(undefined4 *)(param_1 + 0x2a64) = *(undefined4 *)(param_2 + 0x30);
  if (*(char *)(param_1 + 0x2a6a) == '\0') {
    FUN_000156a4(param_1);
  }
  *(undefined1 *)(param_1 + 0x2a43) = 1;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  FUN_00017873(param_1);
  *(undefined4 *)(param_1 + 0x2610) = 1;
  *(undefined4 *)(param_1 + 0x261c) = 1;
  *(undefined4 *)(param_1 + 0x29d8) = 0xfff0;
  local_10 = 5;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  _io_connect_method_scalarI_scalarO(*(undefined4 *)(param_1 + 4),0x14,0,0,&local_38,&local_10);
  *(undefined4 *)(param_1 + 0x2610) = local_38;
  *(undefined4 *)(param_1 + 0x2614) = local_34;
  *(undefined4 *)(param_1 + 0x2618) = local_30;
  *(undefined4 *)(param_1 + 0x261c) = local_2c;
  iVar4 = *(int *)(param_1 + 0x1e4);
  *(int *)(param_1 + 0x1d8) = iVar4 + 0x1c;
  *(int *)(param_1 + 0x1dc) = iVar4 + 0x20;
  *(int *)(param_1 + 0x1e0) = iVar4 + -0x74 + *(int *)(iVar4 + 0x10) * 4;
  *(undefined4 *)(iVar4 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  FUN_000a53a7(param_1);
  FUN_0009fd44(pvVar1);
  FUN_00051bac(pvVar1);
  *(undefined4 *)(param_1 + 0x26a0) = 0;
  *(undefined4 *)(param_1 + 0x26b0) = 0;
  *(undefined4 *)(param_1 + 0x2b78) = 0;
  *(undefined4 *)(param_1 + 0x2b74) = 0;
  iVar4 = 0x10;
  pvVar3 = pvVar1;
  do {
    *(undefined1 *)((int)pvVar3 + 0x2784) = 0;
    pvVar3 = (void *)((int)pvVar3 + 1);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined1 *)(param_1 + 0x26bd) = 1;
  *(undefined1 *)(param_1 + 0x2a43) = 1;
  *(undefined4 *)(param_1 + 0x26c8) = 7;
  *(undefined1 *)(param_1 + 0x2b82) = 0;
  local_24 = 0xffffffff;
  local_20 = 0x3ffffff;
  local_1c = 0xfffffffd;
  local_18 = 0x7ffffff;
  local_14 = 0xffffffff;
  *(undefined1 *)(param_1 + 0x2b88) = 1;
  ((void (*)())FUN_000a81f5)(pvVar1,&local_24);
  ((int (*)())FUN_0002a71b)(param_1);
  return;
}

/* FUN_0002aa79 @ 0x2aa79 (207 bytes) */
int FUN_0002aa79(param_1)
  int param_1;
{
  if (*(void **)(param_1 + 0x27cc) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x27cc));
  }
  if (*(void **)(param_1 + 0x27d0) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x27d0));
  }
  if (*(char *)(param_1 + 0x2a6a) == '\0') {
    FUN_0001595c(param_1);
    FUN_0002380d(param_1);
    if (*(uint *)(param_1 + 0x1dc) <= *(int *)(param_1 + 0x1e4) + 0x28U) goto LAB_0002aad0;
  }
  else {
    FUN_0002380d(param_1);
    if (*(uint *)(param_1 + 0x1dc) <= *(int *)(param_1 + 0x1e4) + 0x28U) goto LAB_0002aad0;
  }
  FUN_00017c77(param_1,0x1000000);
LAB_0002aad0:
  FUN_00051cf9(param_1 + 0x240);
  FUN_0009fdbd(param_1 + 0x240);
  FUN_000a5d2f(param_1);
  if (*(int *)(param_1 + 0x2b74) != 0) {
    _vfree(*(int *)(param_1 + 0x2b74));
  }
  *(undefined4 *)(param_1 + 0x2b78) = 0;
  *(undefined4 *)(param_1 + 0x2b74) = 0;
  return;
}

/* FUN_0002ab48 @ 0x2ab48 (46 bytes) */
int FUN_0002ab48(param_1)
  int param_1;
{
  if (*(uint *)(param_1 + 0x1dc) <= *(int *)(param_1 + 0x1e4) + 0x28U) {
    return;
  }
  FUN_00017c77(param_1,0x1000000);
  return;
}

/* FUN_0002ab76 @ 0x2ab76 (241 bytes) */
int FUN_0002ab76(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  uint param_3;
  uint param_4;
{
  int iVar1;
  
  if ((int)param_4 < 4) {
    param_4 = FUN_0002a011(param_1,param_3,param_4);
  }
  else {
    iVar1 = (param_3 >> 3 & 1) + (param_3 >> 2 & 1) + (param_3 >> 1 & 1) + (param_3 & 1);
    if (((iVar1 == 2) || (iVar1 == 0)) || (param_3 == 2)) goto LAB_0002abf0;
    if (iVar1 == 3) {
      param_4 = param_4 & 0xfffffffc;
    }
    else if (param_3 == 4) {
      param_4 = ((int)param_4 / 3) * 3;
    }
    else {
      param_4 = param_4 & 0xfffffffe;
    }
  }
  if (param_4 == 0) {
    return 0;
  }
LAB_0002abf0:
  if (*(char *)(param_1 + 0x2b80) != '\0') {
    FUN_000a2046(param_1 + 0x240,param_3);
  }
  if (*(int *)(param_1 + 0x1b68) != 0) {
    FUN_0002a0bb(param_1 + 0x240,param_3);
  }
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  return param_4;
}

/* FUN_0002ac68 @ 0x2ac68 (210 bytes) */
int FUN_0002ac68(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint *param_4;
{
  byte bVar1;
  uint *puVar2;
  int *piVar3;
  
  if (param_2 == 0) {
    puVar2 = *(uint **)(param_1 + 0x1d8);
    *puVar2 = *puVar2 | (int)param_4 - (int)puVar2 >> 2;
    *(uint **)(param_1 + 0x1d8) = param_4;
    *param_4 = param_3 * 0x1000000 + 0x16000000;
    return param_4 + 1;
  }
  piVar3 = (int *)((uint)(param_4 + 0xb) & 0xffffffe0);
  *param_4 = (((int)piVar3 - (int)param_4) + -8) * 0x4000 | 0xc0001000;
  piVar3[-1] = (int)piVar3 - (int)param_4;
  puVar2 = *(uint **)(param_1 + 0x1d8);
  *puVar2 = *puVar2 | (int)piVar3 - (int)puVar2 >> 2;
  *(int **)(param_1 + 0x1d8) = piVar3;
  *piVar3 = param_3 * 0x1000000 + 0x6000000;
  piVar3[1] = **(int **)(param_2 + 0x34);
  *(int *)(*(int *)(param_2 + 0x34) + 0x10) = *(int *)(*(int *)(param_2 + 0x34) + 0x10) + 0x10000;
  bVar1 = *(byte *)(param_2 + 0xc9);
  piVar3[2] = *(int *)(param_2 + 0x40);
  if ((bVar1 & 3) == 0) {
    return (uint *)(piVar3 + 3);
  }
  piVar3[3] = *(uint *)(param_2 + 0xcc) & 0x3fffffff | (uint)*(byte *)(param_2 + 0x38) << 0x18;
  return (uint *)(piVar3 + 4);
}

/* FUN_0002ad3a @ 0x2ad3a (476 bytes) */
int FUN_0002ad3a(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int local_14;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar7 = iVar1;
  for (uVar6 = (uint)*(ushort *)(param_2 + 4); uVar6 != 0; uVar6 = uVar6 >> 1) {
    if (((((uVar6 & 1) != 0) && (iVar2 = *(int *)(iVar7 + 0x18c), iVar2 != 0)) &&
        (*(short *)(*(int *)(iVar2 + 0x30) + 2) == 0x1902)) && (*(char *)(iVar2 + 200) == '\x01')) {
      puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x3fa);
      *(undefined4 **)(param_1 + 0x274c) = puVar4;
      puVar3 = *(uint **)(iVar1 + 0x1d8);
      *puVar3 = *puVar3 | (int)puVar4 - (int)puVar3 >> 2;
      *(undefined4 **)(iVar1 + 0x1d8) = puVar4;
      *puVar4 = 0x45000000;
      puVar4[1] = 0x3ed;
      puVar4[2] = 0xd;
      puVar4[3] = **(undefined4 **)(*(int *)(iVar7 + 0x18c) + 0x34);
      puVar4[4] = (uint)*(byte *)(*(int *)(iVar7 + 0x18c) + 0x38);
      puVar4[0x3ed] = &UINT_000013c4;
      puVar4[0x3ef] = 0x113c8;
      puVar4[0x3f2] = 0x13cd;
      puVar4[0x3f4] = &UINT_000013cc;
      puVar4[0x3f6] = 0x13ca;
      *(undefined4 **)(param_1 + 0x274c) = puVar4 + 0x3f8;
      (**(code **)(param_1 + 0x275c))(param_1,puVar4 + 0x3f8);
      if (*(int *)(iVar1 + 0x1e4) + 0x28U < *(uint *)(iVar1 + 0x1dc)) {
        FUN_00017c77(iVar1,0x1000000);
      }
      *(undefined1 *)(*(int *)(iVar7 + 0x18c) + 200) = 0;
    }
    iVar7 = iVar7 + 4;
  }
  uVar6 = (uint)*(ushort *)(param_2 + 4);
  uVar5 = (**(code **)(param_1 + 0x2758))(param_1,0x96);
  *(undefined4 *)(param_1 + 0x274c) = uVar5;
  if (uVar6 != 0) {
    local_14 = 0;
    iVar7 = iVar1;
    do {
      while ((uVar6 & 1) != 0) {
        uVar5 = ((int (*)())FUN_0002ac68)(iVar1,*(undefined4 *)(iVar7 + 0x18c),local_14,uVar5);
        local_14 = local_14 + 1;
        iVar7 = iVar7 + 4;
        uVar6 = uVar6 >> 1;
        if (uVar6 == 0) goto LAB_0002aee4;
      }
      local_14 = local_14 + 1;
      iVar7 = iVar7 + 4;
      uVar6 = uVar6 >> 1;
    } while (uVar6 != 0);
  }
LAB_0002aee4:
  *(undefined4 *)(param_1 + 0x274c) = uVar5;
                    
                    
  (**(code **)(param_1 + 0x275c))();
  return;
}

/* FUN_0002af16 @ 0x2af16 (361 bytes) */
int FUN_0002af16(param_1, param_2)
  int param_1;
  uint param_2;
{
  byte bVar1;
  byte bVar2;
  
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffe7fff;
  bVar2 = *(byte *)(param_1 + 0x1a) & 0xf1;
  *(byte *)(param_1 + 0x1a) = bVar2;
  if ((*(byte *)(param_1 + 0x16) & 0xe0) == 0) {
    *(byte *)(param_1 + 0x1a) = bVar2;
    if (param_2 == 0x2700) {
      bVar2 = *(byte *)(param_1 + 0x15) & 0x87 | 0x28;
      *(byte *)(param_1 + 0x15) = bVar2;
      goto LAB_0002afae;
    }
    if (param_2 < 0x2701) {
      if (param_2 == 0x2600) {
        bVar2 = *(byte *)(param_1 + 0x15) & 0x87 | 8;
        *(byte *)(param_1 + 0x15) = bVar2;
        goto LAB_0002afae;
      }
      if (param_2 == 0x2601) {
        bVar2 = *(byte *)(param_1 + 0x15) & 0x87 | 0x10;
        *(byte *)(param_1 + 0x15) = bVar2;
        goto LAB_0002afae;
      }
    }
    else {
      if (param_2 == 0x2702) {
        bVar2 = *(byte *)(param_1 + 0x15) & 0x87 | 0x48;
        *(byte *)(param_1 + 0x15) = bVar2;
        goto LAB_0002afae;
      }
      if (param_2 < 0x2702) {
        bVar2 = *(byte *)(param_1 + 0x15) & 0x87 | 0x30;
        *(byte *)(param_1 + 0x15) = bVar2;
        goto LAB_0002afae;
      }
      if (param_2 == 0x2703) {
        bVar2 = *(byte *)(param_1 + 0x15) & 0x87 | 0x50;
        *(byte *)(param_1 + 0x15) = bVar2;
        goto LAB_0002afae;
      }
    }
    bVar2 = *(byte *)(param_1 + 0x15);
    goto LAB_0002afae;
  }
  bVar1 = *(byte *)(param_1 + 0x15);
  bVar2 = bVar1 | 0x18;
  *(byte *)(param_1 + 0x15) = bVar2;
  if (param_2 == 0x2700) {
LAB_0002afa5:
    bVar2 = bVar1 & 0x9f | 0x38;
    *(byte *)(param_1 + 0x15) = bVar2;
  }
  else {
    if (param_2 < 0x2701) {
      if (param_2 - 0x2600 < 2) {
        bVar2 = bVar1 & 0x9f | 0x18;
        *(byte *)(param_1 + 0x15) = bVar2;
      }
      goto LAB_0002afae;
    }
    if (param_2 != 0x2702) {
      if (param_2 < 0x2702) goto LAB_0002afa5;
      if (param_2 != 0x2703) goto LAB_0002afae;
    }
    bVar2 = bVar1 & 0x9f | 0x58;
    *(byte *)(param_1 + 0x15) = bVar2;
  }
LAB_0002afae:
  if (*(char *)(param_1 + 0x35) != '\0') {
    *(byte *)(param_1 + 0x1a) = *(byte *)(param_1 + 0x1a) & 0xf1;
    if (1 < (bVar2 >> 3 & 3)) {
      bVar2 = bVar2 & 0xe7 | 8;
      *(byte *)(param_1 + 0x15) = bVar2;
    }
    if ((bVar2 & 0x60) == 0x40) {
      bVar2 = bVar2 & 0x9f | 0x20;
      *(byte *)(param_1 + 0x15) = bVar2;
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffe7fff;
    }
  }
  *(bool *)(param_1 + 0x36) = (bVar2 & 0x1e) == 10;
  return;
}

/* FUN_0002b07f @ 0x2b07f (112 bytes) */
int FUN_0002b07f(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  
  if ((*(byte *)(param_1 + 0x16) & 0xe0) == 0) {
    if (param_2 == 0x2600) {
      bVar1 = *(byte *)(param_1 + 0x15) & 0xf9 | 2;
      *(byte *)(param_1 + 0x15) = bVar1;
    }
    else if (param_2 == 0x2601) {
      bVar1 = *(byte *)(param_1 + 0x15) & 0xf9 | 4;
      *(byte *)(param_1 + 0x15) = bVar1;
    }
    else {
      bVar1 = *(byte *)(param_1 + 0x15);
    }
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x15) | 6;
    *(byte *)(param_1 + 0x15) = bVar1;
  }
  if ((*(char *)(param_1 + 0x35) != '\0') && (1 < (bVar1 >> 1 & 3))) {
    bVar1 = bVar1 & 0xf9 | 2;
    *(byte *)(param_1 + 0x15) = bVar1;
  }
  *(bool *)(param_1 + 0x36) = (bVar1 & 0x1e) == 10;
  return;
}

/* FUN_0002b0ef @ 0x2b0ef (819 bytes) */
int FUN_0002b0ef(param_1)
  int param_1;
{
  int iVar1;
  float in_XMM0_Da;
  uint uVar2;
  float fVar3;
  float in_XMM1_Da;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  double dVar7;
  float in_XMM2_Da;
  float fVar8;
  float fVar9;
  double dVar10;
  float in_XMM3_Da;
  double dVar11;
  float fVar12;
  float local_11c;
  uint local_fc;
  float local_bc;
  float local_8c;
  float local_7c;
  float local_6c;
  float local_5c;
  double local_4c;
  double local_3c;
  
  if (*(char *)(param_1 + 0x37) != '\0') {
    if (0.0 <= in_XMM0_Da) {
      dVar11 = DOUBLE_001cf330;
      local_8c = FLOAT_001c5ba4;
      if (in_XMM0_Da <= FLOAT_001c5ba4) {
        dVar11 = (double)in_XMM0_Da;
        local_8c = in_XMM0_Da;
      }
    }
    else {
      local_8c = 0.0;
      dVar11 = 0.0;
    }
    if (in_XMM1_Da < 0.0) {
      local_7c = 0.0;
      local_4c = 0.0;
    }
    else {
      local_7c = FLOAT_001c5ba4;
      local_4c = DOUBLE_001cf330;
      if (in_XMM1_Da <= FLOAT_001c5ba4) {
        local_4c = (double)in_XMM1_Da;
        local_7c = in_XMM1_Da;
      }
    }
    if (0.0 <= in_XMM2_Da) {
      local_6c = FLOAT_001c5ba4;
      local_3c = DOUBLE_001cf330;
      if (in_XMM2_Da <= FLOAT_001c5ba4) {
        local_3c = (double)in_XMM2_Da;
        local_6c = in_XMM2_Da;
      }
    }
    else {
      local_6c = 0.0;
      local_3c = 0.0;
    }
    if (in_XMM3_Da < 0.0) {
      local_5c = 0.0;
      dVar10 = 0.0;
    }
    else {
      local_5c = FLOAT_001c5ba4;
      dVar10 = DOUBLE_001cf330;
      if (in_XMM3_Da <= FLOAT_001c5ba4) {
        dVar10 = (double)in_XMM3_Da;
        local_5c = in_XMM3_Da;
      }
    }
    dVar11 = dVar11 * DOUBLE_001cf380;
    dVar7 = dVar11;
    if (DAT_001c60c0 <= dVar11) {
      dVar7 = DAT_001c60c0;
    }
    if (dVar7 <= 0.0) {
      dVar7 = 0.0;
    }
    uVar4 = (uint)(dVar7 - (double)(-(ulonglong)(DAT_001c60b0 <= dVar11) & (ulonglong)DAT_001c60b0))
    ;
    local_bc = (float)((uint)(DAT_001c60b0 <= dVar11) * -0x80000000 ^ uVar4);
    local_4c = local_4c * DOUBLE_001cf380;
    dVar11 = local_4c;
    if (DAT_001c60c0 <= local_4c) {
      dVar11 = DAT_001c60c0;
    }
    if (dVar11 <= 0.0) {
      dVar11 = 0.0;
    }
    uVar5 = (uint)(dVar11 - (double)(-(ulonglong)(DAT_001c60b0 <= local_4c) &
                                    (ulonglong)DAT_001c60b0));
    local_3c = local_3c * DOUBLE_001cf380;
    dVar11 = local_3c;
    if (DAT_001c60c0 <= local_3c) {
      dVar11 = DAT_001c60c0;
    }
    if (dVar11 <= 0.0) {
      dVar11 = 0.0;
    }
    uVar6 = (uint)(dVar11 - (double)(-(ulonglong)(DAT_001c60b0 <= local_3c) &
                                    (ulonglong)DAT_001c60b0));
    local_fc = (uint)(DAT_001c60b0 <= local_3c) * -0x80000000 ^ uVar6;
    dVar10 = dVar10 * DOUBLE_001cf380;
    dVar11 = dVar10;
    if (DAT_001c60c0 <= dVar10) {
      dVar11 = DAT_001c60c0;
    }
    if (dVar11 <= 0.0) {
      dVar11 = 0.0;
    }
    uVar2 = (uint)(dVar11 - (double)((ulonglong)DAT_001c60b0 & -(ulonglong)(DAT_001c60b0 <= dVar10))
                  );
    local_11c = (float)((uint)(DAT_001c60b0 <= dVar10) * -0x80000000 ^ uVar2);
    switch(*(char *)(param_1 + 0x37)) {
    default:
      *(undefined4 *)(param_1 + 0x28) = 0;
      return;
    case '\x01':
    case '\x03':
      local_11c = local_bc;
      break;
    case '\x02':
      break;
    case '\x04':
    case '\x0f':
    case '\x16':
      local_11c = (float)(uVar2 << 8 | (uint)local_bc);
      break;
    case '\x05':
      local_11c = (float)(((uint)local_bc & 0xf8) << 8 | (uVar5 & 0xfc) << 3 | local_fc >> 3);
      break;
    case '\x06':
      local_11c = (float)(((uint)local_11c & 0xf0) << 8 | ((uint)local_bc & 0xf0) << 4 |
                          uVar5 & 0xf0 | local_fc >> 4);
      break;
    case '\a':
      local_11c = (float)(((uint)local_11c & 0x80) << 8 | ((uint)local_bc & 0xf8) << 7 |
                          (uVar5 & 0xf8) << 2 | local_fc >> 3);
      break;
    case '\b':
    case '\v':
    case '\f':
    case '\r':
    case '\x0e':
    case '\x11':
    case '\x17':
    case '\x1d':
    case '&':
    case '\'':
      local_11c = (float)(uVar4 << 0x10 | uVar2 << 0x18 | uVar5 << 8 | local_fc);
      break;
    case '\t':
    case '\n':
    case '\x12':
    case '\x18':
    case '\x1e':
      local_11c = (float)(uVar6 << 0x10 | uVar2 << 0x18 | uVar5 << 8 | (uint)local_bc);
      break;
    case '\x10':
      fVar8 = local_8c * FLOAT_001c5c04 + FLOAT_001c5bd4;
      if (fVar8 <= 0.0) {
        fVar8 = 0.0;
      }
      uVar4 = (int)(fVar8 - (float)((uint)_UNK_001c60d0 & -(uint)(_UNK_001c60d0 <= fVar8))) +
              (uint)(_UNK_001c60d0 <= fVar8) * -0x80000000 | -(uint)(_UNK_001c60e0 <= fVar8);
      local_11c = (float)(uVar4 << 0x10 | uVar4);
      break;
    case '\x13':
    case '\x15':
      local_11c = in_XMM0_Da;
      break;
    case '\x14':
      local_11c = in_XMM3_Da;
      break;
    case '\x19':
    case '\x1b':
      fVar8 = local_8c * FLOAT_001c5c04 + FLOAT_001c5bd4;
      if (fVar8 <= 0.0) {
        fVar8 = 0.0;
      }
      uVar4 = (int)(fVar8 - (float)((uint)_UNK_001c60d0 & -(uint)(_UNK_001c60d0 <= fVar8))) |
              -(uint)(_UNK_001c60e0 <= fVar8);
      local_11c = (float)(uVar4 << 0x10 | uVar4 & 0xffff);
      break;
    case '\x1a':
      fVar8 = local_5c * FLOAT_001c5c04 + FLOAT_001c5bd4;
      if (fVar8 <= 0.0) {
        fVar8 = 0.0;
      }
      uVar4 = (int)(fVar8 - (float)((uint)_UNK_001c60d0 & -(uint)(_UNK_001c60d0 <= fVar8))) |
              -(uint)(_UNK_001c60e0 <= fVar8);
      local_11c = (float)(uVar4 << 0x10 | uVar4 & 0xffff);
      break;
    case '\x1c':
      fVar8 = local_8c * FLOAT_001c5c04 + FLOAT_001c5bd4;
      if (fVar8 <= 0.0) {
        fVar8 = 0.0;
      }
      fVar12 = FLOAT_001c5bd4 + FLOAT_001c5c04 * local_5c;
      if (fVar12 <= 0.0) {
        fVar12 = 0.0;
      }
      local_11c = (float)(((int)(fVar8 - (float)(-(uint)(_UNK_001c60d0 <= fVar8) &
                                                (uint)_UNK_001c60d0)) |
                          -(uint)(_UNK_001c60e0 <= fVar8)) & 0xffff |
                         ((int)(fVar12 - (float)((uint)_UNK_001c60d0 &
                                                -(uint)(_UNK_001c60d0 <= fVar12))) |
                         -(uint)(_UNK_001c60e0 <= fVar12)) << 0x10);
      break;
    case '\x1f':
    case '!':
      uVar4 = FUN_0001b725();
      local_11c = (float)(uVar4 << 0x10 | uVar4);
      break;
    case ' ':
      uVar4 = FUN_0001b725(in_XMM3_Da);
      local_11c = (float)(uVar4 << 0x10 | uVar4);
      break;
    case '\"':
      uVar4 = FUN_0001b725();
      iVar1 = FUN_0001b725(in_XMM3_Da);
      local_11c = (float)(iVar1 << 0x10 | uVar4);
      break;
    case '#':
      fVar8 = local_8c * FLOAT_001c5c0c + FLOAT_001c5bd4;
      if (fVar8 <= 0.0) {
        fVar8 = 0.0;
      }
      fVar12 = local_5c * FLOAT_001c5c10 + FLOAT_001c5bd4;
      if (fVar12 <= 0.0) {
        fVar12 = 0.0;
      }
      fVar9 = local_6c * FLOAT_001c5c0c + FLOAT_001c5bd4;
      if (fVar9 <= 0.0) {
        fVar9 = 0.0;
      }
      fVar3 = FLOAT_001c5bd4 + FLOAT_001c5c0c * local_7c;
      if (fVar3 <= 0.0) {
        fVar3 = 0.0;
      }
      local_11c = (float)(((int)(fVar8 - (float)(-(uint)(_UNK_001c60d0 <= fVar8) &
                                                (uint)_UNK_001c60d0)) |
                          -(uint)(_UNK_001c60e0 <= fVar8)) & 0x3ff |
                         ((int)(fVar12 - (float)(-(uint)(_UNK_001c60d0 <= fVar12) &
                                                (uint)_UNK_001c60d0)) |
                         -(uint)(_UNK_001c60e0 <= fVar12)) << 0x1e |
                         (((int)(fVar9 - (float)(-(uint)(_UNK_001c60d0 <= fVar9) &
                                                (uint)_UNK_001c60d0)) |
                          -(uint)(_UNK_001c60e0 <= fVar9)) & 0x3ff) << 0x14 |
                         (((int)(fVar3 - (float)((uint)_UNK_001c60d0 &
                                                -(uint)(_UNK_001c60d0 <= fVar3))) |
                          -(uint)(_UNK_001c60e0 <= fVar3)) & 0x3ff) << 10);
      break;
    case '$':
      fVar8 = local_6c * FLOAT_001c5c0c + FLOAT_001c5bd4;
      if (fVar8 <= 0.0) {
        fVar8 = 0.0;
      }
      fVar12 = local_5c * FLOAT_001c5c10 + FLOAT_001c5bd4;
      if (fVar12 <= 0.0) {
        fVar12 = 0.0;
      }
      fVar9 = local_8c * FLOAT_001c5c0c + FLOAT_001c5bd4;
      if (fVar9 <= 0.0) {
        fVar9 = 0.0;
      }
      fVar3 = FLOAT_001c5bd4 + FLOAT_001c5c0c * local_7c;
      if (fVar3 <= 0.0) {
        fVar3 = 0.0;
      }
      local_11c = (float)(((int)(fVar8 - (float)(-(uint)(_UNK_001c60d0 <= fVar8) &
                                                (uint)_UNK_001c60d0)) |
                          -(uint)(_UNK_001c60e0 <= fVar8)) & 0x3ff |
                         ((int)(fVar12 - (float)(-(uint)(_UNK_001c60d0 <= fVar12) &
                                                (uint)_UNK_001c60d0)) |
                         -(uint)(_UNK_001c60e0 <= fVar12)) << 0x1e |
                         (((int)(fVar9 - (float)(-(uint)(_UNK_001c60d0 <= fVar9) &
                                                (uint)_UNK_001c60d0)) |
                          -(uint)(_UNK_001c60e0 <= fVar9)) & 0x3ff) << 0x14 |
                         (((int)(fVar3 - (float)((uint)_UNK_001c60d0 &
                                                -(uint)(_UNK_001c60d0 <= fVar3))) |
                          -(uint)(_UNK_001c60e0 <= fVar3)) & 0x3ff) << 10);
      break;
    case '(':
      local_11c = (float)((uint)local_bc & 0xe0 | (uVar5 & 0xe0) >> 3 | local_fc >> 6);
      break;
    case ')':
      fVar8 = local_8c * FLOAT_001c5c08 + FLOAT_001c5bd4;
      if (fVar8 <= 0.0) {
        fVar8 = 0.0;
      }
      local_11c = (float)(((int)(fVar8 - (float)((uint)_UNK_001c60d0 &
                                                -(uint)(_UNK_001c60d0 <= fVar8))) |
                          -(uint)(_UNK_001c60e0 <= fVar8)) << 8);
    }
    *(float *)(param_1 + 0x28) = local_11c;
    return;
  }
  return;
}

/* FUN_0002bc75 @ 0x2bc75 (183 bytes) */
int FUN_0002bc75(param_1)
  int param_1;
{
  int iVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  pbVar2 = *(byte **)(param_1 + 0x30);
  bVar3 = *pbVar2 & 0xf;
  *(byte *)(param_1 + 0x6c) = bVar3;
  iVar1 = *(short *)(pbVar2 + 0x3c) * 0x18;
  uVar5 = (uint)pbVar2[iVar1 + 0xaa];
  uVar4 = (uint)*(ushort *)(pbVar2 + iVar1 + 0xa4) + uVar5 * -2;
  if ((int)uVar4 < 1) {
    uVar4 = 1;
  }
  uVar6 = (uint)*(ushort *)(pbVar2 + iVar1 + 0xa6) + uVar5 * -2;
  if ((int)uVar6 < 1) {
    uVar6 = 1;
  }
  uVar5 = (uint)*(ushort *)(pbVar2 + iVar1 + 0xa8) + uVar5 * -2;
  if ((int)uVar5 < 1) {
    uVar5 = 1;
  }
  if (bVar3 == 1) {
    if ((uVar4 & uVar4 - 1) != 0) {
      return 1;
    }
    if ((uVar6 & uVar6 - 1) != 0) {
      return 1;
    }
    uVar6 = uVar5 & uVar5 - 1;
  }
  else if ((bVar3 == 0) || (bVar3 == 3)) {
    if ((uVar4 & uVar4 - 1) != 0) {
      return 1;
    }
    uVar6 = uVar6 & uVar6 - 1;
  }
  else {
    if (bVar3 != 4) {
      return 1;
    }
    uVar6 = uVar4 & uVar4 - 1;
  }
  if (uVar6 != 0) {
    return 1;
  }
  return 0;
}

/* FUN_0002bd2c @ 0x2bd2c (2471 bytes) */
int FUN_0002bd2c(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  float fVar2;
  byte bVar3;
  byte bVar4;
  short sVar5;
  undefined2 uVar6;
  int iVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined *puVar12;
  char cVar13;
  char cVar14;
  ushort uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  byte bVar19;
  short sVar20;
  uint uVar21;
  int iVar22;
  ushort uVar23;
  uint uVar24;
  float fVar25;
  float fVar26;
  char local_22;
  
  param_2[0x2e] = (int)param_2;
  iVar7 = param_2[0xc];
  *(bool *)((int)param_2 + 0x3d) = *(short *)(iVar7 + 0x5c) != 0;
  uVar24 = (uint)((double)*(float *)(iVar7 + 0x30) + DOUBLE_001cf368);
  uVar17 = (uint)((double)*(float *)(iVar7 + 0x34) + DOUBLE_001cf368);
  uVar21 = (uint)*(byte *)(iVar7 + 0x5e);
  uVar16 = uVar24 + uVar21;
  if ((int)uVar16 < 0) {
    uVar16 = 0;
  }
  if ((int)uVar21 < (int)uVar16) {
    uVar21 = uVar16;
  }
  uVar18 = (uint)*(short *)(iVar7 + 0x3c);
  uVar16 = uVar17 + uVar18;
  if (((int)uVar16 < (int)uVar21) && (uVar21 = uVar16, (int)uVar16 <= (int)uVar18)) {
    uVar21 = uVar18;
  }
  if ((int)(uint)*(byte *)(iVar7 + 0x5f) < (int)uVar21) {
    uVar21 = (uint)*(byte *)(iVar7 + 0x5f);
  }
  uVar16 = 0;
  if (-1 < (int)uVar24) {
    uVar16 = uVar24;
  }
  if ((int)uVar17 <= (int)uVar16) {
    uVar16 = uVar17;
  }
  uVar18 = (int)*(short *)(iVar7 + 0x3e) - uVar18;
  if ((int)uVar18 < (int)uVar16) {
    uVar16 = uVar18;
  }
  uVar17 = (uint)*(byte *)(iVar7 + 100);
  if ((int)uVar16 <= (int)(uint)*(byte *)(iVar7 + 100)) {
    uVar17 = uVar16;
  }
  if ((int)uVar17 < 0) {
    uVar17 = 0;
  }
  uVar24 = (uint)*(byte *)(iVar7 + 0x65);
  if ((int)uVar16 <= (int)(uint)*(byte *)(iVar7 + 0x65)) {
    uVar24 = uVar16;
  }
  if ((int)uVar24 < 0) {
    uVar24 = 0;
  }
  cVar13 = (char)uVar24;
  if ((int)(uint)*(byte *)(iVar7 + 0x66) < (int)uVar16) {
    uVar16 = (uint)*(byte *)(iVar7 + 0x66);
  }
  if ((int)uVar16 < 0) {
    uVar16 = 0;
  }
  bVar19 = *(byte *)((int)param_2 + 0x73);
  iVar22 = param_2[0x1b];
  sVar20 = *(short *)((int)param_2 + 0x76);
  iVar9 = param_2[0x1e];
  sVar5 = *(short *)((int)param_2 + 0x7a);
  iVar10 = param_2[0x1d];
  iVar11 = param_2[0x1f];
  *(undefined1 *)((int)param_2 + 0x6e) = *(undefined1 *)(iVar7 + 0x6a);
  *(undefined2 *)(param_2 + 0x1d) = *(undefined2 *)(iVar7 + 2);
  *(char *)((int)param_2 + 0x73) = (char)param_2[0xe];
  *(ushort *)((int)param_2 + 0x7a) = (ushort)*(byte *)(iVar7 + 0x66) - ((ushort)uVar16 & 0xff);
  *(undefined2 *)(param_2 + 0x1d) = *(undefined2 *)(iVar7 + 2);
  *(undefined2 *)(param_2 + 0x1f) = *(undefined2 *)((int)param_2 + 0x3e);
  bVar3 = *(byte *)param_2[0xc];
  *(byte *)(param_2 + 0x1b) = bVar3 & 0xf;
  cVar8 = (char)uVar17;
  switch(bVar3 & 0xf) {
  case 0:
    uVar17 = 1 << (*(char *)(iVar7 + 100) - cVar8 & 0x1fU);
    *(short *)((int)param_2 + 0x76) = (short)uVar17;
    uVar16 = 1 << (*(char *)(iVar7 + 0x65) - cVar13 & 0x1fU);
    *(short *)(param_2 + 0x1e) = (short)uVar16;
    param_2[0x20] = (int)(float)(uVar17 & 0xffff);
    param_2[0x21] = (int)(float)(uVar16 & 0xffff);
    *(undefined1 *)((int)param_2 + 0x6d) = 2;
    break;
  case 1:
    uVar17 = 1 << (*(char *)(iVar7 + 100) - cVar8 & 0x1fU);
    *(short *)((int)param_2 + 0x76) = (short)uVar17;
    uVar16 = 1 << (*(char *)(iVar7 + 0x65) - cVar13 & 0x1fU);
    *(short *)(param_2 + 0x1e) = (short)uVar16;
    param_2[0x20] = (int)(float)(uVar17 & 0xffff);
    param_2[0x21] = (int)(float)(uVar16 & 0xffff);
    *(undefined1 *)((int)param_2 + 0x6d) = 3;
    break;
  case 2:
    iVar1 = iVar7 + 0xa0 + uVar21 * 0x18;
    uVar23 = *(short *)(iVar1 + 4) + (ushort)*(byte *)(iVar1 + 10) * -2;
    *(ushort *)((int)param_2 + 0x76) = uVar23;
    uVar15 = *(short *)(iVar1 + 6) + (ushort)*(byte *)(iVar1 + 10) * -2;
    *(ushort *)(param_2 + 0x1e) = uVar15;
    param_2[0x20] = (int)(float)uVar23;
    param_2[0x21] = (int)(float)uVar15;
    *(undefined1 *)((int)param_2 + 0x6d) = 2;
    break;
  case 3:
    cVar14 = ((int (*)())FUN_0002bc75)();
    if (cVar14 == '\0') {
      *(short *)((int)param_2 + 0x76) = (short)(1 << (*(char *)(iVar7 + 100) - cVar8 & 0x1fU));
      *(short *)(param_2 + 0x1e) = (short)(1 << (*(char *)(iVar7 + 0x65) - cVar13 & 0x1fU));
    }
    else {
      iVar1 = iVar7 + 0xa0 + uVar21 * 0x18;
      *(ushort *)((int)param_2 + 0x76) = *(short *)(iVar1 + 4) + (ushort)*(byte *)(iVar1 + 10) * -2;
      *(ushort *)(param_2 + 0x1e) = *(short *)(iVar1 + 6) + (ushort)*(byte *)(iVar1 + 10) * -2;
    }
    param_2[0x20] = (int)(float)*(ushort *)((int)param_2 + 0x76);
    param_2[0x21] = (int)(float)*(ushort *)(param_2 + 0x1e);
    *(undefined1 *)((int)param_2 + 0x6d) = 2;
    break;
  case 4:
    cVar13 = ((int (*)())FUN_0002bc75)();
    if (cVar13 == '\0') {
      *(short *)((int)param_2 + 0x76) = (short)(1 << (*(char *)(iVar7 + 100) - cVar8 & 0x1fU));
    }
    else {
      iVar1 = iVar7 + 0xa0 + uVar21 * 0x18;
      *(ushort *)((int)param_2 + 0x76) = *(short *)(iVar1 + 4) + (ushort)*(byte *)(iVar1 + 10) * -2;
    }
    *(undefined2 *)(param_2 + 0x1e) = 1;
    param_2[0x20] = (int)(float)*(ushort *)((int)param_2 + 0x76);
    param_2[0x21] = 0x3f800000;
    *(undefined1 *)((int)param_2 + 0x6d) = 1;
  }
  bVar3 = *(byte *)((int)param_2 + 0x73);
  if (((((bVar19 == bVar3) && ((char)iVar22 == (char)param_2[0x1b])) &&
       (sVar20 == *(short *)((int)param_2 + 0x76))) &&
      (((short)iVar9 == (short)param_2[0x1e] && (sVar5 == *(short *)((int)param_2 + 0x7a))))) &&
     (((short)iVar10 == (short)param_2[0x1d] && ((short)iVar11 == (short)param_2[0x1f])))) {
LAB_0002c0a5:
    uVar16 = (uint)(*(byte *)((int)param_2 + 0xc9) & 3);
    iVar22 = *param_2;
    if (iVar22 == 0) goto LAB_0002c4a0;
LAB_0002c0be:
    param_2[0x10] = uVar16 << 0x1e | *(uint *)(uVar21 * 0x20 + 0x48 + iVar22);
  }
  else {
    param_2[0x18] = 0;
    *(ushort *)(param_2 + 0x16) =
         *(ushort *)(param_2 + 0x16) & 0xf800 | *(ushort *)((int)param_2 + 0x76) - 1 & 0x7ff;
    param_2[0x16] = param_2[0x16] & 0xffc007ffU | (*(ushort *)(param_2 + 0x1e) - 1 & 0x7ff) << 0xb;
    *(ushort *)((int)param_2 + 0x5a) =
         *(ushort *)((int)param_2 + 0x5a) & 0xfc3f | (*(byte *)((int)param_2 + 0x7a) & 0xf) << 6;
    *(byte *)((int)param_2 + 0x5b) =
         *(byte *)((int)param_2 + 0x5b) & 0x43 | ((short)param_2[0x1f] != 0) << 7;
    *(ushort *)(param_2 + 0x18) =
         *(ushort *)(param_2 + 0x18) & 0xc000 | (short)param_2[0x1f] - 1U & 0x3fff;
    bVar19 = *(byte *)((int)param_2 + 0x61) & 0x7f |
             (char)((int)(*(ushort *)((int)param_2 + 0x76) - 1) >> 0xb) << 7;
    *(byte *)((int)param_2 + 0x61) = bVar19;
    *(byte *)((int)param_2 + 0x62) =
         *(byte *)((int)param_2 + 0x62) & 0xfe |
         (byte)((int)(*(ushort *)(param_2 + 0x1e) - 1) >> 0xb) & 1;
    *(byte *)(param_2 + 0x17) = *(byte *)(param_2 + 0x17) & 0x1f;
    bVar4 = *(byte *)((int)param_2 + 0x5d);
    *(byte *)((int)param_2 + 0x5d) = bVar4 & 0xfe;
    *(undefined1 *)((int)param_2 + 0x71) = 0;
    *(byte *)((int)param_2 + 0x56) = *(byte *)((int)param_2 + 0x56) & 0xdf;
    *(byte *)((int)param_2 + 0x57) = *(byte *)((int)param_2 + 0x57) & 0xbf;
    puVar12 = PTR_DAT_002131c9;
    *(byte *)(param_2 + 0x17) =
         (byte)(*(ushort *)(PTR_DAT_002131c9 + (uint)bVar3 * 0x24 + 0x1e) >> 4) & 0x1f;
    if (bVar3 == 0x29) {
      *(undefined1 *)(param_2 + 0x17) = 6;
      *(byte *)((int)param_2 + 0x61) = bVar19 | 0x40;
      *(byte *)((int)param_2 + 0x5d) = bVar4 & 0x80;
      param_2[0x17] = param_2[0x17] & 0xfffc7fff;
      bVar19 = *(byte *)((int)param_2 + 0x5e) & 0xe3;
      *(byte *)((int)param_2 + 0x5e) = bVar19;
    }
    else {
      bVar19 = puVar12[(uint)bVar3 * 0x24 + 0x1f];
      *(byte *)((int)param_2 + 0x5d) = bVar4 & 0xf0 | bVar19 & 0xe;
      *(byte *)((int)param_2 + 0x5d) =
           bVar4 & 0x80 | bVar19 & 0xe | puVar12[(uint)bVar3 * 0x24 + 0x1f] & 0x70;
      param_2[0x17] =
           param_2[0x17] & 0xfffc7fffU | (uint)(puVar12[(uint)bVar3 * 0x24 + 0x20] & 7) << 0xf;
      bVar19 = *(byte *)((int)param_2 + 0x5e) & 0xe3 |
               (byte)puVar12[(uint)bVar3 * 0x24 + 0x20] >> 1 & 0x1c;
      *(byte *)((int)param_2 + 0x5e) = bVar19;
    }
    *(byte *)((int)param_2 + 0x5e) = bVar19 & 0x3f | puVar12[(uint)bVar3 * 0x24 + 0x20] & 0x40;
    *(byte *)((int)param_2 + 0x71) = (byte)~puVar12[(uint)bVar3 * 0x24 + 0x20] >> 7;
    if ((char)param_2[0x1b] == '\0') {
      *(byte *)((int)param_2 + 0x5f) = *(byte *)((int)param_2 + 0x5f) & 0xf9 | 4;
LAB_0002c099:
      sVar20 = (short)param_2[0x1d];
    }
    else {
      if (*(char *)((int)param_2 + 0x6d) == '\x03') {
        *(byte *)((int)param_2 + 0x5f) = *(byte *)((int)param_2 + 0x5f) & 0xf9 | 2;
        goto LAB_0002c099;
      }
      *(byte *)((int)param_2 + 0x5f) = *(byte *)((int)param_2 + 0x5f) & 0xf9;
      sVar20 = (short)param_2[0x1d];
    }
    if (sVar20 != 0x1907) goto LAB_0002c0a5;
    *(byte *)((int)param_2 + 0x5d) = *(byte *)((int)param_2 + 0x5d) & 0xf1 | 10;
    uVar16 = (uint)(*(byte *)((int)param_2 + 0xc9) & 3);
    iVar22 = *param_2;
    if (iVar22 != 0) goto LAB_0002c0be;
LAB_0002c4a0:
    if ((*(byte *)(iVar7 + 1) & 4) == 0) {
      param_2[0x10] = uVar16 << 0x1e;
    }
    else {
      param_2[0x10] = uVar16 << 0x1e | uVar21;
    }
  }
  iVar7 = param_2[0xc];
  local_22 = *(char *)((int)param_2 + 0x72);
  if (*(float *)(iVar7 + 0x2c) != (float)param_2[0x24]) {
    param_2[0x24] = (int)*(float *)(iVar7 + 0x2c);
    fVar2 = *(float *)(iVar7 + 0x2c);
    if (fVar2 <= 0.0) {
      fVar2 = 0.0;
    }
    if ((uint)(*(byte *)((int)param_2 + 0x52) >> 5) !=
        *(uint *)(&DAT_001c6060 +
                 ((int)(fVar2 - (float)((uint)DAT_001c60f0 & -(uint)(DAT_001c60f0 <= fVar2))) |
                 -(uint)(DAT_001c6100 <= fVar2)) * 4)) {
      *(byte *)((int)param_2 + 0x52) =
           *(byte *)((int)param_2 + 0x52) & 0x1f |
           (char)*(uint *)(&DAT_001c6060 +
                          ((int)(fVar2 - (float)((uint)DAT_001c60f0 & -(uint)(DAT_001c60f0 <= fVar2)
                                                )) | -(uint)(DAT_001c6100 <= fVar2)) * 4) << 5;
      *(undefined2 *)(param_2 + 0x28) = 0xffff;
      *(undefined2 *)((int)param_2 + 0xa2) = 0xffff;
    }
  }
  if ((short)param_2[0x28] == *(short *)(iVar7 + 0x16)) {
    sVar20 = *(short *)(iVar7 + 0x18);
    if (*(short *)((int)param_2 + 0xa2) == sVar20) {
      cVar13 = *(char *)((int)param_2 + 0x71);
      if (cVar13 == (char)param_2[0x1c]) goto LAB_0002c1e1;
      goto LAB_0002c17e;
    }
    if (*(char *)((int)param_2 + 0x71) != (char)param_2[0x1c]) goto LAB_0002c17e;
LAB_0002c1b1:
    *(short *)((int)param_2 + 0xa2) = sVar20;
    ((int (*)())FUN_0002b07f)();
    cVar13 = *(char *)((int)param_2 + 0x71);
  }
  else {
LAB_0002c17e:
    *(short *)(param_2 + 0x28) = *(short *)(iVar7 + 0x16);
    ((int (*)())FUN_0002af16)();
    *(bool *)((int)param_2 + 0x3d) = *(short *)(param_2[0xc] + 0x5c) != 0;
    sVar20 = *(short *)(iVar7 + 0x18);
    if ((sVar20 != *(short *)((int)param_2 + 0xa2)) ||
       (cVar13 = *(char *)((int)param_2 + 0x71), cVar13 != (char)param_2[0x1c])) goto LAB_0002c1b1;
  }
  if (local_22 != *(char *)((int)param_2 + 0x72)) {
    *(undefined2 *)((int)param_2 + 0x9a) = 0xffff;
    *(undefined2 *)(param_2 + 0x27) = 0xffff;
    *(undefined2 *)((int)param_2 + 0x9e) = 0xffff;
    local_22 = *(char *)((int)param_2 + 0x72);
  }
LAB_0002c1e1:
  *(char *)(param_2 + 0x1c) = cVar13;
  uVar15 = *(ushort *)(iVar7 + 0x10);
  if (*(ushort *)((int)param_2 + 0x9a) != uVar15) {
    *(ushort *)((int)param_2 + 0x9a) = uVar15;
    uVar21 = (uint)uVar15;
    if (local_22 == '\0') {
      *(byte *)(param_2 + 0x14) =
           *(byte *)(param_2 + 0x14) & 0xf8 |
           ((byte)(uVar21 * 0x29 >> 0x10) & 1 | (byte)(uVar21 * 0x97 >> 9) & 2 |
           (byte)(uVar21 * 0x113 >> 7) & 4) ^ 2;
    }
    else {
      *(byte *)(param_2 + 0x14) =
           *(byte *)(param_2 + 0x14) & 0xf8 |
           ((byte)(uVar21 * 0x29 >> 0x10) & 1 | (byte)(uVar21 * 0x73 >> 5) & 2 |
           (byte)(uVar21 * 7 >> 3) & 4) ^ 2;
    }
  }
  uVar15 = *(ushort *)(iVar7 + 0x12);
  if (*(ushort *)(param_2 + 0x27) != uVar15) {
    *(ushort *)(param_2 + 0x27) = uVar15;
    uVar21 = (uint)uVar15;
    if (*(char *)((int)param_2 + 0x6d) == '\x01') {
      *(byte *)(param_2 + 0x14) = *(byte *)(param_2 + 0x14) & 199;
    }
    else if (local_22 == '\0') {
      *(byte *)(param_2 + 0x14) =
           *(byte *)(param_2 + 0x14) & 199 |
           (((byte)(uVar21 * 0x29 >> 0x10) & 1 | (byte)(uVar21 * 0x97 >> 9) & 2 |
            (byte)(uVar21 * 0x113 >> 7) & 4) ^ 2) << 3;
    }
    else {
      *(byte *)(param_2 + 0x14) =
           *(byte *)(param_2 + 0x14) & 199 |
           (((byte)(uVar21 * 0x29 >> 0x10) & 1 | (byte)(uVar21 * 0x73 >> 5) & 2 |
            (byte)(uVar21 * 7 >> 3) & 4) ^ 2) << 3;
    }
  }
  uVar15 = *(ushort *)(iVar7 + 0x14);
  if (*(ushort *)((int)param_2 + 0x9e) != uVar15) {
    *(ushort *)((int)param_2 + 0x9e) = uVar15;
    uVar21 = (uint)uVar15;
    if (*(char *)((int)param_2 + 0x6d) == '\x03') {
      if (local_22 == '\0') {
        *(ushort *)(param_2 + 0x14) =
             *(ushort *)(param_2 + 0x14) & 0xfe3f |
             (ushort)(((uVar21 * 0x29 >> 0x10 & 1 | uVar21 * 0x97 >> 9 & 2 | uVar21 * 0x113 >> 7 & 4
                       ) ^ 2) << 6);
      }
      else {
        *(ushort *)(param_2 + 0x14) =
             *(ushort *)(param_2 + 0x14) & 0xfe3f |
             (ushort)(((uVar21 * 0x29 >> 0x10 & 1 | uVar21 * 0x73 >> 5 & 2 | uVar21 * 7 >> 3 & 4) ^
                      2) << 6);
      }
    }
    else {
      *(ushort *)(param_2 + 0x14) = *(ushort *)(param_2 + 0x14) & 0xfe3f;
    }
  }
  iVar22 = param_2[0xc];
  sVar20 = *(short *)(iVar22 + 2);
  if (sVar20 == 0x1902) {
    if (*(short *)(iVar7 + 0x48) == -0x7fb7) {
      *(undefined1 *)((int)param_2 + 0x6b) = 5;
    }
    else {
      *(bool *)((int)param_2 + 0x6b) = *(short *)(iVar7 + 0x48) != 0x1906;
    }
    *(undefined2 *)(param_2 + 0x25) = *(undefined2 *)(iVar7 + 0x48);
    *(undefined2 *)((int)param_2 + 0x96) = *(undefined2 *)(iVar7 + 0x42);
    uVar6 = *(undefined2 *)(iVar7 + 0x40);
    *(undefined2 *)(param_2 + 0x26) = uVar6;
    param_2[0x23] = *(int *)(iVar7 + 0x44);
    *(bool *)((int)param_2 + 0x6a) = *(short *)(iVar7 + 0x42) == -0x77b2;
    *(char *)((int)param_2 + 0x69) = (char)uVar6;
    *(bool *)(param_2 + 0x1a) = *(float *)(iVar7 + 0x44) != 0.0;
    iVar22 = param_2[0xc];
  }
  else if (sVar20 == -0x7fb7) {
    *(undefined1 *)((int)param_2 + 0x6b) = 5;
  }
  else {
    *(char *)((int)param_2 + 0x6b) = (char)sVar20 + -6;
  }
  *(undefined1 *)(param_2 + 0x29) = 0;
  *(char *)((int)param_2 + 0xa5) = *(char *)(iVar22 + 0x5f) - *(char *)(iVar22 + 0x5e);
  param_2[0x12] = (uint)*(byte *)(iVar22 + 0x5f) << 0x10 | (uint)*(byte *)(iVar22 + 0x5e);
  fVar2 = FLOAT_001c5bd4;
  fVar25 = *(float *)(iVar22 + 0x30) + FLOAT_001c5bd4;
  if (fVar25 <= 0.0) {
    fVar25 = 0.0;
  }
  fVar26 = *(float *)(iVar22 + 0x34) + FLOAT_001c5bd4;
  if (fVar26 <= 0.0) {
    fVar26 = 0.0;
  }
  param_2[0x13] =
       ((int)(fVar25 - (float)(-(uint)(DAT_001c60f0 <= fVar25) & (uint)DAT_001c60f0)) |
       -(uint)(DAT_001c6100 <= fVar25)) << 0x10 |
       (int)(fVar26 - (float)((uint)DAT_001c60f0 & -(uint)(DAT_001c60f0 <= fVar26))) +
       (uint)(DAT_001c60f0 <= fVar26) * -0x80000000 | -(uint)(DAT_001c6100 <= fVar26);
  ((int (*)())FUN_0002b0ef)();
  uVar21 = (uint)(*(float *)(iVar22 + 0x34) + fVar2);
  uVar16 = (uint)(fVar2 + *(float *)(iVar22 + 0x30));
  uVar17 = (uint)*(byte *)((int)param_2 + 0xa5);
  if ((int)uVar17 < (int)uVar21) {
    uVar21 = uVar17;
  }
  if ((int)uVar17 < (int)uVar16) {
    uVar16 = uVar17;
  }
  uVar24 = uVar17 + 1;
  if ((uint)*(byte *)((int)param_2 + 0x6e) < uVar17 + 1) {
    uVar24 = (uint)*(byte *)((int)param_2 + 0x6e);
  }
  uVar21 = (uVar21 - uVar16) + 1;
  if ((int)uVar24 <= (int)uVar21) {
    uVar21 = uVar24;
  }
  cVar13 = '\x01';
  if (0 < (int)uVar21) {
    cVar13 = (char)uVar21;
  }
  *(byte *)((int)param_2 + 0x5b) = *(byte *)((int)param_2 + 0x5b) & 0xc3 | (cVar13 - 1U & 0xf) << 2;
  *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) & 0x7f;
  return;
}

/* FUN_0002c8e0 @ 0x2c8e0 (733 bytes) */
int FUN_0002c8e0(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  byte local_25;
  
  if (*(int *)(param_1 + 0x2a90) != 0) {
    iVar4 = *(int *)(param_1 + 0x18c + param_2 * 4);
    if ((((*(short *)(*(int *)(iVar4 + 0x30) + 0x18) != 0x2600) &&
         (sVar3 = *(short *)(*(int *)(iVar4 + 0x30) + 0x16), sVar3 != 0x2600)) && (sVar3 != 0x2702))
       && (sVar3 != 0x2700)) {
      *(byte *)(iVar4 + 0x52) =
           *(byte *)(iVar4 + 0x52) & 0x1f |
           (char)*(undefined4 *)(&DAT_001c6060 + *(int *)(param_1 + 0x2a90) * 4) << 5;
      cVar1 = *(char *)(iVar4 + 0x72);
      ((int (*)())FUN_0002af16)();
      ((int (*)())FUN_0002b07f)();
      cVar2 = *(char *)(iVar4 + 0x72);
      if (cVar1 != cVar2) {
        uVar5 = (uint)*(ushort *)(iVar4 + 0x9a);
        if (cVar2 == '\0') {
          local_25 = *(byte *)(iVar4 + 0x50) & 0xf8 |
                     ((byte)(uVar5 * 0x29 >> 0x10) & 1 | (byte)(uVar5 * 0x97 >> 9) & 2 |
                     (byte)(uVar5 * 0x113 >> 7) & 4) ^ 2;
          *(byte *)(iVar4 + 0x50) = local_25;
        }
        else {
          local_25 = *(byte *)(iVar4 + 0x50) & 0xf8 |
                     ((byte)(uVar5 * 0x29 >> 0x10) & 1 | (byte)(uVar5 * 0x73 >> 5) & 2 |
                     (byte)(uVar5 * 7 >> 3) & 4) ^ 2;
          *(byte *)(iVar4 + 0x50) = local_25;
        }
        uVar5 = (uint)*(ushort *)(iVar4 + 0x9c);
        if (*(char *)(iVar4 + 0x6d) == '\x01') {
          *(byte *)(iVar4 + 0x50) = local_25 & 199;
        }
        else if (cVar2 == '\0') {
          *(byte *)(iVar4 + 0x50) =
               local_25 & 199 |
               (((byte)(uVar5 * 0x29 >> 0x10) & 1 | (byte)(uVar5 * 0x97 >> 9) & 2 |
                (byte)(uVar5 * 0x113 >> 7) & 4) ^ 2) << 3;
        }
        else {
          *(byte *)(iVar4 + 0x50) =
               local_25 & 199 |
               (((byte)(uVar5 * 0x29 >> 0x10) & 1 | (byte)(uVar5 * 0x73 >> 5) & 2 |
                (byte)(uVar5 * 7 >> 3) & 4) ^ 2) << 3;
        }
        uVar5 = (uint)*(ushort *)(iVar4 + 0x9e);
        if (*(char *)(iVar4 + 0x6d) == '\x03') {
          if (cVar2 == '\0') {
            *(ushort *)(iVar4 + 0x50) =
                 *(ushort *)(iVar4 + 0x50) & 0xfe3f |
                 (ushort)(((uVar5 * 0x29 >> 0x10 & 1 | uVar5 * 0x97 >> 9 & 2 |
                           uVar5 * 0x113 >> 7 & 4) ^ 2) << 6);
          }
          else {
            *(ushort *)(iVar4 + 0x50) =
                 *(ushort *)(iVar4 + 0x50) & 0xfe3f |
                 (ushort)(((uVar5 * 0x29 >> 0x10 & 1 | uVar5 * 0x73 >> 5 & 2 | uVar5 * 7 >> 3 & 4) ^
                          2) << 6);
          }
        }
        else {
          *(ushort *)(iVar4 + 0x50) = *(ushort *)(iVar4 + 0x50) & 0xfe3f;
        }
      }
    }
  }
  return;
}

/* FUN_0002cbbd @ 0x2cbbd (1450 bytes) */
int FUN_0002cbbd(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  float fVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  float fVar5;
  char cVar6;
  uint uVar7;
  short sVar8;
  float fVar9;
  float fVar10;
  char local_29;
  
  fVar5 = DAT_001c6120;
  fVar1 = DAT_001c6110;
  iVar4 = *(int *)(param_2 + 0x30);
  fVar9 = *(float *)(iVar4 + 0x30) + FLOAT_001c5bd4;
  if (fVar9 <= 0.0) {
    fVar9 = 0.0;
  }
  fVar10 = FLOAT_001c5bd4 + *(float *)(iVar4 + 0x34);
  if (fVar10 <= 0.0) {
    fVar10 = 0.0;
  }
  if ((((uint)*(byte *)(iVar4 + 0x5f) << 0x10 | (uint)*(byte *)(iVar4 + 0x5e)) !=
       *(uint *)(param_2 + 0x48)) ||
     ((((int)(fVar9 - (float)(-(uint)(DAT_001c6110 <= fVar9) & (uint)DAT_001c6110)) |
       -(uint)(DAT_001c6120 <= fVar9)) << 0x10 |
      (int)(fVar10 - (float)(-(uint)(DAT_001c6110 <= fVar10) & (uint)DAT_001c6110)) +
      (uint)(DAT_001c6110 <= fVar10) * -0x80000000 | -(uint)(DAT_001c6120 <= fVar10)) !=
      *(uint *)(param_2 + 0x4c))) {
    ((int (*)())FUN_0002bd2c)();
    return;
  }
  local_29 = *(char *)(param_2 + 0x72);
  if (*(float *)(iVar4 + 0x2c) != *(float *)(param_2 + 0x90)) {
    *(float *)(param_2 + 0x90) = *(float *)(iVar4 + 0x2c);
    fVar9 = *(float *)(iVar4 + 0x2c);
    if (fVar9 <= 0.0) {
      fVar9 = 0.0;
    }
    if ((uint)(*(byte *)(param_2 + 0x52) >> 5) !=
        *(uint *)(&DAT_001c6060 +
                 ((int)(fVar9 - (float)((uint)fVar1 & -(uint)(fVar1 <= fVar9))) |
                 -(uint)(fVar5 <= fVar9)) * 4)) {
      *(byte *)(param_2 + 0x52) =
           *(byte *)(param_2 + 0x52) & 0x1f |
           (char)*(uint *)(&DAT_001c6060 +
                          ((int)(fVar9 - (float)((uint)fVar1 & -(uint)(fVar1 <= fVar9))) |
                          -(uint)(fVar5 <= fVar9)) * 4) << 5;
      *(undefined2 *)(param_2 + 0xa0) = 0xffff;
      *(undefined2 *)(param_2 + 0xa2) = 0xffff;
    }
  }
  if (*(short *)(param_2 + 0xa0) == *(short *)(iVar4 + 0x16)) {
    sVar8 = *(short *)(iVar4 + 0x18);
    if (*(short *)(param_2 + 0xa2) == sVar8) {
      cVar6 = *(char *)(param_2 + 0x71);
      if (cVar6 == *(char *)(param_2 + 0x70)) goto LAB_0002cdb9;
      goto LAB_0002cd59;
    }
    if (*(char *)(param_2 + 0x70) != *(char *)(param_2 + 0x71)) goto LAB_0002cd59;
LAB_0002cd89:
    *(short *)(param_2 + 0xa2) = sVar8;
    ((int (*)())FUN_0002b07f)();
    cVar6 = *(char *)(param_2 + 0x71);
  }
  else {
LAB_0002cd59:
    *(short *)(param_2 + 0xa0) = *(short *)(iVar4 + 0x16);
    ((int (*)())FUN_0002af16)();
    *(bool *)(param_2 + 0x3d) = *(short *)(*(int *)(param_2 + 0x30) + 0x5c) != 0;
    sVar8 = *(short *)(iVar4 + 0x18);
    if ((sVar8 != *(short *)(param_2 + 0xa2)) ||
       (cVar6 = *(char *)(param_2 + 0x71), cVar6 != *(char *)(param_2 + 0x70))) goto LAB_0002cd89;
  }
  if (local_29 != *(char *)(param_2 + 0x72)) {
    *(undefined2 *)(param_2 + 0x9a) = 0xffff;
    *(undefined2 *)(param_2 + 0x9c) = 0xffff;
    *(undefined2 *)(param_2 + 0x9e) = 0xffff;
    local_29 = *(char *)(param_2 + 0x72);
  }
LAB_0002cdb9:
  *(char *)(param_2 + 0x70) = cVar6;
  uVar2 = *(ushort *)(iVar4 + 0x10);
  if (*(ushort *)(param_2 + 0x9a) != uVar2) {
    *(ushort *)(param_2 + 0x9a) = uVar2;
    uVar7 = (uint)uVar2;
    if (local_29 == '\0') {
      *(byte *)(param_2 + 0x50) =
           *(byte *)(param_2 + 0x50) & 0xf8 |
           ((byte)(uVar7 * 0x29 >> 0x10) & 1 | (byte)(uVar7 * 0x97 >> 9) & 2 |
           (byte)(uVar7 * 0x113 >> 7) & 4) ^ 2;
    }
    else {
      *(byte *)(param_2 + 0x50) =
           *(byte *)(param_2 + 0x50) & 0xf8 |
           ((byte)(uVar7 * 0x29 >> 0x10) & 1 | (byte)(uVar7 * 0x73 >> 5) & 2 |
           (byte)(uVar7 * 7 >> 3) & 4) ^ 2;
    }
  }
  uVar2 = *(ushort *)(iVar4 + 0x12);
  if (*(ushort *)(param_2 + 0x9c) != uVar2) {
    *(ushort *)(param_2 + 0x9c) = uVar2;
    uVar7 = (uint)uVar2;
    if (*(char *)(param_2 + 0x6d) == '\x01') {
      *(byte *)(param_2 + 0x50) = *(byte *)(param_2 + 0x50) & 199;
    }
    else if (local_29 == '\0') {
      *(byte *)(param_2 + 0x50) =
           *(byte *)(param_2 + 0x50) & 199 |
           (((byte)(uVar7 * 0x29 >> 0x10) & 1 | (byte)(uVar7 * 0x97 >> 9) & 2 |
            (byte)(uVar7 * 0x113 >> 7) & 4) ^ 2) << 3;
    }
    else {
      *(byte *)(param_2 + 0x50) =
           *(byte *)(param_2 + 0x50) & 199 |
           (((byte)(uVar7 * 0x29 >> 0x10) & 1 | (byte)(uVar7 * 0x73 >> 5) & 2 |
            (byte)(uVar7 * 7 >> 3) & 4) ^ 2) << 3;
    }
  }
  uVar2 = *(ushort *)(iVar4 + 0x14);
  if (*(ushort *)(param_2 + 0x9e) != uVar2) {
    *(ushort *)(param_2 + 0x9e) = uVar2;
    uVar7 = (uint)uVar2;
    if (*(char *)(param_2 + 0x6d) == '\x03') {
      if (local_29 == '\0') {
        *(ushort *)(param_2 + 0x50) =
             *(ushort *)(param_2 + 0x50) & 0xfe3f |
             (ushort)(((uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x97 >> 9 & 2 | uVar7 * 0x113 >> 7 & 4) ^
                      2) << 6);
      }
      else {
        *(ushort *)(param_2 + 0x50) =
             *(ushort *)(param_2 + 0x50) & 0xfe3f |
             (ushort)(((uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x73 >> 5 & 2 | uVar7 * 7 >> 3 & 4) ^ 2)
                     << 6);
      }
    }
    else {
      *(ushort *)(param_2 + 0x50) = *(ushort *)(param_2 + 0x50) & 0xfe3f;
    }
  }
  sVar8 = *(short *)(*(int *)(param_2 + 0x30) + 2);
  if (sVar8 == 0x1902) {
    if (*(short *)(iVar4 + 0x48) == -0x7fb7) {
      *(undefined1 *)(param_2 + 0x6b) = 5;
    }
    else {
      *(bool *)(param_2 + 0x6b) = *(short *)(iVar4 + 0x48) != 0x1906;
    }
    *(undefined2 *)(param_2 + 0x94) = *(undefined2 *)(iVar4 + 0x48);
    *(undefined2 *)(param_2 + 0x96) = *(undefined2 *)(iVar4 + 0x42);
    uVar3 = *(undefined2 *)(iVar4 + 0x40);
    *(undefined2 *)(param_2 + 0x98) = uVar3;
    *(undefined4 *)(param_2 + 0x8c) = *(undefined4 *)(iVar4 + 0x44);
    *(bool *)(param_2 + 0x6a) = *(short *)(iVar4 + 0x42) == -0x77b2;
    *(char *)(param_2 + 0x69) = (char)uVar3;
    *(bool *)(param_2 + 0x68) = *(float *)(iVar4 + 0x44) != 0.0;
  }
  else if (sVar8 == -0x7fb7) {
    *(undefined1 *)(param_2 + 0x6b) = 5;
  }
  else {
    *(char *)(param_2 + 0x6b) = (char)sVar8 + -6;
  }
  fVar1 = *(float *)(iVar4 + 0x1c);
  if ((((fVar1 != *(float *)(param_2 + 0xa8)) || (NAN(fVar1) || NAN(*(float *)(param_2 + 0xa8)))) ||
      (*(float *)(param_2 + 0xac) != *(float *)(iVar4 + 0x20))) ||
     (((NAN(*(float *)(param_2 + 0xac)) || NAN(*(float *)(iVar4 + 0x20)) ||
       (*(float *)(param_2 + 0xb0) != *(float *)(iVar4 + 0x24))) ||
      ((NAN(*(float *)(param_2 + 0xb0)) || NAN(*(float *)(iVar4 + 0x24)) ||
       (*(float *)(param_2 + 0xb4) != *(float *)(iVar4 + 0x28))))))) {
    *(float *)(param_2 + 0xa8) = fVar1;
    *(undefined4 *)(param_2 + 0xac) = *(undefined4 *)(iVar4 + 0x20);
    *(undefined4 *)(param_2 + 0xb0) = *(undefined4 *)(iVar4 + 0x24);
    *(undefined4 *)(param_2 + 0xb4) = *(undefined4 *)(iVar4 + 0x28);
    ((int (*)())FUN_0002b0ef)();
  }
  *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) & 0x7f;
  return;
}

/* FUN_0002d168 @ 0x2d168 (37 bytes) */
int FUN_0002d168(param_1)
  uint param_1;
{
  switch(param_1 & 0xf) {
  case 3:
    return 7;
  case 4:
  case 10:
    return 8;
  default:
    return 0;
  case 6:
    return 0x27;
  case 7:
    return 0x2b;
  case 8:
    return 0x2c;
  case 9:
    return 0x2a;
  case 0xb:
    return 0x18;
  case 0xc:
    return 0x1e;
  case 0xd:
    return 0x12;
  }
}

/* FUN_0002d1fb @ 0x2d1fb (651 bytes) */
int FUN_0002d1fb(param_1, param_2, param_3)
  uint param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  
  if (param_1 == 0x1909) {
    if (param_3 == 1) {
LAB_0002d31d:
      return param_2 == 0x1401;
    }
    if (param_3 == 0x13) {
LAB_0002d2f1:
      return param_2 == 0x1406;
    }
    if (param_3 == 0x1f) {
LAB_0002d293:
      if (param_2 == 0x140b) {
        return true;
      }
      return false;
    }
    if (param_3 != 0x19) {
      return false;
    }
  }
  else if (param_1 < 0x190a) {
    if (param_1 == 0x1907) {
      if (param_3 == 5) {
        if (param_2 == 0x8363) {
          return true;
        }
        return false;
      }
      if (param_3 == 0x28) {
        if (param_2 != 0x8032) {
          return false;
        }
        return true;
      }
      return false;
    }
    if (param_1 < 0x1908) {
      if (param_1 != 0x1906) {
        return false;
      }
      if (param_3 == 2) goto LAB_0002d31d;
      if (param_3 == 0x14) goto LAB_0002d2f1;
      if (param_3 == 0x20) goto LAB_0002d293;
      if (param_3 != 0x1a) {
        return false;
      }
    }
    else {
      if (param_3 == 0x12) {
LAB_0002d3d3:
        return param_2 == 0x1406;
      }
      if (param_3 == 0x1e) {
        return param_2 == 0x140b;
      }
      if (param_3 == 10) {
        return param_2 == 0x8035;
      }
      if (param_3 == 9) {
LAB_0002d25d:
        if ((param_2 != 0x8367) && (param_2 != 0x1401)) {
          return false;
        }
        return true;
      }
      if (param_3 == 0x23) {
        if (param_2 == 0x8368) {
          return true;
        }
        return false;
      }
      if (param_3 != 0x18) {
        return false;
      }
    }
  }
  else {
    if (param_1 == 0x80e1) {
      if (param_3 == 7) {
        bVar1 = param_2 == 0x8366;
      }
      else if (param_3 == 6) {
        bVar1 = param_2 == 0x8365;
      }
      else if (param_3 == 0xb) {
        bVar1 = param_2 == 0x8035;
      }
      else {
        if (param_3 == 8) goto LAB_0002d25d;
        bVar1 = false;
        if (param_3 == 0x24) {
          return param_2 == 0x8368;
        }
        if (param_3 == 0x11) goto LAB_0002d2f1;
        if (param_3 == 0x1d) goto LAB_0002d293;
      }
      if (param_3 != 0x17) {
        return bVar1;
      }
      if (param_2 == 0x1403) {
        return true;
      }
      return bVar1;
    }
    if (param_1 == 0x85b9) {
      if (param_3 == 0x27) {
        if (param_2 == 0x85ba) {
          return true;
        }
        return false;
      }
      if (param_3 == 0x26) {
        if (param_2 == 0x85bb) {
          return true;
        }
        return false;
      }
      return false;
    }
    if (param_1 != 0x190a) {
      return false;
    }
    if (param_3 == 4) goto LAB_0002d31d;
    if (param_3 == 0x16) goto LAB_0002d3d3;
    if (param_3 == 0x22) goto LAB_0002d293;
    if (param_3 != 0x1c) {
      return false;
    }
  }
  if (param_2 == 0x1403) {
    return true;
  }
  return false;
}

/* FUN_0002d486 @ 0x2d486 (642 bytes) */
int FUN_0002d486(param_1, param_2)
  uint param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (param_1 == 0x1909) {
    if (param_2 == 0x1401) {
      uVar1 = 1;
    }
    else {
      if (param_2 == 0x1406) {
        return 0x13;
      }
      uVar1 = 0;
      if (param_2 == 0x140b) {
        return 0x1f;
      }
    }
    if (param_2 != 0x1403) {
      return uVar1;
    }
    return 0x19;
  }
  if (param_1 < 0x190a) {
    if (param_1 == 0x1907) {
      if (param_2 == 0x8363) {
        return 5;
      }
      if (param_2 == 0x8032) {
        return 0x28;
      }
    }
    else {
      if (0x1907 < param_1) {
        if (param_2 == 0x1406) {
          uVar1 = 0x12;
        }
        else {
          if (param_2 == 0x140b) {
            return 0x1e;
          }
          uVar1 = 0;
          if (param_2 == 0x8035) {
            return 10;
          }
        }
        if ((param_2 == 0x8367) || (param_2 == 0x1401)) {
          return 9;
        }
        if (param_2 == 0x8036) {
          return 0x23;
        }
        if (param_2 != 0x1403) {
          return uVar1;
        }
        return 0x18;
      }
      if (param_1 == 0x1906) {
        if (param_2 == 0x1401) {
          uVar1 = 2;
        }
        else {
          if (param_2 == 0x1406) {
            return 0x14;
          }
          uVar1 = 0;
          if (param_2 == 0x140b) {
            return 0x20;
          }
        }
        if (param_2 != 0x1403) {
          return uVar1;
        }
        return 0x1a;
      }
    }
  }
  else {
    if (param_1 == 0x80e1) {
      if (param_2 == 0x8034) {
        uVar1 = 7;
      }
      else {
        if (param_2 == 0x8365) {
          return 6;
        }
        uVar1 = 0;
        if (param_2 == 0x8035) {
          return 0xb;
        }
      }
      if ((param_2 == 0x8367) || (param_2 == 0x1401)) {
        return 8;
      }
      if (param_2 == 0x8036) {
        return 0x24;
      }
      if (param_2 != 0x1406) {
        if (param_2 == 0x140b) {
          return 0x1d;
        }
        if (param_2 != 0x1403) {
          return uVar1;
        }
        return 0x17;
      }
      return 0x11;
    }
    if (param_1 == 0x85b9) {
      if (param_2 == 0x85ba) {
        return 0x27;
      }
      if (param_2 == 0x85bb) {
        return 0x26;
      }
    }
    else if (param_1 == 0x190a) {
      if (param_2 == 0x1401) {
        uVar1 = 4;
      }
      else {
        if (param_2 == 0x1406) {
          return 0x16;
        }
        uVar1 = 0;
        if (param_2 == 0x140b) {
          return 0x22;
        }
      }
      if (param_2 != 0x1403) {
        return uVar1;
      }
      return 0x1c;
    }
  }
  return 0;
}

/* FUN_0002d708 @ 0x2d708 (2046 bytes) */
int FUN_0002d708(param_1, param_2)
  int param_1;
  int param_2;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar5;
  char cVar6;
  char cVar7;
  undefined1 uVar8;
  char cVar9;
  char cVar10;
  int iVar11;
  uint uVar12;
  char cVar13;
  uint local_20 [3];
  undefined4 local_14;
  undefined4 local_10;
  
  puVar5 = *(ushort **)(param_2 + 0x30);
  uVar1 = *puVar5;
  if ((uVar1 & 0x200) != 0) {
    return;
  }
  if ((uVar1 & 0x400) != 0) {
    local_10 = *(undefined4 *)(puVar5 + 4);
    *(undefined1 *)(param_2 + 0x38) = 0;
    local_14 = 3;
    iVar11 = _io_connect_method_scalarI_scalarO
                       (*(undefined4 *)(param_1 + 4),6,&local_10,1,local_20,&local_14);
    if (iVar11 != 0) {
      return;
    }
    uVar1 = puVar5[6];
    if (uVar1 == 0x409) {
      if ((local_20[0] & 0x300) < 0x100) {
        return;
      }
    }
    else if (uVar1 == 0x40a) {
      if ((local_20[0] & 0x300) < 0x200) {
        return;
      }
    }
    else if ((ushort)(uVar1 - 0x40b) < 2) {
      return;
    }
    uVar8 = ((int (*)())FUN_0002d168)(local_20[0]);
    *(undefined1 *)(param_2 + 0x38) = uVar8;
    return;
  }
  uVar2 = puVar5[0x2a];
  uVar3 = puVar5[0x2d];
  uVar4 = puVar5[0x2c];
  uVar12 = *(uint *)(param_1 + 0x154) & 0xf;
  if (uVar4 != 0x1900) {
    if (uVar4 != 0x85b9) {
      if (uVar3 == 0x8362) {
LAB_0002d821:
        cVar6 = '(';
        cVar13 = '(';
        cVar7 = '(';
      }
      else if (uVar3 < 0x8363) {
        if (uVar3 == 0x8034) {
LAB_0002da85:
          cVar6 = '\0';
          cVar13 = '\a';
          cVar7 = '\a';
        }
        else if (uVar3 < 0x8035) {
          if (uVar3 == 0x8032) goto LAB_0002d821;
          if (uVar3 == 0x8033) goto LAB_0002daae;
LAB_0002d78d:
          cVar6 = '\0';
          cVar13 = '\0';
          cVar7 = '\0';
        }
        else if (uVar3 == 0x8035) {
          if (uVar4 == 0x80e1) {
            cVar6 = '\0';
            cVar13 = '\0';
            cVar7 = '\v';
          }
          else {
            cVar6 = '\0';
            cVar13 = '\0';
            cVar7 = '\n';
          }
        }
        else {
          if (uVar3 != 0x8036) goto LAB_0002d78d;
LAB_0002d951:
          if (uVar4 == 0x80e1) {
            cVar6 = '\0';
            cVar13 = '\0';
            cVar7 = '$';
          }
          else {
            cVar6 = '\0';
            cVar13 = '\0';
            cVar7 = '#';
          }
        }
      }
      else if (uVar3 == 0x8365) {
LAB_0002daae:
        cVar6 = '\0';
        cVar13 = '\x06';
        cVar7 = '\x06';
      }
      else if (uVar3 < 0x8365) {
        cVar6 = '\0';
        cVar13 = '\x05';
        cVar7 = '\x05';
      }
      else {
        if (uVar3 != 0x8367) {
          if (0x8366 < uVar3) {
            if (uVar3 == 0x8368) goto LAB_0002d951;
            goto LAB_0002d78d;
          }
          goto LAB_0002da85;
        }
        if (uVar4 == 0x80e1) {
          cVar6 = '\0';
          cVar13 = '\0';
          cVar7 = '\b';
        }
        else {
          cVar6 = '\0';
          cVar13 = '\0';
          cVar7 = '\t';
        }
      }
      if (0x8056 < uVar2) {
        if (uVar2 == 0x84ec) {
          cVar13 = '\0';
          cVar9 = '\f';
          cVar10 = '\x03';
        }
        else if (uVar2 < 0x84ed) {
          if (uVar2 < 0x81a8) {
            if (uVar2 < 0x81a6) {
              if (uVar2 == 0x8059) {
                if (uVar4 == 0x80e1) {
                  cVar13 = '\0';
                  cVar9 = '\0';
                  cVar10 = '$';
                }
                else {
                  cVar13 = '\0';
                  cVar9 = '\0';
                  cVar10 = '#';
                }
              }
              else if (uVar2 < 0x805a) {
                if (uVar2 != 0x8057) {
                  if (uVar2 == 0x8058) goto LAB_0002dbfc;
                  goto LAB_0002d9ec;
                }
                cVar9 = '\0';
                cVar10 = '\a';
              }
              else {
                if (uVar2 < 0x805c) goto LAB_0002dc26;
                if (uVar2 != 0x81a5) goto LAB_0002d9ec;
LAB_0002dd4b:
                cVar9 = '\0';
                cVar10 = '\x10';
                cVar13 = '\0';
              }
            }
            else {
LAB_0002dbb0:
              cVar13 = '\0';
              cVar9 = '\0';
              cVar10 = ')';
            }
          }
          else if (uVar2 == 0x83f3) {
            cVar9 = '\x0e';
            cVar10 = '\x06';
          }
          else if (uVar2 < 0x83f4) {
            if (uVar2 == 0x83f1) {
              cVar9 = '\f';
              cVar10 = '\x06';
            }
            else {
              if (uVar2 < 0x83f2) {
                if (uVar2 == 0x83f0) goto LAB_0002db17;
                goto LAB_0002d9ec;
              }
LAB_0002d918:
              cVar9 = '\r';
              cVar10 = '\x06';
            }
          }
          else if (uVar2 == 0x84ea) {
            cVar13 = '\0';
            cVar9 = '\f';
            cVar10 = '\x01';
          }
          else if (uVar2 < 0x84eb) {
            if (uVar2 != 0x84e9) goto LAB_0002d9ec;
            if (uVar4 == 0x1908) {
LAB_0002de5c:
              if ((uVar3 == 0x8034) || (uVar3 == 0x8366)) goto LAB_0002dc6a;
            }
            else if (uVar4 < 0x1909) {
              if (uVar4 != 0x1906) {
LAB_0002dc6a:
                cVar13 = '\0';
                cVar9 = '\f';
                cVar10 = '\x02';
                goto LAB_0002d990;
              }
            }
            else if (uVar4 != 0x190a) {
              if (uVar4 == 0x80e1) goto LAB_0002de5c;
              goto LAB_0002dc6a;
            }
LAB_0002de72:
            cVar9 = '\0';
            cVar10 = '\x02';
            cVar13 = '\0';
          }
          else {
            cVar9 = '\r';
            cVar10 = '\x04';
          }
        }
        else if (uVar2 == 0x8819) {
          cVar13 = '\0';
          cVar9 = '\0';
          cVar10 = '\x16';
        }
        else if (uVar2 < 0x881a) {
          if (uVar2 < 0x8816) {
            if (uVar2 < 0x8814) {
              if (uVar2 != 0x84ed) {
                if (uVar2 == 0x84ee) goto LAB_0002d918;
                goto LAB_0002d9ec;
              }
LAB_0002db17:
              cVar9 = '\f';
              cVar10 = '\x05';
            }
            else if (uVar4 == 0x80e1) {
              cVar13 = '\0';
              cVar9 = '\0';
              cVar10 = '\x11';
            }
            else {
              cVar13 = '\0';
              cVar9 = '\0';
              cVar10 = '\x12';
            }
          }
          else if (uVar2 == 0x8817) {
            cVar13 = '\0';
            cVar9 = '\0';
            cVar10 = '\x15';
          }
          else if (uVar2 < 0x8818) {
            cVar13 = '\0';
            cVar9 = '\0';
            cVar10 = '\x14';
          }
          else {
            cVar13 = '\0';
            cVar9 = '\0';
            cVar10 = '\x13';
          }
        }
        else if (uVar2 == 0x881d) {
          cVar13 = '\0';
          cVar9 = '\0';
          cVar10 = '!';
        }
        else if (uVar2 < 0x881e) {
          if (uVar2 < 0x881c) {
            cVar13 = '\0';
            cVar9 = '\0';
            cVar10 = '\x1e';
          }
          else {
            cVar13 = '\0';
            cVar9 = '\0';
            cVar10 = ' ';
          }
        }
        else if (uVar2 == 0x881f) {
          cVar13 = '\0';
          cVar9 = '\0';
          cVar10 = '\"';
        }
        else if (uVar2 < 0x881f) {
          cVar13 = '\0';
          cVar9 = '\0';
          cVar10 = '\x1f';
        }
        else {
          if (uVar2 != 0x8837) {
            if (uVar2 == 0x88f0) goto LAB_0002dbb0;
            goto LAB_0002d9ec;
          }
          cVar13 = '\0';
          cVar9 = '\x0f';
          cVar10 = '\x04';
        }
        goto LAB_0002d990;
      }
      if (uVar2 < 0x8055) {
        if (uVar2 < 0x8041) {
          if (uVar2 < 0x803f) {
            if (uVar2 == 0x1908) {
LAB_0002dca9:
              if (uVar4 == 0x1908) {
LAB_0002d980:
                if (uVar12 == 3) goto LAB_0002d989;
              }
              else {
                if (uVar4 < 0x1909) {
                  if (uVar4 == 0x1906) goto LAB_0002d980;
                }
                else if ((uVar4 == 0x190a) || (uVar4 == 0x80e1)) goto LAB_0002d980;
LAB_0002dcc3:
                if (uVar12 == 3) goto LAB_0002dccc;
              }
LAB_0002dbfc:
              cVar9 = '\0';
              cVar10 = '\t';
              cVar13 = cVar7;
            }
            else {
              if (uVar2 < 0x1909) {
                if (uVar2 == 4) goto LAB_0002dca9;
                if (4 < uVar2) {
                  if (uVar2 == 0x1906) goto LAB_0002de72;
                  if (0x1906 < uVar2) goto LAB_0002deb5;
                  if (uVar2 == 0x1902) goto LAB_0002dd4b;
LAB_0002d9ec:
                  cVar9 = '\0';
                  cVar10 = '\0';
                  cVar13 = '\0';
                  goto LAB_0002d990;
                }
                if (uVar2 == 2) goto LAB_0002dd89;
                if (uVar2 < 3) {
                  if (uVar2 == 1) goto LAB_0002d897;
                  goto LAB_0002d9ec;
                }
LAB_0002deb5:
                if (uVar4 == 0x1906) {
                  cVar9 = '\0';
                  cVar10 = '(';
                  cVar13 = '\0';
                  goto LAB_0002d990;
                }
                goto LAB_0002dcc3;
              }
              if (uVar2 < 0x803d) {
                if (0x803a < uVar2) goto LAB_0002de72;
                if (uVar2 == 0x190a) {
LAB_0002dd89:
                  cVar9 = '\0';
                  cVar10 = '\x04';
                  cVar13 = '\0';
                }
                else {
                  if (uVar2 < 0x190a) goto LAB_0002d897;
                  if (uVar2 != 0x2a10) goto LAB_0002d9ec;
                  cVar9 = '\0';
                  cVar10 = '(';
                  cVar13 = cVar6;
                }
              }
              else {
                cVar9 = '\0';
                cVar10 = '\x1a';
                cVar13 = '\0';
              }
            }
          }
          else {
LAB_0002d897:
            cVar9 = '\0';
            cVar10 = '\x01';
            cVar13 = '\0';
          }
        }
        else if (uVar2 < 0x804c) {
          if (uVar2 < 0x8049) {
            if (uVar2 < 0x8047) {
              if (0x8042 < uVar2) goto LAB_0002dd89;
              cVar9 = '\0';
              cVar10 = '\x19';
              cVar13 = '\0';
            }
            else {
              cVar9 = '\0';
              cVar10 = '\x1c';
              cVar13 = '\0';
            }
          }
          else {
            cVar9 = '\0';
            cVar10 = '\x03';
            cVar13 = '\0';
          }
        }
        else if (uVar2 < 0x8051) {
          if (uVar2 < 0x804f) {
            if (0x804d < uVar2) goto LAB_0002d9ec;
            cVar9 = '\0';
            cVar10 = '\x1b';
            cVar13 = '\0';
          }
          else {
LAB_0002dccc:
            cVar9 = '\0';
            cVar10 = '\x05';
          }
        }
        else if (uVar2 == 0x8052) {
          cVar9 = '\0';
          cVar10 = '#';
          cVar13 = cVar7;
        }
        else {
          if (uVar2 < 0x8053) goto LAB_0002dbfc;
LAB_0002dc26:
          cVar9 = '\0';
          cVar10 = '\x18';
          cVar13 = '\0';
        }
      }
      else {
LAB_0002d989:
        cVar9 = '\0';
        cVar10 = '\x06';
      }
LAB_0002d990:
      if ((((uVar1 & 0xf) == 2) || (cVar9 == '\0')) && (cVar9 = cVar10, cVar13 != '\0')) {
        cVar9 = cVar13;
      }
      goto LAB_0002d8bd;
    }
    if (uVar3 == 0x85ba) {
      cVar9 = '\'';
      goto LAB_0002d8bd;
    }
    if (uVar3 == 0x85bb) {
      cVar9 = '&';
      goto LAB_0002d8bd;
    }
  }
  cVar9 = '\0';
LAB_0002d8bd:
  *(char *)(param_2 + 0x38) = cVar9;
  return;
}

/* FUN_0002df06 @ 0x2df06 (54 bytes) */
int FUN_0002df06(param_1, param_2, param_3, param_4)
  uint param_1;
  int param_2;
  int param_3;
  int param_4;
{
  param_4 = (param_2 + 3 >> 2) * (param_3 + 3 >> 2) * param_4;
  if (param_1 == 0xc) {
    return param_4 * 8;
  }
  if ((0xb < param_1) && (param_1 < 0x10)) {
    return param_4 * 0x10;
  }
  return 0;
}

/* FUN_0002df3c @ 0x2df3c (559 bytes) */
int FUN_0002df3c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  void *param_1;
  int param_2;
  uint param_3;
  uint param_4;
  int param_5;
  uint param_6;
  uint param_7;
{
  float fVar1;
  ushort uVar2;
  
  _memcpy(param_1,PTR_DAT_00213291,0x74);
  *(ushort *)((int)param_1 + 0xc) =
       *(ushort *)((int)param_1 + 0xc) & 0xc001 |
       ((ushort)((param_4 >> (*(byte *)(param_2 + 0x17) >> 5)) >> 1) & 0x1fff) * 2;
  *(byte *)((int)param_1 + 0xe) = *(byte *)((int)param_1 + 0xe) & 0xe0 | param_5 & 1 | param_5 & 6;
  *(ushort *)((int)param_1 + 0xe) =
       *(ushort *)((int)param_1 + 0xe) & 0xfe1f | (*(byte *)(param_2 + 0x1a) >> 2 & 0xf) << 5;
  *(byte *)((int)param_1 + 0x14) =
       *(byte *)((int)param_1 + 0x14) & 0xe0 | *(byte *)(param_2 + 0x18) & 3;
  *(uint *)((int)param_1 + 0x14) = *(uint *)((int)param_1 + 0x14) & 0x1f;
  uVar2 = (short)param_6 - 1;
  *(ushort *)((int)param_1 + 0x1c) = *(ushort *)((int)param_1 + 0x1c) & 0xf800 | uVar2 & 0x7ff;
  *(uint *)((int)param_1 + 0x1c) =
       *(uint *)((int)param_1 + 0x1c) & 0xffc007ff | (param_7 - 1 & 0x7ff) << 0xb;
  *(ushort *)((int)param_1 + 0x1e) = *(ushort *)((int)param_1 + 0x1e) & 0xfc3f;
  *(byte *)((int)param_1 + 0x1f) = *(byte *)((int)param_1 + 0x1f) & 0x83 | 0x80;
  *(ushort *)((int)param_1 + 0x24) =
       *(ushort *)((int)param_1 + 0x24) & 0xc000 |
       (short)(param_3 >> (*(byte *)(param_2 + 0x17) >> 5)) - 1U & 0x3fff;
  *(byte *)((int)param_1 + 0x25) = *(byte *)((int)param_1 + 0x25) & 0x3f | (0x800 < param_6) << 7;
  *(byte *)((int)param_1 + 0x26) = *(byte *)((int)param_1 + 0x26) & 0xf0 | 0x800 < param_7;
  *(ushort *)((int)param_1 + 0x30) = *(ushort *)((int)param_1 + 0x30) & 0xe000 | uVar2 & 0x1fff;
  *(uint *)((int)param_1 + 0x30) =
       *(uint *)((int)param_1 + 0x30) & 0xfc001fff | (param_7 - 1 & 0x1fff) << 0xd;
  *(uint *)((int)param_1 + 0x4c) = param_6 * 0x60000 | param_7 * 6;
  fVar1 = FLOAT_001c5bd4;
  if ((int)param_6 < 0) {
    *(float *)((int)param_1 + 0x58) = (float)param_6 * FLOAT_001c5bd4;
  }
  else {
    *(float *)((int)param_1 + 0x58) = (float)(int)param_6 * FLOAT_001c5bd4;
  }
  if (-1 < (int)param_7) {
    *(float *)((int)param_1 + 0x5c) = (float)(int)param_7 * fVar1;
    return (int)param_1 + 0x74;
  }
  *(float *)((int)param_1 + 0x5c) = (float)param_7 * fVar1;
  return (int)param_1 + 0x74;
}

/* FUN_0002e16b @ 0x2e16b (456 bytes) */
int FUN_0002e16b(param_1, param_2, param_3, param_4)
  undefined1 *param_1;
  byte *param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  sbyte sVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte *local_68;
  byte *local_64;
  byte *local_60;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  int local_2c [8];
  
  uVar5 = 0;
  uVar6 = 0xff;
  local_30 = 0;
  local_68 = param_2;
  do {
    iVar3 = 0;
    pbVar4 = local_68;
    do {
      uVar1 = (uint)*pbVar4;
      if (uVar1 < uVar6) {
        uVar6 = uVar1;
      }
      if (uVar5 < uVar1) {
        uVar5 = uVar1;
      }
      iVar3 = iVar3 + 1;
      pbVar4 = pbVar4 + param_3;
    } while (iVar3 != 4);
    local_30 = local_30 + 1;
    local_68 = local_68 + param_4;
  } while (local_30 != 4);
  local_50 = uVar5 * 0x100;
  local_4c = uVar6 * 0x100;
  local_40 = (int)(local_50 + uVar6 * -0x100) / 7;
  if (local_50 == local_4c) {
    if (uVar6 == 0) {
      local_50 = 0x100;
      local_40 = 0xffff;
      local_3c = 0x7fff;
    }
    else {
      local_4c = local_4c + -0x100;
      local_40 = 0xffff;
      local_3c = 0x7fff;
    }
  }
  else {
    local_3c = local_40 >> 1;
  }
  local_2c[0] = 1;
  local_2c[1] = 7;
  local_2c[2] = 6;
  local_2c[3] = 5;
  local_2c[4] = 4;
  local_2c[5] = 3;
  local_2c[6] = 2;
  local_2c[7] = 0;
  local_48 = 0;
  local_38 = 0x10;
  local_64 = param_2;
  do {
    local_34 = local_38;
    local_44 = 0;
    local_60 = local_64;
    do {
      pbVar4 = param_1 + ((int)local_34 >> 3);
      iVar3 = local_2c[(int)(((uint)*local_60 * 0x100 + local_3c) - local_4c) / local_40];
      sVar2 = (sbyte)(local_34 & 7);
      *pbVar4 = ~(byte)(7 << sVar2) & *pbVar4 | (byte)(iVar3 << sVar2);
      if (5 < (local_34 & 7)) {
        pbVar4[1] = ~(byte)(7 >> (8U - sVar2 & 0x1f)) & pbVar4[1] |
                    (byte)(iVar3 >> (8U - sVar2 & 0x1f));
      }
      local_44 = local_44 + 1;
      local_60 = local_60 + param_3;
      local_34 = local_34 + 3;
    } while (local_44 != 4);
    local_48 = local_48 + 1;
    local_64 = local_64 + param_4;
    local_38 = local_38 + 0xc;
  } while (local_48 != 4);
  (*(unsigned char *)((unsigned char *)&(local_50) + 0)) = (undefined1)((uint)local_50 >> 8);
  *param_1 = (undefined1)local_50;
  (*(unsigned char *)((unsigned char *)&(local_4c) + 0)) = (undefined1)((uint)local_4c >> 8);
  param_1[1] = (undefined1)local_4c;
  return;
}

/* FUN_0002e333 @ 0x2e333 (120 bytes) */
int FUN_0002e333(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x1dc);
  if (*(int **)(param_1 + 0x1e0) <= piVar2 + 1) {
    FUN_00017c77(param_1,0x1000000);
    piVar2 = *(int **)(param_1 + 0x1dc);
  }
  *(int **)(param_1 + 0x1dc) = piVar2 + 1;
  puVar1 = *(uint **)(param_1 + 0x1d8);
  *puVar1 = *puVar1 | (int)piVar2 - (int)puVar1 >> 2;
  *(int **)(param_1 + 0x1d8) = piVar2;
  *piVar2 = param_2 * 0x1000000 + 0x16000000;
  FUN_000a665d();
  return;
}

/* FUN_0002e3ab @ 0x2e3ab (106 bytes) */
int FUN_0002e3ab(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0xf;
  iVar1 = param_1;
  do {
    if (*(int *)(iVar1 + 0x1c8) != 0) {
      param_2 = ((int (*)())FUN_0002ac68)(param_1,0,iVar2,param_2);
    }
    iVar1 = iVar1 + -4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  ((int (*)())FUN_0002ac68)(param_1,param_3,0,param_2);
  return;
}

/* FUN_0002e415 @ 0x2e415 (134 bytes) */
int FUN_0002e415(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_18;
  undefined4 local_14;
  
  iVar5 = 0;
  local_18 = 0;
  iVar4 = param_1;
  local_14 = param_2;
  do {
    iVar1 = *(int *)(iVar4 + 0x18c);
    if (iVar1 != 0) {
      piVar3 = (int *)(local_18 + *(int *)(param_1 + 0x18));
      iVar2 = 5;
      do {
        if (iVar1 == *piVar3) {
          if (*(int *)(iVar1 + 0x34) != 0) goto LAB_0002e454;
          break;
        }
        piVar3 = piVar3 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      iVar1 = 0;
    }
LAB_0002e454:
    if ((iVar5 == 0) || (iVar1 != 0)) {
      local_14 = ((int (*)())FUN_0002ac68)(param_1,iVar1,iVar5,local_14);
    }
    iVar5 = iVar5 + 1;
    local_18 = local_18 + 0x14;
    iVar4 = iVar4 + 4;
    if (iVar5 == 0x10) {
      return local_14;
    }
  } while( true );
}

/* FUN_0002e49b @ 0x2e49b (29 bytes) */
int FUN_0002e49b(param_1)
  uint param_1;
{
  int iVar1;
  
  if (1 < param_1) {
    iVar1 = 0;
    do {
      param_1 = param_1 >> 1;
      iVar1 = iVar1 + 1;
    } while (1 < param_1);
    return iVar1;
  }
  return 0;
}

/* FUN_0002e4b8 @ 0x2e4b8 (129 bytes) */
int FUN_0002e4b8(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x18c + param_3 * 4) = param_2;
  uVar2 = (**(code **)(iVar1 + 0x2998))(param_1,0xe);
  *(undefined4 *)(iVar1 + 0x298c) = uVar2;
  uVar2 = ((int (*)())FUN_0002ac68)(iVar1,param_2,param_3,uVar2);
  *(undefined4 *)(iVar1 + 0x298c) = uVar2;
                    
                    
  (**(code **)(iVar1 + 0x299c))();
  return;
}

/* FUN_0002e539 @ 0x2e539 (29 bytes) */
int FUN_0002e539(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  _gldDeleteTexture(*(undefined4 *)(param_1 + 4),param_2);
  return;
}

/* FUN_0002e556 @ 0x2e556 (142 bytes) */
int FUN_0002e556(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 *param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  *param_1 = 0xc0101000;
  param_1[1] = 0x51b;
  param_1[2] = (param_2 & 0xf) << 8 | 0x42cc30f3;
  param_1[3] = 0x1056b;
  param_1[4] = 0;
  param_1[5] = param_3;
  param_1[6] = 0x10501;
  param_1[7] = 0;
  param_1[8] = param_4;
  param_1[9] = 0x5c1;
  param_1[10] = 0;
  param_1[0xb] = 0x5c0;
  param_1[0xc] = param_5;
  param_1[0xd] = 0x50d;
  param_1[0xe] = param_6;
  param_1[0xf] = 0x1050e;
  param_1[0x10] = 0;
  param_1[0x11] = param_7;
  return param_1 + 0x12;
}

/* FUN_0002e5e4 @ 0x2e5e4 (183 bytes) */
int FUN_0002e5e4(param_1)
  int param_1;
{
  int iVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  pbVar2 = *(byte **)(param_1 + 0x30);
  bVar3 = *pbVar2 & 0xf;
  *(byte *)(param_1 + 0x6c) = bVar3;
  iVar1 = *(short *)(pbVar2 + 0x3c) * 0x18;
  uVar5 = (uint)pbVar2[iVar1 + 0xaa];
  uVar4 = (uint)*(ushort *)(pbVar2 + iVar1 + 0xa4) + uVar5 * -2;
  if ((int)uVar4 < 1) {
    uVar4 = 1;
  }
  uVar6 = (uint)*(ushort *)(pbVar2 + iVar1 + 0xa6) + uVar5 * -2;
  if ((int)uVar6 < 1) {
    uVar6 = 1;
  }
  uVar5 = (uint)*(ushort *)(pbVar2 + iVar1 + 0xa8) + uVar5 * -2;
  if ((int)uVar5 < 1) {
    uVar5 = 1;
  }
  if (bVar3 == 1) {
    if ((uVar4 & uVar4 - 1) != 0) {
      return 1;
    }
    if ((uVar6 & uVar6 - 1) != 0) {
      return 1;
    }
    uVar6 = uVar5 & uVar5 - 1;
  }
  else if ((bVar3 == 0) || (bVar3 == 3)) {
    if ((uVar4 & uVar4 - 1) != 0) {
      return 1;
    }
    uVar6 = uVar6 & uVar6 - 1;
  }
  else {
    if (bVar3 != 4) {
      return 1;
    }
    uVar6 = uVar4 & uVar4 - 1;
  }
  if (uVar6 != 0) {
    return 1;
  }
  return 0;
}

/* FUN_0002e69b @ 0x2e69b (586 bytes) */
int FUN_0002e69b(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  undefined4 uVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  undefined1 local_30;
  int local_20 [4];
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  local_20[0] = 0;
  puVar2 = _malloc(0x910);
  if (puVar2 != (undefined2 *)0x0) {
    *puVar2 = (short)param_8;
    puVar2[1] = param_5;
    *(undefined4 *)(puVar2 + 2) = 0x3f800000;
    *(undefined4 *)(puVar2 + 4) = 0;
    puVar2[6] = 0x405;
    puVar2[8] = 0x2901;
    puVar2[9] = 0x2901;
    puVar2[10] = 0x2901;
    puVar2[0xb] = 0x2600;
    puVar2[0xc] = 0x2600;
    puVar2[0xd] = 0x85bd;
    *(undefined4 *)(puVar2 + 0xe) = 0;
    *(undefined4 *)(puVar2 + 0x10) = 0;
    *(undefined4 *)(puVar2 + 0x12) = 0;
    *(undefined4 *)(puVar2 + 0x14) = 0;
    *(undefined4 *)(puVar2 + 0x16) = 0x3f800000;
    *(undefined4 *)(puVar2 + 0x18) = 0xc47a0000;
    *(undefined4 *)(puVar2 + 0x1a) = 0x447a0000;
    *(undefined4 *)(puVar2 + 0x1c) = 0;
    puVar2[0x1e] = 0;
    puVar2[0x1f] = 0;
    puVar2[0x20] = 0;
    puVar2[0x21] = 0;
    *(undefined4 *)(puVar2 + 0x22) = 0;
    puVar2[0x24] = 0;
    *(byte *)(puVar2 + 0x25) = *(byte *)(puVar2 + 0x25) & 0xfe;
    *(byte *)((int)puVar2 + 0x4b) = *(byte *)((int)puVar2 + 0x4b) & 0xfe;
    *(undefined4 *)(puVar2 + 0x26) = 0;
    puVar2[0x2a] = param_5;
    puVar2[0x2c] = param_5;
    puVar2[0x2d] = param_7;
    puVar2[0x2e] = 0x2600;
    *(undefined1 *)(puVar2 + 0x2f) = 0;
    *(undefined1 *)((int)puVar2 + 0x5f) = 0;
    iVar3 = ((int (*)())FUN_0002e49b)(param_2);
    iVar4 = ((int (*)())FUN_0002e49b)(param_3);
    iVar5 = ((int (*)())FUN_0002e49b)(param_4);
    local_30 = (undefined1)iVar3;
    *(undefined1 *)(puVar2 + 0x30) = local_30;
    *(char *)((int)puVar2 + 0x61) = (char)iVar4;
    *(char *)(puVar2 + 0x31) = (char)iVar5;
    iVar7 = iVar4;
    if (iVar4 <= iVar5) {
      iVar7 = iVar5;
    }
    if (iVar7 < iVar3) {
      iVar7 = iVar3;
    }
    *(char *)((int)puVar2 + 99) = (char)iVar7;
    *(undefined1 *)(puVar2 + 0x32) = local_30;
    *(char *)((int)puVar2 + 0x65) = (char)iVar4;
    *(char *)(puVar2 + 0x33) = (char)iVar5;
    *(char *)((int)puVar2 + 0x67) = (char)iVar7;
    *(undefined1 *)((int)puVar2 + 0x69) = 0;
    *(undefined1 *)(puVar2 + 0x35) = 1;
    *(undefined1 *)((int)puVar2 + 0x6b) = 0;
    *(undefined1 *)(puVar2 + 0x36) = 1;
    *(undefined1 *)((int)puVar2 + 0x6d) = 0;
    *(char *)(puVar2 + 0x37) = (param_8 == 3) * '\x02';
    *(char *)((int)puVar2 + 0x6f) = (param_8 == 1) * '\x02';
    puVar2[0x38] = 1;
    puVar2[0x3e] = 1;
    iVar7 = 1 << ((byte)(DAT_001ecab7)[(uint)param_6 * 0x24] >> 5);
    pvVar6 = _malloc(param_2 * param_3 * param_4 * iVar7);
    if (pvVar6 != (void *)0x0) {
      puVar2[0x52] = (short)param_2;
      puVar2[0x53] = (short)param_3;
      puVar2[0x54] = (short)param_4;
      *(undefined1 *)(puVar2 + 0x55) = 0;
      puVar2[0x56] = (short)iVar7 * (short)param_2;
      puVar2[0x57] = (short)param_3;
      puVar2[0x58] = param_5;
      puVar2[0x59] = param_7;
      *(void **)(puVar2 + 0x5a) = pvVar6;
      iVar7 = _gldCreateTexture(uVar1,local_20,puVar2);
      if ((iVar7 == 0) && (local_20[0] != 0)) {
        *(undefined1 *)(local_20[0] + 0x39) = 0xff;
        *(byte *)(local_20[0] + 0x38) = param_6;
        *(ushort *)(local_20[0] + 0x24) = *(ushort *)(local_20[0] + 0x24) | 1;
        return local_20[0];
      }
    }
    _free(puVar2);
  }
  return 0;
}

/* FUN_0002e8e5 @ 0x2e8e5 (69 bytes) */
int FUN_0002e8e5(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  byte bVar1;
  
  bVar1 = *(byte *)(param_2 + 0x38);
  if (bVar1 == 0xc) {
    return -2;
  }
  if ((0xb < bVar1) && (bVar1 < 0x10)) {
    return 1;
  }
  return 1 << ((byte)(DAT_001ecab7)[(uint)bVar1 * 0x24] >> 5);
}

/* FUN_0002e92a @ 0x2e92a (439 bytes) */
int FUN_0002e92a(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  uint *param_5;
{
  int iVar1;
  short sVar2;
  byte bVar3;
  uint uVar4;
  
  if (*(char *)(param_2 + 0x38) == '\0') {
    ((int (*)())FUN_0002d708)();
  }
  iVar1 = (uint)*(byte *)(param_2 + 0x38) * 0x24;
  if ((((((DAT_001ecab1)[iVar1] & 0xfc) == 0) || (((DAT_001ecab2)[iVar1] & 0x3f) == 0)) ||
      ((*(ushort *)(DAT_001ecab2 + iVar1) & 0xfc0) == 0)) ||
     ((((DAT_001ecab4)[iVar1] & 0x3f) == 0 || (*(short *)(*(int *)(param_2 + 0x30) + 2) != 0x1907))
     )) {
    if (*(byte *)(param_2 + 0x38) == 0x29) {
      sVar2 = *(short *)(*(int *)(param_2 + 0x30) + 2);
      if (sVar2 == 0x1902) {
        *param_5 = 0x81a6;
        param_5[7] = (uint)((*(unsigned char *)0x001ed07a) >> 2);
      }
      else if (sVar2 == 0x1901) {
        *param_5 = 0x81a6;
        param_5[7] = 0;
      }
      else {
        *param_5 = (uint)(*(unsigned int *)0x001ed06c);
        param_5[7] = (uint)((*(unsigned char *)0x001ed07a) >> 2);
      }
      param_5[4] = 0;
    }
    else {
      *param_5 = (uint)*(ushort *)(&DAT_001ecaa8 + iVar1);
      param_5[4] = (uint)((DAT_001ecab4)[iVar1] & 0x3f);
      param_5[7] = (uint)((byte)(DAT_001ecab6)[iVar1] >> 2);
    }
  }
  else {
    *param_5 = (uint)*(ushort *)(&DAT_001ecaaa + iVar1);
    param_5[4] = 0;
    param_5[7] = (uint)((byte)(DAT_001ecab6)[iVar1] >> 2);
  }
  param_5[1] = (uint)((byte)(DAT_001ecab1)[iVar1] >> 2);
  param_5[2] = (uint)((DAT_001ecab2)[iVar1] & 0x3f);
  param_5[3] = *(ushort *)(DAT_001ecab2 + iVar1) >> 6 & 0x3f;
  param_5[5] = *(ushort *)(DAT_001ecab4 + iVar1) >> 6 & 0x3f;
  param_5[6] = *(uint *)(DAT_001ecab4 + iVar1) >> 0xc & 0x3f;
  bVar3 = (byte)(DAT_001ecab7)[iVar1] >> 4 & 1;
  *(byte *)(param_5 + 9) = bVar3;
  if (bVar3 == 0) {
    param_5[8] = 0;
    return;
  }
  uVar4 = ((int (*)())FUN_0002df06)(*(undefined2 *)
                        (*(int *)(param_2 + 0x30) + (param_4 * 3 + param_3 * 0x2d) * 8 + 0xa8));
  param_5[8] = uVar4;
  return;
}

/* FUN_0002eae1 @ 0x2eae1 (163 bytes) */
int FUN_0002eae1(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  uint param_1;
  undefined4 param_2;
  int param_3;
  uint *param_4;
  uint *param_5;
  uint *param_6;
  int *param_7;
  uint *param_8;
  uint *param_9;
{
  int iVar1;
  
  iVar1 = (param_1 & 0xff) * 0x24;
  *(uint *)(param_3 + 0x18) = (uint)((DAT_001ecab0)[iVar1] & 0x1f);
  *(uint *)(param_3 + 0x1c) = *(ushort *)(DAT_001ecab0 + iVar1) >> 5 & 0x1f;
  *param_8 = *(ushort *)(DAT_001ecab8 + iVar1) >> 4 & 0x1f;
  *param_9 = (uint)((DAT_001ecab8)[iVar1] & 3);
  *param_4 = (uint)((byte)(DAT_001ecab7)[iVar1] >> 5);
  *param_5 = (byte)(DAT_001ecab9)[iVar1] >> 1 & 7;
  *param_6 = (byte)(DAT_001ecab9)[iVar1] >> 4 & 7;
  *param_7 = 1 << ((byte)(DAT_001ecab7)[iVar1] >> 5);
  *(uint *)(param_3 + 0x24) = *(uint *)(param_3 + 0x24) & *(uint *)(&DAT_001ecaac + iVar1);
  return;
}

/* FUN_0002eb84 @ 0x2eb84 (222 bytes) */
int FUN_0002eb84(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
{
  int iVar1;
  undefined *puVar2;
  ushort uVar3;
  ushort *puVar4;
  uint uVar5;
  
  puVar4 = *(ushort **)(param_2 + 0x30);
  if (*(char *)(param_2 + 0x38) == '\0') {
    ((int (*)())FUN_0002d708)();
  }
  if ((((param_5 != '\0') ||
       ((((*(ushort *)(*(int *)(param_1 + 0x10) + 0x30b0) & 0x1ff) == 0 &&
         (uVar5 = *(uint *)(*(int *)(param_1 + 0x10) + 0x30b4), (uVar5 & 0xff0000) == 0)) &&
        ((uVar5 & 0xff1) == 0)))) &&
      (((char)puVar4[(param_4 * 3 + param_3 * 0x2d) * 4 + 0x55] == '\0' &&
       (uVar3 = *puVar4, (uVar3 & 0xf) != 4)))) && ((param_5 != '\0' || ((uVar3 & 0x400) == 0)))) {
    iVar1 = (uint)*(byte *)(param_2 + 0x38) * 0x24;
    puVar2 = &DAT_001ecaa0 + iVar1;
    if (((*(byte *)(*(int *)(param_2 + 0x30) + 0x4a) & 1) == 0) && (param_5 == '\0')) {
      return puVar2;
    }
    if (param_4 != *(byte *)(*(int *)(param_2 + 0x30) + 0x5e)) {
      return puVar2;
    }
    if ((char)(DAT_001ecac0)[iVar1] < '\0') {
      return puVar2;
    }
  }
  return (undefined *)0x0;
}

/* FUN_0002ec62 @ 0x2ec62 (1569 bytes) */
int FUN_0002ec62(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int *param_2;
  int param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
  int param_8;
{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int local_120;
  int local_118;
  int local_110;
  undefined4 local_10c;
  uint local_108;
  undefined4 local_f4;
  undefined4 local_f0;
  int local_9c;
  uint local_98;
  undefined4 local_94;
  undefined4 local_90;
  int local_8c;
  int local_88;
  undefined1 local_84 [4];
  undefined1 local_80 [4];
  undefined4 local_7c;
  uint local_78;
  undefined4 local_74;
  int local_70;
  int local_6c;
  undefined1 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  
  iVar10 = *param_2;
  puVar2 = (undefined4 *)param_2[0xd];
  if ((puVar2 == (undefined4 *)0x0) || ((char)param_2[0xe] == '\0')) {
    return 0x2717;
  }
  if ((*(short *)(param_2[0xc] + 2) == 0x1902) && ((char)param_2[0x32] == '\x01')) {
    puVar7 = (undefined4 *)(**(code **)(param_1 + 0x2998))(param_1 + 0x240,0x3fa);
    *(undefined4 **)(param_1 + 0x298c) = puVar7;
    puVar3 = *(uint **)(param_1 + 0x1d8);
    *puVar3 = *puVar3 | (int)puVar7 - (int)puVar3 >> 2;
    *(undefined4 **)(param_1 + 0x1d8) = puVar7;
    *puVar7 = 0x45000000;
    puVar7[1] = 0x3ed;
    puVar7[2] = 0xd;
    puVar7[3] = *(undefined4 *)param_2[0xd];
    puVar7[4] = (uint)*(byte *)(param_2 + 0xe);
    puVar7[0x3ed] = &UINT_000013c4;
    puVar7[0x3ef] = 0x113c8;
    puVar7[0x3f2] = 0x13cd;
    puVar7[0x3f4] = &UINT_000013cc;
    puVar7[0x3f6] = 0x13ca;
    *(undefined4 **)(param_1 + 0x298c) = puVar7 + 0x3f8;
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240,puVar7 + 0x3f8);
    if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
      FUN_00017c77(param_1,0x1000000);
    }
    *(undefined1 *)(param_2 + 0x32) = 0;
  }
  cVar4 = *(char *)((int)puVar2 + 0x16);
  if ((cVar4 != '\x03') && (cVar4 != '\a')) {
    if (cVar4 != '\x06') {
      return 0x2717;
    }
    if ((0x1ffff < (int)puVar2[4]) &&
       (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc))) {
      FUN_00017c77(param_1,0x1000000);
    }
    if ((((uint)*(ushort *)((int)puVar2 + param_3 * 2 + 0x28) &
         ~(uint)*(ushort *)((int)puVar2 + param_3 * 2 + 0x1c)) >> ((byte)param_4 & 0x1f) & 1) == 0)
    {
      return 0;
    }
    cVar4 = FUN_00017c5b(param_1,puVar2[3]);
    if (cVar4 == '\0') {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,puVar2 + 3,1,0,0);
    }
    if ((param_7 != 0) && ((*(byte *)(param_1 + 0x24) & 0x82) != 0)) {
      FUN_00009948(param_1,param_7,param_2[4]);
    }
    *(ushort *)((int)puVar2 + param_3 * 2 + 0x1c) =
         *(ushort *)((int)puVar2 + param_3 * 2 + 0x1c) |
         *(ushort *)((int)puVar2 + param_3 * 2 + 0x28);
    return 0;
  }
  iVar1 = iVar10 + 0x40 + (param_3 * 0xd + param_4) * 0x20;
  if ((0x1ffff < (int)puVar2[4]) && (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc))
     ) {
    FUN_00017c77(param_1,0x1000000);
  }
  if ((((uint)*(ushort *)((int)puVar2 + param_3 * 2 + 0x28) &
       ~(uint)*(ushort *)((int)puVar2 + param_3 * 2 + 0x1c)) >> ((byte)param_4 & 0x1f) & 1) != 0) {
    local_10c = *puVar2;
    local_108 = param_3 << 0x10 | param_4;
    _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xd,&local_10c,2,0,0);
  }
  if ((*(byte *)(iVar10 + 0x20) & 8) != 0) {
    cVar4 = FUN_00017c5b(param_1,*(undefined4 *)(iVar10 + 0x1c));
    if (cVar4 == '\0') {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar10 + 0x1c,1,0,0);
    }
    *(byte *)(iVar10 + 0x20) = *(byte *)(iVar10 + 0x20) & 0xf7;
  }
  if (*(char *)((int)puVar2 + 0x16) == '\a') {
    return 0;
  }
  (*(unsigned char *)((unsigned char *)&(param_4) + 0)) = (byte)param_4 - *(char *)((int)puVar2 + 0x17);
  iVar6 = (int)(uint)*(ushort *)(iVar10 + 0x14) >> ((byte)param_4 & 0x1f);
  local_110 = (int)(uint)*(ushort *)(iVar10 + 0x16) >> ((byte)param_4 & 0x1f);
  iVar8 = (int)(uint)*(ushort *)(iVar10 + 0x18) >> ((byte)param_4 & 0x1f);
  if (iVar6 < 1) {
    iVar6 = 1;
  }
  if (local_110 < 1) {
    local_110 = 1;
  }
  if (iVar8 < 1) {
    iVar8 = 1;
  }
  iVar8 = iVar8 / (int)(uint)*(ushort *)(iVar1 + 2);
  ((int (*)())FUN_0002eae1)(local_24,local_20,local_1c,local_18,local_14,local_10);
  local_2c = local_f4;
  local_28 = local_f0;
  local_6c = local_110;
  local_7c = 2;
  local_78 = 0;
  local_74 = 0xffffefff;
  local_94 = local_f4;
  local_90 = local_f0;
  uVar9 = *(uint *)(iVar10 + 0x10) >> ((byte)param_4 & 0x1f);
  local_98 = 0x20;
  if (0x1f < (int)uVar9) {
    local_98 = uVar9;
  }
  local_8c = param_7;
  local_88 = param_8;
  local_30 = 0;
  local_70 = iVar6;
  _glgConvertType(param_5,param_6,local_84,local_80);
  local_118 = *(int *)(iVar1 + 0x1c);
  if (local_118 == 0) {
    return 0x2717;
  }
  sVar5 = *(short *)(param_2[0xc] + 2);
  if ((sVar5 == 0x1909) || (uVar9 = local_78 | 0x20000, sVar5 == 0x1907)) {
    local_78 = local_78 | 0x28000;
    sVar5 = *(short *)(param_2[0xc] + 2);
    uVar9 = local_78;
    if (sVar5 != 0x1909) goto LAB_0002eedf;
  }
  else {
LAB_0002eedf:
    local_78 = uVar9;
    if ((sVar5 != -0x7fb7) && (sVar5 != 0x190a)) goto LAB_0002eef3;
  }
  local_78 = local_78 | 0x40000;
LAB_0002eef3:
  if (*(short *)(iVar1 + 2) != 0) {
    local_120 = 0;
    do {
      local_9c = local_118;
      if (0 < iVar8) {
        iVar10 = 0;
        do {
          _glgProcessPixels(0,&local_9c);
          local_9c = local_9c + local_110 * local_98;
          local_8c = local_8c + local_110 * local_88;
          iVar10 = iVar10 + 1;
        } while (iVar8 != iVar10);
      }
      local_118 = local_118 + *(int *)(iVar1 + 0xc);
      local_120 = local_120 + 1;
    } while (local_120 < (int)(uint)*(ushort *)(iVar1 + 2));
  }
  return 0;
}

/* _gldGetTextureLevel @ 0x2f283 (195 bytes) */
int _gldGetTextureLevel(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_2 + 0x30) != 0) {
    iVar1 = *(int *)(param_2 + 0x30) + 0xa0 + (param_4 * 3 + param_3 * 0x2d) * 8;
    uVar2 = *(ushort *)(iVar1 + 0xc);
    iVar3 = FUN_00009369(*(undefined2 *)(iVar1 + 0x10),*(undefined2 *)(iVar1 + 0x12));
    _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
    uVar4 = ((int (*)())FUN_0002ec62)(param_1,param_2,param_3,param_4,*(undefined2 *)(iVar1 + 0x10),
                         *(undefined2 *)(iVar1 + 0x12),*(undefined4 *)(iVar1 + 0x14),
                         iVar3 * (uint)uVar2);
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return uVar4;
  }
  return 0x2717;
}

/* FUN_0002f346 @ 0x2f346 (2670 bytes) */
int FUN_0002f346(param_1, param_2)
  int param_1;
  int *param_2;
{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  sbyte sVar6;
  bool bVar7;
  byte bVar8;
  char cVar9;
  int iVar10;
  void *pvVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  byte bVar15;
  uint uVar16;
  byte bVar17;
  byte bVar18;
  byte bVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  uint uVar24;
  undefined *puVar25;
  int *piVar26;
  bool bVar27;
  bool bVar28;
  bool local_fe;
  byte local_fd;
  int *local_fc;
  uint local_f4;
  uint local_cc;
  sbyte local_bc;
  int *local_b8;
  void *local_a0;
  int local_9c;
  undefined1 local_98 [4];
  undefined1 local_94 [4];
  int *local_90;
  uint local_8c;
  undefined4 local_7c;
  uint local_74;
  uint local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 local_30 [4];
  int local_2c;
  int local_28;
  uint local_24;
  byte local_20 [16];
  
  iVar3 = param_2[0xc];
  uVar2 = *(ushort *)(iVar3 + 0x7c);
  iVar23 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
  bVar27 = ((DAT_001ecab7)[iVar23] & 0xe0) == 0x80;
  bVar7 = !bVar27;
  bVar15 = *(byte *)(iVar3 + 0x5e);
  iVar3 = iVar3 + 0xa0 + (uint)bVar15 * 0x18;
  iVar10 = FUN_00009369(*(undefined2 *)(iVar3 + 0x10),*(undefined2 *)(iVar3 + 0x12));
  iVar20 = (uint)*(ushort *)(iVar3 + 0xc) * iVar10;
  pvVar11 = (void *)((iVar10 + iVar20) * (uint)*(byte *)(iVar3 + 10) + *(int *)(iVar3 + 0x14));
  ((int (*)())FUN_0002eae1)(local_20,local_30,local_30,&local_2c,&local_24,&local_28);
  uVar21 = (uint)*(ushort *)(iVar3 + 4) + (uint)*(byte *)(iVar3 + 10) * -2;
  if ((int)uVar21 < 1) {
    uVar21 = 1;
  }
  uVar16 = (uint)*(ushort *)(iVar3 + 6) + (uint)*(byte *)(iVar3 + 10) * -2;
  uVar22 = 1;
  if (0 < (int)uVar16) {
    uVar22 = uVar16;
  }
  local_7c = 0;
  if (bVar27) {
    bVar8 = 0;
    bVar27 = false;
LAB_0002f4d7:
    sVar6 = 0;
  }
  else {
    bVar8 = (byte)(DAT_001ecab8)[iVar23] >> 2 & 3;
    if (bVar8 != 0) {
      bVar27 = false;
      if (((DAT_001ecab8)[iVar23] & 0xc) == 8) goto LAB_0002f6a4;
      goto LAB_0002f4d7;
    }
    bVar27 = true;
    if (((DAT_001ecab8)[iVar23] & 0xc) != 8) goto LAB_0002f4d7;
LAB_0002f6a4:
    if (((DAT_001ecab7)[iVar23] & 0xe0) != 0x20) goto LAB_0002f4d7;
    sVar6 = 1;
  }
  bVar17 = (byte)(*(unsigned int *)((unsigned char *)&(local_20) + 0));
  uVar16 = (0x20 >> (bVar8 + bVar17 & 0x1f)) * 8;
  uVar24 = 8 << bVar8;
  if ((uVar16 < uVar21) && (uVar24 < uVar22)) {
    local_fd = 1;
  }
  else {
    local_fd = 0;
  }
  uVar12 = (uVar21 << (bVar17 & 0x1f)) + 0x1f & 0xffffffe0;
  iVar10 = uVar12 * uVar22;
  bVar28 = local_fd != 0;
  iVar23 = iVar10;
  local_f4 = uVar12;
  if (bVar28) {
    local_f4 = (((uVar16 - 1) + uVar21) / uVar16) * uVar16 << (bVar17 & 0x1f);
    iVar23 = uVar24 * (((uVar24 - 1) + uVar22) / uVar24) * local_f4;
  }
  local_fe = bVar28 && bVar7;
  *(short *)((int)param_2 + 0x3e) = (short)(local_f4 >> (bVar17 & 0x1f));
  cVar9 = FUN_00009a9e(param_1,param_2,iVar10 + 0x3a0,iVar23);
  if (cVar9 == '\0') {
    return 0;
  }
  *(byte *)(param_2[0xd] + 0x15) = local_fd << 2 | (local_fe << sVar6 & 3U) << 3;
  piVar4 = (int *)*param_2;
  if ((uVar2 & 1) != 0) {
    _glgConvertType(*(undefined2 *)(iVar3 + 0x10),*(undefined2 *)(iVar3 + 0x12),local_98,local_94);
    local_6c = 0;
    local_68 = 0;
    piVar26 = piVar4 + 0x368;
    local_a0 = pvVar11;
    local_9c = iVar20;
    local_90 = piVar26;
    local_8c = uVar12;
    local_74 = uVar21;
    local_70 = uVar22;
    cVar9 = ((int (*)())FUN_0002d1fb)();
    if (cVar9 == '\0') {
      _glgProcessPixels(0,&local_a0);
    }
    else if (uVar22 != 0) {
      local_cc = 0;
      do {
        _memcpy(piVar26,pvVar11,local_2c * local_74);
        piVar26 = (int *)((int)piVar26 + local_8c);
        pvVar11 = (void *)((int)pvVar11 + local_9c);
        local_cc = local_cc + 1;
      } while (local_cc < local_70);
    }
    if ((*(byte *)(param_1 + 0x24) & 0x82) != 0) {
      FUN_00009943(param_1,piVar4 + 0x2a0,iVar10);
    }
  }
  if ((*(byte *)((int)param_2 + 0x39) & 3) == 0) goto LAB_0002f634;
  if (local_24 < 3) {
LAB_0002f6cd:
    local_bc = 0;
  }
  else if (local_24 < 5) {
    local_bc = 1;
  }
  else {
    if (local_24 != 6) goto LAB_0002f6cd;
    local_bc = 2;
  }
  bVar5 = (int)(uVar21 << (local_20[0] & 0x1f)) >> local_bc < 0x2000;
  *(byte *)(param_2[0xd] + 0x17) = bVar15;
  *(undefined1 *)(param_2[0xd] + 0x34) = 1;
  *(undefined1 *)(param_2[0xd] + 0x35) = 1;
  *(byte *)(*param_2 + 0x20) = *(byte *)(*param_2 + 0x20) & 0xfe | bVar5;
  *(byte *)(*param_2 + 0x20) = *(byte *)(*param_2 + 0x20) | 2;
  bVar8 = *(byte *)(piVar4 + 8);
  *(byte *)(piVar4 + 8) = bVar8 & 0xf7;
  piVar4[1] = 0x20;
  *piVar4 = 0;
  piVar4[2] = 0;
  *(byte *)((int)piVar4 + 0x1a) = local_20[0];
  *(char *)((int)piVar4 + 0x1b) = (char)local_28;
  *(short *)(piVar4 + 5) = (short)uVar21;
  *(short *)((int)piVar4 + 0x16) = (short)uVar22;
  *(undefined2 *)(piVar4 + 6) = 1;
  piVar4[3] = local_f4;
  piVar4[4] = uVar12;
  *(byte *)(piVar4 + 8) = bVar8 & 0xf3;
  piVar26 = piVar4 + 0x280;
  iVar23 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
  puVar25 = &DAT_001ecaa0 + iVar23;
  if (-1 < (char)(DAT_001ecab9)[iVar23]) {
    if (((DAT_001ecab7)[iVar23] & 0x10) == 0) {
      bVar8 = (byte)(DAT_001ecab7)[iVar23] >> 5;
      if (bVar8 == 1) {
        puVar25 = &DAT_001ecb78;
      }
      else if (bVar8 < 2) {
        if (bVar8 == 0) {
          puVar25 = &DAT_001ecb0c;
        }
        else {
LAB_0002f800:
          puVar25 = &DAT_001ecd28;
        }
      }
      else {
        if (bVar8 == 2) goto LAB_0002fd15;
        if (bVar8 != 3) goto LAB_0002f800;
        puVar25 = &DAT_001eced8;
      }
    }
    else {
LAB_0002fd15:
      puVar25 = &DAT_001ecbc0;
    }
  }
  _memcpy(piVar4 + 0x2a0,PTR_DAT_00213295,0x23c);
  piVar4[0x2ab] = 0;
  *(byte *)(piVar4 + 0x306) =
       *(byte *)(piVar4 + 0x306) & 0xe0 | (byte)(*(ushort *)(puVar25 + 0x1a) >> 6) & 0x1f;
  bVar17 = (byte)puVar25[0x1b] >> 3 & 3;
  bVar8 = *(byte *)((int)piVar4 + 0xc19);
  *(byte *)((int)piVar4 + 0xc19) = bVar8 & 0xfc | bVar17;
  bVar18 = (byte)puVar25[0x1b] >> 3 & 0xc;
  *(byte *)((int)piVar4 + 0xc19) = bVar8 & 0xf0 | bVar17 | bVar18;
  bVar19 = (puVar25[0x1c] & 3) << 4;
  *(byte *)((int)piVar4 + 0xc19) = bVar8 & 0xc0 | bVar17 | bVar18 | bVar19;
  *(byte *)((int)piVar4 + 0xc19) = bVar17 | bVar18 | bVar19 | ((byte)puVar25[0x1c] >> 2) << 6;
  *(byte *)((int)piVar4 + 0xc1a) = *(byte *)((int)piVar4 + 0xc1a) & 0xf0;
  *(byte *)(piVar4 + 0x31c) = (byte)(*(ushort *)(puVar25 + 0x1e) >> 4) & 0x1f;
  bVar8 = *(byte *)((int)piVar4 + 0xc71);
  *(byte *)((int)piVar4 + 0xc71) = bVar8 & 0xfe;
  bVar17 = puVar25[0x1f];
  *(byte *)((int)piVar4 + 0xc71) = bVar8 & 0xf0 | bVar17 & 0xe;
  *(byte *)((int)piVar4 + 0xc71) = bVar8 & 0x80 | bVar17 & 0xe | puVar25[0x1f] & 0x70;
  piVar4[0x31c] = piVar4[0x31c] & 0xfffc7fffU | (uint)(puVar25[0x20] & 7) << 0xf;
  bVar17 = (byte)puVar25[0x20] >> 1 & 0x1c;
  bVar8 = *(byte *)((int)piVar4 + 0xc72);
  *(byte *)((int)piVar4 + 0xc72) = bVar8 & 0xc3 | bVar17;
  *(byte *)((int)piVar4 + 0xc72) = bVar8 & 3 | bVar17 | puVar25[0x20] & 0x40;
  *(byte *)((int)piVar4 + 0xc73) = *(byte *)((int)piVar4 + 0xc73) & 0xf8;
  local_fc = piVar26;
  if (bVar5) {
    *piVar26 = 0x1393;
    piVar4[0x281] = 10;
    piVar4[0x282] = 0x5c8;
    piVar4[0x283] = 0x20000;
    piVar4[0x284] = 0x575;
    local_fc = piVar4 + 0x286;
    piVar4[0x285] = local_28;
  }
  piVar1 = piVar4 + (uint)bVar15 * 8 + 0x10;
  local_b8 = local_fc;
  *(short *)piVar1 = (short)((int)local_fc - (int)piVar26 >> 2);
  *(short *)(piVar1 + 6) = (short)((int)(piVar4 + 0x32f) - (int)piVar26 >> 2) - (short)piVar4[1];
  piVar1[1] = 0xda0;
  piVar1[2] = 0;
  piVar1[3] = 0;
  piVar1[4] = 0;
  *(undefined2 *)((int)piVar1 + 2) = 1;
  piVar1[5] = 0;
  piVar1[7] = (int)(piVar4 + 0x368);
  if ((!bVar28 || !bVar7) || (bVar27)) {
    bVar15 = 0;
  }
  else {
    bVar15 = 1;
  }
  local_fd = (sVar6 * '\x02' | bVar15) * '\x02' | local_fd;
  puVar13 = (undefined4 *)
            ((int (*)())FUN_0002df3c)(piVar4 + 0x32f,puVar25,uVar12,local_f4,local_fd,
                         (int)(uVar21 << (local_20[0] & 0x1f)) >> ((byte)puVar25[0x17] >> 5),uVar22)
  ;
  *puVar13 = 0x1393;
  puVar13[1] = 10;
  puVar13[2] = 0x5c8;
  puVar13[3] = 0x20000;
  puVar13[4] = 0x1040;
  puVar13[5] = 0;
  if (bVar5) {
    puVar14 = (undefined4 *)
              ((int (*)())FUN_0002e556)(local_fc,local_24,uVar12,local_f4,local_fd,0,
                           uVar22 << 0x10 | (int)(uVar21 << (local_20[0] & 0x1f)) >> local_bc);
    *puVar14 = 0xd0b;
    puVar14[1] = 5;
    puVar14[2] = 0x5c8;
    puVar14[3] = 0x10000;
    puVar14[4] = 0x1040;
    puVar14[5] = 0;
    local_b8 = puVar14 + 6;
  }
  piVar4[2] = ((int)puVar13 + (0x18 - (int)piVar26) >> 2) - piVar4[1];
  *piVar4 = (int)local_b8 - (int)piVar26 >> 2;
LAB_0002f634:
  *(ushort *)(param_2[0xd] + 0x1c) = *(ushort *)(param_2[0xd] + 0x1c) | uVar2;
  *(ushort *)(param_2[0xd] + 0x28) = *(ushort *)(param_2[0xd] + 0x28) & ~uVar2;
  *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) & 0xf8;
  *(ushort *)(param_2 + 9) = *(ushort *)(param_2 + 9) & ~uVar2;
  return 1;
}

/* FUN_0002fdb4 @ 0x2fdb4 (10558 bytes) */
int FUN_0002fdb4(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined1 *puVar1;
  ushort *puVar2;
  short sVar3;
  ushort *puVar4;
  byte *pbVar5;
  int *piVar6;
  size_t sVar7;
  bool bVar8;
  bool bVar9;
  ushort uVar10;
  char cVar11;
  byte bVar12;
  byte bVar13;
  ushort uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  int *piVar22;
  int iVar23;
  undefined1 *puVar24;
  int iVar25;
  undefined4 *puVar26;
  int *piVar27;
  undefined4 uVar28;
  undefined1 *puVar29;
  byte bVar30;
  byte bVar31;
  byte bVar32;
  byte bVar33;
  byte bVar34;
  uint uVar35;
  undefined *puVar36;
  uint uVar37;
  int iVar38;
  uint uVar39;
  int iVar40;
  undefined1 *puVar41;
  uint uVar42;
  uint uVar43;
  bool bVar44;
  bool bVar45;
  undefined1 *local_314;
  uint local_2fc;
  uint local_2c0;
  int local_2bc;
  uint local_2b8;
  int *local_2a0;
  byte local_298;
  char local_279;
  uint local_278;
  uint local_274;
  int local_26c;
  int local_268;
  int local_264;
  int *local_260;
  undefined1 *local_25c;
  uint local_258;
  byte local_254;
  byte local_250;
  byte local_24c;
  uint local_248;
  undefined *local_240;
  ushort local_236;
  sbyte local_224;
  undefined1 *local_200;
  int local_1f8;
  int local_1f0;
  uint local_1e0;
  undefined1 *local_1dc;
  bool local_1d5;
  int local_1d4;
  int local_1d0;
  int local_1c4;
  int local_1c0;
  sbyte local_1a8;
  int *local_1a0;
  int local_19c;
  int local_198;
  int local_194;
  int *local_190;
  int local_18c;
  int local_188;
  int *local_184;
  int *local_180;
  int local_17c;
  uint local_178;
  int local_174;
  int *local_164;
  uint local_160;
  uint local_15c;
  int local_158;
  uint local_154;
  byte local_150;
  undefined1 *local_14c;
  uint local_148;
  undefined1 local_144 [4];
  undefined1 local_140 [4];
  undefined1 *local_13c;
  int local_138;
  int local_130;
  undefined4 local_12c;
  uint local_128;
  undefined4 local_124;
  uint local_120;
  uint local_11c;
  undefined4 local_118;
  undefined4 local_114;
  int local_dc [9];
  undefined4 local_b8;
  int aiStack_6c [14];
  int local_34;
  int local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  byte local_20 [16];
  
  puVar4 = (ushort *)param_2[0xc];
  cVar11 = ((int (*)())FUN_0002e5e4)();
  if (cVar11 != '\0') {
    pbVar5 = (byte *)param_2[0xc];
    bVar30 = *pbVar5 & 0xf;
    *(byte *)(param_2 + 0x1b) = bVar30;
    iVar25 = *(short *)(pbVar5 + 0x3c) * 0x18;
    uVar15 = (uint)pbVar5[iVar25 + 0xaa];
    if (bVar30 == 0) {
      uVar16 = (uint)*(ushort *)(pbVar5 + iVar25 + 0xa4) + uVar15 * -2;
      if ((int)uVar16 < 1) {
        uVar16 = 1;
      }
      uVar15 = (uint)*(ushort *)(pbVar5 + iVar25 + 0xa6) + uVar15 * -2;
      if ((int)uVar15 < 1) {
        uVar15 = 1;
      }
      uVar16 = uVar16 & uVar16 - 1;
joined_r0x00030100:
      if ((uVar16 == 0) && ((uVar15 & uVar15 - 1) == 0)) {
LAB_00030052:
        bVar30 = *pbVar5 & 0xf;
        *(byte *)(param_2 + 0x1b) = bVar30;
        iVar25 = *(short *)(pbVar5 + 0x3c) * 0x18;
        uVar15 = (uint)pbVar5[iVar25 + 0xaa];
        if (bVar30 == 3) {
          uVar37 = (uint)*(ushort *)(pbVar5 + iVar25 + 0xa4) + uVar15 * -2;
          if ((int)uVar37 < 1) {
            uVar37 = 1;
          }
          uVar15 = (uint)*(ushort *)(pbVar5 + iVar25 + 0xa6) + uVar15 * -2;
          if ((int)uVar15 < 1) {
            uVar15 = 1;
          }
          if (((uVar37 & uVar37 - 1) != 0) || ((uVar15 & uVar15 - 1) != 0)) {
            if ((ushort)(*(short *)(pbVar5 + 0x16) + 0xda00U) < 2) {
              uVar14 = *(ushort *)(pbVar5 + 0x10);
              if (uVar14 < 0x8744) {
                if (((uVar14 < 0x8742) && (uVar14 != 0x2901)) && (uVar14 != 0x8370)) {
LAB_0003021f:
                  uVar14 = *(ushort *)(pbVar5 + 0x12);
                  if (uVar14 < 0x8744) goto LAB_0003022f;
LAB_0003028c:
                  if (uVar14 != 0x8912) goto LAB_0003008b;
                }
              }
              else if (uVar14 != 0x8912) goto LAB_0003021f;
            }
            goto LAB_0002fe47;
          }
        }
        else if (bVar30 == 4) {
          uVar15 = (uint)*(ushort *)(pbVar5 + iVar25 + 0xa4) + uVar15 * -2;
          if ((int)uVar15 < 1) {
            uVar15 = 1;
          }
          if ((uVar15 & uVar15 - 1) != 0) {
            if (1 < (ushort)(*(short *)(pbVar5 + 0x16) + 0xda00U)) goto LAB_0002fe47;
            uVar14 = *(ushort *)(pbVar5 + 0x10);
            if (0x8743 < uVar14) goto LAB_0003028c;
LAB_0003022f:
            if (((0x8741 < uVar14) || (uVar14 == 0x2901)) || (uVar14 == 0x8370)) goto LAB_0002fe47;
          }
        }
LAB_0003008b:
        *(undefined1 *)(param_2 + 0x11) = 0;
        goto LAB_0002fe51;
      }
    }
    else {
      if (bVar30 != 1) goto LAB_00030052;
      uVar37 = (uint)*(ushort *)(pbVar5 + iVar25 + 0xa4) + uVar15 * -2;
      if ((int)uVar37 < 1) {
        uVar37 = 1;
      }
      uVar16 = (uint)*(ushort *)(pbVar5 + iVar25 + 0xa6) + uVar15 * -2;
      if ((int)uVar16 < 1) {
        uVar16 = 1;
      }
      uVar15 = (uint)*(ushort *)(pbVar5 + iVar25 + 0xa8) + uVar15 * -2;
      if ((int)uVar15 < 1) {
        uVar15 = 1;
      }
      if ((uVar37 & uVar37 - 1) == 0) {
        uVar16 = uVar16 & uVar16 - 1;
        goto joined_r0x00030100;
      }
    }
LAB_0002fe47:
    *(undefined1 *)(param_2 + 0x11) = 1;
  }
LAB_0002fe51:
  bVar30 = *(byte *)((int)param_2 + 0x39);
  *(byte *)((int)param_2 + 0x39) = bVar30 & 0x9f;
  if ((bVar30 & 0x1f) == 0) {
    ((int (*)())FUN_0002cbbd)(param_1,param_2);
    return 1;
  }
  ((int (*)())FUN_0002d708)();
  if ((char)param_2[0xe] == '\0') {
    return 0;
  }
  if (*(char *)((int)puVar4 + 0x6f) != '\0') {
    if (0x1000 < (uint)(1 << ((byte)puVar4[0x32] & 0x1f))) {
      return 0;
    }
    if (0x1000 < (uint)(1 << (*(byte *)((int)puVar4 + 0x65) & 0x1f))) {
      return 0;
    }
    if (0x100 < (uint)(1 << ((byte)puVar4[0x33] & 0x1f))) {
      return 0;
    }
  }
  uVar15 = (uint)(byte)puVar4[0x2f];
  uVar14 = *puVar4;
  if ((uVar14 & 0x400) == 0) {
    if ((uVar14 & 0x800) != 0) {
      cVar11 = FUN_0000a1e2(param_1,param_2,*(undefined4 *)(puVar4 + 4));
      if (cVar11 == '\0') {
        return 0;
      }
      if (*(char *)((int)puVar4 + 0x6d) != '\0') {
        uVar15 = 1 << ((byte)(DAT_001ecab7)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >> 5);
        *(short *)((int)param_2 + 0x3e) =
             (short)((((uint)puVar4[0x52] + (uint)(byte)puVar4[0x55] * -2) * uVar15 + 0x1f &
                     0xffffffe0) / uVar15);
      }
      *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) & 0xf8;
      goto LAB_0002ff73;
    }
    if ((uVar14 & 0x2000) != 0) {
      cVar11 = ((int (*)())FUN_0002f346)();
      if (cVar11 == '\0') {
        return 0;
      }
      *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) & 0xf8;
      goto LAB_0002ff73;
    }
    if ((((((*(float *)(param_2[0xc] + 4) == FLOAT_001c5b9c) ||
           (sVar3 = *(short *)(param_2[0xc] + 0x1a), sVar3 == -0x7a41)) || (sVar3 == -0x7a42)) &&
         (((char)puVar4[0x36] == '\x01' && ((char)puVar4[0x35] == '\x01')))) &&
        (*(char *)((int)puVar4 + 0x6f) == '\0')) && (*(int *)(puVar4 + uVar15 * 0xc + 0x5a) != 0)) {
      iVar25 = FUN_00009369(puVar4[uVar15 * 0xc + 0x58],puVar4[uVar15 * 0xc + 0x59]);
      uVar14 = puVar4[uVar15 * 0xc + 0x56];
      uVar37 = (uint)uVar14 * iVar25;
      local_2c0 = iVar25 * (uint)(byte)puVar4[uVar15 * 0xc + 0x55] +
                  *(int *)(puVar4 + uVar15 * 0xc + 0x5a);
      if ((char)puVar4[0x37] != '\0') {
        local_2c0 = local_2c0 + (byte)puVar4[uVar15 * 0xc + 0x55] * uVar37;
      }
      uVar16 = local_2c0;
      bVar30 = ((int (*)())FUN_0002d1fb)();
      iVar17 = param_2[0xc];
      if (*(short *)(iVar17 + 0x1a) == -0x7a41) {
        bVar8 = uVar14 < 0x4001;
      }
      else {
        bVar8 = uVar37 <= *(uint *)(param_1 + 0x29d8);
      }
      if ((bVar8 & bVar30 & (local_2c0 & 0x1f) == 0 & (uVar37 & 0x1f) == 0) != 0) {
        bVar30 = *(byte *)(iVar17 + 0x5e);
        local_b8 = 0;
        ((int (*)())FUN_0002eae1)(local_20,&local_30,&local_30,&local_28,&local_24,&local_2c);
        iVar18 = (uint)puVar4[uVar15 * 0xc + 0x52] + (uint)(byte)puVar4[uVar15 * 0xc + 0x55] * -2;
        if (iVar18 < 1) {
          iVar18 = 1;
        }
        uVar15 = (uint)puVar4[uVar15 * 0xc + 0x53] -
                 (uint)(byte)puVar4[uVar15 * 0xc + 0x55] * (uint)*(byte *)(iVar17 + 0x6e);
        uVar20 = 1;
        if (0 < (int)uVar15) {
          uVar20 = uVar15;
        }
        local_2bc = (uVar20 - 1) * uVar37 + (iVar18 + 1U & 0xfffffffe) * iVar25;
        if ((*(byte *)(param_1 + 0x24) & 0x82) == 0) {
          iVar17 = param_2[0xc];
        }
        else {
          iVar17 = param_2[0xc];
          if (((*(byte *)(iVar17 + 0x4b) & 2) == 0) && (uVar20 != 0)) {
            uVar15 = 0;
            do {
              FUN_00009943(param_1,local_2c0,iVar25 * iVar18);
              local_2c0 = local_2c0 + uVar37;
              uVar15 = uVar15 + 1;
            } while (uVar15 < uVar20);
            iVar17 = param_2[0xc];
          }
        }
        local_2b8 = *(uint *)(iVar17 + 0x50);
        if ((uVar16 < local_2b8) ||
           (uVar15 = local_2b8 + *(int *)(iVar17 + 0x4c), uVar15 < uVar16 + local_2bc)) {
          local_2b8 = uVar16;
        }
        else {
          local_2bc = uVar15 - local_2b8;
        }
        if ((*(short *)(iVar17 + 0x1a) == -0x7a41) &&
           ((*(char *)(iVar17 + 0x6d) != '\0' || (iVar18 * iVar25 == uVar37)))) {
          *(short *)((int)param_2 + 0x3e) = (short)(uVar37 >> (local_20[0] & 0x1f));
          cVar11 = FUN_00009eba(param_1,param_2,uVar16,local_2b8,local_2bc);
          if (cVar11 == '\0') {
            return 0;
          }
          *(byte *)(param_2[0xd] + 0x15) = (byte)local_2c & 3;
          uVar14 = (ushort)(-2 << (bVar30 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (bVar30 & 0x1f));
        }
        else {
          uVar15 = (iVar18 << (local_20[0] & 0x1f)) + 0x1fU & 0xffffffe0;
          *(short *)((int)param_2 + 0x3e) = (short)(uVar15 >> (local_20[0] & 0x1f));
          if ((*(byte *)((int)param_2 + 0x39) & 3) != 0) {
            if (local_24 < 3) {
LAB_000316c1:
              local_1a8 = 0;
            }
            else if (local_24 < 5) {
              local_1a8 = 1;
            }
            else {
              if (local_24 != 6) goto LAB_000316c1;
              local_1a8 = 2;
            }
            bVar8 = (iVar18 << (local_20[0] & 0x1f)) >> local_1a8 < 0x2000;
            cVar11 = FUN_00009fb8(param_1,param_2,0x348,uVar15 * uVar20,local_2b8,local_2bc);
            if (cVar11 == '\0') {
              return 0;
            }
            *(undefined1 *)(param_2[0xd] + 0x15) = 0;
            piVar6 = (int *)*param_2;
            bVar13 = *(byte *)(piVar6 + 8);
            *(byte *)(piVar6 + 8) = bVar13 & 0xf6 | bVar8 | 2;
            piVar6[1] = 0x20;
            *piVar6 = 0;
            piVar6[2] = 0;
            *(byte *)((int)piVar6 + 0x1a) = local_20[0];
            *(char *)((int)piVar6 + 0x1b) = (char)local_2c;
            *(short *)(piVar6 + 5) = (short)iVar18;
            *(short *)((int)piVar6 + 0x16) = (short)uVar20;
            *(undefined2 *)(piVar6 + 6) = 1;
            piVar6[3] = uVar15;
            piVar6[4] = uVar37;
            *(byte *)(piVar6 + 8) = bVar13 & 0xf2 | bVar8 | 2;
            piVar22 = piVar6 + 0x280;
            iVar25 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
            puVar36 = &DAT_001ecaa0 + iVar25;
            if (-1 < (char)(DAT_001ecab9)[iVar25]) {
              if (((DAT_001ecab7)[iVar25] & 0x10) == 0) {
                bVar13 = (byte)(DAT_001ecab7)[iVar25] >> 5;
                if (bVar13 == 1) {
                  puVar36 = &DAT_001ecb78;
                }
                else if (bVar13 < 2) {
                  if (bVar13 == 0) {
                    puVar36 = &DAT_001ecb0c;
                  }
                  else {
LAB_0003265f:
                    puVar36 = &DAT_001ecd28;
                  }
                }
                else if (bVar13 == 2) {
                  puVar36 = &DAT_001ecbc0;
                }
                else {
                  if (bVar13 != 3) goto LAB_0003265f;
                  puVar36 = &DAT_001eced8;
                }
              }
              else {
                puVar36 = &DAT_001ecbc0;
              }
            }
            _memcpy(piVar6 + 0x2a0,PTR_DAT_00213295,0x23c);
            piVar6[0x2ab] = 0;
            *(byte *)(piVar6 + 0x306) =
                 *(byte *)(piVar6 + 0x306) & 0xe0 | (byte)(*(ushort *)(puVar36 + 0x1a) >> 6) & 0x1f;
            bVar32 = (byte)puVar36[0x1b] >> 3 & 3;
            bVar13 = *(byte *)((int)piVar6 + 0xc19);
            *(byte *)((int)piVar6 + 0xc19) = bVar13 & 0xfc | bVar32;
            bVar12 = (byte)puVar36[0x1b] >> 3 & 0xc;
            *(byte *)((int)piVar6 + 0xc19) = bVar13 & 0xf0 | bVar32 | bVar12;
            bVar31 = (puVar36[0x1c] & 3) << 4;
            *(byte *)((int)piVar6 + 0xc19) = bVar13 & 0xc0 | bVar32 | bVar12 | bVar31;
            *(byte *)((int)piVar6 + 0xc19) =
                 bVar32 | bVar12 | bVar31 | ((byte)puVar36[0x1c] >> 2) << 6;
            *(byte *)((int)piVar6 + 0xc1a) = *(byte *)((int)piVar6 + 0xc1a) & 0xf0;
            *(byte *)(piVar6 + 0x31c) = (byte)(*(ushort *)(puVar36 + 0x1e) >> 4) & 0x1f;
            bVar13 = *(byte *)((int)piVar6 + 0xc71);
            *(byte *)((int)piVar6 + 0xc71) = bVar13 & 0xfe;
            bVar32 = puVar36[0x1f];
            *(byte *)((int)piVar6 + 0xc71) = bVar13 & 0xf0 | bVar32 & 0xe;
            *(byte *)((int)piVar6 + 0xc71) = bVar13 & 0x80 | bVar32 & 0xe | puVar36[0x1f] & 0x70;
            piVar6[0x31c] = piVar6[0x31c] & 0xfffc7fffU | (uint)(puVar36[0x20] & 7) << 0xf;
            *(byte *)((int)piVar6 + 0xc72) =
                 *(byte *)((int)piVar6 + 0xc72) & 3 | (byte)puVar36[0x20] >> 1 & 0x1c;
            *(byte *)((int)piVar6 + 0xc73) = *(byte *)((int)piVar6 + 0xc73) & 0xf8;
            local_2a0 = piVar22;
            if (bVar8) {
              *piVar22 = 0x1393;
              piVar6[0x281] = 10;
              piVar6[0x282] = 0x5c8;
              piVar6[0x283] = 0x20000;
              piVar6[0x284] = 0x575;
              local_2a0 = piVar6 + 0x286;
              piVar6[0x285] = local_2c;
            }
            piVar27 = piVar6 + (uint)bVar30 * 8 + 0x10;
            *(short *)piVar27 = (short)((int)local_2a0 - (int)piVar22 >> 2);
            *(short *)(piVar27 + 6) =
                 (short)((int)(piVar6 + 0x32f) - (int)piVar22 >> 2) - (short)piVar6[1];
            piVar27[1] = uVar16 - (local_2b8 & 0xfffff000);
            piVar27[2] = 0;
            piVar27[3] = 0;
            piVar27[4] = 0;
            *(undefined2 *)((int)piVar27 + 2) = 1;
            piVar27[5] = 0;
            piVar27[7] = 0;
            iVar25 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
            puVar36 = &DAT_001ecaa0 + iVar25;
            if (-1 < (char)(DAT_001ecab9)[iVar25]) {
              if (((DAT_001ecab7)[iVar25] & 0x10) == 0) {
                bVar13 = (byte)(DAT_001ecab7)[iVar25] >> 5;
                if (bVar13 == 1) {
                  puVar36 = &DAT_001ecb78;
                }
                else if (bVar13 < 2) {
                  if (bVar13 == 0) {
                    puVar36 = &DAT_001ecb0c;
                  }
                  else {
LAB_000319fd:
                    puVar36 = &DAT_001ecd28;
                  }
                }
                else {
                  if (bVar13 == 2) goto LAB_000326c0;
                  if (bVar13 != 3) goto LAB_000319fd;
                  puVar36 = &DAT_001eced8;
                }
              }
              else {
LAB_000326c0:
                puVar36 = &DAT_001ecbc0;
              }
            }
            puVar26 = (undefined4 *)
                      ((int (*)())FUN_0002df3c)(piVar6 + 0x32f,puVar36,uVar37,uVar15,0,
                                   (iVar18 << (local_20[0] & 0x1f)) >> ((byte)puVar36[0x17] >> 5),
                                   uVar20);
            if (bVar8) {
              local_2a0 = (int *)((int (*)())FUN_0002e556)(local_2a0,local_24,uVar37,uVar15,0,0,
                                              uVar20 << 0x10 |
                                              (iVar18 << (local_20[0] & 0x1f)) >> local_1a8);
            }
            *puVar26 = 0x1393;
            puVar26[1] = 10;
            puVar26[2] = 0x5c8;
            puVar26[3] = 0x20000;
            puVar26[4] = 0x1040;
            puVar26[5] = 0;
            if (bVar8) {
              *local_2a0 = 0xd0b;
              local_2a0[1] = 5;
              local_2a0[2] = 0x5c8;
              local_2a0[3] = 0x10000;
              piVar27 = local_2a0 + 5;
              local_2a0[4] = 0x1040;
              local_2a0 = local_2a0 + 6;
              *piVar27 = 0;
            }
            *(uint *)(param_2[0xd] + 0x18) = uVar15 * uVar20;
            *(byte *)(param_2[0xd] + 0x14) = *(byte *)(param_2[0xd] + 0x14) | 2;
            piVar6[2] = ((int)puVar26 + (0x18 - (int)piVar22) >> 2) - piVar6[1];
            *piVar6 = (int)local_2a0 - (int)piVar22 >> 2;
          }
          *(byte *)(param_2[0xd] + 0x14) = *(byte *)(param_2[0xd] + 0x14) | 1;
          uVar14 = (ushort)(1 << (bVar30 & 0x1f));
          *(ushort *)(param_2[0xd] + 0x1c) = *(ushort *)(param_2[0xd] + 0x1c) | uVar14;
          uVar14 = ~uVar14;
          *(ushort *)(param_2[0xd] + 0x28) = *(ushort *)(param_2[0xd] + 0x28) & uVar14;
          *(byte *)(param_2[0xd] + 0x17) = bVar30;
          *(undefined1 *)(param_2[0xd] + 0x34) = 1;
          *(undefined1 *)(param_2[0xd] + 0x35) = 1;
        }
        *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) & 0xf8;
        *(ushort *)(param_2 + 9) = *(ushort *)(param_2 + 9) & uVar14;
        goto LAB_0002ff73;
      }
    }
    if (*(char *)((int)puVar4 + 0x6d) == '\0') {
      cVar11 = ((int (*)())FUN_0002e5e4)();
      if (cVar11 == '\0') {
        iVar25 = param_2[0xc];
        bVar30 = *(byte *)(iVar25 + 0x6c);
        uVar16 = (uint)bVar30;
        bVar13 = *(byte *)(iVar25 + 0x69);
        uVar37 = (uint)bVar13;
        bVar32 = *(byte *)(iVar25 + 0x6b);
        uVar15 = (uint)bVar32;
        local_128 = 0;
        uVar14 = *(ushort *)(iVar25 + 2);
        if (0x1908 < uVar14) {
          if (0x190a < uVar14) {
            if (uVar14 != 0x8049) goto LAB_00030520;
            local_128 = 0x4000;
          }
          local_128 = local_128 | 0x2000;
        }
LAB_00030520:
        local_12c = 2;
        ((int (*)())FUN_0002eae1)(&local_24,&local_30,&local_34,local_20,&local_28,&local_2c);
        uVar20 = local_24;
        iVar17 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
        local_240 = &DAT_001ecaa0 + iVar17;
        if (((DAT_001ecab7)[iVar17] & 0xe0) == 0x80) {
          local_279 = '\0';
          local_248 = 0;
          local_1d5 = false;
          local_1d4 = 5;
LAB_000305f5:
          local_1d0 = 0;
        }
        else {
          bVar12 = (byte)(DAT_001ecab8)[iVar17] >> 2 & 3;
          local_248 = (uint)bVar12;
          if (bVar12 != 0) {
            local_1d4 = 5 - local_248;
          }
          else {
            local_1d4 = 5;
          }
          local_1d5 = bVar12 == 0;
          local_279 = '\x01';
          if ((((DAT_001ecab8)[iVar17] & 0xc) != 8) || (((DAT_001ecab7)[iVar17] & 0xe0) != 0x20))
          goto LAB_000305f5;
          local_1d0 = 1;
        }
        iVar17 = *(byte *)(iVar25 + 0x62) - uVar37;
        if (iVar17 < 0) {
          iVar17 = 0;
        }
        iVar18 = *(byte *)(iVar25 + 0x60) - uVar37;
        if (iVar18 < 0) {
          iVar18 = 0;
        }
        iVar18 = iVar18 - local_30;
        if (iVar18 < 0) {
          iVar18 = 0;
        }
        iVar19 = *(byte *)(iVar25 + 0x61) - uVar37;
        if (iVar19 < 0) {
          iVar19 = 0;
        }
        uVar42 = iVar19 - local_34;
        if ((int)uVar42 < 0) {
          uVar42 = 0;
        }
        local_254 = (byte)iVar18;
        local_298 = (byte)local_24;
        bVar8 = (uint)((1 << (local_254 & 0x1f)) << (local_298 & 0x1f)) <=
                *(uint *)(param_1 + 0x29d8);
        bVar12 = (byte)local_1d4;
        bVar31 = (byte)local_248;
        local_160 = uVar37;
        if (uVar15 < uVar37) {
          local_278 = 0;
          local_26c = 0;
          local_158 = 0;
          local_1c4 = 0;
          local_1c0 = 0;
        }
        else {
          local_184 = aiStack_6c + uVar37;
          local_180 = local_dc + uVar37;
          local_278 = 0;
          local_26c = 0;
          local_158 = 0;
          uVar39 = uVar42;
          local_268 = iVar18;
          local_264 = iVar17;
          do {
            *local_184 = local_158;
            *local_180 = local_26c;
            iVar23 = uVar20 + local_268;
            iVar38 = 1 << ((byte)local_264 & 0x1f);
            iVar19 = 5;
            if (4 < iVar23) {
              iVar19 = iVar23;
            }
            local_158 = local_158 +
                        (1 << ((byte)uVar39 & 0x1f)) * (1 << ((byte)iVar19 & 0x1f)) * iVar38;
            bVar33 = bVar12;
            if (local_1d4 <= iVar23) {
              bVar33 = (byte)iVar23;
            }
            uVar43 = 1 << (bVar33 & 0x1f);
            bVar33 = bVar31;
            if ((int)local_248 <= (int)uVar39) {
              bVar33 = (byte)uVar39;
            }
            uVar35 = 1 << (bVar33 & 0x1f);
            local_26c = local_26c + iVar38 * uVar43 * uVar35;
            if ((uVar43 < (uint)(1 << (bVar12 + 3 & 0x1f))) || (uVar35 < (uint)(1 << bVar31 + 3))) {
              local_278 = local_278 & ~(1 << ((byte)local_160 & 0x1f));
            }
            else {
              local_278 = local_278 | 1 << ((byte)local_160 & 0x1f);
            }
            iVar19 = local_268 + -1;
            if (local_268 < 1) {
              iVar19 = local_268;
            }
            if (0 < (int)uVar39) {
              uVar39 = uVar39 - 1;
            }
            iVar38 = local_264 + -1;
            if (local_264 < 1) {
              iVar38 = local_264;
            }
            local_160 = local_160 + 1;
            local_184 = local_184 + 1;
            local_180 = local_180 + 1;
            local_268 = iVar19;
            local_264 = iVar38;
          } while (local_160 <= uVar15);
          local_1c4 = uVar16 * local_158;
          local_1c0 = uVar16 * local_26c;
        }
        aiStack_6c[local_160] = local_158;
        local_dc[local_160] = local_26c;
        if (bVar8) {
          if (uVar15 < uVar37) {
            local_274 = 0x15;
          }
          else {
            iVar19 = *(byte *)(iVar25 + 0x62) - uVar37;
            iVar38 = 0;
            uVar20 = uVar37;
            do {
              iVar23 = 0;
              if (-1 < iVar19) {
                iVar23 = iVar19;
              }
              iVar38 = iVar38 + (uVar16 * 0x12 << ((byte)iVar23 & 0x1f));
              uVar20 = uVar20 + 1;
              iVar19 = iVar19 + -1;
            } while (uVar20 <= uVar15);
            local_274 = iVar38 + 0x15;
          }
          local_274 = local_274 & 0xfffffff8;
        }
        else {
          local_274 = 0;
        }
        if (uVar15 < uVar37) {
          uVar20 = 0x98;
        }
        else {
          iVar19 = *(byte *)(iVar25 + 0x62) - uVar37;
          iVar38 = 0x91;
          uVar20 = uVar37;
          do {
            iVar23 = 0;
            if (-1 < iVar19) {
              iVar23 = iVar19;
            }
            iVar38 = iVar38 + (uVar16 * 0x2a << ((byte)iVar23 & 0x1f));
            uVar20 = uVar20 + 1;
            iVar19 = iVar19 + -1;
          } while (uVar20 <= uVar15);
          uVar20 = iVar38 + 7;
        }
        cVar11 = FUN_00009a9e(param_1,param_2,local_1c4 + local_274 * 4 + (uVar20 & 0xfffffff8) * 4,
                              local_1c0);
        if (cVar11 == '\0') {
          return 0;
        }
        *(byte *)(param_2[0xd] + 0x15) = (local_279 << (sbyte)local_1d0 & 3U) << 3 | 4;
        piVar6 = (int *)*param_2;
        if ((*(byte *)((int)param_2 + 0x39) & 3) == 0) {
          local_260 = (int *)0x0;
          local_164 = (int *)0x0;
        }
        else {
          *(byte *)(param_2[0xd] + 0x17) = bVar13;
          *(byte *)(param_2[0xd] + 0x34) = bVar30;
          *(byte *)(param_2[0xd] + 0x35) = (bVar32 - bVar13) + '\x01';
          bVar13 = *(byte *)(piVar6 + 8);
          *(byte *)(piVar6 + 8) = bVar13 & 0xf6 | bVar8 | 2;
          piVar6[1] = local_274;
          *piVar6 = 0;
          piVar6[2] = 0;
          bVar32 = (byte)local_24;
          *(byte *)((int)piVar6 + 0x1a) = bVar32;
          *(char *)((int)piVar6 + 0x1b) = (char)local_2c;
          uVar39 = 1 << (local_254 & 0x1f);
          *(short *)(piVar6 + 5) = (short)uVar39;
          local_250 = (byte)uVar42;
          *(short *)((int)piVar6 + 0x16) = (short)(1 << (local_250 & 0x1f));
          local_24c = (byte)iVar17;
          *(short *)(piVar6 + 6) = (short)(1 << (local_24c & 0x1f));
          uVar39 = (uVar39 & 0xffff) << (bVar32 & 0x1f);
          piVar6[3] = uVar39;
          if (uVar39 >> (bVar12 & 0x1f) == 0) {
            piVar6[3] = 1 << (bVar12 & 0x1f);
          }
          uVar39 = (uint)*(ushort *)(piVar6 + 5) << (bVar32 & 0x1f);
          piVar6[4] = uVar39;
          if (uVar39 >> 5 == 0) {
            piVar6[4] = 0x20;
          }
          *(byte *)(piVar6 + 8) = bVar13 & 0xf2 | bVar8 | 2;
          local_260 = piVar6 + 0x280;
          piVar22 = local_260 + piVar6[1];
          _memcpy(piVar22,PTR_DAT_00213295,0x23c);
          local_164 = piVar22 + 0x8f;
          iVar19 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
          local_240 = &DAT_001ecaa0 + iVar19;
          if (-1 < (char)(DAT_001ecab9)[iVar19]) {
            if (((DAT_001ecab7)[iVar19] & 0x10) == 0) {
              bVar13 = (byte)(DAT_001ecab7)[iVar19] >> 5;
              if (bVar13 == 1) {
                local_240 = &DAT_001ecb78;
              }
              else if (bVar13 < 2) {
                if (bVar13 == 0) {
                  local_240 = &DAT_001ecb0c;
                }
                else {
LAB_0003219a:
                  local_240 = &DAT_001ecd28;
                }
              }
              else {
                if (bVar13 == 2) goto LAB_00032408;
                if (bVar13 != 3) goto LAB_0003219a;
                local_240 = &DAT_001eced8;
              }
            }
            else {
LAB_00032408:
              local_240 = &DAT_001ecbc0;
            }
          }
          piVar22[0xb] = 0;
          *(byte *)(piVar22 + 0x66) =
               *(byte *)(piVar22 + 0x66) & 0xe0 | (byte)(*(ushort *)(local_240 + 0x1a) >> 6) & 0x1f;
          bVar32 = (byte)local_240[0x1b] >> 3 & 3;
          bVar13 = *(byte *)((int)piVar22 + 0x199);
          *(byte *)((int)piVar22 + 0x199) = bVar13 & 0xfc | bVar32;
          bVar33 = (byte)local_240[0x1b] >> 3 & 0xc;
          *(byte *)((int)piVar22 + 0x199) = bVar13 & 0xf0 | bVar32 | bVar33;
          bVar34 = (local_240[0x1c] & 3) << 4;
          *(byte *)((int)piVar22 + 0x199) = bVar13 & 0xc0 | bVar32 | bVar33 | bVar34;
          *(byte *)((int)piVar22 + 0x199) =
               bVar32 | bVar33 | bVar34 | ((byte)local_240[0x1c] >> 2) << 6;
          *(byte *)((int)piVar22 + 0x19a) = *(byte *)((int)piVar22 + 0x19a) & 0xf0;
          *(byte *)(piVar22 + 0x7c) = (byte)(*(ushort *)(local_240 + 0x1e) >> 4) & 0x1f;
          bVar13 = *(byte *)((int)piVar22 + 0x1f1);
          *(byte *)((int)piVar22 + 0x1f1) = bVar13 & 0xfe;
          bVar32 = local_240[0x1f];
          *(byte *)((int)piVar22 + 0x1f1) = bVar13 & 0xf0 | bVar32 & 0xe;
          *(byte *)((int)piVar22 + 0x1f1) = bVar13 & 0x80 | bVar32 & 0xe | local_240[0x1f] & 0x70;
          piVar22[0x7c] = piVar22[0x7c] & 0xfffc7fffU | (uint)(local_240[0x20] & 7) << 0xf;
          bVar32 = (byte)local_240[0x20] >> 1 & 0x1c;
          bVar13 = *(byte *)((int)piVar22 + 0x1f2);
          *(byte *)((int)piVar22 + 0x1f2) = bVar13 & 0xc3 | bVar32;
          *(byte *)((int)piVar22 + 0x1f2) = bVar13 & 3 | bVar32 | local_240[0x20] & 0x40;
          *(byte *)((int)piVar22 + 499) = *(byte *)((int)piVar22 + 499) & 0xf8;
          if (bVar8) {
            *local_260 = 0x1393;
            piVar6[0x281] = 10;
            piVar6[0x282] = 0x5c8;
            piVar6[0x283] = 0x20000;
            piVar6[0x284] = 0x575;
            local_260 = piVar6 + 0x286;
            piVar6[0x285] = local_2c;
          }
        }
        if (bVar30 != 0) {
          local_18c = uVar37 << 5;
          local_188 = uVar37 * 0x18;
          local_258 = 0;
          local_25c = (undefined1 *)0x0;
          do {
            local_236 = *(ushort *)(iVar25 + 0x7c + local_258 * 2);
            if (uVar37 <= uVar15) {
              local_1a0 = aiStack_6c + uVar37;
              local_19c = local_18c;
              local_198 = local_188;
              local_194 = local_18c;
              local_190 = local_dc + uVar37;
              local_17c = iVar18;
              local_178 = uVar42;
              local_174 = iVar17;
              local_15c = uVar37;
              do {
                iVar38 = local_17c + local_24;
                iVar19 = 5;
                if (4 < iVar38) {
                  iVar19 = iVar38;
                }
                iVar23 = 1 << ((byte)iVar19 & 0x1f);
                iVar19 = uVar16 * *local_1a0 + (local_1a0[1] - *local_1a0) * local_258 + 0xa00 +
                         (local_274 + (uVar20 & 0xfffffff8)) * 4;
                bVar9 = (byte)((char)param_2[0xe] - 0xcU) < 4;
                bVar30 = (byte)local_174;
                if ((*(byte *)((int)param_2 + 0x39) & 3) == 0) {
                  local_236 = local_236 & *(ushort *)((int)param_2 + local_258 * 2 + 0x24);
                }
                else {
                  local_154 = local_178;
                  local_150 = bVar30;
                  if ((((local_178 != local_248 + 3) && (local_248 <= local_178)) &&
                      (local_174 != 0)) && (local_178 < 0xb)) {
                    iVar21 = local_174;
                    do {
                      iVar21 = iVar21 + -1;
                      local_150 = (byte)iVar21;
                      local_154 = local_154 + 1;
                      if (local_154 == local_174 + local_178) goto LAB_000309cb;
                    } while (local_154 != 0xb);
                    local_154 = 0xb;
                  }
LAB_000309cb:
                  bVar13 = bVar12;
                  if (local_1d4 <= iVar38) {
                    bVar13 = (byte)iVar38;
                  }
                  iVar38 = 1 << (bVar13 & 0x1f);
                  *(short *)((int)piVar6 + local_194 + 0x40) =
                       (short)((int)local_260 - (int)(piVar6 + 0x280) >> 2);
                  *(short *)((int)piVar6 + local_194 + 0x58) =
                       (short)((int)local_164 - (int)(piVar6 + 0x280) >> 2) - (short)piVar6[1];
                  *(int *)((int)piVar6 + local_194 + 0x44) = iVar19;
                  *(uint *)((int)piVar6 + local_194 + 0x48) =
                       uVar16 * *local_190 + (local_190[1] - *local_190) * local_258;
                  *(short *)((int)piVar6 + local_194 + 0x42) = (short)(1 << (local_150 & 0x1f));
                  *(int *)((int)piVar6 + local_194 + 0x4c) = iVar23 << ((byte)local_154 & 0x1f);
                  bVar13 = (byte)local_154;
                  if ((int)local_154 <= (int)local_248) {
                    bVar13 = bVar31;
                  }
                  *(int *)((int)piVar6 + local_194 + 0x50) = (1 << (bVar13 & 0x1f)) * iVar38;
                  uVar39 = local_248;
                  if ((int)local_248 <= (int)local_178) {
                    uVar39 = local_178;
                  }
                  *(int *)((int)piVar6 + local_194 + 0x54) = iVar38 << ((byte)uVar39 & 0x1f);
                  *(int *)((int)piVar6 + local_194 + 0x5c) = (int)piVar6 + iVar19;
                  if (local_28 < 3) {
LAB_00030af4:
                    local_224 = 0;
                  }
                  else if (local_28 < 5) {
                    local_224 = 1;
                  }
                  else {
                    if (local_28 != 6) goto LAB_00030af4;
                    local_224 = 2;
                  }
                  uVar39 = 1 << (local_150 & 0x1f);
                  if (uVar39 != 0) {
                    iVar40 = 1 << ((byte)local_154 & 0x1f);
                    iVar21 = 1 << ((byte)local_17c & 0x1f);
                    uVar43 = 0;
                    do {
                      if ((local_279 == '\0') || (local_1d5)) {
                        uVar35 = 0;
                      }
                      else {
                        uVar35 = 1;
                      }
                      uVar35 = (uVar35 | local_1d0 * 2) * 2 |
                               local_278 >> ((byte)local_15c & 0x1f) & 1;
                      local_164 = (int *)((int (*)())FUN_0002df3c)(local_164,local_240,iVar23,iVar38,uVar35,
                                                      (iVar21 << ((byte)local_24 & 0x1f)) >>
                                                      ((byte)local_240[0x17] >> 5),iVar40);
                      if (bVar8) {
                        local_260 = (int *)((int (*)())FUN_0002e556)(local_260,local_28,iVar23,iVar38,uVar35,0,
                                                        (iVar21 << ((byte)local_24 & 0x1f)) >>
                                                        local_224 | iVar40 << 0x10);
                      }
                      uVar43 = uVar43 + 1;
                    } while (uVar43 < uVar39);
                  }
                }
                if ((local_236 >> ((byte)local_15c & 0x1f) & 1) != 0) {
                  iVar38 = iVar25 + 0xa0 + local_198;
                  bVar44 = *(short *)(iVar38 + 0x12) == 0;
                  iVar21 = FUN_00009369(*(undefined2 *)(iVar38 + 0x10),*(short *)(iVar38 + 0x12));
                  uVar39 = (uint)*(ushort *)(iVar38 + 0xc);
                  local_148 = iVar21 * uVar39;
                  local_314 = *(undefined1 **)(iVar38 + 0x14);
                  if ((*(char *)(iVar38 + 10) != '\0') && (!bVar44)) {
                    if (*(char *)(iVar25 + 0x6e) == '\0') {
                      iVar40 = 1;
                    }
                    else {
                      iVar40 = uVar39 + 1;
                      if (*(char *)(iVar25 + 0x6f) != '\0') {
                        iVar40 = iVar40 + uVar39 * *(ushort *)(iVar38 + 0xe);
                      }
                    }
                    local_314 = local_314 + iVar21 * iVar40;
                  }
                  iVar21 = *(byte *)(iVar25 + 0x60) - local_15c;
                  if (iVar21 < 0) {
                    iVar21 = 0;
                  }
                  local_120 = 1 << ((byte)iVar21 & 0x1f);
                  iVar21 = *(byte *)(iVar25 + 0x61) - local_15c;
                  if (iVar21 < 0) {
                    iVar21 = 0;
                  }
                  iVar40 = *(byte *)(iVar25 + 0x62) - local_15c;
                  if (iVar40 < 0) {
                    iVar40 = 0;
                  }
                  local_11c = 1 << ((char)iVar21 + (char)iVar40 & 0x1fU);
                  local_14c = local_314;
                  _glgConvertType(*(undefined2 *)(iVar38 + 0x10),*(undefined2 *)(iVar38 + 0x12),
                                  local_144,local_140);
                  local_138 = iVar23;
                  if (bVar9) {
                    local_138 = local_120 << 2;
                  }
                  local_13c = (undefined1 *)(iVar19 + *param_2);
                  local_124 = 0x7ffff;
                  uVar14 = *(short *)(iVar38 + 0x10) + 0xe6fa;
                  if (uVar14 < 5) {
                    local_124 = 0x7dfff;
                    if ((1 << ((byte)uVar14 & 0x1f) & 0x19U) == 0) {
                      local_124 = 0x7ffff;
                    }
                  }
                  local_118 = 0;
                  local_114 = 0;
                  if (((!bVar44) && (bVar9)) && (local_25c == (undefined1 *)0x0)) {
                    local_25c = _valloc(((1 << (*(char *)(iVar25 + 100) + 2U & 0x1f)) + 0x1fU &
                                        0xffffffe0) <<
                                        (*(char *)(iVar25 + 0x66) + *(char *)(iVar25 + 0x65) & 0x1fU
                                        ));
                  }
                  sVar7 = 1 << ((byte)local_17c + (char)local_178 + bVar30 + (char)local_24 & 0x1f);
                  iVar23 = FUN_00009369(*(undefined2 *)(iVar38 + 0x10),
                                        *(undefined2 *)(iVar38 + 0x12));
                  uVar43 = local_120;
                  uVar39 = local_148;
                  local_2fc = local_120;
                  bVar45 = local_148 == iVar23 * local_120;
                  bVar30 = ((int (*)())FUN_0002d1fb)();
                  puVar24 = local_13c;
                  if ((((bVar45 & bVar30) == 0) || (((uint)local_14c & 0x1f) != 0)) ||
                     ((uVar39 & 0x1f) != 0)) {
                    if ((*(int *)(iVar38 + 0x10) == 0x14011907) &&
                       ((local_130 == 0 || (local_130 == 0x11)))) {
                      puVar41 = local_14c;
                      for (puVar29 = local_13c; local_13c = puVar24,
                          puVar29 < local_13c + uVar43 * 4 + (local_11c - 1) * local_138;
                          puVar29 = puVar29 + local_138 + uVar43 * -4) {
                        puVar1 = puVar29 + uVar43 * 4;
                        for (; puVar29 < puVar1; puVar29 = puVar29 + 4) {
                          *puVar29 = *puVar41;
                          puVar29[1] = puVar41[1];
                          puVar29[2] = puVar41[2];
                          puVar41 = puVar41 + 3;
                          puVar29[3] = 0xff;
                        }
                        puVar41 = puVar41 + uVar39 + uVar43 * -3;
                      }
                    }
                    else if (bVar44) {
                      local_13c = puVar24;
                      if (bVar9) {
                        uVar39 = ((int (*)())FUN_0002df06)(1);
                        if (uVar39 < 0x20) {
                          local_1dc = local_14c;
                          if (local_11c != 0) {
                            local_1e0 = 0;
                            puVar24 = local_13c;
                            do {
                              _memcpy((void *)((uint)(puVar24 + 0x1f) & 0xffffffe0),local_1dc,uVar39
                                     );
                              local_1dc = local_1dc + uVar39;
                              puVar24 = (undefined1 *)
                                        ((int)((uint)(puVar24 + 0x1f) & 0xffffffe0) + uVar39);
                              local_1e0 = local_1e0 + 4;
                            } while (local_1e0 < local_11c);
                          }
                        }
                        else {
                          _memcpy(local_13c,local_14c,sVar7);
                        }
                      }
                    }
                    else if (bVar9) {
                      uVar14 = *(ushort *)(iVar38 + 0x10);
                      uVar39 = (uint)uVar14;
                      if (((uVar43 == *(ushort *)(iVar38 + 0xc)) &&
                          ((*(short *)(iVar38 + 0x12) == 0x1401 ||
                           (*(short *)(iVar38 + 0x12) == -0x7c99)))) &&
                         ((uVar39 - 0x1907 < 2 || ((uVar14 == 0x80e1 || (uVar14 == 0x80e0)))))) {
                        local_200 = local_14c;
                      }
                      else {
                        local_13c = local_25c;
                        _glgProcessPixels(0,&local_14c);
                        local_200 = local_25c;
                        uVar39 = 0x1908;
                        local_2fc = local_120;
                      }
                      uVar43 = local_11c;
                      if ((char)param_2[0xe] == '\x0f') {
                        if ((uVar39 == 0x1908) || (uVar39 == 0x80e1)) {
                          local_1f0 = 4;
                        }
                        else {
                          local_1f0 = 3;
                        }
                        local_13c = puVar24;
                        if (0 < (int)local_11c) {
                          local_1f8 = 0;
                          do {
                            if (0 < (int)local_2fc) {
                              iVar38 = 0;
                              do {
                                ((int (*)())FUN_0002e16b)(local_1f0 * local_2fc);
                                ((int (*)())FUN_0002e16b)(local_1f0 * local_2fc);
                                iVar38 = iVar38 + 4;
                              } while (iVar38 < (int)local_2fc);
                            }
                            local_1f8 = local_1f8 + 4;
                          } while (local_1f8 < (int)uVar43);
                        }
                      }
                      else {
                        local_13c = puVar24;
                        FUN_00019e30(local_2fc,local_11c,uVar39,(char)param_2[0xe],local_200,puVar24
                                    );
                      }
                    }
                    else {
                      _glgProcessPixels(0,&local_14c);
                    }
                  }
                  else {
                    _memcpy(local_13c,local_14c,sVar7);
                  }
                  if ((*(byte *)(param_1 + 0x24) & 0x82) != 0) {
                    FUN_00009943(param_1,*param_2 + iVar19,
                                 (uint)*(ushort *)((int)piVar6 + local_19c + 0x42) *
                                 *(int *)((int)piVar6 + local_19c + 0x4c));
                  }
                }
                iVar19 = local_17c + -1;
                if (local_17c < 1) {
                  iVar19 = local_17c;
                }
                uVar39 = local_178 - 1;
                if ((int)local_178 < 1) {
                  uVar39 = local_178;
                }
                iVar38 = local_174 + -1;
                if (local_174 < 1) {
                  iVar38 = local_174;
                }
                local_15c = local_15c + 1;
                local_1a0 = local_1a0 + 1;
                local_19c = local_19c + 0x20;
                local_198 = local_198 + 0x18;
                local_194 = local_194 + 0x20;
                local_190 = local_190 + 1;
                local_17c = iVar19;
                local_178 = uVar39;
                local_174 = iVar38;
              } while (local_15c <= uVar15);
            }
            puVar2 = (ushort *)(param_2[0xd] + 0x1c + local_258 * 2);
            *puVar2 = *puVar2 | local_236;
            puVar2 = (ushort *)(param_2[0xd] + 0x28 + local_258 * 2);
            *puVar2 = *puVar2 & ~local_236;
            puVar2 = (ushort *)((int)param_2 + local_258 * 2 + 0x24);
            *puVar2 = *puVar2 & ~local_236;
            local_258 = local_258 + 1;
            local_18c = local_18c + 0x1a0;
            local_188 = local_188 + 0x168;
          } while (local_258 < uVar16);
          if (local_25c != (undefined1 *)0x0) {
            _free(local_25c);
          }
        }
        bVar30 = *(byte *)((int)param_2 + 0x39);
        if ((bVar30 & 3) != 0) {
          *local_164 = 0x1393;
          local_164[1] = 10;
          local_164[2] = 0x5c8;
          local_164[3] = 0x20000;
          local_164[4] = 0x1040;
          local_164[5] = 0;
          if (bVar8) {
            *local_260 = 0xd0b;
            local_260[1] = 5;
            local_260[2] = 0x5c8;
            local_260[3] = 0x10000;
            piVar22 = local_260 + 5;
            local_260[4] = 0x1040;
            local_260 = local_260 + 6;
            *piVar22 = 0;
          }
          piVar6[2] = ((int)local_164 + (0x18 - (int)(piVar6 + 0x280)) >> 2) - piVar6[1];
          *piVar6 = (int)local_260 - (int)(piVar6 + 0x280) >> 2;
          bVar30 = *(byte *)((int)param_2 + 0x39);
        }
        *(byte *)((int)param_2 + 0x39) = bVar30 & 0xf8;
        goto LAB_0002ff73;
      }
      if ((char)param_2[0x11] != '\0') {
        return 0;
      }
    }
    cVar11 = ((int (*)())FUN_0002f346)();
    if (cVar11 == '\0') {
      return 0;
    }
    goto LAB_0002ff73;
  }
  uVar14 = puVar4[6];
  if (uVar14 == 0x405) {
LAB_000303d9:
    uVar28 = 0;
  }
  else if (uVar14 < 0x406) {
    if (uVar14 == 0x402) goto LAB_000303d9;
    if (uVar14 == 0x403) {
      uVar28 = 2;
    }
    else {
      if (uVar14 != 0x401) goto LAB_00030148;
      uVar28 = 3;
    }
  }
  else if (uVar14 == 0x40a) {
    uVar28 = 8;
  }
  else if (uVar14 == 0x1100) {
    uVar28 = 0x11;
  }
  else if (uVar14 == 0x409) {
    uVar28 = 7;
  }
  else {
LAB_00030148:
    uVar28 = 1;
  }
  cVar11 = FUN_0000a0c2(param_1,param_2,*(undefined4 *)(puVar4 + 4),uVar28,(char)puVar4[0x36]);
  if (cVar11 == '\0') {
    return 0;
  }
  if (*(char *)((int)puVar4 + 0x6d) == '\0') {
    uVar14 = puVar4[0x52];
    if ((uVar14 < 0x21) && (puVar4[0x53] < 0x21)) goto LAB_0003038f;
  }
  else {
    uVar14 = puVar4[0x52];
LAB_0003038f:
    uVar15 = 1 << ((byte)(DAT_001ecab7)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >> 5);
    *(short *)((int)param_2 + 0x3e) =
         (short)((((uint)uVar14 + (uint)(byte)puVar4[0x55] * -2) * uVar15 + 0xff & 0xffffff00) /
                uVar15);
  }
  *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) & 0xf8;
LAB_0002ff73:
  if ((*(char *)((int)puVar4 + 0x6d) == '\0') || (puVar4[0x52] < 0x1001)) {
    bVar8 = false;
  }
  else {
    bVar8 = true;
  }
  if ((*(char *)((int)puVar4 + 0x6d) == '\0') || (puVar4[0x53] < 0x1001)) {
    bVar9 = false;
  }
  else {
    bVar9 = true;
  }
  if (bVar8) {
    if (bVar9) {
      return 0;
    }
    *(byte *)((int)param_2 + 0xc9) = *(byte *)((int)param_2 + 0xc9) & 0xfc | 1;
    uVar14 = puVar4[0x52];
    uVar15 = (int)(uint)uVar14 >> 1;
    uVar10 = (ushort)uVar15 & 0xfe00;
    *(ushort *)(param_2 + 0x34) = uVar10 + 2;
    *(ushort *)((int)param_2 + 0xd2) = uVar14 - uVar10;
    *(ushort *)(param_2 + 0x35) = uVar10;
    param_2[0x33] = param_2[0x33] & 0xc0000000U | uVar15 & 0x3ffffe00;
  }
  else if (bVar9) {
    *(byte *)((int)param_2 + 0xc9) = *(byte *)((int)param_2 + 0xc9) & 0xfc | 2;
    uVar14 = puVar4[0x53];
    uVar15 = (int)(uint)uVar14 >> 1;
    uVar37 = uVar15 & 0xffffffc0;
    sVar3 = (short)uVar37;
    *(short *)(param_2 + 0x34) = sVar3 + 1;
    *(ushort *)((int)param_2 + 0xd2) = uVar14 - sVar3;
    *(short *)(param_2 + 0x35) = sVar3;
    if ((*(byte *)(param_2[0xc] + 1) & 4) == 0) {
      param_2[0x33] =
           param_2[0x33] & 0xc0000000U |
           (*(ushort *)((int)param_2 + 0x3e) * uVar37 <<
           ((byte)(DAT_001ecab7)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >> 5)) >> 5;
    }
    else {
      param_2[0x33] = param_2[0x33] & 0xc0000000U | uVar15 & 0x3fffffc0;
    }
  }
  else {
    *(byte *)((int)param_2 + 0xc9) = *(byte *)((int)param_2 + 0xc9) & 0xfc;
  }
  ((int (*)())FUN_0002bd2c)(param_1,param_2);
  return 1;
}

/* FUN_000326f2 @ 0x326f2 (66 bytes) */
int FUN_000326f2(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  char cVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  cVar2 = ((int (*)())FUN_0002fdb4)(uVar1,param_2);
  if (cVar2 != '\0') {
    return 1;
  }
  _gldDeleteTexture(uVar1,param_2);
  return 0;
}

/* FUN_00032734 @ 0x32734 (5401 bytes) */
int FUN_00032734(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int *piVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  uint *puVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  uint uVar19;
  uint uVar20;
  int *piVar21;
  uint uVar22;
  float fVar23;
  float fVar24;
  double dVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  int local_d0;
  uint local_98;
  uint local_94;
  uint local_84;
  int local_80;
  int local_7c;
  int local_78;
  int *local_70;
  int *local_6c;
  int local_60;
  byte local_5c;
  int local_58;
  byte local_54;
  int local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  uint local_40;
  uint *local_24;
  int *local_20;
  
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  iVar4 = param_2[0xc];
  uVar20 = (uint)*(byte *)(iVar4 + 0x5e);
  bVar2 = *(byte *)(iVar4 + 0x5f);
  if ((*(byte *)(iVar4 + 0x4a) & 1) != 0) {
    bVar2 = *(byte *)(iVar4 + 0x6b);
  }
  local_98 = (uint)bVar2;
  uVar22 = local_98 - uVar20;
  cVar6 = ((int (*)())FUN_0002e5e4)();
  if (cVar6 != '\0') {
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return 0;
  }
  if ((uVar22 == 0) || (*(char *)(iVar4 + 0x6d) != '\0')) goto LAB_000327ab;
  local_94 = uVar20 + 1;
  iVar7 = ((int (*)())FUN_0002eb84)(uVar20,1);
  if ((iVar7 == 0) || (-1 < *(char *)(iVar7 + 0x19))) {
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return 0;
  }
  if (((*(byte *)((int)param_2 + 0x39) & 7) != 0) &&
     (cVar6 = ((int (*)())FUN_0002fdb4)(param_1,param_2), cVar6 == '\0')) {
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return 0;
  }
  iVar12 = *(byte *)(iVar4 + 0x60) - uVar20;
  if (iVar12 < 0) {
    iVar12 = 0;
  }
  iVar12 = 1 << ((byte)iVar12 & 0x1f);
  iVar13 = *(byte *)(iVar4 + 0x61) - uVar20;
  if (iVar13 < 0) {
    iVar13 = 0;
  }
  iVar13 = 1 << ((byte)iVar13 & 0x1f);
  local_84 = *(byte *)(iVar4 + 0x62) - uVar20;
  if ((int)local_84 < 0) {
    local_84 = 0;
  }
  local_80 = iVar12 >> 1;
  if (local_80 < 1) {
    local_80 = 1;
  }
  local_7c = iVar13 >> 1;
  if (local_7c < 1) {
    local_7c = 1;
  }
  iVar14 = local_84 - 1;
  if (iVar14 < 0) {
    iVar14 = 0;
  }
  local_78 = 1 << ((byte)iVar14 & 0x1f);
  if (*(char *)(iVar4 + 0x6f) == '\0') {
    local_4c = uVar22;
    if (*(char *)(iVar4 + 0x6c) == '\x06') {
      iVar14 = uVar22 * 2;
      iVar8 = uVar22 * 0x2c + -0x16;
      local_48 = uVar22 * 0x10000;
      local_40 = uVar22;
    }
    else {
      iVar8 = uVar22 * 0x1e + -0x12;
      iVar14 = uVar22 + 1;
      local_48 = 0x10000;
      local_40 = 1;
    }
  }
  else {
    if ((int)uVar22 < 1) {
      iVar8 = 0;
      iVar14 = 1;
      local_4c = 0;
    }
    else {
      uVar19 = 0;
      local_4c = 0;
      do {
        iVar14 = local_78 >> ((byte)uVar19 & 0x1f);
        if (iVar14 < 1) {
          iVar14 = 1;
        }
        local_4c = local_4c + iVar14;
        uVar19 = uVar19 + 1;
      } while (uVar22 != uVar19);
      iVar8 = local_4c * 0x28;
      iVar14 = local_4c + 1;
    }
    iVar8 = iVar8 + -0x12;
    local_48 = 0x10000;
    local_40 = 1;
  }
  iVar15 = param_1 + 0x240;
  uVar9 = (**(code **)(param_1 + 0x2998))(iVar15,iVar8 + 0x340 + iVar14);
  *(undefined4 *)(param_1 + 0x298c) = uVar9;
  puVar10 = (undefined4 *)((int (*)())FUN_0002e3ab)();
  puVar5 = *(uint **)(param_1 + 0x1d8);
  *puVar5 = *puVar5 | (int)puVar10 - (int)puVar5 >> 2;
  *(undefined4 **)(param_1 + 0x1d8) = puVar10;
  *puVar10 = 0x37000000;
  uVar19 = param_3 << 0x10;
  puVar10[2] = local_94 * 0x100 | uVar19 | uVar22;
  puVar10[3] = local_4c | local_48;
  local_6c = puVar10 + 4 + local_4c;
  piVar1 = local_6c + local_40;
  _memcpy(piVar1,PTR_DAT_002131cd,0x2f4);
  local_20 = piVar1 + 0xbd;
  if (*(char *)(iVar4 + 0x6f) != '\0') {
    piVar1[0x21] = 0x1002;
    piVar1[0x22] = 0;
    piVar1[0x25] = 0x825;
    piVar1[0x26] = 3;
    piVar1[0x27] = 0x82d;
    piVar1[0x28] = 5;
    piVar1[0x29] = 0x854;
    piVar1[0x2a] = 0x26020001;
    piVar1[0x2b] = 0x878;
    piVar1[0x2c] = -0x57704f8;
    *(byte *)(piVar1 + 0x92) = *(byte *)(piVar1 + 0x92) & 0x80 | 3;
    piVar1[0x98] = piVar1[0x98] & 0xfffc0fffU | 0x2000;
  }
  *(byte *)((int)piVar1 + 0x289) = *(byte *)((int)piVar1 + 0x289) & 0x81 | 0x34;
  piVar1[0xa2] = piVar1[0xa2] & 0xfffe7fffU | (uint)(~-(local_84 == 0) & 2) << 0xf;
  *(ushort *)(piVar1 + 0xa4) = *(ushort *)(piVar1 + 0xa4) & 0xe007 | 0x1f00;
  *(ushort *)(piVar1 + 0xa6) = *(ushort *)(piVar1 + 0xa6) & 0xf800 | (short)iVar12 - 1U & 0x7ff;
  piVar1[0xa6] = piVar1[0xa6] & 0xffc007ffU | (iVar13 - 1U & 0x7ff) << 0xb;
  *(ushort *)((int)piVar1 + 0x29a) =
       *(ushort *)((int)piVar1 + 0x29a) & 0xfc3f | (ushort)((local_84 & 0xf) << 6);
  *(byte *)((int)piVar1 + 0x29b) = *(byte *)((int)piVar1 + 0x29b) & 0x43 | ((byte)uVar22 & 0xf) << 2
  ;
  *(byte *)(piVar1 + 0xa8) =
       *(byte *)(piVar1 + 0xa8) & 0xe0 | (byte)(*(ushort *)(iVar7 + 0x1e) >> 4) & 0x1f;
  *(byte *)((int)piVar1 + 0x2a1) =
       *(byte *)((int)piVar1 + 0x2a1) & 0x8f | *(byte *)(iVar7 + 0x1f) & 0x70;
  piVar1[0xa8] = piVar1[0xa8] & 0xfffc7fffU | (uint)(*(byte *)(iVar7 + 0x20) & 7) << 0xf;
  *(byte *)((int)piVar1 + 0x2a2) =
       *(byte *)((int)piVar1 + 0x2a2) & 0xe3 | *(byte *)(iVar7 + 0x20) >> 1 & 0x1c;
  *(byte *)((int)piVar1 + 0x2a1) =
       *(byte *)((int)piVar1 + 0x2a1) & 0xf1 | *(byte *)(iVar7 + 0x1f) & 0xe;
  bVar16 = *(byte *)(iVar7 + 0x1b) >> 3 & 3;
  bVar2 = *(byte *)((int)piVar1 + 0x229);
  *(byte *)((int)piVar1 + 0x229) = bVar2 & 0xfc | bVar16;
  bVar17 = *(byte *)(iVar7 + 0x1b) >> 3 & 0xc;
  *(byte *)((int)piVar1 + 0x229) = bVar2 & 0xf0 | bVar16 | bVar17;
  bVar18 = (*(byte *)(iVar7 + 0x1c) & 3) << 4;
  *(byte *)((int)piVar1 + 0x229) = bVar2 & 0xc0 | bVar16 | bVar17 | bVar18;
  *(byte *)((int)piVar1 + 0x229) = bVar16 | bVar17 | bVar18 | (*(byte *)(iVar7 + 0x1c) >> 2) << 6;
  *(byte *)(piVar1 + 0x8a) =
       *(byte *)(piVar1 + 0x8a) & 0xe0 | (byte)(*(ushort *)(iVar7 + 0x1a) >> 6) & 0x1f;
  sVar3 = *(short *)(iVar4 + 2);
  if (((sVar3 != 0x1908) && (sVar3 != 0x1906)) && (sVar3 != 0x190a)) {
    piVar1[0x56] = piVar1[0x56] & 0xfffe3fffU | 0x18000;
  }
  if ((param_2[0xd] == 0) || ((*(byte *)(param_2[0xd] + 0x15) & 0x18) == 0)) {
    iVar14 = 0x20;
  }
  else {
    iVar14 = (int)(0x20 / (longlong)
                          (1 << ((byte)(DAT_001ecab8)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >> 2 &
                                3)));
  }
  iVar14 = iVar14 >> (*(byte *)(iVar7 + 0x17) >> 5);
  if ((*(byte *)(iVar4 + 1) & 4) == 0) {
    local_60 = *param_2 + 0x40 + (param_3 * 0xd + local_94) * 0x20;
  }
  else {
    local_60 = 0;
  }
  puVar10[4] = (int)piVar1 + (0x268 - (int)puVar10) >> 2;
  local_70 = puVar10 + 5;
  if (local_60 == 0) {
    piVar1[0x9a] = local_94 | uVar19;
  }
  else {
    piVar1[0x9a] = *(int *)(local_60 + 8);
  }
  *local_6c = (int)piVar1 + (0x280 - (int)puVar10) >> 2;
  local_6c = local_6c + 1;
  if (local_60 == 0) {
    piVar1[0xa0] = uVar20 | uVar19;
  }
  else {
    piVar1[0xa0] = *(int *)((param_3 * 0xd + uVar20) * 0x20 + *param_2 + 0x48);
    iVar8 = param_2[0xd];
    if ((iVar8 == 0) || ((*(byte *)(iVar8 + 0x15) & 4) == 0)) {
LAB_00032dcf:
      iVar11 = 0;
    }
    else {
      local_5c = (char)local_94 - *(char *)(param_2[0xc] + 0x69);
      if ((*(byte *)(iVar8 + 0x15) & 0x18) == 0) {
        local_58 = 1;
        local_d0 = 0x100;
      }
      else {
        local_58 = 1 << ((byte)(DAT_001ecab8)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >> 2 & 3);
        local_d0 = (int)(0x20 / (longlong)local_58) << 3;
      }
      if ((*(int *)(*param_2 + 0xc) >> (local_5c & 0x1f) < local_d0) ||
         ((int)(uint)*(ushort *)(*param_2 + 0x16) >> (local_5c & 0x1f) < local_58 * 8))
      goto LAB_00032dcf;
      iVar11 = 1;
    }
    if (iVar8 == 0) {
      uVar20 = 0;
    }
    else {
      uVar20 = (*(byte *)(iVar8 + 0x15) >> 3 & 3) << 0x11;
    }
    piVar1[0x9c] = uVar20 | iVar11 << 0x10 | local_80 + -1 + iVar14 & -iVar14 & 0x3ffeU |
                   (*(byte *)(iVar7 + 0x1a) >> 2 & 0xf) << 0x15;
  }
  piVar1[0xb3] = local_80 - 1U & 0x1fff | (local_7c - 1U & 0x1fff) << 0xd;
  if ((*(byte *)(iVar7 + 0x21) & 2) != 0) {
    piVar1[0x1e] = 0;
  }
  fVar27 = (float)(DOUBLE_001cf388 / (double)iVar12);
  fVar26 = (float)(DOUBLE_001cf388 / (double)iVar13);
  local_44 = (param_3 * 0xd + local_94) * 0x20;
  fVar28 = fVar26 + FLOAT_001c5ba4;
  fVar23 = FLOAT_001c5ba4 + fVar27;
  while( true ) {
    local_44 = local_44 + 0x20;
    if (*(char *)(iVar4 + 0x6f) == '\0') {
      *local_20 = 0x31080;
      local_20[1] = (int)fVar27;
      local_20[2] = (int)(fVar26 + FLOAT_001c5ba4);
      local_20[3] = (int)fVar23;
      local_20[4] = (int)fVar26;
      local_20[5] = 0x1087;
      local_20[6] = (int)((float)local_80 * FLOAT_001c5bf4) << 0x10 |
                    (int)(FLOAT_001c5bf4 * (float)local_7c);
      local_20[7] = -0x3ffccb00;
      local_20[8] = (int)((unsigned char *)0x00010031);
      fVar24 = FLOAT_001c5bd4;
      local_20[9] = (int)(((float)local_80 + 0.0) * FLOAT_001c5bd4);
      local_20[10] = (int)(((float)local_7c + 0.0) * fVar24);
      local_20[0xb] = 0;
      local_20 = local_20 + 0xc;
    }
    else {
      dVar25 = DOUBLE_001cf330 / (double)local_78;
      fVar24 = (float)((double)(float)dVar25 * DOUBLE_001cf368 +
                      (double)(float)((DOUBLE_001cf330 / (double)(1 << ((byte)local_84 & 0x1f))) *
                                     DOUBLE_001cf388));
      if (0 < local_78) {
        iVar12 = 0;
        piVar21 = local_20;
        do {
          while( true ) {
            *piVar21 = -0x3febcb00;
            piVar21[1] = 0x4003d;
            piVar21[2] = 0;
            piVar21[3] = 0;
            piVar21[4] = (int)fVar27;
            piVar21[5] = (int)fVar26;
            piVar21[6] = (int)fVar24;
            piVar21[7] = (int)(float)local_80;
            piVar21[8] = 0;
            piVar21[9] = (int)fVar23;
            piVar21[10] = (int)fVar26;
            piVar21[0xb] = (int)fVar24;
            piVar21[0xc] = (int)(float)local_80;
            piVar21[0xd] = (int)(float)local_7c;
            piVar21[0xe] = (int)fVar23;
            piVar21[0xf] = (int)fVar28;
            piVar21[0x10] = (int)fVar24;
            piVar21[0x11] = 0;
            piVar21[0x12] = (int)(float)local_7c;
            piVar21[0x13] = (int)fVar27;
            piVar21[0x14] = (int)fVar28;
            piVar21[0x15] = (int)fVar24;
            local_20 = piVar21 + 0x16;
            fVar24 = fVar24 + (float)dVar25;
            iVar12 = iVar12 + 1;
            if (local_78 <= iVar12) break;
            piVar21[0x16] = 0x1393;
            piVar21[0x17] = 10;
            piVar21[0x18] = 0x138a;
            *local_70 = (int)piVar21 + (100 - (int)puVar10) >> 2;
            local_70 = local_70 + 1;
            if (local_60 == 0) {
              piVar21 = piVar21 + 0x1a;
            }
            else {
              piVar21[0x19] = iVar12 * *(int *)(local_60 + 0x14) + *(int *)(local_60 + 8);
              piVar21 = piVar21 + 0x1a;
            }
          }
          piVar21 = local_20;
        } while (local_78 != iVar12);
      }
    }
    if ((int)local_98 <= (int)local_94) break;
    *local_20 = 0x1393;
    local_20[1] = 10;
    local_20[2] = 0x5c8;
    local_20[3] = 0x20000;
    local_20[4] = 0x1040;
    local_20[5] = 0;
    piVar21 = local_20 + 6;
    if (*(char *)(iVar4 + 0x6c) == '\x06') {
      local_20[6] = 0x1150;
      *local_6c = (int)local_20 + (0x1c - (int)puVar10) >> 2;
      local_6c = local_6c + 1;
      if (local_60 == 0) {
        local_20[7] = local_94 | uVar19;
      }
      else {
        local_20[7] = *(int *)(local_60 + 8);
      }
      local_20[8] = 0x1120;
      piVar21 = local_20 + 10;
      local_20[9] = piVar1[0xa6] & 0xfc000000U | local_80 - 1U & 0x7ff |
                    (local_7c - 1U & 0x7ff) << 0xb;
      *(byte *)((int)local_20 + 0x27) = *(byte *)((int)local_20 + 0x27) & 0x7f;
      local_20[9] = local_20[9] & 0xc3ffffff;
    }
    local_94 = local_94 + 1;
    uVar20 = local_84 - 1;
    local_84 = 0;
    if (-1 < (int)uVar20) {
      local_84 = uVar20;
    }
    local_80 = local_80 >> 1;
    if (local_80 < 1) {
      local_80 = 1;
    }
    local_7c = local_7c >> 1;
    if (local_7c < 1) {
      local_7c = 1;
    }
    iVar12 = local_78 >> 1;
    local_78 = 1;
    if (0 < iVar12) {
      local_78 = iVar12;
    }
    if ((*(byte *)(iVar4 + 1) & 4) == 0) {
      local_60 = *param_2 + 0x40 + local_44;
      *piVar21 = 0x138a;
      *local_70 = (int)piVar21 + (4 - (int)puVar10) >> 2;
      if (local_60 == 0) goto LAB_000333f9;
      piVar21[1] = *(int *)(local_60 + 8);
      piVar21[2] = 0x138e;
    }
    else {
      local_60 = 0;
      *piVar21 = 0x138a;
      *local_70 = (int)piVar21 + (4 - (int)puVar10) >> 2;
LAB_000333f9:
      piVar21[1] = uVar19 | local_94;
      piVar21[2] = 0x138e;
    }
    if (local_60 != 0) {
      local_24 = (uint *)(piVar21 + 3);
      iVar12 = param_2[0xd];
      if ((iVar12 == 0) || ((*(byte *)(iVar12 + 0x15) & 4) == 0)) {
LAB_000333c2:
        iVar13 = 0;
      }
      else {
        local_54 = (char)local_94 - *(char *)(param_2[0xc] + 0x69);
        if ((*(byte *)(iVar12 + 0x15) & 0x18) == 0) {
          local_50 = 1;
          local_d0 = 0x100;
        }
        else {
          local_50 = 1 << ((byte)(DAT_001ecab8)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >> 2 & 3);
          local_d0 = (int)(0x20 / (longlong)local_50) << 3;
        }
        if ((*(int *)(*param_2 + 0xc) >> (local_54 & 0x1f) < local_d0) ||
           ((int)(uint)*(ushort *)(*param_2 + 0x16) >> (local_54 & 0x1f) < local_50 * 8))
        goto LAB_000333c2;
        iVar13 = 1;
      }
      if (iVar12 == 0) {
        uVar20 = 0;
      }
      else {
        uVar20 = (*(byte *)(iVar12 + 0x15) >> 3 & 3) << 0x11;
      }
      *local_24 = uVar20 | iVar13 << 0x10 | iVar14 + -1 + local_80 & -iVar14 & 0x3ffeU |
                  (*(byte *)(iVar7 + 0x1a) >> 2 & 0xf) << 0x15;
    }
    local_70 = local_70 + 1;
    local_20 = piVar21 + 4;
  }
  puVar10[1] = (int)local_20 - (int)puVar10 >> 2;
  puVar5 = *(uint **)(param_1 + 0x1d8);
  *puVar5 = *puVar5 | (int)local_20 - (int)puVar5 >> 2;
  *(int **)(param_1 + 0x1d8) = local_20;
  *local_20 = 0x33000000;
  local_20[1] = 0;
  local_20[2] = 0x1393;
  local_20[3] = 10;
  local_20[4] = 0x13c6;
  local_20[5] = 3;
  local_20[6] = 0x5c8;
  local_20[7] = 0x20000;
  local_20[8] = 0x10ea;
  local_20[9] = *(int *)(param_1 + 0x1cfc);
  local_20[10] = 0x10fa;
  local_20[0xb] = *(int *)(param_1 + 0x1da0);
  local_20[0xc] = -0x3ffff000;
  local_20[0xe] = 0x11004;
  local_20[0xf] = *(int *)(param_1 + 0x1ca8);
  local_20[0x10] = *(int *)(param_1 + 0x1cac);
  local_20[0x11] = 0x1008;
  local_20[0x12] = *(int *)(param_1 + 0x1ca0);
  local_20[0x13] = 0x10e9;
  local_20[0x14] = *(int *)(param_1 + 0x1d20);
  local_20[0x15] = 0x13c7;
  local_20[0x16] = *(int *)(param_1 + 0x1cf0);
  local_20[0x17] = 0x13c1;
  local_20[0x18] = *(int *)(param_1 + 0x1ce4);
  local_20[0x19] = 0x850;
  local_20[0x1a] = *(int *)(param_1 + 0x1dc0);
  local_20[0x1b] = 0x887;
  local_20[0x1c] = *(int *)(param_1 + 0x1db4);
  local_20[0xbd] = 0x82c;
  local_20[0xbe] = *(int *)(param_1 + 0x1dc4);
  local_20[0x1d] = 0x10ae;
  local_20[0x1e] = *(int *)(param_1 + 0x1d70);
  local_20[0x1f] = 0x1394;
  local_20[0x20] = *(int *)(param_1 + 0x1d30);
  local_20[0x21] = 0x1380;
  local_20[0x22] = 0;
  local_20[0x23] = 0x1002;
  local_20[0x24] = *(int *)(param_1 + 0x1d90);
  local_20[0x24] = *(int *)(param_1 + 0x1d90);
  local_20[0x25] = 0x824;
  local_20[0x26] = *(int *)(param_1 + 0x1ddc);
  local_20[0x27] = 0x825;
  local_20[0x28] = *(int *)(param_1 + 0x1de0);
  local_20[0x29] = 0x82d;
  local_20[0x2a] = *(int *)(param_1 + 0x26cc);
  local_20[0x2b] = 0x854;
  local_20[0x2c] = **(int **)(param_1 + 0x2680);
  local_20[0x2d] = 0x878;
  local_20[0x2e] = **(int **)(param_1 + 0x2684);
  local_20[0x2f] = (int)&switchdataD_000013c0;
  local_20[0x30] = *(int *)(param_1 + 0x1ce0);
  local_20[0x31] = 0x12f0;
  local_20[0x32] = *(int *)(param_1 + 0x1d2c);
  if (((DAT_001ecaba)[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24] & 1) == 0) {
    *(byte *)(local_20 + 0x32) = *(byte *)(local_20 + 0x32) & 0xfe;
  }
  local_20[0x33] = 0x12f5;
  local_20[0x34] = *(int *)(param_1 + 0x1c8c);
  if (((DAT_001ecaba)[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24] & 1) == 0) {
    *(byte *)((int)local_20 + 0xd1) = *(byte *)((int)local_20 + 0xd1) & 0xf7;
  }
  local_20[0x35] = 0x10a2;
  local_20[0x36] = *(int *)(param_1 + 0x1d7c);
  local_20[0x37] = 0x1381;
  local_20[0x38] = *(int *)(param_1 + 0x1cc0);
  if (((DAT_001ecaba)[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24] & 2) == 0) {
    *(byte *)(local_20 + 0x38) = *(byte *)(local_20 + 0x38) & 0xfc;
  }
  local_20[0x39] = 0x109e;
  local_20[0x3a] = *(int *)(param_1 + 0x1d6c);
  local_20[0x3b] = 0x1096;
  local_20[0x3a] = *(int *)(param_1 + 0x1df8);
  local_20[0x3d] = 0x1041;
  local_20[0x3e] = *(int *)(param_1 + 0x29f0);
  local_20[0x3f] = 0x1046;
  local_20[0x40] = *(int *)(param_1 + 0x1dfc);
  local_20[0x41] = 0x1094;
  local_20[0x42] = 0;
  local_20[0x43] = 0x1095;
  local_20[0x45] = 0x1095;
  local_20[0x47] = 0x1095;
  local_20[0x49] = 0x1095;
  local_20[0x4b] = 0x1095;
  local_20[0x4d] = 0x1095;
  local_20[0x4f] = 0x1095;
  local_20[0x51] = 0x1095;
  local_20[0x53] = 0x1095;
  local_20[0x55] = 0x1095;
  local_20[0x57] = 0x1095;
  local_20[0x59] = 0x1095;
  local_20[0x5b] = -0x3fddf000;
  local_20[0x7f] = 0x1180;
  local_20[0x80] = 2;
  local_20[0x81] = 0x1189;
  local_20[0x83] = 0x1181;
  local_20[0x85] = 0x118d;
  local_20[0x87] = 0x118e;
  local_20[0x89] = 0x118c;
  local_20[0x8b] = 0x11a9;
  local_20[0x8c] = *(int *)(param_1 + 0x257c);
  local_20[0x8d] = 0x11aa;
  local_20[0x8e] = *(int *)(param_1 + 0x2580);
  local_20[0x8f] = 0x11ab;
  local_20[0x90] = *(int *)(param_1 + 0x2584);
  local_20[0x91] = 0x11ac;
  local_20[0x92] = *(int *)(param_1 + 0x2588);
  local_20[0x93] = 0x10c0;
  local_20[0x94] = *(int *)(param_1 + 0x216c);
  local_20[0x95] = 0x10c1;
  local_20[0x97] = 0x10c8;
  local_20[0x99] = 0x101d;
  local_20[0x9a] = *(int *)(param_1 + 0x2128);
  local_20[0x9b] = 0x138a;
  local_20[0x9c] = 0;
  local_20[0x9d] = 0x138e;
  local_20[0x9e] = 0;
  local_20[0x9f] = 0x1040;
  local_20[0xa0] = 0;
  local_20[0xa1] = 0x1150;
  local_20[0xa2] = 0;
  local_20[0xa3] = 0x1100;
  local_20[0xa4] = *(int *)(param_1 + 0x1f1c);
  local_20[0xa5] = 0x1110;
  local_20[0xa6] = *(int *)(param_1 + 0x1f5c);
  local_20[0xa7] = 0x1120;
  local_20[0xa8] = *(int *)(param_1 + 0x1f9c);
  local_20[0xa9] = 0x1130;
  local_20[0xaa] = *(int *)(param_1 + 0x1fdc);
  local_20[0xab] = 0x1140;
  local_20[0xac] = *(int *)(param_1 + 0x201c);
  local_20[0xad] = 0x10f4;
  local_20[0xae] = 0xaaaa;
  local_20[0xaf] = 0x1383;
  local_20[0xb0] = *(int *)(param_1 + 0x1d34);
  local_20[0xb1] = 0x1386;
  local_20[0xb2] = *(int *)(param_1 + 0x1d38);
  local_20[0xb3] = 0x110f8;
  local_20[0xb4] = *(int *)(param_1 + 0x1d98);
  local_20[0xb5] = *(int *)(param_1 + 0x1d50);
  local_20[0xb6] = 0x1087;
  local_20[0xb7] = *(int *)(param_1 + 0x1f0c);
  local_20[0xb8] = 0x31080;
  local_20[0xb9] = *(int *)(param_1 + 0x1efc);
  local_20[0xba] = *(int *)(param_1 + 0x1f04);
  local_20[0xbb] = *(int *)(param_1 + 0x1f00);
  local_20[0xbc] = *(int *)(param_1 + 0x1f08);
  FUN_0004acbc(local_20 + 2,iVar15);
  uVar9 = ((int (*)())FUN_0002e415)();
  *(undefined4 *)(param_1 + 0x298c) = uVar9;
  (**(code **)(param_1 + 0x299c))(iVar15,uVar9);
LAB_000327ab:
  _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
  return 1;
}

/* FUN_00033c4d @ 0x33c4d (6532 bytes) */
int FUN_00033c4d(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  int *param_2;
  int param_3;
  uint param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
  int param_9;
  int param_10;
  int param_11;
{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  uint *puVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  uint uVar18;
  uint uVar19;
  uint *puVar20;
  uint uVar21;
  bool bVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  int local_134;
  int local_130;
  uint local_108;
  uint local_104;
  int local_100;
  byte local_f8;
  int local_f4;
  uint local_ec;
  uint local_e4;
  uint local_e0;
  float local_dc;
  float local_cc;
  float local_c4;
  byte local_bf;
  byte local_be;
  byte local_bd;
  ushort local_bc;
  ushort local_ac;
  float local_98;
  float local_94;
  float local_90;
  undefined4 local_8c;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  int local_74;
  uint local_70;
  uint local_6c;
  int local_68;
  uint local_64;
  uint local_50;
  uint local_4c;
  int local_48;
  float local_40;
  uint local_3c;
  
  iVar7 = param_1 + 0x240;
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  iVar4 = param_2[0xc];
  iVar8 = ((int (*)())FUN_0002eb84)(param_4,0);
  if ((iVar8 == 0) || (-1 < *(char *)(iVar8 + 0x19))) {
LAB_00033cae:
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return 0;
  }
  iVar9 = FUN_000092a0(*(undefined2 *)(*(int *)(param_1 + 0x10) + 0x2db8),
                       *(undefined4 *)(param_1 + 0x154));
  bVar22 = *(short *)(iVar4 + 2) == 0x1902;
  if (bVar22) {
    if ((*(int *)(param_1 + 0x150) == 0) && (cVar6 = FUN_00017bd8(param_1,iVar9), cVar6 != '\0')) {
      _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
      return 0;
    }
    if ((*(uint *)(param_1 + 0x154) & 0x30000) == 0) goto LAB_00033cae;
  }
  iVar10 = param_3 * 0x168 + param_4 * 0x18 + param_2[0xc];
  local_108 = (uint)*(ushort *)(iVar10 + 0xa4);
  local_104 = (uint)*(ushort *)(iVar10 + 0xa6);
  if (local_108 == 0) {
    local_108 = 1;
    fVar25 = FLOAT_001c5ba4;
  }
  else {
    fVar25 = (float)local_108;
  }
  if (local_104 == 0) {
    local_104 = 1;
    local_dc = FLOAT_001c5ba4;
  }
  else {
    local_dc = (float)local_104;
  }
  fVar27 = (float)param_8;
  fVar28 = (float)param_9;
  fVar24 = (float)(param_8 + param_10);
  if ((float)*(int *)(param_1 + 0x15c) <= (float)(param_8 + param_10)) {
    fVar24 = (float)*(int *)(param_1 + 0x15c);
  }
  fVar30 = (float)(param_9 + param_11);
  if ((float)*(int *)(param_1 + 0x160) <= (float)(param_9 + param_11)) {
    fVar30 = (float)*(int *)(param_1 + 0x160);
  }
  fVar23 = ((float)(~-(uint)(fVar27 <= 0.0) & (uint)fVar27) - fVar27) + (float)param_5;
  fVar29 = ((float)(~-(uint)(fVar28 <= 0.0) & (uint)fVar28) - fVar28) + (float)param_6;
  fVar27 = (float)param_5 + (fVar24 - fVar27);
  fVar24 = (float)param_6 + (fVar30 - fVar28);
  if (fVar23 <= 0.0) {
    fVar23 = 0.0;
  }
  if (fVar29 <= 0.0) {
    fVar29 = 0.0;
  }
  if (fVar25 <= fVar27) {
    fVar27 = fVar25;
  }
  if (local_dc <= fVar24) {
    fVar24 = local_dc;
  }
  fVar25 = (float)(param_8 - param_5);
  local_cc = (float)(param_9 - param_6);
  fVar30 = fVar23 + fVar25;
  fVar28 = fVar27 + fVar25;
  if ((fVar27 <= fVar23) || (fVar24 <= fVar29)) {
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return 1;
  }
  if (((*(byte *)((int)param_2 + 0x39) & 7) != 0) &&
     (cVar6 = ((int (*)())FUN_0002fdb4)(param_1,param_2), cVar6 == '\0')) goto LAB_00033cae;
  if ((*(int *)(param_1 + 0x150) == 0) && (cVar6 = FUN_00017bd8(param_1,iVar9), cVar6 != '\0')) {
    FUN_00020d0f(param_1,0,iVar9,0,(int)fVar30,(int)(fVar29 + local_cc),(int)(fVar28 - fVar30),
                 (int)((fVar24 + local_cc) - (fVar29 + local_cc)));
  }
  if (bVar22) {
    local_100 = 1000;
    local_74 = 4000;
  }
  else {
    local_100 = 0;
    local_74 = 0;
  }
  if (*(char *)(param_1 + 0x2b7c) == '\0') {
    local_c4 = FLOAT_001c5ba4;
  }
  else {
    local_cc = (float)*(int *)(param_1 + 0x160) - local_cc;
    local_c4 = FLOAT_001c5bdc;
  }
  if (*(int *)(param_1 + 0x150) == 0) {
    local_8c = CONCAT22(*(undefined2 *)(param_1 + 0x11c),*(undefined2 *)(param_1 + 0x120));
  }
  else {
    local_8c = CONCAT22(*(undefined2 *)(param_1 + 0x15c),*(undefined2 *)(param_1 + 0x160));
  }
  if (((*(unsigned short *)((unsigned char *)&(local_8c) + 2)) < 0x1001) && ((ushort)local_8c < 0x1001)) {
    local_bf = 0;
    local_be = 0;
    local_bd = 0;
    local_bc = 0;
    local_ac = 0;
    local_94 = 0.0;
    local_98 = 0.0;
    local_40 = 0.0;
    local_90 = 0.0;
    iVar10 = 0xc;
    local_70 = 0;
  }
  else {
    fVar26 = local_cc + fVar29 * local_c4;
    local_40 = local_cc + fVar24 * local_c4;
    local_94 = fVar26;
    if (local_40 < fVar26) {
      local_94 = local_40;
      local_40 = fVar26;
    }
    local_98 = fVar30;
    local_90 = fVar28;
    if (fVar28 < fVar30) {
      local_98 = fVar28;
      local_90 = fVar30;
    }
    uVar18 = (uint)((*(unsigned short *)((unsigned char *)&(local_8c) + 2)) >> 9) * 0x200;
    uVar13 = (int)local_98 - 1;
    if ((int)uVar13 < 0) {
      uVar13 = (int)local_98 + 0x1fe;
    }
    uVar13 = uVar13 & 0xfffffe00;
    if ((int)uVar13 < 0) {
      local_bc = 0;
    }
    else {
      if ((int)uVar13 <= (int)uVar18) {
        uVar18 = uVar13;
      }
      local_bc = (ushort)uVar18;
    }
    if ((ushort)local_8c < 0x41) {
      uVar13 = 0x40;
    }
    else {
      uVar18 = local_8c >> 6 & 0x3ff;
      uVar13 = uVar18 * 0x40;
      if ((int)((local_8c & 0xffff) + uVar18 * -0x40) < 0x40) {
        uVar13 = uVar13 - 0x40;
      }
    }
    local_50 = local_8c & 0xffff;
    uVar18 = (int)local_94 - 1;
    if ((int)uVar18 < 0) {
      uVar18 = (int)local_94 + 0x3e;
    }
    uVar18 = uVar18 & 0xffffffc0;
    if ((int)uVar18 < 0) {
      local_ac = 0;
    }
    else {
      if ((int)uVar18 <= (int)uVar13) {
        uVar13 = uVar18;
      }
      local_ac = (ushort)uVar13;
    }
    if (local_bc < 0x200) {
      uVar13 = 0x200;
    }
    else {
      uVar13 = (uint)local_bc;
    }
    uVar18 = (*(unsigned short *)((unsigned char *)&(local_8c) + 2)) - 1;
    if ((int)uVar18 < 0) {
      uVar18 = (*(unsigned short *)((unsigned char *)&(local_8c) + 2)) + 0x1fe;
    }
    uVar19 = (uint)local_90;
    if ((0.0 < local_90) && ((float)(int)uVar19 < local_90)) {
      uVar19 = uVar19 + 1;
    }
    uVar14 = uVar18 & 0xfffffe00;
    if ((int)uVar19 <= (int)(uVar18 & 0xfffffe00)) {
      uVar14 = uVar19;
    }
    if ((int)uVar13 < (int)uVar14) {
      local_be = (byte)((int)((uVar14 - uVar13) + 0xbff) / 0xc00);
    }
    else {
      local_be = 1;
    }
    if (local_ac < 0x40) {
      uVar13 = 0x40;
    }
    else {
      uVar13 = (uint)local_ac;
    }
    uVar18 = local_50 - 1;
    if ((int)uVar18 < 0) {
      uVar18 = local_50 + 0x3e;
    }
    uVar19 = (uint)local_40;
    if ((0.0 < local_40) && ((float)(int)uVar19 < local_40)) {
      uVar19 = uVar19 + 1;
    }
    uVar14 = uVar18 & 0xffffffc0;
    if ((int)uVar19 <= (int)(uVar18 & 0xffffffc0)) {
      uVar14 = uVar19;
    }
    if ((int)uVar13 < (int)uVar14) {
      local_bd = (byte)((int)((uVar14 - uVar13) + 0xf7f) / 0xf80);
    }
    else {
      local_bd = 1;
    }
    local_bf = local_bd * local_be;
    local_70 = (uint)local_bf;
    iVar10 = local_70 << 4;
  }
  local_50 = local_8c & 0xffff;
  local_6c = (uint)(*(unsigned short *)((unsigned char *)&(local_8c) + 2));
  uVar11 = (**(code **)(param_1 + 0x2998))
                     (iVar7,(-(uint)!bVar22 & 0xfffffff5) + 0x34e + iVar10 + local_100);
  *(undefined4 *)(param_1 + 0x298c) = uVar11;
  iVar10 = ((int (*)())FUN_0002e3ab)();
  puVar12 = (undefined4 *)(iVar10 + local_74);
  puVar20 = *(uint **)(param_1 + 0x1d8);
  *puVar20 = *puVar20 | (int)puVar12 - (int)puVar20 >> 2;
  *(undefined4 **)(param_1 + 0x1d8) = puVar12;
  *puVar12 = 0x32000000;
  puVar12[2] = local_100;
  if (bVar22) {
    if ((*(byte *)(param_1 + 0x155) & 0x20) == 0) {
LAB_000340f3:
      uVar11 = 4;
    }
    else if (iVar9 == 7) {
      uVar11 = 10;
    }
    else {
      if (iVar9 != 8) goto LAB_000340f3;
      uVar11 = 0xb;
    }
    puVar12[3] = uVar11;
  }
  else {
    puVar12[3] = iVar9;
  }
  puVar12[4] = param_3 << 0x10 | param_4;
  puVar12[5] = local_70;
  puVar12[6] = local_8c << 0x10 | local_6c;
  _memcpy(puVar12 + 7,PTR_DAT_002131cd,0x2f4);
  puVar20 = puVar12 + 0xc4;
  bVar15 = *(byte *)(iVar8 + 0x1b) >> 3 & 3;
  bVar1 = *(byte *)((int)puVar12 + 0x245);
  *(byte *)((int)puVar12 + 0x245) = bVar1 & 0xfc | bVar15;
  bVar16 = *(byte *)(iVar8 + 0x1b) >> 3 & 0xc;
  *(byte *)((int)puVar12 + 0x245) = bVar1 & 0xf0 | bVar15 | bVar16;
  bVar17 = (*(byte *)(iVar8 + 0x1c) & 3) << 4;
  *(byte *)((int)puVar12 + 0x245) = bVar1 & 0xc0 | bVar15 | bVar16 | bVar17;
  *(byte *)((int)puVar12 + 0x245) = bVar15 | bVar16 | bVar17 | (*(byte *)(iVar8 + 0x1c) >> 2) << 6;
  *(byte *)(puVar12 + 0x91) =
       *(byte *)(puVar12 + 0x91) & 0xe0 | (byte)(*(ushort *)(iVar8 + 0x1a) >> 6) & 0x1f;
  sVar2 = *(short *)(iVar4 + 2);
  if ((((sVar2 != 0x1908) && (sVar2 != 0x1906)) && (sVar2 != 0x190a)) && (sVar2 != 0x1902)) {
    puVar12[0x5d] = puVar12[0x5d] & 0xfffe3fff | 0x18000;
  }
  iVar9 = param_2[0xd];
  if ((iVar9 == 0) || ((*(byte *)(iVar9 + 0x15) & 0x18) == 0)) {
    local_134 = 0x20;
  }
  else {
    local_134 = (int)(0x20 / (longlong)
                             (1 << ((byte)(DAT_001ecab8)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >>
                                    2 & 3)));
  }
  local_134 = local_134 >> (*(byte *)(iVar8 + 0x17) >> 5);
  if ((iVar9 == 0) || (*(char *)(iVar9 + 0x16) != '\x06')) {
    iVar9 = (param_3 * 0xd + param_4) * 0x20;
    local_68 = param_7 * *(int *)(*param_2 + 0x54 + iVar9) + *(int *)(*param_2 + 0x48 + iVar9);
    local_64 = 0;
  }
  else {
    local_64 = (uint)(*(byte *)(iVar8 + 0x18) & 3) << 0x13;
    local_68 = 0;
  }
  if (*(char *)(param_2[0xc] + 0x6d) == '\0') {
    uVar13 = (local_108 - 1) + local_134 & -local_134;
  }
  else {
    uVar13 = (uint)*(ushort *)((int)param_2 + 0x3e);
  }
  puVar12[0xa1] = local_68;
  iVar9 = param_2[0xd];
  if ((iVar9 != 0) && ((*(byte *)(iVar9 + 0x15) & 4) != 0)) {
    local_f8 = (char)param_4 - *(char *)(param_2[0xc] + 0x69);
    if ((*(byte *)(iVar9 + 0x15) & 0x18) == 0) {
      local_f4 = 1;
      local_130 = 0x100;
    }
    else {
      local_f4 = 1 << ((byte)(DAT_001ecab8)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >> 2 & 3);
      local_130 = (int)(0x20 / (longlong)local_f4) << 3;
    }
    if ((local_130 <= *(int *)(*param_2 + 0xc) >> (local_f8 & 0x1f)) &&
       (local_f4 * 8 <= (int)(uint)*(ushort *)(*param_2 + 0x16) >> (local_f8 & 0x1f))) {
      iVar10 = 1;
      goto LAB_00034389;
    }
  }
  iVar10 = 0;
LAB_00034389:
  if (iVar9 == 0) {
    uVar18 = 0;
  }
  else {
    uVar18 = (*(byte *)(iVar9 + 0x15) >> 3 & 3) << 0x11;
  }
  puVar12[0xa3] =
       uVar18 | iVar10 << 0x10 | uVar13 & 0x3ffe | local_64 |
       (*(byte *)(iVar8 + 0x1a) >> 2 & 0xf) << 0x15;
  puVar12[0xba] = local_108 - 1 & 0x1fff | (local_104 - 1 & 0x1fff) << 0xd;
  if ((*(byte *)(iVar8 + 0x21) & 2) != 0) {
    puVar12[0x25] = 0;
  }
  if (local_bf == 0) {
    fVar25 = 0.0;
    if ((*(unsigned short *)((unsigned char *)&(local_8c) + 2)) != 0) {
      fVar25 = FLOAT_001c5ba4 / (float)local_6c;
    }
    fVar26 = 0.0;
    if ((ushort)local_8c != 0) {
      fVar26 = FLOAT_001c5ba4 / (float)local_50;
    }
    *puVar20 = 0x31080;
    puVar12[0xc5] = fVar30 * fVar25;
    puVar12[0xc6] = (fVar24 * local_c4 + local_cc) * fVar26;
    puVar12[199] = fVar25 * fVar28;
    puVar12[200] = fVar26 * (fVar29 * local_c4 + local_cc);
    puVar12[0xc9] = 0x1087;
    puVar12[0xca] =
         (int)((fVar27 - fVar23) * FLOAT_001c5bf4) << 0x10 |
         (int)((fVar24 - fVar29) * FLOAT_001c5bf4);
    puVar12[0xcb] = 0xc0033500;
    puVar12[0xcc] = ((unsigned char *)0x00010031);
    fVar25 = FLOAT_001c5bd4;
    puVar12[0xcd] = (fVar23 + fVar27) * FLOAT_001c5bd4;
    puVar12[0xce] = fVar25 * (fVar29 + fVar24);
    puVar12[0xcf] = 0;
    puVar20 = puVar12 + 0xd0;
  }
  else {
    if ((local_c4 != 0.0) || (NAN(local_c4))) {
      local_84 = FLOAT_001c5ba4 / local_c4;
    }
    else {
      local_84 = 0.0;
    }
    fVar25 = (float)((uint)fVar25 ^ DAT_001c6130);
    fVar24 = local_84 * (float)((uint)local_cc ^ DAT_001c6130);
    uVar13 = (uint)local_bd;
    if (uVar13 != 0) {
      uVar19 = (uint)local_be;
      uVar18 = (uint)local_ac;
      local_3c = local_50 - uVar18;
      local_ec = 0;
      local_48 = 0;
      do {
        if (uVar19 != 0) {
          uVar14 = (uint)local_bc;
          iVar8 = uVar18 + local_48;
          local_4c = local_6c - uVar14;
          uVar21 = 0;
          do {
            *puVar20 = uVar14;
            puVar20[1] = uVar18 + local_48;
            if ((int)local_6c < (int)(uVar14 + 0x1000)) {
              local_e4 = local_4c;
              if (iVar8 + 0x1000 <= (int)local_50) goto LAB_00035095;
LAB_000352fa:
              puVar20[2] = local_e4;
              puVar20[3] = local_3c;
              local_e0 = local_3c;
            }
            else {
              local_e4 = 0x1000;
              if ((int)local_50 < iVar8 + 0x1000) goto LAB_000352fa;
LAB_00035095:
              local_e0 = 0x1000;
              puVar20[2] = local_e4;
              puVar20[3] = 0x1000;
            }
            fVar27 = local_98;
            if (uVar21 != 0) {
              fVar27 = (float)(int)(uVar14 + 0x200);
            }
            fVar28 = local_94;
            if (local_ec != 0) {
              fVar28 = (float)(iVar8 + 0x40);
            }
            fVar30 = local_90;
            if (uVar21 != uVar19 - 1) {
              fVar30 = (float)(int)(uVar14 + 0xe00);
            }
            fVar23 = local_40;
            if (local_ec != uVar13 - 1) {
              fVar23 = (float)(iVar8 + 0xfc0);
            }
            fVar29 = local_98;
            if (local_98 <= fVar27) {
              fVar29 = fVar27;
            }
            local_7c = local_94;
            if (local_94 <= fVar28) {
              local_7c = fVar28;
            }
            local_80 = local_90;
            if (fVar30 <= local_90) {
              local_80 = fVar30;
            }
            fVar27 = local_40;
            if (fVar23 <= local_40) {
              fVar27 = fVar23;
            }
            local_78 = fVar25 + fVar29;
            fVar31 = local_80 + fVar25;
            fVar26 = local_84 * local_7c + fVar24;
            fVar23 = local_84 * fVar27 + fVar24;
            fVar28 = fVar27;
            fVar30 = fVar26;
            if (fVar23 < fVar26) {
              fVar28 = local_7c;
              fVar30 = fVar23;
              fVar23 = fVar26;
              local_7c = fVar27;
            }
            fVar27 = fVar31;
            fVar26 = fVar29;
            if (fVar31 < local_78) {
              fVar27 = local_78;
              fVar26 = local_80;
              local_80 = fVar29;
              local_78 = fVar31;
            }
            fVar29 = 0.0;
            if (local_e4 != 0) {
              fVar29 = FLOAT_001c5ba4 / (float)(int)local_e4;
            }
            fVar31 = 0.0;
            if (local_e0 != 0) {
              fVar31 = FLOAT_001c5ba4 / (float)(int)local_e0;
            }
            puVar20[4] = 0x31080;
            puVar20[5] = (uint)((fVar26 - (float)(int)uVar14) * fVar29);
            puVar20[6] = (uint)((fVar28 - (float)iVar8) * fVar31);
            puVar20[7] = (uint)(fVar29 * (local_80 - (float)(int)uVar14));
            puVar20[8] = (uint)(fVar31 * (local_7c - (float)iVar8));
            puVar20[9] = 0x1087;
            puVar20[10] = (int)((fVar27 - local_78) * FLOAT_001c5bf4) << 0x10 |
                          (int)((fVar23 - fVar30) * FLOAT_001c5bf4);
            puVar20[0xb] = 0xc0033500;
            puVar20[0xc] = (uint)((unsigned char *)0x00010031);
            puVar20[0xd] = (uint)((fVar27 + local_78) * FLOAT_001c5bd4);
            puVar20[0xe] = (uint)((fVar23 + fVar30) * FLOAT_001c5bd4);
            puVar20[0xf] = 0;
            puVar20 = puVar20 + 0x10;
            uVar21 = uVar21 + 1;
            uVar14 = uVar14 + 0xc00;
            local_4c = local_4c - 0xc00;
          } while (uVar21 != uVar19);
        }
        local_ec = local_ec + 1;
        local_48 = local_48 + 0xf80;
        local_3c = local_3c - 0xf80;
      } while (local_ec != uVar13);
    }
  }
  puVar12[1] = (int)puVar20 - (int)puVar12 >> 2;
  puVar5 = *(uint **)(param_1 + 0x1d8);
  *puVar5 = *puVar5 | (int)puVar20 - (int)puVar5 >> 2;
  *(uint **)(param_1 + 0x1d8) = puVar20;
  *puVar20 = 0x33000000;
  if (bVar22) {
    uVar13 = 2;
  }
  else {
    uVar13 = 0;
  }
  puVar20[1] = uVar13;
  puVar20[2] = 0x1393;
  puVar20[3] = 10;
  puVar20[4] = 0x13c6;
  puVar20[5] = 3;
  puVar20[6] = 0x5c8;
  puVar20[7] = 0x20000;
  puVar20[8] = 0x10ea;
  puVar20[9] = *(uint *)(param_1 + 0x1cfc);
  puVar20[10] = 0x10fa;
  puVar20[0xb] = *(uint *)(param_1 + 0x1da0);
  puVar20[0xc] = 0xc0001000;
  puVar20[0xe] = 0x11004;
  puVar20[0xf] = *(uint *)(param_1 + 0x1ca8);
  puVar20[0x10] = *(uint *)(param_1 + 0x1cac);
  puVar20[0x11] = 0x1008;
  puVar20[0x12] = *(uint *)(param_1 + 0x1ca0);
  puVar20[0x13] = 0x10e9;
  puVar20[0x14] = *(uint *)(param_1 + 0x1d20);
  puVar20[0x15] = 0x13c7;
  puVar20[0x16] = *(uint *)(param_1 + 0x1cf0);
  puVar20[0x17] = 0x13c1;
  puVar20[0x18] = *(uint *)(param_1 + 0x1ce4);
  puVar20[0x19] = 0x850;
  puVar20[0x1a] = *(uint *)(param_1 + 0x1dc0);
  puVar20[0x1b] = 0x887;
  puVar20[0x1c] = *(uint *)(param_1 + 0x1db4);
  puVar20[0xbd] = 0x82c;
  puVar20[0xbe] = *(uint *)(param_1 + 0x1dc4);
  puVar20[0x1d] = 0x10ae;
  puVar20[0x1e] = *(uint *)(param_1 + 0x1d70);
  puVar20[0x1f] = 0x1394;
  puVar20[0x20] = *(uint *)(param_1 + 0x1d30);
  puVar20[0x21] = 0x1380;
  puVar20[0x22] = 0;
  puVar20[0x23] = 0x1002;
  puVar20[0x24] = *(uint *)(param_1 + 0x1d90);
  puVar20[0x24] = *(uint *)(param_1 + 0x1d90);
  puVar20[0x25] = 0x824;
  puVar20[0x26] = *(uint *)(param_1 + 0x1ddc);
  puVar20[0x27] = 0x825;
  puVar20[0x28] = *(uint *)(param_1 + 0x1de0);
  puVar20[0x29] = 0x82d;
  puVar20[0x2a] = *(uint *)(param_1 + 0x26cc);
  puVar20[0x2b] = 0x854;
  puVar20[0x2c] = **(uint **)(param_1 + 0x2680);
  puVar20[0x2d] = 0x878;
  puVar20[0x2e] = **(uint **)(param_1 + 0x2684);
  puVar20[0x2f] = (uint)&switchdataD_000013c0;
  puVar20[0x30] = *(uint *)(param_1 + 0x1ce0);
  puVar20[0x31] = 0x12f0;
  puVar20[0x32] = *(uint *)(param_1 + 0x1d2c);
  if (((DAT_001ecaba)[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24] & 1) == 0) {
    *(byte *)(puVar20 + 0x32) = (byte)puVar20[0x32] & 0xfe;
  }
  puVar20[0x33] = 0x12f5;
  puVar20[0x34] = *(uint *)(param_1 + 0x1c8c);
  if (((DAT_001ecaba)[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24] & 1) == 0) {
    *(byte *)((int)puVar20 + 0xd1) = *(byte *)((int)puVar20 + 0xd1) & 0xf7;
  }
  puVar20[0x35] = 0x10a2;
  puVar20[0x36] = *(uint *)(param_1 + 0x1d7c);
  puVar20[0x37] = 0x1381;
  puVar20[0x38] = *(uint *)(param_1 + 0x1cc0);
  if (((DAT_001ecaba)[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24] & 2) == 0) {
    *(byte *)(puVar20 + 0x38) = (byte)puVar20[0x38] & 0xfc;
  }
  puVar20[0x39] = 0x109e;
  puVar20[0x3a] = *(uint *)(param_1 + 0x1d6c);
  puVar20[0x3b] = 0x1096;
  puVar20[0x3a] = *(uint *)(param_1 + 0x1df8);
  puVar20[0x3d] = 0x1041;
  puVar20[0x3e] = *(uint *)(param_1 + 0x29f0);
  puVar20[0x3f] = 0x1046;
  puVar20[0x40] = *(uint *)(param_1 + 0x1dfc);
  puVar20[0x41] = 0x1094;
  puVar20[0x42] = 0;
  puVar20[0x43] = 0x1095;
  puVar20[0x45] = 0x1095;
  puVar20[0x47] = 0x1095;
  puVar20[0x49] = 0x1095;
  puVar20[0x4b] = 0x1095;
  puVar20[0x4d] = 0x1095;
  puVar20[0x4f] = 0x1095;
  puVar20[0x51] = 0x1095;
  puVar20[0x53] = 0x1095;
  puVar20[0x55] = 0x1095;
  puVar20[0x57] = 0x1095;
  puVar20[0x59] = 0x1095;
  puVar20[0x5b] = 0xc0221000;
  puVar20[0x7f] = 0x1180;
  puVar20[0x80] = 2;
  puVar20[0x81] = 0x1189;
  puVar20[0x83] = 0x1181;
  puVar20[0x85] = 0x118d;
  puVar20[0x87] = 0x118e;
  puVar20[0x89] = 0x118c;
  puVar20[0x8b] = 0x11a9;
  puVar20[0x8c] = *(uint *)(param_1 + 0x257c);
  puVar20[0x8d] = 0x11aa;
  puVar20[0x8e] = *(uint *)(param_1 + 0x2580);
  puVar20[0x8f] = 0x11ab;
  puVar20[0x90] = *(uint *)(param_1 + 0x2584);
  puVar20[0x91] = 0x11ac;
  puVar20[0x92] = *(uint *)(param_1 + 0x2588);
  puVar20[0x93] = 0x10c0;
  puVar20[0x94] = *(uint *)(param_1 + 0x216c);
  puVar20[0x95] = 0x10c1;
  puVar20[0x97] = 0x10c8;
  puVar20[0x99] = 0x101d;
  puVar20[0x9a] = *(uint *)(param_1 + 0x2128);
  puVar20[0x9b] = 0x138a;
  puVar20[0x9c] = 0;
  puVar20[0x9d] = 0x138e;
  puVar20[0x9e] = 0;
  puVar20[0x9f] = 0x1040;
  puVar20[0xa0] = 0;
  puVar20[0xa1] = 0x1150;
  puVar20[0xa2] = 0;
  puVar20[0xa3] = 0x1100;
  puVar20[0xa4] = *(uint *)(param_1 + 0x1f1c);
  puVar20[0xa5] = 0x1110;
  puVar20[0xa6] = *(uint *)(param_1 + 0x1f5c);
  puVar20[0xa7] = 0x1120;
  puVar20[0xa8] = *(uint *)(param_1 + 0x1f9c);
  puVar20[0xa9] = 0x1130;
  puVar20[0xaa] = *(uint *)(param_1 + 0x1fdc);
  puVar20[0xab] = 0x1140;
  puVar20[0xac] = *(uint *)(param_1 + 0x201c);
  puVar20[0xad] = 0x10f4;
  puVar20[0xae] = 0xaaaa;
  puVar20[0xaf] = 0x1383;
  puVar20[0xb0] = *(uint *)(param_1 + 0x1d34);
  puVar20[0xb1] = 0x1386;
  puVar20[0xb2] = *(uint *)(param_1 + 0x1d38);
  puVar20[0xb3] = 0x110f8;
  puVar20[0xb4] = *(uint *)(param_1 + 0x1d98);
  puVar20[0xb5] = *(uint *)(param_1 + 0x1d50);
  puVar20[0xb6] = 0x1087;
  puVar20[0xb7] = *(uint *)(param_1 + 0x1f0c);
  puVar20[0xb8] = 0x31080;
  puVar20[0xb9] = *(uint *)(param_1 + 0x1efc);
  puVar20[0xba] = *(uint *)(param_1 + 0x1f04);
  puVar20[0xbb] = *(uint *)(param_1 + 0x1f00);
  puVar20[0xbc] = *(uint *)(param_1 + 0x1f08);
  FUN_0004acbc(puVar20 + 2,iVar7);
  if (bVar22) {
    puVar20[0xbf] = (uint)&UINT_000013c4;
    puVar20[0xc1] = 0x113c8;
    puVar20[0xc4] = 0x13cd;
    puVar20[0xc6] = (uint)&UINT_000013cc;
    puVar20[200] = 0x13ca;
  }
  uVar11 = ((int (*)())FUN_0002e415)();
  *(undefined4 *)(param_1 + 0x298c) = uVar11;
  (**(code **)(param_1 + 0x299c))(iVar7,uVar11);
  _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
  if ((((*(byte *)(param_1 + 0x24) & 0x82) != 0) && (param_2[0xd] != 0)) &&
     (*(char *)(param_2[0xd] + 0x16) == '\x06')) {
    iVar4 = iVar4 + 0xa0 + (uint)*(byte *)(iVar4 + 0x5e) * 0x18;
    uVar3 = *(ushort *)(iVar4 + 0xc);
    iVar7 = FUN_00009369(*(undefined2 *)(iVar4 + 0x10),*(undefined2 *)(iVar4 + 0x12));
    if (*(int *)(iVar4 + 0x14) != 0) {
      FUN_00009948(param_1,*(int *)(iVar4 + 0x14),iVar7 * (uint)uVar3 * local_104);
    }
  }
  if (((*(byte *)(param_2[0xc] + 0x4a) & 1) != 0) && (param_4 == *(byte *)(param_2[0xc] + 0x5e))) {
    ((int (*)())FUN_00032734)(param_1,param_2,param_3);
    return 1;
  }
  return 1;
}

/* FUN_000355d1 @ 0x355d1 (11991 bytes) */
int FUN_000355d1(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15)
  int param_1;
  int *param_2;
  int param_3;
  uint param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
  int param_9;
  int param_10;
  int param_11;
  uint param_12;
  int param_13;
  int param_14;
  undefined4 *param_15;
{
  ushort *puVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  short sVar5;
  char cVar6;
  float fVar7;
  byte bVar8;
  char cVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  undefined4 uVar16;
  uint *puVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  size_t sVar21;
  uint *puVar22;
  byte bVar23;
  byte bVar24;
  byte bVar25;
  uint uVar26;
  uint *puVar27;
  uint *puVar28;
  undefined4 *puVar29;
  int iVar30;
  bool bVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  int local_2c0;
  uint local_1e4;
  int local_1d8;
  uint local_1a4;
  uint local_1a0;
  uint local_190;
  byte local_188;
  int local_180;
  int local_16c;
  uint *local_168;
  uint *local_164;
  int local_158;
  uint *local_154;
  uint *local_144;
  byte local_140;
  int local_13c;
  uint local_128;
  byte local_114;
  int local_110;
  float local_108;
  float local_100;
  float local_fc;
  uint local_e4;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  float local_bc;
  float local_b4;
  int local_ac;
  uint *local_a0;
  uint *local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint *local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  undefined4 local_78;
  uint local_74;
  undefined4 local_70;
  int local_6c;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_2c;
  int local_28;
  int local_24;
  uint local_20 [4];
  
  cVar6 = (char)param_4;
  if (param_15 == (undefined4 *)0x0) {
    _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
    iVar12 = ((int (*)())FUN_0002eb84)(param_4,0);
    if (iVar12 == 0) {
LAB_000366d4:
      _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
      return 0;
    }
    iVar13 = param_2[0xd];
    if ((iVar13 == 0) || (*(char *)(iVar13 + 0x16) != '\x06')) {
      if ((*(byte *)((int)param_2 + 0x39) & 7) != 0) {
        cVar9 = ((int (*)())FUN_0002fdb4)(param_1,param_2);
        if (cVar9 == '\0') goto LAB_000366d4;
        iVar13 = param_2[0xd];
      }
      if (*(char *)(iVar13 + 0x16) != '\x06') {
        bVar8 = *(byte *)(iVar12 + 0x17) >> 5;
        uVar10 = (param_8 << bVar8) + 0x23U & 0xffffffe0;
        if ((((param_10 == 1) && (param_8 < 0x1001)) && ((param_8 < 0x801 || (bVar8 < 4)))) &&
           ((*(byte *)(iVar12 + 0x17) & 0x10) == 0)) {
          iVar30 = param_1 + 0x240;
          uVar16 = (**(code **)(param_1 + 0x2998))(iVar30,0xe0);
          *(undefined4 *)(param_1 + 0x298c) = uVar16;
          uVar16 = ((int (*)())FUN_0002e3ab)();
          *(undefined4 *)(param_1 + 0x298c) = uVar16;
          (**(code **)(param_1 + 0x299c))(iVar30,uVar16);
          iVar13 = (int)(0x1e000 / (ulonglong)uVar10);
          bVar8 = *(byte *)(param_2 + 0xe);
          uVar20 = ((int (*)())FUN_0002d486)();
          if ((uVar20 == bVar8) && (*(byte *)(iVar12 + 0x17) >> 5 < 3)) {
            iVar13 = (int)(0x10000 / (ulonglong)uVar10);
            if (0 < param_9) {
              iVar11 = (param_3 * 0xd + param_4) * 0x20;
              local_1d8 = 0;
              do {
                iVar19 = local_1d8 + iVar13;
                local_180 = iVar13;
                if (param_9 < iVar19) {
                  local_180 = param_9 - local_1d8;
                }
                bVar8 = *(byte *)(iVar12 + 0x18) & 3;
                puVar27 = *(uint **)(param_1 + 500);
                if (*(undefined1 **)(param_1 + 0x1f8) <=
                    (undefined1 *)((int)puVar27 + uVar10 * local_180 + 0x80)) {
                  local_24 = 2;
                  uVar20 = *(int *)(param_1 + 0x204) + 1;
                  *(uint *)(param_1 + 0x204) = uVar20;
                  if (2 < uVar20) {
                    if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
                      FUN_00017c77(param_1,0x1000000);
                      puVar27 = *(uint **)(param_1 + 500);
                    }
                    *(undefined4 *)(param_1 + 0x204) = 1;
                  }
                  *(int *)(*(int *)(param_1 + 0x208) + 0xc) =
                       (int)puVar27 - *(int *)(param_1 + 0x1fc) >> 2;
                  _io_connect_method_scalarI_scalarO
                            (*(undefined4 *)(param_1 + 4),0x12,0,0,&local_98,&local_24);
                  *(uint **)(param_1 + 0x1fc) = local_98;
                  *(uint **)(param_1 + 500) = local_98;
                  *(undefined1 **)(param_1 + 0x1f8) =
                       (undefined1 *)((int)local_98 + (local_94 & 0xfffffffc));
                  *(undefined4 *)(param_1 + 0x200) = *(undefined4 *)(*(int *)(param_1 + 0x208) + 8);
                  *(uint *)(param_1 + 0x26c8) = *(uint *)(param_1 + 0x26c8) | 1;
                  puVar27 = local_98;
                }
                puVar27 = (uint *)((uint)((int)puVar27 + 0x7f) & 0xffffff80);
                *(uint **)(param_1 + 500) = puVar27;
                local_68 = local_180;
                local_6c = param_8;
                local_2c = 0;
                local_78 = 2;
                local_90 = (uint)(*(byte *)(iVar12 + 0x10) & 0x1f);
                local_8c = *(ushort *)(iVar12 + 0x10) >> 5 & 0x1f;
                local_64 = 0;
                local_60 = 0;
                local_70 = 0;
                local_74 = 0;
                if (param_14 == '\0') {
                  iVar15 = *(int *)(param_1 + 0x10);
                  iVar18 = iVar15 + 0x2e6c;
                  if (*(char *)(iVar15 + 0x2e84) != '\0') {
                    local_74 = 1;
                    if (param_12 < 0x8037) {
                      if (param_12 < 0x8035) {
                        if (param_12 < 0x1407) {
                          if (0x1404 < param_12) goto LAB_00037574;
                          if (param_12 != 0x1403) {
LAB_000372e0:
                            bVar23 = 0;
                            goto LAB_000372e2;
                          }
                        }
                        else if (param_12 != 0x140b) {
                          if (param_12 < 0x140b) goto LAB_000372e0;
                          if (param_12 < 0x8033) {
                            bVar23 = 0;
                            goto LAB_000372e2;
                          }
                        }
                        goto LAB_0003759d;
                      }
LAB_00037574:
                      bVar23 = 2;
                    }
                    else {
                      if (param_12 < 0x8369) {
                        if (0x8366 < param_12) goto LAB_00037574;
                        if (param_12 < 0x8363) goto LAB_000372e0;
                      }
                      else if (1 < param_12 - 0x85ba) {
                        bVar23 = 0;
                        goto LAB_000372e2;
                      }
LAB_0003759d:
                      bVar23 = 1;
                    }
LAB_000372e2:
                    bVar8 = bVar8 ^ bVar23;
                  }
                  if (*(char *)(iVar15 + 0x2e85) != '\0') {
                    local_74 = local_74 | 4;
                  }
                }
                else {
                  iVar18 = 0;
                }
                local_88 = puVar27;
                local_84 = uVar10;
                local_80 = local_90;
                local_7c = local_8c;
                FUN_000095f0(param_1,param_11,param_12,param_8,param_9,&local_94,&local_28,&local_24
                             ,iVar18);
                uVar26 = local_84;
                uVar20 = local_94;
                local_98 = (uint *)(param_13 + local_24 + local_1d8 * local_94);
                if (bVar8 == 1) {
                  local_154 = local_88;
                  iVar15 = local_28 * local_6c;
                  puVar22 = local_98;
                  puVar17 = local_88;
                  local_158 = local_68 + -1;
                  puVar28 = local_98;
                  if (0 < local_68) {
                    do {
                      for (; 0 < iVar15; iVar15 = iVar15 + -2) {
                        *(ushort *)puVar17 = (ushort)*puVar22 << 8 | (ushort)*puVar22 >> 8;
                        puVar22 = (uint *)((int)puVar22 + 2);
                        puVar17 = (uint *)((int)puVar17 + 2);
                      }
                      puVar22 = (uint *)((int)puVar28 + local_94);
                      puVar17 = (uint *)((int)local_154 + local_84);
                      iVar18 = local_158 + -1;
                      bVar31 = -1 < local_158;
                      iVar15 = local_28 * local_6c;
                      local_154 = puVar17;
                      local_158 = iVar18;
                      puVar28 = puVar22;
                    } while (iVar18 != -1 && bVar31);
                  }
                }
                else if (bVar8 == 2) {
                  local_168 = local_88;
                  iVar15 = local_28 * local_6c;
                  puVar22 = local_88;
                  puVar17 = local_98;
                  local_164 = local_98;
                  local_16c = local_68 + -1;
                  if (0 < local_68) {
                    do {
                      for (; 0 < iVar15; iVar15 = iVar15 + -4) {
                        uVar20 = *puVar17;
                        *puVar22 = uVar20 >> 0x18 | (uVar20 & 0xff0000) >> 8 |
                                   (uVar20 & 0xff00) << 8 | uVar20 << 0x18;
                        puVar22 = puVar22 + 1;
                        puVar17 = puVar17 + 1;
                      }
                      puVar17 = (uint *)((int)local_164 + local_94);
                      puVar22 = (uint *)((int)local_168 + local_84);
                      iVar18 = local_16c + -1;
                      bVar31 = -1 < local_16c;
                      iVar15 = local_28 * local_6c;
                      local_164 = puVar17;
                      local_168 = puVar22;
                      local_16c = iVar18;
                    } while (iVar18 != -1 && bVar31);
                  }
                }
                else {
                  sVar21 = local_28 * local_6c;
                  puVar17 = local_98;
                  puVar22 = local_88;
                  iVar15 = local_68;
                  if ((int)sVar21 < 0x11) {
                    puVar17 = local_88;
                    local_144 = local_98;
                    local_cc = local_68 + -1;
                    if (0 < local_68) {
                      do {
                        puVar22 = puVar17;
                        uVar20 = sVar21;
                        puVar28 = local_144;
                        if ((((uint)puVar17 & 1) != 0) && (sVar21 != 0)) {
                          *(char *)puVar17 = (char)*local_144;
                          puVar22 = (uint *)((int)puVar17 + 1);
                          uVar20 = sVar21 - 1;
                          puVar28 = (uint *)((int)local_144 + 1);
                        }
                        if ((((uint)puVar22 & 2) != 0) && (1 < uVar20)) {
                          uVar26 = *puVar28;
                          puVar28 = (uint *)((int)puVar28 + 2);
                          *(ushort *)puVar22 = (ushort)uVar26;
                          puVar22 = (uint *)((int)puVar22 + 2);
                          uVar20 = uVar20 - 2;
                        }
                        for (; 3 < uVar20; uVar20 = uVar20 - 4) {
                          uVar26 = *puVar28;
                          puVar28 = puVar28 + 1;
                          *puVar22 = uVar26;
                          puVar22 = puVar22 + 1;
                        }
                        if (1 < uVar20) {
                          uVar26 = *puVar28;
                          puVar28 = (uint *)((int)puVar28 + 2);
                          *(ushort *)puVar22 = (ushort)uVar26;
                          puVar22 = (uint *)((int)puVar22 + 2);
                          uVar20 = uVar20 - 2;
                        }
                        if (uVar20 != 0) {
                          *(char *)puVar22 = (char)*puVar28;
                        }
                        local_144 = (uint *)((int)local_144 + local_94);
                        puVar17 = (uint *)((int)puVar17 + local_84);
                        iVar15 = local_cc + -1;
                        bVar31 = -1 < local_cc;
                        local_cc = iVar15;
                      } while (iVar15 != -1 && bVar31);
                    }
                  }
                  else {
                    for (; 0 < iVar15; iVar15 = iVar15 + -1) {
                      _memcpy(puVar22,puVar17,sVar21);
                      puVar17 = (uint *)((int)puVar17 + uVar20);
                      puVar22 = (uint *)((int)puVar22 + uVar26);
                    }
                  }
                }
                iVar15 = *(int *)(param_1 + 0x1fc);
                *(uint **)(param_1 + 500) = (uint *)((int)puVar27 + uVar10 * local_180);
                puVar14 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar30,0x2a);
                *(undefined4 **)(param_1 + 0x298c) = puVar14;
                puVar17 = *(uint **)(param_1 + 0x1d8);
                *puVar17 = *puVar17 | (int)puVar14 - (int)puVar17 >> 2;
                *(undefined4 **)(param_1 + 0x1d8) = puVar14;
                *puVar14 = 0x44000000;
                puVar14[1] = 0x2a;
                puVar14[2] = param_3 << 0x10 | param_4 & 0xffff;
                puVar14[3] = *(undefined4 *)(param_1 + 0x200);
                puVar14[4] = (int)puVar27 - iVar15;
                puVar14[5] = 0x1393;
                puVar14[6] = 10;
                puVar14[7] = 0x5c8;
                puVar14[8] = 0x20000;
                puVar14[9] = 0xd07;
                puVar14[10] = 0xffffffff;
                puVar14[0xb] = 0xc0001000;
                puVar14[0xc] = 0;
                puVar14[0xd] = 0x51b;
                puVar14[0xe] = (*(ushort *)(iVar12 + 0x18) >> 4 & 0xf) << 8 | 0x2cc30fb;
                puVar14[0xf] = 0x56b;
                puVar14[0x10] = 0;
                puVar14[0x11] = 0x56c;
                puVar14[0x12] = uVar10;
                puVar14[0x13] = 0x5c1;
                puVar14[0x14] = 0;
                puVar14[0x15] = 0x501;
                if ((param_2[0xd] == 0) || (*(char *)(param_2[0xd] + 0x16) != '\x06')) {
                  puVar14[0x16] =
                       param_7 * *(int *)(*param_2 + 0x54 + iVar11) +
                       *(int *)(*param_2 + 0x48 + iVar11);
                }
                else {
                  puVar14[0x16] = 0;
                }
                puVar1 = (ushort *)(param_4 * 0x18 + param_3 * 0x168 + param_2[0xc] + 0xa4);
                uVar16 = *(undefined4 *)puVar1;
                if (*(char *)(param_2[0xc] + 0x6d) == '\0') {
                  if ((param_2[0xd] == 0) || ((*(byte *)(param_2[0xd] + 0x15) & 0x18) == 0)) {
                    iVar15 = 0x20;
                  }
                  else {
                    iVar15 = (int)(0x20 / (longlong)
                                          (1 << ((byte)(DAT_001ecab8)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >> 2
                                                & 3)));
                  }
                  bVar8 = *(byte *)(iVar12 + 0x17) >> 5;
                  iVar15 = iVar15 >> bVar8;
                  iVar15 = ((*puVar1 - 1) + iVar15 & -iVar15) << bVar8;
                }
                else {
                  iVar15 = (uint)*(ushort *)((int)param_2 + 0x3e) << (*(byte *)(iVar12 + 0x17) >> 5)
                  ;
                }
                puVar14[0x17] = 0x502;
                puVar14[0x18] = iVar15;
                puVar14[0x19] = 0x5c0;
                iVar15 = param_2[0xd];
                if (iVar15 == 0) {
                  local_1e4 = 0;
LAB_00037216:
                  uVar20 = 0;
                }
                else {
                  bVar8 = *(byte *)(iVar15 + 0x15) >> 3;
                  local_1e4 = (bVar8 & 3) * 2;
                  if ((*(byte *)(iVar15 + 0x15) & 4) == 0) goto LAB_00037216;
                  local_140 = cVar6 - *(char *)(param_2[0xc] + 0x69);
                  if ((bVar8 & 3) == 0) {
                    local_d8 = 0x100;
                  }
                  else {
                    local_d8 = (int)(0x20 / (longlong)
                                            (1 << ((byte)(DAT_001ecab8)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >>
                                                   2 & 3))) << 3;
                  }
                  if ((iVar15 == 0) || ((*(byte *)(iVar15 + 0x15) & 0x18) == 0)) {
                    iVar15 = 1;
                  }
                  else {
                    iVar15 = 1 << ((byte)(DAT_001ecab8)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >> 2
                                  & 3);
                  }
                  if ((*(int *)(*param_2 + 0xc) >> (local_140 & 0x1f) < local_d8) ||
                     ((int)(uint)*(ushort *)(*param_2 + 0x16) >> (local_140 & 0x1f) < iVar15 * 8))
                  goto LAB_00037216;
                  uVar20 = 1;
                }
                puVar14[0x1a] = local_1e4 | uVar20;
                puVar14[0x1b] = 0x5bb;
                puVar14[0x1c] = 0;
                puVar14[0x1d] = 0x5bc;
                puVar14[0x1e] = uVar16;
                bVar8 = *(byte *)(iVar12 + 0x17);
                bVar23 = (byte)(*(ushort *)(iVar12 + 0x18) >> 4) & 0x1f;
                if (bVar23 < 3) {
LAB_00037128:
                  cVar9 = '\0';
                }
                else if (bVar23 < 5) {
                  cVar9 = '\x01';
                }
                else {
                  if (bVar23 != 6) goto LAB_00037128;
                  cVar9 = '\x02';
                }
                puVar14[0x1f] = 0x50e;
                bVar8 = (bVar8 >> 5) - cVar9;
                puVar14[0x20] =
                     (local_1d8 + param_6) * 0x10000 | param_5 << (bVar8 & 0x1f) & 0xffffU;
                puVar14[0x21] = 0x50f;
                puVar14[0x22] = local_180 << 0x10 | param_8 << (bVar8 & 0x1f) & 0xffffU;
                puVar14[0x23] = 0x80000000;
                puVar14[0x24] = 0xd0b;
                puVar14[0x25] = 5;
                puVar14[0x26] = 0x5c8;
                puVar14[0x27] = 0x10000;
                puVar14[0x28] = 0x1040;
                puVar14[0x29] = 0;
                *(undefined4 **)(param_1 + 0x298c) = puVar14 + 0x2a;
                (**(code **)(param_1 + 0x299c))(iVar30,puVar14 + 0x2a);
                local_1d8 = iVar19;
              } while (iVar19 < param_9);
            }
          }
          else if (0 < param_9) {
            fVar32 = ((float)(param_8 + param_5) - (float)param_5) * FLOAT_001c5bf4;
            fVar34 = ((float)param_5 + (float)(param_8 + param_5)) * FLOAT_001c5bd4;
            iVar11 = (param_3 * 0xd + param_4) * 0x20;
            local_ac = 0;
            do {
              iVar19 = local_ac + iVar13;
              local_13c = iVar13;
              if (param_9 < iVar19) {
                local_13c = param_9 - local_ac;
              }
              uVar10 = (param_8 << (*(byte *)(iVar12 + 0x17) >> 5)) + 0x23U & 0xffffffe0;
              puVar14 = (undefined4 *)
                        (**(code **)(param_1 + 0x2998))(iVar30,(uVar10 * local_13c >> 2) + 0x193);
              *(undefined4 **)(param_1 + 0x298c) = puVar14;
              iVar15 = param_3 * 0x168 + param_4 * 0x18 + param_2[0xc];
              uVar2 = *(ushort *)(iVar15 + 0xa4);
              uVar3 = *(ushort *)(iVar15 + 0xa6);
              puVar27 = *(uint **)(param_1 + 0x1d8);
              *puVar27 = *puVar27 | (int)puVar14 - (int)puVar27 >> 2;
              *(undefined4 **)(param_1 + 0x1d8) = puVar14;
              *puVar14 = 0x35000000;
              puVar14[2] = param_3 << 0x10 | param_4;
              _memcpy(puVar14 + 3,PTR_DAT_002131cd,0x2f4);
              *(byte *)(puVar14 + 0xa3) =
                   *(byte *)(puVar14 + 0xa3) & 0xfc | *(byte *)(iVar12 + 0x18) & 3;
              puVar14[0xa9] = (local_13c - 1U & 0x7ff) << 0xb | param_8 - 1U & 0x7ff | 0x80000000;
              puVar14[0xab] =
                   (uint)CONCAT11(0xa6,(byte)*(undefined4 *)
                                              (&DAT_001ed188 +
                                              (uint)(*(byte *)(iVar12 + 0x17) >> 5) * 4) & 0x1f);
              bVar8 = *(byte *)(iVar12 + 0x17);
              if ((bVar8 & 0xe0) == 0) {
                *(byte *)((int)puVar14 + 0x2ad) = *(byte *)((int)puVar14 + 0x2ad) & 0x8f;
                bVar8 = *(byte *)(iVar12 + 0x17);
              }
              puVar14[0xad] = (uVar10 >> (bVar8 >> 5)) - 1 & 0x3fff;
              *(byte *)((int)puVar14 + 0x2b5) =
                   *(byte *)((int)puVar14 + 0x2b5) & 0x7f | (0x800 < param_8) << 7;
              *(byte *)((int)puVar14 + 0x2b6) =
                   *(byte *)((int)puVar14 + 0x2b6) & 0xfe | 0x800 < local_13c;
              *(byte *)(puVar14 + 0x8d) =
                   *(byte *)(puVar14 + 0x8d) & 0xe0 |
                   (DAT_001ed174)[(uint)(*(byte *)(iVar12 + 0x17) >> 5) * 4] & 0x1f;
              iVar15 = param_2[0xd];
              if ((iVar15 == 0) || ((*(byte *)(iVar15 + 0x15) & 0x18) == 0)) {
                local_2c0 = 0x20;
              }
              else {
                local_2c0 = (int)(0x20 / (longlong)
                                         (1 << ((byte)(DAT_001ecab8)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >> 2 &
                                               3)));
              }
              local_2c0 = local_2c0 >> (*(byte *)(iVar12 + 0x17) >> 5);
              if ((iVar15 == 0) || (*(char *)(iVar15 + 0x16) != '\x06')) {
                iVar15 = param_7 * *(int *)(*param_2 + 0x54 + iVar11) +
                         *(int *)(*param_2 + 0x48 + iVar11);
                local_e4 = 0;
              }
              else {
                local_e4 = (uint)(*(byte *)(iVar12 + 0x18) & 3) << 0x13;
                iVar15 = 0;
              }
              puVar14[0x9d] = iVar15;
              if (*(char *)(param_2[0xc] + 0x6d) != '\0') {
                uVar2 = *(ushort *)((int)param_2 + 0x3e);
              }
              local_128 = (uint)uVar2;
              uVar20 = (local_128 - 1) + local_2c0 & -local_2c0;
              iVar15 = param_2[0xd];
              if ((iVar15 == 0) || ((*(byte *)(iVar15 + 0x15) & 4) == 0)) {
LAB_000368c5:
                iVar18 = 0;
              }
              else {
                local_114 = cVar6 - *(char *)(param_2[0xc] + 0x69);
                if ((*(byte *)(iVar15 + 0x15) & 0x18) == 0) {
                  local_dc = 0x100;
                }
                else {
                  local_dc = (int)(0x20 / (longlong)
                                          (1 << ((byte)(DAT_001ecab8)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >> 2
                                                & 3))) << 3;
                }
                if ((iVar15 == 0) || ((*(byte *)(iVar15 + 0x15) & 0x18) == 0)) {
                  local_110 = 1;
                }
                else {
                  local_110 = 1 << ((byte)(DAT_001ecab8)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >>
                                    2 & 3);
                }
                if ((*(int *)(*param_2 + 0xc) >> (local_114 & 0x1f) < local_dc) ||
                   ((int)(uint)*(ushort *)(*param_2 + 0x16) >> (local_114 & 0x1f) < local_110 * 8))
                goto LAB_000368c5;
                iVar18 = 1;
              }
              if (((*(byte *)(iVar12 + 0x18) & 0xc) == 0) || (iVar15 == 0)) {
                uVar26 = 0;
              }
              else {
                uVar26 = (*(byte *)(iVar15 + 0x15) >> 3 & 3) << 0x11;
              }
              puVar14[0x9f] =
                   uVar26 | iVar18 << 0x10 | uVar20 & 0x3ffe | local_e4 |
                   (*(uint *)(&DAT_001ed160 + (uint)(*(byte *)(iVar12 + 0x17) >> 5) * 4) & 0xf) <<
                   0x15;
              puVar14[0xb6] = uVar20 - 1 & 0x1fff | (uVar3 - 1 & 0x1fff) << 0xd;
              fVar37 = (float)(local_13c + local_ac + param_6);
              fVar38 = (float)(local_ac + param_6);
              puVar14[0xc0] = 0x31080;
              puVar14[0xc1] = 0;
              puVar14[0xc2] = 0x3f800000;
              puVar14[0xc3] = 0x3f800000;
              puVar14[0xc4] = 0;
              puVar14[0xc5] = 0x1087;
              puVar14[0xc6] = (int)((fVar37 - fVar38) * FLOAT_001c5bf4) | (int)fVar32 << 0x10;
              puVar14[199] = 0xc0033500;
              puVar14[200] = ((unsigned char *)0x00010031);
              puVar14[0xc9] = fVar34;
              puVar14[0xca] = (fVar37 + fVar38) * FLOAT_001c5bd4;
              puVar14[0xcb] = 0;
              puVar29 = puVar14 + 0xcc;
              puVar14[1] = (int)puVar29 - (int)puVar14 >> 2;
              puVar27 = *(uint **)(param_1 + 0x1d8);
              *puVar27 = *puVar27 | (int)puVar29 - (int)puVar27 >> 2;
              *(undefined4 **)(param_1 + 0x1d8) = puVar29;
              puVar14[0xcc] = 0x33000000;
              puVar14[0xcd] = 0;
              puVar14[0xce] = 0x1393;
              puVar14[0xcf] = 10;
              puVar14[0xd0] = 0x13c6;
              puVar14[0xd1] = 3;
              puVar14[0xd2] = 0x5c8;
              puVar14[0xd3] = 0x20000;
              puVar14[0xd4] = 0x10ea;
              puVar14[0xd5] = *(undefined4 *)(param_1 + 0x1cfc);
              puVar14[0xd6] = 0x10fa;
              puVar14[0xd7] = *(undefined4 *)(param_1 + 0x1da0);
              puVar14[0xd8] = 0xc0001000;
              puVar14[0xda] = 0x11004;
              puVar14[0xdb] = *(undefined4 *)(param_1 + 0x1ca8);
              puVar14[0xdc] = *(undefined4 *)(param_1 + 0x1cac);
              puVar14[0xdd] = 0x1008;
              puVar14[0xde] = *(undefined4 *)(param_1 + 0x1ca0);
              puVar14[0xdf] = 0x10e9;
              puVar14[0xe0] = *(undefined4 *)(param_1 + 0x1d20);
              puVar14[0xe1] = 0x13c7;
              puVar14[0xe2] = *(undefined4 *)(param_1 + 0x1cf0);
              puVar14[0xe3] = 0x13c1;
              puVar14[0xe4] = *(undefined4 *)(param_1 + 0x1ce4);
              puVar14[0xe5] = 0x850;
              puVar14[0xe6] = *(undefined4 *)(param_1 + 0x1dc0);
              puVar14[0xe7] = 0x887;
              puVar14[0xe8] = *(undefined4 *)(param_1 + 0x1db4);
              puVar14[0x189] = 0x82c;
              puVar14[0x18a] = *(undefined4 *)(param_1 + 0x1dc4);
              puVar14[0xe9] = 0x10ae;
              puVar14[0xea] = *(undefined4 *)(param_1 + 0x1d70);
              puVar14[0xeb] = 0x1394;
              puVar14[0xec] = *(undefined4 *)(param_1 + 0x1d30);
              puVar14[0xed] = 0x1380;
              puVar14[0xee] = 0;
              puVar14[0xef] = 0x1002;
              puVar14[0xf0] = *(undefined4 *)(param_1 + 0x1d90);
              puVar14[0xf0] = *(undefined4 *)(param_1 + 0x1d90);
              puVar14[0xf1] = 0x824;
              puVar14[0xf2] = *(undefined4 *)(param_1 + 0x1ddc);
              puVar14[0xf3] = 0x825;
              puVar14[0xf4] = *(undefined4 *)(param_1 + 0x1de0);
              puVar14[0xf5] = 0x82d;
              puVar14[0xf6] = *(undefined4 *)(param_1 + 0x26cc);
              puVar14[0xf7] = 0x854;
              puVar14[0xf8] = **(undefined4 **)(param_1 + 0x2680);
              puVar14[0xf9] = 0x878;
              puVar14[0xfa] = **(undefined4 **)(param_1 + 0x2684);
              puVar14[0xfb] = &switchdataD_000013c0;
              puVar14[0xfc] = *(undefined4 *)(param_1 + 0x1ce0);
              puVar14[0xfd] = 0x12f0;
              puVar14[0xfe] = *(undefined4 *)(param_1 + 0x1d2c);
              if (((DAT_001ecaba)[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24] & 1) == 0) {
                *(byte *)(puVar14 + 0xfe) = *(byte *)(puVar14 + 0xfe) & 0xfe;
              }
              puVar14[0xff] = 0x12f5;
              puVar14[0x100] = *(undefined4 *)(param_1 + 0x1c8c);
              if (((DAT_001ecaba)[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24] & 1) == 0) {
                *(byte *)((int)puVar14 + 0x401) = *(byte *)((int)puVar14 + 0x401) & 0xf7;
              }
              puVar14[0x101] = 0x10a2;
              puVar14[0x102] = *(undefined4 *)(param_1 + 0x1d7c);
              puVar14[0x103] = 0x1381;
              puVar14[0x104] = *(undefined4 *)(param_1 + 0x1cc0);
              if (((DAT_001ecaba)[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24] & 2) == 0) {
                *(byte *)(puVar14 + 0x104) = *(byte *)(puVar14 + 0x104) & 0xfc;
              }
              puVar14[0x105] = 0x109e;
              puVar14[0x106] = *(undefined4 *)(param_1 + 0x1d6c);
              puVar14[0x107] = 0x1096;
              puVar14[0x106] = *(undefined4 *)(param_1 + 0x1df8);
              puVar14[0x109] = 0x1041;
              puVar14[0x10a] = *(undefined4 *)(param_1 + 0x29f0);
              puVar14[0x10b] = 0x1046;
              puVar14[0x10c] = *(undefined4 *)(param_1 + 0x1dfc);
              puVar14[0x10d] = 0x1094;
              puVar14[0x10e] = 0;
              puVar14[0x10f] = 0x1095;
              puVar14[0x111] = 0x1095;
              puVar14[0x113] = 0x1095;
              puVar14[0x115] = 0x1095;
              puVar14[0x117] = 0x1095;
              puVar14[0x119] = 0x1095;
              puVar14[0x11b] = 0x1095;
              puVar14[0x11d] = 0x1095;
              puVar14[0x11f] = 0x1095;
              puVar14[0x121] = 0x1095;
              puVar14[0x123] = 0x1095;
              puVar14[0x125] = 0x1095;
              puVar14[0x127] = 0xc0221000;
              puVar14[0x14b] = 0x1180;
              puVar14[0x14c] = 2;
              puVar14[0x14d] = 0x1189;
              puVar14[0x14f] = 0x1181;
              puVar14[0x151] = 0x118d;
              puVar14[0x153] = 0x118e;
              puVar14[0x155] = 0x118c;
              puVar14[0x157] = 0x11a9;
              puVar14[0x158] = *(undefined4 *)(param_1 + 0x257c);
              puVar14[0x159] = 0x11aa;
              puVar14[0x15a] = *(undefined4 *)(param_1 + 0x2580);
              puVar14[0x15b] = 0x11ab;
              puVar14[0x15c] = *(undefined4 *)(param_1 + 0x2584);
              puVar14[0x15d] = 0x11ac;
              puVar14[0x15e] = *(undefined4 *)(param_1 + 0x2588);
              puVar14[0x15f] = 0x10c0;
              puVar14[0x160] = *(undefined4 *)(param_1 + 0x216c);
              puVar14[0x161] = 0x10c1;
              puVar14[0x163] = 0x10c8;
              puVar14[0x165] = 0x101d;
              puVar14[0x166] = *(undefined4 *)(param_1 + 0x2128);
              puVar14[0x167] = 0x138a;
              puVar14[0x168] = 0;
              puVar14[0x169] = 0x138e;
              puVar14[0x16a] = 0;
              puVar14[0x16b] = 0x1040;
              puVar14[0x16c] = 0;
              puVar14[0x16d] = 0x1150;
              puVar14[0x16e] = 0;
              puVar14[0x16f] = 0x1100;
              puVar14[0x170] = *(undefined4 *)(param_1 + 0x1f1c);
              puVar14[0x171] = 0x1110;
              puVar14[0x172] = *(undefined4 *)(param_1 + 0x1f5c);
              puVar14[0x173] = 0x1120;
              puVar14[0x174] = *(undefined4 *)(param_1 + 0x1f9c);
              puVar14[0x175] = 0x1130;
              puVar14[0x176] = *(undefined4 *)(param_1 + 0x1fdc);
              puVar14[0x177] = 0x1140;
              puVar14[0x178] = *(undefined4 *)(param_1 + 0x201c);
              puVar14[0x179] = 0x10f4;
              puVar14[0x17a] = 0xaaaa;
              puVar14[0x17b] = 0x1383;
              puVar14[0x17c] = *(undefined4 *)(param_1 + 0x1d34);
              puVar14[0x17d] = 0x1386;
              puVar14[0x17e] = *(undefined4 *)(param_1 + 0x1d38);
              puVar14[0x17f] = 0x110f8;
              puVar14[0x180] = *(undefined4 *)(param_1 + 0x1d98);
              puVar14[0x181] = *(undefined4 *)(param_1 + 0x1d50);
              puVar14[0x182] = 0x1087;
              puVar14[0x183] = *(undefined4 *)(param_1 + 0x1f0c);
              puVar14[0x184] = 0x31080;
              puVar14[0x185] = *(undefined4 *)(param_1 + 0x1efc);
              puVar14[0x186] = *(undefined4 *)(param_1 + 0x1f04);
              puVar14[0x187] = *(undefined4 *)(param_1 + 0x1f00);
              puVar14[0x188] = *(undefined4 *)(param_1 + 0x1f08);
              FUN_0004acbc(puVar14 + 0xce,iVar30);
              local_a0 = puVar14 + 0x18b;
              for (puVar27 = puVar14 + 0x18c; ((uint)puVar27 & 0x1f) != 0; puVar27 = puVar27 + 1) {
              }
              puVar14[0xa3] = puVar14[0xa3] & 0x1f | ((int)puVar27 - (int)puVar14 >> 2) << 5;
              iVar15 = ((param_8 << (*(byte *)(iVar12 + 0x17) >> 5)) + 3 >> 2) +
                       ((int)puVar27 - (int)local_a0 >> 2);
              if (iVar15 == 1) {
                uVar20 = 0x80000000;
              }
              else {
                uVar20 = (iVar15 + -2) * 0x10000 | 0xc0001000;
              }
              *local_a0 = uVar20;
              local_a0 = local_a0 + iVar15;
              if (1 < local_13c) {
                uVar20 = uVar10 >> 2;
                iVar15 = 1;
                do {
                  if (uVar20 == 1) {
                    uVar26 = 0x80000000;
                  }
                  else {
                    uVar26 = (uVar20 - 2) * 0x10000 | 0xc0001000;
                  }
                  *local_a0 = uVar26;
                  iVar15 = iVar15 + 1;
                  local_a0 = local_a0 + uVar20;
                } while (local_13c != iVar15);
              }
              sVar5 = *(short *)(param_2[0xc] + 0x1a);
              sVar4 = *(short *)(param_2[0xc] + 2);
              local_80 = (uint)(*(byte *)(iVar12 + 0x10) & 0x1f);
              local_7c = *(ushort *)(iVar12 + 0x10) >> 5 & 0x1f;
              local_64 = 0;
              local_60 = 0;
              local_74 = 0;
              local_70 = 0x7efff;
              if (param_14 == '\0') {
                iVar15 = *(int *)(param_1 + 0x10);
                iVar18 = iVar15 + 0x2e6c;
                local_74 = (uint)(*(char *)(iVar15 + 0x2e84) != '\0');
                if (*(char *)(iVar15 + 0x2e85) != '\0') {
                  local_74 = local_74 | 4;
                }
              }
              else {
                iVar18 = 0;
              }
              local_84 = uVar10;
              FUN_000095f0(param_1,param_11,param_12,param_8,param_9,&local_94,&local_24,&local_28,
                           iVar18);
              _glgConvertType(param_11,param_12,&local_90,&local_8c);
              if ((((sVar4 != 0x1908) && (sVar5 != -0x7a43)) && (sVar4 != 0x1906)) &&
                 ((sVar4 != 0x190a &&
                  ((0x15 < local_80 || ((1 << ((byte)local_80 & 0x1f) & 0x3ff707U) == 0)))))) {
                local_74 = local_74 | 0x8000;
              }
              local_78 = 2;
              local_68 = local_13c;
              local_6c = param_8;
              local_98 = (uint *)(param_13 + local_28 + local_ac * local_94);
              local_2c = 0;
              local_88 = puVar27;
              _glgProcessPixels(*(int *)(param_1 + 0x10) + 0x2e48,&local_98);
              *(uint **)(param_1 + 0x298c) = local_a0;
              (**(code **)(param_1 + 0x299c))(iVar30,local_a0);
              local_ac = iVar19;
            } while (iVar19 < param_9);
          }
          uVar16 = (**(code **)(param_1 + 0x2998))(iVar30,0xe0);
          *(undefined4 *)(param_1 + 0x298c) = uVar16;
          uVar16 = ((int (*)())FUN_0002e415)();
          *(undefined4 *)(param_1 + 0x298c) = uVar16;
          (**(code **)(param_1 + 0x299c))(iVar30,uVar16);
          _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
          if (((*(byte *)(param_2[0xc] + 0x4a) & 1) != 0) &&
             (param_4 == *(byte *)(param_2[0xc] + 0x5e))) {
            ((int (*)())FUN_00032734)(param_1,param_2,param_3);
            return 1;
          }
          return 1;
        }
        goto LAB_000366d4;
      }
    }
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return 0;
  }
  iVar12 = param_2[0xc];
  uVar10 = ((int (*)())FUN_0002d486)();
  if (uVar10 == 0) {
    return 0;
  }
  FUN_000095f0(param_1,param_11,param_12,param_8,param_9,local_20,&local_28,&local_24,
               *(int *)(param_1 + 0x10) + 0x2e6c);
  uVar20 = param_13 + local_24;
  iVar13 = *(int *)*param_15;
  if (0x1000 < (int)local_20[0] >> ((byte)local_28 & 0x1f)) {
    return 0;
  }
  if (0x1000 < param_9) {
    return 0;
  }
  iVar30 = param_3 * 0x168 + param_4 * 0x18;
  iVar11 = iVar30 + param_2[0xc];
  if (0x1000 < *(ushort *)(iVar11 + 0xa4)) {
    return 0;
  }
  if (0x1000 < *(ushort *)(iVar11 + 0xa6)) {
    return 0;
  }
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  iVar11 = ((int (*)())FUN_0002eb84)(param_4,0);
  if ((iVar11 == 0) || (-1 < *(char *)(iVar11 + 0x19))) {
LAB_00036a22:
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return 0;
  }
  iVar30 = iVar30 + param_2[0xc];
  local_1a4 = (uint)*(ushort *)(iVar30 + 0xa4);
  local_1a0 = (uint)*(ushort *)(iVar30 + 0xa6);
  if (local_1a4 == 0) {
    local_1a4 = 1;
    fVar32 = FLOAT_001c5ba4;
  }
  else {
    fVar32 = (float)local_1a4;
  }
  if (local_1a0 == 0) {
    local_1a0 = 1;
    local_108 = FLOAT_001c5ba4;
  }
  else {
    local_108 = (float)local_1a0;
  }
  fVar34 = (float)param_5;
  fVar37 = fVar34 + 0.0;
  fVar38 = (float)param_6;
  fVar39 = fVar38 + 0.0;
  if (0.0 < fVar37) {
    local_bc = fVar37 + fVar34;
    local_fc = fVar37;
  }
  else {
    local_fc = 0.0;
    local_bc = fVar37;
  }
  if (0.0 < fVar39) {
    local_b4 = fVar39 + fVar38;
    local_100 = fVar39;
  }
  else {
    local_100 = 0.0;
    local_b4 = fVar39;
  }
  fVar37 = (float)param_8 + fVar34;
  if (fVar32 <= (float)param_8 + fVar34) {
    fVar37 = fVar32;
  }
  fVar32 = (float)param_9 + fVar38;
  if (local_108 <= (float)param_9 + fVar38) {
    fVar32 = local_108;
  }
  if ((fVar37 <= local_fc) || (fVar32 <= local_100)) {
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return 1;
  }
  if (((*(byte *)((int)param_2 + 0x39) & 7) != 0) &&
     (cVar9 = ((int (*)())FUN_0002fdb4)(param_1,param_2), cVar9 == '\0')) goto LAB_00036a22;
  if ((*(int *)param_15[1] != 0) && (cVar9 = FUN_0001c242(param_1,param_15,1), cVar9 == '\0'))
  goto LAB_00037458;
  if (((int *)param_15[2] == (int *)0x0) || (iVar30 = *(int *)param_15[2], iVar30 == 0)) {
LAB_000375d6:
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return 0;
  }
  if (*(char *)(iVar30 + 0x16) != '\x06') {
    if (param_11 == 0x1908) {
      if (param_12 != 0x1406) goto LAB_00037458;
    }
    else if ((param_11 != 0x80e1) || (param_12 != 0x8367)) {
LAB_00037458:
      _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
      return 0;
    }
  }
  iVar30 = (uVar10 & 0xff) * 0x24;
  if (((uVar20 | local_20[0]) & 0x1f) != 0) goto LAB_000375d6;
  iVar15 = param_1 + 0x240;
  uVar16 = (**(code **)(param_1 + 0x2998))(iVar15,0x343);
  *(undefined4 *)(param_1 + 0x298c) = uVar16;
  puVar17 = (uint *)((int (*)())FUN_0002e3ab)();
  puVar29 = (undefined4 *)((uint)(puVar17 + 0xb) & 0xffffffe0);
  *puVar17 = (((int)puVar29 - (int)puVar17) + -8) * 0x4000 | 0xc0001000;
  puVar29[-1] = (int)puVar29 - (int)puVar17;
  puVar27 = *(uint **)(param_1 + 0x1d8);
  *puVar27 = *puVar27 | (int)puVar29 - (int)puVar27 >> 2;
  *(undefined4 **)(param_1 + 0x1d8) = puVar29;
  *puVar29 = 0x3e000000;
  puVar14 = *(undefined4 **)param_15[2];
  puVar14[4] = puVar14[4] + 0x10000;
  puVar29[2] = *puVar14;
  puVar29[3] = uVar20 - *(int *)*param_15;
  puVar29[4] = param_3 << 0x10 | param_4;
  _memcpy(puVar29 + 5,PTR_DAT_002131cd,0x2f4);
  iVar19 = param_2[0xd];
  if ((iVar19 == 0) || ((*(byte *)(iVar19 + 0x15) & 0x18) == 0)) {
    iVar18 = 0x20;
  }
  else {
    iVar18 = (int)(0x20 / (longlong)
                          (1 << ((byte)(DAT_001ecab8)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >> 2 &
                                3)));
  }
  iVar18 = iVar18 >> (*(byte *)(iVar11 + 0x17) >> 5);
  if ((iVar19 == 0) || (*(char *)(iVar19 + 0x16) != '\x06')) {
    iVar19 = (param_3 * 0xd + param_4) * 0x20;
    local_d4 = param_7 * *(int *)(*param_2 + 0x54 + iVar19) + *(int *)(*param_2 + 0x48 + iVar19);
  }
  else {
    local_d4 = 0;
  }
  if (*(char *)(param_2[0xc] + 0x6d) == '\0') {
    local_190 = (local_1a4 - 1) + iVar18 & -iVar18;
  }
  else {
    local_190 = (uint)*(ushort *)((int)param_2 + 0x3e);
  }
  *(byte *)(puVar29 + 0xa5) = *(byte *)(puVar29 + 0xa5) & 0xfc | (DAT_001ecab8)[iVar30] & 3;
  fVar7 = DAT_001c6150;
  fVar39 = DAT_001c6140;
  fVar33 = (fVar34 + fVar37) - local_bc;
  fVar40 = (fVar38 + fVar32) - local_b4;
  fVar35 = fVar33 - FLOAT_001c5ba4;
  if (fVar35 <= 0.0) {
    fVar35 = 0.0;
  }
  fVar36 = fVar40 - FLOAT_001c5ba4;
  if (fVar36 <= 0.0) {
    fVar36 = 0.0;
  }
  puVar29[0xab] =
       ((int)(fVar35 - (float)(-(uint)(DAT_001c6140 <= fVar35) & (uint)DAT_001c6140)) |
       -(uint)(DAT_001c6150 <= fVar35)) & 0x7ff |
       (((int)(fVar36 - (float)(-(uint)(DAT_001c6140 <= fVar36) & (uint)DAT_001c6140)) |
        -(uint)(DAT_001c6150 <= fVar36)) & 0x7ff) << 0xb | 0x80000000;
  bVar8 = (DAT_001ecac0)[iVar30];
  puVar29[0xad] =
       *(ushort *)(&DAT_001ecabe + iVar30) >> 4 & 0x1f | (bVar8 >> 6 & 1) << 0x16 |
       ((byte)(DAT_001ecabf)[iVar30] >> 1 & 7) << 9 |
       ((byte)(DAT_001ecabf)[iVar30] >> 4 & 7) << 0xc | (bVar8 & 7) << 0xf |
       (bVar8 >> 3 & 7) << 0x12;
  fVar35 = fVar33;
  if (fVar33 <= 0.0) {
    fVar35 = 0.0;
  }
  fVar36 = fVar40;
  if (fVar40 <= 0.0) {
    fVar36 = 0.0;
  }
  puVar29[0xaf] =
       ((int)local_20[0] >> ((byte)(DAT_001ecab7)[iVar30] >> 5)) - 1U & 0x3fff |
       (((int)(fVar35 - (float)(-(uint)(fVar39 <= fVar35) & (uint)fVar39)) |
        -(uint)(fVar7 <= fVar35)) - 1 >> 0xb) << 0xf |
       (((int)(fVar36 - (float)((uint)fVar39 & -(uint)(fVar39 <= fVar36))) |
        -(uint)(fVar7 <= fVar36)) - 1 >> 0xb) << 0x10;
  puVar29[0xa5] = puVar29[0xa5] & 0x1f | (uVar20 - iVar13) * 0x20;
  puVar29[0x9f] = local_d4;
  iVar13 = param_2[0xd];
  if ((iVar13 != 0) && ((*(byte *)(iVar13 + 0x15) & 4) != 0)) {
    local_188 = cVar6 - *(char *)(param_2[0xc] + 0x69);
    if ((*(byte *)(iVar13 + 0x15) & 0x18) == 0) {
      local_d0 = 0x100;
    }
    else {
      local_d0 = (int)(0x20 / (longlong)
                              (1 << ((byte)(DAT_001ecab8)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >>
                                     2 & 3))) << 3;
    }
    if ((iVar13 == 0) || ((*(byte *)(iVar13 + 0x15) & 0x18) == 0)) {
      iVar30 = 1;
    }
    else {
      iVar30 = 1 << ((byte)(DAT_001ecab8)[(uint)*(byte *)(param_2 + 0xe) * 0x24] >> 2 & 3);
    }
    if ((local_d0 <= *(int *)(*param_2 + 0xc) >> (local_188 & 0x1f)) &&
       (iVar30 * 8 <= (int)(uint)*(ushort *)(*param_2 + 0x16) >> (local_188 & 0x1f))) {
      iVar30 = 1;
      goto LAB_00037b3f;
    }
  }
  iVar30 = 0;
LAB_00037b3f:
  if (iVar13 == 0) {
    uVar10 = 0;
  }
  else {
    uVar10 = (*(byte *)(iVar13 + 0x15) >> 3 & 3) << 0x11;
  }
  puVar29[0xa1] =
       uVar10 | iVar30 << 0x10 | local_190 & 0x3ffe | (uint)(*(byte *)(iVar11 + 0x18) & 3) << 0x13 |
       (*(byte *)(iVar11 + 0x1a) >> 2 & 0xf) << 0x15;
  bVar23 = *(byte *)(iVar11 + 0x1b) >> 3 & 3;
  bVar8 = *(byte *)((int)puVar29 + 0x23d);
  *(byte *)((int)puVar29 + 0x23d) = bVar8 & 0xfc | bVar23;
  bVar24 = *(byte *)(iVar11 + 0x1b) >> 3 & 0xc;
  *(byte *)((int)puVar29 + 0x23d) = bVar8 & 0xf0 | bVar23 | bVar24;
  bVar25 = (*(byte *)(iVar11 + 0x1c) & 3) << 4;
  *(byte *)((int)puVar29 + 0x23d) = bVar8 & 0xc0 | bVar23 | bVar24 | bVar25;
  *(byte *)((int)puVar29 + 0x23d) = bVar23 | bVar24 | bVar25 | (*(byte *)(iVar11 + 0x1c) >> 2) << 6;
  *(byte *)(puVar29 + 0x8f) =
       *(byte *)(puVar29 + 0x8f) & 0xe0 | (byte)(*(ushort *)(iVar11 + 0x1a) >> 6) & 0x1f;
  sVar5 = *(short *)(iVar12 + 2);
  if (((sVar5 != 0x1908) && (sVar5 != 0x1906)) && (sVar5 != 0x190a)) {
    puVar29[0x5b] = puVar29[0x5b] & 0xfffe3fff | 0x18000;
  }
  puVar29[0xb8] = local_1a4 - 1 & 0x1fff | (local_1a0 - 1 & 0x1fff) << 0xd;
  if ((*(byte *)(iVar11 + 0x21) & 2) != 0) {
    puVar29[0x23] = 0;
  }
  fVar33 = FLOAT_001c5ba4 / fVar33;
  fVar40 = FLOAT_001c5ba4 / fVar40;
  puVar29[0xc2] = 0x31080;
  puVar29[0xc3] = fVar33 * local_bc;
  puVar29[0xc4] = (fVar38 + fVar32) * fVar40;
  puVar29[0xc5] = (fVar34 + fVar37) * fVar33;
  puVar29[0xc6] = fVar40 * local_b4;
  puVar29[199] = 0x1087;
  puVar29[200] = (int)((fVar37 - local_fc) * FLOAT_001c5bf4) << 0x10 |
                 (int)((fVar32 - local_100) * FLOAT_001c5bf4);
  puVar29[0xc9] = 0xc0033500;
  puVar29[0xca] = ((unsigned char *)0x00010031);
  fVar34 = FLOAT_001c5bd4;
  puVar29[0xcb] = (local_fc + fVar37) * FLOAT_001c5bd4;
  puVar29[0xcc] = fVar34 * (local_100 + fVar32);
  puVar29[0xcd] = 0;
  puVar14 = puVar29 + 0xce;
  puVar29[1] = (int)puVar14 - (int)puVar17 >> 2;
  puVar27 = *(uint **)(param_1 + 0x1d8);
  *puVar27 = *puVar27 | (int)puVar14 - (int)puVar27 >> 2;
  *(undefined4 **)(param_1 + 0x1d8) = puVar14;
  puVar29[0xce] = 0x33000000;
  puVar29[0xcf] = 0;
  puVar29[0xd0] = 0x1393;
  puVar29[0xd1] = 10;
  puVar29[0xd2] = 0x13c6;
  puVar29[0xd3] = 3;
  puVar29[0xd4] = 0x5c8;
  puVar29[0xd5] = 0x20000;
  puVar29[0xd6] = 0x10ea;
  puVar29[0xd7] = *(undefined4 *)(param_1 + 0x1cfc);
  puVar29[0xd8] = 0x10fa;
  puVar29[0xd9] = *(undefined4 *)(param_1 + 0x1da0);
  puVar29[0xda] = 0xc0001000;
  puVar29[0xdc] = 0x11004;
  puVar29[0xdd] = *(undefined4 *)(param_1 + 0x1ca8);
  puVar29[0xde] = *(undefined4 *)(param_1 + 0x1cac);
  puVar29[0xdf] = 0x1008;
  puVar29[0xe0] = *(undefined4 *)(param_1 + 0x1ca0);
  puVar29[0xe1] = 0x10e9;
  puVar29[0xe2] = *(undefined4 *)(param_1 + 0x1d20);
  puVar29[0xe3] = 0x13c7;
  puVar29[0xe4] = *(undefined4 *)(param_1 + 0x1cf0);
  puVar29[0xe5] = 0x13c1;
  puVar29[0xe6] = *(undefined4 *)(param_1 + 0x1ce4);
  puVar29[0xe7] = 0x850;
  puVar29[0xe8] = *(undefined4 *)(param_1 + 0x1dc0);
  puVar29[0xe9] = 0x887;
  puVar29[0xea] = *(undefined4 *)(param_1 + 0x1db4);
  puVar29[0x18b] = 0x82c;
  puVar29[0x18c] = *(undefined4 *)(param_1 + 0x1dc4);
  puVar29[0xeb] = 0x10ae;
  puVar29[0xec] = *(undefined4 *)(param_1 + 0x1d70);
  puVar29[0xed] = 0x1394;
  puVar29[0xee] = *(undefined4 *)(param_1 + 0x1d30);
  puVar29[0xef] = 0x1380;
  puVar29[0xf0] = 0;
  puVar29[0xf1] = 0x1002;
  puVar29[0xf2] = *(undefined4 *)(param_1 + 0x1d90);
  puVar29[0xf2] = *(undefined4 *)(param_1 + 0x1d90);
  puVar29[0xf3] = 0x824;
  puVar29[0xf4] = *(undefined4 *)(param_1 + 0x1ddc);
  puVar29[0xf5] = 0x825;
  puVar29[0xf6] = *(undefined4 *)(param_1 + 0x1de0);
  puVar29[0xf7] = 0x82d;
  puVar29[0xf8] = *(undefined4 *)(param_1 + 0x26cc);
  puVar29[0xf9] = 0x854;
  puVar29[0xfa] = **(undefined4 **)(param_1 + 0x2680);
  puVar29[0xfb] = 0x878;
  puVar29[0xfc] = **(undefined4 **)(param_1 + 0x2684);
  puVar29[0xfd] = &switchdataD_000013c0;
  puVar29[0xfe] = *(undefined4 *)(param_1 + 0x1ce0);
  puVar29[0xff] = 0x12f0;
  puVar29[0x100] = *(undefined4 *)(param_1 + 0x1d2c);
  if (((DAT_001ecaba)[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24] & 1) == 0) {
    *(byte *)(puVar29 + 0x100) = *(byte *)(puVar29 + 0x100) & 0xfe;
  }
  puVar29[0x101] = 0x12f5;
  puVar29[0x102] = *(undefined4 *)(param_1 + 0x1c8c);
  if (((DAT_001ecaba)[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24] & 1) == 0) {
    *(byte *)((int)puVar29 + 0x409) = *(byte *)((int)puVar29 + 0x409) & 0xf7;
  }
  puVar29[0x103] = 0x10a2;
  puVar29[0x104] = *(undefined4 *)(param_1 + 0x1d7c);
  puVar29[0x105] = 0x1381;
  puVar29[0x106] = *(undefined4 *)(param_1 + 0x1cc0);
  if (((DAT_001ecaba)[(uint)*(byte *)(param_1 + 0x2b7f) * 0x24] & 2) == 0) {
    *(byte *)(puVar29 + 0x106) = *(byte *)(puVar29 + 0x106) & 0xfc;
  }
  puVar29[0x107] = 0x109e;
  puVar29[0x108] = *(undefined4 *)(param_1 + 0x1d6c);
  puVar29[0x109] = 0x1096;
  puVar29[0x108] = *(undefined4 *)(param_1 + 0x1df8);
  puVar29[0x10b] = 0x1041;
  puVar29[0x10c] = *(undefined4 *)(param_1 + 0x29f0);
  puVar29[0x10d] = 0x1046;
  puVar29[0x10e] = *(undefined4 *)(param_1 + 0x1dfc);
  puVar29[0x10f] = 0x1094;
  puVar29[0x110] = 0;
  puVar29[0x111] = 0x1095;
  puVar29[0x113] = 0x1095;
  puVar29[0x115] = 0x1095;
  puVar29[0x117] = 0x1095;
  puVar29[0x119] = 0x1095;
  puVar29[0x11b] = 0x1095;
  puVar29[0x11d] = 0x1095;
  puVar29[0x11f] = 0x1095;
  puVar29[0x121] = 0x1095;
  puVar29[0x123] = 0x1095;
  puVar29[0x125] = 0x1095;
  puVar29[0x127] = 0x1095;
  puVar29[0x129] = 0xc0221000;
  puVar29[0x14d] = 0x1180;
  puVar29[0x14e] = 2;
  puVar29[0x14f] = 0x1189;
  puVar29[0x151] = 0x1181;
  puVar29[0x153] = 0x118d;
  puVar29[0x155] = 0x118e;
  puVar29[0x157] = 0x118c;
  puVar29[0x159] = 0x11a9;
  puVar29[0x15a] = *(undefined4 *)(param_1 + 0x257c);
  puVar29[0x15b] = 0x11aa;
  puVar29[0x15c] = *(undefined4 *)(param_1 + 0x2580);
  puVar29[0x15d] = 0x11ab;
  puVar29[0x15e] = *(undefined4 *)(param_1 + 0x2584);
  puVar29[0x15f] = 0x11ac;
  puVar29[0x160] = *(undefined4 *)(param_1 + 0x2588);
  puVar29[0x161] = 0x10c0;
  puVar29[0x162] = *(undefined4 *)(param_1 + 0x216c);
  puVar29[0x163] = 0x10c1;
  puVar29[0x165] = 0x10c8;
  puVar29[0x167] = 0x101d;
  puVar29[0x168] = *(undefined4 *)(param_1 + 0x2128);
  puVar29[0x169] = 0x138a;
  puVar29[0x16a] = 0;
  puVar29[0x16b] = 0x138e;
  puVar29[0x16c] = 0;
  puVar29[0x16d] = 0x1040;
  puVar29[0x16e] = 0;
  puVar29[0x16f] = 0x1150;
  puVar29[0x170] = 0;
  puVar29[0x171] = 0x1100;
  puVar29[0x172] = *(undefined4 *)(param_1 + 0x1f1c);
  puVar29[0x173] = 0x1110;
  puVar29[0x174] = *(undefined4 *)(param_1 + 0x1f5c);
  puVar29[0x175] = 0x1120;
  puVar29[0x176] = *(undefined4 *)(param_1 + 0x1f9c);
  puVar29[0x177] = 0x1130;
  puVar29[0x178] = *(undefined4 *)(param_1 + 0x1fdc);
  puVar29[0x179] = 0x1140;
  puVar29[0x17a] = *(undefined4 *)(param_1 + 0x201c);
  puVar29[0x17b] = 0x10f4;
  puVar29[0x17c] = 0xaaaa;
  puVar29[0x17d] = 0x1383;
  puVar29[0x17e] = *(undefined4 *)(param_1 + 0x1d34);
  puVar29[0x17f] = 0x1386;
  puVar29[0x180] = *(undefined4 *)(param_1 + 0x1d38);
  puVar29[0x181] = 0x110f8;
  puVar29[0x182] = *(undefined4 *)(param_1 + 0x1d98);
  puVar29[0x183] = *(undefined4 *)(param_1 + 0x1d50);
  puVar29[0x184] = 0x1087;
  puVar29[0x185] = *(undefined4 *)(param_1 + 0x1f0c);
  puVar29[0x186] = 0x31080;
  puVar29[0x187] = *(undefined4 *)(param_1 + 0x1efc);
  puVar29[0x188] = *(undefined4 *)(param_1 + 0x1f04);
  puVar29[0x189] = *(undefined4 *)(param_1 + 0x1f00);
  puVar29[0x18a] = *(undefined4 *)(param_1 + 0x1f08);
  FUN_0004acbc(puVar29 + 0xd0,iVar15);
  uVar16 = ((int (*)())FUN_0002e415)();
  *(undefined4 *)(param_1 + 0x298c) = uVar16;
  (**(code **)(param_1 + 0x299c))(iVar15,uVar16);
  _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
  if (((*(byte *)(param_2[0xc] + 0x4a) & 1) != 0) && (param_4 == *(byte *)(param_2[0xc] + 0x5e))) {
    ((int (*)())FUN_00032734)(param_1,param_2,param_3);
    return 1;
  }
  return 1;
}

/* FUN_000384a8 @ 0x384a8 (176 bytes) */
int FUN_000384a8(param_1)
  int param_1;
{
  int iVar1;
  undefined1 local_20 [12];
  undefined4 local_14;
  undefined4 local_10 [2];
  
  local_10[0] = 0;
  local_14 = 3;
  iVar1 = _IOServiceOpen(*(undefined4 *)(*(int *)(PTR_DAT_002131ad + 8) + param_1 * 4),
                         *(undefined4 *)PTR_002131b5,1,local_10);
  if (iVar1 == 0) {
    iVar1 = _io_connect_method_scalarI_scalarO(local_10[0],3,0,0,local_20,&local_14);
    if (iVar1 == 0) {
      _IOServiceClose(local_10[0]);
      return 1;
    }
    _IOServiceClose(local_10[0]);
  }
  return 0;
}

/* FUN_00038558 @ 0x38558 (16 bytes) */
int FUN_00038558()
{
  return "ATIR500";
}

/* _gldGetVersion @ 0x38568 (67 bytes) */
int _gldGetVersion(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  if (*(int *)PTR_DAT_002131ad != 0) {
    *param_1 = 2;
    *param_2 = 4;
    *param_3 = 0xb;
    *param_4 = 0x1900;
    return 1;
  }
  return 0;
}

/* _gldGetString @ 0x385ab (36 bytes) */
int _gldGetString(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint uVar1;
  
  switch(param_2) {
  case 0x1f00:
    return "ATI Technologies Inc.";
  case 0x1f01:
    break;
  case 0x1f02:
    return "1.5 ATI-1.4.19";
  case 0x1f03:
    return "";
  case 0x1f04:
    return "ATIRadeonX1000GLDriver";
  default:
    return (char *)0x0;
  }
  uVar1 = *(uint *)(param_1 + 0x24) & 0x7ff00000;
  if (uVar1 == 0x100000) {
    return "ATI Radeon X1800 OpenGL Engine";
  }
  if (uVar1 != 0x200000) {
    if (uVar1 == 0x800000) {
      return "ATI Radeon X1900 OpenGL Engine";
    }
    return "ATI Radeon X1000 OpenGL Engine";
  }
  return "ATI Radeon X1600 OpenGL Engine";
}

/* FUN_00038644 @ 0x38644 (769 bytes) */
int FUN_00038644(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  bool bVar10;
  uint local_30;
  uint local_24;
  int local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  
  iVar8 = ((int (*)())FUN_0002ab76)(param_1,param_4,3,param_3);
  if (iVar8 == 0) {
    return;
  }
  iVar4 = *(int *)(param_1 + 0x29e8);
  iVar5 = *(int *)(*(int *)(**(int **)(param_1 + 0x1cc) + 4) + 0x20);
  local_10 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar5 * iVar8 * 5 + iVar8 * 2 + 0x16 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe));
  *(undefined4 **)(param_1 + 0x298c) = local_10;
  if (*(int *)(param_1 + 0x2680) != param_1 + 0x1e24) {
    *(int *)(param_1 + 0x2680) = param_1 + 0x1e24;
    *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
    *(undefined4 *)(param_1 + 0x26cc) = *(undefined4 *)(param_1 + 0x1ee4);
    local_10 = (undefined4 *)((int (*)())FUN_0002a122)(param_1,local_10);
  }
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    *local_10 = 0x5c8;
    local_10[1] = 0x10000000;
    local_10 = local_10 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  *local_10 = 0x82c;
  local_10[1] = *(undefined4 *)(param_1 + 0x1dc4);
  local_10[2] = 0x821;
  local_10[3] = 3;
  local_10 = local_10 + 4;
  iVar4 = *(int *)(iVar4 + 0x2c);
  local_24 = param_2;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  uVar1 = param_2 + iVar8 * iVar5 * 4 * 4;
  if (param_2 < uVar1) {
    iVar8 = iVar5 + -1;
    local_30 = 0;
    do {
      *local_10 = 0x917;
      if (local_30 < 0x20) {
        local_10[1] = (uint)((**(uint **)(*(int *)(param_1 + 0x10) + 0x2d50) &
                             1 << ((byte)local_30 & 0x1f)) != 0);
      }
      else {
        if (local_30 < 0x40) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 4) &
                   1 << ((byte)local_30 - 0x20 & 0x1f)) == 0;
        }
        else if (local_30 < 0x60) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 8) &
                   1 << ((byte)local_30 - 0x40 & 0x1f)) == 0;
        }
        else {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 0xc) &
                   1 << ((byte)local_30 + 0xa0 & 0x1f)) == 0;
        }
        local_10[1] = (uint)!bVar10;
      }
      local_10 = local_10 + 2;
      if (-1 < iVar8) {
        local_14 = (undefined4 *)(iVar4 + iVar8 * 4);
        puVar9 = (undefined4 *)(local_24 + iVar8 * 0x10);
        local_18 = 0;
        do {
          uVar2 = *puVar9;
          uVar6 = puVar9[1];
          uVar7 = puVar9[2];
          uVar3 = puVar9[3];
          *local_10 = *local_14;
          local_10[1] = uVar2;
          local_10[2] = uVar6;
          local_10[3] = uVar7;
          local_10[4] = uVar3;
          local_10 = local_10 + 5;
          local_18 = local_18 + 1;
          local_14 = local_14 + -1;
          puVar9 = puVar9 + -4;
        } while (local_18 != iVar5);
      }
      local_30 = local_30 + 1;
      local_24 = local_24 + iVar5 * 0x10;
    } while (local_24 < uVar1);
  }
  *local_10 = 0x92b;
  local_10[1] = 0;
  local_10[2] = 0x1393;
  local_10[3] = 0;
  *(undefined4 **)(param_1 + 0x298c) = local_10 + 4;
                    
                    
  (**(code **)(param_1 + 0x299c))();
  return;
}

/* FUN_00038945 @ 0x38945 (1161 bytes) */
int FUN_00038945(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  undefined4 param_4;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  uint local_5c;
  uint local_54;
  uint local_40;
  uint local_3c;
  int local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  int local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  
  iVar9 = ((int (*)())FUN_0002ab76)(param_1,0,6,param_4);
  if (iVar9 == 0) {
    return;
  }
  iVar3 = *(int *)(param_1 + 0x29e8);
  iVar4 = *(int *)(*(int *)(**(int **)(param_1 + 0x1cc) + 4) + 0x20);
  local_14 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        (iVar9 * 5 + 5) * iVar4 + iVar9 * 2 + 0x18 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe));
  *(undefined4 **)(param_1 + 0x298c) = local_14;
  if (*(int *)(param_1 + 0x2680) != param_1 + 0x1e24) {
    *(int *)(param_1 + 0x2680) = param_1 + 0x1e24;
    *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
    *(undefined4 *)(param_1 + 0x26cc) = *(undefined4 *)(param_1 + 0x1ee4);
    local_14 = (undefined4 *)((int (*)())FUN_0002a122)(param_1,local_14);
  }
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    *local_14 = 0x5c8;
    local_14[1] = 0x10000000;
    local_14 = local_14 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  *local_14 = 0x82c;
  local_14[1] = *(undefined4 *)(param_1 + 0x1dc4);
  local_14[2] = 0x821;
  local_14[3] = 5;
  local_14 = local_14 + 4;
  iVar5 = *(int *)(iVar3 + 0x2c);
  local_54 = param_2;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  iVar10 = iVar4 * 0x10;
  if (param_2 < param_2 + iVar10) {
    iVar11 = iVar4 + -1;
    local_5c = 0;
    do {
      *local_14 = 0x917;
      if (local_5c < 0x20) {
        local_14[1] = (uint)((**(uint **)(*(int *)(param_1 + 0x10) + 0x2d50) &
                             1 << ((byte)local_5c & 0x1f)) != 0);
      }
      else {
        if (local_5c < 0x40) {
          bVar12 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 4) &
                   1 << ((byte)local_5c - 0x20 & 0x1f)) == 0;
        }
        else if (local_5c < 0x60) {
          bVar12 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 8) &
                   1 << ((byte)local_5c - 0x40 & 0x1f)) == 0;
        }
        else {
          bVar12 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 0xc) &
                   1 << ((byte)local_5c + 0xa0 & 0x1f)) == 0;
        }
        local_14[1] = (uint)!bVar12;
      }
      local_14 = local_14 + 2;
      if (-1 < iVar11) {
        local_1c = (undefined4 *)(iVar5 + iVar11 * 4);
        local_18 = (undefined4 *)(iVar11 * 0x10 + local_54);
        local_20 = 0;
        do {
          uVar2 = *local_18;
          uVar6 = local_18[1];
          uVar7 = local_18[2];
          uVar8 = local_18[3];
          *local_14 = *local_1c;
          local_14[1] = uVar2;
          local_14[2] = uVar6;
          local_14[3] = uVar7;
          local_14[4] = uVar8;
          local_14 = local_14 + 5;
          local_20 = local_20 + 1;
          local_1c = local_1c + -1;
          local_18 = local_18 + -4;
        } while (local_20 != iVar4);
      }
      local_5c = local_5c + 1;
      local_54 = local_54 + iVar10;
    } while (local_54 < param_2 + iVar10);
  }
  iVar3 = *(int *)(iVar3 + 0x2c);
  local_3c = param_3;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  uVar1 = param_3 + iVar4 * 4 * iVar9 * 4;
  if (param_3 < uVar1) {
    iVar9 = iVar4 + -1;
    local_40 = 1;
    do {
      *local_14 = 0x917;
      if (local_40 < 0x20) {
        local_14[1] = (uint)((**(uint **)(*(int *)(param_1 + 0x10) + 0x2d50) &
                             1 << ((byte)local_40 & 0x1f)) != 0);
      }
      else {
        if (local_40 < 0x40) {
          bVar12 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 4) &
                   1 << ((byte)local_40 - 0x20 & 0x1f)) == 0;
        }
        else if (local_40 < 0x60) {
          bVar12 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 8) &
                   1 << ((byte)local_40 - 0x40 & 0x1f)) == 0;
        }
        else {
          bVar12 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 0xc) &
                   1 << ((byte)local_40 + 0xa0 & 0x1f)) == 0;
        }
        local_14[1] = (uint)!bVar12;
      }
      local_14 = local_14 + 2;
      if (-1 < iVar9) {
        local_28 = (undefined4 *)(iVar3 + iVar9 * 4);
        local_24 = (undefined4 *)(iVar9 * 0x10 + local_3c);
        local_2c = 0;
        do {
          uVar2 = *local_24;
          uVar6 = local_24[1];
          uVar7 = local_24[2];
          uVar8 = local_24[3];
          *local_14 = *local_28;
          local_14[1] = uVar2;
          local_14[2] = uVar6;
          local_14[3] = uVar7;
          local_14[4] = uVar8;
          local_14 = local_14 + 5;
          local_2c = local_2c + 1;
          local_28 = local_28 + -1;
          local_24 = local_24 + -4;
        } while (local_2c != iVar4);
      }
      local_40 = local_40 + 1;
      local_3c = local_3c + iVar10;
    } while (local_3c < uVar1);
  }
  *local_14 = 0x92b;
  local_14[1] = 0;
  local_14[2] = 0x1393;
  local_14[3] = 0;
  *(undefined4 **)(param_1 + 0x298c) = local_14 + 4;
                    
                    
  (**(code **)(param_1 + 0x299c))();
  return;
}

/* FUN_00038dce @ 0x38dce (770 bytes) */
int FUN_00038dce(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  bool bVar10;
  uint local_30;
  uint local_24;
  int local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  
  iVar8 = ((int (*)())FUN_0002ab76)(param_1,0,4,param_3);
  if (iVar8 == 0) {
    return;
  }
  iVar4 = *(int *)(param_1 + 0x29e8);
  iVar5 = *(int *)(*(int *)(**(int **)(param_1 + 0x1cc) + 4) + 0x20);
  local_10 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar5 * iVar8 * 5 + iVar8 * 2 + 0x16 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe));
  *(undefined4 **)(param_1 + 0x298c) = local_10;
  if (*(int *)(param_1 + 0x2680) != param_1 + 0x1e24) {
    *(int *)(param_1 + 0x2680) = param_1 + 0x1e24;
    *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
    *(undefined4 *)(param_1 + 0x26cc) = *(undefined4 *)(param_1 + 0x1ee4);
    local_10 = (undefined4 *)((int (*)())FUN_0002a122)(param_1,local_10);
  }
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    *local_10 = 0x5c8;
    local_10[1] = 0x10000000;
    local_10 = local_10 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  *local_10 = 0x82c;
  local_10[1] = *(undefined4 *)(param_1 + 0x1dc4);
  local_10[2] = 0x821;
  local_10[3] = 4;
  local_10 = local_10 + 4;
  iVar4 = *(int *)(iVar4 + 0x2c);
  local_24 = param_2;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  uVar1 = param_2 + iVar8 * iVar5 * 4 * 4;
  if (param_2 < uVar1) {
    iVar8 = iVar5 + -1;
    local_30 = 0;
    do {
      *local_10 = 0x917;
      if (local_30 < 0x20) {
        local_10[1] = (uint)((**(uint **)(*(int *)(param_1 + 0x10) + 0x2d50) &
                             1 << ((byte)local_30 & 0x1f)) != 0);
      }
      else {
        if (local_30 < 0x40) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 4) &
                   1 << ((byte)local_30 - 0x20 & 0x1f)) == 0;
        }
        else if (local_30 < 0x60) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 8) &
                   1 << ((byte)local_30 - 0x40 & 0x1f)) == 0;
        }
        else {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 0xc) &
                   1 << ((byte)local_30 + 0xa0 & 0x1f)) == 0;
        }
        local_10[1] = (uint)!bVar10;
      }
      local_10 = local_10 + 2;
      if (-1 < iVar8) {
        local_14 = (undefined4 *)(iVar4 + iVar8 * 4);
        puVar9 = (undefined4 *)(local_24 + iVar8 * 0x10);
        local_18 = 0;
        do {
          uVar2 = *puVar9;
          uVar6 = puVar9[1];
          uVar7 = puVar9[2];
          uVar3 = puVar9[3];
          *local_10 = *local_14;
          local_10[1] = uVar2;
          local_10[2] = uVar6;
          local_10[3] = uVar7;
          local_10[4] = uVar3;
          local_10 = local_10 + 5;
          local_18 = local_18 + 1;
          local_14 = local_14 + -1;
          puVar9 = puVar9 + -4;
        } while (local_18 != iVar5);
      }
      local_30 = local_30 + 1;
      local_24 = local_24 + iVar5 * 0x10;
    } while (local_24 < uVar1);
  }
  *local_10 = 0x92b;
  local_10[1] = 0;
  local_10[2] = 0x1393;
  local_10[3] = 0;
  *(undefined4 **)(param_1 + 0x298c) = local_10 + 4;
                    
                    
  (**(code **)(param_1 + 0x299c))();
  return;
}

/* FUN_000390d0 @ 0x390d0 (770 bytes) */
int FUN_000390d0(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  bool bVar10;
  uint local_30;
  uint local_24;
  int local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  
  iVar8 = ((int (*)())FUN_0002ab76)(param_1,0,5,param_3);
  if (iVar8 == 0) {
    return;
  }
  iVar4 = *(int *)(param_1 + 0x29e8);
  iVar5 = *(int *)(*(int *)(**(int **)(param_1 + 0x1cc) + 4) + 0x20);
  local_10 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar5 * iVar8 * 5 + iVar8 * 2 + 0x16 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe));
  *(undefined4 **)(param_1 + 0x298c) = local_10;
  if (*(int *)(param_1 + 0x2680) != param_1 + 0x1e24) {
    *(int *)(param_1 + 0x2680) = param_1 + 0x1e24;
    *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
    *(undefined4 *)(param_1 + 0x26cc) = *(undefined4 *)(param_1 + 0x1ee4);
    local_10 = (undefined4 *)((int (*)())FUN_0002a122)(param_1,local_10);
  }
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    *local_10 = 0x5c8;
    local_10[1] = 0x10000000;
    local_10 = local_10 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  *local_10 = 0x82c;
  local_10[1] = *(undefined4 *)(param_1 + 0x1dc4);
  local_10[2] = 0x821;
  local_10[3] = 6;
  local_10 = local_10 + 4;
  iVar4 = *(int *)(iVar4 + 0x2c);
  local_24 = param_2;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  uVar1 = param_2 + iVar8 * iVar5 * 4 * 4;
  if (param_2 < uVar1) {
    iVar8 = iVar5 + -1;
    local_30 = 0;
    do {
      *local_10 = 0x917;
      if (local_30 < 0x20) {
        local_10[1] = (uint)((**(uint **)(*(int *)(param_1 + 0x10) + 0x2d50) &
                             1 << ((byte)local_30 & 0x1f)) != 0);
      }
      else {
        if (local_30 < 0x40) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 4) &
                   1 << ((byte)local_30 - 0x20 & 0x1f)) == 0;
        }
        else if (local_30 < 0x60) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 8) &
                   1 << ((byte)local_30 - 0x40 & 0x1f)) == 0;
        }
        else {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 0xc) &
                   1 << ((byte)local_30 + 0xa0 & 0x1f)) == 0;
        }
        local_10[1] = (uint)!bVar10;
      }
      local_10 = local_10 + 2;
      if (-1 < iVar8) {
        local_14 = (undefined4 *)(iVar4 + iVar8 * 4);
        puVar9 = (undefined4 *)(local_24 + iVar8 * 0x10);
        local_18 = 0;
        do {
          uVar2 = *puVar9;
          uVar6 = puVar9[1];
          uVar7 = puVar9[2];
          uVar3 = puVar9[3];
          *local_10 = *local_14;
          local_10[1] = uVar2;
          local_10[2] = uVar6;
          local_10[3] = uVar7;
          local_10[4] = uVar3;
          local_10 = local_10 + 5;
          local_18 = local_18 + 1;
          local_14 = local_14 + -1;
          puVar9 = puVar9 + -4;
        } while (local_18 != iVar5);
      }
      local_30 = local_30 + 1;
      local_24 = local_24 + iVar5 * 0x10;
    } while (local_24 < uVar1);
  }
  *local_10 = 0x92b;
  local_10[1] = 0;
  local_10[2] = 0x1393;
  local_10[3] = 0;
  *(undefined4 **)(param_1 + 0x298c) = local_10 + 4;
                    
                    
  (**(code **)(param_1 + 0x299c))();
  return;
}

/* FUN_000393d2 @ 0x393d2 (770 bytes) */
int FUN_000393d2(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  bool bVar10;
  uint local_30;
  uint local_24;
  int local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  
  iVar8 = ((int (*)())FUN_0002ab76)(param_1,0,7,param_3);
  if (iVar8 == 0) {
    return;
  }
  iVar4 = *(int *)(param_1 + 0x29e8);
  iVar5 = *(int *)(*(int *)(**(int **)(param_1 + 0x1cc) + 4) + 0x20);
  local_10 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar5 * iVar8 * 5 + iVar8 * 2 + 0x16 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe));
  *(undefined4 **)(param_1 + 0x298c) = local_10;
  if (*(int *)(param_1 + 0x2680) != param_1 + 0x1e24) {
    *(int *)(param_1 + 0x2680) = param_1 + 0x1e24;
    *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
    *(undefined4 *)(param_1 + 0x26cc) = *(undefined4 *)(param_1 + 0x1ee4);
    local_10 = (undefined4 *)((int (*)())FUN_0002a122)(param_1,local_10);
  }
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    *local_10 = 0x5c8;
    local_10[1] = 0x10000000;
    local_10 = local_10 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  *local_10 = 0x82c;
  local_10[1] = *(undefined4 *)(param_1 + 0x1dc4);
  local_10[2] = 0x821;
  local_10[3] = 0xd;
  local_10 = local_10 + 4;
  iVar4 = *(int *)(iVar4 + 0x2c);
  local_24 = param_2;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  uVar1 = param_2 + iVar8 * iVar5 * 4 * 4;
  if (param_2 < uVar1) {
    iVar8 = iVar5 + -1;
    local_30 = 0;
    do {
      *local_10 = 0x917;
      if (local_30 < 0x20) {
        local_10[1] = (uint)((**(uint **)(*(int *)(param_1 + 0x10) + 0x2d50) &
                             1 << ((byte)local_30 & 0x1f)) != 0);
      }
      else {
        if (local_30 < 0x40) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 4) &
                   1 << ((byte)local_30 - 0x20 & 0x1f)) == 0;
        }
        else if (local_30 < 0x60) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 8) &
                   1 << ((byte)local_30 - 0x40 & 0x1f)) == 0;
        }
        else {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 0xc) &
                   1 << ((byte)local_30 + 0xa0 & 0x1f)) == 0;
        }
        local_10[1] = (uint)!bVar10;
      }
      local_10 = local_10 + 2;
      if (-1 < iVar8) {
        local_14 = (undefined4 *)(iVar4 + iVar8 * 4);
        puVar9 = (undefined4 *)(local_24 + iVar8 * 0x10);
        local_18 = 0;
        do {
          uVar2 = *puVar9;
          uVar6 = puVar9[1];
          uVar7 = puVar9[2];
          uVar3 = puVar9[3];
          *local_10 = *local_14;
          local_10[1] = uVar2;
          local_10[2] = uVar6;
          local_10[3] = uVar7;
          local_10[4] = uVar3;
          local_10 = local_10 + 5;
          local_18 = local_18 + 1;
          local_14 = local_14 + -1;
          puVar9 = puVar9 + -4;
        } while (local_18 != iVar5);
      }
      local_30 = local_30 + 1;
      local_24 = local_24 + iVar5 * 0x10;
    } while (local_24 < uVar1);
  }
  *local_10 = 0x92b;
  local_10[1] = 0;
  local_10[2] = 0x1393;
  local_10[3] = 0;
  *(undefined4 **)(param_1 + 0x298c) = local_10 + 4;
                    
                    
  (**(code **)(param_1 + 0x299c))();
  return;
}

/* FUN_000396d4 @ 0x396d4 (770 bytes) */
int FUN_000396d4(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  bool bVar10;
  uint local_30;
  uint local_24;
  int local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  
  iVar8 = ((int (*)())FUN_0002ab76)(param_1,0,8,param_3);
  if (iVar8 == 0) {
    return;
  }
  iVar4 = *(int *)(param_1 + 0x29e8);
  iVar5 = *(int *)(*(int *)(**(int **)(param_1 + 0x1cc) + 4) + 0x20);
  local_10 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar5 * iVar8 * 5 + iVar8 * 2 + 0x16 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe));
  *(undefined4 **)(param_1 + 0x298c) = local_10;
  if (*(int *)(param_1 + 0x2680) != param_1 + 0x1e24) {
    *(int *)(param_1 + 0x2680) = param_1 + 0x1e24;
    *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
    *(undefined4 *)(param_1 + 0x26cc) = *(undefined4 *)(param_1 + 0x1ee4);
    local_10 = (undefined4 *)((int (*)())FUN_0002a122)(param_1,local_10);
  }
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    *local_10 = 0x5c8;
    local_10[1] = 0x10000000;
    local_10 = local_10 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  *local_10 = 0x82c;
  local_10[1] = *(undefined4 *)(param_1 + 0x1dc4);
  local_10[2] = 0x821;
  local_10[3] = 0xe;
  local_10 = local_10 + 4;
  iVar4 = *(int *)(iVar4 + 0x2c);
  local_24 = param_2;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  uVar1 = param_2 + iVar8 * iVar5 * 4 * 4;
  if (param_2 < uVar1) {
    iVar8 = iVar5 + -1;
    local_30 = 0;
    do {
      *local_10 = 0x917;
      if (local_30 < 0x20) {
        local_10[1] = (uint)((**(uint **)(*(int *)(param_1 + 0x10) + 0x2d50) &
                             1 << ((byte)local_30 & 0x1f)) != 0);
      }
      else {
        if (local_30 < 0x40) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 4) &
                   1 << ((byte)local_30 - 0x20 & 0x1f)) == 0;
        }
        else if (local_30 < 0x60) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 8) &
                   1 << ((byte)local_30 - 0x40 & 0x1f)) == 0;
        }
        else {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 0xc) &
                   1 << ((byte)local_30 + 0xa0 & 0x1f)) == 0;
        }
        local_10[1] = (uint)!bVar10;
      }
      local_10 = local_10 + 2;
      if (-1 < iVar8) {
        local_14 = (undefined4 *)(iVar4 + iVar8 * 4);
        puVar9 = (undefined4 *)(local_24 + iVar8 * 0x10);
        local_18 = 0;
        do {
          uVar2 = *puVar9;
          uVar6 = puVar9[1];
          uVar7 = puVar9[2];
          uVar3 = puVar9[3];
          *local_10 = *local_14;
          local_10[1] = uVar2;
          local_10[2] = uVar6;
          local_10[3] = uVar7;
          local_10[4] = uVar3;
          local_10 = local_10 + 5;
          local_18 = local_18 + 1;
          local_14 = local_14 + -1;
          puVar9 = puVar9 + -4;
        } while (local_18 != iVar5);
      }
      local_30 = local_30 + 1;
      local_24 = local_24 + iVar5 * 0x10;
    } while (local_24 < uVar1);
  }
  *local_10 = 0x92b;
  local_10[1] = 0;
  local_10[2] = 0x1393;
  local_10[3] = 0;
  *(undefined4 **)(param_1 + 0x298c) = local_10 + 4;
                    
                    
  (**(code **)(param_1 + 0x299c))();
  return;
}

/* FUN_000399d6 @ 0x399d6 (770 bytes) */
int FUN_000399d6(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  bool bVar10;
  uint local_30;
  uint local_24;
  int local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  
  iVar8 = ((int (*)())FUN_0002ab76)(param_1,0,9,param_3);
  if (iVar8 == 0) {
    return;
  }
  iVar4 = *(int *)(param_1 + 0x29e8);
  iVar5 = *(int *)(*(int *)(**(int **)(param_1 + 0x1cc) + 4) + 0x20);
  local_10 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar5 * iVar8 * 5 + iVar8 * 2 + 0x16 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe));
  *(undefined4 **)(param_1 + 0x298c) = local_10;
  if (*(int *)(param_1 + 0x2680) != param_1 + 0x1e24) {
    *(int *)(param_1 + 0x2680) = param_1 + 0x1e24;
    *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
    *(undefined4 *)(param_1 + 0x26cc) = *(undefined4 *)(param_1 + 0x1ee4);
    local_10 = (undefined4 *)((int (*)())FUN_0002a122)(param_1,local_10);
  }
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    *local_10 = 0x5c8;
    local_10[1] = 0x10000000;
    local_10 = local_10 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  *local_10 = 0x82c;
  local_10[1] = *(undefined4 *)(param_1 + 0x1dc4);
  local_10[2] = 0x821;
  local_10[3] = 0xf;
  local_10 = local_10 + 4;
  iVar4 = *(int *)(iVar4 + 0x2c);
  local_24 = param_2;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  uVar1 = param_2 + iVar8 * iVar5 * 4 * 4;
  if (param_2 < uVar1) {
    iVar8 = iVar5 + -1;
    local_30 = 0;
    do {
      *local_10 = 0x917;
      if (local_30 < 0x20) {
        local_10[1] = (uint)((**(uint **)(*(int *)(param_1 + 0x10) + 0x2d50) &
                             1 << ((byte)local_30 & 0x1f)) != 0);
      }
      else {
        if (local_30 < 0x40) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 4) &
                   1 << ((byte)local_30 - 0x20 & 0x1f)) == 0;
        }
        else if (local_30 < 0x60) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 8) &
                   1 << ((byte)local_30 - 0x40 & 0x1f)) == 0;
        }
        else {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 0xc) &
                   1 << ((byte)local_30 + 0xa0 & 0x1f)) == 0;
        }
        local_10[1] = (uint)!bVar10;
      }
      local_10 = local_10 + 2;
      if (-1 < iVar8) {
        local_14 = (undefined4 *)(iVar4 + iVar8 * 4);
        puVar9 = (undefined4 *)(local_24 + iVar8 * 0x10);
        local_18 = 0;
        do {
          uVar2 = *puVar9;
          uVar6 = puVar9[1];
          uVar7 = puVar9[2];
          uVar3 = puVar9[3];
          *local_10 = *local_14;
          local_10[1] = uVar2;
          local_10[2] = uVar6;
          local_10[3] = uVar7;
          local_10[4] = uVar3;
          local_10 = local_10 + 5;
          local_18 = local_18 + 1;
          local_14 = local_14 + -1;
          puVar9 = puVar9 + -4;
        } while (local_18 != iVar5);
      }
      local_30 = local_30 + 1;
      local_24 = local_24 + iVar5 * 0x10;
    } while (local_24 < uVar1);
  }
  *local_10 = 0x92b;
  local_10[1] = 0;
  local_10[2] = 0x1393;
  local_10[3] = 0;
  *(undefined4 **)(param_1 + 0x298c) = local_10 + 4;
                    
                    
  (**(code **)(param_1 + 0x299c))();
  return;
}

/* FUN_00039cd8 @ 0x39cd8 (770 bytes) */
int FUN_00039cd8(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  bool bVar10;
  uint local_30;
  uint local_24;
  int local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  
  iVar8 = ((int (*)())FUN_0002ab76)(param_1,0,0,param_3);
  if (iVar8 == 0) {
    return;
  }
  iVar4 = *(int *)(param_1 + 0x29e8);
  iVar5 = *(int *)(*(int *)(**(int **)(param_1 + 0x1cc) + 4) + 0x20);
  local_10 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar5 * iVar8 * 5 + iVar8 * 2 + 0x16 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe));
  *(undefined4 **)(param_1 + 0x298c) = local_10;
  if (*(int *)(param_1 + 0x2680) != param_1 + 0x1e24) {
    *(int *)(param_1 + 0x2680) = param_1 + 0x1e24;
    *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
    *(undefined4 *)(param_1 + 0x26cc) = *(undefined4 *)(param_1 + 0x1ee4);
    local_10 = (undefined4 *)((int (*)())FUN_0002a122)(param_1,local_10);
  }
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    *local_10 = 0x5c8;
    local_10[1] = 0x10000000;
    local_10 = local_10 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  *local_10 = 0x82c;
  local_10[1] = *(undefined4 *)(param_1 + 0x1dc4);
  local_10[2] = 0x821;
  local_10[3] = 1;
  local_10 = local_10 + 4;
  iVar4 = *(int *)(iVar4 + 0x2c);
  local_24 = param_2;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  uVar1 = param_2 + iVar8 * iVar5 * 4 * 4;
  if (param_2 < uVar1) {
    iVar8 = iVar5 + -1;
    local_30 = 0;
    do {
      *local_10 = 0x917;
      if (local_30 < 0x20) {
        local_10[1] = (uint)((**(uint **)(*(int *)(param_1 + 0x10) + 0x2d50) &
                             1 << ((byte)local_30 & 0x1f)) != 0);
      }
      else {
        if (local_30 < 0x40) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 4) &
                   1 << ((byte)local_30 - 0x20 & 0x1f)) == 0;
        }
        else if (local_30 < 0x60) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 8) &
                   1 << ((byte)local_30 - 0x40 & 0x1f)) == 0;
        }
        else {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 0xc) &
                   1 << ((byte)local_30 + 0xa0 & 0x1f)) == 0;
        }
        local_10[1] = (uint)!bVar10;
      }
      local_10 = local_10 + 2;
      if (-1 < iVar8) {
        local_14 = (undefined4 *)(iVar4 + iVar8 * 4);
        puVar9 = (undefined4 *)(local_24 + iVar8 * 0x10);
        local_18 = 0;
        do {
          uVar2 = *puVar9;
          uVar6 = puVar9[1];
          uVar7 = puVar9[2];
          uVar3 = puVar9[3];
          *local_10 = *local_14;
          local_10[1] = uVar2;
          local_10[2] = uVar6;
          local_10[3] = uVar7;
          local_10[4] = uVar3;
          local_10 = local_10 + 5;
          local_18 = local_18 + 1;
          local_14 = local_14 + -1;
          puVar9 = puVar9 + -4;
        } while (local_18 != iVar5);
      }
      local_30 = local_30 + 1;
      local_24 = local_24 + iVar5 * 0x10;
    } while (local_24 < uVar1);
  }
  *local_10 = 0x92b;
  local_10[1] = 0;
  local_10[2] = 0x1393;
  local_10[3] = 0;
  *(undefined4 **)(param_1 + 0x298c) = local_10 + 4;
                    
                    
  (**(code **)(param_1 + 0x299c))();
  return;
}

/* FUN_00039fda @ 0x39fda (770 bytes) */
int FUN_00039fda(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  bool bVar10;
  uint local_30;
  uint local_24;
  int local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  
  iVar8 = ((int (*)())FUN_0002ab76)(param_1,0,1,param_3);
  if (iVar8 == 0) {
    return;
  }
  iVar4 = *(int *)(param_1 + 0x29e8);
  iVar5 = *(int *)(*(int *)(**(int **)(param_1 + 0x1cc) + 4) + 0x20);
  local_10 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar5 * iVar8 * 5 + iVar8 * 2 + 0x16 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe));
  *(undefined4 **)(param_1 + 0x298c) = local_10;
  if (*(int *)(param_1 + 0x2680) != param_1 + 0x1e24) {
    *(int *)(param_1 + 0x2680) = param_1 + 0x1e24;
    *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
    *(undefined4 *)(param_1 + 0x26cc) = *(undefined4 *)(param_1 + 0x1ee4);
    local_10 = (undefined4 *)((int (*)())FUN_0002a122)(param_1,local_10);
  }
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    *local_10 = 0x5c8;
    local_10[1] = 0x10000000;
    local_10 = local_10 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  *local_10 = 0x82c;
  local_10[1] = *(undefined4 *)(param_1 + 0x1dc4);
  local_10[2] = 0x821;
  local_10[3] = 2;
  local_10 = local_10 + 4;
  iVar4 = *(int *)(iVar4 + 0x2c);
  local_24 = param_2;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  uVar1 = param_2 + iVar8 * iVar5 * 4 * 4;
  if (param_2 < uVar1) {
    iVar8 = iVar5 + -1;
    local_30 = 0;
    do {
      *local_10 = 0x917;
      if (local_30 < 0x20) {
        local_10[1] = (uint)((**(uint **)(*(int *)(param_1 + 0x10) + 0x2d50) &
                             1 << ((byte)local_30 & 0x1f)) != 0);
      }
      else {
        if (local_30 < 0x40) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 4) &
                   1 << ((byte)local_30 - 0x20 & 0x1f)) == 0;
        }
        else if (local_30 < 0x60) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 8) &
                   1 << ((byte)local_30 - 0x40 & 0x1f)) == 0;
        }
        else {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 0xc) &
                   1 << ((byte)local_30 + 0xa0 & 0x1f)) == 0;
        }
        local_10[1] = (uint)!bVar10;
      }
      local_10 = local_10 + 2;
      if (-1 < iVar8) {
        local_14 = (undefined4 *)(iVar4 + iVar8 * 4);
        puVar9 = (undefined4 *)(local_24 + iVar8 * 0x10);
        local_18 = 0;
        do {
          uVar2 = *puVar9;
          uVar6 = puVar9[1];
          uVar7 = puVar9[2];
          uVar3 = puVar9[3];
          *local_10 = *local_14;
          local_10[1] = uVar2;
          local_10[2] = uVar6;
          local_10[3] = uVar7;
          local_10[4] = uVar3;
          local_10 = local_10 + 5;
          local_18 = local_18 + 1;
          local_14 = local_14 + -1;
          puVar9 = puVar9 + -4;
        } while (local_18 != iVar5);
      }
      local_30 = local_30 + 1;
      local_24 = local_24 + iVar5 * 0x10;
    } while (local_24 < uVar1);
  }
  *local_10 = 0x92b;
  local_10[1] = 0;
  local_10[2] = 0x1393;
  local_10[3] = 0;
  *(undefined4 **)(param_1 + 0x298c) = local_10 + 4;
                    
                    
  (**(code **)(param_1 + 0x299c))();
  return;
}

/* FUN_0003a2dc @ 0x3a2dc (769 bytes) */
int FUN_0003a2dc(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  bool bVar10;
  uint local_30;
  uint local_24;
  int local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  
  iVar8 = ((int (*)())FUN_0002ab76)(param_1,param_4,2,param_3);
  if (iVar8 == 0) {
    return;
  }
  iVar4 = *(int *)(param_1 + 0x29e8);
  iVar5 = *(int *)(*(int *)(**(int **)(param_1 + 0x1cc) + 4) + 0x20);
  local_10 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar5 * iVar8 * 5 + iVar8 * 2 + 0x16 +
                        (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe));
  *(undefined4 **)(param_1 + 0x298c) = local_10;
  if (*(int *)(param_1 + 0x2680) != param_1 + 0x1e24) {
    *(int *)(param_1 + 0x2680) = param_1 + 0x1e24;
    *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
    *(undefined4 *)(param_1 + 0x26cc) = *(undefined4 *)(param_1 + 0x1ee4);
    local_10 = (undefined4 *)((int (*)())FUN_0002a122)(param_1,local_10);
  }
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    *local_10 = 0x5c8;
    local_10[1] = 0x10000000;
    local_10 = local_10 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  *local_10 = 0x82c;
  local_10[1] = *(undefined4 *)(param_1 + 0x1dc4);
  local_10[2] = 0x821;
  local_10[3] = 0xc;
  local_10 = local_10 + 4;
  iVar4 = *(int *)(iVar4 + 0x2c);
  local_24 = param_2;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  uVar1 = param_2 + iVar8 * iVar5 * 4 * 4;
  if (param_2 < uVar1) {
    iVar8 = iVar5 + -1;
    local_30 = 0;
    do {
      *local_10 = 0x917;
      if (local_30 < 0x20) {
        local_10[1] = (uint)((**(uint **)(*(int *)(param_1 + 0x10) + 0x2d50) &
                             1 << ((byte)local_30 & 0x1f)) != 0);
      }
      else {
        if (local_30 < 0x40) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 4) &
                   1 << ((byte)local_30 - 0x20 & 0x1f)) == 0;
        }
        else if (local_30 < 0x60) {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 8) &
                   1 << ((byte)local_30 - 0x40 & 0x1f)) == 0;
        }
        else {
          bVar10 = (*(uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x2d50) + 0xc) &
                   1 << ((byte)local_30 + 0xa0 & 0x1f)) == 0;
        }
        local_10[1] = (uint)!bVar10;
      }
      local_10 = local_10 + 2;
      if (-1 < iVar8) {
        local_14 = (undefined4 *)(iVar4 + iVar8 * 4);
        puVar9 = (undefined4 *)(local_24 + iVar8 * 0x10);
        local_18 = 0;
        do {
          uVar2 = *puVar9;
          uVar6 = puVar9[1];
          uVar7 = puVar9[2];
          uVar3 = puVar9[3];
          *local_10 = *local_14;
          local_10[1] = uVar2;
          local_10[2] = uVar6;
          local_10[3] = uVar7;
          local_10[4] = uVar3;
          local_10 = local_10 + 5;
          local_18 = local_18 + 1;
          local_14 = local_14 + -1;
          puVar9 = puVar9 + -4;
        } while (local_18 != iVar5);
      }
      local_30 = local_30 + 1;
      local_24 = local_24 + iVar5 * 0x10;
    } while (local_24 < uVar1);
  }
  *local_10 = 0x92b;
  local_10[1] = 0;
  local_10[2] = 0x1393;
  local_10[3] = 0;
  *(undefined4 **)(param_1 + 0x298c) = local_10 + 4;
                    
                    
  (**(code **)(param_1 + 0x299c))();
  return;
}

/* FUN_0003a5dd @ 0x3a5dd (311 bytes) */
int FUN_0003a5dd(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  piVar1 = *(int **)(param_1 + 0x1cc);
  if ((param_2 == 0) || ((*(uint *)(param_2 + 0xc) & 0x4400000) != 0)) {
    uVar4 = 2;
  }
  else {
    uVar4 = 0;
  }
  if ((piVar1 != (int *)0x0) &&
     (((param_2 == 0 || ((*(ushort *)(param_2 + 8) & 0xff00) != 0)) ||
      ((*(uint *)(param_2 + 0xc) & 0x4c00000) != 0)))) {
    uVar4 = uVar4 | 1;
  }
  FUN_00051e3f(param_1 + 0x240,uVar4);
  iVar2 = *(int *)(param_1 + 0x29e8) + 0x14;
  if ((uVar4 & 1) != 0) {
    iVar3 = piVar1[0xd];
    if (((iVar3 == 0) && (iVar3 = piVar1[0xc], iVar3 == 0)) && (iVar3 = piVar1[0xb], iVar3 == 0)) {
      iVar3 = *(int *)(*piVar1 + 4);
    }
    if ((uVar4 & 2) != 0) {
      FUN_0003ad08(param_1,iVar2,*(undefined4 *)(iVar3 + 0x28),iVar3 + *(int *)(iVar3 + 0x2c) * 8,
                   *(undefined4 *)(*piVar1 + 0x18));
      return param_3;
    }
    FUN_0003cca2(param_1,iVar2,*(undefined4 *)(iVar3 + 0x28),iVar3 + *(int *)(iVar3 + 0x2c) * 8,
                 *(undefined4 *)(*piVar1 + 0x18),param_2 + 0x14);
  }
  return param_3;
}

