#include "decls.h"

/* FUN_0003b280 @ 0x3b280 (772 bytes) */
int FUN_0003b280(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
  uint param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined4 *puVar16;
  int iVar17;
  uint *puVar18;
  uint local_50 [4];
  
  if (*(uint *)(param_2 + 0x24) != param_3) {
    if (*(int *)(param_2 + 0x28) != 0) {
      (**(code **)(param_1 + 0x18))();
      *(undefined4 *)(param_2 + 0x28) = 0;
    }
    if (param_3 != 0) {
      uVar7 = (**(code **)(param_1 + 0x10))(param_3,4);
      *(undefined4 *)(param_2 + 0x28) = uVar7;
    }
  }
  *(uint *)(param_2 + 0x24) = param_3;
  if (*(char *)(param_2 + 0x8c) != '\0') {
    iVar15 = 0;
    iVar17 = param_2;
    do {
      uVar7 = FUN_00054460(param_1,0x87bf,0x87c2,0x87e1,1);
      bVar1 = iVar15 != 3;
      iVar15 = iVar15 + 1;
      *(undefined4 *)(iVar17 + 0x68) = uVar7;
      iVar17 = iVar17 + 4;
    } while (bVar1);
  }
  if (param_3 != 0) {
    iVar17 = *(int *)(param_2 + 0x28);
    uVar14 = 0;
    uVar13 = 0;
    puVar9 = (undefined1 *)((unsigned int)__builtin_frame_address(0));
    do {
      if (uVar13 < param_5) {
        local_50[0] = *(uint *)(uVar13 * 8 + param_6);
        local_50[1] = *(uint *)(uVar13 * 8 + param_6 + 4);
        if ((uVar14 < (local_50[0] & 0xffff)) || ((local_50[1] & 0xffff) <= uVar14))
        goto LAB_0003b3e0;
        uVar13 = uVar13 + 1;
        iVar15 = ((local_50[1] & 0xffff) - (local_50[0] & 0xffff)) + 1;
      }
      else {
LAB_0003b3e0:
        iVar15 = 1;
      }
      puVar18 = (uint *)(uVar14 * 8 + param_4);
      if ((*(uint *)(param_4 + uVar14 * 8) & 0x1f0000) != 0) {
        iVar4 = -(iVar15 + 0x1eU & 0xfffffff0);
        *(undefined1 **)(&STACKARG(0xffffff70) + iVar4) = puVar9;
        iVar6 = -(iVar15 * 4 + 0x1eU & 0xfffffff0);
        puVar8 = (undefined1 *)((int)local_50 + iVar4);
        puVar2 = (undefined4 *)((int)(&STACKARG(0xffffff70) + iVar4) + iVar6);
        *puVar2 = puVar9;
        puVar3 = (undefined4 *)((int)puVar2 + iVar6);
        *puVar3 = puVar9;
        puVar16 = puVar3 + 0x10;
        puVar12 = puVar18;
        bVar1 = iVar15 != 0;
        puVar9 = puVar8;
        puVar11 = puVar2 + 0x10;
        iVar4 = iVar15;
        while (bVar1) {
          uVar5 = *puVar12;
          uVar10 = uVar5 >> 0x10 & 0x1f;
          if (uVar10 == 2) {
            *puVar9 = 0;
            *puVar11 = uVar5 & 0xffff;
          }
          else if (uVar10 == 0x11) {
            *puVar9 = 1;
            *puVar11 = 0;
          }
          else {
            *puVar9 = 2;
            *puVar11 = 0;
          }
          puVar12 = puVar12 + 2;
          puVar9 = puVar9 + 1;
          puVar11 = puVar11 + 1;
          iVar4 = iVar4 + -1;
          bVar1 = iVar4 != 0;
        }
        FUN_000534c0(param_1,iVar15,puVar8,puVar2 + 0x10,puVar16);
        if (iVar15 != 0) {
          iVar4 = 0;
          do {
            uVar5 = *puVar18;
            uVar7 = *puVar16;
            *(undefined4 *)(iVar17 + (puVar18[1] & 0xffff) * 4) = uVar7;
            if ((uVar5 >> 0x10 & 0x1f) == 0x11) {
              FUN_000547f0(param_1,uVar7,((unsigned char *)0x00001406),(uVar5 & 0xffff) * 0x10 + param_8);
            }
            iVar4 = iVar4 + 1;
            puVar18 = puVar18 + 2;
            puVar16 = puVar16 + 1;
          } while (iVar15 != iVar4);
          uVar14 = uVar14 + iVar4;
        }
        puVar9 = (undefined1 *)*puVar3;
        uVar14 = uVar14 - 1;
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 < param_3);
  }
  return;
}

/* FUN_0003b5b0 @ 0x3b5b0 (100 bytes) */
int FUN_0003b5b0(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  
  if (*param_2 == 0) {
    iVar1 = FUN_00053dc0(param_1,1);
    *param_2 = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  thunk_FUN_00053b60(param_1);
  return 1;
}

/* FUN_0003b620 @ 0x3b620 (592 bytes) */
int FUN_0003b620(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  uint *param_5;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  short sVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 local_418 [258];
  
  if (*(char *)(param_3 + 0x8c) == '\0') {
    *(undefined4 *)(param_2 + 0x800) = 0;
  }
  else {
    *(undefined2 *)(param_2 + 2) = 0;
    *(undefined2 *)(param_2 + 10) = 1;
    *(undefined4 *)(param_2 + 0x800) = 4;
    *(undefined2 *)(param_2 + 0x12) = 2;
    *(undefined2 *)(param_2 + 0x1a) = 3;
    local_418[0] = *(undefined4 *)(param_3 + 0x68);
    local_418[1] = *(undefined4 *)(param_3 + 0x6c);
    local_418[2] = *(undefined4 *)(param_3 + 0x70);
    local_418[3] = *(undefined4 *)(param_3 + 0x74);
  }
  if (param_4 == 0) {
    iVar7 = *(int *)(param_2 + 0x800);
    *(int *)(param_2 + 0x804) = iVar7;
    *(int *)(param_2 + 0x808) = iVar7;
  }
  else {
    iVar3 = *(int *)(param_3 + 0x28);
    iVar7 = *(int *)(param_2 + 0x800);
    puVar4 = param_5;
    iVar8 = param_4;
    do {
      if ((*puVar4 & 0x1fc700) == 0x100000) {
        iVar1 = param_2 + iVar7 * 8;
        uVar6 = *(undefined4 *)(iVar3 + (uint)*(ushort *)((int)puVar4 + 6) * 4);
        *(char *)(iVar1 + 1) = (char)*(ushort *)((int)puVar4 + 6);
        local_418[iVar7] = uVar6;
        *(ushort *)(iVar1 + 2) = *(byte *)((int)puVar4 + 2) >> 4 & 3;
        iVar7 = *(int *)(param_2 + 0x800) + 1;
        *(int *)(param_2 + 0x800) = iVar7;
      }
      puVar4 = puVar4 + 2;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    *(int *)(param_2 + 0x804) = iVar7;
    iVar3 = *(int *)(param_3 + 0x28);
    puVar4 = param_5;
    iVar8 = param_4;
    do {
      if ((*puVar4 & 0x1f0000) == 0x20000) {
        iVar1 = param_2 + iVar7 * 8;
        uVar6 = *(undefined4 *)(iVar3 + (uint)*(ushort *)((int)puVar4 + 6) * 4);
        *(char *)(iVar1 + 1) = (char)*(ushort *)((int)puVar4 + 6);
        local_418[iVar7] = uVar6;
        *(short *)(iVar1 + 2) = (short)*puVar4;
        iVar7 = *(int *)(param_2 + 0x804) + 1;
        *(int *)(param_2 + 0x804) = iVar7;
      }
      puVar4 = puVar4 + 2;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    *(int *)(param_2 + 0x808) = iVar7;
    sVar5 = 0;
    do {
      uVar2 = *param_5 >> 0x10 & 0x1f;
      if ((((uVar2 != 0) && (uVar2 != 0x11)) && (uVar2 != 2)) && ((*param_5 & 0x1fc700) != 0x100000)
         ) {
        iVar8 = param_2 + iVar7 * 8;
        uVar6 = *(undefined4 *)(iVar3 + (uint)*(ushort *)((int)param_5 + 6) * 4);
        *(char *)(iVar8 + 1) = (char)*(ushort *)((int)param_5 + 6);
        *(short *)(iVar8 + 2) = sVar5;
        local_418[iVar7] = uVar6;
        iVar7 = *(int *)(param_2 + 0x808) + 1;
        *(int *)(param_2 + 0x808) = iVar7;
      }
      sVar5 = sVar5 + 1;
      param_5 = param_5 + 2;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  FUN_00054590(param_1 + 0x240,param_2,iVar7,local_418);
  return;
}

/* FUN_0003b870 @ 0x3b870 (2500 bytes) */
int FUN_0003b870(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  ushort *puVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  float fVar9;
  int iVar10;
  undefined *puVar11;
  dword *pdVar12;
  undefined8 *puVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  float *pfVar21;
  undefined4 *puVar22;
  dword *pdVar23;
  int iVar24;
  dword *pdVar25;
  uint uVar26;
  float *pfVar27;
  byte *pbVar28;
  double dVar29;
  undefined8 uVar30;
  double dVar31;
  byte *local_68;
  int local_64;
  undefined1 auStack_60 [8];
  uint local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  
  uVar14 = FUN_001a3264(param_1 + 0x240);
  iVar15 = FUN_00054470(uVar14,&local_68,&local_64,auStack_60);
  if (iVar15 != 0) {
    ((int (*)())FUN_0003b620)(param_1,local_68,param_2,param_3,param_4);
  }
  iVar15 = *(int *)(local_68 + 0x800);
  pbVar28 = local_68;
  if (local_68 < local_68 + iVar15 * 8) {
    iVar16 = *(int *)(param_1 + 0x10) + 0x1860;
    do {
      puVar1 = (ushort *)(pbVar28 + 2);
      bVar2 = *pbVar28;
      puVar22 = *(undefined4 **)(pbVar28 + 4);
      pbVar28 = pbVar28 + 8;
      iVar19 = iVar16 + (uint)*puVar1 * 4;
      uVar8 = *(undefined4 *)(iVar16 + (uint)*puVar1 * 4);
      iVar10 = local_64 + (uint)bVar2 * 0x10;
      uVar14 = *(undefined4 *)(iVar19 + 0x30);
      uVar3 = *(undefined4 *)(iVar19 + 0x10);
      uVar4 = *(undefined4 *)(iVar19 + 0x20);
      *(undefined4 *)(local_64 + (uint)bVar2 * 0x10) = uVar8;
      *(undefined4 *)(iVar10 + 0xc) = uVar14;
      *(undefined4 *)(iVar10 + 4) = uVar3;
      *(undefined4 *)(iVar10 + 8) = uVar4;
      puVar22[3] = uVar14;
      *puVar22 = uVar8;
      puVar22[1] = uVar3;
      puVar22[2] = uVar4;
    } while (pbVar28 < local_68 + iVar15 * 8);
  }
  iVar15 = *(int *)(local_68 + 0x804);
  for (; pbVar28 < local_68 + iVar15 * 8; pbVar28 = pbVar28 + 8) {
    bVar2 = *pbVar28;
    uVar30 = (*(undefined8 **)(pbVar28 + 4))[1];
    *(undefined8 *)(local_64 + (uint)bVar2 * 0x10) = **(undefined8 **)(pbVar28 + 4);
    *(undefined8 *)(local_64 + (uint)bVar2 * 0x10 + 8) = uVar30;
  }
  iVar15 = *(int *)(local_68 + 0x808);
  fVar5 = FLOAT_001aa0e8;
joined_r0x0003b9b0:
  if (local_68 + iVar15 * 8 <= pbVar28) {
    FLOAT_001aa0e8 = fVar5;
    return;
  }
  local_58 = *(uint *)((uint)*(ushort *)(pbVar28 + 2) * 8 + param_4);
  pfVar27 = (float *)(local_64 + (uint)*pbVar28 * 0x10);
  local_54 = *(undefined4 *)((uint)*(ushort *)(pbVar28 + 2) * 8 + param_4 + 4);
  uVar20 = local_58 >> 0x10 & 0x1f;
  FLOAT_001aa0e8 = fVar5;
  if (uVar20 == 1) {
    iVar16 = (local_58 & 0xffff) * 0x10;
    iVar10 = iVar16 + param_5;
    if (*(int *)(*(int *)(param_1 + 0x18) + 0x198) == 0) {
      fVar5 = *(float *)(iVar10 + 0xc);
      fVar6 = *(float *)(iVar10 + 4);
      fVar7 = *(float *)(iVar10 + 8);
      *(undefined4 *)(local_64 + (uint)*pbVar28 * 0x10) = *(undefined4 *)(iVar16 + param_5);
      pfVar27[3] = fVar5;
      pfVar27[1] = fVar6;
      pfVar27[2] = fVar7;
    }
    else {
      _glpUniformToFloat(*(undefined4 *)(**(int **)(param_1 + 0x1cc) + 4),local_58 & 0xffff,iVar10,
                         pfVar27);
    }
    goto LAB_0003c2d0;
  }
  local_50 = local_58;
  local_4c = local_54;
  if ((local_58 & 0x1f0000) == 0x100000) {
    uVar20 = local_58 >> 0xc & 3;
    uVar26 = local_58 & 0xff;
    switch(local_58 >> 8 & 7) {
    default:
      iVar16 = 0;
      break;
    case 1:
      iVar16 = 0xc0;
      break;
    case 2:
      iVar16 = 0x80;
      break;
    case 3:
      iVar16 = (uVar26 + 4) * 0x40;
      break;
    case 4:
      iVar16 = (uVar26 + 0x10) * 0x40;
      break;
    case 5:
      iVar16 = (uVar26 + 8) * 0x40;
    }
    uVar26 = local_58 >> 0xe & 3;
    iVar10 = *(int *)(param_1 + 0x10) + 0x1860 + iVar16;
    if ((1 < uVar26) && (iVar10 = iVar16 + *(int *)(param_1 + 0x10) + 0x1e60, 3 < uVar26)) {
      iVar10 = 0;
    }
    if (uVar26 < 3) {
      if (uVar26 == 0) {
LAB_0003bef8:
        iVar16 = uVar20 * 4;
        iVar19 = iVar10 + iVar16;
        *pfVar27 = *(float *)(iVar10 + iVar16);
        pfVar27[1] = *(float *)(iVar19 + 0x10);
        pfVar27[2] = *(float *)(iVar19 + 0x20);
        pfVar27[3] = *(float *)(iVar19 + 0x30);
      }
      else {
        iVar16 = uVar20 * 0x10;
        iVar19 = iVar10 + iVar16;
        *pfVar27 = *(float *)(iVar10 + iVar16);
        pfVar27[1] = *(float *)(iVar19 + 4);
        pfVar27[2] = *(float *)(iVar19 + 8);
        pfVar27[3] = *(float *)(iVar19 + 0xc);
      }
    }
    else if (uVar26 == 3) goto LAB_0003bef8;
    goto LAB_0003c2d0;
  }
  switch(uVar20) {
  case 0:
    pdVar25 = (dword *)(pfVar27 + 1);
    pdVar12 = (dword *)(pfVar27 + 2);
    pdVar23 = (dword *)(pfVar27 + 3);
    pfVar21 = pfVar27;
    break;
  default:
    goto switchD_0003bf70_caseD_1;
  case 2:
    pfVar21 = (float *)((local_58 & 0xffff) * 0x10 +
                       *(int *)(((unsigned char *)0x00004308) + *(int *)(param_1 + 0x10)));
    pdVar25 = (dword *)(pfVar21 + 1);
    pdVar12 = (dword *)(pfVar21 + 2);
    pdVar23 = (dword *)(pfVar21 + 3);
    break;
  case 3:
    uVar20 = local_58 & 0xff;
    switch(local_58 >> 8 & 0xf) {
    case 0:
      pfVar21 = (float *)(uVar20 * 0x80 + 0x24c0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar12 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 1:
      pfVar21 = (float *)(uVar20 * 0x80 + 0x24d0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar12 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 2:
      pfVar21 = (float *)(uVar20 * 0x80 + 0x24e0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar12 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 3:
      pfVar21 = (float *)(uVar20 * 0x80 + 0x24f0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar12 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 4:
      pfVar21 = (float *)(uVar20 * 0x80 + 0x2500 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar12 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 5:
      pfVar21 = (float *)(uVar20 * 0x80 + 0x2510 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar12 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 6:
      iVar16 = uVar20 * 0x80 + *(int *)(param_1 + 0x10);
      fVar6 = *(float *)(iVar16 + 0x24f4);
      fVar7 = *(float *)(iVar16 + 0x24f0);
      fVar9 = *(float *)(iVar16 + 0x24f8) + fVar5;
      dVar29 = (double)_sqrt((double)(fVar9 * fVar9 + fVar7 * fVar7 + fVar6 * fVar6));
      pfVar27[3] = fVar5;
      fVar5 = (float)(DOUBLE_001aa200 / dVar29);
      pfVar27[2] = fVar9 * fVar5;
      *pfVar27 = fVar7 * fVar5;
      pfVar27[1] = fVar6 * fVar5;
      goto LAB_0003c2d0;
    case 7:
      pfVar21 = (float *)(uVar20 * 0x80 + 0x2530 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar12 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    default:
      goto switchD_0003bf70_caseD_1;
    }
    break;
  case 4:
    uVar20 = local_58 >> 9 & 3;
    iVar17 = *(int *)(param_1 + 0x10) + 0x24c0;
    iVar16 = (local_58 & 0xff) * 0x80;
    iVar10 = (local_58 >> 8 & 1) * 0x240;
    iVar19 = *(int *)(param_1 + 0x10) + 0x28c0;
    iVar24 = iVar17 + iVar16;
    iVar18 = iVar19 + iVar10;
    if (uVar20 == 1) {
      *pfVar27 = *(float *)(iVar24 + 0x10) * *(float *)(iVar18 + 0x10);
      pfVar27[1] = *(float *)(iVar24 + 0x14) * *(float *)(iVar18 + 0x14);
      pfVar27[2] = *(float *)(iVar24 + 0x18) * *(float *)(iVar18 + 0x18);
      pfVar27[3] = *(float *)(iVar18 + 0x1c);
    }
    else if (uVar20 == 2) {
      *pfVar27 = *(float *)(iVar24 + 0x20) * *(float *)(iVar18 + 0x20);
      pfVar27[1] = *(float *)(iVar24 + 0x24) * *(float *)(iVar18 + 0x24);
      pfVar27[2] = *(float *)(iVar24 + 0x28) * *(float *)(iVar18 + 0x28);
      pfVar27[3] = *(float *)(iVar18 + 0x2c);
    }
    else {
      if (uVar20 != 0) goto switchD_0003bf70_caseD_1;
      *pfVar27 = *(float *)(iVar17 + iVar16) * *(float *)(iVar19 + iVar10);
      pfVar27[1] = *(float *)(iVar24 + 4) * *(float *)(iVar18 + 4);
      pfVar27[2] = *(float *)(iVar24 + 8) * *(float *)(iVar18 + 8);
      pfVar27[3] = *(float *)(iVar18 + 0xc);
    }
    goto LAB_0003c2d0;
  case 5:
    uVar20 = local_58 & 1;
    switch(local_58 >> 1 & 7) {
    case 0:
      pfVar21 = (float *)(uVar20 * 0x240 + 0x28c0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar12 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 1:
      pfVar21 = (float *)(uVar20 * 0x240 + 0x28d0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar12 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 2:
      pfVar21 = (float *)(uVar20 * 0x240 + 0x28e0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar12 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 3:
      pfVar21 = (float *)(uVar20 * 0x240 + 0x28f0 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar12 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 4:
      pfVar21 = (float *)(uVar20 * 0x240 + 0x2900 + *(int *)(param_1 + 0x10));
      pdVar25 = (dword *)(pfVar21 + 1);
      pdVar12 = (dword *)(pfVar21 + 2);
      pdVar23 = (dword *)(pfVar21 + 3);
      break;
    case 5:
      iVar16 = *(int *)(param_1 + 0x10);
      iVar10 = iVar16 + 0x28c0 + uVar20 * 0x240;
      *pfVar27 = *(float *)(iVar16 + 0x24b0) * *(float *)(iVar16 + 0x28c0 + uVar20 * 0x240) +
                 *(float *)(iVar10 + 0x30);
      pfVar27[1] = *(float *)(iVar16 + 0x24b4) * *(float *)(iVar10 + 4) + *(float *)(iVar10 + 0x34);
      pfVar27[2] = *(float *)(iVar16 + 0x24b8) * *(float *)(iVar10 + 8) + *(float *)(iVar10 + 0x38);
      pfVar27[3] = *(float *)(iVar10 + 0x1c);
      goto LAB_0003c2d0;
    default:
      goto switchD_0003bf70_caseD_1;
    }
    break;
  case 6:
    iVar16 = *(int *)(param_1 + 0x10);
    pdVar23 = (dword *)(iVar16 + 0x24bc);
    pdVar25 = (dword *)(iVar16 + 0x24b4);
    pdVar12 = (dword *)(iVar16 + 0x24b8);
    pfVar21 = (float *)(iVar16 + 0x24b0);
    break;
  case 7:
    uVar20 = local_58 >> 5 & 7;
    local_58 = local_58 & 0x1f;
    if (uVar20 == 1) {
      iVar16 = *(int *)(param_1 + 0x10);
      puVar11 = ((unsigned char *)0x000039a0) + local_58 * 0x94;
LAB_0003bae4:
      pdVar23 = (dword *)(puVar11 + iVar16 + 0x1c);
      pdVar25 = (dword *)(puVar11 + iVar16 + 0x14);
      pdVar12 = (dword *)(puVar11 + iVar16 + 0x18);
      pfVar21 = (float *)(puVar11 + iVar16 + 0x10);
    }
    else {
      if (uVar20 < 2) {
        if (uVar20 == 0) {
          iVar16 = *(int *)(param_1 + 0x10);
          puVar11 = ((unsigned char *)0x00003980) + local_58 * 0x94;
          goto LAB_0003bac0;
        }
        goto switchD_0003bf70_caseD_1;
      }
      if (uVar20 == 2) {
        iVar16 = *(int *)(param_1 + 0x10);
        puVar11 = ((unsigned char *)0x000039c0) + local_58 * 0x94;
LAB_0003bb08:
        pdVar23 = (dword *)(puVar11 + iVar16 + 0x20);
        pdVar25 = (dword *)(puVar11 + iVar16 + 0x18);
        pdVar12 = (dword *)(puVar11 + iVar16 + 0x1c);
        pfVar21 = (float *)(puVar11 + iVar16 + 0x14);
      }
      else {
        if (uVar20 != 3) goto switchD_0003bf70_caseD_1;
        iVar16 = *(int *)(param_1 + 0x10);
        puVar11 = ((unsigned char *)0x000039e0) + local_58 * 0x94;
LAB_0003bb2c:
        pdVar23 = (dword *)(puVar11 + iVar16 + 0x24);
        pdVar25 = (dword *)(puVar11 + iVar16 + 0x1c);
        pdVar12 = (dword *)(puVar11 + iVar16 + 0x20);
        pfVar21 = (float *)(puVar11 + iVar16 + 0x18);
      }
    }
    break;
  case 8:
    uVar20 = local_58 >> 5 & 7;
    local_58 = local_58 & 0x1f;
    if (uVar20 == 1) {
      iVar16 = *(int *)(param_1 + 0x10);
      puVar11 = ((unsigned char *)0x000039b0) + local_58 * 0x94;
      goto LAB_0003bae4;
    }
    if (uVar20 < 2) {
      if (uVar20 == 0) {
        iVar16 = *(int *)(param_1 + 0x10);
        puVar11 = ((unsigned char *)0x00003990) + local_58 * 0x94;
        goto LAB_0003bac0;
      }
    }
    else {
      if (uVar20 == 2) {
        iVar16 = *(int *)(param_1 + 0x10);
        puVar11 = ((unsigned char *)0x000039d0) + local_58 * 0x94;
        goto LAB_0003bb08;
      }
      if (uVar20 == 3) {
        iVar16 = *(int *)(param_1 + 0x10);
        puVar11 = ((unsigned char *)0x000039f0) + local_58 * 0x94;
        goto LAB_0003bb2c;
      }
    }
    goto switchD_0003bf70_caseD_1;
  case 9:
    iVar16 = *(int *)(param_1 + 0x10) + (local_58 & 0x1f) * 0x7c;
    pdVar23 = (dword *)(((unsigned char *)0x000031c0) + iVar16 + 0x10);
    pdVar12 = (dword *)(((unsigned char *)0x000031c0) + iVar16 + 0xc);
    pdVar25 = (dword *)(((unsigned char *)0x000031c0) + iVar16 + 8);
    pfVar21 = (float *)(((unsigned char *)0x000031c0) + iVar16 + 4);
    break;
  case 10:
    iVar16 = *(int *)(param_1 + 0x10);
    puVar11 = ((unsigned char *)0x00003e20) + (local_58 & 0xff) * 0x10;
LAB_0003bac0:
    pdVar23 = (dword *)(puVar11 + iVar16 + 0x18);
    pdVar25 = (dword *)(puVar11 + iVar16 + 0x10);
    pdVar12 = (dword *)(puVar11 + iVar16 + 0x14);
    pfVar21 = (float *)(puVar11 + iVar16 + 0xc);
    break;
  case 0xb:
    iVar16 = *(int *)(param_1 + 0x10);
    pdVar23 = (dword *)(((unsigned char *)0x00002dec) + iVar16);
    pdVar25 = (dword *)(((unsigned char *)0x00002de4) + iVar16);
    pdVar12 = (dword *)(((unsigned char *)0x00002de8) + iVar16);
    pfVar21 = (float *)(((unsigned char *)0x00002de0) + iVar16);
    break;
  case 0xc:
    iVar16 = *(int *)(param_1 + 0x10);
    pdVar23 = (dword *)(((unsigned char *)0x00002dfc) + iVar16);
    pdVar25 = (dword *)(((unsigned char *)0x00002df4) + iVar16);
    pdVar12 = (dword *)(((unsigned char *)0x00002df8) + iVar16);
    pfVar21 = (float *)(((unsigned char *)0x00002df0) + iVar16);
    break;
  case 0xd:
    iVar16 = *(int *)(param_1 + 0x10);
    pdVar23 = (dword *)(((unsigned char *)0x000030c8) + iVar16);
    pdVar25 = (dword *)(((unsigned char *)0x000030c0) + iVar16);
    pdVar12 = (dword *)(((unsigned char *)0x000030c4) + iVar16);
    pfVar21 = (float *)(((unsigned char *)0x000030bc) + iVar16);
    break;
  case 0xe:
    iVar16 = *(int *)(param_1 + 0x10);
    pdVar23 = (dword *)(((unsigned char *)0x000030d8) + iVar16);
    pdVar25 = (dword *)(((unsigned char *)0x000030d0) + iVar16);
    pdVar12 = (dword *)(((unsigned char *)0x000030d4) + iVar16);
    pfVar21 = (float *)(((unsigned char *)0x000030cc) + iVar16);
    break;
  case 0xf:
    *pfVar27 = (float)*(double *)(FUN_00001830 + *(int *)(param_1 + 0x10));
    pfVar27[1] = (float)*(double *)(*(int *)(param_1 + 0x10) + 0x1838);
    dVar31 = *(double *)(FUN_00001830 + *(int *)(param_1 + 0x10));
    dVar29 = *(double *)(*(int *)(param_1 + 0x10) + 0x1838);
    pfVar27[3] = 1.0;
    pfVar27[2] = (float)(dVar29 - dVar31);
    goto LAB_0003c2d0;
  case 0x12:
    fVar5 = *(float *)(*(int *)(param_1 + 0x10) + 0x24a4);
    pfVar27[3] = fVar5;
    *pfVar27 = fVar5;
    pfVar27[1] = fVar5;
    pfVar27[2] = fVar5;
    goto LAB_0003c2d0;
  }
LAB_0003c2b0:
  *pfVar27 = *pfVar21;
  pfVar27[1] = (float)*pdVar25;
  pfVar27[2] = (float)*pdVar12;
  pfVar27[3] = (float)*pdVar23;
LAB_0003c2d0:
  puVar13 = *(undefined8 **)(pbVar28 + 4);
  pbVar28 = pbVar28 + 8;
  uVar30 = *(undefined8 *)(pfVar27 + 2);
  *puVar13 = *(undefined8 *)pfVar27;
  puVar13[1] = uVar30;
  fVar5 = FLOAT_001aa0e8;
  goto joined_r0x0003b9b0;
switchD_0003bf70_caseD_1:
  pdVar25 = &MACH_HEADER.cputype;
  pdVar12 = &MACH_HEADER.cpusubtype;
  pdVar23 = &MACH_HEADER.filetype;
  pfVar21 = (float *)0x0;
  goto LAB_0003c2b0;
}

/* FUN_0003c310 @ 0x3c310 (236 bytes) */
int FUN_0003c310(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  if (param_2[2] != 0) {
    (**(code **)(param_1 + 0x18))();
    param_2[2] = 0;
  }
  if (param_2[4] != 0) {
    (**(code **)(param_1 + 0x18))();
    param_2[4] = 0;
  }
  if (param_2[6] != 0) {
    (**(code **)(param_1 + 0x18))();
    param_2[6] = 0;
  }
  if (param_2[8] != 0) {
    (**(code **)(param_1 + 0x18))();
    param_2[8] = 0;
  }
  if (param_2[10] != 0) {
    (**(code **)(param_1 + 0x18))();
    param_2[10] = 0;
  }
  FUN_00053ef0(param_1,*param_2);
  return;
}

/* FUN_0003c400 @ 0x3c400 (4136 bytes) */
int FUN_0003c400(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  undefined4 *param_3;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  undefined4 *puVar19;
  int iVar20;
  uint *puVar21;
  uint *puVar22;
  int iVar23;
  uint uVar24;
  undefined4 *puVar25;
  undefined4 uVar26;
  char cStack_95;
  char cStack_75;
  undefined4 local_70 [11];
  
  if (param_2[8] != 0) {
    bVar2 = *param_2 - 0x8b30U < 2;
    FUN_000538e0();
    FUN_00053060(param_1);
    iVar12 = param_2[0x12];
    iVar5 = param_2[0x13];
    *(undefined1 *)(param_3 + 0x23) = 0;
    if (iVar12 != 0) {
      iVar14 = 0;
      do {
        cStack_95 = (char)param_2[iVar5 * 2 + iVar14 * 2];
        if (cStack_95 == '\0') {
          *(undefined1 *)(param_3 + 0x23) = 1;
        }
        iVar14 = iVar14 + 1;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
    }
    iVar5 = 0;
    puVar19 = param_3;
    do {
      uVar7 = FUN_00054460(param_1,0x87bf,0x87c4,0x87e1,1);
      puVar19[0xd] = uVar7;
      uVar7 = FUN_00054460(param_1,0x87be,0x87c4,0x87e1,1);
      puVar19[0x10] = uVar7;
      uVar7 = FUN_00054460(param_1,0x87bf,0x87c4,0x87e1,1);
      bVar1 = iVar5 != 2;
      iVar5 = iVar5 + 1;
      puVar19[0x13] = uVar7;
      puVar19 = puVar19 + 1;
    } while (bVar1);
    iVar5 = 0;
    uVar7 = FUN_00054460(param_1,0x87bf,0x87c4,0x87e1,1);
    param_3[0x16] = uVar7;
    uVar7 = FUN_00054460(param_1,0x87be,0x87c4,0x87e1,1);
    param_3[0x17] = uVar7;
    puVar19 = param_3;
    do {
      uVar7 = FUN_00054460(param_1,0x87bf,0x87c4,0x87e1,1);
      bVar1 = iVar5 != 1;
      iVar5 = iVar5 + 1;
      puVar19[0x18] = uVar7;
      puVar19 = puVar19 + 1;
    } while (bVar1);
    iVar5 = param_2[4];
    if (iVar5 != param_3[1]) {
      if (param_3[2] != 0) {
        (**(code **)(param_1 + 0x18))();
        param_3[2] = 0;
      }
      if (iVar5 != 0) {
        uVar7 = (**(code **)(param_1 + 0x10))(iVar5,4);
        param_3[2] = uVar7;
      }
    }
    param_3[1] = iVar5;
    if (iVar5 != 0) {
      iVar12 = FUN_00054460(param_1,0x87bf,0x87c4,0x87e1,iVar5);
      iVar14 = 0;
      do {
        iVar17 = iVar14 * 4;
        iVar3 = iVar14 + iVar12;
        iVar14 = iVar14 + 1;
        *(int *)(iVar17 + param_3[2]) = iVar3;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    iVar12 = param_2[8];
    iVar5 = param_2[9];
    if (iVar12 != param_3[3]) {
      if (param_3[4] != 0) {
        (**(code **)(param_1 + 0x18))();
        param_3[4] = 0;
      }
      if (iVar12 != 0) {
        uVar7 = (**(code **)(param_1 + 0x10))(iVar12,4);
        param_3[4] = uVar7;
      }
    }
    param_3[3] = iVar12;
    if (iVar12 != 0) {
      puVar19 = (undefined4 *)param_3[4];
      iVar14 = 0;
      do {
        uVar15 = param_2[iVar5 * 2 + iVar14 * 2 + 1];
        if (((uint)param_2[iVar5 * 2 + iVar14 * 2] >> 0x10 & 0xf) - 1 < 10) {
          if ((uVar15 & 0xffff) == 0) {
            uVar7 = FUN_00054940(param_1,0x87e2);
            *puVar19 = uVar7;
          }
          else {
            uVar7 = FUN_00054460(param_1,0x87bf,0x87c1,0x87e1,1);
            puVar19[uVar15 & 0xffff] = uVar7;
          }
        }
        iVar14 = iVar14 + 1;
      } while (iVar12 != iVar14);
    }
    ((int (*)())FUN_0003b280)(param_1,param_3,param_2[10],param_2 + param_2[0xb] * 2,param_2[0xe],
                 param_2 + param_2[0xf] * 2,param_2[0x1a],param_2 + param_2[0x1b] * 2);
    iVar12 = param_2[0x14];
    iVar5 = param_2[0xd];
    if (iVar12 != 0) {
      iVar14 = 0;
      puVar21 = (uint *)(param_2 + param_2[0x15] * 2);
      do {
        puVar22 = puVar21 + 2;
        uVar15 = *puVar21 >> 0x12 & 0xff;
        if ((*puVar21 & 0x3fc0000) == 0x1340000) goto LAB_0003d23c;
        uVar24 = puVar21[2];
        if (0x4d < uVar15) goto switchD_0003cbec_caseD_3;
        bVar1 = uVar15 == 0x48;
        if (bVar1) {
          iVar17 = param_3[0x17];
          goto LAB_0003c9b8;
        }
        if ((bVar2) && ((uVar24 & 0x7000) != 0x3000)) goto switchD_0003cbec_caseD_3;
        uVar6 = uVar24 >> 0x11 & 7;
        if (uVar6 == 1) {
          iVar17 = *(int *)((puVar21[3] & 0xffff) * 4 + param_3[2]);
          goto LAB_0003c9b8;
        }
        if (uVar6 != 3) {
switchD_0003cbec_caseD_3:
          bVar2 = false;
          goto LAB_0003d254;
        }
        uVar6 = param_2[iVar5 * 2 + (puVar21[3] & 0xffff) * 2];
        switch(uVar6 >> 0x10 & 0xf) {
        case 0:
          iVar17 = 0;
          break;
        case 1:
          iVar17 = 0x879a;
          break;
        case 2:
          iVar17 = 0x87bd;
          break;
        case 3:
          iVar17 = 0x610e;
          break;
        case 4:
          iVar17 = 0x610f;
          if ((uVar6 & 1) == 0) {
            iVar17 = 0x879b;
          }
          break;
        case 5:
          iVar17 = 0x6110;
          if ((uVar6 & 1) == 0) {
            iVar17 = 0x879c;
          }
          break;
        case 6:
          iVar17 = (uVar6 & 0x1f) + 0x879d;
          break;
        default:
          goto switchD_0003cbec_caseD_3;
        }
LAB_0003c9b8:
        iVar3 = iVar17;
        if (((uVar24 & 0x1e000) != 0x1e000) && (!bVar1)) {
          iVar3 = param_3[0x16];
        }
        if ((uVar15 < 0x1f) || ((iVar18 = 2, 0x3a < uVar15 && (iVar18 = 3, 0x40 < uVar15)))) {
          iVar18 = 1;
        }
        iVar20 = 0;
        iVar23 = 0;
        puVar22 = puVar21 + 4;
        puVar19 = param_3;
        do {
          puVar21 = puVar22;
          uVar6 = *puVar21;
          puVar22 = puVar21 + 2;
          uVar16 = puVar21[1] & 0xffff;
          if ((bVar2) && ((uVar6 & 0x7000) != 0x3000)) goto switchD_0003cbec_caseD_3;
          uVar4 = uVar6 >> 0x17 & 7;
          if (uVar4 == 1) {
            uVar7 = *(undefined4 *)(uVar16 * 4 + param_3[2]);
          }
          else if (uVar4 == 2) {
            if ((int)uVar6 < 0) {
              cStack_75 = (char)uVar6;
              FUN_00053f80(param_1,0x8782,puVar19[0x13],param_3[0x17],
                           *(undefined4 *)((uVar16 + (int)cStack_75) * 4 + param_3[10]));
              uVar7 = puVar19[0x13];
            }
            else {
              uVar7 = *(undefined4 *)(uVar16 * 4 + param_3[10]);
            }
          }
          else {
            uVar7 = 0;
            if (uVar4 == 0) {
              uVar7 = *(undefined4 *)(uVar16 * 4 + param_3[4]);
            }
          }
          *(undefined4 *)((int)local_70 + iVar23) = uVar7;
          if ((uVar6 & 0x8000000) == 0) {
            iVar8 = (uVar6 >> 0x15 & 3) + 0x87d5;
            iVar10 = (uVar6 >> 0x13 & 3) + 0x87d5;
            iVar11 = (uVar6 >> 0x11 & 3) + 0x87d5;
            iVar13 = (uVar6 >> 0xf & 3) + 0x87d5;
          }
          else {
            iVar8 = (uVar6 >> 0x15 & 3) + 0x87d9;
            iVar10 = (uVar6 >> 0x13 & 3) + 0x87d9;
            iVar11 = (uVar6 >> 0x11 & 3) + 0x87d9;
            iVar13 = (uVar6 >> 0xf & 3) + 0x87d9;
          }
          if ((((iVar8 != 0x87d5) || (iVar10 != 0x87d6)) || (iVar11 != 0x87d7)) ||
             (iVar13 != 0x87d8)) {
            FUN_00054080(param_1,puVar19[0xd],*(undefined4 *)((int)local_70 + iVar23));
            *(undefined4 *)((int)local_70 + iVar23) = puVar19[0xd];
          }
          uVar7 = local_70[1];
          iVar20 = iVar20 + 1;
          iVar23 = iVar23 + 4;
          puVar19 = puVar19 + 1;
        } while (iVar18 != iVar20);
        switch(uVar15) {
        case 0:
          FUN_00053f00(param_1,0x8799,iVar3,local_70[0]);
          break;
        case 1:
          FUN_00053f00(param_1,0x879e,iVar3,local_70[0]);
          break;
        case 2:
          FUN_00054080(param_1,param_3[0x18],local_70[0],0x87d9,0x87da,0x87db,0x87dc);
          FUN_00053f80(param_1,0x878a,iVar3,local_70[0],param_3[0x18]);
          break;
        default:
          goto switchD_0003cbec_caseD_3;
        case 4:
          FUN_00053f00(param_1,0x8789,iVar3,local_70[0]);
          break;
        case 5:
          FUN_00053f00(param_1,0x878f,iVar3,local_70[0]);
          break;
        case 0xd:
          FUN_00054080(param_1,param_3[0x18],local_70[0],0x87d9,0x87da,0x87db,0x87dc);
          FUN_00053f80(param_1,0x878a,param_3[0x19],local_70[0],param_3[0x18]);
          FUN_000543b0(param_1,param_3[0x10],param_3[0x19],0);
          uVar26 = param_3[0x11];
          uVar9 = param_3[0x10];
          uVar7 = 0x8795;
          goto LAB_0003cdec;
        case 0xe:
          FUN_000543b0(param_1,param_3[0x10],local_70[0],0);
          uVar26 = param_3[0x11];
          uVar9 = param_3[0x10];
          uVar7 = 0x8794;
          goto LAB_0003cdec;
        case 0x10:
          FUN_000543b0(param_1,param_3[0x10],local_70[0],0);
          uVar26 = param_3[0x11];
          uVar9 = param_3[0x10];
          uVar7 = 0x8791;
          goto LAB_0003cdec;
        case 0x11:
          FUN_00053f00(param_1,0x87a0,iVar3,local_70[0]);
          break;
        case 0x13:
          FUN_000543b0(param_1,param_3[0x10],local_70[0],0);
          uVar26 = param_3[0x11];
          uVar9 = param_3[0x10];
          uVar7 = 0x8792;
LAB_0003cdec:
          FUN_00053f00(param_1,uVar7,uVar26,uVar9);
          FUN_00053f00(param_1,0x8799,iVar3,param_3[0x11]);
          break;
        case 0x14:
          FUN_00053f00(param_1,0x87a1,iVar3,local_70[0]);
          break;
        case 0x1f:
          FUN_00053f80(param_1,0x8787,iVar3,local_70[0],local_70[1]);
          break;
        case 0x20:
          FUN_00053f80(param_1,0x8796,iVar3,local_70[0],local_70[1]);
          break;
        case 0x22:
          FUN_00053f80(param_1,0x8786,iVar3,local_70[0],local_70[1]);
          break;
        case 0x28:
          FUN_00053f80(param_1,0x8784,iVar3,local_70[0],local_70[1]);
          break;
        case 0x29:
          FUN_00053f80(param_1,0x8785,iVar3,local_70[0],local_70[1]);
          break;
        case 0x2a:
          FUN_00054080(param_1,param_3[0x18],local_70[0],0x87d5,0x87d6,0x87d7,0x87de);
          FUN_00053f80(param_1,0x8785,iVar3,param_3[0x18],local_70[1]);
          break;
        case 0x2b:
          FUN_00053f80(param_1,0x879f,iVar3,local_70[0],local_70[1]);
          break;
        case 0x2c:
          FUN_00053f80(param_1,0x878b,iVar3,local_70[0],local_70[1]);
          break;
        case 0x2d:
          FUN_00053f80(param_1,0x878a,iVar3,local_70[0],local_70[1]);
          break;
        case 0x2e:
          FUN_00053f80(param_1,0x8797,iVar3,local_70[0],local_70[1]);
          break;
        case 0x32:
          FUN_00053f80(param_1,0x878c,iVar3,local_70[0],local_70[1]);
          break;
        case 0x35:
          FUN_00053f80(param_1,0x878d,iVar3,local_70[0],local_70[1]);
          break;
        case 0x38:
          FUN_000543b0(param_1,param_3[0x10],local_70[0],0);
          FUN_000543b0(param_1,param_3[0x11],uVar7,0);
          FUN_00053f80(param_1,0x8793,param_3[0x12],param_3[0x10],param_3[0x11]);
          FUN_00053f00(param_1,0x8799,iVar3,param_3[0x12]);
          break;
        case 0x3f:
          FUN_00054000(param_1,0x8788,iVar3,local_70[0],local_70[1],local_70[2]);
          break;
        case 0x41:
          uVar15 = *puVar22;
          puVar22 = puVar21 + 4;
          if (((*(int *)(&DAT_001da630 + (uVar15 >> 10 & 0x3c)) != 0x87d5) ||
              (*(int *)(&DAT_001da630 + (uVar15 >> 6 & 0x3c)) != 0x87d6)) ||
             ((*(int *)(&DAT_001da630 + (uVar15 >> 2 & 0x3c)) != 0x87d7 ||
              (*(int *)(&DAT_001da630 + (uVar15 & 0xf) * 4) != 0x87d8)))) {
            FUN_00054080(param_1,iVar3,local_70[0],*(int *)(&DAT_001da630 + (uVar15 >> 10 & 0x3c)),
                         *(int *)(&DAT_001da630 + (uVar15 >> 6 & 0x3c)));
          }
          break;
        case 0x48:
          FUN_000543b0(param_1,iVar3,local_70[0],0);
        }
        if (((uVar24 & 0x1e000) != 0x1e000) && (!bVar1)) {
          FUN_000541a0(param_1,iVar17,iVar3,uVar24 >> 0xd & 1,uVar24 >> 0xe & 1,uVar24 >> 0xf & 1,
                       uVar24 >> 0x10 & 1);
        }
LAB_0003d23c:
        iVar14 = iVar14 + 1;
        puVar21 = puVar22;
      } while (iVar12 != iVar14);
    }
    bVar2 = true;
LAB_0003d254:
    if (*(char *)(param_3 + 0x23) != '\0') {
      uVar26 = param_3[0x16];
      uVar7 = *(undefined4 *)param_3[4];
      FUN_00053f80(param_1,0x8785,uVar26,uVar7,param_3[0x1a]);
      FUN_000541a0(param_1,0x879a,uVar26,1,0,0,0);
      FUN_00053f80(param_1,0x8785,uVar26,uVar7,param_3[0x1b]);
      FUN_000541a0(param_1,0x879a,uVar26,0,1,0,0);
      FUN_00053f80(param_1,0x8785,uVar26,uVar7,param_3[0x1c]);
      FUN_000541a0(param_1,0x879a,uVar26,0,0,1,0);
      FUN_00053f80(param_1,0x8785,uVar26,uVar7,param_3[0x1d]);
      FUN_000541a0(param_1,0x879a,uVar26,0,0,0,1);
    }
    FUN_00053990(param_1);
    if (!bVar2) {
      FUN_000530a0(param_1);
      return 0;
    }
    iVar5 = FUN_00053070(param_1);
    if (iVar5 != 0) {
      uVar15 = param_3[3];
      if (uVar15 != param_3[5]) {
        if (param_3[6] != 0) {
          (**(code **)(param_1 + 0x18))();
          param_3[6] = 0;
        }
        if (uVar15 != 0) {
          uVar7 = (**(code **)(param_1 + 0x10))(uVar15,4);
          param_3[6] = uVar7;
        }
      }
      param_3[5] = uVar15;
      if (uVar15 != 0) {
        puVar19 = (undefined4 *)param_3[6];
        *puVar19 = FUN_000308c0;
        if (1 < uVar15) {
          uVar24 = 1;
          iVar5 = 4;
          do {
            uVar24 = uVar24 + 1;
            uVar7 = FUN_00052ee0(param_1,*(undefined4 *)(param_3[4] + iVar5));
            *(undefined4 *)((int)puVar19 + iVar5) = uVar7;
            iVar5 = iVar5 + 4;
          } while (uVar15 != uVar24);
        }
      }
      uVar15 = param_3[3];
      if (uVar15 != param_3[7]) {
        if (param_3[8] != 0) {
          (**(code **)(param_1 + 0x18))();
          param_3[8] = 0;
        }
        if (uVar15 != 0) {
          uVar7 = (**(code **)(param_1 + 0x10))(uVar15,4);
          param_3[8] = uVar7;
        }
      }
      param_3[7] = uVar15;
      if (uVar15 != 0) {
        puVar25 = (undefined4 *)param_3[8];
        puVar19 = puVar25;
        uVar24 = uVar15;
        do {
          *puVar19 = 0x80;
          puVar19 = puVar19 + 1;
          uVar24 = uVar24 - 1;
        } while (uVar24 != 0);
        *puVar25 = 0;
        if (1 < uVar15) {
          uVar24 = 1;
          do {
            iVar5 = FUN_00052f60(param_1,*(undefined4 *)(uVar24 * 4 + param_3[4]));
            if (iVar5 != 0x81) {
              puVar25[iVar5 + -1] = uVar24;
            }
            uVar24 = uVar24 + 1;
          } while (uVar15 != uVar24);
        }
      }
      FUN_000530c0(param_1,*param_3,param_3 + 0x1e);
      return 1;
    }
  }
  return 0;
}

/* FUN_0003d590 @ 0x3d590 (2944 bytes) */
int FUN_0003d590(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  ushort *puVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  uint uVar11;
  int iVar12;
  undefined *puVar13;
  dword *pdVar14;
  int iVar15;
  undefined4 *puVar16;
  int iVar17;
  int iVar18;
  undefined4 *puVar19;
  int iVar20;
  undefined4 *puVar21;
  undefined8 *puVar22;
  float *pfVar23;
  undefined4 *puVar24;
  int iVar25;
  dword *pdVar26;
  int iVar27;
  uint uVar28;
  uint uVar29;
  dword *pdVar30;
  int iVar31;
  float *pfVar32;
  byte *pbVar33;
  byte *pbVar34;
  undefined8 uVar35;
  double dVar36;
  undefined8 uVar37;
  double dVar38;
  byte *local_88[0];
  int local_84;
  int local_80 [2];
  uint local_78;
  undefined4 local_74;
  uint local_70;
  undefined4 local_6c;
  
  iVar31 = param_1 + 0x240;
  FUN_001a3264();
  iVar15 = FUN_00054470(iVar31,&local_88,&local_84,local_80);
  if (iVar15 != 0) {
    ((int (*)())FUN_0003b620)(param_1,local_88[0],param_2,param_3,param_4);
  }
  puVar16 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar31,*(int *)(local_88[0] + 0x808) * 7 + 2)
  ;
  puVar21 = *(undefined4 **)(param_1 + 0x2834);
  *(undefined4 **)(param_1 + 0x298c) = puVar16;
  puVar19 = puVar16 + *(int *)(local_88[0] + 0x808) * 7 + 2;
  puVar24 = puVar16;
  if ((puVar21 <= puVar16) || (puVar24 = puVar21, puVar21 < puVar19)) {
    uVar28 = *(byte *)(param_1 + 8) - 1;
    dataCacheBlockTouch(puVar24);
    dataCacheBlockTouch((int)puVar19 + -1);
    uVar29 = ~uVar28;
    uVar11 = uVar29 & (uint)puVar19;
    for (uVar29 = uVar28 + (int)puVar24 & uVar29; uVar29 < uVar11;
        uVar29 = uVar29 + *(byte *)(param_1 + 8)) {
      dataCacheBlockClearToZero(uVar29);
    }
    *(uint *)(param_1 + 0x2834) = uVar11;
  }
  iVar15 = *(int *)(local_88[0] + 0x800);
  puVar24 = puVar16 + 2;
  *puVar16 = 0x8a1;
  puVar16[1] = 0;
  pbVar33 = local_88;
  if (local_88[0] < local_88[0] + iVar15 * 8) {
    iVar25 = *(int *)(param_1 + 0x10) + 0x1860;
    do {
      puVar1 = (ushort *)(pbVar33 + 2);
      bVar2 = *pbVar33;
      puVar16 = *(undefined4 **)(pbVar33 + 4);
      pbVar33 = pbVar33 + 8;
      iVar12 = iVar25 + (uint)*puVar1 * 4;
      uVar9 = *(undefined4 *)(iVar25 + (uint)*puVar1 * 4);
      iVar17 = (uint)bVar2 * 0x10;
      uVar3 = *(undefined4 *)(iVar12 + 0x30);
      uVar4 = *(undefined4 *)(iVar12 + 0x10);
      uVar5 = *(undefined4 *)(iVar12 + 0x20);
      iVar12 = local_84 + iVar17;
      *(undefined4 *)(local_84 + iVar17) = uVar9;
      *(undefined4 *)(iVar12 + 0xc) = uVar3;
      *(undefined4 *)(iVar12 + 4) = uVar4;
      *(undefined4 *)(iVar12 + 8) = uVar5;
      puVar16[3] = uVar3;
      *puVar16 = uVar9;
      puVar16[1] = uVar4;
      puVar16[2] = uVar5;
      puVar24[1] = local_80[0] + (uint)bVar2;
      puVar24[3] = uVar9;
      puVar24[4] = uVar4;
      puVar24[5] = uVar5;
      puVar24[6] = uVar3;
      *puVar24 = 0x880;
      puVar24[2] = ((unsigned char *)0x00038882);
      puVar24 = puVar24 + 7;
    } while (pbVar33 < local_88[0] + iVar15 * 8);
  }
  iVar15 = *(int *)(local_88[0] + 0x804);
  while (pbVar34 = pbVar33, pbVar34 < local_88[0] + iVar15 * 8) {
    pbVar33 = pbVar34 + 8;
    if ((*(uint *)((pbVar34[1] >> 3 & 0x1c) + param_6) >> (pbVar34[1] & 0x1f) & 1) != 0) {
      puVar22 = *(undefined8 **)(pbVar34 + 4);
      bVar2 = *pbVar34;
      *puVar24 = 0x880;
      puVar24[2] = ((unsigned char *)0x00038882);
      iVar25 = (uint)bVar2 * 0x10;
      uVar37 = puVar22[1];
      uVar35 = *puVar22;
      puVar24[1] = local_80[0] + (uint)bVar2;
      *(undefined8 *)(puVar24 + 3) = uVar35;
      *(undefined8 *)(local_84 + iVar25) = uVar35;
      *(undefined8 *)(puVar24 + 5) = uVar37;
      *(undefined8 *)(local_84 + iVar25 + 8) = uVar37;
      puVar24 = puVar24 + 7;
    }
  }
  iVar15 = *(int *)(local_88[0] + 0x808);
LAB_0003d820:
  while( true ) {
    if (local_88[0] + iVar15 * 8 <= pbVar34) {
      *(undefined4 **)(param_1 + 0x298c) = puVar24;
      (**(code **)(param_1 + 0x299c))(iVar31,puVar24);
      return;
    }
    if ((*(uint *)((pbVar34[1] >> 3 & 0x1c) + param_6) >> (pbVar34[1] & 0x1f) & 1) != 0) break;
    pbVar34 = pbVar34 + 8;
  }
  bVar2 = *pbVar34;
  pfVar32 = (float *)(puVar24 + 3);
  local_78 = *(uint *)((uint)*(ushort *)(pbVar34 + 2) * 8 + param_4);
  local_74 = *(undefined4 *)((uint)*(ushort *)(pbVar34 + 2) * 8 + param_4 + 4);
  puVar24[1] = local_80[0] + (uint)bVar2;
  puVar24[2] = ((unsigned char *)0x00038882);
  *puVar24 = 0x880;
  fVar6 = FLOAT_001aa0e8;
  if ((local_78 >> 0x10 & 0x1f) == 1) {
    iVar25 = (local_78 & 0xffff) * 0x10;
    iVar17 = iVar25 + param_5;
    if (*(int *)(*(int *)(param_1 + 0x18) + 0x198) == 0) {
      uVar3 = *(undefined4 *)(iVar17 + 0xc);
      uVar4 = *(undefined4 *)(iVar17 + 4);
      uVar5 = *(undefined4 *)(iVar17 + 8);
      puVar24[3] = *(undefined4 *)(iVar25 + param_5);
      puVar24[6] = uVar3;
      puVar24[4] = uVar4;
      puVar24[5] = uVar5;
    }
    else {
      _glpUniformToFloat(*(undefined4 *)(**(int **)(param_1 + 0x1cc) + 4),local_78 & 0xffff,iVar17,
                         pfVar32);
    }
    goto LAB_0003e170;
  }
  local_70 = local_78;
  local_6c = local_74;
  if ((local_78 & 0x1f0000) == 0x100000) {
    uVar29 = local_78 >> 0xc & 3;
    uVar11 = local_78 & 0xff;
    switch(local_78 >> 8 & 7) {
    default:
      iVar25 = 0;
      break;
    case 1:
      iVar25 = 0xc0;
      break;
    case 2:
      iVar25 = 0x80;
      break;
    case 3:
      iVar25 = (uVar11 + 4) * 0x40;
      break;
    case 4:
      iVar25 = (uVar11 + 0x10) * 0x40;
      break;
    case 5:
      iVar25 = (uVar11 + 8) * 0x40;
    }
    uVar11 = local_78 >> 0xe & 3;
    iVar17 = *(int *)(param_1 + 0x10) + 0x1860 + iVar25;
    if ((1 < uVar11) && (iVar17 = iVar25 + *(int *)(param_1 + 0x10) + 0x1e60, 3 < uVar11)) {
      iVar17 = 0;
    }
    if (uVar11 < 3) {
      if (uVar11 == 0) {
LAB_0003dd8c:
        iVar25 = uVar29 * 4;
        iVar12 = iVar17 + iVar25;
        *pfVar32 = *(float *)(iVar17 + iVar25);
        puVar24[4] = *(undefined4 *)(iVar12 + 0x10);
        puVar24[5] = *(undefined4 *)(iVar12 + 0x20);
        puVar24[6] = *(undefined4 *)(iVar12 + 0x30);
      }
      else {
        iVar25 = uVar29 * 0x10;
        iVar12 = iVar17 + iVar25;
        *pfVar32 = *(float *)(iVar17 + iVar25);
        puVar24[4] = *(undefined4 *)(iVar12 + 4);
        puVar24[5] = *(undefined4 *)(iVar12 + 8);
        puVar24[6] = *(undefined4 *)(iVar12 + 0xc);
      }
    }
    else if (uVar11 == 3) goto LAB_0003dd8c;
    goto LAB_0003e170;
  }
  switch(local_78 >> 0x10 & 0x1f) {
  case 0:
    pdVar30 = puVar24 + 4;
    pdVar14 = puVar24 + 5;
    pdVar26 = puVar24 + 6;
    pfVar23 = pfVar32;
    break;
  default:
    goto switchD_0003de14_caseD_1;
  case 2:
    pfVar23 = (float *)((local_78 & 0xffff) * 0x10 +
                       *(int *)(((unsigned char *)0x00004308) + *(int *)(param_1 + 0x10)));
    pdVar30 = (dword *)(pfVar23 + 1);
    pdVar14 = (dword *)(pfVar23 + 2);
    pdVar26 = (dword *)(pfVar23 + 3);
    break;
  case 3:
    uVar29 = local_78 & 0xff;
    switch(local_78 >> 8 & 0xf) {
    case 0:
      pfVar23 = (float *)(uVar29 * 0x80 + 0x24c0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 1:
      pfVar23 = (float *)(uVar29 * 0x80 + 0x24d0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 2:
      pfVar23 = (float *)(uVar29 * 0x80 + 0x24e0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 3:
      pfVar23 = (float *)(uVar29 * 0x80 + 0x24f0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 4:
      pfVar23 = (float *)(uVar29 * 0x80 + 0x2500 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 5:
      pfVar23 = (float *)(uVar29 * 0x80 + 0x2510 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 6:
      iVar25 = uVar29 * 0x80 + *(int *)(param_1 + 0x10);
      fVar7 = *(float *)(iVar25 + 0x24f4);
      fVar8 = *(float *)(iVar25 + 0x24f0);
      fVar10 = *(float *)(iVar25 + 0x24f8) + FLOAT_001aa0e8;
      dVar36 = (double)_sqrt((double)(fVar10 * fVar10 + fVar8 * fVar8 + fVar7 * fVar7));
      puVar24[6] = fVar6;
      fVar6 = (float)(DOUBLE_001aa200 / dVar36);
      puVar24[5] = fVar10 * fVar6;
      *pfVar32 = fVar8 * fVar6;
      puVar24[4] = fVar7 * fVar6;
      goto LAB_0003e170;
    case 7:
      pfVar23 = (float *)(uVar29 * 0x80 + 0x2530 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    default:
      goto switchD_0003de14_caseD_1;
    }
    break;
  case 4:
    uVar29 = local_78 >> 9 & 3;
    iVar18 = *(int *)(param_1 + 0x10) + 0x24c0;
    iVar25 = (local_78 & 0xff) * 0x80;
    iVar17 = (local_78 >> 8 & 1) * 0x240;
    iVar12 = *(int *)(param_1 + 0x10) + 0x28c0;
    iVar27 = iVar18 + iVar25;
    iVar20 = iVar12 + iVar17;
    if (uVar29 == 1) {
      *pfVar32 = *(float *)(iVar27 + 0x10) * *(float *)(iVar20 + 0x10);
      puVar24[4] = *(float *)(iVar27 + 0x14) * *(float *)(iVar20 + 0x14);
      puVar24[5] = *(float *)(iVar27 + 0x18) * *(float *)(iVar20 + 0x18);
      puVar24[6] = *(undefined4 *)(iVar20 + 0x1c);
    }
    else if (uVar29 == 2) {
      *pfVar32 = *(float *)(iVar27 + 0x20) * *(float *)(iVar20 + 0x20);
      puVar24[4] = *(float *)(iVar27 + 0x24) * *(float *)(iVar20 + 0x24);
      puVar24[5] = *(float *)(iVar27 + 0x28) * *(float *)(iVar20 + 0x28);
      puVar24[6] = *(undefined4 *)(iVar20 + 0x2c);
    }
    else {
      if (uVar29 != 0) goto switchD_0003de14_caseD_1;
      *pfVar32 = *(float *)(iVar18 + iVar25) * *(float *)(iVar12 + iVar17);
      puVar24[4] = *(float *)(iVar27 + 4) * *(float *)(iVar20 + 4);
      puVar24[5] = *(float *)(iVar27 + 8) * *(float *)(iVar20 + 8);
      puVar24[6] = *(undefined4 *)(iVar20 + 0xc);
    }
    goto LAB_0003e170;
  case 5:
    uVar29 = local_78 & 1;
    switch(local_78 >> 1 & 7) {
    case 0:
      pfVar23 = (float *)(uVar29 * 0x240 + 0x28c0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 1:
      pfVar23 = (float *)(uVar29 * 0x240 + 0x28d0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 2:
      pfVar23 = (float *)(uVar29 * 0x240 + 0x28e0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 3:
      pfVar23 = (float *)(uVar29 * 0x240 + 0x28f0 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 4:
      pfVar23 = (float *)(uVar29 * 0x240 + 0x2900 + *(int *)(param_1 + 0x10));
      pdVar30 = (dword *)(pfVar23 + 1);
      pdVar14 = (dword *)(pfVar23 + 2);
      pdVar26 = (dword *)(pfVar23 + 3);
      break;
    case 5:
      iVar25 = *(int *)(param_1 + 0x10);
      iVar17 = iVar25 + 0x28c0 + uVar29 * 0x240;
      *pfVar32 = *(float *)(iVar25 + 0x24b0) * *(float *)(iVar25 + 0x28c0 + uVar29 * 0x240) +
                 *(float *)(iVar17 + 0x30);
      puVar24[4] = *(float *)(iVar25 + 0x24b4) * *(float *)(iVar17 + 4) + *(float *)(iVar17 + 0x34);
      puVar24[5] = *(float *)(iVar25 + 0x24b8) * *(float *)(iVar17 + 8) + *(float *)(iVar17 + 0x38);
      puVar24[6] = *(undefined4 *)(iVar17 + 0x1c);
      goto LAB_0003e170;
    default:
      goto switchD_0003de14_caseD_1;
    }
    break;
  case 6:
    iVar25 = *(int *)(param_1 + 0x10);
    pdVar26 = (dword *)(iVar25 + 0x24bc);
    pdVar30 = (dword *)(iVar25 + 0x24b4);
    pdVar14 = (dword *)(iVar25 + 0x24b8);
    pfVar23 = (float *)(iVar25 + 0x24b0);
    break;
  case 7:
    uVar11 = local_78 >> 5 & 7;
    uVar29 = local_78 & 0x1f;
    if (uVar11 == 1) {
      iVar25 = *(int *)(param_1 + 0x10);
      puVar13 = ((unsigned char *)0x000039a0) + uVar29 * 0x94;
LAB_0003d908:
      pdVar26 = (dword *)(puVar13 + iVar25 + 0x1c);
      pdVar30 = (dword *)(puVar13 + iVar25 + 0x14);
      pdVar14 = (dword *)(puVar13 + iVar25 + 0x18);
      pfVar23 = (float *)(puVar13 + iVar25 + 0x10);
    }
    else {
      if (uVar11 < 2) {
        if (uVar11 == 0) {
          iVar25 = *(int *)(param_1 + 0x10);
          puVar13 = ((unsigned char *)0x00003980) + uVar29 * 0x94;
          goto LAB_0003d8e4;
        }
        goto switchD_0003de14_caseD_1;
      }
      if (uVar11 == 2) {
        iVar25 = *(int *)(param_1 + 0x10);
        puVar13 = ((unsigned char *)0x000039c0) + uVar29 * 0x94;
LAB_0003d92c:
        pdVar26 = (dword *)(puVar13 + iVar25 + 0x20);
        pdVar30 = (dword *)(puVar13 + iVar25 + 0x18);
        pdVar14 = (dword *)(puVar13 + iVar25 + 0x1c);
        pfVar23 = (float *)(puVar13 + iVar25 + 0x14);
      }
      else {
        if (uVar11 != 3) goto switchD_0003de14_caseD_1;
        iVar25 = *(int *)(param_1 + 0x10);
        puVar13 = ((unsigned char *)0x000039e0) + uVar29 * 0x94;
LAB_0003d950:
        pdVar26 = (dword *)(puVar13 + iVar25 + 0x24);
        pdVar30 = (dword *)(puVar13 + iVar25 + 0x1c);
        pdVar14 = (dword *)(puVar13 + iVar25 + 0x20);
        pfVar23 = (float *)(puVar13 + iVar25 + 0x18);
      }
    }
    break;
  case 8:
    uVar11 = local_78 >> 5 & 7;
    uVar29 = local_78 & 0x1f;
    if (uVar11 == 1) {
      iVar25 = *(int *)(param_1 + 0x10);
      puVar13 = ((unsigned char *)0x000039b0) + uVar29 * 0x94;
      goto LAB_0003d908;
    }
    if (uVar11 < 2) {
      if (uVar11 == 0) {
        iVar25 = *(int *)(param_1 + 0x10);
        puVar13 = ((unsigned char *)0x00003990) + uVar29 * 0x94;
        goto LAB_0003d8e4;
      }
    }
    else {
      if (uVar11 == 2) {
        iVar25 = *(int *)(param_1 + 0x10);
        puVar13 = ((unsigned char *)0x000039d0) + uVar29 * 0x94;
        goto LAB_0003d92c;
      }
      if (uVar11 == 3) {
        iVar25 = *(int *)(param_1 + 0x10);
        puVar13 = ((unsigned char *)0x000039f0) + uVar29 * 0x94;
        goto LAB_0003d950;
      }
    }
    goto switchD_0003de14_caseD_1;
  case 9:
    iVar25 = *(int *)(param_1 + 0x10) + (local_78 & 0x1f) * 0x7c;
    pdVar26 = (dword *)(((unsigned char *)0x000031c0) + iVar25 + 0x10);
    pdVar14 = (dword *)(((unsigned char *)0x000031c0) + iVar25 + 0xc);
    pdVar30 = (dword *)(((unsigned char *)0x000031c0) + iVar25 + 8);
    pfVar23 = (float *)(((unsigned char *)0x000031c0) + iVar25 + 4);
    break;
  case 10:
    iVar25 = *(int *)(param_1 + 0x10);
    puVar13 = ((unsigned char *)0x00003e20) + (local_78 & 0xff) * 0x10;
LAB_0003d8e4:
    pdVar26 = (dword *)(puVar13 + iVar25 + 0x18);
    pdVar30 = (dword *)(puVar13 + iVar25 + 0x10);
    pdVar14 = (dword *)(puVar13 + iVar25 + 0x14);
    pfVar23 = (float *)(puVar13 + iVar25 + 0xc);
    break;
  case 0xb:
    iVar25 = *(int *)(param_1 + 0x10);
    pdVar26 = (dword *)(((unsigned char *)0x00002dec) + iVar25);
    pdVar30 = (dword *)(((unsigned char *)0x00002de4) + iVar25);
    pdVar14 = (dword *)(((unsigned char *)0x00002de8) + iVar25);
    pfVar23 = (float *)(((unsigned char *)0x00002de0) + iVar25);
    break;
  case 0xc:
    iVar25 = *(int *)(param_1 + 0x10);
    pdVar26 = (dword *)(((unsigned char *)0x00002dfc) + iVar25);
    pdVar30 = (dword *)(((unsigned char *)0x00002df4) + iVar25);
    pdVar14 = (dword *)(((unsigned char *)0x00002df8) + iVar25);
    pfVar23 = (float *)(((unsigned char *)0x00002df0) + iVar25);
    break;
  case 0xd:
    iVar25 = *(int *)(param_1 + 0x10);
    pdVar26 = (dword *)(((unsigned char *)0x000030c8) + iVar25);
    pdVar30 = (dword *)(((unsigned char *)0x000030c0) + iVar25);
    pdVar14 = (dword *)(((unsigned char *)0x000030c4) + iVar25);
    pfVar23 = (float *)(((unsigned char *)0x000030bc) + iVar25);
    break;
  case 0xe:
    iVar25 = *(int *)(param_1 + 0x10);
    pdVar26 = (dword *)(((unsigned char *)0x000030d8) + iVar25);
    pdVar30 = (dword *)(((unsigned char *)0x000030d0) + iVar25);
    pdVar14 = (dword *)(((unsigned char *)0x000030d4) + iVar25);
    pfVar23 = (float *)(((unsigned char *)0x000030cc) + iVar25);
    break;
  case 0xf:
    *pfVar32 = (float)*(double *)(FUN_00001830 + *(int *)(param_1 + 0x10));
    puVar24[4] = (float)*(double *)(*(int *)(param_1 + 0x10) + 0x1838);
    dVar38 = *(double *)(FUN_00001830 + *(int *)(param_1 + 0x10));
    dVar36 = *(double *)(*(int *)(param_1 + 0x10) + 0x1838);
    puVar24[6] = 0x3f800000;
    puVar24[5] = (float)(dVar36 - dVar38);
    goto LAB_0003e170;
  case 0x12:
    fVar6 = *(float *)(*(int *)(param_1 + 0x10) + 0x24a4);
    puVar24[6] = fVar6;
    *pfVar32 = fVar6;
    puVar24[4] = fVar6;
    puVar24[5] = fVar6;
    goto LAB_0003e170;
  }
LAB_0003e150:
  *pfVar32 = *pfVar23;
  puVar24[4] = *pdVar30;
  puVar24[5] = *pdVar14;
  puVar24[6] = *pdVar26;
LAB_0003e170:
  uVar37 = *(undefined8 *)(puVar24 + 5);
  uVar35 = *(undefined8 *)pfVar32;
  iVar25 = (uint)bVar2 * 0x10;
  puVar24 = puVar24 + 7;
  *(undefined8 *)(local_84 + iVar25) = uVar35;
  *(undefined8 *)(local_84 + iVar25 + 8) = uVar37;
  puVar22 = *(undefined8 **)(pbVar34 + 4);
  pbVar34 = pbVar34 + 8;
  puVar22[1] = uVar37;
  *puVar22 = uVar35;
  goto LAB_0003d820;
switchD_0003de14_caseD_1:
  pdVar30 = &MACH_HEADER.cputype;
  pdVar14 = &MACH_HEADER.cpusubtype;
  pdVar26 = &MACH_HEADER.filetype;
  pfVar23 = (float *)0x0;
  goto LAB_0003e150;
}

/* FUN_0003e250 @ 0x3e250 (188 bytes) */
int FUN_0003e250(param_1)
  int param_1;
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 local_68 [16];
  undefined4 local_58 [22];
  
  if (*(int *)(param_1 + 0x29fc) != 0) {
    iVar3 = 0;
    iVar4 = 0;
    iVar5 = 0x10;
    iVar2 = param_1;
    do {
      if (*(int *)(iVar2 + 0x18c) == 0) {
        *(undefined4 *)((int)local_58 + iVar4) = 0;
        local_68[iVar3] = 0;
      }
      else {
        uVar1 = **(ushort **)(*(int *)(iVar2 + 0x18c) + 0x30);
        local_68[iVar3] = 1;
        if ((uVar1 & 0xf) == 0) {
          *(undefined4 *)((int)local_58 + iVar4) = 2;
        }
        else if ((uVar1 & 0xf) == 1) {
          *(undefined4 *)((int)local_58 + iVar4) = 1;
        }
        else {
          *(undefined4 *)((int)local_58 + iVar4) = 0;
        }
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 4;
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_000a1090(param_1 + 0x240,local_68);
  }
  return;
}

/* FUN_0003e320 @ 0x3e320 (120 bytes) */
int FUN_0003e320(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x1d0);
  ((int (*)())FUN_0003e250)();
  if (piVar4 != (int *)0x0) {
    iVar1 = *piVar4;
    puVar3 = *(uint **)(iVar1 + 4);
    uVar2 = *puVar3;
    ((int (*)())FUN_0003e420)(param_1 + 0x240,*(int *)(param_1 + 0x29ec) + 0x14,uVar2 >> 0x10 & 0xff,
                 puVar3 + (uVar2 & 0xffff),((unsigned char *)0x00001010) + *(int *)(param_1 + 0x10),
                 *(undefined4 *)(iVar1 + 0x18));
  }
  return param_3;
}

/* FUN_0003e3a0 @ 0x3e3a0 (116 bytes) */
int FUN_0003e3a0(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_2;
  if (iVar2 == 0) {
    iVar2 = FUN_000a12b0(param_1,1);
    *param_2 = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  FUN_000a12f0(param_1,iVar2);
  uVar1 = FUN_000a11a0(param_1);
  *(undefined4 *)(param_1 + 0x27b8) = uVar1;
  return 1;
}

/* FUN_0003e420 @ 0x3e420 (152 bytes) */
int FUN_0003e420(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  uint *param_4;
  int param_5;
  int param_6;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 != 0) {
    iVar4 = 0;
    do {
      uVar1 = *param_4;
      param_4 = param_4 + 1;
      if ((uVar1 & 3) != 1) {
        uVar2 = uVar1 >> 0xc & 0xff;
        if ((uVar1 & 3) == 0) {
          iVar3 = uVar2 * 0x10 + param_5;
        }
        else {
          iVar3 = uVar2 * 0x10 + param_6;
        }
        FUN_000a2100(param_1,(uVar1 >> 0x14 & 0xff) + 0x8941,iVar3);
      }
      iVar4 = iVar4 + 1;
    } while (param_3 != iVar4);
  }
  return;
}

/* FUN_0003e4c0 @ 0x3e4c0 (8 bytes) */
int FUN_0003e4c0(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  FUN_000a1570(param_1,*param_2);
  return;
}

/* FUN_0003e4d0 @ 0x3e4d0 (276 bytes) */
int FUN_0003e4d0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  uint *param_4;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  if (param_3 != 0) {
    iVar5 = 0;
    do {
      uVar4 = *param_4;
      param_4 = param_4 + 1;
      uVar3 = 0x8977;
      uVar1 = uVar4 & 0x300;
      if (uVar1 != 0x100) {
        if (uVar1 < 0x101) {
          uVar3 = 0x8976;
          if (uVar1 != 0) {
LAB_0003e540:
            uVar3 = 0;
          }
        }
        else {
          uVar3 = 0x8978;
          if (uVar1 != 0x200) {
            if (uVar1 != 0x300) goto LAB_0003e540;
            uVar3 = 0x8979;
          }
        }
      }
      uVar1 = uVar4 >> 0x14 & 0xff;
      if ((uVar4 & 7) == 1) {
        iVar2 = uVar1 + 0x8921;
      }
      else {
        iVar2 = 0;
        if ((uVar4 & 7) == 5) {
          iVar2 = uVar1 + 0x84c0;
        }
      }
      if ((uVar4 & 0xf0) == 0) {
        FUN_000a1a60(param_1);
      }
      else {
        FUN_000a1bc0(param_1,(uVar4 >> 0xc & 0xff) + 0x8921,iVar2,uVar3);
      }
      iVar5 = iVar5 + 1;
    } while (param_3 != iVar5);
  }
  return;
}

/* FUN_0003e600 @ 0x3e600 (1352 bytes) */
int FUN_0003e600(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  uint *param_4;
{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  undefined4 local_5c;
  
  if (param_3 != 0) {
    iVar9 = 0;
    iVar7 = 0;
    do {
      uVar5 = *param_4;
      param_4 = param_4 + 1;
      uVar2 = uVar5 & 0xf00;
      if (uVar2 == 0x500) {
        uVar10 = 0x8967;
      }
      else if (uVar2 < 0x501) {
        if (uVar2 == 0x200) {
          uVar10 = 0x8964;
        }
        else if (uVar2 < 0x201) {
          if (uVar2 == 0) {
            uVar10 = 0x8961;
          }
          else {
            uVar10 = 0x8963;
            if (uVar2 != 0x100) {
LAB_0003e674:
              uVar10 = 0;
            }
          }
        }
        else if (uVar2 == 0x300) {
          uVar10 = 0x8965;
        }
        else {
          if (uVar2 != 0x400) goto LAB_0003e674;
          uVar10 = 0x8966;
        }
      }
      else if (uVar2 == 0x800) {
        uVar10 = 0x896a;
      }
      else if (uVar2 < 0x801) {
        if (uVar2 == 0x600) {
          uVar10 = 0x8968;
        }
        else {
          if (uVar2 != 0x700) goto LAB_0003e674;
          uVar10 = 0x8969;
        }
      }
      else if (uVar2 == 0x900) {
        uVar10 = 0x896b;
      }
      else {
        if (uVar2 != 0xa00) goto LAB_0003e674;
        uVar10 = 0x896c;
      }
      uVar11 = 0;
      iVar8 = (uVar5 >> 0x14 & 0xff) + 0x8921;
      if ((uVar5 & 0xf000) != 0) {
        puVar1 = (undefined *)(uVar5 & 0x7000);
        uVar11 = 4;
        if (puVar1 != (undefined *)0x3000) {
          if (puVar1 < (undefined *)0x3001) {
            uVar11 = 1;
            if ((puVar1 != (undefined *)0x1000) && (uVar11 = 2, puVar1 != (undefined *)0x2000)) {
LAB_0003e7c8:
              uVar11 = 0;
            }
          }
          else {
            uVar11 = 0x10;
            if ((puVar1 != ((unsigned char *)0x00005000)) && (uVar11 = 0x20, puVar1 != (undefined *)0x6000)) {
              if (puVar1 != (undefined *)0x4000) goto LAB_0003e7c8;
              uVar11 = 8;
            }
          }
        }
        if ((uVar5 & 0x8000) != 0) {
          uVar11 = uVar11 | 0x40;
        }
      }
      if (uVar2 == 0) {
        iVar9 = 1;
LAB_0003e830:
        puVar6 = &local_60;
        iVar12 = iVar9;
        do {
          uVar4 = *param_4;
          param_4 = param_4 + 1;
          uVar2 = uVar4 & 7;
          uVar3 = uVar4 >> 0x14 & 0xff;
          if (uVar2 == 2) {
            uVar3 = uVar3 + 0x8941;
          }
          else if (uVar2 < 3) {
            if (uVar2 != 1) goto LAB_0003e868;
            uVar3 = uVar3 + 0x8921;
          }
          else if (uVar2 != 3) {
            if (uVar2 == 4) {
              if (uVar3 == 0) {
                uVar3 = 0x8577;
              }
              else {
                if (uVar3 != 1) goto LAB_0003e868;
                uVar3 = 0x896d;
              }
            }
            else {
LAB_0003e868:
              uVar3 = 0;
            }
          }
          uVar2 = uVar4 & 0x7000;
          puVar6[-2] = uVar3;
          if (uVar2 == 0x2000) {
            uVar3 = 0x1904;
          }
          else if (uVar2 < 0x2001) {
            uVar3 = 0x1903;
            if (uVar2 != 0x1000) {
LAB_0003e904:
              uVar3 = 0;
            }
          }
          else {
            uVar3 = 0x1905;
            if ((uVar2 != 0x3000) && (uVar3 = 0x1906, uVar2 != 0x4000)) goto LAB_0003e904;
          }
          puVar6[-1] = uVar3;
          uVar2 = 0;
          if ((uVar4 & 0xf00) != 0) {
            uVar2 = uVar4 >> 6 & 4;
            if ((uVar4 & 0x200) != 0) {
              uVar2 = uVar2 | 1;
            }
            if ((uVar4 & 0x400) != 0) {
              uVar2 = uVar2 | 8;
            }
            if ((uVar4 & 0x800) != 0) {
              uVar2 = uVar2 | 2;
            }
          }
          *puVar6 = uVar2;
          puVar6 = puVar6 + 3;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
      else {
        if (uVar2 < 0x501) {
          iVar9 = 2;
          goto LAB_0003e830;
        }
        if (uVar2 < 0xa01) {
          iVar9 = 3;
          goto LAB_0003e830;
        }
        if (iVar9 != 0) goto LAB_0003e830;
      }
      if ((uVar5 & 0x70000) == 0) {
        uVar2 = 0;
        if ((uVar5 & 0xf0000) == 0) goto LAB_0003e9b8;
      }
      else {
        uVar2 = (uVar5 & 0x70000) >> 0x10 & 1;
        if ((uVar5 & 0x20000) != 0) {
          uVar2 = uVar2 | 2;
        }
        if ((uVar5 & 0x40000) != 0) {
          uVar2 = uVar2 | 4;
        }
LAB_0003e9b8:
        if (iVar9 == 2) {
          FUN_000a1dc0(param_1,uVar10,iVar8,uVar2,uVar11,local_68,local_64,local_60);
        }
        else if (iVar9 == 3) {
          FUN_000a1e70(param_1,uVar10,iVar8,uVar2,uVar11,local_68,local_64,local_60);
        }
        else if (iVar9 == 1) {
          FUN_000a1d20(param_1,uVar10,iVar8,uVar2,uVar11,local_68,local_64,local_60);
        }
      }
      if (((uVar5 & 0x80000) != 0) || ((uVar5 & 0xf0000) == 0)) {
        if (iVar9 == 2) {
          FUN_000a1fb0(param_1,uVar10,iVar8,uVar11,local_68,local_64,local_60,local_5c);
        }
        else if (iVar9 == 3) {
          FUN_000a2050(param_1,uVar10,iVar8,uVar11,local_68,local_64,local_60,local_5c);
        }
        else if (iVar9 == 1) {
          FUN_000a1f20(param_1,uVar10,iVar8,uVar11,local_68,local_64,local_60);
        }
      }
      iVar7 = iVar7 + 1;
    } while (param_3 != iVar7);
  }
  return;
}

/* FUN_0003eb70 @ 0x3eb70 (296 bytes) */
int FUN_0003eb70(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 param_3;
{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  
  *(undefined2 *)(param_1 + 0x2800) = 0;
  FUN_000a16b0();
  uVar1 = *(ushort *)((int)param_2 + 0x16);
  uVar4 = *param_2 >> 0x10 & 0xff;
  puVar6 = param_2 + (*param_2 & 0xffff);
  if (uVar4 != 0) {
    uVar5 = 0;
    do {
      uVar2 = *puVar6;
      puVar6 = puVar6 + 1;
      if ((uVar2 & 3) == 1) {
        FUN_000a2100(param_1,(uVar2 >> 0x14 & 0xff) + 0x8941,
                     (int)param_2 + (uVar2 >> 8 & 0xff0) + (uint)uVar1 * 4);
      }
      uVar5 = uVar5 + 1;
    } while (uVar4 != uVar5);
  }
  ((int (*)())FUN_0003e4d0)(param_1,param_3,param_2[1] >> 0x10 & 0xff,param_2 + (param_2[1] & 0xffff));
  ((int (*)())FUN_0003e600)(param_1,param_3,param_2[2] >> 0x10 & 0xff,param_2 + (param_2[2] & 0xffff));
  ((int (*)())FUN_0003e4d0)(param_1,param_3,param_2[3] >> 0x10 & 0xff,param_2 + (param_2[3] & 0xffff));
  ((int (*)())FUN_0003e600)(param_1,param_3,param_2[4] >> 0x10 & 0xff,param_2 + (param_2[4] & 0xffff));
  FUN_000a1750(param_1);
  uVar3 = FUN_000a11a0(param_1);
  *(undefined4 *)(param_1 + 0x27b8) = uVar3;
  return 1;
}

/* FUN_0003ed50 @ 0x3ed50 (60 bytes) */
int FUN_0003ed50(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = *(uint *)(((uint)*(ushort *)(param_2 + 6) + *(int *)(*param_1 + 0x14)) * 8 + *param_1) >>
          0x1a & 7;
  if (uVar1 == 3) {
    return 1;
  }
  return (uint)(uVar1 == 4) << 1;
}

/* FUN_0003ed90 @ 0x3ed90 (160 bytes) */
int FUN_0003ed90(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  uint *param_2;
  uint *param_3;
  uint *param_4;
  int param_5;
{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *param_2;
  uVar3 = 0;
  if ((uVar5 & 0xe0000) == 0x20000) {
    uVar2 = (uint)*(ushort *)((int)param_2 + 6);
  }
  else {
    uVar1 = *(ushort *)((int)param_2 + 6);
    iVar4 = *(int *)(*param_1 + 0x10);
    param_1[4] = 1 << (uVar1 & 0x3f) | param_1[4];
    uVar2 = (uint)uVar1 + iVar4 + 1;
    uVar5 = *param_2;
  }
  if (param_5 != 0) {
    uVar3 = 0x100;
  }
  *param_3 = uVar2 & 0xffff | 0x440000;
  *param_4 = (uVar5 >> 0x10 & 1) << 6 |
             (uVar5 >> 0xf & 1) << 4 | (uVar5 >> 0xe & 1) << 2 | uVar5 >> 0xd & 1 | uVar3;
  return 0;
}

/* FUN_0003ee30 @ 0x3ee30 (88 bytes) */
int FUN_0003ee30(param_1, param_2, param_3)
  uint param_1;
  int param_2;
  uint *param_3;
{
  if (param_2 == 0) {
    *param_3 = param_1 & 7 | *param_3 & 0xfffffff8;
    return;
  }
  if (param_2 == 1) {
    *param_3 = (param_1 & 7) << 4 | *param_3 & 0xffffff8f;
    return;
  }
  if (param_2 == 2) {
    *param_3 = (param_1 & 7) << 8 | *param_3 & 0xfffff8ff;
    return;
  }
  *param_3 = (param_1 & 7) << 0xc | *param_3 & 0xffff8fff;
  return;
}

/* FUN_0003eea0 @ 0x3eea0 (168 bytes) */
int FUN_0003eea0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint *param_3;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + 0x14) >> 0x15 & 0x3f) < 0x20) {
    iVar1 = *(int *)(param_1 + 0x28);
    iVar3 = *(int *)(param_1 + 0x18) * 4;
    *(undefined4 *)(iVar3 + iVar1) = 0x1c;
    iVar3 = iVar3 + iVar1;
    uVar2 = *(uint *)(param_1 + 0x14);
    *(undefined4 *)(iVar3 + 0x14) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    *(undefined4 *)(iVar3 + 0x10) = 0;
    *(undefined4 *)(iVar3 + 8) = param_2;
    *(uint *)(iVar3 + 4) = uVar2 >> 0x15 & 0x3f | 0x20000;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 6;
    *param_3 = *(uint *)(param_1 + 0x14) >> 0x15 & 0x3f;
    *(uint *)(param_1 + 0x14) =
         ((*(uint *)(param_1 + 0x14) >> 0x15 & 0x3f) + 1) * 0x200000 & 0x7e00000 |
         *(uint *)(param_1 + 0x14) & 0xf81fffff;
    return *(int *)(param_1 + 0x24);
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    return *(int *)(param_1 + 0x24);
  }
  *(undefined4 *)(param_1 + 0x24) = 4;
  return 4;
}

/* FUN_0003ef50 @ 0x3ef50 (240 bytes) */
int FUN_0003ef50(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)(param_1 + 0x28);
  iVar3 = *(int *)(param_1 + 0x2c);
  uVar1 = *(uint *)(param_1 + 0x30);
  if (uVar1 < (uint)(param_2 + iVar3)) {
    if (uVar1 == 0) {
      uVar1 = 0x10;
    }
    else {
      uVar1 = uVar1 << 1;
    }
    for (; uVar1 < (uint)(param_2 + iVar3); uVar1 = uVar1 << 1) {
    }
    if ((void *)*piVar4 == (void *)0x0) {
      pvVar2 = _malloc(uVar1 << 2);
    }
    else {
      pvVar2 = _realloc((void *)*piVar4,uVar1 << 2);
    }
    if (pvVar2 == (void *)0x0) {
      if (*(int *)(param_1 + 0x24) != 0) {
        return *(int *)(param_1 + 0x24);
      }
      *(undefined4 *)(param_1 + 0x24) = 1;
      return 1;
    }
    *piVar4 = (int)pvVar2;
    *(uint *)(param_1 + 0x30) = uVar1;
    iVar3 = *(int *)(param_1 + 0x2c);
  }
  *(int *)(param_1 + 0x2c) = param_2 + iVar3;
  *param_3 = iVar3 * 4 + *piVar4;
  return 0;
}

/* FUN_0003f050 @ 0x3f050 (336 bytes) */
int FUN_0003f050(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 *param_3;
{
  byte *pbVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  
  iVar5 = *param_1;
  iVar3 = iVar5 + *(int *)(iVar5 + 0x54) * 8 + param_2 * 8;
  if ((*(uint *)(iVar3 + 0x18) & 0x3800000) == 0x1000000) {
    iVar3 = ((uint)*(ushort *)(iVar3 + 0x1e) + *(int *)(iVar5 + 0x2c)) * 8;
    uVar7 = *(uint *)(iVar5 + iVar3);
    iVar5 = iVar5 + iVar3;
    if (((uVar7 & 0x1f0000) == 0x10000) && ((uVar7 & 0x1c000000) == 0xc000000)) {
      *param_3 = *(undefined4 *)((uint)*(ushort *)(iVar5 + 2) * 0x10 + param_1[3]);
      pbVar4 = (byte *)param_1[0xd];
      uVar7 = *(uint *)(pbVar4 + 0x20) >> 0x1b;
      if (uVar7 == 0) {
        uVar2 = *(ushort *)(iVar5 + 2);
LAB_0003f164:
        pbVar4[uVar7 * 2] = (byte)uVar2;
        *(char *)(uVar7 * 2 + param_1[0xd] + 1) = (char)*param_3;
        *(int *)(param_1[0xd] + 0x20) = *(int *)(param_1[0xd] + 0x20) + 0x8000000;
        return 0;
      }
      uVar2 = *(ushort *)(iVar5 + 2);
      if (*pbVar4 != uVar2) {
        iVar3 = 0;
        pbVar6 = pbVar4;
        uVar8 = uVar7;
        do {
          iVar3 = iVar3 + 1;
          uVar8 = uVar8 - 1;
          if (uVar8 == 0) {
            if (0xf < iVar3) {
              if (param_1[9] != 0) {
                return param_1[9];
              }
              param_1[9] = 4;
              return 4;
            }
            goto LAB_0003f164;
          }
          pbVar1 = pbVar6 + 2;
          pbVar6 = pbVar6 + 2;
        } while (*pbVar1 != uVar2);
      }
      return 0;
    }
  }
  if (param_1[9] != 0) {
    return param_1[9];
  }
  param_1[9] = 2;
  return 2;
}

/* FUN_0003f1c0 @ 0x3f1c0 (700 bytes) */
int FUN_0003f1c0(param_1, param_2, param_3, param_4)
  int *param_1;
  uint *param_2;
  uint *param_3;
  uint *param_4;
{
  int iVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  uVar8 = *param_2;
  uVar5 = uVar8 & 0x3800000;
  if (uVar5 == 0) {
    iVar9 = *param_1;
    iVar1 = ((uint)*(ushort *)((int)param_2 + 6) + *(int *)(iVar9 + 0x24)) * 8;
    switch(*(ushort *)(iVar9 + iVar1) & 0xf) {
    default:
switchD_0003f230_caseD_0:
      if (param_1[9] != 0) {
        return param_1[9];
      }
      param_1[9] = 3;
      return 3;
    case 1:
      bVar2 = false;
      uVar5 = 0x160000;
      break;
    case 2:
      bVar2 = false;
      uVar5 = 0x120000;
      break;
    case 3:
      bVar2 = false;
      uVar5 = 0x130000;
      break;
    case 5:
      bVar2 = true;
      uVar5 = 0x100000;
      break;
    case 7:
      bVar2 = false;
      uVar5 = *(uint *)(iVar9 + iVar1) & 0x1f | 0x110000;
    }
  }
  else if (uVar5 == 0x1000000) {
    bVar2 = false;
    uVar5 = *(ushort *)((int)param_2 + 6) | 0x10000;
  }
  else if (uVar5 == 0x800000) {
    bVar2 = false;
    uVar5 = *(ushort *)((int)param_2 + 6) | 0x40000;
  }
  else {
    if (uVar5 != 0x1800000) goto switchD_0003f230_caseD_0;
    bVar2 = false;
    uVar5 = (uint)*(ushort *)((int)param_2 + 6) + *(int *)(*param_1 + 0x10) + 1 & 0xffff | 0x40000;
  }
  if ((param_1[5] & 0x20000000U) == 0) {
    uVar6 = 4;
  }
  else {
    uVar6 = (uVar8 >> 0xc & 3) + 1;
  }
  uVar3 = uVar8 >> 0x1b & 1;
  uVar7 = 4;
  if (uVar6 != 0) {
    uVar7 = *(uint *)(&DAT_001dac08 + (uVar8 >> 0x13 & 0xc)) >> 0x19 & 7;
  }
  uVar4 = uVar3 ^ *(uint *)(&DAT_001dac08 + (uVar8 >> 0x13 & 0xc)) >> 0x18 & 1;
  uVar10 = uVar4 << 3 | uVar7;
  if (uVar6 < 2) {
    uVar8 = uVar4 << 0xf |
            uVar7 << 0xc | uVar4 << 0xb | uVar7 << 8 | uVar4 << 7 | uVar7 << 4 | uVar10;
  }
  else {
    uVar7 = 4;
    if (2 < uVar6) {
      uVar7 = *(uint *)(&DAT_001dac08 + (uVar8 >> 0xf & 0xc)) >> 0x19 & 7;
    }
    uVar4 = 4;
    if (3 < uVar6) {
      uVar4 = *(uint *)(&DAT_001dac08 + (uVar8 >> 0xd & 0xc)) >> 0x19 & 7;
    }
    uVar8 = (uVar3 ^ *(uint *)(&DAT_001dac08 + (uVar8 >> 0xd & 0xc)) >> 0x18 & 1) << 0xf |
            uVar4 << 0xc |
            (uVar3 ^ *(uint *)(&DAT_001dac08 + (uVar8 >> 0xf & 0xc)) >> 0x18 & 1) << 0xb |
            uVar7 << 8 |
            (uVar3 ^ *(uint *)(&DAT_001dac08 + (uVar8 >> 0x11 & 0xc)) >> 0x18 & 1) << 7 |
            *(uint *)(&DAT_001dac08 + (uVar8 >> 0x11 & 0xc)) >> 0x15 & 0x70 | uVar10;
  }
  if (bVar2) {
    uVar8 = ((byte)(DAT_001dac00)[uVar8 >> 0xc & 7] & 7) << 0xc |
            ((byte)(DAT_001dac00)[uVar8 >> 8 & 7] & 7) << 8 |
            ((byte)(DAT_001dac00)[uVar8 >> 4 & 7] & 7) << 4 |
            (byte)(DAT_001dac00)[uVar8 & 7] & 7 | uVar8 & 0xffff8888;
  }
  *param_3 = uVar5 | 0x400000;
  *param_4 = uVar8;
  return 0;
}

/* FUN_0003f4e0 @ 0x3f4e0 (232 bytes) */
int FUN_0003f4e0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  undefined4 *param_3;
  uint *param_4;
  uint *param_5;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_38;
  uint local_34 [7];
  
  iVar2 = ((int (*)())FUN_0003f1c0)(param_1,param_2,&local_38,local_34);
  if (iVar2 == 0) {
    uVar6 = *param_5;
    uVar3 = 0;
    uVar7 = *param_2 >> 0x1b & 1;
    uVar1 = *(uint *)(&DAT_001dac08 + (uVar6 >> 10 & 0x3c));
    uVar5 = *(uint *)(&DAT_001dac08 + (uVar6 >> 6 & 0x3c));
    uVar4 = *(uint *)(&DAT_001dac08 + (uVar6 >> 2 & 0x3c));
    uVar6 = *(uint *)(&DAT_001dac08 + (uVar6 & 0xf) * 4);
    *param_3 = local_38;
    *param_4 = (uVar7 ^ uVar6 >> 0x18 & 1) << 0xf |
               uVar6 >> 0xd & 0x7000 |
               (uVar7 ^ uVar4 >> 0x18 & 1) << 0xb |
               uVar4 >> 0x11 & 0x700 |
               (uVar7 ^ uVar5 >> 0x18 & 1) << 7 |
               uVar5 >> 0x15 & 0x70 |
               (uVar7 ^ uVar1 >> 0x18 & 1) << 3 | uVar1 >> 0x19 & 7 | local_34[0] & 0xffff0000;
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 0x24);
  }
  return uVar3;
}

/* FUN_0003f5d0 @ 0x3f5d0 (12 bytes) */
int FUN_0003f5d0(param_1)
  void *param_1;
{
  if (param_1 == (void *)0x0) {
    return;
  }
  _free(param_1);
  return;
}

/* FUN_0003f5e0 @ 0x3f5e0 (112 bytes) */
int FUN_0003f5e0(param_1)
  void *param_1;
{
  if (*(int *)((int)param_1 + 0x34) != 0) {
    ((int (*)())FUN_0003f5d0)();
  }
  if (*(void **)((int)param_1 + 0x28) != (void *)0x0) {
    _free(*(void **)((int)param_1 + 0x28));
  }
  if (param_1 != (void *)0x0) {
    _free(param_1);
    return;
  }
  return;
}

/* FUN_0003f660 @ 0x3f660 (220 bytes) */
int FUN_0003f660()
{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  
  pvVar2 = _malloc(0x38);
  if (pvVar2 != (void *)0x0) {
    _memset(pvVar2,0,0x38);
    *(undefined4 *)((int)pvVar2 + 0x24) = 0;
    *(undefined4 *)((int)pvVar2 + 0x28) = 0;
    *(undefined4 *)((int)pvVar2 + 0x30) = 0;
    *(undefined4 *)((int)pvVar2 + 0x2c) = 0;
    *(undefined4 *)((int)pvVar2 + 4) = 0xffffffff;
    *(undefined4 *)((int)pvVar2 + 8) = 0xffffffff;
    pvVar3 = _malloc(0x24);
    pvVar1 = (void *)0x0;
    if (pvVar3 != (void *)0x0) {
      _memset(pvVar3,0,0x24);
      pvVar1 = pvVar3;
    }
    *(void **)((int)pvVar2 + 0x34) = pvVar1;
    if (*(int *)((int)pvVar2 + 0x34) != 0) {
      return pvVar2;
    }
    if (pvVar2 != (void *)0x0) {
      _free(pvVar2);
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}

/* FUN_0003f750 @ 0x3f750 (232 bytes) */
int FUN_0003f750(param_1, param_2, param_3, param_4)
  int *param_1;
  uint *param_2;
  uint *param_3;
  uint *param_4;
{
  undefined4 uVar1;
  uint uVar2;
  
  if (((param_1[5] & 0x20000000U) != 0) &&
     (((((uVar2 = *param_2, (uVar2 & 0x2000) != 0 && ((uVar2 & 0x300) != 0)) ||
        (((uVar2 & 0x4000) != 0 && ((uVar2 & 0xc0) != 0x40)))) ||
       (((uVar2 & 0x8000) != 0 && ((uVar2 & 0x30) != 0x20)))) ||
      (((uVar2 & 0x10000) != 0 && ((uVar2 & 0xc) != 0xc)))))) {
    uVar1 = *(undefined4 *)(*param_1 + 0x10);
    *param_3 = 0;
    *param_4 = 0;
    *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    *(short *)((int)param_3 + 2) = (short)uVar1;
    *param_3 = *param_3 | 0x400000;
    *param_4 = *param_4 & 0xffffff00 | 0x55;
    return 0;
  }
  uVar1 = ((int (*)())FUN_0003ed90)();
  return uVar1;
}

/* FUN_0003f850 @ 0x3f850 (396 bytes) */
int FUN_0003f850(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  dword *pdVar4;
  dword *pdVar5;
  dword *pdVar6;
  undefined4 *puVar7;
  dword *pdVar8;
  int *piVar9;
  dword *pdVar10;
  dword *pdVar11;
  
  piVar9 = (int *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  iVar2 = *(int *)(param_1 + 0x2c);
  uVar1 = *(uint *)(param_1 + 0x30);
  if (uVar1 < iVar2 + 7U) {
    if (uVar1 == 0) {
      uVar1 = 0x10;
    }
    else {
      uVar1 = uVar1 << 1;
    }
    for (; uVar1 < iVar2 + 7U; uVar1 = uVar1 << 1) {
    }
    if ((void *)*piVar9 == (void *)0x0) {
      pvVar3 = _malloc(uVar1 << 2);
    }
    else {
      pvVar3 = _realloc((void *)*piVar9,uVar1 << 2);
    }
    if (pvVar3 == (void *)0x0) {
      iVar2 = *(int *)(param_1 + 0x24);
      if (iVar2 == 0) {
        iVar2 = 1;
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (iVar2 != 0) {
        return iVar2;
      }
      puVar7 = (undefined4 *)0x0;
      pdVar8 = &MACH_HEADER.cputype;
      pdVar10 = &MACH_HEADER.cpusubtype;
      pdVar11 = &MACH_HEADER.filetype;
      pdVar4 = &MACH_HEADER.ncmds;
      pdVar5 = &MACH_HEADER.sizeofcmds;
      pdVar6 = &MACH_HEADER.flags;
      goto LAB_0003f918;
    }
    *piVar9 = (int)pvVar3;
    *(uint *)(param_1 + 0x30) = uVar1;
    iVar2 = *(int *)(param_1 + 0x2c);
  }
  *(int *)(param_1 + 0x2c) = iVar2 + 7;
  puVar7 = (undefined4 *)(iVar2 * 4 + *piVar9);
  pdVar8 = puVar7 + 1;
  pdVar10 = puVar7 + 2;
  pdVar11 = puVar7 + 3;
  pdVar4 = puVar7 + 4;
  pdVar5 = puVar7 + 5;
  pdVar6 = puVar7 + 6;
LAB_0003f918:
  *puVar7 = 1;
  *pdVar8 = 0x10200;
  *pdVar10 = 0x47;
  *pdVar11 = 0x170000;
  *pdVar4 = 0x440000;
  *pdVar5 = (dword)((unsigned char *)0x00004444);
  *pdVar6 = 0x28;
  return 0;
}

/* FUN_0003f9f0 @ 0x3f9f0 (472 bytes) */
int FUN_0003f9f0(param_1, param_2, param_3)
  int *param_1;
  uint *param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  dword *pdVar7;
  dword *pdVar8;
  uint uVar9;
  uint uVar10;
  dword *pdVar11;
  uint uVar12;
  dword *pdVar13;
  int *piVar14;
  dword local_38;
  dword local_34 [6];
  
  local_38 = 0;
  local_34[0] = 0;
  iVar2 = ((int (*)())FUN_0003ed90)(param_1,param_2,&local_38,local_34,param_3);
  if (iVar2 != 0) {
    return param_1[9];
  }
  uVar12 = *param_2;
  piVar14 = param_1 + 10;
  iVar2 = param_1[0xb];
  uVar4 = param_1[0xc];
  uVar9 = *(uint *)(&DAT_001dac08 + (uVar12 >> 6 & 0xc));
  uVar6 = *(uint *)(&DAT_001dac08 + (uVar12 >> 4 & 0xc));
  uVar5 = *(uint *)(&DAT_001dac08 + (uVar12 >> 2 & 0xc));
  uVar10 = *(uint *)(&DAT_001dac08 + (uVar12 & 0xc));
  uVar12 = *(uint *)(*param_1 + 0x10);
  if (uVar4 < iVar2 + 5U) {
    if (uVar4 == 0) {
      uVar4 = 0x10;
    }
    else {
      uVar4 = uVar4 << 1;
    }
    for (; uVar4 < iVar2 + 5U; uVar4 = uVar4 << 1) {
    }
    if ((void *)*piVar14 == (void *)0x0) {
      pvVar3 = _malloc(uVar4 << 2);
    }
    else {
      pvVar3 = _realloc((void *)*piVar14,uVar4 << 2);
    }
    if (pvVar3 == (void *)0x0) {
      iVar2 = param_1[9];
      if (iVar2 == 0) {
        iVar2 = 1;
        param_1[9] = 1;
      }
      if (iVar2 != 0) {
        return iVar2;
      }
      puVar1 = (undefined4 *)0x0;
      pdVar7 = &MACH_HEADER.cputype;
      pdVar11 = &MACH_HEADER.cpusubtype;
      pdVar13 = &MACH_HEADER.filetype;
      pdVar8 = &MACH_HEADER.ncmds;
      goto LAB_0003fb50;
    }
    *piVar14 = (int)pvVar3;
    param_1[0xc] = uVar4;
    iVar2 = param_1[0xb];
  }
  param_1[0xb] = iVar2 + 5;
  puVar1 = (undefined4 *)(iVar2 * 4 + *piVar14);
  pdVar7 = puVar1 + 1;
  pdVar11 = puVar1 + 2;
  pdVar13 = puVar1 + 3;
  pdVar8 = puVar1 + 4;
LAB_0003fb50:
  *puVar1 = 0x47;
  *pdVar7 = local_38;
  *pdVar11 = local_34[0];
  *pdVar13 = uVar12 & 0xffff | 0x440000;
  *pdVar8 = uVar10 >> 9 & 0x8000 |
            uVar10 >> 0xd & 0x7000 |
            uVar5 >> 0xd & 0x800 |
            uVar5 >> 0x11 & 0x700 |
            uVar6 >> 0x11 & 0x80 | uVar6 >> 0x15 & 0x70 | uVar9 >> 0x15 & 8 | uVar9 >> 0x19 & 7;
  return 0;
}

/* FUN_0003fbf0 @ 0x3fbf0 (392 bytes) */
int FUN_0003fbf0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  
  if (*(int *)(param_1 + 0x24) != 0) {
    return *(int *)(param_1 + 0x24);
  }
  piVar9 = (int *)(param_1 + 0x28);
  iVar7 = *(int *)(param_1 + 0x2c);
  uVar2 = *(uint *)(param_1 + 0x30);
  iVar8 = (param_3 + param_4) * 2 + 1;
  uVar3 = iVar8 + iVar7;
  if (uVar2 < uVar3) {
    if (uVar2 == 0) {
      uVar2 = 0x10;
    }
    else {
      uVar2 = uVar2 << 1;
    }
    for (; uVar2 < uVar3; uVar2 = uVar2 << 1) {
    }
    if ((void *)*piVar9 == (void *)0x0) {
      pvVar4 = _malloc(uVar2 << 2);
    }
    else {
      pvVar4 = _realloc((void *)*piVar9,uVar2 << 2);
    }
    if (pvVar4 == (void *)0x0) {
      iVar7 = *(int *)(param_1 + 0x24);
      if (iVar7 == 0) {
        iVar7 = 1;
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      puVar5 = (undefined4 *)0x0;
      if (iVar7 != 0) {
        return iVar7;
      }
      goto LAB_0003fcc0;
    }
    *piVar9 = (int)pvVar4;
    *(uint *)(param_1 + 0x30) = uVar2;
    iVar7 = *(int *)(param_1 + 0x2c);
  }
  *(int *)(param_1 + 0x2c) = iVar8 + iVar7;
  puVar5 = (undefined4 *)(iVar7 * 4 + *piVar9);
LAB_0003fcc0:
  *puVar5 = *param_2;
  if (param_3 == 0) {
    iVar7 = 1;
  }
  else {
    iVar7 = 3;
    puVar5[1] = param_2[1];
    puVar5[2] = param_2[2];
  }
  if (0 < param_4) {
    puVar5 = puVar5 + iVar7;
    puVar6 = puVar5;
    do {
      *puVar6 = param_2[3];
      puVar6 = puVar6 + 2;
      puVar1 = param_2 + 6;
      param_2 = param_2 + 1;
      puVar5[1] = *puVar1;
      puVar5 = puVar5 + 2;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return 0;
}

/* FUN_00044c90 @ 0x44c90 (2856 bytes) */
int FUN_00044c90(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined **ppuVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined **ppuVar8;
  undefined **ppuVar9;
  undefined4 *puVar10;
  uint *puVar11;
  int iVar12;
  int *piVar13;
  undefined1 auStack_b8 [2];
  ushort local_b6;
  undefined1 auStack_b4 [4];
  undefined *local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined *local_94;
  undefined *local_90;
  undefined4 local_88[0];
  undefined4 local_84;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined *local_70 [3];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 auStack_54 [4];
  uint local_50;
  undefined *local_4c;
  undefined1 auStack_48 [4];
  undefined *local_44;
  
  iVar12 = *param_1;
  puVar6 = &local_a0;
  iVar3 = *(int *)(iVar12 + 0x54);
  _memset(&local_ac,0,0x24);
  iVar12 = iVar12 + iVar3 * 8 + param_2 * 8;
  _memset(&local_88,0,0x24);
  local_a8 = CONCAT22(4,(short)param_1[8]);
  local_ac = CONCAT22((*(unsigned short *)((unsigned char *)&(local_ac) + 0)),0x5b);
  local_a4 = 0x55;
  local_a8 = local_a8 | 0x400000;
  iVar3 = ((int (*)())FUN_0003f1c0)(param_1,iVar12 + 0x18,puVar6,&local_94);
  if (iVar3 == 0) {
    local_90 = ((unsigned char *)0x00005555);
    local_9c = 0x440000;
    if (param_1[9] != 0) {
      return param_1[9];
    }
    piVar13 = param_1 + 10;
    iVar3 = param_1[0xb];
    uVar4 = param_1[0xc];
    if (uVar4 < iVar3 + 7U) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = uVar4 << 1;
      }
      for (; uVar4 < iVar3 + 7U; uVar4 = uVar4 << 1) {
      }
      if ((void *)*piVar13 == (void *)0x0) {
        pvVar5 = _malloc(uVar4 << 2);
      }
      else {
        pvVar5 = _realloc((void *)*piVar13,uVar4 << 2);
      }
      if (pvVar5 == (void *)0x0) goto LAB_000457a8;
      *piVar13 = (int)pvVar5;
      param_1[0xc] = uVar4;
      iVar3 = param_1[0xb];
    }
    param_1[0xb] = iVar3 + 7;
    puVar10 = (undefined4 *)(iVar3 * 4 + *piVar13);
    *puVar10 = local_ac;
    puVar10[1] = local_a8;
    puVar10[2] = local_a4;
    puVar7 = puVar6;
    do {
      puVar10[3] = *puVar7;
      puVar1 = puVar7 + 3;
      puVar7 = puVar7 + 1;
      puVar10[4] = *puVar1;
      puVar10 = puVar10 + 2;
    } while (&uStack_98 != puVar7);
    local_88[0] = CONCAT22((*(unsigned short *)((unsigned char *)&(local_88[0]) + 0)),0xd);
    local_84 = CONCAT22(4,(short)param_1[8] + 1);
    local_7c = (undefined *)CONCAT22(4,(short)param_1[8]);
    local_88[0] = local_88[0] & 0xc000ffff | 0x20000;
    local_84 = local_84 | 0x400000;
    local_80 = 0x55;
    local_70[0] = ((unsigned char *)0x00003210);
    local_70[1] = ((unsigned char *)0x00004454);
    local_70[2] = ((unsigned char *)0x00004445);
    local_7c = (undefined *)((uint)local_7c | 0x400000);
    local_78 = 0x440000;
    local_74 = 0x440000;
    if (param_1[9] != 0) {
      return param_1[9];
    }
    iVar3 = param_1[0xb];
    uVar4 = param_1[0xc];
    if (uVar4 < iVar3 + 9U) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = uVar4 << 1;
      }
      for (; uVar4 < iVar3 + 9U; uVar4 = uVar4 << 1) {
      }
      if ((void *)*piVar13 == (void *)0x0) {
        pvVar5 = _malloc(uVar4 << 2);
      }
      else {
        pvVar5 = _realloc((void *)*piVar13,uVar4 << 2);
      }
      if (pvVar5 == (void *)0x0) goto LAB_000457a8;
      *piVar13 = (int)pvVar5;
      param_1[0xc] = uVar4;
      iVar3 = param_1[0xb];
    }
    ppuVar9 = (undefined **)&local_7c;
    param_1[0xb] = iVar3 + 9;
    puVar11 = (uint *)(iVar3 * 4 + *piVar13);
    *puVar11 = local_88[0];
    puVar11[1] = local_84;
    puVar11[2] = local_80;
    ppuVar8 = ppuVar9;
    do {
      puVar11[3] = (uint)*ppuVar8;
      ppuVar2 = ppuVar8 + 3;
      ppuVar8 = ppuVar8 + 1;
      puVar11[4] = (uint)*ppuVar2;
      puVar11 = puVar11 + 2;
    } while (local_70 != ppuVar8);
    if (1 < (*(uint *)(iVar12 + 4) >> 0x1a & 3)) {
      local_a0 = CONCAT22(4,(short)param_1[8]);
      local_94 = ((unsigned char *)0x00003210);
      local_a0 = local_a0 | 0x400000;
      if (param_1[9] != 0) {
        return param_1[9];
      }
      iVar3 = param_1[0xb];
      uVar4 = param_1[0xc];
      if (uVar4 < iVar3 + 7U) {
        if (uVar4 == 0) {
          uVar4 = 0x10;
        }
        else {
          uVar4 = uVar4 << 1;
        }
        for (; uVar4 < iVar3 + 7U; uVar4 = uVar4 << 1) {
        }
        if ((void *)*piVar13 == (void *)0x0) {
          pvVar5 = _malloc(uVar4 << 2);
        }
        else {
          pvVar5 = _realloc((void *)*piVar13,uVar4 << 2);
        }
        if (pvVar5 == (void *)0x0) goto LAB_000457a8;
        *piVar13 = (int)pvVar5;
        param_1[0xc] = uVar4;
        iVar3 = param_1[0xb];
      }
      param_1[0xb] = iVar3 + 7;
      puVar10 = (undefined4 *)(iVar3 * 4 + *piVar13);
      *puVar10 = local_ac;
      puVar10[1] = local_a8;
      puVar10[2] = local_a4;
      puVar7 = puVar6;
      do {
        puVar10[3] = *puVar7;
        puVar1 = puVar7 + 3;
        puVar7 = puVar7 + 1;
        puVar10[4] = *puVar1;
        puVar10 = puVar10 + 2;
      } while (&uStack_98 != puVar7);
      local_74 = CONCAT22(4,(short)param_1[8] + 1);
      local_70[1] = (undefined *)((uint)local_70[1] & 0xfffff88f | 0x540);
      local_70[2] = ((unsigned char *)0x00003210);
      local_74 = local_74 | 0x400000;
      if (param_1[9] != 0) {
        return param_1[9];
      }
      iVar3 = param_1[0xb];
      uVar4 = param_1[0xc];
      if (uVar4 < iVar3 + 9U) {
        if (uVar4 == 0) {
          uVar4 = 0x10;
        }
        else {
          uVar4 = uVar4 << 1;
        }
        for (; uVar4 < iVar3 + 9U; uVar4 = uVar4 << 1) {
        }
        if ((void *)*piVar13 == (void *)0x0) {
          pvVar5 = _malloc(uVar4 << 2);
        }
        else {
          pvVar5 = _realloc((void *)*piVar13,uVar4 << 2);
        }
        if (pvVar5 == (void *)0x0) goto LAB_000457a8;
        *piVar13 = (int)pvVar5;
        param_1[0xc] = uVar4;
        iVar3 = param_1[0xb];
      }
      param_1[0xb] = iVar3 + 9;
      puVar11 = (uint *)(iVar3 * 4 + *piVar13);
      *puVar11 = local_88[0];
      puVar11[1] = local_84;
      puVar11[2] = local_80;
      ppuVar8 = ppuVar9;
      do {
        puVar11[3] = (uint)*ppuVar8;
        ppuVar2 = ppuVar8 + 3;
        ppuVar8 = ppuVar8 + 1;
        puVar11[4] = (uint)*ppuVar2;
        puVar11 = puVar11 + 2;
      } while (local_70 != ppuVar8);
      if ((*(uint *)(iVar12 + 4) & 0xc000000) == 0xc000000) {
        if (param_1[9] != 0) {
          return param_1[9];
        }
        iVar3 = param_1[0xb];
        uVar4 = param_1[0xc];
        if (uVar4 < iVar3 + 7U) {
          if (uVar4 == 0) {
            uVar4 = 0x10;
          }
          else {
            uVar4 = uVar4 << 1;
          }
          for (; uVar4 < iVar3 + 7U; uVar4 = uVar4 << 1) {
          }
          if ((void *)*piVar13 == (void *)0x0) {
            pvVar5 = _malloc(uVar4 << 2);
          }
          else {
            pvVar5 = _realloc((void *)*piVar13,uVar4 << 2);
          }
          if (pvVar5 == (void *)0x0) goto LAB_000457a8;
          *piVar13 = (int)pvVar5;
          param_1[0xc] = uVar4;
          iVar3 = param_1[0xb];
        }
        param_1[0xb] = iVar3 + 7;
        puVar10 = (undefined4 *)(iVar3 * 4 + *piVar13);
        *puVar10 = local_ac;
        puVar10[1] = local_a8;
        puVar10[2] = local_a4;
        do {
          puVar10[3] = *puVar6;
          puVar7 = puVar6 + 3;
          puVar6 = puVar6 + 1;
          puVar10[4] = *puVar7;
          puVar10 = puVar10 + 2;
        } while (&uStack_98 != puVar6);
        local_70[1] = (undefined *)((uint)local_70[1] & 0xffff88ff | 0x5400);
        if (param_1[9] != 0) {
          return param_1[9];
        }
        iVar3 = param_1[0xb];
        uVar4 = param_1[0xc];
        if (uVar4 < iVar3 + 9U) {
          if (uVar4 == 0) {
            uVar4 = 0x10;
          }
          else {
            uVar4 = uVar4 << 1;
          }
          for (; uVar4 < iVar3 + 9U; uVar4 = uVar4 << 1) {
          }
          if ((void *)*piVar13 == (void *)0x0) {
            pvVar5 = _malloc(uVar4 << 2);
          }
          else {
            pvVar5 = _realloc((void *)*piVar13,uVar4 << 2);
          }
          if (pvVar5 == (void *)0x0) goto LAB_000457a8;
          *piVar13 = (int)pvVar5;
          param_1[0xc] = uVar4;
          iVar3 = param_1[0xb];
        }
        param_1[0xb] = iVar3 + 9;
        puVar11 = (uint *)(iVar3 * 4 + *piVar13);
        *puVar11 = local_88[0];
        puVar11[1] = local_84;
        puVar11[2] = local_80;
        do {
          puVar11[3] = (uint)*ppuVar9;
          ppuVar8 = ppuVar9 + 3;
          ppuVar9 = ppuVar9 + 1;
          puVar11[4] = (uint)*ppuVar8;
          puVar11 = puVar11 + 2;
        } while (local_70 != ppuVar9);
      }
    }
    _memset(&local_64,0,0x24);
    local_64 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_64) + 0)),0xd);
    local_88[0] = local_88[0] & 0xc000ffff | 0x30000;
    iVar3 = ((int (*)())FUN_0003f750)(param_1,iVar12 + 8,&local_60,&local_5c,*(uint *)(iVar12 + 4) >> 0x14 & 1);
    if (iVar3 == 0) {
      local_58 = (undefined *)CONCAT22(4,(short)param_1[8] + 1);
      local_4c = ((unsigned char *)0x00003210);
      local_58 = (undefined *)((uint)local_58 | 0x400000);
      iVar3 = ((int (*)())FUN_0003f1c0)(param_1,iVar12 + 0x10,auStack_54,auStack_48);
      if (iVar3 == 0) {
        iVar3 = ((int (*)())FUN_0003ed90)(param_1,iVar12 + 8,auStack_b8,auStack_b4,0);
        if (iVar3 == 0) {
          local_b0 = ((unsigned char *)0x00003210);
          uVar4 = *(uint *)(iVar12 + 8);
          if ((uVar4 & 0x2000) != 0) {
            ((int (*)())FUN_0003ee30)(0,uVar4 >> 8 & 3,&local_b0);
            uVar4 = *(uint *)(iVar12 + 8);
          }
          if ((uVar4 & 0x4000) != 0) {
            ((int (*)())FUN_0003ee30)(1,uVar4 >> 6 & 3,&local_b0);
            uVar4 = *(uint *)(iVar12 + 8);
          }
          if ((uVar4 & 0x8000) != 0) {
            ((int (*)())FUN_0003ee30)(2,uVar4 >> 4 & 3,&local_b0);
            uVar4 = *(uint *)(iVar12 + 8);
          }
          if ((uVar4 & 0x10000) != 0) {
            ((int (*)())FUN_0003ee30)(3,uVar4 >> 2 & 3,&local_b0);
          }
          iVar3 = param_1[9];
          local_50 = local_b6 | 0x440000;
          local_44 = local_b0;
        }
        else {
          iVar3 = param_1[9];
        }
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = param_1[0xb];
        uVar4 = param_1[0xc];
        if (uVar4 < iVar3 + 9U) {
          if (uVar4 == 0) {
            uVar4 = 0x10;
          }
          else {
            uVar4 = uVar4 << 1;
          }
          for (; uVar4 < iVar3 + 9U; uVar4 = uVar4 << 1) {
          }
          if ((void *)*piVar13 == (void *)0x0) {
            pvVar5 = _malloc(uVar4 << 2);
          }
          else {
            pvVar5 = _realloc((void *)*piVar13,uVar4 << 2);
          }
          if (pvVar5 == (void *)0x0) {
LAB_000457a8:
            if (param_1[9] != 0) {
              return param_1[9];
            }
            param_1[9] = 1;
            return 1;
          }
          *piVar13 = (int)pvVar5;
          param_1[0xc] = uVar4;
          iVar3 = param_1[0xb];
        }
        ppuVar8 = (undefined **)&local_58;
        param_1[0xb] = iVar3 + 9;
        puVar6 = (undefined4 *)(iVar3 * 4 + *piVar13);
        *puVar6 = local_64;
        puVar6[1] = local_60;
        puVar6[2] = local_5c;
        do {
          puVar6[3] = *ppuVar8;
          ppuVar9 = ppuVar8 + 3;
          ppuVar8 = ppuVar8 + 1;
          puVar6[4] = *ppuVar9;
          puVar6 = puVar6 + 2;
        } while (&local_4c != ppuVar8);
        return 0;
      }
    }
  }
  return param_1[9];
}

/* FUN_000457f0 @ 0x457f0 (2412 bytes) */
int FUN_000457f0(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined **ppuVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  short sVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined **ppuVar11;
  undefined **ppuVar12;
  uint *puVar13;
  undefined4 *puVar14;
  uint *puVar15;
  int *piVar16;
  int iVar17;
  uint local_98;
  uint local_94;
  undefined4 local_90;
  uint local_8c;
  undefined4 local_88[0];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined *local_70;
  undefined *local_6c;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined *local_4c;
  uint local_48;
  undefined *local_44;
  
  iVar17 = *param_1;
  iVar3 = *(int *)(iVar17 + 0x54);
  _memset(&local_88,0,0x24);
  iVar17 = iVar17 + iVar3 * 8 + param_2 * 8;
  _memset(&local_64,0,0x24);
  iVar3 = ((int (*)())FUN_0003f750)(param_1,iVar17 + 8,&local_98,&local_94,*(uint *)(iVar17 + 4) >> 0x14 & 1);
  if (iVar3 != 0) {
LAB_000458f0:
    return param_1[9];
  }
  puVar15 = (uint *)(iVar17 + 0x10);
  iVar3 = ((int (*)())FUN_0003f1c0)(param_1,puVar15,&local_90,&local_8c);
  if (iVar3 != 0) goto LAB_000458f0;
  puVar7 = &local_7c;
  local_84 = CONCAT22(4,(short)param_1[8]);
  local_88[0] = CONCAT22((*(unsigned short *)((unsigned char *)&(local_88[0]) + 0)),0x5b);
  local_80 = 0x55;
  local_84 = local_84 | 0x400000;
  iVar3 = ((int (*)())FUN_0003f1c0)(param_1,iVar17 + 0x18,puVar7,&local_70);
  if (iVar3 != 0) goto LAB_000458f0;
  local_6c = ((unsigned char *)0x00005555);
  local_78 = 0x440000;
  if (param_1[9] != 0) {
    return param_1[9];
  }
  piVar16 = param_1 + 10;
  iVar3 = param_1[0xb];
  uVar4 = param_1[0xc];
  if (uVar4 < iVar3 + 7U) {
    if (uVar4 == 0) {
      uVar4 = 0x10;
    }
    else {
      uVar4 = uVar4 << 1;
    }
    for (; uVar4 < iVar3 + 7U; uVar4 = uVar4 << 1) {
    }
    if ((void *)*piVar16 == (void *)0x0) {
      pvVar5 = _malloc(uVar4 << 2);
    }
    else {
      pvVar5 = _realloc((void *)*piVar16,uVar4 << 2);
    }
    if (pvVar5 == (void *)0x0) goto LAB_00046124;
    *piVar16 = (int)pvVar5;
    param_1[0xc] = uVar4;
    iVar3 = param_1[0xb];
  }
  param_1[0xb] = iVar3 + 7;
  puVar14 = (undefined4 *)(iVar3 * 4 + *piVar16);
  *puVar14 = local_88[0];
  puVar14[1] = local_84;
  puVar14[2] = local_80;
  puVar10 = puVar7;
  do {
    puVar14[3] = *puVar10;
    puVar1 = puVar10 + 3;
    puVar10 = puVar10 + 1;
    puVar14[4] = *puVar1;
    puVar14 = puVar14 + 2;
  } while (&uStack_74 != puVar10);
  local_64 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_64) + 0)),0xd);
  local_64 = local_64 & 0xc000ffff | 0x20000;
  if ((*puVar15 & 0x3000) == 0x1000) {
    sVar6 = (short)param_1[8];
    local_60 = local_98;
    local_5c = local_94;
  }
  else {
    sVar6 = (short)param_1[8];
    local_60 = CONCAT22(4,sVar6 + 1);
    local_5c = 0x55;
    local_60 = local_60 | 0x400000;
  }
  uVar9 = local_8c >> 4 & 7;
  uVar8 = local_8c >> 7 & 1;
  local_58 = (undefined *)CONCAT22(4,sVar6);
  uVar4 = local_8c >> 3 & 1;
  local_4c = ((unsigned char *)0x00003210);
  local_50 = local_90;
  local_44 = (undefined *)
             (uVar4 << 0xf |
             (local_8c & 7) << 0xc |
             uVar4 << 0xb |
             (local_8c & 7) << 8 | uVar4 << 7 | (local_8c & 7) << 4 | local_8c & 0xffff000f);
  local_54 = local_90;
  local_58 = (undefined *)((uint)local_58 | 0x400000);
  local_48 = uVar8 << 0xf |
             uVar9 << 0xc |
             uVar8 << 0xb |
             uVar9 << 8 | uVar8 << 7 | uVar9 << 4 | uVar8 << 3 | local_8c & 0xffff0000 | uVar9;
  if (param_1[9] != 0) {
    return param_1[9];
  }
  iVar3 = param_1[0xb];
  uVar4 = param_1[0xc];
  if (uVar4 < iVar3 + 9U) {
    if (uVar4 == 0) {
      uVar4 = 0x10;
    }
    else {
      uVar4 = uVar4 << 1;
    }
    for (; uVar4 < iVar3 + 9U; uVar4 = uVar4 << 1) {
    }
    if ((void *)*piVar16 == (void *)0x0) {
      pvVar5 = _malloc(uVar4 << 2);
    }
    else {
      pvVar5 = _realloc((void *)*piVar16,uVar4 << 2);
    }
    if (pvVar5 == (void *)0x0) goto LAB_00046124;
    *piVar16 = (int)pvVar5;
    param_1[0xc] = uVar4;
    iVar3 = param_1[0xb];
  }
  ppuVar12 = (undefined **)&local_58;
  param_1[0xb] = iVar3 + 9;
  puVar13 = (uint *)(iVar3 * 4 + *piVar16);
  *puVar13 = local_64;
  puVar13[1] = local_60;
  puVar13[2] = local_5c;
  ppuVar11 = ppuVar12;
  do {
    puVar13[3] = (uint)*ppuVar11;
    ppuVar2 = ppuVar11 + 3;
    ppuVar11 = ppuVar11 + 1;
    puVar13[4] = (uint)*ppuVar2;
    puVar13 = puVar13 + 2;
  } while (&local_4c != ppuVar11);
  if (1 < (*puVar15 >> 0xc & 3)) {
    local_7c = CONCAT22(4,(short)param_1[8]);
    local_70 = ((unsigned char *)0x00003210);
    local_7c = local_7c | 0x400000;
    if (param_1[9] != 0) {
      return param_1[9];
    }
    iVar3 = param_1[0xb];
    uVar4 = param_1[0xc];
    if (uVar4 < iVar3 + 7U) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = uVar4 << 1;
      }
      for (; uVar4 < iVar3 + 7U; uVar4 = uVar4 << 1) {
      }
      if ((void *)*piVar16 == (void *)0x0) {
        pvVar5 = _malloc(uVar4 << 2);
      }
      else {
        pvVar5 = _realloc((void *)*piVar16,uVar4 << 2);
      }
      if (pvVar5 == (void *)0x0) goto LAB_00046124;
      *piVar16 = (int)pvVar5;
      param_1[0xc] = uVar4;
      iVar3 = param_1[0xb];
    }
    param_1[0xb] = iVar3 + 7;
    puVar14 = (undefined4 *)(iVar3 * 4 + *piVar16);
    *puVar14 = local_88[0];
    puVar14[1] = local_84;
    puVar14[2] = local_80;
    puVar10 = puVar7;
    do {
      puVar14[3] = *puVar10;
      puVar1 = puVar10 + 3;
      puVar10 = puVar10 + 1;
      puVar14[4] = *puVar1;
      puVar14 = puVar14 + 2;
    } while (&uStack_74 != puVar10);
    if ((*puVar15 & 0x3000) == 0x2000) {
      local_60 = local_98;
      local_5c = local_94;
    }
    uVar4 = local_8c >> 8 & 7;
    uVar8 = local_8c >> 0xb & 1;
    local_50 = CONCAT22(4,(short)param_1[8] + 1);
    local_44 = ((unsigned char *)0x00003210);
    local_50 = local_50 | 0x400000;
    local_48 = uVar8 << 0xf |
               uVar4 << 0xc |
               uVar8 << 0xb |
               uVar4 << 8 | uVar8 << 7 | uVar4 << 4 | uVar8 << 3 | uVar4 | local_48 & 0xffff0000;
    if (param_1[9] != 0) {
      return param_1[9];
    }
    iVar3 = param_1[0xb];
    uVar4 = param_1[0xc];
    if (uVar4 < iVar3 + 9U) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = uVar4 << 1;
      }
      for (; uVar4 < iVar3 + 9U; uVar4 = uVar4 << 1) {
      }
      if ((void *)*piVar16 == (void *)0x0) {
        pvVar5 = _malloc(uVar4 << 2);
      }
      else {
        pvVar5 = _realloc((void *)*piVar16,uVar4 << 2);
      }
      if (pvVar5 == (void *)0x0) goto LAB_00046124;
      *piVar16 = (int)pvVar5;
      param_1[0xc] = uVar4;
      iVar3 = param_1[0xb];
    }
    param_1[0xb] = iVar3 + 9;
    puVar13 = (uint *)(iVar3 * 4 + *piVar16);
    *puVar13 = local_64;
    puVar13[1] = local_60;
    puVar13[2] = local_5c;
    ppuVar11 = ppuVar12;
    do {
      puVar13[3] = (uint)*ppuVar11;
      ppuVar2 = ppuVar11 + 3;
      ppuVar11 = ppuVar11 + 1;
      puVar13[4] = (uint)*ppuVar2;
      puVar13 = puVar13 + 2;
    } while (&local_4c != ppuVar11);
    if ((*puVar15 & 0x3000) != 0x3000) {
      return 0;
    }
    if (param_1[9] != 0) {
      return param_1[9];
    }
    iVar3 = param_1[0xb];
    uVar4 = param_1[0xc];
    if (uVar4 < iVar3 + 7U) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = uVar4 << 1;
      }
      for (; uVar4 < iVar3 + 7U; uVar4 = uVar4 << 1) {
      }
      if ((void *)*piVar16 == (void *)0x0) {
        pvVar5 = _malloc(uVar4 << 2);
      }
      else {
        pvVar5 = _realloc((void *)*piVar16,uVar4 << 2);
      }
      if (pvVar5 == (void *)0x0) goto LAB_00046124;
      *piVar16 = (int)pvVar5;
      param_1[0xc] = uVar4;
      iVar3 = param_1[0xb];
    }
    param_1[0xb] = iVar3 + 7;
    puVar14 = (undefined4 *)(iVar3 * 4 + *piVar16);
    *puVar14 = local_88[0];
    puVar14[1] = local_84;
    puVar14[2] = local_80;
    do {
      puVar14[3] = *puVar7;
      puVar10 = puVar7 + 3;
      puVar7 = puVar7 + 1;
      puVar14[4] = *puVar10;
      puVar14 = puVar14 + 2;
    } while (&uStack_74 != puVar7);
    uVar8 = local_8c >> 0xc & 7;
    uVar4 = local_8c >> 0xf & 1;
    local_60 = local_98;
    local_5c = local_94;
    local_48 = uVar4 << 0xf |
               uVar8 << 0xc |
               uVar4 << 0xb |
               uVar8 << 8 | uVar4 << 7 | uVar8 << 4 | uVar4 << 3 | uVar8 | local_48 & 0xffff0000;
    if (param_1[9] != 0) {
      return param_1[9];
    }
    iVar3 = param_1[0xb];
    uVar4 = param_1[0xc];
    if (uVar4 < iVar3 + 9U) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = uVar4 << 1;
      }
      for (; uVar4 < iVar3 + 9U; uVar4 = uVar4 << 1) {
      }
      if ((void *)*piVar16 == (void *)0x0) {
        pvVar5 = _malloc(uVar4 << 2);
      }
      else {
        pvVar5 = _realloc((void *)*piVar16,uVar4 << 2);
      }
      if (pvVar5 == (void *)0x0) {
LAB_00046124:
        if (param_1[9] == 0) {
          param_1[9] = 1;
          return 1;
        }
        return param_1[9];
      }
      *piVar16 = (int)pvVar5;
      param_1[0xc] = uVar4;
      iVar3 = param_1[0xb];
    }
    param_1[0xb] = iVar3 + 9;
    puVar15 = (uint *)(iVar3 * 4 + *piVar16);
    *puVar15 = local_64;
    puVar15[1] = local_60;
    puVar15[2] = local_5c;
    do {
      puVar15[3] = (uint)*ppuVar12;
      ppuVar11 = ppuVar12 + 3;
      ppuVar12 = ppuVar12 + 1;
      puVar15[4] = (uint)*ppuVar11;
      puVar15 = puVar15 + 2;
    } while (ppuVar12 != &local_4c);
  }
  return 0;
}

/* FUN_00046180 @ 0x46180 (1528 bytes) */
int FUN_00046180(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  undefined4 *puVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  int *piVar11;
  undefined4 local_58;
  uint local_54;
  uint local_50;
  undefined4 local_4c;
  uint local_48;
  undefined4 uStack_44;
  undefined *local_40;
  uint local_3c;
  
  bVar2 = param_3 == 0;
  iVar10 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
  _memset(&local_58,0,0x24);
  if (bVar2) {
    param_3 = (*(uint *)(param_2 * 8 + iVar10 + 4) >> 0x1a & 3) + 1;
  }
  if (param_3 < 3) {
    if (param_3 == 1) {
      (*(unsigned short *)((unsigned char *)&(local_58) + 2)) = 0x47;
    }
    else {
      (*(unsigned short *)((unsigned char *)&(local_58) + 2)) = 0x49;
    }
    iVar10 = iVar10 + param_2 * 8;
    iVar5 = ((int (*)())FUN_0003f750)(param_1,iVar10 + 8,&local_54,&local_50,1);
    if (iVar5 != 0) {
LAB_00046640:
      return param_1[9];
    }
    if (bVar2) {
      iVar10 = ((int (*)())FUN_0003f1c0)(param_1,iVar10 + 0x10,&local_4c,&local_40);
      if (iVar10 != 0) goto LAB_00046640;
    }
    else {
      local_4c = CONCAT22(4,(short)param_1[8]);
      local_40 = ((unsigned char *)0x00003210);
      local_4c = local_4c | 0x400000;
    }
    if (param_3 == 2) {
      local_48 = local_4c;
      local_3c = (uint)local_40 >> 4 & 8 | (uint)local_40 >> 4 & 7 | (uint)local_40 & 0xfffffff0;
    }
    if (param_1[9] != 0) {
      return param_1[9];
    }
    piVar11 = param_1 + 10;
    iVar10 = param_1[0xb];
    iVar5 = param_3 * 2 + 3;
    uVar3 = param_1[0xc];
    uVar4 = iVar5 + iVar10;
    if (uVar3 < uVar4) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < uVar4; uVar3 = uVar3 << 1) {
      }
      if ((void *)*piVar11 == (void *)0x0) {
        pvVar6 = _malloc(uVar3 << 2);
      }
      else {
        pvVar6 = _realloc((void *)*piVar11,uVar3 << 2);
      }
      if (pvVar6 == (void *)0x0) goto LAB_0004676c;
      *piVar11 = (int)pvVar6;
      param_1[0xc] = uVar3;
      iVar10 = param_1[0xb];
    }
    param_1[0xb] = iVar5 + iVar10;
    puVar7 = (undefined4 *)(iVar10 * 4 + *piVar11);
    *puVar7 = local_58;
    puVar7[1] = local_54;
    puVar7[2] = local_50;
    if (0 < param_3) {
      puVar8 = &local_4c;
      do {
        puVar7[3] = *puVar8;
        puVar9 = puVar8 + 3;
        puVar8 = puVar8 + 1;
        puVar7[4] = *puVar9;
        puVar7 = puVar7 + 2;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  else {
    local_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_58) + 0)),0x49);
    local_50 = local_50 & 0xffffff00 | 0x111;
    local_54 = CONCAT22((short)(local_54 >> 0x10),(short)param_1[8]) & 0xffc0ffff | 0x440000;
    if (bVar2) {
      iVar5 = ((int (*)())FUN_0003f1c0)(param_1,iVar10 + param_2 * 8 + 0x10,&local_4c,&local_40);
      if (iVar5 != 0) goto LAB_00046640;
    }
    else {
      local_4c = CONCAT22(4,(short)param_1[8]);
      local_40 = ((unsigned char *)0x00003210);
      local_4c = local_4c | 0x400000;
    }
    local_48 = local_4c;
    uVar3 = (uint)local_40 >> 4 & 7;
    uVar4 = (uint)local_40 >> 4 & 8;
    if (param_3 == 3) {
      local_3c = uVar4 | uVar3 | (uint)local_40 & 0xfffff0f0 | 0x500;
    }
    else {
      local_3c = ((uint)local_40 & 0xfffff8f0) >> 4 & 0x800 |
                 (uint)local_40 >> 4 & 0x700 | uVar4 | uVar3 | (uint)local_40 & 0xfffff0f0;
    }
    if (param_1[9] != 0) {
      return param_1[9];
    }
    piVar11 = param_1 + 10;
    iVar5 = param_1[0xb];
    uVar3 = param_1[0xc];
    if (uVar3 < iVar5 + 7U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar5 + 7U; uVar3 = uVar3 << 1) {
      }
      if ((void *)*piVar11 == (void *)0x0) {
        pvVar6 = _malloc(uVar3 << 2);
      }
      else {
        pvVar6 = _realloc((void *)*piVar11,uVar3 << 2);
      }
      if (pvVar6 == (void *)0x0) goto LAB_0004676c;
      *piVar11 = (int)pvVar6;
      param_1[0xc] = uVar3;
      iVar5 = param_1[0xb];
    }
    puVar9 = &local_4c;
    param_1[0xb] = iVar5 + 7;
    puVar7 = (undefined4 *)(iVar5 * 4 + *piVar11);
    *puVar7 = local_58;
    puVar7[1] = local_54;
    puVar7[2] = local_50;
    puVar8 = puVar9;
    do {
      puVar7[3] = *puVar8;
      puVar1 = puVar8 + 3;
      puVar8 = puVar8 + 1;
      puVar7[4] = *puVar1;
      puVar7 = puVar7 + 2;
    } while (&uStack_44 != puVar8);
    iVar10 = ((int (*)())FUN_0003f750)(param_1,iVar10 + param_2 * 8 + 8,&local_54,&local_50,1);
    if (iVar10 != 0) goto LAB_00046640;
    local_4c = CONCAT22(4,(short)param_1[8]);
    local_40 = (undefined *)0x0;
    local_3c = local_3c & 0xfffffff8 | 2;
    local_48 = local_4c | 0x400000;
    local_4c = local_4c | 0x400000;
    if (param_1[9] != 0) {
      return param_1[9];
    }
    iVar10 = param_1[0xb];
    uVar3 = param_1[0xc];
    if (uVar3 < iVar10 + 7U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar10 + 7U; uVar3 = uVar3 << 1) {
      }
      if ((void *)*piVar11 == (void *)0x0) {
        pvVar6 = _malloc(uVar3 << 2);
      }
      else {
        pvVar6 = _realloc((void *)*piVar11,uVar3 << 2);
      }
      if (pvVar6 == (void *)0x0) {
LAB_0004676c:
        if (param_1[9] != 0) {
          return param_1[9];
        }
        param_1[9] = 1;
        return 1;
      }
      *piVar11 = (int)pvVar6;
      param_1[0xc] = uVar3;
      iVar10 = param_1[0xb];
    }
    param_1[0xb] = iVar10 + 7;
    puVar7 = (undefined4 *)(iVar10 * 4 + *piVar11);
    *puVar7 = local_58;
    puVar7[1] = local_54;
    puVar7[2] = local_50;
    do {
      puVar7[3] = *puVar9;
      puVar8 = puVar9 + 3;
      puVar9 = puVar9 + 1;
      puVar7[4] = *puVar8;
      puVar7 = puVar7 + 2;
    } while (puVar9 != &uStack_44);
  }
  return 0;
}

/* FUN_000467a0 @ 0x467a0 (632 bytes) */
int FUN_000467a0(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  undefined2 uVar6;
  undefined4 *puVar5;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  undefined4 uStack_44;
  undefined *local_40;
  uint local_3c;
  
  iVar9 = *param_1;
  iVar2 = *(int *)(iVar9 + 0x54);
  _memset(&local_58,0,0x24);
  iVar9 = iVar9 + iVar2 * 8 + param_2 * 8;
  local_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_58) + 0)),0x23);
  iVar2 = ((int (*)())FUN_0003f750)(param_1,iVar9 + 8,&local_54,&local_50,1);
  if (iVar2 == 0) {
    if (param_3 == 0) {
      iVar2 = ((int (*)())FUN_0003f1c0)(param_1,iVar9 + 0x10,&local_4c,&local_40);
      if (iVar2 != 0) goto LAB_000468f0;
      uVar6 = (undefined2)param_1[8];
    }
    else {
      uVar6 = (undefined2)param_1[8];
      local_4c = CONCAT22(4,uVar6);
      local_40 = ((unsigned char *)0x00003210);
      local_4c = local_4c | 0x400000;
    }
    iVar2 = param_1[9];
    local_3c = local_3c & 0xffff0000 | 0x5555;
    local_48 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_48) + 0)),uVar6) & 0xffc0ffff | 0x440000;
    if (iVar2 == 0) {
      piVar8 = param_1 + 10;
      iVar2 = param_1[0xb];
      uVar3 = param_1[0xc];
      if (uVar3 < iVar2 + 7U) {
        if (uVar3 == 0) {
          uVar3 = 0x10;
        }
        else {
          uVar3 = uVar3 << 1;
        }
        for (; uVar3 < iVar2 + 7U; uVar3 = uVar3 << 1) {
        }
        if ((void *)*piVar8 == (void *)0x0) {
          pvVar4 = _malloc(uVar3 << 2);
        }
        else {
          pvVar4 = _realloc((void *)*piVar8,uVar3 << 2);
        }
        if (pvVar4 == (void *)0x0) {
          if (param_1[9] != 0) {
            return param_1[9];
          }
          param_1[9] = 1;
          return 1;
        }
        *piVar8 = (int)pvVar4;
        param_1[0xc] = uVar3;
        iVar2 = param_1[0xb];
      }
      puVar5 = &local_4c;
      param_1[0xb] = iVar2 + 7;
      puVar7 = (undefined4 *)(iVar2 * 4 + *piVar8);
      *puVar7 = local_58;
      puVar7[1] = local_54;
      puVar7[2] = local_50;
      do {
        puVar7[3] = *puVar5;
        puVar1 = puVar5 + 3;
        puVar5 = puVar5 + 1;
        puVar7[4] = *puVar1;
        puVar7 = puVar7 + 2;
      } while (&uStack_44 != puVar5);
      iVar2 = 0;
    }
  }
  else {
LAB_000468f0:
    iVar2 = param_1[9];
  }
  return iVar2;
}

