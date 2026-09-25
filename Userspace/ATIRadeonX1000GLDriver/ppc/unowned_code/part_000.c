#include "decls.h"

/* orph_98d8 @ 0x98d8 (16 bytes) */
int orph_98d8(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  int in_r11;
  
  *param_3 = in_r11 * 0x240 + 0x28d0;
  return;
}

/* orph_98e8 @ 0x98e8 (16 bytes) */
int orph_98e8(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  int in_r11;
  
  *param_3 = in_r11 * 0x240 + 0x28e0;
  return;
}

/* orph_98f8 @ 0x98f8 (16 bytes) */
int orph_98f8(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  int in_r11;
  
  *param_3 = in_r11 * 0x240 + 0x28f0;
  return;
}

/* orph_9908 @ 0x9908 (16 bytes) */
int orph_9908(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  int in_r11;
  
  *param_3 = in_r11 * 0x240 + 0x2900;
  return;
}

/* orph_9918 @ 0x9918 (16 bytes) */
int orph_9918(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  int in_r11;
  
  *param_3 = in_r11 * 0x240 + 0x2a90;
  return;
}

/* orph_9930 @ 0x9930 (120 bytes) */
int orph_9930(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  uint uVar1;
  uint uVar2;
  uint uStack_18;
  
  uVar2 = uStack_18 >> 5 & 7;
  uVar1 = uStack_18 & 0x1f;
  if (uVar2 == 1) {
    *param_3 = ((unsigned char *)0x000039b0) + uVar1 * 0x94;
    return;
  }
  if (uVar2 < 2) {
    if (uVar2 != 0) {
      return;
    }
    *param_3 = ((unsigned char *)0x0000398c) + uVar1 * 0x94;
    return;
  }
  if (uVar2 == 2) {
    *param_3 = ((unsigned char *)0x000039d4) + uVar1 * 0x94;
    return;
  }
  if (uVar2 != 3) {
    return;
  }
  *param_3 = ((unsigned char *)0x000039f8) + uVar1 * 0x94;
  return;
}

/* orph_9954 @ 0x9954 (52 bytes) */
int orph_9954(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  int in_r0;
  int in_r9;
  
  if (in_r9 == 2) {
    *param_3 = ((unsigned char *)0x000039d4) + in_r0 * 0x94;
    return;
  }
  if (in_r9 != 3) {
    return;
  }
  *param_3 = ((unsigned char *)0x000039f8) + in_r0 * 0x94;
  return;
}

/* orph_9968 @ 0x9968 (16 bytes) */
int orph_9968(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  int in_r0;
  
  *param_3 = ((unsigned char *)0x0000398c) + in_r0 * 0x94;
  return;
}

/* orph_9978 @ 0x9978 (16 bytes) */
int orph_9978(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  int in_r0;
  
  *param_3 = ((unsigned char *)0x000039b0) + in_r0 * 0x94;
  return;
}

/* orph_9988 @ 0x9988 (16 bytes) */
int orph_9988(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  int in_r0;
  
  *param_3 = ((unsigned char *)0x000039d4) + in_r0 * 0x94;
  return;
}

/* orph_9998 @ 0x9998 (16 bytes) */
int orph_9998(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  int in_r0;
  
  *param_3 = ((unsigned char *)0x000039f8) + in_r0 * 0x94;
  return;
}

/* orph_99a8 @ 0x99a8 (120 bytes) */
int orph_99a8(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  uint uVar1;
  uint uVar2;
  uint uStack_18;
  
  uVar2 = uStack_18 >> 5 & 7;
  uVar1 = uStack_18 & 0x1f;
  if (uVar2 == 1) {
    *param_3 = ((unsigned char *)0x000039c0) + uVar1 * 0x94;
    return;
  }
  if (uVar2 < 2) {
    if (uVar2 != 0) {
      return;
    }
    *param_3 = ((unsigned char *)0x0000399c) + uVar1 * 0x94;
    return;
  }
  if (uVar2 == 2) {
    *param_3 = ((unsigned char *)0x000039e4) + uVar1 * 0x94;
    return;
  }
  if (uVar2 != 3) {
    return;
  }
  *param_3 = ((unsigned char *)0x00003a08) + uVar1 * 0x94;
  return;
}

/* orph_99cc @ 0x99cc (52 bytes) */
int orph_99cc(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  int in_r0;
  int in_r9;
  
  if (in_r9 == 2) {
    *param_3 = ((unsigned char *)0x000039e4) + in_r0 * 0x94;
    return;
  }
  if (in_r9 != 3) {
    return;
  }
  *param_3 = ((unsigned char *)0x00003a08) + in_r0 * 0x94;
  return;
}

/* orph_99e0 @ 0x99e0 (16 bytes) */
int orph_99e0(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  int in_r0;
  
  *param_3 = ((unsigned char *)0x0000399c) + in_r0 * 0x94;
  return;
}

/* orph_99f0 @ 0x99f0 (16 bytes) */
int orph_99f0(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  int in_r0;
  
  *param_3 = ((unsigned char *)0x000039c0) + in_r0 * 0x94;
  return;
}

/* orph_9a00 @ 0x9a00 (16 bytes) */
int orph_9a00(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  int in_r0;
  
  *param_3 = ((unsigned char *)0x000039e4) + in_r0 * 0x94;
  return;
}

/* orph_9a10 @ 0x9a10 (16 bytes) */
int orph_9a10(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  int in_r0;
  
  *param_3 = ((unsigned char *)0x00003a08) + in_r0 * 0x94;
  return;
}

/* orph_9a20 @ 0x9a20 (20 bytes) */
int orph_9a20(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  byte bStack_15;
  
  *param_3 = ((unsigned char *)0x00003e2c) + (uint)bStack_15 * 0x10;
  return;
}

/* orph_9a34 @ 0x9a34 (12 bytes) */
int orph_9a34(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  *param_3 = ((unsigned char *)0x00002de0);
  return;
}

/* orph_9a40 @ 0x9a40 (12 bytes) */
int orph_9a40(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  *param_3 = ((unsigned char *)0x00002df0);
  return;
}

/* orph_9a4c @ 0x9a4c (12 bytes) */
int orph_9a4c(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  *param_3 = 0x24b0;
  return;
}

/* orph_9a58 @ 0x9a58 (12 bytes) */
int orph_9a58(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  *param_3 = ((unsigned char *)0x000030bc);
  return;
}

/* orph_9a64 @ 0x9a64 (12 bytes) */
int orph_9a64(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  *param_3 = ((unsigned char *)0x000030cc);
  return;
}

