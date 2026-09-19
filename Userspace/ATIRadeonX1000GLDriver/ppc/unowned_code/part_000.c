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

/* orph_1efd0 @ 0x1efd0 (3244 bytes) */
int orph_1efd0()
{
  byte *pbVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  byte bVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  undefined4 uVar10;
  void *pvVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  byte *pbVar19;
  undefined4 *puVar20;
  int in_r11;
  int *piVar21;
  undefined *puVar22;
  uint uVar23;
  undefined4 *puVar24;
  int unaff_r17;
  int unaff_r18;
  int unaff_r19;
  int iVar25;
  int unaff_r21;
  int unaff_r22;
  int unaff_r23;
  undefined *unaff_r24;
  uint unaff_r25;
  int unaff_r26;
  int unaff_r28;
  uint unaff_r29;
  uint uVar26;
  uint *puVar27;
  int unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte in_cr6;
  int iVar28;
  int iStack00000038;
  int iStack0000003c;
  int iStack00000040;
  int iStack00000044;
  undefined4 *puStack00000048;
  uint uStack0000004c;
  int in_stack_000000d0;
  
  uVar26 = (unaff_r29 / 3) * 3;
  if (unaff_r25 < uVar26) {
    uVar26 = unaff_r25;
  }
  if (in_r11 == 0) {
LAB_0001f7f0:
    uVar10 = 0;
  }
  else {
    bVar2 = unaff_r24 == ((unsigned char *)0x000014ff);
    if (((bVar2) || (*(int *)(unaff_r30 + 0x24e0) != 0)) || (unaff_r22 != 0)) {
      iStack00000038 = 1;
      iStack0000003c = 1;
    }
    else if (*(int *)(unaff_r30 + 0x2494) == unaff_r30 + 0x2528) {
      iStack00000038 = 0;
      iStack0000003c = 0;
    }
    else {
      iStack00000038 = 1;
      iStack0000003c = 0;
    }
    uVar14 = -(uint)*(byte *)(unaff_r30 + 0x2802) >> 0x1e & 2;
    if (*(int *)(unaff_r30 + 0x2440) != unaff_r30 + 0x23f0) {
      uVar14 = uVar14 + (*(int *)(unaff_r30 + 0x243c) + 1U & 0xfffffffe) + 4;
    }
    if (iStack00000038 == 0) {
      piVar21 = *(int **)(unaff_r26 + 0x1d4);
    }
    else {
      piVar21 = *(int **)(unaff_r26 + 0x1d4);
      iVar13 = uVar14 + 0x14;
      if (*(int *)(*piVar21 + 0x308) != 0 || *(int *)(*piVar21 + 0x30c) != 0) {
        iVar13 = unaff_r17 + uVar14 + 0x13;
      }
      if (unaff_r22 != 0) {
        iVar13 = iVar13 + 1;
      }
      uVar14 = iVar13 + (unaff_r17 + 1U >> 1) * 3 + 3;
      if (*(int *)(unaff_r30 + 0x24e0) != 0) {
        uVar14 = uVar14 + *(int *)(unaff_r30 + 0x24e0) + 1;
      }
    }
    iStack00000044 = uVar14 + 2;
    iStack00000040 = 0;
    puStack00000048 = *(undefined4 **)(piVar21[1] + 0x80);
    if (unaff_r21 == 0) {
      iStack00000040 = *(int *)(unaff_r28 + 0x314);
    }
    uVar14 = unaff_r17 + 1U >> 1;
    piVar21 = (int *)0x0;
    puVar24 = (undefined4 *)0x0;
    iVar13 = 0;
    uStack0000004c = (uVar14 * 3 + -1) * 0x10000 | 0x831;
    while ((bool)(in_cr6 >> 2 & 1)) {
      iVar25 = iVar13 * uVar26 + unaff_r23;
      if (unaff_r25 < uVar26) {
        uVar26 = unaff_r25;
      }
      bVar3 = unaff_r24 == ((unsigned char *)0x00001403);
      if (bVar3) {
LAB_0001f1c0:
        if (unaff_r22 == 0) {
          iVar7 = (uVar26 + 1 >> 1) + 4;
        }
        else {
LAB_0001f1f0:
          iVar7 = 8;
        }
      }
      else if (((unsigned char *)0x00001403) < unaff_r24) {
        if (unaff_r24 == ((unsigned char *)0x00001405)) {
          iVar7 = uVar26 + 4;
          if (unaff_r22 != 0) goto LAB_0001f1f0;
        }
        else {
          if (!bVar2) goto LAB_0001f1ac;
          iVar7 = 4;
        }
      }
      else {
        if (unaff_r24 == ((unsigned char *)0x00001401)) goto LAB_0001f1c0;
LAB_0001f1ac:
        iVar7 = 0;
      }
      puVar8 = (uint *)(**(code **)(unaff_r30 + 0x2758))(unaff_r30,iVar7 + iStack00000044);
      cVar5 = *(char *)(unaff_r30 + 0x2802);
      *(uint **)(FUN_00002748 + unaff_r30 + 4) = puVar8;
      puVar9 = puVar8;
      if (cVar5 != '\0') {
        puVar9 = puVar8 + 2;
        *puVar8 = 0x5c8;
        puVar8[1] = 0x10000000;
        *(undefined1 *)(unaff_r30 + 0x2802) = 0;
      }
      if (*(int *)(unaff_r30 + 0x2440) != unaff_r30 + 0x23f0) {
        *(int *)(unaff_r30 + 0x2440) = unaff_r30 + 0x23f0;
        *(int *)(unaff_r30 + 0x2444) = unaff_r30 + 0x2410;
        puVar9 = (uint *)FUN_0002c0c0(unaff_r26,puVar9);
      }
      if (iStack00000038 != 0) {
        puVar24 = (undefined4 *)((uint)(puVar9 + 0xb) & 0xffffffe0);
        *(int *)(unaff_r30 + 0x2494) = unaff_r30 + 0x2528;
        *(int *)(unaff_r30 + 0x2498) = unaff_r30 + 0x2548;
        *(undefined4 *)(unaff_r30 + 0x2490) = *(undefined4 *)(unaff_r30 + 0x2588);
        *puVar9 = (((int)puVar24 - (int)puVar9) + -8) * 0x4000 | 0xc0001000;
        puVar24[-1] = (int)puVar24 - (int)puVar9;
        puVar9 = *(uint **)(unaff_r26 + 0x1d8);
        *puVar9 = *puVar9 | (int)puVar24 - (int)puVar9 >> 2;
        *(undefined4 **)(unaff_r26 + 0x1d8) = puVar24;
        *puVar24 = 0x39000000;
        puVar24[1] = unaff_r17;
        puVar24[2] = unaff_r21;
        puVar24[3] = unaff_r22;
        if (bVar3) {
          uVar10 = 2;
        }
        else {
          uVar10 = 4;
        }
        puVar24[4] = uVar10;
        puVar9 = puVar24 + 8;
        iVar7 = **(int **)(unaff_r26 + 0x1d4);
        if (*(int *)(iVar7 + 0x308) == 0 && *(int *)(iVar7 + 0x30c) == 0) {
          puVar9 = puVar24 + 9;
          puVar24[8] = *(undefined4 *)(*(int **)(unaff_r26 + 0x1d4))[0x8a];
          piVar21 = (int *)(*(int *)(*(int *)(unaff_r26 + 0x1d4) + 0x228) + 0x10);
          if (in_RESERVE != '\0') {
            iVar7 = storeWordConditionalIndexed(*piVar21 + 0x10000,0,piVar21);
            *piVar21 = iVar7;
          }
          if (unaff_r22 != 0) {
            puVar9 = puVar24 + 10;
            puVar24[9] = **(undefined4 **)(*(int *)(unaff_r26 + 0x1d4) + 0x228);
            piVar21 = (int *)(*(int *)(*(int *)(unaff_r26 + 0x1d4) + 0x228) + 0x10);
            if (in_RESERVE != '\0') {
              iVar7 = storeWordConditionalIndexed(*piVar21 + 0x10000,0,piVar21);
              *piVar21 = iVar7;
            }
          }
        }
        else {
          bVar4 = false;
          if (unaff_r17 != 0) {
            puVar20 = (undefined4 *)(unaff_r30 + 0x24e8);
            iVar7 = unaff_r17;
            if (unaff_r17 == 0) {
              iVar7 = 1;
            }
            do {
              puVar8 = (uint *)*puVar20;
              puVar20 = puVar20 + 1;
              puVar27 = puVar8 + 4;
              *puVar9 = *puVar8;
              puVar9 = puVar9 + 1;
              do {
                if (in_RESERVE != '\0') {
                  uVar12 = storeWordConditionalIndexed(*puVar27 + 0x10000,0,puVar27);
                  *puVar27 = uVar12;
                  bVar4 = true;
                }
              } while (!bVar4);
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
          if (unaff_r22 != 0) {
            *puVar9 = *(uint *)**(undefined4 **)
                                 (*(int *)(*(int *)(*(int *)(unaff_r26 + 0x1d4) + 4) + 0x80) + 8);
            puVar9 = puVar9 + 1;
            piVar21 = (int *)(**(int **)(*(int *)(*(int *)(*(int *)(unaff_r26 + 0x1d4) + 4) + 0x80)
                                        + 8) + 0x10);
            do {
              if (in_RESERVE != '\0') {
                iVar7 = storeWordConditionalIndexed(*piVar21 + 0x10000,0,piVar21);
                *piVar21 = iVar7;
                bVar4 = true;
              }
            } while (!bVar4);
          }
        }
        puVar24[5] = ((int)puVar9 - (int)puVar24 >> 2) + 2;
        if (bVar2) {
          puVar8 = puVar9 + 1;
          *puVar9 = uStack0000004c;
          if (uVar14 != 0) {
            piVar21 = (int *)(unaff_r30 + 0x254c);
            iVar7 = unaff_r30;
            uVar12 = uVar14;
            do {
              *puVar8 = *(uint *)(iVar7 + 0x2528);
              if (piVar21[-1] == -1) {
                puVar8[1] = 0xffffffff;
              }
              else {
                puVar8[1] = piVar21[-1] + unaff_r23 * (*(uint *)(iVar7 + 0x2528) >> 8 & 0x7f) * 4;
              }
              if (*piVar21 == -1) {
                puVar8[2] = 0xffffffff;
              }
              else {
                puVar8[2] = *piVar21 + unaff_r23 * (*(byte *)(iVar7 + 0x2528) & 0x7f) * 4;
              }
              puVar8 = puVar8 + 3;
              iVar7 = iVar7 + 4;
              piVar21 = piVar21 + 2;
              uVar12 = uVar12 - 1;
            } while (uVar12 != 0);
          }
          puVar9 = puVar8 + 2;
          *puVar8 = 0x830;
          puVar8[1] = *(uint *)(unaff_r30 + 0x2588);
          *(undefined4 *)(unaff_r30 + 0x2494) = 0;
        }
        else {
          puVar9 = (uint *)FUN_0002c180(unaff_r26);
        }
        piVar21 = puVar24 + 7;
        puVar24[6] = (int)puVar9 + (4 - (int)puVar24) >> 2;
        uVar12 = *(uint *)(unaff_r30 + 0x24dc);
        bVar4 = uVar12 == 0;
        if (bVar4) {
          iStack00000038 = iStack0000003c;
        }
        else {
          puVar8 = puVar9 + 1;
          *puVar9 = (*(int *)(unaff_r30 + 0x24e0) + -1) * 0x10000 | 0xc0001000;
          if (*(int *)(*(int *)(unaff_r26 + 0x14) + 0x11c) == 0) {
            iVar7 = *(int *)(unaff_r26 + 0x1cc);
            if (iVar7 != 0) goto LAB_0001f704;
            if ((uVar12 & 2) != 0) {
              puVar9[1] = *(uint *)(unaff_r18 + 0x40);
              puVar9[2] = *(uint *)(unaff_r18 + 0x44);
              puVar8 = puVar9 + 5;
              uVar18 = *(uint *)(unaff_r18 + 0x48);
              puVar9[4] = 0x3f800000;
              puVar9[3] = uVar18;
            }
            if ((uVar12 & 4) != 0) {
              *puVar8 = *(uint *)(unaff_r18 + 0x30);
              puVar8[1] = *(uint *)(unaff_r18 + 0x34);
              puVar8[2] = *(uint *)(unaff_r18 + 0x38);
              puVar8[3] = *(uint *)(unaff_r18 + 0x3c);
              puVar8 = puVar8 + 4;
            }
            if ((uVar12 & 8) != 0) {
              *puVar8 = *(uint *)(unaff_r18 + 0x50);
              puVar8[1] = *(uint *)(unaff_r18 + 0x54);
              uVar18 = *(uint *)(unaff_r18 + 0x58);
              puVar8[3] = 0x3f800000;
              puVar8[2] = uVar18;
              puVar8 = puVar8 + 4;
            }
            uVar18 = 0;
            iVar28 = 8;
            iVar7 = unaff_r18;
            do {
              if ((uVar12 & 0x400 << (uVar18 & 0x3f)) != 0) {
                *puVar8 = *(uint *)(iVar7 + 0x80);
                puVar8[1] = *(uint *)(iVar7 + 0x84);
                puVar8[2] = *(uint *)(iVar7 + 0x88);
                puVar8[3] = *(uint *)(iVar7 + 0x8c);
                puVar8 = puVar8 + 4;
              }
              uVar18 = uVar18 + 1;
              iVar7 = iVar7 + 0x10;
              iVar28 = iVar28 + -1;
            } while (iVar28 != 0);
            if ((uVar12 & 0x40000) != 0) {
              uVar18 = *(uint *)(unaff_r18 + 0x5c);
              puVar8[3] = 0x3f800000;
              puVar8[1] = 0x3f800000;
              puVar8[2] = 0x3f800000;
              *puVar8 = uVar18;
              puVar8 = puVar8 + 4;
            }
            puVar9 = puVar8;
            if ((uVar12 & 0x80000) != 0) {
              *puVar8 = *(uint *)(unaff_r18 + 0x60);
              puVar8[1] = *(uint *)(unaff_r18 + 100);
              puVar8[2] = *(uint *)(unaff_r18 + 0x68);
              puVar8[3] = *(uint *)(unaff_r18 + 0x6c);
              puVar9 = puVar8 + 4;
            }
          }
          else {
            iVar7 = *(int *)(unaff_r26 + 0x1cc);
LAB_0001f704:
            iVar15 = *(int *)(*(int *)(unaff_r26 + 0x14) + 0x11c);
            iVar28 = 0x16;
            puVar9 = puVar8;
            if ((iVar7 == 0) ||
               (iVar28 = *(int *)(*(int *)(FUN_000027a4 + unaff_r30 + 4) + 0x28), iVar28 != 0)) {
              uVar18 = 0;
              puVar8 = (uint *)(unaff_r30 + 0x259c);
              do {
                uVar16 = 1 << (uVar18 & 0x3f);
                if ((uVar12 & uVar16) != 0) {
                  uVar17 = uVar18;
                  if (iVar15 != 0) {
                    uVar17 = *puVar8;
                  }
                  uVar12 = uVar12 & ~uVar16;
                  iVar7 = unaff_r18 + uVar17 * 0x10;
                  bVar4 = uVar12 == 0;
                  *puVar9 = *(uint *)(unaff_r18 + uVar17 * 0x10);
                  puVar9[1] = *(uint *)(iVar7 + 4);
                  puVar9[2] = *(uint *)(iVar7 + 8);
                  puVar9[3] = *(uint *)(iVar7 + 0xc);
                  puVar9 = puVar9 + 4;
                }
                if (bVar4) break;
                uVar18 = uVar18 + 1;
                puVar8 = puVar8 + 1;
                iVar28 = iVar28 + -1;
              } while (iVar28 != 0);
            }
          }
          iStack00000038 = iStack0000003c;
        }
      }
      puVar22 = &UNK_001ba4e4 + unaff_r31;
      dataCacheBlockTouch(puVar22);
      if (bVar3) {
        puVar8 = (uint *)(iVar25 * 2 + in_stack_000000d0);
        dataCacheBlockTouch(puVar8);
        dataCacheBlockTouch((int)puVar8 + (uint)*(byte *)(unaff_r26 + 8));
        uVar12 = uVar26 << 0x10 | *(uint *)(puVar22 + unaff_r19 * 4) & 0xf | 0x10;
        if (unaff_r22 == 0) {
          *puVar9 = 0x82c;
          uVar18 = uVar26 + 1 >> 1;
          puVar27 = puVar9 + 4;
          uVar16 = *(uint *)(unaff_r30 + 0x1b84);
          puVar9[2] = uVar18 << 0x10 | 0xc0003600;
          puVar9[3] = uVar12;
          puVar9[1] = uVar16;
          if (uVar26 < 0x201) {
            uVar12 = uVar26 >> 3;
            puVar9 = puVar8;
            if (uVar12 != 0) {
              if (uVar12 == 0) {
                uVar12 = 1;
              }
              do {
                uVar18 = *puVar9;
                uVar16 = puVar9[1];
                uVar17 = puVar9[2];
                uVar23 = puVar9[3];
                puVar9 = puVar9 + 4;
                *puVar27 = uVar18 << 0x10 | uVar18 >> 0x10;
                puVar27[1] = uVar16 << 0x10 | uVar16 >> 0x10;
                puVar27[2] = uVar17 << 0x10 | uVar17 >> 0x10;
                puVar27[3] = uVar23 << 0x10 | uVar23 >> 0x10;
                puVar27 = puVar27 + 4;
                uVar12 = uVar12 - 1;
              } while (uVar12 != 0);
            }
            uVar12 = uVar26 >> 1 & 3;
            if (uVar12 != 0) {
              if (uVar12 == 0) {
                uVar12 = 1;
              }
              do {
                uVar18 = *puVar9;
                puVar9 = puVar9 + 1;
                *puVar27 = uVar18 << 0x10 | uVar18 >> 0x10;
                puVar27 = puVar27 + 1;
                uVar12 = uVar12 - 1;
              } while (uVar12 != 0);
            }
            if ((uVar26 & 1) != 0) {
              *puVar27 = (uint)*(ushort *)((int)puVar8 + uVar26 * 2 + -2);
              puVar27 = puVar27 + 1;
            }
          }
          else {
            if (*(char *)(unaff_r26 + 8) == -0x80) {
              FUN_0001eae0(puVar27,puVar8,uVar26);
            }
            else {
              FUN_0001e890(puVar27,puVar8,uVar26);
            }
            puVar27 = puVar27 + uVar18;
          }
        }
        else {
          *puVar9 = 0x82c;
          uVar18 = *(uint *)(unaff_r30 + 0x1b84);
          puVar9[2] = 0xc0003600;
          puVar9[3] = uVar12;
          puVar9[1] = uVar18;
          *piVar21 = (int)puVar9 + (0x10 - (int)puVar24) >> 2;
          piVar21 = piVar21 + 1;
          puVar9[4] = 0xc0023300;
          puVar9[5] = 0x80000810;
          if (puStack00000048 == (undefined4 *)0x0) {
            puVar9[6] = (int)puVar8 - iStack00000040;
          }
          else {
            puVar9[6] = (int)puVar8 - *(int *)*puStack00000048;
          }
          puVar27 = puVar9 + 8;
          puVar9[7] = uVar26 + 1 >> 1;
        }
      }
      else if (((unsigned char *)0x00001403) < unaff_r24) {
        if (unaff_r24 == ((unsigned char *)0x00001405)) {
          pvVar11 = (void *)(iVar25 * 4 + in_stack_000000d0);
          uVar12 = uVar26 << 0x10 | *(uint *)(puVar22 + unaff_r19 * 4) & 0xf | 0x810;
          if (unaff_r22 == 0) {
            *puVar9 = 0x82c;
            puVar27 = puVar9 + 4 + uVar26;
            uVar18 = *(uint *)(unaff_r30 + 0x1b84);
            puVar9[2] = uVar26 << 0x10 | 0xc0003600;
            puVar9[3] = uVar12;
            puVar9[1] = uVar18;
            _memcpy(puVar9 + 4,pvVar11,uVar26 * 4);
          }
          else {
            *puVar9 = 0x82c;
            uVar18 = *(uint *)(unaff_r30 + 0x1b84);
            puVar9[2] = 0xc0003600;
            puVar9[3] = uVar12;
            puVar9[1] = uVar18;
            *piVar21 = (int)puVar9 + (0x10 - (int)puVar24) >> 2;
            puVar9[4] = 0xc0023300;
            puVar9[5] = 0x80000810;
            piVar21 = piVar21 + 1;
            if (puStack00000048 == (undefined4 *)0x0) {
              puVar9[6] = (int)pvVar11 - iStack00000040;
            }
            else {
              puVar9[6] = (int)pvVar11 - *(int *)*puStack00000048;
            }
            puVar27 = puVar9 + 8;
            puVar9[7] = uVar26;
          }
        }
        else {
          if (!bVar2) goto LAB_0001f7f0;
          puVar27 = puVar9 + 4;
          uVar18 = *(uint *)(puVar22 + unaff_r19 * 4);
          *puVar9 = 0x82c;
          unaff_r23 = unaff_r23 + uVar26;
          uVar12 = *(uint *)(unaff_r30 + 0x1b84);
          puVar9[2] = 0xc0003400;
          puVar9[1] = uVar12;
          puVar9[3] = uVar26 << 0x10 | uVar18 & 0xf | 0x820;
        }
      }
      else {
        if (unaff_r24 != ((unsigned char *)0x00001401)) goto LAB_0001f7f0;
        uVar18 = *(uint *)(puVar22 + unaff_r19 * 4);
        *puVar9 = 0x82c;
        puVar27 = puVar9 + 4;
        uVar12 = *(uint *)(unaff_r30 + 0x1b84);
        puVar9[2] = (uVar26 + 1) * 0x8000 & 0xffff0000 | 0xc0003600;
        puVar9[1] = uVar12;
        puVar9[3] = uVar26 << 0x10 | uVar18 & 0xf | 0x10;
        if ((uVar26 & 0xfffffffe) != 0) {
          uVar12 = 0;
          pbVar19 = (byte *)(in_stack_000000d0 + iVar25);
          do {
            pbVar1 = pbVar19 + 1;
            uVar12 = uVar12 + 2;
            bVar6 = *pbVar19;
            pbVar19 = pbVar19 + 2;
            *puVar27 = (uint)*pbVar1 << 0x10 | (uint)bVar6;
            puVar27 = puVar27 + 1;
          } while (uVar12 < (uVar26 & 0xfffffffe));
        }
        if ((uVar26 & 1) != 0) {
          *puVar27 = (uint)((byte *)(in_stack_000000d0 + iVar25))[uVar26 - 1];
          puVar27 = puVar27 + 1;
        }
      }
      unaff_r25 = unaff_r25 - uVar26;
      *puVar27 = (uint)((unsigned char *)0x00001393);
      puVar27[1] = 0;
      puVar27 = puVar27 + 2;
      iVar13 = iVar13 + 1;
      *(uint **)(FUN_00002748 + unaff_r30 + 4) = puVar27;
      (**(code **)(unaff_r30 + 0x275c))(unaff_r30,puVar27);
      in_cr6 = (0 < (int)unaff_r25) << 2;
      if (*(uint **)(unaff_r26 + 0x2994) <= puVar27) {
        pbVar19 = *(byte **)(unaff_r26 + 0x238);
        if (((uint)pbVar19[3] << 0x18 | (uint)pbVar19[2] << 0x10 | (uint)pbVar19[1] << 8 |
            (uint)*pbVar19) == *(uint *)(pbVar19 + 0x20)) {
          FUN_0001a0f0(unaff_r26,0x1000000);
          in_cr6 = (0 < (int)unaff_r25) << 2;
        }
        else {
          in_cr6 = (0 < (int)unaff_r25) << 2;
          *(uint **)(unaff_r26 + 0x2994) = *(uint **)(unaff_r26 + 0x2994) + 0x1000;
        }
      }
    }
    uVar10 = 1;
    *(undefined1 *)(unaff_r30 + 0x281e) = 1;
    *(undefined1 *)(unaff_r30 + 0x2595) = 1;
  }
  return uVar10;
}

/* orph_1efec @ 0x1efec (3228 bytes) */
int orph_1efec()
{
  byte *pbVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  byte bVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  undefined4 uVar10;
  void *pvVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  byte *pbVar19;
  undefined4 *puVar20;
  int in_r11;
  int *piVar21;
  undefined *puVar22;
  uint uVar23;
  undefined4 *puVar24;
  int unaff_r17;
  int unaff_r18;
  int unaff_r19;
  int iVar25;
  int unaff_r21;
  int unaff_r22;
  int unaff_r23;
  undefined *unaff_r24;
  uint unaff_r25;
  int unaff_r26;
  uint uVar26;
  int unaff_r28;
  uint unaff_r29;
  uint *puVar27;
  int unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte in_cr6;
  int iVar28;
  int iStack00000038;
  int iStack0000003c;
  int iStack00000040;
  int iStack00000044;
  undefined4 *puStack00000048;
  uint uStack0000004c;
  int in_stack_000000d0;
  
  uVar26 = unaff_r29 & 0xfffffffc;
  if (unaff_r25 < (unaff_r29 & 0xfffffffc)) {
    uVar26 = unaff_r25;
  }
  if (in_r11 == 0) {
LAB_0001f7f0:
    uVar10 = 0;
  }
  else {
    bVar2 = unaff_r24 == ((unsigned char *)0x000014ff);
    if (((bVar2) || (*(int *)(unaff_r30 + 0x24e0) != 0)) || (unaff_r22 != 0)) {
      iStack00000038 = 1;
      iStack0000003c = 1;
    }
    else if (*(int *)(unaff_r30 + 0x2494) == unaff_r30 + 0x2528) {
      iStack00000038 = 0;
      iStack0000003c = 0;
    }
    else {
      iStack00000038 = 1;
      iStack0000003c = 0;
    }
    uVar14 = -(uint)*(byte *)(unaff_r30 + 0x2802) >> 0x1e & 2;
    if (*(int *)(unaff_r30 + 0x2440) != unaff_r30 + 0x23f0) {
      uVar14 = uVar14 + (*(int *)(unaff_r30 + 0x243c) + 1U & 0xfffffffe) + 4;
    }
    if (iStack00000038 == 0) {
      piVar21 = *(int **)(unaff_r26 + 0x1d4);
    }
    else {
      piVar21 = *(int **)(unaff_r26 + 0x1d4);
      iVar13 = uVar14 + 0x14;
      if (*(int *)(*piVar21 + 0x308) != 0 || *(int *)(*piVar21 + 0x30c) != 0) {
        iVar13 = unaff_r17 + uVar14 + 0x13;
      }
      if (unaff_r22 != 0) {
        iVar13 = iVar13 + 1;
      }
      uVar14 = iVar13 + (unaff_r17 + 1U >> 1) * 3 + 3;
      if (*(int *)(unaff_r30 + 0x24e0) != 0) {
        uVar14 = uVar14 + *(int *)(unaff_r30 + 0x24e0) + 1;
      }
    }
    iStack00000044 = uVar14 + 2;
    iStack00000040 = 0;
    puStack00000048 = *(undefined4 **)(piVar21[1] + 0x80);
    if (unaff_r21 == 0) {
      iStack00000040 = *(int *)(unaff_r28 + 0x314);
    }
    uVar14 = unaff_r17 + 1U >> 1;
    piVar21 = (int *)0x0;
    puVar24 = (undefined4 *)0x0;
    iVar13 = 0;
    uStack0000004c = (uVar14 * 3 + -1) * 0x10000 | 0x831;
    while ((bool)(in_cr6 >> 2 & 1)) {
      iVar25 = iVar13 * uVar26 + unaff_r23;
      if (unaff_r25 < uVar26) {
        uVar26 = unaff_r25;
      }
      bVar3 = unaff_r24 == ((unsigned char *)0x00001403);
      if (bVar3) {
LAB_0001f1c0:
        if (unaff_r22 == 0) {
          iVar7 = (uVar26 + 1 >> 1) + 4;
        }
        else {
LAB_0001f1f0:
          iVar7 = 8;
        }
      }
      else if (((unsigned char *)0x00001403) < unaff_r24) {
        if (unaff_r24 == ((unsigned char *)0x00001405)) {
          iVar7 = uVar26 + 4;
          if (unaff_r22 != 0) goto LAB_0001f1f0;
        }
        else {
          if (!bVar2) goto LAB_0001f1ac;
          iVar7 = 4;
        }
      }
      else {
        if (unaff_r24 == ((unsigned char *)0x00001401)) goto LAB_0001f1c0;
LAB_0001f1ac:
        iVar7 = 0;
      }
      puVar8 = (uint *)(**(code **)(unaff_r30 + 0x2758))(unaff_r30,iVar7 + iStack00000044);
      cVar5 = *(char *)(unaff_r30 + 0x2802);
      *(uint **)(FUN_00002748 + unaff_r30 + 4) = puVar8;
      puVar9 = puVar8;
      if (cVar5 != '\0') {
        puVar9 = puVar8 + 2;
        *puVar8 = 0x5c8;
        puVar8[1] = 0x10000000;
        *(undefined1 *)(unaff_r30 + 0x2802) = 0;
      }
      if (*(int *)(unaff_r30 + 0x2440) != unaff_r30 + 0x23f0) {
        *(int *)(unaff_r30 + 0x2440) = unaff_r30 + 0x23f0;
        *(int *)(unaff_r30 + 0x2444) = unaff_r30 + 0x2410;
        puVar9 = (uint *)FUN_0002c0c0(unaff_r26,puVar9);
      }
      if (iStack00000038 != 0) {
        puVar24 = (undefined4 *)((uint)(puVar9 + 0xb) & 0xffffffe0);
        *(int *)(unaff_r30 + 0x2494) = unaff_r30 + 0x2528;
        *(int *)(unaff_r30 + 0x2498) = unaff_r30 + 0x2548;
        *(undefined4 *)(unaff_r30 + 0x2490) = *(undefined4 *)(unaff_r30 + 0x2588);
        *puVar9 = (((int)puVar24 - (int)puVar9) + -8) * 0x4000 | 0xc0001000;
        puVar24[-1] = (int)puVar24 - (int)puVar9;
        puVar9 = *(uint **)(unaff_r26 + 0x1d8);
        *puVar9 = *puVar9 | (int)puVar24 - (int)puVar9 >> 2;
        *(undefined4 **)(unaff_r26 + 0x1d8) = puVar24;
        *puVar24 = 0x39000000;
        puVar24[1] = unaff_r17;
        puVar24[2] = unaff_r21;
        puVar24[3] = unaff_r22;
        if (bVar3) {
          uVar10 = 2;
        }
        else {
          uVar10 = 4;
        }
        puVar24[4] = uVar10;
        puVar9 = puVar24 + 8;
        iVar7 = **(int **)(unaff_r26 + 0x1d4);
        if (*(int *)(iVar7 + 0x308) == 0 && *(int *)(iVar7 + 0x30c) == 0) {
          puVar9 = puVar24 + 9;
          puVar24[8] = *(undefined4 *)(*(int **)(unaff_r26 + 0x1d4))[0x8a];
          piVar21 = (int *)(*(int *)(*(int *)(unaff_r26 + 0x1d4) + 0x228) + 0x10);
          if (in_RESERVE != '\0') {
            iVar7 = storeWordConditionalIndexed(*piVar21 + 0x10000,0,piVar21);
            *piVar21 = iVar7;
          }
          if (unaff_r22 != 0) {
            puVar9 = puVar24 + 10;
            puVar24[9] = **(undefined4 **)(*(int *)(unaff_r26 + 0x1d4) + 0x228);
            piVar21 = (int *)(*(int *)(*(int *)(unaff_r26 + 0x1d4) + 0x228) + 0x10);
            if (in_RESERVE != '\0') {
              iVar7 = storeWordConditionalIndexed(*piVar21 + 0x10000,0,piVar21);
              *piVar21 = iVar7;
            }
          }
        }
        else {
          bVar4 = false;
          if (unaff_r17 != 0) {
            puVar20 = (undefined4 *)(unaff_r30 + 0x24e8);
            iVar7 = unaff_r17;
            if (unaff_r17 == 0) {
              iVar7 = 1;
            }
            do {
              puVar8 = (uint *)*puVar20;
              puVar20 = puVar20 + 1;
              puVar27 = puVar8 + 4;
              *puVar9 = *puVar8;
              puVar9 = puVar9 + 1;
              do {
                if (in_RESERVE != '\0') {
                  uVar12 = storeWordConditionalIndexed(*puVar27 + 0x10000,0,puVar27);
                  *puVar27 = uVar12;
                  bVar4 = true;
                }
              } while (!bVar4);
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
          if (unaff_r22 != 0) {
            *puVar9 = *(uint *)**(undefined4 **)
                                 (*(int *)(*(int *)(*(int *)(unaff_r26 + 0x1d4) + 4) + 0x80) + 8);
            puVar9 = puVar9 + 1;
            piVar21 = (int *)(**(int **)(*(int *)(*(int *)(*(int *)(unaff_r26 + 0x1d4) + 4) + 0x80)
                                        + 8) + 0x10);
            do {
              if (in_RESERVE != '\0') {
                iVar7 = storeWordConditionalIndexed(*piVar21 + 0x10000,0,piVar21);
                *piVar21 = iVar7;
                bVar4 = true;
              }
            } while (!bVar4);
          }
        }
        puVar24[5] = ((int)puVar9 - (int)puVar24 >> 2) + 2;
        if (bVar2) {
          puVar8 = puVar9 + 1;
          *puVar9 = uStack0000004c;
          if (uVar14 != 0) {
            piVar21 = (int *)(unaff_r30 + 0x254c);
            iVar7 = unaff_r30;
            uVar12 = uVar14;
            do {
              *puVar8 = *(uint *)(iVar7 + 0x2528);
              if (piVar21[-1] == -1) {
                puVar8[1] = 0xffffffff;
              }
              else {
                puVar8[1] = piVar21[-1] + unaff_r23 * (*(uint *)(iVar7 + 0x2528) >> 8 & 0x7f) * 4;
              }
              if (*piVar21 == -1) {
                puVar8[2] = 0xffffffff;
              }
              else {
                puVar8[2] = *piVar21 + unaff_r23 * (*(byte *)(iVar7 + 0x2528) & 0x7f) * 4;
              }
              puVar8 = puVar8 + 3;
              iVar7 = iVar7 + 4;
              piVar21 = piVar21 + 2;
              uVar12 = uVar12 - 1;
            } while (uVar12 != 0);
          }
          puVar9 = puVar8 + 2;
          *puVar8 = 0x830;
          puVar8[1] = *(uint *)(unaff_r30 + 0x2588);
          *(undefined4 *)(unaff_r30 + 0x2494) = 0;
        }
        else {
          puVar9 = (uint *)FUN_0002c180(unaff_r26);
        }
        piVar21 = puVar24 + 7;
        puVar24[6] = (int)puVar9 + (4 - (int)puVar24) >> 2;
        uVar12 = *(uint *)(unaff_r30 + 0x24dc);
        bVar4 = uVar12 == 0;
        if (bVar4) {
          iStack00000038 = iStack0000003c;
        }
        else {
          puVar8 = puVar9 + 1;
          *puVar9 = (*(int *)(unaff_r30 + 0x24e0) + -1) * 0x10000 | 0xc0001000;
          if (*(int *)(*(int *)(unaff_r26 + 0x14) + 0x11c) == 0) {
            iVar7 = *(int *)(unaff_r26 + 0x1cc);
            if (iVar7 != 0) goto LAB_0001f704;
            if ((uVar12 & 2) != 0) {
              puVar9[1] = *(uint *)(unaff_r18 + 0x40);
              puVar9[2] = *(uint *)(unaff_r18 + 0x44);
              puVar8 = puVar9 + 5;
              uVar18 = *(uint *)(unaff_r18 + 0x48);
              puVar9[4] = 0x3f800000;
              puVar9[3] = uVar18;
            }
            if ((uVar12 & 4) != 0) {
              *puVar8 = *(uint *)(unaff_r18 + 0x30);
              puVar8[1] = *(uint *)(unaff_r18 + 0x34);
              puVar8[2] = *(uint *)(unaff_r18 + 0x38);
              puVar8[3] = *(uint *)(unaff_r18 + 0x3c);
              puVar8 = puVar8 + 4;
            }
            if ((uVar12 & 8) != 0) {
              *puVar8 = *(uint *)(unaff_r18 + 0x50);
              puVar8[1] = *(uint *)(unaff_r18 + 0x54);
              uVar18 = *(uint *)(unaff_r18 + 0x58);
              puVar8[3] = 0x3f800000;
              puVar8[2] = uVar18;
              puVar8 = puVar8 + 4;
            }
            uVar18 = 0;
            iVar28 = 8;
            iVar7 = unaff_r18;
            do {
              if ((uVar12 & 0x400 << (uVar18 & 0x3f)) != 0) {
                *puVar8 = *(uint *)(iVar7 + 0x80);
                puVar8[1] = *(uint *)(iVar7 + 0x84);
                puVar8[2] = *(uint *)(iVar7 + 0x88);
                puVar8[3] = *(uint *)(iVar7 + 0x8c);
                puVar8 = puVar8 + 4;
              }
              uVar18 = uVar18 + 1;
              iVar7 = iVar7 + 0x10;
              iVar28 = iVar28 + -1;
            } while (iVar28 != 0);
            if ((uVar12 & 0x40000) != 0) {
              uVar18 = *(uint *)(unaff_r18 + 0x5c);
              puVar8[3] = 0x3f800000;
              puVar8[1] = 0x3f800000;
              puVar8[2] = 0x3f800000;
              *puVar8 = uVar18;
              puVar8 = puVar8 + 4;
            }
            puVar9 = puVar8;
            if ((uVar12 & 0x80000) != 0) {
              *puVar8 = *(uint *)(unaff_r18 + 0x60);
              puVar8[1] = *(uint *)(unaff_r18 + 100);
              puVar8[2] = *(uint *)(unaff_r18 + 0x68);
              puVar8[3] = *(uint *)(unaff_r18 + 0x6c);
              puVar9 = puVar8 + 4;
            }
          }
          else {
            iVar7 = *(int *)(unaff_r26 + 0x1cc);
LAB_0001f704:
            iVar15 = *(int *)(*(int *)(unaff_r26 + 0x14) + 0x11c);
            iVar28 = 0x16;
            puVar9 = puVar8;
            if ((iVar7 == 0) ||
               (iVar28 = *(int *)(*(int *)(FUN_000027a4 + unaff_r30 + 4) + 0x28), iVar28 != 0)) {
              uVar18 = 0;
              puVar8 = (uint *)(unaff_r30 + 0x259c);
              do {
                uVar16 = 1 << (uVar18 & 0x3f);
                if ((uVar12 & uVar16) != 0) {
                  uVar17 = uVar18;
                  if (iVar15 != 0) {
                    uVar17 = *puVar8;
                  }
                  uVar12 = uVar12 & ~uVar16;
                  iVar7 = unaff_r18 + uVar17 * 0x10;
                  bVar4 = uVar12 == 0;
                  *puVar9 = *(uint *)(unaff_r18 + uVar17 * 0x10);
                  puVar9[1] = *(uint *)(iVar7 + 4);
                  puVar9[2] = *(uint *)(iVar7 + 8);
                  puVar9[3] = *(uint *)(iVar7 + 0xc);
                  puVar9 = puVar9 + 4;
                }
                if (bVar4) break;
                uVar18 = uVar18 + 1;
                puVar8 = puVar8 + 1;
                iVar28 = iVar28 + -1;
              } while (iVar28 != 0);
            }
          }
          iStack00000038 = iStack0000003c;
        }
      }
      puVar22 = &UNK_001ba4e4 + unaff_r31;
      dataCacheBlockTouch(puVar22);
      if (bVar3) {
        puVar8 = (uint *)(iVar25 * 2 + in_stack_000000d0);
        dataCacheBlockTouch(puVar8);
        dataCacheBlockTouch((int)puVar8 + (uint)*(byte *)(unaff_r26 + 8));
        uVar12 = uVar26 << 0x10 | *(uint *)(puVar22 + unaff_r19 * 4) & 0xf | 0x10;
        if (unaff_r22 == 0) {
          *puVar9 = 0x82c;
          uVar18 = uVar26 + 1 >> 1;
          puVar27 = puVar9 + 4;
          uVar16 = *(uint *)(unaff_r30 + 0x1b84);
          puVar9[2] = uVar18 << 0x10 | 0xc0003600;
          puVar9[3] = uVar12;
          puVar9[1] = uVar16;
          if (uVar26 < 0x201) {
            uVar12 = uVar26 >> 3;
            puVar9 = puVar8;
            if (uVar12 != 0) {
              if (uVar12 == 0) {
                uVar12 = 1;
              }
              do {
                uVar18 = *puVar9;
                uVar16 = puVar9[1];
                uVar17 = puVar9[2];
                uVar23 = puVar9[3];
                puVar9 = puVar9 + 4;
                *puVar27 = uVar18 << 0x10 | uVar18 >> 0x10;
                puVar27[1] = uVar16 << 0x10 | uVar16 >> 0x10;
                puVar27[2] = uVar17 << 0x10 | uVar17 >> 0x10;
                puVar27[3] = uVar23 << 0x10 | uVar23 >> 0x10;
                puVar27 = puVar27 + 4;
                uVar12 = uVar12 - 1;
              } while (uVar12 != 0);
            }
            uVar12 = uVar26 >> 1 & 3;
            if (uVar12 != 0) {
              if (uVar12 == 0) {
                uVar12 = 1;
              }
              do {
                uVar18 = *puVar9;
                puVar9 = puVar9 + 1;
                *puVar27 = uVar18 << 0x10 | uVar18 >> 0x10;
                puVar27 = puVar27 + 1;
                uVar12 = uVar12 - 1;
              } while (uVar12 != 0);
            }
            if ((uVar26 & 1) != 0) {
              *puVar27 = (uint)*(ushort *)((int)puVar8 + uVar26 * 2 + -2);
              puVar27 = puVar27 + 1;
            }
          }
          else {
            if (*(char *)(unaff_r26 + 8) == -0x80) {
              FUN_0001eae0(puVar27,puVar8,uVar26);
            }
            else {
              FUN_0001e890(puVar27,puVar8,uVar26);
            }
            puVar27 = puVar27 + uVar18;
          }
        }
        else {
          *puVar9 = 0x82c;
          uVar18 = *(uint *)(unaff_r30 + 0x1b84);
          puVar9[2] = 0xc0003600;
          puVar9[3] = uVar12;
          puVar9[1] = uVar18;
          *piVar21 = (int)puVar9 + (0x10 - (int)puVar24) >> 2;
          piVar21 = piVar21 + 1;
          puVar9[4] = 0xc0023300;
          puVar9[5] = 0x80000810;
          if (puStack00000048 == (undefined4 *)0x0) {
            puVar9[6] = (int)puVar8 - iStack00000040;
          }
          else {
            puVar9[6] = (int)puVar8 - *(int *)*puStack00000048;
          }
          puVar27 = puVar9 + 8;
          puVar9[7] = uVar26 + 1 >> 1;
        }
      }
      else if (((unsigned char *)0x00001403) < unaff_r24) {
        if (unaff_r24 == ((unsigned char *)0x00001405)) {
          pvVar11 = (void *)(iVar25 * 4 + in_stack_000000d0);
          uVar12 = uVar26 << 0x10 | *(uint *)(puVar22 + unaff_r19 * 4) & 0xf | 0x810;
          if (unaff_r22 == 0) {
            *puVar9 = 0x82c;
            puVar27 = puVar9 + 4 + uVar26;
            uVar18 = *(uint *)(unaff_r30 + 0x1b84);
            puVar9[2] = uVar26 << 0x10 | 0xc0003600;
            puVar9[3] = uVar12;
            puVar9[1] = uVar18;
            _memcpy(puVar9 + 4,pvVar11,uVar26 * 4);
          }
          else {
            *puVar9 = 0x82c;
            uVar18 = *(uint *)(unaff_r30 + 0x1b84);
            puVar9[2] = 0xc0003600;
            puVar9[3] = uVar12;
            puVar9[1] = uVar18;
            *piVar21 = (int)puVar9 + (0x10 - (int)puVar24) >> 2;
            puVar9[4] = 0xc0023300;
            puVar9[5] = 0x80000810;
            piVar21 = piVar21 + 1;
            if (puStack00000048 == (undefined4 *)0x0) {
              puVar9[6] = (int)pvVar11 - iStack00000040;
            }
            else {
              puVar9[6] = (int)pvVar11 - *(int *)*puStack00000048;
            }
            puVar27 = puVar9 + 8;
            puVar9[7] = uVar26;
          }
        }
        else {
          if (!bVar2) goto LAB_0001f7f0;
          puVar27 = puVar9 + 4;
          uVar18 = *(uint *)(puVar22 + unaff_r19 * 4);
          *puVar9 = 0x82c;
          unaff_r23 = unaff_r23 + uVar26;
          uVar12 = *(uint *)(unaff_r30 + 0x1b84);
          puVar9[2] = 0xc0003400;
          puVar9[1] = uVar12;
          puVar9[3] = uVar26 << 0x10 | uVar18 & 0xf | 0x820;
        }
      }
      else {
        if (unaff_r24 != ((unsigned char *)0x00001401)) goto LAB_0001f7f0;
        uVar18 = *(uint *)(puVar22 + unaff_r19 * 4);
        *puVar9 = 0x82c;
        puVar27 = puVar9 + 4;
        uVar12 = *(uint *)(unaff_r30 + 0x1b84);
        puVar9[2] = (uVar26 + 1) * 0x8000 & 0xffff0000 | 0xc0003600;
        puVar9[1] = uVar12;
        puVar9[3] = uVar26 << 0x10 | uVar18 & 0xf | 0x10;
        if ((uVar26 & 0xfffffffe) != 0) {
          uVar12 = 0;
          pbVar19 = (byte *)(in_stack_000000d0 + iVar25);
          do {
            pbVar1 = pbVar19 + 1;
            uVar12 = uVar12 + 2;
            bVar6 = *pbVar19;
            pbVar19 = pbVar19 + 2;
            *puVar27 = (uint)*pbVar1 << 0x10 | (uint)bVar6;
            puVar27 = puVar27 + 1;
          } while (uVar12 < (uVar26 & 0xfffffffe));
        }
        if ((uVar26 & 1) != 0) {
          *puVar27 = (uint)((byte *)(in_stack_000000d0 + iVar25))[uVar26 - 1];
          puVar27 = puVar27 + 1;
        }
      }
      unaff_r25 = unaff_r25 - uVar26;
      *puVar27 = (uint)((unsigned char *)0x00001393);
      puVar27[1] = 0;
      puVar27 = puVar27 + 2;
      iVar13 = iVar13 + 1;
      *(uint **)(FUN_00002748 + unaff_r30 + 4) = puVar27;
      (**(code **)(unaff_r30 + 0x275c))(unaff_r30,puVar27);
      in_cr6 = (0 < (int)unaff_r25) << 2;
      if (*(uint **)(unaff_r26 + 0x2994) <= puVar27) {
        pbVar19 = *(byte **)(unaff_r26 + 0x238);
        if (((uint)pbVar19[3] << 0x18 | (uint)pbVar19[2] << 0x10 | (uint)pbVar19[1] << 8 |
            (uint)*pbVar19) == *(uint *)(pbVar19 + 0x20)) {
          FUN_0001a0f0(unaff_r26,0x1000000);
          in_cr6 = (0 < (int)unaff_r25) << 2;
        }
        else {
          in_cr6 = (0 < (int)unaff_r25) << 2;
          *(uint **)(unaff_r26 + 0x2994) = *(uint **)(unaff_r26 + 0x2994) + 0x1000;
        }
      }
    }
    uVar10 = 1;
    *(undefined1 *)(unaff_r30 + 0x281e) = 1;
    *(undefined1 *)(unaff_r30 + 0x2595) = 1;
  }
  return uVar10;
}

/* orph_1eff8 @ 0x1eff8 (3228 bytes) */
int orph_1eff8()
{
  byte *pbVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  byte bVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  undefined4 uVar10;
  void *pvVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  byte *pbVar19;
  undefined4 *puVar20;
  int in_r11;
  int *piVar21;
  undefined *puVar22;
  uint uVar23;
  undefined4 *puVar24;
  int unaff_r17;
  int unaff_r18;
  int unaff_r19;
  int iVar25;
  int unaff_r21;
  int unaff_r22;
  int unaff_r23;
  undefined *unaff_r24;
  uint unaff_r25;
  int unaff_r26;
  uint uVar26;
  int unaff_r28;
  uint unaff_r29;
  uint *puVar27;
  int unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte in_cr6;
  int iVar28;
  int iStack00000038;
  int iStack0000003c;
  int iStack00000040;
  int iStack00000044;
  undefined4 *puStack00000048;
  uint uStack0000004c;
  int in_stack_000000d0;
  
  uVar26 = unaff_r29 & 0xfffffffe;
  if (unaff_r25 < (unaff_r29 & 0xfffffffe)) {
    uVar26 = unaff_r25;
  }
  if (in_r11 == 0) {
LAB_0001f7f0:
    uVar10 = 0;
  }
  else {
    bVar2 = unaff_r24 == ((unsigned char *)0x000014ff);
    if (((bVar2) || (*(int *)(unaff_r30 + 0x24e0) != 0)) || (unaff_r22 != 0)) {
      iStack00000038 = 1;
      iStack0000003c = 1;
    }
    else if (*(int *)(unaff_r30 + 0x2494) == unaff_r30 + 0x2528) {
      iStack00000038 = 0;
      iStack0000003c = 0;
    }
    else {
      iStack00000038 = 1;
      iStack0000003c = 0;
    }
    uVar14 = -(uint)*(byte *)(unaff_r30 + 0x2802) >> 0x1e & 2;
    if (*(int *)(unaff_r30 + 0x2440) != unaff_r30 + 0x23f0) {
      uVar14 = uVar14 + (*(int *)(unaff_r30 + 0x243c) + 1U & 0xfffffffe) + 4;
    }
    if (iStack00000038 == 0) {
      piVar21 = *(int **)(unaff_r26 + 0x1d4);
    }
    else {
      piVar21 = *(int **)(unaff_r26 + 0x1d4);
      iVar13 = uVar14 + 0x14;
      if (*(int *)(*piVar21 + 0x308) != 0 || *(int *)(*piVar21 + 0x30c) != 0) {
        iVar13 = unaff_r17 + uVar14 + 0x13;
      }
      if (unaff_r22 != 0) {
        iVar13 = iVar13 + 1;
      }
      uVar14 = iVar13 + (unaff_r17 + 1U >> 1) * 3 + 3;
      if (*(int *)(unaff_r30 + 0x24e0) != 0) {
        uVar14 = uVar14 + *(int *)(unaff_r30 + 0x24e0) + 1;
      }
    }
    iStack00000044 = uVar14 + 2;
    iStack00000040 = 0;
    puStack00000048 = *(undefined4 **)(piVar21[1] + 0x80);
    if (unaff_r21 == 0) {
      iStack00000040 = *(int *)(unaff_r28 + 0x314);
    }
    uVar14 = unaff_r17 + 1U >> 1;
    piVar21 = (int *)0x0;
    puVar24 = (undefined4 *)0x0;
    iVar13 = 0;
    uStack0000004c = (uVar14 * 3 + -1) * 0x10000 | 0x831;
    while ((bool)(in_cr6 >> 2 & 1)) {
      iVar25 = iVar13 * uVar26 + unaff_r23;
      if (unaff_r25 < uVar26) {
        uVar26 = unaff_r25;
      }
      bVar3 = unaff_r24 == ((unsigned char *)0x00001403);
      if (bVar3) {
LAB_0001f1c0:
        if (unaff_r22 == 0) {
          iVar7 = (uVar26 + 1 >> 1) + 4;
        }
        else {
LAB_0001f1f0:
          iVar7 = 8;
        }
      }
      else if (((unsigned char *)0x00001403) < unaff_r24) {
        if (unaff_r24 == ((unsigned char *)0x00001405)) {
          iVar7 = uVar26 + 4;
          if (unaff_r22 != 0) goto LAB_0001f1f0;
        }
        else {
          if (!bVar2) goto LAB_0001f1ac;
          iVar7 = 4;
        }
      }
      else {
        if (unaff_r24 == ((unsigned char *)0x00001401)) goto LAB_0001f1c0;
LAB_0001f1ac:
        iVar7 = 0;
      }
      puVar8 = (uint *)(**(code **)(unaff_r30 + 0x2758))(unaff_r30,iVar7 + iStack00000044);
      cVar5 = *(char *)(unaff_r30 + 0x2802);
      *(uint **)(FUN_00002748 + unaff_r30 + 4) = puVar8;
      puVar9 = puVar8;
      if (cVar5 != '\0') {
        puVar9 = puVar8 + 2;
        *puVar8 = 0x5c8;
        puVar8[1] = 0x10000000;
        *(undefined1 *)(unaff_r30 + 0x2802) = 0;
      }
      if (*(int *)(unaff_r30 + 0x2440) != unaff_r30 + 0x23f0) {
        *(int *)(unaff_r30 + 0x2440) = unaff_r30 + 0x23f0;
        *(int *)(unaff_r30 + 0x2444) = unaff_r30 + 0x2410;
        puVar9 = (uint *)FUN_0002c0c0(unaff_r26,puVar9);
      }
      if (iStack00000038 != 0) {
        puVar24 = (undefined4 *)((uint)(puVar9 + 0xb) & 0xffffffe0);
        *(int *)(unaff_r30 + 0x2494) = unaff_r30 + 0x2528;
        *(int *)(unaff_r30 + 0x2498) = unaff_r30 + 0x2548;
        *(undefined4 *)(unaff_r30 + 0x2490) = *(undefined4 *)(unaff_r30 + 0x2588);
        *puVar9 = (((int)puVar24 - (int)puVar9) + -8) * 0x4000 | 0xc0001000;
        puVar24[-1] = (int)puVar24 - (int)puVar9;
        puVar9 = *(uint **)(unaff_r26 + 0x1d8);
        *puVar9 = *puVar9 | (int)puVar24 - (int)puVar9 >> 2;
        *(undefined4 **)(unaff_r26 + 0x1d8) = puVar24;
        *puVar24 = 0x39000000;
        puVar24[1] = unaff_r17;
        puVar24[2] = unaff_r21;
        puVar24[3] = unaff_r22;
        if (bVar3) {
          uVar10 = 2;
        }
        else {
          uVar10 = 4;
        }
        puVar24[4] = uVar10;
        puVar9 = puVar24 + 8;
        iVar7 = **(int **)(unaff_r26 + 0x1d4);
        if (*(int *)(iVar7 + 0x308) == 0 && *(int *)(iVar7 + 0x30c) == 0) {
          puVar9 = puVar24 + 9;
          puVar24[8] = *(undefined4 *)(*(int **)(unaff_r26 + 0x1d4))[0x8a];
          piVar21 = (int *)(*(int *)(*(int *)(unaff_r26 + 0x1d4) + 0x228) + 0x10);
          if (in_RESERVE != '\0') {
            iVar7 = storeWordConditionalIndexed(*piVar21 + 0x10000,0,piVar21);
            *piVar21 = iVar7;
          }
          if (unaff_r22 != 0) {
            puVar9 = puVar24 + 10;
            puVar24[9] = **(undefined4 **)(*(int *)(unaff_r26 + 0x1d4) + 0x228);
            piVar21 = (int *)(*(int *)(*(int *)(unaff_r26 + 0x1d4) + 0x228) + 0x10);
            if (in_RESERVE != '\0') {
              iVar7 = storeWordConditionalIndexed(*piVar21 + 0x10000,0,piVar21);
              *piVar21 = iVar7;
            }
          }
        }
        else {
          bVar4 = false;
          if (unaff_r17 != 0) {
            puVar20 = (undefined4 *)(unaff_r30 + 0x24e8);
            iVar7 = unaff_r17;
            if (unaff_r17 == 0) {
              iVar7 = 1;
            }
            do {
              puVar8 = (uint *)*puVar20;
              puVar20 = puVar20 + 1;
              puVar27 = puVar8 + 4;
              *puVar9 = *puVar8;
              puVar9 = puVar9 + 1;
              do {
                if (in_RESERVE != '\0') {
                  uVar12 = storeWordConditionalIndexed(*puVar27 + 0x10000,0,puVar27);
                  *puVar27 = uVar12;
                  bVar4 = true;
                }
              } while (!bVar4);
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
          if (unaff_r22 != 0) {
            *puVar9 = *(uint *)**(undefined4 **)
                                 (*(int *)(*(int *)(*(int *)(unaff_r26 + 0x1d4) + 4) + 0x80) + 8);
            puVar9 = puVar9 + 1;
            piVar21 = (int *)(**(int **)(*(int *)(*(int *)(*(int *)(unaff_r26 + 0x1d4) + 4) + 0x80)
                                        + 8) + 0x10);
            do {
              if (in_RESERVE != '\0') {
                iVar7 = storeWordConditionalIndexed(*piVar21 + 0x10000,0,piVar21);
                *piVar21 = iVar7;
                bVar4 = true;
              }
            } while (!bVar4);
          }
        }
        puVar24[5] = ((int)puVar9 - (int)puVar24 >> 2) + 2;
        if (bVar2) {
          puVar8 = puVar9 + 1;
          *puVar9 = uStack0000004c;
          if (uVar14 != 0) {
            piVar21 = (int *)(unaff_r30 + 0x254c);
            iVar7 = unaff_r30;
            uVar12 = uVar14;
            do {
              *puVar8 = *(uint *)(iVar7 + 0x2528);
              if (piVar21[-1] == -1) {
                puVar8[1] = 0xffffffff;
              }
              else {
                puVar8[1] = piVar21[-1] + unaff_r23 * (*(uint *)(iVar7 + 0x2528) >> 8 & 0x7f) * 4;
              }
              if (*piVar21 == -1) {
                puVar8[2] = 0xffffffff;
              }
              else {
                puVar8[2] = *piVar21 + unaff_r23 * (*(byte *)(iVar7 + 0x2528) & 0x7f) * 4;
              }
              puVar8 = puVar8 + 3;
              iVar7 = iVar7 + 4;
              piVar21 = piVar21 + 2;
              uVar12 = uVar12 - 1;
            } while (uVar12 != 0);
          }
          puVar9 = puVar8 + 2;
          *puVar8 = 0x830;
          puVar8[1] = *(uint *)(unaff_r30 + 0x2588);
          *(undefined4 *)(unaff_r30 + 0x2494) = 0;
        }
        else {
          puVar9 = (uint *)FUN_0002c180(unaff_r26);
        }
        piVar21 = puVar24 + 7;
        puVar24[6] = (int)puVar9 + (4 - (int)puVar24) >> 2;
        uVar12 = *(uint *)(unaff_r30 + 0x24dc);
        bVar4 = uVar12 == 0;
        if (bVar4) {
          iStack00000038 = iStack0000003c;
        }
        else {
          puVar8 = puVar9 + 1;
          *puVar9 = (*(int *)(unaff_r30 + 0x24e0) + -1) * 0x10000 | 0xc0001000;
          if (*(int *)(*(int *)(unaff_r26 + 0x14) + 0x11c) == 0) {
            iVar7 = *(int *)(unaff_r26 + 0x1cc);
            if (iVar7 != 0) goto LAB_0001f704;
            if ((uVar12 & 2) != 0) {
              puVar9[1] = *(uint *)(unaff_r18 + 0x40);
              puVar9[2] = *(uint *)(unaff_r18 + 0x44);
              puVar8 = puVar9 + 5;
              uVar18 = *(uint *)(unaff_r18 + 0x48);
              puVar9[4] = 0x3f800000;
              puVar9[3] = uVar18;
            }
            if ((uVar12 & 4) != 0) {
              *puVar8 = *(uint *)(unaff_r18 + 0x30);
              puVar8[1] = *(uint *)(unaff_r18 + 0x34);
              puVar8[2] = *(uint *)(unaff_r18 + 0x38);
              puVar8[3] = *(uint *)(unaff_r18 + 0x3c);
              puVar8 = puVar8 + 4;
            }
            if ((uVar12 & 8) != 0) {
              *puVar8 = *(uint *)(unaff_r18 + 0x50);
              puVar8[1] = *(uint *)(unaff_r18 + 0x54);
              uVar18 = *(uint *)(unaff_r18 + 0x58);
              puVar8[3] = 0x3f800000;
              puVar8[2] = uVar18;
              puVar8 = puVar8 + 4;
            }
            uVar18 = 0;
            iVar28 = 8;
            iVar7 = unaff_r18;
            do {
              if ((uVar12 & 0x400 << (uVar18 & 0x3f)) != 0) {
                *puVar8 = *(uint *)(iVar7 + 0x80);
                puVar8[1] = *(uint *)(iVar7 + 0x84);
                puVar8[2] = *(uint *)(iVar7 + 0x88);
                puVar8[3] = *(uint *)(iVar7 + 0x8c);
                puVar8 = puVar8 + 4;
              }
              uVar18 = uVar18 + 1;
              iVar7 = iVar7 + 0x10;
              iVar28 = iVar28 + -1;
            } while (iVar28 != 0);
            if ((uVar12 & 0x40000) != 0) {
              uVar18 = *(uint *)(unaff_r18 + 0x5c);
              puVar8[3] = 0x3f800000;
              puVar8[1] = 0x3f800000;
              puVar8[2] = 0x3f800000;
              *puVar8 = uVar18;
              puVar8 = puVar8 + 4;
            }
            puVar9 = puVar8;
            if ((uVar12 & 0x80000) != 0) {
              *puVar8 = *(uint *)(unaff_r18 + 0x60);
              puVar8[1] = *(uint *)(unaff_r18 + 100);
              puVar8[2] = *(uint *)(unaff_r18 + 0x68);
              puVar8[3] = *(uint *)(unaff_r18 + 0x6c);
              puVar9 = puVar8 + 4;
            }
          }
          else {
            iVar7 = *(int *)(unaff_r26 + 0x1cc);
LAB_0001f704:
            iVar15 = *(int *)(*(int *)(unaff_r26 + 0x14) + 0x11c);
            iVar28 = 0x16;
            puVar9 = puVar8;
            if ((iVar7 == 0) ||
               (iVar28 = *(int *)(*(int *)(FUN_000027a4 + unaff_r30 + 4) + 0x28), iVar28 != 0)) {
              uVar18 = 0;
              puVar8 = (uint *)(unaff_r30 + 0x259c);
              do {
                uVar16 = 1 << (uVar18 & 0x3f);
                if ((uVar12 & uVar16) != 0) {
                  uVar17 = uVar18;
                  if (iVar15 != 0) {
                    uVar17 = *puVar8;
                  }
                  uVar12 = uVar12 & ~uVar16;
                  iVar7 = unaff_r18 + uVar17 * 0x10;
                  bVar4 = uVar12 == 0;
                  *puVar9 = *(uint *)(unaff_r18 + uVar17 * 0x10);
                  puVar9[1] = *(uint *)(iVar7 + 4);
                  puVar9[2] = *(uint *)(iVar7 + 8);
                  puVar9[3] = *(uint *)(iVar7 + 0xc);
                  puVar9 = puVar9 + 4;
                }
                if (bVar4) break;
                uVar18 = uVar18 + 1;
                puVar8 = puVar8 + 1;
                iVar28 = iVar28 + -1;
              } while (iVar28 != 0);
            }
          }
          iStack00000038 = iStack0000003c;
        }
      }
      puVar22 = &UNK_001ba4e4 + unaff_r31;
      dataCacheBlockTouch(puVar22);
      if (bVar3) {
        puVar8 = (uint *)(iVar25 * 2 + in_stack_000000d0);
        dataCacheBlockTouch(puVar8);
        dataCacheBlockTouch((int)puVar8 + (uint)*(byte *)(unaff_r26 + 8));
        uVar12 = uVar26 << 0x10 | *(uint *)(puVar22 + unaff_r19 * 4) & 0xf | 0x10;
        if (unaff_r22 == 0) {
          *puVar9 = 0x82c;
          uVar18 = uVar26 + 1 >> 1;
          puVar27 = puVar9 + 4;
          uVar16 = *(uint *)(unaff_r30 + 0x1b84);
          puVar9[2] = uVar18 << 0x10 | 0xc0003600;
          puVar9[3] = uVar12;
          puVar9[1] = uVar16;
          if (uVar26 < 0x201) {
            uVar12 = uVar26 >> 3;
            puVar9 = puVar8;
            if (uVar12 != 0) {
              if (uVar12 == 0) {
                uVar12 = 1;
              }
              do {
                uVar18 = *puVar9;
                uVar16 = puVar9[1];
                uVar17 = puVar9[2];
                uVar23 = puVar9[3];
                puVar9 = puVar9 + 4;
                *puVar27 = uVar18 << 0x10 | uVar18 >> 0x10;
                puVar27[1] = uVar16 << 0x10 | uVar16 >> 0x10;
                puVar27[2] = uVar17 << 0x10 | uVar17 >> 0x10;
                puVar27[3] = uVar23 << 0x10 | uVar23 >> 0x10;
                puVar27 = puVar27 + 4;
                uVar12 = uVar12 - 1;
              } while (uVar12 != 0);
            }
            uVar12 = uVar26 >> 1 & 3;
            if (uVar12 != 0) {
              if (uVar12 == 0) {
                uVar12 = 1;
              }
              do {
                uVar18 = *puVar9;
                puVar9 = puVar9 + 1;
                *puVar27 = uVar18 << 0x10 | uVar18 >> 0x10;
                puVar27 = puVar27 + 1;
                uVar12 = uVar12 - 1;
              } while (uVar12 != 0);
            }
            if ((uVar26 & 1) != 0) {
              *puVar27 = (uint)*(ushort *)((int)puVar8 + uVar26 * 2 + -2);
              puVar27 = puVar27 + 1;
            }
          }
          else {
            if (*(char *)(unaff_r26 + 8) == -0x80) {
              FUN_0001eae0(puVar27,puVar8,uVar26);
            }
            else {
              FUN_0001e890(puVar27,puVar8,uVar26);
            }
            puVar27 = puVar27 + uVar18;
          }
        }
        else {
          *puVar9 = 0x82c;
          uVar18 = *(uint *)(unaff_r30 + 0x1b84);
          puVar9[2] = 0xc0003600;
          puVar9[3] = uVar12;
          puVar9[1] = uVar18;
          *piVar21 = (int)puVar9 + (0x10 - (int)puVar24) >> 2;
          piVar21 = piVar21 + 1;
          puVar9[4] = 0xc0023300;
          puVar9[5] = 0x80000810;
          if (puStack00000048 == (undefined4 *)0x0) {
            puVar9[6] = (int)puVar8 - iStack00000040;
          }
          else {
            puVar9[6] = (int)puVar8 - *(int *)*puStack00000048;
          }
          puVar27 = puVar9 + 8;
          puVar9[7] = uVar26 + 1 >> 1;
        }
      }
      else if (((unsigned char *)0x00001403) < unaff_r24) {
        if (unaff_r24 == ((unsigned char *)0x00001405)) {
          pvVar11 = (void *)(iVar25 * 4 + in_stack_000000d0);
          uVar12 = uVar26 << 0x10 | *(uint *)(puVar22 + unaff_r19 * 4) & 0xf | 0x810;
          if (unaff_r22 == 0) {
            *puVar9 = 0x82c;
            puVar27 = puVar9 + 4 + uVar26;
            uVar18 = *(uint *)(unaff_r30 + 0x1b84);
            puVar9[2] = uVar26 << 0x10 | 0xc0003600;
            puVar9[3] = uVar12;
            puVar9[1] = uVar18;
            _memcpy(puVar9 + 4,pvVar11,uVar26 * 4);
          }
          else {
            *puVar9 = 0x82c;
            uVar18 = *(uint *)(unaff_r30 + 0x1b84);
            puVar9[2] = 0xc0003600;
            puVar9[3] = uVar12;
            puVar9[1] = uVar18;
            *piVar21 = (int)puVar9 + (0x10 - (int)puVar24) >> 2;
            puVar9[4] = 0xc0023300;
            puVar9[5] = 0x80000810;
            piVar21 = piVar21 + 1;
            if (puStack00000048 == (undefined4 *)0x0) {
              puVar9[6] = (int)pvVar11 - iStack00000040;
            }
            else {
              puVar9[6] = (int)pvVar11 - *(int *)*puStack00000048;
            }
            puVar27 = puVar9 + 8;
            puVar9[7] = uVar26;
          }
        }
        else {
          if (!bVar2) goto LAB_0001f7f0;
          puVar27 = puVar9 + 4;
          uVar18 = *(uint *)(puVar22 + unaff_r19 * 4);
          *puVar9 = 0x82c;
          unaff_r23 = unaff_r23 + uVar26;
          uVar12 = *(uint *)(unaff_r30 + 0x1b84);
          puVar9[2] = 0xc0003400;
          puVar9[1] = uVar12;
          puVar9[3] = uVar26 << 0x10 | uVar18 & 0xf | 0x820;
        }
      }
      else {
        if (unaff_r24 != ((unsigned char *)0x00001401)) goto LAB_0001f7f0;
        uVar18 = *(uint *)(puVar22 + unaff_r19 * 4);
        *puVar9 = 0x82c;
        puVar27 = puVar9 + 4;
        uVar12 = *(uint *)(unaff_r30 + 0x1b84);
        puVar9[2] = (uVar26 + 1) * 0x8000 & 0xffff0000 | 0xc0003600;
        puVar9[1] = uVar12;
        puVar9[3] = uVar26 << 0x10 | uVar18 & 0xf | 0x10;
        if ((uVar26 & 0xfffffffe) != 0) {
          uVar12 = 0;
          pbVar19 = (byte *)(in_stack_000000d0 + iVar25);
          do {
            pbVar1 = pbVar19 + 1;
            uVar12 = uVar12 + 2;
            bVar6 = *pbVar19;
            pbVar19 = pbVar19 + 2;
            *puVar27 = (uint)*pbVar1 << 0x10 | (uint)bVar6;
            puVar27 = puVar27 + 1;
          } while (uVar12 < (uVar26 & 0xfffffffe));
        }
        if ((uVar26 & 1) != 0) {
          *puVar27 = (uint)((byte *)(in_stack_000000d0 + iVar25))[uVar26 - 1];
          puVar27 = puVar27 + 1;
        }
      }
      unaff_r25 = unaff_r25 - uVar26;
      *puVar27 = (uint)((unsigned char *)0x00001393);
      puVar27[1] = 0;
      puVar27 = puVar27 + 2;
      iVar13 = iVar13 + 1;
      *(uint **)(FUN_00002748 + unaff_r30 + 4) = puVar27;
      (**(code **)(unaff_r30 + 0x275c))(unaff_r30,puVar27);
      in_cr6 = (0 < (int)unaff_r25) << 2;
      if (*(uint **)(unaff_r26 + 0x2994) <= puVar27) {
        pbVar19 = *(byte **)(unaff_r26 + 0x238);
        if (((uint)pbVar19[3] << 0x18 | (uint)pbVar19[2] << 0x10 | (uint)pbVar19[1] << 8 |
            (uint)*pbVar19) == *(uint *)(pbVar19 + 0x20)) {
          FUN_0001a0f0(unaff_r26,0x1000000);
          in_cr6 = (0 < (int)unaff_r25) << 2;
        }
        else {
          in_cr6 = (0 < (int)unaff_r25) << 2;
          *(uint **)(unaff_r26 + 0x2994) = *(uint **)(unaff_r26 + 0x2994) + 0x1000;
        }
      }
    }
    uVar10 = 1;
    *(undefined1 *)(unaff_r30 + 0x281e) = 1;
    *(undefined1 *)(unaff_r30 + 0x2595) = 1;
  }
  return uVar10;
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
int orph_4c544(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x1e68) = 0;
  FUN_0004a860();
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

/* orph_c5538 @ 0xc5538 (52 bytes) */
int orph_c5538(param_1)
  uint param_1;
{
  int unaff_r31;
  
  if (param_1 < 0x20) {
                    
                    
    (*(code *)(*(int *)(param_1 * 4 + unaff_r31 + 0x144) + unaff_r31 + 0x144))();
    return;
  }
  return;
}

/* orph_c5540 @ 0xc5540 (52 bytes) */
int orph_c5540(param_1)
  uint param_1;
{
  int unaff_r31;
  
  if (param_1 < 0x20) {
                    
                    
    (*(code *)(*(int *)(param_1 * 4 + unaff_r31 + 0x144) + unaff_r31 + 0x144))();
    return;
  }
  return;
}

/* orph_c5548 @ 0xc5548 (52 bytes) */
int orph_c5548(param_1)
  uint param_1;
{
  int unaff_r31;
  
  if (param_1 < 0x20) {
                    
                    
    (*(code *)(*(int *)(param_1 * 4 + unaff_r31 + 0x144) + unaff_r31 + 0x144))();
    return;
  }
  return;
}

/* orph_c5550 @ 0xc5550 (60 bytes) */
int orph_c5550(param_1)
  uint param_1;
{
  int unaff_r31;
  
  if (param_1 < 0x20) {
                    
                    
    (*(code *)(*(int *)(param_1 * 4 + unaff_r31 + 0x144) + unaff_r31 + 0x144))();
    return;
  }
  return;
}

/* orph_c5560 @ 0xc5560 (60 bytes) */
int orph_c5560(param_1)
  uint param_1;
{
  int unaff_r31;
  
  if (param_1 < 0x20) {
                    
                    
    (*(code *)(*(int *)(param_1 * 4 + unaff_r31 + 0x144) + unaff_r31 + 0x144))();
    return;
  }
  return;
}

/* orph_c5570 @ 0xc5570 (76 bytes) */
int orph_c5570(param_1)
  uint param_1;
{
  int unaff_r31;
  
  if (param_1 < 0x20) {
                    
                    
    (*(code *)(*(int *)(param_1 * 4 + unaff_r31 + 0x144) + unaff_r31 + 0x144))();
    return;
  }
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

/* orph_cd154 @ 0xcd154 (8 bytes) */
int orph_cd154(param_1)
  undefined4 *param_1;
{
  undefined4 uVar1;
  code *pcVar2;
  
  uVar1 = 3;
  if (param_1 != (undefined4 *)0x0) {
    pcVar2 = (code *)*param_1;
    uVar1 = param_1[1];
    FUN_000da458(param_1,1);
    (*pcVar2)(uVar1,param_1);
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