/* FUN_00046a30 @ 0x46a30 (1080 bytes) */
int FUN_00046a30(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint *puVar1;
  void *pvVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  undefined4 local_5c;
  undefined1 auStack_58 [2];
  short local_56;
  uint uStack_54;
  uint local_50;
  undefined1 auStack_4c [32];
  
  iVar12 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
  _memset(&local_68,0,0x24);
  iVar13 = iVar12 + param_2 * 8;
  uVar10 = *(uint *)(iVar12 + param_2 * 8) >> 0x12 & 0xff;
  if ((param_1[5] & 0x20000000U) == 0) {
    uVar8 = 0;
    uVar6 = 0;
    uVar7 = 0;
    uVar11 = 3;
  }
  else {
    uVar8 = *(uint *)(iVar13 + 4) >> 0x1c & 1;
    uVar6 = *(uint *)(iVar13 + 0x10) >> 0xe & 1;
    uVar7 = *(uint *)(iVar13 + 0x18) >> 0xe & 1;
    uVar11 = *(uint *)(iVar13 + 4) >> 0x1a & 3;
  }
  iVar12 = uVar10 * 0x10;
  local_68 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_68) + 0)),(short)(*(uint *)(&DAT_001dac34 + iVar12) >> 1));
  local_68 = (*(uint *)(&DAT_001dac38 + iVar12) >> 0x13) << 0x10 | local_68 & 0xc000ffff;
  iVar12 = ((int (*)())FUN_0003f750)(param_1,iVar13 + 8,&local_64,&local_60,*(uint *)(iVar13 + 4) >> 0x14 & 1);
  if (iVar12 == 0) {
    iVar12 = ((int (*)())FUN_0003f1c0)(param_1,iVar13 + 0x10,&local_5c,&local_50);
    if ((iVar12 == 0) &&
       (iVar12 = ((int (*)())FUN_0003f1c0)(param_1,iVar13 + 0x18,auStack_58,auStack_4c), iVar12 == 0)) {
      if (uVar8 == 0) {
        iVar12 = 1;
      }
      else {
        iVar12 = uVar11 + 1;
        if (iVar12 == 0) {
LAB_00046cd4:
          if ((((param_1[5] & 0x20000000U) == 0) || (uVar10 != 0x3a)) ||
             (iVar12 = ((int (*)())FUN_0003ed50)(param_1,iVar13 + 8), iVar12 != 1)) {
            return 0;
          }
          local_68 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_68) + 0)),99);
          local_5c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_5c) + 0)),(*(unsigned short *)((unsigned char *)&(local_64) + 2)));
          local_50 = local_50 & 0xffff0000 | 0x3210;
          local_5c = (local_64 >> 0x10 & 0x3f) << 0x10 | local_5c & 0xffc0ffff;
          local_68 = local_68 & 0xc000ffff;
          if (param_1[9] != 0) {
            return param_1[9];
          }
          piVar14 = param_1 + 10;
          iVar12 = param_1[0xb];
          uVar10 = param_1[0xc];
          if (uVar10 < iVar12 + 5U) {
            if (uVar10 == 0) {
              uVar10 = 0x10;
            }
            else {
              uVar10 = uVar10 << 1;
            }
            for (; uVar10 < iVar12 + 5U; uVar10 = uVar10 << 1) {
            }
            if ((void *)*piVar14 == (void *)0x0) {
              pvVar2 = _malloc(uVar10 << 2);
            }
            else {
              pvVar2 = _realloc((void *)*piVar14,uVar10 << 2);
            }
            if (pvVar2 == (void *)0x0) {
LAB_00046e28:
              if (param_1[9] != 0) {
                return param_1[9];
              }
              param_1[9] = 1;
              return 1;
            }
            *piVar14 = (int)pvVar2;
            param_1[0xc] = uVar10;
            iVar12 = param_1[0xb];
          }
          param_1[0xb] = iVar12 + 5;
          puVar5 = (uint *)(iVar12 * 4 + *piVar14);
          *puVar5 = local_68;
          puVar5[1] = local_64;
          puVar5[2] = local_60;
          puVar5[3] = local_5c;
          puVar5[4] = local_50;
          return 0;
        }
      }
      if (param_1[9] != 0) {
        return param_1[9];
      }
      iVar9 = 0;
      piVar14 = param_1 + 10;
      do {
        iVar3 = param_1[0xb];
        uVar11 = param_1[0xc];
        if (uVar11 < iVar3 + 7U) {
          if (uVar11 == 0) {
            uVar11 = 0x10;
          }
          else {
            uVar11 = uVar11 << 1;
          }
          for (; uVar11 < iVar3 + 7U; uVar11 = uVar11 << 1) {
          }
          if ((void *)*piVar14 == (void *)0x0) {
            pvVar2 = _malloc(uVar11 << 2);
          }
          else {
            pvVar2 = _realloc((void *)*piVar14,uVar11 << 2);
          }
          if (pvVar2 == (void *)0x0) goto LAB_00046e28;
          *piVar14 = (int)pvVar2;
          param_1[0xc] = uVar11;
          iVar3 = param_1[0xb];
        }
        param_1[0xb] = iVar3 + 7;
        puVar5 = (uint *)(iVar3 * 4 + *piVar14);
        *puVar5 = local_68;
        puVar5[1] = local_64;
        puVar5[2] = local_60;
        puVar4 = &local_5c;
        do {
          puVar5[3] = *puVar4;
          puVar1 = puVar4 + 3;
          puVar4 = puVar4 + 1;
          puVar5[4] = *puVar1;
          puVar5 = puVar5 + 2;
        } while (puVar4 != &uStack_54);
        if (uVar8 != 0) {
          local_64 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_64) + 0)),(*(unsigned short *)((unsigned char *)&(local_64) + 2)) + 1);
        }
        if (uVar6 != 0) {
          local_5c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_5c) + 0)),(*(unsigned short *)((unsigned char *)&(local_5c) + 2)) + 1);
        }
        if (uVar7 != 0) {
          local_56 = local_56 + 1;
        }
        iVar9 = iVar9 + 1;
        if (iVar12 == iVar9) goto LAB_00046cd4;
        if (param_1[9] != 0) {
          return param_1[9];
        }
      } while( true );
    }
  }
  return param_1[9];
}