/* orph_9a70 @ 0x9a70 (168 bytes) */
int orph_9a70(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
  undefined4 *param_4;
  undefined4 param_5;
  int param_6;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uStack_18;
  
  uVar3 = uStack_18 >> 8 & 7;
  iVar1 = (uStack_18 & 0xff) * 0x40;
  if (uVar3 < 6) {
                    
                    
    (*(code *)(*(int *)(uVar3 * 4 + param_6 + 0x3e0) + param_6 + 0x3e0))();
    return;
  }
  uVar3 = uStack_18 >> 0xe & 3;
  if (uVar3 < 2) {
    *param_3 = iVar1 + 0x1860;
  }
  else {
    *param_3 = iVar1 + 0x1e60;
  }
  uVar2 = uStack_18 >> 0xc & 3;
  if (uVar3 < 3) {
    if (uVar3 != 0) {
      *param_3 = uVar2 * 0x10 + *param_3;
      return;
    }
  }
  else if (uVar3 != 3) {
    return;
  }
  *param_3 = uVar2 * 4 + *param_3;
  *param_4 = 0x10;
  return;
}

/* orph_9aa4 @ 0x9aa4 (1 bytes) */
int orph_9aa4()
{
                    
  halt_baddata();
}

/* orph_9ac4 @ 0x9ac4 (124 bytes) */
int orph_9ac4(param_1, param_2, param_3, param_4)
  uint param_1;
  undefined4 param_2;
  int *param_3;
  undefined4 *param_4;
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 >> 0xe & 3;
  if (uVar1 < 2) {
    *param_3 = 0x1920;
  }
  else {
    *param_3 = 0x1f20;
  }
  uVar2 = param_1 >> 0xc & 3;
  if (uVar1 < 3) {
    if (uVar1 != 0) {
      *param_3 = uVar2 * 0x10 + *param_3;
      return;
    }
  }
  else if (uVar1 != 3) {
    return;
  }
  *param_3 = uVar2 * 4 + *param_3;
  *param_4 = 0x10;
  return;
}

/* orph_9acc @ 0x9acc (128 bytes) */
int orph_9acc(param_1, param_2, param_3, param_4)
  uint param_1;
  undefined4 param_2;
  int *param_3;
  undefined4 *param_4;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int in_r10;
  
  iVar1 = (in_r10 + 4) * 0x40;
  uVar2 = param_1 >> 0xe & 3;
  if (uVar2 < 2) {
    *param_3 = iVar1 + 0x1860;
  }
  else {
    *param_3 = iVar1 + 0x1e60;
  }
  uVar3 = param_1 >> 0xc & 3;
  if (uVar2 < 3) {
    if (uVar2 != 0) {
      *param_3 = uVar3 * 0x10 + *param_3;
      return;
    }
  }
  else if (uVar2 != 3) {
    return;
  }
  *param_3 = uVar3 * 4 + *param_3;
  *param_4 = 0x10;
  return;
}

/* orph_9ad8 @ 0x9ad8 (124 bytes) */
int orph_9ad8(param_1, param_2, param_3, param_4)
  uint param_1;
  undefined4 param_2;
  int *param_3;
  undefined4 *param_4;
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 >> 0xe & 3;
  if (uVar1 < 2) {
    *param_3 = 0x18e0;
  }
  else {
    *param_3 = 0x1ee0;
  }
  uVar2 = param_1 >> 0xc & 3;
  if (uVar1 < 3) {
    if (uVar1 != 0) {
      *param_3 = uVar2 * 0x10 + *param_3;
      return;
    }
  }
  else if (uVar1 != 3) {
    return;
  }
  *param_3 = uVar2 * 4 + *param_3;
  *param_4 = 0x10;
  return;
}

/* orph_9ae0 @ 0x9ae0 (128 bytes) */
int orph_9ae0(param_1, param_2, param_3, param_4)
  uint param_1;
  undefined4 param_2;
  int *param_3;
  undefined4 *param_4;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int in_r10;
  
  iVar1 = (in_r10 + 0x10) * 0x40;
  uVar2 = param_1 >> 0xe & 3;
  if (uVar2 < 2) {
    *param_3 = iVar1 + 0x1860;
  }
  else {
    *param_3 = iVar1 + 0x1e60;
  }
  uVar3 = param_1 >> 0xc & 3;
  if (uVar2 < 3) {
    if (uVar2 != 0) {
      *param_3 = uVar3 * 0x10 + *param_3;
      return;
    }
  }
  else if (uVar2 != 3) {
    return;
  }
  *param_3 = uVar3 * 4 + *param_3;
  *param_4 = 0x10;
  return;
}

/* orph_9aec @ 0x9aec (124 bytes) */
int orph_9aec(param_1, param_2, param_3, param_4)
  uint param_1;
  undefined4 param_2;
  int *param_3;
  undefined4 *param_4;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int in_r10;
  
  iVar1 = (in_r10 + 8) * 0x40;
  uVar2 = param_1 >> 0xe & 3;
  if (uVar2 < 2) {
    *param_3 = iVar1 + 0x1860;
  }
  else {
    *param_3 = iVar1 + 0x1e60;
  }
  uVar3 = param_1 >> 0xc & 3;
  if (uVar2 < 3) {
    if (uVar2 != 0) {
      *param_3 = uVar3 * 0x10 + *param_3;
      return;
    }
  }
  else if (uVar2 != 3) {
    return;
  }
  *param_3 = uVar3 * 4 + *param_3;
  *param_4 = 0x10;
  return;
}

/* orph_9b0c @ 0x9b0c (92 bytes) */
int orph_9b0c(param_1, param_2, param_3, param_4)
  uint param_1;
  undefined4 param_2;
  int *param_3;
  undefined4 *param_4;
{
  int unaff_r2;
  uint uVar1;
  int in_r11;
  byte in_cr6;
  
  *param_3 = in_r11 + 0x1860;
  uVar1 = param_1 >> 0xc & 3;
  if (unaff_r2 < 3) {
    if (!(bool)(in_cr6 >> 3 & 1)) {
      *param_3 = uVar1 * 0x10 + *param_3;
      return;
    }
    if (unaff_r2 != 0) {
      return;
    }
  }
  else if (unaff_r2 != 3) {
    return;
  }
  *param_3 = uVar1 * 4 + *param_3;
  *param_4 = 0x10;
  return;
}

