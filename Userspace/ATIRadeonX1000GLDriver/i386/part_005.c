#include "decls.h"

/* FUN_0003a714 @ 0x3a714 (750 bytes) */
int FUN_0003a714(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  uint param_1;
  int param_2;
  uint param_3;
  int param_4;
  uint param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
{
  char cVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 *puVar7;
  uint *puVar8;
  uint *puVar9;
  int iVar10;
  uint local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  byte local_6d;
  uint local_60;
  undefined4 *local_50;
  uint *local_4c;
  undefined1 *local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  undefined1 *local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint *local_20;
  undefined4 *local_1c;
  uint *local_18;
  int local_14;
  int local_10;
  
  puVar9 = &local_9c;
  local_44 = param_3;
  local_40 = param_1;
  if (*(uint *)(param_2 + 0x24) != param_3) {
    if (*(uint *)(param_2 + 0x28) != 0) {
      local_9c = *(uint *)(param_2 + 0x28);
      (**(code **)(param_1 + 0x18))();
      *(undefined4 *)(param_2 + 0x28) = 0;
    }
    if (local_44 != 0) {
      local_98 = 4;
      local_9c = local_44;
      uVar5 = (**(code **)(local_40 + 0x10))();
      *(undefined4 *)(param_2 + 0x28) = uVar5;
      *(uint *)(param_2 + 0x24) = local_44;
      cVar1 = *(char *)(param_2 + 0x8c);
      goto joined_r0x0003a9b3;
    }
  }
  *(uint *)(param_2 + 0x24) = local_44;
  cVar1 = *(char *)(param_2 + 0x8c);
joined_r0x0003a9b3:
  if (cVar1 != '\0') {
    local_10 = 0;
    iVar10 = param_2;
    do {
      local_8c = 1;
      local_90 = 0x87e1;
      local_94 = 0x87c2;
      local_98 = 0x87bf;
      local_9c = local_40;
      uVar5 = FUN_00052f54();
      *(undefined4 *)(iVar10 + 0x68) = uVar5;
      local_10 = local_10 + 1;
      iVar10 = iVar10 + 4;
    } while (local_10 != 4);
    local_10 = 4;
  }
  if (local_44 != 0) {
    local_28 = *(int *)(param_2 + 0x28);
    local_34 = 0;
    local_30 = 0;
    do {
      if (local_30 < param_5) {
        uVar6 = *(uint *)(param_6 + local_30 * 8) >> 0x10;
        uVar4 = *(uint *)(param_6 + 4 + local_30 * 8) >> 0x10;
        if ((local_34 < uVar6) || (uVar4 <= local_34)) goto LAB_0003a95e;
        local_2c = (uVar4 - uVar6) + 1;
        local_30 = local_30 + 1;
        bVar3 = *(byte *)(local_34 * 8 + 1 + param_4);
      }
      else {
LAB_0003a95e:
        local_2c = 1;
        bVar3 = *(byte *)(local_34 * 8 + 1 + param_4);
      }
      if ((bVar3 & 0xf8) != 0) {
        local_3c = local_34 * 8;
        iVar10 = -(local_2c + 0x1eU & 0xfffffff0);
        puVar7 = (undefined1 *)((int)puVar9 + iVar10 + 0x20);
        uVar4 = local_2c * 4 + 0x1eU & 0xfffffff0;
        puVar8 = (uint *)((int)puVar9 + (iVar10 - uVar4) + 0x20);
        local_50 = (undefined4 *)((int)puVar9 + uVar4 * -2 + iVar10 + 0x20);
        local_4c = puVar8;
        local_48 = puVar7;
        local_38 = (undefined1 *)puVar9;
        if (local_2c != 0) {
          local_18 = (uint *)(param_4 + local_3c);
          local_24 = 0;
          do {
            while( true ) {
              uVar6 = *local_18;
              bVar3 = (byte)(uVar6 >> 0xb) & 0x1f;
              if (bVar3 != 2) break;
              *puVar7 = 0;
              *puVar8 = uVar6 >> 0x10;
              local_24 = local_24 + 1;
              local_18 = local_18 + 2;
              puVar7 = puVar7 + 1;
              puVar8 = puVar8 + 1;
              if (local_2c == local_24) goto LAB_0003a87c;
            }
            if (bVar3 == 0x11) {
              *puVar7 = 1;
              *puVar8 = 0;
            }
            else {
              *puVar7 = 2;
              *puVar8 = 0;
            }
            local_24 = local_24 + 1;
            local_18 = local_18 + 2;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          } while (local_2c != local_24);
        }
LAB_0003a87c:
        *(undefined4 **)((int)puVar9 + uVar4 * -2 + iVar10 + 0x10) = local_50;
        *(uint **)((int)puVar9 + uVar4 * -2 + iVar10 + 0xc) = local_4c;
        *(undefined1 **)((int)puVar9 + uVar4 * -2 + iVar10 + 8) = local_48;
        iVar2 = local_2c;
        *(int *)((int)puVar9 + uVar4 * -2 + iVar10 + 4) = local_2c;
        *(uint *)((int)puVar9 + uVar4 * -2 + iVar10) = local_40;
        *(undefined4 *)((int)puVar9 + uVar4 * -2 + iVar10 + -4) = 0x3a8a3;
        FUN_0005220f();
        if (iVar2 != 0) {
          local_20 = (uint *)(param_4 + local_3c);
          local_1c = local_50;
          local_14 = 0;
          do {
            while( true ) {
              uVar6 = *local_20;
              local_6d = (byte)(uVar6 >> 0xb) & 0x1f;
              uVar5 = *local_1c;
              local_60 = local_20[1] >> 0x10;
              *(undefined4 *)(local_28 + local_60 * 4) = uVar5;
              if (local_6d != 0x11) break;
              *(uint *)((int)puVar9 + uVar4 * -2 + iVar10 + 0xc) = (uVar6 >> 0x10) * 0x10 + param_8;
              *(undefined4 *)((int)puVar9 + uVar4 * -2 + iVar10 + 8) = 0x1406;
              *(undefined4 *)((int)puVar9 + uVar4 * -2 + iVar10 + 4) = uVar5;
              *(uint *)((int)puVar9 + uVar4 * -2 + iVar10) = local_40;
              *(undefined4 *)((int)puVar9 + uVar4 * -2 + iVar10 + -4) = 0x3a929;
              FUN_0005321e();
              local_14 = local_14 + 1;
              local_20 = local_20 + 2;
              local_1c = local_1c + 1;
              if (local_2c == local_14) goto LAB_0003a93d;
            }
            local_14 = local_14 + 1;
            local_20 = local_20 + 2;
            local_1c = local_1c + 1;
          } while (local_2c != local_14);
LAB_0003a93d:
          local_34 = local_34 + local_14;
        }
        local_34 = local_34 - 1;
        puVar9 = (uint *)local_38;
      }
      local_34 = local_34 + 1;
    } while (local_34 < local_44);
  }
  return;
}

/* FUN_0003aa02 @ 0x3aa02 (68 bytes) */
int FUN_0003aa02(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  
  if (*param_2 == 0) {
    iVar1 = FUN_0005295d(param_1,1);
    *param_2 = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  FUN_00052954(param_1,*param_2);
  return 1;
}

/* FUN_0003aa46 @ 0x3aa46 (706 bytes) */
int FUN_0003aa46(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  uint *param_5;
{
  int iVar1;
  ushort uVar2;
  int iVar3;
  byte bVar4;
  uint *puVar5;
  int iVar6;
  undefined1 local_440;
  int local_42c;
  int local_41c;
  int local_410;
  undefined4 local_40c [256];
  
  if (*(char *)(param_3 + 0x8c) == '\0') {
    *(undefined4 *)(param_2 + 0x800) = 0;
  }
  else {
    *(undefined4 *)(param_2 + 0x800) = 4;
    *(undefined2 *)(param_2 + 2) = 0;
    *(undefined2 *)(param_2 + 10) = 1;
    *(undefined2 *)(param_2 + 0x12) = 2;
    *(undefined2 *)(param_2 + 0x1a) = 3;
    local_40c[0] = *(undefined4 *)(param_3 + 0x68);
    local_40c[1] = *(undefined4 *)(param_3 + 0x6c);
    local_40c[2] = *(undefined4 *)(param_3 + 0x70);
    local_40c[3] = *(undefined4 *)(param_3 + 0x74);
  }
  if (param_4 == 0) {
    local_42c = *(int *)(param_2 + 0x800);
    *(int *)(param_2 + 0x804) = local_42c;
    *(int *)(param_2 + 0x808) = local_42c;
  }
  else {
    iVar3 = *(int *)(param_3 + 0x28);
    local_41c = 0;
    local_42c = *(int *)(param_2 + 0x800);
    puVar5 = param_5;
    do {
      while ((*puVar5 & 0xe3f800) != 0x8000) {
        local_41c = local_41c + 1;
        puVar5 = puVar5 + 2;
        if (param_4 == local_41c) goto LAB_0003ab6c;
      }
      iVar6 = param_2 + local_42c * 8;
      uVar2 = *(ushort *)((int)puVar5 + 6);
      local_40c[local_42c] = *(undefined4 *)(iVar3 + (uint)uVar2 * 4);
      *(char *)(iVar6 + 1) = (char)uVar2;
      *(ushort *)(iVar6 + 2) = *(byte *)((int)puVar5 + 2) >> 2 & 3;
      local_42c = *(int *)(param_2 + 0x800) + 1;
      *(int *)(param_2 + 0x800) = local_42c;
      local_41c = local_41c + 1;
      puVar5 = puVar5 + 2;
    } while (param_4 != local_41c);
LAB_0003ab6c:
    *(int *)(param_2 + 0x804) = local_42c;
    iVar3 = *(int *)(param_3 + 0x28);
    iVar6 = 0;
    puVar5 = param_5;
    do {
      while ((*puVar5 & 0xf800) != 0x1000) {
        iVar6 = iVar6 + 1;
        puVar5 = puVar5 + 2;
        if (param_4 == iVar6) goto LAB_0003ac10;
      }
      iVar1 = param_2 + local_42c * 8;
      uVar2 = *(ushort *)((int)puVar5 + 6);
      local_40c[local_42c] = *(undefined4 *)(iVar3 + (uint)uVar2 * 4);
      local_440 = (undefined1)uVar2;
      *(undefined1 *)(iVar1 + 1) = local_440;
      *(undefined2 *)(iVar1 + 2) = *(undefined2 *)((int)puVar5 + 2);
      local_42c = *(int *)(param_2 + 0x804) + 1;
      *(int *)(param_2 + 0x804) = local_42c;
      iVar6 = iVar6 + 1;
      puVar5 = puVar5 + 2;
    } while (param_4 != iVar6);
LAB_0003ac10:
    *(int *)(param_2 + 0x808) = local_42c;
    local_410 = 0;
    do {
      bVar4 = *(byte *)((int)param_5 + 1) >> 3;
      if ((((bVar4 != 0) && (bVar4 != 0x11)) && (bVar4 != 2)) && ((*param_5 & 0xe3f800) != 0x8000))
      {
        iVar6 = param_2 + local_42c * 8;
        uVar2 = *(ushort *)((int)param_5 + 6);
        local_40c[local_42c] = *(undefined4 *)(iVar3 + (uint)uVar2 * 4);
        *(char *)(iVar6 + 1) = (char)uVar2;
        *(short *)(iVar6 + 2) = (short)local_410;
        local_42c = *(int *)(param_2 + 0x808) + 1;
        *(int *)(param_2 + 0x808) = local_42c;
      }
      local_410 = local_410 + 1;
      param_5 = param_5 + 2;
    } while (param_4 != local_410);
  }
  FUN_0005303a(param_1 + 0x240,param_2,local_42c,local_40c);
  return;
}

/* FUN_0003ad08 @ 0x3ad08 (824 bytes) */
int FUN_0003ad08(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  float *pfVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  undefined8 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  float fVar11;
  char cVar12;
  undefined8 *puVar13;
  float *pfVar14;
  uint uVar15;
  int iVar16;
  undefined4 *puVar17;
  uint uVar18;
  int iVar19;
  float *pfVar20;
  byte bVar21;
  dword *pdVar22;
  uint uVar23;
  dword *pdVar24;
  dword *pdVar25;
  float fVar26;
  float fVar27;
  byte *local_50;
  int local_3c;
  undefined1 local_28 [4];
  int local_24;
  byte *local_20 [4];
  
  cVar12 = FUN_00052f7b(param_1 + 0x240,local_20,&local_24,local_28);
  if (cVar12 != '\0') {
    ((int (*)())FUN_0003aa46)(param_3,param_4);
  }
  iVar7 = *(int *)(local_20[0] + 0x800);
  if (local_20[0] < local_20[0] + iVar7 * 8) {
    iVar19 = *(int *)(param_1 + 0x10) + 0x1860;
    local_50 = local_20[0];
    do {
      puVar8 = *(undefined4 **)(local_50 + 4);
      uVar2 = *(undefined4 *)(iVar19 + (uint)*(ushort *)(local_50 + 2) * 4);
      iVar16 = (uint)*(ushort *)(local_50 + 2) * 4 + iVar19;
      uVar3 = *(undefined4 *)(iVar16 + 0x10);
      uVar9 = *(undefined4 *)(iVar16 + 0x20);
      uVar10 = *(undefined4 *)(iVar16 + 0x30);
      puVar17 = (undefined4 *)((uint)*local_50 * 0x10 + local_24);
      *puVar17 = uVar2;
      puVar17[1] = uVar3;
      puVar17[2] = uVar9;
      puVar17[3] = uVar10;
      *puVar8 = uVar2;
      puVar8[1] = uVar3;
      puVar8[2] = uVar9;
      puVar8[3] = uVar10;
      local_50 = local_50 + 8;
    } while (local_50 < local_20[0] + iVar7 * 8);
  }
  else {
    local_50 = local_20[0];
  }
  iVar7 = *(int *)(local_20[0] + 0x804);
  for (; local_50 < local_20[0] + iVar7 * 8; local_50 = local_50 + 8) {
    uVar6 = (*(undefined8 **)(local_50 + 4))[1];
    puVar13 = (undefined8 *)((uint)*local_50 * 0x10 + local_24);
    *puVar13 = **(undefined8 **)(local_50 + 4);
    puVar13[1] = uVar6;
  }
  iVar7 = *(int *)(local_20[0] + 0x808);
  do {
    fVar11 = FLOAT_001c5ba4;
    if (local_20[0] + iVar7 * 8 <= local_50) {
      return;
    }
    uVar15 = *(uint *)(param_4 + (uint)*(ushort *)(local_50 + 2) * 8);
    pfVar14 = (float *)((uint)*local_50 * 0x10 + local_24);
    bVar21 = (byte)(uVar15 >> 0xb) & 0x1f;
    if (bVar21 == 1) {
      pfVar20 = (float *)((uVar15 >> 0x10) * 0x10 + param_5);
      if (*(int *)(*(int *)(param_1 + 0x18) + 0x198) == 0) {
        *pfVar14 = *pfVar20;
        pfVar14[1] = pfVar20[1];
        pfVar14[2] = pfVar20[2];
        pfVar14[3] = pfVar20[3];
      }
      else {
        _glpUniformToFloat(*(undefined4 *)(**(int **)(param_1 + 0x1cc) + 4),uVar15 >> 0x10,pfVar20,
                           pfVar14);
      }
      goto LAB_0003ae98;
    }
    if (((byte)(uVar15 >> 8) & 0xf8) == 0x80) {
      uVar23 = uVar15 >> 0x12 & 3;
      uVar18 = uVar15 >> 0x18;
      switch(uVar15 >> 0x15 & 7) {
      default:
        iVar19 = 0;
        break;
      case 1:
        iVar19 = 0xc0;
        break;
      case 2:
        iVar19 = 0x80;
        break;
      case 3:
        iVar19 = (uVar18 + 4) * 0x40;
        break;
      case 4:
        iVar19 = (uVar18 + 0x10) * 0x40;
        break;
      case 5:
        iVar19 = (uVar18 + 8) * 0x40;
      }
      uVar15 = uVar15 >> 0x10 & 3;
      local_3c = *(int *)(param_1 + 0x10) + 0x1860 + iVar19;
      if ((1 < uVar15) && (local_3c = *(int *)(param_1 + 0x10) + 0x1e60 + iVar19, 3 < uVar15)) {
        local_3c = 0;
      }
      if (uVar15 < 3) {
        if (uVar15 == 0) {
LAB_0003afc4:
          iVar19 = uVar23 * 4;
          *pfVar14 = *(float *)(local_3c + iVar19);
          iVar19 = iVar19 + local_3c;
          pfVar14[1] = *(float *)(iVar19 + 0x10);
          pfVar14[2] = *(float *)(iVar19 + 0x20);
          pfVar14[3] = *(float *)(iVar19 + 0x30);
        }
        else {
          iVar19 = uVar23 * 0x10;
          *pfVar14 = *(float *)(local_3c + iVar19);
          iVar19 = iVar19 + local_3c;
          pfVar14[1] = *(float *)(iVar19 + 4);
          pfVar14[2] = *(float *)(iVar19 + 8);
          pfVar14[3] = *(float *)(iVar19 + 0xc);
        }
      }
      else if (uVar15 == 3) goto LAB_0003afc4;
      goto LAB_0003ae98;
    }
    switch(bVar21) {
    case 0:
      pdVar25 = (dword *)(pfVar14 + 1);
      pdVar24 = (dword *)(pfVar14 + 2);
      pdVar22 = (dword *)(pfVar14 + 3);
      pfVar20 = pfVar14;
      break;
    default:
LAB_0003ae71:
      pdVar25 = &MACH_HEADER.cputype;
      pdVar24 = &MACH_HEADER.cpusubtype;
      pdVar22 = &MACH_HEADER.filetype;
      pfVar20 = (float *)0x0;
      break;
    case 2:
      pfVar20 = (float *)((uVar15 >> 0x10) * 0x10 + *(int *)(*(int *)(param_1 + 0x10) + 0x4308));
      pdVar25 = (dword *)(pfVar20 + 1);
      pdVar24 = (dword *)(pfVar20 + 2);
      pdVar22 = (dword *)(pfVar20 + 3);
      break;
    case 3:
      uVar18 = uVar15 >> 0x18;
      switch(uVar15 >> 0x14 & 0xf) {
      case 0:
        pfVar20 = (float *)(uVar18 * 0x80 + 0x24c0 + *(int *)(param_1 + 0x10));
        pdVar25 = (dword *)(pfVar20 + 1);
        pdVar24 = (dword *)(pfVar20 + 2);
        pdVar22 = (dword *)(pfVar20 + 3);
        break;
      case 1:
        pfVar20 = (float *)(uVar18 * 0x80 + 0x24d0 + *(int *)(param_1 + 0x10));
        pdVar25 = (dword *)(pfVar20 + 1);
        pdVar24 = (dword *)(pfVar20 + 2);
        pdVar22 = (dword *)(pfVar20 + 3);
        break;
      case 2:
        pfVar20 = (float *)(uVar18 * 0x80 + 0x24e0 + *(int *)(param_1 + 0x10));
        pdVar25 = (dword *)(pfVar20 + 1);
        pdVar24 = (dword *)(pfVar20 + 2);
        pdVar22 = (dword *)(pfVar20 + 3);
        break;
      case 3:
        pfVar20 = (float *)(uVar18 * 0x80 + 0x24f0 + *(int *)(param_1 + 0x10));
        pdVar25 = (dword *)(pfVar20 + 1);
        pdVar24 = (dword *)(pfVar20 + 2);
        pdVar22 = (dword *)(pfVar20 + 3);
        break;
      case 4:
        pfVar20 = (float *)(uVar18 * 0x80 + 0x2500 + *(int *)(param_1 + 0x10));
        pdVar25 = (dword *)(pfVar20 + 1);
        pdVar24 = (dword *)(pfVar20 + 2);
        pdVar22 = (dword *)(pfVar20 + 3);
        break;
      case 5:
        pfVar20 = (float *)(uVar18 * 0x80 + 0x2510 + *(int *)(param_1 + 0x10));
        pdVar25 = (dword *)(pfVar20 + 1);
        pdVar24 = (dword *)(pfVar20 + 2);
        pdVar22 = (dword *)(pfVar20 + 3);
        break;
      case 6:
        iVar19 = uVar18 * 0x80 + *(int *)(param_1 + 0x10);
        fVar4 = *(float *)(iVar19 + 0x24f0);
        fVar5 = *(float *)(iVar19 + 0x24f4);
        fVar27 = *(float *)(iVar19 + 0x24f8) + FLOAT_001c5ba4;
        fVar26 = (float)(DOUBLE_001cf330 /
                        SQRT((double)(fVar4 * fVar4 + fVar5 * fVar5 + fVar27 * fVar27)));
        *pfVar14 = fVar4 * fVar26;
        pfVar14[1] = fVar5 * fVar26;
        pfVar14[2] = fVar27 * fVar26;
        pfVar14[3] = fVar11;
        goto LAB_0003ae98;
      case 7:
        pfVar20 = (float *)(uVar18 * 0x80 + 0x2530 + *(int *)(param_1 + 0x10));
        pdVar25 = (dword *)(pfVar20 + 1);
        pdVar24 = (dword *)(pfVar20 + 2);
        pdVar22 = (dword *)(pfVar20 + 3);
        break;
      default:
        goto LAB_0003ae71;
      }
      break;
    case 4:
      pfVar20 = (float *)(*(int *)(param_1 + 0x10) + 0x28c0 + (uVar15 >> 0x17 & 1) * 0x240);
      pfVar1 = (float *)(*(int *)(param_1 + 0x10) + 0x24c0 + (uVar15 >> 0x18) * 0x80);
      uVar15 = uVar15 >> 0x15 & 3;
      if (uVar15 == 1) {
        *pfVar14 = pfVar1[4] * pfVar20[4];
        pfVar14[1] = pfVar1[5] * pfVar20[5];
        pfVar14[2] = pfVar1[6] * pfVar20[6];
        pfVar14[3] = pfVar20[7];
      }
      else if (uVar15 == 2) {
        *pfVar14 = pfVar1[8] * pfVar20[8];
        pfVar14[1] = pfVar1[9] * pfVar20[9];
        pfVar14[2] = pfVar1[10] * pfVar20[10];
        pfVar14[3] = pfVar20[0xb];
      }
      else {
        if (uVar15 != 0) goto LAB_0003ae71;
        *pfVar14 = *pfVar1 * *pfVar20;
        pfVar14[1] = pfVar1[1] * pfVar20[1];
        pfVar14[2] = pfVar1[2] * pfVar20[2];
        pfVar14[3] = pfVar20[3];
      }
      goto LAB_0003ae98;
    case 5:
      iVar19 = (int)uVar15 >> 0x1f;
      switch(uVar15 >> 0x1c & 7) {
      case 0:
        pfVar20 = (float *)(iVar19 * -0x240 + 0x28c0 + *(int *)(param_1 + 0x10));
        pdVar25 = (dword *)(pfVar20 + 1);
        pdVar24 = (dword *)(pfVar20 + 2);
        pdVar22 = (dword *)(pfVar20 + 3);
        break;
      case 1:
        pfVar20 = (float *)(iVar19 * -0x240 + 0x28d0 + *(int *)(param_1 + 0x10));
        pdVar25 = (dword *)(pfVar20 + 1);
        pdVar24 = (dword *)(pfVar20 + 2);
        pdVar22 = (dword *)(pfVar20 + 3);
        break;
      case 2:
        pfVar20 = (float *)(iVar19 * -0x240 + 0x28e0 + *(int *)(param_1 + 0x10));
        pdVar25 = (dword *)(pfVar20 + 1);
        pdVar24 = (dword *)(pfVar20 + 2);
        pdVar22 = (dword *)(pfVar20 + 3);
        break;
      case 3:
        pfVar20 = (float *)(iVar19 * -0x240 + 0x28f0 + *(int *)(param_1 + 0x10));
        pdVar25 = (dword *)(pfVar20 + 1);
        pdVar24 = (dword *)(pfVar20 + 2);
        pdVar22 = (dword *)(pfVar20 + 3);
        break;
      case 4:
        pfVar20 = (float *)(iVar19 * -0x240 + 0x2900 + *(int *)(param_1 + 0x10));
        pdVar25 = (dword *)(pfVar20 + 1);
        pdVar24 = (dword *)(pfVar20 + 2);
        pdVar22 = (dword *)(pfVar20 + 3);
        break;
      case 5:
        iVar16 = *(int *)(param_1 + 0x10);
        pfVar20 = (float *)(iVar16 + 0x28c0 + iVar19 * -0x240);
        *pfVar14 = *(float *)(iVar16 + 0x24b0) * *pfVar20 + pfVar20[0xc];
        pfVar14[1] = *(float *)(iVar16 + 0x24b4) * pfVar20[1] + pfVar20[0xd];
        pfVar14[2] = *(float *)(iVar16 + 0x24b8) * pfVar20[2] + pfVar20[0xe];
        pfVar14[3] = pfVar20[7];
        goto LAB_0003ae98;
      default:
        goto LAB_0003ae71;
      }
      break;
    case 6:
      iVar19 = *(int *)(param_1 + 0x10);
      pdVar25 = (dword *)(iVar19 + 0x24b4);
      pdVar24 = (dword *)(iVar19 + 0x24b8);
      pdVar22 = (dword *)(iVar19 + 0x24bc);
      pfVar20 = (float *)(iVar19 + 0x24b0);
      break;
    case 7:
      uVar18 = uVar15 >> 0x1b;
      uVar15 = uVar15 >> 0x18 & 7;
      if (uVar15 == 1) {
        iVar19 = *(int *)(param_1 + 0x10) + 0x39a0 + uVar18 * 0x94;
        pdVar25 = (dword *)(iVar19 + 0x14);
        pdVar24 = (dword *)(iVar19 + 0x18);
        pdVar22 = (dword *)(iVar19 + 0x1c);
        pfVar20 = (float *)(iVar19 + 0x10);
      }
      else if (uVar15 < 2) {
        if (uVar15 != 0) goto LAB_0003ae71;
        iVar19 = *(int *)(param_1 + 0x10) + 0x3980 + uVar18 * 0x94;
        pdVar25 = (dword *)(iVar19 + 0x10);
        pdVar24 = (dword *)(iVar19 + 0x14);
        pdVar22 = (dword *)(iVar19 + 0x18);
        pfVar20 = (float *)(iVar19 + 0xc);
      }
      else if (uVar15 == 2) {
        iVar19 = *(int *)(param_1 + 0x10) + 0x39c0 + uVar18 * 0x94;
        pdVar25 = (dword *)(iVar19 + 0x18);
        pdVar24 = (dword *)(iVar19 + 0x1c);
        pdVar22 = (dword *)(iVar19 + 0x20);
        pfVar20 = (float *)(iVar19 + 0x14);
      }
      else {
        if (uVar15 != 3) goto LAB_0003ae71;
        iVar19 = *(int *)(param_1 + 0x10) + 0x39e0 + uVar18 * 0x94;
        pdVar25 = (dword *)(iVar19 + 0x1c);
        pdVar24 = (dword *)(iVar19 + 0x20);
        pdVar22 = (dword *)(iVar19 + 0x24);
        pfVar20 = (float *)(iVar19 + 0x18);
      }
      break;
    case 8:
      uVar18 = uVar15 >> 0x1b;
      uVar15 = uVar15 >> 0x18 & 7;
      if (uVar15 == 1) {
        iVar19 = *(int *)(param_1 + 0x10) + 0x39b0 + uVar18 * 0x94;
        pdVar25 = (dword *)(iVar19 + 0x14);
        pdVar24 = (dword *)(iVar19 + 0x18);
        pdVar22 = (dword *)(iVar19 + 0x1c);
        pfVar20 = (float *)(iVar19 + 0x10);
      }
      else if (uVar15 < 2) {
        if (uVar15 != 0) goto LAB_0003ae71;
        iVar19 = *(int *)(param_1 + 0x10) + 0x3990 + uVar18 * 0x94;
        pdVar25 = (dword *)(iVar19 + 0x10);
        pdVar24 = (dword *)(iVar19 + 0x14);
        pdVar22 = (dword *)(iVar19 + 0x18);
        pfVar20 = (float *)(iVar19 + 0xc);
      }
      else if (uVar15 == 2) {
        iVar19 = *(int *)(param_1 + 0x10) + 0x39d0 + uVar18 * 0x94;
        pdVar25 = (dword *)(iVar19 + 0x18);
        pdVar24 = (dword *)(iVar19 + 0x1c);
        pdVar22 = (dword *)(iVar19 + 0x20);
        pfVar20 = (float *)(iVar19 + 0x14);
      }
      else {
        if (uVar15 != 3) goto LAB_0003ae71;
        iVar19 = *(int *)(param_1 + 0x10) + 0x39f0 + uVar18 * 0x94;
        pdVar25 = (dword *)(iVar19 + 0x1c);
        pdVar24 = (dword *)(iVar19 + 0x20);
        pdVar22 = (dword *)(iVar19 + 0x24);
        pfVar20 = (float *)(iVar19 + 0x18);
      }
      break;
    case 9:
      iVar19 = (uVar15 >> 0x1b) * 0x7c + 0x31c0 + *(int *)(param_1 + 0x10);
      pdVar25 = (dword *)(iVar19 + 8);
      pdVar24 = (dword *)(iVar19 + 0xc);
      pdVar22 = (dword *)(iVar19 + 0x10);
      pfVar20 = (float *)(iVar19 + 4);
      break;
    case 10:
      iVar19 = (uVar15 >> 0x18) * 0x10 + 0x3e20 + *(int *)(param_1 + 0x10);
      pdVar25 = (dword *)(iVar19 + 0x10);
      pdVar24 = (dword *)(iVar19 + 0x14);
      pdVar22 = (dword *)(iVar19 + 0x18);
      pfVar20 = (float *)(iVar19 + 0xc);
      break;
    case 0xb:
      iVar19 = *(int *)(param_1 + 0x10);
      pdVar25 = (dword *)(iVar19 + 0x2de4);
      pdVar24 = (dword *)(iVar19 + 0x2de8);
      pdVar22 = (dword *)(iVar19 + 0x2dec);
      pfVar20 = (float *)(iVar19 + 0x2de0);
      break;
    case 0xc:
      iVar19 = *(int *)(param_1 + 0x10);
      pdVar25 = (dword *)(iVar19 + 0x2df4);
      pdVar24 = (dword *)(iVar19 + 0x2df8);
      pdVar22 = (dword *)(iVar19 + 0x2dfc);
      pfVar20 = (float *)(iVar19 + 0x2df0);
      break;
    case 0xd:
      iVar19 = *(int *)(param_1 + 0x10);
      pdVar25 = (dword *)(iVar19 + 0x30c0);
      pdVar24 = (dword *)(iVar19 + 0x30c4);
      pdVar22 = (dword *)(iVar19 + 0x30c8);
      pfVar20 = (float *)(iVar19 + 0x30bc);
      break;
    case 0xe:
      iVar19 = *(int *)(param_1 + 0x10);
      pdVar25 = (dword *)(iVar19 + 0x30d0);
      pdVar24 = (dword *)(iVar19 + 0x30d4);
      pdVar22 = (dword *)(iVar19 + 0x30d8);
      pfVar20 = (float *)(iVar19 + 0x30cc);
      break;
    case 0xf:
      *pfVar14 = (float)*(double *)(*(int *)(param_1 + 0x10) + 0x1830);
      pfVar14[1] = (float)*(double *)(*(int *)(param_1 + 0x10) + 0x1838);
      pfVar14[2] = (float)(*(double *)(*(int *)(param_1 + 0x10) + 0x1838) -
                          *(double *)(*(int *)(param_1 + 0x10) + 0x1830));
      pfVar14[3] = 1.0;
      goto LAB_0003ae98;
    case 0x12:
      fVar11 = *(float *)(*(int *)(param_1 + 0x10) + 0x24a4);
      *pfVar14 = fVar11;
      pfVar14[1] = fVar11;
      pfVar14[2] = fVar11;
      pfVar14[3] = fVar11;
      goto LAB_0003ae98;
    }
    *pfVar14 = *pfVar20;
    pfVar14[1] = (float)*pdVar25;
    pfVar14[2] = (float)*pdVar24;
    pfVar14[3] = (float)*pdVar22;
LAB_0003ae98:
    uVar6 = *(undefined8 *)(pfVar14 + 2);
    puVar13 = *(undefined8 **)(local_50 + 4);
    *puVar13 = *(undefined8 *)pfVar14;
    puVar13[1] = uVar6;
    local_50 = local_50 + 8;
  } while( true );
}

/* FUN_0003b82e @ 0x3b82e (133 bytes) */
int FUN_0003b82e(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(param_2 + 8) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 8));
    *(undefined4 *)(param_2 + 8) = 0;
  }
  if (*(int *)(param_2 + 0x10) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x10));
    *(undefined4 *)(param_2 + 0x10) = 0;
  }
  if (*(int *)(param_2 + 0x18) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x18));
    *(undefined4 *)(param_2 + 0x18) = 0;
  }
  if (*(int *)(param_2 + 0x20) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x20));
    *(undefined4 *)(param_2 + 0x20) = 0;
  }
  if (*(int *)(param_2 + 0x28) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x28));
    *(undefined4 *)(param_2 + 0x28) = 0;
  }
  FUN_00052a8e();
  return;
}

/* FUN_0003b8b3 @ 0x3b8b3 (2832 bytes) */
int FUN_0003b8b3(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  undefined4 *param_3;
{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  int iVar16;
  int iVar17;
  uint *puVar18;
  undefined4 uVar19;
  undefined4 *local_b0;
  uint *local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_5c;
  int local_58;
  uint local_4c;
  undefined4 *local_44;
  uint local_34;
  int local_30;
  undefined4 local_28 [6];
  
  if (param_2[8] != 0) {
    bVar2 = *param_2 - 0x8b30U < 2;
    FUN_00052588(param_1);
    FUN_00051e79(param_1);
    iVar17 = param_2[0x12];
    iVar8 = param_2[0x13];
    *(undefined1 *)(param_3 + 0x23) = 0;
    if (iVar17 != 0) {
      iVar4 = 0;
      do {
        if (*(char *)((int)param_2 + iVar4 * 8 + iVar8 * 8 + 3) == '\0') {
          *(undefined1 *)(param_3 + 0x23) = 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar17 != iVar4);
    }
    iVar17 = 0;
    puVar15 = param_3;
    do {
      uVar5 = FUN_00052f54(param_1,0x87bf,0x87c4,0x87e1,1);
      puVar15[0xd] = uVar5;
      uVar5 = FUN_00052f54(param_1,0x87be,0x87c4,0x87e1,1);
      puVar15[0x10] = uVar5;
      uVar5 = FUN_00052f54(param_1,0x87bf,0x87c4,0x87e1,1);
      puVar15[0x13] = uVar5;
      iVar17 = iVar17 + 1;
      puVar15 = puVar15 + 1;
    } while (iVar17 != 3);
    uVar5 = FUN_00052f54(param_1,0x87bf,0x87c4,0x87e1,1);
    param_3[0x16] = uVar5;
    uVar5 = FUN_00052f54(param_1,0x87be,0x87c4,0x87e1,1);
    param_3[0x17] = uVar5;
    iVar17 = 2;
    puVar15 = param_3;
    do {
      uVar5 = FUN_00052f54(param_1,0x87bf,0x87c4,0x87e1,1);
      puVar15[0x18] = uVar5;
      puVar15 = puVar15 + 1;
      iVar17 = iVar17 + -1;
    } while (iVar17 != 0);
    iVar17 = param_2[4];
    if (iVar17 != param_3[1]) {
      if (param_3[2] != 0) {
        (**(code **)(param_1 + 0x18))(param_3[2]);
        param_3[2] = 0;
      }
      if (iVar17 != 0) {
        uVar5 = (**(code **)(param_1 + 0x10))(iVar17,4);
        param_3[2] = uVar5;
      }
    }
    param_3[1] = iVar17;
    if (iVar17 != 0) {
      iVar8 = FUN_00052f54(param_1,0x87bf,0x87c4,0x87e1,iVar17);
      iVar4 = 0;
      do {
        *(int *)(param_3[2] + iVar4 * 4) = iVar4 + iVar8;
        iVar4 = iVar4 + 1;
      } while (iVar17 != iVar4);
    }
    iVar17 = param_2[8];
    iVar8 = param_2[9];
    if (iVar17 != param_3[3]) {
      if (param_3[4] != 0) {
        (**(code **)(param_1 + 0x18))(param_3[4]);
        param_3[4] = 0;
      }
      if (iVar17 != 0) {
        uVar5 = (**(code **)(param_1 + 0x10))(iVar17,4);
        param_3[4] = uVar5;
      }
    }
    param_3[3] = iVar17;
    if (iVar17 != 0) {
      iVar4 = param_3[4];
      iVar16 = 0;
      do {
        while( true ) {
          uVar13 = (uint)param_2[iVar8 * 2 + iVar16 * 2 + 1] >> 0x10;
          if ((byte)(((byte)((uint)param_2[iVar8 * 2 + iVar16 * 2] >> 0xc) & 0xf) - 1) < 10) break;
LAB_0003bb44:
          iVar16 = iVar16 + 1;
          if (iVar17 == iVar16) goto LAB_0003bbbf;
        }
        if ((short)((uint)param_2[iVar8 * 2 + iVar16 * 2 + 1] >> 0x10) == 0) {
          uVar5 = FUN_00053311(param_1,0x87e2);
          *(undefined4 *)(iVar4 + uVar13 * 4) = uVar5;
          goto LAB_0003bb44;
        }
        uVar5 = FUN_00052f54(param_1,0x87bf,0x87c1,0x87e1,1);
        *(undefined4 *)(iVar4 + uVar13 * 4) = uVar5;
        iVar16 = iVar16 + 1;
      } while (iVar17 != iVar16);
    }
LAB_0003bbbf:
    ((int (*)())FUN_0003a714)(param_2 + param_2[0xb] * 2,param_2[0xe],param_2 + param_2[0xf] * 2,param_2[0x1a],
                 param_2 + param_2[0x1b] * 2);
    iVar17 = param_2[0x14];
    iVar8 = param_2[0xd];
    local_70 = (uint *)(param_2 + param_2[0x15] * 2);
    if (iVar17 != 0) {
      local_68 = 0;
      do {
        uVar13 = *local_70 >> 6;
        bVar12 = (byte)uVar13;
        puVar9 = local_70 + 2;
        if (((ushort)*local_70 & 0x3fc0) == 0x1340) goto code_r0x0003bf4b;
        uVar6 = local_70[2];
        if (0x4d < bVar12) goto LAB_0003bcac;
        if (bVar12 == 0x48) {
          local_6c = param_3[0x17];
          goto LAB_0003bfae;
        }
        if ((bVar2) && (((byte)(uVar6 >> 0x10) & 0xe) != 0xc)) goto LAB_0003bcac;
        uVar7 = uVar6 >> 0xc & 7;
        if (uVar7 == 1) {
          local_6c = *(int *)(param_3[2] + (local_70[3] >> 0x10) * 4);
          goto LAB_0003bfae;
        }
        if (uVar7 != 3) {
LAB_0003bcac:
          bVar2 = false;
          cVar3 = *(char *)(param_3 + 0x23);
          goto joined_r0x0003bf72;
        }
        uVar7 = param_2[iVar8 * 2 + (local_70[3] >> 0x10) * 2];
        switch(uVar7 >> 0xc & 0xf) {
        case 0:
          local_6c = 0;
          break;
        case 1:
          local_6c = 0x879a;
          break;
        case 2:
          local_6c = 0x87bd;
          break;
        case 3:
          local_6c = 0x610e;
          break;
        case 4:
          local_6c = (-(uint)((uVar7 & 0x80000000) == 0) & 0x268c) + 0x610f;
          break;
        case 5:
          local_6c = (-(uint)((uVar7 & 0x80000000) == 0) & 0x268c) + 0x6110;
          break;
        case 6:
          local_6c = (uVar7 >> 0x1b) + 0x879d;
          break;
        default:
          goto LAB_0003bcac;
        }
LAB_0003bfae:
        if (((uVar6 & 0x78000) == 0x78000) || (bVar12 == 0x48)) {
          local_30 = local_6c;
        }
        else {
          local_30 = param_3[0x16];
        }
        if (bVar12 < 0x1f) {
LAB_0003c0f1:
          local_5c = 1;
        }
        else if (bVar12 < 0x3b) {
          local_5c = 2;
        }
        else {
          if (0x40 < bVar12) goto LAB_0003c0f1;
          local_5c = 3;
        }
        local_44 = param_3;
        local_58 = 0;
        local_b0 = local_28;
        puVar9 = local_70 + 4;
        do {
          local_70 = puVar9;
          uVar7 = *local_70;
          puVar9 = local_70 + 2;
          uVar14 = local_70[1] >> 0x10;
          if ((bVar2) && (((byte)(uVar7 >> 0x10) & 0xe) != 0xc)) goto LAB_0003bcac;
          uVar10 = uVar7 >> 6 & 7;
          if (uVar10 == 1) {
            uVar5 = *(undefined4 *)(param_3[2] + uVar14 * 4);
          }
          else if (uVar10 == 2) {
            if ((uVar7 & 1) == 0) {
              uVar5 = *(undefined4 *)(param_3[10] + uVar14 * 4);
            }
            else {
              FUN_00052b11(param_1,0x8782,local_44[0x13],param_3[0x17],
                           *(undefined4 *)(param_3[10] + (uVar14 + ((int)uVar7 >> 0x18)) * 4));
              uVar5 = local_44[0x13];
            }
          }
          else if (uVar10 == 0) {
            uVar5 = *(undefined4 *)(param_3[4] + uVar14 * 4);
          }
          else {
            uVar5 = 0;
          }
          local_28[local_58] = uVar5;
          if ((uVar7 & 0x10) == 0) {
            local_64 = (uVar7 >> 9 & 3) + 0x87d5;
            iVar4 = (uVar7 >> 0xb & 3) + 0x87d5;
            iVar16 = (uVar7 >> 0xd & 3) + 0x87d5;
            iVar11 = (uVar7 >> 0xf & 3) + 0x87d5;
          }
          else {
            local_64 = (uVar7 >> 9 & 3) + 0x87d9;
            iVar4 = (uVar7 >> 0xb & 3) + 0x87d9;
            iVar16 = (uVar7 >> 0xd & 3) + 0x87d9;
            iVar11 = (uVar7 >> 0xf & 3) + 0x87d9;
          }
          if ((((local_64 != 0x87d5) || (iVar4 != 0x87d6)) || (iVar16 != 0x87d7)) ||
             (iVar11 != 0x87d8)) {
            FUN_00052bf0(param_1,local_44[0xd],*local_b0,local_64,iVar4,iVar16,iVar11);
            *local_b0 = local_44[0xd];
          }
          uVar5 = local_28[1];
          local_58 = local_58 + 1;
          local_b0 = local_b0 + 1;
          local_44 = local_44 + 1;
        } while (local_5c != local_58);
        switch(uVar13 & 0xff) {
        case 0:
          FUN_00052aa0(param_1,0x8799,local_30,local_28[0]);
          local_70 = puVar9;
          break;
        case 1:
          FUN_00052aa0(param_1,0x879e,local_30,local_28[0]);
          local_70 = puVar9;
          break;
        case 2:
          FUN_00052bf0(param_1,param_3[0x18],local_28[0],0x87d9,0x87da,0x87db,0x87dc);
          FUN_00052b11(param_1,0x878a,local_30,local_28[0],param_3[0x18]);
          local_70 = puVar9;
          break;
        default:
          goto LAB_0003bcac;
        case 4:
          FUN_00052aa0(param_1,0x8789,local_30,local_28[0]);
          local_70 = puVar9;
          break;
        case 5:
          FUN_00052aa0(param_1,0x878f,local_30,local_28[0]);
          local_70 = puVar9;
          break;
        case 0xd:
          FUN_00052bf0(param_1,param_3[0x18],local_28[0],0x87d9,0x87da,0x87db,0x87dc);
          FUN_00052b11(param_1,0x878a,param_3[0x19],local_28[0],param_3[0x18]);
          FUN_00052eb4(param_1,param_3[0x10],param_3[0x19],0);
          uVar5 = param_3[0x10];
          uVar19 = param_3[0x11];
          puVar18 = (uint *)0x8795;
          goto code_r0x0003c835;
        case 0xe:
          FUN_00052eb4(param_1,param_3[0x10],local_28[0],0);
          uVar5 = param_3[0x10];
          uVar19 = param_3[0x11];
          puVar18 = &UINT_00008794;
          goto code_r0x0003c835;
        case 0x10:
          FUN_00052eb4(param_1,param_3[0x10],local_28[0],0);
          uVar5 = param_3[0x10];
          uVar19 = param_3[0x11];
          puVar18 = (uint *)0x8791;
          goto code_r0x0003c835;
        case 0x11:
          FUN_00052aa0(param_1,&UINT_000087a0,local_30,local_28[0]);
          local_70 = puVar9;
          break;
        case 0x13:
          FUN_00052eb4(param_1,param_3[0x10],local_28[0],0);
          uVar5 = param_3[0x10];
          uVar19 = param_3[0x11];
          puVar18 = (uint *)0x8792;
code_r0x0003c835:
          FUN_00052aa0(param_1,puVar18,uVar19,uVar5);
          FUN_00052aa0(param_1,0x8799,local_30,param_3[0x11]);
          local_70 = puVar9;
          break;
        case 0x14:
          FUN_00052aa0(param_1,0x87a1,local_30,local_28[0]);
          local_70 = puVar9;
          break;
        case 0x1f:
          FUN_00052b11(param_1,((unsigned char *)0x00008787),local_30,local_28[0],local_28[1]);
          local_70 = puVar9;
          break;
        case 0x20:
          FUN_00052b11(param_1,0x8796,local_30,local_28[0],local_28[1]);
          local_70 = puVar9;
          break;
        case 0x22:
          FUN_00052b11(param_1,((unsigned char *)0x00008786),local_30,local_28[0],local_28[1]);
          local_70 = puVar9;
          break;
        case 0x28:
          FUN_00052b11(param_1,0x8784,local_30,local_28[0],local_28[1]);
          local_70 = puVar9;
          break;
        case 0x29:
          uVar5 = local_28[0];
          goto code_r0x0003ca36;
        case 0x2a:
          FUN_00052bf0(param_1,param_3[0x18],local_28[0],0x87d5,0x87d6,0x87d7,0x87de);
          uVar5 = param_3[0x18];
code_r0x0003ca36:
          FUN_00052b11(param_1,((unsigned char *)0x00008785),local_30,uVar5,local_28[1]);
          local_70 = puVar9;
          break;
        case 0x2b:
          FUN_00052b11(param_1,0x879f,local_30,local_28[0],local_28[1]);
          local_70 = puVar9;
          break;
        case 0x2c:
          FUN_00052b11(param_1,0x878b,local_30,local_28[0],local_28[1]);
          local_70 = puVar9;
          break;
        case 0x2d:
          FUN_00052b11(param_1,0x878a,local_30,local_28[0],local_28[1]);
          local_70 = puVar9;
          break;
        case 0x2e:
          FUN_00052b11(param_1,0x8797,local_30,local_28[0],local_28[1]);
          local_70 = puVar9;
          break;
        case 0x32:
          FUN_00052b11(param_1,&UINT_0000878c,local_30,local_28[0],local_28[1]);
          local_70 = puVar9;
          break;
        case 0x35:
          FUN_00052b11(param_1,0x878d,local_30,local_28[0],local_28[1]);
          local_70 = puVar9;
          break;
        case 0x38:
          FUN_00052eb4(param_1,param_3[0x10],local_28[0],0);
          FUN_00052eb4(param_1,param_3[0x11],uVar5,0);
          FUN_00052b11(param_1,0x8793,param_3[0x12],param_3[0x10],param_3[0x11]);
          FUN_00052aa0(param_1,0x8799,local_30,param_3[0x12]);
          local_70 = puVar9;
          break;
        case 0x3f:
          FUN_00052b81(param_1,&switchdataD_00008788,local_30,local_28[0],
                       local_28[1],local_28[2]);
          local_70 = puVar9;
          break;
        case 0x41:
          uVar13 = *puVar9;
          local_70 = local_70 + 4;
          iVar4 = *(int *)((uVar13 >> 0x10 & 0xf) * 4 + 0x1ed1a0);
          iVar16 = *(int *)((uVar13 >> 0x14 & 0xf) * 4 + 0x1ed1a0);
          iVar11 = *(int *)((uVar13 >> 0x18 & 0xf) * 4 + 0x1ed1a0);
          iVar1 = *(int *)((uVar13 >> 0x1c) * 4 + 0x1ed1a0);
          if (((iVar4 != 0x87d5) || (iVar16 != 0x87d6)) || ((iVar11 != 0x87d7 || (iVar1 != 0x87d8)))
             ) {
            FUN_00052bf0(param_1,local_30,local_28[0],iVar4,iVar16,iVar11,iVar1);
          }
          break;
        case 0x48:
          FUN_00052eb4(param_1,local_30,local_28[0],0);
          local_70 = puVar9;
        }
        puVar9 = local_70;
        if (((uVar6 & 0x78000) != 0x78000) && (bVar12 != 0x48)) {
          FUN_00052ce1(param_1,local_6c,local_30,uVar6 >> 0x12 & 1,uVar6 >> 0x11 & 1,
                       uVar6 >> 0x10 & 1,uVar6 >> 0xf & 1);
        }
code_r0x0003bf4b:
        local_70 = puVar9;
        local_68 = local_68 + 1;
      } while (iVar17 != local_68);
    }
    bVar2 = true;
    cVar3 = *(char *)(param_3 + 0x23);
joined_r0x0003bf72:
    if (cVar3 == '\0') {
      FUN_00052610(param_1);
    }
    else {
      uVar5 = *(undefined4 *)param_3[4];
      uVar19 = param_3[0x16];
      FUN_00052b11(param_1,((unsigned char *)0x00008785),uVar19,uVar5,param_3[0x1a]);
      FUN_00052ce1(param_1,0x879a,uVar19,1,0,0,0);
      FUN_00052b11(param_1,((unsigned char *)0x00008785),uVar19,uVar5,param_3[0x1b]);
      FUN_00052ce1(param_1,0x879a,uVar19,0,1,0,0);
      FUN_00052b11(param_1,((unsigned char *)0x00008785),uVar19,uVar5,param_3[0x1c]);
      FUN_00052ce1(param_1,0x879a,uVar19,0,0,1,0);
      FUN_00052b11(param_1,((unsigned char *)0x00008785),uVar19,uVar5,param_3[0x1d]);
      FUN_00052ce1(param_1,0x879a,uVar19,0,0,0,1);
      FUN_00052610(param_1);
    }
    if (!bVar2) {
      FUN_00051ea5(param_1);
      return 0;
    }
    cVar3 = FUN_00051e7e(param_1);
    if (cVar3 != '\0') {
      uVar13 = param_3[3];
      if (uVar13 != param_3[5]) {
        if (param_3[6] != 0) {
          (**(code **)(param_1 + 0x18))(param_3[6]);
          param_3[6] = 0;
        }
        if (uVar13 != 0) {
          uVar5 = (**(code **)(param_1 + 0x10))(uVar13,4);
          param_3[6] = uVar5;
        }
      }
      param_3[5] = uVar13;
      if (uVar13 != 0) {
        puVar15 = (undefined4 *)param_3[6];
        *puVar15 = 0x308c0;
        if (1 < uVar13) {
          local_4c = 1;
          do {
            uVar5 = FUN_00051d6d(param_1,*(undefined4 *)(param_3[4] + local_4c * 4));
            puVar15[local_4c] = uVar5;
            local_4c = local_4c + 1;
          } while (uVar13 != local_4c);
        }
      }
      uVar13 = param_3[3];
      if (uVar13 != param_3[7]) {
        if (param_3[8] != 0) {
          (**(code **)(param_1 + 0x18))(param_3[8]);
          param_3[8] = 0;
        }
        if (uVar13 != 0) {
          uVar5 = (**(code **)(param_1 + 0x10))(uVar13,4);
          param_3[8] = uVar5;
        }
      }
      param_3[7] = uVar13;
      if (uVar13 != 0) {
        puVar15 = (undefined4 *)param_3[8];
        uVar6 = 0;
        do {
          puVar15[uVar6] = 0x80;
          uVar6 = uVar6 + 1;
        } while (uVar13 != uVar6);
        *puVar15 = 0;
        if (1 < uVar13) {
          local_34 = 1;
          do {
            iVar17 = FUN_00051dd3(param_1,*(undefined4 *)(param_3[4] + local_34 * 4));
            if (iVar17 + -1 != 0x80) {
              puVar15[iVar17 + -1] = local_34;
            }
            local_34 = local_34 + 1;
          } while (uVar13 != local_34);
        }
      }
      FUN_00051ebb(param_1,*param_3,param_3 + 0x1e);
      return 1;
    }
  }
  return 0;
}

/* FUN_0003cca2 @ 0x3cca2 (1155 bytes) */
int FUN_0003cca2(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  undefined4 *puVar1;
  float *pfVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  byte bVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  float fVar13;
  byte *pbVar14;
  char cVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  undefined4 *puVar19;
  float *pfVar20;
  uint uVar21;
  int iVar22;
  float *pfVar23;
  byte bVar24;
  undefined8 *puVar25;
  dword *pdVar26;
  uint uVar27;
  dword *pdVar28;
  dword *pdVar29;
  float fVar30;
  float fVar31;
  undefined4 *local_5c;
  byte *local_58;
  int local_40;
  int local_28;
  int local_24;
  byte *local_20 [4];
  
  iVar16 = param_1 + 0x240;
  cVar15 = FUN_00052f7b(iVar16,local_20,&local_24,&local_28);
  if (cVar15 != '\0') {
    ((int (*)())FUN_0003aa46)(param_3,param_4);
  }
  local_5c = (undefined4 *)
             (**(code **)(param_1 + 0x2998))(iVar16,*(int *)(local_20[0] + 0x808) * 7 + 2);
  *(undefined4 **)(param_1 + 0x298c) = local_5c;
  iVar10 = *(int *)(local_20[0] + 0x800);
  *local_5c = 0x8a1;
  local_5c[1] = 0;
  local_5c = local_5c + 2;
  if (local_20[0] < local_20[0] + iVar10 * 8) {
    iVar22 = *(int *)(param_1 + 0x10) + 0x1860;
    local_58 = local_20[0];
    do {
      bVar9 = *local_58;
      puVar1 = *(undefined4 **)(local_58 + 4);
      uVar3 = *(undefined4 *)(iVar22 + (uint)*(ushort *)(local_58 + 2) * 4);
      iVar18 = (uint)*(ushort *)(local_58 + 2) * 4 + iVar22;
      uVar11 = *(undefined4 *)(iVar18 + 0x10);
      uVar12 = *(undefined4 *)(iVar18 + 0x20);
      uVar4 = *(undefined4 *)(iVar18 + 0x30);
      puVar19 = (undefined4 *)((uint)bVar9 * 0x10 + local_24);
      *puVar19 = uVar3;
      puVar19[1] = uVar11;
      puVar19[2] = uVar12;
      puVar19[3] = uVar4;
      *puVar1 = uVar3;
      puVar1[1] = uVar11;
      puVar1[2] = uVar12;
      puVar1[3] = uVar4;
      *local_5c = 0x880;
      local_5c[1] = (uint)bVar9 + local_28;
      local_5c[2] = 0x38882;
      local_5c[3] = uVar3;
      local_5c[4] = uVar11;
      local_5c[5] = uVar12;
      local_5c[6] = uVar4;
      local_5c = local_5c + 7;
      local_58 = local_58 + 8;
    } while (local_58 < local_20[0] + iVar10 * 8);
  }
  else {
    local_58 = local_20[0];
  }
  iVar10 = *(int *)(local_20[0] + 0x804);
  pbVar14 = local_58;
  while (local_58 = pbVar14, local_58 < local_20[0] + iVar10 * 8) {
    pbVar14 = local_58 + 8;
    if ((*(uint *)(param_6 + ((int)(uint)local_58[1] >> 5) * 4) >> (local_58[1] & 0x1f) & 1) != 0) {
      puVar25 = *(undefined8 **)(local_58 + 4);
      bVar9 = *local_58;
      *local_5c = 0x880;
      local_5c[2] = 0x38882;
      uVar7 = *puVar25;
      uVar8 = puVar25[1];
      local_5c[1] = local_28 + (uint)bVar9;
      puVar25 = (undefined8 *)((uint)bVar9 * 0x10 + local_24);
      *(undefined8 *)(local_5c + 3) = uVar7;
      *puVar25 = uVar7;
      *(undefined8 *)(local_5c + 5) = uVar8;
      puVar25[1] = uVar8;
      local_5c = local_5c + 7;
    }
  }
  iVar10 = *(int *)(local_20[0] + 0x808);
  for (; local_58 < local_20[0] + iVar10 * 8; local_58 = local_58 + 8) {
    while ((*(uint *)(param_6 + ((int)(uint)local_58[1] >> 5) * 4) >> (local_58[1] & 0x1f) & 1) != 0
          ) {
      bVar9 = *local_58;
      uVar17 = *(uint *)(param_4 + (uint)*(ushort *)(local_58 + 2) * 8);
      bVar24 = (byte)(uVar17 >> 0xb) & 0x1f;
      *local_5c = 0x880;
      local_5c[1] = local_28 + (uint)bVar9;
      local_5c[2] = 0x38882;
      fVar13 = FLOAT_001c5ba4;
      pfVar20 = (float *)(local_5c + 3);
      if (bVar24 == 1) {
        puVar1 = (undefined4 *)((uVar17 >> 0x10) * 0x10 + param_5);
        if (*(int *)(*(int *)(param_1 + 0x18) + 0x198) == 0) {
          local_5c[3] = *puVar1;
          local_5c[4] = puVar1[1];
          local_5c[5] = puVar1[2];
          local_5c[6] = puVar1[3];
        }
        else {
          _glpUniformToFloat(*(undefined4 *)(**(int **)(param_1 + 0x1cc) + 4),uVar17 >> 0x10,puVar1,
                             pfVar20);
        }
        goto LAB_0003cefb;
      }
      if (((byte)(uVar17 >> 8) & 0xf8) == 0x80) {
        uVar27 = uVar17 >> 0x12 & 3;
        uVar21 = uVar17 >> 0x18;
        switch(uVar17 >> 0x15 & 7) {
        default:
          iVar22 = 0;
          break;
        case 1:
          iVar22 = 0xc0;
          break;
        case 2:
          iVar22 = 0x80;
          break;
        case 3:
          iVar22 = (uVar21 + 4) * 0x40;
          break;
        case 4:
          iVar22 = (uVar21 + 0x10) * 0x40;
          break;
        case 5:
          iVar22 = (uVar21 + 8) * 0x40;
        }
        uVar17 = uVar17 >> 0x10 & 3;
        local_40 = *(int *)(param_1 + 0x10) + 0x1860 + iVar22;
        if ((1 < uVar17) && (local_40 = *(int *)(param_1 + 0x10) + 0x1e60 + iVar22, 3 < uVar17)) {
          local_40 = 0;
        }
        if (uVar17 < 3) {
          if (uVar17 == 0) {
LAB_0003d10d:
            iVar22 = uVar27 * 4;
            *pfVar20 = *(float *)(local_40 + iVar22);
            iVar22 = iVar22 + local_40;
            local_5c[4] = *(undefined4 *)(iVar22 + 0x10);
            local_5c[5] = *(undefined4 *)(iVar22 + 0x20);
            local_5c[6] = *(undefined4 *)(iVar22 + 0x30);
          }
          else {
            iVar22 = uVar27 * 0x10;
            *pfVar20 = *(float *)(local_40 + iVar22);
            iVar22 = iVar22 + local_40;
            local_5c[4] = *(undefined4 *)(iVar22 + 4);
            local_5c[5] = *(undefined4 *)(iVar22 + 8);
            local_5c[6] = *(undefined4 *)(iVar22 + 0xc);
          }
        }
        else if (uVar17 == 3) goto LAB_0003d10d;
        goto LAB_0003cefb;
      }
      switch(bVar24) {
      case 0:
        pdVar29 = local_5c + 4;
        pdVar28 = local_5c + 5;
        pdVar26 = local_5c + 6;
        pfVar23 = pfVar20;
        break;
      default:
LAB_0003ced4:
        pdVar29 = &MACH_HEADER.cputype;
        pdVar28 = &MACH_HEADER.cpusubtype;
        pdVar26 = &MACH_HEADER.filetype;
        pfVar23 = (float *)0x0;
        break;
      case 2:
        pfVar23 = (float *)((uVar17 >> 0x10) * 0x10 + *(int *)(*(int *)(param_1 + 0x10) + 0x4308));
        pdVar29 = (dword *)(pfVar23 + 1);
        pdVar28 = (dword *)(pfVar23 + 2);
        pdVar26 = (dword *)(pfVar23 + 3);
        break;
      case 3:
        uVar21 = uVar17 >> 0x18;
        switch(uVar17 >> 0x14 & 0xf) {
        case 0:
          pfVar23 = (float *)(uVar21 * 0x80 + 0x24c0 + *(int *)(param_1 + 0x10));
          pdVar29 = (dword *)(pfVar23 + 1);
          pdVar28 = (dword *)(pfVar23 + 2);
          pdVar26 = (dword *)(pfVar23 + 3);
          break;
        case 1:
          pfVar23 = (float *)(uVar21 * 0x80 + 0x24d0 + *(int *)(param_1 + 0x10));
          pdVar29 = (dword *)(pfVar23 + 1);
          pdVar28 = (dword *)(pfVar23 + 2);
          pdVar26 = (dword *)(pfVar23 + 3);
          break;
        case 2:
          pfVar23 = (float *)(uVar21 * 0x80 + 0x24e0 + *(int *)(param_1 + 0x10));
          pdVar29 = (dword *)(pfVar23 + 1);
          pdVar28 = (dword *)(pfVar23 + 2);
          pdVar26 = (dword *)(pfVar23 + 3);
          break;
        case 3:
          pfVar23 = (float *)(uVar21 * 0x80 + 0x24f0 + *(int *)(param_1 + 0x10));
          pdVar29 = (dword *)(pfVar23 + 1);
          pdVar28 = (dword *)(pfVar23 + 2);
          pdVar26 = (dword *)(pfVar23 + 3);
          break;
        case 4:
          pfVar23 = (float *)(uVar21 * 0x80 + 0x2500 + *(int *)(param_1 + 0x10));
          pdVar29 = (dword *)(pfVar23 + 1);
          pdVar28 = (dword *)(pfVar23 + 2);
          pdVar26 = (dword *)(pfVar23 + 3);
          break;
        case 5:
          pfVar23 = (float *)(uVar21 * 0x80 + 0x2510 + *(int *)(param_1 + 0x10));
          pdVar29 = (dword *)(pfVar23 + 1);
          pdVar28 = (dword *)(pfVar23 + 2);
          pdVar26 = (dword *)(pfVar23 + 3);
          break;
        case 6:
          iVar22 = uVar21 * 0x80 + *(int *)(param_1 + 0x10);
          fVar5 = *(float *)(iVar22 + 0x24f0);
          fVar6 = *(float *)(iVar22 + 0x24f4);
          fVar31 = *(float *)(iVar22 + 0x24f8) + FLOAT_001c5ba4;
          fVar30 = (float)(DOUBLE_001cf330 /
                          SQRT((double)(fVar5 * fVar5 + fVar6 * fVar6 + fVar31 * fVar31)));
          *pfVar20 = fVar5 * fVar30;
          local_5c[4] = fVar6 * fVar30;
          local_5c[5] = fVar31 * fVar30;
          local_5c[6] = fVar13;
          goto LAB_0003cefb;
        case 7:
          pfVar23 = (float *)(uVar21 * 0x80 + 0x2530 + *(int *)(param_1 + 0x10));
          pdVar29 = (dword *)(pfVar23 + 1);
          pdVar28 = (dword *)(pfVar23 + 2);
          pdVar26 = (dword *)(pfVar23 + 3);
          break;
        default:
          goto LAB_0003ced4;
        }
        break;
      case 4:
        pfVar23 = (float *)(*(int *)(param_1 + 0x10) + 0x28c0 + (uVar17 >> 0x17 & 1) * 0x240);
        pfVar2 = (float *)(*(int *)(param_1 + 0x10) + 0x24c0 + (uVar17 >> 0x18) * 0x80);
        uVar17 = uVar17 >> 0x15 & 3;
        if (uVar17 == 1) {
          *pfVar20 = pfVar2[4] * pfVar23[4];
          local_5c[4] = pfVar2[5] * pfVar23[5];
          local_5c[5] = pfVar2[6] * pfVar23[6];
          local_5c[6] = pfVar23[7];
        }
        else if (uVar17 == 2) {
          *pfVar20 = pfVar2[8] * pfVar23[8];
          local_5c[4] = pfVar2[9] * pfVar23[9];
          local_5c[5] = pfVar2[10] * pfVar23[10];
          local_5c[6] = pfVar23[0xb];
        }
        else {
          if (uVar17 != 0) goto LAB_0003ced4;
          *pfVar20 = *pfVar2 * *pfVar23;
          local_5c[4] = pfVar2[1] * pfVar23[1];
          local_5c[5] = pfVar2[2] * pfVar23[2];
          local_5c[6] = pfVar23[3];
        }
        goto LAB_0003cefb;
      case 5:
        iVar22 = (int)uVar17 >> 0x1f;
        switch(uVar17 >> 0x1c & 7) {
        case 0:
          pfVar23 = (float *)(iVar22 * -0x240 + 0x28c0 + *(int *)(param_1 + 0x10));
          pdVar29 = (dword *)(pfVar23 + 1);
          pdVar28 = (dword *)(pfVar23 + 2);
          pdVar26 = (dword *)(pfVar23 + 3);
          break;
        case 1:
          pfVar23 = (float *)(iVar22 * -0x240 + 0x28d0 + *(int *)(param_1 + 0x10));
          pdVar29 = (dword *)(pfVar23 + 1);
          pdVar28 = (dword *)(pfVar23 + 2);
          pdVar26 = (dword *)(pfVar23 + 3);
          break;
        case 2:
          pfVar23 = (float *)(iVar22 * -0x240 + 0x28e0 + *(int *)(param_1 + 0x10));
          pdVar29 = (dword *)(pfVar23 + 1);
          pdVar28 = (dword *)(pfVar23 + 2);
          pdVar26 = (dword *)(pfVar23 + 3);
          break;
        case 3:
          pfVar23 = (float *)(iVar22 * -0x240 + 0x28f0 + *(int *)(param_1 + 0x10));
          pdVar29 = (dword *)(pfVar23 + 1);
          pdVar28 = (dword *)(pfVar23 + 2);
          pdVar26 = (dword *)(pfVar23 + 3);
          break;
        case 4:
          pfVar23 = (float *)(iVar22 * -0x240 + 0x2900 + *(int *)(param_1 + 0x10));
          pdVar29 = (dword *)(pfVar23 + 1);
          pdVar28 = (dword *)(pfVar23 + 2);
          pdVar26 = (dword *)(pfVar23 + 3);
          break;
        case 5:
          iVar18 = *(int *)(param_1 + 0x10);
          pfVar23 = (float *)(iVar18 + 0x28c0 + iVar22 * -0x240);
          *pfVar20 = *(float *)(iVar18 + 0x24b0) * *pfVar23 + pfVar23[0xc];
          local_5c[4] = *(float *)(iVar18 + 0x24b4) * pfVar23[1] + pfVar23[0xd];
          local_5c[5] = *(float *)(iVar18 + 0x24b8) * pfVar23[2] + pfVar23[0xe];
          local_5c[6] = pfVar23[7];
          goto LAB_0003cefb;
        default:
          goto LAB_0003ced4;
        }
        break;
      case 6:
        iVar22 = *(int *)(param_1 + 0x10);
        pdVar29 = (dword *)(iVar22 + 0x24b4);
        pdVar28 = (dword *)(iVar22 + 0x24b8);
        pdVar26 = (dword *)(iVar22 + 0x24bc);
        pfVar23 = (float *)(iVar22 + 0x24b0);
        break;
      case 7:
        uVar21 = uVar17 >> 0x1b;
        uVar17 = uVar17 >> 0x18 & 7;
        if (uVar17 == 1) {
          iVar22 = *(int *)(param_1 + 0x10) + 0x39a0 + uVar21 * 0x94;
          pdVar29 = (dword *)(iVar22 + 0x14);
          pdVar28 = (dword *)(iVar22 + 0x18);
          pdVar26 = (dword *)(iVar22 + 0x1c);
          pfVar23 = (float *)(iVar22 + 0x10);
        }
        else if (uVar17 < 2) {
          if (uVar17 != 0) goto LAB_0003ced4;
          iVar22 = *(int *)(param_1 + 0x10) + 0x3980 + uVar21 * 0x94;
          pdVar29 = (dword *)(iVar22 + 0x10);
          pdVar28 = (dword *)(iVar22 + 0x14);
          pdVar26 = (dword *)(iVar22 + 0x18);
          pfVar23 = (float *)(iVar22 + 0xc);
        }
        else if (uVar17 == 2) {
          iVar22 = *(int *)(param_1 + 0x10) + 0x39c0 + uVar21 * 0x94;
          pdVar29 = (dword *)(iVar22 + 0x18);
          pdVar28 = (dword *)(iVar22 + 0x1c);
          pdVar26 = (dword *)(iVar22 + 0x20);
          pfVar23 = (float *)(iVar22 + 0x14);
        }
        else {
          if (uVar17 != 3) goto LAB_0003ced4;
          iVar22 = *(int *)(param_1 + 0x10) + 0x39e0 + uVar21 * 0x94;
          pdVar29 = (dword *)(iVar22 + 0x1c);
          pdVar28 = (dword *)(iVar22 + 0x20);
          pdVar26 = (dword *)(iVar22 + 0x24);
          pfVar23 = (float *)(iVar22 + 0x18);
        }
        break;
      case 8:
        uVar21 = uVar17 >> 0x1b;
        uVar17 = uVar17 >> 0x18 & 7;
        if (uVar17 == 1) {
          iVar22 = *(int *)(param_1 + 0x10) + 0x39b0 + uVar21 * 0x94;
          pdVar29 = (dword *)(iVar22 + 0x14);
          pdVar28 = (dword *)(iVar22 + 0x18);
          pdVar26 = (dword *)(iVar22 + 0x1c);
          pfVar23 = (float *)(iVar22 + 0x10);
        }
        else if (uVar17 < 2) {
          if (uVar17 != 0) goto LAB_0003ced4;
          iVar22 = *(int *)(param_1 + 0x10) + 0x3990 + uVar21 * 0x94;
          pdVar29 = (dword *)(iVar22 + 0x10);
          pdVar28 = (dword *)(iVar22 + 0x14);
          pdVar26 = (dword *)(iVar22 + 0x18);
          pfVar23 = (float *)(iVar22 + 0xc);
        }
        else if (uVar17 == 2) {
          iVar22 = *(int *)(param_1 + 0x10) + 0x39d0 + uVar21 * 0x94;
          pdVar29 = (dword *)(iVar22 + 0x18);
          pdVar28 = (dword *)(iVar22 + 0x1c);
          pdVar26 = (dword *)(iVar22 + 0x20);
          pfVar23 = (float *)(iVar22 + 0x14);
        }
        else {
          if (uVar17 != 3) goto LAB_0003ced4;
          iVar22 = *(int *)(param_1 + 0x10) + 0x39f0 + uVar21 * 0x94;
          pdVar29 = (dword *)(iVar22 + 0x1c);
          pdVar28 = (dword *)(iVar22 + 0x20);
          pdVar26 = (dword *)(iVar22 + 0x24);
          pfVar23 = (float *)(iVar22 + 0x18);
        }
        break;
      case 9:
        iVar22 = (uVar17 >> 0x1b) * 0x7c + 0x31c0 + *(int *)(param_1 + 0x10);
        pdVar29 = (dword *)(iVar22 + 8);
        pdVar28 = (dword *)(iVar22 + 0xc);
        pdVar26 = (dword *)(iVar22 + 0x10);
        pfVar23 = (float *)(iVar22 + 4);
        break;
      case 10:
        iVar22 = (uVar17 >> 0x18) * 0x10 + 0x3e20 + *(int *)(param_1 + 0x10);
        pdVar29 = (dword *)(iVar22 + 0x10);
        pdVar28 = (dword *)(iVar22 + 0x14);
        pdVar26 = (dword *)(iVar22 + 0x18);
        pfVar23 = (float *)(iVar22 + 0xc);
        break;
      case 0xb:
        iVar22 = *(int *)(param_1 + 0x10);
        pdVar29 = (dword *)(iVar22 + 0x2de4);
        pdVar28 = (dword *)(iVar22 + 0x2de8);
        pdVar26 = (dword *)(iVar22 + 0x2dec);
        pfVar23 = (float *)(iVar22 + 0x2de0);
        break;
      case 0xc:
        iVar22 = *(int *)(param_1 + 0x10);
        pdVar29 = (dword *)(iVar22 + 0x2df4);
        pdVar28 = (dword *)(iVar22 + 0x2df8);
        pdVar26 = (dword *)(iVar22 + 0x2dfc);
        pfVar23 = (float *)(iVar22 + 0x2df0);
        break;
      case 0xd:
        iVar22 = *(int *)(param_1 + 0x10);
        pdVar29 = (dword *)(iVar22 + 0x30c0);
        pdVar28 = (dword *)(iVar22 + 0x30c4);
        pdVar26 = (dword *)(iVar22 + 0x30c8);
        pfVar23 = (float *)(iVar22 + 0x30bc);
        break;
      case 0xe:
        iVar22 = *(int *)(param_1 + 0x10);
        pdVar29 = (dword *)(iVar22 + 0x30d0);
        pdVar28 = (dword *)(iVar22 + 0x30d4);
        pdVar26 = (dword *)(iVar22 + 0x30d8);
        pfVar23 = (float *)(iVar22 + 0x30cc);
        break;
      case 0xf:
        *pfVar20 = (float)*(double *)(*(int *)(param_1 + 0x10) + 0x1830);
        local_5c[4] = (float)*(double *)(*(int *)(param_1 + 0x10) + 0x1838);
        local_5c[5] = (float)(*(double *)(*(int *)(param_1 + 0x10) + 0x1838) -
                             *(double *)(*(int *)(param_1 + 0x10) + 0x1830));
        local_5c[6] = 0x3f800000;
        goto LAB_0003cefb;
      case 0x12:
        fVar13 = *(float *)(*(int *)(param_1 + 0x10) + 0x24a4);
        *pfVar20 = fVar13;
        local_5c[4] = fVar13;
        local_5c[5] = fVar13;
        local_5c[6] = fVar13;
        goto LAB_0003cefb;
      }
      *pfVar20 = *pfVar23;
      local_5c[4] = *pdVar29;
      local_5c[5] = *pdVar28;
      local_5c[6] = *pdVar26;
LAB_0003cefb:
      uVar7 = *(undefined8 *)pfVar20;
      uVar8 = *(undefined8 *)(local_5c + 5);
      local_5c = local_5c + 7;
      puVar25 = (undefined8 *)(local_24 + (uint)bVar9 * 0x10);
      *puVar25 = uVar7;
      puVar25[1] = uVar8;
      puVar25 = *(undefined8 **)(local_58 + 4);
      *puVar25 = uVar7;
      puVar25[1] = uVar8;
      local_58 = local_58 + 8;
      if (local_20[0] + iVar10 * 8 <= local_58) goto LAB_0003cf3f;
    }
  }
LAB_0003cf3f:
  *(undefined4 **)(param_1 + 0x298c) = local_5c;
  (**(code **)(param_1 + 0x299c))(iVar16,local_5c);
  return;
}

/* FUN_0003d90a @ 0x3d90a (148 bytes) */
int FUN_0003d90a(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int local_10;
  
  local_10 = param_1;
  iVar3 = 0;
  uVar1 = *(uint *)(param_1 + 0x29fc);
  do {
    while( true ) {
      if (*(int *)(local_10 + 0x18c) == 0) {
        uVar2 = 0xff;
      }
      else {
        uVar2 = **(ushort **)(*(int *)(local_10 + 0x18c) + 0x30) & 0xf;
      }
      if (uVar2 == *(uint *)(local_10 + 0x2a00)) break;
      uVar1 = uVar1 | 1 << ((byte)iVar3 & 0x1f);
      *(uint *)(param_1 + 0x29fc) = uVar1;
      *(uint *)(local_10 + 0x2a00) = uVar2;
      iVar3 = iVar3 + 1;
      local_10 = local_10 + 4;
      if (iVar3 == 0x10) {
        return;
      }
    }
    uVar1 = ~(1 << ((byte)iVar3 & 0x1f)) & uVar1;
    *(uint *)(param_1 + 0x29fc) = uVar1;
    iVar3 = iVar3 + 1;
    local_10 = local_10 + 4;
  } while (iVar3 != 0x10);
  return;
}

/* FUN_0003d99e @ 0x3d99e (159 bytes) */
int FUN_0003d99e(param_1)
  int param_1;
{
  undefined1 *puVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint local_5c [15];
  undefined1 auStack_1d [17];
  
  if (*(int *)(param_1 + 0x29fc) != 0) {
    iVar3 = 1;
    puVar1 = auStack_1d + 1;
    iVar4 = param_1;
    puVar5 = local_5c;
LAB_0003d9db:
    do {
      if (*(int *)(iVar4 + 0x18c) == 0) {
        puVar1[iVar3 + -1] = 0;
        *puVar5 = 0;
      }
      else {
        uVar2 = **(ushort **)(*(int *)(iVar4 + 0x18c) + 0x30);
        puVar1[iVar3 + -1] = 1;
        if ((uVar2 & 0xf) != 0) {
          *puVar5 = (uint)((uVar2 & 0xf) == 1);
          iVar3 = iVar3 + 1;
          puVar5 = puVar5 + 1;
          iVar4 = iVar4 + 4;
          if (iVar3 == 0x11) break;
          goto LAB_0003d9db;
        }
        *puVar5 = 2;
      }
      iVar3 = iVar3 + 1;
      puVar5 = puVar5 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar3 != 0x11);
    FUN_0009fe06(param_1 + 0x240,puVar1,local_5c);
  }
  return;
}

/* FUN_0003da3d @ 0x3da3d (115 bytes) */
int FUN_0003da3d(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  piVar1 = *(int **)(param_1 + 0x1d0);
  ((int (*)())FUN_0003d99e)(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    puVar3 = *(uint **)(iVar2 + 4);
    uVar4 = *puVar3;
    ((int (*)())FUN_0003db02)(param_1 + 0x240,*(int *)(param_1 + 0x29ec) + 0x14,(uVar4 & 0xff0000) >> 0x10,
                 puVar3 + (uVar4 & 0xffff),*(int *)(param_1 + 0x10) + 0x1010,
                 *(undefined4 *)(iVar2 + 0x18));
  }
  return param_3;
}

/* FUN_0003dab0 @ 0x3dab0 (82 bytes) */
int FUN_0003dab0(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  if (*param_2 == 0) {
    iVar1 = FUN_0009ffa9(param_1,1);
    *param_2 = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  FUN_0009ffd8(param_1,*param_2);
  uVar2 = FUN_0009fef6(param_1);
  *(undefined4 *)(param_1 + 0x27b8) = uVar2;
  return 1;
}

/* FUN_0003db02 @ 0x3db02 (120 bytes) */
int FUN_0003db02(param_1, param_2, param_3, param_4, param_5, param_6)
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
        uVar2 = (uVar1 & 0xff000) >> 0xc;
        if ((uVar1 & 3) == 0) {
          iVar3 = uVar2 * 0x10 + param_5;
        }
        else {
          iVar3 = uVar2 * 0x10 + param_6;
        }
        FUN_000a0bce(param_1,((uVar1 & 0xff00000) >> 0x14) + 0x8941,iVar3);
      }
      iVar4 = iVar4 + 1;
    } while (param_3 != iVar4);
  }
  return;
}

/* FUN_0003db7a @ 0x3db7a (17 bytes) */
int FUN_0003db7a()
{
  FUN_000a0228();
  return;
}

/* FUN_0003db8b @ 0x3db8b (305 bytes) */
int FUN_0003db8b(param_1, param_2, param_3, param_4)
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
  int local_14;
  
  if (param_3 != 0) {
    local_14 = 0;
    do {
      uVar1 = *param_4;
      param_4 = param_4 + 1;
      iVar2 = ((uVar1 & 0xff000) >> 0xc) + 0x8921;
      uVar4 = uVar1 & 0x300;
      if (uVar4 == 0x100) {
        uVar3 = 0x8977;
LAB_0003dbe2:
        uVar4 = (uVar1 & 0xff00000) >> 0x14;
        if ((uVar1 & 7) != 1) goto LAB_0003dbf7;
LAB_0003dc55:
        iVar5 = uVar4 + 0x8921;
        if ((uVar1 & 0xf0) != 0) goto LAB_0003dc63;
LAB_0003dc0a:
        FUN_000a064f(param_1,iVar2,iVar5,uVar3);
      }
      else {
        if (0x100 < uVar4) {
          if (uVar4 == 0x200) {
            uVar3 = 0x8978;
          }
          else {
            if (uVar4 != 0x300) goto LAB_0003dbe0;
            uVar3 = 0x8979;
          }
          goto LAB_0003dbe2;
        }
        if (uVar4 != 0) {
LAB_0003dbe0:
          uVar3 = 0;
          goto LAB_0003dbe2;
        }
        uVar3 = 0x8976;
        uVar4 = (uVar1 & 0xff00000) >> 0x14;
        if ((uVar1 & 7) == 1) goto LAB_0003dc55;
LAB_0003dbf7:
        if ((uVar1 & 7) == 5) {
          iVar5 = uVar4 + 0x84c0;
        }
        else {
          iVar5 = 0;
        }
        if ((uVar1 & 0xf0) == 0) goto LAB_0003dc0a;
LAB_0003dc63:
        FUN_000a075a(param_1,iVar2,iVar5,uVar3);
      }
      local_14 = local_14 + 1;
    } while (param_3 != local_14);
  }
  return;
}

/* FUN_0003dcbc @ 0x3dcbc (1685 bytes) */
int FUN_0003dcbc(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  uint *param_4;
{
  uint uVar1;
  uint uVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  bool bVar8;
  uint *local_54;
  undefined4 local_50;
  int local_4c;
  int local_48;
  uint local_44;
  int local_40;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (param_3 != 0) {
    local_54 = param_4;
    local_48 = 0;
    local_4c = 0;
    do {
      uVar1 = *local_54;
      local_54 = local_54 + 1;
      uVar4 = uVar1 & 0xf00;
      if (uVar4 == 0x500) {
        local_50 = 0x8967;
LAB_0003dee5:
        local_40 = ((uVar1 & 0xff00000) >> 0x14) + 0x8921;
        sVar3 = (short)(uVar1 & 0xf000);
        if ((uVar1 & 0xf000) != 0) goto LAB_0003dd52;
LAB_0003df07:
        local_44 = 0;
        if (uVar4 != 0) goto LAB_0003dda0;
LAB_0003df16:
        local_48 = 1;
LAB_0003ddb3:
        iVar7 = 0;
        puVar6 = &local_28;
        do {
          uVar4 = *local_54;
          local_54 = local_54 + 1;
          uVar5 = (uVar4 & 0xff00000) >> 0x14;
          uVar2 = uVar4 & 7;
          if (uVar2 == 2) {
            uVar5 = uVar5 + 0x8941;
LAB_0003dded:
            puVar6[-2] = uVar5;
            bVar8 = (uVar4 & 0x7000) == 0x2000;
            if (!bVar8) goto LAB_0003de02;
LAB_0003df85:
            uVar2 = 0x1904;
LAB_0003de15:
            puVar6[-1] = uVar2;
            if ((uVar4 & 0xf00) == 0) goto LAB_0003de21;
LAB_0003df33:
            uVar2 = ~-(uint)((uVar4 & 0x100) == 0) & 4;
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
          else {
            if (2 < uVar2) {
              if (uVar2 != 3) {
                if (uVar2 == 4) {
                  if (uVar5 == 0) {
                    uVar5 = 0x8577;
                  }
                  else {
                    if (uVar5 != 1) goto LAB_0003ddeb;
                    uVar5 = 0x896d;
                  }
                }
                else {
LAB_0003ddeb:
                  uVar5 = 0;
                }
              }
              goto LAB_0003dded;
            }
            if (uVar2 != 1) goto LAB_0003ddeb;
            puVar6[-2] = uVar5 + 0x8921;
            bVar8 = false;
            if ((uVar4 & 0x7000) == 0x2000) goto LAB_0003df85;
LAB_0003de02:
            uVar2 = uVar4 & 0x7000;
            if (0x1fff < uVar2 && !bVar8) {
              if (uVar2 == 0x3000) {
                uVar2 = 0x1905;
              }
              else {
                if (uVar2 != 0x4000) goto LAB_0003de13;
                uVar2 = 0x1906;
              }
              goto LAB_0003de15;
            }
            if (uVar2 != 0x1000) {
LAB_0003de13:
              uVar2 = 0;
              goto LAB_0003de15;
            }
            puVar6[-1] = 0x1903;
            if ((uVar4 & 0xf00) != 0) goto LAB_0003df33;
LAB_0003de21:
            uVar2 = 0;
          }
          *puVar6 = uVar2;
          iVar7 = iVar7 + 1;
          puVar6 = puVar6 + 3;
        } while (local_48 != iVar7);
      }
      else {
        if (0x500 < uVar4) {
          if (uVar4 == 0x800) {
            local_50 = 0x896a;
          }
          else if (uVar4 < 0x801) {
            if (uVar4 == 0x600) {
              local_50 = 0x8968;
            }
            else {
              if (uVar4 != 0x700) goto LAB_0003dede;
              local_50 = 0x8969;
            }
          }
          else if (uVar4 == 0x900) {
            local_50 = 0x896b;
          }
          else {
            if (uVar4 != 0xa00) goto LAB_0003dede;
            local_50 = 0x896c;
          }
          goto LAB_0003dee5;
        }
        if (uVar4 == 0x200) {
          local_50 = 0x8964;
          goto LAB_0003dee5;
        }
        if (0x200 < uVar4) {
          if (uVar4 == 0x300) {
            local_50 = 0x8965;
          }
          else {
            if (uVar4 != 0x400) goto LAB_0003dede;
            local_50 = 0x8966;
          }
          goto LAB_0003dee5;
        }
        if (uVar4 != 0) {
          if (uVar4 == 0x100) {
            local_50 = 0x8963;
          }
          else {
LAB_0003dede:
            local_50 = 0;
          }
          goto LAB_0003dee5;
        }
        local_50 = 0x8961;
        local_40 = ((uVar1 & 0xff00000) >> 0x14) + 0x8921;
        sVar3 = (short)(uVar1 & 0xf000);
        if ((uVar1 & 0xf000) == 0) goto LAB_0003df07;
LAB_0003dd52:
        uVar2 = uVar1 & 0x7000;
        if (uVar2 == 0x3000) {
          local_44 = 4;
        }
        else if (uVar2 < 0x3001) {
          if (uVar2 == 0x1000) {
            local_44 = 1;
          }
          else if (uVar2 == 0x2000) {
            local_44 = 2;
          }
          else {
LAB_0003dd81:
            local_44 = 0;
          }
        }
        else if (uVar2 == 0x5000) {
          local_44 = 0x10;
        }
        else if (uVar2 == 0x6000) {
          local_44 = 0x20;
        }
        else {
          if (uVar2 != 0x4000) goto LAB_0003dd81;
          local_44 = 8;
        }
        uVar2 = local_44 | 0x40;
        if (-1 < sVar3) {
          uVar2 = local_44;
        }
        local_44 = uVar2;
        if (uVar4 == 0) goto LAB_0003df16;
LAB_0003dda0:
        if (uVar4 < 0x501) {
          local_48 = 2;
          goto LAB_0003ddb3;
        }
        if (uVar4 < 0xa01) {
          local_48 = 3;
          goto LAB_0003ddb3;
        }
        if (local_48 != 0) goto LAB_0003ddb3;
      }
      if ((uVar1 & 0x70000) == 0) {
        if ((uVar1 & 0xf0000) == 0) {
          uVar4 = 0;
          if (local_48 == 2) goto LAB_0003e01c;
LAB_0003de60:
          if (local_48 == 3) {
            FUN_000a0992(param_1,local_50,local_40,uVar4,local_44,local_30,local_2c,local_28,
                         local_24,local_20,local_1c,local_18,local_14,local_10);
          }
          else if (local_48 == 1) {
            FUN_000a0865(param_1,local_50,local_40,uVar4,local_44,local_30,local_2c,local_28);
          }
        }
      }
      else {
        uVar4 = (uVar1 & 0x70000) >> 0x10 & 1;
        if ((uVar1 & 0x20000) != 0) {
          uVar4 = uVar4 | 2;
        }
        if ((uVar1 & 0x40000) != 0) {
          uVar4 = uVar4 | 4;
        }
        if (local_48 != 2) goto LAB_0003de60;
LAB_0003e01c:
        FUN_000a08fd(param_1,local_50,local_40,uVar4,local_44,local_30,local_2c,local_28,local_24,
                     local_20,local_1c);
      }
      if (((uVar1 & 0x80000) != 0) || ((uVar1 & 0xf0000) == 0)) {
        if (local_48 == 2) {
          FUN_000a0ab5(param_1,local_50,local_40,local_44,local_30,local_2c,local_28,local_24,
                       local_20,local_1c);
        }
        else if (local_48 == 3) {
          FUN_000a0b43(param_1,local_50,local_40,local_44,local_30,local_2c,local_28,local_24,
                       local_20,local_1c,local_18,local_14,local_10);
        }
        else if (local_48 == 1) {
          FUN_000a0a24(param_1,local_50,local_40,local_44,local_30,local_2c,local_28);
        }
      }
      local_4c = local_4c + 1;
    } while (param_3 != local_4c);
  }
  return;
}

/* FUN_0003e351 @ 0x3e351 (344 bytes) */
int FUN_0003e351(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  *(undefined2 *)(param_1 + 0x2800) = 0;
  FUN_000a0353(param_1);
  uVar2 = param_2[5];
  puVar5 = param_2 + (*param_2 & 0xffff);
  uVar4 = (*param_2 & 0xff0000) >> 0x10;
  if (uVar4 != 0) {
    uVar6 = 0;
    do {
      while( true ) {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        if ((uVar1 & 3) != 1) break;
        FUN_000a0bce(param_1,((uVar1 & 0xff00000) >> 0x14) + 0x8941,
                     (int)param_2 + ((uVar1 & 0xff000) >> 8) + (uint)(ushort)uVar2 * 4);
        uVar6 = uVar6 + 1;
        if (uVar4 == uVar6) goto LAB_0003e3e8;
      }
      uVar6 = uVar6 + 1;
    } while (uVar4 != uVar6);
  }
LAB_0003e3e8:
  ((int (*)())FUN_0003db8b)(param_2 + (param_2[1] & 0xffff));
  ((int (*)())FUN_0003dcbc)(param_2 + (param_2[2] & 0xffff));
  ((int (*)())FUN_0003db8b)(param_2 + (param_2[3] & 0xffff));
  ((int (*)())FUN_0003dcbc)(param_2 + (param_2[4] & 0xffff));
  FUN_000a03be(param_1);
  uVar3 = FUN_0009fef6(param_1);
  *(undefined4 *)(param_1 + 0x27b8) = uVar3;
  return 1;
}

/* FUN_0003e4ac @ 0x3e4ac (101 bytes) */
int FUN_0003e4ac(param_1)
  int *param_1;
{
  undefined4 *puVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(param_1[0xd] + 0x20);
  if ((bVar2 & 0x20) == 0) {
    *(byte *)(param_1[0xd] + 0x20) = bVar2 | 0x20;
    puVar1 = (undefined4 *)(param_1[10] + param_1[6] * 4);
    *puVar1 = 0x1c;
    puVar1[1] = *(ushort *)(*param_1 + 0x28) | 0x10000;
    puVar1[2] = 0x40490fdb;
    puVar1[3] = 0x3fc90fdb;
    puVar1[4] = 0x3c8efa35;
    puVar1[5] = 0x42652ee1;
    param_1[6] = param_1[6] + 6;
  }
  return param_1[9];
}

/* FUN_0003e511 @ 0x3e511 (47 bytes) */
int FUN_0003e511(param_1, param_2)
  int *param_1;
  int param_2;
{
  byte bVar1;
  
  bVar1 = *(byte *)(*param_1 + ((uint)*(ushort *)(param_2 + 6) + *(int *)(*param_1 + 0x14)) * 8) >>
          3 & 7;
  if (bVar1 != 3) {
    return (bVar1 == 4) * '\x02';
  }
  return '\x01';
}

/* FUN_0003e540 @ 0x3e540 (188 bytes) */
int FUN_0003e540(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  uint *param_3;
  uint *param_4;
  int param_5;
{
  byte bVar1;
  short sVar2;
  byte bVar3;
  uint uVar4;
  undefined4 local_10;
  
  uVar4 = 0;
  bVar3 = *(byte *)(param_2 + 1);
  if ((bVar3 & 0x70) == 0x10) {
    sVar2 = *(short *)(param_2 + 6);
  }
  else {
    sVar2 = (short)*(undefined4 *)(*param_1 + 0x10) + *(short *)(param_2 + 6) + 1;
    param_1[4] = param_1[4] | 1 << ((byte)*(short *)(param_2 + 6) & 0x1f);
    bVar3 = *(byte *)(param_2 + 1);
  }
  local_10 = CONCAT22(4,sVar2);
  if (param_5 != 0) {
    uVar4 = 0x100;
  }
  bVar1 = *(byte *)(param_2 + 2);
  *param_3 = local_10 | 0x400000;
  *param_4 = uVar4 | bVar1 >> 2 & 1 | (bVar1 >> 1 & 1) << 2 | (bVar1 & 1) << 4 |
             (uint)(bVar3 >> 7) << 6;
  return 0;
}

/* FUN_0003e5fc @ 0x3e5fc (89 bytes) */
int FUN_0003e5fc(param_1, param_2, param_3)
  uint param_1;
  int param_2;
  uint *param_3;
{
  if (param_2 == 0) {
    *param_3 = *param_3 & 0xfffffff8 | param_1 & 7;
    return;
  }
  if (param_2 != 1) {
    if (param_2 != 2) {
      *param_3 = *param_3 & 0xffff8fff | (param_1 & 7) << 0xc;
      return;
    }
    *param_3 = *param_3 & 0xfffff8ff | (param_1 & 7) << 8;
    return;
  }
  *param_3 = *param_3 & 0xffffff8f | (param_1 & 7) << 4;
  return;
}

/* FUN_0003e655 @ 0x3e655 (198 bytes) */
int FUN_0003e655(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint *param_3;
{
  undefined4 *puVar1;
  
  if ((*(ushort *)(param_1 + 0x14) >> 5 & 0x3f) < 0x20) {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x18) * 4);
    *puVar1 = 0x1c;
    puVar1[1] = *(ushort *)(param_1 + 0x14) >> 5 & 0xffc0003f | 0x20000;
    puVar1[2] = param_2;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 6;
    *param_3 = *(ushort *)(param_1 + 0x14) >> 5 & 0x3f;
    *(ushort *)(param_1 + 0x14) =
         *(ushort *)(param_1 + 0x14) & 0xf81f |
         ((byte)((char)(*(ushort *)(param_1 + 0x14) >> 5) + 1) & 0x3f) << 5;
    return *(undefined4 *)(param_1 + 0x24);
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    return *(undefined4 *)(param_1 + 0x24);
  }
  *(undefined4 *)(param_1 + 0x24) = 4;
  return *(undefined4 *)(param_1 + 0x24);
}

/* FUN_0003e71b @ 0x3e71b (158 bytes) */
int FUN_0003e71b(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  piVar3 = (int *)(param_1 + 0x28);
  uVar4 = *(uint *)(param_1 + 0x30);
  iVar2 = *(int *)(param_1 + 0x2c);
  if (uVar4 < (uint)(param_2 + iVar2)) {
    if (uVar4 == 0) {
      uVar4 = 0x10;
      goto LAB_0003e745;
    }
    do {
      uVar4 = uVar4 * 2;
LAB_0003e745: ;
    } while (uVar4 < (uint)(param_2 + iVar2));
    if ((void *)*piVar3 == (void *)0x0) {
      pvVar1 = _malloc(uVar4 * 4);
    }
    else {
      pvVar1 = _realloc((void *)*piVar3,uVar4 * 4);
    }
    if (pvVar1 == (void *)0x0) {
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      return *(undefined4 *)(param_1 + 0x24);
    }
    *piVar3 = (int)pvVar1;
    *(uint *)(param_1 + 0x30) = uVar4;
    iVar2 = *(int *)(param_1 + 0x2c);
  }
  *(int *)(param_1 + 0x2c) = param_2 + iVar2;
  *param_3 = *piVar3 + iVar2 * 4;
  return 0;
}

/* FUN_0003e7b9 @ 0x3e7b9 (277 bytes) */
int FUN_0003e7b9(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 *param_3;
{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  ushort local_16;
  
  iVar3 = *param_1;
  iVar5 = iVar3 + *(int *)(iVar3 + 0x54) * 8 + param_2 * 8;
  if ((((*(ushort *)(iVar5 + 0x18) & 0x1c0) == 0x80) &&
      (pbVar7 = (byte *)(iVar3 + ((uint)*(ushort *)(iVar5 + 0x1e) + *(int *)(iVar3 + 0x2c)) * 8),
      (pbVar7[1] & 0xf8) == 8)) && ((*pbVar7 & 0x38) == 0x18)) {
    *param_3 = *(undefined4 *)((uint)*(ushort *)(pbVar7 + 2) * 0x10 + param_1[3]);
    pbVar4 = (byte *)param_1[0xd];
    uVar6 = (uint)(pbVar4[0x20] & 0x1f);
    if (uVar6 == 0) {
      if ((pbVar4[0x20] & 0x1f) == 0) {
        uVar6 = 0;
        local_16 = *(ushort *)(pbVar7 + 2);
LAB_0003e850:
        pbVar4[uVar6 * 2] = (byte)local_16;
        *(char *)(param_1[0xd] + 1 + uVar6 * 2) = (char)*param_3;
        bVar2 = *(byte *)(param_1[0xd] + 0x20);
        *(byte *)(param_1[0xd] + 0x20) = bVar2 & 0xe0 | bVar2 + 1 & 0x1f;
        return 0;
      }
    }
    else {
      local_16 = *(ushort *)(pbVar7 + 2);
      if (local_16 != *pbVar4) {
        uVar8 = 0;
        pbVar7 = pbVar4;
        while (uVar8 = uVar8 + 1, uVar6 != uVar8) {
          pbVar1 = pbVar7 + 2;
          pbVar7 = pbVar7 + 2;
          if (*pbVar1 == local_16) {
            return 0;
          }
        }
        if ((int)uVar8 < 0x10) goto LAB_0003e850;
        if (param_1[9] == 0) {
          param_1[9] = 4;
        }
        goto LAB_0003e7e9;
      }
    }
    iVar5 = 0;
  }
  else {
    if (param_1[9] == 0) {
      param_1[9] = 2;
    }
LAB_0003e7e9:
    iVar5 = param_1[9];
  }
  return iVar5;
}

/* FUN_0003e8ce @ 0x3e8ce (811 bytes) */
int FUN_0003e8ce(param_1, param_2, param_3, param_4)
  int *param_1;
  uint *param_2;
  uint *param_3;
  uint *param_4;
{
  int iVar1;
  byte bVar2;
  bool bVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 local_2c;
  
  uVar5 = (ushort)*param_2 & 0x1c0;
  if (uVar5 == 0) {
    iVar1 = *param_1 + ((uint)*(ushort *)((int)param_2 + 6) + *(int *)(*param_1 + 0x24)) * 8;
    switch(*(byte *)(iVar1 + 1) >> 4) {
    default:
LAB_0003e908:
      if (param_1[9] == 0) {
        param_1[9] = 3;
      }
      return param_1[9];
    case 1:
      local_2c = 0x160000;
      bVar3 = false;
      break;
    case 2:
      local_2c = 0x120000;
      bVar3 = false;
      break;
    case 3:
      local_2c = 0x130000;
      bVar3 = false;
      break;
    case 5:
      local_2c = 0x100000;
      bVar3 = true;
      break;
    case 7:
      local_2c = CONCAT22(0x11,(ushort)(*(byte *)(iVar1 + 3) >> 3));
      bVar3 = false;
    }
  }
  else if (uVar5 == 0x80) {
    local_2c = CONCAT22(1,*(ushort *)((int)param_2 + 6));
    bVar3 = false;
  }
  else if (uVar5 == 0x40) {
    local_2c = CONCAT22(4,*(ushort *)((int)param_2 + 6));
    bVar3 = false;
  }
  else {
    if (uVar5 != 0xc0) goto LAB_0003e908;
    local_2c = CONCAT22(4,*(ushort *)((int)param_2 + 6) + (short)*(undefined4 *)(*param_1 + 0x10) +
                          1);
    bVar3 = false;
  }
  if ((*(byte *)(param_1 + 5) & 4) == 0) {
    bVar4 = 4;
  }
  else {
    bVar4 = (*(byte *)((int)param_2 + 2) >> 2 & 3) + 1;
  }
  uVar8 = (byte)((byte)*param_2 >> 4) & 1;
  bVar2 = *(byte *)((int)param_2 + 1);
  uVar10 = 4;
  if (bVar4 != 0) {
    uVar10 = *(uint *)(&DAT_001ed7c0 + (bVar2 >> 1 & 3) * 4) >> 4 & 7;
  }
  uVar9 = uVar8 ^ *(uint *)(&DAT_001ed7c0 + (bVar2 >> 1 & 3) * 4) >> 7 & 1;
  if (bVar4 < 2) {
    uVar10 = uVar10 | uVar9 << 3 | uVar10 << 4 | uVar9 << 7 | uVar10 << 8 | uVar9 << 0xb |
             uVar10 << 0xc | uVar9 << 0xf;
  }
  else {
    uVar6 = 4;
    if (2 < bVar4) {
      uVar6 = *(uint *)(&DAT_001ed7c0 + (bVar2 >> 5 & 3) * 4) >> 4 & 7;
    }
    uVar7 = 4;
    if (3 < bVar4) {
      uVar7 = *(uint *)(&DAT_001ed7c0 + (*param_2 >> 0xf & 3) * 4) >> 4 & 7;
    }
    uVar10 = uVar10 | uVar9 << 3 | *(uint *)(&DAT_001ed7c0 + (bVar2 >> 3 & 3) * 4) & 0x70 |
             ((*(uint *)(&DAT_001ed7c0 + (bVar2 >> 3 & 3) * 4) >> 7 ^ uVar8) & 1) << 7 | uVar6 << 8
             | (uint)(byte)((byte)uVar8 ^
                           (byte)(*(uint *)(&DAT_001ed7c0 + (bVar2 >> 5 & 3) * 4) >> 7) & 1) << 0xb
             | uVar7 << 0xc |
             (uint)(byte)((byte)uVar8 ^
                         (byte)(*(uint *)(&DAT_001ed7c0 + (*param_2 >> 0xf & 3) * 4) >> 7) & 1) <<
             0xf;
  }
  if (bVar3) {
    uVar10 = uVar10 & 0xffff8888 | (byte)(DAT_001ed7a0)[uVar10 & 7] >> 4 & 7 |
             ((byte)(DAT_001ed7a0)[(uVar10 & 0x70) >> 4] >> 4 & 7) << 4 |
             ((byte)(DAT_001ed7a0)[(uVar10 & 0x700) >> 8] >> 4 & 7) << 8 |
             ((byte)(DAT_001ed7a0)[(uVar10 & 0x7000) >> 0xc] >> 4 & 7) << 0xc;
  }
  *param_3 = local_2c | 0x400000;
  *param_4 = uVar10;
  return 0;
}

/* FUN_0003ec89 @ 0x3ec89 (281 bytes) */
int FUN_0003ec89(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  byte *param_2;
  undefined4 *param_3;
  uint *param_4;
  int param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 local_24 [2];
  undefined2 uStack_22;
  undefined4 local_20;
  
  iVar5 = ((int (*)())FUN_0003e8ce)(local_24);
  if (iVar5 != 0) {
    return *(undefined4 *)(param_1 + 0x24);
  }
  uVar1 = *(uint *)(&DAT_001ed7c0 + (*(byte *)(param_5 + 2) & 0xf) * 4);
  uVar6 = *param_2 >> 4 & 1;
  uVar2 = *(uint *)(&DAT_001ed7c0 + (uint)(*(byte *)(param_5 + 2) >> 4) * 4);
  uVar3 = *(uint *)(&DAT_001ed7c0 + (*(byte *)(param_5 + 3) & 0xf) * 4);
  uVar4 = *(uint *)(&DAT_001ed7c0 + (uint)(*(byte *)(param_5 + 3) >> 4) * 4);
  *param_3 = local_20;
  *param_4 = CONCAT22(uStack_22,
                      (ushort)(byte)((byte)(uVar1 >> 4) & 7 |
                                     (byte)(((uVar1 >> 7 ^ uVar6) & 1) << 3) | (byte)uVar2 & 0x70 |
                                    (byte)(((uVar2 >> 7 ^ uVar6) & 1) << 7))) | (uVar3 & 0x70) << 4
             | ((uVar3 >> 7 ^ uVar6) & 1) << 0xb | (uVar4 & 0x70) << 8 |
             ((uVar4 >> 7 ^ uVar6) & 1) << 0xf;
  return 0;
}

/* FUN_0003eda2 @ 0x3eda2 (18 bytes) */
int FUN_0003eda2(param_1)
  void *param_1;
{
  if (param_1 != (void *)0x0) {
    _free(param_1);
    return;
  }
  return;
}

/* FUN_0003edb4 @ 0x3edb4 (63 bytes) */
int FUN_0003edb4(param_1)
  void *param_1;
{
  if (*(int *)((int)param_1 + 0x34) != 0) {
    ((int (*)())FUN_0003eda2)(*(int *)((int)param_1 + 0x34));
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

/* FUN_0003edf3 @ 0x3edf3 (170 bytes) */
int FUN_0003edf3()
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar1 = _malloc(0x38);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2 = puVar1;
  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar1[9] = 0;
  puVar1[10] = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[1] = 0xffffffff;
  puVar1[2] = 0xffffffff;
  puVar2 = _malloc(0x24);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar4 = puVar2;
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
  }
  puVar1[0xd] = puVar2;
  if (puVar1[0xd] == 0) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    _free(puVar1);
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}

/* FUN_0003ee9d @ 0x3ee9d (179 bytes) */
int FUN_0003ee9d(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  uint *param_3;
  undefined4 *param_4;
{
  byte bVar1;
  undefined4 uVar2;
  
  if (((*(byte *)(param_1 + 5) & 4) != 0) &&
     (((((bVar1 = *(byte *)(param_2 + 2), (bVar1 & 4) != 0 && ((bVar1 & 0xc0) != 0)) ||
        (((bVar1 & 2) != 0 && ((*(byte *)(param_2 + 3) & 3) != 1)))) ||
       (((bVar1 & 1) != 0 && ((*(byte *)(param_2 + 3) & 0xc) != 8)))) ||
      ((*(char *)(param_2 + 1) < '\0' && ((*(byte *)(param_2 + 3) & 0x30) != 0x30)))))) {
    uVar2 = *(undefined4 *)(*param_1 + 0x10);
    *param_3 = 0;
    *param_4 = 0;
    *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    *(short *)param_3 = (short)uVar2;
    *(byte *)((int)param_3 + 2) = *(byte *)((int)param_3 + 2) | 0x40;
    *(undefined1 *)param_4 = 0x55;
    return 0;
  }
  uVar2 = ((int (*)())FUN_0003e540)();
  return uVar2;
}

/* FUN_0003ef50 @ 0x3ef50 (283 bytes) */
int FUN_0003ef50(param_1)
  int param_1;
{
  void *pvVar1;
  dword *pdVar2;
  int iVar3;
  dword *pdVar4;
  undefined4 *puVar5;
  int *piVar6;
  dword *pdVar7;
  dword *pdVar8;
  uint uVar9;
  dword *local_14;
  dword *local_10;
  
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  piVar6 = (int *)(param_1 + 0x28);
  uVar9 = *(uint *)(param_1 + 0x30);
  iVar3 = *(int *)(param_1 + 0x2c);
  if (uVar9 < iVar3 + 7U) {
    if (uVar9 == 0) {
      uVar9 = 0x10;
      goto LAB_0003ef87;
    }
    do {
      uVar9 = uVar9 * 2;
LAB_0003ef87: ;
    } while (uVar9 < iVar3 + 7U);
    if ((void *)*piVar6 == (void *)0x0) {
      pvVar1 = _malloc(uVar9 * 4);
    }
    else {
      pvVar1 = _realloc((void *)*piVar6,uVar9 * 4);
    }
    if (pvVar1 == (void *)0x0) {
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        return *(int *)(param_1 + 0x24);
      }
      puVar5 = (undefined4 *)0x0;
      local_14 = &MACH_HEADER.cputype;
      local_10 = &MACH_HEADER.cpusubtype;
      pdVar8 = &MACH_HEADER.filetype;
      pdVar7 = &MACH_HEADER.ncmds;
      pdVar4 = &MACH_HEADER.sizeofcmds;
      pdVar2 = &MACH_HEADER.flags;
      goto LAB_0003efd7;
    }
    *piVar6 = (int)pvVar1;
    *(uint *)(param_1 + 0x30) = uVar9;
    iVar3 = *(int *)(param_1 + 0x2c);
  }
  puVar5 = (undefined4 *)(*piVar6 + iVar3 * 4);
  *(int *)(param_1 + 0x2c) = iVar3 + 7;
  local_14 = puVar5 + 1;
  local_10 = puVar5 + 2;
  pdVar8 = puVar5 + 3;
  pdVar7 = puVar5 + 4;
  pdVar4 = puVar5 + 5;
  pdVar2 = puVar5 + 6;
LAB_0003efd7:
  *puVar5 = 1;
  *local_14 = (dword)((unsigned char *)0x00010200);
  *local_10 = 0x47;
  *pdVar8 = 0x170000;
  *pdVar7 = 0x440000;
  *pdVar4 = 0x4444;
  *pdVar2 = 0x28;
  return 0;
}

/* FUN_0003f06b @ 0x3f06b (515 bytes) */
int FUN_0003f06b(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  undefined4 *puVar8;
  int iVar9;
  dword *pdVar10;
  int *piVar11;
  dword *pdVar12;
  uint local_38;
  dword *local_34;
  dword *local_30;
  dword local_24;
  dword local_20;
  
  local_20 = 0;
  local_24 = 0;
  iVar6 = ((int (*)())FUN_0003e540)(&local_24,param_3);
  if (iVar6 != 0) {
    return param_1[9];
  }
  uVar2 = *(ushort *)(*param_1 + 0x10);
  uVar3 = *(uint *)(&DAT_001ed7c0 + (uint)(*(byte *)(param_2 + 2) >> 6) * 4);
  bVar1 = *(byte *)(param_2 + 3);
  uVar4 = *(uint *)(&DAT_001ed7c0 + (bVar1 & 3) * 4);
  iVar6 = *(int *)(&DAT_001ed7c0 + (bVar1 >> 2 & 3) * 4);
  iVar5 = *(int *)(&DAT_001ed7c0 + (bVar1 >> 4 & 3) * 4);
  piVar11 = param_1 + 10;
  local_38 = param_1[0xc];
  iVar9 = param_1[0xb];
  if (local_38 < iVar9 + 5U) {
    if (local_38 == 0) {
      local_38 = 0x10;
    }
    else {
      local_38 = local_38 * 2;
    }
    for (; local_38 < iVar9 + 5U; local_38 = local_38 * 2) {
    }
    if ((void *)*piVar11 == (void *)0x0) {
      pvVar7 = _malloc(local_38 << 2);
    }
    else {
      pvVar7 = _realloc((void *)*piVar11,local_38 << 2);
    }
    if (pvVar7 == (void *)0x0) {
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) {
        return param_1[9];
      }
      puVar8 = (undefined4 *)0x0;
      local_34 = &MACH_HEADER.cputype;
      local_30 = &MACH_HEADER.cpusubtype;
      pdVar12 = &MACH_HEADER.filetype;
      pdVar10 = &MACH_HEADER.ncmds;
      goto LAB_0003f1b0;
    }
    *piVar11 = (int)pvVar7;
    param_1[0xc] = local_38;
    iVar9 = param_1[0xb];
  }
  puVar8 = (undefined4 *)(*piVar11 + iVar9 * 4);
  param_1[0xb] = iVar9 + 5;
  local_34 = puVar8 + 1;
  local_30 = puVar8 + 2;
  pdVar12 = puVar8 + 3;
  pdVar10 = puVar8 + 4;
LAB_0003f1b0:
  *puVar8 = 0x47;
  *local_34 = local_20;
  *local_30 = local_24;
  *pdVar12 = uVar2 | 0x440000;
  *pdVar10 = uVar3 >> 4 & 0xf | uVar4 & 0x70 | uVar4 & 0x80 | iVar6 << 4 & 0x700U |
             iVar6 << 4 & 0x800U | iVar5 << 8 & 0x7000U | iVar5 << 8 & 0x8000U;
  return 0;
}

/* FUN_0003f26e @ 0x3f26e (292 bytes) */
int FUN_0003f26e(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int *piVar8;
  
  if (*(int *)(param_1 + 0x24) != 0) {
    return *(int *)(param_1 + 0x24);
  }
  piVar8 = (int *)(param_1 + 0x28);
  uVar7 = *(uint *)(param_1 + 0x30);
  iVar1 = (param_3 + param_4) * 2 + 1;
  iVar5 = *(int *)(param_1 + 0x2c);
  uVar3 = iVar1 + iVar5;
  if (uVar7 < uVar3) {
    if (uVar7 == 0) {
      uVar7 = 0x10;
    }
    else {
      uVar7 = uVar7 * 2;
    }
    for (; uVar7 < uVar3; uVar7 = uVar7 * 2) {
    }
    if ((void *)*piVar8 == (void *)0x0) {
      pvVar2 = _malloc(uVar7 * 4);
    }
    else {
      pvVar2 = _realloc((void *)*piVar8,uVar7 * 4);
    }
    if (pvVar2 == (void *)0x0) {
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        return *(int *)(param_1 + 0x24);
      }
      puVar4 = (undefined4 *)0x0;
      goto LAB_0003f2b4;
    }
    *piVar8 = (int)pvVar2;
    *(uint *)(param_1 + 0x30) = uVar7;
    iVar5 = *(int *)(param_1 + 0x2c);
  }
  puVar4 = (undefined4 *)(*piVar8 + iVar5 * 4);
  *(int *)(param_1 + 0x2c) = iVar1 + iVar5;
LAB_0003f2b4:
  *puVar4 = *param_2;
  if (param_3 == 0) {
    iVar1 = 1;
  }
  else {
    puVar4[1] = param_2[1];
    puVar4[2] = param_2[2];
    iVar1 = 3;
  }
  if (0 < param_4) {
    puVar4 = puVar4 + iVar1;
    iVar1 = 0;
    puVar6 = puVar4;
    do {
      *puVar6 = param_2[3];
      puVar4[1] = param_2[6];
      iVar1 = iVar1 + 1;
      param_2 = param_2 + 1;
      puVar6 = puVar6 + 2;
      puVar4 = puVar4 + 2;
    } while (param_4 != iVar1);
  }
  return 0;
}

/* FUN_0003f392 @ 0x3f392 (379 bytes) */
int FUN_0003f392(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 *param_3;
{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  
  puVar1 = (ushort *)(*param_1 + *(int *)(*param_1 + 0x54) * 8 + param_2 * 8);
  uVar11 = (((DAT_001ed80c)[(uint)(byte)(*puVar1 >> 6) * 0x10] & 0xf) >> 1 ^ 1) & 1;
  uVar2 = (uint)((byte)*puVar1 & 7);
  if (param_1[9] != 0) {
    return param_1[9];
  }
  piVar7 = param_1 + 10;
  uVar10 = param_1[0xc];
  iVar3 = (uVar11 + uVar2) * 2 + 1;
  iVar8 = param_1[0xb];
  uVar5 = iVar3 + iVar8;
  if (uVar10 < uVar5) {
    if (uVar10 == 0) {
      uVar10 = 0x10;
    }
    else {
      uVar10 = uVar10 * 2;
    }
    for (; uVar10 < uVar5; uVar10 = uVar10 * 2) {
    }
    if ((void *)*piVar7 == (void *)0x0) {
      pvVar4 = _malloc(uVar10 * 4);
      if (pvVar4 != (void *)0x0) {
        *piVar7 = (int)pvVar4;
        goto LAB_0003f4a4;
      }
    }
    else {
      pvVar4 = _realloc((void *)*piVar7,uVar10 * 4);
      if (pvVar4 != (void *)0x0) {
        *piVar7 = (int)pvVar4;
LAB_0003f4a4:
        param_1[0xc] = uVar10;
        iVar8 = param_1[0xb];
        goto LAB_0003f40a;
      }
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) {
      return param_1[9];
    }
    puVar6 = (undefined4 *)0x0;
  }
  else {
LAB_0003f40a:
    puVar6 = (undefined4 *)(*piVar7 + iVar8 * 4);
    param_1[0xb] = iVar3 + iVar8;
  }
  *puVar6 = *param_3;
  if (uVar11 == 0) {
    iVar3 = 1;
  }
  else {
    puVar6[1] = param_3[1];
    puVar6[2] = param_3[2];
    iVar3 = 3;
  }
  if (uVar2 != 0) {
    puVar6 = puVar6 + iVar3;
    uVar11 = 0;
    puVar9 = puVar6;
    do {
      *puVar9 = param_3[3];
      puVar6[1] = param_3[6];
      uVar11 = uVar11 + 1;
      param_3 = param_3 + 1;
      puVar9 = puVar9 + 2;
      puVar6 = puVar6 + 2;
    } while (uVar2 != uVar11);
  }
  return 0;
}

/* FUN_0003f50d @ 0x3f50d (456 bytes) */
int FUN_0003f50d(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  void *pvVar4;
  undefined4 *puVar5;
  dword *pdVar6;
  dword *pdVar7;
  uint local_34;
  
  if ((*(byte *)((int)param_3 + 0xe) & 0x3f) != 1) {
    if (param_1[9] == 0) {
      param_1[9] = 2;
    }
    return param_1[9];
  }
  pbVar2 = (byte *)(*param_1 + *(int *)(*param_1 + 0x2c) * 8 + (uint)*(ushort *)(param_3 + 3) * 8);
  if ((((pbVar2[1] & 0xf8) == 0x88) && ((*pbVar2 >> 3 & 7) < 2)) &&
     ((*(byte *)(param_3 + 6) & 7) < 4)) {
    iVar3 = param_1[9];
  }
  else {
    if (param_1[9] == 0) {
      param_1[9] = 2;
    }
    iVar3 = param_1[9];
  }
  if (iVar3 != 0) {
    return iVar3;
  }
  ((int (*)())FUN_0003e655)();
  *(byte *)((int)param_3 + 0xe) = *(byte *)((int)param_3 + 0xe) & 0xc0 | 2;
  *(undefined2 *)(param_3 + 3) = 0;
  if (param_1[9] != 0) {
    return param_1[9];
  }
  piVar1 = param_1 + 10;
  local_34 = param_1[0xc];
  iVar3 = param_1[0xb];
  if (local_34 < iVar3 + 3U) {
    if (local_34 == 0) {
      local_34 = 0x10;
    }
    else {
      local_34 = local_34 * 2;
    }
    for (; local_34 < iVar3 + 3U; local_34 = local_34 * 2) {
    }
    if ((void *)*piVar1 == (void *)0x0) {
      pvVar4 = _malloc(local_34 << 2);
      if (pvVar4 != (void *)0x0) {
        *piVar1 = (int)pvVar4;
        goto LAB_0003f616;
      }
    }
    else {
      pvVar4 = _realloc((void *)*piVar1,local_34 << 2);
      if (pvVar4 != (void *)0x0) {
        *piVar1 = (int)pvVar4;
LAB_0003f616:
        param_1[0xc] = local_34;
        iVar3 = param_1[0xb];
        goto LAB_0003f622;
      }
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) {
      return param_1[9];
    }
    puVar5 = (undefined4 *)0x0;
    pdVar7 = &MACH_HEADER.cputype;
    pdVar6 = &MACH_HEADER.cpusubtype;
  }
  else {
LAB_0003f622:
    puVar5 = (undefined4 *)(*piVar1 + iVar3 * 4);
    param_1[0xb] = iVar3 + 3;
    pdVar7 = puVar5 + 1;
    pdVar6 = puVar5 + 2;
  }
  *puVar5 = *param_3;
  *pdVar7 = param_3[3];
  *pdVar6 = param_3[6];
  return 0;
}

/* FUN_0003f6d5 @ 0x3f6d5 (360 bytes) */
int FUN_0003f6d5(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 *puVar6;
  int iVar7;
  dword *pdVar8;
  int *piVar9;
  dword *pdVar10;
  dword *pdVar11;
  uint uVar12;
  dword *local_10;
  
  pbVar1 = (byte *)(*(int *)(param_1 + 0x34) + 0x20);
  *pbVar1 = *pbVar1 | 0x80;
  if ((*(byte *)(*(int *)(param_1 + 0x34) + 0x21) & 1) != 0) {
    uVar2 = ((byte)((*(byte *)(param_3 + 6) ^ 8) >> 3) & 1) << 3;
    uVar12 = param_3[6];
    param_3[6] = uVar12 & 0xfffffff7 | uVar2;
    uVar3 = (uint)((byte)~*(byte *)(param_3 + 6) >> 7) << 7;
    param_3[6] = uVar12 & 0xffffff77 | uVar2 | uVar3;
    uVar4 = ((byte)((*(byte *)((int)param_3 + 0x19) ^ 8) >> 3) & 1) << 0xb;
    param_3[6] = uVar12 & 0xfffff777 | uVar2 | uVar3 | uVar4;
    param_3[6] = uVar12 & 0xffff7777 | uVar2 | uVar3 | uVar4 |
                 (uint)((byte)~*(byte *)((int)param_3 + 0x19) >> 7) << 0xf;
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    return *(int *)(param_1 + 0x24);
  }
  piVar9 = (int *)(param_1 + 0x28);
  uVar12 = *(uint *)(param_1 + 0x30);
  iVar7 = *(int *)(param_1 + 0x2c);
  if (uVar12 < iVar7 + 5U) {
    if (uVar12 == 0) {
      uVar12 = 0x10;
      goto LAB_0003f7c3;
    }
    do {
      uVar12 = uVar12 * 2;
LAB_0003f7c3: ;
    } while (uVar12 < iVar7 + 5U);
    if ((void *)*piVar9 == (void *)0x0) {
      pvVar5 = _malloc(uVar12 * 4);
    }
    else {
      pvVar5 = _realloc((void *)*piVar9,uVar12 * 4);
    }
    if (pvVar5 == (void *)0x0) {
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        return *(int *)(param_1 + 0x24);
      }
      puVar6 = (undefined4 *)0x0;
      local_10 = &MACH_HEADER.cputype;
      pdVar11 = &MACH_HEADER.cpusubtype;
      pdVar10 = &MACH_HEADER.filetype;
      pdVar8 = &MACH_HEADER.ncmds;
      goto LAB_0003f78e;
    }
    *piVar9 = (int)pvVar5;
    *(uint *)(param_1 + 0x30) = uVar12;
    iVar7 = *(int *)(param_1 + 0x2c);
  }
  puVar6 = (undefined4 *)(*piVar9 + iVar7 * 4);
  *(int *)(param_1 + 0x2c) = iVar7 + 5;
  local_10 = puVar6 + 1;
  pdVar11 = puVar6 + 2;
  pdVar10 = puVar6 + 3;
  pdVar8 = puVar6 + 4;
LAB_0003f78e:
  *puVar6 = *param_3;
  *local_10 = param_3[1];
  *pdVar11 = param_3[2];
  *pdVar10 = param_3[3];
  *pdVar8 = param_3[6];
  return 0;
}

/* FUN_0003f83d @ 0x3f83d (1912 bytes) */
int FUN_0003f83d(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 *param_3;
{
  uint *puVar1;
  uint *puVar2;
  byte bVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  dword *pdVar11;
  int *piVar12;
  dword *pdVar13;
  undefined4 local_5c;
  undefined4 local_58;
  uint local_4c;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  dword *local_34;
  dword *local_30;
  dword *local_2c;
  dword *local_28;
  dword *local_24;
  dword *local_20;
  dword *local_1c;
  dword *local_18;
  dword *local_14;
  dword *local_10;
  
  if ((*(byte *)(param_1 + 5) & 4) == 0) {
    bVar3 = 1;
  }
  else {
    bVar3 = (*(byte *)(*param_1 + *(int *)(*param_1 + 0x54) * 8 + 4 + param_2 * 8) >> 4 & 3) + 1;
  }
  uVar7 = param_3[6];
  uVar6 = uVar7;
  if (1 < bVar3) {
    local_58 = param_3[1];
    local_5c = param_3[2];
    iVar10 = param_1[8];
    param_3[2] = 0;
    param_3[1] = 0x40000;
    *(short *)(param_3 + 1) = (short)iVar10;
    *(byte *)((int)param_3 + 6) = *(byte *)((int)param_3 + 6) | 0x40;
    *(undefined1 *)(param_3 + 2) = 0x55;
    uVar6 = param_3[6];
  }
  puVar1 = param_3 + 6;
  uVar9 = uVar7 & 7;
  uVar5 = uVar7 >> 3 & 1;
  param_3[6] = CONCAT22((short)(uVar6 >> 0x10),
                        CONCAT11((byte)uVar9,
                                 (byte)uVar9 | (char)uVar5 * '\b' | (byte)(uVar9 << 4) |
                                 (byte)(uVar5 << 7))) | uVar5 << 0xb | uVar9 << 0xc | uVar5 << 0xf;
  if (param_1[9] == 0) {
    piVar12 = param_1 + 10;
    local_4c = param_1[0xc];
    iVar10 = param_1[0xb];
    if (local_4c < iVar10 + 5U) {
      if (local_4c == 0) {
        local_4c = 0x10;
      }
      else {
        local_4c = local_4c * 2;
      }
      for (; local_4c < iVar10 + 5U; local_4c = local_4c * 2) {
      }
      if ((void *)*piVar12 == (void *)0x0) {
        pvVar4 = _malloc(local_4c << 2);
      }
      else {
        pvVar4 = _realloc((void *)*piVar12,local_4c << 2);
      }
      if (pvVar4 != (void *)0x0) {
        *piVar12 = (int)pvVar4;
        param_1[0xc] = local_4c;
        iVar10 = param_1[0xb];
        goto LAB_0003f91c;
      }
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) goto LAB_0003f957;
      puVar8 = (undefined4 *)0x0;
      local_14 = &MACH_HEADER.cputype;
      local_10 = &MACH_HEADER.cpusubtype;
      pdVar13 = &MACH_HEADER.filetype;
      pdVar11 = &MACH_HEADER.ncmds;
    }
    else {
LAB_0003f91c:
      puVar8 = (undefined4 *)(*piVar12 + iVar10 * 4);
      param_1[0xb] = iVar10 + 5;
      local_14 = puVar8 + 1;
      local_10 = puVar8 + 2;
      pdVar13 = puVar8 + 3;
      pdVar11 = puVar8 + 4;
    }
    *puVar8 = *param_3;
    *local_14 = param_3[1];
    *local_10 = param_3[2];
    *pdVar13 = param_3[3];
    *pdVar11 = param_3[6];
  }
LAB_0003f957:
  if (bVar3 < 2) goto LAB_0003fb29;
  puVar2 = param_3 + 2;
  param_3[2] = param_3[2] & 0xfffffffc;
  uVar5 = uVar7 >> 4 & 7;
  uVar6 = uVar7 >> 7 & 1;
  *puVar1 = CONCAT22((short)(*puVar1 >> 0x10),
                     (ushort)(byte)((byte)uVar5 | (char)uVar6 * '\b' | (byte)(uVar5 << 4) |
                                   (byte)(uVar6 << 7))) | uVar5 << 8 | uVar6 << 0xb | uVar5 << 0xc |
            uVar6 << 0xf;
  if (param_1[9] == 0) {
    piVar12 = param_1 + 10;
    local_44 = param_1[0xc];
    iVar10 = param_1[0xb];
    if (local_44 < iVar10 + 5U) {
      if (local_44 == 0) {
        local_44 = 0x10;
      }
      else {
        local_44 = local_44 * 2;
      }
      for (; local_44 < iVar10 + 5U; local_44 = local_44 * 2) {
      }
      if ((void *)*piVar12 == (void *)0x0) {
        pvVar4 = _malloc(local_44 << 2);
      }
      else {
        pvVar4 = _realloc((void *)*piVar12,local_44 << 2);
      }
      if (pvVar4 != (void *)0x0) {
        *piVar12 = (int)pvVar4;
        param_1[0xc] = local_44;
        iVar10 = param_1[0xb];
        goto LAB_0003fa29;
      }
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) goto LAB_0003fa64;
      puVar8 = (undefined4 *)0x0;
      local_1c = &MACH_HEADER.cputype;
      local_18 = &MACH_HEADER.cpusubtype;
      pdVar13 = &MACH_HEADER.filetype;
      pdVar11 = &MACH_HEADER.ncmds;
    }
    else {
LAB_0003fa29:
      puVar8 = (undefined4 *)(*piVar12 + iVar10 * 4);
      param_1[0xb] = iVar10 + 5;
      local_1c = puVar8 + 1;
      local_18 = puVar8 + 2;
      pdVar13 = puVar8 + 3;
      pdVar11 = puVar8 + 4;
    }
    *puVar8 = *param_3;
    *local_1c = param_3[1];
    *local_18 = param_3[2];
    *pdVar13 = param_3[3];
    *pdVar11 = param_3[6];
  }
LAB_0003fa64:
  if (2 < bVar3) {
    *puVar2 = *puVar2 & 0xfffffff3;
    uVar5 = uVar7 >> 8 & 7;
    uVar6 = uVar7 >> 0xb & 1;
    *puVar1 = CONCAT22((short)(*puVar1 >> 0x10),
                       (ushort)(byte)((byte)uVar5 | (char)uVar6 * '\b' | (byte)(uVar5 << 4) |
                                     (byte)(uVar6 << 7))) | uVar5 << 8 | uVar6 << 0xb | uVar5 << 0xc
              | uVar6 << 0xf;
    if (param_1[9] == 0) {
      piVar12 = param_1 + 10;
      local_40 = param_1[0xc];
      iVar10 = param_1[0xb];
      if (local_40 < iVar10 + 5U) {
        if (local_40 == 0) {
          local_40 = 0x10;
        }
        else {
          local_40 = local_40 * 2;
        }
        for (; local_40 < iVar10 + 5U; local_40 = local_40 * 2) {
        }
        if ((void *)*piVar12 == (void *)0x0) {
          pvVar4 = _malloc(local_40 << 2);
        }
        else {
          pvVar4 = _realloc((void *)*piVar12,local_40 << 2);
        }
        if (pvVar4 != (void *)0x0) {
          *piVar12 = (int)pvVar4;
          param_1[0xc] = local_40;
          iVar10 = param_1[0xb];
          goto LAB_0003fc13;
        }
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        if (param_1[9] != 0) goto LAB_0003fc4e;
        puVar8 = (undefined4 *)0x0;
        local_24 = &MACH_HEADER.cputype;
        local_20 = &MACH_HEADER.cpusubtype;
        pdVar13 = &MACH_HEADER.filetype;
        pdVar11 = &MACH_HEADER.ncmds;
      }
      else {
LAB_0003fc13:
        puVar8 = (undefined4 *)(*piVar12 + iVar10 * 4);
        param_1[0xb] = iVar10 + 5;
        local_24 = puVar8 + 1;
        local_20 = puVar8 + 2;
        pdVar13 = puVar8 + 3;
        pdVar11 = puVar8 + 4;
      }
      *puVar8 = *param_3;
      *local_24 = param_3[1];
      *local_20 = param_3[2];
      *pdVar13 = param_3[3];
      *pdVar11 = param_3[6];
    }
LAB_0003fc4e:
    if (bVar3 == 4) {
      *puVar2 = *puVar2 & 0xffffffcf;
      uVar6 = uVar7 >> 0xc & 7;
      uVar7 = uVar7 >> 0xf & 1;
      *puVar1 = CONCAT22((short)(*puVar1 >> 0x10),
                         (ushort)(byte)((byte)uVar6 | (char)uVar7 * '\b' | (byte)(uVar6 << 4) |
                                       (byte)(uVar7 << 7))) | uVar6 << 8 | uVar7 << 0xb |
                uVar6 << 0xc | uVar7 << 0xf;
      if (param_1[9] == 0) {
        piVar12 = param_1 + 10;
        local_3c = param_1[0xc];
        iVar10 = param_1[0xb];
        if (local_3c < iVar10 + 5U) {
          if (local_3c == 0) {
            local_3c = 0x10;
          }
          else {
            local_3c = local_3c * 2;
          }
          for (; local_3c < iVar10 + 5U; local_3c = local_3c * 2) {
          }
          if ((void *)*piVar12 == (void *)0x0) {
            pvVar4 = _malloc(local_3c << 2);
          }
          else {
            pvVar4 = _realloc((void *)*piVar12,local_3c << 2);
          }
          if (pvVar4 != (void *)0x0) {
            *piVar12 = (int)pvVar4;
            param_1[0xc] = local_3c;
            iVar10 = param_1[0xb];
            goto LAB_0003fd1c;
          }
          if (param_1[9] == 0) {
            param_1[9] = 1;
          }
          if (param_1[9] != 0) goto LAB_0003fa6e;
          puVar8 = (undefined4 *)0x0;
          local_2c = &MACH_HEADER.cputype;
          local_28 = &MACH_HEADER.cpusubtype;
          pdVar13 = &MACH_HEADER.filetype;
          pdVar11 = &MACH_HEADER.ncmds;
        }
        else {
LAB_0003fd1c:
          puVar8 = (undefined4 *)(*piVar12 + iVar10 * 4);
          param_1[0xb] = iVar10 + 5;
          local_2c = puVar8 + 1;
          local_28 = puVar8 + 2;
          pdVar13 = puVar8 + 3;
          pdVar11 = puVar8 + 4;
        }
        *puVar8 = *param_3;
        *local_2c = param_3[1];
        *local_28 = param_3[2];
        *pdVar13 = param_3[3];
        *pdVar11 = param_3[6];
      }
    }
  }
LAB_0003fa6e:
  iVar10 = param_1[8];
  param_3[3] = 0;
  *puVar1 = 0;
  param_3[3] = param_3[3] & 0xffc0ffff | 0x40000;
  *(short *)(param_3 + 3) = (short)iVar10;
  *(byte *)((int)param_3 + 0xe) = *(byte *)((int)param_3 + 0xe) | 0x40;
  *puVar1 = *puVar1 & 0xffff8888 | 0x3210;
  *(byte *)puVar1 = (byte)*puVar1 & 0x77;
  *(byte *)((int)param_3 + 0x19) = *(byte *)((int)param_3 + 0x19) & 0x77;
  param_3[1] = local_58;
  param_3[2] = local_5c;
  *param_3 = 0;
  *(undefined2 *)param_3 = 0x47;
  if (param_1[9] != 0) goto LAB_0003fb29;
  piVar12 = param_1 + 10;
  local_38 = param_1[0xc];
  iVar10 = param_1[0xb];
  if (local_38 < iVar10 + 5U) {
    if (local_38 == 0) {
      local_38 = 0x10;
    }
    else {
      local_38 = local_38 * 2;
    }
    for (; local_38 < iVar10 + 5U; local_38 = local_38 * 2) {
    }
    if ((void *)*piVar12 == (void *)0x0) {
      pvVar4 = _malloc(local_38 << 2);
    }
    else {
      pvVar4 = _realloc((void *)*piVar12,local_38 << 2);
    }
    if (pvVar4 != (void *)0x0) {
      *piVar12 = (int)pvVar4;
      param_1[0xc] = local_38;
      iVar10 = param_1[0xb];
      goto LAB_0003faee;
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) goto LAB_0003fb29;
    puVar8 = (undefined4 *)0x0;
    local_34 = &MACH_HEADER.cputype;
    local_30 = &MACH_HEADER.cpusubtype;
    pdVar13 = &MACH_HEADER.filetype;
    pdVar11 = &MACH_HEADER.ncmds;
  }
  else {
LAB_0003faee:
    puVar8 = (undefined4 *)(*piVar12 + iVar10 * 4);
    param_1[0xb] = iVar10 + 5;
    local_34 = puVar8 + 1;
    local_30 = puVar8 + 2;
    pdVar13 = puVar8 + 3;
    pdVar11 = puVar8 + 4;
  }
  *puVar8 = *param_3;
  *local_34 = param_3[1];
  *local_30 = param_3[2];
  *pdVar13 = param_3[3];
  *pdVar11 = param_3[6];
LAB_0003fb29:
  return param_1[9];
}

/* FUN_0003ffb5 @ 0x3ffb5 (27 bytes) */
int FUN_0003ffb5(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  *(byte *)(param_3 + 0x1a) = *(byte *)(param_3 + 0x1a) | 0x10;
  *(byte *)(param_3 + 0x18) = *(byte *)(param_3 + 0x18) & 0x77;
  *(byte *)(param_3 + 0x19) = *(byte *)(param_3 + 0x19) & 0x77;
  ((int (*)())FUN_0003f83d)();
  return;
}

/* FUN_0003ffd0 @ 0x3ffd0 (2182 bytes) */
int FUN_0003ffd0(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 *param_3;
{
  uint uVar1;
  byte bVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  dword *pdVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  dword *pdVar13;
  dword *pdVar14;
  uint *puVar15;
  int *piVar16;
  int iVar17;
  uint uVar18;
  undefined4 local_28;
  undefined4 local_24;
  dword *local_10;
  
  if ((*(byte *)(param_1 + 5) & 4) == 0) {
    bVar2 = 1;
  }
  else {
    bVar2 = (*(byte *)(*param_1 + *(int *)(*param_1 + 0x54) * 8 + 4 + param_2 * 8) >> 4 & 3) + 1;
  }
  uVar18 = param_3[6];
  uVar1 = param_3[7];
  uVar5 = uVar18;
  uVar12 = uVar1;
  if (1 < bVar2) {
    local_24 = param_3[1];
    local_28 = param_3[2];
    iVar17 = param_1[8];
    param_3[2] = 0;
    param_3[1] = 0x40000;
    *(short *)(param_3 + 1) = (short)iVar17;
    *(byte *)((int)param_3 + 6) = *(byte *)((int)param_3 + 6) | 0x40;
    *(undefined1 *)(param_3 + 2) = 0x55;
    uVar5 = param_3[6];
    uVar12 = param_3[7];
  }
  puVar10 = param_3 + 6;
  uVar11 = uVar18 & 7;
  uVar4 = uVar18 >> 3 & 1;
  param_3[6] = CONCAT22((short)(uVar5 >> 0x10),
                        CONCAT11((byte)uVar11,
                                 (byte)uVar11 | (char)uVar4 * '\b' | (byte)(uVar11 << 4) |
                                 (byte)(uVar4 << 7))) | uVar4 << 0xb | uVar11 << 0xc | uVar4 << 0xf;
  puVar15 = param_3 + 7;
  uVar4 = uVar1 & 7;
  uVar5 = uVar1 >> 3 & 1;
  param_3[7] = CONCAT22((short)(uVar12 >> 0x10),
                        CONCAT11((byte)uVar4,
                                 (byte)uVar4 | (char)uVar5 * '\b' | (byte)(uVar4 << 4) |
                                 (byte)(uVar5 << 7))) | uVar5 << 0xb | uVar4 << 0xc | uVar5 << 0xf;
  if (param_1[9] == 0) {
    piVar16 = param_1 + 10;
    uVar5 = param_1[0xc];
    iVar17 = param_1[0xb];
    if (uVar5 < iVar17 + 7U) {
      if (uVar5 == 0) {
        uVar5 = 0x10;
        goto LAB_00040665;
      }
      do {
        uVar5 = uVar5 * 2;
LAB_00040665: ;
      } while (uVar5 < iVar17 + 7U);
      if ((void *)*piVar16 == (void *)0x0) {
        pvVar3 = _malloc(uVar5 * 4);
      }
      else {
        pvVar3 = _realloc((void *)*piVar16,uVar5 * 4);
      }
      if (pvVar3 != (void *)0x0) {
        *piVar16 = (int)pvVar3;
        param_1[0xc] = uVar5;
        iVar17 = param_1[0xb];
        goto LAB_0004012a;
      }
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) goto LAB_0004016c;
      puVar9 = (undefined4 *)0x0;
      pdVar7 = &MACH_HEADER.cputype;
      pdVar14 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_0004012a:
      puVar9 = (undefined4 *)(*piVar16 + iVar17 * 4);
      param_1[0xb] = iVar17 + 7;
      pdVar7 = puVar9 + 1;
      pdVar14 = puVar9 + 2;
    }
    *puVar9 = *param_3;
    *pdVar7 = param_3[1];
    *pdVar14 = param_3[2];
    iVar17 = 0;
    puVar8 = param_3;
    do {
      puVar9[3] = puVar8[3];
      puVar9[4] = puVar8[6];
      iVar17 = iVar17 + 1;
      puVar9 = puVar9 + 2;
      puVar8 = puVar8 + 1;
    } while (iVar17 != 2);
  }
LAB_0004016c:
  if (bVar2 < 2) goto LAB_00040391;
  puVar6 = param_3 + 2;
  param_3[2] = param_3[2] & 0xfffffffc;
  uVar12 = uVar18 >> 4 & 7;
  uVar5 = uVar18 >> 7 & 1;
  *puVar10 = CONCAT22((short)(*puVar10 >> 0x10),
                      (ushort)(byte)((byte)uVar12 | (char)uVar5 * '\b' | (byte)(uVar12 << 4) |
                                    (byte)(uVar5 << 7))) | uVar12 << 8 | uVar5 << 0xb |
             uVar12 << 0xc | uVar5 << 0xf;
  uVar12 = uVar1 >> 4 & 7;
  uVar5 = uVar1 >> 7 & 1;
  *puVar15 = CONCAT22((short)(*puVar15 >> 0x10),
                      (ushort)(byte)((byte)uVar12 | (char)uVar5 * '\b' | (byte)(uVar12 << 4) |
                                    (byte)(uVar5 << 7))) | uVar12 << 8 | uVar5 << 0xb |
             uVar12 << 0xc | uVar5 << 0xf;
  if (param_1[9] == 0) {
    piVar16 = param_1 + 10;
    uVar5 = param_1[0xc];
    iVar17 = param_1[0xb];
    if (uVar5 < iVar17 + 7U) {
      if (uVar5 == 0) {
        uVar5 = 0x10;
      }
      else {
        uVar5 = uVar5 * 2;
      }
      for (; uVar5 < iVar17 + 7U; uVar5 = uVar5 * 2) {
      }
      if ((void *)*piVar16 == (void *)0x0) {
        pvVar3 = _malloc(uVar5 * 4);
      }
      else {
        pvVar3 = _realloc((void *)*piVar16,uVar5 * 4);
      }
      if (pvVar3 != (void *)0x0) {
        *piVar16 = (int)pvVar3;
        param_1[0xc] = uVar5;
        iVar17 = param_1[0xb];
        goto LAB_0004028b;
      }
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) goto LAB_000402cd;
      puVar9 = (undefined4 *)0x0;
      pdVar7 = &MACH_HEADER.cputype;
      pdVar14 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_0004028b:
      puVar9 = (undefined4 *)(*piVar16 + iVar17 * 4);
      param_1[0xb] = iVar17 + 7;
      pdVar7 = puVar9 + 1;
      pdVar14 = puVar9 + 2;
    }
    *puVar9 = *param_3;
    *pdVar7 = param_3[1];
    *pdVar14 = param_3[2];
    iVar17 = 0;
    puVar8 = param_3;
    do {
      puVar9[3] = puVar8[3];
      puVar9[4] = puVar8[6];
      iVar17 = iVar17 + 1;
      puVar9 = puVar9 + 2;
      puVar8 = puVar8 + 1;
    } while (iVar17 != 2);
  }
LAB_000402cd:
  if (2 < bVar2) {
    *puVar6 = *puVar6 & 0xfffffff3;
    uVar12 = uVar18 >> 8 & 7;
    uVar5 = uVar18 >> 0xb & 1;
    *puVar10 = CONCAT22((short)(*puVar10 >> 0x10),
                        (ushort)(byte)((byte)uVar12 | (char)uVar5 * '\b' | (byte)(uVar12 << 4) |
                                      (byte)(uVar5 << 7))) | uVar12 << 8 | uVar5 << 0xb |
               uVar12 << 0xc | uVar5 << 0xf;
    uVar12 = uVar1 >> 8 & 7;
    uVar5 = uVar1 >> 0xb & 1;
    *puVar15 = CONCAT22((short)(*puVar15 >> 0x10),
                        (ushort)(byte)((byte)uVar12 | (char)uVar5 * '\b' | (byte)(uVar12 << 4) |
                                      (byte)(uVar5 << 7))) | uVar12 << 8 | uVar5 << 0xb |
               uVar12 << 0xc | uVar5 << 0xf;
    if (param_1[9] == 0) {
      piVar16 = param_1 + 10;
      uVar12 = param_1[0xc];
      iVar17 = param_1[0xb];
      uVar5 = iVar17 + 7;
      if (uVar12 < uVar5) {
        if (uVar12 == 0) {
          uVar12 = 0x10;
          uVar4 = 0x10;
          if (0x10 < uVar5) goto LAB_000406c5;
        }
        else {
LAB_000406c5:
          do {
            uVar12 = uVar12 * 2;
            uVar4 = uVar12;
          } while (uVar12 < uVar5);
        }
        if ((void *)*piVar16 == (void *)0x0) {
          pvVar3 = _malloc(uVar4 * 4);
        }
        else {
          pvVar3 = _realloc((void *)*piVar16,uVar4 * 4);
        }
        if (pvVar3 != (void *)0x0) {
          *piVar16 = (int)pvVar3;
          param_1[0xc] = uVar4;
          iVar17 = param_1[0xb];
          goto LAB_0004047d;
        }
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        if (param_1[9] != 0) goto LAB_000404bf;
        puVar9 = (undefined4 *)0x0;
        pdVar7 = &MACH_HEADER.cputype;
        pdVar14 = &MACH_HEADER.cpusubtype;
      }
      else {
LAB_0004047d:
        puVar9 = (undefined4 *)(*piVar16 + iVar17 * 4);
        param_1[0xb] = iVar17 + 7;
        pdVar7 = puVar9 + 1;
        pdVar14 = puVar9 + 2;
      }
      *puVar9 = *param_3;
      *pdVar7 = param_3[1];
      *pdVar14 = param_3[2];
      iVar17 = 0;
      puVar8 = param_3;
      do {
        puVar9[3] = puVar8[3];
        puVar9[4] = puVar8[6];
        iVar17 = iVar17 + 1;
        puVar9 = puVar9 + 2;
        puVar8 = puVar8 + 1;
      } while (iVar17 != 2);
    }
LAB_000404bf:
    if (bVar2 == 4) {
      *puVar6 = *puVar6 & 0xffffffcf;
      uVar5 = uVar18 >> 0xc & 7;
      uVar18 = uVar18 >> 0xf & 1;
      *puVar10 = CONCAT22((short)(*puVar10 >> 0x10),
                          (ushort)(byte)((byte)uVar5 | (char)uVar18 * '\b' | (byte)(uVar5 << 4) |
                                        (byte)(uVar18 << 7))) | uVar5 << 8 | uVar18 << 0xb |
                 uVar5 << 0xc | uVar18 << 0xf;
      uVar5 = uVar1 >> 0xc & 7;
      uVar18 = uVar1 >> 0xf & 1;
      *puVar15 = CONCAT22((short)(*puVar15 >> 0x10),
                          (ushort)(byte)((byte)uVar5 | (char)uVar18 * '\b' | (byte)(uVar5 << 4) |
                                        (byte)(uVar18 << 7))) | uVar5 << 8 | uVar18 << 0xb |
                 uVar5 << 0xc | uVar18 << 0xf;
      if (param_1[9] == 0) {
        piVar16 = param_1 + 10;
        uVar18 = param_1[0xc];
        iVar17 = param_1[0xb];
        if (uVar18 < iVar17 + 7U) {
          if (uVar18 == 0) {
            uVar18 = 0x10;
          }
          else {
            uVar18 = uVar18 * 2;
          }
          for (; uVar18 < iVar17 + 7U; uVar18 = uVar18 * 2) {
          }
          if ((void *)*piVar16 == (void *)0x0) {
            pvVar3 = _malloc(uVar18 * 4);
          }
          else {
            pvVar3 = _realloc((void *)*piVar16,uVar18 * 4);
          }
          if (pvVar3 != (void *)0x0) {
            *piVar16 = (int)pvVar3;
            param_1[0xc] = uVar18;
            iVar17 = param_1[0xb];
            goto LAB_000405d7;
          }
          if (param_1[9] == 0) {
            param_1[9] = 1;
          }
          if (param_1[9] != 0) goto LAB_000402d7;
          puVar9 = (undefined4 *)0x0;
          pdVar7 = &MACH_HEADER.cputype;
          pdVar14 = &MACH_HEADER.cpusubtype;
        }
        else {
LAB_000405d7:
          puVar9 = (undefined4 *)(*piVar16 + iVar17 * 4);
          param_1[0xb] = iVar17 + 7;
          pdVar7 = puVar9 + 1;
          pdVar14 = puVar9 + 2;
        }
        *puVar9 = *param_3;
        *pdVar7 = param_3[1];
        *pdVar14 = param_3[2];
        iVar17 = 0;
        puVar8 = param_3;
        do {
          puVar9[3] = puVar8[3];
          puVar9[4] = puVar8[6];
          iVar17 = iVar17 + 1;
          puVar9 = puVar9 + 2;
          puVar8 = puVar8 + 1;
        } while (iVar17 != 2);
      }
    }
  }
LAB_000402d7:
  iVar17 = param_1[8];
  param_3[3] = 0;
  *puVar10 = 0;
  param_3[3] = param_3[3] & 0xffc0ffff | 0x40000;
  *(short *)(param_3 + 3) = (short)iVar17;
  *(byte *)((int)param_3 + 0xe) = *(byte *)((int)param_3 + 0xe) | 0x40;
  *puVar10 = *puVar10 & 0xffff8888 | 0x3210;
  *(byte *)puVar10 = (byte)*puVar10 & 0x77;
  *(byte *)((int)param_3 + 0x19) = *(byte *)((int)param_3 + 0x19) & 0x77;
  param_3[1] = local_24;
  param_3[2] = local_28;
  *param_3 = 0;
  *(undefined2 *)param_3 = 0x47;
  if (param_1[9] != 0) goto LAB_00040391;
  piVar16 = param_1 + 10;
  uVar18 = param_1[0xc];
  iVar17 = param_1[0xb];
  if (uVar18 < iVar17 + 5U) {
    if (uVar18 == 0) {
      uVar18 = 0x10;
      goto LAB_00040627;
    }
    do {
      uVar18 = uVar18 * 2;
LAB_00040627: ;
    } while (uVar18 < iVar17 + 5U);
    if ((void *)*piVar16 == (void *)0x0) {
      pvVar3 = _malloc(uVar18 * 4);
    }
    else {
      pvVar3 = _realloc((void *)*piVar16,uVar18 * 4);
    }
    if (pvVar3 != (void *)0x0) {
      *piVar16 = (int)pvVar3;
      param_1[0xc] = uVar18;
      iVar17 = param_1[0xb];
      goto LAB_00040353;
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) goto LAB_00040391;
    puVar9 = (undefined4 *)0x0;
    local_10 = &MACH_HEADER.cputype;
    pdVar7 = &MACH_HEADER.cpusubtype;
    pdVar14 = &MACH_HEADER.filetype;
    pdVar13 = &MACH_HEADER.ncmds;
  }
  else {
LAB_00040353:
    puVar9 = (undefined4 *)(*piVar16 + iVar17 * 4);
    param_1[0xb] = iVar17 + 5;
    local_10 = puVar9 + 1;
    pdVar7 = puVar9 + 2;
    pdVar14 = puVar9 + 3;
    pdVar13 = puVar9 + 4;
  }
  *puVar9 = *param_3;
  *local_10 = param_3[1];
  *pdVar7 = param_3[2];
  *pdVar14 = param_3[3];
  *pdVar13 = param_3[6];
LAB_00040391:
  return param_1[9];
}

/* FUN_00040856 @ 0x40856 (425 bytes) */
int FUN_00040856(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  dword dVar1;
  dword dVar2;
  void *pvVar3;
  undefined4 *puVar4;
  undefined2 uVar5;
  int iVar6;
  dword *pdVar7;
  int *piVar8;
  dword *pdVar9;
  uint local_48;
  dword *local_44;
  dword *local_40;
  undefined4 local_2c;
  
  dVar1 = *(dword *)(param_3 + 0xc);
  dVar2 = *(dword *)(param_3 + 0x18);
  uVar5 = (undefined2)*(undefined4 *)(param_1 + 0x20);
  local_2c = (uint)CONCAT12(0x44,uVar5);
  *(undefined4 *)(param_3 + 0xc) = 0x40000;
  *(undefined2 *)(param_3 + 0xc) = uVar5;
  *(byte *)(param_3 + 0xe) = *(byte *)(param_3 + 0xe) | 0x40;
  *(undefined4 *)(param_3 + 0x18) = 0x3210;
  *(byte *)(param_3 + 0x18) = *(byte *)(param_3 + 0x18) & 0x77;
  *(byte *)(param_3 + 0x19) = *(byte *)(param_3 + 0x19) & 0x77;
  if (*(int *)(param_1 + 0x24) != 0) goto LAB_00040937;
  piVar8 = (int *)(param_1 + 0x28);
  local_48 = *(uint *)(param_1 + 0x30);
  iVar6 = *(int *)(param_1 + 0x2c);
  if (local_48 < iVar6 + 5U) {
    if (local_48 == 0) {
      local_48 = 0x10;
    }
    else {
      local_48 = local_48 * 2;
    }
    for (; local_48 < iVar6 + 5U; local_48 = local_48 * 2) {
    }
    if ((void *)*piVar8 == (void *)0x0) {
      pvVar3 = _malloc(local_48 << 2);
    }
    else {
      pvVar3 = _realloc((void *)*piVar8,local_48 << 2);
    }
    if (pvVar3 != (void *)0x0) {
      *piVar8 = (int)pvVar3;
      *(uint *)(param_1 + 0x30) = local_48;
      iVar6 = *(int *)(param_1 + 0x2c);
      goto LAB_000408fb;
    }
    if (*(int *)(param_1 + 0x24) == 0) {
      *(undefined4 *)(param_1 + 0x24) = 1;
    }
    if (*(int *)(param_1 + 0x24) != 0) goto LAB_00040937;
    puVar4 = (undefined4 *)0x0;
    local_44 = &MACH_HEADER.cputype;
    local_40 = &MACH_HEADER.cpusubtype;
    pdVar9 = &MACH_HEADER.filetype;
    pdVar7 = &MACH_HEADER.ncmds;
  }
  else {
LAB_000408fb:
    puVar4 = (undefined4 *)(*piVar8 + iVar6 * 4);
    *(int *)(param_1 + 0x2c) = iVar6 + 5;
    local_44 = puVar4 + 1;
    local_40 = puVar4 + 2;
    pdVar9 = puVar4 + 3;
    pdVar7 = puVar4 + 4;
  }
  *puVar4 = 0x4d;
  *local_44 = local_2c;
  *local_40 = 0x55;
  *pdVar9 = dVar1;
  *pdVar7 = dVar2;
LAB_00040937:
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  ((int (*)())FUN_0003f83d)(param_1,param_2,param_3);
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
  return *(undefined4 *)(param_1 + 0x24);
}

/* FUN_000409ff @ 0x409ff (439 bytes) */
int FUN_000409ff(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 *param_3;
{
  ushort uVar1;
  undefined4 uVar2;
  void *pvVar3;
  dword *pdVar4;
  dword *pdVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  
  uVar1 = *(ushort *)(*param_1 + (*(int *)(*param_1 + 0x54) + param_2) * 8);
  ((int (*)())FUN_0003e4ac)();
  uVar2 = *(undefined4 *)(*param_1 + 0x28);
  param_3[7] = 0;
  param_3[4] = 0x10000;
  *(short *)(param_3 + 4) = (short)uVar2;
  *(byte *)((int)param_3 + 0x12) = *(byte *)((int)param_3 + 0x12) | 0x40;
  param_3[7] = param_3[7] & 0xffff8888 | 0x3210;
  *(byte *)(param_3 + 7) = *(byte *)(param_3 + 7) & 0x77;
  *(byte *)((int)param_3 + 0x1d) = *(byte *)((int)param_3 + 0x1d) & 0x77;
  uVar6 = (uint)((DAT_001c6160)[(((uVar1 & 0x3fc0) != 0x580) + 2) * 4] & 7);
  param_3[7] = param_3[7] & 0xfffffff8 | uVar6;
  *(byte *)(param_3 + 7) = *(byte *)(param_3 + 7) & 0xf7;
  param_3[7] = param_3[7] & 0xffffff8f | uVar6 << 4;
  *(byte *)(param_3 + 7) = *(byte *)(param_3 + 7) & 0x7f;
  param_3[7] = param_3[7] & 0xfffff8ff | uVar6 << 8;
  *(byte *)((int)param_3 + 0x1d) = *(byte *)((int)param_3 + 0x1d) & 0xf7;
  param_3[7] = param_3[7] & 0xffff8fff | uVar6 << 0xc;
  *(byte *)((int)param_3 + 0x1d) = *(byte *)((int)param_3 + 0x1d) & 0x7f;
  if (param_1[9] != 0) {
    return param_1[9];
  }
  piVar8 = param_1 + 10;
  uVar6 = param_1[0xc];
  iVar9 = param_1[0xb];
  if (uVar6 < iVar9 + 7U) {
    if (uVar6 == 0) {
      uVar6 = 0x10;
      goto LAB_00040b48;
    }
    do {
      uVar6 = uVar6 * 2;
LAB_00040b48: ;
    } while (uVar6 < iVar9 + 7U);
    if ((void *)*piVar8 == (void *)0x0) {
      pvVar3 = _malloc(uVar6 * 4);
    }
    else {
      pvVar3 = _realloc((void *)*piVar8,uVar6 * 4);
    }
    if (pvVar3 == (void *)0x0) {
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) {
        return param_1[9];
      }
      puVar7 = (undefined4 *)0x0;
      pdVar4 = &MACH_HEADER.cputype;
      pdVar5 = &MACH_HEADER.cpusubtype;
      goto LAB_00040b05;
    }
    *piVar8 = (int)pvVar3;
    param_1[0xc] = uVar6;
    iVar9 = param_1[0xb];
  }
  puVar7 = (undefined4 *)(*piVar8 + iVar9 * 4);
  param_1[0xb] = iVar9 + 7;
  pdVar4 = puVar7 + 1;
  pdVar5 = puVar7 + 2;
LAB_00040b05:
  *puVar7 = *param_3;
  *pdVar4 = param_3[1];
  *pdVar5 = param_3[2];
  iVar9 = 0;
  do {
    puVar7[3] = param_3[3];
    puVar7[4] = param_3[6];
    iVar9 = iVar9 + 1;
    puVar7 = puVar7 + 2;
    param_3 = param_3 + 1;
  } while (iVar9 != 2);
  return 0;
}

/* FUN_00040bb6 @ 0x40bb6 (983 bytes) */
int FUN_00040bb6(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  void *pvVar6;
  int iVar7;
  dword *pdVar8;
  byte bVar9;
  byte bVar10;
  undefined2 uVar11;
  int iVar12;
  dword *pdVar13;
  dword *pdVar14;
  int *piVar15;
  uint uVar16;
  undefined4 *puVar17;
  dword *local_40;
  undefined4 local_30;
  undefined4 local_2c;
  dword local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  dword local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  puVar17 = &local_30;
  for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar17 = 0;
    puVar17 = puVar17 + 1;
  }
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x20);
  local_24 = *(undefined4 *)(param_3 + 0xc);
  local_18 = *(undefined4 *)(param_3 + 0x18);
  local_20 = *(undefined4 *)(param_3 + 0x10);
  local_14 = *(undefined4 *)(param_3 + 0x1c);
  uVar11 = (undefined2)*(undefined4 *)(param_1 + 0x20);
  local_2c = (dword)CONCAT12(0x44,uVar11);
  local_28 = 0x55;
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar15 = (int *)(param_1 + 0x28);
    uVar16 = *(uint *)(param_1 + 0x30);
    iVar7 = *(int *)(param_1 + 0x2c);
    if (uVar16 < iVar7 + 7U) {
      if (uVar16 == 0) {
        uVar16 = 0x10;
        goto LAB_00040e66;
      }
      do {
        uVar16 = uVar16 * 2;
LAB_00040e66: ;
      } while (uVar16 < iVar7 + 7U);
      if ((void *)*piVar15 == (void *)0x0) {
        pvVar6 = _malloc(uVar16 * 4);
      }
      else {
        pvVar6 = _realloc((void *)*piVar15,uVar16 * 4);
      }
      if (pvVar6 != (void *)0x0) {
        *piVar15 = (int)pvVar6;
        *(uint *)(param_1 + 0x30) = uVar16;
        iVar7 = *(int *)(param_1 + 0x2c);
        goto LAB_00040c36;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        uVar11 = (undefined2)*(undefined4 *)(param_1 + 0x20);
        goto LAB_00040c7e;
      }
      puVar17 = (undefined4 *)0x0;
      pdVar8 = &MACH_HEADER.cputype;
      pdVar14 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00040c36:
      puVar17 = (undefined4 *)(*piVar15 + iVar7 * 4);
      *(int *)(param_1 + 0x2c) = iVar7 + 7;
      pdVar8 = puVar17 + 1;
      pdVar14 = puVar17 + 2;
    }
    *puVar17 = local_30;
    *pdVar8 = local_2c;
    *pdVar14 = local_28;
    iVar7 = 0;
    iVar12 = 0;
    do {
      *(undefined4 *)((int)puVar17 + iVar12 * 2 + 0xc) =
           *(undefined4 *)(iVar12 + 0xc + (int)&local_30);
      *(undefined4 *)((int)puVar17 + iVar12 * 2 + 0x10) =
           *(undefined4 *)(iVar12 + 0x18 + (int)&local_30);
      iVar7 = iVar7 + 1;
      iVar12 = iVar12 + 4;
    } while (iVar7 != 2);
    uVar11 = (undefined2)*(undefined4 *)(param_1 + 0x20);
  }
LAB_00040c7e:
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x30);
  local_24 = (dword)CONCAT12(0x44,uVar11);
  local_18 = 0x3210;
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar15 = (int *)(param_1 + 0x28);
    uVar16 = *(uint *)(param_1 + 0x30);
    iVar7 = *(int *)(param_1 + 0x2c);
    if (uVar16 < iVar7 + 5U) {
      if (uVar16 == 0) {
        uVar16 = 0x10;
        goto LAB_00040e28;
      }
      do {
        uVar16 = uVar16 * 2;
LAB_00040e28: ;
      } while (uVar16 < iVar7 + 5U);
      if ((void *)*piVar15 == (void *)0x0) {
        pvVar6 = _malloc(uVar16 * 4);
      }
      else {
        pvVar6 = _realloc((void *)*piVar15,uVar16 * 4);
      }
      if (pvVar6 != (void *)0x0) {
        *piVar15 = (int)pvVar6;
        *(uint *)(param_1 + 0x30) = uVar16;
        iVar7 = *(int *)(param_1 + 0x2c);
        goto LAB_00040cc9;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) goto LAB_00040cff;
      puVar17 = (undefined4 *)0x0;
      local_40 = &MACH_HEADER.cputype;
      pdVar8 = &MACH_HEADER.cpusubtype;
      pdVar14 = &MACH_HEADER.filetype;
      pdVar13 = &MACH_HEADER.ncmds;
    }
    else {
LAB_00040cc9:
      puVar17 = (undefined4 *)(*piVar15 + iVar7 * 4);
      *(int *)(param_1 + 0x2c) = iVar7 + 5;
      local_40 = puVar17 + 1;
      pdVar8 = puVar17 + 2;
      pdVar14 = puVar17 + 3;
      pdVar13 = puVar17 + 4;
    }
    *puVar17 = local_30;
    *local_40 = local_2c;
    *pdVar8 = local_28;
    *pdVar14 = local_24;
    *pdVar13 = local_18;
  }
LAB_00040cff:
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x40);
  local_20 = *(undefined4 *)(param_3 + 0x10);
  uVar1 = *(undefined4 *)(param_3 + 0x1c);
  (*(unsigned char *)((unsigned char *)&(local_14) + 0)) = (byte)uVar1;
  bVar4 = (byte)local_14 >> 3;
  bVar9 = (byte)local_14 & 0xf7;
  bVar2 = (byte)local_14 & 0x77;
  (*(unsigned char *)((unsigned char *)&(local_14) + 1)) = (byte)((uint)uVar1 >> 8);
  bVar5 = (*(unsigned char *)((unsigned char *)&(local_14) + 1)) >> 3;
  bVar10 = (*(unsigned char *)((unsigned char *)&(local_14) + 1)) & 0xf7;
  bVar3 = (*(unsigned char *)((unsigned char *)&(local_14) + 1)) & 0x77;
  (*(unsigned short *)((unsigned char *)&(local_14) + 2)) = (undefined2)((uint)uVar1 >> 0x10);
  (*(unsigned short *)((unsigned char *)&(local_14) + 0)) =
       CONCAT11(bVar3 | ((bVar5 ^ 1) & 1) << 3 | ~bVar10 & 0x80,
                bVar2 | ((bVar4 ^ 1) & 1) << 3 | ~bVar9 & 0x80);
  local_1c = *(undefined4 *)(param_3 + 0xc);
  local_10 = *(undefined4 *)(param_3 + 0x18);
  local_2c = *(dword *)(param_3 + 4);
  local_28 = *(dword *)(param_3 + 8);
  if (*(int *)(param_1 + 0x24) != 0) {
    return *(int *)(param_1 + 0x24);
  }
  piVar15 = (int *)(param_1 + 0x28);
  uVar16 = *(uint *)(param_1 + 0x30);
  iVar7 = *(int *)(param_1 + 0x2c);
  if (uVar16 < iVar7 + 9U) {
    if (uVar16 == 0) {
      uVar16 = 0x10;
      goto LAB_00040de6;
    }
    do {
      uVar16 = uVar16 * 2;
LAB_00040de6: ;
    } while (uVar16 < iVar7 + 9U);
    if ((void *)*piVar15 == (void *)0x0) {
      pvVar6 = _malloc(uVar16 * 4);
    }
    else {
      pvVar6 = _realloc((void *)*piVar15,uVar16 * 4);
    }
    if (pvVar6 == (void *)0x0) {
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        return *(int *)(param_1 + 0x24);
      }
      puVar17 = (undefined4 *)0x0;
      pdVar8 = &MACH_HEADER.cputype;
      pdVar14 = &MACH_HEADER.cpusubtype;
      goto LAB_00040da0;
    }
    *piVar15 = (int)pvVar6;
    *(uint *)(param_1 + 0x30) = uVar16;
    iVar7 = *(int *)(param_1 + 0x2c);
  }
  puVar17 = (undefined4 *)(*piVar15 + iVar7 * 4);
  *(int *)(param_1 + 0x2c) = iVar7 + 9;
  pdVar8 = puVar17 + 1;
  pdVar14 = puVar17 + 2;
LAB_00040da0:
  *puVar17 = local_30;
  *pdVar8 = local_2c;
  *pdVar14 = local_28;
  iVar7 = 0;
  iVar12 = 0;
  do {
    *(undefined4 *)((int)puVar17 + iVar12 * 2 + 0xc) =
         *(undefined4 *)(iVar12 + 0xc + (int)&local_30);
    *(undefined4 *)((int)puVar17 + iVar12 * 2 + 0x10) =
         *(undefined4 *)(iVar12 + 0x18 + (int)&local_30);
    iVar7 = iVar7 + 1;
    iVar12 = iVar12 + 4;
  } while (iVar7 != 3);
  return 0;
}

/* FUN_00040f8d @ 0x40f8d (3721 bytes) */
int FUN_00040f8d(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  void *pvVar2;
  ushort uVar3;
  int iVar4;
  dword *pdVar5;
  short sVar6;
  int iVar7;
  dword *pdVar8;
  undefined4 *puVar9;
  int *piVar10;
  uint uVar11;
  uint *puVar12;
  undefined4 local_30;
  undefined4 local_2c;
  dword local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18 [3];
  
  if ((*(byte *)(*param_1 + (param_2 + *(int *)(*param_1 + 0x54)) * 8) & 7) == 1) {
    *(undefined4 *)(param_3 + 0x10) = 0x40000;
    *(undefined2 *)(param_3 + 0x10) = 0;
    *(byte *)(param_3 + 0x12) = *(byte *)(param_3 + 0x12) | 0x40;
    *(undefined4 *)(param_3 + 0x1c) = 5;
    *(byte *)(param_3 + 0x1c) = *(byte *)(param_3 + 0x1c) & 0xf7;
    *(uint *)(param_3 + 0x1c) = *(uint *)(param_3 + 0x1c) & 0xffffff8f | 0x50;
    *(byte *)(param_3 + 0x1c) = *(byte *)(param_3 + 0x1c) & 0x7f;
    *(uint *)(param_3 + 0x1c) = *(uint *)(param_3 + 0x1c) & 0xfffff8ff | 0x500;
    *(byte *)(param_3 + 0x1d) = *(byte *)(param_3 + 0x1d) & 0xf7;
    *(uint *)(param_3 + 0x1c) = *(uint *)(param_3 + 0x1c) & 0xffff8fff | 0x5000;
    *(byte *)(param_3 + 0x1d) = *(byte *)(param_3 + 0x1d) & 0x7f;
  }
  puVar9 = &local_30;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x5b);
  iVar4 = param_1[8];
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,(short)iVar4);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  local_24 = *(undefined4 *)(param_3 + 0xc);
  local_18[0] = *(uint *)(param_3 + 0x18) & 0xffff7777 | 0x100000;
  local_20 = *(undefined4 *)(param_3 + 0x10);
  local_18[1] = *(uint *)(param_3 + 0x1c) & 0xffff7777 | 0x100000;
  if (param_1[9] == 0) {
    piVar10 = param_1 + 10;
    uVar11 = param_1[0xc];
    iVar4 = param_1[0xb];
    if (uVar11 < iVar4 + 7U) {
      if (uVar11 == 0) {
        uVar11 = 0x10;
        goto LAB_00041a7b;
      }
      do {
        uVar11 = uVar11 * 2;
LAB_00041a7b: ;
      } while (uVar11 < iVar4 + 7U);
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar11 * 4);
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar11 * 4);
      }
      if (pvVar2 != (void *)0x0) {
        *piVar10 = (int)pvVar2;
        param_1[0xc] = uVar11;
        iVar4 = param_1[0xb];
        goto LAB_00041040;
      }
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) {
        iVar4 = param_1[8];
        goto LAB_00041088;
      }
      puVar9 = (undefined4 *)0x0;
      pdVar5 = &MACH_HEADER.cputype;
      pdVar8 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00041040:
      puVar9 = (undefined4 *)(*piVar10 + iVar4 * 4);
      param_1[0xb] = iVar4 + 7;
      pdVar5 = puVar9 + 1;
      pdVar8 = puVar9 + 2;
    }
    *puVar9 = local_30;
    *pdVar5 = local_2c;
    *pdVar8 = local_28;
    iVar4 = 0;
    iVar7 = 0;
    do {
      *(undefined4 *)((int)puVar9 + iVar7 * 2 + 0xc) = *(undefined4 *)(iVar7 + 0xc + (int)&local_30)
      ;
      *(undefined4 *)((int)puVar9 + iVar7 * 2 + 0x10) =
           *(undefined4 *)(iVar7 + 0x18 + (int)&local_30);
      iVar4 = iVar4 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar4 != 2);
    iVar4 = param_1[8];
  }
LAB_00041088:
  uVar3 = (*(unsigned short *)((unsigned char *)&(local_30) + 2)) & 0xc000;
  local_30 = CONCAT22(uVar3,0xd) | 0x30000;
  local_1c = local_20;
  local_18[2] = local_18[1];
  local_20 = local_24;
  local_18[1] = local_18[0];
  (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(0x44,(short)iVar4);
  local_24 = (uint)(uint3)local_24;
  local_18[0] = 0x3210;
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,(short)iVar4 + 1);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  if (param_1[9] == 0) {
    piVar10 = param_1 + 10;
    uVar11 = param_1[0xc];
    iVar4 = param_1[0xb];
    if (uVar11 < iVar4 + 9U) {
      if (uVar11 == 0) {
        uVar11 = 0x10;
      }
      else {
        uVar11 = uVar11 * 2;
      }
      for (; uVar11 < iVar4 + 9U; uVar11 = uVar11 * 2) {
      }
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar11 * 4);
        uVar1 = local_30;
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar11 * 4);
        uVar1 = local_30;
      }
      local_30 = uVar1;
      if (pvVar2 != (void *)0x0) {
        *piVar10 = (int)pvVar2;
        param_1[0xc] = uVar11;
        iVar4 = param_1[0xb];
        goto LAB_0004111f;
      }
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) {
        iVar4 = param_1[8];
        (*(unsigned short *)((unsigned char *)&(local_30) + 2)) = (ushort)(uVar1 >> 0x10);
        uVar3 = (*(unsigned short *)((unsigned char *)&(local_30) + 2));
        goto LAB_0004116b;
      }
      puVar12 = (uint *)0x0;
      pdVar5 = &MACH_HEADER.cputype;
      pdVar8 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_0004111f:
      puVar12 = (uint *)(*piVar10 + iVar4 * 4);
      param_1[0xb] = iVar4 + 9;
      pdVar5 = puVar12 + 1;
      pdVar8 = puVar12 + 2;
    }
    *puVar12 = local_30;
    *pdVar5 = local_2c;
    *pdVar8 = local_28;
    iVar4 = 0;
    iVar7 = 0;
    do {
      *(undefined4 *)((int)puVar12 + iVar7 * 2 + 0xc) =
           *(undefined4 *)(iVar7 + 0xc + (int)&local_30);
      *(undefined4 *)((int)puVar12 + iVar7 * 2 + 0x10) =
           *(undefined4 *)(iVar7 + 0x18 + (int)&local_30);
      iVar4 = iVar4 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar4 != 3);
    iVar4 = param_1[8];
    uVar3 = (*(unsigned short *)((unsigned char *)&(local_30) + 2));
  }
LAB_0004116b:
  local_30 = CONCAT22(uVar3,(undefined2)local_30) & 0xc000ffff | 0x40000;
  (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(0x44,(short)iVar4);
  local_24 = (uint)(uint3)local_24;
  local_18[0] = 0x3210;
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,(short)iVar4 + 2);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  uVar3 = uVar3 & 0xc000;
  if (param_1[9] == 0) {
    piVar10 = param_1 + 10;
    uVar11 = param_1[0xc];
    iVar4 = param_1[0xb];
    if (uVar11 < iVar4 + 9U) {
      if (uVar11 == 0) {
        uVar11 = 0x10;
        goto LAB_000418e4;
      }
      do {
        uVar11 = uVar11 * 2;
LAB_000418e4: ;
      } while (uVar11 < iVar4 + 9U);
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar11 * 4);
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar11 * 4);
      }
      if (pvVar2 != (void *)0x0) {
        *piVar10 = (int)pvVar2;
        param_1[0xc] = uVar11;
        iVar4 = param_1[0xb];
        goto LAB_000411e0;
      }
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) {
        iVar4 = param_1[8];
        (*(unsigned short *)((unsigned char *)&(local_30) + 2)) = (ushort)(local_30 >> 0x10);
        uVar3 = (*(unsigned short *)((unsigned char *)&(local_30) + 2));
        goto LAB_0004122c;
      }
      puVar12 = (uint *)0x0;
      pdVar5 = &MACH_HEADER.cputype;
      pdVar8 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_000411e0:
      puVar12 = (uint *)(*piVar10 + iVar4 * 4);
      param_1[0xb] = iVar4 + 9;
      pdVar5 = puVar12 + 1;
      pdVar8 = puVar12 + 2;
    }
    *puVar12 = local_30;
    *pdVar5 = local_2c;
    *pdVar8 = local_28;
    iVar4 = 0;
    iVar7 = 0;
    do {
      *(undefined4 *)((int)puVar12 + iVar7 * 2 + 0xc) =
           *(undefined4 *)(iVar7 + 0xc + (int)&local_30);
      *(undefined4 *)((int)puVar12 + iVar7 * 2 + 0x10) =
           *(undefined4 *)(iVar7 + 0x18 + (int)&local_30);
      iVar4 = iVar4 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar4 != 3);
    iVar4 = param_1[8];
    uVar3 = (*(unsigned short *)((unsigned char *)&(local_30) + 2));
  }
LAB_0004122c:
  local_30 = CONCAT22(uVar3,0x20) & 0xc000ffff;
  (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(0x44,(short)iVar4 + 2);
  local_24 = (uint)(uint3)local_24;
  local_18[0] = 0x3210;
  sVar6 = (short)iVar4 + 1;
  (*(unsigned int *)((unsigned char *)&(local_20) + 0)) = CONCAT12(0x44,sVar6);
  local_20 = (uint)(uint3)local_20;
  local_18[1] = 0x3210;
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,sVar6);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  if (param_1[9] == 0) {
    piVar10 = param_1 + 10;
    uVar11 = param_1[0xc];
    iVar4 = param_1[0xb];
    if (uVar11 < iVar4 + 7U) {
      if (uVar11 == 0) {
        uVar11 = 0x10;
        goto LAB_000418a2;
      }
      do {
        uVar11 = uVar11 * 2;
LAB_000418a2: ;
      } while (uVar11 < iVar4 + 7U);
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar11 * 4);
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar11 * 4);
      }
      if (pvVar2 != (void *)0x0) {
        *piVar10 = (int)pvVar2;
        param_1[0xc] = uVar11;
        iVar4 = param_1[0xb];
        goto LAB_000412cc;
      }
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) {
        iVar4 = param_1[8];
        goto LAB_00041314;
      }
      puVar12 = (uint *)0x0;
      pdVar5 = &MACH_HEADER.cputype;
      pdVar8 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_000412cc:
      puVar12 = (uint *)(*piVar10 + iVar4 * 4);
      param_1[0xb] = iVar4 + 7;
      pdVar5 = puVar12 + 1;
      pdVar8 = puVar12 + 2;
    }
    *puVar12 = local_30;
    *pdVar5 = local_2c;
    *pdVar8 = local_28;
    iVar4 = 0;
    iVar7 = 0;
    do {
      *(undefined4 *)((int)puVar12 + iVar7 * 2 + 0xc) =
           *(undefined4 *)(iVar7 + 0xc + (int)&local_30);
      *(undefined4 *)((int)puVar12 + iVar7 * 2 + 0x10) =
           *(undefined4 *)(iVar7 + 0x18 + (int)&local_30);
      iVar4 = iVar4 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar4 != 2);
    iVar4 = param_1[8];
  }
LAB_00041314:
  (*(unsigned short *)((unsigned char *)&(local_30) + 0)) = 5;
  (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(0x44,(short)iVar4 + 1);
  local_24 = (uint)(uint3)local_24;
  local_18[0] = 0x3210;
  param_1[8] = iVar4 + 3;
  ((int (*)())FUN_0003f83d)(param_1,param_2,&local_30);
  param_1[8] = param_1[8] + -3;
  puVar9 = &local_30;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x5b);
  ((int (*)())FUN_0003e4ac)();
  (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(0x41,(short)*(undefined4 *)(*param_1 + 0x28));
  local_24 = (uint)(uint3)local_24;
  local_18[0] = 0x1111;
  sVar6 = (short)param_1[8];
  (*(unsigned int *)((unsigned char *)&(local_20) + 0)) = CONCAT12(0x44,sVar6 + 1);
  local_20 = (uint)(uint3)local_20;
  local_18[1] = 0x3210;
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,sVar6 + 2);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  if (param_1[9] == 0) {
    piVar10 = param_1 + 10;
    uVar11 = param_1[0xc];
    iVar4 = param_1[0xb];
    if (uVar11 < iVar4 + 7U) {
      if (uVar11 == 0) {
        uVar11 = 0x10;
        goto LAB_000419f7;
      }
      do {
        uVar11 = uVar11 * 2;
LAB_000419f7: ;
      } while (uVar11 < iVar4 + 7U);
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar11 * 4);
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar11 * 4);
      }
      if (pvVar2 != (void *)0x0) {
        *piVar10 = (int)pvVar2;
        param_1[0xc] = uVar11;
        iVar4 = param_1[0xb];
        goto LAB_00041418;
      }
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) {
        sVar6 = (short)param_1[8];
        goto LAB_00041460;
      }
      puVar9 = (undefined4 *)0x0;
      pdVar5 = &MACH_HEADER.cputype;
      pdVar8 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00041418:
      puVar9 = (undefined4 *)(*piVar10 + iVar4 * 4);
      param_1[0xb] = iVar4 + 7;
      pdVar5 = puVar9 + 1;
      pdVar8 = puVar9 + 2;
    }
    *puVar9 = local_30;
    *pdVar5 = local_2c;
    *pdVar8 = local_28;
    iVar4 = 0;
    iVar7 = 0;
    do {
      *(undefined4 *)((int)puVar9 + iVar7 * 2 + 0xc) = *(undefined4 *)(iVar7 + 0xc + (int)&local_30)
      ;
      *(undefined4 *)((int)puVar9 + iVar7 * 2 + 0x10) =
           *(undefined4 *)(iVar7 + 0x18 + (int)&local_30);
      iVar4 = iVar4 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar4 != 2);
    sVar6 = (short)param_1[8];
  }
LAB_00041460:
  uVar3 = (*(unsigned short *)((unsigned char *)&(local_30) + 2)) & 0xc000;
  local_30 = CONCAT22(uVar3,0xd) | 0x30000;
  (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(0x44,sVar6);
  local_24 = (uint)(uint3)local_24;
  local_18[0] = 0x3210;
  (*(unsigned int *)((unsigned char *)&(local_20) + 0)) = CONCAT12(0x44,sVar6 + 2);
  local_20 = (uint)(uint3)local_20;
  local_18[1] = 0x3210;
  (*(unsigned int *)((unsigned char *)&(local_1c) + 0)) = CONCAT12(0x44,sVar6 + 1);
  local_1c = (uint)(uint3)local_1c;
  local_18[2] = 0x3210;
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,sVar6 + 1);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  if (param_1[9] == 0) {
    piVar10 = param_1 + 10;
    uVar11 = param_1[0xc];
    iVar4 = param_1[0xb];
    if (uVar11 < iVar4 + 9U) {
      if (uVar11 == 0) {
        uVar11 = 0x10;
        goto LAB_000419b5;
      }
      do {
        uVar11 = uVar11 * 2;
LAB_000419b5: ;
      } while (uVar11 < iVar4 + 9U);
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar11 * 4);
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar11 * 4);
      }
      if (pvVar2 != (void *)0x0) {
        *piVar10 = (int)pvVar2;
        param_1[0xc] = uVar11;
        iVar4 = param_1[0xb];
        goto LAB_0004152c;
      }
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] == 0) {
        puVar12 = (uint *)0x0;
        pdVar5 = &MACH_HEADER.cputype;
        pdVar8 = &MACH_HEADER.cpusubtype;
        goto LAB_0004153d;
      }
    }
    else {
LAB_0004152c:
      puVar12 = (uint *)(*piVar10 + iVar4 * 4);
      param_1[0xb] = iVar4 + 9;
      pdVar5 = puVar12 + 1;
      pdVar8 = puVar12 + 2;
LAB_0004153d:
      *puVar12 = local_30;
      *pdVar5 = local_2c;
      *pdVar8 = local_28;
      iVar4 = 0;
      iVar7 = 0;
      do {
        *(undefined4 *)((int)puVar12 + iVar7 * 2 + 0xc) =
             *(undefined4 *)(iVar7 + 0xc + (int)&local_30);
        *(undefined4 *)((int)puVar12 + iVar7 * 2 + 0x10) =
             *(undefined4 *)(iVar7 + 0x18 + (int)&local_30);
        iVar4 = iVar4 + 1;
        iVar7 = iVar7 + 4;
      } while (iVar4 != 3);
    }
    uVar3 = (*(unsigned short *)((unsigned char *)&(local_30) + 2));
  }
  local_30 = CONCAT22(uVar3,0x5b) & 0xc000ffff;
  ((int (*)())FUN_0003e4ac)();
  (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(0x41,(short)*(undefined4 *)(*param_1 + 0x28));
  local_24 = (uint)(uint3)local_24;
  local_18[0] = 0;
  sVar6 = (short)param_1[8];
  (*(unsigned int *)((unsigned char *)&(local_20) + 0)) = CONCAT12(0x44,sVar6 + 1);
  local_20 = (uint)(uint3)local_20;
  local_18[1] = 0x3210;
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,sVar6 + 2);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  if (param_1[9] == 0) {
    piVar10 = param_1 + 10;
    uVar11 = param_1[0xc];
    iVar4 = param_1[0xb];
    if (uVar11 < iVar4 + 7U) {
      if (uVar11 == 0) {
        uVar11 = 0x10;
        goto LAB_00041a39;
      }
      do {
        uVar11 = uVar11 * 2;
LAB_00041a39: ;
      } while (uVar11 < iVar4 + 7U);
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar11 * 4);
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar11 * 4);
      }
      if (pvVar2 != (void *)0x0) {
        *piVar10 = (int)pvVar2;
        param_1[0xc] = uVar11;
        iVar4 = param_1[0xb];
        goto LAB_00041625;
      }
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) {
        sVar6 = (short)param_1[8];
        goto LAB_0004166d;
      }
      puVar12 = (uint *)0x0;
      pdVar5 = &MACH_HEADER.cputype;
      pdVar8 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00041625:
      puVar12 = (uint *)(*piVar10 + iVar4 * 4);
      param_1[0xb] = iVar4 + 7;
      pdVar5 = puVar12 + 1;
      pdVar8 = puVar12 + 2;
    }
    *puVar12 = local_30;
    *pdVar5 = local_2c;
    *pdVar8 = local_28;
    iVar4 = 0;
    iVar7 = 0;
    do {
      *(undefined4 *)((int)puVar12 + iVar7 * 2 + 0xc) =
           *(undefined4 *)(iVar7 + 0xc + (int)&local_30);
      *(undefined4 *)((int)puVar12 + iVar7 * 2 + 0x10) =
           *(undefined4 *)(iVar7 + 0x18 + (int)&local_30);
      iVar4 = iVar4 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar4 != 2);
    sVar6 = (short)param_1[8];
  }
LAB_0004166d:
  uVar3 = (*(unsigned short *)((unsigned char *)&(local_30) + 2)) & 0xc000;
  local_30 = CONCAT22(uVar3,0xd) | 0x50000;
  local_24 = *(undefined4 *)(param_3 + 0x10);
  local_18[0] = *(undefined4 *)(param_3 + 0x1c);
  (*(unsigned int *)((unsigned char *)&(local_20) + 0)) = CONCAT12(0x44,sVar6 + 2);
  local_20 = (uint)(uint3)local_20;
  local_18[1] = 0x3210;
  (*(unsigned int *)((unsigned char *)&(local_1c) + 0)) = CONCAT12(0x44,sVar6 + 1);
  local_1c = (uint)(uint3)local_1c;
  local_18[2] = 0x3210;
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,sVar6 + 1);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  if (param_1[9] == 0) {
    piVar10 = param_1 + 10;
    uVar11 = param_1[0xc];
    iVar4 = param_1[0xb];
    if (uVar11 < iVar4 + 9U) {
      if (uVar11 == 0) {
        uVar11 = 0x10;
        goto LAB_00041926;
      }
      do {
        uVar11 = uVar11 * 2;
LAB_00041926: ;
      } while (uVar11 < iVar4 + 9U);
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar11 * 4);
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar11 * 4);
      }
      if (pvVar2 != (void *)0x0) {
        *piVar10 = (int)pvVar2;
        param_1[0xc] = uVar11;
        iVar4 = param_1[0xb];
        goto LAB_00041721;
      }
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) {
        sVar6 = (short)param_1[8];
        (*(unsigned short *)((unsigned char *)&(local_30) + 2)) = (ushort)(local_30 >> 0x10);
        uVar3 = (*(unsigned short *)((unsigned char *)&(local_30) + 2));
        goto LAB_0004176d;
      }
      puVar12 = (uint *)0x0;
      pdVar5 = &MACH_HEADER.cputype;
      pdVar8 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00041721:
      puVar12 = (uint *)(*piVar10 + iVar4 * 4);
      param_1[0xb] = iVar4 + 9;
      pdVar5 = puVar12 + 1;
      pdVar8 = puVar12 + 2;
    }
    *puVar12 = local_30;
    *pdVar5 = local_2c;
    *pdVar8 = local_28;
    iVar4 = 0;
    iVar7 = 0;
    do {
      *(undefined4 *)((int)puVar12 + iVar7 * 2 + 0xc) =
           *(undefined4 *)(iVar7 + 0xc + (int)&local_30);
      *(undefined4 *)((int)puVar12 + iVar7 * 2 + 0x10) =
           *(undefined4 *)(iVar7 + 0x18 + (int)&local_30);
      iVar4 = iVar4 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar4 != 3);
    sVar6 = (short)param_1[8];
    uVar3 = (*(unsigned short *)((unsigned char *)&(local_30) + 2));
  }
LAB_0004176d:
  local_30 = CONCAT22(uVar3,0xd) & 0xc000ffff | 0x50000;
  local_24 = *(undefined4 *)(param_3 + 0xc);
  local_18[0] = *(undefined4 *)(param_3 + 0x18);
  (*(unsigned int *)((unsigned char *)&(local_20) + 0)) = CONCAT12(0x44,sVar6 + 1);
  local_20 = (uint)(uint3)local_20;
  local_18[1] = 0xba98;
  (*(unsigned int *)((unsigned char *)&(local_1c) + 0)) = CONCAT12(0x44,sVar6 + 1);
  local_1c = (uint)(uint3)local_1c;
  local_18[2] = 0x3210;
  local_2c = *(dword *)(param_3 + 4);
  local_28 = *(dword *)(param_3 + 8);
  if (param_1[9] != 0) goto LAB_00041847;
  piVar10 = param_1 + 10;
  uVar11 = param_1[0xc];
  iVar4 = param_1[0xb];
  if (uVar11 < iVar4 + 9U) {
    if (uVar11 == 0) {
      uVar11 = 0x10;
      goto LAB_00041860;
    }
    do {
      uVar11 = uVar11 * 2;
LAB_00041860: ;
    } while (uVar11 < iVar4 + 9U);
    if ((void *)*piVar10 == (void *)0x0) {
      pvVar2 = _malloc(uVar11 * 4);
    }
    else {
      pvVar2 = _realloc((void *)*piVar10,uVar11 * 4);
    }
    if (pvVar2 != (void *)0x0) {
      *piVar10 = (int)pvVar2;
      param_1[0xc] = uVar11;
      iVar4 = param_1[0xb];
      goto LAB_00041805;
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) goto LAB_00041847;
    puVar12 = (uint *)0x0;
    pdVar5 = &MACH_HEADER.cputype;
    pdVar8 = &MACH_HEADER.cpusubtype;
  }
  else {
LAB_00041805:
    puVar12 = (uint *)(*piVar10 + iVar4 * 4);
    param_1[0xb] = iVar4 + 9;
    pdVar5 = puVar12 + 1;
    pdVar8 = puVar12 + 2;
  }
  *puVar12 = local_30;
  *pdVar5 = local_2c;
  *pdVar8 = local_28;
  iVar4 = 0;
  iVar7 = 0;
  do {
    *(undefined4 *)((int)puVar12 + iVar7 * 2 + 0xc) = *(undefined4 *)(iVar7 + 0xc + (int)&local_30);
    *(undefined4 *)((int)puVar12 + iVar7 * 2 + 0x10) =
         *(undefined4 *)(iVar7 + 0x18 + (int)&local_30);
    iVar4 = iVar4 + 1;
    iVar7 = iVar7 + 4;
  } while (iVar4 != 3);
LAB_00041847:
  return param_1[9];
}

/* FUN_00041e16 @ 0x41e16 (3386 bytes) */
int FUN_00041e16(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  void *pvVar1;
  int iVar2;
  dword *pdVar3;
  int iVar4;
  dword *pdVar5;
  dword *pdVar6;
  short sVar7;
  undefined4 *puVar8;
  int *piVar9;
  uint uVar10;
  uint *puVar11;
  dword *local_40;
  undefined4 local_30;
  undefined4 local_2c;
  dword local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  dword local_18 [2];
  undefined *local_10;
  
  puVar8 = &local_30;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x23);
  sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,sVar7);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  local_24 = *(undefined4 *)(param_3 + 0xc);
  local_18[0] = *(undefined4 *)(param_3 + 0x18);
  local_20 = *(undefined4 *)(param_3 + 0x10);
  local_18[1] = *(undefined4 *)(param_3 + 0x1c);
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    uVar10 = *(uint *)(param_1 + 0x30);
    iVar2 = *(int *)(param_1 + 0x2c);
    if (uVar10 < iVar2 + 7U) {
      if (uVar10 == 0) {
        uVar10 = 0x10;
        goto LAB_0004262a;
      }
      do {
        uVar10 = uVar10 * 2;
LAB_0004262a: ;
      } while (uVar10 < iVar2 + 7U);
      if ((void *)*piVar9 == (void *)0x0) {
        pvVar1 = _malloc(uVar10 * 4);
      }
      else {
        pvVar1 = _realloc((void *)*piVar9,uVar10 * 4);
      }
      if (pvVar1 != (void *)0x0) {
        *piVar9 = (int)pvVar1;
        *(uint *)(param_1 + 0x30) = uVar10;
        iVar2 = *(int *)(param_1 + 0x2c);
        goto LAB_00041e97;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_00041edf;
      }
      puVar8 = (undefined4 *)0x0;
      pdVar3 = &MACH_HEADER.cputype;
      pdVar6 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00041e97:
      puVar8 = (undefined4 *)(*piVar9 + iVar2 * 4);
      *(int *)(param_1 + 0x2c) = iVar2 + 7;
      pdVar3 = puVar8 + 1;
      pdVar6 = puVar8 + 2;
    }
    *puVar8 = local_30;
    *pdVar3 = local_2c;
    *pdVar6 = local_28;
    iVar2 = 0;
    iVar4 = 0;
    do {
      *(undefined4 *)((int)puVar8 + iVar4 * 2 + 0xc) = *(undefined4 *)(iVar4 + 0xc + (int)&local_30)
      ;
      *(undefined4 *)((int)puVar8 + iVar4 * 2 + 0x10) =
           *(undefined4 *)(iVar4 + 0x18 + (int)&local_30);
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar2 != 2);
    sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
  }
LAB_00041edf:
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x40);
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,sVar7 + 1);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(0x44,sVar7);
  local_24 = (dword)(uint3)local_24;
  local_18[0] = 0x3210;
  (*(unsigned int *)((unsigned char *)&(local_20) + 0)) = CONCAT12(0x44,sVar7);
  local_20 = (uint)(uint3)local_20;
  local_18[1] = 0x3210;
  local_1c = 0x440000;
  local_10 = ((unsigned char *)0x0000dddd);
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    uVar10 = *(uint *)(param_1 + 0x30);
    iVar2 = *(int *)(param_1 + 0x2c);
    if (uVar10 < iVar2 + 9U) {
      if (uVar10 == 0) {
        uVar10 = 0x10;
      }
      else {
        uVar10 = uVar10 * 2;
      }
      for (; uVar10 < iVar2 + 9U; uVar10 = uVar10 * 2) {
      }
      if ((void *)*piVar9 == (void *)0x0) {
        pvVar1 = _malloc(uVar10 * 4);
      }
      else {
        pvVar1 = _realloc((void *)*piVar9,uVar10 * 4);
      }
      if (pvVar1 != (void *)0x0) {
        *piVar9 = (int)pvVar1;
        *(uint *)(param_1 + 0x30) = uVar10;
        iVar2 = *(int *)(param_1 + 0x2c);
        goto LAB_00041f9a;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_00041fe2;
      }
      puVar8 = (undefined4 *)0x0;
      pdVar3 = &MACH_HEADER.cputype;
      pdVar6 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00041f9a:
      puVar8 = (undefined4 *)(*piVar9 + iVar2 * 4);
      *(int *)(param_1 + 0x2c) = iVar2 + 9;
      pdVar3 = puVar8 + 1;
      pdVar6 = puVar8 + 2;
    }
    *puVar8 = local_30;
    *pdVar3 = local_2c;
    *pdVar6 = local_28;
    iVar2 = 0;
    iVar4 = 0;
    do {
      *(undefined4 *)((int)puVar8 + iVar4 * 2 + 0xc) = *(undefined4 *)(iVar4 + 0xc + (int)&local_30)
      ;
      *(undefined4 *)((int)puVar8 + iVar4 * 2 + 0x10) =
           *(undefined4 *)(iVar4 + 0x18 + (int)&local_30);
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar2 != 3);
    sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
  }
LAB_00041fe2:
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x49);
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,sVar7 + 2);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  local_24 = *(undefined4 *)(param_3 + 0x14);
  local_18[0] = *(undefined4 *)(param_3 + 0x20);
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    uVar10 = *(uint *)(param_1 + 0x30);
    iVar2 = *(int *)(param_1 + 0x2c);
    if (uVar10 < iVar2 + 7U) {
      if (uVar10 == 0) {
        uVar10 = 0x10;
      }
      else {
        uVar10 = uVar10 * 2;
      }
      for (; uVar10 < iVar2 + 7U; uVar10 = uVar10 * 2) {
      }
      local_20 = local_24;
      local_18[1] = local_18[0];
      if ((void *)*piVar9 == (void *)0x0) {
        pvVar1 = _malloc(uVar10 * 4);
      }
      else {
        pvVar1 = _realloc((void *)*piVar9,uVar10 * 4);
      }
      if (pvVar1 != (void *)0x0) {
        *piVar9 = (int)pvVar1;
        *(uint *)(param_1 + 0x30) = uVar10;
        iVar2 = *(int *)(param_1 + 0x2c);
        goto LAB_00042041;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_00042089;
      }
      puVar8 = (undefined4 *)0x0;
      pdVar3 = &MACH_HEADER.cputype;
      pdVar6 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00042041:
      puVar8 = (undefined4 *)(*piVar9 + iVar2 * 4);
      *(int *)(param_1 + 0x2c) = iVar2 + 7;
      pdVar3 = puVar8 + 1;
      pdVar6 = puVar8 + 2;
    }
    *puVar8 = local_30;
    *pdVar3 = local_2c;
    *pdVar6 = local_28;
    iVar2 = 0;
    iVar4 = 0;
    do {
      *(undefined4 *)((int)puVar8 + iVar4 * 2 + 0xc) = *(undefined4 *)(iVar4 + 0xc + (int)&local_30)
      ;
      *(undefined4 *)((int)puVar8 + iVar4 * 2 + 0x10) =
           *(undefined4 *)(iVar4 + 0x18 + (int)&local_30);
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar2 != 2);
    sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
  }
LAB_00042089:
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x40);
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,sVar7 + 1);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(0x44,sVar7 + 2);
  local_24 = (dword)(uint3)local_24;
  local_18[0] = 0x3210;
  (*(unsigned int *)((unsigned char *)&(local_20) + 0)) = CONCAT12(0x44,sVar7 + 1);
  local_20 = (uint)(uint3)local_20;
  local_18[1] = 0x3210;
  local_1c = 0x440000;
  local_10 = (undefined *)0x5555;
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    uVar10 = *(uint *)(param_1 + 0x30);
    iVar2 = *(int *)(param_1 + 0x2c);
    if (uVar10 < iVar2 + 9U) {
      if (uVar10 == 0) {
        uVar10 = 0x10;
      }
      else {
        uVar10 = uVar10 * 2;
      }
      for (; uVar10 < iVar2 + 9U; uVar10 = uVar10 * 2) {
      }
      if ((void *)*piVar9 == (void *)0x0) {
        pvVar1 = _malloc(uVar10 * 4);
      }
      else {
        pvVar1 = _realloc((void *)*piVar9,uVar10 * 4);
      }
      if (pvVar1 != (void *)0x0) {
        *piVar9 = (int)pvVar1;
        *(uint *)(param_1 + 0x30) = uVar10;
        iVar2 = *(int *)(param_1 + 0x2c);
        goto LAB_00042147;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_0004218f;
      }
      puVar8 = (undefined4 *)0x0;
      pdVar3 = &MACH_HEADER.cputype;
      pdVar6 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00042147:
      puVar8 = (undefined4 *)(*piVar9 + iVar2 * 4);
      *(int *)(param_1 + 0x2c) = iVar2 + 9;
      pdVar3 = puVar8 + 1;
      pdVar6 = puVar8 + 2;
    }
    *puVar8 = local_30;
    *pdVar3 = local_2c;
    *pdVar6 = local_28;
    iVar2 = 0;
    iVar4 = 0;
    do {
      *(undefined4 *)((int)puVar8 + iVar4 * 2 + 0xc) = *(undefined4 *)(iVar4 + 0xc + (int)&local_30)
      ;
      *(undefined4 *)((int)puVar8 + iVar4 * 2 + 0x10) =
           *(undefined4 *)(iVar4 + 0x18 + (int)&local_30);
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar2 != 3);
    sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
  }
LAB_0004218f:
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x5a);
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,sVar7 + 2);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(0x44,sVar7 + 1);
  local_24 = (dword)(uint3)local_24;
  local_18[0] = 0x3210;
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    uVar10 = *(uint *)(param_1 + 0x30);
    iVar2 = *(int *)(param_1 + 0x2c);
    if (uVar10 < iVar2 + 5U) {
      if (uVar10 == 0) {
        uVar10 = 0x10;
        goto LAB_00042748;
      }
      do {
        uVar10 = uVar10 * 2;
LAB_00042748: ;
      } while (uVar10 < iVar2 + 5U);
      if ((void *)*piVar9 == (void *)0x0) {
        pvVar1 = _malloc(uVar10 * 4);
      }
      else {
        pvVar1 = _realloc((void *)*piVar9,uVar10 * 4);
      }
      if (pvVar1 != (void *)0x0) {
        *piVar9 = (int)pvVar1;
        *(uint *)(param_1 + 0x30) = uVar10;
        iVar2 = *(int *)(param_1 + 0x2c);
        goto LAB_00042201;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_0004223d;
      }
      puVar8 = (undefined4 *)0x0;
      local_40 = &MACH_HEADER.cputype;
      pdVar3 = &MACH_HEADER.cpusubtype;
      pdVar6 = &MACH_HEADER.filetype;
      pdVar5 = &MACH_HEADER.ncmds;
    }
    else {
LAB_00042201:
      puVar8 = (undefined4 *)(*piVar9 + iVar2 * 4);
      *(int *)(param_1 + 0x2c) = iVar2 + 5;
      local_40 = puVar8 + 1;
      pdVar3 = puVar8 + 2;
      pdVar6 = puVar8 + 3;
      pdVar5 = puVar8 + 4;
    }
    *puVar8 = local_30;
    *local_40 = local_2c;
    *pdVar3 = local_28;
    *pdVar6 = local_24;
    *pdVar5 = local_18[0];
    sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
  }
LAB_0004223d:
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x40);
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,sVar7 + 2);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  local_24 = *(undefined4 *)(param_3 + 0x14);
  local_18[0] = *(undefined4 *)(param_3 + 0x20);
  (*(unsigned int *)((unsigned char *)&(local_20) + 0)) = CONCAT12(0x44,sVar7);
  local_20 = (uint)(uint3)local_20;
  local_18[1] = 0x3210;
  (*(unsigned int *)((unsigned char *)&(local_1c) + 0)) = CONCAT12(0x44,sVar7 + 2);
  local_1c = (uint)(uint3)local_1c;
  local_10 = (undefined *)0x3210;
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    uVar10 = *(uint *)(param_1 + 0x30);
    iVar2 = *(int *)(param_1 + 0x2c);
    if (uVar10 < iVar2 + 9U) {
      if (uVar10 == 0) {
        uVar10 = 0x10;
        goto LAB_0004266c;
      }
      do {
        uVar10 = uVar10 * 2;
LAB_0004266c: ;
      } while (uVar10 < iVar2 + 9U);
      if ((void *)*piVar9 == (void *)0x0) {
        pvVar1 = _malloc(uVar10 * 4);
      }
      else {
        pvVar1 = _realloc((void *)*piVar9,uVar10 * 4);
      }
      if (pvVar1 != (void *)0x0) {
        *piVar9 = (int)pvVar1;
        *(uint *)(param_1 + 0x30) = uVar10;
        iVar2 = *(int *)(param_1 + 0x2c);
        goto LAB_0004258f;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_000422ce;
      }
      puVar8 = (undefined4 *)0x0;
      pdVar3 = &MACH_HEADER.cputype;
      pdVar6 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_0004258f:
      puVar8 = (undefined4 *)(*piVar9 + iVar2 * 4);
      *(int *)(param_1 + 0x2c) = iVar2 + 9;
      pdVar3 = puVar8 + 1;
      pdVar6 = puVar8 + 2;
    }
    *puVar8 = local_30;
    *pdVar3 = local_2c;
    *pdVar6 = local_28;
    iVar2 = 0;
    iVar4 = 0;
    do {
      *(undefined4 *)((int)puVar8 + iVar4 * 2 + 0xc) = *(undefined4 *)(iVar4 + 0xc + (int)&local_30)
      ;
      *(undefined4 *)((int)puVar8 + iVar4 * 2 + 0x10) =
           *(undefined4 *)(iVar4 + 0x18 + (int)&local_30);
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar2 != 3);
    sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
  }
LAB_000422ce:
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x49);
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,sVar7 + 2);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(0x44,sVar7 + 2);
  local_24 = (dword)(uint3)local_24;
  local_18[0] = 0x3210;
  local_20 = *(undefined4 *)(param_3 + 0x10);
  local_18[1] = *(undefined4 *)(param_3 + 0x1c);
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    uVar10 = *(uint *)(param_1 + 0x30);
    iVar2 = *(int *)(param_1 + 0x2c);
    if (uVar10 < iVar2 + 7U) {
      if (uVar10 == 0) {
        uVar10 = 0x10;
        goto LAB_00042815;
      }
      do {
        uVar10 = uVar10 * 2;
LAB_00042815: ;
      } while (uVar10 < iVar2 + 7U);
      if ((void *)*piVar9 == (void *)0x0) {
        pvVar1 = _malloc(uVar10 * 4);
      }
      else {
        pvVar1 = _realloc((void *)*piVar9,uVar10 * 4);
      }
      if (pvVar1 != (void *)0x0) {
        *piVar9 = (int)pvVar1;
        *(uint *)(param_1 + 0x30) = uVar10;
        iVar2 = *(int *)(param_1 + 0x2c);
        goto LAB_00042350;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_00042398;
      }
      puVar8 = (undefined4 *)0x0;
      pdVar3 = &MACH_HEADER.cputype;
      pdVar6 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00042350:
      puVar8 = (undefined4 *)(*piVar9 + iVar2 * 4);
      *(int *)(param_1 + 0x2c) = iVar2 + 7;
      pdVar3 = puVar8 + 1;
      pdVar6 = puVar8 + 2;
    }
    *puVar8 = local_30;
    *pdVar3 = local_2c;
    *pdVar6 = local_28;
    iVar2 = 0;
    iVar4 = 0;
    do {
      *(undefined4 *)((int)puVar8 + iVar4 * 2 + 0xc) = *(undefined4 *)(iVar4 + 0xc + (int)&local_30)
      ;
      *(undefined4 *)((int)puVar8 + iVar4 * 2 + 0x10) =
           *(undefined4 *)(iVar4 + 0x18 + (int)&local_30);
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar2 != 2);
    sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
  }
LAB_00042398:
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x40);
  (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = CONCAT12(0x44,sVar7 + 2);
  local_2c = (dword)(uint3)local_2c;
  local_28 = 0x55;
  local_24 = *(undefined4 *)(param_3 + 0x14);
  local_18[0] = *(undefined4 *)(param_3 + 0x20);
  local_20 = *(undefined4 *)(param_3 + 0xc);
  local_18[1] = *(undefined4 *)(param_3 + 0x18);
  (*(unsigned int *)((unsigned char *)&(local_1c) + 0)) = CONCAT12(0x44,sVar7 + 2);
  local_1c = (uint)(uint3)local_1c;
  local_10 = (undefined *)0xba98;
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    uVar10 = *(uint *)(param_1 + 0x30);
    iVar2 = *(int *)(param_1 + 0x2c);
    if (uVar10 < iVar2 + 9U) {
      if (uVar10 == 0) {
        uVar10 = 0x10;
        goto LAB_000427d7;
      }
      do {
        uVar10 = uVar10 * 2;
LAB_000427d7: ;
      } while (uVar10 < iVar2 + 9U);
      if ((void *)*piVar9 == (void *)0x0) {
        pvVar1 = _malloc(uVar10 * 4);
      }
      else {
        pvVar1 = _realloc((void *)*piVar9,uVar10 * 4);
      }
      if (pvVar1 != (void *)0x0) {
        *piVar9 = (int)pvVar1;
        *(uint *)(param_1 + 0x30) = uVar10;
        iVar2 = *(int *)(param_1 + 0x2c);
        goto LAB_00042426;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_0004246e;
      }
      puVar8 = (undefined4 *)0x0;
      pdVar3 = &MACH_HEADER.cputype;
      pdVar6 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00042426:
      puVar8 = (undefined4 *)(*piVar9 + iVar2 * 4);
      *(int *)(param_1 + 0x2c) = iVar2 + 9;
      pdVar3 = puVar8 + 1;
      pdVar6 = puVar8 + 2;
    }
    *puVar8 = local_30;
    *pdVar3 = local_2c;
    *pdVar6 = local_28;
    iVar2 = 0;
    iVar4 = 0;
    do {
      *(undefined4 *)((int)puVar8 + iVar4 * 2 + 0xc) = *(undefined4 *)(iVar4 + 0xc + (int)&local_30)
      ;
      *(undefined4 *)((int)puVar8 + iVar4 * 2 + 0x10) =
           *(undefined4 *)(iVar4 + 0x18 + (int)&local_30);
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar2 != 3);
    sVar7 = (short)*(undefined4 *)(param_1 + 0x20);
  }
LAB_0004246e:
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)) & 0xc000,0xd) | 0x50000;
  local_2c = *(dword *)(param_3 + 4);
  local_28 = *(dword *)(param_3 + 8);
  (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(0x44,sVar7 + 1);
  local_24 = (dword)(uint3)local_24;
  local_18[0] = 0x3210;
  local_20 = 0x440000;
  local_18[1] = 0x4444;
  (*(unsigned int *)((unsigned char *)&(local_1c) + 0)) = CONCAT12(0x44,sVar7 + 2);
  local_1c = (uint)(uint3)local_1c;
  local_10 = (undefined *)0x3210;
  if (*(int *)(param_1 + 0x24) != 0) goto LAB_0004256b;
  piVar9 = (int *)(param_1 + 0x28);
  uVar10 = *(uint *)(param_1 + 0x30);
  iVar2 = *(int *)(param_1 + 0x2c);
  if (uVar10 < iVar2 + 9U) {
    if (uVar10 == 0) {
      uVar10 = 0x10;
      goto LAB_000425e8;
    }
    do {
      uVar10 = uVar10 * 2;
LAB_000425e8: ;
    } while (uVar10 < iVar2 + 9U);
    if ((void *)*piVar9 == (void *)0x0) {
      pvVar1 = _malloc(uVar10 * 4);
    }
    else {
      pvVar1 = _realloc((void *)*piVar9,uVar10 * 4);
    }
    if (pvVar1 != (void *)0x0) {
      *piVar9 = (int)pvVar1;
      *(uint *)(param_1 + 0x30) = uVar10;
      iVar2 = *(int *)(param_1 + 0x2c);
      goto LAB_00042529;
    }
    if (*(int *)(param_1 + 0x24) == 0) {
      *(undefined4 *)(param_1 + 0x24) = 1;
    }
    if (*(int *)(param_1 + 0x24) != 0) goto LAB_0004256b;
    puVar11 = (uint *)0x0;
    pdVar3 = &MACH_HEADER.cputype;
    pdVar6 = &MACH_HEADER.cpusubtype;
  }
  else {
LAB_00042529:
    puVar11 = (uint *)(*piVar9 + iVar2 * 4);
    *(int *)(param_1 + 0x2c) = iVar2 + 9;
    pdVar3 = puVar11 + 1;
    pdVar6 = puVar11 + 2;
  }
  *puVar11 = local_30;
  *pdVar3 = local_2c;
  *pdVar6 = local_28;
  iVar2 = 0;
  iVar4 = 0;
  do {
    *(undefined4 *)((int)puVar11 + iVar4 * 2 + 0xc) = *(undefined4 *)(iVar4 + 0xc + (int)&local_30);
    *(undefined4 *)((int)puVar11 + iVar4 * 2 + 0x10) =
         *(undefined4 *)(iVar4 + 0x18 + (int)&local_30);
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar2 != 3);
LAB_0004256b:
  return *(undefined4 *)(param_1 + 0x24);
}

/* FUN_00042b50 @ 0x42b50 (265 bytes) */
int FUN_00042b50(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  dword *pdVar4;
  dword *pdVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  
  uVar1 = param_3[3];
  uVar2 = param_3[6];
  param_3[3] = param_3[5];
  param_3[6] = param_3[8];
  param_3[5] = uVar1;
  param_3[8] = uVar2;
  if (*(int *)(param_1 + 0x24) != 0) goto LAB_00042bd3;
  piVar6 = (int *)(param_1 + 0x28);
  uVar8 = *(uint *)(param_1 + 0x30);
  iVar7 = *(int *)(param_1 + 0x2c);
  if (uVar8 < iVar7 + 9U) {
    if (uVar8 == 0) {
      uVar8 = 0x10;
      goto LAB_00042be8;
    }
    do {
      uVar8 = uVar8 * 2;
LAB_00042be8: ;
    } while (uVar8 < iVar7 + 9U);
    if ((void *)*piVar6 == (void *)0x0) {
      pvVar3 = _malloc(uVar8 * 4);
      if (pvVar3 == (void *)0x0) goto LAB_00042c2b;
LAB_00042c09:
      *piVar6 = (int)pvVar3;
      *(uint *)(param_1 + 0x30) = uVar8;
      iVar7 = *(int *)(param_1 + 0x2c);
      goto LAB_00042b91;
    }
    pvVar3 = _realloc((void *)*piVar6,uVar8 * 4);
    if (pvVar3 != (void *)0x0) goto LAB_00042c09;
LAB_00042c2b:
    if (*(int *)(param_1 + 0x24) == 0) {
      *(undefined4 *)(param_1 + 0x24) = 1;
    }
    if (*(int *)(param_1 + 0x24) != 0) goto LAB_00042bd3;
    puVar9 = (undefined4 *)0x0;
    pdVar4 = &MACH_HEADER.cputype;
    pdVar5 = &MACH_HEADER.cpusubtype;
  }
  else {
LAB_00042b91:
    puVar9 = (undefined4 *)(*piVar6 + iVar7 * 4);
    *(int *)(param_1 + 0x2c) = iVar7 + 9;
    pdVar4 = puVar9 + 1;
    pdVar5 = puVar9 + 2;
  }
  *puVar9 = *param_3;
  *pdVar4 = param_3[1];
  *pdVar5 = param_3[2];
  iVar7 = 0;
  do {
    puVar9[3] = param_3[3];
    puVar9[4] = param_3[6];
    iVar7 = iVar7 + 1;
    puVar9 = puVar9 + 2;
    param_3 = param_3 + 1;
  } while (iVar7 != 3);
LAB_00042bd3:
  return *(undefined4 *)(param_1 + 0x24);
}

/* FUN_00042c59 @ 0x42c59 (911 bytes) */
int FUN_00042c59(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  uint uVar6;
  dword *pdVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  dword *pdVar10;
  int iVar11;
  int *piVar12;
  uint uVar13;
  int local_24;
  uint local_1c;
  dword *local_14;
  dword *local_10;
  
  if ((*(byte *)(param_1 + 0x14) & 4) == 0) {
    *(undefined2 *)param_3 = 0x24;
    if (*(int *)(param_1 + 0x24) != 0) goto LAB_00042d90;
    piVar12 = (int *)(param_1 + 0x28);
    uVar6 = *(uint *)(param_1 + 0x30);
    iVar11 = *(int *)(param_1 + 0x2c);
    uVar1 = iVar11 + 7;
    if (uVar6 < uVar1) {
      if (uVar6 == 0) {
        uVar6 = 0x10;
        uVar13 = 0x10;
        if (0x10 < uVar1) goto LAB_00042e87;
      }
      else {
LAB_00042e87:
        do {
          uVar6 = uVar6 * 2;
          uVar13 = uVar6;
        } while (uVar6 < uVar1);
      }
      if ((void *)*piVar12 == (void *)0x0) {
        pvVar5 = _malloc(uVar13 * 4);
      }
      else {
        pvVar5 = _realloc((void *)*piVar12,uVar13 * 4);
      }
      if (pvVar5 == (void *)0x0) {
        if (*(int *)(param_1 + 0x24) == 0) {
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        if (*(int *)(param_1 + 0x24) == 0) {
          puVar9 = (undefined4 *)0x0;
          pdVar7 = &MACH_HEADER.cputype;
          pdVar10 = &MACH_HEADER.cpusubtype;
          goto LAB_00042dd7;
        }
        goto LAB_00042d90;
      }
      *piVar12 = (int)pvVar5;
      *(uint *)(param_1 + 0x30) = uVar13;
      iVar11 = *(int *)(param_1 + 0x2c);
    }
    puVar9 = (undefined4 *)(*piVar12 + iVar11 * 4);
    *(int *)(param_1 + 0x2c) = iVar11 + 7;
    pdVar7 = puVar9 + 1;
    pdVar10 = puVar9 + 2;
LAB_00042dd7:
    *puVar9 = *param_3;
    *pdVar7 = param_3[1];
    *pdVar10 = param_3[2];
    iVar11 = 0;
    do {
      puVar9[3] = param_3[3];
      puVar9[4] = param_3[6];
      iVar11 = iVar11 + 1;
      puVar9 = puVar9 + 2;
      param_3 = param_3 + 1;
    } while (iVar11 != 2);
    return *(undefined4 *)(param_1 + 0x24);
  }
  uVar2 = param_3[1];
  uVar3 = param_3[2];
  uVar4 = *(undefined4 *)(param_1 + 0x20);
  param_3[2] = 0;
  param_3[1] = 0x40000;
  *(short *)(param_3 + 1) = (short)uVar4;
  *(byte *)((int)param_3 + 6) = *(byte *)((int)param_3 + 6) | 0x40;
  *(undefined1 *)(param_3 + 2) = 0x55;
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar12 = (int *)(param_1 + 0x28);
    uVar6 = *(uint *)(param_1 + 0x30);
    iVar11 = *(int *)(param_1 + 0x2c);
    uVar1 = iVar11 + 7;
    if (uVar6 < uVar1) {
      if (uVar6 == 0) {
        uVar6 = 0x10;
        uVar13 = 0x10;
        if (0x10 < uVar1) goto LAB_00042ed1;
      }
      else {
LAB_00042ed1:
        do {
          uVar6 = uVar6 * 2;
          uVar13 = uVar6;
        } while (uVar6 < uVar1);
      }
      if ((void *)*piVar12 == (void *)0x0) {
        pvVar5 = _malloc(uVar13 * 4);
      }
      else {
        pvVar5 = _realloc((void *)*piVar12,uVar13 * 4);
      }
      if (pvVar5 != (void *)0x0) {
        *piVar12 = (int)pvVar5;
        *(uint *)(param_1 + 0x30) = uVar13;
        iVar11 = *(int *)(param_1 + 0x2c);
        goto LAB_00042e29;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) goto LAB_00042ca7;
      puVar9 = (undefined4 *)0x0;
      pdVar7 = &MACH_HEADER.cputype;
      pdVar10 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00042e29:
      puVar9 = (undefined4 *)(*piVar12 + iVar11 * 4);
      *(int *)(param_1 + 0x2c) = iVar11 + 7;
      pdVar7 = puVar9 + 1;
      pdVar10 = puVar9 + 2;
    }
    *puVar9 = *param_3;
    *pdVar7 = param_3[1];
    *pdVar10 = param_3[2];
    local_24 = 0;
    puVar8 = param_3;
    do {
      puVar9[3] = puVar8[3];
      puVar9[4] = puVar8[6];
      local_24 = local_24 + 1;
      puVar9 = puVar9 + 2;
      puVar8 = puVar8 + 1;
    } while (local_24 != 2);
  }
LAB_00042ca7:
  *param_3 = 0;
  *(undefined2 *)param_3 = 0x38;
  param_3[1] = uVar2;
  param_3[2] = uVar3;
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  param_3[3] = 0x40000;
  *(short *)(param_3 + 3) = (short)uVar2;
  *(byte *)((int)param_3 + 0xe) = *(byte *)((int)param_3 + 0xe) | 0x40;
  param_3[6] = 0x3210;
  *(byte *)(param_3 + 6) = *(byte *)(param_3 + 6) & 0x77;
  *(byte *)((int)param_3 + 0x19) = *(byte *)((int)param_3 + 0x19) & 0x77;
  if (*(int *)(param_1 + 0x24) != 0) goto LAB_00042d90;
  piVar12 = (int *)(param_1 + 0x28);
  local_1c = *(uint *)(param_1 + 0x30);
  iVar11 = *(int *)(param_1 + 0x2c);
  if (local_1c < iVar11 + 5U) {
    if (local_1c == 0) {
      local_1c = 0x10;
    }
    else {
      local_1c = local_1c * 2;
    }
    for (; local_1c < iVar11 + 5U; local_1c = local_1c * 2) {
    }
    if ((void *)*piVar12 == (void *)0x0) {
      pvVar5 = _malloc(local_1c << 2);
    }
    else {
      pvVar5 = _realloc((void *)*piVar12,local_1c << 2);
    }
    if (pvVar5 != (void *)0x0) {
      *piVar12 = (int)pvVar5;
      *(uint *)(param_1 + 0x30) = local_1c;
      iVar11 = *(int *)(param_1 + 0x2c);
      goto LAB_00042d55;
    }
    if (*(int *)(param_1 + 0x24) == 0) {
      *(undefined4 *)(param_1 + 0x24) = 1;
    }
    if (*(int *)(param_1 + 0x24) != 0) goto LAB_00042d90;
    puVar9 = (undefined4 *)0x0;
    local_14 = &MACH_HEADER.cputype;
    local_10 = &MACH_HEADER.cpusubtype;
    pdVar7 = &MACH_HEADER.filetype;
    pdVar10 = &MACH_HEADER.ncmds;
  }
  else {
LAB_00042d55:
    puVar9 = (undefined4 *)(*piVar12 + iVar11 * 4);
    *(int *)(param_1 + 0x2c) = iVar11 + 5;
    local_14 = puVar9 + 1;
    local_10 = puVar9 + 2;
    pdVar7 = puVar9 + 3;
    pdVar10 = puVar9 + 4;
  }
  *puVar9 = *param_3;
  *local_14 = param_3[1];
  *local_10 = param_3[2];
  *pdVar7 = param_3[3];
  *pdVar10 = param_3[6];
LAB_00042d90:
  return *(undefined4 *)(param_1 + 0x24);
}

/* FUN_00042fe8 @ 0x42fe8 (299 bytes) */
int FUN_00042fe8(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint local_10;
  
  param_3[4] = 0x40000;
  *(undefined2 *)(param_3 + 4) = 0;
  *(byte *)((int)param_3 + 0x12) = *(byte *)((int)param_3 + 0x12) | 0x40;
  param_3[7] = 4;
  *(byte *)(param_3 + 7) = *(byte *)(param_3 + 7) & 0xf7;
  param_3[7] = param_3[7] & 0xffffff8f | 0x40;
  *(byte *)(param_3 + 7) = *(byte *)(param_3 + 7) & 0x7f;
  param_3[7] = param_3[7] & 0xfffff8ff | 0x400;
  *(byte *)((int)param_3 + 0x1d) = *(byte *)((int)param_3 + 0x1d) & 0xf7;
  param_3[7] = param_3[7] & 0xffff8fff | 0x4000;
  *(byte *)((int)param_3 + 0x1d) = *(byte *)((int)param_3 + 0x1d) & 0x7f;
  if (*(int *)(param_1 + 0x24) != 0) {
    return *(int *)(param_1 + 0x24);
  }
  piVar4 = (int *)(param_1 + 0x28);
  local_10 = *(uint *)(param_1 + 0x30);
  iVar3 = *(int *)(param_1 + 0x2c);
  if (local_10 < iVar3 + 5U) {
    if (local_10 == 0) {
      local_10 = 0x10;
    }
    else {
      local_10 = local_10 * 2;
    }
    for (; local_10 < iVar3 + 5U; local_10 = local_10 * 2) {
    }
    if ((void *)*piVar4 == (void *)0x0) {
      pvVar1 = _malloc(local_10 << 2);
    }
    else {
      pvVar1 = _realloc((void *)*piVar4,local_10 << 2);
    }
    if (pvVar1 == (void *)0x0) {
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        return *(int *)(param_1 + 0x24);
      }
      puVar2 = (undefined4 *)0x0;
      goto LAB_0004306d;
    }
    *piVar4 = (int)pvVar1;
    *(uint *)(param_1 + 0x30) = local_10;
    iVar3 = *(int *)(param_1 + 0x2c);
  }
  puVar2 = (undefined4 *)(*piVar4 + iVar3 * 4);
  *(int *)(param_1 + 0x2c) = iVar3 + 5;
LAB_0004306d:
  *puVar2 = *param_3;
  iVar3 = 0;
  do {
    puVar2[1] = param_3[3];
    puVar2[2] = param_3[6];
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 2;
    param_3 = param_3 + 1;
  } while (iVar3 != 2);
  return 0;
}

/* FUN_00043113 @ 0x43113 (1233 bytes) */
int FUN_00043113(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  void *pvVar1;
  int iVar2;
  dword *pdVar3;
  undefined4 *puVar4;
  undefined2 uVar5;
  int iVar6;
  dword *pdVar7;
  int *piVar8;
  uint uVar9;
  undefined4 local_30;
  undefined4 local_2c;
  dword local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_18 [3];
  
  puVar4 = &local_30;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x23);
  uVar5 = (undefined2)*(undefined4 *)(param_1 + 0x20);
  local_2c = (dword)CONCAT12(0x44,uVar5);
  local_28 = 0x55;
  local_24 = *(undefined4 *)(param_3 + 0xc);
  local_18[0] = *(undefined4 *)(param_3 + 0x18);
  local_20 = *(undefined4 *)(param_3 + 0x10);
  local_18[1] = *(undefined4 *)(param_3 + 0x1c);
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar8 = (int *)(param_1 + 0x28);
    uVar9 = *(uint *)(param_1 + 0x30);
    iVar2 = *(int *)(param_1 + 0x2c);
    if (uVar9 < iVar2 + 7U) {
      if (uVar9 == 0) {
        uVar9 = 0x10;
        goto LAB_000433e0;
      }
      do {
        uVar9 = uVar9 * 2;
LAB_000433e0: ;
      } while (uVar9 < iVar2 + 7U);
      if ((void *)*piVar8 == (void *)0x0) {
        pvVar1 = _malloc(uVar9 * 4);
      }
      else {
        pvVar1 = _realloc((void *)*piVar8,uVar9 * 4);
      }
      if (pvVar1 != (void *)0x0) {
        *piVar8 = (int)pvVar1;
        *(uint *)(param_1 + 0x30) = uVar9;
        iVar2 = *(int *)(param_1 + 0x2c);
        goto LAB_00043193;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        uVar5 = (undefined2)*(undefined4 *)(param_1 + 0x20);
        goto LAB_000431db;
      }
      puVar4 = (undefined4 *)0x0;
      pdVar3 = &MACH_HEADER.cputype;
      pdVar7 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00043193:
      puVar4 = (undefined4 *)(*piVar8 + iVar2 * 4);
      *(int *)(param_1 + 0x2c) = iVar2 + 7;
      pdVar3 = puVar4 + 1;
      pdVar7 = puVar4 + 2;
    }
    *puVar4 = local_30;
    *pdVar3 = local_2c;
    *pdVar7 = local_28;
    iVar2 = 0;
    iVar6 = 0;
    do {
      *(undefined4 *)((int)puVar4 + iVar6 * 2 + 0xc) = *(undefined4 *)(iVar6 + 0xc + (int)&local_30)
      ;
      *(undefined4 *)((int)puVar4 + iVar6 * 2 + 0x10) =
           *(undefined4 *)(iVar6 + 0x18 + (int)&local_30);
      iVar2 = iVar2 + 1;
      iVar6 = iVar6 + 4;
    } while (iVar2 != 2);
    uVar5 = (undefined2)*(undefined4 *)(param_1 + 0x20);
  }
LAB_000431db:
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x49);
  local_24 = (uint)CONCAT12(0x44,uVar5);
  local_18[0] = 0x3210;
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar8 = (int *)(param_1 + 0x28);
    uVar9 = *(uint *)(param_1 + 0x30);
    iVar2 = *(int *)(param_1 + 0x2c);
    if (uVar9 < iVar2 + 7U) {
      if (uVar9 == 0) {
        uVar9 = 0x10;
      }
      else {
        uVar9 = uVar9 * 2;
      }
      for (; uVar9 < iVar2 + 7U; uVar9 = uVar9 * 2) {
      }
      if ((void *)*piVar8 == (void *)0x0) {
        pvVar1 = _malloc(uVar9 * 4);
      }
      else {
        pvVar1 = _realloc((void *)*piVar8,uVar9 * 4);
      }
      if (pvVar1 != (void *)0x0) {
        *piVar8 = (int)pvVar1;
        *(uint *)(param_1 + 0x30) = uVar9;
        iVar2 = *(int *)(param_1 + 0x2c);
        goto LAB_00043226;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        uVar5 = (undefined2)*(undefined4 *)(param_1 + 0x20);
        goto LAB_0004326e;
      }
      puVar4 = (undefined4 *)0x0;
      pdVar3 = &MACH_HEADER.cputype;
      pdVar7 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00043226:
      puVar4 = (undefined4 *)(*piVar8 + iVar2 * 4);
      *(int *)(param_1 + 0x2c) = iVar2 + 7;
      pdVar3 = puVar4 + 1;
      pdVar7 = puVar4 + 2;
    }
    *puVar4 = local_30;
    *pdVar3 = local_2c;
    *pdVar7 = local_28;
    iVar2 = 0;
    iVar6 = 0;
    do {
      *(undefined4 *)((int)puVar4 + iVar6 * 2 + 0xc) = *(undefined4 *)(iVar6 + 0xc + (int)&local_30)
      ;
      *(undefined4 *)((int)puVar4 + iVar6 * 2 + 0x10) =
           *(undefined4 *)(iVar6 + 0x18 + (int)&local_30);
      iVar2 = iVar2 + 1;
      iVar6 = iVar6 + 4;
    } while (iVar2 != 2);
    uVar5 = (undefined2)*(undefined4 *)(param_1 + 0x20);
  }
LAB_0004326e:
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),3);
  local_20 = (uint)CONCAT12(0x44,uVar5);
  local_18[1] = 0x3210;
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar8 = (int *)(param_1 + 0x28);
    uVar9 = *(uint *)(param_1 + 0x30);
    iVar2 = *(int *)(param_1 + 0x2c);
    if (uVar9 < iVar2 + 7U) {
      if (uVar9 == 0) {
        uVar9 = 0x10;
      }
      else {
        uVar9 = uVar9 * 2;
      }
      for (; uVar9 < iVar2 + 7U; uVar9 = uVar9 * 2) {
      }
      if ((void *)*piVar8 == (void *)0x0) {
        pvVar1 = _malloc(uVar9 * 4);
      }
      else {
        pvVar1 = _realloc((void *)*piVar8,uVar9 * 4);
      }
      if (pvVar1 != (void *)0x0) {
        *piVar8 = (int)pvVar1;
        *(uint *)(param_1 + 0x30) = uVar9;
        iVar2 = *(int *)(param_1 + 0x2c);
        goto LAB_000432b9;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) goto LAB_000432fb;
      puVar4 = (undefined4 *)0x0;
      pdVar3 = &MACH_HEADER.cputype;
      pdVar7 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_000432b9:
      puVar4 = (undefined4 *)(*piVar8 + iVar2 * 4);
      *(int *)(param_1 + 0x2c) = iVar2 + 7;
      pdVar3 = puVar4 + 1;
      pdVar7 = puVar4 + 2;
    }
    *puVar4 = local_30;
    *pdVar3 = local_2c;
    *pdVar7 = local_28;
    iVar6 = 0;
    iVar2 = 0;
    do {
      *(undefined4 *)((int)puVar4 + iVar2 * 2 + 0xc) = *(undefined4 *)(iVar2 + 0xc + (int)&local_30)
      ;
      *(undefined4 *)((int)puVar4 + iVar2 * 2 + 0x10) =
           *(undefined4 *)(iVar2 + 0x18 + (int)&local_30);
      iVar6 = iVar6 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar6 != 2);
  }
LAB_000432fb:
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x5b);
  local_2c = *(dword *)(param_3 + 4);
  local_28 = *(dword *)(param_3 + 8);
  local_24 = *(undefined4 *)(param_3 + 0xc);
  local_18[0] = *(undefined4 *)(param_3 + 0x18);
  if (*(int *)(param_1 + 0x24) != 0) goto LAB_0004337a;
  piVar8 = (int *)(param_1 + 0x28);
  uVar9 = *(uint *)(param_1 + 0x30);
  iVar2 = *(int *)(param_1 + 0x2c);
  if (uVar9 < iVar2 + 7U) {
    if (uVar9 == 0) {
      uVar9 = 0x10;
    }
    else {
      uVar9 = uVar9 * 2;
    }
    for (; uVar9 < iVar2 + 7U; uVar9 = uVar9 * 2) {
    }
    if ((void *)*piVar8 == (void *)0x0) {
      pvVar1 = _malloc(uVar9 * 4);
    }
    else {
      pvVar1 = _realloc((void *)*piVar8,uVar9 * 4);
    }
    if (pvVar1 != (void *)0x0) {
      *piVar8 = (int)pvVar1;
      *(uint *)(param_1 + 0x30) = uVar9;
      iVar2 = *(int *)(param_1 + 0x2c);
      goto LAB_00043338;
    }
    if (*(int *)(param_1 + 0x24) == 0) {
      *(undefined4 *)(param_1 + 0x24) = 1;
    }
    if (*(int *)(param_1 + 0x24) != 0) goto LAB_0004337a;
    puVar4 = (undefined4 *)0x0;
    pdVar3 = &MACH_HEADER.cputype;
    pdVar7 = &MACH_HEADER.cpusubtype;
  }
  else {
LAB_00043338:
    puVar4 = (undefined4 *)(*piVar8 + iVar2 * 4);
    *(int *)(param_1 + 0x2c) = iVar2 + 7;
    pdVar3 = puVar4 + 1;
    pdVar7 = puVar4 + 2;
  }
  *puVar4 = local_30;
  *pdVar3 = local_2c;
  *pdVar7 = local_28;
  iVar6 = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)((int)puVar4 + iVar2 * 2 + 0xc) = *(undefined4 *)(iVar2 + 0xc + (int)&local_30);
    *(undefined4 *)((int)puVar4 + iVar2 * 2 + 0x10) = *(undefined4 *)(iVar2 + 0x18 + (int)&local_30)
    ;
    iVar6 = iVar6 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar6 != 2);
LAB_0004337a:
  return *(undefined4 *)(param_1 + 0x24);
}

/* FUN_000435e4 @ 0x435e4 (342 bytes) */
int FUN_000435e4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  uint uVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  dword *pdVar5;
  int *piVar6;
  dword *pdVar7;
  uint local_20;
  
  if ((*(byte *)(param_1 + 0x15) & 8) == 0) {
    ((int (*)())FUN_0003e655)();
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffe0fff;
    *(byte *)(param_1 + 0x15) = *(byte *)(param_1 + 0x15) | 8;
  }
  uVar1 = *(uint *)(param_1 + 0x14);
  param_3[3] = 0x40000;
  *(ushort *)(param_3 + 3) = (ushort)(uVar1 >> 0xc) & 0x1f;
  *(byte *)((int)param_3 + 0xe) = *(byte *)((int)param_3 + 0xe) | 0x40;
  param_3[6] = 0x3210;
  *(byte *)(param_3 + 6) = *(byte *)(param_3 + 6) & 0x77;
  *(byte *)((int)param_3 + 0x19) = *(byte *)((int)param_3 + 0x19) & 0x77;
  *(byte *)((int)param_3 + 0xe) = *(byte *)((int)param_3 + 0xe) & 0xc0 | 2;
  if (*(int *)(param_1 + 0x24) != 0) {
    return *(int *)(param_1 + 0x24);
  }
  piVar6 = (int *)(param_1 + 0x28);
  local_20 = *(uint *)(param_1 + 0x30);
  iVar4 = *(int *)(param_1 + 0x2c);
  if (local_20 < iVar4 + 3U) {
    if (local_20 == 0) {
      local_20 = 0x10;
    }
    else {
      local_20 = local_20 * 2;
    }
    for (; local_20 < iVar4 + 3U; local_20 = local_20 * 2) {
    }
    if ((void *)*piVar6 == (void *)0x0) {
      pvVar2 = _malloc(local_20 << 2);
    }
    else {
      pvVar2 = _realloc((void *)*piVar6,local_20 << 2);
    }
    if (pvVar2 == (void *)0x0) {
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) {
        return *(int *)(param_1 + 0x24);
      }
      puVar3 = (undefined4 *)0x0;
      pdVar7 = &MACH_HEADER.cputype;
      pdVar5 = &MACH_HEADER.cpusubtype;
      goto LAB_00043663;
    }
    *piVar6 = (int)pvVar2;
    *(uint *)(param_1 + 0x30) = local_20;
    iVar4 = *(int *)(param_1 + 0x2c);
  }
  puVar3 = (undefined4 *)(*piVar6 + iVar4 * 4);
  *(int *)(param_1 + 0x2c) = iVar4 + 3;
  pdVar7 = puVar3 + 1;
  pdVar5 = puVar3 + 2;
LAB_00043663:
  *puVar3 = *param_3;
  *pdVar7 = param_3[3];
  *pdVar5 = param_3[6];
  return 0;
}

/* FUN_0004373a @ 0x4373a (2981 bytes) */
int FUN_0004373a(param_1, param_2)
  int *param_1;
  int param_2;
{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  dword *pdVar7;
  undefined4 *puVar8;
  dword *pdVar9;
  uint uVar10;
  uint *puVar11;
  dword *pdVar12;
  dword local_84 [3];
  undefined4 local_78;
  uint local_70;
  undefined4 local_6c;
  undefined1 local_68 [4];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  dword local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48 [3];
  undefined4 local_3c;
  undefined4 local_38;
  dword local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_24 [4];
  undefined1 local_14 [4];
  ushort local_10;
  
  iVar6 = *param_1;
  iVar2 = *(int *)(iVar6 + 0x54);
  puVar8 = &local_3c;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  puVar8 = &local_60;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  local_3c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_3c) + 2)),0x5b);
  local_38 = (uint)CONCAT12(0x44,(short)param_1[8]);
  local_34 = 0x55;
  iVar6 = iVar6 + iVar2 * 8 + param_2 * 8;
  iVar2 = ((int (*)())FUN_0003e8ce)(local_24);
  if (iVar2 != 0) goto LAB_0004380e;
  local_2c = 0x440000;
  local_24[1] = 0x5555;
  if (param_1[9] != 0) goto LAB_000437fb;
  piVar5 = param_1 + 10;
  uVar10 = param_1[0xc];
  iVar2 = param_1[0xb];
  if (uVar10 < iVar2 + 7U) {
    if (uVar10 == 0) {
      uVar10 = 0x10;
    }
    else {
      uVar10 = uVar10 * 2;
    }
    for (; uVar10 < iVar2 + 7U; uVar10 = uVar10 * 2) {
    }
    if ((void *)*piVar5 == (void *)0x0) {
      pvVar3 = _malloc(uVar10 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar5 = (int)pvVar3;
        goto LAB_00043885;
      }
    }
    else {
      pvVar3 = _realloc((void *)*piVar5,uVar10 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar5 = (int)pvVar3;
LAB_00043885:
        param_1[0xc] = uVar10;
        iVar2 = param_1[0xb];
        goto LAB_00043891;
      }
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) goto LAB_000437fb;
    puVar8 = (undefined4 *)0x0;
    pdVar7 = &MACH_HEADER.cputype;
    pdVar9 = &MACH_HEADER.cpusubtype;
  }
  else {
LAB_00043891:
    puVar8 = (undefined4 *)(*piVar5 + iVar2 * 4);
    param_1[0xb] = iVar2 + 7;
    pdVar7 = puVar8 + 1;
    pdVar9 = puVar8 + 2;
  }
  *puVar8 = local_3c;
  *pdVar7 = local_38;
  *pdVar9 = local_34;
  iVar4 = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)((int)puVar8 + iVar2 * 2 + 0xc) = *(undefined4 *)(iVar2 + 0xc + (int)&local_3c);
    *(undefined4 *)((int)puVar8 + iVar2 * 2 + 0x10) = *(undefined4 *)(iVar2 + 0x18 + (int)&local_3c)
    ;
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar4 != 2);
  local_60 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_60) + 2)) & 0xc000,0xd) | 0x20000;
  local_5c = (uint)CONCAT12(0x44,(short)param_1[8] + 1);
  local_58 = 0x55;
  local_54 = (uint)CONCAT12(0x44,(short)param_1[8]);
  local_48[0] = 0x3210;
  local_50 = 0x440000;
  local_4c = 0x440000;
  local_48[1] = 0x4454;
  local_48[2] = 0x4445;
  if (param_1[9] != 0) goto LAB_000437fb;
  uVar10 = param_1[0xc];
  iVar2 = param_1[0xb];
  if (uVar10 < iVar2 + 9U) {
    if (uVar10 == 0) {
      uVar10 = 0x10;
    }
    else {
      uVar10 = uVar10 * 2;
    }
    for (; uVar10 < iVar2 + 9U; uVar10 = uVar10 * 2) {
    }
    if ((void *)*piVar5 == (void *)0x0) {
      pvVar3 = _malloc(uVar10 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar5 = (int)pvVar3;
        goto LAB_00043a09;
      }
    }
    else {
      pvVar3 = _realloc((void *)*piVar5,uVar10 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar5 = (int)pvVar3;
LAB_00043a09:
        param_1[0xc] = uVar10;
        iVar2 = param_1[0xb];
        goto LAB_00043a15;
      }
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) goto LAB_000437fb;
    puVar11 = (uint *)0x0;
    pdVar7 = &MACH_HEADER.cputype;
    pdVar9 = &MACH_HEADER.cpusubtype;
  }
  else {
LAB_00043a15:
    puVar11 = (uint *)(*piVar5 + iVar2 * 4);
    param_1[0xb] = iVar2 + 9;
    pdVar7 = puVar11 + 1;
    pdVar9 = puVar11 + 2;
  }
  *puVar11 = local_60;
  *pdVar7 = local_5c;
  *pdVar9 = local_58;
  iVar2 = 0;
  iVar4 = 0;
  do {
    *(undefined4 *)((int)puVar11 + iVar4 * 2 + 0xc) = *(undefined4 *)(iVar4 + 0xc + (int)&local_60);
    *(undefined4 *)((int)puVar11 + iVar4 * 2 + 0x10) =
         *(undefined4 *)(iVar4 + 0x18 + (int)&local_60);
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar2 != 3);
  if (1 < (*(byte *)(iVar6 + 4) >> 4 & 3)) {
    local_30 = (uint)CONCAT12(0x44,(short)param_1[8]);
    local_24[0] = 0x3210;
    if (param_1[9] != 0) goto LAB_000437fb;
    uVar10 = param_1[0xc];
    iVar2 = param_1[0xb];
    if (uVar10 < iVar2 + 7U) {
      if (uVar10 != 0) goto LAB_00043bbf;
      for (uVar10 = 0x10; uVar10 < iVar2 + 7U; uVar10 = uVar10 * 2) {
LAB_00043bbf: ;
      }
      if ((void *)*piVar5 == (void *)0x0) {
        pvVar3 = _malloc(uVar10 * 4);
        if (pvVar3 != (void *)0x0) {
          *piVar5 = (int)pvVar3;
          goto LAB_00043bf8;
        }
      }
      else {
        pvVar3 = _realloc((void *)*piVar5,uVar10 * 4);
        if (pvVar3 != (void *)0x0) {
          *piVar5 = (int)pvVar3;
LAB_00043bf8:
          param_1[0xc] = uVar10;
          iVar2 = param_1[0xb];
          goto LAB_00043ac9;
        }
      }
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) goto LAB_000437fb;
      puVar8 = (undefined4 *)0x0;
      pdVar7 = &MACH_HEADER.cputype;
      pdVar9 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00043ac9:
      puVar8 = (undefined4 *)(*piVar5 + iVar2 * 4);
      param_1[0xb] = iVar2 + 7;
      pdVar7 = puVar8 + 1;
      pdVar9 = puVar8 + 2;
    }
    *puVar8 = local_3c;
    *pdVar7 = local_38;
    *pdVar9 = local_34;
    iVar4 = 0;
    iVar2 = 0;
    do {
      *(undefined4 *)((int)puVar8 + iVar2 * 2 + 0xc) = *(undefined4 *)(iVar2 + 0xc + (int)&local_3c)
      ;
      *(undefined4 *)((int)puVar8 + iVar2 * 2 + 0x10) =
           *(undefined4 *)(iVar2 + 0x18 + (int)&local_3c);
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar4 != 2);
    local_48[1] = local_48[1] & 0xfffff88f | 0x540;
    local_4c = (uint)CONCAT12(0x44,(short)param_1[8] + 1);
    local_48[2] = 0x3210;
    if (param_1[9] != 0) goto LAB_000437fb;
    uVar10 = param_1[0xc];
    iVar2 = param_1[0xb];
    if (uVar10 < iVar2 + 9U) {
      if (uVar10 != 0) goto LAB_00043b98;
      for (uVar10 = 0x10; uVar10 < iVar2 + 9U; uVar10 = uVar10 * 2) {
LAB_00043b98: ;
      }
      if ((void *)*piVar5 == (void *)0x0) {
        pvVar3 = _malloc(uVar10 * 4);
        if (pvVar3 != (void *)0x0) {
          *piVar5 = (int)pvVar3;
          goto LAB_00043c3c;
        }
      }
      else {
        pvVar3 = _realloc((void *)*piVar5,uVar10 * 4);
        if (pvVar3 != (void *)0x0) {
          *piVar5 = (int)pvVar3;
LAB_00043c3c:
          param_1[0xc] = uVar10;
          iVar2 = param_1[0xb];
          goto LAB_00043c48;
        }
      }
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) goto LAB_000437fb;
      puVar11 = (uint *)0x0;
      pdVar7 = &MACH_HEADER.cputype;
      pdVar9 = &MACH_HEADER.cpusubtype;
    }
    else {
LAB_00043c48:
      puVar11 = (uint *)(*piVar5 + iVar2 * 4);
      param_1[0xb] = iVar2 + 9;
      pdVar7 = puVar11 + 1;
      pdVar9 = puVar11 + 2;
    }
    *puVar11 = local_60;
    *pdVar7 = local_5c;
    *pdVar9 = local_58;
    iVar2 = 0;
    iVar4 = 0;
    do {
      *(undefined4 *)((int)puVar11 + iVar4 * 2 + 0xc) =
           *(undefined4 *)(iVar4 + 0xc + (int)&local_60);
      *(undefined4 *)((int)puVar11 + iVar4 * 2 + 0x10) =
           *(undefined4 *)(iVar4 + 0x18 + (int)&local_60);
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar2 != 3);
    if ((*(byte *)(iVar6 + 4) & 0x30) == 0x30) {
      if (param_1[9] != 0) goto LAB_0004380e;
      uVar10 = param_1[0xc];
      iVar2 = param_1[0xb];
      if (uVar10 < iVar2 + 7U) {
        if (uVar10 == 0) {
          uVar10 = 0x10;
        }
        else {
          uVar10 = uVar10 * 2;
        }
        for (; uVar10 < iVar2 + 7U; uVar10 = uVar10 * 2) {
        }
        if ((void *)*piVar5 == (void *)0x0) {
          pvVar3 = _malloc(uVar10 * 4);
          if (pvVar3 != (void *)0x0) {
            *piVar5 = (int)pvVar3;
            goto LAB_00043f85;
          }
        }
        else {
          pvVar3 = _realloc((void *)*piVar5,uVar10 * 4);
          if (pvVar3 != (void *)0x0) {
            *piVar5 = (int)pvVar3;
LAB_00043f85:
            param_1[0xc] = uVar10;
            iVar2 = param_1[0xb];
            goto LAB_00043f91;
          }
        }
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        if (param_1[9] != 0) goto LAB_0004380e;
        puVar8 = (undefined4 *)0x0;
        pdVar7 = &MACH_HEADER.cputype;
        pdVar9 = &MACH_HEADER.cpusubtype;
      }
      else {
LAB_00043f91:
        puVar8 = (undefined4 *)(*piVar5 + iVar2 * 4);
        param_1[0xb] = iVar2 + 7;
        pdVar7 = puVar8 + 1;
        pdVar9 = puVar8 + 2;
      }
      *puVar8 = local_3c;
      *pdVar7 = local_38;
      *pdVar9 = local_34;
      iVar4 = 0;
      iVar2 = 0;
      do {
        *(undefined4 *)((int)puVar8 + iVar2 * 2 + 0xc) =
             *(undefined4 *)(iVar2 + 0xc + (int)&local_3c);
        *(undefined4 *)((int)puVar8 + iVar2 * 2 + 0x10) =
             *(undefined4 *)(iVar2 + 0x18 + (int)&local_3c);
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + 4;
      } while (iVar4 != 2);
      local_48[1] = local_48[1] & 0xffff88ff | 0x5400;
      if (param_1[9] != 0) goto LAB_000437fb;
      uVar10 = param_1[0xc];
      iVar2 = param_1[0xb];
      if (uVar10 < iVar2 + 9U) {
        if (uVar10 != 0) goto LAB_00044020;
        for (uVar10 = 0x10; uVar10 < iVar2 + 9U; uVar10 = uVar10 * 2) {
LAB_00044020: ;
        }
        if ((void *)*piVar5 == (void *)0x0) {
          pvVar3 = _malloc(uVar10 * 4);
          if (pvVar3 != (void *)0x0) {
            *piVar5 = (int)pvVar3;
            goto LAB_00044059;
          }
        }
        else {
          pvVar3 = _realloc((void *)*piVar5,uVar10 * 4);
          if (pvVar3 != (void *)0x0) {
            *piVar5 = (int)pvVar3;
LAB_00044059:
            param_1[0xc] = uVar10;
            iVar2 = param_1[0xb];
            goto LAB_00044065;
          }
        }
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        if (param_1[9] != 0) {
LAB_000437fb:
          return param_1[9];
        }
        puVar11 = (uint *)0x0;
        pdVar7 = &MACH_HEADER.cputype;
        pdVar9 = &MACH_HEADER.cpusubtype;
      }
      else {
LAB_00044065:
        puVar11 = (uint *)(*piVar5 + iVar2 * 4);
        param_1[0xb] = iVar2 + 9;
        pdVar7 = puVar11 + 1;
        pdVar9 = puVar11 + 2;
      }
      *puVar11 = local_60;
      *pdVar7 = local_5c;
      *pdVar9 = local_58;
      iVar2 = 0;
      iVar4 = 0;
      do {
        *(undefined4 *)((int)puVar11 + iVar4 * 2 + 0xc) =
             *(undefined4 *)(iVar4 + 0xc + (int)&local_60);
        *(undefined4 *)((int)puVar11 + iVar4 * 2 + 0x10) =
             *(undefined4 *)(iVar4 + 0x18 + (int)&local_60);
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 4;
      } while (iVar2 != 3);
    }
  }
  pdVar7 = local_84;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pdVar7 = 0;
    pdVar7 = pdVar7 + 1;
  }
  local_84[0] = CONCAT22((*(unsigned short *)((unsigned char *)&(local_84[0]) + 2)),0xd);
  local_60 = local_60 & 0xc000ffff | 0x30000;
  iVar2 = ((int (*)())FUN_0003ee9d)(local_84 + 2,*(byte *)(iVar6 + 5) >> 3 & 1);
  if (iVar2 != 0) {
    return param_1[9];
  }
  local_78 = (uint)CONCAT12(0x44,(short)param_1[8] + 1);
  local_6c = 0x3210;
  iVar2 = ((int (*)())FUN_0003e8ce)(local_68);
  if (iVar2 != 0) goto LAB_0004380e;
  iVar2 = ((int (*)())FUN_0003e540)(local_14,0);
  if (iVar2 == 0) {
    local_24[3] = 0x3210;
    bVar1 = *(byte *)(iVar6 + 10);
    if ((bVar1 & 4) != 0) {
      ((int (*)())FUN_0003e5fc)();
      bVar1 = *(byte *)(iVar6 + 10);
    }
    if ((bVar1 & 2) != 0) {
      ((int (*)())FUN_0003e5fc)();
      bVar1 = *(byte *)(iVar6 + 10);
    }
    if ((bVar1 & 1) != 0) {
      ((int (*)())FUN_0003e5fc)();
    }
    if (*(char *)(iVar6 + 9) < '\0') {
      ((int (*)())FUN_0003e5fc)();
    }
    local_64 = local_24[3];
    local_70 = local_10 | 0x440000;
  }
  else if (param_1[9] != 0) {
    return param_1[9];
  }
  if (param_1[9] != 0) goto LAB_0004380e;
  uVar10 = param_1[0xc];
  iVar6 = param_1[0xb];
  if (uVar10 < iVar6 + 9U) {
    if (uVar10 == 0) {
      uVar10 = 0x10;
    }
    else {
      uVar10 = uVar10 * 2;
    }
    for (; uVar10 < iVar6 + 9U; uVar10 = uVar10 * 2) {
    }
    if ((void *)*piVar5 == (void *)0x0) {
      pvVar3 = _malloc(uVar10 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar5 = (int)pvVar3;
        goto LAB_00043eb5;
      }
    }
    else {
      pvVar3 = _realloc((void *)*piVar5,uVar10 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar5 = (int)pvVar3;
LAB_00043eb5:
        param_1[0xc] = uVar10;
        iVar6 = param_1[0xb];
        goto LAB_00043ec1;
      }
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) {
LAB_0004380e:
      return param_1[9];
    }
    pdVar12 = (dword *)0x0;
    pdVar7 = &MACH_HEADER.cputype;
    pdVar9 = &MACH_HEADER.cpusubtype;
  }
  else {
LAB_00043ec1:
    pdVar12 = (dword *)(*piVar5 + iVar6 * 4);
    param_1[0xb] = iVar6 + 9;
    pdVar7 = pdVar12 + 1;
    pdVar9 = pdVar12 + 2;
  }
  *pdVar12 = local_84[0];
  *pdVar7 = local_84[1];
  *pdVar9 = local_84[2];
  iVar6 = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)((int)pdVar12 + iVar2 * 2 + 0xc) = *(undefined4 *)(iVar2 + 0xc + (int)local_84);
    *(undefined4 *)((int)pdVar12 + iVar2 * 2 + 0x10) = *(undefined4 *)(iVar2 + 0x18 + (int)local_84)
    ;
    iVar6 = iVar6 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar6 != 3);
  return 0;
}

/* FUN_000442df @ 0x442df (2438 bytes) */
int FUN_000442df(param_1, param_2)
  int *param_1;
  int param_2;
{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  byte bVar4;
  short sVar5;
  int iVar6;
  int *piVar7;
  dword *pdVar8;
  undefined4 *puVar9;
  uint *puVar10;
  byte bVar11;
  dword *pdVar12;
  uint uVar13;
  int iVar14;
  undefined4 local_64;
  undefined4 local_60;
  dword local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  byte local_48;
  byte bStack_47;
  undefined2 uStack_46;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  dword local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_28 [3];
  byte local_1c;
  byte bStack_1b;
  undefined4 local_18;
  dword local_14;
  dword local_10;
  
  iVar2 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
  puVar9 = &local_40;
  for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  iVar6 = 9;
  puVar9 = &local_64;
  while( true ) {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  iVar6 = iVar2 + param_2 * 8;
  iVar2 = ((int (*)())FUN_0003ee9d)(&local_14,*(byte *)(iVar2 + 5 + param_2 * 8) >> 3 & 1);
  if (iVar2 != 0) goto LAB_00044346;
  iVar2 = ((int (*)())FUN_0003e8ce)(&local_1c);
  if (iVar2 != 0) goto LAB_00044377;
  local_40 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_40) + 2)),0x5b);
  local_3c = (uint)CONCAT12(0x44,(short)param_1[8]);
  local_38 = 0x55;
  iVar2 = ((int (*)())FUN_0003e8ce)(local_28);
  if (iVar2 != 0) goto LAB_00044346;
  local_30 = 0x440000;
  local_28[1] = 0x5555;
  if (param_1[9] != 0) goto LAB_00044a83;
  piVar7 = param_1 + 10;
  uVar13 = param_1[0xc];
  iVar2 = param_1[0xb];
  if (uVar13 < iVar2 + 7U) {
    if (uVar13 == 0) {
      uVar13 = 0x10;
    }
    else {
      uVar13 = uVar13 * 2;
    }
    for (; uVar13 < iVar2 + 7U; uVar13 = uVar13 * 2) {
    }
    if ((void *)*piVar7 == (void *)0x0) {
      pvVar3 = _malloc(uVar13 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar7 = (int)pvVar3;
        goto LAB_00044463;
      }
    }
    else {
      pvVar3 = _realloc((void *)*piVar7,uVar13 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar7 = (int)pvVar3;
LAB_00044463:
        param_1[0xc] = uVar13;
        iVar2 = param_1[0xb];
        goto LAB_0004446c;
      }
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) goto LAB_00044a83;
    puVar9 = (undefined4 *)0x0;
    pdVar8 = &MACH_HEADER.cputype;
    pdVar12 = &MACH_HEADER.cpusubtype;
  }
  else {
LAB_0004446c:
    puVar9 = (undefined4 *)(*piVar7 + iVar2 * 4);
    param_1[0xb] = iVar2 + 7;
    pdVar8 = puVar9 + 1;
    pdVar12 = puVar9 + 2;
  }
  *puVar9 = local_40;
  *pdVar8 = local_3c;
  *pdVar12 = local_38;
  iVar14 = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)((int)puVar9 + iVar2 * 2 + 0xc) = *(undefined4 *)(iVar2 + 0xc + (int)&local_40);
    *(undefined4 *)((int)puVar9 + iVar2 * 2 + 0x10) = *(undefined4 *)(iVar2 + 0x18 + (int)&local_40)
    ;
    iVar14 = iVar14 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar14 != 2);
  local_64 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_64) + 2)) & 0xc000,0xd) | 0x20000;
  if ((*(byte *)(iVar6 + 0x12) & 0xc) == 4) {
    local_60 = local_10;
    local_5c = local_14;
    sVar5 = (short)param_1[8];
  }
  else {
    sVar5 = (short)param_1[8];
    local_60 = (dword)CONCAT12(0x44,sVar5 + 1);
    local_5c = 0x55;
  }
  local_58 = (uint)CONCAT12(0x44,sVar5);
  local_4c = 0x3210;
  local_54 = local_18;
  bVar11 = local_1c >> 4 & 7;
  bVar1 = ((char)local_1c >> 7) * -8;
  bVar4 = ((char)local_1c >> 7) * -0x80;
  uStack_46 = (undefined2)((uint)local_1c >> 0x10);
  local_48 = CONCAT11(bVar11 | bVar1 & 0xf | bVar11 << 4 | bVar4,
                       bVar11 | bVar1 & 0xf | bVar11 << 4 | bVar4);
  local_50 = local_18;
  bVar1 = (local_1c >> 3 & 1) * '\b' | local_1c & 7 | (local_1c & 7) << 4 | (local_1c >> 3) << 7;
  local_44 = CONCAT22(uStack_46,CONCAT11(bVar1,bVar1));
  if (param_1[9] != 0) goto LAB_00044a83;
  uVar13 = param_1[0xc];
  iVar2 = param_1[0xb];
  if (uVar13 < iVar2 + 9U) {
    if (uVar13 == 0) {
      uVar13 = 0x10;
    }
    else {
      uVar13 = uVar13 * 2;
    }
    for (; uVar13 < iVar2 + 9U; uVar13 = uVar13 * 2) {
    }
    if ((void *)*piVar7 == (void *)0x0) {
      pvVar3 = _malloc(uVar13 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar7 = (int)pvVar3;
        goto LAB_0004463b;
      }
    }
    else {
      pvVar3 = _realloc((void *)*piVar7,uVar13 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar7 = (int)pvVar3;
LAB_0004463b:
        param_1[0xc] = uVar13;
        iVar2 = param_1[0xb];
        goto LAB_00044644;
      }
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) goto LAB_00044a83;
    puVar10 = (uint *)0x0;
    pdVar8 = &MACH_HEADER.cputype;
    pdVar12 = &MACH_HEADER.cpusubtype;
  }
  else {
LAB_00044644:
    puVar10 = (uint *)(*piVar7 + iVar2 * 4);
    param_1[0xb] = iVar2 + 9;
    pdVar8 = puVar10 + 1;
    pdVar12 = puVar10 + 2;
  }
  *puVar10 = local_64;
  *pdVar8 = local_60;
  *pdVar12 = local_5c;
  iVar2 = 0;
  iVar14 = 0;
  do {
    *(undefined4 *)((int)puVar10 + iVar14 * 2 + 0xc) =
         *(undefined4 *)(iVar14 + 0xc + (int)&local_64);
    *(undefined4 *)((int)puVar10 + iVar14 * 2 + 0x10) =
         *(undefined4 *)(iVar14 + 0x18 + (int)&local_64);
    iVar2 = iVar2 + 1;
    iVar14 = iVar14 + 4;
  } while (iVar2 != 3);
  if ((*(byte *)(iVar6 + 0x12) >> 2 & 3) < 2) {
    return 0;
  }
  local_34 = (uint)CONCAT12(0x44,(short)param_1[8]);
  local_28[0] = 0x3210;
  if (param_1[9] != 0) goto LAB_00044a83;
  uVar13 = param_1[0xc];
  iVar2 = param_1[0xb];
  if (uVar13 < iVar2 + 7U) {
    if (uVar13 != 0) goto LAB_000446f4;
    for (uVar13 = 0x10; uVar13 < iVar2 + 7U; uVar13 = uVar13 * 2) {
LAB_000446f4: ;
    }
    if ((void *)*piVar7 == (void *)0x0) {
      pvVar3 = _malloc(uVar13 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar7 = (int)pvVar3;
        goto LAB_00044727;
      }
    }
    else {
      pvVar3 = _realloc((void *)*piVar7,uVar13 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar7 = (int)pvVar3;
LAB_00044727:
        param_1[0xc] = uVar13;
        iVar2 = param_1[0xb];
        goto LAB_00044730;
      }
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) goto LAB_00044a83;
    puVar9 = (undefined4 *)0x0;
    pdVar8 = &MACH_HEADER.cputype;
    pdVar12 = &MACH_HEADER.cpusubtype;
  }
  else {
LAB_00044730:
    puVar9 = (undefined4 *)(*piVar7 + iVar2 * 4);
    param_1[0xb] = iVar2 + 7;
    pdVar8 = puVar9 + 1;
    pdVar12 = puVar9 + 2;
  }
  *puVar9 = local_40;
  *pdVar8 = local_3c;
  *pdVar12 = local_38;
  iVar14 = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)((int)puVar9 + iVar2 * 2 + 0xc) = *(undefined4 *)(iVar2 + 0xc + (int)&local_40);
    *(undefined4 *)((int)puVar9 + iVar2 * 2 + 0x10) = *(undefined4 *)(iVar2 + 0x18 + (int)&local_40)
    ;
    iVar14 = iVar14 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar14 != 2);
  if ((*(byte *)(iVar6 + 0x12) & 0xc) == 8) {
    local_60 = local_10;
    local_5c = local_14;
  }
  bVar1 = (bStack_1b >> 3 & 1) * '\b' | bStack_1b & 7 | (bStack_1b & 7) << 4 | (bStack_1b >> 3) << 7
  ;
  local_48 = CONCAT11(bVar1,bVar1);
  local_50 = (uint)CONCAT12(0x44,(short)param_1[8] + 1);
  local_44 = 0x3210;
  if (param_1[9] != 0) goto LAB_00044a83;
  uVar13 = param_1[0xc];
  iVar2 = param_1[0xb];
  if (uVar13 < iVar2 + 9U) {
    if (uVar13 != 0) goto LAB_00044819;
    for (uVar13 = 0x10; uVar13 < iVar2 + 9U; uVar13 = uVar13 * 2) {
LAB_00044819: ;
    }
    if ((void *)*piVar7 == (void *)0x0) {
      pvVar3 = _malloc(uVar13 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar7 = (int)pvVar3;
        goto LAB_0004484c;
      }
    }
    else {
      pvVar3 = _realloc((void *)*piVar7,uVar13 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar7 = (int)pvVar3;
LAB_0004484c:
        param_1[0xc] = uVar13;
        iVar2 = param_1[0xb];
        goto LAB_00044855;
      }
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) {
LAB_00044a83:
      return param_1[9];
    }
    puVar10 = (uint *)0x0;
    pdVar8 = &MACH_HEADER.cputype;
    pdVar12 = &MACH_HEADER.cpusubtype;
  }
  else {
LAB_00044855:
    puVar10 = (uint *)(*piVar7 + iVar2 * 4);
    param_1[0xb] = iVar2 + 9;
    pdVar8 = puVar10 + 1;
    pdVar12 = puVar10 + 2;
  }
  *puVar10 = local_64;
  *pdVar8 = local_60;
  *pdVar12 = local_5c;
  iVar2 = 0;
  iVar14 = 0;
  do {
    *(undefined4 *)((int)puVar10 + iVar14 * 2 + 0xc) =
         *(undefined4 *)(iVar14 + 0xc + (int)&local_64);
    *(undefined4 *)((int)puVar10 + iVar14 * 2 + 0x10) =
         *(undefined4 *)(iVar14 + 0x18 + (int)&local_64);
    iVar2 = iVar2 + 1;
    iVar14 = iVar14 + 4;
  } while (iVar2 != 3);
  if ((*(byte *)(iVar6 + 0x12) & 0xc) != 0xc) {
    return 0;
  }
  if (param_1[9] != 0) goto LAB_00044377;
  uVar13 = param_1[0xc];
  iVar2 = param_1[0xb];
  if (uVar13 < iVar2 + 7U) {
    if (uVar13 == 0) {
      uVar13 = 0x10;
    }
    else {
      uVar13 = uVar13 * 2;
    }
    for (; uVar13 < iVar2 + 7U; uVar13 = uVar13 * 2) {
    }
    if ((void *)*piVar7 == (void *)0x0) {
      pvVar3 = _malloc(uVar13 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar7 = (int)pvVar3;
        goto LAB_00044914;
      }
    }
    else {
      pvVar3 = _realloc((void *)*piVar7,uVar13 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar7 = (int)pvVar3;
LAB_00044914:
        param_1[0xc] = uVar13;
        iVar2 = param_1[0xb];
        goto LAB_0004491d;
      }
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) {
LAB_00044377:
      return param_1[9];
    }
    puVar9 = (undefined4 *)0x0;
    pdVar8 = &MACH_HEADER.cputype;
    pdVar12 = &MACH_HEADER.cpusubtype;
  }
  else {
LAB_0004491d:
    puVar9 = (undefined4 *)(*piVar7 + iVar2 * 4);
    param_1[0xb] = iVar2 + 7;
    pdVar8 = puVar9 + 1;
    pdVar12 = puVar9 + 2;
  }
  *puVar9 = local_40;
  *pdVar8 = local_3c;
  *pdVar12 = local_38;
  iVar6 = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)((int)puVar9 + iVar2 * 2 + 0xc) = *(undefined4 *)(iVar2 + 0xc + (int)&local_40);
    *(undefined4 *)((int)puVar9 + iVar2 * 2 + 0x10) = *(undefined4 *)(iVar2 + 0x18 + (int)&local_40)
    ;
    iVar6 = iVar6 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar6 != 2);
  local_60 = local_10;
  local_5c = local_14;
  bVar4 = bStack_1b >> 4 & 7;
  bVar1 = ((char)bStack_1b >> 7) * -8;
  bVar11 = ((char)bStack_1b >> 7) * -0x80;
  local_48 = CONCAT11(bVar4 | bVar1 & 0xf | bVar4 << 4 | bVar11,
                       bVar4 | bVar1 & 0xf | bVar4 << 4 | bVar11);
  if (param_1[9] != 0) goto LAB_00044346;
  uVar13 = param_1[0xc];
  iVar2 = param_1[0xb];
  if (uVar13 < iVar2 + 9U) {
    if (uVar13 != 0) goto LAB_000449f8;
    for (uVar13 = 0x10; uVar13 < iVar2 + 9U; uVar13 = uVar13 * 2) {
LAB_000449f8: ;
    }
    if ((void *)*piVar7 == (void *)0x0) {
      pvVar3 = _malloc(uVar13 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar7 = (int)pvVar3;
        goto LAB_00044a2b;
      }
    }
    else {
      pvVar3 = _realloc((void *)*piVar7,uVar13 * 4);
      if (pvVar3 != (void *)0x0) {
        *piVar7 = (int)pvVar3;
LAB_00044a2b:
        param_1[0xc] = uVar13;
        iVar2 = param_1[0xb];
        goto LAB_00044a34;
      }
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) {
LAB_00044346:
      return param_1[9];
    }
    puVar10 = (uint *)0x0;
    pdVar8 = &MACH_HEADER.cputype;
    pdVar12 = &MACH_HEADER.cpusubtype;
  }
  else {
LAB_00044a34:
    puVar10 = (uint *)(*piVar7 + iVar2 * 4);
    param_1[0xb] = iVar2 + 9;
    pdVar8 = puVar10 + 1;
    pdVar12 = puVar10 + 2;
  }
  *puVar10 = local_64;
  *pdVar8 = local_60;
  *pdVar12 = local_5c;
  iVar6 = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)((int)puVar10 + iVar2 * 2 + 0xc) = *(undefined4 *)(iVar2 + 0xc + (int)&local_64);
    *(undefined4 *)((int)puVar10 + iVar2 * 2 + 0x10) =
         *(undefined4 *)(iVar2 + 0x18 + (int)&local_64);
    iVar6 = iVar6 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar6 != 3);
  return 0;
}

/* FUN_00044c65 @ 0x44c65 (1386 bytes) */
int FUN_00044c65(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint param_3;
{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  dword *pdVar7;
  int iVar8;
  dword *pdVar9;
  uint uVar10;
  int *piVar11;
  uint local_44;
  uint local_30;
  undefined1 uStack_2a;
  dword local_2c;
  undefined1 uStack_29;
  uint local_28;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined4 local_14;
  
  iVar2 = *param_1;
  iVar8 = *(int *)(iVar2 + 0x54);
  puVar6 = &local_30;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  if (param_3 == 0) {
    local_44 = (*(byte *)(iVar2 + iVar8 * 8 + 4 + param_2 * 8) >> 4 & 3) + 1;
    if (2 < local_44) goto LAB_00044d08;
  }
  else {
    local_44 = param_3;
    if (2 < (int)param_3) {
LAB_00044d08:
      local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),0x49);
      local_2c = CONCAT13(uStack_29,CONCAT12(uStack_2a,(short)param_1[8])) & 0xffc0ffff | 0x440000;
      local_28 = CONCAT31((int3)(local_28 >> 8),0x11) | 0x100;
      if (param_3 == 0) {
        iVar2 = ((int (*)())FUN_0003e8ce)(&local_18);
        if (iVar2 != 0) goto LAB_00045001;
      }
      else {
        (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(0x44,(short)param_1[8]);
        local_24 = (uint)(uint3)local_24;
        local_18 = 0x3210;
      }
      local_20 = local_24;
      (*(unsigned char *)((unsigned char *)&(local_14) + 0)) = (byte)local_18;
      (*(unsigned char *)((unsigned char *)&(local_14) + 1)) = (byte)(local_18 >> 8);
      if (local_44 == 3) {
        bVar1 = (*(unsigned char *)((unsigned char *)&(local_14) + 1)) & 0xf0 | 5;
      }
      else {
        bVar1 = (*(unsigned char *)((unsigned char *)&(local_14) + 1)) & 0xf0 | (*(unsigned char *)((unsigned char *)&(local_14) + 1)) >> 4 & 7 | ((*(unsigned char *)((unsigned char *)&(local_14) + 1)) >> 7) << 3;
      }
      local_14 = CONCAT22((short)(local_18 >> 0x10),
                          CONCAT11(bVar1,(byte)local_14 & 0xf0 | (byte)local_14 >> 4 & 7 |
                                         ((byte)local_14 >> 7) << 3));
      if (param_1[9] != 0) goto LAB_00045001;
      piVar11 = param_1 + 10;
      uVar10 = param_1[0xc];
      iVar2 = param_1[0xb];
      if (uVar10 < iVar2 + 7U) {
        if (uVar10 != 0) goto LAB_0004501d;
        for (uVar10 = 0x10; uVar10 < iVar2 + 7U; uVar10 = uVar10 * 2) {
LAB_0004501d: ;
        }
        if ((void *)*piVar11 == (void *)0x0) {
          pvVar3 = _malloc(uVar10 * 4);
        }
        else {
          pvVar3 = _realloc((void *)*piVar11,uVar10 * 4);
        }
        if (pvVar3 != (void *)0x0) {
          *piVar11 = (int)pvVar3;
          param_1[0xc] = uVar10;
          iVar2 = param_1[0xb];
          goto LAB_00044dd0;
        }
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        if (param_1[9] != 0) goto LAB_00045001;
        puVar6 = (uint *)0x0;
        pdVar9 = &MACH_HEADER.cputype;
        pdVar7 = &MACH_HEADER.cpusubtype;
      }
      else {
LAB_00044dd0:
        puVar6 = (uint *)(*piVar11 + iVar2 * 4);
        param_1[0xb] = iVar2 + 7;
        pdVar9 = puVar6 + 1;
        pdVar7 = puVar6 + 2;
      }
      *puVar6 = local_30;
      *pdVar9 = local_2c;
      *pdVar7 = local_28;
      iVar8 = 0;
      iVar2 = 0;
      do {
        *(undefined4 *)((int)puVar6 + iVar2 * 2 + 0xc) =
             *(undefined4 *)(iVar2 + 0xc + (int)&local_30);
        *(undefined4 *)((int)puVar6 + iVar2 * 2 + 0x10) =
             *(undefined4 *)(iVar2 + 0x18 + (int)&local_30);
        iVar8 = iVar8 + 1;
        iVar2 = iVar2 + 4;
      } while (iVar8 != 2);
      iVar2 = ((int (*)())FUN_0003ee9d)(&local_28,1);
      if (iVar2 == 0) {
        (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(0x44,(short)param_1[8]);
        local_24 = (uint)(uint3)local_24;
        local_18 = 0;
        local_20 = local_24;
        local_14 = local_14 & 0xfffffff8 | 2;
        if (param_1[9] != 0) goto LAB_00044cde;
        uVar10 = param_1[0xc];
        iVar2 = param_1[0xb];
        if (uVar10 < iVar2 + 7U) {
          if (uVar10 != 0) goto LAB_000450d7;
          for (uVar10 = 0x10; uVar10 < iVar2 + 7U; uVar10 = uVar10 * 2) {
LAB_000450d7: ;
          }
          if ((void *)*piVar11 == (void *)0x0) {
            pvVar3 = _malloc(uVar10 * 4);
          }
          else {
            pvVar3 = _realloc((void *)*piVar11,uVar10 * 4);
          }
          if (pvVar3 == (void *)0x0) {
            if (param_1[9] == 0) {
              param_1[9] = 1;
            }
            if (param_1[9] != 0) goto LAB_00044cde;
            puVar6 = (uint *)0x0;
            pdVar9 = &MACH_HEADER.cputype;
            pdVar7 = &MACH_HEADER.cpusubtype;
            goto LAB_00044ea5;
          }
          *piVar11 = (int)pvVar3;
          param_1[0xc] = uVar10;
          iVar2 = param_1[0xb];
        }
        puVar6 = (uint *)(*piVar11 + iVar2 * 4);
        param_1[0xb] = iVar2 + 7;
        pdVar9 = puVar6 + 1;
        pdVar7 = puVar6 + 2;
LAB_00044ea5:
        *puVar6 = local_30;
        *pdVar9 = local_2c;
        *pdVar7 = local_28;
        iVar8 = 0;
        iVar2 = 0;
        do {
          *(undefined4 *)((int)puVar6 + iVar2 * 2 + 0xc) =
               *(undefined4 *)(iVar2 + 0xc + (int)&local_30);
          *(undefined4 *)((int)puVar6 + iVar2 * 2 + 0x10) =
               *(undefined4 *)(iVar2 + 0x18 + (int)&local_30);
          iVar8 = iVar8 + 1;
          iVar2 = iVar2 + 4;
        } while (iVar8 != 2);
        return 0;
      }
      goto LAB_00044cde;
    }
  }
  local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),(ushort)(local_44 != 1) * 2 + 0x47);
  iVar2 = ((int (*)())FUN_0003ee9d)(&local_28,1);
  if (iVar2 != 0) {
LAB_00044cde:
    return param_1[9];
  }
  if (param_3 == 0) {
    iVar2 = ((int (*)())FUN_0003e8ce)(&local_18);
    if (iVar2 != 0) {
      return param_1[9];
    }
  }
  else {
    (*(unsigned int *)((unsigned char *)&(local_24) + 0)) = CONCAT12(0x44,(short)param_1[8]);
    local_24 = (uint)(uint3)local_24;
    local_18 = 0x3210;
  }
  if (local_44 == 2) {
    local_20 = local_24;
    (*(unsigned char *)((unsigned char *)&(local_14) + 0)) = (byte)local_18;
    local_14 = CONCAT31((int3)(local_18 >> 8),
                        (byte)local_14 & 0xf0 | (byte)local_14 >> 4 & 7 | ((byte)local_14 >> 7) << 3
                       );
  }
  if (param_1[9] != 0) {
LAB_00045001:
    return param_1[9];
  }
  piVar11 = param_1 + 10;
  uVar10 = param_1[0xc];
  iVar2 = local_44 * 2 + 3;
  iVar8 = param_1[0xb];
  uVar5 = iVar2 + iVar8;
  if (uVar10 < uVar5) {
    if (uVar10 == 0) {
      uVar10 = 0x10;
      goto LAB_00044f54;
    }
    do {
      uVar10 = uVar10 * 2;
LAB_00044f54: ;
    } while (uVar10 < uVar5);
    if ((void *)*piVar11 == (void *)0x0) {
      pvVar3 = _malloc(uVar10 * 4);
    }
    else {
      pvVar3 = _realloc((void *)*piVar11,uVar10 * 4);
    }
    if (pvVar3 == (void *)0x0) {
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
      if (param_1[9] != 0) goto LAB_00045001;
      puVar6 = (uint *)0x0;
      pdVar9 = &MACH_HEADER.cputype;
      pdVar7 = &MACH_HEADER.cpusubtype;
      goto LAB_00044f98;
    }
    *piVar11 = (int)pvVar3;
    param_1[0xc] = uVar10;
    iVar8 = param_1[0xb];
  }
  puVar6 = (uint *)(*piVar11 + iVar8 * 4);
  param_1[0xb] = iVar2 + iVar8;
  pdVar9 = puVar6 + 1;
  pdVar7 = puVar6 + 2;
LAB_00044f98:
  *puVar6 = local_30;
  *pdVar9 = local_2c;
  *pdVar7 = local_28;
  if ((int)local_44 < 1) {
    return 0;
  }
  uVar10 = 0;
  iVar2 = 0;
  do {
    puVar6[3] = *(uint *)(iVar2 + 0xc + (int)&local_30);
    puVar6[4] = *(uint *)(iVar2 + 0x18 + (int)&local_30);
    uVar10 = uVar10 + 1;
    iVar2 = iVar2 + 4;
    puVar6 = puVar6 + 2;
  } while (local_44 != uVar10);
  return 0;
}

/* FUN_000451cf @ 0x451cf (448 bytes) */
int FUN_000451cf(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  void *pvVar1;
  int iVar2;
  dword *pdVar3;
  dword *pdVar4;
  int *piVar5;
  dword *pdVar6;
  int iVar7;
  uint uVar8;
  dword local_30 [3];
  undefined4 local_24;
  undefined2 local_20;
  byte local_1e;
  undefined4 local_18;
  undefined1 local_14;
  undefined1 local_13;
  
  pdVar6 = local_30;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pdVar6 = 0;
    pdVar6 = pdVar6 + 1;
  }
  local_30[0] = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30[0]) + 2)),0x23);
  iVar2 = ((int (*)())FUN_0003ee9d)(local_30 + 2,1);
  if (iVar2 != 0) {
LAB_00045282:
    return *(undefined4 *)(param_1 + 0x24);
  }
  if (param_3 == 0) {
    iVar2 = ((int (*)())FUN_0003e8ce)(&local_18);
    if (iVar2 != 0) goto LAB_00045282;
    local_20 = (undefined2)*(undefined4 *)(param_1 + 0x20);
  }
  else {
    local_20 = (undefined2)*(undefined4 *)(param_1 + 0x20);
    local_24 = (uint)CONCAT12(0x44,local_20);
    local_18 = 0x3210;
  }
  local_1e = local_1e & 0xc0 | 0x44;
  local_14 = 0x55;
  local_13 = 0x55;
  if (*(int *)(param_1 + 0x24) != 0) {
LAB_00045275:
    return *(undefined4 *)(param_1 + 0x24);
  }
  piVar5 = (int *)(param_1 + 0x28);
  uVar8 = *(uint *)(param_1 + 0x30);
  iVar2 = *(int *)(param_1 + 0x2c);
  if (uVar8 < iVar2 + 7U) {
    if (uVar8 != 0) goto LAB_00045323;
    for (uVar8 = 0x10; uVar8 < iVar2 + 7U; uVar8 = uVar8 * 2) {
LAB_00045323: ;
    }
    if ((void *)*piVar5 == (void *)0x0) {
      pvVar1 = _malloc(uVar8 * 4);
    }
    else {
      pvVar1 = _realloc((void *)*piVar5,uVar8 * 4);
    }
    if (pvVar1 == (void *)0x0) {
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (*(int *)(param_1 + 0x24) != 0) goto LAB_00045275;
      pdVar3 = (dword *)0x0;
      pdVar6 = &MACH_HEADER.cputype;
      pdVar4 = &MACH_HEADER.cpusubtype;
      goto LAB_000452b3;
    }
    *piVar5 = (int)pvVar1;
    *(uint *)(param_1 + 0x30) = uVar8;
    iVar2 = *(int *)(param_1 + 0x2c);
  }
  pdVar3 = (dword *)(*piVar5 + iVar2 * 4);
  *(int *)(param_1 + 0x2c) = iVar2 + 7;
  pdVar6 = pdVar3 + 1;
  pdVar4 = pdVar3 + 2;
LAB_000452b3:
  *pdVar3 = local_30[0];
  *pdVar6 = local_30[1];
  *pdVar4 = local_30[2];
  iVar7 = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)((int)pdVar3 + iVar2 * 2 + 0xc) = *(undefined4 *)(iVar2 + 0xc + (int)local_30);
    *(undefined4 *)((int)pdVar3 + iVar2 * 2 + 0x10) = *(undefined4 *)(iVar2 + 0x18 + (int)local_30);
    iVar7 = iVar7 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar7 != 2);
  return 0;
}

/* FUN_0004538f @ 0x4538f (1018 bytes) */
int FUN_0004538f(param_1, param_2)
  int *param_1;
  int param_2;
{
  ushort *puVar1;
  byte bVar2;
  void *pvVar3;
  byte bVar4;
  int iVar5;
  undefined4 *puVar6;
  uint *puVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  dword *pdVar11;
  dword *pdVar12;
  int *piVar13;
  dword *pdVar14;
  int iVar15;
  uint uVar16;
  uint local_68;
  int local_58;
  int local_54;
  dword *local_50;
  undefined4 local_40;
  undefined4 local_3c;
  dword local_38;
  undefined4 local_34;
  undefined4 local_30;
  dword local_28;
  undefined1 local_24 [20];
  
  iVar10 = *param_1;
  iVar15 = *(int *)(iVar10 + 0x54);
  puVar6 = &local_40;
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  puVar1 = (ushort *)(iVar10 + iVar15 * 8 + param_2 * 8);
  bVar2 = (byte)(*puVar1 >> 6);
  if ((*(byte *)(param_1 + 5) & 4) == 0) {
    bVar8 = 0;
    bVar4 = 0;
    bVar9 = 0;
    local_68 = 3;
  }
  else {
    local_68 = (byte)((byte)puVar1[2] >> 4) & 3;
    bVar8 = (byte)puVar1[2] >> 3 & 1;
    bVar4 = (byte)puVar1[9] >> 1 & 1;
    bVar9 = (byte)puVar1[0xd] >> 1 & 1;
  }
  iVar10 = (uint)bVar2 * 0x10;
  local_40 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_40) + 2)) & 0xc000 | *(ushort *)(&DAT_001ed804 + iVar10) & 0x1fff,
                      (short)(*(uint *)(&DAT_001ed800 + iVar10) >> 0xf));
  iVar10 = ((int (*)())FUN_0003ee9d)(&local_38,*(byte *)((int)puVar1 + 5) >> 3 & 1);
  if (iVar10 == 0) {
    iVar10 = ((int (*)())FUN_0003e8ce)(&local_28);
    if (iVar10 != 0) goto LAB_000454b6;
    iVar10 = ((int (*)())FUN_0003e8ce)(local_24);
    if (iVar10 != 0) goto LAB_00045450;
    if (bVar8 == 0) {
      local_58 = 1;
    }
    else {
      local_58 = local_68 + 1;
      if (local_58 == 0) {
LAB_000454ff:
        if ((((*(byte *)(param_1 + 5) & 4) == 0) || (bVar2 != 0x3a)) ||
           (iVar10 = ((int (*)())FUN_0003e511)(), iVar10 != 1)) {
          return 0;
        }
        local_40 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_40) + 2)),99) & 0xc000ffff;
        bVar2 = (*(unsigned char *)((unsigned char *)&(local_34) + 2)) & 0xc0;
        (*(unsigned int *)((unsigned char *)&(local_34) + 0)) = CONCAT12(bVar2 | (*(unsigned char *)((unsigned char *)&(local_3c) + 2)) & 0x3f,(short)local_3c);
        local_28 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_28) + 2)),0x3210);
        if (param_1[9] != 0) {
LAB_000454b6:
          return param_1[9];
        }
        piVar13 = param_1 + 10;
        uVar16 = param_1[0xc];
        iVar10 = param_1[0xb];
        if (uVar16 < iVar10 + 5U) {
          if (uVar16 != 0) goto LAB_0004557e;
          for (uVar16 = 0x10; uVar16 < iVar10 + 5U; uVar16 = uVar16 * 2) {
LAB_0004557e: ;
          }
          if ((void *)*piVar13 == (void *)0x0) {
            pvVar3 = _malloc(uVar16 * 4);
          }
          else {
            pvVar3 = _realloc((void *)*piVar13,uVar16 * 4);
          }
          if (pvVar3 == (void *)0x0) {
            if (param_1[9] == 0) {
              param_1[9] = 1;
            }
            if (param_1[9] != 0) goto LAB_000454b6;
            puVar7 = (uint *)0x0;
            local_50 = &MACH_HEADER.cputype;
            pdVar14 = &MACH_HEADER.cpusubtype;
            pdVar12 = &MACH_HEADER.filetype;
            pdVar11 = &MACH_HEADER.ncmds;
            goto LAB_000455cb;
          }
          *piVar13 = (int)pvVar3;
          param_1[0xc] = uVar16;
          iVar10 = param_1[0xb];
        }
        puVar7 = (uint *)(*piVar13 + iVar10 * 4);
        param_1[0xb] = iVar10 + 5;
        local_50 = puVar7 + 1;
        pdVar14 = puVar7 + 2;
        pdVar12 = puVar7 + 3;
        pdVar11 = puVar7 + 4;
LAB_000455cb:
        *puVar7 = local_40;
        *local_50 = local_3c;
        *pdVar14 = local_38;
        *pdVar12 = local_34;
        *pdVar11 = local_28;
        return 0;
      }
    }
    if (param_1[9] == 0) {
      local_54 = 0;
      piVar13 = param_1 + 10;
      do {
        uVar16 = param_1[0xc];
        iVar10 = param_1[0xb];
        if (uVar16 < iVar10 + 7U) {
          if (uVar16 == 0) {
            uVar16 = 0x10;
          }
          else {
            uVar16 = uVar16 * 2;
          }
          for (; uVar16 < iVar10 + 7U; uVar16 = uVar16 * 2) {
          }
          if ((void *)*piVar13 == (void *)0x0) {
            pvVar3 = _malloc(uVar16 * 4);
          }
          else {
            pvVar3 = _realloc((void *)*piVar13,uVar16 * 4);
          }
          if (pvVar3 != (void *)0x0) {
            *piVar13 = (int)pvVar3;
            param_1[0xc] = uVar16;
            iVar10 = param_1[0xb];
            goto LAB_00045662;
          }
          if (param_1[9] == 0) {
            param_1[9] = 1;
          }
          if (param_1[9] != 0) break;
          puVar6 = (undefined4 *)0x0;
          pdVar14 = &MACH_HEADER.cputype;
          pdVar12 = &MACH_HEADER.cpusubtype;
        }
        else {
LAB_00045662:
          puVar6 = (undefined4 *)(*piVar13 + iVar10 * 4);
          param_1[0xb] = iVar10 + 7;
          pdVar14 = puVar6 + 1;
          pdVar12 = puVar6 + 2;
        }
        *puVar6 = local_40;
        *pdVar14 = local_3c;
        *pdVar12 = local_38;
        iVar15 = 0;
        iVar10 = 0;
        do {
          *(undefined4 *)((int)puVar6 + iVar10 * 2 + 0xc) =
               *(undefined4 *)(iVar10 + 0xc + (int)&local_40);
          *(undefined4 *)((int)puVar6 + iVar10 * 2 + 0x10) =
               *(undefined4 *)(iVar10 + 0x18 + (int)&local_40);
          iVar15 = iVar15 + 1;
          iVar10 = iVar10 + 4;
        } while (iVar15 != 2);
        if (bVar8 != 0) {
          local_3c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_3c) + 2)),(short)local_3c + 1);
        }
        local_34 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_34) + 2)),((short)local_34 + 1) - (ushort)(bVar4 == 0));
        local_30 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_30) + 2)),((short)local_30 + 1) - (ushort)(bVar9 == 0));
        local_54 = local_54 + 1;
        if (local_58 == local_54) goto LAB_000454ff;
      } while (param_1[9] == 0);
    }
  }
LAB_00045450:
  return param_1[9];
}

/* FUN_00045789 @ 0x45789 (9082 bytes) */
int FUN_00045789(param_1)
  int *param_1;
{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  byte bVar14;
  byte bVar15;
  ushort *puVar16;
  int iVar17;
  int iVar18;
  char cVar19;
  short sVar20;
  undefined2 uVar21;
  int iVar22;
  undefined4 *puVar23;
  bool bVar24;
  undefined4 local_1a0;
  int local_18c;
  uint *local_184;
  int local_160;
  byte local_15c;
  int local_13c;
  int local_138;
  uint local_134;
  int local_128;
  uint local_120;
  byte local_104;
  int local_f0;
  uint local_bc;
  undefined4 *local_ac;
  ushort *local_a0;
  undefined4 local_98;
  undefined4 local_94;
  uint local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  uint local_5c;
  undefined4 local_58;
  undefined4 local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  undefined4 local_44;
  uint local_40;
  uint local_3c;
  uint *local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  
  iVar22 = *param_1;
  iVar3 = *(int *)(iVar22 + 0x50);
  puVar1 = (ushort *)(iVar22 + *(int *)(iVar22 + 0x54) * 8);
  if (iVar3 < 1) {
    return 0;
  }
  local_15c = (byte)(*puVar1 >> 6);
  local_134 = (uint)local_15c;
  bVar14 = (byte)(DAT_001ed801)[local_134 * 0x10] >> 3 & 0xf;
  if ((bVar14 == 0) || ((DAT_001edf10 & ((DAT_001ed80c)[local_134 * 0x10] & 0xf)) != 0)) {
LAB_00045803:
    if (param_1[9] == 0) {
      param_1[9] = 3;
    }
LAB_00045814:
    return param_1[9];
  }
  local_13c = 0;
  local_138 = 0;
  local_160 = 0;
  local_a0 = puVar1;
LAB_00045b56:
  uVar11 = (uint)((byte)*local_a0 & 7);
  if (bVar14 == 2) {
    iVar22 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
    puVar16 = (ushort *)(local_160 + iVar22);
    bVar14 = (byte)(*puVar16 >> 6);
    if ((bVar14 - 0x44 < 2) || (bVar14 == 0x47)) {
      local_128 = 1;
    }
    else {
      local_128 = 0;
    }
    if (((bVar14 == 0x43) || (bVar14 == 0x45)) || (bVar14 == 0x47)) {
      bVar24 = true;
    }
    else {
      bVar24 = false;
    }
    puVar23 = &local_98;
    for (iVar17 = 9; iVar17 != 0; iVar17 = iVar17 + -1) {
      *puVar23 = 0;
      puVar23 = puVar23 + 1;
    }
    local_98 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_98) + 2)),
                        (short)(*(uint *)(&DAT_001ed800 + (uint)bVar14 * 0x10) >> 0xf));
    iVar22 = iVar22 + local_160;
    ((int (*)())FUN_0003ee9d)(&local_90,*(byte *)((int)puVar16 + 5) >> 3 & 1);
    ((int (*)())FUN_0003e8ce)(&local_80);
    if ((*(byte *)(param_1 + 5) & 4) == 0) {
      local_98 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_98) + 2)) & 0xc000 | (ushort)(*(byte *)(iVar22 + 0x1b) >> 3),
                          (undefined2)local_98);
      local_120 = (uint)(*(byte *)(iVar22 + 0x1b) & 7);
      if (local_128 != 0) {
        local_88 = local_8c;
        local_7c = local_80;
      }
    }
    else {
      local_38 = (uint *)0x0;
      iVar17 = ((int (*)())FUN_0003e7b9)();
      if (iVar17 != 0) {
        iVar22 = param_1[9];
joined_r0x000460a8:
        if (iVar22 != 0) {
          return iVar22;
        }
        goto LAB_00045a42;
      }
      local_98 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_98) + 2)) & 0xc000 | (ushort)local_38 & 0x3fff,(undefined2)local_98);
      local_120 = (uint)(*(byte *)(iVar22 + 0x23) & 7);
      if (local_128 != 0) {
        ((int (*)())FUN_0003e8ce)(&local_7c);
        bVar14 = ((byte)local_7c >> 3 & 1) * '\b';
        bVar6 = ((byte)local_7c & 7) << 4;
        bVar15 = ((byte)local_7c >> 3) << 7;
        (*(unsigned short *)((unsigned char *)&(local_7c) + 0)) =
             CONCAT11((byte)local_7c & 7 | bVar14 | bVar6 | bVar15,
                      (byte)local_7c & 7 | bVar14 | bVar6 | bVar15);
      }
    }
    if (local_120 - 5 < 3) {
      local_98 = local_98 & 0xf3ffffff | 0x4000000;
    }
    uVar13 = local_80;
    if (bVar24) {
      uVar12 = local_80 & 0xff1fffff;
      local_80 = uVar12 | 0x600000;
      uVar13 = local_80;
      (*(unsigned char *)((unsigned char *)&(local_80) + 1)) = (byte)(uVar12 >> 8);
      if ((char)(*(unsigned char *)((unsigned char *)&(local_80) + 1)) < '\0') {
        (*(unsigned char *)((unsigned char *)&(local_80) + 0)) = (byte)uVar12;
        bVar6 = (byte)local_80 >> 3;
        bVar7 = (byte)local_80 >> 7;
        bVar14 = (byte)local_80 & 0x77;
        bVar8 = (*(unsigned char *)((unsigned char *)&(local_80) + 1)) >> 3;
        bVar9 = (*(unsigned char *)((unsigned char *)&(local_80) + 1)) >> 7;
        bVar15 = (*(unsigned char *)((unsigned char *)&(local_80) + 1)) & 0x77;
        (*(unsigned short *)((unsigned char *)&(local_80) + 2)) = SUB42(uVar13,2);
        (*(unsigned short *)((unsigned char *)&(local_80) + 0)) =
             CONCAT11(bVar15 | (bVar8 & 1 ^ 1) << 3 | (bVar9 ^ 1) << 7,
                      bVar14 | (bVar6 & 1 ^ 1) << 3 | (bVar7 ^ 1) << 7);
        uVar13 = local_80;
      }
    }
    local_80 = uVar13;
    ((int (*)())FUN_0003f26e)(local_128 + 1);
  }
  else {
    if (bVar14 == 7) {
      if (local_15c == 0) {
        iVar22 = *param_1;
        iVar17 = *(int *)(iVar22 + 0x54);
        puVar23 = &local_98;
        for (iVar18 = 9; iVar18 != 0; iVar18 = iVar18 + -1) {
          *puVar23 = 0;
          puVar23 = puVar23 + 1;
        }
        local_98 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_98) + 2)),0x47);
        iVar17 = local_160 + iVar22 + iVar17 * 8;
        iVar22 = ((int (*)())FUN_0003ee9d)(&local_90,*(byte *)(iVar17 + 5) >> 3 & 1);
        if (iVar22 == 0) {
          iVar22 = ((int (*)())FUN_0003e8ce)(&local_80);
          if (iVar22 != 0) goto LAB_000462c5;
          if (((*(byte *)(param_1 + 5) & 4) == 0) ||
             (bVar14 = *(byte *)(iVar17 + 4), (bVar14 & 8) == 0)) {
            iVar22 = 1;
          }
          else {
            iVar22 = (bVar14 >> 4 & 3) + 1;
            if (iVar22 == 0) goto LAB_00045a4b;
          }
          iVar17 = 0;
          do {
            iVar18 = ((int (*)())FUN_0003f26e)(1);
            if (iVar18 != 0) goto LAB_000462c5;
            local_94 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_94) + 2)),(short)local_94 + 1);
            local_8c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_8c) + 2)),(short)local_8c + 1);
            iVar17 = iVar17 + 1;
          } while (iVar22 != iVar17);
          goto LAB_00045a4b;
        }
LAB_00046124:
        iVar22 = param_1[9];
LAB_0004612d:
        if (iVar22 != 0) {
          return iVar22;
        }
        goto LAB_00045a4b;
      }
      if (local_15c == 0x40) {
        iVar22 = ((int (*)())FUN_0003ee9d)(&local_34,
                              *(byte *)(local_160 + 5 + *param_1 + *(int *)(*param_1 + 0x54) * 8) >>
                              3 & 1);
        if (iVar22 == 0) {
          iVar22 = 0;
          do {
            iVar17 = ((int (*)())FUN_0003e8ce)((int)&local_50 + iVar22);
            if (iVar17 != 0) goto LAB_00046c65;
            iVar22 = iVar22 + 4;
          } while (iVar22 != 0xc);
          iVar22 = param_1[8];
          iVar17 = 0;
          do {
            (&local_74)[iVar17] = 0;
            *(byte *)((int)&local_74 + iVar17 * 4 + 2) =
                 *(byte *)((int)&local_74 + iVar17 * 4 + 2) & 0xc0 | 4;
            sVar20 = (short)iVar22 + (short)iVar17;
            *(short *)(&local_74 + iVar17) = sVar20;
            (&local_44)[iVar17] = 0;
            bVar14 = *(byte *)((int)&local_44 + iVar17 * 4 + 2);
            *(short *)(&local_44 + iVar17) = sVar20;
            *(byte *)((int)&local_44 + iVar17 * 4 + 2) = bVar14 & 0xc0 | 0x44;
            iVar17 = iVar17 + 1;
          } while (iVar17 != 3);
          iVar22 = ((int (*)())FUN_0003e71b)();
          uVar13 = local_44;
          if (iVar22 == 0) {
            *local_38 = 0x5b;
            local_38[1] = local_44;
            local_38[2] = local_34;
            local_38[3] = local_90;
            local_38[4] = local_48;
            local_38[5] = local_98;
            local_38[6] = local_50;
            iVar22 = ((int (*)())FUN_0003e71b)();
            uVar12 = local_40;
            if (iVar22 == 0) {
              *local_38 = 0x5b;
              local_38[1] = local_40;
              local_38[2] = local_34;
              local_38[3] = local_94;
              local_38[4] = local_4c;
              local_38[5] = local_98;
              local_38[6] = local_50;
              local_34 = local_34 | 0x100;
              iVar22 = ((int (*)())FUN_0003e71b)();
              uVar5 = local_70;
              uVar4 = local_74;
              if (iVar22 == 0) {
                *local_38 = 0x20;
                local_38[1] = uVar13;
                local_38[2] = local_34;
                local_38[3] = local_74;
                local_38[4] = local_70;
                local_34 = local_34 & 0xfffffeff;
                iVar22 = ((int (*)())FUN_0003e71b)();
                if (iVar22 != 0) {
LAB_000462c5:
                  iVar22 = param_1[9];
                  goto LAB_0004612d;
                }
                *local_38 = 3;
                local_38[1] = uVar12;
                local_38[2] = local_34;
                local_38[3] = uVar4;
                local_38[4] = uVar4;
                iVar22 = ((int (*)())FUN_0003e71b)();
                if (iVar22 == 0) {
                  *local_38 = 0x49;
                  local_38[1] = uVar13;
                  local_38[2] = local_34;
                  local_38[3] = uVar4;
                  local_38[4] = uVar4;
                  iVar22 = ((int (*)())FUN_0003e71b)();
                  if (iVar22 == 0) {
                    *local_38 = 0x49;
                    local_38[1] = uVar12;
                    local_38[2] = local_34;
                    local_38[3] = uVar4;
                    local_38[4] = uVar5;
                    uVar13 = local_74 | 0x400000;
                    iVar22 = ((int (*)())FUN_0003e71b)();
                    if (iVar22 != 0) {
LAB_00046c65:
                      iVar22 = param_1[9];
                      goto LAB_0004612d;
                    }
                    *local_38 = 0x23;
                    local_38[1] = local_3c;
                    local_38[2] = local_34;
                    local_38[3] = uVar13;
                    local_38[4] = 0x4555;
                    local_38[5] = uVar13;
                    local_38[6] = 0x4555;
                    local_70 = local_70 | 0x400000;
                    iVar22 = ((int (*)())FUN_0003e71b)();
                    if (iVar22 == 0) {
                      *local_38 = 0x40;
                      local_38[1] = local_30;
                      local_38[2] = local_34;
                      local_38[3] = local_74;
                      local_38[4] = local_6c;
                      local_38[5] = local_70;
                      local_38[6] = 0xba98;
                      goto LAB_00045a4b;
                    }
                    goto LAB_000462c5;
                  }
                }
              }
            }
          }
LAB_0004652c:
          iVar22 = param_1[9];
          goto LAB_0004612d;
        }
        goto LAB_00046124;
      }
      if (local_15c == 0x22) {
        iVar22 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
        iVar17 = iVar22 + local_160;
        cVar19 = (*(byte *)(iVar17 + 0x12) >> 1 & 1) + (*(byte *)(iVar17 + 0x1a) >> 1 & 1);
        if ((cVar19 == '\x01') &&
           (((*(byte *)(iVar17 + 0x12) & 0xc) == 0 || ((*(byte *)(iVar17 + 0x1a) & 0xc) == 0)))) {
          iVar22 = ((int (*)())FUN_0004538f)();
        }
        else {
          puVar23 = &local_74;
          for (iVar18 = 9; iVar18 != 0; iVar18 = iVar18 + -1) {
            *puVar23 = 0;
            puVar23 = puVar23 + 1;
          }
          local_74 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_74) + 2)),0x49);
          iVar22 = ((int (*)())FUN_0003ee9d)(&local_6c,*(byte *)(local_160 + 5 + iVar22) >> 3 & 1);
          if (iVar22 == 0) {
            iVar22 = ((int (*)())FUN_0003e8ce)(&local_5c);
            if (iVar22 == 0) {
              iVar22 = ((int (*)())FUN_0003e8ce)(&local_58);
              uVar12 = local_6c;
              uVar13 = local_70;
              if (iVar22 == 0) {
                if (cVar19 == '\0') {
                  iVar22 = ((int (*)())FUN_0003f26e)(2);
                  if (iVar22 != 0) {
LAB_00046f67:
                    iVar22 = param_1[9];
                    goto LAB_0004633f;
                  }
                }
                else if (cVar19 == '\x01') {
                  if ((*(byte *)(iVar17 + 0x12) & 2) == 0) {
                    local_74 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_74) + 2)),0x23);
                    (*(unsigned int *)((unsigned char *)&(local_70) + 0)) = CONCAT12(0x44,(short)param_1[8]);
                    local_70 = (uint)(uint3)local_70;
                    local_6c = 0;
                    local_104 = (byte)uVar12;
                    do {
                      iVar22 = 0;
                      bVar24 = (local_104 & 3) == 1;
                      while( true ) {
                        if (bVar24) {
                          if (iVar22 == 0) {
                            local_6c = CONCAT31((*(unsigned int *)((unsigned char *)&(local_6c) + 1)),1);
                          }
                          else if (iVar22 == 1) {
                            local_6c = CONCAT31((*(unsigned int *)((unsigned char *)&(local_6c) + 1)),4);
                          }
                          else if (iVar22 == 2) {
                            local_6c = CONCAT31((*(unsigned int *)((unsigned char *)&(local_6c) + 1)),0x10);
                          }
                          else {
                            local_6c = CONCAT31((*(unsigned int *)((unsigned char *)&(local_6c) + 1)),0x40);
                          }
                          iVar18 = ((int (*)())FUN_0003f26e)(2);
                          if (iVar18 != 0) goto LAB_00046f67;
                        }
                        iVar22 = iVar22 + 1;
                        local_64 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_64) + 2)),(short)local_64 + 1);
                        if ((int)(*(byte *)(iVar17 + 0x1a) >> 2 & 3) < iVar22) {
                          local_74 = 0x47;
                          (*(unsigned int *)((unsigned char *)&(local_68) + 0)) = CONCAT12(0x44,(short)param_1[8]);
                          local_68 = (uint)(uint3)local_68;
                          local_5c = 0x3210;
                          local_70 = uVar13;
                          local_6c = uVar12;
                          iVar22 = ((int (*)())FUN_0003f26e)(1);
                          if (iVar22 != 0) goto LAB_000463a1;
                          goto LAB_00045a4b;
                        }
                        if (iVar22 == 0) break;
                        if (iVar22 == 1) {
                          bVar24 = (local_104 & 0xc) == 4;
                        }
                        else if (iVar22 == 2) {
                          bVar24 = (local_104 & 0x30) == 0x10;
                        }
                        else {
                          bVar24 = (local_104 & 0xc0) == 0x40;
                        }
                      }
                    } while( true );
                  }
                  bVar14 = *(byte *)(iVar17 + 0x12) >> 2 & 3;
                  local_98 = local_74;
                  local_8c = local_68;
                  local_88 = local_64;
                  local_84 = local_60;
                  local_80 = local_5c;
                  local_78 = local_54;
                  iVar22 = param_1[8];
                  (*(unsigned int *)((unsigned char *)&(local_94) + 0)) = CONCAT12(0x44,(short)iVar22);
                  local_94 = (uint)(uint3)local_94;
                  local_90 = 0x55;
                  bVar15 = ((byte)local_58 >> 3 & 1) * '\b' | (byte)local_58 & 7 |
                           ((byte)local_58 & 7) << 4 | ((byte)local_58 >> 3) << 7;
                  (*(unsigned short *)((unsigned char *)&(local_7c) + 2)) = (undefined2)((uint)local_58 >> 0x10);
                  (*(unsigned short *)((unsigned char *)&(local_7c) + 0)) = CONCAT11(bVar15,bVar15);
                  iVar17 = ((int (*)())FUN_0003f26e)(2);
                  if (iVar17 == 0) {
                    local_98 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_98) + 2)),0x40);
                    (*(unsigned int *)((unsigned char *)&(local_84) + 0)) = CONCAT12(0x44,(short)iVar22);
                    local_84 = (uint)(uint3)local_84;
                    local_78 = 0x3210;
                    local_8c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_8c) + 2)),(short)local_8c + 1);
                    if (bVar14 == 1) {
                      local_94 = local_70;
                      local_90 = local_6c;
                    }
                    bVar6 = (byte)local_58 >> 4 & 7;
                    bVar15 = ((char)(byte)local_58 >> 7) * -8;
                    bVar7 = ((char)(byte)local_58 >> 7) * -0x80;
                    (*(unsigned short *)((unsigned char *)&(local_7c) + 0)) =
                         CONCAT11(bVar6 | bVar15 & 0xf | bVar6 << 4 | bVar7,
                                  bVar6 | bVar15 & 0xf | bVar6 << 4 | bVar7);
                    iVar22 = ((int (*)())FUN_0003f26e)(3);
                    if ((iVar22 == 0) && (1 < bVar14)) {
                      local_8c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_8c) + 2)),(short)local_8c + 1);
                      if (bVar14 == 2) {
                        local_94 = local_70;
                        local_90 = local_6c;
                      }
                      bVar15 = ((*(unsigned char *)((unsigned char *)&(local_58) + 1)) >> 3 & 1) * '\b' | (*(unsigned char *)((unsigned char *)&(local_58) + 1)) & 7 |
                               ((*(unsigned char *)((unsigned char *)&(local_58) + 1)) & 7) << 4 | ((*(unsigned char *)((unsigned char *)&(local_58) + 1)) >> 3) << 7;
                      (*(unsigned short *)((unsigned char *)&(local_7c) + 0)) = CONCAT11(bVar15,bVar15);
                      iVar22 = ((int (*)())FUN_0003f26e)(3);
                      if ((iVar22 == 0) && (bVar14 == 3)) {
                        local_8c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_8c) + 2)),(short)local_8c + 1);
                        local_94 = local_70;
                        local_90 = local_6c;
                        bVar15 = (*(unsigned char *)((unsigned char *)&(local_58) + 1)) >> 4 & 7;
                        bVar14 = ((char)(*(unsigned char *)((unsigned char *)&(local_58) + 1)) >> 7) * -8;
                        bVar6 = ((char)(*(unsigned char *)((unsigned char *)&(local_58) + 1)) >> 7) * -0x80;
                        (*(unsigned short *)((unsigned char *)&(local_7c) + 0)) =
                             CONCAT11(bVar15 | bVar14 & 0xf | bVar15 << 4 | bVar6,
                                      bVar15 | bVar14 & 0xf | bVar15 << 4 | bVar6);
                        ((int (*)())FUN_0003f26e)(3);
                      }
                    }
                  }
                }
                else {
                  iVar22 = (*(byte *)(iVar17 + 0x12) >> 2 & 3) + 1;
                  uVar21 = (undefined2)param_1[8];
                  (*(unsigned int *)((unsigned char *)&(local_70) + 0)) = CONCAT12(0x44,uVar21);
                  local_70 = (uint)(uint3)local_70;
                  local_6c = 0x55;
                  local_18c = param_1[8] + iVar22;
                  param_1[8] = local_18c;
                  if (iVar22 != 0) {
                    local_f0 = 0;
                    while( true ) {
                      bVar14 = *(byte *)(iVar17 + 0x12) >> 2 & 3;
                      local_98 = local_74;
                      local_8c = local_68;
                      local_88 = local_64;
                      local_84 = local_60;
                      local_80 = local_5c;
                      local_78 = local_54;
                      (*(unsigned int *)((unsigned char *)&(local_94) + 0)) = CONCAT12(0x44,(short)local_18c);
                      local_94 = (uint)(uint3)local_94;
                      local_90 = 0x55;
                      bVar15 = ((byte)local_58 >> 3 & 1) * '\b' | (byte)local_58 & 7 |
                               ((byte)local_58 & 7) << 4 | ((byte)local_58 >> 3) << 7;
                      (*(unsigned short *)((unsigned char *)&(local_7c) + 2)) = (undefined2)((uint)local_58 >> 0x10);
                      (*(unsigned short *)((unsigned char *)&(local_7c) + 0)) = CONCAT11(bVar15,bVar15);
                      iVar18 = ((int (*)())FUN_0003f26e)(2);
                      if (iVar18 == 0) {
                        local_98 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_98) + 2)),0x40);
                        (*(unsigned int *)((unsigned char *)&(local_84) + 0)) = CONCAT12(0x44,(short)local_18c);
                        local_84 = (uint)(uint3)local_84;
                        local_78 = 0x3210;
                        local_8c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_8c) + 2)),(short)local_8c + 1);
                        if (bVar14 == 1) {
                          local_94 = local_70;
                          local_90 = local_6c;
                        }
                        bVar6 = (byte)local_58 >> 4 & 7;
                        bVar15 = ((char)(byte)local_58 >> 7) * -8;
                        bVar7 = ((char)(byte)local_58 >> 7) * -0x80;
                        (*(unsigned short *)((unsigned char *)&(local_7c) + 0)) =
                             CONCAT11(bVar6 | bVar15 & 0xf | bVar6 << 4 | bVar7,
                                      bVar6 | bVar15 & 0xf | bVar6 << 4 | bVar7);
                        iVar18 = ((int (*)())FUN_0003f26e)(3);
                        if ((iVar18 == 0) && (1 < bVar14)) {
                          local_8c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_8c) + 2)),(short)local_8c + 1);
                          if (bVar14 == 2) {
                            local_94 = local_70;
                            local_90 = local_6c;
                          }
                          bVar15 = ((*(unsigned char *)((unsigned char *)&(local_58) + 1)) >> 3 & 1) * '\b' | (*(unsigned char *)((unsigned char *)&(local_58) + 1)) & 7 |
                                   ((*(unsigned char *)((unsigned char *)&(local_58) + 1)) & 7) << 4 | ((*(unsigned char *)((unsigned char *)&(local_58) + 1)) >> 3) << 7;
                          (*(unsigned short *)((unsigned char *)&(local_7c) + 0)) = CONCAT11(bVar15,bVar15);
                          iVar18 = ((int (*)())FUN_0003f26e)(3);
                          if ((iVar18 == 0) && (bVar14 == 3)) {
                            local_8c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_8c) + 2)),(short)local_8c + 1);
                            local_94 = local_70;
                            local_90 = local_6c;
                            bVar15 = (*(unsigned char *)((unsigned char *)&(local_58) + 1)) >> 4 & 7;
                            bVar14 = ((char)(*(unsigned char *)((unsigned char *)&(local_58) + 1)) >> 7) * -8;
                            bVar6 = ((char)(*(unsigned char *)((unsigned char *)&(local_58) + 1)) >> 7) * -0x80;
                            (*(unsigned short *)((unsigned char *)&(local_7c) + 0)) =
                                 CONCAT11(bVar15 | bVar14 & 0xf | bVar15 << 4 | bVar6,
                                          bVar15 | bVar14 & 0xf | bVar15 << 4 | bVar6);
                            ((int (*)())FUN_0003f26e)(3);
                          }
                        }
                      }
                      local_f0 = local_f0 + 1;
                      local_70 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_70) + 2)),(short)local_70 + 1);
                      local_64 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_64) + 2)),(short)local_64 + 1);
                      if (iVar22 == local_f0) break;
                      local_18c = param_1[8];
                    }
                    local_18c = param_1[8];
                  }
                  param_1[8] = local_18c - iVar22;
                  local_74 = 0x47;
                  (*(unsigned int *)((unsigned char *)&(local_68) + 0)) = CONCAT12(0x44,uVar21);
                  local_68 = (uint)(uint3)local_68;
                  local_5c = 0x3210;
                  local_70 = uVar13;
                  local_6c = uVar12;
                  if (iVar22 != 0) {
                    iVar17 = 0;
                    do {
                      ((int (*)())FUN_0003f26e)(1);
                      iVar17 = iVar17 + 1;
                      local_70 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_70) + 2)),(short)local_70 + 1);
                      local_68 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_68) + 2)),(short)local_68 + 1);
                    } while (iVar22 != iVar17);
                  }
                }
                goto LAB_00045a4b;
              }
              iVar22 = param_1[9];
            }
            else {
              iVar22 = param_1[9];
            }
          }
          else {
LAB_000463a1:
            iVar22 = param_1[9];
          }
        }
LAB_0004633f:
        if (iVar22 != 0) {
LAB_00045f1c:
          return param_1[9];
        }
        goto LAB_00045a4b;
      }
      if (((local_134 - 0x1f < 2) || (local_15c == 0x23)) || (local_15c == 0x3a)) {
        iVar22 = ((int (*)())FUN_0004538f)();
        if (iVar22 != 0) goto LAB_00046153;
        goto LAB_00045a42;
      }
      if (local_15c == 0x6c) {
        iVar22 = *param_1;
        iVar17 = *(int *)(iVar22 + 0x54);
        puVar23 = &local_98;
        for (iVar18 = 9; iVar18 != 0; iVar18 = iVar18 + -1) {
          *puVar23 = 0;
          puVar23 = puVar23 + 1;
        }
        iVar18 = ((int (*)())FUN_0003e511)();
        if (iVar18 == 1) {
          local_98 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_98) + 2)),99);
        }
        else if (iVar18 == 2) {
          local_98 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_98) + 2)),0x56) & 0xc000ffff;
        }
        else {
          local_98 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_98) + 2)),0x47);
        }
        iVar22 = ((int (*)())FUN_0003ee9d)(&local_90,*(byte *)(local_160 + 5 + iVar22 + iVar17 * 8) >> 3 & 1);
        if (iVar22 != 0) goto LAB_000462c5;
        iVar22 = ((int (*)())FUN_0003e8ce)(&local_80);
        if (iVar22 != 0) goto LAB_0004652c;
        if (iVar18 == 2) {
          local_88 = CONCAT13((*(unsigned char *)((unsigned char *)&(local_88) + 3)),CONCAT12((*(unsigned char *)((unsigned char *)&(local_88) + 2)),(short)param_1[8])) &
                     0xffc0ffff | 0x440000;
          local_7c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_7c) + 2)),0x4444);
          uVar10 = 2;
        }
        else {
          uVar10 = 1;
        }
LAB_00046822:
        iVar22 = ((int (*)())FUN_0003f26e)(uVar10);
        if (iVar22 != 0) goto LAB_00046124;
        goto LAB_00045a4b;
      }
      if (local_15c == 8) {
        iVar22 = ((int (*)())FUN_000451cf)();
        if (iVar22 != 0) goto LAB_00046153;
        goto LAB_00045a4b;
      }
      if (local_15c == 9) {
        iVar22 = ((int (*)())FUN_00044c65)();
        if (iVar22 == 0) goto LAB_00045a4b;
        goto LAB_00045814;
      }
      if (local_15c == 10) {
        puVar23 = &local_98;
        for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
          *puVar23 = 0;
          puVar23 = puVar23 + 1;
        }
        local_98 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_98) + 2)),0x5b);
        iVar22 = ((int (*)())FUN_0003ee9d)(&local_90,1);
        if (iVar22 != 0) goto LAB_0004652c;
        local_8c = CONCAT13((*(unsigned char *)((unsigned char *)&(local_8c) + 3)),CONCAT12((*(unsigned char *)((unsigned char *)&(local_8c) + 2)),(short)param_1[8])) & 0xffc0ffff
                   | 0x440000;
        local_80 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_80) + 2)),0x5555);
        iVar22 = ((int (*)())FUN_0003e8ce)(&local_7c);
        if (iVar22 == 0) {
          uVar10 = 2;
          goto LAB_00046822;
        }
        iVar22 = param_1[9];
        goto LAB_0004612d;
      }
      if (local_15c == 0x26) {
        puVar23 = &local_98;
        for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
          *puVar23 = 0;
          puVar23 = puVar23 + 1;
        }
        local_98 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_98) + 2)),0x5b);
        local_94 = CONCAT13((*(unsigned char *)((unsigned char *)&(local_94) + 3)),CONCAT12((*(unsigned char *)((unsigned char *)&(local_94) + 2)),(short)param_1[8])) & 0xffc0ffff
                   | 0x440000;
        local_90 = CONCAT31((*(unsigned int *)((unsigned char *)&(local_90) + 1)),0x55);
        iVar22 = ((int (*)())FUN_0003e8ce)(&local_80);
        if (iVar22 != 0) goto LAB_0004652c;
        iVar22 = ((int (*)())FUN_0003e8ce)(&local_7c);
        if (iVar22 == 0) {
          iVar22 = ((int (*)())FUN_0003f26e)(2);
          if (iVar22 != 0) goto LAB_00046124;
          local_98 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_98) + 2)),1);
          iVar22 = ((int (*)())FUN_0003ee9d)(&local_90,1);
          if (iVar22 != 0) goto LAB_000462c5;
          local_8c = (uint)CONCAT12(0x44,(short)param_1[8]);
          local_80 = 0x3210;
          iVar22 = ((int (*)())FUN_0003f26e)(1);
          if (iVar22 == 0) goto LAB_00045a4b;
          iVar22 = param_1[9];
        }
        else {
          iVar22 = param_1[9];
        }
        goto LAB_0004612d;
      }
      if (local_15c == 0x39) {
        iVar22 = ((int (*)())FUN_000442df)();
        if (iVar22 != 0) goto LAB_0004695b;
        goto LAB_00045a4b;
      }
      if (local_15c == 0x6d) {
        iVar22 = ((int (*)())FUN_0004373a)();
        goto LAB_0004633f;
      }
      if ((local_15c == 0x31) || (local_15c == 0x36)) {
        iVar22 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
        if ((*(byte *)(param_1 + 5) & 4) == 0) {
          bVar24 = false;
          bVar6 = 0;
          bVar14 = *(byte *)(local_160 + iVar22 + 0x12);
          bVar15 = *(byte *)(local_160 + iVar22 + 0x1a);
        }
        else {
          bVar14 = *(byte *)(local_160 + iVar22 + 0x12);
          bVar6 = bVar14 >> 1 & 1;
          bVar15 = *(byte *)(local_160 + iVar22 + 0x1a);
          bVar24 = (bVar15 & 2) != 0;
        }
        puVar16 = (ushort *)(iVar22 + local_160);
        uVar2 = puVar16[2];
        uVar12 = (bVar14 >> 2 & 3) + 1;
        uVar13 = (bVar15 >> 2 & 3) + 1;
        puVar23 = &local_98;
        for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
          *puVar23 = 0;
          puVar23 = puVar23 + 1;
        }
        local_98 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_98) + 2)) & 0xc000 | (ushort)((*puVar16 & 0x3fc0) == 0xc40),0x56);
        iVar22 = ((int (*)())FUN_0003e8ce)(&local_80);
        if (iVar22 == 0) {
          iVar22 = ((int (*)())FUN_0003e8ce)(&local_7c);
          if (iVar22 == 0) {
            if ((byte)(((byte)uVar2 >> 4 & 3) + 1) < 2) {
              (*(unsigned int *)((unsigned char *)&(local_94) + 0)) = CONCAT12(0x44,(short)param_1[8]);
              local_94 = (uint)(uint3)local_94;
              local_90 = 0x55;
              iVar22 = ((int (*)())FUN_0003f26e)(2);
              if (iVar22 != 0) goto LAB_00046711;
              if (uVar13 <= uVar12) {
                uVar13 = uVar12;
              }
              if (((bVar6 != 0) || (bVar24)) && (1 < uVar13)) {
                sVar20 = (short)param_1[8];
                local_94 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_94) + 2)),sVar20 + 1);
                puVar23 = &local_74;
                for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
                  *puVar23 = 0;
                  puVar23 = puVar23 + 1;
                }
                uVar21 = 0x49;
                if ((*puVar16 & 0x3fc0) != 0xc40) {
                  uVar21 = 3;
                }
                local_74 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_74) + 2)),uVar21);
                (*(unsigned int *)((unsigned char *)&(local_70) + 0)) = CONCAT12(0x44,sVar20);
                local_70 = (uint)(uint3)local_70;
                local_6c = 0x55;
                (*(unsigned int *)((unsigned char *)&(local_68) + 0)) = CONCAT12(0x44,sVar20);
                local_68 = (uint)(uint3)local_68;
                local_5c = 0x3210;
                local_64 = (uint)CONCAT12(0x44,sVar20 + 1);
                local_58 = 0x3210;
                uVar12 = 1;
                do {
                  local_8c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_8c) + 2)),((short)local_8c + 1) - (ushort)(bVar6 == 0));
                  local_88 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_88) + 2)),((short)local_88 + 1) - (ushort)!bVar24);
                  iVar22 = ((int (*)())FUN_0003f26e)(2);
                  if (iVar22 != 0) {
                    iVar22 = param_1[9];
                    goto LAB_0004671a;
                  }
                  iVar22 = ((int (*)())FUN_0003f26e)(2);
                  if (iVar22 != 0) goto LAB_00046711;
                  uVar12 = uVar12 + 1;
                } while (uVar13 != uVar12);
              }
              if ((*puVar16 & 0x3fc0) == 0xc40) {
                iVar22 = ((int (*)())FUN_00044c65)();
              }
              else {
                puVar23 = &local_74;
                for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
                  *puVar23 = 0;
                  puVar23 = puVar23 + 1;
                }
                local_74 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_74) + 2)),0x23);
                iVar22 = ((int (*)())FUN_0003ee9d)(&local_6c,1);
                if (iVar22 == 0) {
                  (*(unsigned int *)((unsigned char *)&(local_68) + 0)) = CONCAT12(0x44,(short)param_1[8]);
                  local_68 = (uint)(uint3)local_68;
                  local_5c = 0x3210;
                  local_64 = CONCAT13((*(unsigned char *)((unsigned char *)&(local_64) + 3)),CONCAT12((*(unsigned char *)((unsigned char *)&(local_64) + 2)),(short)param_1[8])) &
                             0xffc0ffff | 0x440000;
                  local_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_58) + 2)),0x5555);
                  iVar22 = ((int (*)())FUN_0003f26e)(2);
                  if (iVar22 == 0) goto LAB_00045a42;
                  iVar22 = param_1[9];
                }
                else {
                  iVar22 = param_1[9];
                }
              }
            }
            else {
              ((int (*)())FUN_0003ee9d)(&local_90,0);
              ((int (*)())FUN_0003f26e)(2);
              iVar22 = param_1[9];
            }
          }
          else {
            iVar22 = param_1[9];
          }
        }
        else {
LAB_00046711:
          iVar22 = param_1[9];
        }
LAB_0004671a:
        if (iVar22 != 0) goto LAB_00045f1c;
        goto LAB_00045a42;
      }
      if (local_15c != 0x4d) goto LAB_00045803;
      goto LAB_00045ac8;
    }
    if (bVar14 == 5) {
      puVar23 = &local_74;
      for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
        *puVar23 = 0;
        puVar23 = puVar23 + 1;
      }
      iVar22 = local_134 * 0x10;
      local_74 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_74) + 2)) & 0xc000 | *(ushort *)(&DAT_001ed804 + iVar22) & 0x1fff,
                          (short)(*(uint *)(&DAT_001ed800 + iVar22) >> 0xf));
      if (((DAT_001ed80c)[iVar22] & 2) == 0) {
        if (((*(byte *)((int)local_a0 + 5) & 8) == 0) && (((DAT_001ed80c)[iVar22] & 1) == 0)) {
          local_1a0 = 0;
        }
        else {
          local_1a0 = 1;
        }
        ((int (*)())FUN_0003ee9d)(&local_6c,local_1a0);
      }
      if (uVar11 != 0) {
        local_bc = 0;
        local_ac = &local_68;
        do {
          ((int (*)())FUN_0003e8ce)(local_ac + 3);
          local_bc = local_bc + 1;
          local_ac = local_ac + 1;
        } while (uVar11 != local_bc);
      }
      (**(code **)(local_134 * 0x10 + 0x1ed808))(param_1,local_138,&local_74);
      iVar22 = param_1[9];
      goto joined_r0x000460a8;
    }
    iVar22 = local_134 * 0x10;
    uVar13 = *(uint *)(&DAT_001ed800 + iVar22);
    uVar2 = *(ushort *)(&DAT_001ed804 + iVar22);
    uVar12 = uVar11;
    if (bVar14 == 4) {
      uVar12 = uVar11 - 1;
    }
    iVar17 = ((int (*)())FUN_0003e71b)();
    if (iVar17 != 0) goto LAB_00045f1c;
    *local_38 = uVar13 >> 0xf & 0xffff | (uint)(uVar2 & 0x1fff) << 0x10;
    if (((byte)(DAT_001ed801)[iVar22] >> 3 & 0xf) == 3) {
      if (((byte)(DAT_001ed801)[local_134 * 0x10] >> 3 & 0xf) != 4) goto LAB_00045994;
LAB_00045eea:
      iVar22 = ((int (*)())FUN_0003ec89)(&local_2c,(byte *)((int)puVar1 + local_160 + 0x18));
      if (iVar22 != 0) goto LAB_00045f1c;
    }
    else {
      if (((*(byte *)((int)local_a0 + 5) & 8) == 0) && (((DAT_001ed80c)[iVar22] & 1) == 0)) {
        uVar10 = 0;
      }
      else {
        uVar10 = 1;
      }
      iVar22 = ((int (*)())FUN_0003ee9d)(&local_24,uVar10);
      if (iVar22 != 0) goto LAB_00045f1c;
      local_38[1] = local_20;
      local_38[2] = local_24;
      if (((byte)(DAT_001ed801)[local_134 * 0x10] >> 3 & 0xf) == 4) goto LAB_00045eea;
LAB_00045994:
      iVar22 = ((int (*)())FUN_0003e8ce)(&local_2c);
      if (iVar22 != 0) {
LAB_00046153:
        return param_1[9];
      }
    }
    local_184 = &local_2c;
    bVar14 = (byte)(DAT_001ed801)[local_134 * 0x10] >> 3 & 0xf;
    if (bVar14 == 6) {
      local_2c = local_2c & 0xffff0fff | 0x5000;
LAB_000459eb:
      local_38[3] = local_28;
      local_38[4] = local_2c;
    }
    else {
      if (bVar14 != 3) goto LAB_000459eb;
      local_38[1] = local_28;
      local_38[2] = local_2c;
    }
    if (1 < (int)uVar12) {
      iVar22 = ((int (*)())FUN_0003e8ce)(local_184);
      if (iVar22 == 0) {
        local_38[5] = local_28;
        local_38[6] = local_2c;
        if (2 < (int)uVar12) {
          iVar22 = ((int (*)())FUN_0003e8ce)(local_184);
          if (iVar22 != 0) {
LAB_0004695b:
            return param_1[9];
          }
          local_38[7] = local_28;
          local_38[8] = local_2c;
        }
        goto LAB_00045a42;
      }
      goto LAB_00045814;
    }
  }
LAB_00045a42:
  if (local_15c != 0x4d) {
LAB_00045a4b:
    if (((((byte)(DAT_001ed801)[local_134 * 0x10] >> 3 & 0xf) != 3) &&
        ((*(byte *)(param_1 + 5) & 4) != 0)) &&
       (((((bVar14 = *(byte *)((int)puVar1 + local_160 + 10), (bVar14 & 4) != 0 &&
           ((bVar14 & 0xc0) != 0)) ||
          (((bVar14 & 2) != 0 && ((*(byte *)((int)puVar1 + local_160 + 0xb) & 3) != 1)))) ||
         (((bVar14 & 1) != 0 && ((*(byte *)((int)puVar1 + local_160 + 0xb) & 0xc) != 8)))) ||
        (((char)*(byte *)((int)puVar1 + local_160 + 9) < '\0' &&
         ((*(byte *)((int)puVar1 + local_160 + 0xb) & 0x30) != 0x30)))))) {
      ((int (*)())FUN_0003f06b)();
    }
  }
LAB_00045ac8:
  local_138 = local_138 + uVar11 + 2;
  local_13c = local_13c + 1;
  if (iVar3 == local_13c) {
    return 0;
  }
  local_160 = local_138 * 8;
  local_a0 = puVar1 + local_138 * 4;
  local_15c = (byte)(*local_a0 >> 6);
  local_134 = (uint)local_15c;
  bVar14 = (byte)(DAT_001ed801)[local_134 * 0x10] >> 3 & 0xf;
  if ((bVar14 == 0) || ((DAT_001edf10 & ((DAT_001ed80c)[local_134 * 0x10] & 0xf)) != 0))
  goto LAB_00045803;
  goto LAB_00045b56;
}

/* FUN_00047b03 @ 0x47b03 (6268 bytes) */
int FUN_00047b03(param_1)
  int *param_1;
{
  short sVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  void *pvVar5;
  dword *pdVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  dword *pdVar12;
  uint *puVar13;
  undefined2 uVar14;
  int iVar15;
  uint uVar16;
  dword *pdVar17;
  short sVar18;
  int iVar19;
  uint uVar20;
  int *piVar21;
  byte *pbVar22;
  dword *local_d0;
  int local_c0;
  dword local_b8;
  dword local_b0;
  dword local_ac;
  undefined4 *local_a4;
  int local_90;
  uint local_84;
  int local_70;
  int local_6c;
  dword *local_68;
  dword *local_64;
  int local_60;
  uint local_5c;
  undefined4 local_58;
  dword local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  dword local_44 [13];
  
  piVar21 = (int *)*param_1;
  if (piVar21 == (int *)0x0) {
    if (param_1[9] == 0) {
      param_1[9] = 2;
    }
    goto LAB_00048395;
  }
  param_1[8] = piVar21[4] + piVar21[0xc] + 1;
  iVar15 = *piVar21;
  if ((iVar15 != 0x8804) && (iVar15 != 0x8b30)) {
    if (param_1[9] == 0) {
      param_1[9] = 3;
    }
    goto LAB_00047b4e;
  }
  *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) & 0xfb | (iVar15 - 0x8b30U < 2) << 2;
  piVar21 = param_1 + 10;
  uVar16 = param_1[0xc];
  iVar15 = param_1[0xb];
  if (uVar16 < iVar15 + 2U) {
    if (uVar16 == 0) {
      uVar16 = 0x10;
      goto LAB_00047b9d;
    }
    do {
      uVar16 = uVar16 * 2;
LAB_00047b9d: ;
    } while (uVar16 < iVar15 + 2U);
    if ((void *)*piVar21 == (void *)0x0) {
      pvVar5 = _malloc(uVar16 * 4);
      if (pvVar5 != (void *)0x0) {
        *piVar21 = (int)pvVar5;
        goto LAB_00047bd4;
      }
    }
    else {
      pvVar5 = _realloc((void *)*piVar21,uVar16 * 4);
      if (pvVar5 != (void *)0x0) {
        *piVar21 = (int)pvVar5;
LAB_00047bd4:
        param_1[0xc] = uVar16;
        iVar15 = param_1[0xb];
        goto LAB_00047be0;
      }
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) {
      return param_1[9];
    }
    local_a4 = (undefined4 *)0x0;
    pdVar6 = &MACH_HEADER.cputype;
  }
  else {
LAB_00047be0:
    local_a4 = (undefined4 *)(*piVar21 + iVar15 * 4);
    param_1[0xb] = iVar15 + 2;
    pdVar6 = local_a4 + 1;
  }
  *local_a4 = 1;
  *pdVar6 = (dword)((unsigned char *)0x00010200);
  local_c0 = *param_1;
  iVar15 = local_c0 + *(int *)(local_c0 + 0x34) * 8;
  if (0 < *(int *)(local_c0 + 0x30)) {
    iVar19 = 0;
    do {
      if ((*(byte *)(iVar15 + 1) >> 4 == 4) && ((*(byte *)(iVar15 + 3) & 0x70) != 0)) {
        *(byte *)(param_1[0xd] + 0x21) = *(byte *)(param_1[0xd] + 0x21) | 2;
        local_c0 = *param_1;
        break;
      }
      iVar19 = iVar19 + 1;
      iVar15 = iVar15 + 8;
    } while (*(int *)(local_c0 + 0x30) != iVar19);
  }
  iVar19 = *(int *)(local_c0 + 0x48);
  iVar15 = local_c0 + *(int *)(local_c0 + 0x4c) * 8;
  if (0 < iVar19) {
    iVar9 = 0;
    do {
      switch(*(undefined1 *)(iVar15 + 3)) {
      case 0:
        if (param_1[9] == 0) {
          param_1[9] = 3;
        }
        iVar15 = param_1[9];
        goto code_r0x00047ec5;
      case 1:
        *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) & 0xe7 | 0x10;
        break;
      case 2:
        *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) | 0x18;
        break;
      case 3:
        *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) & 0xe7 | 8;
        break;
      case 8:
      case 10:
        if (param_1[9] == 0) {
          param_1[9] = 3;
        }
        iVar15 = param_1[9];
code_r0x00047ec5:
        if (iVar15 != 0) {
          return iVar15;
        }
        goto LAB_00047ca0;
      }
      iVar9 = iVar9 + 1;
      iVar15 = iVar15 + 8;
    } while (iVar19 != iVar9);
  }
LAB_00047ca0:
  iVar15 = *(int *)(local_c0 + 0x20);
  local_c0 = local_c0 + *(int *)(local_c0 + 0x24) * 8;
  uVar11 = param_1[0xc];
  iVar19 = param_1[0xb];
  uVar16 = iVar15 * 2 + iVar19;
  if (uVar11 < uVar16) {
    if (uVar11 == 0) {
      uVar11 = 0x10;
      uVar7 = 0x10;
      if (0x10 < uVar16) goto LAB_00047ceb;
    }
    else {
LAB_00047ceb:
      do {
        uVar11 = uVar11 * 2;
        uVar7 = uVar11;
      } while (uVar11 < uVar16);
    }
    if ((void *)*piVar21 == (void *)0x0) {
      pvVar5 = _malloc(uVar7 * 4);
    }
    else {
      pvVar5 = _realloc((void *)*piVar21,uVar7 * 4);
    }
    if (pvVar5 != (void *)0x0) {
      *piVar21 = (int)pvVar5;
      param_1[0xc] = uVar7;
      iVar19 = param_1[0xb];
      goto LAB_00047d32;
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) goto LAB_00048395;
    puVar8 = (undefined4 *)0x0;
  }
  else {
LAB_00047d32:
    puVar8 = (undefined4 *)(*piVar21 + iVar19 * 4);
    param_1[0xb] = iVar15 * 2 + iVar19;
  }
  if (iVar15 < 1) {
LAB_00047df1:
    if ((*(byte *)(param_1 + 5) & 0x18) != 0) {
      uVar16 = param_1[0xc];
      iVar15 = param_1[0xb];
      if (uVar16 < iVar15 + 2U) {
        if (uVar16 != 0) goto LAB_00048497;
        for (uVar16 = 0x10; uVar16 < iVar15 + 2U; uVar16 = uVar16 * 2) {
LAB_00048497: ;
        }
        if ((void *)*piVar21 == (void *)0x0) {
          pvVar5 = _malloc(uVar16 * 4);
        }
        else {
          pvVar5 = _realloc((void *)*piVar21,uVar16 * 4);
        }
        if (pvVar5 != (void *)0x0) {
          *piVar21 = (int)pvVar5;
          param_1[0xc] = uVar16;
          iVar15 = param_1[0xb];
          goto LAB_00047e11;
        }
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        if (param_1[9] != 0) goto LAB_00048395;
      }
      else {
LAB_00047e11:
        puVar8 = (undefined4 *)(*piVar21 + iVar15 * 4);
        param_1[0xb] = iVar15 + 2;
      }
      *puVar8 = 0x1ff0016;
      puVar8[1] = 0x100000;
    }
  }
  else {
    local_90 = 0;
    bVar2 = false;
    do {
      bVar3 = *(byte *)(local_c0 + 1) >> 4;
      if (bVar3 == 1) {
        *puVar8 = 0x3ff0016;
code_r0x00047dc5:
        uVar10 = 0x160000;
      }
      else {
        *puVar8 = 0x1ff0016;
        switch(bVar3) {
        default:
          if (param_1[9] == 0) {
            param_1[9] = 3;
          }
          if (param_1[9] == 0) goto LAB_00047e2f;
          goto LAB_00048395;
        case 1:
          goto code_r0x00047dc5;
        case 2:
          uVar10 = 0x120000;
          break;
        case 3:
          uVar10 = 0x130000;
          break;
        case 5:
          uVar10 = 0x100000;
          bVar2 = true;
          break;
        case 7:
          uVar10 = CONCAT22(0x11,(ushort)(*(byte *)(local_c0 + 3) >> 3));
        }
      }
      puVar8[1] = uVar10;
      puVar8 = puVar8 + 2;
      local_90 = local_90 + 1;
      local_c0 = local_c0 + 8;
    } while (iVar15 != local_90);
    if (!bVar2) goto LAB_00047df1;
  }
LAB_00047e2f:
  uVar16 = param_1[1];
  uVar11 = param_1[2];
  iVar19 = 0;
  iVar15 = 0;
LAB_00047e51:
  do {
    iVar9 = iVar15;
    switch(uVar16 & 0xf) {
    case 0:
      (&local_5c)[iVar19] = iVar9 << 0x10 | 0xc000019;
      iVar19 = iVar19 + 1;
      uVar16 = uVar16 >> 4 | uVar11 << 0x1c;
      uVar11 = uVar11 >> 4;
      iVar15 = iVar9 + 1;
      if (iVar9 + 1 == 0x10) goto LAB_00047f02;
      goto LAB_00047e51;
    case 1:
      (&local_5c)[iVar19] = iVar9 << 0x10 | 0xb000019;
      iVar19 = iVar19 + 1;
      break;
    case 2:
      (&local_5c)[iVar19] = iVar9 << 0x10 | 0x12000019;
      iVar19 = iVar19 + 1;
      break;
    case 3:
      (&local_5c)[iVar19] = iVar9 << 0x10 | 0xa000019;
      iVar19 = iVar19 + 1;
      break;
    case 4:
      (&local_5c)[iVar19] = iVar9 << 0x10 | 0x9000019;
      iVar19 = iVar19 + 1;
    }
    uVar16 = uVar16 >> 4 | uVar11 << 0x1c;
    uVar11 = uVar11 >> 4;
    iVar15 = iVar9 + 1;
  } while (iVar9 + 1 != 0x10);
LAB_00047f02:
  uVar16 = param_1[0xc];
  iVar15 = param_1[0xb];
  if (uVar16 < (uint)(iVar19 + iVar15)) {
    if (uVar16 != 0) goto LAB_00047f1f;
    uVar16 = 0x10;
    uVar11 = iVar9 + 1;
    while (uVar11 < (uint)(iVar19 + iVar15)) {
LAB_00047f1f:
      uVar16 = uVar16 * 2;
      uVar11 = uVar16;
    }
    if ((void *)*piVar21 == (void *)0x0) {
      pvVar5 = _malloc(uVar11 * 4);
    }
    else {
      pvVar5 = _realloc((void *)*piVar21,uVar11 * 4);
    }
    if (pvVar5 != (void *)0x0) {
      *piVar21 = (int)pvVar5;
      param_1[0xc] = uVar11;
      iVar15 = param_1[0xb];
      goto LAB_00047f66;
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) {
      return param_1[9];
    }
    iVar9 = 0;
  }
  else {
LAB_00047f66:
    iVar9 = *piVar21 + iVar15 * 4;
    param_1[0xb] = iVar19 + iVar15;
  }
  if (0 < iVar19) {
    iVar15 = 0;
    do {
      *(uint *)(iVar9 + iVar15 * 4) = (&local_5c)[iVar15];
      iVar15 = iVar15 + 1;
    } while (iVar19 != iVar15);
  }
  iVar15 = *param_1;
  uVar16 = *(uint *)(iVar15 + 0x28);
  pbVar22 = (byte *)(iVar15 + *(int *)(iVar15 + 0x2c) * 8);
  iVar15 = iVar15 + *(int *)(iVar15 + 0x6c) * 8;
  if (0 < (int)uVar16) {
    local_84 = 0;
    do {
      while( true ) {
        bVar3 = *pbVar22 & 0x38;
        if ((((bVar3 != 0x18) && (bVar3 != 8)) && (bVar3 != 0x20)) && (bVar3 != 0)) {
          if (param_1[9] == 0) {
            param_1[9] = 3;
          }
          iVar15 = param_1[9];
          goto LAB_000481a2;
        }
        if (pbVar22[1] >> 3 == 0x11) break;
LAB_00047fb8:
        local_84 = local_84 + 1;
        pbVar22 = pbVar22 + 8;
        if (uVar16 == local_84) goto LAB_000480ea;
      }
      uVar7 = param_1[0xc];
      iVar19 = param_1[0xb];
      uVar11 = iVar19 + 6;
      if (uVar7 < uVar11) {
        if (uVar7 == 0) {
          uVar7 = 0x10;
          uVar20 = 0x10;
          if (0x10 < uVar11) goto LAB_00048015;
        }
        else {
LAB_00048015:
          do {
            uVar7 = uVar7 * 2;
            uVar20 = uVar7;
          } while (uVar7 < uVar11);
        }
        if ((void *)*piVar21 == (void *)0x0) {
          pvVar5 = _malloc(uVar20 * 4);
        }
        else {
          pvVar5 = _realloc((void *)*piVar21,uVar20 * 4);
        }
        if (pvVar5 != (void *)0x0) {
          *piVar21 = (int)pvVar5;
          param_1[0xc] = uVar20;
          iVar19 = param_1[0xb];
          goto LAB_0004805c;
        }
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        if (param_1[9] != 0) goto LAB_00047b4e;
        puVar8 = (undefined4 *)0x0;
        pdVar6 = &MACH_HEADER.cputype;
      }
      else {
LAB_0004805c:
        puVar8 = (undefined4 *)(*piVar21 + iVar19 * 4);
        param_1[0xb] = iVar19 + 6;
        pdVar6 = puVar8 + 1;
      }
      *puVar8 = 0x1c;
      *pdVar6 = local_84 & 0xffff | 0x10000;
      uVar11 = (uint)*(ushort *)(pbVar22 + 2);
      if ((*pbVar22 & 0x38) == 0x18) {
        puVar8[2] = (float)*(int *)(uVar11 * 0x10 + iVar15);
        iVar19 = uVar11 * 0x10 + iVar15;
        puVar8[3] = (float)*(int *)(iVar19 + 4);
        puVar8[4] = (float)*(int *)(iVar19 + 8);
        puVar8[5] = (float)*(int *)(iVar19 + 0xc);
        goto LAB_00047fb8;
      }
      if ((*pbVar22 & 0x38) == 0x20) {
        puVar8[2] = (uint)(*(int *)(iVar15 + uVar11 * 0x10) != 0);
        iVar19 = uVar11 * 0x10 + iVar15;
        puVar8[3] = (uint)(*(int *)(iVar19 + 4) != 0);
        puVar8[4] = (uint)(*(int *)(iVar19 + 8) != 0);
        puVar8[5] = (uint)(*(int *)(iVar19 + 0xc) != 0);
        goto LAB_00047fb8;
      }
      puVar8[2] = *(undefined4 *)(iVar15 + uVar11 * 0x10);
      iVar19 = uVar11 * 0x10 + iVar15;
      puVar8[3] = *(undefined4 *)(iVar19 + 4);
      puVar8[4] = *(undefined4 *)(iVar19 + 8);
      puVar8[5] = *(undefined4 *)(iVar19 + 0xc);
      local_84 = local_84 + 1;
      pbVar22 = pbVar22 + 8;
    } while (uVar16 != local_84);
  }
LAB_000480ea:
  param_1[6] = param_1[0xb];
  uVar16 = param_1[0xc];
  iVar15 = param_1[0xb];
  if (uVar16 < iVar15 + 0xc6U) {
    if (uVar16 == 0) {
      uVar16 = 0x10;
    }
    else {
      uVar16 = uVar16 * 2;
    }
    for (; uVar16 < iVar15 + 0xc6U; uVar16 = uVar16 * 2) {
    }
    if ((void *)*piVar21 == (void *)0x0) {
      pvVar5 = _malloc(uVar16 * 4);
      if (pvVar5 != (void *)0x0) {
        *piVar21 = (int)pvVar5;
        goto LAB_00048157;
      }
    }
    else {
      pvVar5 = _realloc((void *)*piVar21,uVar16 * 4);
      if (pvVar5 != (void *)0x0) {
        *piVar21 = (int)pvVar5;
LAB_00048157:
        param_1[0xc] = uVar16;
        iVar15 = param_1[0xb];
        goto LAB_00048163;
      }
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) {
      return param_1[9];
    }
    iVar19 = 0;
  }
  else {
LAB_00048163:
    iVar19 = *piVar21 + iVar15 * 4;
    param_1[0xb] = iVar15 + 0xc6;
  }
  iVar15 = 1;
  do {
    *(undefined4 *)(iVar19 + -4 + iVar15 * 4) = 0x4b;
    iVar15 = iVar15 + 1;
  } while (iVar15 != 199);
  param_1[7] = param_1[0xb];
  iVar15 = param_1[9];
LAB_000481a2:
  if (iVar15 != 0) {
    return iVar15;
  }
  iVar15 = ((int (*)())FUN_00045789)();
  if (iVar15 != 0) {
LAB_00048395:
    return param_1[9];
  }
  local_60 = *param_1;
  iVar15 = *(int *)(local_60 + 0x30);
  local_60 = local_60 + *(int *)(local_60 + 0x34) * 8;
  if (0 < iVar15) {
    local_70 = 0;
    do {
      if ((param_1[4] & 1 << ((byte)local_70 & 0x1f)) != 0) {
        local_b0 = 0x55;
        uVar16 = *(int *)(*param_1 + 0x10) + local_70 + 1U & 0xffff | 0x440000;
        local_b8 = 0x3210;
        bVar3 = *(byte *)(local_60 + 1) >> 4;
        if (bVar3 == 4) {
          bVar3 = *(byte *)(param_1[0xd] + 0x21);
          if (((bVar3 & 2) == 0) && (1 < (bVar3 >> 2 & 0xf))) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          bVar3 = *(byte *)(param_1 + 5);
          *(byte *)(param_1 + 5) = bVar3 | 1;
          local_ac = CONCAT22(0x57,(ushort)(*(byte *)(local_60 + 3) >> 4)) & 0xffff0007;
          if ((bVar3 & 0x18) != 0) {
            pbVar22 = (byte *)(param_1[0xd] + 0x20);
            *pbVar22 = *pbVar22 | 0x40;
            local_c0 = *param_1;
            sVar1 = (*(byte *)(param_1[0xd] + 0x20) >> 5 & 1) +
                    (short)*(undefined4 *)(local_c0 + 0x28);
            sVar18 = sVar1 + 1;
            iVar19 = param_1[8];
            puVar13 = &local_5c;
            for (iVar9 = 9; iVar9 != 0; iVar9 = iVar9 + -1) {
              *puVar13 = 0;
              puVar13 = puVar13 + 1;
            }
            uVar14 = (undefined2)iVar19;
            (*(unsigned int *)((unsigned char *)&(local_58) + 0)) = CONCAT12(0x44,uVar14);
            local_58 = (dword)(uint3)local_58;
            local_54 = 0x55;
            local_50 = local_50 & 0xffc0ffff | 0x500000;
            local_44[0] = local_44[0] & 0xffff0000;
            bVar3 = *(byte *)(param_1 + 5) >> 3;
            bVar4 = bVar3 & 3;
            if (bVar4 == 1) {
              local_5c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_5c) + 2)),0x40);
              local_54 = 0x155;
              (*(unsigned int *)((unsigned char *)&(local_4c) + 0)) = CONCAT12(0x41,sVar18);
              local_4c = (uint)(uint3)local_4c;
              local_44[1] = 0;
              (*(unsigned int *)((unsigned char *)&(local_48) + 0)) = CONCAT12(0x41,sVar18);
              local_48 = (uint)(uint3)local_48;
              local_44[2] = 0x1111;
              if (param_1[9] == 0) {
                uVar11 = param_1[0xc];
                iVar19 = param_1[0xb];
                if (uVar11 < iVar19 + 9U) {
                  if (uVar11 == 0) {
                    uVar11 = 0x10;
                  }
                  else {
                    uVar11 = uVar11 * 2;
                  }
                  for (; uVar11 < iVar19 + 9U; uVar11 = uVar11 * 2) {
                  }
                  if ((void *)*piVar21 == (void *)0x0) {
                    pvVar5 = _malloc(uVar11 * 4);
                    if (pvVar5 != (void *)0x0) {
                      *piVar21 = (int)pvVar5;
                      goto LAB_0004927f;
                    }
                  }
                  else {
                    pvVar5 = _realloc((void *)*piVar21,uVar11 * 4);
                    if (pvVar5 != (void *)0x0) {
                      *piVar21 = (int)pvVar5;
LAB_0004927f:
                      param_1[0xc] = uVar11;
                      iVar19 = param_1[0xb];
                      goto LAB_0004928b;
                    }
                  }
                  if (param_1[9] == 0) {
                    param_1[9] = 1;
                  }
                  if (param_1[9] != 0) {
                    local_c0 = *param_1;
                    goto LAB_00048e10;
                  }
                  puVar13 = (uint *)0x0;
                  pdVar6 = &MACH_HEADER.cputype;
                  pdVar17 = &MACH_HEADER.cpusubtype;
                }
                else {
LAB_0004928b:
                  puVar13 = (uint *)(*piVar21 + iVar19 * 4);
                  param_1[0xb] = iVar19 + 9;
                  pdVar6 = puVar13 + 1;
                  pdVar17 = puVar13 + 2;
                }
                *puVar13 = local_5c;
                *pdVar6 = local_58;
                *pdVar17 = local_54;
                iVar9 = 0;
                iVar19 = 0;
                do {
                  *(undefined4 *)((int)puVar13 + iVar19 * 2 + 0xc) =
                       *(undefined4 *)(iVar19 + 0xc + (int)&local_5c);
                  *(undefined4 *)((int)puVar13 + iVar19 * 2 + 0x10) =
                       *(undefined4 *)(iVar19 + 0x18 + (int)&local_5c);
                  iVar9 = iVar9 + 1;
                  iVar19 = iVar19 + 4;
                } while (iVar9 != 3);
                goto LAB_000492dc;
              }
            }
            else {
              if (((bVar3 & 3) == 0) || (3 < bVar4)) goto LAB_00048795;
              local_5c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_5c) + 2)),0x49);
              if ((*(byte *)(param_1 + 5) & 0x18) == 0x10) {
                (*(unsigned int *)((unsigned char *)&(local_4c) + 0)) = CONCAT12(0x41,sVar18);
                local_4c = (uint)(uint3)local_4c;
                local_44[1] = 0x2222;
                if (param_1[9] == 0) {
                  uVar11 = param_1[0xc];
                  iVar19 = param_1[0xb];
                  if (uVar11 < iVar19 + 7U) {
                    if (uVar11 == 0) {
                      uVar11 = 0x10;
                    }
                    else {
                      uVar11 = uVar11 * 2;
                    }
                    for (; uVar11 < iVar19 + 7U; uVar11 = uVar11 * 2) {
                    }
                    if ((void *)*piVar21 == (void *)0x0) {
                      pvVar5 = _malloc(uVar11 * 4);
                      if (pvVar5 != (void *)0x0) {
                        *piVar21 = (int)pvVar5;
                        goto LAB_00049159;
                      }
                    }
                    else {
                      pvVar5 = _realloc((void *)*piVar21,uVar11 * 4);
                      if (pvVar5 != (void *)0x0) {
                        *piVar21 = (int)pvVar5;
LAB_00049159:
                        param_1[0xc] = uVar11;
                        iVar19 = param_1[0xb];
                        goto LAB_00049165;
                      }
                    }
                    if (param_1[9] == 0) {
                      param_1[9] = 1;
                    }
                    if (param_1[9] != 0) goto LAB_00048d1b;
                    puVar13 = (uint *)0x0;
                    pdVar6 = &MACH_HEADER.cputype;
                    pdVar17 = &MACH_HEADER.cpusubtype;
                  }
                  else {
LAB_00049165:
                    puVar13 = (uint *)(*piVar21 + iVar19 * 4);
                    param_1[0xb] = iVar19 + 7;
                    pdVar6 = puVar13 + 1;
                    pdVar17 = puVar13 + 2;
                  }
                  *puVar13 = local_5c;
                  *pdVar6 = local_58;
                  *pdVar17 = local_54;
                  iVar9 = 0;
                  iVar19 = 0;
                  do {
                    *(undefined4 *)((int)puVar13 + iVar19 * 2 + 0xc) =
                         *(undefined4 *)(iVar19 + 0xc + (int)&local_5c);
                    *(undefined4 *)((int)puVar13 + iVar19 * 2 + 0x10) =
                         *(undefined4 *)(iVar19 + 0x18 + (int)&local_5c);
                    iVar9 = iVar9 + 1;
                    iVar19 = iVar19 + 4;
                  } while (iVar9 != 2);
                }
              }
              else {
                (*(unsigned int *)((unsigned char *)&(local_4c) + 0)) = CONCAT12(0x41,sVar18);
                local_4c = (uint)(uint3)local_4c;
                local_44[1] = 0x3333;
                if (param_1[9] == 0) {
                  uVar11 = param_1[0xc];
                  iVar19 = param_1[0xb];
                  if (uVar11 < iVar19 + 7U) {
                    if (uVar11 == 0) {
                      uVar11 = 0x10;
                    }
                    else {
                      uVar11 = uVar11 * 2;
                    }
                    for (; uVar11 < iVar19 + 7U; uVar11 = uVar11 * 2) {
                    }
                    if ((void *)*piVar21 == (void *)0x0) {
                      pvVar5 = _malloc(uVar11 * 4);
                      if (pvVar5 != (void *)0x0) {
                        *piVar21 = (int)pvVar5;
                        goto LAB_00048b0d;
                      }
                    }
                    else {
                      pvVar5 = _realloc((void *)*piVar21,uVar11 * 4);
                      if (pvVar5 != (void *)0x0) {
                        *piVar21 = (int)pvVar5;
LAB_00048b0d:
                        param_1[0xc] = uVar11;
                        iVar19 = param_1[0xb];
                        goto LAB_00048b19;
                      }
                    }
                    if (param_1[9] == 0) {
                      param_1[9] = 1;
                    }
                    if (param_1[9] != 0) goto LAB_00048b6a;
                    puVar13 = (uint *)0x0;
                    pdVar6 = &MACH_HEADER.cputype;
                    pdVar17 = &MACH_HEADER.cpusubtype;
                  }
                  else {
LAB_00048b19:
                    puVar13 = (uint *)(*piVar21 + iVar19 * 4);
                    param_1[0xb] = iVar19 + 7;
                    pdVar6 = puVar13 + 1;
                    pdVar17 = puVar13 + 2;
                  }
                  *puVar13 = local_5c;
                  *pdVar6 = local_58;
                  *pdVar17 = local_54;
                  iVar9 = 0;
                  iVar19 = 0;
                  do {
                    *(undefined4 *)((int)puVar13 + iVar19 * 2 + 0xc) =
                         *(undefined4 *)(iVar19 + 0xc + (int)&local_5c);
                    *(undefined4 *)((int)puVar13 + iVar19 * 2 + 0x10) =
                         *(undefined4 *)(iVar19 + 0x18 + (int)&local_5c);
                    iVar9 = iVar9 + 1;
                    iVar19 = iVar19 + 4;
                  } while (iVar9 != 2);
                }
LAB_00048b6a:
                local_5c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_5c) + 2)),0x49);
                (*(unsigned int *)((unsigned char *)&(local_50) + 0)) = CONCAT12(0x44,uVar14);
                local_50 = (uint)(uint3)local_50;
                local_44[0] = 0x3210;
                (*(unsigned int *)((unsigned char *)&(local_4c) + 0)) = CONCAT12(0x44,uVar14);
                local_4c = (uint)(uint3)local_4c;
                local_44[1] = 0x3210;
                if (param_1[9] == 0) {
                  uVar11 = param_1[0xc];
                  iVar19 = param_1[0xb];
                  if (uVar11 < iVar19 + 7U) {
                    if (uVar11 != 0) goto LAB_00048bf6;
                    for (uVar11 = 0x10; uVar11 < iVar19 + 7U; uVar11 = uVar11 * 2) {
LAB_00048bf6: ;
                    }
                    if ((void *)*piVar21 == (void *)0x0) {
                      pvVar5 = _malloc(uVar11 * 4);
                      if (pvVar5 != (void *)0x0) {
                        *piVar21 = (int)pvVar5;
                        goto LAB_00048cbe;
                      }
                    }
                    else {
                      pvVar5 = _realloc((void *)*piVar21,uVar11 * 4);
                      if (pvVar5 != (void *)0x0) {
                        *piVar21 = (int)pvVar5;
LAB_00048cbe:
                        param_1[0xc] = uVar11;
                        iVar19 = param_1[0xb];
                        goto LAB_00048cca;
                      }
                    }
                    if (param_1[9] == 0) {
                      param_1[9] = 1;
                    }
                    if (param_1[9] != 0) goto LAB_00048d1b;
                    puVar13 = (uint *)0x0;
                    pdVar6 = &MACH_HEADER.cputype;
                    pdVar17 = &MACH_HEADER.cpusubtype;
                  }
                  else {
LAB_00048cca:
                    puVar13 = (uint *)(*piVar21 + iVar19 * 4);
                    param_1[0xb] = iVar19 + 7;
                    pdVar6 = puVar13 + 1;
                    pdVar17 = puVar13 + 2;
                  }
                  *puVar13 = local_5c;
                  *pdVar6 = local_58;
                  *pdVar17 = local_54;
                  iVar9 = 0;
                  iVar19 = 0;
                  do {
                    *(undefined4 *)((int)puVar13 + iVar19 * 2 + 0xc) =
                         *(undefined4 *)(iVar19 + 0xc + (int)&local_5c);
                    *(undefined4 *)((int)puVar13 + iVar19 * 2 + 0x10) =
                         *(undefined4 *)(iVar19 + 0x18 + (int)&local_5c);
                    iVar9 = iVar9 + 1;
                    iVar19 = iVar19 + 4;
                  } while (iVar9 != 2);
                }
              }
LAB_00048d1b:
              local_5c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_5c) + 2)),0x2d);
              local_54 = local_54 | 0x100;
              (*(unsigned int *)((unsigned char *)&(local_50) + 0)) = CONCAT12(0x44,uVar14);
              local_50 = (uint)(uint3)local_50;
              local_44[0] = 0xba98;
              if (param_1[9] == 0) {
                uVar11 = param_1[0xc];
                iVar19 = param_1[0xb];
                if (uVar11 < iVar19 + 5U) {
                  if (uVar11 != 0) goto LAB_00048d7e;
                  for (uVar11 = 0x10; uVar11 < iVar19 + 5U; uVar11 = uVar11 * 2) {
LAB_00048d7e: ;
                  }
                  if ((void *)*piVar21 == (void *)0x0) {
                    pvVar5 = _malloc(uVar11 * 4);
                    if (pvVar5 != (void *)0x0) {
                      *piVar21 = (int)pvVar5;
                      goto LAB_00048db7;
                    }
                  }
                  else {
                    pvVar5 = _realloc((void *)*piVar21,uVar11 * 4);
                    if (pvVar5 != (void *)0x0) {
                      *piVar21 = (int)pvVar5;
LAB_00048db7:
                      param_1[0xc] = uVar11;
                      iVar19 = param_1[0xb];
                      goto LAB_00048dc3;
                    }
                  }
                  if (param_1[9] == 0) {
                    param_1[9] = 1;
                  }
                  if (param_1[9] != 0) {
                    local_c0 = *param_1;
                    goto LAB_00048e10;
                  }
                  puVar13 = (uint *)0x0;
                  local_64 = &MACH_HEADER.cputype;
                  pdVar6 = &MACH_HEADER.cpusubtype;
                  pdVar17 = &MACH_HEADER.filetype;
                  pdVar12 = &MACH_HEADER.ncmds;
                }
                else {
LAB_00048dc3:
                  puVar13 = (uint *)(*piVar21 + iVar19 * 4);
                  param_1[0xb] = iVar19 + 5;
                  local_64 = puVar13 + 1;
                  pdVar6 = puVar13 + 2;
                  pdVar17 = puVar13 + 3;
                  pdVar12 = puVar13 + 4;
                }
                *puVar13 = local_5c;
                *local_64 = local_58;
                *pdVar6 = local_54;
                *pdVar17 = local_50;
                *pdVar12 = local_44[0];
                local_c0 = *param_1;
                goto LAB_00048e10;
              }
LAB_000492dc:
              local_c0 = *param_1;
            }
LAB_00048e10:
            local_5c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_5c) + 2)),0x47);
            sVar18 = (short)local_70;
            (*(unsigned int *)((unsigned char *)&(local_58) + 0)) = CONCAT12(0x44,sVar18 + (short)*(undefined4 *)(local_c0 + 0x10) + 1);
            local_58 = (dword)(uint3)local_58;
            local_54 = 0x155;
            (*(unsigned int *)((unsigned char *)&(local_50) + 0)) = CONCAT12(0x44,sVar18 + (short)*(undefined4 *)(local_c0 + 0x10) + 1);
            local_50 = (uint)(uint3)local_50;
            local_44[0] = 0x3210;
            if (param_1[9] == 0) {
              uVar11 = param_1[0xc];
              iVar19 = param_1[0xb];
              if (uVar11 < iVar19 + 5U) {
                if (uVar11 != 0) goto LAB_0004902e;
                for (uVar11 = 0x10; uVar11 < iVar19 + 5U; uVar11 = uVar11 * 2) {
LAB_0004902e: ;
                }
                if ((void *)*piVar21 == (void *)0x0) {
                  pvVar5 = _malloc(uVar11 * 4);
                  if (pvVar5 != (void *)0x0) {
                    *piVar21 = (int)pvVar5;
                    goto LAB_00049067;
                  }
                }
                else {
                  pvVar5 = _realloc((void *)*piVar21,uVar11 * 4);
                  if (pvVar5 != (void *)0x0) {
                    *piVar21 = (int)pvVar5;
LAB_00049067:
                    param_1[0xc] = uVar11;
                    iVar19 = param_1[0xb];
                    goto LAB_00049073;
                  }
                }
                if (param_1[9] == 0) {
                  param_1[9] = 1;
                }
                if (param_1[9] != 0) {
                  local_c0 = *param_1;
                  goto LAB_00048e86;
                }
                puVar13 = (uint *)0x0;
                local_68 = &MACH_HEADER.cputype;
                pdVar6 = &MACH_HEADER.cpusubtype;
                pdVar17 = &MACH_HEADER.filetype;
                pdVar12 = &MACH_HEADER.ncmds;
              }
              else {
LAB_00049073:
                puVar13 = (uint *)(*piVar21 + iVar19 * 4);
                param_1[0xb] = iVar19 + 5;
                local_68 = puVar13 + 1;
                pdVar6 = puVar13 + 2;
                pdVar17 = puVar13 + 3;
                pdVar12 = puVar13 + 4;
              }
              *puVar13 = local_5c;
              *local_68 = local_58;
              *pdVar6 = local_54;
              *pdVar17 = local_50;
              *pdVar12 = local_44[0];
              local_c0 = *param_1;
            }
LAB_00048e86:
            local_5c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_5c) + 2)),0x3f);
            (*(unsigned int *)((unsigned char *)&(local_58) + 0)) = CONCAT12(0x44,sVar18 + (short)*(undefined4 *)(local_c0 + 0x10) + 1);
            local_58 = (dword)(uint3)local_58;
            local_54 = 0x15;
            (*(unsigned int *)((unsigned char *)&(local_50) + 0)) = CONCAT12(0x44,uVar14);
            local_50 = (uint)(uint3)local_50;
            local_44[0] = 0x3210;
            (*(unsigned int *)((unsigned char *)&(local_4c) + 0)) = CONCAT12(0x44,sVar18 + (short)*(undefined4 *)(local_c0 + 0x10) + 1);
            local_4c = (uint)(uint3)local_4c;
            local_44[1] = 0x3210;
            (*(unsigned int *)((unsigned char *)&(local_48) + 0)) = CONCAT12(0x41,sVar1);
            local_48 = (uint)(uint3)local_48;
            local_44[2] = 0x3210;
            if (param_1[9] == 0) {
              uVar11 = param_1[0xc];
              iVar19 = param_1[0xb];
              if (uVar11 < iVar19 + 9U) {
                if (uVar11 != 0) goto LAB_00048f71;
                for (uVar11 = 0x10; uVar11 < iVar19 + 9U; uVar11 = uVar11 * 2) {
LAB_00048f71: ;
                }
                if ((void *)*piVar21 == (void *)0x0) {
                  pvVar5 = _malloc(uVar11 * 4);
                  if (pvVar5 != (void *)0x0) {
                    *piVar21 = (int)pvVar5;
                    goto LAB_00048faa;
                  }
                }
                else {
                  pvVar5 = _realloc((void *)*piVar21,uVar11 * 4);
                  if (pvVar5 != (void *)0x0) {
                    *piVar21 = (int)pvVar5;
LAB_00048faa:
                    param_1[0xc] = uVar11;
                    iVar19 = param_1[0xb];
                    goto LAB_00048fb6;
                  }
                }
                if (param_1[9] == 0) {
                  param_1[9] = 1;
                }
                if (param_1[9] != 0) goto LAB_00048795;
                puVar13 = (uint *)0x0;
                pdVar6 = &MACH_HEADER.cputype;
                pdVar17 = &MACH_HEADER.cpusubtype;
              }
              else {
LAB_00048fb6:
                puVar13 = (uint *)(*piVar21 + iVar19 * 4);
                param_1[0xb] = iVar19 + 9;
                pdVar6 = puVar13 + 1;
                pdVar17 = puVar13 + 2;
              }
              *puVar13 = local_5c;
              *pdVar6 = local_58;
              *pdVar17 = local_54;
              iVar9 = 0;
              iVar19 = 0;
              do {
                *(undefined4 *)((int)puVar13 + iVar19 * 2 + 0xc) =
                     *(undefined4 *)(iVar19 + 0xc + (int)&local_5c);
                *(undefined4 *)((int)puVar13 + iVar19 * 2 + 0x10) =
                     *(undefined4 *)(iVar19 + 0x18 + (int)&local_5c);
                iVar9 = iVar9 + 1;
                iVar19 = iVar19 + 4;
              } while (iVar9 != 3);
            }
          }
LAB_00048795:
          if (bVar2) {
            local_6c = 0;
            puVar8 = (undefined4 *)0x0;
            do {
              if (((int)(*(byte *)(param_1[0xd] + 0x21) >> 2 & 0xf) >> ((byte)local_6c & 0x1f) & 1U)
                  != 0) {
                uVar11 = param_1[0xc];
                iVar19 = param_1[0xb];
                if (uVar11 < iVar19 + 5U) {
                  if (uVar11 == 0) {
                    uVar11 = 0x10;
                  }
                  else {
                    uVar11 = uVar11 * 2;
                  }
                  for (; uVar11 < iVar19 + 5U; uVar11 = uVar11 * 2) {
                  }
                  if ((void *)*piVar21 == (void *)0x0) {
                    pvVar5 = _malloc(uVar11 * 4);
                  }
                  else {
                    pvVar5 = _realloc((void *)*piVar21,uVar11 * 4);
                  }
                  if (pvVar5 != (void *)0x0) {
                    *piVar21 = (int)pvVar5;
                    param_1[0xc] = uVar11;
                    iVar19 = param_1[0xb];
                    goto LAB_00048833;
                  }
                  if (param_1[9] == 0) {
                    param_1[9] = 1;
                  }
                  if (param_1[9] != 0) goto LAB_00048654;
                }
                else {
LAB_00048833:
                  puVar8 = (undefined4 *)(*piVar21 + iVar19 * 4);
                  param_1[0xb] = iVar19 + 5;
                }
                local_ac = CONCAT22((*(unsigned short *)((unsigned char *)&(local_ac) + 2)),(short)local_6c);
                *puVar8 = 0x47;
                puVar8[1] = local_ac;
                puVar8[2] = 0x55;
                puVar8[3] = uVar16;
                puVar8[4] = 0x3210;
              }
              local_6c = local_6c + 1;
            } while (local_6c != 4);
            goto LAB_00048230;
          }
        }
        else {
          if (bVar3 != 7) {
            if (param_1[9] == 0) {
              param_1[9] = 3;
            }
            if (param_1[9] != 0) goto LAB_00048654;
            break;
          }
          bVar3 = *(byte *)(param_1 + 5);
          *(byte *)(param_1 + 5) = bVar3 | 2;
          local_ac = 0x580000;
          local_b0 = 0x155;
          local_b8 = 0x3212;
          if ((bVar3 & 4) != 0) {
            local_b8 = 0x3210;
          }
        }
        uVar11 = param_1[0xc];
        iVar19 = param_1[0xb];
        if (uVar11 < iVar19 + 5U) {
          if (uVar11 != 0) goto LAB_00048318;
          for (uVar11 = 0x10; uVar11 < iVar19 + 5U; uVar11 = uVar11 * 2) {
LAB_00048318: ;
          }
          if ((void *)*piVar21 == (void *)0x0) {
            pvVar5 = _malloc(uVar11 * 4);
            if (pvVar5 != (void *)0x0) {
              *piVar21 = (int)pvVar5;
              goto LAB_00048549;
            }
          }
          else {
            pvVar5 = _realloc((void *)*piVar21,uVar11 * 4);
            if (pvVar5 != (void *)0x0) {
              *piVar21 = (int)pvVar5;
LAB_00048549:
              param_1[0xc] = uVar11;
              iVar19 = param_1[0xb];
              goto LAB_000481df;
            }
          }
          if (param_1[9] == 0) {
            param_1[9] = 1;
          }
          if (param_1[9] != 0) goto LAB_00048654;
          puVar8 = (undefined4 *)0x0;
          pdVar6 = &MACH_HEADER.cputype;
          pdVar17 = &MACH_HEADER.cpusubtype;
          pdVar12 = &MACH_HEADER.filetype;
          local_d0 = &MACH_HEADER.ncmds;
        }
        else {
LAB_000481df:
          puVar8 = (undefined4 *)(*piVar21 + iVar19 * 4);
          param_1[0xb] = iVar19 + 5;
          pdVar6 = puVar8 + 1;
          pdVar17 = puVar8 + 2;
          pdVar12 = puVar8 + 3;
          local_d0 = puVar8 + 4;
        }
        *puVar8 = 0x47;
        *pdVar6 = local_ac;
        *pdVar17 = local_b0;
        *pdVar12 = uVar16;
        *local_d0 = local_b8;
      }
LAB_00048230:
      local_70 = local_70 + 1;
      local_60 = local_60 + 8;
    } while (iVar15 != local_70);
  }
  uVar16 = param_1[0xc];
  iVar15 = param_1[0xb];
  if (uVar16 < iVar15 + 1U) {
    if (uVar16 != 0) goto LAB_00048898;
    for (uVar16 = 0x10; uVar16 < iVar15 + 1U; uVar16 = uVar16 * 2) {
LAB_00048898: ;
    }
    if ((void *)*piVar21 == (void *)0x0) {
      pvVar5 = _malloc(uVar16 * 4);
      if (pvVar5 != (void *)0x0) {
        *piVar21 = (int)pvVar5;
        goto LAB_000488d1;
      }
    }
    else {
      pvVar5 = _realloc((void *)*piVar21,uVar16 * 4);
      if (pvVar5 != (void *)0x0) {
        *piVar21 = (int)pvVar5;
LAB_000488d1:
        param_1[0xc] = uVar16;
        iVar15 = param_1[0xb];
        goto LAB_000485fb;
      }
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
    }
    if (param_1[9] != 0) {
      return param_1[9];
    }
  }
  else {
LAB_000485fb:
    local_a4 = (undefined4 *)(*piVar21 + iVar15 * 4);
    param_1[0xb] = iVar15 + 1;
  }
  *local_a4 = 0x28;
  iVar15 = param_1[7];
  iVar19 = iVar15 - param_1[6];
  if (iVar19 != 0) {
    _memmove((void *)(param_1[10] + param_1[6] * 4),(void *)(param_1[10] + iVar15 * 4),
             (param_1[0xb] - iVar15) * 4);
    param_1[0xb] = param_1[0xb] - iVar19;
    param_1[7] = param_1[6];
  }
  if (((*(byte *)(param_1 + 5) & 3) == 0) && (iVar15 = ((int (*)())FUN_0003ef50)(param_1), iVar15 != 0)) {
LAB_00048654:
    return param_1[9];
  }
LAB_00047b4e:
  return param_1[9];
}

/* FUN_0004951b @ 0x4951b (81 bytes) */
int FUN_0004951b(param_1)
  uint param_1;
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (param_1 & 0x80000000) >> 8;
  uVar2 = (param_1 & 0x7f800000) >> 0x17;
  if (uVar2 < 0x41) {
    return 0;
  }
  if (uVar2 < 0xc0) {
    return (uVar2 - 0x40) * 0x10000 | uVar1 | (param_1 & 0x7fffff) >> 7;
  }
  return uVar1 | 0x7fffff;
}

/* FUN_0004956c @ 0x4956c (55 bytes) */
int FUN_0004956c(param_1)
  uint param_1;
{
  return (longdouble)
         (float)((param_1 & 0x800000) << 8 | ((param_1 >> 0x10 & 0x7f) + 0x40) * 0x800000 |
                (param_1 & 0xffff) << 7);
}

/* FUN_000495a3 @ 0x495a3 (85 bytes) */
int FUN_000495a3(param_1)
  int param_1;
{
  int iVar1;
  
  if (((*(byte *)(param_1 + 0x45) & 0x40) != 0) && (iVar1 = *(int *)(param_1 + 0x1e70), iVar1 != 0))
  {
    if ((*(byte *)(param_1 + 0x46) & 4) == 0) {
      if (*(char *)(param_1 + 0x1136) == '\0') goto LAB_000495d1;
    }
    else if (*(char *)(param_1 + 0x11d0) == '\0') {
      (**(code **)(param_1 + 0x294c))(param_1,iVar1);
      return;
    }
  }
  iVar1 = *(int *)(param_1 + 0x1e5c);
LAB_000495d1:
  (**(code **)(param_1 + 0x294c))(param_1,iVar1);
  return;
}

/* FUN_000495f8 @ 0x495f8 (99 bytes) */
int FUN_000495f8(param_1)
  int param_1;
{
  if ((*(byte *)(param_1 + 0x45) & 0x40) == 0) {
    FUN_000b4709(param_1,0);
    (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
    return;
  }
  if ((*(byte *)(param_1 + 0x46) & 4) != 0) {
    FUN_000aea8d(param_1,0);
    return;
  }
  FUN_000b1aed(param_1);
  return;
}

/* FUN_0004965b @ 0x4965b (85 bytes) */
int FUN_0004965b(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  FUN_0004ae65(param_2 + 8);
  FUN_0004ae65(param_2 + 8);
  *param_2 = 0;
  param_2[7] = 0;
  if ((param_1 != 0) && (param_2 == *(undefined4 **)(param_1 + 0x1e68))) {
    *(undefined4 *)(param_1 + 0x1e68) = 0;
    return;
  }
  return;
}