/* FUN_00046e90 @ 0x46e90 (7800 bytes) */
int FUN_00046e90(param_1)
  int *param_1;
{
  bool bVar1;
  bool bVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined2 uVar10;
  uint uVar11;
  undefined *puVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint *puVar19;
  uint *puVar20;
  uint *puVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  undefined4 *puVar25;
  uint *puVar26;
  uint local_108;
  uint local_104[0];
  uint local_100;
  uint local_fc;
  uint local_f8;
  uint local_f4;
  uint *local_f0;
  undefined4 local_ec;
  uint local_e8;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  uint local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined *local_bc;
  undefined *local_b8 [2];
  undefined4 local_b0;
  undefined4 local_ac;
  uint local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined *local_98;
  undefined *local_94;
  undefined *local_90;
  int local_88[0];
  int local_84;
  int local_80;
  uint local_7c;
  uint local_78;
  uint *local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  undefined4 *local_60;
  undefined4 *local_5c;
  
  iVar5 = *param_1;
  iVar16 = *(int *)(iVar5 + 0x50);
  iVar8 = *(int *)(iVar5 + 0x54) * 8;
  puVar20 = (uint *)(iVar5 + iVar8);
  if (iVar16 < 1) {
LAB_00048d20:
    iVar8 = 0;
  }
  else {
    uVar22 = *(uint *)(iVar5 + iVar8) >> 0x12 & 0xff;
    iVar8 = uVar22 * 0x10;
    uVar13 = *(uint *)(&DAT_001dac34 + iVar8) >> 0x11 & 0xf;
    if ((uVar13 != 0) && ((*(uint *)(&DAT_001dac40 + iVar8) >> 0x1c & DAT_001db344) == 0)) {
      iVar17 = 0;
      iVar18 = 0;
      iVar5 = 0;
      puVar19 = puVar20;
      do {
        uVar11 = *puVar19 >> 0x1d;
        iVar15 = uVar11 + 2;
        if (uVar13 == 2) {
          iVar6 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
          uVar13 = *(uint *)(iVar5 + iVar6) >> 0x12 & 0xff;
          if ((uVar13 - 0x44 < 2) || (iVar23 = 0, uVar13 == 0x47)) {
            iVar23 = 1;
          }
          if (((uVar13 == 0x43) || (uVar13 == 0x45)) || (bVar1 = false, uVar13 == 0x47)) {
            bVar1 = true;
          }
          local_5c = &local_b0;
          iVar24 = iVar6 + iVar5;
          _memset(local_5c,0,0x24);
          local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),(short)(*(uint *)(&DAT_001dac34 + uVar13 * 0x10) >> 1))
          ;
          ((int (*)())FUN_0003f750)(param_1,iVar24 + 8,&local_ac,&local_a8,
                       *(uint *)(iVar5 + iVar6 + 4) >> 0x14 & 1);
          ((int (*)())FUN_0003f1c0)(param_1,iVar24 + 0x10,&local_a4,&local_98);
          if ((param_1[5] & 0x20000000U) == 0) {
            local_b0 = (*(uint *)(iVar24 + 0x18) & 0x1f) << 0x10 | local_b0 & 0xc000ffff;
            uVar13 = *(uint *)(iVar24 + 0x18) >> 5 & 7;
            if (iVar23 != 0) {
              local_a0 = local_a4;
              local_94 = local_98;
            }
          }
          else {
            local_f0 = (uint *)0x0;
            iVar6 = ((int (*)())FUN_0003f050)(param_1,iVar18,&local_f0);
            if (iVar6 != 0) goto LAB_00048a2c;
            local_b0 = ((uint)local_f0 & 0x3fff) << 0x10 | local_b0 & 0xc000ffff;
            uVar13 = *(uint *)(iVar24 + 0x20) >> 5 & 7;
            if (iVar23 != 0) {
              ((int (*)())FUN_0003f1c0)(param_1,iVar24 + 0x28,&local_a0,&local_94);
              uVar11 = (uint)local_94 >> 3 & 1;
              local_94 = (undefined *)
                         (uVar11 << 0xf |
                         ((uint)local_94 & 7) << 0xc |
                         uVar11 << 0xb |
                         ((uint)local_94 & 7) << 8 |
                         uVar11 << 7 | ((uint)local_94 & 7) << 4 | (uint)local_94 & 0xffff000f);
            }
          }
          if (uVar13 - 5 < 3) {
            local_b0 = local_b0 & 0xf3ffffff | 0x4000000;
          }
          puVar12 = local_98;
          if ((bVar1) &&
             (puVar12 = (undefined *)((uint)local_98 & 0xff1fffff | 0x600000),
             ((uint)local_98 & 0x8000) != 0)) {
            puVar12 = (undefined *)
                      (((uint)local_98 & 0xff1ff777 ^ 0x8000) & 0x8000 |
                      ((uint)local_98 & 0xff1fff77 ^ 0x800) & 0x800 |
                      ((uint)local_98 & 0xff1ffff7 ^ 0x80) & 0x80 |
                      ((uint)puVar12 ^ 8) & 8 | (uint)local_98 & 0xff1f7777 | 0x600000);
          }
          local_98 = puVar12;
          ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,iVar23 + 1);
LAB_00048c70:
          if (uVar22 != 0x4d) {
LAB_00048c78:
            if ((((*(uint *)(&DAT_001dac34 + iVar8) >> 0x11 & 0xf) != 3) &&
                ((param_1[5] & 0x20000000U) != 0)) &&
               (((((uVar13 = *(uint *)((int)puVar20 + iVar5 + 8), (uVar13 & 0x2000) != 0 &&
                   ((uVar13 & 0x300) != 0)) ||
                  (((uVar13 & 0x4000) != 0 && ((uVar13 & 0xc0) != 0x40)))) ||
                 (((uVar13 & 0x8000) != 0 && ((uVar13 & 0x30) != 0x20)))) ||
                (((uVar13 & 0x10000) != 0 && ((uVar13 & 0xc) != 0xc)))))) {
              ((int (*)())FUN_0003f9f0)(param_1,(int)puVar20 + iVar5 + 8,puVar19[1] >> 0x14 & 1);
            }
          }
        }
        else {
          if (uVar13 != 7) {
            if (uVar13 == 5) {
              local_60 = &local_d4;
              _memset(local_60,0,0x24);
              local_d4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_d4) + 0)),(short)(*(uint *)(&DAT_001dac34 + iVar8) >> 1));
              local_d4 = (*(uint *)(&DAT_001dac38 + iVar8) >> 0x13) << 0x10 | local_d4 & 0xc000ffff;
              if ((*(uint *)(&DAT_001dac40 + iVar8) >> 0x1c & 2) == 0) {
                if (((puVar19[1] & 0x100000) != 0) ||
                   (uVar9 = 0, (*(uint *)(&DAT_001dac40 + iVar8) >> 0x1c & 1) != 0)) {
                  uVar9 = 1;
                }
                ((int (*)())FUN_0003f750)(param_1,(int)puVar20 + iVar5 + 8,&local_d0,&local_cc,uVar9);
              }
              if (uVar11 != 0) {
                uVar13 = 0;
                puVar25 = &local_c8;
                puVar21 = puVar20 + iVar18 * 2 + 4;
                do {
                  uVar13 = uVar13 + 1;
                  ((int (*)())FUN_0003f1c0)(param_1,puVar21,puVar25,puVar25 + 3);
                  puVar25 = puVar25 + 1;
                  puVar21 = puVar21 + 2;
                } while (uVar11 != uVar13);
              }
              (**(code **)(&DAT_001dac3c + iVar8))(param_1,iVar18,local_60);