/* orph_9b30 @ 0x9b30 (36 bytes) */
int orph_9b30(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int *param_3;
  undefined4 *param_4;
{
  int unaff_r2;
  
  if (unaff_r2 != 3) {
    return;
  }
  *param_3 = param_1 * 4 + *param_3;
  *param_4 = 0x10;
  return;
}

/* orph_9b54 @ 0x9b54 (20 bytes) */
int orph_9b54(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int *param_3;
{
  *param_3 = param_1 * 0x10 + *param_3;
  return;
}

/* orph_9b68 @ 0x9b68 (1 bytes) */
int orph_9b68()
{
                    
  halt_baddata();
}

/* orph_40a9c @ 0x40a9c (32 bytes) */
int orph_40a9c(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_r21;
  undefined4 unaff_r22;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  int *piVar10;
  
  param_3[6] = param_3[6] & 0xffff7777 | 0x100000;
  uVar6 = 1;
  if ((param_1[5] & 0x20000000U) != 0) {
    uVar6 = (*(uint *)(param_2 * 8 + *param_1 + *(int *)(*param_1 + 0x54) * 8 + 4) >> 0x1a & 3) + 1;
  }
  uVar9 = param_3[6];
  if (1 < uVar6) {
    iVar4 = param_1[8];
    unaff_r22 = param_3[1];
    unaff_r21 = param_3[2];
    param_3[1] = 0x40000;
    *(short *)((int)param_3 + 6) = (short)iVar4;
    param_3[2] = 0x55;
    param_3[1] = param_3[1] | 0x400000;
  }
  uVar3 = uVar9 >> 3 & 1;
  puVar8 = param_3 + 6;
  param_3[6] = uVar3 << 0xf |
               (uVar9 & 7) << 0xc |
               uVar3 << 0xb |
               (uVar9 & 7) << 8 | uVar3 << 7 | (uVar9 & 7) << 4 | uVar3 << 3 | uVar9 & 0xffff0007;
  if (param_1[9] == 0) {
    piVar10 = param_1 + 10;
    iVar4 = param_1[0xb];
    uVar3 = param_1[0xc];
    if (uVar3 < iVar4 + 5U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 5U; uVar3 = uVar3 << 1) {
      }
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar3 << 2);
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar3 << 2);
      }
      if (pvVar2 == (void *)0x0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00040524;
      }
      *piVar10 = (int)pvVar2;
      param_1[0xc] = uVar3;
      iVar4 = param_1[0xb];
    }
    param_1[0xb] = iVar4 + 5;
    puVar1 = (undefined4 *)(iVar4 * 4 + *piVar10);
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1[3] = param_3[3];
    puVar1[4] = param_3[6];
  }
LAB_00040524:
  if (1 >= uVar6) {
    return param_1[9];
  }
  uVar3 = uVar9 >> 4 & 7;
  uVar5 = uVar9 >> 7 & 1;
  puVar7 = param_3 + 2;
  param_3[2] = param_3[2] & 0xfffffffc;
  *puVar8 = uVar5 << 0xf |
            uVar3 << 0xc |
            uVar5 << 0xb |
            uVar3 << 8 | uVar5 << 7 | uVar3 << 4 | uVar5 << 3 | uVar3 | *puVar8 & 0xffff0000;
  if (param_1[9] == 0) {
    piVar10 = param_1 + 10;
    iVar4 = param_1[0xb];
    uVar3 = param_1[0xc];
    if (uVar3 < iVar4 + 5U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 5U; uVar3 = uVar3 << 1) {
      }
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar3 << 2);
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar3 << 2);
      }
      if (pvVar2 == (void *)0x0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00040664;
      }
      *piVar10 = (int)pvVar2;
      param_1[0xc] = uVar3;
      iVar4 = param_1[0xb];
    }
    param_1[0xb] = iVar4 + 5;
    puVar1 = (undefined4 *)(iVar4 * 4 + *piVar10);
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1[3] = param_3[3];
    puVar1[4] = param_3[6];
  }
LAB_00040664:
  if (uVar6 < 3) goto LAB_000408d0;
  uVar3 = uVar9 >> 8 & 7;
  uVar5 = uVar9 >> 0xb & 1;
  *puVar7 = *puVar7 & 0xfffffff3;
  *puVar8 = uVar5 << 0xf |
            uVar3 << 0xc |
            uVar5 << 0xb |
            uVar3 << 8 | uVar5 << 7 | uVar3 << 4 | uVar5 << 3 | uVar3 | *puVar8 & 0xffff0000;
  if (param_1[9] == 0) {
    piVar10 = param_1 + 10;
    iVar4 = param_1[0xb];
    uVar3 = param_1[0xc];
    if (uVar3 < iVar4 + 5U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 5U; uVar3 = uVar3 << 1) {
      }
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar3 << 2);
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar3 << 2);
      }
      if (pvVar2 == (void *)0x0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00040794;
      }
      *piVar10 = (int)pvVar2;
      param_1[0xc] = uVar3;
      iVar4 = param_1[0xb];
    }
    param_1[0xb] = iVar4 + 5;
    puVar1 = (undefined4 *)(iVar4 * 4 + *piVar10);
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1[3] = param_3[3];
    puVar1[4] = param_3[6];
  }
LAB_00040794:
  if (uVar6 == 4) {
    uVar6 = uVar9 >> 0xc & 7;
    uVar9 = uVar9 >> 0xf & 1;
    *puVar7 = *puVar7 & 0xffffffcf;
    *puVar8 = uVar9 << 0xf |
              uVar6 << 0xc |
              uVar9 << 0xb |
              uVar6 << 8 | uVar9 << 7 | uVar6 << 4 | uVar9 << 3 | uVar6 | *puVar8 & 0xffff0000;
    if (param_1[9] == 0) {
      piVar10 = param_1 + 10;
      iVar4 = param_1[0xb];
      uVar6 = param_1[0xc];
      if (uVar6 < iVar4 + 5U) {
        if (uVar6 == 0) {
          uVar6 = 0x10;
        }
        else {
          uVar6 = uVar6 << 1;
        }
        for (; uVar6 < iVar4 + 5U; uVar6 = uVar6 << 1) {
        }
        if ((void *)*piVar10 == (void *)0x0) {
          pvVar2 = _malloc(uVar6 << 2);
        }
        else {
          pvVar2 = _realloc((void *)*piVar10,uVar6 << 2);
        }
        if (pvVar2 == (void *)0x0) {
          if (param_1[9] == 0) {
            param_1[9] = 1;
          }
          goto LAB_000408d0;
        }
        *piVar10 = (int)pvVar2;
        param_1[0xc] = uVar6;
        iVar4 = param_1[0xb];
      }
      param_1[0xb] = iVar4 + 5;
      puVar1 = (undefined4 *)(iVar4 * 4 + *piVar10);
      *puVar1 = *param_3;
      puVar1[1] = param_3[1];
      puVar1[2] = param_3[2];
      puVar1[3] = param_3[3];
      puVar1[4] = param_3[6];
    }
  }