LAB_00048a2c:
              if (param_1[9] != 0) {
                return param_1[9];
              }
            }
            else {
              uVar7 = *(uint *)(&DAT_001dac34 + iVar8);
              uVar4 = *(uint *)(&DAT_001dac38 + iVar8);
              if (uVar13 == 4) {
                uVar11 = uVar11 - 1;
              }
              iVar6 = uVar11 * 2 + 1;
              if (uVar13 != 3) {
                iVar6 = uVar11 * 2 + 3;
              }
              iVar6 = ((int (*)())FUN_0003ef50)(param_1,iVar6,&local_f0);
              if (iVar6 != 0) goto LAB_00048d74;
              *local_f0 = (uVar4 >> 0x13) << 0x10 | uVar7 >> 1 & 0xffff;
              if ((*(uint *)(&DAT_001dac34 + iVar8) >> 0x11 & 0xf) != 3) {
                if (((puVar19[1] & 0x100000) != 0) ||
                   (uVar9 = 0, (*(uint *)(&DAT_001dac40 + iVar8) & 0x10000000) != 0)) {
                  uVar9 = 1;
                }
                iVar6 = ((int (*)())FUN_0003f750)(param_1,(int)puVar20 + iVar5 + 8,&local_108,&local_104,uVar9);
                if (iVar6 != 0) goto LAB_00048d74;
                local_f0[1] = local_108;
                local_f0[2] = local_104[0];
              }
              if ((*(uint *)(&DAT_001dac34 + iVar8) >> 0x11 & 0xf) == 4) {
                iVar6 = ((int (*)())FUN_0003f4e0)(param_1,(int)puVar20 + iVar5 + 0x10,&local_100,&local_fc,
                                     (int)puVar20 + iVar5 + 0x18);
              }
              else {
                iVar6 = ((int (*)())FUN_0003f1c0)(param_1,(int)puVar20 + iVar5 + 0x10,&local_100,&local_fc);
              }
              if (iVar6 != 0) goto LAB_00048d74;
              uVar13 = *(uint *)(&DAT_001dac34 + iVar8) >> 0x11 & 0xf;
              if (uVar13 == 6) {
                local_fc = local_fc & 0xffff0fff | 0x5000;
              }
              if (uVar13 == 3) {
                local_f0[1] = local_100;
                local_f0[2] = local_fc;
              }
              else {
                local_f0[3] = local_100;
                local_f0[4] = local_fc;
              }
              if (1 < (int)uVar11) {
                iVar6 = ((int (*)())FUN_0003f1c0)(param_1,(int)puVar20 + iVar5 + 0x18,&local_100,&local_fc);
                if (iVar6 != 0) goto LAB_00048d74;
                local_f0[5] = local_100;
                local_f0[6] = local_fc;
                if (2 < (int)uVar11) {
                  iVar6 = ((int (*)())FUN_0003f1c0)(param_1,(int)puVar20 + iVar5 + 0x20,&local_100,&local_fc);
                  if (iVar6 != 0) goto LAB_00048d74;
                  local_f0[7] = local_100;
                  local_f0[8] = local_fc;
                }
              }
            }
            goto LAB_00048c70;
          }
          if (uVar22 == 0) {
            local_5c = &local_b0;
            iVar24 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
            _memset(local_5c,0,0x24);
            iVar23 = iVar5 + iVar24;
            iVar24 = iVar24 + iVar5;
            local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x47);
            iVar6 = ((int (*)())FUN_0003f750)(param_1,iVar24 + 8,&local_ac,&local_a8,
                                 *(uint *)(iVar23 + 4) >> 0x14 & 1);
            if ((iVar6 == 0) &&
               (iVar6 = ((int (*)())FUN_0003f1c0)(param_1,iVar24 + 0x10,&local_a4,&local_98), iVar6 == 0)) {
              if (((param_1[5] & 0x20000000U) == 0) ||
                 (uVar13 = *(uint *)(iVar23 + 4), (uVar13 & 0x10000000) == 0)) {
                iVar6 = 1;
              }
              else {
                iVar6 = (uVar13 >> 0x1a & 3) + 1;
                if (iVar6 == 0) goto LAB_00048c78;
              }
              iVar23 = 0;
              do {
                iVar24 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,1);
                if (iVar24 != 0) goto LAB_00048418;
                iVar23 = iVar23 + 1;
                local_ac = CONCAT22((*(unsigned short *)((unsigned char *)&(local_ac) + 0)),(*(unsigned short *)((unsigned char *)&(local_ac) + 2)) + 1);
                local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
              } while (iVar6 != iVar23);
              goto LAB_00048c78;
            }
LAB_00048418:
            if (param_1[9] != 0) {
              return param_1[9];
            }
            goto LAB_00048c78;
          }
          if (uVar22 == 0x40) {
            iVar23 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
            iVar6 = ((int (*)())FUN_0003f750)(param_1,iVar23 + iVar5 + 8,&local_f8,&local_f4,
                                 *(uint *)(iVar5 + iVar23 + 4) >> 0x14 & 1);
            if (iVar6 == 0) {
              local_5c = &local_b0;
              iVar6 = 0;
              iVar23 = iVar18 * 8 + iVar23 + 0x10;
              do {
                iVar24 = ((int (*)())FUN_0003f1c0)(param_1,iVar23,iVar6 + (int)local_5c,(int)&local_e0 + iVar6);
                if (iVar24 != 0) goto LAB_00048418;
                bVar1 = iVar6 != 8;
                iVar23 = iVar23 + 8;
                iVar6 = iVar6 + 4;
              } while (bVar1);
              iVar6 = param_1[8];
              iVar24 = 0;
              iVar23 = 0;
              local_60 = &local_d4;
              puVar21 = &local_108;
              do {
                sVar3 = (short)iVar6 + (short)iVar24;
                bVar1 = iVar24 != 2;
                iVar24 = iVar24 + 1;
                *(undefined4 *)(iVar23 + (int)local_60) = 0;
                puVar21[0xd] = puVar21[0xd] & 0xffc0ffff | 0x40000;
                *(short *)((int)puVar21 + 0x36) = sVar3;
                *(undefined4 *)((int)&local_ec + iVar23) = 0;
                iVar23 = iVar23 + 4;
                puVar21[7] = puVar21[7] & 0xffc0ffff | 0x40000;
                *(short *)((int)puVar21 + 0x1e) = sVar3;
                puVar21[7] = puVar21[7] | 0x400000;
                puVar21 = puVar21 + 1;
              } while (bVar1);
              iVar6 = ((int (*)())FUN_0003ef50)(param_1,7,&local_f0);
              uVar13 = local_ec;
              if (iVar6 == 0) {
                *local_f0 = 0x5b;
                local_f0[1] = local_ec;
                local_f0[2] = local_f4;
                local_f0[3] = local_a8;
                local_f0[4] = local_d8;
                local_f0[5] = local_b0;
                local_f0[6] = local_e0;
                iVar6 = ((int (*)())FUN_0003ef50)(param_1,7,&local_f0);
                if (iVar6 == 0) {
                  *local_f0 = 0x5b;
                  local_6c = local_e8;
                  local_f0[1] = local_e8;
                  local_f0[2] = local_f4;
                  local_f0[3] = local_ac;
                  local_f0[4] = local_dc;
                  local_f0[5] = local_b0;
                  local_f0[6] = local_e0;
                  local_f4 = local_f4 | 0x100;
                  iVar6 = ((int (*)())FUN_0003ef50)(param_1,5,&local_f0);
                  uVar22 = local_d4;
                  if (iVar6 == 0) {
                    *local_f0 = 0x20;
                    local_f0[1] = uVar13;
                    local_f0[2] = local_f4;
                    local_f0[3] = local_d4;
                    local_70 = local_d0;
                    local_f0[4] = local_d0;
                    local_f4 = local_f4 & 0xfffffeff;
                    iVar6 = ((int (*)())FUN_0003ef50)(param_1,5,&local_f0);
                    if (iVar6 == 0) {
                      *local_f0 = 3;
                      local_f0[1] = local_6c;
                      local_f0[2] = local_f4;
                      local_f0[3] = uVar22;
                      local_f0[4] = uVar22;
                      iVar6 = ((int (*)())FUN_0003ef50)(param_1,5,&local_f0);
                      if (iVar6 == 0) {
                        *local_f0 = 0x49;
                        local_f0[1] = uVar13;
                        local_f0[2] = local_f4;
                        local_f0[3] = uVar22;
                        local_f0[4] = uVar22;
                        iVar6 = ((int (*)())FUN_0003ef50)(param_1,5,&local_f0);
                        uVar13 = local_d4;
                        if (iVar6 == 0) {
                          *local_f0 = 0x49;
                          local_f0[1] = local_6c;
                          local_f0[2] = local_f4;
                          local_f0[3] = uVar22;
                          local_f0[4] = local_70;
                          iVar6 = ((int (*)())FUN_0003ef50)(param_1,7,&local_f0);
                          if (iVar6 == 0) {
                            *local_f0 = 0x23;
                            local_f0[1] = local_e4;
                            local_f0[2] = local_f4;
                            local_f0[3] = uVar13 | 0x400000;
                            local_f0[4] = (uint)((unsigned char *)0x00004555);
                            local_f0[5] = uVar13 | 0x400000;
                            local_f0[6] = (uint)((unsigned char *)0x00004555);
                            local_d0 = local_d0 | 0x400000;
                            iVar6 = ((int (*)())FUN_0003ef50)(param_1,7,&local_f0);
                            if (iVar6 == 0) {
                              *local_f0 = 0x40;
                              local_f0[1] = local_f8;
                              local_f0[2] = local_f4;
                              local_f0[3] = local_d4;
                              local_f0[4] = local_cc;
                              local_f0[5] = local_d0;
                              local_f0[6] = 0xba98;
                              goto LAB_00048c78;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            goto LAB_00048418;
          }
          if (uVar22 == 0x22) {
            iVar23 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
            iVar24 = iVar23 + iVar5;
            puVar21 = (uint *)(iVar24 + 0x10);
            iVar6 = (*(uint *)(iVar24 + 0x10) >> 0xe & 1) + (*(uint *)(iVar24 + 0x18) >> 0xe & 1);
            if ((iVar6 == 1) &&
               (((*(uint *)(iVar24 + 0x10) & 0x3000) == 0 ||
                ((*(uint *)(iVar24 + 0x18) & 0x3000) == 0)))) {
              iVar6 = ((int (*)())FUN_00046a30)(param_1,iVar18);
              goto joined_r0x00048448;
            }
            local_60 = &local_d4;
            _memset(local_60,0,0x24);
            local_d4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_d4) + 0)),0x49);
            iVar23 = ((int (*)())FUN_0003f750)(param_1,iVar24 + 8,&local_d0,&local_cc,
                                  *(uint *)(iVar5 + iVar23 + 4) >> 0x14 & 1);
            if (((iVar23 != 0) ||
                (iVar23 = ((int (*)())FUN_0003f1c0)(param_1,puVar21,&local_c8,&local_bc), iVar23 != 0)) ||
               (iVar23 = ((int (*)())FUN_0003f1c0)(param_1,(uint *)(iVar24 + 0x18),&local_c4,local_b8[0]),
               uVar22 = local_cc, uVar13 = local_d0, iVar23 != 0)) {
LAB_000479ec:
              iVar6 = param_1[9];
              goto joined_r0x00048448;
            }
            if (iVar6 == 0) {
              iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_60,1,2);
joined_r0x000479e8:
              if (iVar6 != 0) goto LAB_000479ec;
            }
            else if (iVar6 != 1) {
              uVar10 = (undefined2)param_1[8];
              local_d0 = CONCAT22(4,uVar10);
              local_68 = uVar13;
              iVar23 = (*puVar21 >> 0xc & 3) + 1;
              iVar6 = iVar23 + param_1[8];
              local_64 = local_cc;
              param_1[8] = iVar6;
              local_cc = 0x55;
              local_d0 = local_d0 | 0x400000;
              if (iVar23 != 0) {
                local_5c = &local_b0;
                iVar6 = 0;
                do {
                  uVar22 = *puVar21 >> 0xc & 3;
                  _memcpy(local_5c,local_60,0x24);
                  iVar14 = param_1[8];
                  uVar13 = (uint)local_b8[0] >> 3 & 1;
                  local_ac = CONCAT22(4,(short)iVar14);
                  local_a8 = 0x55;
                  local_94 = (undefined *)
                             (uVar13 << 0xf |
                             ((uint)local_b8[0] & 7) << 0xc |
                             uVar13 << 0xb |
                             ((uint)local_b8[0] & 7) << 8 |
                             uVar13 << 7 |
                             ((uint)local_b8[0] & 7) << 4 |
                             uVar13 << 3 | (uint)local_b8[0] & 7 | (uint)local_94 & 0xffff0000);
                  local_ac = local_ac | 0x400000;
                  iVar24 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,2);
                  if (iVar24 == 0) {
                    local_9c = CONCAT22(4,(short)iVar14);
                    local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
                    local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x40);
                    local_90 = ((unsigned char *)0x00003210);
                    local_9c = local_9c | 0x400000;
                    if (uVar22 == 1) {
                      local_ac = local_d0;
                      local_a8 = local_cc;
                    }
                    uVar11 = (uint)local_b8[0] >> 4 & 7;
                    uVar13 = (uint)local_b8[0] >> 7 & 1;
                    local_94 = (undefined *)
                               (uVar13 << 0xf |
                               uVar11 << 0xc |
                               uVar13 << 0xb |
                               uVar11 << 8 |
                               uVar13 << 7 |
                               uVar11 << 4 | uVar13 << 3 | uVar11 | (uint)local_94 & 0xffff0000);
                    iVar24 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,3);
                    if ((iVar24 == 0) && (1 < uVar22)) {
                      local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
                      if (uVar22 == 2) {
                        local_ac = local_d0;
                        local_a8 = local_cc;
                      }
                      uVar11 = (uint)local_b8[0] >> 8 & 7;
                      uVar13 = (uint)local_b8[0] >> 0xb & 1;
                      local_94 = (undefined *)
                                 (uVar13 << 0xf |
                                 uVar11 << 0xc |
                                 uVar13 << 0xb |
                                 uVar11 << 8 |
                                 uVar13 << 7 |
                                 uVar11 << 4 | uVar13 << 3 | uVar11 | (uint)local_94 & 0xffff0000);
                      iVar24 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,3);
                      if ((iVar24 == 0) && (uVar22 == 3)) {
                        uVar22 = (uint)local_b8[0] >> 0xc & 7;
                        uVar13 = (uint)local_b8[0] >> 0xf & 1;
                        local_ac = local_d0;
                        local_a8 = local_cc;
                        local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
                        local_94 = (undefined *)
                                   (uVar13 << 0xf |
                                   uVar22 << 0xc |
                                   uVar13 << 0xb |
                                   uVar22 << 8 |
                                   uVar13 << 7 |
                                   uVar22 << 4 | uVar13 << 3 | uVar22 | (uint)local_94 & 0xffff0000)
                        ;
                        ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,3);
                      }
                    }
                  }
                  iVar6 = iVar6 + 1;
                  local_d0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_d0) + 0)),(*(unsigned short *)((unsigned char *)&(local_d0) + 2)) + 1);
                  local_c4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_c4) + 0)),(*(unsigned short *)((unsigned char *)&(local_c4) + 2)) + 1);
                } while (iVar23 != iVar6);
                iVar6 = param_1[8];
              }
              local_c8 = CONCAT22(4,uVar10);
              param_1[8] = iVar6 - iVar23;
              local_d4 = 0x47;
              local_bc = ((unsigned char *)0x00003210);
              local_d0 = local_68;
              local_cc = local_64;
              local_c8 = local_c8 | 0x400000;
              if (iVar23 != 0) {
                iVar6 = 0;
                do {
                  iVar6 = iVar6 + 1;
                  ((int (*)())FUN_0003fbf0)(param_1,local_60,1,1);
                  local_d0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_d0) + 0)),(short)local_d0 + 1);
                  local_c8 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_c8) + 0)),(*(unsigned short *)((unsigned char *)&(local_c8) + 2)) + 1);
                } while (iVar23 != iVar6);
              }
            }
            else {
              if ((*puVar21 & 0x4000) == 0) {
                uVar11 = local_cc & 3;
                local_d0 = CONCAT22(4,(short)param_1[8]);
                local_cc = 0;
                local_d4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_d4) + 0)),0x23);
                local_d0 = local_d0 | 0x400000;
                do {
                  iVar6 = 0;
                  bVar1 = uVar11 == 1;
                  while( true ) {
                    if (bVar1) {
                      uVar4 = local_cc & 0xffffff00;
                      if (iVar6 == 0) {
                        local_cc = uVar4 | 1;
                      }
                      else if (iVar6 == 1) {
                        local_cc = uVar4 | 4;
                      }
                      else if (iVar6 == 2) {
                        local_cc = uVar4 | 0x10;
                      }
                      else {
                        local_cc = local_cc & 0xffffff00 | 0x40;
                      }
                      iVar23 = ((int (*)())FUN_0003fbf0)(param_1,local_60,1,2);
                      if (iVar23 != 0) goto LAB_000479ec;
                    }
                    iVar6 = iVar6 + 1;
                    local_c4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_c4) + 0)),(*(unsigned short *)((unsigned char *)&(local_c4) + 2)) + 1);
                    if ((int)(*(uint *)(iVar24 + 0x18) >> 0xc & 3) < iVar6) {
                      local_c8 = CONCAT22(4,(short)param_1[8]);
                      local_d4 = 0x47;
                      local_bc = ((unsigned char *)0x00003210);
                      local_c8 = local_c8 | 0x400000;
                      local_d0 = uVar13;
                      local_cc = uVar22;
                      iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_60,1,1);
                      goto joined_r0x000479e8;
                    }
                    if (iVar6 == 0) break;
                    if (iVar6 == 1) {
                      bVar1 = (uVar22 & 0xc) == 4;
                    }
                    else if (iVar6 == 2) {
                      bVar1 = (uVar22 & 0x30) == 0x10;
                    }
                    else {
                      bVar1 = (uVar22 & 0xc0) == 0x40;
                    }
                  }
                } while( true );
              }
              local_5c = &local_b0;
              uVar22 = *puVar21 >> 0xc & 3;
              _memcpy(local_5c,local_60,0x24);
              iVar6 = param_1[8];
              uVar13 = (uint)local_b8[0] >> 3 & 1;
              local_ac = CONCAT22(4,(short)iVar6);
              local_a8 = 0x55;
              local_94 = (undefined *)
                         (uVar13 << 0xf |
                         ((uint)local_b8[0] & 7) << 0xc |
                         uVar13 << 0xb |
                         ((uint)local_b8[0] & 7) << 8 |
                         uVar13 << 7 |
                         ((uint)local_b8[0] & 7) << 4 |
                         uVar13 << 3 | (uint)local_b8[0] & 7 | (uint)local_94 & 0xffff0000);
              local_ac = local_ac | 0x400000;
              iVar23 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,2);
              if (iVar23 == 0) {
                local_9c = CONCAT22(4,(short)iVar6);
                local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
                local_90 = ((unsigned char *)0x00003210);
                local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x40);
                local_9c = local_9c | 0x400000;
                if (uVar22 == 1) {
                  local_ac = local_d0;
                  local_a8 = local_cc;
                }
                uVar11 = (uint)local_b8[0] >> 4 & 7;
                uVar13 = (uint)local_b8[0] >> 7 & 1;
                local_94 = (undefined *)
                           (uVar13 << 0xf |
                           uVar11 << 0xc |
                           uVar13 << 0xb |
                           uVar11 << 8 |
                           uVar13 << 7 |
                           uVar11 << 4 | uVar13 << 3 | uVar11 | (uint)local_94 & 0xffff0000);
                iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,3);
                if ((iVar6 == 0) && (1 < uVar22)) {
                  local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
                  if (uVar22 == 2) {
                    local_ac = local_d0;
                    local_a8 = local_cc;
                  }
                  uVar11 = (uint)local_b8[0] >> 8 & 7;
                  uVar13 = (uint)local_b8[0] >> 0xb & 1;
                  local_94 = (undefined *)
                             (uVar13 << 0xf |
                             uVar11 << 0xc |
                             uVar13 << 0xb |
                             uVar11 << 8 |
                             uVar13 << 7 |
                             uVar11 << 4 | uVar13 << 3 | uVar11 | (uint)local_94 & 0xffff0000);
                  iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,3);
                  if ((iVar6 == 0) && (uVar22 == 3)) {
                    uVar22 = (uint)local_b8[0] >> 0xc & 7;
                    uVar13 = (uint)local_b8[0] >> 0xf & 1;
                    local_ac = local_d0;
                    local_a8 = local_cc;
                    local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
                    local_94 = (undefined *)
                               (uVar13 << 0xf |
                               uVar22 << 0xc |
                               uVar13 << 0xb |
                               uVar22 << 8 |
                               uVar13 << 7 |
                               uVar22 << 4 | uVar13 << 3 | uVar22 | (uint)local_94 & 0xffff0000);
                    ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,3);
                  }
                }
              }
            }
            goto LAB_00048c78;
          }
          if (((uVar22 - 0x1f < 2) || (uVar22 == 0x23)) || (uVar22 == 0x3a)) {
            iVar6 = ((int (*)())FUN_00046a30)(param_1,iVar18);
            goto joined_r0x0004802c;
          }
          if (uVar22 == 0x6c) {
            local_5c = &local_b0;
            iVar14 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
            _memset(local_5c,0,0x24);
            iVar23 = iVar14 + iVar5;
            iVar24 = iVar23 + 8;
            iVar6 = ((int (*)())FUN_0003ed50)(param_1,iVar24);
            if (iVar6 == 1) {
              local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),99);
            }
            else if (iVar6 == 2) {
              local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x56);
              local_b0 = local_b0 & 0xc000ffff;
            }
            else {
              local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x47);
            }
            iVar24 = ((int (*)())FUN_0003f750)(param_1,iVar24,&local_ac,&local_a8,
                                  *(uint *)(iVar5 + iVar14 + 4) >> 0x14 & 1);
            if ((iVar24 == 0) &&
               (iVar23 = ((int (*)())FUN_0003f1c0)(param_1,iVar23 + 0x10,&local_a4,&local_98), iVar23 == 0)) {
              uVar9 = 1;
              if (iVar6 == 2) {
                uVar9 = 2;
                local_94 = (undefined *)((uint)local_94 & 0xffff0000 | 0x4444);
                local_a0 = CONCAT22((short)(local_a0 >> 0x10),(short)param_1[8]) & 0xffc0ffff |
                           0x440000;
              }
              iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,uVar9);
              goto joined_r0x00048414;
            }
            goto LAB_00048418;
          }
          if (uVar22 == 8) {
            iVar6 = ((int (*)())FUN_000467a0)(param_1,iVar18,0);
joined_r0x00048448:
            if (iVar6 != 0) {
LAB_00048d74:
              return param_1[9];
            }
            goto LAB_00048c78;
          }
          if (uVar22 == 9) {
            iVar6 = ((int (*)())FUN_00046180)(param_1,iVar18,0);
            goto joined_r0x00048448;
          }
          if (uVar22 == 10) {
            local_5c = &local_b0;
            iVar23 = *param_1;
            iVar6 = *(int *)(iVar23 + 0x54);
            _memset(local_5c,0,0x24);
            iVar23 = iVar23 + iVar6 * 8 + iVar5;
            local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x5b);
            iVar6 = ((int (*)())FUN_0003f750)(param_1,iVar23 + 8,&local_ac,&local_a8,1);
            if (iVar6 == 0) {
              local_98 = (undefined *)((uint)local_98 & 0xffff0000 | 0x5555);
              local_a4 = CONCAT22((short)(local_a4 >> 0x10),(short)param_1[8]) & 0xffc0ffff |
                         0x440000;
              iVar6 = ((int (*)())FUN_0003f1c0)(param_1,iVar23 + 0x10,&local_a0,&local_94);
              if (iVar6 == 0) {
                iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,2);
joined_r0x00048414:
                if (iVar6 == 0) goto LAB_00048c78;
              }
            }
            goto LAB_00048418;
          }
          if (uVar22 == 0x26) {
            local_5c = &local_b0;
            iVar23 = *param_1;
            iVar6 = *(int *)(iVar23 + 0x54);
            _memset(local_5c,0,0x24);
            iVar23 = iVar23 + iVar6 * 8 + iVar5;
            local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x5b);
            local_a8 = local_a8 & 0xffffff00 | 0x55;
            local_ac = CONCAT22((short)(local_ac >> 0x10),(short)param_1[8]) & 0xffc0ffff | 0x440000
            ;
            iVar6 = ((int (*)())FUN_0003f1c0)(param_1,iVar23 + 0x10,&local_a4,&local_98);
            if (((iVar6 == 0) &&
                (iVar6 = ((int (*)())FUN_0003f1c0)(param_1,iVar23 + 0x18,&local_a0,&local_94), iVar6 == 0)) &&
               (iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,2), iVar6 == 0)) {
              local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),1);
              iVar6 = ((int (*)())FUN_0003f750)(param_1,iVar23 + 8,&local_ac,&local_a8,1);
              if (iVar6 == 0) {
                local_a4 = CONCAT22(4,(short)param_1[8]);
                local_98 = ((unsigned char *)0x00003210);
                local_a4 = local_a4 | 0x400000;
                iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,1);
                goto joined_r0x00048414;
              }
            }
            goto LAB_00048418;
          }
          if (uVar22 == 0x39) {
            iVar6 = ((int (*)())FUN_000457f0)(param_1,iVar18);
            goto joined_r0x00048448;
          }
          if (uVar22 == 0x6d) {
            iVar6 = ((int (*)())FUN_00044c90)(param_1,iVar18);
            goto joined_r0x00048448;
          }
          if ((uVar22 == 0x31) || (uVar22 == 0x36)) {
            iVar6 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
            if ((param_1[5] & 0x20000000U) == 0) {
              local_7c = 0;
              local_78 = 0;
            }
            else {
              local_78 = *(uint *)(iVar6 + iVar5 + 0x10) >> 0xe & 1;
              local_7c = *(uint *)(iVar6 + iVar5 + 0x18) >> 0xe & 1;
            }
            puVar26 = (uint *)(iVar5 + iVar6 + 0x10);
            puVar21 = (uint *)(iVar5 + iVar6 + 0x18);
            local_74 = (uint *)(iVar5 + iVar6);
            local_5c = &local_b0;
            local_80 = (local_74[1] >> 0x1a & 3) + 1;
            local_84 = (*puVar26 >> 0xc & 3) + 1;
            local_88[0] = (*puVar21 >> 0xc & 3) + 1;
            _memset(local_5c,0,0x24);
            local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x56);
            local_b0 = (uint)((*(uint *)(iVar5 + iVar6) & 0x3fc0000) == 0xc40000) << 0x10 |
                       local_b0 & 0xc000ffff;
            iVar23 = ((int (*)())FUN_0003f1c0)(param_1,puVar26,&local_a4,&local_98);
            if ((iVar23 == 0) &&
               (iVar23 = ((int (*)())FUN_0003f1c0)(param_1,puVar21,&local_a0,&local_94), iVar23 == 0)) {
              if (local_80 < 2) {
                local_ac = CONCAT22(4,(short)param_1[8]);
                local_a8 = 0x55;
                local_ac = local_ac | 0x400000;
                iVar23 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,2);
                if (iVar23 == 0) {
                  iVar23 = local_84;
                  if (local_84 < local_88[0]) {
                    iVar23 = local_88[0];
                  }
                  bVar1 = local_78 != 0;
                  if (((bVar1) || (local_7c != 0)) && (1 < iVar23)) {
                    local_60 = &local_d4;
                    local_ac = CONCAT22((*(unsigned short *)((unsigned char *)&(local_ac) + 0)),(short)param_1[8] + 1);
                    _memset(local_60,0,0x24);
                    uVar10 = 0x49;
                    if ((*(uint *)(iVar5 + iVar6) & 0x3fc0000) != 0xc40000) {
                      uVar10 = 3;
                    }
                    local_d4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_d4) + 0)),uVar10);
                    sVar3 = (short)param_1[8];
                    local_d0 = CONCAT22(4,sVar3);
                    iVar6 = 1;
                    local_c4 = CONCAT22(4,sVar3 + 1);
                    local_c8 = CONCAT22(4,sVar3);
                    local_cc = 0x55;
                    bVar2 = local_7c != 0;
                    local_b8[0] = ((unsigned char *)0x00003210);
                    local_bc = ((unsigned char *)0x00003210);
                    local_d0 = local_d0 | 0x400000;
                    local_c4 = local_c4 | 0x400000;
                    local_c8 = local_c8 | 0x400000;
                    do {
                      if (bVar1) {
                        local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
                      }
                      if (bVar2) {
                        local_a0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a0) + 0)),(*(unsigned short *)((unsigned char *)&(local_a0) + 2)) + 1);
                      }
                      iVar24 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,2);
                      if ((iVar24 != 0) ||
                         (iVar24 = ((int (*)())FUN_0003fbf0)(param_1,local_60,1,2), iVar24 != 0))
                      goto LAB_000488e8;
                      iVar6 = iVar6 + 1;
                    } while (iVar23 != iVar6);
                  }
                  if ((*local_74 & 0x3fc0000) == 0xc40000) {
                    iVar6 = ((int (*)())FUN_00046180)(param_1,iVar18,iVar23);
                    goto joined_r0x0004802c;
                  }
                  local_60 = &local_d4;
                  iVar23 = *param_1;
                  iVar6 = *(int *)(iVar23 + 0x54);
                  _memset(local_60,0,0x24);
                  local_d4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_d4) + 0)),0x23);
                  iVar6 = ((int (*)())FUN_0003f750)(param_1,iVar23 + iVar6 * 8 + iVar5 + 8,&local_d0,&local_cc,1)
                  ;
                  if (iVar6 == 0) {
                    local_c8 = CONCAT22(4,(short)param_1[8]);
                    local_bc = ((unsigned char *)0x00003210);
                    local_b8[0] = (undefined *)((uint)local_b8[0] & 0xffff0000 | 0x5555);
                    local_c8 = local_c8 | 0x400000;
                    local_c4 = CONCAT22((short)(local_c4 >> 0x10),(short)param_1[8]) & 0xffc0ffff |
                               0x440000;
                    iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_60,1,2);
                    if (iVar6 == 0) goto LAB_00048c70;
                  }
                }
                goto LAB_000488e8;
              }
              ((int (*)())FUN_0003f750)(param_1,iVar5 + iVar6 + 8,&local_ac,&local_a8,0);
              ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,2);
              iVar6 = param_1[9];
            }
            else {
LAB_000488e8:
              iVar6 = param_1[9];
            }