LAB_000408d0:
  iVar4 = param_1[8];
  param_3[3] = 0;
  *puVar8 = 0;
  param_3[3] = param_3[3] & 0xffc0ffff | 0x40000;
  *(short *)((int)param_3 + 0xe) = (short)iVar4;
  param_3[3] = param_3[3] | 0x400000;
  *puVar8 = *puVar8 & 0xffff0000 | 0x3210;
  *param_3 = 0;
  param_3[1] = unaff_r22;
  param_3[2] = unaff_r21;
  *(undefined2 *)((int)param_3 + 2) = 0x47;
  iVar4 = param_1[9];
  if (iVar4 == 0) {
    piVar10 = param_1 + 10;
    iVar4 = param_1[0xb];
    uVar6 = param_1[0xc];
    if (uVar6 < iVar4 + 5U) {
      if (uVar6 == 0) {
        uVar6 = 0x10;
      }
      else {
        uVar6 = uVar6 << 1;
      }
      for (; uVar6 < iVar4 + 5U; uVar6 = uVar6 << 1) {
      }
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar6 << 2);
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar6 << 2);
      }
      if (pvVar2 == (void *)0x0) {
        if (param_1[9] != 0) {
          return param_1[9];
        }
        param_1[9] = 1;
        return 1;
      }
      *piVar10 = (int)pvVar2;
      param_1[0xc] = uVar6;
      iVar4 = param_1[0xb];
    }
    param_1[0xb] = iVar4 + 5;
    puVar1 = (undefined4 *)(iVar4 * 4 + *piVar10);
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1[3] = param_3[3];
    puVar1[4] = param_3[6];
    iVar4 = param_1[9];
  }
  return iVar4;
}