joined_r0x0004802c:
            if (iVar6 != 0) goto LAB_00048d74;
            goto LAB_00048c70;
          }
          if (uVar22 != 0x4d) break;
        }
        iVar17 = iVar17 + 1;
        iVar18 = iVar18 + iVar15;
        if (iVar16 == iVar17) goto LAB_00048d20;
        iVar5 = iVar18 * 8;
        puVar19 = puVar20 + iVar18 * 2;
        uVar22 = puVar20[iVar18 * 2] >> 0x12 & 0xff;
        iVar8 = uVar22 * 0x10;
        uVar13 = *(uint *)(&DAT_001dac34 + iVar8) >> 0x11 & 0xf;
        if ((uVar13 == 0) || ((*(uint *)(&DAT_001dac40 + iVar8) >> 0x1c & DAT_001db344) != 0))
        break;
      } while( true );
    }
    iVar8 = param_1[9];
    if (iVar8 == 0) {
      iVar8 = 3;
      param_1[9] = 3;
    }
  }
  return iVar8;
}

/* FUN_00048da0 @ 0x48da0 (6552 bytes) */
int FUN_00048da0(param_1)
  int *param_1;
{
  undefined **ppuVar1;
  undefined4 *puVar2;
  bool bVar3;
  ushort uVar4;
  short sVar5;
  undefined2 uVar6;
  short sVar7;
  double dVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  void *pvVar16;
  undefined4 *puVar17;
  dword *pdVar18;
  undefined4 *puVar19;
  undefined **ppuVar20;
  int *piVar21;
  undefined *puVar22;
  uint uVar23;
  undefined4 uVar24;
  uint uVar25;
  undefined4 *puVar26;
  int iVar27;
  int iVar28;
  undefined4 local_b8[0];
  undefined4 local_b4;
  uint local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined *local_a0 [10];
  undefined4 local_78;
  uint uStack_74;
  undefined4 local_70;
  uint uStack_6c;
  undefined4 local_68;
  uint uStack_64;
  undefined4 local_60;
  uint uStack_5c[0];
  
  piVar21 = (int *)*param_1;
  if (piVar21 == (int *)0x0) {
    if (param_1[9] != 0) {
      return param_1[9];
    }
    param_1[9] = 2;
    return 2;
  }
  param_1[8] = piVar21[4] + piVar21[0xc] + 1;
  iVar12 = *piVar21;
  if ((iVar12 != 0x8804) && (iVar12 != 0x8b30)) {
switchD_00049180_caseD_0:
    if (param_1[9] != 0) {
      return param_1[9];
    }
LAB_0004a4ec:
    param_1[9] = 3;
    return 3;
  }
  piVar21 = param_1 + 10;
  param_1[5] = (uint)(iVar12 - 0x8b30U < 2) << 0x1d | param_1[5] & 0xdfffffffU;
  iVar12 = param_1[0xb];
  uVar9 = param_1[0xc];
  if (uVar9 < iVar12 + 2U) {
    if (uVar9 == 0) {
      uVar9 = 0x10;
    }
    else {
      uVar9 = uVar9 << 1;
    }
    for (; uVar9 < iVar12 + 2U; uVar9 = uVar9 << 1) {
    }
    if ((void *)*piVar21 == (void *)0x0) {
      pvVar16 = _malloc(uVar9 << 2);
    }
    else {
      pvVar16 = _realloc((void *)*piVar21,uVar9 << 2);
    }
    if (pvVar16 != (void *)0x0) {
      *piVar21 = (int)pvVar16;
      param_1[0xc] = uVar9;
      iVar12 = param_1[0xb];
      goto LAB_00048eb4;
    }
    iVar12 = param_1[9];
    if (iVar12 == 0) {
      iVar12 = 1;
      param_1[9] = 1;
    }
    if (iVar12 != 0) {
      return iVar12;
    }
    puVar26 = (undefined4 *)0x0;
    pdVar18 = &MACH_HEADER.cputype;
  }
  else {
LAB_00048eb4:
    param_1[0xb] = iVar12 + 2;
    puVar26 = (undefined4 *)(iVar12 * 4 + *piVar21);
    pdVar18 = puVar26 + 1;
  }
  *puVar26 = 1;
  *pdVar18 = 0x10200;
  iVar27 = *param_1;
  iVar12 = *(int *)(iVar27 + 0x30);
  puVar10 = (uint *)(iVar27 + *(int *)(iVar27 + 0x34) * 8);
  if (0 < iVar12) {
    do {
      if (((*puVar10 >> 0x10 & 0xf) == 4) && ((*puVar10 & 0xe) != 0)) {
        *(uint *)(param_1[0xd] + 0x20) = *(uint *)(param_1[0xd] + 0x20) | 0x400000;
        iVar27 = *param_1;
        break;
      }
      puVar10 = puVar10 + 2;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  iVar13 = *(int *)(iVar27 + 0x48);
  iVar12 = iVar27 + *(int *)(iVar27 + 0x4c) * 8;
  if (0 < iVar13) {
    do {
      switch(*(undefined1 *)(iVar12 + 3)) {
      case 0:
      case 8:
      case 10:
        iVar12 = param_1[9];
        if (iVar12 == 0) goto LAB_0004a4ec;
        if (iVar12 != 0) {
          return iVar12;
        }
        goto LAB_00049048;
      case 1:
        param_1[5] = param_1[5] & 0xe7ffffffU | 0x10000000;
        break;
      case 2:
        param_1[5] = param_1[5] & 0xe7ffffffU | 0x18000000;
        break;
      case 3:
        param_1[5] = param_1[5] & 0xe7ffffffU | 0x8000000;
      }
      iVar13 = iVar13 + -1;
      iVar12 = iVar12 + 8;
    } while (iVar13 != 0);
  }
LAB_00049048:
  iVar12 = *(int *)(iVar27 + 0x20);
  iVar13 = param_1[0xb];
  uVar9 = param_1[0xc];
  uVar14 = iVar12 * 2 + iVar13;
  puVar10 = (uint *)(iVar27 + *(int *)(iVar27 + 0x24) * 8);
  if (uVar9 < uVar14) {
    if (uVar9 == 0) {
      uVar9 = 0x10;
    }
    else {
      uVar9 = uVar9 << 1;
    }
    for (; uVar9 < uVar14; uVar9 = uVar9 << 1) {
    }
    if ((void *)*piVar21 == (void *)0x0) {
      pvVar16 = _malloc(uVar9 << 2);
    }
    else {
      pvVar16 = _realloc((void *)*piVar21,uVar9 << 2);
    }
    if (pvVar16 == (void *)0x0) goto LAB_0004a55c;
    *piVar21 = (int)pvVar16;
    param_1[0xc] = uVar9;
    iVar13 = param_1[0xb];
  }
  param_1[0xb] = iVar12 * 2 + iVar13;
  puVar17 = (undefined4 *)(iVar13 * 4 + *piVar21);
  if (iVar12 < 1) {
LAB_0004921c:
    if ((param_1[5] & 0x18000000U) != 0) {
      iVar12 = param_1[0xb];
      uVar9 = param_1[0xc];
      if (uVar9 < iVar12 + 2U) {
        if (uVar9 == 0) {
          uVar9 = 0x10;
        }
        else {
          uVar9 = uVar9 << 1;
        }
        for (; uVar9 < iVar12 + 2U; uVar9 = uVar9 << 1) {
        }
        if ((void *)*piVar21 == (void *)0x0) {
          pvVar16 = _malloc(uVar9 << 2);
        }
        else {
          pvVar16 = _realloc((void *)*piVar21,uVar9 << 2);
        }
        if (pvVar16 == (void *)0x0) goto LAB_0004a55c;
        *piVar21 = (int)pvVar16;
        param_1[0xc] = uVar9;
        iVar12 = param_1[0xb];
      }
      param_1[0xb] = iVar12 + 2;
      puVar17 = (undefined4 *)(iVar12 * 4 + *piVar21);
      *puVar17 = 0x1ff0016;
      puVar17[1] = 0x100000;
    }
  }
  else {
    bVar3 = false;
    do {
      uVar4 = *(ushort *)puVar10;
      if ((uVar4 & 0xf) == 1) {
        *puVar17 = 0x3ff0016;
switchD_00049180_caseD_1:
        uVar9 = 0x160000;
      }
      else {
        *puVar17 = 0x1ff0016;
        switch(uVar4 & 0xf) {
        default:
          goto switchD_00049180_caseD_0;
        case 1:
          goto switchD_00049180_caseD_1;
        case 2:
          uVar9 = 0x120000;
          break;
        case 3:
          uVar9 = 0x130000;
          break;
        case 5:
          bVar3 = true;
          uVar9 = 0x100000;
          break;
        case 7:
          uVar9 = *puVar10 & 0x1f | 0x110000;
        }
      }
      iVar12 = iVar12 + -1;
      puVar17[1] = uVar9;
      puVar17 = puVar17 + 2;
      puVar10 = puVar10 + 2;
    } while (iVar12 != 0);
    if (!bVar3) goto LAB_0004921c;
  }
  uVar9 = param_1[1];
  uVar14 = param_1[2];
  iVar13 = 0;
  iVar27 = 0x10;
  iVar12 = 0;
  do {
    iVar28 = iVar12;
    switch(uVar14 & 0xf) {
    case 0:
      iVar28 = iVar12 + 1;
      (local_b8)[iVar12] = iVar13 << 0x10 | 0xc000019;
      break;
    case 1:
      iVar28 = iVar12 + 1;
      (local_b8)[iVar12] = iVar13 << 0x10 | 0xb000019;
      break;
    case 2:
      iVar28 = iVar12 + 1;
      (local_b8)[iVar12] = iVar13 << 0x10 | 0x12000019;
      break;
    case 3:
      iVar28 = iVar12 + 1;
      (local_b8)[iVar12] = iVar13 << 0x10 | 0xa000019;
      break;
    case 4:
      iVar28 = iVar12 + 1;
      (local_b8)[iVar12] = iVar13 << 0x10 | 0x9000019;
    }
    iVar27 = iVar27 + -1;
    uVar23 = uVar9 << 0x1c;
    uVar9 = uVar9 >> 4;
    iVar13 = iVar13 + 1;
    uVar14 = uVar23 | uVar14 >> 4;
    iVar12 = iVar28;
  } while (iVar27 != 0);
  iVar12 = param_1[0xb];
  uVar9 = param_1[0xc];
  if (uVar9 < (uint)(iVar28 + iVar12)) {
    if (uVar9 == 0) {
      uVar9 = 0x10;
    }
    else {
      uVar9 = uVar9 << 1;
    }
    for (; uVar9 < (uint)(iVar28 + iVar12); uVar9 = uVar9 << 1) {
    }
    if ((void *)*piVar21 == (void *)0x0) {
      pvVar16 = _malloc(uVar9 << 2);
    }
    else {
      pvVar16 = _realloc((void *)*piVar21,uVar9 << 2);
    }
    if (pvVar16 != (void *)0x0) {
      *piVar21 = (int)pvVar16;
      param_1[0xc] = uVar9;
      iVar12 = param_1[0xb];
      goto LAB_00049448;
    }
    iVar27 = param_1[9];
    if (iVar27 == 0) {
      iVar27 = 1;
      param_1[9] = 1;
    }
    iVar12 = 0;
    if (iVar27 != 0) {
      return iVar27;
    }
  }
  else {
LAB_00049448:
    param_1[0xb] = iVar28 + iVar12;
    iVar12 = iVar12 * 4 + *piVar21;
  }
  if (0 < iVar28) {
    iVar27 = 0;
    do {
      *(undefined4 *)(iVar27 + iVar12) = *(undefined4 *)((int)&local_b8 + iVar27);
      iVar27 = iVar27 + 4;
      iVar28 = iVar28 + -1;
    } while (iVar28 != 0);
  }
  dVar8 = DOUBLE_001aa1e0;
  iVar12 = *param_1;
  uVar9 = *(uint *)(iVar12 + 0x28);
  puVar10 = (uint *)(iVar12 + *(int *)(iVar12 + 0x2c) * 8);
  iVar12 = iVar12 + *(int *)(iVar12 + 0x6c) * 8;
  if (0 < (int)uVar9) {
    uVar14 = 0;
    do {
      uVar23 = *puVar10 & 0x1c000000;
      if ((((uVar23 != 0xc000000) && (uVar23 != 0x4000000)) && (uVar23 != 0x10000000)) &&
         (uVar23 != 0)) {
        iVar12 = param_1[9];
        if (iVar12 == 0) goto LAB_0004a4ec;
        goto LAB_0004980c;
      }
      if ((*puVar10 >> 0x10 & 0x1f) == 0x11) {
        iVar27 = param_1[0xb];
        uVar23 = param_1[0xc];
        if (uVar23 < iVar27 + 6U) {
          if (uVar23 == 0) {
            uVar23 = 0x10;
          }
          else {
            uVar23 = uVar23 << 1;
          }
          for (; uVar23 < iVar27 + 6U; uVar23 = uVar23 << 1) {
          }
          if ((void *)*piVar21 == (void *)0x0) {
            pvVar16 = _malloc(uVar23 << 2);
          }
          else {
            pvVar16 = _realloc((void *)*piVar21,uVar23 << 2);
          }
          if (pvVar16 == (void *)0x0) goto LAB_0004a55c;
          *piVar21 = (int)pvVar16;
          param_1[0xc] = uVar23;
          iVar27 = param_1[0xb];
        }
        param_1[0xb] = iVar27 + 6;
        puVar17 = (undefined4 *)(iVar27 * 4 + *piVar21);
        *puVar17 = 0x1c;
        puVar17[1] = uVar14 & 0xffff | 0x10000;
        uVar23 = (uint)(ushort)*puVar10;
        if ((*puVar10 & 0x1c000000) == 0xc000000) {
          local_78 = 0x43300000;
          iVar27 = iVar12 + uVar23 * 0x10;
          uStack_74 = *(uint *)(uVar23 * 0x10 + iVar12) ^ 0x80000000;
          puVar17[2] = (float)((double)CONCAT44(0x43300000,uStack_74) - dVar8);
          local_70 = 0x43300000;
          uStack_6c = *(uint *)(iVar27 + 4) ^ 0x80000000;
          puVar17[3] = (float)((double)CONCAT44(0x43300000,uStack_6c) - dVar8);
          local_68 = 0x43300000;
          uStack_64 = *(uint *)(iVar27 + 8) ^ 0x80000000;
          puVar17[4] = (float)((double)CONCAT44(0x43300000,uStack_64) - dVar8);
          local_60 = 0x43300000;
          uStack_5c[0] = *(uint *)(iVar27 + 0xc) ^ 0x80000000;
          puVar17[5] = (float)((double)CONCAT44(0x43300000,uStack_5c[0]) - dVar8);
        }
        else if ((*puVar10 & 0x1c000000) == 0x10000000) {
          iVar27 = iVar12 + uVar23 * 0x10;
          puVar17[2] = (uint)(*(int *)(iVar12 + uVar23 * 0x10) != 0);
          puVar17[3] = (uint)(*(int *)(iVar27 + 4) != 0);
          puVar17[4] = (uint)(*(int *)(iVar27 + 8) != 0);
          puVar17[5] = (uint)(*(int *)(iVar27 + 0xc) != 0);
        }
        else {
          iVar27 = iVar12 + uVar23 * 0x10;
          puVar17[2] = *(undefined4 *)(iVar12 + uVar23 * 0x10);
          puVar17[3] = *(undefined4 *)(iVar27 + 4);
          puVar17[4] = *(undefined4 *)(iVar27 + 8);
          puVar17[5] = *(undefined4 *)(iVar27 + 0xc);
        }
      }
      uVar14 = uVar14 + 1;
      puVar10 = puVar10 + 2;
    } while (uVar9 != uVar14);
  }
  param_1[6] = param_1[0xb];
  iVar12 = param_1[0xb];
  uVar9 = param_1[0xc];
  if (uVar9 < iVar12 + 0xc6U) {
    if (uVar9 == 0) {
      uVar9 = 0x10;
    }
    else {
      uVar9 = uVar9 << 1;
    }
    for (; uVar9 < iVar12 + 0xc6U; uVar9 = uVar9 << 1) {
    }
    if ((void *)*piVar21 == (void *)0x0) {
      pvVar16 = _malloc(uVar9 << 2);
    }
    else {
      pvVar16 = _realloc((void *)*piVar21,uVar9 << 2);
    }
    if (pvVar16 == (void *)0x0) {
LAB_0004a55c:
      if (param_1[9] != 0) {
        return param_1[9];
      }
      param_1[9] = 1;
      return 1;
    }
    *piVar21 = (int)pvVar16;
    param_1[0xc] = uVar9;
    iVar12 = param_1[0xb];
  }
  iVar27 = *piVar21;
  param_1[0xb] = iVar12 + 0xc6;
  iVar13 = 0;
  iVar28 = 0xc6;
  do {
    *(undefined4 *)(iVar13 + iVar12 * 4 + iVar27) = 0x4b;
    iVar13 = iVar13 + 4;
    iVar28 = iVar28 + -1;
  } while (iVar28 != 0);
  iVar12 = param_1[9];
  param_1[7] = param_1[0xb];
LAB_0004980c:
  if (iVar12 != 0) {
    return iVar12;
  }
  iVar12 = ((int (*)())FUN_00046e90)(param_1);
  if (iVar12 != 0) goto LAB_0004a7b4;
  iVar12 = *param_1;
  uVar9 = *(uint *)(iVar12 + 0x30);
  puVar10 = (uint *)(iVar12 + *(int *)(iVar12 + 0x34) * 8);
  if (0 < (int)uVar9) {
    uVar14 = 0;
    do {
      if ((1 << (uVar14 & 0x3f) & param_1[4]) != 0) {
        uVar24 = 0x55;
        puVar22 = ((unsigned char *)0x00003210);
        uVar23 = uVar14 + *(int *)(*param_1 + 0x10) + 1 & 0xffff | 0x440000;
        if ((*(ushort *)puVar10 & 0xf) == 4) {
          iVar12 = param_1[0xd];
          if (((*(uint *)(iVar12 + 0x20) & 0x400000) != 0) ||
             (bVar3 = true, (*(uint *)(iVar12 + 0x20) >> 0x12 & 0xf) < 2)) {
            bVar3 = false;
          }
          uVar15 = param_1[5];
          param_1[5] = uVar15 | 0x80000000;
          uVar25 = *puVar10 >> 1 & 7 | 0x570000;
          if ((uVar15 & 0x18000000) != 0) {
            *(uint *)(iVar12 + 0x20) = *(uint *)(iVar12 + 0x20) | 0x2000000;
            uVar6 = (undefined2)param_1[8];
            sVar7 = ((ushort)((uint)*(undefined4 *)(param_1[0xd] + 0x20) >> 0x1a) & 1) +
                    (short)*(undefined4 *)(*param_1 + 0x28);
            _memset(&local_b8,0,0x24);
            sVar5 = sVar7 + 1;
            uVar15 = (uint)param_1[5] >> 0x1b & 3;
            local_b4 = CONCAT22(4,uVar6);
            local_b0 = 0x55;
            local_a0[0] = (undefined *)((uint)local_a0[0] & 0xffff0000);
            local_ac = (undefined *)((uint)local_ac & 0xffc0ffff | 0x500000);
            local_b4 = local_b4 | 0x400000;
            if (uVar15 == 1) {
              iVar12 = param_1[9];
              local_b8[0] = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b8[0]) + 0)),0x40);
              local_b0 = 0x155;
              local_a0[1] = (undefined *)0x0;
              local_a8 = CONCAT22(1,sVar5) | 0x400000;
              local_a0[2] = ((unsigned char *)0x00001111);
              local_a4 = CONCAT22(1,sVar5) | 0x400000;
              if (iVar12 == 0) {
                iVar12 = param_1[0xb];
                uVar15 = param_1[0xc];
                if (uVar15 < iVar12 + 9U) {
                  if (uVar15 == 0) {
                    uVar15 = 0x10;
                  }
                  else {
                    uVar15 = uVar15 << 1;
                  }
                  for (; uVar15 < iVar12 + 9U; uVar15 = uVar15 << 1) {
                  }
                  if ((void *)*piVar21 == (void *)0x0) {
                    pvVar16 = _malloc(uVar15 << 2);
                  }
                  else {
                    pvVar16 = _realloc((void *)*piVar21,uVar15 << 2);
                  }
                  if (pvVar16 == (void *)0x0) {
LAB_0004a188:
                    iVar12 = param_1[9];
                    if (iVar12 == 0) {
                      iVar12 = 1;
                      param_1[9] = 1;
                    }
                    goto LAB_0004a0d8;
                  }
                  *piVar21 = (int)pvVar16;
                  param_1[0xc] = uVar15;
                  iVar12 = param_1[0xb];
                }
                ppuVar20 = (undefined **)&local_ac;
                param_1[0xb] = iVar12 + 9;
                puVar17 = (undefined4 *)(iVar12 * 4 + *piVar21);
                *puVar17 = local_b8[0];
                puVar17[1] = local_b4;
                puVar17[2] = local_b0;
                do {
                  puVar17[3] = *ppuVar20;
                  ppuVar1 = ppuVar20 + 3;
                  ppuVar20 = ppuVar20 + 1;
                  puVar17[4] = *ppuVar1;
                  puVar17 = puVar17 + 2;
                } while (local_a0 != ppuVar20);
                goto LAB_0004a0d4;
              }
            }
            else {
              if ((uVar15 == 0) || (3 < uVar15)) goto LAB_0004a474;
              local_b8[0] = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b8[0]) + 0)),0x49);
              if ((param_1[5] & 0x18000000U) == 0x10000000) {
                local_a8 = CONCAT22(1,sVar5);
                iVar12 = param_1[9];
                local_a0[1] = ((unsigned char *)0x00002222);
                local_a8 = local_a8 | 0x400000;
                if (iVar12 == 0) {
                  iVar12 = param_1[0xb];
                  uVar15 = param_1[0xc];
                  if (uVar15 < iVar12 + 7U) {
                    if (uVar15 == 0) {
                      uVar15 = 0x10;
                    }
                    else {
                      uVar15 = uVar15 << 1;
                    }
                    for (; uVar15 < iVar12 + 7U; uVar15 = uVar15 << 1) {
                    }
                    if ((void *)*piVar21 == (void *)0x0) {
                      pvVar16 = _malloc(uVar15 << 2);
                    }
                    else {
                      pvVar16 = _realloc((void *)*piVar21,uVar15 << 2);
                    }
                    if (pvVar16 == (void *)0x0) {
LAB_00049f94:
                      iVar12 = param_1[9];
                      if (iVar12 == 0) {
                        iVar12 = 1;
                        param_1[9] = 1;
                      }
                      goto LAB_00049fa8;
                    }
                    *piVar21 = (int)pvVar16;
                    param_1[0xc] = uVar15;
                    iVar12 = param_1[0xb];
                  }
                  puVar19 = &local_ac;
                  param_1[0xb] = iVar12 + 7;
                  puVar17 = (undefined4 *)(iVar12 * 4 + *piVar21);
                  *puVar17 = local_b8[0];
                  puVar17[1] = local_b4;
                  puVar17[2] = local_b0;
                  do {
                    puVar17[3] = *puVar19;
                    puVar2 = puVar19 + 3;
                    puVar19 = puVar19 + 1;
                    puVar17[4] = *puVar2;
                    puVar17 = puVar17 + 2;
                  } while (&local_a4 != puVar19);
LAB_00049f80:
                  iVar12 = param_1[9];
                }
              }
              else {
                local_a8 = CONCAT22(1,sVar5);
                iVar12 = param_1[9];
                local_a8 = local_a8 | 0x400000;
                local_a0[1] = ((unsigned char *)0x00003333);
                if (iVar12 == 0) {
                  iVar12 = param_1[0xb];
                  uVar15 = param_1[0xc];
                  if (uVar15 < iVar12 + 7U) {
                    if (uVar15 == 0) {
                      uVar15 = 0x10;
                    }
                    else {
                      uVar15 = uVar15 << 1;
                    }
                    for (; uVar15 < iVar12 + 7U; uVar15 = uVar15 << 1) {
                    }
                    if ((void *)*piVar21 == (void *)0x0) {
                      pvVar16 = _malloc(uVar15 << 2);
                    }
                    else {
                      pvVar16 = _realloc((void *)*piVar21,uVar15 << 2);
                    }
                    if (pvVar16 == (void *)0x0) {
                      iVar12 = param_1[9];
                      if (iVar12 == 0) {
                        iVar12 = 1;
                        param_1[9] = 1;
                      }
                      goto LAB_00049e2c;
                    }
                    *piVar21 = (int)pvVar16;
                    param_1[0xc] = uVar15;
                    iVar12 = param_1[0xb];
                  }
                  puVar19 = &local_ac;
                  param_1[0xb] = iVar12 + 7;
                  puVar17 = (undefined4 *)(iVar12 * 4 + *piVar21);
                  *puVar17 = local_b8[0];
                  puVar17[1] = local_b4;
                  puVar17[2] = local_b0;
                  do {
                    puVar17[3] = *puVar19;
                    puVar2 = puVar19 + 3;
                    puVar19 = puVar19 + 1;
                    puVar17[4] = *puVar2;
                    puVar17 = puVar17 + 2;
                  } while (&local_a4 != puVar19);
                  iVar12 = param_1[9];
                }
LAB_00049e2c:
                local_ac = (undefined *)CONCAT22(4,uVar6);
                local_a8 = CONCAT22(4,uVar6);
                local_a0[0] = ((unsigned char *)0x00003210);
                local_a0[1] = ((unsigned char *)0x00003210);
                local_b8[0] = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b8[0]) + 0)),0x49);
                local_ac = (undefined *)((uint)local_ac | 0x400000);
                local_a8 = local_a8 | 0x400000;
                if (iVar12 == 0) {
                  iVar12 = param_1[0xb];
                  uVar15 = param_1[0xc];
                  if (uVar15 < iVar12 + 7U) {
                    if (uVar15 == 0) {
                      uVar15 = 0x10;
                    }
                    else {
                      uVar15 = uVar15 << 1;
                    }
                    for (; uVar15 < iVar12 + 7U; uVar15 = uVar15 << 1) {
                    }
                    if ((void *)*piVar21 == (void *)0x0) {
                      pvVar16 = _malloc(uVar15 << 2);
                    }
                    else {
                      pvVar16 = _realloc((void *)*piVar21,uVar15 << 2);
                    }
                    if (pvVar16 == (void *)0x0) goto LAB_00049f94;
                    *piVar21 = (int)pvVar16;
                    param_1[0xc] = uVar15;
                    iVar12 = param_1[0xb];
                  }
                  puVar19 = &local_ac;
                  param_1[0xb] = iVar12 + 7;
                  puVar17 = (undefined4 *)(iVar12 * 4 + *piVar21);
                  *puVar17 = local_b8[0];
                  puVar17[1] = local_b4;
                  puVar17[2] = local_b0;
                  do {
                    puVar17[3] = *puVar19;
                    puVar2 = puVar19 + 3;
                    puVar19 = puVar19 + 1;
                    puVar17[4] = *puVar2;
                    puVar17 = puVar17 + 2;
                  } while (&local_a4 != puVar19);
                  goto LAB_00049f80;
                }
              }
LAB_00049fa8:
              local_ac = (undefined *)CONCAT22(4,uVar6);
              local_b0 = local_b0 | 0x100;
              local_b8[0] = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b8[0]) + 0)),0x2d);
              local_ac = (undefined *)((uint)local_ac | 0x400000);
              local_a0[0] = (undefined *)0xba98;
              if (iVar12 != 0) goto LAB_0004a0d8;
              iVar12 = param_1[0xb];
              uVar15 = param_1[0xc];
              if (uVar15 < iVar12 + 5U) {
                if (uVar15 == 0) {
                  uVar15 = 0x10;
                }
                else {
                  uVar15 = uVar15 << 1;
                }
                for (; uVar15 < iVar12 + 5U; uVar15 = uVar15 << 1) {
                }
                if ((void *)*piVar21 == (void *)0x0) {
                  pvVar16 = _malloc(uVar15 << 2);
                }
                else {
                  pvVar16 = _realloc((void *)*piVar21,uVar15 << 2);
                }
                if (pvVar16 == (void *)0x0) goto LAB_0004a188;
                *piVar21 = (int)pvVar16;
                param_1[0xc] = uVar15;
                iVar12 = param_1[0xb];
              }
              param_1[0xb] = iVar12 + 5;
              puVar17 = (undefined4 *)(iVar12 * 4 + *piVar21);
              *puVar17 = local_b8[0];
              puVar17[1] = local_b4;
              puVar17[2] = local_b0;
              puVar17[3] = local_ac;
              puVar17[4] = local_a0[0];
LAB_0004a0d4:
              iVar12 = param_1[9];
            }
LAB_0004a0d8:
            iVar27 = *param_1;
            local_b8[0] = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b8[0]) + 0)),0x47);
            local_b0 = 0x155;
            sVar5 = (short)uVar14;
            local_b4 = CONCAT22(4,sVar5 + (short)*(undefined4 *)(iVar27 + 0x10) + 1);
            local_b4 = local_b4 | 0x400000;
            local_a0[0] = ((unsigned char *)0x00003210);
            local_ac = (undefined *)CONCAT22(4,sVar5 + (short)*(undefined4 *)(iVar27 + 0x10) + 1);
            local_ac = (undefined *)((uint)local_ac | 0x400000);
            if (iVar12 == 0) {
              iVar12 = param_1[0xb];
              uVar15 = param_1[0xc];
              if (uVar15 < iVar12 + 5U) {
                if (uVar15 == 0) {
                  uVar15 = 0x10;
                }
                else {
                  uVar15 = uVar15 << 1;
                }
                for (; uVar15 < iVar12 + 5U; uVar15 = uVar15 << 1) {
                }
                if ((void *)*piVar21 == (void *)0x0) {
                  pvVar16 = _malloc(uVar15 << 2);
                }
                else {
                  pvVar16 = _realloc((void *)*piVar21,uVar15 << 2);
                }
                if (pvVar16 == (void *)0x0) {
                  iVar12 = param_1[9];
                  if (iVar12 == 0) {
                    iVar12 = 1;
                    param_1[9] = 1;
                  }
                  iVar27 = *param_1;
                  goto LAB_0004a25c;
                }
                *piVar21 = (int)pvVar16;
                param_1[0xc] = uVar15;
                iVar12 = param_1[0xb];
              }
              param_1[0xb] = iVar12 + 5;
              puVar17 = (undefined4 *)(iVar12 * 4 + *piVar21);
              *puVar17 = local_b8[0];
              puVar17[1] = local_b4;
              puVar17[2] = local_b0;
              puVar17[3] = local_ac;
              puVar17[4] = local_a0[0];
              iVar27 = *param_1;
              iVar12 = param_1[9];
            }
LAB_0004a25c:
            local_b8[0] = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b8[0]) + 0)),0x3f);
            local_ac = (undefined *)CONCAT22(4,uVar6);
            local_b0 = 0x15;
            local_a0[0] = ((unsigned char *)0x00003210);
            local_b4 = CONCAT22(4,sVar5 + (short)*(undefined4 *)(iVar27 + 0x10) + 1);
            local_ac = (undefined *)((uint)local_ac | 0x400000);
            local_b4 = local_b4 | 0x400000;
            local_a4 = CONCAT22(1,sVar7);
            local_a0[1] = ((unsigned char *)0x00003210);
            local_a0[2] = ((unsigned char *)0x00003210);
            local_a8 = CONCAT22(4,sVar5 + (short)*(undefined4 *)(iVar27 + 0x10) + 1);
            local_a4 = local_a4 | 0x400000;
            local_a8 = local_a8 | 0x400000;
            if (iVar12 == 0) {
              iVar12 = param_1[0xb];
              uVar15 = param_1[0xc];
              if (uVar15 < iVar12 + 9U) {
                if (uVar15 == 0) {
                  uVar15 = 0x10;
                }
                else {
                  uVar15 = uVar15 << 1;
                }
                for (; uVar15 < iVar12 + 9U; uVar15 = uVar15 << 1) {
                }
                if ((void *)*piVar21 == (void *)0x0) {
                  pvVar16 = _malloc(uVar15 << 2);
                }
                else {
                  pvVar16 = _realloc((void *)*piVar21,uVar15 << 2);
                }
                if (pvVar16 == (void *)0x0) {
                  if (param_1[9] == 0) {
                    param_1[9] = 1;
                  }
                  goto LAB_0004a474;
                }
                *piVar21 = (int)pvVar16;
                param_1[0xc] = uVar15;
                iVar12 = param_1[0xb];
              }
              ppuVar20 = (undefined **)&local_ac;
              param_1[0xb] = iVar12 + 9;
              puVar17 = (undefined4 *)(iVar12 * 4 + *piVar21);
              *puVar17 = local_b8[0];
              puVar17[1] = local_b4;
              puVar17[2] = local_b0;
              do {
                puVar17[3] = *ppuVar20;
                ppuVar1 = ppuVar20 + 3;
                ppuVar20 = ppuVar20 + 1;
                puVar17[4] = *ppuVar1;
                puVar17 = puVar17 + 2;
              } while (local_a0 != ppuVar20);
            }
          }
LAB_0004a474:
          uVar15 = 0;
          if (bVar3) {
            do {
              if (((int)(*(uint *)(param_1[0xd] + 0x20) >> 0x12 & 0xf) >> (uVar15 & 0x3f) & 1U) != 0
                 ) {
                iVar12 = param_1[0xb];
                uVar11 = param_1[0xc];
                if (uVar11 < iVar12 + 5U) {
                  if (uVar11 == 0) {
                    uVar11 = 0x10;
                  }
                  else {
                    uVar11 = uVar11 << 1;
                  }
                  for (; uVar11 < iVar12 + 5U; uVar11 = uVar11 << 1) {
                  }
                  if ((void *)*piVar21 == (void *)0x0) {
                    pvVar16 = _malloc(uVar11 << 2);
                  }
                  else {
                    pvVar16 = _realloc((void *)*piVar21,uVar11 << 2);
                  }
                  if (pvVar16 == (void *)0x0) goto LAB_0004a55c;
                  *piVar21 = (int)pvVar16;
                  param_1[0xc] = uVar11;
                  iVar12 = param_1[0xb];
                }
                uVar25 = uVar15 & 0xffff | uVar25 & 0xffff0000;
                param_1[0xb] = iVar12 + 5;
                iVar27 = iVar12 * 4 + *piVar21;
                *(undefined4 *)(iVar12 * 4 + *piVar21) = 0x47;
                *(undefined **)(iVar27 + 0x10) = ((unsigned char *)0x00003210);
                *(uint *)(iVar27 + 4) = uVar25;
                *(undefined4 *)(iVar27 + 8) = 0x55;
                *(uint *)(iVar27 + 0xc) = uVar23;
              }
              bVar3 = uVar15 != 3;
              uVar15 = uVar15 + 1;
            } while (bVar3);
            goto LAB_0004a680;
          }
        }
        else {
          if ((*(ushort *)puVar10 & 0xf) != 7) goto switchD_00049180_caseD_0;
          uVar15 = param_1[5];
          uVar24 = 0x155;
          param_1[5] = uVar15 | 0x40000000;
          uVar25 = 0x580000;
          if ((uVar15 & 0x20000000) == 0) {
            puVar22 = ((unsigned char *)0x00003212);
          }
        }
        iVar12 = param_1[0xb];
        uVar15 = param_1[0xc];
        if (uVar15 < iVar12 + 5U) {
          if (uVar15 == 0) {
            uVar15 = 0x10;
          }
          else {
            uVar15 = uVar15 << 1;
          }
          for (; uVar15 < iVar12 + 5U; uVar15 = uVar15 << 1) {
          }
          if ((void *)*piVar21 == (void *)0x0) {
            pvVar16 = _malloc(uVar15 << 2);
          }
          else {
            pvVar16 = _realloc((void *)*piVar21,uVar15 << 2);
          }
          if (pvVar16 == (void *)0x0) goto LAB_0004a55c;
          *piVar21 = (int)pvVar16;
          param_1[0xc] = uVar15;
          iVar12 = param_1[0xb];
        }
        param_1[0xb] = iVar12 + 5;
        puVar17 = (undefined4 *)(iVar12 * 4 + *piVar21);
        *puVar17 = 0x47;
        puVar17[4] = puVar22;
        puVar17[1] = uVar25;
        puVar17[2] = uVar24;
        puVar17[3] = uVar23;
      }
LAB_0004a680:
      uVar14 = uVar14 + 1;
      puVar10 = puVar10 + 2;
    } while (uVar9 != uVar14);
  }
  iVar12 = param_1[0xb];
  uVar9 = param_1[0xc];
  if (uVar9 < iVar12 + 1U) {
    if (uVar9 == 0) {
      uVar9 = 0x10;
    }
    else {
      uVar9 = uVar9 << 1;
    }
    for (; uVar9 < iVar12 + 1U; uVar9 = uVar9 << 1) {
    }
    if ((void *)*piVar21 == (void *)0x0) {
      pvVar16 = _malloc(uVar9 << 2);
    }
    else {
      pvVar16 = _realloc((void *)*piVar21,uVar9 << 2);
    }
    if (pvVar16 != (void *)0x0) {
      *piVar21 = (int)pvVar16;
      param_1[0xc] = uVar9;
      iVar12 = param_1[0xb];
      goto LAB_0004a708;
    }
    iVar12 = param_1[9];
    if (iVar12 == 0) {
      iVar12 = 1;
      param_1[9] = 1;
    }
    if (iVar12 != 0) {
      return iVar12;
    }
  }
  else {
LAB_0004a708:
    param_1[0xb] = iVar12 + 1;
    puVar26 = (undefined4 *)(iVar12 * 4 + *piVar21);
  }
  *puVar26 = 0x28;
  iVar12 = param_1[7];
  iVar27 = iVar12 - param_1[6];
  if (iVar27 != 0) {
    _memmove((void *)(param_1[10] + param_1[6] * 4),(void *)(param_1[10] + iVar12 * 4),
             (param_1[0xb] - iVar12) * 4);
    param_1[7] = param_1[6];
    param_1[0xb] = param_1[0xb] - iVar27;
  }
  if ((param_1[5] & 0xc0000000U) == 0) {
    ((int (*)())FUN_0003f850)(param_1);
  }
LAB_0004a7b4:
  return param_1[9];
}

/* FUN_0004a7d0 @ 0x4a7d0 (80 bytes) */
uint FUN_0004a7d0(double param_1)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  
  fVar1 = (float)param_1;
  uVar2 = (uint)fVar1 >> 0x17 & 0xff;
  uVar3 = (uint)fVar1 >> 8 & 0x800000;
  if (uVar2 < 0x41) {
    return 0;
  }
  if (0xbf < uVar2) {
    return uVar3 | 0x7fffff;
  }
  return (uint)fVar1 >> 7 & 0xffff | uVar3 | (uVar2 - 0x40) * 0x10000;
}

/* FUN_0004a860 @ 0x4a860 (112 bytes) */
int FUN_0004a860(param_1)
  int param_1;
{
  char cVar1;
  
  if (((*(uint *)(param_1 + 0x44) & 0x20000) != 0) && (*(int *)(param_1 + 0x1e70) != 0)) {
    if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
      cVar1 = ((unsigned char *)0x00001136)[param_1];
    }
    else {
      cVar1 = ((unsigned char *)0x000011d0)[param_1];
    }
    if (cVar1 == '\0') {
                    
                    
      (**(code **)(param_1 + 0x294c))(param_1);
      return;
    }
  }
                    
                    
  (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
  return;
}

/* FUN_0004a8f0 @ 0x4a8f0 (140 bytes) */
int FUN_0004a8f0(param_1)
  int param_1;
{
  if ((*(uint *)(param_1 + 0x44) & 0x20000) == 0) {
    FUN_000b6580(param_1,0);
                    
                    
    (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
    return;
  }
  if ((*(uint *)(param_1 + 0x44) & 0x2000) != 0) {
    FUN_000afe40(param_1,0);
    return;
  }
  FUN_000b3630();
  return;
}

/* FUN_0004a990 @ 0x4a990 (100 bytes) */
int FUN_0004a990(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  ((int (*)())FUN_0004cde0)(param_2 + 8);
  ((int (*)())FUN_0004cde0)(param_2 + 8);
  *param_2 = 0;
  param_2[7] = 0;
  if ((param_1 != 0) && (param_2 == *(undefined4 **)(param_1 + 0x1e68))) {
    *(undefined4 *)(param_1 + 0x1e68) = 0;
  }
  return;
}

/* FUN_0004aa00 @ 0x4aa00 (136 bytes) */
int FUN_0004aa00(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  puVar2 = *(undefined1 **)(((unsigned char *)0x00001488) + param_1);
  if ((puVar2 == (undefined1 *)0x0) ||
     ((*(int *)(puVar2 + 0x37cc) < 0x41 && (*(int *)(puVar2 + 0x37d0) < 0x41)))) {
    uVar1 = 0;
  }
  else {
    if (param_2 != 0) {
      *(undefined4 *)(param_1 + 0x1e68) = 0;
      *puVar2 = 0;
      *(undefined4 *)(((unsigned char *)0x00001488) + param_1) = 0;
    }
    FUN_00088190();
    uVar1 = 1;
  }
  return uVar1;
}

/* FUN_0004aa90 @ 0x4aa90 (196 bytes) */
int FUN_0004aa90(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  
  if (((unsigned char *)0x000013b2)[param_1] != '\0') {
    iVar3 = 0;
    puVar2 = param_2;
    do {
      puVar1 = puVar2 + 1;
      iVar3 = iVar3 + 1;
      puVar2[0x22] = puVar2[0x22] & 0xfe001fc0 | 0xd10000;
      puVar2 = puVar2 + 1;
      *puVar2 = *puVar1 & 0xfffcffef;
    } while (iVar3 < (int)(uint)(byte)((unsigned char *)0x000013b2)[param_1]);
  }
  param_2[0x87] = 0;
  param_2[0x83] = 1;
  param_2[0x84] = 0;
  param_2[0x86] = 0;
  *param_2 = *param_2 & 0xfffffff0;
  param_2[1] = param_2[1] & 0xfffc0fff | 0x10000;
  param_2[0x22] = param_2[0x22] & 0xffffe03f;
  param_2[0x82] = param_2[0x82] & 0xfffff800 | 0x80;
  return;
}

/* FUN_0004ab60 @ 0x4ab60 (304 bytes) */
int FUN_0004ab60(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  FUN_000b6020(param_1,(*(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x20
                                 ) ^ 0x800000) >> 0x17 & 1,1);
  *(uint *)(((unsigned char *)0x00001544) + *(int *)(param_1 + 0x1e60)) =
       *(uint *)(((unsigned char *)0x00001544) + *(int *)(param_1 + 0x1e60)) & 0xffc0003f | 0x40;
  *(undefined4 *)(((unsigned char *)0x00001098) + *(int *)(param_1 + 0x1e60)) = 1;
  ((int (*)())FUN_0004aa90)(param_1,((unsigned char *)0x000010ec) + *(int *)(param_1 + 0x1e60));
  *(undefined4 *)(param_1 + 0x1e84) = 0;
  *(undefined4 *)(param_1 + 0x277c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1e64) = 0;
  *(undefined4 *)(param_1 + 0x1e80) = 0;
  if (0 < *(int *)(param_1 + 0x1e74)) {
    iVar1 = 0;
    do {
      iVar2 = iVar1 * 4;
      iVar1 = iVar1 + 1;
      ((unsigned char *)0x000010e9)[*(int *)(iVar2 + *(int *)(param_1 + 0x1e7c))] = 0;
      ((unsigned char *)0x000010ea)[*(int *)(iVar2 + *(int *)(param_1 + 0x1e7c))] = 0;
    } while (iVar1 < *(int *)(param_1 + 0x1e74));
  }
  *(undefined4 *)(param_1 + 0x1e74) = 0;
  if (*(int *)(param_1 + 0x1e5c) == 0) {
    *(undefined4 *)(param_1 + 0x1e5c) = *(undefined4 *)(param_1 + 0x1e60);
  }
  *(undefined4 *)(param_1 + 0x1e84) = 0;
  *(undefined4 *)(param_1 + 0x1e80) = 0;
  iVar2 = 8;
  iVar1 = 0;
  do {
    *(undefined4 *)(param_1 + 0x1e88 + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

/* FUN_0004ac90 @ 0x4ac90 (1272 bytes) */
int FUN_0004ac90(param_1)
  int param_1;
{
  bool bVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  code *pcVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  code *pcVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  int iVar15;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  
  piVar10 = *(int **)(param_1 + 0x1e5c);
  piVar10[0x42e] = piVar10[0x42e] & 0xffff00ff;
  fVar2 = FLOAT_001aa0d4;
  uVar12 = (uint)*(byte *)(param_1 + 0x2b);
  if ((uint)(byte)((unsigned char *)0x000013b2)[param_1] < (uint)*(byte *)(param_1 + 0x2b)) {
    uVar12 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
  }
  bVar1 = false;
  if (uVar12 != 0) {
    uVar11 = 0;
    iVar13 = param_1;
    do {
      iVar4 = *(int *)(((unsigned char *)0x000013f8) + iVar13);
      if (((iVar4 != 0) && (*(short *)(iVar4 + 0x38) == 0x1902)) &&
         (*(float *)(iVar4 + 0x50) != fVar2)) {
        iVar4 = ((int)uVar11 >> 2) + (uint)((int)uVar11 < 0 && (uVar11 & 3) != 0);
        if (iVar4 == 1) {
          iVar15 = ((uint (*)())FUN_0004a7d0)();
          piVar10[0x68] = iVar15;
        }
        else if (iVar4 < 2) {
          if (iVar4 == 0) {
            iVar15 = ((uint (*)())FUN_0004a7d0)();
            piVar10[99] = iVar15;
          }
        }
        else if (iVar4 == 2) {
          iVar15 = ((uint (*)())FUN_0004a7d0)();
          piVar10[0x6d] = iVar15;
        }
        else if (iVar4 == 3) {
          iVar15 = ((uint (*)())FUN_0004a7d0)();
          piVar10[0x72] = iVar15;
        }
        uVar3 = iVar4 + 0x10U >> 3 & 0x1ffffffc;
        bVar1 = true;
        *(uint *)((int)piVar10 + (int)(((unsigned char *)0x000010b8) + uVar3)) =
             1 << (iVar4 + 0x10U & 0x1f) | *(uint *)((int)piVar10 + (int)(((unsigned char *)0x000010b8) + uVar3));
      }
      uVar11 = uVar11 + 1;
      iVar13 = iVar13 + 4;
    } while (uVar12 != uVar11);
  }
  if (*(char *)(param_1 + 0x121) != '\0') {
    iVar13 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    local_58 = *(undefined4 *)(((unsigned char *)0x00002de0) + iVar13);
    local_54 = *(undefined4 *)(((unsigned char *)0x00002de4) + iVar13);
    local_50 = *(undefined4 *)(((unsigned char *)0x00002de8) + iVar13);
    local_4c = 0;
    local_48 = FLOAT_001aa114 /
               (*(float *)(((unsigned char *)0x00002df8) + iVar13) - *(float *)(((unsigned char *)0x00002df4) + iVar13));
    local_44 = *(float *)(((unsigned char *)0x00002df8) + iVar13) * *(float *)(((unsigned char *)0x00002dfc) + iVar13);
    local_40 = (float)((double)*(float *)(((unsigned char *)0x00002df0) + iVar13) / DOUBLE_001aa268);
    local_3c = (float)((double)*(float *)(((unsigned char *)0x00002df0) + iVar13) / DOUBLE_001aa270);
    (**(code **)(((unsigned char *)0x00001280) + param_1))
              (param_1,0,
               *(undefined4 *)(((unsigned char *)0x00003878) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(param_1 + 0x1e5c)))
               ,*(undefined4 *)
                 (((unsigned char *)0x00003878) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(param_1 + 0x1e5c))),&local_58,1,
               1);
    (**(code **)(((unsigned char *)0x00001280) + param_1))
              (param_1,0,
               *(undefined4 *)(((unsigned char *)0x0000387c) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(param_1 + 0x1e5c)))
               ,*(undefined4 *)
                 (((unsigned char *)0x0000387c) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(param_1 + 0x1e5c))),&local_48,1,
               1);
  }
  FUN_000b5190(param_1,*(int *)(param_1 + 0x1e5c) + 0x1784,
               ((unsigned char *)0x00001660) + *(int *)(param_1 + 0x1e5c));
  uVar12 = (uint)*(byte *)(param_1 + 0x20);
  if (uVar12 != 0) {
    iVar13 = 0;
    iVar4 = param_1 + 0x28b4;
    do {
      if ((uVar12 & 1) != 0) {
        (**(code **)(((unsigned char *)0x00001280) + param_1))(param_1,0,iVar13 + 0x14,iVar13 + 0x14,iVar4,1,1);
      }
      uVar12 = uVar12 >> 1;
      iVar13 = iVar13 + 1;
      iVar4 = iVar4 + 0x10;
    } while (uVar12 != 0);
  }
  if ((bVar1) &&
     (*(undefined1 *)((int)piVar10 + 0x10eb) = 0, piVar10 == *(int **)(param_1 + 0x1e64))) {
    if (*(int *)(param_1 + 0x23e0) == 0) {
      iVar13 = piVar10[0xdac];
      puVar14 = (uint *)(piVar10 + 0x43b);
      piVar6 = piVar10 + 0x423;
      piVar7 = piVar10;
    }
    else {
      iVar13 = piVar10[0xdaf];
      puVar14 = (uint *)(piVar10 + 0x4c6);
      piVar6 = piVar10 + 0x424;
      piVar7 = piVar10 + 7;
    }
    *(int **)(param_1 + 0x1e64) = piVar10;
    if (*piVar7 == 0) {
      iVar4 = piVar7[1];
      *(undefined4 *)(FUN_00002348 + param_1 + 4) = 1;
      *(int *)(param_1 + 0x2350) = iVar4;
      *(int *)(param_1 + 0x2338) = *piVar6;
      *piVar7 = 1;
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x100000;
    }
    if (*(char *)((int)piVar10 + 0x10eb) == '\0') {
      iVar15 = 8;
      iVar4 = param_1;
      piVar7 = piVar10;
      do {
        piVar6 = piVar7 + 0x42e;
        piVar7 = piVar7 + 1;
        *(int *)(iVar4 + 0x1e88) = *piVar6;
        iVar4 = iVar4 + 4;
        iVar15 = iVar15 + -1;
      } while (iVar15 != 0);
      uVar12 = 0;
      pcVar5 = FUN_00001f30 + param_1;
      piVar6 = piVar10 + 0x20;
      piVar7 = piVar10;
      do {
        uVar11 = piVar7[0x42e];
        if (uVar11 != 0) {
          piVar8 = piVar6 + 3;
          pcVar9 = pcVar5 + 8;
          uVar3 = uVar12;
          do {
            if (((uVar11 & 1) != 0) && ((1 << (uVar3 & 0x3f) & piVar10[0x436]) == 0)) {
              *(int *)pcVar9 = *piVar8;
              *(int *)(pcVar9 + 4) = piVar8[1];
              *(int *)(pcVar9 + 8) = piVar8[2];
              *(int *)(pcVar9 + 0xc) = piVar8[3];
            }
            uVar11 = uVar11 >> 1;
            uVar3 = uVar3 + 1;
            piVar8 = piVar8 + 4;
            pcVar9 = pcVar9 + 0x10;
          } while (uVar11 != 0);
        }
        bVar1 = uVar12 != 0xe0;
        piVar7 = piVar7 + 1;
        piVar6 = piVar6 + 0x80;
        pcVar5 = pcVar5 + 0x200;
        uVar12 = uVar12 + 0x20;
      } while (bVar1);
      *(undefined1 *)((int)piVar10 + 0x10eb) = 1;
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000000;
    }
    if (puVar14[0x85] == 0) {
      *(uint *)(param_1 + 0x1f2c) = puVar14[0x82];
      uVar12 = *puVar14;
      *(int *)(param_1 + 0x1f34) = iVar13;
      *(uint *)(FUN_00001f30 + param_1) = uVar12 & 0xffffff1f;
      _memcpy((void *)(param_1 + 0x1ea8),puVar14 + 1,iVar13 << 2);
      uVar3 = puVar14[0x23];
      uVar11 = puVar14[0x24];
      uVar12 = puVar14[0x25];
      *(uint *)(param_1 + 0x1ee8) = puVar14[0x22];
      *(uint *)(param_1 + 0x1eec) = uVar3;
      *(uint *)(param_1 + 0x1ef0) = uVar11;
      *(uint *)(param_1 + 0x1ef4) = uVar12;
      uVar3 = puVar14[0x26];
      uVar11 = puVar14[0x27];
      uVar12 = puVar14[0x28];
      *(uint *)(param_1 + 0x1f04) = puVar14[0x29];
      *(uint *)(param_1 + 0x1ef8) = uVar3;
      *(uint *)(param_1 + 0x1efc) = uVar11;
      *(uint *)(param_1 + 0x1f00) = uVar12;
      puVar14[0x85] = 1;
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x80000000;
    }
  }
  return;
}

/* FUN_0004b190 @ 0x4b190 (700 bytes) */
int FUN_0004b190(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  char cVar4;
  code *pcVar3;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  
  iVar7 = *(int *)(param_1 + 0x276c);
  if (((*(uint *)(param_1 + 0x44) & 0x20000) == 0) || (*(int *)(param_1 + 0x1e70) == 0)) {
LAB_0004b200:
    uVar8 = 1;
    iVar9 = *(int *)(param_1 + 0x1e5c);
    bVar2 = false;
  }
  else {
    if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
      cVar4 = ((unsigned char *)0x00001136)[param_1];
    }
    else {
      cVar4 = ((unsigned char *)0x000011d0)[param_1];
    }
    if (cVar4 != '\0') goto LAB_0004b200;
    uVar8 = 0;
    iVar9 = *(int *)(param_1 + 0x1e70);
    bVar2 = true;
  }
  bVar1 = param_2 == 0;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x23e0) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x23e0) = 1;
  }
  puVar5 = *(undefined1 **)(((unsigned char *)0x000036c0) + iVar9);
  if (puVar5 == (undefined1 *)0x0) {
    return;
  }
  if (param_2 == *(int *)(((unsigned char *)0x000010e4) + iVar9)) {
    if (((unsigned char *)0x000036c4)[iVar9] == '\0') {
      if (!bVar1) {
        cVar4 = '\0';
        goto LAB_0004b2f8;
      }
      cVar4 = ((unsigned char *)0x000010e9)[iVar9];
    }
    else {
      if (bVar1) goto LAB_0004b340;
      cVar4 = ((unsigned char *)0x000010ea)[iVar9];
    }
    if (cVar4 != '\0') {
      return;
    }
    if (bVar2) {
      *puVar5 = (char)uVar8;
      ((unsigned char *)0x000010e9)[iVar9] = 0;
      ((unsigned char *)0x000010ea)[iVar9] = 0;
LAB_0004b42c:
      FUN_00088190(param_1,*(undefined4 *)(((unsigned char *)0x000036c0) + iVar9));
      return;
    }
    iVar7 = *(int *)(param_1 + 0x1e5c);
    ((unsigned char *)0x000010e9)[iVar7] = 0;
    ((unsigned char *)0x000010ea)[iVar7] = 0;
    (**(code **)(param_1 + 0x294c))(param_1);
    pcVar3 = *(code **)(((unsigned char *)0x00001330) + param_1);
    uVar8 = *(undefined4 *)(param_1 + 0x1930);
  }
  else {
    if (!bVar1) {
      cVar4 = ((unsigned char *)0x000036c4)[iVar9];
LAB_0004b2f8:
      if (cVar4 == '\0') {
        if (bVar2) {
          FUN_00087e80(param_1,0,puVar5,puVar5 + 4);
        }
        else {
          FUN_000b6580(param_1,1);
        }
        ((unsigned char *)0x000036c4)[iVar9] = 1;
      }
    }
LAB_0004b340:
    *(int *)(((unsigned char *)0x000010e4) + iVar9) = param_2;
    *(int *)(((unsigned char *)0x00001528) + iVar9) = param_2;
    *(int *)(((unsigned char *)0x000012fc) + iVar9) = param_2;
    if (param_2 == 2) {
      iVar7 = iVar7 << 2;
      uVar6 = 4;
    }
    else {
      iVar7 = iVar7 * 4;
      uVar6 = (*(uint *)(((unsigned char *)0x000013e0) + iVar7 + iVar9) >> 6 & 0x3f) + 1 & 0x3f;
    }
    *(uint *)(((unsigned char *)0x000013e0) + iVar7 + iVar9) =
         uVar6 << 0xc | *(uint *)(((unsigned char *)0x000013e0) + iVar7 + iVar9) & 0xff000fff | 0xfc0000;
    if (bVar2) {
      **(undefined1 **)(((unsigned char *)0x000036c0) + iVar9) = (char)uVar8;
      ((unsigned char *)0x000010e9)[iVar9] = 0;
      ((unsigned char *)0x000010ea)[iVar9] = 0;
      *(undefined4 *)(param_1 + 0x1e68) = uVar8;
      goto LAB_0004b42c;
    }
    iVar7 = *(int *)(param_1 + 0x1e5c);
    ((unsigned char *)0x000010e9)[iVar7] = 0;
    ((unsigned char *)0x000010ea)[iVar7] = 0;
    *(undefined4 *)(param_1 + 0x1e68) = 0;
    (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,1);
    (**(code **)(param_1 + 0x294c))(param_1,iVar7);
    pcVar3 = *(code **)(((unsigned char *)0x00001330) + param_1);
    uVar8 = *(undefined4 *)(param_1 + 0x1930);
  }
  (*pcVar3)(param_1,uVar8);
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) & 0x3fefffff;
  return;
}

/* FUN_0004b480 @ 0x4b480 (148 bytes) */
int FUN_0004b480(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  iVar1 = param_2 * 4 + param_1;
  if (*(int *)(((unsigned char *)0x00001448) + iVar1) != 0) {
    uVar3 = *(undefined4 *)(param_1 + 0x1930);
    *(undefined4 *)(param_1 + 0x23e0) = 0;
    **(undefined1 **)(((unsigned char *)0x00001448) + iVar1) = 0;
    (**(code **)(((unsigned char *)0x00001290) + param_1))(param_1,*(undefined4 *)(((unsigned char *)0x00001448) + iVar1));
    pcVar2 = *(code **)(((unsigned char *)0x00001330) + param_1);
    *(uint *)(param_1 + 0x1f2c) = *(uint *)(param_1 + 0x1f2c) & 0xfffff800 | 0x80;
    (*pcVar2)(param_1,0xc0100000);
    *(undefined4 *)(param_1 + 0x1930) = uVar3;
  }
  return;
}

/* FUN_0004b5d0 @ 0x4b5d0 (296 bytes) */
int FUN_0004b5d0(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  ((int (*)())FUN_0004a990)();
  if ((param_1 != 0) && (iVar5 = *(int *)(((unsigned char *)0x000036c0) + param_2), iVar5 != 0)) {
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0xc));
    *(undefined4 *)(iVar5 + 0xc) = 0;
    iVar5 = *(int *)(((unsigned char *)0x000036c0) + param_2);
    iVar3 = *(int *)(param_1 + 0x1e74);
    while (0 < iVar3) {
      piVar1 = *(int **)(param_1 + 0x1e7c);
      iVar2 = 0;
      if (param_2 != *piVar1) {
        iVar2 = 0;
        iVar4 = iVar3;
        do {
          iVar2 = iVar2 + 1;
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) goto LAB_0004b6a8;
        } while (piVar1[iVar2] != param_2);
      }
      iVar3 = iVar3 + -1;
      *(int *)(param_1 + 0x1e74) = iVar3;
      if (iVar3 == iVar2) break;
      if (iVar2 < iVar3) {
        iVar4 = iVar2 << 2;
        while( true ) {
          iVar2 = iVar2 + 1;
          *(undefined4 *)(iVar4 + (int)piVar1) = *(undefined4 *)((int)piVar1 + iVar4 + 4);
          iVar4 = iVar4 + 4;
          iVar3 = *(int *)(param_1 + 0x1e74);
          if (iVar3 <= iVar2) break;
          piVar1 = *(int **)(param_1 + 0x1e7c);
        }
      }
    }
LAB_0004b6a8:
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(((unsigned char *)0x000036c0) + param_2));
    if (param_2 != iVar5 + 0x124) {
      *(undefined4 *)(((unsigned char *)0x000036c0) + param_2) = 0;
    }
  }
  return;
}

/* FUN_0004b710 @ 0x4b710 (188 bytes) */
int FUN_0004b710(param_1)
  int param_1;
{
  int iVar1;
  undefined *puVar2;
  
  if (*(short *)(param_1 + 0x1e6c) != 0) {
    iVar1 = 0;
    puVar2 = (undefined *)0x0;
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(puVar2 + *(int *)(param_1 + 0x1e60) + 0x1780) = 0;
      ((int (*)())FUN_0004b5d0)(param_1);
      puVar2 = ((unsigned char *)0x00003754) + (int)puVar2;
    } while (iVar1 < (int)(uint)*(ushort *)(param_1 + 0x1e6c));
  }
  _free(*(void **)(param_1 + 0x1e60));
  _memset(*(void **)(((unsigned char *)0x00001114) + param_1),0xff,(uint)*(ushort *)(((unsigned char *)0x00001110) + param_1) << 1);
  *(undefined2 *)(param_1 + 0x1e6c) = 0;
  *(undefined4 *)(param_1 + 0x1e5c) = 0;
  *(undefined4 *)(param_1 + 0x1e80) = 0;
  *(undefined4 *)(param_1 + 0x1e84) = 0;
  *(undefined4 *)(param_1 + 0x1e60) = 0;
  return;
}

/* FUN_0004b980 @ 0x4b980 (616 bytes) */
int FUN_0004b980(param_1, param_2)
  int param_1;
  int param_2;
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  
  uVar13 = (uint)*(ushort *)(((unsigned char *)0x00001110) + param_1);
  iVar15 = *(int *)(param_1 + 0x1e60);
  if (uVar13 != 0x2811) {
    *(short *)(((unsigned char *)0x00001110) + param_1) = (short)(uVar13 + param_2);
    if (0x2811 < (uVar13 + param_2 & 0xffff)) {
      *(undefined2 *)(((unsigned char *)0x00001110) + param_1) = 0x2811;
    }
    pvVar5 = (void *)(**(code **)(param_1 + 0xc))((uint)*(ushort *)(((unsigned char *)0x00001110) + param_1) << 1);
    _memset(pvVar5,0xff,(uint)*(ushort *)(((unsigned char *)0x00001110) + param_1) << 1);
    if (uVar13 == 0) {
      iVar6 = *(int *)(((unsigned char *)0x00001114) + param_1);
    }
    else {
      iVar6 = *(int *)(((unsigned char *)0x00001114) + param_1);
      uVar14 = 0;
      do {
        uVar12 = (uint)*(ushort *)(uVar14 * 2 + iVar6);
        if (uVar12 != 0xffff) {
          do {
            iVar6 = iVar15 + uVar12 * 0x3754;
            puVar7 = (uint *)(((unsigned char *)0x000015c8) + iVar6);
            puVar9 = (uint *)(((unsigned char *)0x00001544) + iVar6);
            if (puVar7 < ((unsigned char *)0x00001570) + iVar6) {
              uVar8 = 0;
            }
            else {
              uVar8 = 0;
              puVar11 = (uint *)(((unsigned char *)0x00001570) + iVar6);
              puVar10 = puVar9;
              do {
                puVar9 = puVar11;
                uVar8 = uVar8 ^ *puVar10 ^ (puVar10[1] << 3 | puVar10[1] >> 0x1d) ^
                        (puVar10[2] << 6 | puVar10[2] >> 0x1a) ^
                        (puVar10[3] << 9 | puVar10[3] >> 0x17) ^
                        (puVar10[4] << 0xc | puVar10[4] >> 0x14) ^
                        (puVar10[5] << 0xf | puVar10[5] >> 0x11) ^
                        (puVar10[6] << 0x12 | puVar10[6] >> 0xe) ^
                        (puVar10[7] << 0x15 | puVar10[7] >> 0xb) ^
                        (puVar10[8] << 0x18 | puVar10[8] >> 8) ^
                        (puVar10[9] << 0x1b | puVar10[9] >> 5) ^
                        (puVar10[10] << 0x1e | puVar10[10] >> 2);
                puVar11 = puVar9 + 0xb;
                puVar10 = puVar9;
              } while (puVar9 + 0xb <= puVar7);
            }
            puVar11 = puVar9 + 5;
            if (puVar7 < puVar11) {
              uVar4 = 0;
              puVar11 = puVar9;
            }
            else {
              uVar4 = 0xf;
              uVar8 = uVar8 ^ *puVar9 ^ (puVar9[1] << 3 | puVar9[1] >> 0x1d) ^
                      (puVar9[2] << 6 | puVar9[2] >> 0x1a) ^ (puVar9[3] << 9 | puVar9[3] >> 0x17) ^
                      (puVar9[4] << 0xc | puVar9[4] >> 0x14);
            }
            for (; puVar11 < puVar7; puVar11 = puVar11 + 1) {
              uVar3 = uVar4 & 0x1f;
              uVar4 = uVar4 + 3;
              uVar8 = uVar8 ^ (*puVar11 << uVar3 | *puVar11 >> 0x20 - uVar3);
            }
            uVar1 = *(ushort *)(((unsigned char *)0x000015c8) + iVar6);
            iVar2 = (uVar8 - (uVar8 / *(ushort *)(((unsigned char *)0x00001110) + param_1)) *
                             (uint)*(ushort *)(((unsigned char *)0x00001110) + param_1)) * 2;
            *(undefined2 *)(((unsigned char *)0x000015c8) + iVar6) = *(undefined2 *)((int)pvVar5 + iVar2);
            *(short *)((int)pvVar5 + iVar2) = (short)uVar12;
            uVar12 = (uint)uVar1;
          } while (uVar1 != 0xffff);
          iVar6 = *(int *)(((unsigned char *)0x00001114) + param_1);
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 < uVar13);
    }
    (**(code **)(param_1 + 0x18))(iVar6);
    *(void **)(((unsigned char *)0x00001114) + param_1) = pvVar5;
  }
  return;
}

/* FUN_0004bbf0 @ 0x4bbf0 (1244 bytes) */
int FUN_0004bbf0(param_1)
  int param_1;
{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  uint *puVar8;
  undefined4 uVar9;
  void *pvVar10;
  uint uVar11;
  uint *puVar12;
  int iVar13;
  uint *puVar14;
  uint *puVar15;
  uint *puVar16;
  undefined *puVar17;
  uint uVar18;
  
  uVar18 = 0x11;
  puVar8 = (uint *)(param_1 + 0x18a4);
  if (*(byte *)(param_1 + 0x2b) < 9) {
    uVar18 = (uint)*(byte *)(param_1 + 0x2b) * 2 + 1;
  }
  cVar2 = ((unsigned char *)0x00001112)[param_1];
  if (cVar2 == '\0') {
    puVar12 = (uint *)(param_1 + 0x18e8);
    uVar7 = *(ushort *)(((unsigned char *)0x00001110) + param_1);
    if (puVar12 < (uint *)(param_1 + 0x18d0)) {
      uVar5 = 0;
      puVar14 = puVar8;
    }
    else {
      uVar5 = 0;
      puVar16 = (uint *)(param_1 + 0x18d0);
      puVar15 = puVar8;
      do {
        puVar14 = puVar16;
        uVar5 = uVar5 ^ *puVar15 ^ (puVar15[1] << 3 | puVar15[1] >> 0x1d) ^
                (puVar15[2] << 6 | puVar15[2] >> 0x1a) ^ (puVar15[3] << 9 | puVar15[3] >> 0x17) ^
                (puVar15[4] << 0xc | puVar15[4] >> 0x14) ^ (puVar15[5] << 0xf | puVar15[5] >> 0x11)
                ^ (puVar15[6] << 0x12 | puVar15[6] >> 0xe) ^
                (puVar15[7] << 0x15 | puVar15[7] >> 0xb) ^ (puVar15[8] << 0x18 | puVar15[8] >> 8) ^
                (puVar15[9] << 0x1b | puVar15[9] >> 5) ^ (puVar15[10] << 0x1e | puVar15[10] >> 2);
        puVar16 = puVar14 + 0xb;
        puVar15 = puVar14;
      } while (puVar14 + 0xb <= puVar12);
    }
    puVar16 = puVar14 + 5;
    if (puVar12 < puVar16) {
      uVar11 = 0;
      puVar16 = puVar14;
    }
    else {
      uVar11 = 0xf;
      uVar5 = uVar5 ^ *puVar14 ^ (puVar14[1] << 3 | puVar14[1] >> 0x1d) ^
              (puVar14[2] << 6 | puVar14[2] >> 0x1a) ^ (puVar14[3] << 9 | puVar14[3] >> 0x17) ^
              (puVar14[4] << 0xc | puVar14[4] >> 0x14);
    }
    for (; puVar16 < puVar12; puVar16 = puVar16 + 1) {
      uVar3 = uVar11 & 0x1f;
      uVar11 = uVar11 + 3;
      uVar5 = uVar5 ^ (*puVar16 << uVar3 | *puVar16 >> 0x20 - uVar3);
    }
    uVar5 = uVar5 - (uVar5 / uVar7) * (uint)uVar7;
  }
  else {
    uVar7 = *(ushort *)(((unsigned char *)0x00001110) + param_1);
    uVar5 = *(int *)(param_1 + 0x18a8) + *(int *)(param_1 + 0x18b0) + *(int *)(param_1 + 0x18b8) +
            *(int *)(param_1 + 0x18c0);
    uVar5 = uVar5 - (uVar5 / uVar7) * (uint)uVar7;
  }
  iVar6 = *(int *)(((unsigned char *)0x00001114) + param_1);
  iVar4 = (uVar5 & 0xffff) * 2;
  *(undefined4 *)(param_1 + 0x277c) = 0xffffffff;
  uVar5 = (uint)*(ushort *)(iVar6 + iVar4);
  if (uVar5 == 0xffff) {
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    uVar11 = uVar5;
    do {
      uVar5 = uVar11;
      iVar6 = iVar6 + 1;
      iVar13 = *(int *)(param_1 + 0x1e60) + uVar5 * 0x3754;
      puVar17 = ((unsigned char *)0x00001544) + iVar13;
      if ((*puVar8 == *(uint *)(((unsigned char *)0x00001544) + iVar13) &&
          *(int *)(param_1 + 0x18a8) == *(int *)(((unsigned char *)0x00001548) + iVar13)) &&
          *(int *)(param_1 + 0x18ac) == *(int *)(((unsigned char *)0x0000154c) + iVar13)) {
        if (uVar18 < 4) {
LAB_0004bee0:
          *(int *)(param_1 + 0x1e5c) = iVar13;
          return 1;
        }
        if (*(int *)(((unsigned char *)0x00001550) + iVar13) == *(int *)(param_1 + 0x18b0) &&
            *(int *)(((unsigned char *)0x00001554) + iVar13) == *(int *)(param_1 + 0x18b4)) {
          uVar11 = 3;
          puVar12 = puVar8;
          do {
            uVar11 = uVar11 + 2;
            if (uVar18 <= uVar11) goto LAB_0004bee0;
            puVar14 = (uint *)(puVar17 + 0x18);
            puVar16 = puVar12 + 6;
            puVar15 = (uint *)(puVar17 + 0x14);
            puVar1 = puVar12 + 5;
            puVar17 = puVar17 + 8;
            puVar12 = puVar12 + 2;
          } while (*puVar15 == *puVar1 && *puVar16 == *puVar14);
        }
      }
      uVar11 = (uint)*(ushort *)(((unsigned char *)0x000015c8) + iVar13);
    } while (*(ushort *)(((unsigned char *)0x000015c8) + iVar13) != 0xffff);
  }
  if ((cVar2 == '\0') || (iVar6 < 7)) {
    if ((iVar6 < 8) || (0x2810 < uVar7)) {
      uVar7 = *(ushort *)(param_1 + 0x1e6c);
      if (0x400 < uVar7) {
        uVar5 = 0;
        ((int (*)())FUN_0004b710)(param_1);
        *(undefined2 *)(param_1 + 0x1e6c) = 1;
        pvVar10 = _malloc(0x3754);
        *(void **)(param_1 + 0x1e60) = pvVar10;
        _memset(pvVar10,0,0x3754);
        ((int (*)())FUN_0004ab60)(param_1);
        *(undefined2 *)(((unsigned char *)0x000015c8) + *(int *)(param_1 + 0x1e60)) = 0xffff;
        uVar7 = *(ushort *)(param_1 + 0x1e6c);
      }
      *(ushort *)(param_1 + 0x1e6c) = uVar7 + 1;
      if (*(int *)(param_1 + 0x1e68) != 0) {
        ((unsigned char *)0x000010e9)[*(int *)(param_1 + 0x1e68)] = 0;
        ((unsigned char *)0x000010ea)[*(int *)(param_1 + 0x1e68)] = 0;
        ((unsigned char *)0x000010eb)[*(int *)(param_1 + 0x1e68)] = 0;
        *(undefined4 *)(param_1 + 0x1e68) = 0;
      }
      if (0 < *(int *)(param_1 + 0x1e74)) {
        iVar6 = 0;
        do {
          iVar13 = iVar6 * 4;
          iVar6 = iVar6 + 1;
          ((unsigned char *)0x000010e9)[*(int *)(*(int *)(param_1 + 0x1e7c) + iVar13)] = 0;
          ((unsigned char *)0x000010ea)[*(int *)(*(int *)(param_1 + 0x1e7c) + iVar13)] = 0;
        } while (iVar6 < *(int *)(param_1 + 0x1e74));
      }
      *(undefined4 *)(param_1 + 0x1e74) = 0;
      pvVar10 = _realloc(*(void **)(param_1 + 0x1e60),(uint)*(ushort *)(param_1 + 0x1e6c) * 0x3754);
      *(void **)(param_1 + 0x1e60) = pvVar10;
      if (pvVar10 == (void *)0x0) {
        return 0;
      }
      uVar7 = *(ushort *)(param_1 + 0x1e6c);
      iVar6 = *(int *)(((unsigned char *)0x00001114) + param_1);
      *(uint *)(param_1 + 0x1e5c) = (int)pvVar10 + (uint)uVar7 * 0x3754 + -0x3754;
      if (*(short *)(iVar4 + iVar6) == -1) {
        *(ushort *)(iVar4 + iVar6) = uVar7 - 1;
      }
      else {
        *(ushort *)((int)pvVar10 + uVar5 * 0x3754 + 0x15c8) = uVar7 - 1;
      }
      _memset(*(void **)(param_1 + 0x1e5c),0,0x3754);
      *(undefined2 *)(((unsigned char *)0x000015c8) + *(int *)(param_1 + 0x1e5c)) = 0xffff;
      _memcpy(((unsigned char *)0x00001544) + *(int *)(param_1 + 0x1e5c),(void *)(param_1 + 0x18a4),0x84);
      return 0;
    }
    if (cVar2 == '\0') {
      ((int (*)())FUN_0004b980)(param_1,0x313);
      goto LAB_0004bf48;
    }
  }
  ((int (*)())FUN_0004b980)(param_1,0);
  ((unsigned char *)0x00001112)[param_1] = 0;
LAB_0004bf48:
  uVar9 = ((int (*)())FUN_0004bbf0)(param_1);
  return uVar9;
}