/* orph_40ac0 @ 0x40ac0 (4 bytes) */
int orph_40ac0(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  bool bVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 unaff_r19;
  undefined4 unaff_r20;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  uint *puVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  
  uVar12 = 1;
  if ((param_1[5] & 0x20000000U) != 0) {
    uVar12 = (*(uint *)(param_2 * 8 + *param_1 + *(int *)(*param_1 + 0x54) * 8 + 4) >> 0x1a & 3) + 1
    ;
  }
  uVar17 = param_3[6];
  uVar16 = param_3[7];
  if (uVar12 >= 2) {
    iVar8 = param_1[8];
    unaff_r20 = param_3[1];
    unaff_r19 = param_3[2];
    param_3[1] = 0x40000;
    *(short *)((int)param_3 + 6) = (short)iVar8;
    param_3[2] = 0x55;
    param_3[1] = param_3[1] | 0x400000;
  }
  uVar5 = uVar17 >> 3 & 1;
  uVar9 = uVar16 >> 3 & 1;
  puVar15 = param_3 + 6;
  puVar14 = param_3 + 7;
  param_3[6] = uVar5 << 0xf |
               (uVar17 & 7) << 0xc |
               uVar5 << 0xb |
               (uVar17 & 7) << 8 | uVar5 << 7 | (uVar17 & 7) << 4 | uVar5 << 3 | uVar17 & 0xffff0007
  ;
  param_3[7] = uVar9 << 0xf |
               (uVar16 & 7) << 0xc |
               uVar9 << 0xb |
               (uVar16 & 7) << 8 | uVar9 << 7 | (uVar16 & 7) << 4 | uVar9 << 3 | uVar16 & 0xffff0007
  ;
  if (param_1[9] == 0) {
    piVar18 = param_1 + 10;
    iVar8 = param_1[0xb];
    uVar5 = param_1[0xc];
    if (uVar5 < iVar8 + 7U) {
      if (uVar5 == 0) {
        uVar5 = 0x10;
      }
      else {
        uVar5 = uVar5 << 1;
      }
      for (; uVar5 < iVar8 + 7U; uVar5 = uVar5 << 1) {
      }
      if ((void *)*piVar18 == (void *)0x0) {
        pvVar3 = _malloc(uVar5 << 2);
      }
      else {
        pvVar3 = _realloc((void *)*piVar18,uVar5 << 2);
      }
      if (pvVar3 == (void *)0x0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00040cf0;
      }
      *piVar18 = (int)pvVar3;
      param_1[0xc] = uVar5;
      iVar8 = param_1[0xb];
    }
    iVar4 = 0;
    param_1[0xb] = iVar8 + 7;
    puVar11 = (undefined4 *)(iVar8 * 4 + *piVar18);
    *puVar11 = *param_3;
    puVar11[1] = param_3[1];
    puVar11[2] = param_3[2];
    puVar7 = param_3;
    do {
      bVar2 = iVar4 != 1;
      iVar4 = iVar4 + 1;
      puVar11[3] = puVar7[3];
      puVar1 = puVar7 + 6;
      puVar7 = puVar7 + 1;
      puVar11[4] = *puVar1;
      puVar11 = puVar11 + 2;
    } while (bVar2);
  }
LAB_00040cf0:
  if (uVar12 < 2) {
    return param_1[9];
  }
  uVar9 = uVar17 >> 4 & 7;
  uVar10 = uVar17 >> 7 & 1;
  uVar6 = uVar16 >> 4 & 7;
  uVar5 = uVar16 >> 7 & 1;
  puVar13 = param_3 + 2;
  param_3[2] = param_3[2] & 0xfffffffc;
  *puVar15 = uVar10 << 0xf |
             uVar9 << 0xc |
             uVar10 << 0xb |
             uVar9 << 8 | uVar10 << 7 | uVar9 << 4 | uVar10 << 3 | uVar9 | *puVar15 & 0xffff0000;
  *puVar14 = uVar5 << 0xf |
             uVar6 << 0xc |
             uVar5 << 0xb |
             uVar6 << 8 | uVar5 << 7 | uVar6 << 4 | uVar5 << 3 | uVar6 | *puVar14 & 0xffff0000;
  if (param_1[9] == 0) {
    piVar18 = param_1 + 10;
    iVar8 = param_1[0xb];
    uVar5 = param_1[0xc];
    if (uVar5 < iVar8 + 7U) {
      if (uVar5 == 0) {
        uVar5 = 0x10;
      }
      else {
        uVar5 = uVar5 << 1;
      }
      for (; uVar5 < iVar8 + 7U; uVar5 = uVar5 << 1) {
      }
      if ((void *)*piVar18 == (void *)0x0) {
        pvVar3 = _malloc(uVar5 << 2);
      }
      else {
        pvVar3 = _realloc((void *)*piVar18,uVar5 << 2);
      }
      if (pvVar3 == (void *)0x0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00040e70;
      }
      *piVar18 = (int)pvVar3;
      param_1[0xc] = uVar5;
      iVar8 = param_1[0xb];
    }
    iVar4 = 0;
    param_1[0xb] = iVar8 + 7;
    puVar11 = (undefined4 *)(iVar8 * 4 + *piVar18);
    *puVar11 = *param_3;
    puVar11[1] = param_3[1];
    puVar11[2] = param_3[2];
    puVar7 = param_3;
    do {
      bVar2 = iVar4 != 1;
      iVar4 = iVar4 + 1;
      puVar11[3] = puVar7[3];
      puVar1 = puVar7 + 6;
      puVar7 = puVar7 + 1;
      puVar11[4] = *puVar1;
      puVar11 = puVar11 + 2;
    } while (bVar2);
  }
LAB_00040e70:
  if (uVar12 < 3) goto LAB_00041170;
  uVar9 = uVar17 >> 8 & 7;
  uVar10 = uVar17 >> 0xb & 1;
  uVar6 = uVar16 >> 8 & 7;
  uVar5 = uVar16 >> 0xb & 1;
  *puVar13 = *puVar13 & 0xfffffff3;
  *puVar15 = uVar10 << 0xf |
             uVar9 << 0xc |
             uVar10 << 0xb |
             uVar9 << 8 | uVar10 << 7 | uVar9 << 4 | uVar10 << 3 | uVar9 | *puVar15 & 0xffff0000;
  *puVar14 = uVar5 << 0xf |
             uVar6 << 0xc |
             uVar5 << 0xb |
             uVar6 << 8 | uVar5 << 7 | uVar6 << 4 | uVar5 << 3 | uVar6 | *puVar14 & 0xffff0000;
  if (param_1[9] == 0) {
    piVar18 = param_1 + 10;
    iVar8 = param_1[0xb];
    uVar5 = param_1[0xc];
    if (uVar5 < iVar8 + 7U) {
      if (uVar5 == 0) {
        uVar5 = 0x10;
      }
      else {
        uVar5 = uVar5 << 1;
      }
      for (; uVar5 < iVar8 + 7U; uVar5 = uVar5 << 1) {
      }
      if ((void *)*piVar18 == (void *)0x0) {
        pvVar3 = _malloc(uVar5 << 2);
      }
      else {
        pvVar3 = _realloc((void *)*piVar18,uVar5 << 2);
      }
      if (pvVar3 == (void *)0x0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00040ff0;
      }
      *piVar18 = (int)pvVar3;
      param_1[0xc] = uVar5;
      iVar8 = param_1[0xb];
    }
    iVar4 = 0;
    param_1[0xb] = iVar8 + 7;
    puVar11 = (undefined4 *)(iVar8 * 4 + *piVar18);
    *puVar11 = *param_3;
    puVar11[1] = param_3[1];
    puVar11[2] = param_3[2];
    puVar7 = param_3;
    do {
      bVar2 = iVar4 != 1;
      iVar4 = iVar4 + 1;
      puVar11[3] = puVar7[3];
      puVar1 = puVar7 + 6;
      puVar7 = puVar7 + 1;
      puVar11[4] = *puVar1;
      puVar11 = puVar11 + 2;
    } while (bVar2);
  }
LAB_00040ff0:
  if (uVar12 == 4) {
    uVar5 = uVar17 >> 0xc & 7;
    uVar9 = uVar17 >> 0xf & 1;
    uVar17 = uVar16 >> 0xc & 7;
    uVar12 = uVar16 >> 0xf & 1;
    *puVar13 = *puVar13 & 0xffffffcf;
    *puVar15 = uVar9 << 0xf |
               uVar5 << 0xc |
               uVar9 << 0xb |
               uVar5 << 8 | uVar9 << 7 | uVar5 << 4 | uVar9 << 3 | uVar5 | *puVar15 & 0xffff0000;
    *puVar14 = uVar12 << 0xf |
               uVar17 << 0xc |
               uVar12 << 0xb |
               uVar17 << 8 |
               uVar12 << 7 | uVar17 << 4 | uVar12 << 3 | uVar17 | *puVar14 & 0xffff0000;
    if (param_1[9] == 0) {
      piVar18 = param_1 + 10;
      iVar8 = param_1[0xb];
      uVar12 = param_1[0xc];
      if (uVar12 < iVar8 + 7U) {
        if (uVar12 == 0) {
          uVar12 = 0x10;
        }
        else {
          uVar12 = uVar12 << 1;
        }
        for (; uVar12 < iVar8 + 7U; uVar12 = uVar12 << 1) {
        }
        if ((void *)*piVar18 == (void *)0x0) {
          pvVar3 = _malloc(uVar12 << 2);
        }
        else {
          pvVar3 = _realloc((void *)*piVar18,uVar12 << 2);
        }
        if (pvVar3 == (void *)0x0) {
          if (param_1[9] == 0) {
            param_1[9] = 1;
          }
          goto LAB_00041170;
        }
        *piVar18 = (int)pvVar3;
        param_1[0xc] = uVar12;
        iVar8 = param_1[0xb];
      }
      iVar4 = 0;
      param_1[0xb] = iVar8 + 7;
      puVar11 = (undefined4 *)(iVar8 * 4 + *piVar18);
      *puVar11 = *param_3;
      puVar11[1] = param_3[1];
      puVar11[2] = param_3[2];
      puVar7 = param_3;
      do {
        bVar2 = iVar4 != 1;
        iVar4 = iVar4 + 1;
        puVar11[3] = puVar7[3];
        puVar1 = puVar7 + 6;
        puVar7 = puVar7 + 1;
        puVar11[4] = *puVar1;
        puVar11 = puVar11 + 2;
      } while (bVar2);
    }
  }
LAB_00041170:
  iVar8 = param_1[8];
  param_3[3] = 0;
  *puVar15 = 0;
  param_3[3] = param_3[3] & 0xffc0ffff | 0x40000;
  *(short *)((int)param_3 + 0xe) = (short)iVar8;
  param_3[3] = param_3[3] | 0x400000;
  *puVar15 = *puVar15 & 0xffff0000 | 0x3210;
  *param_3 = 0;
  param_3[1] = unaff_r20;
  param_3[2] = unaff_r19;
  *(undefined2 *)((int)param_3 + 2) = 0x47;
  iVar8 = param_1[9];
  if (iVar8 == 0) {
    piVar18 = param_1 + 10;
    iVar8 = param_1[0xb];
    uVar12 = param_1[0xc];
    if (uVar12 < iVar8 + 5U) {
      if (uVar12 == 0) {
        uVar12 = 0x10;
      }
      else {
        uVar12 = uVar12 << 1;
      }
      for (; uVar12 < iVar8 + 5U; uVar12 = uVar12 << 1) {
      }
      if ((void *)*piVar18 == (void *)0x0) {
        pvVar3 = _malloc(uVar12 << 2);
      }
      else {
        pvVar3 = _realloc((void *)*piVar18,uVar12 << 2);
      }
      if (pvVar3 == (void *)0x0) {
        if (param_1[9] != 0) {
          return param_1[9];
        }
        param_1[9] = 1;
        return 1;
      }
      *piVar18 = (int)pvVar3;
      param_1[0xc] = uVar12;
      iVar8 = param_1[0xb];
    }
    param_1[0xb] = iVar8 + 5;
    puVar11 = (undefined4 *)(iVar8 * 4 + *piVar18);
    *puVar11 = *param_3;
    puVar11[1] = param_3[1];
    puVar11[2] = param_3[2];
    puVar11[3] = param_3[3];
    puVar11[4] = param_3[6];
    iVar8 = param_1[9];
  }
  return iVar8;
}