/* FUN_0004c100 @ 0x4c100 (336 bytes) */
int FUN_0004c100(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  iVar2 = *(int *)(param_2 + 0x1e64);
  if (iVar2 != 0) {
    if (*(int *)(param_2 + 0x23e0) == 0) {
      uVar4 = *(uint *)(((unsigned char *)0x000036a8) + iVar2);
      puVar5 = (undefined4 *)(iVar2 + 4);
      puVar1 = ((unsigned char *)0x000010ec);
    }
    else {
      uVar4 = *(uint *)(((unsigned char *)0x000036b4) + iVar2);
      puVar5 = (undefined4 *)(iVar2 + 0x20);
      puVar1 = ((unsigned char *)0x00001318);
    }
    *(undefined4 *)(param_1 + 0x250) = *(undefined4 *)(puVar1 + iVar2 + 0x44);
    *(undefined4 *)(param_1 + 600) = *(undefined4 *)(puVar1 + iVar2 + 0x48);
    uVar3 = puVar5[2];
    *(undefined4 *)(param_1 + 0x218) = 0;
    *(undefined4 *)(param_1 + 0x220) = uVar3;
    *(undefined4 *)(param_1 + 0x210) = puVar5[3];
    *(undefined4 *)(param_1 + 0x208) = *puVar5;
    *(undefined4 *)(param_1 + 0x200) = puVar5[1];
    if (uVar4 != 0) {
      *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)puVar5[4];
      *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(puVar5[4] + 4);
      *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(puVar5[4] + 8);
      *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(puVar5[4] + 0xc);
      *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(puVar5[4] + 0x10);
      *(undefined4 *)(param_1 + 0x130) = *(undefined4 *)(puVar5[4] + 0x14);
      if (1 < uVar4) {
        *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(puVar5[4] + 0x18);
        *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(puVar5[4] + 0x1c);
        *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(puVar5[4] + 0x20);
        *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(puVar5[4] + 0x24);
        *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(puVar5[4] + 0x28);
        *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(puVar5[4] + 0x2c);
        return;
      }
      goto LAB_0004c1ac;
    }
  }
  *(undefined4 *)(param_1 + 0x1fc) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x104) = 0xc00a1000;
  *(undefined4 *)(param_1 + 0x24c) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x254) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x21c) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x214) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x20c) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x204) = 0xc0001000;
LAB_0004c1ac:
  *(undefined4 *)(param_1 + 0x134) = 0xc00a1000;
  return;
}

/* FUN_0004c260 @ 0x4c260 (732 bytes) */
int FUN_0004c260(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined *puVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  
  if (param_3 == 0) {
    cVar2 = ((unsigned char *)0x000010e9)[param_2];
    iVar8 = *(int *)(((unsigned char *)0x000036a8) + param_2);
    puVar11 = (undefined4 *)(param_2 + 4);
    puVar12 = ((unsigned char *)0x000010ec);
  }
  else {
    cVar2 = ((unsigned char *)0x000010ea)[param_2];
    iVar8 = *(int *)(((unsigned char *)0x000036b4) + param_2);
    puVar11 = (undefined4 *)(param_2 + 0x20);
    puVar12 = ((unsigned char *)0x00001318);
  }
  puVar12 = puVar12 + param_2;
  if (iVar8 != 0) {
    if (cVar2 == '\0') {
      uVar15 = 0;
      puVar9 = puVar12 + 0x44;
      puVar7 = param_1 + 0xf;
      *param_1 = ((unsigned char *)0x00001181);
      dataCacheBlockTouch(puVar9);
      uVar5 = *puVar11;
      param_1[2] = ((unsigned char *)0x00001189);
      param_1[1] = uVar5;
      uVar5 = puVar11[1];
      param_1[4] = ((unsigned char *)0x00001188);
      param_1[6] = ((unsigned char *)0x0000118c);
      param_1[5] = 0;
      param_1[3] = uVar5;
      uVar5 = puVar11[2];
      param_1[8] = ((unsigned char *)0x0000118d);
      param_1[7] = uVar5;
      uVar5 = puVar11[3];
      param_1[10] = ((unsigned char *)0x0000118e);
      param_1[0xb] = 0;
      param_1[0xc] = ((unsigned char *)0x000010c1);
      param_1[9] = uVar5;
      param_1[0xd] = *(undefined4 *)(puVar12 + 0x44);
      param_1[0xe] = (*(uint *)(puVar12 + 0x44) & 0xf) << 0x10 | 0x10c8;
      uVar6 = *(uint *)(puVar12 + 0x44);
      uVar13 = uVar6 & 0xf;
      puVar12 = puVar9;
      if (uVar13 == 0) {
        uVar15 = 0;
      }
      else {
        do {
          uVar15 = uVar15 + 2;
          *puVar7 = *(undefined4 *)(puVar12 + 4);
          puVar7[1] = *(undefined4 *)(puVar12 + 8);
          puVar7 = puVar7 + 2;
          puVar12 = puVar12 + 8;
        } while (uVar15 < uVar13);
      }
      if ((uVar6 & 1) == 0) {
        *puVar7 = *(undefined4 *)(puVar9 + uVar15 * 4 + 4);
        puVar7 = puVar7 + 1;
      }
      param_1 = puVar7 + 3;
      puVar7[1] = 0;
      *puVar7 = ((unsigned char *)0x00001094);
      puVar7[2] = (iVar8 * 6 + -1) * 0x10000 | 0x9095;
      if (0 < iVar8) {
        iVar10 = 0;
        iVar14 = 0;
        do {
          iVar16 = 0;
          iVar17 = 6;
          puVar7 = param_1;
          do {
            iVar3 = iVar16 * 4;
            iVar16 = iVar16 + 1;
            *puVar7 = *(undefined4 *)(iVar3 + iVar14 + puVar11[4]);
            puVar7 = puVar7 + 1;
            iVar17 = iVar17 + -1;
          } while (iVar17 != 0);
          iVar10 = iVar10 + 1;
          param_1 = param_1 + 6;
          iVar14 = iVar14 + 0x18;
        } while (iVar8 != iVar10);
      }
    }
    if (((unsigned char *)0x000010eb)[param_2] == '\0') {
      dataCacheBlockTouch(param_2);
      uVar13 = 0x10000;
      uVar6 = 0;
      iVar10 = param_2 + 0x80;
      iVar8 = param_2;
      do {
        uVar15 = *(uint *)(((unsigned char *)0x000010b8) + iVar8);
        if (uVar15 != 0) {
          puVar11 = (undefined4 *)(iVar10 + 0xc);
          uVar4 = uVar6;
          do {
            if ((uVar15 & 1) != 0) {
              uVar13 = uVar4 & 0x1ff | uVar13 & 0xfffffe00;
              *param_1 = ((unsigned char *)0x00001094);
              param_1[2] = ((unsigned char *)0x00039095);
              param_1[1] = uVar13;
              param_1[3] = *puVar11;
              param_1[4] = puVar11[1];
              param_1[5] = puVar11[2];
              param_1[6] = puVar11[3];
              param_1 = param_1 + 7;
            }
            uVar15 = uVar15 >> 1;
            uVar4 = (uVar4 & 0x1ff) + 1;
            puVar11 = puVar11 + 4;
          } while (uVar15 != 0);
        }
        bVar1 = uVar6 != 0xe0;
        iVar8 = iVar8 + 4;
        iVar10 = iVar10 + 0x200;
        uVar6 = uVar6 + 0x20;
      } while (bVar1);
      uVar6 = *(uint *)(((unsigned char *)0x00003748) + param_2);
      if (uVar6 != 0) {
        puVar12 = ((unsigned char *)0x00001300);
        iVar8 = param_2;
        do {
          if ((uVar6 & 1) != 0) {
            *param_1 = puVar12;
            param_1[1] = *(undefined4 *)(((unsigned char *)0x000036c8) + iVar8);
            param_1 = param_1 + 2;
          }
          uVar6 = uVar6 >> 1;
          puVar12 = puVar12 + 1;
          iVar8 = iVar8 + 4;
        } while (uVar6 != 0);
      }
    }
    if (param_3 == 0) {
      ((unsigned char *)0x000010ea)[param_2] = 0;
      ((unsigned char *)0x000010e9)[param_2] = 1;
    }
    else {
      ((unsigned char *)0x000010e9)[param_2] = 0;
      ((unsigned char *)0x000010ea)[param_2] = 1;
    }
    ((unsigned char *)0x000010eb)[param_2] = 1;
  }
  return;
}

/* FUN_0004cde0 @ 0x4cde0 (72 bytes) */
int FUN_0004cde0(param_1)
  int param_1;
{
  if (*(void **)(param_1 + 0x10) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}

/* FUN_0004ce30 @ 0x4ce30 (680 bytes) */
int FUN_0004ce30(param_1)
  int param_1;
{
  short sVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  iVar4 = *(int *)(param_1 + 4);
  uVar7 = *(uint *)(param_1 + 0x1ae0);
  iVar6 = *(int *)(param_1 + 0x1ab0);
  iVar9 = *(int *)(iVar4 + 0x10);
  sVar1 = *(short *)(((unsigned char *)0x00002dc4) + iVar9);
  iVar8 = iVar4 + 0x30;
  if (*(int *)(iVar4 + 0x150) != 0) {
    iVar8 = *(int *)(iVar4 + 0x150);
  }
  if (((((((unsigned char *)0x00002dc8)[iVar9] == '\0') || (((unsigned char *)0x00002e44)[iVar9] == '\0')) || (sVar1 == 0x200))
      || (sVar1 == 0x202)) ||
     (((*(double *)(FUN_00001830 + iVar9) == DOUBLE_001aa200 &&
       (*(double *)(iVar9 + 0x1838) == DOUBLE_001aa200)) && (sVar1 == 0x203)))) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if (((*(char *)(iVar8 + 0xc5) == '\0') && (((unsigned char *)0x00002dc8)[iVar9] != '\0')) &&
     ((*(uint *)(param_1 + 0x44) & 0x200) == 0)) {
    switch(sVar1) {
    case 0x200:
    case 0x201:
    case 0x202:
    case 0x203:
      if ((*(uint *)(iVar8 + 0xc4) & 0xff00ff00) == 0) {
        bVar2 = true;
        iVar4 = 0x201;
      }
      else {
        bVar2 = false;
        iVar4 = 0x201;
      }
      break;
    case 0x204:
    case 0x205:
    case 0x206:
      if ((*(char *)(iVar8 + 0xc4) == '\0') && (*(char *)(iVar8 + 0xc6) != '\0')) {
        bVar2 = true;
        iVar4 = 0x204;
      }
      else {
        bVar2 = false;
        iVar4 = 0x204;
      }
      break;
    case 0x207:
      bVar2 = false;
      iVar4 = 0x207;
      break;
    default:
      bVar2 = false;
      iVar4 = 0x200;
    }
    if (((*(int *)(((unsigned char *)0x000031c0) + iVar9) == 0) ||
        ((((*(short *)(((unsigned char *)0x000031a2) + iVar9) == 0x1e00 &&
           (*(short *)(((unsigned char *)0x000031a4) + iVar9) == 0x1e00)) &&
          (*(short *)(((unsigned char *)0x000031ba) + iVar9) == 0x1e00)) &&
         (*(short *)(((unsigned char *)0x000031bc) + iVar9) == 0x1e00)))) && (!bVar2)) {
      if (iVar4 == 0x204) {
        uVar5 = *(uint *)(param_1 + 0x1ae0) | 3;
        *(uint *)(param_1 + 0x1ae0) = uVar5;
        *(uint *)(param_1 + 0x1ab0) = *(uint *)(param_1 + 0x1ab0) | 3;
      }
      else if (iVar4 == 0x207) {
        uVar5 = *(uint *)(param_1 + 0x1ae0) & 0xfffffffe;
        *(uint *)(param_1 + 0x1ae0) = uVar5;
        *(uint *)(param_1 + 0x1ab0) = *(uint *)(param_1 + 0x1ab0) | 1;
      }
      else {
        uVar5 = *(uint *)(param_1 + 0x1ae0) & 0xfffffffd | 1;
        *(uint *)(param_1 + 0x1ae0) = uVar5;
        *(uint *)(param_1 + 0x1ab0) = *(uint *)(param_1 + 0x1ab0) & 0xfffffffd | 1;
      }
      *(byte *)(iVar8 + 0xc6) = (byte)((uVar5 ^ 2) >> 1) & 1;
      if (bVar3) {
        *(undefined1 *)(iVar8 + 0xc4) = 0;
        uVar5 = *(uint *)(param_1 + 0x1ae0);
      }
      else {
        uVar5 = *(uint *)(param_1 + 0x1ae0);
      }
      goto LAB_0004d0d0;
    }
  }
  uVar5 = *(uint *)(param_1 + 0x1ae0) & 0xfffffffe;
  *(uint *)(param_1 + 0x1ae0) = uVar5;
  *(uint *)(param_1 + 0x1ab0) = *(uint *)(param_1 + 0x1ab0) & 0xfffffffe;
  if (bVar3) {
    *(undefined1 *)(iVar8 + 0xc5) = 1;
    uVar5 = *(uint *)(param_1 + 0x1ae0);
  }
LAB_0004d0d0:
  if ((uVar7 == uVar5) && (iVar6 == *(int *)(param_1 + 0x1ab0))) {
    return;
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x1000;
  return;
}

/* FUN_0004d100 @ 0x4d100 (1264 bytes) */
int FUN_0004d100(param_1)
  int param_1;
{
  bool bVar1;
  short sVar2;
  short sVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  char cVar11;
  uint uVar10;
  uint uVar12;
  
  uVar5 = *(uint *)(param_1 + 0x1a4c);
  iVar6 = *(int *)(param_1 + 0x1e5c);
  iVar7 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((((*(uint *)(param_1 + 0x1a80) & 1) == 0) || ((*(uint *)(param_1 + 0x1aa0) & 6) == 6)) ||
     (*(char *)(param_1 + 0x23ed) != '\0')) {
    cVar11 = ((unsigned char *)0x00002d66)[iVar7];
    goto LAB_0004d234;
  }
  if (((unsigned char *)0x00002d66)[iVar7] == '\0') {
    cVar11 = '\0';
    if (((*(short *)(((unsigned char *)0x00002d80) + iVar7) != -0x7ffa) ||
        (*(int *)(((unsigned char *)0x00002d68) + iVar7) != *(int *)(((unsigned char *)0x00002d6c) + iVar7))) ||
       (((unsigned char *)0x00002b7e)[*(int *)(param_1 + 4)] != '\0')) {
LAB_0004d234:
      if (cVar11 != '\0') goto LAB_0004d240;
      goto LAB_0004d260;
    }
    sVar2 = *(short *)(((unsigned char *)0x00002d68) + iVar7);
    sVar3 = *(short *)(((unsigned char *)0x00002d6a) + iVar7);
    bVar1 = (*(uint *)(param_1 + 0x8c) & 0x400000) == 0;
    if (((bVar1) || (*(char *)(param_1 + 0x2450) == '\0')) ||
       (bVar4 = true, (int)*(uint *)(param_1 + 0x8c) < 0)) {
      bVar4 = false;
    }
    if (((bVar1) || (sVar2 != 0x302)) || (bVar1 = false, sVar3 != 0x303)) {
      if (bVar4) {
        if (sVar2 == 0) {
          if (sVar3 == 0x301) {
LAB_0004d20c:
            if ((*(int *)(((unsigned char *)0x00001098) + iVar6) == 1) &&
               (bVar1 = true, *(double *)(FUN_00001830 + iVar7) != *(double *)(iVar7 + 0x1838)))
            goto LAB_0004d5c4;
          }
        }
        else if (((sVar2 == 1) || (sVar2 == 0x306)) && (sVar3 == 1)) goto LAB_0004d20c;
      }
      goto LAB_0004d234;
    }
LAB_0004d5c4:
    *(uint *)(param_1 + 0x1a4c) = *(uint *)(param_1 + 0x1a4c) | 0x800;
    *(undefined1 *)(param_1 + 0x1a4f) = 0;
    uVar8 = *(uint *)(param_1 + 0x1a4c) & 0xfffff8ff | 0x400;
    *(uint *)(param_1 + 0x1a4c) = uVar8;
  }
  else {
LAB_0004d240:
    if (*(short *)(((unsigned char *)0x00002d64) + iVar7) == 0x207) {
LAB_0004d260:
      bVar1 = false;
      uVar8 = *(uint *)(param_1 + 0x1a4c) & 0xfffff7ff;
      *(uint *)(param_1 + 0x1a4c) = uVar8;
    }
    else {
      bVar1 = false;
      uVar8 = *(uint *)(param_1 + 0x1a4c) | 0x800;
      *(uint *)(param_1 + 0x1a4c) = uVar8;
    }
  }
  if (uVar5 != uVar8) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x200;
  }
  if (bVar1) {
    *(uint *)(param_1 + 0x18a4) = *(uint *)(param_1 + 0x18a4) | 0x10;
    if ((*(uint *)(((unsigned char *)0x00001544) + iVar6) & 0x10) == 0) {
LAB_0004d2c8:
      FUN_000b6580(param_1,0);
      (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,0);
      (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
    }
  }
  else {
    *(uint *)(param_1 + 0x18a4) = *(uint *)(param_1 + 0x18a4) & 0xffffffef;
    if ((*(uint *)(((unsigned char *)0x00001544) + iVar6) & 0x10) != 0) goto LAB_0004d2c8;
  }
  ((int (*)())FUN_0004ce30)(param_1);
  uVar8 = *(uint *)(param_1 + 0x1aa0);
  uVar12 = *(uint *)(param_1 + 0x1ab8);
  iVar6 = *(int *)(param_1 + 4);
  uVar5 = uVar12 | 1;
  *(uint *)(param_1 + 0x1ab8) = uVar5;
  if ((((uVar8 & 6) != 6) && (((unsigned char *)0x00002b7e)[iVar6] == '\0')) &&
     (*(char *)(param_1 + 0x23ed) == '\0')) {
    uVar9 = *(uint *)(param_1 + 0x1a4c);
    uVar10 = *(uint *)(param_1 + 0x44);
    goto LAB_0004d460;
  }
  uVar9 = *(uint *)(param_1 + 0x1a4c);
  if ((uVar9 & 0x800) == 0) {
    uVar10 = *(uint *)(param_1 + 0x44);
    if ((uVar10 & 0x60020000) != 0x40000000) {
      if ((((unsigned char *)0x00002e2d)[*(int *)(iVar6 + 0x10)] != '\0') && ((uVar10 & 0x20000) == 0)) {
        iVar6 = FUN_0001a010(iVar6,*(undefined4 *)(((unsigned char *)0x000026a0) + iVar6));
        if (iVar6 == 0) {
          uVar8 = *(uint *)(param_1 + 0x1aa0);
          uVar9 = *(uint *)(param_1 + 0x1a4c);
          uVar5 = *(uint *)(param_1 + 0x1ab8);
          goto LAB_0004d440;
        }
        iVar6 = *(int *)(param_1 + 4);
        uVar8 = *(uint *)(param_1 + 0x1aa0);
        uVar9 = *(uint *)(param_1 + 0x1a4c);
        uVar5 = *(uint *)(param_1 + 0x1ab8);
        uVar10 = *(uint *)(param_1 + 0x44);
      }
      iVar6 = *(int *)(iVar6 + 0x10);
      if (((((((unsigned char *)0x00002e2c)[iVar6] == '\0') || ((uVar10 & 0x20000) != 0)) ||
           (*(short *)(((unsigned char *)0x00002e28) + iVar6) == -1)) &&
          (((((unsigned char *)0x00003178)[iVar6] == '\0' || ((uVar10 & 0x20000) != 0)) ||
           ((*(short *)(((unsigned char *)0x00003170) + iVar6) != 0x1b02 &&
            (*(short *)(((unsigned char *)0x00003172) + iVar6) != 0x1b02)))))) &&
         (((uVar9 & 0x10000) == 0 && ((uVar10 & 0x2000100) == 0)))) goto LAB_0004d460;
    }
  }
  else {
LAB_0004d440:
    uVar10 = *(uint *)(param_1 + 0x44);
  }
  uVar5 = uVar5 & 0xfffffffe;
  *(uint *)(param_1 + 0x1ab8) = uVar5;
LAB_0004d460:
  if ((((uVar9 & 0x800) != 0) && (*(int *)(param_1 + 0x27b0) == 1)) &&
     ((*(uint *)(param_1 + 0x8c) & 0x400000) != 0)) {
    uVar5 = uVar5 & 0xfffffffe;
    *(uint *)(param_1 + 0x1ab8) = uVar5;
  }
  if (((uVar8 & 2) != 0) && ((uVar10 >> 9 & 1) != 0)) {
    uVar5 = uVar5 & 0xfffffffe;
    *(uint *)(param_1 + 0x1ab8) = uVar5;
  }
  if (uVar12 != uVar5) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x20000;
  }
  if (*(int *)(param_1 + 0x23dc) != 1) {
    uVar5 = *(uint *)(param_1 + 0x1bd4);
    uVar8 = *(uint *)(param_1 + 0x1aa4);
    iVar6 = FUN_0001a010(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x2460));
    if (iVar6 == 0) {
      if ((*(uint *)(param_1 + 0x1ab8) & 1) == 0) {
        uVar12 = *(uint *)(param_1 + 0x1bd4) & 0xfffffffe;
        *(uint *)(param_1 + 0x1bd4) = uVar12;
        *(uint *)(param_1 + 0x1aa4) = *(uint *)(param_1 + 0x1aa4) & 0xf7ffffff;
      }
      else {
        iVar6 = *(int *)(FUN_00001af4 + param_1);
        uVar12 = *(uint *)(param_1 + 0x1bd4) | 1;
        *(uint *)(param_1 + 0x1bd4) = uVar12;
        if (iVar6 == 0) {
          *(uint *)(param_1 + 0x1aa4) = *(uint *)(param_1 + 0x1aa4) | 0x8000000;
        }
        else {
          *(uint *)(param_1 + 0x1aa4) = *(uint *)(param_1 + 0x1aa4) & 0xf7ffffff;
        }
      }
    }
    else {
      uVar12 = *(uint *)(param_1 + 0x1bd4);
      if ((uVar12 & 1) != 0) {
        uVar12 = uVar12 & 0xfffffffe;
        *(uint *)(param_1 + 0x1bd4) = uVar12;
        *(uint *)(param_1 + 0x1aa4) = *(uint *)(param_1 + 0x1aa4) & 0xf7ffffff;
      }
    }
    if (((uVar5 & 1) != (uVar12 & 1)) ||
       ((uVar8 >> 0x1b & 1) != (*(uint *)(param_1 + 0x1aa4) >> 0x1b & 1))) {
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x20800;
    }
  }
  return;
}

/* FUN_0004d620 @ 0x4d620 (328 bytes) */
int FUN_0004d620(param_1)
  int param_1;
{
  int iVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = *(uint *)(param_1 + 0x44);
  if ((uVar4 & 0x20000) == 0) {
    FUN_000b6580(param_1,0);
                    
                    
    (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
    return;
  }
  if ((uVar4 & 0x2000) != 0) {
    FUN_000afe40(param_1,0);
    return;
  }
  if ((uVar4 & 0x80100000) == 0x80000000) {
    if (*(short *)("}J3x})+x|B;x}k" + *(int *)(*(int *)(param_1 + 4) + 0x10)) == -0x7e06)
    goto LAB_0004d6ac;
  }
  else if ((uVar4 & 0x800000) != 0) {
LAB_0004d6ac:
    cVar2 = '\x01';
    goto LAB_0004d6b0;
  }
  cVar2 = '\0';
LAB_0004d6b0:
  iVar5 = *(int *)(((unsigned char *)0x00001154) + param_1);
  if (*(int *)(iVar5 + 4) != 0) {
    uVar4 = 0;
    iVar3 = 0;
    do {
      iVar1 = *(int *)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 +
                      *(int *)(iVar3 + *(int *)(iVar5 + 0x88) + 0x70));
      if ((iVar1 != 0) && (((unsigned char *)0x0000120c)[iVar1] != cVar2)) {
        *(undefined4 *)(((unsigned char *)0x000016f0) + iVar1) = 1;
        *(undefined1 *)(iVar1 + 0x119) = 1;
        iVar5 = *(int *)(((unsigned char *)0x00001154) + param_1);
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 0x78;
    } while (uVar4 < *(uint *)(iVar5 + 4));
  }
  FUN_000b3630(param_1);
  return;
}

/* FUN_0004d770 @ 0x4d770 (840 bytes) */
int FUN_0004d770(param_1)
  int param_1;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  
  dVar6 = DOUBLE_001aa1e0;
  fVar4 = FLOAT_001aa10c;
  iVar9 = *(int *)(param_1 + 4);
  iVar11 = *(int *)(param_1 + 0x1c9c);
  iVar10 = *(int *)(param_1 + 0x1c98);
  iVar14 = *(int *)(param_1 + 0x1c88);
  iVar13 = *(int *)(param_1 + 0x1c94);
  iVar12 = *(int *)(param_1 + 0x1c90);
  iVar16 = *(int *)(param_1 + 0x1c8c);
  iVar17 = *(int *)(iVar9 + 0x10);
  fVar1 = *(float *)(iVar9 + 0x2a58);
  fVar2 = *(float *)(iVar9 + 0x2a54);
  *(undefined4 *)(param_1 + 0x1c9c) = *(undefined4 *)(iVar17 + 0x1818);
  *(undefined4 *)(param_1 + 0x1c98) = *(undefined4 *)(iVar17 + 0x1828);
  uVar7 = *(uint *)(iVar17 + 0x1840);
  fVar3 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar17 + 0x184c) ^ 0x80000000) -
                         dVar6) * fVar4;
  fVar5 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar17 + 0x1844) ^ 0x80000000) -
                         dVar6) + fVar3;
  fVar4 = fVar2 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar17 + 0x1848) ^ 0x80000000) -
                         dVar6) * fVar4;
  if (*(char *)(param_1 + 0x293c) != '\0') {
    fVar5 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar9 + 0x160) ^ 0x80000000) -
                           dVar6) - fVar5;
    fVar3 = -fVar3;
  }
  *(float *)(param_1 + 0x1c8c) = fVar4;
  *(float *)(param_1 + 0x1c88) =
       fVar2 * (float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - dVar6) + fVar4;
  *(float *)(param_1 + 0x1c94) = fVar3;
  *(float *)(param_1 + 0x1c90) = fVar5;
  if (*(char *)(param_1 + 0x124) != '\0') {
    *(undefined4 *)(param_1 + 0x1c8c) = *(undefined4 *)(param_1 + 0x2814);
    *(undefined4 *)(param_1 + 0x1c94) = *(undefined4 *)(param_1 + 0x2818);
  }
  *(undefined4 *)(param_1 + 0x1ca8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cb0) = 0x3f800000;
  if (((((iVar16 != *(int *)(param_1 + 0x1c8c)) || (iVar14 != *(int *)(param_1 + 0x1c88))) ||
       (iVar13 != *(int *)(param_1 + 0x1c94))) ||
      ((iVar12 != *(int *)(param_1 + 0x1c90) || (iVar11 != *(int *)(param_1 + 0x1c9c))))) ||
     (iVar10 != *(int *)(param_1 + 0x1c98))) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x80;
  }
  uVar15 = *(uint *)(((unsigned char *)0x00001b14) + param_1);
  uVar7 = uVar15 & 0xfffffff8;
  *(uint *)(((unsigned char *)0x00001b14) + param_1) = uVar7;
  if ((((*(uint *)(((unsigned char *)0x0000317c) + iVar17) & 0xffff0000) != 0) || (((unsigned char *)0x0000317b)[iVar17] != '\0'))
     && ((*(float *)(((unsigned char *)0x0000316c) + iVar17) != FLOAT_001aa0d4 ||
         (*(float *)(((unsigned char *)0x00003168) + iVar17) != FLOAT_001aa0d4)))) {
    if (((unsigned char *)0x0000317b)[iVar17] != '\0') {
      if (*(short *)(((unsigned char *)0x00003170) + iVar17) == 0x1b00) {
        uVar7 = uVar7 | 1;
        *(uint *)(((unsigned char *)0x00001b14) + param_1) = uVar7;
      }
      if (*(short *)(((unsigned char *)0x00003172) + iVar17) == 0x1b00) {
        uVar7 = uVar7 | 2;
        *(uint *)(((unsigned char *)0x00001b14) + param_1) = uVar7;
      }
    }
    if (((unsigned char *)0x0000317c)[iVar17] != '\0') {
      if (*(short *)(((unsigned char *)0x00003170) + iVar17) == 0x1b01) {
        uVar7 = uVar7 | 1;
        *(uint *)(((unsigned char *)0x00001b14) + param_1) = uVar7;
      }
      if (*(short *)(((unsigned char *)0x00003172) + iVar17) == 0x1b01) {
        uVar7 = uVar7 | 2;
        *(uint *)(((unsigned char *)0x00001b14) + param_1) = uVar7;
      }
    }
    if (((unsigned char *)0x0000317d)[iVar17] != '\0') {
      if (*(short *)(((unsigned char *)0x00003170) + iVar17) == 0x1b02) {
        uVar7 = uVar7 | 1;
        *(uint *)(((unsigned char *)0x00001b14) + param_1) = uVar7;
      }
      if (*(short *)(((unsigned char *)0x00003172) + iVar17) == 0x1b02) {
        uVar7 = uVar7 | 2;
        *(uint *)(((unsigned char *)0x00001b14) + param_1) = uVar7;
      }
    }
    fVar1 = (float)((double)CONCAT44(0x43300000,*(undefined4 *)(param_1 + 8)) - DOUBLE_001aa250) *
            *(float *)(((unsigned char *)0x00003168) + iVar17);
    fVar2 = FLOAT_001aa104;
    if ((*(uint *)(*(int *)(param_1 + 4) + 0x154) & 0x30000) == 0x10000) {
      fVar2 = FLOAT_001aa164;
    }
    fVar3 = *(float *)(((unsigned char *)0x0000316c) + iVar17);
    uVar8 = *(uint *)(param_1 + 0x1930);
    *(float *)(((unsigned char *)0x00001b24) + param_1) = fVar1;
    *(float *)(((unsigned char *)0x00001b1c) + param_1) = fVar1;
    *(uint *)(param_1 + 0x1930) = uVar8 | 0x20;
    *(float *)(((unsigned char *)0x00001b20) + param_1) = fVar2 * fVar3;
    *(float *)(((unsigned char *)0x00001b18) + param_1) = fVar2 * fVar3;
  }
  if (uVar15 != uVar7) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x20;
  }
  return;
}

/* FUN_0004dac0 @ 0x4dac0 (272 bytes) */
int FUN_0004dac0(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((((unsigned char *)0x00002dc8)[iVar1] == '\0') || (((unsigned char *)0x00001490)[param_1] == '\0')) {
    uVar2 = *(uint *)(param_1 + 0x1930);
    *(uint *)(param_1 + 0x1aa0) = *(uint *)(param_1 + 0x1aa0) & 0xfffffffd;
  }
  else {
    uVar4 = (uint)*(ushort *)(((unsigned char *)0x00002dc4) + iVar1);
    uVar3 = *(uint *)(param_1 + 0x1aa0);
    uVar2 = *(uint *)(param_1 + 0x1a50);
    *(uint *)(param_1 + 0x1aa0) = uVar3 | 2;
    if ((uVar4 == 0x202) ||
       (((uVar4 == 0x203 && (*(double *)(FUN_00001830 + iVar1) == DOUBLE_001aa200)) &&
        (*(double *)(iVar1 + 0x1838) == DOUBLE_001aa200)))) {
      *(uint *)(param_1 + 0x1aa0) = uVar3 & 0xfffffffb | 2;
    }
    else {
      *(uint *)(param_1 + 0x1aa0) = ((byte)((unsigned char *)0x00002e44)[iVar1] & 1) << 2 | uVar3 & 0xfffffffb | 2
      ;
    }
    *(uint *)(param_1 + 0x1aa4) =
         *(uint *)(&DAT_001db368 + (uVar4 & 7) * 4) & 7 | *(uint *)(param_1 + 0x1aa4) & 0xfffffff8;
    if ((*(uint *)(param_1 + 0x44) & 0x200) == 0) {
      uVar3 = uVar2 & 0xfffffffe;
      *(uint *)(param_1 + 0x1a50) = uVar3;
    }
    else {
      uVar3 = uVar2 | 1;
      *(uint *)(param_1 + 0x1a50) = uVar3;
    }
    if (uVar2 == uVar3) {
      uVar2 = *(uint *)(param_1 + 0x1930);
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x1930) | 0x8000000;
      *(uint *)(param_1 + 0x1930) = uVar2;
    }
  }
  *(uint *)(param_1 + 0x1930) = uVar2 | 0x800;
  return;
}

/* FUN_0004dbe0 @ 0x4dbe0 (76 bytes) */
int FUN_0004dbe0(param_1)
  int param_1;
{
  if (*(char *)(param_1 + 0x124) != '\0') {
    FUN_00083110();
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000;
  return;
}