/* orph_4c544 @ 0x4c544 (24 bytes) */
int orph_4c544(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  *(undefined4 *)(param_1 + 0x1e68) = 0;
  FUN_0004a860(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* orph_535c4 @ 0x535c4 (44 bytes) */
int orph_535c4(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(((unsigned char *)0x00001168) + param_1);
  if (((unsigned char *)0x00001170)[param_1] == '\0') {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_00055610(param_1,iVar1 + 0x1c,0x87bf,0xfffffffe,0x87e1,0,param_2,param_3);
    if (1 < param_2) {
      uVar4 = 1;
      do {
        iVar2 = param_2 - uVar4;
        iVar3 = uVar4 + param_3;
        uVar4 = uVar4 + 1;
        FUN_00055610(param_1,iVar1 + 0x1c,0x87bf,0xfffffffe,0x87e1,uVar5,iVar2,iVar3);
      } while (param_2 != uVar4);
    }
  }
  return uVar5;
}

/* orph_535f0 @ 0x535f0 (28 bytes) */
int orph_535f0(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = (param_2 + 0x12) * 4 & 0x7c;
  piVar1 = *(int **)(uVar4 + *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x28);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      iVar5 = *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x14;
      iVar2 = FUN_00055610(param_1,iVar5,0x87bf,0xfffffffc,0x87e1,0,0,param_2);
      if (iVar2 != 0) {
        iVar5 = FUN_00055a30(iVar5,iVar2);
        *(undefined4 *)(iVar5 + 0x50) = 0;
        *(undefined4 *)(iVar5 + 0x48) = 0x12;
        *(undefined1 *)(iVar5 + 0x44) = 1;
        *(int *)(iVar5 + 0x4c) = param_2;
        puVar3 = (undefined4 *)(**(code **)(param_1 + 0xc))(0x10);
        *puVar3 = 0x12;
        puVar3[1] = param_2;
        puVar3[2] = iVar2;
        puVar3[3] = *(undefined4 *)(uVar4 + *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x28);
        *(undefined4 **)(uVar4 + *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x28) = puVar3;
      }
      return iVar2;
    }
    if ((*piVar1 == 0x12) && (param_2 == piVar1[1])) break;
    piVar1 = (int *)piVar1[3];
  }
  return piVar1[2];
}

/* orph_76a64 @ 0x76a64 (80 bytes) */
int orph_76a64(param_1, param_2)
  int param_1;
  int *param_2;
{
  short sVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  
  if (*(char *)(param_2 + 4) == '\0') {
    return;
  }
  if ((*(uint *)(param_1 + 0x8c) & 0x40000000) != 0) {
    return;
  }
  if (*(int *)(**(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2) + 0x4c) == 0) {
    return;
  }
  iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  if (*(int *)(iVar4 + 0x4c) == 0) {
    return;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(char *)((int)param_2 + 0x7a) != '\0') && (((unsigned char *)0x00002e0a)[iVar3] != '\0')) {
    sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar3);
    iVar6 = *(int *)(((unsigned char *)0x000013c4) + iVar4);
    if (sVar1 == 0x801) {
      fVar5 = 0.0;
      fVar2 = -(*(float *)(((unsigned char *)0x00002df0) + iVar3) * *(float *)(((unsigned char *)0x00002df0) + iVar3));
    }
    else if (sVar1 == 0x2601) {
      fVar5 = *(float *)(((unsigned char *)0x00002dfc) + iVar3) * *(float *)(((unsigned char *)0x00002df8) + iVar3);
      fVar2 = -*(float *)(((unsigned char *)0x00002dfc) + iVar3);
    }
    else {
      fVar5 = FLOAT_001aa0d4;
      fVar2 = FLOAT_001aa0d4;
      if (sVar1 == 0x800) {
        fVar5 = 0.0;
        fVar2 = -*(float *)(((unsigned char *)0x00002df0) + iVar3);
      }
    }
    iVar3 = iVar6 * 0x10;
    iVar7 = iVar3 + iVar4;
    *(undefined4 *)(*(int *)(iVar4 + 0x124) + iVar3) = 0;
    *(float *)(iVar3 + *(int *)(iVar4 + 0x124) + 4) = fVar5;
    *(float *)(iVar3 + *(int *)(iVar4 + 0x124) + 8) = fVar2;
    *(undefined4 *)(iVar3 + *(int *)(iVar4 + 0x124) + 0xc) = 0;
    *(undefined4 *)(iVar7 + 0x160) = 0;
    *(float *)(iVar7 + 0x158) = fVar5;
    *(float *)(iVar7 + 0x15c) = fVar2;
    *(undefined4 *)(iVar7 + 0x154) = 0;
    if (*(int *)(((unsigned char *)0x0000137c) + iVar4) < iVar6) {
      *(int *)(((unsigned char *)0x0000137c) + iVar4) = iVar6;
    }
  }
                    
                    
  (**(code **)((int)((unsigned char *)0x000012a0) + param_1))(param_1,iVar4 + 0x13c);
  return;
}

/* orph_7a174 @ 0x7a174 (28 bytes) */
int orph_7a174(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
                    
                    
  (**(code **)(param_1 + 0xc))(param_2);
  return;
}

/* orph_7a190 @ 0x7a190 (16 bytes) */
int orph_7a190(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
                    
                    
  (**(code **)(param_1 + 0x18))(param_2);
  return;
}

/* orph_c6e40 @ 0xc6e40 (12 bytes) */
int orph_c6e40(param_1, param_2)
  undefined4 param_1;
  size_t param_2;
{
  _calloc(param_2,1);
  return;
}

/* orph_c71d0 @ 0xc71d0 (24 bytes) */
int orph_c71d0(param_1)
  int *param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  code *pcVar3;
  
  puVar2 = (undefined4 *)*param_1;
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  uVar1 = 3;
  if (puVar2 != (undefined4 *)0x0) {
    pcVar3 = (code *)*puVar2;
    uVar1 = puVar2[1];
    FUN_000da458(puVar2,1);
    (*pcVar3)(uVar1,puVar2);
    uVar1 = 0;
  }
  return uVar1;
}

/* orph_cd380 @ 0xcd380 (8 bytes) */
int orph_cd380()
{
  return 1;
}

/* orph_ce330 @ 0xce330 (376 bytes) */
int orph_ce330()
{
  bool bVar1;
  size_t sVar2;
  undefined4 uVar3;
  undefined4 unaff_r22;
  int unaff_r23;
  uint unaff_r24;
  uint unaff_r26;
  uint uVar4;
  uint uVar5;
  char *unaff_r29;
  uint uVar6;
  int unaff_r31;
  
  _strcat(unaff_r29,(char *)(unaff_r31 + 0xd8154));
  sVar2 = _strlen(unaff_r29);
  (unaff_r29 + sVar2)[0] = '+';
  (unaff_r29 + sVar2)[1] = '\0';
  _strcat(unaff_r29,&STACKARG(0x38));
  sVar2 = _strlen(unaff_r29);
  (unaff_r29 + sVar2)[0] = ']';
  (unaff_r29 + sVar2)[1] = '\0';
  if ((unaff_r24 != 0xd10000) || (unaff_r23 != 0)) {
    uVar4 = 0;
    sVar2 = _strlen(unaff_r29);
    (unaff_r29 + sVar2)[0] = '.';
    (unaff_r29 + sVar2)[1] = '\0';
    uVar5 = 0xd;
    do {
      uVar6 = (unaff_r24 & 7 << (uVar5 & 0x3f)) >> (uVar5 & 0x3f);
      if (((unaff_r26 & 0x2000000 << (uVar4 & 0x3f)) != 0) && (unaff_r23 != 0)) {
        sVar2 = _strlen(unaff_r29);
        (unaff_r29 + sVar2)[0] = '-';
        (unaff_r29 + sVar2)[1] = '\0';
      }
      if (uVar6 < 6) {
                    
                    
        uVar3 = (*(code *)(*(int *)(unaff_r31 + 0x2c4 + uVar6 * 4) + unaff_r31 + 0x2c4))();
        return uVar3;
      }
      sVar2 = _strlen(unaff_r29);
      (unaff_r29 + sVar2)[0] = '?';
      (unaff_r29 + sVar2)[1] = '\0';
      bVar1 = uVar4 != 3;
      uVar5 = uVar5 + 3;
      uVar4 = uVar4 + 1;
    } while (bVar1);
  }
  return unaff_r22;
}

/* orph_ce344 @ 0xce344 (376 bytes) */
int orph_ce344()
{
  bool bVar1;
  size_t sVar2;
  undefined4 uVar3;
  undefined4 unaff_r22;
  int unaff_r23;
  uint unaff_r24;
  uint unaff_r26;
  uint uVar4;
  uint uVar5;
  char *unaff_r29;
  uint uVar6;
  int unaff_r31;
  
  _strcat(unaff_r29,(char *)(unaff_r31 + 0xd8158));
  sVar2 = _strlen(unaff_r29);
  (unaff_r29 + sVar2)[0] = '+';
  (unaff_r29 + sVar2)[1] = '\0';
  _strcat(unaff_r29,&STACKARG(0x38));
  sVar2 = _strlen(unaff_r29);
  (unaff_r29 + sVar2)[0] = ']';
  (unaff_r29 + sVar2)[1] = '\0';
  if ((unaff_r24 != 0xd10000) || (unaff_r23 != 0)) {
    uVar4 = 0;
    sVar2 = _strlen(unaff_r29);
    (unaff_r29 + sVar2)[0] = '.';
    (unaff_r29 + sVar2)[1] = '\0';
    uVar5 = 0xd;
    do {
      uVar6 = (unaff_r24 & 7 << (uVar5 & 0x3f)) >> (uVar5 & 0x3f);
      if (((unaff_r26 & 0x2000000 << (uVar4 & 0x3f)) != 0) && (unaff_r23 != 0)) {
        sVar2 = _strlen(unaff_r29);
        (unaff_r29 + sVar2)[0] = '-';
        (unaff_r29 + sVar2)[1] = '\0';
      }
      if (uVar6 < 6) {
                    
                    
        uVar3 = (*(code *)(*(int *)(unaff_r31 + 0x2c4 + uVar6 * 4) + unaff_r31 + 0x2c4))();
        return uVar3;
      }
      sVar2 = _strlen(unaff_r29);
      (unaff_r29 + sVar2)[0] = '?';
      (unaff_r29 + sVar2)[1] = '\0';
      bVar1 = uVar4 != 3;
      uVar5 = uVar5 + 3;
      uVar4 = uVar4 + 1;
    } while (bVar1);
  }
  return unaff_r22;
}

/* orph_cec34 @ 0xcec34 (256 bytes) */
int orph_cec34()
{
  uint uVar1;
  size_t sVar2;
  undefined4 unaff_r25;
  uint unaff_r28;
  char *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  
  _strcat(unaff_r29,(char *)(unaff_r31 + 0xd7834));
  sVar2 = _strlen(unaff_r29);
  (unaff_r29 + sVar2)[0] = '+';
  (unaff_r29 + sVar2)[1] = '\0';
  _strcat(unaff_r29,&STACKARG(0x38));
  sVar2 = _strlen(unaff_r29);
  (unaff_r29 + sVar2)[0] = ']';
  (unaff_r29 + sVar2)[1] = '\0';
  if ((unaff_r30 & 0x40) == 0) {
    uVar1 = unaff_r30 & 0x1000000;
  }
  else {
    uVar1 = unaff_r30 & 0x2000000;
  }
  if (uVar1 != 0) {
    _strcat(unaff_r29,(char *)(unaff_r31 + 0xd7a34));
  }
  if (unaff_r28 != 0xf00000) {
    sVar2 = _strlen(unaff_r29);
    (unaff_r29 + sVar2)[0] = '.';
    (unaff_r29 + sVar2)[1] = '\0';
    if ((unaff_r28 & 0x100000) != 0) {
      sVar2 = _strlen(unaff_r29);
      (unaff_r29 + sVar2)[0] = 'x';
      (unaff_r29 + sVar2)[1] = '\0';
    }
    if ((unaff_r28 & 0x200000) != 0) {
      sVar2 = _strlen(unaff_r29);
      (unaff_r29 + sVar2)[0] = 'y';
      (unaff_r29 + sVar2)[1] = '\0';
    }
    if ((unaff_r28 & 0x400000) != 0) {
      sVar2 = _strlen(unaff_r29);
      (unaff_r29 + sVar2)[0] = 'z';
      (unaff_r29 + sVar2)[1] = '\0';
    }
    if ((unaff_r28 & 0x800000) != 0) {
      sVar2 = _strlen(unaff_r29);
      (unaff_r29 + sVar2)[0] = 'w';
      (unaff_r29 + sVar2)[1] = '\0';
    }
  }
  return unaff_r25;
}

/* orph_cec48 @ 0xcec48 (256 bytes) */
int orph_cec48()
{
  uint uVar1;
  size_t sVar2;
  undefined4 unaff_r25;
  uint unaff_r28;
  char *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  
  _strcat(unaff_r29,(char *)(unaff_r31 + 0xd7838));
  sVar2 = _strlen(unaff_r29);
  (unaff_r29 + sVar2)[0] = '+';
  (unaff_r29 + sVar2)[1] = '\0';
  _strcat(unaff_r29,&STACKARG(0x38));
  sVar2 = _strlen(unaff_r29);
  (unaff_r29 + sVar2)[0] = ']';
  (unaff_r29 + sVar2)[1] = '\0';
  if ((unaff_r30 & 0x40) == 0) {
    uVar1 = unaff_r30 & 0x1000000;
  }
  else {
    uVar1 = unaff_r30 & 0x2000000;
  }
  if (uVar1 != 0) {
    _strcat(unaff_r29,(char *)(unaff_r31 + 0xd7a34));
  }
  if (unaff_r28 != 0xf00000) {
    sVar2 = _strlen(unaff_r29);
    (unaff_r29 + sVar2)[0] = '.';
    (unaff_r29 + sVar2)[1] = '\0';
    if ((unaff_r28 & 0x100000) != 0) {
      sVar2 = _strlen(unaff_r29);
      (unaff_r29 + sVar2)[0] = 'x';
      (unaff_r29 + sVar2)[1] = '\0';
    }
    if ((unaff_r28 & 0x200000) != 0) {
      sVar2 = _strlen(unaff_r29);
      (unaff_r29 + sVar2)[0] = 'y';
      (unaff_r29 + sVar2)[1] = '\0';
    }
    if ((unaff_r28 & 0x400000) != 0) {
      sVar2 = _strlen(unaff_r29);
      (unaff_r29 + sVar2)[0] = 'z';
      (unaff_r29 + sVar2)[1] = '\0';
    }
    if ((unaff_r28 & 0x800000) != 0) {
      sVar2 = _strlen(unaff_r29);
      (unaff_r29 + sVar2)[0] = 'w';
      (unaff_r29 + sVar2)[1] = '\0';
    }
  }
  return unaff_r25;
}

/* orph_d9f34 @ 0xd9f34 (8 bytes) */
int orph_d9f34()
{
  return 1;
}

/* orph_d9f78 @ 0xd9f78 (8 bytes) */
int orph_d9f78()
{
  return 1;
}

/* orph_da880 @ 0xda880 (40 bytes) */
int orph_da880(param_1)
  undefined4 *param_1;
{
  param_1[0x87] = 0;
  *param_1 = 0;
  param_1[0x84] = 0;
  param_1[0x85] = 0;
  param_1[0x86] = 0;
                    
                    
  (*(code *)PTR_FUN_001e876c)(param_1 + 4,0,0x200);
  return;
}

/* orph_e2084 @ 0xe2084 (8 bytes) */
int orph_e2084(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x310) != 0) {
    FUN_0010defc(*(int *)(param_1 + 0x310),param_1);
    (**(code **)(param_1 + 0x34c))
              (*(undefined4 *)(param_1 + 0x354),*(undefined4 *)(param_1 + 0x310));
  }
  iVar1 = param_1;
  do {
    if (*(int *)(iVar1 + 0x370) != 0) {
      FUN_00193d18(*(int *)(iVar1 + 0x370));
      (**(code **)(param_1 + 0x34c))
                (*(undefined4 *)(param_1 + 0x354),*(undefined4 *)(iVar1 + 0x370));
      *(undefined4 *)(iVar1 + 0x370) = 0;
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 != param_1 + 0xc);
  return;
}

/* orph_e208c @ 0xe208c (8 bytes) */
int orph_e208c(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x310) != 0) {
    FUN_0010defc(*(int *)(param_1 + 0x310),param_1);
    (**(code **)(param_1 + 0x34c))
              (*(undefined4 *)(param_1 + 0x354),*(undefined4 *)(param_1 + 0x310));
  }
  iVar1 = param_1;
  do {
    if (*(int *)(iVar1 + 0x370) != 0) {
      FUN_00193d18(*(int *)(iVar1 + 0x370));
      (**(code **)(param_1 + 0x34c))
                (*(undefined4 *)(param_1 + 0x354),*(undefined4 *)(iVar1 + 0x370));
      *(undefined4 *)(iVar1 + 0x370) = 0;
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 != param_1 + 0xc);
  return;
}

/* orph_e2884 @ 0xe2884 (36 bytes) */
int orph_e2884(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 100))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

/* orph_e28a8 @ 0xe28a8 (36 bytes) */
int orph_e28a8(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x70))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

/* orph_e28cc @ 0xe28cc (36 bytes) */
int orph_e28cc(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x68))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

/* orph_e2950 @ 0xe2950 (36 bytes) */
int orph_e2950(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x60))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

/* orph_e2974 @ 0xe2974 (36 bytes) */
int orph_e2974(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x78))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

/* orph_e2998 @ 0xe2998 (36 bytes) */
int orph_e2998(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x7c))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

